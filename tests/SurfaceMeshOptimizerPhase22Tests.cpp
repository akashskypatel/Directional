#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/SurfaceOptimizationRailConstraints.h>
#include <directional/validation/SourceAuthoritativeMeshValidator.h>

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::SurfaceOptimizationConstraints;
using directional::geometry::SurfaceOptimizationResult;
using directional::geometry::SurfacePoint;
using directional::validation::MeshValidationFailureCode;
using directional::validation::SourceAuthoritativeMeshValidatorOptions;

bool has_code(
    const directional::validation::SourceAuthoritativeMeshValidationResult &result,
    const MeshValidationFailureCode code) {
  return std::any_of(result.issues.begin(), result.issues.end(),
                     [&](const auto &issue) { return issue.code == code; });
}

Eigen::MatrixXd square_vertices() {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  return vertices;
}

Eigen::MatrixXi square_triangles() {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
      0, 2, 3;
  return faces;
}

Eigen::MatrixXi one_quad() {
  Eigen::MatrixXi quads(1, 4);
  quads << 0, 1, 2, 3;
  return quads;
}

std::vector<SurfacePoint> provenance_for(
    const Eigen::MatrixXd &output, const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const std::vector<int> &components,
    const std::vector<int> &sheets) {
  directional::geometry::SurfaceProjectionBvh bvh(sourceVertices, sourceFaces);
  directional::geometry::SurfaceProjectionOptions options;
  options.faceComponents = &components;
  options.faceSheets = &sheets;
  std::vector<SurfacePoint> provenance;
  provenance.reserve(static_cast<std::size_t>(output.rows()));
  for (int vertex = 0; vertex < output.rows(); ++vertex) {
    provenance.push_back(bvh.project(output.row(vertex).transpose(), options));
  }
  return provenance;
}

SourceAuthoritativeMeshValidatorOptions make_options(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const std::vector<int> &components, const std::vector<int> &sheets,
    const std::vector<SurfacePoint> &provenance,
    std::vector<std::vector<int>> boundaryLoops) {
  SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &sourceVertices;
  options.sourceFaces = &sourceFaces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
  options.vertexProvenance = &provenance;
  options.authoritativeBoundaryLoops = std::move(boundaryLoops);
  return options;
}

SurfaceOptimizationConstraints make_final_constraints(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const std::vector<SurfacePoint> &provenance) {
  SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = sourceVertices;
  constraints.sourceFaces = sourceFaces;
  constraints.sourcePositions = sourceVertices;
  constraints.sourceNormals = Eigen::MatrixXd::Zero(sourceFaces.rows(), 3);
  constraints.sourceFieldX = Eigen::MatrixXd::Zero(sourceFaces.rows(), 3);
  constraints.sourceFieldY = Eigen::MatrixXd::Zero(sourceFaces.rows(), 3);
  for (int face = 0; face < sourceFaces.rows(); ++face) {
    constraints.sourceNormals.row(face) << 0.0, 0.0, 1.0;
    constraints.sourceFieldX.row(face) << 1.0, 0.0, 0.0;
    constraints.sourceFieldY.row(face) << 0.0, 1.0, 0.0;
  }
  constraints.sourceFaceComponent.assign(
      static_cast<std::size_t>(sourceFaces.rows()), 0);
  constraints.sourceFaceSheet.assign(
      static_cast<std::size_t>(sourceFaces.rows()), 0);
  constraints.localTargetSize = Eigen::VectorXd::Ones(sourceVertices.rows());
  constraints.vertexProvenance = provenance;
  constraints.authoritativeBoundaryLoop = {0, 1, 2, 3};
  constraints.authoritativeBoundaryLoops = {{0, 1, 2, 3}};
  constraints.authoritativeBoundaryEdges = {{0, 1}, {1, 2}, {2, 3}, {0, 3}};
  constraints.requireSourceAuthoritativeValidation = true;
  return constraints;
}

void make_annulus(Eigen::MatrixXd &vertices, Eigen::MatrixXi &triangles,
                  Eigen::MatrixXi &quads) {
  vertices.resize(8, 3);
  vertices << 0.0, 0.0, 0.0,
      3.0, 0.0, 0.0,
      3.0, 3.0, 0.0,
      0.0, 3.0, 0.0,
      1.0, 1.0, 0.0,
      2.0, 1.0, 0.0,
      2.0, 2.0, 0.0,
      1.0, 2.0, 0.0;
  quads.resize(4, 4);
  quads << 0, 1, 5, 4,
      1, 2, 6, 5,
      2, 3, 7, 6,
      3, 0, 4, 7;
  triangles.resize(8, 3);
  int row = 0;
  for (int face = 0; face < quads.rows(); ++face) {
    triangles.row(row++) << quads(face, 0), quads(face, 1), quads(face, 2);
    triangles.row(row++) << quads(face, 0), quads(face, 2), quads(face, 3);
  }
}

} // namespace

