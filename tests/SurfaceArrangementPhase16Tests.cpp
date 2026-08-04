#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfaceArrangement.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <set>
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

TriangleFixture unit_square_two_triangles() {
  TriangleFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
      1.0, 0.0;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2, 1, 3, 2;
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

directional::geometry::SurfaceArrangementArc make_face_arc(
    const int id, const int face, const std::array<double, 3> &start,
    const std::array<double, 3> &end, const int family = 0,
    const bool hard = false) {
  auto arc = make_arc(id, start, end, family, hard);
  arc.sourceFace = face;
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

struct BunnySingularityFanFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  std::vector<int> sourceComponents;
  std::vector<int> sourceSheets;
  std::vector<directional::geometry::SurfaceArrangementArc> arcs;
};

BunnySingularityFanFixture bunny_singularity_fan_fixture() {
  // Minimized directly from source vertex 296 and rejected completion cell
  // 6822 of bunny_1k_random.obj. The six incident source triangles, three
  // required singular supports, transition ring, and outer continuation are
  // retained; unrelated mesh geometry is omitted.
  BunnySingularityFanFixture fixture;
  fixture.vertices.resize(7, 3);
  fixture.vertices <<
      -0.010010721447988506, 0.1669560603584521,
      -0.017230066768264458, -0.013936776751792961,
      0.18099765790104674, -0.02263356514784081,
      -0.009673296574374138, 0.17933166897414712,
      -0.030216798833368308, -0.008907478151513765,
      0.16960721958364328, -0.025732266315518212,
      -0.01692817591703402, 0.18785199951164022,
      -0.02146722827642511, -0.015127970157993838,
      0.1849640629036794, -0.026812442827628975,
      -0.02022963778078798, 0.17431411966666274,
      -0.022227561483050516;
  fixture.faces.resize(6, 3);
  fixture.faces << 1, 0, 2, 0, 3, 2, 3, 6, 2, 6, 5, 2, 2, 5, 4, 4, 1,
      2;
  fixture.sourceComponents.assign(6, 0);
  fixture.sourceSheets = {13, 13, 6, 17, 4, 13};

  struct ArcData {
    int face;
    int family;
    int sheet;
    std::array<double, 3> start;
    std::array<double, 3> end;
  };
  const std::vector<ArcData> arcData = {
      // Intrinsic transition ring, in source-face fan order.
      {0, -1, 13, {0.1719429297, 0.0, 0.8280570703},
       {0.0, 0.08488410013, 0.9151158999}},
      {1, -1, 13, {0.08488410013, 0.0, 0.9151158999},
       {0.0, 0.1, 0.9}},
      {2, -1, 6, {0.1, 0.0, 0.9},
       {0.0, 0.09960349404, 0.900396506}},
      {3, -1, 17, {0.09960349404, 0.0, 0.900396506},
       {0.0, 0.2, 0.8}},
      {4, -1, 4, {0.8, 0.2, 0.0},
       {0.8664646879, 0.0, 0.1335353121}},
      {5, -1, 13, {0.1335353121, 0.0, 0.8664646879},
       {0.0, 0.1719429297, 0.8280570703}},
      // Three required radial supports. The third crosses a source edge.
      {0, 0, 13, {0.0, 0.0, 1.0},
       {0.8394742484, 0.1605257516, 0.0}},
      {3, 1, 17, {0.0, 0.0, 1.0},
       {0.537483684, 0.462516316, 0.0}},
      {4, 1, 4, {1.0, 0.0, 0.0},
       {0.9999979605, 2.039457838e-6, 0.0}},
      {3, 1, 17, {0.0, 2.039457838e-6, 0.9999979605},
       {0.5374828406, 0.4625171594, 0.0}},
      // Retained outer continuation that made the wrong source-vertex
      // rotation concatenate all three valid sectors into one pinched walk.
      {3, 1, 17, {0.554909718, 0.445090282, 0.0},
       {0.03767605608, 0.0, 0.9623239439}},
      {2, 1, 6, {0.0, 0.03767605608, 0.9623239439},
       {0.01918077744, 0.0, 0.9808192226}},
      {1, 0, 13, {0.0, 0.01918077744, 0.9808192226},
       {0.0134956923, 0.0, 0.9865043077}},
      {0, 0, 13, {0.0, 0.0134956923, 0.9865043077},
       {0.8281449623, 0.1718550377, 0.0}},
  };
  for (const ArcData &value : arcData) {
    directional::geometry::SurfaceArrangementArc arc;
    arc.id = static_cast<int>(fixture.arcs.size());
    arc.sourceFace = value.face;
    arc.startBarycentric << value.start[0], value.start[1], value.start[2];
    arc.endBarycentric << value.end[0], value.end[1], value.end[2];
    arc.family = value.family;
    arc.strand = value.family;
    arc.provenance = arc.id;
    arc.sourceComponent = 0;
    arc.sourceSheet = value.sheet;
    arc.layoutSupport = true;
    arc.singularitySupport = true;
    fixture.arcs.push_back(std::move(arc));
  }
  return fixture;
}

directional::geometry::SurfaceArrangementNode logical_side_node(
    const int id, const Eigen::RowVector3d &barycentric) {
  directional::geometry::SurfaceArrangementNode node;
  node.id = id;
  node.sourceFace = 0;
  node.barycentric = barycentric;
  return node;
}

} // namespace

TEST(SurfaceArrangementPhase16,
     LogicalSideContinuesAcrossDifferentProvenanceBelowBranchTurn) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementNode> nodes = {
      logical_side_node(0, {0.80, 0.10, 0.10}),
      logical_side_node(1, {0.60, 0.30, 0.10}),
      logical_side_node(2, {0.3267949192431123, 0.4732050807568877,
                            0.20})};
  directional::geometry::SurfaceArrangementHalfedge first;
  first.from = 0;
  first.to = 1;
  first.family = 2;
  first.sourceArc = 10;
  first.strand = 20;
  directional::geometry::SurfaceArrangementHalfedge second;
  second.from = 1;
  second.to = 2;
  second.family = 0;
  second.sourceArc = 11;
  second.strand = 21;

  EXPECT_TRUE(directional::geometry::surface_arrangement_detail::
                  same_logical_side(first, second, nodes, fixture.vertices,
                                    fixture.faces));

  nodes[2].barycentric << 0.3267949192431123, 0.40,
      0.2732050807568877;
  EXPECT_FALSE(directional::geometry::surface_arrangement_detail::
                   same_logical_side(first, second, nodes, fixture.vertices,
                                     fixture.faces));
}

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
                            return node.sourceEdge >= 0 &&
                                   std::abs(node.sourceEdgeParameter - 0.75) <
                                       1.0e-8;
                          }));
  EXPECT_TRUE(has_node_near(complex, Eigen::RowVector3d(1.0, 0.0, 0.0)));
}

