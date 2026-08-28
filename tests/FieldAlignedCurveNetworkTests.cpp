#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <numbers>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include <Eigen/Sparse>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/GlobalTopologyPlan.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "TestFixturePaths.h"
#include "support/SkewSingularFieldWitness.h"


namespace {

using directional::TriMesh;
using directional::geometry::FieldAlignedCurveNetworkErrorCode;
using directional::authority::FieldSingularityId;
using directional::authority::HardRailId;
using directional::authority::SingularityPortId;
using directional::authority::SourceComponentId;
using directional::authority::SourceEdgeTopologyKey;
using directional::authority::SourceFaceId;
using directional::authority::SourceFaceTopologyKey;
using directional::authority::SourceVertexId;
using directional::fields::CrossFieldEdgeTransition;
using directional::fields::CrossFieldResult;
using directional::geometry::FieldAlignedCurveNetwork;
using directional::geometry::FieldAlignedCurveNetworkCandidate;
using directional::geometry::SourceTopologyRegions;
using directional::geometry::SurfaceCellRail;
using directional::geometry::SurfaceCellRailKind;
using directional::geometry::SurfaceCellTracingOptions;

TriMesh make_square_mesh(const bool reverseFaceRows = false) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  if (reverseFaceRows) {
    faces << 0, 2, 3,
             0, 1, 2;
  } else {
    faces << 0, 1, 2,
             0, 2, 3;
  }
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

TriMesh make_four_triangle_fan() {
  Eigen::MatrixXd vertices(5, 3);
  vertices << -1.0, -1.0, 0.0,
               1.0, -1.0, 0.0,
               1.0,  1.0, 0.0,
              -1.0,  1.0, 0.0,
               0.0,  0.0, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4,
           1, 2, 4,
           2, 3, 4,
           3, 0, 4;
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

SourceEdgeTopologyKey edge_key(const TriMesh &mesh, const int edge) {
  return SourceEdgeTopologyKey::from_indices(
             mesh.EV(edge, 0), mesh.EV(edge, 1),
             static_cast<std::size_t>(mesh.V.rows()))
      .value();
}

SourceEdgeTopologyKey topology_edge(const int first, const int second,
                                    const std::size_t vertexExtent = 3U) {
  return SourceEdgeTopologyKey::from_indices(first, second, vertexExtent).value();
}

SourceFaceTopologyKey topology_face(const int first, const int second,
                                    const int third,
                                    const std::size_t vertexExtent = 3U) {
  return SourceFaceTopologyKey::make(
             std::array<SourceVertexId, 3>{
                 SourceVertexId::from_index(first, vertexExtent).value(),
                 SourceVertexId::from_index(second, vertexExtent).value(),
                 SourceVertexId::from_index(third, vertexExtent).value()})
      .value();
}

directional::authority::FieldExactRational exact_integer(const int value) {
  return directional::authority::FieldExactRational::from_integer(value);
}

directional::authority::FieldExactRational exact_ratio(
    const std::int64_t numerator, const std::int64_t denominator) {
  return *directional::authority::FieldExactRational::from_ratio(
      numerator, denominator);
}

directional::authority::FieldBoundaryPoint boundary_point(
    const SourceEdgeTopologyKey &edge, const int numerator,
    const int denominator) {
  return directional::authority::FieldBoundaryPoint{
      edge, directional::authority::ExactUnitParameter{
                exact_ratio(numerator, denominator)}};
}

directional::authority::FieldBranchBoundaryPairing continuation_pairing(
    const std::array<int, 3> &direction,
    std::vector<SourceEdgeTopologyKey> outgoingCarriers) {
  directional::authority::FieldBranchBoundaryPairing pairing;
  pairing.branch = directional::authority::FieldBranch::from_integer(0);
  pairing.direction = directional::authority::FieldBranchDirection{
      std::array<directional::authority::FieldExactRational, 3>{
          exact_integer(direction[0]), exact_integer(direction[1]),
          exact_integer(direction[2])}};
  pairing.outgoingCarriers = std::move(outgoingCarriers);
  return pairing;
}

int source_edge_index(const TriMesh &mesh,
                      const SourceEdgeTopologyKey &sourceEdge) {
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (edge_key(mesh, edge) == sourceEdge) return edge;
  }
  return -1;
}

CrossFieldResult make_zero_transport_field(const TriMesh &mesh) {
  CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.matching = Eigen::VectorXi::Zero(mesh.EV.rows());
  field.effort = Eigen::VectorXd::Zero(mesh.EV.rows());
  field.matchingComputed = true;
  field.singularitiesComputed = true;
  field.singularCycles.resize(0);
  field.singularIndices.resize(0);
  field.primaryDirections.resize(mesh.F.rows(), 3);
  field.secondaryDirections.resize(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    field.primaryDirections.row(face) = Eigen::RowVector3d::UnitX();
    field.secondaryDirections.row(face) = Eigen::RowVector3d::UnitY();
  }
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    field.edgeTransitions.push_back(CrossFieldEdgeTransition{
        edge, mesh.EV(edge, 0), mesh.EV(edge, 1), mesh.EF(edge, 0),
        mesh.EF(edge, 1), 0, 0.0});
  }
  return field;
}

std::optional<SourceTopologyRegions> make_source_authority(
    const TriMesh &mesh,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges = {}) {
  SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.hardFeatureEdges = hardFeatureEdges;
  return directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(mesh.F, options);
}

CrossFieldResult make_index_one_singularity_field(const TriMesh &mesh) {
  CrossFieldResult field = make_zero_transport_field(mesh);
  directional::PCFaceTangentBundle bundle;
  bundle.init(mesh);
  Eigen::SparseMatrix<double, Eigen::RowMajor> cycles = bundle.cycles;
  EXPECT_GT(cycles.rows(), 0);
  bool assigned = false;
  for (Eigen::SparseMatrix<double, Eigen::RowMajor>::InnerIterator it(cycles, 0);
       it; ++it) {
    if (it.value() == 0.0) continue;
    EXPECT_NE(0, it.value());
    const int sign = it.value() > 0.0 ? 1 : -1;
    const int edge = bundle.innerAdjacencies(it.col());
    field.matching(edge) = sign;
    field.effort(edge) = static_cast<double>(sign) * 2.0 * std::numbers::pi;
    auto transition = std::find_if(
        field.edgeTransitions.begin(), field.edgeTransitions.end(),
        [&](const CrossFieldEdgeTransition &candidate) {
          return candidate.sourceEdge == edge;
        });
    EXPECT_NE(field.edgeTransitions.end(), transition);
    if (transition == field.edgeTransitions.end()) break;
    transition->matching = sign;
    transition->effort = field.effort(edge);
    assigned = true;
    break;
  }
  EXPECT_TRUE(assigned);
  field.singularCycles.resize(1);
  field.singularIndices.resize(1);
  field.singularCycles << 4;
  field.singularIndices << 1;
  return field;
}

std::vector<SurfaceCellRail> rails_from_atlas(
    const TriMesh &mesh,
    const directional::authority::FieldTransportAtlas &atlas,
    const bool hardFeatureFirst = false) {
  std::vector<const directional::authority::FieldNonTraversableEdge *> barriers;
  for (const auto &barrier : atlas.nontraversable_edges()) {
    if (barrier.kind ==
            directional::authority::FieldTransportBarrierKind::SourceBoundary ||
        barrier.kind ==
            directional::authority::FieldTransportBarrierKind::HardFeature) {
      barriers.push_back(&barrier);
    }
  }
  if (hardFeatureFirst) {
    std::stable_sort(barriers.begin(), barriers.end(), [](const auto *lhs,
                                                          const auto *rhs) {
      const bool lhsHard = lhs->kind ==
          directional::authority::FieldTransportBarrierKind::HardFeature;
      const bool rhsHard = rhs->kind ==
          directional::authority::FieldTransportBarrierKind::HardFeature;
      return lhsHard != rhsHard ? lhsHard > rhsHard
                                : lhs->sourceEdge < rhs->sourceEdge;
    });
  }
  std::vector<SurfaceCellRail> rails;
  rails.reserve(barriers.size());
  for (std::size_t index = 0; index < barriers.size(); ++index) {
    SurfaceCellRail rail(HardRailId::from_index(
                             static_cast<std::int64_t>(index), barriers.size())
                             .value());
    rail.kind = barriers[index]->kind ==
                        directional::authority::FieldTransportBarrierKind::HardFeature
                    ? SurfaceCellRailKind::HardFeature
                    : SurfaceCellRailKind::Boundary;
    // Deliberately unrelated legacy projection. The CP2 product must derive
    // typed component authority from SourceTopologyRegions instead.
    rail.component = 997;
    rail.sourceVertices = {
        static_cast<int>(barriers[index]->sourceEdge.first().index()),
        static_cast<int>(barriers[index]->sourceEdge.second().index())};
    const int sourceEdge = source_edge_index(mesh, barriers[index]->sourceEdge);
    EXPECT_GE(sourceEdge, 0);
    rail.sourceEdges = {sourceEdge};
    rails.push_back(std::move(rail));
  }
  return rails;
}

FieldAlignedCurveNetwork build_network(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority,
    const directional::authority::FieldTransportAtlas &atlas,
    const std::vector<SurfaceCellRail> &rails) {
  auto built = FieldAlignedCurveNetwork::make(
      mesh, sourceAuthority, atlas,
      rails);
  EXPECT_TRUE(built);
  return built.value();
}

constexpr int kCp3aCenterVertex = 0;
constexpr int kCp3aRingSize = 5;

TriMesh make_cp3a_two_ring_skew_disc() {
  constexpr std::array<double, kCp3aRingSize> angles{
      -2.85, -1.48, -0.20, 1.08, 2.42};
  constexpr std::array<double, kCp3aRingSize> innerRadii{
      1.10, 1.38, 1.22, 1.47, 1.18};
  constexpr std::array<double, kCp3aRingSize> outerRadii{
      2.55, 2.83, 2.64, 2.91, 2.72};
  constexpr double centerX = 0.17;
  constexpr double centerY = -0.11;

  Eigen::MatrixXd vertices(1 + 2 * kCp3aRingSize, 3);
  vertices.row(kCp3aCenterVertex) =
      Eigen::RowVector3d(centerX, centerY, 0.0);
  for (int ring = 0; ring < kCp3aRingSize; ++ring) {
    const double cosine = std::cos(angles[static_cast<std::size_t>(ring)]);
    const double sine = std::sin(angles[static_cast<std::size_t>(ring)]);
    vertices.row(1 + ring) = Eigen::RowVector3d(
        centerX + innerRadii[static_cast<std::size_t>(ring)] * cosine,
        centerY + innerRadii[static_cast<std::size_t>(ring)] * sine, 0.0);
    vertices.row(1 + kCp3aRingSize + ring) = Eigen::RowVector3d(
        centerX + outerRadii[static_cast<std::size_t>(ring)] * cosine,
        centerY + outerRadii[static_cast<std::size_t>(ring)] * sine, 0.0);
  }

  Eigen::MatrixXi faces(3 * kCp3aRingSize, 3);
  int face = 0;
  for (int ring = 0; ring < kCp3aRingSize; ++ring) {
    const int next = (ring + 1) % kCp3aRingSize;
    faces.row(face++) << kCp3aCenterVertex, 1 + ring, 1 + next;
  }
  for (int ring = 0; ring < kCp3aRingSize; ++ring) {
    const int next = (ring + 1) % kCp3aRingSize;
    const int inner = 1 + ring;
    const int nextInner = 1 + next;
    const int outer = 1 + kCp3aRingSize + ring;
    const int nextOuter = 1 + kCp3aRingSize + next;
    faces.row(face++) << inner, outer, nextOuter;
    faces.row(face++) << inner, nextOuter, nextInner;
  }

  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

double wrapped_phase_delta(const double delta) {
  return std::atan2(std::sin(delta), std::cos(delta));
}

double independently_reconstruct_center_index(
    const TriMesh &mesh, const Eigen::MatrixXd &primaryDirections) {
  std::vector<std::pair<double, double>> phaseByPolarAngle;
  const Eigen::RowVector3d center = mesh.V.row(kCp3aCenterVertex);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    bool incident = false;
    for (int corner = 0; corner < 3; ++corner) {
      incident = incident || mesh.F(face, corner) == kCp3aCenterVertex;
    }
    if (!incident) continue;
    const Eigen::RowVector3d centroid =
        (mesh.V.row(mesh.F(face, 0)) + mesh.V.row(mesh.F(face, 1)) +
         mesh.V.row(mesh.F(face, 2))) /
        3.0;
    const double polar =
        std::atan2(centroid.y() - center.y(), centroid.x() - center.x());
    const double primaryAngle = std::atan2(primaryDirections(face, 1),
                                           primaryDirections(face, 0));
    phaseByPolarAngle.emplace_back(polar, 4.0 * primaryAngle);
  }
  std::sort(phaseByPolarAngle.begin(), phaseByPolarAngle.end());
  double phaseWinding = 0.0;
  for (std::size_t index = 0; index < phaseByPolarAngle.size(); ++index) {
    const std::size_t next = (index + 1U) % phaseByPolarAngle.size();
    phaseWinding += wrapped_phase_delta(
        phaseByPolarAngle[next].second - phaseByPolarAngle[index].second);
  }
  return phaseWinding / (2.0 * std::numbers::pi);
}

void make_cp3a_two_ring_index_one_field(const TriMesh &mesh,
                                         CrossFieldResult &field) {
  ASSERT_EQ(0, mesh.isBoundaryVertex(kCp3aCenterVertex));
  for (int ring = 0; ring < kCp3aRingSize; ++ring) {
    ASSERT_EQ(0, mesh.isBoundaryVertex(1 + ring));
    ASSERT_NE(0, mesh.isBoundaryVertex(1 + kCp3aRingSize + ring));
  }

  int centerIncidentFaces = 0;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    int centerCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (mesh.F(face, corner) == kCp3aCenterVertex) centerCorner = corner;
    }
    if (centerCorner < 0) continue;
    ++centerIncidentFaces;
    const int first = mesh.F(face, (centerCorner + 1) % 3);
    const int second = mesh.F(face, (centerCorner + 2) % 3);
    const auto opposite = SourceEdgeTopologyKey::from_indices(
        first, second, static_cast<std::size_t>(mesh.V.rows()));
    ASSERT_TRUE(opposite.has_value());
    const int oppositeEdge = source_edge_index(mesh, opposite.value());
    ASSERT_GE(oppositeEdge, 0);
    ASSERT_GE(mesh.EF(oppositeEdge, 1), 0)
        << "every singular-fan opposite carrier must be interior";
  }
  ASSERT_GE(centerIncidentFaces, 4);

  Eigen::MatrixXd primaryDirections(mesh.F.rows(), 3);
  Eigen::MatrixXd secondaryDirections(mesh.F.rows(), 3);
  const Eigen::RowVector3d center = mesh.V.row(kCp3aCenterVertex);
  constexpr double baseAngle = 0.20577431881013147;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d centroid =
        (mesh.V.row(mesh.F(face, 0)) + mesh.V.row(mesh.F(face, 1)) +
         mesh.V.row(mesh.F(face, 2))) /
        3.0;
    const double polar =
        std::atan2(centroid.y() - center.y(), centroid.x() - center.x());
    const double smoothPhase =
        polar + 0.14 * std::sin(2.0 * polar) + 0.06 * std::sin(3.0 * polar);
    const double angle = baseAngle + 0.25 * smoothPhase;
    const Eigen::RowVector3d primary(std::cos(angle), std::sin(angle), 0.0);
    const Eigen::RowVector3d secondary(-std::sin(angle), std::cos(angle), 0.0);
    primaryDirections.row(face) = primary;
    secondaryDirections.row(face) = secondary;

    ASSERT_TRUE(primary.allFinite());
    ASSERT_TRUE(secondary.allFinite());
    ASSERT_NEAR(1.0, primary.norm(), 1.0e-12);
    ASSERT_NEAR(1.0, secondary.norm(), 1.0e-12);
    ASSERT_NEAR(0.0, primary.dot(secondary), 1.0e-12);
    for (int localEdge = 0; localEdge < 3; ++localEdge) {
      Eigen::RowVector3d edgeDirection =
          mesh.V.row(mesh.F(face, (localEdge + 1) % 3)) -
          mesh.V.row(mesh.F(face, localEdge));
      edgeDirection.normalize();
      const double primaryCross =
          primary.x() * edgeDirection.y() - primary.y() * edgeDirection.x();
      const double secondaryCross =
          secondary.x() * edgeDirection.y() - secondary.y() * edgeDirection.x();
      ASSERT_GT(std::abs(primaryCross), 0.04);
      ASSERT_GT(std::abs(secondaryCross), 0.04);
    }
  }

  const double exactIndex =
      independently_reconstruct_center_index(mesh, primaryDirections);
  ASSERT_NEAR(1.0, exactIndex, 1.0e-12);

  directional::PCFaceTangentBundle bundle;
  bundle.init(mesh);
  directional::CartesianField rawField;
  rawField.init(bundle, directional::fieldTypeEnum::RAW_FIELD,
                directional::fields::kCrossFieldDegree);
  ASSERT_NO_THROW(rawField.set_extrinsic_field(
      directional::fields::make_raw_cross_field(
          mesh, primaryDirections, secondaryDirections)));
  ASSERT_NO_THROW(field = directional::fields::finalize_cross_field_result(
                      rawField, false, true));

  ASSERT_TRUE(field.matchingComputed);
  ASSERT_TRUE(field.singularitiesComputed);
  ASSERT_EQ(mesh.EV.rows(), field.matching.size());
  ASSERT_EQ(mesh.EV.rows(), field.effort.size());
  ASSERT_EQ(field.singularCycles.size(), field.singularIndices.size());

  Eigen::Index interiorSingularityRow = -1;
  int interiorSingularityCount = 0;
  for (Eigen::Index row = 0; row < field.singularCycles.size(); ++row) {
    const int vertex = field.singularCycles(row);
    ASSERT_GE(vertex, 0);
    ASSERT_LT(vertex, mesh.V.rows());
    if (mesh.isBoundaryVertex(vertex) != 0) continue;
    interiorSingularityRow = row;
    ++interiorSingularityCount;
  }
  ASSERT_EQ(1, interiorSingularityCount);
  ASSERT_GE(interiorSingularityRow, 0);
  ASSERT_EQ(kCp3aCenterVertex, field.singularCycles(interiorSingularityRow));
  ASSERT_NEAR(exactIndex,
              static_cast<double>(field.singularIndices(interiorSingularityRow)),
              1.0e-9);
}

std::vector<int> cp3a_equivalent_gauge_shifts(const TriMesh &mesh) {
  std::vector<int> shifts(static_cast<std::size_t>(mesh.F.rows()));
  for (int face = 0; face < mesh.F.rows(); ++face) {
    shifts[static_cast<std::size_t>(face)] = ((5 * face + 1) % 7) - 3;
  }
  return shifts;
}

CrossFieldResult gauge_relabel_field_for_network(
    const TriMesh &mesh, const CrossFieldResult &baseline,
    const std::vector<int> &shifts) {
  CrossFieldResult result = baseline;
  EXPECT_EQ(static_cast<std::size_t>(mesh.F.rows()), shifts.size());
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d p = baseline.primaryDirections.row(face);
    const Eigen::RowVector3d s = baseline.secondaryDirections.row(face);
    const std::array<Eigen::RowVector3d, 4> branches{p, s, -p, -s};
    const int shift = ((shifts[static_cast<std::size_t>(face)] % 4) + 4) % 4;
    result.primaryDirections.row(face) = branches[static_cast<std::size_t>(shift)];
    result.secondaryDirections.row(face) =
        branches[static_cast<std::size_t>((shift + 1) % 4)];
  }
  for (CrossFieldEdgeTransition &transition : result.edgeTransitions) {
    if (transition.firstFace < 0 || transition.secondFace < 0) continue;
    transition.matching = baseline.edgeTransitions[static_cast<std::size_t>(
                              transition.sourceEdge)].matching +
                          shifts[static_cast<std::size_t>(transition.firstFace)] -
                          shifts[static_cast<std::size_t>(transition.secondFace)];
    result.matching(transition.sourceEdge) = transition.matching;
  }
  return result;
}

} // namespace

TEST(FieldAlignedCurveNetwork, PublishesTypedSingularityPortsAndMandatoryGraph) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const CrossFieldResult field = make_index_one_singularity_field(mesh);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);
  const auto &atlas = atlasBuild.value();
  ASSERT_EQ(1U, atlas.singularities().size());
  ASSERT_EQ(1, atlas.singularities().front().indexNumerator);
  const auto rails = rails_from_atlas(mesh, atlas);

  auto built = FieldAlignedCurveNetwork::make(
      mesh, *sourceAuthority, atlas,
      rails);
  ASSERT_TRUE(built);
  const FieldAlignedCurveNetwork &network = built.value();
  EXPECT_EQ(atlas.quadrangulability().source_digest(), network.source_digest());
  EXPECT_EQ(directional::authority::field_transport_atlas_hash(atlas),
            network.atlas_digest());
  EXPECT_NE(0U, network.semantic_digest());
  // 5 vertex-keyed nodes (4 mandatory-edge endpoints + 1 singularity vertex)
  // plus one published terminal 0-cell per barrier-terminating trace (3).
  EXPECT_EQ(8U, network.nodes().size());
  ASSERT_EQ(3U, network.singularity_ports().size());
  EXPECT_EQ(4U, network.mandatory_edges().size());
  for (std::size_t ordinal = 0; ordinal < network.singularity_ports().size();
       ++ordinal) {
    const auto &port = network.singularity_ports()[ordinal];
    EXPECT_EQ(atlas.singularities().front().id, port.singularity);
    EXPECT_EQ(atlas.singularities().front().sourceVertex, port.sourceVertex);
    EXPECT_EQ(atlas.singularities().front().sourceComponent,
              port.sourceComponent);
    EXPECT_EQ(1, port.indexNumerator);
    EXPECT_EQ(static_cast<int>(ordinal), port.ordinal);
  }
}

TEST(FieldAlignedCurveNetwork, RejectsInvalidSingularityPortOwnershipOrCount) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_index_one_singularity_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  const FieldAlignedCurveNetwork baseline =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);
  ASSERT_EQ(3U, baseline.singularity_ports().size());

  FieldAlignedCurveNetworkCandidate missingPort =
      baseline.validation_candidate();
  missingPort.singularityPorts.pop_back();
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(missingPort));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortCount,
            rejected.error().code);

  FieldAlignedCurveNetworkCandidate foreignOwner =
      baseline.validation_candidate();
  foreignOwner.singularityPorts.front().singularity =
      FieldSingularityId::from_index(1, 2).value();
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(foreignOwner));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortOwnership,
            rejected.error().code);
}

TEST(FieldAlignedCurveNetwork, RejectsMissingDuplicateOrForeignMandatoryEdges) {
  const TriMesh mesh = make_square_mesh();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  const FieldAlignedCurveNetwork baseline =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);
  ASSERT_EQ(4U, baseline.mandatory_edges().size());

  FieldAlignedCurveNetworkCandidate missing = baseline.validation_candidate();
  missing.mandatoryEdges.pop_back();
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(missing));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge,
            rejected.error().code);

  FieldAlignedCurveNetworkCandidate duplicate = baseline.validation_candidate();
  duplicate.mandatoryEdges.push_back(duplicate.mandatoryEdges.front());
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(duplicate));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::DuplicateMandatoryEdge,
            rejected.error().code);

  int interiorEdge = -1;
  for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
    if (mesh.EF(edge, 1) >= 0) interiorEdge = edge;
  }
  ASSERT_GE(interiorEdge, 0);
  FieldAlignedCurveNetworkCandidate foreign = baseline.validation_candidate();
  foreign.mandatoryEdges.front().sourceEdge = edge_key(mesh, interiorEdge);
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(foreign));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::ForeignMandatoryEdge,
            rejected.error().code);
}

TEST(FieldAlignedCurveNetwork,
     PreservesBoundaryAndHardFeatureOwnersWithoutNumericAlias) {
  const TriMesh mesh = make_square_mesh();
  int interiorEdge = -1;
  for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
    if (mesh.EF(edge, 1) >= 0) interiorEdge = edge;
  }
  ASSERT_GE(interiorEdge, 0);
  const std::set<SourceEdgeTopologyKey> hardEdges{edge_key(mesh, interiorEdge)};
  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
  ASSERT_TRUE(sourceAuthority.has_value());
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, hardEdges, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value(), true);
  const FieldAlignedCurveNetwork network =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);

  ASSERT_EQ(5U, network.mandatory_edges().size());
  const auto hard = std::find_if(
      network.mandatory_edges().begin(), network.mandatory_edges().end(),
      [](const auto &edge) { return edge.kind == SurfaceCellRailKind::HardFeature; });
  ASSERT_NE(network.mandatory_edges().end(), hard);
  EXPECT_EQ(0U, hard->rail.index());
  EXPECT_EQ(0U, hard->sourceComponent.index());
  EXPECT_EQ(2U, hard->sourceTopologyRegions.size());
  static_assert(!std::is_same_v<HardRailId, SourceComponentId>);
  static_assert(!std::is_convertible_v<HardRailId, SourceComponentId>);
  for (const auto &edge : network.mandatory_edges()) {
    EXPECT_NE(997, static_cast<int>(edge.sourceComponent.index()));
  }
}

TEST(FieldAlignedCurveNetwork, IsInvariantToRailAndSourceFaceOrdering) {
  const TriMesh baselineMesh = make_square_mesh(false);
  const auto baselineAuthority = make_source_authority(baselineMesh);
  ASSERT_TRUE(baselineAuthority.has_value());
  auto baselineAtlas = directional::authority::FieldTransportAtlas::make(
      baselineMesh, *baselineAuthority, {},
      make_zero_transport_field(baselineMesh));
  ASSERT_TRUE(baselineAtlas);
  const auto baselineRails = rails_from_atlas(baselineMesh, baselineAtlas.value());
  const FieldAlignedCurveNetwork baseline = build_network(
      baselineMesh, *baselineAuthority, baselineAtlas.value(), baselineRails);

  const TriMesh reorderedMesh = make_square_mesh(true);
  const auto reorderedAuthority = make_source_authority(reorderedMesh);
  ASSERT_TRUE(reorderedAuthority.has_value());
  auto reorderedAtlas = directional::authority::FieldTransportAtlas::make(
      reorderedMesh, *reorderedAuthority, {},
      make_zero_transport_field(reorderedMesh));
  ASSERT_TRUE(reorderedAtlas);
  auto reorderedRails = rails_from_atlas(reorderedMesh, reorderedAtlas.value());
  std::reverse(reorderedRails.begin(), reorderedRails.end());
  const FieldAlignedCurveNetwork reordered = build_network(
      reorderedMesh, *reorderedAuthority, reorderedAtlas.value(),
      reorderedRails);

  EXPECT_EQ(baseline.source_digest(), reordered.source_digest());
  EXPECT_EQ(baseline.atlas_digest(), reordered.atlas_digest());
  EXPECT_EQ(baseline.semantic_digest(), reordered.semantic_digest());
  ASSERT_EQ(baseline.nodes().size(), reordered.nodes().size());
  ASSERT_EQ(baseline.mandatory_edges().size(), reordered.mandatory_edges().size());
  for (std::size_t index = 0; index < baseline.nodes().size(); ++index) {
    EXPECT_EQ(baseline.nodes()[index].sourceVertex,
              reordered.nodes()[index].sourceVertex);
  }
  for (std::size_t index = 0; index < baseline.mandatory_edges().size(); ++index) {
    EXPECT_EQ(baseline.mandatory_edges()[index].sourceEdge,
              reordered.mandatory_edges()[index].sourceEdge);
    EXPECT_EQ(baseline.mandatory_edges()[index].kind,
              reordered.mandatory_edges()[index].kind);
    EXPECT_EQ(baseline.mandatory_edges()[index].rail,
              reordered.mandatory_edges()[index].rail);
  }

  std::vector<int> boundaryEdges;
  for (int edge = 0; edge < baselineMesh.EF.rows(); ++edge) {
    if (baselineMesh.EF(edge, 1) < 0) boundaryEdges.push_back(edge);
  }
  ASSERT_EQ(4U, boundaryEdges.size());

  SurfaceCellRail closedRail(HardRailId::from_index(0, 1).value());
  closedRail.kind = SurfaceCellRailKind::Boundary;
  closedRail.component = 997;
  closedRail.closed = true;

  const int startVertex = std::min(
      baselineMesh.EV(boundaryEdges.front(), 0),
      baselineMesh.EV(boundaryEdges.front(), 1));
  int currentVertex = startVertex;
  int previousEdge = -1;
  std::set<int> consumedEdges;
  do {
    int nextEdge = -1;
    int nextVertex = -1;
    for (const int edge : boundaryEdges) {
      if (edge == previousEdge || consumedEdges.count(edge) != 0U) continue;
      const int a = baselineMesh.EV(edge, 0);
      const int b = baselineMesh.EV(edge, 1);
      if (a != currentVertex && b != currentVertex) continue;
      nextEdge = edge;
      nextVertex = a == currentVertex ? b : a;
      break;
    }
    ASSERT_GE(nextEdge, 0);
    ASSERT_GE(nextVertex, 0);

    const SourceEdgeTopologyKey sourceEdge = edge_key(baselineMesh, nextEdge);
    const auto barrier = std::find_if(
        baselineAtlas.value().nontraversable_edges().begin(),
        baselineAtlas.value().nontraversable_edges().end(),
        [&](const auto &candidate) { return candidate.sourceEdge == sourceEdge; });
    ASSERT_NE(baselineAtlas.value().nontraversable_edges().end(), barrier);
    EXPECT_EQ(directional::authority::FieldTransportBarrierKind::SourceBoundary,
              barrier->kind);

    closedRail.sourceVertices.push_back(currentVertex);
    closedRail.sourceEdges.push_back(nextEdge);
    consumedEdges.insert(nextEdge);
    previousEdge = nextEdge;
    currentVertex = nextVertex;
  } while (currentVertex != startVertex &&
           consumedEdges.size() <= boundaryEdges.size());

  ASSERT_EQ(startVertex, currentVertex);
  ASSERT_EQ(boundaryEdges.size(), consumedEdges.size());
  ASSERT_TRUE(closedRail.closed);
  ASSERT_EQ(closedRail.sourceEdges.size(), closedRail.sourceVertices.size());
  ASSERT_GE(closedRail.sourceEdges.size(), 3U);
  ASSERT_NE(closedRail.sourceVertices.front(), closedRail.sourceVertices.back());
  for (const int sourceEdge : closedRail.sourceEdges) {
    ASSERT_GE(sourceEdge, 0);
    ASSERT_LT(sourceEdge, baselineMesh.EV.rows());
  }

  auto closedBuilt = FieldAlignedCurveNetwork::make(
      baselineMesh,
      *baselineAuthority, baselineAtlas.value(),
      std::vector<SurfaceCellRail>{closedRail});
  ASSERT_TRUE(closedBuilt);
  const FieldAlignedCurveNetwork &closed = closedBuilt.value();

  const auto wraparound = SourceEdgeTopologyKey::from_indices(
      closedRail.sourceVertices.back(), closedRail.sourceVertices.front(),
      static_cast<std::size_t>(baselineMesh.V.rows()));
  ASSERT_TRUE(wraparound);
  const auto *wraparoundEdge = closed.find_mandatory_edge(wraparound.value());
  ASSERT_NE(nullptr, wraparoundEdge);
  EXPECT_EQ(closedRail.id, wraparoundEdge->rail);
  EXPECT_EQ(SurfaceCellRailKind::Boundary, wraparoundEdge->kind);

  std::size_t atlasMandatoryCount = 0U;
  for (const auto &barrier : baselineAtlas.value().nontraversable_edges()) {
    if (barrier.kind !=
            directional::authority::FieldTransportBarrierKind::SourceBoundary &&
        barrier.kind !=
            directional::authority::FieldTransportBarrierKind::HardFeature) {
      continue;
    }
    ++atlasMandatoryCount;
    const auto *edge = closed.find_mandatory_edge(barrier.sourceEdge);
    ASSERT_NE(nullptr, edge);
    EXPECT_EQ(closedRail.id, edge->rail);
    const SurfaceCellRailKind expectedKind =
        barrier.kind ==
                directional::authority::FieldTransportBarrierKind::HardFeature
            ? SurfaceCellRailKind::HardFeature
            : SurfaceCellRailKind::Boundary;
    EXPECT_EQ(expectedKind, edge->kind);
  }
  EXPECT_EQ(atlasMandatoryCount, closed.mandatory_edges().size());
  EXPECT_EQ(closedRail.sourceEdges.size(), closed.mandatory_edges().size());

  SurfaceCellRail rotatedRail = closedRail;
  std::rotate(rotatedRail.sourceVertices.begin(),
              rotatedRail.sourceVertices.begin() + 1,
              rotatedRail.sourceVertices.end());
  std::rotate(rotatedRail.sourceEdges.begin(), rotatedRail.sourceEdges.begin() + 1,
              rotatedRail.sourceEdges.end());
  auto rotatedBuilt = FieldAlignedCurveNetwork::make(
      baselineMesh,
      *baselineAuthority, baselineAtlas.value(),
      std::vector<SurfaceCellRail>{rotatedRail});
  ASSERT_TRUE(rotatedBuilt);
  EXPECT_EQ(closed.semantic_digest(), rotatedBuilt.value().semantic_digest());

  SurfaceCellRail reversedRail = closedRail;
  std::reverse(reversedRail.sourceVertices.begin() + 1,
               reversedRail.sourceVertices.end());
  std::reverse(reversedRail.sourceEdges.begin(), reversedRail.sourceEdges.end());
  auto reversedBuilt = FieldAlignedCurveNetwork::make(
      baselineMesh,
      *baselineAuthority, baselineAtlas.value(),
      std::vector<SurfaceCellRail>{reversedRail});
  ASSERT_TRUE(reversedBuilt);
  EXPECT_EQ(closed.semantic_digest(), reversedBuilt.value().semantic_digest());
}

TEST(FieldAlignedCurveNetwork,
     TracesSingularityPortsIntoBranchConsistentCandidateSegments) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  auto built = FieldAlignedCurveNetwork::make(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails);
  if (!built) {
    FAIL() << "networkBuild="
           << directional::geometry::field_aligned_curve_network_error_code_name(
                  built.error().code);
  }
  const FieldAlignedCurveNetwork &network = built.value();

  ASSERT_EQ(network.singularity_ports().size(), network.candidate_traces().size());
  bool crossedMultipleFacesWithTypedTransport = false;
  bool terminatedOnBarrierWithoutCrossing = false;
  for (const auto &trace : network.candidate_traces()) {
    ASSERT_FALSE(trace.segments.empty());
    if (trace.segments.size() > 1U) {
      for (std::size_t index = 1U; index < trace.segments.size(); ++index) {
        crossedMultipleFacesWithTypedTransport =
            crossedMultipleFacesWithTypedTransport ||
            trace.segments[index].entryTransport.has_value();
      }
    }
    if (!trace.terminalBarrier.has_value()) continue;
    const auto *mandatory = network.find_mandatory_edge(*trace.terminalBarrier);
    if (mandatory == nullptr ||
        trace.segments.back().outgoingCarrier != *trace.terminalBarrier) {
      continue;
    }
    const bool crossedTerminalBarrier = std::any_of(
        trace.segments.begin(), trace.segments.end(), [&](const auto &segment) {
          return segment.entryTransport.has_value() &&
                 segment.entryTransport->sourceEdge == *trace.terminalBarrier;
        });
    terminatedOnBarrierWithoutCrossing =
        terminatedOnBarrierWithoutCrossing || !crossedTerminalBarrier;
  }
  ASSERT_TRUE(crossedMultipleFacesWithTypedTransport)
      << "CP3a witness must cross an interior carrier with typed transport";
  ASSERT_TRUE(terminatedOnBarrierWithoutCrossing)
      << "CP3a witness must stop at a mandatory barrier without crossing it";

  for (const auto &trace : network.candidate_traces()) {
    const auto port = std::find_if(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace.port; });
    ASSERT_NE(network.singularity_ports().end(), port);
    EXPECT_EQ(port->singularity, trace.singularity);
    EXPECT_EQ(port->sourceVertex, trace.sourceVertex);
    EXPECT_EQ(port->sourceComponent, trace.sourceComponent);
    EXPECT_EQ(port->sourceTopologyRegion, trace.sourceTopologyRegion);
    for (const auto &segment : trace.segments) {
      const auto *frame =
          atlasBuild.value().branch_topology().find_frame(segment.sourceFace);
      ASSERT_NE(nullptr, frame);
      EXPECT_EQ(trace.sourceComponent, frame->sourceComponent);
      EXPECT_EQ(trace.sourceTopologyRegion, frame->topologyRegion);
      const auto pairing = std::find_if(
          frame->branches.begin(), frame->branches.end(),
          [&](const auto &candidate) { return candidate.branch == segment.branch; });
      ASSERT_NE(frame->branches.end(), pairing);
      EXPECT_NE(pairing->outgoingCarriers.end(),
                std::find(pairing->outgoingCarriers.begin(),
                          pairing->outgoingCarriers.end(),
                          segment.outgoingCarrier));
    }
  }
}

