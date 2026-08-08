#include <directional/fields/PointSampledCrossField.h>
#include <directional/io/ReadOBJ.h>
#include <directional/meshing/PatchQuadrangulator.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "TestFixturePaths.h"
#include <directional/validation/MeshValidator.h>
#include <directional/validation/ValidationVisualizer.h>

#include <cmath>
#include <chrono>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <stdexcept>

#include <gtest/gtest.h>

namespace {

using directional::validation::MeshValidationFailureCode;

directional::TriMesh make_two_sheet_mesh() {
  Eigen::MatrixXd vertices(8, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      0.0, 0.0, 0.001, 1.0, 0.0, 0.001, 1.0, 1.0, 0.001, 0.0, 1.0, 0.001;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 2, 0, 2, 3, 4, 6, 5, 4, 7, 6;
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

directional::TriMesh make_square_mesh() {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
      0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

directional::fields::PointSampledCrossFieldOptions two_sheet_projection_options() {
  directional::fields::PointSampledCrossFieldOptions options;
  options.uncoveredFacePolicy =
      directional::fields::UncoveredFacePolicy::PropagateWithinComponent;
  options.faceComponents = {0, 0, 1, 1};
  options.faceSheets = {0, 0, 1, 1};
  return options;
}

bool has_code(const directional::validation::MeshValidationResult &result,
              const MeshValidationFailureCode code) {
  for (const auto &issue : result.issues) {
    if (issue.code == code) {
      return true;
    }
  }
  return false;
}

std::uint64_t hash_matrix(const Eigen::MatrixXd &matrix) {
  std::uint64_t hash = 1469598103934665603ULL;
  for (int row = 0; row < matrix.rows(); ++row) {
    for (int col = 0; col < matrix.cols(); ++col) {
      const long long quantized =
          static_cast<long long>(std::llround(matrix(row, col) * 1.0e12));
      hash ^= static_cast<std::uint64_t>(quantized);
      hash *= 1099511628211ULL;
    }
  }
  return hash;
}

std::uint64_t hash_matrix(const Eigen::MatrixXi &matrix) {
  std::uint64_t hash = 1469598103934665603ULL;
  for (int row = 0; row < matrix.rows(); ++row) {
    for (int col = 0; col < matrix.cols(); ++col) {
      hash ^= static_cast<std::uint64_t>(matrix(row, col));
      hash *= 1099511628211ULL;
    }
  }
  return hash;
}

directional::pipeline::RemeshResult run_phase10_tiny_remesh() {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  return directional::pipeline::remesh_from_mesh(vertices, faces, options);
}

TEST(SurfaceCellsPhase10, MeshValidatorDetectsMissingVertex) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 8;

  const auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces);

  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::MissingVertex));
}

TEST(SurfaceCellsPhase10, MeshValidatorAcceptsPaddedTriangleSentinel) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
      0.0;
  Eigen::MatrixXi faces(2, 4);
  faces << 0, 1, 2, -1, 0, 2, 3, -1;

  const auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces);

  EXPECT_TRUE(result.accepted);
}

TEST(SurfaceCellsPhase10, MeshValidatorDetectsInteriorEdgeIncidenceDefects) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      2.0, 0.0, 0.0;
  Eigen::MatrixXi oneSided(1, 3);
  oneSided << 0, 1, 2;
  directional::validation::MeshValidatorOptions options;
  options.authoritativeBoundaryEdges.insert({0, 1});
  options.authoritativeBoundaryEdges.insert({1, 2});

  auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    oneSided,
                                                                    options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::OneSidedInteriorEdge));

  Eigen::MatrixXi threeSided(3, 3);
  threeSided << 0, 1, 2, 1, 0, 3, 0, 1, 4;
  result = directional::validation::MeshValidator::validate_surface_mesh(
      vertices, threeSided);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::ThreeSidedInteriorEdge));
}

TEST(SurfaceCellsPhase10, MeshValidatorDetectsDuplicateAndInvalidFaces) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi duplicate(2, 3);
  duplicate << 0, 1, 2, 2, 0, 1;

  auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    duplicate);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::DuplicateFace));

  Eigen::MatrixXi zeroArea(1, 4);
  zeroArea << 0, 1, 1, 3;
  result = directional::validation::MeshValidator::validate_surface_mesh(
      vertices, zeroArea);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::ZeroAreaFace));

  Eigen::MatrixXi bowTie(1, 4);
  bowTie << 0, 1, 3, 2;
  result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    bowTie);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::SelfIntersectingFace));
}

TEST(SurfaceCellsPhase10,
     MeshValidatorDetectsWrongBoundaryChangedLoopAndFlippedFace) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;

  directional::validation::MeshValidatorOptions options;
  options.authoritativeBoundaryEdges.insert({0, 2});
  auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces,
                                                                    options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::WrongBoundaryEdge));

  options = {};
  options.authoritativeBoundaryLoop = {0, 1, 2, 7};
  result = directional::validation::MeshValidator::validate_surface_mesh(
      vertices, faces, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::ChangedBoundaryLoop));

  Eigen::MatrixXi flipped(2, 3);
  flipped << 0, 1, 2, 2, 0, 3;
  options = {};
  options.requireConsistentOrientation = true;
  result = directional::validation::MeshValidator::validate_surface_mesh(
      vertices, flipped, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::FlippedFace));
}

TEST(SurfaceCellsPhase10, MeshValidatorDetectsBowTieVertexAndComponentMismatch) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0,
      0.0, -1.0, 0.0, 2.0, 2.0, 0.0;
  Eigen::MatrixXi bowTie(2, 3);
  bowTie << 0, 1, 2, 0, 3, 4;

  auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    bowTie);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::BowTieVertex));

  Eigen::MatrixXi disconnected(2, 3);
  disconnected << 0, 1, 2, 3, 4, 5;
  directional::validation::MeshValidatorOptions options;
  options.expectedConnectedComponents = 1;
  result = directional::validation::MeshValidator::validate_surface_mesh(
      vertices, disconnected, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::ComponentMerge));
}

TEST(SurfaceCellsPhase10, MeshValidatorDetectsFaceToFaceIntersection) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << -1.0, -1.0, 0.0, 1.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
      -0.25, -1.0, 0.0, -0.25, 1.0, 0.0, 0.75, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 3, 4, 5;

  const auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces);

  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::SelfIntersectingFace));
}

TEST(SurfaceCellsPhase10, MeshValidatorDetectsGeometricTJunction) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 0.0;
  Eigen::MatrixXi faces(1, 4);
  faces << 0, 1, 2, 3;

  const auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces);

  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(
      has_code(result, MeshValidationFailureCode::GeometricVertexOnUnsplitEdge));
}

TEST(SurfaceCellsPhase10, DefectVisualizerColorsExactIssueReferences) {
  directional::validation::MeshValidationResult validation;
  validation.fail({MeshValidationFailureCode::GeometricVertexOnUnsplitEdge, 4,
                   0, 1, 0});

  const directional::validation::ValidationDebugColors colors =
      directional::validation::make_validation_debug_colors(5, 1, validation);

  EXPECT_TRUE(
      colors.vertexColors.row(4).isApprox(Eigen::RowVector3d(1.0, 0.0, 0.0)));
  EXPECT_TRUE(colors.vertexColors.row(0).isApprox(
      Eigen::RowVector3d(1.0, 0.55, 0.0)));
  EXPECT_TRUE(colors.vertexColors.row(1).isApprox(
      Eigen::RowVector3d(1.0, 0.55, 0.0)));
  EXPECT_TRUE(
      colors.faceColors.row(0).isApprox(Eigen::RowVector3d(0.85, 0.0, 1.0)));
}

TEST(SurfaceCellsPhase10,
     PatchQuadrangulatorRejectsGeometricTJunctionAcceptedByPhase06ShapeCheck) {
  directional::detail::PatchMesh mesh;
  mesh.vertices = {0, 1, 2, 3, 4};
  mesh.boundaryVertices = {0, 1, 2, 3};
  mesh.quads = {{0, 1, 2, 3}};
  mesh.vertexPositions.resize(5, 3);
  mesh.vertexPositions << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0,
      1.0, 0.0, 1.0, 0.0, 0.0;

  EXPECT_FALSE(
      directional::detail::PatchQuadrangulator::output_has_no_t_junctions(
          mesh));
}

TEST(SurfaceCellsPhase10, GeometricTJunctionIgnoresDisconnectedCloseSheet) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 0.0;
  Eigen::MatrixXi faces(1, 4);
  faces << 0, 1, 2, 3;
  directional::validation::MeshValidatorOptions options;
  options.vertexProvenance.resize(5);
  for (int vertex = 0; vertex < 4; ++vertex) {
    options.vertexProvenance[static_cast<std::size_t>(vertex)].face = 0;
  }
  options.vertexProvenance[4].face = 1;

  const auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces,
                                                                    options);

  EXPECT_TRUE(result.accepted);
}

TEST(SurfaceCellsPhase10,
     MeshValidatorFailsClosedWhenRequiredAuthorityIsMissing) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 0.0;
  Eigen::MatrixXi faces(1, 4);
  faces << 0, 1, 2, 3;

  directional::validation::MeshValidatorOptions options;
  options.requireVertexProvenanceForGeometry = true;
  auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces,
                                                                    options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::MissingProvenance));

  options = {};
  options.requireAuthoritativeBoundary = true;
  result = directional::validation::MeshValidator::validate_surface_mesh(
      vertices, faces, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(
      has_code(result, MeshValidationFailureCode::MissingBoundaryAuthority));

  result = directional::validation::MeshValidator::validate_topology_only(
      vertices, faces);
  EXPECT_TRUE(result.accepted);
}

