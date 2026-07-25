#include <algorithm>
#include <cmath>
#include <filesystem>
#include <numbers>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/fields/CrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

#include "BenchmarkCases.h"

namespace {

struct SyntheticMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

SyntheticMesh make_two_square_components() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0, 3.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0, 3.0, 1.0,
      0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
  return mesh;
}


SyntheticMesh make_open_cylinder(const int segments = 24,
                                 const int rings = 3,
                                 const double radius = 2.0,
                                 const double height = 1.0) {
  SyntheticMesh mesh;
  mesh.vertices.resize(segments * rings, 3);
  for (int ring = 0; ring < rings; ++ring) {
    const double z = -0.5 * height +
                     height * static_cast<double>(ring) /
                         static_cast<double>(rings - 1);
    for (int segment = 0; segment < segments; ++segment) {
      const double angle = 2.0 * std::numbers::pi *
                           static_cast<double>(segment) /
                           static_cast<double>(segments);
      mesh.vertices.row(ring * segments + segment) <<
          radius * std::cos(angle), radius * std::sin(angle), z;
    }
  }

  mesh.faces.resize((rings - 1) * segments * 2, 3);
  int face = 0;
  for (int ring = 0; ring < rings - 1; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const int next = (segment + 1) % segments;
      const int a = ring * segments + segment;
      const int b = ring * segments + next;
      const int c = (ring + 1) * segments + segment;
      const int d = (ring + 1) * segments + next;
      mesh.faces.row(face++) << a, b, d;
      mesh.faces.row(face++) << a, d, c;
    }
  }
  return mesh;
}

SyntheticMesh make_two_square_strip() {
  SyntheticMesh mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 0.75, 0.0, 0.0, 1.5, 0.0, 0.0,
      0.0, 0.75, 0.0, 0.75, 0.75, 0.0, 1.5, 0.75, 0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  return mesh;
}

SyntheticMesh make_planar_grid(const int subdivisions = 2) {
  const int n = std::max(1, subdivisions);
  SyntheticMesh mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices(vertex, 0) = static_cast<double>(x) / n;
      mesh.vertices(vertex, 1) = static_cast<double>(y) / n;
      mesh.vertices(vertex, 2) = 0.0;
    }
  }
  mesh.faces.resize(2 * n * n, 3);
  int face = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int v00 = y * (n + 1) + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * (n + 1) + x;
      const int v11 = v01 + 1;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

SyntheticMesh make_close_parallel_sheets() {
  SyntheticMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0, 0.0, 0.0, 0.02, 1.0, 0.0, 0.02, 1.0, 1.0,
      0.02, 0.0, 1.0, 0.02;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
  return mesh;
}
Eigen::MatrixXd constant_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.block(face, 0, 1, 3) << 1.0, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, 1.0, 0.0;
    raw.block(face, 6, 1, 3) << -1.0, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -1.0, 0.0;
  }
  return raw;
}


Eigen::MatrixXd cylinder_raw_field(const SyntheticMesh &mesh) {
  Eigen::MatrixXd raw(mesh.faces.rows(), 12);
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      centroid += mesh.vertices.row(mesh.faces(face, corner)) / 3.0;
    }
    Eigen::RowVector3d circumferential{-centroid.y(), centroid.x(), 0.0};
    if (circumferential.norm() <= 1.0e-12) {
      circumferential = {1.0, 0.0, 0.0};
    } else {
      circumferential.normalize();
    }
    const Eigen::RowVector3d axial{0.0, 0.0, 1.0};
    raw.block(face, 0, 1, 3) = circumferential;
    raw.block(face, 3, 1, 3) = axial;
    raw.block(face, 6, 1, 3) = -circumferential;
    raw.block(face, 9, 1, 3) = -axial;
  }
  return raw;
}
directional::pipeline::RemeshOptions surface_options() {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.requireMatching = false;
  options.surfaceCells.requireSingularities = false;
  return options;
}

std::string signature(const directional::pipeline::RemeshResult &result) {
  return result.diagnostics.requestedBackend + "/" +
         result.diagnostics.executedBackend + "/" +
         result.diagnostics.terminalFailureCode + "/" +
         std::to_string(result.vertices.rows()) + "/" +
         std::to_string(result.faces.rows()) + "/" +
         std::to_string(result.degrees.sum());
}

} // namespace

