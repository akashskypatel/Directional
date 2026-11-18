// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include "EmbeddedGraphTopology.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <tuple>
#include <utility>
#include <variant>

namespace directional::geometry::embedded_graph_topology_detail {

namespace {
constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void hash_consume(std::uint64_t &hash, const std::uint64_t value) noexcept {
  hash ^= value;
  hash *= kFnvPrime;
}

template <typename Id>
Id make_id(const std::size_t index, const std::size_t extent) {
  return Id::from_index(static_cast<std::int64_t>(index), extent).value();
}

GlobalTopologyPlanError error(const GlobalTopologyPlanErrorCode code) {
  GlobalTopologyPlanError result;
  result.code = code;
  return result;
}

GlobalTopologyPlanError rotation_error(
    const RotationSystemInconsistencyReason reason) {
  GlobalTopologyPlanError result =
      error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
  result.rotationSystemInconsistencyReason = reason;
  return result;
}
} // namespace

std::optional<SourceTopologyIndex> build_source_index(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority) {
  if (!sourceAuthority.matches_source_faces(sourceFaces, sourceVertexCount)) {
    return std::nullopt;
  }

  SourceTopologyIndex result;
  for (int rowIndex = 0; rowIndex < sourceFaces.rows(); ++rowIndex) {
    const auto row = authority::SourceFaceId::from_index(
        rowIndex, static_cast<std::size_t>(sourceFaces.rows()));
    if (!row) return std::nullopt;
    std::vector<authority::SourceVertexId> vertexList;
    vertexList.reserve(3U);
    for (int corner = 0; corner < 3; ++corner) {
      const auto vertex = authority::SourceVertexId::from_index(
          sourceFaces(rowIndex, corner), sourceVertexCount);
      if (!vertex) return std::nullopt;
      vertexList.push_back(vertex.value());
    }
    const std::array<authority::SourceVertexId, 3> vertices{
        vertexList[0], vertexList[1], vertexList[2]};
    const auto topology = authority::SourceFaceTopologyKey::make(vertices);
    if (!topology || topology.value() != sourceAuthority.topology_for_row(row.value())) {
      return std::nullopt;
    }

    std::array<authority::SourceEdgeTopologyKey, 3> edges{
        authority::SourceEdgeTopologyKey::make(vertices[0], vertices[1]).value(),
        authority::SourceEdgeTopologyKey::make(vertices[1], vertices[2]).value(),
        authority::SourceEdgeTopologyKey::make(vertices[2], vertices[0]).value()};
    SourceFaceRecord record{topology.value(), row.value(), vertices, edges,
                            sourceAuthority.component_for_row(row.value()),
                            sourceAuthority.region_for_row(row.value())};
    if (!result.faces.emplace(record.topology, record).second) {
      return std::nullopt;
    }
    for (const auto &edge : edges) {
      result.incidentFaces[edge].push_back(record.topology);
    }
    for (const auto vertex : vertices) {
      result.incidentFacesByVertex[vertex].push_back(record.topology);
    }
  }
  for (auto &[edge, faces] : result.incidentFaces) {
    (void)edge;
    std::sort(faces.begin(), faces.end());
    faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
    if (faces.empty() || faces.size() > 2U) return std::nullopt;
  }
  for (auto &[vertex, faces] : result.incidentFacesByVertex) {
    (void)vertex;
    std::sort(faces.begin(), faces.end());
    faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  }
  return result;
}

bool face_orients_edge_forward(const SourceFaceRecord &face,
                               const authority::SourceEdgeTopologyKey &edge) {
  for (std::size_t corner = 0U; corner < 3U; ++corner) {
    const auto first = face.vertices[corner];
    const auto second = face.vertices[(corner + 1U) % 3U];
    if (first == edge.first() && second == edge.second()) return true;
    if (first == edge.second() && second == edge.first()) return false;
  }
  return false;
}

std::optional<std::size_t> local_edge_index(
    const SourceFaceRecord &face,
    const authority::SourceEdgeTopologyKey &edge) {
  for (std::size_t index = 0U; index < face.edges.size(); ++index) {
    if (face.edges[index] == edge) return index;
  }
  return std::nullopt;
}

std::uint64_t network_binding_digest(
    const FieldAlignedCurveNetwork &network) noexcept {
  std::uint64_t hash = kFnvOffset;
  hash_consume(hash, network.source_digest());
  hash_consume(hash, network.atlas_digest());
  hash_consume(hash, network.semantic_digest());
  return hash;
}

struct TraceEventPositionDiagnostics {
  std::optional<TraceEventPositionFailureReason> failureReason;
  std::optional<TraceEventPositionPass> pass;
  std::vector<TraceEventPositionCandidate> candidates;
};

std::optional<std::size_t> trace_event_position(
    const FieldAlignedCandidateTrace &trace,
    const FieldAlignedNetworkEvent &event,
    const FieldAlignedTraceEventRole role,
    const authority::NetworkNodeId originNode,
    TraceEventPositionDiagnostics *diagnostics = nullptr) {
  if (event.node == originNode && !event.sourceEdge.has_value()) return 0U;
  if (!event.sourceEdge.has_value()) {
    if (role != FieldAlignedTraceEventRole::Terminal &&
        diagnostics != nullptr) {
      diagnostics->failureReason =
          TraceEventPositionFailureReason::NoCarrierMatch;
      diagnostics->pass = TraceEventPositionPass::SourceEdgeUnavailable;
      diagnostics->candidates.clear();
    }
    return role == FieldAlignedTraceEventRole::Terminal
               ? std::optional<std::size_t>{trace.segments.size()}
               : std::nullopt;
  }

  std::set<std::size_t> positions;
  std::vector<TraceEventPositionCandidate> candidates;
  const auto consider = [&](const std::size_t index,
                            const bool requireFace) {
    const auto &segment = trace.segments[index];
    if (requireFace && segment.sourceFace != event.sourceFace) return;
    if (segment.incomingCarrier.has_value() &&
        *segment.incomingCarrier == *event.sourceEdge) {
      positions.insert(index);
      candidates.push_back(TraceEventPositionCandidate{
          index, index, *segment.incomingCarrier,
          TraceEventPositionCarrierRole::Incoming});
    }
    if (segment.outgoingCarrier == *event.sourceEdge) {
      positions.insert(index + 1U);
      candidates.push_back(TraceEventPositionCandidate{
          index + 1U, index, segment.outgoingCarrier,
          TraceEventPositionCarrierRole::Outgoing});
    }
  };
  for (std::size_t index = 0U; index < trace.segments.size(); ++index) {
    consider(index, true);
  }
  TraceEventPositionPass pass = TraceEventPositionPass::FaceRestricted;
  if (positions.empty()) {
    candidates.clear();
    pass = TraceEventPositionPass::WideningFallback;
    for (std::size_t index = 0U; index < trace.segments.size(); ++index) {
      consider(index, false);
    }
  }
  if (positions.size() != 1U) {
    if (diagnostics != nullptr) {
      diagnostics->failureReason =
          positions.empty()
              ? TraceEventPositionFailureReason::NoCarrierMatch
              : TraceEventPositionFailureReason::AmbiguousCarrierMatch;
      diagnostics->pass = pass;
      diagnostics->candidates = std::move(candidates);
    }
    return std::nullopt;
  }
  if (diagnostics != nullptr) {
    diagnostics->pass = pass;
    diagnostics->candidates = std::move(candidates);
  }
  return *positions.begin();
}

struct ArcDraft {
  ArcDraft(const authority::NetworkNodeId first,
           const authority::NetworkNodeId second)
      : firstNode(first), secondNode(second) {}

