#include <directional/geometry/PatchDescriptor.h>
#include <directional/geometry/SurfaceComplexSimplification.h>

#include <gtest/gtest.h>

#include <array>
#include <limits>
#include <numeric>
#include <vector>

namespace {

struct Fixture {
  Eigen::MatrixXd V;
  Eigen::MatrixXi F;
  directional::geometry::SurfaceCellComplex complex;
};

Fixture make_patch(const std::vector<int> &sideCounts,
                   const bool hardBarrier = false) {
  const int boundaryCount =
      std::accumulate(sideCounts.begin(), sideCounts.end(), 0);
  Fixture fixture;
  fixture.V.resize(boundaryCount + 1, 3);
  fixture.V.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.14159265358979323846;
  int boundaryVertex = 0;
  for (int side = 0; side < static_cast<int>(sideCounts.size()); ++side) {
    const double firstAngle =
        2.0 * pi * static_cast<double>(side) /
        static_cast<double>(sideCounts.size());
    const double secondAngle =
        2.0 * pi * static_cast<double>((side + 1) % sideCounts.size()) /
        static_cast<double>(sideCounts.size());
    const Eigen::RowVector3d first{std::cos(firstAngle), std::sin(firstAngle),
                                   0.0};
    const Eigen::RowVector3d second{
        std::cos(secondAngle), std::sin(secondAngle), 0.0};
    for (int local = 0; local < sideCounts[static_cast<std::size_t>(side)];
         ++local) {
      const double t = static_cast<double>(local) /
                       static_cast<double>(
                           sideCounts[static_cast<std::size_t>(side)]);
      fixture.V.row(++boundaryVertex) = (1.0 - t) * first + t * second;
    }
  }
  fixture.F.resize(boundaryCount, 3);
  for (int i = 0; i < boundaryCount; ++i) {
    fixture.F.row(i) << 0, i + 1, (i + 1) % boundaryCount + 1;
  }

  fixture.complex.nodes.resize(boundaryCount);
  fixture.complex.halfedges.resize(boundaryCount);
  directional::geometry::SurfaceArrangementCell cell;
  cell.id = 0;
  cell.sourceFace = 0;
  cell.sourceFaces.resize(boundaryCount);
  std::iota(cell.sourceFaces.begin(), cell.sourceFaces.end(), 0);
  cell.sideEdgeCounts = sideCounts;
  cell.sideFamilies.resize(sideCounts.size());
  for (int i = 0; i < static_cast<int>(sideCounts.size()); ++i) {
    cell.sideFamilies[static_cast<std::size_t>(i)] = i & 1;
  }
  cell.disk = true;
  cell.closed = true;
  cell.boundaryCycle = true;
  cell.boundaryComponentCount = 1;
  cell.eulerCharacteristic = 1;
  cell.signedArea = 1.0;

  int side = 0;
  int sideEnd = sideCounts[0];
  for (int i = 0; i < boundaryCount; ++i) {
    if (i == sideEnd) {
      ++side;
      sideEnd += sideCounts[static_cast<std::size_t>(side)];
    }
    auto &node = fixture.complex.nodes[static_cast<std::size_t>(i)];
    node.id = i;
    node.sourceFace = i;
    node.barycentric << 0.0, 1.0, 0.0;
    directional::geometry::SurfaceArrangementNodeOccurrence previousFace;
    previousFace.sourceFace = (i + boundaryCount - 1) % boundaryCount;
    previousFace.barycentric << 0.0, 0.0, 1.0;
    node.occurrences.push_back(previousFace);
    node.hardBarrierCrossing = hardBarrier && i == 0;

    auto &edge = fixture.complex.halfedges[static_cast<std::size_t>(i)];
    edge.id = i;
    edge.from = i;
    edge.to = (i + 1) % boundaryCount;
    edge.next = (i + 1) % boundaryCount;
    edge.cell = 0;
    edge.family = side & 1;
    edge.sourceFace = i;
    edge.sourceComponent = 2;
    edge.sourceSheet = 4;
    edge.railId = side;
    edge.curveId = 100 + side;
    edge.hardFeature = side == 0;
    cell.halfedges.push_back(i);
  }
  fixture.complex.cells.push_back(std::move(cell));
  return fixture;
}

Fixture make_authoritative_patch(const std::vector<int> &sideCounts) {
  Fixture fixture = make_patch(sideCounts);
  auto &interior = fixture.complex.cells.front();
  interior.boundaryCycle = false;
  interior.cellClass =
      directional::geometry::SurfaceArrangementCellClass::PatchCandidate;
  interior.signedArea = std::abs(interior.signedArea);

  const int edgeCount = static_cast<int>(fixture.complex.halfedges.size());
  directional::geometry::SurfaceArrangementCell exterior = interior;
  exterior.id = 1;
  exterior.boundaryCycle = true;
  exterior.cellClass =
      directional::geometry::SurfaceArrangementCellClass::Exterior;
  exterior.signedArea = -std::abs(interior.signedArea);
  exterior.halfedges.clear();

  fixture.complex.halfedges.reserve(static_cast<std::size_t>(2 * edgeCount));
  for (int edgeId = 0; edgeId < edgeCount; ++edgeId) {
    auto twin = fixture.complex.halfedges[static_cast<std::size_t>(edgeId)];
    twin.id = edgeCount + edgeId;
    twin.from = fixture.complex.halfedges[static_cast<std::size_t>(edgeId)].to;
    twin.to = fixture.complex.halfedges[static_cast<std::size_t>(edgeId)].from;
    twin.twin = edgeId;
    twin.cell = exterior.id;
    twin.next = edgeCount + (edgeId + edgeCount - 1) % edgeCount;
    fixture.complex.halfedges[static_cast<std::size_t>(edgeId)].twin = twin.id;
    fixture.complex.halfedges.push_back(std::move(twin));
  }
  for (int offset = 0; offset < edgeCount; ++offset) {
    exterior.halfedges.push_back(
        edgeCount + (edgeCount - offset) % edgeCount);
  }
  fixture.complex.cells.push_back(std::move(exterior));
  fixture.complex.diagnostics.incidenceValid = true;
  fixture.complex.diagnostics.topologyValid = true;
  return fixture;
}

void append_authoritative_component(
    const directional::geometry::SurfaceCellComplex &component,
    directional::geometry::SurfaceCellComplex &destination) {
  const int nodeOffset = static_cast<int>(destination.nodes.size());
  const int edgeOffset = static_cast<int>(destination.halfedges.size());
  const int cellOffset = static_cast<int>(destination.cells.size());

  for (auto node : component.nodes) {
    node.id += nodeOffset;
    destination.nodes.push_back(std::move(node));
  }
  for (auto edge : component.halfedges) {
    edge.id += edgeOffset;
    edge.from += nodeOffset;
    edge.to += nodeOffset;
    edge.twin += edgeOffset;
    edge.next += edgeOffset;
    edge.cell += cellOffset;
    destination.halfedges.push_back(std::move(edge));
  }
  for (auto cell : component.cells) {
    cell.id += cellOffset;
    for (int &edge : cell.halfedges) {
      edge += edgeOffset;
    }
    destination.cells.push_back(std::move(cell));
  }
}

void append_fixture_component(const Fixture &component, Fixture &destination,
                              const bool shareCenterVertex,
                              const Eigen::RowVector3d &translation) {
  std::vector<int> vertexMap(static_cast<std::size_t>(component.V.rows()), -1);
  const int originalVertexCount = static_cast<int>(destination.V.rows());
  const int firstComponentVertex = shareCenterVertex ? 1 : 0;
  const int addedVertices = component.V.rows() - firstComponentVertex;
  destination.V.conservativeResize(originalVertexCount + addedVertices, 3);
  if (shareCenterVertex) {
    ASSERT_GT(originalVertexCount, 0);
    vertexMap[0] = 0;
  }
  for (int vertex = firstComponentVertex; vertex < component.V.rows(); ++vertex) {
    const int destinationVertex =
        originalVertexCount + vertex - firstComponentVertex;
    vertexMap[static_cast<std::size_t>(vertex)] = destinationVertex;
    destination.V.row(destinationVertex) = component.V.row(vertex) + translation;
  }

  const int faceOffset = static_cast<int>(destination.F.rows());
  destination.F.conservativeResize(faceOffset + component.F.rows(), 3);
  for (int face = 0; face < component.F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      destination.F(faceOffset + face, corner) =
          vertexMap[static_cast<std::size_t>(component.F(face, corner))];
    }
  }

