from pathlib import Path


def read(path):
    return Path(path).read_text(encoding="utf-8")


def write(path, text):
    Path(path).write_text(text, encoding="utf-8")


def replace_required(text, old, new, label, count=1):
    actual = text.count(old)
    if actual != count:
        raise SystemExit(f"{label}: expected {count} matches, found {actual}")
    return text.replace(old, new)


# Public lattice state: typed field-chart authority with explicit absence.
path = "include/directional/geometry/SurfaceCellTracing.h"
text = read(path)
text = replace_required(
    text,
    "#include <numeric>\n#include <queue>",
    "#include <numeric>\n#include <optional>\n#include <queue>",
    "header optional include",
)
text = replace_required(
    text,
    "#include <directional/fields/CrossField.h>\n#include <directional/geometry/ReliefTopology.h>",
    "#include <directional/authority/AuthorityIds.h>\n#include <directional/fields/CrossField.h>\n#include <directional/geometry/ReliefTopology.h>",
    "header authority include",
)
text = replace_required(
    text,
    "  /// Authoritative source chart owning this point's selected source face.\n  int sourceChart = -1;",
    "  /// Authoritative field chart owning this point's selected source face.\n  std::optional<authority::FieldChartId> sourceChart;",
    "typed LocalLatticeState chart",
)
write(path, text)


# Production producer/consumer boundary.
path = "src/geometry/SurfaceCellTracing.cpp"
text = read(path)
text = replace_required(
    text,
    "  /// Connected source chart of equal branch orientation.\n  std::vector<int> faceChart;\n};",
    "  /// Connected field chart of equal branch orientation.\n  std::vector<std::optional<authority::FieldChartId>> faceChart;\n};\n\nstd::optional<authority::FieldChartId> single_field_chart_authority() {\n  const auto chart = authority::LegacyAuthorityAdapters::field_chart(0, 1);\n  if (!chart) {\n    return std::nullopt;\n  }\n  return chart.value();\n}\n\nbool phase_front_cells_have_field_chart_authority(\n    const std::vector<SurfacePhaseFrontCell> &cells) {\n  for (const SurfacePhaseFrontCell &cell : cells) {\n    for (const LocalLatticeState &state : cell.lattice) {\n      if (!state.sourceChart.has_value()) {\n        return false;\n      }\n    }\n  }\n  return true;\n}",
    "UniformPhaseFrame typed chart",
)
old_bfs = """  frame.faceChart.assign(static_cast<std::size_t>(faces.rows()), -1);\n  int nextChart = 0;\n  for (const int seed : activeFaces) {\n    if (frame.faceChart[static_cast<std::size_t>(seed)] >= 0) {\n      continue;\n    }\n    std::queue<int> queue;\n    queue.push(seed);\n    frame.faceChart[static_cast<std::size_t>(seed)] = nextChart;\n    while (!queue.empty()) {\n      const int face = queue.front();\n      queue.pop();\n      for (const int adjacent :\n           equalOrientationAdjacency[static_cast<std::size_t>(face)]) {\n        if (frame.faceChart[static_cast<std::size_t>(adjacent)] >= 0) {\n          continue;\n        }\n        frame.faceChart[static_cast<std::size_t>(adjacent)] = nextChart;\n        queue.push(adjacent);\n      }\n    }\n    ++nextChart;\n  }\n"""
new_bfs = """  // Preserve the established BFS partition and numbering as compatibility\n  // representation, then cross one checked boundary into semantic chart IDs.\n  std::vector<int> legacyFaceChart(static_cast<std::size_t>(faces.rows()), -1);\n  int nextChart = 0;\n  for (const int seed : activeFaces) {\n    if (legacyFaceChart[static_cast<std::size_t>(seed)] >= 0) {\n      continue;\n    }\n    std::queue<int> queue;\n    queue.push(seed);\n    legacyFaceChart[static_cast<std::size_t>(seed)] = nextChart;\n    while (!queue.empty()) {\n      const int face = queue.front();\n      queue.pop();\n      for (const int adjacent :\n           equalOrientationAdjacency[static_cast<std::size_t>(face)]) {\n        if (legacyFaceChart[static_cast<std::size_t>(adjacent)] >= 0) {\n          continue;\n        }\n        legacyFaceChart[static_cast<std::size_t>(adjacent)] = nextChart;\n        queue.push(adjacent);\n      }\n    }\n    ++nextChart;\n  }\n  if (nextChart <= 0) {\n    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::MissingFaceState);\n    return false;\n  }\n  frame.faceChart.assign(static_cast<std::size_t>(faces.rows()), std::nullopt);\n  for (const int face : activeFaces) {\n    const auto chart = authority::LegacyAuthorityAdapters::field_chart(\n        legacyFaceChart[static_cast<std::size_t>(face)],\n        static_cast<std::size_t>(nextChart));\n    if (!chart) {\n      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::MissingFaceState,\n                              -1, -1, face);\n      return false;\n    }\n    frame.faceChart[static_cast<std::size_t>(face)] = chart.value();\n  }\n"""
text = replace_required(text, old_bfs, new_bfs, "phase-frame BFS chart typing")
text = replace_required(
    text,
    "        selectedFace >= static_cast<int>(frame.faceChart.size()) ||\n        frame.faceChart[static_cast<std::size_t>(selectedFace)] < 0) {",
    "        selectedFace >= static_cast<int>(frame.faceChart.size()) ||\n        !frame.faceChart[static_cast<std::size_t>(selectedFace)].has_value()) {",
    "segment typed chart presence",
)
text = replace_required(
    text,
    "    segment.sourceChart =\n        frame.faceChart[static_cast<std::size_t>(selectedFace)];",
    "    segment.sourceChart = static_cast<int>(\n        authority::LegacyAuthorityAdapters::to_legacy_index(\n            frame.faceChart[static_cast<std::size_t>(selectedFace)].value()));",
    "segment chart compatibility output",
)
text = replace_required(
    text,
    "            sourceFace >= static_cast<int>(frame.faceChart.size())) {",
    "            sourceFace >= static_cast<int>(frame.faceChart.size()) ||\n            !frame.faceChart[static_cast<std::size_t>(sourceFace)].has_value()) {",
    "planar lattice typed chart presence",
)
# The typed optional copies directly into LocalLatticeState on the planar path.
text = replace_required(
    text,
    "        state.sourceChart = 0;",
    "        state.sourceChart = single_field_chart_authority();",
    "single-chart lattice authority",
    count=2,
)
text = replace_required(
    text,
    "      if (!local.succeeded || local.cells.empty()) {",
    "      if (!local.succeeded || local.cells.empty() ||\n          !phase_front_cells_have_field_chart_authority(local.cells)) {",
    "aggregate field-chart fail-closed gate",
)
write(path, text)


