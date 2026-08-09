#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/SurfaceOptimizationRailConstraints.h>
#include <directional/validation/SourceAuthoritativeMeshValidator.h>

#include <algorithm>
#include <cstdint>
#include <set>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::SurfaceOptimizationConstraints;
using directional::geometry::SurfaceOptimizationResult;
using directional::geometry::SurfacePoint;
using directional::validation::MeshValidationFailureCode;
using directional::validation::SourceHardRailChartEquivalence;
using directional::validation::SourceAuthoritativeMeshValidatorOptions;
using directional::validation::SourceVertexChartAuthority;

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

std::uint64_t source_edge_key(const int first, const int second) {
  const auto low = static_cast<std::uint32_t>(std::min(first, second));
  const auto high = static_cast<std::uint32_t>(std::max(first, second));
  return (static_cast<std::uint64_t>(low) << 32U) |
         static_cast<std::uint64_t>(high);
}

SurfacePoint source_vertex_point(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &components, const std::vector<int> &sheets,
    const int vertex, const int face) {
  SurfacePoint point;
  point.face = face;
  point.component = components[static_cast<std::size_t>(face)];
  point.sheet = sheets[static_cast<std::size_t>(face)];
  point.position = vertices.row(vertex).transpose();
  point.squaredDistance = 0.0;
  for (int corner = 0; corner < 3; ++corner) {
    if (faces(face, corner) == vertex) {
      point.barycentric(corner) = 1.0;
    }
  }
  return point;
}

directional::geometry::SurfaceCellSourceChart source_chart(
    const int face, const std::vector<int> &components,
    const std::vector<int> &sheets) {
  return {components[static_cast<std::size_t>(face)], face,
          sheets[static_cast<std::size_t>(face)]};
}

SourceHardRailChartEquivalence hard_rail_equivalence(
    const int railId, const int firstFrontEdge, const int secondFrontEdge,
    const std::uint64_t topology) {
  SourceHardRailChartEquivalence equivalence;
  equivalence.railId = railId;
  equivalence.firstFrontEdge = firstFrontEdge;
  equivalence.secondFrontEdge = secondFrontEdge;
  equivalence.sourceRouteTopology = {topology};
  return equivalence;
}

struct HardRailValidationFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi sourceFaces;
  Eigen::MatrixXi quads;
  std::vector<int> components;
  std::vector<int> sheets;
  std::vector<SurfacePoint> provenance;
  std::vector<SourceVertexChartAuthority> authority;
  std::set<std::uint64_t> hardEdges;
};

