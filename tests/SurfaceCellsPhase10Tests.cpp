#include <directional/fields/PointSampledCrossField.h>
#include <directional/io/ReadOBJ.h>
#include <directional/meshing/PatchQuadrangulator.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "TestFixturePaths.h"
#include <directional/validation/MeshValidator.h>
#include <directional/validation/ValidationVisualizer.h>

#include <algorithm>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <set>
#include <string>
#include <tuple>
#include <type_traits>

#include <gtest/gtest.h>

namespace {

using directional::validation::MeshValidationFailureCode;

std::uint64_t test_source_edge_key(
    const directional::authority::SourceEdgeTopologyKey &topology) {
  return directional::pipeline::surface_cell_source_edge_key(
      static_cast<int>(topology.first().index()),
      static_cast<int>(topology.second().index()));
}

std::vector<std::uint64_t> route_topology(
    const directional::authority::CanonicalRoute &route) {
  std::vector<std::uint64_t> result;
  result.reserve(route.steps().size());
  for (const auto &step : route.steps()) {
    result.push_back(test_source_edge_key(step.topology()));
  }
  return result;
}

std::vector<int> route_transition_ids(
    const directional::authority::CanonicalRoute &route) {
  std::vector<int> result;
  result.reserve(route.steps().size());
  for (const auto &step : route.steps()) {
    result.push_back(step.interior().has_value()
                         ? static_cast<int>(step.interior()->index())
                         : -1);
  }
  return result;
}

bool route_is_all_boundary(const directional::authority::CanonicalRoute &route) {
  return !route.empty() &&
         std::all_of(route.steps().begin(), route.steps().end(), [](const auto &step) {
           return step.kind() ==
                  directional::authority::TransitionStepKind::Boundary;
         });
}

bool route_is_all_interior(const directional::authority::CanonicalRoute &route) {
  return !route.empty() &&
         std::all_of(route.steps().begin(), route.steps().end(), [](const auto &step) {
           return step.kind() ==
                      directional::authority::TransitionStepKind::Interior &&
                  step.interior().has_value();
         });
}



const directional::geometry::SurfacePhaseFrontFailure &phase_front_rejection(
    const directional::geometry::SurfacePhaseFrontResult &phaseFront) {
  const auto *failure = phaseFront.rejection();
  if (failure == nullptr) {
    throw std::runtime_error("Expected rejected phase-front outcome.");
  }
  return *failure;
}

const directional::geometry::SurfaceTopologyRegion &phase_front_region(
    const directional::geometry::SurfacePhaseFrontResult &phaseFront,
    const directional::authority::TopologyRegionId id) {
  const auto found = std::find_if(
      phaseFront.product().sourceTopologyRegions.regions().begin(),
      phaseFront.product().sourceTopologyRegions.regions().end(),
      [&](const auto &region) { return region.id() == id; });
  if (found == phaseFront.product().sourceTopologyRegions.regions().end()) {
    throw std::runtime_error("Missing typed topology-region authority.");
  }
  return *found;
}

template <typename Owner>
const directional::geometry::SurfaceTopologyRegion &phase_front_region(
    const directional::geometry::SurfacePhaseFrontResult &phaseFront,
    const Owner &owner) {
  return phase_front_region(phaseFront, owner.sourceTopologyRegion);
}

int phase_front_component(
    const directional::geometry::SurfacePhaseFrontResult &phaseFront,
    const auto &owner) {
  return static_cast<int>(
      phase_front_region(phaseFront, owner).component().index());
}

std::vector<directional::authority::IsolationSheetId> topology_region_sheets(
    const directional::geometry::SurfaceTopologyRegion &region) {
  std::vector<directional::authority::IsolationSheetId> sheets;
  sheets.reserve(region.faces().size());
  for (const auto &face : region.faces()) {
    sheets.push_back(face.sheet);
  }
  std::sort(sheets.begin(), sheets.end());
  sheets.erase(std::unique(sheets.begin(), sheets.end()), sheets.end());
  return sheets;
}

std::optional<int> phase_front_single_sheet(
    const directional::geometry::SurfacePhaseFrontResult &phaseFront,
    const auto &owner) {
  const auto sheets = topology_region_sheets(phase_front_region(phaseFront, owner));
  if (sheets.size() != 1U) return std::nullopt;
  return static_cast<int>(sheets.front().index());
}

std::vector<int> phase_front_sheets(
    const directional::geometry::SurfacePhaseFrontResult &phaseFront,
    const auto &owner) {
  std::vector<int> result;
  for (const auto sheet :
       topology_region_sheets(phase_front_region(phaseFront, owner))) {
    result.push_back(static_cast<int>(sheet.index()));
  }
  return result;
}


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

directional::TriMesh make_disconnected_square_pair_mesh(
    const bool reverseFaceRows = false) {
  Eigen::MatrixXd vertices(8, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0,
              0.0, 0.0, 2.0,
              1.0, 0.0, 2.0,
              1.0, 1.0, 2.0,
              0.0, 1.0, 2.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 2,
           0, 2, 3,
           4, 5, 6,
           4, 6, 7;
  if (reverseFaceRows) faces = faces.colwise().reverse().eval();
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


struct FieldTransitionFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  std::map<std::uint64_t, std::array<int, 2>> edgeFaces;
  std::map<std::uint64_t, int> edgeMatchingIndices;
  directional::geometry::surface_cell_tracing_detail::EdgeTransitionLookup
      transitionLookup;
  std::uint64_t edgeKey = 0;
  std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
};

FieldTransitionFixture make_field_transition_fixture(const int matching = 1) {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  FieldTransitionFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      1.0, 1.0, 0.0,
                      0.0, 1.0, 0.0;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3;
  fixture.faceAxisX.resize(2, 3);
  fixture.faceAxisX << 1.0, 0.0, 0.0,
                       1.0, 0.0, 0.0;
  fixture.faceAxisY.resize(2, 3);
  fixture.faceAxisY << 0.0, 1.0, 0.0,
                       0.0, 1.0, 0.0;
  fixture.edgeFaces = detail::edge_faces(fixture.faces);
  fixture.edgeMatchingIndices = detail::edge_matching_indices(fixture.edgeFaces);
  fixture.edgeKey = detail::edge_key(0, 2);

  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceEdge = fixture.edgeMatchingIndices.at(fixture.edgeKey);
  transition.sourceVertex0 = 0;
  transition.sourceVertex1 = 2;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = matching;
  transition.effort = 0.25;
  fixture.transitions.push_back(transition);
  fixture.transitionLookup = detail::edge_transition_lookup(fixture.transitions);
  return fixture;
}

directional::geometry::surface_cell_tracing_detail::BranchTransitionResult
resolve_field_transition(
    const FieldTransitionFixture &fixture, const int sourceFace,
    const int targetFace, const int sourceFamily, const int sourceSign,
    const Eigen::RowVector3d &sourceDirection,
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr,
    const bool useAuthoritativeTransitions = true) {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  return detail::resolve_branch_transition(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.edgeFaces, fixture.edgeMatchingIndices, fixture.transitionLookup,
      fixture.edgeKey, sourceFace, targetFace, sourceFamily, sourceSign,
      sourceDirection, edgeMatching, edgeEffort,
      useAuthoritativeTransitions ? &fixture.transitions : nullptr);
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     ForwardQuarterTurnUsesTypedModuloTransport) {
  const FieldTransitionFixture fixture = make_field_transition_fixture(1);

  const auto result = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(1, result.matching);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(Eigen::RowVector3d(0.0, 1.0, 0.0),
                                        1.0e-12));
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     ReverseTraversalUsesExactQuarterTurnInverse) {
  const FieldTransitionFixture fixture = make_field_transition_fixture(1);

  const auto result = resolve_field_transition(
      fixture, 1, 0, 1, 1, Eigen::RowVector3d(0.0, 1.0, 0.0));

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(-1, result.matching);
  EXPECT_EQ(0, result.family);
  EXPECT_EQ(1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(Eigen::RowVector3d(1.0, 0.0, 0.0),
                                        1.0e-12));
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     EquivalentQuarterTurnsNormalizeSemantically) {
  const FieldTransitionFixture plusOne = make_field_transition_fixture(1);
  const FieldTransitionFixture plusFive = make_field_transition_fixture(5);

  const auto one = resolve_field_transition(
      plusOne, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));
  const auto five = resolve_field_transition(
      plusFive, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));

  ASSERT_TRUE(one.valid);
  ASSERT_TRUE(five.valid);
  EXPECT_EQ(1, one.matching);
  EXPECT_EQ(5, five.matching);
  EXPECT_EQ(one.family, five.family);
  EXPECT_EQ(one.sign, five.sign);
  EXPECT_TRUE(one.direction.isApprox(five.direction, 1.0e-12));
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     ReversedSourceEdgeEndpointsPreserveSemanticIdentity) {
  FieldTransitionFixture fixture = make_field_transition_fixture(1);
  fixture.transitions.front().sourceVertex0 = 2;
  fixture.transitions.front().sourceVertex1 = 0;
  fixture.transitionLookup =
      directional::geometry::surface_cell_tracing_detail::edge_transition_lookup(
          fixture.transitions);

  const auto result = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0));

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(1, result.matching);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(1, result.sign);
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     MalformedAuthoritativeFaceOrEdgeFailsClosed) {
  FieldTransitionFixture fixture = make_field_transition_fixture(1);
  const int matchingIndex = fixture.edgeMatchingIndices.at(fixture.edgeKey);
  Eigen::VectorXi fallbackMatching =
      Eigen::VectorXi::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  Eigen::VectorXd fallbackEffort =
      Eigen::VectorXd::Constant(static_cast<int>(fixture.edgeMatchingIndices.size()),
                                0.75);
  fallbackMatching[matchingIndex] = 3;

  auto malformedFace = fixture.transitions.front();
  malformedFace.firstFace = fixture.faces.rows();
  fixture.transitions = {malformedFace};
  fixture.transitionLookup.byEdge.clear();
  fixture.transitionLookup.byEdge.emplace(fixture.edgeKey, malformedFace);
  const auto faceResult = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0),
      &fallbackMatching, &fallbackEffort, true);
  EXPECT_FALSE(faceResult.valid);

  auto malformedEdge = malformedFace;
  malformedEdge.firstFace = 0;
  malformedEdge.sourceVertex1 = fixture.vertices.rows();
  fixture.transitions = {malformedEdge};
  fixture.transitionLookup.byEdge.clear();
  fixture.transitionLookup.byEdge.emplace(fixture.edgeKey, malformedEdge);
  const auto edgeResult = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0),
      &fallbackMatching, &fallbackEffort, true);
  EXPECT_FALSE(edgeResult.valid);
}

TEST(SurfaceCellFieldTransitionAuthorityMigration,
     LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent) {
  const FieldTransitionFixture fixture = make_field_transition_fixture(1);
  const int matchingIndex = fixture.edgeMatchingIndices.at(fixture.edgeKey);
  Eigen::VectorXi fallbackMatching =
      Eigen::VectorXi::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  Eigen::VectorXd fallbackEffort =
      Eigen::VectorXd::Constant(static_cast<int>(fixture.edgeMatchingIndices.size()),
                                0.75);
  fallbackMatching[matchingIndex] = 3;

  const auto result = resolve_field_transition(
      fixture, 0, 1, 0, 1, Eigen::RowVector3d(1.0, 0.0, 0.0),
      &fallbackMatching, &fallbackEffort, false);

  ASSERT_TRUE(result.valid);
  EXPECT_EQ(3, result.matching);
  EXPECT_DOUBLE_EQ(0.75, result.effort);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(-1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(Eigen::RowVector3d(0.0, -1.0, 0.0),
                                        1.0e-12));
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
  for (const auto &cell : network.phaseFront.product().cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        if (segment.entryRoute.steps().size() > 1U) {
          ++count;
        }
      }
    }
  }
  return count;
}

int fixture_quarter_turn(const int value) {
  return ((value % 4) + 4) % 4;
}

Eigen::MatrixXd relabeled_xy_raw_field(
    const std::vector<int> &branchLabels) {
  Eigen::Matrix<double, 4, 3> branches;
  branches << 1.0, 0.0, 0.0,
              0.0, 1.0, 0.0,
             -1.0, 0.0, 0.0,
              0.0, -1.0, 0.0;
  Eigen::MatrixXd field(static_cast<Eigen::Index>(branchLabels.size()), 12);
  for (Eigen::Index face = 0; face < field.rows(); ++face) {
    const int label = fixture_quarter_turn(
        branchLabels[static_cast<std::size_t>(face)]);
    for (int branch = 0; branch < 4; ++branch) {
      field.block<1, 3>(face, 3 * branch) =
          branches.row(fixture_quarter_turn(label + branch));
    }
  }
  return field;
}

struct SegmentRouteKey {
  int previousFace = -1;
  int currentFace = -1;
  std::vector<std::uint64_t> sourceTopology;

  bool operator==(const SegmentRouteKey &) const = default;
};

struct SegmentRouteObservation {
  SegmentRouteKey key;
  int matching = 0;
  std::vector<int> sourceEdges;
  int sourceVertex = -1;
  int previousExitEdge = -1;
  int currentEntryEdge = -1;
};

int attached_source_vertex(const directional::TriMesh &mesh, const int face,
                           const Eigen::RowVector3d &barycentric) {
  int sourceVertex = -1;
  for (int corner = 0; corner < 3; ++corner) {
    if (barycentric[corner] < 1.0 - 1.0e-10) continue;
    if (sourceVertex >= 0) return -1;
    sourceVertex = mesh.F(face, corner);
  }
  return sourceVertex;
}

std::vector<SegmentRouteObservation> segment_route_observations(
    const directional::TriMesh &mesh,
    const directional::geometry::SurfaceCellNetwork &network) {
  std::vector<SegmentRouteObservation> observations;
  for (const auto &cell : network.phaseFront.product().cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (std::size_t index = 1; index < path.size(); ++index) {
        const auto &previous = path[index - 1U];
        const auto &current = path[index];
        const auto routeSteps = current.entryRoute.oriented_steps();
        if (routeSteps.empty()) continue;
        std::vector<std::uint64_t> sourceTopology;
        std::vector<int> sourceEdges;
        sourceTopology.reserve(routeSteps.size());
        sourceEdges.reserve(routeSteps.size());
        bool routeValid = true;
        for (const auto &step : routeSteps) {
          if (step.kind() != directional::authority::TransitionStepKind::Interior ||
              !step.interior().has_value()) {
            routeValid = false;
            break;
          }
          sourceTopology.push_back(
              directional::pipeline::surface_cell_source_edge_key(
                  static_cast<int>(step.topology().first().index()),
                  static_cast<int>(step.topology().second().index())));
          sourceEdges.push_back(static_cast<int>(step.interior()->index()));
        }
        if (!routeValid) continue;
        const int previousVertex = attached_source_vertex(
            mesh, previous.face, previous.endBarycentric);
        const int currentVertex = attached_source_vertex(
            mesh, current.face, current.startBarycentric);
        observations.push_back(
            {{previous.face, current.face, std::move(sourceTopology)},
             current.matching, std::move(sourceEdges),
             previousVertex >= 0 && previousVertex == currentVertex
                 ? previousVertex
                 : -1,
             previous.exitEdge, current.entryEdge});
      }
    }
  }
  return observations;
}

std::vector<SegmentRouteObservation> observations_for_route(
    const directional::TriMesh &mesh,
    const directional::geometry::SurfaceCellNetwork &network,
    const SegmentRouteKey &key) {
  std::vector<SegmentRouteObservation> matches;
  for (const auto &observation : segment_route_observations(mesh, network)) {
    if (observation.key == key) matches.push_back(observation);
  }
  return matches;
}

using SegmentRouteSemanticSnapshot =
    std::tuple<int, int, std::vector<std::uint64_t>, int, std::vector<int>,
               int, int, int>;

std::vector<SegmentRouteSemanticSnapshot> segment_route_semantic_snapshot(
    const directional::TriMesh &mesh,
    const directional::geometry::SurfaceCellNetwork &network) {
  std::vector<SegmentRouteSemanticSnapshot> snapshot;
  for (const auto &observation : segment_route_observations(mesh, network)) {
    snapshot.emplace_back(
        observation.key.previousFace, observation.key.currentFace,
        observation.key.sourceTopology, observation.matching,
        observation.sourceEdges, observation.sourceVertex,
        observation.previousExitEdge,
        observation.currentEntryEdge);
  }
  std::sort(snapshot.begin(), snapshot.end());
  return snapshot;
}

struct SegmentRouteFixture {
  directional::TriMesh mesh;
  std::vector<int> branchLabels;
  directional::fields::CrossFieldResult authoritativeField;
  SegmentRouteKey forwardRoute;
  SegmentRouteKey reverseRoute;
  std::vector<int> forwardCompactEdges;
  std::vector<int> reverseCompactEdges;
};

SegmentRouteFixture make_segment_route_fixture() {
  SegmentRouteFixture fixture;
  fixture.mesh = make_vertex_fan_plane_mesh();
  fixture.branchLabels.assign(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  fixture.branchLabels[3] = 1;
  fixture.branchLabels[10] = 3;
  fixture.authoritativeField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, relabeled_xy_raw_field(fixture.branchLabels));

  const std::uint64_t first =
      directional::pipeline::surface_cell_source_edge_key(1, 7);
  const std::uint64_t second =
      directional::pipeline::surface_cell_source_edge_key(6, 7);
  fixture.forwardRoute = {2, 10, {first, second}};
  fixture.reverseRoute = {10, 2, {second, first}};
  // Independent lexicographic enumeration of the fixture's 29 interior
  // source edges assigns (1,7) -> 2 and (6,7) -> 9.
  fixture.forwardCompactEdges = {2, 9};
  fixture.reverseCompactEdges = {9, 2};
  return fixture;
}

directional::geometry::SurfaceCellNetwork build_segment_route_network(
    const SegmentRouteFixture &fixture,
    const directional::fields::CrossFieldResult &crossField) {
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  return directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField, targetSize, options);
}

const directional::fields::CrossFieldEdgeTransition *transition_for_edge(
    const directional::fields::CrossFieldResult &crossField,
    const std::uint64_t topology) {
  const auto found = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [&](const auto &transition) {
        return directional::pipeline::surface_cell_source_edge_key(
                   transition.sourceVertex0, transition.sourceVertex1) ==
               topology;
      });
  return found == crossField.edgeTransitions.end() ? nullptr : &*found;
}

directional::fields::CrossFieldEdgeTransition *transition_for_edge(
    directional::fields::CrossFieldResult &crossField,
    const std::uint64_t topology) {
  const auto found = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [&](const auto &transition) {
        return directional::pipeline::surface_cell_source_edge_key(
                   transition.sourceVertex0, transition.sourceVertex1) ==
               topology;
      });
  return found == crossField.edgeTransitions.end() ? nullptr : &*found;
}

int directed_matching(
    const directional::fields::CrossFieldEdgeTransition &transition,
    const int sourceFace, const int targetFace) {
  if (transition.firstFace == sourceFace &&
      transition.secondFace == targetFace) {
    return transition.matching;
  }
  if (transition.firstFace == targetFace &&
      transition.secondFace == sourceFace) {
    return -transition.matching;
  }
  return 0;
}

