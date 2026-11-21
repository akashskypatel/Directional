// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once
#ifndef DIRECTIONAL_AUTHORITY_EXACT_SOURCE_PATH_H
#define DIRECTIONAL_AUTHORITY_EXACT_SOURCE_PATH_H

#include <algorithm>
#include <array>
#include <optional>
#include <variant>
#include <vector>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/authority/SourceSupport.h>

namespace directional::authority {

struct ExactSourceEdgePoint {
  SourceEdgeTopologyKey edge;
  FieldExactRational parameter;
  auto operator<=>(const ExactSourceEdgePoint &) const = default;
};

struct ExactSourceFacePoint {
  SourceFaceTopologyKey face;
  std::array<FieldExactRational, 3> barycentric;
  auto operator<=>(const ExactSourceFacePoint &) const = default;
};

using ExactSourcePoint =
    std::variant<SourceVertexId, ExactSourceEdgePoint, ExactSourceFacePoint>;

struct ExactSourceSupportPiece {
  SourceSupport carrier;
  ExactSourcePoint first;
  ExactSourcePoint second;
  auto operator<=>(const ExactSourceSupportPiece &) const = default;
};

using ExactSourcePath = std::vector<ExactSourceSupportPiece>;

[[nodiscard]] inline std::optional<ExactSourcePoint>
canonical_exact_source_edge_point(const SourceEdgeTopologyKey &edge,
                                  const FieldExactRational &parameter) {
  const auto zero = FieldExactRational::from_integer(0);
  const auto one = FieldExactRational::from_integer(1);
  if (parameter < zero || parameter > one) return std::nullopt;
  if (parameter == zero) return ExactSourcePoint{edge.first()};
  if (parameter == one) return ExactSourcePoint{edge.second()};
  return ExactSourcePoint{ExactSourceEdgePoint{edge, parameter}};
}

[[nodiscard]] inline std::optional<ExactSourcePoint>
canonical_exact_source_boundary_point(const FieldBoundaryPoint &point) {
  if (!point.parameter.in_unit_interval()) return std::nullopt;
  return canonical_exact_source_edge_point(point.edge, point.parameter.value);
}

[[nodiscard]] inline std::optional<ExactSourcePoint>
canonical_exact_source_face_point(
    const SourceFaceTopologyKey &face,
    const std::array<FieldExactRational, 3> &barycentric) {
  const auto zero = FieldExactRational::from_integer(0);
  const auto one = FieldExactRational::from_integer(1);
  FieldExactRational sum = zero;
  std::size_t zeroCount = 0U;
  for (const auto &coordinate : barycentric) {
    if (coordinate < zero) return std::nullopt;
    if (coordinate == zero) ++zeroCount;
    sum = sum + coordinate;
  }
  if (sum != one || zeroCount == 3U) return std::nullopt;

  const auto &vertices = face.vertices();
  if (zeroCount == 2U) {
    for (std::size_t corner = 0U; corner < 3U; ++corner) {
      if (barycentric[corner] == one) return ExactSourcePoint{vertices[corner]};
    }
    return std::nullopt;
  }
  if (zeroCount == 1U) {
    std::array<std::size_t, 2> nonzero{};
    std::size_t count = 0U;
    for (std::size_t corner = 0U; corner < 3U; ++corner) {
      if (barycentric[corner] != zero) nonzero[count++] = corner;
    }
    if (count != 2U) return std::nullopt;
    const auto edge = SourceEdgeTopologyKey::make(
        vertices[nonzero[0]], vertices[nonzero[1]]);
    if (!edge) return std::nullopt;
    const auto second = std::find(vertices.begin(), vertices.end(),
                                  edge.value().second());
    if (second == vertices.end()) return std::nullopt;
    return canonical_exact_source_edge_point(
        edge.value(), barycentric[static_cast<std::size_t>(
                          std::distance(vertices.begin(), second))]);
  }
  return ExactSourcePoint{ExactSourceFacePoint{face, barycentric}};
}

[[nodiscard]] inline bool
exact_source_point_is_canonical(const ExactSourcePoint &point) {
  const auto zero = FieldExactRational::from_integer(0);
  const auto one = FieldExactRational::from_integer(1);
  if (std::holds_alternative<SourceVertexId>(point)) return true;
  if (const auto *edge = std::get_if<ExactSourceEdgePoint>(&point)) {
    return edge->parameter > zero && edge->parameter < one;
  }
  const auto &face = std::get<ExactSourceFacePoint>(point);
  FieldExactRational sum = zero;
  for (const auto &coordinate : face.barycentric) {
    if (coordinate <= zero) return false;
    sum = sum + coordinate;
  }
  return sum == one;
}

[[nodiscard]] inline bool source_face_contains_edge(
    const SourceFaceTopologyKey &face, const SourceEdgeTopologyKey &edge) {
  const auto &vertices = face.vertices();
  return std::find(vertices.begin(), vertices.end(), edge.first()) !=
             vertices.end() &&
         std::find(vertices.begin(), vertices.end(), edge.second()) !=
             vertices.end();
}

[[nodiscard]] inline bool exact_source_support_contains_point(
    const SourceSupport &carrier, const ExactSourcePoint &point) {
  if (const auto *vertex = std::get_if<SourceVertexSupport>(&carrier)) {
    const auto *pointVertex = std::get_if<SourceVertexId>(&point);
    return pointVertex != nullptr && *pointVertex == vertex->vertex;
  }
  if (const auto *edge = std::get_if<SourceEdgeSupport>(&carrier)) {
    if (const auto *pointVertex = std::get_if<SourceVertexId>(&point)) {
      return *pointVertex == edge->edge.first() ||
             *pointVertex == edge->edge.second();
    }
    const auto *edgePoint = std::get_if<ExactSourceEdgePoint>(&point);
    return edgePoint != nullptr && edgePoint->edge == edge->edge;
  }

  const auto face = std::get<SourceFaceInteriorSupport>(carrier).face;
  if (const auto *pointVertex = std::get_if<SourceVertexId>(&point)) {
    const auto &vertices = face.vertices();
    return std::find(vertices.begin(), vertices.end(), *pointVertex) !=
           vertices.end();
  }
  if (const auto *edgePoint = std::get_if<ExactSourceEdgePoint>(&point)) {
    return source_face_contains_edge(face, edgePoint->edge);
  }
  return std::get<ExactSourceFacePoint>(point).face == face;
}

[[nodiscard]] inline bool
exact_source_path_is_canonical(const ExactSourcePath &path) {
  if (path.empty()) return false;
  std::optional<ExactSourcePoint> previous;
  for (const auto &piece : path) {
    if (!exact_source_point_is_canonical(piece.first) ||
        !exact_source_point_is_canonical(piece.second) ||
        piece.first == piece.second ||
        !exact_source_support_contains_point(piece.carrier, piece.first) ||
        !exact_source_support_contains_point(piece.carrier, piece.second) ||
        (previous.has_value() && *previous != piece.first)) {
      return false;
    }
    previous = piece.second;
  }
  return true;
}

[[nodiscard]] inline ExactSourcePath
reverse_exact_source_path(const ExactSourcePath &path) {
  ExactSourcePath reversed;
  reversed.reserve(path.size());
  for (auto it = path.rbegin(); it != path.rend(); ++it) {
    reversed.push_back(ExactSourceSupportPiece{it->carrier, it->second,
                                               it->first});
  }
  return reversed;
}

[[nodiscard]] inline ExactSourcePath exact_source_path_for_orientation(
    const ExactSourcePath &path, const Orientation orientation) {
  return orientation == Orientation::Forward ? path
                                              : reverse_exact_source_path(path);
}

} // namespace directional::authority

#endif // DIRECTIONAL_AUTHORITY_EXACT_SOURCE_PATH_H