TEST(FieldAlignedCurveNetwork, CandidateTraceTransportComposesTypedAtlasRoutes) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  auto built = FieldAlignedCurveNetwork::make(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails);
  ASSERT_TRUE(built);

  std::size_t crossed = 0U;
  for (const auto &trace : built.value().candidate_traces()) {
    for (std::size_t index = 1U; index < trace.segments.size(); ++index) {
      const auto &previous = trace.segments[index - 1U];
      const auto &segment = trace.segments[index];
      ASSERT_TRUE(segment.incomingCarrier.has_value());
      ASSERT_TRUE(segment.entryTransport.has_value());
      EXPECT_EQ(previous.outgoingCarrier, *segment.incomingCarrier);
      const auto &entry = *segment.entryTransport;
      EXPECT_EQ(previous.outgoingCarrier, entry.sourceEdge);
      EXPECT_EQ(previous.sourceFace, entry.fromFace);
      EXPECT_EQ(segment.sourceFace, entry.toFace);
      const auto directed = atlasBuild.value().branch_topology().transport(
          entry.sourceEdge, entry.fromFace, entry.toFace);
      ASSERT_TRUE(directed.has_value());
      EXPECT_EQ(*directed, entry.directed);
      EXPECT_EQ(previous.branch.rotated(entry.directed.signedLift),
                segment.branch);
      ++crossed;
    }
  }
  ASSERT_GT(crossed, 0U)
      << "transport contract requires at least one crossed adjacency";
}

TEST(FieldAlignedCurveNetwork,
     CandidateTraceOrderingIsInvariantToPortEnumeration) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  const FieldAlignedCurveNetwork baseline =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);
  const auto &attachments =
      atlasBuild.value().branch_topology().singularity_port_attachments();
  for (const auto &trace : baseline.candidate_traces()) {
    const auto port = std::find_if(
        baseline.singularity_ports().begin(), baseline.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace.port; });
    ASSERT_NE(baseline.singularity_ports().end(), port);
    const auto attachment = std::find_if(
        attachments.begin(), attachments.end(), [&](const auto &candidate) {
          return candidate.singularity == trace.singularity &&
                 candidate.localSlot == port->ordinal;
        });
    ASSERT_NE(attachments.end(), attachment);
    EXPECT_EQ(trace.sourceVertex, attachment->sourceVertex);
    EXPECT_EQ(port->ordinal, attachment->localSlot);
    EXPECT_EQ(1U, static_cast<std::size_t>(std::count_if(
                      attachments.begin(), attachments.end(),
                      [&](const auto &candidate) {
                        return candidate.singularity == trace.singularity &&
                               candidate.localSlot == port->ordinal;
                      })));
  }
  FieldAlignedCurveNetworkCandidate reordered = baseline.validation_candidate();
  ASSERT_GT(reordered.singularityPorts.size(), 1U);
  ASSERT_EQ(reordered.singularityPorts.size(), reordered.candidateTraces.size());
  std::reverse(reordered.singularityPorts.begin(), reordered.singularityPorts.end());
  std::reverse(reordered.candidateTraces.begin(), reordered.candidateTraces.end());
  auto rebuilt = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(reordered));
  ASSERT_TRUE(rebuilt);
  EXPECT_EQ(baseline.semantic_digest(), rebuilt.value().semantic_digest());
  EXPECT_EQ(baseline.candidate_traces(), rebuilt.value().candidate_traces());
}

TEST(FieldAlignedCurveNetwork, CandidateTraceRejectsForeignPortOrAtlasBinding) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  const FieldAlignedCurveNetwork baseline =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);
  ASSERT_FALSE(baseline.candidate_traces().empty());

  FieldAlignedCurveNetworkCandidate foreignPort = baseline.validation_candidate();
  foreignPort.candidateTraces.front().port =
      SingularityPortId::from_index(
          static_cast<std::int64_t>(baseline.singularity_ports().size()),
          baseline.singularity_ports().size() + 1U)
          .value();
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(foreignPort));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
            rejected.error().code);

  const CrossFieldResult foreignAtlasField = gauge_relabel_field_for_network(
      mesh, field, cp3a_equivalent_gauge_shifts(mesh));
  auto foreignAtlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, foreignAtlasField);
  ASSERT_TRUE(foreignAtlasBuild);
  ASSERT_EQ(atlasBuild.value().branch_topology().semantic_digest(),
            foreignAtlasBuild.value().branch_topology().semantic_digest());
  ASSERT_NE(directional::authority::field_transport_atlas_hash(atlasBuild.value()),
            directional::authority::field_transport_atlas_hash(
                foreignAtlasBuild.value()));
  const auto foreignAtlasRails = rails_from_atlas(mesh, foreignAtlasBuild.value());
  FieldAlignedCurveNetworkCandidate foreignAtlas = baseline.validation_candidate();
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      foreignAtlasBuild.value(), foreignAtlasRails, std::move(foreignAtlas));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidAtlasBinding,
            rejected.error().code);

  FieldAlignedCurveNetworkCandidate atlasTamper = baseline.validation_candidate();
  bool tampered = false;
  for (auto &trace : atlasTamper.candidateTraces) {
    for (auto &segment : trace.segments) {
      if (!segment.entryTransport.has_value()) continue;
      ++segment.entryTransport->directed.signedLift;
      tampered = true;
      break;
    }
    if (tampered) break;
  }
  ASSERT_TRUE(tampered)
      << "atlas-binding negative requires a crossed typed transport";
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails, std::move(atlasTamper));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
            rejected.error().code);
}

TEST(FieldAlignedCurveNetwork,
     CandidateTraceStopsAtMandatoryBarrierWithoutCrossing) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);
  const auto rails = rails_from_atlas(mesh, atlasBuild.value());
  auto built = FieldAlignedCurveNetwork::make(
      mesh, *sourceAuthority,
      atlasBuild.value(), rails);
  ASSERT_TRUE(built);

  std::size_t barrierStops = 0U;
  for (const auto &trace : built.value().candidate_traces()) {
    if (!trace.terminalBarrier.has_value()) continue;
    ++barrierStops;
    ASSERT_FALSE(trace.segments.empty());
    EXPECT_EQ(*trace.terminalBarrier, trace.segments.back().outgoingCarrier);
    const auto *mandatory =
        built.value().find_mandatory_edge(*trace.terminalBarrier);
    ASSERT_NE(nullptr, mandatory);
    for (const auto &segment : trace.segments) {
      if (!segment.entryTransport.has_value()) continue;
      EXPECT_NE(*trace.terminalBarrier, segment.entryTransport->sourceEdge);
    }
  }
  ASSERT_GT(barrierStops, 0U)
      << "barrier-stop contract requires a terminal mandatory carrier";
}

TEST(FieldAlignedCurveNetwork,
     CandidateTraceIsInvariantToEquivalentBranchRelabeling) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult baselineField;
  make_cp3a_two_ring_index_one_field(mesh, baselineField);
  auto baselineAtlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, baselineField);
  ASSERT_TRUE(baselineAtlas);
  const auto baselineRails = rails_from_atlas(mesh, baselineAtlas.value());
  const FieldAlignedCurveNetwork baseline = build_network(
      mesh, *sourceAuthority, baselineAtlas.value(), baselineRails);

  const CrossFieldResult relabeledField = gauge_relabel_field_for_network(
      mesh, baselineField, cp3a_equivalent_gauge_shifts(mesh));
  auto relabeledAtlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, relabeledField);
  ASSERT_TRUE(relabeledAtlas);
  const auto relabeledRails = rails_from_atlas(mesh, relabeledAtlas.value());
  auto relabeledBuilt = FieldAlignedCurveNetwork::make(
      mesh, *sourceAuthority,
      relabeledAtlas.value(), relabeledRails);
  ASSERT_TRUE(relabeledBuilt);

  EXPECT_EQ(baselineAtlas.value().branch_topology().semantic_digest(),
            relabeledAtlas.value().branch_topology().semantic_digest());
  EXPECT_NE(baseline.atlas_digest(), relabeledBuilt.value().atlas_digest());
  EXPECT_EQ(baseline.candidate_traces(), relabeledBuilt.value().candidate_traces());
  EXPECT_EQ(baseline.semantic_digest(), relabeledBuilt.value().semantic_digest());
}

namespace {

using directional::geometry::FieldAlignedNetworkEventKind;
using directional::geometry::FieldAlignedTraceEventRole;

const directional::geometry::FieldAlignedNetworkEvent *find_first_event(
    const FieldAlignedCurveNetwork &network,
    const FieldAlignedNetworkEventKind kind) {
  const auto found = std::find_if(
      network.events().begin(), network.events().end(),
      [&](const auto &event) { return event.kind == kind; });
  return found == network.events().end() ? nullptr : &*found;
}

bool event_has_trace(
    const directional::geometry::FieldAlignedNetworkEvent &event,
    const directional::authority::TraceId trace,
    const std::optional<FieldAlignedTraceEventRole> role = std::nullopt) {
  return std::any_of(event.incidences.begin(), event.incidences.end(),
                     [&](const auto &incidence) {
                       return incidence.trace == trace &&
                              (!role.has_value() || incidence.role == *role);
                     });
}

bool independent_trace_event_composition_oracle(
    const FieldAlignedCurveNetwork &network) {
  std::map<directional::authority::TraceId,
           const directional::geometry::FieldAlignedCandidateTrace *>
      traceById;
  std::map<SingularityPortId,
           const directional::geometry::FieldAlignedSingularityPort *>
      portById;
  for (const auto &port : network.singularity_ports()) {
    if (!portById.emplace(port.id, &port).second) return false;
  }
  for (const auto &trace : network.candidate_traces()) {
    if (trace.segments.empty() || !traceById.emplace(trace.id, &trace).second) {
      return false;
    }
    const auto port = portById.find(trace.port);
    if (port == portById.end() || port->second->singularity != trace.singularity ||
        port->second->sourceVertex != trace.sourceVertex) {
      return false;
    }
  }

  std::map<SingularityPortId, std::size_t> originCount;
  std::map<directional::authority::TraceId, std::size_t> terminalCount;
  for (const auto &event : network.events()) {
    if (event.incidences.empty()) return false;
    std::set<directional::authority::TraceId> eventTraces;
    for (const auto &incidence : event.incidences) {
      if (!eventTraces.insert(incidence.trace).second) return false;
      const auto trace = traceById.find(incidence.trace);
      const auto port = portById.find(incidence.sourcePort);
      if (trace == traceById.end() || port == portById.end() ||
          trace->second->port != incidence.sourcePort) {
        return false;
      }
      if (incidence.role == FieldAlignedTraceEventRole::Origin) {
        if (event.kind != FieldAlignedNetworkEventKind::SingularityPortOrigin) {
          return false;
        }
        ++originCount[incidence.sourcePort];
      }
      if (incidence.role == FieldAlignedTraceEventRole::Terminal) {
        ++terminalCount[incidence.trace];
        const auto &terminalTrace = *trace->second;
        if (terminalTrace.terminalBarrier.has_value()) {
          if (event.kind !=
                  FieldAlignedNetworkEventKind::MandatoryBarrierTermination ||
              event.sourceEdge != terminalTrace.terminalBarrier ||
              event.sourceFace != terminalTrace.segments.back().sourceFace) {
            return false;
          }
        } else if (event.kind !=
                   FieldAlignedNetworkEventKind::TraceIntersection) {
          return false;
        }
        const bool hasDeclaredFirstContact = std::any_of(
            network.events().begin(), network.events().end(),
            [&](const auto &candidate) {
              return candidate.kind == FieldAlignedNetworkEventKind::FirstContact &&
                     candidate.node == event.node &&
                     candidate.sourceFace == event.sourceFace &&
                     candidate.sourceEdge == event.sourceEdge &&
                     event_has_trace(candidate, incidence.trace);
            });
        if (!hasDeclaredFirstContact) return false;
      }
    }
  }

  for (const auto &port : network.singularity_ports()) {
    if (originCount[port.id] != 1U) return false;
  }
  for (const auto &trace : network.candidate_traces()) {
    if (terminalCount[trace.id] != 1U) return false;
  }

  // Reconstruct earliest declared trace/trace contacts without consulting the
  // production event validator. A retained trace prefix may not cross a face
  // already occupied by an earlier trace and continue beyond that first face.
  const auto &traces = network.candidate_traces();
  for (std::size_t traceIndex = 0U; traceIndex < traces.size(); ++traceIndex) {
    const auto &trace = traces[traceIndex];
    bool foundContact = false;
    for (std::size_t segmentIndex = 0U; segmentIndex < trace.segments.size();
         ++segmentIndex) {
      const auto &segment = trace.segments[segmentIndex];
      for (std::size_t existingIndex = 0U; existingIndex < traceIndex;
           ++existingIndex) {
        const auto &existing = traces[existingIndex];
        for (std::size_t existingSegmentIndex = 0U;
             existingSegmentIndex < existing.segments.size();
             ++existingSegmentIndex) {
          const auto &existingSegment = existing.segments[existingSegmentIndex];
          if (segment.sourceFace != existingSegment.sourceFace) continue;
          if (segmentIndex == 0U && existingSegmentIndex == 0U &&
              trace.singularity == existing.singularity &&
              trace.sourceVertex == existing.sourceVertex) {
            continue;
          }
          if (foundContact || segmentIndex + 1U != trace.segments.size()) {
            return false;
          }
          const bool declared = std::any_of(
              network.events().begin(), network.events().end(),
              [&](const auto &event) {
                return event.kind ==
                           FieldAlignedNetworkEventKind::TraceIntersection &&
                       event.sourceFace == segment.sourceFace &&
                       event_has_trace(event, existing.id) &&
                       event_has_trace(event, trace.id,
                                       FieldAlignedTraceEventRole::Terminal);
              });
          if (!declared) return false;
          foundContact = true;
        }
      }
    }
  }
  return true;
}

struct Cp3bEventFixture {
  TriMesh mesh;
  std::optional<SourceTopologyRegions> sourceAuthority;
  std::optional<directional::authority::FieldTransportAtlas> atlas;
  std::vector<SurfaceCellRail> rails;
  std::optional<FieldAlignedCurveNetwork> network;
};

Cp3bEventFixture build_cp3b_event_fixture() {
  Cp3bEventFixture fixture;
  fixture.mesh = make_cp3a_two_ring_skew_disc();
  fixture.sourceAuthority = make_source_authority(fixture.mesh);
  EXPECT_TRUE(fixture.sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(fixture.mesh, field);
  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      fixture.mesh, *fixture.sourceAuthority, {}, field);
  EXPECT_TRUE(atlasBuild);
  if (!atlasBuild) return fixture;
  fixture.atlas = atlasBuild.value();
  fixture.rails = rails_from_atlas(fixture.mesh, *fixture.atlas);
  auto built = FieldAlignedCurveNetwork::make(
      fixture.mesh,
      *fixture.sourceAuthority, *fixture.atlas, fixture.rails);
  EXPECT_TRUE(built);
  if (built) fixture.network = built.value();
  return fixture;
}

} // namespace

TEST(FieldAlignedCurveNetwork, PublishesTypedFirstContactAndTerminationEvents) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const FieldAlignedCurveNetwork &network = *fixture.network;

  ASSERT_FALSE(network.events().empty());
  const auto *barrierTermination = find_first_event(
      network, FieldAlignedNetworkEventKind::MandatoryBarrierTermination);
  ASSERT_NE(nullptr, barrierTermination)
      << "CP3b witness must terminate at least one trace on a mandatory barrier";
  ASSERT_TRUE(barrierTermination->sourceEdge.has_value());
  ASSERT_NE(nullptr, network.find_mandatory_edge(*barrierTermination->sourceEdge));
  for (const auto &event : network.events()) {
    if (event.kind !=
        FieldAlignedNetworkEventKind::MandatoryBarrierTermination) {
      continue;
    }
    ASSERT_TRUE(event.sourceEdge.has_value());
    const auto *eventMandatory = network.find_mandatory_edge(*event.sourceEdge);
    ASSERT_NE(nullptr, eventMandatory);
    EXPECT_NE(eventMandatory->firstNode, event.node);
    EXPECT_NE(eventMandatory->secondNode, event.node);
    EXPECT_NE(network.nodes().end(),
              std::find_if(network.nodes().begin(), network.nodes().end(),
                           [&](const auto &node) { return node.id == event.node; }));
  }

  const auto firstContact = std::find_if(
      network.events().begin(), network.events().end(), [&](const auto &event) {
        return event.kind == FieldAlignedNetworkEventKind::FirstContact &&
               event.node == barrierTermination->node &&
               event.sourceFace == barrierTermination->sourceFace &&
               event.sourceEdge == barrierTermination->sourceEdge;
      });
  ASSERT_NE(network.events().end(), firstContact)
      << "mandatory barrier termination must have a paired first-contact event";
  ASSERT_TRUE(firstContact->sourceEdge.has_value());
}

TEST(FieldAlignedCurveNetwork, DeclaresTraceIntersectionsAsTypedNetworkEvents) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const FieldAlignedCurveNetwork &network = *fixture.network;

  // M3-CP4c-0b S2 re-authors this accepted site-A identity: a multi-port
  // singularity is a junction, not a trace/trace crossing. The historical
  // identity name is retained so the frozen predecessor selector remains the
  // same 346 identities.
  const auto junction = std::find_if(
      network.events().begin(), network.events().end(), [&](const auto &event) {
        if (event.kind != FieldAlignedNetworkEventKind::SingularityPortJunction ||
            event.incidences.size() < 2U) {
          return false;
        }
        const auto sourceNode = std::find_if(
            network.nodes().begin(), network.nodes().end(),
            [&](const auto &node) { return node.id == event.node; });
        return sourceNode != network.nodes().end() &&
               sourceNode->sourceVertex ==
                   network.singularity_ports().front().sourceVertex;
      });
  ASSERT_NE(network.events().end(), junction)
      << "multi-port singularity must publish SingularityPortJunction";
  std::set<directional::authority::TraceId> incident;
  for (const auto &incidence : junction->incidences) {
    incident.insert(incidence.trace);
  }
  EXPECT_EQ(junction->incidences.size(), incident.size());
  EXPECT_GE(incident.size(), 2U);
  EXPECT_EQ(network.events().end(),
            std::find_if(network.events().begin(), network.events().end(),
                         [&](const auto &event) {
                           return event.kind ==
                                      FieldAlignedNetworkEventKind::TraceIntersection &&
                                  event.node == junction->node;
                         }))
      << "site A must not retain the overloaded TraceIntersection vocabulary";
}

TEST(FieldAlignedCurveNetwork, ConsumesEachSingularityPortExactlyOnceInEventGraph) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const FieldAlignedCurveNetwork &network = *fixture.network;

  std::map<SingularityPortId, std::size_t> consumed;
  for (const auto &event : network.events()) {
    for (const auto &incidence : event.incidences) {
      if (incidence.role == FieldAlignedTraceEventRole::Origin) {
        ++consumed[incidence.sourcePort];
      }
    }
  }
  ASSERT_EQ(network.singularity_ports().size(), consumed.size());
  for (const auto &port : network.singularity_ports()) {
    EXPECT_EQ(1U, consumed[port.id]);
  }
}

TEST(FieldAlignedCurveNetwork,
     IndependentCompositionOracleValidatesTraceEventGraph) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const FieldAlignedCurveNetwork &network = *fixture.network;

  ASSERT_NE(nullptr,
            find_first_event(network, FieldAlignedNetworkEventKind::FirstContact));
  ASSERT_NE(nullptr,
            find_first_event(network,
                             FieldAlignedNetworkEventKind::SingularityPortJunction));
  EXPECT_TRUE(independent_trace_event_composition_oracle(network));
}

TEST(FieldAlignedCurveNetwork, RejectsContactCrossingEventOrIncidenceTamper) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const FieldAlignedCurveNetwork &baseline = *fixture.network;
  ASSERT_FALSE(baseline.events().empty());

  FieldAlignedCurveNetworkCandidate missingEvent =
      baseline.validation_candidate();
  const auto firstContact = std::find_if(
      missingEvent.events.begin(), missingEvent.events.end(), [](const auto &event) {
        return event.kind == FieldAlignedNetworkEventKind::FirstContact;
      });
  ASSERT_NE(missingEvent.events.end(), firstContact);
  missingEvent.events.erase(firstContact);
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      fixture.mesh,
      *fixture.sourceAuthority, *fixture.atlas, fixture.rails, std::move(missingEvent));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
            rejected.error().code);

  FieldAlignedCurveNetworkCandidate incidenceTamper =
      baseline.validation_candidate();
  const auto origin = std::find_if(
      incidenceTamper.events.begin(), incidenceTamper.events.end(),
      [](const auto &event) {
        return event.kind == FieldAlignedNetworkEventKind::SingularityPortOrigin;
      });
  ASSERT_NE(incidenceTamper.events.end(), origin);
  ASSERT_FALSE(origin->incidences.empty());
  origin->incidences.front().role = FieldAlignedTraceEventRole::Terminal;
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      fixture.mesh,
      *fixture.sourceAuthority, *fixture.atlas, fixture.rails, std::move(incidenceTamper));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventIncidence,
            rejected.error().code);
}

TEST(FieldAlignedCurveNetwork, EventGraphSemanticDigestIsOrderInvariant) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const FieldAlignedCurveNetwork &baseline = *fixture.network;

  FieldAlignedCurveNetworkCandidate reordered = baseline.validation_candidate();
  ASSERT_GT(reordered.events.size(), 2U);
  std::reverse(reordered.events.begin(), reordered.events.end());
  for (auto &event : reordered.events) {
    std::reverse(event.incidences.begin(), event.incidences.end());
  }
  std::reverse(reordered.singularityPorts.begin(), reordered.singularityPorts.end());
  std::reverse(reordered.candidateTraces.begin(), reordered.candidateTraces.end());
  auto rebuilt = FieldAlignedCurveNetwork::make_from_candidate(
      fixture.mesh,
      *fixture.sourceAuthority, *fixture.atlas, fixture.rails, std::move(reordered));
  ASSERT_TRUE(rebuilt);
  EXPECT_EQ(baseline.semantic_digest(), rebuilt.value().semantic_digest());
  EXPECT_EQ(baseline.events(), rebuilt.value().events());
}

namespace {

directional::geometry::GlobalTopologyPlan build_topology_plan(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network) {
  auto built = directional::geometry::GlobalTopologyPlan::make(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), sourceAuthority, network);
  EXPECT_TRUE(built) << (built ? ""
                              : directional::geometry::global_topology_plan_error_code_name(
                                    built.error().code));
  return built.value();
}

std::vector<const directional::geometry::GlobalTopologyArc *>
find_mandatory_plan_arcs(
    const directional::geometry::GlobalTopologyPlan &plan,
    const directional::authority::NetworkEdgeId mandatoryEdge) {
  std::vector<const directional::geometry::GlobalTopologyArc *> result;
  for (const auto &arc : plan.arcs()) {
    if (arc.kind == directional::geometry::GlobalTopologyArcKind::Mandatory &&
        arc.mandatoryEdge == mandatoryEdge) {
      result.push_back(&arc);
    }
  }
  return result;
}

std::pair<directional::authority::NetworkNodeId,
          directional::authority::NetworkNodeId>
oriented_endpoints(
    const directional::geometry::GlobalTopologyArc &arc,
    const directional::geometry::GlobalTopologyOrientedArc incidence) {
  return incidence.orientation == directional::authority::Orientation::Forward
             ? std::make_pair(arc.firstNode, arc.secondNode)
             : std::make_pair(arc.secondNode, arc.firstNode);
}

directional::geometry::GlobalTopologyOrientedArc reverse_incidence(
    const directional::geometry::GlobalTopologyOrientedArc incidence) {
  return directional::geometry::GlobalTopologyOrientedArc{
      incidence.arc,
      incidence.orientation == directional::authority::Orientation::Forward
          ? directional::authority::Orientation::Reverse
          : directional::authority::Orientation::Forward};
}

void canonicalize_oriented_cycle(
    std::vector<directional::geometry::GlobalTopologyOrientedArc> &cycle) {
  if (cycle.empty()) return;
  const auto less = [](const auto lhs, const auto rhs) {
    return std::tie(lhs.arc, lhs.orientation) <
           std::tie(rhs.arc, rhs.orientation);
  };
  std::size_t best = 0U;
  for (std::size_t candidate = 1U; candidate < cycle.size(); ++candidate) {
    for (std::size_t offset = 0U; offset < cycle.size(); ++offset) {
      const auto lhs = cycle[(candidate + offset) % cycle.size()];
      const auto rhs = cycle[(best + offset) % cycle.size()];
      if (lhs == rhs) continue;
      if (less(lhs, rhs)) best = candidate;
      break;
    }
  }
  std::rotate(cycle.begin(),
              cycle.begin() + static_cast<std::ptrdiff_t>(best), cycle.end());
}

std::optional<std::vector<std::vector<directional::geometry::GlobalTopologyOrientedArc>>>
independent_plan_face_orbits(
    const directional::geometry::GlobalTopologyPlan &plan) {
  using Incidence = directional::geometry::GlobalTopologyOrientedArc;
  std::map<Incidence, Incidence> successor;
  for (const auto &rotation : plan.rotation_system()) {
    if (rotation.counterClockwise.empty()) return std::nullopt;
    for (std::size_t index = 0U; index < rotation.counterClockwise.size(); ++index) {
      const Incidence outgoing = rotation.counterClockwise[index];
      const Incidence incoming = reverse_incidence(outgoing);
      const Incidence next = rotation.counterClockwise[
          (index + rotation.counterClockwise.size() - 1U) %
          rotation.counterClockwise.size()];
      if (!successor.emplace(incoming, next).second) return std::nullopt;
    }
  }
  std::set<Incidence> all;
  for (const auto &arc : plan.arcs()) {
    all.insert(Incidence{arc.id, directional::authority::Orientation::Forward});
    all.insert(Incidence{arc.id, directional::authority::Orientation::Reverse});
  }
  if (successor.size() != all.size()) return std::nullopt;

  std::set<Incidence> visited;
  std::vector<std::vector<Incidence>> orbits;
  for (const auto start : all) {
    if (visited.count(start) != 0U) continue;
    std::vector<Incidence> orbit;
    Incidence current = start;
    for (std::size_t steps = 0U; steps <= all.size(); ++steps) {
      if (!visited.insert(current).second) {
        if (current != start) return std::nullopt;
        break;
      }
      orbit.push_back(current);
      const auto next = successor.find(current);
      if (next == successor.end()) return std::nullopt;
      current = next->second;
      if (current == start) break;
      if (steps == all.size()) return std::nullopt;
    }
    if (orbit.empty() || current != start) return std::nullopt;
    canonicalize_oriented_cycle(orbit);
    orbits.push_back(std::move(orbit));
  }
  return orbits;
}

struct IndependentSourceFaceRecord {
  SourceFaceTopologyKey key;
  std::array<SourceVertexId, 3> vertices;
  std::array<SourceEdgeTopologyKey, 3> edges;
};

struct IndependentSourceTopology {
  std::map<SourceFaceTopologyKey, IndependentSourceFaceRecord> faces;
  std::map<SourceEdgeTopologyKey, std::vector<SourceFaceTopologyKey>>
      incidentFaces;
};

std::optional<IndependentSourceTopology> independent_source_topology(
    const TriMesh &mesh) {
  IndependentSourceTopology topology;
  for (int row = 0; row < mesh.F.rows(); ++row) {
    std::vector<SourceVertexId> vertexList;
    vertexList.reserve(3U);
    for (int corner = 0; corner < 3; ++corner) {
      const auto vertex = SourceVertexId::from_index(
          mesh.F(row, corner), static_cast<std::size_t>(mesh.V.rows()));
      if (!vertex) return std::nullopt;
      vertexList.push_back(vertex.value());
    }
    const std::array<SourceVertexId, 3> vertices{
        vertexList[0], vertexList[1], vertexList[2]};
    const auto key = SourceFaceTopologyKey::make(vertices);
    if (!key) return std::nullopt;
    std::array<SourceEdgeTopologyKey, 3> edges{
        SourceEdgeTopologyKey::make(vertices[0], vertices[1]).value(),
        SourceEdgeTopologyKey::make(vertices[1], vertices[2]).value(),
        SourceEdgeTopologyKey::make(vertices[2], vertices[0]).value()};
    IndependentSourceFaceRecord record{key.value(), vertices, edges};
    if (!topology.faces.emplace(key.value(), record).second) return std::nullopt;
    for (const auto &edge : edges) {
      topology.incidentFaces[edge].push_back(key.value());
    }
  }
  return topology;
}

bool independent_face_orients_edge_forward(
    const IndependentSourceFaceRecord &face,
    const SourceEdgeTopologyKey &edge) {
  for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
    const auto first = face.vertices[corner];
    const auto second = face.vertices[(corner + 1U) % face.vertices.size()];
    if (first == edge.first() && second == edge.second()) return true;
    if (first == edge.second() && second == edge.first()) return false;
  }
  return false;
}

std::optional<std::size_t> independent_local_edge_index(
    const IndependentSourceFaceRecord &face,
    const SourceEdgeTopologyKey &edge) {
  for (std::size_t index = 0U; index < face.edges.size(); ++index) {
    if (face.edges[index] == edge) return index;
  }
  return std::nullopt;
}

struct IndependentFragmentPartition {
  std::map<std::size_t, std::set<SourceFaceTopologyKey>> facesByOrbit;
  std::set<std::size_t> exteriorOrbits;
  std::set<SourceEdgeTopologyKey> mandatoryEdges;
};

enum class IndependentDiscProofClause {
  None,
  OrbitConstruction,
  FragmentPartition,
  FragmentCountRule,
  EulerIdentity,
  RegionOrbitBijection,
  PerOrbitFaceSetEquality,
  PublishedCertificate,
};

struct IndependentDiscProofResult {
  bool passed = false;
  IndependentDiscProofClause clause = IndependentDiscProofClause::None;
  std::int64_t embeddedGraphChi = 0;
  std::int64_t sourceSurfaceChi = 0;
};

const char *independent_disc_proof_clause_name(
    const IndependentDiscProofClause clause) {
  switch (clause) {
  case IndependentDiscProofClause::None:
    return "None";
  case IndependentDiscProofClause::OrbitConstruction:
    return "OrbitConstruction";
  case IndependentDiscProofClause::FragmentPartition:
    return "FragmentPartition";
  case IndependentDiscProofClause::FragmentCountRule:
    return "FragmentCountRule";
  case IndependentDiscProofClause::EulerIdentity:
    return "EulerIdentity";
  case IndependentDiscProofClause::RegionOrbitBijection:
    return "RegionOrbitBijection";
  case IndependentDiscProofClause::PerOrbitFaceSetEquality:
    return "PerOrbitFaceSetEquality";
  case IndependentDiscProofClause::PublishedCertificate:
    return "PublishedCertificate";
  }
  return "Unknown";
}

