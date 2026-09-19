#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <numeric>
#include <regex>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

#include "BenchmarkCases.h"
#include "TestFixturePaths.h"
#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SurfaceCellTracing.h>

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
  const auto found = std::find_if(
      cases.begin(), cases.end(), [&](const auto &benchmarkCase) {
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
  directional::pipeline::normalize_surface_cell_cross_field_directions(
      result);
  return result;
}

const std::set<directional::authority::SourceEdgeTopologyKey> &no_recovery_excluded_edges() {
  static const std::set<directional::authority::SourceEdgeTopologyKey> edges;
  return edges;
}

directional::geometry::SourceTopologyRegions recovery_source_authority(
    const Eigen::MatrixXi &faces, const std::vector<int> &components,
    const std::vector<int> &sheets) {
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

std::vector<int> json_integer_array(const fs::path &path,
                                    const std::string &key) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open JSON fixture metadata: " +
                             path.string());
  }
  std::ostringstream text;
  text << stream.rdbuf();
  const std::regex arrayPattern("\\\"" + key +
                                "\\\"\\s*:\\s*\\[([^\\]]*)\\]");
  std::smatch match;
  const std::string document = text.str();
  if (!std::regex_search(document, match, arrayPattern)) {
    throw std::runtime_error("Missing JSON integer array: " + key);
  }
  std::vector<int> values;
  const std::regex numberPattern("-?[0-9]+");
  for (std::sregex_iterator iterator(match[1].first, match[1].second,
                                      numberPattern),
       end;
       iterator != end; ++iterator) {
    values.push_back(std::stoi(iterator->str()));
  }
  return values;
}

TEST(MilestoneGP26, RecoveryTargetProjectionIsBoundedAndDeterministic) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  const auto &benchmarkCase = find_case(cases, "plane__surface_cells");
  const auto meshData =
      directional::bench::load_benchmark_mesh(benchmarkCase);
  const auto fieldData = directional::bench::load_benchmark_field(
      benchmarkCase, meshData.faces.rows());
  directional::TriMesh mesh;
  mesh.set_mesh(meshData.vertices, meshData.faces);
  const auto sourceAuthority =
      recovery_source_authority(mesh.F, {}, {});
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
  const double requested =
      0.5 * (meshData.vertices.colwise().maxCoeff() -
             meshData.vertices.colwise().minCoeff())
                .norm() *
      benchmarkCase.lengthRatio;
  const auto first =
      directional::pipeline::make_source_grid_recovery_target_size(
          meshData.vertices, meshData.faces,
          recovery.mesh.vertexPositions, quads,
          recovery.mesh.vertexProvenance, requested, 2.0);
  const auto second =
      directional::pipeline::make_source_grid_recovery_target_size(
          meshData.vertices, meshData.faces,
          recovery.mesh.vertexPositions, quads,
          recovery.mesh.vertexProvenance, requested, 2.0);
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
      "plane__surface_cells", "cylinder__surface_cells",
      "torus__surface_cells", "multi_face_seam__surface_cells",
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
    const auto sourceAuthority =
        recovery_source_authority(mesh.F, {}, {});
    const auto recovery =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData), &sourceAuthority,
            &no_recovery_excluded_edges());
    ASSERT_TRUE(recovery.success)
        << caseName << ": " << recovery.failure;

    Eigen::MatrixXi quads(
        static_cast<int>(recovery.mesh.quads.size()), 4);
    for (int face = 0; face < quads.rows(); ++face) {
      for (int corner = 0; corner < 4; ++corner) {
        quads(face, corner) =
            recovery.mesh.quads[static_cast<std::size_t>(face)]
                               [static_cast<std::size_t>(corner)];
      }
    }
    const double requested =
        0.5 * (meshData.vertices.colwise().maxCoeff() -
               meshData.vertices.colwise().minCoeff())
                  .norm() *
        benchmarkCase.lengthRatio;
    const auto target =
        directional::pipeline::make_source_grid_recovery_target_size(
            meshData.vertices, meshData.faces,
            recovery.mesh.vertexPositions, quads,
            recovery.mesh.vertexProvenance, requested, 2.0);
    EXPECT_TRUE(target.valid) << caseName << ": " << target.failure;
    EXPECT_LE(target.maxRelaxationRatio, 2.0) << caseName;
    EXPECT_TRUE(target.targetSize.allFinite()) << caseName;
    EXPECT_GT(target.targetSize.minCoeff(), 0.0) << caseName;
  }
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

    const auto sourceAuthority =
        recovery_source_authority(mesh.F, {}, {});
    const auto first =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData), &sourceAuthority,
            &no_recovery_excluded_edges());
    const auto second =
        directional::pipeline::recover_unique_field_aligned_source_quads(
            mesh, recovery_field(fieldData), &sourceAuthority,
            &no_recovery_excluded_edges());
    ASSERT_TRUE(first.success)
        << benchmarkCase.name << ": " << first.failure;
    ASSERT_TRUE(second.success)
        << benchmarkCase.name << ": " << second.failure;
    EXPECT_GT(first.mesh.quads.size(),
              static_cast<std::size_t>(meshData.faces.rows() / 2))
        << benchmarkCase.name;
    EXPECT_TRUE(std::all_of(
        first.mesh.quads.begin(), first.mesh.quads.end(),
        [](const auto &quad) { return quad.size() == 4U; }))
        << benchmarkCase.name;
    EXPECT_GT(first.mesh.vertices.size(),
              static_cast<std::size_t>(meshData.vertices.rows()))
        << benchmarkCase.name;
    EXPECT_FALSE(
        directional::geometry::
            output_is_only_paired_source_triangle_boundaries(
                first.mesh, meshData.faces))
        << benchmarkCase.name;
    EXPECT_EQ(first.mesh.quads, second.mesh.quads)
        << benchmarkCase.name;
    EXPECT_EQ(directional::geometry::PureQuadCompletionBackend::
                  SourceGridRecovery,
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
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 2, 3;
  mesh.set_mesh(vertices, faces);

  const double inverseSqrtTwo = 1.0 / std::sqrt(2.0);
  directional::fields::CrossFieldResult field;
  field.rawField = Eigen::MatrixXd::Zero(1, 12);
  for (Eigen::Index face = 0; face < field.rawField.rows(); ++face) {
    field.rawField.row(face)
        << inverseSqrtTwo, inverseSqrtTwo, 0.0, -inverseSqrtTwo,
        inverseSqrtTwo, 0.0, -inverseSqrtTwo, -inverseSqrtTwo, 0.0,
        inverseSqrtTwo, -inverseSqrtTwo, 0.0;
  }
  directional::pipeline::normalize_surface_cell_cross_field_directions(
      field);

  const auto sourceAuthority =
      recovery_source_authority(mesh.F, {}, {});
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, field, &sourceAuthority,
          &no_recovery_excluded_edges());
  EXPECT_FALSE(recovery.success);
  EXPECT_EQ("InvalidSourceGridInput", recovery.failure);
  EXPECT_TRUE(recovery.mesh.quads.empty());
}