  directional::geometry::SurfaceCellComplex remapped = component.complex;
  for (auto &node : remapped.nodes) {
    if (node.sourceFace >= 0) {
      node.sourceFace += faceOffset;
    }
    for (auto &occurrence : node.occurrences) {
      if (occurrence.sourceFace >= 0) {
        occurrence.sourceFace += faceOffset;
      }
    }
  }
  for (auto &edge : remapped.halfedges) {
    if (edge.sourceFace >= 0) {
      edge.sourceFace += faceOffset;
    }
    for (auto &provenance : edge.provenance) {
      if (provenance.sourceFace >= 0) {
        provenance.sourceFace += faceOffset;
      }
    }
  }
  for (auto &cell : remapped.cells) {
    if (cell.sourceFace >= 0) {
      cell.sourceFace += faceOffset;
    }
    for (int &sourceFace : cell.sourceFaces) {
      sourceFace += faceOffset;
    }
  }
  append_authoritative_component(remapped, destination.complex);
}


Fixture make_two_odd_cells_with_shared_interface() {
  Fixture fixture;
  fixture.V.resize(4, 3);
  fixture.V << 0.0, 0.0, 0.0,
               1.0, 0.0, 0.0,
               1.0, 1.0, 0.0,
               0.0, 1.0, 0.0;
  fixture.F.resize(2, 3);
  fixture.F << 0, 1, 2,
               0, 2, 3;

  fixture.complex.nodes.resize(4);
  const std::array<Eigen::RowVector3d, 4> face0Bary{{
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 0.0, 1.0),
      Eigen::RowVector3d::Constant(
          std::numeric_limits<double>::quiet_NaN())}};
  const std::array<Eigen::RowVector3d, 4> face1Bary{{
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d::Constant(
          std::numeric_limits<double>::quiet_NaN()),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 0.0, 1.0)}};
  for (int vertex = 0; vertex < 4; ++vertex) {
    auto &node = fixture.complex.nodes[static_cast<std::size_t>(vertex)];
    node.id = vertex;
    node.sourceComponent = 0;
    node.sourceSheet = 0;
    if (face0Bary[static_cast<std::size_t>(vertex)].allFinite()) {
      node.sourceFace = 0;
      node.barycentric = face0Bary[static_cast<std::size_t>(vertex)];
      node.occurrences.push_back(
          {0, face0Bary[static_cast<std::size_t>(vertex)]});
    }
    if (face1Bary[static_cast<std::size_t>(vertex)].allFinite()) {
      if (node.sourceFace < 0) {
        node.sourceFace = 1;
        node.barycentric = face1Bary[static_cast<std::size_t>(vertex)];
      }
      node.occurrences.push_back(
          {1, face1Bary[static_cast<std::size_t>(vertex)]});
    }
  }

  fixture.complex.halfedges.resize(10);
  const auto configureHalfedge = [&](const int id, const int twin,
                                     const int from, const int to,
                                     const int cell, const int next,
                                     const int sourceFace, const int family,
                                     const bool hardFeature) {
    auto &edge = fixture.complex.halfedges[static_cast<std::size_t>(id)];
    edge.id = id;
    edge.twin = twin;
    edge.from = from;
    edge.to = to;
    edge.cell = cell;
    edge.next = next;
    edge.sourceFace = sourceFace;
    edge.sourceArc = id / 2;
    edge.family = family;
    edge.strand = id / 2;
    edge.sourceComponent = 0;
    edge.sourceSheet = 0;
    edge.hardFeature = hardFeature;
    directional::geometry::SurfaceArrangementProvenance provenance;
    provenance.sourceArc = edge.sourceArc;
    provenance.sourceFace = sourceFace;
    provenance.family = family;
    provenance.strand = edge.strand;
    provenance.sourceComponent = 0;
    provenance.sourceSheet = 0;
    edge.provenance.push_back(provenance);
  };

  // Bounded cell 0: 0 -> 1 -> 2 -> 0.
  configureHalfedge(0, 1, 0, 1, 0, 2, 0, 0, true);
  configureHalfedge(2, 3, 1, 2, 0, 4, 0, 1, true);
  configureHalfedge(4, 5, 2, 0, 0, 0, 0, 0, false);
  // Bounded cell 1: 0 -> 2 -> 3 -> 0.
  configureHalfedge(5, 4, 0, 2, 1, 6, 1, 0, false);
  configureHalfedge(6, 7, 2, 3, 1, 8, 1, 1, true);
  configureHalfedge(8, 9, 3, 0, 1, 5, 1, 0, true);
  // Exterior boundary cycle: 1 -> 0 -> 3 -> 2 -> 1.
  configureHalfedge(1, 0, 1, 0, 2, 9, 0, 0, true);
  configureHalfedge(9, 8, 0, 3, 2, 7, 1, 1, true);
  configureHalfedge(7, 6, 3, 2, 2, 3, 1, 0, true);
  configureHalfedge(3, 2, 2, 1, 2, 1, 0, 1, true);

  fixture.complex.cells.resize(3);
  const auto configureCell = [&](const int id, std::vector<int> halfedges,
                                 const int sourceFace,
                                 const bool boundaryCycle) {
    auto &cell = fixture.complex.cells[static_cast<std::size_t>(id)];
    cell.id = id;
    cell.sourceFace = sourceFace;
    if (sourceFace >= 0) {
      cell.sourceFaces = {sourceFace};
    }
    cell.halfedges = std::move(halfedges);
    cell.sideFamilies = boundaryCycle ? std::vector<int>{0, 1, 0, 1}
                                      : std::vector<int>{0, 1, 0};
    cell.sideEdgeCounts.assign(cell.sideFamilies.size(), 1);
    cell.boundaryCycle = boundaryCycle;
    cell.closed = true;
    cell.disk = true;
    cell.boundaryComponentCount = 1;
    cell.eulerCharacteristic = 1;
    cell.cellClass = boundaryCycle
                         ? directional::geometry::SurfaceArrangementCellClass::Exterior
                         : directional::geometry::SurfaceArrangementCellClass::PatchCandidate;
  };
  configureCell(0, {0, 2, 4}, 0, false);
  configureCell(1, {5, 6, 8}, 1, false);
  configureCell(2, {1, 9, 7, 3}, -1, true);
  fixture.complex.cells[0].signedArea = 0.5;
  fixture.complex.cells[0].area = 0.5;
  fixture.complex.cells[1].signedArea = 0.5;
  fixture.complex.cells[1].area = 0.5;
  fixture.complex.cells[2].signedArea = -1.0;
  fixture.complex.cells[2].area = 1.0;

  auto &diagnostics = fixture.complex.diagnostics;
  diagnostics.embeddingValid = true;
  diagnostics.sourceEulerCharacteristic = 1;
  diagnostics.sourceConnectedComponentCount = 1;
  diagnostics.sourceBoundaryLoopCount = 1;
  diagnostics.supportedArea = 1.0;
  diagnostics.inputMemoryBytes = 1;
  diagnostics.unsplitCrossings = 0;
  diagnostics.geometricTJunctions = 0;
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(fixture.complex);
  return fixture;
}

