#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/SourceRegionDisplay.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <filesystem>
#include <fstream>
#include <map>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace {

struct ProducedRegions {
  std::string fixture;
  directional::TriMesh mesh;
  std::optional<directional::geometry::SourceTopologyRegions> regions;
};

Eigen::MatrixXd read_rawfield(const std::filesystem::path &path,
                              const int expectedFaces) {
  std::ifstream stream(path);
  int degree = 0;
  int faceCount = 0;
  if (!stream || !(stream >> degree >> faceCount) || degree != 4 ||
      faceCount != expectedFaces) {
    throw std::runtime_error("Invalid rawfield fixture: " + path.string());
  }
  Eigen::MatrixXd raw(faceCount, 3 * degree);
  for (int face = 0; face < faceCount; ++face) {
    for (int column = 0; column < raw.cols(); ++column) {
      if (!(stream >> raw(face, column))) {
        throw std::runtime_error("Invalid rawfield payload: " + path.string());
      }
    }
  }
  return raw;
}

// The first committed fixture whose published regions carry an isolation
// seam between at least two sheets, so the seam checks are non-vacuous.
const ProducedRegions &produced_regions() {
  static const std::optional<ProducedRegions> cached = [] {
    std::string rejected;
    for (const std::string name : {"torus", "genus_two", "sphere_prescribed"}) {
      ProducedRegions candidate;
      candidate.fixture = name;
      const auto meshPath = directional::tests::benchmark_fixture_path(
          "milestone-g/" + name + ".obj");
      if (!directional::readOBJ(meshPath.string(), candidate.mesh)) {
        rejected += name + ":unreadable ";
        continue;
      }
      const Eigen::MatrixXd raw = read_rawfield(
          directional::tests::benchmark_fixture_path("milestone-g/" + name +
                                                     ".rawfield"),
          static_cast<int>(candidate.mesh.F.rows()));

      directional::pipeline::RemeshOptions options;
      options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
      options.surfaceCells.enabled = true;
      options.surfaceCells.fallbackPolicy =
          directional::pipeline::SurfaceCellFallbackPolicy::Fail;
      options.surfaceCells.allowSourceGridRecovery = false;
      options.surfaceCells.retainIntermediateGeometry = true;
      options.parallelizeComponents = false;
      const auto result = directional::pipeline::remesh_from_raw_cross_field(
          candidate.mesh.V, candidate.mesh.F, raw, options);
      const auto &regions =
          result.surfaceCellContext.productSnapshots.sourceTopologyRegions;
      if (!regions.has_value()) {
        rejected += name + ":" + result.diagnostics.terminalFailureStage + " ";
        continue;
      }
      const bool hasSeam = std::any_of(
          regions->regions().begin(), regions->regions().end(),
          [](const auto &region) { return !region.isolation_seams().empty(); });
      if (!hasSeam) {
        rejected += name + ":no-isolation-seam ";
        continue;
      }
      candidate.regions = *regions;
      return std::optional<ProducedRegions>(std::move(candidate));
    }
    ADD_FAILURE() << "no committed fixture published an isolation seam: "
                  << rejected;
    return std::optional<ProducedRegions>();
  }();
  if (!cached.has_value()) {
    throw std::runtime_error("no produced topology-region fixture");
  }
  return *cached;
}

} // namespace

