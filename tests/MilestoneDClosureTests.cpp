#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellFeasibilityRepair.h>
#include <directional/geometry/SurfaceComplexSimplification.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <vector>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

namespace {

using directional::geometry::SurfaceArrangementArc;
using directional::geometry::SurfaceCellComplex;
using directional::geometry::SurfaceSimplificationCandidate;
using directional::geometry::SurfaceSimplificationCandidateType;

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

std::string boundary_fan_diagnostic_context(const SurfaceCellComplex &complex) {
  const auto &diagnostics = complex.diagnostics;
  std::ostringstream stream;
  stream << " boundaryFanConflict="
         << directional::geometry::surface_arrangement_boundary_fan_conflict_name(
                diagnostics.boundaryFanConflict)
         << '(' << static_cast<int>(diagnostics.boundaryFanConflict) << ')'
         << " tuple=" << diagnostics.boundaryFanConflictNode << '/'
         << diagnostics.boundaryFanConflictIncoming << '/'
         << diagnostics.boundaryFanConflictSourceRay << '/'
         << diagnostics.boundaryFanConflictTarget
         << " canonicalPairs="
         << diagnostics.boundaryCanonicalFanPairCount
         << " exteriorExclusions="
         << diagnostics.boundaryExteriorSectorExclusionCount
         << " fanSectorNodes=" << diagnostics.boundaryFanSectorNodeCount
         << " cyclicWrapInteriorSectors="
         << diagnostics.boundaryCyclicWrapInteriorSectorCount
         << " hardRailSeparators="
         << diagnostics.boundaryHardRailSeparatorCount
         << " hardRailSidePairs="
         << diagnostics.boundaryHardRailSidePairCount
         << " intervalFailure="
         << directional::geometry::surface_arrangement_interval_failure_name(
                diagnostics.boundaryFanIntervalFailure)
         << '(' << static_cast<int>(diagnostics.boundaryFanIntervalFailure)
         << ')'
         << " intervalChart="
         << diagnostics.boundaryFanIntervalSourceComponent << '/'
         << diagnostics.boundaryFanIntervalSourceSheet << '/'
         << diagnostics.boundaryFanIntervalSourceFace
         << " intervalRoot="
         << diagnostics.boundaryFanIntervalTransitionRoot
         << " intervalIdentityCount="
         << diagnostics.boundaryFanIntervalIdentityCount
         << " intervalPositions="
         << diagnostics.boundaryFanIntervalTargetPosition << "->"
         << diagnostics.boundaryFanIntervalSourcePosition
         << " intervalRawAngles="
         << diagnostics.boundaryFanIntervalTargetRawAngle << "->"
         << diagnostics.boundaryFanIntervalSourceRawAngle
         << " intervalLiftedAngles="
         << diagnostics.boundaryFanIntervalTargetLiftedAngle << "->"
         << diagnostics.boundaryFanIntervalSourceLiftedAngle
         << " intervalLiftTurns="
         << diagnostics.boundaryFanIntervalTargetLiftTurn << "->"
         << diagnostics.boundaryFanIntervalSourceLiftTurn
         << " intervalTurnDifference="
         << diagnostics.boundaryFanIntervalLiftTurnDifference
         << " intervalWedge="
         << diagnostics.boundaryFanIntervalWedgeStart << '/'
         << diagnostics.boundaryFanIntervalWedgeEnd << '/'
         << diagnostics.boundaryFanIntervalWedgeSpan
         << " intervalIntruder="
         << diagnostics.boundaryFanIntervalIntrudingHalfedge
         << " intervalIdentityHash="
         << diagnostics.boundaryFanIntervalIdentity.hash()
         << " intervalIntrudingIdentityHash="
         << diagnostics.boundaryFanIntervalIntrudingIdentity.hash()
         << " intervalEntityKey=";
  stream << '[';
  for (std::size_t index = 0;
       index < diagnostics.boundaryFanIntervalEntityKey.size(); ++index) {
    if (index > 0U) {
      stream << ',';
    }
    stream << diagnostics.boundaryFanIntervalEntityKey[index];
  }
  stream << ']';
  return stream.str();
}

SurfaceArrangementArc arc(const int id, const int face,
                          const Eigen::RowVector3d &a,
                          const Eigen::RowVector3d &b, const int family,
                          const int strand) {
  SurfaceArrangementArc value;
  value.id = id;
  value.sourceFace = face;
  value.startBarycentric = a;
  value.endBarycentric = b;
  value.family = family;
  value.strand = strand;
  value.provenance = id;
  value.sourceComponent = 0;
  value.sourceSheet = 0;
  return value;
}

void expect_node_local_successor_bijection(
    const SurfaceCellComplex &complex) {
  for (const auto &node : complex.nodes) {
    std::set<int> outgoing;
    std::map<int, int> targetCounts;
    int incomingCount = 0;
    for (const auto &halfedge : complex.halfedges) {
      if (halfedge.from == node.id) {
        outgoing.insert(halfedge.id);
      }
      if (halfedge.to != node.id) {
        continue;
      }
      ++incomingCount;
      ASSERT_GE(halfedge.next, 0);
      ASSERT_LT(halfedge.next, static_cast<int>(complex.halfedges.size()));
      EXPECT_EQ(complex.halfedges[static_cast<std::size_t>(halfedge.next)].from,
                node.id);
      ++targetCounts[halfedge.next];
    }
    EXPECT_EQ(incomingCount, static_cast<int>(outgoing.size()));
    EXPECT_EQ(targetCounts.size(), outgoing.size());
    for (const int target : outgoing) {
      EXPECT_EQ(targetCounts[target], 1);
    }
  }
}

int source_vertex_node_count(const SurfaceCellComplex &complex,
                             const Eigen::MatrixXi &faces,
                             const int sourceVertex) {
  int count = 0;
  for (const auto &node : complex.nodes) {
    bool matches = false;
    for (const auto &occurrence : node.occurrences) {
      if (occurrence.sourceFace < 0 || occurrence.sourceFace >= faces.rows()) {
        continue;
      }
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(occurrence.sourceFace, corner) == sourceVertex &&
            occurrence.barycentric[corner] >= 1.0 - 1.0e-10) {
          matches = true;
        }
      }
    }
    count += matches ? 1 : 0;
  }
  return count;
}

