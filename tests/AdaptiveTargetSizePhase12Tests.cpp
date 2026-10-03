#include <directional/geometry/AdaptiveTargetSize.h>
#include <directional/pipeline/RemeshPipeline.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshFixture make_grid(const int n) {
  MeshFixture mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices.row(vertex) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  mesh.faces.resize(2 * n * n, 3);
  int face = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int v00 = y * (n + 1) + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * (n + 1) + x;
      const int v11 = v01 + 1;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

MeshFixture make_box_grid(const int n, const double thickness,
                          const double zOffset = 0.0) {
  MeshFixture mesh;
  const int layer = (n + 1) * (n + 1);
  mesh.vertices.resize(2 * layer, 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int bottom = y * (n + 1) + x;
      const int top = layer + bottom;
      mesh.vertices.row(bottom) << static_cast<double>(x),
          static_cast<double>(y), zOffset;
      mesh.vertices.row(top) << static_cast<double>(x), static_cast<double>(y),
          zOffset + thickness;
    }
  }

  std::vector<Eigen::Vector3i> faces;
  faces.reserve(static_cast<std::size_t>(4 * n * n + 8 * n));
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int b00 = y * (n + 1) + x;
      const int b10 = b00 + 1;
      const int b01 = (y + 1) * (n + 1) + x;
      const int b11 = b01 + 1;
      const int t00 = layer + b00;
      const int t10 = layer + b10;
      const int t01 = layer + b01;
      const int t11 = layer + b11;
      faces.push_back({b00, b11, b10});
      faces.push_back({b00, b01, b11});
      faces.push_back({t00, t10, t11});
      faces.push_back({t00, t11, t01});
    }
  }
  for (int x = 0; x < n; ++x) {
    const int b0 = x;
    const int b1 = x + 1;
    const int t0 = layer + b0;
    const int t1 = layer + b1;
    faces.push_back({b0, b1, t1});
    faces.push_back({b0, t1, t0});

    const int by0 = n * (n + 1) + x;
    const int by1 = by0 + 1;
    const int ty0 = layer + by0;
    const int ty1 = layer + by1;
    faces.push_back({by0, ty1, by1});
    faces.push_back({by0, ty0, ty1});
  }
  for (int y = 0; y < n; ++y) {
    const int b0 = y * (n + 1);
    const int b1 = (y + 1) * (n + 1);
    const int t0 = layer + b0;
    const int t1 = layer + b1;
    faces.push_back({b0, t1, b1});
    faces.push_back({b0, t0, t1});

    const int bx0 = y * (n + 1) + n;
    const int bx1 = (y + 1) * (n + 1) + n;
    const int tx0 = layer + bx0;
    const int tx1 = layer + bx1;
    faces.push_back({bx0, bx1, tx1});
    faces.push_back({bx0, tx1, tx0});
  }

  mesh.faces.resize(static_cast<int>(faces.size()), 3);
  for (int face = 0; face < static_cast<int>(faces.size()); ++face) {
    mesh.faces.row(face) = faces[static_cast<std::size_t>(face)];
  }
  return mesh;
}

MeshFixture combine(const MeshFixture &a, const MeshFixture &b) {
  MeshFixture mesh;
  mesh.vertices.resize(a.vertices.rows() + b.vertices.rows(), 3);
  mesh.vertices.topRows(a.vertices.rows()) = a.vertices;
  mesh.vertices.bottomRows(b.vertices.rows()) = b.vertices;
  mesh.faces.resize(a.faces.rows() + b.faces.rows(), 3);
  mesh.faces.topRows(a.faces.rows()) = a.faces;
  mesh.faces.bottomRows(b.faces.rows()) =
      b.faces.array() + static_cast<int>(a.vertices.rows());
  return mesh;
}

MeshFixture make_open_cylinder(const int segments, const double radius,
                               const double height) {
  MeshFixture mesh;
  mesh.vertices.resize(2 * segments, 3);
  constexpr double pi = 3.14159265358979323846;
  for (int i = 0; i < segments; ++i) {
    const double angle = 2.0 * pi * static_cast<double>(i) /
                         static_cast<double>(segments);
    const double x = radius * std::cos(angle);
    const double y = radius * std::sin(angle);
    mesh.vertices.row(i) << x, y, 0.0;
    mesh.vertices.row(segments + i) << x, y, height;
  }
  mesh.faces.resize(2 * segments, 3);
  for (int i = 0; i < segments; ++i) {
    const int j = (i + 1) % segments;
    mesh.faces.row(2 * i) << i, j, segments + j;
    mesh.faces.row(2 * i + 1) << i, segments + j, segments + i;
  }
  return mesh;
}