TEST(SurfaceCellsPhase10,
     MeshValidatorUsesComponentSheetInsteadOfExactFaceEquality) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 2.0, 1.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 0.0, 0.0;
  Eigen::MatrixXi faces(1, 4);
  faces << 0, 1, 2, 3;
  directional::validation::MeshValidatorOptions options;
  options.requireVertexProvenanceForGeometry = true;
  options.vertexProvenance.resize(5);
  options.vertexProvenance[0].face = 0;
  options.vertexProvenance[1].face = 0;
  options.vertexProvenance[4].face = 1;
  for (auto &point : options.vertexProvenance) {
    point.component = 7;
    point.sheet = 3;
  }

  const auto result =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces,
                                                                    options);

  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(
      has_code(result, MeshValidationFailureCode::GeometricVertexOnUnsplitEdge));
}

TEST(SurfaceCellsPhase10,
     PointSampledCrossFieldIsInvariantToNinetyDegreeRelabeling) {
  const directional::TriMesh mesh = make_square_mesh();
  std::vector<directional::fields::PointCrossFieldSample> samples = {
      {Eigen::Vector3d(0.75, 0.25, 0.0), Eigen::Vector3d::UnitX(), 1.0,
       0},
      {Eigen::Vector3d(0.25, 0.75, 0.0), Eigen::Vector3d::UnitY(), 1.0,
       1}};

  const auto projected =
      directional::fields::project_point_sampled_cross_field(mesh, samples);

  ASSERT_EQ(projected.field.rawField.rows(), mesh.F.rows());
  EXPECT_GT(projected.faceConfidence(0), 0.99);
  const Eigen::RowVector3d primary = projected.field.rawField.block(0, 0, 1, 3);
  EXPECT_NEAR(std::abs(primary.dot(Eigen::RowVector3d(1, 0, 0))), 1.0,
              1.0e-10);
}

TEST(SurfaceCellsPhase10,
     PointSampledCrossFieldComputesMatchingEffortAndSingularityStorage) {
  const directional::TriMesh mesh = make_square_mesh();
  const Eigen::Vector3d tilted(std::cos(0.25), std::sin(0.25), 0.0);
  std::vector<directional::fields::PointCrossFieldSample> samples = {
      {Eigen::Vector3d(0.75, 0.25, 0.0), Eigen::Vector3d::UnitX(), 1.0, 0},
      {Eigen::Vector3d(0.25, 0.75, 0.0), tilted, 1.0, 1}};
  directional::fields::PointSampledCrossFieldOptions options;
  options.combDirections = false;

  const auto projected =
      directional::fields::project_point_sampled_cross_field(mesh, samples,
                                                             options);

  ASSERT_EQ(projected.field.matching.size(), mesh.EV.rows());
  ASSERT_EQ(projected.field.effort.size(), mesh.EV.rows());
  EXPECT_FALSE((projected.field.matching.array() == 0).all());
  EXPECT_GT(projected.field.effort.cwiseAbs().sum(), 1.0e-8);
  EXPECT_EQ(projected.field.singularCycles.size(),
            projected.field.singularIndices.size());
}

TEST(SurfaceCellsPhase10, SurfaceProjectionRecordsFaceAndBarycentricPoint) {
  const directional::TriMesh mesh = make_two_sheet_mesh();

  const directional::geometry::SurfacePoint projected =
      directional::geometry::project_to_surface(
          mesh.V, mesh.F, Eigen::Vector3d(0.25, 0.25, 0.0001));

  ASSERT_TRUE(projected.valid());
  EXPECT_EQ(projected.face, 0);
  EXPECT_NEAR(projected.barycentric.sum(), 1.0, 1.0e-12);
  EXPECT_NEAR(projected.position.z(), 0.0, 1.0e-12);
}

TEST(SurfaceCellsPhase10,
     PointSampledConstantPlanarFieldHasTinyDegreeFourComplexError) {
  const directional::TriMesh mesh = make_square_mesh();
  std::vector<directional::fields::PointCrossFieldSample> samples = {
      {Eigen::Vector3d(0.75, 0.25, 0.0), Eigen::Vector3d::UnitX(), 1.0,
       0},
      {Eigen::Vector3d(0.25, 0.75, 0.0), Eigen::Vector3d::UnitX(), 1.0,
       1}};

  const auto projected =
      directional::fields::project_point_sampled_cross_field(mesh, samples);

  const Eigen::RowVector3d primary = projected.field.rawField.block(0, 0, 1, 3);
  const std::complex<double> z(primary.dot(mesh.FBx.row(0)),
                               primary.dot(mesh.FBy.row(0)));
  EXPECT_NEAR(std::abs(std::pow(z, directional::fields::kCrossFieldDegree) -
                       std::complex<double>(1.0, 0.0)),
              0.0, 1.0e-10);
}

TEST(SurfaceCellsPhase10,
     PointSampledCrossFieldReportsConfidenceCancellationAndUncoveredFaces) {
  const directional::TriMesh mesh = make_square_mesh();
  std::vector<directional::fields::PointCrossFieldSample> samples = {
      {Eigen::Vector3d(0.75, 0.25, 0.0), Eigen::Vector3d::UnitX(), 1.0,
       0},
      {Eigen::Vector3d(0.25, 0.25, 0.0),
       Eigen::Vector3d(std::sqrt(0.5), std::sqrt(0.5), 0.0), 1.0, 0}};

  EXPECT_THROW(
      (void)directional::fields::project_point_sampled_cross_field(mesh,
                                                                   samples),
      std::runtime_error);
}

TEST(SurfaceCellsPhase10, PointSampledCrossFieldDoesNotLeakToCloseSheet) {
  const directional::TriMesh mesh = make_two_sheet_mesh();
  std::vector<directional::fields::PointCrossFieldSample> samples = {
      {Eigen::Vector3d(0.25, 0.25, 0.0008), Eigen::Vector3d::UnitX(), 1.0,
       -1, 0, 0},
      {Eigen::Vector3d(0.25, 0.25, 0.001), Eigen::Vector3d::UnitY(), 1.0,
       -1, 1, 1}};
  const auto options = two_sheet_projection_options();

  const auto projected = directional::fields::project_point_sampled_cross_field(
      mesh, samples, options);

  EXPECT_GT(projected.faceConfidence(0), 0.99);
  EXPECT_GT(projected.faceConfidence(2), 0.99);
  ASSERT_EQ(projected.sampleProvenance.size(), 2U);
  EXPECT_EQ(projected.sampleProvenance.front().face, 0);
  EXPECT_EQ(projected.sampleProvenance.front().component, 0);
}

TEST(SurfaceCellsPhase10,
     PointSampledCrossFieldExplicitlyPropagatesWithinComponent) {
  const directional::TriMesh mesh = make_two_sheet_mesh();
  std::vector<directional::fields::PointCrossFieldSample> samples = {
      {Eigen::Vector3d(0.25, 0.25, 0.0), Eigen::Vector3d::UnitX(), 1.0, -1,
       0, 0},
      {Eigen::Vector3d(0.25, 0.25, 0.001), Eigen::Vector3d::UnitY(), 1.0,
       -1, 1, 1}};

  const auto projected = directional::fields::project_point_sampled_cross_field(
      mesh, samples, two_sheet_projection_options());

  EXPECT_GT(projected.faceConfidence(1), 0.99);
  EXPECT_GT(projected.faceConfidence(3), 0.99);
}

TEST(SurfaceCellsPhase10, SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture) {
  directional::pipeline::RemeshOptions options;
  EXPECT_EQ(options.backend, directional::pipeline::RemeshBackend::Legacy);
  EXPECT_FALSE(options.surfaceCells.enabled);
  EXPECT_FALSE(options.surfaceCells.allowSourceGridRecovery);

  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
      0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  Eigen::MatrixXd raw(2, 12);
  raw << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0,
      0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0,
      0.0;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.lengthRatio = 0.2;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      vertices, faces, raw, options);

  EXPECT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ(result.diagnostics.surfaceCellValidationFailures, 0U);
  EXPECT_FALSE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_GT(result.faces.rows(), 0);
  ASSERT_EQ(result.degrees.size(), result.faces.rows());
  EXPECT_TRUE((result.degrees.array() == 4).all());
  EXPECT_GE(result.diagnostics.surfaceCellFeatureSeconds, 0.0);
  EXPECT_GT(result.diagnostics.adaptiveFeatureBoundaryEdgeCount, 0U);
  EXPECT_GT(result.diagnostics.adaptiveFeatureCurveCount, 0U);
}

TEST(SurfaceCellsPhase10, StrictValidatorAcceptsLegacySyntheticOutput) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
      0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  std::vector<directional::pipeline::RemeshOptions> variants;
  variants.push_back({});
  variants.back().lengthRatio = 0.2;
  variants.back().integralSeamless = false;
  variants.back().roundSeams = false;
  variants.push_back(variants.front());
  variants.back().useFunctionSkeletonCleanup = false;
  variants.push_back(variants.front());
  variants.back().preconditionInputMesh = true;
  variants.push_back(variants.front());
  variants.back().parallelizeComponents = true;
  variants.back().maxComponentThreads = 2;

  for (const auto &options : variants) {
    const auto result =
        directional::pipeline::remesh_from_mesh(vertices, faces, options);
    ASSERT_TRUE(result.success);

    const auto validation =
        directional::validation::MeshValidator::validate_surface_mesh(
            result.vertices, result.faces);

    EXPECT_TRUE(validation.accepted);
  }
}

