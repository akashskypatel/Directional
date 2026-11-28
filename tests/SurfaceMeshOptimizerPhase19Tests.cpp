#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <cmath>
#include <stdexcept>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

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
  c.sourceVertices = source;
  c.sourceFaces.resize(2, 3);
  c.sourceFaces << 0, 1, 2,
      0, 2, 3;
  c.sourceNormals = Eigen::MatrixXd::Zero(2, 3);
  c.sourceNormals.col(2).setOnes();
  c.sourceFieldX = Eigen::MatrixXd::Zero(2, 3);
  c.sourceFieldY = Eigen::MatrixXd::Zero(2, 3);
  c.sourceFieldX.col(0).setOnes();
  c.sourceFieldY.col(1).setOnes();
  static const auto sourceAuthority = [] {
    Eigen::MatrixXi faces(2, 3);
    faces << 0, 1, 2,
        0, 2, 3;
    directional::geometry::SurfaceCellTracingOptions tracing;
    tracing.sourceFaceComponents = {0, 0};
    tracing.sourceFaceSheets = {0, 0};
    auto authority = directional::geometry::surface_cell_tracing_detail::
        build_source_topology_regions(faces, tracing);
    if (!authority.has_value()) {
      throw std::runtime_error(
          "Failed to construct plane source authority.");
    }
    return std::move(*authority);
  }();
  c.sourceAuthority = &sourceAuthority;
  return c;
}

Eigen::MatrixXd source_triangle_vertices() {
  Eigen::MatrixXd v(4, 3);
  v << 0.0, 0.0, 0.0,
       1.0, 0.0, 0.0,
       1.0, 1.0, 0.0,
       0.0, 1.0, 0.0;
  return v;
}

Eigen::MatrixXi source_triangles() {
  Eigen::MatrixXi f(2, 3);
  f << 0, 1, 2,
       0, 2, 3;
  return f;
}

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

directional::geometry::SurfaceOptimizationConstraints
constraints_for_source_triangles() {
  auto c = constraints_for_plane(source_triangle_vertices());
  c.sourceVertices = source_triangle_vertices();
  c.sourceFaces = source_triangles();
  c.sourceNormals.resize(2, 3);
  c.sourceNormals.row(0) << 0.0, 0.0, 1.0;
  c.sourceNormals.row(1) << 0.0, 0.0, 1.0;
  c.sourceFieldX.resize(2, 3);
  c.sourceFieldY.resize(2, 3);
  c.sourceFieldX.row(0) << 1.0, 0.0, 0.0;
  c.sourceFieldX.row(1) << 0.0, 1.0, 0.0;
  c.sourceFieldY.row(0) << 0.0, 1.0, 0.0;
  c.sourceFieldY.row(1) << -1.0, 0.0, 0.0;
  static const auto sourceAuthority =
      test_source_authority(source_triangles(), {0, 0}, {2, 2});
  c.sourceAuthority = &sourceAuthority;
  c.localTargetSize.resize(2);
  c.localTargetSize << 1.0, 0.5;
  c.authoritativeBoundaryLoop = {0, 1, 2, 3};
  return c;
}

} // namespace

TEST(SurfaceMeshOptimizerPhase19, MissingSourceAuthorityFailsClosed) {
  const Eigen::MatrixXd source = plane_vertices();
  auto constraints = constraints_for_plane(source);
  constraints.sourceAuthority = nullptr;

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      source, one_quad(), constraints);
  EXPECT_TRUE(result.rolledBackToInput);
  EXPECT_FALSE(result.projectionHasCompleteProvenance);
  ASSERT_FALSE(result.lastHardInvariantIssues.empty());
  EXPECT_EQ(result.lastHardInvariantIssues.front().code,
            directional::validation::MeshValidationFailureCode::
                MissingSourceAuthority);

  const auto report = directional::geometry::validate_final_surface_mesh(
      source, one_quad(), constraints, result);
  EXPECT_FALSE(report.accepted);
  EXPECT_FALSE(report.sourceAuthoritativeValidationUsed);
  ASSERT_FALSE(report.strictValidationIssues.empty());
  EXPECT_EQ(report.strictValidationIssues.front().code,
            directional::validation::MeshValidationFailureCode::
                MissingSourceAuthority);
}


