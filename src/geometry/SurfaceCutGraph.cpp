// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/geometry/SurfaceCutGraph.h>

#include "EmbeddedGraphTopology.h"
#include "SourceFaceComponentPartition.h"

#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <tuple>
#include <utility>

namespace directional::geometry {
namespace {

using embedded_graph_topology_detail::EmbeddedGraphTopology;
using embedded_graph_topology_detail::SourceTopologyIndex;

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void hash_consume(std::uint64_t &hash, const std::uint64_t value) noexcept {
  hash ^= value;
  hash *= kFnvPrime;
}

template <typename Id> void hash_id(std::uint64_t &hash, const Id id) noexcept {
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
  for (const auto vertex : face.vertices()) hash_id(hash, vertex);
}

SurfaceCutGraphError cut_error(const SurfaceCutGraphErrorCode code) {
  SurfaceCutGraphError result;
  result.code = code;
  return result;
}

SurfaceCutGraphError topology_error(const GlobalTopologyPlanError &error) {
  SurfaceCutGraphError result;
  result.originatingTopologyError = error.code;
  switch (error.code) {
  case GlobalTopologyPlanErrorCode::InvalidSourceBinding:
    result.code = SurfaceCutGraphErrorCode::InvalidSourceBinding;
    break;
  case GlobalTopologyPlanErrorCode::InvalidNetworkBinding:
  case GlobalTopologyPlanErrorCode::InvalidCutGraphBinding:
    result.code = SurfaceCutGraphErrorCode::InvalidNetworkBinding;
    break;
  default:
    result.code = SurfaceCutGraphErrorCode::CellularityNotEstablished;
    break;
  }
  result.sourceVertex = error.sourceVertex;
  result.sourceEdge = error.sourceEdge;
  result.sourceFace = error.sourceFace;
  result.singularity = error.singularity;
  result.secondSourceFace = error.secondSourceFace;
  result.originatingRotationSystemInconsistencyReason =
      error.rotationSystemInconsistencyReason;
  result.vertexTraceSecondaryParameterFailureReason =
      error.vertexTraceSecondaryParameterFailureReason;
  result.edgeTraceSecondaryRankFailureReason =
      error.edgeTraceSecondaryRankFailureReason;
  result.rotationTraceOrientation = error.rotationTraceOrientation;
  result.traceFirstSegment = error.traceFirstSegment;
  result.traceOnePastLastSegment = error.traceOnePastLastSegment;
  result.traceIncomingCarrier = error.traceIncomingCarrier;
  result.traceOutgoingCarrier = error.traceOutgoingCarrier;
  result.traceSegmentOrientation = error.traceSegmentOrientation;
  result.traceSegmentIndex = error.traceSegmentIndex;
  result.traceSegmentIsFirst = error.traceSegmentIsFirst;
  result.traceSourcePort = error.traceSourcePort;
  result.traceBoundCorner = error.traceBoundCorner;
  result.traceBoundCornerProvenance = error.traceBoundCornerProvenance;
  result.traceEntrySupport = error.traceEntrySupport;
  result.traceExitSupport = error.traceExitSupport;
  result.edgeTraceContactIndex = error.edgeTraceContactIndex;
  result.edgeTraceOtherCarrier = error.edgeTraceOtherCarrier;
  result.edgeTraceFaceCorners = error.edgeTraceFaceCorners;
  result.arc = error.arc;
  result.secondArc = error.secondArc;
  result.trace = error.trace;
  result.secondTrace = error.secondTrace;
  result.rotationPreviousRay = error.rotationPreviousRay;
  result.rotationCurrentRay = error.rotationCurrentRay;
  result.rotationFanCensus = error.rotationFanCensus;
  result.traceEventIndex = error.traceEventIndex;
  result.traceEventPositionFailureReason =
      error.traceEventPositionFailureReason;
  result.traceEventPositionPass = error.traceEventPositionPass;
  result.embeddedGraphEulerCensusComplete =
      error.embeddedGraphEulerCensusComplete;
  result.embeddedGraphNodeCount = error.embeddedGraphNodeCount;
  result.embeddedGraphArcCount = error.embeddedGraphArcCount;
  result.embeddedGraphFaceWalkOrbitCount =
      error.embeddedGraphFaceWalkOrbitCount;
  result.embeddedGraphComponentCount = error.embeddedGraphComponentCount;
  result.embeddedGraphSourceEulerCharacteristic =
      error.embeddedGraphSourceEulerCharacteristic;
  result.embeddedGraphEulerResidual = error.embeddedGraphEulerResidual;
  result.traceEventPositionCandidates.reserve(
      error.traceEventPositionCandidates.size());
  for (const TraceEventPositionCandidate &candidate :
       error.traceEventPositionCandidates) {
    result.traceEventPositionCandidates.push_back(
        SurfaceCutGraphTraceEventPositionCandidate{
            candidate.position, candidate.segmentIndex, candidate.carrier,
            candidate.carrierRole});
  }
  return result;
}

std::int64_t source_euler_characteristic(
    const SourceTopologyIndex &topology) {
  std::set<authority::SourceVertexId> vertices;
  for (const auto &[faceKey, face] : topology.faces) {
    (void)faceKey;
    vertices.insert(face.vertices.begin(), face.vertices.end());
  }
  return static_cast<std::int64_t>(vertices.size()) -
         static_cast<std::int64_t>(topology.incidentFaces.size()) +
         static_cast<std::int64_t>(topology.faces.size());
}

std::size_t diagnostic_graph_component_count(
    const std::size_t nodeCount,
    const std::vector<GlobalTopologyArc> &arcs) {
  if (nodeCount == 0U) return 0U;
  std::vector<std::size_t> parent(nodeCount);
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
  for (const auto &arc : arcs) unite(arc.firstNode.index(), arc.secondNode.index());
  std::set<std::size_t> roots;
  for (std::size_t node = 0U; node < nodeCount; ++node)
    roots.insert(root(root, node));
  return roots.size();
}

void annotate_failure_euler_census(
    SurfaceCutGraphError &failure, const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges) {
  using namespace embedded_graph_topology_detail;
  failure.embeddedGraphSourceEulerCharacteristic =
      source_euler_characteristic(topology);
  const auto cutNodeBuild = build_cut_node_bindings(network, cutEdges);
  if (std::holds_alternative<GlobalTopologyPlanError>(cutNodeBuild)) return;
  const auto &cutNodes = std::get<CutNodeBindings>(cutNodeBuild);
  failure.embeddedGraphNodeCount = cutNodes.combinedNodeExtent;
  const auto arcBuild = build_arcs(network, cutEdges, cutNodes);
  if (std::holds_alternative<GlobalTopologyPlanError>(arcBuild)) return;
  const auto &arcs = std::get<std::vector<GlobalTopologyArc>>(arcBuild);
  failure.embeddedGraphArcCount = arcs.size();
  failure.embeddedGraphComponentCount =
      diagnostic_graph_component_count(cutNodes.combinedNodeExtent, arcs);
  const auto rotationBuild = build_rotation_system(topology, network, cutNodes, arcs);
  if (std::holds_alternative<GlobalTopologyPlanError>(rotationBuild)) return;
  const auto &rotations =
      std::get<std::vector<GlobalTopologyNodeRotation>>(rotationBuild);
  const auto faceWalkBuild = walk_graph_faces(arcs, rotations);
  if (std::holds_alternative<GlobalTopologyPlanError>(faceWalkBuild)) return;
  const auto &faceWalk = std::get<FaceWalkResult>(faceWalkBuild);
  failure.embeddedGraphFaceWalkOrbitCount = faceWalk.orbits.size();
  failure.embeddedGraphEulerResidual =
      static_cast<std::int64_t>(cutNodes.combinedNodeExtent) -
      static_cast<std::int64_t>(arcs.size()) +
      static_cast<std::int64_t>(faceWalk.orbits.size()) -
      *failure.embeddedGraphSourceEulerCharacteristic;
  failure.embeddedGraphEulerCensusComplete = true;
}

bool exact_interior_parameter(const authority::ExactUnitParameter &parameter) {
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  return parameter.value > zero && parameter.value < one;
}

using TraceCrossingResult =
    std::variant<std::set<authority::SourceEdgeTopologyKey>, SurfaceCutGraphError>;

TraceCrossingResult trace_crossed_source_edges(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network) {
  std::set<authority::SourceEdgeTopologyKey> crossed;
  const auto validate_and_record = [&](
      const authority::FieldBoundaryPoint &point,
      const authority::SourceEdgeTopologyKey &expected,
      const authority::TraceId trace) -> std::optional<SurfaceCutGraphError> {
    if (point.edge != expected || topology.incidentFaces.count(expected) == 0U) {
      auto failure = cut_error(SurfaceCutGraphErrorCode::InvalidNetworkBinding);
      failure.sourceEdge = expected;
      return failure;
    }
    if (exact_interior_parameter(point.parameter)) crossed.insert(expected);
    (void)trace;
    return std::nullopt;
  };

  for (const auto &trace : network.candidate_traces()) {
    for (const auto &segment : trace.segments) {
      if (segment.incomingCarrier.has_value()) {
        if (const auto failure = validate_and_record(
                segment.entryPoint, *segment.incomingCarrier, trace.id);
            failure.has_value()) return *failure;
      }
      if (segment.edgeTransitExit.has_value()) {
        if (const auto failure = validate_and_record(
                *segment.edgeTransitExit, segment.outgoingCarrier, trace.id);
            failure.has_value()) return *failure;
      }
    }
    if (trace.terminalPoint.has_value()) {
      if (topology.incidentFaces.count(trace.terminalPoint->edge) == 0U) {
        auto failure = cut_error(SurfaceCutGraphErrorCode::InvalidNetworkBinding);
        failure.sourceEdge = trace.terminalPoint->edge;
        return failure;
      }
      if (exact_interior_parameter(trace.terminalPoint->parameter))
        crossed.insert(trace.terminalPoint->edge);
    }
  }
  return crossed;
}

std::set<authority::SourceEdgeTopologyKey> mandatory_source_edges(
    const FieldAlignedCurveNetwork &network) {
  std::set<authority::SourceEdgeTopologyKey> result;
  for (const auto &edge : network.mandatory_edges()) result.insert(edge.sourceEdge);
  return result;
}

std::vector<SurfaceCutCandidateEvidence> classify_cut_candidates(
    const SourceTopologyIndex &topology,
    const std::set<authority::SourceEdgeTopologyKey> &mandatory,
    const std::set<authority::SourceEdgeTopologyKey> &traceCrossed,
    const std::set<authority::SourceEdgeTopologyKey> &selected) {
  std::vector<SurfaceCutCandidateEvidence> result;
  result.reserve(topology.incidentFaces.size());
  for (const auto &[edge, incident] : topology.incidentFaces) {
    (void)incident;
    SurfaceCutCandidateClass classification = SurfaceCutCandidateClass::Admissible;
    if (mandatory.count(edge) != 0U)
      classification = SurfaceCutCandidateClass::MandatoryAlreadyPresent;
    else if (traceCrossed.count(edge) != 0U)
      classification = SurfaceCutCandidateClass::TraceInteriorCrossing;
    result.push_back({edge, classification, selected.count(edge) != 0U});
  }
  return result;
}

std::vector<std::vector<authority::SourceFaceTopologyKey>> proposal_components(
    const SourceTopologyIndex &topology,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  std::vector<authority::SourceFaceTopologyKey> faces;
  faces.reserve(topology.faces.size());
  for (const auto &[key, record] : topology.faces) { (void)record; faces.push_back(key); }
  return detail::build_source_face_component_partition(
             std::move(faces), topology.incidentFaces, barriers).components;
}

struct ProposalCornerKey {
  authority::SourceFaceTopologyKey face;
  authority::SourceVertexId vertex;
  auto operator<=>(const ProposalCornerKey &) const = default;
};

std::optional<bool> proposal_component_is_disc(
    const SourceTopologyIndex &topology,
    const std::vector<authority::SourceFaceTopologyKey> &component,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  if (component.empty()) return std::nullopt;
  const std::set<authority::SourceFaceTopologyKey> members(component.begin(), component.end());
  std::vector<ProposalCornerKey> corners;
  std::map<ProposalCornerKey, std::size_t> cornerIndex;
  for (const auto &faceKey : component) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) return std::nullopt;
    for (const auto vertex : face->second.vertices) {
      ProposalCornerKey key{faceKey, vertex}; cornerIndex.emplace(key, corners.size()); corners.push_back(key);
    }
  }
  std::vector<std::size_t> parent(corners.size()); std::iota(parent.begin(), parent.end(), 0U);
  const auto root=[&](const auto &self,std::size_t v)->std::size_t{return parent[v]==v?v:self(self,parent[v]);};
  const auto unite=[&](std::size_t a,std::size_t b){a=root(root,a);b=root(root,b);if(a==b)return;if(a<b)parent[b]=a;else parent[a]=b;};
  std::size_t gluedEdges=0U;
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size()!=2U || barriers.count(edge)!=0U || members.count(incident[0])==0U || members.count(incident[1])==0U) continue;
    ++gluedEdges;
    for (const auto vertex : {edge.first(), edge.second()})
      unite(cornerIndex.at({incident[0],vertex}), cornerIndex.at({incident[1],vertex}));
  }
  std::set<std::size_t> vertices;
  for(std::size_t i=0;i<corners.size();++i) vertices.insert(root(root,i));
  const std::size_t faceCount=component.size();
  const std::size_t edgeCount=3U*faceCount-gluedEdges;
  const int chi=static_cast<int>(vertices.size())-static_cast<int>(edgeCount)+static_cast<int>(faceCount);
  std::map<std::size_t,std::set<std::size_t>> boundaryAdjacency;
  for (const auto &faceKey : component) {
    const auto &face=topology.faces.at(faceKey);
    for (const auto &edge : face.edges) {
      const auto incident=topology.incidentFaces.find(edge); if(incident==topology.incidentFaces.end()) return std::nullopt;
      const bool glued=incident->second.size()==2U && barriers.count(edge)==0U && members.count(incident->second[0])!=0U && members.count(incident->second[1])!=0U;
      if(glued) continue;
      const auto first=root(root,cornerIndex.at({faceKey,edge.first()}));
      const auto second=root(root,cornerIndex.at({faceKey,edge.second()}));
      if(first==second) return false;
      boundaryAdjacency[first].insert(second); boundaryAdjacency[second].insert(first);
    }
  }
  if(boundaryAdjacency.empty()) return false;
  for(const auto &[vertex,adjacent]:boundaryAdjacency){(void)vertex;if(adjacent.size()!=2U)return false;}
  std::set<std::size_t> visited; std::size_t boundaryLoops=0U;
  for(const auto &[seed,adjacent]:boundaryAdjacency){(void)adjacent;if(visited.count(seed))continue;++boundaryLoops;std::vector<std::size_t> stack{seed};while(!stack.empty()){auto current=stack.back();stack.pop_back();if(!visited.insert(current).second)continue;for(auto next:boundaryAdjacency.at(current))if(!visited.count(next))stack.push_back(next);}}
  return chi==1 && boundaryLoops==1U;
}

