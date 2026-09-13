#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <cmath>
#include <memory>

#include <gtest/gtest.h>

namespace {

const directional::geometry::SourceTopologyRegions *test_source_authority(
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
  static std::vector<std::unique_ptr<directional::geometry::SourceTopologyRegions>> arena;
  arena.push_back(std::make_unique<directional::geometry::SourceTopologyRegions>(
      std::move(*authority)));
  return arena.back().get();
}

Eigen::MatrixXi one_quad() {
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  return quads;
}

directional::geometry::SurfaceOptimizationConstraints make_constraints(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const Eigen::RowVector3d &normal,
    const Eigen::RowVector3d &fieldX = Eigen::RowVector3d(1.0, 0.0, 0.0)) {
  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = sourceVertices;
  constraints.sourceFaces = sourceFaces;
  constraints.sourceNormals =
      Eigen::MatrixXd::Zero(sourceFaces.rows(), 3);
  constraints.sourceFieldX =
      Eigen::MatrixXd::Zero(sourceFaces.rows(), 3);
  constraints.sourceFieldY =
      Eigen::MatrixXd::Zero(sourceFaces.rows(), 3);
  for (int face = 0; face < sourceFaces.rows(); ++face) {
    constraints.sourceNormals.row(face) = normal.normalized();
    Eigen::RowVector3d x = fieldX - fieldX.dot(normal) * normal;
    if (x.norm() <= 1.0e-12) {
      x = Eigen::RowVector3d(0.0, 1.0, 0.0);
    }
    x.normalize();
    constraints.sourceFieldX.row(face) = x;
    constraints.sourceFieldY.row(face) = normal.normalized().cross(x);
  }
  const std::vector<int> sourceComponents(
      static_cast<std::size_t>(sourceFaces.rows()), 0);
  const std::vector<int> sourceSheets(
      static_cast<std::size_t>(sourceFaces.rows()), 0);
  constraints.sourceAuthority =
      test_source_authority(sourceFaces, sourceComponents, sourceSheets);
  constraints.localTargetSize =
      Eigen::VectorXd::Ones(sourceVertices.rows());
  return constraints;
}

std::vector<directional::geometry::SurfacePoint> project_provenance(
    const Eigen::MatrixXd &vertices,
    const directional::geometry::SurfaceOptimizationConstraints &constraints) {
  std::vector<directional::geometry::SurfacePoint> provenance;
  directional::geometry::surface_optimizer_detail::project_vertices(
      vertices, constraints, nullptr, nullptr, nullptr, nullptr, nullptr,
      &provenance);
  return provenance;
}

Eigen::MatrixXd strip_vertices() {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      0.0, 1.0, 0.0,
      1.0, 1.0, 0.0,
      2.0, 1.0, 0.0;
  return vertices;
}

Eigen::MatrixXi strip_quads() {
  Eigen::MatrixXi quads(2, 4);
  quads << 0, 1, 4, 3,
      1, 2, 5, 4;
  return quads;
}

Eigen::MatrixXi strip_triangles() {
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4,
      0, 4, 3,
      1, 2, 5,
      1, 5, 4;
  return faces;
}

} // namespace

TEST(SurfaceMeshOptimizerPhase21,
     SignedScaledJacobianUsesRotatedLocalSourceNormal) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 1.0, 1.0,
      0.0, 0.0, 1.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  const auto constraints = make_constraints(
      vertices, sourceFaces, Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0));
  const auto optimization =
      directional::geometry::optimize_projected_surface_mesh(
          vertices, one_quad(), constraints);
  const auto good = directional::geometry::validate_final_surface_mesh(
      vertices, one_quad(), constraints, optimization);
  EXPECT_GT(good.scaledJacobianMin, 0.99);
  EXPECT_EQ(good.inverted, 0);

  Eigen::MatrixXd inverted = vertices;
  inverted.row(1).swap(inverted.row(3));
  const auto bad = directional::geometry::validate_final_surface_mesh(
      inverted, one_quad(), constraints, optimization);
  EXPECT_LT(bad.scaledJacobianMin, 0.0);
}