TEST(SurfaceArrangementPhase16, SharedSourceEdgeStitchesAcrossTwoFaces) {
  const auto fixture = unit_square_two_triangles();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_face_arc(0, 0, {0.0, 0.25, 0.75}, {0.0, 0.75, 0.25}, 0),
      make_face_arc(1, 1, {0.75, 0.0, 0.25}, {0.25, 0.0, 0.75}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  int seamNodes = 0;
  for (const auto &node : complex.nodes) {
    if (node.sourceEdge >= 0 &&
        std::abs(node.sourceEdgeParameter - 0.25) < 1.0e-8) {
      ++seamNodes;
    }
  }
  EXPECT_EQ(seamNodes, 1);
}

TEST(SurfaceArrangementPhase16, InteriorSourceEdgeIsNotHardRailByDefault) {
  const auto fixture = unit_square_two_triangles();
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});

  const int sharedEdgeId = static_cast<int>(
      directional::geometry::surface_arrangement_detail::source_edge_key(
          fixture.faces, 0, 0) &
      0x7fffffffu);
  int hardInteriorSeamEdges = 0;
  for (const auto &halfedge : complex.halfedges) {
    const auto &from = complex.nodes[static_cast<std::size_t>(halfedge.from)];
    const auto &to = complex.nodes[static_cast<std::size_t>(halfedge.to)];
    if (halfedge.hardFeature && from.sourceEdge == sharedEdgeId &&
        to.sourceEdge == sharedEdgeId) {
      ++hardInteriorSeamEdges;
    }
  }
  EXPECT_EQ(hardInteriorSeamEdges, 0);
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
                                   (cell.cellClass ==
                                        directional::geometry::
                                            SurfaceArrangementCellClass::
                                                PatchCandidate ||
                                    cell.cellClass ==
                                        directional::geometry::
                                            SurfaceArrangementCellClass::
                                                NonDisk);
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
  EXPECT_EQ(complex.diagnostics.sourceEulerCharacteristic, 1);
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

  EXPECT_GT(complex.diagnostics.memoryRatioEstimate, 0.0);
  EXPECT_GE(complex.diagnostics.peakMemoryBytes,
            complex.diagnostics.retainedMemoryBytes);
  EXPECT_GT(complex.diagnostics.measuredMemoryRatio, 0.0);
  EXPECT_EQ(overlay.splitSegmentStarts.rows(),
            static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.splitSegmentEnds.rows(),
            static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.sideFamily.size(), static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.cellId.size(), static_cast<int>(complex.halfedges.size()));
  EXPECT_EQ(overlay.cellClass.size(), static_cast<int>(complex.cells.size()));
  EXPECT_EQ(overlay.sliverCycle.size(), static_cast<int>(complex.cells.size()));
}

TEST(SurfaceArrangementPhase16,
     SharedSourceEdgeUsesOrientationCorrectedCanonicalParameters) {
  const auto fixture = unit_square_two_triangles();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_face_arc(10, 0, {0.0, 0.25, 0.75}, {0.0, 0.75, 0.25}, 0),
      make_face_arc(11, 1, {0.25, 0.0, 0.75}, {0.75, 0.0, 0.25}, 0)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  std::vector<double> seamParameters;
  for (const auto &node : complex.nodes) {
    if (node.sourceEdge >= 0 && node.occurrences.size() == 2U) {
      seamParameters.push_back(node.sourceEdgeParameter);
      EXPECT_EQ(node.occurrences[0].sourceFace, 0);
      EXPECT_EQ(node.occurrences[1].sourceFace, 1);
    }
  }
  std::sort(seamParameters.begin(), seamParameters.end());
  ASSERT_EQ(seamParameters.size(), 2U);
  EXPECT_NEAR(seamParameters[0], 0.25, 1.0e-10);
  EXPECT_NEAR(seamParameters[1], 0.75, 1.0e-10);
}

TEST(SurfaceArrangementPhase16,
     SharedEdgeSplitsPropagateAcrossIncidentFaceCharts) {
  const auto fixture = unit_square_two_triangles();
  auto first = make_face_arc(10, 0, {0.0, 1.0, 0.0},
                             {0.0, 0.0, 1.0}, -1, true);
  first.provenance = 110;
  auto second = make_face_arc(11, 1, {1.0, 0.0, 0.0},
                              {0.0, 0.0, 1.0}, -1, true);
  second.provenance = 111;
  // This support arc plants a midpoint split only in face 0.  Canonical
  // source-edge stitching must propagate that split to the coincident edge
  // segment represented in face 1.
  auto crossing = make_face_arc(12, 0, {1.0, 0.0, 0.0},
                                {0.0, 0.5, 0.5}, 0, false);
  crossing.provenance = 112;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {first, second, crossing});

  int sharedEdgePieces = 0;
  bool foundUnsplitChord = false;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id >= halfedge.twin) {
      continue;
    }
    const auto &from = complex.nodes[static_cast<std::size_t>(halfedge.from)];
    const auto &to = complex.nodes[static_cast<std::size_t>(halfedge.to)];
    std::set<int> sourceArcs;
    std::set<int> sourceFaces;
    for (const auto &value : halfedge.provenance) {
      if (value.sourceArc == 10 || value.sourceArc == 11) {
        sourceArcs.insert(value.sourceArc);
        sourceFaces.insert(value.sourceFace);
      }
    }
    if (sourceArcs.empty()) {
      continue;
    }
    ++sharedEdgePieces;
    EXPECT_EQ(sourceArcs, (std::set<int>{10, 11}));
    EXPECT_EQ(sourceFaces, (std::set<int>{0, 1}));
    const Eigen::RowVector3d fromPosition =
        directional::geometry::surface_arrangement_detail::node_position(
            fixture.vertices, fixture.faces, from);
    const Eigen::RowVector3d toPosition =
        directional::geometry::surface_arrangement_detail::node_position(
            fixture.vertices, fixture.faces, to);
    foundUnsplitChord = foundUnsplitChord ||
                        (fromPosition - toPosition).norm() > 1.0;
  }
  EXPECT_EQ(sharedEdgePieces, 2);
  EXPECT_FALSE(foundUnsplitChord);
  EXPECT_EQ(complex.diagnostics.incompleteArcChains, 0);
}

