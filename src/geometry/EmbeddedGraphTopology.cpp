// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include "EmbeddedGraphTopology.h"

#include <algorithm>
#include <array>
#include <cstdint>
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

struct TraceCut {
  std::size_t position = 0U;
  authority::NetworkNodeId node;

  auto operator<=>(const TraceCut &) const = default;
};

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
};

bool exact_interior_parameter(const authority::ExactUnitParameter &parameter) {
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  return parameter.value > zero && parameter.value < one;
}

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

ArcBuildResult build_arcs(const FieldAlignedCurveNetwork &network,
                          const std::vector<authority::SourceEdgeTopologyKey> &cutEdges,
                          const CutNodeBindings &cutNodes) {
  struct TerminalBarrierCut {
    authority::TraceId trace;
    authority::NetworkNodeId node;
  };

  std::map<authority::SourceEdgeTopologyKey, std::vector<TerminalBarrierCut>>
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
    terminalCutsByEdge[*trace.terminalBarrier].push_back(
        TerminalBarrierCut{trace.id, *terminalNode});
  }

  for (const auto &[sourceEdge, cuts] : terminalCutsByEdge) {
    if (cuts.size() < 2U) continue;
    GlobalTopologyPlanError result =
        error(GlobalTopologyPlanErrorCode::MandatoryEdgeTerminalOrderUnresolved);
    result.sourceEdge = sourceEdge;
    result.trace = cuts[0].trace;
    result.secondTrace = cuts[1].trace;
    return result;
  }

  std::vector<ArcDraft> drafts;
  drafts.reserve(network.mandatory_edges().size() + terminalCutsByEdge.size() +
                 network.candidate_traces().size() + cutEdges.size());
  std::set<authority::SourceEdgeTopologyKey> consumedTerminalEdges;
  for (const auto &edge : network.mandatory_edges()) {
    const auto cuts = terminalCutsByEdge.find(edge.sourceEdge);
    if (cuts == terminalCutsByEdge.end()) {
      ArcDraft draft(edge.firstNode, edge.secondNode);
      draft.kind = GlobalTopologyArcKind::Mandatory;
      draft.mandatoryEdge = edge.id;
      drafts.push_back(std::move(draft));
      continue;
    }

    if (cuts->second.size() != 1U) {
      return error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
    }
    const authority::NetworkNodeId terminal = cuts->second.front().node;
    if (terminal == edge.firstNode || terminal == edge.secondNode) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      result.networkEdge = edge.id;
      result.trace = cuts->second.front().trace;
      result.sourceEdge = edge.sourceEdge;
      return result;
    }
    consumedTerminalEdges.insert(edge.sourceEdge);

    ArcDraft first(edge.firstNode, terminal);
    first.kind = GlobalTopologyArcKind::Mandatory;
    first.mandatoryEdge = edge.id;
    drafts.push_back(std::move(first));

    ArcDraft second(terminal, edge.secondNode);
    second.kind = GlobalTopologyArcKind::Mandatory;
    second.mandatoryEdge = edge.id;
    drafts.push_back(std::move(second));
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

  for (const auto &trace : network.candidate_traces()) {
    const auto origin = originByPort.find(trace.port);
    if (origin == originByPort.end() || trace.segments.empty()) {
      GlobalTopologyPlanError result =
          rotation_error(origin == originByPort.end() ? RotationSystemInconsistencyReason::ArcTraceOriginPortMissing : RotationSystemInconsistencyReason::ArcTraceSegmentsEmpty);
      result.sourceVertex = trace.sourceVertex;
      return result;
    }

    std::map<std::size_t, authority::NetworkNodeId> cuts;
    cuts.emplace(0U, origin->second);
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
      const auto inserted = cuts.emplace(key.segmentPosition, crossing.node);
      if (!inserted.second && inserted.first->second != crossing.node) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
        result.trace = trace.id;
        result.sourceEdge = key.sourceEdge;
        return result;
      }
    }
    bool hasTerminal = false;
    for (std::size_t eventIndex = 0U; eventIndex < network.events().size();
         ++eventIndex) {
      const auto &event = network.events()[eventIndex];
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
        const auto inserted = cuts.emplace(*position, event.node);
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
      }
    }
    if (!hasTerminal || cuts.rbegin()->first != trace.segments.size()) {
      GlobalTopologyPlanError result =
          rotation_error(!hasTerminal ? RotationSystemInconsistencyReason::ArcTraceTerminalEventMissing : RotationSystemInconsistencyReason::ArcTraceTerminalCutPositionMismatch);
      result.sourceVertex = trace.sourceVertex;
      return result;
    }

    std::vector<TraceCut> ordered;
    ordered.reserve(cuts.size());
    for (const auto &[position, node] : cuts) {
      ordered.push_back(TraceCut{position, node});
    }
    for (std::size_t cutIndex = 0U; cutIndex + 1U < ordered.size(); ++cutIndex) {
      const TraceCut &first = ordered[cutIndex];
      const TraceCut &second = ordered[cutIndex + 1U];
      if (first.position >= second.position) continue;
      ArcDraft draft(first.node, second.node);
      draft.kind = GlobalTopologyArcKind::Trace;
      draft.trace = trace.id;
      draft.firstSegment = first.position;
      draft.onePastLastSegment = second.position;
      draft.sourceFaces.reserve(second.position - first.position);
      for (std::size_t segment = first.position; segment < second.position;
           ++segment) {
        draft.sourceFaces.push_back(trace.segments[segment].sourceFace);
      }
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
        std::move(draft.sourceFaces)});
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

  for (const auto &event : network.events()) {
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
    if (destination == mandatory->secondNode) return true;
    if (destination == mandatory->firstNode) return false;
    return std::nullopt;
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
    return trace.terminalContact->barycentric;
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
