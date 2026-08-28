// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/geometry/GlobalTopologyPlan.h>

#include "SourceFaceComponentPartition.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

namespace directional::geometry::global_topology_plan_detail {
namespace {

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void hash_consume(std::uint64_t &hash, const std::uint64_t value) noexcept {
  hash ^= value;
  hash *= kFnvPrime;
}

template <typename Id>
void hash_id(std::uint64_t &hash, const Id id) noexcept {
  hash_consume(hash, static_cast<std::uint64_t>(Id::domain()));
  hash_consume(hash, id.index());
}

void hash_edge(std::uint64_t &hash,
               const authority::SourceEdgeTopologyKey &edge) noexcept {
  hash_id(hash, edge.first());
  hash_id(hash, edge.second());
}

void hash_face(std::uint64_t &hash,
               const authority::SourceFaceTopologyKey &face) noexcept {
  for (const authority::SourceVertexId vertex : face.vertices()) {
    hash_id(hash, vertex);
  }
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

bool fragment_diagnostics_enabled() noexcept {
  const char *value = std::getenv("DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS");
  return value != nullptr && std::strcmp(value, "1") == 0;
}

std::string diagnostic_face(
    const authority::SourceFaceTopologyKey &face) {
  std::ostringstream out;
  out << '[';
  for (std::size_t index = 0U; index < face.vertices().size(); ++index) {
    if (index != 0U) out << ',';
    out << face.vertices()[index].index();
  }
  out << ']';
  return out.str();
}

std::string diagnostic_edge(
    const authority::SourceEdgeTopologyKey &edge) {
  std::ostringstream out;
  out << '(' << edge.first().index() << ',' << edge.second().index() << ')';
  return out.str();
}

template <typename Value>
std::string diagnostic_values(const std::set<Value> &values) {
  std::ostringstream out;
  out << '[';
  bool first = true;
  for (const auto value : values) {
    if (!first) out << ',';
    first = false;
    if constexpr (std::is_integral_v<Value>) {
      out << value;
    } else {
      out << value.index();
    }
  }
  out << ']';
  return out.str();
}

struct FragmentDiagnosticTraceSegment {
  authority::TraceId trace;
  authority::NetworkArcId arc;
  std::size_t segment = 0U;
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  authority::SourceFaceTopologyKey sourceFace;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  authority::SourceEdgeTopologyKey outgoingCarrier;
  std::optional<authority::SourceVertexId> sourcePortVertex;
};

struct FragmentDiagnosticEvidence {
  std::set<std::size_t> exteriorOrbits;
  std::map<authority::SourceFaceTopologyKey, std::set<std::size_t>>
      fragmentOrbits;
  std::map<authority::SourceFaceTopologyKey, std::size_t> tracePieceCount;
  std::map<std::pair<authority::SourceFaceTopologyKey,
                    authority::SourceEdgeTopologyKey>,
           std::set<std::size_t>>
      edgeOrbitEvidence;
  std::vector<FragmentDiagnosticTraceSegment> traceSegments;
};

struct SourceFaceRecord {
  authority::SourceFaceTopologyKey topology;
  authority::SourceFaceId row;
  std::array<authority::SourceVertexId, 3> vertices;
  std::array<authority::SourceEdgeTopologyKey, 3> edges;
  authority::SourceComponentId component;
  authority::TopologyRegionId topologyRegion;
};

struct SourceTopologyIndex {
  std::map<authority::SourceFaceTopologyKey, SourceFaceRecord> faces;
  std::map<authority::SourceEdgeTopologyKey,
           std::vector<authority::SourceFaceTopologyKey>>
      incidentFaces;
  std::map<authority::SourceVertexId,
           std::vector<authority::SourceFaceTopologyKey>>
      incidentFacesByVertex;
};

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

struct CutNodeBindings {
  std::map<authority::SourceVertexId, authority::NetworkNodeId> nodeByVertex;
  std::map<authority::NetworkNodeId, authority::SourceVertexId> syntheticVertices;
  std::size_t combinedNodeExtent = 0U;
};

using CutNodeBindingResult =
    std::variant<CutNodeBindings, GlobalTopologyPlanError>;

CutNodeBindingResult build_cut_node_bindings(
    const FieldAlignedCurveNetwork &network, const SurfaceCutGraph &cutGraph) {
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
  for (const auto &edge : cutGraph.cut_edges()) {
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

using ArcBuildResult =
    std::variant<std::vector<GlobalTopologyArc>, GlobalTopologyPlanError>;

ArcBuildResult build_arcs(const FieldAlignedCurveNetwork &network,
                          const SurfaceCutGraph &cutGraph,
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
                 network.candidate_traces().size() + cutGraph.cut_edges().size());
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

  for (const auto &cutEdge : cutGraph.cut_edges()) {
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

struct NodeLocus {
  std::optional<authority::SourceVertexId> vertex;
  std::optional<authority::SourceEdgeTopologyKey> edge;
};

using NodeLocusResult =
    std::variant<std::map<authority::NetworkNodeId, NodeLocus>,
                 GlobalTopologyPlanError>;

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

using RotationBuildResult =
    std::variant<std::vector<GlobalTopologyNodeRotation>,
                 GlobalTopologyPlanError>;

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

struct FaceWalkResult {
  std::vector<std::vector<GlobalTopologyOrientedArc>> orbits;
  std::vector<std::size_t> orbitByDart;
};

using FaceWalkBuildResult = std::variant<FaceWalkResult, GlobalTopologyPlanError>;

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

std::optional<std::size_t> region_orbit(
    const GlobalTopologyRegion &region, const FaceWalkResult &walk) {
  std::optional<std::size_t> result;
  for (std::size_t orbit = 0U; orbit < walk.orbits.size(); ++orbit) {
    if (walk.orbits[orbit] != region.boundary) continue;
    if (result.has_value()) return std::nullopt;
    result = orbit;
  }
  return result;
}

std::vector<std::size_t> mandatory_arc_indices(
    const std::vector<GlobalTopologyArc> &arcs,
    const authority::NetworkEdgeId edge) {
  std::vector<std::size_t> result;
  for (std::size_t index = 0U; index < arcs.size(); ++index) {
    if (arcs[index].kind == GlobalTopologyArcKind::Mandatory &&
        arcs[index].mandatoryEdge == edge) {
      result.push_back(index);
    }
  }
  return result;
}

using FragmentCornerIncidence =
    std::map<authority::SourceFaceTopologyKey,
             std::map<std::size_t, std::set<authority::SourceVertexId>>>;
using FragmentCornerBuildResult =
    std::variant<FragmentCornerIncidence, GlobalTopologyPlanError>;

FragmentCornerBuildResult build_fragment_corner_incidence(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk) {
  struct RayCut {
    int ordinal = 0;
    std::size_t forwardOrbit = 0U;
    std::size_t reverseOrbit = 0U;
    std::size_t sourceCorner = 0U;
  };

  FragmentCornerIncidence result;
  std::map<authority::SourceFaceTopologyKey, bool> hasFullChord;
  std::map<authority::SourceFaceTopologyKey, std::vector<RayCut>> raysByFace;

  for (const GlobalTopologyArc &arc : arcs) {
    if (arc.kind != GlobalTopologyArcKind::Trace || !arc.trace.has_value()) {
      continue;
    }
    const FieldAlignedCandidateTrace *trace = find_trace(network, *arc.trace);
    if (trace == nullptr || arc.firstSegment >= arc.onePastLastSegment ||
        arc.onePastLastSegment > trace->segments.size()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.arc = arc.id;
      return failure;
    }
    const auto port = std::find_if(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace->port; });
    if (port == network.singularity_ports().end() || port->ordinal < 0 ||
        port->sourceVertex != trace->sourceVertex) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      failure.arc = arc.id;
      failure.singularity = trace->singularity;
      return failure;
    }
    const std::size_t forwardDart = dart_index(
        GlobalTopologyOrientedArc{arc.id, authority::Orientation::Forward});
    const std::size_t reverseDart = dart_index(
        GlobalTopologyOrientedArc{arc.id, authority::Orientation::Reverse});
    if (forwardDart >= walk.orbitByDart.size() ||
        reverseDart >= walk.orbitByDart.size()) {
      return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
    }
    const std::size_t forwardOrbit = walk.orbitByDart[forwardDart];
    const std::size_t reverseOrbit = walk.orbitByDart[reverseDart];

    for (std::size_t segmentIndex = arc.firstSegment;
         segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
      const FieldAlignedCandidateTraceSegment &segment =
          trace->segments[segmentIndex];
      const auto faceIt = topology.faces.find(segment.sourceFace);
      if (faceIt == topology.faces.end()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      const bool terminalSlit =
          !trace->terminalBarrier.has_value() &&
          segmentIndex + 1U == trace->segments.size();
      if (terminalSlit) {
        // The retained outgoing carrier is only a hypothetical continuation.
        // The frozen fragment/F authority remains untouched; this helper only
        // omits the nonexistent chord from source-corner separation.
        continue;
      }
      if (forwardOrbit == reverseOrbit) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::TraceArcDoesNotSeparateItsSides);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }

      const SourceFaceRecord &face = faceIt->second;
      if (segment.incomingCarrier.has_value()) {
        if (hasFullChord[segment.sourceFace] ||
            !raysByFace[segment.sourceFace].empty()) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::SourceFaceCarriesMultipleTraceCuts);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const auto incoming =
            local_edge_index(face, *segment.incomingCarrier);
        const auto outgoing = local_edge_index(face, segment.outgoingCarrier);
        if (!incoming.has_value() || !outgoing.has_value() ||
            *incoming == *outgoing) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::TraceSegmentCarriersCoincide);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const std::size_t turn = (*outgoing + 3U - *incoming) % 3U;
        if (turn != 1U && turn != 2U) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::TraceSegmentTurnNotAdmissible);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        std::optional<std::size_t> sharedCorner;
        for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
          const authority::SourceVertexId vertex = face.vertices[corner];
          const bool onIncoming =
              vertex == segment.incomingCarrier->first() ||
              vertex == segment.incomingCarrier->second();
          const bool onOutgoing =
              vertex == segment.outgoingCarrier.first() ||
              vertex == segment.outgoingCarrier.second();
          if (onIncoming && onOutgoing) {
            if (sharedCorner.has_value()) {
              GlobalTopologyPlanError failure = error(
                  GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareMultipleCorners);
              failure.arc = arc.id;
              failure.sourceFace = segment.sourceFace;
              return failure;
            }
            sharedCorner = corner;
          }
        }
        if (!sharedCorner.has_value()) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareNoCorner);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const std::size_t sideOrbit =
            turn == 1U ? forwardOrbit : reverseOrbit;
        const std::size_t cornerOrbit =
            sideOrbit == forwardOrbit ? reverseOrbit : forwardOrbit;
        result[segment.sourceFace][cornerOrbit].insert(
            face.vertices[*sharedCorner]);
        for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
          if (corner != *sharedCorner) {
            result[segment.sourceFace][sideOrbit].insert(face.vertices[corner]);
          }
        }
        hasFullChord[segment.sourceFace] = true;
        continue;
      }

      if (hasFullChord[segment.sourceFace]) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::SourcePortFaceAlreadyCarriesTraceChord);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      std::optional<std::size_t> sourceCorner;
      for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
        if (face.vertices[corner] == trace->sourceVertex) {
          sourceCorner = corner;
          break;
        }
      }
      const auto outgoing = local_edge_index(face, segment.outgoingCarrier);
      if (!sourceCorner.has_value() || !outgoing.has_value() ||
          *outgoing != (*sourceCorner + 1U) % 3U) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::TraceSourcePortCarrierNotAdmissible);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      raysByFace[segment.sourceFace].push_back(
          RayCut{port->ordinal, forwardOrbit, reverseOrbit, *sourceCorner});
    }
  }

  for (auto &[faceKey, rays] : raysByFace) {
    if (rays.empty()) continue;
    if (hasFullChord[faceKey]) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::SourceFaceCarriesTraceChordAndRays);
      failure.sourceFace = faceKey;
      return failure;
    }
    const auto faceIt = topology.faces.find(faceKey);
    if (faceIt == topology.faces.end()) {
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
    std::sort(rays.begin(), rays.end(), [](const RayCut &first,
                                            const RayCut &second) {
      return first.ordinal < second.ordinal;
    });
    for (std::size_t index = 0U; index < rays.size(); ++index) {
      if (rays[index].sourceCorner != rays.front().sourceCorner ||
          (index > 0U && rays[index - 1U].ordinal == rays[index].ordinal) ||
          (index > 0U &&
           rays[index - 1U].forwardOrbit != rays[index].reverseOrbit)) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        failure.sourceFace = faceKey;
        return failure;
      }
    }
    const SourceFaceRecord &face = faceIt->second;
    const std::size_t sourceCorner = rays.front().sourceCorner;
    const authority::SourceVertexId sourceVertex = face.vertices[sourceCorner];
    for (const RayCut &ray : rays) {
      result[faceKey][ray.forwardOrbit].insert(sourceVertex);
      result[faceKey][ray.reverseOrbit].insert(sourceVertex);
    }
    result[faceKey][rays.front().reverseOrbit].insert(
        face.vertices[(sourceCorner + 1U) % 3U]);
    result[faceKey][rays.back().forwardOrbit].insert(
        face.vertices[(sourceCorner + 2U) % 3U]);
  }

  return result;
}

