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

// O36 staging (RA-230): what one pipeline run built, so the per-arc and the
// chained rim schedules can be compared on the same input.
void print_switch_receipt(const std::string &testName, const char *schedule,
                          const directional::pipeline::RemeshResult &result) {
  const auto &diagnostics = result.diagnostics;
  std::cout << "switch-run case=" << testName << " schedule=" << schedule
            << " produced=" << (result.is_produced() ? 1 : 0) << " faces="
            << (result.is_produced() ? result.product().faces.rows() : 0)
            << " failure=" << diagnostics.terminalFailureCode << '/'
            << diagnostics.terminalFailureStage
            << " phaseFront=" << diagnostics.surfaceCellAuthoritativeProducerDisposition
            << " invalid=" << diagnostics.surfaceCellFirstInvalidProducerStage
            << '/' << diagnostics.surfaceCellFirstInvalidProducerReason
            << " a3=" << diagnostics.surfaceCellA3ScheduledSpans << '/'
            << diagnostics.surfaceCellA3CoveredSpans << '/'
            << diagnostics.surfaceCellA3PartialSpans << '/'
            << diagnostics.surfaceCellA3UnrecordedSpans << '/'
            << diagnostics.surfaceCellA3ForeignIntervalEdges << std::endl;
  // RA-231: every input of the final mesh gate, so a run rejected without a
  // strict issue (AggregateCompletionValidationFailure) shows which measure
  // failed. Values are pairs: p95/max, median/p95, p5/p95 or min/p5.
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  if (!snapshots.hasValidationResult) return;
  const auto &gate = snapshots.validationResult;
  std::cout << "switch-validation case=" << testName << " schedule=" << schedule
            << " accepted=" << (gate.accepted ? 1 : 0)
            << " strict=" << gate.strictValidationIssues.size()
            << " quadToSource=" << gate.quadToSourceP95 << '/'
            << gate.quadToSourceMax << " sourceToOutput="
            << gate.sourceToOutputP95 << '/' << gate.sourceToOutputMax
            << " normalP95=" << gate.normalP95Degrees
            << " field=" << gate.fieldMedianDegrees << '/' << gate.fieldP95Degrees
            << " size=" << gate.sizeP5 << '/' << gate.sizeP95
            << " angle=" << gate.angleP5Degrees << '/' << gate.angleP95Degrees
            << " warpage=" << gate.warpageP95Degrees << '/'
            << gate.warpageMaxDegrees << " aspect=" << gate.aspectP95 << '/'
            << gate.aspectP99 << " jacobian=" << gate.scaledJacobianMin << '/'
            << gate.scaledJacobianP5 << " nonConvex=" << gate.nonConvex
            << " boundaryValence=" << gate.boundaryValenceMismatchCount << '/'
            << gate.boundaryValenceTargetCount << " singularityValence="
            << gate.requiredSingularityValenceMismatchCount << '/'
            << gate.requiredSingularityValenceTargetCount
            << " tJunctions=" << gate.tJunctions
            << " nonManifold=" << gate.nonManifold
            << " degenerate=" << gate.degenerate << " inverted=" << gate.inverted
            << " selfIntersecting=" << gate.selfIntersecting
            << " topologyFixed=" << (gate.topologyHashFixed ? 1 : 0)
            << " featureOrdered=" << (gate.featureParametersOrdered ? 1 : 0)
            << " onComponents=" << (gate.projectionStayedOnComponents ? 1 : 0)
            << std::endl;
}

