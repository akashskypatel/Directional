#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceComplexSimplification.h>

#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::SurfaceArrangementArc;
using directional::geometry::SurfaceCellComplex;
using directional::geometry::SurfaceSimplificationCandidate;
using directional::geometry::SurfaceSimplificationCandidateType;

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

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
  return directional::geometry::build_surface_cell_complex(
      mesh.vertices, mesh.faces,
      {arc(0, 0, {0.5, 0.5, 0.0}, {0.25, 0.25, 0.5}, 0, 7),
       arc(1, 0, {0.25, 0.25, 0.5}, {0.5, 0.0, 0.5}, 0, 7)});
}

std::vector<int> internal_interface(const SurfaceCellComplex &complex) {
  std::map<std::pair<int, int>, std::vector<int>> interfaces;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.family < 0 ||
        halfedge.hardFeature) {
      continue;
    }
    const int other =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell;
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
  std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> desired;
  for (int segment = 0; segment < segments; ++segment) {
    for (int ring = 0; ring < axialCells; ++ring) {
      desired.push_back({{ring * segments + segment,
                          (ring + 1) * segments + segment},
                         {1, segment}});
    }
  }
  for (int ring = 1; ring < axialCells; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      desired.push_back({{ring * segments + segment,
                          ring * segments + (segment + 1) % segments},
                         {0, 1000 + ring}});
    }
  }

  std::vector<SurfaceArrangementArc> arcs;
  int id = 0;
  for (const auto &[edge, metadata] : desired) {
    for (int face = 0; face < mesh.faces.rows(); ++face) {
      int localA = -1;
      int localB = -1;
      for (int corner = 0; corner < 3; ++corner) {
        if (mesh.faces(face, corner) == edge.first) localA = corner;
        if (mesh.faces(face, corner) == edge.second) localB = corner;
      }
      if (localA < 0 || localB < 0) continue;
      Eigen::RowVector3d a = Eigen::RowVector3d::Zero();
      Eigen::RowVector3d b = Eigen::RowVector3d::Zero();
      a[localA] = 1.0;
      b[localB] = 1.0;
      arcs.push_back(arc(id++, face, a, b, metadata.first, metadata.second));
    }
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
      directional::geometry::surface_cell_tracing_detail::edge_key(1, 2));
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(
          mesh.vertices, mesh.faces, {}, options);

  EXPECT_TRUE(complex.diagnostics.topologyValid);
  EXPECT_EQ(std::count_if(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) { return cell.boundaryCycle; }),
            1);
  EXPECT_EQ(std::count_if(complex.cells.begin(), complex.cells.end(),
                          [](const auto &cell) { return !cell.boundaryCycle; }),
            2);
  EXPECT_NEAR(complex.diagnostics.extractedArea,
              complex.diagnostics.supportedArea, 1.0e-10);
}

TEST(MilestoneDClosure, PartialMultiEdgeInterfaceFailsClosed) {
  const MeshFixture mesh = unit_triangle();
  const SurfaceCellComplex complex = two_interface_complex(mesh);
  const std::vector<int> interface = internal_interface(complex);
  ASSERT_GT(interface.size(), 1U);
  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(complex);

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, mesh.vertices, mesh.faces,
      {removal_candidate(1, {interface.front()})});

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
  for (auto &halfedge : complex.halfedges) {
    if (halfedge.id < halfedge.twin && halfedge.family < 0) {
      halfedge.hardFeature = true;
      halfedge.railId = 77;
      halfedge.railT0 = 0.125;
      halfedge.railT1 = 0.875;
      auto &twin = complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
      twin.hardFeature = true;
      twin.railId = 77;
      twin.railT0 = 0.875;
      twin.railT1 = 0.125;
      break;
    }
  }
  const auto protectedBefore =
      directional::geometry::surface_simplification_detail::protected_support(
          complex);

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, mesh.vertices, mesh.faces,
      {removal_candidate(2, interface)});

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
  const SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(mesh.vertices,
                                                         mesh.faces, arcs);
  ASSERT_TRUE(complex.diagnostics.topologyValid);
  ASSERT_EQ(complex.diagnostics.eulerCharacteristic, 0);
  ASSERT_EQ(complex.diagnostics.boundaryLoopCount, 2);

  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, mesh.vertices, mesh.faces);
  const auto candidate = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &value) {
        return value.type == SurfaceSimplificationCandidateType::OpenStrip &&
               value.elementIds.size() == static_cast<std::size_t>(axialCells) &&
               !value.touchesHardFeature && !value.touchesBoundary &&
               !value.touchesSingularity && !value.changesTopology &&
               value.sideFeasible;
      });
  ASSERT_NE(candidate, extracted.candidates.end());

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, mesh.vertices, mesh.faces, {*candidate});
  ASSERT_GE(result.committed, 1);
  EXPECT_LT(result.finalActiveElements, result.initialActiveElements);
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic, 0);
  EXPECT_EQ(result.complex.diagnostics.connectedComponentCount, 1);
  EXPECT_EQ(result.complex.diagnostics.boundaryLoopCount, 2);
}
