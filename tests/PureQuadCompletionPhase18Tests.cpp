#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <numbers>
#include <set>
#include <vector>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

namespace {

const std::set<directional::authority::SourceEdgeTopologyKey> &no_hard_feature_edges() {
  static const std::set<directional::authority::SourceEdgeTopologyKey> edges;
  return edges;
}

directional::geometry::SourceTopologyRegions test_source_authority(
    const Eigen::MatrixXi &faces, const std::vector<int> &components,
    const std::vector<int> &sheets) {
  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.sourceFaceComponents = components;
  tracing.sourceFaceSheets = sheets;
  auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, tracing);
  if (!authority.has_value()) {
    throw std::runtime_error("Failed to construct typed test source authority.");
  }
  return std::move(*authority);
}

auto test_topology_region_id(const int value) {
  const auto id = directional::authority::TopologyRegionId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) {
    throw std::runtime_error("Invalid test topology-region ID.");
  }
  return id.value();
}

auto test_ownership_class_id(const int value) {
  const auto id =
      directional::authority::SurfaceCellOwnershipClassId::from_index(
          value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) {
    throw std::runtime_error("Invalid test ownership-class ID.");
  }
  return id.value();
}

directional::authority::SourceVertexId checked_source_vertex_id(
    const int value, const std::size_t extent) {
  const auto id = directional::authority::SourceVertexId::from_index(value, extent);
  if (!id) throw std::runtime_error("Invalid checked test source-vertex ID.");
  return id.value();
}

directional::authority::SourceFaceId checked_source_face_id(
    const int value, const std::size_t extent) {
  const auto id = directional::authority::SourceFaceId::from_index(value, extent);
  if (!id) throw std::runtime_error("Invalid checked test source-face ID.");
  return id.value();
}

std::array<directional::authority::SourceVertexId, 3>
checked_source_face_vertices(const Eigen::MatrixXi &faces, const int face) {
  if (faces.cols() != 3 || face < 0 || face >= faces.rows() || faces.size() == 0) {
    throw std::runtime_error("Invalid checked test source face.");
  }
  const int maximum = faces.maxCoeff();
  if (maximum < 0) throw std::runtime_error("Negative test source vertex.");
  const std::size_t extent = static_cast<std::size_t>(maximum) + 1U;
  return {checked_source_vertex_id(faces(face, 0), extent),
          checked_source_vertex_id(faces(face, 1), extent),
          checked_source_vertex_id(faces(face, 2), extent)};
}

directional::geometry::SourceProjectionChart test_source_chart(
    const Eigen::MatrixXi &faces,
    const directional::geometry::SourceTopologyRegions &authority,
    const int sourceFace) {
  directional::geometry::SourceChartTransitionGraph graph(
      &faces, &authority, no_hard_feature_edges());
  const auto chart = graph.chart(sourceFace);
  if (!chart.has_value()) {
    throw std::runtime_error("Failed to construct typed test source chart.");
  }
  return chart.value();
}

void assign_test_boundary_node_identities(
    directional::geometry::PureQuadPatch &patch, const int ownerToken = 7001) {
  patch.boundaryNodeIdentities.resize(patch.boundaryVertices.size());
  for (std::size_t index = 0; index < patch.boundaryVertices.size(); ++index) {
    auto &identity = patch.boundaryNodeIdentities[index];
    identity.valid = true;
    identity.values = {ownerToken, patch.boundaryVertices[index]};
  }
}

void assign_patch_boundary_authority(
    directional::geometry::PureQuadPatch &patch, const Eigen::MatrixXi &faces,
    const directional::geometry::SourceTopologyRegions &authority,
    const std::vector<int> &sourceFaces) {
  if (sourceFaces.size() != patch.boundaryVertices.size()) {
    throw std::runtime_error("Test patch source-scope size mismatch.");
  }
  patch.boundaryTopologyRegions.clear();
  patch.boundaryCharts.clear();
  for (const int sourceFace : sourceFaces) {
    const auto row = directional::authority::SourceFaceId::from_index(
        sourceFace, authority.face_count());
    if (!row) {
      throw std::runtime_error("Invalid test patch source face.");
    }
    patch.boundaryTopologyRegions.push_back(
        authority.region_for_row(row.value()));
    patch.boundaryCharts.push_back(
        test_source_chart(faces, authority, sourceFace));
  }
  assign_test_boundary_node_identities(patch);
}

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
  assign_test_boundary_node_identities(p);
  return p;
}

directional::geometry::PureQuadPatch embedded_patch(std::vector<int> sides) {
  auto p = patch(std::move(sides));
  p.boundaryProvenance.clear();
  const int count = static_cast<int>(p.boundaryVertices.size());
  for (int i = 0; i < count; ++i) {
    directional::geometry::SurfacePoint point;
    point.face = 7;
    point.component = 2;
    point.sheet = 3;
    const double angle = 2.0 * std::numbers::pi * static_cast<double>(i) /
                         static_cast<double>(count);
    point.position << std::cos(angle), std::sin(angle), 1.0;
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
  const auto authority =
      test_source_authority(fixture.faces, {0, 0, 1}, {0, 0, 1});
  std::vector<int> boundaryFaces;
  boundaryFaces.reserve(fixture.patch.boundaryProvenance.size());
  for (const auto &point : fixture.patch.boundaryProvenance) {
    boundaryFaces.push_back(point.face);
  }
  assign_patch_boundary_authority(fixture.patch, fixture.faces, authority,
                                  boundaryFaces);
  return fixture;
}

void assign_distinct_domain_identity(
    directional::geometry::PureQuadMesh &mesh, const int token) {
  auto &identity = mesh.domainIdentity;
  identity.valid = true;
  identity.sourceTopologyRegion = test_topology_region_id(3);
  identity.sourceOwnershipClass = test_ownership_class_id(3);
  identity.sourceChartMap.valid = true;
  identity.sourceChartMap.values = {503, 5};
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
  identity.sourceTopologyRegion = test_topology_region_id(3);
  identity.sourceOwnershipClass = test_ownership_class_id(3);
  identity.sourceChartMap.valid = true;
  identity.sourceChartMap.values = {503, 5};
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
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
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
    std::vector<int> boundaryFaces;
    boundaryFaces.reserve(cylinderPatch.boundaryProvenance.size());
    for (const auto &point : cylinderPatch.boundaryProvenance) {
      boundaryFaces.push_back(point.face);
    }
    assign_patch_boundary_authority(cylinderPatch, faces, sourceAuthority,
                                    boundaryFaces);
    directional::geometry::PureQuadCompletionOptions options;
    options.sourcePatch = segment;
    options.sourceVertices = &vertices;
    options.sourceFaces = &faces;
    options.sourceAuthority = &sourceAuthority;
    const auto completion =
        directional::geometry::complete_pure_quad_patch(cylinderPatch, options);
    if (!completion.is_produced()) {
      return {};
    }
    patches.push_back(completion.product());
  }
  return patches;
}

