#include <directional/geometry/PureQuadCompletion.h>

#include <algorithm>
#include <cmath>
#include <map>
#include <numbers>
#include <set>
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

struct CompletionFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  directional::geometry::PureQuadPatch patch;
};

CompletionFixture generated_plane_patch() {
  CompletionFixture fixture;
  fixture.vertices.resize(7, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      1.0, 1.0, 0.0,
                      0.0, 1.0, 0.0,
                      2.0, 0.0, 0.0,
                      3.0, 0.0, 0.0,
                      2.0, 1.0, 0.0;
  fixture.faces.resize(3, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3,
                   4, 5, 6;
  fixture.patch.sideEdgeCounts = {2, 2, 2, 2};
  fixture.patch.turns = {1, 1, 1, 1};
  fixture.patch.sourceFaces = {0, 1};
  const std::vector<Eigen::Vector3d> boundary = {
      {0.0, 0.0, 0.0}, {0.5, 0.0, 0.0}, {1.0, 0.0, 0.0},
      {1.0, 0.5, 0.0}, {1.0, 1.0, 0.0}, {0.5, 1.0, 0.0},
      {0.0, 1.0, 0.0}, {0.0, 0.5, 0.0}};
  for (int index = 0; index < static_cast<int>(boundary.size()); ++index) {
    fixture.patch.boundaryVertices.push_back(index);
    fixture.patch.boundaryProvenance.push_back(
        directional::geometry::project_to_surface(
            fixture.vertices, fixture.faces,
            boundary[static_cast<std::size_t>(index)]));
  }
  return fixture;
}

void assign_distinct_domain_identity(
    directional::geometry::PureQuadMesh &mesh, const int token) {
  auto &identity = mesh.domainIdentity;
  identity.valid = true;
  identity.sourceComponent = 3;
  identity.sourceSheet = 5;
  identity.boundaryNodeCount = 4;
  identity.boundaryHalfedgeCount = 4;
  identity.sourceSupportCount = 2;
  identity.orientedBoundary.valid = true;
  identity.orientedBoundary.values = {101, token};
  identity.undirectedBoundary.valid = true;
  identity.undirectedBoundary.values = {211, token};
  identity.sourceSupport.valid = true;
  identity.sourceSupport.values = {307, token};
}


void assign_same_support_distinct_boundary_identity(
    directional::geometry::PureQuadMesh &mesh, const int boundaryToken) {
  auto &identity = mesh.domainIdentity;
  identity.valid = true;
  identity.sourceComponent = 3;
  identity.sourceSheet = 5;
  identity.boundaryNodeCount = 4;
  identity.boundaryHalfedgeCount = 4;
  identity.sourceSupportCount = 2;
  identity.orientedBoundary.valid = true;
  identity.orientedBoundary.values = {101, boundaryToken};
  identity.undirectedBoundary.valid = true;
  identity.undirectedBoundary.values = {211, boundaryToken};
  identity.sourceSupport.valid = true;
  identity.sourceSupport.values = {307, 9};
}

std::vector<directional::geometry::PureQuadMesh> completed_cylinder_patches(
    Eigen::MatrixXd &vertices, Eigen::MatrixXi &faces,
    const int segments = 8) {
  vertices.resize(2 * segments, 3);
  for (int ring = 0; ring < 2; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const double angle = 2.0 * std::numbers::pi *
                           static_cast<double>(segment) /
                           static_cast<double>(segments);
      vertices.row(ring * segments + segment) <<
          std::cos(angle), std::sin(angle), static_cast<double>(ring);
    }
  }
  faces.resize(2 * segments, 3);
  for (int segment = 0; segment < segments; ++segment) {
    const int next = (segment + 1) % segments;
    faces.row(2 * segment) << segment, next, segments + next;
    faces.row(2 * segment + 1) << segment, segments + next,
        segments + segment;
  }

  std::vector<directional::geometry::PureQuadMesh> patches;
  for (int segment = 0; segment < segments; ++segment) {
    const int next = (segment + 1) % segments;
    directional::geometry::PureQuadPatch cylinderPatch;
    cylinderPatch.sideEdgeCounts = {1, 1, 1, 1};
    cylinderPatch.turns = {1, 1, 1, 1};
    cylinderPatch.sourceFaces = {2 * segment, 2 * segment + 1};
    cylinderPatch.boundaryVertices = {
        segment, next, segments + next, segments + segment};
    for (const int vertex : cylinderPatch.boundaryVertices) {
      cylinderPatch.boundaryProvenance.push_back(
          directional::geometry::project_to_surface(
              vertices, faces, vertices.row(vertex).transpose()));
    }
    directional::geometry::PureQuadCompletionOptions options;
    options.sourcePatch = segment;
    options.sourceVertices = &vertices;
    options.sourceFaces = &faces;
    const auto completion =
        directional::geometry::complete_pure_quad_patch(cylinderPatch, options);
    if (!completion.success) {
      return {};
    }
    patches.push_back(completion.mesh);
  }
  return patches;
}

CompletionFixture source_support_alias_patch() {
  CompletionFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 0.0,
                      1.0, 0.0, 0.0,
                      1.0, 1.0, 0.0,
                      0.0, 1.0, 0.0;
  fixture.faces.resize(2, 3);
  fixture.faces << 0, 1, 2,
                   0, 2, 3;
  fixture.patch.sideEdgeCounts = {1, 1, 1, 1};
  fixture.patch.turns = {1, 1, 1, 1};
  fixture.patch.sourceFaces = {0};
  fixture.patch.boundaryVertices = {10, 11, 12, 13};
  fixture.patch.boundaryComponents.assign(4, 0);
  fixture.patch.boundarySheets.assign(4, 0);

  directional::geometry::SurfacePoint vertexAlias;
  vertexAlias.face = 1;
  vertexAlias.component = 0;
  vertexAlias.sheet = 1;
  vertexAlias.barycentric << 1.0, 0.0, 0.0;
  vertexAlias.position = fixture.vertices.row(0).transpose();
  vertexAlias.squaredDistance = 0.0;

  directional::geometry::SurfacePoint faceZeroVertexOne;
  faceZeroVertexOne.face = 0;
  faceZeroVertexOne.component = 0;
  faceZeroVertexOne.sheet = 0;
  faceZeroVertexOne.barycentric << 0.0, 1.0, 0.0;
  faceZeroVertexOne.position = fixture.vertices.row(1).transpose();
  faceZeroVertexOne.squaredDistance = 0.0;

  directional::geometry::SurfacePoint faceZeroVertexTwo;
  faceZeroVertexTwo.face = 0;
  faceZeroVertexTwo.component = 0;
  faceZeroVertexTwo.sheet = 0;
  faceZeroVertexTwo.barycentric << 0.0, 0.0, 1.0;
  faceZeroVertexTwo.position = fixture.vertices.row(2).transpose();
  faceZeroVertexTwo.squaredDistance = 0.0;

  directional::geometry::SurfacePoint edgeAlias;
  edgeAlias.face = 1;
  edgeAlias.component = 0;
  edgeAlias.sheet = 1;
  edgeAlias.barycentric << 0.5, 0.5, 0.0;
  edgeAlias.position =
      0.5 * (fixture.vertices.row(0) + fixture.vertices.row(2)).transpose();
  edgeAlias.squaredDistance = 0.0;

  fixture.patch.boundaryProvenance = {
      vertexAlias, faceZeroVertexOne, faceZeroVertexTwo, edgeAlias};
  return fixture;
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

TEST(PureQuadCompletionPhase18,
     BoundedFallbackHandlesEvenBoundaryWhenSimpleSideEquationsFail) {
  for (const auto &counts :
       {std::vector<int>{3, 1, 1, 1},
        std::vector<int>{2, 1, 1, 1, 2, 1}}) {
    auto candidate = patch(counts);
    const auto strict =
        directional::geometry::check_pure_quad_patch_admissibility(candidate);
    ASSERT_FALSE(strict.admissible);
    EXPECT_TRUE(strict.reason ==
                    directional::geometry::PureQuadPatchRejectReason::
                        SideInequality ||
                strict.reason ==
                    directional::geometry::PureQuadPatchRejectReason::
                        HexParity);

    directional::geometry::PureQuadCompletionOptions disabled;
    disabled.allowBoundedCombinatorialFallback = false;
    EXPECT_FALSE(directional::geometry::complete_pure_quad_patch(candidate,
                                                                 disabled)
                     .success);

    directional::geometry::PureQuadCompletionOptions enabled;
    enabled.allowBoundedCombinatorialFallback = true;
    const auto completed =
        directional::geometry::complete_pure_quad_patch(candidate, enabled);
    ASSERT_TRUE(completed.success);
    EXPECT_EQ(completed.mesh.backend,
              directional::geometry::PureQuadCompletionBackend::
                  BoundedCombinatorial);
    EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(
        completed.mesh));
  }
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

TEST(PureQuadCompletionPhase18,
     RewriteCatalogCommitsOnlyARealGuardedConnectivityMutation) {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2, 3, 4, 5};
  mesh.boundaryVertices = mesh.vertices;
  mesh.quads = {{0, 1, 2, 3}, {0, 3, 4, 5}};

  directional::geometry::TopologyRewriteCandidate forward;
  forward.id = 0;
  forward.adjacency = {4, 4, 5};
  forward.boundarySignature = {1, 2};
  forward.featureLabel = 7;
  forward.mutation.id = 0;
  forward.mutation.kind =
      directional::geometry::TopologyTemplateKind::LoopRedirection;
  forward.mutation.removeQuadIndices = {0, 1};
  forward.mutation.replacementQuads = {
      {1, 2, 3, 4}, {1, 4, 5, 0}};

  directional::geometry::TopologyRewriteCandidate rejected;
  rejected.id = 1;
  rejected.adjacency = {3, 5};
  rejected.boundarySignature = {2, 2};
  rejected.singularityLabel = 3;
  rejected.singularityBudgetAvailable = false;
  rejected.mutation.id = 1;
  rejected.mutation.kind =
      directional::geometry::TopologyTemplateKind::PolePairCancellation;
  rejected.mutation.removeQuadIndices = {0, 1};
  rejected.mutation.replacementQuads = forward.mutation.replacementQuads;

  const auto result = directional::geometry::apply_topology_rewrite_catalog(
      mesh, {forward, rejected});

  ASSERT_EQ(result.records.size(), 2U);
  EXPECT_TRUE(result.records[0].committed);
  EXPECT_FALSE(result.records[1].committed);
  EXPECT_EQ(result.committed, 1);
  EXPECT_EQ(result.rejected, 1);
  EXPECT_EQ(result.records[0].outputAdjacency,
            std::vector<int>({4, 5, 4}));
  EXPECT_EQ(result.mesh.quads, forward.mutation.replacementQuads);
}

TEST(PureQuadCompletionPhase18,
     RewriteCatalogRejectsMatchedMetadataWithoutAValidMutation) {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2, 3, 4, 5};
  mesh.boundaryVertices = mesh.vertices;
  mesh.quads = {{0, 1, 2, 3}, {0, 3, 4, 5}};

  directional::geometry::TopologyRewriteCandidate candidate;
  candidate.id = 9;
  candidate.adjacency = {4, 4, 5};
  candidate.boundarySignature = {1, 2};
  candidate.featureLabel = 7;
  candidate.mutation.id = 9;
  candidate.mutation.kind =
      directional::geometry::TopologyTemplateKind::LoopRedirection;

  const auto result = directional::geometry::apply_topology_rewrite_catalog(
      mesh, {candidate});

  ASSERT_EQ(result.records.size(), 1U);
  EXPECT_FALSE(result.records.front().committed);
  EXPECT_EQ(result.records.front().reason,
            directional::geometry::PureQuadPatchRejectReason::
                RewritePreconditionFailed);
  EXPECT_EQ(result.committed, 0);
  EXPECT_EQ(result.rejected, 1);
  EXPECT_EQ(result.mesh.quads, mesh.quads);
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

TEST(PureQuadCompletionPhase18,
     BalancedPatternCompletesManySidedRegularDiskWithoutBoundaryFan) {
  const auto candidate = patch(std::vector<int>(14, 2));
  const auto admissibility =
      directional::geometry::check_pure_quad_patch_admissibility(candidate);
  ASSERT_TRUE(admissibility.admissible);

  const auto result =
      directional::geometry::complete_pure_quad_patch(candidate);
  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::Pattern);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.mesh));
  ASSERT_EQ(result.mesh.quads.size(), 13U);
  EXPECT_EQ(result.mesh.vertices, candidate.boundaryVertices);

  std::set<std::pair<int, int>> expectedBoundary;
  for (int index = 0;
       index < static_cast<int>(candidate.boundaryVertices.size()); ++index) {
    expectedBoundary.insert(std::minmax(
        candidate.boundaryVertices[static_cast<std::size_t>(index)],
        candidate.boundaryVertices[static_cast<std::size_t>(
            (index + 1) % candidate.boundaryVertices.size())]));
  }
  EXPECT_EQ(directional::geometry::pure_quad_detail::boundary_edges(
                result.mesh.quads),
            expectedBoundary);

  const auto valences =
      directional::geometry::pure_quad_detail::vertex_valences(
          result.mesh.quads);
  const auto maximum = std::max_element(
      valences.begin(), valences.end(),
      [](const auto &left, const auto &right) {
        return left.second < right.second;
      });
  ASSERT_NE(maximum, valences.end());
  EXPECT_LE(maximum->second, 6);
}

