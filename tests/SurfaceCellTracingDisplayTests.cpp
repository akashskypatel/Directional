#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/SurfaceCellTracingDisplay.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <fstream>
#include <stdexcept>
#include <string>

namespace {

directional::pipeline::RemeshOptions surface_cell_options(const int stopAfterStage) {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.injectFailureAfterStage = stopAfterStage;
  options.parallelizeComponents = false;
  return options;
}

struct FixtureRun {
  directional::TriMesh mesh;
  directional::pipeline::RemeshResult result;
};

FixtureRun run_fixture(const std::string &name) {
  FixtureRun run;
  const auto stem = directional::tests::benchmark_fixture_path("milestone-g/" + name);
  if (!directional::readOBJ(stem.string() + ".obj", run.mesh)) {
    throw std::runtime_error("Failed to read fixture " + name);
  }
  std::ifstream stream(stem.string() + ".rawfield");
  int degree = 0;
  int faces = 0;
  if (!(stream >> degree >> faces) || degree != 4 || faces != run.mesh.F.rows()) {
    throw std::runtime_error("Invalid rawfield for " + name);
  }
  Eigen::MatrixXd raw(faces, 12);
  for (int face = 0; face < faces; ++face) {
    for (int column = 0; column < 12; ++column) stream >> raw(face, column);
  }
  run.result = directional::pipeline::remesh_from_raw_cross_field(
      run.mesh.V, run.mesh.F, raw, surface_cell_options(-1));
  return run;
}

directional::visualization::SurfaceCellTracingDisplay display_of(const FixtureRun &run) {
  const auto &context = run.result.surfaceCellContext;
  return directional::visualization::surface_cell_tracing_display(
      run.mesh.V, run.mesh.F, run.result.diagnostics,
      context.hasTraceNetwork ? &context.productSnapshots.traceNetwork : nullptr);
}

bool has_face(const directional::visualization::SurfaceCellTracingDisplay &display,
              const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
              const Eigen::Index row) {
  for (Eigen::Index face = 0; face < display.stopFaces.rows(); ++face) {
    bool same = true;
    for (int corner = 0; corner < 3; ++corner) {
      same = same && display.stopFaceVertices.row(display.stopFaces(face, corner)) ==
                         V.row(F(row, corner));
    }
    if (same) return true;
  }
  return false;
}

bool has_vertex(const directional::visualization::SurfaceCellTracingDisplay &display,
                const Eigen::RowVector3d &point) {
  for (Eigen::Index row = 0; row < display.stopVertices.rows(); ++row) {
    if (display.stopVertices.row(row) == point) return true;
  }
  return false;
}

} // namespace

TEST(SurfaceCellTracingDisplay, StopLocationShowsWhatEachStageReported) {
  // Quad tracing (A4) rejects genus_two at a face.
  const FixtureRun genus = run_fixture("genus_two");
  const auto *failure =
      genus.result.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.rejection();
  ASSERT_NE(nullptr, failure) << genus.result.diagnostics.terminalFailureStage;
  ASSERT_GE(failure->face, 0);
  const auto genusDisplay = display_of(genus);
  EXPECT_TRUE(has_face(genusDisplay, genus.mesh.V, genus.mesh.F, failure->face));
  const std::string reason =
      directional::geometry::surface_phase_front_failure_reason_name(failure->reason);
  EXPECT_TRUE(std::any_of(genusDisplay.stopNotes.begin(), genusDisplay.stopNotes.end(),
                          [&](const std::string &note) {
                            return note.find(reason) != std::string::npos;
                          }));

  // The field-transport atlas rejects mechanical_feature at a vertex.
  const FixtureRun mechanical = run_fixture("mechanical_feature");
  const auto &vertexLocus = mechanical.result.diagnostics.terminalFailureLocus;
  ASSERT_TRUE(vertexLocus.sourceVertex.has_value())
      << mechanical.result.diagnostics.terminalFailureStage;
  const auto mechanicalDisplay = display_of(mechanical);
  EXPECT_TRUE(has_vertex(mechanicalDisplay,
                         mechanical.mesh.V.row(static_cast<Eigen::Index>(
                             *vertexLocus.sourceVertex))));

  // The cut graph rejects sphere_prescribed at a face given by its corners.
  const FixtureRun sphere = run_fixture("sphere_prescribed");
  const auto &faceLocus = sphere.result.diagnostics.terminalFailureLocus;
  ASSERT_TRUE(faceLocus.sourceFace.has_value())
      << sphere.result.diagnostics.terminalFailureStage;
  std::array<std::size_t, 3> corners = *faceLocus.sourceFace;
  std::sort(corners.begin(), corners.end());
  Eigen::Index row = -1;
  for (Eigen::Index face = 0; face < sphere.mesh.F.rows(); ++face) {
    std::array<std::size_t, 3> key{static_cast<std::size_t>(sphere.mesh.F(face, 0)),
                                   static_cast<std::size_t>(sphere.mesh.F(face, 1)),
                                   static_cast<std::size_t>(sphere.mesh.F(face, 2))};
    std::sort(key.begin(), key.end());
    if (key == corners) row = face;
  }
  ASSERT_GE(row, 0);
  const auto sphereDisplay = display_of(sphere);
  EXPECT_TRUE(has_face(sphereDisplay, sphere.mesh.V, sphere.mesh.F, row));
  for (const auto *display : {&genusDisplay, &mechanicalDisplay, &sphereDisplay}) {
    EXPECT_TRUE(display->has_stop_location());
    EXPECT_EQ(0U, display->cellCount);
  }
}

