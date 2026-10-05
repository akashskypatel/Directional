#include <algorithm>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "BenchmarkCases.h"
#include "TestFixturePaths.h"
#include <directional/geometry/GeneralGraphMatching.h>
#include "TestAuthorityIds.h"

namespace {

namespace fs = std::filesystem;

fs::path source_root() { return directional::tests::test_data_root(); }

fs::path fixture_manifest() {
  return source_root() / "benchmarks" / "fixtures" /
         "milestone_g_manifest.json";
}

const directional::bench::BenchmarkCase &
find_case(const std::vector<directional::bench::BenchmarkCase> &cases,
          const std::string &name) {
  const auto found =
      std::find_if(cases.begin(), cases.end(), [&](const auto &benchmarkCase) {
        return benchmarkCase.name == name;
      });
  if (found == cases.end()) {
    throw std::runtime_error("Missing benchmark case: " + name);
  }
  return *found;
}

directional::fields::CrossFieldResult
recovery_field(const directional::bench::BenchmarkField &field) {
  directional::fields::CrossFieldResult result;
  result.degree = 4;
  result.rawField = field.raw;
  directional::pipeline::normalize_surface_cell_cross_field_directions(result);
  return result;
}


const std::set<directional::authority::SourceEdgeTopologyKey> &
no_recovery_excluded_edges() {
  static const std::set<directional::authority::SourceEdgeTopologyKey> edges;
  return edges;
}

directional::geometry::SourceTopologyRegions recovery_source_authority(
    const Eigen::MatrixXi &faces,
    const std::vector<int> &components = {},
    const std::vector<int> &sheets = {}) {
  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.sourceFaceComponents = components;
  tracing.sourceFaceSheets = sheets;
  auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, tracing);
  if (!authority.has_value()) {
    throw std::runtime_error(
        "Failed to construct source-grid recovery test authority.");
  }
  return std::move(authority.value());
}

directional::pipeline::RemeshResult run_surface_cell_case(
    const directional::bench::BenchmarkMesh &mesh,
    const directional::bench::BenchmarkField &field,
    const directional::pipeline::RemeshOptions &options) {
  if (field.available) {
    return directional::pipeline::remesh_from_raw_cross_field(
        mesh.vertices, mesh.faces, field.raw, options);
  }
  return directional::pipeline::remesh_from_mesh(mesh.vertices, mesh.faces,
                                                  options);
}

std::vector<int> json_integer_array(const fs::path &path,
                                    const std::string &key) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open JSON fixture metadata: " +
                             path.string());
  }
  std::ostringstream text;
  text << stream.rdbuf();
  const std::regex arrayPattern("\\\"" + key + "\\\"\\s*:\\s*\\[([^\\]]*)\\]");
  std::smatch match;
  const std::string document = text.str();
  if (!std::regex_search(document, match, arrayPattern)) {
    throw std::runtime_error("Missing JSON integer array: " + key);
  }
  std::vector<int> values;
  const std::regex numberPattern("-?[0-9]+");
  for (std::sregex_iterator
           iterator(match[1].first, match[1].second, numberPattern),
       end;
       iterator != end; ++iterator) {
    values.push_back(std::stoi(iterator->str()));
  }
  return values;
}

int brute_force_matching_cardinality(
    const int vertexCount,
    const std::vector<std::vector<unsigned char>> &adjacent,
    const std::uint32_t available) {
  int first = -1;
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    if ((available & (std::uint32_t{1} << vertex)) != 0U) {
      first = vertex;
      break;
    }
  }
  if (first < 0) {
    return 0;
  }
  const std::uint32_t withoutFirst =
      available & ~(std::uint32_t{1} << first);
  int best = brute_force_matching_cardinality(
      vertexCount, adjacent, withoutFirst);
  for (int second = first + 1; second < vertexCount; ++second) {
    if ((withoutFirst & (std::uint32_t{1} << second)) == 0U ||
        adjacent[static_cast<std::size_t>(first)]
                [static_cast<std::size_t>(second)] == 0U) {
      continue;
    }
    best = std::max(
        best, 1 + brute_force_matching_cardinality(
                      vertexCount, adjacent,
                      withoutFirst & ~(std::uint32_t{1} << second)));
  }
  return best;
}