directional::fields::CrossFieldResult make_legacy_segment_route_field(
    const SegmentRouteFixture &fixture) {
  auto legacy = fixture.authoritativeField;
  legacy.edgeTransitions.clear();

  std::map<std::uint64_t, std::array<int, 2>> incidence;
  for (int face = 0; face < fixture.mesh.F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const std::uint64_t topology =
          directional::pipeline::surface_cell_source_edge_key(
              fixture.mesh.F(face, corner),
              fixture.mesh.F(face, (corner + 1) % 3));
      auto [found, inserted] = incidence.try_emplace(
          topology, std::array<int, 2>{face, -1});
      if (!inserted && found->second[0] != face && found->second[1] < 0) {
        found->second[1] = face;
      }
    }
  }

  int interiorCount = 0;
  for (const auto &[topology, faces] : incidence) {
    (void)topology;
    if (faces[0] >= 0 && faces[1] >= 0) ++interiorCount;
  }
  legacy.matching.resize(interiorCount);
  legacy.effort = Eigen::VectorXd::Zero(interiorCount);
  int compact = 0;
  for (const auto &[topology, faces] : incidence) {
    (void)topology;
    if (faces[0] < 0 || faces[1] < 0) continue;
    legacy.matching[compact++] = fixture_quarter_turn(
        fixture.branchLabels[static_cast<std::size_t>(faces[0])] -
        fixture.branchLabels[static_cast<std::size_t>(faces[1])]);
  }
  return legacy;
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     MultiStepVertexFanComposesTypedRouteTransport) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto *first = transition_for_edge(
      fixture.authoritativeField, fixture.forwardRoute.sourceTopology[0]);
  const auto *second = transition_for_edge(
      fixture.authoritativeField, fixture.forwardRoute.sourceTopology[1]);
  ASSERT_NE(nullptr, first);
  ASSERT_NE(nullptr, second);
  const int firstTurn = fixture_quarter_turn(directed_matching(*first, 2, 3));
  const int secondTurn =
      fixture_quarter_turn(directed_matching(*second, 3, 10));
  EXPECT_EQ(3, firstTurn);
  EXPECT_EQ(2, secondTurn);
  EXPECT_NE(0, firstTurn);
  EXPECT_NE(0, secondTurn);

  const auto network =
      build_segment_route_network(fixture, fixture.authoritativeField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  const auto witnesses =
      observations_for_route(fixture.mesh, network, fixture.forwardRoute);
  ASSERT_FALSE(witnesses.empty())
      << "fixture must execute the exact 2 -> 3 -> 10 vertex-fan route";
  for (const auto &witness : witnesses) {
    EXPECT_EQ(1, witness.matching);
    EXPECT_EQ(7, witness.sourceVertex);
    EXPECT_GE(witness.previousExitEdge, 0);
    EXPECT_GE(witness.currentEntryEdge, 0);
  }
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     ReverseObservedRouteUsesExactTransportInverse) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto network =
      build_segment_route_network(fixture, fixture.authoritativeField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());

  const auto forward =
      observations_for_route(fixture.mesh, network, fixture.forwardRoute);
  const auto reverse =
      observations_for_route(fixture.mesh, network, fixture.reverseRoute);
  ASSERT_FALSE(forward.empty());
  ASSERT_FALSE(reverse.empty());
  for (const auto &observation : forward) {
    EXPECT_EQ(1, observation.matching);
    EXPECT_EQ(7, observation.sourceVertex);
  }
  for (const auto &observation : reverse) {
    EXPECT_EQ(3, observation.matching);
    EXPECT_EQ(7, observation.sourceVertex);
  }
  EXPECT_EQ(0, fixture_quarter_turn(forward.front().matching +
                                    reverse.front().matching));
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     EquivalentSignedQuarterTurnsComposeSemantically) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  auto equivalent = fixture.authoritativeField;
  auto *first =
      transition_for_edge(equivalent, fixture.forwardRoute.sourceTopology[0]);
  auto *second =
      transition_for_edge(equivalent, fixture.forwardRoute.sourceTopology[1]);
  ASSERT_NE(nullptr, first);
  ASSERT_NE(nullptr, second);
  const int originalFirst = first->matching;
  const int originalSecond = second->matching;
  first->matching += 4;
  second->matching -= 4;
  EXPECT_NE(originalFirst, first->matching);
  EXPECT_NE(originalSecond, second->matching);
  EXPECT_EQ(fixture_quarter_turn(originalFirst),
            fixture_quarter_turn(first->matching));
  EXPECT_EQ(fixture_quarter_turn(originalSecond),
            fixture_quarter_turn(second->matching));

  const auto baseline =
      build_segment_route_network(fixture, fixture.authoritativeField);
  const auto relabeled = build_segment_route_network(fixture, equivalent);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            baseline.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            relabeled.phaseFront.disposition());
  EXPECT_EQ(segment_route_semantic_snapshot(fixture.mesh, baseline),
            segment_route_semantic_snapshot(fixture.mesh, relabeled));
  const auto witnesses =
      observations_for_route(fixture.mesh, relabeled, fixture.forwardRoute);
  ASSERT_FALSE(witnesses.empty());
  for (const auto &witness : witnesses) EXPECT_EQ(1, witness.matching);
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     RouteTopologyAndCompactTransitionProvenanceRemainUnchanged) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto network =
      build_segment_route_network(fixture, fixture.authoritativeField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());

  const auto forward =
      observations_for_route(fixture.mesh, network, fixture.forwardRoute);
  const auto reverse =
      observations_for_route(fixture.mesh, network, fixture.reverseRoute);
  ASSERT_FALSE(forward.empty());
  ASSERT_FALSE(reverse.empty());
  for (const auto &observation : forward) {
    EXPECT_EQ(fixture.forwardRoute.sourceTopology,
              observation.key.sourceTopology);
    EXPECT_EQ(fixture.forwardCompactEdges, observation.sourceEdges);
    ASSERT_FALSE(observation.sourceEdges.empty());
    EXPECT_EQ(9, observation.sourceEdges.back());
    EXPECT_EQ(7, observation.sourceVertex);
  }
  for (const auto &observation : reverse) {
    EXPECT_EQ(fixture.reverseRoute.sourceTopology,
              observation.key.sourceTopology);
    EXPECT_EQ(fixture.reverseCompactEdges, observation.sourceEdges);
    ASSERT_FALSE(observation.sourceEdges.empty());
    EXPECT_EQ(2, observation.sourceEdges.back());
    EXPECT_EQ(7, observation.sourceVertex);
  }
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto baseline =
      build_segment_route_network(fixture, fixture.authoritativeField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            baseline.phaseFront.disposition());
  ASSERT_FALSE(observations_for_route(fixture.mesh, baseline,
                                      fixture.forwardRoute)
                   .empty());

  auto malformed = fixture.authoritativeField;
  auto *transition =
      transition_for_edge(malformed, fixture.forwardRoute.sourceTopology[1]);
  ASSERT_NE(nullptr, transition);
  ASSERT_GE(transition->sourceEdge, 0);
  transition->sourceEdge = -1;

  const auto rejected = build_segment_route_network(fixture, malformed);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            rejected.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                MissingTransitionProvenance,
            rejected.phaseFront.rejection_reason());
  EXPECT_GE(phase_front_rejection(rejected.phaseFront).cell, 0);
  EXPECT_GE(phase_front_rejection(rejected.phaseFront).side, 0);
  EXPECT_EQ(7, phase_front_rejection(rejected.phaseFront).sourceVertex);
  EXPECT_TRUE((phase_front_rejection(rejected.phaseFront).face == 3 &&
               phase_front_rejection(rejected.phaseFront).targetFace == 10) ||
              (phase_front_rejection(rejected.phaseFront).face == 10 &&
               phase_front_rejection(rejected.phaseFront).targetFace == 3));
  EXPECT_FALSE(rejected.phaseFront.is_produced());
  EXPECT_EQ(nullptr, rejected.phaseFront.produced_product());
  EXPECT_TRUE(rejected.seeds.empty());
  EXPECT_TRUE(rejected.traces.empty());
  EXPECT_TRUE(rejected.proposals.empty());
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     LegacyMatchingFallbackUsesSameTypedRouteComposition) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto legacyField = make_legacy_segment_route_field(fixture);
  ASSERT_TRUE(legacyField.edgeTransitions.empty());
  ASSERT_EQ(29, legacyField.matching.size());
  EXPECT_EQ(3, legacyField.matching[2]);
  EXPECT_EQ(2, legacyField.matching[9]);

  const auto authoritative =
      build_segment_route_network(fixture, fixture.authoritativeField);
  const auto legacy = build_segment_route_network(fixture, legacyField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            authoritative.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            legacy.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             legacy.phaseFront.rejection_reason());
  EXPECT_EQ(segment_route_semantic_snapshot(fixture.mesh, authoritative),
            segment_route_semantic_snapshot(fixture.mesh, legacy));
  const auto forward =
      observations_for_route(fixture.mesh, legacy, fixture.forwardRoute);
  const auto reverse =
      observations_for_route(fixture.mesh, legacy, fixture.reverseRoute);
  ASSERT_FALSE(forward.empty());
  ASSERT_FALSE(reverse.empty());
  for (const auto &observation : forward) EXPECT_EQ(1, observation.matching);
  for (const auto &observation : reverse) EXPECT_EQ(3, observation.matching);
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

  ASSERT_TRUE(network.phaseFront.is_produced())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_EQ(8, network.phaseFront.product().gridU);
  EXPECT_EQ(8, network.phaseFront.product().gridV);
  EXPECT_EQ(64U, network.phaseFront.product().cells.size());
  EXPECT_GT(multi_edge_transition_count(network), 0U);
  for (const auto &cell : network.phaseFront.product().cells) {
    EXPECT_TRUE(cell.orientationValidated);
    for (const auto &path : cell.boundaryPaths) {
      ASSERT_FALSE(path.empty());
      for (const auto &segment : path) {
        for (const auto &step : segment.entryRoute.oriented_steps()) {
          EXPECT_EQ(directional::authority::TransitionStepKind::Interior,
                    step.kind());
          EXPECT_TRUE(step.interior().has_value());
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

  ASSERT_TRUE(forward.phaseFront.is_produced());
  ASSERT_TRUE(reverse.phaseFront.is_produced());
  EXPECT_EQ(forward.phaseFront.product().cells.size(), reverse.phaseFront.product().cells.size());
  EXPECT_EQ(forward.phaseFront.product().edges.size(), reverse.phaseFront.product().edges.size());
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

  EXPECT_FALSE(network.phaseFront.is_produced());
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                DuplicateTransitionMetadata,
            network.phaseFront.rejection_reason());
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
            guidance.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             guidance.phaseFront.rejection_reason());
  EXPECT_TRUE(guidance.phaseFront.is_produced());
  for (const auto &edge : guidance.phaseFront.product().edges) {
    EXPECT_GE(edge.filledSide, 0);
    EXPECT_LT(edge.filledSide, 4);
    EXPECT_NE(edge.boundaryKind,
              directional::geometry::SurfaceFrontBoundaryKind::
                  EmbeddedReliefCut);
    if (edge.oppositeEdge < 0) {
      EXPECT_EQ(edge.boundaryKind,
                directional::geometry::SurfaceFrontBoundaryKind::
                    GenuineSourceBoundary);
      EXPECT_TRUE(route_is_all_boundary(edge.route));
    }
  }
  const auto materialized =
      directional::pipeline::build_authoritative_phase_front_mesh(
          mesh.V, mesh.F, guidance.phaseFront.product());
  ASSERT_TRUE(materialized.success) << materialized.failure;
  EXPECT_EQ(materialized.connectedComponents, 1);
  EXPECT_EQ(materialized.boundaryLoopCount, 1);
  EXPECT_EQ(materialized.eulerCharacteristic, 1);
  EXPECT_EQ(materialized.consumedTopologyRegions,
            guidance.phaseFront.product().sourceTopologyRegions.regions().size());

  auto embeddedOptions = guidanceOptions;
  embeddedOptions.reliefBarriersEmbedded = true;
  const auto embedded = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, embeddedOptions);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            embedded.phaseFront.disposition());
  EXPECT_FALSE(embedded.phaseFront.is_produced());
  EXPECT_TRUE(embedded.seeds.empty());
  EXPECT_TRUE(embedded.traces.empty());
  EXPECT_TRUE(embedded.proposals.empty());
  ASSERT_EQ(1U, guidance.phaseFront.product().sourceTopologyRegions.regions().size());
  EXPECT_EQ(nullptr, embedded.phaseFront.produced_product());
  EXPECT_NE(embedded.phaseFront.rejection_reason(),
            directional::geometry::SurfacePhaseFrontFailureReason::None);
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_TRUE(network.phaseFront.is_produced());
  EXPECT_EQ(128U, network.phaseFront.product().cells.size());
  std::set<std::pair<int, int>> sheetKeys;
  for (const auto &cell : network.phaseFront.product().cells) {
    sheetKeys.emplace(phase_front_component(network.phaseFront, cell),
                     phase_front_single_sheet(network.phaseFront, cell).value_or(-1));
  }
  EXPECT_EQ((std::set<std::pair<int, int>>{{0, 0}, {1, 1}}), sheetKeys);
  for (const auto &edge : network.phaseFront.product().edges) {
    if (edge.oppositeEdge < 0) {
      continue;
    }
    ASSERT_LT(edge.oppositeEdge,
              static_cast<int>(network.phaseFront.product().edges.size()));
    const auto &opposite = network.phaseFront.product().edges[
        static_cast<std::size_t>(edge.oppositeEdge)];
    EXPECT_EQ(edge.sourceTopologyRegion, opposite.sourceTopologyRegion);
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
            forward.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition());
  EXPECT_EQ(forward.phaseFront.product().cells.size(), reverse.phaseFront.product().cells.size());
  EXPECT_EQ(forward.phaseFront.product().edges.size(), reverse.phaseFront.product().edges.size());
  EXPECT_EQ(forward.phaseFront.product().events.size(), reverse.phaseFront.product().events.size());
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_TRUE(!network.phaseFront.product().periodicHolonomies.empty());
  EXPECT_EQ(directional::authority::QuarterTurn{},
            network.phaseFront.product().periodicHolonomies.front().action.rotation);
  EXPECT_EQ(network.phaseFront.product().gridU,
            network.phaseFront.product().periodicHolonomies.front().action.shift.x);
  EXPECT_EQ(0, network.phaseFront.product().periodicHolonomies.front().action.shift.y);
  EXPECT_GT(network.phaseFront.product().gridU, 2);
  EXPECT_GT(network.phaseFront.product().gridV, 0);
  EXPECT_EQ(static_cast<std::size_t>(network.phaseFront.product().gridU *
                                     network.phaseFront.product().gridV),
            network.phaseFront.product().cells.size());
  EXPECT_TRUE(route_is_all_interior(
      network.phaseFront.product().periodicHolonomies.front().route));
  EXPECT_FALSE(network.phaseFront.product().periodicHolonomies.front().cutRoute.empty());
  int periodicEdgeCount = 0;
  for (const auto &edge : network.phaseFront.product().edges) {
    EXPECT_GE(edge.filledSide, 0);
    EXPECT_LT(edge.filledSide, 4);
    if (edge.boundaryKind ==
        directional::geometry::SurfaceFrontBoundaryKind::PeriodicCut) {
      ++periodicEdgeCount;
      ASSERT_TRUE(edge.periodicRelation.has_value());
      EXPECT_EQ(edge.periodicRelation->index(), 0U);
      EXPECT_GE(edge.oppositeEdge, 0);
      EXPECT_FALSE(edge.route.empty());
    }
  }
  EXPECT_GT(periodicEdgeCount, 0);
  const auto materialized =
      directional::pipeline::build_authoritative_phase_front_mesh(
          mesh.V, mesh.F, network.phaseFront.product());
  ASSERT_TRUE(materialized.success) << materialized.failure;
  EXPECT_EQ(materialized.connectedComponents, 1);
  EXPECT_EQ(materialized.boundaryLoopCount, 2);
  EXPECT_EQ(materialized.eulerCharacteristic, 0);
  EXPECT_EQ(materialized.consumedPeriodicHolonomies,
            network.phaseFront.product().periodicHolonomies.size());
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
            forward.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition());
  EXPECT_EQ(forward.phaseFront.product().gridU, reverse.phaseFront.product().gridU);
  EXPECT_EQ(forward.phaseFront.product().gridV, reverse.phaseFront.product().gridV);
  EXPECT_EQ(forward.phaseFront.product().periodicHolonomies.front().action,
            reverse.phaseFront.product().periodicHolonomies.front().action);
  const auto expectCanonicalCompactRoute = [](
      const directional::TriMesh &mesh, const std::vector<int> &sourceEdges,
      const std::vector<std::uint64_t> &sourceTopology) {
    ASSERT_EQ(sourceEdges.size(), sourceTopology.size());
    const auto sourceIncidence = directional::geometry::
        surface_cell_tracing_detail::edge_faces(mesh.F);
    const auto sourceWide = directional::geometry::
        surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
    for (std::size_t route = 0; route < sourceTopology.size(); ++route) {
      const auto expected = sourceWide.find(sourceTopology[route]);
      ASSERT_NE(expected, sourceWide.end());
      EXPECT_EQ(expected->second, sourceEdges[route]);
    }
  };
  const auto &forwardHolonomy = forward.phaseFront.product().periodicHolonomies.front();
  const auto &reverseHolonomy = reverse.phaseFront.product().periodicHolonomies.front();
  EXPECT_EQ(forwardHolonomy.route, reverseHolonomy.route);
  EXPECT_EQ(forwardHolonomy.cutRoute, reverseHolonomy.cutRoute);
  expectCanonicalCompactRoute(forwardMesh,
                              route_transition_ids(forwardHolonomy.route),
                              route_topology(forwardHolonomy.route));
  expectCanonicalCompactRoute(reverseMesh,
                              route_transition_ids(reverseHolonomy.route),
                              route_topology(reverseHolonomy.route));
  expectCanonicalCompactRoute(forwardMesh,
                              route_transition_ids(forwardHolonomy.cutRoute),
                              route_topology(forwardHolonomy.cutRoute));
  expectCanonicalCompactRoute(reverseMesh,
                              route_transition_ids(reverseHolonomy.cutRoute),
                              route_topology(reverseHolonomy.cutRoute));
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
            network.phaseFront.disposition());

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
  for (const auto &cell : network.phaseFront.product().cells) {
    for (int corner = 0; corner < 4; ++corner) {
      const auto &state = cell.lattice[static_cast<std::size_t>(corner)];
      if (state.latticeCoordinate.y() != 0 &&
          state.latticeCoordinate.y() != network.phaseFront.product().gridV) {
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());

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
  for (const auto &cell : network.phaseFront.product().cells) {
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());

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
  for (const auto &cell : network.phaseFront.product().cells) {
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
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                AmbiguousPeriodicRingCorrespondence,
            network.phaseFront.rejection_reason())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
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
            network.phaseFront.disposition());

  int periodicMergeCount = 0;
  for (const auto &event : network.phaseFront.product().events) {
    if (event.kind == directional::geometry::SurfaceFrontEventKind::PeriodicFrontMerge) {
      ++periodicMergeCount;
    }
  }
  EXPECT_EQ(network.phaseFront.product().gridV, periodicMergeCount);
  for (const auto &edge : network.phaseFront.product().edges) {
    const int fromU = edge.fromLattice.latticeCoordinate.x();
    const int toU = edge.toLattice.latticeCoordinate.x();
    const bool cutEdge = edge.family == 1 &&
        ((fromU == 0 && toU == 0) ||
         (fromU == network.phaseFront.product().gridU &&
          toU == network.phaseFront.product().gridU));
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

std::uint64_t phase_front_geometry_hash(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const directional::geometry::SurfaceCellNetwork &network) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto consume = [&](const long long value, std::uint64_t &state) {
    state ^= static_cast<std::uint64_t>(value);
    state *= 1099511628211ULL;
  };
  for (const auto &cell : network.phaseFront.product().cells) {
    consume(phase_front_component(network.phaseFront, cell), hash);
    consume(phase_front_single_sheet(network.phaseFront, cell).value_or(-1), hash);
    consume(cell.lattice[0].latticeCoordinate.x(), hash);
    consume(cell.lattice[0].latticeCoordinate.y(), hash);
    for (const auto &corner : cell.corners) {
      const Eigen::RowVector3d position =
          directional::geometry::surface_cell_tracing_detail::point_position(
              vertices, faces, corner);
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        consume(static_cast<long long>(
                    std::llround(position[coordinate] * 1.0e12)),
                hash);
      }
    }
  }
  return hash;
}

std::uint64_t curved_disk_phase_front_geometry_hash(
    const CurvedDiskFixture &fixture,
    const directional::geometry::SurfaceCellNetwork &network) {
  return phase_front_geometry_hash(fixture.vertices, fixture.faces, network);
}

