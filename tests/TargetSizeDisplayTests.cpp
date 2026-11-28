#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/TargetSizeDisplay.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

namespace {

struct MetricRun {
  directional::TriMesh mesh;
  directional::pipeline::RemeshResult result;
};

// Stops after the "metric" stage, where target size and features exist.
MetricRun run_torus_to_metric() {
  MetricRun run;
  const auto stem = directional::tests::benchmark_fixture_path("milestone-g/torus");
  if (!directional::readOBJ(stem.string() + ".obj", run.mesh)) {
    throw std::runtime_error("Failed to read torus.obj");
  }
  std::ifstream stream(stem.string() + ".rawfield");
  int degree = 0;
  int faces = 0;
  if (!(stream >> degree >> faces) || degree != 4 || faces != run.mesh.F.rows()) {
    throw std::runtime_error("Invalid torus.rawfield");
  }
  Eigen::MatrixXd raw(faces, 12);
  for (int face = 0; face < faces; ++face) {
    for (int column = 0; column < 12; ++column) stream >> raw(face, column);
  }
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.injectFailureAfterStage = 1;
  options.parallelizeComponents = false;
  run.result = directional::pipeline::remesh_from_raw_cross_field(
      run.mesh.V, run.mesh.F, raw, options);
  return run;
}

} // namespace

TEST(TargetSizeDisplay, CopiesPublishedScalarsAndFeatureEdges) {
  const MetricRun run = run_torus_to_metric();
  const auto &context = run.result.surfaceCellContext;
  ASSERT_TRUE(context.hasMetricField) << run.result.diagnostics.terminalFailureStage;
  ASSERT_TRUE(context.hasFeatureMap) << run.result.diagnostics.terminalFailureStage;
  const auto display = directional::visualization::target_size_display(
      run.mesh.V, run.mesh.F, &context.metricField, &context.featureMap);

  ASSERT_FALSE(display.vertexScalars.empty());
  EXPECT_EQ("target edge length", display.vertexScalars.front().name);
  const Eigen::VectorXd &published = context.metricField.targetSize;
  const auto &shown = display.vertexScalars.front().values;
  ASSERT_EQ(published.size(), shown.size());
  ASSERT_EQ(run.mesh.V.rows(), shown.size());
  for (Eigen::Index i = 0; i < published.size(); ++i) {
    if (std::isfinite(published(i))) EXPECT_EQ(published(i), shown(i)) << i;
  }
  for (const auto &field : display.vertexScalars) {
    EXPECT_TRUE(field.values.allFinite()) << field.name;
  }

  // Exactly the non-smooth published feature edges, in order.
  Eigen::Index row = 0;
  for (const auto &edge : context.featureMap.edges) {
    if (edge.edgeClass == directional::geometry::AdaptiveFeatureClass::Smooth) continue;
    ASSERT_LT(row, display.featureEdges.rows());
    EXPECT_EQ(static_cast<int>(edge.edgeClass), display.featureClass(row));
    EXPECT_TRUE(display.featurePoints.row(display.featureEdges(row, 0)) ==
                run.mesh.V.row(edge.vertices.first));
    EXPECT_TRUE(display.featurePoints.row(display.featureEdges(row, 1)) ==
                run.mesh.V.row(edge.vertices.second));
    EXPECT_NEAR(edge.angleRadians * 180.0 / 3.14159265358979323846, display.featureAngleDegrees(row), 1e-12);
    ++row;
  }
  EXPECT_EQ(row, display.featureEdges.rows());
  EXPECT_GT(row, 0);  // the torus has sharp feature edges
  RecordProperty("scalars", static_cast<int>(display.vertexScalars.size()));
  RecordProperty("featureEdges", static_cast<int>(display.featureEdges.rows()));
}

TEST(TargetSizeDisplay, ShowsInfinitiesAtTheMaximumAndNotesWrongLengths) {
  Eigen::MatrixXd V(3, 3);
  V << 0, 0, 0, 1, 0, 0, 0, 1, 0;
  Eigen::MatrixXi F(1, 3);
  F << 0, 1, 2;
  directional::geometry::AdaptiveTargetSizeResult targetSize;
  targetSize.targetSize = Eigen::Vector3d(1.0, std::numeric_limits<double>::infinity(), 3.0);
  targetSize.thickness = Eigen::Vector2d(1.0, 2.0);
  const auto display =
      directional::visualization::target_size_display(V, F, &targetSize, nullptr);
  ASSERT_EQ(1U, display.vertexScalars.size());
  EXPECT_EQ(1, display.vertexScalars[0].nonFiniteCount);
  EXPECT_EQ(3.0, display.vertexScalars[0].values(1));
  ASSERT_EQ(1U, display.notes.size());
  EXPECT_NE(std::string::npos, display.notes[0].find("thickness"));
  EXPECT_FALSE(display.hasFeatureMap);
  EXPECT_THROW(directional::visualization::target_size_display(V.leftCols(2), F,
                                                               nullptr, nullptr),
               std::invalid_argument);
}