TEST(SurfaceMeshOptimizerPhase19, SameExtentForeignSourceAuthorityFailsClosed) {
  const Eigen::MatrixXd source = plane_vertices();
  auto constraints = constraints_for_plane(source);
  constraints.sourceFaces.row(0) << 0, 1, 3;
  constraints.sourceFaces.row(1) << 0, 3, 2;

  EXPECT_FALSE(
      directional::geometry::source_optimization_has_complete_authority(
          constraints));
  const auto result = directional::geometry::optimize_projected_surface_mesh(
      source, one_quad(), constraints);
  EXPECT_TRUE(result.rolledBackToInput);
  ASSERT_FALSE(result.lastHardInvariantIssues.empty());
  EXPECT_EQ(directional::validation::MeshValidationFailureCode::
                MissingSourceAuthority,
            result.lastHardInvariantIssues.front().code);
}

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
  constraints.featureCurveIntervals = {
      {1, Eigen::RowVector3d(0.0, 0.0, 0.0),
       Eigen::RowVector3d(1.0, 0.0, 0.0), 1, 0},
      {2, Eigen::RowVector3d(1.0, 0.0, 0.0),
       Eigen::RowVector3d(1.0, 1.0, 0.0), 2, 0}};

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

TEST(SurfaceMeshOptimizerPhase19, LineSearchRejectsConcaveQuad) {
  Eigen::MatrixXd concave = plane_vertices(0.0);
  concave.row(2) << 0.25, 0.25, 0.0;

  EXPECT_FALSE(
      directional::geometry::local_orientation_valid(concave, one_quad()));
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
  Eigen::MatrixXd source(6, 3);
  source << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      0.0, 1.0, 0.0,
      10.0, 0.0, 0.0,
      11.0, 0.0, 0.0,
      10.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      3, 4, 5;
  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = source;
  constraints.sourceFaces = sourceFaces;
  const auto sourceAuthority =
      test_source_authority(sourceFaces, {0, 1}, {0, 0});
  constraints.sourceAuthority = &sourceAuthority;
  constraints.sourceNormals = Eigen::MatrixXd::Zero(2, 3);
  constraints.sourceNormals.col(2).setOnes();
  constraints.sourceFieldX = Eigen::MatrixXd::Zero(2, 3);
  constraints.sourceFieldY = Eigen::MatrixXd::Zero(2, 3);
  constraints.sourceFieldX.col(0).setOnes();
  constraints.sourceFieldY.col(1).setOnes();
  constraints.localTargetSize = Eigen::VectorXd::Ones(6);
  constraints.vertexProvenance.resize(4);
  for (int vertex = 0; vertex < 4; ++vertex) {
    auto &point = constraints.vertexProvenance[static_cast<std::size_t>(vertex)];
    point.face = 0;
    point.barycentric << 1.0, 0.0, 0.0;
    point.position = source.row(0).transpose();
    point.squaredDistance = 0.0;
  }
  Eigen::MatrixXd initial(4, 3);
  initial << 9.9, 0.1, 0.0,
      0.8, 0.1, 0.0,
      0.8, 0.8, 0.0,
      0.1, 0.8, 0.0;

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, one_quad(), constraints);

  EXPECT_TRUE(result.projectionStayedOnComponents);
  EXPECT_LT(result.vertices(0, 0), 2.0);
}

