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

std::optional<std::size_t> trace_event_position(
    const FieldAlignedCandidateTrace &trace,
    const FieldAlignedNetworkEvent &event,
    const FieldAlignedTraceEventRole role,
    const authority::NetworkNodeId originNode) {
  if (event.node == originNode && !event.sourceEdge.has_value()) return 0U;
  if (!event.sourceEdge.has_value()) {
    return role == FieldAlignedTraceEventRole::Terminal
               ? std::optional<std::size_t>{trace.segments.size()}
               : std::nullopt;
  }

  std::set<std::size_t> positions;
  const auto consider = [&](const std::size_t index,
                            const bool requireFace) {
    const auto &segment = trace.segments[index];
    if (requireFace && segment.sourceFace != event.sourceFace) return;
    if (segment.incomingCarrier.has_value() &&
        *segment.incomingCarrier == *event.sourceEdge) {
      positions.insert(index);
    }
    if (segment.outgoingCarrier == *event.sourceEdge) {
      positions.insert(index + 1U);
    }
  };
  for (std::size_t index = 0U; index < trace.segments.size(); ++index) {
    consider(index, true);
  }
  if (positions.empty()) {
    for (std::size_t index = 0U; index < trace.segments.size(); ++index) {
      consider(index, false);
    }
  }
  if (positions.size() != 1U) return std::nullopt;
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
  for (const auto &edge : cutEdges) {
    cutVertices.insert(edge.first());
    cutVertices.insert(edge.second());
  }
  std::size_t nextIndex = network.nodes().size();
  const std::size_t extent = network.nodes().size() +
      static_cast<std::size_t>(std::count_if(
          cutVertices.begin(), cutVertices.end(), [&](const auto vertex) {
            return result.nodeByVertex.count(vertex) == 0U;
          }));
  for (const auto vertex : cutVertices) {
    if (result.nodeByVertex.count(vertex) != 0U) continue;
    const auto id = authority::NetworkNodeId::from_index(
        static_cast<std::int64_t>(nextIndex++), extent);
    if (!id) return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
    result.nodeByVertex.emplace(vertex, id.value());
    result.syntheticVertices.emplace(id.value(), vertex);
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
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceVertex = trace.sourceVertex;
      return result;
    }

    std::map<std::size_t, authority::NetworkNodeId> cuts;
    cuts.emplace(0U, origin->second);
    bool hasTerminal = false;
    for (const auto &event : network.events()) {
      for (const auto &incidence : event.incidences) {
        if (incidence.trace != trace.id) continue;
        const auto position =
            trace_event_position(trace, event, incidence.role, origin->second);
        if (!position.has_value() || *position > trace.segments.size()) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceFace = event.sourceFace;
          result.sourceEdge = event.sourceEdge;
          return result;
        }
        const auto inserted = cuts.emplace(*position, event.node);
        if (!inserted.second && inserted.first->second != event.node) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceFace = event.sourceFace;
          result.sourceEdge = event.sourceEdge;
          return result;
        }
        hasTerminal = hasTerminal ||
                      incidence.role == FieldAlignedTraceEventRole::Terminal;
      }
    }
    if (!hasTerminal || cuts.rbegin()->first != trace.segments.size()) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
    ArcDraft draft(first->second, second->second);
    draft.kind = GlobalTopologyArcKind::Cut;
    draft.cutEdge = cutEdge;
    drafts.push_back(std::move(draft));
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

  const auto set_vertex = [&](const authority::NetworkNodeId node,
                              const authority::SourceVertexId vertex)
      -> std::optional<GlobalTopologyPlanError> {
    auto found = loci.find(node);
    if (found == loci.end()) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceVertex = vertex;
      return result;
    }
    if (found->second.vertex.has_value() && *found->second.vertex != vertex) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
      return result;
    }
    if (found->second.vertex.has_value()) continue;
    if (!event.sourceEdge.has_value()) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceFace = event.sourceFace;
      return result;
    }
    if (found->second.edge.has_value() &&
        *found->second.edge != *event.sourceEdge) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      result.sourceFace = event.sourceFace;
      result.sourceEdge = event.sourceEdge;
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