  GlobalTopologyArcKind kind = GlobalTopologyArcKind::Mandatory;
  authority::NetworkNodeId firstNode;
  authority::NetworkNodeId secondNode;
  std::optional<authority::NetworkEdgeId> mandatoryEdge;
  std::optional<authority::TraceId> trace;
  std::optional<authority::SourceEdgeTopologyKey> cutEdge;
  std::size_t firstSegment = 0U;
  std::size_t onePastLastSegment = 0U;
  std::vector<authority::SourceFaceTopologyKey> sourceFaces;
  authority::ExactSourcePath sourcePath;
};

bool exact_interior_parameter(const authority::ExactUnitParameter &parameter) {
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  return parameter.value > zero && parameter.value < one;
}

std::optional<authority::ExactSourcePath> exact_edge_interval_path(
    const authority::SourceEdgeTopologyKey &edge,
    const authority::FieldExactRational &firstParameter,
    const authority::FieldExactRational &secondParameter) {
  const auto first =
      authority::canonical_exact_source_edge_point(edge, firstParameter);
  const auto second =
      authority::canonical_exact_source_edge_point(edge, secondParameter);
  if (!first.has_value() || !second.has_value() || *first == *second) {
    return std::nullopt;
  }
  authority::ExactSourcePath path{
      authority::ExactSourceSupportPiece{
          authority::SourceEdgeSupport{edge}, *first, *second}};
  return authority::exact_source_path_is_canonical(path)
             ? std::optional<authority::ExactSourcePath>{std::move(path)}
             : std::nullopt;
}

std::optional<authority::ExactSourcePoint> exact_trace_segment_end(
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

std::optional<authority::ExactSourcePath> exact_trace_path(
    const FieldAlignedCandidateTrace &trace, const std::size_t firstSegment,
    const std::size_t onePastLastSegment) {
  if (firstSegment >= onePastLastSegment ||
      onePastLastSegment > trace.segments.size()) {
    return std::nullopt;
  }
  authority::ExactSourcePath path;
  path.reserve(onePastLastSegment - firstSegment);
  for (std::size_t segmentIndex = firstSegment;
       segmentIndex < onePastLastSegment; ++segmentIndex) {
    const auto &segment = trace.segments[segmentIndex];
    const auto first = authority::canonical_exact_source_boundary_point(
        segment.entryPoint);
    const auto second = exact_trace_segment_end(trace, segmentIndex);
    if (!first.has_value() || !second.has_value()) return std::nullopt;
    path.push_back(authority::ExactSourceSupportPiece{
        authority::SourceFaceInteriorSupport{segment.sourceFace}, *first,
        *second});
  }
  return authority::exact_source_path_is_canonical(path)
             ? std::optional<authority::ExactSourcePath>{std::move(path)}
             : std::nullopt;
}

namespace {
void report_duplicate_cut_crossing(
    const FieldAlignedCurveNetwork &network,
    const authority::SourceEdgeTopologyKey &edge,
    const authority::ExactUnitParameter &parameter, authority::TraceId first,
    authority::TraceId second, std::size_t cutEdgeCount);
} // namespace

CutNodeBindingResult build_cut_node_bindings(
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges) {
  std::map<authority::SourceVertexId, std::set<authority::NetworkNodeId>> candidates;
  for (const auto &mandatory : network.mandatory_edges()) {
    candidates[mandatory.sourceEdge.first()].insert(mandatory.firstNode);
    candidates[mandatory.sourceEdge.second()].insert(mandatory.secondNode);
  }
  for (const auto &port : network.singularity_ports()) {
    candidates[port.sourceVertex].insert(port.node);
  }

  CutNodeBindings result;
  for (const auto &[vertex, nodes] : candidates) {
    if (nodes.size() != 1U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceVertex = vertex;
      return failure;
    }
    result.nodeByVertex.emplace(vertex, *nodes.begin());
  }

  std::set<authority::SourceVertexId> cutVertices;
  const std::set<authority::SourceEdgeTopologyKey> selectedCuts(
      cutEdges.begin(), cutEdges.end());
  struct CrossingDraft {
    CutCrossingKey key;
    authority::ExactUnitParameter parameter;
  };
  std::vector<CrossingDraft> crossings;
  std::map<authority::SourceEdgeTopologyKey,
           std::map<authority::ExactUnitParameter, authority::TraceId>>
      traceByExactPoint;
  for (const auto &edge : cutEdges) {
    cutVertices.insert(edge.first());
    cutVertices.insert(edge.second());
  }

  // A trace crossing is published exactly at the next segment's entry point.
  // The segment index is therefore the exact trace-cut position used by
  // build_arcs; no geometric crossing inference or tolerance is needed.
  for (const auto &trace : network.candidate_traces()) {
    for (std::size_t segmentPosition = 0U;
         segmentPosition < trace.segments.size(); ++segmentPosition) {
      const auto &segment = trace.segments[segmentPosition];
      if (!segment.incomingCarrier.has_value() ||
          selectedCuts.count(*segment.incomingCarrier) == 0U) {
        continue;
      }
      if (segment.entryPoint.edge != *segment.incomingCarrier) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
        failure.trace = trace.id;
        failure.sourceEdge = segment.incomingCarrier;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      if (!exact_interior_parameter(segment.entryPoint.parameter)) continue;

      auto &byPoint = traceByExactPoint[*segment.incomingCarrier];
      const auto duplicate = byPoint.find(segment.entryPoint.parameter);
      if (duplicate != byPoint.end() && duplicate->second != trace.id) {
        report_duplicate_cut_crossing(network, *segment.incomingCarrier,
                                      segment.entryPoint.parameter,
                                      duplicate->second, trace.id,
                                      cutEdges.size());
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
        failure.sourceEdge = *segment.incomingCarrier;
        failure.trace = duplicate->second;
        failure.secondTrace = trace.id;
        return failure;
      }
      byPoint.emplace(segment.entryPoint.parameter, trace.id);
      crossings.push_back(CrossingDraft{
          CutCrossingKey{*segment.incomingCarrier, trace.id, segmentPosition},
          segment.entryPoint.parameter});
    }
  }
  std::sort(crossings.begin(), crossings.end(), [](const auto &lhs,
                                                    const auto &rhs) {
    return lhs.key < rhs.key;
  });

  std::size_t nextIndex = network.nodes().size();
  const std::size_t extent = network.nodes().size() +
      static_cast<std::size_t>(std::count_if(
          cutVertices.begin(), cutVertices.end(), [&](const auto vertex) {
            return result.nodeByVertex.count(vertex) == 0U;
          })) +
      crossings.size();
  for (const auto vertex : cutVertices) {
    if (result.nodeByVertex.count(vertex) != 0U) continue;
    const auto id = authority::NetworkNodeId::from_index(
        static_cast<std::int64_t>(nextIndex++), extent);
    if (!id) return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
    result.nodeByVertex.emplace(vertex, id.value());
    result.syntheticVertices.emplace(id.value(), vertex);
  }
  for (const auto &crossing : crossings) {
    const auto id = authority::NetworkNodeId::from_index(
        static_cast<std::int64_t>(nextIndex++), extent);
    if (!id) return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
    CutCrossingBinding binding{crossing.key, crossing.parameter, id.value()};
    if (!result.crossingByKey.emplace(crossing.key, binding).second ||
        !result.syntheticCrossings.emplace(id.value(), binding).second) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceEdge = crossing.key.sourceEdge;
      failure.trace = crossing.key.trace;
      return failure;
    }
  }
  result.combinedNodeExtent = extent;
  return result;
}

std::vector<MandatoryEdgeTerminalInventory>
inventory_mandatory_edge_terminals(
    const std::map<authority::SourceEdgeTopologyKey,
                   std::vector<MandatoryEdgeTerminalCut>> &cutsByEdge) {
  std::vector<MandatoryEdgeTerminalInventory> result;
  for (const auto &[sourceEdge, cuts] : cutsByEdge) {
    if (cuts.size() < 2U) continue;
    MandatoryEdgeTerminalInventory inventory{sourceEdge, cuts, {}, 0U, true};
    std::sort(inventory.cuts.begin(), inventory.cuts.end(),
              [](const MandatoryEdgeTerminalCut &left,
                 const MandatoryEdgeTerminalCut &right) {
                if (left.parameter.value != right.parameter.value) {
                  return left.parameter.value < right.parameter.value;
                }
                return left.trace.index() < right.trace.index();
              });
    for (std::size_t index = 0U; index < inventory.cuts.size(); ++index) {
      const bool sameAsPrevious =
          index > 0U && inventory.cuts[index].parameter.value ==
                            inventory.cuts[index - 1U].parameter.value;
      if (!sameAsPrevious) ++inventory.distinctParameters;
      inventory.orderClass.push_back(inventory.distinctParameters - 1U);
      if (sameAsPrevious &&
          inventory.cuts[index].node != inventory.cuts[index - 1U].node) {
        inventory.equalParametersShareNode = false;
      }
    }
    result.push_back(std::move(inventory));
  }
  return result;
}

MandatoryEdgeSplit split_mandatory_edge_at_terminals(
    const authority::NetworkNodeId firstNode,
    const authority::NetworkNodeId secondNode,
    std::vector<MandatoryEdgeTerminalCut> cuts) {
  std::sort(cuts.begin(), cuts.end(),
            [](const MandatoryEdgeTerminalCut &left,
               const MandatoryEdgeTerminalCut &right) {
              if (left.parameter.value != right.parameter.value) {
                return left.parameter.value < right.parameter.value;
              }
              return left.trace.index() < right.trace.index();
            });
  for (const MandatoryEdgeTerminalCut &cut : cuts) {
    if (cut.node == firstNode || cut.node == secondNode) {
      return MandatoryEdgeSplitFailure{
          MandatoryEdgeSplitFailureKind::TerminalAtEndpoint, cut.trace,
          std::nullopt};
    }
  }
  std::set<authority::NetworkNodeId> nodes;
  for (std::size_t index = 0U; index < cuts.size(); ++index) {
    if (index > 0U &&
        cuts[index].parameter.value == cuts[index - 1U].parameter.value) {
      return MandatoryEdgeSplitFailure{
          MandatoryEdgeSplitFailureKind::EqualParameters,
          cuts[index - 1U].trace, cuts[index].trace};
    }
    if (!nodes.insert(cuts[index].node).second) {
      return MandatoryEdgeSplitFailure{
          MandatoryEdgeSplitFailureKind::SharedNode, cuts[index].trace,
          std::nullopt};
    }
  }
  std::vector<MandatoryEdgePiece> pieces;
  pieces.reserve(cuts.size() + 1U);
  authority::NetworkNodeId lowerNode = firstNode;
  authority::FieldExactRational lowerParameter =
      authority::FieldExactRational::from_integer(0);
  for (const MandatoryEdgeTerminalCut &cut : cuts) {
    pieces.push_back(MandatoryEdgePiece{lowerNode, cut.node, lowerParameter,
                                        cut.parameter.value, cut.trace});
    lowerNode = cut.node;
    lowerParameter = cut.parameter.value;
  }
  pieces.push_back(MandatoryEdgePiece{
      lowerNode, secondNode, lowerParameter,
      authority::FieldExactRational::from_integer(1),
      cuts.empty() ? std::nullopt
                   : std::optional<authority::TraceId>{cuts.back().trace}});
  return pieces;
}

int face_chart_orientation(const FaceChartPoint &a, const FaceChartPoint &b,
                           const FaceChartPoint &c) {
  const authority::FieldExactRational determinant =
      a[0] * (b[1] * c[2] - b[2] * c[1]) - a[1] * (b[0] * c[2] - b[2] * c[0]) +
      a[2] * (b[0] * c[1] - b[1] * c[0]);
  const auto zero = authority::FieldExactRational::from_integer(0);
  if (determinant > zero) return 1;
  if (determinant < zero) return -1;
  return 0;
}

std::optional<authority::FieldExactRational> face_chart_segment_parameter(
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

std::optional<std::vector<std::size_t>> face_chart_counter_clockwise_ray_order(
    const FaceChartPoint &origin, const std::vector<FaceChartPoint> &targets) {
  for (const FaceChartPoint &target : targets) {
    if (target == origin) return std::nullopt;
  }
  std::vector<std::size_t> order(targets.size());
  std::iota(order.begin(), order.end(), 0U);
  if (targets.empty()) return order;

  // Half-turn classes relative to the ray through targets[0]: 0 is that ray,
  // 1 the open counter-clockwise half, 2 the opposite ray, 3 the open
  // clockwise half. Two collinear rays leave in the same direction exactly
  // when the second displacement is a positive multiple of the first.
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto same_direction = [&](const FaceChartPoint &first,
                                  const FaceChartPoint &second) {
    for (std::size_t index = 0U; index < 3U; ++index) {
      const authority::FieldExactRational step = first[index] - origin[index];
      if (step.is_zero()) continue;
      return (second[index] - origin[index]) / step > zero;
    }
    return false;
  };
  std::vector<int> halfTurn(targets.size(), 0);
  for (std::size_t index = 1U; index < targets.size(); ++index) {
    const int side = face_chart_orientation(origin, targets[0], targets[index]);
    if (side > 0) {
      halfTurn[index] = 1;
    } else if (side < 0) {
      halfTurn[index] = 3;
    } else if (same_direction(targets[0], targets[index])) {
      return std::nullopt;
    } else {
      halfTurn[index] = 2;
    }
  }
  std::sort(order.begin(), order.end(),
            [&](const std::size_t lhs, const std::size_t rhs) {
              if (halfTurn[lhs] != halfTurn[rhs]) {
                return halfTurn[lhs] < halfTurn[rhs];
              }
              return face_chart_orientation(origin, targets[lhs],
                                            targets[rhs]) > 0;
            });
  // Within one class, collinear neighbours share a direction.
  for (std::size_t index = 1U; index < order.size(); ++index) {
    if (halfTurn[order[index - 1U]] == halfTurn[order[index]] &&
        face_chart_orientation(origin, targets[order[index - 1U]],
                               targets[order[index]]) == 0) {
      return std::nullopt;
    }
  }
  return order;
}

namespace {

std::optional<FaceChartPoint> canonical_boundary_barycentric(
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

std::set<authority::NetworkNodeId> port_nodes(
    const FieldAlignedCurveNetwork &network) {
  std::set<authority::NetworkNodeId> result;
  for (const auto &port : network.singularity_ports()) result.insert(port.node);
  return result;
}

// Non-port nodes where a trace ends on a trace strictly inside a face. A
// trace-trace contact (TraceIntersection or TraceSelfClosure) is one even when
// its events carry the two segments' common carrier: that edge is not where
// the contact lies, and the exact point is in the terminating trace's record.
// An edge-carrying FirstContact alone (a barrier termination) is not.
std::set<authority::NetworkNodeId>
face_contact_nodes(const FieldAlignedCurveNetwork &network) {
  const std::set<authority::NetworkNodeId> ports = port_nodes(network);
  std::set<authority::NetworkNodeId> result;
  for (const auto &event : network.events()) {
    if (ports.count(event.node) != 0U) continue;
    const bool traceContact =
        event.kind == FieldAlignedNetworkEventKind::TraceIntersection ||
        event.kind == FieldAlignedNetworkEventKind::TraceSelfClosure;
    if (traceContact ||
        (!event.sourceEdge.has_value() &&
         event.kind == FieldAlignedNetworkEventKind::FirstContact)) {
      result.insert(event.node);
    }
  }
  return result;
}

bool is_face_contact_event(const FieldAlignedNetworkEvent &event,
                           const std::set<authority::NetworkNodeId> &nodes) {
  return nodes.count(event.node) != 0U &&
         (event.kind == FieldAlignedNetworkEventKind::FirstContact ||
          event.kind == FieldAlignedNetworkEventKind::TraceIntersection ||
          event.kind == FieldAlignedNetworkEventKind::TraceSelfClosure);
}

GlobalTopologyPlanError face_contact_error(
    const RotationSystemInconsistencyReason reason,
    const authority::SourceFaceTopologyKey &face,
    const std::optional<authority::TraceId> trace) {
  GlobalTopologyPlanError result = rotation_error(reason);
  result.sourceFace = face;
  result.trace = trace;
  return result;
}

} // namespace

std::optional<FaceChartPoint> trace_segment_canonical_entry(
    const FieldAlignedCandidateTrace &trace, const std::size_t segment) {
  if (segment >= trace.segments.size()) return std::nullopt;
  return canonical_boundary_barycentric(trace.segments[segment].sourceFace,
                                        trace.segments[segment].entryPoint);
}

std::optional<FaceChartPoint> trace_segment_canonical_exit(
    const FieldAlignedCandidateTrace &trace, const std::size_t segment) {
  if (segment >= trace.segments.size()) return std::nullopt;
  const FieldAlignedCandidateTraceSegment &current = trace.segments[segment];
  if (current.edgeTransitExit.has_value()) return std::nullopt;
  if (segment + 1U < trace.segments.size()) {
    return canonical_boundary_barycentric(
        current.sourceFace, trace.segments[segment + 1U].entryPoint);
  }
  if (trace.terminalContact.has_value()) {
    if (trace.terminalContact->sourceFace != current.sourceFace) {
      return std::nullopt;
    }
    return trace.terminalContact->barycentric;
  }
  if (trace.terminalPoint.has_value()) {
    return canonical_boundary_barycentric(current.sourceFace,
                                          *trace.terminalPoint);
  }
  return std::nullopt;
}

std::optional<authority::FieldExactRational> trace_segment_contact_parameter(
    const FieldAlignedCandidateTrace &trace, const std::size_t segment,
    const FaceChartPoint &point) {
  const auto entry = trace_segment_canonical_entry(trace, segment);
  const auto exit = trace_segment_canonical_exit(trace, segment);
  if (!entry.has_value() || !exit.has_value()) return std::nullopt;
  return face_chart_segment_parameter(*entry, *exit, point);
}

std::optional<authority::ExactSourcePath> exact_trace_segment_pieces(
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

std::pair<std::size_t, std::size_t> trace_cut_segment_range(
    const TraceCutPosition &first, const TraceCutPosition &second) {
  return {first.segment, second.parameter.has_value() ? second.segment + 1U
                                                      : second.segment};
}

static std::optional<authority::ExactSourcePoint> exact_trace_interior_point(
    const FieldAlignedCandidateTrace &trace, const TraceCutPosition &position) {
  const auto entry = trace_segment_canonical_entry(trace, position.segment);
  const auto exit = trace_segment_canonical_exit(trace, position.segment);
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  const authority::FieldExactRational &t = *position.parameter;
  if (!entry.has_value() || !exit.has_value() || !(t > zero) ||
      !(t < one)) {
    return std::nullopt;
  }
  FaceChartPoint point = *entry;
  for (std::size_t index = 0U; index < 3U; ++index) {
    point[index] = (*entry)[index] + t * ((*exit)[index] - (*entry)[index]);
  }
  return authority::canonical_exact_source_face_point(
      trace.segments[position.segment].sourceFace, point);
}

std::optional<authority::ExactSourcePath> exact_trace_path_between(
    const FieldAlignedCandidateTrace &trace, const TraceCutPosition &first,
    const TraceCutPosition &second) {
  if (!(first < second)) return std::nullopt;
  if (!first.parameter.has_value() && !second.parameter.has_value()) {
    return exact_trace_path(trace, first.segment, second.segment);
  }
  const auto [begin, end] = trace_cut_segment_range(first, second);
  if (begin >= end || end > trace.segments.size()) return std::nullopt;
  authority::ExactSourcePath path;
  path.reserve(end - begin);
  for (std::size_t segmentIndex = begin; segmentIndex < end; ++segmentIndex) {
    const auto &segment = trace.segments[segmentIndex];
    const auto start =
        segmentIndex == begin && first.parameter.has_value()
            ? exact_trace_interior_point(trace, first)
            : authority::canonical_exact_source_boundary_point(
                  segment.entryPoint);
    const auto finish = segmentIndex + 1U == end && second.parameter.has_value()
                            ? exact_trace_interior_point(trace, second)
                            : exact_trace_segment_end(trace, segmentIndex);
    if (!start.has_value() || !finish.has_value()) return std::nullopt;
    path.push_back(authority::ExactSourceSupportPiece{
        authority::SourceFaceInteriorSupport{segment.sourceFace}, *start,
        *finish});
  }
  return authority::exact_source_path_is_canonical(path)
             ? std::optional<authority::ExactSourcePath>{std::move(path)}
             : std::nullopt;
}

std::optional<authority::ExactSourcePath> exact_trace_piece_path_between(
    const FieldAlignedCandidateTrace &trace, const TraceCutPosition &first,
    const TraceCutPosition &second) {
  if (!(first < second)) return std::nullopt;
  const auto [begin, end] = trace_cut_segment_range(first, second);
  if (begin >= end || end > trace.segments.size()) return std::nullopt;
  authority::ExactSourcePath path;
  for (std::size_t segmentIndex = begin; segmentIndex < end; ++segmentIndex) {
    auto pieces = exact_trace_segment_pieces(trace, segmentIndex);
    if (!pieces.has_value()) return std::nullopt;
    const bool clipFirst = segmentIndex == begin && first.parameter.has_value();
    const bool clipLast = segmentIndex + 1U == end && second.parameter.has_value();
    if (clipFirst || clipLast) {
      const auto &segment = trace.segments[segmentIndex];
      if (segment.edgeTransitEntry.has_value() || segment.edgeTransitExit.has_value() ||
          pieces->size() != 1U) return std::nullopt;
      if (clipFirst) {
        const auto point = exact_trace_interior_point(trace, first);
        if (!point.has_value()) return std::nullopt;
        pieces->front().first = *point;
      }
      if (clipLast) {
        const auto point = exact_trace_interior_point(trace, second);
        if (!point.has_value()) return std::nullopt;
        pieces->back().second = *point;
      }
    }
    path.insert(path.end(), pieces->begin(), pieces->end());
  }
  return authority::exact_source_path_is_canonical(path)
             ? std::optional<authority::ExactSourcePath>{std::move(path)}
             : std::nullopt;
}

FaceContactNodeResult collect_face_contact_nodes(
    const FieldAlignedCurveNetwork &network) {
  constexpr RotationSystemInconsistencyReason kInvalid =
      RotationSystemInconsistencyReason::FaceContactBindingInvalid;
  const std::set<authority::NetworkNodeId> contactNodes =
      face_contact_nodes(network);
  std::map<authority::NetworkNodeId, authority::SourceFaceTopologyKey> faces;
  std::map<authority::NetworkNodeId, std::set<authority::TraceId>> incident;
  std::map<authority::NetworkNodeId, std::set<authority::TraceId>> ending;
  for (const auto &event : network.events()) {
    if (!is_face_contact_event(event, contactNodes)) continue;
    const auto [face, inserted] = faces.emplace(event.node, event.sourceFace);
    if (!inserted && face->second != event.sourceFace) {
      return face_contact_error(kInvalid, event.sourceFace, std::nullopt);
    }
    for (const auto &incidence : event.incidences) {
      incident[event.node].insert(incidence.trace);
      if (incidence.role == FieldAlignedTraceEventRole::Terminal) {
        ending[event.node].insert(incidence.trace);
      }
    }
  }

  std::map<authority::NetworkNodeId, FaceContactNode> result;
  for (const auto &[node, face] : faces) {
    const std::set<authority::TraceId> &ends = ending[node];
    if (ends.empty()) return face_contact_error(kInvalid, face, std::nullopt);
    std::optional<FaceChartPoint> point;
    for (const authority::TraceId id : ends) {
      const FieldAlignedCandidateTrace *trace = find_trace(network, id);
      if (trace == nullptr || !trace->terminalContact.has_value() ||
          trace->terminalContact->sourceFace != face ||
          (point.has_value() && *point != trace->terminalContact->barycentric)) {
        return face_contact_error(kInvalid, face, id);
      }
      point = trace->terminalContact->barycentric;
    }
    FaceContactNode contact{face, *point, ends, {}};
    for (const authority::TraceId id : ends) {
      const FieldAlignedTerminalContact &record =
          *find_trace(network, id)->terminalContact;
      const FieldAlignedCandidateTrace *struck =
          find_trace(network, record.struckTrace);
      if (struck == nullptr) return face_contact_error(kInvalid, face, id);
      // Two traces that both end here strike each other's last segment.
      if (ends.count(record.struckTrace) != 0U &&
          record.struckSegmentIndex + 1U == struck->segments.size()) {
        continue;
      }
      if (record.struckSegmentIndex >= struck->segments.size() ||
          struck->segments[record.struckSegmentIndex].sourceFace != face) {
        return face_contact_error(kInvalid, face, record.struckTrace);
      }
      const auto parameter = trace_segment_contact_parameter(
          *struck, record.struckSegmentIndex, contact.point);
      if (!parameter.has_value()) {
        return face_contact_error(kInvalid, face, record.struckTrace);
      }
      const TraceCutPosition position{record.struckSegmentIndex, *parameter};
      const auto [stored, inserted] =
          contact.interior.emplace(record.struckTrace, position);
      if (!inserted && stored->second != position) {
        return face_contact_error(kInvalid, face, record.struckTrace);
      }
    }
    for (const authority::TraceId id : incident[node]) {
      if (ends.count(id) == 0U && contact.interior.count(id) == 0U) {
        return face_contact_error(kInvalid, face, id);
      }
    }
    result.emplace(node, std::move(contact));
  }
  return result;
}

namespace {

// P13-e (RA-243): print each mandatory source edge carrying two or more
// terminal cuts in exact order, so one census shows every such edge.
void report_mandatory_edge_terminal_inventory(
    const FieldAlignedCurveNetwork &network,
    const MandatoryEdgeTerminalInventory &inventory) {
  std::clog << "SurfaceCutGraph.mandatoryEdgeTerminalInventory edge=("
            << inventory.sourceEdge.first().index() << ','
            << inventory.sourceEdge.second().index()
            << ") cuts=" << inventory.cuts.size()
            << " distinctParameters=" << inventory.distinctParameters
            << " equalParametersShareNode="
            << (inventory.equalParametersShareNode ? 1 : 0);
  for (std::size_t index = 0U; index < inventory.cuts.size(); ++index) {
    const MandatoryEdgeTerminalCut &cut = inventory.cuts[index];
    const FieldAlignedCandidateTrace *trace = find_trace(network, cut.trace);
    std::clog << " cut" << index << "=[trace=" << cut.trace.index()
              << " singularity=";
    if (trace != nullptr) {
      std::clog << trace->singularity.index();
    } else {
      std::clog << '-';
    }
    std::clog << " node=" << cut.node.index()
              << " class=" << inventory.orderClass[index] << " t="
              << std::setprecision(17)
              << static_cast<double>(cut.parameter.value.to_double()) << ']';
  }
  std::clog << '\n';
}

// The first Terminal incidence of a trace whose resolved position lies
// before the trace's end; it decides ArcTraceTerminalCutPositionMismatch.
struct TerminalBeforeEnd {
  std::size_t eventIndex = 0U;
  std::size_t position = 0U;
  TraceEventPositionDiagnostics diagnostics;
};

const char *network_event_kind_label(const FieldAlignedNetworkEventKind kind) {
  switch (kind) {
  case FieldAlignedNetworkEventKind::SingularityPortOrigin:
    return "SingularityPortOrigin";
  case FieldAlignedNetworkEventKind::FirstContact:
    return "FirstContact";
  case FieldAlignedNetworkEventKind::TraceIntersection:
    return "TraceIntersection";
  case FieldAlignedNetworkEventKind::MandatoryBarrierTermination:
    return "MandatoryBarrierTermination";
  case FieldAlignedNetworkEventKind::SingularityTermination:
    return "SingularityTermination";
  case FieldAlignedNetworkEventKind::SingularityPortJunction:
    return "SingularityPortJunction";
  case FieldAlignedNetworkEventKind::TraceSelfClosure:
    return "TraceSelfClosure";
  case FieldAlignedNetworkEventKind::LimitCycleTermination:
    return "LimitCycleTermination";
  }
  return "Unknown";
}

void print_face(const authority::SourceFaceTopologyKey &face) {
  const auto &vertices = face.vertices();
  std::clog << '(' << vertices[0].index() << ',' << vertices[1].index() << ','
            << vertices[2].index() << ')';
}

void print_edge(const std::optional<authority::SourceEdgeTopologyKey> &edge) {
  if (!edge.has_value()) {
    std::clog << "none";
    return;
  }
  std::clog << '(' << edge->first().index() << ',' << edge->second().index()
            << ')';
}

// P13 (RA-250): one line naming the event, its resolved position and the
// trace's terminal record, so a census separates a common-carrier contact
// proxy from a limit-cycle entry or another terminal kind.
void report_terminal_cut_before_end(const FieldAlignedCandidateTrace &trace,
                                    const FieldAlignedNetworkEvent &event,
                                    const TerminalBeforeEnd &terminal) {
  const FieldAlignedCandidateTraceSegment &last = trace.segments.back();
  std::clog << "EmbeddedGraphTopology.terminalCutBeforeEnd trace="
            << trace.id.index() << " sourceVertex=" << trace.sourceVertex.index()
            << " segments=" << trace.segments.size()
            << " event=" << terminal.eventIndex
            << " kind=" << network_event_kind_label(event.kind)
            << " node=" << event.node.index() << " face=";
  print_face(event.sourceFace);
  std::clog << " edge=";
  print_edge(event.sourceEdge);
  std::clog << " position=" << terminal.position << " pass=";
  if (terminal.diagnostics.pass.has_value()) {
    std::clog << trace_event_position_pass_name(*terminal.diagnostics.pass);
  } else {
    std::clog << "none";
  }
  for (const TraceEventPositionCandidate &candidate :
       terminal.diagnostics.candidates) {
    std::clog << " candidate=[position=" << candidate.position
              << " segment=" << candidate.segmentIndex << ' '
              << trace_event_position_carrier_role_name(candidate.carrierRole)
              << ']';
  }
  std::clog << " lastFace=";
  print_face(last.sourceFace);
  std::clog << " lastIncoming=";
  print_edge(last.incomingCarrier);
  std::clog << " lastOutgoing=";
  print_edge(last.outgoingCarrier);
  std::clog << " terminal=";
  if (trace.terminalContact.has_value()) {
    std::clog << "contact face=";
    print_face(trace.terminalContact->sourceFace);
    std::clog << " struckTrace=" << trace.terminalContact->struckTrace.index()
              << " struckSegment=" << trace.terminalContact->struckSegmentIndex;
  } else if (trace.terminalLimitCycle.has_value()) {
    std::clog << "limitCycle face=";
    print_face(trace.terminalLimitCycle->sourceFace);
    std::clog << " entryEdge=";
    print_edge(trace.terminalLimitCycle->entryPoint.edge);
  } else if (trace.terminalSingularity.has_value()) {
    std::clog << "singularity=" << trace.terminalSingularity->index();
  } else if (trace.terminalBarrier.has_value()) {
    std::clog << "barrier edge=";
    print_edge(trace.terminalBarrier);
  } else if (trace.terminalPoint.has_value()) {
    std::clog << "point edge=";
    print_edge(trace.terminalPoint->edge);
  } else {
    std::clog << "none";
  }
  std::clog << '\n';
}

void print_node_events(const FieldAlignedCurveNetwork &network,
                       const authority::NetworkNodeId node) {
  std::clog << " events=";
  bool any = false;
  for (const auto &event : network.events()) {
    if (event.node != node) continue;
    std::clog << (any ? "," : "") << network_event_kind_label(event.kind)
              << '@';
    print_edge(event.sourceEdge);
    any = true;
  }
  if (!any) std::clog << "none";
}

void print_trace_terminal_contact(const FieldAlignedCandidateTrace *trace) {
  if (trace == nullptr || !trace->terminalContact.has_value()) {
    std::clog << " struckTrace=none";
    return;
  }
  std::clog << " struckTrace=" << trace->terminalContact->struckTrace.index()
            << " struckSegment=" << trace->terminalContact->struckSegmentIndex
            << " contactFace=";
  print_face(trace->terminalContact->sourceFace);
  std::clog << " at=";
  for (const auto &coordinate : trace->terminalContact->barycentric) {
    std::clog << static_cast<double>(coordinate.to_double()) << ' ';
  }
}

// P13 (RA-255): one exact boundary point as edge:parameter, with the source
// vertex named when the parameter is exactly 0 or 1.
void print_boundary_point(const authority::FieldBoundaryPoint &point) {
  print_edge(point.edge);
  std::clog << ':' << static_cast<double>(point.parameter.value.to_double());
  if (point.parameter.value == authority::FieldExactRational::from_integer(0)) {
    std::clog << "=v" << point.edge.first().index();
  } else if (point.parameter.value ==
             authority::FieldExactRational::from_integer(1)) {
    std::clog << "=v" << point.edge.second().index();
  }
}

// P13 (RA-255): the stored path of one trace, segment by segment (face,
// branch, entry point, incoming/outgoing carrier, edge-transit exit) and its
// end, so the onset of a shared locus or overlap can be located exactly.
void print_trace_path(const FieldAlignedCandidateTrace *trace,
                      const authority::TraceId id) {
  std::clog << " path=" << id.index() << ':';
  if (trace == nullptr) {
    std::clog << "missing";
    return;
  }
  for (std::size_t index = 0U; index < trace->segments.size(); ++index) {
    const auto &segment = trace->segments[index];
    std::clog << (index == 0U ? "" : ",") << index << '@';
    print_face(segment.sourceFace);
    std::clog << "b=" << static_cast<int>(segment.branch.value()) << " in=";
    print_boundary_point(segment.entryPoint);
    std::clog << " from=";
    print_edge(segment.incomingCarrier);
    std::clog << " to=";
    print_edge(segment.outgoingCarrier);
    if (segment.edgeTransitEntry.has_value()) {
      std::clog << " slide=";
      print_boundary_point(*segment.edgeTransitEntry);
    }
    if (segment.edgeTransitExit.has_value()) {
      std::clog << " transit=";
      print_boundary_point(*segment.edgeTransitExit);
    }
  }
  std::clog << " end=";
  if (trace->terminalContact.has_value()) {
    std::clog << "contact";
  } else if (trace->terminalPoint.has_value()) {
    print_boundary_point(*trace->terminalPoint);
  } else {
    std::clog << "none";
  }
}

// P13 (RA-254): every pair of segments of two traces that lie in one source
// face, with their branches, the exact orientation signs of each segment's
// ends against the other segment's supporting line (first line, then second
// line; all four zero means one supporting line, i.e. a collinear overlap)
// and which canonical ends coincide (e = entry, x = exit; first trace first).
void print_same_face_segment_pairs(const FieldAlignedCurveNetwork &network,
                                   const authority::TraceId first,
                                   const authority::TraceId second) {
  std::clog << " sameFacePairs=" << first.index() << '/' << second.index()
            << ':';
  const FieldAlignedCandidateTrace *a = find_trace(network, first);
  const FieldAlignedCandidateTrace *b = find_trace(network, second);
  bool any = false;
  if (a != nullptr && b != nullptr) {
    for (std::size_t i = 0U; i < a->segments.size(); ++i) {
      for (std::size_t j = 0U; j < b->segments.size(); ++j) {
        if (a->segments[i].sourceFace != b->segments[j].sourceFace) continue;
        std::clog << (any ? "," : "") << i << '-' << j << '@';
        print_face(a->segments[i].sourceFace);
        std::clog << "b=" << static_cast<int>(a->segments[i].branch.value())
                  << '-' << static_cast<int>(b->segments[j].branch.value())
                  << " o=";
        const auto aEntry = trace_segment_canonical_entry(*a, i);
        const auto aExit = trace_segment_canonical_exit(*a, i);
        const auto bEntry = trace_segment_canonical_entry(*b, j);
        const auto bExit = trace_segment_canonical_exit(*b, j);
        if (aEntry.has_value() && aExit.has_value() && bEntry.has_value() &&
            bExit.has_value()) {
          std::clog << face_chart_orientation(*aEntry, *aExit, *bEntry) << ':'
                    << face_chart_orientation(*aEntry, *aExit, *bExit) << ':'
                    << face_chart_orientation(*bEntry, *bExit, *aEntry) << ':'
                    << face_chart_orientation(*bEntry, *bExit, *aExit)
                    << " eq=";
          bool equal = false;
          for (const auto &[label, left, right] :
               {std::tuple{"ee", &*aEntry, &*bEntry},
                std::tuple{"ex", &*aEntry, &*bExit},
                std::tuple{"xe", &*aExit, &*bEntry},
                std::tuple{"xx", &*aExit, &*bExit}}) {
            if (*left != *right) continue;
            std::clog << (equal ? "+" : "") << label;
            equal = true;
          }
          if (!equal) std::clog << '-';
        } else {
          std::clog << "unevaluated";
        }
        any = true;
      }
    }
  }
  if (!any) std::clog << "none";
  print_trace_path(a, first);
  print_trace_path(b, second);
}

// P13 (RA-253): both traces that cross one selected cut edge at the same
// exact point, and every event incident to both, so the duplicate crossing
// can be attributed to a shared network node or to two unrelated traces.
void report_duplicate_cut_crossing(
    const FieldAlignedCurveNetwork &network,
    const authority::SourceEdgeTopologyKey &edge,
    const authority::ExactUnitParameter &parameter,
    const authority::TraceId first, const authority::TraceId second,
    const std::size_t cutEdgeCount) {
  const std::streamsize precision = std::clog.precision(17);
  std::clog << "EmbeddedGraphTopology.duplicateCutCrossing edge=";
  print_edge(edge);
  std::clog << " t="
            << static_cast<double>(parameter.value.to_double())
            << " cutEdges=" << cutEdgeCount;
  for (const authority::TraceId id : {first, second}) {
    const FieldAlignedCandidateTrace *trace = find_trace(network, id);
    std::clog << " trace=[" << id.index();
    if (trace != nullptr) {
      std::clog << " segments=" << trace->segments.size() << " crossing=";
      for (std::size_t index = 0U; index < trace->segments.size(); ++index) {
        const auto &segment = trace->segments[index];
        if (segment.incomingCarrier == edge &&
            segment.entryPoint.parameter == parameter) {
          std::clog << index << ' ';
        }
      }
    }
    print_trace_terminal_contact(trace);
    std::clog << ']';
  }
  print_same_face_segment_pairs(network, first, second);
  std::clog << " sharedEvents=";
  bool any = false;
  for (const auto &event : network.events()) {
    const auto touches = [&](const authority::TraceId id) {
      return std::any_of(event.incidences.begin(), event.incidences.end(),
                         [&](const auto &incidence) {
                           return incidence.trace == id;
                         });
    };
    if (!touches(first) || !touches(second)) continue;
    std::clog << (any ? "," : "") << event.node.index() << ':'
              << network_event_kind_label(event.kind) << '@';
    print_edge(event.sourceEdge);
    any = true;
  }
  if (!any) std::clog << "none";
  std::clog << '\n';
  std::clog.precision(precision);
}

void print_cut_claimant(
    const FieldAlignedCurveNetwork &network,
    const std::map<authority::NetworkNodeId, FaceContactNode> &faceContacts,
    const CutNodeBindings &cutNodes, const authority::NetworkNodeId node) {
  std::clog << "[node=" << node.index();
  const auto contact = faceContacts.find(node);
  const auto crossing = cutNodes.syntheticCrossings.find(node);
  if (contact != faceContacts.end()) {
    std::clog << " contact face=";
    print_face(contact->second.face);
    std::clog << " point=";
    for (const auto &coordinate : contact->second.point) {
      std::clog << static_cast<double>(coordinate.to_double()) << ' ';
    }
    std::clog << "terminating=";
    for (const authority::TraceId id : contact->second.terminating) {
      std::clog << id.index();
      print_trace_terminal_contact(find_trace(network, id));
      std::clog << ' ';
    }
    std::clog << "interior=";
    for (const auto &[id, position] : contact->second.interior) {
      std::clog << id.index() << ':' << position.segment << ':'
                << static_cast<double>(position.parameter->to_double())
                << ' ';
    }
  } else if (crossing != cutNodes.syntheticCrossings.end()) {
    std::clog << " crossing edge=";
    print_edge(crossing->second.key.sourceEdge);
    std::clog << " trace=" << crossing->second.key.trace.index()
              << " segment=" << crossing->second.key.segmentPosition;
  } else {
    std::clog << " network";
  }
  print_node_events(network, node);
  std::clog << ']';
}

// P13 (RA-253): the two nodes that claim one cut position of a trace when a
// face-contact node is inserted, so the conflict can be attributed.
void report_contact_cut_conflict(
    const FieldAlignedCurveNetwork &network,
    const std::map<authority::NetworkNodeId, FaceContactNode> &faceContacts,
    const CutNodeBindings &cutNodes, const authority::TraceId trace,
    const TraceCutPosition &position, const authority::NetworkNodeId existing,
    const authority::NetworkNodeId claimant) {
  const std::streamsize precision = std::clog.precision(17);
  std::clog << "EmbeddedGraphTopology.contactCutConflict trace="
            << trace.index() << " position=" << position.segment << ':';
  if (position.parameter.has_value()) {
    std::clog << static_cast<double>(position.parameter->to_double());
  } else {
    std::clog << "boundary";
  }
  std::clog << " existing=";
  print_cut_claimant(network, faceContacts, cutNodes, existing);
  std::clog << " claimant=";
  print_cut_claimant(network, faceContacts, cutNodes, claimant);
  const auto existingContact = faceContacts.find(existing);
  const auto claimantContact = faceContacts.find(claimant);
  if (existingContact != faceContacts.end() &&
      claimantContact != faceContacts.end() &&
      !existingContact->second.terminating.empty() &&
      !claimantContact->second.terminating.empty()) {
    print_same_face_segment_pairs(
        network, *existingContact->second.terminating.begin(),
        *claimantContact->second.terminating.begin());
  }
  std::clog << '\n';
  std::clog.precision(precision);
}

} // namespace

ArcBuildResult build_arcs(const FieldAlignedCurveNetwork &network,
                          const std::vector<authority::SourceEdgeTopologyKey> &cutEdges,
                          const CutNodeBindings &cutNodes) {
  std::map<authority::SourceEdgeTopologyKey,
           std::vector<MandatoryEdgeTerminalCut>>
      terminalCutsByEdge;
  for (const auto &trace : network.candidate_traces()) {
    if (!trace.terminalBarrier.has_value()) continue;

    std::optional<authority::NetworkNodeId> terminalNode;
    for (const auto &event : network.events()) {
      if (event.kind != FieldAlignedNetworkEventKind::MandatoryBarrierTermination ||
          event.sourceEdge != trace.terminalBarrier) {
        continue;
      }
      for (const auto &incidence : event.incidences) {
        if (incidence.trace != trace.id ||
            incidence.role != FieldAlignedTraceEventRole::Terminal) {
          continue;
        }
        if (terminalNode.has_value() && *terminalNode != event.node) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
          result.trace = trace.id;
          result.sourceEdge = trace.terminalBarrier;
          return result;
        }
        terminalNode = event.node;
      }
    }
    if (!terminalNode.has_value()) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      result.trace = trace.id;
      result.sourceEdge = trace.terminalBarrier;
      return result;
    }
    if (!trace.terminalPoint.has_value() ||
        trace.terminalPoint->edge != *trace.terminalBarrier ||
        !exact_interior_parameter(trace.terminalPoint->parameter)) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      result.trace = trace.id;
      result.sourceEdge = trace.terminalBarrier;
      return result;
    }
    terminalCutsByEdge[*trace.terminalBarrier].push_back(
        MandatoryEdgeTerminalCut{trace.id, *terminalNode,
                           trace.terminalPoint->parameter});
  }

  for (const MandatoryEdgeTerminalInventory &inventory :
       inventory_mandatory_edge_terminals(terminalCutsByEdge)) {
    report_mandatory_edge_terminal_inventory(network, inventory);
  }
  std::vector<ArcDraft> drafts;
  drafts.reserve(network.mandatory_edges().size() + terminalCutsByEdge.size() +
                 network.candidate_traces().size() + cutEdges.size());
  std::set<authority::SourceEdgeTopologyKey> consumedTerminalEdges;
  for (const auto &edge : network.mandatory_edges()) {
    const auto cuts = terminalCutsByEdge.find(edge.sourceEdge);
    const MandatoryEdgeSplit split = split_mandatory_edge_at_terminals(
        edge.firstNode, edge.secondNode,
        cuts == terminalCutsByEdge.end()
            ? std::vector<MandatoryEdgeTerminalCut>{}
            : cuts->second);
    if (const auto *failure = std::get_if<MandatoryEdgeSplitFailure>(&split)) {
      if (failure->kind == MandatoryEdgeSplitFailureKind::EqualParameters) {
        GlobalTopologyPlanError result = error(
            GlobalTopologyPlanErrorCode::MandatoryEdgeTerminalOrderUnresolved);
        result.sourceEdge = edge.sourceEdge;
        result.trace = failure->trace;
        result.secondTrace = failure->secondTrace;
        return result;
      }
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      result.networkEdge = edge.id;
      result.trace = failure->trace;
      result.sourceEdge = edge.sourceEdge;
      return result;
    }
    if (cuts != terminalCutsByEdge.end()) {
      consumedTerminalEdges.insert(edge.sourceEdge);
    }
    for (const MandatoryEdgePiece &piece :
         std::get<std::vector<MandatoryEdgePiece>>(split)) {
      const auto path = exact_edge_interval_path(
          edge.sourceEdge, piece.firstParameter, piece.secondParameter);
      if (!path.has_value()) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
        result.networkEdge = edge.id;
        result.trace = piece.adjacentTrace;
        result.sourceEdge = edge.sourceEdge;
        return result;
      }
      ArcDraft draft(piece.firstNode, piece.secondNode);
      draft.kind = GlobalTopologyArcKind::Mandatory;
      draft.mandatoryEdge = edge.id;
      draft.sourcePath = *path;
      drafts.push_back(std::move(draft));
    }
  }
  for (const auto &[sourceEdge, cuts] : terminalCutsByEdge) {
    (void)cuts;
    if (consumedTerminalEdges.count(sourceEdge) != 0U) continue;
    GlobalTopologyPlanError result =
        error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
    result.sourceEdge = sourceEdge;
    return result;
  }

