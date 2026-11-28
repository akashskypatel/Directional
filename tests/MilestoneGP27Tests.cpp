#include "BenchmarkCases.h"
#include "TestFixturePaths.h"
#include "BenchmarkQuality.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <stdexcept>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace {

directional::geometry::SourceProjectionChart test_projection_chart(
    const int fieldChart, const int sourceFaceToken) {
  const auto chart = directional::authority::FieldChartId::from_index(
      fieldChart, static_cast<std::size_t>(std::max(fieldChart + 1, 1)));
  const int firstIndex = 3 * sourceFaceToken;
  const std::size_t vertexExtent = static_cast<std::size_t>(
      std::max(firstIndex + 3, 1));
  const auto first = directional::authority::SourceVertexId::from_index(
      firstIndex, vertexExtent);
  const auto second = directional::authority::SourceVertexId::from_index(
      firstIndex + 1, vertexExtent);
  const auto third = directional::authority::SourceVertexId::from_index(
      firstIndex + 2, vertexExtent);
  if (!chart || !first || !second || !third) {
    throw std::runtime_error("Invalid test projection chart.");
  }
  const auto face = directional::authority::SourceFaceTopologyKey::make(
      {first.value(), second.value(), third.value()});
  if (!face) {
    throw std::runtime_error("Invalid test projection chart topology.");
  }
  return {chart.value(), face.value()};
}


directional::authority::TopologyRegionId test_topology_region_id(
    const int value) {
  const auto id = directional::authority::TopologyRegionId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) throw std::runtime_error("Invalid test topology-region ID.");
  return id.value();
}

directional::authority::IsolationSheetId test_isolation_sheet_id(
    const int value) {
  const auto id = directional::authority::IsolationSheetId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) throw std::runtime_error("Invalid test isolation-sheet ID.");
  return id.value();
}

directional::authority::SourceSupport test_source_vertex_support(
    const int value) {
  const auto id = directional::authority::SourceVertexId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) throw std::runtime_error("Invalid test source-vertex support.");
  return directional::authority::SourceVertexSupport{id.value()};
}

using directional::bench::BenchmarkCase;
using directional::bench::BenchmarkField;
using directional::bench::BenchmarkMesh;
using directional::bench::BenchmarkQuality;