struct RegionDraft {
  std::size_t orbit = 0U;
  std::vector<GlobalTopologyOrientedArc> boundary;
};

using RegionBuildResult =
    std::variant<std::vector<GlobalTopologyRegion>, GlobalTopologyPlanError>;

RegionBuildResult build_regions(
    const SourceTopologyIndex &topology,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk, FragmentDiagnosticEvidence *diagnostics) {
  (void)sourceAuthority;

  std::set<std::size_t> exteriorOrbits;
  std::set<authority::SourceEdgeTopologyKey> mandatoryEdges;
  const std::set<authority::SourceEdgeTopologyKey> cutEdges(
      cutGraph.cut_edges().begin(), cutGraph.cut_edges().end());
  std::map<authority::SourceFaceTopologyKey, std::set<std::size_t>>
      fragmentOrbits;
  std::map<authority::SourceFaceTopologyKey, std::size_t> tracePieceCount;
  std::set<authority::SourceEdgeTopologyKey> traceTouchedEdges;
  std::map<std::pair<authority::SourceFaceTopologyKey,
                     authority::SourceEdgeTopologyKey>,
           std::set<std::size_t>>
      edgeOrbitEvidence;

  const auto add_fragment_orbit = [&](const authority::SourceFaceTopologyKey &face,
                                      const std::size_t orbit) {
    if (exteriorOrbits.count(orbit) == 0U) {
      fragmentOrbits[face].insert(orbit);
    }
  };

  // Mandatory source edges carry an exact interior-side dart. Boundary edges
  // additionally identify the exterior orbit. This is oriented network
  // evidence, not source-component or traversal-order authority.
  for (const auto &mandatory : network.mandatory_edges()) {
    mandatoryEdges.insert(mandatory.sourceEdge);
    const auto arcIndices = mandatory_arc_indices(arcs, mandatory.id);
    if (arcIndices.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
      failure.networkEdge = mandatory.id;
      failure.sourceEdge = mandatory.sourceEdge;
      return failure;
    }
    const auto incident = topology.incidentFaces.find(mandatory.sourceEdge);
    if (incident == topology.incidentFaces.end() || incident->second.empty()) {
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
    for (const std::size_t arcIndex : arcIndices) {
      const GlobalTopologyArc &arc = arcs[arcIndex];
      for (const auto &faceKey : incident->second) {
        const auto face = topology.faces.find(faceKey);
        if (face == topology.faces.end()) {
          return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        }
        const bool forward =
            face_orients_edge_forward(face->second, mandatory.sourceEdge);
        const std::size_t interiorDart =
            2U * arc.id.index() + (forward ? 0U : 1U);
        if (interiorDart >= walk.orbitByDart.size()) {
          return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        }
        const std::size_t interiorOrbit = walk.orbitByDart[interiorDart];
        if (mandatory.kind == SurfaceCellRailKind::Boundary) {
          const std::size_t exteriorDart = interiorDart ^ 1U;
          if (exteriorDart >= walk.orbitByDart.size()) {
            return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
          }
          exteriorOrbits.insert(walk.orbitByDart[exteriorDart]);
        }
        fragmentOrbits[faceKey].insert(interiorOrbit);
        edgeOrbitEvidence[std::make_pair(faceKey, mandatory.sourceEdge)]
            .insert(interiorOrbit);
      }
    }
  }

  // A2a' cuts are ordinary embedded source-edge barriers. Unlike source
  // boundaries both darts own interior regions; unlike mandatory rails they
  // carry no FieldAlignedCurveNetwork edge identity.
  for (const auto &cutEdge : cutGraph.cut_edges()) {
    const auto incident = topology.incidentFaces.find(cutEdge);
    if (incident == topology.incidentFaces.end() || incident->second.size() != 2U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceEdge = cutEdge;
      return failure;
    }
    std::vector<std::size_t> arcIndices;
    for (std::size_t index = 0U; index < arcs.size(); ++index) {
      if (arcs[index].kind == GlobalTopologyArcKind::Cut &&
          arcs[index].cutEdge == cutEdge) {
        arcIndices.push_back(index);
      }
    }
    if (arcIndices.size() != 1U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceEdge = cutEdge;
      return failure;
    }
    const GlobalTopologyArc &arc = arcs[arcIndices.front()];
    for (const auto &faceKey : incident->second) {
      const auto face = topology.faces.find(faceKey);
      if (face == topology.faces.end()) {
        return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      }
      const bool forward = face_orients_edge_forward(face->second, cutEdge);
      const std::size_t interiorDart =
          2U * arc.id.index() + (forward ? 0U : 1U);
      if (interiorDart >= walk.orbitByDart.size()) {
        return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      }
      const std::size_t interiorOrbit = walk.orbitByDart[interiorDart];
      fragmentOrbits[faceKey].insert(interiorOrbit);
      edgeOrbitEvidence[std::make_pair(faceKey, cutEdge)].insert(interiorOrbit);
    }
  }

  std::vector<RegionDraft> drafts;
  for (std::size_t orbit = 0U; orbit < walk.orbits.size(); ++orbit) {
    if (exteriorOrbits.count(orbit) != 0U) continue;
    drafts.push_back(RegionDraft{orbit, walk.orbits[orbit]});
  }
  if (drafts.empty()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::EmbeddedGraphHasNoInteriorFace);
    failure.arc = walk.orbits.front().front().arc;
    return failure;
  }
  std::sort(drafts.begin(), drafts.end(), [](const RegionDraft &lhs,
                                             const RegionDraft &rhs) {
    return lhs.boundary < rhs.boundary;
  });
  std::map<std::size_t, std::size_t> draftByOrbit;
  for (std::size_t index = 0U; index < drafts.size(); ++index) {
    draftByOrbit.emplace(drafts[index].orbit, index);
  }

  // A trace segment is a topological chord of its source face. The two darts
  // of its graph arc are the two sides of that chord, and orbitByDart is the
  // sole owner label for those two fragments. Multiple chords in one face are
  // consistent exactly when their distinct dart orbits produce k+1 fragments.
  for (const auto &arc : arcs) {
    if (arc.kind != GlobalTopologyArcKind::Trace) continue;
    if (!arc.trace.has_value()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.arc = arc.id;
      return failure;
    }
    const auto *trace = find_trace(network, *arc.trace);
    if (trace == nullptr || arc.firstSegment >= arc.onePastLastSegment ||
        arc.onePastLastSegment > trace->segments.size()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.arc = arc.id;
      return failure;
    }
    const std::size_t forwardDart =
        dart_index(GlobalTopologyOrientedArc{arc.id,
                                             authority::Orientation::Forward});
    const std::size_t reverseDart =
        dart_index(GlobalTopologyOrientedArc{arc.id,
                                             authority::Orientation::Reverse});
    if (forwardDart >= walk.orbitByDart.size() ||
        reverseDart >= walk.orbitByDart.size()) {
      return error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
    }
    const std::size_t forwardOrbit = walk.orbitByDart[forwardDart];
    const std::size_t reverseOrbit = walk.orbitByDart[reverseDart];

    std::optional<authority::SourceVertexId> sourcePortVertex;
    if (diagnostics != nullptr) {
      const auto port = std::find_if(
          network.singularity_ports().begin(),
          network.singularity_ports().end(),
          [&](const auto &candidate) { return candidate.id == trace->port; });
      if (port != network.singularity_ports().end()) {
        sourcePortVertex = port->sourceVertex;
      }
    }

    for (std::size_t segmentIndex = arc.firstSegment;
         segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
      const auto &segment = trace->segments[segmentIndex];
      const auto faceIt = topology.faces.find(segment.sourceFace);
      if (faceIt == topology.faces.end()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      ++tracePieceCount[segment.sourceFace];
      add_fragment_orbit(segment.sourceFace, forwardOrbit);
      add_fragment_orbit(segment.sourceFace, reverseOrbit);
      traceTouchedEdges.insert(segment.outgoingCarrier);
      if (segment.incomingCarrier.has_value()) {
        traceTouchedEdges.insert(*segment.incomingCarrier);
      }
      if (diagnostics != nullptr) {
        diagnostics->traceSegments.push_back(FragmentDiagnosticTraceSegment{
            trace->id, arc.id, segmentIndex, forwardOrbit, reverseOrbit,
            segment.sourceFace, segment.incomingCarrier,
            segment.outgoingCarrier, sourcePortVertex});
      }

      // On a triangle, a chord between two carriers leaves the third edge
      // wholly on exactly one oriented side. Record that exact side so an
      // otherwise-uncut neighboring face can inherit the same graph-face orbit
      // without a flood fill or traversal-order choice.
      if (segment.incomingCarrier.has_value()) {
        const auto incoming =
            local_edge_index(faceIt->second, *segment.incomingCarrier);
        const auto outgoing =
            local_edge_index(faceIt->second, segment.outgoingCarrier);
        if (!incoming.has_value() || !outgoing.has_value() ||
            *incoming == *outgoing) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionTraceSegmentCarriersCoincide);
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const std::size_t turn = (*outgoing + 3U - *incoming) % 3U;
        if (turn != 1U && turn != 2U) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionTraceSegmentTurnNotAdmissible);
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        std::size_t third = 0U;
        while (third == *incoming || third == *outgoing) ++third;
        const std::size_t sideOrbit = turn == 1U ? forwardOrbit : reverseOrbit;
        if (exteriorOrbits.count(sideOrbit) == 0U) {
          edgeOrbitEvidence[
              std::make_pair(segment.sourceFace, faceIt->second.edges[third])]
              .insert(sideOrbit);
        }
      } else {
        std::optional<std::size_t> sourceCorner;
        for (std::size_t corner = 0U; corner < faceIt->second.vertices.size();
             ++corner) {
          if (faceIt->second.vertices[corner] == trace->sourceVertex) {
            sourceCorner = corner;
            break;
          }
        }
        const auto outgoing =
            local_edge_index(faceIt->second, segment.outgoingCarrier);
        if (!sourceCorner.has_value() || !outgoing.has_value() ||
            *outgoing != (*sourceCorner + 1U) % 3U) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionTraceSourcePortCarrierNotAdmissible);
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const auto forwardEdge = faceIt->second.edges[(*sourceCorner + 2U) % 3U];
        const auto reverseEdge = faceIt->second.edges[*sourceCorner];
        if (exteriorOrbits.count(forwardOrbit) == 0U) {
          edgeOrbitEvidence[std::make_pair(segment.sourceFace, forwardEdge)]
              .insert(forwardOrbit);
        }
        if (exteriorOrbits.count(reverseOrbit) == 0U) {
          edgeOrbitEvidence[std::make_pair(segment.sourceFace, reverseEdge)]
              .insert(reverseOrbit);
        }
      }
    }
  }

  // Validate every directly cut face before extending single-fragment interiors.
  // A face with k trace chords has k+1 fragments; a face with no chord has one.
  for (const auto &[faceKey, record] : topology.faces) {
    (void)record;
    const auto found = fragmentOrbits.find(faceKey);
    if (found == fragmentOrbits.end() || found->second.empty()) continue;
    const std::size_t expected = tracePieceCount[faceKey] + 1U;
    if (found->second.size() != expected) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::TraceCutFaceFragmentCountMismatch);
      failure.sourceFace = faceKey;
      return failure;
    }
  }

  // Uncrossed faces that are not themselves boundary evidence have one
  // fragment. Resolve only the equivalence induced by source edges untouched
  // by the embedded network. Union-find is used as an order-independent
  // equality constraint; ownership still comes exclusively from a unique
  // neighboring dart-orbit seed. No BFS, distance, proximity, A0 identity, or
  // arbitrary unclaimed-face fallback participates.
  std::vector<authority::SourceFaceTopologyKey> unlabeledFaces;
  std::map<authority::SourceFaceTopologyKey, std::size_t> unlabeledIndex;
  for (const auto &[faceKey, record] : topology.faces) {
    (void)record;
    const auto found = fragmentOrbits.find(faceKey);
    if (found != fragmentOrbits.end() && !found->second.empty()) continue;
    unlabeledIndex.emplace(faceKey, unlabeledFaces.size());
    unlabeledFaces.push_back(faceKey);
  }
  std::set<authority::SourceEdgeTopologyKey> componentBarriers = mandatoryEdges;
  componentBarriers.insert(traceTouchedEdges.begin(), traceTouchedEdges.end());
  componentBarriers.insert(cutEdges.begin(), cutEdges.end());
  const auto componentPartition = detail::build_source_face_component_partition(
      unlabeledFaces, topology.incidentFaces, componentBarriers);

  std::map<std::size_t, std::set<std::size_t>> seedOrbits;
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size() != 2U || mandatoryEdges.count(edge) != 0U || cutEdges.count(edge) != 0U ||
        traceTouchedEdges.count(edge) != 0U) {
      continue;
    }
    for (std::size_t side = 0U; side < 2U; ++side) {
      const auto unlabeled = unlabeledIndex.find(incident[side]);
      if (unlabeled == unlabeledIndex.end()) continue;
      const auto &labeledFace = incident[side ^ 1U];
      const auto labeled = fragmentOrbits.find(labeledFace);
      if (labeled == fragmentOrbits.end() || labeled->second.empty()) continue;

      std::optional<std::size_t> seed;
      if (labeled->second.size() == 1U) {
        seed = *labeled->second.begin();
      } else {
        const auto edgeEvidence =
            edgeOrbitEvidence.find(std::make_pair(labeledFace, edge));
        if (edgeEvidence != edgeOrbitEvidence.end() &&
            edgeEvidence->second.size() == 1U) {
          seed = *edgeEvidence->second.begin();
        }
      }
      if (seed.has_value()) {
        const auto component = componentPartition.componentByFace.find(incident[side]);
        if (component == componentPartition.componentByFace.end()) {
          return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        }
        seedOrbits[component->second].insert(*seed);
      }
    }
  }

  for (std::size_t index = 0U; index < unlabeledFaces.size(); ++index) {
    const auto component =
        componentPartition.componentByFace.find(unlabeledFaces[index]);
    if (component == componentPartition.componentByFace.end()) {
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
    const auto seeds = seedOrbits.find(component->second);
    if (seeds == seedOrbits.end() || seeds->second.size() != 1U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique);
      failure.sourceFace = unlabeledFaces[index];
      return failure;
    }
    fragmentOrbits[unlabeledFaces[index]].insert(*seeds->second.begin());
  }

  std::vector<std::vector<authority::SourceFaceTopologyKey>> owned(drafts.size());
  for (const auto &[faceKey, record] : topology.faces) {
    (void)record;
    const auto fragments = fragmentOrbits.find(faceKey);
    if (fragments == fragmentOrbits.end() || fragments->second.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitMissing);
      failure.sourceFace = faceKey;
      return failure;
    }
    for (const std::size_t orbit : fragments->second) {
      const auto draft = draftByOrbit.find(orbit);
      if (draft == draftByOrbit.end()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitHasNoRegionDraft);
        failure.sourceFace = faceKey;
        return failure;
      }
      owned[draft->second].push_back(faceKey);
    }
  }

  std::vector<GlobalTopologyRegion> regions;
  regions.reserve(drafts.size());
  for (std::size_t index = 0U; index < drafts.size(); ++index) {
    std::sort(owned[index].begin(), owned[index].end());
    owned[index].erase(std::unique(owned[index].begin(), owned[index].end()),
                       owned[index].end());
    if (owned[index].empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionElectedCutComponentEmpty);
      failure.region = make_id<authority::NetworkRegionId>(index, drafts.size());
      return failure;
    }
    regions.push_back(GlobalTopologyRegion{
        make_id<authority::NetworkRegionId>(index, drafts.size()),
        std::move(drafts[index].boundary), std::move(owned[index])});
  }
  if (diagnostics != nullptr) {
    diagnostics->exteriorOrbits = exteriorOrbits;
    diagnostics->fragmentOrbits = fragmentOrbits;
    diagnostics->tracePieceCount = tracePieceCount;
    diagnostics->edgeOrbitEvidence = edgeOrbitEvidence;
    std::sort(diagnostics->traceSegments.begin(),
              diagnostics->traceSegments.end(),
              [](const auto &lhs, const auto &rhs) {
                return std::tie(lhs.trace, lhs.arc, lhs.segment,
                                lhs.forwardOrbit, lhs.reverseOrbit,
                                lhs.sourceFace, lhs.incomingCarrier,
                                lhs.outgoingCarrier, lhs.sourcePortVertex) <
                       std::tie(rhs.trace, rhs.arc, rhs.segment,
                                rhs.forwardOrbit, rhs.reverseOrbit,
                                rhs.sourceFace, rhs.incomingCarrier,
                                rhs.outgoingCarrier, rhs.sourcePortVertex);
              });
  }
  return regions;
}

