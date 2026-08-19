// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/authority/FieldTransportAtlas.h>

#include <algorithm>
#include <bit>
#include <cmath>
#include <exception>
#include <map>
#include <numbers>
#include <numeric>
#include <set>
#include <tuple>
#include <utility>

#include <Eigen/Sparse>

#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/SourceTopologyRegions.h>

namespace directional::authority {
namespace {

constexpr double kIntegerTolerance = 1.0e-6;

template <typename Id> Id make_id(const std::size_t value) {
  return Id::from_index(static_cast<std::int64_t>(value), value + 1U).value();
}

int normalized_quarter_turn(const int value) {
  const int result = value % 4;
  return result < 0 ? result + 4 : result;
}

FieldTransportAtlasBuildResult fail(
    const FieldAtlasBuildErrorCode code,
    std::optional<SourceEdgeTopologyKey> sourceEdge = std::nullopt,
    std::optional<SourceFaceId> sourceFace = std::nullopt,
    std::optional<SourceVertexId> sourceVertex = std::nullopt,
    std::optional<TopologyRegionId> topologyRegion = std::nullopt) {
  return FieldTransportAtlasBuildResult(FieldAtlasBuildError{
      code, std::move(sourceEdge), sourceFace, sourceVertex, topologyRegion});
}

const FieldTransportAdjacency *find_adjacency_in(
    const std::vector<FieldTransportAdjacency> &adjacencies,
    const SourceEdgeTopologyKey &edge) {
  const auto found = std::lower_bound(
      adjacencies.begin(), adjacencies.end(), edge,
      [](const FieldTransportAdjacency &candidate,
         const SourceEdgeTopologyKey &key) {
        return candidate.sourceEdge < key;
      });
  return found != adjacencies.end() && found->sourceEdge == edge ? &*found
                                                                 : nullptr;
}

std::optional<FieldDirectedTransport> directed_transport(
    const FieldTransportAdjacency &adjacency, const SourceFaceId fromFace,
    const SourceFaceId toFace) {
  if (adjacency.firstFace == fromFace && adjacency.secondFace == toFace) {
    return FieldDirectedTransport{adjacency.id, adjacency.forward,
                                  adjacency.forwardLift, adjacency.effort};
  }
  if (adjacency.secondFace == fromFace && adjacency.firstFace == toFace) {
    return FieldDirectedTransport{adjacency.id, adjacency.reverse,
                                  -adjacency.forwardLift, -adjacency.effort};
  }
  return std::nullopt;
}

struct LocalRegionMesh {
  TriMesh mesh;
  std::vector<int> globalFaceByLocal;
  std::vector<int> globalVertexByLocal;
};

std::optional<LocalRegionMesh> make_local_region_mesh(
    const TriMesh &sourceMesh,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const geometry::SurfaceTopologyRegion &region) {
  const std::vector<SourceFaceId> rows =
      sourceAuthority.rows_for_region(region.id());
  if (rows.empty()) return std::nullopt;

  LocalRegionMesh result;
  result.globalFaceByLocal.reserve(rows.size());
  std::set<int> globalVertices;
  for (const SourceFaceId row : rows) {
    const int face = static_cast<int>(row.index());
    if (face < 0 || face >= sourceMesh.F.rows()) return std::nullopt;
    result.globalFaceByLocal.push_back(face);
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = sourceMesh.F(face, corner);
      if (vertex < 0 || vertex >= sourceMesh.V.rows()) return std::nullopt;
      globalVertices.insert(vertex);
    }
  }
  result.globalVertexByLocal.assign(globalVertices.begin(),
                                    globalVertices.end());
  std::map<int, int> localVertex;
  for (int local = 0;
       local < static_cast<int>(result.globalVertexByLocal.size()); ++local) {
    localVertex.emplace(result.globalVertexByLocal[static_cast<std::size_t>(local)],
                        local);
  }

  Eigen::MatrixXd vertices(result.globalVertexByLocal.size(), 3);
  for (int local = 0; local < vertices.rows(); ++local) {
    vertices.row(local) = sourceMesh.V.row(
        result.globalVertexByLocal[static_cast<std::size_t>(local)]);
  }
  Eigen::MatrixXi faces(result.globalFaceByLocal.size(), 3);
  for (int localFace = 0; localFace < faces.rows(); ++localFace) {
    const int globalFace =
        result.globalFaceByLocal[static_cast<std::size_t>(localFace)];
    for (int corner = 0; corner < 3; ++corner) {
      const auto found = localVertex.find(sourceMesh.F(globalFace, corner));
      if (found == localVertex.end()) return std::nullopt;
      faces(localFace, corner) = found->second;
    }
  }