double percentile(std::vector<double> values, const double q) {
  std::sort(values.begin(), values.end());
  const std::size_t index = static_cast<std::size_t>(
      std::floor(q * static_cast<double>(values.size() - 1) + 0.5));
  return values[index];
}

} // namespace

TEST(AdaptiveTargetSizePhase12, GraphDistancesOnPlaneGridAreExact) {
  const MeshFixture mesh = make_grid(2);
  const auto result =
      directional::geometry::compute_intrinsic_graph_distances(
          mesh.vertices, mesh.faces, {0});

  ASSERT_EQ(result.distance.size(), 9);
  EXPECT_DOUBLE_EQ(result.distance[0], 0.0);
  EXPECT_DOUBLE_EQ(result.distance[1], 1.0);
  EXPECT_DOUBLE_EQ(result.distance[3], 1.0);
  EXPECT_DOUBLE_EQ(result.distance[4], std::sqrt(2.0));
  EXPECT_DOUBLE_EQ(result.distance[8], 2.0 * std::sqrt(2.0));
}

TEST(AdaptiveTargetSizePhase12, PlateThicknessMedianAndP95MeetGate) {
  constexpr double expected = 0.2;
  const MeshFixture mesh = make_box_grid(5, expected);
  const auto result =
      directional::geometry::estimate_local_thickness(mesh.vertices, mesh.faces);

  const int layer = 6 * 6;
  std::vector<double> errors;
  for (int y = 2; y <= 3; ++y) {
    for (int x = 2; x <= 3; ++x) {
      const int top = layer + y * 6 + x;
      ASSERT_TRUE(std::isfinite(result.thickness[top]));
      errors.push_back(std::abs(result.thickness[top] - expected) / expected);
    }
  }
  EXPECT_LE(percentile(errors, 0.50), 0.10);
  EXPECT_LE(percentile(errors, 0.95), 0.20);
}

TEST(AdaptiveTargetSizePhase12, ThicknessDoesNotCoupleCloseComponents) {
  const MeshFixture base = make_box_grid(5, 0.2);
  const MeshFixture close = make_box_grid(5, 0.02, 0.23);
  const MeshFixture combined = combine(base, close);

  directional::geometry::LocalThicknessOptions options;
  options.sameComponentOnly = true;
  const auto sameComponent =
      directional::geometry::estimate_local_thickness(combined.vertices,
                                                      combined.faces, options);

  options.sameComponentOnly = false;
  const auto crossComponent =
      directional::geometry::estimate_local_thickness(combined.vertices,
                                                      combined.faces, options);

  const int topCenter = 36 + 3 * 6 + 3;
  ASSERT_TRUE(std::isfinite(sameComponent.thickness[topCenter]));
  ASSERT_TRUE(std::isfinite(crossComponent.thickness[topCenter]));
  EXPECT_NEAR(sameComponent.thickness[topCenter], 0.2, 0.02);
  EXPECT_LT(crossComponent.thickness[topCenter],
            sameComponent.thickness[topCenter]);
}

TEST(AdaptiveTargetSizePhase12, CylinderThicknessMedianMeetsGate) {
  constexpr double radius = 1.0;
  const MeshFixture mesh = make_open_cylinder(48, radius, 2.0);
  const auto result =
      directional::geometry::estimate_local_thickness(mesh.vertices, mesh.faces);

  std::vector<double> errors;
  for (int vertex = 0; vertex < mesh.vertices.rows(); ++vertex) {
    ASSERT_TRUE(std::isfinite(result.thickness[vertex]));
    errors.push_back(std::abs(result.thickness[vertex] - 2.0 * radius) /
                     (2.0 * radius));
  }
  EXPECT_LE(percentile(errors, 0.50), 0.10);
  EXPECT_LE(percentile(errors, 0.95), 0.20);
}

TEST(AdaptiveTargetSizePhase12, CurvatureChordErrorCapMatchesFormula) {
  const MeshFixture mesh = make_grid(1);
  directional::geometry::AdaptiveTargetSizeInput input;
  input.curvature = Eigen::VectorXd::Constant(mesh.vertices.rows(), 2.0);

  directional::geometry::AdaptiveTargetSizeOptions options;
  options.baseSize = 1.0;
  options.minSize = 0.01;
  options.maxSize = 10.0;
  options.absoluteSurfaceError = 0.01;
  options.gradationPasses = 0;
  const auto result = directional::geometry::compute_adaptive_target_size(
      mesh.vertices, mesh.faces, input, options);

  const double expected =
      std::sqrt(8.0 * options.absoluteSurfaceError /
                (2.0 + options.curvatureEpsilon));
  for (int vertex = 0; vertex < result.targetSize.size(); ++vertex) {
    EXPECT_NEAR(result.targetSize[vertex], expected, 1.0e-12);
  }
}

