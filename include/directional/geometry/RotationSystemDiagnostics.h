// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_ROTATION_SYSTEM_DIAGNOSTICS_H
#define DIRECTIONAL_GEOMETRY_ROTATION_SYSTEM_DIAGNOSTICS_H

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

#include <directional/authority/AuthorityIds.h>

namespace directional::geometry {

enum class GlobalTopologyArcKind : std::uint8_t;

/** Diagnostic-only projection of one exact ray-order operand. */
struct RotationRayOrderDiagnostic {
  explicit RotationRayOrderDiagnostic(authority::NetworkArcId arcId)
      : arc(arcId) {}

  GlobalTopologyArcKind kind{};
  std::size_t primary = 0U;
  std::size_t secondary = 0U;
  bool secondaryAvailable = true;
  authority::NetworkArcId arc;
  std::optional<authority::TraceId> trace;
  authority::Orientation orientation = authority::Orientation::Forward;
  std::optional<authority::SourceFaceTopologyKey> sourceFace;
  std::optional<std::size_t> fanSlot;
  std::optional<int> originPortOrdinal;
  std::optional<authority::SourceVertexId> originPortSourceVertex;

  auto operator<=>(const RotationRayOrderDiagnostic &) const = default;
};

struct RotationRayOrderCensus {
  std::vector<RotationRayOrderDiagnostic> rays;
  std::size_t totalRayCount = 0U;
  bool truncated = false;

  auto operator<=>(const RotationRayOrderCensus &) const = default;
};

} // namespace directional::geometry

#endif