CurvedDiskFixture make_curved_disk_with_adjacent_source_sheet(
    const bool reverseDiskFaceRows = false,
    const bool distinctSourceSheets = true) {
  CurvedDiskFixture fixture = make_curved_disk_fixture(reverseDiskFaceRows);
  const int diskFaceCount = fixture.faces.rows();
  const std::uint64_t sharedEdge =
      directional::pipeline::surface_cell_source_edge_key(0, 1);
  fixture.options.hardFeatureEdges.erase(sharedEdge);

  fixture.vertices.conservativeResize(11, 3);
  fixture.vertices.row(9) << 0.0, -0.5, 0.0;
  fixture.vertices.row(10) << 0.5, -0.5, 0.0;
  fixture.faces.conservativeResize(diskFaceCount + 2, 3);
  fixture.faces.row(diskFaceCount) << 9, 10, 1;
  fixture.faces.row(diskFaceCount + 1) << 9, 1, 0;

  fixture.faceAxisX.conservativeResize(fixture.faces.rows(), 3);
  fixture.faceAxisY.conservativeResize(fixture.faces.rows(), 3);
  for (int face = diskFaceCount; face < fixture.faces.rows(); ++face) {
    const Eigen::RowVector3d a =
        fixture.vertices.row(fixture.faces(face, 0));
    const Eigen::RowVector3d b =
        fixture.vertices.row(fixture.faces(face, 1));
    const Eigen::RowVector3d c =
        fixture.vertices.row(fixture.faces(face, 2));
    Eigen::RowVector3d normal = (b - a).cross(c - a);
    normal.normalize();
    Eigen::RowVector3d axisX(1.0, 0.0, 0.0);
    axisX -= axisX.dot(normal) * normal;
    axisX.normalize();
    Eigen::RowVector3d axisY = normal.cross(axisX);
    axisY.normalize();
    fixture.faceAxisX.row(face) = axisX;
    fixture.faceAxisY.row(face) = axisY;
  }

  fixture.targetSize = Eigen::VectorXd::Constant(fixture.vertices.rows(), 0.25);
  fixture.options.sourceFaceComponents.resize(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  fixture.options.sourceFaceSheets.resize(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  const int adjacentSheet = distinctSourceSheets ? 1 : 0;
  for (int face = diskFaceCount; face < fixture.faces.rows(); ++face) {
    fixture.options.sourceFaceComponents[static_cast<std::size_t>(face)] = 0;
    fixture.options.sourceFaceSheets[static_cast<std::size_t>(face)] =
        adjacentSheet;
  }
  return fixture;
}


struct TopologyRegionFixture {
  Eigen::MatrixXi faces;
  directional::geometry::SurfaceCellTracingOptions options;
};

TopologyRegionFixture make_split_isolation_annulus_fixture(
    const bool reverseFaceRows = false) {
  TopologyRegionFixture fixture;
  fixture.faces.resize(8, 3);
  fixture.faces << 0, 1, 5,
                   0, 5, 4,
                   1, 2, 6,
                   1, 6, 5,
                   2, 3, 7,
                   2, 7, 6,
                   3, 0, 4,
                   3, 4, 7;
  std::vector<int> sheets{0, 0, 0, 0, 1, 1, 1, 1};
  if (reverseFaceRows) {
    fixture.faces = fixture.faces.colwise().reverse().eval();
    std::reverse(sheets.begin(), sheets.end());
  }
  fixture.options.sourceFaceComponents.assign(8U, 0);
  fixture.options.sourceFaceSheets = std::move(sheets);
  return fixture;
}

CurvedDiskFixture make_polygonal_curved_disk_fixture(
    const bool reverseFaceRows = false) {
  CurvedDiskFixture fixture;
  fixture.vertices.resize(6, 3);
  fixture.vertices << 0.0, 0.0, 0.00,
                      1.0, 0.0, 0.02,
                      1.0, 0.5, 0.03,
                      0.5, 0.5, 0.02,
                      0.5, 1.0, 0.01,
                      0.0, 1.0, 0.02;
  fixture.faces.resize(4, 3);
  fixture.faces << 0, 1, 3,
                   1, 2, 3,
                   0, 3, 5,
                   3, 4, 5;
  if (reverseFaceRows) {
    fixture.faces = fixture.faces.colwise().reverse().eval();
  }

  fixture.faceAxisX.resize(fixture.faces.rows(), 3);
  fixture.faceAxisY.resize(fixture.faces.rows(), 3);
  for (int face = 0; face < fixture.faces.rows(); ++face) {
    const Eigen::RowVector3d a = fixture.vertices.row(fixture.faces(face, 0));
    const Eigen::RowVector3d b = fixture.vertices.row(fixture.faces(face, 1));
    const Eigen::RowVector3d c = fixture.vertices.row(fixture.faces(face, 2));
    Eigen::RowVector3d normal = (b - a).cross(c - a);
    normal.normalize();
    Eigen::RowVector3d axisX(1.0, 0.0, 0.0);
    axisX -= axisX.dot(normal) * normal;
    axisX.normalize();
    Eigen::RowVector3d axisY = normal.cross(axisX);
    axisY.normalize();
    fixture.faceAxisX.row(face) = axisX;
    fixture.faceAxisY.row(face) = axisY;
  }
  fixture.targetSize = Eigen::VectorXd::Constant(fixture.vertices.rows(), 0.25);
  fixture.options.sourceFaceComponents.assign(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  fixture.options.sourceFaceSheets.assign(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  for (const auto edge : std::array<std::array<int, 2>, 6>{{
           {{0, 1}}, {{1, 2}}, {{2, 3}},
           {{3, 4}}, {{4, 5}}, {{5, 0}}}}) {
    fixture.options.hardFeatureEdges.insert(
        directional::pipeline::surface_cell_source_edge_key(edge[0], edge[1]));
  }
  return fixture;
}

CurvedDiskFixture make_invalid_boundary_turn_disk_fixture() {
  CurvedDiskFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 0.00,
                      1.0, 0.0, 0.02,
                      0.1, 0.2, 0.03,
                      0.0, 1.0, 0.01;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3;
  fixture.faceAxisX.resize(fixture.faces.rows(), 3);
  fixture.faceAxisY.resize(fixture.faces.rows(), 3);
  for (int face = 0; face < fixture.faces.rows(); ++face) {
    const Eigen::RowVector3d a = fixture.vertices.row(fixture.faces(face, 0));
    const Eigen::RowVector3d b = fixture.vertices.row(fixture.faces(face, 1));
    const Eigen::RowVector3d c = fixture.vertices.row(fixture.faces(face, 2));
    Eigen::RowVector3d normal = (b - a).cross(c - a);
    normal.normalize();
    Eigen::RowVector3d axisX(1.0, 0.0, 0.0);
    axisX -= axisX.dot(normal) * normal;
    axisX.normalize();
    Eigen::RowVector3d axisY = normal.cross(axisX);
    axisY.normalize();
    fixture.faceAxisX.row(face) = axisX;
    fixture.faceAxisY.row(face) = axisY;
  }
  fixture.targetSize = Eigen::VectorXd::Constant(fixture.vertices.rows(), 0.25);
  fixture.options.sourceFaceComponents.assign(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  fixture.options.sourceFaceSheets.assign(
      static_cast<std::size_t>(fixture.faces.rows()), 0);
  for (const auto edge : std::array<std::array<int, 2>, 4>{{
           {{0, 1}}, {{1, 2}}, {{2, 3}}, {{3, 0}}}}) {
    fixture.options.hardFeatureEdges.insert(
        directional::pipeline::surface_cell_source_edge_key(edge[0], edge[1]));
  }
  return fixture;
}

TEST(SurfaceCellsPhase10,
     ExistingRectangularCurvedDiskRetainsExactBoundaryPhaseFastPath) {
  const CurvedDiskFixture fixture = make_curved_disk_fixture();
  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.targetSize, fixture.options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_NE(nullptr, network.phaseFront.produced_product());
  ASSERT_EQ(1U, network.phaseFront.product().boundedDiskBoundaryPhases.size());
  const auto &phase = network.phaseFront.product().boundedDiskBoundaryPhases.front();
  EXPECT_TRUE(phase.rectangular);
  EXPECT_TRUE(phase.polygonClosed);
  EXPECT_TRUE(phase.chartConstructed);
  EXPECT_EQ(4, phase.signedQuarterTurnSum);
  ASSERT_EQ(4U, phase.runs.size());
  EXPECT_NE(0U, phase.structuralHash);
  for (const auto &run : phase.runs) {
    EXPECT_EQ(1, run.signedQuarterTurnToNext);
    EXPECT_GT(run.intrinsicLength, 0.0);
    EXPECT_FALSE(run.sourceEdgeTopology.empty());
  }
}

TEST(SurfaceCellsPhase10,
     PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase) {
  const CurvedDiskFixture fixture = make_polygonal_curved_disk_fixture();
  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.targetSize, fixture.options);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskFrontPairing,
            network.phaseFront.rejection_reason())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_EQ(nullptr, network.phaseFront.produced_product())
      << "rejected producer outcomes must not expose partial phase authority";
}

TEST(SurfaceCellsPhase10,
     PolygonalCurvedDiskInvalidCyclicFieldTurnFailsClosed) {
  const CurvedDiskFixture fixture = make_invalid_boundary_turn_disk_fixture();
  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.targetSize, fixture.options);

  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskBoundaryTurn,
            network.phaseFront.rejection_reason())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_EQ(nullptr, network.phaseFront.produced_product());
}

TEST(SurfaceCellsPhase10,
     PolygonalCurvedDiskRejectionIsInvariantToFaceRowEnumeration) {
  const CurvedDiskFixture forward = make_polygonal_curved_disk_fixture(false);
  const CurvedDiskFixture reversed = make_polygonal_curved_disk_fixture(true);
  const auto forwardNetwork = directional::geometry::build_surface_cell_network(
      forward.vertices, forward.faces, forward.faceAxisX, forward.faceAxisY,
      forward.targetSize, forward.options);
  const auto reversedNetwork = directional::geometry::build_surface_cell_network(
      reversed.vertices, reversed.faces, reversed.faceAxisX, reversed.faceAxisY,
      reversed.targetSize, reversed.options);

  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            forwardNetwork.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            reversedNetwork.phaseFront.disposition());
  EXPECT_EQ(forwardNetwork.phaseFront.rejection_reason(),
            reversedNetwork.phaseFront.rejection_reason());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskFrontPairing,
            forwardNetwork.phaseFront.rejection_reason());
  EXPECT_EQ(nullptr, forwardNetwork.phaseFront.produced_product());
  EXPECT_EQ(nullptr, reversedNetwork.phaseFront.produced_product());
}

TEST(SurfaceCellsPhase10,
     ExactAdjacentCrossSheetEdgeIsInternalTopologyRegionIsolationSeam) {
  const CurvedDiskFixture fixture =
      make_curved_disk_with_adjacent_source_sheet(false, true);
  const std::uint64_t sharedEdge =
      directional::pipeline::surface_cell_source_edge_key(0, 1);
  ASSERT_EQ(0U, fixture.options.hardFeatureEdges.count(sharedEdge));

  const auto fullIncident =
      directional::geometry::surface_cell_tracing_detail::edge_faces(fixture.faces);
  const auto found = fullIncident.find(sharedEdge);
  ASSERT_NE(fullIncident.end(), found);
  ASSERT_GE(found->second[0], 0);
  ASSERT_GE(found->second[1], 0);
  const auto topology =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(fixture.faces, fixture.options);
  ASSERT_TRUE(topology.has_value());
  directional::geometry::SurfaceCellTracingOptions typedOptions = fixture.options;
  typedOptions.sourceFaceComponents.clear();
  typedOptions.sourceFaceSheets.clear();
  typedOptions.sourceAuthority = &*topology;
  ASSERT_FALSE(directional::geometry::surface_cell_tracing_detail::
                   source_faces_compatible(typedOptions, found->second[0],
                                           found->second[1]));
  ASSERT_EQ(1U, topology->regions().size());
  const auto &region = topology->regions().front();
  EXPECT_EQ(1, region.euler_characteristic());
  EXPECT_EQ(1, region.boundary_loop_count());
  ASSERT_EQ(2U, topology_region_sheets(region).size());
  const auto firstVertex = directional::authority::SourceVertexId::from_index(
      0, static_cast<std::size_t>(fixture.vertices.rows()));
  const auto secondVertex = directional::authority::SourceVertexId::from_index(
      1, static_cast<std::size_t>(fixture.vertices.rows()));
  ASSERT_TRUE(firstVertex);
  ASSERT_TRUE(secondVertex);
  const auto typedSharedEdge = directional::authority::SourceEdgeTopologyKey::make(
      firstVertex.value(), secondVertex.value());
  ASSERT_TRUE(typedSharedEdge);
  EXPECT_TRUE(std::binary_search(region.isolation_seams().begin(),
                                 region.isolation_seams().end(),
                                 typedSharedEdge.value()));
  EXPECT_FALSE(
      directional::geometry::surface_cell_tracing_detail::
          source_edge_is_authoritative_local_boundary(
              typedOptions, fixture.faces.rows(), found->second[0],
              found->second, sharedEdge));
}

TEST(SurfaceCellsPhase10,
     SameSheetInternalEdgeIsNeitherBoundaryNorIsolationSeam) {
  const CurvedDiskFixture fixture =
      make_curved_disk_with_adjacent_source_sheet(false, false);
  const std::uint64_t sharedEdge =
      directional::pipeline::surface_cell_source_edge_key(0, 1);
  const auto fullIncident =
      directional::geometry::surface_cell_tracing_detail::edge_faces(fixture.faces);
  const auto found = fullIncident.find(sharedEdge);
  ASSERT_NE(fullIncident.end(), found);
  ASSERT_GE(found->second[0], 0);
  ASSERT_GE(found->second[1], 0);
  const auto topology =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(fixture.faces, fixture.options);
  ASSERT_TRUE(topology.has_value());
  directional::geometry::SurfaceCellTracingOptions typedOptions = fixture.options;
  typedOptions.sourceFaceComponents.clear();
  typedOptions.sourceFaceSheets.clear();
  typedOptions.sourceAuthority = &*topology;
  ASSERT_TRUE(directional::geometry::surface_cell_tracing_detail::
                  source_faces_compatible(typedOptions, found->second[0],
                                          found->second[1]));
  ASSERT_EQ(1U, topology->regions().size());
  EXPECT_FALSE(
      directional::geometry::surface_cell_tracing_detail::
          source_edge_is_authoritative_local_boundary(
              typedOptions, fixture.faces.rows(), found->second[0],
              found->second, sharedEdge));
}

TEST(SurfaceCellsPhase10,
     TopologyRegionIsolationSeamIsInvariantToFaceRowEnumeration) {
  const CurvedDiskFixture forward =
      make_curved_disk_with_adjacent_source_sheet(false, true);
  const CurvedDiskFixture reversed =
      make_curved_disk_with_adjacent_source_sheet(true, true);
  const auto forwardTopology =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(forward.faces, forward.options);
  const auto reversedTopology =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(reversed.faces, reversed.options);
  ASSERT_TRUE(forwardTopology.has_value());
  ASSERT_TRUE(reversedTopology.has_value());
  ASSERT_EQ(1U, forwardTopology->regions().size());
  ASSERT_EQ(1U, reversedTopology->regions().size());
  const auto &a = forwardTopology->regions().front();
  const auto &b = reversedTopology->regions().front();
  EXPECT_EQ(a.euler_characteristic(), b.euler_characteristic());
  EXPECT_EQ(a.boundary_loop_count(), b.boundary_loop_count());
  EXPECT_EQ(topology_region_sheets(a), topology_region_sheets(b));
  EXPECT_EQ(a.boundary_edges(), b.boundary_edges());
  EXPECT_EQ(a.isolation_seams(), b.isolation_seams());
  EXPECT_EQ(directional::geometry::surface_topology_region_hash(a),
            directional::geometry::surface_topology_region_hash(b));
}

TEST(SurfaceCellsPhase10,
     ClassifierSplitAnnulusRemainsOneSourceTopologyRegion) {
  const TopologyRegionFixture fixture = make_split_isolation_annulus_fixture();
  const auto topology =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(fixture.faces, fixture.options);
  ASSERT_TRUE(topology.has_value());
  ASSERT_EQ(1U, topology->regions().size());
  const auto &region = topology->regions().front();
  EXPECT_EQ(0, region.euler_characteristic());
  EXPECT_EQ(2, region.boundary_loop_count());
  ASSERT_EQ(2U, topology_region_sheets(region).size());
  EXPECT_FALSE(region.isolation_seams().empty());
  EXPECT_NE(0U, directional::geometry::surface_topology_region_hash(region));
}

TEST(SurfaceCellsPhase10,
     ClassifierSplitAnnulusTopologyRegionIsRowOrderInvariant) {
  const TopologyRegionFixture forward = make_split_isolation_annulus_fixture(false);
  const TopologyRegionFixture reversed = make_split_isolation_annulus_fixture(true);
  const auto a = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(forward.faces, forward.options);
  const auto b = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(reversed.faces, reversed.options);
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  ASSERT_EQ(1U, a->regions().size());
  ASSERT_EQ(1U, b->regions().size());
  EXPECT_EQ(a->regions().front().euler_characteristic(),
            b->regions().front().euler_characteristic());
  EXPECT_EQ(a->regions().front().boundary_loop_count(),
            b->regions().front().boundary_loop_count());
  EXPECT_EQ(a->regions().front().boundary_edges(),
            b->regions().front().boundary_edges());
  EXPECT_EQ(a->regions().front().isolation_seams(),
            b->regions().front().isolation_seams());
  EXPECT_EQ(directional::geometry::surface_topology_region_hash(
                a->regions().front()),
            directional::geometry::surface_topology_region_hash(
                b->regions().front()));
}

TEST(SurfaceCellsPhase10,
     HardFeatureCannotBeReinterpretedAsInternalIsolationSeam) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};
  const std::uint64_t sharedEdge =
      directional::pipeline::surface_cell_source_edge_key(0, 2);
  options.hardFeatureEdges.insert(sharedEdge);
  const auto topology = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, options);
  ASSERT_TRUE(topology.has_value());
  ASSERT_EQ(2U, topology->regions().size());
}

TEST(SurfaceCellsPhase10,
     HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              2.0, 0.0, 0.0,
              0.0, 1.0, 0.0,
              1.0, 1.0, 0.0,
              2.0, 1.0, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4,
           0, 4, 3,
           1, 2, 5,
           1, 5, 4;
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(faces.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.5;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(faces.rows()),
                                      0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(faces.rows()), 0);
  options.hardFeatureEdges.insert(
      directional::pipeline::surface_cell_source_edge_key(1, 4));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(vertices.rows(), 0.5);

  const auto network = directional::geometry::build_surface_cell_network(
      vertices, faces, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  int hardEdges = 0;
  int hardMerges = 0;
  for (const auto &edge : network.phaseFront.product().edges) {
    if (edge.boundaryKind !=
        directional::geometry::SurfaceFrontBoundaryKind::HardRail) {
      continue;
    }
    ++hardEdges;
    ASSERT_GE(edge.oppositeEdge, 0);
    EXPECT_FALSE(edge.exterior);
    EXPECT_TRUE(route_is_all_interior(edge.route));
    const auto &opposite = network.phaseFront.product().edges[static_cast<std::size_t>(
        edge.oppositeEdge)];
    EXPECT_EQ(opposite.oppositeEdge,
              static_cast<int>(&edge - network.phaseFront.product().edges.data()));
    EXPECT_NE(edge.sourceTopologyRegion, opposite.sourceTopologyRegion);
  }
  for (const auto &event : network.phaseFront.product().events) {
    hardMerges += event.kind ==
                      directional::geometry::SurfaceFrontEventKind::
                          HardRailMerge
                      ? 1
                      : 0;
  }
  EXPECT_GT(hardEdges, 0);
  EXPECT_EQ(hardEdges, hardMerges * 2);

  const auto materialized =
      directional::pipeline::build_authoritative_phase_front_mesh(
          vertices, faces, network.phaseFront.product());
  ASSERT_TRUE(materialized.success) << materialized.failure;
  EXPECT_EQ(materialized.connectedComponents, 1);
  EXPECT_EQ(materialized.boundaryLoopCount, 1);
  EXPECT_EQ(materialized.eulerCharacteristic, 1);
  EXPECT_EQ(materialized.consumedTopologyRegions, 2U);
}

TEST(SurfaceCellsPhase10,
     SourceDisconnectedCloseSheetsRemainSeparateTopologyRegions) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           3, 4, 5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 1};
  options.sourceFaceSheets = {0, 1};
  const auto topology = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, options);
  ASSERT_TRUE(topology.has_value());
  ASSERT_EQ(2U, topology->regions().size());
  const auto firstRow = directional::authority::SourceFaceId::from_index(
      0, topology->face_count());
  const auto secondRow = directional::authority::SourceFaceId::from_index(
      1, topology->face_count());
  ASSERT_TRUE(firstRow);
  ASSERT_TRUE(secondRow);
  EXPECT_NE(topology->region_for_row(firstRow.value()),
            topology->region_for_row(secondRow.value()));
}

