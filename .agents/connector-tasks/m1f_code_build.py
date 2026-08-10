from pathlib import Path


def replace_once(path: Path, old: str, new: str) -> None:
    text = path.read_text()
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected exactly one occurrence, found {count}: {old[:80]!r}")
    path.write_text(text.replace(old, new, 1))


source = Path("src/geometry/SurfaceCellTracing.cpp")
tests = Path("tests/SurfaceCellsPhase10Tests.cpp")
handoff = Path(".agents/Directional/Future_Chat_Session_Handoff.md")
workflow_policy = Path(".agents/Directional/GitHub_Workflow_Policy.md")

# M1f: declare the already-existing provenance helper before the earlier
# continuation consumer; the definition remains at its existing ownership site.
replace_once(
    source,
    "VertexContinuationResult resolve_vertex_continuation(\n",
    "bool source_edge_provenance(\n"
    "    const std::uint64_t edgeKey,\n"
    "    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,\n"
    "    const std::map<std::uint64_t, int> &sourceMatchingIndices,\n"
    "    const EdgeTransitionLookup &transitionLookup,\n"
    "    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,\n"
    "    int &sourceEdge);\n\n"
    "VertexContinuationResult resolve_vertex_continuation(\n",
)

# PathState no longer owns an unrestricted signed integer accumulator. It keeps
# only the semantic observed route required by this continuation owner.
replace_once(
    source,
    "    int family = 0;\n"
    "    int sign = 1;\n"
    "    int matching = 0;\n"
    "    double effort = 0.0;\n",
    "    int family = 0;\n"
    "    int sign = 1;\n"
    "    double effort = 0.0;\n"
    "    std::vector<authority::TransitionStep> routeSteps;\n",
)

old_step = """      PathState next = path;
      next.face = step.face;
      next.family = transition.family;
      next.sign = transition.sign;
      next.matching += transition.matching;
      next.effort += std::abs(transition.effort);
"""
new_step = """      int sourceEdge = -1;
      if (!source_edge_provenance(
              step.edgeKey, edgeFaces, edgeMatchingIndices, transitionLookup,
              edgeTransitions, sourceEdge)) {
        metadataFailure = true;
        continue;
      }
      const auto firstVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey >> 32U),
          static_cast<std::size_t>(vertices.rows()));
      const auto secondVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey & 0xffffffffULL),
          static_cast<std::size_t>(vertices.rows()));
      if (!firstVertex || !secondVertex) {
        metadataFailure = true;
        continue;
      }
      const auto topology = authority::SourceEdgeTopologyKey::make(
          firstVertex.value(), secondVertex.value());
      if (!topology) {
        metadataFailure = true;
        continue;
      }
      const std::uint64_t compatibilityTopology = edge_key(
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().first())),
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().second())));
      if (compatibilityTopology != step.edgeKey) {
        metadataFailure = true;
        continue;
      }
      const auto interiorTransition =
          authority::LegacyAuthorityAdapters::interior_transition(
              sourceEdge, edgeMatchingIndices.size());
      if (!interiorTransition) {
        metadataFailure = true;
        continue;
      }
      const auto typedStep = authority::TransitionStep::interior(
          topology.value(),
          std::optional<authority::InteriorTransitionId>{
              interiorTransition.value()},
          authority::GridAutomorphism{
              authority::QuarterTurn::from_integer(transition.matching),
              authority::LatticeTranslation{0, 0}},
          authority::Orientation::Forward);
      if (!typedStep) {
        metadataFailure = true;
        continue;
      }

      PathState next = path;
      next.face = step.face;
      next.family = transition.family;
      next.sign = transition.sign;
      next.routeSteps.push_back(typedStep.value());
      next.effort += std::abs(transition.effort);
"""
replace_once(source, old_step, new_step)

