// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_SOURCE_SUPPORT_H
#define DIRECTIONAL_AUTHORITY_SOURCE_SUPPORT_H

#include <variant>

#include <directional/authority/AuthorityIds.h>

namespace directional::authority {

struct SourceVertexSupport {
  SourceVertexId vertex;
  auto operator<=>(const SourceVertexSupport &) const = default;
};

struct SourceEdgeSupport {
  SourceEdgeTopologyKey edge;
  auto operator<=>(const SourceEdgeSupport &) const = default;
};

struct SourceFaceInteriorSupport {
  // Canonical source simplex. Raw source-face rows are representation leaves
  // and never participate in support equality/order/hash.
  SourceFaceTopologyKey face;
  auto operator<=>(const SourceFaceInteriorSupport &) const = default;
};

using SourceSupport =
    std::variant<SourceVertexSupport, SourceEdgeSupport, SourceFaceInteriorSupport>;

enum class SourceSupportKind : std::uint8_t { Vertex, Edge, FaceInterior };

[[nodiscard]] constexpr SourceSupportKind support_kind(const SourceSupport &support) {
  if (std::holds_alternative<SourceVertexSupport>(support)) {
    return SourceSupportKind::Vertex;
  }
  if (std::holds_alternative<SourceEdgeSupport>(support)) {
    return SourceSupportKind::Edge;
  }
  return SourceSupportKind::FaceInterior;
}

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_SOURCE_SUPPORT_H