TEST(SurfaceCellTracingDisplay, RequestedStopShowsTracedCells) {
  // A flat 2 x 2 square grid with a constant cross field traces quickly.
  Eigen::MatrixXd V(9, 3);
  for (int y = 0, vertex = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) V.row(vertex++) << x, y, 0.0;
  }
  Eigen::MatrixXi F(8, 3);
  for (int y = 0, face = 0; y < 2; ++y) {
    for (int x = 0; x < 2; ++x) {
      const int lowerLeft = 3 * y + x;
      F.row(face++) << lowerLeft, lowerLeft + 1, lowerLeft + 4;
      F.row(face++) << lowerLeft, lowerLeft + 4, lowerLeft + 3;
    }
  }
  Eigen::MatrixXd raw(F.rows(), 12);
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    raw.row(face) << 1, 0, 0, 0, 1, 0, -1, 0, 0, 0, -1, 0;
  }
  auto options = surface_cell_options(3);
  options.lengthRatio = 0.2;
  const auto result =
      directional::pipeline::remesh_from_raw_cross_field(V, F, raw, options);
  ASSERT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode)
      << result.diagnostics.terminalFailureStage;
  const auto &network = result.surfaceCellContext.productSnapshots.traceNetwork;
  const auto *product = network.phaseFront.produced_product();
  ASSERT_NE(nullptr, product);

  const auto display = directional::visualization::surface_cell_tracing_display(
      V, F, result.diagnostics, &network);
  EXPECT_FALSE(display.has_stop_location());  // a requested stop names no place
  EXPECT_EQ(product->cells().size(), display.cellCount);
  ASSERT_GT(display.cellCount, 0U);

  // Independent reconstruction of every boundary segment, in cell order.
  Eigen::Index row = 0;
  for (const auto &cell : product->cells()) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        ASSERT_LT(row, display.cellEdges.rows());
        Eigen::RowVector3d start = Eigen::RowVector3d::Zero();
        Eigen::RowVector3d end = Eigen::RowVector3d::Zero();
        for (int corner = 0; corner < 3; ++corner) {
          start += segment.startBarycentric(corner) * V.row(F(segment.face, corner));
          end += segment.endBarycentric(corner) * V.row(F(segment.face, corner));
        }
        EXPECT_LE((display.cellPoints.row(display.cellEdges(row, 0)) - start).norm(), 1e-12);
        EXPECT_LE((display.cellPoints.row(display.cellEdges(row, 1)) - end).norm(), 1e-12);
        ++row;
      }
    }
  }
  EXPECT_EQ(row, display.cellEdges.rows());

  // Every traced point lies on the flat square.
  for (const auto *points : {&display.cellPoints, &display.cellCorners}) {
    ASSERT_GT(points->rows(), 0);
    EXPECT_LE(points->col(2).cwiseAbs().maxCoeff(), 1e-12);
    EXPECT_GE(points->leftCols(2).minCoeff(), -1e-9);
    EXPECT_LE(points->leftCols(2).maxCoeff(), 2.0 + 1e-9);
  }
  RecordProperty("cells", static_cast<int>(display.cellCount));
}

TEST(SurfaceCellTracingDisplay, RejectsMalformedMatrices) {
  const directional::RemeshDiagnostics diagnostics;
  EXPECT_THROW(directional::visualization::surface_cell_tracing_display(
                   Eigen::MatrixXd(3, 2), Eigen::MatrixXi(1, 3), diagnostics, nullptr),
               std::invalid_argument);
  EXPECT_THROW(directional::visualization::surface_cell_tracing_display(
                   Eigen::MatrixXd(3, 3), Eigen::MatrixXi(1, 4), diagnostics, nullptr),
               std::invalid_argument);
}