directional::geometry::PureQuadMesh completed_typed_single_quad(
    const Eigen::MatrixXi &faces,
    const directional::geometry::SourceTopologyRegions &sourceAuthority,
    const int sourcePatch) {
  auto typedPatch = patch({1, 1, 1, 1});
  typedPatch.sourceFaces = {0};
  assign_patch_boundary_authority(typedPatch, faces, sourceAuthority,
                                  {0, 0, 0, 0});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = sourcePatch;
  options.sourceFaces = &faces;
  options.sourceAuthority = &sourceAuthority;
  const auto completion =
      directional::geometry::complete_pure_quad_patch(typedPatch, options);
  if (!completion.is_produced()) {
    const auto *failure = completion.rejection();
    throw std::runtime_error(
        "Failed to construct typed single-quad fixture: " +
        (failure == nullptr ? std::string("MissingOutcome")
                            : failure->detail));
  }
  return completion.product();
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
  const auto authority =
      test_source_authority(fixture.faces, {0, 0}, {0, 1});
  assign_patch_boundary_authority(fixture.patch, fixture.faces, authority,
                                  {0, 0, 0, 0});
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
  ASSERT_TRUE(quad.is_produced());
  EXPECT_EQ(quad.product().backend,
            directional::geometry::PureQuadCompletionBackend::ClosedForm);
  EXPECT_EQ(quad.product().quads.size(), 4U);

  const auto tri = directional::geometry::complete_pure_quad_patch(patch({2, 2, 2}));
  ASSERT_TRUE(tri.is_produced());
  EXPECT_EQ(tri.product().quads.size(), 2U);

  const auto pent =
      directional::geometry::complete_pure_quad_patch(patch({2, 1, 1, 1, 1}));
  ASSERT_TRUE(pent.is_produced());
  EXPECT_EQ(pent.product().quads.size(), 2U);

  const auto hex =
      directional::geometry::complete_pure_quad_patch(patch({1, 1, 1, 1, 1, 1}));
  ASSERT_TRUE(hex.is_produced());
  EXPECT_EQ(hex.product().quads.size(), 2U);
}

TEST(PureQuadCompletionPhase18, PatternFallbackCompletesValidNonSimplePatch) {
  auto p = patch({2, 2, 2, 1, 1});
  p.simple = false;
  const auto result = directional::geometry::complete_pure_quad_patch(p);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.product().backend,
            directional::geometry::PureQuadCompletionBackend::BoundedCombinatorial);
  EXPECT_GT(result.exploredPatterns, 0);
  EXPECT_TRUE(std::all_of(result.product().quads.begin(), result.product().quads.end(),
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
                                                                 disabled).is_produced());

    directional::geometry::PureQuadCompletionOptions enabled;
    enabled.allowBoundedCombinatorialFallback = true;
    const auto completed =
        directional::geometry::complete_pure_quad_patch(candidate, enabled);
    ASSERT_TRUE(completed.is_produced());
    EXPECT_EQ(completed.product().backend,
              directional::geometry::PureQuadCompletionBackend::
                  BoundedCombinatorial);
    EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(
        completed.product()));
  }
}

TEST(PureQuadCompletionPhase18, CompletionDoesNotUseSharedCenterFan) {
  const auto completion =
      directional::geometry::complete_pure_quad_patch(patch({2, 2, 2}));
  ASSERT_TRUE(completion.is_produced());
  EXPECT_FALSE(completion.product().usesCenterFan);

  std::map<int, int> interiorUseCount;
  for (const auto &quad : completion.product().quads) {
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
                            static_cast<int>(completion.product().quads.size());
                   });
  EXPECT_EQ(sharedByEveryQuad, interiorUseCount.end());
}

TEST(PureQuadCompletionPhase18, CompletionVerticesCarrySourceProvenance) {
  const auto completion = directional::geometry::complete_pure_quad_patch(
      embedded_patch({2, 2, 2}));
  ASSERT_TRUE(completion.is_produced());
  ASSERT_EQ(completion.product().vertexProvenance.size(),
            completion.product().vertices.size());
  ASSERT_EQ(completion.product().vertexPositions.rows(),
            static_cast<int>(completion.product().vertices.size()));
  for (const auto &point : completion.product().vertexProvenance) {
    EXPECT_TRUE(point.valid());
    EXPECT_EQ(point.component, 2);
    EXPECT_EQ(point.sheet, 3);
  }
  EXPECT_NEAR(completion.product().vertexPositions(0, 2), 1.0, 1.0e-12);
}

TEST(PureQuadCompletionPhase18, ZigZagBoundaryFailsEmbeddingValidation) {
  auto invalid = embedded_patch({2, 2, 2});
  for (int i = 0; i < static_cast<int>(invalid.boundaryProvenance.size()); ++i) {
    invalid.boundaryProvenance[static_cast<std::size_t>(i)].position <<
        static_cast<double>(i), static_cast<double>(i % 2), 1.0;
  }
  const auto completion =
      directional::geometry::complete_pure_quad_patch(invalid);
  EXPECT_TRUE(completion.is_rejected());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_EQ(completion.rejection()->detail.rfind(
                "InvalidCompletionQuadEmbedding", 0),
            0U);
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
  ASSERT_TRUE(completion.is_produced());

  const auto report = directional::geometry::validate_pure_quad_completion(
      completion.product(), {3, 5, 6, 4, 3, 5, 3, 5, 3, 5, 3}, {}, true);

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
  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.product().backend,
            directional::geometry::PureQuadCompletionBackend::TransitionTemplate);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.product()));
  EXPECT_EQ(result.product().quads.size(), 2U);
}

TEST(PureQuadCompletionPhase18, GeneralPatternPreservesEntireBoundary) {
  const auto result = directional::geometry::complete_pure_quad_patch(
      patch({2, 2, 2, 1, 1}));
  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.product().backend,
            directional::geometry::PureQuadCompletionBackend::Pattern);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.product()));
  EXPECT_EQ(result.product().quads.size(), 3U);
}

TEST(PureQuadCompletionPhase18,
     BalancedPatternCompletesManySidedRegularDiskWithoutBoundaryFan) {
  const auto candidate = patch(std::vector<int>(14, 2));
  const auto admissibility =
      directional::geometry::check_pure_quad_patch_admissibility(candidate);
  ASSERT_TRUE(admissibility.admissible);

  const auto result =
      directional::geometry::complete_pure_quad_patch(candidate);
  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.product().backend,
            directional::geometry::PureQuadCompletionBackend::Pattern);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.product()));
  ASSERT_EQ(result.product().quads.size(), 13U);
  EXPECT_EQ(result.product().vertices, candidate.boundaryVertices);

  std::set<std::pair<int, int>> expectedBoundary;
  for (int index = 0;
       index < static_cast<int>(candidate.boundaryVertices.size()); ++index) {
    expectedBoundary.insert(std::minmax(
        candidate.boundaryVertices[static_cast<std::size_t>(index)],
        candidate.boundaryVertices[static_cast<std::size_t>(
            (index + 1) % candidate.boundaryVertices.size())]));
  }
  EXPECT_EQ(directional::geometry::pure_quad_detail::boundary_edges(
                result.product().quads),
            expectedBoundary);

  const auto valences =
      directional::geometry::pure_quad_detail::vertex_valences(
          result.product().quads);
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
  EXPECT_TRUE(result.is_rejected());
  EXPECT_EQ(nullptr, result.produced_product());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(directional::geometry::PureQuadPatchRejectReason::MissingBoundaryData,
            result.rejection()->reason);
}

TEST(PureQuadCompletionPhase18, BoundedFallbackHonorsSearchLimit) {
  auto p = patch({2, 2, 2, 1, 1});
  p.simple = false;
  directional::geometry::PureQuadCompletionOptions options;
  options.maxBoundaryEdges = 6;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  EXPECT_TRUE(result.is_rejected());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(result.rejection()->reason,
            directional::geometry::PureQuadPatchRejectReason::SearchLimitExceeded);
}