  std::map<authority::SingularityPortId, authority::NetworkNodeId> originByPort;
  for (const auto &port : network.singularity_ports()) {
    originByPort.emplace(port.id, port.node);
  }
  const FaceContactNodeResult faceContactBuild =
      collect_face_contact_nodes(network);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&faceContactBuild)) {
    return *failure;
  }
  const auto &faceContacts =
      std::get<std::map<authority::NetworkNodeId, FaceContactNode>>(
          faceContactBuild);

  for (const auto &trace : network.candidate_traces()) {
    const auto origin = originByPort.find(trace.port);
    if (origin == originByPort.end() || trace.segments.empty()) {
      GlobalTopologyPlanError result =
          rotation_error(origin == originByPort.end() ? RotationSystemInconsistencyReason::ArcTraceOriginPortMissing : RotationSystemInconsistencyReason::ArcTraceSegmentsEmpty);
      result.sourceVertex = trace.sourceVertex;
      return result;
    }

    std::map<TraceCutPosition, authority::NetworkNodeId> cuts;
    cuts.emplace(TraceCutPosition{0U, std::nullopt}, origin->second);
    for (const auto &[key, crossing] : cutNodes.crossingByKey) {
      if (key.trace != trace.id) continue;
      if (key.segmentPosition == 0U ||
          key.segmentPosition >= trace.segments.size()) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
        result.trace = trace.id;
        result.sourceEdge = key.sourceEdge;
        return result;
      }
      const auto inserted = cuts.emplace(
          TraceCutPosition{key.segmentPosition, std::nullopt}, crossing.node);
      if (!inserted.second && inserted.first->second != crossing.node) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
        result.trace = trace.id;
        result.sourceEdge = key.sourceEdge;
        return result;
      }
    }
    bool hasTerminal = false;
    std::optional<TerminalBeforeEnd> terminalBeforeEnd;
    // A face-contact node's positions come from its exact contact record:
    // the trace's end where it terminates, an interior cut where it is struck.
    for (const auto &[node, contact] : faceContacts) {
      std::vector<TraceCutPosition> positions;
      if (contact.terminating.count(trace.id) != 0U) {
        positions.push_back(
            TraceCutPosition{trace.segments.size(), std::nullopt});
        hasTerminal = true;
      }
      const auto interior = contact.interior.find(trace.id);
      if (interior != contact.interior.end()) {
        positions.push_back(interior->second);
      }
      for (const TraceCutPosition &position : positions) {
        const auto inserted = cuts.emplace(position, node);
        if (!inserted.second && inserted.first->second != node) {
          report_contact_cut_conflict(network, faceContacts, cutNodes,
                                      trace.id, position,
                                      inserted.first->second, node);
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.trace = trace.id;
          result.sourceFace = contact.face;
          result.rotationSystemInconsistencyReason =
              RotationSystemInconsistencyReason::TraceEventPositionNodeConflict;
          return result;
        }
      }
    }
    for (std::size_t eventIndex = 0U; eventIndex < network.events().size();
         ++eventIndex) {
      const auto &event = network.events()[eventIndex];
      if (faceContacts.count(event.node) != 0U) continue;
      for (const auto &incidence : event.incidences) {
        if (incidence.trace != trace.id) continue;
        TraceEventPositionDiagnostics positionDiagnostics;
        const auto position = trace_event_position(
            trace, event, incidence.role, origin->second, &positionDiagnostics);
        if (!position.has_value() || *position > trace.segments.size()) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.trace = trace.id;
          result.sourceFace = event.sourceFace;
          result.sourceEdge = event.sourceEdge;
          result.rotationSystemInconsistencyReason =
              RotationSystemInconsistencyReason::TraceEventPositionInvalid;
          result.traceEventIndex = eventIndex;
          result.traceEventPositionFailureReason =
              positionDiagnostics.failureReason;
          result.traceEventPositionPass = positionDiagnostics.pass;
          result.traceEventPositionCandidates =
              std::move(positionDiagnostics.candidates);
          return result;
        }
        const auto inserted =
            cuts.emplace(TraceCutPosition{*position, std::nullopt}, event.node);
        if (!inserted.second && inserted.first->second != event.node) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceFace = event.sourceFace;
          result.sourceEdge = event.sourceEdge;
          result.rotationSystemInconsistencyReason =
              RotationSystemInconsistencyReason::TraceEventPositionNodeConflict;
          return result;
        }
        hasTerminal = hasTerminal ||
                      incidence.role == FieldAlignedTraceEventRole::Terminal;
        if (incidence.role == FieldAlignedTraceEventRole::Terminal &&
            *position < trace.segments.size() &&
            !terminalBeforeEnd.has_value()) {
          terminalBeforeEnd =
              TerminalBeforeEnd{eventIndex, *position, positionDiagnostics};
        }
      }
    }
    if (!hasTerminal ||
        cuts.rbegin()->first !=
            TraceCutPosition{trace.segments.size(), std::nullopt}) {
      GlobalTopologyPlanError result =
          rotation_error(!hasTerminal ? RotationSystemInconsistencyReason::ArcTraceTerminalEventMissing : RotationSystemInconsistencyReason::ArcTraceTerminalCutPositionMismatch);
      result.sourceVertex = trace.sourceVertex;
      // The error's locus is the terminal event that resolved before the
      // trace's end; sourceVertex stays the trace's origin vertex.
      if (terminalBeforeEnd.has_value()) {
        const auto &event = network.events()[terminalBeforeEnd->eventIndex];
        report_terminal_cut_before_end(trace, event, *terminalBeforeEnd);
        result.trace = trace.id;
        result.sourceFace = event.sourceFace;
        result.sourceEdge = event.sourceEdge;
        result.traceEventIndex = terminalBeforeEnd->eventIndex;
        result.traceEventPositionPass = terminalBeforeEnd->diagnostics.pass;
        result.traceEventPositionCandidates =
            terminalBeforeEnd->diagnostics.candidates;
      }
      return result;
    }

    const std::vector<std::pair<TraceCutPosition, authority::NetworkNodeId>>
        ordered(cuts.begin(), cuts.end());
    for (std::size_t cutIndex = 0U; cutIndex + 1U < ordered.size(); ++cutIndex) {
      const auto &[firstPosition, firstNode] = ordered[cutIndex];
      const auto &[secondPosition, secondNode] = ordered[cutIndex + 1U];
      const auto [firstSegment, onePastLastSegment] =
          trace_cut_segment_range(firstPosition, secondPosition);
      if (firstSegment >= onePastLastSegment) continue;
      ArcDraft draft(firstNode, secondNode);
      draft.kind = GlobalTopologyArcKind::Trace;
      draft.trace = trace.id;
      draft.firstSegment = firstSegment;
      draft.onePastLastSegment = onePastLastSegment;
      draft.sourceFaces.reserve(onePastLastSegment - firstSegment);
      for (std::size_t segment = firstSegment; segment < onePastLastSegment;
           ++segment) {
        draft.sourceFaces.push_back(trace.segments[segment].sourceFace);
      }
      const auto path =
          exact_trace_path_between(trace, firstPosition, secondPosition);
      if (!path.has_value()) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
        result.trace = trace.id;
        result.sourceFace = trace.segments[firstSegment].sourceFace;
        return result;
      }
      draft.sourcePath = *path;
      drafts.push_back(std::move(draft));
    }
  }

  for (const auto &cutEdge : cutEdges) {
    const auto first = cutNodes.nodeByVertex.find(cutEdge.first());
    const auto second = cutNodes.nodeByVertex.find(cutEdge.second());
    if (first == cutNodes.nodeByVertex.end() ||
        second == cutNodes.nodeByVertex.end() || first->second == second->second) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceEdge = cutEdge;
      return failure;
    }
    std::vector<std::pair<authority::ExactUnitParameter,
                          authority::NetworkNodeId>> orderedPoints;
    orderedPoints.emplace_back(
        authority::ExactUnitParameter{
            authority::FieldExactRational::from_integer(0)},
        first->second);
    for (const auto &[key, crossing] : cutNodes.crossingByKey) {
      if (key.sourceEdge == cutEdge) {
        orderedPoints.emplace_back(crossing.parameter, crossing.node);
      }
    }
    orderedPoints.emplace_back(
        authority::ExactUnitParameter{
            authority::FieldExactRational::from_integer(1)},
        second->second);
    std::sort(orderedPoints.begin(), orderedPoints.end(), [](const auto &lhs,
                                                             const auto &rhs) {
      return lhs.first < rhs.first;
    });
    for (std::size_t index = 1U; index < orderedPoints.size(); ++index) {
      if (!(orderedPoints[index - 1U].first < orderedPoints[index].first) ||
          orderedPoints[index - 1U].second == orderedPoints[index].second) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
        failure.sourceEdge = cutEdge;
        return failure;
      }
      ArcDraft draft(orderedPoints[index - 1U].second,
                     orderedPoints[index].second);
      draft.kind = GlobalTopologyArcKind::Cut;
      draft.cutEdge = cutEdge;
      const auto path = exact_edge_interval_path(
          cutEdge, orderedPoints[index - 1U].first.value,
          orderedPoints[index].first.value);
      if (!path.has_value()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
        failure.sourceEdge = cutEdge;
        return failure;
      }
      draft.sourcePath = *path;
      drafts.push_back(std::move(draft));
    }
  }

  std::sort(drafts.begin(), drafts.end(), [](const ArcDraft &lhs,
                                             const ArcDraft &rhs) {
    return std::tie(lhs.kind, lhs.mandatoryEdge, lhs.trace, lhs.cutEdge,
                    lhs.firstSegment, lhs.onePastLastSegment, lhs.firstNode,
                    lhs.secondNode) <
           std::tie(rhs.kind, rhs.mandatoryEdge, rhs.trace, rhs.cutEdge,
                    rhs.firstSegment, rhs.onePastLastSegment, rhs.firstNode,
                    rhs.secondNode);
  });

  std::vector<GlobalTopologyArc> arcs;
  arcs.reserve(drafts.size());
  for (std::size_t index = 0U; index < drafts.size(); ++index) {
    ArcDraft &draft = drafts[index];
    arcs.push_back(GlobalTopologyArc{
        make_id<authority::NetworkArcId>(index, drafts.size()), draft.kind,
        draft.firstNode, draft.secondNode, draft.mandatoryEdge, draft.trace,
        draft.cutEdge, draft.firstSegment, draft.onePastLastSegment,
        std::move(draft.sourceFaces), std::move(draft.sourcePath)});
  }
  return arcs;
}

