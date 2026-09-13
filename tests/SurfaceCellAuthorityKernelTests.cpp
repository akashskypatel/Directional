// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/authority/SourceSupport.h>
#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfacePointSupport.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

namespace directional::authority {
namespace {

template <typename... Ts> struct TypeList {};

using SemanticIdDomains = TypeList<
    SourceVertexId, SourceFaceId, InteriorTransitionId, SourceComponentId,
    IsolationSheetId, TopologyRegionId, SurfaceCellOwnershipClassId,
    FieldChartId, SourceVertexFanId, HardRailId, PeriodicRelationId, CellId,
    OccurrenceId, QuotientClassId>;

template <typename A, typename B>
inline constexpr bool semantic_id_pair_contract_v =
    std::is_same_v<A, B> ||
    (!std::is_convertible_v<A, B> && !std::is_constructible_v<B, A>);

template <typename A, typename... Bs>
consteval bool semantic_id_row_contract(TypeList<Bs...>) {
  return (semantic_id_pair_contract_v<A, Bs> && ...);
}

template <typename... As, typename... Bs>
consteval bool semantic_id_matrix_contract(TypeList<As...>,
                                           TypeList<Bs...> all) {
  return (semantic_id_row_contract<As>(all) && ...);
}

template <typename A, typename... Bs>
consteval std::size_t semantic_id_distinct_row_count(TypeList<Bs...>) {
  return (std::size_t{0} + ... + (std::is_same_v<A, Bs> ? 0U : 1U));
}

template <typename... As, typename... Bs>
consteval std::size_t semantic_id_distinct_pair_count(TypeList<As...>,
                                                      TypeList<Bs...> all) {
  return (std::size_t{0} + ... + semantic_id_distinct_row_count<As>(all));
}

template <typename... Ts>
consteval std::size_t semantic_id_domain_count(TypeList<Ts...>) {
  return sizeof...(Ts);
}

static_assert(semantic_id_domain_count(SemanticIdDomains{}) == 14U);
static_assert(semantic_id_distinct_pair_count(SemanticIdDomains{},
                                              SemanticIdDomains{}) == 182U);
static_assert(semantic_id_matrix_contract(SemanticIdDomains{},
                                          SemanticIdDomains{}));
static_assert(!std::is_constructible_v<SourceFaceId, int>);
static_assert(!std::is_constructible_v<FieldChartId, std::size_t>);
static_assert(!std::is_convertible_v<SourceFaceId, int>);

TEST(SurfaceCellAuthorityKernel, StrongIdsAreStaticallyNonInterconvertible) {
  SUCCEED();
}

TEST(SurfaceCellAuthorityKernel, CheckedConstructionAcceptsBoundariesAndRejectsDomainErrors) {
  const auto lower = directional::authority::SourceFaceId::from_index(0, 8);
  const auto upper = directional::authority::SourceFaceId::from_index(7, 8);
  ASSERT_TRUE(lower.has_value());
  ASSERT_TRUE(upper.has_value());
  EXPECT_NE(lower.value(), upper.value());
  EXPECT_LT(lower.value(), upper.value());

  const auto negative = directional::authority::SourceFaceId::from_index(-1, 8);
  ASSERT_FALSE(negative.has_value());
  EXPECT_EQ(negative.error().code, DomainErrorCode::NegativeIndex);
  EXPECT_EQ(negative.error().expectedDomain, AuthorityDomain::SourceFace);

  const auto outOfRange = directional::authority::SourceFaceId::from_index(8, 8);
  ASSERT_FALSE(outOfRange.has_value());
  EXPECT_EQ(outOfRange.error().code, DomainErrorCode::IndexOutOfRange);
  EXPECT_EQ(outOfRange.error().inputValue, 8);
  EXPECT_EQ(outOfRange.error().extent, 8u);
}

TEST(SurfaceCellAuthorityKernel, NumericCoincidenceDoesNotConflateDomains) {
  const auto face = directional::authority::SourceFaceId::from_index(2, 5);
  const auto chart = directional::authority::FieldChartId::from_index(2, 5);
  ASSERT_TRUE(face.has_value());
  ASSERT_TRUE(chart.has_value());

  EXPECT_EQ(SourceFaceId::domain(), AuthorityDomain::SourceFace);
  EXPECT_EQ(FieldChartId::domain(), AuthorityDomain::FieldChart);
  EXPECT_NE(SourceFaceId::domain(), FieldChartId::domain());
  static_assert(!std::is_same_v<SourceFaceId, FieldChartId>);
}

TEST(SurfaceCellAuthorityKernel, SourceEdgeCanonicalizationPreservesExplicitOrientation) {
  const auto aResult = directional::authority::SourceVertexId::from_index(1, 8);
  const auto bResult = directional::authority::SourceVertexId::from_index(6, 8);
  ASSERT_TRUE(aResult.has_value());
  ASSERT_TRUE(bResult.has_value());

  const auto forward = SourceEdgeTopologyKey::make(aResult.value(), bResult.value());
  const auto reverse = SourceEdgeTopologyKey::make(bResult.value(), aResult.value());
  ASSERT_TRUE(forward.has_value());
  ASSERT_TRUE(reverse.has_value());
  EXPECT_EQ(forward.value(), reverse.value());
  EXPECT_EQ(forward.value().first(), aResult.value());
  EXPECT_EQ(forward.value().second(), bResult.value());
  EXPECT_NE(Orientation::Forward, Orientation::Reverse);

  const auto degenerate =
      SourceEdgeTopologyKey::make(aResult.value(), aResult.value());
  ASSERT_FALSE(degenerate.has_value());
  EXPECT_EQ(degenerate.error().code, DomainErrorCode::DegenerateSourceEdge);
  EXPECT_EQ(degenerate.error().expectedDomain,
            AuthorityDomain::SourceEdgeTopology);
}

TEST(SurfaceCellAuthorityKernel, SourceSupportAlternativesRemainTypeDistinct) {
  const auto vertex = directional::authority::SourceVertexId::from_index(3, 8);
  const auto a = directional::authority::SourceVertexId::from_index(0, 8);
  const auto b = directional::authority::SourceVertexId::from_index(1, 8);
  const auto c = directional::authority::SourceVertexId::from_index(2, 8);
  ASSERT_TRUE(vertex.has_value());
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  ASSERT_TRUE(c.has_value());
  const auto face = SourceFaceTopologyKey::make(
      {a.value(), b.value(), c.value()});
  ASSERT_TRUE(face.has_value());

  const SourceSupport vertexSupport = SourceVertexSupport{vertex.value()};
  const SourceSupport faceSupport =
      SourceFaceInteriorSupport{face.value()};
  EXPECT_NE(vertexSupport, faceSupport);
  EXPECT_EQ(support_kind(vertexSupport), SourceSupportKind::Vertex);
  EXPECT_EQ(support_kind(faceSupport), SourceSupportKind::FaceInterior);
}

TEST(SurfaceCellAuthorityKernel,
     SourceFaceTopologyKeyCanonicalizesAllVertexPermutations) {
  const auto a = SourceVertexId::from_index(1, 8);
  const auto b = SourceVertexId::from_index(3, 8);
  const auto c = SourceVertexId::from_index(6, 8);
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  ASSERT_TRUE(c.has_value());
  ASSERT_NE(a.value(), b.value());
  ASSERT_NE(a.value(), c.value());
  ASSERT_NE(b.value(), c.value());

  const auto abc =
      SourceFaceTopologyKey::make({a.value(), b.value(), c.value()});
  const auto acb =
      SourceFaceTopologyKey::make({a.value(), c.value(), b.value()});
  const auto bac =
      SourceFaceTopologyKey::make({b.value(), a.value(), c.value()});
  const auto bca =
      SourceFaceTopologyKey::make({b.value(), c.value(), a.value()});
  const auto cab =
      SourceFaceTopologyKey::make({c.value(), a.value(), b.value()});
  const auto cba =
      SourceFaceTopologyKey::make({c.value(), b.value(), a.value()});

  ASSERT_TRUE(abc.has_value());
  ASSERT_TRUE(acb.has_value());
  ASSERT_TRUE(bac.has_value());
  ASSERT_TRUE(bca.has_value());
  ASSERT_TRUE(cab.has_value());
  ASSERT_TRUE(cba.has_value());

  EXPECT_EQ(abc.value(), acb.value());
  EXPECT_EQ(abc.value(), bac.value());
  EXPECT_EQ(abc.value(), bca.value());
  EXPECT_EQ(abc.value(), cab.value());
  EXPECT_EQ(abc.value(), cba.value());
  EXPECT_EQ(abc.value().vertices(),
            (std::array<SourceVertexId, 3>{a.value(), b.value(), c.value()}));
}

TEST(SurfaceCellAuthorityKernel,
     SourceFaceTopologyKeyRejectsRepeatedSourceVertex) {
  const auto a = SourceVertexId::from_index(1, 8);
  const auto b = SourceVertexId::from_index(5, 8);
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  ASSERT_NE(a.value(), b.value());

  const auto repeated =
      SourceFaceTopologyKey::make({a.value(), b.value(), a.value()});
  ASSERT_FALSE(repeated.has_value());
  EXPECT_EQ(repeated.error().code, DomainErrorCode::DegenerateSourceFace);
  EXPECT_EQ(repeated.error().expectedDomain, AuthorityDomain::SourceFace);
}

directional::geometry::SourceTopologyRegions test_source_regions(
    const Eigen::MatrixXi &faces, const std::vector<int> &components,
    const std::vector<int> &sheets) {
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = components;
  options.sourceFaceSheets = sheets;
  const auto regions = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, options);
  if (!regions.has_value()) {
    throw std::runtime_error("Failed to build source-topology test authority.");
  }
  return regions.value();
}

directional::geometry::SurfacePoint interior_point(
    const int face, const Eigen::Vector3d &barycentric) {
  directional::geometry::SurfacePoint point;
  point.face = face;
  point.component = 0;
  point.sheet = 0;
  point.barycentric = barycentric;
  point.position = Eigen::Vector3d::Zero();
  point.squaredDistance = 0.0;
  return point;
}

TEST(SurfaceCellAuthorityKernel,
     FaceInteriorSupportIsInvariantToSourceRowsAndCyclicCornerStarts) {
  Eigen::MatrixXi original(2, 3);
  original << 0, 1, 2,
              2, 1, 3;
  Eigen::MatrixXi permuted(2, 3);
  permuted << 1, 3, 2,
              1, 2, 0;

  directional::geometry::SurfacePointSourceSupportResolver originalResolver(
      original);
  directional::geometry::SurfacePointSourceSupportResolver permutedResolver(
      permuted);
  const auto originalSupport = originalResolver.resolve(
      interior_point(0, Eigen::Vector3d(0.2, 0.3, 0.5)));
  const auto permutedSupport = permutedResolver.resolve(
      interior_point(1, Eigen::Vector3d(0.3, 0.5, 0.2)));
  const auto distinctSupport = originalResolver.resolve(
      interior_point(1, Eigen::Vector3d(0.2, 0.3, 0.5)));

  ASSERT_TRUE(originalSupport.valid());
  ASSERT_TRUE(permutedSupport.valid());
  ASSERT_TRUE(distinctSupport.valid());
  EXPECT_EQ(originalSupport.identity, permutedSupport.identity);
  EXPECT_NE(originalSupport.identity, distinctSupport.identity);
}

TEST(SurfaceCellAuthorityKernel,
     ProjectionChartsAndTransitionsIgnoreSourceFaceRows) {
  Eigen::MatrixXi original(2, 3);
  original << 0, 1, 2,
              2, 1, 3;
  Eigen::MatrixXi permuted(2, 3);
  permuted << 1, 3, 2,
              1, 2, 0;
  const std::vector<int> originalComponents{0, 0};
  const std::vector<int> originalSheets{0, 0};
  const std::vector<int> permutedComponents{0, 0};
  const std::vector<int> permutedSheets{0, 0};
  const auto originalAuthority =
      test_source_regions(original, originalComponents, originalSheets);
  const auto permutedAuthority =
      test_source_regions(permuted, permutedComponents, permutedSheets);
  directional::geometry::SourceChartTransitionGraph originalGraph(
      original, originalAuthority,
      directional::geometry::empty_hard_feature_edges());
  directional::geometry::SourceChartTransitionGraph permutedGraph(
      permuted, permutedAuthority,
      directional::geometry::empty_hard_feature_edges());
  ASSERT_TRUE(originalGraph.available());
  ASSERT_TRUE(permutedGraph.available());

  const auto originalFirst = originalGraph.chart(0);
  const auto originalSecond = originalGraph.chart(1);
  const auto permutedFirst = permutedGraph.chart(1);
  const auto permutedSecond = permutedGraph.chart(0);
  ASSERT_TRUE(originalFirst.has_value());
  ASSERT_TRUE(originalSecond.has_value());
  ASSERT_TRUE(permutedFirst.has_value());
  ASSERT_TRUE(permutedSecond.has_value());
  EXPECT_EQ(originalFirst.value(), permutedFirst.value());
  EXPECT_EQ(originalSecond.value(), permutedSecond.value());
  EXPECT_NE(originalFirst.value(), originalSecond.value());

  const auto originalRow = originalGraph.source_face_row(originalFirst.value());
  const auto permutedRow = permutedGraph.source_face_row(permutedFirst.value());
  ASSERT_TRUE(originalRow.has_value());
  ASSERT_TRUE(permutedRow.has_value());
  EXPECT_EQ(0U, originalRow->index());
  EXPECT_EQ(1U, permutedRow->index());

  std::vector<std::uint64_t> originalHashes;
  std::vector<std::uint64_t> permutedHashes;
  for (const auto &transition : originalGraph.transitions()) {
    originalHashes.push_back(transition.structuralHash);
  }
  for (const auto &transition : permutedGraph.transitions()) {
    permutedHashes.push_back(transition.structuralHash);
  }
  std::sort(originalHashes.begin(), originalHashes.end());
  std::sort(permutedHashes.begin(), permutedHashes.end());
  EXPECT_EQ(originalHashes, permutedHashes);
}

TEST(SurfaceCellAuthorityKernel,
     SourceEntityRebindingPreservesSupportWithoutRowEqualityOracle) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           2, 1, 3;
  const auto sourceAuthority =
      test_source_regions(faces, {0, 0}, {0, 0});
  directional::geometry::SourceChartTransitionGraph graph(
      faces, sourceAuthority,
      directional::geometry::empty_hard_feature_edges());
  ASSERT_TRUE(graph.available());

