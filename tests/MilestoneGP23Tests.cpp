#include <string>

#include <gtest/gtest.h>

#include <directional/fields/CrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace {

struct TestMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

TestMesh make_planar_grid() {
  TestMesh mesh;
  mesh.vertices.resize(9, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
                   0.5, 0.0, 0.0,
                   1.0, 0.0, 0.0,
                   0.0, 0.5, 0.0,
                   0.5, 0.5, 0.0,
                   1.0, 0.5, 0.0,
                   0.0, 1.0, 0.0,
                   0.5, 1.0, 0.0,
                   1.0, 1.0, 0.0;
  mesh.faces.resize(8, 3);
  mesh.faces << 0, 1, 4,
                0, 4, 3,
                1, 2, 5,
                1, 5, 4,
                3, 4, 7,
                3, 7, 6,
                4, 5, 8,
                4, 8, 7;
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

directional::pipeline::RemeshOptions surface_options(
    const directional::pipeline::SurfaceCellFallbackPolicy policy) {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy = policy;
  return options;
}

void expect_no_output_mesh(const directional::pipeline::RemeshResult &result) {
  EXPECT_EQ(0, result.product().vertices.rows());
  EXPECT_EQ(0, result.product().faces.rows());
  EXPECT_EQ(0, result.product().degrees.size());
}

void expect_input_mesh(const directional::pipeline::RemeshResult &result,
                       const TestMesh &mesh) {
  ASSERT_EQ(mesh.vertices.rows(), result.product().vertices.rows());
  ASSERT_EQ(mesh.vertices.cols(), result.product().vertices.cols());
  ASSERT_EQ(mesh.faces.rows(), result.product().faces.rows());
  ASSERT_EQ(mesh.faces.cols(), result.product().faces.cols());
  EXPECT_TRUE(result.product().vertices.isApprox(mesh.vertices));
  EXPECT_EQ(result.product().faces, mesh.faces);
}

} // namespace

TEST(MilestoneGP23, FailReturnsNoMesh) {
  using directional::pipeline::SurfaceCellFallbackPolicy;
  const TestMesh mesh = make_planar_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options =
      surface_options(SurfaceCellFallbackPolicy::Fail);
  options.surfaceCells.injectFailureAfterStage = 9;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  expect_no_output_mesh(result);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("optimization",
            result.diagnostics.originalSurfaceCellFailureStage);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("optimization", result.diagnostics.terminalFailureStage);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackCause.empty());
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
            result.diagnostics.surfaceCellOutputOrigin);

  const Eigen::MatrixXd malformed(mesh.faces.rows(), 11);
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, malformed, options);
  EXPECT_FALSE(result.is_produced());
  expect_no_output_mesh(result);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("InvalidFieldDimensions", result.diagnostics.terminalFailureCode);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
}

TEST(MilestoneGP23, ReturnInputMeshIsCanonicalFallback) {
  using directional::pipeline::SurfaceCellFallbackPolicy;
  const TestMesh mesh = make_planar_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options =
      surface_options(SurfaceCellFallbackPolicy::ReturnInputMesh);
  options.surfaceCells.injectFailureAfterStage = 9;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(result.is_produced());
  expect_input_mesh(result, mesh);
  EXPECT_EQ("ReturnInputMesh", result.diagnostics.surfaceCellFallbackPolicy);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("InputMesh", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("optimization",
            result.diagnostics.originalSurfaceCellFailureStage);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.surfaceCellFallbackCause);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.terminalFailureStage.empty());
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellReturnedInputMeshFallback);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::InputMeshFallback,
            result.diagnostics.surfaceCellOutputOrigin);

  const Eigen::MatrixXd malformed(mesh.faces.rows(), 11);
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, malformed, options);
  ASSERT_TRUE(result.is_produced());
  expect_input_mesh(result, mesh);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.surfaceCellFallbackCause);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
}