  try {
    result.mesh.set_mesh(vertices, faces);
  } catch (const std::exception &) {
    return std::nullopt;
  }
  return result;
}

SourceEdgeTopologyKey global_edge_key(const LocalRegionMesh &local,
                                      const int localEdge,
                                      const std::size_t vertexExtent) {
  const int first = local.globalVertexByLocal[static_cast<std::size_t>(
      local.mesh.EV(localEdge, 0))];
  const int second = local.globalVertexByLocal[static_cast<std::size_t>(
      local.mesh.EV(localEdge, 1))];
  return SourceEdgeTopologyKey::from_indices(first, second, vertexExtent)
      .value();
}

struct DirectedCycleEdge {
  const FieldTransportAdjacency *adjacency = nullptr;
  SourceFaceId fromFace;
  SourceFaceId toFace;
};

std::optional<std::vector<FieldTransportStep>> order_cycle_steps(
    std::vector<DirectedCycleEdge> directed) {
  if (directed.empty()) return std::vector<FieldTransportStep>{};

  std::sort(directed.begin(), directed.end(),
            [](const DirectedCycleEdge &a, const DirectedCycleEdge &b) {
              return std::tie(a.fromFace, a.toFace, a.adjacency->sourceEdge) <
                     std::tie(b.fromFace, b.toFace, b.adjacency->sourceEdge);
            });
  for (std::size_t i = 1; i < directed.size(); ++i) {
    if (directed[i - 1U].fromFace == directed[i].fromFace) {
      return std::nullopt;
    }
  }

  const SourceFaceId start = directed.front().fromFace;
  SourceFaceId current = start;
  std::vector<bool> used(directed.size(), false);
  std::vector<FieldTransportStep> result;
  result.reserve(directed.size());
  for (std::size_t step = 0; step < directed.size(); ++step) {
    const auto found = std::lower_bound(
        directed.begin(), directed.end(), current,
        [](const DirectedCycleEdge &candidate, const SourceFaceId face) {
          return candidate.fromFace < face;
        });
    if (found == directed.end() || found->fromFace != current) {
      return std::nullopt;
    }
    const std::size_t index =
        static_cast<std::size_t>(found - directed.begin());
    if (used[index]) return std::nullopt;
    used[index] = true;
    const auto transport = directed_transport(
        *found->adjacency, found->fromFace, found->toFace);
    if (!transport.has_value()) return std::nullopt;
    result.push_back(FieldTransportStep{
        found->adjacency->id, found->adjacency->sourceEdge, found->fromFace,
        found->toFace, transport->transport, transport->signedLift});
    current = found->toFace;
  }
  if (current != start ||
      std::find(used.begin(), used.end(), false) != used.end()) {
    return std::nullopt;
  }
  return result;
}

QuarterTurn compose_cycle(
    const std::vector<FieldTransportStep> &steps) noexcept {
  QuarterTurn result;
  for (const FieldTransportStep &step : steps) {
    result = compose(step.transport, result);
  }
  return result;
}

int signature_gcd(const std::vector<int> &signature) {
  int result = 0;
  for (const int value : signature) {
    result = std::gcd(result, std::abs(value));
  }
  // A regular genus-one component has the empty primitive signature.
  return signature.empty() ? 1 : result;
}

bool is_genus_one_two_cone_exception(std::vector<int> signature) {
  if (signature.size() != 2U) return false;
  std::sort(signature.begin(), signature.end());
  return signature[0] == -1 && signature[1] == 1;
}

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;

void consume_hash(std::uint64_t &hash, const std::uint64_t value) noexcept {
  hash ^= value;
  hash *= kFnvPrime;
}

void consume_signed(std::uint64_t &hash, const int value) noexcept {
  consume_hash(hash, static_cast<std::uint64_t>(
                         static_cast<std::int64_t>(value)));
}

void consume_face_topology(std::uint64_t &hash,
                           const SourceFaceTopologyKey &topology) noexcept {
  for (const SourceVertexId vertex : topology.vertices()) {
    consume_hash(hash, vertex.index());
  }
}

std::uint64_t source_binding_digest(
    const std::size_t sourceVertexCount,
    std::vector<SourceFaceTopologyKey> rowTopology) {
  std::sort(rowTopology.begin(), rowTopology.end());
  std::uint64_t hash = kFnvOffset;
  consume_hash(hash, sourceVertexCount);
  consume_hash(hash, rowTopology.size());
  for (const SourceFaceTopologyKey &topology : rowTopology) {
    consume_face_topology(hash, topology);
  }
  return hash;
}

std::uint64_t cycle_semantic_digest(
    const FieldCycleWitness &cycle,
    const std::vector<SourceFaceTopologyKey> &rowTopology) noexcept {
  std::uint64_t hash = kFnvOffset;
  consume_hash(hash, static_cast<std::uint64_t>(cycle.kind));
  consume_hash(hash, cycle.localVertex.has_value()
                         ? cycle.localVertex->index() + 1U
                         : 0U);
  consume_hash(hash, cycle.steps.size());
  for (const FieldTransportStep &step : cycle.steps) {
    consume_hash(hash, step.sourceEdge.first().index());
    consume_hash(hash, step.sourceEdge.second().index());
    if (step.fromFace.index() < rowTopology.size()) {
      consume_face_topology(hash, rowTopology[step.fromFace.index()]);
    }
    if (step.toFace.index() < rowTopology.size()) {
      consume_face_topology(hash, rowTopology[step.toFace.index()]);
    }
    consume_hash(hash, step.transport.value());
    consume_signed(hash, step.signedLift);
  }
  consume_hash(hash, cycle.composedTransport.value());
  consume_signed(hash, cycle.turningLift);
  return hash;
}

std::uint64_t component_holonomy_digest(
    const std::vector<FieldCycleWitness> &cycles,
    const std::size_t begin, const std::size_t end,
    const std::vector<SourceFaceTopologyKey> &rowTopology) {
  std::vector<std::uint64_t> cycleDigests;
  cycleDigests.reserve(end - begin);
  for (std::size_t index = begin; index < end; ++index) {
    cycleDigests.push_back(cycle_semantic_digest(cycles[index], rowTopology));
  }
  std::sort(cycleDigests.begin(), cycleDigests.end());
  std::uint64_t hash = kFnvOffset;
  consume_hash(hash, cycleDigests.size());
  for (const std::uint64_t digest : cycleDigests) consume_hash(hash, digest);
  return hash;
}

std::uint64_t atlas_fact_digest(
    const std::uint64_t sourceDigest,
    const std::vector<SourceFaceTopologyKey> &rowTopology,
    const std::vector<FieldTransportAdjacency> &adjacencies,
    const std::vector<FieldNonTraversableEdge> &nontraversableEdges,
    const std::vector<FieldCycleWitness> &cycles,
    const std::vector<FieldSingularityFact> &singularities,
    const std::vector<FieldComponentTopology> &componentTopology,
    const std::vector<FieldQuadrangulabilityWitness> &witnesses) {
  std::uint64_t hash = kFnvOffset;
  consume_hash(hash, sourceDigest);

  consume_hash(hash, adjacencies.size());
  for (const FieldTransportAdjacency &adjacency : adjacencies) {
    consume_hash(hash, adjacency.sourceEdge.first().index());
    consume_hash(hash, adjacency.sourceEdge.second().index());
    const bool canonicalForward =
        adjacency.firstFaceTopology < adjacency.secondFaceTopology;
    consume_face_topology(
        hash, canonicalForward ? adjacency.firstFaceTopology
                               : adjacency.secondFaceTopology);
    consume_face_topology(
        hash, canonicalForward ? adjacency.secondFaceTopology
                               : adjacency.firstFaceTopology);
    consume_hash(hash, (canonicalForward ? adjacency.forward
                                         : adjacency.reverse)
                           .value());
    consume_hash(hash, (canonicalForward ? adjacency.reverse
                                         : adjacency.forward)
                           .value());
    consume_signed(hash, canonicalForward ? adjacency.forwardLift
                                          : -adjacency.forwardLift);
    double canonicalEffort =
        canonicalForward ? adjacency.effort : -adjacency.effort;
    if (canonicalEffort == 0.0) canonicalEffort = 0.0;
    consume_hash(hash, std::bit_cast<std::uint64_t>(canonicalEffort));
  }

  consume_hash(hash, nontraversableEdges.size());
  for (const FieldNonTraversableEdge &edge : nontraversableEdges) {
    consume_hash(hash, edge.sourceEdge.first().index());
    consume_hash(hash, edge.sourceEdge.second().index());
    consume_hash(hash, static_cast<std::uint64_t>(edge.kind));
  }

  std::vector<std::uint64_t> cycleDigests;
  cycleDigests.reserve(cycles.size());
  for (const FieldCycleWitness &cycle : cycles) {
    cycleDigests.push_back(cycle_semantic_digest(cycle, rowTopology));
  }
  std::sort(cycleDigests.begin(), cycleDigests.end());
  consume_hash(hash, cycleDigests.size());
  for (const std::uint64_t digest : cycleDigests) consume_hash(hash, digest);

  std::vector<std::pair<std::uint64_t, int>> singularityFacts;
  singularityFacts.reserve(singularities.size());
  for (const FieldSingularityFact &singularity : singularities) {
    singularityFacts.emplace_back(singularity.sourceVertex.index(),
                                  singularity.indexNumerator);
  }
  std::sort(singularityFacts.begin(), singularityFacts.end());
  consume_hash(hash, singularityFacts.size());
  for (const auto &[vertex, numerator] : singularityFacts) {
    consume_hash(hash, vertex);
    consume_signed(hash, numerator);
  }

  std::vector<std::tuple<int, int, int, std::size_t, std::size_t,
                         std::size_t, std::size_t, std::size_t>>
      topologyFacts;
  topologyFacts.reserve(componentTopology.size());
  for (const FieldComponentTopology &topology : componentTopology) {
    topologyFacts.emplace_back(
        topology.eulerCharacteristic, topology.boundaryLoopCount,
        topology.genus, topology.vertexCount, topology.edgeCount,
        topology.faceCount, topology.localCycleCount,
        topology.handleGeneratorCount);
  }
  std::sort(topologyFacts.begin(), topologyFacts.end());
  consume_hash(hash, topologyFacts.size());
  for (const auto &[euler, boundaries, genus, vertices, edges, faces,
                    localCycles, handles] : topologyFacts) {
    consume_signed(hash, euler);
    consume_signed(hash, boundaries);
    consume_signed(hash, genus);
    consume_hash(hash, vertices);
    consume_hash(hash, edges);
    consume_hash(hash, faces);
    consume_hash(hash, localCycles);
    consume_hash(hash, handles);
  }

  std::vector<std::uint64_t> witnessDigests;
  witnessDigests.reserve(witnesses.size());
  for (const FieldQuadrangulabilityWitness &witness : witnesses) {
    std::uint64_t witnessHash = kFnvOffset;
    consume_hash(witnessHash, static_cast<std::uint64_t>(witness.kind));
    consume_hash(witnessHash, witness.holonomySignatureDigest);
    consume_signed(witnessHash, witness.numeratorGcd);
    consume_signed(witnessHash, witness.indexSum);
    consume_signed(witnessHash, witness.requiredIndexSum);
    consume_hash(witnessHash, witness.fullSignature.size());
    for (const int value : witness.fullSignature) {
      consume_signed(witnessHash, value);
    }
    consume_hash(witnessHash, witness.singularityNumerators.size());
    for (const int value : witness.singularityNumerators) {
      consume_signed(witnessHash, value);
    }
    consume_hash(witnessHash, witness.exactCycleLifts.size());
    consume_hash(witnessHash, witness.boundaryCycles.size());
    witnessDigests.push_back(witnessHash);
  }
  std::sort(witnessDigests.begin(), witnessDigests.end());
  consume_hash(hash, witnessDigests.size());
  for (const std::uint64_t digest : witnessDigests) consume_hash(hash, digest);
  return hash;
}

} // namespace