TEST(PureQuadCompletionPhase18, SingularityCompletionUsesPoleTemplate) {
  auto p = patch({2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = 1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  EXPECT_TRUE(result.is_produced());
  EXPECT_EQ(result.product().backend,
            directional::geometry::PureQuadCompletionBackend::PoleTemplate);
}

TEST(PureQuadCompletionPhase18, P17BuildsValenceThreeSingularityPole) {
  auto p = patch({2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = 1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.product().backend,
            directional::geometry::PureQuadCompletionBackend::PoleTemplate);
  ASSERT_EQ(result.product().quads.size(), 3U);
  const int pole = result.product().quads.front().front();
  const auto valences =
      directional::geometry::pure_quad_detail::vertex_valences(result.product().quads);
  ASSERT_TRUE(valences.count(pole));
  EXPECT_EQ(valences.at(pole), 3);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.product()));
}

TEST(PureQuadCompletionPhase18, P17BuildsValenceFiveSingularityPole) {
  auto p = patch({2, 2, 2, 2, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = -1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(result.product().quads.size(), 5U);
  const int pole = result.product().quads.front().front();
  const auto valences =
      directional::geometry::pure_quad_detail::vertex_valences(result.product().quads);
  EXPECT_EQ(valences.at(pole), 5);
  EXPECT_TRUE(directional::geometry::pure_quad_topology_is_disk(result.product()));
}

TEST(PureQuadCompletionPhase18, P17PoleTemplateFailsClosedForWrongBoundaryPattern) {
  auto p = patch({1, 1, 1, 1, 2});
  p.singularityCount = 1;
  p.singularIndexNumerator = -1;
  const auto result = directional::geometry::complete_pure_quad_patch(p);
  EXPECT_TRUE(result.is_rejected());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(result.rejection()->reason,
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
  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(result.product().quadLineage.size(), result.product().quads.size());
  for (int q = 0; q < static_cast<int>(result.product().quadLineage.size()); ++q) {
    const auto &lineage = result.product().quadLineage[static_cast<std::size_t>(q)];
    EXPECT_TRUE(lineage.valid());
    EXPECT_EQ(lineage.outputQuad, q);
    EXPECT_EQ(lineage.sourcePatch, 42);
    EXPECT_EQ(lineage.operation,
              directional::geometry::PureQuadCompletionBackend::ClosedForm);
  }
}

TEST(PureQuadCompletionPhase18, P18MapsBoundaryFeatureVerticesToOrderedIntervals) {
  auto p = patch({1, 1, 1, 1});
  p.boundaryRailIds.assign(
      p.boundaryVertices.size(), directional::tests::test_hard_rail_id(7));
  p.boundaryCurveIds.assign(p.boundaryVertices.size(), 11);
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 3;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(result.product().vertexLineage.size(), result.product().vertices.size());
  for (const auto &lineage : result.product().vertexLineage) {
    EXPECT_TRUE(lineage.valid());
    EXPECT_EQ(lineage.kind,
              directional::geometry::PureQuadVertexLineageKind::OrderedFeatureInterval);
    EXPECT_EQ(lineage.featureInterval.railId,
              directional::tests::test_hard_rail_id(7));
    EXPECT_EQ(lineage.featureInterval.curveId, 11);
  }
}

TEST(PureQuadCompletionPhase18, P18GeneratedInteriorVertexHasSourceTriangleLineage) {
  auto p = patch({2, 2, 2, 2});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 5;
  const auto result = directional::geometry::complete_pure_quad_patch(p, options);
  ASSERT_TRUE(result.is_produced());
  const auto generated = std::find_if(
      result.product().vertexLineage.begin(), result.product().vertexLineage.end(),
      [](const auto &lineage) { return lineage.outputVertex < 0; });
  ASSERT_NE(generated, result.product().vertexLineage.end());
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
  ASSERT_TRUE(result.is_produced());
  result.product().quadLineage.clear();
  Eigen::MatrixXi F(1, 3);
  F << 0, 1, 2;
  const auto validation =
      directional::geometry::validate_pure_quad_output_lineage(result.product(), F, false);
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
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  options.sourceAuthority = &sourceAuthority;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  ASSERT_TRUE(completion.is_produced());
  ASSERT_EQ(9U, completion.product().vertices.size());
  ASSERT_EQ(4U, completion.product().quads.size());
  std::set<std::pair<long long, long long>> positions;
  for (int row = 0; row < completion.product().vertexPositions.rows(); ++row) {
    positions.emplace(
        std::llround(completion.product().vertexPositions(row, 0) * 1000000.0),
        std::llround(completion.product().vertexPositions(row, 1) * 1000000.0));
  }
  EXPECT_EQ(completion.product().vertices.size(), positions.size());
  const auto interior = std::find_if(
      completion.product().vertices.begin(), completion.product().vertices.end(),
      [](const int vertex) { return vertex < 0; });
  ASSERT_NE(interior, completion.product().vertices.end());
  const int row = static_cast<int>(
      std::distance(completion.product().vertices.begin(), interior));
  EXPECT_NEAR(0.5, completion.product().vertexPositions(row, 0), 1.0e-12);
  EXPECT_NEAR(0.5, completion.product().vertexPositions(row, 1), 1.0e-12);
  EXPECT_TRUE(completion.product().vertexProvenance[static_cast<std::size_t>(row)]
                  .valid());
}

TEST(PureQuadCompletionPhase18,
     MilestoneEPlaneProducesGeneratedManifoldPureQuadTopology) {
  const CompletionFixture fixture = generated_plane_patch();
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 0;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  options.sourceAuthority = &sourceAuthority;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.is_produced());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &fixture.faces, &sourceAuthority, &no_hard_feature_edges());
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


TEST(SurfaceCellSourceSupportAndChartAuthority,
     SourceSupportVariantsAreDistinctAndMalformedSupportFailsTyped) {
  const CompletionFixture fixture = source_support_alias_patch();
  directional::geometry::SurfacePointSourceSupportResolver resolver(
      fixture.faces);

  const auto vertexSupport =
      resolver.resolve(fixture.patch.boundaryProvenance[0]);
  ASSERT_TRUE(vertexSupport.valid());
  ASSERT_TRUE(vertexSupport.identity.has_value());
  const auto *vertex =
      std::get_if<directional::authority::SourceVertexSupport>(
          &vertexSupport.identity.value());
  ASSERT_NE(nullptr, vertex);
  const std::size_t vertexExtent =
      static_cast<std::size_t>(fixture.faces.maxCoeff()) + 1U;
  const std::size_t faceExtent = static_cast<std::size_t>(fixture.faces.rows());
  EXPECT_EQ(checked_source_vertex_id(0, vertexExtent), vertex->vertex);
  ASSERT_EQ(2U, vertexSupport.incidentFaces.size());
  EXPECT_EQ(checked_source_face_id(0, faceExtent), vertexSupport.incidentFaces[0]);
  EXPECT_EQ(checked_source_face_id(1, faceExtent), vertexSupport.incidentFaces[1]);

  const auto edgeSupport =
      resolver.resolve(fixture.patch.boundaryProvenance[3]);
  ASSERT_TRUE(edgeSupport.valid());
  ASSERT_TRUE(edgeSupport.identity.has_value());
  const auto *edge = std::get_if<directional::authority::SourceEdgeSupport>(
      &edgeSupport.identity.value());
  ASSERT_NE(nullptr, edge);
  EXPECT_EQ(checked_source_vertex_id(0, vertexExtent), edge->edge.first());
  EXPECT_EQ(checked_source_vertex_id(2, vertexExtent), edge->edge.second());
  ASSERT_EQ(2U, edgeSupport.incidentFaces.size());
  EXPECT_EQ(checked_source_face_id(0, faceExtent), edgeSupport.incidentFaces[0]);
  EXPECT_EQ(checked_source_face_id(1, faceExtent), edgeSupport.incidentFaces[1]);

  directional::geometry::SurfacePoint faceInterior;
  faceInterior.face = 0;
  faceInterior.component = 0;
  faceInterior.sheet = 0;
  faceInterior.barycentric << 0.2, 0.3, 0.5;
  const auto faceSupport = resolver.resolve(faceInterior);
  ASSERT_TRUE(faceSupport.valid());
  ASSERT_TRUE(faceSupport.identity.has_value());
  const auto *face =
      std::get_if<directional::authority::SourceFaceInteriorSupport>(
          &faceSupport.identity.value());
  ASSERT_NE(nullptr, face);
  std::array<directional::authority::SourceVertexId, 3> sourceVertices{
      directional::authority::SourceVertexId::from_index(0, 4).value(),
      directional::authority::SourceVertexId::from_index(1, 4).value(),
      directional::authority::SourceVertexId::from_index(2, 4).value()};
  const auto sourceTopology =
      directional::authority::SourceFaceTopologyKey::make(sourceVertices);
  ASSERT_TRUE(sourceTopology.has_value());
  EXPECT_EQ(sourceTopology.value(), face->face);
  EXPECT_NE(vertexSupport.identity, edgeSupport.identity);
  EXPECT_NE(vertexSupport.identity, faceSupport.identity);
  EXPECT_NE(edgeSupport.identity, faceSupport.identity);

  faceInterior.face = fixture.faces.rows();
  const auto malformed = resolver.resolve(faceInterior);
  EXPECT_FALSE(malformed.valid());
  EXPECT_FALSE(malformed.identity.has_value());
  EXPECT_EQ(directional::geometry::SurfacePointSourceSupportFailure::
                InvalidSourceFace,
            malformed.failure);
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
  const auto sourceAuthority =
      test_source_authority(fixture.faces, components, sheets);
  options.sourceAuthority = &sourceAuthority;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  EXPECT_TRUE(completion.is_produced());
  EXPECT_EQ(nullptr, completion.rejection());
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
  const auto sourceAuthority =
      test_source_authority(fixture.faces, components, sheets);
  options.sourceAuthority = &sourceAuthority;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  EXPECT_TRUE(completion.is_rejected());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_TRUE(completion.rejection()->detail.starts_with(
      "CompletionOwnershipSourceSupportEscape:"));
  EXPECT_TRUE(completion.rejection()->ownershipRejection.active);
  EXPECT_TRUE(completion.rejection()->ownershipRejection.boundaryVertex);
  ASSERT_TRUE(
      completion.rejection()->ownershipRejection.sourceSupport.has_value());
  EXPECT_TRUE(std::holds_alternative<
              directional::authority::SourceFaceInteriorSupport>(
      completion.rejection()->ownershipRejection.sourceSupport.value()));
}

TEST(PureQuadCompletionPhase18,
     CompletionAcceptsGeneratedInteriorOnEitherPatchFace) {
  const CompletionFixture fixture = generated_plane_patch();
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 36;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  options.sourceAuthority = &sourceAuthority;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.is_produced());

  const auto interior = std::find_if(
      completion.product().vertices.begin(), completion.product().vertices.end(),
      [](const int vertex) { return vertex < 0; });
  ASSERT_NE(interior, completion.product().vertices.end());
  const std::size_t row = static_cast<std::size_t>(
      std::distance(completion.product().vertices.begin(), interior));
  directional::geometry::SurfacePointSourceSupportResolver resolver(
      fixture.faces);
  for (const int allowedFace : fixture.patch.sourceFaces) {
    auto allowedMesh = completion.product();
    allowedMesh.vertexProvenance[row].face = allowedFace;
    allowedMesh.vertexProvenance[row].barycentric << 0.2, 0.3, 0.5;
    allowedMesh.vertexLineage[row].sourcePoint =
        allowedMesh.vertexProvenance[row];
    directional::geometry::PureQuadCompletionOwnershipRejection rejection;
    std::string failure;
    EXPECT_TRUE(directional::geometry::pure_quad_detail::
                    validate_completion_domain_ownership(
                        fixture.patch, allowedMesh, 0, &resolver,
                        &fixture.faces, &sourceAuthority, failure, &rejection, &no_hard_feature_edges()))
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
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  options.sourceAuthority = &sourceAuthority;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.is_produced());

  auto escapedMesh = completion.product();
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
                       fixture.patch, escapedMesh, 0, &resolver,
                       &fixture.faces, &sourceAuthority, failure, &rejection, &no_hard_feature_edges()));
  EXPECT_TRUE(failure.starts_with(
      "CompletionOwnershipSourceSupportEscape:"));
  EXPECT_TRUE(rejection.active);
  EXPECT_FALSE(rejection.boundaryVertex);
}