TEST(SurfaceCellPipelinePhase20, BackendNamesAndParsersExposeStableApi) {
  using directional::pipeline::RemeshBackend;
  using directional::pipeline::SurfaceCellFallbackPolicy;

  directional::pipeline::RemeshOptions defaults;
  EXPECT_EQ(RemeshBackend::LegacyInteger, defaults.backend);
  EXPECT_EQ("LegacyInteger",
            directional::pipeline::remesh_backend_name(defaults.backend));
  EXPECT_EQ(RemeshBackend::LegacyInteger,
            directional::pipeline::parse_remesh_backend("legacy-integer"));
  EXPECT_EQ(RemeshBackend::SurfaceCells,
            directional::pipeline::parse_remesh_backend("surface_cells"));
  EXPECT_EQ(SurfaceCellFallbackPolicy::ReturnQuadDominant,
            directional::pipeline::parse_surface_cell_fallback_policy(
                "return-quad-dominant"));
  EXPECT_THROW((void)directional::pipeline::parse_remesh_backend("unknown"),
               std::runtime_error);
}

TEST(SurfaceCellPipelinePhase20, InvalidRawFieldDimsReturnPreciseFailureCode) {
  const SyntheticMesh mesh = make_two_square_components();
  Eigen::MatrixXd badRaw(mesh.faces.rows(), 9);
  badRaw.setZero();
  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, badRaw, surface_options());

  EXPECT_FALSE(result.success);
  EXPECT_EQ("SurfaceCells", result.diagnostics.remeshBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.terminalFailureCode);
  EXPECT_EQ("InvalidFieldDimensions",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("input-validation", result.diagnostics.terminalFailureStage);
  EXPECT_EQ("input-validation",
            result.diagnostics.originalSurfaceCellFailureStage);
}

TEST(SurfaceCellPipelinePhase20, CrossFieldResultRequiresMatchingAndSingularities) {
  const SyntheticMesh mesh = make_two_square_components();
  directional::fields::CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.rawField = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.requireMatching = true;
  options.surfaceCells.requireSingularities = true;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_cross_field_result(
          mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingMatching", result.diagnostics.terminalFailureCode);

  field.matching = Eigen::VectorXi::Zero(1);
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_EQ("MissingSingularities", result.diagnostics.terminalFailureCode);

  options.surfaceCells.requireSingularities = false;
  result = directional::pipeline::remesh_from_cross_field_result(
      mesh.vertices, mesh.faces, field, options);
  EXPECT_TRUE(result.success) << "relief=" << result.diagnostics.surfaceCellReliefPatchCount << " trace=" << result.diagnostics.surfaceCellTraceSegmentCount << " arrangement=" << result.diagnostics.surfaceCellArrangementCellCount << " simplified=" << result.diagnostics.surfaceCellSimplifiedCellCount << " completed=" << result.diagnostics.surfaceCellCompletedQuadCount << " opt=" << result.diagnostics.surfaceCellOptimizationIterationCount << " terminal=" << result.diagnostics.terminalFailureCode << ":" << result.diagnostics.terminalFailureStage;
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
}

TEST(SurfaceCellPipelinePhase20, ExplicitFallbackPoliciesAreObservable) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 8;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  EXPECT_FALSE(result.success);
  EXPECT_FALSE(result.diagnostics.surfaceCellFallbackAttempted);

  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.success) << "relief=" << result.diagnostics.surfaceCellReliefPatchCount << " trace=" << result.diagnostics.surfaceCellTraceSegmentCount << " arrangement=" << result.diagnostics.surfaceCellArrangementCellCount << " simplified=" << result.diagnostics.surfaceCellSimplifiedCellCount << " completed=" << result.diagnostics.surfaceCellCompletedQuadCount << " opt=" << result.diagnostics.surfaceCellOptimizationIterationCount << " terminal=" << result.diagnostics.terminalFailureCode << ":" << result.diagnostics.terminalFailureStage;
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellReturnedQuadDominantFallback);
  EXPECT_TRUE(result.diagnostics.surfaceCellReturnedInputMeshFallback);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("InputMesh", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.surfaceCellFallbackCause);
  ASSERT_GT(result.diagnostics.faceDegreeHistogram.size(), 3U);
  EXPECT_EQ(static_cast<std::size_t>(mesh.faces.rows()),
            result.diagnostics.faceDegreeHistogram[3]);
}

TEST(SurfaceCellPipelinePhase20, DebugArtifactsAreRetainedOnlyWhenRequested) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 0;
  directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_FALSE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifacts.empty());

  options.surfaceCells.preserveDebugArtifacts = true;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  ASSERT_EQ(1U, result.diagnostics.surfaceCellDebugArtifacts.size());
  EXPECT_EQ("feature", result.diagnostics.surfaceCellDebugArtifacts[0]);

  options.surfaceCells.injectFailureAfterStage = 1;
  result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  EXPECT_TRUE(result.diagnostics.surfaceCellDebugArtifactsPreserved);
  ASSERT_EQ(2U, result.diagnostics.surfaceCellDebugArtifacts.size());
  EXPECT_EQ("feature", result.diagnostics.surfaceCellDebugArtifacts[0]);
  EXPECT_EQ("metric", result.diagnostics.surfaceCellDebugArtifacts[1]);
}