FieldTransportAtlasBuildResult FieldTransportAtlas::make(
    const TriMesh &sourceMesh,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges,
    const fields::CrossFieldResult &crossField) {
  if (sourceMesh.V.cols() != 3 || sourceMesh.V.rows() <= 0 ||
      sourceMesh.F.cols() != 3 || sourceMesh.F.rows() <= 0 ||
      sourceMesh.EV.cols() != 2 || sourceMesh.EF.cols() != 2 ||
      sourceMesh.EV.rows() != sourceMesh.EF.rows() ||
      crossField.degree != fields::kCrossFieldDegree ||
      !crossField.matchingComputed || !crossField.singularitiesComputed ||
      crossField.singularCycles.size() != crossField.singularIndices.size() ||
      !sourceAuthority.matches_source_faces(
          sourceMesh.F, static_cast<std::size_t>(sourceMesh.V.rows()))) {
    return fail(FieldAtlasBuildErrorCode::InvalidInput);
  }

  const std::size_t vertexExtent =
      static_cast<std::size_t>(sourceMesh.V.rows());
  const std::size_t faceExtent =
      static_cast<std::size_t>(sourceMesh.F.rows());
  std::vector<SourceFaceTopologyKey> rowTopology;
  std::vector<TopologyRegionId> rowRegions;
  std::vector<SourceComponentId> rowComponents;
  rowTopology.reserve(faceExtent);
  rowRegions.reserve(faceExtent);
  rowComponents.reserve(faceExtent);
  for (std::size_t row = 0; row < faceExtent; ++row) {
    const SourceFaceId face = make_id<SourceFaceId>(row);
    rowTopology.push_back(sourceAuthority.topology_for_row(face));
    rowRegions.push_back(sourceAuthority.region_for_row(face));
    rowComponents.push_back(sourceAuthority.component_for_row(face));
  }
  const std::uint64_t sourceDigest =
      source_binding_digest(vertexExtent, rowTopology);

  std::map<SourceEdgeTopologyKey, const fields::CrossFieldEdgeTransition *>
      transitionByEdge;
  for (const fields::CrossFieldEdgeTransition &transition :
       crossField.edgeTransitions) {
    const auto key = SourceEdgeTopologyKey::from_indices(
        transition.sourceVertex0, transition.sourceVertex1, vertexExtent);
    if (!key) return fail(FieldAtlasBuildErrorCode::InvalidInput);
    if (!std::isfinite(transition.effort)) {
      return fail(FieldAtlasBuildErrorCode::InvalidInput, key.value());
    }
    if (!transitionByEdge.emplace(key.value(), &transition).second) {
      return fail(FieldAtlasBuildErrorCode::DuplicateAdjacency, key.value());
    }
  }

  std::vector<int> sourceEdges(static_cast<std::size_t>(sourceMesh.EV.rows()));
  std::iota(sourceEdges.begin(), sourceEdges.end(), 0);
  std::sort(sourceEdges.begin(), sourceEdges.end(), [&](const int a, const int b) {
    const auto ka = SourceEdgeTopologyKey::from_indices(
        sourceMesh.EV(a, 0), sourceMesh.EV(a, 1), vertexExtent);
    const auto kb = SourceEdgeTopologyKey::from_indices(
        sourceMesh.EV(b, 0), sourceMesh.EV(b, 1), vertexExtent);
    return ka && kb ? ka.value() < kb.value() : a < b;
  });

  std::vector<FieldTransportAdjacency> adjacencies;
  std::vector<FieldNonTraversableEdge> nontraversableEdges;
  for (const int edgeIndex : sourceEdges) {
    const auto edge = SourceEdgeTopologyKey::from_indices(
        sourceMesh.EV(edgeIndex, 0), sourceMesh.EV(edgeIndex, 1),
        vertexExtent);
    if (!edge) return fail(FieldAtlasBuildErrorCode::InvalidInput);
    const int firstRaw = sourceMesh.EF(edgeIndex, 0);
    const int secondRaw = sourceMesh.EF(edgeIndex, 1);
    if (firstRaw < 0 || firstRaw >= sourceMesh.F.rows()) {
      return fail(FieldAtlasBuildErrorCode::InvalidInput, edge.value());
    }
    const SourceFaceId first = make_id<SourceFaceId>(
        static_cast<std::size_t>(firstRaw));
    const std::optional<SourceFaceId> second =
        secondRaw >= 0 && secondRaw < sourceMesh.F.rows()
            ? std::optional<SourceFaceId>(make_id<SourceFaceId>(
                  static_cast<std::size_t>(secondRaw)))
            : std::nullopt;

    if (!second.has_value()) {
      nontraversableEdges.push_back(FieldNonTraversableEdge{
          edge.value(), FieldTransportBarrierKind::SourceBoundary, first,
          std::nullopt});
      continue;
    }
    if (hardFeatureEdges.count(edge.value()) != 0U) {
      nontraversableEdges.push_back(FieldNonTraversableEdge{
          edge.value(), FieldTransportBarrierKind::HardFeature, first, second});
      continue;
    }
    if (rowRegions[first.index()] != rowRegions[second->index()] ||
        rowComponents[first.index()] != rowComponents[second->index()]) {
      nontraversableEdges.push_back(FieldNonTraversableEdge{
          edge.value(), FieldTransportBarrierKind::NonTraversable, first,
          second});
      continue;
    }

    const auto transition = transitionByEdge.find(edge.value());
    if (transition == transitionByEdge.end()) {
      return fail(FieldAtlasBuildErrorCode::MissingAdjacency, edge.value());
    }
    const fields::CrossFieldEdgeTransition &raw = *transition->second;
    if (raw.sourceEdge != edgeIndex || raw.firstFace < 0 ||
        raw.secondFace < 0 || raw.firstFace >= sourceMesh.F.rows() ||
        raw.secondFace >= sourceMesh.F.rows() ||
        !((raw.firstFace == firstRaw && raw.secondFace == secondRaw) ||
          (raw.firstFace == secondRaw && raw.secondFace == firstRaw))) {
      return fail(FieldAtlasBuildErrorCode::NonReciprocalAdjacency,
                  edge.value());
    }
    const SourceFaceId rawFirst =
        make_id<SourceFaceId>(static_cast<std::size_t>(raw.firstFace));
    const SourceFaceId rawSecond =
        make_id<SourceFaceId>(static_cast<std::size_t>(raw.secondFace));
    const QuarterTurn forward = QuarterTurn::from_integer(raw.matching);
    const QuarterTurn reverse = forward.inverse();
    if (compose(forward, reverse) != QuarterTurn{}) {
      return fail(FieldAtlasBuildErrorCode::NonReciprocalAdjacency,
                  edge.value());
    }
    adjacencies.push_back(FieldTransportAdjacency{
        make_id<FieldTransportAdjacencyId>(adjacencies.size()), edge.value(),
        rawFirst, rawSecond, rowTopology[rawFirst.index()],
        rowTopology[rawSecond.index()], rowRegions[rawFirst.index()],
        rowComponents[rawFirst.index()], forward, reverse, raw.matching,
        raw.effort});
  }
  std::sort(adjacencies.begin(), adjacencies.end(),
            [](const FieldTransportAdjacency &a,
               const FieldTransportAdjacency &b) {
              return a.sourceEdge < b.sourceEdge;
            });
  // Reassign storage-independent IDs after canonical edge sorting.
  for (std::size_t index = 0; index < adjacencies.size(); ++index) {
    adjacencies[index].id = make_id<FieldTransportAdjacencyId>(index);
  }
  std::sort(nontraversableEdges.begin(), nontraversableEdges.end(),
            [](const FieldNonTraversableEdge &a,
               const FieldNonTraversableEdge &b) {
              return a.sourceEdge < b.sourceEdge;
            });

  std::map<int, int> rawSingularity;
  for (Eigen::Index index = 0; index < crossField.singularCycles.size();
       ++index) {
    const int vertex = crossField.singularCycles(index);
    const int numerator = crossField.singularIndices(index);
    const auto typed = SourceVertexId::from_index(vertex, vertexExtent);
    if (!typed || numerator == 0 ||
        !rawSingularity.emplace(vertex, numerator).second) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt,
                  typed ? std::optional<SourceVertexId>(typed.value())
                        : std::nullopt);
    }
  }

  std::vector<FieldCycleWitness> cycles;
  std::vector<FieldComponentTopology> componentTopology;
  std::vector<FieldQuadrangulabilityWitness> certificateWitnesses;
  std::map<int, std::pair<TopologyRegionId, FieldCycleId>>
      localCycleByGlobalVertex;

  for (const geometry::SurfaceTopologyRegion &region :
       sourceAuthority.regions()) {
    const std::vector<SourceFaceId> regionRows =
        sourceAuthority.rows_for_region(region.id());

    // A one-face disk has no traversable interior edge and therefore needs no
    // local tangent-bundle reconstruction. Publish its relative-boundary
    // proof directly from checked source authority.
    if (regionRows.size() == 1U && region.euler_characteristic() == 1 &&
        region.boundary_loop_count() == 1) {
      const SourceFaceId sourceFace = regionRows.front();
      if (sourceFace.index() >= static_cast<std::size_t>(sourceMesh.F.rows())) {
        return fail(FieldAtlasBuildErrorCode::CanonicalBindingMismatch,
                    std::nullopt, sourceFace, std::nullopt, region.id());
      }
      std::set<int> sourceVertices;
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex =
            sourceMesh.F(static_cast<int>(sourceFace.index()), corner);
        if (vertex < 0 || vertex >= sourceMesh.V.rows()) {
          return fail(FieldAtlasBuildErrorCode::CanonicalBindingMismatch,
                      std::nullopt, sourceFace, std::nullopt, region.id());
        }
        sourceVertices.insert(vertex);
      }
      if (sourceVertices.size() != 3U) {
        return fail(FieldAtlasBuildErrorCode::CanonicalBindingMismatch,
                    std::nullopt, sourceFace, std::nullopt, region.id());
      }

      const std::size_t componentCycleBegin = cycles.size();
      const FieldCycleId boundaryCycleId =
          make_id<FieldCycleId>(cycles.size());
      const int requiredIndexSum = 4 * region.euler_characteristic();
      cycles.push_back(FieldCycleWitness{
          boundaryCycleId, FieldCycleKind::BoundaryLoop, region.id(),
          region.component(), std::nullopt, {}, QuarterTurn{},
          requiredIndexSum});

      FieldQuadrangulabilityWitness witness{
          region.id(), region.component(),
          FieldQuadrangulabilityWitnessKind::RelativeBoundary,
          {requiredIndexSum}, {boundaryCycleId}, {boundaryCycleId},
          requiredIndexSum, requiredIndexSum, requiredIndexSum};
      witness.holonomySignatureDigest = component_holonomy_digest(
          cycles, componentCycleBegin, cycles.size(), rowTopology);
      certificateWitnesses.push_back(std::move(witness));
      componentTopology.push_back(FieldComponentTopology{
          region.id(), region.component(), 1, 1, 0, 3U, 3U, 1U, 0U, 0U});
      continue;
    }

    const auto local = make_local_region_mesh(sourceMesh, sourceAuthority,
                                               region);
    if (!local.has_value()) {
      return fail(FieldAtlasBuildErrorCode::CanonicalBindingMismatch,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }
    const int eulerCharacteristic = static_cast<int>(
        local->mesh.V.rows() - local->mesh.EV.rows() + local->mesh.F.rows());
    const int boundaryLoopCount =
        static_cast<int>(local->mesh.boundaryLoops.size());
    const int genusNumerator =
        2 - boundaryLoopCount - eulerCharacteristic;
    if (eulerCharacteristic != region.euler_characteristic() ||
        boundaryLoopCount != region.boundary_loop_count() ||
        genusNumerator < 0 || genusNumerator % 2 != 0) {
      return fail(FieldAtlasBuildErrorCode::CanonicalBindingMismatch,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }
    const int genus = genusNumerator / 2;

    PCFaceTangentBundle bundle;
    try {
      bundle.init(local->mesh);
    } catch (const std::exception &) {
      return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }
    std::vector<int> interiorLocalVertices;
    for (int vertex = 0; vertex < local->mesh.V.rows(); ++vertex) {
      if (local->mesh.isBoundaryVertex(vertex) == 0) {
        interiorLocalVertices.push_back(vertex);
      }
    }
    const int expectedHandleCount = 2 * genus;
    const int expectedCycleCount =
        static_cast<int>(interiorLocalVertices.size()) + boundaryLoopCount +
        expectedHandleCount;
    if (bundle.cycles.rows() != expectedCycleCount ||
        bundle.cycleCurvatures.size() != expectedCycleCount ||
        bundle.cycles.cols() != bundle.innerAdjacencies.size()) {
      return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }

    Eigen::VectorXd effort(bundle.innerAdjacencies.size());
    for (int column = 0; column < bundle.innerAdjacencies.size(); ++column) {
      const int localEdge = bundle.innerAdjacencies(column);
      const SourceEdgeTopologyKey edge =
          global_edge_key(*local, localEdge, vertexExtent);
      const auto transition = transitionByEdge.find(edge);
      if (transition == transitionByEdge.end()) {
        return fail(FieldAtlasBuildErrorCode::MissingAdjacency, edge,
                    std::nullopt, std::nullopt, region.id());
      }
      const int globalFirst = local->globalFaceByLocal[static_cast<std::size_t>(
          local->mesh.EF(localEdge, 0))];
      const int globalSecond = local->globalFaceByLocal[static_cast<std::size_t>(
          local->mesh.EF(localEdge, 1))];
      const fields::CrossFieldEdgeTransition &raw = *transition->second;
      if (raw.firstFace == globalFirst && raw.secondFace == globalSecond) {
        effort(column) = raw.effort;
      } else if (raw.firstFace == globalSecond &&
                 raw.secondFace == globalFirst) {
        effort(column) = -raw.effort;
      } else {
        return fail(FieldAtlasBuildErrorCode::NonReciprocalAdjacency, edge,
                    std::nullopt, std::nullopt, region.id());
      }
    }
    const Eigen::VectorXd exactLifts =
        ((bundle.cycles * effort +
          static_cast<double>(fields::kCrossFieldDegree) *
              bundle.cycleCurvatures)
             .array() /
         (2.0 * std::numbers::pi));
    Eigen::SparseMatrix<double, Eigen::RowMajor> rowCycles = bundle.cycles;

    const std::size_t componentCycleBegin = cycles.size();
    std::vector<std::size_t> localCycleIndices;
    std::vector<std::size_t> boundaryCycleIndices;
    std::vector<std::size_t> handleCycleIndices;
    for (int row = 0; row < expectedCycleCount; ++row) {
      const double exactLift = exactLifts(row);
      const double roundedLift = std::round(exactLift);
      if (!std::isfinite(exactLift) ||
          std::abs(exactLift - roundedLift) >= kIntegerTolerance) {
        return fail(FieldAtlasBuildErrorCode::NonIntegralCycleLift,
                    std::nullopt, std::nullopt, std::nullopt, region.id());
      }
      const int turningLift = static_cast<int>(roundedLift);
      std::vector<DirectedCycleEdge> directed;
      for (Eigen::SparseMatrix<double, Eigen::RowMajor>::InnerIterator it(
               rowCycles, row);
           it; ++it) {
        const double coefficient = it.value();
        // Sparse-sparse cycle construction may retain explicit algebraic
        // zeros. They are representation storage, not semantic cycle support.
        if (std::abs(coefficient) < kIntegerTolerance) continue;
        if (std::abs(std::abs(coefficient) - 1.0) >= kIntegerTolerance ||
            it.col() < 0 || it.col() >= bundle.innerAdjacencies.size()) {
          return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
                      std::nullopt, std::nullopt, std::nullopt, region.id());
        }
        const int localEdge = bundle.innerAdjacencies(it.col());
        const SourceEdgeTopologyKey edge =
            global_edge_key(*local, localEdge, vertexExtent);
        const FieldTransportAdjacency *adjacency =
            find_adjacency_in(adjacencies, edge);
        if (adjacency == nullptr) {
          return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis, edge,
                      std::nullopt, std::nullopt, region.id());
        }
        const int firstLocal = local->mesh.EF(localEdge, 0);
        const int secondLocal = local->mesh.EF(localEdge, 1);
        if (firstLocal < 0 || secondLocal < 0) {
          return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis, edge,
                      std::nullopt, std::nullopt, region.id());
        }
        SourceFaceId first = make_id<SourceFaceId>(static_cast<std::size_t>(
            local->globalFaceByLocal[static_cast<std::size_t>(firstLocal)]));
        SourceFaceId second = make_id<SourceFaceId>(static_cast<std::size_t>(
            local->globalFaceByLocal[static_cast<std::size_t>(secondLocal)]));
        if (coefficient < 0.0) std::swap(first, second);
        directed.push_back({adjacency, first, second});
      }
      const auto ordered = order_cycle_steps(directed);
      if (!ordered.has_value()) {
        return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
                    std::nullopt, std::nullopt, std::nullopt, region.id());
      }
      const QuarterTurn composed = compose_cycle(*ordered);
      if (static_cast<int>(composed.value()) !=
          normalized_quarter_turn(turningLift)) {
        return fail(FieldAtlasBuildErrorCode::CycleTransportMismatch,
                    std::nullopt, std::nullopt, std::nullopt, region.id());
      }

      FieldCycleKind kind = FieldCycleKind::HandleGenerator;
      std::optional<SourceVertexId> localVertex;
      if (row < static_cast<int>(interiorLocalVertices.size())) {
        kind = FieldCycleKind::LocalVertex;
        const int globalVertex = local->globalVertexByLocal[static_cast<std::size_t>(
            interiorLocalVertices[static_cast<std::size_t>(row)])];
        localVertex = make_id<SourceVertexId>(
            static_cast<std::size_t>(globalVertex));
      } else if (row < static_cast<int>(interiorLocalVertices.size()) +
                           boundaryLoopCount) {
        kind = FieldCycleKind::BoundaryLoop;
      }
      const std::size_t cycleIndex = cycles.size();
      cycles.push_back(FieldCycleWitness{
          make_id<FieldCycleId>(cycleIndex), kind, region.id(),
          region.component(), localVertex, std::move(*ordered), composed,
          turningLift});
      if (kind == FieldCycleKind::LocalVertex) {
        localCycleIndices.push_back(cycleIndex);
        const int globalVertex =
            static_cast<int>(cycles.back().localVertex->index());
        if (!localCycleByGlobalVertex
                 .emplace(globalVertex,
                          std::make_pair(region.id(), cycles.back().id))
                 .second) {
          return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                      std::nullopt, std::nullopt,
                      cycles.back().localVertex, region.id());
        }
      } else if (kind == FieldCycleKind::BoundaryLoop) {
        boundaryCycleIndices.push_back(cycleIndex);
      } else {
        handleCycleIndices.push_back(cycleIndex);
      }
    }
    if (cycles.size() - componentCycleBegin !=
            static_cast<std::size_t>(expectedCycleCount) ||
        boundaryCycleIndices.size() !=
            static_cast<std::size_t>(boundaryLoopCount) ||
        handleCycleIndices.size() !=
            static_cast<std::size_t>(expectedHandleCount)) {
      return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }

    std::vector<int> signature;
    int interiorIndexSum = 0;
    for (const std::size_t cycleIndex : localCycleIndices) {
      const FieldCycleWitness &cycle = cycles[cycleIndex];
      const int globalVertex = static_cast<int>(cycle.localVertex->index());
      const auto supplied = rawSingularity.find(globalVertex);
      if ((cycle.turningLift == 0 && supplied != rawSingularity.end()) ||
          (cycle.turningLift != 0 &&
           (supplied == rawSingularity.end() ||
            supplied->second != cycle.turningLift))) {
        return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                    std::nullopt, std::nullopt, cycle.localVertex,
                    region.id());
      }
      if (cycle.turningLift != 0) signature.push_back(cycle.turningLift);
      interiorIndexSum += cycle.turningLift;
    }
    std::sort(signature.begin(), signature.end());

    const int requiredIndexSum = 4 * eulerCharacteristic;
    FieldQuadrangulabilityWitness witness{
        region.id(), region.component(),
        boundaryLoopCount == 0
            ? FieldQuadrangulabilityWitnessKind::ClosedShenSufficient
            : FieldQuadrangulabilityWitnessKind::RelativeBoundary,
        {}, {}, {}, 0, 0, requiredIndexSum};
    witness.singularityNumerators = signature;
    witness.exactCycleLifts.reserve(cycles.size() - componentCycleBegin);
    for (std::size_t cycleIndex = componentCycleBegin;
         cycleIndex < cycles.size(); ++cycleIndex) {
      witness.exactCycleLifts.push_back(cycles[cycleIndex].id);
    }

    if (boundaryLoopCount == 0) {
      if (interiorIndexSum != requiredIndexSum) {
        return fail(
            FieldAtlasBuildErrorCode::GaussBonnetPoincareHopfMismatch,
            std::nullopt, std::nullopt, std::nullopt, region.id());
      }
      witness.indexSum = interiorIndexSum;
    } else {
      int boundaryIndexSum = 0;
      for (const std::size_t cycleIndex : boundaryCycleIndices) {
        boundaryIndexSum += cycles[cycleIndex].turningLift;
        witness.boundaryCycles.push_back(cycles[cycleIndex].id);
      }
      const int correction =
          requiredIndexSum - interiorIndexSum - boundaryIndexSum;
      if (boundaryCycleIndices.empty() || correction % 4 != 0) {
        return fail(FieldAtlasBuildErrorCode::UnestablishedAdmissibility,
                    std::nullopt, std::nullopt, std::nullopt, region.id());
      }
      FieldCycleWitness &canonicalBoundary =
          cycles[boundaryCycleIndices.front()];
      canonicalBoundary.turningLift += correction;
      if (static_cast<int>(canonicalBoundary.composedTransport.value()) !=
          normalized_quarter_turn(canonicalBoundary.turningLift)) {
        return fail(FieldAtlasBuildErrorCode::CycleTransportMismatch,
                    std::nullopt, std::nullopt, std::nullopt, region.id());
      }
      witness.indexSum = requiredIndexSum;
    }
    for (std::size_t cycleIndex = componentCycleBegin;
         cycleIndex < cycles.size(); ++cycleIndex) {
      if (cycles[cycleIndex].turningLift != 0) {
        witness.fullSignature.push_back(cycles[cycleIndex].turningLift);
      }
    }
    std::sort(witness.fullSignature.begin(), witness.fullSignature.end());
    witness.numeratorGcd = signature_gcd(witness.fullSignature);
    if (boundaryLoopCount == 0 &&
        (witness.numeratorGcd != 1 ||
         (genus == 1 && is_genus_one_two_cone_exception(signature)))) {
      return fail(FieldAtlasBuildErrorCode::UnestablishedAdmissibility,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }
    witness.holonomySignatureDigest = component_holonomy_digest(
        cycles, componentCycleBegin, cycles.size(), rowTopology);
    certificateWitnesses.push_back(std::move(witness));
    componentTopology.push_back(FieldComponentTopology{
        region.id(), region.component(), eulerCharacteristic,
        boundaryLoopCount, genus,
        static_cast<std::size_t>(local->mesh.V.rows()),
        static_cast<std::size_t>(local->mesh.EV.rows()),
        static_cast<std::size_t>(local->mesh.F.rows()),
        localCycleIndices.size(), handleCycleIndices.size()});
  }

  std::vector<FieldSingularityFact> singularities;
  singularities.reserve(rawSingularity.size());
  for (const auto &[rawVertex, numerator] : rawSingularity) {
    const SourceVertexId vertex =
        make_id<SourceVertexId>(static_cast<std::size_t>(rawVertex));
    std::optional<TopologyRegionId> region;
    std::optional<FieldCycleId> cycle;
    const auto represented = localCycleByGlobalVertex.find(rawVertex);
    if (represented != localCycleByGlobalVertex.end()) {
      region = represented->second.first;
      cycle = represented->second.second;
    }

    std::optional<SourceComponentId> component;
    for (int face = 0; face < sourceMesh.F.rows() && !component.has_value();
         ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        if (sourceMesh.F(face, corner) == rawVertex) {
          component = rowComponents[static_cast<std::size_t>(face)];
          break;
        }
      }
    }
    if (!component.has_value()) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex);
    }
    singularities.push_back(FieldSingularityFact{
        make_id<FieldSingularityId>(singularities.size()), vertex, *component,
        numerator, region, cycle});
  }

  const std::uint64_t atlasDigest = atlas_fact_digest(
      sourceDigest, rowTopology, adjacencies, nontraversableEdges, cycles,
      singularities, componentTopology, certificateWitnesses);
  FieldQuadrangulabilityCertificate certificate(
      std::move(certificateWitnesses), true, sourceDigest, atlasDigest);
  return FieldTransportAtlasBuildResult(FieldTransportAtlas(
      vertexExtent, std::move(rowTopology), std::move(rowRegions),
      std::move(rowComponents), std::move(adjacencies),
      std::move(nontraversableEdges), std::move(cycles),
      std::move(singularities), std::move(componentTopology),
      std::move(certificate)));
}