std::pair<authority::NetworkNodeId, authority::NetworkNodeId>
oriented_arc_nodes(const GlobalTopologyArc &arc,
                   const authority::Orientation orientation) {
  return orientation == authority::Orientation::Forward
             ? std::make_pair(arc.firstNode, arc.secondNode)
             : std::make_pair(arc.secondNode, arc.firstNode);
}

std::optional<GlobalTopologyPlanError> validate_single_boundary_walk(
    const GlobalTopologyRegion &region,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById) {
  if (region.boundary.empty()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
    failure.region = region.id;
    return failure;
  }
  const auto firstArc = arcById.find(region.boundary.front().arc);
  if (firstArc == arcById.end()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
    failure.region = region.id;
    failure.arc = region.boundary.front().arc;
    return failure;
  }
  const auto firstNodes =
      oriented_arc_nodes(*firstArc->second, region.boundary.front().orientation);
  const authority::NetworkNodeId start = firstNodes.first;
  authority::NetworkNodeId current = firstNodes.second;
  for (std::size_t index = 1U; index < region.boundary.size(); ++index) {
    const auto nextArc = arcById.find(region.boundary[index].arc);
    if (nextArc == arcById.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.region = region.id;
      failure.arc = region.boundary[index].arc;
      return failure;
    }
    const auto next =
        oriented_arc_nodes(*nextArc->second, region.boundary[index].orientation);
    if (current == start || next.first != current) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
      failure.region = region.id;
      failure.arc = region.boundary[index].arc;
      return failure;
    }
    current = next.second;
  }
  if (current != start) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
    failure.region = region.id;
    failure.arc = region.boundary.front().arc;
    return failure;
  }
  return std::nullopt;
}