TEST(SurfaceCellsPhase10,
     ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  Eigen::MatrixXd raw(2, 12);
  for (int face = 0; face < 2; ++face) {
    raw.row(face) << 1.0, 0.0, 0.0,
                     0.0, 1.0, 0.0,
                    -1.0, 0.0, 0.0,
                     0.0,-1.0, 0.0;
  }
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, raw);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(4, 0.5);
  const auto network = directional::geometry::build_surface_cell_network(
      vertices, faces, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  EXPECT_FALSE(network.phaseFront.product().sourceTopologyRegions.regions().front()
                   .isolation_seams().empty());
  ASSERT_EQ(1U,
            network.phaseFront.product().isolationSeamTransportCertificates.size());
  const auto &certificate =
      network.phaseFront.product().isolationSeamTransportCertificates.front();
  EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions.regions().front().id(),
            certificate.region);
  EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions.regions().front()
                .isolation_seams().front(),
            certificate.seam);
  EXPECT_LT(certificate.transition.index(),
            static_cast<std::size_t>(crossField.matching.size()));
  EXPECT_NE(certificate.firstSheet, certificate.secondSheet);
  EXPECT_EQ(certificate.forward.inverse(), certificate.reverse);
  EXPECT_NE(0U, directional::geometry::surface_cell_tracing_detail::
                    isolation_seam_transport_certificate_hash(certificate));
  bool sawCrossSheetScope = false;
  for (const auto &cell : network.phaseFront.product().cells) {
    sawCrossSheetScope |=
        topology_region_sheets(phase_front_region(network.phaseFront, cell)).size() > 1U;
    EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions.regions().front().id(),
              cell.sourceTopologyRegion);
  }
  EXPECT_TRUE(sawCrossSheetScope);
  const auto materialized =
      directional::pipeline::build_authoritative_phase_front_mesh(
          vertices, faces, network.phaseFront.product());
  ASSERT_TRUE(materialized.success) << materialized.failure;
  EXPECT_EQ(network.phaseFront.product().isolationSeamTransportCertificates.size(),
            materialized.consumedInternalIsolationSeams);
  EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions.regions().size(),
            materialized.consumedTopologyRegions);
  EXPECT_EQ(1, materialized.connectedComponents);
  EXPECT_EQ(1, materialized.boundaryLoopCount);
  EXPECT_EQ(1, materialized.eulerCharacteristic);
}

TEST(SurfaceCellsPhase10,
     NonReciprocalSourceAdjacentIsolationSeamFailsClosed) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  Eigen::MatrixXd raw(2, 12);
  for (int face = 0; face < 2; ++face) {
    raw.row(face) << 1.0, 0.0, 0.0,
                     0.0, 1.0, 0.0,
                    -1.0, 0.0, 0.0,
                     0.0,-1.0, 0.0;
  }
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, raw);
  auto transition = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [](const auto &candidate) {
        return candidate.firstFace >= 0 && candidate.secondFace >= 0;
      });
  ASSERT_NE(crossField.edgeTransitions.end(), transition);
  transition->matching += 1;
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(4, 0.5);
  const auto network = directional::geometry::build_surface_cell_network(
      vertices, faces, crossField, targetSize, options);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidTopologyRegionTransport,
            network.phaseFront.rejection_reason())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_EQ(nullptr, network.phaseFront.produced_product());
}

TEST(SurfaceCellsPhase10, CurvedBoundedDiskPhaseFrontIsStructurallyApplicable) {
  const CurvedDiskFixture fixture = make_curved_disk_fixture();
  const auto network = directional::geometry::build_surface_cell_network(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.targetSize, fixture.options);

  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::
                UnsupportedSourceSheetTopology,
            network.phaseFront.rejection_reason());
  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::NonPlanarSource,
            network.phaseFront.rejection_reason());
  if (network.phaseFront.disposition() ==
      directional::geometry::SurfaceCellProducerDisposition::Rejected) {
    EXPECT_TRUE(
        network.phaseFront.rejection_reason() ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskTransport ||
        network.phaseFront.rejection_reason() ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskBoundaryPhase ||
        network.phaseFront.rejection_reason() ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskChart ||
        network.phaseFront.rejection_reason() ==
            directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskFrontPairing)
        << directional::geometry::surface_phase_front_failure_reason_name(
               network.phaseFront.rejection_reason());
  } else {
    EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
              network.phaseFront.disposition());
    EXPECT_TRUE(network.phaseFront.is_produced());
    EXPECT_FALSE(network.phaseFront.product().cells.empty());
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

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forwardNetwork.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reversedNetwork.phaseFront.disposition());
  EXPECT_EQ(forwardNetwork.phaseFront.product().gridU,
            reversedNetwork.phaseFront.product().gridU);
  EXPECT_EQ(forwardNetwork.phaseFront.product().gridV, reversedNetwork.phaseFront.product().gridV);
  EXPECT_EQ(forwardNetwork.phaseFront.product().cells.size(),
            reversedNetwork.phaseFront.product().cells.size());
  if (forwardNetwork.phaseFront.disposition() ==
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_EQ(1U, network.phaseFront.product().boundedDiskBoundaryPhases.size());
  bool sawHardFeatureAuthority = false;
  for (const auto &run :
       network.phaseFront.product().boundedDiskBoundaryPhases.front().runs) {
    for (const auto &authority : run.edgeAuthority) {
      sawHardFeatureAuthority |= authority.hardFeature;
    }
  }
  EXPECT_TRUE(sawHardFeatureAuthority);

  std::size_t exteriorCount = 0;
  for (const auto &edge : network.phaseFront.product().edges) {
    if (!edge.exterior) continue;
    ++exteriorCount;
    ASSERT_LT(edge.filledCell.index(),
              network.phaseFront.product().cells.size());
    const auto &cell =
        network.phaseFront.product().cells[edge.filledCell.index()];
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
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskTransport,
            network.phaseFront.rejection_reason())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_EQ(nullptr, network.phaseFront.produced_product());
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());

  std::map<std::pair<int, int>, int> cellsBySheet;
  for (const auto &cell : network.phaseFront.product().cells) {
    ++cellsBySheet[{phase_front_component(network.phaseFront, cell),
                    phase_front_single_sheet(network.phaseFront, cell).value_or(-1)}];
  }
  ASSERT_EQ(3U, cellsBySheet.size());
  EXPECT_GT((cellsBySheet[std::pair<int, int>{0, 0}]), 0);
  EXPECT_GT((cellsBySheet[std::pair<int, int>{1, 1}]), 0);
  EXPECT_GT((cellsBySheet[std::pair<int, int>{2, 2}]), 0);
  ASSERT_EQ(1U, network.phaseFront.product().periodicHolonomies.size());
  EXPECT_EQ(1, phase_front_single_sheet(
                   network.phaseFront,
                   network.phaseFront.product().periodicHolonomies.front()).value_or(-1));
}

TEST(SurfaceCellsPhase10,
     PolygonalCurvedDiskRetainsPeriodicAuthorityWithoutPartialSheetCells) {
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
  const CurvedDiskFixture disk = make_polygonal_curved_disk_fixture();
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
    const int sheet = face < planeFaces
                          ? 0
                          : (face < planeFaces + cylinderFaces ? 1 : 2);
    options.sourceFaceComponents[static_cast<std::size_t>(face)] = sheet;
    options.sourceFaceSheets[static_cast<std::size_t>(face)] = sheet;
  }
  const int diskOffset = planeVertices + cylinderVertices;
  for (const auto edge : std::array<std::array<int, 2>, 6>{{
           {{0, 1}}, {{1, 2}}, {{2, 3}},
           {{3, 4}}, {{4, 5}}, {{5, 0}}}}) {
    options.hardFeatureEdges.insert(
        directional::pipeline::surface_cell_source_edge_key(
            diskOffset + edge[0], diskOffset + edge[1]));
  }
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(vertices.rows(), 0.25);
  const auto network = directional::geometry::build_surface_cell_network(
      vertices, faces, crossField, targetSize, options);

  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            network.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                InvalidBoundedDiskFrontPairing,
            network.phaseFront.rejection_reason())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_EQ(nullptr, network.phaseFront.produced_product())
      << "rejected producer outcomes must not expose partial authority";

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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_TRUE(network.phaseFront.is_produced());
  ASSERT_EQ(1U, network.phaseFront.product().periodicHolonomies.size());
  EXPECT_EQ(1, phase_front_component(
                   network.phaseFront,
                   network.phaseFront.product().periodicHolonomies.front()));
  EXPECT_EQ(1, phase_front_single_sheet(
                   network.phaseFront,
                   network.phaseFront.product().periodicHolonomies.front()).value_or(-1));

  std::map<std::pair<int, int>, int> cellsBySheet;
  for (const auto &cell : network.phaseFront.product().cells) {
    ++cellsBySheet[{phase_front_component(network.phaseFront, cell),
                    phase_front_single_sheet(network.phaseFront, cell).value_or(-1)}];
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
              network.phaseFront.disposition());
    EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                  UnsupportedSourceSheetTopology,
              network.phaseFront.rejection_reason())
        << directional::geometry::surface_phase_front_failure_reason_name(
               network.phaseFront.rejection_reason());
    EXPECT_FALSE(network.phaseFront.is_produced());
    EXPECT_EQ(nullptr, network.phaseFront.produced_product());
    ASSERT_GE(phase_front_rejection(network.phaseFront).face, 0);
    ASSERT_LT(phase_front_rejection(network.phaseFront).face,
              static_cast<int>(options.sourceFaceSheets.size()));
    EXPECT_EQ(1, options.sourceFaceComponents[
                     static_cast<std::size_t>(phase_front_rejection(network.phaseFront).face)]);
    EXPECT_EQ(1, options.sourceFaceSheets[
                     static_cast<std::size_t>(phase_front_rejection(network.phaseFront).face)]);
  }
}

directional::authority::TopologyRegionId test_topology_region(const int value) {
  const auto id = directional::authority::TopologyRegionId::from_index(value, 64);
  if (!id) throw std::runtime_error("Invalid test topology-region id.");
  return id.value();
}

directional::authority::CanonicalRoute test_interior_route(
    std::initializer_list<std::array<int, 3>> steps) {
  std::vector<directional::authority::TransitionStep> observed;
  observed.reserve(steps.size());
  for (const auto &step : steps) {
    const auto first = directional::authority::SourceVertexId::from_index(step[0], 4096);
    const auto second = directional::authority::SourceVertexId::from_index(step[1], 4096);
    const auto transition =
        directional::authority::InteriorTransitionId::from_index(step[2], 4096);
    if (!first || !second || !transition) {
      throw std::runtime_error("Invalid test route authority.");
    }
    const auto topology = directional::authority::SourceEdgeTopologyKey::make(
        first.value(), second.value());
    if (!topology) throw std::runtime_error("Degenerate test route topology.");
    const auto typedStep = directional::authority::TransitionStep::interior(
        topology.value(), transition.value(),
        directional::authority::GridAutomorphism::identity(),
        directional::authority::Orientation::Forward);
    if (!typedStep) throw std::runtime_error("Invalid test route step.");
    observed.push_back(typedStep.value());
  }
  return directional::authority::CanonicalRoute::from_observed_steps(
      std::move(observed));
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  SurfacePeriodicHolonomy forward(test_topology_region(2));
  forward.action = {directional::authority::QuarterTurn{}, {8, 0}};
  forward.route = test_interior_route({{0, 1, 4}, {1, 2, 6},
                                      {2, 3, 8}, {3, 4, 10}});
  forward.cutRoute = test_interior_route({{4, 5, 12}, {5, 6, 14}});

  SurfacePeriodicHolonomy reverse = forward;
  reverse.action = forward.action.inverse();
  reverse.route = forward.route.reversed();
  reverse.cutRoute = forward.cutRoute.reversed();

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, forward));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Equivalent,
            insert_periodic_holonomy(relations, reverse));
  ASSERT_EQ(1U, relations.size());
  EXPECT_EQ(8, relations.front().action.shift.x);
  EXPECT_EQ(0, relations.front().action.shift.y);
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  const auto makeRelation = [](const int region, const int routeBase) {
    SurfacePeriodicHolonomy relation(test_topology_region(region));
    relation.action = {directional::authority::QuarterTurn{}, {6, 0}};
    relation.route = test_interior_route(
        {{routeBase, routeBase + 1, routeBase + 10}});
    relation.cutRoute = test_interior_route(
        {{routeBase + 2, routeBase + 3, routeBase + 11}});
    return relation;
  };

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, makeRelation(3, 30)));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, makeRelation(1, 10)));
  ASSERT_EQ(2U, relations.size());
  EXPECT_EQ(test_topology_region(1), relations[0].sourceTopologyRegion);
  EXPECT_EQ(test_topology_region(3), relations[1].sourceTopologyRegion);
}

TEST(SurfaceCellsPhase10,
     PeriodicHolonomySameRegionDependentBasisFailsClosedWithoutOrderChoice) {
  using directional::geometry::SurfacePeriodicHolonomy;
  using directional::geometry::SurfacePeriodicHolonomyInsertStatus;
  using directional::geometry::surface_cell_tracing_detail::insert_periodic_holonomy;

  const auto makeRelation = [](const int base) {
    SurfacePeriodicHolonomy relation(test_topology_region(0));
    relation.action = {directional::authority::QuarterTurn{}, {4, 0}};
    relation.route = test_interior_route({{base, base + 1, base + 10}});
    relation.cutRoute = test_interior_route({{base + 2, base + 3, base + 11}});
    return relation;
  };

  for (const bool reversed : {false, true}) {
    std::vector<SurfacePeriodicHolonomy> relations;
    auto first = makeRelation(1);
    auto second = makeRelation(5);
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

  SurfacePeriodicHolonomy first(test_topology_region(0));
  first.action = {directional::authority::QuarterTurn{}, {4, 0}};
  first.route = test_interior_route({{0, 1, 1}, {1, 2, 2}});
  first.cutRoute = test_interior_route({{2, 3, 3}});
  SurfacePeriodicHolonomy conflicting = first;
  conflicting.action = {directional::authority::QuarterTurn::from_integer(1),
                        {0, 4}};

  std::vector<SurfacePeriodicHolonomy> relations;
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Inserted,
            insert_periodic_holonomy(relations, first));
  EXPECT_EQ(SurfacePeriodicHolonomyInsertStatus::Incompatible,
            insert_periodic_holonomy(relations, conflicting));
}

struct PeriodicHolonomyRouteStep {
  int sourceFace = -1;
  int targetFace = -1;
  std::uint64_t topology = 0;
  std::uint64_t semanticTopology = 0;
};

struct PeriodicHolonomyRouteFixture {
  directional::TriMesh mesh;
  Eigen::MatrixXd rawField;
  directional::fields::CrossFieldResult authoritativeField;
  std::vector<PeriodicHolonomyRouteStep> expectedRoute;
};

std::vector<std::vector<int>> periodic_cylinder_vertex_rings() {
  return {
      {0, 1, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30},
      {3, 2, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31},
      {33, 32, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47},
      {49, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},
      {65, 64, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79}};
}

PeriodicHolonomyRouteStep periodic_route_step(
    const int sourceFace, const int targetFace, const int firstVertex,
    const int secondVertex, const int semanticFirstVertex,
    const int semanticSecondVertex) {
  return {
      sourceFace,
      targetFace,
      directional::pipeline::surface_cell_source_edge_key(firstVertex,
                                                           secondVertex),
      directional::pipeline::surface_cell_source_edge_key(
          semanticFirstVertex, semanticSecondVertex)};
}

std::vector<PeriodicHolonomyRouteStep> expected_forward_periodic_route() {
  const auto rings = periodic_cylinder_vertex_rings();
  const auto &bottom = rings[0];
  const auto &top = rings[1];
  std::vector<PeriodicHolonomyRouteStep> route;
  route.reserve(32);
  const auto append = [&](const int sourceFace, const int targetFace,
                          const int firstVertex, const int secondVertex) {
    route.push_back(periodic_route_step(
        sourceFace, targetFace, firstVertex, secondVertex, firstVertex,
        secondVertex));
  };

  append(0, 1, bottom[0], top[1]);
  append(1, 30, bottom[0], top[0]);
  for (int strip = 15; strip >= 1; --strip) {
    append(2 * strip, 2 * strip + 1, bottom[strip],
           top[(strip + 1) % 16]);
    append(2 * strip + 1, 2 * (strip - 1), bottom[strip], top[strip]);
  }
  return route;
}

PeriodicHolonomyRouteFixture make_periodic_holonomy_route_fixture() {
  PeriodicHolonomyRouteFixture fixture;
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  if (!directional::readOBJ(meshPath.string(), fixture.mesh)) {
    throw std::runtime_error("Could not load the committed cylinder fixture.");
  }
  fixture.rawField =
      read_rawfield_fixture(fieldPath, fixture.mesh.F.rows());
  fixture.authoritativeField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, fixture.rawField);
  fixture.expectedRoute = expected_forward_periodic_route();
  return fixture;
}

PeriodicHolonomyRouteFixture reflect_periodic_holonomy_route_fixture(
    const PeriodicHolonomyRouteFixture &source) {
  const auto rings = periodic_cylinder_vertex_rings();
  std::vector<int> oldToNew(static_cast<std::size_t>(source.mesh.V.rows()), -1);
  Eigen::MatrixXd vertices = source.mesh.V;
  for (const auto &ring : rings) {
    for (int position = 0; position < 16; ++position) {
      const int oldVertex = ring[static_cast<std::size_t>(position)];
      const int newVertex =
          ring[static_cast<std::size_t>((16 - position) % 16)];
      oldToNew[static_cast<std::size_t>(oldVertex)] = newVertex;
      vertices.row(newVertex) = source.mesh.V.row(oldVertex);
    }
  }
  if (std::find(oldToNew.begin(), oldToNew.end(), -1) != oldToNew.end()) {
    throw std::runtime_error("Incomplete reflected cylinder vertex authority.");
  }

  Eigen::MatrixXi faces = source.mesh.F;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      faces(face, corner) =
          oldToNew[static_cast<std::size_t>(source.mesh.F(face, corner))];
    }
  }

  PeriodicHolonomyRouteFixture reflected;
  reflected.mesh.set_mesh(vertices, faces);
  reflected.rawField = source.rawField;
  reflected.authoritativeField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reflected.mesh, reflected.rawField);

  const auto &bottom = rings[0];
  const auto &top = rings[1];
  const auto append = [&](const int sourceFace, const int targetFace,
                          const int oldFirstVertex,
                          const int oldSecondVertex) {
    reflected.expectedRoute.push_back(periodic_route_step(
        sourceFace, targetFace,
        oldToNew[static_cast<std::size_t>(oldFirstVertex)],
        oldToNew[static_cast<std::size_t>(oldSecondVertex)], oldFirstVertex,
        oldSecondVertex));
  };
  reflected.expectedRoute.reserve(32);
  append(30, 1, bottom[0], top[0]);
  for (int strip = 0; strip <= 14; ++strip) {
    append(2 * strip + 1, 2 * strip, bottom[strip],
           top[(strip + 1) % 16]);
    append(2 * strip, 2 * (strip + 1) + 1, bottom[strip + 1],
           top[strip + 1]);
  }
  append(31, 30, bottom[15], top[0]);
  return reflected;
}

