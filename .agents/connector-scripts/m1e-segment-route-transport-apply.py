from pathlib import Path

SOURCE = Path("src/geometry/SurfaceCellTracing.cpp")
TESTS = Path("tests/SurfaceCellsPhase10Tests.cpp")

source = SOURCE.read_text()
tests = TESTS.read_text()

old_include = "#include <directional/authority/GridAutomorphism.h>\n#include <directional/authority/LegacyAuthorityAdapters.h>"
new_include = "#include <directional/authority/CanonicalRoute.h>\n#include <directional/authority/GridAutomorphism.h>\n#include <directional/authority/LegacyAuthorityAdapters.h>"
if source.count(old_include) != 1:
    raise SystemExit("unexpected authority include anchor count")
source = source.replace(old_include, new_include, 1)

old_state = """    int totalMatching = 0;
    double totalEffort = 0.0;
    std::vector<int> sourceEdges;
    std::vector<std::uint64_t> sourceTopology;
    sourceEdges.reserve(route.size());
    sourceTopology.reserve(route.size());
"""
new_state = """    double totalEffort = 0.0;
    std::vector<int> sourceEdges;
    std::vector<std::uint64_t> sourceTopology;
    std::vector<authority::TransitionStep> observedSteps;
    sourceEdges.reserve(route.size());
    sourceTopology.reserve(route.size());
    observedSteps.reserve(route.size());
"""
if source.count(old_state) != 1:
    raise SystemExit("unexpected segment route state anchor count")
source = source.replace(old_state, new_state, 1)

old_step = """      sourceEdges.push_back(sourceEdge);
      sourceTopology.push_back(step.edgeKey);
      totalMatching += transition.matching;
      totalEffort += std::abs(transition.effort);
      transitFace = step.face;
      transitFamily = transition.family;
      transitSign = transition.sign;
      transitDirection = transition.direction;
"""
new_step = """      const auto rejectStepAuthority = [&]() {
        set_phase_front_failure(
            failure,
            crossesIsolationSheet
                ? SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport
                : SurfacePhaseFrontFailureReason::MissingTransitionProvenance,
            cellId, sideId, transitFace, step.face, sourceVertex);
        return false;
      };
      const auto firstVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey >> 32U),
          static_cast<std::size_t>(vertices.rows()));
      const auto secondVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey & 0xffffffffULL),
          static_cast<std::size_t>(vertices.rows()));
      if (!firstVertex || !secondVertex) {
        return rejectStepAuthority();
      }
      const auto topology = authority::SourceEdgeTopologyKey::make(
          firstVertex.value(), secondVertex.value());
      if (!topology) {
        return rejectStepAuthority();
      }
      const auto compatibilityTopology = edge_key(
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().first())),
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().second())));
      if (compatibilityTopology != step.edgeKey) {
        return rejectStepAuthority();
      }
      const auto interiorTransition =
          authority::LegacyAuthorityAdapters::interior_transition(
              sourceEdge, sourceMatchingIndices.size());
      if (!interiorTransition) {
        return rejectStepAuthority();
      }
      const auto typedStep = authority::TransitionStep::interior(
          topology.value(),
          std::optional<authority::InteriorTransitionId>{
              interiorTransition.value()},
          authority::GridAutomorphism{
              authority::QuarterTurn::from_integer(transition.matching),
              Eigen::Vector2i::Zero()},
          authority::Orientation::Forward);
      if (!typedStep) {
        return rejectStepAuthority();
      }
      sourceEdges.push_back(sourceEdge);
      sourceTopology.push_back(step.edgeKey);
      observedSteps.push_back(typedStep.value());
      totalEffort += std::abs(transition.effort);
      transitFace = step.face;
      transitFamily = transition.family;
      transitSign = transition.sign;
      transitDirection = transition.direction;
"""
if source.count(old_step) != 1:
    raise SystemExit("unexpected segment route step anchor count")
source = source.replace(old_step, new_step, 1)

