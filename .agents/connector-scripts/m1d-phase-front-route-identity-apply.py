from pathlib import Path

SOURCE = Path("src/pipeline/RemeshPipeline.cpp")
TESTS = Path("tests/SurfaceCellTransitionQuotientTests.cpp")

source = SOURCE.read_text()
tests = TESTS.read_text()

include_anchor = "#include <directional/pipeline/RemeshPipeline.h>\n#include <directional/geometry/GeneralGraphMatching.h>\n"
include_replacement = (
    "#include <directional/pipeline/RemeshPipeline.h>\n"
    "#include <directional/authority/LegacyAuthorityAdapters.h>\n"
    "#include <directional/geometry/GeneralGraphMatching.h>\n"
)
if "#include <directional/authority/LegacyAuthorityAdapters.h>" not in source:
    if source.count(include_anchor) != 1:
        raise SystemExit("M1d include anchor missing or ambiguous")
    source = source.replace(include_anchor, include_replacement, 1)

old_route_validator = r'''  const auto exact_interior_route_valid =
      [&](const std::vector<int> &routeEdges,
          const std::vector<std::uint64_t> &routeTopology) {
    if (routeTopology.empty() || routeEdges.size() != routeTopology.size()) {
      return false;
    }
    std::set<std::uint64_t> uniqueTopology;
    for (std::size_t index = 0; index < routeTopology.size(); ++index) {
      const std::uint64_t topology = routeTopology[index];
      const auto incidence = exactSourceIncidence.find(topology);
      const auto sourceEdge = sourceEdgeIndices.find(topology);
      if (!uniqueTopology.insert(topology).second ||
          incidence == exactSourceIncidence.end() ||
          incidence->second[0] < 0 || incidence->second[1] < 0 ||
          sourceEdge == sourceEdgeIndices.end() ||
          sourceEdge->second != routeEdges[index]) {
        return false;
      }
    }
    return true;
  };
'''

new_route_validator = r'''  const auto exact_interior_route_valid =
      [&](const std::vector<int> &routeEdges,
          const std::vector<std::uint64_t> &routeTopology) {
    if (routeTopology.empty() || routeEdges.size() != routeTopology.size()) {
      return false;
    }
    const std::size_t transitionExtent = sourceEdgeIndices.size();
    std::set<authority::SourceEdgeTopologyKey> uniqueTopology;
    for (std::size_t index = 0; index < routeTopology.size(); ++index) {
      const std::uint64_t rawTopology = routeTopology[index];
      const std::uint64_t firstLegacyVertex = rawTopology >> 32U;
      const std::uint64_t secondLegacyVertex = rawTopology & 0xffffffffULL;
      const auto firstVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(firstLegacyVertex),
          static_cast<std::size_t>(sourceVertices.rows()));
      const auto secondVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(secondLegacyVertex),
          static_cast<std::size_t>(sourceVertices.rows()));
      if (!firstVertex || !secondVertex) {
        return false;
      }
      const auto topology = authority::SourceEdgeTopologyKey::make(
          firstVertex.value(), secondVertex.value());
      if (!topology || !uniqueTopology.insert(topology.value()).second) {
        return false;
      }

      const std::size_t firstLegacyIndex =
          authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().first());
      const std::size_t secondLegacyIndex =
          authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().second());
      if (firstLegacyIndex >
              static_cast<std::size_t>(std::numeric_limits<int>::max()) ||
          secondLegacyIndex >
              static_cast<std::size_t>(std::numeric_limits<int>::max())) {
        return false;
      }
      const std::uint64_t compatibilityTopology = surface_cell_source_edge_key(
          static_cast<int>(firstLegacyIndex),
          static_cast<int>(secondLegacyIndex));
      if (compatibilityTopology != rawTopology) {
        return false;
      }

      const auto incidence = exactSourceIncidence.find(compatibilityTopology);
      const auto sourceEdge = sourceEdgeIndices.find(compatibilityTopology);
      if (incidence == exactSourceIncidence.end() || incidence->second[0] < 0 ||
          incidence->second[1] < 0 || sourceEdge == sourceEdgeIndices.end()) {
        return false;
      }
      const auto suppliedTransition =
          authority::LegacyAuthorityAdapters::interior_transition(
              static_cast<std::int64_t>(routeEdges[index]), transitionExtent);
      const auto expectedTransition =
          authority::LegacyAuthorityAdapters::interior_transition(
              static_cast<std::int64_t>(sourceEdge->second), transitionExtent);
      if (!suppliedTransition || !expectedTransition ||
          suppliedTransition.value() != expectedTransition.value()) {
        return false;
      }
    }
    return true;
  };
'''

