#include <directional/geometry/FourSidedDiscQuadrangulation.h>

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <deque>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <variant>
#include <vector>

namespace {

using directional::geometry::FourSidedDiscQuadrangulation;
using directional::geometry::FourSidedDiscQuadrangulationFailure;
using directional::geometry::quadrangulate_four_sided_disc;
using Sides = std::array<std::size_t, 4>;

std::string sides_text(const Sides &sides) {
  return "(" + std::to_string(sides[0]) + "," + std::to_string(sides[1]) + "," +
         std::to_string(sides[2]) + "," + std::to_string(sides[3]) + ")";
}

// Independent structural check: the first defect found, or none.
std::optional<std::string> structural_defect(const FourSidedDiscQuadrangulation &disc,
                                             const Sides &sides) {
  const std::size_t vertexCount = disc.vertexCount;
  std::size_t total = 0U;
  for (const std::size_t count : sides) total += count;
  if (disc.boundary.size() != total) return "boundary length";
  std::size_t offset = 0U;
  for (std::size_t side = 0U; side < 4U; ++side) {
    if (disc.sideStarts[side] != offset) return "side start";
    offset += sides[side];
  }

  std::map<std::pair<std::size_t, std::size_t>, std::size_t> directed;
  std::vector<std::set<std::size_t>> neighbours(vertexCount);
  std::vector<bool> used(vertexCount, false);
  for (const auto &quad : disc.quads) {
    if (std::set<std::size_t>(quad.begin(), quad.end()).size() != 4U) {
      return "quad repeats a vertex";
    }
    for (std::size_t k = 0U; k < 4U; ++k) {
      const std::size_t from = quad[k];
      const std::size_t to = quad[(k + 1U) % 4U];
      if (from >= vertexCount || to >= vertexCount) return "vertex out of range";
      if (++directed[{from, to}] > 1U) return "directed edge in two quads";
      neighbours[from].insert(to);
      neighbours[to].insert(from);
      used[from] = true;
    }
  }
  if (std::find(used.begin(), used.end(), false) != used.end()) {
    return "vertex in no quad";
  }

  std::set<std::pair<std::size_t, std::size_t>> undirected;
  std::set<std::pair<std::size_t, std::size_t>> unpaired;
  for (const auto &[edge, count] : directed) {
    (void)count;
    undirected.insert(std::minmax(edge.first, edge.second));
    if (directed.count({edge.second, edge.first}) == 0U) unpaired.insert(edge);
  }
  const std::set<std::size_t> onBoundary(disc.boundary.begin(), disc.boundary.end());
  if (onBoundary.size() != total) return "boundary repeats a vertex";
  std::set<std::pair<std::size_t, std::size_t>> cycle;
  for (std::size_t index = 0U; index < total; ++index) {
    cycle.insert({disc.boundary[index], disc.boundary[(index + 1U) % total]});
  }
  if (cycle != unpaired) return "boundary is not the one-quad edges";
  if (static_cast<long long>(vertexCount) -
          static_cast<long long>(undirected.size()) +
          static_cast<long long>(disc.quads.size()) != 1LL) {
    return "Euler characteristic";
  }

  // Manifold: the quads around each vertex form one fan, closed inside and
  // open on the boundary.
  std::vector<std::map<std::size_t, std::vector<std::size_t>>> link(vertexCount);
  for (const auto &quad : disc.quads) {
    for (std::size_t k = 0U; k < 4U; ++k) {
      const std::size_t center = quad[k];
      const std::size_t before = quad[(k + 3U) % 4U];
      const std::size_t after = quad[(k + 1U) % 4U];
      link[center][before].push_back(after);
      link[center][after].push_back(before);
    }
  }
  for (std::size_t center = 0U; center < vertexCount; ++center) {
    std::size_t ends = 0U;
    for (const auto &[node, adjacent] : link[center]) {
      (void)node;
      if (adjacent.size() > 2U) return "non-manifold fan";
      if (adjacent.size() == 1U) ++ends;
    }
    if (ends != (onBoundary.count(center) != 0U ? 2U : 0U)) return "fan not closed";
    std::set<std::size_t> reached{link[center].begin()->first};
    std::deque<std::size_t> pending{link[center].begin()->first};
    while (!pending.empty()) {
      const std::size_t node = pending.front();
      pending.pop_front();
      for (const std::size_t other : link[center][node]) {
        if (reached.insert(other).second) pending.push_back(other);
      }
    }
    if (reached.size() != link[center].size()) return "fan split";
  }

  std::vector<bool> reached(vertexCount, false);
  std::deque<std::size_t> pending{0U};
  reached[0] = true;
  std::size_t reachedCount = 1U;
  while (!pending.empty()) {
    const std::size_t vertex = pending.front();
    pending.pop_front();
    for (const std::size_t other : neighbours[vertex]) {
      if (!reached[other]) {
        reached[other] = true;
        ++reachedCount;
        pending.push_back(other);
      }
    }
  }
  if (reachedCount != vertexCount) return "disconnected";

  std::set<std::size_t> corners;
  for (const std::size_t start : disc.sideStarts) corners.insert(disc.boundary[start]);
  std::vector<directional::geometry::FourSidedDiscIrregularVertex> irregular;
  std::size_t valenceThree = 0U;
  std::size_t valenceFive = 0U;
  for (std::size_t vertex = 0U; vertex < vertexCount; ++vertex) {
    const std::size_t valence = neighbours[vertex].size();
    if (corners.count(vertex) != 0U) {
      if (valence != 2U) return "corner valence";
    } else if (onBoundary.count(vertex) != 0U) {
      if (valence != 3U) return "boundary valence";
    } else if (valence != 4U) {
      if (valence != 3U && valence != 5U) return "interior valence";
      (valence == 3U ? valenceThree : valenceFive) += 1U;
      irregular.push_back({vertex, static_cast<int>(valence)});
    }
  }
  if (irregular != disc.irregularVertices) return "reported irregular vertices";
  if (valenceThree != valenceFive) return "valence-3 and valence-5 counts differ";
  const bool equalOpposite = sides[0] == sides[2] && sides[1] == sides[3];
  if (irregular.size() != (equalOpposite ? 0U : 2U)) return "irregular vertex count";
  return std::nullopt;
}

std::optional<FourSidedDiscQuadrangulationFailure> failure_of(
    const directional::geometry::FourSidedDiscQuadrangulationResult &result) {
  const auto *failure = std::get_if<FourSidedDiscQuadrangulationFailure>(&result);
  return failure != nullptr ? std::optional{*failure} : std::nullopt;
}

void expect_filled(const Sides &sides, const std::size_t irregularVertices) {
  SCOPED_TRACE(sides_text(sides));
  const auto result = quadrangulate_four_sided_disc(sides);
  const auto *disc = std::get_if<FourSidedDiscQuadrangulation>(&result);
  ASSERT_NE(nullptr, disc);
  const auto defect = structural_defect(*disc, sides);
  EXPECT_FALSE(defect.has_value()) << defect.value_or("");
  EXPECT_EQ(irregularVertices, disc->irregularVertices.size());
  EXPECT_TRUE(result == quadrangulate_four_sided_disc(sides));
}

} // namespace