NodeLocusResult build_node_loci(const FieldAlignedCurveNetwork &network,
                                 const CutNodeBindings &cutNodes) {
  std::map<authority::NetworkNodeId, NodeLocus> loci;
  for (const auto &node : network.nodes()) loci.emplace(node.id, NodeLocus{});
  for (const auto &[node, vertex] : cutNodes.syntheticVertices) {
    loci.emplace(node, NodeLocus{vertex, std::nullopt});
  }
  for (const auto &[node, crossing] : cutNodes.syntheticCrossings) {
    loci.emplace(node, NodeLocus{std::nullopt, crossing.key.sourceEdge});
  }

  const auto set_vertex = [&](const authority::NetworkNodeId node,
                              const authority::SourceVertexId vertex)
      -> std::optional<GlobalTopologyPlanError> {
    auto found = loci.find(node);
    if (found == loci.end()) {
      GlobalTopologyPlanError result =
          rotation_error(RotationSystemInconsistencyReason::NodeLocusRegistrationMissing);
      result.sourceVertex = vertex;
      return result;
    }
    if (found->second.vertex.has_value() && *found->second.vertex != vertex) {
      GlobalTopologyPlanError result =
          rotation_error(RotationSystemInconsistencyReason::NodeLocusSourceVertexConflict);
      result.sourceVertex = vertex;
      return result;
    }
    found->second.vertex = vertex;
    return std::nullopt;
  };

  for (const auto &port : network.singularity_ports()) {
    if (const auto failure = set_vertex(port.node, port.sourceVertex);
        failure.has_value()) {
      return *failure;
    }
  }
  for (const auto &edge : network.mandatory_edges()) {
    if (const auto failure = set_vertex(edge.firstNode, edge.sourceEdge.first());
        failure.has_value()) {
      return *failure;
    }
    if (const auto failure = set_vertex(edge.secondNode, edge.sourceEdge.second());
        failure.has_value()) {
      return *failure;
    }
  }

  // A face-contact node has neither a vertex nor an edge locus; rotation
  // reads its face and exact point from collect_face_contact_nodes.
  const std::set<authority::NetworkNodeId> contactNodes =
      face_contact_nodes(network);
  for (const auto &event : network.events()) {
    if (is_face_contact_event(event, contactNodes)) continue;
    auto found = loci.find(event.node);
    if (found == loci.end()) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceFace = event.sourceFace;
      result.sourceEdge = event.sourceEdge;
      result.rotationSystemInconsistencyReason =
          RotationSystemInconsistencyReason::EventNodeLocusMissing;
      return result;
    }
    if (found->second.vertex.has_value()) continue;
    if (!event.sourceEdge.has_value()) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceFace = event.sourceFace;
      result.rotationSystemInconsistencyReason =
          RotationSystemInconsistencyReason::EventLocusMissingSourceEdge;
      return result;
    }
    if (found->second.edge.has_value() &&
        *found->second.edge != *event.sourceEdge) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceFace = event.sourceFace;
      result.sourceEdge = event.sourceEdge;
      result.rotationSystemInconsistencyReason =
          RotationSystemInconsistencyReason::EventLocusSourceEdgeConflict;
      return result;
    }
    found->second.edge = event.sourceEdge;
  }
  return loci;
}

struct VertexFanSlots {
  std::map<authority::SourceEdgeTopologyKey, std::size_t> edgeSlots;
  std::map<authority::SourceFaceTopologyKey, std::size_t> faceSlots;
};

std::optional<VertexFanSlots> build_vertex_fan_slots(
    const SourceTopologyIndex &topology,
    const authority::SourceVertexId vertex) {
  const auto incident = topology.incidentFacesByVertex.find(vertex);
  if (incident == topology.incidentFacesByVertex.end() ||
      incident->second.empty()) {
    return std::nullopt;
  }

  struct Wedge {
    authority::SourceFaceTopologyKey face;
    authority::SourceEdgeTopologyKey start;
    authority::SourceEdgeTopologyKey end;
  };
  std::map<authority::SourceEdgeTopologyKey, Wedge> byStart;
  std::map<authority::SourceEdgeTopologyKey, std::size_t> incomingCount;
  std::set<authority::SourceEdgeTopologyKey> allEdges;
  for (const auto &faceKey : incident->second) {
    const auto faceIt = topology.faces.find(faceKey);
    if (faceIt == topology.faces.end()) return std::nullopt;
    const SourceFaceRecord &face = faceIt->second;
    std::size_t corner = 3U;
    for (std::size_t index = 0U; index < 3U; ++index) {
      if (face.vertices[index] == vertex) {
        corner = index;
        break;
      }
    }
    if (corner >= 3U) return std::nullopt;
    const auto next = face.vertices[(corner + 1U) % 3U];
    const auto previous = face.vertices[(corner + 2U) % 3U];
    const auto start = authority::SourceEdgeTopologyKey::make(vertex, next);
    const auto end = authority::SourceEdgeTopologyKey::make(previous, vertex);
    if (!start || !end) return std::nullopt;
    Wedge wedge{faceKey, start.value(), end.value()};
    if (!byStart.emplace(wedge.start, wedge).second) return std::nullopt;
    ++incomingCount[wedge.end];
    allEdges.insert(wedge.start);
    allEdges.insert(wedge.end);
  }

  std::optional<authority::SourceEdgeTopologyKey> startEdge;
  for (const auto &edge : allEdges) {
    if (incomingCount[edge] == 0U) {
      if (startEdge.has_value()) return std::nullopt;
      startEdge = edge;
    }
  }
  const bool cycle = !startEdge.has_value();
  if (cycle) startEdge = *allEdges.begin();

  VertexFanSlots slots;
  auto current = *startEdge;
  std::set<authority::SourceEdgeTopologyKey> visitedEdges;
  std::set<authority::SourceFaceTopologyKey> visitedFaces;
  std::size_t slot = 0U;
  while (true) {
    if (!visitedEdges.insert(current).second) {
      if (cycle && current == *startEdge) break;
      return std::nullopt;
    }
    slots.edgeSlots.emplace(current, slot++);
    const auto wedge = byStart.find(current);
    if (wedge == byStart.end()) {
      if (cycle) return std::nullopt;
      break;
    }
    if (!visitedFaces.insert(wedge->second.face).second) return std::nullopt;
    slots.faceSlots.emplace(wedge->second.face, slot++);
    current = wedge->second.end;
    if (cycle && current == *startEdge) break;
  }
  if (visitedFaces.size() != incident->second.size()) return std::nullopt;
  if (!cycle && !visitedEdges.count(current)) {
    slots.edgeSlots.emplace(current, slot++);
  }
  return slots;
}

const FieldAlignedCandidateTrace *find_trace(
    const FieldAlignedCurveNetwork &network, const authority::TraceId trace) {
  const auto found = std::find_if(
      network.candidate_traces().begin(), network.candidate_traces().end(),
      [&](const auto &candidate) { return candidate.id == trace; });
  return found == network.candidate_traces().end() ? nullptr : &*found;
}

const FieldAlignedMandatoryEdge *find_mandatory(
    const FieldAlignedCurveNetwork &network,
    const authority::NetworkEdgeId edge) {
  const auto found = std::find_if(
      network.mandatory_edges().begin(), network.mandatory_edges().end(),
      [&](const auto &candidate) { return candidate.id == edge; });
  return found == network.mandatory_edges().end() ? nullptr : &*found;
}

struct RayOrderKey {
  explicit RayOrderKey(const authority::NetworkArcId arcId) : arc(arcId) {}