old_finish = """    previous.exitEdge = previousEdge;
    current.entryEdge = currentEdge;
    current.matching = normalized_branch(totalMatching);
    current.matchingEffort = totalEffort;
"""
new_finish = """    const authority::CanonicalRoute typedRoute =
        authority::CanonicalRoute::from_observed_steps(std::move(observedSteps));
    authority::GridAutomorphism routeTransport{
        authority::QuarterTurn::from_integer(0), Eigen::Vector2i::Zero()};
    for (const authority::TransitionStep &step : typedRoute.oriented_steps()) {
      routeTransport = authority::compose(step.transport(), routeTransport);
    }
    previous.exitEdge = previousEdge;
    current.entryEdge = currentEdge;
    current.matching = static_cast<int>(routeTransport.rotation.value());
    current.matchingEffort = totalEffort;
"""
if source.count(old_finish) != 1:
    raise SystemExit("unexpected segment route finish anchor count")
source = source.replace(old_finish, new_finish, 1)

old_test_include = "#include <directional/fields/PointSampledCrossField.h>\n"
new_test_include = "#include <directional/authority/GridAutomorphism.h>\n#include <directional/fields/PointSampledCrossField.h>\n"
if tests.count(old_test_include) != 1:
    raise SystemExit("unexpected test include anchor count")
tests = tests.replace(old_test_include, new_test_include, 1)

old_std_include = "#include <fstream>\n#include <stdexcept>\n"
new_std_include = "#include <fstream>\n#include <optional>\n#include <stdexcept>\n"
if tests.count(old_std_include) != 1:
    raise SystemExit("unexpected std include anchor count")
tests = tests.replace(old_std_include, new_std_include, 1)

anchor = """TEST(SurfaceCellsPhase10,
     UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans) {
"""
if tests.count(anchor) != 1:
    raise SystemExit("unexpected vertex-fan test anchor count")