std::optional<std::set<authority::SourceEdgeTopologyKey>> proposal_tree_cotree_cut_edges(
    const SourceTopologyIndex &topology,
    const std::vector<authority::SourceFaceTopologyKey> &component,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  if(component.empty()) return std::nullopt;
  std::map<authority::SourceFaceTopologyKey,std::size_t> faceIndex;
  for(std::size_t i=0;i<component.size();++i) faceIndex.emplace(component[i],i);
  std::vector<std::size_t> parent(component.size()); std::iota(parent.begin(),parent.end(),0U);
  const auto root=[&](const auto &self,std::size_t v)->std::size_t{return parent[v]==v?v:self(self,parent[v]);};
  const auto unite=[&](std::size_t a,std::size_t b){a=root(root,a);b=root(root,b);if(a==b)return false;if(a<b)parent[b]=a;else parent[a]=b;return true;};
  std::set<authority::SourceEdgeTopologyKey> cuts; std::size_t dualTreeEdges=0U;
  for(const auto &[edge,incident]:topology.incidentFaces){if(incident.size()!=2U||barriers.count(edge))continue;auto first=faceIndex.find(incident[0]);auto second=faceIndex.find(incident[1]);if(first==faceIndex.end()||second==faceIndex.end())continue;if(unite(first->second,second->second))++dualTreeEdges;else cuts.insert(edge);}
  if(dualTreeEdges+1U!=component.size()) return std::nullopt;
  return cuts;
}