MeshFixture unit_triangle() {
  MeshFixture fixture;
  fixture.vertices.resize(3, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0;
  fixture.faces.resize(1, 3);
  fixture.faces << 0, 1, 2;
  return fixture;
}

MeshFixture curved_square() {
  MeshFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                      1.0, 1.0, 0.4;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2,
                   1, 3, 2;
  return fixture;
}

SurfaceCellComplex two_interface_complex(const MeshFixture &mesh) {
  SurfaceCellComplex complex;
  const std::array<Eigen::RowVector3d, 6> barycentrics = {
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 0.0, 1.0),
      Eigen::RowVector3d(0.5, 0.5, 0.0),
      Eigen::RowVector3d(1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0),
      Eigen::RowVector3d(0.5, 0.0, 0.5)};
  complex.nodes.reserve(barycentrics.size());
  for (int id = 0; id < static_cast<int>(barycentrics.size()); ++id) {
    directional::geometry::SurfaceArrangementNode node;
    node.id = id;
    node.sourceFace = 0;
    node.sourceComponent = 0;
    node.sourceSheet = 0;
    node.barycentric = barycentrics[static_cast<std::size_t>(id)];
    directional::geometry::SurfaceArrangementNodeOccurrence occurrence;
    occurrence.sourceFace = 0;
    occurrence.barycentric = node.barycentric;
    occurrence.sourceComponent = 0;
    occurrence.sourceSheet = 0;
    occurrence.provenance = id;
    node.occurrences.push_back(occurrence);
    complex.nodes.push_back(std::move(node));
  }

  const auto add_pair = [&](const int from, const int to,
                            const int forwardCell, const int reverseCell,
                            const int family, const int strand) {
    const int first = static_cast<int>(complex.halfedges.size());
    directional::geometry::SurfaceArrangementHalfedge forward;
    directional::geometry::SurfaceArrangementHalfedge reverse;
    for (directional::geometry::SurfaceArrangementHalfedge *edge :
         {&forward, &reverse}) {
      edge->sourceFace = 0;
      edge->sourceComponent = 0;
      edge->sourceSheet = 0;
      edge->family = family;
      edge->strand = strand;
      edge->sourceArc = strand;
      directional::geometry::SurfaceArrangementProvenance provenance;
      provenance.sourceArc = strand;
      provenance.provenance = strand;
      provenance.sourceFace = 0;
      provenance.family = family;
      provenance.strand = strand;
      provenance.sourceComponent = 0;
      provenance.sourceSheet = 0;
      edge->provenance.push_back(provenance);
    }
    forward.id = first;
    forward.twin = first + 1;
    forward.from = from;
    forward.to = to;
    forward.cell = forwardCell;
    reverse.id = first + 1;
    reverse.twin = first;
    reverse.from = to;
    reverse.to = from;
    reverse.cell = reverseCell;
    reverse.sourceT0 = 1.0;
    reverse.sourceT1 = 0.0;
    reverse.provenance.front().sourceT0 = 1.0;
    reverse.provenance.front().sourceT1 = 0.0;
    complex.halfedges.push_back(std::move(forward));
    complex.halfedges.push_back(std::move(reverse));
    return first;
  };

  // Nodes: A=0, B=1, C=2, P=3, R=4, Q=5.
  const int ap = add_pair(0, 3, 1, 2, -1, 0);
  const int pb = add_pair(3, 1, 0, 2, -1, 1);
  const int bc = add_pair(1, 2, 0, 2, -1, 2);
  const int cq = add_pair(2, 5, 0, 2, -1, 3);
  const int qa = add_pair(5, 0, 1, 2, -1, 4);
  const int pr = add_pair(3, 4, 1, 0, 0, 7);
  const int rq = add_pair(4, 5, 1, 0, 0, 7);

  const std::array<std::vector<int>, 3> cycles = {
      std::vector<int>{pb, bc, cq, rq + 1, pr + 1},
      std::vector<int>{ap, pr, rq, qa},
      std::vector<int>{ap + 1, qa + 1, cq + 1, bc + 1, pb + 1}};
  complex.cells.reserve(cycles.size());
  for (int id = 0; id < static_cast<int>(cycles.size()); ++id) {
    directional::geometry::SurfaceArrangementCell cell;
    cell.id = id;
    cell.sourceFace = 0;
    cell.sourceComponent = 0;
    cell.sourceSheet = 0;
    cell.sourceFaces = {0};
    cell.halfedges = cycles[static_cast<std::size_t>(id)];
    cell.boundaryCycle = id == 2;
    cell.closed = true;
    cell.disk = true;
    cell.boundaryComponentCount = 1;
    cell.eulerCharacteristic = 1;
    cell.signedArea = cell.boundaryCycle ? -0.5 : (id == 0 ? 1.0 / 3.0 : 1.0 / 6.0);
    cell.area = std::abs(cell.signedArea);
    for (int index = 0; index < static_cast<int>(cell.halfedges.size()); ++index) {
      const int edgeId = cell.halfedges[static_cast<std::size_t>(index)];
      complex.halfedges[static_cast<std::size_t>(edgeId)].next =
          cell.halfedges[static_cast<std::size_t>((index + 1) % cell.halfedges.size())];
    }
    complex.cells.push_back(std::move(cell));
  }

  complex.diagnostics.eulerCharacteristic = 1;
  complex.diagnostics.sourceEulerCharacteristic = 1;
  complex.diagnostics.connectedComponentCount = 1;
  complex.diagnostics.sourceConnectedComponentCount = 1;
  complex.diagnostics.boundaryLoopCount = 1;
  complex.diagnostics.sourceBoundaryLoopCount = 1;
  complex.diagnostics.incidenceValid = true;
  complex.diagnostics.embeddingValid = true;
  complex.diagnostics.orientationValid = true;
  complex.diagnostics.cellsDiskValid = true;
  complex.diagnostics.boundaryLoopsValid = true;
  complex.diagnostics.eulerCharacteristicValid = true;
  complex.diagnostics.topologyValid = true;
  complex.diagnostics.supportedArea = 0.5;
  complex.diagnostics.extractedArea = 0.5;
  return complex;
}
std::vector<int> internal_interface(const SurfaceCellComplex &complex) {
  std::map<std::pair<int, int>, std::vector<int>> interfaces;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.hardFeature) {
      continue;
    }
    const int other =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell;
    if (halfedge.cell < 0 || other < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size()) ||
        other >= static_cast<int>(complex.cells.size()) ||
        complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle ||
        complex.cells[static_cast<std::size_t>(other)].boundaryCycle) {
      continue;
    }
    const auto key = std::minmax(halfedge.cell, other);
    interfaces[{key.first, key.second}].push_back(halfedge.id);
  }
  for (auto &[cells, edges] : interfaces) {
    if (cells.first >= 0 && cells.second >= 0 &&
        cells.first != cells.second && edges.size() > 1U) {
      std::sort(edges.begin(), edges.end());
      return edges;
    }
  }
  return {};
}

