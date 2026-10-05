#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

namespace {

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

Eigen::MatrixXd derivative_vertices() {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.1, 0.1, 0.2,
      1.3, 0.2, 0.1,
      1.1, 1.4, 0.3,
      -0.1, 0.9, -0.05;
  return vertices;
}

Eigen::MatrixXi derivative_quad() {
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  return quads;
}

directional::geometry::SurfaceOptimizationConstraints derivative_constraints() {
  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices.resize(4, 3);
  constraints.sourceVertices << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      2.0, 2.0, 0.0,
      0.0, 2.0, 0.0;
  constraints.sourceFaces.resize(2, 3);
  constraints.sourceFaces << 0, 1, 2,
      0, 2, 3;
  static const auto sourceAuthority =
      test_source_authority(constraints.sourceFaces, {0, 0}, {0, 0});
  constraints.sourceAuthority = &sourceAuthority;
  constraints.sourceNormals.resize(1, 3);
  constraints.sourceNormals << 0.2, 0.1, 1.0;
  constraints.sourceNormals.row(0).normalize();
  constraints.sourceFieldX.resize(1, 3);
  constraints.sourceFieldY.resize(1, 3);
  constraints.sourceFieldX << 1.0, 0.25, 0.0;
  constraints.sourceFieldY << -0.25, 1.0, 0.0;
  constraints.sourceFieldX.row(0).normalize();
  constraints.sourceFieldY.row(0).normalize();
  constraints.localTargetSize.resize(4);
  constraints.localTargetSize << 0.9, 1.1, 1.2, 0.8;
  constraints.featureVertices = {2};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureCurveIds(2) = 7;
  constraints.featureCurveIntervals.push_back(
      {7, {0.0, 0.0, 0.0}, {2.0, 0.0, 0.0}, 0, 0});
  return constraints;
}

directional::geometry::SurfaceOptimizationOptions isolated_options(
    const std::function<void(
        directional::geometry::SurfaceOptimizationWeights &)> &enable) {
  directional::geometry::SurfaceOptimizationOptions options;
  options.finiteDifferenceStep = 1.0e-6;
  options.weights.surface = 0.0;
  options.weights.normal = 0.0;
  options.weights.field = 0.0;
  options.weights.orthogonality = 0.0;
  options.weights.size = 0.0;
  options.weights.valenceShape = 0.0;
  options.weights.feature = 0.0;
  enable(options.weights);
  return options;
}

double relative_gradient_error(const Eigen::MatrixXd &direct,
                               const Eigen::MatrixXd &finiteDifference) {
  const double denominator =
      std::max({1.0, direct.norm(), finiteDifference.norm()});
  return (direct - finiteDifference).norm() / denominator;
}

} // namespace

TEST(SurfaceMeshOptimizerPhase20,
     DirectDerivativesMatchFiniteDifferencesForEveryEnabledEnergy) {
  const Eigen::MatrixXd vertices = derivative_vertices();
  const Eigen::MatrixXi quads = derivative_quad();
  const auto constraints = derivative_constraints();

  struct EnergyCase {
    const char *name;
    std::function<void(directional::geometry::SurfaceOptimizationWeights &)>
        enable;
  };
  const std::array<EnergyCase, 7> cases = {{
      {"surface", [](auto &weights) { weights.surface = 1.0; }},
      {"normal", [](auto &weights) { weights.normal = 1.0; }},
      {"field", [](auto &weights) { weights.field = 1.0; }},
      {"orthogonality",
       [](auto &weights) { weights.orthogonality = 1.0; }},
      {"size", [](auto &weights) { weights.size = 1.0; }},
      {"valenceShape",
       [](auto &weights) { weights.valenceShape = 1.0; }},
      {"feature", [](auto &weights) { weights.feature = 1.0; }},
  }};

  for (const EnergyCase &testCase : cases) {
    SCOPED_TRACE(testCase.name);
    const auto options = isolated_options(testCase.enable);
    const Eigen::MatrixXd direct =
        directional::geometry::evaluate_surface_optimization_gradient(
            vertices, quads, constraints, options)
            .total;
    const Eigen::MatrixXd finiteDifference =
        directional::geometry::finite_difference_surface_optimization_gradient(
            vertices, quads, constraints, options);

    EXPECT_GT(direct.norm(), 1.0e-8);
    EXPECT_LT(relative_gradient_error(direct, finiteDifference), 1.0e-6);
  }
}