PeriodicHolonomyRouteFixture reorder_periodic_holonomy_faces(
    const PeriodicHolonomyRouteFixture &source) {
  PeriodicHolonomyRouteFixture reordered;
  const int faceCount = source.mesh.F.rows();
  Eigen::MatrixXi faces(faceCount, 3);
  reordered.rawField.resize(source.rawField.rows(), source.rawField.cols());
  std::vector<int> oldToNewFace(static_cast<std::size_t>(faceCount), -1);
  for (int oldFace = 0; oldFace < faceCount; ++oldFace) {
    const int newFace = faceCount - 1 - oldFace;
    oldToNewFace[static_cast<std::size_t>(oldFace)] = newFace;
    faces.row(newFace) = source.mesh.F.row(oldFace);
    reordered.rawField.row(newFace) = source.rawField.row(oldFace);
  }
  reordered.mesh.set_mesh(source.mesh.V, faces);
  reordered.authoritativeField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reordered.mesh, reordered.rawField);
  reordered.expectedRoute = source.expectedRoute;
  for (auto &step : reordered.expectedRoute) {
    step.sourceFace =
        oldToNewFace[static_cast<std::size_t>(step.sourceFace)];
    step.targetFace =
        oldToNewFace[static_cast<std::size_t>(step.targetFace)];
  }
  return reordered;
}

bool assign_directed_matching(
    directional::fields::CrossFieldResult &field,
    const PeriodicHolonomyRouteStep &step, const int matching) {
  auto *transition = transition_for_edge(field, step.topology);
  if (transition == nullptr) return false;
  if (transition->firstFace == step.sourceFace &&
      transition->secondFace == step.targetFace) {
    transition->matching = matching;
    return true;
  }
  if (transition->firstFace == step.targetFace &&
      transition->secondFace == step.sourceFace) {
    transition->matching = -matching;
    return true;
  }
  return false;
}

directional::fields::CrossFieldResult balanced_periodic_route_field(
    const PeriodicHolonomyRouteFixture &fixture) {
  if (fixture.expectedRoute.size() != 32U) {
    throw std::runtime_error("Unexpected periodic route cardinality.");
  }
  auto field = fixture.authoritativeField;
  if (!assign_directed_matching(field, fixture.expectedRoute[0], 1) ||
      !assign_directed_matching(field, fixture.expectedRoute[1], -1)) {
    throw std::runtime_error("Could not author nonzero periodic transport.");
  }
  return field;
}

directional::geometry::SurfaceCellNetwork build_periodic_route_network(
    const PeriodicHolonomyRouteFixture &fixture,
    const directional::fields::CrossFieldResult &field) {
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  return directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, field, targetSize, options);
}

std::vector<std::uint64_t> periodic_route_topology(
    const PeriodicHolonomyRouteFixture &fixture) {
  std::vector<std::uint64_t> topology;
  topology.reserve(fixture.expectedRoute.size());
  for (const auto &step : fixture.expectedRoute) {
    topology.push_back(step.topology);
  }
  return topology;
}

std::vector<int> independent_periodic_route_compact_ids(
    const PeriodicHolonomyRouteFixture &fixture) {
  std::map<std::uint64_t, int> compactByTopology;
  int compact = 0;
  for (const std::uint64_t topology : interior_source_edges(fixture.mesh)) {
    compactByTopology.emplace(topology, compact++);
  }
  std::vector<int> route;
  route.reserve(fixture.expectedRoute.size());
  for (const auto &step : fixture.expectedRoute) {
    const auto found = compactByTopology.find(step.topology);
    route.push_back(found == compactByTopology.end() ? -1 : found->second);
  }
  return route;
}

using PeriodicHolonomySnapshot =
    std::tuple<directional::authority::GridAutomorphism,
               directional::authority::CanonicalRoute,
               directional::authority::CanonicalRoute>;

PeriodicHolonomySnapshot periodic_holonomy_snapshot(
    const directional::geometry::SurfacePeriodicHolonomy &holonomy) {
  return {holonomy.action, holonomy.route, holonomy.cutRoute};
}

directional::fields::CrossFieldResult make_legacy_periodic_route_field(
    const PeriodicHolonomyRouteFixture &fixture,
    const directional::fields::CrossFieldResult &authoritative) {
  std::map<std::uint64_t, std::array<int, 2>> incidence;
  for (int face = 0; face < fixture.mesh.F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const std::uint64_t topology =
          directional::pipeline::surface_cell_source_edge_key(
              fixture.mesh.F(face, corner),
              fixture.mesh.F(face, (corner + 1) % 3));
      auto [found, inserted] = incidence.try_emplace(
          topology, std::array<int, 2>{face, -1});
      if (!inserted && found->second[0] != face && found->second[1] < 0) {
        found->second[1] = face;
      }
    }
  }

  auto legacy = authoritative;
  const std::size_t interiorCount = static_cast<std::size_t>(std::count_if(
      incidence.begin(), incidence.end(), [](const auto &entry) {
        return entry.second[0] >= 0 && entry.second[1] >= 0;
      }));
  legacy.matching.resize(static_cast<Eigen::Index>(interiorCount));
  legacy.effort.resize(static_cast<Eigen::Index>(interiorCount));
  int compact = 0;
  for (const auto &[topology, faces] : incidence) {
    if (faces[0] < 0 || faces[1] < 0) continue;
    const auto *transition = transition_for_edge(authoritative, topology);
    if (transition == nullptr) {
      throw std::runtime_error("Missing periodic legacy transition authority.");
    }
    legacy.matching[compact] =
        directed_matching(*transition, faces[0], faces[1]);
    legacy.effort[compact] = transition->effort;
    ++compact;
  }
  legacy.edgeTransitions.clear();
  return legacy;
}

TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
     NonzeroStepsComposeToZeroWholeCycle) {
  const auto fixture = make_periodic_holonomy_route_fixture();
  const auto field = balanced_periodic_route_field(fixture);
  const auto *first = transition_for_edge(field, fixture.expectedRoute[0].topology);
  const auto *second = transition_for_edge(field, fixture.expectedRoute[1].topology);
  ASSERT_NE(nullptr, first);
  ASSERT_NE(nullptr, second);
  EXPECT_EQ(1, directed_matching(*first, fixture.expectedRoute[0].sourceFace,
                                 fixture.expectedRoute[0].targetFace));
  EXPECT_EQ(-1, directed_matching(*second, fixture.expectedRoute[1].sourceFace,
                                  fixture.expectedRoute[1].targetFace));

  const auto network = build_periodic_route_network(fixture, field);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_EQ(1U, network.phaseFront.product().periodicHolonomies.size());
  const auto &holonomy = network.phaseFront.product().periodicHolonomies.front();
  EXPECT_EQ(directional::authority::QuarterTurn{}, holonomy.action.rotation);
  EXPECT_EQ(periodic_route_topology(fixture), route_topology(holonomy.route));
  EXPECT_EQ(independent_periodic_route_compact_ids(fixture),
            route_transition_ids(holonomy.route));
}

TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
     ReverseObservedCycleUsesExactTransportInverse) {
  const auto forwardFixture = make_periodic_holonomy_route_fixture();
  const auto reverseFixture =
      reflect_periodic_holonomy_route_fixture(forwardFixture);
  const auto forwardField = balanced_periodic_route_field(forwardFixture);
  const auto reverseField = balanced_periodic_route_field(reverseFixture);

  for (const auto &forwardStep : forwardFixture.expectedRoute) {
    const auto reverseStep = std::find_if(
        reverseFixture.expectedRoute.begin(), reverseFixture.expectedRoute.end(),
        [&](const auto &candidate) {
          return candidate.semanticTopology == forwardStep.semanticTopology &&
                 candidate.sourceFace == forwardStep.targetFace &&
                 candidate.targetFace == forwardStep.sourceFace;
        });
    ASSERT_NE(reverseFixture.expectedRoute.end(), reverseStep);
    const auto *forwardTransition =
        transition_for_edge(forwardField, forwardStep.topology);
    const auto *reverseTransition =
        transition_for_edge(reverseField, reverseStep->topology);
    ASSERT_NE(nullptr, forwardTransition);
    ASSERT_NE(nullptr, reverseTransition);
    const int forwardMatching = directed_matching(
        *forwardTransition, forwardStep.sourceFace, forwardStep.targetFace);
    const int reverseMatching = directed_matching(
        *reverseTransition, reverseStep->sourceFace, reverseStep->targetFace);
    EXPECT_EQ(0, fixture_quarter_turn(forwardMatching + reverseMatching));
  }

  const auto forward =
      build_periodic_route_network(forwardFixture, forwardField);
  const auto reverse =
      build_periodic_route_network(reverseFixture, reverseField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition());
  ASSERT_EQ(1U, forward.phaseFront.product().periodicHolonomies.size());
  ASSERT_EQ(1U, reverse.phaseFront.product().periodicHolonomies.size());
  EXPECT_EQ(directional::authority::QuarterTurn{},
            forward.phaseFront.product().periodicHolonomies.front().action.rotation);
  EXPECT_EQ(directional::authority::QuarterTurn{},
            reverse.phaseFront.product().periodicHolonomies.front().action.rotation);
  EXPECT_EQ(periodic_route_topology(forwardFixture),
            route_topology(forward.phaseFront.product().periodicHolonomies.front().route));
  EXPECT_EQ(periodic_route_topology(reverseFixture),
            route_topology(reverse.phaseFront.product().periodicHolonomies.front().route));
}

TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
     EquivalentSignedRepresentationsNormalizeSemantically) {
  const auto fixture = make_periodic_holonomy_route_fixture();
  const auto baselineField = balanced_periodic_route_field(fixture);
  auto equivalentField = baselineField;
  auto *first = transition_for_edge(
      equivalentField, fixture.expectedRoute[0].topology);
  auto *second = transition_for_edge(
      equivalentField, fixture.expectedRoute[1].topology);
  ASSERT_NE(nullptr, first);
  ASSERT_NE(nullptr, second);
  first->matching += 4;
  second->matching -= 4;

  const auto baseline = build_periodic_route_network(fixture, baselineField);
  const auto equivalent =
      build_periodic_route_network(fixture, equivalentField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            baseline.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            equivalent.phaseFront.disposition());
  ASSERT_EQ(1U, baseline.phaseFront.product().periodicHolonomies.size());
  ASSERT_EQ(1U, equivalent.phaseFront.product().periodicHolonomies.size());
  EXPECT_EQ(periodic_holonomy_snapshot(
                baseline.phaseFront.product().periodicHolonomies.front()),
            periodic_holonomy_snapshot(
                equivalent.phaseFront.product().periodicHolonomies.front()));
}

TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
     RouteTopologyAndCompactIdentityIgnoreFaceRowOrder) {
  const auto fixture = make_periodic_holonomy_route_fixture();
  const auto reordered = reorder_periodic_holonomy_faces(fixture);
  const auto field = balanced_periodic_route_field(fixture);
  const auto reorderedField = balanced_periodic_route_field(reordered);

  const auto baseline = build_periodic_route_network(fixture, field);
  const auto permuted =
      build_periodic_route_network(reordered, reorderedField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            baseline.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            permuted.phaseFront.disposition());
  ASSERT_EQ(1U, baseline.phaseFront.product().periodicHolonomies.size());
  ASSERT_EQ(1U, permuted.phaseFront.product().periodicHolonomies.size());
  const auto expectedTopology = periodic_route_topology(fixture);
  const auto expectedCompact = independent_periodic_route_compact_ids(fixture);
  ASSERT_EQ(expectedTopology, periodic_route_topology(reordered));
  ASSERT_EQ(expectedCompact, independent_periodic_route_compact_ids(reordered));
  EXPECT_EQ(expectedTopology,
            route_topology(baseline.phaseFront.product().periodicHolonomies.front().route));
  EXPECT_EQ(expectedTopology,
            route_topology(permuted.phaseFront.product().periodicHolonomies.front().route));
  EXPECT_EQ(expectedCompact,
            route_transition_ids(baseline.phaseFront.product().periodicHolonomies.front().route));
  EXPECT_EQ(expectedCompact,
            route_transition_ids(permuted.phaseFront.product().periodicHolonomies.front().route));
}

TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
     MalformedAuthoritativeCrossingProvenanceFailsClosed) {
  const auto fixture = make_periodic_holonomy_route_fixture();
  auto malformed = balanced_periodic_route_field(fixture);
  auto *transition = transition_for_edge(
      malformed, fixture.expectedRoute.front().topology);
  ASSERT_NE(nullptr, transition);
  ASSERT_GE(transition->sourceEdge, 0);
  transition->sourceEdge = -1;

  const auto rejected = build_periodic_route_network(fixture, malformed);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            rejected.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                PeriodicHolonomyMismatch,
            rejected.phaseFront.rejection_reason());
  EXPECT_EQ(fixture.expectedRoute.front().sourceFace,
            phase_front_rejection(rejected.phaseFront).face);
  EXPECT_EQ(fixture.expectedRoute.front().targetFace,
            phase_front_rejection(rejected.phaseFront).targetFace);
  EXPECT_FALSE(rejected.phaseFront.is_produced());
  EXPECT_EQ(nullptr, rejected.phaseFront.produced_product());
  EXPECT_TRUE(rejected.seeds.empty());
  EXPECT_TRUE(rejected.traces.empty());
  EXPECT_TRUE(rejected.proposals.empty());
}

TEST(SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration,
     LegacyMatchingPathUsesSameTypedAlgebra) {
  const auto fixture = make_periodic_holonomy_route_fixture();
  const auto authoritativeField = balanced_periodic_route_field(fixture);
  const auto legacyField =
      make_legacy_periodic_route_field(fixture, authoritativeField);
  ASSERT_TRUE(legacyField.edgeTransitions.empty());

  const auto authoritative =
      build_periodic_route_network(fixture, authoritativeField);
  const auto legacy = build_periodic_route_network(fixture, legacyField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            authoritative.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            legacy.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             legacy.phaseFront.rejection_reason());
  ASSERT_EQ(1U, authoritative.phaseFront.product().periodicHolonomies.size());
  ASSERT_EQ(1U, legacy.phaseFront.product().periodicHolonomies.size());
  EXPECT_EQ(periodic_holonomy_snapshot(
                authoritative.phaseFront.product().periodicHolonomies.front()),
            periodic_holonomy_snapshot(
                legacy.phaseFront.product().periodicHolonomies.front()));
}

TEST(SurfaceCellsPhase10,
     ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary) {
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

  EXPECT_GT(result.diagnostics.surfaceCellTopologyRegionCount, 0U);
  EXPECT_GT(result.diagnostics.surfaceCellInternalIsolationSeamCount, 0U);
  EXPECT_EQ(result.diagnostics.surfaceCellTopologyRegionCount,
            result.diagnostics.surfaceCellConsumedTopologyRegionCount);
  EXPECT_EQ(result.diagnostics.surfaceCellInternalIsolationSeamCount,
            result.diagnostics.surfaceCellConsumedInternalIsolationSeamCount);
  EXPECT_EQ(result.diagnostics.surfaceCellPeriodicHolonomies.size(),
            result.diagnostics.surfaceCellConsumedPeriodicHolonomyCount);
  EXPECT_EQ(1,
            result.diagnostics.surfaceCellMaterializedConnectedComponentCount);
  EXPECT_EQ(0, result.diagnostics.surfaceCellMaterializedBoundaryLoopCount);
  EXPECT_EQ(0, result.diagnostics.surfaceCellMaterializedEulerCharacteristic);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ":"
      << result.diagnostics.terminalFailureStage << " producer="
      << result.diagnostics.surfaceCellFirstInvalidProducerStage << "/"
      << result.diagnostics.surfaceCellFirstInvalidProducerReason;
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &network = result.surfaceCellContext.traceNetwork;
  const auto &phaseFront = network.phaseFront;
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             phaseFront.rejection_reason());
  EXPECT_TRUE(phaseFront.is_produced());
  ASSERT_FALSE(network.phaseFront.product().sourceTopologyRegions.regions().empty());
  EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions.regions().size(),
            result.diagnostics.surfaceCellTopologyRegionCount);
  ASSERT_EQ(static_cast<std::size_t>(mesh.F.rows()),
            network.phaseFront.product().sourceTopologyRegions.face_count());
  for (std::size_t rowIndex = 0;
       rowIndex < network.phaseFront.product().sourceTopologyRegions.face_count();
       ++rowIndex) {
    const auto row = directional::authority::SourceFaceId::from_index(
        rowIndex, network.phaseFront.product().sourceTopologyRegions.face_count());
    ASSERT_TRUE(row);
    EXPECT_LT(network.phaseFront.product().sourceTopologyRegions
                  .region_for_row(row.value()).index(),
              network.phaseFront.product().sourceTopologyRegions.regions().size());
  }
  bool sawMultiSheetRegionWithInternalSeam = false;
  for (const auto &region : network.phaseFront.product().sourceTopologyRegions.regions()) {
    if (topology_region_sheets(region).size() > 1U &&
        !region.isolation_seams().empty()) {
      sawMultiSheetRegionWithInternalSeam = true;
    }
  }
  EXPECT_TRUE(sawMultiSheetRegionWithInternalSeam);
  EXPECT_EQ(result.diagnostics.surfaceCellInternalIsolationSeamCount,
            phaseFront.product().isolationSeamTransportCertificates.size());
  EXPECT_EQ(result.diagnostics.surfaceCellTopologyRegionCount,
            result.diagnostics.surfaceCellTopologyRegionHashes.size());
  EXPECT_FALSE(phaseFront.product().periodicHolonomies.empty());
  EXPECT_EQ(phaseFront.product().periodicHolonomies.size(),
            result.diagnostics.surfaceCellPeriodicHolonomies.size());
  ASSERT_EQ(static_cast<std::size_t>(result.vertices.rows()),
            result.outputVertexLineage.size());
  ASSERT_EQ(static_cast<std::size_t>(result.faces.rows()),
            result.outputQuadLineage.size());
  EXPECT_GT(result.faces.rows(), 0);
  EXPECT_EQ(4, result.faces.cols());
  for (const auto &lineage : result.outputVertexLineage) {
    EXPECT_TRUE(lineage.sourcePoint.valid());
    EXPECT_FALSE(lineage.sourceTopologyRegions.empty());
    EXPECT_FALSE(lineage.sourceIsolationSheets.empty());
    EXPECT_FALSE(lineage.sourceCharts.empty());
    EXPECT_TRUE(lineage.sourceSupport.has_value());
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
            valid.phaseFront.disposition());
  const auto &holonomy = valid.phaseFront.product().periodicHolonomies.front();
  ASSERT_TRUE(route_is_all_interior(holonomy.route));
  const std::uint64_t tamperedTopology =
      test_source_edge_key(holonomy.route.steps().front().topology());
  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(mesh.F);
  const auto incident = sourceIncidence.find(tamperedTopology);
  ASSERT_NE(sourceIncidence.end(), incident);
  ASSERT_GE(incident->second[0], 0);
  ASSERT_GE(incident->second[1], 0);
  const auto sourceWide = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const auto expectedRouteIndex = sourceWide.find(tamperedTopology);
  ASSERT_NE(sourceWide.end(), expectedRouteIndex);
  ASSERT_TRUE(holonomy.route.steps().front().interior().has_value());
  EXPECT_EQ(expectedRouteIndex->second,
            static_cast<int>(holonomy.route.steps().front().interior()->index()));

  auto transition = crossField.edgeTransitions.end();
  int transitionCount = 0;
  for (auto candidate = crossField.edgeTransitions.begin();
       candidate != crossField.edgeTransitions.end(); ++candidate) {
    const bool sameTopology =
        directional::pipeline::surface_cell_source_edge_key(
            candidate->sourceVertex0, candidate->sourceVertex1) ==
        tamperedTopology;
    const bool reciprocalFaces =
        (candidate->firstFace == incident->second[0] &&
         candidate->secondFace == incident->second[1]) ||
        (candidate->firstFace == incident->second[1] &&
         candidate->secondFace == incident->second[0]);
    if (!sameTopology || !reciprocalFaces) continue;
    ++transitionCount;
    transition = candidate;
  }
  ASSERT_EQ(1, transitionCount);
  ASSERT_NE(crossField.edgeTransitions.end(), transition);
  ASSERT_GE(transition->sourceEdge, 0);
  ASSERT_LT(transition->sourceEdge, mesh.EV.rows());
  ASSERT_EQ(tamperedTopology,
            directional::pipeline::surface_cell_source_edge_key(
                mesh.EV(transition->sourceEdge, 0),
                mesh.EV(transition->sourceEdge, 1)));
  const bool reciprocalEfFaces =
      (mesh.EF(transition->sourceEdge, 0) == incident->second[0] &&
       mesh.EF(transition->sourceEdge, 1) == incident->second[1]) ||
      (mesh.EF(transition->sourceEdge, 0) == incident->second[1] &&
       mesh.EF(transition->sourceEdge, 1) == incident->second[0]);
  ASSERT_TRUE(reciprocalEfFaces);
  transition->matching += 1;

  const auto malformed = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            malformed.phaseFront.disposition());
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontFailureReason::
                PeriodicHolonomyMismatch,
            malformed.phaseFront.rejection_reason());
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
  EXPECT_GT(result.diagnostics.surfaceCellTopologyRegionCount, 0U);
  EXPECT_EQ(result.diagnostics.surfaceCellTopologyRegionCount,
            result.diagnostics.surfaceCellConsumedTopologyRegionCount);
  EXPECT_EQ(result.diagnostics.surfaceCellPeriodicHolonomies.size(),
            result.diagnostics.surfaceCellConsumedPeriodicHolonomyCount);
  EXPECT_EQ(1,
            result.diagnostics.surfaceCellMaterializedConnectedComponentCount);
  EXPECT_EQ(2, result.diagnostics.surfaceCellMaterializedBoundaryLoopCount);
  EXPECT_EQ(0, result.diagnostics.surfaceCellMaterializedEulerCharacteristic);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ":"
      << result.diagnostics.terminalFailureStage << " producer="
      << result.diagnostics.surfaceCellFirstInvalidProducerStage << "/"
      << result.diagnostics.surfaceCellFirstInvalidProducerReason;
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork);
  const auto &network = result.surfaceCellContext.traceNetwork;
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_TRUE(network.phaseFront.is_produced());
  EXPECT_FALSE(network.phaseFront.product().periodicHolonomies.empty());
  EXPECT_TRUE(result.diagnostics.surfaceCellPeriodicHolonomyAvailable);
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
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  EXPECT_TRUE(network.phaseFront.is_produced());
  EXPECT_EQ(64U, network.phaseFront.product().cells.size());
  EXPECT_TRUE(network.seeds.empty());
  EXPECT_TRUE(network.traces.empty());
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ":"
      << result.diagnostics.terminalFailureStage;
  EXPECT_EQ(64U, result.diagnostics.surfaceCellCompletedQuadCount);
}