const FieldTransportAdjacency *FieldTransportAtlas::find_adjacency(
    const SourceEdgeTopologyKey &sourceEdge) const noexcept {
  return find_adjacency_in(adjacencies_, sourceEdge);
}

std::optional<FieldDirectedTransport> FieldTransportAtlas::transport(
    const SourceEdgeTopologyKey &sourceEdge, const SourceFaceId fromFace,
    const SourceFaceId toFace) const noexcept {
  const FieldTransportAdjacency *adjacency = find_adjacency(sourceEdge);
  return adjacency == nullptr
             ? std::nullopt
             : directed_transport(*adjacency, fromFace, toFace);
}

bool FieldTransportAtlas::matches_source_faces(
    const Eigen::MatrixXi &sourceFaces,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const std::size_t sourceVertexCount) const noexcept {
  if (sourceVertexCount != sourceVertexCount_ ||
      rowTopology_.size() != static_cast<std::size_t>(sourceFaces.rows()) ||
      rowRegions_.size() != rowTopology_.size() ||
      rowComponents_.size() != rowTopology_.size() ||
      !sourceAuthority.matches_source_faces(sourceFaces, sourceVertexCount)) {
    return false;
  }
  for (std::size_t row = 0; row < rowTopology_.size(); ++row) {
    const SourceFaceId face = make_id<SourceFaceId>(row);
    if (rowTopology_[row] != sourceAuthority.topology_for_row(face) ||
        rowRegions_[row] != sourceAuthority.region_for_row(face) ||
        rowComponents_[row] != sourceAuthority.component_for_row(face)) {
      return false;
    }
  }
  return true;
}