SurfaceSimplificationCandidate removal_candidate(
    const int id, const std::vector<int> &halfedges) {
  return directional::geometry::make_removal_candidate(
      id, SurfaceSimplificationCandidateType::RedundantStrand, halfedges,
      -static_cast<double>(halfedges.size()));
}

bool candidate_support_connected(const SurfaceCellComplex &complex,
                                 const SurfaceSimplificationCandidate &candidate) {
  if (candidate.elementIds.empty()) return false;
  std::map<int, std::vector<int>> nodeEdges;
  for (const int id : candidate.elementIds) {
    if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) return false;
    const auto &halfedge = complex.halfedges[static_cast<std::size_t>(id)];
    nodeEdges[halfedge.from].push_back(id);
    nodeEdges[halfedge.to].push_back(id);
  }
  std::set<int> remaining(candidate.elementIds.begin(), candidate.elementIds.end());
  std::vector<int> stack{*remaining.begin()};
  remaining.erase(stack.back());
  while (!stack.empty()) {
    const int id = stack.back();
    stack.pop_back();
    const auto &halfedge = complex.halfedges[static_cast<std::size_t>(id)];
    for (const int node : {halfedge.from, halfedge.to}) {
      for (const int neighbor : nodeEdges[node]) {
        if (remaining.erase(neighbor) != 0U) stack.push_back(neighbor);
      }
    }
  }
  return remaining.empty();
}

