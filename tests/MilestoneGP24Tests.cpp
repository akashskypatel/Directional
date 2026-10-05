#include <cmath>
#include <limits>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/pipeline/RemeshPipeline.h>

namespace {

struct TestMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

TestMesh make_two_squares() {
  TestMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
                   1.0, 0.0, 0.0,
                   1.0, 1.0, 0.0,
                   0.0, 1.0, 0.0,
                   3.0, 0.0, 0.0,
                   4.0, 0.0, 0.0,
                   4.0, 1.0, 0.0,
                   3.0, 1.0, 0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2,
                0, 2, 3,
                4, 5, 6,
                4, 6, 7;
  return mesh;
}

Eigen::MatrixXd constant_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.block(face, 0, 1, 3) << 1.0, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, 1.0, 0.0;
    raw.block(face, 6, 1, 3) << -1.0, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -1.0, 0.0;
  }
  return raw;
}

directional::pipeline::RemeshOptions surface_options() {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.lengthRatio = 0.2;
  return options;
}

const directional::SurfaceCellStageLineage *find_stage(
    const directional::RemeshDiagnostics &diagnostics,
    const std::string &name) {
  for (const directional::SurfaceCellStageLineage &lineage :
       diagnostics.surfaceCellStageLineage) {
    if (lineage.stage == name) {
      return &lineage;
    }
  }
  return nullptr;
}

void expect_overall_time(const directional::pipeline::RemeshResult &result) {
  EXPECT_TRUE(result.diagnostics.overallPipelineTimeAvailable);
  EXPECT_TRUE(std::isfinite(result.diagnostics.overallPipelineSeconds));
  EXPECT_GE(result.diagnostics.overallPipelineSeconds, 0.0);
}

void expect_all_surface_counts_available(
    const directional::RemeshDiagnostics &diagnostics) {
  EXPECT_TRUE(diagnostics.surfaceCellValidationFailureCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellProvenanceVertexCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellFeatureCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellMetricSampleCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellReliefCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellTraceCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellArrangementCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellSimplifiedCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellCompletedQuadCountAvailable);
  EXPECT_TRUE(diagnostics.surfaceCellOptimizationIterationCountAvailable);
}

} // namespace

TEST(MilestoneGP24, EverySurfaceCellCountHasAvailability) {
  const TestMesh mesh = make_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult completed =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());
  ASSERT_TRUE(completed.is_produced())
      << completed.diagnostics.terminalFailureCode << "/"
      << completed.diagnostics.terminalFailureStage << " validation="
      << completed.diagnostics.surfaceCellValidationFailures << " time="
      << completed.surfaceCellContext.productSnapshots.validationResult.optimizerTimeWithinGate
      << " size="
      << completed.surfaceCellContext.productSnapshots.validationResult.sizeP5 << ","
      << completed.surfaceCellContext.productSnapshots.validationResult.sizeP95 << " field="
      << completed.surfaceCellContext.productSnapshots.validationResult.fieldMedianDegrees << ","
      << completed.surfaceCellContext.productSnapshots.validationResult.fieldP95Degrees;
  expect_all_surface_counts_available(completed.diagnostics);

  directional::pipeline::RemeshOptions featureFailure = surface_options();
  featureFailure.surfaceCells.injectFailureAfterStage = 0;
  const directional::pipeline::RemeshResult failed =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, featureFailure);
  ASSERT_FALSE(failed.is_produced());
  EXPECT_TRUE(failed.diagnostics.surfaceCellFeatureCountAvailable);
  EXPECT_FALSE(failed.diagnostics.surfaceCellMetricSampleCountAvailable);
  EXPECT_FALSE(failed.diagnostics.surfaceCellReliefCountAvailable);
  EXPECT_FALSE(failed.diagnostics.surfaceCellProvenanceVertexCountAvailable);
  EXPECT_FALSE(failed.diagnostics.surfaceCellValidationFailureCountAvailable);
  EXPECT_EQ(0U, failed.diagnostics.surfaceCellMetricSampleCount);
  EXPECT_EQ(0U, failed.diagnostics.surfaceCellValidationFailures);
}

TEST(MilestoneGP24, EveryReturnPathReportsOverallPipelineTime) {
  const TestMesh mesh = make_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.parallelizeComponents = true;
  expect_overall_time(directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options));

  options = surface_options();
  const Eigen::MatrixXd malformed(mesh.faces.rows(), 11);
  expect_overall_time(directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, malformed, options));

  options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 9;
  expect_overall_time(directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options));

  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnInputMesh;
  const directional::pipeline::RemeshResult fallback =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  ASSERT_TRUE(fallback.is_produced());
  expect_overall_time(fallback);
}

