// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <array>
#include <cstddef>
#include <optional>
#include <utility>

#include <directional/authority/ExactSourcePath.h>
#include <directional/geometry/SurfaceCellTracing.h>

// The exact source pieces of a traced segment, read from the candidate trace
// record alone. Both the curve-network stage and the embedded-graph stage
// read traces this way, so it sits below both.
namespace directional::geometry::exact_trace_segment_detail {

/**
 * Exact barycentric coordinates of a point of one source face, listed in that
 * face's oriented corner order. Every predicate below is affine-invariant, so
 * no metric geometry is read.
 */
using FaceChartPoint = std::array<authority::FieldExactRational, 3>;

/**
 * The exact t with point = entry + t * (exit - entry), when the point lies
 * strictly inside the straight segment from `entry` to `exit`. Empty when the
 * segment is degenerate, the point is off its line, or t is not in (0, 1).
 */
[[nodiscard]] inline std::optional<authority::FieldExactRational> face_chart_segment_parameter(
    const FaceChartPoint &entry, const FaceChartPoint &exit,
    const FaceChartPoint &point) {
  std::optional<std::size_t> axis;
  for (std::size_t index = 0U; index < 3U; ++index) {
    if (exit[index] != entry[index]) {
      axis = index;
      break;
    }
  }
  if (!axis.has_value()) return std::nullopt;
  const authority::FieldExactRational parameter =
      (point[*axis] - entry[*axis]) / (exit[*axis] - entry[*axis]);
  for (std::size_t index = 0U; index < 3U; ++index) {
    if (entry[index] + parameter * (exit[index] - entry[index]) !=
        point[index]) {
      return std::nullopt;
    }
  }
  if (!(parameter > authority::FieldExactRational::from_integer(0)) ||
      !(parameter < authority::FieldExactRational::from_integer(1))) {
    return std::nullopt;
  }
  return parameter;
}

/** The exact end point of trace segment `segmentIndex`. The last segment ends
 * at the trace's terminal face contact or terminal point; any other segment,
 * or a last one with neither, ends at its slide exit when it slides, else at
 * the next segment's entry. Empty when the record holds none. */
[[nodiscard]] inline std::optional<authority::ExactSourcePoint> exact_trace_segment_end(
    const FieldAlignedCandidateTrace &trace, const std::size_t segmentIndex) {
  if (segmentIndex >= trace.segments.size()) return std::nullopt;
  const auto &segment = trace.segments[segmentIndex];
  if (segmentIndex + 1U == trace.segments.size()) {
    if (trace.terminalContact.has_value()) {
      if (trace.terminalContact->sourceFace != segment.sourceFace) {
        return std::nullopt;
      }
      return authority::canonical_exact_source_face_point(
          trace.terminalContact->sourceFace,
          trace.terminalContact->barycentric);
    }
    if (trace.terminalPoint.has_value()) {
      return authority::canonical_exact_source_boundary_point(
          *trace.terminalPoint);
    }
  }
  if (segment.edgeTransitExit.has_value()) {
    return authority::canonical_exact_source_boundary_point(
        *segment.edgeTransitExit);
  }
  if (segmentIndex + 1U < trace.segments.size()) {
    return authority::canonical_exact_source_boundary_point(
        trace.segments[segmentIndex + 1U].entryPoint);
  }
  return std::nullopt;
}

/** Exact barycentric coordinates, in `face`'s corner order, of a point on one
 * of its edges. Empty when the edge is not an edge of `face`. */
[[nodiscard]] inline std::optional<FaceChartPoint> canonical_boundary_barycentric(
    const authority::SourceFaceTopologyKey &face,
    const authority::FieldBoundaryPoint &point) {
  const auto &vertices = face.vertices();
  FaceChartPoint barycentric{authority::FieldExactRational::from_integer(0),
                             authority::FieldExactRational::from_integer(0),
                             authority::FieldExactRational::from_integer(0)};
  std::optional<std::size_t> firstIndex;
  std::optional<std::size_t> secondIndex;
  for (std::size_t index = 0U; index < vertices.size(); ++index) {
    if (vertices[index] == point.edge.first()) firstIndex = index;
    if (vertices[index] == point.edge.second()) secondIndex = index;
  }
  if (!firstIndex.has_value() || !secondIndex.has_value()) return std::nullopt;
  barycentric[*firstIndex] =
      authority::FieldExactRational::from_integer(1) - point.parameter.value;
  barycentric[*secondIndex] = point.parameter.value;
  return barycentric;
}

/**
 * The exact source path segment `segment` of `trace` traverses. A segment
 * without an edge transit is one face piece to its end. A segment with an edge
 * transit is a face piece from its entry to the slide start, omitted when the
 * two are the same point, then an edge piece along its outgoing carrier to the
 * slide end. A terminal face contact on the last segment ends it on its face
 * piece, so the slide is not traversed. Empty when the record is incomplete or
 * inconsistent.
 */
[[nodiscard]] inline std::optional<authority::ExactSourcePath> exact_trace_segment_pieces(
    const FieldAlignedCandidateTrace &trace, const std::size_t segmentIndex) {
  if (segmentIndex >= trace.segments.size()) return std::nullopt;
  const FieldAlignedCandidateTraceSegment &segment = trace.segments[segmentIndex];
  const auto face_piece_to_end = [&]() -> std::optional<authority::ExactSourcePath> {
    const auto first = authority::canonical_exact_source_boundary_point(
        segment.entryPoint);
    const auto second = exact_trace_segment_end(trace, segmentIndex);
    if (!first.has_value() || !second.has_value()) return std::nullopt;
    authority::ExactSourcePath path{authority::ExactSourceSupportPiece{
        authority::SourceFaceInteriorSupport{segment.sourceFace}, *first,
        *second}};
    return authority::exact_source_path_is_canonical(path)
               ? std::optional<authority::ExactSourcePath>{std::move(path)}
               : std::nullopt;
  };
  if (!segment.edgeTransitEntry.has_value() &&
      !segment.edgeTransitExit.has_value()) {
    return face_piece_to_end();
  }
  if (!segment.edgeTransitEntry.has_value() ||
      !segment.edgeTransitExit.has_value() ||
      segment.edgeTransitEntry->edge != segment.outgoingCarrier ||
      segment.edgeTransitExit->edge != segment.outgoingCarrier) {
    return std::nullopt;
  }
  const bool last = segmentIndex + 1U == trace.segments.size();
  if (last && trace.terminalContact.has_value()) {
    // A contact is published after its whole proposal is committed, so the
    // record keeps the slide although the trace stops on the face piece.
    const auto entry =
        canonical_boundary_barycentric(segment.sourceFace, segment.entryPoint);
    const auto slideStart = canonical_boundary_barycentric(
        segment.sourceFace, *segment.edgeTransitEntry);
    if (!entry.has_value() || !slideStart.has_value() ||
        trace.terminalContact->sourceFace != segment.sourceFace ||
        !face_chart_segment_parameter(*entry, *slideStart,
                                      trace.terminalContact->barycentric)
             .has_value()) {
      return std::nullopt;
    }
    return face_piece_to_end();
  }
  const auto entry =
      authority::canonical_exact_source_boundary_point(segment.entryPoint);
  const auto slideStart =
      authority::canonical_exact_source_boundary_point(*segment.edgeTransitEntry);
  const auto slideEnd =
      authority::canonical_exact_source_boundary_point(*segment.edgeTransitExit);
  if (!entry.has_value() || !slideStart.has_value() || !slideEnd.has_value()) {
    return std::nullopt;
  }
  if (last && trace.terminalPoint.has_value() &&
      authority::canonical_exact_source_boundary_point(*trace.terminalPoint) !=
          slideEnd) {
    return std::nullopt;
  }
  authority::ExactSourcePath path;
  if (*entry != *slideStart) {
    path.push_back(authority::ExactSourceSupportPiece{
        authority::SourceFaceInteriorSupport{segment.sourceFace}, *entry,
        *slideStart});
  }
  path.push_back(authority::ExactSourceSupportPiece{
      authority::SourceEdgeSupport{segment.outgoingCarrier}, *slideStart,
      *slideEnd});
  return authority::exact_source_path_is_canonical(path)
             ? std::optional<authority::ExactSourcePath>{std::move(path)}
             : std::nullopt;
}

} // namespace directional::geometry::exact_trace_segment_detail