MeshFixture open_cylinder(const int segments, const int axialCells) {
  MeshFixture fixture;
  constexpr double pi = 3.14159265358979323846;
  fixture.vertices.resize((axialCells + 1) * segments, 3);
  for (int ring = 0; ring <= axialCells; ++ring) {
    const double z = static_cast<double>(ring) / axialCells;
    for (int segment = 0; segment < segments; ++segment) {
      const double angle = 2.0 * pi * segment / segments;
      fixture.vertices.row(ring * segments + segment) =
          Eigen::RowVector3d(std::cos(angle), std::sin(angle), z);
    }
  }
  fixture.faces.resize(2 * axialCells * segments, 3);
  int face = 0;
  for (int ring = 0; ring < axialCells; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const int next = (segment + 1) % segments;
      const int v00 = ring * segments + segment;
      const int v10 = ring * segments + next;
      const int v01 = (ring + 1) * segments + segment;
      const int v11 = (ring + 1) * segments + next;
      fixture.faces.row(face++) = Eigen::RowVector3i(v00, v10, v01);
      fixture.faces.row(face++) = Eigen::RowVector3i(v10, v11, v01);
    }
  }
  return fixture;
}

std::vector<SurfaceArrangementArc> cylinder_grid_arcs(
    const MeshFixture &mesh, const int segments, const int axialCells) {
  // Build one canonical, face-interior axial strand. Each quadrilateral band
  // contributes two chart-local segments meeting on its diagonal. Arrangement
  // stitching then identifies the diagonal and ring-edge crossings by exact
  // source-edge parameter, avoiding duplicate arcs that coincide with source
  // mesh edges already owned by the base DCEL.
  std::vector<SurfaceArrangementArc> arcs;
  arcs.reserve(static_cast<std::size_t>(2 * axialCells));
  constexpr int segment = 0;
  constexpr int family = 1;
  constexpr int strand = 7;
  int id = 0;
  for (int ring = 0; ring < axialCells; ++ring) {
    const int firstFace = 2 * (ring * segments + segment);
    const int secondFace = firstFace + 1;
    if (secondFace >= mesh.faces.rows()) {
      break;
    }

    SurfaceArrangementArc first = arc(
        id++, firstFace,
        Eigen::RowVector3d(0.5, 0.5, 0.0),
        Eigen::RowVector3d(0.0, 0.5, 0.5), family, strand);
    SurfaceArrangementArc second = arc(
        id++, secondFace,
        Eigen::RowVector3d(0.5, 0.0, 0.5),
        Eigen::RowVector3d(0.0, 0.5, 0.5), family, strand);
    first.layoutSupport = true;
    second.layoutSupport = true;
    arcs.push_back(std::move(first));
    arcs.push_back(std::move(second));
  }
  return arcs;
}

} // namespace

TEST(MilestoneDClosure, CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces) {
  const MeshFixture mesh = curved_square();
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(mesh.vertices,
                                                         mesh.faces, {});
  EXPECT_TRUE(complex.diagnostics.embeddingValid);
  EXPECT_TRUE(complex.diagnostics.cellsDiskValid);
  EXPECT_TRUE(complex.diagnostics.topologyValid);
  const auto interior = std::find_if(
      complex.cells.begin(), complex.cells.end(),
      [](const auto &cell) { return !cell.boundaryCycle; });
  ASSERT_NE(interior, complex.cells.end());
  EXPECT_EQ(interior->sourceFaces, (std::vector<int>{0, 1}));
  EXPECT_NEAR(complex.diagnostics.extractedArea,
              complex.diagnostics.supportedArea, 1.0e-10);
}