TEST(SurfaceMeshOptimizerPhase21,
     QuadQualityReportsConvexityWarpageAnglesAndAspect) {
  Eigen::MatrixXd rectangle(4, 3);
  rectangle << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      2.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  const auto planar = directional::geometry::evaluate_surface_quad_quality(
      rectangle, one_quad(), 0, Eigen::RowVector3d(0.0, 0.0, 1.0));
  EXPECT_TRUE(planar.convex);
  EXPECT_NEAR(planar.warpageDegrees, 0.0, 1.0e-12);
  EXPECT_NEAR(planar.minimumAngleDegrees, 90.0, 1.0e-12);
  EXPECT_NEAR(planar.maximumAngleDegrees, 90.0, 1.0e-12);
  EXPECT_NEAR(planar.aspectRatio, 2.0, 1.0e-12);

  Eigen::MatrixXd concave = rectangle;
  concave.row(2) << 0.5, 0.25, 0.0;
  const auto folded = directional::geometry::evaluate_surface_quad_quality(
      concave, one_quad(), 0, Eigen::RowVector3d(0.0, 0.0, 1.0));
  EXPECT_FALSE(folded.convex);

  Eigen::MatrixXd warped = rectangle;
  warped(2, 2) = 0.5;
  const auto nonPlanar = directional::geometry::evaluate_surface_quad_quality(
      warped, one_quad(), 0, Eigen::RowVector3d(0.0, 0.0, 1.0));
  EXPECT_GT(nonPlanar.warpageDegrees, 0.0);
}

TEST(SurfaceMeshOptimizerPhase21,
     BidirectionalSamplingDetectsSourceCoverageHole) {
  Eigen::MatrixXd source(4, 3);
  source << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      2.0, 2.0, 0.0,
      0.0, 2.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  auto constraints = make_constraints(
      source, sourceFaces, Eigen::RowVector3d(0.0, 0.0, 1.0));

  Eigen::MatrixXd output(4, 3);
  output << 0.5, 0.5, 0.0,
      1.5, 0.5, 0.0,
      1.5, 1.5, 0.0,
      0.5, 1.5, 0.0;
  directional::geometry::SurfaceOptimizationResult optimization;
  optimization.vertices = output;
  optimization.quads = one_quad();
  optimization.vertexProvenance = project_provenance(output, constraints);

  const auto report = directional::geometry::validate_final_surface_mesh(
      output, one_quad(), constraints, optimization);
  EXPECT_EQ(report.quadToSourceSampleCount, 9U);
  EXPECT_EQ(report.sourceToOutputSampleCount, 14U);
  EXPECT_NEAR(report.quadToSourceMax, 0.0, 1.0e-12);
  EXPECT_GT(report.sourceToOutputMax, 0.5);
  EXPECT_FALSE(report.accepted);
}

TEST(SurfaceMeshOptimizerPhase21,
     BoundaryValenceTargetsDistinguishCornersAndStraightSamples) {
  const Eigen::MatrixXd vertices = strip_vertices();
  const Eigen::MatrixXi quads = strip_quads();
  auto constraints = make_constraints(
      vertices, strip_triangles(), Eigen::RowVector3d(0.0, 0.0, 1.0));
  const auto optimization =
      directional::geometry::optimize_projected_surface_mesh(
          vertices, quads, constraints);
  const auto inferred = directional::geometry::validate_final_surface_mesh(
      vertices, quads, constraints, optimization);
  EXPECT_EQ(inferred.boundaryValenceTargetCount, 6);
  EXPECT_EQ(inferred.boundaryValenceMismatchCount, 0);

  constraints.boundaryValenceTargets[1] = 2;
  const auto explicitWrong =
      directional::geometry::validate_final_surface_mesh(
          vertices, quads, constraints, optimization);
  EXPECT_EQ(explicitWrong.boundaryValenceMismatchCount, 1);
}