Fixture make_same_corner_distinct_boundary_components() {
  const Fixture component = make_authoritative_patch({1, 1, 1, 1});
  Fixture fixture;
  fixture.V = component.V;
  fixture.F = component.F;
  append_authoritative_component(component.complex, fixture.complex);

  directional::geometry::SurfaceCellComplex alternate = component.complex;
  for (auto &edge : alternate.halfedges) {
    edge.railId += 1000;
    edge.curveId += 2000;
    edge.proposalBoundarySegment += 3000;
    for (auto &provenance : edge.provenance) {
      provenance.railId += 1000;
      provenance.curveId += 2000;
      provenance.proposalBoundarySegment += 3000;
    }
  }
  append_authoritative_component(alternate, fixture.complex);

  // This fixture is intentionally an overlapping ownership input. Derive
  // its diagnostics from the constructed DCEL instead of setting validity
  // flags. The production path must reject it before candidate expansion.
  fixture.complex.diagnostics.sourceEulerCharacteristic = 1;
  fixture.complex.diagnostics.sourceConnectedComponentCount = 1;
  fixture.complex.diagnostics.sourceBoundaryLoopCount = 1;
  fixture.complex.diagnostics.supportedArea = 1.0;
  fixture.complex.diagnostics.inputMemoryBytes = 1;
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(fixture.complex);
  return fixture;
}


Fixture make_valid_parallel_route_same_corner_complex() {
  Fixture fixture;
  // A triangulated annular source support.  Both arrangement domains use the
  // same four authoritative corner vertices, but their boundary curves carry
  // different complete face-route provenance through the annulus.
  fixture.V.resize(8, 3);
  fixture.V << -2.0, -2.0, 0.0,
                2.0, -2.0, 0.0,
                2.0,  2.0, 0.0,
               -2.0,  2.0, 0.0,
               -0.7, -0.7, 0.0,
                0.7, -0.7, 0.0,
                0.7,  0.7, 0.0,
               -0.7,  0.7, 0.0;
  fixture.F.resize(8, 3);
  fixture.F << 0, 1, 5,
               0, 5, 4,
               1, 2, 6,
               1, 6, 5,
               2, 3, 7,
               2, 7, 6,
               3, 0, 4,
               3, 4, 7;

  fixture.complex.nodes.resize(4);
  for (int vertex = 0; vertex < 4; ++vertex) {
    auto &node = fixture.complex.nodes[static_cast<std::size_t>(vertex)];
    node.id = vertex;
    node.sourceComponent = 0;
    node.sourceSheet = 0;
    for (int face = 0; face < fixture.F.rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        if (fixture.F(face, corner) != vertex) continue;
        Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
        barycentric(corner) = 1.0;
        if (node.sourceFace < 0) {
          node.sourceFace = face;
          node.barycentric = barycentric;
        }
        node.occurrences.push_back({face, barycentric});
      }
    }
  }

  fixture.complex.halfedges.resize(16);
  const auto configureEdge = [&](const int id, const int twin, const int from,
                                 const int to, const int cell, const int next,
                                 const int side, const bool alternateRoute) {
    auto &edge = fixture.complex.halfedges[static_cast<std::size_t>(id)];
    edge.id = id;
    edge.twin = twin;
    edge.from = from;
    edge.to = to;
    edge.cell = cell;
    edge.next = next;
    edge.family = side & 1;
    edge.sourceFace = 2 * side;
    edge.sourceArc = 100 * (alternateRoute ? 2 : 1) + side;
    edge.strand = edge.sourceArc;
    edge.sourceComponent = 0;
    edge.sourceSheet = 0;
    edge.railId = (alternateRoute ? 1000 : 0) + side;
    edge.curveId = (alternateRoute ? 2000 : 1000) + side;
    edge.sourceT0 = 0.0;
    edge.sourceT1 = 1.0;
    const auto addProvenance = [&](const int face, const int ordinal) {
      directional::geometry::SurfaceArrangementProvenance provenance;
      provenance.sourceArc = edge.sourceArc + ordinal;
      provenance.sourceFace = face;
      provenance.family = edge.family;
      provenance.strand = edge.strand;
      provenance.sourceComponent = 0;
      provenance.sourceSheet = 0;
      provenance.railId = edge.railId;
      provenance.curveId = edge.curveId;
      provenance.sourceT0 = 0.0;
      provenance.sourceT1 = 1.0;
      edge.provenance.push_back(provenance);
    };
    addProvenance(2 * side, 0);
    if (alternateRoute) {
      addProvenance(2 * side + 1, 1);
      addProvenance((2 * ((side + 1) % 4) + 1) % 8, 2);
    }
  };

  // Domain A and its exterior twin loop.
  configureEdge(0, 1, 0, 1, 0, 2, 0, false);
  configureEdge(2, 3, 1, 2, 0, 4, 1, false);
  configureEdge(4, 5, 2, 3, 0, 6, 2, false);
  configureEdge(6, 7, 3, 0, 0, 0, 3, false);
  configureEdge(1, 0, 1, 0, 1, 7, 0, false);
  configureEdge(7, 6, 0, 3, 1, 5, 3, false);
  configureEdge(5, 4, 3, 2, 1, 3, 2, false);
  configureEdge(3, 2, 2, 1, 1, 1, 1, false);

  // Domain B has the same authoritative corners but a distinct complete
  // embedded route on every side.  Both completions are closed-form quads, so
  // no rotation variant can bypass the initial same-corner claim.
  configureEdge(8, 9, 0, 1, 2, 10, 0, true);
  configureEdge(10, 11, 1, 2, 2, 12, 1, true);
  configureEdge(12, 13, 2, 3, 2, 14, 2, true);
  configureEdge(14, 15, 3, 0, 2, 8, 3, true);
  configureEdge(9, 8, 1, 0, 3, 15, 0, true);
  configureEdge(15, 14, 0, 3, 3, 13, 3, true);
  configureEdge(13, 12, 3, 2, 3, 11, 2, true);
  configureEdge(11, 10, 2, 1, 3, 9, 1, true);

  fixture.complex.cells.resize(4);
  const std::vector<int> allFaces{0, 1, 2, 3, 4, 5, 6, 7};
  const auto configureCell = [&](const int id, std::vector<int> halfedges,
                                 const bool exterior) {
    auto &cell = fixture.complex.cells[static_cast<std::size_t>(id)];
    cell.id = id;
    cell.sourceFace = 0;
    cell.sourceFaces = allFaces;
    cell.halfedges = std::move(halfedges);
    cell.sideFamilies = {0, 1, 0, 1};
    cell.sideEdgeCounts = {1, 1, 1, 1};
    cell.boundaryCycle = exterior;
    cell.closed = true;
    cell.disk = true;
    cell.boundaryComponentCount = 1;
    cell.eulerCharacteristic = 1;
    cell.signedArea = exterior ? -3.0 : 3.0;
    cell.area = 3.0;
    cell.cellClass = exterior
        ? directional::geometry::SurfaceArrangementCellClass::Exterior
        : directional::geometry::SurfaceArrangementCellClass::PatchCandidate;
  };
  configureCell(0, {0, 2, 4, 6}, false);
  configureCell(1, {1, 7, 5, 3}, true);
  configureCell(2, {8, 10, 12, 14}, false);
  configureCell(3, {9, 15, 13, 11}, true);

  auto &diagnostics = fixture.complex.diagnostics;
  diagnostics.embeddingValid = true;
  diagnostics.sourceEulerCharacteristic = 0;
  diagnostics.sourceConnectedComponentCount = 1;
  diagnostics.sourceBoundaryLoopCount = 2;
  diagnostics.supportedArea = 6.0;
  diagnostics.inputMemoryBytes = 1;
  diagnostics.unsplitCrossings = 0;
  diagnostics.geometricTJunctions = 0;
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(fixture.complex);
  return fixture;
}

} // namespace