TEST(SurfaceCellsPhase10, StrictValidatorOverheadStaysBelowFivePercent) {
  const auto remeshStart = std::chrono::steady_clock::now();
  const auto result = run_phase10_tiny_remesh();
  const auto remeshEnd = std::chrono::steady_clock::now();
  ASSERT_TRUE(result.success);

  const auto validationStart = std::chrono::steady_clock::now();
  const auto validation =
      directional::validation::MeshValidator::validate_surface_mesh(
          result.vertices, result.faces);
  const auto validationEnd = std::chrono::steady_clock::now();
  ASSERT_TRUE(validation.accepted);

  const double remeshSeconds =
      std::chrono::duration<double>(remeshEnd - remeshStart).count();
  const double validationSeconds =
      std::chrono::duration<double>(validationEnd - validationStart).count();
  EXPECT_LT(validationSeconds, remeshSeconds * 0.05);
}

TEST(SurfaceCellsPhase10, LegacySyntheticOutputHashIsStableAcrossTenRuns) {
  const auto first = run_phase10_tiny_remesh();
  ASSERT_TRUE(first.success);
  const std::uint64_t vertexHash = hash_matrix(first.vertices);
  const std::uint64_t faceHash = hash_matrix(first.faces);

  for (int run = 1; run < 10; ++run) {
    const auto next = run_phase10_tiny_remesh();
    ASSERT_TRUE(next.success);
    EXPECT_EQ(hash_matrix(next.vertices), vertexHash);
    EXPECT_EQ(hash_matrix(next.faces), faceHash);
  }
}


directional::TriMesh make_vertex_fan_plane_mesh(bool reverseFaces = false) {
  constexpr int columns = 5;
  constexpr int rows = 4;
  Eigen::MatrixXd vertices(columns * rows, 3);
  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < columns; ++x) {
      const int vertex = y * columns + x;
      vertices.row(vertex) << static_cast<double>(x) / 4.0,
          static_cast<double>(y) / 3.0, 0.0;
    }
  }
  Eigen::MatrixXi faces(2 * (columns - 1) * (rows - 1), 3);
  int face = 0;
  for (int y = 0; y + 1 < rows; ++y) {
    for (int x = 0; x + 1 < columns; ++x) {
      const int v00 = y * columns + x;
      const int v10 = v00 + 1;
      const int v01 = v00 + columns;
      const int v11 = v01 + 1;
      faces.row(face++) << v00, v10, v11;
      faces.row(face++) << v00, v11, v01;
    }
  }
  if (reverseFaces) {
    Eigen::MatrixXi reversed = faces.colwise().reverse().eval();
    faces = reversed;
  }
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

Eigen::MatrixXd constant_xy_raw_field(const int faceCount) {
  Eigen::MatrixXd field(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    field.row(face) << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0,
        0.0, 0.0, -1.0, 0.0;
  }
  return field;
}

Eigen::MatrixXd read_rawfield_fixture(
    const std::filesystem::path &path, const int expectedFaces) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open rawfield fixture: " +
                             path.string());
  }
  int degree = 0;
  int faceCount = 0;
  if (!(stream >> degree >> faceCount) || degree != 4 ||
      faceCount != expectedFaces) {
    throw std::runtime_error("Invalid rawfield fixture header: " +
                             path.string());
  }
  Eigen::MatrixXd field(faceCount, 3 * degree);
  for (int face = 0; face < faceCount; ++face) {
    for (int column = 0; column < field.cols(); ++column) {
      if (!(stream >> field(face, column))) {
        throw std::runtime_error("Invalid rawfield fixture payload: " +
                                 path.string());
      }
    }
  }
  return field;
}

std::set<std::uint64_t> interior_source_edges(
    const directional::TriMesh &mesh) {
  std::set<std::uint64_t> edges;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (mesh.EF(edge, 0) < 0 || mesh.EF(edge, 1) < 0) {
      continue;
    }
    edges.insert(directional::pipeline::surface_cell_source_edge_key(
        mesh.EV(edge, 0), mesh.EV(edge, 1)));
  }
  return edges;
}

std::size_t multi_edge_transition_count(
    const directional::geometry::SurfaceCellNetwork &network) {
  std::size_t count = 0;
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        if (segment.transitionSourceEdges.size() > 1U) {
          ++count;
        }
      }
    }
  }
  return count;
}

TEST(SurfaceCellsPhase10,
     UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  ASSERT_TRUE(network.phaseFront.succeeded)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  EXPECT_EQ(8, network.phaseFront.gridU);
  EXPECT_EQ(8, network.phaseFront.gridV);
  EXPECT_EQ(64U, network.phaseFront.cells.size());
  EXPECT_GT(multi_edge_transition_count(network), 0U);
  for (const auto &cell : network.phaseFront.cells) {
    EXPECT_TRUE(cell.orientationValidated);
    for (const auto &path : cell.boundaryPaths) {
      ASSERT_FALSE(path.empty());
      for (const auto &segment : path) {
        if (!segment.transitionSourceEdges.empty()) {
          EXPECT_EQ(segment.transitionSourceEdge,
                    segment.transitionSourceEdges.back());
        }
      }
    }
  }
}

TEST(SurfaceCellsPhase10,
     UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering) {
  const directional::TriMesh forwardMesh = make_vertex_fan_plane_mesh(false);
  const directional::TriMesh reverseMesh = make_vertex_fan_plane_mesh(true);
  const auto forwardField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          forwardMesh, constant_xy_raw_field(forwardMesh.F.rows()));
  const auto reverseField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reverseMesh, constant_xy_raw_field(reverseMesh.F.rows()));
  Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(forwardMesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions forwardOptions;
  forwardOptions.sourceFaceComponents.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  forwardOptions.sourceFaceSheets.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  directional::geometry::SurfaceCellTracingOptions reverseOptions =
      forwardOptions;

  const auto forward = directional::geometry::build_surface_cell_network(
      forwardMesh.V, forwardMesh.F, forwardField, targetSize, forwardOptions);
  const auto reverse = directional::geometry::build_surface_cell_network(
      reverseMesh.V, reverseMesh.F, reverseField, targetSize, reverseOptions);

  ASSERT_TRUE(forward.phaseFront.succeeded);
  ASSERT_TRUE(reverse.phaseFront.succeeded);
  EXPECT_EQ(forward.phaseFront.cells.size(), reverse.phaseFront.cells.size());
  EXPECT_EQ(forward.phaseFront.edges.size(), reverse.phaseFront.edges.size());
  EXPECT_EQ(multi_edge_transition_count(forward),
            multi_edge_transition_count(reverse));
}

TEST(SurfaceCellsPhase10,
     UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, constant_xy_raw_field(mesh.F.rows()));
  ASSERT_FALSE(crossField.edgeTransitions.empty());
  crossField.edgeTransitions.push_back(crossField.edgeTransitions.front());
  Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  EXPECT_FALSE(network.phaseFront.succeeded);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                DuplicateTransitionMetadata,
            network.phaseFront.failure.reason);
  EXPECT_TRUE(network.seeds.empty());
  EXPECT_TRUE(network.traces.empty());
  EXPECT_TRUE(network.proposals.empty());
}

TEST(SurfaceCellsPhase10,
     UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions guidanceOptions;
  guidanceOptions.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  guidanceOptions.sourceFaceSheets.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  guidanceOptions.reliefBarrierEdges = interior_source_edges(mesh);
  ASSERT_FALSE(guidanceOptions.reliefBarrierEdges.empty());
  guidanceOptions.reliefBarriersEmbedded = false;

  const auto guidance = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, guidanceOptions);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            guidance.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             guidance.phaseFront.failure.reason);
  EXPECT_TRUE(guidance.phaseFront.succeeded);

  auto embeddedOptions = guidanceOptions;
  embeddedOptions.reliefBarriersEmbedded = true;
  const auto embedded = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, embeddedOptions);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            embedded.phaseFront.disposition);
  EXPECT_FALSE(embedded.phaseFront.succeeded);
  EXPECT_TRUE(embedded.seeds.empty());
  EXPECT_TRUE(embedded.traces.empty());
  EXPECT_TRUE(embedded.proposals.empty());
}

TEST(SurfaceCellsPhase10,
     UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/close_sheets.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/close_sheets.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField =
      read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, rawField);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.resize(static_cast<std::size_t>(mesh.F.rows()));
  options.sourceFaceSheets.resize(static_cast<std::size_t>(mesh.F.rows()));
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const int component = mesh.F(face, 0) < 16 ? 0 : 1;
    options.sourceFaceComponents[static_cast<std::size_t>(face)] = component;
    options.sourceFaceSheets[static_cast<std::size_t>(face)] = component;
  }

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  ASSERT_TRUE(network.phaseFront.succeeded);
  EXPECT_EQ(128U, network.phaseFront.cells.size());
  std::set<std::pair<int, int>> sheetKeys;
  for (const auto &cell : network.phaseFront.cells) {
    sheetKeys.emplace(cell.sourceComponent, cell.sourceSheet);
  }
  EXPECT_EQ((std::set<std::pair<int, int>>{{0, 0}, {1, 1}}), sheetKeys);
  for (const auto &edge : network.phaseFront.edges) {
    if (edge.oppositeEdge < 0) {
      continue;
    }
    ASSERT_LT(edge.oppositeEdge,
              static_cast<int>(network.phaseFront.edges.size()));
    const auto &opposite = network.phaseFront.edges[
        static_cast<std::size_t>(edge.oppositeEdge)];
    EXPECT_EQ(edge.sourceComponent, opposite.sourceComponent);
    EXPECT_EQ(edge.sourceSheet, opposite.sourceSheet);
  }
}