BenchmarkMesh square_source_mesh() {
  BenchmarkMesh mesh;
  mesh.vertices.resize(4, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3;
  return mesh;
}

BenchmarkField square_field() {
  BenchmarkField field;
  field.available = true;
  field.degree = 4;
  field.raw.resize(2, 6);
  field.raw << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  return field;
}

directional::pipeline::RemeshResult square_quad_result() {
  directional::pipeline::RemeshProduct result;
  result.vertices = square_source_mesh().vertices;
  result.faces.resize(1, 4);
  result.faces << 0, 1, 2, 3;
  result.degrees = Eigen::VectorXi::Constant(1, 4);
  const std::array<Eigen::Vector3d, 4> barycentric{
      Eigen::Vector3d(1.0, 0.0, 0.0),
      Eigen::Vector3d(0.0, 1.0, 0.0),
      Eigen::Vector3d(0.0, 0.0, 1.0),
      Eigen::Vector3d(0.0, 0.0, 1.0)};
  const std::array<int, 4> sourceFaces{0, 0, 0, 1};
  for (int vertex = 0; vertex < 4; ++vertex) {
    directional::geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = vertex;
    lineage.sourcePoint.face = sourceFaces[static_cast<std::size_t>(vertex)];
    lineage.sourcePoint.component = 0;
    lineage.sourcePoint.sheet = 0;
    lineage.sourcePoint.barycentric =
        barycentric[static_cast<std::size_t>(vertex)];
    lineage.sourcePoint.position = result.vertices.row(vertex).transpose();
    lineage.sourcePoint.squaredDistance = 0.0;
    lineage.sourceComponent = 0;
    lineage.sourceSheet = 0;
    lineage.sourceTopologyRegions = {test_topology_region_id(0)};
    lineage.sourceIsolationSheets = {test_isolation_sheet_id(0)};
    lineage.sourceCharts = {test_projection_chart(
        0, sourceFaces[static_cast<std::size_t>(vertex)])};
    lineage.sourceSupport = test_source_vertex_support(vertex);
    result.outputVertexLineage.push_back(std::move(lineage));
  }
  directional::geometry::PureQuadFaceLineage faceLineage;
  faceLineage.outputQuad = 0;
  faceLineage.sourcePatch = 0;
  faceLineage.operationLocalQuad = 0;
  result.outputQuadLineage.push_back(faceLineage);
  return directional::pipeline::RemeshResult::produced(
      std::move(result), directional::pipeline::RemeshProductKind::Meshed,
      true);
}

directional::pipeline::RemeshResult two_component_quad_result() {
  directional::pipeline::RemeshProduct result;
  result.vertices.resize(8, 3);
  result.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0, 3.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0,
      3.0, 1.0, 0.0;
  result.faces.resize(2, 4);
  result.faces << 0, 1, 2, 3, 4, 5, 6, 7;
  result.degrees = Eigen::VectorXi::Constant(2, 4);
  for (int vertex = 0; vertex < 8; ++vertex) {
    const int component = vertex / 4;
    directional::geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = vertex;
    lineage.sourcePoint.face = component;
    lineage.sourcePoint.component = component;
    lineage.sourcePoint.sheet = component;
    lineage.sourcePoint.barycentric = Eigen::Vector3d(1.0, 0.0, 0.0);
    lineage.sourcePoint.position = result.vertices.row(vertex).transpose();
    lineage.sourcePoint.squaredDistance = 0.0;
    lineage.sourceComponent = component;
    lineage.sourceSheet = component;
    lineage.sourceTopologyRegions = {test_topology_region_id(component)};
    lineage.sourceIsolationSheets = {test_isolation_sheet_id(component)};
    lineage.sourceCharts = {test_projection_chart(component, component)};
    lineage.sourceSupport = test_source_vertex_support(vertex % 4);
    result.outputVertexLineage.push_back(std::move(lineage));
  }
  for (int face = 0; face < 2; ++face) {
    directional::geometry::PureQuadFaceLineage lineage;
    lineage.outputQuad = face;
    lineage.sourcePatch = face;
    lineage.operationLocalQuad = face;
    result.outputQuadLineage.push_back(lineage);
  }
  return directional::pipeline::RemeshResult::produced(
      std::move(result), directional::pipeline::RemeshProductKind::Meshed,
      true);
}

directional::pipeline::RemeshResult permute_output_rows(
    const directional::pipeline::RemeshResult &source) {
  directional::pipeline::RemeshProduct permuted = source.product();
  const std::array<int, 8> newToOld{7, 6, 5, 4, 3, 2, 1, 0};
  std::array<int, 8> oldToNew{};
  for (int vertex = 0; vertex < 8; ++vertex) {
    oldToNew[static_cast<std::size_t>(newToOld[static_cast<std::size_t>(vertex)])] =
        vertex;
    permuted.vertices.row(vertex) =
        source.product().vertices.row(newToOld[static_cast<std::size_t>(vertex)]);
  }
  for (int face = 0; face < 2; ++face) {
    const int sourceFace = 1 - face;
    for (int corner = 0; corner < 4; ++corner) {
      permuted.faces(face, corner) = oldToNew[static_cast<std::size_t>(
          source.product().faces(sourceFace, corner))];
    }
  }
  permuted.outputVertexLineage.clear();
  for (int vertex = 0; vertex < 8; ++vertex) {
    auto lineage = source.product().outputVertexLineage[static_cast<std::size_t>(
        newToOld[static_cast<std::size_t>(vertex)])];
    lineage.outputVertex = vertex;
    permuted.outputVertexLineage.push_back(std::move(lineage));
  }
  permuted.outputQuadLineage.clear();
  for (int face = 0; face < 2; ++face) {
    auto lineage = source.product().outputQuadLineage[static_cast<std::size_t>(1 - face)];
    lineage.outputQuad = face;
    permuted.outputQuadLineage.push_back(std::move(lineage));
  }
  const auto *sourcePublication = source.produced_product();
  if (sourcePublication == nullptr) {
    throw std::invalid_argument("Permutation requires a produced remesh product.");
  }
  return directional::pipeline::RemeshResult::produced(
      std::move(permuted), sourcePublication->kind,
      sourcePublication->crossFieldAccepted, source.surfaceCellContext,
      source.diagnostics);
}

std::filesystem::path artifact_directory(const std::string &testName) {
  std::error_code error;
  std::filesystem::path root = std::filesystem::temp_directory_path(error);
  if (error) {
    error.clear();
    root = std::filesystem::current_path() / "build" / "test-artifacts";
    std::filesystem::create_directories(root, error);
  }
  if (error) {
    throw std::filesystem::filesystem_error(
        "unable to create P27 artifact root", root, error);
  }
  return root / ("directional-p27-" + testName);
}

void remove_quality_artifacts(const BenchmarkQuality &quality) {
  std::error_code error;
  if (!quality.outputMeshPath.empty()) {
    std::filesystem::remove(quality.outputMeshPath, error);
  }
  error.clear();
  if (!quality.reviewImagePath.empty()) {
    std::filesystem::remove(quality.reviewImagePath, error);
  }
}

std::string
validation_detail(const directional::pipeline::RemeshResult &result) {
  const auto &validation = result.surfaceCellContext.productSnapshots.validationResult;
  std::ostringstream detail;
  detail << "failure=" << result.diagnostics.terminalFailureCode << "/"
         << result.diagnostics.terminalFailureStage
         << " component=" << result.diagnostics.failedComponentIndex
         << " validationFailures="
         << result.diagnostics.surfaceCellValidationFailures
         << " strict=" << validation.accepted
         << " topology=" << validation.connectedComponentMismatchCount << "/"
         << validation.eulerCharacteristicMismatchCount << "/"
         << validation.boundaryCycleMismatchCount
         << " rails=" << validation.featureRailMismatchCount
         << " provenance=" << validation.provenanceFailureCount
         << " sheets=" << validation.localSheetMismatchCount
         << " geometry=" << validation.degenerate << "/" << validation.inverted
         << "/" << validation.selfIntersecting
         << " manifold=" << validation.tJunctions << "/"
         << validation.nonManifold << "/" << validation.nonConvex
         << " valence=" << validation.boundaryValenceMismatchCount << "/"
         << validation.requiredSingularityValenceMismatchCount
         << std::setprecision(6) << " surface=" << validation.quadToSourceP95
         << "," << validation.quadToSourceMax << "/"
         << validation.sourceToOutputP95 << "," << validation.sourceToOutputMax
         << " normal=" << validation.normalP95Degrees
         << " size=" << validation.sizeP5 << "," << validation.sizeP95
         << " field=" << validation.fieldMedianDegrees << ","
         << validation.fieldP95Degrees
         << " angles=" << validation.angleP5Degrees << ","
         << validation.angleP95Degrees
         << " warp=" << validation.warpageP95Degrees << ","
         << validation.warpageMaxDegrees << " aspect=" << validation.aspectP95
         << "," << validation.aspectP99
         << " jacobian=" << validation.scaledJacobianMin << ","
         << validation.scaledJacobianP5;
  return detail.str();
}

TEST(MilestoneGP27, QualitySchemaContainsEveryRequiredProductionMetric) {
  BenchmarkCase benchmarkCase;
  benchmarkCase.name = "unit_plane__surface_cells";
  benchmarkCase.lengthRatio = 1.0 / std::sqrt(2.0);
  benchmarkCase.backend = directional::pipeline::RemeshBackend::SurfaceCells;

  const BenchmarkQuality quality =
      directional::bench::evaluate_benchmark_quality(
          benchmarkCase, square_source_mesh(), square_field(),
          square_quad_result(), 123456U, artifact_directory("quality-schema"));

  ASSERT_TRUE(quality.available) << quality.error;
  EXPECT_DOUBLE_EQ(quality.pureQuadRate, 1.0);
  EXPECT_EQ(quality.nonManifoldEdgeCount, 0);
  EXPECT_EQ(quality.tJunctionCount, 0);
  EXPECT_EQ(quality.duplicateFaceCount, 0);
  EXPECT_EQ(quality.selfIntersectionCount, 0);
  EXPECT_TRUE(quality.topologyPreserved);
  EXPECT_TRUE(quality.boundaryPreserved);
  EXPECT_DOUBLE_EQ(quality.featureRecall, 1.0);
  EXPECT_NEAR(quality.fieldAlignmentP95Degrees, 0.0, 1.0e-12);
  EXPECT_NEAR(quality.relativeSizeErrorP95, 0.0, 1.0e-12);
  EXPECT_NEAR(quality.surfaceApproximationP95, 0.0, 1.0e-12);
  EXPECT_EQ(quality.irregularVertexCount, 0);
  EXPECT_EQ(quality.peakWorkingSetBytes, 123456U);
  EXPECT_FALSE(quality.outputStructuralHash.empty());
  EXPECT_FALSE(quality.outputSemanticHash.empty());
  EXPECT_NE(quality.outputSemanticHashValue, 0U);
  EXPECT_TRUE(std::filesystem::is_regular_file(quality.outputMeshPath));
  EXPECT_TRUE(std::filesystem::is_regular_file(quality.reviewImagePath));

  std::ostringstream json;
  directional::bench::write_benchmark_quality_json(json, quality);
  for (const std::string &property :
       {"available", "pureQuadRate", "nonManifoldEdgeCount", "tJunctionCount",
        "duplicateFaceCount", "selfIntersectionCount", "topologyPreserved",
        "boundaryPreserved", "featureRecall", "featureAlignmentP95Degrees",
        "fieldAlignmentP95Degrees", "relativeSizeErrorP95",
        "surfaceApproximationP95", "irregularVertexCount",
        "peakWorkingSetBytes", "outputStructuralHash", "outputSemanticHash",
        "outputMeshPath",
        "reviewImagePath", "valenceHistogram"}) {
    EXPECT_NE(json.str().find("\"" + property + "\""), std::string::npos)
        << property;
  }
  remove_quality_artifacts(quality);
}

TEST(MilestoneGP27, FailedRunReviewImagePreservesInspectableSourceEvidence) {
  BenchmarkCase benchmarkCase;
  benchmarkCase.name = "unit_plane__surface_cells";
  const std::filesystem::path path =
      directional::bench::write_benchmark_failure_review_image(
          benchmarkCase, square_source_mesh(),
          artifact_directory("failure-review"));

  ASSERT_TRUE(std::filesystem::is_regular_file(path));
  EXPECT_GT(std::filesystem::file_size(path), 54U);

  std::error_code error;
  std::filesystem::remove(path, error);
}

TEST(MilestoneGP27, StructuralHashCoversGeometryDegreesAndConnectivity) {
  directional::pipeline::RemeshResult baseline = square_quad_result();
  const std::uint64_t baselineHash =
      directional::bench::benchmark_output_structural_hash(baseline);
  EXPECT_EQ(baselineHash,
            directional::bench::benchmark_output_structural_hash(baseline));

  directional::pipeline::RemeshResult geometry = baseline;
  geometry.product().vertices(0, 0) += 0.125;
  EXPECT_NE(baselineHash,
            directional::bench::benchmark_output_structural_hash(geometry));

  directional::pipeline::RemeshResult degree = baseline;
  degree.product().degrees(0) = 3;
  EXPECT_NE(baselineHash,
            directional::bench::benchmark_output_structural_hash(degree));

  directional::pipeline::RemeshResult connectivity = baseline;
  connectivity.product().faces(0, 1) = 3;
  connectivity.product().faces(0, 3) = 1;
  EXPECT_NE(baselineHash,
            directional::bench::benchmark_output_structural_hash(connectivity));
}

TEST(MilestoneGP27,
     SemanticHashIsInvariantToComponentVertexAndFaceRowPermutation) {
  const auto baseline = two_component_quad_result();
  const auto permuted = permute_output_rows(baseline);
  const std::uint64_t baselineSemantic =
      directional::bench::benchmark_output_semantic_hash(baseline);
  ASSERT_NE(baselineSemantic, 0U);
  EXPECT_EQ(baselineSemantic,
            directional::bench::benchmark_output_semantic_hash(permuted));
  EXPECT_NE(directional::bench::benchmark_output_structural_hash(baseline),
            directional::bench::benchmark_output_structural_hash(permuted));
}

TEST(MilestoneGP27, SemanticHashDetectsConnectivityAndLineageMutation) {
  const auto baseline = two_component_quad_result();
  const std::uint64_t baselineSemantic =
      directional::bench::benchmark_output_semantic_hash(baseline);
  ASSERT_NE(baselineSemantic, 0U);

  auto connectivityMutation = baseline;
  std::swap(connectivityMutation.faces(0, 3),
            connectivityMutation.faces(1, 3));
  EXPECT_NE(baselineSemantic,
            directional::bench::benchmark_output_semantic_hash(
                connectivityMutation));

  auto lineageMutation = baseline;
  lineageMutation.outputVertexLineage.front().sourceSupport =
      test_source_vertex_support(1);
  EXPECT_NE(baselineSemantic,
            directional::bench::benchmark_output_semantic_hash(
                lineageMutation));
}

TEST(MilestoneGP27, QualityCountsSelfIntersectingPolygon) {
  BenchmarkCase benchmarkCase;
  benchmarkCase.name = "unit_bow_tie__surface_cells";
  benchmarkCase.lengthRatio = 1.0 / std::sqrt(2.0);
  benchmarkCase.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  directional::pipeline::RemeshResult result = square_quad_result();
  result.product().faces << 0, 2, 1, 3;

  const BenchmarkQuality quality =
      directional::bench::evaluate_benchmark_quality(
          benchmarkCase, square_source_mesh(), square_field(), result, 1U,
          artifact_directory("bow-tie"));
  ASSERT_TRUE(quality.available) << quality.error;
  EXPECT_GT(quality.selfIntersectionCount, 0);
  remove_quality_artifacts(quality);
}

TEST(MilestoneGP27, ProductionManifestIsCanonicalCompleteAndPaired) {
  const std::filesystem::path manifest =
      directional::tests::benchmark_fixture_path(
          "milestone_g_manifest.json");
  const std::vector<BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifest);
  ASSERT_EQ(cases.size(), 20U);

  std::set<std::string> names;
  for (const BenchmarkCase &benchmarkCase : cases) {
    EXPECT_TRUE(names.insert(benchmarkCase.name).second) << benchmarkCase.name;
    EXPECT_EQ(benchmarkCase.surfaceCellFallback,
              directional::pipeline::SurfaceCellFallbackPolicy::Fail);
  }
  for (const std::string &fixture :
       {"plane", "cylinder", "torus", "thin_bent_tube", "close_sheets",
        "sphere_prescribed", "multi_face_seam", "bunny_1k_random",
        "vase", "mechanical_feature"}) {
    EXPECT_EQ(names.count(fixture + "__surface_cells"), 1U) << fixture;
    EXPECT_EQ(names.count(fixture + "__legacy_integer"), 1U) << fixture;
  }
  EXPECT_EQ(names.count("sphere_singularities__surface_cells"), 0U);
}