TEST(MilestoneDClosure, InteriorHardRailIsNotClassifiedAsExteriorBoundary) {
  const MeshFixture mesh = curved_square();
  directional::geometry::SurfaceArrangementOptions options;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          1, 2, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(
          mesh.vertices, mesh.faces, {}, options);

  if (!complex.diagnostics.incidenceValid) {
    EXPECT_NE(complex.diagnostics.boundaryFanIntervalFailure,
              directional::geometry::SurfaceArrangementIntervalFailure::None)
        << boundary_fan_diagnostic_context(complex);
  }
  ASSERT_TRUE(complex.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             complex.diagnostics.incidenceFailure)
      << boundary_fan_diagnostic_context(complex);
  EXPECT_EQ(source_vertex_node_count(complex, mesh.faces, 1), 1);
  EXPECT_EQ(source_vertex_node_count(complex, mesh.faces, 2), 1);
  expect_node_local_successor_bijection(complex);
  EXPECT_EQ(complex.diagnostics.incidenceFailure,
            directional::geometry::SurfaceArrangementIncidenceFailure::None);
  EXPECT_GT(complex.diagnostics.directedWedgeCount, 0);
  EXPECT_EQ(complex.diagnostics.successorMissingCount, 0);
  EXPECT_EQ(complex.diagnostics.successorAmbiguityCount, 0);
  EXPECT_EQ(complex.diagnostics.predecessorMultiplicityFailureCount, 0);
  EXPECT_EQ(complex.diagnostics.repeatedNodeCycleCount, 0);
  EXPECT_EQ(complex.diagnostics.repeatedEdgeCycleCount, 0);
  EXPECT_GT(complex.diagnostics.boundaryRotationalNodeCount, 0);
  EXPECT_GT(complex.diagnostics.boundaryDegreeTwoRotationalNodeCount, 0);
  EXPECT_GT(complex.diagnostics.boundaryFanSectorNodeCount, 0);
  EXPECT_GT(complex.diagnostics.boundaryCanonicalFanPairCount, 0);
  EXPECT_EQ(complex.diagnostics.boundaryExteriorSectorExclusionCount,
            complex.diagnostics.boundaryFanSectorNodeCount);
  EXPECT_GT(complex.diagnostics.boundaryInteriorSectorCount, 0);
  EXPECT_GE(complex.diagnostics.boundaryHardRailSeparatorCount, 2);
  EXPECT_GE(complex.diagnostics.boundaryHardRailSidePairCount, 2);
  EXPECT_TRUE(complex.diagnostics.embeddingValid);
  EXPECT_TRUE(complex.diagnostics.orientationValid);
  EXPECT_TRUE(complex.diagnostics.cellsDiskValid);
  EXPECT_TRUE(complex.diagnostics.boundaryLoopsValid);
  EXPECT_TRUE(complex.diagnostics.eulerCharacteristicValid);
  EXPECT_TRUE(complex.diagnostics.topologyValid);
  EXPECT_EQ(std::count_if(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) { return cell.boundaryCycle; }),
            1);
  EXPECT_EQ(std::count_if(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) { return !cell.boundaryCycle; }),
            2);
  EXPECT_TRUE(std::all_of(
      complex.halfedges.begin(), complex.halfedges.end(),
      [&](const auto &halfedge) {
        return halfedge.cell >= 0 &&
               halfedge.cell < static_cast<int>(complex.cells.size());
      }));
  int boundedHardRailTwinPairs = 0;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id >= halfedge.twin || !halfedge.hardFeature) {
      continue;
    }
    const auto &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell < 0 || twin.cell < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size()) ||
        twin.cell >= static_cast<int>(complex.cells.size())) {
      continue;
    }
    const auto &left = complex.cells[static_cast<std::size_t>(halfedge.cell)];
    const auto &right = complex.cells[static_cast<std::size_t>(twin.cell)];
    if (!left.boundaryCycle && !right.boundaryCycle) {
      ++boundedHardRailTwinPairs;
      EXPECT_NE(left.id, right.id);
      ASSERT_GE(halfedge.authoritativeChartRoot, 0);
      ASSERT_GE(twin.authoritativeChartRoot, 0);
      EXPECT_NE(halfedge.authoritativeChartRoot,
                twin.authoritativeChartRoot);
      for (const int edgeId : left.halfedges) {
        ASSERT_GE(edgeId, 0);
        ASSERT_LT(edgeId, static_cast<int>(complex.halfedges.size()));
        EXPECT_EQ(complex.halfedges[static_cast<std::size_t>(edgeId)]
                      .authoritativeChartRoot,
                  halfedge.authoritativeChartRoot);
      }
      for (const int edgeId : right.halfedges) {
        ASSERT_GE(edgeId, 0);
        ASSERT_LT(edgeId, static_cast<int>(complex.halfedges.size()));
        EXPECT_EQ(complex.halfedges[static_cast<std::size_t>(edgeId)]
                      .authoritativeChartRoot,
                  twin.authoritativeChartRoot);
      }
      EXPECT_TRUE(left.sourceOwnershipClass.has_value());
      EXPECT_TRUE(right.sourceOwnershipClass.has_value());
      EXPECT_FALSE(left.sourceOwnershipClass == right.sourceOwnershipClass);
      ASSERT_EQ(left.sourceCharts.size(), 1U);
      ASSERT_EQ(right.sourceCharts.size(), 1U);
      EXPECT_NE(left.sourceCharts.front().face, right.sourceCharts.front().face);
      EXPECT_EQ(left.sourceComponent, right.sourceComponent);
    }
  }
  EXPECT_EQ(boundedHardRailTwinPairs, 1);
  EXPECT_NEAR(complex.diagnostics.extractedArea,
              complex.diagnostics.supportedArea, 1.0e-10);
  const auto exterior = std::find_if(
      complex.cells.begin(), complex.cells.end(),
      [](const auto &cell) { return cell.boundaryCycle; });
  ASSERT_NE(exterior, complex.cells.end());
  EXPECT_EQ(exterior->sourceBoundarySide, -1);
  EXPECT_EQ(exterior->sourceBoundaryLoopIds, (std::vector<int>{0}));
  for (const int halfedgeId : exterior->halfedges) {
    ASSERT_GE(halfedgeId, 0);
    ASSERT_LT(halfedgeId, static_cast<int>(complex.halfedges.size()));
    const auto &halfedge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    ASSERT_GE(halfedge.next, 0);
    ASSERT_LT(halfedge.next, static_cast<int>(complex.halfedges.size()));
    const auto &next =
        complex.halfedges[static_cast<std::size_t>(halfedge.next)];
    EXPECT_EQ(halfedge.to, next.from);
    EXPECT_EQ(next.cell, exterior->id);
  }
}