  std::size_t primary = 0U;
  std::size_t secondary = 0U;
  GlobalTopologyArcKind kind = GlobalTopologyArcKind::Mandatory;
  std::optional<authority::TraceId> trace;
  authority::NetworkArcId arc;
  authority::Orientation orientation = authority::Orientation::Forward;

  auto operator<=>(const RayOrderKey &) const = default;
};

std::optional<authority::SourceFaceTopologyKey> trace_ray_face(
    const GlobalTopologyArc &arc, const authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace) {
  if (arc.firstSegment >= arc.onePastLastSegment ||
      arc.onePastLastSegment > trace.segments.size()) {
    return std::nullopt;
  }
  return orientation == authority::Orientation::Forward
             ? std::optional<authority::SourceFaceTopologyKey>{
                   trace.segments[arc.firstSegment].sourceFace}
             : std::optional<authority::SourceFaceTopologyKey>{
                   trace.segments[arc.onePastLastSegment - 1U].sourceFace};
}

std::optional<authority::ExactUnitParameter> cut_node_parameter(
    const authority::NetworkNodeId node,
    const authority::SourceEdgeTopologyKey &sourceEdge,
    const CutNodeBindings &cutNodes) {
  const auto first = cutNodes.nodeByVertex.find(sourceEdge.first());
  const auto second = cutNodes.nodeByVertex.find(sourceEdge.second());
  if (first != cutNodes.nodeByVertex.end() && first->second == node) {
    return authority::ExactUnitParameter{
        authority::FieldExactRational::from_integer(0)};
  }
  if (second != cutNodes.nodeByVertex.end() && second->second == node) {
    return authority::ExactUnitParameter{
        authority::FieldExactRational::from_integer(1)};
  }
  const auto crossing = cutNodes.syntheticCrossings.find(node);
  if (crossing != cutNodes.syntheticCrossings.end() &&
      crossing->second.key.sourceEdge == sourceEdge) {
    return crossing->second.parameter;
  }
  return std::nullopt;
}

std::optional<bool> edge_ray_points_to_second_endpoint(
    const GlobalTopologyArc &arc, const authority::Orientation orientation,
    const authority::SourceEdgeTopologyKey &sourceEdge,
    const FieldAlignedCurveNetwork &network, const CutNodeBindings &cutNodes) {
  const authority::NetworkNodeId destination =
      orientation == authority::Orientation::Forward ? arc.secondNode
                                                     : arc.firstNode;
  if (arc.kind == GlobalTopologyArcKind::Mandatory) {
    if (!arc.mandatoryEdge.has_value()) return std::nullopt;
    const auto *mandatory = find_mandatory(network, *arc.mandatoryEdge);
    if (mandatory == nullptr || mandatory->sourceEdge != sourceEdge) {
      return std::nullopt;
    }
    // build_arcs orients every Mandatory piece from lower to higher edge
    // parameter, including pieces between two terminal cuts.
    return orientation == authority::Orientation::Forward;
  }
  if (arc.kind != GlobalTopologyArcKind::Cut || arc.cutEdge != sourceEdge) {
    return std::nullopt;
  }
  const authority::NetworkNodeId origin =
      orientation == authority::Orientation::Forward ? arc.firstNode
                                                     : arc.secondNode;
  const auto originParameter = cut_node_parameter(origin, sourceEdge, cutNodes);
  const auto destinationParameter =
      cut_node_parameter(destination, sourceEdge, cutNodes);
  if (!originParameter.has_value() || !destinationParameter.has_value() ||
      originParameter->value == destinationParameter->value) {
    return std::nullopt;
  }
  return originParameter->value < destinationParameter->value;
}

std::optional<std::array<authority::FieldExactRational, 3>>
field_boundary_point_barycentric(
    const SourceFaceRecord &face,
    const authority::FieldBoundaryPoint &point) {
  std::array<authority::FieldExactRational, 3> barycentric{
      authority::FieldExactRational::from_integer(0),
      authority::FieldExactRational::from_integer(0),
      authority::FieldExactRational::from_integer(0)};
  std::optional<std::size_t> firstIndex;
  std::optional<std::size_t> secondIndex;
  for (std::size_t index = 0U; index < face.vertices.size(); ++index) {
    if (face.vertices[index] == point.edge.first()) firstIndex = index;
    if (face.vertices[index] == point.edge.second()) secondIndex = index;
  }
  if (!firstIndex.has_value() || !secondIndex.has_value()) return std::nullopt;
  const auto one = authority::FieldExactRational::from_integer(1);
  barycentric[*firstIndex] = one - point.parameter.value;
  barycentric[*secondIndex] = point.parameter.value;
  return barycentric;
}

std::optional<std::array<authority::FieldExactRational, 3>>
source_vertex_barycentric(const SourceFaceRecord &face,
                          const authority::SourceVertexId vertex) {
  std::array<authority::FieldExactRational, 3> barycentric{
      authority::FieldExactRational::from_integer(0),
      authority::FieldExactRational::from_integer(0),
      authority::FieldExactRational::from_integer(0)};
  for (std::size_t index = 0U; index < face.vertices.size(); ++index) {
    if (face.vertices[index] != vertex) continue;
    barycentric[index] = authority::FieldExactRational::from_integer(1);
    return barycentric;
  }
  return std::nullopt;
}

std::optional<std::array<authority::FieldExactRational, 3>>
vertex_trace_ray_second_point(
    const SourceFaceRecord &face, const GlobalTopologyArc &arc,
    const authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace) {
  if (arc.firstSegment >= arc.onePastLastSegment ||
      arc.onePastLastSegment > trace.segments.size()) {
    return std::nullopt;
  }
  const std::size_t segmentIndex =
      orientation == authority::Orientation::Forward
          ? arc.firstSegment
          : arc.onePastLastSegment - 1U;
  const auto &segment = trace.segments[segmentIndex];
  if (segment.sourceFace != face.topology) return std::nullopt;

  if (orientation == authority::Orientation::Reverse) {
    return field_boundary_point_barycentric(face, segment.entryPoint);
  }

  if (segment.edgeTransitExit.has_value()) {
    return field_boundary_point_barycentric(face, *segment.edgeTransitExit);
  }
  if (segmentIndex + 1U < trace.segments.size()) {
    const auto continued = field_boundary_point_barycentric(
        face, trace.segments[segmentIndex + 1U].entryPoint);
    if (continued.has_value()) return continued;
  }
  if (trace.terminalContact.has_value() &&
      trace.terminalContact->sourceFace == face.topology) {
    const auto canonicalVertices = trace.terminalContact->sourceFace.vertices();
    auto orientedBarycentric = trace.terminalContact->barycentric;
    std::array<bool, 3> assigned{false, false, false};
    for (std::size_t canonicalCorner = 0U; canonicalCorner < 3U;
         ++canonicalCorner) {
      bool mapped = false;
      for (std::size_t orientedCorner = 0U; orientedCorner < 3U;
           ++orientedCorner) {
        if (face.vertices[orientedCorner] != canonicalVertices[canonicalCorner])
          continue;
        if (assigned[orientedCorner]) return std::nullopt;
        orientedBarycentric[orientedCorner] =
            trace.terminalContact->barycentric[canonicalCorner];
        assigned[orientedCorner] = true;
        mapped = true;
        break;
      }
      if (!mapped) return std::nullopt;
    }
    for (const bool wasAssigned : assigned) {
      if (!wasAssigned) return std::nullopt;
    }
    return orientedBarycentric;
  }
  if (trace.terminalPoint.has_value()) {
    const auto terminal =
        field_boundary_point_barycentric(face, *trace.terminalPoint);
    if (terminal.has_value()) return terminal;
  }

  // Vertex-hit continuation is the final exact fallback.  A continuation can
  // enter its next face through an edge that is not an edge of this face even
  // though the entry point itself is their shared source vertex.  Recover that
  // vertex from the exact boundary-point support, then express the same source
  // vertex as this face's unit barycentric corner.  Keeping this last preserves
  // all previously representable Forward exits byte-for-byte.
  if (segmentIndex + 1U < trace.segments.size()) {
    const auto support =
        trace.segments[segmentIndex + 1U].entryPoint.source_support();
    if (support.has_value()) {
      if (const auto *vertex =
              std::get_if<authority::SourceVertexSupport>(&*support)) {
        return source_vertex_barycentric(face, vertex->vertex);
      }
    }
  }
  return std::nullopt;
}

std::optional<authority::FieldExactRational> vertex_locus_secondary_parameter(
    const SourceTopologyIndex &topology,
    const authority::SourceVertexId locus, const GlobalTopologyArc &arc,
    const authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace,
    VertexTraceSecondaryParameterFailureReason *failureReason) {
  const auto fail = [&](const VertexTraceSecondaryParameterFailureReason reason)
      -> std::optional<authority::FieldExactRational> {
    if (failureReason != nullptr) *failureReason = reason;
    return std::nullopt;
  };
  const auto faceKey = trace_ray_face(arc, orientation, trace);
  if (!faceKey.has_value()) {
    return fail(VertexTraceSecondaryParameterFailureReason::
                    TraceRayFaceUnavailable);
  }
  const auto faceIt = topology.faces.find(*faceKey);
  if (faceIt == topology.faces.end()) {
    return fail(VertexTraceSecondaryParameterFailureReason::
                    SourceFaceRecordUnavailable);
  }
  const SourceFaceRecord &face = faceIt->second;

  std::size_t corner = 3U;
  for (std::size_t index = 0U; index < face.vertices.size(); ++index) {
    if (face.vertices[index] == locus) {
      corner = index;
      break;
    }
  }
  if (corner >= 3U) {
    return fail(
        VertexTraceSecondaryParameterFailureReason::LocusCornerUnavailable);
  }

  const auto secondPoint =
      vertex_trace_ray_second_point(face, arc, orientation, trace);
  if (!secondPoint.has_value()) {
    return fail(
        VertexTraceSecondaryParameterFailureReason::SecondPointUnavailable);
  }
  const std::size_t next = (corner + 1U) % 3U;
  const std::size_t previous = (corner + 2U) % 3U;
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto denominator = (*secondPoint)[next] + (*secondPoint)[previous];
  if (denominator <= zero || (*secondPoint)[next] < zero ||
      (*secondPoint)[previous] < zero) {
    return fail(
        VertexTraceSecondaryParameterFailureReason::InvalidDenominator);
  }

  // build_vertex_fan_slots orders a face wedge from the oriented edge
  // (v,next) to (previous,v).  Projecting a ray from v to the opposite edge
  // preserves angular order, so the exact opposite-edge parameter below is a
  // canonical within-wedge order key.  No metric geometry is involved.
  return (*secondPoint)[previous] / denominator;
}

std::vector<std::size_t> vertex_trace_secondary_ranks(
    const std::vector<authority::FieldExactRational> &parameters) {
  std::vector<std::size_t> order(parameters.size());
  std::iota(order.begin(), order.end(), 0U);
  std::sort(order.begin(), order.end(), [&](const std::size_t lhs,
                                            const std::size_t rhs) {
    return parameters[lhs] < parameters[rhs];
  });

  std::vector<std::size_t> ranks(parameters.size(), 0U);
  std::size_t rank = 0U;
  for (std::size_t position = 0U; position < order.size(); ++position) {
    if (position > 0U &&
        parameters[order[position - 1U]] != parameters[order[position]]) {
      ++rank;
    }
    ranks[order[position]] = rank;
  }
  return ranks;
}

RotationSystemInconsistencyReason vertex_trace_secondary_collision_reason(
    const authority::FieldExactRational &first,
    const authority::FieldExactRational &second) noexcept {
  return first == second
             ? RotationSystemInconsistencyReason::
                   RotationVertexTraceRaysExactlyCoincident
             : RotationSystemInconsistencyReason::RotationRayOrderKeyCollision;
}

std::optional<std::size_t> edge_locus_secondary_rank(
    const SourceTopologyIndex &topology,
    const authority::SourceEdgeTopologyKey &locus,
    const GlobalTopologyArc &arc, const authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace,
    EdgeTraceSecondaryRankFailureReason *failureReason,
    EdgeLocusSecondaryRankDiagnosticContext *diagnosticContext) {
  if (diagnosticContext != nullptr) *diagnosticContext = {};
  const auto fail = [&](const EdgeTraceSecondaryRankFailureReason reason)
      -> std::optional<std::size_t> {
    if (failureReason != nullptr) *failureReason = reason;
    return std::nullopt;
  };

  const auto faceKey = trace_ray_face(arc, orientation, trace);
  if (!faceKey.has_value()) {
    return fail(
        EdgeTraceSecondaryRankFailureReason::TraceRayFaceUnavailable);
  }
  if (diagnosticContext != nullptr) diagnosticContext->sourceFace = *faceKey;

  const auto faceIt = topology.faces.find(*faceKey);
  if (faceIt == topology.faces.end()) {
    return fail(
        EdgeTraceSecondaryRankFailureReason::SourceFaceRecordUnavailable);
  }
  if (diagnosticContext != nullptr)
    diagnosticContext->faceCorners = faceIt->second.vertices;

  const auto contactIndex = local_edge_index(faceIt->second, locus);
  if (!contactIndex.has_value()) {
    return fail(EdgeTraceSecondaryRankFailureReason::ContactEdgeUnavailable);
  }
  if (diagnosticContext != nullptr)
    diagnosticContext->contactIndex = *contactIndex;

  const std::size_t segmentIndex =
      orientation == authority::Orientation::Forward
          ? arc.firstSegment
          : arc.onePastLastSegment - 1U;
  const auto &segment = trace.segments[segmentIndex];
  if (diagnosticContext != nullptr) {
    diagnosticContext->incomingCarrier = segment.incomingCarrier;
    diagnosticContext->outgoingCarrier = segment.outgoingCarrier;
  }

  std::optional<authority::SourceEdgeTopologyKey> other;
  if (orientation == authority::Orientation::Forward) {
    if (segment.incomingCarrier.has_value() &&
        *segment.incomingCarrier == locus) {
      other = segment.outgoingCarrier;
    }
  } else if (segment.outgoingCarrier == locus) {
    other = segment.incomingCarrier;
  }
  if (diagnosticContext != nullptr)
    diagnosticContext->otherCarrier = other;

  if (other.has_value()) {
    const auto otherIndex = local_edge_index(faceIt->second, *other);
    if (!otherIndex.has_value()) {
      return fail(
          EdgeTraceSecondaryRankFailureReason::OppositeCarrierNotInFace);
    }
    if (*otherIndex == *contactIndex) {
      return fail(
          EdgeTraceSecondaryRankFailureReason::CoincidentLocalEdgeIndex);
    }
    return 2U * ((*otherIndex + 3U - *contactIndex) % 3U);
  }

  // With no opposite carrier, the ray can still leave this contact edge
  // through a face corner. Bind that corner to the selected segment's own
  // far-end boundary support: entry for Reverse, exit for Forward. This also
  // recovers the historical first-segment singularity case because that
  // segment's entry support is the trace source vertex.
  const authority::FieldBoundaryPoint *farEndPoint = nullptr;
  if (orientation == authority::Orientation::Reverse) {
    farEndPoint = &segment.entryPoint;
  } else if (segment.edgeTransitExit.has_value()) {
    farEndPoint = &*segment.edgeTransitExit;
  } else if (segmentIndex + 1U < trace.segments.size()) {
    farEndPoint = &trace.segments[segmentIndex + 1U].entryPoint;
  } else if (trace.terminalPoint.has_value()) {
    farEndPoint = &*trace.terminalPoint;
  }

  if (farEndPoint != nullptr) {
    const auto support = farEndPoint->source_support();
    if (support.has_value()) {
      if (const auto *vertex =
              std::get_if<authority::SourceVertexSupport>(&*support)) {
        for (std::size_t corner = 0U; corner < 3U; ++corner) {
          if (faceIt->second.vertices[corner] != vertex->vertex) continue;
          return 1U +
                 2U * ((corner + 2U + 3U - *contactIndex) % 3U);
        }
      }
    }
  }
  return fail(
      EdgeTraceSecondaryRankFailureReason::SourceVertexFallbackUnbound);
}