TEST(PatchDescriptorMilestoneE, DerivesOrderedSidesSubdivisionsAndFeatures) {
  const Fixture fixture = make_patch({2, 3, 2, 3});
  const auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);

  ASSERT_TRUE(descriptor.boundaryCycleValid);
  ASSERT_EQ(descriptor.sides.size(), 4U);
  EXPECT_EQ(descriptor.patch.sideEdgeCounts,
            (std::vector<int>{2, 3, 2, 3}));
  EXPECT_EQ(descriptor.patch.turns, (std::vector<int>{1, 1, 1, 1}));
  EXPECT_EQ(descriptor.patch.boundaryVertices.size(), 10U);
  EXPECT_EQ(descriptor.patch.boundaryProvenance.size(), 10U);
  EXPECT_TRUE(descriptor.sides.front().hardFeature);
  EXPECT_EQ(descriptor.sides.front().railIds,
            (std::set<int>{0}));
  EXPECT_EQ(descriptor.sides.front().curveIds,
            (std::set<int>{100}));
  EXPECT_TRUE(descriptor.feasibility.admissible);
}

TEST(PatchDescriptorMilestoneE, SupportsThreeFourFiveAndSixSidedPatches) {
  const std::vector<std::vector<int>> cases = {
      {2, 1, 1}, {2, 3, 2, 3}, {2, 1, 1, 1, 1}, {2, 2, 1, 1, 1, 1}};
  for (const auto &counts : cases) {
    const Fixture fixture = make_patch(counts);
    const auto descriptor = directional::geometry::derive_patch_descriptor(
        fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
    EXPECT_EQ(descriptor.sides.size(), counts.size());
    EXPECT_EQ(descriptor.patch.sideEdgeCounts, counts);
    EXPECT_TRUE(descriptor.feasibility.admissible)
        << "side count " << counts.size();
  }
}

TEST(PatchDescriptorMilestoneE, RejectsOddBoundaryAndHardBarrierCrossing) {
  {
    const Fixture fixture = make_patch({1, 1, 1});
    const auto descriptor = directional::geometry::derive_patch_descriptor(
        fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
    EXPECT_EQ(descriptor.feasibility.reason,
              directional::geometry::PureQuadPatchRejectReason::OddBoundary);
  }
  {
    const Fixture fixture = make_patch({2, 2, 2}, true);
    const auto descriptor = directional::geometry::derive_patch_descriptor(
        fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
    EXPECT_FALSE(descriptor.featureConstraintsValid);
    EXPECT_EQ(
        descriptor.feasibility.reason,
        directional::geometry::PureQuadPatchRejectReason::HardFeatureCrossing);
  }
}

TEST(PatchDescriptorMilestoneE,
     SharedEdgeParityRepairConforminglyCompletesTwoOddCells) {
  const Fixture fixture = make_two_odd_cells_with_shared_interface();
  const Eigen::MatrixXd &V = fixture.V;
  const Eigen::MatrixXi &F = fixture.F;
  const directional::geometry::SurfaceCellComplex &complex = fixture.complex;
  ASSERT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(complex));
  ASSERT_TRUE(complex.diagnostics.topologyValid);
  const int oddBefore = static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.halfedges.size() % 2U != 0U;
      }));
  ASSERT_EQ(2, oddBefore);

  const auto repaired =
      directional::geometry::repair_surface_cell_boundary_parity(complex);
  ASSERT_TRUE(repaired.success) << repaired.failure;
  EXPECT_EQ(2, repaired.oddCellsBefore);
  EXPECT_EQ(0, repaired.oddCellsAfter);
  EXPECT_FALSE(repaired.splitHalfedges.empty());
  EXPECT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(repaired.complex));
  for (const auto &cell : repaired.complex.cells) {
    if (!cell.boundaryCycle) {
      EXPECT_EQ(0U, cell.halfedges.size() % 2U);
    }
  }

  const auto completion =
      directional::geometry::complete_surface_cell_complex(complex, V, F);
  ASSERT_TRUE(completion.success) << completion.failure;
  EXPECT_EQ(2, completion.parityOddCellsBefore);
  EXPECT_EQ(0, completion.parityOddCellsAfter);
  EXPECT_GT(completion.paritySplitEdges, 0);
  EXPECT_TRUE(completion.hasPreparedComplex);
  EXPECT_FALSE(completion.assembly.mesh.quads.empty());

  int sharedInterior = -1;
  for (const auto &edge : repaired.complex.halfedges) {
    if (edge.id > edge.twin) {
      continue;
    }
    const auto &twin = repaired.complex.halfedges[
        static_cast<std::size_t>(edge.twin)];
    if (!repaired.complex.cells[static_cast<std::size_t>(edge.cell)]
             .boundaryCycle &&
        !repaired.complex.cells[static_cast<std::size_t>(twin.cell)]
             .boundaryCycle) {
      sharedInterior = edge.id;
      break;
    }
  }
  ASSERT_GE(sharedInterior, 0);
  const auto perturbed =
      directional::geometry::subdivide_surface_cell_complex_edges(
          repaired.complex, {{sharedInterior, 1}});
  ASSERT_TRUE(perturbed.success) << perturbed.failure;
  const auto sideRepair =
      directional::geometry::repair_surface_cell_side_subdivisions(
          perturbed.complex, V, F);
  ASSERT_TRUE(sideRepair.success) << sideRepair.failure;
  EXPECT_GT(sideRepair.infeasibleCellsBefore, 0);
  EXPECT_EQ(0, sideRepair.infeasibleCellsAfter);
  EXPECT_GT(sideRepair.insertedVertices, 0);
  EXPECT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(sideRepair.complex));
  const auto descriptors = directional::geometry::derive_patch_descriptors(
      sideRepair.complex, V, F);
  for (const auto &descriptor : descriptors.descriptors) {
    EXPECT_NE(directional::geometry::PureQuadPatchRejectReason::OddBoundary,
              descriptor.feasibility.reason);
    EXPECT_NE(directional::geometry::PureQuadPatchRejectReason::SideInequality,
              descriptor.feasibility.reason);
    EXPECT_NE(directional::geometry::PureQuadPatchRejectReason::HexParity,
              descriptor.feasibility.reason);
  }
}