using CertificateResult = std::variant<SurfaceCutGraphCellularityCertificate, SurfaceCutGraphError>;
using OwnershipBuildResult =
    std::variant<std::vector<SurfaceCutGraphSourceFaceOwnership>,
                 SurfaceCutGraphError>;

OwnershipBuildResult build_source_face_ownership(
    const EmbeddedGraphTopology &embedded,
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges,
    const std::set<std::size_t> &certificateFaceOrbits) {
  using namespace embedded_graph_topology_detail;
  using SourceFace = authority::SourceFaceTopologyKey;
  using SourceEdge = authority::SourceEdgeTopologyKey;

  std::map<SourceFace, std::set<std::size_t>> directOwners;
  std::map<std::pair<SourceFace, SourceEdge>, std::set<std::size_t>>
      directOwnersByEdgeSide;
  std::map<SourceFace, std::vector<SurfaceCutGraphTraceFragmentSideOwner>>
      traceSides;
  std::set<SourceFace> traceCutFaces;
  std::set<SourceEdge> barriers(cutEdges.begin(), cutEdges.end());

  const auto add_owner = [&](const SourceFace &face,
                             const std::optional<SourceEdge> &edge,
                             const std::size_t orbit) {
    if (certificateFaceOrbits.count(orbit) == 0U) return;
    directOwners[face].insert(orbit);
    if (edge.has_value()) {
      directOwnersByEdgeSide[{face, *edge}].insert(orbit);
    }
  };

  for (const GlobalTopologyArc &arc : embedded.arcs) {
    std::optional<SourceEdge> graphSourceEdge;
    if (arc.kind == GlobalTopologyArcKind::Mandatory &&
        arc.mandatoryEdge.has_value()) {
      const auto *mandatory = find_mandatory(network, *arc.mandatoryEdge);
      if (mandatory != nullptr) graphSourceEdge = mandatory->sourceEdge;
    } else if (arc.kind == GlobalTopologyArcKind::Cut && arc.cutEdge.has_value()) {
      graphSourceEdge = arc.cutEdge;
    }

    if (graphSourceEdge.has_value()) {
      barriers.insert(*graphSourceEdge);
      const auto incident = embedded.sourceTopology.incidentFaces.find(*graphSourceEdge);
      if (incident == embedded.sourceTopology.incidentFaces.end()) continue;
      for (const SourceFace &faceKey : incident->second) {
        const auto face = embedded.sourceTopology.faces.find(faceKey);
        if (face == embedded.sourceTopology.faces.end()) continue;
        const bool forward = face_orients_edge_forward(face->second, *graphSourceEdge);
        const std::size_t interiorDart =
            2U * arc.id.index() + (forward ? 0U : 1U);
        if (interiorDart >= embedded.faceWalk.orbitByDart.size()) continue;
        add_owner(faceKey, graphSourceEdge,
                  embedded.faceWalk.orbitByDart[interiorDart]);
      }
      continue;
    }

    if (arc.kind != GlobalTopologyArcKind::Trace || !arc.trace.has_value()) continue;
    const auto *trace = find_trace(network, *arc.trace);
    if (trace == nullptr || arc.firstSegment >= arc.onePastLastSegment ||
        arc.onePastLastSegment > trace->segments.size()) {
      continue;
    }
    const std::size_t forwardDart =
        dart_index(GlobalTopologyOrientedArc{arc.id, authority::Orientation::Forward});
    const std::size_t reverseDart =
        dart_index(GlobalTopologyOrientedArc{arc.id, authority::Orientation::Reverse});
    if (forwardDart >= embedded.faceWalk.orbitByDart.size() ||
        reverseDart >= embedded.faceWalk.orbitByDart.size()) {
      continue;
    }
    const std::size_t forwardOrbit = embedded.faceWalk.orbitByDart[forwardDart];
    const std::size_t reverseOrbit = embedded.faceWalk.orbitByDart[reverseDart];

    for (std::size_t segmentIndex = arc.firstSegment;
         segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
      const auto &segment = trace->segments[segmentIndex];
      const bool terminalSlit = !trace->terminalBarrier.has_value() &&
                                segmentIndex + 1U == trace->segments.size();
      if (terminalSlit) continue;
      const auto faceIt = embedded.sourceTopology.faces.find(segment.sourceFace);
      if (faceIt == embedded.sourceTopology.faces.end()) continue;

      traceCutFaces.insert(segment.sourceFace);
      barriers.insert(segment.outgoingCarrier);
      if (segment.incomingCarrier.has_value()) barriers.insert(*segment.incomingCarrier);

      add_owner(segment.sourceFace, std::nullopt, forwardOrbit);
      add_owner(segment.sourceFace, std::nullopt, reverseOrbit);
      if (certificateFaceOrbits.count(forwardOrbit) != 0U) {
        traceSides[segment.sourceFace].push_back(
            SurfaceCutGraphTraceFragmentSideOwner{
                trace->id, segmentIndex, authority::Orientation::Forward,
                forwardOrbit});
      }
      if (certificateFaceOrbits.count(reverseOrbit) != 0U) {
        traceSides[segment.sourceFace].push_back(
            SurfaceCutGraphTraceFragmentSideOwner{
                trace->id, segmentIndex, authority::Orientation::Reverse,
                reverseOrbit});
      }

      if (segment.incomingCarrier.has_value()) {
        const auto incoming = local_edge_index(faceIt->second, *segment.incomingCarrier);
        const auto outgoing = local_edge_index(faceIt->second, segment.outgoingCarrier);
        if (!incoming.has_value() || !outgoing.has_value() || *incoming == *outgoing)
          continue;
        const std::size_t turn = (*outgoing + 3U - *incoming) % 3U;
        if (turn != 1U && turn != 2U) continue;
        std::size_t third = 0U;
        while (third == *incoming || third == *outgoing) ++third;
        add_owner(segment.sourceFace, faceIt->second.edges[third],
                  turn == 1U ? forwardOrbit : reverseOrbit);
        continue;
      }

      const auto entrySupport = segment.entryPoint.source_support();
      if (!entrySupport.has_value()) continue;
      const auto *entryVertex =
          std::get_if<authority::SourceVertexSupport>(&*entrySupport);
      if (entryVertex == nullptr) continue;
      std::optional<std::size_t> sourceCorner;
      for (std::size_t corner = 0U; corner < faceIt->second.vertices.size(); ++corner) {
        if (faceIt->second.vertices[corner] == entryVertex->vertex) {
          sourceCorner = corner;
          break;
        }
      }
      const auto outgoing = local_edge_index(faceIt->second, segment.outgoingCarrier);
      if (!sourceCorner.has_value() || !outgoing.has_value() ||
          *outgoing != (*sourceCorner + 1U) % 3U) {
        continue;
      }
      add_owner(segment.sourceFace,
                faceIt->second.edges[(*sourceCorner + 2U) % 3U], forwardOrbit);
      add_owner(segment.sourceFace, faceIt->second.edges[*sourceCorner],
                reverseOrbit);
    }
  }

  std::vector<SourceFace> uncutFaces;
  uncutFaces.reserve(embedded.sourceTopology.faces.size());
  for (const auto &[faceKey, record] : embedded.sourceTopology.faces) {
    (void)record;
    if (traceCutFaces.count(faceKey) == 0U) uncutFaces.push_back(faceKey);
  }
  const auto partition = detail::build_source_face_component_partition(
      uncutFaces, embedded.sourceTopology.incidentFaces, barriers);

  for (std::size_t component = 0U; component < partition.components.size(); ++component) {
    const auto &faces = partition.components[component];
    std::set<std::size_t> owners;
    for (const SourceFace &face : faces) {
      const auto direct = directOwners.find(face);
      if (direct != directOwners.end()) {
        owners.insert(direct->second.begin(), direct->second.end());
      }
    }
    for (const auto &[edge, incident] : embedded.sourceTopology.incidentFaces) {
      if (barriers.count(edge) != 0U || incident.size() != 2U) continue;
      std::optional<std::size_t> componentSide;
      for (std::size_t side = 0U; side < incident.size(); ++side) {
        const auto found = partition.componentByFace.find(incident[side]);
        if (found != partition.componentByFace.end() && found->second == component) {
          componentSide = side;
          break;
        }
      }
      if (!componentSide.has_value()) continue;
      const SourceFace &other = incident[*componentSide ^ 1U];
      if (traceCutFaces.count(other) == 0U) continue;
      const auto sideOwner = directOwnersByEdgeSide.find({other, edge});
      if (sideOwner != directOwnersByEdgeSide.end() && sideOwner->second.size() == 1U) {
        owners.insert(*sideOwner->second.begin());
      }
    }
    if (owners.size() != 1U) {
      SurfaceCutGraphError failure =
          cut_error(SurfaceCutGraphErrorCode::SourceFaceOwnershipNotEstablished);
      if (!faces.empty()) failure.sourceFace = faces.front();
      return failure;
    }
    for (const SourceFace &face : faces) directOwners[face] = owners;
  }

  std::vector<SurfaceCutGraphSourceFaceOwnership> result;
  result.reserve(embedded.sourceTopology.faces.size());
  for (const auto &[faceKey, record] : embedded.sourceTopology.faces) {
    (void)record;
    const auto found = directOwners.find(faceKey);
    if (found == directOwners.end() || found->second.empty()) {
      SurfaceCutGraphError failure =
          cut_error(SurfaceCutGraphErrorCode::SourceFaceOwnershipNotEstablished);
      failure.sourceFace = faceKey;
      return failure;
    }
    SurfaceCutGraphSourceFaceOwnership owner;
    owner.sourceFace = faceKey;
    owner.certifiedFaceOrbits.assign(found->second.begin(), found->second.end());
    const auto sides = traceSides.find(faceKey);
    if (sides != traceSides.end()) owner.traceFragmentSides = sides->second;
    std::sort(owner.traceFragmentSides.begin(), owner.traceFragmentSides.end());
    owner.traceFragmentSides.erase(
        std::unique(owner.traceFragmentSides.begin(), owner.traceFragmentSides.end()),
        owner.traceFragmentSides.end());
    if (traceCutFaces.count(faceKey) == 0U && owner.certifiedFaceOrbits.size() != 1U) {
      SurfaceCutGraphError failure =
          cut_error(SurfaceCutGraphErrorCode::SourceFaceOwnershipNotEstablished);
      failure.sourceFace = faceKey;
      return failure;
    }
    result.push_back(std::move(owner));
  }
  return result;
}