RotationBuildResult build_rotation_system(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const CutNodeBindings &cutNodes,
    const std::vector<GlobalTopologyArc> &arcs) {
  const NodeLocusResult locusResult = build_node_loci(network, cutNodes);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&locusResult)) {
    return *failure;
  }
  const auto &loci =
      std::get<std::map<authority::NetworkNodeId, NodeLocus>>(locusResult);
  const FaceContactNodeResult faceContactBuild =
      collect_face_contact_nodes(network);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&faceContactBuild)) {
    return *failure;
  }
  const auto &faceContacts =
      std::get<std::map<authority::NetworkNodeId, FaceContactNode>>(
          faceContactBuild);

  std::map<authority::NetworkNodeId,
           std::vector<GlobalTopologyOrientedArc>>
      incidences;
  for (const auto &[node, locus] : loci) {
    (void)locus;
    incidences[node];
  }
  for (const auto &arc : arcs) {
    incidences[arc.firstNode].push_back(
        GlobalTopologyOrientedArc{arc.id, authority::Orientation::Forward});
    incidences[arc.secondNode].push_back(
        GlobalTopologyOrientedArc{arc.id, authority::Orientation::Reverse});
  }

  std::map<authority::NetworkArcId, const GlobalTopologyArc *> arcById;
  for (const auto &arc : arcs) arcById.emplace(arc.id, &arc);

  std::vector<GlobalTopologyNodeRotation> rotations;
  rotations.reserve(incidences.size());
  for (auto &[node, outgoing] : incidences) {
    if (outgoing.empty()) {
      GlobalTopologyPlanError result =
          rotation_error(RotationSystemInconsistencyReason::RotationNodeOutgoingIncidenceEmpty);
      return result;
    }
    const auto locusIt = loci.find(node);
    if (locusIt == loci.end()) {
      return rotation_error(RotationSystemInconsistencyReason::RotationNodeLocusMissing);
    }

    std::vector<std::pair<RayOrderKey, GlobalTopologyOrientedArc>> keyed;
    keyed.reserve(outgoing.size());
    std::map<GlobalTopologyOrientedArc, RotationRayOrderDiagnostic>
        rayDiagnostics;
    std::map<GlobalTopologyOrientedArc, authority::FieldExactRational>
        vertexTraceSecondaryParameters;
    const auto base_ray_diagnostic = [](const RayOrderKey &key) {
      RotationRayOrderDiagnostic diagnostic(key.arc);
      diagnostic.kind = key.kind;
      diagnostic.primary = key.primary;
      diagnostic.secondary = key.secondary;
      diagnostic.arc = key.arc;
      diagnostic.trace = key.trace;
      diagnostic.orientation = key.orientation;
      return diagnostic;
    };
    if (locusIt->second.vertex.has_value()) {
      const auto slots =
          build_vertex_fan_slots(topology, *locusIt->second.vertex);
      if (!slots.has_value()) {
        GlobalTopologyPlanError result =
            rotation_error(RotationSystemInconsistencyReason::RotationVertexFanSlotsUnavailable);
        result.sourceVertex = locusIt->second.vertex;
        return result;
      }
      for (const auto incidence : outgoing) {
        const auto arcIt = arcById.find(incidence.arc);
        if (arcIt == arcById.end()) {
          return rotation_error(RotationSystemInconsistencyReason::RotationVertexArcBindingMissing);
        }
        const GlobalTopologyArc &arc = *arcIt->second;
        RayOrderKey key(arc.id);
        key.kind = arc.kind;
        key.trace = arc.trace;
        key.arc = arc.id;
        key.orientation = incidence.orientation;
        if (arc.kind == GlobalTopologyArcKind::Mandatory ||
            arc.kind == GlobalTopologyArcKind::Cut) {
          std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
          if (arc.kind == GlobalTopologyArcKind::Mandatory) {
            if (!arc.mandatoryEdge.has_value()) {
              return rotation_error(RotationSystemInconsistencyReason::RotationVertexMandatoryArcMissingNetworkEdge);
            }
            const auto *mandatory = find_mandatory(network, *arc.mandatoryEdge);
            if (mandatory == nullptr) {
              return rotation_error(RotationSystemInconsistencyReason::RotationVertexMandatoryNetworkEdgeMissing);
            }
            sourceEdge = mandatory->sourceEdge;
          } else {
            sourceEdge = arc.cutEdge;
          }
          if (!sourceEdge.has_value()) {
            return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
          }
          const auto slot = slots->edgeSlots.find(*sourceEdge);
          if (slot == slots->edgeSlots.end()) {
            GlobalTopologyPlanError result =
                rotation_error(RotationSystemInconsistencyReason::RotationVertexSourceEdgeMissingFromFan);
            result.sourceVertex = locusIt->second.vertex;
            result.sourceEdge = *sourceEdge;
            return result;
          }
          key.primary = 2U * slot->second;
        } else {
          if (!arc.trace.has_value()) {
            return rotation_error(RotationSystemInconsistencyReason::RotationVertexTraceBindingMissing);
          }
          const auto *trace = find_trace(network, *arc.trace);
          if (trace == nullptr) {
            return rotation_error(RotationSystemInconsistencyReason::RotationVertexTraceMissing);
          }
          const auto face = trace_ray_face(arc, incidence.orientation, *trace);
          if (!face.has_value()) {
            return rotation_error(RotationSystemInconsistencyReason::RotationVertexTraceRayFaceUnavailable);
          }
          const auto slot = slots->faceSlots.find(*face);
          if (slot == slots->faceSlots.end()) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceVertex = locusIt->second.vertex;
            result.sourceFace = face;
            result.rotationSystemInconsistencyReason =
                RotationSystemInconsistencyReason::VertexTraceFaceMissingFromFan;
            return result;
          }
          key.primary = 2U * slot->second + 1U;
          const auto port = std::find_if(
              network.singularity_ports().begin(),
              network.singularity_ports().end(), [&](const auto &candidate) {
                return candidate.id == trace->port;
              });
          if (port == network.singularity_ports().end() ||
              port->ordinal < 0) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceVertex = locusIt->second.vertex;
            result.sourceFace = face;
            result.rotationSystemInconsistencyReason =
                RotationSystemInconsistencyReason::VertexTracePortOrdinalInvalid;
            return result;
          }
          VertexTraceSecondaryParameterFailureReason secondaryFailure =
              VertexTraceSecondaryParameterFailureReason::
                  SecondPointUnavailable;
          const auto secondaryParameter = vertex_locus_secondary_parameter(
              topology, *locusIt->second.vertex, arc, incidence.orientation,
              *trace, &secondaryFailure);
          if (!secondaryParameter.has_value()) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceVertex = locusIt->second.vertex;
            result.sourceFace = face;
            result.rotationSystemInconsistencyReason =
                RotationSystemInconsistencyReason::
                    VertexTraceSecondaryParameterUnavailable;
            result.vertexTraceSecondaryParameterFailureReason =
                secondaryFailure;
            result.arc = arc.id;
            result.trace = trace->id;
            result.rotationTraceOrientation = incidence.orientation;
            result.traceFirstSegment = arc.firstSegment;
            result.traceOnePastLastSegment = arc.onePastLastSegment;
            return result;
          }
          key.secondary = 0U;
          vertexTraceSecondaryParameters.emplace(incidence,
                                                  *secondaryParameter);
          RotationRayOrderDiagnostic diagnostic = base_ray_diagnostic(key);
          diagnostic.sourceFace = *face;
          diagnostic.fanSlot = slot->second;
          diagnostic.originPortOrdinal = port->ordinal;
          diagnostic.originPortSourceVertex = port->sourceVertex;
          rayDiagnostics.emplace(incidence, std::move(diagnostic));
        }
        keyed.emplace_back(key, incidence);
      }

      std::map<std::size_t, std::vector<std::size_t>> traceRaysByWedge;
      for (std::size_t index = 0U; index < keyed.size(); ++index) {
        if (keyed[index].first.kind == GlobalTopologyArcKind::Trace) {
          traceRaysByWedge[keyed[index].first.primary].push_back(index);
        }
      }
      for (auto &[primary, indices] : traceRaysByWedge) {
        (void)primary;
        std::vector<authority::FieldExactRational> parameters;
        parameters.reserve(indices.size());
        for (const std::size_t index : indices) {
          parameters.push_back(
              vertexTraceSecondaryParameters.at(keyed[index].second));
        }
        const auto ranks = vertex_trace_secondary_ranks(parameters);
        for (std::size_t position = 0U; position < indices.size(); ++position) {
          RayOrderKey &key = keyed[indices[position]].first;
          key.secondary = ranks[position];
          const auto diagnostic = rayDiagnostics.find(keyed[indices[position]].second);
          if (diagnostic != rayDiagnostics.end()) {
            diagnostic->second.secondary = ranks[position];
          }
        }
      }
    } else if (locusIt->second.edge.has_value()) {
      const auto incidentFaces = topology.incidentFaces.find(*locusIt->second.edge);
      if (incidentFaces == topology.incidentFaces.end() ||
          incidentFaces->second.empty()) {
        GlobalTopologyPlanError result =
            rotation_error(incidentFaces == topology.incidentFaces.end() ? RotationSystemInconsistencyReason::RotationEdgeIncidentFacesMissing : RotationSystemInconsistencyReason::RotationEdgeIncidentFacesEmpty);
        result.sourceEdge = locusIt->second.edge;
        return result;
      }
      std::map<authority::SourceFaceTopologyKey, std::size_t> sideRank;
      for (const auto &faceKey : incidentFaces->second) {
        const auto face = topology.faces.find(faceKey);
        if (face == topology.faces.end()) {
          return rotation_error(RotationSystemInconsistencyReason::RotationEdgeSourceFaceMissing);
        }
        sideRank.emplace(
            faceKey,
            face_orients_edge_forward(face->second, *locusIt->second.edge)
                ? 0U
                : 1U);
      }

      const std::size_t edgeRayCount = static_cast<std::size_t>(
          std::count_if(outgoing.begin(), outgoing.end(), [&](const auto incidence) {
            const auto arcIt = arcById.find(incidence.arc);
            return arcIt != arcById.end() &&
                   (arcIt->second->kind == GlobalTopologyArcKind::Mandatory ||
                    arcIt->second->kind == GlobalTopologyArcKind::Cut);
          }));
      if (edgeRayCount != 0U && edgeRayCount != 2U) {
        GlobalTopologyPlanError result =
            rotation_error(RotationSystemInconsistencyReason::RotationEdgeRayCountInvalid);
        result.sourceEdge = locusIt->second.edge;
        return result;
      }
      if (edgeRayCount == 2U && outgoing.size() != 3U && outgoing.size() != 4U) {
        GlobalTopologyPlanError result =
            rotation_error(RotationSystemInconsistencyReason::RotationEdgeRayValenceInvalid);
        result.sourceEdge = locusIt->second.edge;
        return result;
      }

      // Diagnostic-only census for edge-locus failures. It reuses the exact
      // already-owned ordering inputs and never feeds a semantic decision.
      const auto edge_ray_diagnostic = [&](const GlobalTopologyOrientedArc incidence) {
        RotationRayOrderDiagnostic diagnostic(incidence.arc);
        diagnostic.orientation = incidence.orientation;
        const auto arcIt = arcById.find(incidence.arc);
        if (arcIt == arcById.end()) return diagnostic;
        const GlobalTopologyArc &arc = *arcIt->second;
        diagnostic.kind = arc.kind;
        diagnostic.trace = arc.trace;

        if (arc.kind == GlobalTopologyArcKind::Mandatory ||
            arc.kind == GlobalTopologyArcKind::Cut) {
          const auto towardSecond = edge_ray_points_to_second_endpoint(
              arc, incidence.orientation, *locusIt->second.edge, network,
              cutNodes);
          if (towardSecond.has_value()) {
            diagnostic.primary = *towardSecond ? 0U : 2U;
          }
          return diagnostic;
        }

        diagnostic.secondaryAvailable = false;
        if (!arc.trace.has_value()) return diagnostic;
        const auto *trace = find_trace(network, *arc.trace);
        if (trace == nullptr) return diagnostic;
        const auto face = trace_ray_face(arc, incidence.orientation, *trace);
        if (!face.has_value()) return diagnostic;
        diagnostic.sourceFace = *face;
        const auto side = sideRank.find(*face);
        if (side == sideRank.end()) return diagnostic;
        diagnostic.primary = edgeRayCount == 0U ? side->second
                                                : 2U * side->second + 1U;
        const auto secondary = edge_locus_secondary_rank(
            topology, *locusIt->second.edge, arc, incidence.orientation,
            *trace);
        if (secondary.has_value()) {
          diagnostic.secondary = *secondary;
          diagnostic.secondaryAvailable = true;
        }
        return diagnostic;
      };
      const auto publish_edge_locus_census = [&](GlobalTopologyPlanError &result) {
        constexpr std::size_t kRotationFanCensusLimit = 16U;
        result.rotationFanCensus.totalRayCount = outgoing.size();
        const std::size_t censusCount =
            std::min(outgoing.size(), kRotationFanCensusLimit);
        result.rotationFanCensus.rays.reserve(censusCount);
        for (std::size_t censusIndex = 0U; censusIndex < censusCount;
             ++censusIndex) {
          result.rotationFanCensus.rays.push_back(
              edge_ray_diagnostic(outgoing[censusIndex]));
        }
        result.rotationFanCensus.truncated = censusCount < outgoing.size();
      };

      for (const auto incidence : outgoing) {
        const auto arcIt = arcById.find(incidence.arc);
        if (arcIt == arcById.end()) {
          return rotation_error(RotationSystemInconsistencyReason::RotationEdgeArcBindingMissing);
        }
        const GlobalTopologyArc &arc = *arcIt->second;
        RayOrderKey key(arc.id);
        key.kind = arc.kind;
        key.trace = arc.trace;
        key.arc = arc.id;
        key.orientation = incidence.orientation;

        if (arc.kind == GlobalTopologyArcKind::Mandatory ||
            arc.kind == GlobalTopologyArcKind::Cut) {
          if (edgeRayCount != 2U) {
            GlobalTopologyPlanError result =
                rotation_error(RotationSystemInconsistencyReason::RotationEdgeNonTraceArcRequiresTwoRays);
            result.sourceEdge = locusIt->second.edge;
            return result;
          }
          if (arc.kind == GlobalTopologyArcKind::Mandatory &&
              !arc.mandatoryEdge.has_value()) {
            return rotation_error(RotationSystemInconsistencyReason::RotationEdgeMandatoryArcMissingNetworkEdge);
          }
          if (arc.kind == GlobalTopologyArcKind::Cut &&
              arc.cutEdge != *locusIt->second.edge) {
            GlobalTopologyPlanError result =
                rotation_error(RotationSystemInconsistencyReason::RotationEdgeCutArcLocusMismatch);
            result.sourceEdge = locusIt->second.edge;
            return result;
          }
          const auto towardSecond = edge_ray_points_to_second_endpoint(
              arc, incidence.orientation, *locusIt->second.edge, network,
              cutNodes);
          if (!towardSecond.has_value()) {
            GlobalTopologyPlanError result =
                rotation_error(RotationSystemInconsistencyReason::RotationEdgeRayEndpointDirectionUnavailable);
            result.sourceEdge = locusIt->second.edge;
            result.networkEdge = arc.mandatoryEdge;
            return result;
          }
          // Around the canonical edge direction, side-rank 0 lies between
          // the ray toward the second endpoint and the ray toward the first;
          // side-rank 1 occupies the complementary sector.
          key.primary = *towardSecond ? 0U : 2U;
          keyed.emplace_back(key, incidence);
          continue;
        }

        if (!arc.trace.has_value()) {
          GlobalTopologyPlanError result =
              rotation_error(RotationSystemInconsistencyReason::RotationEdgeTraceBindingMissing);
          result.sourceEdge = locusIt->second.edge;
          return result;
        }
        const auto *trace = find_trace(network, *arc.trace);
        if (trace == nullptr) {
          return rotation_error(RotationSystemInconsistencyReason::RotationEdgeTraceMissing);
        }
        const auto face = trace_ray_face(arc, incidence.orientation, *trace);
        if (!face.has_value() || sideRank.count(*face) == 0U) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceEdge = locusIt->second.edge;
          result.sourceFace = face;
          result.rotationSystemInconsistencyReason =
              RotationSystemInconsistencyReason::EdgeTraceFaceSideInvalid;
          return result;
        }
        EdgeTraceSecondaryRankFailureReason secondaryFailure =
            EdgeTraceSecondaryRankFailureReason::SourceVertexFallbackUnbound;
        EdgeLocusSecondaryRankDiagnosticContext secondaryContext;
        const auto secondary = edge_locus_secondary_rank(
            topology, *locusIt->second.edge, arc, incidence.orientation,
            *trace, &secondaryFailure, &secondaryContext);
        if (!secondary.has_value()) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceEdge = locusIt->second.edge;
          result.sourceFace = face;
          result.sourceVertex = trace->sourceVertex;
          result.rotationSystemInconsistencyReason =
              RotationSystemInconsistencyReason::EdgeTraceSecondaryRankInvalid;
          result.edgeTraceSecondaryRankFailureReason = secondaryFailure;
          result.arc = arc.id;
          result.trace = trace->id;
          result.rotationTraceOrientation = incidence.orientation;
          result.traceFirstSegment = arc.firstSegment;
          result.traceOnePastLastSegment = arc.onePastLastSegment;
          result.traceIncomingCarrier = secondaryContext.incomingCarrier;
          result.traceOutgoingCarrier = secondaryContext.outgoingCarrier;
          result.edgeTraceContactIndex = secondaryContext.contactIndex;
          result.edgeTraceOtherCarrier = secondaryContext.otherCarrier;
          result.edgeTraceFaceCorners = secondaryContext.faceCorners;
          publish_edge_locus_census(result);
          return result;
        }
        key.primary = edgeRayCount == 0U
                          ? sideRank.at(*face)
                          : 2U * sideRank.at(*face) + 1U;
        key.secondary = *secondary;
        keyed.emplace_back(key, incidence);
      }
    } else if (const auto contact = faceContacts.find(node);
               contact != faceContacts.end()) {
      // FC-5: order the rays counter-clockwise around the exact contact
      // point, in the face's oriented corner order (Amendment 26).
      const authority::SourceFaceTopologyKey &faceKey = contact->second.face;
      const auto unsupported = [&](const std::optional<authority::TraceId> trace) {
        return face_contact_error(
            RotationSystemInconsistencyReason::FaceContactRayUnsupported,
            faceKey, trace);
      };
      const auto faceIt = topology.faces.find(faceKey);
      if (faceIt == topology.faces.end()) return unsupported(std::nullopt);
      const auto &canonicalVertices = faceKey.vertices();
      std::array<std::size_t, 3> canonicalCorner{3U, 3U, 3U};
      for (std::size_t corner = 0U; corner < 3U; ++corner) {
        for (std::size_t index = 0U; index < 3U; ++index) {
          if (faceIt->second.vertices[corner] == canonicalVertices[index]) {
            canonicalCorner[corner] = index;
          }
        }
        if (canonicalCorner[corner] >= 3U) return unsupported(std::nullopt);
      }
      const auto oriented = [&](const FaceChartPoint &point) {
        FaceChartPoint result = point;
        for (std::size_t corner = 0U; corner < 3U; ++corner) {
          result[corner] = point[canonicalCorner[corner]];
        }
        return result;
      };
      std::vector<FaceChartPoint> targets;
      targets.reserve(outgoing.size());
      for (const auto incidence : outgoing) {
        const auto arcIt = arcById.find(incidence.arc);
        if (arcIt == arcById.end() ||
            arcIt->second->kind != GlobalTopologyArcKind::Trace ||
            !arcIt->second->trace.has_value()) {
          return unsupported(std::nullopt);
        }
        const GlobalTopologyArc &arc = *arcIt->second;
        const FieldAlignedCandidateTrace *trace = find_trace(network, *arc.trace);
        if (trace == nullptr || arc.firstSegment >= arc.onePastLastSegment ||
            arc.onePastLastSegment > trace->segments.size()) {
          return unsupported(arc.trace);
        }
        // A trace segment is straight in its face, so the ray from the
        // contact point along it heads to the segment's exit (forward) or
        // entry (reverse).
        const bool forward = incidence.orientation == authority::Orientation::Forward;
        const std::size_t segment =
            forward ? arc.firstSegment : arc.onePastLastSegment - 1U;
        if (trace->segments[segment].sourceFace != faceKey) {
          return unsupported(arc.trace);
        }
        const auto second = forward
                                ? trace_segment_canonical_exit(*trace, segment)
                                : trace_segment_canonical_entry(*trace, segment);
        if (!second.has_value()) return unsupported(arc.trace);
        targets.push_back(oriented(*second));
      }
      const auto order = face_chart_counter_clockwise_ray_order(
          oriented(contact->second.point), targets);
      if (!order.has_value()) {
        return face_contact_error(
            RotationSystemInconsistencyReason::FaceContactRayDirectionCollision,
            faceKey, std::nullopt);
      }
      for (std::size_t rank = 0U; rank < order->size(); ++rank) {
        const GlobalTopologyOrientedArc incidence = outgoing[(*order)[rank]];
        const GlobalTopologyArc &arc = *arcById.at(incidence.arc);
        RayOrderKey key(arc.id);
        key.kind = arc.kind;
        key.trace = arc.trace;
        key.orientation = incidence.orientation;
        key.primary = rank;
        keyed.emplace_back(key, incidence);
      }
    } else {
      return rotation_error(RotationSystemInconsistencyReason::RotationNodeLocusUnsupported);
    }

    std::sort(keyed.begin(), keyed.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.first < rhs.first;
    });
    for (std::size_t index = 1U; index < keyed.size(); ++index) {
      const RayOrderKey &previous = keyed[index - 1U].first;
      const RayOrderKey &current = keyed[index].first;
      if (locusIt->second.vertex.has_value() &&
          previous.kind == GlobalTopologyArcKind::Trace &&
          current.kind == GlobalTopologyArcKind::Trace &&
          previous.primary == current.primary &&
          previous.secondary == current.secondary) {
        GlobalTopologyPlanError result = rotation_error(
            vertex_trace_secondary_collision_reason(
                vertexTraceSecondaryParameters.at(keyed[index - 1U].second),
                vertexTraceSecondaryParameters.at(keyed[index].second)));
        result.sourceVertex = locusIt->second.vertex;
        result.sourceEdge = locusIt->second.edge;
        const auto diagnostic_for = [&](const std::size_t keyedIndex) {
          const auto found = rayDiagnostics.find(keyed[keyedIndex].second);
          return found != rayDiagnostics.end()
                     ? found->second
                     : base_ray_diagnostic(keyed[keyedIndex].first);
        };
        result.rotationPreviousRay = diagnostic_for(index - 1U);
        result.rotationCurrentRay = diagnostic_for(index);
        result.arc = result.rotationPreviousRay->arc;
        result.secondArc = result.rotationCurrentRay->arc;
        result.trace = result.rotationPreviousRay->trace;
        result.secondTrace = result.rotationCurrentRay->trace;
        result.sourceFace = result.rotationPreviousRay->sourceFace;
        result.secondSourceFace = result.rotationCurrentRay->sourceFace;
        constexpr std::size_t kRotationFanCensusLimit = 16U;
        result.rotationFanCensus.totalRayCount = keyed.size();
        const std::size_t censusCount =
            std::min(keyed.size(), kRotationFanCensusLimit);
        result.rotationFanCensus.rays.reserve(censusCount);
        for (std::size_t censusIndex = 0U; censusIndex < censusCount;
             ++censusIndex) {
          result.rotationFanCensus.rays.push_back(
              diagnostic_for(censusIndex));
        }
        result.rotationFanCensus.truncated = censusCount < keyed.size();
        return result;
      }
    }
    GlobalTopologyNodeRotation rotation{node, {}};
    rotation.counterClockwise.reserve(keyed.size());
    for (const auto &[key, incidence] : keyed) {
      (void)key;
      rotation.counterClockwise.push_back(incidence);
    }
    rotations.push_back(std::move(rotation));
  }
  std::sort(rotations.begin(), rotations.end(), [](const auto &lhs,
                                                    const auto &rhs) {
    return lhs.node < rhs.node;
  });
  return rotations;
}