TEST(PatchDescriptorMilestoneE,
     FiveSidedRepairUsesBoundedClosedFormInsteadOfCompositionSearch) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const auto before = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  ASSERT_EQ(5U, before.sides.size());
  ASSERT_EQ(directional::geometry::PureQuadPatchRejectReason::SideInequality,
            before.feasibility.reason);

  const auto repaired =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F);
  ASSERT_TRUE(repaired.success) << repaired.failure;
  EXPECT_EQ(1, repaired.infeasibleCellsBefore);
  EXPECT_EQ(0, repaired.infeasibleCellsAfter);
  EXPECT_GT(repaired.insertedVertices, 0);
  EXPECT_LE(repaired.insertedVertices, 36);
  EXPECT_EQ(repaired.insertedVertices, repaired.attemptedInsertions);
  EXPECT_EQ(0, repaired.finalEquationDefect);

  const auto after = directional::geometry::derive_patch_descriptor(
      repaired.complex, repaired.complex.cells.front(), fixture.V, fixture.F);
  ASSERT_EQ(5U, after.sides.size());
  const int repairedBoundary =
      std::accumulate(after.patch.sideEdgeCounts.begin(),
                      after.patch.sideEdgeCounts.end(), 0);
  EXPECT_EQ(0, repairedBoundary % 2);
  EXPECT_LE(repairedBoundary, 60);
  EXPECT_TRUE(after.feasibility.admissible);
}


TEST(PatchDescriptorMilestoneE,
     SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const auto repaired =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(repaired.success) << repaired.failure;
  ASSERT_GT(repaired.insertedVertices, 0);
  ASSERT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(repaired.complex));

  for (const auto &cell : repaired.complex.cells) {
    if (cell.cellClass ==
        directional::geometry::SurfaceArrangementCellClass::Exterior) {
      continue;
    }
    const auto audit =
        directional::geometry::audit_surface_cell_domain_identity(
            repaired.complex, cell, cell.halfedges, fixture.F);
    EXPECT_TRUE(audit.valid)
        << directional::geometry::surface_cell_domain_identity_failure_name(
               audit.failure)
        << " cell=" << audit.cellId << " halfedge=" << audit.halfedgeId
        << " node=" << audit.nodeId << " sourceFace=" << audit.sourceFace
        << " component=" << audit.sourceComponent
        << " sheet=" << audit.sourceSheet;
  }

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      repaired.complex, fixture.V, fixture.F);
  ASSERT_FALSE(descriptors.ownershipConflict.active());
  ASSERT_FALSE(descriptors.descriptors.empty());
  for (const auto &descriptor : descriptors.descriptors) {
    EXPECT_TRUE(descriptor.domainIdentityAudit.valid);
    EXPECT_TRUE(descriptor.patch.domainIdentity.valid);
  }
}

TEST(PatchDescriptorMilestoneE,
     PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(fixture.complex);

  directional::geometry::SurfaceCellSideRepairOptions repairOptions;
  repairOptions.maxInsertedVertices = 1;
  repairOptions.maxLocalInsertedVertices = 512;
  repairOptions.maxPropagationPasses = 4096;
  repairOptions.maxStagnantPasses = 64;
  const auto rejected =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F, repairOptions);

  ASSERT_FALSE(rejected.success);
  EXPECT_EQ("SideRepairInsertionLimit", rejected.failure);
  EXPECT_GT(rejected.attemptedInsertions, 0);
  EXPECT_TRUE(rejected.rollbackEquivalent);
  EXPECT_EQ(rejected.rollbackIdentityHashBefore,
            rejected.rollbackIdentityHashAfter);
  EXPECT_EQ(before,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(rejected.complex));

  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.allowBoundedCombinatorialFallback = true;
  options.sideRepairOptions = repairOptions;
  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);
  EXPECT_TRUE(completion.sideRollbackEquivalent);
  EXPECT_EQ(completion.sideRollbackIdentityHashBefore,
            completion.sideRollbackIdentityHashAfter);
  EXPECT_TRUE(completion.success) << completion.failure;
  EXPECT_FALSE(completion.descriptors.descriptors.empty());
  EXPECT_FALSE(completion.assembly.mesh.quads.empty());
  EXPECT_EQ(std::string::npos,
            completion.failure.find("RollbackMismatch"));
}

TEST(PatchDescriptorMilestoneE, RejectsNonDiskAndBrokenBoundaryCycle) {
  Fixture fixture = make_patch({2, 2, 2, 2});
  fixture.complex.cells.front().disk = false;
  auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  EXPECT_EQ(descriptor.feasibility.reason,
            directional::geometry::PureQuadPatchRejectReason::NonDisk);

  fixture = make_patch({2, 2, 2, 2});
  fixture.complex.halfedges.front().to = 3;
  descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  EXPECT_FALSE(descriptor.boundaryCycleValid);
  EXPECT_EQ(descriptor.feasibility.reason,
            directional::geometry::PureQuadPatchRejectReason::NonDisk);
}