TEST(MilestoneDClosure, PartialMultiEdgeInterfaceFailsClosed) {
  const MeshFixture mesh = unit_triangle();
  SurfaceCellComplex complex = two_interface_complex(mesh);
  ASSERT_TRUE(directional::geometry::canonicalize_surface_cell_ownership(
      complex, mesh.faces));
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(complex);
  const std::vector<int> interface = internal_interface(complex);
  ASSERT_GT(interface.size(), 1U);
  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(complex);

  directional::geometry::SurfaceSimplificationOptions options;
  options.refreshCandidatesAfterCommit = false;
  options.maxCommittedTransactions = 1;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, mesh.vertices, mesh.faces,
      {removal_candidate(1, {interface.front()})}, options);

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_FALSE(result.transactions.front().committed);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                TopologyChanged);
  EXPECT_EQ(result.finalHash, before);
}

TEST(MilestoneDClosure, CompleteInterfaceCommitsAndPreservesProtectedRails) {
  const MeshFixture mesh = unit_triangle();
  SurfaceCellComplex complex = two_interface_complex(mesh);
  const std::vector<int> interface = internal_interface(complex);
  ASSERT_GT(interface.size(), 1U);
  const std::set<int> interfaceSet(interface.begin(), interface.end());
  int protectedHalfedge = -1;
  for (const auto &candidate : complex.halfedges) {
    if (candidate.id > candidate.twin || candidate.twin < 0 ||
        interfaceSet.count(candidate.id) != 0U) {
      continue;
    }
    const auto &candidateTwin =
        complex.halfedges[static_cast<std::size_t>(candidate.twin)];
    const bool touchesExterior =
        complex.cells[static_cast<std::size_t>(candidate.cell)].boundaryCycle ||
        complex.cells[static_cast<std::size_t>(candidateTwin.cell)].boundaryCycle;
    if (touchesExterior) {
      protectedHalfedge = candidate.id;
      break;
    }
  }
  ASSERT_GE(protectedHalfedge, 0);
  auto &halfedge =
      complex.halfedges[static_cast<std::size_t>(protectedHalfedge)];
  ASSERT_GE(halfedge.twin, 0);
  halfedge.hardFeature = true;
  halfedge.railId = directional::tests::test_hard_rail_id(77);
  halfedge.railT0 = 0.125;
  halfedge.railT1 = 0.875;
  auto &twin = complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
  twin.hardFeature = true;
  twin.railId = directional::tests::test_hard_rail_id(77);
  twin.railT0 = 0.875;
  twin.railT1 = 0.125;
  const auto protectedBefore =
      directional::geometry::surface_simplification_detail::protected_support(
          complex);

  directional::geometry::SurfaceSimplificationOptions options;
  options.refreshCandidatesAfterCommit = false;
  options.maxCommittedTransactions = 1;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, mesh.vertices, mesh.faces,
      {removal_candidate(2, interface)}, options);

  ASSERT_EQ(result.committed, 1);
  EXPECT_LT(result.finalActiveElements, result.initialActiveElements);
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic,
            complex.diagnostics.eulerCharacteristic);
  EXPECT_EQ(directional::geometry::surface_simplification_detail::
                protected_support(result.complex),
            protectedBefore);
}

