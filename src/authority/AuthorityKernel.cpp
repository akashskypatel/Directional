// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/LegacyAuthorityAdapters.h>
#include <directional/authority/SourceSupport.h>

#include <algorithm>
#include <utility>

namespace directional::authority {

DomainResult<SourceEdgeTopologyKey>
SourceEdgeTopologyKey::make(SourceVertexId a, SourceVertexId b) {
  if (a == b) {
    return DomainResult<SourceEdgeTopologyKey>(DomainError{
        DomainErrorCode::DegenerateSourceEdge, AuthorityDomain::SourceVertex,
        AuthorityDomain::SourceVertex,
        static_cast<std::int64_t>(a.value()), 0});
  }
  if (b < a) {
    std::swap(a, b);
  }
  return DomainResult<SourceEdgeTopologyKey>(SourceEdgeTopologyKey(a, b));
}

TransitionStep TransitionStep::boundary(SourceEdgeTopologyKey topology,
                                        GridAutomorphism transport,
                                        Orientation orientation) {
  return TransitionStep(TransitionStepKind::Boundary, topology, std::nullopt,
                        transport, orientation);
}

DomainResult<TransitionStep>
TransitionStep::interior(SourceEdgeTopologyKey topology,
                         std::optional<InteriorTransitionId> interior,
                         GridAutomorphism transport, Orientation orientation) {
  if (!interior.has_value()) {
    return DomainResult<TransitionStep>(DomainError{
        DomainErrorCode::MissingInteriorTransition,
        AuthorityDomain::InteriorTransition, std::nullopt, 0, 0});
  }
  return DomainResult<TransitionStep>(
      TransitionStep(TransitionStepKind::Interior, topology, interior, transport,
                     orientation));
}

TransitionStep TransitionStep::reversed() const {
  return TransitionStep(kind_, topology_, interior_, transport_.inverse(),
                        reverse_orientation(orientation_));
}

std::vector<TransitionStep>
CanonicalRoute::reverse_steps(const std::vector<TransitionStep> &steps) {
  std::vector<TransitionStep> reversed;
  reversed.reserve(steps.size());
  for (auto it = steps.rbegin(); it != steps.rend(); ++it) {
    reversed.push_back(it->reversed());
  }
  return reversed;
}

CanonicalRoute
CanonicalRoute::from_observed_steps(std::vector<TransitionStep> observedSteps) {
  auto reversed = reverse_steps(observedSteps);
  const bool reversedIsCanonical = std::lexicographical_compare(
      reversed.begin(), reversed.end(), observedSteps.begin(), observedSteps.end());
  if (reversedIsCanonical) {
    return CanonicalRoute(std::move(reversed), Orientation::Reverse);
  }
  return CanonicalRoute(std::move(observedSteps), Orientation::Forward);
}

std::vector<TransitionStep> CanonicalRoute::oriented_steps() const {
  if (canonicalOrientation_ == Orientation::Forward) {
    return canonicalSteps_;
  }
  return reverse_steps(canonicalSteps_);
}

CanonicalRoute CanonicalRoute::reversed() const {
  return CanonicalRoute(canonicalSteps_, reverse_orientation(canonicalOrientation_));
}

DomainResult<SourceVertexId>
LegacyAuthorityAdapters::source_vertex(std::int64_t legacyValue,
                                       std::size_t extent) {
  return checked<SourceVertexId>(AuthorityDomain::SourceVertex, legacyValue,
                                 extent);
}

DomainResult<SourceFaceId>
LegacyAuthorityAdapters::source_face(std::int64_t legacyValue,
                                     std::size_t extent) {
  return checked<SourceFaceId>(AuthorityDomain::SourceFace, legacyValue, extent);
}

DomainResult<InteriorTransitionId>
LegacyAuthorityAdapters::interior_transition(std::int64_t legacyValue,
                                             std::size_t extent) {
  return checked<InteriorTransitionId>(AuthorityDomain::InteriorTransition,
                                       legacyValue, extent);
}

DomainResult<SourceComponentId>
LegacyAuthorityAdapters::source_component(std::int64_t legacyValue,
                                          std::size_t extent) {
  return checked<SourceComponentId>(AuthorityDomain::SourceComponent,
                                    legacyValue, extent);
}

DomainResult<IsolationSheetId>
LegacyAuthorityAdapters::isolation_sheet(std::int64_t legacyValue,
                                         std::size_t extent) {
  return checked<IsolationSheetId>(AuthorityDomain::IsolationSheet, legacyValue,
                                   extent);
}

DomainResult<TopologyRegionId>
LegacyAuthorityAdapters::topology_region(std::int64_t legacyValue,
                                         std::size_t extent) {
  return checked<TopologyRegionId>(AuthorityDomain::TopologyRegion, legacyValue,
                                   extent);
}

DomainResult<FieldChartId>
LegacyAuthorityAdapters::field_chart(std::int64_t legacyValue,
                                     std::size_t extent) {
  return checked<FieldChartId>(AuthorityDomain::FieldChart, legacyValue, extent);
}

DomainResult<HardRailId>
LegacyAuthorityAdapters::hard_rail(std::int64_t legacyValue,
                                   std::size_t extent) {
  return checked<HardRailId>(AuthorityDomain::HardRail, legacyValue, extent);
}

DomainResult<PeriodicRelationId>
LegacyAuthorityAdapters::periodic_relation(std::int64_t legacyValue,
                                           std::size_t extent) {
  return checked<PeriodicRelationId>(AuthorityDomain::PeriodicRelation,
                                     legacyValue, extent);
}

DomainResult<CellId> LegacyAuthorityAdapters::cell(std::int64_t legacyValue,
                                                    std::size_t extent) {
  return checked<CellId>(AuthorityDomain::Cell, legacyValue, extent);
}

DomainResult<OccurrenceId>
LegacyAuthorityAdapters::occurrence(std::int64_t legacyValue,
                                    std::size_t extent) {
  return checked<OccurrenceId>(AuthorityDomain::Occurrence, legacyValue, extent);
}

DomainResult<QuotientClassId>
LegacyAuthorityAdapters::quotient_class(std::int64_t legacyValue,
                                        std::size_t extent) {
  return checked<QuotientClassId>(AuthorityDomain::QuotientClass, legacyValue,
                                  extent);
}

} // namespace directional::authority