std::optional<bool> mandatory_ray_points_to_second_endpoint(
    const GlobalTopologyArc &arc, const authority::Orientation orientation,
    const FieldAlignedMandatoryEdge &mandatory) {
  const authority::NetworkNodeId destination =
      orientation == authority::Orientation::Forward ? arc.secondNode
                                                     : arc.firstNode;
  if (destination == mandatory.secondNode) return true;
  if (destination == mandatory.firstNode) return false;
  return std::nullopt;
}

std::optional<std::size_t> edge_locus_secondary_rank(
    const SourceTopologyIndex &topology,
    const authority::SourceEdgeTopologyKey &locus,
    const GlobalTopologyArc &arc, const authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace) {
  const auto faceKey = trace_ray_face(arc, orientation, trace);
  if (!faceKey.has_value()) return std::nullopt;
  const auto faceIt = topology.faces.find(*faceKey);
  if (faceIt == topology.faces.end()) return std::nullopt;
  const auto contactIndex = local_edge_index(faceIt->second, locus);
  if (!contactIndex.has_value()) return std::nullopt;

  const auto &segment = orientation == authority::Orientation::Forward
                            ? trace.segments[arc.firstSegment]
                            : trace.segments[arc.onePastLastSegment - 1U];
  std::optional<authority::SourceEdgeTopologyKey> other;
  if (orientation == authority::Orientation::Forward) {
    if (segment.incomingCarrier.has_value() &&
        *segment.incomingCarrier == locus) {
      other = segment.outgoingCarrier;
    }
  } else if (segment.outgoingCarrier == locus) {
    other = segment.incomingCarrier;
  }
  if (other.has_value()) {
    const auto otherIndex = local_edge_index(faceIt->second, *other);
    if (!otherIndex.has_value() || *otherIndex == *contactIndex) {
      return std::nullopt;
    }
    return 2U * ((*otherIndex + 3U - *contactIndex) % 3U);
  }

  // A first/last segment can connect the contact carrier directly to its
  // singularity source vertex. Keep that exact topological case between the
  // two carrier destinations without using geometry.
  for (std::size_t corner = 0U; corner < 3U; ++corner) {
    if (faceIt->second.vertices[corner] == trace.sourceVertex) {
      return 1U + 2U * corner;
    }
  }
  return std::nullopt;
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
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      return result;
    }
    const auto locusIt = loci.find(node);
    if (locusIt == loci.end()) {
      return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
    }

    std::vector<std::pair<RayOrderKey, GlobalTopologyOrientedArc>> keyed;
    keyed.reserve(outgoing.size());
    if (locusIt->second.vertex.has_value()) {
      const auto slots =
          build_vertex_fan_slots(topology, *locusIt->second.vertex);
      if (!slots.has_value()) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        result.sourceVertex = locusIt->second.vertex;
        return result;
      }
      for (const auto incidence : outgoing) {
        const auto arcIt = arcById.find(incidence.arc);
        if (arcIt == arcById.end()) {
          return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
              return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            }
            const auto *mandatory = find_mandatory(network, *arc.mandatoryEdge);
            if (mandatory == nullptr) {
              return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceVertex = locusIt->second.vertex;
            result.sourceEdge = *sourceEdge;
            return result;
          }
          key.primary = 2U * slot->second;
        } else {
          if (!arc.trace.has_value()) {
            return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          }
          const auto *trace = find_trace(network, *arc.trace);
          if (trace == nullptr) {
            return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          }
          const auto face = trace_ray_face(arc, incidence.orientation, *trace);
          if (!face.has_value()) {
            return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          }
          const auto slot = slots->faceSlots.find(*face);
          if (slot == slots->faceSlots.end()) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceVertex = locusIt->second.vertex;
            result.sourceFace = face;
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
            return result;
          }
          key.secondary = static_cast<std::size_t>(port->ordinal);
        }
        keyed.emplace_back(key, incidence);
      }
    } else if (locusIt->second.edge.has_value()) {
      const auto incidentFaces = topology.incidentFaces.find(*locusIt->second.edge);
      if (incidentFaces == topology.incidentFaces.end() ||
          incidentFaces->second.empty()) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        result.sourceEdge = locusIt->second.edge;
        return result;
      }
      std::map<authority::SourceFaceTopologyKey, std::size_t> sideRank;
      for (const auto &faceKey : incidentFaces->second) {
        const auto face = topology.faces.find(faceKey);
        if (face == topology.faces.end()) {
          return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        }
        sideRank.emplace(
            faceKey,
            face_orients_edge_forward(face->second, *locusIt->second.edge)
                ? 0U
                : 1U);
      }

      const std::size_t mandatoryRayCount = static_cast<std::size_t>(
          std::count_if(outgoing.begin(), outgoing.end(), [&](const auto incidence) {
            const auto arcIt = arcById.find(incidence.arc);
            return arcIt != arcById.end() &&
                   arcIt->second->kind == GlobalTopologyArcKind::Mandatory;
          }));
      if (mandatoryRayCount != 0U &&
          (mandatoryRayCount != 2U || outgoing.size() != 3U)) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        result.sourceEdge = locusIt->second.edge;
        return result;
      }

      for (const auto incidence : outgoing) {
        const auto arcIt = arcById.find(incidence.arc);
        if (arcIt == arcById.end()) {
          return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        }
        const GlobalTopologyArc &arc = *arcIt->second;
        RayOrderKey key(arc.id);
        key.kind = arc.kind;
        key.trace = arc.trace;
        key.arc = arc.id;
        key.orientation = incidence.orientation;

        if (arc.kind == GlobalTopologyArcKind::Mandatory) {
          if (mandatoryRayCount != 2U || !arc.mandatoryEdge.has_value()) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceEdge = locusIt->second.edge;
            return result;
          }
          const auto *mandatory = find_mandatory(network, *arc.mandatoryEdge);
          if (mandatory == nullptr ||
              mandatory->sourceEdge != *locusIt->second.edge) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceEdge = locusIt->second.edge;
            return result;
          }
          const auto towardSecond = mandatory_ray_points_to_second_endpoint(
              arc, incidence.orientation, *mandatory);
          if (!towardSecond.has_value()) {
            GlobalTopologyPlanError result =
                error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
            result.sourceEdge = locusIt->second.edge;
            result.networkEdge = mandatory->id;
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
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceEdge = locusIt->second.edge;
          return result;
        }
        const auto *trace = find_trace(network, *arc.trace);
        if (trace == nullptr) {
          return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        }
        const auto face = trace_ray_face(arc, incidence.orientation, *trace);
        if (!face.has_value() || sideRank.count(*face) == 0U) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceEdge = locusIt->second.edge;
          result.sourceFace = face;
          return result;
        }
        const auto secondary = edge_locus_secondary_rank(
            topology, *locusIt->second.edge, arc, incidence.orientation,
            *trace);
        if (!secondary.has_value()) {
          GlobalTopologyPlanError result =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          result.sourceEdge = locusIt->second.edge;
          result.sourceFace = face;
          return result;
        }
        key.primary = mandatoryRayCount == 0U
                          ? sideRank.at(*face)
                          : 2U * sideRank.at(*face) + 1U;
        key.secondary = *secondary;
        keyed.emplace_back(key, incidence);
      }
    } else {
      return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        result.sourceVertex = locusIt->second.vertex;
        result.sourceEdge = locusIt->second.edge;
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
    return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
  }
  const std::size_t dartCount = 2U * arcs.size();
  std::vector<std::size_t> successor(dartCount,
                                     std::numeric_limits<std::size_t>::max());
  std::vector<std::size_t> incidenceCount(dartCount, 0U);
  for (const auto &rotation : rotations) {
    const std::size_t count = rotation.counterClockwise.size();
    if (count == 0U) {
      GlobalTopologyPlanError result =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      return result;
    }
    for (std::size_t index = 0U; index < count; ++index) {
      const auto reverseIncidence = rotation.counterClockwise[index];
      const std::size_t reverseDart = dart_index(reverseIncidence);
      if (reverseDart >= dartCount) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        result.region.reset();
        result.arc = reverseIncidence.arc;
        return result;
      }
      ++incidenceCount[reverseDart];
      const auto next = rotation.counterClockwise[(index + count - 1U) % count];
      const std::size_t incomingDart = dart_index(reversed(reverseIncidence));
      if (successor[incomingDart] != std::numeric_limits<std::size_t>::max()) {
        GlobalTopologyPlanError result =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
    return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
        return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      }
      if (result.orbitByDart[current] !=
          std::numeric_limits<std::size_t>::max()) {
        if (current != start) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
        return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      }
    }
    if (boundary.empty()) {
      return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
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