TEST(PureQuadCompletionPhase18,
     CompletionRejectsComponentSheetMismatchAtSharedSourceEntity) {
  CompletionFixture fixture = source_support_alias_patch();
  fixture.patch.boundaryTopologyRegions[0] = test_topology_region_id(7);
  const std::vector<int> components{0, 0};
  const std::vector<int> sheets{0, 1};
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 43;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  const auto sourceAuthority =
      test_source_authority(fixture.faces, components, sheets);
  options.sourceAuthority = &sourceAuthority;

  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);

  EXPECT_TRUE(completion.is_rejected());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_TRUE(completion.rejection()->detail.starts_with(
      "CompletionOwnershipComponentSheetMismatch:"));
  EXPECT_TRUE(completion.rejection()->ownershipRejection.active);
  EXPECT_EQ("CompletionOwnershipComponentSheetMismatch",
            completion.rejection()->ownershipRejection.failure);
}

TEST(PureQuadCompletionPhase18,
     MilestoneECylinderStitchesPeriodicPatchBoundaries) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  const auto patches = completed_cylinder_patches(vertices, faces);
  ASSERT_EQ(8U, patches.size());

  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

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
     SameExtentForeignSourceAuthorityRejectsStitchPublication) {
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  const auto completed =
      completed_typed_single_quad(sourceFaces, sourceAuthority, 17);

  Eigen::MatrixXi foreignFaces(1, 3);
  foreignFaces << 0, 1, 3;
  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completed}, 1.0e-9, &foreignFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("MissingSourceAuthority", assembly.failure);
}

TEST(PureQuadCompletionPhase18,
     DuplicateStitchedQuadReportsBothAuthoritativeSourcePatches) {
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  auto first = completed_typed_single_quad(sourceFaces, sourceAuthority, 41);
  auto second = first;
  second.sourcePatch = 73;
  for (auto &lineage : second.quadLineage) {
    lineage.sourcePatch = 73;
  }

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first, second}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_TRUE(assembly.failure.starts_with(
      "DuplicateStitchedQuad:firstPatch=41;firstLocalQuad=0;"
      "secondPatch=73;secondLocalQuad=0;globalVertices=0,1,2,3"));
  EXPECT_NE(std::string::npos, assembly.failure.find(";classification="));
  EXPECT_TRUE(assembly.ownershipConflict.active());
}