TEST(SurfaceCellsPhase10,
     UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/close_sheets.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/close_sheets.rawfield");
  directional::TriMesh forwardMesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), forwardMesh));
  const Eigen::MatrixXd forwardRaw =
      read_rawfield_fixture(fieldPath, forwardMesh.F.rows());

  Eigen::MatrixXi reversedFaces = forwardMesh.F.colwise().reverse().eval();
  Eigen::MatrixXd reversedRaw = forwardRaw.colwise().reverse().eval();
  directional::TriMesh reverseMesh;
  reverseMesh.set_mesh(forwardMesh.V, reversedFaces);

  const auto build = [](const directional::TriMesh &mesh,
                        const Eigen::MatrixXd &rawField) {
    const auto crossField =
        directional::pipeline::finalize_surface_cell_raw_cross_field(
            mesh, rawField);
    const Eigen::VectorXd targetSize =
        Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
    directional::geometry::SurfaceCellTracingOptions options;
    options.sourceFaceComponents.resize(
        static_cast<std::size_t>(mesh.F.rows()));
    options.sourceFaceSheets.resize(static_cast<std::size_t>(mesh.F.rows()));
    for (int face = 0; face < mesh.F.rows(); ++face) {
      const int component = mesh.F(face, 0) < 16 ? 0 : 1;
      options.sourceFaceComponents[static_cast<std::size_t>(face)] = component;
      options.sourceFaceSheets[static_cast<std::size_t>(face)] = component;
    }
    return directional::geometry::build_surface_cell_network(
        mesh.V, mesh.F, crossField, targetSize, options);
  };

  const auto forward = build(forwardMesh, forwardRaw);
  const auto reverse = build(reverseMesh, reversedRaw);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition);
  EXPECT_EQ(forward.phaseFront.cells.size(), reverse.phaseFront.cells.size());
  EXPECT_EQ(forward.phaseFront.edges.size(), reverse.phaseFront.edges.size());
  EXPECT_EQ(forward.phaseFront.events.size(), reverse.phaseFront.events.size());
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontDerivesAnnulusFromSourceTopology) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, rawField);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  ASSERT_TRUE(!network.phaseFront.periodicHolonomies.empty());
  EXPECT_EQ(0, network.phaseFront.periodicHolonomies.front().quarterTurnRotation);
  EXPECT_EQ(network.phaseFront.gridU,
            network.phaseFront.periodicHolonomies.front().latticeTranslation.x());
  EXPECT_EQ(0, network.phaseFront.periodicHolonomies.front().latticeTranslation.y());
  EXPECT_GT(network.phaseFront.gridU, 2);
  EXPECT_GT(network.phaseFront.gridV, 0);
  EXPECT_EQ(static_cast<std::size_t>(network.phaseFront.gridU *
                                     network.phaseFront.gridV),
            network.phaseFront.cells.size());
  EXPECT_FALSE(network.phaseFront.periodicHolonomies.front().sourceRouteEdges.empty());
  EXPECT_FALSE(network.phaseFront.periodicHolonomies.front().cutSourceEdges.empty());
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh forwardMesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), forwardMesh));
  const Eigen::MatrixXd forwardRaw =
      read_rawfield_fixture(fieldPath, forwardMesh.F.rows());
  Eigen::MatrixXi reversedFaces = forwardMesh.F.colwise().reverse().eval();
  Eigen::MatrixXd reversedRaw = forwardRaw.colwise().reverse().eval();
  directional::TriMesh reverseMesh;
  reverseMesh.set_mesh(forwardMesh.V, reversedFaces);

  const auto build = [](const directional::TriMesh &mesh,
                        const Eigen::MatrixXd &rawField) {
    const auto crossField =
        directional::pipeline::finalize_surface_cell_raw_cross_field(mesh,
                                                                      rawField);
    const Eigen::VectorXd targetSize =
        Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
    directional::geometry::SurfaceCellTracingOptions options;
    options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
    options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
    return directional::geometry::build_surface_cell_network(
        mesh.V, mesh.F, crossField, targetSize, options);
  };

  const auto forward = build(forwardMesh, forwardRaw);
  const auto reverse = build(reverseMesh, reversedRaw);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition);
  EXPECT_EQ(forward.phaseFront.gridU, reverse.phaseFront.gridU);
  EXPECT_EQ(forward.phaseFront.gridV, reverse.phaseFront.gridV);
  EXPECT_EQ(forward.phaseFront.periodicHolonomies.front().quarterTurnRotation,
            reverse.phaseFront.periodicHolonomies.front().quarterTurnRotation);
  EXPECT_EQ(forward.phaseFront.periodicHolonomies.front().latticeTranslation,
            reverse.phaseFront.periodicHolonomies.front().latticeTranslation);
  const auto canonicalEdgeRoute = [](
      const directional::TriMesh &mesh, const std::vector<int> &sourceEdges) {
    std::vector<std::pair<int, int>> route;
    route.reserve(sourceEdges.size());
    for (const int sourceEdge : sourceEdges) {
      if (sourceEdge < 0 || sourceEdge >= mesh.EV.rows()) {
        return std::vector<std::pair<int, int>>{};
      }
      route.emplace_back(
          std::min(mesh.EV(sourceEdge, 0), mesh.EV(sourceEdge, 1)),
          std::max(mesh.EV(sourceEdge, 0), mesh.EV(sourceEdge, 1)));
    }
    return route;
  };
  const auto forwardRoute = canonicalEdgeRoute(
      forwardMesh, forward.phaseFront.periodicHolonomies.front().sourceRouteEdges);
  const auto reverseRoute = canonicalEdgeRoute(
      reverseMesh, reverse.phaseFront.periodicHolonomies.front().sourceRouteEdges);
  const auto forwardCut = canonicalEdgeRoute(
      forwardMesh, forward.phaseFront.periodicHolonomies.front().cutSourceEdges);
  const auto reverseCut = canonicalEdgeRoute(
      reverseMesh, reverse.phaseFront.periodicHolonomies.front().cutSourceEdges);
  ASSERT_EQ(forward.phaseFront.periodicHolonomies.front().sourceRouteEdges.size(),
            forwardRoute.size());
  ASSERT_EQ(reverse.phaseFront.periodicHolonomies.front().sourceRouteEdges.size(),
            reverseRoute.size());
  ASSERT_EQ(forward.phaseFront.periodicHolonomies.front().cutSourceEdges.size(),
            forwardCut.size());
  ASSERT_EQ(reverse.phaseFront.periodicHolonomies.front().cutSourceEdges.size(),
            reverseCut.size());
  EXPECT_EQ(forwardRoute, reverseRoute);
  EXPECT_EQ(forwardCut, reverseCut);
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, rawField);
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition);

  std::set<int> sourceBoundaryVertices;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (mesh.EF(edge, 0) >= 0 && mesh.EF(edge, 1) >= 0) {
      continue;
    }
    sourceBoundaryVertices.insert(mesh.EV(edge, 0));
    sourceBoundaryVertices.insert(mesh.EV(edge, 1));
  }
  ASSERT_FALSE(sourceBoundaryVertices.empty());

  std::set<int> phaseBoundaryVertices;
  for (const auto &cell : network.phaseFront.cells) {
    for (int corner = 0; corner < 4; ++corner) {
      const auto &state = cell.lattice[static_cast<std::size_t>(corner)];
      if (state.latticeCoordinate.y() != 0 &&
          state.latticeCoordinate.y() != network.phaseFront.gridV) {
        continue;
      }
      const auto &point = cell.corners[static_cast<std::size_t>(corner)];
      ASSERT_GE(point.face, 0);
      ASSERT_LT(point.face, mesh.F.rows());
      int sourceCorner = -1;
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        if (std::abs(point.barycentric[coordinate] - 1.0) <= 1.0e-10) {
          sourceCorner = coordinate;
          break;
        }
      }
      if (sourceCorner >= 0) {
        phaseBoundaryVertices.insert(mesh.F(point.face, sourceCorner));
      }
    }
  }
  EXPECT_EQ(sourceBoundaryVertices, phaseBoundaryVertices);
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, rawField);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);

  const auto segmentPoint = [&mesh](
      const directional::geometry::SurfaceTraceSegment &segment,
      const bool end) -> Eigen::RowVector3d {
    const Eigen::RowVector3d barycentric =
        end ? segment.endBarycentric : segment.startBarycentric;
    Eigen::RowVector3d point = Eigen::RowVector3d::Zero();
    for (int coordinate = 0; coordinate < 3; ++coordinate) {
      point += barycentric[coordinate] *
               Eigen::RowVector3d(mesh.V.row(mesh.F(segment.face, coordinate)));
    }
    return point;
  };

  int exactSourceVertexEndpoints = 0;
  for (const auto &cell : network.phaseFront.cells) {
    for (int side = 0; side < 4; ++side) {
      const auto &path = cell.boundaryPaths[static_cast<std::size_t>(side)];
      ASSERT_FALSE(path.empty());
      for (const auto &segment : path) {
        ASSERT_GE(segment.face, 0);
        ASSERT_LT(segment.face, mesh.F.rows());
        const std::array<Eigen::RowVector3d, 2> endpointBarycentrics{
            segment.startBarycentric, segment.endBarycentric};
        for (const Eigen::RowVector3d &barycentric : endpointBarycentrics) {
          EXPECT_TRUE(barycentric.allFinite());
          EXPECT_NEAR(1.0, barycentric.sum(), 1.0e-14);
          for (int coordinate = 0; coordinate < 3; ++coordinate) {
            EXPECT_GE(barycentric[coordinate], 0.0);
            EXPECT_LE(barycentric[coordinate], 1.0);
          }
          int dominant = -1;
          for (int coordinate = 0; coordinate < 3; ++coordinate) {
            if (barycentric[coordinate] >= 1.0 - 1.0e-10) {
              dominant = coordinate;
              break;
            }
          }
          if (dominant >= 0) {
            EXPECT_DOUBLE_EQ(1.0, barycentric[dominant]);
            for (int coordinate = 0; coordinate < 3; ++coordinate) {
              if (coordinate != dominant) {
                EXPECT_DOUBLE_EQ(0.0, barycentric[coordinate]);
              }
            }
            ++exactSourceVertexEndpoints;
          }
        }
        EXPECT_GT((segmentPoint(segment, true) - segmentPoint(segment, false)).norm(),
                  1.0e-14)
            << "tolerance-only periodic chart segments must not be emitted";
      }

      const auto &next =
          cell.boundaryPaths[static_cast<std::size_t>((side + 1) % 4)];
      ASSERT_FALSE(next.empty());
      EXPECT_NEAR(0.0,
                  (segmentPoint(path.back(), true) -
                   segmentPoint(next.front(), false))
                      .norm(),
                  1.0e-12)
          << "adjacent periodic sides must share the exact source breakpoint";
    }
    EXPECT_EQ(directional::geometry::CellRejectionReason::Accepted,
              directional::geometry::surface_cell_tracing_detail::
                  validate_closed_boundary_paths(mesh.V, mesh.F, cell.corners,
                                                 cell.boundaryPaths, 1.0e-7));
  }
  EXPECT_GT(exactSourceVertexEndpoints, 0);
}