TEST(SurfaceMeshOptimizerPhase20,
     FeatureIntervalOrderDerivativeMatchesFiniteDifference) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      0.8, 0.0, 0.0,
      0.2, 0.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 3, 2;

  auto constraints = derivative_constraints();
  constraints.featureVertices = {1, 2};
  constraints.orderedFeatureVertices = {1, 2};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureCurveIds(1) = 17;
  constraints.featureCurveIds(2) = 17;
  constraints.featureRailIds.assign(4, std::nullopt);
  constraints.featureRailIds[1] = directional::tests::test_hard_rail_id(4);
  constraints.featureRailIds[2] = directional::tests::test_hard_rail_id(4);
  constraints.featureCurveIntervals.clear();
  constraints.featureCurveIntervals.push_back(
      {17, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0, 0});

  const auto options = isolated_options(
      [](auto &weights) { weights.feature = 1.0; });
  const auto energy =
      directional::geometry::evaluate_surface_optimization_energy(
          vertices, quads, constraints, options);
  const Eigen::MatrixXd direct =
      directional::geometry::evaluate_surface_optimization_gradient(
          vertices, quads, constraints, options)
          .total;
  const Eigen::MatrixXd finiteDifference =
      directional::geometry::finite_difference_surface_optimization_gradient(
          vertices, quads, constraints, options);

  EXPECT_NEAR(energy.feature, 0.36, 1.0e-12);
  EXPECT_LT(relative_gradient_error(direct, finiteDifference), 1.0e-6);
  EXPECT_GT(direct(1, 0), 0.0);
  EXPECT_LT(direct(2, 0), 0.0);
}

TEST(SurfaceMeshOptimizerPhase20,
     FourRosyBranchDerivativeUsesClosestAxisAndSign) {
  Eigen::MatrixXd vertices = derivative_vertices();
  vertices.row(1) << 0.9, 0.65, 0.25;
  auto constraints = derivative_constraints();
  constraints.sourceFieldX.row(0) << 1.0, 0.0, 0.0;
  constraints.sourceFieldY.row(0) << 0.0, 1.0, 0.0;
  const auto options =
      isolated_options([](auto &weights) { weights.field = 1.0; });

  const Eigen::MatrixXd direct =
      directional::geometry::evaluate_surface_optimization_gradient(
          vertices, derivative_quad(), constraints, options)
          .total;
  const Eigen::MatrixXd finiteDifference =
      directional::geometry::finite_difference_surface_optimization_gradient(
          vertices, derivative_quad(), constraints, options);

  EXPECT_LT(relative_gradient_error(direct, finiteDifference), 1.0e-6);
}