TEST(PureQuadCompletionPhase18,
     CompletedFaceOwnershipCanonicalizesRotationAndReversal) {
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  auto first = completed_typed_single_quad(sourceFaces, sourceAuthority, 41);
  auto second = first;
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
      {first, second}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
  EXPECT_GT(assembly.estimatedOwnershipRegistryOwnedBytes, 0U);
  EXPECT_GT(assembly.estimatedDeferredOutputOwnedBytes, 0U);
  EXPECT_GE(assembly.estimatedWorkspaceOwnedBytes,
            assembly.estimatedOwnershipRegistryOwnedBytes +
                assembly.estimatedDeferredOutputOwnedBytes);
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
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  auto first = completed_typed_single_quad(sourceFaces, sourceAuthority, 101);
  auto second = first;
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
      {second, first}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

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
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  const auto base = completed_typed_single_quad(sourceFaces, sourceAuthority, 101);
  auto first = base;
  auto second = base;
  auto third = base;
  auto fourth = base;
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
    ASSERT_EQ(mesh->boundaryNodeIdentities.size(),
              mesh->boundaryVertices.size());
    for (int row = 0; row < static_cast<int>(mesh->vertexLineage.size()); ++row) {
      auto &exact = mesh->boundaryNodeIdentities[static_cast<std::size_t>(row)];
      exact.values.push_back(700 + row);
      auto &lineage = mesh->vertexLineage[static_cast<std::size_t>(row)];
      lineage.stitchIdentity.canonical = exact;
      lineage.authoritativeIdentity = {};
    }
  }

  const auto forward = directional::geometry::stitch_pure_quad_patches(
      {first, second, third, fourth}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());
  const auto reordered = directional::geometry::stitch_pure_quad_patches(
      {fourth, second, first, third}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

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
     UnderQualifiedAuthoritativeIdentityFailsClosed) {
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  auto first = completed_typed_single_quad(sourceFaces, sourceAuthority, 101);
  auto second = first;
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
  for (auto &lineage : second.vertexLineage) {
    lineage.authoritativeIdentity =
        directional::geometry::pure_quad_detail::canonical_authoritative_identity(
            lineage, sourceFaces, sourceAuthority, &no_hard_feature_edges());
    ASSERT_TRUE(lineage.authoritativeIdentity.valid());
    lineage.authoritativeIdentity.canonical.values.pop_back();
  }

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first, second}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidAuthoritativeStitchIdentity", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18,
     CompletionOwnershipClassificationIsPatchOrderInvariant) {
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  auto first = completed_typed_single_quad(sourceFaces, sourceAuthority, 301);
  auto second = first;
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
      {first, second}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());
  const auto reverse = directional::geometry::stitch_pure_quad_patches(
      {second, first}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

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

  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InconsistentSharedBoundaryPosition", assembly.failure);
}


TEST(PureQuadCompletionPhase18,
     CoincidentPositionsOnDistinctTypedSheetsDoNotMerge) {
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
                 3, 4, 5;
  const auto sourceAuthority =
      test_source_authority(sourceFaces, {7, 7}, {11, 19});
  auto firstPatch = patch({1, 1, 1, 1});
  auto secondPatch = firstPatch;
  firstPatch.sourceFaces = {0};
  secondPatch.sourceFaces = {1};
  for (auto &point : secondPatch.boundaryProvenance) {
    point.face = 1;
  }
  assign_patch_boundary_authority(firstPatch, sourceFaces, sourceAuthority,
                                  {0, 0, 0, 0});
  assign_patch_boundary_authority(secondPatch, sourceFaces, sourceAuthority,
                                  {1, 1, 1, 1});
  // Force assembly to use typed source authority rather than exact boundary IDs.
  firstPatch.boundaryNodeIdentities.clear();
  secondPatch.boundaryNodeIdentities.clear();

  directional::geometry::PureQuadCompletionOptions firstOptions;
  firstOptions.sourcePatch = 101;
  firstOptions.sourceFaces = &sourceFaces;
  firstOptions.sourceAuthority = &sourceAuthority;
  directional::geometry::PureQuadCompletionOptions secondOptions;
  secondOptions.sourcePatch = 205;
  secondOptions.sourceFaces = &sourceFaces;
  secondOptions.sourceAuthority = &sourceAuthority;
  const auto first = directional::geometry::complete_pure_quad_patch(
      firstPatch, firstOptions);
  const auto second = directional::geometry::complete_pure_quad_patch(
      secondPatch, secondOptions);
  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.product(), second.product()}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  ASSERT_TRUE(assembly.success) << assembly.failure;
  EXPECT_EQ(8U, assembly.mesh.vertices.size());
  EXPECT_EQ(2U, assembly.mesh.quads.size());
  EXPECT_EQ(2, assembly.connectedComponents);
  EXPECT_EQ(0, assembly.mergedBoundaryVertices);
}

TEST(PureQuadCompletionPhase18,
     CoincidentGeneratedInteriorsRemainPatchLocal) {
  const CompletionFixture fixture = generated_plane_patch();
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  directional::geometry::PureQuadCompletionOptions firstOptions;
  firstOptions.sourcePatch = 301;
  firstOptions.sourceVertices = &fixture.vertices;
  firstOptions.sourceFaces = &fixture.faces;
  firstOptions.sourceAuthority = &sourceAuthority;
  directional::geometry::PureQuadCompletionOptions secondOptions =
      firstOptions;
  secondOptions.sourcePatch = 509;
  const auto first = directional::geometry::complete_pure_quad_patch(
      fixture.patch, firstOptions);
  const auto second = directional::geometry::complete_pure_quad_patch(
      fixture.patch, secondOptions);
  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.product(), second.product()}, 1.0e-9, &fixture.faces, &sourceAuthority, &no_hard_feature_edges());

  ASSERT_TRUE(assembly.success) << assembly.failure;
  const int expected = static_cast<int>(first.product().vertices.size() +
                                        second.product().vertices.size() -
                                        first.product().boundaryVertices.size());
  EXPECT_EQ(expected, static_cast<int>(assembly.mesh.vertices.size()));
}

TEST(PureQuadCompletionPhase18,
     ExactBoundaryIdentityWithoutTypedLineageIsNotPublished) {
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 599;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({1, 1, 1, 1}), options);
  ASSERT_TRUE(completion.is_produced());
  ASSERT_FALSE(completion.product().vertexLineage.empty());
  EXPECT_TRUE(std::all_of(
      completion.product().vertexLineage.begin(), completion.product().vertexLineage.end(),
      [](const auto &lineage) {
        return !lineage.stitchIdentity.valid() &&
               !lineage.authoritativeIdentity.valid();
      }));

  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());
  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("MissingTypedStitchIdentity", assembly.failure);
}

TEST(PureQuadCompletionPhase18,
     ExactBoundaryIdentityPublishesOnlyAfterTypedLineageValidation) {
  const CompletionFixture fixture = generated_plane_patch();
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 600;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  options.sourceAuthority = &sourceAuthority;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.is_produced());
  ASSERT_FALSE(completion.product().vertexLineage.empty());
  for (const auto &lineage : completion.product().vertexLineage) {
    EXPECT_FALSE(lineage.sourceTopologyRegions.empty());
    EXPECT_FALSE(lineage.sourceIsolationSheets.empty());
    EXPECT_FALSE(lineage.sourceCharts.empty());
    EXPECT_TRUE(lineage.sourceSupport.has_value());
  }
  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &fixture.faces, &sourceAuthority, &no_hard_feature_edges());
  EXPECT_TRUE(assembly.success) << assembly.failure;
}

TEST(PureQuadCompletionPhase18,
     CompatibleExactBoundaryKeyMergesWithTypedAuthorityCertificate) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  const auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());

  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

  ASSERT_TRUE(assembly.success) << assembly.failure;
  EXPECT_GT(assembly.mergedBoundaryVertices, 0);
  EXPECT_EQ(1, assembly.connectedComponents);
}