TEST(SurfaceCellsPhase10,
     PeriodicChartEndpointCanonicalizationKeepsGenuineOverlapRejected) {
  using directional::geometry::surface_cell_tracing_detail::
      segments_intersect_beyond_shared_endpoint_2d;
  const Eigen::Vector2d a(0.0, 0.0);
  const Eigen::Vector2d b(1.0, 0.0);
  const Eigen::Vector2d c(1.0, 0.0);
  const Eigen::Vector2d d(2.0, 0.0);
  const Eigen::Vector2d overlap(0.5, 0.0);

  EXPECT_FALSE(segments_intersect_beyond_shared_endpoint_2d(a, b, c, d));
  EXPECT_TRUE(segments_intersect_beyond_shared_endpoint_2d(a, b, c, overlap));
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, rawField);
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  directional::geometry::cross_field_axes(crossField, faceAxisX, faceAxisY);
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);

  const auto faceNormal = [&](const int face) -> Eigen::RowVector3d {
    const Eigen::RowVector3d edge01 =
        mesh.V.row(mesh.F(face, 1)) - mesh.V.row(mesh.F(face, 0));
    const Eigen::RowVector3d edge02 =
        mesh.V.row(mesh.F(face, 2)) - mesh.V.row(mesh.F(face, 0));
    Eigen::RowVector3d normal = edge01.cross(edge02);
    const double norm = normal.norm();
    if (norm > 0.0) return Eigen::RowVector3d(normal / norm);
    return Eigen::RowVector3d(0.0, 0.0, 0.0);
  };
  const auto tangent = [&](Eigen::RowVector3d direction,
                           const int face) -> Eigen::RowVector3d {
    const Eigen::RowVector3d normal = faceNormal(face);
    direction -= direction.dot(normal) * normal;
    const double norm = direction.norm();
    if (norm > 0.0) return Eigen::RowVector3d(direction / norm);
    return Eigen::RowVector3d(0.0, 0.0, 0.0);
  };
  const auto segmentPoint = [&mesh](
      const directional::geometry::SurfaceTraceSegment &segment,
      const Eigen::RowVector3d &barycentric) -> Eigen::RowVector3d {
    Eigen::RowVector3d point = Eigen::RowVector3d::Zero();
    for (int coordinate = 0; coordinate < 3; ++coordinate) {
      point += barycentric[coordinate] *
          Eigen::RowVector3d(mesh.V.row(mesh.F(segment.face, coordinate)));
    }
    return point;
  };

  int observedVSegments = 0;
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        if (segment.family != 1) continue;
        ASSERT_GE(segment.face, 0);
        ASSERT_LT(segment.face, mesh.F.rows());
        const Eigen::RowVector3d start = segment.startBarycentric;
        const Eigen::RowVector3d end = segment.endBarycentric;
        ASSERT_TRUE(start.allFinite());
        ASSERT_TRUE(end.allFinite());
        EXPECT_NEAR(1.0, start.sum(), 1.0e-12);
        EXPECT_NEAR(1.0, end.sum(), 1.0e-12);
        for (int coordinate = 0; coordinate < 3; ++coordinate) {
          EXPECT_GE(start[coordinate], -1.0e-12);
          EXPECT_LE(start[coordinate], 1.0 + 1.0e-12);
          EXPECT_GE(end[coordinate], -1.0e-12);
          EXPECT_LE(end[coordinate], 1.0 + 1.0e-12);
        }

        const Eigen::RowVector3d sourceDirection =
            segmentPoint(segment, end) - segmentPoint(segment, start);
        if (sourceDirection.norm() <= 1.0e-14) continue;
        const Eigen::RowVector3d segmentDirection =
            tangent(sourceDirection, segment.face);
        const Eigen::RowVector3d authoritativeV =
            tangent(faceAxisY.row(segment.face), segment.face);
        ASSERT_GT(segmentDirection.squaredNorm(), 0.0);
        ASSERT_GT(authoritativeV.squaredNorm(), 0.0);
        EXPECT_NEAR(1.0, std::abs(segmentDirection.dot(authoritativeV)), 1.0e-10)
            << "source-attached phase-front V path segments must consume the "
               "axial field family independent of target subdivision";
        ++observedVSegments;
      }
    }
  }
  EXPECT_GT(observedVSegments, 0)
      << "field-authoritative correspondence requires a nonempty V-family "
         "source-attached path witness";
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));

  // Every cylinder source triangle contains one same-height ring edge and two
  // upward inter-ring edges: the axial edge and the strip diagonal.  Define a
  // synthetic 4-RoSy whose V family is their exact tangent bisector.  Both
  // topology-compatible ring bijections are then genuinely field-equivalent,
  // so production must reject ambiguity rather than recover the old
  // lexicographic source-vertex tie-break.
  Eigen::MatrixXd faceAxisX(mesh.F.rows(), 3);
  Eigen::MatrixXd faceAxisY(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d p0 = mesh.V.row(mesh.F(face, 0));
    const Eigen::RowVector3d p1 = mesh.V.row(mesh.F(face, 1));
    const Eigen::RowVector3d p2 = mesh.V.row(mesh.F(face, 2));
    Eigen::RowVector3d normal = (p1 - p0).cross(p2 - p0);
    ASSERT_GT(normal.norm(), 0.0);
    normal.normalize();

    std::vector<Eigen::RowVector3d> rising;
    for (const auto &edgeVertices :
         {std::pair<int, int>{mesh.F(face, 0), mesh.F(face, 1)},
          std::pair<int, int>{mesh.F(face, 1), mesh.F(face, 2)},
          std::pair<int, int>{mesh.F(face, 2), mesh.F(face, 0)}}) {
      Eigen::RowVector3d direction =
          mesh.V.row(edgeVertices.second) - mesh.V.row(edgeVertices.first);
      if (std::abs(direction.z()) <= 1.0e-12) continue;
      if (direction.z() < 0.0) direction *= -1.0;
      direction -= direction.dot(normal) * normal;
      ASSERT_GT(direction.norm(), 0.0);
      rising.push_back(direction.normalized());
    }
    ASSERT_EQ(2U, rising.size());
    if (rising[0].dot(rising[1]) < 0.0) rising[1] *= -1.0;
    Eigen::RowVector3d vAxis = rising[0] + rising[1];
    ASSERT_GT(vAxis.norm(), 0.0);
    vAxis.normalize();
    Eigen::RowVector3d uAxis = normal.cross(vAxis);
    ASSERT_GT(uAxis.norm(), 0.0);
    uAxis.normalize();
    faceAxisX.row(face) = uAxis;
    faceAxisY.row(face) = vAxis;
  }

  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, faceAxisX, faceAxisY, targetSize, options);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                AmbiguousPeriodicRingCorrespondence,
            network.phaseFront.failure.reason)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  EXPECT_TRUE(network.seeds.empty());
  EXPECT_TRUE(network.traces.empty());
  EXPECT_TRUE(network.proposals.empty());
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, rawField);
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition);

  int periodicMergeCount = 0;
  for (const auto &event : network.phaseFront.events) {
    if (event.kind == directional::geometry::SurfaceFrontEventKind::PeriodicFrontMerge) {
      ++periodicMergeCount;
    }
  }
  EXPECT_EQ(network.phaseFront.gridV, periodicMergeCount);
  for (const auto &edge : network.phaseFront.edges) {
    const int fromU = edge.fromLattice.latticeCoordinate.x();
    const int toU = edge.toLattice.latticeCoordinate.x();
    const bool cutEdge = edge.family == 1 &&
        ((fromU == 0 && toU == 0) ||
         (fromU == network.phaseFront.gridU &&
          toU == network.phaseFront.gridU));
    if (cutEdge) {
      EXPECT_FALSE(edge.exterior);
      EXPECT_GE(edge.oppositeEdge, 0);
    }
  }
}

struct CurvedDiskFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  Eigen::VectorXd targetSize;
  directional::geometry::SurfaceCellTracingOptions options;
};