std::size_t dart_index(const GlobalTopologyOrientedArc incidence) {
  return 2U * incidence.arc.index() +
         (incidence.orientation == authority::Orientation::Forward ? 0U : 1U);
}

GlobalTopologyOrientedArc oriented_arc_from_dart(
    const std::size_t dart, const std::size_t arcExtent) {
  return GlobalTopologyOrientedArc{
      make_id<authority::NetworkArcId>(dart / 2U, arcExtent),
      (dart % 2U) == 0U ? authority::Orientation::Forward
                        : authority::Orientation::Reverse};
}

GlobalTopologyOrientedArc reversed(
    const GlobalTopologyOrientedArc incidence) {
  return GlobalTopologyOrientedArc{
      incidence.arc,
      incidence.orientation == authority::Orientation::Forward
          ? authority::Orientation::Reverse
          : authority::Orientation::Forward};
}

void canonicalize_cycle(std::vector<GlobalTopologyOrientedArc> &cycle) {
  if (cycle.empty()) return;
  const auto less = [](const GlobalTopologyOrientedArc lhs,
                       const GlobalTopologyOrientedArc rhs) {
    return std::tie(lhs.arc, lhs.orientation) <
           std::tie(rhs.arc, rhs.orientation);
  };
  std::size_t best = 0U;
  for (std::size_t start = 1U; start < cycle.size(); ++start) {
    bool candidateIsLess = false;
    bool decided = false;
    for (std::size_t offset = 0U; offset < cycle.size(); ++offset) {
      const auto candidate = cycle[(start + offset) % cycle.size()];
      const auto current = cycle[(best + offset) % cycle.size()];
      if (candidate == current) continue;
      candidateIsLess = less(candidate, current);
      decided = true;
      break;
    }
    if (decided && candidateIsLess) best = start;
  }
  std::rotate(cycle.begin(), cycle.begin() + static_cast<std::ptrdiff_t>(best),
              cycle.end());
}

FaceWalkBuildResult walk_graph_faces(
    const std::vector<GlobalTopologyArc> &arcs,
    const std::vector<GlobalTopologyNodeRotation> &rotations) {
  if (arcs.empty()) {
    return rotation_error(RotationSystemInconsistencyReason::FaceWalkArcSetEmpty);
  }
  const std::size_t dartCount = 2U * arcs.size();
  std::vector<std::size_t> successor(dartCount,
                                     std::numeric_limits<std::size_t>::max());
  std::vector<std::size_t> incidenceCount(dartCount, 0U);
  for (const auto &rotation : rotations) {
    const std::size_t count = rotation.counterClockwise.size();
    if (count == 0U) {
      GlobalTopologyPlanError result =
          rotation_error(RotationSystemInconsistencyReason::FaceWalkNodeRotationEmpty);
      return result;
    }
    for (std::size_t index = 0U; index < count; ++index) {
      const auto reverseIncidence = rotation.counterClockwise[index];
      const std::size_t reverseDart = dart_index(reverseIncidence);
      if (reverseDart >= dartCount) {
        GlobalTopologyPlanError result =
            rotation_error(RotationSystemInconsistencyReason::FaceWalkRotationDartOutOfRange);
        result.region.reset();
        result.arc = reverseIncidence.arc;
        return result;
      }
      ++incidenceCount[reverseDart];
      const auto next = rotation.counterClockwise[(index + count - 1U) % count];
      const std::size_t incomingDart = dart_index(reversed(reverseIncidence));
      if (successor[incomingDart] != std::numeric_limits<std::size_t>::max()) {
        GlobalTopologyPlanError result =
            rotation_error(RotationSystemInconsistencyReason::FaceWalkSuccessorAlreadyAssigned);
        result.arc = reverseIncidence.arc;
        return result;
      }
      successor[incomingDart] = dart_index(next);
    }
  }
  if (std::any_of(incidenceCount.begin(), incidenceCount.end(),
                  [](const std::size_t count) { return count != 1U; }) ||
      std::any_of(successor.begin(), successor.end(), [](const std::size_t next) {
        return next == std::numeric_limits<std::size_t>::max();
      })) {
    return rotation_error(std::any_of(incidenceCount.begin(), incidenceCount.end(), [](const std::size_t count) { return count != 1U; }) ? RotationSystemInconsistencyReason::FaceWalkIncidenceCountInvalid : RotationSystemInconsistencyReason::FaceWalkSuccessorMissing);
  }

  FaceWalkResult result;
  result.orbitByDart.assign(dartCount, std::numeric_limits<std::size_t>::max());
  for (std::size_t start = 0U; start < dartCount; ++start) {
    if (result.orbitByDart[start] != std::numeric_limits<std::size_t>::max()) {
      continue;
    }
    std::vector<GlobalTopologyOrientedArc> boundary;
    std::size_t current = start;
    for (std::size_t steps = 0U; steps <= dartCount; ++steps) {
      if (current >= dartCount) {
        return rotation_error(RotationSystemInconsistencyReason::FaceWalkCurrentDartOutOfRange);
      }
      if (result.orbitByDart[current] !=
          std::numeric_limits<std::size_t>::max()) {
        if (current != start) {
          GlobalTopologyPlanError failure =
              rotation_error(RotationSystemInconsistencyReason::FaceWalkOrbitReenteredAtDifferentStart);
          failure.arc = oriented_arc_from_dart(current, arcs.size()).arc;
          return failure;
        }
        break;
      }
      result.orbitByDart[current] = result.orbits.size();
      boundary.push_back(oriented_arc_from_dart(current, arcs.size()));
      current = successor[current];
      if (current == start) break;
      if (steps == dartCount) {
        return rotation_error(RotationSystemInconsistencyReason::FaceWalkCycleDidNotCloseWithinDartBudget);
      }
    }
    if (boundary.empty()) {
      return rotation_error(RotationSystemInconsistencyReason::FaceWalkBoundaryEmpty);
    }
    canonicalize_cycle(boundary);
    result.orbits.push_back(std::move(boundary));
  }
  return result;
}



EmbeddedGraphTopologyBuildResult build_embedded_graph_topology(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges) {
  const auto sourceTopology =
      build_source_index(sourceFaces, sourceVertexCount, sourceAuthority);
  if (!sourceTopology.has_value()) {
    return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
  }

  const auto cutNodeBuild = build_cut_node_bindings(network, cutEdges);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&cutNodeBuild)) {
    return *failure;
  }
  const auto cutNodes = std::get<CutNodeBindings>(cutNodeBuild);

  const auto arcBuild = build_arcs(network, cutEdges, cutNodes);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&arcBuild)) {
    return *failure;
  }
  const auto arcs = std::get<std::vector<GlobalTopologyArc>>(arcBuild);

  const auto rotationBuild =
      build_rotation_system(*sourceTopology, network, cutNodes, arcs);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&rotationBuild)) {
    return *failure;
  }
  const auto rotations =
      std::get<std::vector<GlobalTopologyNodeRotation>>(rotationBuild);

  const auto faceWalkBuild = walk_graph_faces(arcs, rotations);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&faceWalkBuild)) {
    return *failure;
  }

  return EmbeddedGraphTopology{*sourceTopology, cutNodes, arcs, rotations,
                               std::get<FaceWalkResult>(faceWalkBuild)};
}

ExteriorOrbitBuildResult exterior_boundary_orbits(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk) {
  std::set<std::size_t> exterior;
  for (const auto &mandatory : network.mandatory_edges()) {
    if (mandatory.kind != SurfaceCellRailKind::Boundary) continue;
    std::vector<const GlobalTopologyArc *> matching;
    for (const auto &arc : arcs) {
      if (arc.kind == GlobalTopologyArcKind::Mandatory &&
          arc.mandatoryEdge == mandatory.id) matching.push_back(&arc);
    }
    if (matching.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
      failure.networkEdge = mandatory.id;
      failure.sourceEdge = mandatory.sourceEdge;
      return failure;
    }
    const auto incident = topology.incidentFaces.find(mandatory.sourceEdge);
    if (incident == topology.incidentFaces.end() || incident->second.size() != 1U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.sourceEdge = mandatory.sourceEdge;
      return failure;
    }
    const auto face = topology.faces.find(incident->second.front());
    if (face == topology.faces.end())
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    const bool forward = face_orients_edge_forward(face->second, mandatory.sourceEdge);
    for (const auto *arc : matching) {
      const std::size_t interiorDart = 2U * arc->id.index() + (forward ? 0U : 1U);
      const std::size_t exteriorDart = interiorDart ^ 1U;
      if (exteriorDart >= walk.orbitByDart.size()) {
        GlobalTopologyPlanError failure =
            rotation_error(RotationSystemInconsistencyReason::ExteriorBoundaryDartOutOfRange);
        failure.arc = arc->id;
        return failure;
      }
      exterior.insert(walk.orbitByDart[exteriorDart]);
    }
  }
  return exterior;
}