std::optional<GlobalTopologyPlanError> validate_no_region_fragment_pinch(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const std::vector<GlobalTopologyNodeRotation> &rotations,
    const FaceWalkResult &walk, const GlobalTopologyRegion &region,
    const std::size_t owningOrbit) {
  const NodeLocusResult locusBuild = build_node_loci(network);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&locusBuild)) {
    return *failure;
  }
  const auto &loci =
      std::get<std::map<authority::NetworkNodeId, NodeLocus>>(locusBuild);
  const std::set<authority::SourceFaceTopologyKey> regionFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());

  for (const auto &rotation : rotations) {
    const auto locus = loci.find(rotation.node);
    if (locus == loci.end() || rotation.counterClockwise.empty()) continue;

    const std::size_t count = rotation.counterClockwise.size();
    std::vector<bool> ownsSector(count, false);
    bool anyOwned = false;
    bool allOwned = true;
    for (std::size_t index = 0U; index < count; ++index) {
      const std::size_t incomingDart =
          dart_index(reversed(rotation.counterClockwise[index]));
      if (incomingDart >= walk.orbitByDart.size()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
        failure.region = region.id;
        failure.sourceVertex = locus->second.vertex;
        failure.sourceEdge = locus->second.edge;
        return failure;
      }
      ownsSector[index] = walk.orbitByDart[incomingDart] == owningOrbit;
      anyOwned = anyOwned || ownsSector[index];
      allOwned = allOwned && ownsSector[index];
    }
    if (!anyOwned || allOwned) continue;

    std::size_t runCount = 0U;
    for (std::size_t index = 0U; index < count; ++index) {
      const std::size_t previous = (index + count - 1U) % count;
      if (ownsSector[index] && !ownsSector[previous]) ++runCount;
    }
    if (runCount <= 1U) continue;

    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionFragmentPinchedAtVertex);
    failure.region = region.id;
    failure.sourceVertex = locus->second.vertex;
    failure.sourceEdge = locus->second.edge;

    std::vector<authority::SourceFaceTopologyKey> witnesses;
    if (locus->second.vertex.has_value()) {
      const auto incident =
          topology.incidentFacesByVertex.find(*locus->second.vertex);
      if (incident != topology.incidentFacesByVertex.end()) {
        for (const auto &face : incident->second) {
          if (regionFaces.count(face) != 0U) witnesses.push_back(face);
        }
        if (witnesses.empty() && !incident->second.empty()) {
          witnesses.push_back(incident->second.front());
        }
      }
    } else if (locus->second.edge.has_value()) {
      const auto incident = topology.incidentFaces.find(*locus->second.edge);
      if (incident != topology.incidentFaces.end()) {
        for (const auto &face : incident->second) {
          if (regionFaces.count(face) != 0U) witnesses.push_back(face);
        }
        if (witnesses.empty() && !incident->second.empty()) {
          witnesses.push_back(incident->second.front());
        }
      }
    }
    if (!witnesses.empty()) {
      failure.sourceFace = witnesses.front();
      failure.secondSourceFace =
          witnesses.size() > 1U ? witnesses[1] : witnesses.front();
    }
    return failure;
  }
  return std::nullopt;
}

using RegionCertificateBuildResult =
    std::variant<GlobalTopologyRegionDiscCertificate, GlobalTopologyPlanError>;

using RegionSingularityValidationResult =
    std::variant<std::vector<authority::FieldSingularityId>,
                 GlobalTopologyPlanError>;

RegionSingularityValidationResult validate_region_interior_singularities(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const GlobalTopologyRegion &region,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById) {
  std::set<authority::NetworkNodeId> boundaryNodes;
  for (const auto incidence : region.boundary) {
    const auto found = arcById.find(incidence.arc);
    if (found == arcById.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.region = region.id;
      failure.arc = incidence.arc;
      return failure;
    }
    const auto nodes = oriented_arc_nodes(*found->second, incidence.orientation);
    boundaryNodes.insert(nodes.first);
    boundaryNodes.insert(nodes.second);
  }

  const std::set<authority::SourceFaceTopologyKey> regionFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());
  std::map<authority::SourceVertexId, authority::FieldSingularityId>
      singularityAtVertex;
  for (const auto &port : network.singularity_ports()) {
    singularityAtVertex.emplace(port.sourceVertex, port.singularity);
  }

  std::vector<authority::FieldSingularityId> boundarySingularities;
  for (const auto &[sourceVertex, singularity] : singularityAtVertex) {
    const auto incident = topology.incidentFacesByVertex.find(sourceVertex);
    if (incident == topology.incidentFacesByVertex.end()) continue;
    const bool reachesRegion = std::any_of(
        incident->second.begin(), incident->second.end(),
        [&](const auto &face) { return regionFaces.count(face) != 0U; });
    if (!reachesRegion) continue;
    const bool onBoundary = std::any_of(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &port) {
          return port.singularity == singularity &&
                 boundaryNodes.count(port.node) != 0U;
        });
    if (!onBoundary) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionContainsInteriorSingularity);
      failure.region = region.id;
      failure.singularity = singularity;
      failure.sourceVertex = sourceVertex;
      return failure;
    }
    boundarySingularities.push_back(singularity);
  }
  std::sort(boundarySingularities.begin(), boundarySingularities.end());
  boundarySingularities.erase(
      std::unique(boundarySingularities.begin(), boundarySingularities.end()),
      boundarySingularities.end());
  return boundarySingularities;
}