// RA-232 (O41): the mesh the final gate measured, its edge length over the
// local target split into boundary edges (one quad) and interior edges, and
// the target's range on the source. The gate counts a fixed rail edge as on
// target, so a low size percentile comes from interior edges; this shows how
// low and against which target. Each undirected edge counts once.
void print_switch_size_receipt(const std::string &testName, const char *schedule,
                               const Eigen::MatrixXi &sourceFaces,
                               const directional::pipeline::RemeshResult &result) {
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  const Eigen::VectorXd &target = result.surfaceCellContext.metricField.targetSize;
  if (!snapshots.hasOptimizationResult || target.size() == 0) return;
  const auto &checked = snapshots.optimizationResult;
  const auto local_target = [&](const int vertex) {
    if (vertex < 0 ||
        vertex >= static_cast<int>(checked.vertexProvenance.size())) {
      return 0.0;
    }
    const auto &point = checked.vertexProvenance[static_cast<std::size_t>(vertex)];
    if (point.face < 0 || point.face >= sourceFaces.rows()) return 0.0;
    double value = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      const int source = sourceFaces(point.face, corner);
      if (source >= 0 && source < target.size()) {
        value += point.barycentric(corner) * target(source);
      }
    }
    return value;
  };
  std::map<std::pair<int, int>, std::pair<int, double>> edges;
  for (int quad = 0; quad < checked.quads.rows(); ++quad) {
    for (int corner = 0; corner < 4; ++corner) {
      const int a = checked.quads(quad, corner);
      const int b = checked.quads(quad, (corner + 1) % 4);
      if (a < 0 || b < 0 || a >= checked.vertices.rows() ||
          b >= checked.vertices.rows()) {
        continue;
      }
      const double length = (checked.vertices.row(b) - checked.vertices.row(a)).norm();
      const double localTarget = 0.5 * (local_target(a) + local_target(b));
      auto &entry = edges[{std::min(a, b), std::max(a, b)}];
      ++entry.first;
      entry.second = localTarget > 0.0 ? length / localTarget : 0.0;
    }
  }
  std::vector<double> boundary;
  std::vector<double> interior;
  for (const auto &[key, entry] : edges) {
    (entry.first == 1 ? boundary : interior).push_back(entry.second);
  }
  const auto summary = [](std::vector<double> values) {
    std::ostringstream text;
    text << values.size();
    if (values.empty()) return text.str();
    std::sort(values.begin(), values.end());
    const auto at = [&](const double q) {
      return values[static_cast<std::size_t>(q * static_cast<double>(values.size() - 1U))];
    };
    text << ':' << at(0.05) << '/' << at(0.5) << '/' << at(0.95);
    return text.str();
  };
  const auto belowHalf = std::count_if(interior.begin(), interior.end(),
                                       [](const double ratio) { return ratio < 0.5; });
  std::vector<double> sourceTarget(target.data(), target.data() + target.size());
  std::sort(sourceTarget.begin(), sourceTarget.end());
  std::cout << "switch-size case=" << testName << " schedule=" << schedule
            << " quads=" << checked.quads.rows()
            << " boundary=" << summary(boundary)
            << " interior=" << summary(interior)
            << " interiorBelowHalf=" << belowHalf
            << " target=" << sourceTarget.front() << '/'
            << sourceTarget[sourceTarget.size() / 2U] << '/'
            << sourceTarget.back() << std::endl;
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

  // O36 staging (RA-230): the same input with chained rim schedules.
  print_switch_receipt(GetParam().testName, "perArc", result);
  print_switch_size_receipt(GetParam().testName, "perArc", mesh.faces, result);
  {
    directional::pipeline::RemeshOptions chainedOptions = options;
    chainedOptions.surfaceCells.chainRimSchedules = true;
    const directional::pipeline::RemeshResult chainedResult =
        directional::pipeline::remesh_from_raw_cross_field(
            mesh.vertices, mesh.faces, field.raw, chainedOptions);
    print_switch_receipt(GetParam().testName, "chained", chainedResult);
    print_switch_size_receipt(GetParam().testName, "chained", mesh.faces,
                              chainedResult);
  }

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
  // RA-228: an annulus reads both rims from the plan, so it records an
  // interval on every output rim edge.
  if (produced && !phaseFront.product().periodicHolonomies().empty()) {
    std::size_t recorded = 0U;
    for (const auto &[head, side] : sides) recorded += side.recorded;
    EXPECT_EQ(0U, unresolved);
    EXPECT_EQ(rimEdges, recorded);
  }

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

  // O39: the exact rim branch rule on every source-boundary edge, taken in
  // its face's direction.
  std::map<std::pair<int, int>, int> edgeFaceCount;
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = mesh.faces(face, corner);
      const int b = mesh.faces(face, (corner + 1) % 3);
      ++edgeFaceCount[{std::min(a, b), std::max(a, b)}];
    }
  }
  std::size_t sourceRimEdges = 0U;
  std::size_t decided = 0U;
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = mesh.faces(face, corner);
      const int b = mesh.faces(face, (corner + 1) % 3);
      if (edgeFaceCount.at({std::min(a, b), std::max(a, b)}) != 1) continue;
      const auto exact = directional::geometry::surface_cell_tracing_detail::
          exact_boundary_edge_field_branch(mesh.vertices, mesh.faces, faceAxisX,
                                           faceAxisY, face, a, b);
      ++sourceRimEdges;
      if (exact.has_value()) ++decided;
    }
  }
  EXPECT_GT(sourceRimEdges, 0U);
  std::cout << "rim-branch case=" << GetParam().testName
            << " rimEdges=" << sourceRimEdges << " decided=" << decided
            << " undecided=" << sourceRimEdges - decided << std::endl;

  // 64D: what each schedule places on every rim network edge, against the
  // output rim edges there. The annulus lattice puts a breakpoint at every
  // rim vertex and splits each rim edge evenly, so it can read a schedule
  // only on edges where both hold.
  std::map<directional::authority::NetworkEdgeId,
           std::vector<const directional::geometry::GlobalTopologyArc *>>
      rimArcsOnEdge;
  for (const auto &arc : topology.arcs()) {
    if (arc.mandatoryEdge.has_value() && arcOfEdge.count(*arc.mandatoryEdge) != 0U) {
      rimArcsOnEdge[*arc.mandatoryEdge].push_back(&arc);
    }
  }
  std::map<directional::authority::NetworkEdgeId, long long> outputOnEdge;
  if (produced) {
    for (const auto &edge : phaseFront.product().edges()) {
      if (edge.boundaryKind !=
              directional::geometry::SurfaceFrontBoundaryKind::GenuineSourceBoundary ||
          edge.route.steps().empty()) {
        continue;
      }
      const auto *mandatory =
          network.find_mandatory_edge(edge.route.steps().front().topology());
      if (mandatory != nullptr) ++outputOnEdge[mandatory->id];
    }
  }
  const std::size_t periodic =
      produced ? phaseFront.product().periodicHolonomies().size() : 0U;
  const auto report_rim_schedule =
      [&](const char *schedule,
          const directional::geometry::GlobalConformityBaselinePlan &plan) {
        std::size_t split = 0U;
        std::size_t vertexBreaks = 0U;
        std::size_t equalOutput = 0U;
        std::size_t evenSplit = 0U;
        for (const auto &[edge, arcs] : rimArcsOnEdge) {
          if (arcs.size() > 1U) ++split;
          bool breaks = true;
          bool even = true;
          long long intervals = 0;
          for (const auto *arc : arcs) {
            const auto *binding = plan.find_arc_binding(arc->id);
            ASSERT_NE(nullptr, binding);
            const auto *entry = plan.find_schedule(binding->span);
            ASSERT_NE(nullptr, entry);
            // An arc is one support piece. A breakpoint on its far end is
            // located at the start of the next piece, the span's last one at
            // the end of its last piece.
            const std::size_t piece = binding->firstSupportPiece;
            const long long count = std::stoll(entry->count.to_string());
            bool startBreak = false;
            bool endBreak = false;
            std::vector<std::pair<EInt, EInt>> inside;
            for (long long ordinal = 0; ordinal <= count; ++ordinal) {
              const auto location =
                  plan.breakpoint_location(binding->span, EInt(ordinal));
              ASSERT_TRUE(location.has_value());
              const bool atStart = location->localNumerator == EInt(0);
              if (location->supportPieceIndex == piece) {
                if (atStart) {
                  startBreak = true;
                } else if (location->localNumerator == location->localDenominator) {
                  endBreak = true;
                } else {
                  inside.emplace_back(location->localNumerator,
                                      location->localDenominator);
                }
              } else if (location->supportPieceIndex == piece + 1U && atStart) {
                endBreak = true;
              }
            }
            breaks = breaks && startBreak && endBreak;
            intervals += static_cast<long long>(inside.size()) + 1;
            const EInt parts(static_cast<long long>(inside.size()) + 1);
            for (std::size_t k = 0U; k < inside.size(); ++k) {
              const EInt step(static_cast<long long>(k) + 1);
              if (!(inside[k].first * parts == inside[k].second * step)) {
                even = false;
              }
            }
          }
          if (!breaks) continue;
          ++vertexBreaks;
          const auto output = outputOnEdge.find(edge);
          if (output != outputOnEdge.end() && output->second == intervals) {
            ++equalOutput;
          }
          if (even) ++evenSplit;
        }
        std::cout << "annulus-rim case=" << GetParam().testName
                  << " schedule=" << schedule << " periodic=" << periodic
                  << " rimEdges=" << rimArcsOnEdge.size() << " split=" << split
                  << " vertexBreaks=" << vertexBreaks
                  << " equalOutput=" << equalOutput
                  << " evenSplit=" << evenSplit << std::endl;
      };
  report_rim_schedule("perArc", perArc);
  report_rim_schedule("chained", *chained);
  report_rim_schedule("stopped", stoppedBuilt.value());

  // O37: the one-pass locator gives every span's breakpoints exactly as the
  // per-ordinal locator does, on all three schedules.
  using PlanPointer = const directional::geometry::GlobalConformityBaselinePlan *;
  for (const PlanPointer plan : std::initializer_list<PlanPointer>{
           &perArc, &*chained, &stoppedBuilt.value()}) {
    for (const auto &entry : plan->schedule()) {
      const auto batch = plan->breakpoint_locations(entry.span);
      ASSERT_TRUE(batch.has_value());
      ASSERT_EQ(std::stoull(entry.count.to_string()) + 1U, batch->size());
      for (std::size_t ordinal = 0U; ordinal < batch->size(); ++ordinal) {
        const auto single = plan->breakpoint_location(
            entry.span, EInt(static_cast<long long>(ordinal)));
        ASSERT_TRUE(single.has_value());
        const auto &located = (*batch)[ordinal];
        EXPECT_TRUE(located.id == single->id &&
                    located.supportPieceIndex == single->supportPieceIndex &&
                    located.localNumerator == single->localNumerator &&
                    located.localDenominator == single->localDenominator &&
                    located.firstEndpoint == single->firstEndpoint &&
                    located.lastEndpoint == single->lastEndpoint)
            << entry.span.network_arc().index() << '/' << ordinal;
      }
    }
  }

  // RA-232 (O41): how far the parity solve moved the field-corner-stopped
  // spans from their preferred counts.
  std::size_t raised = 0U;
  std::size_t lowered = 0U;
  std::ostringstream moved;
  for (const auto &entry : stoppedBuilt.value().schedule()) {
    if (entry.count == entry.preferredCount) continue;
    (entry.preferredCount < entry.count ? raised : lowered) += 1U;
    moved << (moved.tellp() > 0 ? "," : "") << entry.preferredCount.to_string()
          << "->" << entry.count.to_string();
  }
  std::cout << "switch-spans case=" << GetParam().testName << " schedule=stopped"
            << " spans=" << stoppedBuilt.value().schedule().size()
            << " raised=" << raised << " lowered=" << lowered
            << " moved=" << (moved.tellp() > 0 ? moved.str() : "-") << std::endl;
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