void expect_completed_surface_cells(
    const directional::bench::BenchmarkCase &benchmarkCase,
    const bool expectSourceGridRecovery) {
  const directional::bench::BenchmarkMesh mesh =
      directional::bench::load_benchmark_mesh(benchmarkCase);
  const directional::bench::BenchmarkField field =
      directional::bench::load_benchmark_field(benchmarkCase,
                                               mesh.faces.rows());
  directional::pipeline::RemeshOptions options =
      directional::bench::make_remesh_options(benchmarkCase);
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = true;
  options.surfaceCells.enforceOptimizerTimeGate = false;
  options.parallelizeComponents = true;
  options.maxComponentThreads = 2;

  const directional::pipeline::RemeshResult result =
      run_surface_cell_case(mesh, field, options);

  ASSERT_TRUE(result.is_produced())
      << benchmarkCase.name << ": " << result.diagnostics.terminalFailureCode
      << "/" << result.diagnostics.terminalFailureStage
      << " component=" << result.diagnostics.failedComponentIndex
      << " validationFailures="
      << result.diagnostics.surfaceCellValidationFailures << " topology="
      << result.surfaceCellContext.productSnapshots.validationResult
             .connectedComponentMismatchCount
      << "/"
      << result.surfaceCellContext.productSnapshots.validationResult
             .eulerCharacteristicMismatchCount
      << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.boundaryCycleMismatchCount
      << " rails="
      << result.surfaceCellContext.productSnapshots.validationResult.featureRailMismatchCount
      << " provenance="
      << result.surfaceCellContext.productSnapshots.validationResult.provenanceFailureCount
      << " sheets="
      << result.surfaceCellContext.productSnapshots.validationResult.localSheetMismatchCount
      << " geometry=" << result.surfaceCellContext.productSnapshots.validationResult.degenerate
      << "/" << result.surfaceCellContext.productSnapshots.validationResult.inverted << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.selfIntersecting
      << " manifold(t/nonmanifold/nonconvex)="
      << result.surfaceCellContext.productSnapshots.validationResult.tJunctions << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.nonManifold << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.nonConvex
      << " valence(boundary/singularity)="
      << result.surfaceCellContext.productSnapshots.validationResult.boundaryValenceMismatchCount
      << "/"
      << result.surfaceCellContext.productSnapshots.validationResult
             .requiredSingularityValenceMismatchCount
      << " surface/normal="
      << result.surfaceCellContext.productSnapshots.validationResult.quadToSourceP95 << ","
      << result.surfaceCellContext.productSnapshots.validationResult.quadToSourceMax << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.sourceToOutputP95 << ","
      << result.surfaceCellContext.productSnapshots.validationResult.sourceToOutputMax << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.normalP95Degrees
      << " quality(size/field/jacobian)="
      << result.surfaceCellContext.productSnapshots.validationResult.sizeP5 << ","
      << result.surfaceCellContext.productSnapshots.validationResult.sizeP95 << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.fieldMedianDegrees << ","
      << result.surfaceCellContext.productSnapshots.validationResult.fieldP95Degrees << "/"
      << result.surfaceCellContext.productSnapshots.validationResult.scaledJacobianMin << ","
      << result.surfaceCellContext.productSnapshots.validationResult.scaledJacobianP5
      << " optimizer(iterations/rollback/line-search/"
         "hard/orientation)="
      << result.surfaceCellContext.productSnapshots.optimizationResult.iterations.size() << "/"
      << result.surfaceCellContext.productSnapshots.optimizationResult.rolledBackToInput << "/"
      << result.surfaceCellContext.productSnapshots.optimizationResult.lineSearchRejectionCount
      << "/"
      << result.surfaceCellContext.productSnapshots.optimizationResult
             .hardInvariantRejectionCount
      << "/"
      << result.surfaceCellContext.productSnapshots.optimizationResult.orientationRejectionCount
      << " energy(size/field)="
      << result.surfaceCellContext.productSnapshots.optimizationResult.initialEnergy.size << ","
      << result.surfaceCellContext.productSnapshots.optimizationResult.finalEnergy.size << "/"
      << result.surfaceCellContext.productSnapshots.optimizationResult.initialEnergy.field << ","
      << result.surfaceCellContext.productSnapshots.optimizationResult.finalEnergy.field;
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  if (expectSourceGridRecovery) {
    EXPECT_TRUE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
    EXPECT_TRUE(result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
    EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize);
    EXPECT_GT(result.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize.size(), 0);
    EXPECT_LE(result.diagnostics
                  .surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio,
              options.surfaceCells.maxSourceGridRecoveryTargetRelaxation);
    EXPECT_EQ(2 * mesh.faces.rows(),
              static_cast<Eigen::Index>(result.product().faces.rows()));
    EXPECT_GT(result.product().vertices.rows(), mesh.vertices.rows());
  } else {
    EXPECT_GT(result.product().faces.rows(), 0);
  }
  EXPECT_EQ(expectSourceGridRecovery
                ? directional::SurfaceCellOutputOrigin::SourceGridRecovery
                : directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  ASSERT_EQ(result.product().faces.rows(), result.product().degrees.size());
  for (Eigen::Index face = 0; face < result.product().degrees.size(); ++face) {
    EXPECT_EQ(4, result.product().degrees(face));
  }
  EXPECT_EQ(static_cast<std::size_t>(result.product().vertices.rows()),
            result.product().outputVertexProvenance.size());
  EXPECT_EQ(static_cast<std::size_t>(result.product().faces.rows()),
            result.product().outputQuadLineage.size());
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasValidationResult);
  EXPECT_TRUE(result.surfaceCellContext.productSnapshots.validationResult.accepted);
}