CertificateResult certify_actual_embedded_graph(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges,
    const std::vector<SurfaceCutCandidateEvidence> &cutCandidates) {
  using namespace embedded_graph_topology_detail;
  const auto embeddedBuild=build_embedded_graph_topology(sourceFaces,sourceVertexCount,sourceAuthority,network,cutEdges);
  if(const auto *failure=std::get_if<GlobalTopologyPlanError>(&embeddedBuild)) return topology_error(*failure);
  const auto &embedded=std::get<EmbeddedGraphTopology>(embeddedBuild);
  const auto exteriorBuild=exterior_boundary_orbits(embedded.sourceTopology,network,embedded.arcs,embedded.faceWalk);
  if(const auto *failure=std::get_if<GlobalTopologyPlanError>(&exteriorBuild)) return topology_error(*failure);
  const auto &exterior=std::get<std::set<std::size_t>>(exteriorBuild);
  const auto boundaryLoops=source_boundary_loop_count(embedded.sourceTopology);
  if(!boundaryLoops.has_value()) return cut_error(SurfaceCutGraphErrorCode::NonManifoldSource);
  std::set<authority::SourceVertexId> sourceVertices; std::set<authority::SourceComponentId> sourceComponents;
  for(const auto &[faceKey,face]:embedded.sourceTopology.faces){(void)faceKey;sourceComponents.insert(face.component);sourceVertices.insert(face.vertices.begin(),face.vertices.end());}
  const std::size_t graphComponents=actual_graph_component_count(embedded), sourceComponentCount=sourceComponents.size(), totalOrbits=embedded.faceWalk.orbits.size();
  if(exterior.size()>totalOrbits) return cut_error(SurfaceCutGraphErrorCode::CellularityNotEstablished);
  const std::size_t countedFaces=totalOrbits-exterior.size();
  const int correction=graphComponents>=sourceComponentCount?static_cast<int>(graphComponents-sourceComponentCount):0;
  const int sourceEuler=static_cast<int>(sourceVertices.size())-static_cast<int>(embedded.sourceTopology.incidentFaces.size())+static_cast<int>(embedded.sourceTopology.faces.size());
  const int graphEuler=static_cast<int>(embedded.cutNodes.combinedNodeExtent)-static_cast<int>(embedded.arcs.size())+static_cast<int>(countedFaces)-correction;
  const bool discEmbeddingEstablished=graphComponents==sourceComponentCount && exterior.size()==*boundaryLoops && graphEuler==sourceEuler;
  SurfaceCutGraphCellularityCertificate certificate;
  certificate.vertexCount=embedded.cutNodes.combinedNodeExtent; certificate.edgeCount=embedded.arcs.size(); certificate.totalOrbitCount=totalOrbits; certificate.excludedBoundaryOrbitCount=exterior.size(); certificate.sourceBoundaryLoopCount=*boundaryLoops; certificate.faceCount=countedFaces; certificate.graphComponentCount=graphComponents; certificate.sourceComponentCount=sourceComponentCount; certificate.disconnectedComponentCorrection=correction; certificate.eulerCharacteristic=graphEuler; certificate.sourceEulerCharacteristic=sourceEuler; certificate.cutCandidates=cutCandidates;
  certificate.faces.reserve(countedFaces);
  for(std::size_t orbit=0;orbit<totalOrbits;++orbit){if(exterior.count(orbit))continue;certificate.faces.push_back({orbit,1U,embedded.faceWalk.orbits[orbit].size(),discEmbeddingEstablished});}
  certificate.sourceFaceCount = embedded.sourceTopology.faces.size();
  if (discEmbeddingEstablished) {
    std::set<std::size_t> certificateFaceOrbits;
    for (const auto &face : certificate.faces) certificateFaceOrbits.insert(face.orbit);
    const auto ownershipBuild = build_source_face_ownership(
        embedded, network, cutEdges, certificateFaceOrbits);
    if (const auto *failure = std::get_if<SurfaceCutGraphError>(&ownershipBuild))
      return *failure;
    certificate.sourceFaceOwners =
        std::get<std::vector<SurfaceCutGraphSourceFaceOwnership>>(ownershipBuild);
  }
  return certificate;
}

