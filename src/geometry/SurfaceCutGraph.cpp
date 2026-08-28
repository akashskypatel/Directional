// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/geometry/SurfaceCutGraph.h>

#include "SourceFaceComponentPartition.h"

#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <set>
#include <tuple>
#include <utility>

namespace directional::geometry {
namespace {

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

struct SourceFaceRecord {
  authority::SourceFaceTopologyKey key;
  std::array<authority::SourceVertexId, 3> vertices;
  std::array<authority::SourceEdgeTopologyKey, 3> edges;
};

struct SourceIndex {
  std::map<authority::SourceFaceTopologyKey, SourceFaceRecord> faces;
  std::map<authority::SourceEdgeTopologyKey,
           std::vector<authority::SourceFaceTopologyKey>>
      incidentFaces;
  std::set<authority::SourceVertexId> vertices;
};

std::optional<SourceIndex> build_source_index(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority) {
  if (!sourceAuthority.matches_source_faces(sourceFaces, sourceVertexCount)) {
    return std::nullopt;
  }
  SourceIndex result;
  for (int rowIndex = 0; rowIndex < sourceFaces.rows(); ++rowIndex) {
    const auto row = authority::SourceFaceId::from_index(
        rowIndex, static_cast<std::size_t>(sourceFaces.rows()));
    if (!row) return std::nullopt;
    std::array<authority::SourceVertexId, 3> vertices{
        authority::SourceVertexId::from_index(sourceFaces(rowIndex, 0),
                                               sourceVertexCount)
            .value(),
        authority::SourceVertexId::from_index(sourceFaces(rowIndex, 1),
                                               sourceVertexCount)
            .value(),
        authority::SourceVertexId::from_index(sourceFaces(rowIndex, 2),
                                               sourceVertexCount)
            .value()};
    const auto key = authority::SourceFaceTopologyKey::make(vertices);
    if (!key || key.value() != sourceAuthority.topology_for_row(row.value())) {
      return std::nullopt;
    }
    std::array<authority::SourceEdgeTopologyKey, 3> edges{
        authority::SourceEdgeTopologyKey::make(vertices[0], vertices[1]).value(),
        authority::SourceEdgeTopologyKey::make(vertices[1], vertices[2]).value(),
        authority::SourceEdgeTopologyKey::make(vertices[2], vertices[0]).value()};
    const SourceFaceRecord record{key.value(), vertices, edges};
    if (!result.faces.emplace(record.key, record).second) return std::nullopt;
    for (const auto vertex : vertices) result.vertices.insert(vertex);
    for (const auto &edge : edges) result.incidentFaces[edge].push_back(record.key);
  }
  for (auto &[edge, faces] : result.incidentFaces) {
    (void)edge;
    std::sort(faces.begin(), faces.end());
    faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
    if (faces.empty() || faces.size() > 2U) return std::nullopt;
  }
  return result;
}

std::set<authority::SourceEdgeTopologyKey>
network_barriers(const FieldAlignedCurveNetwork &network) {
  std::set<authority::SourceEdgeTopologyKey> result;
  for (const auto &edge : network.mandatory_edges()) result.insert(edge.sourceEdge);
  for (const auto &trace : network.candidate_traces()) {
    for (const auto &segment : trace.segments) {
      result.insert(segment.outgoingCarrier);
      if (segment.incomingCarrier.has_value()) result.insert(*segment.incomingCarrier);
    }
  }
  return result;
}

std::vector<std::vector<authority::SourceFaceTopologyKey>> build_components(
    const SourceIndex &topology,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  std::vector<authority::SourceFaceTopologyKey> faces;
  faces.reserve(topology.faces.size());
  for (const auto &[key, record] : topology.faces) {
    (void)record;
    faces.push_back(key);
  }
  return detail::build_source_face_component_partition(
             std::move(faces), topology.incidentFaces, barriers)
      .components;
}

struct CornerKey {
  authority::SourceFaceTopologyKey face;
  authority::SourceVertexId vertex;
  auto operator<=>(const CornerKey &) const = default;
};

std::optional<SurfaceCutGraphComponentCertificate> certify_component(
    const SourceIndex &topology,
    const std::vector<authority::SourceFaceTopologyKey> &component,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  if (component.empty()) return std::nullopt;
  std::set<authority::SourceFaceTopologyKey> members(component.begin(), component.end());
  std::vector<CornerKey> corners;
  std::map<CornerKey, std::size_t> cornerIndex;
  for (const auto &faceKey : component) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) return std::nullopt;
    for (const auto vertex : face->second.vertices) {
      const CornerKey key{faceKey, vertex};
      cornerIndex.emplace(key, corners.size());
      corners.push_back(key);
    }
  }
  std::vector<std::size_t> parent(corners.size());
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