void expect_truthful_surface_cells_outcome(
    const directional::bench::BenchmarkCase &benchmarkCase) {
  directional::pipeline::RemeshResult result;
  {
    const directional::bench::BenchmarkMesh mesh =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const directional::bench::BenchmarkField field =
        directional::bench::load_benchmark_field(benchmarkCase,
                                                 mesh.faces.rows());
    directional::pipeline::RemeshOptions options =
        directional::bench::make_remesh_options(benchmarkCase);
    options.surfaceCells.fallbackPolicy =
        directional::pipeline::SurfaceCellFallbackPolicy::Fail;
    options.surfaceCells.allowSourceGridRecovery = true;
    options.surfaceCells.enforceOptimizerTimeGate = false;
    options.parallelizeComponents = true;
    options.maxComponentThreads = 2;

    std::cerr << "[P5_P26_BEFORE_PIPELINE] " << benchmarkCase.name
              << std::endl;
    result = run_surface_cell_case(mesh, field, options);
    std::cerr << "[P5_P26_AFTER_PIPELINE] " << benchmarkCase.name
              << " success=" << result.is_produced() << std::endl;
  }
  std::cerr << "[P5_P26_AFTER_INPUT_DESTRUCTION] " << benchmarkCase.name
            << std::endl;

  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend)
      << benchmarkCase.name;
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend)
      << benchmarkCase.name;
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted)
      << benchmarkCase.name;
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback)
      << benchmarkCase.name;
  EXPECT_FALSE(result.diagnostics.surfaceCellReturnedInputMeshFallback)
      << benchmarkCase.name;

  if (result.is_produced()) {
    EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred)
        << benchmarkCase.name;
    EXPECT_EQ(result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed
                  ? directional::SurfaceCellOutputOrigin::SourceGridRecovery
                  : directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
              result.diagnostics.surfaceCellOutputOrigin)
        << benchmarkCase.name;
    EXPECT_EQ("None", result.diagnostics.terminalFailureCode)
        << benchmarkCase.name;
    EXPECT_TRUE(result.diagnostics.terminalFailureStage.empty())
        << benchmarkCase.name;
    ASSERT_EQ(result.product().faces.rows(), result.product().degrees.size()) << benchmarkCase.name;
    EXPECT_TRUE((result.product().degrees.array() == 4).all()) << benchmarkCase.name;
    EXPECT_TRUE(result.surfaceCellContext.productSnapshots.hasValidationResult)
        << benchmarkCase.name;
    EXPECT_TRUE(result.surfaceCellContext.productSnapshots.validationResult.accepted)
        << benchmarkCase.name;
  } else {
    EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred)
        << benchmarkCase.name;
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
              result.diagnostics.surfaceCellOutputOrigin)
        << benchmarkCase.name;
    EXPECT_NE("None", result.diagnostics.terminalFailureCode)
        << benchmarkCase.name;
    EXPECT_FALSE(result.diagnostics.terminalFailureStage.empty())
        << benchmarkCase.name;
    EXPECT_EQ(result.diagnostics.terminalFailureCode,
              result.diagnostics.originalSurfaceCellFailureCode)
        << benchmarkCase.name;
    EXPECT_EQ(result.diagnostics.terminalFailureStage,
              result.diagnostics.originalSurfaceCellFailureStage)
        << benchmarkCase.name;
    EXPECT_EQ(0, result.product().vertices.rows()) << benchmarkCase.name;
    EXPECT_EQ(0, result.product().faces.rows()) << benchmarkCase.name;
  }
  std::cerr << "[P5_P26_AFTER_DIAGNOSTIC_READS] " << benchmarkCase.name
            << std::endl;
  std::cerr << "[P5_P26_BEFORE_RESULT_DESTRUCTION] " << benchmarkCase.name
            << std::endl;
}

TEST(MilestoneGP26, RecoveryTargetProjectionIsBoundedAndDeterministic) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  const auto &benchmarkCase = find_case(cases, "plane__surface_cells");
  const auto meshData = directional::bench::load_benchmark_mesh(benchmarkCase);
  const auto fieldData = directional::bench::load_benchmark_field(
      benchmarkCase, meshData.faces.rows());
  directional::TriMesh mesh;
  mesh.set_mesh(meshData.vertices, meshData.faces);
  const auto sourceAuthority = recovery_source_authority(mesh.F);
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData), &sourceAuthority,
          &no_recovery_excluded_edges());
  ASSERT_TRUE(recovery.success) << recovery.failure;

  Eigen::MatrixXi quads(static_cast<int>(recovery.mesh.quads.size()), 4);
  for (int face = 0; face < quads.rows(); ++face) {
    for (int corner = 0; corner < 4; ++corner) {
      quads(face, corner) =
          recovery.mesh.quads[static_cast<std::size_t>(face)]
                             [static_cast<std::size_t>(corner)];
    }
  }
  const double requested = 0.5 *
                           (meshData.vertices.colwise().maxCoeff() -
                            meshData.vertices.colwise().minCoeff())
                               .norm() *
                           benchmarkCase.lengthRatio;
  const auto first =
      directional::pipeline::make_source_grid_recovery_target_size(
          meshData.vertices, meshData.faces, recovery.mesh.vertexPositions,
          quads, recovery.mesh.vertexProvenance, requested, 2.0);
  const auto second =
      directional::pipeline::make_source_grid_recovery_target_size(
          meshData.vertices, meshData.faces, recovery.mesh.vertexPositions,
          quads, recovery.mesh.vertexProvenance, requested, 2.0);
  ASSERT_TRUE(first.valid) << first.failure;
  ASSERT_TRUE(second.valid) << second.failure;
  EXPECT_TRUE(first.targetSize.isApprox(second.targetSize, 0.0));
  EXPECT_DOUBLE_EQ(first.maxRelaxationRatio, second.maxRelaxationRatio);
  EXPECT_GE(first.targetSize.minCoeff(), requested / 2.0);
  EXPECT_LE(first.targetSize.maxCoeff(), requested * 2.0);
}

