#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"
#include "TestFixturePaths.h"

namespace {

struct DesignAcceptanceCase {
  const char *testName;
  const char *benchmarkName;
};

const directional::bench::BenchmarkCase &find_benchmark_case(
    const std::vector<directional::bench::BenchmarkCase> &cases,
    const std::string &name) {
  const auto found = std::find_if(
      cases.begin(), cases.end(), [&](const auto &candidate) {
        return candidate.name == name;
      });
  if (found == cases.end()) {
    throw std::runtime_error("missing benchmark case: " + name);
  }
  return *found;
}

std::string failure_context(const directional::pipeline::RemeshResult &result) {
  return "terminal=" + result.diagnostics.terminalFailureCode + ":" +
         result.diagnostics.terminalFailureStage +
         " traceSegments=" +
         std::to_string(result.diagnostics.surfaceCellTraceSegmentCount) +
         " arrangementCells=" +
         std::to_string(result.diagnostics.surfaceCellArrangementCellCount) +
         " completedQuads=" +
         std::to_string(result.diagnostics.surfaceCellCompletedQuadCount);
}

class SurfaceCellDesignAcceptance
    : public ::testing::TestWithParam<DesignAcceptanceCase> {};

TEST_P(SurfaceCellDesignAcceptance,
       ProducesDirectSourceAuthoritativePureQuadOutput) {
  const std::vector<directional::bench::BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(
          directional::tests::benchmark_fixture_path(
              "milestone_g_manifest.json"));
  const directional::bench::BenchmarkCase &benchmarkCase =
      find_benchmark_case(cases, GetParam().benchmarkName);
  const directional::bench::BenchmarkMesh mesh =
      directional::bench::load_benchmark_mesh(benchmarkCase);
  const directional::bench::BenchmarkField field =
      directional::bench::load_benchmark_field(benchmarkCase,
                                                mesh.faces.rows());

  ASSERT_TRUE(field.available);
  ASSERT_EQ(4, field.degree);
  ASSERT_EQ(mesh.faces.rows(), field.raw.rows());
  ASSERT_EQ(12, field.raw.cols());

  directional::pipeline::RemeshOptions options =
      directional::bench::make_remesh_options(benchmarkCase);
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.rejectPairedSourceTriangleBoundaryOutput = true;
  options.surfaceCells.preserveDebugArtifacts = false;
  options.surfaceCells.retainIntermediateGeometry = false;
  options.surfaceCells.useSkeletonHints = false;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);

  ASSERT_TRUE(result.success) << failure_context(result);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_FALSE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);

  ASSERT_GT(result.vertices.rows(), 0);
  ASSERT_GT(result.faces.rows(), 0);
  ASSERT_EQ(4, result.faces.cols());
  ASSERT_EQ(result.faces.rows(), result.degrees.size());
  EXPECT_TRUE((result.degrees.array() == 4).all());
}

INSTANTIATE_TEST_SUITE_P(
    UniformPhaseFront, SurfaceCellDesignAcceptance,
    ::testing::Values(
        DesignAcceptanceCase{"Plane", "plane__surface_cells"},
        DesignAcceptanceCase{"MultiFaceSeam",
                             "multi_face_seam__surface_cells"},
        DesignAcceptanceCase{"CloseSheets", "close_sheets__surface_cells"},
        DesignAcceptanceCase{"Cylinder", "cylinder__surface_cells"}),
    [](const ::testing::TestParamInfo<DesignAcceptanceCase> &info) {
      return info.param.testName;
    });

} // namespace