TEST(MilestoneGP27, ProductionFeatureMapsBuildAuthoritativeRails) {
  const std::filesystem::path manifest =
      directional::tests::benchmark_fixture_path(
          "milestone_g_manifest.json");
  const std::vector<BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifest);
  for (const BenchmarkCase &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
        directional::pipeline::RemeshBackend::SurfaceCells) {
      continue;
    }
    const BenchmarkMesh mesh =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    directional::TriMesh triMesh;
    triMesh.set_mesh(mesh.vertices, mesh.faces);
    const directional::pipeline::RemeshOptions options =
        directional::bench::make_remesh_options(benchmarkCase);
    const directional::geometry::AdaptiveFeatureMap featureMap =
        directional::geometry::AdaptiveFeatureMapBuilder::build(
            mesh.vertices, mesh.faces,
            options.featureAlign ? options.featureMap
                                 : options.surfaceCells.featureMap);
    const directional::pipeline::SurfaceCellRailBuildResult rails =
        directional::pipeline::build_authoritative_surface_cell_rails(
            triMesh, featureMap);
    std::ostringstream detail;
    const auto *railFailure = rails.rejection();
    if (railFailure != nullptr && railFailure->failedEdgeIndex >= 0 &&
        railFailure->failedEdgeIndex < static_cast<int>(featureMap.edges.size())) {
      const auto &failed = featureMap.edges[
          static_cast<std::size_t>(railFailure->failedEdgeIndex)];
      detail << " failedVertices=" << failed.vertices.first << ","
             << failed.vertices.second
             << " class=" << static_cast<int>(failed.edgeClass)
             << " curve=" << failed.curve;
      for (const auto &curve : featureMap.curves) {
        const auto found = std::find(curve.edges.begin(), curve.edges.end(),
                                     railFailure->failedEdgeIndex);
        if (found == curve.edges.end()) {
          continue;
        }
        const std::size_t position =
            static_cast<std::size_t>(found - curve.edges.begin());
        detail << " curveId=" << curve.id << " closed=" << curve.closed
               << " edgeCount=" << curve.edges.size()
               << " vertexCount=" << curve.vertices.size()
               << " position=" << position;
        const std::size_t begin = position > 2U ? position - 2U : 0U;
        const std::size_t end = std::min(curve.edges.size(), position + 3U);
        for (std::size_t index = begin; index < end; ++index) {
          detail << " [" << index << ":e" << curve.edges[index] << " "
                 << curve.vertices[index] << "->";
          if (index + 1U < curve.vertices.size()) {
            detail << curve.vertices[index + 1U];
          } else if (curve.closed && !curve.vertices.empty()) {
            detail << curve.vertices.front();
          } else {
            detail << "?";
          }
          detail << "]";
        }
      }
    }
    EXPECT_TRUE(rails.is_produced())
        << benchmarkCase.name
        << " status="
        << static_cast<int>(railFailure == nullptr
                                ? directional::geometry::surface_cell_tracing_detail::RailBuildStatus::Valid
                                : railFailure->validationStatus)
        << " edge=" << (railFailure == nullptr ? -1 : railFailure->failedEdgeIndex)
        << " rail=" << (railFailure == nullptr ? -1 : railFailure->failedRailId)
        << " interval="
        << (railFailure == nullptr ? -1 : railFailure->failedIntervalIndex)
        << detail.str();
  }
}