  std::size_t gluedEdges = 0U;
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size() != 2U || barriers.count(edge) != 0U ||
        members.count(incident[0]) == 0U || members.count(incident[1]) == 0U) {
      continue;
    }
    ++gluedEdges;
    for (const auto vertex : {edge.first(), edge.second()}) {
      unite(cornerIndex.at(CornerKey{incident[0], vertex}),
            cornerIndex.at(CornerKey{incident[1], vertex}));
    }
  }

  std::set<std::size_t> roots;
  for (std::size_t index = 0U; index < corners.size(); ++index) {
    roots.insert(root(root, index));
  }
  const std::size_t faceCount = component.size();
  const std::size_t edgeCount = 3U * faceCount - gluedEdges;
  const std::size_t vertexCount = roots.size();

  std::map<std::size_t, std::multiset<std::size_t>> boundaryAdjacency;
  std::size_t boundaryEdgeCopies = 0U;
  for (const auto &faceKey : component) {
    const auto &face = topology.faces.at(faceKey);
    for (const auto &edge : face.edges) {
      const auto incident = topology.incidentFaces.find(edge);
      if (incident == topology.incidentFaces.end()) return std::nullopt;
      const bool glued = incident->second.size() == 2U &&
                         barriers.count(edge) == 0U &&
                         members.count(incident->second[0]) != 0U &&
                         members.count(incident->second[1]) != 0U;
      if (glued) continue;
      const std::size_t first = root(root, cornerIndex.at(CornerKey{faceKey, edge.first()}));
      const std::size_t second = root(root, cornerIndex.at(CornerKey{faceKey, edge.second()}));
      if (first == second) return std::nullopt;
      boundaryAdjacency[first].insert(second);
      boundaryAdjacency[second].insert(first);
      ++boundaryEdgeCopies;
    }
  }

  std::size_t boundaryWalkCount = 0U;
  bool boundaryCyclesValid = boundaryEdgeCopies != 0U;
  for (const auto &[vertex, adjacent] : boundaryAdjacency) {
    (void)vertex;
    if (adjacent.size() != 2U) boundaryCyclesValid = false;
  }
  if (boundaryCyclesValid) {
    std::set<std::size_t> visited;
    for (const auto &[start, adjacent] : boundaryAdjacency) {
      (void)adjacent;
      if (visited.count(start) != 0U) continue;
      ++boundaryWalkCount;
      std::vector<std::size_t> stack{start};
      while (!stack.empty()) {
        const std::size_t current = stack.back();
        stack.pop_back();
        if (!visited.insert(current).second) continue;
        for (const std::size_t next : boundaryAdjacency.at(current)) {
          if (visited.count(next) == 0U) stack.push_back(next);
        }
      }
    }
  }

  SurfaceCutGraphComponentCertificate result;
  result.sourceFaces = component;
  result.boundaryWalkCount = boundaryCyclesValid ? boundaryWalkCount : 0U;
  result.sourceFacesConnected = true;
  result.eulerCharacteristic = static_cast<int>(vertexCount) -
                               static_cast<int>(edgeCount) +
                               static_cast<int>(faceCount);
  result.vertexCount = vertexCount;
  result.edgeCount = edgeCount;
  result.faceCount = faceCount;
  return result;
}

