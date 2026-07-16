#include <cmath>
#include <limits>

#include <gtest/gtest.h>

#include <directional/diagnostics/IntegrationDiagnostics.h>
#include <directional/diagnostics/MesherDiagnostics.h>
#include <directional/diagnostics/RemeshDiagnostics.h>
#include <directional/integration/IntegrationData.h>
#include <directional/meshing/MesherData.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

TEST(DiagnosticsPhase00, IntegrationDataOwnsDefaultDiagnostics) {
  directional::IntegrationData data(4);

  EXPECT_EQ(data.diagnostics.integerIterations, 0U);
  EXPECT_EQ(data.diagnostics.directFactorizations, 0U);
  EXPECT_TRUE(std::isfinite(data.diagnostics.totalSeconds));
  EXPECT_GE(data.diagnostics.totalSeconds, 0.0);
  EXPECT_TRUE(std::isnan(data.diagnostics.finalIntegrationEnergy));
}

TEST(DiagnosticsPhase00, MesherDataOwnsDefaultDiagnostics) {
  directional::MesherData data;

  EXPECT_TRUE(std::isfinite(data.diagnostics.totalMesherSeconds));
  EXPECT_GE(data.diagnostics.totalMesherSeconds, 0.0);
  EXPECT_EQ(data.diagnostics.verticesBeforeSimplification, 0U);
  EXPECT_EQ(data.diagnostics.lowValenceOperationsAccepted, 0U);
}

TEST(DiagnosticsPhase00, RemeshResultAggregatesNestedDiagnostics) {
  directional::pipeline::RemeshResult result;

  result.diagnostics.integration.integerIterations = 3;
  result.diagnostics.mesher.lowValenceOperationsAccepted = 2;
  result.diagnostics.overallPipelineSeconds = 1.25;

  EXPECT_EQ(result.diagnostics.integration.integerIterations, 3U);
  EXPECT_EQ(result.diagnostics.mesher.lowValenceOperationsAccepted, 2U);
  EXPECT_DOUBLE_EQ(result.diagnostics.overallPipelineSeconds, 1.25);
}

} // namespace