# Downstream hashing/equality/quotient compatibility must consume typed IDs.
path = "src/pipeline/RemeshPipeline.cpp"
text = read(path)
text = replace_required(
    text,
    "    hash_combine_i64(seed, state.scaleLevel);\n    hash_combine_i64(seed, state.sourceChart);",
    "    hash_combine_i64(seed, state.scaleLevel);\n    hash_combine_i64(seed, state.sourceChart.has_value() ? 1 : 0);\n    if (state.sourceChart.has_value()) {\n      hash_combine_i64(\n          seed, static_cast<std::int64_t>(\n                    authority::LegacyAuthorityAdapters::to_legacy_index(\n                        state.sourceChart.value())));\n    }",
    "typed lattice chart hash",
)
text = replace_required(
    text,
    "  const auto lattice_equal = [](const geometry::LocalLatticeState &first,\n                                const geometry::LocalLatticeState &second) {\n    return first.latticeCoordinate == second.latticeCoordinate &&\n           first.branchRotation == second.branchRotation &&\n           first.scaleLevel == second.scaleLevel &&\n           first.sourceChart == second.sourceChart &&\n           (first.phase - second.phase).norm() <= 1.0e-10;\n  };",
    "  const auto lattice_equal = [](const geometry::LocalLatticeState &first,\n                                const geometry::LocalLatticeState &second) {\n    if (!first.sourceChart.has_value() || !second.sourceChart.has_value()) {\n      return false;\n    }\n    return first.latticeCoordinate == second.latticeCoordinate &&\n           first.branchRotation == second.branchRotation &&\n           first.scaleLevel == second.scaleLevel &&\n           first.sourceChart.value() == second.sourceChart.value() &&\n           (first.phase - second.phase).norm() <= 1.0e-10;\n  };",
    "typed lattice chart equality",
)
old_domain = """      domainStates.push_back(\n          {occurrence.topologyRegion, occurrence.point.sheet,\n           occurrence.lattice.latticeCoordinate.x(),\n           occurrence.lattice.latticeCoordinate.y(),\n           occurrence.lattice.branchRotation, occurrence.lattice.scaleLevel,\n           occurrence.lattice.sourceChart});"""
new_domain = """      if (!occurrence.lattice.sourceChart.has_value()) {\n        result.failure = \"MissingFieldChartAuthority\";\n        return result;\n      }\n      domainStates.push_back(\n          {occurrence.topologyRegion, occurrence.point.sheet,\n           occurrence.lattice.latticeCoordinate.x(),\n           occurrence.lattice.latticeCoordinate.y(),\n           occurrence.lattice.branchRotation, occurrence.lattice.scaleLevel,\n           static_cast<std::int64_t>(\n               authority::LegacyAuthorityAdapters::to_legacy_index(\n                   occurrence.lattice.sourceChart.value()))});"""
text = replace_required(text, old_domain, new_domain, "quotient chart compatibility state")
text = replace_required(
    text,
    "      return std::tuple{weightedVertices, occurrence.point.sheet,\n                        occurrence.lattice.sourceChart,\n                        occurrence.topologyRegion, occurrence.point.face};",
    "      return std::tuple{\n          weightedVertices, occurrence.point.sheet,\n          authority::LegacyAuthorityAdapters::to_legacy_index(\n              occurrence.lattice.sourceChart.value()),\n          occurrence.topologyRegion, occurrence.point.face};",
    "representative chart compatibility key",
)
write(path, text)