struct VertexContinuationRouteFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  std::map<std::uint64_t, std::array<int, 2>> edgeFaces;
  std::map<std::uint64_t, int> edgeMatchingIndices;
  std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
  Eigen::VectorXi legacyMatching;
  Eigen::VectorXd legacyEffort;
  directional::geometry::SurfaceCellTracingOptions options;
  std::vector<std::uint64_t> forwardTopology;
  std::vector<int> forwardCompactEdges;
  Eigen::RowVector3d forwardDirection = Eigen::RowVector3d::Zero();
};

VertexContinuationRouteFixture make_vertex_continuation_route_fixture() {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  VertexContinuationRouteFixture fixture;
  fixture.vertices.resize(5, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                     -1.0, 0.0, 0.0,
                      0.0,-1.0, 0.0;
  fixture.faces.resize(4, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3,
                   0, 3, 4,
                   0, 4, 1;

  const double invSqrt2 = 1.0 / std::sqrt(2.0);
  const Eigen::RowVector3d diagonal(invSqrt2, invSqrt2, 0.0);
  const Eigen::RowVector3d perpendicular(-invSqrt2, invSqrt2, 0.0);
  fixture.forwardDirection = diagonal;
  fixture.faceAxisX.resize(4, 3);
  fixture.faceAxisY.resize(4, 3);
  fixture.faceAxisX.row(0) = perpendicular;
  fixture.faceAxisY.row(0) = -diagonal;
  fixture.faceAxisX.row(1) = perpendicular;
  fixture.faceAxisY.row(1) = diagonal;
  fixture.faceAxisX.row(2) = diagonal;
  fixture.faceAxisY.row(2) = perpendicular;
  fixture.faceAxisX.row(3) = perpendicular;
  fixture.faceAxisY.row(3) = -diagonal;

  fixture.edgeFaces = detail::edge_faces(fixture.faces);
  fixture.edgeMatchingIndices = detail::edge_matching_indices(fixture.edgeFaces);
  const std::uint64_t first = detail::edge_key(0, 3);
  const std::uint64_t second = detail::edge_key(0, 2);
  fixture.forwardTopology = {first, second};
  fixture.forwardCompactEdges = {2, 1};

  directional::fields::CrossFieldEdgeTransition firstTransition;
  firstTransition.sourceEdge = 2;
  firstTransition.sourceVertex0 = 0;
  firstTransition.sourceVertex1 = 3;
  firstTransition.firstFace = 2;
  firstTransition.secondFace = 1;
  firstTransition.matching = 1;
  firstTransition.effort = 0.25;
  fixture.transitions.push_back(firstTransition);

  directional::fields::CrossFieldEdgeTransition secondTransition;
  secondTransition.sourceEdge = 1;
  secondTransition.sourceVertex0 = 0;
  secondTransition.sourceVertex1 = 2;
  secondTransition.firstFace = 1;
  secondTransition.secondFace = 0;
  secondTransition.matching = 2;
  secondTransition.effort = 0.5;
  fixture.transitions.push_back(secondTransition);

  fixture.legacyMatching =
      Eigen::VectorXi::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  fixture.legacyEffort =
      Eigen::VectorXd::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  fixture.legacyMatching[fixture.edgeMatchingIndices.at(first)] = -1;
  fixture.legacyMatching[fixture.edgeMatchingIndices.at(second)] = -2;
  fixture.legacyEffort[fixture.edgeMatchingIndices.at(first)] = 0.25;
  fixture.legacyEffort[fixture.edgeMatchingIndices.at(second)] = 0.5;

  fixture.options.sourceFaceComponents = {0, 0, 0, 0};
  fixture.options.sourceFaceSheets = {0, 0, 0, 0};
  fixture.options.hardFeatureEdges.insert(detail::edge_key(0, 1));
  fixture.options.hardFeatureEdges.insert(detail::edge_key(0, 4));
  return fixture;
}

directional::geometry::surface_cell_tracing_detail::VertexContinuationResult
resolve_vertex_continuation_fixture(
    const VertexContinuationRouteFixture &fixture, const int currentFace,
    const int currentFamily, const int currentSign,
    const Eigen::RowVector3d &incomingDirection,
    const std::vector<directional::fields::CrossFieldEdgeTransition>
        *transitions) {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  const auto lookup = transitions != nullptr
                          ? detail::edge_transition_lookup(*transitions)
                          : detail::EdgeTransitionLookup{};
  return detail::resolve_vertex_continuation(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.edgeFaces, fixture.edgeMatchingIndices, lookup, currentFace, 0,
      currentFamily, currentSign, incomingDirection, fixture.options,
      &fixture.legacyMatching, &fixture.legacyEffort, transitions);
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     MultiStepContinuationComposesTypedTransport) {
  const auto fixture = make_vertex_continuation_route_fixture();
  ASSERT_EQ(2U, fixture.transitions.size());
  EXPECT_EQ(1, fixture.transitions[0].matching);
  EXPECT_EQ(2, fixture.transitions[1].matching);

  const auto result = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);

  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            result.status);
  EXPECT_EQ(0, result.face);
  EXPECT_EQ((std::vector<int>{2, 1, 0}), result.facePath);
  EXPECT_EQ(3, result.matching);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(-1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(fixture.forwardDirection, 1.0e-12));
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     ReverseObservedContinuationUsesExactTransportInverse) {
  const auto fixture = make_vertex_continuation_route_fixture();
  const auto forward = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  const auto reverse = resolve_vertex_continuation_fixture(
      fixture, 0, 1, 1, -fixture.forwardDirection, &fixture.transitions);

  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            forward.status);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            reverse.status);
  EXPECT_EQ(3, forward.matching);
  EXPECT_EQ(1, reverse.matching);
  EXPECT_EQ((std::vector<int>{0, 1, 2}), reverse.facePath);
  EXPECT_EQ(0, fixture_quarter_turn(forward.matching + reverse.matching));
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     EquivalentSignedRepresentationsNormalizeSemantically) {
  const auto fixture = make_vertex_continuation_route_fixture();
  auto plusFour = fixture.transitions;
  plusFour[0].matching += 4;
  auto minusFour = fixture.transitions;
  minusFour[1].matching -= 4;

  const auto baseline = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  const auto positive = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &plusFour);
  const auto negative = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &minusFour);

  for (const auto *result : {&baseline, &positive, &negative}) {
    ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                  VertexContinuationStatus::Found,
              result->status);
    EXPECT_EQ(3, result->matching);
    EXPECT_EQ((std::vector<int>{2, 1, 0}), result->facePath);
  }
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     ContinuationFacePathPreservesIndependentCompactRouteAuthority) {
  const auto fixture = make_vertex_continuation_route_fixture();
  ASSERT_EQ(2U, fixture.forwardTopology.size());
  ASSERT_EQ(2U, fixture.forwardCompactEdges.size());
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::edge_key(0, 3),
            fixture.forwardTopology[0]);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::edge_key(0, 2),
            fixture.forwardTopology[1]);
  EXPECT_EQ((std::vector<int>{2, 1}), fixture.forwardCompactEdges);

  const auto result = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            result.status);
  EXPECT_EQ((std::vector<int>{2, 1, 0}), result.facePath);
  EXPECT_EQ(3, result.matching);
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     MalformedAuthoritativeStepProvenanceFailsClosedWithoutLegacyFallback) {
  const auto fixture = make_vertex_continuation_route_fixture();
  const auto baseline = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            baseline.status);

  auto malformed = fixture.transitions;
  malformed[0].sourceEdge = -1;
  const auto rejected = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &malformed);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::FieldMetadata,
            rejected.status);
  EXPECT_EQ(-1, rejected.face);
  EXPECT_TRUE(rejected.facePath.empty());
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     LegacyMatchingPathUsesSameTypedRouteComposition) {
  const auto fixture = make_vertex_continuation_route_fixture();
  const auto authoritative = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  const auto legacy = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, nullptr);

  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            authoritative.status);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            legacy.status);
  EXPECT_EQ(authoritative.face, legacy.face);
  EXPECT_EQ(authoritative.family, legacy.family);
  EXPECT_EQ(authoritative.sign, legacy.sign);
  EXPECT_EQ(authoritative.facePath, legacy.facePath);
  EXPECT_EQ(3, authoritative.matching);
  EXPECT_EQ(3, legacy.matching);
  EXPECT_NEAR(authoritative.matchingEffort, legacy.matchingEffort, 1.0e-12);
}


TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     PlanarMultiFaceFrontPublishesCheckedSingleChart) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_FALSE(network.phaseFront.product().cells.empty());
  for (const auto &cell : network.phaseFront.product().cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      EXPECT_EQ(0U,
                (
                    state.sourceChart.value()).index());
    }
  }
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     MultipleOrientationChartsPreserveEstablishedNumbering) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto network =
      build_segment_route_network(fixture, fixture.authoritativeField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());

  ASSERT_GT(fixture.mesh.F.rows(), 10);
  std::vector<int> expectedChartByFace(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  expectedChartByFace[3] = 1;
  expectedChartByFace[10] = 2;

  std::map<int, std::set<int>> compatibilityChartsByFace;
  std::set<int> producerCompatibilityCharts;
  for (const auto &cell : network.phaseFront.product().cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        ASSERT_GE(segment.face, 0);
        ASSERT_LT(segment.face, fixture.mesh.F.rows());
        const int expectedChart =
            expectedChartByFace[static_cast<std::size_t>(segment.face)];
        ASSERT_TRUE(segment.sourceChart.has_value());
        EXPECT_EQ(static_cast<std::size_t>(expectedChart),
                  segment.sourceChart->index())
            << "source face " << segment.face
            << " must preserve the hard-authored producer chart identity";
        compatibilityChartsByFace[segment.face].insert(
            static_cast<int>(segment.sourceChart->index()));
        producerCompatibilityCharts.insert(
            static_cast<int>(segment.sourceChart->index()));
      }
    }
  }
  EXPECT_EQ((std::set<int>{0, 1, 2}), producerCompatibilityCharts);
  EXPECT_EQ((std::set<int>{1}), compatibilityChartsByFace[3]);
  EXPECT_EQ((std::set<int>{2}), compatibilityChartsByFace[10]);

  std::set<std::size_t> typedOccurrenceCharts;
  for (const auto &cell : network.phaseFront.product().cells) {
    ASSERT_EQ(cell.corners.size(), cell.lattice.size());
    for (std::size_t corner = 0; corner < cell.lattice.size(); ++corner) {
      const auto &state = cell.lattice[corner];
      ASSERT_TRUE(state.sourceChart.has_value());
      const int sourceFace = cell.corners[corner].face;
      ASSERT_GE(sourceFace, 0);
      ASSERT_LT(sourceFace, fixture.mesh.F.rows());
      const std::size_t typedChart =
          (
              state.sourceChart.value()).index();
      EXPECT_EQ(
          static_cast<std::size_t>(
              expectedChartByFace[static_cast<std::size_t>(sourceFace)]),
          typedChart)
          << "lattice occurrence on source face " << sourceFace
          << " must carry that face's producer-owned FieldChartId";
      typedOccurrenceCharts.insert(typedChart);
    }
  }
  EXPECT_GE(typedOccurrenceCharts.size(), 2U)
      << "the fixture must exercise more than the default chart in actual "
         "constructive-front occurrences";
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     NumericCoincidenceCannotCrossAuthorityDomains) {
  using directional::authority::AuthorityDomain;
  using directional::authority::DomainErrorCode;
  using directional::authority::FieldChartId;
  const auto chart = directional::authority::FieldChartId::from_index(0, 1);
  const auto face = directional::authority::SourceFaceId::from_index(0, 1);
  ASSERT_TRUE(chart);
  ASSERT_TRUE(face);
  EXPECT_EQ((chart.value()).index(),
            (face.value()).index());

  const auto wrongDomain = FieldChartId::from_domain_index(
      AuthorityDomain::SourceFace, 0, 1);
  ASSERT_FALSE(wrongDomain);
  EXPECT_EQ(DomainErrorCode::DomainMismatch, wrongDomain.error().code);
  EXPECT_EQ(AuthorityDomain::FieldChart, wrongDomain.error().expectedDomain);
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     MissingOrInvalidChartAuthorityCannotMasqueradeAsValid) {
  directional::geometry::LocalLatticeState state;
  EXPECT_FALSE(state.sourceChart.has_value());

  const auto negative =
      directional::authority::FieldChartId::from_index(-1, 3);
  const auto outOfRange =
      directional::authority::FieldChartId::from_index(3, 3);
  EXPECT_FALSE(negative);
  EXPECT_FALSE(outOfRange);

  const auto valid =
      directional::authority::FieldChartId::from_index(0, 3);
  ASSERT_TRUE(valid);
  state.sourceChart = valid.value();
  ASSERT_TRUE(state.sourceChart.has_value());
  EXPECT_EQ(0U,
            (
                state.sourceChart.value()).index());
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     FaceRowPermutationPreservesTypedPlanarChartAuthority) {
  const directional::TriMesh forwardMesh = make_vertex_fan_plane_mesh(false);
  const directional::TriMesh reverseMesh = make_vertex_fan_plane_mesh(true);
  const auto forwardField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          forwardMesh, constant_xy_raw_field(forwardMesh.F.rows()));
  const auto reverseField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reverseMesh, constant_xy_raw_field(reverseMesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(forwardMesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions forwardOptions;
  forwardOptions.sourceFaceComponents.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  forwardOptions.sourceFaceSheets.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  directional::geometry::SurfaceCellTracingOptions reverseOptions = forwardOptions;

  const auto forward = directional::geometry::build_surface_cell_network(
      forwardMesh.V, forwardMesh.F, forwardField, targetSize, forwardOptions);
  const auto reverse = directional::geometry::build_surface_cell_network(
      reverseMesh.V, reverseMesh.F, reverseField, targetSize, reverseOptions);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition());
  ASSERT_EQ(forward.phaseFront.product().cells.size(), reverse.phaseFront.product().cells.size());
  for (const auto *network : {&forward, &reverse}) {
    for (const auto &cell : network->phaseFront.product().cells) {
      for (const auto &state : cell.lattice) {
        ASSERT_TRUE(state.sourceChart.has_value());
        EXPECT_EQ(
            0U,
            (
                state.sourceChart.value()).index());
      }
    }
  }
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero) {
  const CurvedDiskFixture disk = make_curved_disk_fixture();
  const auto bounded = directional::geometry::build_surface_cell_network(
      disk.vertices, disk.faces, disk.faceAxisX, disk.faceAxisY,
      disk.targetSize, disk.options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            bounded.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             bounded.phaseFront.rejection_reason());
  ASSERT_FALSE(bounded.phaseFront.product().cells.empty());
  for (const auto &cell : bounded.phaseFront.product().cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      EXPECT_EQ(0U,
                (
                    state.sourceChart.value()).index());
    }
  }

  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField =
      read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(mesh,
                                                                    rawField);
  const Eigen::VectorXd target =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto periodic = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, target, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            periodic.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             periodic.phaseFront.rejection_reason());
  ASSERT_FALSE(periodic.phaseFront.product().cells.empty());
  for (const auto &cell : periodic.phaseFront.product().cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      EXPECT_EQ(0U,
                (
                    state.sourceChart.value()).index());
    }
  }
}


TEST(SurfaceCellAuthorityContractCutover,
     PlanarCellsReferenceRegionThatOwnsComponentAndSheet) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  ASSERT_FALSE(network.phaseFront.product().cells.empty());
  const auto &region = network.phaseFront.product().sourceTopologyRegions.regions().front();
  ASSERT_EQ(1U, topology_region_sheets(region).size());
  EXPECT_EQ(0U, region.component().index());
  EXPECT_EQ(0U, topology_region_sheets(region).front().index());
  for (const auto &cell : network.phaseFront.product().cells) {
    EXPECT_EQ(region.id(), cell.sourceTopologyRegion);
  }
}

TEST(SurfaceCellAuthorityContractCutover,
     ExplicitSourceLabelsRemainDistinctTypedDomains) {
  static_assert(!std::is_same_v<directional::authority::SourceComponentId,
                                directional::authority::IsolationSheetId>);
  static_assert(!std::is_same_v<directional::authority::TopologyRegionId,
                                directional::authority::IsolationSheetId>);
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 2);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 5);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());
  ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  const auto &region = network.phaseFront.product().sourceTopologyRegions.regions().front();
  ASSERT_EQ(1U, topology_region_sheets(region).size());
  EXPECT_EQ(2U, region.component().index());
  EXPECT_EQ(5U, topology_region_sheets(region).front().index());
  for (const auto &cell : network.phaseFront.product().cells) {
    EXPECT_EQ(region.id(), cell.sourceTopologyRegion);
  }
}

TEST(SurfaceCellAuthorityContractCutover,
     MultiSheetCellsDeriveCompleteSheetSetFromOwningRegion) {
  const directional::TriMesh mesh = make_square_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Constant(4, 0.5);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition())
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.rejection_reason());
  ASSERT_EQ(1U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  const auto &region = network.phaseFront.product().sourceTopologyRegions.regions().front();
  ASSERT_EQ(2U, topology_region_sheets(region).size());
  EXPECT_EQ(0U, topology_region_sheets(region)[0].index());
  EXPECT_EQ(1U, topology_region_sheets(region)[1].index());
  for (const auto &cell : network.phaseFront.product().cells) {
    EXPECT_EQ(region.id(), cell.sourceTopologyRegion);
    EXPECT_EQ((std::vector<int>{0, 1}),
              phase_front_sheets(network.phaseFront, cell));
    EXPECT_FALSE(phase_front_single_sheet(network.phaseFront, cell).has_value());
  }
}

