#include "BenchmarkCases.h"
#include "TestFixturePaths.h"
#include "BenchmarkQuality.h"

#include <cmath>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

namespace {

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
  directional::pipeline::RemeshResult result;
  result.success = true;
  result.vertices = square_source_mesh().vertices;
  result.faces.resize(1, 4);
  result.faces << 0, 1, 2, 3;
  result.degrees = Eigen::VectorXi::Constant(1, 4);
  return result;
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
  const auto &validation = result.surfaceCellContext.validationResult;
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
        "peakWorkingSetBytes", "outputStructuralHash", "outputMeshPath",
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
  geometry.vertices(0, 0) += 0.125;
  EXPECT_NE(baselineHash,
            directional::bench::benchmark_output_structural_hash(geometry));

  directional::pipeline::RemeshResult degree = baseline;
  degree.degrees(0) = 3;
  EXPECT_NE(baselineHash,
            directional::bench::benchmark_output_structural_hash(degree));

  directional::pipeline::RemeshResult connectivity = baseline;
  connectivity.faces(0, 1) = 3;
  connectivity.faces(0, 3) = 1;
  EXPECT_NE(baselineHash,
            directional::bench::benchmark_output_structural_hash(connectivity));
}

TEST(MilestoneGP27, QualityCountsSelfIntersectingPolygon) {
  BenchmarkCase benchmarkCase;
  benchmarkCase.name = "unit_bow_tie__surface_cells";
  benchmarkCase.lengthRatio = 1.0 / std::sqrt(2.0);
  benchmarkCase.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  directional::pipeline::RemeshResult result = square_quad_result();
  result.faces << 0, 2, 1, 3;

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
  ASSERT_EQ(cases.size(), 18U);

  std::set<std::string> names;
  for (const BenchmarkCase &benchmarkCase : cases) {
    EXPECT_TRUE(names.insert(benchmarkCase.name).second) << benchmarkCase.name;
    EXPECT_EQ(benchmarkCase.surfaceCellFallback,
              directional::pipeline::SurfaceCellFallbackPolicy::Fail);
  }
  for (const std::string &fixture :
       {"plane", "cylinder", "torus", "thin_bent_tube", "close_sheets",
        "sphere_prescribed", "multi_face_seam", "bunny_1k_random",
        "mechanical_feature"}) {
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
    if (!rails.success && rails.failedEdgeIndex >= 0 &&
        rails.failedEdgeIndex < static_cast<int>(featureMap.edges.size())) {
      const auto &failed =
          featureMap.edges[static_cast<std::size_t>(rails.failedEdgeIndex)];
      detail << " failedVertices=" << failed.vertices.first << ","
             << failed.vertices.second
             << " class=" << static_cast<int>(failed.edgeClass)
             << " curve=" << failed.curve;
      for (const auto &curve : featureMap.curves) {
        const auto found = std::find(curve.edges.begin(), curve.edges.end(),
                                     rails.failedEdgeIndex);
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
    EXPECT_TRUE(rails.success)
        << benchmarkCase.name
        << " status=" << static_cast<int>(rails.validationStatus)
        << " edge=" << rails.failedEdgeIndex << " rail=" << rails.failedRailId
        << " interval=" << rails.failedIntervalIndex << detail.str();
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
    const BenchmarkMesh mesh =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const BenchmarkField field = directional::bench::load_benchmark_field(
        benchmarkCase, mesh.faces.rows());
    directional::pipeline::RemeshOptions options =
        directional::bench::make_remesh_options(benchmarkCase);
    options.surfaceCells.fallbackPolicy =
        directional::pipeline::SurfaceCellFallbackPolicy::Fail;
    options.surfaceCells.enforceOptimizerTimeGate = false;
    const directional::pipeline::RemeshResult result =
        field.available
            ? directional::pipeline::remesh_from_raw_cross_field(
                  mesh.vertices, mesh.faces, field.raw, options)
            : directional::pipeline::remesh_from_mesh(
                  mesh.vertices, mesh.faces, options);
    EXPECT_TRUE(result.success)
        << benchmarkCase.name << " " << validation_detail(result);
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
    const BenchmarkMesh mesh =
        directional::bench::load_benchmark_mesh(*found);
    const BenchmarkField field =
        directional::bench::load_benchmark_field(*found, mesh.faces.rows());
    directional::pipeline::RemeshOptions options =
        directional::bench::make_remesh_options(*found);
    options.surfaceCells.fallbackPolicy =
        directional::pipeline::SurfaceCellFallbackPolicy::Fail;
    options.surfaceCells.enforceOptimizerTimeGate = false;
    result = field.available
        ? directional::pipeline::remesh_from_raw_cross_field(
              mesh.vertices, mesh.faces, field.raw, options)
        : directional::pipeline::remesh_from_mesh(
              mesh.vertices, mesh.faces, options);
  }

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
  if (result.success) {
    ASSERT_GT(result.vertices.rows(), 0) << caseName;
    ASSERT_GT(result.faces.rows(), 0) << caseName;
    ASSERT_EQ(result.degrees.size(), result.faces.rows()) << caseName;
  }
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