TEST(PureQuadCompletionPhase18,
     ManySidedCompletionStillRejectsNonDiskAndSingularPatches) {
  auto nonDisk = patch(std::vector<int>(14, 2));
  nonDisk.diskTopology = false;
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(nonDisk)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::NonDisk);

  auto singular = patch(std::vector<int>(14, 2));
  singular.singularityCount = 1;
  singular.singularIndexNumerator = 1;
  EXPECT_EQ(directional::geometry::check_pure_quad_patch_admissibility(singular)
                .reason,
            directional::geometry::PureQuadPatchRejectReason::SingularityMismatch);
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

TEST(PureQuadCompletionPhase18, SingularityCompletionUsesPoleTemplate) {
  auto p = patch({2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = 1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  EXPECT_TRUE(result.success);
  EXPECT_EQ(result.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::PoleTemplate);
}

TEST(PureQuadCompletionPhase18, P17BuildsValenceThreeSingularityPole) {
  auto p = patch({2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = 1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  ASSERT_TRUE(result.success);
  EXPECT_EQ(result.mesh.backend,
            directional::geometry::PureQuadCompletionBackend::PoleTemplate);
  ASSERT_EQ(result.mesh.quads.size(), 3U);
  const int pole = result.mesh.quads.front().front();
  const auto valences =
      directional::geometry::pure_quad_detail::vertex_valences(result.mesh.quads);
  ASSERT_TRUE(valences.count(pole));
  EXPECT_EQ(valences.at(pole), 3);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.mesh));
}

TEST(PureQuadCompletionPhase18, P17BuildsValenceFiveSingularityPole) {
  auto p = patch({2, 2, 2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = -1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  ASSERT_TRUE(result.success);
  ASSERT_EQ(result.mesh.quads.size(), 5U);
  const int pole = result.mesh.quads.front().front();
  const auto valences =
      directional::geometry::pure_quad_detail::vertex_valences(result.mesh.quads);
  EXPECT_EQ(valences.at(pole), 5);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.mesh));
}

TEST(PureQuadCompletionPhase18, P17PoleTemplateFailsClosedForWrongBoundaryPattern) {
  auto p = patch({1, 1, 1, 1, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = -1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  EXPECT_FALSE(result.success);
  EXPECT_EQ(result.failureReason,
            directional::geometry::PureQuadPatchRejectReason::UnsupportedSingularityCompletion);
}

TEST(PureQuadCompletionPhase18, P17GuardedLoopRedirectionMutatesConnectivity) {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2, 3, 4, 5};
  mesh.boundaryVertices = mesh.vertices;
  mesh.quads = {{0, 1, 2, 3}, {0, 3, 4, 5}};

  directional::geometry::GuardedTopologyMutation mutation;
  mutation.id = 4;
  mutation.kind = directional::geometry::TopologyTemplateKind::LoopRedirection;
  mutation.removeQuadIndices = {0, 1};
  mutation.replacementQuads = {{1, 2, 3, 4}, {1, 4, 5, 0}};
  mutation.expectedValenceBefore = {{0, 3}, {3, 3}};
  mutation.expectedValenceAfter = {{1, 3}, {4, 3}};

  const auto result =
      directional::geometry::apply_guarded_topology_mutations(mesh, {mutation});
  ASSERT_EQ(result.committed, 1);
  ASSERT_EQ(result.rejected, 0);
  EXPECT_EQ(result.mesh.quads, mutation.replacementQuads);
  EXPECT_EQ(result.records.front().reason,
            directional::geometry::PureQuadPatchRejectReason::None);
}

TEST(PureQuadCompletionPhase18, P17ProtectedFeatureViolationRollsBack) {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2, 3, 4, 5};
  mesh.boundaryVertices = mesh.vertices;
  mesh.quads = {{0, 1, 2, 3}, {0, 3, 4, 5}};

  directional::geometry::GuardedTopologyMutation mutation;
  mutation.id = 5;
  mutation.kind = directional::geometry::TopologyTemplateKind::PolePairSlide;
  mutation.removeQuadIndices = {0, 1};
  mutation.replacementQuads = {{1, 2, 3, 4}, {1, 4, 5, 0}};
  mutation.protectedEdges = {{0, 3}};

  const auto result =
      directional::geometry::apply_guarded_topology_mutations(mesh, {mutation});
  ASSERT_EQ(result.committed, 0);
  ASSERT_EQ(result.rejected, 1);
  EXPECT_EQ(result.mesh.quads, mesh.quads);
  EXPECT_EQ(result.records.front().reason,
            directional::geometry::PureQuadPatchRejectReason::RewriteFeatureViolation);
}

TEST(PureQuadCompletionPhase18, P17ValenceMismatchRollsBack) {
  directional::geometry::PureQuadMesh mesh;
  mesh.vertices = {0, 1, 2, 3, 4, 5};
  mesh.boundaryVertices = mesh.vertices;
  mesh.quads = {{0, 1, 2, 3}, {0, 3, 4, 5}};

  directional::geometry::GuardedTopologyMutation mutation;
  mutation.id = 6;
  mutation.kind = directional::geometry::TopologyTemplateKind::PolePairCancellation;
  mutation.removeQuadIndices = {0, 1};
  mutation.replacementQuads = {{1, 2, 3, 4}, {1, 4, 5, 0}};
  mutation.expectedValenceAfter = {{1, 4}};

  const auto result =
      directional::geometry::apply_guarded_topology_mutations(mesh, {mutation});
  EXPECT_EQ(result.committed, 0);
  EXPECT_EQ(result.mesh.quads, mesh.quads);
  EXPECT_EQ(result.records.front().reason,
            directional::geometry::PureQuadPatchRejectReason::RewriteValenceMismatch);
}

TEST(PureQuadCompletionPhase18, P18MapsEveryQuadToPatchAndCompletionOperation) {
  auto p = patch({2, 2, 2, 2});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 42;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  ASSERT_TRUE(result.success);
  ASSERT_EQ(result.mesh.quadLineage.size(), result.mesh.quads.size());
  for (int q = 0; q < static_cast<int>(result.mesh.quadLineage.size()); ++q) {
    const auto &lineage = result.mesh.quadLineage[static_cast<std::size_t>(q)];
    EXPECT_TRUE(lineage.valid());
    EXPECT_EQ(lineage.outputQuad, q);
    EXPECT_EQ(lineage.sourcePatch, 42);
    EXPECT_EQ(lineage.operation,
              directional::geometry::PureQuadCompletionBackend::ClosedForm);
  }
}

TEST(PureQuadCompletionPhase18, P18MapsBoundaryFeatureVerticesToOrderedIntervals) {
  auto p = patch({1, 1, 1, 1});
  p.boundaryRailIds.assign(p.boundaryVertices.size(), 7);
  p.boundaryCurveIds.assign(p.boundaryVertices.size(), 11);
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 3;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  ASSERT_TRUE(result.success);
  ASSERT_EQ(result.mesh.vertexLineage.size(), result.mesh.vertices.size());
  for (const auto &lineage : result.mesh.vertexLineage) {
    EXPECT_TRUE(lineage.valid());
    EXPECT_EQ(lineage.kind,
              directional::geometry::PureQuadVertexLineageKind::OrderedFeatureInterval);
    EXPECT_EQ(lineage.featureInterval.railId, 7);
    EXPECT_EQ(lineage.featureInterval.curveId, 11);
  }
}

TEST(PureQuadCompletionPhase18, P18GeneratedInteriorVertexHasSourceTriangleLineage) {
  auto p = patch({2, 2, 2, 2});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 5;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  ASSERT_TRUE(result.success);
  const auto generated = std::find_if(
      result.mesh.vertexLineage.begin(), result.mesh.vertexLineage.end(),
      [](const auto &lineage) { return lineage.outputVertex < 0; });
  ASSERT_NE(generated, result.mesh.vertexLineage.end());
  EXPECT_EQ(generated->kind,
            directional::geometry::PureQuadVertexLineageKind::SourceTriangle);
  EXPECT_TRUE(generated->sourcePoint.valid());
}

TEST(PureQuadCompletionPhase18, P18RejectsPairedSourceTriangleBoundaryProofFixture) {
  directional::geometry::PureQuadMesh mesh;
  mesh.sourcePatch = 9;
  mesh.vertices = {0, 1, 2, 3};
  mesh.quads = {{0, 1, 2, 3}};
  mesh.boundaryVertices = mesh.vertices;
  Eigen::MatrixXi F(2, 3);
  F << 0, 1, 2,
       0, 2, 3;
  for (int v = 0; v < 4; ++v) {
    directional::geometry::SurfacePoint point;
    point.face = (v == 3) ? 1 : 0;
    point.barycentric = Eigen::Vector3d::Zero();
    if (v == 0) point.barycentric(0) = 1.0;
    if (v == 1) point.barycentric(1) = 1.0;
    if (v == 2) point.barycentric(2) = 1.0;
    if (v == 3) point.barycentric(2) = 1.0;
    mesh.vertexProvenance.push_back(point);
    directional::geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = v;
    lineage.sourcePoint = point;
    mesh.vertexLineage.push_back(lineage);
  }
  mesh.quadLineage.push_back(
      {0, 9, directional::geometry::PureQuadCompletionBackend::Pattern, 0});
  const auto validation =
      directional::geometry::validate_pure_quad_output_lineage(mesh, F, true);
  EXPECT_FALSE(validation.valid);
  EXPECT_TRUE(validation.solelyPairedSourceTriangleBoundaries);
  EXPECT_EQ(validation.failure, "PairedSourceTriangleBoundaryOutput");
}

TEST(PureQuadCompletionPhase18,
     P18PairedBoundaryDetectionIsDiagnosticUnlessExplicitlyRejected) {
  directional::geometry::PureQuadMesh mesh;
  mesh.sourcePatch = 9;
  mesh.vertices = {0, 1, 2, 3};
  mesh.quads = {{0, 1, 2, 3}};
  mesh.boundaryVertices = mesh.vertices;
  Eigen::MatrixXi F(2, 3);
  F << 0, 1, 2,
       0, 2, 3;
  for (int v = 0; v < 4; ++v) {
    directional::geometry::SurfacePoint point;
    point.face = (v == 3) ? 1 : 0;
    point.barycentric = Eigen::Vector3d::Zero();
    if (v == 0) point.barycentric(0) = 1.0;
    if (v == 1) point.barycentric(1) = 1.0;
    if (v == 2) point.barycentric(2) = 1.0;
    if (v == 3) point.barycentric(2) = 1.0;
    mesh.vertexProvenance.push_back(point);
    directional::geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = v;
    lineage.sourcePoint = point;
    mesh.vertexLineage.push_back(lineage);
  }
  mesh.quadLineage.push_back(
      {0, 9, directional::geometry::PureQuadCompletionBackend::Pattern, 0});

  const auto validation =
      directional::geometry::validate_pure_quad_output_lineage(mesh, F, false);
  EXPECT_TRUE(validation.valid);
  EXPECT_TRUE(validation.solelyPairedSourceTriangleBoundaries);
  EXPECT_TRUE(validation.failure.empty());
}

TEST(PureQuadCompletionPhase18, P18FailsClosedWhenQuadLineageIsMissing) {
  auto p = patch({1, 1, 1, 1});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 12;
  auto result = directional::geometry::complete_pure_quad_patch(p, options);
  ASSERT_TRUE(result.success);
  result.mesh.quadLineage.clear();
  Eigen::MatrixXi F(1, 3);
  F << 0, 1, 2;
  const auto validation =
      directional::geometry::validate_pure_quad_output_lineage(result.mesh, F, false);
  EXPECT_FALSE(validation.valid);
  EXPECT_EQ(validation.failure, "MissingOutputQuadLineage");
}

TEST(PureQuadCompletionPhase18,
     GeneratedRectangularVerticesProjectToDistinctSourceLocations) {
  const CompletionFixture fixture = generated_plane_patch();
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 17;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  ASSERT_TRUE(completion.success);
  ASSERT_EQ(9U, completion.mesh.vertices.size());
  ASSERT_EQ(4U, completion.mesh.quads.size());
  std::set<std::pair<long long, long long>> positions;
  for (int row = 0; row < completion.mesh.vertexPositions.rows(); ++row) {
    positions.emplace(
        std::llround(completion.mesh.vertexPositions(row, 0) * 1000000.0),
        std::llround(completion.mesh.vertexPositions(row, 1) * 1000000.0));
  }
  EXPECT_EQ(completion.mesh.vertices.size(), positions.size());
  const auto interior = std::find_if(
      completion.mesh.vertices.begin(), completion.mesh.vertices.end(),
      [](const int vertex) { return vertex < 0; });
  ASSERT_NE(interior, completion.mesh.vertices.end());
  const int row = static_cast<int>(
      std::distance(completion.mesh.vertices.begin(), interior));
  EXPECT_NEAR(0.5, completion.mesh.vertexPositions(row, 0), 1.0e-12);
  EXPECT_NEAR(0.5, completion.mesh.vertexPositions(row, 1), 1.0e-12);
  EXPECT_TRUE(completion.mesh.vertexProvenance[static_cast<std::size_t>(row)]
                  .valid());
}

TEST(PureQuadCompletionPhase18,
     MilestoneEPlaneProducesGeneratedManifoldPureQuadTopology) {
  const CompletionFixture fixture = generated_plane_patch();
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 0;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.success);

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.mesh});
  ASSERT_TRUE(assembly.success) << assembly.failure;
  EXPECT_EQ(1, assembly.connectedComponents);
  EXPECT_EQ(1, assembly.boundaryLoopCount);
  EXPECT_EQ(1, assembly.eulerCharacteristic);
  EXPECT_EQ(4U, assembly.mesh.quads.size());
  EXPECT_FALSE(
      directional::geometry::output_is_only_paired_source_triangle_boundaries(
          assembly.mesh, fixture.faces));
  const auto report = directional::geometry::validate_pure_quad_completion(
      assembly.mesh);
  EXPECT_TRUE(report.pureQuads);
  EXPECT_EQ(0, report.tJunctions);
  EXPECT_EQ(0, report.nonManifoldElements);
  EXPECT_EQ(0, report.degenerateElements);
}