TEST(SurfaceCellAuthorityContractCutover,
     CellAndEdgeConsumersReferenceThePublishedRegion) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.5);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());
  ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  std::map<directional::authority::CellId,
           const directional::geometry::SurfacePhaseFrontCell *> cellsById;
  for (const auto &cell : network.phaseFront.product().cells) {
    ASSERT_TRUE(cellsById.emplace(cell.id, &cell).second);
    EXPECT_EQ(cell.sourceTopologyRegion,
              phase_front_region(network.phaseFront, cell).id());
  }
  ASSERT_FALSE(network.phaseFront.product().edges.empty());
  for (const auto &edge : network.phaseFront.product().edges) {
    const auto owner = cellsById.find(edge.filledCell);
    ASSERT_NE(cellsById.end(), owner);
    EXPECT_EQ(owner->second->sourceTopologyRegion, edge.sourceTopologyRegion);
    EXPECT_EQ(edge.sourceTopologyRegion,
              phase_front_region(network.phaseFront, edge).id());
  }
}

TEST(SurfaceCellAuthorityContractCutover,
     ProductionAggregationCounterfactualIgnoresPreConsumerRawProjectionTamper) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  const auto baseline =
      directional::pipeline::remesh_surface_cell_components_from_cross_field(
          mesh.V, mesh.F, crossField, options);
  const auto tampered = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [](const std::size_t componentIndex,
             directional::pipeline::RemeshResult &componentResult) {
            const int token = 10000 + static_cast<int>(componentIndex) * 1000;
            for (auto &point : componentResult.outputVertexProvenance) {
              point.component = token + 1;
              point.sheet = token + 2;
            }
            for (auto &lineage : componentResult.outputVertexLineage) {
              lineage.sourcePoint.component = token + 3;
              lineage.sourcePoint.sheet = token + 4;
              lineage.featureInterval.start.component = token + 5;
              lineage.featureInterval.start.sheet = token + 6;
              lineage.featureInterval.end.component = token + 7;
              lineage.featureInterval.end.sheet = token + 8;
            }
            for (auto &patch : componentResult.surfaceCellContext.completedPatches) {
              for (auto &point : patch.vertexProvenance) {
                point.component = token + 9;
                point.sheet = token + 10;
              }
              for (auto &lineage : patch.vertexLineage) {
                lineage.sourcePoint.component = token + 11;
                lineage.sourcePoint.sheet = token + 12;
                lineage.featureInterval.start.component = token + 13;
                lineage.featureInterval.start.sheet = token + 14;
                lineage.featureInterval.end.component = token + 15;
                lineage.featureInterval.end.sheet = token + 16;
              }
            }
            for (int &component :
                 componentResult.surfaceCellContext.sourceSurfaceLabels
                     .componentByFace) {
              component = token + 17;
            }
            for (int &sheet :
                 componentResult.surfaceCellContext.sourceSurfaceLabels
                     .localSheetByFace) {
              sheet = token + 18;
            }
          });

  ASSERT_TRUE(baseline.success)
      << baseline.diagnostics.terminalFailureCode << ':'
      << baseline.diagnostics.terminalFailureStage;
  ASSERT_TRUE(tampered.success)
      << tampered.diagnostics.terminalFailureCode << ':'
      << tampered.diagnostics.terminalFailureStage;
  EXPECT_EQ(2U, baseline.diagnostics.componentCount);
  EXPECT_EQ(baseline.vertices, tampered.vertices);
  EXPECT_EQ(baseline.faces, tampered.faces);
  EXPECT_EQ(baseline.degrees, tampered.degrees);

  const auto typedSnapshot = [](const directional::pipeline::RemeshResult &value) {
    std::vector<std::string> rows;
    rows.reserve(value.outputVertexLineage.size());
    for (const auto &lineage : value.outputVertexLineage) {
      std::ostringstream row;
      row << "R";
      for (const auto region : lineage.sourceTopologyRegions) {
        row << ':' << region.index();
      }
      row << "|S";
      for (const auto sheet : lineage.sourceIsolationSheets) {
        row << ':' << sheet.index();
      }
      row << "|C";
      for (const auto &chart : lineage.sourceCharts) {
        row << ':' << chart.chart.index() << '@' << chart.face.index();
      }
      row << "|P";
      std::visit(
          [&](const auto &support) {
            using Support = std::decay_t<decltype(support)>;
            if constexpr (std::is_same_v<
                              Support,
                              directional::authority::SourceVertexSupport>) {
              row << "V" << support.vertex.index();
            } else if constexpr (std::is_same_v<
                                     Support,
                                     directional::authority::SourceEdgeSupport>) {
              row << "E" << support.edge.first().index() << ':'
                  << support.edge.second().index();
            } else {
              row << "F" << support.face.index();
            }
          },
          lineage.sourceSupport.value());
      rows.push_back(row.str());
    }
    std::sort(rows.begin(), rows.end());
    return rows;
  };
  EXPECT_EQ(typedSnapshot(baseline), typedSnapshot(tampered));

  const auto completionHash = [](const directional::pipeline::RemeshResult &value) {
    directional::geometry::PureQuadMesh semanticMesh;
    semanticMesh.vertices.resize(static_cast<std::size_t>(value.vertices.rows()));
    std::iota(semanticMesh.vertices.begin(), semanticMesh.vertices.end(), 0);
    semanticMesh.vertexPositions = value.vertices;
    semanticMesh.vertexProvenance = value.outputVertexProvenance;
    semanticMesh.vertexLineage = value.outputVertexLineage;
    semanticMesh.quadLineage = value.outputQuadLineage;
    semanticMesh.quads.reserve(static_cast<std::size_t>(value.faces.rows()));
    for (int face = 0; face < value.faces.rows(); ++face) {
      const int degree = value.degrees.size() == value.faces.rows()
                             ? value.degrees(face)
                             : value.faces.cols();
      std::vector<int> polygon;
      polygon.reserve(static_cast<std::size_t>(std::max(0, degree)));
      for (int corner = 0; corner < degree; ++corner) {
        polygon.push_back(value.faces(face, corner));
      }
      semanticMesh.quads.push_back(std::move(polygon));
    }
    return directional::pipeline::hash_completion(semanticMesh);
  };
  EXPECT_EQ(completionHash(baseline), completionHash(tampered));

  ASSERT_TRUE(baseline.surfaceCellContext.hasValidationResult);
  ASSERT_TRUE(tampered.surfaceCellContext.hasValidationResult);
  const auto &baselineValidation = baseline.surfaceCellContext.validationResult;
  const auto &tamperedValidation = tampered.surfaceCellContext.validationResult;
  EXPECT_EQ(baselineValidation.accepted, tamperedValidation.accepted);
  EXPECT_EQ(baselineValidation.sourceAuthoritativeValidationUsed,
            tamperedValidation.sourceAuthoritativeValidationUsed);
  EXPECT_EQ(baselineValidation.provenanceValidationUsed,
            tamperedValidation.provenanceValidationUsed);
  EXPECT_EQ(baselineValidation.localSheetCompatibilityPassed,
            tamperedValidation.localSheetCompatibilityPassed);
  EXPECT_EQ(baselineValidation.connectedComponentMismatchCount,
            tamperedValidation.connectedComponentMismatchCount);
  EXPECT_EQ(baselineValidation.eulerCharacteristicMismatchCount,
            tamperedValidation.eulerCharacteristicMismatchCount);
  EXPECT_EQ(baselineValidation.boundaryCycleMismatchCount,
            tamperedValidation.boundaryCycleMismatchCount);

  std::set<std::size_t> firstComponentSheets;
  std::set<std::size_t> secondComponentSheets;
  for (const auto &lineage : baseline.outputVertexLineage) {
    ASSERT_FALSE(lineage.sourceTopologyRegions.empty());
    ASSERT_FALSE(lineage.sourceIsolationSheets.empty());
    ASSERT_FALSE(lineage.sourceCharts.empty());
    ASSERT_TRUE(lineage.sourceSupport.has_value());
    auto &sheets = lineage.sourcePoint.face < 2 ? firstComponentSheets
                                                : secondComponentSheets;
    for (const auto sheet : lineage.sourceIsolationSheets) {
      sheets.insert(sheet.index());
    }
  }
  ASSERT_FALSE(firstComponentSheets.empty());
  ASSERT_FALSE(secondComponentSheets.empty());
  EXPECT_LT(*firstComponentSheets.rbegin(), *secondComponentSheets.begin());
}

TEST(SurfaceCellAuthorityContractCutover,
     ProductionAggregationRejectsUnownedTypedRemapWithZeroPublication) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [](const std::size_t componentIndex,
             directional::pipeline::RemeshResult &componentResult) {
            if (componentIndex != 0U ||
                componentResult.outputVertexLineage.empty()) {
              return;
            }
            const auto unowned =
                directional::authority::TopologyRegionId::from_index(99, 128);
            if (!unowned) return;
            componentResult.outputVertexLineage.front().sourceTopologyRegions =
                {unowned.value()};
          });

  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("InvalidTypedComponentAuthorityRemap",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_TRUE(rejected.outputVertexProvenance.empty());
  EXPECT_TRUE(rejected.outputVertexLineage.empty());
  EXPECT_TRUE(rejected.outputQuadLineage.empty());
  EXPECT_TRUE(rejected.surfaceCellContext.completedPatches.empty());
}


TEST(SurfaceCellAuthorityContractCutover,
     PostMoveAggregateOptimizerUsesRetainedSourceAuthority) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  const auto result =
      directional::pipeline::remesh_surface_cell_components_from_cross_field(
          mesh.V, mesh.F, crossField, options);

  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ':'
      << result.diagnostics.terminalFailureStage;
  ASSERT_TRUE(result.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_TRUE(result.surfaceCellContext.sourceTopologyRegions->matches_source_faces(
      mesh.F, static_cast<std::size_t>(mesh.V.rows())));
}

TEST(SurfaceCellAuthorityContractCutover,
     DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  const auto result =
      directional::pipeline::remesh_surface_cell_components_from_cross_field(
          mesh.V, mesh.F, crossField, options);
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ':'
      << result.diagnostics.terminalFailureStage;
  ASSERT_TRUE(result.surfaceCellContext.sourceTopologyRegions.has_value());
  const auto &authority =
      result.surfaceCellContext.sourceTopologyRegions.value();
  EXPECT_TRUE(authority.matches_source_faces(
      mesh.F, static_cast<std::size_t>(mesh.V.rows())));

  const auto row0 = directional::authority::SourceFaceId::from_index(
      0, authority.face_count());
  const auto row2 = directional::authority::SourceFaceId::from_index(
      2, authority.face_count());
  ASSERT_TRUE(row0);
  ASSERT_TRUE(row2);
  EXPECT_NE(authority.component_for_row(row0.value()),
            authority.component_for_row(row2.value()));
  EXPECT_NE(authority.region_for_row(row0.value()),
            authority.region_for_row(row2.value()));
  EXPECT_NE(authority.sheet_for_row(row0.value()),
            authority.sheet_for_row(row2.value()));

  for (const auto &lineage : result.outputVertexLineage) {
    ASSERT_TRUE(lineage.stitchIdentity.valid());
    ASSERT_TRUE(lineage.authoritativeIdentity.valid());
    EXPECT_EQ(
        lineage.authoritativeIdentity,
        directional::geometry::pure_quad_detail::canonical_authoritative_identity(
            lineage, mesh.F, authority));
  }
  for (const auto &lineage : result.outputQuadLineage) {
    EXPECT_NE(0U, lineage.canonicalStitchCycleHash);
    EXPECT_NE(0U, lineage.canonicalAuthoritativeCycleHash);
  }
  ASSERT_TRUE(result.surfaceCellContext.hasValidationResult);
  ASSERT_TRUE(
      result.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
  EXPECT_TRUE(result.surfaceCellContext.componentValidationReportsComplete);
  const auto &finalValidation = result.surfaceCellContext.validationResult;
  const auto &finalSourceAuthorityValidation =
      result.surfaceCellContext.finalSourceAuthorityValidationResult;
  ASSERT_TRUE(finalSourceAuthorityValidation.accepted);
  EXPECT_EQ(finalSourceAuthorityValidation.strictValidationUsed,
            finalValidation.strictValidationUsed);
  EXPECT_EQ(finalSourceAuthorityValidation.provenanceValidationUsed,
            finalValidation.provenanceValidationUsed);
  EXPECT_EQ(finalSourceAuthorityValidation.sourceAuthorityUsed,
            finalValidation.sourceAuthoritativeValidationUsed);
  EXPECT_EQ(finalSourceAuthorityValidation.boundaryAuthorityUsed,
            finalValidation.authoritativeBoundaryUsed);
  EXPECT_EQ(finalSourceAuthorityValidation.featureRailAuthorityUsed,
            finalValidation.authoritativeFeatureRailsUsed);
  EXPECT_TRUE(finalValidation.sourceAuthoritativeValidationUsed);
  EXPECT_TRUE(finalValidation.authoritativeBoundaryUsed);
  EXPECT_TRUE(finalValidation.authoritativeFeatureRailsPassed);
  EXPECT_TRUE(finalValidation.orderedBoundaryCyclesPassed);
  EXPECT_TRUE(finalValidation.localSheetCompatibilityPassed);
  EXPECT_TRUE(finalValidation.strictValidationIssues.empty());

  bool sawGeneratedInterior = false;
  for (const auto &patch : result.surfaceCellContext.completedPatches) {
    ASSERT_EQ(patch.boundaryVertices.size(),
              patch.boundaryNodeIdentities.size());
    for (std::size_t row = 0; row < patch.vertexLineage.size(); ++row) {
      const auto &lineage = patch.vertexLineage[row];
      ASSERT_TRUE(lineage.stitchIdentity.valid());
      ASSERT_TRUE(lineage.authoritativeIdentity.valid());
      EXPECT_EQ(
          directional::geometry::pure_quad_detail::canonical_lineage_stitch_identity(
              patch, static_cast<int>(row)),
          lineage.stitchIdentity);
      EXPECT_EQ(
          lineage.authoritativeIdentity,
          directional::geometry::pure_quad_detail::canonical_authoritative_identity(
              lineage, mesh.F, authority));
      sawGeneratedInterior =
          sawGeneratedInterior ||
          lineage.stitchIdentity.kind ==
              directional::geometry::PureQuadStitchIdentityKind::GeneratedPatchInterior;
    }
    for (const auto &lineage : patch.quadLineage) {
      EXPECT_NE(0U, lineage.canonicalStitchCycleHash);
      EXPECT_NE(0U, lineage.canonicalAuthoritativeCycleHash);
    }
  }
  EXPECT_TRUE(sawGeneratedInterior)
      << "fixture must exercise generated-interior canonical identity";
  const auto restitched = directional::geometry::stitch_pure_quad_patches(
      result.surfaceCellContext.completedPatches, 1.0e-9, &mesh.F, &authority);
  EXPECT_TRUE(restitched.success) << restitched.failure;
}

TEST(SurfaceCellAuthorityContractCutover,
     DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  constexpr std::int64_t staleToken = 0x5354414c45;
  const auto result = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [staleToken](const std::size_t,
             directional::pipeline::RemeshResult &componentResult) {
            const auto makeStale = [staleToken](auto &lineage) {
              if (lineage.stitchIdentity.valid()) {
                lineage.stitchIdentity.kind =
                    lineage.stitchIdentity.kind ==
                            directional::geometry::PureQuadStitchIdentityKind::
                                ArrangementBoundaryNode
                        ? directional::geometry::PureQuadStitchIdentityKind::
                              GeneratedPatchInterior
                        : directional::geometry::PureQuadStitchIdentityKind::
                              ArrangementBoundaryNode;
                lineage.stitchIdentity.canonical.valid = true;
                lineage.stitchIdentity.canonical.values = {staleToken};
              }
              if (lineage.authoritativeIdentity.valid()) {
                lineage.authoritativeIdentity.canonical.valid = true;
                lineage.authoritativeIdentity.canonical.values = {staleToken};
              }
            };
            for (auto &lineage : componentResult.outputVertexLineage) {
              makeStale(lineage);
            }
            for (auto &patch :
                 componentResult.surfaceCellContext.completedPatches) {
              for (auto &lineage : patch.vertexLineage) {
                makeStale(lineage);
              }
              for (auto &identity : patch.boundaryNodeIdentities) {
                identity.valid = true;
                identity.values = {staleToken};
              }
            }
          });

  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ':'
      << result.diagnostics.terminalFailureStage;
  ASSERT_TRUE(result.surfaceCellContext.sourceTopologyRegions.has_value());
  const auto &authority =
      result.surfaceCellContext.sourceTopologyRegions.value();
  for (const auto &lineage : result.outputVertexLineage) {
    EXPECT_TRUE(lineage.stitchIdentity.valid());
    EXPECT_TRUE(lineage.authoritativeIdentity.valid());
    EXPECT_NE((std::vector<std::int64_t>{staleToken}),
              lineage.stitchIdentity.canonical.values);
    EXPECT_EQ(
        lineage.authoritativeIdentity,
        directional::geometry::pure_quad_detail::canonical_authoritative_identity(
            lineage, mesh.F, authority));
  }
  for (const auto &patch : result.surfaceCellContext.completedPatches) {
    for (std::size_t row = 0; row < patch.vertexLineage.size(); ++row) {
      EXPECT_EQ(
          directional::geometry::pure_quad_detail::canonical_lineage_stitch_identity(
              patch, static_cast<int>(row)),
          patch.vertexLineage[row].stitchIdentity);
    }
    for (const auto &identity : patch.boundaryNodeIdentities) {
      EXPECT_NE((std::vector<std::int64_t>{staleToken}), identity.values);
    }
  }
}