TEST(PureQuadCompletionPhase18,
     CompatibleCollisionPublishesOnlyPostIntersectionAuthority) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  const auto sourcePatches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, sourcePatches.size());
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  auto first = sourcePatches[0];
  auto second = sourcePatches[1];

  int firstRow = -1;
  int secondRow = -1;
  for (std::size_t firstBoundary = 0;
       firstBoundary < first.boundaryNodeIdentities.size() && firstRow < 0;
       ++firstBoundary) {
    for (std::size_t secondBoundary = 0;
         secondBoundary < second.boundaryNodeIdentities.size();
         ++secondBoundary) {
      if (first.boundaryNodeIdentities[firstBoundary] !=
          second.boundaryNodeIdentities[secondBoundary]) {
        continue;
      }
      const int firstVertex = first.boundaryVertices[firstBoundary];
      const int secondVertex = second.boundaryVertices[secondBoundary];
      const auto firstFound =
          std::find(first.vertices.begin(), first.vertices.end(), firstVertex);
      const auto secondFound =
          std::find(second.vertices.begin(), second.vertices.end(), secondVertex);
      if (firstFound == first.vertices.end() ||
          secondFound == second.vertices.end()) {
        continue;
      }
      const int firstCandidate = static_cast<int>(
          std::distance(first.vertices.begin(), firstFound));
      const int secondCandidate = static_cast<int>(
          std::distance(second.vertices.begin(), secondFound));
      const auto *support = std::get_if<directional::authority::SourceVertexSupport>(
          &first.vertexLineage[static_cast<std::size_t>(firstCandidate)]
               .sourceSupport.value());
      if (support == nullptr) {
        continue;
      }
      int incidentCount = 0;
      for (int face = 0; face < faces.rows(); ++face) {
        for (int corner = 0; corner < 3; ++corner) {
          if (checked_source_face_vertices(faces, face)[static_cast<std::size_t>(corner)] ==
              support->vertex) {
            ++incidentCount;
            break;
          }
        }
      }
      if (incidentCount >= 3) {
        firstRow = firstCandidate;
        secondRow = secondCandidate;
        break;
      }
    }
  }
  ASSERT_GE(firstRow, 0);
  ASSERT_GE(secondRow, 0);

  auto &firstLineage = first.vertexLineage[static_cast<std::size_t>(firstRow)];
  auto &secondLineage =
      second.vertexLineage[static_cast<std::size_t>(secondRow)];
  ASSERT_EQ(firstLineage.stitchIdentity, secondLineage.stitchIdentity);
  ASSERT_EQ(firstLineage.sourceSupport, secondLineage.sourceSupport);
  ASSERT_TRUE(firstLineage.sourceSupport.has_value());

  std::vector<int> incidentFaces;
  const auto *vertexSupport =
      std::get_if<directional::authority::SourceVertexSupport>(
          &firstLineage.sourceSupport.value());
  ASSERT_NE(vertexSupport, nullptr);
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      if (checked_source_face_vertices(faces, face)[static_cast<std::size_t>(corner)] ==
          vertexSupport->vertex) {
        incidentFaces.push_back(face);
        break;
      }
    }
  }
  ASSERT_GE(incidentFaces.size(), 3U);

  // Start from owner-valid chart closures that overlap on one canonical
  // source chart but are intentionally non-identical.  This exercises the
  // post-intersection certificate rather than relying on whichever incident
  // face each patch selected during completion.
  const auto commonChart =
      test_source_chart(faces, sourceAuthority, incidentFaces[0]);
  const auto firstExtraChart =
      test_source_chart(faces, sourceAuthority, incidentFaces[1]);
  const auto secondExtraChart =
      test_source_chart(faces, sourceAuthority, incidentFaces[2]);
  ASSERT_NE(commonChart, firstExtraChart);
  ASSERT_NE(commonChart, secondExtraChart);
  ASSERT_NE(firstExtraChart, secondExtraChart);
  firstLineage.sourceCharts = {commonChart, firstExtraChart};
  secondLineage.sourceCharts = {commonChart, secondExtraChart};
  std::sort(firstLineage.sourceCharts.begin(), firstLineage.sourceCharts.end());
  std::sort(secondLineage.sourceCharts.begin(), secondLineage.sourceCharts.end());
  firstLineage.authoritativeIdentity = {};
  secondLineage.authoritativeIdentity = {};

  const auto intersect = [](const auto &left, const auto &right) {
    using Value = typename std::decay_t<decltype(left)>::value_type;
    std::vector<Value> lhs = left;
    std::vector<Value> rhs = right;
    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    std::vector<Value> common;
    std::set_intersection(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
                          std::back_inserter(common));
    common.erase(std::unique(common.begin(), common.end()), common.end());
    return common;
  };
  const auto expectedRegions = intersect(firstLineage.sourceTopologyRegions,
                                         secondLineage.sourceTopologyRegions);
  const auto expectedSheets = intersect(firstLineage.sourceIsolationSheets,
                                        secondLineage.sourceIsolationSheets);
  const auto expectedCharts =
      intersect(firstLineage.sourceCharts, secondLineage.sourceCharts);
  ASSERT_FALSE(expectedRegions.empty());
  ASSERT_FALSE(expectedSheets.empty());
  ASSERT_FALSE(expectedCharts.empty());
  ASSERT_NE(firstLineage.sourceCharts, secondLineage.sourceCharts);

  const auto firstCandidateIdentity =
      directional::geometry::pure_quad_detail::canonical_authoritative_identity(
          firstLineage, faces, sourceAuthority, &no_hard_feature_edges());
  const auto secondCandidateIdentity =
      directional::geometry::pure_quad_detail::canonical_authoritative_identity(
          secondLineage, faces, sourceAuthority, &no_hard_feature_edges());
  ASSERT_TRUE(firstCandidateIdentity.valid());
  ASSERT_TRUE(secondCandidateIdentity.valid());
  ASSERT_NE(firstCandidateIdentity, secondCandidateIdentity);

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first, second}, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());
  ASSERT_TRUE(assembly.success) << assembly.failure;

  const auto published = std::find_if(
      assembly.mesh.vertexLineage.begin(), assembly.mesh.vertexLineage.end(),
      [&](const auto &lineage) {
        return lineage.stitchIdentity == firstLineage.stitchIdentity;
      });
  ASSERT_NE(assembly.mesh.vertexLineage.end(), published);
  EXPECT_EQ(expectedRegions, published->sourceTopologyRegions);
  EXPECT_EQ(expectedSheets, published->sourceIsolationSheets);
  EXPECT_EQ(expectedCharts, published->sourceCharts);
  EXPECT_EQ(firstLineage.sourceSupport, published->sourceSupport);
  EXPECT_EQ(
      directional::geometry::pure_quad_detail::canonical_authoritative_identity(
          *published, faces, sourceAuthority, &no_hard_feature_edges()),
      published->authoritativeIdentity);
  EXPECT_NE(firstCandidateIdentity, published->authoritativeIdentity);
  EXPECT_NE(secondCandidateIdentity, published->authoritativeIdentity);
}

TEST(PureQuadCompletionPhase18, MissingSourceAuthorityPublishesNothing) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  const auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, nullptr, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("MissingSourceAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
  EXPECT_TRUE(assembly.mesh.vertexLineage.empty());
}

