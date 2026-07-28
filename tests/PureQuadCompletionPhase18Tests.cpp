#include <directional/geometry/PureQuadCompletion.h>

#include <algorithm>
#include <map>
#include <vector>

#include <gtest/gtest.h>

namespace {

directional::geometry::PureQuadPatch patch(std::vector<int> sides) {
  directional::geometry::PureQuadPatch p;
  p.sideEdgeCounts = std::move(sides);
  const int count = directional::geometry::pure_quad_detail::boundary_edge_count(p);
  for (int i = 0; i < count; ++i) {
    p.boundaryVertices.push_back(i);
  }
  p.turns.assign(p.sideEdgeCounts.size(), 1);
  constexpr double pi = 3.14159265358979323846;
  for (int i = 0; i < count; ++i) {
    directional::geometry::SurfacePoint point;
    point.face = 0;
    point.component = 0;
    point.sheet = 0;
    const double angle = 2.0 * pi * static_cast<double>(i) /
                         static_cast<double>(count);
    point.position << std::cos(angle), std::sin(angle), 0.0;
    point.barycentric << 1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0;
    point.squaredDistance = 0.0;
    p.boundaryProvenance.push_back(point);
  }
  return p;
}

directional::geometry::PureQuadPatch embedded_patch(std::vector<int> sides) {
  auto p = patch(std::move(sides));
  p.boundaryProvenance.clear();
  for (int i = 0; i < static_cast<int>(p.boundaryVertices.size()); ++i) {
    directional::geometry::SurfacePoint point;
    point.face = 7;
    point.component = 2;
    point.sheet = 3;
    point.position << static_cast<double>(i), static_cast<double>(i % 2), 1.0;
    point.barycentric << 0.5, 0.25, 0.25;
    point.squaredDistance = 0.0;
    p.boundaryProvenance.push_back(point);
  }
  return p;
}

} // namespace

TEST(PureQuadCompletionPhase18, ThreeSidedInequalityEqualityAndFailure) {
  auto equal = patch({2, 1, 1});
  EXPECT_TRUE(
      directional::geometry::check_pure_quad_patch_admissibility(equal)
          .admissible);

  auto fail = patch({4, 1, 1});
  const auto result =
      directional::geometry::check_pure_quad_patch_admissibility(fail);
  EXPECT_FALSE(result.admissible);
  EXPECT_EQ(result.reason,
            directional::geometry::PureQuadPatchRejectReason::SideInequality);
}

TEST(PureQuadCompletionPhase18, FourSidedOppositeEqualityAndFailure) {
  EXPECT_TRUE(directional::geometry::check_pure_quad_patch_admissibility(
                  patch({2, 3, 2, 3}))
                  .admissible);

  const auto result = directional::geometry::check_pure_quad_patch_admissibility(
      patch({4, 2, 2, 2}));
  EXPECT_FALSE(result.admissible);
  EXPECT_EQ(result.reason,
            directional::geometry::PureQuadPatchRejectReason::SideInequality);
}

TEST(PureQuadCompletionPhase18, FiveSidedInequalityEqualityAndFailure) {
  EXPECT_TRUE(directional::geometry::check_pure_quad_patch_admissibility(
                  patch({1, 1, 1, 1, 2}))
                  .admissible);

  const auto result = directional::geometry::check_pure_quad_patch_admissibility(
      patch({1, 1, 4, 1, 1}));
  EXPECT_FALSE(result.admissible);
  EXPECT_EQ(result.reason,
            directional::geometry::PureQuadPatchRejectReason::SideInequality);
}

TEST(PureQuadCompletionPhase18, SixSidedInequalityEqualityFailureAndParity) {
  EXPECT_TRUE(directional::geometry::check_pure_quad_patch_admissibility(
                  patch({2, 2, 1, 1, 1, 1}))
                  .admissible);

  const auto inequality =
      directional::geometry::check_pure_quad_patch_admissibility(
          patch({4, 2, 1, 1, 1, 1}));
  EXPECT_FALSE(inequality.admissible);
  EXPECT_EQ(inequality.reason,
            directional::geometry::PureQuadPatchRejectReason::SideInequality);

  auto parityPatch = patch({2, 1, 2, 1, 2, 2});
  const auto parity =
      directional::geometry::check_pure_quad_patch_admissibility(parityPatch);
  EXPECT_FALSE(parity.admissible);
  EXPECT_EQ(parity.reason,
            directional::geometry::PureQuadPatchRejectReason::HexParity);
}