  directional::geometry::SurfacePoint source =
      interior_point(0, Eigen::Vector3d(0.0, 0.4, 0.6));
  directional::geometry::SurfacePoint rebound;
  ASSERT_TRUE(graph.rebind(source, 1, rebound));
  EXPECT_EQ(1, rebound.face);

  directional::geometry::SurfacePointSourceSupportResolver resolver(faces);
  const auto before = resolver.resolve(source);
  const auto after = resolver.resolve(rebound);
  ASSERT_TRUE(before.valid());
  ASSERT_TRUE(after.valid());
  EXPECT_EQ(before.identity, after.identity);
  EXPECT_NE(before.incidentFaces.front(), after.incidentFaces.back());
}

TEST(SurfaceCellAuthorityKernel, QuarterTurnNormalizesAndCyclesExactly) {
  EXPECT_EQ(QuarterTurn::from_integer(0), QuarterTurn{});
  EXPECT_EQ(QuarterTurn::from_integer(4), QuarterTurn{});
  EXPECT_EQ(QuarterTurn::from_integer(-1), QuarterTurn::from_integer(3));

  auto accumulated = QuarterTurn{};
  for (int i = 0; i < 4; ++i) {
    accumulated = compose(QuarterTurn::from_integer(1), accumulated);
  }
  EXPECT_EQ(accumulated, QuarterTurn{});
}