std::optional<std::set<authority::SourceEdgeTopologyKey>>
tree_cotree_cut_edges(
    const SourceIndex &topology,
    const std::vector<authority::SourceFaceTopologyKey> &component,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  if (component.empty()) return std::nullopt;

  std::map<authority::SourceFaceTopologyKey, std::size_t> faceIndex;
  for (std::size_t index = 0U; index < component.size(); ++index) {
    faceIndex.emplace(component[index], index);
  }

  std::vector<std::size_t> parent(component.size());
  std::iota(parent.begin(), parent.end(), 0U);
  const auto root = [&](const auto &self, const std::size_t value) -> std::size_t {
    return parent[value] == value ? value : self(self, parent[value]);
  };
  const auto unite = [&](const std::size_t first, const std::size_t second) {
    const std::size_t firstRoot = root(root, first);
    const std::size_t secondRoot = root(root, second);
    if (firstRoot == secondRoot) return false;
    if (firstRoot < secondRoot) parent[secondRoot] = firstRoot;
    else parent[firstRoot] = secondRoot;
    return true;
  };

  // Deterministic tree-cotree baseline. SourceEdgeTopologyKey order chooses a
  // dual spanning tree. Every remaining primal edge is the complementary
  // tree-cotree cut graph. The subsequent certificate is recomputed from
  // scratch; no construction argument is accepted as proof of cellularity.
  std::set<authority::SourceEdgeTopologyKey> cuts;
  std::size_t dualTreeEdges = 0U;
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size() != 2U || barriers.count(edge) != 0U) continue;
    const auto first = faceIndex.find(incident[0]);
    const auto second = faceIndex.find(incident[1]);
    if (first == faceIndex.end() || second == faceIndex.end()) continue;
    if (unite(first->second, second->second)) {
      ++dualTreeEdges;
    } else {
      cuts.insert(edge);
    }
  }
  if (dualTreeEdges + 1U != component.size()) return std::nullopt;
  return cuts;
}

std::size_t network_edge_count(const FieldAlignedCurveNetwork &network) {
  std::size_t result = network.mandatory_edges().size();
  std::map<authority::SourceEdgeTopologyKey, std::set<authority::NetworkNodeId>>
      mandatoryCuts;
  for (const auto &event : network.events()) {
    if (event.kind == FieldAlignedNetworkEventKind::MandatoryBarrierTermination &&
        event.sourceEdge.has_value()) {
      mandatoryCuts[*event.sourceEdge].insert(event.node);
    }
  }
  for (const auto &[edge, nodes] : mandatoryCuts) {
    if (network.find_mandatory_edge(edge) != nullptr) result += nodes.size();
  }
  for (const auto &trace : network.candidate_traces()) {
    std::set<authority::NetworkNodeId> nodes;
    const auto port = std::find_if(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace.port; });
    if (port != network.singularity_ports().end()) nodes.insert(port->node);
    for (const auto &event : network.events()) {
      if (std::any_of(event.incidences.begin(), event.incidences.end(),
                      [&](const auto &incidence) {
                        return incidence.trace == trace.id;
                      })) {
        nodes.insert(event.node);
      }
    }
    if (nodes.size() >= 2U) result += nodes.size() - 1U;
  }
  return result;
}

std::set<authority::SourceVertexId>
network_source_vertex_nodes(const FieldAlignedCurveNetwork &network) {
  std::set<authority::SourceVertexId> result;
  for (const auto &edge : network.mandatory_edges()) {
    result.insert(edge.sourceEdge.first());
    result.insert(edge.sourceEdge.second());
  }
  for (const auto &port : network.singularity_ports()) result.insert(port.sourceVertex);
  return result;
}

std::uint64_t candidate_hash(const SurfaceCutGraphCandidate &candidate) noexcept {
  std::uint64_t hash = kFnvOffset;
  hash_consume(hash, candidate.sourceDigest);
  hash_consume(hash, candidate.atlasDigest);
  hash_consume(hash, candidate.networkDigest);
  hash_consume(hash, candidate.cutEdges.size());
  for (const auto &edge : candidate.cutEdges) hash_edge(hash, edge);
  const auto &certificate = candidate.certificate;
  hash_consume(hash, certificate.vertexCount);
  hash_consume(hash, certificate.edgeCount);
  hash_consume(hash, certificate.faceCount);
  hash_consume(hash, static_cast<std::uint64_t>(certificate.eulerCharacteristic));
  hash_consume(hash,
               static_cast<std::uint64_t>(certificate.sourceEulerCharacteristic));
  hash_consume(hash, certificate.components.size());
  for (const auto &component : certificate.components) {
    hash_consume(hash, component.sourceFaces.size());
    for (const auto &face : component.sourceFaces) hash_face(hash, face);
    hash_consume(hash, component.boundaryWalkCount);
    hash_consume(hash, component.sourceFacesConnected ? 1U : 0U);
    hash_consume(hash, static_cast<std::uint64_t>(component.eulerCharacteristic));
    hash_consume(hash, component.vertexCount);
    hash_consume(hash, component.edgeCount);
    hash_consume(hash, component.faceCount);
  }
  return hash;
}