TEST(SurfaceArrangementPhase16,
     CoincidentSharedEdgeSegmentsMergeAndPreserveAllProvenance) {
  const auto fixture = unit_square_two_triangles();
  auto first = make_face_arc(20, 0, {0.0, 0.25, 0.75},
                             {0.0, 0.75, 0.25}, 0, true);
  first.strand = 31;
  first.provenance = 41;
  first.railId = 51;
  first.curveId = 61;
  first.sourceComponent = 2;
  first.sourceSheet = 3;
  first.proposalId = 71;
  first.proposalSeedId = 81;
  first.proposalSide = 1;
  first.proposalBoundarySegment = 91;

  auto second = make_face_arc(21, 1, {0.25, 0.0, 0.75},
                              {0.75, 0.0, 0.25}, 1, false);
  second.strand = 32;
  second.provenance = 42;
  second.railId = 52;
  second.curveId = 62;
  second.sourceComponent = 2;
  second.sourceSheet = 3;
  second.proposalId = 72;
  second.proposalSeedId = 82;
  second.proposalSide = 2;
  second.proposalBoundarySegment = 92;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {first, second});

  int stitchedUndirectedEdges = 0;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id >= halfedge.twin) {
      continue;
    }
    const auto &from = complex.nodes[static_cast<std::size_t>(halfedge.from)];
    const auto &to = complex.nodes[static_cast<std::size_t>(halfedge.to)];
    if (from.occurrences.size() != 2U || to.occurrences.size() != 2U) {
      continue;
    }
    ++stitchedUndirectedEdges;
    ASSERT_EQ(halfedge.provenance.size(), 2U);
    std::set<int> sourceArcs;
    std::set<int> sourceFaces;
    std::set<int> strands;
    std::set<int> provenances;
    std::set<int> railIds;
    std::set<int> curveIds;
    std::set<int> proposalIds;
    for (const auto &value : halfedge.provenance) {
      sourceArcs.insert(value.sourceArc);
      sourceFaces.insert(value.sourceFace);
      strands.insert(value.strand);
      provenances.insert(value.provenance);
      railIds.insert(value.railId);
      curveIds.insert(value.curveId);
      proposalIds.insert(value.proposalId);
      EXPECT_EQ(value.sourceComponent, 2);
      EXPECT_EQ(value.sourceSheet, 3);
    }
    EXPECT_EQ(sourceArcs, (std::set<int>{20, 21}));
    EXPECT_EQ(sourceFaces, (std::set<int>{0, 1}));
    EXPECT_EQ(strands, (std::set<int>{31, 32}));
    EXPECT_EQ(provenances, (std::set<int>{41, 42}));
    EXPECT_EQ(railIds, (std::set<int>{51, 52}));
    EXPECT_EQ(curveIds, (std::set<int>{61, 62}));
    EXPECT_EQ(proposalIds, (std::set<int>{71, 72}));
    EXPECT_TRUE(halfedge.hardFeature);
  }
  EXPECT_EQ(stitchedUndirectedEdges, 1);
  EXPECT_EQ(complex.diagnostics.incompleteArcChains, 0);
}

TEST(SurfaceArrangementPhase16,
     FaceLabelsMergeCoincidentSharedEdgeSegmentsOnTheSameSheet) {
  const auto fixture = unit_square_two_triangles();
  auto first = make_face_arc(30, 0, {0.0, 0.25, 0.75},
                             {0.0, 0.75, 0.25}, 0, true);
  auto second = make_face_arc(31, 1, {0.25, 0.0, 0.75},
                              {0.75, 0.0, 0.25}, 1, false);

  const std::vector<int> components = {2, 2};
  const std::vector<int> sheets = {5, 5};
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {first, second}, options);

  ASSERT_EQ(complex.nodes.size(), 2U);
  for (const auto &node : complex.nodes) {
    EXPECT_EQ(node.sourceComponent, 2);
    EXPECT_EQ(node.sourceSheet, 5);
    EXPECT_EQ(node.occurrences.size(), 2U);
  }
  ASSERT_EQ(complex.halfedges.size(), 2U);
  ASSERT_EQ(complex.halfedges.front().provenance.size(), 2U);
  EXPECT_EQ(complex.halfedges.front().sourceComponent, 2);
  EXPECT_EQ(complex.halfedges.front().sourceSheet, 5);
}

TEST(SurfaceArrangementPhase16,
     AdjacentSourceVertexChartsMergeAcrossDifferentLocalSheetLabels) {
  const auto fixture = unit_square_two_triangles();
  auto first = make_face_arc(40, 0, {0.0, 1.0, 0.0},
                             {0.50, 0.25, 0.25}, 0, false);
  auto second = make_face_arc(41, 1, {1.0, 0.0, 0.0},
                              {0.50, 0.25, 0.25}, 1, false);

  const std::vector<int> components = {2, 2};
  const std::vector<int> sheets = {5, 6};
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {first, second}, options);

  ASSERT_EQ(complex.nodes.size(), 3U);
  int sharedVertexNode = -1;
  for (const auto &node : complex.nodes) {
    const Eigen::RowVector3d position =
        directional::geometry::surface_arrangement_detail::node_position(
            fixture.vertices, fixture.faces, node);
    if ((position - fixture.vertices.row(1)).norm() <= 1.0e-12) {
      sharedVertexNode = node.id;
      EXPECT_EQ(node.sourceComponent, 2);
      EXPECT_EQ(node.occurrences.size(), 2U);
    }
  }
  ASSERT_GE(sharedVertexNode, 0);
  EXPECT_EQ(2, std::count_if(
                   complex.halfedges.begin(), complex.halfedges.end(),
                   [&](const auto &halfedge) {
                     return halfedge.from == sharedVertexNode;
                   }));
}

TEST(SurfaceArrangementPhase16,
     DifferentPinchedSourceVertexFansRemainSeparate) {
  TriangleFixture fixture;
  fixture.vertices.resize(5, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                     -1.0, 0.0, 0.0,
                      0.0,-1.0, 0.0;
  fixture.faces.resize(4, 3);
  fixture.faces << 0, 1, 2,
                   1, 3, 2,
                   2, 3, 4,
                   0, 4, 3;

  auto first = make_face_arc(50, 0, {1.0, 0.0, 0.0},
                             {0.50, 0.25, 0.25}, 0, false);
  auto second = make_face_arc(51, 3, {1.0, 0.0, 0.0},
                              {0.50, 0.25, 0.25}, 1, false);

  const std::vector<int> components = {2, 2, 2, 2};
  const std::vector<int> sheets = {5, 5, 6, 6};
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {first, second}, options);

  ASSERT_EQ(complex.nodes.size(), 4U);
  int sourceVertexNodes = 0;
  std::set<int> sourceVertexSheets;
  for (const auto &node : complex.nodes) {
    const Eigen::RowVector3d position =
        directional::geometry::surface_arrangement_detail::node_position(
            fixture.vertices, fixture.faces, node);
    if ((position - fixture.vertices.row(0)).norm() <= 1.0e-12) {
      ++sourceVertexNodes;
      sourceVertexSheets.insert(node.sourceSheet);
      EXPECT_EQ(node.occurrences.size(), 1U);
    }
  }
  EXPECT_EQ(sourceVertexNodes, 2);
  EXPECT_EQ(sourceVertexSheets, (std::set<int>{5, 6}));
  EXPECT_EQ(complex.halfedges.size(), 4U);
}