TEST(PureQuadCompletionPhase18, RejectsOddBoundaryHardFeatureAndBadTurns) {
  auto odd = patch({1, 1, 1});
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(odd)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::OddBoundary);

  auto hard = patch({2, 2, 2});
  hard.hardFeatureCrossing = true;
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(hard)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::HardFeatureCrossing);

  auto badTurn = patch({2, 2, 2});
  badTurn.turns[0] = 2;
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(badTurn)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::InvalidTurn);
}

TEST(PureQuadCompletionPhase18, SingularityRulesAndValenceConvention) {
  auto four = patch({2, 2, 2, 2});
  four.singularityCount = 1;
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(four)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::SingularityMismatch);

  auto three = patch({2, 2, 2});
  three.singularityCount = 2;
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(three)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::SingularityMismatch);

  three.singularityCount = 1;
  three.singularIndexNumerator = 1;
  const auto accepted =
      directional::geometry::check_pure_quad_patch_admissibility(three);
  EXPECT_TRUE(accepted.admissible);
  EXPECT_EQ(accepted.expectedInteriorValence, 3);
}

TEST(PureQuadCompletionPhase18, ClosedFormCountsForSupportedPatches) {
  const auto quad =
      directional::geometry::complete_pure_quad_patch(patch({2, 2, 2, 2}));
  ASSERT_TRUE(quad.success);
  EXPECT_EQ(quad.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::ClosedForm);
  EXPECT_EQ(quad.mesh.quads.size(), 4U);

  const auto tri = directional::geometry::complete_pure_quad_patch(patch({2, 2, 2}));
  ASSERT_TRUE(tri.success);
  EXPECT_EQ(tri.mesh.quads.size(), 2U);

  const auto pent =
      directional::geometry::complete_pure_quad_patch(patch({2, 1, 1, 1, 1}));
  ASSERT_TRUE(pent.success);
  EXPECT_EQ(pent.mesh.quads.size(), 2U);

  const auto hex =
      directional::geometry::complete_pure_quad_patch(patch({1, 1, 1, 1, 1, 1}));
  ASSERT_TRUE(hex.success);
  EXPECT_EQ(hex.mesh.quads.size(), 2U);
}

TEST(PureQuadCompletionPhase18, PatternFallbackCompletesValidNonSimplePatch) {
  auto p = patch({2, 2, 2, 1, 1});
  p.simple = false;
  const auto result = directional::geometry::complete_pure_quad_patch(p);

  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::BoundedCombinatorial);
  EXPECT_GT(result.exploredPatterns, 0);
  EXPECT_TRUE(std::all_of(result.mesh.quads.begin(), result.mesh.quads.end(),
                          [](const auto &q) { return q.size() == 4; }));
}

TEST(PureQuadCompletionPhase18, CompletionDoesNotUseSharedCenterFan) {
  const auto completion =
      directional::geometry::complete_pure_quad_patch(patch({2, 2, 2}));
  ASSERT_TRUE(completion.success);
  EXPECT_FALSE(completion.mesh.usesCenterFan);

  std::map<int, int> interiorUseCount;
  for (const auto &quad : completion.mesh.quads) {
    for (const int vertex : quad) {
      if (vertex < 0) {
        ++interiorUseCount[vertex];
      }
    }
  }
  const auto sharedByEveryQuad =
      std::find_if(interiorUseCount.begin(), interiorUseCount.end(),
                   [&](const auto &entry) {
                     return entry.second ==
                            static_cast<int>(completion.mesh.quads.size());
                   });
  EXPECT_EQ(sharedByEveryQuad, interiorUseCount.end());
}