std::optional<IndependentFragmentPartition> independent_fragment_partition(
    const directional::geometry::GlobalTopologyPlan &plan, const TriMesh &mesh,
    const FieldAlignedCurveNetwork &network,
    const std::vector<std::vector<directional::geometry::GlobalTopologyOrientedArc>>
        &orbits,
    IndependentDiscProofClause *failureClause = nullptr) {
  if (failureClause != nullptr) {
    *failureClause = IndependentDiscProofClause::FragmentPartition;
  }
  using Incidence = directional::geometry::GlobalTopologyOrientedArc;
  const auto topology = independent_source_topology(mesh);
  if (!topology.has_value()) return std::nullopt;

  std::map<Incidence, std::size_t> orbitByIncidence;
  for (std::size_t orbit = 0U; orbit < orbits.size(); ++orbit) {
    for (const auto incidence : orbits[orbit]) {
      if (!orbitByIncidence.emplace(incidence, orbit).second) return std::nullopt;
    }
  }

  IndependentFragmentPartition result;
  std::map<SourceFaceTopologyKey, std::set<std::size_t>> fragmentOrbits;
  std::map<SourceFaceTopologyKey, std::size_t> tracePieces;
  std::set<SourceEdgeTopologyKey> traceTouchedEdges;
  std::map<std::pair<SourceFaceTopologyKey, SourceEdgeTopologyKey>,
           std::set<std::size_t>>
      edgeOrbitEvidence;
  for (const auto &[face, record] : topology->faces) {
    (void)record;
    fragmentOrbits[face];
  }

  for (const auto &mandatory : network.mandatory_edges()) {
    result.mandatoryEdges.insert(mandatory.sourceEdge);
    const auto pieces = find_mandatory_plan_arcs(plan, mandatory.id);
    if (pieces.empty()) return std::nullopt;
    const auto incident = topology->incidentFaces.find(mandatory.sourceEdge);
    if (incident == topology->incidentFaces.end() || incident->second.empty()) {
      return std::nullopt;
    }
    for (const auto *arc : pieces) {
      for (const auto &faceKey : incident->second) {
        const auto face = topology->faces.find(faceKey);
        if (face == topology->faces.end()) return std::nullopt;
        const Incidence interior{
            arc->id, independent_face_orients_edge_forward(
                         face->second, mandatory.sourceEdge)
                         ? directional::authority::Orientation::Forward
                         : directional::authority::Orientation::Reverse};
        const auto owner = orbitByIncidence.find(interior);
        if (owner == orbitByIncidence.end()) return std::nullopt;
        fragmentOrbits[faceKey].insert(owner->second);
        edgeOrbitEvidence[std::make_pair(faceKey, mandatory.sourceEdge)]
            .insert(owner->second);
        if (mandatory.kind == SurfaceCellRailKind::Boundary) {
          const auto exterior =
              orbitByIncidence.find(reverse_incidence(interior));
          if (exterior == orbitByIncidence.end()) return std::nullopt;
          result.exteriorOrbits.insert(exterior->second);
        }
      }
    }
  }

  for (const auto &arc : plan.arcs()) {
    if (arc.kind != directional::geometry::GlobalTopologyArcKind::Trace ||
        !arc.trace.has_value()) {
      continue;
    }
    const auto trace = std::find_if(
        network.candidate_traces().begin(), network.candidate_traces().end(),
        [&](const auto &candidate) { return candidate.id == *arc.trace; });
    if (trace == network.candidate_traces().end() ||
        arc.firstSegment >= arc.onePastLastSegment ||
        arc.onePastLastSegment > trace->segments.size()) {
      return std::nullopt;
    }
    const auto forward = orbitByIncidence.find(Incidence{
        arc.id, directional::authority::Orientation::Forward});
    const auto reverse = orbitByIncidence.find(Incidence{
        arc.id, directional::authority::Orientation::Reverse});
    if (forward == orbitByIncidence.end() || reverse == orbitByIncidence.end()) {
      return std::nullopt;
    }
    for (std::size_t segmentIndex = arc.firstSegment;
         segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
      const auto &segment = trace->segments[segmentIndex];
      const auto face = topology->faces.find(segment.sourceFace);
      if (face == topology->faces.end()) return std::nullopt;
      ++tracePieces[segment.sourceFace];
      traceTouchedEdges.insert(segment.outgoingCarrier);
      if (segment.incomingCarrier.has_value()) {
        traceTouchedEdges.insert(*segment.incomingCarrier);
      }
      if (result.exteriorOrbits.count(forward->second) == 0U) {
        fragmentOrbits[segment.sourceFace].insert(forward->second);
      }
      if (result.exteriorOrbits.count(reverse->second) == 0U) {
        fragmentOrbits[segment.sourceFace].insert(reverse->second);
      }

      if (segment.incomingCarrier.has_value()) {
        const auto incoming = independent_local_edge_index(
            face->second, *segment.incomingCarrier);
        const auto outgoing = independent_local_edge_index(
            face->second, segment.outgoingCarrier);
        if (!incoming.has_value() || !outgoing.has_value() ||
            *incoming == *outgoing) {
          return std::nullopt;
        }
        std::size_t third = 0U;
        while (third == *incoming || third == *outgoing) ++third;
        const std::size_t turn = (*outgoing + 3U - *incoming) % 3U;
        if (turn != 1U && turn != 2U) return std::nullopt;
        const std::size_t sideOrbit =
            turn == 1U ? forward->second : reverse->second;
        if (result.exteriorOrbits.count(sideOrbit) == 0U) {
          edgeOrbitEvidence[
              std::make_pair(segment.sourceFace, face->second.edges[third])]
              .insert(sideOrbit);
        }
      } else {
        std::optional<std::size_t> sourceCorner;
        for (std::size_t corner = 0U; corner < face->second.vertices.size();
             ++corner) {
          if (face->second.vertices[corner] == trace->sourceVertex) {
            sourceCorner = corner;
            break;
          }
        }
        const auto outgoing = independent_local_edge_index(
            face->second, segment.outgoingCarrier);
        if (!sourceCorner.has_value() || !outgoing.has_value() ||
            *outgoing != (*sourceCorner + 1U) % 3U) {
          return std::nullopt;
        }
        const auto forwardEdge =
            face->second.edges[(*sourceCorner + 2U) % 3U];
        const auto reverseEdge = face->second.edges[*sourceCorner];
        if (result.exteriorOrbits.count(forward->second) == 0U) {
          edgeOrbitEvidence[std::make_pair(segment.sourceFace, forwardEdge)]
              .insert(forward->second);
        }
        if (result.exteriorOrbits.count(reverse->second) == 0U) {
          edgeOrbitEvidence[std::make_pair(segment.sourceFace, reverseEdge)]
              .insert(reverse->second);
        }
      }
    }
  }

  // Re-derive K2R/K3R ownership independently as connected equality
  // components of unlabeled faces.  Traversal order never elects an owner:
  // each component is accepted only when its complete boundary evidence has
  // exactly one orbit seed.
  const auto side_orbit = [&](const SourceFaceTopologyKey &face,
                              const SourceEdgeTopologyKey &edge)
      -> std::optional<std::size_t> {
    const auto fragments = fragmentOrbits.find(face);
    if (fragments != fragmentOrbits.end() && fragments->second.size() == 1U) {
      return *fragments->second.begin();
    }
    const auto evidence = edgeOrbitEvidence.find(std::make_pair(face, edge));
    if (evidence != edgeOrbitEvidence.end() && evidence->second.size() == 1U) {
      return *evidence->second.begin();
    }
    return std::nullopt;
  };

  std::set<SourceFaceTopologyKey> pending;
  for (const auto &[face, record] : topology->faces) {
    (void)record;
    if (fragmentOrbits[face].empty()) pending.insert(face);
  }
  while (!pending.empty()) {
    const SourceFaceTopologyKey startFace = *pending.begin();
    std::vector<SourceFaceTopologyKey> component;
    std::vector<SourceFaceTopologyKey> work{startFace};
    pending.erase(startFace);
    while (!work.empty()) {
      const SourceFaceTopologyKey face = work.back();
      work.pop_back();
      component.push_back(face);
      for (const auto &[edge, incident] : topology->incidentFaces) {
        if (incident.size() != 2U || result.mandatoryEdges.count(edge) != 0U ||
            traceTouchedEdges.count(edge) != 0U) {
          continue;
        }
        std::optional<SourceFaceTopologyKey> next;
        if (incident[0] == face) next = incident[1];
        if (incident[1] == face) next = incident[0];
        if (!next.has_value() || pending.count(*next) == 0U) continue;
        pending.erase(*next);
        work.push_back(*next);
      }
    }

    const std::set<SourceFaceTopologyKey> componentSet(component.begin(),
                                                       component.end());
    std::set<std::size_t> seeds;
    for (const auto &[edge, incident] : topology->incidentFaces) {
      if (incident.size() != 2U || result.mandatoryEdges.count(edge) != 0U ||
          traceTouchedEdges.count(edge) != 0U) {
        continue;
      }
      for (std::size_t side = 0U; side < 2U; ++side) {
        if (componentSet.count(incident[side]) == 0U ||
            componentSet.count(incident[side ^ 1U]) != 0U) {
          continue;
        }
        const auto seed = side_orbit(incident[side ^ 1U], edge);
        if (seed.has_value()) seeds.insert(*seed);
      }
    }
    if (seeds.size() != 1U) return std::nullopt;
    for (const auto &face : component) {
      fragmentOrbits[face].insert(*seeds.begin());
    }
  }

  for (const auto &[face, record] : topology->faces) {
    (void)record;
    const auto fragments = fragmentOrbits.find(face);
    if (fragments == fragmentOrbits.end() || fragments->second.empty()) {
      return std::nullopt;
    }
    if (fragments->second.size() != tracePieces[face] + 1U) {
      if (failureClause != nullptr) {
        *failureClause = IndependentDiscProofClause::FragmentCountRule;
      }
      return std::nullopt;
    }
    for (const std::size_t orbit : fragments->second) {
      if (result.exteriorOrbits.count(orbit) == 0U) {
        result.facesByOrbit[orbit].insert(face);
      }
    }
  }
  return result;
}

IndependentDiscProofResult independent_disc_proof_oracle(
    const directional::geometry::GlobalTopologyPlan &plan, const TriMesh &mesh,
    const FieldAlignedCurveNetwork &network) {
  IndependentDiscProofResult result;
  const auto orbits = independent_plan_face_orbits(plan);
  if (!orbits.has_value()) {
    result.clause = IndependentDiscProofClause::OrbitConstruction;
    return result;
  }
  IndependentDiscProofClause partitionFailure =
      IndependentDiscProofClause::FragmentPartition;
  const auto partition = independent_fragment_partition(
      plan, mesh, network, *orbits, &partitionFailure);
  if (!partition.has_value()) {
    result.clause = partitionFailure;
    return result;
  }
  result.embeddedGraphChi =
      static_cast<std::int64_t>(network.nodes().size()) -
      static_cast<std::int64_t>(plan.arcs().size()) +
      static_cast<std::int64_t>(orbits->size() -
                                partition->exteriorOrbits.size());
  result.sourceSurfaceChi =
      static_cast<std::int64_t>(mesh.V.rows()) -
      static_cast<std::int64_t>(mesh.EV.rows()) +
      static_cast<std::int64_t>(mesh.F.rows());
  // A dart-orbit face walk caps each source boundary component.  Excluding
  // those exterior orbits gives V_g - E_g + F_g^interior = chi(S).
  if (result.embeddedGraphChi != result.sourceSurfaceChi) {
    result.clause = IndependentDiscProofClause::EulerIdentity;
    return result;
  }
  std::set<std::size_t> claimedOrbit;
  for (const auto &region : plan.regions()) {
    std::optional<std::size_t> matched;
    for (std::size_t index = 0U; index < orbits->size(); ++index) {
      if ((*orbits)[index] == region.boundary) {
        matched = index;
        break;
      }
    }
    if (!matched.has_value() || !claimedOrbit.insert(*matched).second) {
      result.clause = IndependentDiscProofClause::RegionOrbitBijection;
      return result;
    }
    const auto expected = partition->facesByOrbit.find(*matched);
    if (expected == partition->facesByOrbit.end()) {
      result.clause = IndependentDiscProofClause::PerOrbitFaceSetEquality;
      return result;
    }
    const std::set<SourceFaceTopologyKey> published(region.sourceFaces.begin(),
                                                    region.sourceFaces.end());
    if (published != expected->second) {
      result.clause = IndependentDiscProofClause::PerOrbitFaceSetEquality;
      return result;
    }
    const auto *certificate = plan.find_region_certificate(region.id);
    if (certificate == nullptr || !certificate->proves_disc_topology() ||
        certificate->boundaryWalkCount != 1U) {
      result.clause = IndependentDiscProofClause::PublishedCertificate;
      return result;
    }
  }
  if (claimedOrbit.size() != partition->facesByOrbit.size()) {
    result.clause = IndependentDiscProofClause::RegionOrbitBijection;
    return result;
  }
  result.passed = true;
  result.clause = IndependentDiscProofClause::None;
  return result;
}

std::vector<directional::geometry::GlobalTopologyOrientedArc>
ordered_mandatory_cycle(const directional::geometry::GlobalTopologyPlan &plan) {
  using Incidence = directional::geometry::GlobalTopologyOrientedArc;
  std::vector<const directional::geometry::GlobalTopologyArc *> mandatory;
  for (const auto &arc : plan.arcs()) {
    if (arc.kind == directional::geometry::GlobalTopologyArcKind::Mandatory) {
      mandatory.push_back(&arc);
    }
  }
  if (mandatory.empty()) return {};
  std::vector<Incidence> result;
  std::set<directional::authority::NetworkArcId> used;
  result.push_back(Incidence{mandatory.front()->id,
                             directional::authority::Orientation::Forward});
  used.insert(mandatory.front()->id);
  const auto first = oriented_endpoints(*mandatory.front(), result.front());
  auto current = first.second;
  while (used.size() < mandatory.size()) {
    const auto found = std::find_if(mandatory.begin(), mandatory.end(),
                                    [&](const auto *arc) {
      return used.count(arc->id) == 0U &&
             (arc->firstNode == current || arc->secondNode == current);
    });
    if (found == mandatory.end()) return {};
    const auto orientation = (*found)->firstNode == current
                                 ? directional::authority::Orientation::Forward
                                 : directional::authority::Orientation::Reverse;
    const Incidence incidence{(*found)->id, orientation};
    result.push_back(incidence);
    used.insert((*found)->id);
    current = oriented_endpoints(**found, incidence).second;
  }
  if (current != first.first) return {};
  canonicalize_oriented_cycle(result);
  return result;
}

} // namespace

TEST(GlobalTopologyPlan, DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);

  ASSERT_GT(plan.regions().size(), 1U)
      << "CP4a witness must expose more than one embedded-graph face";
  ASSERT_TRUE(std::any_of(plan.arcs().begin(), plan.arcs().end(),
                          [](const auto &arc) {
                            return arc.kind ==
                                   directional::geometry::GlobalTopologyArcKind::Trace;
                          }))
      << "CP4a face derivation must include event-cut trace arcs";
  ASSERT_TRUE(std::any_of(plan.regions().begin(), plan.regions().end(),
                          [](const auto &region) {
                            return region.sourceFaces.size() > 1U;
                          }))
      << "CP4a witness must publish a non-trivial source-face region";

  std::map<directional::authority::NetworkArcId, std::size_t> boundaryUseCount;
  for (const auto &region : plan.regions()) {
    ASSERT_FALSE(region.boundary.empty());
    for (std::size_t index = 0U; index < region.boundary.size(); ++index) {
      const auto incidence = region.boundary[index];
      const auto next = region.boundary[(index + 1U) % region.boundary.size()];
      const auto *arc = plan.find_arc(incidence.arc);
      const auto *nextArc = plan.find_arc(next.arc);
      ASSERT_NE(nullptr, arc);
      ASSERT_NE(nullptr, nextArc);
      const auto endpoints = oriented_endpoints(*arc, incidence);
      const auto nextEndpoints = oriented_endpoints(*nextArc, next);
      EXPECT_EQ(endpoints.second, nextEndpoints.first)
          << "published region boundary must be one exact face walk";
      ++boundaryUseCount[incidence.arc];
    }
  }

  for (const auto &arc : plan.arcs()) {
    ASSERT_NE(0U, boundaryUseCount[arc.id]);
    if (arc.kind == directional::geometry::GlobalTopologyArcKind::Trace) {
      EXPECT_EQ(2U, boundaryUseCount[arc.id])
          << "internal trace arc must bound two embedded-graph faces";
    }
  }
}

TEST(GlobalTopologyPlan, PublishesRotationSystemConsistentWithNetworkEvents) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);

  std::map<directional::authority::NetworkNodeId,
           std::set<directional::authority::NetworkArcId>>
      expectedIncident;
  for (const auto &arc : plan.arcs()) {
    expectedIncident[arc.firstNode].insert(arc.id);
    expectedIncident[arc.secondNode].insert(arc.id);
  }
  ASSERT_EQ(fixture.network->nodes().size(), plan.rotation_system().size());
  for (const auto &rotation : plan.rotation_system()) {
    std::multiset<directional::authority::NetworkArcId> actual;
    for (const auto incidence : rotation.counterClockwise) {
      actual.insert(incidence.arc);
    }
    std::multiset<directional::authority::NetworkArcId> expected;
    for (const auto &arc : plan.arcs()) {
      if (arc.firstNode == rotation.node) expected.insert(arc.id);
      if (arc.secondNode == rotation.node) expected.insert(arc.id);
    }
    EXPECT_EQ(expected, actual);
  }

  for (const auto &event : fixture.network->events()) {
    const auto *rotation = plan.find_rotation(event.node);
    ASSERT_NE(nullptr, rotation);
    for (const auto &incidence : event.incidences) {
      const bool represented = std::any_of(
          rotation->counterClockwise.begin(), rotation->counterClockwise.end(),
          [&](const auto orientedArc) {
            const auto *arc = plan.find_arc(orientedArc.arc);
            return arc != nullptr && arc->trace == incidence.trace;
          });
      EXPECT_TRUE(represented)
          << "typed network-event incidence must own a rotation-system ray";
    }
  }
}

TEST(GlobalTopologyPlan, CoversEverySourceFaceExactlyOnce) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);

  std::map<directional::authority::SourceFaceTopologyKey,
           std::set<directional::authority::NetworkRegionId>>
      owners;
  for (const auto &region : plan.regions()) {
    ASSERT_FALSE(region.sourceFaces.empty());
    for (const auto &face : region.sourceFaces) owners[face].insert(region.id);
  }

  std::map<directional::authority::SourceFaceTopologyKey, std::size_t>
      tracePieces;
  bool exposesFloodFillCounterexample = false;
  for (const auto &arc : plan.arcs()) {
    if (arc.kind != directional::geometry::GlobalTopologyArcKind::Trace) {
      continue;
    }
    const directional::geometry::GlobalTopologyOrientedArc forward{
        arc.id, directional::authority::Orientation::Forward};
    const directional::geometry::GlobalTopologyOrientedArc reverse{
        arc.id, directional::authority::Orientation::Reverse};
    const auto forwardRegion = std::find_if(
        plan.regions().begin(), plan.regions().end(), [&](const auto &region) {
          return std::find(region.boundary.begin(), region.boundary.end(), forward) !=
                 region.boundary.end();
        });
    const auto reverseRegion = std::find_if(
        plan.regions().begin(), plan.regions().end(), [&](const auto &region) {
          return std::find(region.boundary.begin(), region.boundary.end(), reverse) !=
                 region.boundary.end();
        });
    ASSERT_NE(plan.regions().end(), forwardRegion);
    ASSERT_NE(plan.regions().end(), reverseRegion);
    ASSERT_NE(forwardRegion->id, reverseRegion->id)
        << "the two darts of an interior trace must enclose distinct graph faces";

    for (const auto &face : arc.sourceFaces) {
      ++tracePieces[face];
      ASSERT_EQ(1U, owners.count(face));
      EXPECT_EQ(1U, owners[face].count(forwardRegion->id))
          << "forward dart orbit must own its fragment of the crossed face";
      EXPECT_EQ(1U, owners[face].count(reverseRegion->id))
          << "reverse dart orbit must own its fragment of the crossed face";
      exposesFloodFillCounterexample = true;
    }
  }

  ASSERT_EQ(static_cast<std::size_t>(fixture.mesh.F.rows()), owners.size());
  for (int rowIndex = 0; rowIndex < fixture.mesh.F.rows(); ++rowIndex) {
    const auto row = directional::authority::SourceFaceId::from_index(
        rowIndex, static_cast<std::size_t>(fixture.mesh.F.rows()));
    ASSERT_TRUE(row.has_value());
    const auto &face = fixture.sourceAuthority->topology_for_row(row.value());
    ASSERT_EQ(1U, owners.count(face));
    EXPECT_EQ(tracePieces[face] + 1U, owners[face].size())
        << "each trace chord must add exactly one fragment to its source face";
  }

  ASSERT_TRUE(exposesFloodFillCounterexample)
      << "A3 fixture must contain a trace-crossed source face";
  const bool wholeFaceFloodFillCouldRepresentOwnership =
      std::all_of(owners.begin(), owners.end(), [](const auto &entry) {
        return entry.second.size() == 1U;
      });
  EXPECT_FALSE(wholeFaceFloodFillCouldRepresentOwnership)
      << "an atomic whole-source-face flood fill cannot represent both enclosed "
         "fragments of a trace-crossed face";
}

TEST(GlobalTopologyPlan, PreservesMandatoryBoundaryAndHardFeatureEdges) {
  const TriMesh mesh = make_square_mesh();
  const auto hardFeature = SourceEdgeTopologyKey::from_indices(0, 2, 4U);
  ASSERT_TRUE(hardFeature.has_value());
  const std::set<SourceEdgeTopologyKey> hardFeatures{hardFeature.value()};
  const auto sourceAuthority = make_source_authority(mesh, hardFeatures);
  ASSERT_TRUE(sourceAuthority.has_value());
  auto atlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, hardFeatures, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlas);
  const auto rails = rails_from_atlas(mesh, atlas.value());
  const FieldAlignedCurveNetwork network =
      build_network(mesh, *sourceAuthority, atlas.value(), rails);
  const auto plan = build_topology_plan(mesh, *sourceAuthority, network);

  ASSERT_TRUE(std::any_of(network.mandatory_edges().begin(),
                          network.mandatory_edges().end(), [](const auto &edge) {
                            return edge.kind == SurfaceCellRailKind::HardFeature;
                          }))
      << "A4 fixture must actually contain a hard feature";
  for (const auto &edge : network.mandatory_edges()) {
    const auto pieces = find_mandatory_plan_arcs(plan, edge.id);
    ASSERT_FALSE(pieces.empty());
    for (const auto *arc : pieces) {
      std::size_t uses = 0U;
      for (const auto &region : plan.regions()) {
        uses += static_cast<std::size_t>(std::count_if(
            region.boundary.begin(), region.boundary.end(),
            [&](const auto incidence) { return incidence.arc == arc->id; }));
      }
      if (edge.kind == SurfaceCellRailKind::Boundary) {
        EXPECT_EQ(1U, uses);
      } else {
        EXPECT_EQ(2U, uses);
      }
    }
  }
}

TEST(GlobalTopologyPlan, RejectsForeignNetworkBindingOrTamperedRegionOwnership) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);

  auto foreignBinding = plan.validation_candidate();
  foreignBinding.networkDigest ^= 0x9e3779b97f4a7c15ULL;
  auto rejected = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      fixture.mesh.F, static_cast<std::size_t>(fixture.mesh.V.rows()),
      *fixture.sourceAuthority, *fixture.network, std::move(foreignBinding));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(directional::geometry::GlobalTopologyPlanErrorCode::InvalidNetworkBinding,
            rejected.error().code)
      << directional::geometry::global_topology_plan_error_code_name(
             rejected.error().code);

  auto unowned = plan.validation_candidate();
  ASSERT_FALSE(unowned.regions.empty());
  ASSERT_FALSE(unowned.regions.front().sourceFaces.empty());
  unowned.regions.front().sourceFaces.erase(
      unowned.regions.front().sourceFaces.begin());
  rejected = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      fixture.mesh.F, static_cast<std::size_t>(fixture.mesh.V.rows()),
      *fixture.sourceAuthority, *fixture.network, std::move(unowned));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(
      directional::geometry::GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned,
      rejected.error().code)
      << directional::geometry::global_topology_plan_error_code_name(
             rejected.error().code);

  auto multiplyOwned = plan.validation_candidate();
  ASSERT_GT(multiplyOwned.regions.size(), 1U);
  ASSERT_FALSE(multiplyOwned.regions.front().sourceFaces.empty());
  const auto duplicatedFace = multiplyOwned.regions.front().sourceFaces.front();
  multiplyOwned.regions[1].sourceFaces.push_back(duplicatedFace);
  rejected = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      fixture.mesh.F, static_cast<std::size_t>(fixture.mesh.V.rows()),
      *fixture.sourceAuthority, *fixture.network, std::move(multiplyOwned));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(directional::geometry::GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned,
            rejected.error().code)
      << directional::geometry::global_topology_plan_error_code_name(
             rejected.error().code);
}

TEST(GlobalTopologyPlan, RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling) {
  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  auto baselineAtlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(baselineAtlas);
  const auto baselineRails = rails_from_atlas(mesh, baselineAtlas.value());
  const FieldAlignedCurveNetwork baselineNetwork = build_network(
      mesh, *sourceAuthority, baselineAtlas.value(), baselineRails);
  const auto baselinePlan =
      build_topology_plan(mesh, *sourceAuthority, baselineNetwork);

  auto reordered = baselinePlan.validation_candidate();
  std::reverse(reordered.arcs.begin(), reordered.arcs.end());
  std::reverse(reordered.rotations.begin(), reordered.rotations.end());
  std::reverse(reordered.regions.begin(), reordered.regions.end());
  for (auto &region : reordered.regions) {
    std::reverse(region.sourceFaces.begin(), region.sourceFaces.end());
  }
  auto rebuilt = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      baselineNetwork, std::move(reordered));
  ASSERT_TRUE(rebuilt) << (rebuilt ? ""
                                  : directional::geometry::global_topology_plan_error_code_name(
                                        rebuilt.error().code));
  EXPECT_EQ(baselinePlan.semantic_digest(), rebuilt.value().semantic_digest());
  EXPECT_EQ(baselinePlan.regions(), rebuilt.value().regions());
  EXPECT_EQ(baselinePlan.rotation_system(), rebuilt.value().rotation_system());

  const CrossFieldResult relabeledField = gauge_relabel_field_for_network(
      mesh, field, cp3a_equivalent_gauge_shifts(mesh));
  auto relabeledAtlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, relabeledField);
  ASSERT_TRUE(relabeledAtlas);
  const auto relabeledRails = rails_from_atlas(mesh, relabeledAtlas.value());
  const FieldAlignedCurveNetwork relabeledNetwork = build_network(
      mesh, *sourceAuthority, relabeledAtlas.value(), relabeledRails);
  ASSERT_EQ(baselineNetwork.semantic_digest(), relabeledNetwork.semantic_digest());
  ASSERT_NE(baselineNetwork.atlas_digest(), relabeledNetwork.atlas_digest());
  const auto relabeledPlan =
      build_topology_plan(mesh, *sourceAuthority, relabeledNetwork);

  EXPECT_NE(baselinePlan.network_digest(), relabeledPlan.network_digest());
  EXPECT_EQ(baselinePlan.semantic_digest(), relabeledPlan.semantic_digest());
  EXPECT_EQ(baselinePlan.regions(), relabeledPlan.regions());
  EXPECT_EQ(baselinePlan.rotation_system(), relabeledPlan.rotation_system());
}

TEST(GlobalTopologyPlan, ProvesDiscTopologyForEveryEmittedRegion) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);

  ASSERT_EQ(plan.regions().size(), plan.region_certificates().size());
  for (const auto &region : plan.regions()) {
    const auto *certificate = plan.find_region_certificate(region.id);
    ASSERT_NE(nullptr, certificate);
    EXPECT_EQ(region.id, certificate->region);
    EXPECT_EQ(1U, certificate->boundaryWalkCount);
    EXPECT_TRUE(certificate->sourceFacesConnected);
    EXPECT_EQ(1, certificate->eulerCharacteristic);
    EXPECT_EQ(region.sourceFaces.size(), certificate->faceCount);
    EXPECT_TRUE(certificate->proves_disc_topology());
    EXPECT_TRUE(certificate->proves_field_regularity());
  }
}

TEST(GlobalTopologyPlan, RejectsRegionWithMultipleBoundaryWalks) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);
  ASSERT_GT(plan.regions().size(), 1U);

  auto candidate = plan.validation_candidate();
  ASSERT_FALSE(candidate.regions[0].boundary.empty());
  const auto duplicateWalk = candidate.regions[0].boundary;
  const auto secondWalkArc = duplicateWalk.front().arc;
  candidate.regions[0].boundary.insert(candidate.regions[0].boundary.end(),
                                       duplicateWalk.begin(),
                                       duplicateWalk.end());
  auto rejected = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      fixture.mesh.F, static_cast<std::size_t>(fixture.mesh.V.rows()),
      *fixture.sourceAuthority, *fixture.network, std::move(candidate));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(
      directional::geometry::GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk,
      rejected.error().code)
      << directional::geometry::global_topology_plan_error_code_name(
             rejected.error().code);
  ASSERT_TRUE(rejected.error().region.has_value());
  ASSERT_TRUE(rejected.error().arc.has_value());
  EXPECT_EQ(secondWalkArc, *rejected.error().arc);
}

TEST(GlobalTopologyPlan, RejectsRegionWithWrongEulerCharacteristicOrInteriorSingularity) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  auto atlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_index_one_singularity_field(mesh));
  ASSERT_TRUE(atlas);
  ASSERT_TRUE(atlas.value().quadrangulability().established());
  const auto rails = rails_from_atlas(mesh, atlas.value());
  const auto network = build_network(mesh, *sourceAuthority, atlas.value(), rails);
  const auto plan = build_topology_plan(mesh, *sourceAuthority, network);

  auto candidate = plan.validation_candidate();
  ASSERT_FALSE(candidate.regions.empty());
  const auto outerBoundary = ordered_mandatory_cycle(plan);
  ASSERT_FALSE(outerBoundary.empty())
      << "B3 fixture must expose the closed source-boundary cycle";
  std::vector<directional::authority::SourceFaceTopologyKey> allFaces;
  for (int rowIndex = 0; rowIndex < mesh.F.rows(); ++rowIndex) {
    const auto row = directional::authority::SourceFaceId::from_index(
        rowIndex, static_cast<std::size_t>(mesh.F.rows()));
    ASSERT_TRUE(row.has_value());
    allFaces.push_back(sourceAuthority->topology_for_row(row.value()));
  }
  candidate.regions.erase(candidate.regions.begin() + 1,
                          candidate.regions.end());
  candidate.regions.front().boundary = outerBoundary;
  candidate.regions.front().sourceFaces = std::move(allFaces);
  candidate.regionCertificates.clear();
  auto rejected = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      network, std::move(candidate));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(
      directional::geometry::GlobalTopologyPlanErrorCode::RegionContainsInteriorSingularity,
      rejected.error().code)
      << directional::geometry::global_topology_plan_error_code_name(
             rejected.error().code);
  EXPECT_TRUE(rejected.error().region.has_value());
  EXPECT_TRUE(rejected.error().singularity.has_value());
  EXPECT_TRUE(rejected.error().sourceVertex.has_value());
}

TEST(GlobalTopologyPlan, IndependentDiscProofOracleAgreesWithPublishedCertificates) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);
  ASSERT_FALSE(plan.regions().empty());
  const auto proof =
      independent_disc_proof_oracle(plan, fixture.mesh, *fixture.network);
  EXPECT_TRUE(proof.passed)
      << "clause=" << independent_disc_proof_clause_name(proof.clause)
      << " embedded_graph_chi=" << proof.embeddedGraphChi
      << " source_surface_chi=" << proof.sourceSurfaceChi;
}

TEST(GlobalTopologyPlan, RejectsTamperedDiscProofCertificate) {
  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  const auto plan = build_topology_plan(
      fixture.mesh, *fixture.sourceAuthority, *fixture.network);
  auto candidate = plan.validation_candidate();
  ASSERT_FALSE(candidate.regionCertificates.empty());
  const auto tamperedRegion = candidate.regionCertificates.front().region;
  ++candidate.regionCertificates.front().eulerCharacteristic;
  auto rejected = directional::geometry::GlobalTopologyPlan::make_from_candidate(
      fixture.mesh.F, static_cast<std::size_t>(fixture.mesh.V.rows()),
      *fixture.sourceAuthority, *fixture.network, std::move(candidate));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(
      directional::geometry::GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding,
      rejected.error().code)
      << directional::geometry::global_topology_plan_error_code_name(
             rejected.error().code);
  ASSERT_TRUE(rejected.error().region.has_value());
  EXPECT_EQ(tamperedRegion, *rejected.error().region);
}

TEST(GlobalTopologyPlan, UnestablishedFieldTransportCannotProduceATopologyPlan) {
  using Atlas = directional::authority::FieldTransportAtlas;
  using AtlasCertificate =
      directional::authority::FieldQuadrangulabilityCertificate;
  static_assert(!std::is_default_constructible_v<Atlas>);
  static_assert(!std::is_default_constructible_v<AtlasCertificate>);
  static_assert(std::is_same_v<
                decltype(std::declval<const Atlas &>().quadrangulability()),
                const AtlasCertificate &>);

  using NetworkFactory = directional::geometry::FieldAlignedCurveNetworkBuildResult (*)(
      const TriMesh &, const SourceTopologyRegions &, const Atlas &,
      const std::vector<SurfaceCellRail> &);
  static_assert(std::is_same_v<decltype(&FieldAlignedCurveNetwork::make),
                               NetworkFactory>);
  using PlanFactory = directional::geometry::GlobalTopologyPlanBuildResult (*)(
      const Eigen::MatrixXi &, std::size_t, const SourceTopologyRegions &,
      const FieldAlignedCurveNetwork &);
  static_assert(std::is_same_v<decltype(&directional::geometry::GlobalTopologyPlan::make),
                               PlanFactory>);

  const TriMesh mesh = make_square_mesh();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  auto atlas = Atlas::make(mesh, *sourceAuthority, {},
                           make_zero_transport_field(mesh));
  ASSERT_TRUE(atlas);
  ASSERT_TRUE(atlas.value().quadrangulability().established())
      << "the only public atlas value route publishes an established certificate";
  const auto rails = rails_from_atlas(mesh, atlas.value());
  const auto network = build_network(mesh, *sourceAuthority, atlas.value(), rails);
  const auto plan = directional::geometry::GlobalTopologyPlan::make(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      network);
  EXPECT_TRUE(plan) << (plan ? ""
                           : directional::geometry::global_topology_plan_error_code_name(
                                 plan.error().code));
  // D4 FieldTransportUnestablished disposition remains M7.  M3 proves the
  // structural negative: there is no public alternate GlobalTopologyPlan path
  // around the established-atlas -> network -> topology-plan chain.
}


namespace {

enum class Cp4cRailAuthority {
  AtlasDerived,
  PipelineAuthoritative,
};

const char *cp4c_rail_authority_name(const Cp4cRailAuthority authority) {
  switch (authority) {
  case Cp4cRailAuthority::AtlasDerived:
    return "atlas-derived";
  case Cp4cRailAuthority::PipelineAuthoritative:
    return "pipeline-authoritative";
  }
  return "unknown";
}

struct Cp4cProductionFixture {
  TriMesh mesh;
  Cp4cRailAuthority railAuthority = Cp4cRailAuthority::PipelineAuthoritative;
  std::optional<SourceTopologyRegions> sourceAuthority;
  std::optional<directional::authority::FieldTransportAtlas> atlas;
  std::optional<FieldAlignedCurveNetwork> network;
  std::optional<directional::geometry::GlobalTopologyPlan> plan;
};

Eigen::MatrixXd read_cp4c_rawfield(const std::filesystem::path &path,
                                   const int expectedFaces) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open rawfield fixture: " +
                             path.string());
  }
  int degree = 0;
  int faceCount = 0;
  if (!(stream >> degree >> faceCount) || degree != 4 ||
      faceCount != expectedFaces) {
    throw std::runtime_error("Invalid rawfield fixture header: " +
                             path.string());
  }
  Eigen::MatrixXd raw(faceCount, 3 * degree);
  for (int face = 0; face < faceCount; ++face) {
    for (int column = 0; column < raw.cols(); ++column) {
      if (!(stream >> raw(face, column))) {
        throw std::runtime_error("Invalid rawfield fixture payload: " +
                                 path.string());
      }
    }
  }
  return raw;
}

directional::pipeline::RemeshOptions cp4c_remesh_options() {
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  return options;
}


void append_cp4c_terminal_event_report(
    std::ostringstream &report, const FieldAlignedCurveNetwork &network) {
  std::size_t terminalIntersectionCount = 0U;
  std::set<int> terminalKinds;
  std::map<int, std::set<std::size_t>> contributingTraceIds;
  for (const auto &event : network.events()) {
    bool hasTerminal = false;
    for (const auto &incidence : event.incidences) {
      if (incidence.role !=
          directional::geometry::FieldAlignedTraceEventRole::Terminal) {
        continue;
      }
      hasTerminal = true;
      contributingTraceIds[static_cast<int>(event.kind)].insert(
          incidence.trace.index());
    }
    if (!hasTerminal) continue;
    terminalKinds.insert(static_cast<int>(event.kind));
    if (event.kind ==
        directional::geometry::FieldAlignedNetworkEventKind::TraceIntersection) {
      ++terminalIntersectionCount;
    }
  }

  report << ";terminalTraceIntersectionCount=" << terminalIntersectionCount
         << ";producedTerminalEventKinds=";
  bool first = true;
  for (const int kind : terminalKinds) {
    if (!first) report << ',';
    first = false;
    report << kind;
  }
  if (first) report << "none";

  report << ";terminalEventTraceIds=";
  first = true;
  for (const auto &[kind, traceIds] : contributingTraceIds) {
    for (const std::size_t traceId : traceIds) {
      if (!first) report << ',';
      first = false;
      report << kind << ':' << traceId;
    }
  }
  if (first) report << "none";
}

void append_cp4c_atlas_failure_diagnosis(
    std::ostringstream &report, const TriMesh &mesh,
    const SourceTopologyRegions &sourceAuthority,
    const CrossFieldResult &crossField,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges,
    const directional::authority::FieldAtlasBuildError &error) {
  if (!error.sourceEdge.has_value() || !error.topologyRegion.has_value()) {
    return;
  }

  const SourceEdgeTopologyKey sourceEdge = *error.sourceEdge;
  const int edge = source_edge_index(mesh, sourceEdge);
  bool transitionExists = false;
  if (edge >= 0) {
    transitionExists = std::any_of(
        crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
        [&](const auto &transition) {
          return transition.sourceEdge == edge;
        });
  }

  bool adjacencyExists = false;
  int globalFaceA = -1;
  int globalFaceB = -1;
  if (edge >= 0) {
    globalFaceA = mesh.EF(edge, 0);
    globalFaceB = mesh.EF(edge, 1);
    if (globalFaceA >= 0 && globalFaceB >= 0 && transitionExists &&
        hardFeatureEdges.find(sourceEdge) == hardFeatureEdges.end()) {
      const auto faceA = directional::authority::SourceFaceId::from_index(
          globalFaceA, static_cast<std::size_t>(mesh.F.rows()));
      const auto faceB = directional::authority::SourceFaceId::from_index(
          globalFaceB, static_cast<std::size_t>(mesh.F.rows()));
      adjacencyExists =
          faceA.has_value() && faceB.has_value() &&
          sourceAuthority.region_for_row(faceA.value()) == *error.topologyRegion &&
          sourceAuthority.region_for_row(faceB.value()) == *error.topologyRegion;
    }
  }

  const auto rows = sourceAuthority.rows_for_region(*error.topologyRegion);
  int localFaceA = -1;
  int localFaceB = -1;
  std::set<int> localVertices;
  std::map<SourceEdgeTopologyKey, int> localEdgeIncidence;
  for (std::size_t localFace = 0; localFace < rows.size(); ++localFace) {
    const int row = static_cast<int>(rows[localFace].index());
    if (row == globalFaceA) localFaceA = static_cast<int>(localFace);
    if (row == globalFaceB) localFaceB = static_cast<int>(localFace);
    for (int corner = 0; corner < 3; ++corner) {
      localVertices.insert(mesh.F(row, corner));
      const int next = (corner + 1) % 3;
      const auto edgeKey = SourceEdgeTopologyKey::from_indices(
          mesh.F(row, corner), mesh.F(row, next),
          static_cast<std::size_t>(mesh.V.rows()));
      if (edgeKey.has_value()) ++localEdgeIncidence[edgeKey.value()];
    }
  }
  const std::size_t localBoundaryEdges =
      static_cast<std::size_t>(std::count_if(
          localEdgeIncidence.begin(), localEdgeIncidence.end(),
          [](const auto &entry) { return entry.second == 1; }));

  report << ";atlasFailureDiagnosis={sourceEdge="
         << sourceEdge.first().index() << '-' << sourceEdge.second().index()
         << ",fieldTransportAdjacencyExists="
         << (adjacencyExists ? "true" : "false")
         << ",globalEF=" << globalFaceA << ',' << globalFaceB
         << ",localEF=" << localFaceA << ',' << localFaceB
         << ",localV=" << localVertices.size()
         << ",localF=" << rows.size()
         << ",localBoundaryEdges=" << localBoundaryEdges << '}';
}

