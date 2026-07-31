#include <directional/validation/SourceAuthoritativeMeshValidator.h>

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::SurfacePoint;
using directional::validation::MeshValidationFailureCode;

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

  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &vertices;
  options.sourceFaces = &sourceFaces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
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
  const std::vector<int> sheets = {0, 1};

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

  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &vertices;
  options.sourceFaces = &sourceFaces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
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

  const directional::validation::source_authoritative_detail::
      SourcePointLabelSupport support(&sourceFaces, &components, &sheets);
  std::vector<const SurfacePoint *> points;
  for (const SurfacePoint &point : provenance) {
    points.push_back(&point);
  }
  EXPECT_FALSE(support.have_compatible_chart(points));
}