TEST(SourceRegionDisplay, FaceLabelsAndSeamsMatchPublishedRegions) {
  const ProducedRegions &produced = produced_regions();
  const auto &regions = *produced.regions;
  const auto display = directional::visualization::source_region_display(
      produced.mesh.V, produced.mesh.F, regions);
  const Eigen::Index faces = produced.mesh.F.rows();
  ASSERT_EQ(faces, display.faceRegion.size());
  ASSERT_EQ(faces, display.faceSheet.size());
  ASSERT_EQ(faces, display.faceComponent.size());
  EXPECT_EQ(regions.regions().size(), display.regionCount);

  // Labels equal the published region membership, face by face.
  std::size_t labelled = 0;
  for (const auto &region : regions.regions()) {
    for (const auto &face : region.faces()) {
      const auto row = regions.row_for_topology(face.topology);
      ASSERT_TRUE(row.has_value()) << produced.fixture;
      const auto index = static_cast<Eigen::Index>(row->index());
      EXPECT_EQ(static_cast<int>(region.id().index()), display.faceRegion(index));
      EXPECT_EQ(static_cast<int>(face.sheet.index()), display.faceSheet(index));
      EXPECT_EQ(static_cast<int>(region.component().index()),
                display.faceComponent(index));
      ++labelled;
    }
  }
  EXPECT_EQ(static_cast<std::size_t>(faces), labelled) << produced.fixture;

  // Independent oracle: each displayed seam is an interior mesh edge whose
  // two faces carry different isolation sheets.
  std::map<std::pair<int, int>, std::vector<Eigen::Index>> edgeFaces;
  for (Eigen::Index face = 0; face < faces; ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = produced.mesh.F(face, corner);
      const int b = produced.mesh.F(face, (corner + 1) % 3);
      edgeFaces[{std::min(a, b), std::max(a, b)}].push_back(face);
    }
  }
  ASSERT_GT(display.seamEdges.rows(), 0) << produced.fixture;
  ASSERT_EQ(display.seamEdges.rows(), display.seamRegion.size());
  ASSERT_EQ(2 * display.seamEdges.rows(), display.seamPoints.rows());
  std::set<int> seamSheets;
  for (Eigen::Index seam = 0; seam < display.seamEdges.rows(); ++seam) {
    const Eigen::RowVector3d first =
        display.seamPoints.row(display.seamEdges(seam, 0));
    const Eigen::RowVector3d second =
        display.seamPoints.row(display.seamEdges(seam, 1));
    std::optional<std::pair<int, int>> key;
    for (const auto &[edge, incident] : edgeFaces) {
      const bool forward = produced.mesh.V.row(edge.first) == first &&
                           produced.mesh.V.row(edge.second) == second;
      const bool backward = produced.mesh.V.row(edge.first) == second &&
                            produced.mesh.V.row(edge.second) == first;
      if (forward || backward) {
        key = edge;
        break;
      }
    }
    ASSERT_TRUE(key.has_value()) << produced.fixture << " seam " << seam;
    const auto &incident = edgeFaces.at(*key);
    ASSERT_EQ(2U, incident.size()) << produced.fixture << " seam " << seam;
    EXPECT_NE(display.faceSheet(incident[0]), display.faceSheet(incident[1]))
        << produced.fixture << " seam " << seam;
    seamSheets.insert(display.faceSheet(incident[0]));
    seamSheets.insert(display.faceSheet(incident[1]));
  }
  EXPECT_GE(seamSheets.size(), 2U) << produced.fixture;
  EXPECT_GE(display.sheetCount, 2U) << produced.fixture;

  RecordProperty("fixture", produced.fixture);
  RecordProperty("regions", static_cast<int>(display.regionCount));
  RecordProperty("sheets", static_cast<int>(display.sheetCount));
  RecordProperty("seamEdges", static_cast<int>(display.seamEdges.rows()));
  RecordProperty("boundaryEdges",
                 static_cast<int>(display.boundaryEdges.rows()));
}

TEST(SourceRegionDisplay, RejectsMeshesTheRegionsDoNotCover) {
  const ProducedRegions &produced = produced_regions();
  const Eigen::MatrixXi fewerFaces =
      produced.mesh.F.topRows(produced.mesh.F.rows() - 1);
  EXPECT_THROW(directional::visualization::source_region_display(
                   produced.mesh.V, fewerFaces, *produced.regions),
               std::invalid_argument);
  const Eigen::MatrixXd planar = produced.mesh.V.leftCols(2);
  EXPECT_THROW(directional::visualization::source_region_display(
                   planar, produced.mesh.F, *produced.regions),
               std::invalid_argument);
  const Eigen::MatrixXd truncated = produced.mesh.V.topRows(1);
  EXPECT_THROW(directional::visualization::source_region_display(
                   truncated, produced.mesh.F, *produced.regions),
               std::invalid_argument);
}