TEST(PureQuadCompletionPhase18, UnownedRegionCertificatePublishesNothing) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  ASSERT_FALSE(patches.front().vertexLineage.empty());
  const auto fake = directional::authority::TopologyRegionId::from_index(7, 8);
  ASSERT_TRUE(fake);
  patches.front().vertexLineage.front().sourceTopologyRegions = {fake.value()};

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidTypedStitchAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18, SparseOwnerCertificatePublishesNothing) {
  CompletionFixture fixture = source_support_alias_patch();
  const auto sourceAuthority =
      test_source_authority(fixture.faces, {0, 0}, {0, 1});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 617;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  options.sourceAuthority = &sourceAuthority;
  auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.is_produced());
  const auto lineageIt = std::find_if(
      completion.product().vertexLineage.begin(),
      completion.product().vertexLineage.end(), [](const auto &lineage) {
        return lineage.sourceSupport.has_value() &&
               std::holds_alternative<
                   directional::authority::SourceVertexSupport>(
                   lineage.sourceSupport.value());
      });
  ASSERT_NE(lineageIt, completion.product().vertexLineage.end());
  auto &lineage = *lineageIt;
  const auto secondFace = directional::authority::SourceFaceId::from_index(
      1, static_cast<std::size_t>(fixture.faces.rows()));
  ASSERT_TRUE(secondFace);
  const auto secondChart = test_source_chart(fixture.faces, sourceAuthority, 1);
  if (std::find(lineage.sourceCharts.begin(), lineage.sourceCharts.end(),
                secondChart) == lineage.sourceCharts.end()) {
    lineage.sourceCharts.push_back(secondChart);
  }
  const auto secondRegion = sourceAuthority.region_for_row(secondFace.value());
  if (std::find(lineage.sourceTopologyRegions.begin(),
                lineage.sourceTopologyRegions.end(),
                secondRegion) == lineage.sourceTopologyRegions.end()) {
    lineage.sourceTopologyRegions.push_back(secondRegion);
  }
  const auto secondSheet = sourceAuthority.sheet_for_row(secondFace.value());
  if (std::find(lineage.sourceIsolationSheets.begin(),
                lineage.sourceIsolationSheets.end(),
                secondSheet) == lineage.sourceIsolationSheets.end()) {
    lineage.sourceIsolationSheets.push_back(secondSheet);
  }
  lineage.authoritativeIdentity = {};
  const auto completeIdentity =
      directional::geometry::pure_quad_detail::canonical_authoritative_identity(
          lineage, fixture.faces, sourceAuthority, &no_hard_feature_edges());
  ASSERT_TRUE(completeIdentity.valid());

  const auto firstFace = directional::authority::SourceFaceId::from_index(
      0, static_cast<std::size_t>(fixture.faces.rows()));
  ASSERT_TRUE(firstFace);
  lineage.sourceIsolationSheets = {
      sourceAuthority.sheet_for_row(firstFace.value())};
  EXPECT_FALSE(
      directional::geometry::pure_quad_detail::canonical_authoritative_identity(
          lineage, fixture.faces, sourceAuthority, &no_hard_feature_edges())
          .valid());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &fixture.faces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidTypedStitchAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18, WrongOwnerSheetCertificatePublishesNothing) {
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
                 3, 4, 5;
  const auto sourceAuthority =
      test_source_authority(sourceFaces, {7, 7}, {11, 19});
  auto sourcePatch = patch({1, 1, 1, 1});
  sourcePatch.sourceFaces = {0};
  assign_patch_boundary_authority(sourcePatch, sourceFaces, sourceAuthority,
                                  {0, 0, 0, 0});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 619;
  options.sourceFaces = &sourceFaces;
  options.sourceAuthority = &sourceAuthority;
  auto completion = directional::geometry::complete_pure_quad_patch(
      sourcePatch, options);
  ASSERT_TRUE(completion.is_produced());
  ASSERT_FALSE(completion.product().vertexLineage.empty());
  const auto secondFace = directional::authority::SourceFaceId::from_index(
      1, static_cast<std::size_t>(sourceFaces.rows()));
  ASSERT_TRUE(secondFace);
  completion.product().vertexLineage.front().sourceIsolationSheets = {
      sourceAuthority.sheet_for_row(secondFace.value())};

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidTypedStitchAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18, WrongFaceChartCertificatePublishesNothing) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  auto &lineage = patches.front().vertexLineage.front();
  ASSERT_FALSE(lineage.sourceCharts.empty());
  ASSERT_TRUE(lineage.sourceSupport.has_value());
  const auto supportIncident = [&](const int face) {
    const auto faceVertices = checked_source_face_vertices(faces, face);
    if (const auto *vertex =
            std::get_if<directional::authority::SourceVertexSupport>(
                &lineage.sourceSupport.value())) {
      return std::find(faceVertices.begin(), faceVertices.end(), vertex->vertex) !=
             faceVertices.end();
    }
    if (const auto *edge =
            std::get_if<directional::authority::SourceEdgeSupport>(
                &lineage.sourceSupport.value())) {
      const bool hasFirst =
          std::find(faceVertices.begin(), faceVertices.end(), edge->edge.first()) !=
          faceVertices.end();
      const bool hasSecond =
          std::find(faceVertices.begin(), faceVertices.end(), edge->edge.second()) !=
          faceVertices.end();
      return hasFirst && hasSecond;
    }
    if (const auto *interior =
            std::get_if<directional::authority::SourceFaceInteriorSupport>(
                &lineage.sourceSupport.value())) {
      const auto row = directional::authority::SourceFaceId::from_index(
          face, static_cast<std::size_t>(faces.rows()));
      return row &&
             interior->face == sourceAuthority.topology_for_row(row.value());
    }
    return false;
  };
  int wrongFace = -1;
  for (int face = 0; face < faces.rows(); ++face) {
    if (!supportIncident(face)) {
      wrongFace = face;
      break;
    }
  }
  ASSERT_GE(wrongFace, 0);
  const auto wrongFaceId = directional::authority::SourceFaceId::from_index(
      wrongFace, static_cast<std::size_t>(faces.rows()));
  ASSERT_TRUE(wrongFaceId);
  lineage.sourceCharts.front().face =
      sourceAuthority.topology_for_row(wrongFaceId.value());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidTypedStitchAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18, ExactOnlyAuthoritativeAliasPublishesNothing) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  auto &lineage = patches.front().vertexLineage.front();
  lineage.authoritativeIdentity = lineage.stitchIdentity;

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidAuthoritativeStitchIdentity", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18, StaleCanonicalAuthorityPublishesNothing) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  auto &lineage = patches.front().vertexLineage.front();
  lineage.authoritativeIdentity =
      directional::geometry::pure_quad_detail::canonical_authoritative_identity(
          lineage, faces, sourceAuthority, &no_hard_feature_edges());
  ASSERT_TRUE(lineage.authoritativeIdentity.valid());
  ASSERT_GT(lineage.authoritativeIdentity.canonical.values.size(), 1U);
  lineage.authoritativeIdentity.canonical.values.pop_back();

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("InvalidAuthoritativeStitchIdentity", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18,
     SameExactBoundaryKeyRejectsIncompatibleTypedLineage) {
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
                 3, 4, 5;
  const auto sourceAuthority =
      test_source_authority(sourceFaces, {7, 7}, {11, 19});
  auto firstPatch = patch({1, 1, 1, 1});
  auto secondPatch = firstPatch;
  firstPatch.sourceFaces = {0};
  secondPatch.sourceFaces = {1};
  for (auto &point : secondPatch.boundaryProvenance) {
    point.face = 1;
  }
  assign_patch_boundary_authority(firstPatch, sourceFaces, sourceAuthority,
                                  {0, 0, 0, 0});
  assign_patch_boundary_authority(secondPatch, sourceFaces, sourceAuthority,
                                  {1, 1, 1, 1});
  ASSERT_EQ(firstPatch.boundaryNodeIdentities,
            secondPatch.boundaryNodeIdentities);

  directional::geometry::PureQuadCompletionOptions firstOptions;
  firstOptions.sourcePatch = 611;
  firstOptions.sourceFaces = &sourceFaces;
  firstOptions.sourceAuthority = &sourceAuthority;
  directional::geometry::PureQuadCompletionOptions secondOptions;
  secondOptions.sourcePatch = 613;
  secondOptions.sourceFaces = &sourceFaces;
  secondOptions.sourceAuthority = &sourceAuthority;
  const auto first = directional::geometry::complete_pure_quad_patch(
      firstPatch, firstOptions);
  const auto second = directional::geometry::complete_pure_quad_patch(
      secondPatch, secondOptions);
  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.product(), second.product()}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("IncompatibleTypedStitchAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18,
     SameRegionSheetDifferentCompletedSupportsRejectTypedStitchCompatibility) {
  Eigen::MatrixXi sourceFaces(2, 3);
  sourceFaces << 0, 1, 2,
                 0, 2, 3;
  const auto sourceAuthority =
      test_source_authority(sourceFaces, {7, 7}, {11, 11});
  const auto row0 = directional::authority::SourceFaceId::from_index(
      0, sourceAuthority.face_count());
  const auto row1 = directional::authority::SourceFaceId::from_index(
      1, sourceAuthority.face_count());
  ASSERT_TRUE(row0);
  ASSERT_TRUE(row1);
  ASSERT_EQ(sourceAuthority.region_for_row(row0.value()),
            sourceAuthority.region_for_row(row1.value()));
  ASSERT_EQ(sourceAuthority.sheet_for_row(row0.value()),
            sourceAuthority.sheet_for_row(row1.value()));

  auto firstPatch = patch({1, 1, 1, 1});
  auto secondPatch = firstPatch;
  firstPatch.sourceFaces = {0};
  secondPatch.sourceFaces = {1};
  for (auto &point : secondPatch.boundaryProvenance) {
    point.face = 1;
  }
  assign_patch_boundary_authority(firstPatch, sourceFaces, sourceAuthority,
                                  {0, 0, 0, 0});
  assign_patch_boundary_authority(secondPatch, sourceFaces, sourceAuthority,
                                  {1, 1, 1, 1});
  ASSERT_EQ(firstPatch.boundaryNodeIdentities,
            secondPatch.boundaryNodeIdentities);

  directional::geometry::PureQuadCompletionOptions firstOptions;
  firstOptions.sourcePatch = 631;
  firstOptions.sourceFaces = &sourceFaces;
  firstOptions.sourceAuthority = &sourceAuthority;
  directional::geometry::PureQuadCompletionOptions secondOptions;
  secondOptions.sourcePatch = 633;
  secondOptions.sourceFaces = &sourceFaces;
  secondOptions.sourceAuthority = &sourceAuthority;
  const auto first = directional::geometry::complete_pure_quad_patch(
      firstPatch, firstOptions);
  const auto second = directional::geometry::complete_pure_quad_patch(
      secondPatch, secondOptions);
  ASSERT_TRUE(first.is_produced());
  ASSERT_TRUE(second.is_produced());
  ASSERT_FALSE(first.product().vertexLineage.empty());
  ASSERT_FALSE(second.product().vertexLineage.empty());
  EXPECT_EQ(first.product().vertexLineage.front().sourceTopologyRegions,
            second.product().vertexLineage.front().sourceTopologyRegions);
  EXPECT_EQ(first.product().vertexLineage.front().sourceIsolationSheets,
            second.product().vertexLineage.front().sourceIsolationSheets);
  EXPECT_NE(first.product().vertexLineage.front().sourceSupport,
            second.product().vertexLineage.front().sourceSupport);

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {first.product(), second.product()}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());

  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("IncompatibleTypedStitchAuthority", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18,
     MissingTypedStitchIdentityFailsClosedForGeneratedInterior) {
  Eigen::MatrixXi sourceFaces(1, 3);
  sourceFaces << 0, 1, 2;
  const auto sourceAuthority = test_source_authority(sourceFaces, {0}, {0});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 601;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      patch({2, 2, 2, 2}), options);
  ASSERT_TRUE(completion.is_produced());

  const auto assembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &sourceFaces, &sourceAuthority, &no_hard_feature_edges());
  EXPECT_FALSE(assembly.success);
  EXPECT_EQ("MissingTypedStitchIdentity", assembly.failure);
  EXPECT_TRUE(assembly.mesh.vertices.empty());
  EXPECT_TRUE(assembly.mesh.quads.empty());
}

