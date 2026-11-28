#include <directional/geometry/FourSidedDiscQuadrangulation.h>

#include <algorithm>
#include <optional>

// Construction family and its bound.
//
// Counting. Let a quad disc have corners of valence 2 and every other boundary
// vertex of valence 3. With V - E + F = 1 and 4F = 2E - |boundary|, the sum
// over interior vertices of (4 - valence) is 0. So with valences 3 and 5 only,
// #valence-3 = #valence-5, and a disc with no interior irregular vertex is a
// flat quad grid with four convex corners: the w x h grid, which needs equal
// opposite sides. Hence any filling with unequal opposite sides has at least
// two interior irregular vertices.
//
// Grid class. a = c and b = d: the a x b grid, no irregular vertex.
//
// Pentagon-triangle class. Glue rectangular grid blocks edge to edge. At a
// vertex, each block it is a corner of contributes one quarter turn and each
// block side it lies inside contributes two; the valence equals the number of
// quarter turns, plus one on the boundary. Five blocks around one hub (hub5)
// with spokes g1..g5 form a pentagon whose side i is g(i-1) + g(i+1); three
// blocks around hub3 with spokes hg, hu, hv form a triangle with sides hu + hv
// (glued), hg + hv (U) and hu + hg (V). Gluing the triangle's first side onto
// pentagon side 5 (needs g4 + g1 = hu + hv) flattens both ends of the glued
// side, leaving four corners. Every vertex then has two quarter turns on the
// boundary (valence 3) or four inside (valence 4), except the four corners
// (one quarter turn, valence 2), hub3 (valence 3) and hub5 (valence 5). In
// walk order from pentagon corner X2 the sides are
//   A = g1 + g3,  B = g2 + g4,  C = g3 + g5 + hg + hv,  D = hu + hg + g5 + g2.
// With g1 = x, g3 = A - x, g4 = y and g2 = B - y, the side and gluing
// equations give g5 + hg = (C + D - A - B) / 2, hv = x + (B - A + C - D) / 2
// and hu = y + (A - B + D - C) / 2; the halvings are exact because the total
// is even. hv grows with x, hu with y, and g5 and hg share a fixed sum, so
// x = A - 1, y = B - 1 and g5 = 1 are optimal: g2 = g3 = g5 = 1,
// hg = (C + D - A - B) / 2 - 1, hv = (A + B - 2 + C - D) / 2 and
// hu = (A + B - 2 - C + D) / 2. All parameters are positive exactly when
//   A >= 2, B >= 2, C + D >= A + B + 4 and A + B >= |C - D| + 4,
// so these inequalities are this layout's exact domain. Rotations are tried
// in order 0..3 and the first that fits is used; a reflection adds nothing,
// since it swaps A with B and C with D, which leaves the inequalities as
// they are.
//
// Theorem. Every even-total input with equal opposite sides is filled with no
// irregular vertex, and every even-total input with a rotation satisfying the
// inequalities above with exactly one valence-3 and one valence-5 vertex,
// which is the minimum for unequal opposite sides. The family is uniform in
// the parity class of the opposite differences: (a - c, b - d) both odd, as
// (30, 35, 35, 32) through the rotation (32, 30, 35, 35), and both even and not
// both zero, as (31, 35, 35, 31) through (31, 31, 35, 35). Over rotations,
// C + D - A - B takes the values +-(a - c) +- (b - d), so the class needs
// |a - c| + |b - d| >= 4. Inputs outside the domain are reported, not
// repaired. Some are not fillable at all under this boundary rule: two
// adjacent one-edge sides force all four sides to one edge, and b = d = 1
// forces a = c.

namespace directional::geometry {
namespace {

using Chain = std::vector<std::size_t>;

Chain reversed(Chain chain) {
  std::reverse(chain.begin(), chain.end());
  return chain;
}

// chain[first] .. chain[last], inclusive.
Chain slice(const Chain &chain, const std::size_t first, const std::size_t last) {
  return Chain(chain.begin() + static_cast<std::ptrdiff_t>(first),
               chain.begin() + static_cast<std::ptrdiff_t>(last) + 1);
}

// `first` followed by `second`, which starts where `first` ends.
Chain joined(Chain first, const Chain &second) {
  first.insert(first.end(), second.begin() + 1, second.end());
  return first;
}

class QuadDiscBuilder {
public:
  std::size_t vertex() { return vertexCount_++; }

  // `length` edges from `from` to `to`, with new vertices between them.
  Chain path(const std::size_t from, const std::size_t to,
             const std::size_t length) {
    Chain chain{from};
    for (std::size_t step = 1U; step < length; ++step) chain.push_back(vertex());
    chain.push_back(to);
    return chain;
  }