TEST(SurfaceMeshOptimizerPhase19, FeatureParameterOrderGateFailsWhenCrossed) {
  auto constraints = constraints_for_plane(plane_vertices(0.0));
  constraints.featureVertices = {1, 2};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureCurveIds(1) = 7;
  constraints.featureCurveIds(2) = 7;
  constraints.featureParameters = Eigen::VectorXd::Zero(4);
  constraints.featureParameters(1) = 0.8;
  constraints.featureParameters(2) = 0.2;
  constraints.featureCurveIntervals = {
      {7, Eigen::RowVector3d(0.0, 0.0, 0.0),
       Eigen::RowVector3d(1.0, 0.0, 0.0), 1, 0}};
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

TEST(SurfaceMeshOptimizerPhase19, ProjectsToSourceTrianglesWithProvenance) {
  Eigen::MatrixXd initial = source_triangle_vertices();
  initial.array().col(2) += 0.2;
  auto constraints = constraints_for_source_triangles();

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, one_quad(), constraints);

  ASSERT_EQ(result.vertexProvenance.size(), 4U);
  EXPECT_TRUE(result.sourceTriangleProjectionUsed);
  EXPECT_EQ(result.sourceBvhBuildCount, 1U);
  EXPECT_GT(result.projectionQueryCount, 0U);
  for (const auto &point : result.vertexProvenance) {
    EXPECT_TRUE(point.valid());
    EXPECT_GE(point.face, 0);
    EXPECT_EQ(point.component, 0);
    EXPECT_EQ(point.sheet, 2);
    EXPECT_NEAR(point.barycentric.sum(), 1.0, 1.0e-12);
    EXPECT_NEAR(point.position.z(), 0.0, 1.0e-12);
  }
}

TEST(SurfaceMeshOptimizerPhase19, FeatureIntervalsUseCurveIdsNotVertexIds) {
  auto constraints = constraints_for_source_triangles();
  constraints.featureVertices = {1, 2};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureCurveIds(1) = 42;
  constraints.featureCurveIds(2) = 42;
  constraints.featureCurveIntervals.push_back(
      {42, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}});
  Eigen::MatrixXd initial = source_triangle_vertices();
  initial.row(1) << 0.25, 0.4, 0.0;
  initial.row(2) << 0.75, 0.5, 0.0;

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, one_quad(), constraints);

  EXPECT_NEAR(result.vertices(1, 1), 0.0, 1.0e-12);
  EXPECT_NEAR(result.vertices(2, 1), 0.0, 1.0e-12);
  EXPECT_TRUE(result.featureParametersOrdered);
}

TEST(SurfaceMeshOptimizerPhase19, FiniteDifferenceGradientCoversEnabledTerms) {
  auto constraints = constraints_for_source_triangles();
  Eigen::MatrixXd initial = source_triangle_vertices();
  initial.row(2) << 1.1, 0.8, 0.15;
  constraints.featureVertices = {2};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureCurveIds(2) = 99;
  constraints.featureCurveIntervals.push_back(
      {99, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}});

  const auto expectGradientFor = [&](auto setWeight) {
    directional::geometry::SurfaceOptimizationOptions options;
    options.targetSize = 0.8;
    options.weights.surface = 0.0;
    options.weights.normal = 0.0;
    options.weights.field = 0.0;
    options.weights.orthogonality = 0.0;
    options.weights.size = 0.0;
    options.weights.valenceShape = 0.0;
    options.weights.feature = 0.0;
    setWeight(options.weights);
    const auto gradient =
        directional::geometry::finite_difference_surface_optimization_gradient(
            initial, one_quad(), constraints, options);
    EXPECT_EQ(gradient.rows(), initial.rows());
    EXPECT_EQ(gradient.cols(), initial.cols());
    EXPECT_GT(gradient.norm(), 1.0e-8);
  };

  expectGradientFor([](auto &w) { w.surface = 1.0; });
  expectGradientFor([](auto &w) { w.normal = 1.0; });
  expectGradientFor([](auto &w) { w.field = 1.0; });
  expectGradientFor([](auto &w) { w.orthogonality = 1.0; });
  expectGradientFor([](auto &w) { w.size = 1.0; });
  expectGradientFor([](auto &w) { w.valenceShape = 1.0; });
  expectGradientFor([](auto &w) { w.feature = 1.0; });
}

