#include <directional/geometry/SurfaceMeshOptimizer.h>

#include <cmath>

#include <gtest/gtest.h>

namespace {

Eigen::MatrixXd plane_vertices(const double offset = 0.0) {
  Eigen::MatrixXd v(4, 3);
  v << 0.0, 0.0, offset, 1.0, 0.0, offset, 1.0, 1.0, offset, 0.0, 1.0,
      offset;
  return v;
}

Eigen::MatrixXi one_quad() {
  Eigen::MatrixXi q(1, 4);
  q << 0, 1, 2, 3;
  return q;
}

directional::geometry::SurfaceOptimizationConstraints
constraints_for_plane(const Eigen::MatrixXd &source) {
  directional::geometry::SurfaceOptimizationConstraints c;
  c.sourcePositions = source;
  c.sourceNormals = Eigen::MatrixXd::Constant(1, 3, 0.0);
  c.sourceNormals.row(0) << 0.0, 0.0, 1.0;
  c.sourceFieldX.resize(1, 3);
  c.sourceFieldY.resize(1, 3);
  c.sourceFieldX.row(0) << 1.0, 0.0, 0.0;
  c.sourceFieldY.row(0) << 0.0, 1.0, 0.0;
  c.sourceComponent = Eigen::VectorXi::Zero(source.rows());
  return c;
}

} // namespace

TEST(SurfaceMeshOptimizerPhase19, PlanarGridConvergesToSourceProjection) {
  const Eigen::MatrixXd source = plane_vertices(0.0);
  Eigen::MatrixXd initial = plane_vertices(0.2);
  const Eigen::MatrixXi quads = one_quad();
  auto constraints = constraints_for_plane(source);
  directional::geometry::SurfaceOptimizationOptions options;
  options.maxIterations = 8;
  options.targetSize = 1.0;

  const auto before = directional::geometry::evaluate_surface_optimization_energy(
      initial, quads, constraints, options);
  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, quads, constraints, options);
  const auto after = directional::geometry::evaluate_surface_optimization_energy(
      result.vertices, quads, constraints, options);

  EXPECT_LT(after.total, before.total);
  EXPECT_TRUE(result.monotonicEnergy);
  EXPECT_NEAR(result.vertices.col(2).norm(), 0.0, 1.0e-12);
}

TEST(SurfaceMeshOptimizerPhase19, SphereCylinderStyleProjectionStaysOnSamples) {
  Eigen::MatrixXd source(4, 3);
  source << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0,
      0.0;
  Eigen::MatrixXd initial = 1.2 * source;
  const Eigen::MatrixXi quads = one_quad();
  auto constraints = constraints_for_plane(source);
  constraints.sourceNormals = source;
  constraints.sourceComponent = Eigen::VectorXi::Zero(source.rows());

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, quads, constraints);

  for (int i = 0; i < source.rows(); ++i) {
    EXPECT_NEAR((result.vertices.row(i) - source.row(i)).norm(), 0.0, 1.0e-12);
  }
}

TEST(SurfaceMeshOptimizerPhase19, FeatureCornerFixedAndFeatureEdgeSlides) {
  const Eigen::MatrixXd source = plane_vertices(0.0);
  Eigen::MatrixXd initial = source;
  initial.row(1) << 0.4, 0.2, 0.0;
  auto constraints = constraints_for_plane(source);
  constraints.fixedVertices = {0};
  constraints.featureVertices = {1, 2};
  constraints.featureIntervals.resize(4);
  constraints.featureIntervals[1] = {Eigen::RowVector3d(0.0, 0.0, 0.0),
                                     Eigen::RowVector3d(1.0, 0.0, 0.0)};
  constraints.featureIntervals[2] = {Eigen::RowVector3d(1.0, 0.0, 0.0),
                                     Eigen::RowVector3d(1.0, 1.0, 0.0)};

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, one_quad(), constraints);

  EXPECT_TRUE(result.vertices.row(0).isApprox(source.row(0)));
  EXPECT_NEAR(result.vertices(1, 1), 0.0, 1.0e-12);
  EXPECT_TRUE(result.featureParametersOrdered);
}

TEST(SurfaceMeshOptimizerPhase19, LineSearchRejectsFaceInversion) {
  Eigen::MatrixXd source = plane_vertices(0.0);
  Eigen::MatrixXd inverted = source;
  inverted.row(1).swap(inverted.row(3));
  EXPECT_FALSE(
      directional::geometry::local_orientation_valid(inverted, one_quad()));
}

TEST(SurfaceMeshOptimizerPhase19, DegreeFourAverageHandlesNinetyDegreeRelabel) {
  const auto q = directional::geometry::degree_four_average(
      {0.0, 0.5 * 3.14159265358979323846});

  EXPECT_NEAR(std::abs(q), 1.0, 1.0e-12);
  EXPECT_NEAR(q.real(), 1.0, 1.0e-12);
  EXPECT_NEAR(q.imag(), 0.0, 1.0e-12);
}