TEST(SurfaceCellAuthorityKernel, GridAutomorphismIdentityInverseAndAssociativityAreExact) {
  const GridAutomorphism identity = GridAutomorphism::identity();
  const GridAutomorphism a{QuarterTurn::from_integer(1), {2, -1}};
  const GridAutomorphism b{QuarterTurn::from_integer(2), {-3, 4}};
  const GridAutomorphism c{QuarterTurn::from_integer(3), {5, 2}};

  EXPECT_EQ(compose(identity, a), a);
  EXPECT_EQ(compose(a, identity), a);
  EXPECT_EQ(compose(a, a.inverse()), identity);
  EXPECT_EQ(compose(a.inverse(), a), identity);
  EXPECT_EQ(compose(a, compose(b, c)), compose(compose(a, b), c));
}

TEST(SurfaceCellAuthorityKernel, NonzeroRotationTranslationRoundTripIsExact) {
  const GridAutomorphism transform{QuarterTurn::from_integer(1), {7, -4}};
  const LatticeTranslation point{3, 5};
  const auto transformed = transform.apply(point);
  EXPECT_NE(transform.rotation, QuarterTurn{});
  EXPECT_EQ(transform.inverse().apply(transformed), point);
}

TEST(SurfaceCellAuthorityKernel, BoundaryStepWithoutInteriorTransitionIsValid) {
  const auto a = directional::authority::SourceVertexId::from_index(0, 4);
  const auto b = directional::authority::SourceVertexId::from_index(1, 4);
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  const auto key = SourceEdgeTopologyKey::make(a.value(), b.value());
  ASSERT_TRUE(key.has_value());

  const auto step = TransitionStep::boundary(
      key.value(), GridAutomorphism::identity(), Orientation::Forward);
  EXPECT_EQ(step.kind(), TransitionStepKind::Boundary);
  EXPECT_FALSE(step.interior().has_value());
}