void emit_fragment_euler_diagnostics(
    const FragmentDiagnosticEvidence &diagnostics,
    const GlobalTopologyRegion &region, const std::size_t owningOrbit,
    const std::set<authority::SourceVertexId> &candidateVertices,
    const std::set<authority::SourceVertexId> &mandatoryBoundaryEndpoints,
    const std::set<authority::SourceVertexId> &tracePortBoundaryVertices,
    const std::set<authority::SourceVertexId> &interiorVertices,
    const GlobalTopologyRegionDiscCertificate &certificate) {
  {
    std::ostringstream out;
    out << "M3_CP4AB_FRAGMENT_DIAG record=exterior_orbits orbits="
        << diagnostic_values(diagnostics.exteriorOrbits);
    std::cerr << out.str() << '\n';
  }
  for (const auto &segment : diagnostics.traceSegments) {
    std::ostringstream out;
    out << "M3_CP4AB_FRAGMENT_DIAG record=trace_segment"
        << " trace=" << segment.trace.index()
        << " arc=" << segment.arc.index()
        << " segment=" << segment.segment
        << " forward_orbit=" << segment.forwardOrbit
        << " reverse_orbit=" << segment.reverseOrbit
        << " source_face=" << diagnostic_face(segment.sourceFace)
        << " incoming_carrier="
        << (segment.incomingCarrier.has_value()
                ? diagnostic_edge(*segment.incomingCarrier)
                : std::string{"none"})
        << " outgoing_carrier=" << diagnostic_edge(segment.outgoingCarrier)
        << " source_port_vertex=";
    if (segment.sourcePortVertex.has_value()) {
      out << segment.sourcePortVertex->index();
    } else {
      out << "none";
    }
    std::cerr << out.str() << '\n';
  }

  std::ostringstream out;
  out << "M3_CP4AB_FRAGMENT_DIAG record=euler_rejection"
      << " region=" << region.id.index()
      << " owning_orbit=" << owningOrbit
      << " support_faces=[";
  for (std::size_t index = 0U; index < region.sourceFaces.size(); ++index) {
    if (index != 0U) out << ';';
    out << diagnostic_face(region.sourceFaces[index]);
  }
  out << "] fragment_orbits=[";
  bool first = true;
  for (const auto &face : region.sourceFaces) {
    const auto found = diagnostics.fragmentOrbits.find(face);
    if (found == diagnostics.fragmentOrbits.end()) continue;
    if (!first) out << ';';
    first = false;
    out << diagnostic_face(face) << ':' << diagnostic_values(found->second);
  }
  out << "] edge_orbit_evidence=[";
  first = true;
  const std::set<authority::SourceFaceTopologyKey> supportFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());
  for (const auto &[key, orbits] : diagnostics.edgeOrbitEvidence) {
    if (supportFaces.count(key.first) == 0U) continue;
    if (!first) out << ';';
    first = false;
    out << diagnostic_face(key.first) << '/' << diagnostic_edge(key.second)
        << ':' << diagnostic_values(orbits);
  }
  out << "] trace_piece_count=[";
  first = true;
  for (const auto &face : region.sourceFaces) {
    if (!first) out << ';';
    first = false;
    const auto found = diagnostics.tracePieceCount.find(face);
    out << diagnostic_face(face) << ':'
        << (found == diagnostics.tracePieceCount.end() ? 0U : found->second);
  }
  out << "] candidate_vertices=" << diagnostic_values(candidateVertices)
      << " mandatory_boundary_endpoints="
      << diagnostic_values(mandatoryBoundaryEndpoints)
      << " trace_port_boundary_vertices="
      << diagnostic_values(tracePortBoundaryVertices)
      << " interior_vertices=" << diagnostic_values(interiorVertices)
      << " V_int=" << certificate.vertexCount
      << " E_int=" << certificate.edgeCount
      << " F=" << certificate.faceCount
      << " chi=" << certificate.eulerCharacteristic;
  std::cerr << out.str() << '\n';
}

RegionCertificateBuildResult build_region_certificate(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    const std::vector<GlobalTopologyArc> &arcs,
    const GlobalTopologyRegion &region, const std::size_t owningOrbit,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById,
    std::vector<authority::FieldSingularityId> boundarySingularities,
    const FragmentCornerIncidence &fragmentCorners,
    const FragmentDiagnosticEvidence *diagnostics) {
  if (const auto failure = validate_single_boundary_walk(region, arcById);
      failure.has_value()) {
    return *failure;
  }

  GlobalTopologyRegionDiscCertificate certificate(region.id);
  certificate.boundaryWalkCount = 1U;
  certificate.faceCount = region.sourceFaces.size();

  certificate.boundarySingularities = std::move(boundarySingularities);
  certificate.interiorSingularityFree = true;

  using FragmentKey =
      std::pair<authority::SourceFaceTopologyKey, std::size_t>;
  std::set<FragmentKey> fragments;
  std::map<FragmentKey, std::vector<FragmentKey>> neighbors;
  for (const auto &face : region.sourceFaces) {
    const FragmentKey fragment{face, owningOrbit};
    fragments.insert(fragment);
    neighbors.emplace(fragment, std::vector<FragmentKey>{});
  }

  std::set<authority::SourceEdgeTopologyKey> mandatoryEdges;
  for (const auto &mandatory : network.mandatory_edges()) {
    mandatoryEdges.insert(mandatory.sourceEdge);
  }
  const std::set<authority::SourceEdgeTopologyKey> cutEdges(
      cutGraph.cut_edges().begin(), cutGraph.cut_edges().end());
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size() != 2U || mandatoryEdges.count(edge) != 0U ||
        cutEdges.count(edge) != 0U) {
      continue;
    }
    const FragmentKey first{incident[0], owningOrbit};
    const FragmentKey second{incident[1], owningOrbit};
    if (fragments.count(first) == 0U || fragments.count(second) == 0U) {
      continue;
    }
    neighbors[first].push_back(second);
    neighbors[second].push_back(first);
    ++certificate.edgeCount;
  }

  std::set<FragmentKey> visited;
  std::deque<FragmentKey> queue;
  const FragmentKey firstFragment{region.sourceFaces.front(), owningOrbit};
  queue.push_back(firstFragment);
  visited.insert(firstFragment);
  while (!queue.empty()) {
    const auto fragment = queue.front();
    queue.pop_front();
    for (const auto &next : neighbors[fragment]) {
      if (visited.insert(next).second) queue.push_back(next);
    }
  }
  if (visited.size() != fragments.size()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionInteriorDisconnected);
    failure.region = region.id;
    failure.sourceFace = region.sourceFaces.front();
    const auto disconnected = std::find_if(
        region.sourceFaces.begin(), region.sourceFaces.end(),
        [&](const auto &face) {
          return visited.count(FragmentKey{face, owningOrbit}) == 0U;
        });
    if (disconnected != region.sourceFaces.end()) {
      failure.secondSourceFace = *disconnected;
    }
    return failure;
  }
  certificate.sourceFacesConnected = true;

  std::set<authority::SourceVertexId> boundaryVertices;
  std::set<authority::SourceVertexId> mandatoryBoundaryEndpoints;
  std::set<authority::SourceVertexId> tracePortBoundaryVertices;
  std::set<authority::NetworkEdgeId> boundaryMandatoryEdges;
  std::set<authority::TraceId> boundaryTraces;
  for (const auto incidence : region.boundary) {
    const auto found = arcById.find(incidence.arc);
    if (found == arcById.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.region = region.id;
      failure.arc = incidence.arc;
      return failure;
    }
    if (found->second->mandatoryEdge.has_value()) {
      boundaryMandatoryEdges.insert(*found->second->mandatoryEdge);
      const auto *mandatory =
          find_mandatory(network, *found->second->mandatoryEdge);
      if (mandatory == nullptr) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
        failure.region = region.id;
        failure.arc = incidence.arc;
        return failure;
      }
      const auto addSourceEndpoint = [&](
          const authority::NetworkNodeId node) {
        if (node == mandatory->firstNode) {
          boundaryVertices.insert(mandatory->sourceEdge.first());
          if (diagnostics != nullptr) {
            mandatoryBoundaryEndpoints.insert(mandatory->sourceEdge.first());
          }
        }
        if (node == mandatory->secondNode) {
          boundaryVertices.insert(mandatory->sourceEdge.second());
          if (diagnostics != nullptr) {
            mandatoryBoundaryEndpoints.insert(mandatory->sourceEdge.second());
          }
        }
      };
      addSourceEndpoint(found->second->firstNode);
      addSourceEndpoint(found->second->secondNode);
    }
    if (found->second->cutEdge.has_value()) {
      boundaryVertices.insert(found->second->cutEdge->first());
      boundaryVertices.insert(found->second->cutEdge->second());
    }
    if (found->second->trace.has_value()) {
      boundaryTraces.insert(*found->second->trace);
    }
  }
  for (const auto &trace : network.candidate_traces()) {
    if (boundaryTraces.count(trace.id) == 0U) continue;
    const auto port = std::find_if(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace.port; });
    if (port == network.singularity_ports().end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      failure.region = region.id;
      failure.singularity = trace.singularity;
      return failure;
    }
    boundaryVertices.insert(port->sourceVertex);
    if (diagnostics != nullptr) {
      tracePortBoundaryVertices.insert(port->sourceVertex);
    }
  }

  // A fragment that reaches the source mesh boundary must expose that same
  // mandatory parent edge on the region walk. This prevents the independent
  // mesh-boundary V_int exclusion below from masking an incomplete walk.
  for (const auto &faceKey : region.sourceFaces) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    for (const auto &sourceEdge : face->second.edges) {
      const auto incident = topology.incidentFaces.find(sourceEdge);
      if (incident == topology.incidentFaces.end() ||
          incident->second.size() != 1U) {
        continue;
      }
      const auto mandatory = std::find_if(
          network.mandatory_edges().begin(), network.mandatory_edges().end(),
          [&](const auto &candidate) {
            return candidate.sourceEdge == sourceEdge;
          });
      if (mandatory == network.mandatory_edges().end() ||
          boundaryMandatoryEdges.count(mandatory->id) == 0U) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::RegionOwnedBoundaryEdgeMissingFromWalk);
        failure.region = region.id;
        failure.sourceFace = faceKey;
        failure.sourceEdge = sourceEdge;
        if (mandatory != network.mandatory_edges().end()) {
          failure.networkEdge = mandatory->id;
        }
        return failure;
      }
    }
  }

  std::set<authority::SourceVertexId> meshBoundaryVertices;
  for (const auto &[sourceEdge, incident] : topology.incidentFaces) {
    if (incident.size() != 1U) continue;
    meshBoundaryVertices.insert(sourceEdge.first());
    meshBoundaryVertices.insert(sourceEdge.second());
  }

  std::set<authority::SourceVertexId> candidateVertices;
  std::set<authority::SourceVertexId> interiorVertices;
  const std::set<authority::SourceFaceTopologyKey> regionFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());
  for (const auto &faceKey : region.sourceFaces) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    const auto cutFace = fragmentCorners.find(faceKey);
    if (cutFace == fragmentCorners.end()) {
      candidateVertices.insert(face->second.vertices.begin(),
                               face->second.vertices.end());
      continue;
    }
    const auto fragment = cutFace->second.find(owningOrbit);
    if (fragment == cutFace->second.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionSourceFaceOwningFragmentMissing);
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    candidateVertices.insert(fragment->second.begin(), fragment->second.end());
  }

  for (const authority::SourceVertexId vertex : candidateVertices) {
    if (meshBoundaryVertices.count(vertex) != 0U ||
        boundaryVertices.count(vertex) != 0U) {
      continue;
    }
    const auto incident = topology.incidentFacesByVertex.find(vertex);
    if (incident == topology.incidentFacesByVertex.end() ||
        incident->second.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.region = region.id;
      failure.sourceVertex = vertex;
      return failure;
    }

    bool allOwned = true;
    for (const auto &incidentFace : incident->second) {
      const auto cutFace = fragmentCorners.find(incidentFace);
      if (cutFace == fragmentCorners.end()) {
        if (regionFaces.count(incidentFace) == 0U) allOwned = false;
        continue;
      }

      bool hasCornerOwner = false;
      bool ownedByRegion = false;
      bool ownedByOtherRegion = false;
      for (const auto &[orbit, corners] : cutFace->second) {
        if (corners.count(vertex) == 0U) continue;
        hasCornerOwner = true;
        if (orbit == owningOrbit) {
          ownedByRegion = true;
        } else {
          ownedByOtherRegion = true;
        }
      }
      if (!hasCornerOwner) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::RegionInteriorVertexCornerOwnerMissing);
        failure.region = region.id;
        failure.sourceFace = incidentFace;
        failure.sourceVertex = vertex;
        return failure;
      }
      if (!ownedByRegion || ownedByOtherRegion) allOwned = false;
    }
    if (allOwned) interiorVertices.insert(vertex);
  }
  certificate.vertexCount = interiorVertices.size();
  certificate.faceCount = fragments.size();
  // The validated single boundary walk and no-pinch condition give
  // V_boundary == E_boundary, so the boundary terms cancel from chi.
  certificate.eulerCharacteristic =
      static_cast<int>(certificate.vertexCount) -
      static_cast<int>(certificate.edgeCount) +
      static_cast<int>(certificate.faceCount);
  if (certificate.eulerCharacteristic != 1) {
    if (diagnostics != nullptr) {
      emit_fragment_euler_diagnostics(
          *diagnostics, region, owningOrbit, candidateVertices,
          mandatoryBoundaryEndpoints, tracePortBoundaryVertices,
          interiorVertices, certificate);
    }
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionEulerCharacteristicNotOne);
    failure.region = region.id;
    failure.eulerCharacteristic = certificate.eulerCharacteristic;
    failure.vertexCount = certificate.vertexCount;
    failure.edgeCount = certificate.edgeCount;
    failure.faceCount = certificate.faceCount;
    return failure;
  }
  return certificate;
}