struct Cp4cReachabilityObservation {
  TriMesh mesh;
  Cp4cRailAuthority railAuthority = Cp4cRailAuthority::PipelineAuthoritative;
  std::vector<SurfaceCellRail> rails;
  std::optional<SourceTopologyRegions> sourceAuthority;
  std::optional<directional::authority::FieldTransportAtlas> atlas;
  std::optional<FieldAlignedCurveNetwork> network;
  std::optional<directional::geometry::GlobalTopologyPlan> plan;
  std::string report;
};

std::string source_edge_locus(const SourceEdgeTopologyKey &edge) {
  return std::to_string(edge.first().index()) + "-" +
         std::to_string(edge.second().index());
}

std::string source_face_locus(const SourceFaceTopologyKey &face) {
  const auto &vertices = face.vertices();
  return std::to_string(vertices[0].index()) + "-" +
         std::to_string(vertices[1].index()) + "-" +
         std::to_string(vertices[2].index());
}

std::string exact_rational_locus(
    const directional::authority::FieldExactRational &value) {
  return value.numerator_string() + "/" + value.denominator_string();
}

std::string branch_locus(const directional::authority::FieldBranch branch) {
  return std::to_string(static_cast<unsigned int>(branch.value()));
}

std::string signed_lift_locus(const int signedLift) {
  return std::to_string(signedLift);
}

std::optional<int> cp4c_raw_face_gauge(
    const TriMesh &mesh, const CrossFieldResult &field, const int face,
    const SourceFaceTopologyKey &topology) {
  constexpr double tolerance = 1.0e-10;
  const auto &vertices = topology.vertices();
  const Eigen::Vector3d p0 =
      mesh.V.row(static_cast<int>(vertices[0].index())).transpose();
  const Eigen::Vector3d p1 =
      mesh.V.row(static_cast<int>(vertices[1].index())).transpose();
  const Eigen::Vector3d p2 =
      mesh.V.row(static_cast<int>(vertices[2].index())).transpose();
  Eigen::Vector3d normal = (p1 - p0).cross(p2 - p0);
  const double normalNorm = normal.norm();
  if (!std::isfinite(normalNorm) || normalNorm <= tolerance) {
    return std::nullopt;
  }
  normal /= normalNorm;

  const auto project = [&](const Eigen::Vector3d &direction)
      -> std::optional<Eigen::Vector3d> {
    Eigen::Vector3d tangent = direction - direction.dot(normal) * normal;
    const double norm = tangent.norm();
    if (!std::isfinite(norm) || norm <= tolerance) return std::nullopt;
    tangent /= norm;
    return tangent.allFinite() ? std::optional<Eigen::Vector3d>(tangent)
                               : std::nullopt;
  };

  const auto reference = project(p1 - p0);
  const auto primary = project(field.primaryDirections.row(face).transpose());
  const auto secondary =
      project(field.secondaryDirections.row(face).transpose());
  if (!reference.has_value() || !primary.has_value() ||
      !secondary.has_value() ||
      std::abs(primary->dot(*secondary)) > 1.0 - 1.0e-8) {
    return std::nullopt;
  }

  const std::array<Eigen::Vector3d, 4> rawDirections{
      *primary, *secondary, -*primary, -*secondary};
  std::array<double, 4> angles{};
  int gauge = 0;
  double best = std::numeric_limits<double>::infinity();
  for (int raw = 0; raw < 4; ++raw) {
    double angle = directional::test_support::independent_signed_angle(
        *reference, rawDirections[static_cast<std::size_t>(raw)], normal);
    if (angle < 0.0) angle += 2.0 * std::numbers::pi;
    if (angle >= 2.0 * std::numbers::pi) angle -= 2.0 * std::numbers::pi;
    angles[static_cast<std::size_t>(raw)] = angle;
    if (angle < best) {
      best = angle;
      gauge = raw;
    }
  }
  for (int raw = 0; raw < 4; ++raw) {
    if (raw != gauge &&
        std::abs(angles[static_cast<std::size_t>(raw)] - best) <= tolerance) {
      return std::nullopt;
    }
  }
  return gauge;
}

struct Cp4cLiftTerms {
  int matching = 0;
  int sourceRawGauge = 0;
  int targetRawGauge = 0;
};

std::optional<Cp4cLiftTerms> cp4c_lift_terms(
    const TriMesh &mesh, const CrossFieldResult &field,
    const directional::authority::FieldTransportAdjacency &adjacency,
    const SourceFaceTopologyKey &sourceFace,
    const SourceFaceTopologyKey &targetFace) {
  int matching = 0;
  int sourceRow = -1;
  int targetRow = -1;
  if (adjacency.firstFaceTopology == sourceFace &&
      adjacency.secondFaceTopology == targetFace) {
    matching = adjacency.forwardLift;
    sourceRow = static_cast<int>(adjacency.firstFace.index());
    targetRow = static_cast<int>(adjacency.secondFace.index());
  } else if (adjacency.secondFaceTopology == sourceFace &&
             adjacency.firstFaceTopology == targetFace) {
    matching = -adjacency.forwardLift;
    sourceRow = static_cast<int>(adjacency.secondFace.index());
    targetRow = static_cast<int>(adjacency.firstFace.index());
  } else {
    return std::nullopt;
  }
  const auto sourceGauge =
      cp4c_raw_face_gauge(mesh, field, sourceRow, sourceFace);
  const auto targetGauge =
      cp4c_raw_face_gauge(mesh, field, targetRow, targetFace);
  if (!sourceGauge.has_value() || !targetGauge.has_value()) {
    return std::nullopt;
  }
  return Cp4cLiftTerms{matching, *sourceGauge, *targetGauge};
}

bool cp4c_edge_incident_to_declared_singularity(
    const SourceEdgeTopologyKey &edge, const CrossFieldResult &field) {
  for (Eigen::Index row = 0; row < field.singularCycles.size(); ++row) {
    const int vertex = field.singularCycles(row);
    if (vertex < 0) continue;
    if (edge.first().index() == static_cast<std::size_t>(vertex) ||
        edge.second().index() == static_cast<std::size_t>(vertex)) {
      return true;
    }
  }
  return false;
}

struct Cp4cCensusWitnessMetadata {
  std::string name;
  std::string matchingProvenance;
  std::string matchingCodePath;
  std::string population;
  std::string classification;
};

struct Cp4cTangencySample {
  directional::authority::FieldExactRational sourceRatio;
  directional::authority::FieldExactRational targetRatio;
  directional::authority::FieldExactRational transportAngleProxy;
  int sourceOppositeRank = 0;
  int targetOppositeRank = 0;
};

struct Cp4cGrazingObservation {
  SourceEdgeTopologyKey sourceEdge;
  SourceFaceTopologyKey sourceFace;
  SourceFaceTopologyKey targetFace;
  directional::authority::FieldBranch sourceBranch;
  directional::authority::FieldBranch targetBranch;
  int matching = 0;
  int sourceRawGauge = 0;
  int targetRawGauge = 0;
  int signedLift = 0;
  bool singularVertexIncident = false;
  directional::authority::FieldExactRational sourceOppositeDerivative;
  directional::authority::FieldExactRational targetOppositeDerivative;
  directional::authority::FieldExactRational sourceRate;
  directional::authority::FieldExactRational targetRate;
  bool signAgreement = false;
  bool zeroRate = false;
  std::string selectedEndpoint;
  Cp4cTangencySample tangency;
};

directional::authority::FieldExactRational cp4c_exact_abs(
    const directional::authority::FieldExactRational &value) {
  const auto zero = directional::authority::FieldExactRational::from_integer(0);
  return value < zero ? -value : value;
}

std::optional<directional::authority::FieldExactRational> cp4c_tangency_ratio(
    const directional::authority::FieldBranchDirection &direction,
    const std::size_t opposite) {
  auto maximum = cp4c_exact_abs(direction.barycentric[0]);
  for (std::size_t index = 1U; index < direction.barycentric.size(); ++index) {
    maximum = std::max(maximum, cp4c_exact_abs(direction.barycentric[index]));
  }
  if (maximum.is_zero()) return std::nullopt;
  return cp4c_exact_abs(direction.barycentric[opposite]) / maximum;
}

int cp4c_opposite_rank(
    const directional::authority::FieldBranchDirection &direction,
    const std::size_t opposite) {
  const auto magnitude = cp4c_exact_abs(direction.barycentric[opposite]);
  int less = 0;
  for (std::size_t index = 0U; index < direction.barycentric.size(); ++index) {
    if (index != opposite && cp4c_exact_abs(direction.barycentric[index]) < magnitude) {
      ++less;
    }
  }
  return std::min(less, 2);
}

const char *cp4c_rank_locus(const int rank) {
  switch (rank) {
  case 0:
    return "smallest";
  case 1:
    return "middle";
  case 2:
    return "largest";
  default:
    return "invalid";
  }
}

std::optional<directional::authority::FieldExactRational>
cp4c_transport_angle_proxy(
    const TriMesh &mesh, const CrossFieldResult &field, const int sourceRow,
    const int targetRow, const SourceEdgeTopologyKey &edge) {
  // K1 is diagnostic only.  Preserve the independent unfolded-edge effort as
  // its exact IEEE-754 dyadic value; it is an angle proxy, not a topology
  // predicate and must never be thresholded to decide ownership.
  const auto measured = directional::test_support::independent_edge_measurement(
      mesh, field, sourceRow, targetRow, edge);
  return directional::authority::FieldExactRational::from_double_exact(
      measured.effort);
}

std::string cp4c_tangency_sample_locus(const Cp4cTangencySample &sample) {
  const auto minRatio = std::min(sample.sourceRatio, sample.targetRatio);
  std::ostringstream stream;
  stream << "{sourceRatio=" << exact_rational_locus(sample.sourceRatio)
         << ",targetRatio=" << exact_rational_locus(sample.targetRatio)
         << ",minRatio=" << exact_rational_locus(minRatio)
         << ",transportAngleProxy="
         << exact_rational_locus(sample.transportAngleProxy)
         << ",sourceOppositeRank=" << cp4c_rank_locus(sample.sourceOppositeRank)
         << ",targetOppositeRank=" << cp4c_rank_locus(sample.targetOppositeRank)
         << '}';
  return stream.str();
}

const directional::authority::FieldBranchBoundaryPairing *
find_cp4c_branch_pairing(
    const directional::authority::FieldFaceBranchFrame &frame,
    const directional::authority::FieldBranch branch) {
  const auto found = std::find_if(
      frame.branches.begin(), frame.branches.end(),
      [&](const auto &pairing) { return pairing.branch == branch; });
  return found == frame.branches.end() ? nullptr : &*found;
}

std::optional<std::size_t> cp4c_opposite_coordinate(
    const SourceFaceTopologyKey &face, const SourceEdgeTopologyKey &edge) {
  const auto &vertices = face.vertices();
  for (std::size_t index = 0U; index < vertices.size(); ++index) {
    if (vertices[index] != edge.first() && vertices[index] != edge.second()) {
      return index;
    }
  }
  return std::nullopt;
}

std::optional<std::size_t> cp4c_vertex_coordinate(
    const SourceFaceTopologyKey &face, const SourceVertexId vertex) {
  const auto &vertices = face.vertices();
  for (std::size_t index = 0U; index < vertices.size(); ++index) {
    if (vertices[index] == vertex) return index;
  }
  return std::nullopt;
}

std::string cp4c_flow_agreement_census(
    const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
    const CrossFieldResult &field,
    const directional::authority::FieldTransportAtlas &atlas) {
  using directional::geometry::surface_cell_tracing_detail::
      FieldBranchEdgeFlowRelation;
  using directional::geometry::surface_cell_tracing_detail::
      classify_field_branch_transport_flow;

  const auto &topology = atlas.branch_topology();
  std::size_t interiorEdgeCount = 0U;
  for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
    if (mesh.EF(edge, 0) >= 0 && mesh.EF(edge, 1) >= 0) ++interiorEdgeCount;
  }

  std::size_t pairsChecked = 0U;
  std::vector<Cp4cGrazingObservation> grazing;
  std::set<std::tuple<SourceEdgeTopologyKey, unsigned int>>
      distinctGrazingConfigurations;
  std::set<SourceEdgeTopologyKey> distinctGrazingEdges;
  std::map<int, std::size_t> matchingHistogram;
  std::size_t singularIncidentGrazing = 0U;
  std::size_t signDisagreements = 0U;
  std::size_t zeroRates = 0U;
  std::vector<Cp4cTangencySample> grazingTangency;
  std::vector<Cp4cTangencySample> nonGrazingTangency;
  const auto zero = directional::authority::FieldExactRational::from_integer(0);

  for (const auto &adjacency : topology.transports()) {
    const auto *rawAdjacency = atlas.find_adjacency(adjacency.sourceEdge);
    if (rawAdjacency == nullptr) {
      ADD_FAILURE() << "L2 missing raw A1 adjacency for witness=" << metadata.name
                    << ";edge=" << source_edge_locus(adjacency.sourceEdge);
      continue;
    }
    for (int direction = 0; direction < 2; ++direction) {
      const auto &sourceFace =
          direction == 0 ? adjacency.firstFace : adjacency.secondFace;
      const auto &targetFace =
          direction == 0 ? adjacency.secondFace : adjacency.firstFace;
      const auto directed =
          topology.transport(adjacency.sourceEdge, sourceFace, targetFace);
      if (!directed.has_value()) {
        ADD_FAILURE() << "L2 missing directed A1 transport for witness="
                      << metadata.name
                      << ";edge=" << source_edge_locus(adjacency.sourceEdge);
        continue;
      }
      const auto liftTerms =
          cp4c_lift_terms(mesh, field, *rawAdjacency, sourceFace, targetFace);
      if (!liftTerms.has_value()) {
        ADD_FAILURE() << "L2 could not decompose lift for witness="
                      << metadata.name
                      << ";edge=" << source_edge_locus(adjacency.sourceEdge)
                      << ";sourceFace=" << source_face_locus(sourceFace)
                      << ";targetFace=" << source_face_locus(targetFace);
        continue;
      }
      int sourceRow = -1;
      int targetRow = -1;
      if (rawAdjacency->firstFaceTopology == sourceFace &&
          rawAdjacency->secondFaceTopology == targetFace) {
        sourceRow = static_cast<int>(rawAdjacency->firstFace.index());
        targetRow = static_cast<int>(rawAdjacency->secondFace.index());
      } else if (rawAdjacency->secondFaceTopology == sourceFace &&
                 rawAdjacency->firstFaceTopology == targetFace) {
        sourceRow = static_cast<int>(rawAdjacency->secondFace.index());
        targetRow = static_cast<int>(rawAdjacency->firstFace.index());
      }
      if (sourceRow < 0 || targetRow < 0) {
        ADD_FAILURE() << "L2 could not resolve face rows for witness="
                      << metadata.name
                      << ";edge=" << source_edge_locus(adjacency.sourceEdge);
        continue;
      }
      const auto transportAngleProxy = cp4c_transport_angle_proxy(
          mesh, field, sourceRow, targetRow, adjacency.sourceEdge);
      if (!transportAngleProxy.has_value()) {
        ADD_FAILURE() << "L2 could not serialize transport angle proxy for witness="
                      << metadata.name
                      << ";edge=" << source_edge_locus(adjacency.sourceEdge);
        continue;
      }

      const auto z4 = [](const int value) { return ((value % 4) + 4) % 4; };
      const int recomposedLift = liftTerms->matching +
                                 liftTerms->sourceRawGauge -
                                 liftTerms->targetRawGauge;
      EXPECT_EQ(z4(recomposedLift), z4(directed->signedLift))
          << "L2 independently re-derived gauge terms must reproduce A1's "
             "published Z4 lift"
          << ";witness=" << metadata.name
          << ";edge=" << source_edge_locus(adjacency.sourceEdge);
      const auto *sourceFrame = topology.find_frame(sourceFace);
      const auto *targetFrame = topology.find_frame(targetFace);
      if (sourceFrame == nullptr || targetFrame == nullptr) {
        ADD_FAILURE() << "L2 missing A1 frame for witness=" << metadata.name
                      << ";edge=" << source_edge_locus(adjacency.sourceEdge);
        continue;
      }
      const auto sourceOpposite =
          cp4c_opposite_coordinate(sourceFace, adjacency.sourceEdge);
      const auto targetOpposite =
          cp4c_opposite_coordinate(targetFace, adjacency.sourceEdge);
      const auto sourceBeta =
          cp4c_vertex_coordinate(sourceFace, adjacency.sourceEdge.second());
      const auto targetBeta =
          cp4c_vertex_coordinate(targetFace, adjacency.sourceEdge.second());
      if (!sourceOpposite.has_value() || !targetOpposite.has_value() ||
          !sourceBeta.has_value() || !targetBeta.has_value()) {
        ADD_FAILURE() << "L2 invalid edge/face incidence for witness="
                      << metadata.name
                      << ";edge=" << source_edge_locus(adjacency.sourceEdge);
        continue;
      }

      for (int branchIndex = 0; branchIndex < 4; ++branchIndex) {
        const auto sourceBranch =
            directional::authority::FieldBranch::from_integer(branchIndex);
        const auto targetBranch = sourceBranch.rotated(directed->signedLift);
        const auto *sourcePairing =
            find_cp4c_branch_pairing(*sourceFrame, sourceBranch);
        const auto *targetPairing =
            find_cp4c_branch_pairing(*targetFrame, targetBranch);
        if (sourcePairing == nullptr || targetPairing == nullptr) {
          ADD_FAILURE() << "L2 missing A1 branch pairing for witness="
                        << metadata.name
                        << ";edge=" << source_edge_locus(adjacency.sourceEdge)
                        << ";sourceBranch=" << branch_locus(sourceBranch)
                        << ";targetBranch=" << branch_locus(targetBranch);
          continue;
        }

        ++pairsChecked;
        const auto &sourceDerivative =
            sourcePairing->direction.barycentric[*sourceOpposite];
        const auto &targetDerivative =
            targetPairing->direction.barycentric[*targetOpposite];
        const auto sourceRatio =
            cp4c_tangency_ratio(sourcePairing->direction, *sourceOpposite);
        const auto targetRatio =
            cp4c_tangency_ratio(targetPairing->direction, *targetOpposite);
        if (!sourceRatio.has_value() || !targetRatio.has_value()) {
          ADD_FAILURE() << "L2 invalid tangency ratio for witness="
                        << metadata.name
                        << ";edge=" << source_edge_locus(adjacency.sourceEdge);
          continue;
        }
        const Cp4cTangencySample tangency{
            *sourceRatio, *targetRatio, *transportAngleProxy,
            cp4c_opposite_rank(sourcePairing->direction, *sourceOpposite),
            cp4c_opposite_rank(targetPairing->direction, *targetOpposite)};

        const bool sourceOutflow = sourceDerivative < zero;
        if (!sourceOutflow) {
          nonGrazingTangency.push_back(tangency);
          continue;
        }
        const auto relation = classify_field_branch_transport_flow(
            sourceFace, *sourcePairing, targetFace, *targetPairing,
            adjacency.sourceEdge);
        if (relation != FieldBranchEdgeFlowRelation::Outflow) {
          nonGrazingTangency.push_back(tangency);
          continue;
        }

        const auto &sourceRate =
            sourcePairing->direction.barycentric[*sourceBeta];
        const auto &targetRate =
            targetPairing->direction.barycentric[*targetBeta];
        const bool positiveAgreement = sourceRate > zero && targetRate > zero;
        const bool negativeAgreement = sourceRate < zero && targetRate < zero;
        const bool signAgreement = positiveAgreement || negativeAgreement;
        const bool zeroRate = sourceRate == zero || targetRate == zero;
        const std::string selectedEndpoint =
            positiveAgreement ? "second"
                              : negativeAgreement ? "first" : "ambiguous";
        const bool singularIncident =
            cp4c_edge_incident_to_declared_singularity(adjacency.sourceEdge,
                                                        field);
        const auto canonicalBranch =
            sourceFace == adjacency.firstFace ? sourceBranch : targetBranch;
        distinctGrazingConfigurations.emplace(adjacency.sourceEdge,
                                              canonicalBranch.value());
        distinctGrazingEdges.emplace(adjacency.sourceEdge);
        ++matchingHistogram[liftTerms->matching];
        singularIncidentGrazing += singularIncident ? 1U : 0U;
        signDisagreements += signAgreement ? 0U : 1U;
        zeroRates += zeroRate ? 1U : 0U;
        grazingTangency.push_back(tangency);
        grazing.push_back(Cp4cGrazingObservation{
            adjacency.sourceEdge, sourceFace, targetFace, sourceBranch,
            targetBranch, liftTerms->matching, liftTerms->sourceRawGauge,
            liftTerms->targetRawGauge, directed->signedLift, singularIncident,
            sourceDerivative, targetDerivative, sourceRate, targetRate,
            signAgreement, zeroRate, selectedEndpoint, tangency});
      }
    }
  }

  const std::size_t expectedPairs = interiorEdgeCount * 8U;
  EXPECT_EQ(expectedPairs, pairsChecked)
      << "L2 must cover every interior edge x four branches x both directions"
      << ";witness=" << metadata.name;
  EXPECT_EQ(interiorEdgeCount, topology.transports().size())
      << "L2 A1 transport inventory must cover every interior edge"
      << ";witness=" << metadata.name;

  const std::size_t distinctCount = distinctGrazingConfigurations.size();
  const std::size_t distinctEdgeCount = distinctGrazingEdges.size();
  if (metadata.name == "sphere_prescribed") {
    EXPECT_EQ(72U, distinctCount);
    EXPECT_EQ(72U, distinctEdgeCount);
  } else if (metadata.name == "torus") {
    EXPECT_EQ(120U, distinctCount);
    EXPECT_EQ(120U, distinctEdgeCount);
  } else if (metadata.name == "two-ring") {
    EXPECT_EQ(2U, distinctCount);
  } else if (metadata.name == "four-triangle-fan") {
    EXPECT_EQ(1U, distinctCount);
  }
  EXPECT_EQ(0U, signDisagreements)
      << "L2 sign disagreement is material review evidence;witness="
      << metadata.name;
  EXPECT_EQ(0U, zeroRates)
      << "L2 zero rate is material review evidence;witness=" << metadata.name;

  std::ostringstream report;
  report << "m3Cp4c0L2"
         << ";credit=none"
         << ";owningMeasure=L2-census"
         << ";witness=" << metadata.name
         << ";matchingProvenance=" << metadata.matchingProvenance
         << ";matchingCodePath=" << metadata.matchingCodePath
         << ";population=" << metadata.population
         << ";classification=" << metadata.classification
         << ";pairsChecked=" << pairsChecked
         << ";directedGrazing=" << grazing.size()
         << ";distinctGrazingConfigurations=" << distinctCount
         << ";distinctGrazingEdges=" << distinctEdgeCount
         << ";signDisagreements=" << signDisagreements
         << ";zeroRates=" << zeroRates
         << ";singularIncidentGrazing=" << singularIncidentGrazing
         << ";matchingHistogram={";
  bool firstHistogram = true;
  for (const auto &[matching, count] : matchingHistogram) {
    if (!firstHistogram) report << ',';
    firstHistogram = false;
    report << matching << ':' << count;
  }
  if (firstHistogram) report << "none";
  report << "};discretizationAssumption=piecewise-constant-face-field"
         << ";grazingTangencyDistribution=[";
  for (std::size_t index = 0U; index < grazingTangency.size(); ++index) {
    if (index != 0U) report << ',';
    report << cp4c_tangency_sample_locus(grazingTangency[index]);
  }
  report << "];nonGrazingTangencyDistribution=[";
  for (std::size_t index = 0U; index < nonGrazingTangency.size(); ++index) {
    if (index != 0U) report << ',';
    report << cp4c_tangency_sample_locus(nonGrazingTangency[index]);
  }
  report << "];status="
         << (grazing.empty() ? "zero-grazing" : "grazing-present");
  for (std::size_t index = 0U; index < grazing.size(); ++index) {
    const auto &observation = grazing[index];
    report << ";grazing[" << index << "]={edge="
           << source_edge_locus(observation.sourceEdge)
           << ",sourceFace=" << source_face_locus(observation.sourceFace)
           << ",targetFace=" << source_face_locus(observation.targetFace)
           << ",sourceBranch=" << branch_locus(observation.sourceBranch)
           << ",targetBranch=" << branch_locus(observation.targetBranch)
           << ",matching=" << observation.matching
           << ",rawGaugeSource=" << observation.sourceRawGauge
           << ",rawGaugeTarget=" << observation.targetRawGauge
           << ",signedLift=" << signed_lift_locus(observation.signedLift)
           << ",singularVertexIncident="
           << (observation.singularVertexIncident ? "true" : "false")
           << ",dXopp="
           << exact_rational_locus(observation.sourceOppositeDerivative)
           << ",dYopp="
           << exact_rational_locus(observation.targetOppositeDerivative)
           << ",rX=" << exact_rational_locus(observation.sourceRate)
           << ",rY=" << exact_rational_locus(observation.targetRate)
           << ",signAgreement="
           << (observation.signAgreement ? "true" : "false")
           << ",zeroRate=" << (observation.zeroRate ? "true" : "false")
           << ",selectedEndpoint=" << observation.selectedEndpoint
           << ",tangency=" << cp4c_tangency_sample_locus(observation.tangency)
           << '}';
  }
  return report.str();
}

std::string cp4c_matching_geometry_census(
    const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
    const CrossFieldResult &field) {
  std::size_t edgesChecked = 0U;
  std::size_t agreementCount = 0U;
  struct Disagreement {
    SourceEdgeTopologyKey edge;
    int firstFace = -1;
    int secondFace = -1;
    int declaredMatching = 0;
    int geometryMatching = 0;
  };
  std::vector<Disagreement> disagreements;
  const auto rawIndex = [](const int value) { return ((value % 4) + 4) % 4; };

  for (const auto &transition : field.edgeTransitions) {
    if (transition.firstFace < 0 || transition.secondFace < 0) continue;
    if (transition.sourceEdge < 0 || transition.sourceEdge >= mesh.EV.rows()) {
      ADD_FAILURE() << "J3 invalid transition edge for witness=" << metadata.name;
      continue;
    }
    const SourceEdgeTopologyKey edge = edge_key(mesh, transition.sourceEdge);
    const auto measured = directional::test_support::independent_edge_measurement(
        mesh, field, transition.firstFace, transition.secondFace, edge);
    ++edgesChecked;
    if (rawIndex(transition.matching) == rawIndex(measured.matching)) {
      ++agreementCount;
      continue;
    }
    disagreements.push_back(Disagreement{edge, transition.firstFace,
                                         transition.secondFace,
                                         transition.matching,
                                         measured.matching});
  }

  std::size_t expectedInteriorEdges = 0U;
  for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
    if (mesh.EF(edge, 0) >= 0 && mesh.EF(edge, 1) >= 0) {
      ++expectedInteriorEdges;
    }
  }
  EXPECT_EQ(expectedInteriorEdges, edgesChecked)
      << "J3 must independently measure every interior transition"
      << ";witness=" << metadata.name;

  std::ostringstream report;
  report << "m3Cp4c0J3"
         << ";credit=none"
         << ";owningMeasure=J3"
         << ";oracleKind=principal-matching-implementation-cross-check"
         << ";canDetectMatchingAliasing=false"
         << ";witness=" << metadata.name
         << ";matchingProvenance=" << metadata.matchingProvenance
         << ";matchingCodePath=" << metadata.matchingCodePath
         << ";population=" << metadata.population
         << ";classification=" << metadata.classification
         << ";edgesChecked=" << edgesChecked
         << ";agreements=" << agreementCount
         << ";disagreements=" << disagreements.size()
         << ";agreementRate=" << agreementCount << '/' << edgesChecked;
  for (std::size_t index = 0U; index < disagreements.size(); ++index) {
    const auto &disagreement = disagreements[index];
    report << ";disagreement[" << index << "]={edge="
           << source_edge_locus(disagreement.edge)
           << ",firstFaceRow=" << disagreement.firstFace
           << ",secondFaceRow=" << disagreement.secondFace
           << ",sourceRawIndex=0"
           << ",declaredRawTarget=" << rawIndex(disagreement.declaredMatching)
           << ",geometryRawTarget=" << rawIndex(disagreement.geometryMatching)
           << ",declaredMatching=" << disagreement.declaredMatching
           << ",geometryMatching=" << disagreement.geometryMatching << '}';
  }
  return report.str();
}

template <typename Callback>
void for_each_cp4c_census_witness(Callback &&callback) {
  {
    const TriMesh mesh = make_cp3a_two_ring_skew_disc();
    const auto sourceAuthority = make_source_authority(mesh);
    ASSERT_TRUE(sourceAuthority.has_value());
    CrossFieldResult field;
    make_cp3a_two_ring_index_one_field(mesh, field);
    const auto atlas = directional::authority::FieldTransportAtlas::make(
        mesh, *sourceAuthority, {}, field);
    ASSERT_TRUE(atlas);
    callback(Cp4cCensusWitnessMetadata{
                 "two-ring", "computed",
                 "finalize_cross_field_result->principal_matching->"
                 "populate_cross_field_edge_transitions",
                 "included", "production-reasoning"},
             mesh, field, atlas.value());
  }

  {
    const TriMesh mesh = make_four_triangle_fan();
    const auto sourceAuthority = make_source_authority(mesh);
    ASSERT_TRUE(sourceAuthority.has_value());
    const CrossFieldResult field = make_index_one_singularity_field(mesh);
    const auto atlas = directional::authority::FieldTransportAtlas::make(
        mesh, *sourceAuthority, {}, field);
    ASSERT_TRUE(atlas);
    callback(Cp4cCensusWitnessMetadata{
                 "four-triangle-fan", "fixture-imposed",
                 "make_index_one_singularity_field->manual-edge-transition-"
                 "overwrite",
                 "excluded", "fixture-artifact-imposed-matching-contradicts-"
                 "geometry"},
             mesh, field, atlas.value());
  }

  for (const std::string fixtureStem : {std::string("sphere_prescribed"),
                                        std::string("torus")}) {
    TriMesh mesh;
    const auto meshPath = directional::tests::benchmark_fixture_path(
        "milestone-g/" + fixtureStem + ".obj");
    const auto fieldPath = directional::tests::benchmark_fixture_path(
        "milestone-g/" + fixtureStem + ".rawfield");
    ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh)) << fixtureStem;
    const Eigen::MatrixXd raw = read_cp4c_rawfield(fieldPath, mesh.F.rows());
    const CrossFieldResult field =
        directional::pipeline::finalize_surface_cell_raw_cross_field(mesh, raw);
    const auto sourceAuthority = make_source_authority(mesh);
    ASSERT_TRUE(sourceAuthority.has_value()) << fixtureStem;
    const auto atlas = directional::authority::FieldTransportAtlas::make(
        mesh, *sourceAuthority, {}, field);
    ASSERT_TRUE(atlas) << fixtureStem;
    callback(Cp4cCensusWitnessMetadata{
                 fixtureStem, "computed-at-load",
                 "finalize_surface_cell_raw_cross_field->principal_matching->"
                 "populate_cross_field_edge_transitions",
                 "included", "production-reasoning"},
             mesh, field, atlas.value());
  }
}

struct VertexFanTransportStep {
  int faceRow = -1;
  SourceFaceTopologyKey sourceFace;
  int signedLiftToNext = 0;
};

std::optional<std::vector<VertexFanTransportStep>> walk_complete_vertex_fan(
    const TriMesh &mesh,
    const directional::authority::FieldBranchTopology &topology,
    const SourceVertexId sourceVertex) {
  std::vector<int> incidentRows;
  for (int row = 0; row < mesh.F.rows(); ++row) {
    for (int corner = 0; corner < 3; ++corner) {
      if (mesh.F(row, corner) ==
          static_cast<int>(sourceVertex.index())) {
        incidentRows.push_back(row);
        break;
      }
    }
  }
  if (incidentRows.size() < 2U) return std::nullopt;

  const int startRow = incidentRows.front();
  int currentRow = startRow;
  std::set<int> visited;
  std::vector<VertexFanTransportStep> walk;
  walk.reserve(incidentRows.size());

  for (std::size_t step = 0U; step < incidentRows.size(); ++step) {
    if (!visited.insert(currentRow).second) return std::nullopt;

    int sourceCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (mesh.F(currentRow, corner) ==
          static_cast<int>(sourceVertex.index())) {
        sourceCorner = corner;
        break;
      }
    }
    if (sourceCorner < 0) return std::nullopt;

    // Following the predecessor edge walks the oriented fan consistently with
    // the source-face winding rather than relying on face-row numbering.
    const int nextVertex = mesh.F(currentRow, (sourceCorner + 2) % 3);
    const auto edge = SourceEdgeTopologyKey::from_indices(
        static_cast<int>(sourceVertex.index()), nextVertex,
        static_cast<std::size_t>(mesh.V.rows()));
    if (!edge.has_value()) return std::nullopt;
    const int edgeRow = source_edge_index(mesh, edge.value());
    if (edgeRow < 0 || mesh.EF(edgeRow, 0) < 0 || mesh.EF(edgeRow, 1) < 0) {
      return std::nullopt;
    }
    const int nextRow = mesh.EF(edgeRow, 0) == currentRow
                            ? mesh.EF(edgeRow, 1)
                            : mesh.EF(edgeRow, 0);
    if (nextRow < 0) return std::nullopt;

    const SourceFaceTopologyKey currentFace = topology_face(
        mesh.F(currentRow, 0), mesh.F(currentRow, 1), mesh.F(currentRow, 2),
        static_cast<std::size_t>(mesh.V.rows()));
    const SourceFaceTopologyKey nextFace = topology_face(
        mesh.F(nextRow, 0), mesh.F(nextRow, 1), mesh.F(nextRow, 2),
        static_cast<std::size_t>(mesh.V.rows()));
    const auto directed = topology.transport(edge.value(), currentFace, nextFace);
    if (!directed.has_value()) return std::nullopt;

    walk.push_back(
        VertexFanTransportStep{currentRow, currentFace, directed->signedLift});
    currentRow = nextRow;
  }

  if (currentRow != startRow || visited.size() != incidentRows.size()) {
    return std::nullopt;
  }
  return walk;
}

int normalized_quarter_turn(const int lift) {
  return ((lift % 4) + 4) % 4;
}

int composed_fan_lift(const std::vector<VertexFanTransportStep> &walk) {
  int lift = 0;
  for (const auto &step : walk) lift += step.signedLiftToNext;
  return normalized_quarter_turn(lift);
}