// Every input with sides 1..10 is filled with a valid disc, reported outside
// the construction domain, or (odd total) reported odd, so the domain
// predicate is exercised both ways over the whole box. 2300 of the 5000
// even-total inputs are in the domain: 100 grids and 2200 pentagon-triangle
// discs.
TEST(FourSidedDiscQuadrangulation, ExhaustiveBoxFillsTheConstructionDomainAndRejectsTheRest) {
  constexpr std::size_t kMaxSide = 10U;
  std::size_t evenInputs = 0U;
  std::size_t grids = 0U;
  std::size_t filled = 0U;
  std::size_t defects = 0U;
  for (std::size_t a = 1U; a <= kMaxSide; ++a) {
    for (std::size_t b = 1U; b <= kMaxSide; ++b) {
      for (std::size_t c = 1U; c <= kMaxSide; ++c) {
        for (std::size_t d = 1U; d <= kMaxSide; ++d) {
          const Sides sides{a, b, c, d};
          const auto result = quadrangulate_four_sided_disc(sides);
          if ((a + b + c + d) % 2U != 0U) {
            EXPECT_EQ(std::optional{FourSidedDiscQuadrangulationFailure::OddBoundary},
                      failure_of(result))
                << sides_text(sides);
            continue;
          }
          ++evenInputs;
          const auto *disc = std::get_if<FourSidedDiscQuadrangulation>(&result);
          if (disc == nullptr) {
            EXPECT_EQ(std::optional{
                          FourSidedDiscQuadrangulationFailure::OutsideConstructionDomain},
                      failure_of(result))
                << sides_text(sides);
            continue;
          }
          ++filled;
          if (a == c && b == d) ++grids;
          const auto defect = structural_defect(*disc, sides);
          if (defect.has_value() && ++defects <= 10U) {
            ADD_FAILURE() << sides_text(sides) << ": " << *defect;
          }
        }
      }
    }
  }
  EXPECT_EQ(0U, defects);
  EXPECT_EQ(5000U, evenInputs);
  EXPECT_EQ(100U, grids);
  EXPECT_EQ(2300U, filled);
}