TEST(PatchDescriptorMilestoneE, DerivesCompatibleInteriorSingularityValence) {
  Fixture fixture = make_patch({2, 1, 1});
  directional::geometry::PatchDescriptorOptions options;
  options.singularCycles.resize(1);
  options.singularIndices.resize(1);
  options.singularCycles << 0;
  options.singularIndices << 1;

  auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F,
      options);
  ASSERT_TRUE(descriptor.feasibility.admissible);
  EXPECT_EQ(descriptor.patch.singularityCount, 1);
  EXPECT_EQ(descriptor.feasibility.expectedInteriorValence, 3);

  options.singularIndices << -1;
  descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F,
      options);
  EXPECT_EQ(
      descriptor.feasibility.reason,
      directional::geometry::PureQuadPatchRejectReason::SingularityMismatch);
}

TEST(PatchDescriptorMilestoneE, BoundarySingularityDoesNotConsumeInteriorPole) {
  Fixture fixture = make_patch({2, 3, 2, 3});
  directional::geometry::PatchDescriptorOptions options;
  options.singularCycles.resize(1);
  options.singularIndices.resize(1);
  options.singularCycles << 1;
  options.singularIndices << 1;
  const auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F,
      options);
  EXPECT_EQ(descriptor.patch.singularityCount, 0);
  EXPECT_TRUE(descriptor.feasibility.admissible);
}

TEST(PatchDescriptorMilestoneE,
     GlobalDescriptorAssignmentUsesEmbeddedSingularityAsBoundaryTopology) {
  const Fixture fixture = make_authoritative_patch({2, 3, 2, 3});
  directional::geometry::PatchDescriptorOptions options;
  options.singularCycles.resize(1);
  options.singularIndices.resize(1);
  options.singularCycles << 1;
  options.singularIndices << 1;

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      fixture.complex, fixture.V, fixture.F, options);
  ASSERT_TRUE(descriptors.unresolvedSingularVertices.empty());
  ASSERT_EQ(1U, descriptors.descriptors.size());
  EXPECT_EQ(0, descriptors.descriptors.front().patch.singularityCount);
  EXPECT_TRUE(descriptors.descriptors.front().feasibility.admissible);
}

TEST(PatchDescriptorMilestoneE,
     GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  const Fixture secondDomain = make_authoritative_patch({2, 2, 2, 2});
  append_fixture_component(secondDomain, fixture, true,
                           Eigen::RowVector3d{2.5, 0.0, 0.0});
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.descriptorOptions.singularCycles.resize(1);
  options.descriptorOptions.singularIndices.resize(1);
  options.descriptorOptions.singularCycles << 0;
  options.descriptorOptions.singularIndices << 1;

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      fixture.complex, fixture.V, fixture.F, options.descriptorOptions);
  ASSERT_EQ((std::vector<int>{0}), descriptors.unresolvedSingularVertices);
  ASSERT_EQ(2U, descriptors.descriptors.size());
  for (const auto &descriptor : descriptors.descriptors) {
    EXPECT_EQ(0, descriptor.patch.singularityCount);
  }

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);
  EXPECT_FALSE(completion.success);
  EXPECT_EQ("UnresolvedSingularityOwnership", completion.failure);
  EXPECT_TRUE(completion.completedPatches.empty());
}

TEST(PatchDescriptorMilestoneE,
     CompletesAuthoritativeComplexThroughMilestoneEEntryPoint) {
  const Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.success) << completion.assembly.failure;
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  ASSERT_EQ(1U, completion.completedPatches.size());
  EXPECT_EQ(4U, completion.assembly.mesh.quads.size());
  EXPECT_EQ(1, completion.assembly.connectedComponents);
  EXPECT_EQ(1, completion.assembly.boundaryLoopCount);
  EXPECT_EQ(1, completion.assembly.eulerCharacteristic);
}


TEST(PatchDescriptorMilestoneE,
     ComplexCompletionFailsClosedInsteadOfReturningPartialOutput) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  Fixture invalid = make_authoritative_patch({2, 2, 2, 2});
  invalid.complex.cells.front().disk = false;
  invalid.complex.cells.front().cellClass =
      directional::geometry::SurfaceArrangementCellClass::NonDisk;
  append_fixture_component(invalid, fixture, false,
                           Eigen::RowVector3d{3.0, 0.0, 0.0});

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  EXPECT_FALSE(completion.success);
  EXPECT_EQ("IncompleteSurfaceCellComplex", completion.failure);
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(1, completion.failedPatches);
  EXPECT_EQ(1U, completion.completedPatches.size());
  EXPECT_FALSE(completion.assembly.success);
  EXPECT_TRUE(completion.assembly.mesh.quads.empty());
}

TEST(PatchDescriptorMilestoneE,
     ExteriorArrangementCyclesAreNotAuthoritativeCompletionPatches) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.success) << completion.failure;
  EXPECT_EQ(1U, completion.descriptors.descriptors.size());
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  EXPECT_EQ(1U, completion.completedPatches.size());
}


TEST(PatchDescriptorMilestoneE,
     DuplicateDomainsFailBeforePatchCompletion) {
  Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  directional::geometry::SurfaceCellComplex duplicate;
  append_authoritative_component(fixture.complex, duplicate);
  append_authoritative_component(fixture.complex, duplicate);
  duplicate.cells[0].id = 91;
  duplicate.cells[1].id = 92;
  duplicate.cells[2].id = 401;
  duplicate.cells[3].id = 402;
  for (auto &edge : duplicate.halfedges) {
    if (edge.cell == 0) edge.cell = 91;
    else if (edge.cell == 1) edge.cell = 92;
    else if (edge.cell == 2) edge.cell = 401;
    else if (edge.cell == 3) edge.cell = 402;
  }
  std::reverse(duplicate.cells.begin(), duplicate.cells.end());

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      duplicate, fixture.V, fixture.F);

  ASSERT_TRUE(descriptors.ownershipConflict.active());
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                DuplicateOrientedDomain,
            descriptors.ownershipConflict.classification);
  EXPECT_EQ(91, descriptors.ownershipConflict.firstPatch);
  EXPECT_EQ(401, descriptors.ownershipConflict.secondPatch);
}

