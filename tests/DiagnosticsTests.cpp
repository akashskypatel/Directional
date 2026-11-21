#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include <directional/diagnostics/IntegrationDiagnostics.h>
#include <directional/diagnostics/MesherDiagnostics.h>
#include <directional/diagnostics/RemeshDiagnostics.h>
#include <directional/integration/IntegrationData.h>
#include <directional/meshing/MesherData.h>
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

directional::pipeline::RemeshResult run_tiny_synthetic_remesh() {
  const SyntheticMesh mesh = make_grid_mesh(2);
  directional::pipeline::RemeshOptions options;
  options.verbose = false;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  return directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                                  options);
}

void expect_nonnegative_finite(const double value) {
  EXPECT_TRUE(std::isfinite(value));
  EXPECT_GE(value, 0.0);
}

std::string read_text_file(const std::filesystem::path &path) {
  std::ifstream stream(path);
  std::ostringstream buffer;
  buffer << stream.rdbuf();
  return buffer.str();
}

void expect_contains(const std::string &text, const std::string &needle) {
  EXPECT_NE(text.find(needle), std::string::npos) << needle;
}

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

TEST(DiagnosticsPhase00, SyntheticRemeshDiagnosticsArePopulatedWithoutVerbose) {
  const directional::pipeline::RemeshResult result =
      run_tiny_synthetic_remesh();

  ASSERT_TRUE(result.is_produced());
  EXPECT_GT(result.product().vertices.rows(), 0);
  EXPECT_GT(result.product().faces.rows(), 0);

  const directional::IntegrationDiagnostics &integration =
      result.diagnostics.integration;
  expect_nonnegative_finite(integration.totalSeconds);
  expect_nonnegative_finite(integration.symbolicAnalysisSeconds);
  expect_nonnegative_finite(integration.numericFactorizationSeconds);
  expect_nonnegative_finite(integration.backSubstitutionSeconds);
  EXPECT_GE(integration.integerIterations, 1U);
  EXPECT_EQ(integration.directFactorizations, integration.integerIterations);
  EXPECT_TRUE(std::isfinite(integration.finalLinearSystemResidualNorm));
  EXPECT_TRUE(std::isfinite(integration.finalConstraintResidualNorm));
  EXPECT_TRUE(std::isfinite(integration.finalIntegrationEnergy));

  const directional::MesherDiagnostics &mesher = result.diagnostics.mesher;
  expect_nonnegative_finite(mesher.totalMesherSeconds);
  expect_nonnegative_finite(mesher.generateArrangementSeconds);
  expect_nonnegative_finite(mesher.simplifyTotalSeconds);
  expect_nonnegative_finite(mesher.retwinSeconds);
  EXPECT_GT(mesher.verticesBeforeSimplification, 0U);
  EXPECT_GT(mesher.facesBeforeSimplification, 0U);
  EXPECT_GT(mesher.halfedgesBeforeSimplification, 0U);
  EXPECT_GT(mesher.verticesAfterSimplification, 0U);
  EXPECT_GT(mesher.facesAfterSimplification, 0U);
  EXPECT_GT(mesher.halfedgesAfterSimplification, 0U);
}

TEST(DiagnosticsPhase00, RemeshDiagnosticsContainNestedStageTotals) {
  const directional::pipeline::RemeshResult result =
      run_tiny_synthetic_remesh();

  ASSERT_TRUE(result.is_produced());
  const directional::RemeshDiagnostics &diagnostics = result.diagnostics;
  EXPECT_TRUE(diagnostics.overallPipelineTimeAvailable);
  expect_nonnegative_finite(diagnostics.overallPipelineSeconds);
  expect_nonnegative_finite(diagnostics.setupIntegrationSeconds);
  expect_nonnegative_finite(diagnostics.integrationTotalSeconds);
  expect_nonnegative_finite(diagnostics.setupMesherSeconds);
  expect_nonnegative_finite(diagnostics.mesherTotalSeconds);

  constexpr double timerTolerance = 1.0e-6;
  EXPECT_GE(diagnostics.overallPipelineSeconds + timerTolerance,
            diagnostics.setupIntegrationSeconds);
  EXPECT_GE(diagnostics.overallPipelineSeconds + timerTolerance,
            diagnostics.integrationTotalSeconds);
  EXPECT_GE(diagnostics.overallPipelineSeconds + timerTolerance,
            diagnostics.setupMesherSeconds);
  EXPECT_GE(diagnostics.overallPipelineSeconds + timerTolerance,
            diagnostics.mesherTotalSeconds);
}