std::uint64_t candidate_hash(const SurfaceCutGraphCandidate &candidate) noexcept {
  std::uint64_t hash=kFnvOffset; hash_consume(hash,candidate.sourceDigest);hash_consume(hash,candidate.atlasDigest);hash_consume(hash,candidate.networkDigest);hash_consume(hash,candidate.cutEdges.size());for(const auto &edge:candidate.cutEdges)hash_edge(hash,edge);
  const auto &c=candidate.certificate; hash_consume(hash,static_cast<std::uint64_t>(c.complex));hash_consume(hash,c.vertexCount);hash_consume(hash,c.edgeCount);hash_consume(hash,c.totalOrbitCount);hash_consume(hash,c.excludedBoundaryOrbitCount);hash_consume(hash,c.sourceBoundaryLoopCount);hash_consume(hash,c.faceCount);hash_consume(hash,c.graphComponentCount);hash_consume(hash,c.sourceComponentCount);hash_consume(hash,static_cast<std::uint64_t>(static_cast<std::int64_t>(c.disconnectedComponentCorrection)));hash_consume(hash,static_cast<std::uint64_t>(static_cast<std::int64_t>(c.eulerCharacteristic)));hash_consume(hash,static_cast<std::uint64_t>(static_cast<std::int64_t>(c.sourceEulerCharacteristic)));hash_consume(hash,c.saturationUsed?1U:0U);if(c.saturationLocus.has_value()){for(const auto vertex:c.saturationLocus->vertices())hash_id(hash,vertex);}else{hash_consume(hash,0U);}hash_consume(hash,c.saturationPromotedEdgeCount);hash_consume(hash,c.faces.size());for(const auto &face:c.faces){hash_consume(hash,face.orbit);hash_consume(hash,face.boundaryWalkCount);hash_consume(hash,face.boundaryArcCount);hash_consume(hash,face.discTopologyEstablished?1U:0U);}hash_consume(hash,c.sourceFaceCount);hash_consume(hash,c.sourceFaceOwners.size());for(const auto &owner:c.sourceFaceOwners){hash_face(hash,owner.sourceFace);hash_consume(hash,owner.certifiedFaceOrbits.size());for(const auto orbit:owner.certifiedFaceOrbits)hash_consume(hash,orbit);hash_consume(hash,owner.traceFragmentSides.size());for(const auto &side:owner.traceFragmentSides){hash_id(hash,side.trace);hash_consume(hash,side.segmentIndex);hash_consume(hash,static_cast<std::uint64_t>(side.orientation));hash_consume(hash,side.orbit);}}hash_consume(hash,c.cutCandidates.size());for(const auto &e:c.cutCandidates){hash_edge(hash,e.sourceEdge);hash_consume(hash,static_cast<std::uint64_t>(e.classification));hash_consume(hash,e.selected?1U:0U);}return hash;
}