TEST(SurfaceMeshOptimizerPhase19, LocalSourceSizeAndFieldDriveMetrics) {
  auto constraints = constraints_for_source_triangles();
  constraints.localTargetSize << 2.0, 2.0;
  constraints.sourceFieldX.row(0) << 1.0, 1.0, 0.0;
  constraints.sourceFieldX.row(0).normalize();
  constraints.sourceFieldY.row(0) << -1.0, 1.0, 0.0;
  constraints.sourceFieldY.row(0).normalize();
  directional::geometry::SurfaceOptimizationOptions options;
  options.targetSize = 1.0;
  const auto report = directional::geometry::validate_final_surface_mesh(
      source_triangle_vertices(), one_quad(), constraints,
      directional::geometry::optimize_projected_surface_mesh(
          source_triangle_vertices(), one_quad(), constraints, options),
      options, 0.1, 1.0);

  EXPECT_LT(report.sizeP5, 1.0);
  EXPECT_GT(report.fieldP95Degrees, 0.0);
}

TEST(SurfaceMeshOptimizerPhase19, SignedScaledJacobianDetectsInversion) {
  auto constraints = constraints_for_source_triangles();
  Eigen::MatrixXd inverted = source_triangle_vertices();
  inverted.row(1).swap(inverted.row(3));

  const auto report = directional::geometry::validate_final_surface_mesh(
      inverted, one_quad(), constraints,
      directional::geometry::optimize_projected_surface_mesh(
          source_triangle_vertices(), one_quad(), constraints),
      {}, 0.1, 1.0);

  EXPECT_LT(report.scaledJacobianMin, 0.0);
}

TEST(SurfaceMeshOptimizerPhase19, OverlayErrorsAreComputedFromSourceData) {
  auto constraints = constraints_for_source_triangles();
  Eigen::MatrixXd vertices = source_triangle_vertices();
  vertices.row(2) << 1.2, 0.8, 0.1;

  const auto overlay = directional::geometry::make_surface_optimization_overlay(
      vertices, one_quad(), constraints);

  EXPECT_GT(overlay.surfaceError.maxCoeff(), 0.0);
  EXPECT_GT(overlay.fieldAlignmentError.maxCoeff(), 0.0);
  EXPECT_GE(overlay.normalError.maxCoeff(), 0.0);
}

TEST(SurfaceMeshOptimizerPhase19, FinalValidationUsesAuthorityOptions) {
  auto constraints = constraints_for_source_triangles();
  const auto result = directional::geometry::optimize_projected_surface_mesh(
      source_triangle_vertices(), one_quad(), constraints);

  const auto report = directional::geometry::validate_final_surface_mesh(
      result.vertices, one_quad(), constraints, result, {}, 0.1, 1.0);

  EXPECT_TRUE(report.strictValidationUsed);
  EXPECT_TRUE(report.provenanceValidationUsed);
  EXPECT_TRUE(report.authoritativeBoundaryUsed);
  EXPECT_EQ(report.tJunctions, 0);
}

TEST(SurfaceMeshOptimizerPhase19,
     BarycentricProvenanceInterpolatesNormalsFourRosyFieldAndTargetSize) {
  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices.resize(3, 3);
  constraints.sourceVertices << 0.0, 0.0, 0.0,
                                1.0, 0.0, 0.0,
                                0.0, 1.0, 0.0;
  constraints.sourceFaces.resize(1, 3);
  constraints.sourceFaces << 0, 1, 2;
  constraints.sourceNormals.resize(3, 3);
  constraints.sourceNormals << 0.0, 0.0, 1.0,
                               0.0, 0.6, 0.8,
                               0.0, 0.0, 1.0;
  constraints.sourceFieldX.resize(3, 3);
  constraints.sourceFieldX << 1.0, 0.0, 0.0,
                              0.0, 1.0, 0.0,
                              1.0, 0.0, 0.0;
  constraints.localTargetSize.resize(3);
  constraints.localTargetSize << 1.0, 2.0, 4.0;

  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 3;
  point.sheet = 7;
  point.barycentric << 0.2, 0.3, 0.5;

  const auto normal =
      directional::geometry::surface_optimizer_detail::local_source_normal(
          constraints, point, 0);
  const auto cross =
      directional::geometry::surface_optimizer_detail::local_source_cross(
          constraints, point, 0);
  const double target =
      directional::geometry::surface_optimizer_detail::local_target_size(
          constraints, point, 0, 1.0);

  const Eigen::RowVector3d expectedNormal =
      Eigen::RowVector3d(0.0, 0.18, 0.94).normalized();
  EXPECT_TRUE(normal.isApprox(expectedNormal, 1.0e-12));
  EXPECT_NEAR(std::abs(cross.x.dot(Eigen::RowVector3d(1.0, 0.0, 0.0))),
              1.0, 1.0e-12);
  EXPECT_NEAR(cross.x.dot(cross.y), 0.0, 1.0e-12);
  EXPECT_NEAR(target, 2.8, 1.0e-12);
}