TEST(SurfaceCellPipelinePhase20, RealStageDiagnosticsAreDerivedFromIntermediates) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_TRUE(result.success);
  EXPECT_EQ("None", result.diagnostics.terminalFailureCode);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(static_cast<std::size_t>(mesh.vertices.rows()),
            result.diagnostics.surfaceCellMetricSampleCount);
  EXPECT_NE(static_cast<std::size_t>(mesh.faces.rows()),
            result.diagnostics.surfaceCellFeatureCount);
  EXPECT_TRUE(result.diagnostics.surfaceCellReliefCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellTraceCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellArrangementCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellSimplifiedCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellCompletedQuadCountAvailable);
  EXPECT_TRUE(result.diagnostics.surfaceCellOptimizationIterationCountAvailable);
  EXPECT_GT(result.diagnostics.surfaceCellReliefPatchCount, 0U);
  EXPECT_GT(result.diagnostics.surfaceCellTraceSegmentCount, 0U);
  EXPECT_EQ(2U, result.diagnostics.surfaceCellCompletedQuadCount);
  ASSERT_EQ(mesh.faces.rows() / 2, result.faces.rows());
  EXPECT_TRUE((result.degrees.array() == 4).all());
  ASSERT_EQ(static_cast<std::size_t>(result.vertices.rows()),
            result.outputVertexProvenance.size());
  for (const directional::geometry::SurfacePoint &point :
       result.outputVertexProvenance) {
    EXPECT_TRUE(point.valid());
  }
}

TEST(SurfaceCellPipelinePhase20, TryLegacyPreservesInjectedSurfaceCellFailureWhenLegacyFails) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 8;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::TryLegacy;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  EXPECT_FALSE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_FALSE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.surfaceCellFallbackCause);
}


TEST(SurfaceCellPipelinePhase20, TryLegacyReportsExecutedBackendWhenLegacySucceeds) {
  const SyntheticMesh mesh = make_planar_grid();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.injectFailureAfterStage = 8;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::TryLegacy;

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options);

  ASSERT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellUsedLegacyFallback);
  EXPECT_EQ("SurfaceCells", result.diagnostics.requestedBackend);
  EXPECT_EQ("LegacyInteger", result.diagnostics.executedBackend);
  EXPECT_EQ("InjectedStageFailure",
            result.diagnostics.originalSurfaceCellFailureCode);
  EXPECT_EQ("optimization",
            result.diagnostics.originalSurfaceCellFailureStage);
  EXPECT_EQ("InjectedStageFailure", result.diagnostics.surfaceCellFallbackCause);
  EXPECT_NE("InjectedStageFailure", result.diagnostics.terminalFailureCode);
}

TEST(SurfaceCellPipelinePhase20, CylinderFixtureProducesPureQuads) {
  const SyntheticMesh mesh = make_open_cylinder();
  const Eigen::MatrixXd raw = cylinder_raw_field(mesh);

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  EXPECT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ("SurfaceCells", result.diagnostics.executedBackend);
  EXPECT_GT(result.faces.rows(), 0);
  ASSERT_EQ(result.faces.rows(), result.degrees.size());
  EXPECT_TRUE((result.degrees.array() == 4).all());
  EXPECT_EQ(static_cast<std::size_t>(result.vertices.rows()),
            result.outputVertexProvenance.size());
  for (const directional::geometry::SurfacePoint &point :
       result.outputVertexProvenance) {
    EXPECT_TRUE(point.valid());
  }
}
TEST(SurfaceCellPipelinePhase20, MultiFaceStripDoesNotDuplicateSourceSeam) {
  const SyntheticMesh mesh = make_two_square_strip();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  ASSERT_TRUE(result.success);
  EXPECT_TRUE(result.diagnostics.surfaceCellRemeshOccurred);
  EXPECT_EQ(mesh.faces.rows() / 2, result.faces.rows());
  EXPECT_EQ(mesh.vertices.rows(), result.vertices.rows());
  int seamEdgeIncidence = 0;
  for (int face = 0; face < result.faces.rows(); ++face) {
    for (int corner = 0; corner < result.faces.cols(); ++corner) {
      const int a = result.faces(face, corner);
      const int b = result.faces(face, (corner + 1) % result.faces.cols());
      if (std::min(a, b) == 1 && std::max(a, b) == 4) {
        ++seamEdgeIncidence;
      }
    }
  }
  EXPECT_EQ(2, seamEdgeIncidence);
}