std::uint64_t candidate_semantic_hash(
    const SurfaceCutGraphCandidate &candidate,
    const std::uint64_t networkSemanticDigest) noexcept {
  std::uint64_t hash = kFnvOffset;
  hash_consume(hash, candidate.sourceDigest);
  hash_consume(hash, networkSemanticDigest);
  hash_consume(hash, candidate.cutEdges.size());
  for (const auto &edge : candidate.cutEdges) hash_edge(hash, edge);

  const auto &certificate = candidate.certificate;
  hash_consume(hash, static_cast<std::uint64_t>(certificate.complex));
  hash_consume(hash, certificate.vertexCount);
  hash_consume(hash, certificate.edgeCount);
  hash_consume(hash, certificate.totalOrbitCount);
  hash_consume(hash, certificate.excludedBoundaryOrbitCount);
  hash_consume(hash, certificate.sourceBoundaryLoopCount);
  hash_consume(hash, certificate.faceCount);
  hash_consume(hash, certificate.graphComponentCount);
  hash_consume(hash, certificate.sourceComponentCount);
  hash_consume(hash, static_cast<std::uint64_t>(static_cast<std::int64_t>(
                         certificate.disconnectedComponentCorrection)));
  hash_consume(hash, static_cast<std::uint64_t>(
                         static_cast<std::int64_t>(certificate.eulerCharacteristic)));
  hash_consume(hash, static_cast<std::uint64_t>(static_cast<std::int64_t>(
                         certificate.sourceEulerCharacteristic)));
  hash_consume(hash, certificate.faces.size());
  for (const auto &face : certificate.faces) {
    // EmbeddedGraphTopology assigns NetworkArcId from a total sort over
    // semantic arc descriptors, then walk_graph_faces visits darts in that
    // canonical ID/orientation order. The orbit ordinal is therefore a
    // content-derived rank, not source-row, container, or gauge enumeration.
    // Proved by ordinal 359
    // SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration.
    hash_consume(hash, face.orbit);
    hash_consume(hash, face.boundaryWalkCount);
    hash_consume(hash, face.boundaryArcCount);
    hash_consume(hash, face.discTopologyEstablished ? 1U : 0U);
  }
  hash_consume(hash, certificate.sourceFaceCount);
  hash_consume(hash, certificate.sourceFaceOwners.size());
  for (const auto &owner : certificate.sourceFaceOwners) {
    hash_face(hash, owner.sourceFace);
    hash_consume(hash, owner.certifiedFaceOrbits.size());
    for (const auto orbit : owner.certifiedFaceOrbits) hash_consume(hash, orbit);
    hash_consume(hash, owner.traceFragmentSides.size());
    for (const auto &side : owner.traceFragmentSides) {
      hash_id(hash, side.trace);
      hash_consume(hash, side.segmentIndex);
      hash_consume(hash, static_cast<std::uint64_t>(side.orientation));
      hash_consume(hash, side.orbit);
    }
  }
  hash_consume(hash, certificate.cutCandidates.size());
  for (const auto &evidence : certificate.cutCandidates) {
    hash_edge(hash, evidence.sourceEdge);
    hash_consume(hash, static_cast<std::uint64_t>(evidence.classification));
    hash_consume(hash, evidence.selected ? 1U : 0U);
  }
  return hash;
}