TEST(SurfaceMeshOptimizerPhase19,
     ExplicitCurveIntervalsPreserveSegmentAssociationAndOrder) {
  auto constraints = constraints_for_source_triangles();
  constraints.featureVertices = {0, 1};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureIntervalIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureParameters = Eigen::VectorXd::Zero(4);
  constraints.featureCurveIds(0) = 12;
  constraints.featureCurveIds(1) = 12;
  constraints.featureIntervalIds(0) = 101;
  constraints.featureIntervalIds(1) = 102;
  constraints.featureParameters(0) = 0.25;
  constraints.featureParameters(1) = 1.75;
  constraints.orderedFeatureVertices = {0, 1};
  constraints.featureCurveIntervals = {
      {12, Eigen::RowVector3d(0.0, 0.0, 0.0),
       Eigen::RowVector3d(1.0, 0.0, 0.0), 101, 0, 0, 0.0, 1.0},
      {12, Eigen::RowVector3d(1.0, 0.0, 0.0),
       Eigen::RowVector3d(1.0, 1.0, 0.0), 102, 1, 0, 1.0, 2.0}};

  Eigen::MatrixXd vertices = source_triangle_vertices();
  vertices.row(0) << 0.25, 0.4, 0.0;
  vertices.row(1) << 0.6, 0.75, 0.0;
  Eigen::VectorXd parameters;
  bool ordered = false;
  std::vector<directional::geometry::SurfacePoint> provenance;
  const Eigen::MatrixXd projected =
      directional::geometry::surface_optimizer_detail::project_vertices(
          vertices, constraints, &parameters, &ordered, nullptr, &provenance);

  EXPECT_NEAR(projected(0, 0), 0.25, 1.0e-12);
  EXPECT_NEAR(projected(0, 1), 0.0, 1.0e-12);
  EXPECT_NEAR(projected(1, 0), 1.0, 1.0e-12);
  EXPECT_NEAR(projected(1, 1), 0.75, 1.0e-12);
  EXPECT_NEAR(parameters(0), 0.25, 1.0e-12);
  EXPECT_NEAR(parameters(1), 1.75, 1.0e-12);
  EXPECT_TRUE(ordered);
  ASSERT_EQ(provenance.size(), 4U);
  EXPECT_TRUE(provenance[0].valid());
  EXPECT_TRUE(provenance[1].valid());
}

TEST(SurfaceMeshOptimizerPhase19,
     TriangleProjectionFailsClosedWhenTypedSourceAuthorityDoesNotMatchSourceFaces) {
  auto constraints = constraints_for_source_triangles();
  Eigen::MatrixXi foreignFaces = constraints.sourceFaces;
  ASSERT_GE(foreignFaces.rows(), 2);
  const Eigen::RowVectorXi firstForeignRow = foreignFaces.row(0);
  foreignFaces.row(0) = foreignFaces.row(1);
  foreignFaces.row(1) = firstForeignRow;
  const auto foreignAuthority =
      test_source_authority(foreignFaces, {0, 0}, {0, 0});
  ASSERT_FALSE(foreignAuthority.matches_source_faces(
      constraints.sourceFaces,
      static_cast<std::size_t>(constraints.sourceVertices.rows())));
  constraints.sourceAuthority = &foreignAuthority;

  const auto result = directional::geometry::optimize_projected_surface_mesh(
      source_triangle_vertices(), one_quad(), constraints);

  EXPECT_TRUE(result.rolledBackToInput);
  EXPECT_FALSE(result.projectionStayedOnSheets);
  EXPECT_FALSE(result.projectionHasCompleteProvenance);
  EXPECT_FALSE(result.sourceTriangleProjectionUsed);
  ASSERT_FALSE(result.lastHardInvariantIssues.empty());
  EXPECT_EQ(directional::validation::MeshValidationFailureCode::
                MissingSourceAuthority,
            result.lastHardInvariantIssues.front().code);
}