TEST(MilestoneDClosure, DisconnectedSameStrandProducesConnectedCandidates) {
  const MeshFixture mesh = unit_triangle();
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(
          mesh.vertices, mesh.faces,
          {arc(0, 0, {0.8, 0.1, 0.1}, {0.65, 0.25, 0.1}, 0, 9),
           arc(1, 0, {0.25, 0.65, 0.1}, {0.1, 0.75, 0.15}, 0, 9)});
  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, mesh.vertices, mesh.faces);

  int redundant = 0;
  for (const auto &candidate : extracted.candidates) {
    if (candidate.type != SurfaceSimplificationCandidateType::RedundantStrand) {
      continue;
    }
    ++redundant;
    EXPECT_TRUE(candidate_support_connected(complex, candidate));
  }
  EXPECT_EQ(redundant, 0); // one-segment components are not redundant strands
  EXPECT_GE(extracted.openStripCandidates, 2);
}

TEST(MilestoneDClosure, BranchedStrandIsTopologyChangingRegionCandidate) {
  const MeshFixture mesh = unit_triangle();
  const Eigen::RowVector3d center(0.34, 0.33, 0.33);
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(
          mesh.vertices, mesh.faces,
          {arc(0, 0, center, {0.7, 0.2, 0.1}, 0, 11),
           arc(1, 0, center, {0.2, 0.7, 0.1}, 0, 11),
           arc(2, 0, center, {0.2, 0.1, 0.7}, 0, 11)});
  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, mesh.vertices, mesh.faces);

  const auto found = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return candidate.type ==
               SurfaceSimplificationCandidateType::RegionCollapse;
      });
  ASSERT_NE(found, extracted.candidates.end());
  EXPECT_TRUE(found->changesTopology);
  EXPECT_FALSE(found->sideFeasible);
  EXPECT_TRUE(found->touchesSingularity);
}