using CandidateResult=std::variant<SurfaceCutGraphCandidate,SurfaceCutGraphError>;
CandidateResult canonical_candidate(const Eigen::MatrixXi &sourceFaces,const std::size_t sourceVertexCount,const SourceTopologyRegions &sourceAuthority,const authority::FieldTransportAtlas &fieldTransportAtlas,const FieldAlignedCurveNetwork &network){
  using namespace embedded_graph_topology_detail;
  const auto topology=build_source_index(sourceFaces,sourceVertexCount,sourceAuthority); if(!topology.has_value())return cut_error(SurfaceCutGraphErrorCode::InvalidSourceBinding);
  if(!fieldTransportAtlas.matches_source_faces(sourceFaces,sourceAuthority,sourceVertexCount)||!fieldTransportAtlas.quadrangulability().established())return cut_error(SurfaceCutGraphErrorCode::InvalidAtlasBinding);
  if(network.source_digest()!=fieldTransportAtlas.quadrangulability().source_digest()||network.atlas_digest()!=authority::field_transport_atlas_hash(fieldTransportAtlas))return cut_error(SurfaceCutGraphErrorCode::InvalidNetworkBinding);
  const auto mandatory=mandatory_source_edges(network); for(const auto &edge:mandatory)if(topology->incidentFaces.count(edge)==0U){auto failure=cut_error(SurfaceCutGraphErrorCode::InvalidNetworkBinding);failure.sourceEdge=edge;return failure;}
  const auto crossedBuild=trace_crossed_source_edges(*topology,network);if(const auto *failure=std::get_if<SurfaceCutGraphError>(&crossedBuild))return *failure;const auto &traceCrossed=std::get<std::set<authority::SourceEdgeTopologyKey>>(crossedBuild);
  std::set<authority::SourceEdgeTopologyKey> cuts;
  bool saturationUsed=false;std::optional<authority::SourceFaceTopologyKey> saturationLocus;std::size_t saturationPromotedEdgeCount=0U;
  std::size_t certificationAttemptIndex = 0U;
  while(true){const auto evidence=classify_cut_candidates(*topology,mandatory,traceCrossed,cuts);const auto certificateBuild=certify_actual_embedded_graph(sourceFaces,sourceVertexCount,sourceAuthority,network,{cuts.begin(),cuts.end()},evidence);if(const auto *failure=std::get_if<SurfaceCutGraphError>(&certificateBuild)){auto result=*failure;annotate_failure_euler_census(result,*topology,network,{cuts.begin(),cuts.end()});result.cutCandidates=evidence;result.certificationAttemptIndex=certificationAttemptIndex;result.certificationCutEdgeCount=cuts.size();return result;}auto certificate=std::get<SurfaceCutGraphCellularityCertificate>(certificateBuild);if(certificate.proves_cellularity()){certificate.saturationUsed=saturationUsed;certificate.saturationLocus=saturationLocus;certificate.saturationPromotedEdgeCount=saturationPromotedEdgeCount;SurfaceCutGraphCandidate result;result.cutEdges.assign(cuts.begin(),cuts.end());result.certificate=std::move(certificate);result.sourceDigest=network.source_digest();result.atlasDigest=network.atlas_digest();result.networkDigest=network.semantic_digest();return result;}
    ++certificationAttemptIndex;
    std::set<authority::SourceEdgeTopologyKey> barriers=mandatory;barriers.insert(traceCrossed.begin(),traceCrossed.end());barriers.insert(cuts.begin(),cuts.end());const auto components=proposal_components(*topology,barriers);bool added=false;std::optional<authority::SourceFaceTopologyKey> blockedLocus;std::vector<std::vector<authority::SourceFaceTopologyKey>> nonDiscComponents;
    for(const auto &component:components){const auto disc=proposal_component_is_disc(*topology,component,barriers);if(!disc.has_value())return cut_error(SurfaceCutGraphErrorCode::NonManifoldSource);if(*disc)continue;nonDiscComponents.push_back(component);if(!component.empty()&&!blockedLocus.has_value())blockedLocus=component.front();const auto proposed=proposal_tree_cotree_cut_edges(*topology,component,barriers);if(!proposed.has_value())continue;for(const auto &edge:*proposed){if(mandatory.count(edge))continue;added=cuts.insert(edge).second||added;}}
    if(added)continue;

    // The source-face barrier partition is only a conservative proposal
    // heuristic. If it cannot propose progress, saturate the offending
    // components with every remaining source edge that is not already a graph
    // arc. This includes exact trace-crossed edges under Amendment 14. The
    // subsequent actual-complex certificate, not this heuristic, is authority.
    std::set<authority::SourceFaceTopologyKey> nonDiscFaces;
    for(const auto &component:nonDiscComponents)nonDiscFaces.insert(component.begin(),component.end());
    std::vector<authority::SourceEdgeTopologyKey> saturationEdges;
    for(const auto &[edge,incident]:topology->incidentFaces){
      if(mandatory.count(edge)||cuts.count(edge))continue;
      const bool touches=nonDiscFaces.empty()||std::any_of(incident.begin(),incident.end(),[&](const auto face){return nonDiscFaces.count(face)!=0U;});
      if(touches)saturationEdges.push_back(edge);
    }
    if(!blockedLocus.has_value()&&!topology->faces.empty())blockedLocus=topology->faces.begin()->first;
    if(saturationEdges.empty()){auto failure=cut_error(SurfaceCutGraphErrorCode::CutSearchExhaustedBeforeCellularity);failure.sourceFace=blockedLocus;failure.nonDiscComponentCount=nonDiscComponents.size();failure.remainingAdmissibleEdgeCount=0U;failure.cutCandidates=evidence;return failure;}
    saturationUsed=true;if(!saturationLocus.has_value())saturationLocus=blockedLocus;std::size_t promoted=0U;for(const auto &edge:saturationEdges)promoted+=cuts.insert(edge).second?1U:0U;saturationPromotedEdgeCount+=promoted;
    if(promoted==0U){auto failure=cut_error(SurfaceCutGraphErrorCode::CutSearchExhaustedBeforeCellularity);failure.sourceFace=blockedLocus;failure.nonDiscComponentCount=nonDiscComponents.size();failure.remainingAdmissibleEdgeCount=saturationEdges.size();failure.cutCandidates=evidence;return failure;}
  }
}
} // namespace