TEST(PatchDescriptorMilestoneE,
     DomainIdentityIsIndependentOfSourceFaceRowOrder) {
  const Fixture first = make_authoritative_patch({2, 2, 2, 2});
  Fixture reordered = first;
  std::vector<int> permutation(reordered.F.rows());
  std::iota(permutation.begin(), permutation.end(), 0);
  std::reverse(permutation.begin(), permutation.end());
  Eigen::MatrixXi reorderedFaces = reordered.F;
  for (int row = 0; row < reordered.F.rows(); ++row) {
    reorderedFaces.row(row) = reordered.F.row(permutation[row]);
  }
  std::vector<int> inverse(permutation.size());
  for (int row = 0; row < static_cast<int>(permutation.size()); ++row) {
    inverse[static_cast<std::size_t>(permutation[row])] = row;
  }
  reordered.F = reorderedFaces;
  for (auto &node : reordered.complex.nodes) {
    node.sourceFace = inverse[static_cast<std::size_t>(node.sourceFace)];
    for (auto &occurrence : node.occurrences) {
      occurrence.sourceFace =
          inverse[static_cast<std::size_t>(occurrence.sourceFace)];
    }
  }
  for (auto &edge : reordered.complex.halfedges) {
    edge.sourceFace = inverse[static_cast<std::size_t>(edge.sourceFace)];
  }
  for (auto &cell : reordered.complex.cells) {
    cell.sourceFace = inverse[static_cast<std::size_t>(cell.sourceFace)];
    for (int &face : cell.sourceFaces) {
      face = inverse[static_cast<std::size_t>(face)];
    }
  }

  const auto firstDescriptor = directional::geometry::derive_patch_descriptor(
      first.complex, first.complex.cells.front(), first.V, first.F);
  const auto reorderedDescriptor =
      directional::geometry::derive_patch_descriptor(
          reordered.complex, reordered.complex.cells.front(), reordered.V,
          reordered.F);

  ASSERT_TRUE(firstDescriptor.patch.domainIdentity.valid);
  ASSERT_TRUE(reorderedDescriptor.patch.domainIdentity.valid);
  EXPECT_TRUE(firstDescriptor.patch.domainIdentity.same_oriented_domain(
      reorderedDescriptor.patch.domainIdentity));
  EXPECT_EQ(firstDescriptor.patch.boundaryNodeIdentities,
            reorderedDescriptor.patch.boundaryNodeIdentities);
}


TEST(PatchDescriptorMilestoneE,
     WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger) {
  const Fixture fixture = make_valid_parallel_route_same_corner_complex();
  ASSERT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(fixture.complex));
  directional::geometry::SurfaceCellComplexCompletionOptions preconditionOptions;
  preconditionOptions.maxSameCornerBoundaryRepairs = 0;
  preconditionOptions.maxSameCornerCandidateEvaluations = 0;
  preconditionOptions.maxSameCornerFullCompletionPasses = 1;
  preconditionOptions.maxSameCornerVisitedStates = 1;
  preconditionOptions.maxSameCornerInsertedVertices = 0;
  const auto precondition =
      directional::geometry::complete_surface_cell_complex(
          fixture.complex, fixture.V, fixture.F, preconditionOptions);
  ASSERT_FALSE(precondition.success);
  ASSERT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                SameCornerDistinctBoundaryClaim,
            precondition.assembly.ownershipConflict.classification);
  ASSERT_GT(precondition.completionOwnershipRouteCandidateCount, 0);

  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 4;
  options.maxSameCornerCandidateEvaluations = 4;
  options.maxSameCornerFullCompletionPasses = 5;
  options.maxSameCornerVisitedStates = 5;
  options.maxSameCornerInsertedVertices = 8;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  ASSERT_TRUE(completion.success) << completion.failure;
  EXPECT_GE(completion.completionOwnershipStructuralRepairAttempts, 1);
  EXPECT_LE(completion.completionOwnershipStructuralRepairAttempts, 4);
  EXPECT_LE(completion.completionOwnershipStructuralCandidatesConsumed, 4);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_GE(completion.completionOwnershipIncrementalRecomputationPasses, 1);
  EXPECT_GT(completion.completionOwnershipReusedPatchCompletions, 0);
  EXPECT_GT(completion.completionOwnershipRecomputedPatchCompletions, 0);
  EXPECT_LE(completion.completionOwnershipVisitedStateCount, 5);
  EXPECT_LE(completion.completionOwnershipInsertedBoundaryVertices, 8);
  EXPECT_EQ(1, completion.completionOwnershipPeakLiveCandidateComplexes);
  EXPECT_EQ(0, completion.completionOwnershipCurrentLiveCandidateComplexes);
  ASSERT_FALSE(completion.ownershipRepairAttempts.empty());
  EXPECT_GT(completion.ownershipRepairAttempts.front().routeIntervalCount, 1);
  EXPECT_EQ(completion.completionOwnershipRouteCandidateCount,
            completion.ownershipRepairAttempts.front().routeCandidateCount);
  EXPECT_EQ(
      directional::geometry::SurfaceCellOwnershipRepairAction::
          RouteCompleteBoundarySubdivision,
      completion.ownershipRepairAttempts.front().action);
  EXPECT_EQ(
      directional::geometry::SurfaceCellOwnershipRepairOutcome::
          AssemblySucceeded,
      completion.ownershipRepairAttempts.back().outcome);
  EXPECT_FALSE(completion.assembly.ownershipConflict.active());
}