  // A w x h grid block bounded, in walk order, by bottom (w edges), right
  // (h), top (w) and left (h); each chain starts where the previous one ends.
  void block(const Chain &bottom, const Chain &right, const Chain &top,
             const Chain &left) {
    const std::size_t w = bottom.size() - 1U;
    const std::size_t h = right.size() - 1U;
    std::vector<std::size_t> grid((w + 1U) * (h + 1U), 0U);
    const auto at = [&](const std::size_t i, const std::size_t j)
        -> std::size_t & { return grid[i * (h + 1U) + j]; };
    for (std::size_t j = 0U; j <= h; ++j) {
      for (std::size_t i = 0U; i <= w; ++i) {
        if (j == 0U) {
          at(i, j) = bottom[i];
        } else if (i == w) {
          at(i, j) = right[j];
        } else if (j == h) {
          at(i, j) = top[w - i];
        } else if (i == 0U) {
          at(i, j) = left[h - j];
        } else {
          at(i, j) = vertex();
        }
      }
    }
    for (std::size_t j = 0U; j < h; ++j) {
      for (std::size_t i = 0U; i < w; ++i) {
        quads_.push_back({at(i, j), at(i + 1U, j), at(i + 1U, j + 1U),
                          at(i, j + 1U)});
      }
    }
  }