TEST(MilestoneGP26, RecoveryPreservesComponentAndSheetProvenance) {
  const auto cases =
      directional::bench::load_benchmark_manifest(fixture_manifest());
  const auto &benchmarkCase = find_case(cases, "plane__surface_cells");
  const auto meshData =
      directional::bench::load_benchmark_mesh(benchmarkCase);
  const auto fieldData = directional::bench::load_benchmark_field(
      benchmarkCase, meshData.faces.rows());
  directional::TriMesh mesh;
  mesh.set_mesh(meshData.vertices, meshData.faces);
  const std::vector<int> components(
      static_cast<std::size_t>(meshData.faces.rows()), 7);
  const std::vector<int> sheets(
      static_cast<std::size_t>(meshData.faces.rows()), 11);

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
  const auto meshData =
      directional::bench::load_benchmark_mesh(benchmarkCase);
  const auto fieldData = directional::bench::load_benchmark_field(
      benchmarkCase, meshData.faces.rows());
  directional::TriMesh mesh;
  mesh.set_mesh(meshData.vertices, meshData.faces);
  const auto sourceAuthority =
      recovery_source_authority(mesh.F, {}, {});
  const auto recovery =
      directional::pipeline::recover_unique_field_aligned_source_quads(
          mesh, recovery_field(fieldData), &sourceAuthority,
          &no_recovery_excluded_edges());
  ASSERT_TRUE(recovery.success) << recovery.failure;

  const fs::path metadata =
      source_root() / "benchmarks" / "fixtures" / "milestone-g" /
      "sphere_prescribed.fieldmeta.json";
  const std::vector<int> singularVertices =
      json_integer_array(metadata, "singular_vertices");
  const std::vector<int> singularIndices =
      json_integer_array(metadata, "singular_indices");
  ASSERT_EQ(8U, singularVertices.size());
  ASSERT_EQ(singularVertices.size(), singularIndices.size());
  EXPECT_EQ(
      8,
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

} // namespace