TEST(MilestoneGP23, LegacyFallbackAliasParsesButSerializesCanonicalName) {
  using directional::pipeline::SurfaceCellFallbackPolicy;

  const SurfaceCellFallbackPolicy parsed =
      directional::pipeline::parse_surface_cell_fallback_policy(
          "ReturnQuadDominant");
  EXPECT_EQ(SurfaceCellFallbackPolicy::ReturnInputMesh, parsed);
  EXPECT_EQ("ReturnInputMesh",
            directional::pipeline::surface_cell_fallback_policy_name(parsed));
}

TEST(MilestoneGP23, TryLegacyParserRejectsLegacyIntegrationFallback) {
  EXPECT_THROW(
      directional::pipeline::parse_surface_cell_fallback_policy("TryLegacy"),
      std::runtime_error);
}

TEST(MilestoneGP23, SurfaceCellFailureTerminatesBeforeLegacyIntegration) {
  using directional::pipeline::SurfaceCellFallbackPolicy;
  const TestMesh mesh = make_planar_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options =
      surface_options(SurfaceCellFallbackPolicy::Fail);
  options.surfaceCells.injectFailureAfterStage = 9;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.is_produced());
  expect_no_output_mesh(result);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("Fail", result.diagnostics.surfaceCellFallbackPolicy);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackCause.empty());
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("optimization",
            result.diagnostics.originalSurfaceCellFailureStage);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("optimization", result.diagnostics.terminalFailureStage);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.setupIntegrationSeconds);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.integrationTotalSeconds);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.setupMesherSeconds);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.mesherTotalSeconds);
  EXPECT_EQ(0U, result.diagnostics.integration.integerIterations);
  EXPECT_EQ(0U, result.diagnostics.integration.directFactorizations);
  EXPECT_DOUBLE_EQ(0.0,
                   result.diagnostics.integration.numericFactorizationSeconds);
}

TEST(MilestoneGP23, EarlyCrossFieldValidationUsesConfiguredFallbackPolicy) {
  using directional::pipeline::SurfaceCellFallbackPolicy;
  const TestMesh mesh = make_planar_grid();

  directional::fields::CrossFieldResult malformed;
  malformed.degree = directional::fields::kCrossFieldDegree;
  malformed.rawField = Eigen::MatrixXd::Zero(mesh.faces.rows(), 11);

  directional::pipeline::RemeshOptions options =
      surface_options(SurfaceCellFallbackPolicy::ReturnInputMesh);
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, malformed, options);
  ASSERT_TRUE(result.is_produced());
  expect_input_mesh(result, mesh);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("InputMesh", result.diagnostics.executedBackend);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);

  options.surfaceCells.fallbackPolicy = SurfaceCellFallbackPolicy::Fail;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, malformed, options);
  EXPECT_FALSE(result.is_produced());
  expect_no_output_mesh(result);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InvalidFieldDimensions", result.diagnostics.terminalFailureCode);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.integrationTotalSeconds);
  EXPECT_EQ(0U, result.diagnostics.integration.directFactorizations);

  directional::fields::CrossFieldResult missingMatching;
  missingMatching.degree = directional::fields::kCrossFieldDegree;
  missingMatching.rawField = constant_raw_field(mesh.faces.rows());
  missingMatching.primaryDirections =
      missingMatching.rawField.block(0, 0, mesh.faces.rows(), 3);
  missingMatching.secondaryDirections =
      missingMatching.rawField.block(0, 3, mesh.faces.rows(), 3);
  missingMatching.confidence = Eigen::VectorXd::Ones(mesh.faces.rows());
  missingMatching.confidenceComputed = true;
  missingMatching.singularitiesComputed = true;
  missingMatching.uncoveredFacePolicyApplied = true;

  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, missingMatching, options);
  EXPECT_FALSE(result.is_produced());
  expect_no_output_mesh(result);
  EXPECT_EQ("MissingMatching",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("MissingMatching", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_DOUBLE_EQ(0.0, result.diagnostics.integrationTotalSeconds);
  EXPECT_EQ(0U, result.diagnostics.integration.directFactorizations);
}