TEST(PureQuadCompletionPhase18,
     RawProjectionTamperDoesNotChangeTypedStitchAssembly) {
  const CompletionFixture fixture = generated_plane_patch();
  const auto sourceAuthority = test_source_authority(
      fixture.faces, {0, 0, 1}, {0, 0, 1});
  directional::geometry::PureQuadCompletionOptions options;
  options.sourcePatch = 607;
  options.sourceVertices = &fixture.vertices;
  options.sourceFaces = &fixture.faces;
  options.sourceAuthority = &sourceAuthority;
  const auto completion = directional::geometry::complete_pure_quad_patch(
      fixture.patch, options);
  ASSERT_TRUE(completion.is_produced());

  auto tampered = completion.product();
  for (auto &point : tampered.vertexProvenance) {
    point.component = 901;
    point.sheet = 902;
  }
  for (auto &lineage : tampered.vertexLineage) {
    lineage.sourcePoint.component = 903;
    lineage.sourcePoint.sheet = 904;
  }

  const auto baselineAssembly = directional::geometry::stitch_pure_quad_patches(
      {completion.product()}, 1.0e-9, &fixture.faces, &sourceAuthority, &no_hard_feature_edges());
  const auto tamperedAssembly = directional::geometry::stitch_pure_quad_patches(
      {tampered}, 1.0e-9, &fixture.faces, &sourceAuthority, &no_hard_feature_edges());
  ASSERT_TRUE(baselineAssembly.success) << baselineAssembly.failure;
  ASSERT_TRUE(tamperedAssembly.success) << tamperedAssembly.failure;
  EXPECT_EQ(baselineAssembly.mesh.vertices, tamperedAssembly.mesh.vertices);
  EXPECT_EQ(baselineAssembly.mesh.quads, tamperedAssembly.mesh.quads);
  EXPECT_EQ(baselineAssembly.mergedBoundaryVertices,
            tamperedAssembly.mergedBoundaryVertices);
}

TEST(PureQuadCompletionPhase18, StitchingIsPatchOrderInvariant) {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  auto patches = completed_cylinder_patches(vertices, faces, 4);
  ASSERT_EQ(4U, patches.size());
  const auto sourceAuthority = test_source_authority(
      faces, std::vector<int>(static_cast<std::size_t>(faces.rows()), 0),
      std::vector<int>(static_cast<std::size_t>(faces.rows()), 0));
  const auto forward = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());
  std::reverse(patches.begin(), patches.end());
  const auto reverse = directional::geometry::stitch_pure_quad_patches(
      patches, 1.0e-9, &faces, &sourceAuthority, &no_hard_feature_edges());
  ASSERT_TRUE(forward.success) << forward.failure;
  ASSERT_TRUE(reverse.success) << reverse.failure;
  EXPECT_EQ(forward.mesh.quads, reverse.mesh.quads);
  EXPECT_TRUE(forward.mesh.vertexPositions.isApprox(
      reverse.mesh.vertexPositions, 0.0));
  EXPECT_EQ(forward.eulerCharacteristic, reverse.eulerCharacteristic);
  EXPECT_EQ(forward.boundaryLoopCount, reverse.boundaryLoopCount);
}