TEST(SurfaceCellAuthorityKernel, InteriorStepRequiresNamedInteriorTransition) {
  const auto a = directional::authority::SourceVertexId::from_index(0, 4);
  const auto b = directional::authority::SourceVertexId::from_index(2, 4);
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  const auto key = SourceEdgeTopologyKey::make(a.value(), b.value());
  ASSERT_TRUE(key.has_value());

  const auto missing = TransitionStep::interior(
      key.value(), std::nullopt, GridAutomorphism::identity(),
      Orientation::Forward);
  ASSERT_FALSE(missing.has_value());
  EXPECT_EQ(missing.error().code, DomainErrorCode::MissingInteriorTransition);

  const auto transition = directional::authority::InteriorTransitionId::from_index(1, 3);
  ASSERT_TRUE(transition.has_value());
  const auto valid = TransitionStep::interior(
      key.value(), transition.value(),
      GridAutomorphism{QuarterTurn::from_integer(1), {2, 0}},
      Orientation::Reverse);
  ASSERT_TRUE(valid.has_value());
  EXPECT_EQ(valid.value().kind(), TransitionStepKind::Interior);
  EXPECT_EQ(valid.value().interior(), transition.value());
}

TEST(SurfaceCellAuthorityKernel, CanonicalRouteReversalRoundTripIsExact) {
  const auto v0 = directional::authority::SourceVertexId::from_index(0, 6);
  const auto v1 = directional::authority::SourceVertexId::from_index(1, 6);
  const auto v2 = directional::authority::SourceVertexId::from_index(2, 6);
  ASSERT_TRUE(v0.has_value());
  ASSERT_TRUE(v1.has_value());
  ASSERT_TRUE(v2.has_value());

  const auto e01 = SourceEdgeTopologyKey::make(v0.value(), v1.value());
  const auto e12 = SourceEdgeTopologyKey::make(v1.value(), v2.value());
  ASSERT_TRUE(e01.has_value());
  ASSERT_TRUE(e12.has_value());

  std::vector<TransitionStep> observed{
      TransitionStep::boundary(
          e01.value(), GridAutomorphism{QuarterTurn::from_integer(1), {1, 2}},
          Orientation::Forward),
      TransitionStep::boundary(
          e12.value(), GridAutomorphism{QuarterTurn::from_integer(3), {-2, 1}},
          Orientation::Reverse)};
  const auto route = CanonicalRoute::from_observed_steps(observed);
  const auto reversed = route.reversed();

  EXPECT_EQ(reversed.reversed(), route);
  const auto twiceReversedSteps = reversed.reversed().oriented_steps();
  EXPECT_EQ(twiceReversedSteps, route.oriented_steps());
  EXPECT_NE(reversed.canonical_orientation(), route.canonical_orientation());
}
TEST(SurfaceCellAuthorityKernel, EmptyCanonicalRouteReversalStillFlipsOrientation) {
  const CanonicalRoute route;
  ASSERT_TRUE(route.empty());
  const auto reversed = route.reversed();
  EXPECT_TRUE(reversed.empty());
  EXPECT_EQ(route.steps(), reversed.steps());
  EXPECT_NE(route.canonical_orientation(), reversed.canonical_orientation());
  EXPECT_NE(route, reversed);
  EXPECT_EQ(reversed.reversed(), route);
}


