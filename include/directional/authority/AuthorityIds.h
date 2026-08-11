// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_AUTHORITY_IDS_H
#define DIRECTIONAL_AUTHORITY_AUTHORITY_IDS_H

#include <array>
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
  NegativeIndex,
  IndexOutOfRange,
  DomainMismatch,
  DegenerateSourceEdge,
  DegenerateSourceFace,
  MissingInteriorTransition,
};

struct DomainError {
  DomainErrorCode code = DomainErrorCode::NegativeIndex;
  AuthorityDomain expectedDomain = AuthorityDomain::SourceVertex;
  std::optional<AuthorityDomain> suppliedDomain;
  std::int64_t inputValue = 0;
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

  [[nodiscard]] static DomainResult<SemanticId>
  from_index(std::int64_t inputValue, std::size_t extent) {
    if (inputValue < 0) {
      return DomainResult<SemanticId>(DomainError{
          DomainErrorCode::NegativeIndex, domain(), std::nullopt, inputValue,
          extent});
    }
    const auto value = static_cast<std::uint64_t>(inputValue);
    if (value >= extent) {
      return DomainResult<SemanticId>(DomainError{
          DomainErrorCode::IndexOutOfRange, domain(), std::nullopt, inputValue,
          extent});
    }
    return DomainResult<SemanticId>(SemanticId(static_cast<std::size_t>(value)));
  }

  [[nodiscard]] static DomainResult<SemanticId>
  from_domain_index(AuthorityDomain suppliedDomain, std::int64_t inputValue,
                    std::size_t extent) {
    if (suppliedDomain != domain()) {
      return DomainResult<SemanticId>(DomainError{
          DomainErrorCode::DomainMismatch, domain(), suppliedDomain, inputValue,
          extent});
    }
    return from_index(inputValue, extent);
  }

  /** Representation-leaf projection only; never a semantic identity. */
  [[nodiscard]] constexpr std::size_t index() const noexcept { return value_; }
  /** Compatibility spelling for representation leaves. */
  [[nodiscard]] constexpr std::size_t value() const noexcept { return index(); }

  auto operator<=>(const SemanticId &) const = default;

private:
  explicit constexpr SemanticId(std::size_t value) noexcept : value_(value) {}

  std::size_t value_;
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

class SourceFaceTopologyKey {
public:
  [[nodiscard]] static DomainResult<SourceFaceTopologyKey>
  make(std::array<SourceVertexId, 3> vertices);

  [[nodiscard]] const std::array<SourceVertexId, 3> &vertices() const noexcept {
    return vertices_;
  }

  auto operator<=>(const SourceFaceTopologyKey &) const = default;

private:
  explicit SourceFaceTopologyKey(std::array<SourceVertexId, 3> vertices)
      : vertices_(std::move(vertices)) {}

  std::array<SourceVertexId, 3> vertices_;
};

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_AUTHORITY_IDS_H
