#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"
#include "support/SurfaceCellProductOracle.h"
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


struct FixtureTopologyStats {
  int boundaryEdges = 0;
  int nonManifoldEdges = 0;
  int connectedFaceComponents = 0;
  int degenerateFaces = 0;
};

FixtureTopologyStats fixture_topology_stats(
    const directional::bench::BenchmarkMesh &mesh) {
  FixtureTopologyStats stats;
  std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
  std::vector<std::vector<int>> adjacency(
      static_cast<std::size_t>(mesh.faces.rows()));
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    const Eigen::RowVector3d a =
        mesh.vertices.row(mesh.faces(face, 0));
    const Eigen::RowVector3d b =
        mesh.vertices.row(mesh.faces(face, 1));
    const Eigen::RowVector3d c =
        mesh.vertices.row(mesh.faces(face, 2));
    if ((b - a).cross(c - a).squaredNorm() <= 1.0e-24) {
      ++stats.degenerateFaces;
    }
    for (int edge = 0; edge < 3; ++edge) {
      const int first = mesh.faces(face, edge);
      const int second = mesh.faces(face, (edge + 1) % 3);
      edgeFaces[std::minmax(first, second)].push_back(face);
    }
  }
  for (const auto &[edge, incident] : edgeFaces) {
    (void)edge;
    if (incident.size() == 1U) {
      ++stats.boundaryEdges;
    } else if (incident.size() > 2U) {
      ++stats.nonManifoldEdges;
    }
    for (std::size_t first = 0; first < incident.size(); ++first) {
      for (std::size_t second = first + 1U; second < incident.size();
           ++second) {
        adjacency[static_cast<std::size_t>(incident[first])].push_back(
            incident[second]);
        adjacency[static_cast<std::size_t>(incident[second])].push_back(
            incident[first]);
      }
    }
  }
  std::vector<bool> visited(static_cast<std::size_t>(mesh.faces.rows()),
                            false);
  for (int seed = 0; seed < mesh.faces.rows(); ++seed) {
    if (visited[static_cast<std::size_t>(seed)]) {
      continue;
    }
    ++stats.connectedFaceComponents;
    std::queue<int> queue;
    queue.push(seed);
    visited[static_cast<std::size_t>(seed)] = true;
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      for (const int adjacent :
           adjacency[static_cast<std::size_t>(face)]) {
        if (!visited[static_cast<std::size_t>(adjacent)]) {
          visited[static_cast<std::size_t>(adjacent)] = true;
          queue.push(adjacent);
        }
      }
    }
  }
  return stats;
}

TEST(SurfaceCellMandatoryProductionFixtures,
     BunnyAndVaseAreNontrivialManifoldProductionInputs) {
  const std::vector<directional::bench::BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(
          directional::tests::benchmark_fixture_path(
              "milestone_g_manifest.json"));

  const auto verify = [&](const char *name, const int expectedVertices,
                          const int expectedFaces,
                          const int expectedBoundaryEdges) {
    const directional::bench::BenchmarkCase &benchmarkCase =
        find_benchmark_case(cases, name);
    const directional::bench::BenchmarkMesh mesh =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    ASSERT_EQ(expectedVertices, mesh.vertices.rows()) << name;
    ASSERT_EQ(expectedFaces, mesh.faces.rows()) << name;
    ASSERT_EQ(3, mesh.faces.cols()) << name;
    const FixtureTopologyStats stats = fixture_topology_stats(mesh);
    EXPECT_EQ(0, stats.degenerateFaces) << name;
    EXPECT_EQ(0, stats.nonManifoldEdges) << name;
    EXPECT_EQ(1, stats.connectedFaceComponents) << name;
    EXPECT_EQ(expectedBoundaryEdges, stats.boundaryEdges) << name;
    const Eigen::RowVector3d extent =
        mesh.vertices.colwise().maxCoeff() -
        mesh.vertices.colwise().minCoeff();
    EXPECT_GT(extent.minCoeff(), 1.0e-3) << name;
  };

  verify("bunny_1k_random__surface_cells", 502, 1000, 0);
  verify("vase__surface_cells", 1274, 2404, 142);
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
  directional::bench::BenchmarkField field =
      directional::bench::load_benchmark_field(benchmarkCase,
                                                mesh.faces.rows());
  if (!field.available) {
    field = directional::bench::generate_benchmark_field(benchmarkCase, mesh);
  }

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

  const auto independentOracle =
      directional::tests::surface_cell_oracle::inspect_surface_cell_product(
          mesh.vertices, mesh.faces, result);
  EXPECT_TRUE(independentOracle.ok()) << independentOracle.describe();

  ASSERT_TRUE(result.is_produced()) << failure_context(result);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_FALSE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);

  ASSERT_GT(result.product().vertices.rows(), 0);
  ASSERT_GT(result.product().faces.rows(), 0);
  ASSERT_EQ(4, result.product().faces.cols());
  ASSERT_EQ(result.product().faces.rows(), result.product().degrees.size());
  EXPECT_TRUE((result.product().degrees.array() == 4).all());
}

INSTANTIATE_TEST_SUITE_P(
    UniformPhaseFront, SurfaceCellDesignAcceptance,
    ::testing::Values(
        DesignAcceptanceCase{"Plane", "plane__surface_cells"},
        DesignAcceptanceCase{"MultiFaceSeam",
                             "multi_face_seam__surface_cells"},
        DesignAcceptanceCase{"CloseSheets", "close_sheets__surface_cells"},
        DesignAcceptanceCase{"Cylinder", "cylinder__surface_cells"},
        DesignAcceptanceCase{"BunnyRandom",
                             "bunny_1k_random__surface_cells"},
        DesignAcceptanceCase{"Vase", "vase__surface_cells"}),
    [](const ::testing::TestParamInfo<DesignAcceptanceCase> &info) {
      return info.param.testName;
    });

} // namespace
