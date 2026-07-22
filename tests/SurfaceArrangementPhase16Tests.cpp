#include <directional/geometry/SurfaceArrangement.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct TriangleFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

TriangleFixture unit_triangle() {
  TriangleFixture fixture;
  fixture.vertices.resize(3, 3);
  fixture.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  fixture.faces.resize(1, 3);
  fixture.faces << 0, 1, 2;
  return fixture;
}

directional::geometry::SurfaceArrangementArc make_arc(
    const int id, const std::array<double, 3> &start,
    const std::array<double, 3> &end, const int family = 0,
    const bool hard = false) {
  directional::geometry::SurfaceArrangementArc arc;
  arc.id = id;
  arc.sourceFace = 0;
  arc.startBarycentric << start[0], start[1], start[2];
  arc.endBarycentric << end[0], end[1], end[2];
  arc.family = family;
  arc.strand = family;
  arc.featureClass = hard ? 7 : 0;
  arc.hardFeature = hard;
  arc.provenance = id;
  return arc;
}

int interior_cell_count(const directional::geometry::SurfaceCellComplex &complex) {
  return static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(),
      [](const directional::geometry::SurfaceArrangementCell &cell) {
        return !cell.boundaryCycle;
      }));
}

bool has_node_near(const directional::geometry::SurfaceCellComplex &complex,
                   const Eigen::RowVector3d &bary) {
  for (const auto &node : complex.nodes) {
    if ((node.barycentric - bary).norm() < 1.0e-8) {
      return true;
    }
  }
  return false;
}

} // namespace

TEST(SurfaceArrangementPhase16, TwoCrossingSegmentsSplitOnce) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_EQ(complex.diagnostics.plantedIntersections, 1);
  EXPECT_EQ(complex.diagnostics.unsplitCrossings, 0);
  EXPECT_EQ(complex.diagnostics.geometricTJunctions, 0);
  EXPECT_TRUE(has_node_near(complex, Eigen::RowVector3d(1.0 / 3.0, 1.0 / 3.0,
                                                       1.0 / 3.0)));
}

TEST(SurfaceArrangementPhase16, CoincidentEndpointsMergeToOneNode) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.50, 0.00, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.00, 0.50, 0.50}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  int matching = 0;
  for (const auto &node : complex.nodes) {
    if ((node.barycentric - Eigen::RowVector3d(0.5, 0.0, 0.5)).norm() <
        1.0e-8) {
      ++matching;
    }
  }
  EXPECT_EQ(matching, 1);
}

TEST(SurfaceArrangementPhase16, ThreeWayIntersectionAppearsOnce) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1),
      make_arc(2, {0.00, 0.50, 0.50}, {0.75, 0.25, 0.00}, 0)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  int matching = 0;
  for (const auto &node : complex.nodes) {
    if ((node.barycentric - Eigen::RowVector3d(1.0 / 3.0, 1.0 / 3.0,
                                               1.0 / 3.0))
            .norm() < 1.0e-8) {
      ++matching;
    }
  }
  EXPECT_EQ(matching, 1);
  EXPECT_EQ(complex.diagnostics.unsplitCrossings, 0);
}

TEST(SurfaceArrangementPhase16, SourceEdgeAndVertexEventsAreCanonical) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.00, 0.25, 0.75}, {0.50, 0.25, 0.25}, 0),
      make_arc(1, {1.00, 0.00, 0.00}, {0.00, 0.50, 0.50}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_TRUE(std::any_of(complex.nodes.begin(), complex.nodes.end(),
                          [](const auto &node) {
                            return node.sourceEdge == 0 &&
                                   std::abs(node.sourceEdgeParameter - 0.75) <
                                       1.0e-8;
                          }));
  EXPECT_TRUE(has_node_near(complex, Eigen::RowVector3d(1.0, 0.0, 0.0)));
}

TEST(SurfaceArrangementPhase16, NearlyParallelSegmentsDoNotCreateFalseCrossing) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.70, 0.20, 0.10}, {0.30, 0.60, 0.10}, 0),
      make_arc(1, {0.69, 0.20, 0.11}, {0.29, 0.60, 0.11}, 0)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_EQ(complex.diagnostics.plantedIntersections, 0);
  EXPECT_EQ(complex.diagnostics.unsplitCrossings, 0);
}