TEST(MilestoneGP26, RequiredProductionRecoveryTargetsAreFeasible) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  const std::vector<std::string> requiredCases = {
      "plane__surface_cells",
      "cylinder__surface_cells",
      "torus__surface_cells",
      "multi_face_seam__surface_cells",
      "mechanical_feature__surface_cells",
      "close_sheets__surface_cells"};

  for (const std::string &caseName : requiredCases) {
    const auto &benchmarkCase = find_case(cases, caseName);
    const auto meshData =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const auto fieldData = directional::bench::load_benchmark_field(
        benchmarkCase, meshData.faces.rows());
    directional::TriMesh mesh;
    mesh.set_mesh(meshData.vertices, meshData.faces);
    const auto sourceAuthority = recovery_source_authority(mesh.F);
    const auto recovery =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData), &sourceAuthority,
            &no_recovery_excluded_edges());
    ASSERT_TRUE(recovery.success) << caseName << ": " << recovery.failure;

    Eigen::MatrixXi quads(static_cast<int>(recovery.mesh.quads.size()), 4);
    for (int face = 0; face < quads.rows(); ++face) {
      for (int corner = 0; corner < 4; ++corner) {
        quads(face, corner) =
            recovery.mesh.quads[static_cast<std::size_t>(face)]
                               [static_cast<std::size_t>(corner)];
      }
    }
    const double requested = 0.5 *
                             (meshData.vertices.colwise().maxCoeff() -
                              meshData.vertices.colwise().minCoeff())
                                 .norm() *
                             benchmarkCase.lengthRatio;
    const auto target =
        directional::pipeline::make_source_grid_recovery_target_size(
            meshData.vertices, meshData.faces, recovery.mesh.vertexPositions,
            quads, recovery.mesh.vertexProvenance, requested, 2.0);
    EXPECT_TRUE(target.valid) << caseName << ": " << target.failure;
    EXPECT_LE(target.maxRelaxationRatio, 2.0) << caseName;
    EXPECT_TRUE(target.targetSize.allFinite()) << caseName;
    EXPECT_GT(target.targetSize.minCoeff(), 0.0) << caseName;
  }
}

TEST(MilestoneGP26, FeatureRailVerticesSupportBothIncidentLocalSheets) {
  Eigen::MatrixXd sourceVertices(6, 3);
  sourceVertices << -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 1.0,
      0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  Eigen::MatrixXi outputQuads(2, 4);
  outputQuads << 0, 1, 4, 3, 1, 2, 5, 4;
  const std::vector<int> components = {0, 0, 0, 0};
  const std::vector<int> sheets = {0, 0, 1, 1};

  std::vector<directional::geometry::SurfacePoint> provenance(6);
  const auto assign = [&](const int outputVertex, const int sourceFace,
                          const int sourceCorner) {
    auto &point = provenance[static_cast<std::size_t>(outputVertex)];
    point.face = sourceFace;
    point.component = components[static_cast<std::size_t>(sourceFace)];
    point.sheet = sheets[static_cast<std::size_t>(sourceFace)];
    point.barycentric = Eigen::Vector3d::Zero();
    point.barycentric(sourceCorner) = 1.0;
    point.position = sourceVertices.row(outputVertex).transpose();
    point.squaredDistance = 0.0;
  };
  assign(0, 0, 0);
  assign(1, 0, 1); // Shared crease vertex chooses the left chart.
  assign(4, 0, 2); // Shared crease vertex chooses the left chart.
  assign(3, 1, 2);
  assign(2, 2, 1);
  assign(5, 2, 2);

  directional::validation::SourceAuthoritativeMeshValidatorOptions options;
  options.sourceVertices = &sourceVertices;
  options.sourceFaces = &sourceFaces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;
  options.vertexProvenance = &provenance;
  options.authoritativeBoundaryEdges = {{0, 1}, {1, 2}, {2, 5},
                                        {4, 5}, {3, 4}, {0, 3}};
  options.authoritativeFeatureRails = {{1, 4}};
  options.expectedFeatureRailCount = 1;

  const auto validation =
      directional::validation::validate_source_authoritative_surface_mesh(
          sourceVertices, outputQuads, options);
  EXPECT_TRUE(validation.accepted);
  EXPECT_TRUE(validation.localSheetCompatibilityPassed);
  EXPECT_TRUE(validation.featureRailsPassed);
}