HardRailValidationFixture make_hard_rail_validation_fixture() {
  HardRailValidationFixture fixture;
  fixture.vertices.resize(6, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
      1.0, 0.0, 0.0,
      2.0, 0.0, 0.0,
      0.0, 1.0, 0.0,
      1.0, 1.0, 0.0,
      2.0, 1.0, 0.0;
  fixture.sourceFaces.resize(4, 3);
  fixture.sourceFaces << 0, 1, 4,
      0, 4, 3,
      1, 2, 5,
      1, 5, 4;
  fixture.quads.resize(2, 4);
  fixture.quads << 0, 1, 4, 3,
      1, 2, 5, 4;
  fixture.components = {0, 0, 0, 0};
  fixture.sheets = {0, 0, 1, 1};
  fixture.provenance = {
      source_vertex_point(fixture.vertices, fixture.sourceFaces,
                          fixture.components, fixture.sheets, 0, 0),
      source_vertex_point(fixture.vertices, fixture.sourceFaces,
                          fixture.components, fixture.sheets, 1, 0),
      source_vertex_point(fixture.vertices, fixture.sourceFaces,
                          fixture.components, fixture.sheets, 2, 2),
      source_vertex_point(fixture.vertices, fixture.sourceFaces,
                          fixture.components, fixture.sheets, 3, 1),
      source_vertex_point(fixture.vertices, fixture.sourceFaces,
                          fixture.components, fixture.sheets, 4, 0),
      source_vertex_point(fixture.vertices, fixture.sourceFaces,
                          fixture.components, fixture.sheets, 5, 2)};
  fixture.authority.resize(fixture.provenance.size());
  for (std::size_t vertex = 0; vertex < fixture.authority.size(); ++vertex) {
    SourceVertexChartAuthority &authority = fixture.authority[vertex];
    authority.retained = true;
    authority.sourceCharts.push_back(source_chart(
        fixture.provenance[vertex].face, fixture.components,
        fixture.sheets));
  }
  const std::uint64_t railTopology = source_edge_key(1, 4);
  const SourceHardRailChartEquivalence equivalence =
      hard_rail_equivalence(7, 10, 11, railTopology);
  for (const int vertex : {1, 4}) {
    SourceVertexChartAuthority &authority =
        fixture.authority[static_cast<std::size_t>(vertex)];
    authority.sourceCharts.push_back(
        source_chart(3, fixture.components, fixture.sheets));
    std::sort(authority.sourceCharts.begin(), authority.sourceCharts.end());
    authority.hardRailEquivalences.push_back(equivalence);
  }
  fixture.hardEdges.insert(railTopology);
  return fixture;
}

SourceAuthoritativeMeshValidatorOptions hard_rail_options(
    const HardRailValidationFixture &fixture) {
  auto options = make_options(
      fixture.vertices, fixture.sourceFaces, fixture.components,
      fixture.sheets, fixture.provenance, {{0, 1, 2, 5, 4, 3}});
  options.vertexChartAuthority = &fixture.authority;
  options.sourceHardFeatureEdges = fixture.hardEdges;
  return options;
}

SurfaceOptimizationConstraints hard_rail_constraints(
    const HardRailValidationFixture &fixture) {
  SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = fixture.vertices;
  constraints.sourceFaces = fixture.sourceFaces;
  constraints.sourcePositions = fixture.vertices;
  constraints.sourceNormals =
      Eigen::MatrixXd::Zero(fixture.sourceFaces.rows(), 3);
  constraints.sourceFieldX =
      Eigen::MatrixXd::Zero(fixture.sourceFaces.rows(), 3);
  constraints.sourceFieldY =
      Eigen::MatrixXd::Zero(fixture.sourceFaces.rows(), 3);
  for (int face = 0; face < fixture.sourceFaces.rows(); ++face) {
    constraints.sourceNormals.row(face) << 0.0, 0.0, 1.0;
    constraints.sourceFieldX.row(face) << 1.0, 0.0, 0.0;
    constraints.sourceFieldY.row(face) << 0.0, 1.0, 0.0;
  }
  constraints.sourceFaceComponent = fixture.components;
  constraints.sourceFaceSheet = fixture.sheets;
  constraints.sourceHardFeatureEdges = fixture.hardEdges;
  constraints.vertexProvenance = fixture.provenance;
  constraints.vertexChartAuthority = fixture.authority;
  constraints.outputQuadSourceFaces.assign(
      static_cast<std::size_t>(fixture.quads.rows()), -1);
  constraints.localTargetSize =
      Eigen::VectorXd::Ones(fixture.vertices.rows());
  constraints.authoritativeBoundaryLoop = {0, 1, 2, 5, 4, 3};
  constraints.authoritativeBoundaryLoops = {{0, 1, 2, 5, 4, 3}};
  for (std::size_t index = 0;
       index < constraints.authoritativeBoundaryLoop.size(); ++index) {
    const int first = constraints.authoritativeBoundaryLoop[index];
    const int second = constraints.authoritativeBoundaryLoop[
        (index + 1U) % constraints.authoritativeBoundaryLoop.size()];
    constraints.authoritativeBoundaryEdges.insert(
        {std::min(first, second), std::max(first, second)});
  }
  constraints.requireSourceAuthoritativeValidation = true;
  return constraints;
}

directional::validation::source_authoritative_detail::SourceChartCompatibility
resolve_quad_chart(const HardRailValidationFixture &fixture, const int face) {
  const directional::validation::source_authoritative_detail::
      SourcePointLabelSupport support(
          &fixture.sourceFaces, &fixture.components, &fixture.sheets,
          &fixture.hardEdges);
  std::vector<const SurfacePoint *> points;
  std::vector<const SourceVertexChartAuthority *> authority;
  for (int corner = 0; corner < 4; ++corner) {
    const int vertex = fixture.quads(face, corner);
    points.push_back(&fixture.provenance[static_cast<std::size_t>(vertex)]);
    authority.push_back(&fixture.authority[static_cast<std::size_t>(vertex)]);
  }
  return support.resolve_compatible_chart(points, authority);
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

TEST(SurfaceMeshOptimizerPhase22,
     ReciprocalHardRailAuthorityResolvesOneExactChartSidePerQuad) {
  const HardRailValidationFixture fixture =
      make_hard_rail_validation_fixture();
  const auto validation =
      directional::validation::validate_source_authoritative_surface_mesh(
          fixture.vertices, fixture.quads, hard_rail_options(fixture));
  EXPECT_TRUE(validation.accepted);
  EXPECT_TRUE(validation.localSheetCompatibilityPassed);

  const auto left = resolve_quad_chart(fixture, 0);
  const auto right = resolve_quad_chart(fixture, 1);
  ASSERT_TRUE(left.valid());
  ASSERT_TRUE(right.valid());
  EXPECT_NE(left.semanticSide, right.semanticSide);

  const SurfaceOptimizationConstraints constraints =
      hard_rail_constraints(fixture);
  const auto rightLabel = directional::geometry::surface_optimizer_detail::
      consistent_component_sheet(fixture.quads, 1, fixture.provenance,
                                 &constraints);
  EXPECT_EQ(rightLabel, std::make_pair(0, 1));
  const SurfacePoint rightReference =
      directional::geometry::surface_optimizer_detail::
          quad_reference_surface_point(fixture.vertices, fixture.quads, 1,
                                       constraints, fixture.provenance);
  ASSERT_TRUE(rightReference.valid());
  EXPECT_EQ(rightReference.sheet, 1);
  EXPECT_TRUE(directional::geometry::source_authoritative_hard_invariants_valid(
      fixture.vertices, fixture.quads, constraints, fixture.provenance));
}

TEST(SurfaceMeshOptimizerPhase22,
     MissingOrMisalignedHardRailChartAuthorityFailsClosed) {
  HardRailValidationFixture missing = make_hard_rail_validation_fixture();
  missing.authority[1].hardRailEquivalences.clear();
  const auto missingResult =
      directional::validation::validate_source_authoritative_surface_mesh(
          missing.vertices, missing.quads, hard_rail_options(missing));
  EXPECT_FALSE(missingResult.accepted);
  EXPECT_TRUE(
      has_code(missingResult, MeshValidationFailureCode::LocalSheetMismatch));

  HardRailValidationFixture misaligned = make_hard_rail_validation_fixture();
  misaligned.authority.pop_back();
  const auto misalignedResult =
      directional::validation::validate_source_authoritative_surface_mesh(
          misaligned.vertices, misaligned.quads,
          hard_rail_options(misaligned));
  EXPECT_FALSE(misalignedResult.accepted);
  EXPECT_TRUE(has_code(misalignedResult,
                       MeshValidationFailureCode::LocalSheetMismatch));
}

TEST(SurfaceMeshOptimizerPhase22,
     TamperedHardRailIdentityRouteAndChartAuthorityFailClosed) {
  const auto expect_local_sheet_mismatch = [](const auto &fixture) {
    const auto result =
        directional::validation::validate_source_authoritative_surface_mesh(
            fixture.vertices, fixture.quads, hard_rail_options(fixture));
    EXPECT_FALSE(result.accepted);
    EXPECT_TRUE(
        has_code(result, MeshValidationFailureCode::LocalSheetMismatch));
  };

  HardRailValidationFixture wrongRail = make_hard_rail_validation_fixture();
  wrongRail.authority[1].hardRailEquivalences[0].railId = 8;
  expect_local_sheet_mismatch(wrongRail);

  HardRailValidationFixture wrongRoute = make_hard_rail_validation_fixture();
  wrongRoute.authority[1]
      .hardRailEquivalences[0]
      .sourceRouteTopology = {source_edge_key(0, 1)};
  expect_local_sheet_mismatch(wrongRoute);

  HardRailValidationFixture nonreciprocal =
      make_hard_rail_validation_fixture();
  nonreciprocal.authority[1].hardRailEquivalences[0].secondFrontEdge = 10;
  expect_local_sheet_mismatch(nonreciprocal);

  HardRailValidationFixture unsupported = make_hard_rail_validation_fixture();
  unsupported.authority[1].sourceCharts.push_back(
      source_chart(1, unsupported.components, unsupported.sheets));
  std::sort(unsupported.authority[1].sourceCharts.begin(),
            unsupported.authority[1].sourceCharts.end());
  expect_local_sheet_mismatch(unsupported);
}

TEST(SurfaceMeshOptimizerPhase22,
     AmbiguousHardRailChartSidesAreRejectedInsteadOfOrdered) {
  Eigen::MatrixXd sourceVertices(9, 3);
  sourceVertices << -1.0, -1.0, 0.0,
      1.0, -1.0, 0.0,
      1.0, 1.0, 0.0,
      -1.0, 1.0, 0.0,
      0.0, 0.0, 0.0,
      -2.0, -2.0, 0.0,
      2.0, -2.0, 0.0,
      2.0, 2.0, 0.0,
      -2.0, 2.0, 0.0;
  Eigen::MatrixXi sourceFaces(12, 3);
  sourceFaces << 4, 0, 1,
      4, 1, 2,
      4, 2, 3,
      4, 3, 0,
      5, 6, 1,
      5, 1, 0,
      6, 7, 2,
      6, 2, 1,
      7, 8, 3,
      7, 3, 2,
      8, 5, 0,
      8, 0, 3;
  const std::vector<int> components(12, 0);
  const std::vector<int> sheets = {0, 0, 0, 0, 1, 1,
                                   1, 1, 1, 1, 1, 1};
  Eigen::MatrixXd output = sourceVertices.topRows(4);
  const Eigen::MatrixXi quads = one_quad();
  std::vector<SurfacePoint> provenance = {
      source_vertex_point(sourceVertices, sourceFaces, components, sheets,
                          0, 0),
      source_vertex_point(sourceVertices, sourceFaces, components, sheets,
                          1, 0),
      source_vertex_point(sourceVertices, sourceFaces, components, sheets,
                          2, 1),
      source_vertex_point(sourceVertices, sourceFaces, components, sheets,
                          3, 2)};
  std::vector<SourceVertexChartAuthority> authority(4);
  for (std::size_t vertex = 0; vertex < authority.size(); ++vertex) {
    authority[vertex].retained = true;
    authority[vertex].sourceCharts.push_back(
        source_chart(provenance[vertex].face, components, sheets));
  }
  std::set<std::uint64_t> hardEdges;
  const auto add_relation = [&](const int firstVertex, const int secondVertex,
                                const int targetFace, const int railId,
                                const int firstFrontEdge) {
    const std::uint64_t topology =
        source_edge_key(firstVertex, secondVertex);
    const SourceHardRailChartEquivalence equivalence =
        hard_rail_equivalence(railId, firstFrontEdge, firstFrontEdge + 1,
                              topology);
    hardEdges.insert(topology);
    for (const int vertex : {firstVertex, secondVertex}) {
      authority[static_cast<std::size_t>(vertex)].sourceCharts.push_back(
          source_chart(targetFace, components, sheets));
      authority[static_cast<std::size_t>(vertex)]
          .hardRailEquivalences.push_back(equivalence);
    }
  };
  add_relation(0, 1, 5, 10, 20);
  add_relation(1, 2, 7, 11, 22);
  add_relation(2, 3, 9, 12, 24);
  add_relation(3, 0, 11, 13, 26);
  for (SourceVertexChartAuthority &vertexAuthority : authority) {
    std::sort(vertexAuthority.sourceCharts.begin(),
              vertexAuthority.sourceCharts.end());
    std::sort(vertexAuthority.hardRailEquivalences.begin(),
              vertexAuthority.hardRailEquivalences.end());
  }
  auto options = make_options(sourceVertices, sourceFaces, components, sheets,
                              provenance, {{0, 1, 2, 3}});
  options.vertexChartAuthority = &authority;
  options.sourceHardFeatureEdges = hardEdges;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          output, quads, options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::LocalSheetMismatch));
}

