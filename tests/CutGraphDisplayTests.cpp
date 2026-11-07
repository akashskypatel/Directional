#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/CutGraphDisplay.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>

namespace {

struct CutGraphRun {
  directional::TriMesh mesh;
  directional::pipeline::RemeshResult result;
};

CutGraphRun run_fixture(const std::string &name) {
  CutGraphRun run;
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
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.injectFailureAfterStage = 3;
  options.parallelizeComponents = false;
  run.result = directional::pipeline::remesh_from_raw_cross_field(
      run.mesh.V, run.mesh.F, raw, options);
  return run;
}

bool in_some_face(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
                  const Eigen::RowVector3d &first, const Eigen::RowVector3d &second,
                  const double scale) {
  const auto inside = [&](const Eigen::Index face, const Eigen::RowVector3d &point) {
    const Eigen::RowVector3d a = V.row(F(face, 0));
    const Eigen::RowVector3d b = V.row(F(face, 1));
    const Eigen::RowVector3d c = V.row(F(face, 2));
    const Eigen::RowVector3d normal = (b - a).cross(c - a);
    const double area2 = normal.norm();
    if (std::abs((point - a).dot(normal / area2)) > 1e-9 * scale) return false;
    const double wa = (c - b).cross(point - b).dot(normal) / (area2 * area2);
    const double wb = (a - c).cross(point - c).dot(normal) / (area2 * area2);
    return wa >= -1e-7 && wb >= -1e-7 && 1.0 - wa - wb >= -1e-7;
  };
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    if (inside(face, first) && inside(face, second)) return true;
  }
  return false;
}

void expect_display_matches(const CutGraphRun &run) {
  const auto &snapshots = run.result.surfaceCellContext.productSnapshots;
  ASSERT_TRUE(snapshots.surfaceCutGraph.has_value())
      << run.result.diagnostics.terminalFailureStage;
  ASSERT_TRUE(snapshots.globalTopologyPlan.has_value())
      << run.result.diagnostics.terminalFailureStage;
  const auto &V = run.mesh.V;
  const auto &F = run.mesh.F;
  const auto display = directional::visualization::cut_graph_display(
      V, F, &*snapshots.surfaceCutGraph, &*snapshots.globalTopologyPlan);

  // Cut edges are mesh edges, in published order.
  std::set<std::pair<int, int>> meshEdges;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = F(face, corner);
      const int b = F(face, (corner + 1) % 3);
      meshEdges.insert({std::min(a, b), std::max(a, b)});
    }
  }
  const auto &cuts = snapshots.surfaceCutGraph->cut_edges();
  ASSERT_EQ(static_cast<Eigen::Index>(cuts.size()), display.cutEdges.rows());
  ASSERT_GT(display.cutEdges.rows(), 0);
  for (std::size_t row = 0; row < cuts.size(); ++row) {
    const int a = static_cast<int>(cuts[row].first().index());
    const int b = static_cast<int>(cuts[row].second().index());
    EXPECT_TRUE(meshEdges.count({std::min(a, b), std::max(a, b)}) == 1U);
    const auto index = static_cast<Eigen::Index>(row);
    EXPECT_TRUE(display.cutPoints.row(display.cutEdges(index, 0)) == V.row(a));
    EXPECT_TRUE(display.cutPoints.row(display.cutEdges(index, 1)) == V.row(b));
  }

  // Face labels recomputed from the published region face lists.
  const auto &plan = *snapshots.globalTopologyPlan;
  ASSERT_GT(plan.regions().size(), 0U);
  std::map<std::array<std::size_t, 3>, Eigen::Index> rowOf;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    std::array<std::size_t, 3> key{static_cast<std::size_t>(F(face, 0)),
                                   static_cast<std::size_t>(F(face, 1)),
                                   static_cast<std::size_t>(F(face, 2))};
    std::sort(key.begin(), key.end());
    rowOf[key] = face;
  }
  std::map<Eigen::Index, std::set<int>> owners;
  for (std::size_t region = 0; region < plan.regions().size(); ++region) {
    for (const auto &key : plan.regions()[region].sourceFaces) {
      owners[rowOf.at({key.vertices()[0].index(), key.vertices()[1].index(),
                       key.vertices()[2].index()})]
          .insert(static_cast<int>(region));
    }
  }
  std::size_t split = 0;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const auto found = owners.find(face);
    int expected = directional::visualization::kNoDiscRegion;
    if (found != owners.end() && found->second.size() == 1U) {
      expected = *found->second.begin();
    } else if (found != owners.end()) {
      expected = directional::visualization::kSplitDiscRegion;
      ++split;
    }
    EXPECT_EQ(expected, display.faceRegion(face)) << "face " << face;
  }
  EXPECT_EQ(split, display.splitFaceCount);
  EXPECT_EQ(plan.regions().size(), display.regionCount);

  // Arc segments lie on the surface and keep their arc's kind.
  ASSERT_GT(display.arcEdges.rows(), 0);
  const double scale = (V.colwise().maxCoeff() - V.colwise().minCoeff()).norm();
  for (Eigen::Index row = 0; row < display.arcEdges.rows(); ++row) {
    const int arc = display.arcIndex(row);
    ASSERT_GE(arc, 0);
    ASSERT_LT(static_cast<std::size_t>(arc), plan.arcs().size());
    EXPECT_EQ(static_cast<int>(plan.arcs()[static_cast<std::size_t>(arc)].kind),
              display.arcKind(row));
    EXPECT_TRUE(in_some_face(V, F, display.arcPoints.row(display.arcEdges(row, 0)),
                             display.arcPoints.row(display.arcEdges(row, 1)), scale))
        << "arc segment " << row;
  }
  ::testing::Test::RecordProperty("cutEdges", static_cast<int>(display.cutEdges.rows()));
  ::testing::Test::RecordProperty("regions", static_cast<int>(display.regionCount));
  ::testing::Test::RecordProperty("arcSegments", static_cast<int>(display.arcEdges.rows()));
}

} // namespace

TEST(CutGraphDisplay, TorusMatchesPublishedCutGraphAndRegions) {
  expect_display_matches(run_fixture("torus"));
}

TEST(CutGraphDisplay, GenusTwoMatchesPublishedCutGraphAndRegions) {
  expect_display_matches(run_fixture("genus_two"));
}

TEST(CutGraphDisplay, AbsentProductsGiveAnEmptyDisplay) {
  Eigen::MatrixXd V(3, 3);
  V << 0, 0, 0, 1, 0, 0, 0, 1, 0;
  Eigen::MatrixXi F(1, 3);
  F << 0, 1, 2;
  const auto display =
      directional::visualization::cut_graph_display(V, F, nullptr, nullptr);
  EXPECT_FALSE(display.hasCutGraph);
  EXPECT_FALSE(display.hasTopologyPlan);
  EXPECT_EQ(0, display.cutEdges.rows());
  EXPECT_EQ(directional::visualization::kNoDiscRegion, display.faceRegion(0));
  EXPECT_THROW(directional::visualization::cut_graph_display(V.leftCols(2), F,
                                                             nullptr, nullptr),
               std::invalid_argument);
}