TEST(MilestoneGP26, FeatureRailAssemblyAcceptsIncidentSheetCharts) {
  Eigen::MatrixXd sourceVertices(6, 3);
  sourceVertices << -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 1.0,
      0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0;
  Eigen::MatrixXi sourceFaces(4, 3);
  sourceFaces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  const std::vector<int> components = {0, 0, 0, 0};
  const std::vector<int> sheets = {0, 0, 1, 1};

  std::vector<directional::geometry::SurfacePoint> provenance(6);
  for (int vertex = 0; vertex < sourceVertices.rows(); ++vertex) {
    auto &point = provenance[static_cast<std::size_t>(vertex)];
    point.face = vertex == 3 ? 1 : (vertex >= 2 && vertex != 4 ? 2 : 0);
    point.component = components[static_cast<std::size_t>(point.face)];
    point.sheet = sheets[static_cast<std::size_t>(point.face)];
    point.barycentric = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      if (sourceFaces(point.face, corner) == vertex) {
        point.barycentric(corner) = 1.0;
      }
    }
    point.position = sourceVertices.row(vertex).transpose();
    point.squaredDistance = 0.0;
  }
  // The shared crease endpoints intentionally use the left-sheet chart.
  provenance[1].face = 0;
  provenance[1].sheet = 0;
  provenance[1].barycentric << 0.0, 1.0, 0.0;
  provenance[4].face = 0;
  provenance[4].sheet = 0;
  provenance[4].barycentric << 0.0, 0.0, 1.0;

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(9));
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.curveId = 7;
  rail.component = 0;
  rail.sourceVertices = {1, 4};
  directional::geometry::SurfaceCellRailSample start;
  start.sourceFace = 3;
  start.barycentric << 1.0, 0.0, 0.0;
  start.position = sourceVertices.row(1);
  start.railParameter = 0.0;
  directional::geometry::SurfaceCellRailSample end;
  end.sourceFace = 3;
  end.barycentric << 0.0, 0.0, 1.0;
  end.position = sourceVertices.row(4);
  end.railParameter = 1.0;
  rail.samples = {start, end};

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceFaces = sourceFaces;
  constraints.sourceFaceComponent = components;
  constraints.sourceFaceSheet = sheets;
  directional::geometry::fill_surface_optimization_rail_constraints(
      {rail}, sourceVertices, provenance, constraints);

  EXPECT_EQ(1U, constraints.requiredFeatureRailCount);
  EXPECT_NE(constraints.featureVertices.end(),
            std::find(constraints.featureVertices.begin(),
                      constraints.featureVertices.end(), 1));
  EXPECT_NE(constraints.featureVertices.end(),
            std::find(constraints.featureVertices.begin(),
                      constraints.featureVertices.end(), 4));
  ASSERT_EQ(1U, constraints.authoritativeFeatureRails.size());
  EXPECT_EQ((std::vector<int>{1, 4}),
            constraints.authoritativeFeatureRails.front());
}

} // namespace

TEST(MilestoneGP26, ManifestContainsCompletePairedProductionMatrix) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  ASSERT_EQ(20U, cases.size());

  const std::vector<std::string> fixtures = {
      "plane",           "cylinder",     "torus",
      "thin_bent_tube",  "close_sheets", "sphere_prescribed",
      "multi_face_seam", "bunny_1k_random", "vase",
      "mechanical_feature"};
  for (const std::string &fixture : fixtures) {
    const auto &surface = find_case(cases, fixture + "__surface_cells");
    const auto &legacy = find_case(cases, fixture + "__legacy_integer");
    EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
              surface.backend);
    EXPECT_EQ(directional::pipeline::RemeshBackend::LegacyInteger,
              legacy.backend);
    EXPECT_EQ(surface.meshPath, legacy.meshPath);
    EXPECT_EQ(surface.fieldPath, legacy.fieldPath);
    EXPECT_EQ(surface.generatedField, legacy.generatedField);
    EXPECT_TRUE(fs::is_regular_file(surface.meshPath));
    if (surface.fieldPath.empty()) {
      EXPECT_EQ("smooth", surface.generatedField) << fixture;
    } else {
      EXPECT_TRUE(fs::is_regular_file(surface.fieldPath)) << fixture;
    }
  }
}