using RegionCertificatesBuildResult =
    std::variant<std::vector<GlobalTopologyRegionDiscCertificate>,
                 GlobalTopologyPlanError>;

RegionCertificatesBuildResult build_region_certificates(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    const std::vector<GlobalTopologyNodeRotation> &rotations,
    const std::vector<GlobalTopologyArc> &arcs,
    const std::vector<GlobalTopologyRegion> &regions,
    const FragmentDiagnosticEvidence *diagnostics) {
  std::map<authority::NetworkArcId, const GlobalTopologyArc *> arcById;
  for (const auto &arc : arcs) {
    if (!arcById.emplace(arc.id, &arc).second) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.arc = arc.id;
      return failure;
    }
  }
  const FaceWalkBuildResult walkBuild = walk_graph_faces(arcs, rotations);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&walkBuild)) {
    return *failure;
  }
  const auto &walk = std::get<FaceWalkResult>(walkBuild);
  const FragmentCornerBuildResult cornerBuild =
      build_fragment_corner_incidence(topology, network, arcs, walk);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&cornerBuild)) {
    return *failure;
  }
  const auto &fragmentCorners =
      std::get<FragmentCornerIncidence>(cornerBuild);
  std::vector<GlobalTopologyRegionDiscCertificate> certificates;
  certificates.reserve(regions.size());
  for (const auto &region : regions) {
    const auto singularities = validate_region_interior_singularities(
        topology, network, region, arcById);
    if (const auto *failure =
            std::get_if<GlobalTopologyPlanError>(&singularities)) {
      return *failure;
    }
    if (const auto failure = validate_single_boundary_walk(region, arcById);
        failure.has_value()) {
      return *failure;
    }
    const auto orbit = region_orbit(region, walk);
    if (!orbit.has_value()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
      failure.region = region.id;
      return failure;
    }
    if (const auto pinch = validate_no_region_fragment_pinch(
            topology, network, rotations, walk, region, *orbit);
        pinch.has_value()) {
      return *pinch;
    }
    const auto built = build_region_certificate(
        topology, network, cutGraph, arcs, region, *orbit, arcById,
        std::get<std::vector<authority::FieldSingularityId>>(singularities),
        fragmentCorners, diagnostics);
    if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&built)) {
      return *failure;
    }
    certificates.push_back(std::get<GlobalTopologyRegionDiscCertificate>(built));
  }
  return certificates;
}

void canonicalize_candidate(GlobalTopologyPlanCandidate &candidate) {
  std::sort(candidate.arcs.begin(), candidate.arcs.end(), [](const auto &lhs,
                                                             const auto &rhs) {
    return lhs.id < rhs.id;
  });
  for (auto &rotation : candidate.rotations) {
    canonicalize_cycle(rotation.counterClockwise);
  }
  std::sort(candidate.rotations.begin(), candidate.rotations.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.node < rhs.node; });
  for (auto &region : candidate.regions) {
    canonicalize_cycle(region.boundary);
    std::sort(region.sourceFaces.begin(), region.sourceFaces.end());
  }
  std::sort(candidate.regions.begin(), candidate.regions.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.id < rhs.id; });
  for (auto &certificate : candidate.regionCertificates) {
    std::sort(certificate.boundarySingularities.begin(),
              certificate.boundarySingularities.end());
    certificate.boundarySingularities.erase(
        std::unique(certificate.boundarySingularities.begin(),
                    certificate.boundarySingularities.end()),
        certificate.boundarySingularities.end());
  }
  std::sort(candidate.regionCertificates.begin(), candidate.regionCertificates.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.region < rhs.region; });
}

std::uint64_t candidate_semantic_digest(
    const GlobalTopologyPlanCandidate &candidate,
    const FieldAlignedCurveNetwork &network) noexcept {
  std::uint64_t hash = kFnvOffset;
  hash_consume(hash, candidate.sourceDigest);
  hash_consume(hash, candidate.cutGraphDigest);
  // Deliberately consume only the gauge-invariant network identity. The exact
  // network/atlas provenance lives in candidate.networkDigest instead.
  hash_consume(hash, network.semantic_digest());
  hash_consume(hash, candidate.arcs.size());
  for (const auto &arc : candidate.arcs) {
    hash_id(hash, arc.id);
    hash_consume(hash, static_cast<std::uint64_t>(arc.kind));
    hash_id(hash, arc.firstNode);
    hash_id(hash, arc.secondNode);
    hash_consume(hash, arc.mandatoryEdge.has_value());
    if (arc.mandatoryEdge.has_value()) hash_id(hash, *arc.mandatoryEdge);
    hash_consume(hash, arc.trace.has_value());
    if (arc.trace.has_value()) hash_id(hash, *arc.trace);
    hash_consume(hash, arc.cutEdge.has_value());
    if (arc.cutEdge.has_value()) hash_edge(hash, *arc.cutEdge);
    hash_consume(hash, arc.firstSegment);
    hash_consume(hash, arc.onePastLastSegment);
    hash_consume(hash, arc.sourceFaces.size());
    for (const auto &face : arc.sourceFaces) hash_face(hash, face);
  }
  hash_consume(hash, candidate.rotations.size());
  for (const auto &rotation : candidate.rotations) {
    hash_id(hash, rotation.node);
    hash_consume(hash, rotation.counterClockwise.size());
    for (const auto incidence : rotation.counterClockwise) {
      hash_id(hash, incidence.arc);
      hash_consume(hash, static_cast<std::uint64_t>(incidence.orientation));
    }
  }
  hash_consume(hash, candidate.regions.size());
  for (const auto &region : candidate.regions) {
    hash_id(hash, region.id);
    hash_consume(hash, region.boundary.size());
    for (const auto incidence : region.boundary) {
      hash_id(hash, incidence.arc);
      hash_consume(hash, static_cast<std::uint64_t>(incidence.orientation));
    }
    hash_consume(hash, region.sourceFaces.size());
    for (const auto &face : region.sourceFaces) hash_face(hash, face);
  }
  hash_consume(hash, candidate.regionCertificates.size());
  for (const auto &certificate : candidate.regionCertificates) {
    hash_id(hash, certificate.region);
    hash_consume(hash, certificate.boundaryWalkCount);
    hash_consume(hash, certificate.sourceFacesConnected);
    hash_consume(hash, static_cast<std::uint64_t>(
                           static_cast<std::int64_t>(certificate.eulerCharacteristic)));
    hash_consume(hash, certificate.vertexCount);
    hash_consume(hash, certificate.edgeCount);
    hash_consume(hash, certificate.faceCount);
    hash_consume(hash, certificate.interiorSingularityFree);
    hash_consume(hash, certificate.boundarySingularities.size());
    for (const auto singularity : certificate.boundarySingularities) {
      hash_id(hash, singularity);
    }
  }
  return hash;
}

using CandidateBuildResult =
    std::variant<GlobalTopologyPlanCandidate, GlobalTopologyPlanError>;

