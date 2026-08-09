// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/authority/LegacyAuthorityAdapters.h>
#include <directional/authority/SourceSupport.h>

#include <cstddef>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

namespace directional::authority {
namespace {

static_assert(!std::is_convertible_v<SourceFaceId, FieldChartId>);
static_assert(!std::is_convertible_v<FieldChartId, SourceFaceId>);
static_assert(!std::is_convertible_v<InteriorTransitionId, SourceFaceId>);
static_assert(!std::is_convertible_v<SourceFaceId, InteriorTransitionId>);
static_assert(!std::is_convertible_v<TopologyRegionId, IsolationSheetId>);
static_assert(!std::is_convertible_v<IsolationSheetId, TopologyRegionId>);
static_assert(!std::is_convertible_v<IsolationSheetId, FieldChartId>);
static_assert(!std::is_convertible_v<FieldChartId, IsolationSheetId>);
static_assert(!std::is_constructible_v<SourceFaceId, int>);
static_assert(!std::is_constructible_v<FieldChartId, std::size_t>);
static_assert(!std::is_convertible_v<SourceFaceId, int>);

TEST(SurfaceCellAuthorityKernel, StrongIdsAreStaticallyNonInterconvertible) {
  SUCCEED();
}

TEST(SurfaceCellAuthorityKernel, CheckedLegacyConversionAcceptsAndRejectsDomainErrors) {
  const auto valid = LegacyAuthorityAdapters::source_face(3, 8);
  ASSERT_TRUE(valid.has_value());
  EXPECT_EQ(valid.value().value(), 3u);

  const auto negative = LegacyAuthorityAdapters::source_face(-1, 8);
  ASSERT_FALSE(negative.has_value());
  EXPECT_EQ(negative.error().code, DomainErrorCode::NegativeLegacyValue);
  EXPECT_EQ(negative.error().expectedDomain, AuthorityDomain::SourceFace);

  const auto outOfRange = LegacyAuthorityAdapters::source_face(8, 8);
  ASSERT_FALSE(outOfRange.has_value());
  EXPECT_EQ(outOfRange.error().code, DomainErrorCode::OutOfRangeLegacyValue);
  EXPECT_EQ(outOfRange.error().legacyValue, 8);
  EXPECT_EQ(outOfRange.error().extent, 8u);
}

TEST(SurfaceCellAuthorityKernel, NumericCoincidenceDoesNotConflateDomains) {
  const auto face = LegacyAuthorityAdapters::source_face(2, 5);
  const auto chart = LegacyAuthorityAdapters::field_chart(2, 5);
  ASSERT_TRUE(face.has_value());
  ASSERT_TRUE(chart.has_value());

  EXPECT_EQ(face.value().value(), chart.value().value());
  EXPECT_EQ(SourceFaceId::domain(), AuthorityDomain::SourceFace);
  EXPECT_EQ(FieldChartId::domain(), AuthorityDomain::FieldChart);
  static_assert(!std::is_same_v<SourceFaceId, FieldChartId>);
}

TEST(SurfaceCellAuthorityKernel, SourceEdgeCanonicalizationPreservesExplicitOrientation) {
  const auto aResult = LegacyAuthorityAdapters::source_vertex(1, 8);
  const auto bResult = LegacyAuthorityAdapters::source_vertex(6, 8);
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
  const auto vertex = LegacyAuthorityAdapters::source_vertex(3, 8);
  const auto face = LegacyAuthorityAdapters::source_face(3, 8);
  ASSERT_TRUE(vertex.has_value());
  ASSERT_TRUE(face.has_value());

  const SourceSupport vertexSupport = SourceVertexSupport{vertex.value()};
  const SourceSupport faceSupport = SourceFaceInteriorSupport{face.value()};
  EXPECT_NE(vertexSupport, faceSupport);
  EXPECT_EQ(support_kind(vertexSupport), SourceSupportKind::Vertex);
  EXPECT_EQ(support_kind(faceSupport), SourceSupportKind::FaceInterior);
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
  const auto a = LegacyAuthorityAdapters::source_vertex(0, 4);
  const auto b = LegacyAuthorityAdapters::source_vertex(1, 4);
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
  const auto a = LegacyAuthorityAdapters::source_vertex(0, 4);
  const auto b = LegacyAuthorityAdapters::source_vertex(2, 4);
  ASSERT_TRUE(a.has_value());
  ASSERT_TRUE(b.has_value());
  const auto key = SourceEdgeTopologyKey::make(a.value(), b.value());
  ASSERT_TRUE(key.has_value());

  const auto missing = TransitionStep::interior(
      key.value(), std::nullopt, GridAutomorphism::identity(),
      Orientation::Forward);
  ASSERT_FALSE(missing.has_value());
  EXPECT_EQ(missing.error().code, DomainErrorCode::MissingInteriorTransition);

  const auto transition = LegacyAuthorityAdapters::interior_transition(1, 3);
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
  const auto v0 = LegacyAuthorityAdapters::source_vertex(0, 6);
  const auto v1 = LegacyAuthorityAdapters::source_vertex(1, 6);
  const auto v2 = LegacyAuthorityAdapters::source_vertex(2, 6);
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

TEST(SurfaceCellAuthorityKernel, RepresentationHandlePerturbationDoesNotChangeCanonicalRoute) {
  const auto v0 = LegacyAuthorityAdapters::source_vertex(0, 5);
  const auto v1 = LegacyAuthorityAdapters::source_vertex(1, 5);
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

TEST(SurfaceCellAuthorityKernel, LegacyAdapterRoundTripPreservesSemanticValue) {
  const auto region = LegacyAuthorityAdapters::topology_region(4, 9);
  ASSERT_TRUE(region.has_value());
  const auto raw = LegacyAuthorityAdapters::to_legacy_index(region.value());
  const auto reconstructed = LegacyAuthorityAdapters::topology_region(
      static_cast<std::int64_t>(raw), 9);
  ASSERT_TRUE(reconstructed.has_value());
  EXPECT_EQ(reconstructed.value(), region.value());
}

TEST(SurfaceCellAuthorityKernel, DeliberateCrossDomainAdapterMisuseIsRejected) {
  const auto misuse = LegacyAuthorityAdapters::checked<FieldChartId>(
      AuthorityDomain::SourceFace, 1, 4);
  ASSERT_FALSE(misuse.has_value());
  EXPECT_EQ(misuse.error().code, DomainErrorCode::DomainMismatch);
  EXPECT_EQ(misuse.error().expectedDomain, AuthorityDomain::FieldChart);
  ASSERT_TRUE(misuse.error().suppliedDomain.has_value());
  EXPECT_EQ(*misuse.error().suppliedDomain, AuthorityDomain::SourceFace);
}

} // namespace
} // namespace directional::authority