TEST(MilestoneGP27, ProductionSurfaceCellMatrixMatchesSupportedDisposition) {
  const std::filesystem::path manifest =
      directional::tests::benchmark_fixture_path(
          "milestone_g_manifest.json");
  const std::vector<BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifest);
  for (const BenchmarkCase &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
        directional::pipeline::RemeshBackend::SurfaceCells) {
      continue;
    }
    SCOPED_TRACE(::testing::Message()
                 << "P27 surface-cell matrix case=" << benchmarkCase.name);
    std::cerr << "[P5_P27_CASE_BEGIN] " << benchmarkCase.name << std::endl;
    directional::pipeline::RemeshResult result;
    {
      const BenchmarkMesh mesh =
          directional::bench::load_benchmark_mesh(benchmarkCase);
      const BenchmarkField field = directional::bench::load_benchmark_field(
          benchmarkCase, mesh.faces.rows());
      directional::pipeline::RemeshOptions options =
          directional::bench::make_remesh_options(benchmarkCase);
      options.surfaceCells.fallbackPolicy =
          directional::pipeline::SurfaceCellFallbackPolicy::Fail;
      options.surfaceCells.enforceOptimizerTimeGate = false;
      std::cerr << "[P5_P27_BEFORE_PIPELINE] " << benchmarkCase.name
                << std::endl;
      result = field.available
          ? directional::pipeline::remesh_from_raw_cross_field(
                mesh.vertices, mesh.faces, field.raw, options)
          : directional::pipeline::remesh_from_mesh(
                mesh.vertices, mesh.faces, options);
      std::cerr << "[P5_P27_AFTER_PIPELINE] " << benchmarkCase.name
                << " success=" << result.is_produced() << std::endl;
    }
    std::cerr << "[P5_P27_AFTER_INPUT_DESTRUCTION] " << benchmarkCase.name
              << std::endl;
    EXPECT_TRUE(result.is_produced())
        << benchmarkCase.name << " " << validation_detail(result);
    std::cerr << "[P5_P27_AFTER_DIAGNOSTIC_READS] " << benchmarkCase.name
              << std::endl;
    std::cerr << "[P5_P27_BEFORE_RESULT_DESTRUCTION] " << benchmarkCase.name
              << std::endl;
    std::cerr << "[P5_P27_CASE_END] " << benchmarkCase.name << std::endl;
  }
}