bool SurfaceCutGraphCellularityCertificate::proves_cellularity() const noexcept {
  if (complex != SurfaceCutGraphComplexKind::ActualEmbeddedGraph ||
      faceCount == 0U || totalOrbitCount < excludedBoundaryOrbitCount ||
      sourceBoundaryLoopCount != excludedBoundaryOrbitCount ||
      graphComponentCount != sourceComponentCount ||
      eulerCharacteristic != sourceEulerCharacteristic || faces.empty() ||
      !std::all_of(faces.begin(), faces.end(),
                   [](const auto &face) { return face.proves_disc_topology(); })) {
    return false;
  }
  if (sourceFaceCount == 0U || sourceFaceOwners.size() != sourceFaceCount)
    return false;
  std::set<std::size_t> certifiedFaceOrbits;
  for (const auto &face : faces) certifiedFaceOrbits.insert(face.orbit);
  std::optional<authority::SourceFaceTopologyKey> previousFace;
  for (const auto &owner : sourceFaceOwners) {
    if (previousFace.has_value() && !(*previousFace < owner.sourceFace))
      return false;
    previousFace = owner.sourceFace;
    if (owner.certifiedFaceOrbits.empty()) return false;
    if (!owner.trace_crossed() && owner.certifiedFaceOrbits.size() != 1U)
      return false;
    for (const auto orbit : owner.certifiedFaceOrbits) {
      if (certifiedFaceOrbits.count(orbit) == 0U) return false;
    }
    for (const auto &side : owner.traceFragmentSides) {
      if (certifiedFaceOrbits.count(side.orbit) == 0U ||
          !std::binary_search(owner.certifiedFaceOrbits.begin(),
                              owner.certifiedFaceOrbits.end(), side.orbit)) {
        return false;
      }
    }
  }
  return true;
}

const SurfaceCutGraphSourceFaceOwnership *
SurfaceCutGraphCellularityCertificate::find_source_face_owner(
    const authority::SourceFaceTopologyKey &sourceFace) const noexcept {
  const auto found = std::lower_bound(
      sourceFaceOwners.begin(), sourceFaceOwners.end(), sourceFace,
      [](const SurfaceCutGraphSourceFaceOwnership &candidate,
         const authority::SourceFaceTopologyKey &key) {
        return candidate.sourceFace < key;
      });
  return found != sourceFaceOwners.end() && found->sourceFace == sourceFace
             ? &*found
             : nullptr;
}

SurfaceCutGraphBuildResult SurfaceCutGraph::make(const Eigen::MatrixXi &sourceFaces,const std::size_t sourceVertexCount,const SourceTopologyRegions &sourceAuthority,const authority::FieldTransportAtlas &fieldTransportAtlas,const FieldAlignedCurveNetwork &network){const auto candidate=canonical_candidate(sourceFaces,sourceVertexCount,sourceAuthority,fieldTransportAtlas,network);if(const auto *failure=std::get_if<SurfaceCutGraphError>(&candidate))return SurfaceCutGraphBuildResult(*failure);const auto &value=std::get<SurfaceCutGraphCandidate>(candidate);return SurfaceCutGraphBuildResult(SurfaceCutGraph(value.cutEdges,value.certificate,value.sourceDigest,value.atlasDigest,value.networkDigest,candidate_semantic_hash(value,network.semantic_digest()),candidate_hash(value)));}

SurfaceCutGraphBuildResult SurfaceCutGraph::make_from_candidate(const Eigen::MatrixXi &sourceFaces,const std::size_t sourceVertexCount,const SourceTopologyRegions &sourceAuthority,const authority::FieldTransportAtlas &fieldTransportAtlas,const FieldAlignedCurveNetwork &network,SurfaceCutGraphCandidate candidate){const auto canonical=canonical_candidate(sourceFaces,sourceVertexCount,sourceAuthority,fieldTransportAtlas,network);if(const auto *failure=std::get_if<SurfaceCutGraphError>(&canonical))return SurfaceCutGraphBuildResult(*failure);auto wanted=std::get<SurfaceCutGraphCandidate>(canonical);std::sort(candidate.cutEdges.begin(),candidate.cutEdges.end());candidate.cutEdges.erase(std::unique(candidate.cutEdges.begin(),candidate.cutEdges.end()),candidate.cutEdges.end());if(candidate!=wanted)return SurfaceCutGraphBuildResult(cut_error(candidate.sourceDigest!=wanted.sourceDigest?SurfaceCutGraphErrorCode::InvalidSourceBinding:candidate.atlasDigest!=wanted.atlasDigest?SurfaceCutGraphErrorCode::InvalidAtlasBinding:candidate.networkDigest!=wanted.networkDigest?SurfaceCutGraphErrorCode::InvalidNetworkBinding:SurfaceCutGraphErrorCode::CellularityNotEstablished));return SurfaceCutGraphBuildResult(SurfaceCutGraph(wanted.cutEdges,wanted.certificate,wanted.sourceDigest,wanted.atlasDigest,wanted.networkDigest,candidate_semantic_hash(wanted,network.semantic_digest()),candidate_hash(wanted)));}

const char *surface_cut_graph_error_code_name(const SurfaceCutGraphErrorCode code) noexcept {switch(code){case SurfaceCutGraphErrorCode::InvalidSourceBinding:return "InvalidSourceBinding";case SurfaceCutGraphErrorCode::InvalidAtlasBinding:return "InvalidAtlasBinding";case SurfaceCutGraphErrorCode::InvalidNetworkBinding:return "InvalidNetworkBinding";case SurfaceCutGraphErrorCode::NonManifoldSource:return "NonManifoldSource";case SurfaceCutGraphErrorCode::CellularityNotEstablished:return "CellularityNotEstablished";case SurfaceCutGraphErrorCode::CutSearchExhaustedBeforeCellularity:return "CutSearchExhaustedBeforeCellularity";case SurfaceCutGraphErrorCode::EmptyNetworkOnClosedSurface:return "EmptyNetworkOnClosedSurface";case SurfaceCutGraphErrorCode::SourceFaceOwnershipNotEstablished:return "SourceFaceOwnershipNotEstablished";}return "Unknown";}
const char *surface_cut_candidate_class_name(const SurfaceCutCandidateClass c) noexcept {switch(c){case SurfaceCutCandidateClass::Admissible:return "Admissible";case SurfaceCutCandidateClass::MandatoryAlreadyPresent:return "MandatoryAlreadyPresent";case SurfaceCutCandidateClass::TraceInteriorCrossing:return "TraceInteriorCrossing";}return "Unknown";}
const char *surface_cut_graph_complex_kind_name(const SurfaceCutGraphComplexKind kind) noexcept {switch(kind){case SurfaceCutGraphComplexKind::ActualEmbeddedGraph:return "actualEmbeddedGraph";}return "Unknown";}
std::uint64_t surface_cut_graph_hash(const SurfaceCutGraph &graph) noexcept {return graph.provenance_digest();}

} // namespace directional::geometry