// O36 staging (RA-230): a flat disc whose rim is smooth, so only the field
// corners can cut it into sides. No gate fixture has one. Receipt only.
TEST(SurfaceCellDesignSwitchReceipt, SmoothRimDiscUnderBothRimSchedules) {
  constexpr int kSegments = 32;
  constexpr int kRings = 6;
  const double pi = std::acos(-1.0);
  const auto vertex = [](const int ring, const int segment) {
    return 1 + (ring - 1) * kSegments + (segment % kSegments);
  };
  Eigen::MatrixXd vertices(1 + kRings * kSegments, 3);
  vertices.row(0) << 0.0, 0.0, 0.0;
  for (int ring = 1; ring <= kRings; ++ring) {
    for (int segment = 0; segment < kSegments; ++segment) {
      const double angle = 2.0 * pi * segment / kSegments;
      const double radius = static_cast<double>(ring) / kRings;
      vertices.row(vertex(ring, segment)) << radius * std::cos(angle),
          radius * std::sin(angle), 0.0;
    }
  }
  Eigen::MatrixXi faces(kSegments * (2 * kRings - 1), 3);
  int face = 0;
  for (int segment = 0; segment < kSegments; ++segment) {
    faces.row(face++) << 0, vertex(1, segment), vertex(1, segment + 1);
  }
  for (int ring = 1; ring < kRings; ++ring) {
    for (int segment = 0; segment < kSegments; ++segment) {
      const int a = vertex(ring, segment);
      const int b = vertex(ring, segment + 1);
      const int c = vertex(ring + 1, segment + 1);
      const int d = vertex(ring + 1, segment);
      faces.row(face++) << a, d, c;
      faces.row(face++) << a, c, b;
    }
  }
  ASSERT_EQ(faces.rows(), face);
  Eigen::MatrixXd raw(faces.rows(), 12);
  for (int row = 0; row < faces.rows(); ++row) {
    raw.row(row) << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0,
        0.0;
  }

  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.lengthRatio = 0.2;
  print_switch_receipt("SmoothRimDisc", "perArc",
                       directional::pipeline::remesh_from_raw_cross_field(
                           vertices, faces, raw, options));
  options.surfaceCells.chainRimSchedules = true;
  print_switch_receipt("SmoothRimDisc", "chained",
                       directional::pipeline::remesh_from_raw_cross_field(
                           vertices, faces, raw, options));
}

} // namespace