TEST(MilestoneGP26, ProductionAssetsAndFieldSourcesAreValid) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  int prescribedFieldCases = 0;
  int calculatedFieldCases = 0;
  for (const auto &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
        directional::pipeline::RemeshBackend::SurfaceCells) {
      continue;
    }
    const auto mesh = directional::bench::load_benchmark_mesh(benchmarkCase);
    const auto field = directional::bench::load_benchmark_field(
        benchmarkCase, mesh.faces.rows());
    EXPECT_GT(mesh.vertices.rows(), 0) << benchmarkCase.name;
    EXPECT_GT(mesh.faces.rows(), 0) << benchmarkCase.name;
    EXPECT_EQ(0, mesh.faces.rows() % 2) << benchmarkCase.name;
    if (benchmarkCase.fieldPath.empty()) {
      ++calculatedFieldCases;
      EXPECT_FALSE(field.available) << benchmarkCase.name;
      EXPECT_EQ("smooth", benchmarkCase.generatedField) << benchmarkCase.name;
    } else {
      ++prescribedFieldCases;
      EXPECT_TRUE(field.available) << benchmarkCase.name;
      EXPECT_EQ(mesh.faces.rows(), field.raw.rows()) << benchmarkCase.name;
      EXPECT_EQ(12, field.raw.cols()) << benchmarkCase.name;
    }
  }
  EXPECT_EQ(8, prescribedFieldCases);
  EXPECT_EQ(2, calculatedFieldCases);
}

TEST(MilestoneGP26, ProductionFieldFilesFinalizeAuthoritatively) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  int finalizedCases = 0;
  for (const auto &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
            directional::pipeline::RemeshBackend::SurfaceCells ||
        benchmarkCase.fieldPath.empty()) {
      continue;
    }
    ++finalizedCases;
    const auto meshData =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const auto fieldData = directional::bench::load_benchmark_field(
        benchmarkCase, meshData.faces.rows());
    ASSERT_TRUE(fieldData.available) << benchmarkCase.name;
    directional::TriMesh mesh;
    mesh.set_mesh(meshData.vertices, meshData.faces);

    const directional::fields::CrossFieldResult field =
        directional::pipeline::finalize_surface_cell_raw_cross_field(
            mesh, fieldData.raw);
    EXPECT_TRUE(field.matchingComputed) << benchmarkCase.name;
    EXPECT_TRUE(field.singularitiesComputed) << benchmarkCase.name;
    EXPECT_EQ(mesh.EF.rows(), field.matching.size()) << benchmarkCase.name;
    EXPECT_EQ(mesh.EF.rows(), field.effort.size()) << benchmarkCase.name;
    EXPECT_EQ(static_cast<std::size_t>(mesh.EF.rows()),
              field.edgeTransitions.size())
        << benchmarkCase.name;
  }
  EXPECT_EQ(8, finalizedCases);
}

TEST(MilestoneGP26,
     UniqueFieldAlignedRecoveryAcceptsEveryPrescribedFieldFixture) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  int recoveredCases = 0;
  for (const auto &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
            directional::pipeline::RemeshBackend::SurfaceCells ||
        benchmarkCase.fieldPath.empty()) {
      continue;
    }
    ++recoveredCases;
    const auto meshData =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const auto fieldData = directional::bench::load_benchmark_field(
        benchmarkCase, meshData.faces.rows());
    ASSERT_TRUE(fieldData.available) << benchmarkCase.name;
    directional::TriMesh mesh;
    mesh.set_mesh(meshData.vertices, meshData.faces);

    const auto sourceAuthority = recovery_source_authority(mesh.F);
    const auto first =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData), &sourceAuthority,
            &no_recovery_excluded_edges());
    const auto second =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData), &sourceAuthority,
            &no_recovery_excluded_edges());
    ASSERT_TRUE(first.success) << benchmarkCase.name << ": " << first.failure;
    ASSERT_TRUE(second.success) << benchmarkCase.name << ": " << second.failure;
    EXPECT_GT(first.mesh.quads.size(),
              static_cast<std::size_t>(meshData.faces.rows() / 2))
        << benchmarkCase.name;
    EXPECT_TRUE(std::all_of(first.mesh.quads.begin(), first.mesh.quads.end(),
                            [](const auto &quad) { return quad.size() == 4U; }))
        << benchmarkCase.name;
    EXPECT_GT(first.mesh.vertices.size(),
              static_cast<std::size_t>(meshData.vertices.rows()))
        << benchmarkCase.name;
    EXPECT_FALSE(
        directional::geometry::output_is_only_paired_source_triangle_boundaries(
            first.mesh, meshData.faces))
        << benchmarkCase.name;
    EXPECT_EQ(first.mesh.quads, second.mesh.quads) << benchmarkCase.name;
    EXPECT_EQ(
        directional::geometry::PureQuadCompletionBackend::SourceGridRecovery,
        first.mesh.backend);
    EXPECT_FALSE(first.mesh.usesCenterFan);
    ASSERT_EQ(first.mesh.vertexLineage.size(),
              first.mesh.vertexProvenance.size());
    ASSERT_EQ(first.mesh.quadLineage.size(), first.mesh.quads.size());
    EXPECT_TRUE(std::all_of(
        first.mesh.vertexLineage.begin(), first.mesh.vertexLineage.end(),
        [](const auto &lineage) { return lineage.valid(); }));
    EXPECT_TRUE(std::all_of(
        first.mesh.quadLineage.begin(), first.mesh.quadLineage.end(),
        [](const auto &lineage) { return lineage.valid(); }));
  }
  EXPECT_EQ(8, recoveredCases);
}