TEST(MilestoneGP24, ProvenanceCountComesFromOutput) {
  const TestMesh mesh = make_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult completed =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());
  ASSERT_TRUE(completed.is_produced())
      << completed.diagnostics.terminalFailureCode << "/"
      << completed.diagnostics.terminalFailureStage << " validation="
      << completed.diagnostics.surfaceCellValidationFailures << " time="
      << completed.surfaceCellContext.productSnapshots.validationResult.optimizerTimeWithinGate
      << " size="
      << completed.surfaceCellContext.productSnapshots.validationResult.sizeP5 << ","
      << completed.surfaceCellContext.productSnapshots.validationResult.sizeP95 << " field="
      << completed.surfaceCellContext.productSnapshots.validationResult.fieldMedianDegrees << ","
      << completed.surfaceCellContext.productSnapshots.validationResult.fieldP95Degrees;
  ASSERT_TRUE(completed.diagnostics.surfaceCellProvenanceVertexCountAvailable);
  EXPECT_EQ(completed.product().outputVertexProvenance.size(),
            completed.diagnostics.surfaceCellProvenanceVertexCount);
  EXPECT_EQ(static_cast<std::size_t>(completed.product().vertices.rows()),
            completed.diagnostics.surfaceCellProvenanceVertexCount);

  directional::pipeline::RemeshOptions rejected = surface_options();
  rejected.surfaceCells.rejectPairedSourceTriangleBoundaryOutput = true;
  const directional::pipeline::RemeshResult completionFailure =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, rejected);
  ASSERT_FALSE(completionFailure.is_produced());
  EXPECT_EQ("completion", completionFailure.diagnostics.terminalFailureStage);
  EXPECT_TRUE(completionFailure.diagnostics
                  .surfaceCellProvenanceVertexCountAvailable);
  EXPECT_EQ(completionFailure.surfaceCellContext.completedProvenance.size(),
            completionFailure.diagnostics.surfaceCellProvenanceVertexCount);
  EXPECT_EQ(nullptr, completionFailure.produced_product());
}

TEST(MilestoneGP24, RealFailurePreservesLastValidStageArtifacts) {
  const TestMesh mesh = make_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.preserveDebugArtifacts = true;
  options.surfaceCells.targetSize.baseSize = 0.01;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_FALSE(result.is_produced());
  EXPECT_EQ("validation", result.diagnostics.terminalFailureStage);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasOptimizationResult);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasValidationResult);
  EXPECT_TRUE(result.diagnostics.surfaceCellValidationFailureCountAvailable);
  EXPECT_GT(result.diagnostics.surfaceCellValidationFailures, 0U);
  ASSERT_FALSE(result.diagnostics.surfaceCellDebugArtifacts.empty());
  EXPECT_EQ("validation", result.diagnostics.surfaceCellDebugArtifacts.back());

  const directional::SurfaceCellStageLineage *validation =
      find_stage(result.diagnostics, "validation");
  ASSERT_NE(nullptr, validation);
  EXPECT_TRUE(validation->available);
  EXPECT_EQ("validation", validation->outputObject.type);
  EXPECT_EQ("NotProductionReady", validation->terminalFailureCode);
  EXPECT_EQ("validation", validation->terminalFailureStage);
}

TEST(MilestoneGP24, ComponentAggregationPreservesAvailabilitySemantics) {
  directional::RemeshDiagnostics first;
  first.executedBackend = "SurfaceCells";
  first.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::CompletedSurfaceCells;
  first.surfaceCellFeatureCount = 4U;
  first.surfaceCellFeatureCountAvailable = true;
  first.surfaceCellMetricSampleCount = 8U;
  first.surfaceCellMetricSampleCountAvailable = true;
  first.surfaceCellFallbackCause = "NotProductionReady";
  directional::SurfaceCellStageLineage firstLineage;
  firstLineage.stage = "feature";
  firstLineage.outputObject.type = "feature";
  firstLineage.outputObject.structuralHash = 11U;
  firstLineage.available = true;
  first.surfaceCellStageLineage.push_back(firstLineage);

  directional::RemeshDiagnostics second;
  second.executedBackend = "InputMesh";
  second.surfaceCellOutputOrigin =
      directional::SurfaceCellOutputOrigin::InputMeshFallback;
  second.surfaceCellFeatureCount = 6U;
  second.surfaceCellFeatureCountAvailable = true;
  second.surfaceCellMetricSampleCount = 99U;
  second.surfaceCellMetricSampleCountAvailable = false;
  second.surfaceCellFallbackAttempted = true;
  second.surfaceCellReturnedInputMeshFallback = true;
  second.surfaceCellFallbackCause = "UnsupportedInput";
  directional::SurfaceCellStageLineage secondLineage = firstLineage;
  secondLineage.outputObject.structuralHash = 22U;
  second.surfaceCellStageLineage.push_back(secondLineage);

  directional::RemeshDiagnostics aggregate;
  aggregate.executedBackend.clear();
  directional::pipeline::accumulate_component_diagnostics(
      aggregate, first, 0U, true);
  directional::pipeline::accumulate_component_diagnostics(
      aggregate, second, 1U, false);

  EXPECT_TRUE(aggregate.surfaceCellFeatureCountAvailable);
  EXPECT_EQ(10U, aggregate.surfaceCellFeatureCount);
  EXPECT_FALSE(aggregate.surfaceCellMetricSampleCountAvailable);
  EXPECT_EQ(0U, aggregate.surfaceCellMetricSampleCount);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::Mixed,
            aggregate.surfaceCellOutputOrigin);
  EXPECT_EQ("Mixed", aggregate.executedBackend);
  EXPECT_EQ("Mixed", aggregate.surfaceCellFallbackCause);
  EXPECT_TRUE(aggregate.surfaceCellFallbackAttempted);
  EXPECT_TRUE(aggregate.surfaceCellReturnedInputMeshFallback);
  ASSERT_EQ(2U, aggregate.surfaceCellStageLineage.size());
  EXPECT_EQ(0U, aggregate.surfaceCellStageLineage[0].componentIndex);
  EXPECT_EQ(1U, aggregate.surfaceCellStageLineage[1].componentIndex);
  EXPECT_EQ(11U, aggregate.surfaceCellStageLineage[0]
                     .outputObject.structuralHash);
  EXPECT_EQ(22U, aggregate.surfaceCellStageLineage[1]
                     .outputObject.structuralHash);
}