TEST(PureQuadCompletionPhase18,
     SourceSupportResolverUsesIntrinsicVertexAndEdgeIncidence) {
  const CompletionFixture fixture = source_support_alias_patch();
  directional::geometry::SurfacePointSourceSupportResolver resolver(
      fixture.faces);

  const auto vertexSupport =
      resolver.resolve(fixture.patch.boundaryProvenance[0]);
  ASSERT_TRUE(vertexSupport.valid());
  EXPECT_EQ(directional::geometry::SurfacePointSourceEntityKind::SourceVertex,
            vertexSupport.kind);
  EXPECT_EQ(0, vertexSupport.sourceVertex);
  EXPECT_EQ((std::vector<int>{0, 1}), vertexSupport.supportedFaces);

  const auto edgeSupport =
      resolver.resolve(fixture.patch.boundaryProvenance[3]);
  ASSERT_TRUE(edgeSupport.valid());
  EXPECT_EQ(directional::geometry::SurfacePointSourceEntityKind::SourceEdge,
            edgeSupport.kind);
  EXPECT_EQ((std::pair<int, int>{0, 2}), edgeSupport.sourceEdge);
  EXPECT_EQ((std::vector<int>{0, 1}), edgeSupport.supportedFaces);
}

TEST(PureQuadCompletionPhase18,
     CompletionAcceptsBoundaryVertexAndEdgeChartAliases) {
  const CompletionFixture fixture = source_support_alias_patch();
  const std::vector<int> components{0, 0};
  const std::vector<int> sheets{0, 1};
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 27;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  EXPECT_TRUE(completion.success) << completion.failure;
  EXPECT_FALSE(completion.ownershipRejection.active);
}