TEST(PatchDescriptorMilestoneE,
     SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion) {
  const Fixture fixture = make_same_corner_distinct_boundary_components();
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 8;
  options.maxSameCornerCandidateEvaluations = 8;
  options.maxSameCornerFullCompletionPasses = 9;
  options.maxSameCornerVisitedStates = 9;
  options.maxSameCornerInsertedVertices = 16;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  EXPECT_FALSE(completion.success);
  EXPECT_EQ(0, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(0, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(
      directional::geometry::SurfaceCellStructuralRepairExhaustionReason::
          OwnershipOverlap,
      completion.completionOwnershipStructuralExhaustionReason);
  EXPECT_TRUE(completion.ownershipRepairAttempts.empty());
  EXPECT_NE(std::string::npos,
            completion.failure.find("SameCornerDistinctBoundaryOverlap:"));
}

TEST(PatchDescriptorMilestoneE,
     ZeroStructuralBudgetFailsBeforeCandidateExpansion) {
  const Fixture fixture = make_valid_parallel_route_same_corner_complex();
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 0;
  options.maxSameCornerCandidateEvaluations = 0;
  options.maxSameCornerFullCompletionPasses = 1;
  options.maxSameCornerVisitedStates = 1;
  options.maxSameCornerInsertedVertices = 0;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  EXPECT_FALSE(completion.success);
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                SameCornerDistinctBoundaryClaim,
            completion.assembly.ownershipConflict.classification);
  EXPECT_GT(completion.completionOwnershipRouteCandidateCount, 0);
  EXPECT_EQ(0, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(0, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(
      directional::geometry::SurfaceCellStructuralRepairExhaustionReason::
          CandidateBudget,
      completion.completionOwnershipStructuralExhaustionReason);
  EXPECT_NE(std::string::npos,
            completion.failure.find(
                "SameCornerStructuralRepairExhausted:candidate-budget:"));
}

TEST(PatchDescriptorMilestoneE,
     OneCandidateBudgetIsExactAndDoesNotRecurse) {
  const Fixture fixture = make_valid_parallel_route_same_corner_complex();
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 1;
  options.maxSameCornerCandidateEvaluations = 1;
  options.maxSameCornerFullCompletionPasses = 2;
  options.maxSameCornerVisitedStates = 2;
  options.maxSameCornerInsertedVertices = 8;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  EXPECT_EQ(1, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(1, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(1, completion.completionOwnershipIncrementalRecomputationPasses);
  EXPECT_GT(completion.completionOwnershipReusedPatchCompletions, 0);
  EXPECT_GT(completion.completionOwnershipRecomputedPatchCompletions, 0);
  EXPECT_LE(completion.completionOwnershipVisitedStateCount, 2);
  EXPECT_LE(completion.completionOwnershipPeakLiveCandidateComplexes, 1);
  EXPECT_EQ(0, completion.completionOwnershipCurrentLiveCandidateComplexes);
  ASSERT_EQ(1U, completion.ownershipRepairAttempts.size());
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipRepairAction::
                RouteCompleteBoundarySubdivision,
            completion.ownershipRepairAttempts.front().action);
  EXPECT_GT(completion.ownershipRepairAttempts.front().routeIntervalCount, 1);
  EXPECT_EQ(1, completion.ownershipRepairAttempts.front().candidateEvaluation);
  EXPECT_EQ(1, completion.ownershipRepairAttempts.front().structuralAttempt);
}

TEST(PatchDescriptorMilestoneE,
     StructuralRepairLedgerIsPatchOrderInvariant) {
  const Fixture first = make_valid_parallel_route_same_corner_complex();
  Fixture reordered = first;
  std::swap(reordered.complex.cells[0], reordered.complex.cells[2]);
  reordered.complex.cells[0].id = 0;
  reordered.complex.cells[2].id = 2;
  for (auto &edge : reordered.complex.halfedges) {
    if (edge.cell == 0) {
      edge.cell = 2;
    } else if (edge.cell == 2) {
      edge.cell = 0;
    }
  }
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(reordered.complex);
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 4;
  options.maxSameCornerCandidateEvaluations = 4;
  options.maxSameCornerFullCompletionPasses = 5;
  options.maxSameCornerVisitedStates = 5;
  options.maxSameCornerInsertedVertices = 8;

  const auto a = directional::geometry::complete_surface_cell_complex(
      first.complex, first.V, first.F, options);
  const auto b = directional::geometry::complete_surface_cell_complex(
      reordered.complex, reordered.V, reordered.F, options);

  EXPECT_EQ(a.success, b.success);
  EXPECT_EQ(a.completionOwnershipStructuralRepairAttempts,
            b.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(a.completionOwnershipStructuralCandidatesConsumed,
            b.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(a.completionOwnershipFullRecomputationPasses,
            b.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(a.completionOwnershipVisitedStateCount,
            b.completionOwnershipVisitedStateCount);
  EXPECT_EQ(a.completionOwnershipStructuralExhaustionReason,
            b.completionOwnershipStructuralExhaustionReason);
  ASSERT_FALSE(a.ownershipRepairAttempts.empty());
  ASSERT_EQ(a.ownershipRepairAttempts.size(), b.ownershipRepairAttempts.size());
  for (std::size_t index = 0; index < a.ownershipRepairAttempts.size(); ++index) {
    EXPECT_EQ(a.ownershipRepairAttempts[index].outcome,
              b.ownershipRepairAttempts[index].outcome);
    EXPECT_EQ(a.ownershipRepairAttempts[index].candidateEvaluation,
              b.ownershipRepairAttempts[index].candidateEvaluation);
    EXPECT_EQ(a.ownershipRepairAttempts[index].routeIdentityHash,
              b.ownershipRepairAttempts[index].routeIdentityHash);
    EXPECT_EQ(a.ownershipRepairAttempts[index].routeIntervalCount,
              b.ownershipRepairAttempts[index].routeIntervalCount);
    EXPECT_EQ(a.ownershipRepairAttempts[index].selectedHalfedges,
              b.ownershipRepairAttempts[index].selectedHalfedges);
  }
}


TEST(PatchDescriptorMilestoneE,
     FailedSubdivisionReturnsBitExactCommittedComplex) {
  Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  ASSERT_GE(fixture.complex.halfedges.size(), 4U);
  const auto &badEdge = fixture.complex.halfedges[2];
  ASSERT_GE(badEdge.from, 0);
  ASSERT_GE(badEdge.to, 0);
  ASSERT_LT(static_cast<std::size_t>(badEdge.from),
            fixture.complex.nodes.size());
  ASSERT_LT(static_cast<std::size_t>(badEdge.to),
            fixture.complex.nodes.size());

  // Keep edge 0 valid so the transaction appends a tentative node first.
  // Then remove common face support from edge 2's endpoint pair so its
  // midpoint embedding fails after mutation has begun.
  auto &badFrom =
      fixture.complex.nodes[static_cast<std::size_t>(badEdge.from)];
  auto &badTo =
      fixture.complex.nodes[static_cast<std::size_t>(badEdge.to)];
  badFrom.occurrences.clear();
  badTo.occurrences.clear();
  badFrom.sourceFace = badEdge.sourceFace;
  badTo.sourceFace =
      (badEdge.sourceFace + 1) % static_cast<int>(fixture.F.rows());
  badFrom.barycentric = Eigen::RowVector3d(0.2, 0.7, 0.1);
  badTo.barycentric = Eigen::RowVector3d(0.2, 0.1, 0.7);

  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(fixture.complex);
  const auto result =
      directional::geometry::subdivide_surface_cell_complex_edges(
          fixture.complex, {{0, 1}, {2, 1}});

  ASSERT_FALSE(result.success);
  EXPECT_EQ("InvalidMidpointEmbedding", result.failure);
  EXPECT_TRUE(result.rollbackEquivalent);
  EXPECT_EQ(result.rollbackIdentityHashBefore,
            result.rollbackIdentityHashAfter);
  EXPECT_EQ(before,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(result.complex));
  EXPECT_EQ(fixture.complex.nodes.size(), result.complex.nodes.size());
  EXPECT_EQ(fixture.complex.halfedges.size(),
            result.complex.halfedges.size());
  EXPECT_EQ(fixture.complex.cells.size(), result.complex.cells.size());
}

TEST(PatchDescriptorMilestoneE,
     AlreadySuccessfulComplexPerformsNoStructuralRepair) {
  const Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);
  ASSERT_TRUE(completion.success) << completion.failure;
  ASSERT_FALSE(completion.descriptors.descriptors.empty());
  ASSERT_FALSE(completion.completedPatches.empty());
  ASSERT_FALSE(completion.assembly.mesh.quads.empty());
  EXPECT_TRUE(completion.assembly.failure.empty());
  EXPECT_EQ(0, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(0, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(0, completion.completionOwnershipRouteCandidateCount);
  EXPECT_TRUE(completion.ownershipRepairAttempts.empty());
}