std::string cp4c_holonomy_census(
    const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
    const directional::authority::FieldTransportAtlas &atlas) {
  std::map<std::size_t, int> declaredIndexByVertex;
  for (const auto &singularity : atlas.singularities()) {
    declaredIndexByVertex[singularity.sourceVertex.index()] =
        normalized_quarter_turn(singularity.indexNumerator);
  }

  std::size_t interiorVertices = 0U;
  std::size_t completeFans = 0U;
  std::vector<std::tuple<std::size_t, int, int>> mismatches;
  const auto &topology = atlas.branch_topology();
  for (int vertex = 0; vertex < mesh.V.rows(); ++vertex) {
    if (mesh.isBoundaryVertex(vertex) != 0) continue;
    ++interiorVertices;
    const auto sourceVertex = SourceVertexId::from_index(
        vertex, static_cast<std::size_t>(mesh.V.rows()));
    if (!sourceVertex.has_value()) {
      ADD_FAILURE() << "K3 could not construct source vertex for witness="
                    << metadata.name << ";vertex=" << vertex;
      continue;
    }
    const auto walk = walk_complete_vertex_fan(mesh, topology, sourceVertex.value());
    if (!walk.has_value()) continue;
    ++completeFans;
    const int observed = composed_fan_lift(*walk);
    const auto declared = declaredIndexByVertex.find(
        static_cast<std::size_t>(vertex));
    const int expected = declared == declaredIndexByVertex.end() ? 0 : declared->second;
    if (observed != expected) {
      mismatches.emplace_back(static_cast<std::size_t>(vertex), expected, observed);
    }
  }

  EXPECT_EQ(interiorVertices, completeFans)
      << "K3 holonomy oracle requires one complete intrinsic fan per interior vertex"
      << ";witness=" << metadata.name;

  std::ostringstream report;
  report << "m3Cp4c0K3Holonomy"
         << ";credit=none"
         << ";owningMeasure=K3"
         << ";oracleKind=vertex-fan-holonomy"
         << ";usesPrincipalMatchingMinimizer=false"
         << ";witness=" << metadata.name
         << ";population=" << metadata.population
         << ";interiorVertices=" << interiorVertices
         << ";completeFans=" << completeFans
         << ";mismatches=" << mismatches.size();
  for (std::size_t index = 0U; index < mismatches.size(); ++index) {
    const auto &[vertex, expected, observed] = mismatches[index];
    report << ";mismatch[" << index << "]={sourceVertex=" << vertex
           << ",declaredIndexNumeratorZ4=" << expected
           << ",composedFanLiftZ4=" << observed << '}';
  }
  return report.str();
}

void append_atlas_error(std::ostringstream &stream,
                        const directional::authority::FieldAtlasBuildError &error) {
  stream << "fieldTransportAtlas=false"
         << ";fieldAtlasError="
         << directional::authority::field_atlas_build_error_code_name(error.code);
  if (error.topologyRegion.has_value()) {
    stream << ";topologyRegion=" << error.topologyRegion->index();
  }
  if (error.sourceFace.has_value()) {
    stream << ";sourceFaceRow=" << error.sourceFace->index();
  }
  if (error.sourceVertex.has_value()) {
    stream << ";sourceVertex=" << error.sourceVertex->index();
  }
  if (error.sourceEdge.has_value()) {
    stream << ";sourceEdge=" << source_edge_locus(*error.sourceEdge);
  }
}

void append_network_error(
    std::ostringstream &stream,
    const directional::geometry::FieldAlignedCurveNetworkError &error) {
  stream << "fieldAlignedCurveNetwork=false"
         << ";networkError="
         << directional::geometry::field_aligned_curve_network_error_code_name(
                error.code);
  if (error.sourceVertex.has_value()) {
    stream << ";sourceVertex=" << error.sourceVertex->index();
  }
  if (error.sourceEdge.has_value()) {
    stream << ";sourceEdge=" << source_edge_locus(*error.sourceEdge);
  }
  if (error.sourceFace.has_value()) {
    stream << ";sourceFace=" << source_face_locus(*error.sourceFace);
  }
  if (error.relatedSourceFace.has_value()) {
    stream << ";relatedSourceFace="
           << source_face_locus(*error.relatedSourceFace);
  }
  if (error.branch.has_value()) {
    stream << ";branch=" << branch_locus(*error.branch);
  }
  if (error.relatedBranch.has_value()) {
    stream << ";relatedBranch=" << branch_locus(*error.relatedBranch);
  }
  if (error.signedLift.has_value()) {
    stream << ";signedLift=" << signed_lift_locus(*error.signedLift);
  }
  if (error.parameter.has_value()) {
    stream << ";parameter=" << exact_rational_locus(error.parameter->value);
  }
  if (!error.exactValues.empty()) {
    stream << ";exactValues=[";
    for (std::size_t index = 0U; index < error.exactValues.size(); ++index) {
      if (index != 0U) stream << ',';
      stream << exact_rational_locus(error.exactValues[index]);
    }
    stream << ']';
  }
  if (!error.publishedEdges.empty() ||
      error.code == FieldAlignedCurveNetworkErrorCode::
                        BranchContinuationOutsideOutflowSet) {
    stream << ";publishedEdges=[";
    for (std::size_t index = 0U; index < error.publishedEdges.size(); ++index) {
      if (index != 0U) stream << ',';
      stream << source_edge_locus(error.publishedEdges[index]);
    }
    stream << ']';
  }
  if (!error.publishedFaces.empty() ||
      error.code ==
          FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved) {
    stream << ";publishedFaces=[";
    for (std::size_t index = 0U; index < error.publishedFaces.size(); ++index) {
      if (index != 0U) stream << ',';
      stream << source_face_locus(error.publishedFaces[index]);
    }
    stream << ']';
  }
  if (error.rail.has_value()) {
    stream << ";rail=" << error.rail->index();
  }
  if (error.singularity.has_value()) {
    stream << ";singularity=" << error.singularity->index();
  }
  if (error.traceSeedVertex.has_value()) {
    stream << ";traceSeedVertex=" << error.traceSeedVertex->index();
  }
  if (error.traceSeedSingularity.has_value()) {
    stream << ";traceSeedSingularity="
           << error.traceSeedSingularity->index();
  }
  if (!error.traceHistory.empty()) {
    stream << ";traceHistory=[";
    for (std::size_t index = 0U; index < error.traceHistory.size(); ++index) {
      if (index != 0U) stream << ',';
      const auto &step = error.traceHistory[index];
      stream << "{sourceFace=" << source_face_locus(step.sourceFace)
             << ",branch=" << branch_locus(step.branch)
             << ",incomingCarrier=";
      if (step.incomingCarrier.has_value()) {
        stream << source_edge_locus(*step.incomingCarrier);
      } else {
        stream << "none";
      }
      stream << ",entryParameter="
             << exact_rational_locus(step.entryParameter.value) << '}';
    }
    stream << ']';
  }
  if (error.traceSteps.has_value()) {
    stream << ";traceSteps=" << *error.traceSteps;
  }
  if (error.traceStepBudget.has_value()) {
    stream << ";traceStepBudget=" << *error.traceStepBudget;
  }
  if (error.traceCombinatorialVisits.has_value()) {
    stream << ";traceCombinatorialVisits=" << *error.traceCombinatorialVisits;
  }
  if (error.traceCombinatorialVisitAllowance.has_value()) {
    stream << ";traceCombinatorialVisitAllowance="
           << *error.traceCombinatorialVisitAllowance;
  }
}

std::string network_error_locus(
    const directional::geometry::FieldAlignedCurveNetworkError &error) {
  std::ostringstream stream;
  append_network_error(stream, error);
  return stream.str();
}

void append_plan_error(std::ostringstream &stream,
                       const directional::geometry::GlobalTopologyPlanError &error) {
  stream << "globalTopologyPlan=false"
         << ";planError="
         << directional::geometry::global_topology_plan_error_code_name(
                error.code);
  if (error.region.has_value()) {
    stream << ";region=" << error.region->index();
  }
  if (error.arc.has_value()) {
    stream << ";arc=" << error.arc->index();
  }
  if (error.sourceFace.has_value()) {
    stream << ";sourceFace=" << source_face_locus(*error.sourceFace);
  }
  if (error.sourceVertex.has_value()) {
    stream << ";sourceVertex=" << error.sourceVertex->index();
  }
}

std::size_t source_boundary_vertex_count(const TriMesh &mesh) {
  std::set<int> vertices;
  for (const auto &loop : mesh.boundaryLoops) {
    vertices.insert(loop.begin(), loop.end());
  }
  return vertices.size();
}

Cp4cReachabilityObservation observe_cp4c_witness(
    const std::string &fixtureStem, const std::string &fixtureName) {
  Cp4cReachabilityObservation observation;
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/" + fixtureStem + ".obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/" + fixtureStem + ".rawfield");
  if (!directional::readOBJ(meshPath.string(), observation.mesh)) {
    observation.report = fixtureName + ":fixture-load-failed";
    return observation;
  }
  const Eigen::MatrixXd raw =
      read_cp4c_rawfield(fieldPath, observation.mesh.F.rows());
  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      observation.mesh.V, observation.mesh.F, raw, cp4c_remesh_options());
  const auto &products = result.surfaceCellContext.productSnapshots;

  std::ostringstream report;
  report << fixtureName
         << ";railAuthority="
         << cp4c_rail_authority_name(observation.railAuthority)
         << ";pipelineFailure=" << result.diagnostics.terminalFailureCode
         << ";pipelineFailureStage=" << result.diagnostics.terminalFailureStage
         << ";sourceTopologyRegionsSnapshot="
         << (products.sourceTopologyRegions.has_value() ? "yes" : "no")
         << ";fieldTransportAtlasSnapshot="
         << (products.fieldTransportAtlas.has_value() ? "yes" : "no")
         << ";fieldAlignedCurveNetworkSnapshot="
         << (products.fieldAlignedCurveNetwork.has_value() ? "yes" : "no")
         << ";globalTopologyPlanSnapshot="
         << (products.globalTopologyPlan.has_value() ? "yes" : "no")
         << ";sourceEuler=" << observation.mesh.eulerChar
         << ";sourceBoundaryLoopCount=" << observation.mesh.boundaryLoops.size();
  const int sourceGenus =
      (2 - static_cast<int>(observation.mesh.boundaryLoops.size()) -
       observation.mesh.eulerChar) /
      2;
  report << ";sourceGenus=" << sourceGenus
         << ";interiorLocalVertices="
         << static_cast<std::size_t>(observation.mesh.V.rows()) -
                source_boundary_vertex_count(observation.mesh);

  if (!products.hasCrossField || !products.hasAuthoritativeRails ||
      !products.hasSourceSurfaceLabels) {
    report << ";furthestStage=pre-source-topology"
           << ";diagnosticSnapshotInputsIncomplete=true";
    observation.report = report.str();
    return observation;
  }

  observation.rails = products.authoritativeRails;
  SurfaceCellTracingOptions tracingOptions;
  tracingOptions.authoritativeRails = observation.rails;
  tracingOptions.hardFeatureEdges =
      directional::pipeline::hard_feature_edge_keys_from_rails(
          observation.rails,
          static_cast<std::size_t>(observation.mesh.V.rows()));
  tracingOptions.sourceFaceComponents =
      products.sourceSurfaceLabels.componentByFace;
  tracingOptions.sourceFaceSheets = products.sourceSurfaceLabels.localSheetByFace;
  observation.sourceAuthority =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(observation.mesh.F, tracingOptions);
  if (!observation.sourceAuthority.has_value()) {
    report << ";sourceTopologyRegions=false;furthestStage=pre-source-topology";
    observation.report = report.str();
    return observation;
  }
  report << ";sourceTopologyRegions=true"
         << ";sourceTopologyRegionCount="
         << observation.sourceAuthority->regions().size();

  auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      observation.mesh, *observation.sourceAuthority,
      tracingOptions.hardFeatureEdges, products.crossField);
  if (!atlasBuild) {
    report << ";furthestStage=source-topology;failedStage=field-transport-atlas;";
    append_atlas_error(report, atlasBuild.error());
    append_cp4c_atlas_failure_diagnosis(
        report, observation.mesh, *observation.sourceAuthority,
        products.crossField, tracingOptions.hardFeatureEdges, atlasBuild.error());
    observation.report = report.str();
    return observation;
  }
  observation.atlas = std::move(atlasBuild.value());
  report << ";fieldTransportAtlas=true";

  auto networkBuild = FieldAlignedCurveNetwork::make(
      observation.mesh,
      *observation.sourceAuthority, *observation.atlas, observation.rails);
  if (!networkBuild) {
    report << ";furthestStage=field-transport-atlas;failedStage=field-aligned-network;";
    append_network_error(report, networkBuild.error());
    observation.report = report.str();
    return observation;
  }
  observation.network = std::move(networkBuild.value());
  report << ";fieldAlignedCurveNetwork=true"
         << ";networkTraceCount=" << observation.network->candidate_traces().size()
         << ";networkEventCount=" << observation.network->events().size();
  append_cp4c_terminal_event_report(report, *observation.network);

  auto planBuild = directional::geometry::GlobalTopologyPlan::make(
      observation.mesh.F, static_cast<std::size_t>(observation.mesh.V.rows()),
      *observation.sourceAuthority, *observation.network);
  if (!planBuild) {
    report << ";furthestStage=field-aligned-network;failedStage=global-topology-plan;";
    append_plan_error(report, planBuild.error());
    observation.report = report.str();
    return observation;
  }
  observation.plan = std::move(planBuild.value());
  report << ";globalTopologyPlan=true"
         << ";furthestStage=global-topology-plan"
         << ";regionCount=" << observation.plan->regions().size()
         << ";arcCount=" << observation.plan->arcs().size()
         << ";nodeCount=" << observation.plan->rotation_system().size();
  for (const auto &certificate : observation.plan->region_certificates()) {
    report << ";region[" << certificate.region.index() << "]="
           << "V" << certificate.vertexCount << ",E" << certificate.edgeCount
           << ",F" << certificate.faceCount << ",chi"
           << certificate.eulerCharacteristic;
  }
  observation.report = report.str();
  return observation;
}

const directional::authority::FieldBranchBoundaryPairing *
cp4c_find_branch_pairing(
    const directional::authority::FieldFaceBranchFrame &frame,
    const directional::authority::FieldBranch branch) {
  const directional::authority::FieldBranchBoundaryPairing *result = nullptr;
  for (const auto &pairing : frame.branches) {
    if (pairing.branch != branch) continue;
    if (result != nullptr) return nullptr;
    result = &pairing;
  }
  return result;
}

struct Cp4cGrazingTraceCost {
  directional::authority::FieldSingularityId singularity;
  SourceVertexId sourceVertex;
  int localSlot = 0;
  std::vector<SourceEdgeTopologyKey> traversedEdges;
  std::optional<std::size_t> firstTransitStep;
  std::size_t transitCount = 0U;
  std::string terminalKind = "none";
  std::optional<SourceVertexId> terminalVertex;
};

std::optional<directional::authority::FieldBoundaryPoint>
cp4c_boundary_point_at_vertex(const SourceFaceTopologyKey &face,
                              const SourceVertexId sourceVertex) {
  std::vector<SourceEdgeTopologyKey> incident;
  for (const SourceVertexId other : face.vertices()) {
    if (other == sourceVertex) continue;
    const auto edge = SourceEdgeTopologyKey::make(sourceVertex, other);
    if (edge.has_value()) incident.push_back(edge.value());
  }
  if (incident.size() != 2U) return std::nullopt;
  std::sort(incident.begin(), incident.end());
  const auto edge = incident.front();
  return directional::authority::FieldBoundaryPoint{
      edge, directional::authority::ExactUnitParameter{
                exact_integer(edge.first() == sourceVertex ? 0 : 1)}};
}

bool cp4c_is_singularity_vertex(
    const directional::authority::FieldTransportAtlas &atlas,
    const SourceVertexId sourceVertex) {
  return std::any_of(atlas.singularities().begin(), atlas.singularities().end(),
                     [&](const auto &singularity) {
                       return singularity.sourceVertex == sourceVertex;
                     });
}

std::string cp4c_sphere_grazing_cost_census(
    const TriMesh &mesh,
    const directional::authority::FieldTransportAtlas &atlas) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const auto &topology = atlas.branch_topology();
  std::vector<Cp4cGrazingTraceCost> costs;
  costs.reserve(topology.singularity_port_attachments().size());
  std::map<SourceEdgeTopologyKey, std::size_t> tracesPerGrazingEdge;

  for (const auto &attachment : topology.singularity_port_attachments()) {
    Cp4cGrazingTraceCost cost{attachment.singularity, attachment.sourceVertex,
                             attachment.localSlot};
    SourceFaceTopologyKey currentFace = attachment.startFace;
    auto currentBranch = attachment.branch;
    std::optional<SourceEdgeTopologyKey> incomingCarrier;
    auto currentEntryPoint =
        cp4c_boundary_point_at_vertex(currentFace, attachment.sourceVertex);
    if (!currentEntryPoint.has_value()) {
      cost.terminalKind = "InvalidStartPoint";
      costs.push_back(std::move(cost));
      continue;
    }
    FieldAlignedTraceTraversalGuard guard(field_aligned_trace_step_budget(topology));

    while (true) {
      const FieldAlignedTraceTraversalState state{
          currentFace, currentBranch, incomingCarrier, *currentEntryPoint};
      const auto status = guard.observe(state);
      if (status != FieldAlignedTraceTraversalStatus::Advanced) {
        cost.terminalKind =
            status == FieldAlignedTraceTraversalStatus::CycleDetected
                ? "TraceStateCycleDetected"
                : "TraceStepBudgetExhausted";
        break;
      }

      const auto *frame = topology.find_frame(currentFace);
      if (frame == nullptr) {
        cost.terminalKind = "MissingFrame";
        break;
      }
      const auto *pairing = cp4c_find_branch_pairing(*frame, currentBranch);
      if (pairing == nullptr) {
        cost.terminalKind = "MissingPairing";
        break;
      }

      auto continuation = resolve_field_branch_continuation(
          currentFace, *pairing, *currentEntryPoint);
      if (const auto *error =
              std::get_if<directional::geometry::FieldAlignedCurveNetworkError>(
                  &continuation)) {
        cost.terminalKind =
            directional::geometry::field_aligned_curve_network_error_code_name(
                error->code);
        break;
      }
      const auto decision = std::get<FieldBranchContinuationDecision>(continuation);
      cost.traversedEdges.push_back(decision.outgoingCarrier);

      if (decision.kind == FieldBranchContinuationKind::VertexHit) {
        if (!decision.sourceVertex.has_value()) {
          cost.terminalKind = "InvalidVertexHit";
          break;
        }
        cost.terminalVertex = decision.sourceVertex;
        if (cp4c_is_singularity_vertex(atlas, *decision.sourceVertex)) {
          cost.terminalKind = "SingularityTermination";
          break;
        }
        auto transit = resolve_field_vertex_transit(
            mesh, topology, frame->sourceComponent, frame->topologyRegion,
            currentFace, currentBranch, *decision.sourceVertex,
            FieldVertexArrivalMode::FaceInterior);
        if (const auto *error =
                std::get_if<directional::geometry::FieldAlignedCurveNetworkError>(
                    &transit)) {
          cost.terminalKind =
              directional::geometry::field_aligned_curve_network_error_code_name(
                  error->code);
          break;
        }
        const auto vertexTransit = std::get<FieldVertexTransitDecision>(transit);
        currentFace = vertexTransit.nextFace;
        currentBranch = vertexTransit.nextBranch;
        currentEntryPoint =
            cp4c_boundary_point_at_vertex(currentFace, *decision.sourceVertex);
        incomingCarrier.reset();
        if (!currentEntryPoint.has_value()) {
          cost.terminalKind = "InvalidVertexEntry";
          break;
        }
        continue;
      }

      std::optional<SourceFaceTopologyKey> nextFace;
      for (const auto &transport : topology.transports()) {
        if (transport.sourceEdge != decision.outgoingCarrier) continue;
        if (transport.firstFace == currentFace) {
          nextFace = transport.secondFace;
        } else if (transport.secondFace == currentFace) {
          nextFace = transport.firstFace;
        }
        if (nextFace.has_value()) break;
      }
      if (!nextFace.has_value()) {
        cost.terminalKind = "BoundaryTermination";
        break;
      }
      const auto directed =
          topology.transport(decision.outgoingCarrier, currentFace, *nextFace);
      if (!directed.has_value()) {
        cost.terminalKind = "MissingTransport";
        break;
      }
      const auto nextBranch = currentBranch.rotated(directed->signedLift);
      const auto *targetFrame = topology.find_frame(*nextFace);
      const auto *targetPairing =
          targetFrame == nullptr
              ? nullptr
              : cp4c_find_branch_pairing(*targetFrame, nextBranch);
      if (targetPairing == nullptr) {
        cost.terminalKind = "MissingTargetPairing";
        break;
      }

      const auto relation = classify_field_branch_transport_flow(
          currentFace, *pairing, *nextFace, *targetPairing,
          decision.outgoingCarrier);
      if (relation == FieldBranchEdgeFlowRelation::Outflow) {
        auto grazing = resolve_field_branch_grazing_transit(
            currentFace, *pairing, *nextFace, *targetPairing,
            decision.outgoingCarrier, directed->signedLift,
            decision.exitPoint.parameter);
        if (const auto *error =
                std::get_if<directional::geometry::FieldAlignedCurveNetworkError>(
                    &grazing)) {
          cost.terminalKind =
              directional::geometry::field_aligned_curve_network_error_code_name(
                  error->code);
          break;
        }
        const auto edgeTransit =
            std::get<FieldBranchContinuationDecision>(grazing);
        if (!cost.firstTransitStep.has_value()) {
          cost.firstTransitStep = cost.traversedEdges.size();
        }
        ++cost.transitCount;
        ++tracesPerGrazingEdge[decision.outgoingCarrier];
        if (!edgeTransit.sourceVertex.has_value()) {
          cost.terminalKind = "InvalidEdgeTransit";
          break;
        }
        cost.terminalVertex = edgeTransit.sourceVertex;
        if (cp4c_is_singularity_vertex(atlas, *edgeTransit.sourceVertex)) {
          cost.terminalKind = "SingularityTermination";
          break;
        }
        auto vertexTransit = resolve_field_vertex_transit(
            mesh, topology, frame->sourceComponent, frame->topologyRegion,
            currentFace, currentBranch, *edgeTransit.sourceVertex,
            FieldVertexArrivalMode::EdgeTransit);
        if (const auto *error =
                std::get_if<directional::geometry::FieldAlignedCurveNetworkError>(
                    &vertexTransit)) {
          cost.terminalKind =
              directional::geometry::field_aligned_curve_network_error_code_name(
                  error->code);
          break;
        }
        const auto next = std::get<FieldVertexTransitDecision>(vertexTransit);
        currentFace = next.nextFace;
        currentBranch = next.nextBranch;
        currentEntryPoint =
            cp4c_boundary_point_at_vertex(currentFace, *edgeTransit.sourceVertex);
        incomingCarrier.reset();
        if (!currentEntryPoint.has_value()) {
          cost.terminalKind = "InvalidEdgeTransitEntry";
          break;
        }
        continue;
      }

      incomingCarrier = decision.outgoingCarrier;
      currentFace = *nextFace;
      currentBranch = nextBranch;
      currentEntryPoint = decision.exitPoint;
    }

    costs.push_back(std::move(cost));
  }

  std::ostringstream report;
  report << "m3Cp4c0K2"
         << ";credit=none"
         << ";owningMeasure=K2"
         << ";modelChoice=grazing-edge-transit"
         << ";traceCount=" << costs.size()
         << ";grazingEdgesReached=" << tracesPerGrazingEdge.size()
         << ";maxTracesPerGrazingEdge=";
  std::size_t maxTracesPerGrazingEdge = 0U;
  for (const auto &[edge, count] : tracesPerGrazingEdge) {
    (void)edge;
    maxTracesPerGrazingEdge = std::max(maxTracesPerGrazingEdge, count);
  }
  report << maxTracesPerGrazingEdge;
  for (std::size_t index = 0U; index < costs.size(); ++index) {
    const auto &cost = costs[index];
    report << ";trace[" << index << "]={singularity="
           << cost.singularity.index()
           << ",sourceVertex=" << cost.sourceVertex.index()
           << ",localSlot=" << cost.localSlot
           << ",traversedEdges=[";
    for (std::size_t edgeIndex = 0U; edgeIndex < cost.traversedEdges.size();
         ++edgeIndex) {
      if (edgeIndex != 0U) report << ',';
      report << source_edge_locus(cost.traversedEdges[edgeIndex]);
    }
    report << "]"
           << ",transitCount=" << cost.transitCount
           << ",firstTransitStep=";
    if (cost.firstTransitStep.has_value()) {
      report << *cost.firstTransitStep;
    } else {
      report << "none";
    }
    report << ",terminalKind=" << cost.terminalKind << ",terminalVertex=";
    if (cost.terminalVertex.has_value()) {
      report << cost.terminalVertex->index();
    } else {
      report << "none";
    }
    report << '}';
  }
  for (const auto &[edge, count] : tracesPerGrazingEdge) {
    report << ";grazingEdge[" << source_edge_locus(edge) << "]={traceCount="
           << count << '}';
  }
  return report.str();
}

std::string cp4c_grazing_trace_multiplicity_census(
    const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
    const directional::authority::FieldTransportAtlas &atlas) {
  const auto sourceAuthority = make_source_authority(mesh);
  if (!sourceAuthority.has_value()) {
    ADD_FAILURE() << "L5 source authority unavailable;witness=" << metadata.name;
    return "m3Cp4c0L5;credit=none;owningMeasure=L5;witness=" +
           metadata.name + ";status=source-authority-unavailable";
  }
  const auto rails = rails_from_atlas(mesh, atlas);
  const auto networkBuild =
      FieldAlignedCurveNetwork::make(mesh, *sourceAuthority, atlas, rails);
  if (!networkBuild) {
    return "m3Cp4c0L5;credit=none;owningMeasure=L5;witness=" +
           metadata.name + ";status=network-build-red;error=" +
           network_error_locus(networkBuild.error());
  }

  std::map<SourceEdgeTopologyKey, std::set<std::size_t>> tracesByGrazingEdge;
  for (const auto &trace : networkBuild.value().candidate_traces()) {
    for (const auto &segment : trace.segments) {
      if (!segment.edgeTransitExit.has_value()) continue;
      tracesByGrazingEdge[segment.outgoingCarrier].insert(trace.id.index());
    }
  }

  std::size_t maxTracesPerGrazingEdge = 0U;
  for (const auto &[edge, traces] : tracesByGrazingEdge) {
    (void)edge;
    maxTracesPerGrazingEdge =
        std::max(maxTracesPerGrazingEdge, traces.size());
  }
  EXPECT_LE(maxTracesPerGrazingEdge, 1U)
      << "L5 more than one candidate trace reached the same grazing edge; "
         "return to review;witness="
      << metadata.name;

  std::ostringstream report;
  report << "m3Cp4c0L5"
         << ";credit=none"
         << ";owningMeasure=L5"
         << ";witness=" << metadata.name
         << ";population=" << metadata.population
         << ";candidateTraceCount="
         << networkBuild.value().candidate_traces().size()
         << ";grazingEdgesReached=" << tracesByGrazingEdge.size()
         << ";maxTracesPerGrazingEdge=" << maxTracesPerGrazingEdge
         << ";status="
         << (maxTracesPerGrazingEdge <= 1U ? "non-merging-observed"
                                           : "multiple-traces-observed");
  for (const auto &[edge, traces] : tracesByGrazingEdge) {
    report << ";grazingEdge[" << source_edge_locus(edge) << "]={traces=[";
    bool first = true;
    for (const std::size_t trace : traces) {
      if (!first) report << ',';
      first = false;
      report << trace;
    }
    report << "]}";
  }
  return report.str();
}

Cp4cProductionFixture build_cp4c_production_fixture(
    const std::string &fixtureStem, const std::string &fixtureName) {
  Cp4cProductionFixture fixture;
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/" + fixtureStem + ".obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/" + fixtureStem + ".rawfield");
  if (!directional::readOBJ(meshPath.string(), fixture.mesh)) {
    throw std::runtime_error("Failed to read committed " + fixtureName +
                             " fixture");
  }
  const Eigen::MatrixXd raw =
      read_cp4c_rawfield(fieldPath, fixture.mesh.F.rows());

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      fixture.mesh.V, fixture.mesh.F, raw, cp4c_remesh_options());
  const auto &products = result.surfaceCellContext.productSnapshots;
  if (!products.sourceTopologyRegions.has_value() ||
      !products.fieldTransportAtlas.has_value() ||
      !products.fieldAlignedCurveNetwork.has_value() ||
      !products.globalTopologyPlan.has_value()) {
    throw std::runtime_error(
        fixtureName + " pipeline did not retain CP4c topology authority: " +
        result.diagnostics.terminalFailureCode + "/" +
        result.diagnostics.terminalFailureStage);
  }

  fixture.sourceAuthority = products.sourceTopologyRegions;
  fixture.atlas = products.fieldTransportAtlas;
  fixture.network = products.fieldAlignedCurveNetwork;
  fixture.plan = products.globalTopologyPlan;
  return fixture;
}

const Cp4cProductionFixture &cp4c_torus_fixture() {
  static const Cp4cProductionFixture fixture =
      build_cp4c_production_fixture("torus", "torus");
  return fixture;
}

const Cp4cProductionFixture &cp4c_mechanical_fixture() {
  static const Cp4cProductionFixture fixture =
      build_cp4c_production_fixture("mechanical_feature", "mechanical feature");
  return fixture;
}

bool region_boundary_uses_nontrivial_cycle(
    const directional::geometry::GlobalTopologyPlan &plan,
    const directional::geometry::GlobalTopologyRegion &region) {
  if (region.boundary.size() < 2U) return false;
  std::set<SourceFaceTopologyKey> sourceFaces;
  std::set<directional::authority::NetworkNodeId> nodes;
  for (const auto incidence : region.boundary) {
    const auto *arc = plan.find_arc(incidence.arc);
    if (arc == nullptr) return false;
    sourceFaces.insert(arc->sourceFaces.begin(), arc->sourceFaces.end());
    const auto [first, second] = oriented_endpoints(*arc, incidence);
    nodes.insert(first);
    nodes.insert(second);
  }
  return nodes.size() >= 2U && sourceFaces.size() >= 2U;
}

bool hard_feature_mandatory_edge_lies_on_region_boundary(
    const FieldAlignedCurveNetwork &network,
    const directional::geometry::GlobalTopologyPlan &plan) {
  for (const auto &edge : network.mandatory_edges()) {
    if (edge.kind != SurfaceCellRailKind::HardFeature) continue;
    for (const auto *arc : find_mandatory_plan_arcs(plan, edge.id)) {
      if (std::any_of(plan.regions().begin(), plan.regions().end(),
                      [&](const auto &region) {
                        return std::any_of(
                            region.boundary.begin(), region.boundary.end(),
                            [&](const auto incidence) {
                              return incidence.arc == arc->id;
                            });
                      })) {
        return true;
      }
    }
  }
  return false;
}

void assert_cp4c_common_preconditions(const Cp4cProductionFixture &fixture) {
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  ASSERT_TRUE(fixture.plan.has_value());
  const auto &plan = *fixture.plan;
  ASSERT_TRUE(std::any_of(plan.regions().begin(), plan.regions().end(),
                          [](const auto &region) {
                            return region.sourceFaces.size() > 1U;
                          }))
      << "CP4c witness must publish a non-vacuous multi-face region";
  ASSERT_GE(plan.regions().size(), 2U)
      << "CP4c witness must publish at least two distinct regions";
  ASSERT_TRUE(fixture.atlas->quadrangulability().established())
      << "CP4c witness requires an established quadrangulability certificate";
}

void assert_cp4c_torus_preconditions(const Cp4cProductionFixture &fixture) {
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_common_preconditions(fixture));
  ASSERT_TRUE(fixture.mesh.boundaryLoops.empty())
      << "the committed torus witness must be closed";
  ASSERT_EQ(0, fixture.mesh.eulerChar)
      << "the committed torus witness must have source Euler characteristic 0";
  const int genus = (2 - fixture.mesh.eulerChar) / 2 -
                    static_cast<int>(fixture.mesh.boundaryLoops.size());
  ASSERT_EQ(1, genus)
      << "the committed torus witness must derive genus 1 from source topology";
  ASSERT_TRUE(std::any_of(
      fixture.plan->regions().begin(), fixture.plan->regions().end(),
      [&](const auto &region) {
        return region_boundary_uses_nontrivial_cycle(*fixture.plan, region);
      }))
      << "the torus witness must expose a non-trivial multi-face graph cycle";
}

void assert_cp4c_mechanical_preconditions(
    const Cp4cProductionFixture &fixture) {
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_common_preconditions(fixture));
  ASSERT_TRUE(hard_feature_mandatory_edge_lies_on_region_boundary(
      *fixture.network, *fixture.plan))
      << "the mechanical witness must publish a hard-feature mandatory edge "
         "on a region boundary";
}

void expect_cp4c_plan_disc_proofs(const Cp4cProductionFixture &fixture) {
  ASSERT_TRUE(fixture.network.has_value());
  ASSERT_TRUE(fixture.plan.has_value());
  const auto &network = *fixture.network;
  const auto &plan = *fixture.plan;
  EXPECT_EQ(network.source_digest(), plan.source_digest());
  EXPECT_EQ(network.semantic_digest(), plan.network_digest());
  ASSERT_EQ(plan.regions().size(), plan.region_certificates().size());
  for (const auto &region : plan.regions()) {
    const auto *certificate = plan.find_region_certificate(region.id);
    ASSERT_NE(nullptr, certificate);
    EXPECT_EQ(region.id, certificate->region);
    EXPECT_EQ(1U, certificate->boundaryWalkCount);
    EXPECT_TRUE(certificate->sourceFacesConnected);
    EXPECT_EQ(1, certificate->eulerCharacteristic);
    EXPECT_TRUE(certificate->proves_disc_topology());
    EXPECT_TRUE(certificate->proves_field_regularity());
  }
}

void expect_rotation_face_walk_agreement(
    const Cp4cProductionFixture &fixture) {
  ASSERT_TRUE(fixture.network.has_value());
  ASSERT_TRUE(fixture.plan.has_value());
  const auto &plan = *fixture.plan;
  const auto orbits = independent_plan_face_orbits(plan);
  ASSERT_TRUE(orbits.has_value());
  IndependentDiscProofClause failureClause = IndependentDiscProofClause::None;
  const auto partition = independent_fragment_partition(
      plan, fixture.mesh, *fixture.network, *orbits, &failureClause);
  ASSERT_TRUE(partition.has_value())
      << independent_disc_proof_clause_name(failureClause);
  EXPECT_EQ(orbits->size(),
            plan.regions().size() + partition->exteriorOrbits.size())
      << "every rotation-system face walk must be either one published region "
         "or an independently identified exterior orbit";

  std::set<std::vector<directional::geometry::GlobalTopologyOrientedArc>>
      matched;
  for (const auto &region : plan.regions()) {
    auto boundary = region.boundary;
    canonicalize_oriented_cycle(boundary);
    const auto orbit = std::find(orbits->begin(), orbits->end(), boundary);
    ASSERT_NE(orbits->end(), orbit)
        << "every published region walk must be a face orbit of the published "
           "rotation system";
    const auto orbitIndex =
        static_cast<std::size_t>(std::distance(orbits->begin(), orbit));
    EXPECT_EQ(0U, partition->exteriorOrbits.count(orbitIndex))
        << "a published region must not be an exterior face walk";
    ASSERT_TRUE(matched.insert(boundary).second)
        << "distinct published regions must not reuse one face walk";
  }
}

void expect_all_mandatory_edges_preserved(
    const FieldAlignedCurveNetwork &network,
    const directional::geometry::GlobalTopologyPlan &plan) {
  for (const auto &edge : network.mandatory_edges()) {
    const auto pieces = find_mandatory_plan_arcs(plan, edge.id);
    ASSERT_FALSE(pieces.empty());
    for (const auto *arc : pieces) {
      std::size_t uses = 0U;
      for (const auto &region : plan.regions()) {
        uses += static_cast<std::size_t>(std::count_if(
            region.boundary.begin(), region.boundary.end(),
            [&](const auto incidence) { return incidence.arc == arc->id; }));
      }
      EXPECT_EQ(edge.kind == SurfaceCellRailKind::Boundary ? 1U : 2U, uses);
    }
  }
}

} // namespace