TEST(SurfaceMeshOptimizerPhase21,
     RequiredSingularityTargetsDistinguishBoundaryAndInteriorValence) {
  Eigen::MatrixXd source(4, 3);
  source << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  auto constraints = make_constraints(
      source, sourceFaces, Eigen::RowVector3d(0.0, 0.0, 1.0));
  const auto optimization =
      directional::geometry::optimize_projected_surface_mesh(
          source, one_quad(), constraints);

  Eigen::VectorXi cycles(1);
  Eigen::VectorXi indices(1);
  cycles << 0;
  indices << 1;
  directional::geometry::fill_required_singularity_valence_targets(
      source, sourceFaces, cycles, indices, source,
      optimization.vertexProvenance, constraints);
  ASSERT_EQ(constraints.requiredSingularityValenceTargets.size(), 1U);
  // A +1 quarter-index at a source boundary corner uses the boundary
  // regular valence: 3 - 1 = 2.
  EXPECT_EQ(constraints.requiredSingularityValenceTargets.begin()->second, 2);
  const auto boundaryMatched =
      directional::geometry::validate_final_surface_mesh(
          source, one_quad(), constraints, optimization);
  EXPECT_EQ(boundaryMatched.requiredSingularityValenceMismatchCount, 0);

  constraints.requiredSingularityValenceTargets.begin()->second = 3;
  const auto boundaryMismatch =
      directional::geometry::validate_final_surface_mesh(
          source, one_quad(), constraints, optimization);
  EXPECT_EQ(boundaryMismatch.requiredSingularityValenceMismatchCount, 1);

  Eigen::MatrixXd interiorSource(5, 3);
  interiorSource << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      0.5, 0.5, 0.0;
  Eigen::MatrixXi interiorFaces(4, 3);
  interiorFaces << 0, 1, 4,
      1, 2, 4,
      2, 3, 4,
      3, 0, 4;
  Eigen::MatrixXd interiorOutput(1, 3);
  interiorOutput.row(0) = interiorSource.row(4);
  std::vector<directional::geometry::SurfacePoint> interiorProvenance(1);
  interiorProvenance[0].face = 0;
  interiorProvenance[0].component = 0;
  interiorProvenance[0].sheet = 0;
  interiorProvenance[0].barycentric = Eigen::Vector3d(0.0, 0.0, 1.0);
  interiorProvenance[0].position = interiorSource.row(4).transpose();
  cycles << 4;
  indices << 1;
  directional::geometry::fill_required_singularity_valence_targets(
      interiorSource, interiorFaces, cycles, indices, interiorOutput,
      interiorProvenance, constraints);
  ASSERT_EQ(constraints.requiredSingularityValenceTargets.size(), 1U);
  // The same +1 index at an interior source vertex retains 4 - 1 = 3.
  EXPECT_EQ(constraints.requiredSingularityValenceTargets.begin()->second, 3);

  Eigen::MatrixXd oneOutput(1, 3);
  oneOutput << 0.5, 0.0, 0.0;
  std::vector<directional::geometry::SurfacePoint> oneProvenance(1);
  oneProvenance[0] = optimization.vertexProvenance[0];
  Eigen::VectorXi conflictingCycles(2);
  Eigen::VectorXi conflictingIndices(2);
  conflictingCycles << 0, 1;
  conflictingIndices << 1, -1;
  directional::geometry::fill_required_singularity_valence_targets(
      source, sourceFaces, conflictingCycles, conflictingIndices, oneOutput,
      oneProvenance, constraints);
  ASSERT_EQ(constraints.requiredSingularityValenceTargets.size(), 1U);
  EXPECT_EQ(constraints.requiredSingularityValenceTargets.begin()->second, 0);
}


TEST(SurfaceMeshOptimizerPhase21,
     PipelineStyleBoundarySingularitiesAcceptCompletedCloseSheetQuads) {
  Eigen::MatrixXd source(8, 3);
  source << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 0.0, 0.02,
      1.0, 0.0, 0.02,
      1.0, 1.0, 0.02,
      0.0, 1.0, 0.02;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3,
      4, 5, 6,
      4, 6, 7;
  Eigen::MatrixXi quads(2, 4);
  quads << 0, 1, 2, 3,
      4, 5, 6, 7;

  auto constraints = make_constraints(
      source, sourceFaces, Eigen::RowVector3d(0.0, 0.0, 1.0));
  constraints.sourceAuthority =
      test_source_authority(sourceFaces, {0, 0, 1, 1}, {0, 0, 1, 1});

  directional::geometry::SurfaceOptimizationResult optimization;
  optimization.vertices = source;
  optimization.quads = quads;
  optimization.vertexProvenance = project_provenance(source, constraints);
  optimization.topologyHash =
      directional::geometry::surface_optimizer_detail::topology_hash(quads);

  Eigen::VectorXi cycles(8);
  Eigen::VectorXi indices = Eigen::VectorXi::Ones(8);
  for (int vertex = 0; vertex < cycles.size(); ++vertex) {
    cycles(vertex) = vertex;
  }
  directional::geometry::fill_required_singularity_valence_targets(
      source, sourceFaces, cycles, indices, source,
      optimization.vertexProvenance, constraints);

  ASSERT_EQ(constraints.requiredSingularityValenceTargets.size(), 8U);
  for (const auto &[vertex, target] :
       constraints.requiredSingularityValenceTargets) {
    EXPECT_GE(vertex, 0);
    EXPECT_EQ(target, 2);
  }
  const auto validation = directional::geometry::validate_final_surface_mesh(
      source, quads, constraints, optimization);
  EXPECT_EQ(validation.requiredSingularityValenceMismatchCount, 0);
  EXPECT_TRUE(validation.accepted);
}

