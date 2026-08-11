// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/SourceSupport.h>

#include <algorithm>
#include <utility>

namespace directional::authority {

DomainResult<SourceEdgeTopologyKey>
SourceEdgeTopologyKey::make(SourceVertexId a, SourceVertexId b) {
  if (a == b) {
    return DomainResult<SourceEdgeTopologyKey>(DomainError{
        DomainErrorCode::DegenerateSourceEdge,
        AuthorityDomain::SourceEdgeTopology, std::nullopt,
        static_cast<std::int64_t>(a.index()), 0});
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

} // namespace directional::authority
