// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_LEGACY_AUTHORITY_ADAPTERS_H
#define DIRECTIONAL_AUTHORITY_LEGACY_AUTHORITY_ADAPTERS_H

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include <directional/authority/AuthorityIds.h>

namespace directional::authority {

class LegacyAuthorityAdapters {
public:
  template <typename Id>
  [[nodiscard]] static DomainResult<Id>
  checked(AuthorityDomain suppliedDomain, std::int64_t legacyValue,
          std::size_t extent) {
    static_assert(is_supported_id<Id>(),
                  "LegacyAuthorityAdapters::checked requires an authority ID");

    if (suppliedDomain != Id::domain()) {
      return DomainResult<Id>(DomainError{DomainErrorCode::DomainMismatch,
                                          Id::domain(), suppliedDomain,
                                          legacyValue, extent});
    }
    if (legacyValue < 0) {
      return DomainResult<Id>(DomainError{DomainErrorCode::NegativeLegacyValue,
                                          Id::domain(), suppliedDomain,
                                          legacyValue, extent});
    }
    const auto value = static_cast<std::uint64_t>(legacyValue);
    if (value >= static_cast<std::uint64_t>(extent)) {
      return DomainResult<Id>(DomainError{
          DomainErrorCode::OutOfRangeLegacyValue, Id::domain(), suppliedDomain,
          legacyValue, extent});
    }
    return DomainResult<Id>(Id(static_cast<std::size_t>(value)));
  }

  template <typename Id>
  [[nodiscard]] static std::size_t to_legacy_index(Id id) noexcept {
    static_assert(is_supported_id<Id>(),
                  "LegacyAuthorityAdapters::to_legacy_index requires an authority ID");
    return id.value();
  }

  [[nodiscard]] static DomainResult<SourceVertexId>
  source_vertex(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<SourceFaceId>
  source_face(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<InteriorTransitionId>
  interior_transition(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<SourceComponentId>
  source_component(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<IsolationSheetId>
  isolation_sheet(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<TopologyRegionId>
  topology_region(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<FieldChartId>
  field_chart(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<HardRailId>
  hard_rail(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<PeriodicRelationId>
  periodic_relation(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<CellId>
  cell(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<OccurrenceId>
  occurrence(std::int64_t legacyValue, std::size_t extent);
  [[nodiscard]] static DomainResult<QuotientClassId>
  quotient_class(std::int64_t legacyValue, std::size_t extent);

private:
  template <typename T> static consteval bool is_supported_id() {
    return std::is_same_v<T, SourceVertexId> ||
           std::is_same_v<T, SourceFaceId> ||
           std::is_same_v<T, InteriorTransitionId> ||
           std::is_same_v<T, SourceComponentId> ||
           std::is_same_v<T, IsolationSheetId> ||
           std::is_same_v<T, TopologyRegionId> ||
           std::is_same_v<T, FieldChartId> ||
           std::is_same_v<T, HardRailId> ||
           std::is_same_v<T, PeriodicRelationId> || std::is_same_v<T, CellId> ||
           std::is_same_v<T, OccurrenceId> ||
           std::is_same_v<T, QuotientClassId>;
  }
};

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_LEGACY_AUTHORITY_ADAPTERS_H