TEST(SurfaceMeshOptimizerPhase20,
     BarycentricSourceDataDerivativesMatchFiniteDifferences) {
  Eigen::MatrixXd sourceVertices(4, 3);
  sourceVertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.20, 0.10, 0.08,
      0.82, 0.12, -0.04,
      0.78, 0.66, 0.11,
      0.16, 0.76, -0.07;

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = sourceVertices;
  constraints.sourceFaces = sourceFaces;
  const auto sourceAuthority =
      test_source_authority(sourceFaces, {0, 0}, {3, 3});
  constraints.sourceAuthority = &sourceAuthority;
  constraints.sourceNormals.resize(4, 3);
  constraints.sourceNormals << 0.0, 0.0, 1.0,
      0.18, 0.0, 0.98,
      0.18, 0.16, 0.97,
      0.0, 0.16, 0.99;
  constraints.sourceFieldX.resize(4, 3);
  constraints.sourceFieldY.resize(4, 3);
  for (int vertex = 0; vertex < 4; ++vertex) {
    constraints.sourceNormals.row(vertex).normalize();
    const double angle = 0.17 * static_cast<double>(vertex);
    constraints.sourceFieldX.row(vertex) << std::cos(angle), std::sin(angle),
        0.0;
    constraints.sourceFieldY.row(vertex) << -std::sin(angle), std::cos(angle),
        0.0;
  }
  constraints.localTargetSize.resize(4);
  constraints.localTargetSize << 0.7, 0.9, 1.15, 1.3;
  constraints.vertexProvenance.resize(4);
  directional::geometry::SurfaceProjectionBvh bvh(sourceVertices, sourceFaces);
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    constraints.vertexProvenance[static_cast<std::size_t>(vertex)] =
        bvh.project(vertices.row(vertex).transpose());
    constraints.vertexProvenance[static_cast<std::size_t>(vertex)].component = 0;
    constraints.vertexProvenance[static_cast<std::size_t>(vertex)].sheet = 3;
  }

  struct SourceEnergyCase {
    const char *name;
    std::function<void(directional::geometry::SurfaceOptimizationWeights &)>
        enable;
  };
  const std::array<SourceEnergyCase, 3> cases = {{
      {"normal", [](auto &weights) { weights.normal = 1.0; }},
      {"field", [](auto &weights) { weights.field = 1.0; }},
      {"size", [](auto &weights) { weights.size = 1.0; }},
  }};
  for (const SourceEnergyCase &testCase : cases) {
    SCOPED_TRACE(testCase.name);
    auto options = isolated_options(testCase.enable);
    options.finiteDifferenceStep = 1.0e-7;
    const Eigen::MatrixXd direct =
        directional::geometry::evaluate_surface_optimization_gradient(
            vertices, derivative_quad(), constraints, options)
            .total;
    const Eigen::MatrixXd finiteDifference =
        directional::geometry::finite_difference_surface_optimization_gradient(
            vertices, derivative_quad(), constraints, options);
    EXPECT_LT(relative_gradient_error(direct, finiteDifference), 1.0e-5);
  }
}

TEST(SurfaceMeshOptimizerPhase20,
     FixedConnectivityValencePenaltyHasZeroPositionalDerivative) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  auto constraints = derivative_constraints();
  constraints.featureVertices.clear();
  constraints.featureCurveIntervals.clear();
  const auto options = isolated_options(
      [](auto &weights) { weights.valenceShape = 1.0; });

  const auto energy =
      directional::geometry::evaluate_surface_optimization_energy(
          vertices, derivative_quad(), constraints, options);
  const auto gradient =
      directional::geometry::evaluate_surface_optimization_gradient(
          vertices, derivative_quad(), constraints, options);

  EXPECT_GT(energy.valenceShape, 0.0);
  EXPECT_NEAR(gradient.valenceShape.norm(), 0.0, 1.0e-12);
}

TEST(SurfaceMeshOptimizerPhase20,
     FixedVerticesReceiveNoDerivativeFromNeighboringTerms) {
  const Eigen::MatrixXd vertices = derivative_vertices();
  auto constraints = derivative_constraints();
  constraints.fixedVertices = {0, 2};
  const auto gradient =
      directional::geometry::evaluate_surface_optimization_gradient(
          vertices, derivative_quad(), constraints);

  EXPECT_NEAR(gradient.total.row(0).norm(), 0.0, 1.0e-12);
  EXPECT_NEAR(gradient.total.row(2).norm(), 0.0, 1.0e-12);
  EXPECT_GT(gradient.total.row(1).norm() + gradient.total.row(3).norm(),
            1.0e-8);
}