// The prescribed sphere's region schedules, in every rotation and reflection:
// odd/odd opposite differences (30, 35, 35, 32), even/even (31, 35, 35, 31) and
// the equal-sided strip (1, 32, 1, 32).
TEST(FourSidedDiscQuadrangulation, SphereRegionSchedulesAreFilledInEverySymmetry) {
  const std::array<std::pair<Sides, std::size_t>, 3> schedules{{
      {{30U, 35U, 35U, 32U}, 2U},
      {{31U, 35U, 35U, 31U}, 2U},
      {{1U, 32U, 1U, 32U}, 0U}}};
  for (const auto &[sides, irregularVertices] : schedules) {
    const Sides mirrored{sides[3], sides[2], sides[1], sides[0]};
    for (const Sides &base : {sides, mirrored}) {
      for (std::size_t rotation = 0U; rotation < 4U; ++rotation) {
        expect_filled({base[rotation], base[(rotation + 1U) % 4U],
                       base[(rotation + 2U) % 4U], base[(rotation + 3U) % 4U]},
                      irregularVertices);
      }
    }
  }
}

// (3, 1, 1, 1) and (2, 2, 1, 1) have two adjacent one-edge sides, which force
// all four sides to one edge; (4, 1, 2, 1) has b = d = 1, which forces a = c.
// Neither is fillable with corners of valence 2 and every other boundary
// vertex of valence 3, so the construction must reject them.
TEST(FourSidedDiscQuadrangulation, RejectsUnfillableAndInvalidBoundaries) {
  using Failure = FourSidedDiscQuadrangulationFailure;
  for (const Sides &sides : {Sides{3U, 1U, 1U, 1U}, Sides{2U, 2U, 1U, 1U},
                             Sides{4U, 1U, 2U, 1U}}) {
    EXPECT_EQ(std::optional{Failure::OutsideConstructionDomain},
              failure_of(quadrangulate_four_sided_disc(sides)))
        << sides_text(sides);
  }
  EXPECT_EQ(std::optional{Failure::OddBoundary},
            failure_of(quadrangulate_four_sided_disc({1U, 1U, 1U, 2U})));
  EXPECT_EQ(std::optional{Failure::NonPositiveSide},
            failure_of(quadrangulate_four_sided_disc({0U, 2U, 2U, 2U})));
  constexpr std::size_t tooLong =
      directional::geometry::kFourSidedDiscMaxSideCount + 1U;
  EXPECT_EQ(std::optional{Failure::SideBeyondSizeBound},
            failure_of(quadrangulate_four_sided_disc({tooLong, 1U, tooLong, 1U})));
  EXPECT_STREQ("outside-construction-domain",
               directional::geometry::four_sided_disc_quadrangulation_failure_name(
                   Failure::OutsideConstructionDomain));
}

TEST(FourSidedDiscQuadrangulation, RepeatedCallsGiveIdenticalDiscs) {
  for (const Sides &sides : {Sides{30U, 35U, 35U, 32U}, Sides{31U, 35U, 35U, 31U},
                             Sides{1U, 32U, 1U, 32U}, Sides{2U, 3U, 6U, 5U}}) {
    const auto first = quadrangulate_four_sided_disc(sides);
    ASSERT_TRUE(std::holds_alternative<FourSidedDiscQuadrangulation>(first))
        << sides_text(sides);
    EXPECT_TRUE(first == quadrangulate_four_sided_disc(sides)) << sides_text(sides);
  }
}