using CandidateResult = std::variant<SurfaceCutGraphCandidate, SurfaceCutGraphError>;

CandidateResult canonical_candidate(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const FieldAlignedCurveNetwork &network) {
  const auto topology = build_source_index(sourceFaces, sourceVertexCount,
                                           sourceAuthority);
  if (!topology.has_value()) return cut_error(SurfaceCutGraphErrorCode::InvalidSourceBinding);
  if (!fieldTransportAtlas.matches_source_faces(sourceFaces, sourceAuthority, sourceVertexCount) ||
      !fieldTransportAtlas.quadrangulability().established()) {
    return cut_error(SurfaceCutGraphErrorCode::InvalidAtlasBinding);
  }
  if (network.source_digest() != fieldTransportAtlas.quadrangulability().source_digest() ||
      network.atlas_digest() != authority::field_transport_atlas_hash(fieldTransportAtlas)) {
    return cut_error(SurfaceCutGraphErrorCode::InvalidNetworkBinding);
  }

  std::set<authority::SourceEdgeTopologyKey> barriers = network_barriers(network);
  for (const auto &edge : barriers) {
    if (topology->incidentFaces.count(edge) == 0U) {
      SurfaceCutGraphError failure = cut_error(SurfaceCutGraphErrorCode::InvalidNetworkBinding);
      failure.sourceEdge = edge;
      return failure;
    }
  }

  auto initialComponents = build_components(*topology, barriers);
  std::vector<SurfaceCutGraphComponentCertificate> initialCertificates;
  initialCertificates.reserve(initialComponents.size());
  bool alreadyCellular = true;
  for (const auto &component : initialComponents) {
    const auto certificate = certify_component(*topology, component, barriers);
    if (!certificate.has_value()) {
      return cut_error(SurfaceCutGraphErrorCode::NonManifoldSource);
    }
    alreadyCellular = alreadyCellular && certificate->proves_disc_topology();
    initialCertificates.push_back(*certificate);
  }

  std::set<authority::SourceEdgeTopologyKey> cuts;
  if (!alreadyCellular) {
    for (std::size_t componentIndex = 0U;
         componentIndex < initialComponents.size(); ++componentIndex) {
      if (initialCertificates[componentIndex].proves_disc_topology()) continue;
      const auto componentCuts = tree_cotree_cut_edges(
          *topology, initialComponents[componentIndex], barriers);
      if (!componentCuts.has_value() || componentCuts->empty()) {
        SurfaceCutGraphError failure =
            cut_error(SurfaceCutGraphErrorCode::CellularityNotEstablished);
        if (!initialComponents[componentIndex].empty()) {
          failure.sourceFace = initialComponents[componentIndex].front();
        }
        return failure;
      }
      cuts.insert(componentCuts->begin(), componentCuts->end());
    }
  }

  barriers.insert(cuts.begin(), cuts.end());
  const auto finalComponents = build_components(*topology, barriers);
  std::vector<SurfaceCutGraphComponentCertificate> finalCertificates;
  finalCertificates.reserve(finalComponents.size());
  for (const auto &component : finalComponents) {
    const auto certificate = certify_component(*topology, component, barriers);
    if (!certificate.has_value() || !certificate->proves_disc_topology()) {
      SurfaceCutGraphError failure =
          cut_error(SurfaceCutGraphErrorCode::CellularityNotEstablished);
      if (!component.empty()) failure.sourceFace = component.front();
      return failure;
    }
    finalCertificates.push_back(*certificate);
  }

  const int sourceEuler = static_cast<int>(topology->vertices.size()) -
                          static_cast<int>(topology->incidentFaces.size()) +
                          static_cast<int>(topology->faces.size());
  const std::size_t networkVertices = network.nodes().size();
  const std::size_t networkEdges = network_edge_count(network);
  const auto representedVertices = network_source_vertex_nodes(network);
  std::set<authority::SourceVertexId> addedVertices;
  for (const auto &edge : cuts) {
    if (representedVertices.count(edge.first()) == 0U) addedVertices.insert(edge.first());
    if (representedVertices.count(edge.second()) == 0U) addedVertices.insert(edge.second());
  }
  const std::size_t graphVertices = networkVertices + addedVertices.size();
  const std::size_t graphEdges = networkEdges + cuts.size();
  const std::size_t graphFaces = finalCertificates.size();

  SurfaceCutGraphCandidate result;
  result.cutEdges.assign(cuts.begin(), cuts.end());
  result.sourceDigest = network.source_digest();
  result.atlasDigest = network.atlas_digest();
  result.networkDigest = network.semantic_digest();
  result.certificate.vertexCount = graphVertices;
  result.certificate.edgeCount = graphEdges;
  result.certificate.faceCount = graphFaces;
  result.certificate.eulerCharacteristic =
      static_cast<int>(graphVertices) - static_cast<int>(graphEdges) +
      static_cast<int>(graphFaces);
  result.certificate.sourceEulerCharacteristic = sourceEuler;
  result.certificate.components = std::move(finalCertificates);

  if (!result.certificate.proves_cellularity()) {
    return cut_error(SurfaceCutGraphErrorCode::CellularityNotEstablished);
  }
  return result;
}

} // namespace