CandidateBuildResult canonical_candidate(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph) {
  const auto topology =
      build_source_index(sourceFaces, sourceVertexCount, sourceAuthority);
  if (!topology.has_value() || network.source_digest() == 0U) {
    return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
  }
  if (!cutGraph.certificate().proves_cellularity() ||
      cutGraph.source_digest() != network.source_digest() ||
      cutGraph.network_digest() != network.semantic_digest()) {
    return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
  }
  const CutNodeBindingResult cutNodeBuild =
      build_cut_node_bindings(network, cutGraph);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&cutNodeBuild)) {
    return *failure;
  }
  const auto &cutNodes = std::get<CutNodeBindings>(cutNodeBuild);

  const ArcBuildResult arcBuild = build_arcs(network, cutGraph, cutNodes);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&arcBuild)) {
    return *failure;
  }
  const auto &arcs = std::get<std::vector<GlobalTopologyArc>>(arcBuild);
  const RotationBuildResult rotationBuild =
      build_rotation_system(*topology, network, cutNodes, arcs);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&rotationBuild)) {
    return *failure;
  }
  const auto &rotations =
      std::get<std::vector<GlobalTopologyNodeRotation>>(rotationBuild);
  const FaceWalkBuildResult faceWalk = walk_graph_faces(arcs, rotations);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&faceWalk)) {
    return *failure;
  }
  FragmentDiagnosticEvidence diagnosticEvidence;
  FragmentDiagnosticEvidence *diagnostics =
      fragment_diagnostics_enabled() ? &diagnosticEvidence : nullptr;
  const RegionBuildResult regionBuild =
      build_regions(*topology, sourceAuthority, network, cutGraph, arcs,
                    std::get<FaceWalkResult>(faceWalk), diagnostics);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&regionBuild)) {
    return *failure;
  }

  GlobalTopologyPlanCandidate candidate;
  candidate.arcs = arcs;
  candidate.rotations = rotations;
  candidate.regions = std::get<std::vector<GlobalTopologyRegion>>(regionBuild);
  const RegionCertificatesBuildResult certificateBuild =
      build_region_certificates(*topology, network, cutGraph, candidate.rotations,
                                candidate.arcs, candidate.regions, diagnostics);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&certificateBuild)) {
    return *failure;
  }
  candidate.regionCertificates =
      std::get<std::vector<GlobalTopologyRegionDiscCertificate>>(certificateBuild);
  candidate.sourceDigest = network.source_digest();
  candidate.networkDigest = network_binding_digest(network);
  candidate.cutGraphDigest = cutGraph.semantic_digest();
  canonicalize_candidate(candidate);
  return candidate;
}

std::optional<GlobalTopologyPlanError> validate_candidate_structure(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    GlobalTopologyPlanCandidate &candidate) {
  const auto topology =
      build_source_index(sourceFaces, sourceVertexCount, sourceAuthority);
  if (!topology.has_value() || candidate.sourceDigest != network.source_digest()) {
    return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
  }
  if (candidate.networkDigest != network_binding_digest(network)) {
    return error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
  }
  if (candidate.cutGraphDigest != cutGraph.semantic_digest() ||
      !cutGraph.certificate().proves_cellularity()) {
    return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
  }
  canonicalize_candidate(candidate);

  std::map<authority::NetworkArcId, const GlobalTopologyArc *> arcById;
  for (const auto &arc : candidate.arcs) {
    if (!arcById.emplace(arc.id, &arc).second) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.arc = arc.id;
      return failure;
    }
  }
  for (const auto &region : candidate.regions) {
    if (region.sourceFaces.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionCoversNoSourceFace);
      failure.region = region.id;
      return failure;
    }
    for (const auto incidence : region.boundary) {
      if (arcById.count(incidence.arc) == 0U) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
        failure.region = region.id;
        failure.arc = incidence.arc;
        return failure;
      }
    }
  }

  // sourceFaces is the public support key for one fragment in this region;
  // the owning orbit is implicit in the region boundary. A crossed source face
  // therefore appears in more than one region by design. Structural validation
  // checks total source support here, then the canonical reconstruction below
  // proves the exact (SourceFaceTopologyKey, orbit) fragment assignment.
  std::set<authority::SourceFaceTopologyKey> coveredFaces;
  for (const auto &region : candidate.regions) {
    for (const auto &face : region.sourceFaces) {
      if (topology->faces.count(face) == 0U) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        failure.sourceFace = face;
        return failure;
      }
      coveredFaces.insert(face);
    }
  }
  for (const auto &[face, record] : topology->faces) {
    (void)record;
    if (coveredFaces.count(face) == 0U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned);
      failure.sourceFace = face;
      return failure;
    }
  }

  const CandidateBuildResult canonical = canonical_candidate(
      sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&canonical)) {
    return *failure;
  }
  GlobalTopologyPlanCandidate wanted =
      std::get<GlobalTopologyPlanCandidate>(canonical);
  canonicalize_candidate(wanted);

  bool canonicalRegionBoundaries =
      candidate.regions.size() == wanted.regions.size();
  if (canonicalRegionBoundaries) {
    for (std::size_t index = 0U; index < candidate.regions.size(); ++index) {
      if (candidate.regions[index].id != wanted.regions[index].id ||
          candidate.regions[index].boundary != wanted.regions[index].boundary) {
        canonicalRegionBoundaries = false;
        break;
      }
    }
  }
  if (canonicalRegionBoundaries) {
    for (std::size_t index = 0U; index < candidate.regions.size(); ++index) {
      // Exact canonical fragment ownership is part of the immutable construction
      // contract. The region identifies the orbit, so each sourceFaces element is
      // one (SourceFaceTopologyKey, orbit) fragment key.
      if (candidate.regions[index].sourceFaces !=
          wanted.regions[index].sourceFaces) {
        for (const auto &face : wanted.regions[index].sourceFaces) {
          if (!std::binary_search(candidate.regions[index].sourceFaces.begin(),
                                  candidate.regions[index].sourceFaces.end(),
                                  face)) {
            GlobalTopologyPlanError failure =
                error(GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned);
            failure.sourceFace = face;
            failure.region = wanted.regions[index].id;
            return failure;
          }
        }
        for (const auto &face : candidate.regions[index].sourceFaces) {
          if (!std::binary_search(wanted.regions[index].sourceFaces.begin(),
                                  wanted.regions[index].sourceFaces.end(),
                                  face)) {
            GlobalTopologyPlanError failure = error(
                GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
            failure.sourceFace = face;
            failure.region = candidate.regions[index].id;
            return failure;
          }
        }
        const auto duplicate = std::adjacent_find(
            candidate.regions[index].sourceFaces.begin(),
            candidate.regions[index].sourceFaces.end());
        if (duplicate != candidate.regions[index].sourceFaces.end()) {
          GlobalTopologyPlanError failure = error(
              GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
          failure.sourceFace = *duplicate;
          failure.region = candidate.regions[index].id;
          return failure;
        }
        return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      }
    }
  }

  const RegionCertificatesBuildResult certificateBuild =
      build_region_certificates(*topology, network, cutGraph, candidate.rotations,
                                candidate.arcs, candidate.regions, nullptr);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&certificateBuild)) {
    return *failure;
  }
  auto expectedCertificates =
      std::get<std::vector<GlobalTopologyRegionDiscCertificate>>(certificateBuild);
  std::sort(expectedCertificates.begin(), expectedCertificates.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.region < rhs.region; });
  if (candidate.regionCertificates.size() != expectedCertificates.size()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding);
    if (!candidate.regionCertificates.empty()) {
      failure.region = candidate.regionCertificates.front().region;
    } else if (!candidate.regions.empty()) {
      failure.region = candidate.regions.front().id;
    }
    return failure;
  }
  for (std::size_t index = 0U; index < expectedCertificates.size(); ++index) {
    if (candidate.regionCertificates[index] != expectedCertificates[index]) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding);
      failure.region = expectedCertificates[index].region;
      return failure;
    }
  }

  for (const auto &mandatory : network.mandatory_edges()) {
    std::vector<authority::NetworkArcId> pieces;
    for (const auto &candidateArc : candidate.arcs) {
      if (candidateArc.kind == GlobalTopologyArcKind::Mandatory &&
          candidateArc.mandatoryEdge == mandatory.id) {
        pieces.push_back(candidateArc.id);
      }
    }
    if (pieces.empty()) {
      GlobalTopologyPlanError failure = error(
          GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
      failure.networkEdge = mandatory.id;
      failure.sourceEdge = mandatory.sourceEdge;
      return failure;
    }
    for (const authority::NetworkArcId piece : pieces) {
      const bool represented = std::any_of(
          candidate.regions.begin(), candidate.regions.end(),
          [&](const auto &region) {
            return std::any_of(region.boundary.begin(), region.boundary.end(),
                               [&](const auto incidence) {
                                 return incidence.arc == piece;
                               });
          });
      if (!represented) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
        failure.networkEdge = mandatory.id;
        failure.sourceEdge = mandatory.sourceEdge;
        failure.arc = piece;
        return failure;
      }
    }
  }

  if (candidate.arcs != wanted.arcs) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
    if (!candidate.arcs.empty()) failure.arc = candidate.arcs.front().id;
    return failure;
  }
  if (candidate.rotations != wanted.rotations) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
    if (!candidate.rotations.empty()) {
      failure.arc = candidate.rotations.front().counterClockwise.empty()
                        ? std::optional<authority::NetworkArcId>{}
                        : std::optional<authority::NetworkArcId>{
                              candidate.rotations.front().counterClockwise.front().arc};
    }
    return failure;
  }
  if (candidate.regions.size() != wanted.regions.size()) {
    return error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
  }
  for (std::size_t index = 0U; index < candidate.regions.size(); ++index) {
    if (candidate.regions[index].id != wanted.regions[index].id ||
        candidate.regions[index].boundary != wanted.regions[index].boundary) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
      failure.region = candidate.regions[index].id;
      if (!candidate.regions[index].boundary.empty()) {
        failure.arc = candidate.regions[index].boundary.front().arc;
      }
      return failure;
    }
    // Exact canonical fragment ownership is part of the immutable construction
    // contract. The region identifies the orbit, so each sourceFaces element is
    // one (SourceFaceTopologyKey, orbit) fragment key.
    if (candidate.regions[index].sourceFaces !=
        wanted.regions[index].sourceFaces) {
      for (const auto &face : wanted.regions[index].sourceFaces) {
        if (!std::binary_search(candidate.regions[index].sourceFaces.begin(),
                                candidate.regions[index].sourceFaces.end(),
                                face)) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned);
          failure.sourceFace = face;
          failure.region = wanted.regions[index].id;
          return failure;
        }
      }
      for (const auto &face : candidate.regions[index].sourceFaces) {
        if (!std::binary_search(wanted.regions[index].sourceFaces.begin(),
                                wanted.regions[index].sourceFaces.end(),
                                face)) {
          GlobalTopologyPlanError failure = error(
              GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
          failure.sourceFace = face;
          failure.region = candidate.regions[index].id;
          return failure;
        }
      }
      const auto duplicate = std::adjacent_find(
          candidate.regions[index].sourceFaces.begin(),
          candidate.regions[index].sourceFaces.end());
      if (duplicate != candidate.regions[index].sourceFaces.end()) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
        failure.sourceFace = *duplicate;
        failure.region = candidate.regions[index].id;
        return failure;
      }
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
  }
  return std::nullopt;
}

} // namespace
} // namespace directional::geometry::global_topology_plan_detail