TEST(SurfaceArrangementPhase16,
     SharedSourceVertexUsesOneGlobalNodeWithAllFaceOccurrences) {
  TriangleFixture fixture;
  fixture.vertices.resize(5, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                     -1.0, 0.0, 0.0,
                      0.0,-1.0, 0.0;
  fixture.faces.resize(4, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3,
                   0, 3, 4,
                   0, 4, 1;

  std::vector<directional::geometry::SurfaceArrangementArc> arcs;
  for (int face = 0; face < 4; ++face) {
    auto arc = make_face_arc(100 + face, face, {1.0, 0.0, 0.0},
                             {0.5, 0.5, 0.0}, face % 2);
    arc.provenance = 200 + face;
    arcs.push_back(arc);
  }

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  int matchingNodes = 0;
  for (const auto &node : complex.nodes) {
    if ((fixture.vertices.row(0) -
         (node.barycentric[0] * fixture.vertices.row(node.sourceFace >= 0 ? fixture.faces(node.sourceFace, 0) : 0) +
          node.barycentric[1] * fixture.vertices.row(node.sourceFace >= 0 ? fixture.faces(node.sourceFace, 1) : 0) +
          node.barycentric[2] * fixture.vertices.row(node.sourceFace >= 0 ? fixture.faces(node.sourceFace, 2) : 0))).norm() < 1.0e-10) {
      ++matchingNodes;
      EXPECT_EQ(node.occurrences.size(), 4U);
      std::set<int> faces;
      for (const auto &occurrence : node.occurrences) {
        faces.insert(occurrence.sourceFace);
      }
      EXPECT_EQ(faces, (std::set<int>{0, 1, 2, 3}));
    }
  }
  EXPECT_EQ(matchingNodes, 1);
}

TEST(SurfaceArrangementPhase16,
     FaceInteriorKeysSanitizeSubToleranceBarycentricNoise) {
  const auto fixture = unit_triangle();
  auto first = make_arc(300, {0.2, 0.3, 0.5}, {0.4, 0.3, 0.3}, 0);
  auto second = make_arc(301, {0.2 + 2.0e-12, 0.3 - 1.0e-12,
                               0.5 - 1.0e-12},
                         {0.1, 0.4, 0.5}, 1);

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {first, second});

  int matching = 0;
  for (const auto &node : complex.nodes) {
    if ((node.barycentric - Eigen::RowVector3d(0.2, 0.3, 0.5)).norm() <
        1.0e-9) {
      ++matching;
    }
  }
  EXPECT_EQ(matching, 1);
}

TEST(SurfaceArrangementPhase16,
     AuthoritativeTopologyDiagnosticsMatchSingleDiskSource) {
  const auto fixture = unit_triangle();
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});

  EXPECT_TRUE(complex.diagnostics.incidenceValid);
  EXPECT_TRUE(complex.diagnostics.orientationValid);
  EXPECT_TRUE(complex.diagnostics.boundaryLoopsValid);
  EXPECT_TRUE(complex.diagnostics.eulerCharacteristicValid);
  EXPECT_TRUE(complex.diagnostics.topologyValid);
  EXPECT_EQ(complex.diagnostics.connectedComponentCount, 1);
  EXPECT_EQ(complex.diagnostics.sourceConnectedComponentCount, 1);
  EXPECT_EQ(complex.diagnostics.boundaryLoopCount, 1);
  EXPECT_EQ(complex.diagnostics.sourceBoundaryLoopCount, 1);
  EXPECT_EQ(complex.diagnostics.eulerCharacteristic, 1);
  EXPECT_EQ(complex.diagnostics.sourceEulerCharacteristic, 1);
}

TEST(SurfaceArrangementPhase16,
     AuthoritativeTopologyDiagnosticsHandleDisconnectedSourceComponents) {
  TriangleFixture fixture;
  fixture.vertices.resize(6, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                      3.0, 0.0, 0.0,
                      4.0, 0.0, 0.0,
                      3.0, 1.0, 0.0;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2,
                   3, 4, 5;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});

  EXPECT_TRUE(complex.diagnostics.topologyValid);
  EXPECT_EQ(complex.diagnostics.connectedComponentCount, 2);
  EXPECT_EQ(complex.diagnostics.sourceConnectedComponentCount, 2);
  EXPECT_EQ(complex.diagnostics.boundaryLoopCount, 2);
  EXPECT_EQ(complex.diagnostics.sourceBoundaryLoopCount, 2);
  EXPECT_EQ(complex.diagnostics.eulerCharacteristic, 2);
  EXPECT_EQ(complex.diagnostics.sourceEulerCharacteristic, 2);
}

TEST(SurfaceArrangementPhase16,
     NestedCyclesAreClassifiedAsNonDiskInsteadOfDefaultDisk) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(400, {0.70, 0.20, 0.10}, {0.50, 0.40, 0.10}, 0),
      make_arc(401, {0.50, 0.40, 0.10}, {0.30, 0.40, 0.30}, 1),
      make_arc(402, {0.30, 0.40, 0.30}, {0.50, 0.20, 0.30}, 0),
      make_arc(403, {0.50, 0.20, 0.30}, {0.70, 0.20, 0.10}, 1),
      make_arc(410, {0.55, 0.27, 0.18}, {0.47, 0.35, 0.18}, 0),
      make_arc(411, {0.47, 0.35, 0.18}, {0.39, 0.35, 0.26}, 1),
      make_arc(412, {0.39, 0.35, 0.26}, {0.47, 0.27, 0.26}, 0),
      make_arc(413, {0.47, 0.27, 0.26}, {0.55, 0.27, 0.18}, 1)};
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs, options);

  EXPECT_TRUE(std::any_of(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && !cell.disk &&
               cell.boundaryComponentCount == 2 &&
               cell.eulerCharacteristic == 0 &&
               cell.cellClass == directional::geometry::
                   SurfaceArrangementCellClass::NonDisk;
      }));
}

TEST(SurfaceArrangementPhase16,
     HardBarrierCrossingsAreUniqueTransverseAndLocalizedToIncidentCells) {
  const auto fixture = unit_triangle();
  auto hard = make_arc(500, {0.70, 0.10, 0.20}, {0.30, 0.50, 0.20}, 0, true);
  auto crossing =
      make_arc(501, {0.60, 0.30, 0.10}, {0.40, 0.30, 0.30}, 1, false);
  auto overlap =
      make_arc(502, {0.60, 0.20, 0.20}, {0.40, 0.40, 0.20}, 0, false);

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {hard, crossing, overlap});

  EXPECT_EQ(complex.diagnostics.hardBarrierCrossings, 1);
  EXPECT_EQ(static_cast<int>(std::count_if(
                complex.nodes.begin(), complex.nodes.end(),
                [](const auto &node) { return node.hardBarrierCrossing; })),
            1);
}

TEST(SurfaceArrangementPhase16,
     PeakMemoryMeasurementUsesOwnedCapacityAndBoundsRetainedStorage) {
  const auto fixture = unit_triangle();
  std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_arc(600, {0.50, 0.50, 0.00}, {0.25, 0.25, 0.50}, 0),
      make_arc(601, {0.50, 0.00, 0.50}, {0.25, 0.50, 0.25}, 1)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);

  EXPECT_GT(complex.diagnostics.inputMemoryBytes, 0U);
  EXPECT_GT(complex.diagnostics.retainedMemoryBytes, 0U);
  EXPECT_GE(complex.diagnostics.peakMemoryBytes,
            complex.diagnostics.retainedMemoryBytes);
  EXPECT_DOUBLE_EQ(
      complex.diagnostics.measuredMemoryRatio,
      static_cast<double>(complex.diagnostics.peakMemoryBytes) /
          static_cast<double>(complex.diagnostics.inputMemoryBytes));
  EXPECT_DOUBLE_EQ(complex.diagnostics.memoryRatioEstimate,
                   complex.diagnostics.measuredMemoryRatio);
}