std::optional<std::size_t>
actual_complement_component_count(const EmbeddedGraphTopology &topology) {
  using Point = authority::ExactSourcePoint;
  using Rational = authority::FieldExactRational;
  using SourceEdge = authority::SourceEdgeTopologyKey;
  using SourceFace = authority::SourceFaceTopologyKey;

  struct Interval {
    Rational low;
    Rational high;
  };
  struct SeamKey {
    SourceEdge edge;
    Rational low;
    Rational high;
    auto operator<=>(const SeamKey &) const = default;
  };
  struct FacePiece {
    Point first;
    Point second;
  };
  struct LocalPoint {
    Point key;
    Rational x;
    Rational y;
  };
  struct LocalEdge {
    std::size_t first = 0U;
    std::size_t second = 0U;
    std::optional<SeamKey> seam;
  };

  const Rational zero = Rational::from_integer(0);
  const Rational one = Rational::from_integer(1);

  const auto edge_parameter = [&](const SourceEdge &edge,
                                  const Point &point)
      -> std::optional<Rational> {
    if (const auto *vertex = std::get_if<authority::SourceVertexId>(&point)) {
      if (*vertex == edge.first()) return zero;
      if (*vertex == edge.second()) return one;
      return std::nullopt;
    }
    const auto *edgePoint = std::get_if<authority::ExactSourceEdgePoint>(&point);
    if (edgePoint == nullptr || edgePoint->edge != edge) return std::nullopt;
    return edgePoint->parameter;
  };

  std::map<SourceEdge, std::set<Point>> edgePoints;
  std::map<SourceEdge, std::vector<Interval>> barrierIntervals;
  std::map<SourceFace, std::vector<FacePiece>> facePieces;
  for (const auto &[edge, incident] : topology.sourceTopology.incidentFaces) {
    (void)incident;
    edgePoints[edge].insert(Point{edge.first()});
    edgePoints[edge].insert(Point{edge.second()});
  }

  const auto record_edge_point = [&](const Point &point) {
    if (const auto *edgePoint =
            std::get_if<authority::ExactSourceEdgePoint>(&point)) {
      const auto found = edgePoints.find(edgePoint->edge);
      if (found != edgePoints.end()) found->second.insert(point);
    }
  };

  for (const auto &arc : topology.arcs) {
    for (const auto &piece : arc.sourcePath) {
      record_edge_point(piece.first);
      record_edge_point(piece.second);
      if (const auto *edgeSupport =
              std::get_if<authority::SourceEdgeSupport>(&piece.carrier)) {
        const auto first = edge_parameter(edgeSupport->edge, piece.first);
        const auto second = edge_parameter(edgeSupport->edge, piece.second);
        if (!first.has_value() || !second.has_value() || *first == *second) {
          return std::nullopt;
        }
        const Rational low = *first < *second ? *first : *second;
        const Rational high = *first < *second ? *second : *first;
        barrierIntervals[edgeSupport->edge].push_back(Interval{low, high});
        continue;
      }
      if (const auto *faceSupport =
              std::get_if<authority::SourceFaceInteriorSupport>(&piece.carrier)) {
        if (topology.sourceTopology.faces.count(faceSupport->face) == 0U) {
          return std::nullopt;
        }
        facePieces[faceSupport->face].push_back(
            FacePiece{piece.first, piece.second});
        continue;
      }
      return std::nullopt;
    }
  }

  const auto interval_is_barrier = [&](const SeamKey &seam) {
    const auto found = barrierIntervals.find(seam.edge);
    if (found == barrierIntervals.end()) return false;
    return std::any_of(found->second.begin(), found->second.end(),
                       [&](const Interval &interval) {
                         return interval.low <= seam.low &&
                                interval.high >= seam.high;
                       });
  };

  std::map<SeamKey, std::vector<std::size_t>> seamFragments;
  std::set<SeamKey> barrierSeams;
  std::size_t nextFragment = 0U;

  for (const auto &[faceKey, face] : topology.sourceTopology.faces) {
    const auto face_coordinates = [&](const Point &point)
        -> std::optional<std::pair<Rational, Rational>> {
      std::array<Rational, 3> barycentric{zero, zero, zero};
      if (const auto *vertex =
              std::get_if<authority::SourceVertexId>(&point)) {
        const auto found = std::find(face.vertices.begin(), face.vertices.end(),
                                     *vertex);
        if (found == face.vertices.end()) return std::nullopt;
        barycentric[static_cast<std::size_t>(
            std::distance(face.vertices.begin(), found))] = one;
      } else if (const auto *edgePoint =
                     std::get_if<authority::ExactSourceEdgePoint>(&point)) {
        if (!authority::source_face_contains_edge(face.topology,
                                                  edgePoint->edge)) {
          return std::nullopt;
        }
        const auto first =
            std::find(face.vertices.begin(), face.vertices.end(),
                      edgePoint->edge.first());
        const auto second =
            std::find(face.vertices.begin(), face.vertices.end(),
                      edgePoint->edge.second());
        if (first == face.vertices.end() || second == face.vertices.end()) {
          return std::nullopt;
        }
        barycentric[static_cast<std::size_t>(
            std::distance(face.vertices.begin(), first))] =
            one - edgePoint->parameter;
        barycentric[static_cast<std::size_t>(
            std::distance(face.vertices.begin(), second))] =
            edgePoint->parameter;
      } else {
        const auto &facePoint = std::get<authority::ExactSourceFacePoint>(point);
        if (facePoint.face != face.topology) return std::nullopt;
        const auto canonicalVertices = facePoint.face.vertices();
        std::array<bool, 3> assigned{false, false, false};
        for (std::size_t canonical = 0U; canonical < 3U; ++canonical) {
          const auto oriented =
              std::find(face.vertices.begin(), face.vertices.end(),
                        canonicalVertices[canonical]);
          if (oriented == face.vertices.end()) return std::nullopt;
          const std::size_t index = static_cast<std::size_t>(
              std::distance(face.vertices.begin(), oriented));
          if (assigned[index]) return std::nullopt;
          assigned[index] = true;
          barycentric[index] = facePoint.barycentric[canonical];
        }
      }
      if (barycentric[0] + barycentric[1] + barycentric[2] != one) {
        return std::nullopt;
      }
      return std::pair<Rational, Rational>{barycentric[1], barycentric[2]};
    };

    std::map<Point, std::size_t> pointIndex;
    std::vector<LocalPoint> points;
    const auto add_point = [&](const Point &point) -> std::optional<std::size_t> {
      const auto existing = pointIndex.find(point);
      if (existing != pointIndex.end()) return existing->second;
      const auto coordinates = face_coordinates(point);
      if (!coordinates.has_value()) return std::nullopt;
      const std::size_t index = points.size();
      pointIndex.emplace(point, index);
      points.push_back(LocalPoint{point, coordinates->first, coordinates->second});
      return index;
    };

    for (const auto vertex : face.vertices) {
      if (!add_point(Point{vertex}).has_value()) return std::nullopt;
    }
    for (const auto &edge : face.edges) {
      const auto found = edgePoints.find(edge);
      if (found == edgePoints.end()) return std::nullopt;
      for (const auto &point : found->second) {
        if (!add_point(point).has_value()) return std::nullopt;
      }
    }
    const auto pieces = facePieces.find(faceKey);
    if (pieces != facePieces.end()) {
      for (const auto &piece : pieces->second) {
        if (!add_point(piece.first).has_value() ||
            !add_point(piece.second).has_value()) {
          return std::nullopt;
        }
      }
    }

    std::vector<LocalEdge> edges;
    std::set<std::pair<std::size_t, std::size_t>> edgeSet;
    const auto add_edge = [&](std::size_t first, std::size_t second,
                              std::optional<SeamKey> seam)
        -> std::optional<std::size_t> {
      if (first == second) return std::nullopt;
      const auto key = std::minmax(first, second);
      const std::pair<std::size_t, std::size_t> ordered{key.first, key.second};
      if (!edgeSet.insert(ordered).second) return std::nullopt;
      const std::size_t index = edges.size();
      edges.push_back(LocalEdge{first, second, std::move(seam)});
      return index;
    };

    if (pieces != facePieces.end()) {
      for (const auto &piece : pieces->second) {
        const auto first = pointIndex.find(piece.first);
        const auto second = pointIndex.find(piece.second);
        if (first == pointIndex.end() || second == pointIndex.end() ||
            !add_edge(first->second, second->second, std::nullopt).has_value()) {
          return std::nullopt;
        }
      }
    }

    for (const auto &edge : face.edges) {
      const auto found = edgePoints.find(edge);
      if (found == edgePoints.end()) return std::nullopt;
      std::vector<std::pair<Rational, Point>> ordered;
      ordered.reserve(found->second.size());
      for (const auto &point : found->second) {
        const auto parameter = edge_parameter(edge, point);
        if (!parameter.has_value()) return std::nullopt;
        ordered.push_back({*parameter, point});
      }
      std::sort(ordered.begin(), ordered.end(),
                [](const auto &lhs, const auto &rhs) {
                  return lhs.first < rhs.first;
                });
      for (std::size_t index = 1U; index < ordered.size(); ++index) {
        if (ordered[index - 1U].first >= ordered[index].first) {
          return std::nullopt;
        }
        const SeamKey seam{edge, ordered[index - 1U].first,
                           ordered[index].first};
        const auto first = pointIndex.find(ordered[index - 1U].second);
        const auto second = pointIndex.find(ordered[index].second);
        if (first == pointIndex.end() || second == pointIndex.end() ||
            !add_edge(first->second, second->second, seam).has_value()) {
          return std::nullopt;
        }
      }
    }

    const auto cross = [&](const std::size_t first, const std::size_t second,
                           const std::size_t third) {
      const Rational ax = points[second].x - points[first].x;
      const Rational ay = points[second].y - points[first].y;
      const Rational bx = points[third].x - points[first].x;
      const Rational by = points[third].y - points[first].y;
      return ax * by - ay * bx;
    };
    for (std::size_t firstEdge = 0U; firstEdge < edges.size(); ++firstEdge) {
      for (std::size_t secondEdge = firstEdge + 1U; secondEdge < edges.size();
           ++secondEdge) {
        const auto &first = edges[firstEdge];
        const auto &second = edges[secondEdge];
        if (first.first == second.first || first.first == second.second ||
            first.second == second.first || first.second == second.second) {
          continue;
        }
        const Rational o1 = cross(first.first, first.second, second.first);
        const Rational o2 = cross(first.first, first.second, second.second);
        const Rational o3 = cross(second.first, second.second, first.first);
        const Rational o4 = cross(second.first, second.second, first.second);
        const auto sign = [&](const Rational &value) {
          return value < zero ? -1 : value > zero ? 1 : 0;
        };
        const int s1 = sign(o1), s2 = sign(o2), s3 = sign(o3), s4 = sign(o4);
        const auto on_segment = [&](const std::size_t firstVertex,
                                    const std::size_t secondVertex,
                                    const std::size_t pointVertex) {
          const auto &a = points[firstVertex];
          const auto &b = points[secondVertex];
          const auto &point = points[pointVertex];
          const Rational minX = a.x < b.x ? a.x : b.x;
          const Rational maxX = a.x < b.x ? b.x : a.x;
          const Rational minY = a.y < b.y ? a.y : b.y;
          const Rational maxY = a.y < b.y ? b.y : a.y;
          return point.x >= minX && point.x <= maxX &&
                 point.y >= minY && point.y <= maxY;
        };
        const bool intersects =
            (s1 != 0 && s2 != 0 && s3 != 0 && s4 != 0 && s1 != s2 &&
             s3 != s4) ||
            (s1 == 0 && on_segment(first.first, first.second, second.first)) ||
            (s2 == 0 && on_segment(first.first, first.second, second.second)) ||
            (s3 == 0 && on_segment(second.first, second.second, first.first)) ||
            (s4 == 0 && on_segment(second.first, second.second, first.second));
        if (intersects) return std::nullopt;
      }
    }

    const std::size_t dartCount = edges.size() * 2U;
    std::vector<std::vector<std::size_t>> outgoing(points.size());
    const auto dart_from = [&](const std::size_t dart) {
      const auto &edge = edges[dart / 2U];
      return (dart & 1U) == 0U ? edge.first : edge.second;
    };
    const auto dart_to = [&](const std::size_t dart) {
      const auto &edge = edges[dart / 2U];
      return (dart & 1U) == 0U ? edge.second : edge.first;
    };
    for (std::size_t dart = 0U; dart < dartCount; ++dart) {
      outgoing[dart_from(dart)].push_back(dart);
    }
    const auto upper_half = [&](const Rational &dx, const Rational &dy) {
      return dy > zero || (dy == zero && dx > zero);
    };
    for (std::size_t vertex = 0U; vertex < outgoing.size(); ++vertex) {
      auto &rotation = outgoing[vertex];
      if (rotation.empty()) return std::nullopt;
      for (std::size_t first = 0U; first < rotation.size(); ++first) {
        const auto firstTo = dart_to(rotation[first]);
        const Rational ax = points[firstTo].x - points[vertex].x;
        const Rational ay = points[firstTo].y - points[vertex].y;
        for (std::size_t second = first + 1U; second < rotation.size(); ++second) {
          const auto secondTo = dart_to(rotation[second]);
          const Rational bx = points[secondTo].x - points[vertex].x;
          const Rational by = points[secondTo].y - points[vertex].y;
          if (upper_half(ax, ay) == upper_half(bx, by) &&
              ax * by - ay * bx == zero) {
            return std::nullopt;
          }
        }
      }
      std::sort(rotation.begin(), rotation.end(), [&](const std::size_t lhs,
                                                      const std::size_t rhs) {
        const auto lhsTo = dart_to(lhs);
        const auto rhsTo = dart_to(rhs);
        const Rational lx = points[lhsTo].x - points[vertex].x;
        const Rational ly = points[lhsTo].y - points[vertex].y;
        const Rational rx = points[rhsTo].x - points[vertex].x;
        const Rational ry = points[rhsTo].y - points[vertex].y;
        const bool lhsUpper = upper_half(lx, ly);
        const bool rhsUpper = upper_half(rx, ry);
        if (lhsUpper != rhsUpper) return lhsUpper;
        return lx * ry - ly * rx > zero;
      });
    }

    std::vector<std::size_t> successor(dartCount, dartCount);
    for (std::size_t dart = 0U; dart < dartCount; ++dart) {
      const std::size_t target = dart_to(dart);
      const std::size_t reverse = dart ^ 1U;
      const auto &rotation = outgoing[target];
      const auto found = std::find(rotation.begin(), rotation.end(), reverse);
      if (found == rotation.end()) return std::nullopt;
      const std::size_t offset =
          static_cast<std::size_t>(std::distance(rotation.begin(), found));
      successor[dart] = rotation[offset == 0U ? rotation.size() - 1U
                                              : offset - 1U];
    }

    std::vector<std::size_t> orbitByDart(dartCount, dartCount);
    std::vector<Rational> orbitArea2;
    for (std::size_t start = 0U; start < dartCount; ++start) {
      if (orbitByDart[start] != dartCount) continue;
      const std::size_t orbit = orbitArea2.size();
      Rational area2 = zero;
      std::size_t current = start;
      for (std::size_t steps = 0U; steps <= dartCount; ++steps) {
        if (orbitByDart[current] != dartCount) {
          if (current != start) return std::nullopt;
          break;
        }
        orbitByDart[current] = orbit;
        const auto first = dart_from(current);
        const auto second = dart_to(current);
        area2 = area2 + points[first].x * points[second].y -
                          points[first].y * points[second].x;
        current = successor[current];
        if (current == start) break;
        if (steps == dartCount) return std::nullopt;
      }
      if (area2 == zero) return std::nullopt;
      orbitArea2.push_back(area2);
    }

    std::map<std::size_t, std::size_t> fragmentByOrbit;
    for (std::size_t orbit = 0U; orbit < orbitArea2.size(); ++orbit) {
      if (orbitArea2[orbit] > zero) {
        fragmentByOrbit.emplace(orbit, nextFragment++);
      }
    }
    if (fragmentByOrbit.empty()) return std::nullopt;

    for (std::size_t edgeIndex = 0U; edgeIndex < edges.size(); ++edgeIndex) {
      const auto &edge = edges[edgeIndex];
      if (!edge.seam.has_value()) continue;
      const std::size_t forwardOrbit = orbitByDart[2U * edgeIndex];
      const std::size_t reverseOrbit = orbitByDart[2U * edgeIndex + 1U];
      const auto forward = fragmentByOrbit.find(forwardOrbit);
      const auto reverse = fragmentByOrbit.find(reverseOrbit);
      if ((forward == fragmentByOrbit.end()) ==
          (reverse == fragmentByOrbit.end())) {
        return std::nullopt;
      }
      const std::size_t fragment =
          forward != fragmentByOrbit.end() ? forward->second : reverse->second;
      seamFragments[*edge.seam].push_back(fragment);
      if (interval_is_barrier(*edge.seam)) barrierSeams.insert(*edge.seam);
    }
  }

  if (nextFragment == 0U) return std::nullopt;
  std::vector<std::size_t> parent(nextFragment);
  std::iota(parent.begin(), parent.end(), 0U);
  const auto root = [&](const auto &self, std::size_t value) -> std::size_t {
    return parent[value] == value ? value : self(self, parent[value]);
  };
  const auto unite = [&](std::size_t first, std::size_t second) {
    first = root(root, first);
    second = root(root, second);
    if (first == second) return;
    if (first < second) parent[second] = first;
    else parent[first] = second;
  };

  for (const auto &[seam, fragments] : seamFragments) {
    const auto incident = topology.sourceTopology.incidentFaces.find(seam.edge);
    if (incident == topology.sourceTopology.incidentFaces.end()) {
      return std::nullopt;
    }
    if (incident->second.size() == 1U) {
      if (fragments.size() != 1U) return std::nullopt;
      continue;
    }
    if (incident->second.size() != 2U || fragments.size() != 2U) {
      return std::nullopt;
    }
    if (barrierSeams.count(seam) == 0U) unite(fragments[0], fragments[1]);
  }

  std::set<std::size_t> roots;
  for (std::size_t fragment = 0U; fragment < nextFragment; ++fragment) {
    roots.insert(root(root, fragment));
  }
  return roots.size();
}

std::optional<FixedCandidateTopologyInvariant>
fixed_candidate_topology_invariant(const EmbeddedGraphTopology &topology) {
  const auto observed = actual_complement_component_count(topology);
  if (!observed.has_value()) return std::nullopt;

  std::set<authority::SourceVertexId> sourceVertices;
  std::set<authority::SourceComponentId> sourceComponents;
  for (const auto &[faceKey, face] : topology.sourceTopology.faces) {
    (void)faceKey;
    sourceVertices.insert(face.vertices.begin(), face.vertices.end());
    sourceComponents.insert(face.component);
  }
  const std::size_t graphComponents = actual_graph_component_count(topology);
  if (graphComponents < sourceComponents.size()) return std::nullopt;

  const std::int64_t vertexCount =
      static_cast<std::int64_t>(topology.cutNodes.combinedNodeExtent);
  const std::int64_t edgeCount =
      static_cast<std::int64_t>(topology.arcs.size());
  const std::int64_t componentCount =
      static_cast<std::int64_t>(graphComponents);
  const std::int64_t sourceComponentCount =
      static_cast<std::int64_t>(sourceComponents.size());
  const std::int64_t firstBetti = edgeCount - vertexCount + componentCount;
  if (firstBetti < 0) return std::nullopt;
  const int sourceEuler =
      static_cast<int>(sourceVertices.size()) -
      static_cast<int>(topology.sourceTopology.incidentFaces.size()) +
      static_cast<int>(topology.sourceTopology.faces.size());
  const std::int64_t requiredFaceCount =
      static_cast<std::int64_t>(sourceEuler) - sourceComponentCount + firstBetti;
  if (requiredFaceCount < 0) return std::nullopt;

  FixedCandidateTopologyInvariant result;
  result.vertexCount = topology.cutNodes.combinedNodeExtent;
  result.edgeCount = topology.arcs.size();
  result.observedComplementComponentCount = *observed;
  result.graphComponentCount = graphComponents;
  result.sourceComponentCount = sourceComponents.size();
  result.firstBetti = firstBetti;
  result.requiredFaceCount = requiredFaceCount;
  result.sourceEulerCharacteristic = sourceEuler;
  result.rejects = static_cast<std::int64_t>(*observed) != requiredFaceCount;
  return result;
}

std::size_t actual_graph_component_count(const EmbeddedGraphTopology &topology) {
  const std::size_t count = topology.cutNodes.combinedNodeExtent;
  if (count == 0U) return 0U;
  std::vector<std::size_t> parent(count);
  std::iota(parent.begin(), parent.end(), 0U);
  const auto root = [&](const auto &self, std::size_t value) -> std::size_t {
    return parent[value] == value ? value : self(self, parent[value]);
  };
  const auto unite = [&](std::size_t first, std::size_t second) {
    first = root(root, first);
    second = root(root, second);
    if (first == second) return;
    if (first < second) parent[second] = first;
    else parent[first] = second;
  };
  for (const auto &arc : topology.arcs)
    unite(arc.firstNode.index(), arc.secondNode.index());
  std::set<std::size_t> roots;
  for (std::size_t node = 0; node < count; ++node)
    roots.insert(root(root, node));
  return roots.size();
}

std::optional<std::size_t> source_boundary_loop_count(
    const SourceTopologyIndex &topology) {
  std::map<authority::SourceVertexId, std::vector<authority::SourceVertexId>> adjacency;
  std::size_t boundaryEdgeCount = 0U;
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size() != 1U) continue;
    ++boundaryEdgeCount;
    adjacency[edge.first()].push_back(edge.second());
    adjacency[edge.second()].push_back(edge.first());
  }
  if (boundaryEdgeCount == 0U) return 0U;
  for (auto &[vertex, adjacent] : adjacency) {
    (void)vertex;
    std::sort(adjacent.begin(), adjacent.end());
    adjacent.erase(std::unique(adjacent.begin(), adjacent.end()), adjacent.end());
    if (adjacent.size() != 2U) return std::nullopt;
  }
  std::set<authority::SourceVertexId> visited;
  std::size_t loops = 0U;
  for (const auto &[seed, adjacent] : adjacency) {
    (void)adjacent;
    if (visited.count(seed) != 0U) continue;
    ++loops;
    std::vector<authority::SourceVertexId> stack{seed};
    while (!stack.empty()) {
      auto current = stack.back(); stack.pop_back();
      if (!visited.insert(current).second) continue;
      for (auto next : adjacency.at(current))
        if (visited.count(next) == 0U) stack.push_back(next);
    }
  }
  return loops;
}

} // namespace directional::geometry::embedded_graph_topology_detail
