from pathlib import Path

path = Path("tests/SurfaceCellsPhase10Tests.cpp")
text = path.read_text()
old = r'''  std::set<std::size_t> typedCharts;
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
'''
new = r'''  ASSERT_GT(fixture.mesh.F.rows(), 10);
  std::vector<int> expectedChartByFace(
      static_cast<std::size_t>(fixture.mesh.F.rows()), 0);
  expectedChartByFace[3] = 1;
  expectedChartByFace[10] = 2;

  std::map<int, std::set<int>> compatibilityChartsByFace;
  std::set<int> producerCompatibilityCharts;
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        ASSERT_GE(segment.face, 0);
        ASSERT_LT(segment.face, fixture.mesh.F.rows());
        const int expectedChart =
            expectedChartByFace[static_cast<std::size_t>(segment.face)];
        EXPECT_EQ(expectedChart, segment.sourceChart)
            << "source face " << segment.face
            << " must preserve the hard-authored producer chart numbering";
        compatibilityChartsByFace[segment.face].insert(segment.sourceChart);
        producerCompatibilityCharts.insert(segment.sourceChart);
      }
    }
  }
  EXPECT_EQ((std::set<int>{0, 1, 2}), producerCompatibilityCharts);
  EXPECT_EQ((std::set<int>{1}), compatibilityChartsByFace[3]);
  EXPECT_EQ((std::set<int>{2}), compatibilityChartsByFace[10]);

  std::set<std::size_t> typedOccurrenceCharts;
  for (const auto &cell : network.phaseFront.cells) {
    ASSERT_EQ(cell.corners.size(), cell.lattice.size());
    for (std::size_t corner = 0; corner < cell.lattice.size(); ++corner) {
      const auto &state = cell.lattice[corner];
      ASSERT_TRUE(state.sourceChart.has_value());
      const int sourceFace = cell.corners[corner].face;
      ASSERT_GE(sourceFace, 0);
      ASSERT_LT(sourceFace, fixture.mesh.F.rows());
      const std::size_t typedChart =
          directional::authority::LegacyAuthorityAdapters::to_legacy_index(
              state.sourceChart.value());
      EXPECT_EQ(
          static_cast<std::size_t>(
              expectedChartByFace[static_cast<std::size_t>(sourceFace)]),
          typedChart)
          << "lattice occurrence on source face " << sourceFace
          << " must carry that face's producer-owned FieldChartId";
      typedOccurrenceCharts.insert(typedChart);
    }
  }
  EXPECT_GE(typedOccurrenceCharts.size(), 2U)
      << "the fixture must exercise more than the default chart in actual "
         "constructive-front occurrences";
'''
if text.count(old) != 1:
    raise SystemExit(f"expected exactly one old witness block, found {text.count(old)}")
text = text.replace(old, new)
path.write_text(text)

updated = path.read_text()
assert "EXPECT_EQ((std::set<std::size_t>{0U, 1U, 2U}), typedCharts);" not in updated
assert "EXPECT_EQ((std::set<int>{0, 1, 2}), producerCompatibilityCharts);" in updated
assert "expectedChartByFace[3] = 1;" in updated
assert "expectedChartByFace[10] = 2;" in updated
assert "EXPECT_GE(typedOccurrenceCharts.size(), 2U)" in updated