TEST(MilestoneGP26, SourceCellRecoveryFailsClosedForIncompleteField) {
  directional::TriMesh mesh;
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  mesh.set_mesh(vertices, faces);

  // Supply only one field row for two source faces. Field alignment is a soft
  // source-cell cost on arbitrary triangulations, so a valid two-triangle
  // square is not an incomplete recovery scenario. Missing authoritative face
  // data is, and must fail before any topology is emitted.
  const double inverseSqrtTwo = 1.0 / std::sqrt(2.0);
  directional::fields::CrossFieldResult field;
  field.rawField = Eigen::MatrixXd::Zero(1, 12);
  for (Eigen::Index face = 0; face < field.rawField.rows(); ++face) {
    field.rawField.row(face) << inverseSqrtTwo, inverseSqrtTwo, 0.0,
        -inverseSqrtTwo, inverseSqrtTwo, 0.0, -inverseSqrtTwo, -inverseSqrtTwo,
        0.0, inverseSqrtTwo, -inverseSqrtTwo, 0.0;
  }
  directional::pipeline::normalize_surface_cell_cross_field_directions(field);

  const auto sourceAuthority = recovery_source_authority(mesh.F);
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, field, &sourceAuthority, &no_recovery_excluded_edges());
  EXPECT_FALSE(recovery.success);
  EXPECT_EQ("InvalidSourceGridInput", recovery.failure);
  EXPECT_TRUE(recovery.mesh.quads.empty());
}

TEST(MilestoneGP26, GeneralMatchingContractsOddCyclesDeterministically) {
  using directional::geometry::GeneralGraphMatchingEdge;
  const std::vector<GeneralGraphMatchingEdge> edges = {
      {0, 1, 0.0}, {1, 2, 0.0}, {2, 0, 0.0},
      {0, 3, 1.0}, {1, 4, 1.0}, {2, 5, 1.0}};

  const auto first =
      directional::geometry::maximum_cardinality_matching(6, edges);
  const auto second =
      directional::geometry::maximum_cardinality_matching(6, edges);

  ASSERT_TRUE(first.perfect());
  EXPECT_EQ(first.mate, second.mate);
  for (int vertex = 0; vertex < 6; ++vertex) {
    ASSERT_GE(first.mate[static_cast<std::size_t>(vertex)], 0);
    EXPECT_EQ(vertex,
              first.mate[static_cast<std::size_t>(
                  first.mate[static_cast<std::size_t>(vertex)])]);
  }
}

TEST(MilestoneGP26, GeneralMatchingReportsMaximumWhenPerfectIsImpossible) {
  using directional::geometry::GeneralGraphMatchingEdge;
  const std::vector<GeneralGraphMatchingEdge> edges = {
      {0, 1, 0.0}, {1, 2, 0.0}, {2, 0, 0.0}};
  const auto result =
      directional::geometry::maximum_cardinality_matching(3, edges);
  EXPECT_FALSE(result.perfect());
  EXPECT_EQ(1, result.matchedEdgeCount);
  EXPECT_EQ(1, std::count(result.mate.begin(), result.mate.end(), -1));
}

TEST(MilestoneGP26, GeneralMatchingMatchesExhaustiveSmallGraphOracle) {
  using directional::geometry::GeneralGraphMatchingEdge;
  for (int vertexCount = 1; vertexCount <= 6; ++vertexCount) {
    std::vector<std::pair<int, int>> possibleEdges;
    for (int first = 0; first < vertexCount; ++first) {
      for (int second = first + 1; second < vertexCount; ++second) {
        possibleEdges.emplace_back(first, second);
      }
    }
    const std::uint32_t graphCount =
        std::uint32_t{1} << possibleEdges.size();
    for (std::uint32_t graph = 0; graph < graphCount; ++graph) {
      std::vector<GeneralGraphMatchingEdge> edges;
      std::vector<std::vector<unsigned char>> adjacent(
          static_cast<std::size_t>(vertexCount),
          std::vector<unsigned char>(static_cast<std::size_t>(vertexCount),
                                     0));
      for (std::size_t edge = 0; edge < possibleEdges.size(); ++edge) {
        if ((graph & (std::uint32_t{1} << edge)) == 0U) {
          continue;
        }
        const auto [first, second] = possibleEdges[edge];
        edges.push_back(
            {first, second, static_cast<double>(possibleEdges.size() - edge)});
        adjacent[static_cast<std::size_t>(first)]
                [static_cast<std::size_t>(second)] = 1;
        adjacent[static_cast<std::size_t>(second)]
                [static_cast<std::size_t>(first)] = 1;
      }
      const auto matching =
          directional::geometry::maximum_cardinality_matching(vertexCount,
                                                               edges);
      const int expected = brute_force_matching_cardinality(
          vertexCount, adjacent,
          (std::uint32_t{1} << vertexCount) - std::uint32_t{1});
      ASSERT_EQ(expected, matching.matchedEdgeCount)
          << "vertices=" << vertexCount << " graph=" << graph;
      ASSERT_EQ(static_cast<std::size_t>(vertexCount), matching.mate.size());
      for (int vertex = 0; vertex < vertexCount; ++vertex) {
        const int mate = matching.mate[static_cast<std::size_t>(vertex)];
        if (mate < 0) {
          continue;
        }
        ASSERT_LT(mate, vertexCount);
        EXPECT_EQ(vertex, matching.mate[static_cast<std::size_t>(mate)]);
        EXPECT_NE(0U, adjacent[static_cast<std::size_t>(vertex)]
                              [static_cast<std::size_t>(mate)]);
      }
    }
  }
}

