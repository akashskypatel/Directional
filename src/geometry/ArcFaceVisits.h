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
    const embedded_graph_topology_detail::FaceChartPoint &barycentric) {
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

/** One visit of a trace arc to a source face, read from the arc's own exact
 * pieces: visit k owns the next `sourcePieceCounts[k]` pieces of
 * `sourcePath`. A visit that opens with a face piece cuts the face interior
 * along the arc's forward orientation, with the arc's two face-walk orbits as
 * sides; a trailing edge piece adds nothing. A visit made of one edge piece
 * runs along an edge of the face without entering it: it cuts nothing and
 * touches the face only with the dart on the face's side of that edge. */
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
  const auto on_closure = [](const std::optional<embedded::FaceChartPoint> &point) {
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
      row.cut = FaceCutPiece{face_boundary_position(*entry),
                             face_boundary_position(*exit), forwardOrbit,
                             reverseOrbit};
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