TEST(SurfaceCellAuthorityContractCutover,
     ComponentBoundaryRailTamperRejectsAtAggregationSeam) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool mutated = false;
  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&mutated](const std::size_t componentIndex,
                     directional::pipeline::RemeshResult &componentResult) {
            if (componentIndex != 1U) return;
            auto &rails = componentResult.surfaceCellContext.authoritativeRails;
            const auto boundary = std::find_if(
                rails.begin(), rails.end(), [](const auto &rail) {
                  return rail.kind ==
                         directional::geometry::SurfaceCellRailKind::Boundary;
                });
            if (boundary == rails.end()) return;
            rails.erase(boundary);
            mutated = true;
          });

  ASSERT_TRUE(mutated) << "fixture must expose component boundary authority";
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("ChangedComponentValidationAuthority",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     ComponentFeatureRailTamperRejectsAtAggregationSeam) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.featureMap.userHardEdges.insert({0, 2});
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool mutated = false;
  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&mutated](const std::size_t componentIndex,
                     directional::pipeline::RemeshResult &componentResult) {
            if (componentIndex != 1U) return;
            auto &rails = componentResult.surfaceCellContext.authoritativeRails;
            const auto feature = std::find_if(
                rails.begin(), rails.end(), [](const auto &rail) {
                  return rail.kind ==
                         directional::geometry::SurfaceCellRailKind::HardFeature;
                });
            if (feature == rails.end()) return;
            rails.erase(feature);
            mutated = true;
          });

  ASSERT_TRUE(mutated) << "fixture must expose hard-feature authority to tamper";
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("ChangedComponentValidationAuthority",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     FinalMergedOracleRejectsMissingRemappedBoundaryAuthority) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool reachedFinalOracleSeam = false;
  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&reachedFinalOracleSeam](
              directional::validation::SourceAuthoritativeMeshValidatorOptions
                  &validationOptions) {
            reachedFinalOracleSeam =
                !validationOptions.authoritativeBoundaryEdges.empty() ||
                !validationOptions.authoritativeBoundaryLoops.empty();
            validationOptions.authoritativeBoundaryEdges.clear();
            validationOptions.authoritativeBoundaryLoops.clear();
          });

  ASSERT_TRUE(reachedFinalOracleSeam)
      << "fixture must carry remapped boundary authority to the final oracle";
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("FinalMergedSourceAuthorityValidationFailed",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ("MissingBoundaryAuthority",
            rejected.diagnostics.surfaceCellFirstInvalidProducerValidationIssue);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_TRUE(rejected.outputVertexProvenance.empty());
  EXPECT_TRUE(rejected.outputVertexLineage.empty());
  EXPECT_TRUE(rejected.outputQuadLineage.empty());
  EXPECT_FALSE(rejected.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_FALSE(rejected.surfaceCellContext.hasCompletedPatches);
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
  EXPECT_FALSE(
      rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     FinalMergedOracleRejectsMissingRemappedFeatureAuthority) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.featureMap.userHardEdges.insert({0, 2});
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool reachedFinalOracleSeam = false;
  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&reachedFinalOracleSeam](
              directional::validation::SourceAuthoritativeMeshValidatorOptions
                  &validationOptions) {
            reachedFinalOracleSeam =
                validationOptions.expectedFeatureRailCount > 0U &&
                !validationOptions.authoritativeFeatureRails.empty();
            validationOptions.authoritativeFeatureRails.clear();
          });

  ASSERT_TRUE(reachedFinalOracleSeam)
      << "fixture must carry remapped hard-feature authority to the final oracle";
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("FinalMergedSourceAuthorityValidationFailed",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ("MissingFeatureRail",
            rejected.diagnostics.surfaceCellFirstInvalidProducerValidationIssue);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_TRUE(rejected.outputVertexProvenance.empty());
  EXPECT_TRUE(rejected.outputVertexLineage.empty());
  EXPECT_TRUE(rejected.outputQuadLineage.empty());
  EXPECT_FALSE(rejected.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_FALSE(rejected.surfaceCellContext.hasCompletedPatches);
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
  EXPECT_FALSE(
      rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool reachedFinalOracleSeam = false;
  bool mutatedBoundaryContent = false;
  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&reachedFinalOracleSeam, &mutatedBoundaryContent](
              directional::validation::SourceAuthoritativeMeshValidatorOptions
                  &validationOptions) {
            if (validationOptions.authoritativeBoundaryLoops.size() < 2U ||
                validationOptions.authoritativeBoundaryLoops[0].size() < 3U ||
                validationOptions.authoritativeBoundaryLoops[1].empty()) {
              return;
            }
            auto &loop = validationOptions.authoritativeBoundaryLoops.front();
            const int replacement =
                validationOptions.authoritativeBoundaryLoops[1].front();
            if (std::find(loop.begin(), loop.end(), replacement) != loop.end()) {
              return;
            }

            reachedFinalOracleSeam =
                !validationOptions.authoritativeBoundaryEdges.empty();
            loop.front() = replacement;
            validationOptions.authoritativeBoundaryEdges.clear();
            for (const auto &boundaryLoop :
                 validationOptions.authoritativeBoundaryLoops) {
              for (std::size_t index = 0; index < boundaryLoop.size(); ++index) {
                const int a = boundaryLoop[index];
                const int b =
                    boundaryLoop[(index + 1U) % boundaryLoop.size()];
                validationOptions.authoritativeBoundaryEdges.insert(
                    {std::min(a, b), std::max(a, b)});
              }
            }
            mutatedBoundaryContent = true;
          });

  ASSERT_TRUE(reachedFinalOracleSeam)
      << "fixture must carry present remapped boundary authority";
  ASSERT_TRUE(mutatedBoundaryContent)
      << "fixture must expose two disjoint aggregate boundary loops";
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("FinalMergedSourceAuthorityValidationFailed",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ("ChangedBoundaryLoop",
            rejected.diagnostics.surfaceCellFirstInvalidProducerValidationIssue);
  const auto &issues =
      rejected.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues;
  EXPECT_NE(std::find(issues.begin(), issues.end(), "ChangedBoundaryLoop"),
            issues.end());
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_TRUE(rejected.outputVertexProvenance.empty());
  EXPECT_TRUE(rejected.outputVertexLineage.empty());
  EXPECT_TRUE(rejected.outputQuadLineage.empty());
  EXPECT_FALSE(rejected.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_FALSE(rejected.surfaceCellContext.hasCompletedPatches);
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
  EXPECT_FALSE(
      rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     FinalMergedOracleRejectsChangedRemappedFeatureRailContent) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.featureMap.userHardEdges.insert({0, 2});
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool reachedFinalOracleSeam = false;
  bool mutatedFeatureContent = false;
  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&reachedFinalOracleSeam, &mutatedFeatureContent](
              directional::validation::SourceAuthoritativeMeshValidatorOptions
                  &validationOptions) {
            if (validationOptions.authoritativeFeatureRails.empty() ||
                validationOptions.expectedFeatureRailCount == 0U ||
                validationOptions.authoritativeBoundaryLoops.size() < 2U ||
                validationOptions.authoritativeBoundaryLoops[0].empty() ||
                validationOptions.authoritativeBoundaryLoops[1].empty()) {
              return;
            }
            reachedFinalOracleSeam =
                validationOptions.authoritativeFeatureRails.size() ==
                validationOptions.expectedFeatureRailCount;
            const int first =
                validationOptions.authoritativeBoundaryLoops[0].front();
            const int second =
                validationOptions.authoritativeBoundaryLoops[1].front();
            validationOptions.authoritativeFeatureRails.front() = {first, second};
            mutatedFeatureContent = true;
          });

  ASSERT_TRUE(reachedFinalOracleSeam)
      << "fixture must carry non-empty remapped feature authority";
  ASSERT_TRUE(mutatedFeatureContent)
      << "fixture must expose two disconnected boundary loops";
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("FinalMergedSourceAuthorityValidationFailed",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ("MissingFeatureRail",
            rejected.diagnostics.surfaceCellFirstInvalidProducerValidationIssue);
  const auto &issues =
      rejected.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues;
  EXPECT_NE(std::find(issues.begin(), issues.end(), "MissingFeatureRail"),
            issues.end());
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_TRUE(rejected.outputVertexProvenance.empty());
  EXPECT_TRUE(rejected.outputVertexLineage.empty());
  EXPECT_TRUE(rejected.outputQuadLineage.empty());
  EXPECT_FALSE(rejected.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_FALSE(rejected.surfaceCellContext.hasCompletedPatches);
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
  EXPECT_FALSE(
      rejected.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.featureMap.userHardEdges.insert({0, 2});
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool observedNonEmptyFeatureAuthority = false;
  const auto result = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&observedNonEmptyFeatureAuthority](
              directional::validation::SourceAuthoritativeMeshValidatorOptions
                  &validationOptions) {
            observedNonEmptyFeatureAuthority =
                validationOptions.expectedFeatureRailCount > 0U &&
                validationOptions.authoritativeFeatureRails.size() ==
                    validationOptions.expectedFeatureRailCount &&
                std::all_of(
                    validationOptions.authoritativeFeatureRails.begin(),
                    validationOptions.authoritativeFeatureRails.end(),
                    [](const auto &rail) { return rail.size() >= 2U; });
          });

  ASSERT_TRUE(observedNonEmptyFeatureAuthority)
      << "fixture must reach the final oracle with non-empty feature authority";
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ':'
      << result.diagnostics.terminalFailureStage;
  ASSERT_TRUE(result.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
  const auto &oracle =
      result.surfaceCellContext.finalSourceAuthorityValidationResult;
  EXPECT_TRUE(oracle.accepted);
  EXPECT_TRUE(oracle.sourceAuthorityUsed);
  EXPECT_TRUE(oracle.boundaryAuthorityUsed);
  EXPECT_TRUE(oracle.featureRailsPassed);
  EXPECT_TRUE(oracle.orderedBoundaryCyclesPassed);
  EXPECT_TRUE(oracle.localSheetCompatibilityPassed);
  EXPECT_TRUE(oracle.issues.empty());
  ASSERT_TRUE(result.surfaceCellContext.hasValidationResult);
  EXPECT_TRUE(
      result.surfaceCellContext.validationResult.authoritativeFeatureRailsPassed);
}

TEST(SurfaceCellAuthorityContractCutover,
     FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  bool removedComponentReport = false;
  const auto result = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [&removedComponentReport](
              const std::size_t componentIndex,
              directional::pipeline::RemeshResult &componentResult) {
            if (componentIndex != 1U ||
                !componentResult.surfaceCellContext.hasValidationResult) {
              return;
            }
            componentResult.surfaceCellContext.hasValidationResult = false;
            removedComponentReport = true;
          });

  ASSERT_TRUE(removedComponentReport)
      << "fixture must remove one component report after authority capture";
  ASSERT_TRUE(result.success)
      << result.diagnostics.terminalFailureCode << ':'
      << result.diagnostics.terminalFailureStage;
  EXPECT_FALSE(result.surfaceCellContext.hasValidationResult);
  EXPECT_FALSE(result.surfaceCellContext.componentValidationReportsComplete);
  ASSERT_TRUE(
      result.surfaceCellContext.hasFinalSourceAuthorityValidationResult);
  const auto &oracle =
      result.surfaceCellContext.finalSourceAuthorityValidationResult;
  EXPECT_TRUE(oracle.accepted);
  EXPECT_TRUE(oracle.sourceAuthorityUsed);
  EXPECT_TRUE(oracle.provenanceValidationUsed);
  EXPECT_TRUE(oracle.boundaryAuthorityUsed);
  EXPECT_TRUE(oracle.orderedBoundaryCyclesPassed);
  EXPECT_TRUE(oracle.featureRailsPassed);
  EXPECT_TRUE(oracle.localSheetCompatibilityPassed);
  EXPECT_TRUE(oracle.issues.empty());
}

TEST(SurfaceCellAuthorityContractCutover,
     SecondComponentAuthorityFailurePublishesNoSemanticAggregateContext) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [](const std::size_t componentIndex,
             directional::pipeline::RemeshResult &componentResult) {
            if (componentIndex != 1U ||
                componentResult.outputVertexLineage.empty()) {
              return;
            }
            const auto unowned =
                directional::authority::TopologyRegionId::from_index(99, 128);
            if (!unowned) return;
            componentResult.outputVertexLineage.front().sourceTopologyRegions =
                {unowned.value()};
          });

  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_TRUE(rejected.outputVertexProvenance.empty());
  EXPECT_TRUE(rejected.outputVertexLineage.empty());
  EXPECT_TRUE(rejected.outputQuadLineage.empty());
  EXPECT_EQ(0, rejected.rawCrossField.size());
  EXPECT_TRUE(rejected.surfaceCellContext.completedPatches.empty());
  EXPECT_TRUE(rejected.surfaceCellContext.authoritativeRails.empty());
  EXPECT_TRUE(rejected.surfaceCellContext.debugProducts.empty());
  EXPECT_TRUE(rejected.surfaceCellContext.sourceSurfaceLabels.componentByFace.empty());
  EXPECT_TRUE(rejected.surfaceCellContext.sourceSurfaceLabels.localSheetByFace.empty());
  EXPECT_FALSE(rejected.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_FALSE(rejected.surfaceCellContext.hasSourceMesh);
  EXPECT_FALSE(rejected.surfaceCellContext.hasCrossField);
  EXPECT_FALSE(rejected.surfaceCellContext.hasSourceSurfaceLabels);
  EXPECT_FALSE(rejected.surfaceCellContext.hasAuthoritativeRails);
  EXPECT_FALSE(rejected.surfaceCellContext.hasCompletedPatches);
  EXPECT_FALSE(rejected.surfaceCellContext.hasOptimizationResult);
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     FinalMergedOracleRejectsPostComponentProvenanceTamper) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;
  options.lengthRatio = 0.2;

  const auto rejected = directional::pipeline::remesh_pipeline_detail::
      remesh_surface_cell_components_from_cross_field_counterfactual(
          mesh.V, mesh.F, crossField, options,
          [](const std::size_t componentIndex,
             directional::pipeline::RemeshResult &componentResult) {
            if (componentIndex != 1U ||
                componentResult.outputVertexProvenance.empty()) {
              return;
            }
            auto &point = componentResult.outputVertexProvenance.front();
            point.barycentric << 1.0, 0.0, 0.0;
          });

  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("component-merge-authority",
            rejected.diagnostics.terminalFailureStage);
  EXPECT_EQ("FinalMergedSourceAuthorityValidationFailed",
            rejected.diagnostics.surfaceCellFirstInvalidProducerReason);
  EXPECT_EQ(0, rejected.vertices.rows());
  EXPECT_EQ(0, rejected.faces.rows());
  EXPECT_FALSE(rejected.surfaceCellContext.sourceTopologyRegions.has_value());
  EXPECT_FALSE(rejected.surfaceCellContext.hasValidationResult);
}

TEST(SurfaceCellAuthorityContractCutover,
     SameExtentForeignSourceTopologyDoesNotMatchPublishedAuthority) {
  const directional::TriMesh mesh = make_square_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.5);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());
  const auto &authority =
      network.phaseFront.product().sourceTopologyRegions;
  ASSERT_TRUE(authority.matches_source_faces(
      mesh.F, static_cast<std::size_t>(mesh.V.rows())));

  Eigen::MatrixXi foreignFaces = mesh.F;
  ASSERT_GE(foreignFaces.rows(), 1);
  foreignFaces.row(0) << 0, 1, 3;
  EXPECT_FALSE(authority.matches_source_faces(
      foreignFaces, static_cast<std::size_t>(mesh.V.rows())));
  directional::geometry::SourceChartTransitionGraph foreignTransitions(
      foreignFaces, authority);
  EXPECT_FALSE(foreignTransitions.available());
}

TEST(SurfaceCellAuthorityContractCutover,
     AuthorityOnlyFaceRowPermutationRejectsExactTopologyBinding) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh(false);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(mesh.F, options);
  ASSERT_TRUE(authority.has_value());
  ASSERT_TRUE(authority->matches_source_faces(
      mesh.F, static_cast<std::size_t>(mesh.V.rows())));

  Eigen::MatrixXi permuted = mesh.F;
  ASSERT_GE(permuted.rows(), 2);
  permuted.row(0).swap(permuted.row(1));
  EXPECT_FALSE(authority->matches_source_faces(
      permuted, static_cast<std::size_t>(mesh.V.rows())));
  directional::geometry::SourceChartTransitionGraph mismatched(
      permuted, authority.value());
  EXPECT_FALSE(mismatched.available());
}

TEST(SurfaceCellAuthorityContractCutover,
     ConsistentlyPermutedSourceMatrixAndAuthorityPreserveSemanticTopology) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh(false);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto forwardAuthority =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(mesh.F, options);
  ASSERT_TRUE(forwardAuthority.has_value());

  Eigen::MatrixXi permuted = mesh.F;
  ASSERT_GE(permuted.rows(), 4);
  permuted.row(0).swap(permuted.row(3));
  permuted.row(1).swap(permuted.row(2));
  const auto permutedAuthority =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(permuted, options);
  ASSERT_TRUE(permutedAuthority.has_value());
  EXPECT_TRUE(permutedAuthority->matches_source_faces(
      permuted, static_cast<std::size_t>(mesh.V.rows())));
  EXPECT_FALSE(forwardAuthority->matches_source_faces(
      permuted, static_cast<std::size_t>(mesh.V.rows())));

  const auto snapshot = [](const auto &authority) {
    std::multiset<std::tuple<std::uint64_t, int, int, std::size_t>> result;
    for (const auto &region : authority.regions()) {
      result.emplace(directional::geometry::surface_topology_region_hash(region),
                     region.euler_characteristic(),
                     region.boundary_loop_count(), region.faces().size());
    }
    return result;
  };
  EXPECT_EQ(snapshot(forwardAuthority.value()),
            snapshot(permutedAuthority.value()));
}

TEST(SurfaceCellAuthorityContractCutover,
     FaceRowPermutationPreservesSemanticRegionIdentity) {
  const directional::TriMesh forwardMesh = make_disconnected_square_pair_mesh(false);
  const directional::TriMesh reverseMesh = make_disconnected_square_pair_mesh(true);
  const auto forwardField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          forwardMesh, constant_xy_raw_field(forwardMesh.F.rows()));
  const auto reverseField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reverseMesh, constant_xy_raw_field(reverseMesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(forwardMesh.V.rows(), 0.5);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);

  const auto forward = directional::geometry::build_surface_cell_network(
      forwardMesh.V, forwardMesh.F, forwardField, targetSize, options);
  const auto reverse = directional::geometry::build_surface_cell_network(
      reverseMesh.V, reverseMesh.F, reverseField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition());
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition());

  const auto snapshot = [](const auto &network) {
    std::multiset<std::pair<std::uint64_t, int>> result;
    for (const auto &region : network.phaseFront.product().sourceTopologyRegions.regions()) {
      const int cellCount = static_cast<int>(std::count_if(
          network.phaseFront.product().cells.begin(), network.phaseFront.product().cells.end(),
          [&](const auto &cell) { return cell.sourceTopologyRegion == region.id(); }));
      result.emplace(
          directional::geometry::surface_topology_region_hash(region), cellCount);
    }
    return result;
  };
  EXPECT_EQ(snapshot(forward), snapshot(reverse));
}

TEST(SurfaceCellAuthorityContractCutover,
     ConflictingCellRegionFailsBeforeMaterialization) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.5);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());
  ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  ASSERT_FALSE(network.phaseFront.product().cells.empty());

  auto changed = network.phaseFront.product();
  const auto current = changed.cells.front().sourceTopologyRegion;
  const auto replacement = std::find_if(
      changed.sourceTopologyRegions.regions().begin(),
      changed.sourceTopologyRegions.regions().end(),
      [&](const auto &region) { return region.id() != current; });
  ASSERT_NE(changed.sourceTopologyRegions.regions().end(), replacement);
  changed.cells.front().sourceTopologyRegion = replacement->id();
  const auto rejected = directional::pipeline::build_authoritative_phase_front_mesh(
      mesh.V, mesh.F, changed);
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("AuthoritativePhaseFrontSourceLabelMismatch", rejected.failure);
}

TEST(SurfaceCellAuthorityContractCutover,
     ConflictingEdgeRegionFailsBeforeMaterialization) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.5);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());
  ASSERT_EQ(2U, network.phaseFront.product().sourceTopologyRegions.regions().size());
  ASSERT_FALSE(network.phaseFront.product().edges.empty());

  auto changed = network.phaseFront.product();
  const auto current = changed.edges.front().sourceTopologyRegion;
  const auto replacement = std::find_if(
      changed.sourceTopologyRegions.regions().begin(),
      changed.sourceTopologyRegions.regions().end(),
      [&](const auto &region) { return region.id() != current; });
  ASSERT_NE(changed.sourceTopologyRegions.regions().end(), replacement);
  changed.edges.front().sourceTopologyRegion = replacement->id();
  const auto rejected = directional::pipeline::build_authoritative_phase_front_mesh(
      mesh.V, mesh.F, changed);
  EXPECT_FALSE(rejected.success);
  EXPECT_EQ("InvalidAuthoritativePhaseFrontSideAuthority", rejected.failure);
}

TEST(SurfaceCellAuthorityContractCutover,
     RequiredRegionReferencesCannotPublishMissingAuthority) {
  static_assert(!std::is_default_constructible_v<
                directional::geometry::SurfacePhaseFrontCell>);
  static_assert(!std::is_default_constructible_v<
                directional::geometry::SurfaceFrontEdge>);
  static_assert(!std::is_default_constructible_v<
                directional::geometry::SurfacePeriodicHolonomy>);
  static_assert(!std::is_default_constructible_v<
                directional::geometry::SurfaceBoundedDiskBoundaryPhase>);
}

TEST(SurfaceCellAuthorityContractCutover,
     MaterializerConsumesPublishedTopologyRegionsExactlyOnce) {
  const directional::TriMesh mesh = make_disconnected_square_pair_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.5);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition());

  const auto materialized = directional::pipeline::build_authoritative_phase_front_mesh(
      mesh.V, mesh.F, network.phaseFront.product());
  ASSERT_TRUE(materialized.success) << materialized.failure;
  EXPECT_EQ(network.phaseFront.product().sourceTopologyRegions.regions().size(),
            materialized.consumedTopologyRegions);
  EXPECT_EQ(static_cast<std::size_t>(mesh.F.rows()),
            network.phaseFront.product().sourceTopologyRegions.face_count());
}

} // namespace