TEST(SurfaceMeshOptimizerPhase21,
     OverlayUsesSourceSamplesForNormalFieldCoverageAndValence) {
  const Eigen::MatrixXd vertices = strip_vertices();
  const Eigen::MatrixXi quads = strip_quads();
  auto constraints = make_constraints(
      vertices, strip_triangles(), Eigen::RowVector3d(0.0, 0.2, 1.0),
      Eigen::RowVector3d(1.0, 1.0, 0.0));
  const auto overlay = directional::geometry::make_surface_optimization_overlay(
      vertices, quads, constraints);

  EXPECT_EQ(overlay.sourceToOutputError.size(), vertices.rows());
  EXPECT_GT(overlay.normalError.maxCoeff(), 0.0);
  EXPECT_GT(overlay.fieldAlignmentError.maxCoeff(), 0.0);
  EXPECT_EQ(overlay.targetValence(0), 2);
  EXPECT_EQ(overlay.targetValence(1), 3);
  EXPECT_EQ(overlay.valenceError.maxCoeff(), 0);
  EXPECT_EQ(overlay.valenceError.minCoeff(), 0);
}

TEST(SurfaceMeshOptimizerPhase21,
     ReverseSamplingDoesNotLeakAcrossCloseSheets) {
  Eigen::MatrixXd source(8, 3);
  source << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 0.0, 0.01,
      1.0, 0.0, 0.01,
      1.0, 1.0, 0.01,
      0.0, 1.0, 0.01;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3,
      4, 6, 5,
      4, 7, 6;
  auto constraints = make_constraints(
      source, sourceFaces, Eigen::RowVector3d(0.0, 0.0, 1.0));
  constraints.sourceAuthority =
      test_source_authority(sourceFaces, {0, 0, 0, 0}, {0, 0, 1, 1});

  const Eigen::MatrixXd output = source.topRows(4);
  directional::geometry::SurfaceOptimizationResult optimization;
  optimization.vertices = output;
  optimization.quads = one_quad();
  optimization.vertexProvenance = project_provenance(output, constraints);
  for (auto &point : optimization.vertexProvenance) {
    point.sheet = 0;
  }

  const auto report = directional::geometry::validate_final_surface_mesh(
      output, one_quad(), constraints, optimization);
  EXPECT_TRUE(std::isinf(report.sourceToOutputMax));
  EXPECT_FALSE(report.accepted);
}

TEST(SurfaceMeshOptimizerPhase21,
     MixedOutputSheetAuthorityFailsClosed) {
  Eigen::MatrixXd source(8, 3);
  source << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 0.0, 0.01,
      1.0, 0.0, 0.01,
      1.0, 1.0, 0.01,
      0.0, 1.0, 0.01;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3,
      4, 6, 5,
      4, 7, 6;
  auto constraints = make_constraints(
      source, sourceFaces, Eigen::RowVector3d(0.0, 0.0, 1.0));
  constraints.sourceAuthority =
      test_source_authority(sourceFaces, {0, 0, 0, 0}, {0, 0, 1, 1});

  const Eigen::MatrixXd output = source.topRows(4);
  directional::geometry::SurfaceOptimizationResult optimization;
  optimization.vertices = output;
  optimization.quads = one_quad();
  optimization.vertexProvenance = project_provenance(output, constraints);
  ASSERT_EQ(optimization.vertexProvenance.size(), 4U);
  optimization.vertexProvenance[0].sheet = 0;
  optimization.vertexProvenance[1].sheet = 1;
  optimization.vertexProvenance[2].sheet = 0;
  optimization.vertexProvenance[3].sheet = 1;

  const auto report = directional::geometry::validate_final_surface_mesh(
      output, one_quad(), constraints, optimization);
  EXPECT_TRUE(std::isinf(report.quadToSourceMax));
  EXPECT_TRUE(std::isinf(report.sourceToOutputMax));
  EXPECT_FALSE(report.accepted);
}