CurvedDiskFixture make_curved_disk_fixture(const bool reverseFaceRows = false) {
  CurvedDiskFixture fixture;
  fixture.vertices.resize(9, 3);
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) {
      const int vertex = y * 3 + x;
      const double px = 0.5 * static_cast<double>(x);
      const double py = 0.5 * static_cast<double>(y);
      const double pz = (x == 1 && y == 1) ? 0.22 : 0.0;
      fixture.vertices.row(vertex) << px, py, pz;
    }
  }
  fixture.faces.resize(8, 3);
  int face = 0;
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 2; ++x) {
      const int a = y * 3 + x;
      const int b = a + 1;
      const int c = a + 3;
      const int d = c + 1;
      fixture.faces.row(face++) << a, b, d;
      fixture.faces.row(face++) << a, d, c;
    }
  }
  if (reverseFaceRows) {
    fixture.faces = fixture.faces.colwise().reverse().eval();
  }

  fixture.faceAxisX.resize(fixture.faces.rows(), 3);
  fixture.faceAxisY.resize(fixture.faces.rows(), 3);
  for (int currentFace = 0; currentFace < fixture.faces.rows(); ++currentFace) {
    const Eigen::RowVector3d a =
        fixture.vertices.row(fixture.faces(currentFace, 0));
    const Eigen::RowVector3d b =
        fixture.vertices.row(fixture.faces(currentFace, 1));
    const Eigen::RowVector3d c =
        fixture.vertices.row(fixture.faces(currentFace, 2));
    Eigen::RowVector3d normal = (b - a).cross(c - a);
    normal.normalize();
    Eigen::RowVector3d axisX(1.0, 0.0, 0.0);
    axisX -= axisX.dot(normal) * normal;
    axisX.normalize();
    Eigen::RowVector3d axisY = normal.cross(axisX);
    axisY.normalize();
    fixture.faceAxisX.row(currentFace) = axisX;
    fixture.faceAxisY.row(currentFace) = axisY;
  }
  fixture.targetSize = Eigen::VectorXd::Constant(fixture.vertices.rows(), 0.25);
  fixture.options.sourceFaceComponents.assign(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  fixture.options.sourceFaceSheets.assign(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  const auto add_boundary = [&](const int a, const int b) {
    fixture.options.hardFeatureEdges.insert(
        directional::pipeline::surface_cell_source_edge_key(a, b));
  };
  for (int x = 0; x < 2; ++x) {
    add_boundary(x, x + 1);
    add_boundary(6 + x, 6 + x + 1);
  }
  for (int y = 0; y < 2; ++y) {
    add_boundary(y * 3, (y + 1) * 3);
    add_boundary(y * 3 + 2, (y + 1) * 3 + 2);
  }
  return fixture;
}

Eigen::MatrixXd curved_disk_raw_field(const CurvedDiskFixture &fixture) {
  Eigen::MatrixXd raw(fixture.faces.rows(), 12);
  for (int face = 0; face < fixture.faces.rows(); ++face) {
    const Eigen::RowVector3d x = fixture.faceAxisX.row(face);
    const Eigen::RowVector3d y = fixture.faceAxisY.row(face);
    raw.row(face) << x, y, -x, -y;
  }
  return raw;
}

std::uint64_t curved_disk_phase_front_geometry_hash(
    const CurvedDiskFixture &fixture,
    const directional::geometry::SurfaceCellNetwork &network) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto consume = [&](const long long value, std::uint64_t &state) {
    state ^= static_cast<std::uint64_t>(value);
    state *= 1099511628211ULL;
  };
  for (const auto &cell : network.phaseFront.cells) {
    consume(cell.lattice[0].latticeCoordinate.x(), hash);
    consume(cell.lattice[0].latticeCoordinate.y(), hash);
    for (const auto &corner : cell.corners) {
      const Eigen::RowVector3d position =
          directional::geometry::surface_cell_tracing_detail::point_position(
              fixture.vertices, fixture.faces, corner);
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        consume(static_cast<long long>(
                    std::llround(position[coordinate] * 1.0e12)),
                hash);
      }
    }
  }
  return hash;
}

TEST(SurfaceCellsPhase10, CurvedBoundedDiskPhaseFrontIsStructurallyApplicable) {
  const CurvedDiskFixture fixture = make_curved_disk_fixture();
  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.targetSize, fixture.options);

  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::
                UnsupportedSourceSheetTopology,
            network.phaseFront.failure.reason);
  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::NonPlanarSource,
            network.phaseFront.failure.reason);
  if (network.phaseFront.disposition ==
      directional::geometry::SurfaceCellProducerDisposition::Rejected) {
    EXPECT_TRUE(
        network.phaseFront.failure.reason ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskTransport ||
        network.phaseFront.failure.reason ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskBoundaryPhase ||
        network.phaseFront.failure.reason ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskChart ||
        network.phaseFront.failure.reason ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskFrontPairing)
        << directional::geometry::surface_phase_front_failure_reason_name(
               network.phaseFront.failure.reason);
  } else {
    EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
              network.phaseFront.disposition);
    EXPECT_TRUE(network.phaseFront.succeeded);
    EXPECT_FALSE(network.phaseFront.cells.empty());
  }
}

TEST(SurfaceCellsPhase10, CurvedBoundedDiskIsInvariantToFaceRowEnumeration) {
  const CurvedDiskFixture forward = make_curved_disk_fixture(false);
  const CurvedDiskFixture reversed = make_curved_disk_fixture(true);
  const auto forwardNetwork = directional::geometry::build_surface_cell_network(
      forward.vertices, forward.faces, forward.faceAxisX, forward.faceAxisY,
      forward.targetSize, forward.options);
  const auto reversedNetwork = directional::geometry::build_surface_cell_network(
      reversed.vertices, reversed.faces, reversed.faceAxisX, reversed.faceAxisY,
      reversed.targetSize, reversed.options);

  EXPECT_EQ(forwardNetwork.phaseFront.disposition,
            reversedNetwork.phaseFront.disposition);
  EXPECT_EQ(forwardNetwork.phaseFront.failure.reason,
            reversedNetwork.phaseFront.failure.reason);
  EXPECT_EQ(forwardNetwork.phaseFront.gridU, reversedNetwork.phaseFront.gridU);
  EXPECT_EQ(forwardNetwork.phaseFront.gridV, reversedNetwork.phaseFront.gridV);
  EXPECT_EQ(forwardNetwork.phaseFront.cells.size(),
            reversedNetwork.phaseFront.cells.size());
  if (forwardNetwork.phaseFront.disposition ==
      directional::geometry::SurfaceCellProducerDisposition::Produced) {
    EXPECT_EQ(curved_disk_phase_front_geometry_hash(forward, forwardNetwork),
              curved_disk_phase_front_geometry_hash(reversed, reversedNetwork));
  }
}

TEST(SurfaceCellsPhase10, CurvedBoundedDiskPreservesAuthoritativeHardBoundary) {
  const CurvedDiskFixture fixture = make_curved_disk_fixture();
  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.targetSize, fixture.options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);

  std::size_t exteriorCount = 0;
  for (const auto &edge : network.phaseFront.edges) {
    if (!edge.exterior) continue;
    ++exteriorCount;
    ASSERT_GE(edge.filledCell, 0);
    ASSERT_LT(edge.filledCell,
              static_cast<int>(network.phaseFront.cells.size()));
    const auto &cell =
        network.phaseFront.cells[static_cast<std::size_t>(edge.filledCell)];
    bool matchedSide = false;
    for (int side = 0; side < 4; ++side) {
      if (cell.lattice[static_cast<std::size_t>(side)].latticeCoordinate !=
              edge.fromLattice.latticeCoordinate ||
          cell.lattice[static_cast<std::size_t>((side + 1) % 4)]
                  .latticeCoordinate != edge.toLattice.latticeCoordinate) {
        continue;
      }
      matchedSide = true;
      for (const auto &segment :
           cell.boundaryPaths[static_cast<std::size_t>(side)]) {
        bool onHardBoundary = false;
        for (int corner = 0; corner < 3; ++corner) {
          if (std::abs(segment.startBarycentric[corner]) <= 1.0e-9 &&
              std::abs(segment.endBarycentric[corner]) <= 1.0e-9) {
            const int a = fixture.faces(segment.face, (corner + 1) % 3);
            const int b = fixture.faces(segment.face, (corner + 2) % 3);
            onHardBoundary =
                fixture.options.hardFeatureEdges.count(
                    directional::pipeline::surface_cell_source_edge_key(a, b)) !=
                0U;
          }
        }
        EXPECT_TRUE(onHardBoundary);
      }
      break;
    }
    EXPECT_TRUE(matchedSide);
  }
  EXPECT_GT(exteriorCount, 0U);
}

TEST(SurfaceCellsPhase10, CurvedBoundedDiskInvalidReciprocalTransportFailsClosed) {
  const CurvedDiskFixture fixture = make_curved_disk_fixture();
  directional::TriMesh mesh;
  mesh.set_mesh(fixture.vertices, fixture.faces);
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, curved_disk_raw_field(fixture));
  ASSERT_FALSE(crossField.edgeTransitions.empty());
  auto transition = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [&](const auto &candidate) {
        return candidate.firstFace >= 0 && candidate.secondFace >= 0;
      });
  ASSERT_NE(crossField.edgeTransitions.end(), transition);
  transition->matching += 1;

  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, crossField, fixture.targetSize,
      fixture.options);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskTransport,
            network.phaseFront.failure.reason)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  EXPECT_TRUE(network.phaseFront.cells.empty());
}

