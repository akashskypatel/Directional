#include <algorithm>
#include <filesystem>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/fields/CrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"

namespace {

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

SyntheticMesh make_two_square_components() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0, 3.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0, 3.0, 1.0,
      0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
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
  options.surfaceCells.requireMatching = false;
  options.surfaceCells.requireSingularities = false;
  return options;
}

std::string signature(const directional::pipeline::RemeshResult &result) {
  return result.diagnostics.remeshBackend + "/" +
         result.diagnostics.terminalFailureCode + "/" +
         std::to_string(result.vertices.rows()) + "/" +
         std::to_string(result.faces.rows()) + "/" +
         std::to_string(result.degrees.sum());
}

} // namespace

TEST(SurfaceCellPipelinePhase20, BackendNamesAndParsersExposeStableApi) {
  using directional::pipeline::RemeshBackend;
  using directional::pipeline::SurfaceCellFallbackPolicy;

  directional::pipeline::RemeshOptions defaults;
  EXPECT_EQ(RemeshBackend::LegacyInteger, defaults.backend);
  EXPECT_EQ("LegacyInteger",
            directional::pipeline::remesh_backend_name(defaults.backend));
  EXPECT_EQ(RemeshBackend::LegacyInteger,
            directional::pipeline::parse_remesh_backend("legacy-integer"));
  EXPECT_EQ(RemeshBackend::SurfaceCells,
            directional::pipeline::parse_remesh_backend("surface_cells"));
  EXPECT_EQ(SurfaceCellFallbackPolicy::ReturnQuadDominant,
            directional::pipeline::parse_surface_cell_fallback_policy(
                "return-quad-dominant"));
  EXPECT_THROW((void)directional::pipeline::parse_remesh_backend("unknown"),
               std::runtime_error);
}

TEST(SurfaceCellPipelinePhase20, InvalidRawFieldDimsReturnPreciseFailureCode) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd badRaw(mesh.faces.rows(), 9);
  badRaw.setZero();
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, badRaw, surface_options());

  EXPECT_FALSE(result.success);
  EXPECT_EQ("SurfaceCells", result.diagnostics.remeshBackend);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.terminalFailureCode);
  EXPECT_EQ("input-validation", result.diagnostics.terminalFailureStage);
}

TEST(SurfaceCellPipelinePhase20, CrossFieldResultRequiresMatchingAndSingularities) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::fields::CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.rawField = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.requireMatching = true;
  options.surfaceCells.requireSingularities = true;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingMatching", result.diagnostics.terminalFailureCode);

  field.matching = Eigen::VectorXi::Zero(1);
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingSingularities", result.diagnostics.terminalFailureCode);

  options.surfaceCells.requireSingularities = false;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("NotProductionReady", result.diagnostics.terminalFailureCode);
}

TEST(SurfaceCellPipelinePhase20, ExplicitFallbackPoliciesAreObservable) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  EXPECT_FALSE(result.success);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);

  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellReturnedQuadDominantFallback);
  ASSERT_GT(result.diagnostics.faceDegreeHistogram.size(), 3U);
  EXPECT_EQ(static_cast<std::size_t>(mesh.faces.rows()),
            result.diagnostics.faceDegreeHistogram[3]);
}

TEST(SurfaceCellPipelinePhase20, DebugArtifactsAreRetainedOnlyWhenRequested) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 0;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_FALSE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifacts.empty());

  options.surfaceCells.preserveDebugArtifacts = true;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  ASSERT_EQ(1U, result.diagnostics.surfaceCellDebugArtifacts.size());
  EXPECT_EQ("feature", result.diagnostics.surfaceCellDebugArtifacts[0]);
}

TEST(SurfaceCellPipelinePhase20, ComponentSchedulingAppliesToSurfaceCells) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions sequential = surface_options();
  sequential.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;
  const directional::pipeline::RemeshResult sequentialResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, sequential);

  directional::pipeline::RemeshOptions parallel = sequential;
  parallel.parallelizeComponents = true;
  parallel.maxComponentThreads = 2;
  const directional::pipeline::RemeshResult parallelResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, parallel);

  EXPECT_TRUE(sequentialResult.success);
  EXPECT_TRUE(parallelResult.success);
  EXPECT_EQ(signature(sequentialResult), signature(parallelResult));
  EXPECT_EQ(2U, parallelResult.diagnostics.componentCount);
}

TEST(SurfaceCellPipelinePhase20, SurfaceCellFallbackIsDeterministic) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;

  const std::string expected = signature(
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options));
  for (int run = 0; run < 10; ++run) {
    EXPECT_EQ(expected, signature(
                            directional::pipeline::remesh_from_raw_cross_field(
                                mesh.vertices, mesh.faces, raw, options)));
  }
}

TEST(SurfaceCellPipelinePhase20, BenchmarkManifestDispatchesBackends) {
  const std::filesystem::path manifestPath =
      std::filesystem::path(DIRECTIONAL_TEST_SOURCE_DIR) /
      "benchmarks/fixtures/manifest.example.json";
  const std::vector<directional::bench::BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifestPath);

  const auto surfaceCase = std::find_if(
      cases.begin(), cases.end(),
      [](const directional::bench::BenchmarkCase &candidate) {
        return candidate.name == "fertility_surface_cells_skeleton_hints";
      });
  ASSERT_NE(cases.end(), surfaceCase);
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            surfaceCase->backend);
  EXPECT_TRUE(surfaceCase->surfaceCellSkeletonHints);

  const directional::pipeline::RemeshOptions options =
      directional::bench::make_remesh_options(*surfaceCase);
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            options.backend);
  EXPECT_TRUE(options.surfaceCells.enabled);
  EXPECT_TRUE(options.surfaceCells.useSkeletonHints);
}
