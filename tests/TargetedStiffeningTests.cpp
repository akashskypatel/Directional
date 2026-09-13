#include <cmath>

#include <gtest/gtest.h>

#include <directional/integration/IntegrationData.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

SyntheticMesh make_grid_mesh(const int subdivisions) {
  const int n = std::max(1, subdivisions);
  SyntheticMesh mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices(vertex, 0) = static_cast<double>(x) / n;
      mesh.vertices(vertex, 1) = static_cast<double>(y) / n;
      mesh.vertices(vertex, 2) = 0.0;
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

directional::pipeline::RemeshResult run_integration_only(
    const bool enableTargetedStiffening) {
  const SyntheticMesh mesh = make_grid_mesh(1);
  directional::pipeline::RemeshOptions options;
  options.verbose = false;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.stopAfterIntegration = true;
  options.useTargetedParametrizationStiffening = enableTargetedStiffening;
  options.targetedStiffening.enabled = enableTargetedStiffening;
  return directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                                 options);
}

directional::pipeline::RemeshResult run_broad_bad_region_probe() {
  const SyntheticMesh mesh = make_grid_mesh(1);
  directional::pipeline::RemeshOptions options;
  options.verbose = false;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.stopAfterIntegration = true;
  options.useTargetedParametrizationStiffening = true;
  options.targetedStiffening.enabled = true;
  options.targetedStiffening.maximumBadFaceFraction = 0.25;
  options.targetedStiffening.thresholds.maximumConditionNumber = 0.1;
  return directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                                 options);
}

} // namespace

TEST(TargetedStiffeningPhase09, IntegrationDataDisablesStiffeningByDefault) {
  const directional::IntegrationData data(4);

  EXPECT_FALSE(data.targetedStiffening.enabled);
  EXPECT_EQ(data.targetedStiffening.maximumPasses, 1);
}

TEST(TargetedStiffeningPhase09, StiffeningPreservesFixedIntegerVariables) {
  const directional::pipeline::RemeshResult result =
      run_integration_only(true);

  ASSERT_TRUE(result.is_produced());
  const directional::IntegrationDiagnostics &diagnostics =
      result.diagnostics.integration;
  EXPECT_TRUE(std::isfinite(diagnostics.maximumUnresolvedIntegerResidual));
  EXPECT_LE(diagnostics.maximumUnresolvedIntegerResidual, 1.0e-8);
}

TEST(TargetedStiffeningPhase09, StiffeningDoesNotWorsenConstraintResidual) {
  const directional::pipeline::RemeshResult baseline =
      run_integration_only(false);
  const directional::pipeline::RemeshResult stiffened =
      run_integration_only(true);

  ASSERT_TRUE(baseline.is_produced());
  ASSERT_TRUE(stiffened.is_produced());
  const double tolerance =
      1.0e-8 * std::max(1.0, baseline.diagnostics.integration
                                 .finalConstraintResidualNorm);

  EXPECT_LE(stiffened.diagnostics.integration.finalConstraintResidualNorm,
            baseline.diagnostics.integration.finalConstraintResidualNorm +
                tolerance);
}

TEST(TargetedStiffeningPhase09, SyntheticFixtureRecordsQualityDiagnostics) {
  const directional::pipeline::RemeshResult result =
      run_integration_only(true);

  ASSERT_TRUE(result.is_produced());
  const directional::IntegrationDiagnostics &diagnostics =
      result.diagnostics.integration;
  EXPECT_TRUE(std::isfinite(diagnostics.parametrizationQualityAnalysisSeconds));
  EXPECT_GE(diagnostics.parametrizationQualityAnalysisSeconds, 0.0);
  EXPECT_GE(diagnostics.parametrizationInitialBadFaceCount,
            diagnostics.parametrizationPostStiffeningBadFaceCount);
  EXPECT_LE(diagnostics.targetedStiffeningPasses, 1U);
}

TEST(TargetedStiffeningPhase09, BroadBadFaceRegionDoesNotTriggerExtraSolve) {
  const directional::pipeline::RemeshResult result =
      run_broad_bad_region_probe();

  ASSERT_TRUE(result.is_produced());
  const directional::IntegrationDiagnostics &diagnostics =
      result.diagnostics.integration;
  EXPECT_GT(diagnostics.parametrizationInitialBadFaceCount, 0U);
  EXPECT_EQ(diagnostics.parametrizationInitialBadFaceCount,
            diagnostics.parametrizationPostStiffeningBadFaceCount);
  EXPECT_EQ(diagnostics.targetedStiffeningPasses, 0U);
  EXPECT_EQ(diagnostics.targetedStiffeningExtraFactorizations, 0U);
  EXPECT_DOUBLE_EQ(diagnostics.targetedStiffeningExtraSolveSeconds, 0.0);
}