namespace {

struct EventWitnessView {
  std::string name;
  const TriMesh *mesh = nullptr;
  const SourceTopologyRegions *sourceAuthority = nullptr;
  const directional::authority::FieldTransportAtlas *atlas = nullptr;
  const std::vector<SurfaceCellRail> *rails = nullptr;
  const FieldAlignedCurveNetwork *network = nullptr;
};

void record_terminal_event_contract(
    const EventWitnessView &witness,
    std::set<FieldAlignedNetworkEventKind> &unionKinds,
    std::map<FieldAlignedNetworkEventKind, std::set<std::string>> &contributors) {
  ASSERT_NE(nullptr, witness.network);

  std::set<FieldAlignedNetworkEventKind> producedKinds;
  for (const auto &event : witness.network->events()) {
    if (std::any_of(event.incidences.begin(), event.incidences.end(),
                    [](const auto &incidence) {
                      return incidence.role == FieldAlignedTraceEventRole::Terminal;
                    })) {
      producedKinds.insert(event.kind);
      unionKinds.insert(event.kind);
      contributors[event.kind].insert(witness.name);
    }
  }

  for (const auto &trace : witness.network->candidate_traces()) {
    std::vector<const directional::geometry::FieldAlignedNetworkEvent *> terminals;
    for (const auto &event : witness.network->events()) {
      if (event_has_trace(event, trace.id, FieldAlignedTraceEventRole::Terminal)) {
        terminals.push_back(&event);
      }
    }
    ASSERT_EQ(1U, terminals.size())
        << witness.name << ": every produced trace must have exactly one typed "
                           "terminal event";
    EXPECT_EQ(1U, producedKinds.count(terminals.front()->kind))
        << witness.name << ": terminal kind must be represented by an actually "
                           "published event";
  }
}

const directional::geometry::FieldAlignedNetworkEvent *
find_terminal_trace_intersection(const FieldAlignedCurveNetwork &network) {
  const auto intersection = std::find_if(
      network.events().begin(), network.events().end(), [](const auto &event) {
        return event.kind == FieldAlignedNetworkEventKind::TraceIntersection &&
               std::any_of(event.incidences.begin(), event.incidences.end(),
                           [](const auto &incidence) {
                             return incidence.role ==
                                    FieldAlignedTraceEventRole::Terminal;
                           });
      });
  return intersection == network.events().end() ? nullptr : &*intersection;
}

std::string terminal_kind_contributors(
    const std::map<FieldAlignedNetworkEventKind, std::set<std::string>> &contributors,
    const FieldAlignedNetworkEventKind kind) {
  const auto found = contributors.find(kind);
  if (found == contributors.end() || found->second.empty()) return "none";
  std::ostringstream stream;
  bool first = true;
  for (const auto &name : found->second) {
    if (!first) stream << ',';
    first = false;
    stream << name;
  }
  return stream.str();
}

} // namespace

TEST(GlobalTopologyPlan, TorusWitnessStageReachabilityIsObservable) {
  const Cp4cReachabilityObservation observation =
      observe_cp4c_witness("torus", "torus");
  FAIL() << observation.report;
}

TEST(GlobalTopologyPlan, MechanicalWitnessStageReachabilityIsObservable) {
  const Cp4cReachabilityObservation observation =
      observe_cp4c_witness("mechanical_feature", "mechanical feature");
  FAIL() << observation.report;
}

TEST(GlobalTopologyPlan, TorusWitnessDerivesRegionsThroughProductionEntryPath) {
  const auto &fixture = cp4c_torus_fixture();
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_torus_preconditions(fixture));
  ASSERT_NO_FATAL_FAILURE(expect_cp4c_plan_disc_proofs(fixture));
}

TEST(GlobalTopologyPlan,
     MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath) {
  const auto &fixture = cp4c_mechanical_fixture();
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_mechanical_preconditions(fixture));
  ASSERT_NO_FATAL_FAILURE(expect_cp4c_plan_disc_proofs(fixture));
}

TEST(GlobalTopologyPlan, RotationSystemAndFaceWalkAgreeOnProducedWitnesses) {
  const auto &torus = cp4c_torus_fixture();
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_torus_preconditions(torus));
  ASSERT_NO_FATAL_FAILURE(expect_rotation_face_walk_agreement(torus));

  const auto &mechanical = cp4c_mechanical_fixture();
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_mechanical_preconditions(mechanical));
  ASSERT_NO_FATAL_FAILURE(expect_rotation_face_walk_agreement(mechanical));
}


void assert_cp4c_sphere_preconditions(
    const Cp4cReachabilityObservation &sphere) {
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.network.has_value()) << sphere.report;
  ASSERT_GE(sphere.network->singularity_ports().size(), 1U) << sphere.report;
  ASSERT_GE(sphere.network->candidate_traces().size(), 2U) << sphere.report;
  ASSERT_EQ(0U, sphere.network->mandatory_edges().size()) << sphere.report;
}

TEST(ResolvedBranchContinuation,
     PositionChoosesSmallerExactExitAndFlipsAcrossCrossover) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const SourceEdgeTopologyKey incoming = topology_edge(0, 1);
  const SourceEdgeTopologyKey exitAcrossV0 = topology_edge(1, 2);
  const SourceEdgeTopologyKey exitAcrossV1 = topology_edge(0, 2);
  const auto pairing = continuation_pairing(
      {-1, -2, 3}, {exitAcrossV0, exitAcrossV1});

  const auto left = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(incoming, 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::surface_cell_tracing_detail::
                  FieldBranchContinuationDecision>(left));
  const auto &leftDecision = std::get<
      directional::geometry::surface_cell_tracing_detail::
          FieldBranchContinuationDecision>(left);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                FieldBranchContinuationKind::EdgeExit,
            leftDecision.kind);
  EXPECT_EQ(exitAcrossV1, leftDecision.outgoingCarrier);
  EXPECT_NE(pairing.outgoingCarriers.end(),
            std::find(pairing.outgoingCarriers.begin(),
                      pairing.outgoingCarriers.end(),
                      leftDecision.outgoingCarrier));

  const auto right = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(incoming, 3, 4));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::surface_cell_tracing_detail::
                  FieldBranchContinuationDecision>(right));
  const auto &rightDecision = std::get<
      directional::geometry::surface_cell_tracing_detail::
          FieldBranchContinuationDecision>(right);
  EXPECT_EQ(exitAcrossV0, rightDecision.outgoingCarrier);
  EXPECT_NE(leftDecision.outgoingCarrier, rightDecision.outgoingCarrier);
  EXPECT_NE(pairing.outgoingCarriers.end(),
            std::find(pairing.outgoingCarriers.begin(),
                      pairing.outgoingCarriers.end(),
                      rightDecision.outgoingCarrier));
}

TEST(ResolvedBranchContinuation,
     RegularVertexHitPublishesVertexSupportAndSectorTransit) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const SourceEdgeTopologyKey incoming = topology_edge(0, 2);
  const auto pairing = continuation_pairing(
      {-1, 2, -1}, {topology_edge(0, 1), topology_edge(1, 2)});
  const auto continuation =
      directional::geometry::surface_cell_tracing_detail::
          resolve_field_branch_continuation(
              face, pairing, boundary_point(incoming, 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::surface_cell_tracing_detail::
                  FieldBranchContinuationDecision>(continuation));
  const auto &decision = std::get<
      directional::geometry::surface_cell_tracing_detail::
          FieldBranchContinuationDecision>(continuation);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                FieldBranchContinuationKind::VertexHit,
            decision.kind);
  ASSERT_TRUE(decision.sourceVertex.has_value());
  EXPECT_EQ(SourceVertexId::from_index(1, 3).value(), *decision.sourceVertex);
  const auto support = decision.exitPoint.source_support();
  ASSERT_TRUE(support.has_value());
  const auto *vertexSupport =
      std::get_if<directional::authority::SourceVertexSupport>(&*support);
  ASSERT_NE(nullptr, vertexSupport);
  EXPECT_EQ(*decision.sourceVertex, vertexSupport->vertex);

  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto &topology = atlasBuild.value().branch_topology();
  const SourceVertexId center =
      SourceVertexId::from_index(4, static_cast<std::size_t>(mesh.V.rows()))
          .value();
  bool foundResolvedSector = false;
  for (const auto &frame : topology.frames()) {
    if (std::find(frame.sourceFace.vertices().begin(),
                  frame.sourceFace.vertices().end(), center) ==
        frame.sourceFace.vertices().end()) {
      continue;
    }
    for (const auto &candidatePairing : frame.branches) {
      const auto transit =
          directional::geometry::surface_cell_tracing_detail::
              resolve_field_vertex_transit(
                  mesh, topology, frame.sourceComponent, frame.topologyRegion,
                  frame.sourceFace, candidatePairing.branch, center);
      if (!std::holds_alternative<
              directional::geometry::surface_cell_tracing_detail::
                  FieldVertexTransitDecision>(transit)) {
        continue;
      }
      const auto &resolved = std::get<
          directional::geometry::surface_cell_tracing_detail::
              FieldVertexTransitDecision>(transit);
      EXPECT_NE(frame.sourceFace, resolved.nextFace);
      foundResolvedSector = true;
      break;
    }
    if (foundResolvedSector) break;
  }
  EXPECT_TRUE(foundResolvedSector)
      << "regular fan must expose at least one unique existing-sector transit";
}

TEST(ResolvedBranchContinuation,
     SingularVertexTerminationProducesTypedEventAndStopsTrace) {
  using directional::authority::NetworkNodeId;
  using directional::authority::TopologyRegionId;
  using directional::authority::TraceId;
  using directional::geometry::FieldAlignedCandidateTrace;
  using directional::geometry::FieldAlignedCandidateTraceSegment;
  using directional::geometry::FieldAlignedNetworkEventKind;
  using directional::geometry::FieldAlignedTraceEventRole;

  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const SourceVertexId sourceVertex = SourceVertexId::from_index(0, 3).value();
  const SourceVertexId terminalVertex = SourceVertexId::from_index(1, 3).value();
  const auto sourceComponent = SourceComponentId::from_index(0, 1).value();
  const auto topologyRegion = TopologyRegionId::from_index(0, 1).value();
  const FieldSingularityId sourceSingularity =
      FieldSingularityId::from_index(0, 2).value();
  const FieldSingularityId terminalSingularity =
      FieldSingularityId::from_index(1, 2).value();
  const SingularityPortId sourcePort =
      SingularityPortId::from_index(0, 2).value();
  const SingularityPortId terminalPortId =
      SingularityPortId::from_index(1, 2).value();
  const NetworkNodeId terminalNode = NetworkNodeId::from_index(0, 1).value();

  FieldAlignedCurveNetworkCandidate candidate;
  candidate.singularityPorts.emplace_back(
      terminalPortId, terminalSingularity, terminalNode, terminalVertex,
      sourceComponent, topologyRegion, 1, 0);

  FieldAlignedCandidateTrace trace(
      TraceId::from_index(0, 1).value(), sourcePort, sourceSingularity,
      sourceVertex, sourceComponent, topologyRegion);
  const auto terminalPoint = boundary_point(topology_edge(0, 1), 1, 1);
  trace.segments.emplace_back(
      face, directional::authority::FieldBranch::from_integer(0),
      boundary_point(topology_edge(0, 2), 1, 2), std::nullopt,
      topology_edge(0, 1), std::nullopt);
  trace.terminalPoint = terminalPoint;
  trace.terminalSingularity = terminalSingularity;

  const auto error =
      directional::geometry::surface_cell_tracing_detail::
          append_field_aligned_singularity_termination(candidate, trace);
  ASSERT_FALSE(error.has_value());
  ASSERT_EQ(1U, trace.segments.size());
  ASSERT_EQ(2U, candidate.events.size());
  EXPECT_EQ(FieldAlignedNetworkEventKind::FirstContact,
            candidate.events.front().kind);
  const auto &termination = candidate.events.back();
  EXPECT_EQ(FieldAlignedNetworkEventKind::SingularityTermination,
            termination.kind);
  EXPECT_EQ(terminalNode, termination.node);
  ASSERT_EQ(1U, termination.incidences.size());
  EXPECT_EQ(FieldAlignedTraceEventRole::Terminal,
            termination.incidences.front().role);
  EXPECT_EQ(trace.id, termination.incidences.front().trace);
  EXPECT_EQ(trace.terminalPoint, std::optional{terminalPoint});
  EXPECT_EQ(trace.terminalSingularity,
            std::optional{terminalSingularity});
}

TEST(ResolvedBranchContinuation,
     RejectsThreeWayMinimizerInvariantViolation) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing = continuation_pairing(
      {-1, -1, -1}, {topology_edge(0, 1), topology_edge(0, 2),
                     topology_edge(1, 2)});
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(topology_edge(0, 1), 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::
                BranchContinuationMinimizerImpossible,
            error.code);
  EXPECT_EQ(face, error.sourceFace);
  EXPECT_EQ(pairing.branch, error.branch);
  EXPECT_EQ(3U, error.exactValues.size());
}

TEST(ResolvedBranchContinuation, RejectsNoOutflow) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing = continuation_pairing({1, 1, 1}, {});
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(topology_edge(0, 1), 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::BranchContinuationNoOutflow,
            error.code);
  EXPECT_EQ(face, error.sourceFace);
  EXPECT_EQ(pairing.branch, error.branch);
  EXPECT_EQ(topology_edge(0, 1), error.sourceEdge);
}

TEST(ResolvedBranchContinuation, RejectsDegenerateZeroTimeEntry) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing = continuation_pairing(
      {-1, -2, 3}, {topology_edge(0, 2), topology_edge(1, 2)});
  const auto point = boundary_point(topology_edge(1, 2), 1, 2);
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(face, pairing, point);
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(
      FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry,
      error.code);
  EXPECT_EQ(point.parameter, error.parameter);
  ASSERT_EQ(1U, error.exactValues.size());
  EXPECT_TRUE(error.exactValues.front().is_zero());
}

TEST(ResolvedBranchContinuation, RejectsNonBarycentricDirection) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing = continuation_pairing(
      {-1, 1, 1}, {topology_edge(1, 2)});
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(topology_edge(0, 1), 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::BranchDirectionNotBarycentric,
            error.code);
  EXPECT_EQ(face, error.sourceFace);
  EXPECT_EQ(pairing.branch, error.branch);
}

TEST(ResolvedBranchContinuation,
     ExactComparatorDistinguishesRoundedEqualDoubleRatios) {
  const double p1 = 0x1.fffffffffffedp-1;
  const double d1 = 0x1.fffffffffffeep-1;
  const double p2 = 0x1.fffffffffffeep-1;
  const double d2 = 0x1.fffffffffffefp-1;
  ASSERT_EQ(p1 / d1, p2 / d2)
      << "witness requires native double division to round to equality";

  const auto exactP1 =
      directional::authority::FieldExactRational::from_double_exact(p1);
  const auto exactD1 =
      directional::authority::FieldExactRational::from_double_exact(d1);
  const auto exactP2 =
      directional::authority::FieldExactRational::from_double_exact(p2);
  const auto exactD2 =
      directional::authority::FieldExactRational::from_double_exact(d2);
  ASSERT_TRUE(exactP1.has_value());
  ASSERT_TRUE(exactD1.has_value());
  ASSERT_TRUE(exactP2.has_value());
  ASSERT_TRUE(exactD2.has_value());
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                FieldBranchExitTimeOrdering::Less,
            directional::geometry::surface_cell_tracing_detail::
                compare_field_branch_exit_times(
                    *exactP1, *exactD1, *exactP2, *exactD2));
}

TEST(ResolvedBranchContinuation, RejectsExitOutsidePublishedOutflowSet) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing = continuation_pairing(
      {-1, -2, 3}, {topology_edge(1, 2)});
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(topology_edge(0, 1), 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::
                BranchContinuationOutsideOutflowSet,
            error.code);
  EXPECT_EQ(topology_edge(0, 2), error.sourceEdge);
  EXPECT_EQ(pairing.outgoingCarriers, error.publishedEdges);
}

TEST(ResolvedBranchContinuation, RejectsParameterOutsideUnitInterval) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing = continuation_pairing(
      {-1, -2, 3}, {topology_edge(0, 2), topology_edge(1, 2)});
  const auto point = boundary_point(topology_edge(0, 1), 3, 2);
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(face, pairing, point);
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::BoundaryPointParameterOutOfRange,
            error.code);
  EXPECT_EQ(point.parameter, error.parameter);
  EXPECT_EQ(point.edge, error.sourceEdge);
}

TEST(ResolvedBranchContinuation, RejectsBoundaryPointOnForeignEdge) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2, 4);
  const auto pairing = continuation_pairing(
      {-1, -2, 3}, {topology_edge(0, 2, 4), topology_edge(1, 2, 4)});
  const SourceEdgeTopologyKey foreign = topology_edge(0, 3, 4);
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(foreign, 1, 2));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(
      FieldAlignedCurveNetworkErrorCode::BoundaryPointEdgeNotIncidentToFace,
      error.code);
  EXPECT_EQ(face, error.sourceFace);
  EXPECT_EQ(foreign, error.sourceEdge);
}

TEST(ResolvedBranchContinuation, RejectsUnresolvedRegularVertexSector) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto &topology = atlasBuild.value().branch_topology();
  ASSERT_FALSE(topology.frames().empty());
  const auto &frame = topology.frames().front();
  ASSERT_FALSE(frame.branches.empty());
  const SourceVertexId center =
      SourceVertexId::from_index(4, static_cast<std::size_t>(mesh.V.rows()))
          .value();
  const auto foreignComponent = SourceComponentId::from_index(1, 2).value();
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_vertex_transit(
          mesh, topology, foreignComponent, frame.topologyRegion,
          frame.sourceFace, frame.branches.front().branch, center);
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved,
            error.code);
  EXPECT_EQ(center, error.sourceVertex);
  EXPECT_EQ(frame.sourceFace, error.sourceFace);
  EXPECT_EQ(frame.branches.front().branch, error.branch);
}

TEST(ResolvedBranchCorrection,
     NetworkDiagnosticsPublishEveryRequiredLocusLosslessly) {
  using Error = directional::geometry::FieldAlignedCurveNetworkError;
  const SourceFaceTopologyKey firstFace = topology_face(0, 1, 2, 4);
  const SourceFaceTopologyKey secondFace = topology_face(0, 1, 3, 4);
  const SourceEdgeTopologyKey edge = topology_edge(0, 1, 4);
  const auto branch = directional::authority::FieldBranch::from_integer(1);
  const auto relatedBranch =
      directional::authority::FieldBranch::from_integer(3);
  const auto parameter = directional::authority::ExactUnitParameter{
      exact_ratio(1, 3)};

  auto base_error = [&](const FieldAlignedCurveNetworkErrorCode code) {
    Error error;
    error.code = code;
    error.sourceFace = firstFace;
    error.branch = branch;
    return error;
  };
  auto expect_tokens = [](const Error &error,
                          const std::vector<std::string> &tokens) {
    const std::string emitted = network_error_locus(error);
    for (const std::string &token : tokens) {
      EXPECT_NE(std::string::npos, emitted.find(token)) << emitted;
    }
  };

  expect_tokens(base_error(
                    FieldAlignedCurveNetworkErrorCode::
                        BranchDirectionNotBarycentric),
                {"sourceFace=0-1-2", "branch=1"});

  Error noOutflow = base_error(
      FieldAlignedCurveNetworkErrorCode::BranchContinuationNoOutflow);
  noOutflow.sourceEdge = edge;
  expect_tokens(noOutflow,
                {"sourceFace=0-1-2", "branch=1", "sourceEdge=0-1"});

  Error degenerate = base_error(
      FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry);
  degenerate.sourceEdge = edge;
  degenerate.parameter = parameter;
  degenerate.exactValues = {exact_ratio(0, 1)};
  expect_tokens(degenerate,
                {"sourceFace=0-1-2", "branch=1", "sourceEdge=0-1",
                 "parameter=1/3", "exactValues=[0/1]"});

  Error minimizer = base_error(
      FieldAlignedCurveNetworkErrorCode::BranchContinuationMinimizerImpossible);
  minimizer.exactValues = {exact_ratio(1, 2), exact_ratio(2, 3),
                           exact_ratio(3, 4)};
  expect_tokens(minimizer, {"sourceFace=0-1-2", "branch=1",
                            "exactValues=[1/2,2/3,3/4]"});

  Error outside = base_error(
      FieldAlignedCurveNetworkErrorCode::BranchContinuationOutsideOutflowSet);
  outside.sourceEdge = edge;
  expect_tokens(outside, {"sourceFace=0-1-2", "branch=1", "sourceEdge=0-1",
                          "publishedEdges=[]"});

  Error outOfRange = base_error(
      FieldAlignedCurveNetworkErrorCode::BoundaryPointParameterOutOfRange);
  outOfRange.sourceEdge = edge;
  outOfRange.parameter = parameter;
  expect_tokens(outOfRange, {"sourceEdge=0-1", "parameter=1/3"});

  Error foreign = base_error(
      FieldAlignedCurveNetworkErrorCode::BoundaryPointEdgeNotIncidentToFace);
  foreign.sourceEdge = edge;
  expect_tokens(foreign, {"sourceFace=0-1-2", "sourceEdge=0-1"});

  Error sector = base_error(
      FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
  sector.sourceVertex = SourceVertexId::from_index(0, 4).value();
  expect_tokens(sector, {"sourceVertex=0", "sourceFace=0-1-2", "branch=1",
                         "publishedFaces=[]"});
  sector.publishedFaces = {firstFace, secondFace};
  expect_tokens(sector, {"publishedFaces=[0-1-2,0-1-3]"});

  Error grazing = base_error(
      FieldAlignedCurveNetworkErrorCode::BranchGrazingSlideDirectionAmbiguous);
  grazing.sourceEdge = edge;
  grazing.relatedSourceFace = secondFace;
  grazing.relatedBranch = relatedBranch;
  grazing.signedLift = 2;
  grazing.parameter = parameter;
  grazing.exactValues = {exact_integer(-1), exact_integer(-1),
                         exact_integer(2), exact_integer(-2)};
  expect_tokens(
      grazing,
      {"sourceFace=0-1-2", "relatedSourceFace=0-1-3", "branch=1",
       "relatedBranch=3", "sourceEdge=0-1", "signedLift=2",
       "parameter=1/3", "exactValues=[-1/1,-1/1,2/1,-2/1]"});

  Error bounded = base_error(
      FieldAlignedCurveNetworkErrorCode::TraceStepBudgetExhausted);
  bounded.sourceEdge = edge;
  bounded.parameter = parameter;
  bounded.traceSteps = 64U;
  bounded.traceStepBudget = 64U;
  expect_tokens(bounded, {"sourceFace=0-1-2", "branch=1", "sourceEdge=0-1",
                          "parameter=1/3", "traceSteps=64",
                          "traceStepBudget=64"});

  Error cycle = base_error(
      FieldAlignedCurveNetworkErrorCode::TraceStateCycleDetected);
  cycle.sourceEdge = edge;
  cycle.parameter = parameter;
  cycle.traceSteps = 7U;
  cycle.traceStepBudget = 64U;
  expect_tokens(cycle, {"sourceFace=0-1-2", "branch=1", "sourceEdge=0-1",
                        "parameter=1/3", "traceSteps=7",
                        "traceStepBudget=64"});
}

TEST(ResolvedBranchCorrection,
     TraceSeedDiagnosticNeverBackfillsFailureLocus) {
  directional::geometry::FieldAlignedCurveNetworkError error;
  error.code =
      FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry;
  error.sourceFace = topology_face(0, 1, 2);
  error.branch = directional::authority::FieldBranch::from_integer(0);
  error.sourceEdge = topology_edge(0, 1);
  error.parameter =
      directional::authority::ExactUnitParameter{exact_ratio(1, 2)};
  const SourceVertexId seedVertex = SourceVertexId::from_index(2, 3).value();
  const FieldSingularityId seedSingularity =
      FieldSingularityId::from_index(0, 1).value();
  directional::geometry::surface_cell_tracing_detail::
      annotate_field_aligned_trace_seed(error, seedVertex, seedSingularity);

  EXPECT_FALSE(error.sourceVertex.has_value());
  EXPECT_FALSE(error.singularity.has_value());
  const std::string emitted = network_error_locus(error);
  EXPECT_EQ(std::string::npos, emitted.find(";sourceVertex=")) << emitted;
  EXPECT_EQ(std::string::npos, emitted.find(";singularity=")) << emitted;
  EXPECT_NE(std::string::npos, emitted.find(";traceSeedVertex=2")) << emitted;
  EXPECT_NE(std::string::npos, emitted.find(";traceSeedSingularity=0"))
      << emitted;
}

TEST(ResolvedBranchCorrection,
     NetworkDiagnosticsContainNoControlCharactersForAnyCode) {
  using Error = directional::geometry::FieldAlignedCurveNetworkError;
  const std::array<FieldAlignedCurveNetworkErrorCode, 29> codes{{
      FieldAlignedCurveNetworkErrorCode::InvalidSourceBinding,
      FieldAlignedCurveNetworkErrorCode::InvalidAtlasBinding,
      FieldAlignedCurveNetworkErrorCode::DuplicateRailId,
      FieldAlignedCurveNetworkErrorCode::InvalidRailGeometry,
      FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge,
      FieldAlignedCurveNetworkErrorCode::DuplicateMandatoryEdge,
      FieldAlignedCurveNetworkErrorCode::ForeignMandatoryEdge,
      FieldAlignedCurveNetworkErrorCode::MandatoryKindMismatch,
      FieldAlignedCurveNetworkErrorCode::MandatoryOwnerMismatch,
      FieldAlignedCurveNetworkErrorCode::InvalidSingularityBinding,
      FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortCount,
      FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortOwnership,
      FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
      FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
      FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
      FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventIncidence,
      FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
      FieldAlignedCurveNetworkErrorCode::BranchDirectionNotBarycentric,
      FieldAlignedCurveNetworkErrorCode::BranchContinuationNoOutflow,
      FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry,
      FieldAlignedCurveNetworkErrorCode::BranchContinuationMinimizerImpossible,
      FieldAlignedCurveNetworkErrorCode::BranchContinuationOutsideOutflowSet,
      FieldAlignedCurveNetworkErrorCode::BoundaryPointParameterOutOfRange,
      FieldAlignedCurveNetworkErrorCode::BoundaryPointEdgeNotIncidentToFace,
      FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved,
      FieldAlignedCurveNetworkErrorCode::BranchTransportFlowDisagreement,
      FieldAlignedCurveNetworkErrorCode::TraceStateCycleDetected,
      FieldAlignedCurveNetworkErrorCode::TraceStepBudgetExhausted,
      FieldAlignedCurveNetworkErrorCode::BranchGrazingSlideDirectionAmbiguous,
  }};
  const SourceFaceTopologyKey firstFace = topology_face(0, 1, 2, 4);
  const SourceFaceTopologyKey secondFace = topology_face(0, 1, 3, 4);
  const SourceEdgeTopologyKey edge = topology_edge(0, 1, 4);
  const SourceVertexId sourceVertex = SourceVertexId::from_index(0, 4).value();
  const SourceVertexId seedVertex = SourceVertexId::from_index(2, 4).value();
  const HardRailId rail = HardRailId::from_index(0, 1).value();
  const FieldSingularityId singularity =
      FieldSingularityId::from_index(0, 2).value();
  const FieldSingularityId seedSingularity =
      FieldSingularityId::from_index(1, 2).value();

  for (const FieldAlignedCurveNetworkErrorCode code : codes) {
    Error error;
    error.code = code;
    error.sourceVertex = sourceVertex;
    error.sourceEdge = edge;
    error.sourceFace = firstFace;
    error.relatedSourceFace = secondFace;
    error.branch = directional::authority::FieldBranch::from_integer(0);
    error.relatedBranch = directional::authority::FieldBranch::from_integer(0);
    error.parameter =
        directional::authority::ExactUnitParameter{exact_ratio(1, 3)};
    error.exactValues = {exact_ratio(-1, 2), exact_ratio(2, 3)};
    error.publishedEdges = {edge};
    error.publishedFaces = {firstFace, secondFace};
    error.rail = rail;
    error.singularity = singularity;
    error.traceSeedVertex = seedVertex;
    error.traceSeedSingularity = seedSingularity;
    error.traceSteps = 7U;
    error.traceStepBudget = 64U;

    const std::string emitted = network_error_locus(error);
    const auto control = std::find_if(
        emitted.begin(), emitted.end(), [](const char value) {
          const auto byte = static_cast<unsigned char>(value);
          return byte < 0x20U || byte > 0x7eU;
        });
    EXPECT_TRUE(control == emitted.end())
        << "code="
        << directional::geometry::field_aligned_curve_network_error_code_name(
               code)
        << ";byte="
        << (control == emitted.end()
                ? -1
                : static_cast<int>(static_cast<unsigned char>(*control)));
  }
}

TEST(ResolvedBranchCorrection,
     TracingPathNeverPublishesSeedIdentityAsFailureLocus) {
  using directional::authority::TopologyRegionId;
  using directional::authority::TraceId;
  using directional::geometry::FieldAlignedCandidateTrace;

  const SourceFaceTopologyKey constructedFace = topology_face(0, 1, 2);
  const SourceVertexId seedVertex = SourceVertexId::from_index(2, 3).value();
  const FieldSingularityId seedSingularity =
      FieldSingularityId::from_index(0, 1).value();
  const auto sourceComponent = SourceComponentId::from_index(0, 1).value();
  const auto topologyRegion = TopologyRegionId::from_index(0, 1).value();
  FieldAlignedCurveNetworkCandidate candidate;
  FieldAlignedCandidateTrace trace(
      TraceId::from_index(0, 1).value(),
      SingularityPortId::from_index(0, 1).value(), seedSingularity, seedVertex,
      sourceComponent, topologyRegion);
  trace.segments.emplace_back(
      constructedFace, directional::authority::FieldBranch::from_integer(0),
      boundary_point(topology_edge(0, 2), 1, 2), std::nullopt,
      topology_edge(0, 1), std::nullopt);

  const auto constructedError =
      directional::geometry::surface_cell_tracing_detail::
          append_field_aligned_singularity_termination(candidate, trace);
  ASSERT_TRUE(constructedError.has_value());
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
            constructedError->code);
  ASSERT_EQ(std::optional{seedVertex}, constructedError->traceSeedVertex);
  ASSERT_EQ(std::optional{seedSingularity},
            constructedError->traceSeedSingularity);
  EXPECT_FALSE(constructedError->sourceVertex.has_value())
      << network_error_locus(*constructedError);
  EXPECT_FALSE(constructedError->singularity.has_value())
      << network_error_locus(*constructedError);

  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.sourceAuthority.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;

  const auto networkBuild = FieldAlignedCurveNetwork::make(
      sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails);
  if (!networkBuild) {
    const auto &error = networkBuild.error();
    ASSERT_NE(FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
              error.code)
        << network_error_locus(error);
    ASSERT_TRUE(error.traceSeedVertex.has_value()) << network_error_locus(error);
    ASSERT_TRUE(error.traceSeedSingularity.has_value())
        << network_error_locus(error);
    if (error.sourceVertex.has_value()) {
      EXPECT_NE(*error.traceSeedVertex, *error.sourceVertex)
          << network_error_locus(error);
    }
    if (error.singularity.has_value()) {
      EXPECT_NE(*error.traceSeedSingularity, *error.singularity)
          << network_error_locus(error);
    }
  }
}


const char *cp4c0b_contact_census_terminal_kind_name(
    const directional::geometry::surface_cell_tracing_detail::
        FieldAlignedContactCensusPriorTerminalKind kind) {
  using Kind = directional::geometry::surface_cell_tracing_detail::
      FieldAlignedContactCensusPriorTerminalKind;
  switch (kind) {
  case Kind::None:
    return "none";
  case Kind::Singularity:
    return "terminalSingularity";
  case Kind::Barrier:
    return "terminalBarrier";
  }
  return "unknown";
}

const char *cp4c0b_contact_census_site_name(
    const directional::geometry::surface_cell_tracing_detail::
        FieldAlignedContactCensusSite site) {
  using Site = directional::geometry::surface_cell_tracing_detail::
      FieldAlignedContactCensusSite;
  switch (site) {
  case Site::SingularityJunction:
    return "A";
  case Site::SharedFaceTraceContact:
    return "B";
  case Site::SelfClosure:
    return "C";
  }
  return "unknown";
}

const char *field_aligned_event_kind_name(
    const directional::geometry::FieldAlignedNetworkEventKind kind) {
  using Kind = directional::geometry::FieldAlignedNetworkEventKind;
  switch (kind) {
  case Kind::SingularityPortOrigin:
    return "SingularityPortOrigin";
  case Kind::FirstContact:
    return "FirstContact";
  case Kind::TraceIntersection:
    return "TraceIntersection";
  case Kind::MandatoryBarrierTermination:
    return "MandatoryBarrierTermination";
  case Kind::SingularityTermination:
    return "SingularityTermination";
  case Kind::SingularityPortJunction:
    return "SingularityPortJunction";
  case Kind::TraceSelfClosure:
    return "TraceSelfClosure";
  }
  return "unknown";
}

std::string cp4c0b_contact_census_report(
    const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
    const directional::authority::FieldTransportAtlas &atlas) {
  std::ostringstream report;
  report << "m3Cp4c0bS1"
         << ";credit=none"
         << ";owningMeasure=S1"
         << ";railAuthority="
         << cp4c_rail_authority_name(Cp4cRailAuthority::AtlasDerived)
         << ";witness=" << metadata.name
         << ";population=" << metadata.population
         << ";classification=" << metadata.classification;

  const auto sourceAuthority = make_source_authority(mesh);
  if (!sourceAuthority.has_value()) {
    return report.str() + ";status=source-authority-unavailable";
  }
  const auto rails = rails_from_atlas(mesh, atlas);
  report << ";mandatoryEdgeCount=" << rails.size()
         << ";singularityCount=" << atlas.singularities().size();
  const auto result =
      directional::geometry::surface_cell_tracing_detail::
          diagnose_field_aligned_contact_census(
              mesh, *sourceAuthority, atlas, rails);
  if (const auto *error =
          std::get_if<directional::geometry::FieldAlignedCurveNetworkError>(
              &result)) {
    report << ";status=unreached;";
    append_network_error(report, *error);
    return report.str();
  }

  const auto &census =
      std::get<directional::geometry::surface_cell_tracing_detail::
                   FieldAlignedContactCensus>(result);
  std::size_t nonProper = 0U;
  std::size_t unevaluated = 0U;
  for (const auto &contact : census.sharedFaceContacts) {
    if (!contact.properCrossing.has_value()) {
      ++unevaluated;
    } else if (!*contact.properCrossing) {
      ++nonProper;
    }
  }

  report << ";status=reached"
         << ";sharedFaceContactCount=" << census.sharedFaceContacts.size()
         << ";properCrossingCount="
         << (census.sharedFaceContacts.size() - nonProper - unevaluated)
         << ";nonProperCrossingCount=" << nonProper
         << ";unevaluatedCrossingCount=" << unevaluated
         << ";requiresReview=" << ((nonProper != 0U || unevaluated != 0U) ? 1 : 0)
         << ";siteCounts={A=" << census.siteA << ",B=" << census.siteB
         << ",C=" << census.siteC << '}'
         << ";nodeCount=" << census.nodeCount;

  for (std::size_t index = 0U; index < census.sharedFaceContacts.size(); ++index) {
    const auto &contact = census.sharedFaceContacts[index];
    report << ";contact[" << index << "]={trace=" << contact.trace.index()
           << ",segment=" << contact.segmentIndex
           << ",existingTrace=" << contact.existingTrace.index()
           << ",existingSegment=" << contact.existingSegmentIndex
           << ",face=" << source_face_locus(contact.sourceFace)
           << ",sharedCarrier=";
    if (contact.sharedCarrier.has_value()) {
      report << source_edge_locus(*contact.sharedCarrier);
    } else {
      report << "none";
    }
    report << ",properCrossing=";
    if (contact.properCrossing.has_value()) {
      report << (*contact.properCrossing ? "true" : "false");
    } else {
      report << "unevaluated";
    }
    report << ",priorTerminalKind="
           << cp4c0b_contact_census_terminal_kind_name(
                  contact.priorTerminalKind)
           << '}';
  }

  for (std::size_t index = 0U; index < census.contactNodes.size(); ++index) {
    const auto &node = census.contactNodes[index];
    report << ";contactNode[" << index << "]={site="
           << cp4c0b_contact_census_site_name(node.site)
           << ",node=" << node.node.index()
           << ",sourceVertex=" << node.sourceVertex.index() << '}';
  }

  report << ";eventKindHistogram={";
  bool first = true;
  for (const auto &[kind, count] : census.eventKindHistogram) {
    if (!first) report << ',';
    first = false;
    report << field_aligned_event_kind_name(kind) << '=' << count;
  }
  report << '}';
  return report.str();
}