TEST(AdaptiveTargetSizePhase12, ClampsAndFiniteRangeHold) {
  const MeshFixture mesh = make_grid(1);
  directional::geometry::AdaptiveTargetSizeInput input;
  input.salience = Eigen::VectorXd::Constant(mesh.vertices.rows(), 100.0);
  input.featureDensity =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 100.0);
  input.curvature =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0e12);
  input.thickness = Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0e-9);

  directional::geometry::AdaptiveTargetSizeOptions options;
  options.baseSize = 1.0;
  options.minSize = 0.05;
  options.maxSize = 0.5;
  const auto result = directional::geometry::compute_adaptive_target_size(
      mesh.vertices, mesh.faces, input, options);

  EXPECT_TRUE(result.allFinite);
  for (int vertex = 0; vertex < result.targetSize.size(); ++vertex) {
    EXPECT_GE(result.targetSize[vertex], options.minSize);
    EXPECT_LE(result.targetSize[vertex], options.maxSize);
  }
}

TEST(AdaptiveTargetSizePhase12, GradationEnforcesTwoToOneEdgeRatios) {
  const MeshFixture mesh = make_grid(4);
  Eigen::VectorXd sizes(mesh.vertices.rows());
  for (int vertex = 0; vertex < sizes.size(); ++vertex) {
    sizes[vertex] = vertex % 2 == 0 ? 1.0 : 100.0;
  }
  const Eigen::VectorXd graded =
      directional::geometry::apply_size_gradation(mesh.vertices, mesh.faces,
                                                  sizes, 2.0, 64);
  const auto graph =
      directional::geometry::compute_intrinsic_graph_distances(mesh.vertices,
                                                              mesh.faces, {});
  for (const auto &[a, b] : graph.edges) {
    const double lo = std::min(graded[a], graded[b]);
    const double hi = std::max(graded[a], graded[b]);
    EXPECT_LE(hi / lo, 2.0 + 1.0e-12);
  }
}

TEST(AdaptiveTargetSizePhase12, ThinHandleRetainsThreeTargetCells) {
  const MeshFixture mesh = make_grid(1);
  directional::geometry::AdaptiveTargetSizeInput input;
  input.thickness = Eigen::VectorXd::Constant(mesh.vertices.rows(), 0.3);

  directional::geometry::AdaptiveTargetSizeOptions options;
  options.baseSize = 1.0;
  options.minSize = 0.01;
  options.maxSize = 1.0;
  options.thicknessScale = 1.0 / 3.0;
  const auto result = directional::geometry::compute_adaptive_target_size(
      mesh.vertices, mesh.faces, input, options);

  for (int vertex = 0; vertex < result.targetSize.size(); ++vertex) {
    EXPECT_LE(result.targetSize[vertex], 0.1 + 1.0e-12);
    EXPECT_GE(0.3 / result.targetSize[vertex], 3.0 - 1.0e-12);
  }
}

TEST(AdaptiveTargetSizePhase12, OverlayVectorsHaveVertexDimensions) {
  const MeshFixture mesh = make_grid(2);
  directional::geometry::AdaptiveTargetSizeInput input;
  input.salience = Eigen::VectorXd::LinSpaced(mesh.vertices.rows(), 0.0, 1.0);
  input.featureDensity =
      Eigen::VectorXd::LinSpaced(mesh.vertices.rows(), 1.0, 0.0);
  const auto result = directional::geometry::compute_adaptive_target_size(
      mesh.vertices, mesh.faces, input);

  EXPECT_EQ(result.normalizedSalience.size(), mesh.vertices.rows());
  EXPECT_EQ(result.normalizedFeatureDensity.size(), mesh.vertices.rows());
  EXPECT_EQ(result.curvatureSize.size(), mesh.vertices.rows());
  EXPECT_EQ(result.thicknessSize.size(), mesh.vertices.rows());
  EXPECT_EQ(result.targetSize.size(), mesh.vertices.rows());
}