TEST(SurfaceMeshOptimizerPhase20,
     RejectedOrderViolatingTrialRollsBackAllVertices) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      0.4, 0.0, 0.0,
      0.6, 0.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 3, 2;

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = vertices;
  constraints.sourceFaces.resize(2, 3);
  constraints.sourceFaces << 0, 1, 3,
      0, 3, 2;
  const auto sourceAuthority =
      test_source_authority(constraints.sourceFaces, {0, 0}, {0, 0});
  constraints.sourceAuthority = &sourceAuthority;
  constraints.sourceNormals.resize(1, 3);
  constraints.sourceNormals << 0.0, 0.0, 1.0;
  constraints.sourceFieldX.resize(1, 3);
  constraints.sourceFieldY.resize(1, 3);
  constraints.sourceFieldX << 1.0, 0.0, 0.0;
  constraints.sourceFieldY << 0.0, 1.0, 0.0;
  constraints.featureVertices = {1, 2};
  constraints.orderedFeatureVertices = {1, 2};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureCurveIds(1) = 7;
  constraints.featureCurveIds(2) = 7;
  constraints.featureRailIds.assign(4, std::nullopt);
  constraints.featureRailIds[1] = directional::tests::test_hard_rail_id(5);
  constraints.featureRailIds[2] = directional::tests::test_hard_rail_id(5);
  constraints.featureCurveIntervals.push_back(
      {7, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0, 0});

  directional::geometry::SurfaceOptimizationOptions options;
  options.maxIterations = 1;
  options.lineSearchSteps.fill(10.0);
  options.weights.surface = 1.0;
  options.weights.normal = 0.0;
  options.weights.field = 0.0;
  options.weights.orthogonality = 0.0;
  options.weights.size = 0.0;
  options.weights.valenceShape = 0.0;
  options.weights.feature = 0.0;
  const Eigen::MatrixXd projected =
      directional::geometry::surface_optimizer_detail::project_vertices(
          vertices, constraints);

  const auto result =
      directional::geometry::optimize_projected_surface_mesh(
          vertices, quads, constraints, options);

  ASSERT_EQ(result.iterations.size(), 1U);
  EXPECT_FALSE(result.iterations.front().accepted);
  EXPECT_TRUE(result.vertices.isApprox(projected, 1.0e-12));
  EXPECT_TRUE(result.featureParametersOrdered);
}

TEST(SurfaceMeshOptimizerPhase20,
     OptimizerUsesDirectDerivativeAndRetainsTopology) {
  Eigen::MatrixXd vertices = derivative_vertices();
  auto constraints = derivative_constraints();
  directional::geometry::SurfaceOptimizationOptions options;
  options.maxIterations = 4;
  const std::uint64_t expectedHash =
      directional::geometry::surface_optimizer_detail::topology_hash(
          derivative_quad());

  const auto result =
      directional::geometry::optimize_projected_surface_mesh(
          vertices, derivative_quad(), constraints, options);

  EXPECT_TRUE(result.directGradientUsed);
  EXPECT_GT(result.directGradientEvaluationCount, 0U);
  EXPECT_EQ(result.topologyHash, expectedHash);
  EXPECT_TRUE(result.topologyHashFixed);
  EXPECT_TRUE(result.monotonicEnergy);
}

TEST(SurfaceMeshOptimizerPhase20,
     ArmijoConditionScalesWithTheActualDescentDirection) {
  const double currentEnergy = 1.0e-8;
  const double trialEnergy = 2.5e-9;
  const double alpha = 0.25;
  const double directionSquaredNorm = 4.0e-8;
  const double armijo = 1.0e-6;

  EXPECT_TRUE(
      directional::geometry::surface_optimizer_detail::armijo_sufficient_decrease(
          currentEnergy, trialEnergy, alpha, directionSquaredNorm, armijo));
  EXPECT_GT(currentEnergy - trialEnergy, 0.0);
  EXPECT_LT(currentEnergy - trialEnergy, armijo * alpha);
}