TEST(MilestoneDClosure, CylindricalOpenStrandCommitsWithTopologyPreserved) {
  constexpr int segments = 8;
  constexpr int axialCells = 2;
  const MeshFixture mesh = open_cylinder(segments, axialCells);
  const auto arcs = cylinder_grid_arcs(mesh, segments, axialCells);
  // This fixture tests the open-cylinder DCEL and simplification contract, not
  // classifier ambiguity. Stamp one explicit connected source component and
  // one physical side before arrangement construction so every periodic seam
  // occurrence participates in the same authoritative chart.
  const std::vector<int> sourceComponents(
      static_cast<std::size_t>(mesh.faces.rows()), 0);
  const std::vector<int> sourceSheets(
      static_cast<std::size_t>(mesh.faces.rows()), 0);
  directional::geometry::SurfaceArrangementOptions arrangementOptions;
  arrangementOptions.sourceFaceComponents = &sourceComponents;
  arrangementOptions.sourceFaceSheets = &sourceSheets;
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(
          mesh.vertices, mesh.faces, arcs, arrangementOptions);
  const auto incidence =
      directional::geometry::surface_simplification_detail::
          audit_complex_incidence(complex);
  ASSERT_TRUE(incidence.valid)
      << directional::geometry::surface_simplification_detail::
             surface_cell_incidence_failure_name(incidence.failure)
      << " cell=" << incidence.cell << " halfedge=" << incidence.halfedge
      << " twin=" << incidence.twin << " next=" << incidence.next
      << " node=" << incidence.node << " expected=" << incidence.expected
      << " actual=" << incidence.actual;
  expect_node_local_successor_bijection(complex);
  ASSERT_TRUE(complex.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             complex.diagnostics.incidenceFailure);
  EXPECT_EQ(complex.diagnostics.incidenceFailure,
            directional::geometry::SurfaceArrangementIncidenceFailure::None);
  EXPECT_GT(complex.diagnostics.directedWedgeCount, 0);
  EXPECT_EQ(complex.diagnostics.successorMissingCount, 0);
  EXPECT_EQ(complex.diagnostics.successorAmbiguityCount, 0);
  EXPECT_EQ(complex.diagnostics.predecessorMultiplicityFailureCount, 0);
  EXPECT_EQ(complex.diagnostics.repeatedNodeCycleCount, 0);
  EXPECT_EQ(complex.diagnostics.repeatedEdgeCycleCount, 0);
  EXPECT_GT(complex.diagnostics.boundaryRotationalNodeCount, 0);
  EXPECT_GT(complex.diagnostics.boundaryDegreeTwoRotationalNodeCount, 0);
  EXPECT_TRUE(std::all_of(
      complex.halfedges.begin(), complex.halfedges.end(),
      [&](const auto &halfedge) {
        return halfedge.cell >= 0 &&
               halfedge.cell < static_cast<int>(complex.cells.size());
      }));
  EXPECT_TRUE(std::none_of(
      complex.cells.begin(), complex.cells.end(),
      [](const auto &cell) { return cell.supportOnlyCycle; }));
  ASSERT_TRUE(complex.diagnostics.embeddingValid);
  ASSERT_TRUE(complex.diagnostics.orientationValid);
  ASSERT_TRUE(complex.diagnostics.cellsDiskValid);
  ASSERT_TRUE(complex.diagnostics.topologyValid);
  ASSERT_EQ(complex.diagnostics.eulerCharacteristic, 0);
  ASSERT_EQ(complex.diagnostics.connectedComponentCount, 1);
  ASSERT_EQ(complex.diagnostics.boundaryLoopCount, 2);
  std::set<int> exteriorLoops;
  int exteriorCells = 0;
  for (const auto &cell : complex.cells) {
    if (!cell.boundaryCycle) {
      continue;
    }
    ++exteriorCells;
    EXPECT_EQ(cell.sourceBoundarySide, -1);
    exteriorLoops.insert(cell.sourceBoundaryLoopIds.begin(),
                         cell.sourceBoundaryLoopIds.end());
    for (const int halfedgeId : cell.halfedges) {
      ASSERT_GE(halfedgeId, 0);
      ASSERT_LT(halfedgeId, static_cast<int>(complex.halfedges.size()));
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      ASSERT_GE(halfedge.next, 0);
      ASSERT_LT(halfedge.next, static_cast<int>(complex.halfedges.size()));
      const auto &next =
          complex.halfedges[static_cast<std::size_t>(halfedge.next)];
      EXPECT_EQ(halfedge.to, next.from);
      EXPECT_EQ(next.cell, cell.id);
    }
  }
  EXPECT_EQ(exteriorCells, 2);
  EXPECT_EQ(exteriorLoops, (std::set<int>{0, 1}));

  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, mesh.vertices, mesh.faces);
  const auto candidate = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &value) {
        return value.type == SurfaceSimplificationCandidateType::OpenStrip &&
               value.elementIds.size() ==
                   static_cast<std::size_t>(2 * axialCells) &&
               !value.touchesHardFeature && !value.touchesBoundary &&
               !value.touchesSingularity && !value.changesTopology &&
               value.sideFeasible;
      });
  ASSERT_NE(candidate, extracted.candidates.end());

  directional::geometry::SurfaceSimplificationOptions options;
  options.refreshCandidatesAfterCommit = false;
  options.maxCommittedTransactions = 1;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, mesh.vertices, mesh.faces, {*candidate}, options);
  ASSERT_EQ(result.committed, 1);
  EXPECT_EQ(result.recomputedCandidates, 0);
  EXPECT_LT(result.finalActiveElements, result.initialActiveElements);
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic, 0);
  EXPECT_EQ(result.complex.diagnostics.connectedComponentCount, 1);
  EXPECT_EQ(result.complex.diagnostics.boundaryLoopCount, 2);
}