TEST(PureQuadCompletionPhase18, CompletionVerticesCarrySourceProvenance) {
  const auto completion = directional::geometry::complete_pure_quad_patch(
      embedded_patch({2, 2, 2}));
  ASSERT_TRUE(completion.success);
  ASSERT_EQ(completion.mesh.vertexProvenance.size(),
            completion.mesh.vertices.size());
  ASSERT_EQ(completion.mesh.vertexPositions.rows(),
            static_cast<int>(completion.mesh.vertices.size()));
  for (const auto &point : completion.mesh.vertexProvenance) {
    EXPECT_TRUE(point.valid());
    EXPECT_EQ(point.component, 2);
    EXPECT_EQ(point.sheet, 3);
  }
  EXPECT_NEAR(completion.mesh.vertexPositions(0, 2), 1.0, 1.0e-12);
}

TEST(PureQuadCompletionPhase18, EndpointResolutionChoosesExtensionRemovalTransition) {
  std::vector<directional::geometry::CompletionEndpoint> endpoints(3);
  endpoints[0].id = 0;
  endpoints[0].targetCurve = 10;
  endpoints[0].compatibleCurveAvailable = true;
  endpoints[0].extendCost = 1.0;
  endpoints[0].removeCost = 2.0;
  endpoints[0].transitionCost = 3.0;
  endpoints[1].id = 1;
  endpoints[1].incidentTrace = 11;
  endpoints[1].removalKeepsPatchesFeasible = true;
  endpoints[1].removeCost = 1.0;
  endpoints[2].id = 2;
  endpoints[2].transitionTemplateAvailable = true;
  endpoints[2].transitionCost = 1.0;

  const auto result =
      directional::geometry::resolve_completion_endpoints(endpoints);

  ASSERT_EQ(result.records.size(), 3U);
  EXPECT_EQ(result.records[0].action,
            directional::geometry::EndpointResolutionAction::Extend);
  EXPECT_EQ(result.records[1].action,
            directional::geometry::EndpointResolutionAction::RemoveTrace);
  EXPECT_EQ(result.records[2].action,
            directional::geometry::EndpointResolutionAction::InsertTransition);
  EXPECT_EQ(result.hangingNodes, 0);
  EXPECT_EQ(result.endpointsEmbeddedInEdges, 0);
  EXPECT_EQ(result.arrangementRebuilds, 3);
  EXPECT_EQ(result.mutatedAdjacency.size(), 3U);
}

TEST(PureQuadCompletionPhase18, UnresolvedEndpointReportsHangingNode) {
  directional::geometry::CompletionEndpoint endpoint;
  endpoint.id = 4;
  const auto result =
      directional::geometry::resolve_completion_endpoints({endpoint});

  ASSERT_EQ(result.records.size(), 1U);
  EXPECT_EQ(result.records.front().action,
            directional::geometry::EndpointResolutionAction::Unresolved);
  EXPECT_EQ(result.hangingNodes, 1);
  EXPECT_EQ(result.endpointsEmbeddedInEdges, 1);
}

TEST(PureQuadCompletionPhase18, RewriteCatalogForwardAndRejectionCases) {
  directional::geometry::TopologyRewriteCandidate forward;
  forward.id = 0;
  forward.adjacency = {3, 5, 4};
  forward.boundarySignature = {2, 2};
  forward.singularityLabel = 3;

  directional::geometry::TopologyRewriteCandidate rejected;
  rejected.id = 1;
  rejected.adjacency = {3, 5};
  rejected.boundarySignature = {2, 2};
  rejected.singularityLabel = 3;
  rejected.singularityBudgetAvailable = false;

  const auto result =
      directional::geometry::apply_topology_rewrite_catalog({forward, rejected});

  ASSERT_EQ(result.records.size(), 2U);
  EXPECT_TRUE(result.records[0].committed);
  EXPECT_FALSE(result.records[1].committed);
  EXPECT_EQ(result.committed, 1);
  EXPECT_EQ(result.rejected, 1);
  EXPECT_EQ(result.records[0].outputAdjacency, std::vector<int>({4, 3, 5}));
}