if "std::set<authority::SourceEdgeTopologyKey> uniqueTopology;" not in source:
    if source.count(old_route_validator) != 1:
        raise SystemExit("M1d route-validator anchor missing or ambiguous")
    source = source.replace(old_route_validator, new_route_validator, 1)

m1d_tests = r'''

TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,
     ValidHardRailRouteUsesTypedIdentity) {
  const auto &fixture = hard_rail_fixture();
  const int hardRail = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const auto &edge =
      fixture.network.phaseFront.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_FALSE(edge.sourceRouteTopology.empty());
  ASSERT_EQ(edge.sourceRouteTopology.size(), edge.sourceRouteEdges.size());

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  for (std::size_t index = 0; index < edge.sourceRouteTopology.size(); ++index) {
    const auto expected = sourceTransitions.find(edge.sourceRouteTopology[index]);
    ASSERT_NE(sourceTransitions.end(), expected);
    EXPECT_EQ(expected->second, edge.sourceRouteEdges[index]);
  }

  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(1, result.connectedComponents);
}

TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,
     ValidPeriodicCutRouteUsesTypedIdentity) {
  const auto &fixture = cylinder_fixture();
  const int periodic = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::PeriodicCut);
  ASSERT_GE(periodic, 0);
  const auto &edge =
      fixture.network.phaseFront.edges[static_cast<std::size_t>(periodic)];
  ASSERT_FALSE(edge.sourceRouteTopology.empty());
  ASSERT_EQ(edge.sourceRouteTopology.size(), edge.sourceRouteEdges.size());
  ASSERT_GE(edge.periodicRelation, 0);
  ASSERT_LT(static_cast<std::size_t>(edge.periodicRelation),
            fixture.network.phaseFront.periodicHolonomies.size());

  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(fixture.network.phaseFront.periodicHolonomies.size(),
            result.consumedPeriodicHolonomies);
}

TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,
     InvalidInteriorTransitionIdFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  const int hardRail = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  ASSERT_FALSE(sourceTransitions.empty());

  SurfacePhaseFrontResult negative = fixture.network.phaseFront;
  auto &negativeEdge = negative.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_FALSE(negativeEdge.sourceRouteEdges.empty());
  negativeEdge.sourceRouteEdges.front() = -1;
  const auto negativeResult = materialize(fixture, negative);
  EXPECT_FALSE(negativeResult.success);
  EXPECT_EQ("InvalidHardRailAuthority", negativeResult.failure);

  SurfacePhaseFrontResult outOfRange = fixture.network.phaseFront;
  auto &outOfRangeEdge = outOfRange.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_FALSE(outOfRangeEdge.sourceRouteEdges.empty());
  ASSERT_LE(sourceTransitions.size(),
            static_cast<std::size_t>(std::numeric_limits<int>::max()));
  outOfRangeEdge.sourceRouteEdges.front() =
      static_cast<int>(sourceTransitions.size());
  const auto outOfRangeResult = materialize(fixture, outOfRange);
  EXPECT_FALSE(outOfRangeResult.success);
  EXPECT_EQ("InvalidHardRailAuthority", outOfRangeResult.failure);
}

TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,
     OutOfDomainPackedSourceVertexFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_FALSE(edge.sourceRouteTopology.empty());
  edge.sourceRouteTopology.front() =
      directional::pipeline::surface_cell_source_edge_key(
          0, static_cast<int>(fixture.mesh.V.rows()));

  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidHardRailAuthority", result.failure);
}

TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,
     RouteTopologyTransitionMismatchFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_FALSE(edge.sourceRouteEdges.empty());

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const int current = edge.sourceRouteEdges.front();
  int alternate = -1;
  for (const auto &[topology, compact] : sourceTransitions) {
    (void)topology;
    if (compact != current) {
      alternate = compact;
      break;
    }
  }
  ASSERT_GE(alternate, 0)
      << "hard-rail fixture must expose two valid compact transitions";
  edge.sourceRouteEdges.front() = alternate;

  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidHardRailAuthority", result.failure);
}

TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,
     DuplicateSemanticRouteTopologyFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_FALSE(edge.sourceRouteTopology.empty());
  ASSERT_EQ(edge.sourceRouteTopology.size(), edge.sourceRouteEdges.size());
  edge.sourceRouteTopology.push_back(edge.sourceRouteTopology.front());
  edge.sourceRouteEdges.push_back(edge.sourceRouteEdges.front());

  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidHardRailAuthority", result.failure);
}
'''

suite_marker = "TEST(SurfaceCellPhaseFrontRouteAuthorityMigration,"
if suite_marker not in tests:
    close_marker = "\n} // namespace\n"
    close_at = tests.rfind(close_marker)
    if close_at < 0:
        raise SystemExit("M1d test namespace close anchor missing")
    tests = tests[:close_at] + m1d_tests + tests[close_at:]

SOURCE.write_text(source)
TESTS.write_text(tests)
