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

  EXPECT_LE(complex.diagnostics.memoryRatioEstimate, 10.0);
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
