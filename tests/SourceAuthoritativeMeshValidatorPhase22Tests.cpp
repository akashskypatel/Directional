#include <directional/validation/SourceAuthoritativeMeshValidator.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <cstdint>
#include <set>
#include <vector>

#include <gtest/gtest.h>

namespace {

const std::set<directional::authority::SourceEdgeTopologyKey> &no_hard_feature_edges() {
  static const std::set<directional::authority::SourceEdgeTopologyKey> edges;
  return edges;
}

using directional::geometry::SurfacePoint;
using directional::validation::MeshValidationFailureCode;

directional::geometry::SourceTopologyRegions test_source_authority(
    const Eigen::MatrixXi &faces, const std::vector<int> &components,
    const std::vector<int> &sheets) {
  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.sourceFaceComponents = components;
  tracing.sourceFaceSheets = sheets;
  auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, tracing);
  if (!authority.has_value()) {
    throw std::runtime_error("Failed to construct typed test source authority.");
  }
  return std::move(*authority);
}

directional::validation::source_authoritative_detail::TrianglePrimitive
make_triangle_primitive(const Eigen::MatrixXd &vertices, const int a,
                        const int b, const int c, const int parentFace) {
  using directional::validation::source_authoritative_detail::TrianglePrimitive;
  TrianglePrimitive triangle;
  triangle.vertices = {a, b, c};
  triangle.parentFace = parentFace;
  for (const int vertex : triangle.vertices) {
    triangle.bounds.expand(vertices.row(vertex).transpose());
  }
  triangle.bounds.pad(1.0e-9);
  return triangle;
}

bool has_code(
    const directional::validation::SourceAuthoritativeMeshValidationResult &result,
    const MeshValidationFailureCode code) {
  return std::any_of(result.issues.begin(), result.issues.end(),
                     [&](const auto &issue) { return issue.code == code; });
}

std::vector<SurfacePoint> square_provenance(const Eigen::MatrixXd &vertices) {
  std::vector<SurfacePoint> provenance(4);
  provenance[0].face = 0;
  provenance[0].barycentric << 1.0, 0.0, 0.0;
  provenance[1].face = 0;
  provenance[1].barycentric << 0.0, 1.0, 0.0;
  provenance[2].face = 0;
  provenance[2].barycentric << 0.0, 0.0, 1.0;
  provenance[3].face = 1;
  provenance[3].barycentric << 0.0, 0.0, 1.0;
  for (int vertex = 0; vertex < 4; ++vertex) {
    provenance[static_cast<std::size_t>(vertex)].position =
        vertices.row(vertex).transpose();
    provenance[static_cast<std::size_t>(vertex)].component = 0;
    provenance[static_cast<std::size_t>(vertex)].sheet = 0;
  }
  return provenance;
}

} // namespace

TEST(SourceAuthoritativeMeshValidatorPhase22,
     SharedEdgeAllowsLegalAdjacencyButRejectsCoplanarFoldover) {
  using directional::validation::source_authoritative_detail::triangles_intersect;

  Eigen::MatrixXd legal(4, 3);
  legal << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      0.5, 1.0, 0.0,
      1.5, -1.0, 0.0;
  EXPECT_FALSE(triangles_intersect(
      legal, make_triangle_primitive(legal, 0, 1, 2, 0),
      make_triangle_primitive(legal, 1, 0, 3, 1), 1.0e-9));

  Eigen::MatrixXd overlap(4, 3);
  overlap << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      0.5, 1.0, 0.0,
      1.5, 1.0, 0.0;
  EXPECT_TRUE(triangles_intersect(
      overlap, make_triangle_primitive(overlap, 0, 1, 2, 0),
      make_triangle_primitive(overlap, 1, 0, 3, 1), 1.0e-9));
}

TEST(SourceAuthoritativeMeshValidatorPhase22,
     MissingSourceAuthorityRejectsEvenWhenOptionalGatesAreDisabled) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  const std::vector<SurfacePoint> provenance = square_provenance(vertices);

  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &vertices;
  options.sourceFaces = &sourceFaces;
  options.vertexProvenance = &provenance;
  options.requireBoundaryAuthority = false;
  options.requireFeatureRailAuthority = false;
  options.requireLocalSheetCompatibility = false;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          vertices, quads, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_FALSE(result.sourceAuthorityUsed);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::MissingSourceAuthority));
}

TEST(SourceAuthoritativeMeshValidatorPhase22,
     SameExtentForeignSourceAuthorityRejectsBeforeOptionalGates) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXi foreignFaces(2, 3);
  foreignFaces << 0, 1, 3,
      1, 2, 3;
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  const std::vector<SurfacePoint> provenance = square_provenance(vertices);
  const auto foreignAuthority =
      test_source_authority(foreignFaces, {0, 0}, {0, 0});
  ASSERT_FALSE(foreignAuthority.matches_source_faces(
      sourceFaces, static_cast<std::size_t>(vertices.rows())));

  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &vertices;
  options.sourceFaces = &sourceFaces;
  options.sourceAuthority = &foreignAuthority;
  options.vertexProvenance = &provenance;
  options.requireBoundaryAuthority = false;
  options.requireFeatureRailAuthority = false;
  options.requireLocalSheetCompatibility = false;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          vertices, quads, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_FALSE(result.sourceAuthorityUsed);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::MissingSourceAuthority));
}