# Packaged fixture root: prefer sibling ../test-data, retain existing fallback.
path = "tests/TestFixturePaths.h"
text = read(path)
text = replace_required(
    text,
    "inline std::filesystem::path test_data_root() {\n  const std::filesystem::path packaged =\n      test_executable_directory() / \"test-data\";\n  if (std::filesystem::exists(packaged / \"benchmarks\" / \"fixtures\")) {\n    return packaged;\n  }\n  return std::filesystem::path(DIRECTIONAL_TEST_SOURCE_DIR);\n}",
    "inline std::filesystem::path test_data_root() {\n  const std::filesystem::path executableDirectory =\n      test_executable_directory();\n  const std::filesystem::path siblingPackage =\n      executableDirectory.parent_path() / \"test-data\";\n  if (std::filesystem::exists(siblingPackage / \"benchmarks\" / \"fixtures\")) {\n    return siblingPackage;\n  }\n  const std::filesystem::path legacyPackage = executableDirectory / \"test-data\";\n  if (std::filesystem::exists(legacyPackage / \"benchmarks\" / \"fixtures\")) {\n    return legacyPackage;\n  }\n  return std::filesystem::path(DIRECTIONAL_TEST_SOURCE_DIR);\n}",
    "packaged fixture sibling lookup",
)
write(path, text)