TEST(SurfaceMeshOptimizerPhase22,
     ValidMeshPassesSourceTopologyBoundaryProvenanceAndSpatialChecks) {
  const Eigen::MatrixXd sourceVertices = square_vertices();
  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance = provenance_for(sourceVertices, sourceVertices,
                                         sourceFaces, components, sheets);
  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          sourceVertices, one_quad(),
          make_options(sourceVertices, sourceFaces, components, sheets,
                       provenance, {{0, 1, 2, 3}}));

  EXPECT_TRUE(result.accepted);
  EXPECT_TRUE(result.sourceAuthorityUsed);
  EXPECT_TRUE(result.provenanceCoverageComplete);
  EXPECT_TRUE(result.localSheetCompatibilityPassed);
  EXPECT_TRUE(result.orderedBoundaryCyclesPassed);
  EXPECT_TRUE(result.spatialAccelerationUsed);
  EXPECT_EQ(result.sourceTopology.eulerCharacteristic, 1);
  EXPECT_EQ(result.outputTopology.eulerCharacteristic, 1);
}

TEST(SurfaceMeshOptimizerPhase22, MissingOrInvalidProvenanceFailsClosed) {
  const Eigen::MatrixXd sourceVertices = square_vertices();
  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  std::vector<SurfacePoint> provenance;
  auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          sourceVertices, one_quad(),
          make_options(sourceVertices, sourceFaces, components, sheets,
                       provenance, {{0, 1, 2, 3}}));
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::MissingProvenance));

  provenance = provenance_for(sourceVertices, sourceVertices, sourceFaces,
                              components, sheets);
  provenance[2].barycentric << 2.0, -1.0, 0.0;
  result = directional::validation::validate_source_authoritative_surface_mesh(
      sourceVertices, one_quad(),
      make_options(sourceVertices, sourceFaces, components, sheets, provenance,
                   {{0, 1, 2, 3}}));
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::InvalidProvenance));
}

TEST(SurfaceMeshOptimizerPhase22,
     EulerCharacteristicAndAllOrderedBoundaryCyclesAreAuthoritative) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi triangles;
  Eigen::MatrixXi quads;
  make_annulus(vertices, triangles, quads);
  const std::vector<int> components(static_cast<std::size_t>(triangles.rows()),
                                    0);
  const std::vector<int> sheets(static_cast<std::size_t>(triangles.rows()), 0);
  const auto provenance =
      provenance_for(vertices, vertices, triangles, components, sheets);

  auto valid = directional::validation::validate_source_authoritative_surface_mesh(
      vertices, quads,
      make_options(vertices, triangles, components, sheets, provenance,
                   {{0, 1, 2, 3}, {4, 5, 6, 7}}));
  EXPECT_TRUE(valid.accepted);
  EXPECT_EQ(valid.sourceTopology.eulerCharacteristic, 0);
  EXPECT_EQ(valid.outputTopology.boundaryLoopCount, 2);

  auto missingLoop =
      directional::validation::validate_source_authoritative_surface_mesh(
          vertices, quads,
          make_options(vertices, triangles, components, sheets, provenance,
                       {{0, 1, 2, 3}}));
  EXPECT_FALSE(missingLoop.accepted);
  EXPECT_TRUE(
      has_code(missingLoop, MeshValidationFailureCode::ChangedBoundaryLoop));

  const Eigen::MatrixXd diskSource = square_vertices();
  const Eigen::MatrixXi diskFaces = square_triangles();
  const std::vector<int> diskComponents = {0, 0};
  const std::vector<int> diskSheets = {0, 0};
  const auto ringOnDisk = provenance_for(vertices, diskSource, diskFaces,
                                         diskComponents, diskSheets);
  const auto changedEuler =
      directional::validation::validate_source_authoritative_surface_mesh(
          vertices, quads,
          make_options(diskSource, diskFaces, diskComponents, diskSheets,
                       ringOnDisk, {{0, 1, 2, 3}, {4, 5, 6, 7}}));
  EXPECT_FALSE(changedEuler.accepted);
  EXPECT_TRUE(has_code(changedEuler,
                       MeshValidationFailureCode::ChangedEulerCharacteristic));
}