const char *field_atlas_build_error_code_name(
    const FieldAtlasBuildErrorCode code) noexcept {
  switch (code) {
  case FieldAtlasBuildErrorCode::InvalidInput:
    return "InvalidInput";
  case FieldAtlasBuildErrorCode::CanonicalBindingMismatch:
    return "CanonicalBindingMismatch";
  case FieldAtlasBuildErrorCode::MissingAdjacency:
    return "MissingAdjacency";
  case FieldAtlasBuildErrorCode::DuplicateAdjacency:
    return "DuplicateAdjacency";
  case FieldAtlasBuildErrorCode::NonReciprocalAdjacency:
    return "NonReciprocalAdjacency";
  case FieldAtlasBuildErrorCode::IncompleteCycleBasis:
    return "IncompleteCycleBasis";
  case FieldAtlasBuildErrorCode::NonIntegralCycleLift:
    return "NonIntegralCycleLift";
  case FieldAtlasBuildErrorCode::CycleTransportMismatch:
    return "CycleTransportMismatch";
  case FieldAtlasBuildErrorCode::SingularityMismatch:
    return "SingularityMismatch";
  case FieldAtlasBuildErrorCode::GaussBonnetPoincareHopfMismatch:
    return "GaussBonnetPoincareHopfMismatch";
  case FieldAtlasBuildErrorCode::UnestablishedAdmissibility:
    return "UnestablishedAdmissibility";
  }
  return "Unknown";
}

std::uint64_t field_transport_atlas_hash(
    const FieldTransportAtlas &atlas) noexcept {
  return atlas.quadrangulability().atlas_digest();
}

} // namespace directional::authority