class MilestoneGP27SurfaceCellCase
    : public ::testing::TestWithParam<const char *> {};

TEST_P(MilestoneGP27SurfaceCellCase,
       RunsIndependentlyAndOwnsReturnedDiagnostics) {
  const std::string caseName = GetParam();
  const std::filesystem::path manifest =
      directional::tests::benchmark_fixture_path(
          "milestone_g_manifest.json");
  const std::vector<BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifest);
  const auto found = std::find_if(
      cases.begin(), cases.end(), [&](const BenchmarkCase &candidate) {
        return candidate.name == caseName;
      });
  ASSERT_NE(found, cases.end()) << caseName;
  ASSERT_EQ(found->backend,
            directional::pipeline::RemeshBackend::SurfaceCells);

  directional::pipeline::RemeshResult result;
  {
    std::cerr << "[P5_P27_PARAM_BEFORE_INPUT_LOAD] " << caseName
              << std::endl;
    const BenchmarkMesh mesh =
        directional::bench::load_benchmark_mesh(*found);
    const BenchmarkField field =
        directional::bench::load_benchmark_field(*found, mesh.faces.rows());
    directional::pipeline::RemeshOptions options =
        directional::bench::make_remesh_options(*found);
    options.surfaceCells.fallbackPolicy =
        directional::pipeline::SurfaceCellFallbackPolicy::Fail;
    options.surfaceCells.enforceOptimizerTimeGate = false;
    std::cerr << "[P5_P27_PARAM_BEFORE_PIPELINE] " << caseName
              << std::endl;
    result = field.available
        ? directional::pipeline::remesh_from_raw_cross_field(
              mesh.vertices, mesh.faces, field.raw, options)
        : directional::pipeline::remesh_from_mesh(
              mesh.vertices, mesh.faces, options);
    std::cerr << "[P5_P27_PARAM_AFTER_PIPELINE] " << caseName
              << " success=" << result.is_produced() << std::endl;
  }
  std::cerr << "[P5_P27_PARAM_AFTER_INPUT_DESTRUCTION] " << caseName
            << std::endl;

  // Every public payload must remain owned after all source mesh, field,
  // options, and temporary pipeline contexts have been destroyed.
  const std::string ownedFailureCode =
      result.diagnostics.terminalFailureCode;
  const std::string ownedFailureStage =
      result.diagnostics.terminalFailureStage;
  EXPECT_EQ(ownedFailureCode, result.diagnostics.terminalFailureCode);
  EXPECT_EQ(ownedFailureStage, result.diagnostics.terminalFailureStage);
  EXPECT_GE(result.surfaceCellContext.completionAttemptedPatches, 0);
  EXPECT_GE(result.surfaceCellContext.completionFailedPatches, 0);
  EXPECT_GE(result.surfaceCellContext.completionOwnershipRepairAttempts, 0);
  std::cerr << "[P5_P27_PARAM_AFTER_DIAGNOSTIC_READS] " << caseName
            << std::endl;
  if (result.is_produced()) {
    ASSERT_GT(result.product().vertices.rows(), 0) << caseName;
    ASSERT_GT(result.product().faces.rows(), 0) << caseName;
    ASSERT_EQ(result.product().degrees.size(), result.product().faces.rows()) << caseName;
  }
  std::cerr << "[P5_P27_PARAM_BEFORE_RESULT_DESTRUCTION] " << caseName
            << std::endl;
}

INSTANTIATE_TEST_SUITE_P(
    ProductionManifestCases, MilestoneGP27SurfaceCellCase,
    ::testing::Values(
        "plane__surface_cells", "cylinder__surface_cells",
        "torus__surface_cells", "thin_bent_tube__surface_cells",
        "close_sheets__surface_cells", "sphere_prescribed__surface_cells",
        "multi_face_seam__surface_cells",
        "bunny_1k_random__surface_cells",
        "mechanical_feature__surface_cells"));

TEST(MilestoneGP27, WorkingSetSamplerReturnsAnObservedPeak) {
  directional::bench::PeakWorkingSetSampler sampler;
  const std::uint64_t peak = sampler.finish();
#ifdef _WIN32
  EXPECT_GT(peak, 0U);
#else
  EXPECT_GE(peak, 0U);
#endif
}

} // namespace