TEST(SurfaceMeshOptimizerPhase22, MissingHardFeatureRailEdgeFailsClosed) {
  const Eigen::MatrixXd sourceVertices = square_vertices();
  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance = provenance_for(sourceVertices, sourceVertices,
                                         sourceFaces, components, sheets);
  auto options = make_options(sourceVertices, sourceFaces, components, sheets,
                              provenance, {{0, 1, 2, 3}});
  options.expectedFeatureRailCount = 1;
  options.authoritativeFeatureRails = {{0, 2}};

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          sourceVertices, one_quad(), options);
  EXPECT_FALSE(result.accepted);
  EXPECT_FALSE(result.featureRailsPassed);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::MissingFeatureRail));
}

TEST(SurfaceMeshOptimizerPhase22,
     SpatialFaceIndexDetectsCoplanarOverlappingDisconnectedFaces) {
  Eigen::MatrixXd sourceVertices(4, 3);
  sourceVertices << 0.0, 0.0, 0.0,
      3.0, 0.0, 0.0,
      3.0, 2.0, 0.0,
      0.0, 2.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXd output(8, 3);
  output << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      2.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      1.0, 0.25, 0.0,
      3.0, 0.25, 0.0,
      3.0, 1.25, 0.0,
      1.0, 1.25, 0.0;
  Eigen::MatrixXi quads(2, 4);
  quads << 0, 1, 2, 3,
      4, 5, 6, 7;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance =
      provenance_for(output, sourceVertices, sourceFaces, components, sheets);
  auto options = make_options(sourceVertices, sourceFaces, components, sheets,
                              provenance, {});
  options.requireBoundaryAuthority = false;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          output, quads, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(
      has_code(result, MeshValidationFailureCode::SelfIntersectingFace));
  EXPECT_TRUE(result.spatialAccelerationUsed);
}

TEST(SurfaceMeshOptimizerPhase22,
     ProvenanceComponentSheetAndFaceCompatibilityAreEnforced) {
  Eigen::MatrixXd source(8, 3);
  source << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      0.0, 0.0, 0.001,
      1.0, 0.0, 0.001,
      1.0, 1.0, 0.001,
      0.0, 1.0, 0.001;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3,
      4, 6, 5,
      4, 7, 6;
  const std::vector<int> components = {0, 0, 1, 1};
  const std::vector<int> sheets = {0, 0, 1, 1};
  Eigen::MatrixXd mixed(4, 3);
  mixed << source.row(0), source.row(1), source.row(6), source.row(7);
  auto provenance =
      provenance_for(mixed, source, sourceFaces, components, sheets);
  auto options = make_options(source, sourceFaces, components, sheets,
                              provenance, {{0, 1, 2, 3}});

  const auto mixedResult =
      directional::validation::validate_source_authoritative_surface_mesh(
          mixed, one_quad(), options);
  EXPECT_FALSE(mixedResult.accepted);
  EXPECT_TRUE(
      has_code(mixedResult, MeshValidationFailureCode::LocalSheetMismatch));

  provenance[0].component = 1;
  const auto wrongLabel =
      directional::validation::validate_source_authoritative_surface_mesh(
          mixed, one_quad(),
          make_options(source, sourceFaces, components, sheets, provenance,
                       {{0, 1, 2, 3}}));
  EXPECT_FALSE(wrongLabel.accepted);
  EXPECT_TRUE(has_code(wrongLabel,
                       MeshValidationFailureCode::SourceComponentMismatch));
}

TEST(SurfaceMeshOptimizerPhase22,
     FinalReportUsesSourceAuthorityAndRejectsAnyStrictIssue) {
  const Eigen::MatrixXd sourceVertices = square_vertices();
  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance = provenance_for(sourceVertices, sourceVertices,
                                         sourceFaces, components, sheets);
  auto constraints =
      make_final_constraints(sourceVertices, sourceFaces, provenance);
  SurfaceOptimizationResult optimization;
  optimization.vertices = sourceVertices;
  optimization.quads = one_quad();
  optimization.vertexProvenance = provenance;
  optimization.topologyHashFixed = true;
  optimization.featureParametersOrdered = true;
  optimization.projectionStayedOnComponents = true;
  optimization.projectionStayedOnSheets = true;

  const auto valid = directional::geometry::validate_final_surface_mesh(
      sourceVertices, one_quad(), constraints, optimization);
  EXPECT_TRUE(valid.accepted);
  EXPECT_TRUE(valid.sourceAuthoritativeValidationUsed);
  EXPECT_TRUE(valid.spatialAccelerationUsed);
  EXPECT_TRUE(valid.orderedBoundaryCyclesPassed);
  EXPECT_TRUE(valid.localSheetCompatibilityPassed);

  constraints.authoritativeBoundaryLoops.clear();
  constraints.authoritativeBoundaryLoop.clear();
  constraints.authoritativeBoundaryEdges.clear();
  const auto missingBoundary =
      directional::geometry::validate_final_surface_mesh(
          sourceVertices, one_quad(), constraints, optimization);
  EXPECT_FALSE(missingBoundary.accepted);
  EXPECT_GT(missingBoundary.boundaryCycleMismatchCount, 0);
}