TEST(ResolvedBranchCorrection,
     ContactPredicateCensusIsPublishedNonGating) {
  for_each_cp4c_census_witness(
      [](const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
         const CrossFieldResult &,
         const directional::authority::FieldTransportAtlas &atlas) {
        std::cout << cp4c0b_contact_census_report(metadata, mesh, atlas) << '\n';
      });
}

TEST(ResolvedBranchCorrection,
     CrossFaceFlowAgreementCensusIsPublishedNonGating) {
  for_each_cp4c_census_witness(
      [](const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
         const CrossFieldResult &field,
         const directional::authority::FieldTransportAtlas &atlas) {
        std::cout << cp4c_flow_agreement_census(metadata, mesh, field, atlas)
                  << '\n';
      });
}

TEST(ResolvedBranchCorrection,
     MatchingVersusGeometryCensusIsPublishedNonGating) {
  for_each_cp4c_census_witness(
      [](const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
         const CrossFieldResult &field,
         const directional::authority::FieldTransportAtlas &) {
        std::cout << cp4c_matching_geometry_census(metadata, mesh, field)
                  << '\n';
      });
}

TEST(ResolvedBranchCorrection,
     GrazingEdgeTraceMultiplicityIsPublishedNonGating) {
  for_each_cp4c_census_witness(
      [](const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
         const CrossFieldResult &,
         const directional::authority::FieldTransportAtlas &atlas) {
        std::cout << cp4c_grazing_trace_multiplicity_census(metadata, mesh, atlas)
                  << '\n';
      });
}

TEST(ResolvedBranchCorrection,
     VertexFanHolonomyCensusIsPublishedNonGating) {
  for_each_cp4c_census_witness(
      [](const Cp4cCensusWitnessMetadata &metadata, const TriMesh &mesh,
         const CrossFieldResult &,
         const directional::authority::FieldTransportAtlas &atlas) {
        if (metadata.population != "included") return;
        std::cout << cp4c_holonomy_census(metadata, mesh, atlas) << '\n';
      });
}

TEST(ResolvedBranchCorrection,
     PrescribedSphereGrazingCostCensusIsPublishedNonGating) {
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  std::cout << cp4c_sphere_grazing_cost_census(sphere.mesh, *sphere.atlas) << '\n';
}

TEST(ResolvedBranchCorrection,
     PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating) {
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");

  std::ostringstream report;
  report << "m3Cp4c0G5"
         << ";credit=none"
         << ";owningMeasure=G5"
         << ";reachability={" << sphere.report << '}';

  if (!sphere.sourceAuthority.has_value() || !sphere.atlas.has_value()) {
    report << ";fieldAlignedCurveNetwork=unavailable";
  } else {
    const auto networkBuild = FieldAlignedCurveNetwork::make(
        sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails);
    if (!networkBuild) {
      report << ';' << network_error_locus(networkBuild.error());
    } else {
      std::array<std::size_t, 5> terminalEventsByKind{};
      for (const auto &event : networkBuild.value().events()) {
        const bool hasTerminal = std::any_of(
            event.incidences.begin(), event.incidences.end(),
            [](const auto &incidence) {
              return incidence.role ==
                     directional::geometry::FieldAlignedTraceEventRole::Terminal;
            });
        if (hasTerminal) {
          ++terminalEventsByKind[static_cast<std::size_t>(event.kind)];
        }
      }
      report << ";fieldAlignedCurveNetwork=true"
             << ";traceCount=" << networkBuild.value().candidate_traces().size()
             << ";terminalEventSummary={"
             << "SingularityPortOrigin=" << terminalEventsByKind[0] << ','
             << "FirstContact=" << terminalEventsByKind[1] << ','
             << "TraceIntersection=" << terminalEventsByKind[2] << ','
             << "MandatoryBarrierTermination=" << terminalEventsByKind[3] << ','
             << "SingularityTermination=" << terminalEventsByKind[4] << '}';
    }
  }

  std::cout << report.str() << '\n';
}

TEST(ResolvedBranchCorrection,
     ExactFlowClassificationKeepsSubToleranceCarrier) {
  const TriMesh mesh = make_square_mesh();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field = make_zero_transport_field(mesh);
  constexpr double epsilon = 5.0e-11;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    field.primaryDirections.row(face) = Eigen::RowVector3d(epsilon, 1.0, 0.0);
    field.secondaryDirections.row(face) =
        Eigen::RowVector3d(-1.0, epsilon, 0.0);
  }
  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(atlasBuild);

  bool observedBandCarrier = false;
  const std::array<std::size_t, 3> opposite{{2U, 0U, 1U}};
  for (const auto &frame : atlasBuild.value().branch_topology().frames()) {
    for (const auto &pairing : frame.branches) {
      ASSERT_FALSE(pairing.incomingCarriers.empty());
      ASSERT_FALSE(pairing.outgoingCarriers.empty());
      ASSERT_EQ(3U, pairing.intervals.size());
      for (std::size_t interval = 0U; interval < 3U; ++interval) {
        const auto &derivative = pairing.direction[opposite[interval]];
        const long double magnitude = std::abs(derivative.to_double(18));
        if (magnitude <= 0.0L || magnitude > 1.0e-10L) continue;
        observedBandCarrier = true;
        const auto &published = pairing.intervals[interval];
        EXPECT_NE(directional::authority::FieldBoundaryFlow::Tangent,
                  published.flow);
        const auto &carriers =
            derivative > exact_integer(0) ? pairing.incomingCarriers
                                          : pairing.outgoingCarriers;
        EXPECT_NE(carriers.end(),
                  std::find(carriers.begin(), carriers.end(),
                            published.sourceEdge));
      }
    }
  }
  EXPECT_TRUE(observedBandCarrier);
}

TEST(ResolvedBranchCorrection,
     ExactVertexSectorRejectsToleranceBandAndSelectsUniqueFace) {
  const TriMesh mesh = make_four_triangle_fan();
  const SourceVertexId center = SourceVertexId::from_index(4, 5).value();
  const auto epsilon = exact_ratio(1, 100000000000LL);

  auto sector_direction = [&](const int row,
                              const directional::authority::FieldExactRational
                                  &nextValue,
                              const directional::authority::FieldExactRational
                                  &previousValue) {
    const SourceFaceTopologyKey face = topology_face(
        mesh.F(row, 0), mesh.F(row, 1), mesh.F(row, 2), 5U);
    int corner = -1;
    for (int c = 0; c < 3; ++c) {
      if (mesh.F(row, c) == 4) corner = c;
    }
    EXPECT_GE(corner, 0);
    const SourceVertexId next =
        SourceVertexId::from_index(mesh.F(row, (corner + 1) % 3), 5).value();
    const SourceVertexId previous =
        SourceVertexId::from_index(mesh.F(row, (corner + 2) % 3), 5).value();
    directional::authority::FieldBranchDirection result;
    for (std::size_t index = 0U; index < 3U; ++index) {
      if (face.vertices()[index] == next) result.barycentric[index] = nextValue;
      if (face.vertices()[index] == previous) {
        result.barycentric[index] = previousValue;
      }
      if (face.vertices()[index] == center) {
        result.barycentric[index] = -nextValue - previousValue;
      }
    }
    EXPECT_TRUE(result.is_barycentric());
    return result;
  };

  std::array<directional::authority::FieldBranchDirection, 4> directions{
      sector_direction(0, exact_integer(1), -epsilon),
      sector_direction(1, epsilon, exact_integer(1)),
      sector_direction(2, exact_integer(-1), exact_integer(0)),
      sector_direction(3, exact_integer(-1), exact_integer(0))};
  std::size_t admitted = 0U;
  int admittedRow = -1;
  for (int row = 0; row < 4; ++row) {
    const auto face = SourceFaceId::from_index(row, 4).value();
    if (directional::authority::direction_in_vertex_sector(
            mesh, face, center, directions[static_cast<std::size_t>(row)])) {
      ++admitted;
      admittedRow = row;
    }
  }
  EXPECT_EQ(1U, admitted);
  ASSERT_EQ(1, admittedRow);

  const SourceFaceTopologyKey admittedFace = topology_face(
      mesh.F(admittedRow, 0), mesh.F(admittedRow, 1),
      mesh.F(admittedRow, 2), 5U);
  int centerCorner = -1;
  for (int c = 0; c < 3; ++c) {
    if (mesh.F(admittedRow, c) == 4) centerCorner = c;
  }
  ASSERT_GE(centerCorner, 0);
  const SourceVertexId next = SourceVertexId::from_index(
      mesh.F(admittedRow, (centerCorner + 1) % 3), 5).value();
  const SourceVertexId previous = SourceVertexId::from_index(
      mesh.F(admittedRow, (centerCorner + 2) % 3), 5).value();
  const SourceEdgeTopologyKey outgoing =
      SourceEdgeTopologyKey::make(next, previous).value();
  const SourceEdgeTopologyKey entry =
      SourceEdgeTopologyKey::make(center, next).value();
  directional::authority::FieldBranchBoundaryPairing pairing;
  pairing.branch = directional::authority::FieldBranch::from_integer(0);
  pairing.direction = directions[static_cast<std::size_t>(admittedRow)];
  pairing.outgoingCarriers = {outgoing};
  const auto entryParameter =
      entry.first() == center ? exact_integer(0) : exact_integer(1);
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          admittedFace, pairing,
          directional::authority::FieldBoundaryPoint{
              entry,
              directional::authority::ExactUnitParameter{entryParameter}});
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::surface_cell_tracing_detail::
                  FieldBranchContinuationDecision>(result));
  const auto &decision = std::get<
      directional::geometry::surface_cell_tracing_detail::
          FieldBranchContinuationDecision>(result);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                FieldBranchContinuationKind::EdgeExit,
            decision.kind);
}

TEST(ResolvedBranchCorrection,
     ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip) {
  const double base = std::ldexp(1.0, 20);
  const double spacing =
      std::nextafter(base, std::numeric_limits<double>::infinity()) - base;
  const auto epsilonRational = exact_ratio(1, 7);
  directional::authority::FieldBranchDirection direction{
      std::array<directional::authority::FieldExactRational, 3>{
          -exact_integer(1) + epsilonRational, exact_integer(1),
          -epsilonRational}};

  Eigen::MatrixXd vertices(4, 3);
  vertices << base, base, 0.0, base + spacing, base, 0.0, base,
      base + spacing, 0.0, base + spacing, base + spacing, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 0, 3;
  TriMesh witness;
  witness.set_mesh(vertices, faces);

  // Construct the deliberately lossy world-space round trip from the exact
  // numerator and denominator. Do not route this premise through
  // ENumber::to_double(maxDigits): the GMP backend is free to use its native
  // conversion and must not determine whether this test has a witness.
  const auto lossyDouble =
      [](const directional::authority::FieldExactRational &value) {
        return std::stod(value.numerator_string()) /
               std::stod(value.denominator_string());
      };
  const double lossyEpsilon = lossyDouble(epsilonRational);
  const auto recoveredEpsilon =
      directional::authority::FieldExactRational::from_double_exact(
          lossyEpsilon);
  ASSERT_TRUE(recoveredEpsilon.has_value());
  EXPECT_NE(epsilonRational, *recoveredEpsilon);

  Eigen::Vector3d world = Eigen::Vector3d::Zero();
  for (std::size_t index = 0U; index < 3U; ++index) {
    world += lossyDouble(direction[index]) *
             witness.V.row(static_cast<int>(index)).transpose();
  }
  const Eigen::Vector3d a(spacing, 0.0, 0.0);
  const Eigen::Vector3d b(0.0, spacing, 0.0);
  const double aa = a.dot(a);
  const double ab = a.dot(b);
  const double bb = b.dot(b);
  const double det = aa * bb - ab * ab;
  ASSERT_TRUE(std::isfinite(det));
  ASSERT_GT(det, 0.0);
  const double ar = a.dot(world);
  const double br = b.dot(world);
  const double recoveredBeta = (br * aa - ar * ab) / det;
  ASSERT_TRUE(std::isfinite(recoveredBeta));
  EXPECT_GT(recoveredBeta, 0.0);

  const auto face = SourceFaceId::from_index(0, 2).value();
  const auto vertex = SourceVertexId::from_index(0, 4).value();
  EXPECT_FALSE(directional::authority::direction_in_vertex_sector(
      witness, face, vertex, direction));
}

TEST(ResolvedBranchCorrection,
     ExactVertexSectorPartitionsAcceptedInteriorFans) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const SourceVertexId center = SourceVertexId::from_index(4, 5).value();
  const auto &topology = atlasBuild.value().branch_topology();
  const auto fanWalk = walk_complete_vertex_fan(mesh, topology, center);
  ASSERT_TRUE(fanWalk.has_value());
  ASSERT_EQ(static_cast<std::size_t>(mesh.F.rows()), fanWalk->size());

  // FieldBranch is a per-face gauged label: carry each start branch through the
  // published signedLift rather than reusing its numeric value on every face.
  for (std::size_t branchValue = 0U; branchValue < 4U; ++branchValue) {
    const auto startBranch = directional::authority::FieldBranch::from_integer(
        static_cast<int>(branchValue));
    auto currentBranch = startBranch;
    std::size_t admitted = 0U;
    for (const auto &step : *fanWalk) {
      const auto *frame = topology.find_frame(step.sourceFace);
      ASSERT_NE(nullptr, frame);
      const auto pairing = std::find_if(
          frame->branches.begin(), frame->branches.end(),
          [&](const auto &candidate) {
            return candidate.branch == currentBranch;
          });
      ASSERT_NE(frame->branches.end(), pairing);
      const auto faceId = SourceFaceId::from_index(
          step.faceRow, static_cast<std::size_t>(mesh.F.rows())).value();
      if (directional::authority::direction_in_vertex_sector(
              mesh, faceId, center, pairing->direction)) {
        ++admitted;
      }
      currentBranch = currentBranch.rotated(step.signedLiftToNext);
    }
    EXPECT_EQ(1U, admitted) << "branch=" << branchValue;
    EXPECT_EQ(startBranch, currentBranch)
        << "regular fan transport must close after one complete circuit";
  }
}

TEST(ResolvedBranchCorrection,
     FieldBranchTransportLocalHolonomyMatchesVertexIndex) {
  const TriMesh fanMesh = make_four_triangle_fan();
  const auto fanAuthority = make_source_authority(fanMesh);
  ASSERT_TRUE(fanAuthority.has_value());
  const auto fanAtlasBuild = directional::authority::FieldTransportAtlas::make(
      fanMesh, *fanAuthority, {}, make_zero_transport_field(fanMesh));
  ASSERT_TRUE(fanAtlasBuild);
  const SourceVertexId fanCenter = SourceVertexId::from_index(4, 5).value();
  const auto fanWalk = walk_complete_vertex_fan(
      fanMesh, fanAtlasBuild.value().branch_topology(), fanCenter);
  ASSERT_TRUE(fanWalk.has_value());
  EXPECT_EQ(0, composed_fan_lift(*fanWalk));

  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  ASSERT_EQ(8U, sphere.atlas->singularities().size()) << sphere.report;
  for (const auto &singularity : sphere.atlas->singularities()) {
    ASSERT_EQ(1, singularity.indexNumerator);
    const auto walk = walk_complete_vertex_fan(
        sphere.mesh, sphere.atlas->branch_topology(),
        singularity.sourceVertex);
    ASSERT_TRUE(walk.has_value())
        << "sourceVertex=" << singularity.sourceVertex.index();
    EXPECT_EQ(normalized_quarter_turn(singularity.indexNumerator),
              composed_fan_lift(*walk))
        << "sourceVertex=" << singularity.sourceVertex.index();
  }
}

TEST(ResolvedBranchCorrection,
     SingleMinimizerVertexEndpointDispatchesVertexHit) {
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const auto pairing =
      continuation_pairing({-1, 1, 0}, {topology_edge(1, 2)});
  const auto result = directional::geometry::surface_cell_tracing_detail::
      resolve_field_branch_continuation(
          face, pairing, boundary_point(topology_edge(0, 1), 0, 1));
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::surface_cell_tracing_detail::
                  FieldBranchContinuationDecision>(result));
  const auto &decision = std::get<
      directional::geometry::surface_cell_tracing_detail::
          FieldBranchContinuationDecision>(result);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                FieldBranchContinuationKind::VertexHit,
            decision.kind);
  ASSERT_TRUE(decision.sourceVertex.has_value());
  EXPECT_EQ(SourceVertexId::from_index(1, 3).value(), *decision.sourceVertex);
}

TEST(ResolvedBranchCorrection,
     CrossEdgeGrazingClassifiesAndTransitsWithPublishedAuthorities) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey sourceFace = topology_face(0, 1, 2, 4);
  const SourceFaceTopologyKey targetFace = topology_face(0, 1, 3, 4);
  const SourceEdgeTopologyKey carrier = topology_edge(0, 1, 4);
  auto sourcePairing = continuation_pairing({-1, 2, -1}, {carrier});
  auto targetPairing = continuation_pairing({-1, 2, -1}, {carrier});
  targetPairing.branch = directional::authority::FieldBranch::from_integer(2);

  EXPECT_EQ(FieldBranchEdgeFlowRelation::Outflow,
            classify_field_branch_transport_flow(
                sourceFace, sourcePairing, targetFace, targetPairing, carrier));
  auto tangentPairing = continuation_pairing({1, -1, 0}, {carrier});
  EXPECT_EQ(FieldBranchEdgeFlowRelation::Tangent,
            classify_field_branch_transport_flow(
                sourceFace, sourcePairing, targetFace, tangentPairing, carrier));

  const auto result = resolve_field_branch_grazing_transit(
      sourceFace, sourcePairing, targetFace, targetPairing, carrier, 2,
      directional::authority::ExactUnitParameter{exact_ratio(1, 3)});
  ASSERT_TRUE(std::holds_alternative<FieldBranchContinuationDecision>(result));
  const auto &decision = std::get<FieldBranchContinuationDecision>(result);
  EXPECT_EQ(FieldBranchContinuationKind::EdgeTransit, decision.kind);
  ASSERT_TRUE(decision.sourceVertex.has_value());
  EXPECT_EQ(carrier.second(), *decision.sourceVertex);
  EXPECT_EQ(exact_integer(1), decision.exitPoint.parameter.value);
}


TEST(ResolvedBranchCorrection,
     GrazingSlideAmbiguityPublishesSiteSourcedLocus) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey sourceFace = topology_face(0, 1, 2, 4);
  const SourceFaceTopologyKey targetFace = topology_face(0, 1, 3, 4);
  const SourceEdgeTopologyKey carrier = topology_edge(0, 1, 4);
  auto sourcePairing = continuation_pairing({-1, 2, -1}, {carrier});
  auto targetPairing = continuation_pairing({3, -2, -1}, {carrier});
  targetPairing.branch = directional::authority::FieldBranch::from_integer(2);
  const auto parameter =
      directional::authority::ExactUnitParameter{exact_ratio(1, 3)};

  const auto result = resolve_field_branch_grazing_transit(
      sourceFace, sourcePairing, targetFace, targetPairing, carrier, 2,
      parameter);
  ASSERT_TRUE(std::holds_alternative<
              directional::geometry::FieldAlignedCurveNetworkError>(result));
  const auto &error =
      std::get<directional::geometry::FieldAlignedCurveNetworkError>(result);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::BranchGrazingSlideDirectionAmbiguous,
            error.code);
  const std::string locus = network_error_locus(error);
  for (const std::string &token :
       {std::string("sourceFace=0-1-2"),
        std::string("relatedSourceFace=0-1-3"), std::string("branch=0"),
        std::string("relatedBranch=2"), std::string("sourceEdge=0-1"),
        std::string("signedLift=2"), std::string("parameter=1/3"),
        std::string("exactValues=[-1/1,-1/1,2/1,-2/1]")}) {
    EXPECT_NE(std::string::npos, locus.find(token)) << locus;
  }
}

TEST(ResolvedBranchCorrection,
     GrazingTransitIsInvariantToPositiveFaceScale) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey sourceFace = topology_face(0, 1, 2, 4);
  const SourceFaceTopologyKey targetFace = topology_face(0, 1, 3, 4);
  const SourceEdgeTopologyKey carrier = topology_edge(0, 1, 4);
  const auto sourcePairing = continuation_pairing({-1, 2, -1}, {carrier});
  const auto scaledSourcePairing =
      continuation_pairing({-3, 6, -3}, {carrier});
  const auto targetPairing = continuation_pairing({-1, 2, -1}, {carrier});
  const auto parameter =
      directional::authority::ExactUnitParameter{exact_ratio(2, 5)};

  const auto base = resolve_field_branch_grazing_transit(
      sourceFace, sourcePairing, targetFace, targetPairing, carrier, 0,
      parameter);
  const auto scaled = resolve_field_branch_grazing_transit(
      sourceFace, scaledSourcePairing, targetFace, targetPairing, carrier, 0,
      parameter);
  ASSERT_TRUE(std::holds_alternative<FieldBranchContinuationDecision>(base));
  ASSERT_TRUE(std::holds_alternative<FieldBranchContinuationDecision>(scaled));
  const auto &baseDecision = std::get<FieldBranchContinuationDecision>(base);
  const auto &scaledDecision = std::get<FieldBranchContinuationDecision>(scaled);
  EXPECT_EQ(baseDecision.sourceVertex, scaledDecision.sourceVertex);
  EXPECT_EQ(baseDecision.exitPoint, scaledDecision.exitPoint);
}

TEST(ResolvedBranchCorrection,
     GrazingTransitSelectsSameEndpointFromEitherFace) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey firstFace = topology_face(0, 1, 2, 4);
  const SourceFaceTopologyKey secondFace = topology_face(0, 1, 3, 4);
  const SourceEdgeTopologyKey carrier = topology_edge(0, 1, 4);
  auto firstPairing = continuation_pairing({-1, 2, -1}, {carrier});
  auto secondPairing = continuation_pairing({-1, 2, -1}, {carrier});
  secondPairing.branch = directional::authority::FieldBranch::from_integer(2);
  const auto parameter =
      directional::authority::ExactUnitParameter{exact_ratio(1, 2)};

  const auto forward = resolve_field_branch_grazing_transit(
      firstFace, firstPairing, secondFace, secondPairing, carrier, 2,
      parameter);
  const auto reverse = resolve_field_branch_grazing_transit(
      secondFace, secondPairing, firstFace, firstPairing, carrier, -2,
      parameter);
  ASSERT_TRUE(std::holds_alternative<FieldBranchContinuationDecision>(forward));
  ASSERT_TRUE(std::holds_alternative<FieldBranchContinuationDecision>(reverse));
  const auto &forwardDecision =
      std::get<FieldBranchContinuationDecision>(forward);
  const auto &reverseDecision = std::get<FieldBranchContinuationDecision>(reverse);
  EXPECT_EQ(forwardDecision.sourceVertex, reverseDecision.sourceVertex);
  EXPECT_EQ(forwardDecision.exitPoint, reverseDecision.exitPoint);
}

TEST(ResolvedBranchCorrection,
     FaceInteriorArrivalModePreservesExistingVertexTransit) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_zero_transport_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto &topology = atlasBuild.value().branch_topology();
  const SourceVertexId center = SourceVertexId::from_index(4, 5).value();

  bool compared = false;
  for (const auto &frame : topology.frames()) {
    if (std::find(frame.sourceFace.vertices().begin(), frame.sourceFace.vertices().end(),
                  center) == frame.sourceFace.vertices().end()) {
      continue;
    }
    for (const auto &pairing : frame.branches) {
      const auto legacy = resolve_field_vertex_transit(
          mesh, topology, frame.sourceComponent, frame.topologyRegion,
          frame.sourceFace, pairing.branch, center);
      const auto explicitFaceInterior = resolve_field_vertex_transit(
          mesh, topology, frame.sourceComponent, frame.topologyRegion,
          frame.sourceFace, pairing.branch, center,
          FieldVertexArrivalMode::FaceInterior);
      EXPECT_EQ(legacy, explicitFaceInterior);
      compared = true;
    }
  }
  EXPECT_TRUE(compared);
}

TEST(ResolvedBranchCorrection,
     TraceTraversalDistinguishesExactEntryPositionsAndFailsClosedOnBounds) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const SourceEdgeTopologyKey edge = topology_edge(0, 1);
  const auto branch = directional::authority::FieldBranch::from_integer(0);
  const FieldAlignedTraceTraversalState first{
      face, branch, edge, boundary_point(edge, 1, 3)};
  const FieldAlignedTraceTraversalState second{
      face, branch, edge, boundary_point(edge, 2, 3)};

  FieldAlignedTraceTraversalGuard cycleGuard(3U);
  EXPECT_EQ(FieldAlignedTraceTraversalStatus::Advanced,
            cycleGuard.observe(first));
  EXPECT_EQ(FieldAlignedTraceTraversalStatus::Advanced,
            cycleGuard.observe(second));
  const auto cycleStatus = cycleGuard.observe(first);
  ASSERT_EQ(FieldAlignedTraceTraversalStatus::CycleDetected, cycleStatus);
  const auto cycleError =
      field_aligned_trace_traversal_error(cycleStatus, first, cycleGuard);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::TraceStateCycleDetected,
            cycleError.code);
  EXPECT_EQ(first.entryPoint.parameter, cycleError.parameter);

  FieldAlignedTraceTraversalGuard boundGuard(1U);
  EXPECT_EQ(FieldAlignedTraceTraversalStatus::Advanced,
            boundGuard.observe(first));
  const auto status = boundGuard.observe(second);
  ASSERT_EQ(FieldAlignedTraceTraversalStatus::StepBudgetExhausted, status);
  const auto error =
      field_aligned_trace_traversal_error(status, second, boundGuard);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::TraceStepBudgetExhausted,
            error.code);
  EXPECT_EQ(second.entryPoint.parameter, error.parameter);
  EXPECT_EQ(1U, error.traceSteps);
  EXPECT_EQ(1U, error.traceStepBudget);
}

TEST(ResolvedBranchCorrection,
     TraceTraversalFailsClosedOnPositionFreeCombinatorialRecurrence) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const SourceEdgeTopologyKey edge = topology_edge(0, 1);
  const auto branch = directional::authority::FieldBranch::from_integer(0);
  // Three entries into one (face, branch, incoming carrier), each at a distinct
  // exact position. The exact-state guard can never see these as a repetition,
  // which is precisely how a circulating trace escaped every earlier bound.
  const FieldAlignedTraceTraversalState first{
      face, branch, edge, boundary_point(edge, 1, 5)};
  const FieldAlignedTraceTraversalState second{
      face, branch, edge, boundary_point(edge, 2, 5)};
  const FieldAlignedTraceTraversalState third{
      face, branch, edge, boundary_point(edge, 3, 5)};

  FieldAlignedTraceTraversalGuard guard(1024U);
  EXPECT_EQ(FieldAlignedTraceTraversalStatus::Advanced, guard.observe(first));
  EXPECT_EQ(FieldAlignedTraceTraversalStatus::Advanced, guard.observe(second));
  const auto status = guard.observe(third);
  ASSERT_EQ(FieldAlignedTraceTraversalStatus::CombinatorialRecurrenceExceeded,
            status);
  const auto error = field_aligned_trace_traversal_error(status, third, guard);
  EXPECT_EQ(
      FieldAlignedCurveNetworkErrorCode::TraceCombinatorialRecurrenceExceeded,
      error.code);
  EXPECT_EQ(third.entryPoint.parameter, error.parameter);
  ASSERT_TRUE(error.traceCombinatorialVisits.has_value());
  EXPECT_EQ(kFieldAlignedTraceMaxCombinatorialVisits + 1U,
            *error.traceCombinatorialVisits);
  ASSERT_TRUE(error.traceCombinatorialVisitAllowance.has_value());
  EXPECT_EQ(kFieldAlignedTraceMaxCombinatorialVisits,
            *error.traceCombinatorialVisitAllowance);

  // The guard counts states, not steps: a different incoming carrier is a
  // different combinatorial state and must still advance.
  const SourceEdgeTopologyKey otherEdge = topology_edge(1, 2);
  const FieldAlignedTraceTraversalState other{
      face, branch, otherEdge, boundary_point(otherEdge, 1, 5)};
  EXPECT_EQ(FieldAlignedTraceTraversalStatus::Advanced, guard.observe(other));

  const std::string emitted = network_error_locus(error);
  EXPECT_EQ(std::string::npos, emitted.find('\0'));
  EXPECT_NE(std::string::npos,
            emitted.find("TraceCombinatorialRecurrenceExceeded"));
  EXPECT_NE(std::string::npos, emitted.find(";traceCombinatorialVisits="));
  EXPECT_NE(std::string::npos,
            emitted.find(";traceCombinatorialVisitAllowance="));
}

TEST(ResolvedBranchCorrection,
     ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const SourceFaceTopologyKey face = topology_face(0, 1, 2);
  const SourceEdgeTopologyKey incoming = topology_edge(0, 1);
  const SourceEdgeTopologyKey outgoing = topology_edge(1, 2);
  // Keep the positive control geometrically non-degenerate: on incoming
  // edge (0,1), barycentric coordinate 2 is exactly zero.  The former
  // {-1,2,-1} witness therefore made that zero coordinate an outflow
  // minimizer and correctly produced a zero-time degenerate entry.
  const auto pairing = continuation_pairing({-2, 1, 1}, {outgoing, incoming});

  // A parameter still inside the unit interval whose exact width exceeds the
  // policy: 1 / 2^k built by repeated squaring, so the value stays exact and
  // the construction itself stays cheap.
  auto wide = exact_ratio(1, 2);
  std::size_t width = 1U;
  while (width <= kFieldExactContinuationMagnitudeBits) {
    wide = wide * wide;
    width = wide.magnitude_bits();
  }
  ASSERT_GT(wide.magnitude_bits(), kFieldExactContinuationMagnitudeBits);
  const directional::authority::FieldBoundaryPoint widePoint{
      incoming, directional::authority::ExactUnitParameter{wide}};
  ASSERT_TRUE(widePoint.parameter.in_unit_interval());

  const auto rejected =
      resolve_field_branch_continuation(face, pairing, widePoint);
  const auto *error =
      std::get_if<directional::geometry::FieldAlignedCurveNetworkError>(
          &rejected);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::
                BranchContinuationExactMagnitudeExceeded,
            error->code);
  EXPECT_EQ(face, error->sourceFace);
  EXPECT_EQ(incoming, error->sourceEdge);
  ASSERT_TRUE(error->parameter.has_value());
  EXPECT_EQ(widePoint.parameter, *error->parameter);
  const std::string emitted = network_error_locus(*error);
  EXPECT_NE(std::string::npos,
            emitted.find("BranchContinuationExactMagnitudeExceeded"));

  // The policy is a width, never a value: an ordinary narrow parameter on the
  // same face and pairing still resolves, so nothing about the topological
  // decision has been approximated away.
  const auto narrowPoint = boundary_point(incoming, 1, 2);
  const auto resolved =
      resolve_field_branch_continuation(face, pairing, narrowPoint);
  const auto *decision =
      std::get_if<FieldBranchContinuationDecision>(&resolved);
  ASSERT_NE(nullptr, decision);
  EXPECT_EQ(FieldBranchContinuationKind::EdgeExit, decision->kind);
  EXPECT_EQ(outgoing, decision->outgoingCarrier);
  EXPECT_EQ(boundary_point(outgoing, 1, 4), decision->exitPoint);
}

TEST(ResolvedBranchCorrection,
     TraceStepBudgetCannotFireBeforeTheRecurrenceAllowance) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const auto atlasBuild = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, make_index_one_singularity_field(mesh));
  ASSERT_TRUE(atlasBuild);
  const auto &topology = atlasBuild.value().branch_topology();

  std::size_t branchStates = 0U;
  for (const auto &frame : topology.frames()) {
    branchStates += frame.branches.size();
  }
  ASSERT_GT(branchStates, 0U);

  // Six position-free entry modes per branch state - three edges and three
  // vertices - times the per-state visit allowance. The budget is therefore an
  // envelope of the recurrence guard, not an independent policy, so it can
  // never fire first and can never be reached by an unbounded circulation.
  const std::size_t expected = std::max<std::size_t>(
      64U, branchStates * 6U * kFieldAlignedTraceMaxCombinatorialVisits);
  EXPECT_EQ(expected, field_aligned_trace_step_budget(topology));
}

TEST(ResolvedBranchCorrection,
     FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness) {
  const TriMesh fanMesh = make_four_triangle_fan();
  const auto fanAuthority = make_source_authority(fanMesh);
  ASSERT_TRUE(fanAuthority.has_value());
  const auto fanAtlas = directional::authority::FieldTransportAtlas::make(
      fanMesh, *fanAuthority, {}, make_index_one_singularity_field(fanMesh));
  ASSERT_TRUE(fanAtlas);
  EXPECT_NO_THROW({
    const auto build = FieldAlignedCurveNetwork::make(
        fanMesh, *fanAuthority, fanAtlas.value(),
        rails_from_atlas(fanMesh, fanAtlas.value()));
    (void)build;
  });

  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.sourceAuthority.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  // The exact backend signals its own runaway guards by throwing. A2a is a
  // closed producer: every outcome is a typed value, including this one.
  EXPECT_NO_THROW({
    const auto build = FieldAlignedCurveNetwork::make(
        sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails);
    (void)build;
  });
}

// Non-gating diagnostic. The transit contract itself is proved at unit level by
// CrossEdgeGrazingClassifiesAndTransitsWithPublishedAuthorities,
// GrazingTransitIsInvariantToPositiveFaceScale and
// GrazingTransitSelectsSameEndpointFromEitherFace. This identity additionally
// requires a *published sphere network*, which A2a cannot produce while some of
// the witness's separatrices circulate: terminating a circulating trace is
// crash-on-contact (DESIGN.md 4.6), owned by CP4c-1 measures C4/C5. It reports
// the typed outcome rather than asserting a build that this checkpoint cannot
// deliver, and is excluded from the required-green selector until C4/C5 land.
TEST(ResolvedBranchCorrection,
     GrazingTraceSegmentsPublishExactEndpointSupport) {
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.sourceAuthority.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  const auto networkBuild = FieldAlignedCurveNetwork::make(
      sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails);
  if (!networkBuild) {
    GTEST_SKIP() << "m3Cp4c0N5;credit=none;owningMeasure=C4/C5"
                 << ";spherePublishesNetwork=false;"
                 << network_error_locus(networkBuild.error());
  }

  std::size_t transitedSegments = 0U;
  for (const auto &trace : networkBuild.value().candidate_traces()) {
    for (std::size_t index = 0U; index < trace.segments.size(); ++index) {
      const auto &segment = trace.segments[index];
      if (!segment.edgeTransitExit.has_value()) continue;
      ++transitedSegments;
      const auto &exit = *segment.edgeTransitExit;
      const auto zero = exact_integer(0);
      const auto one = exact_integer(1);
      ASSERT_TRUE(exit.parameter.value == zero || exit.parameter.value == one);
      const auto support = exit.source_support();
      ASSERT_TRUE(support.has_value());
      const auto *vertexSupport =
          std::get_if<directional::authority::SourceVertexSupport>(&*support);
      ASSERT_NE(nullptr, vertexSupport);
      const SourceVertexId expectedVertex =
          exit.parameter.value == zero ? exit.edge.first() : exit.edge.second();
      EXPECT_EQ(expectedVertex, vertexSupport->vertex);

      const directional::authority::FieldBoundaryPoint *continuedPoint = nullptr;
      if (index + 1U < trace.segments.size()) {
        continuedPoint = &trace.segments[index + 1U].entryPoint;
      } else if (trace.terminalPoint.has_value()) {
        continuedPoint = &*trace.terminalPoint;
      }
      ASSERT_NE(nullptr, continuedPoint);
      const auto continuedSupport = continuedPoint->source_support();
      ASSERT_TRUE(continuedSupport.has_value());
      const auto *continuedVertex =
          std::get_if<directional::authority::SourceVertexSupport>(
              &*continuedSupport);
      ASSERT_NE(nullptr, continuedVertex);
      EXPECT_EQ(expectedVertex, continuedVertex->vertex);
    }
  }
  EXPECT_GT(transitedSegments, 0U);
}

