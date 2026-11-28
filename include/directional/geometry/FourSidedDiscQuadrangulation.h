// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_FOUR_SIDED_DISC_QUADRANGULATION_H
#define DIRECTIONAL_GEOMETRY_FOUR_SIDED_DISC_QUADRANGULATION_H

#include <array>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <variant>
#include <vector>

namespace directional::geometry {

/** Why a four-corner disc could not be quadrangulated. */
enum class FourSidedDiscQuadrangulationFailure : std::uint8_t {
  /** The side counts add up to an odd number of boundary edges. */
  OddBoundary = 0,
  /** A side has no edge. */
  NonPositiveSide = 1,
  /** A side exceeds kFourSidedDiscMaxSideCount. */
  SideBeyondSizeBound = 2,
  /** The side counts lie outside the domain of the construction family
   *  (see quadrangulate_four_sided_disc). */
  OutsideConstructionDomain = 3,
};

[[nodiscard]] const char *four_sided_disc_quadrangulation_failure_name(
    FourSidedDiscQuadrangulationFailure failure) noexcept;

/** Largest side count accepted, so every vertex count fits in std::size_t. */
inline constexpr std::size_t kFourSidedDiscMaxSideCount = std::size_t{1} << 16U;

/** An interior vertex whose valence is not 4. */
struct FourSidedDiscIrregularVertex {
  std::size_t vertex = 0U;
  int valence = 0;

  auto operator<=>(const FourSidedDiscIrregularVertex &) const = default;
};

/**
 * A combinatorial pure-quad disc. Vertices are 0 .. vertexCount - 1. The
 * boundary cycle starts at the corner where side 0 begins and runs in walk
 * order; side k is boundary[sideStarts[k]] .. boundary[sideStarts[k+1]]
 * (cyclically), so sideStarts[k] is the sum of the earlier side counts. Every
 * quad lists its vertices in the boundary's orientation: each boundary edge
 * (boundary[i], boundary[i + 1]) appears in its quad in that direction.
 * Corners have valence 2, every other boundary vertex valence 3, and interior
 * vertices valence 4 except irregularVertices (valence 3 or 5, sorted by id).
 */
struct FourSidedDiscQuadrangulation {
  std::size_t vertexCount = 0U;
  std::vector<std::array<std::size_t, 4>> quads;
  std::vector<std::size_t> boundary;
  std::array<std::size_t, 4> sideStarts{};
  std::vector<FourSidedDiscIrregularVertex> irregularVertices;

  auto operator<=>(const FourSidedDiscQuadrangulation &) const = default;
};

using FourSidedDiscQuadrangulationResult =
    std::variant<FourSidedDiscQuadrangulation, FourSidedDiscQuadrangulationFailure>;

/**
 * Quadrangulates the four-corner disc whose sides, in walk order, have
 * sideCounts[0..3] edges, with a regular boundary and the fewest interior
 * irregular vertices the family needs. Deterministic; no geometry.
 *
 * Domain: an even total and either equal opposite sides (the grid, no
 * irregular vertex) or a rotation (A, B, C, D) of the side counts with
 *   A >= 2, B >= 2, C + D >= A + B + 4 and A + B >= |C - D| + 4
 * (one valence-3 and one valence-5 vertex). The family's derivation is in
 * FourSidedDiscQuadrangulation.cpp.
 */
[[nodiscard]] FourSidedDiscQuadrangulationResult
quadrangulate_four_sided_disc(const std::array<std::size_t, 4> &sideCounts);

} // namespace directional::geometry

#endif