TEST(SurfaceMeshOptimizerPhase19,
     FixedFeatureVertexRefreshesSourceTriangleProvenance) {
  auto constraints = constraints_for_source_triangles();
  constraints.fixedVertices = {0};
  constraints.featureVertices = {0};
  constraints.featureCurveIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureIntervalIds = Eigen::VectorXi::Constant(4, -1);
  constraints.featureParameters = Eigen::VectorXd::Zero(4);
  constraints.featureCurveIds(0) = 4;
  constraints.featureIntervalIds(0) = 9;
  directional::geometry::SurfaceFeatureCurveInterval interval;
  interval.curveId = 4;
  interval.intervalId = 9;
  interval.sourceFace = 0;
  interval.parameterStart = 0.0;
  interval.parameterEnd = 1.0;
  interval.start << 0.0, 0.0, 0.0;
  interval.end << 1.0, 0.0, 0.0;
  constraints.featureCurveIntervals = {interval};
  constraints.vertexProvenance.resize(4);
  for (auto &point : constraints.vertexProvenance) {
    point.face = 0;
    point.component = 0;
    point.sheet = 2;
    point.barycentric << 1.0, 0.0, 0.0;
  }

  Eigen::MatrixXd initial = source_triangle_vertices();
  initial.row(0) << 0.25, 0.2, 0.3;
  const auto result = directional::geometry::optimize_projected_surface_mesh(
      initial, one_quad(), constraints);

  EXPECT_NEAR(result.vertices(0, 0), 0.25, 1.0e-12);
  EXPECT_NEAR(result.vertices(0, 1), 0.0, 1.0e-12);
  EXPECT_NEAR(result.vertices(0, 2), 0.0, 1.0e-12);
  ASSERT_EQ(result.vertexProvenance.size(), 4U);
  EXPECT_TRUE(result.vertexProvenance[0].valid());
  EXPECT_EQ(result.vertexProvenance[0].component, 0);
  EXPECT_EQ(result.vertexProvenance[0].sheet, 2);
  EXPECT_TRUE(result.projectionHasCompleteProvenance);
  EXPECT_TRUE(result.sourceTriangleProjectionUsed);
}

TEST(SurfaceMeshOptimizerPhase19,
     FixedRailSegmentUsesItsRealizableLengthForSizeEnergyAndValidation) {
  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.fixedVertices = {0, 1};
  constraints.featureVertices = {0, 1};
  constraints.featureRailIds.assign(
      2, directional::tests::test_hard_rail_id(17));
  constraints.localTargetSize = Eigen::VectorXd::Constant(2, 0.25);

  directional::geometry::SurfacePoint first;
  first.face = 0;
  first.barycentric << 1.0, 0.0, 0.0;
  directional::geometry::SurfacePoint second = first;

  const double fixedTarget =
      directional::geometry::surface_optimizer_detail::
          effective_edge_target_size(constraints, first, second, 0, 1, 1.0,
                                     0.25);
  EXPECT_DOUBLE_EQ(fixedTarget, 1.0);

  constraints.localTargetSize = Eigen::VectorXd::Constant(2, 0.01);
  const double extremeTarget =
      directional::geometry::surface_optimizer_detail::
          effective_edge_target_size(constraints, first, second, 0, 1, 1.0,
                                     0.01);
  EXPECT_DOUBLE_EQ(extremeTarget, 0.01);

  constraints.localTargetSize = Eigen::VectorXd::Constant(2, 0.25);
  constraints.fixedVertices = {0};
  const double movableTarget =
      directional::geometry::surface_optimizer_detail::
          effective_edge_target_size(constraints, first, second, 0, 1, 1.0,
                                     0.25);
  EXPECT_DOUBLE_EQ(movableTarget, 0.25);
}