TEST(DiagnosticsPhase00, DiagnosticsDoNotChangeSyntheticSignature) {
  const directional::pipeline::RemeshResult first =
      run_tiny_synthetic_remesh();
  const directional::pipeline::RemeshResult second =
      run_tiny_synthetic_remesh();

  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());
  ASSERT_EQ(first.product().vertices.rows(), second.product().vertices.rows());
  ASSERT_EQ(first.product().faces.rows(), second.product().faces.rows());
  ASSERT_EQ(first.product().degrees.size(), second.product().degrees.size());
  EXPECT_EQ(first.product().degrees.sum(), second.product().degrees.sum());
  EXPECT_EQ((first.product().degrees.array() == 4).count(),
            (second.product().degrees.array() == 4).count());
}

TEST(DiagnosticsPhase00, BenchmarkJsonRoundTripsRequiredFields) {
  const std::filesystem::path path =
      std::filesystem::temp_directory_path() /
      "directional_benchmark_roundtrip.json";
  {
    std::ofstream output(path);
    ASSERT_TRUE(output.good());
    output << R"json({
  "schema": 1,
  "timestamp": "2026-07-16T00:00:00Z",
  "buildType": "Release",
  "compiler": "test",
  "platform": "test",
  "cpuDescription": "test",
  "selectedIntegrationBackend": "Eigen SparseLU",
  "cases": [{
    "name": "synthetic_grid_2",
    "fixturePath": "synthetic",
    "fixtureHash": "abc",
    "field": {"source": "generated", "method": "smooth"},
    "remeshOptions": {"lengthRatio": 0.2},
    "runs": [{
      "success": true,
      "wallSeconds": 0.1,
      "diagnostics": {
        "overallPipelineSeconds": 0.1,
        "overallPipelineTimeAvailable": true,
        "remeshBackend": "SurfaceCells",
        "requestedBackend": "SurfaceCells",
        "executedBackend": "SurfaceCells",
        "surfaceCellFallbackPolicy": "Fail",
        "surfaceCellFallbackCause": "",
        "originalSurfaceCellFailureCode": "NotProductionReady",
        "originalSurfaceCellFailureStage": "production-gate",
        "terminalFailureCode": "NotProductionReady",
        "terminalFailureStage": "production-gate",
        "surfaceCellFallbackAttempted": false,
        "surfaceCellUsedLegacyFallback": false,
        "surfaceCellReturnedInputMeshFallback": false,
        "surfaceCellRemeshOccurred": false,
        "surfaceCellOutputOrigin": "None",
        "surfaceCellStageLineage": [{
          "stage": "completion",
          "inputObjectHash": "simplification:count=1",
          "outputObjectHash": "completion:count=1",
          "objectCount": 1,
          "available": true,
          "consumedByNextStage": true,
          "consumptionKind": "Full",
          "componentIndex": null,
          "durationSeconds": 0.001,
          "terminalFailureCode": "None",
          "terminalFailureStage": ""
        }],
        "surfaceCellContextProducts": [{
          "name": "completion",
          "type": "completion",
          "structuralHash": 17,
          "elementCount": 1,
          "available": true
        }],
        "surfaceCellValidationSeconds": 0.0,
        "surfaceCellValidationFailures": 0,
        "surfaceCellProvenanceVertexCount": 0,
        "surfaceCellFeatureCount": 0,
        "surfaceCellMetricSampleCount": 0,
        "surfaceCellReliefPatchCount": 0,
        "surfaceCellTraceSegmentCount": 0,
        "surfaceCellArrangementCellCount": 0,
        "surfaceCellSimplifiedCellCount": 0,
        "surfaceCellCompletedQuadCount": 0,
        "surfaceCellOptimizationIterationCount": 0,
        "surfaceCellValidationFailureCountAvailable": true,
        "surfaceCellProvenanceVertexCountAvailable": true,
        "surfaceCellFeatureCountAvailable": true,
        "surfaceCellMetricSampleCountAvailable": true,
        "surfaceCellReliefCountAvailable": false,
        "surfaceCellTraceCountAvailable": false,
        "surfaceCellArrangementCountAvailable": false,
        "surfaceCellSimplifiedCountAvailable": false,
        "surfaceCellCompletedQuadCountAvailable": false,
        "surfaceCellOptimizationIterationCountAvailable": false,
        "adaptiveFeatureMapSeconds": 0.0,
        "adaptiveFeatureHardEdgeCount": 0,
        "adaptiveFeatureSoftEdgeCount": 0,
        "adaptiveFeatureBoundaryEdgeCount": 0,
        "adaptiveFeatureNonManifoldEdgeCount": 0,
        "adaptiveFeatureCurveCount": 0,
        "adaptiveFeatureClosedCurveCount": 0,
        "adaptiveFeatureMaxDensity": 0.0,
        "adaptiveTargetSizeSeconds": 0.0,
        "adaptiveTargetSizeResolvedSurfaceError": 0.0,
        "adaptiveTargetSizeMin": 0.0,
        "adaptiveTargetSizeMax": 0.0,
        "adaptiveTargetSizeFiniteVertexCount": 0,
        "adaptiveTargetSizeNonFiniteVertexCount": 0,
        "preconditioningSeconds": 0.0,
        "preconditioningFlipsAccepted": 0,
        "preconditioningInputTriangleCount": 2,
        "preconditioningOutputTriangleCount": 2,
        "preconditioningMinAngleBefore": 30.0,
        "preconditioningMinAngleAfter": 30.0,
        "retwinCallCount": 1,
        "retwinCallsBeforeFunctionCleanup": 1,
        "retwinCallsAfterFunctionCleanup": 0,
        "localPatchPrevalidationAccepted": 1,
        "localPatchPrevalidationRejected": 0,
        "lowValenceMutationsAttempted": 1,
        "patchFallbackRegionsDetected": 0,
        "patchFallbackPatchesAttempted": 0,
        "patchFallbackPatchesSucceeded": 0,
        "patchFallbackPatchesRejected": 0,
        "patchFallbackFacesRepaired": 0,
        "patchFallbackNonQuadFacesBefore": 0,
        "patchFallbackNonQuadFacesAfter": 0
      },
      "outputVertexCount": 4,
      "outputFaceCount": 1,
      "quadCount": 1,
      "nonQuadFaceCount": 0,
      "connectedComponentCount": 1,
      "boundaryEdgeCount": 4,
      "degenerateFaceCount": 0
    }],
    "aggregates": {
      "median": 0.1,
      "p90": 0.1,
      "min": 0.1,
      "max": 0.1,
      "coefficientOfVariation": 0.0
    }
  }]
})json";
  }

  const std::string json = read_text_file(path);
  expect_contains(json, "\"schema\"");
  expect_contains(json, "\"timestamp\"");
  expect_contains(json, "\"selectedIntegrationBackend\"");
  expect_contains(json, "\"fixtureHash\"");
  expect_contains(json, "\"field\"");
  expect_contains(json, "\"success\"");
  expect_contains(json, "\"wallSeconds\"");
  expect_contains(json, "\"diagnostics\"");
  expect_contains(json, "\"overallPipelineTimeAvailable\"");
  expect_contains(json, "\"requestedBackend\"");
  expect_contains(json, "\"executedBackend\"");
  expect_contains(json, "\"surfaceCellFallbackCause\"");
  expect_contains(json, "\"originalSurfaceCellFailureCode\"");
  expect_contains(json, "\"surfaceCellReturnedInputMeshFallback\"");
  expect_contains(json, "\"surfaceCellRemeshOccurred\"");
  expect_contains(json, "\"surfaceCellOutputOrigin\"");
  expect_contains(json, "\"surfaceCellStageLineage\"");
  expect_contains(json, "\"surfaceCellContextProducts\"");
  expect_contains(json, "\"inputObjectHash\"");
  expect_contains(json, "\"consumedByNextStage\"");
  expect_contains(json, "\"componentIndex\"");
  expect_contains(json, "\"surfaceCellValidationSeconds\"");
  expect_contains(json, "\"surfaceCellValidationFailures\"");
  expect_contains(json, "\"surfaceCellProvenanceVertexCount\"");
  expect_contains(json, "\"surfaceCellFeatureCount\"");
  expect_contains(json, "\"surfaceCellMetricSampleCount\"");
  expect_contains(json, "\"surfaceCellValidationFailureCountAvailable\"");
  expect_contains(json, "\"surfaceCellProvenanceVertexCountAvailable\"");
  expect_contains(json, "\"surfaceCellFeatureCountAvailable\"");
  expect_contains(json, "\"surfaceCellMetricSampleCountAvailable\"");
  expect_contains(json, "\"surfaceCellReliefCountAvailable\"");
  expect_contains(json, "\"surfaceCellOptimizationIterationCountAvailable\"");
  expect_contains(json, "\"adaptiveFeatureMapSeconds\"");
  expect_contains(json, "\"adaptiveFeatureHardEdgeCount\"");
  expect_contains(json, "\"adaptiveFeatureSoftEdgeCount\"");
  expect_contains(json, "\"adaptiveFeatureBoundaryEdgeCount\"");
  expect_contains(json, "\"adaptiveFeatureNonManifoldEdgeCount\"");
  expect_contains(json, "\"adaptiveFeatureCurveCount\"");
  expect_contains(json, "\"adaptiveFeatureClosedCurveCount\"");
  expect_contains(json, "\"adaptiveFeatureMaxDensity\"");
  expect_contains(json, "\"adaptiveTargetSizeSeconds\"");
  expect_contains(json, "\"adaptiveTargetSizeResolvedSurfaceError\"");
  expect_contains(json, "\"adaptiveTargetSizeMin\"");
  expect_contains(json, "\"adaptiveTargetSizeMax\"");
  expect_contains(json, "\"adaptiveTargetSizeFiniteVertexCount\"");
  expect_contains(json, "\"adaptiveTargetSizeNonFiniteVertexCount\"");
  expect_contains(json, "\"preconditioningSeconds\"");
  expect_contains(json, "\"preconditioningFlipsAccepted\"");
  expect_contains(json, "\"preconditioningInputTriangleCount\"");
  expect_contains(json, "\"preconditioningOutputTriangleCount\"");
  expect_contains(json, "\"preconditioningMinAngleBefore\"");
  expect_contains(json, "\"preconditioningMinAngleAfter\"");
  expect_contains(json, "\"retwinCallCount\"");
  expect_contains(json, "\"retwinCallsBeforeFunctionCleanup\"");
  expect_contains(json, "\"retwinCallsAfterFunctionCleanup\"");
  expect_contains(json, "\"localPatchPrevalidationAccepted\"");
  expect_contains(json, "\"localPatchPrevalidationRejected\"");
  expect_contains(json, "\"lowValenceMutationsAttempted\"");
  expect_contains(json, "\"patchFallbackRegionsDetected\"");
  expect_contains(json, "\"patchFallbackPatchesAttempted\"");
  expect_contains(json, "\"patchFallbackPatchesSucceeded\"");
  expect_contains(json, "\"patchFallbackPatchesRejected\"");
  expect_contains(json, "\"patchFallbackFacesRepaired\"");
  expect_contains(json, "\"patchFallbackNonQuadFacesBefore\"");
  expect_contains(json, "\"patchFallbackNonQuadFacesAfter\"");
  expect_contains(json, "\"outputVertexCount\"");
  expect_contains(json, "\"quadCount\"");
  expect_contains(json, "\"connectedComponentCount\"");
  expect_contains(json, "\"coefficientOfVariation\"");

  std::filesystem::remove(path);
}

} // namespace