bool SurfaceCutGraphCellularityCertificate::proves_cellularity() const noexcept {
  return faceCount > 0U && eulerCharacteristic == sourceEulerCharacteristic &&
         !components.empty() &&
         std::all_of(components.begin(), components.end(), [](const auto &component) {
           return component.proves_disc_topology();
         });
}

SurfaceCutGraphBuildResult SurfaceCutGraph::make(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const FieldAlignedCurveNetwork &network) {
  const auto candidate = canonical_candidate(sourceFaces, sourceVertexCount,
                                             sourceAuthority,
                                             fieldTransportAtlas, network);
  if (const auto *failure = std::get_if<SurfaceCutGraphError>(&candidate)) {
    return SurfaceCutGraphBuildResult(*failure);
  }
  const auto &value = std::get<SurfaceCutGraphCandidate>(candidate);
  return SurfaceCutGraphBuildResult(SurfaceCutGraph(
      value.cutEdges, value.certificate, value.sourceDigest, value.atlasDigest,
      value.networkDigest, candidate_hash(value)));
}

SurfaceCutGraphBuildResult SurfaceCutGraph::make_from_candidate(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const FieldAlignedCurveNetwork &network, SurfaceCutGraphCandidate candidate) {
  const auto canonical = canonical_candidate(sourceFaces, sourceVertexCount,
                                             sourceAuthority,
                                             fieldTransportAtlas, network);
  if (const auto *failure = std::get_if<SurfaceCutGraphError>(&canonical)) {
    return SurfaceCutGraphBuildResult(*failure);
  }
  auto wanted = std::get<SurfaceCutGraphCandidate>(canonical);
  std::sort(candidate.cutEdges.begin(), candidate.cutEdges.end());
  candidate.cutEdges.erase(std::unique(candidate.cutEdges.begin(), candidate.cutEdges.end()),
                           candidate.cutEdges.end());
  if (candidate != wanted) {
    return SurfaceCutGraphBuildResult(
        cut_error(candidate.sourceDigest != wanted.sourceDigest
                      ? SurfaceCutGraphErrorCode::InvalidSourceBinding
                      : candidate.atlasDigest != wanted.atlasDigest
                            ? SurfaceCutGraphErrorCode::InvalidAtlasBinding
                            : candidate.networkDigest != wanted.networkDigest
                                  ? SurfaceCutGraphErrorCode::InvalidNetworkBinding
                                  : SurfaceCutGraphErrorCode::CellularityNotEstablished));
  }
  return SurfaceCutGraphBuildResult(SurfaceCutGraph(
      wanted.cutEdges, wanted.certificate, wanted.sourceDigest,
      wanted.atlasDigest, wanted.networkDigest, candidate_hash(wanted)));
}

const char *surface_cut_graph_error_code_name(
    const SurfaceCutGraphErrorCode code) noexcept {
  switch (code) {
  case SurfaceCutGraphErrorCode::InvalidSourceBinding:
    return "InvalidSourceBinding";
  case SurfaceCutGraphErrorCode::InvalidAtlasBinding:
    return "InvalidAtlasBinding";
  case SurfaceCutGraphErrorCode::InvalidNetworkBinding:
    return "InvalidNetworkBinding";
  case SurfaceCutGraphErrorCode::NonManifoldSource:
    return "NonManifoldSource";
  case SurfaceCutGraphErrorCode::CellularityNotEstablished:
    return "CellularityNotEstablished";
  }
  return "Unknown";
}

std::uint64_t surface_cut_graph_hash(const SurfaceCutGraph &graph) noexcept {
  return graph.semantic_digest();
}

} // namespace directional::geometry