# Six behavioral M1h contracts. They compile in this turn and execute only in
# the following immutable artifact-only Test + Benchmark turn.
path = "tests/SurfaceCellsPhase10Tests.cpp"
text = read(path)
text = replace_required(
    text,
    "#include <directional/fields/PointSampledCrossField.h>",
    "#include <directional/authority/LegacyAuthorityAdapters.h>\n#include <directional/fields/PointSampledCrossField.h>",
    "test authority adapter include",
)
insert = r'''

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     PlanarMultiFaceFrontPublishesCheckedSingleChart) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);

  const auto network = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  ASSERT_FALSE(network.phaseFront.cells.empty());
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      EXPECT_EQ(0U,
                directional::authority::LegacyAuthorityAdapters::to_legacy_index(
                    state.sourceChart.value()));
    }
  }
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     MultipleOrientationChartsPreserveEstablishedNumbering) {
  const SegmentRouteFixture fixture = make_segment_route_fixture();
  const auto network =
      build_segment_route_network(fixture, fixture.authoritativeField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);

  std::set<std::size_t> typedCharts;
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      typedCharts.insert(
          directional::authority::LegacyAuthorityAdapters::to_legacy_index(
              state.sourceChart.value()));
    }
  }
  EXPECT_EQ((std::set<std::size_t>{0U, 1U, 2U}), typedCharts);

  std::map<int, std::set<int>> compatibilityChartsByFace;
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        compatibilityChartsByFace[segment.face].insert(segment.sourceChart);
      }
    }
  }
  EXPECT_EQ((std::set<int>{1}), compatibilityChartsByFace[3]);
  EXPECT_EQ((std::set<int>{2}), compatibilityChartsByFace[10]);
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     NumericCoincidenceCannotCrossAuthorityDomains) {
  using directional::authority::AuthorityDomain;
  using directional::authority::DomainErrorCode;
  using directional::authority::FieldChartId;
  using directional::authority::LegacyAuthorityAdapters;

  const auto chart = LegacyAuthorityAdapters::field_chart(0, 1);
  const auto face = LegacyAuthorityAdapters::source_face(0, 1);
  ASSERT_TRUE(chart);
  ASSERT_TRUE(face);
  EXPECT_EQ(LegacyAuthorityAdapters::to_legacy_index(chart.value()),
            LegacyAuthorityAdapters::to_legacy_index(face.value()));

  const auto wrongDomain = LegacyAuthorityAdapters::checked<FieldChartId>(
      AuthorityDomain::SourceFace, 0, 1);
  ASSERT_FALSE(wrongDomain);
  EXPECT_EQ(DomainErrorCode::DomainMismatch, wrongDomain.error().code);
  EXPECT_EQ(AuthorityDomain::FieldChart, wrongDomain.error().expectedDomain);
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     MissingOrInvalidChartAuthorityCannotMasqueradeAsValid) {
  directional::geometry::LocalLatticeState state;
  EXPECT_FALSE(state.sourceChart.has_value());

  const auto negative =
      directional::authority::LegacyAuthorityAdapters::field_chart(-1, 3);
  const auto outOfRange =
      directional::authority::LegacyAuthorityAdapters::field_chart(3, 3);
  EXPECT_FALSE(negative);
  EXPECT_FALSE(outOfRange);

  const auto valid =
      directional::authority::LegacyAuthorityAdapters::field_chart(0, 3);
  ASSERT_TRUE(valid);
  state.sourceChart = valid.value();
  ASSERT_TRUE(state.sourceChart.has_value());
  EXPECT_EQ(0U,
            directional::authority::LegacyAuthorityAdapters::to_legacy_index(
                state.sourceChart.value()));
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     FaceRowPermutationPreservesTypedPlanarChartAuthority) {
  const directional::TriMesh forwardMesh = make_vertex_fan_plane_mesh(false);
  const directional::TriMesh reverseMesh = make_vertex_fan_plane_mesh(true);
  const auto forwardField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          forwardMesh, constant_xy_raw_field(forwardMesh.F.rows()));
  const auto reverseField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          reverseMesh, constant_xy_raw_field(reverseMesh.F.rows()));
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(forwardMesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions forwardOptions;
  forwardOptions.sourceFaceComponents.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  forwardOptions.sourceFaceSheets.assign(
      static_cast<std::size_t>(forwardMesh.F.rows()), 0);
  directional::geometry::SurfaceCellTracingOptions reverseOptions = forwardOptions;

  const auto forward = directional::geometry::build_surface_cell_network(
      forwardMesh.V, forwardMesh.F, forwardField, targetSize, forwardOptions);
  const auto reverse = directional::geometry::build_surface_cell_network(
      reverseMesh.V, reverseMesh.F, reverseField, targetSize, reverseOptions);

  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            forward.phaseFront.disposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            reverse.phaseFront.disposition);
  ASSERT_EQ(forward.phaseFront.cells.size(), reverse.phaseFront.cells.size());
  for (const auto *network : {&forward, &reverse}) {
    for (const auto &cell : network->phaseFront.cells) {
      for (const auto &state : cell.lattice) {
        ASSERT_TRUE(state.sourceChart.has_value());
        EXPECT_EQ(
            0U,
            directional::authority::LegacyAuthorityAdapters::to_legacy_index(
                state.sourceChart.value()));
      }
    }
  }
}

TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,
     PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero) {
  const CurvedDiskFixture disk = make_curved_disk_fixture();
  const auto bounded = directional::geometry::build_surface_cell_network(
      disk.vertices, disk.faces, disk.faceAxisX, disk.faceAxisY,
      disk.targetSize, disk.options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            bounded.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             bounded.phaseFront.failure.reason);
  ASSERT_FALSE(bounded.phaseFront.cells.empty());
  for (const auto &cell : bounded.phaseFront.cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      EXPECT_EQ(0U,
                directional::authority::LegacyAuthorityAdapters::to_legacy_index(
                    state.sourceChart.value()));
    }
  }

  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/cylinder.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd rawField =
      read_rawfield_fixture(fieldPath, mesh.F.rows());
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(mesh,
                                                                    rawField);
  const Eigen::VectorXd target =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.25);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  const auto periodic = directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, target, options);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            periodic.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             periodic.phaseFront.failure.reason);
  ASSERT_FALSE(periodic.phaseFront.cells.empty());
  for (const auto &cell : periodic.phaseFront.cells) {
    for (const auto &state : cell.lattice) {
      ASSERT_TRUE(state.sourceChart.has_value());
      EXPECT_EQ(0U,
                directional::authority::LegacyAuthorityAdapters::to_legacy_index(
                    state.sourceChart.value()));
    }
  }
}
'''
closing = "\n} // namespace\n"
pos = text.rfind(closing)
if pos < 0:
    raise SystemExit("tests: final anonymous namespace close not found")
text = text[:pos] + insert + text[pos:]
if text.count("TEST(SurfaceCellPhaseFrontFieldChartAuthorityMigration,") != 6:
    raise SystemExit("tests: M1h suite must contain exactly six contracts")
write(path, text)

print("m1h_source_edit=pass")
