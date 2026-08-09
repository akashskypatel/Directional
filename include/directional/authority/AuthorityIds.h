// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_AUTHORITY_IDS_H
#define DIRECTIONAL_AUTHORITY_AUTHORITY_IDS_H

#include <compare>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <utility>
#include <variant>

namespace directional::authority {

enum class AuthorityDomain : std::uint8_t {
  SourceVertex,
  SourceFace,
  SourceEdgeTopology,
  InteriorTransition,
  SourceComponent,
  IsolationSheet,
  TopologyRegion,
  FieldChart,
  HardRail,
  PeriodicRelation,
  Cell,
  Occurrence,
  QuotientClass,
};

enum class DomainErrorCode : std::uint8_t {
  NegativeLegacyValue,
  OutOfRangeLegacyValue,
  DomainMismatch,
  DegenerateSourceEdge,
  MissingInteriorTransition,
};

struct DomainError {
  DomainErrorCode code = DomainErrorCode::NegativeLegacyValue;
  AuthorityDomain expectedDomain = AuthorityDomain::SourceVertex;
  std::optional<AuthorityDomain> suppliedDomain;
  std::int64_t legacyValue = 0;
  std::size_t extent = 0;

  auto operator<=>(const DomainError &) const = default;
};

template <typename T> class DomainResult {
public:
  explicit DomainResult(T value) : state_(std::move(value)) {}
  explicit DomainResult(DomainError error) : state_(std::move(error)) {}

  [[nodiscard]] bool has_value() const noexcept {
    return std::holds_alternative<T>(state_);
  }

  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }

  [[nodiscard]] const T &value() const { return std::get<T>(state_); }
  [[nodiscard]] T &value() { return std::get<T>(state_); }
  [[nodiscard]] const DomainError &error() const {
    return std::get<DomainError>(state_);
  }

private:
  std::variant<T, DomainError> state_;
};

class LegacyAuthorityAdapters;

namespace detail {

struct SourceVertexTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::SourceVertex;
};
struct SourceFaceTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::SourceFace;
};
struct InteriorTransitionTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::InteriorTransition;
};
struct SourceComponentTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::SourceComponent;
};
struct IsolationSheetTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::IsolationSheet;
};
struct TopologyRegionTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::TopologyRegion;
};
struct FieldChartTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::FieldChart;
};
struct HardRailTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::HardRail;
};
struct PeriodicRelationTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::PeriodicRelation;
};
struct CellTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::Cell;
};
struct OccurrenceTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::Occurrence;
};
struct QuotientClassTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::QuotientClass;
};

} // namespace detail

template <typename Tag> class SemanticId {
public:
  SemanticId() = delete;

  [[nodiscard]] static constexpr AuthorityDomain domain() noexcept {
    return Tag::domain;
  }

  [[nodiscard]] constexpr std::size_t value() const noexcept { return value_; }

  auto operator<=>(const SemanticId &) const = default;

private:
  explicit constexpr SemanticId(std::size_t value) noexcept : value_(value) {}

  std::size_t value_;

  friend class LegacyAuthorityAdapters;
};

using SourceVertexId = SemanticId<detail::SourceVertexTag>;
using SourceFaceId = SemanticId<detail::SourceFaceTag>;
using InteriorTransitionId = SemanticId<detail::InteriorTransitionTag>;
using SourceComponentId = SemanticId<detail::SourceComponentTag>;
using IsolationSheetId = SemanticId<detail::IsolationSheetTag>;
using TopologyRegionId = SemanticId<detail::TopologyRegionTag>;
using FieldChartId = SemanticId<detail::FieldChartTag>;
using HardRailId = SemanticId<detail::HardRailTag>;
using PeriodicRelationId = SemanticId<detail::PeriodicRelationTag>;
using CellId = SemanticId<detail::CellTag>;
using OccurrenceId = SemanticId<detail::OccurrenceTag>;
using QuotientClassId = SemanticId<detail::QuotientClassTag>;

enum class Orientation : std::int8_t { Forward = 1, Reverse = -1 };

[[nodiscard]] constexpr Orientation reverse_orientation(Orientation orientation) {
  return orientation == Orientation::Forward ? Orientation::Reverse
                                             : Orientation::Forward;
}

class SourceEdgeTopologyKey {
public:
  [[nodiscard]] static DomainResult<SourceEdgeTopologyKey>
  make(SourceVertexId a, SourceVertexId b);

  [[nodiscard]] SourceVertexId first() const noexcept { return first_; }
  [[nodiscard]] SourceVertexId second() const noexcept { return second_; }

  auto operator<=>(const SourceEdgeTopologyKey &) const = default;

private:
  SourceEdgeTopologyKey(SourceVertexId first, SourceVertexId second)
      : first_(first), second_(second) {}

  SourceVertexId first_;
  SourceVertexId second_;
};

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_AUTHORITY_IDS_H
