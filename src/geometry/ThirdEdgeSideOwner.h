#pragma once

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/FieldTransportAtlas.h>

#include <cstddef>
#include <optional>
#include <set>
#include <vector>

namespace directional::geometry::detail {

/** Exact distance of a carrier point from the triangle apex the carrier
 * shares with the other carrier, in edge-parameter units. Absent when the
 * apex is not an endpoint of the point's edge. */
inline std::optional<authority::FieldExactRational>
carrier_apex_distance(const authority::FieldBoundaryPoint &point,
                      const authority::SourceVertexId apex) {
  if (apex == point.edge.first()) return point.parameter.value;
  if (apex == point.edge.second()) {
    return authority::FieldExactRational::from_integer(1) -
           point.parameter.value;
  }
  return std::nullopt;
}

/** One trace segment that crosses a source triangle from one carrier edge to
 * the other, seen from the triangle's third (uncrossed) edge. */
struct ThirdEdgeChordCandidate {
  /** Orbit on the segment's side that faces the third edge. */
  std::size_t thirdEdgeOrbit = 0U;
  /** Crossing distance from the apex on the carrier after the third edge. */
  std::optional<authority::FieldExactRational> firstCarrierApexDistance;
  /** Crossing distance from the apex on the carrier before the third edge. */
  std::optional<authority::FieldExactRational> secondCarrierApexDistance;
};

/** Orbits that own the third edge's side of a triangle crossed by chords.
 *
 * Every chord that crosses both carriers separates the apex from the third
 * edge, so the chords are nested and only the one farthest from the apex
 * bounds the region touching the third edge. When both carriers order every
 * pair of chords strictly and identically, that chord's orbit is returned
 * alone. Otherwise (a missing crossing, a tie, or disagreeing orders, which
 * would mean the chords meet inside the triangle) every candidate orbit is
 * returned, so the ambiguity stays visible to the caller. */
inline std::set<std::size_t>
third_edge_side_owner(const std::vector<ThirdEdgeChordCandidate> &candidates) {
  std::set<std::size_t> orbits;
  for (const auto &candidate : candidates) orbits.insert(candidate.thirdEdgeOrbit);
  if (orbits.size() <= 1U) return orbits;

  for (const auto &candidate : candidates) {
    if (!candidate.firstCarrierApexDistance.has_value() ||
        !candidate.secondCarrierApexDistance.has_value()) {
      return orbits;
    }
  }
  for (std::size_t left = 0U; left < candidates.size(); ++left) {
    for (std::size_t right = left + 1U; right < candidates.size(); ++right) {
      const auto first = *candidates[left].firstCarrierApexDistance <=>
                         *candidates[right].firstCarrierApexDistance;
      const auto second = *candidates[left].secondCarrierApexDistance <=>
                          *candidates[right].secondCarrierApexDistance;
      if (first == 0 || first != second) return orbits;
    }
  }

  std::size_t outermost = 0U;
  for (std::size_t index = 1U; index < candidates.size(); ++index) {
    if (*candidates[index].firstCarrierApexDistance >
        *candidates[outermost].firstCarrierApexDistance) {
      outermost = index;
    }
  }
  return {candidates[outermost].thirdEdgeOrbit};
}

} // namespace directional::geometry::detail