addition = r'''struct SegmentRouteObservation {
  int previousFace = -1;
  int currentFace = -1;
  int matching = 0;
  double matchingEffort = 0.0;
  std::vector<int> sourceEdges;
  std::vector<std::uint64_t> sourceTopology;
};

std::vector<SegmentRouteObservation> segment_route_observations(
    const directional::geometry::SurfaceCellNetwork &network) {
  std::vector<SegmentRouteObservation> observations;
  for (const auto &cell : network.phaseFront.cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (std::size_t index = 1; index < path.size(); ++index) {
        const auto &current = path[index];
        if (current.transitionSourceTopology.empty()) continue;
        observations.push_back(
            {path[index - 1U].face, current.face, current.matching,
             current.matchingEffort, current.transitionSourceEdges,
             current.transitionSourceTopology});
      }
    }
  }
  return observations;
}

directional::geometry::SurfaceCellNetwork build_vertex_fan_network(
    const directional::TriMesh &mesh,
    const directional::fields::CrossFieldResult &crossField) {
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.V.rows(), 0.125);
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  return directional::geometry::build_surface_cell_network(
      mesh.V, mesh.F, crossField, targetSize, options);
}

std::optional<int> expected_segment_route_matching(
    const directional::fields::CrossFieldResult &crossField,
    const SegmentRouteObservation &observation) {
  using directional::authority::GridAutomorphism;
  using directional::authority::QuarterTurn;
  GridAutomorphism total{QuarterTurn::from_integer(0),
                         Eigen::Vector2i::Zero()};
  int face = observation.previousFace;
  for (const std::uint64_t topology : observation.sourceTopology) {
    const auto transition = std::find_if(
        crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
        [&](const auto &candidate) {
          return directional::pipeline::surface_cell_source_edge_key(
                     candidate.sourceVertex0, candidate.sourceVertex1) ==
                 topology;
        });
    if (transition == crossField.edgeTransitions.end()) return std::nullopt;
    int matching = 0;
    int nextFace = -1;
    if (transition->firstFace == face) {
      matching = transition->matching;
      nextFace = transition->secondFace;
    } else if (transition->secondFace == face) {
      matching = -transition->matching;
      nextFace = transition->firstFace;
    } else {
      return std::nullopt;
    }
    total = directional::authority::compose(
        GridAutomorphism{QuarterTurn::from_integer(matching),
                         Eigen::Vector2i::Zero()},
        total);
    face = nextFace;
  }
  if (face != observation.currentFace) return std::nullopt;
  return static_cast<int>(total.rotation.value());
}

bool routes_are_reverse_descriptions(const SegmentRouteObservation &first,
                                     const SegmentRouteObservation &second) {
  return first.previousFace == second.currentFace &&
         first.currentFace == second.previousFace &&
         first.sourceTopology.size() == second.sourceTopology.size() &&
         std::equal(first.sourceTopology.begin(), first.sourceTopology.end(),
                    second.sourceTopology.rbegin());
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     MultiStepVertexFanComposesTypedRouteTransport) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, constant_xy_raw_field(mesh.F.rows()));
  for (auto &transition : crossField.edgeTransitions) transition.matching += 4;

  const auto network = build_vertex_fan_network(mesh, crossField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             network.phaseFront.failure.reason);
  const auto observations = segment_route_observations(network);
  const auto witness = std::find_if(
      observations.begin(), observations.end(), [](const auto &observation) {
        return observation.sourceTopology.size() > 1U;
      });
  ASSERT_NE(observations.end(), witness)
      << "fixture must exercise a real multi-step segment_on_source route";
  const auto expected = expected_segment_route_matching(crossField, *witness);
  ASSERT_TRUE(expected.has_value());
  EXPECT_EQ(*expected, witness->matching);
  EXPECT_GT(witness->matchingEffort, 0.0);
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     ReverseObservedRouteUsesExactTransportInverse) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, constant_xy_raw_field(mesh.F.rows()));
  for (auto &transition : crossField.edgeTransitions) transition.matching += 4;

  const auto network = build_vertex_fan_network(mesh, crossField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition);
  const auto observations = segment_route_observations(network);
  bool foundReverse = false;
  for (std::size_t first = 0; first < observations.size() && !foundReverse;
       ++first) {
    for (std::size_t second = first + 1; second < observations.size(); ++second) {
      if (!routes_are_reverse_descriptions(observations[first],
                                           observations[second])) {
        continue;
      }
      foundReverse = true;
      const auto forward = directional::authority::QuarterTurn::from_integer(
          observations[first].matching);
      const auto reverse = directional::authority::QuarterTurn::from_integer(
          observations[second].matching);
      EXPECT_EQ(forward.inverse(), reverse);
      EXPECT_TRUE(std::equal(observations[first].sourceEdges.begin(),
                             observations[first].sourceEdges.end(),
                             observations[second].sourceEdges.rbegin()));
      break;
    }
  }
  EXPECT_TRUE(foundReverse)
      << "fixture must expose reciprocal observed source routes";
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     EquivalentSignedQuarterTurnsComposeSemantically) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto baseField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  auto equivalentField = baseField;
  for (auto &transition : equivalentField.edgeTransitions) {
    transition.matching += 4;
  }

  const auto base = build_vertex_fan_network(mesh, baseField);
  const auto equivalent = build_vertex_fan_network(mesh, equivalentField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            base.phaseFront.disposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            equivalent.phaseFront.disposition);
  const auto baseRoutes = segment_route_observations(base);
  const auto equivalentRoutes = segment_route_observations(equivalent);
  ASSERT_EQ(baseRoutes.size(), equivalentRoutes.size());
  ASSERT_FALSE(baseRoutes.empty());
  for (std::size_t index = 0; index < baseRoutes.size(); ++index) {
    EXPECT_EQ(baseRoutes[index].previousFace,
              equivalentRoutes[index].previousFace);
    EXPECT_EQ(baseRoutes[index].currentFace, equivalentRoutes[index].currentFace);
    EXPECT_EQ(baseRoutes[index].sourceTopology,
              equivalentRoutes[index].sourceTopology);
    EXPECT_EQ(baseRoutes[index].sourceEdges,
              equivalentRoutes[index].sourceEdges);
    EXPECT_EQ(baseRoutes[index].matching, equivalentRoutes[index].matching);
  }
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     RouteTopologyAndCompactTransitionProvenanceRemainUnchanged) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  const auto network = build_vertex_fan_network(mesh, crossField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            network.phaseFront.disposition);
  const auto observations = segment_route_observations(network);
  const auto witness = std::find_if(
      observations.begin(), observations.end(), [](const auto &observation) {
        return observation.sourceTopology.size() > 1U;
      });
  ASSERT_NE(observations.end(), witness);
  ASSERT_EQ(witness->sourceTopology.size(), witness->sourceEdges.size());

  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.F);
  const auto compact =
      directional::geometry::surface_cell_tracing_detail::edge_matching_indices(
          edgeFaces);
  for (std::size_t index = 0; index < witness->sourceTopology.size(); ++index) {
    const auto found = compact.find(witness->sourceTopology[index]);
    ASSERT_NE(compact.end(), found);
    EXPECT_EQ(found->second, witness->sourceEdges[index]);
  }
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  auto crossField = directional::pipeline::finalize_surface_cell_raw_cross_field(
      mesh, constant_xy_raw_field(mesh.F.rows()));
  const auto baseline = build_vertex_fan_network(mesh, crossField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            baseline.phaseFront.disposition);
  const auto observations = segment_route_observations(baseline);
  const auto witness = std::find_if(
      observations.begin(), observations.end(), [](const auto &observation) {
        return observation.sourceTopology.size() > 1U;
      });
  ASSERT_NE(observations.end(), witness);
  const std::uint64_t corruptedTopology = witness->sourceTopology.front();
  const auto transition = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [&](const auto &candidate) {
        return directional::pipeline::surface_cell_source_edge_key(
                   candidate.sourceVertex0, candidate.sourceVertex1) ==
               corruptedTopology;
      });
  ASSERT_NE(crossField.edgeTransitions.end(), transition);
  transition->sourceVertex0 = mesh.V.rows();

  const auto rejected = build_vertex_fan_network(mesh, crossField);
  EXPECT_EQ(directional::geometry::SurfaceCellProducerDisposition::Rejected,
            rejected.phaseFront.disposition);
  EXPECT_NE(directional::geometry::SurfacePhaseFrontFailureReason::None,
            rejected.phaseFront.failure.reason);
  EXPECT_FALSE(rejected.phaseFront.succeeded);
  EXPECT_TRUE(rejected.phaseFront.cells.empty());
  EXPECT_TRUE(rejected.seeds.empty());
  EXPECT_TRUE(rejected.traces.empty());
  EXPECT_TRUE(rejected.proposals.empty());
}

TEST(SurfaceCellSegmentRouteTransportAuthorityMigration,
     LegacyMatchingFallbackUsesSameTypedRouteComposition) {
  const directional::TriMesh mesh = make_vertex_fan_plane_mesh();
  const auto authoritativeField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          mesh, constant_xy_raw_field(mesh.F.rows()));
  auto legacyField = authoritativeField;
  legacyField.edgeTransitions.clear();

  const auto authoritative = build_vertex_fan_network(mesh, authoritativeField);
  const auto legacy = build_vertex_fan_network(mesh, legacyField);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            authoritative.phaseFront.disposition);
  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
            legacy.phaseFront.disposition)
      << directional::geometry::surface_phase_front_failure_reason_name(
             legacy.phaseFront.failure.reason);
  const auto authoritativeRoutes = segment_route_observations(authoritative);
  const auto legacyRoutes = segment_route_observations(legacy);
  ASSERT_EQ(authoritativeRoutes.size(), legacyRoutes.size());
  ASSERT_FALSE(authoritativeRoutes.empty());
  for (std::size_t index = 0; index < authoritativeRoutes.size(); ++index) {
    EXPECT_EQ(authoritativeRoutes[index].previousFace,
              legacyRoutes[index].previousFace);
    EXPECT_EQ(authoritativeRoutes[index].currentFace,
              legacyRoutes[index].currentFace);
    EXPECT_EQ(authoritativeRoutes[index].sourceTopology,
              legacyRoutes[index].sourceTopology);
    EXPECT_EQ(authoritativeRoutes[index].sourceEdges,
              legacyRoutes[index].sourceEdges);
    EXPECT_EQ(authoritativeRoutes[index].matching, legacyRoutes[index].matching);
  }
}

'''
tests = tests.replace(anchor, addition + anchor, 1)

SOURCE.write_text(source)
TESTS.write_text(tests)
