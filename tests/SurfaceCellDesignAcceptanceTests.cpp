#include <algorithm>
#include <bit>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
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
         result.diagnostics.terminalFailureStage + " detail=" +
         result.diagnostics.terminalFailureDetailCode + " traceSegments=" +
         std::to_string(result.diagnostics.surfaceCellTraceSegmentCount) +
         " arrangementCells=" +
         std::to_string(result.diagnostics.surfaceCellArrangementCellCount) +
         " completedQuads=" +
         std::to_string(result.diagnostics.surfaceCellCompletedQuadCount) +
         " completion=" + result.surfaceCellContext.completionFailure;
}

std::string hex64(const std::uint64_t value) {
  char text[17];
  std::snprintf(text, sizeof(text), "%016llx",
                static_cast<unsigned long long>(value));
  return text;
}

// FNV-1a over the exact 64-bit pattern of every coefficient, row-major and
// low byte first, so equal digests mean bit-identical matrices on any host.
std::string bit_digest(const Eigen::MatrixXd &matrix) {
  std::uint64_t digest = 14695981039346656037ULL;
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      const std::uint64_t bits = std::bit_cast<std::uint64_t>(matrix(row, col));
      for (int byte = 0; byte < 8; ++byte) {
        digest ^= (bits >> (8 * byte)) & 0xffU;
        digest *= 1099511628211ULL;
      }
    }
  }
  return hex64(digest);
}