TEST(SurfaceCellAuthorityKernel, RepresentationHandlePerturbationDoesNotChangeCanonicalRoute) {
  const auto v0 = directional::authority::SourceVertexId::from_index(0, 5);
  const auto v1 = directional::authority::SourceVertexId::from_index(1, 5);
  ASSERT_TRUE(v0.has_value());
  ASSERT_TRUE(v1.has_value());
  const auto edge = SourceEdgeTopologyKey::make(v0.value(), v1.value());
  ASSERT_TRUE(edge.has_value());

  const std::vector<TransitionStep> semanticSteps{
      TransitionStep::boundary(edge.value(), GridAutomorphism::identity(),
                               Orientation::Forward)};
  std::vector<std::size_t> representationHandles{91, 7, 42};
  const auto first = CanonicalRoute::from_observed_steps(semanticSteps);

  std::swap(representationHandles.front(), representationHandles.back());
  const auto second = CanonicalRoute::from_observed_steps(semanticSteps);

  EXPECT_EQ(first, second);
  EXPECT_EQ(representationHandles.front(), 42u);
}

TEST(SurfaceCellAuthorityKernel, CrossDomainConstructionIsRejected) {
  const auto misuse = FieldChartId::from_domain_index(
      AuthorityDomain::SourceFace, 1, 4);
  ASSERT_FALSE(misuse.has_value());
  EXPECT_EQ(misuse.error().code, DomainErrorCode::DomainMismatch);
  EXPECT_EQ(misuse.error().expectedDomain, AuthorityDomain::FieldChart);
  ASSERT_TRUE(misuse.error().suppliedDomain.has_value());
  EXPECT_EQ(*misuse.error().suppliedDomain, AuthorityDomain::SourceFace);
}

} // namespace
} // namespace directional::authority