TEST(PureQuadCompletionPhase18,
     CompletionRejectsFaceInteriorOutsidePatchSupport) {
  CompletionFixture fixture = source_support_alias_patch();
  auto &outside = fixture.patch.boundaryProvenance[0];
  outside.face = 1;
  outside.component = 0;
  outside.sheet = 1;
  outside.barycentric << 0.2, 0.3, 0.5;
  outside.position =
      0.2 * fixture.vertices.row(0).transpose() +
      0.3 * fixture.vertices.row(2).transpose() +
      0.5 * fixture.vertices.row(3).transpose();
  const std::vector<int> components{0, 0};
  const std::vector<int> sheets{0, 1};
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 31;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  EXPECT_FALSE(completion.success);
  EXPECT_TRUE(completion.failure.starts_with(
      "CompletionOwnershipSourceSupportEscape:"));
  EXPECT_TRUE(completion.ownershipRejection.active);
  EXPECT_TRUE(completion.ownershipRejection.boundaryVertex);
  EXPECT_EQ(directional::geometry::SurfacePointSourceEntityKind::FaceInterior,
            completion.ownershipRejection.sourceEntityKind);
}

TEST(PureQuadCompletionPhase18,
     CompletionAcceptsGeneratedInteriorOnEitherPatchFace) {
  const CompletionFixture fixture = generated_plane_patch();
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 36;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.success) << completion.failure;

  const auto interior = std::find_if(
      completion.mesh.vertices.begin(), completion.mesh.vertices.end(),
      [](const int vertex) { return vertex < 0; });
  ASSERT_NE(interior, completion.mesh.vertices.end());
  const std::size_t row = static_cast<std::size_t>(
      std::distance(completion.mesh.vertices.begin(), interior));
  directional::geometry::SurfacePointSourceSupportResolver resolver(
      fixture.faces);
  for (const int allowedFace : fixture.patch.sourceFaces) {
    auto allowedMesh = completion.mesh;
    allowedMesh.vertexProvenance[row].face = allowedFace;
    allowedMesh.vertexProvenance[row].barycentric << 0.2, 0.3, 0.5;
    allowedMesh.vertexLineage[row].sourcePoint =
        allowedMesh.vertexProvenance[row];
    directional::geometry::PureQuadCompletionOwnershipRejection rejection;
    std::string failure;
    EXPECT_TRUE(directional::geometry::pure_quad_detail::
                    validate_completion_domain_ownership(
                        fixture.patch, allowedMesh, 0, &resolver, nullptr,
                        nullptr, failure, &rejection))
        << "allowed face " << allowedFace << ": " << failure;
    EXPECT_FALSE(rejection.active);
  }
}