TEST(SurfaceArrangementPhase16,
     ShortParallelSegmentsUseSpatialCollinearityTolerance) {
  using directional::geometry::surface_arrangement_detail::Segment2;
  using directional::geometry::surface_arrangement_detail::
      segment_intersection_params;

  Segment2 first;
  first.start << 0.0, 0.0;
  first.end << 1.0e-6, 0.0;

  Segment2 second;
  second.start << 0.0, 2.5e-7;
  second.end << 1.0e-6, 2.5e-7;

  double firstParameter = 0.0;
  double secondParameter = 0.0;
  Eigen::Vector2d point = Eigen::Vector2d::Zero();
  EXPECT_FALSE(segment_intersection_params(
      first, second, firstParameter, secondParameter, point));
}

TEST(SurfaceArrangementPhase16,
     CollinearToleranceDoesNotIntersectDisjointFiniteSegments) {
  using directional::geometry::surface_arrangement_detail::Segment2;
  using directional::geometry::surface_arrangement_detail::
      segment_intersection_params;

  Segment2 first;
  first.start << 0.0, 0.0;
  first.end << 1.0, 0.0;

  Segment2 second;
  second.start << -1.0e-6, 5.0e-13;
  second.end << -2.0e-13, 5.0e-13;

  double firstParameter = 0.0;
  double secondParameter = 0.0;
  Eigen::Vector2d point = Eigen::Vector2d::Zero();
  EXPECT_FALSE(segment_intersection_params(
      first, second, firstParameter, secondParameter, point));
}

TEST(SurfaceArrangementPhase16,
     SplitProvenanceRemainsWithinFiniteSourceArcDomain) {
  const auto fixture = unit_triangle();
  auto primary =
      make_arc(700, {0.8, 0.2, 0.0}, {0.2, 0.8, 0.0}, 0);
  auto nearDisjoint = make_arc(
      701, {0.8999999999995, 0.1, 5.0e-13},
      {0.8000000000003, 0.1999999999998, 5.0e-13}, 1);

  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {primary, nearDisjoint}, options);

  bool sawPrimary = false;
  bool sawNearDisjoint = false;
  for (const auto &halfedge : complex.halfedges) {
    for (const auto &provenance : halfedge.provenance) {
      sawPrimary = sawPrimary || provenance.sourceArc == 700;
      sawNearDisjoint = sawNearDisjoint || provenance.sourceArc == 701;
      EXPECT_GE(provenance.sourceT0, -1.0e-12);
      EXPECT_LE(provenance.sourceT0, 1.0 + 1.0e-12);
      EXPECT_GE(provenance.sourceT1, -1.0e-12);
      EXPECT_LE(provenance.sourceT1, 1.0 + 1.0e-12);
    }
  }
  EXPECT_TRUE(sawPrimary);
  EXPECT_TRUE(sawNearDisjoint);
}

TEST(SurfaceArrangementPhase16,
     CurvedMultiFaceFixturePreservesStitchedTopologyAndEulerCharacteristic) {
  auto fixture = unit_square_two_triangles();
  fixture.vertices(3, 2) = 0.4;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});

  EXPECT_TRUE(complex.diagnostics.incidenceValid);
  EXPECT_TRUE(complex.diagnostics.orientationValid);
  EXPECT_TRUE(complex.diagnostics.eulerCharacteristicValid);
  EXPECT_TRUE(complex.diagnostics.topologyValid);
  EXPECT_EQ(complex.diagnostics.eulerCharacteristic, 1);
  EXPECT_EQ(complex.diagnostics.sourceEulerCharacteristic, 1);
  EXPECT_EQ(complex.diagnostics.connectedComponentCount, 1);
  EXPECT_EQ(complex.diagnostics.boundaryLoopCount, 1);
  EXPECT_TRUE(std::any_of(
      complex.nodes.begin(), complex.nodes.end(), [](const auto &node) {
        return node.occurrences.size() == 2U;
      }));
}

TEST(SurfaceArrangementPhase16,
     AdjacentPerFaceChartsShareOneCanonicalCellOwnershipClass) {
  const auto fixture = unit_square_two_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 1};
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {}, options);

  const auto cell = std::find_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &candidate) {
        return !candidate.boundaryCycle && candidate.sourceFaces.size() == 2U;
      });
  ASSERT_NE(cell, complex.cells.end());
  ASSERT_TRUE(cell->sourceOwnershipClass.valid);
  ASSERT_EQ(2U, cell->sourceCharts.size());
  EXPECT_EQ((std::set<int>{0, 1}),
            (std::set<int>{cell->sourceCharts[0].localSheet,
                           cell->sourceCharts[1].localSheet}));
  for (const int halfedgeId : cell->halfedges) {
    const auto &edge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    EXPECT_TRUE(std::binary_search(
        cell->sourceCharts.begin(), cell->sourceCharts.end(),
        directional::geometry::SurfaceCellSourceChart{
            edge.sourceComponent, edge.sourceFace, edge.sourceSheet}));
  }
}

TEST(SurfaceArrangementPhase16,
     DanglingBridgeRetainsCompleteCellOwnershipWithoutCycleDecomposition) {
  const auto fixture = unit_triangle();
  auto dangling = make_arc(500, {0.50, 0.50, 0.00},
                           {0.40, 0.30, 0.30}, 0);
  dangling.layoutSupport = true;
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {dangling});

  EXPECT_TRUE(complex.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             complex.diagnostics.incidenceFailure);
  EXPECT_EQ(complex.diagnostics.incidenceFailure,
            directional::geometry::SurfaceArrangementIncidenceFailure::None);
  EXPECT_TRUE(std::all_of(
      complex.halfedges.begin(), complex.halfedges.end(),
      [&](const auto &halfedge) {
        return halfedge.cell >= 0 &&
               halfedge.cell < static_cast<int>(complex.cells.size());
      }));
  EXPECT_TRUE(std::any_of(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.bridgeExcursion && !cell.disk &&
               cell.cellClass ==
                   directional::geometry::SurfaceArrangementCellClass::NonDisk;
      }));
  EXPECT_EQ(complex.diagnostics.repeatedNodeCycleCount, 0);
  EXPECT_EQ(complex.diagnostics.repeatedEdgeCycleCount, 0);
}

TEST(SurfaceArrangementPhase16,
     IsolatedSupportBridgeReceivesTransactionalCellOwnership) {
  const auto fixture = unit_triangle();
  auto isolated = make_arc(501, {0.80, 0.10, 0.10},
                           {0.60, 0.30, 0.10}, 0);
  isolated.layoutSupport = true;
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {isolated});

  EXPECT_TRUE(complex.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             complex.diagnostics.incidenceFailure);
  const auto support = std::find_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return cell.supportOnlyCycle;
      });
  ASSERT_NE(support, complex.cells.end());
  EXPECT_FALSE(support->disk);
  EXPECT_FALSE(support->boundaryCycle);
  ASSERT_EQ(support->halfedges.size(), 2U);
  EXPECT_EQ(complex.halfedges[static_cast<std::size_t>(support->halfedges[0])]
                .twin,
            support->halfedges[1]);
  EXPECT_TRUE(std::all_of(
      complex.halfedges.begin(), complex.halfedges.end(),
      [&](const auto &halfedge) {
        return halfedge.cell >= 0 &&
               halfedge.cell < static_cast<int>(complex.cells.size());
      }));
  EXPECT_TRUE(std::any_of(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) {
                            return cell.boundaryCycle;
                          }));
}

