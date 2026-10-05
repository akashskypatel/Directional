#include <directional/pipeline/RemeshPipeline.h>

#include <gtest/gtest.h>

namespace {

struct StripMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

StripMesh make_two_square_strip() {
  StripMesh mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 0.75, 0.0, 0.0, 1.5, 0.0, 0.0,
      0.0, 0.75, 0.0, 0.75, 0.75, 0.0, 1.5, 0.75, 0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  return mesh;
}

directional::geometry::AdaptiveFeatureEdge feature_edge(
    const int a, const int b, const std::vector<int> &faces,
    const directional::geometry::AdaptiveFeatureClass edgeClass,
    const int curve) {
  directional::geometry::AdaptiveFeatureEdge edge;
  edge.vertices = directional::geometry::AdaptiveFeatureMap::canonical_edge(a, b);
  edge.incidentFaces = faces;
  edge.component = 0;
  edge.curve = curve;
  edge.edgeClass = edgeClass;
  edge.strength = edgeClass == directional::geometry::AdaptiveFeatureClass::Hard
                      ? 1.0
                      : 0.6;
  return edge;
}

directional::geometry::AdaptiveFeatureMap mixed_curve_map(
    const directional::geometry::AdaptiveFeatureClass middleClass) {
  directional::geometry::AdaptiveFeatureMap map;
  map.edges = {
      feature_edge(0, 1, {0},
                   directional::geometry::AdaptiveFeatureClass::Hard, 17),
      feature_edge(1, 4, {0, 3}, middleClass, 17),
      feature_edge(4, 5, {3},
                   directional::geometry::AdaptiveFeatureClass::Hard, 17)};
  for (int index = 0; index < static_cast<int>(map.edges.size()); ++index) {
    map.edgeIndex.emplace(map.edges[static_cast<std::size_t>(index)].vertices,
                          index);
  }
  directional::geometry::AdaptiveFeatureCurve curve;
  curve.id = 17;
  curve.component = 0;
  curve.edges = {0, 1, 2};
  curve.vertices = {0, 1, 4, 5};
  curve.closed = false;
  map.curves.push_back(curve);
  return map;
}

} // namespace

TEST(MilestoneBClosure, MixedFeatureCurveIsSplitIntoContiguousRailRuns) {
  const StripMesh mesh = make_two_square_strip();
  directional::TriMesh source;
  source.set_mesh(mesh.vertices, mesh.faces);
  const auto map = mixed_curve_map(
      directional::geometry::AdaptiveFeatureClass::Soft);

  const auto result =
      directional::pipeline::build_authoritative_surface_cell_rails(source, map);

  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(result.product().rails.size(), 2U);
  EXPECT_EQ(result.product().rails[0].sourceEdges, std::vector<int>({0}));
  EXPECT_EQ(result.product().rails[1].sourceEdges, std::vector<int>({2}));
  EXPECT_EQ(result.product().rails[0].sourceVertices, std::vector<int>({0, 1}));
  EXPECT_EQ(result.product().rails[1].sourceVertices, std::vector<int>({4, 5}));
  EXPECT_FALSE(result.product().rails[0].closed);
  EXPECT_FALSE(result.product().rails[1].closed);
}

TEST(MilestoneBClosure, ContiguousHardCurveRemainsOneOrderedRail) {
  const StripMesh mesh = make_two_square_strip();
  directional::TriMesh source;
  source.set_mesh(mesh.vertices, mesh.faces);
  const auto map = mixed_curve_map(
      directional::geometry::AdaptiveFeatureClass::Hard);

  const auto result =
      directional::pipeline::build_authoritative_surface_cell_rails(source, map);

  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(result.product().rails.size(), 1U);
  EXPECT_EQ(result.product().rails.front().sourceEdges, std::vector<int>({0, 1, 2}));
  EXPECT_EQ(result.product().rails.front().sourceVertices,
            std::vector<int>({0, 1, 4, 5}));
  EXPECT_EQ(result.product().rails.front().samples.size(), 6U);
}


TEST(MilestoneBClosure, ClosedRailUsesCanonicalCyclicVertexLoop) {
  StripMesh mesh;
  mesh.vertices.resize(4, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3;

  directional::TriMesh source;
  source.set_mesh(mesh.vertices, mesh.faces);

  directional::geometry::AdaptiveFeatureMap map;
  map.edges = {
      feature_edge(0, 1, {0},
                   directional::geometry::AdaptiveFeatureClass::Boundary, 21),
      feature_edge(1, 2, {0},
                   directional::geometry::AdaptiveFeatureClass::Boundary, 21),
      feature_edge(2, 3, {1},
                   directional::geometry::AdaptiveFeatureClass::Boundary, 21),
      feature_edge(3, 0, {1},
                   directional::geometry::AdaptiveFeatureClass::Boundary, 21)};
  for (int index = 0; index < static_cast<int>(map.edges.size()); ++index) {
    map.edgeIndex.emplace(map.edges[static_cast<std::size_t>(index)].vertices,
                          index);
  }
  directional::geometry::AdaptiveFeatureCurve curve;
  curve.id = 21;
  curve.component = 0;
  curve.edges = {0, 1, 2, 3};
  curve.vertices = {0, 1, 2, 3, 0};
  curve.closed = true;
  map.curves.push_back(curve);

  const auto result =
      directional::pipeline::build_authoritative_surface_cell_rails(source, map);

  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(result.product().rails.size(), 1U);
  const auto &rail = result.product().rails.front();
  EXPECT_TRUE(rail.closed);
  EXPECT_EQ(rail.sourceEdges, std::vector<int>({0, 1, 2, 3}));
  EXPECT_EQ(rail.sourceVertices, std::vector<int>({0, 1, 2, 3}));
  EXPECT_EQ(rail.samples.size(), 8U);

  directional::geometry::SurfaceOptimizationConstraints constraints;
  directional::pipeline::fill_surface_cell_rail_constraints(result.product().rails,
                                                              constraints);
  EXPECT_EQ(constraints.authoritativeBoundaryEdges.size(), 4U);
  EXPECT_EQ(constraints.authoritativeBoundaryLoop,
            std::vector<int>({0, 1, 2, 3}));
  EXPECT_EQ(constraints.authoritativeBoundaryEdges.count({0, 0}), 0U);

  directional::geometry::SurfaceCellRail hardRail = rail;
  hardRail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  const auto hardEdges =
      directional::pipeline::hard_feature_edge_keys_from_rails({hardRail});
  EXPECT_EQ(hardEdges.size(), 4U);
  EXPECT_THROW(
      (void)directional::pipeline::surface_cell_source_edge_key(
          0, 0, static_cast<std::size_t>(mesh.vertices.rows())),
      std::invalid_argument);
}

TEST(MilestoneBClosure, InvalidCurveOrderingFailsBeforeTracing) {
  const StripMesh mesh = make_two_square_strip();
  directional::TriMesh source;
  source.set_mesh(mesh.vertices, mesh.faces);
  auto map = mixed_curve_map(
      directional::geometry::AdaptiveFeatureClass::Hard);
  map.curves.front().vertices = {0, 4, 1, 5};

  const auto result =
      directional::pipeline::build_authoritative_surface_cell_rails(source, map);

  ASSERT_TRUE(result.is_rejected());
  ASSERT_NE(result.rejection(), nullptr);
  EXPECT_EQ(result.rejection()->failedEdgeIndex, 0);
  EXPECT_EQ(result.rejection()->kind,
            directional::pipeline::SurfaceCellRailBuildFailureKind::InvalidFeatureEdge);
}