TEST(PureQuadCompletionPhase18,
     CompletionRejectsGeneratedInteriorOutsidePatchSupport) {
  const CompletionFixture fixture = generated_plane_patch();
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 37;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.success) << completion.failure;

  auto escapedMesh = completion.mesh;
  const auto interior = std::find_if(
      escapedMesh.vertices.begin(), escapedMesh.vertices.end(),
      [](const int vertex) { return vertex < 0; });
  ASSERT_NE(interior, escapedMesh.vertices.end());
  const std::size_t row = static_cast<std::size_t>(
      std::distance(escapedMesh.vertices.begin(), interior));
  escapedMesh.vertexProvenance[row].face = 2;
  escapedMesh.vertexProvenance[row].barycentric << 0.2, 0.3, 0.5;
  escapedMesh.vertexProvenance[row].position =
      0.2 * fixture.vertices.row(4).transpose() +
      0.3 * fixture.vertices.row(5).transpose() +
      0.5 * fixture.vertices.row(6).transpose();
  escapedMesh.vertexLineage[row].sourcePoint =
      escapedMesh.vertexProvenance[row];

  directional::geometry::SurfacePointSourceSupportResolver resolver(
      fixture.faces);
  directional::geometry::PureQuadCompletionOwnershipRejection rejection;
  std::string failure;
  EXPECT_FALSE(directional::geometry::pure_quad_detail::
                   validate_completion_domain_ownership(
                       fixture.patch, escapedMesh, 0, &resolver, nullptr,
                       nullptr, failure, &rejection));
  EXPECT_TRUE(failure.starts_with(
      "CompletionOwnershipSourceSupportEscape:"));
  EXPECT_TRUE(rejection.active);
  EXPECT_FALSE(rejection.boundaryVertex);
}