// One line per case: bit-exact input digests, then each context product's
// structural hash and element count. Most hashes quantize doubles to 1e-9,
// but the atlas digest hashes exact effort bits and several later hashes
// embed it, so those differ with any last-bit change in the field.
void print_platform_digest(const char *testName,
                           const directional::bench::BenchmarkMesh &mesh,
                           const Eigen::MatrixXd &rawField,
                           const directional::pipeline::RemeshResult &result) {
  std::cout << "platform-digest case=" << testName
            << " vertexBits=" << bit_digest(mesh.vertices)
            << " faceBits=" << bit_digest(mesh.faces.cast<double>())
            << " fieldBits=" << bit_digest(rawField);
  for (const auto &product : result.surfaceCellContext.debugProducts) {
    std::cout << ' ' << product.name << '=' << hex64(product.structuralHash)
              << '/' << product.elementCount;
  }
  // The final validator's issue counts by code, so a census run shows which
  // checks a RED output fails, not only the first one (RA-208).
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  if (snapshots.hasValidationResult) {
    std::map<std::string, int> issueCounts;
    for (const auto &issue : snapshots.validationResult.strictValidationIssues) {
      ++issueCounts[std::string(
          directional::validation::mesh_validation_failure_name(issue.code))];
    }
    std::cout << " validationIssues="
              << snapshots.validationResult.strictValidationIssues.size();
    for (const auto &[name, count] : issueCounts) {
      std::cout << ' ' << name << '=' << count;
    }
  }
  std::cout << std::endl;
  // Report-only A3 consumption recorded by A4 (RA-214 D4), on its own line so
  // the digest line above stays comparable with earlier runs.
  const auto &diagnostics = result.diagnostics;
  std::cout << "a3-coverage case=" << testName
            << " observed=" << (diagnostics.surfaceCellA3CoverageObserved ? 1 : 0)
            << " scheduled=" << diagnostics.surfaceCellA3ScheduledSpans
            << " covered=" << diagnostics.surfaceCellA3CoveredSpans
            << " partial=" << diagnostics.surfaceCellA3PartialSpans
            << " unrecorded=" << diagnostics.surfaceCellA3UnrecordedSpans
            << " foreign=" << diagnostics.surfaceCellA3ForeignIntervalEdges
            << std::endl;
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
  print_platform_digest(GetParam().testName, mesh, field.raw, result);

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

// RA-222 (D4): report-only rim census of the produced gate fixtures. For every
// A3 span on a source-boundary rail it prints the count the per-arc schedule
// gives, the count the chained schedule would give, and the number of output
// rim edges the phase front built there. Uniform and annulus regions do not
// read A3 today, so the three need not agree; nothing here asserts that they do.
class SurfaceCellDesignD4RimCensus
    : public ::testing::TestWithParam<DesignAcceptanceCase> {};

TEST_P(SurfaceCellDesignD4RimCensus, ReportsRimCountsAgainstTheA3Schedules) {
  using directional::geometry::ConformitySpanId;
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

  directional::pipeline::RemeshOptions options =
      directional::bench::make_remesh_options(benchmarkCase);
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.rejectPairedSourceTriangleBoundaryOutput = true;
  options.surfaceCells.preserveDebugArtifacts = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.useSkeletonHints = false;
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);

  const auto &context = result.surfaceCellContext;
  const auto &snapshots = context.productSnapshots;
  ASSERT_TRUE(snapshots.globalTopologyPlan.has_value());
  ASSERT_TRUE(snapshots.globalConformityBaseline.has_value());
  ASSERT_TRUE(snapshots.fieldAlignedCurveNetwork.has_value());
  const auto &topology = *snapshots.globalTopologyPlan;
  const auto &perArc = *snapshots.globalConformityBaseline;
  const auto &network = *snapshots.fieldAlignedCurveNetwork;
  const Eigen::VectorXd &targetSize = context.metricField.targetSize;

  // The chained schedule is comparable only if this test holds the inputs the
  // pipeline scheduled from: they must reproduce the published baseline.
  const bool ownInputs =
      targetSize.size() == mesh.vertices.rows() &&
      directional::geometry::validate_global_conformity_baseline(
          topology,
          directional::pipeline::remesh_pipeline_detail::
              make_global_conformity_baseline_input(mesh.vertices, targetSize,
                                                    topology),
          perArc)
          .has_value();
  std::optional<directional::geometry::GlobalConformityBaselineInput> chainedInput;
  std::optional<directional::geometry::GlobalConformityBaselinePlan> chained;
  if (ownInputs) {
    chainedInput =
        directional::geometry::make_chained_global_conformity_baseline_input(
            mesh.vertices, targetSize, topology, network,
            context.featureMap.curves);
    ASSERT_TRUE(chainedInput.has_value());
    std::size_t laterArcs = 0U;
    for (const auto &chain : chainedInput->chains) laterArcs += chain.size() - 1U;
    ASSERT_EQ(topology.arcs().size(), chainedInput->spans.size() + laterArcs);
    auto built = directional::geometry::build_global_conformity_baseline(
        topology, *chainedInput);
    ASSERT_TRUE(built);
    EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline(
        topology, *chainedInput, built.value()));
    chained = std::move(built.value());
  }

  // A rim arc lies on a source-boundary network edge. Its side is the chained
  // span that binds it, or the arc itself when there is no chained schedule.
  std::map<directional::authority::NetworkEdgeId,
           directional::authority::NetworkArcId>
      arcOfEdge;
  struct Side {
    std::size_t arcs = 0U;
    long long perArc = 0;
    std::string chained = "-";
    std::size_t output = 0U;
    std::size_t recorded = 0U;
  };
  std::map<directional::authority::NetworkArcId, Side> sides;
  const auto side_of = [&](const directional::authority::NetworkArcId arc) {
    if (!chained.has_value()) return arc;
    return chained->find_arc_binding(arc)->span.network_arc();
  };
  for (const auto &arc : topology.arcs()) {
    if (!arc.mandatoryEdge.has_value()) continue;
    const auto &edges = network.mandatory_edges();
    const auto edge = std::find_if(edges.begin(), edges.end(), [&](const auto &e) {
      return e.id == *arc.mandatoryEdge;
    });
    if (edge == edges.end() ||
        edge->kind != directional::geometry::SurfaceCellRailKind::Boundary) {
      continue;
    }
    arcOfEdge.emplace(*arc.mandatoryEdge, arc.id);
    Side &side = sides[side_of(arc.id)];
    ++side.arcs;
    const auto *entry =
        perArc.find_schedule(ConformitySpanId::from_network_arc(arc.id));
    ASSERT_NE(nullptr, entry);
    side.perArc += std::stoll(entry->count.to_string());
  }
  if (chained.has_value()) {
    for (auto &[head, side] : sides) {
      const auto *entry =
          chained->find_schedule(ConformitySpanId::from_network_arc(head));
      ASSERT_NE(nullptr, entry);
      side.chained = entry->count.to_string();
    }
  }

  const auto &phaseFront = snapshots.traceNetwork.phaseFront;
  const bool produced =
      phaseFront.disposition() ==
      directional::geometry::SurfaceCellProducerDisposition::Produced;
  std::size_t rimEdges = 0U;
  std::size_t unresolved = 0U;
  if (produced) {
    for (const auto &edge : phaseFront.product().edges()) {
      if (edge.boundaryKind !=
          directional::geometry::SurfaceFrontBoundaryKind::GenuineSourceBoundary) {
        continue;
      }
      ++rimEdges;
      // An output rim edge is counted on the side its first route step is on.
      const auto *mandatory = edge.route.steps().empty()
                                  ? nullptr
                                  : network.find_mandatory_edge(
                                        edge.route.steps().front().topology());
      const auto arc = mandatory == nullptr ? arcOfEdge.end()
                                            : arcOfEdge.find(mandatory->id);
      if (arc == arcOfEdge.end()) {
        ++unresolved;
        continue;
      }
      Side &side = sides[side_of(arc->second)];
      ++side.output;
      if (edge.sharedBoundaryInterval.has_value()) ++side.recorded;
    }
  }

  std::size_t rimArcs = 0U;
  long long perArcTotal = 0;
  std::ostringstream list;
  for (const auto &[head, side] : sides) {
    rimArcs += side.arcs;
    perArcTotal += side.perArc;
    list << (list.tellp() > 0 ? "," : "") << side.arcs << ':' << side.perArc
         << '/' << side.chained << '/' << side.output << '/' << side.recorded;
  }
  std::cout << "d4-rim case=" << GetParam().testName
            << " inputs=" << (ownInputs ? "own" : "foreign")
            << " phaseFront=" << (produced ? "Produced" : "NotProduced")
            << " rimArcs=" << rimArcs << " sides=" << sides.size()
            << " perArcTotal=" << perArcTotal << " outputRimEdges=" << rimEdges
            << " unresolved=" << unresolved
            << " arcs:perArc/chained/output/recorded=" << list.str()
            << std::endl;

  // RA-224: the chained schedule once rim rails also stop at the boundary
  // field corners. `chains` and `spans` read without/with those stops.
  if (!chainedInput.has_value() || !snapshots.fieldTransportAtlas.has_value()) {
    std::cout << "d4-corner case=" << GetParam().testName << " inputs=foreign"
              << std::endl;
    return;
  }
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  directional::geometry::cross_field_axes(snapshots.crossField, faceAxisX,
                                          faceAxisY);
  const auto fieldCorners =
      directional::geometry::derive_boundary_field_corner_vertices(
          mesh.vertices, mesh.faces, faceAxisX, faceAxisY,
          &*snapshots.fieldTransportAtlas);
  const auto stoppedInput =
      directional::geometry::make_chained_global_conformity_baseline_input(
          mesh.vertices, targetSize, topology, network,
          context.featureMap.curves, fieldCorners);
  ASSERT_TRUE(stoppedInput.has_value());
  const auto stoppedBuilt = directional::geometry::build_global_conformity_baseline(
      topology, *stoppedInput);
  ASSERT_TRUE(stoppedBuilt);
  EXPECT_TRUE(directional::geometry::validate_global_conformity_baseline(
      topology, *stoppedInput, stoppedBuilt.value()));
  // A stop only ever splits a span.
  EXPECT_GE(stoppedInput->spans.size(), chainedInput->spans.size());
  std::cout << "d4-corner case=" << GetParam().testName << " inputs=own"
            << " fieldCorners=" << fieldCorners.size()
            << " chains=" << chainedInput->chains.size() << '/'
            << stoppedInput->chains.size()
            << " spans=" << chainedInput->spans.size() << '/'
            << stoppedInput->spans.size() << std::endl;
}

INSTANTIATE_TEST_SUITE_P(
    ProducedGateFixtures, SurfaceCellDesignD4RimCensus,
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
