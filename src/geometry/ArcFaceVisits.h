#pragma once

#include "EmbeddedGraphTopology.h"
#include "FaceCutCornerPartition.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <map>
#include <optional>
#include <utility>
#include <variant>
#include <vector>

namespace directional::geometry::detail {

/** Boundary position of a point given by exact barycentric coordinates in a
 * face's corner order: a corner, a point on an open edge, or empty for a
 * point strictly inside the face. The coordinates must be non-negative and
 * sum to one. */
[[nodiscard]] inline std::optional<FaceBoundaryPosition> face_boundary_position(
    const exact_trace_segment_detail::FaceChartPoint &barycentric) {
  std::array<bool, 3> weighted{};
  std::size_t weightedCount = 0U;
  for (std::size_t corner = 0U; corner < 3U; ++corner) {
    weighted[corner] = !barycentric[corner].is_zero();
    if (weighted[corner]) ++weightedCount;
  }
  for (std::size_t corner = 0U; corner < 3U; ++corner) {
    if (weightedCount == 1U && weighted[corner]) {
      return FaceBoundaryPosition{
          corner, authority::FieldExactRational::from_integer(0)};
    }
    const std::size_t next = (corner + 1U) % 3U;
    if (weightedCount == 2U && weighted[corner] && weighted[next]) {
      // On local edge `corner`, the weight of its far corner is the distance
      // from corner `corner`.
      return FaceBoundaryPosition{corner, barycentric[next]};
    }
  }
  return std::nullopt;
}

/** For a straight piece whose two ends lie on one closed edge of a face, the
 * side of that edge the face lies on: Forward when the piece runs in corner
 * order (from corner k toward corner k + 1 on local edge k), which is the
 * side `FaceCutPiece` gives the forward dart. Such a piece runs along the
 * edge and cuts no face interior. Empty when the ends share no closed edge.
 * The two positions must differ. */
[[nodiscard]] inline std::optional<authority::Orientation> along_edge_face_side(
    const FaceBoundaryPosition &first, const FaceBoundaryPosition &second) {
  if (!face_cut_partition_detail::on_one_closed_edge(first, second)) {
    return std::nullopt;
  }
  // Local edge k holds its own points and corner k + 1, which is encoded as
  // offset 0 on edge k + 1.
  std::size_t edge = first.edge;
  if (first.edge != second.edge && first.offset.is_zero() &&
      (first.edge + 2U) % 3U == second.edge) {
    edge = second.edge;
  }
  const auto along = [&](const FaceBoundaryPosition &position) {
    return position.edge == edge
               ? position.offset
               : authority::FieldExactRational::from_integer(1);
  };
  return along(first) < along(second) ? authority::Orientation::Forward
                                      : authority::Orientation::Reverse;
}

/** One visit of a trace arc to a source face, read from the arc's own exact
 * pieces: visit k owns the next `sourcePieceCounts[k]` pieces of
 * `sourcePath`. A visit that opens with a face piece cuts the face interior
 * along the arc's forward orientation, with the arc's two face-walk orbits as
 * sides; a trailing edge piece adds nothing. A visit that runs along an edge
 * of the face without entering it, as one edge piece or as a face piece whose
 * ends lie on one closed edge, cuts nothing and touches the face only with
 * the dart on the face's side of that edge. */
struct ArcFaceVisit {
  authority::SourceFaceTopologyKey face;
  /** Position in the arc's `sourceFaces`. */
  std::size_t visit = 0U;
  /** The face-interior cut; empty for an edge-only visit. */
  std::optional<FaceCutPiece> cut;
  /** For an edge-only visit, the orbit of the dart on the face's side. */
  std::optional<std::size_t> edgeSideOrbit;
};

enum class ArcFaceVisitFailure {
  /** `sourceFaces`, `sourcePieceCounts` and `sourcePath` do not bind as
   * `source_piece_binding_failure` requires. */
  PieceBinding,
  /** A visited face is not in the source topology. */
  UnknownFace,
  /** A face piece end is not on the closure of its face. */
  PointOffFace,
  /** An edge-only visit does not advance along an edge of its face. */
  EdgeSideUndetermined,
};

using ArcFaceVisitsResult =
    std::variant<std::vector<ArcFaceVisit>, ArcFaceVisitFailure>;

[[nodiscard]] inline ArcFaceVisitsResult arc_face_visits(
    const std::map<authority::SourceFaceTopologyKey,
                   embedded_graph_topology_detail::SourceFaceRecord> &faces,
    const std::vector<authority::SourceFaceTopologyKey> &sourceFaces,
    const std::vector<std::size_t> &sourcePieceCounts,
    const authority::ExactSourcePath &sourcePath,
    const std::size_t forwardOrbit, const std::size_t reverseOrbit) {
  namespace embedded = embedded_graph_topology_detail;
  if (embedded::source_piece_binding_failure(sourceFaces, sourcePieceCounts,
                                             sourcePath)) {
    return ArcFaceVisitFailure::PieceBinding;
  }
  const auto on_closure = [](const std::optional<exact_trace_segment_detail::FaceChartPoint> &point) {
    const auto zero = authority::FieldExactRational::from_integer(0);
    return point.has_value() &&
           std::none_of(point->begin(), point->end(),
                        [&](const auto &weight) { return weight < zero; });
  };
  std::vector<ArcFaceVisit> visits;
  visits.reserve(sourceFaces.size());
  std::size_t piece = 0U;
  for (std::size_t visit = 0U; visit < sourceFaces.size(); ++visit) {
    const auto faceIt = faces.find(sourceFaces[visit]);
    if (faceIt == faces.end()) return ArcFaceVisitFailure::UnknownFace;
    const embedded::SourceFaceRecord &face = faceIt->second;
    const authority::ExactSourceSupportPiece &opening = sourcePath[piece];
    ArcFaceVisit row{sourceFaces[visit], visit, std::nullopt, std::nullopt};
    if (std::holds_alternative<authority::SourceFaceInteriorSupport>(
            opening.carrier)) {
      const auto entry =
          embedded::exact_source_point_barycentric(face, opening.first);
      const auto exit =
          embedded::exact_source_point_barycentric(face, opening.second);
      if (!on_closure(entry) || !on_closure(exit)) {
        return ArcFaceVisitFailure::PointOffFace;
      }
      auto entryPosition = face_boundary_position(*entry);
      auto exitPosition = face_boundary_position(*exit);
      const auto alongEdge =
          entryPosition.has_value() && exitPosition.has_value()
              ? along_edge_face_side(*entryPosition, *exitPosition)
              : std::nullopt;
      if (alongEdge.has_value()) {
        row.edgeSideOrbit = *alongEdge == authority::Orientation::Forward
                                ? forwardOrbit
                                : reverseOrbit;
      } else {
        row.cut = FaceCutPiece{std::move(entryPosition),
                               std::move(exitPosition), forwardOrbit,
                               reverseOrbit};
      }
    } else {
      const auto side = embedded::edge_piece_face_side(face, opening);
      if (!side.has_value()) return ArcFaceVisitFailure::EdgeSideUndetermined;
      row.edgeSideOrbit = *side == authority::Orientation::Forward
                              ? forwardOrbit
                              : reverseOrbit;
    }
    visits.push_back(std::move(row));
    piece += sourcePieceCounts[visit];
  }
  return visits;
}

} // namespace directional::geometry::detail