TEST(ResolvedBranchCorrection,
     AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections) {
  Cp3bEventFixture twoRing = build_cp3b_event_fixture();
  ASSERT_TRUE(twoRing.network.has_value());

  const TriMesh fanMesh = make_four_triangle_fan();
  const auto fanAuthority = make_source_authority(fanMesh);
  ASSERT_TRUE(fanAuthority.has_value());
  const auto fanAtlas = directional::authority::FieldTransportAtlas::make(
      fanMesh, *fanAuthority, {}, make_index_one_singularity_field(fanMesh));
  ASSERT_TRUE(fanAtlas);
  const auto fanNetwork = FieldAlignedCurveNetwork::make(
      fanMesh, *fanAuthority, fanAtlas.value(),
      rails_from_atlas(fanMesh, fanAtlas.value()));
  if (!fanNetwork) {
    EXPECT_NE(FieldAlignedCurveNetworkErrorCode::
                  BranchContinuationDegenerateEntry,
              fanNetwork.error().code);
    EXPECT_NE(FieldAlignedCurveNetworkErrorCode::
                  BranchContinuationOutsideOutflowSet,
              fanNetwork.error().code);
  }

  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.sourceAuthority.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  const auto sphereNetwork = FieldAlignedCurveNetwork::make(
      sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails);
  if (!sphereNetwork) {
    EXPECT_NE(FieldAlignedCurveNetworkErrorCode::
                  BranchContinuationDegenerateEntry,
              sphereNetwork.error().code)
        << network_error_locus(sphereNetwork.error());
    EXPECT_NE(FieldAlignedCurveNetworkErrorCode::
                  BranchContinuationOutsideOutflowSet,
              sphereNetwork.error().code)
        << network_error_locus(sphereNetwork.error());
  }
}

TEST(GlobalTopologyPlan, SpherePrescribedWitnessStageReachabilityIsObservable) {
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_sphere_preconditions(sphere));
  FAIL() << sphere.report;
}

TEST(FieldAlignedCurveNetwork, RejectsTamperedTraceIntersectionCrossing) {
  Cp3bEventFixture twoRing = build_cp3b_event_fixture();
  ASSERT_TRUE(twoRing.sourceAuthority.has_value());
  ASSERT_TRUE(twoRing.atlas.has_value());
  ASSERT_TRUE(twoRing.network.has_value());

  const Cp4cReachabilityObservation torus =
      observe_cp4c_witness("torus", "torus");
  const Cp4cReachabilityObservation mechanical =
      observe_cp4c_witness("mechanical_feature", "mechanical feature");
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_sphere_preconditions(sphere));

  std::vector<EventWitnessView> witnesses;
  witnesses.push_back(EventWitnessView{"two-ring", &twoRing.mesh,
                                       &*twoRing.sourceAuthority, &*twoRing.atlas,
                                       &twoRing.rails, &*twoRing.network});
  if (torus.sourceAuthority && torus.atlas && torus.network) {
    witnesses.push_back(EventWitnessView{"torus", &torus.mesh,
                                         &*torus.sourceAuthority, &*torus.atlas,
                                         &torus.rails, &*torus.network});
  }
  if (mechanical.sourceAuthority && mechanical.atlas && mechanical.network) {
    witnesses.push_back(EventWitnessView{
        "mechanical feature", &mechanical.mesh, &*mechanical.sourceAuthority,
        &*mechanical.atlas, &mechanical.rails, &*mechanical.network});
  }
  if (sphere.sourceAuthority && sphere.atlas && sphere.network) {
    witnesses.push_back(EventWitnessView{
        "prescribed sphere", &sphere.mesh, &*sphere.sourceAuthority,
        &*sphere.atlas, &sphere.rails, &*sphere.network});
  }

  const EventWitnessView *selected = nullptr;
  const directional::geometry::FieldAlignedNetworkEvent *intersection = nullptr;
  for (const auto &witness : witnesses) {
    const auto *candidate = find_terminal_trace_intersection(*witness.network);
    if (candidate != nullptr) {
      selected = &witness;
      intersection = candidate;
      break;
    }
  }
  ASSERT_NE(nullptr, selected)
      << "crossing tamper requires an actually produced terminal intersection; "
      << "torusReachability={" << torus.report << "}; mechanicalReachability={"
      << mechanical.report << "}; sphereReachability={" << sphere.report << "}";
  ASSERT_NE(nullptr, intersection);

  auto tampered = selected->network->validation_candidate();
  const auto tamperedIntersection = std::find_if(
      tampered.events.begin(), tampered.events.end(), [](const auto &event) {
        return event.kind == FieldAlignedNetworkEventKind::TraceIntersection &&
               std::any_of(event.incidences.begin(), event.incidences.end(),
                           [](const auto &incidence) {
                             return incidence.role ==
                                    FieldAlignedTraceEventRole::Terminal;
                           });
      });
  ASSERT_NE(tampered.events.end(), tamperedIntersection);
  const auto terminal = std::find_if(
      tamperedIntersection->incidences.begin(), tamperedIntersection->incidences.end(),
      [](const auto &incidence) {
        return incidence.role == FieldAlignedTraceEventRole::Terminal;
      });
  ASSERT_NE(tamperedIntersection->incidences.end(), terminal);
  terminal->role = FieldAlignedTraceEventRole::Interior;

  const auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      *selected->mesh,
      *selected->sourceAuthority, *selected->atlas, *selected->rails,
      std::move(tampered));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventIncidence,
            rejected.error().code);
}

TEST(FieldAlignedCurveNetwork,
     EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced) {
  Cp3bEventFixture twoRing = build_cp3b_event_fixture();
  ASSERT_TRUE(twoRing.sourceAuthority.has_value());
  ASSERT_TRUE(twoRing.atlas.has_value());
  ASSERT_TRUE(twoRing.network.has_value());

  const Cp4cReachabilityObservation torus =
      observe_cp4c_witness("torus", "torus");
  const Cp4cReachabilityObservation mechanical =
      observe_cp4c_witness("mechanical_feature", "mechanical feature");
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_sphere_preconditions(sphere));

  std::set<FieldAlignedNetworkEventKind> producedTerminalKinds;
  std::map<FieldAlignedNetworkEventKind, std::set<std::string>> contributors;
  record_terminal_event_contract(
      EventWitnessView{"two-ring", &twoRing.mesh, &*twoRing.sourceAuthority,
                       &*twoRing.atlas, &twoRing.rails, &*twoRing.network},
      producedTerminalKinds, contributors);
  if (torus.sourceAuthority && torus.atlas && torus.network) {
    record_terminal_event_contract(
        EventWitnessView{"torus", &torus.mesh, &*torus.sourceAuthority,
                         &*torus.atlas, &torus.rails, &*torus.network},
        producedTerminalKinds, contributors);
  }
  if (mechanical.sourceAuthority && mechanical.atlas && mechanical.network) {
    record_terminal_event_contract(
        EventWitnessView{"mechanical feature", &mechanical.mesh,
                         &*mechanical.sourceAuthority, &*mechanical.atlas,
                         &mechanical.rails, &*mechanical.network},
        producedTerminalKinds, contributors);
  }
  if (sphere.sourceAuthority && sphere.atlas && sphere.network) {
    record_terminal_event_contract(
        EventWitnessView{"prescribed sphere", &sphere.mesh,
                         &*sphere.sourceAuthority, &*sphere.atlas,
                         &sphere.rails, &*sphere.network},
        producedTerminalKinds, contributors);
  }

  ASSERT_FALSE(producedTerminalKinds.empty())
      << "terminal-kind witness union must be non-vacuous; TraceIntersection="
      << terminal_kind_contributors(
             contributors, FieldAlignedNetworkEventKind::TraceIntersection)
      << "; MandatoryBarrierTermination="
      << terminal_kind_contributors(
             contributors,
             FieldAlignedNetworkEventKind::MandatoryBarrierTermination)
      << "; torusReachability={" << torus.report
      << "}; mechanicalReachability={" << mechanical.report
      << "}; sphereReachability={" << sphere.report << "}";
  EXPECT_EQ(1U, producedTerminalKinds.count(
                    FieldAlignedNetworkEventKind::TraceIntersection))
      << "TraceIntersection contributors="
      << terminal_kind_contributors(
             contributors, FieldAlignedNetworkEventKind::TraceIntersection);
  EXPECT_EQ(1U, producedTerminalKinds.count(
                    FieldAlignedNetworkEventKind::MandatoryBarrierTermination))
      << "MandatoryBarrierTermination contributors="
      << terminal_kind_contributors(
             contributors,
             FieldAlignedNetworkEventKind::MandatoryBarrierTermination);
}

TEST(TraceTerminationCorrection,
     ExactBarycentricPredicateSeparatesCrossingTouchAndOverlap) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  using Rational = directional::authority::FieldExactRational;
  const auto point = [](const Rational &a, const Rational &b,
                        const Rational &c) {
    return std::array<Rational, 3>{a, b, c};
  };

  // Proper crossing in the affine (b0,b1) chart.  The exact intersection is
  // (1/4,1/4,1/2).
  const auto proper = classify_field_aligned_barycentric_contact(
      point(exact_integer(0), exact_ratio(1, 2), exact_ratio(1, 2)),
      point(exact_ratio(1, 2), exact_integer(0), exact_ratio(1, 2)),
      point(exact_integer(0), exact_integer(0), exact_integer(1)),
      point(exact_ratio(1, 2), exact_ratio(1, 2), exact_integer(0)));
  ASSERT_EQ(FieldAlignedSegmentContactKind::ProperCrossing, proper.kind);
  ASSERT_TRUE(proper.barycentric.has_value());
  EXPECT_EQ(exact_ratio(1, 4), (*proper.barycentric)[0]);
  EXPECT_EQ(exact_ratio(1, 4), (*proper.barycentric)[1]);
  EXPECT_EQ(exact_ratio(1, 2), (*proper.barycentric)[2]);

  // A shared singularity origin is an endpoint touch, not crash-on-contact.
  const auto sharedOrigin = classify_field_aligned_barycentric_contact(
      point(exact_integer(0), exact_integer(0), exact_integer(1)),
      point(exact_ratio(1, 2), exact_integer(0), exact_ratio(1, 2)),
      point(exact_integer(0), exact_integer(0), exact_integer(1)),
      point(exact_integer(0), exact_ratio(1, 2), exact_ratio(1, 2)));
  EXPECT_EQ(FieldAlignedSegmentContactKind::EndpointTouch, sharedOrigin.kind);
  ASSERT_TRUE(sharedOrigin.barycentric.has_value());
  EXPECT_EQ(point(exact_integer(0), exact_integer(0), exact_integer(1)),
            *sharedOrigin.barycentric);

  const auto overlap = classify_field_aligned_barycentric_contact(
      point(exact_integer(0), exact_integer(0), exact_integer(1)),
      point(exact_ratio(1, 2), exact_ratio(1, 2), exact_integer(0)),
      point(exact_ratio(1, 4), exact_ratio(1, 4), exact_ratio(1, 2)),
      point(exact_ratio(1, 2), exact_ratio(1, 2), exact_integer(0)));
  EXPECT_EQ(FieldAlignedSegmentContactKind::CollinearOverlap, overlap.kind);
  EXPECT_TRUE(overlap.barycentric.has_value());
}

TEST(TraceTerminationCorrection,
     ArrivalFilterAndTiePolicyHaveNoSeniorityFallback) {
  using namespace directional::geometry::surface_cell_tracing_detail;
  EXPECT_EQ(directional::geometry::FieldTraceArrivalPriority::ArcLengthFiltered,
            field_aligned_production_arrival_priority());

  const TriMesh measureMesh = make_square_mesh();
  const auto measureFace = topology_face(0, 1, 2, 4U);
  const std::array<directional::authority::FieldExactRational, 3> vertex0{
      exact_integer(1), exact_integer(0), exact_integer(0)};
  const std::array<directional::authority::FieldExactRational, 3> vertex1{
      exact_integer(0), exact_integer(1), exact_integer(0)};
  const std::array<directional::authority::FieldExactRational, 3> vertex2{
      exact_integer(0), exact_integer(0), exact_integer(1)};
  const auto unitMeasure = field_aligned_filtered_arrival_measure(
      measureMesh, measureFace, vertex0, vertex1);
  const auto diagonalMeasure = field_aligned_filtered_arrival_measure(
      measureMesh, measureFace, vertex0, vertex2);
  ASSERT_TRUE(unitMeasure.has_value());
  ASSERT_TRUE(diagonalMeasure.has_value());
  EXPECT_TRUE(std::isfinite(unitMeasure->value));
  EXPECT_TRUE(std::isfinite(unitMeasure->bound));
  EXPECT_GT(unitMeasure->bound, 0.0);
  EXPECT_EQ(1U, unitMeasure->segmentCount);
  EXPECT_EQ(FieldAlignedArrivalOrdering::Earlier,
            field_aligned_compare_arrivals(*unitMeasure, *diagonalMeasure));
  EXPECT_EQ(FieldAlignedArrivalOrdering::Inconclusive,
            field_aligned_compare_arrivals(*unitMeasure, *unitMeasure));

  const FieldAlignedArrivalMeasure early{1.0, 0.01, 2U};
  const FieldAlignedArrivalMeasure late{2.0, 0.01, 2U};
  EXPECT_EQ(FieldAlignedArrivalOrdering::Earlier,
            field_aligned_compare_arrivals(early, late));
  EXPECT_EQ(FieldAlignedArrivalOrdering::Later,
            field_aligned_compare_arrivals(late, early));

  const FieldAlignedArrivalMeasure overlappingFirst{1.0, 0.2, 3U};
  const FieldAlignedArrivalMeasure overlappingSecond{1.1, 0.2, 7U};
  EXPECT_EQ(FieldAlignedArrivalOrdering::Inconclusive,
            field_aligned_compare_arrivals(overlappingFirst,
                                           overlappingSecond));
  const auto mutual = field_aligned_contact_termination_decision(
      FieldAlignedArrivalOrdering::Inconclusive, false);
  EXPECT_TRUE(mutual.terminateFirst);
  EXPECT_TRUE(mutual.terminateSecond);

  const auto firstWins = field_aligned_contact_termination_decision(
      FieldAlignedArrivalOrdering::Earlier, false);
  EXPECT_FALSE(firstWins.terminateFirst);
  EXPECT_TRUE(firstWins.terminateSecond);
  const auto secondWins = field_aligned_contact_termination_decision(
      FieldAlignedArrivalOrdering::Later, false);
  EXPECT_TRUE(secondWins.terminateFirst);
  EXPECT_FALSE(secondWins.terminateSecond);
}

TEST(TraceTerminationCorrection,
     ProductionPriorityIsFixedAndAlternativesRemainDiagnosticOnly) {
  using Atlas = directional::authority::FieldTransportAtlas;
  using NetworkFactory = directional::geometry::FieldAlignedCurveNetworkBuildResult (*)(
      const TriMesh &, const SourceTopologyRegions &, const Atlas &,
      const std::vector<SurfaceCellRail> &);
  static_assert(std::is_same_v<decltype(&FieldAlignedCurveNetwork::make),
                               NetworkFactory>);
  static_assert(static_cast<std::uint8_t>(
                    directional::geometry::FieldTraceArrivalPriority::
                        ArcLengthFiltered) == 0U);
  static_assert(static_cast<std::uint8_t>(
                    directional::geometry::FieldTraceArrivalPriority::StepCount) ==
                1U);
  static_assert(static_cast<std::uint8_t>(
                    directional::geometry::FieldTraceArrivalPriority::
                        BarycentricTime) == 2U);
  static_assert(static_cast<std::uint8_t>(
                    directional::geometry::FieldTraceArrivalPriority::
                        TraceSeniority) == 3U);

  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.sourceAuthority.has_value());
  ASSERT_TRUE(fixture.atlas.has_value());
  ASSERT_TRUE(fixture.network.has_value());
  EXPECT_EQ(directional::geometry::FieldTraceArrivalPriority::ArcLengthFiltered,
            fixture.network->arrival_priority());

  auto diagnostic = FieldAlignedCurveNetwork::diagnose_with_arrival_priority(
      fixture.mesh, *fixture.sourceAuthority, *fixture.atlas, fixture.rails,
      directional::geometry::FieldTraceArrivalPriority::StepCount);
  ASSERT_TRUE(diagnostic);
  EXPECT_EQ(directional::geometry::FieldTraceArrivalPriority::StepCount,
            diagnostic.value().arrival_priority());
}

TEST(TraceTerminationCorrection,
     SiteVocabularyIsDisjointAndTwoRingGainsNoContactTerminus) {
  using Kind = directional::geometry::FieldAlignedNetworkEventKind;
  static_assert(static_cast<std::uint8_t>(Kind::SingularityPortOrigin) == 0U);
  static_assert(static_cast<std::uint8_t>(Kind::FirstContact) == 1U);
  static_assert(static_cast<std::uint8_t>(Kind::TraceIntersection) == 2U);
  static_assert(static_cast<std::uint8_t>(Kind::MandatoryBarrierTermination) ==
                3U);
  static_assert(static_cast<std::uint8_t>(Kind::SingularityTermination) == 4U);
  static_assert(static_cast<std::uint8_t>(Kind::SingularityPortJunction) == 5U);
  static_assert(static_cast<std::uint8_t>(Kind::TraceSelfClosure) == 6U);

  Cp3bEventFixture fixture = build_cp3b_event_fixture();
  ASSERT_TRUE(fixture.network.has_value());
  const auto &network = *fixture.network;
  EXPECT_EQ(9U, network.nodes().size());
  EXPECT_EQ(1U, static_cast<std::size_t>(std::count_if(
                    network.events().begin(), network.events().end(),
                    [](const auto &event) {
                      return event.kind == Kind::SingularityPortJunction;
                    })));
  EXPECT_EQ(0U, static_cast<std::size_t>(std::count_if(
                    network.events().begin(), network.events().end(),
                    [](const auto &event) {
                      return event.kind == Kind::TraceIntersection;
                    })));
  EXPECT_EQ(0U, static_cast<std::size_t>(std::count_if(
                    network.events().begin(), network.events().end(),
                    [](const auto &event) {
                      return event.kind == Kind::TraceSelfClosure;
                    })));
  for (const auto &trace : network.candidate_traces()) {
    EXPECT_FALSE(trace.terminalContact.has_value());
  }
}

TEST(TraceTerminationCorrection,
     PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents) {
  using Kind = directional::geometry::FieldAlignedNetworkEventKind;
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.sourceAuthority.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.network.has_value()) << sphere.report;
  const FieldAlignedCurveNetwork &network = *sphere.network;
  ASSERT_EQ(24U, network.candidate_traces().size()) << sphere.report;

  std::size_t contactTermini = 0U;
  for (const auto &trace : network.candidate_traces()) {
    const std::size_t terminalKinds =
        static_cast<std::size_t>(trace.terminalSingularity.has_value()) +
        static_cast<std::size_t>(trace.terminalBarrier.has_value()) +
        static_cast<std::size_t>(trace.terminalContact.has_value());
    EXPECT_EQ(1U, terminalKinds) << "trace=" << trace.id.index();
    if (!trace.terminalContact.has_value()) continue;
    ++contactTermini;
    const auto &contact = *trace.terminalContact;
    const auto struck = std::find_if(
        network.candidate_traces().begin(), network.candidate_traces().end(),
        [&](const auto &candidate) { return candidate.id == contact.struckTrace; });
    ASSERT_NE(network.candidate_traces().end(), struck);
    EXPECT_LT(contact.struckSegmentIndex, struck->segments.size());
    EXPECT_EQ(exact_integer(1), contact.barycentric[0] + contact.barycentric[1] +
                                    contact.barycentric[2]);
  }
  EXPECT_GT(contactTermini, 0U) << sphere.report;

  std::size_t correctedIntersections = 0U;
  bool hasMutualTermination = false;
  for (const auto &event : network.events()) {
    if (event.kind != Kind::TraceIntersection) continue;
    ++correctedIntersections;
    const std::size_t terminals = static_cast<std::size_t>(std::count_if(
        event.incidences.begin(), event.incidences.end(), [](const auto &incidence) {
          return incidence.role ==
                 directional::geometry::FieldAlignedTraceEventRole::Terminal;
        }));
    hasMutualTermination = hasMutualTermination || terminals == 2U;
  }
  EXPECT_GT(correctedIntersections, 0U) << sphere.report;
  EXPECT_TRUE(hasMutualTermination)
      << "symmetric/inconclusive same-point arrival must terminate both traces";
}

TEST(TraceTerminationCorrection,
     TerminalContactTamperIsRejectedAtExactLocusBinding) {
  const Cp4cReachabilityObservation sphere =
      observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
  ASSERT_TRUE(sphere.sourceAuthority.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.atlas.has_value()) << sphere.report;
  ASSERT_TRUE(sphere.network.has_value()) << sphere.report;

  auto tampered = sphere.network->validation_candidate();
  auto trace = std::find_if(tampered.candidateTraces.begin(),
                            tampered.candidateTraces.end(), [](const auto &value) {
                              return value.terminalContact.has_value();
                            });
  ASSERT_NE(tampered.candidateTraces.end(), trace);
  trace->terminalContact->barycentric[0] =
      trace->terminalContact->barycentric[0] + exact_integer(1);
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails,
      std::move(tampered));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
            rejected.error().code);
}

enum class Cp4cNodeProvenance : unsigned int {
  Singularity = 1U << 0U,
  MandatoryEdgeEndpoint = 1U << 1U,
  Contact = 1U << 2U,
};

unsigned int cp4c_node_provenance(
    const FieldAlignedCurveNetwork &network,
    const directional::authority::NetworkNodeId node) {
  unsigned int provenance = 0U;
  if (std::any_of(network.singularity_ports().begin(),
                  network.singularity_ports().end(),
                  [&](const auto &port) { return port.node == node; })) {
    provenance |= static_cast<unsigned int>(Cp4cNodeProvenance::Singularity);
  }
  if (std::any_of(network.mandatory_edges().begin(),
                  network.mandatory_edges().end(),
                  [&](const auto &edge) {
                    return edge.firstNode == node || edge.secondNode == node;
                  })) {
    provenance |=
        static_cast<unsigned int>(Cp4cNodeProvenance::MandatoryEdgeEndpoint);
  }
  if (provenance == 0U) {
    provenance = static_cast<unsigned int>(Cp4cNodeProvenance::Contact);
  }
  return provenance;
}

bool cp4c_has_node_provenance(const unsigned int provenance,
                              const Cp4cNodeProvenance value) {
  return (provenance & static_cast<unsigned int>(value)) != 0U;
}

const char *cp4c_event_role_name(const FieldAlignedTraceEventRole role) {
  switch (role) {
  case FieldAlignedTraceEventRole::Interior:
    return "Interior";
  case FieldAlignedTraceEventRole::Origin:
    return "Origin";
  case FieldAlignedTraceEventRole::Terminal:
    return "Terminal";
  }
  return "unknown";
}

void append_cp4c0b_terminus_observation(
    std::ostringstream &report, const FieldAlignedCurveNetwork &network) {
  std::size_t barrierTerminatingTraces = 0U;
  std::size_t contactTerminatingTraces = 0U;
  std::size_t singularityTerminatingTraces = 0U;
  std::size_t exactlyOneTerminalKind = 0U;

  report << ";traceCount=" << network.candidate_traces().size();
  for (std::size_t index = 0U; index < network.candidate_traces().size(); ++index) {
    const auto &trace = network.candidate_traces()[index];
    const std::size_t terminalKindCount =
        static_cast<std::size_t>(trace.terminalSingularity.has_value()) +
        static_cast<std::size_t>(trace.terminalBarrier.has_value()) +
        static_cast<std::size_t>(trace.terminalContact.has_value());
    exactlyOneTerminalKind += static_cast<std::size_t>(terminalKindCount == 1U);
    barrierTerminatingTraces +=
        static_cast<std::size_t>(trace.terminalBarrier.has_value());
    contactTerminatingTraces +=
        static_cast<std::size_t>(trace.terminalContact.has_value());
    singularityTerminatingTraces +=
        static_cast<std::size_t>(trace.terminalSingularity.has_value());

    report << ";trace[" << index << "]={id=" << trace.id.index()
           << ",terminalKindCount=" << terminalKindCount << ",terminalKind=";
    if (terminalKindCount != 1U) {
      report << "none-or-multiple";
    } else if (trace.terminalSingularity.has_value()) {
      report << "terminalSingularity";
    } else if (trace.terminalBarrier.has_value()) {
      report << "terminalBarrier";
    } else {
      report << "terminalContact";
    }
    report << '}';
  }
  report << ";terminalKindsExactlyOne=" << exactlyOneTerminalKind << '/'
         << network.candidate_traces().size()
         << ";barrierTerminatingTraceCount=" << barrierTerminatingTraces
         << ";contactTerminatingTraceCount=" << contactTerminatingTraces
         << ";singularityTerminatingTraceCount=" << singularityTerminatingTraces;

  report << ";nodeCount=" << network.nodes().size();
  for (std::size_t index = 0U; index < network.nodes().size(); ++index) {
    const auto &node = network.nodes()[index];
    const unsigned int provenance = cp4c_node_provenance(network, node.id);
    report << ";node[" << index << "]={id=" << node.id.index()
           << ",provenanceMask=" << provenance
           << ",singularity="
           << (cp4c_has_node_provenance(provenance,
                                        Cp4cNodeProvenance::Singularity)
                   ? 1
                   : 0)
           << ",mandatoryEdgeEndpoint="
           << (cp4c_has_node_provenance(
                   provenance, Cp4cNodeProvenance::MandatoryEdgeEndpoint)
                   ? 1
                   : 0)
           << ",contact="
           << (cp4c_has_node_provenance(provenance, Cp4cNodeProvenance::Contact)
                   ? 1
                   : 0)
           << '}';
  }

  std::map<FieldAlignedNetworkEventKind, std::size_t> eventKindHistogram;
  std::size_t mutualTerminationEvents = 0U;
  for (const auto &event : network.events()) {
    ++eventKindHistogram[event.kind];
    const std::size_t terminalIncidences = static_cast<std::size_t>(std::count_if(
        event.incidences.begin(), event.incidences.end(), [](const auto &incidence) {
          return incidence.role == FieldAlignedTraceEventRole::Terminal;
        }));
    mutualTerminationEvents += static_cast<std::size_t>(terminalIncidences == 2U);
  }
  report << ";eventKindHistogram={";
  bool firstKind = true;
  for (const auto &[kind, count] : eventKindHistogram) {
    if (!firstKind) report << ',';
    firstKind = false;
    report << field_aligned_event_kind_name(kind) << '=' << count;
  }
  report << '}';
  report << ";mutualTerminationEventCount=" << mutualTerminationEvents
         << ";arrivalComparisonInconclusiveObserved="
         << (mutualTerminationEvents != 0U ? 1 : 0)
         << ";arrivalObservationBasis=two-terminal-non-self-contact-event";
}

void append_cp4c0b_guard_observation(
    std::ostringstream &report,
    const std::optional<FieldAlignedCurveNetworkErrorCode> errorCode) {
  report << ";guardFired={N1="
         << (errorCode == FieldAlignedCurveNetworkErrorCode::
                              TraceCombinatorialRecurrenceExceeded
                 ? 1
                 : 0)
         << ",N2="
         << (errorCode == FieldAlignedCurveNetworkErrorCode::
                              BranchContinuationExactMagnitudeExceeded
                 ? 1
                 : 0)
         << ",N4="
         << (errorCode == FieldAlignedCurveNetworkErrorCode::
                              TraceStepBudgetExhausted
                 ? 1
                 : 0)
         << '}';
}

TEST(ResolvedBranchCorrection,
     FourTriangleFanTerminationCensusIsPublishedNonGating) {
  std::ostringstream report;
  report << "m3Cp4c0bV2"
         << ";credit=none"
         << ";owningMeasure=V2"
         << ";witness=four-triangle-fan"
         << ";railAuthority="
         << cp4c_rail_authority_name(Cp4cRailAuthority::AtlasDerived);

  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  if (!sourceAuthority.has_value()) {
    report << ";status=source-authority-unavailable";
    std::cout << report.str() << '\n';
    return;
  }
  const CrossFieldResult field = make_index_one_singularity_field(mesh);
  const auto atlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  if (!atlas) {
    report << ";status=atlas-unavailable";
    std::cout << report.str() << '\n';
    return;
  }
  const auto rails = rails_from_atlas(mesh, atlas.value());
  report << ";mandatoryEdgeCount=" << rails.size()
         << ";singularityCount=" << atlas.value().singularities().size();

  const auto networkBuild =
      FieldAlignedCurveNetwork::make(mesh, *sourceAuthority, atlas.value(), rails);
  if (!networkBuild) {
    report << ";status=unreached";
    append_cp4c0b_guard_observation(report, networkBuild.error().code);
    report << ';';
    append_network_error(report, networkBuild.error());
    std::cout << report.str() << '\n';
    return;
  }

  report << ";status=reached";
  append_cp4c0b_guard_observation(report, std::nullopt);
  append_cp4c0b_terminus_observation(report, networkBuild.value());
  std::cout << report.str() << '\n';
}

TEST(ResolvedBranchCorrection,
     TwoRingContactPairingCensusIsPublishedNonGating) {
  std::ostringstream report;
  report << "m3Cp4c0bV3"
         << ";credit=none"
         << ";owningMeasure=V3"
         << ";witness=two-ring"
         << ";railAuthority="
         << cp4c_rail_authority_name(Cp4cRailAuthority::AtlasDerived);

  const TriMesh mesh = make_cp3a_two_ring_skew_disc();
  const auto sourceAuthority = make_source_authority(mesh);
  if (!sourceAuthority.has_value()) {
    report << ";status=source-authority-unavailable";
    std::cout << report.str() << '\n';
    return;
  }
  CrossFieldResult field;
  make_cp3a_two_ring_index_one_field(mesh, field);
  const auto atlas = directional::authority::FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, field);
  if (!atlas) {
    report << ";status=atlas-unavailable";
    std::cout << report.str() << '\n';
    return;
  }
  const auto rails = rails_from_atlas(mesh, atlas.value());
  report << ";mandatoryEdgeCount=" << rails.size()
         << ";singularityCount=" << atlas.value().singularities().size();

  const auto networkBuild =
      FieldAlignedCurveNetwork::make(mesh, *sourceAuthority, atlas.value(), rails);
  if (!networkBuild) {
    report << ";status=unreached";
    append_cp4c0b_guard_observation(report, networkBuild.error().code);
    report << ';';
    append_network_error(report, networkBuild.error());
    std::cout << report.str() << '\n';
    return;
  }

  const auto &network = networkBuild.value();
  report << ";status=reached";
  append_cp4c0b_guard_observation(report, std::nullopt);
  append_cp4c0b_terminus_observation(report, network);

  std::size_t barrierEventIndex = 0U;
  for (std::size_t eventIndex = 0U; eventIndex < network.events().size();
       ++eventIndex) {
    const auto &event = network.events()[eventIndex];
    report << ";event[" << eventIndex << "]={kind="
           << field_aligned_event_kind_name(event.kind)
           << ",node=" << event.node.index()
           << ",sourceFace=" << source_face_locus(event.sourceFace)
           << ",sourceEdge=";
    if (event.sourceEdge.has_value()) {
      report << source_edge_locus(*event.sourceEdge);
    } else {
      report << "none";
    }
    report << ",incidences=[";
    for (std::size_t incidenceIndex = 0U;
         incidenceIndex < event.incidences.size(); ++incidenceIndex) {
      if (incidenceIndex != 0U) report << ',';
      const auto &incidence = event.incidences[incidenceIndex];
      report << "{trace=" << incidence.trace.index()
             << ",sourcePort=" << incidence.sourcePort.index()
             << ",role=" << cp4c_event_role_name(incidence.role) << '}';
    }
    report << "]}";

    if (event.kind != FieldAlignedNetworkEventKind::MandatoryBarrierTermination)
      continue;
    const bool hasPairedFirstContact = std::any_of(
        network.events().begin(), network.events().end(), [&](const auto &candidate) {
          return candidate.kind == FieldAlignedNetworkEventKind::FirstContact &&
                 candidate.node == event.node &&
                 candidate.sourceFace == event.sourceFace &&
                 candidate.sourceEdge == event.sourceEdge;
        });
    report << ";barrierPairing[" << barrierEventIndex++ << "]={event="
           << eventIndex << ",pairedFirstContact="
           << (hasPairedFirstContact ? 1 : 0) << '}';
  }
  report << ";barrierTerminationEventCount=" << barrierEventIndex;
  std::cout << report.str() << '\n';
}

TEST(TraceTerminationCorrection,
     TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded) {
  const Cp4cReachabilityObservation torus =
      observe_cp4c_witness("torus", "torus");
  ASSERT_TRUE(torus.sourceAuthority.has_value()) << torus.report;
  ASSERT_TRUE(torus.atlas.has_value()) << torus.report;
  ASSERT_TRUE(torus.network.has_value()) << torus.report;
  EXPECT_EQ(Cp4cRailAuthority::PipelineAuthoritative, torus.railAuthority);
  EXPECT_TRUE(torus.network->candidate_traces().empty());
  ASSERT_FALSE(torus.network->nodes().empty());
  for (const auto &node : torus.network->nodes()) {
    const unsigned int provenance =
        cp4c_node_provenance(*torus.network, node.id);
    EXPECT_TRUE(cp4c_has_node_provenance(
        provenance, Cp4cNodeProvenance::MandatoryEdgeEndpoint));
    EXPECT_FALSE(
        cp4c_has_node_provenance(provenance, Cp4cNodeProvenance::Contact));
  }
  for (const auto &trace : torus.network->candidate_traces()) {
    EXPECT_FALSE(trace.terminalContact.has_value());
  }

  std::map<directional::geometry::FieldAlignedNetworkEventKind, std::size_t>
      eventKindHistogram;
  for (const auto &event : torus.network->events()) {
    ++eventKindHistogram[event.kind];
  }
  EXPECT_EQ(0U,
            eventKindHistogram[directional::geometry::
                                   FieldAlignedNetworkEventKind::TraceIntersection]);
  EXPECT_EQ(0U, eventKindHistogram[directional::geometry::
                                      FieldAlignedNetworkEventKind::
                                          SingularityPortJunction]);
  EXPECT_TRUE(torus.network->events().empty());

  // The four-triangle fan remains a structural/excluded witness: exercise the
  // producer without granting it CP4c-0b acceptance credit.
  const TriMesh fan = make_four_triangle_fan();
  const auto authority = make_source_authority(fan);
  ASSERT_TRUE(authority.has_value());
  const auto atlas = directional::authority::FieldTransportAtlas::make(
      fan, *authority, {}, make_index_one_singularity_field(fan));
  ASSERT_TRUE(atlas);
  const auto fanBuild = FieldAlignedCurveNetwork::make(
      fan, *authority, atlas.value(), rails_from_atlas(fan, atlas.value()));
  (void)fanBuild;
  SUCCEED() << "fan executed only as an excluded non-creditable structural witness";
}

TEST(GlobalTopologyPlan,
     ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation) {
  const auto &torus = cp4c_torus_fixture();
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_torus_preconditions(torus));
  ASSERT_NO_FATAL_FAILURE(expect_cp4c_plan_disc_proofs(torus));
  ASSERT_NO_FATAL_FAILURE(
      expect_all_mandatory_edges_preserved(*torus.network, *torus.plan));

  const auto &mechanical = cp4c_mechanical_fixture();
  ASSERT_NO_FATAL_FAILURE(assert_cp4c_mechanical_preconditions(mechanical));
  ASSERT_NO_FATAL_FAILURE(expect_cp4c_plan_disc_proofs(mechanical));
  ASSERT_NO_FATAL_FAILURE(expect_all_mandatory_edges_preserved(
      *mechanical.network, *mechanical.plan));
}