TEST(SurfaceMeshOptimizerPhase22,
     SourceAuthoritativeHardInvariantCheckRejectsGeometricTJunction) {
  Eigen::MatrixXd sourceVertices(4, 3);
  sourceVertices << 0.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      2.0, 1.0, 0.0,
      0.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3;
  Eigen::MatrixXd output(5, 3);
  output << sourceVertices,
      1.0, 0.0, 0.0;
  Eigen::MatrixXi quads = one_quad();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance =
      provenance_for(output, sourceVertices, sourceFaces, components, sheets);
  auto constraints = make_final_constraints(sourceVertices, sourceFaces,
                                             provenance);
  constraints.requireSourceAuthoritativeValidation = true;

  EXPECT_FALSE(
      directional::geometry::source_authoritative_hard_invariants_valid(
          output, quads, constraints, provenance));
}



TEST(SurfaceMeshOptimizerPhase22,
     RailConstraintBuilderUsesOutputVertexSequencesForBoundaryAndFeatures) {
  using directional::geometry::SurfaceCellRail;
  using directional::geometry::SurfaceCellRailKind;
  using directional::geometry::SurfaceCellRailSample;

  SurfaceCellRail boundary;
  boundary.id = 1;
  boundary.curveId = 1;
  boundary.component = 0;
  boundary.kind = SurfaceCellRailKind::Boundary;
  boundary.closed = true;
  const Eigen::MatrixXd output = square_vertices();
  for (int edge = 0; edge < 4; ++edge) {
    SurfaceCellRailSample start;
    start.sourceFace = 0;
    start.railParameter = static_cast<double>(edge);
    start.position = output.row(edge);
    SurfaceCellRailSample end = start;
    end.railParameter = static_cast<double>(edge + 1);
    end.position = output.row((edge + 1) % 4);
    boundary.samples.push_back(start);
    boundary.samples.push_back(end);
  }

  SurfaceCellRail feature;
  feature.id = 2;
  feature.curveId = 7;
  feature.component = 0;
  feature.kind = SurfaceCellRailKind::HardFeature;
  feature.closed = false;
  SurfaceCellRailSample featureStart;
  featureStart.sourceFace = 0;
  featureStart.railParameter = 0.0;
  featureStart.position = output.row(0);
  SurfaceCellRailSample featureEnd = featureStart;
  featureEnd.railParameter = 1.0;
  featureEnd.position = output.row(1);
  feature.samples = {featureStart, featureEnd};

  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance = provenance_for(output, output, sourceFaces,
                                         components, sheets);
  SurfaceOptimizationConstraints boundaryConstraints;
  boundaryConstraints.sourceFaceSheet = sheets;
  directional::geometry::fill_surface_optimization_rail_constraints(
      {boundary}, output, provenance, boundaryConstraints);

  EXPECT_TRUE(boundaryConstraints.featureRailAuthorityProvided);
  ASSERT_EQ(boundaryConstraints.authoritativeBoundaryLoops.size(), 1U);
  EXPECT_EQ(boundaryConstraints.authoritativeBoundaryLoops.front(),
            (std::vector<int>{0, 1, 2, 3}));
  EXPECT_EQ(boundaryConstraints.authoritativeBoundaryEdges.size(), 4U);

  SurfaceOptimizationConstraints featureConstraints;
  featureConstraints.sourceFaceSheet = sheets;
  directional::geometry::fill_surface_optimization_rail_constraints(
      {feature}, output, provenance, featureConstraints);
  EXPECT_TRUE(featureConstraints.featureRailAuthorityProvided);
  EXPECT_EQ(featureConstraints.requiredFeatureRailCount, 1U);
  ASSERT_EQ(featureConstraints.authoritativeFeatureRails.size(), 1U);
  EXPECT_EQ(featureConstraints.authoritativeFeatureRails.front(),
            (std::vector<int>{0, 1}));
}