TEST(PureQuadCompletionPhase18,
     CompletionRejectsComponentSheetMismatchAtSharedSourceEntity) {
  CompletionFixture fixture = source_support_alias_patch();
  fixture.patch.boundarySheets[0] = 7;
  const std::vector<int> components{0, 0};
  const std::vector<int> sheets{0, 1};
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 43;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  options.sourceFaceComponents = &components;
  options.sourceFaceSheets = &sheets;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  EXPECT_FALSE(completion.success);
  EXPECT_TRUE(completion.failure.starts_with(
      "CompletionOwnershipComponentSheetMismatch:"));
  EXPECT_TRUE(completion.ownershipRejection.active);
  EXPECT_EQ(7, completion.ownershipRejection.sourceSheet);
}

TEST(PureQuadCompletionPhase18,
     MilestoneECylinderStitchesPeriodicPatchBoundaries) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  const auto patches = completed_cylinder_patches(vertices, faces);
  ASSERT_EQ(8U, patches.size());

  const auto assembly =
      directional::geometry::stitch_pure_quad_patches(patches);

  ASSERT_TRUE(assembly.success) << assembly.failure;
  EXPECT_EQ(1, assembly.connectedComponents);
  EXPECT_EQ(2, assembly.boundaryLoopCount);
  EXPECT_EQ(0, assembly.eulerCharacteristic);
  EXPECT_EQ(8U, assembly.mesh.quads.size());
  EXPECT_EQ(16U, assembly.mesh.vertices.size());
  EXPECT_GT(assembly.mergedBoundaryVertices, 0);
  const auto report = directional::geometry::validate_pure_quad_completion(
      assembly.mesh);
  EXPECT_TRUE(report.pureQuads);
  EXPECT_EQ(0, report.tJunctions);
  EXPECT_EQ(0, report.nonManifoldElements);
  EXPECT_EQ(0, report.degenerateElements);
}


