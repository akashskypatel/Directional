#pragma once

#include <directional/authority/FieldTransportAtlas.h>

#include <algorithm>
#include <array>
#include <cstddef>
#include <optional>
#include <set>
#include <variant>
#include <vector>

namespace directional::geometry::detail {

/** A point on the boundary of a source triangle. Corners 0, 1, 2 follow the
 * face's vertex order and local edge k runs from corner k to corner k + 1
 * (mod 3). `offset` is the exact distance from corner `edge` along that edge
 * in edge-parameter units: 0 is corner `edge` itself and values in (0, 1) lie
 * on the open edge. */
struct FaceBoundaryPosition {
  std::size_t edge = 0U;
  authority::FieldExactRational offset;
};

/** The face-interior part of one trace arc inside a source triangle: a
 * straight cut directed along the arc's forward orientation. An end inside
 * the triangle (a terminal slit, or a node on another cut) has no boundary
 * position. Pieces that run along an edge cut no face interior and are not
 * passed here. */
struct FaceCutPiece {
  std::optional<FaceBoundaryPosition> entry;
  std::optional<FaceBoundaryPosition> exit;
  /** Face-walk orbit on the side of the cut that the corner order 0, 1, 2
   * winds around, i.e. the left side when that order is counter-clockwise.
   * This is the side the plan's `turn` rule assigns to the forward dart. */
  std::size_t forwardOrbit = 0U;
  /** Face-walk orbit on the other side. */
  std::size_t reverseOrbit = 0U;
};

enum class FaceCutPartitionFailure {
  /** An edge index outside 0..2 or an offset outside [0, 1). */
  MalformedBoundaryPosition,
  /** Both ends lie on one closed edge, so the cut would run along it. */
  CutAlongOneEdge,
  /** No cut reaches the boundary, so no corner can be attributed. */
  NoBoundaryEndpoint,
  /** Two cut ends meet at one boundary point but cannot be ordered there:
   * one of them ends inside the triangle, or both share both ends. */
  UnorderedSharedEndpoint,
  /** Two boundary-to-boundary cuts interleave along the boundary, so they
   * cross inside the triangle without a node. */
  CrossingCuts,
  /** Neighbouring cut ends along the boundary disagree on the orbit of the
   * region between them. */
  InconsistentSideOrbits,
};

/** Orbits whose regions touch each corner of the triangle. */
using FaceCornerOrbits = std::array<std::set<std::size_t>, 3>;
using FaceCornerPartitionResult =
    std::variant<FaceCornerOrbits, FaceCutPartitionFailure>;

namespace face_cut_partition_detail {

struct BoundaryEnd {
  FaceBoundaryPosition position;
  /** The cut's other end, when it is on the boundary. */
  std::optional<FaceBoundaryPosition> otherEnd;
  /** Orbit of the region just before this end in corner order. */
  std::size_t before = 0U;
  /** Orbit of the region just after this end in corner order. */
  std::size_t after = 0U;
};

inline bool valid_position(const FaceBoundaryPosition &position) {
  return position.edge < 3U &&
         position.offset >= authority::FieldExactRational::from_integer(0) &&
         position.offset < authority::FieldExactRational::from_integer(1);
}

inline bool same_position(const FaceBoundaryPosition &first,
                          const FaceBoundaryPosition &second) {
  return first.edge == second.edge && first.offset == second.offset;
}

inline bool position_less(const FaceBoundaryPosition &first,
                          const FaceBoundaryPosition &second) {
  if (first.edge != second.edge) return first.edge < second.edge;
  return first.offset < second.offset;
}

/** True when both positions lie on one closed edge. A corner lies on the
 * edge it starts and on the edge that ends at it. */
inline bool on_one_closed_edge(const FaceBoundaryPosition &first,
                               const FaceBoundaryPosition &second) {
  if (first.edge == second.edge) return true;
  if (first.offset.is_zero() && (first.edge + 2U) % 3U == second.edge) {
    return true;
  }
  return second.offset.is_zero() && (second.edge + 2U) % 3U == first.edge;
}

/** Orders cut ends that share one boundary point, walking around that point
 * from the boundary before it to the boundary after it. A straight cut whose
 * other end lies farther along the boundary is met first. Callers reject
 * shared points where an end lacks a boundary `otherEnd` or where both cuts
 * share both ends; such ends compare equal here. */
inline bool met_first_at_shared_point(const BoundaryEnd &first,
                                      const BoundaryEnd &second) {
  if (!first.otherEnd.has_value() || !second.otherEnd.has_value()) {
    return false;
  }
  const auto turns = [](const BoundaryEnd &end) {
    return (end.otherEnd->edge + 3U - end.position.edge) % 3U;
  };
  if (turns(first) != turns(second)) return turns(first) > turns(second);
  return first.otherEnd->offset > second.otherEnd->offset;
}

} // namespace face_cut_partition_detail

/** Attributes each corner of a source triangle to the face-walk orbits of
 * the regions that touch it, from the straight face-interior cuts of the
 * trace arcs crossing the triangle.
 *
 * Walking the boundary in corner order, every cut end splits the boundary;
 * an end where the cut enters has its forward orbit before it and its
 * reverse orbit after it, and an end where the cut leaves has the opposite.
 * Each stretch of boundary between consecutive ends must receive one orbit
 * from both of its ends. A corner without a cut end takes the orbit of the
 * stretch containing it; a corner where cuts end touches every orbit on
 * either side of each of those cuts. Orbits of regions that touch no corner
 * (a strip between nested cuts, a region bounded only by interior ends)
 * appear in no corner set; callers own the full orbit list of the face.
 *
 * Exact and order-independent: the result depends only on the multiset of
 * pieces, never on their order, and nothing is guessed. */
inline FaceCornerPartitionResult
partition_face_corners(const std::vector<FaceCutPiece> &pieces) {
  using namespace face_cut_partition_detail;

  std::vector<BoundaryEnd> ends;
  for (const FaceCutPiece &piece : pieces) {
    if ((piece.entry.has_value() && !valid_position(*piece.entry)) ||
        (piece.exit.has_value() && !valid_position(*piece.exit))) {
      return FaceCutPartitionFailure::MalformedBoundaryPosition;
    }
    if (piece.entry.has_value() && piece.exit.has_value() &&
        on_one_closed_edge(*piece.entry, *piece.exit)) {
      return FaceCutPartitionFailure::CutAlongOneEdge;
    }
    if (piece.entry.has_value()) {
      ends.push_back(BoundaryEnd{*piece.entry, piece.exit, piece.forwardOrbit,
                                 piece.reverseOrbit});
    }
    if (piece.exit.has_value()) {
      ends.push_back(BoundaryEnd{*piece.exit, piece.entry, piece.reverseOrbit,
                                 piece.forwardOrbit});
    }
  }
  if (ends.empty()) return FaceCutPartitionFailure::NoBoundaryEndpoint;

  for (std::size_t first = 0U; first < pieces.size(); ++first) {
    const FaceCutPiece &chord = pieces[first];
    if (!chord.entry.has_value() || !chord.exit.has_value()) continue;
    const bool entryFirst = position_less(*chord.entry, *chord.exit);
    const FaceBoundaryPosition &low = entryFirst ? *chord.entry : *chord.exit;
    const FaceBoundaryPosition &high = entryFirst ? *chord.exit : *chord.entry;
    for (std::size_t second = first + 1U; second < pieces.size(); ++second) {
      const FaceCutPiece &other = pieces[second];
      if (!other.entry.has_value() || !other.exit.has_value()) continue;
      const FaceBoundaryPosition &a = *other.entry;
      const FaceBoundaryPosition &b = *other.exit;
      if (same_position(a, low) || same_position(a, high) ||
          same_position(b, low) || same_position(b, high)) {
        continue;
      }
      const bool aInside = position_less(low, a) && position_less(a, high);
      const bool bInside = position_less(low, b) && position_less(b, high);
      if (aInside != bInside) return FaceCutPartitionFailure::CrossingCuts;
    }
  }

  for (std::size_t first = 0U; first < ends.size(); ++first) {
    for (std::size_t second = first + 1U; second < ends.size(); ++second) {
      if (!same_position(ends[first].position, ends[second].position)) {
        continue;
      }
      if (!ends[first].otherEnd.has_value() ||
          !ends[second].otherEnd.has_value() ||
          same_position(*ends[first].otherEnd, *ends[second].otherEnd)) {
        return FaceCutPartitionFailure::UnorderedSharedEndpoint;
      }
    }
  }

  std::sort(ends.begin(), ends.end(),
            [](const BoundaryEnd &first, const BoundaryEnd &second) {
              if (!same_position(first.position, second.position)) {
                return position_less(first.position, second.position);
              }
              return met_first_at_shared_point(first, second);
            });

  for (std::size_t index = 0U; index < ends.size(); ++index) {
    if (ends[index].after != ends[(index + 1U) % ends.size()].before) {
      return FaceCutPartitionFailure::InconsistentSideOrbits;
    }
  }

  FaceCornerOrbits corners;
  for (std::size_t corner = 0U; corner < 3U; ++corner) {
    const FaceBoundaryPosition position{
        corner, authority::FieldExactRational::from_integer(0)};
    bool cutEndsHere = false;
    for (const BoundaryEnd &end : ends) {
      if (!same_position(end.position, position)) continue;
      cutEndsHere = true;
      corners[corner].insert(end.before);
      corners[corner].insert(end.after);
    }
    if (cutEndsHere) continue;
    const auto next = std::find_if(
        ends.begin(), ends.end(), [&](const BoundaryEnd &end) {
          return position_less(position, end.position);
        });
    corners[corner].insert(next == ends.end() ? ends.front().before
                                              : next->before);
  }
  return corners;
}

} // namespace directional::geometry::detail