TEST(MilestoneGP26, RecoveryPreservesComponentAndSheetProvenance) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  const auto &benchmarkCase = find_case(cases, "plane__surface_cells");
  const auto meshData = directional::bench::load_benchmark_mesh(benchmarkCase);
  const auto fieldData = directional::bench::load_benchmark_field(
      benchmarkCase, meshData.faces.rows());
  directional::TriMesh mesh;
  mesh.set_mesh(meshData.vertices, meshData.faces);
  const std::vector<int> components(
      static_cast<std::size_t>(meshData.faces.rows()), 7);
  const std::vector<int> sheets(static_cast<std::size_t>(meshData.faces.rows()),
                                11);

  const auto sourceAuthority =
      recovery_source_authority(mesh.F, components, sheets);
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData), &sourceAuthority,
          &no_recovery_excluded_edges());
  ASSERT_TRUE(recovery.success) << recovery.failure;
  ASSERT_FALSE(recovery.mesh.vertexProvenance.empty());
  for (const auto &point : recovery.mesh.vertexProvenance) {
    EXPECT_EQ(7, point.component);
    EXPECT_EQ(11, point.sheet);
  }
}

TEST(MilestoneGP26, PrescribedSphereSingularitiesMatchRecoveredValence) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  const auto &benchmarkCase =
      find_case(cases, "sphere_prescribed__surface_cells");
  const auto meshData = directional::bench::load_benchmark_mesh(benchmarkCase);
  const auto fieldData = directional::bench::load_benchmark_field(
      benchmarkCase, meshData.faces.rows());
  directional::TriMesh mesh;
  mesh.set_mesh(meshData.vertices, meshData.faces);
  const auto sourceAuthority = recovery_source_authority(mesh.F);
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData), &sourceAuthority,
          &no_recovery_excluded_edges());
  ASSERT_TRUE(recovery.success) << recovery.failure;

  const fs::path metadata = source_root() / "benchmarks" / "fixtures" /
                            "milestone-g" / "sphere_prescribed.fieldmeta.json";
  const std::vector<int> singularVertices =
      json_integer_array(metadata, "singular_vertices");
  const std::vector<int> singularIndices =
      json_integer_array(metadata, "singular_indices");
  ASSERT_EQ(8U, singularVertices.size());
  ASSERT_EQ(singularVertices.size(), singularIndices.size());
  EXPECT_EQ(8,
            std::accumulate(singularIndices.begin(), singularIndices.end(), 0));

  std::vector<int> valence(recovery.mesh.vertices.size(), 0);
  for (const auto &quad : recovery.mesh.quads) {
    for (const int vertex : quad) {
      ++valence[static_cast<std::size_t>(vertex)];
    }
  }
  for (std::size_t index = 0; index < singularVertices.size(); ++index) {
    const int vertex = singularVertices[index];
    ASSERT_GE(vertex, 0);
    ASSERT_LT(static_cast<std::size_t>(vertex), valence.size());
    EXPECT_EQ(4 - singularIndices[index],
              valence[static_cast<std::size_t>(vertex)]);
  }
}

TEST(MilestoneGP26, ProductionMatrixTerminatesWithoutHiddenFallback) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  for (const auto &benchmarkCase : cases) {
    if (benchmarkCase.backend ==
        directional::pipeline::RemeshBackend::SurfaceCells) {
      SCOPED_TRACE(::testing::Message()
                   << "P26 surface-cell matrix case=" << benchmarkCase.name);
      std::cerr << "[P5_P26_CASE_BEGIN] " << benchmarkCase.name
                << std::endl;
      expect_truthful_surface_cells_outcome(benchmarkCase);
      std::cerr << "[P5_P26_CASE_END] " << benchmarkCase.name
                << std::endl;
    }
  }
}

TEST(MilestoneGP26, PlaneAndMechanicalFixturesCompleteEndToEnd) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  expect_completed_surface_cells(find_case(cases, "plane__surface_cells"),
                                 true);
  expect_completed_surface_cells(
      find_case(cases, "mechanical_feature__surface_cells"), false);
}

TEST(MilestoneGP26, CylinderCompletesEndToEnd) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  expect_completed_surface_cells(find_case(cases, "cylinder__surface_cells"),
                                 true);
}

TEST(MilestoneGP26, MultiFaceSeamCompletesEndToEnd) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  expect_completed_surface_cells(
      find_case(cases, "multi_face_seam__surface_cells"), true);
}

TEST(MilestoneGP26, TorusCompletesEndToEnd) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  expect_completed_surface_cells(find_case(cases, "torus__surface_cells"),
                                 false);
}