TEST(PureQuadCompletionPhase18,
     DuplicateStitchedQuadReportsBothAuthoritativeSourcePatches) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 41;
  const auto first = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(first.success);

  directional::geometry::PureQuadMesh second = first.mesh;
  second.sourcePatch = 73;
  for (auto &lineage : second.quadLineage) {
    lineage.sourcePatch = 73;
  }

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.mesh, second});

  EXPECT_FALSE(assembly.success);
  EXPECT_TRUE(assembly.failure.starts_with(
      "DuplicateStitchedQuad:firstPatch=41;firstLocalQuad=0;"
      "secondPatch=73;secondLocalQuad=0;globalVertices=0,1,2,3"));
  EXPECT_NE(std::string::npos,
            assembly.failure.find(";classification="));
  EXPECT_TRUE(assembly.ownershipConflict.active());
}

TEST(PureQuadCompletionPhase18,
     CompletedFaceOwnershipCanonicalizesRotationAndReversal) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 41;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(completion.success);

  auto first = completion.mesh;
  auto second = completion.mesh;
  first.sourcePatch = 41;
  second.sourcePatch = 73;
  assign_distinct_domain_identity(first, 1);
  assign_distinct_domain_identity(second, 2);
  for (auto &lineage : first.quadLineage) {
    lineage.sourcePatch = first.sourcePatch;
  }
  for (auto &lineage : second.quadLineage) {
    lineage.sourcePatch = second.sourcePatch;
  }
  ASSERT_EQ(1U, second.quads.size());
  second.quads[0] = {2, 1, 0, 3};

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first, second});

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                CompletionTemplateOwnership,
            assembly.ownershipConflict.classification);
  EXPECT_EQ(assembly.ownershipConflict.firstCornerIdentityHashes,
            assembly.ownershipConflict.secondCornerIdentityHashes);
  EXPECT_EQ(assembly.ownershipConflict.firstCornerAuthoritativeHashes,
            assembly.ownershipConflict.secondCornerAuthoritativeHashes);
  EXPECT_NE(std::string::npos,
            assembly.failure.find(";firstBackend=closed-form;"));
  EXPECT_NE(std::string::npos,
            assembly.failure.find(";firstCornerKinds=arrangement-node,"));
}


TEST(PureQuadCompletionPhase18,
     SameCornersWithEqualSourceSupportAndDistinctBoundariesAreTyped) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 101;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(completion.success);

  auto first = completion.mesh;
  auto second = completion.mesh;
  first.sourcePatch = 101;
  second.sourcePatch = 202;
  assign_same_support_distinct_boundary_identity(first, 1);
  assign_same_support_distinct_boundary_identity(second, 2);
  first.sourceSideEdgeCounts = {1, 1, 1, 1};
  second.sourceSideEdgeCounts = {2, 1, 1, 2};
  for (auto &lineage : first.quadLineage) {
    lineage.sourcePatch = first.sourcePatch;
  }
  for (auto &lineage : second.quadLineage) {
    lineage.sourcePatch = second.sourcePatch;
  }

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {second, first});

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                SameCornerDistinctBoundaryClaim,
            assembly.ownershipConflict.classification);
  EXPECT_EQ(assembly.ownershipConflict.firstCornerAuthoritativeHashes,
            assembly.ownershipConflict.secondCornerAuthoritativeHashes);
  EXPECT_NE(assembly.ownershipConflict.firstBoundaryHalfedgeHash,
            assembly.ownershipConflict.secondBoundaryHalfedgeHash);
  EXPECT_NE(std::string::npos,
            assembly.failure.find(
                ";classification=same-corner-distinct-boundary;"));
}

TEST(PureQuadCompletionPhase18,
     CompleteOwnershipInventoryReportsIndependentClaimsDeterministically) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 101;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(completion.success);

  auto first = completion.mesh;
  auto second = completion.mesh;
  auto third = completion.mesh;
  auto fourth = completion.mesh;
  first.sourcePatch = 101;
  second.sourcePatch = 202;
  third.sourcePatch = 303;
  fourth.sourcePatch = 404;
  assign_same_support_distinct_boundary_identity(first, 1);
  assign_same_support_distinct_boundary_identity(second, 2);
  assign_same_support_distinct_boundary_identity(third, 3);
  assign_same_support_distinct_boundary_identity(fourth, 4);
  for (auto *mesh : {&first, &second, &third, &fourth}) {
    for (auto &lineage : mesh->quadLineage) {
      lineage.sourcePatch = mesh->sourcePatch;
    }
  }
  for (auto *mesh : {&third, &fourth}) {
    for (int row = 0; row < static_cast<int>(mesh->vertexLineage.size());
         ++row) {
      auto &lineage = mesh->vertexLineage[static_cast<std::size_t>(row)];
      lineage.stitchIdentity.canonical.values.push_back(700 + row);
      lineage.authoritativeIdentity.canonical.values.push_back(700 + row);
    }
  }

  const auto forward = directional::geometry::stitch_pure_quad_patches(
      {first, second, third, fourth});
  const auto reordered = directional::geometry::stitch_pure_quad_patches(
      {fourth, second, first, third});

  ASSERT_FALSE(forward.success);
  ASSERT_EQ(2U, forward.ownershipConflicts.size());
  EXPECT_EQ(forward.ownershipConflicts, reordered.ownershipConflicts);
  EXPECT_EQ(forward.ownershipConflict, forward.ownershipConflicts.front());
  for (const auto &conflict : forward.ownershipConflicts) {
    EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                  SameCornerDistinctBoundaryClaim,
              conflict.classification);
    EXPECT_NE(0U, conflict.exact_hash());
    EXPECT_NE(conflict.firstOwner.domain.undirectedBoundary,
              conflict.secondOwner.domain.undirectedBoundary);
  }
}