TEST(SurfaceArrangementPhase16,
     DirectedWedgeIncidenceFormsACompletePermutation) {
  const auto fixture = unit_square_two_triangles();
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});

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
  EXPECT_NE(complex.diagnostics.directedIncidenceHash, 0U);

  std::vector<int> predecessorCount(complex.halfedges.size(), 0);
  for (const auto &halfedge : complex.halfedges) {
    ASSERT_GE(halfedge.twin, 0);
    ASSERT_LT(halfedge.twin, static_cast<int>(complex.halfedges.size()));
    ASSERT_GE(halfedge.next, 0);
    ASSERT_LT(halfedge.next, static_cast<int>(complex.halfedges.size()));
    EXPECT_EQ(complex.halfedges[static_cast<std::size_t>(halfedge.twin)].twin,
              halfedge.id);
    EXPECT_EQ(complex.halfedges[static_cast<std::size_t>(halfedge.next)].from,
              halfedge.to);
    ++predecessorCount[static_cast<std::size_t>(halfedge.next)];
  }
  EXPECT_TRUE(std::all_of(predecessorCount.begin(), predecessorCount.end(),
                          [](const int count) { return count == 1; }));

  for (const auto &cell : complex.cells) {
    std::set<int> nodes;
    std::set<std::pair<int, int>> edges;
    for (const int halfedgeId : cell.halfedges) {
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      EXPECT_TRUE(nodes.insert(halfedge.from).second);
      EXPECT_TRUE(edges.insert({std::min(halfedge.from, halfedge.to),
                                std::max(halfedge.from, halfedge.to)})
                      .second);
    }
  }
}

TEST(SurfaceArrangementPhase16,
     AdjacentLocalSheetChartsShareDirectedIntrinsicWedges) {
  const auto fixture = unit_square_two_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {3, 11};
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {}, options);

  EXPECT_TRUE(complex.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             complex.diagnostics.incidenceFailure);
  EXPECT_TRUE(complex.diagnostics.topologyValid);
  EXPECT_EQ(complex.diagnostics.incidenceFailure,
            directional::geometry::SurfaceArrangementIncidenceFailure::None);
  EXPECT_EQ(complex.diagnostics.successorMissingCount, 0);
  EXPECT_EQ(complex.diagnostics.successorAmbiguityCount, 0);
  const auto interior = std::find_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.sourceFaces.size() == 2U;
      });
  ASSERT_NE(interior, complex.cells.end());
  ASSERT_EQ(interior->sourceCharts.size(), 2U);
  EXPECT_NE(interior->sourceCharts[0].localSheet,
            interior->sourceCharts[1].localSheet);
}

TEST(SurfaceArrangementPhase16,
     NonManifoldSourceEdgeFailsClosedWithTypedIncidenceEvidence) {
  TriangleFixture fixture;
  fixture.vertices.resize(5, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.5, 1.0, 0.0,
                      0.5, -1.0, 0.0,
                      0.5, 0.0, 1.0;
  fixture.faces.resize(3, 3);
  fixture.faces << 0, 1, 2,
                   1, 0, 3,
                   0, 1, 4;
  const std::vector<int> components = {0, 0, 0};
  const std::vector<int> sheets = {0, 1, 2};
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
  const std::vector<directional::geometry::SurfaceArrangementArc> arcs = {
      make_face_arc(900, 0, {0.5, 0.5, 0.0},
                    {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0}, 0),
      make_face_arc(901, 1, {0.5, 0.5, 0.0},
                    {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0}, 0),
      make_face_arc(902, 2, {0.5, 0.5, 0.0},
                    {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0}, 0)};

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs, options);

  EXPECT_FALSE(complex.diagnostics.topologyValid);
  EXPECT_FALSE(complex.diagnostics.incidenceValid);
  EXPECT_NE(complex.diagnostics.incidenceFailure,
            directional::geometry::SurfaceArrangementIncidenceFailure::None);
  EXPECT_TRUE(complex.cells.empty());
}

TEST(SurfaceArrangementPhase16,
     DisconnectedCloseSheetsKeepDistinctCanonicalOwnershipClasses) {
  TriangleFixture fixture;
  fixture.vertices.resize(6, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                      0.0, 0.0, 1.0e-6,
                      1.0, 0.0, 1.0e-6,
                      0.0, 1.0, 1.0e-6;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2, 3, 4, 5;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {}, options);
  std::vector<directional::geometry::SurfaceCellCanonicalIdentity> ownership;
  for (const auto &cell : complex.cells) {
    if (!cell.boundaryCycle) {
      ASSERT_TRUE(cell.sourceOwnershipClass.valid);
      ownership.push_back(cell.sourceOwnershipClass);
    }
  }
  ASSERT_EQ(2U, ownership.size());
  EXPECT_NE(ownership[0], ownership[1]);
}

TEST(SurfaceArrangementPhase16,
     UnlabelledTopologyDerivesCanonicalOwnershipRegistry) {
  const auto fixture = unit_square_two_triangles();
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});

  EXPECT_TRUE(directional::geometry::validate_surface_cell_ownership_registry(
      complex));
  ASSERT_FALSE(complex.sourceOwnershipRegistry.empty());
  const auto interior = std::find_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.sourceFaces.size() == 2U;
      });
  ASSERT_NE(interior, complex.cells.end());
  ASSERT_TRUE(interior->sourceOwnershipClass.valid);
  EXPECT_EQ(2U, interior->sourceOwnershipClass.values.size());
  ASSERT_EQ(2U, interior->sourceCharts.size());
  EXPECT_EQ(0, interior->sourceCharts[0].localSheet);
  EXPECT_EQ(0, interior->sourceCharts[1].localSheet);
  EXPECT_NE(interior->sourceCharts[0].sourceFace,
            interior->sourceCharts[1].sourceFace);
  const auto *record = directional::geometry::find_surface_cell_ownership_class(
      complex, interior->sourceOwnershipClass);
  ASSERT_NE(nullptr, record);
  EXPECT_EQ(2U, record->exactCharts.size());
}

TEST(SurfaceArrangementPhase16,
     OwnershipRegistryStoresClassMembershipOnceForRepeatedCells) {
  const auto fixture = unit_square_two_triangles();
  auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {});
  const auto interior = std::find_if(
      complex.cells.begin(), complex.cells.end(),
      [](const auto &cell) { return !cell.boundaryCycle; });
  ASSERT_NE(interior, complex.cells.end());
  const auto prototype = *interior;
  for (int copy = 0; copy < 128; ++copy) {
    auto cell = prototype;
    cell.id = static_cast<int>(complex.cells.size());
    complex.cells.push_back(std::move(cell));
  }

  ASSERT_TRUE(directional::geometry::validate_surface_cell_ownership_registry(
      complex));
  std::size_t perCellOwnershipWords = 0U;
  for (const auto &cell : complex.cells) {
    if (cell.sourceOwnershipClass.valid) {
      perCellOwnershipWords += cell.sourceOwnershipClass.values.size();
      EXPECT_EQ(2U, cell.sourceOwnershipClass.values.size());
    }
  }
  std::size_t registryMembershipWords = 0U;
  for (const auto &record : complex.sourceOwnershipRegistry) {
    registryMembershipWords += record.canonicalMembership.values.size();
  }
  EXPECT_LT(registryMembershipWords, perCellOwnershipWords);
}