TEST(SurfaceMeshOptimizerPhase22,
     DisconnectedCloseSheetsRejectInjectedChartAuthority) {
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
  const auto provenance =
      provenance_for(mixed, source, sourceFaces, components, sheets);
  std::vector<SourceVertexChartAuthority> authority(provenance.size());
  for (std::size_t vertex = 0; vertex < authority.size(); ++vertex) {
    authority[vertex].retained = true;
    authority[vertex].sourceCharts.push_back(
        source_chart(provenance[vertex].face, components, sheets));
  }
  authority[0].sourceCharts.push_back(source_chart(2, components, sheets));
  std::sort(authority[0].sourceCharts.begin(),
            authority[0].sourceCharts.end());
  auto options = make_options(source, sourceFaces, components, sheets,
                              provenance, {{0, 1, 2, 3}});
  options.vertexChartAuthority = &authority;

  const auto result =
      directional::validation::validate_source_authoritative_surface_mesh(
          mixed, one_quad(), options);
  EXPECT_FALSE(result.accepted);
  EXPECT_TRUE(has_code(result, MeshValidationFailureCode::LocalSheetMismatch));
}

TEST(SurfaceMeshOptimizerPhase22,
     HardRailChartResolutionIsInvariantToSourceFaceRows) {
  const HardRailValidationFixture original =
      make_hard_rail_validation_fixture();
  const auto originalValidation =
      directional::validation::validate_source_authoritative_surface_mesh(
          original.vertices, original.quads, hard_rail_options(original));
  ASSERT_TRUE(originalValidation.accepted);
  const auto originalLeft = resolve_quad_chart(original, 0);
  const auto originalRight = resolve_quad_chart(original, 1);
  ASSERT_TRUE(originalLeft.valid());
  ASSERT_TRUE(originalRight.valid());

  HardRailValidationFixture reversed = original;
  std::vector<int> remap(
      static_cast<std::size_t>(original.sourceFaces.rows()), -1);
  for (int oldFace = 0; oldFace < original.sourceFaces.rows(); ++oldFace) {
    const int newFace = original.sourceFaces.rows() - 1 - oldFace;
    reversed.sourceFaces.row(newFace) = original.sourceFaces.row(oldFace);
    reversed.components[static_cast<std::size_t>(newFace)] =
        original.components[static_cast<std::size_t>(oldFace)];
    reversed.sheets[static_cast<std::size_t>(newFace)] =
        original.sheets[static_cast<std::size_t>(oldFace)];
    remap[static_cast<std::size_t>(oldFace)] = newFace;
  }
  for (SurfacePoint &point : reversed.provenance) {
    point.face = remap[static_cast<std::size_t>(point.face)];
  }
  for (SourceVertexChartAuthority &vertexAuthority : reversed.authority) {
    for (auto &chart : vertexAuthority.sourceCharts) {
      chart.sourceFace = remap[static_cast<std::size_t>(chart.sourceFace)];
    }
    std::sort(vertexAuthority.sourceCharts.begin(),
              vertexAuthority.sourceCharts.end());
  }

  const auto reversedValidation =
      directional::validation::validate_source_authoritative_surface_mesh(
          reversed.vertices, reversed.quads, hard_rail_options(reversed));
  EXPECT_TRUE(reversedValidation.accepted);
  const auto reversedLeft = resolve_quad_chart(reversed, 0);
  const auto reversedRight = resolve_quad_chart(reversed, 1);
  ASSERT_TRUE(reversedLeft.valid());
  ASSERT_TRUE(reversedRight.valid());
  EXPECT_EQ(originalLeft.semanticSide, reversedLeft.semanticSide);
  EXPECT_EQ(originalRight.semanticSide, reversedRight.semanticSide);
}