replace_once(
    source,
    "        candidate.sign = next.sign;\n"
    "        candidate.matching = next.matching;\n"
    "        candidate.matchingEffort = next.effort;\n",
    "        candidate.sign = next.sign;\n"
    "        const authority::CanonicalRoute typedRoute =\n"
    "            authority::CanonicalRoute::from_observed_steps(next.routeSteps);\n"
    "        authority::GridAutomorphism routeTransport =\n"
    "            authority::GridAutomorphism::identity();\n"
    "        for (const authority::TransitionStep &routeStep :\n"
    "             typedRoute.oriented_steps()) {\n"
    "          routeTransport = compose(routeStep.transport(), routeTransport);\n"
    "        }\n"
    "        candidate.matching =\n"
    "            static_cast<int>(routeTransport.rotation.value());\n"
    "        candidate.matchingEffort = next.effort;\n",
)

# Focused M1f contracts exercise the real package-visible production consumer
# directly. The fixture is asymmetric and forces exactly the two-step chain
# face 2 -> 1 -> 0 (or its inverse) while blocking the alternate fan route.
insert = r'''

struct VertexContinuationRouteFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  std::map<std::uint64_t, std::array<int, 2>> edgeFaces;
  std::map<std::uint64_t, int> edgeMatchingIndices;
  std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
  Eigen::VectorXi legacyMatching;
  Eigen::VectorXd legacyEffort;
  directional::geometry::SurfaceCellTracingOptions options;
  std::vector<std::uint64_t> forwardTopology;
  std::vector<int> forwardCompactEdges;
  Eigen::RowVector3d forwardDirection = Eigen::RowVector3d::Zero();
};

VertexContinuationRouteFixture make_vertex_continuation_route_fixture() {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  VertexContinuationRouteFixture fixture;
  fixture.vertices.resize(5, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      0.0, 1.0, 0.0,
                     -1.0, 0.0, 0.0,
                      0.0,-1.0, 0.0;
  fixture.faces.resize(4, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3,
                   0, 3, 4,
                   0, 4, 1;

  const double invSqrt2 = 1.0 / std::sqrt(2.0);
  const Eigen::RowVector3d diagonal(invSqrt2, invSqrt2, 0.0);
  const Eigen::RowVector3d perpendicular(-invSqrt2, invSqrt2, 0.0);
  fixture.forwardDirection = diagonal;
  fixture.faceAxisX.resize(4, 3);
  fixture.faceAxisY.resize(4, 3);
  fixture.faceAxisX.row(0) = perpendicular;
  fixture.faceAxisY.row(0) = -diagonal;
  fixture.faceAxisX.row(1) = perpendicular;
  fixture.faceAxisY.row(1) = diagonal;
  fixture.faceAxisX.row(2) = diagonal;
  fixture.faceAxisY.row(2) = perpendicular;
  fixture.faceAxisX.row(3) = perpendicular;
  fixture.faceAxisY.row(3) = -diagonal;

  fixture.edgeFaces = detail::edge_faces(fixture.faces);
  fixture.edgeMatchingIndices = detail::edge_matching_indices(fixture.edgeFaces);
  const std::uint64_t first = detail::edge_key(0, 3);
  const std::uint64_t second = detail::edge_key(0, 2);
  fixture.forwardTopology = {first, second};
  ASSERT_EQ(2, fixture.edgeMatchingIndices.at(first));
  ASSERT_EQ(1, fixture.edgeMatchingIndices.at(second));
  fixture.forwardCompactEdges = {2, 1};

  directional::fields::CrossFieldEdgeTransition firstTransition;
  firstTransition.sourceEdge = 2;
  firstTransition.sourceVertex0 = 0;
  firstTransition.sourceVertex1 = 3;
  firstTransition.firstFace = 2;
  firstTransition.secondFace = 1;
  firstTransition.matching = 1;
  firstTransition.effort = 0.25;
  fixture.transitions.push_back(firstTransition);

  directional::fields::CrossFieldEdgeTransition secondTransition;
  secondTransition.sourceEdge = 1;
  secondTransition.sourceVertex0 = 0;
  secondTransition.sourceVertex1 = 2;
  secondTransition.firstFace = 1;
  secondTransition.secondFace = 0;
  secondTransition.matching = 2;
  secondTransition.effort = 0.5;
  fixture.transitions.push_back(secondTransition);

  fixture.legacyMatching =
      Eigen::VectorXi::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  fixture.legacyEffort =
      Eigen::VectorXd::Zero(static_cast<int>(fixture.edgeMatchingIndices.size()));
  fixture.legacyMatching[fixture.edgeMatchingIndices.at(first)] = -1;
  fixture.legacyMatching[fixture.edgeMatchingIndices.at(second)] = -2;
  fixture.legacyEffort[fixture.edgeMatchingIndices.at(first)] = 0.25;
  fixture.legacyEffort[fixture.edgeMatchingIndices.at(second)] = 0.5;

  fixture.options.sourceFaceComponents = {0, 0, 0, 0};
  fixture.options.sourceFaceSheets = {0, 0, 0, 0};
  fixture.options.hardFeatureEdges.insert(detail::edge_key(0, 1));
  fixture.options.hardFeatureEdges.insert(detail::edge_key(0, 4));
  return fixture;
}

directional::geometry::surface_cell_tracing_detail::VertexContinuationResult
resolve_vertex_continuation_fixture(
    const VertexContinuationRouteFixture &fixture, const int currentFace,
    const int currentFamily, const int currentSign,
    const Eigen::RowVector3d &incomingDirection,
    const std::vector<directional::fields::CrossFieldEdgeTransition>
        *transitions) {
  namespace detail = directional::geometry::surface_cell_tracing_detail;
  const auto lookup = transitions != nullptr
                          ? detail::edge_transition_lookup(*transitions)
                          : detail::EdgeTransitionLookup{};
  return detail::resolve_vertex_continuation(
      fixture.vertices, fixture.faces, fixture.faceAxisX, fixture.faceAxisY,
      fixture.edgeFaces, fixture.edgeMatchingIndices, lookup, currentFace, 0,
      currentFamily, currentSign, incomingDirection, fixture.options,
      &fixture.legacyMatching, &fixture.legacyEffort, transitions);
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     MultiStepContinuationComposesTypedTransport) {
  const auto fixture = make_vertex_continuation_route_fixture();
  ASSERT_EQ(2U, fixture.transitions.size());
  EXPECT_EQ(1, fixture.transitions[0].matching);
  EXPECT_EQ(2, fixture.transitions[1].matching);

  const auto result = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);

  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            result.status);
  EXPECT_EQ(0, result.face);
  EXPECT_EQ((std::vector<int>{2, 1, 0}), result.facePath);
  EXPECT_EQ(3, result.matching);
  EXPECT_EQ(1, result.family);
  EXPECT_EQ(-1, result.sign);
  EXPECT_TRUE(result.direction.isApprox(fixture.forwardDirection, 1.0e-12));
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     ReverseObservedContinuationUsesExactTransportInverse) {
  const auto fixture = make_vertex_continuation_route_fixture();
  const auto forward = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  const auto reverse = resolve_vertex_continuation_fixture(
      fixture, 0, 1, 1, -fixture.forwardDirection, &fixture.transitions);

  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            forward.status);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            reverse.status);
  EXPECT_EQ(3, forward.matching);
  EXPECT_EQ(1, reverse.matching);
  EXPECT_EQ((std::vector<int>{0, 1, 2}), reverse.facePath);
  EXPECT_EQ(0, fixture_quarter_turn(forward.matching + reverse.matching));
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     EquivalentSignedRepresentationsNormalizeSemantically) {
  const auto fixture = make_vertex_continuation_route_fixture();
  auto plusFour = fixture.transitions;
  plusFour[0].matching += 4;
  auto minusFour = fixture.transitions;
  minusFour[1].matching -= 4;

  const auto baseline = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  const auto positive = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &plusFour);
  const auto negative = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &minusFour);

  for (const auto *result : {&baseline, &positive, &negative}) {
    ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                  VertexContinuationStatus::Found,
              result->status);
    EXPECT_EQ(3, result->matching);
    EXPECT_EQ((std::vector<int>{2, 1, 0}), result->facePath);
  }
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     ContinuationFacePathPreservesIndependentCompactRouteAuthority) {
  const auto fixture = make_vertex_continuation_route_fixture();
  ASSERT_EQ(2U, fixture.forwardTopology.size());
  ASSERT_EQ(2U, fixture.forwardCompactEdges.size());
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::edge_key(0, 3),
            fixture.forwardTopology[0]);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::edge_key(0, 2),
            fixture.forwardTopology[1]);
  EXPECT_EQ((std::vector<int>{2, 1}), fixture.forwardCompactEdges);

  const auto result = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            result.status);
  EXPECT_EQ((std::vector<int>{2, 1, 0}), result.facePath);
  EXPECT_EQ(3, result.matching);
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     MalformedAuthoritativeStepProvenanceFailsClosedWithoutLegacyFallback) {
  const auto fixture = make_vertex_continuation_route_fixture();
  const auto baseline = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            baseline.status);

  auto malformed = fixture.transitions;
  malformed[0].sourceEdge = -1;
  const auto rejected = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &malformed);
  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::FieldMetadata,
            rejected.status);
  EXPECT_EQ(-1, rejected.face);
  EXPECT_TRUE(rejected.facePath.empty());
}

TEST(SurfaceCellVertexContinuationRouteTransportAuthorityMigration,
     LegacyMatchingPathUsesSameTypedRouteComposition) {
  const auto fixture = make_vertex_continuation_route_fixture();
  const auto authoritative = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, &fixture.transitions);
  const auto legacy = resolve_vertex_continuation_fixture(
      fixture, 2, 0, 1, fixture.forwardDirection, nullptr);

  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            authoritative.status);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            legacy.status);
  EXPECT_EQ(authoritative.face, legacy.face);
  EXPECT_EQ(authoritative.family, legacy.family);
  EXPECT_EQ(authoritative.sign, legacy.sign);
  EXPECT_EQ(authoritative.facePath, legacy.facePath);
  EXPECT_EQ(3, authoritative.matching);
  EXPECT_EQ(3, legacy.matching);
  EXPECT_NEAR(authoritative.matchingEffort, legacy.matchingEffort, 1.0e-12);
}
'''
replace_once(tests, "\n} // namespace\n", insert + "\n} // namespace\n")