  // sides[k] runs from the corner before side k to the corner after it.
  FourSidedDiscQuadrangulation finish(
      const std::array<Chain, 4> &sides,
      std::vector<FourSidedDiscIrregularVertex> irregular) {
    FourSidedDiscQuadrangulation result;
    for (std::size_t side = 0U; side < 4U; ++side) {
      result.sideStarts[side] = result.boundary.size();
      result.boundary.insert(result.boundary.end(), sides[side].begin(),
                             sides[side].end() - 1);
    }
    std::sort(irregular.begin(), irregular.end());
    result.vertexCount = vertexCount_;
    result.quads = std::move(quads_);
    result.irregularVertices = std::move(irregular);
    return result;
  }

private:
  std::size_t vertexCount_ = 0U;
  std::vector<std::array<std::size_t, 4>> quads_;
};

bool pentagon_triangle_fits(const std::size_t a, const std::size_t b,
                            const std::size_t c, const std::size_t d) {
  const std::size_t sideDifference = c > d ? c - d : d - c;
  return a >= 2U && b >= 2U && c + d >= a + b + 4U &&
         a + b >= sideDifference + 4U;
}

FourSidedDiscQuadrangulation grid(const std::array<std::size_t, 4> &counts) {
  QuadDiscBuilder builder;
  std::array<std::size_t, 4> corner{};
  for (auto &value : corner) value = builder.vertex();
  std::array<Chain, 4> sides;
  for (std::size_t side = 0U; side < 4U; ++side) {
    sides[side] =
        builder.path(corner[side], corner[(side + 1U) % 4U], counts[side]);
  }
  builder.block(sides[0], sides[1], sides[2], sides[3]);
  return builder.finish(sides, {});
}

// Sides (A, B, C, D) are counts[rotation], counts[rotation + 1], ...
FourSidedDiscQuadrangulation pentagon_triangle(
    const std::array<std::size_t, 4> &counts, const std::size_t rotation) {
  const std::size_t a = counts[rotation];
  const std::size_t b = counts[(rotation + 1U) % 4U];
  const std::size_t c = counts[(rotation + 2U) % 4U];
  const std::size_t d = counts[(rotation + 3U) % 4U];
  // Spoke lengths, index 1..5 around hub5 (index 0 unused).
  const std::array<std::size_t, 6> g{0U, a - 1U, 1U, 1U, b - 1U, 1U};
  const std::size_t gluedLength = g[1] + g[4];
  const std::size_t hg = (c + d - a - b) / 2U - 1U;
  const std::size_t hv = (a + b + c - 2U - d) / 2U;
  const std::size_t hu = (a + b + d - 2U - c) / 2U;
  const auto previous = [](const std::size_t i) { return i == 1U ? 5U : i - 1U; };
  const auto next = [](const std::size_t i) { return i == 5U ? 1U : i + 1U; };

  QuadDiscBuilder builder;
  std::array<std::size_t, 6> corner{};  // pentagon corners X1..X5
  for (std::size_t i = 1U; i <= 5U; ++i) corner[i] = builder.vertex();
  const std::size_t freeCorner = builder.vertex();  // the triangle's corner
  const std::size_t hub5 = builder.vertex();
  const std::size_t hub3 = builder.vertex();
  std::array<std::size_t, 6> spokeEnd{};
  for (std::size_t i = 1U; i <= 4U; ++i) spokeEnd[i] = builder.vertex();
  const std::size_t onU = builder.vertex();
  const std::size_t onV = builder.vertex();
  // Pentagon side 5 from X1 to X5, shared with the triangle.
  const Chain glued = builder.path(corner[1], corner[5], gluedLength);
  spokeEnd[5] = glued[g[1]];
  const std::size_t onGlued = glued[hv];

  std::array<Chain, 6> spoke;
  for (std::size_t i = 1U; i <= 5U; ++i) {
    spoke[i] = builder.path(hub5, spokeEnd[i], g[i]);
  }
  // Pentagon side i: X(i) -> spokeEnd(i) -> X(i + 1).
  std::array<Chain, 6> toSpokeEnd;
  std::array<Chain, 6> fromSpokeEnd;
  for (std::size_t i = 1U; i <= 4U; ++i) {
    toSpokeEnd[i] = builder.path(corner[i], spokeEnd[i], g[previous(i)]);
    fromSpokeEnd[i] = builder.path(spokeEnd[i], corner[next(i)], g[next(i)]);
  }
  toSpokeEnd[5] = reversed(slice(glued, g[1], gluedLength));
  fromSpokeEnd[5] = reversed(slice(glued, 0U, g[1]));
  for (std::size_t i = 1U; i <= 5U; ++i) {
    builder.block(spoke[i], fromSpokeEnd[i], toSpokeEnd[next(i)],
                  reversed(spoke[next(i)]));
  }

  const Chain spokeG = builder.path(hub3, onGlued, hg);
  const Chain spokeU = builder.path(hub3, onU, hu);
  const Chain spokeV = builder.path(hub3, onV, hv);
  const Chain uFirst = builder.path(corner[5], onU, hg);
  const Chain uSecond = builder.path(onU, freeCorner, hv);
  const Chain vFirst = builder.path(freeCorner, onV, hu);
  const Chain vSecond = builder.path(onV, corner[1], hg);
  builder.block(spokeG, slice(glued, hv, gluedLength), uFirst, reversed(spokeU));
  builder.block(spokeU, uSecond, vFirst, reversed(spokeV));
  builder.block(spokeV, vSecond, slice(glued, 0U, hv), reversed(spokeG));

  const std::array<Chain, 4> canonical{
      joined(toSpokeEnd[2], fromSpokeEnd[2]),
      joined(toSpokeEnd[3], fromSpokeEnd[3]),
      joined(joined(joined(toSpokeEnd[4], fromSpokeEnd[4]), uFirst), uSecond),
      joined(joined(joined(vFirst, vSecond), toSpokeEnd[1]), fromSpokeEnd[1])};
  std::array<Chain, 4> sides;
  for (std::size_t side = 0U; side < 4U; ++side) {
    sides[side] = canonical[(side + 4U - rotation) % 4U];
  }
  return builder.finish(sides, {{hub5, 5}, {hub3, 3}});
}

} // namespace

const char *four_sided_disc_quadrangulation_failure_name(
    const FourSidedDiscQuadrangulationFailure failure) noexcept {
  switch (failure) {
  case FourSidedDiscQuadrangulationFailure::OddBoundary:
    return "odd-boundary";
  case FourSidedDiscQuadrangulationFailure::NonPositiveSide:
    return "non-positive-side";
  case FourSidedDiscQuadrangulationFailure::SideBeyondSizeBound:
    return "side-beyond-size-bound";
  case FourSidedDiscQuadrangulationFailure::OutsideConstructionDomain:
    return "outside-construction-domain";
  }
  return "unknown";
}

FourSidedDiscQuadrangulationResult
quadrangulate_four_sided_disc(const std::array<std::size_t, 4> &sideCounts) {
  using Failure = FourSidedDiscQuadrangulationFailure;
  std::size_t total = 0U;
  for (const std::size_t count : sideCounts) {
    if (count == 0U) return Failure::NonPositiveSide;
    if (count > kFourSidedDiscMaxSideCount) return Failure::SideBeyondSizeBound;
    total += count;
  }
  if (total % 2U != 0U) return Failure::OddBoundary;
  if (sideCounts[0] == sideCounts[2] && sideCounts[1] == sideCounts[3]) {
    return grid(sideCounts);
  }
  for (std::size_t rotation = 0U; rotation < 4U; ++rotation) {
    if (pentagon_triangle_fits(sideCounts[rotation],
                               sideCounts[(rotation + 1U) % 4U],
                               sideCounts[(rotation + 2U) % 4U],
                               sideCounts[(rotation + 3U) % 4U])) {
      return pentagon_triangle(sideCounts, rotation);
    }
  }
  return Failure::OutsideConstructionDomain;
}

} // namespace directional::geometry