TEST(SurfaceMeshOptimizerPhase22,
     HardRailChartAuthorityNeverMasksScalarProvenanceFailures) {
  const auto expect_code = [](const auto &fixture,
                              const MeshValidationFailureCode code) {
    const auto result =
        directional::validation::validate_source_authoritative_surface_mesh(
            fixture.vertices, fixture.quads, hard_rail_options(fixture));
    EXPECT_FALSE(result.accepted);
    EXPECT_TRUE(has_code(result, code));
  };

  HardRailValidationFixture barycentric =
      make_hard_rail_validation_fixture();
  barycentric.provenance[2].barycentric << 2.0, -1.0, 0.0;
  expect_code(barycentric, MeshValidationFailureCode::InvalidProvenance);

  HardRailValidationFixture position = make_hard_rail_validation_fixture();
  position.provenance[2].position.z() = 0.25;
  expect_code(position, MeshValidationFailureCode::SourcePositionMismatch);

  HardRailValidationFixture component = make_hard_rail_validation_fixture();
  component.provenance[2].component = 1;
  expect_code(component, MeshValidationFailureCode::SourceComponentMismatch);

  HardRailValidationFixture sheet = make_hard_rail_validation_fixture();
  sheet.provenance[2].sheet = 0;
  expect_code(sheet, MeshValidationFailureCode::SourceSheetMismatch);
}