TEST(PureQuadCompletionPhase18, RewriteAcceptanceUsesTemplatePostconditions) {
  directional::geometry::TopologyRewriteCandidate candidate;
  candidate.id = 9;
  candidate.adjacency = {3, 5, 4};
  candidate.boundarySignature = {2, 2};
  candidate.singularityLabel = 3;
  candidate.strictValidatorAccepts = false;
  candidate.postconditionsHold = true;

  const auto result =
      directional::geometry::apply_topology_rewrite_catalog({candidate});

  ASSERT_EQ(result.records.size(), 1U);
  EXPECT_TRUE(result.records.front().committed);
  EXPECT_EQ(result.committed, 1);
}

TEST(PureQuadCompletionPhase18, ClosedSurfaceSingularityBudgetExact) {
  EXPECT_TRUE(directional::geometry::closed_surface_singularity_budget_exact(
      2, {4, 4}));
  EXPECT_FALSE(directional::geometry::closed_surface_singularity_budget_exact(
      2, {4, 3}));
}

TEST(PureQuadCompletionPhase18, ValidationReportsPureQuadAndValenceRatio) {
  const auto completion =
      directional::geometry::complete_pure_quad_patch(patch({2, 2, 2, 2}));
  ASSERT_TRUE(completion.success);

  const auto report = directional::geometry::validate_pure_quad_completion(
      completion.mesh, {3, 5, 6, 4, 3, 5, 3, 5, 3, 5, 3}, {}, true);

  EXPECT_TRUE(report.pureQuads);
  EXPECT_EQ(report.tJunctions, 0);
  EXPECT_EQ(report.hangingNodes, 0);
  EXPECT_TRUE(report.closedSurfaceSingularityBudgetExact);
  EXPECT_GE(report.extraordinaryValence35Ratio, 0.90);
  EXPECT_EQ(report.reportedHighValenceVertices.size(), 1U);
}

TEST(PureQuadCompletionPhase18, ValidationReportsNonPureAndInvariantFlags) {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2};
  mesh.boundaryVertices = mesh.vertices;
  mesh.quads = {{0, 1, 2}};
  mesh.vertexPositions.resize(3, 3);
  mesh.vertexPositions << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;

  auto report =
      directional::geometry::validate_pure_quad_completion(mesh, {}, {}, false);
  report.topologyInvariant = false;
  report.featureBoundaryInvariant = false;

  EXPECT_FALSE(report.pureQuads);
  EXPECT_FALSE(report.closedSurfaceSingularityBudgetExact);
  EXPECT_FALSE(report.topologyInvariant);
  EXPECT_FALSE(report.featureBoundaryInvariant);
}


TEST(PureQuadCompletionPhase18, TransitionTemplateHasConformingDiskTopology) {
  const auto result = directional::geometry::complete_pure_quad_patch(
      patch({2, 1, 1, 1, 1}));
  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::TransitionTemplate);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.mesh));
  EXPECT_EQ(result.mesh.quads.size(), 2U);
}

TEST(PureQuadCompletionPhase18, GeneralPatternPreservesEntireBoundary) {
  const auto result = directional::geometry::complete_pure_quad_patch(
      patch({2, 2, 2, 1, 1}));
  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::Pattern);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.mesh));
  EXPECT_EQ(result.mesh.quads.size(), 3U);
}

TEST(PureQuadCompletionPhase18, MissingProvenanceFailsClosed) {
  auto p = patch({2, 2, 2, 2});
  p.boundaryProvenance.clear();
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.failureReason,
            directional::geometry::PureQuadPatchRejectReason::MissingBoundaryData);
}

TEST(PureQuadCompletionPhase18, BoundedFallbackHonorsSearchLimit) {
  auto p = patch({2, 2, 2, 1, 1});
  p.simple = false;
  directional::geometry::PureQuadCompletionOptions options;
  options.maxBoundaryEdges = 6;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.failureReason,
            directional::geometry::PureQuadPatchRejectReason::SearchLimitExceeded);
}

TEST(PureQuadCompletionPhase18, SingularityCompletionFailsClosedUntilPoleTemplates) {
  auto p = patch({2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = 1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.failureReason,
            directional::geometry::PureQuadPatchRejectReason::UnsupportedSingularityCompletion);
}