TEST(SurfaceMeshOptimizerPhase22,
     DuplicateFacesAndNonmanifoldIncidenceRemainHardFailures) {
  const Eigen::MatrixXd sourceVertices = square_vertices();
  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance = provenance_for(sourceVertices, sourceVertices,
                                         sourceFaces, components, sheets);
  Eigen::MatrixXi duplicated(3, 4);
  duplicated << 0, 1, 2, 3,
      0, 1, 2, 3,
      0, 1, 2, 3;
  auto options = make_options(sourceVertices, sourceFaces, components, sheets,
                              provenance, {});
  options.requireBoundaryAuthority = false;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          sourceVertices, duplicated, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::DuplicateFace));
  EXPECT_TRUE(
      has_code(result, MeshValidationFailureCode::ThreeSidedInteriorEdge));
}


TEST(SurfaceMeshOptimizerPhase22,
     ExplicitEmptyFeatureRailAuthorityIsReportedAsUsedAndPassed) {
  const Eigen::MatrixXd sourceVertices = square_vertices();
  const Eigen::MatrixXi sourceFaces = square_triangles();
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 0};
  const auto provenance = provenance_for(sourceVertices, sourceVertices,
                                         sourceFaces, components, sheets);
  SurfaceOptimizationConstraints constraints =
      make_final_constraints(sourceVertices, sourceFaces, provenance);
  constraints.featureRailAuthorityProvided = true;
  constraints.requiredFeatureRailCount = 0U;
  constraints.authoritativeFeatureRails.clear();

  SurfaceOptimizationResult optimization;
  optimization.vertices = sourceVertices;
  optimization.quads = one_quad();
  optimization.vertexProvenance = provenance;
  optimization.topologyHashFixed = true;
  optimization.featureParametersOrdered = true;
  optimization.projectionStayedOnComponents = true;
  optimization.projectionStayedOnSheets = true;

  const auto report = directional::geometry::validate_final_surface_mesh(
      sourceVertices, one_quad(), constraints, optimization);

  EXPECT_TRUE(report.accepted);
  EXPECT_TRUE(report.authoritativeFeatureRailsUsed);
  EXPECT_TRUE(report.authoritativeFeatureRailsPassed);
  EXPECT_EQ(report.featureRailMismatchCount, 0);
}

TEST(SurfaceMeshOptimizerPhase22,
     LineSearchOrientationUsesEachQuadsAuthoritativeSourceNormal) {
  Eigen::MatrixXd vertices(8, 3);
  vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      1.0, 1.0, 0.0,
      0.0, 1.0, 0.0,
      2.0, 0.0, 0.0,
      2.0, 1.0, 0.0,
      2.0, 1.0, 1.0,
      2.0, 0.0, 1.0;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 2,
      0, 2, 3,
      4, 5, 6,
      4, 6, 7;
  Eigen::MatrixXi quads(2, 4);
  quads << 0, 1, 2, 3,
      4, 5, 6, 7;

  SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = vertices;
  constraints.sourceFaces = sourceFaces;
  constraints.sourcePositions = vertices;
  constraints.sourceNormals.resize(4, 3);
  constraints.sourceNormals << 0.0, 0.0, 1.0,
      0.0, 0.0, 1.0,
      1.0, 0.0, 0.0,
      1.0, 0.0, 0.0;
  constraints.sourceFaceComponent = {0, 0, 1, 1};
  constraints.sourceFaceSheet = {0, 0, 0, 0};

  directional::geometry::SurfaceProjectionBvh bvh(vertices, sourceFaces);
  directional::geometry::SurfaceProjectionOptions projectionOptions;
  projectionOptions.faceComponents = &constraints.sourceFaceComponent;
  projectionOptions.faceSheets = &constraints.sourceFaceSheet;
  std::vector<SurfacePoint> provenance;
  provenance.reserve(8);
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    directional::geometry::SurfaceProjectionOptions constrained =
        projectionOptions;
    std::vector<unsigned char> allowedFaces(4, 0);
    if (vertex < 4) {
      allowedFaces[0] = 1;
      allowedFaces[1] = 1;
    } else {
      allowedFaces[2] = 1;
      allowedFaces[3] = 1;
    }
    constrained.allowedFaces = &allowedFaces;
    provenance.push_back(
        bvh.project(vertices.row(vertex).transpose(), constrained));
  }
  constraints.vertexProvenance = provenance;

  EXPECT_TRUE(directional::geometry::local_orientation_valid(
      vertices, quads, &constraints, &provenance));

  Eigen::MatrixXi flipped = quads;
  flipped.row(1) << 4, 7, 6, 5;
  EXPECT_FALSE(directional::geometry::local_orientation_valid(
      vertices, flipped, &constraints, &provenance));
}