TEST(SurfaceCellsPhase10, PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets) {
  directional::TriMesh plane;
  directional::TriMesh cylinder;
  ASSERT_TRUE(directional::readOBJ(
      directional::tests::benchmark_fixture_path("milestone-g/plane.obj").string(),
      plane));
  ASSERT_TRUE(directional::readOBJ(
      directional::tests::benchmark_fixture_path("milestone-g/cylinder.obj").string(),
      cylinder));
  const Eigen::MatrixXd planeRaw = read_rawfield_fixture(
      directional::tests::benchmark_fixture_path("milestone-g/plane.rawfield"),
      plane.F.rows());
  const Eigen::MatrixXd cylinderRaw = read_rawfield_fixture(
      directional::tests::benchmark_fixture_path("milestone-g/cylinder.rawfield"),
      cylinder.F.rows());
  const CurvedDiskFixture disk = make_curved_disk_fixture();
  const Eigen::MatrixXd diskRaw = curved_disk_raw_field(disk);

  const int planeVertices = plane.V.rows();
  const int cylinderVertices = cylinder.V.rows();
  const int planeFaces = plane.F.rows();
  const int cylinderFaces = cylinder.F.rows();
  Eigen::MatrixXd vertices(
      planeVertices + cylinderVertices + disk.vertices.rows(), 3);
  vertices.topRows(planeVertices) = plane.V;
  vertices.middleRows(planeVertices, cylinderVertices) = cylinder.V;
  vertices.middleRows(planeVertices, cylinderVertices).col(0).array() += 10.0;
  vertices.bottomRows(disk.vertices.rows()) = disk.vertices;
  vertices.bottomRows(disk.vertices.rows()).col(0).array() += 20.0;

  Eigen::MatrixXi faces(planeFaces + cylinderFaces + disk.faces.rows(), 3);
  faces.topRows(planeFaces) = plane.F;
  faces.middleRows(planeFaces, cylinderFaces) =
      (cylinder.F.array() + planeVertices).matrix();
  faces.bottomRows(disk.faces.rows()) =
      (disk.faces.array() + planeVertices + cylinderVertices).matrix();
  Eigen::MatrixXd rawField(planeRaw.rows() + cylinderRaw.rows() + diskRaw.rows(),
                           planeRaw.cols());
  rawField.topRows(planeRaw.rows()) = planeRaw;
  rawField.middleRows(planeRaw.rows(), cylinderRaw.rows()) = cylinderRaw;
  rawField.bottomRows(diskRaw.rows()) = diskRaw;

  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(mesh, rawField);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.resize(static_cast<std::size_t>(faces.rows()));
  options.sourceFaceSheets.resize(static_cast<std::size_t>(faces.rows()));
  for (int face = 0; face < faces.rows(); ++face) {
    const int sheet = face < planeFaces ? 0 : (face < planeFaces + cylinderFaces ? 1 : 2);
    options.sourceFaceComponents[static_cast<std::size_t>(face)] = sheet;
    options.sourceFaceSheets[static_cast<std::size_t>(face)] = sheet;
  }
  const int diskOffset = planeVertices + cylinderVertices;
  const auto addDiskBoundary = [&](const int a, const int b) {
    options.hardFeatureEdges.insert(
        directional::pipeline::surface_cell_source_edge_key(diskOffset + a,
                                                             diskOffset + b));
  };
  for (int x = 0; x < 2; ++x) {
    addDiskBoundary(x, x + 1);
    addDiskBoundary(6 + x, 6 + x + 1);
  }
  for (int y = 0; y < 2; ++y) {
    addDiskBoundary(y * 3, (y + 1) * 3);
    addDiskBoundary(y * 3 + 2, (y + 1) * 3 + 2);
  }
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(vertices.rows(), 0.25);
  const auto network = directional::geometry::build_surface_cell_network(
      vertices, faces, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);

  std::map<std::pair<int, int>, int> cellsBySheet;
  for (const auto &cell : network.phaseFront.cells) {
    ++cellsBySheet[{cell.sourceComponent, cell.sourceSheet}];
  }
  ASSERT_EQ(3U, cellsBySheet.size());
  EXPECT_GT((cellsBySheet[std::pair<int, int>{0, 0}]), 0);
  EXPECT_GT((cellsBySheet[std::pair<int, int>{1, 1}]), 0);
  EXPECT_GT((cellsBySheet[std::pair<int, int>{2, 2}]), 0);
  ASSERT_EQ(1U, network.phaseFront.periodicHolonomies.size());
  EXPECT_EQ(1, network.phaseFront.periodicHolonomies.front().sourceSheet);
}

TEST(SurfaceCellsPhase10,
     PhaseFrontComposesBoundedAndPeriodicAuthoritativeSheets) {
  directional::TriMesh plane;
  directional::TriMesh cylinder;
  ASSERT_TRUE(directional::readOBJ(
      directional::tests::benchmark_fixture_path("milestone-g/plane.obj").string(),
      plane));
  ASSERT_TRUE(directional::readOBJ(
      directional::tests::benchmark_fixture_path("milestone-g/cylinder.obj").string(),
      cylinder));
  const Eigen::MatrixXd planeRaw = read_rawfield_fixture(
      directional::tests::benchmark_fixture_path("milestone-g/plane.rawfield"),
      plane.F.rows());
  const Eigen::MatrixXd cylinderRaw = read_rawfield_fixture(
      directional::tests::benchmark_fixture_path("milestone-g/cylinder.rawfield"),
      cylinder.F.rows());

  Eigen::MatrixXd vertices(plane.V.rows() + cylinder.V.rows(), 3);
  vertices.topRows(plane.V.rows()) = plane.V;
  vertices.bottomRows(cylinder.V.rows()) = cylinder.V;
  vertices.bottomRows(cylinder.V.rows()).col(0).array() += 10.0;
  Eigen::MatrixXi faces(plane.F.rows() + cylinder.F.rows(), 3);
  faces.topRows(plane.F.rows()) = plane.F;
  faces.bottomRows(cylinder.F.rows()) =
      (cylinder.F.array() + plane.V.rows()).matrix();
  Eigen::MatrixXd rawField(planeRaw.rows() + cylinderRaw.rows(), planeRaw.cols());
  rawField.topRows(planeRaw.rows()) = planeRaw;
  rawField.bottomRows(cylinderRaw.rows()) = cylinderRaw;

  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(mesh, rawField);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.resize(static_cast<std::size_t>(mesh.F.rows()));
  options.sourceFaceSheets.resize(static_cast<std::size_t>(mesh.F.rows()));
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const bool onPlane = face < plane.F.rows();
    options.sourceFaceComponents[static_cast<std::size_t>(face)] = onPlane ? 0 : 1;
    options.sourceFaceSheets[static_cast<std::size_t>(face)] = onPlane ? 0 : 1;
  }

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  ASSERT_TRUE(network.phaseFront.succeeded);
  ASSERT_EQ(1U, network.phaseFront.periodicHolonomies.size());
  EXPECT_EQ(1, network.phaseFront.periodicHolonomies.front().sourceComponent);
  EXPECT_EQ(1, network.phaseFront.periodicHolonomies.front().sourceSheet);

  std::map<std::pair<int, int>, int> cellsBySheet;
  for (const auto &cell : network.phaseFront.cells) {
    ++cellsBySheet[{cell.sourceComponent, cell.sourceSheet}];
  }
  ASSERT_EQ(2U, cellsBySheet.size());
  EXPECT_GT((cellsBySheet[std::pair<int, int>{0, 0}]), 0);
  EXPECT_GT((cellsBySheet[std::pair<int, int>{1, 1}]), 0);
}