TEST(SurfaceArrangementPhase16,
     OwnershipClassOrdinalIsInvariantToSourceFaceRowOrder) {
  const auto fixture = unit_square_two_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {7, 11};
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
  const auto first = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {}, options);

  Eigen::MatrixXi reorderedFaces = fixture.faces;
  reorderedFaces.row(0).swap(reorderedFaces.row(1));
  const std::vector<int> reorderedComponents = {0, 0};
  const std::vector<int> reorderedSheets = {11, 7};
  directional::geometry::SurfaceArrangementOptions reorderedOptions;
  reorderedOptions.sourceFaceComponents = &reorderedComponents;
  reorderedOptions.sourceFaceSheets = &reorderedSheets;
  const auto second = directional::geometry::build_surface_cell_complex(
      fixture.vertices, reorderedFaces, {}, reorderedOptions);

  ASSERT_TRUE(first.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             first.diagnostics.incidenceFailure);
  ASSERT_TRUE(second.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             second.diagnostics.incidenceFailure);
  EXPECT_EQ(first.diagnostics.directedIncidenceHash,
            second.diagnostics.directedIncidenceHash);
  ASSERT_EQ(first.sourceOwnershipRegistry.size(),
            second.sourceOwnershipRegistry.size());
  for (std::size_t index = 0; index < first.sourceOwnershipRegistry.size();
       ++index) {
    EXPECT_EQ(first.sourceOwnershipRegistry[index].canonicalMembership,
              second.sourceOwnershipRegistry[index].canonicalMembership);
  }
}

TEST(SurfaceArrangementPhase16,
     WholeMeshOrientationReversalPreservesDirectedIncidence) {
  const auto fixture = unit_square_two_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {5, 9};
  directional::geometry::SurfaceArrangementOptions options;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
  const auto forward = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, {}, options);

  Eigen::MatrixXi reversed = fixture.faces;
  for (int face = 0; face < reversed.rows(); ++face) {
    std::swap(reversed(face, 1), reversed(face, 2));
  }
  const auto backward = directional::geometry::build_surface_cell_complex(
      fixture.vertices, reversed, {}, options);

  ASSERT_TRUE(forward.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             forward.diagnostics.incidenceFailure);
  ASSERT_TRUE(backward.diagnostics.incidenceValid)
      << directional::geometry::surface_arrangement_incidence_failure_name(
             backward.diagnostics.incidenceFailure);
  EXPECT_EQ(forward.diagnostics.directedIncidenceHash,
            backward.diagnostics.directedIncidenceHash);
  EXPECT_EQ(forward.cells.size(), backward.cells.size());
}

TEST(SurfaceArrangementPhase16,
     BunnySingularityFanUsesIntrinsicSourceVertexRotation) {
  const BunnySingularityFanFixture fixture =
      bunny_singularity_fan_fixture();
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  options.sourceFaceComponents = &fixture.sourceComponents;
  options.sourceFaceSheets = &fixture.sourceSheets;

  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, fixture.arcs, options);

  EXPECT_TRUE(complex.diagnostics.embeddingValid);
  EXPECT_TRUE(complex.diagnostics.cellsDiskValid);
  EXPECT_TRUE(complex.diagnostics.topologyValid);

  int center = -1;
  for (const auto &node : complex.nodes) {
    for (const auto &occurrence : node.occurrences) {
      for (int corner = 0; corner < 3; ++corner) {
        if (fixture.faces(occurrence.sourceFace, corner) == 2 &&
            occurrence.barycentric[corner] >= 1.0 - 1.0e-10) {
          ASSERT_TRUE(center < 0 || center == node.id);
          center = node.id;
        }
      }
    }
  }
  ASSERT_GE(center, 0);

  int centerCells = 0;
  for (const auto &cell : complex.cells) {
    bool touchesCenter = false;
    for (const int halfedgeId : cell.halfedges) {
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      touchesCenter = touchesCenter || halfedge.from == center ||
                      halfedge.to == center;
    }
    if (touchesCenter && !cell.boundaryCycle) {
      ++centerCells;
      std::set<int> boundaryNodes;
      std::set<int> halfedges;
      for (const int halfedgeId : cell.halfedges) {
        const auto &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        EXPECT_TRUE(halfedges.insert(halfedgeId).second);
        EXPECT_EQ(halfedges.count(halfedge.twin), 0U)
            << "a local singular sector must not contain both sides of a "
               "required support";
        EXPECT_TRUE(boundaryNodes.insert(halfedge.from).second)
            << "a local singular sector must have a simple boundary";
      }
      EXPECT_TRUE(cell.disk);
      EXPECT_EQ(cell.boundaryComponentCount, 1);
      EXPECT_EQ(cell.eulerCharacteristic, 1);
    }
  }
  EXPECT_EQ(centerCells, 3);
}


TEST(SourceChartTransitionsR1,
     SharedSourceEdgeRebindsWithCanonicalEndpointOrientation) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {4, 4};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  ASSERT_TRUE(graph.available());
  ASSERT_EQ(2U, graph.transitions().size());
  EXPECT_EQ(graph.chart_component(0), graph.chart_component(1));

  directional::geometry::SurfacePoint first;
  first.face = 0;
  first.component = 0;
  first.sheet = 4;
  first.barycentric << 0.0, 0.25, 0.75;

  directional::geometry::SurfacePoint second;
  ASSERT_TRUE(graph.rebind(first, 1, second));
  EXPECT_EQ(1, second.face);
  EXPECT_EQ(0, second.component);
  EXPECT_EQ(4, second.sheet);
  EXPECT_NEAR(0.75, second.barycentric(0), 1.0e-12);
  EXPECT_NEAR(0.25, second.barycentric(1), 1.0e-12);
  EXPECT_NEAR(0.0, second.barycentric(2), 1.0e-12);
  EXPECT_EQ(graph.resolve_entity(first).canonical,
            graph.resolve_entity(second).canonical);

  const auto &forward = graph.transitions().front();
  const auto reverse = std::find_if(
      graph.transitions().begin(), graph.transitions().end(),
      [&](const auto &candidate) {
        return candidate.from == forward.to && candidate.to == forward.from;
      });
  ASSERT_NE(reverse, graph.transitions().end());
  EXPECT_EQ(forward.sharedEntity.canonical, reverse->sharedEntity.canonical);
  EXPECT_EQ(forward.orientation, reverse->orientation);
}

TEST(SourceChartTransitionsR1,
     ExactManifoldAdjacencyCrossesLocalSheetLabels) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {4, 9};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  ASSERT_TRUE(graph.available());
  ASSERT_EQ(2U, graph.transitions().size());
  EXPECT_EQ(graph.chart_component(0), graph.chart_component(1));

  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 0;
  point.sheet = 4;
  point.barycentric << 0.0, 0.25, 0.75;
  directional::geometry::SurfacePoint rebound;
  ASSERT_TRUE(graph.rebind(point, 1, rebound));
  EXPECT_EQ(1, rebound.face);
  EXPECT_EQ(0, rebound.component);
  EXPECT_EQ(9, rebound.sheet);
  EXPECT_NEAR(0.75, rebound.barycentric(0), 1.0e-12);
  EXPECT_NEAR(0.25, rebound.barycentric(1), 1.0e-12);
  EXPECT_NEAR(0.0, rebound.barycentric(2), 1.0e-12);
  EXPECT_EQ(graph.resolve_entity(point).canonical,
            graph.resolve_entity(rebound).canonical);
}

