// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_CANONICAL_ROUTE_H
#define DIRECTIONAL_AUTHORITY_CANONICAL_ROUTE_H

#include <compare>
#include <optional>
#include <vector>

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/GridAutomorphism.h>

namespace directional::authority {

enum class TransitionStepKind : std::uint8_t { Boundary, Interior };

class TransitionStep {
public:
  [[nodiscard]] static TransitionStep
  boundary(SourceEdgeTopologyKey topology, GridAutomorphism transport,
           Orientation orientation);

  [[nodiscard]] static DomainResult<TransitionStep>
  interior(SourceEdgeTopologyKey topology,
           std::optional<InteriorTransitionId> interior,
           GridAutomorphism transport, Orientation orientation);

  [[nodiscard]] TransitionStepKind kind() const noexcept { return kind_; }
  [[nodiscard]] const SourceEdgeTopologyKey &topology() const noexcept {
    return topology_;
  }
  [[nodiscard]] const std::optional<InteriorTransitionId> &interior() const noexcept {
    return interior_;
  }
  [[nodiscard]] const GridAutomorphism &transport() const noexcept {
    return transport_;
  }
  [[nodiscard]] Orientation orientation() const noexcept { return orientation_; }

  [[nodiscard]] TransitionStep reversed() const;

  auto operator<=>(const TransitionStep &) const = default;

private:
  TransitionStep(TransitionStepKind kind, SourceEdgeTopologyKey topology,
                 std::optional<InteriorTransitionId> interior,
                 GridAutomorphism transport, Orientation orientation)
      : kind_(kind), topology_(topology), interior_(std::move(interior)),
        transport_(transport), orientation_(orientation) {}

  TransitionStepKind kind_;
  SourceEdgeTopologyKey topology_;
  std::optional<InteriorTransitionId> interior_;
  GridAutomorphism transport_;
  Orientation orientation_;
};

class CanonicalRoute {
public:
  CanonicalRoute() = default;

  [[nodiscard]] static CanonicalRoute
  from_observed_steps(std::vector<TransitionStep> observedSteps);

  [[nodiscard]] const std::vector<TransitionStep> &steps() const noexcept {
    return canonicalSteps_;
  }

  [[nodiscard]] Orientation canonical_orientation() const noexcept {
    return canonicalOrientation_;
  }

  [[nodiscard]] std::vector<TransitionStep> oriented_steps() const;
  [[nodiscard]] CanonicalRoute reversed() const;
  [[nodiscard]] GridAutomorphism composed_transport() const noexcept;
  [[nodiscard]] bool empty() const noexcept { return canonicalSteps_.empty(); }

  auto operator<=>(const CanonicalRoute &) const = default;

private:
  CanonicalRoute(std::vector<TransitionStep> canonicalSteps,
                 Orientation canonicalOrientation)
      : canonicalSteps_(std::move(canonicalSteps)),
        canonicalOrientation_(canonicalOrientation) {}

  [[nodiscard]] static std::vector<TransitionStep>
  reverse_steps(const std::vector<TransitionStep> &steps);

  std::vector<TransitionStep> canonicalSteps_;
  Orientation canonicalOrientation_ = Orientation::Forward;
};

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_CANONICAL_ROUTE_H