TEST(SourceAuthoritativeMeshValidatorPhase22,
     SourceOrientationRemainsAuthoritativeWhenSheetGateIsDisabled) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXi reversed(1, 4);
  reversed << 0, 3, 2, 1;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const std::vector<SurfacePoint> provenance = square_provenance(vertices);

  const auto sourceAuthority =
      test_source_authority(sourceFaces, components, sheets);
  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &vertices;
  options.sourceFaces = &sourceFaces;
  options.sourceAuthority = &sourceAuthority;
  options.vertexProvenance = &provenance;
  options.authoritativeBoundaryLoops = {{0, 1, 2, 3}};
  options.requireLocalSheetCompatibility = false;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          vertices, reversed, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::FlippedFace));
}

TEST(SourceAuthoritativeMeshValidatorPhase22,
     EdgeAdjacentSourceChartsMaySupportOneOutputQuad) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};

  std::vector<SurfacePoint> provenance(4);
  const auto assign = [&](const int outputVertex, const int sourceFace,
                          const int sourceCorner) {
    SurfacePoint &point = provenance[static_cast<std::size_t>(outputVertex)];
    point.face = sourceFace;
    point.component = components[static_cast<std::size_t>(sourceFace)];
    point.sheet = sheets[static_cast<std::size_t>(sourceFace)];
    point.barycentric = Eigen::Vector3d::Zero();
    point.barycentric(sourceCorner) = 1.0;
    point.position = vertices.row(outputVertex).transpose();
    point.squaredDistance = 0.0;
  };
  assign(0, 0, 0);
  assign(1, 0, 1);
  assign(2, 0, 2);
  assign(3, 1, 2);

  const auto sourceAuthority =
      test_source_authority(sourceFaces, components, sheets);
  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &vertices;
  options.sourceFaces = &sourceFaces;
  options.sourceAuthority = &sourceAuthority;
  options.vertexProvenance = &provenance;
  options.authoritativeBoundaryLoops = {{0, 1, 2, 3}};

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          vertices, quads, options);
  EXPECT_TRUE(result.accepted);
  EXPECT_TRUE(result.localSheetCompatibilityPassed);
}

TEST(SourceAuthoritativeMeshValidatorPhase22,
     NonAdjacentChartsInOneComponentRemainIncompatible) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 0.0, 0.001,
      1.0, 0.0, 0.001,
      0.0, 1.0, 0.001;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      3, 4, 5;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 1};
  std::vector<SurfacePoint> provenance(4);
  const std::array<std::pair<int, int>, 4> sourceCorners = {
      std::pair<int, int>{0, 0}, {0, 1}, {1, 1}, {1, 2}};
  for (int vertex = 0; vertex < 4; ++vertex) {
    const auto [face, corner] = sourceCorners[static_cast<std::size_t>(vertex)];
    SurfacePoint &point = provenance[static_cast<std::size_t>(vertex)];
    point.face = face;
    point.component = 0;
    point.sheet = sheets[static_cast<std::size_t>(face)];
    point.barycentric = Eigen::Vector3d::Zero();
    point.barycentric(corner) = 1.0;
    point.position = vertices.row(sourceFaces(face, corner)).transpose();
    point.squaredDistance = 0.0;
  }

  const auto sourceAuthority =
      test_source_authority(sourceFaces, components, sheets);
  const directional::validation::source_authoritative_detail::
      SourcePointLabelSupport support(&sourceFaces, &sourceAuthority,
                                      &no_hard_feature_edges());
  std::vector<const SurfacePoint *> points;
  for (const SurfacePoint &point : provenance) {
    points.push_back(&point);
  }
  EXPECT_FALSE(support.have_compatible_chart(points));
}


TEST(SourceAuthoritativeMeshValidatorPhase22,
     HardRailPreventsChartCompatibilityAcrossSharedSourceEdge) {
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      2, 1, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto hardEdge = directional::authority::SourceEdgeTopologyKey::from_indices(
      1, 2, 4);
  ASSERT_TRUE(hardEdge);
  const std::set<directional::authority::SourceEdgeTopologyKey> hardEdges = {
      hardEdge.value()};

  SurfacePoint first;
  first.face = 0;
  first.component = 0;
  first.sheet = 0;
  first.barycentric << 0.0, 0.5, 0.5;
  SurfacePoint second = first;
  second.face = 1;
  second.barycentric << 0.5, 0.5, 0.0;

  const auto sourceAuthority =
      test_source_authority(sourceFaces, components, sheets);
  const directional::validation::source_authoritative_detail::
      SourcePointLabelSupport support(&sourceFaces, &sourceAuthority, &hardEdges);
  const std::vector<const SurfacePoint *> points = {&first, &second};
  EXPECT_FALSE(support.have_compatible_chart(points));
}

TEST(SourceAuthoritativeMeshValidatorPhase22,
     NonConsecutiveChartsReconcileThroughOneIntrinsicVertexFan) {
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3,
      0, 3, 4,
      0, 4, 1;
  const std::vector<int> components = {0, 0, 0, 0};
  const std::vector<int> sheets = {0, 0, 0, 0};

  SurfacePoint first;
  first.face = 0;
  first.component = 0;
  first.sheet = 0;
  first.barycentric << 1.0, 0.0, 0.0;
  SurfacePoint opposite = first;
  opposite.face = 2;

  const auto sourceAuthority =
      test_source_authority(sourceFaces, components, sheets);
  const directional::validation::source_authoritative_detail::
      SourcePointLabelSupport support(&sourceFaces, &sourceAuthority,
                                      &no_hard_feature_edges());
  const std::vector<const SurfacePoint *> points = {&first, &opposite};
  EXPECT_TRUE(support.have_compatible_chart(points));
}
