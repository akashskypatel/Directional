#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <numeric>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "BenchmarkCases.h"

namespace {

namespace fs = std::filesystem;

fs::path source_root() { return fs::path(DIRECTIONAL_TEST_SOURCE_DIR); }

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
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);

  ASSERT_TRUE(result.success)
      << benchmarkCase.name << ": " << result.diagnostics.terminalFailureCode
      << "/" << result.diagnostics.terminalFailureStage
      << " component=" << result.diagnostics.failedComponentIndex
      << " validationFailures="
      << result.diagnostics.surfaceCellValidationFailures << " topology="
      << result.surfaceCellContext.validationResult
             .connectedComponentMismatchCount
      << "/"
      << result.surfaceCellContext.validationResult
             .eulerCharacteristicMismatchCount
      << "/"
      << result.surfaceCellContext.validationResult.boundaryCycleMismatchCount
      << " rails="
      << result.surfaceCellContext.validationResult.featureRailMismatchCount
      << " provenance="
      << result.surfaceCellContext.validationResult.provenanceFailureCount
      << " sheets="
      << result.surfaceCellContext.validationResult.localSheetMismatchCount
      << " geometry=" << result.surfaceCellContext.validationResult.degenerate
      << "/" << result.surfaceCellContext.validationResult.inverted << "/"
      << result.surfaceCellContext.validationResult.selfIntersecting
      << " manifold(t/nonmanifold/nonconvex)="
      << result.surfaceCellContext.validationResult.tJunctions << "/"
      << result.surfaceCellContext.validationResult.nonManifold << "/"
      << result.surfaceCellContext.validationResult.nonConvex
      << " valence(boundary/singularity)="
      << result.surfaceCellContext.validationResult.boundaryValenceMismatchCount
      << "/"
      << result.surfaceCellContext.validationResult
             .requiredSingularityValenceMismatchCount
      << " surface/normal="
      << result.surfaceCellContext.validationResult.quadToSourceP95 << ","
      << result.surfaceCellContext.validationResult.quadToSourceMax << "/"
      << result.surfaceCellContext.validationResult.sourceToOutputP95 << ","
      << result.surfaceCellContext.validationResult.sourceToOutputMax << "/"
      << result.surfaceCellContext.validationResult.normalP95Degrees
      << " quality(size/field/jacobian)="
      << result.surfaceCellContext.validationResult.sizeP5 << ","
      << result.surfaceCellContext.validationResult.sizeP95 << "/"
      << result.surfaceCellContext.validationResult.fieldMedianDegrees << ","
      << result.surfaceCellContext.validationResult.fieldP95Degrees << "/"
      << result.surfaceCellContext.validationResult.scaledJacobianMin << ","
      << result.surfaceCellContext.validationResult.scaledJacobianP5
      << " optimizer(iterations/rollback/line-search/"
         "hard/orientation)="
      << result.surfaceCellContext.optimizationResult.iterations.size() << "/"
      << result.surfaceCellContext.optimizationResult.rolledBackToInput << "/"
      << result.surfaceCellContext.optimizationResult.lineSearchRejectionCount
      << "/"
      << result.surfaceCellContext.optimizationResult
             .hardInvariantRejectionCount
      << "/"
      << result.surfaceCellContext.optimizationResult.orientationRejectionCount
      << " energy(size/field)="
      << result.surfaceCellContext.optimizationResult.initialEnergy.size << ","
      << result.surfaceCellContext.optimizationResult.finalEnergy.size << "/"
      << result.surfaceCellContext.optimizationResult.initialEnergy.field << ","
      << result.surfaceCellContext.optimizationResult.finalEnergy.field;
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  if (expectSourceGridRecovery) {
    EXPECT_TRUE(result.diagnostics.surfaceCellSourceGridRecoveryUsed);
    EXPECT_TRUE(result.surfaceCellContext.sourceGridRecoveryUsed);
    EXPECT_TRUE(result.surfaceCellContext.hasSourceGridRecoveryTargetSize);
    EXPECT_GT(result.surfaceCellContext.sourceGridRecoveryTargetSize.size(), 0);
    EXPECT_LE(result.diagnostics
                  .surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio,
              options.surfaceCells.maxSourceGridRecoveryTargetRelaxation);
    EXPECT_EQ(2 * mesh.faces.rows(),
              static_cast<Eigen::Index>(result.faces.rows()));
    EXPECT_GT(result.vertices.rows(), mesh.vertices.rows());
  } else {
    EXPECT_GT(result.faces.rows(), 0);
  }
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  ASSERT_EQ(result.faces.rows(), result.degrees.size());
  for (Eigen::Index face = 0; face < result.degrees.size(); ++face) {
    EXPECT_EQ(4, result.degrees(face));
  }
  EXPECT_EQ(static_cast<std::size_t>(result.vertices.rows()),
            result.outputVertexProvenance.size());
  EXPECT_EQ(static_cast<std::size_t>(result.faces.rows()),
            result.outputQuadLineage.size());
  EXPECT_TRUE(result.surfaceCellContext.hasValidationResult);
  EXPECT_TRUE(result.surfaceCellContext.validationResult.accepted);
}