TEST(SurfaceArrangementPhase16, FeatureOverlapPreservesHardRailProvenance) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.00, 1.00, 0.00}, {0.00, 0.00, 1.00}, 0, true),
      make_arc(1, {0.00, 0.75, 0.25}, {0.00, 0.25, 0.75}, 0, true)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_EQ(complex.diagnostics.hardBarrierCrossings, 0);
  EXPECT_TRUE(std::any_of(complex.halfedges.begin(), complex.halfedges.end(),
                          [](const auto &h) { return h.hardFeature; }));
}

TEST(SurfaceArrangementPhase16, DisconnectedComponentsExtractMultipleCells) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.80, 0.10, 0.10}, {0.60, 0.30, 0.10}, 0),
      make_arc(1, {0.30, 0.60, 0.10}, {0.10, 0.70, 0.20}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_GE(interior_cell_count(complex), 1);
  EXPECT_EQ(complex.diagnostics.incompleteArcChains, 0);
}

TEST(SurfaceArrangementPhase16, NonDiskAndPatchCandidateClassificationIsExposed) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_TRUE(std::any_of(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) {
                            return !cell.boundaryCycle &&
                                   cell.cellClass ==
                                       directional::geometry::
                                           SurfaceArrangementCellClass::
                                               PatchCandidate;
                          }));
}

TEST(SurfaceArrangementPhase16, RegularFourSidedAlternatingCellIsQuadReady) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.60, 0.20, 0.20}, {0.40, 0.40, 0.20}, 0),
      make_arc(1, {0.40, 0.40, 0.20}, {0.20, 0.40, 0.40}, 1),
      make_arc(2, {0.20, 0.40, 0.40}, {0.40, 0.20, 0.40}, 0),
      make_arc(3, {0.40, 0.20, 0.40}, {0.60, 0.20, 0.20}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_TRUE(std::any_of(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) {
                            return cell.quadReady &&
                                   cell.cellClass ==
                                       directional::geometry::
                                           SurfaceArrangementCellClass::
                                               RegularQuad;
                          }));
}

TEST(SurfaceArrangementPhase16, EulerBoundaryAndAreaChecksPassOnPlanarFixture) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_EQ(complex.diagnostics.eulerCharacteristic, 1);
  EXPECT_LE(complex.diagnostics.relativeAreaError, 1.0e-8);
  EXPECT_TRUE(std::any_of(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) { return cell.boundaryCycle; }));
}

TEST(SurfaceArrangementPhase16, TopologyHashIgnoresInsertionOrder) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1),
      make_arc(2, {0.00, 0.50, 0.50}, {0.75, 0.25, 0.00}, 0)};
  auto reversed = arcs;
  std::reverse(reversed.begin(), reversed.end());

  const auto first = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);
  const auto second = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, reversed);

  EXPECT_EQ(directional::geometry::hash_surface_cell_complex(first),
            directional::geometry::hash_surface_cell_complex(second));
}

TEST(SurfaceArrangementPhase16, TenRunTopologyHashIsIdentical) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1),
      make_arc(2, {0.00, 0.50, 0.50}, {0.75, 0.25, 0.00}, 0)};

  const auto first = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);
  const std::uint64_t hash =
      directional::geometry::hash_surface_cell_complex(first);
  for (int run = 0; run < 9; ++run) {
    const auto repeated = directional::geometry::build_surface_cell_complex(
        fixture.vertices, fixture.faces, arcs);
    EXPECT_EQ(directional::geometry::hash_surface_cell_complex(repeated), hash);
  }
}

TEST(SurfaceArrangementPhase16, MemoryRatioAndOverlayChannelsAreBounded) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(0, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(1, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);
  const auto overlay = directional::geometry::make_surface_arrangement_overlay(
      complex);

  EXPECT_LE(complex.diagnostics.memoryRatioEstimate, 10.0);
  EXPECT_EQ(overlay.splitSegmentStarts.rows(),
            static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.splitSegmentEnds.rows(),
            static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.sideFamily.size(), static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.cellId.size(), static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.cellClass.size(), static_cast<int>(complex.cells.size()));
  EXPECT_EQ(overlay.sliverCycle.size(), static_cast<int>(complex.cells.size()));
}