TEST(SurfaceCellPipelinePhase20, CloseSheetsDoNotLeakSourceProvenance) {
  const SyntheticMesh mesh = make_close_parallel_sheets();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  const directional::pipeline::RemeshResult result =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, surface_options());

  ASSERT_TRUE(result.success);
  ASSERT_EQ(static_cast<std::size_t>(result.vertices.rows()),
            result.outputVertexProvenance.size());
  for (int vertex = 0; vertex < result.vertices.rows(); ++vertex) {
    const double outputZ = result.vertices(vertex, 2);
    const directional::geometry::SurfacePoint &point =
        result.outputVertexProvenance[static_cast<std::size_t>(vertex)];
    ASSERT_TRUE(point.valid());
    EXPECT_NEAR(outputZ, point.position.z(), 1.0e-12);
  }
}

TEST(SurfaceCellPipelinePhase20, InjectedFailuresPreserveLastCompletedStageArtifacts) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  const std::vector<std::string> stages = {"feature", "metric", "relief",
                                           "tracing", "strands", "arrangement",
                                           "simplification", "completion",
                                           "optimization"};

  for (int stage = 0; stage < static_cast<int>(stages.size()); ++stage) {
    directional::pipeline::RemeshOptions options = surface_options();
    options.surfaceCells.preserveDebugArtifacts = true;
    options.surfaceCells.injectFailureAfterStage = stage;
    const directional::pipeline::RemeshResult result =
        directional::pipeline::remesh_from_raw_cross_field(
            mesh.vertices, mesh.faces, raw, options);

    EXPECT_FALSE(result.success) << stage;
    EXPECT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode)
        << stage;
    EXPECT_EQ(stages[static_cast<std::size_t>(stage)],
              result.diagnostics.terminalFailureStage)
        << stage;
    ASSERT_EQ(static_cast<std::size_t>(stage + 1),
              result.diagnostics.surfaceCellDebugArtifacts.size())
        << stage;
    for (int i = 0; i <= stage; ++i) {
      EXPECT_EQ(stages[static_cast<std::size_t>(i)],
                result.diagnostics.surfaceCellDebugArtifacts[static_cast<std::size_t>(i)])
          << stage;
    }
  }
}

TEST(SurfaceCellPipelinePhase20, ComponentSchedulingAppliesToSurfaceCells) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions sequential = surface_options();
  sequential.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;
  const directional::pipeline::RemeshResult sequentialResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, sequential);

  directional::pipeline::RemeshOptions parallel = sequential;
  parallel.parallelizeComponents = true;
  parallel.maxComponentThreads = 2;
  const directional::pipeline::RemeshResult parallelResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, parallel);

  EXPECT_TRUE(sequentialResult.success);
  EXPECT_TRUE(parallelResult.success);
  EXPECT_EQ(signature(sequentialResult), signature(parallelResult));
  EXPECT_EQ(2U, parallelResult.diagnostics.componentCount);
}

TEST(SurfaceCellPipelinePhase20, SurfaceCellFallbackIsDeterministic) {
  const SyntheticMesh mesh = make_two_square_components();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnQuadDominant;

  const std::string expected = signature(
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, options));
  for (int run = 0; run < 10; ++run) {
    EXPECT_EQ(expected, signature(
                            directional::pipeline::remesh_from_raw_cross_field(
                                mesh.vertices, mesh.faces, raw, options)));
  }
}

TEST(SurfaceCellPipelinePhase20, BenchmarkManifestDispatchesBackends) {
  const std::filesystem::path manifestPath =
      std::filesystem::path(DIRECTIONAL_TEST_SOURCE_DIR) /
      "benchmarks/fixtures/manifest.example.json";
  const std::vector<directional::bench::BenchmarkCase> cases =
      directional::bench::load_benchmark_manifest(manifestPath);

  const auto surfaceCase = std::find_if(
      cases.begin(), cases.end(),
      [](const directional::bench::BenchmarkCase &candidate) {
        return candidate.name == "fertility_surface_cells_skeleton_hints";
      });
  ASSERT_NE(cases.end(), surfaceCase);
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            surfaceCase->backend);
  EXPECT_TRUE(surfaceCase->surfaceCellSkeletonHints);

  const directional::pipeline::RemeshOptions options =
      directional::bench::make_remesh_options(*surfaceCase);
  EXPECT_EQ(directional::pipeline::RemeshBackend::SurfaceCells,
            options.backend);
  EXPECT_TRUE(options.surfaceCells.enabled);
  EXPECT_TRUE(options.surfaceCells.useSkeletonHints);
}