TEST(SurfaceMeshOptimizerPhase19, DeterministicEnergyReductionAndTopologyHash) {
  const Eigen::MatrixXd source = plane_vertices(0.0);
  const Eigen::MatrixXd initial = plane_vertices(0.1);
  const Eigen::MatrixXi quads = one_quad();
  const auto constraints = constraints_for_plane(source);
  const auto first = directional::geometry::optimize_projected_surface_mesh(
      initial, quads, constraints);
  const auto second = directional::geometry::optimize_projected_surface_mesh(
      initial, quads, constraints);

  ASSERT_FALSE(first.iterations.empty());
  EXPECT_EQ(first.topologyHash, second.topologyHash);
  EXPECT_TRUE(first.topologyHashFixed);
  EXPECT_TRUE(first.vertices.isApprox(second.vertices, 1.0e-12));
}

TEST(SurfaceMeshOptimizerPhase19, FinalValidationPassesSectionFiveFixture) {
  const Eigen::MatrixXd source = plane_vertices(0.0);
  const Eigen::MatrixXi quads = one_quad();
  const auto constraints = constraints_for_plane(source);
  directional::geometry::SurfaceOptimizationOptions options;
  options.targetSize = 1.0;
  const auto result = directional::geometry::optimize_projected_surface_mesh(
      source, quads, constraints, options);

  const auto report = directional::geometry::validate_final_surface_mesh(
      result.vertices, quads, constraints, result, options, 0.1, 1.0);

  EXPECT_TRUE(report.accepted);
  EXPECT_EQ(report.tJunctions, 0);
  EXPECT_EQ(report.nonManifold, 0);
  EXPECT_TRUE(report.optimizerTimeWithinGate);
}

TEST(SurfaceMeshOptimizerPhase19, ProjectionDoesNotJumpAcrossComponents) {
  Eigen::MatrixXd source(4, 3);
  source << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 10.0, 0.0, 0.0, 11.0, 0.0,
      0.0;
  Eigen::MatrixXd initial = source;
  initial.row(0) << 9.9, 0.0, 0.0;
  auto constraints = constraints_for_plane(source);
  constraints.sourceComponent.resize(4);
  constraints.sourceComponent << 0, 0, 1, 1;

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, one_quad(), constraints);

  EXPECT_TRUE(result.projectionStayedOnComponents);
  EXPECT_NEAR(result.vertices(0, 0), 1.0, 1.0e-12);
}

TEST(SurfaceMeshOptimizerPhase19, FeatureParameterOrderGateFailsWhenCrossed) {
  auto constraints = constraints_for_plane(plane_vertices(0.0));
  constraints.featureVertices = {1, 2};
  constraints.featureParameters = Eigen::VectorXd::Zero(4);
  constraints.featureParameters(1) = 0.8;
  constraints.featureParameters(2) = 0.2;
  constraints.featureIntervals.resize(4);
  constraints.featureIntervals[1] = {Eigen::RowVector3d(0.0, 0.0, 0.0),
                                     Eigen::RowVector3d(1.0, 0.0, 0.0)};
  constraints.featureIntervals[2] = constraints.featureIntervals[1];
  bool ordered = true;
  Eigen::MatrixXd crossed = plane_vertices(0.0);
  crossed.row(1) << 0.8, 0.0, 0.0;
  crossed.row(2) << 0.2, 0.0, 0.0;
  directional::geometry::surface_optimizer_detail::project_vertices(
      crossed, constraints, nullptr, &ordered, nullptr);
  EXPECT_FALSE(ordered);
}

TEST(SurfaceMeshOptimizerPhase19, OverlayProvidesRequiredHeatmapChannels) {
  const Eigen::MatrixXd source = plane_vertices(0.0);
  const Eigen::MatrixXi quads = one_quad();
  const auto constraints = constraints_for_plane(source);

  const auto overlay = directional::geometry::make_surface_optimization_overlay(
      source, quads, constraints);

  EXPECT_EQ(overlay.wireframeStarts.rows(), 4);
  EXPECT_EQ(overlay.wireframeEnds.rows(), 4);
  EXPECT_EQ(overlay.shadedVertices.rows(), source.rows());
  EXPECT_EQ(overlay.surfaceError.size(), source.rows());
  EXPECT_EQ(overlay.normalError.size(), quads.rows());
  EXPECT_EQ(overlay.fieldAlignmentError.size(), 4 * quads.rows());
  EXPECT_EQ(overlay.sizeRatio.size(), 4 * quads.rows());
  EXPECT_EQ(overlay.poleValence.size(), source.rows());
}

TEST(SurfaceMeshOptimizerPhase19, OptimizerTimingGateCanFail) {
  const Eigen::MatrixXd source = plane_vertices(0.0);
  const Eigen::MatrixXi quads = one_quad();
  const auto constraints = constraints_for_plane(source);
  directional::geometry::SurfaceOptimizationOptions options;
  options.targetSize = 1.0;
  const auto result = directional::geometry::optimize_projected_surface_mesh(
      source, quads, constraints, options);

  const auto report = directional::geometry::validate_final_surface_mesh(
      result.vertices, quads, constraints, result, options, 0.5, 1.0);

  EXPECT_FALSE(report.optimizerTimeWithinGate);
  EXPECT_FALSE(report.accepted);
}