TEST(SurfaceCellsPhase10,
     PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority) {
  const auto build = [](const bool reverseFaces) {
    Eigen::MatrixXd vertices(8, 3);
    vertices << 0.0, 0.0, 0.0,
                1.0, 0.0, 0.0,
                1.0, 1.0, 0.0,
                0.0, 1.0, 0.0,
                0.0, 0.0, 3.0,
                1.0, 0.0, 3.0,
                0.5, 0.9, 3.0,
                0.5, 0.3, 3.8;
    Eigen::MatrixXi faces(6, 3);
    faces << 0, 1, 2,
             0, 2, 3,
             4, 6, 5,
             4, 5, 7,
             5, 6, 7,
             6, 4, 7;
    if (reverseFaces) {
      faces = faces.colwise().reverse().eval();
    }

    Eigen::MatrixXd faceAxisX(faces.rows(), 3);
    Eigen::MatrixXd faceAxisY(faces.rows(), 3);
    for (int face = 0; face < faces.rows(); ++face) {
      const Eigen::RowVector3d a = vertices.row(faces(face, 0));
      const Eigen::RowVector3d b = vertices.row(faces(face, 1));
      const Eigen::RowVector3d c = vertices.row(faces(face, 2));
      Eigen::RowVector3d normal = (b - a).cross(c - a);
      normal.normalize();
      Eigen::RowVector3d reference =
          std::abs(normal.z()) < 0.9 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
                                     : Eigen::RowVector3d(1.0, 0.0, 0.0);
      Eigen::RowVector3d axisX = reference - reference.dot(normal) * normal;
      axisX.normalize();
      Eigen::RowVector3d axisY = normal.cross(axisX);
      axisY.normalize();
      faceAxisX.row(face) = axisX;
      faceAxisY.row(face) = axisY;
    }

    directional::geometry::SurfaceCellTracingOptions options;
    options.sourceFaceComponents.resize(static_cast<std::size_t>(faces.rows()));
    options.sourceFaceSheets.resize(static_cast<std::size_t>(faces.rows()));
    for (int face = 0; face < faces.rows(); ++face) {
      const bool planeFace = faces(face, 0) < 4 && faces(face, 1) < 4 &&
                             faces(face, 2) < 4;
      options.sourceFaceComponents[static_cast<std::size_t>(face)] =
          planeFace ? 0 : 1;
      options.sourceFaceSheets[static_cast<std::size_t>(face)] =
          planeFace ? 0 : 1;
    }
    const Eigen::VectorXd targetSize =
        Eigen::VectorXd::Constant(vertices.rows(), 0.25);
    return std::make_pair(
        directional::geometry::build_surface_cell_network(
            vertices, faces, faceAxisX, faceAxisY, targetSize, options),
        std::move(options));
  };

  const auto forward = build(false);
  const auto reverse = build(true);
  for (const auto *built : {&forward, &reverse}) {
    const auto &network = built->first;
    const auto &options = built->second;
    EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
              network.phaseFront.disposition);
    EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                  UnsupportedSourceSheetTopology,
              network.phaseFront.failure.reason)
        << directional::geometry::surface_phase_front_failure_reason_name(
               network.phaseFront.failure.reason);
    EXPECT_FALSE(network.phaseFront.succeeded);
    EXPECT_TRUE(network.phaseFront.cells.empty());
    EXPECT_TRUE(network.phaseFront.edges.empty());
    EXPECT_TRUE(network.phaseFront.events.empty());
    ASSERT_GE(network.phaseFront.failure.face, 0);
    ASSERT_LT(network.phaseFront.failure.face,
              static_cast<int>(options.sourceFaceSheets.size()));
    EXPECT_EQ(1, options.sourceFaceComponents[
                     static_cast<std::size_t>(network.phaseFront.failure.face)]);
    EXPECT_EQ(1, options.sourceFaceSheets[
                     static_cast<std::size_t>(network.phaseFront.failure.face)]);
  }
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  SurfacePeriodicHolonomy forward;
  forward.sourceComponent = 2;
  forward.sourceSheet = 7;
  forward.quarterTurnRotation = 0;
  forward.latticeTranslation = Eigen::Vector2i(8, 0);
  forward.sourceRouteEdges = {4, 6, 8, 10};
  forward.sourceRouteTopology = {40, 60, 80, 100};
  forward.cutSourceEdges = {12, 14};
  forward.cutSourceTopology = {120, 140};

  SurfacePeriodicHolonomy reverse = forward;
  reverse.latticeTranslation = Eigen::Vector2i(-8, 0);
  std::reverse(reverse.sourceRouteEdges.begin(), reverse.sourceRouteEdges.end());
  std::reverse(reverse.sourceRouteTopology.begin(), reverse.sourceRouteTopology.end());
  std::reverse(reverse.cutSourceEdges.begin(), reverse.cutSourceEdges.end());
  std::reverse(reverse.cutSourceTopology.begin(), reverse.cutSourceTopology.end());

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, forward));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Equivalent,
            insert_periodic_holonomy(relations, reverse));
  ASSERT_EQ(1U, relations.size());
  EXPECT_EQ(8, relations.front().latticeTranslation.x());
  EXPECT_EQ(0, relations.front().latticeTranslation.y());
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyDistinctAuthoritativeSheetsRetainEveryRelation) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  const auto makeRelation = [](const int sheet, const std::uint64_t routeKey,
                               const std::uint64_t cutKey) {
    SurfacePeriodicHolonomy relation;
    relation.sourceComponent = 0;
    relation.sourceSheet = sheet;
    relation.latticeTranslation = Eigen::Vector2i(6, 0);
    relation.sourceRouteEdges = {sheet * 10 + 1};
    relation.sourceRouteTopology = {routeKey};
    relation.cutSourceEdges = {sheet * 10 + 2};
    relation.cutSourceTopology = {cutKey};
    return relation;
  };

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, makeRelation(3, 300, 301)));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, makeRelation(1, 100, 101)));
  ASSERT_EQ(2U, relations.size());
  EXPECT_EQ(1, relations[0].sourceSheet);
  EXPECT_EQ(3, relations[1].sourceSheet);
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomySameSheetDependentBasisFailsClosedWithoutOrderChoice) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  const auto makeRelation = [](const int edge, const std::uint64_t topology) {
    SurfacePeriodicHolonomy relation;
    relation.sourceComponent = 0;
    relation.sourceSheet = 0;
    relation.latticeTranslation = Eigen::Vector2i(4, 0);
    relation.sourceRouteEdges = {edge};
    relation.sourceRouteTopology = {topology};
    relation.cutSourceEdges = {edge + 1};
    relation.cutSourceTopology = {topology + 1};
    return relation;
  };

  for (const bool reversed : {false, true}) {
    std::vector<SurfacePeriodicHolonomy> relations;
    auto first = makeRelation(1, 10);
    auto second = makeRelation(3, 30);
    if (reversed) std::swap(first, second);
    EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
              insert_periodic_holonomy(relations, first));
    EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis,
              insert_periodic_holonomy(relations, second));
    ASSERT_EQ(1U, relations.size());
  }
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyConflictingTransportFailsClosed) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  SurfacePeriodicHolonomy first;
  first.sourceComponent = 0;
  first.sourceSheet = 0;
  first.latticeTranslation = Eigen::Vector2i(4, 0);
  first.sourceRouteEdges = {1, 2};
  first.sourceRouteTopology = {10, 20};
  first.cutSourceEdges = {3};
  first.cutSourceTopology = {30};
  SurfacePeriodicHolonomy conflicting = first;
  conflicting.quarterTurnRotation = 1;
  conflicting.latticeTranslation = Eigen::Vector2i(0, 4);

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, first));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Incompatible,
            insert_periodic_holonomy(relations, conflicting));
}

TEST(SurfaceCellsPhase10,
     ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());

  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.preserveDebugArtifacts = true;
  options.surfaceCells.retainIntermediateGeometry = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.V, mesh.F, rawField, options);
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &phaseFront = result.surfaceCellContext.traceNetwork.phaseFront;
  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::InvalidPeriodicTopology,
            phaseFront.failure.reason);
  EXPECT_NE(directional::geometry::SurfaceCellProducerDisposition::NotApplicable,
            phaseFront.disposition)
      << "authoritative sheet coverage must not leak partial NotApplicable";
  EXPECT_GT(phaseFront.periodicHolonomies.size(), 1U);
  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::
                UnsupportedSourceSheetTopology,
            phaseFront.failure.reason)
      << "curved topological disks now have a structural producer";
  if (phaseFront.disposition ==
      directional::geometry::SurfaceCellProducerDisposition::Rejected) {
    EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::None,
              phaseFront.failure.reason);
  }
  if (phaseFront.disposition ==
      directional::geometry::SurfaceCellProducerDisposition::Produced) {
    EXPECT_EQ(phaseFront.periodicHolonomies.size(),
              result.diagnostics.surfaceCellPeriodicHolonomies.size());
  }
}

TEST(SurfaceCellsPhase10,
     PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, rawField);
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto valid = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            valid.phaseFront.disposition);
  ASSERT_FALSE(valid.phaseFront.periodicHolonomies.front().sourceRouteEdges.empty());
  const int tamperedEdge = valid.phaseFront.periodicHolonomies.front().sourceRouteEdges.front();
  auto transition = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [&](const auto &candidate) { return candidate.sourceEdge == tamperedEdge; });
  ASSERT_NE(crossField.edgeTransitions.end(), transition);
  transition->matching += 1;

  const auto malformed = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            malformed.phaseFront.disposition);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                PeriodicHolonomyMismatch,
            malformed.phaseFront.failure.reason);
  EXPECT_TRUE(malformed.seeds.empty());
  EXPECT_TRUE(malformed.traces.empty());
  EXPECT_TRUE(malformed.proposals.empty());
}

TEST(SurfaceCellsPhase10,
     ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField = read_rawfield_fixture(fieldPath, mesh.F.rows());

  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.preserveDebugArtifacts = true;
  options.surfaceCells.retainIntermediateGeometry = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.V, mesh.F, rawField, options);
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &network = result.surfaceCellContext.traceNetwork;
  EXPECT_NE(directional::geometry::SurfaceCellProducerDisposition::NotApplicable,
            network.phaseFront.disposition);
  if (network.phaseFront.disposition ==
      directional::geometry::SurfaceCellProducerDisposition::Produced) {
    EXPECT_TRUE(!network.phaseFront.periodicHolonomies.empty());
    EXPECT_TRUE(result.diagnostics.surfaceCellPeriodicHolonomyAvailable);
  } else {
    EXPECT_TRUE(network.phaseFront.failure.reason ==
                    directional::geometry::SurfacePhaseFrontFailureReason::
                        PeriodicHolonomyMismatch ||
                network.phaseFront.failure.reason ==
                    directional::geometry::SurfacePhaseFrontFailureReason::
                        InvalidPeriodicChart ||
                network.phaseFront.failure.reason ==
                    directional::geometry::SurfacePhaseFrontFailureReason::
                        InvalidPeriodicFrontPairing ||
                network.phaseFront.failure.reason ==
                    directional::geometry::SurfacePhaseFrontFailureReason::
                        InvalidPeriodicRingCorrespondence ||
                network.phaseFront.failure.reason ==
                    directional::geometry::SurfacePhaseFrontFailureReason::
                        AmbiguousPeriodicRingCorrespondence);
  }
  EXPECT_TRUE(network.seeds.empty());
  EXPECT_TRUE(network.traces.empty());
}


TEST(SurfaceCellsPhase10,
     ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/plane.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/plane.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField =
      read_rawfield_fixture(fieldPath, mesh.F.rows());

  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.preserveDebugArtifacts = true;
  options.surfaceCells.retainIntermediateGeometry = true;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.V, mesh.F, rawField, options);

  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &network = result.surfaceCellContext.traceNetwork;
  EXPECT_EQ("Produced",
            result.diagnostics.surfaceCellAuthoritativeProducerDisposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  EXPECT_TRUE(network.phaseFront.succeeded);
  EXPECT_EQ(64U, network.phaseFront.cells.size());
  EXPECT_TRUE(network.seeds.empty());
  EXPECT_TRUE(network.traces.empty());
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ":"
      << result.diagnostics.terminalFailureStage;
  EXPECT_EQ(64U, result.diagnostics.surfaceCellCompletedQuadCount);
}

} // namespace