# User-authorized durable policy: resource-heavy runtime validation may use
# GitHub Actions, without weakening turn or artifact authority boundaries.
replace_once(
    handoff,
    "This section is durable handoff policy and must remain in every future rewrite of this handoff unless the user explicitly changes it.\n\n",
    "This section is durable handoff policy and must remain in every future rewrite of this handoff unless the user explicitly changes it.\n\n"
    "- Long-running or resource-heavy tests and benchmarks may be executed using narrowly scoped GitHub Actions workflows when local or connector execution is impractical or would exceed interactive resource limits. This does not relax turn separation: runtime tests and benchmarks remain Test + Benchmark work, must consume exact immutable artifacts when artifact-only validation is required, and must not rebuild, relink, regenerate, or edit product/test content during that turn. Temporary workflows must follow `GitHub_Workflow_Policy.md`, retain unconditional detailed diagnostic logs plus exact source/artifact authority, and be removed or disabled before their trigger markers/payloads are cleaned up.\n",
)

replace_once(
    workflow_policy,
    "They may **not** configure, compile, relink, regenerate code/discovery, patch packaged source, modify fixtures/manifests, or edit implementation/test/benchmark/validator/build logic. An invalid artifact is an infrastructure failure; do not create a replacement build inside Test + Benchmark.\n",
    "They may **not** configure, compile, relink, regenerate code/discovery, patch packaged source, modify fixtures/manifests, or edit implementation/test/benchmark/validator/build logic. An invalid artifact is an infrastructure failure; do not create a replacement build inside Test + Benchmark.\n\n"
    "Long-running or resource-heavy tests and benchmarks are explicitly permitted on temporary, narrowly scoped GitHub Actions workflows. They remain subject to the same Test + Benchmark artifact-only boundary, exact preflight/postflight authority, logging requirements, bounded time/resource controls, and temporary-workflow cleanup lifecycle; remote execution is an execution-plane choice, not permission to combine build and runtime validation.\n",
)

print("updated M1f source/tests and durable GitHub heavy-test policy")