TEST(SourceChartTransitionsR1,
     SourceVertexFanCrossesAdjacentLocalSheetLabels) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {2, 6};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 0;
  point.sheet = 2;
  point.barycentric << 0.0, 1.0, 0.0;
  directional::geometry::SurfacePoint rebound;
  ASSERT_TRUE(graph.rebind(point, 1, rebound));
  EXPECT_EQ(6, rebound.sheet);
  EXPECT_EQ(graph.resolve_entity(point).canonical,
            graph.resolve_entity(rebound).canonical);
}

TEST(SourceChartTransitionsR1,
     ComponentMismatchBlocksExactManifoldAdjacency) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  const std::vector<int> components = {0, 1};
  const std::vector<int> sheets = {4, 9};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  ASSERT_TRUE(graph.available());
  EXPECT_TRUE(graph.transitions().empty());
  EXPECT_NE(graph.chart_component(0), graph.chart_component(1));
  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 0;
  point.sheet = 4;
  point.barycentric << 0.0, 0.5, 0.5;
  directional::geometry::SurfacePoint rebound;
  EXPECT_FALSE(graph.rebind(point, 1, rebound));
}

TEST(SourceChartTransitionsR1,
     NonManifoldSharedEdgeDoesNotCreateTransition) {
  Eigen::MatrixXi faces(3, 3);
  faces << 0, 1, 2,
           2, 1, 3,
           1, 2, 4;
  const std::vector<int> components = {0, 0, 0};
  const std::vector<int> sheets = {0, 1, 2};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  ASSERT_TRUE(graph.available());
  EXPECT_TRUE(graph.transitions().empty());
  EXPECT_NE(graph.chart_component(0), graph.chart_component(1));
  EXPECT_NE(graph.chart_component(1), graph.chart_component(2));
}

TEST(SourceChartTransitionsR1, HardRailSplitsAdjacentProjectionCharts) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 1};
  const std::uint64_t hardEdge =
      (static_cast<std::uint64_t>(1U) << 32U) | 2U;
  const std::set<std::uint64_t> hardEdges = {hardEdge};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets, &hardEdges);

  ASSERT_TRUE(graph.available());
  EXPECT_TRUE(graph.transitions().empty());
  EXPECT_NE(graph.chart_component(0), graph.chart_component(1));

  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 0;
  point.sheet = 0;
  point.barycentric << 0.0, 0.5, 0.5;
  directional::geometry::SurfacePoint rebound;
  EXPECT_FALSE(graph.rebind(point, 1, rebound));
}

TEST(SourceChartTransitionsR1,
     SourceVertexFansRespectTwoHardRailBarriers) {
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 2,
           0, 2, 3,
           0, 3, 4,
           0, 4, 1;
  const std::vector<int> components = {0, 0, 0, 0};
  const std::vector<int> sheets = {0, 0, 0, 0};
  const auto edgeKey = [](const int a, const int b) {
    const auto low = static_cast<std::uint32_t>(std::min(a, b));
    const auto high = static_cast<std::uint32_t>(std::max(a, b));
    return (static_cast<std::uint64_t>(low) << 32U) | high;
  };
  const std::set<std::uint64_t> hardEdges = {edgeKey(0, 2), edgeKey(0, 4)};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets, &hardEdges);

  directional::geometry::SurfacePoint left;
  left.face = 0;
  left.component = 0;
  left.sheet = 0;
  left.barycentric << 1.0, 0.0, 0.0;
  directional::geometry::SurfacePoint right = left;
  right.face = 1;
  right.sheet = 0;

  const auto leftEntity = graph.resolve_entity(left);
  const auto rightEntity = graph.resolve_entity(right);
  ASSERT_TRUE(leftEntity.valid());
  ASSERT_TRUE(rightEntity.valid());
  EXPECT_NE(leftEntity.canonical, rightEntity.canonical);
  directional::geometry::SurfacePoint rebound;
  EXPECT_FALSE(graph.rebind(left, 1, rebound));
}

TEST(SourceChartTransitionsR1,
     DisconnectedCloseSheetsNeverShareTransitionComponent) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           3, 4, 5;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  ASSERT_TRUE(graph.available());
  EXPECT_NE(graph.chart_component(0), graph.chart_component(1));
  EXPECT_NE(graph.chart_component_identity(graph.chart_component(0)),
            graph.chart_component_identity(graph.chart_component(1)));
}

TEST(SourceChartTransitionsR1,
     ComponentIdentityIsInvariantToSourceFaceRowPermutation) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           1, 3, 2;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {7, 11};
  const directional::geometry::SourceChartTransitionGraph first(
      faces, components, sheets);

  Eigen::MatrixXi reordered = faces;
  reordered.row(0).swap(reordered.row(1));
  const std::vector<int> reorderedComponents = {0, 0};
  const std::vector<int> reorderedSheets = {11, 7};
  const directional::geometry::SourceChartTransitionGraph second(
      reordered, reorderedComponents, reorderedSheets);

  ASSERT_EQ(first.chart_component(0), first.chart_component(1));
  ASSERT_EQ(second.chart_component(0), second.chart_component(1));
  EXPECT_EQ(first.chart_component_identity(first.chart_component(0)),
            second.chart_component_identity(second.chart_component(0)));
}

TEST(SourceChartTransitionsR1,
     WholeMeshOrientationReversalPreservesCanonicalTransitions) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  Eigen::MatrixXi reversed(2, 3);
  reversed << 0, 2, 1,
              2, 3, 1;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {5, 9};

  const directional::geometry::SourceChartTransitionGraph forward(
      faces, components, sheets);
  const directional::geometry::SourceChartTransitionGraph backward(
      reversed, components, sheets);

  ASSERT_TRUE(forward.available());
  ASSERT_TRUE(backward.available());
  ASSERT_EQ(2U, forward.transitions().size());
  ASSERT_EQ(2U, backward.transitions().size());
  EXPECT_EQ(forward.chart_component_identity(forward.chart_component(0)),
            backward.chart_component_identity(backward.chart_component(0)));

  std::vector<std::uint64_t> forwardHashes;
  std::vector<std::uint64_t> backwardHashes;
  for (const auto &transition : forward.transitions()) {
    forwardHashes.push_back(transition.structuralHash);
  }
  for (const auto &transition : backward.transitions()) {
    backwardHashes.push_back(transition.structuralHash);
  }
  EXPECT_EQ(forwardHashes, backwardHashes);
}

TEST(SourceChartTransitionsR1,
     InconsistentSharedEdgeOrientationRejectsTransitionGraph) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           1, 2, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const directional::geometry::SourceChartTransitionGraph graph(
      faces, components, sheets);

  EXPECT_FALSE(graph.available());
  EXPECT_TRUE(graph.transitions().empty());
}