void expect_truthful_surface_cells_outcome(
    const directional::bench::BenchmarkCase &benchmarkCase) {
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
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);

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

  if (result.success) {
    EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred)
        << benchmarkCase.name;
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::CompletedSurfaceCells,
              result.diagnostics.surfaceCellOutputOrigin)
        << benchmarkCase.name;
    EXPECT_EQ("None", result.diagnostics.terminalFailureCode)
        << benchmarkCase.name;
    EXPECT_TRUE(result.diagnostics.terminalFailureStage.empty())
        << benchmarkCase.name;
    ASSERT_EQ(result.faces.rows(), result.degrees.size()) << benchmarkCase.name;
    EXPECT_TRUE((result.degrees.array() == 4).all()) << benchmarkCase.name;
    EXPECT_TRUE(result.surfaceCellContext.hasValidationResult)
        << benchmarkCase.name;
    EXPECT_TRUE(result.surfaceCellContext.validationResult.accepted)
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
    EXPECT_EQ(0, result.vertices.rows()) << benchmarkCase.name;
    EXPECT_EQ(0, result.faces.rows()) << benchmarkCase.name;
  }
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
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData));
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
    const auto recovery =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData));
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

  directional::geometry::SurfaceCellRail rail;
  rail.id = 9;
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
  ASSERT_EQ(18U, cases.size());

  const std::vector<std::string> fixtures = {
      "plane",           "cylinder",     "torus",
      "thin_bent_tube",  "close_sheets", "sphere_prescribed",
      "multi_face_seam", "bunny1k",      "mechanical_feature"};
  for (const std::string &fixture : fixtures) {
    const auto &surface = find_case(cases, fixture + "__surface_cells");
    const auto &legacy = find_case(cases, fixture + "__legacy_integer");
    EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
              surface.backend);
    EXPECT_EQ(directional::pipeline::RemeshBackend::LegacyInteger,
              legacy.backend);
    EXPECT_EQ(surface.meshPath, legacy.meshPath);
    EXPECT_EQ(surface.fieldPath, legacy.fieldPath);
    EXPECT_TRUE(fs::is_regular_file(surface.meshPath));
    EXPECT_TRUE(fs::is_regular_file(surface.fieldPath));
  }
}

TEST(MilestoneGP26, ProductionAssetsAndFieldsLoadWithMatchingFaceCounts) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
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
    EXPECT_TRUE(field.available) << benchmarkCase.name;
    EXPECT_EQ(mesh.faces.rows(), field.raw.rows()) << benchmarkCase.name;
    EXPECT_EQ(12, field.raw.cols()) << benchmarkCase.name;
  }
}

TEST(MilestoneGP26, ProductionFieldFilesFinalizeAuthoritatively) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  for (const auto &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
        directional::pipeline::RemeshBackend::SurfaceCells) {
      continue;
    }
    const auto meshData =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const auto fieldData = directional::bench::load_benchmark_field(
        benchmarkCase, meshData.faces.rows());
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
}

TEST(MilestoneGP26, UniqueFieldAlignedRecoveryAcceptsEveryProductionFixture) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  for (const auto &benchmarkCase : cases) {
    if (benchmarkCase.backend !=
        directional::pipeline::RemeshBackend::SurfaceCells) {
      continue;
    }
    const auto meshData =
        directional::bench::load_benchmark_mesh(benchmarkCase);
    const auto fieldData = directional::bench::load_benchmark_field(
        benchmarkCase, meshData.faces.rows());
    directional::TriMesh mesh;
    mesh.set_mesh(meshData.vertices, meshData.faces);

    const auto first =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData));
    const auto second =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData));
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
}

TEST(MilestoneGP26, SourceCellRecoveryFailsClosedForIncompleteInput) {
  directional::TriMesh mesh;
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  mesh.set_mesh(vertices, faces);

  // Align one cross branch with the shared diagonal. The only possible
  // triangle pair is therefore explicitly rejected as a source-cell
  // candidate, leaving an incomplete candidate graph that must fail closed.
  const double inverseSqrtTwo = 1.0 / std::sqrt(2.0);
  directional::fields::CrossFieldResult field;
  field.rawField = Eigen::MatrixXd::Zero(2, 12);
  for (Eigen::Index face = 0; face < field.rawField.rows(); ++face) {
    field.rawField.row(face) << inverseSqrtTwo, inverseSqrtTwo, 0.0,
        -inverseSqrtTwo, inverseSqrtTwo, 0.0, -inverseSqrtTwo, -inverseSqrtTwo,
        0.0, inverseSqrtTwo, -inverseSqrtTwo, 0.0;
  }
  directional::pipeline::normalize_surface_cell_cross_field_directions(field);

  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(mesh,
                                                                       field);
  EXPECT_FALSE(recovery.success);
  EXPECT_EQ("AmbiguousOrIncompleteSourceGrid", recovery.failure);
  EXPECT_TRUE(recovery.mesh.quads.empty());
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

  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData), &components, &sheets);
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
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData));
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
      expect_truthful_surface_cells_outcome(benchmarkCase);
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