TEST(MilestoneGP24, ValidationFailureCountTracksEnforcedGates) {
  directional::geometry::SurfaceFinalValidationReport report;
  report.accepted = false;
  report.quadToSourceP95 = 0.20;
  report.optimizerTimeWithinGate = false;

  EXPECT_EQ(1U,
            directional::pipeline::surface_cell_validation_failure_count(
                report, false));
  EXPECT_EQ(2U,
            directional::pipeline::surface_cell_validation_failure_count(
                report, true));
}

TEST(MilestoneGP24, StageDurationsUseIndependentIntervals) {
  const TestMesh mesh = make_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());
  ASSERT_TRUE(result.is_produced())
      << result.diagnostics.terminalFailureCode << "/"
      << result.diagnostics.terminalFailureStage << " validation="
      << result.diagnostics.surfaceCellValidationFailures << " time="
      << result.surfaceCellContext.productSnapshots.validationResult.optimizerTimeWithinGate
      << " size=" << result.surfaceCellContext.productSnapshots.validationResult.sizeP5 << ","
      << result.surfaceCellContext.productSnapshots.validationResult.sizeP95 << " field="
      << result.surfaceCellContext.productSnapshots.validationResult.fieldMedianDegrees << ","
      << result.surfaceCellContext.productSnapshots.validationResult.fieldP95Degrees;
  expect_overall_time(result);

  double stageSum = 0.0;
  for (const directional::SurfaceCellStageLineage &lineage :
       result.diagnostics.surfaceCellStageLineage) {
    EXPECT_TRUE(std::isfinite(lineage.durationSeconds));
    EXPECT_GE(lineage.durationSeconds, 0.0);
    stageSum += lineage.durationSeconds;
  }
  EXPECT_LE(stageSum,
            result.diagnostics.overallPipelineSeconds + 5.0e-3);

  const struct {
    const char *name;
    double value;
  } timedStages[] = {
      {"feature", result.diagnostics.surfaceCellFeatureSeconds},
      {"metric", result.diagnostics.surfaceCellMetricSeconds},
      {"relief", result.diagnostics.surfaceCellReliefSeconds},
      {"tracing", result.diagnostics.surfaceCellTracingSeconds},
      {"arrangement", result.diagnostics.surfaceCellArrangementSeconds},
      {"simplification",
       result.diagnostics.surfaceCellSimplificationSeconds},
      {"completion", result.diagnostics.surfaceCellCompletionSeconds},
      {"optimization", result.diagnostics.surfaceCellOptimizationSeconds},
      {"validation", result.diagnostics.surfaceCellValidationSeconds},
  };
  for (const auto &timed : timedStages) {
    const directional::SurfaceCellStageLineage *lineage =
        find_stage(result.diagnostics, timed.name);
    ASSERT_NE(nullptr, lineage) << timed.name;
    EXPECT_NEAR(timed.value, lineage->durationSeconds, 1.0e-12)
        << timed.name;
  }

  const directional::SurfaceCellStageLineage *optimization =
      find_stage(result.diagnostics, "optimization");
  const directional::SurfaceCellStageLineage *validation =
      find_stage(result.diagnostics, "validation");
  ASSERT_NE(nullptr, optimization);
  ASSERT_NE(nullptr, validation);
  EXPECT_EQ("validation", validation->outputObject.type);
  EXPECT_NE(optimization->outputObject.structuralHash,
            validation->outputObject.structuralHash);
}

TEST(MilestoneGP24, ValidationHashIgnoresUnenforcedTimingObservation) {
  directional::geometry::SurfaceFinalValidationReport withinGate;
  withinGate.accepted = true;
  withinGate.optimizerTimeWithinGate = true;
  directional::geometry::SurfaceFinalValidationReport exceededGate =
      withinGate;
  exceededGate.optimizerTimeWithinGate = false;

  EXPECT_EQ(directional::pipeline::hash_surface_cell_validation(withinGate),
            directional::pipeline::hash_surface_cell_validation(exceededGate));
  directional::geometry::SurfaceFinalValidationReport enforcedRejection =
      exceededGate;
  enforcedRejection.accepted = false;
  EXPECT_NE(
      directional::pipeline::hash_surface_cell_validation(withinGate, true),
      directional::pipeline::hash_surface_cell_validation(enforcedRejection,
                                                          true));
}
