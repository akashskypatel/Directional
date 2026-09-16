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
#include <type_traits>
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
  SurfaceCellOwnershipClass,
  FieldChart,
  FieldTransportAdjacency,
  FieldCycle,
  FieldSingularity,
  NetworkNode,
  NetworkEdge,
  SingularityPort,
  Trace,
  SourceVertexFan,
  HardRail,
  PeriodicRelation,
  Cell,
  Occurrence,
  QuotientClass,
  NetworkRegion,
  NetworkArc,
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
struct SurfaceCellOwnershipClassTag {
  static constexpr AuthorityDomain domain =
      AuthorityDomain::SurfaceCellOwnershipClass;
};
struct FieldChartTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::FieldChart;
};
struct FieldTransportAdjacencyTag {
  static constexpr AuthorityDomain domain =
      AuthorityDomain::FieldTransportAdjacency;
};
struct FieldCycleTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::FieldCycle;
};
struct FieldSingularityTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::FieldSingularity;
};
struct NetworkNodeTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::NetworkNode;
};
struct NetworkEdgeTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::NetworkEdge;
};
struct NetworkRegionTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::NetworkRegion;
};
struct NetworkArcTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::NetworkArc;
};
struct SingularityPortTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::SingularityPort;
};
struct TraceTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::Trace;
};
struct SourceVertexFanTag {
  static constexpr AuthorityDomain domain = AuthorityDomain::SourceVertexFan;
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
using SurfaceCellOwnershipClassId =
    SemanticId<detail::SurfaceCellOwnershipClassTag>;
using FieldChartId = SemanticId<detail::FieldChartTag>;
using FieldTransportAdjacencyId =
    SemanticId<detail::FieldTransportAdjacencyTag>;
using FieldCycleId = SemanticId<detail::FieldCycleTag>;
using FieldSingularityId = SemanticId<detail::FieldSingularityTag>;
using NetworkNodeId = SemanticId<detail::NetworkNodeTag>;
using NetworkEdgeId = SemanticId<detail::NetworkEdgeTag>;
using NetworkRegionId = SemanticId<detail::NetworkRegionTag>;
using NetworkArcId = SemanticId<detail::NetworkArcTag>;
using SingularityPortId = SemanticId<detail::SingularityPortTag>;
using TraceId = SemanticId<detail::TraceTag>;
using SourceVertexFanId = SemanticId<detail::SourceVertexFanTag>;
using HardRailId = SemanticId<detail::HardRailTag>;
using PeriodicRelationId = SemanticId<detail::PeriodicRelationTag>;
using CellId = SemanticId<detail::CellTag>;
using OccurrenceId = SemanticId<detail::OccurrenceTag>;
using QuotientClassId = SemanticId<detail::QuotientClassTag>;

// WU2A0 compile contracts: numeric values are explicit representation
// projections only. Semantic IDs cannot silently cross a container boundary or
// another semantic domain through implicit conversion/construction.
static_assert(!std::is_convertible_v<SourceVertexId, std::size_t>);
static_assert(!std::is_convertible_v<SourceFaceId, std::size_t>);
static_assert(!std::is_convertible_v<SourceComponentId, std::size_t>);
static_assert(!std::is_convertible_v<IsolationSheetId, std::size_t>);
static_assert(!std::is_convertible_v<TopologyRegionId, std::size_t>);
static_assert(!std::is_convertible_v<FieldChartId, std::size_t>);
static_assert(!std::is_convertible_v<FieldTransportAdjacencyId, std::size_t>);
static_assert(!std::is_convertible_v<FieldCycleId, std::size_t>);
static_assert(!std::is_convertible_v<FieldSingularityId, std::size_t>);
static_assert(!std::is_convertible_v<NetworkNodeId, std::size_t>);
static_assert(!std::is_convertible_v<NetworkEdgeId, std::size_t>);
static_assert(!std::is_convertible_v<SingularityPortId, std::size_t>);
static_assert(!std::is_convertible_v<TraceId, std::size_t>);
static_assert(!std::is_convertible_v<NetworkNodeId, NetworkEdgeId>);
static_assert(!std::is_convertible_v<NetworkEdgeId, NetworkNodeId>);
static_assert(!std::is_convertible_v<SingularityPortId, FieldSingularityId>);
static_assert(!std::is_convertible_v<FieldSingularityId, SingularityPortId>);
static_assert(!std::is_constructible_v<SourceVertexId, std::size_t>);
static_assert(!std::is_constructible_v<SourceFaceId, std::size_t>);
static_assert(!std::is_convertible_v<TopologyRegionId, FieldChartId>);
static_assert(!std::is_convertible_v<FieldChartId, TopologyRegionId>);
static_assert(!std::is_convertible_v<SurfaceCellOwnershipClassId,
                                     TopologyRegionId>);
static_assert(!std::is_convertible_v<TopologyRegionId,
                                     SurfaceCellOwnershipClassId>);

enum class Orientation : std::int8_t { Forward = 1, Reverse = -1 };

[[nodiscard]] constexpr Orientation reverse_orientation(Orientation orientation) {
  return orientation == Orientation::Forward ? Orientation::Reverse
                                             : Orientation::Forward;
}

class SourceEdgeTopologyKey {
public:
  [[nodiscard]] static DomainResult<SourceEdgeTopologyKey>
  make(SourceVertexId a, SourceVertexId b);

  [[nodiscard]] static DomainResult<SourceEdgeTopologyKey>
  from_indices(std::int64_t a, std::int64_t b, std::size_t vertexExtent) {
    const auto first = SourceVertexId::from_index(a, vertexExtent);
    if (!first) return DomainResult<SourceEdgeTopologyKey>(first.error());
    const auto second = SourceVertexId::from_index(b, vertexExtent);
    if (!second) return DomainResult<SourceEdgeTopologyKey>(second.error());
    return make(first.value(), second.value());
  }

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
