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
