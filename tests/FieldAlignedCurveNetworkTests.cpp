#include <gtest/gtest.h>

#include <algorithm>
#include <numbers>
#include <set>
#include <type_traits>
#include <vector>

#include <Eigen/Sparse>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/SurfaceCellTracing.h>

namespace {

using directional::TriMesh;
using directional::geometry::FieldAlignedCurveNetworkErrorCode;
using directional::authority::FieldSingularityId;
using directional::authority::HardRailId;
using directional::authority::SourceComponentId;
using directional::authority::SourceEdgeTopologyKey;
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
    rail.sourceEdges = {static_cast<int>(index)};
    rails.push_back(std::move(rail));
  }
  return rails;
}

FieldAlignedCurveNetwork build_network(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority,
    const directional::authority::FieldTransportAtlas &atlas,
    const std::vector<SurfaceCellRail> &rails) {
  auto built = FieldAlignedCurveNetwork::make(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), sourceAuthority, atlas,
      rails);
  EXPECT_TRUE(built);
  return built.value();
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
  const auto rails = rails_from_atlas(atlas);

  auto built = FieldAlignedCurveNetwork::make(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority, atlas,
      rails);
  ASSERT_TRUE(built);
  const FieldAlignedCurveNetwork &network = built.value();
  EXPECT_EQ(atlas.quadrangulability().source_digest(), network.source_digest());
  EXPECT_EQ(directional::authority::field_transport_atlas_hash(atlas),
            network.atlas_digest());
  EXPECT_NE(0U, network.semantic_digest());
  EXPECT_EQ(5U, network.nodes().size());
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
  const auto rails = rails_from_atlas(atlasBuild.value());
  const FieldAlignedCurveNetwork baseline =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);
  ASSERT_EQ(3U, baseline.singularity_ports().size());

  FieldAlignedCurveNetworkCandidate missingPort =
      baseline.validation_candidate();
  missingPort.singularityPorts.pop_back();
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      atlasBuild.value(), rails, std::move(missingPort));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortCount,
            rejected.error().code);

  FieldAlignedCurveNetworkCandidate foreignOwner =
      baseline.validation_candidate();
  foreignOwner.singularityPorts.front().singularity =
      FieldSingularityId::from_index(1, 2).value();
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
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
  const auto rails = rails_from_atlas(atlasBuild.value());
  const FieldAlignedCurveNetwork baseline =
      build_network(mesh, *sourceAuthority, atlasBuild.value(), rails);
  ASSERT_EQ(4U, baseline.mandatory_edges().size());

  FieldAlignedCurveNetworkCandidate missing = baseline.validation_candidate();
  missing.mandatoryEdges.pop_back();
  auto rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
      atlasBuild.value(), rails, std::move(missing));
  ASSERT_FALSE(rejected);
  EXPECT_EQ(FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge,
            rejected.error().code);

  FieldAlignedCurveNetworkCandidate duplicate = baseline.validation_candidate();
  duplicate.mandatoryEdges.push_back(duplicate.mandatoryEdges.front());
  rejected = FieldAlignedCurveNetwork::make_from_candidate(
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
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
      mesh.F, static_cast<std::size_t>(mesh.V.rows()), *sourceAuthority,
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
  const auto rails = rails_from_atlas(atlasBuild.value(), true);
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
  const auto baselineRails = rails_from_atlas(baselineAtlas.value());
  const FieldAlignedCurveNetwork baseline = build_network(
      baselineMesh, *baselineAuthority, baselineAtlas.value(), baselineRails);

  const TriMesh reorderedMesh = make_square_mesh(true);
  const auto reorderedAuthority = make_source_authority(reorderedMesh);
  ASSERT_TRUE(reorderedAuthority.has_value());
  auto reorderedAtlas = directional::authority::FieldTransportAtlas::make(
      reorderedMesh, *reorderedAuthority, {},
      make_zero_transport_field(reorderedMesh));
  ASSERT_TRUE(reorderedAtlas);
  auto reorderedRails = rails_from_atlas(reorderedAtlas.value());
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
}