TEST(AdaptiveTargetSizePhase12, SurfaceCellScaffoldPopulatesSizeDiagnostics) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd primary(mesh.faces.rows(), 3);
  primary.setZero();
  primary.col(0).setOnes();
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.targetSize.baseSize = 0.25;
  options.surfaceCells.targetSize.minSize = 0.05;
  options.surfaceCells.targetSize.maxSize = 1.0;

  const auto result =
      directional::pipeline::remesh_from_cross_field(mesh.vertices, mesh.faces,
                                                    primary, options);

  EXPECT_GT(result.diagnostics.adaptiveTargetSizeSeconds, 0.0);
  EXPECT_EQ(result.diagnostics.adaptiveTargetSizeFiniteVertexCount,
            static_cast<std::size_t>(mesh.vertices.rows()));
  EXPECT_EQ(result.diagnostics.adaptiveTargetSizeNonFiniteVertexCount, 0U);
  EXPECT_GE(result.diagnostics.adaptiveTargetSizeMin,
            options.surfaceCells.targetSize.minSize);
  EXPECT_LE(result.diagnostics.adaptiveTargetSizeMax,
            options.surfaceCells.targetSize.maxSize);
}

TEST(AdaptiveTargetSizePhase12, PrincipalCurvatureEstimatorDrivesSizing) {
  constexpr double radius = 2.0;
  const MeshFixture mesh = make_open_cylinder(48, radius, 2.0);

  const auto curvature =
      directional::geometry::estimate_principal_vertex_curvature(mesh.vertices,
                                                                 mesh.faces);

  ASSERT_EQ(curvature.curvature.size(), mesh.vertices.rows());
  EXPECT_GT(curvature.confidence.mean(), 0.3);
  EXPECT_NEAR(curvature.curvature.mean(), 1.0 / radius, 0.12);

  directional::geometry::AdaptiveFeatureMap featureMap =
      directional::geometry::AdaptiveFeatureMapBuilder::build(mesh.vertices,
                                                              mesh.faces);
  directional::geometry::AdaptiveTargetSizeOptions options;
  options.baseSize = 1.0;
  options.minSize = 0.01;
  options.maxSize = 10.0;
  options.absoluteSurfaceError = 0.01;
  options.gradationPasses = 0;
  const auto result = directional::geometry::compute_adaptive_target_size(
      mesh.vertices, mesh.faces, featureMap, options);

  EXPECT_LT(result.curvature.mean(), 0.75);
  EXPECT_GT(result.curvature.mean(), 0.25);
}

TEST(AdaptiveTargetSizePhase12, ThicknessHonorsSheetFilterWhenComponentsAreClose) {
  const MeshFixture base = make_box_grid(5, 0.2);
  const MeshFixture close = make_box_grid(5, 0.02, 0.23);
  const MeshFixture combined = combine(base, close);

  directional::geometry::LocalThicknessOptions unfiltered;
  unfiltered.sameComponentOnly = false;
  const auto crossSheet =
      directional::geometry::estimate_local_thickness(combined.vertices,
                                                      combined.faces,
                                                      unfiltered);

  directional::geometry::LocalThicknessOptions sheetFiltered = unfiltered;
  sheetFiltered.faceSheets.resize(static_cast<std::size_t>(combined.faces.rows()),
                                  0);
  for (int face = base.faces.rows(); face < combined.faces.rows(); ++face) {
    sheetFiltered.faceSheets[static_cast<std::size_t>(face)] = 1;
  }
  const auto sameSheet =
      directional::geometry::estimate_local_thickness(combined.vertices,
                                                      combined.faces,
                                                      sheetFiltered);

  const int topCenter = 36 + 3 * 6 + 3;
  ASSERT_TRUE(std::isfinite(crossSheet.thickness[topCenter]));
  ASSERT_TRUE(std::isfinite(sameSheet.thickness[topCenter]));
  EXPECT_LT(crossSheet.thickness[topCenter], sameSheet.thickness[topCenter]);
  EXPECT_NEAR(sameSheet.thickness[topCenter], 0.2, 0.02);
}

TEST(AdaptiveTargetSizePhase12, OptionalHeatAndSkeletonHintsFailFast) {
  const MeshFixture mesh = make_grid(1);
  directional::geometry::AdaptiveTargetSizeInput input;
  directional::geometry::AdaptiveTargetSizeOptions options;
  options.enableHeatDistance = true;
  EXPECT_THROW((void)directional::geometry::compute_adaptive_target_size(
                   mesh.vertices, mesh.faces, input, options),
               std::invalid_argument);

  options.enableHeatDistance = false;
  options.enableSkeletonHints = true;
  EXPECT_THROW((void)directional::geometry::compute_adaptive_target_size(
                   mesh.vertices, mesh.faces, input, options),
               std::invalid_argument);
}