TEST(PureQuadCompletionPhase18,
     UnderQualifiedStitchIdentityIsClassifiedAsFalseMerge) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 101;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(completion.success);

  auto first = completion.mesh;
  auto second = completion.mesh;
  first.sourcePatch = 101;
  second.sourcePatch = 205;
  assign_distinct_domain_identity(first, 3);
  assign_distinct_domain_identity(second, 4);
  for (auto &lineage : first.quadLineage) {
    lineage.sourcePatch = first.sourcePatch;
  }
  for (auto &lineage : second.quadLineage) {
    lineage.sourcePatch = second.sourcePatch;
  }
  for (int row = 0; row < static_cast<int>(second.vertexLineage.size()); ++row) {
    auto &authoritative =
        second.vertexLineage[static_cast<std::size_t>(row)]
            .authoritativeIdentity;
    authoritative.canonical.values.push_back(900 + row);
  }

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first, second});

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                FalseVertexEquivalence,
            assembly.ownershipConflict.classification);
  EXPECT_EQ(assembly.ownershipConflict.firstCornerIdentityHashes,
            assembly.ownershipConflict.secondCornerIdentityHashes);
  EXPECT_NE(assembly.ownershipConflict.firstCornerAuthoritativeHashes,
            assembly.ownershipConflict.secondCornerAuthoritativeHashes);
  EXPECT_NE(std::string::npos,
            assembly.failure.find(";classification=false-merge;"));
}

TEST(PureQuadCompletionPhase18,
     CompletionOwnershipClassificationIsPatchOrderInvariant) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 301;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(completion.success);

  auto first = completion.mesh;
  auto second = completion.mesh;
  first.sourcePatch = 301;
  second.sourcePatch = 509;
  assign_distinct_domain_identity(first, 5);
  assign_distinct_domain_identity(second, 6);
  for (auto &lineage : first.quadLineage) {
    lineage.sourcePatch = first.sourcePatch;
  }
  for (auto &lineage : second.quadLineage) {
    lineage.sourcePatch = second.sourcePatch;
  }

  const auto forward = directional::geometry::stitch_pure_quad_patches(
      {first, second});
  const auto reverse = directional::geometry::stitch_pure_quad_patches(
      {second, first});

  EXPECT_FALSE(forward.success);
  EXPECT_FALSE(reverse.success);
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                CompletionTemplateOwnership,
            forward.ownershipConflict.classification);
  EXPECT_EQ(forward.ownershipConflict.classification,
            reverse.ownershipConflict.classification);
  EXPECT_EQ(forward.failure, reverse.failure);
}

TEST(PureQuadCompletionPhase18,
     StitchingRejectsInconsistentSharedBoundaryGeometry) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto shared = std::find(patches[1].vertices.begin(),
                                patches[1].vertices.end(), 1);
  ASSERT_NE(shared, patches[1].vertices.end());
  const int row =
      static_cast<int>(std::distance(patches[1].vertices.begin(), shared));
  patches[1].vertexPositions(row, 0) += 0.25;

  const auto assembly =
      directional::geometry::stitch_pure_quad_patches(patches);

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InconsistentSharedBoundaryPosition", assembly.failure);
}


TEST(PureQuadCompletionPhase18,
     CoincidentPositionsOnDistinctSheetsDoNotMerge) {
  auto firstPatch = patch({1, 1, 1, 1});
  auto secondPatch = firstPatch;
  for (auto &point : firstPatch.boundaryProvenance) {
    point.component = 7;
    point.sheet = 11;
  }
  for (auto &point : secondPatch.boundaryProvenance) {
    point.component = 7;
    point.sheet = 19;
  }
  directional::geometry::PureQuadCompletionOptions firstOptions;
  firstOptions.sourcePatch = 101;
  directional::geometry::PureQuadCompletionOptions secondOptions;
  secondOptions.sourcePatch = 205;
  const auto first = directional::geometry::complete_pure_quad_patch(
      firstPatch, firstOptions);
  const auto second = directional::geometry::complete_pure_quad_patch(
      secondPatch, secondOptions);
  ASSERT_TRUE(first.success);
  ASSERT_TRUE(second.success);

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.mesh, second.mesh});

  ASSERT_TRUE(assembly.success) << assembly.failure;
  EXPECT_EQ(8U, assembly.mesh.vertices.size());
  EXPECT_EQ(2U, assembly.mesh.quads.size());
  EXPECT_EQ(2, assembly.connectedComponents);
  EXPECT_EQ(0, assembly.mergedBoundaryVertices);
}

TEST(PureQuadCompletionPhase18,
     CoincidentGeneratedInteriorsRemainPatchLocal) {
  directional::geometry::PureQuadCompletionOptions firstOptions;
  firstOptions.sourcePatch = 301;
  directional::geometry::PureQuadCompletionOptions secondOptions;
  secondOptions.sourcePatch = 509;
  const auto first = directional::geometry::complete_pure_quad_patch(
      patch({2, 2, 2, 2}), firstOptions);
  const auto second = directional::geometry::complete_pure_quad_patch(
      patch({2, 2, 2, 2}), secondOptions);
  ASSERT_TRUE(first.success);
  ASSERT_TRUE(second.success);

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.mesh, second.mesh});

  ASSERT_TRUE(assembly.success) << assembly.failure;
  const int expected = static_cast<int>(first.mesh.vertices.size() +
                                        second.mesh.vertices.size() -
                                        first.mesh.boundaryVertices.size());
  EXPECT_EQ(expected, static_cast<int>(assembly.mesh.vertices.size()));
}

TEST(PureQuadCompletionPhase18, StitchingIsPatchOrderInvariant) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto forward =
      directional::geometry::stitch_pure_quad_patches(patches);
  std::reverse(patches.begin(), patches.end());
  const auto reverse =
      directional::geometry::stitch_pure_quad_patches(patches);
  ASSERT_TRUE(forward.success) << forward.failure;
  ASSERT_TRUE(reverse.success) << reverse.failure;
  EXPECT_EQ(forward.mesh.quads, reverse.mesh.quads);
  EXPECT_TRUE(forward.mesh.vertexPositions.isApprox(
      reverse.mesh.vertexPositions, 0.0));
  EXPECT_EQ(forward.eulerCharacteristic, reverse.eulerCharacteristic);
  EXPECT_EQ(forward.boundaryLoopCount, reverse.boundaryLoopCount);
}