namespace directional::geometry {

GlobalTopologyPlanBuildResult GlobalTopologyPlan::make(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph) {
  const auto canonical = global_topology_plan_detail::canonical_candidate(
      sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&canonical)) {
    return GlobalTopologyPlanBuildResult(*failure);
  }
  return make_from_candidate(
      sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph,
      std::get<GlobalTopologyPlanCandidate>(canonical));
}

GlobalTopologyPlanBuildResult GlobalTopologyPlan::make_from_candidate(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network, const SurfaceCutGraph &cutGraph,
    GlobalTopologyPlanCandidate candidate) {
  if (const auto failure =
          global_topology_plan_detail::validate_candidate_structure(
              sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph,
              candidate);
      failure.has_value()) {
    return GlobalTopologyPlanBuildResult(*failure);
  }
  const std::uint64_t semanticDigest =
      global_topology_plan_detail::candidate_semantic_digest(candidate, network);
  return GlobalTopologyPlanBuildResult(GlobalTopologyPlan(
      std::move(candidate.arcs), std::move(candidate.rotations),
      std::move(candidate.regions), std::move(candidate.regionCertificates),
      candidate.sourceDigest, candidate.networkDigest, candidate.cutGraphDigest,
      semanticDigest));
}

const GlobalTopologyArc *
GlobalTopologyPlan::find_arc(const authority::NetworkArcId arc) const noexcept {
  const auto found = std::lower_bound(
      arcs_.begin(), arcs_.end(), arc,
      [](const GlobalTopologyArc &candidate, const authority::NetworkArcId id) {
        return candidate.id < id;
      });
  return found != arcs_.end() && found->id == arc ? &*found : nullptr;
}

const GlobalTopologyNodeRotation *GlobalTopologyPlan::find_rotation(
    const authority::NetworkNodeId node) const noexcept {
  const auto found = std::lower_bound(
      rotations_.begin(), rotations_.end(), node,
      [](const GlobalTopologyNodeRotation &candidate,
         const authority::NetworkNodeId id) { return candidate.node < id; });
  return found != rotations_.end() && found->node == node ? &*found : nullptr;
}

const GlobalTopologyRegionDiscCertificate *
GlobalTopologyPlan::find_region_certificate(
    const authority::NetworkRegionId region) const noexcept {
  const auto found = std::lower_bound(
      regionCertificates_.begin(), regionCertificates_.end(), region,
      [](const GlobalTopologyRegionDiscCertificate &candidate,
         const authority::NetworkRegionId id) { return candidate.region < id; });
  return found != regionCertificates_.end() && found->region == region
             ? &*found
             : nullptr;
}

GlobalTopologyPlanCandidate GlobalTopologyPlan::validation_candidate() const {
  return GlobalTopologyPlanCandidate{arcs_, rotations_, regions_,
                                     regionCertificates_, sourceDigest_,
                                     networkDigest_, cutGraphDigest_};
}

const char *global_topology_plan_error_code_name(
    const GlobalTopologyPlanErrorCode code) noexcept {
  switch (code) {
  case GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk:
    return "RegionBoundaryNotSingleWalk";
  case GlobalTopologyPlanErrorCode::RegionInteriorDisconnected:
    return "RegionInteriorDisconnected";
  case GlobalTopologyPlanErrorCode::RegionEulerCharacteristicNotOne:
    return "RegionEulerCharacteristicNotOne";
  case GlobalTopologyPlanErrorCode::RegionContainsInteriorSingularity:
    return "RegionContainsInteriorSingularity";
  case GlobalTopologyPlanErrorCode::RegionCoversNoSourceFace:
    return "RegionCoversNoSourceFace";
  case GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned:
    return "RegionSourceFaceUnowned";
  case GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned:
    return "RegionSourceFaceMultiplyOwned";
  case GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork:
    return "RegionBoundaryArcNotOwnedByNetwork";
  case GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary:
    return "MandatoryEdgeNotOnAnyRegionBoundary";
  case GlobalTopologyPlanErrorCode::RotationSystemInconsistent:
    return "RotationSystemInconsistent";
  case GlobalTopologyPlanErrorCode::InvalidNetworkBinding:
    return "InvalidNetworkBinding";
  case GlobalTopologyPlanErrorCode::InvalidSourceBinding:
    return "InvalidSourceBinding";
  case GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding:
    return "InvalidRegionCertificateBinding";
  case GlobalTopologyPlanErrorCode::EmbeddedGraphHasNoInteriorFace:
    return "EmbeddedGraphHasNoInteriorFace";
  case GlobalTopologyPlanErrorCode::RegionCutComponentCountDeficit:
    return "RegionCutComponentCountDeficit";
  case GlobalTopologyPlanErrorCode::TraceArcDoesNotSeparateItsSides:
    return "TraceArcDoesNotSeparateItsSides";
  case GlobalTopologyPlanErrorCode::SourceFaceCarriesMultipleTraceCuts:
    return "SourceFaceCarriesMultipleTraceCuts";
  case GlobalTopologyPlanErrorCode::TraceSegmentCarriersCoincide:
    return "TraceSegmentCarriersCoincide";
  case GlobalTopologyPlanErrorCode::TraceSegmentTurnNotAdmissible:
    return "TraceSegmentTurnNotAdmissible";
  case GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareMultipleCorners:
    return "TraceSegmentCarriersShareMultipleCorners";
  case GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareNoCorner:
    return "TraceSegmentCarriersShareNoCorner";
  case GlobalTopologyPlanErrorCode::SourcePortFaceAlreadyCarriesTraceChord:
    return "SourcePortFaceAlreadyCarriesTraceChord";
  case GlobalTopologyPlanErrorCode::TraceSourcePortCarrierNotAdmissible:
    return "TraceSourcePortCarrierNotAdmissible";
  case GlobalTopologyPlanErrorCode::SourceFaceCarriesTraceChordAndRays:
    return "SourceFaceCarriesTraceChordAndRays";
  case GlobalTopologyPlanErrorCode::RegionTraceSegmentCarriersCoincide:
    return "RegionTraceSegmentCarriersCoincide";
  case GlobalTopologyPlanErrorCode::RegionTraceSegmentTurnNotAdmissible:
    return "RegionTraceSegmentTurnNotAdmissible";
  case GlobalTopologyPlanErrorCode::RegionTraceSourcePortCarrierNotAdmissible:
    return "RegionTraceSourcePortCarrierNotAdmissible";
  case GlobalTopologyPlanErrorCode::TraceCutFaceFragmentCountMismatch:
    return "TraceCutFaceFragmentCountMismatch";
  case GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique:
    return "UncutFaceComponentOrbitSeedNotUnique";
  case GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitMissing:
    return "SourceFaceFragmentOrbitMissing";
  case GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitHasNoRegionDraft:
    return "SourceFaceFragmentOrbitHasNoRegionDraft";
  case GlobalTopologyPlanErrorCode::RegionSourceFaceOwningFragmentMissing:
    return "RegionSourceFaceOwningFragmentMissing";
  case GlobalTopologyPlanErrorCode::RegionInteriorVertexCornerOwnerMissing:
    return "RegionInteriorVertexCornerOwnerMissing";
  case GlobalTopologyPlanErrorCode::RegionBoundaryEvidenceMissing:
    return "RegionBoundaryEvidenceMissing";
  case GlobalTopologyPlanErrorCode::RegionElectedCutComponentEmpty:
    return "RegionElectedCutComponentEmpty";
  case GlobalTopologyPlanErrorCode::RegionFragmentPinchedAtVertex:
    return "RegionFragmentPinchedAtVertex";
  case GlobalTopologyPlanErrorCode::MandatoryEdgeTerminalOrderUnresolved:
    return "MandatoryEdgeTerminalOrderUnresolved";
  case GlobalTopologyPlanErrorCode::RegionOwnedBoundaryEdgeMissingFromWalk:
    return "RegionOwnedBoundaryEdgeMissingFromWalk";
  case GlobalTopologyPlanErrorCode::InvalidCutGraphBinding:
    return "InvalidCutGraphBinding";
  }
  return "Unknown";
}

std::uint64_t global_topology_plan_hash(
    const GlobalTopologyPlan &plan) noexcept {
  return plan.semantic_digest();
}

} // namespace directional::geometry
