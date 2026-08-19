#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <map>
#include <numeric>
#include <limits>
#include <optional>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Geometry>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/SurfaceCellTracing.h>

namespace {

using directional::TriMesh;
using directional::authority::FieldAtlasBuildErrorCode;
using directional::authority::FieldComponentTopology;
using directional::authority::FieldCycleId;
using directional::authority::FieldCycleKind;
using directional::authority::FieldCycleWitness;
using directional::authority::FieldNonTraversableEdge;
using directional::authority::FieldQuadrangulabilityWitness;
using directional::authority::FieldQuadrangulabilityWitnessKind;
using directional::authority::FieldSingularityFact;
using directional::authority::FieldSingularityId;
using directional::authority::FieldTransportAdjacency;
using directional::authority::FieldTransportAtlas;
using directional::authority::FieldTransportBarrierKind;
using directional::authority::FieldTransportStep;
using directional::authority::QuarterTurn;
using directional::authority::SourceFaceId;
using directional::authority::SourceFaceTopologyKey;
using directional::authority::SourceEdgeTopologyKey;
using directional::authority::SourceVertexId;
using directional::fields::CrossFieldEdgeTransition;
using directional::fields::CrossFieldResult;
using directional::geometry::SourceTopologyRegions;
using directional::geometry::SurfaceCellTracingOptions;

TriMesh make_square_mesh(const bool reverseFaceRows = false) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              1.0, 1.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  if (reverseFaceRows) {
    faces << 0, 2, 3,
             0, 1, 2;
  } else {
    faces << 0, 1, 2,
             0, 2, 3;
  }
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

TriMesh make_four_triangle_fan() {
  Eigen::MatrixXd vertices(5, 3);
  vertices << -1.0, -1.0, 0.0,
               1.0, -1.0, 0.0,
               1.0,  1.0, 0.0,
              -1.0,  1.0, 0.0,
               0.0,  0.0, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4,
           1, 2, 4,
           2, 3, 4,
           3, 0, 4;
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

SourceEdgeTopologyKey edge_key(const TriMesh &mesh, const int edge) {
  return SourceEdgeTopologyKey::from_indices(
             mesh.EV(edge, 0), mesh.EV(edge, 1),
             static_cast<std::size_t>(mesh.V.rows()))
      .value();
}

CrossFieldResult make_zero_transport_field(const TriMesh &mesh) {
  CrossFieldResult field;
  field.degree = directional::fields::kCrossFieldDegree;
  field.matching = Eigen::VectorXi::Zero(mesh.EV.rows());
  field.effort = Eigen::VectorXd::Zero(mesh.EV.rows());
  field.matchingComputed = true;
  field.singularitiesComputed = true;
  field.singularCycles.resize(0);
  field.singularIndices.resize(0);
  field.primaryDirections.resize(mesh.F.rows(), 3);
  field.secondaryDirections.resize(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    field.primaryDirections.row(face) = Eigen::RowVector3d::UnitX();
    field.secondaryDirections.row(face) = Eigen::RowVector3d::UnitY();
  }
  field.edgeTransitions.reserve(static_cast<std::size_t>(mesh.EV.rows()));
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    field.edgeTransitions.push_back(CrossFieldEdgeTransition{
        edge, mesh.EV(edge, 0), mesh.EV(edge, 1), mesh.EF(edge, 0),
        mesh.EF(edge, 1), 0, 0.0});
  }
  return field;
}

std::optional<SourceTopologyRegions> make_source_authority(
    const TriMesh &mesh,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges = {}) {
  SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  options.sourceFaceSheets.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
  options.hardFeatureEdges = hardFeatureEdges;
  return directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(mesh.F, options);
}

CrossFieldEdgeTransition *find_transition(CrossFieldResult &field,
                                          const SourceEdgeTopologyKey &key,
                                          const std::size_t vertexExtent) {
  const auto found = std::find_if(
      field.edgeTransitions.begin(), field.edgeTransitions.end(),
      [&](const CrossFieldEdgeTransition &transition) {
        const auto transitionKey = SourceEdgeTopologyKey::from_indices(
            transition.sourceVertex0, transition.sourceVertex1, vertexExtent);
        return transitionKey && transitionKey.value() == key;
      });
  return found == field.edgeTransitions.end() ? nullptr : &*found;
}

struct DisjointSet {
  explicit DisjointSet(const int count) : parent(static_cast<std::size_t>(count)) {
    std::iota(parent.begin(), parent.end(), 0);
  }
  int root(int value) {
    int &parentValue = parent[static_cast<std::size_t>(value)];
    if (parentValue != value) parentValue = root(parentValue);
    return parentValue;
  }
  bool join(const int a, const int b) {
    const int ra = root(a);
    const int rb = root(b);
    if (ra == rb) return false;
    parent[static_cast<std::size_t>(rb)] = ra;
    return true;
  }
  std::vector<int> parent;
};

/**
 * Independent A1 oracle. It deliberately does not call the atlas factory,
 * validator, cycle builder, or admissibility decision. Each expected fact has
 * a separate source authority:
 *
 * - source binding: source face rows plus SourceTopologyRegions;
 * - adjacency/barriers: EV/EF, hard features, and raw edge transitions;
 * - branch transport: raw face branches plus an independent connection;
 * - topology/rank: source incidence plus an independent tree/cotree;
 * - cycle proof: source incidence plus independently validated raw transport;
 * - singularities: raw CrossFieldResult cycles/indices;
 * - admissibility: source topology plus the independently verified proof; and
 * - digests: independently written canonical hash projections.
 *
 * Published atlas payload is accepted only as proof material after its source
 * binding, ownership, completeness, and transport have been checked.
 */
struct IndependentOracleSummary {
  std::size_t traversableEdges = 0U;
  std::size_t boundaryEdges = 0U;
  std::size_t hardFeatureEdges = 0U;
  int eulerCharacteristic = 0;
  int boundaryLoops = 0;
  int handleGenerators = 0;
  bool reciprocal = true;
};

IndependentOracleSummary independent_oracle(
    const TriMesh &mesh, const CrossFieldResult &field,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges = {}) {
  IndependentOracleSummary result;
  result.eulerCharacteristic =
      static_cast<int>(mesh.V.rows() - mesh.EV.rows() + mesh.F.rows());

  std::map<SourceEdgeTopologyKey, const CrossFieldEdgeTransition *> transitions;
  for (const CrossFieldEdgeTransition &transition : field.edgeTransitions) {
    const auto key = SourceEdgeTopologyKey::from_indices(
        transition.sourceVertex0, transition.sourceVertex1,
        static_cast<std::size_t>(mesh.V.rows()));
    if (!key || !transitions.emplace(key.value(), &transition).second) {
      result.reciprocal = false;
    }
  }

  std::map<int, std::vector<int>> boundaryAdjacency;
  DisjointSet primal(mesh.V.rows());
  std::set<int> primalTreeEdges;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    const SourceEdgeTopologyKey key = edge_key(mesh, edge);
    if (mesh.EF(edge, 1) < 0) {
      ++result.boundaryEdges;
      boundaryAdjacency[mesh.EV(edge, 0)].push_back(mesh.EV(edge, 1));
      boundaryAdjacency[mesh.EV(edge, 1)].push_back(mesh.EV(edge, 0));
      continue;
    }
    if (hardFeatureEdges.count(key) != 0U) {
      ++result.hardFeatureEdges;
      continue;
    }
    ++result.traversableEdges;
    const auto transition = transitions.find(key);
    if (transition == transitions.end() ||
        !((transition->second->firstFace == mesh.EF(edge, 0) &&
           transition->second->secondFace == mesh.EF(edge, 1)) ||
          (transition->second->firstFace == mesh.EF(edge, 1) &&
           transition->second->secondFace == mesh.EF(edge, 0)))) {
      result.reciprocal = false;
    }
    if (primal.join(mesh.EV(edge, 0), mesh.EV(edge, 1))) {
      primalTreeEdges.insert(edge);
    }
  }

  std::set<int> unseenBoundaryVertices;
  for (auto &[vertex, neighbors] : boundaryAdjacency) {
    std::sort(neighbors.begin(), neighbors.end());
    neighbors.erase(std::unique(neighbors.begin(), neighbors.end()),
                    neighbors.end());
    unseenBoundaryVertices.insert(vertex);
  }
  while (!unseenBoundaryVertices.empty()) {
    ++result.boundaryLoops;
    std::vector<int> stack{*unseenBoundaryVertices.begin()};
    while (!stack.empty()) {
      const int vertex = stack.back();
      stack.pop_back();
      if (unseenBoundaryVertices.erase(vertex) == 0U) continue;
      for (const int neighbor : boundaryAdjacency[vertex]) {
        if (unseenBoundaryVertices.count(neighbor) != 0U) {
          stack.push_back(neighbor);
        }
      }
    }
  }

  DisjointSet dual(mesh.F.rows());
  std::set<int> dualCotreeEdges;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (mesh.EF(edge, 1) < 0 || primalTreeEdges.count(edge) != 0U ||
        hardFeatureEdges.count(edge_key(mesh, edge)) != 0U) {
      continue;
    }
    if (dual.join(mesh.EF(edge, 0), mesh.EF(edge, 1))) {
      dualCotreeEdges.insert(edge);
    }
  }
  int leftover = 0;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (mesh.EF(edge, 1) >= 0 &&
        hardFeatureEdges.count(edge_key(mesh, edge)) == 0U &&
        primalTreeEdges.count(edge) == 0U &&
        dualCotreeEdges.count(edge) == 0U) {
      ++leftover;
    }
  }
  result.handleGenerators =
      leftover - std::max(0, result.boundaryLoops - 1);
  return result;
}

struct IndependentAtlasSnapshot {
  std::vector<FieldTransportAdjacency> adjacencies;
  std::vector<FieldNonTraversableEdge> nontraversableEdges;
  std::vector<FieldCycleWitness> cycles;
  std::vector<FieldSingularityFact> singularities;
  std::vector<FieldComponentTopology> componentTopology;
  std::vector<FieldQuadrangulabilityWitness> witnesses;
  bool established = false;
  std::uint64_t sourceDigest = 0U;
  std::uint64_t atlasDigest = 0U;
};

IndependentAtlasSnapshot independent_snapshot(const FieldTransportAtlas &atlas) {
  return IndependentAtlasSnapshot{
      atlas.adjacencies(), atlas.nontraversable_edges(), atlas.cycles(),
      atlas.singularities(), atlas.component_topology(),
      atlas.quadrangulability().witnesses(),
      atlas.quadrangulability().established(),
      atlas.quadrangulability().source_digest(),
      atlas.quadrangulability().atlas_digest()};
}

constexpr std::uint64_t kIndependentFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kIndependentFnvPrime = 1099511628211ULL;

void independent_consume(std::uint64_t &hash,
                         const std::uint64_t value) {
  hash ^= value;
  hash *= kIndependentFnvPrime;
}

void independent_consume_signed(std::uint64_t &hash, const int value) {
  independent_consume(hash, static_cast<std::uint64_t>(
                                static_cast<std::int64_t>(value)));
}

void independent_consume_face(std::uint64_t &hash,
                              const SourceFaceTopologyKey &topology) {
  for (const auto vertex : topology.vertices()) {
    independent_consume(hash, vertex.index());
  }
}

std::vector<SourceFaceTopologyKey> independent_row_topology(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority) {
  std::vector<SourceFaceTopologyKey> result;
  result.reserve(static_cast<std::size_t>(mesh.F.rows()));
  for (int row = 0; row < mesh.F.rows(); ++row) {
    const SourceFaceId face = SourceFaceId::from_index(
        row, static_cast<std::size_t>(mesh.F.rows())).value();
    result.push_back(sourceAuthority.topology_for_row(face));
  }
  return result;
}

std::uint64_t independent_source_digest(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority) {
  std::vector<SourceFaceTopologyKey> topology =
      independent_row_topology(mesh, sourceAuthority);
  std::sort(topology.begin(), topology.end());
  std::uint64_t hash = kIndependentFnvOffset;
  independent_consume(hash, static_cast<std::size_t>(mesh.V.rows()));
  independent_consume(hash, topology.size());
  for (const SourceFaceTopologyKey &face : topology) {
    independent_consume_face(hash, face);
  }
  return hash;
}

std::uint64_t independent_cycle_digest(
    const FieldCycleWitness &cycle,
    const std::vector<SourceFaceTopologyKey> &rowTopology) {
  std::uint64_t hash = kIndependentFnvOffset;
  independent_consume(hash, static_cast<std::uint64_t>(cycle.kind));
  independent_consume(hash, cycle.localVertex.has_value()
                                ? cycle.localVertex->index() + 1U
                                : 0U);
  independent_consume(hash, cycle.steps.size());
  for (const FieldTransportStep &step : cycle.steps) {
    independent_consume(hash, step.sourceEdge.first().index());
    independent_consume(hash, step.sourceEdge.second().index());
    if (step.fromFace.index() < rowTopology.size()) {
      independent_consume_face(hash, rowTopology[step.fromFace.index()]);
    }
    if (step.toFace.index() < rowTopology.size()) {
      independent_consume_face(hash, rowTopology[step.toFace.index()]);
    }
    independent_consume(hash, step.transport.value());
    independent_consume_signed(hash, step.signedLift);
  }
  independent_consume(hash, cycle.composedTransport.value());
  independent_consume_signed(hash, cycle.turningLift);
  return hash;
}

std::uint64_t independent_holonomy_digest(
    const std::vector<FieldCycleWitness> &cycles,
    const std::vector<SourceFaceTopologyKey> &rowTopology) {
  std::vector<std::uint64_t> digests;
  digests.reserve(cycles.size());
  for (const FieldCycleWitness &cycle : cycles) {
    digests.push_back(independent_cycle_digest(cycle, rowTopology));
  }
  std::sort(digests.begin(), digests.end());
  std::uint64_t hash = kIndependentFnvOffset;
  independent_consume(hash, digests.size());
  for (const std::uint64_t digest : digests) {
    independent_consume(hash, digest);
  }
  return hash;
}

int independent_signature_gcd(const std::vector<int> &signature) {
  int result = 0;
  for (const int value : signature) {
    result = std::gcd(result, std::abs(value));
  }
  return signature.empty() ? 1 : result;
}

std::uint64_t independent_atlas_digest(
    const IndependentAtlasSnapshot &snapshot,
    const std::vector<SourceFaceTopologyKey> &rowTopology) {
  std::uint64_t hash = kIndependentFnvOffset;
  independent_consume(hash, snapshot.sourceDigest);

  independent_consume(hash, snapshot.adjacencies.size());
  for (const FieldTransportAdjacency &adjacency : snapshot.adjacencies) {
    independent_consume(hash, adjacency.sourceEdge.first().index());
    independent_consume(hash, adjacency.sourceEdge.second().index());
    const bool canonicalForward =
        adjacency.firstFaceTopology < adjacency.secondFaceTopology;
    independent_consume_face(
        hash, canonicalForward ? adjacency.firstFaceTopology
                               : adjacency.secondFaceTopology);
    independent_consume_face(
        hash, canonicalForward ? adjacency.secondFaceTopology
                               : adjacency.firstFaceTopology);
    independent_consume(hash, (canonicalForward ? adjacency.forward
                                                : adjacency.reverse)
                                  .value());
    independent_consume(hash, (canonicalForward ? adjacency.reverse
                                                : adjacency.forward)
                                  .value());
    independent_consume_signed(
        hash, canonicalForward ? adjacency.forwardLift
                               : -adjacency.forwardLift);
    double canonicalEffort =
        canonicalForward ? adjacency.effort : -adjacency.effort;
    if (canonicalEffort == 0.0) canonicalEffort = 0.0;
    independent_consume(
        hash, std::bit_cast<std::uint64_t>(canonicalEffort));
  }

  independent_consume(hash, snapshot.nontraversableEdges.size());
  for (const FieldNonTraversableEdge &edge : snapshot.nontraversableEdges) {
    independent_consume(hash, edge.sourceEdge.first().index());
    independent_consume(hash, edge.sourceEdge.second().index());
    independent_consume(hash, static_cast<std::uint64_t>(edge.kind));
  }

  std::vector<std::uint64_t> cycleDigests;
  cycleDigests.reserve(snapshot.cycles.size());
  for (const FieldCycleWitness &cycle : snapshot.cycles) {
    cycleDigests.push_back(independent_cycle_digest(cycle, rowTopology));
  }
  std::sort(cycleDigests.begin(), cycleDigests.end());
  independent_consume(hash, cycleDigests.size());
  for (const std::uint64_t digest : cycleDigests) {
    independent_consume(hash, digest);
  }

  std::vector<std::pair<std::uint64_t, int>> singularities;
  singularities.reserve(snapshot.singularities.size());
  for (const FieldSingularityFact &singularity : snapshot.singularities) {
    singularities.emplace_back(singularity.sourceVertex.index(),
                               singularity.indexNumerator);
  }
  std::sort(singularities.begin(), singularities.end());
  independent_consume(hash, singularities.size());
  for (const auto &[vertex, numerator] : singularities) {
    independent_consume(hash, vertex);
    independent_consume_signed(hash, numerator);
  }

  std::vector<std::tuple<int, int, int, std::size_t, std::size_t,
                         std::size_t, std::size_t, std::size_t>>
      topologyFacts;
  for (const FieldComponentTopology &topology : snapshot.componentTopology) {
    topologyFacts.emplace_back(
        topology.eulerCharacteristic, topology.boundaryLoopCount,
        topology.genus, topology.vertexCount, topology.edgeCount,
        topology.faceCount, topology.localCycleCount,
        topology.handleGeneratorCount);
  }
  std::sort(topologyFacts.begin(), topologyFacts.end());
  independent_consume(hash, topologyFacts.size());
  for (const auto &[euler, boundaries, genus, vertices, edges, faces,
                    localCycles, handles] : topologyFacts) {
    independent_consume_signed(hash, euler);
    independent_consume_signed(hash, boundaries);
    independent_consume_signed(hash, genus);
    independent_consume(hash, vertices);
    independent_consume(hash, edges);
    independent_consume(hash, faces);
    independent_consume(hash, localCycles);
    independent_consume(hash, handles);
  }

  std::vector<std::uint64_t> witnessDigests;
  for (const FieldQuadrangulabilityWitness &witness : snapshot.witnesses) {
    std::uint64_t witnessHash = kIndependentFnvOffset;
    independent_consume(witnessHash,
                        static_cast<std::uint64_t>(witness.kind));
    independent_consume(witnessHash, witness.holonomySignatureDigest);
    independent_consume_signed(witnessHash, witness.numeratorGcd);
    independent_consume_signed(witnessHash, witness.indexSum);
    independent_consume_signed(witnessHash, witness.requiredIndexSum);
    independent_consume(witnessHash, witness.fullSignature.size());
    for (const int value : witness.fullSignature) {
      independent_consume_signed(witnessHash, value);
    }
    independent_consume(witnessHash,
                        witness.singularityNumerators.size());
    for (const int value : witness.singularityNumerators) {
      independent_consume_signed(witnessHash, value);
    }
    independent_consume(witnessHash, witness.exactCycleLifts.size());
    independent_consume(witnessHash, witness.boundaryCycles.size());
    witnessDigests.push_back(witnessHash);
  }
  std::sort(witnessDigests.begin(), witnessDigests.end());
  independent_consume(hash, witnessDigests.size());
  for (const std::uint64_t digest : witnessDigests) {
    independent_consume(hash, digest);
  }
  return hash;
}

std::array<Eigen::RowVector3d, 4> independent_face_branches(
    const CrossFieldResult &field, const int face) {
  const Eigen::RowVector3d first =
      field.primaryDirections.row(face).normalized();
  const Eigen::RowVector3d second =
      field.secondaryDirections.row(face).normalized();
  return {first, second, -first, -second};
}

struct IndependentEdgeMeasurement {
  int matching = 0;
  double effort = 0.0;
};

double independent_signed_angle(const Eigen::Vector3d &from,
                                const Eigen::Vector3d &to,
                                const Eigen::Vector3d &normal) {
  const Eigen::Vector3d a = from.normalized();
  const Eigen::Vector3d b = to.normalized();
  return std::atan2(normal.dot(a.cross(b)),
                    std::clamp(a.dot(b), -1.0, 1.0));
}

IndependentEdgeMeasurement independent_edge_measurement(
    const TriMesh &mesh, const CrossFieldResult &field, const int sourceFace,
    const int targetFace, const SourceEdgeTopologyKey &edge) {
  const auto sourceBranches = independent_face_branches(field, sourceFace);
  const auto targetBranches = independent_face_branches(field, targetFace);
  const Eigen::Vector3d sourceA =
      (mesh.V.row(mesh.F(sourceFace, 1)) -
       mesh.V.row(mesh.F(sourceFace, 0)))
          .transpose();
  const Eigen::Vector3d sourceB =
      (mesh.V.row(mesh.F(sourceFace, 2)) -
       mesh.V.row(mesh.F(sourceFace, 0)))
          .transpose();
  const Eigen::Vector3d targetA =
      (mesh.V.row(mesh.F(targetFace, 1)) -
       mesh.V.row(mesh.F(targetFace, 0)))
          .transpose();
  const Eigen::Vector3d targetB =
      (mesh.V.row(mesh.F(targetFace, 2)) -
       mesh.V.row(mesh.F(targetFace, 0)))
          .transpose();
  const Eigen::Vector3d sourceNormal = sourceA.cross(sourceB).normalized();
  const Eigen::Vector3d targetNormal = targetA.cross(targetB).normalized();
  Eigen::Vector3d axis =
      (mesh.V.row(static_cast<int>(edge.second().index())) -
       mesh.V.row(static_cast<int>(edge.first().index())))
          .transpose();
  axis.normalize();
  const double connectionAngle = std::atan2(
      axis.dot(sourceNormal.cross(targetNormal)),
      sourceNormal.dot(targetNormal));
  const Eigen::AngleAxisd connection(connectionAngle, axis);

  std::array<Eigen::Vector3d, 4> transported;
  for (int branch = 0; branch < 4; ++branch) {
    transported[static_cast<std::size_t>(branch)] =
        connection * sourceBranches[static_cast<std::size_t>(branch)].transpose();
  }

  int principalBranch = 0;
  double smallestRotation = std::numeric_limits<double>::infinity();
  for (int branch = 0; branch < 4; ++branch) {
    const double rotation = independent_signed_angle(
        transported[0], targetBranches[static_cast<std::size_t>(branch)].transpose(),
        targetNormal);
    if (std::abs(rotation) < std::abs(smallestRotation)) {
      smallestRotation = rotation;
      principalBranch = branch;
    }
  }

  double freeRotation = 0.0;
  for (int branch = 0; branch < 4; ++branch) {
    freeRotation += independent_signed_angle(
        transported[static_cast<std::size_t>(branch)],
        targetBranches[static_cast<std::size_t>(branch)].transpose(),
        targetNormal);
  }
  const double effort = std::atan2(std::sin(freeRotation),
                                   std::cos(freeRotation));

  double selectedRotation = 0.0;
  for (int branch = 0; branch < 4; ++branch) {
    selectedRotation += independent_signed_angle(
        transported[static_cast<std::size_t>(branch)],
        targetBranches[static_cast<std::size_t>(
            (branch + principalBranch) % 4)]
            .transpose(),
        targetNormal);
  }
  const int matching = static_cast<int>(
      principalBranch -
      std::llround((selectedRotation - effort) /
                   (2.0 * std::numbers::pi)));
  return IndependentEdgeMeasurement{matching, effort};
}

int independent_connection_matching(const TriMesh &mesh,
                                    const CrossFieldResult &field,
                                    const int sourceFace,
                                    const int targetFace,
                                    const SourceEdgeTopologyKey &edge) {
  return independent_edge_measurement(mesh, field, sourceFace, targetFace, edge)
      .matching;
}

using IndependentSupportKey =
    std::tuple<std::uint64_t, std::uint64_t, std::uint64_t, std::uint64_t>;

struct IndependentCycleRow {
  FieldCycleKind kind = FieldCycleKind::HandleGenerator;
  std::optional<std::uint64_t> localVertex;
  std::vector<std::pair<int, int>> edgeSigns;
  std::vector<IndependentSupportKey> support;
  int turningLift = 0;
  QuarterTurn composed;
};

int independent_corner_for_vertex(const TriMesh &mesh, const int face,
                                  const int vertex) {
  for (int corner = 0; corner < 3; ++corner) {
    if (mesh.F(face, corner) == vertex) return corner;
  }
  return -1;
}

double independent_corner_angle(const TriMesh &mesh, const int face,
                                const int corner) {
  const Eigen::Vector3d first =
      (mesh.V.row(mesh.F(face, (corner + 1) % 3)) -
       mesh.V.row(mesh.F(face, corner)))
          .transpose();
  const Eigen::Vector3d second =
      (mesh.V.row(mesh.F(face, (corner + 2) % 3)) -
       mesh.V.row(mesh.F(face, corner)))
          .transpose();
  return std::acos(std::clamp(first.normalized().dot(second.normalized()),
                              -1.0, 1.0));
}

double independent_cycle_curvature(const TriMesh &mesh,
                                   const IndependentCycleRow &row) {
  std::set<int> corners;
  std::set<int> vertices;
  for (const auto &[edge, sign] : row.edgeSigns) {
    if (edge < 0 || edge >= mesh.EV.rows() || mesh.EF(edge, 0) < 0 ||
        mesh.EF(edge, 1) < 0 || (sign != -1 && sign != 1)) {
      return std::numeric_limits<double>::quiet_NaN();
    }
    const int firstCorner = independent_corner_for_vertex(
        mesh, mesh.EF(edge, 0), mesh.EV(edge, 0));
    const int secondCorner = independent_corner_for_vertex(
        mesh, mesh.EF(edge, 1), mesh.EV(edge, 1));
    if (firstCorner < 0 || secondCorner < 0) {
      return std::numeric_limits<double>::quiet_NaN();
    }
    if (sign < 0) {
      corners.insert(mesh.EF(edge, 0) * 3 + firstCorner);
      corners.insert(mesh.EF(edge, 1) * 3 + (secondCorner + 1) % 3);
      vertices.insert(mesh.EV(edge, 0));
    } else {
      corners.insert(mesh.EF(edge, 0) * 3 + (firstCorner + 1) % 3);
      corners.insert(mesh.EF(edge, 1) * 3 + secondCorner);
      vertices.insert(mesh.EV(edge, 1));
    }
  }

  double curvature = row.kind == FieldCycleKind::LocalVertex
                         ? 2.0 * std::numbers::pi
                         : std::numbers::pi *
                               static_cast<double>(vertices.size());
  for (const int encoded : corners) {
    curvature -= independent_corner_angle(mesh, encoded / 3, encoded % 3);
  }
  return curvature;
}

std::vector<std::pair<int, int>> independent_vertex_cycle(
    const TriMesh &mesh, const int vertex) {
  std::vector<std::pair<int, int>> result;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (mesh.EF(edge, 1) < 0) continue;
    if (mesh.EV(edge, 0) == vertex) {
      result.emplace_back(edge, -1);
    } else if (mesh.EV(edge, 1) == vertex) {
      result.emplace_back(edge, 1);
    }
  }
  return result;
}

std::vector<IndependentCycleRow> independent_cycle_rows(const TriMesh &mesh) {
  std::vector<IndependentCycleRow> rows;
  std::vector<bool> boundaryVertex(static_cast<std::size_t>(mesh.V.rows()),
                                   false);
  for (int vertex = 0; vertex < mesh.V.rows(); ++vertex) {
    boundaryVertex[static_cast<std::size_t>(vertex)] =
        mesh.isBoundaryVertex(vertex) != 0;
    if (!boundaryVertex[static_cast<std::size_t>(vertex)]) {
      rows.push_back(IndependentCycleRow{
          FieldCycleKind::LocalVertex,
          static_cast<std::uint64_t>(vertex),
          independent_vertex_cycle(mesh, vertex), {}, 0, QuarterTurn{}});
    }
  }

  for (const auto &loop : mesh.boundaryLoops) {
    std::map<int, int> coefficients;
    for (const int vertex : loop) {
      for (const auto &[edge, sign] : independent_vertex_cycle(mesh, vertex)) {
        coefficients[edge] += sign;
      }
    }
    IndependentCycleRow row;
    row.kind = FieldCycleKind::BoundaryLoop;
    for (const auto &[edge, coefficient] : coefficients) {
      if (coefficient == 0) continue;
      if (coefficient != -1 && coefficient != 1) return {};
      row.edgeSigns.emplace_back(edge, coefficient);
    }
    rows.push_back(std::move(row));
  }

  const int eulerCharacteristic =
      static_cast<int>(mesh.V.rows() - mesh.EV.rows() + mesh.F.rows());
  const int expectedHandles =
      2 - static_cast<int>(mesh.boundaryLoops.size()) - eulerCharacteristic;
  if (expectedHandles <= 0) return rows;

  DisjointSet primal(mesh.V.rows());
  std::set<int> primalTree;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (primal.join(mesh.EV(edge, 0), mesh.EV(edge, 1))) {
      primalTree.insert(edge);
    }
  }
  DisjointSet dual(mesh.F.rows());
  std::set<int> dualTree;
  for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
    if (mesh.EF(edge, 1) < 0 || primalTree.count(edge) != 0U) continue;
    if (dual.join(mesh.EF(edge, 0), mesh.EF(edge, 1))) dualTree.insert(edge);
  }
  std::vector<std::vector<std::pair<int, int>>> dualAdjacency(
      static_cast<std::size_t>(mesh.F.rows()));
  for (const int edge : dualTree) {
    const int first = mesh.EF(edge, 0);
    const int second = mesh.EF(edge, 1);
    dualAdjacency[static_cast<std::size_t>(first)].emplace_back(second, edge);
    dualAdjacency[static_cast<std::size_t>(second)].emplace_back(first, edge);
  }

  int handles = 0;
  for (int chord = 0; chord < mesh.EV.rows() && handles < expectedHandles;
       ++chord) {
    if (mesh.EF(chord, 1) < 0 || primalTree.count(chord) != 0U ||
        dualTree.count(chord) != 0U) {
      continue;
    }
    const int start = mesh.EF(chord, 1);
    const int target = mesh.EF(chord, 0);
    std::vector<int> parent(static_cast<std::size_t>(mesh.F.rows()), -2);
    std::vector<int> parentEdge(static_cast<std::size_t>(mesh.F.rows()), -1);
    std::vector<int> stack{start};
    parent[static_cast<std::size_t>(start)] = -1;
    while (!stack.empty() && parent[static_cast<std::size_t>(target)] == -2) {
      const int face = stack.back();
      stack.pop_back();
      for (const auto &[next, edge] :
           dualAdjacency[static_cast<std::size_t>(face)]) {
        if (parent[static_cast<std::size_t>(next)] != -2) continue;
        parent[static_cast<std::size_t>(next)] = face;
        parentEdge[static_cast<std::size_t>(next)] = edge;
        stack.push_back(next);
      }
    }
    if (parent[static_cast<std::size_t>(target)] == -2) continue;

    std::map<int, int> coefficients;
    coefficients[chord] = 1;
    int current = target;
    while (current != start) {
      const int next = parent[static_cast<std::size_t>(current)];
      const int edge = parentEdge[static_cast<std::size_t>(current)];
      if (next < 0 || edge < 0) {
        coefficients.clear();
        break;
      }
      if (mesh.EF(edge, 0) == current && mesh.EF(edge, 1) == next) {
        coefficients[edge] += 1;
      } else if (mesh.EF(edge, 1) == current &&
                 mesh.EF(edge, 0) == next) {
        coefficients[edge] -= 1;
      } else {
        coefficients.clear();
        break;
      }
      current = next;
    }
    if (coefficients.empty()) continue;

    IndependentCycleRow row;
    row.kind = FieldCycleKind::HandleGenerator;
    bool hasPureInteriorEdge = false;
    for (const auto &[edge, coefficient] : coefficients) {
      if (coefficient == 0) continue;
      if (coefficient != -1 && coefficient != 1) {
        row.edgeSigns.clear();
        break;
      }
      row.edgeSigns.emplace_back(edge, coefficient);
      hasPureInteriorEdge =
          hasPureInteriorEdge ||
          (!boundaryVertex[static_cast<std::size_t>(mesh.EV(edge, 0))] &&
           !boundaryVertex[static_cast<std::size_t>(mesh.EV(edge, 1))]);
    }
    if (row.edgeSigns.empty() ||
        (!mesh.boundaryLoops.empty() && !hasPureInteriorEdge)) {
      continue;
    }
    rows.push_back(std::move(row));
    ++handles;
  }
  if (handles != expectedHandles) return {};
  return rows;
}

std::optional<std::vector<IndependentCycleRow>> independent_cycle_facts(
    const TriMesh &mesh, const CrossFieldResult &field) {
  std::vector<IndependentCycleRow> rows = independent_cycle_rows(mesh);
  const int expectedCount =
      static_cast<int>(std::count_if(
          rows.begin(), rows.end(), [](const IndependentCycleRow &row) {
            return row.kind == FieldCycleKind::LocalVertex;
          })) +
      static_cast<int>(mesh.boundaryLoops.size()) +
      (2 - static_cast<int>(mesh.boundaryLoops.size()) -
       static_cast<int>(mesh.V.rows() - mesh.EV.rows() + mesh.F.rows()));
  if (rows.empty() && expectedCount != 0) return std::nullopt;

  for (IndependentCycleRow &row : rows) {
    double effortSum = 0.0;
    int matchingSum = 0;
    row.support.clear();
    for (const auto &[edge, sign] : row.edgeSigns) {
      if (mesh.EF(edge, 0) < 0 || mesh.EF(edge, 1) < 0) return std::nullopt;
      const SourceEdgeTopologyKey key = edge_key(mesh, edge);
      const IndependentEdgeMeasurement measurement = independent_edge_measurement(
          mesh, field, mesh.EF(edge, 0), mesh.EF(edge, 1), key);
      effortSum += static_cast<double>(sign) * measurement.effort;
      matchingSum += sign * measurement.matching;
      const std::uint64_t from = static_cast<std::uint64_t>(
          sign > 0 ? mesh.EF(edge, 0) : mesh.EF(edge, 1));
      const std::uint64_t to = static_cast<std::uint64_t>(
          sign > 0 ? mesh.EF(edge, 1) : mesh.EF(edge, 0));
      row.support.emplace_back(key.first().index(), key.second().index(), from,
                               to);
    }
    std::sort(row.support.begin(), row.support.end());
    const double curvature = independent_cycle_curvature(mesh, row);
    if (!std::isfinite(curvature)) return std::nullopt;
    const double exactLift =
        (effortSum + 4.0 * curvature) / (2.0 * std::numbers::pi);
    const double rounded = std::round(exactLift);
    if (!std::isfinite(exactLift) || std::abs(exactLift - rounded) >= 1.0e-6) {
      return std::nullopt;
    }
    row.turningLift = static_cast<int>(rounded);
    row.composed = QuarterTurn::from_integer(matchingSum);
    if (static_cast<int>(row.composed.value()) !=
        ((row.turningLift % 4) + 4) % 4) {
      return std::nullopt;
    }
  }

  const int requiredIndexSum =
      4 * static_cast<int>(mesh.V.rows() - mesh.EV.rows() + mesh.F.rows());
  int localIndexSum = 0;
  int boundaryIndexSum = 0;
  std::size_t firstBoundary = rows.size();
  for (std::size_t index = 0; index < rows.size(); ++index) {
    if (rows[index].kind == FieldCycleKind::LocalVertex) {
      localIndexSum += rows[index].turningLift;
    } else if (rows[index].kind == FieldCycleKind::BoundaryLoop) {
      if (firstBoundary == rows.size()) firstBoundary = index;
      boundaryIndexSum += rows[index].turningLift;
    }
  }
  if (!mesh.boundaryLoops.empty()) {
    if (firstBoundary == rows.size()) return std::nullopt;
    const int correction =
        requiredIndexSum - localIndexSum - boundaryIndexSum;
    if (correction % 4 != 0) return std::nullopt;
    rows[firstBoundary].turningLift += correction;
    rows[firstBoundary].composed =
        QuarterTurn::from_integer(rows[firstBoundary].turningLift);
  }
  return rows;
}

std::vector<IndependentSupportKey> independent_published_support(
    const FieldCycleWitness &cycle) {
  std::vector<IndependentSupportKey> support;
  support.reserve(cycle.steps.size());
  for (const FieldTransportStep &step : cycle.steps) {
    support.emplace_back(step.sourceEdge.first().index(),
                         step.sourceEdge.second().index(),
                         step.fromFace.index(), step.toFace.index());
  }
  std::sort(support.begin(), support.end());
  return support;
}

std::optional<FieldAtlasBuildErrorCode> independent_validate_snapshot(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority,
    const CrossFieldResult &field,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges,
    const IndependentAtlasSnapshot &snapshot) {
  const auto rowTopology = independent_row_topology(mesh, sourceAuthority);
  if (snapshot.sourceDigest !=
      independent_source_digest(mesh, sourceAuthority)) {
    return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
  }

  std::map<SourceEdgeTopologyKey, const CrossFieldEdgeTransition *> raw;
  for (const CrossFieldEdgeTransition &transition : field.edgeTransitions) {
    const auto key = SourceEdgeTopologyKey::from_indices(
        transition.sourceVertex0, transition.sourceVertex1,
        static_cast<std::size_t>(mesh.V.rows()));
    if (!key) return FieldAtlasBuildErrorCode::InvalidInput;
    if (!raw.emplace(key.value(), &transition).second) {
      return FieldAtlasBuildErrorCode::DuplicateAdjacency;
    }
  }

  if (!field.singularitiesComputed ||
      field.singularCycles.size() != field.singularIndices.size()) {
    return FieldAtlasBuildErrorCode::InvalidInput;
  }
  std::map<std::uint64_t, int> rawSingularities;
  for (Eigen::Index index = 0; index < field.singularCycles.size(); ++index) {
    const int vertex = field.singularCycles(index);
    const int numerator = field.singularIndices(index);
    if (vertex < 0 || vertex >= mesh.V.rows() || numerator == 0 ||
        !rawSingularities
             .emplace(static_cast<std::uint64_t>(vertex), numerator)
             .second) {
      return FieldAtlasBuildErrorCode::SingularityMismatch;
    }
  }

  std::map<SourceEdgeTopologyKey, const FieldTransportAdjacency *> adjacency;
  for (const FieldTransportAdjacency &candidate : snapshot.adjacencies) {
    if (!adjacency.emplace(candidate.sourceEdge, &candidate).second) {
      return FieldAtlasBuildErrorCode::DuplicateAdjacency;
    }
  }
  std::map<SourceEdgeTopologyKey, FieldTransportBarrierKind> barriers;
  for (const FieldNonTraversableEdge &candidate :
       snapshot.nontraversableEdges) {
    if (!barriers.emplace(candidate.sourceEdge, candidate.kind).second) {
      return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
    }
  }

  std::size_t traversableCount = 0U;
  std::size_t barrierCount = 0U;
  for (int edgeIndex = 0; edgeIndex < mesh.EV.rows(); ++edgeIndex) {
    const SourceEdgeTopologyKey edge = edge_key(mesh, edgeIndex);
    const int firstRaw = mesh.EF(edgeIndex, 0);
    const int secondRaw = mesh.EF(edgeIndex, 1);
    const SourceFaceId first = SourceFaceId::from_index(
        firstRaw, static_cast<std::size_t>(mesh.F.rows())).value();
    const std::optional<SourceFaceId> second =
        secondRaw >= 0
            ? std::optional<SourceFaceId>(SourceFaceId::from_index(
                  secondRaw, static_cast<std::size_t>(mesh.F.rows())).value())
            : std::nullopt;
    std::optional<FieldTransportBarrierKind> expectedBarrier;
    if (!second.has_value()) {
      expectedBarrier = FieldTransportBarrierKind::SourceBoundary;
    } else if (hardFeatureEdges.count(edge) != 0U) {
      expectedBarrier = FieldTransportBarrierKind::HardFeature;
    } else if (sourceAuthority.region_for_row(first) !=
                   sourceAuthority.region_for_row(*second) ||
               sourceAuthority.component_for_row(first) !=
                   sourceAuthority.component_for_row(*second)) {
      expectedBarrier = FieldTransportBarrierKind::NonTraversable;
    }
    if (expectedBarrier.has_value()) {
      ++barrierCount;
      const auto found = barriers.find(edge);
      if (found == barriers.end() || found->second != *expectedBarrier) {
        return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
      }
      continue;
    }

    ++traversableCount;
    const auto found = adjacency.find(edge);
    if (found == adjacency.end()) {
      return FieldAtlasBuildErrorCode::MissingAdjacency;
    }
    const auto rawFound = raw.find(edge);
    if (rawFound == raw.end()) {
      return FieldAtlasBuildErrorCode::MissingAdjacency;
    }
    const FieldTransportAdjacency &typed = *found->second;
    const CrossFieldEdgeTransition &transition = *rawFound->second;
    if (typed.firstFace.index() >= rowTopology.size() ||
        typed.secondFace.index() >= rowTopology.size() ||
        typed.firstFaceTopology != rowTopology[typed.firstFace.index()] ||
        typed.secondFaceTopology != rowTopology[typed.secondFace.index()] ||
        compose(typed.forward, typed.reverse) !=
            QuarterTurn{} ||
        typed.reverse != typed.forward.inverse() ||
        static_cast<int>(typed.forward.value()) !=
            ((typed.forwardLift % 4) + 4) % 4) {
      return FieldAtlasBuildErrorCode::NonReciprocalAdjacency;
    }
    const IndependentEdgeMeasurement sourceMeasurement =
        independent_edge_measurement(mesh, field, transition.firstFace,
                                     transition.secondFace, edge);
    if (transition.firstFace != static_cast<int>(typed.firstFace.index()) ||
        transition.secondFace != static_cast<int>(typed.secondFace.index()) ||
        transition.matching != typed.forwardLift ||
        transition.effort != typed.effort ||
        sourceMeasurement.matching != transition.matching ||
        std::abs(sourceMeasurement.effort - transition.effort) >= 1.0e-6 ||
        QuarterTurn::from_integer(sourceMeasurement.matching) != typed.forward) {
      return FieldAtlasBuildErrorCode::NonReciprocalAdjacency;
    }
  }
  if (adjacency.size() != traversableCount) {
    return FieldAtlasBuildErrorCode::DuplicateAdjacency;
  }
  if (barriers.size() != barrierCount) {
    return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
  }

  if (sourceAuthority.regions().size() != 1U ||
      snapshot.componentTopology.size() != 1U ||
      snapshot.witnesses.size() != 1U) {
    return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
  }
  const IndependentOracleSummary topology =
      independent_oracle(mesh, field, hardFeatureEdges);
  std::size_t localCycles = 0U;
  for (int vertex = 0; vertex < mesh.V.rows(); ++vertex) {
    if (mesh.isBoundaryVertex(vertex) == 0) ++localCycles;
  }
  const FieldComponentTopology &publishedTopology =
      snapshot.componentTopology.front();
  const int expectedGenusNumerator =
      2 - topology.boundaryLoops - topology.eulerCharacteristic;
  if (expectedGenusNumerator < 0 || expectedGenusNumerator % 2 != 0 ||
      publishedTopology.topologyRegion !=
          sourceAuthority.regions().front().id() ||
      publishedTopology.sourceComponent !=
          sourceAuthority.regions().front().component() ||
      publishedTopology.eulerCharacteristic != topology.eulerCharacteristic ||
      publishedTopology.boundaryLoopCount != topology.boundaryLoops ||
      publishedTopology.genus != expectedGenusNumerator / 2 ||
      publishedTopology.vertexCount !=
          static_cast<std::size_t>(mesh.V.rows()) ||
      publishedTopology.edgeCount !=
          static_cast<std::size_t>(mesh.EV.rows()) ||
      publishedTopology.faceCount !=
          static_cast<std::size_t>(mesh.F.rows()) ||
      publishedTopology.localCycleCount != localCycles ||
      publishedTopology.handleGeneratorCount !=
          static_cast<std::size_t>(topology.handleGenerators)) {
    return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
  }

  const std::size_t expectedCycleCount =
      localCycles + static_cast<std::size_t>(topology.boundaryLoops) +
      static_cast<std::size_t>(topology.handleGenerators);
  if (snapshot.cycles.size() != expectedCycleCount) {
    return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
  }
  const auto expectedCycleFacts = independent_cycle_facts(mesh, field);
  if (!expectedCycleFacts.has_value() ||
      expectedCycleFacts->size() != snapshot.cycles.size()) {
    return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
  }
  std::vector<bool> matchedExpected(expectedCycleFacts->size(), false);
  std::size_t localCount = 0U;
  std::size_t boundaryCount = 0U;
  std::size_t handleCount = 0U;
  std::map<std::uint64_t, FieldCycleId> localCycleByVertex;
  for (std::size_t cycleIndex = 0; cycleIndex < snapshot.cycles.size();
       ++cycleIndex) {
    const FieldCycleWitness &cycle = snapshot.cycles[cycleIndex];
    const std::vector<IndependentSupportKey> publishedSupport =
        independent_published_support(cycle);
    std::optional<std::size_t> expectedIndex;
    for (std::size_t candidate = 0; candidate < expectedCycleFacts->size();
         ++candidate) {
      if (matchedExpected[candidate]) continue;
      const IndependentCycleRow &expected = (*expectedCycleFacts)[candidate];
      if (expected.kind != cycle.kind || expected.support != publishedSupport) {
        continue;
      }
      if (expected.localVertex.has_value() != cycle.localVertex.has_value()) {
        continue;
      }
      if (expected.localVertex.has_value() &&
          *expected.localVertex != cycle.localVertex->index()) {
        continue;
      }
      expectedIndex = candidate;
      break;
    }
    if (!expectedIndex.has_value()) {
      return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
    }
    matchedExpected[*expectedIndex] = true;
    const IndependentCycleRow &expectedCycle =
        (*expectedCycleFacts)[*expectedIndex];
    if (cycle.id.index() != cycleIndex ||
        cycle.topologyRegion != publishedTopology.topologyRegion ||
        cycle.sourceComponent != publishedTopology.sourceComponent) {
      return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
    }
    if (cycle.kind == FieldCycleKind::LocalVertex) {
      ++localCount;
      if (!cycle.localVertex.has_value() ||
          cycle.localVertex->index() >=
              static_cast<std::size_t>(mesh.V.rows()) ||
          mesh.isBoundaryVertex(
              static_cast<int>(cycle.localVertex->index())) != 0 ||
          !localCycleByVertex
               .emplace(cycle.localVertex->index(), cycle.id)
               .second) {
        return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
      }
    } else if (cycle.kind == FieldCycleKind::BoundaryLoop) {
      ++boundaryCount;
      if (cycle.localVertex.has_value()) {
        return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
      }
    } else if (cycle.kind == FieldCycleKind::HandleGenerator) {
      ++handleCount;
      if (cycle.localVertex.has_value()) {
        return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
      }
    } else {
      return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
    }
    QuarterTurn composed;
    std::optional<SourceFaceId> start;
    std::optional<SourceFaceId> current;
    for (const FieldTransportStep &step : cycle.steps) {
      if (!start.has_value()) {
        start = step.fromFace;
        current = step.fromFace;
      }
      if (*current != step.fromFace ||
          step.adjacency.index() >= snapshot.adjacencies.size()) {
        return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
      }
      const FieldTransportAdjacency &edge =
          snapshot.adjacencies[step.adjacency.index()];
      const bool forward = edge.firstFace == step.fromFace &&
                           edge.secondFace == step.toFace;
      const bool reverse = edge.secondFace == step.fromFace &&
                           edge.firstFace == step.toFace;
      if ((!forward && !reverse) || edge.sourceEdge != step.sourceEdge ||
          step.transport != (forward ? edge.forward : edge.reverse) ||
          step.signedLift !=
              (forward ? edge.forwardLift : -edge.forwardLift)) {
        return FieldAtlasBuildErrorCode::CycleTransportMismatch;
      }
      composed = compose(step.transport, composed);
      current = step.toFace;
    }
    if (start.has_value() && current != start) {
      return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
    }
    if (composed != cycle.composedTransport ||
        cycle.composedTransport != expectedCycle.composed ||
        cycle.turningLift != expectedCycle.turningLift ||
        static_cast<int>(expectedCycle.composed.value()) !=
            ((expectedCycle.turningLift % 4) + 4) % 4) {
      return FieldAtlasBuildErrorCode::CycleTransportMismatch;
    }
    if (cycle.kind == FieldCycleKind::LocalVertex) {
      const auto expected =
          rawSingularities.find(cycle.localVertex->index());
      if ((expected == rawSingularities.end() &&
           cycle.turningLift != 0) ||
          (expected != rawSingularities.end() &&
           cycle.turningLift != expected->second)) {
        return FieldAtlasBuildErrorCode::SingularityMismatch;
      }
    }
  }
  if (localCount != localCycles ||
      boundaryCount != static_cast<std::size_t>(topology.boundaryLoops) ||
      handleCount != static_cast<std::size_t>(topology.handleGenerators) ||
      std::find(matchedExpected.begin(), matchedExpected.end(), false) !=
          matchedExpected.end()) {
    return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
  }

  if (snapshot.singularities.size() != rawSingularities.size()) {
    return FieldAtlasBuildErrorCode::SingularityMismatch;
  }
  std::set<std::uint64_t> publishedSingularities;
  for (std::size_t singularityIndex = 0;
       singularityIndex < snapshot.singularities.size();
       ++singularityIndex) {
    const FieldSingularityFact &singularity =
        snapshot.singularities[singularityIndex];
    const std::uint64_t vertex = singularity.sourceVertex.index();
    const auto expected = rawSingularities.find(vertex);
    if (singularity.id.index() != singularityIndex ||
        expected == rawSingularities.end() ||
        expected->second != singularity.indexNumerator ||
        !publishedSingularities.emplace(vertex).second) {
      return FieldAtlasBuildErrorCode::SingularityMismatch;
    }

    std::optional<SourceFaceId> incidentFace;
    for (int face = 0; face < mesh.F.rows() && !incidentFace.has_value();
         ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        if (mesh.F(face, corner) == static_cast<int>(vertex)) {
          incidentFace = SourceFaceId::from_index(
              face, static_cast<std::size_t>(mesh.F.rows())).value();
          break;
        }
      }
    }
    if (!incidentFace.has_value() ||
        singularity.sourceComponent !=
            sourceAuthority.component_for_row(*incidentFace)) {
      return FieldAtlasBuildErrorCode::SingularityMismatch;
    }

    const auto localCycle = localCycleByVertex.find(vertex);
    if (localCycle == localCycleByVertex.end()) {
      if (singularity.topologyRegion.has_value() ||
          singularity.localCycle.has_value()) {
        return FieldAtlasBuildErrorCode::SingularityMismatch;
      }
    } else if (!singularity.topologyRegion.has_value() ||
               *singularity.topologyRegion !=
                   publishedTopology.topologyRegion ||
               !singularity.localCycle.has_value() ||
               *singularity.localCycle != localCycle->second) {
      return FieldAtlasBuildErrorCode::SingularityMismatch;
    }
  }

  const FieldQuadrangulabilityWitness &witness = snapshot.witnesses.front();
  const auto expectedKind =
      topology.boundaryLoops == 0
          ? FieldQuadrangulabilityWitnessKind::ClosedShenSufficient
          : FieldQuadrangulabilityWitnessKind::RelativeBoundary;
  if (!snapshot.established ||
      witness.topologyRegion != publishedTopology.topologyRegion ||
      witness.sourceComponent != publishedTopology.sourceComponent ||
      witness.kind != expectedKind) {
    return FieldAtlasBuildErrorCode::UnestablishedAdmissibility;
  }
  std::vector<int> singularityNumerators;
  std::vector<int> fullSignature;
  std::vector<std::uint64_t> expectedCycles;
  std::vector<std::uint64_t> expectedBoundaryCycles;
  int localIndexSum = 0;
  for (const FieldCycleWitness &cycle : snapshot.cycles) {
    expectedCycles.push_back(cycle.id.index());
    if (cycle.kind == FieldCycleKind::BoundaryLoop) {
      expectedBoundaryCycles.push_back(cycle.id.index());
    }
    if (cycle.kind == FieldCycleKind::LocalVertex) {
      localIndexSum += cycle.turningLift;
    }
    if (cycle.turningLift != 0) {
      fullSignature.push_back(cycle.turningLift);
    }
  }
  for (const auto &[vertex, numerator] : rawSingularities) {
    if (localCycleByVertex.count(vertex) != 0U) {
      singularityNumerators.push_back(numerator);
    }
  }
  std::sort(singularityNumerators.begin(), singularityNumerators.end());
  std::sort(fullSignature.begin(), fullSignature.end());
  std::vector<std::uint64_t> publishedCycles;
  for (const auto id : witness.exactCycleLifts) {
    publishedCycles.push_back(id.index());
  }
  std::vector<std::uint64_t> publishedBoundaryCycles;
  for (const auto id : witness.boundaryCycles) {
    publishedBoundaryCycles.push_back(id.index());
  }
  std::sort(publishedCycles.begin(), publishedCycles.end());
  std::sort(publishedBoundaryCycles.begin(), publishedBoundaryCycles.end());
  const int requiredIndexSum = 4 * topology.eulerCharacteristic;
  if (publishedCycles != expectedCycles ||
      publishedBoundaryCycles != expectedBoundaryCycles ||
      witness.singularityNumerators != singularityNumerators ||
      witness.fullSignature != fullSignature ||
      witness.numeratorGcd != independent_signature_gcd(fullSignature) ||
      witness.requiredIndexSum != requiredIndexSum ||
      witness.indexSum !=
          (topology.boundaryLoops == 0 ? localIndexSum : requiredIndexSum) ||
      witness.holonomySignatureDigest !=
          independent_holonomy_digest(snapshot.cycles, rowTopology)) {
    return FieldAtlasBuildErrorCode::UnestablishedAdmissibility;
  }
  if (topology.boundaryLoops == 0 &&
      (localIndexSum != requiredIndexSum || witness.numeratorGcd != 1)) {
    return FieldAtlasBuildErrorCode::GaussBonnetPoincareHopfMismatch;
  }
  if (snapshot.atlasDigest !=
      independent_atlas_digest(snapshot, rowTopology)) {
    return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
  }
  return std::nullopt;
}

TEST(FieldTransportAtlas,
     PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness) {
  const TriMesh mesh = make_square_mesh();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const CrossFieldResult field = make_zero_transport_field(mesh);

  const std::vector<IndependentCycleRow> sourceCycles =
      independent_cycle_rows(mesh);
  ASSERT_EQ(1U, sourceCycles.size());
  EXPECT_EQ(FieldCycleKind::BoundaryLoop, sourceCycles.front().kind);
  EXPECT_TRUE(sourceCycles.front().edgeSigns.empty());

  const auto sourceCycleFacts = independent_cycle_facts(mesh, field);
  ASSERT_TRUE(sourceCycleFacts.has_value());
  ASSERT_EQ(1U, sourceCycleFacts->size());
  const IndependentCycleRow &sourceBoundaryCycle = sourceCycleFacts->front();
  EXPECT_EQ(FieldCycleKind::BoundaryLoop, sourceBoundaryCycle.kind);
  EXPECT_TRUE(sourceBoundaryCycle.support.empty());
  EXPECT_EQ(QuarterTurn{}, sourceBoundaryCycle.composed);
  EXPECT_EQ(4, sourceBoundaryCycle.turningLift);

  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built);
  const FieldTransportAtlas &atlas = built.value();
  ASSERT_EQ(1U, atlas.adjacencies().size());
  ASSERT_EQ(4U, atlas.nontraversable_edges().size());
  ASSERT_EQ(1U, atlas.cycles().size());
  const FieldCycleWitness &boundaryCycle = atlas.cycles().front();
  EXPECT_EQ(FieldCycleKind::BoundaryLoop, boundaryCycle.kind);
  EXPECT_TRUE(boundaryCycle.steps.empty());
  EXPECT_EQ(QuarterTurn{}, boundaryCycle.composedTransport);
  EXPECT_EQ(sourceBoundaryCycle.turningLift, boundaryCycle.turningLift);
  EXPECT_TRUE(atlas.quadrangulability().established());
  ASSERT_EQ(1U, atlas.quadrangulability().witnesses().size());
  const auto &witness = atlas.quadrangulability().witnesses().front();
  EXPECT_EQ(FieldQuadrangulabilityWitnessKind::RelativeBoundary,
            witness.kind);
  EXPECT_EQ(4, witness.indexSum);
  EXPECT_EQ(4, witness.requiredIndexSum);
  ASSERT_EQ(1U, witness.boundaryCycles.size());
  EXPECT_NE(0U, witness.holonomySignatureDigest);
  EXPECT_NE(0U, atlas.quadrangulability().source_digest());
  EXPECT_NE(0U, atlas.quadrangulability().atlas_digest());
  EXPECT_EQ(atlas.quadrangulability().atlas_digest(),
            directional::authority::field_transport_atlas_hash(atlas));
  EXPECT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, independent_snapshot(atlas))
                   .has_value());

  const auto &adjacency = atlas.adjacencies().front();
  const auto forward = atlas.transport(adjacency.sourceEdge,
                                       adjacency.firstFace,
                                       adjacency.secondFace);
  const auto reverse = atlas.transport(adjacency.sourceEdge,
                                       adjacency.secondFace,
                                       adjacency.firstFace);
  ASSERT_TRUE(forward.has_value());
  ASSERT_TRUE(reverse.has_value());
  EXPECT_EQ(directional::authority::QuarterTurn{},
            compose(forward->transport, reverse->transport));
  EXPECT_EQ(forward->signedLift, -reverse->signedLift);
}

TEST(FieldTransportAtlas, RejectsStableAdjacencyTamperReasons) {
  const TriMesh mesh = make_square_mesh();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());

  CrossFieldResult missing = make_zero_transport_field(mesh);
  const auto interior = std::find_if(
      missing.edgeTransitions.begin(), missing.edgeTransitions.end(),
      [](const CrossFieldEdgeTransition &transition) {
        return transition.secondFace >= 0;
      });
  ASSERT_NE(missing.edgeTransitions.end(), interior);
  const CrossFieldEdgeTransition validInterior = *interior;
  missing.edgeTransitions.erase(interior);
  auto missingResult =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, missing);
  ASSERT_FALSE(missingResult);
  EXPECT_EQ(FieldAtlasBuildErrorCode::MissingAdjacency,
            missingResult.error().code);

  CrossFieldResult duplicate = make_zero_transport_field(mesh);
  duplicate.edgeTransitions.push_back(validInterior);
  auto duplicateResult =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, duplicate);
  ASSERT_FALSE(duplicateResult);
  EXPECT_EQ(FieldAtlasBuildErrorCode::DuplicateAdjacency,
            duplicateResult.error().code);

  CrossFieldResult nonreciprocal = make_zero_transport_field(mesh);
  CrossFieldEdgeTransition *corrupted = find_transition(
      nonreciprocal,
      SourceEdgeTopologyKey::from_indices(
          validInterior.sourceVertex0, validInterior.sourceVertex1,
          static_cast<std::size_t>(mesh.V.rows()))
          .value(),
      static_cast<std::size_t>(mesh.V.rows()));
  ASSERT_NE(nullptr, corrupted);
  corrupted->secondFace = corrupted->firstFace;
  auto nonreciprocalResult =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, nonreciprocal);
  ASSERT_FALSE(nonreciprocalResult);
  EXPECT_EQ(FieldAtlasBuildErrorCode::NonReciprocalAdjacency,
            nonreciprocalResult.error().code);
}

TEST(FieldTransportAtlas,
     IndependentOracleRejectsCompleteTypedTamperMatrix) {
  const TriMesh mesh = make_square_mesh();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const CrossFieldResult field = make_zero_transport_field(mesh);
  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built);
  const IndependentAtlasSnapshot baseline =
      independent_snapshot(built.value());
  ASSERT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, baseline));

  const auto expect_rejected = [&](const auto &mutate,
                                   const FieldAtlasBuildErrorCode expected) {
    IndependentAtlasSnapshot candidate = baseline;
    ASSERT_FALSE(independent_validate_snapshot(
        mesh, *sourceAuthority, field, {}, candidate));
    mutate(candidate);
    const auto rejection = independent_validate_snapshot(
        mesh, *sourceAuthority, field, {}, candidate);
    ASSERT_TRUE(rejection.has_value());
    EXPECT_EQ(expected, *rejection);
  };

  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.adjacencies.clear();
      },
      FieldAtlasBuildErrorCode::MissingAdjacency);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.adjacencies.push_back(candidate.adjacencies.front());
      },
      FieldAtlasBuildErrorCode::DuplicateAdjacency);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.adjacencies.front().reverse =
            QuarterTurn::from_integer(1);
      },
      FieldAtlasBuildErrorCode::NonReciprocalAdjacency);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        ++candidate.cycles.front().turningLift;
      },
      FieldAtlasBuildErrorCode::CycleTransportMismatch);
  expect_rejected(
      [&](IndependentAtlasSnapshot &candidate) {
        const SourceFaceId face = SourceFaceId::from_index(
            0, static_cast<std::size_t>(mesh.F.rows())).value();
        candidate.singularities.push_back(FieldSingularityFact{
            FieldSingularityId::from_index(0, 1).value(),
            SourceVertexId::from_index(
                0, static_cast<std::size_t>(mesh.V.rows())).value(),
            sourceAuthority->component_for_row(face), 1,
            sourceAuthority->region_for_row(face), std::nullopt});
      },
      FieldAtlasBuildErrorCode::SingularityMismatch);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        ++candidate.componentTopology.front().eulerCharacteristic;
      },
      FieldAtlasBuildErrorCode::CanonicalBindingMismatch);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        ++candidate.witnesses.front().numeratorGcd;
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.witnesses.front().holonomySignatureDigest ^= 1U;
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.witnesses.front().singularityNumerators.push_back(1);
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.witnesses.front().exactCycleLifts.clear();
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.witnesses.front().boundaryCycles.clear();
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.witnesses.front().kind =
            FieldQuadrangulabilityWitnessKind::ClosedShenSufficient;
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.established = false;
      },
      FieldAtlasBuildErrorCode::UnestablishedAdmissibility);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.sourceDigest ^= 1U;
      },
      FieldAtlasBuildErrorCode::CanonicalBindingMismatch);
  expect_rejected(
      [](IndependentAtlasSnapshot &candidate) {
        candidate.atlasDigest ^= 1U;
      },
      FieldAtlasBuildErrorCode::CanonicalBindingMismatch);
}

TEST(FieldTransportAtlas, ClassifiesHardFeaturesAsNontraversableCuts) {
  const TriMesh mesh = make_square_mesh();
  int interiorEdge = -1;
  for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
    if (mesh.EF(edge, 1) >= 0) interiorEdge = edge;
  }
  ASSERT_GE(interiorEdge, 0);
  const std::set<SourceEdgeTopologyKey> hardEdges{edge_key(mesh, interiorEdge)};
  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
  ASSERT_TRUE(sourceAuthority.has_value());

  auto built = FieldTransportAtlas::make(
      mesh, *sourceAuthority, hardEdges, make_zero_transport_field(mesh));
  ASSERT_TRUE(built);
  EXPECT_TRUE(built.value().adjacencies().empty());
  const auto hard = std::count_if(
      built.value().nontraversable_edges().begin(),
      built.value().nontraversable_edges().end(),
      [](const auto &edge) {
        return edge.kind == FieldTransportBarrierKind::HardFeature;
      });
  EXPECT_EQ(1, hard);
  EXPECT_EQ(2U, built.value().component_topology().size());
}

TEST(FieldTransportAtlas, RejectsNonIntegralLiftAndSingularityMismatch) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());

  CrossFieldResult nonIntegral = make_zero_transport_field(mesh);
  const auto interior = std::find_if(
      nonIntegral.edgeTransitions.begin(), nonIntegral.edgeTransitions.end(),
      [](const CrossFieldEdgeTransition &transition) {
        return transition.secondFace >= 0;
      });
  ASSERT_NE(nonIntegral.edgeTransitions.end(), interior);
  interior->effort = 0.2;
  auto nonIntegralResult =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, nonIntegral);
  ASSERT_FALSE(nonIntegralResult);
  EXPECT_EQ(FieldAtlasBuildErrorCode::NonIntegralCycleLift,
            nonIntegralResult.error().code);

  CrossFieldResult mismatch = make_zero_transport_field(mesh);
  mismatch.singularCycles.resize(1);
  mismatch.singularIndices.resize(1);
  mismatch.singularCycles << 4;
  mismatch.singularIndices << 1;
  auto mismatchResult =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, mismatch);
  ASSERT_FALSE(mismatchResult);
  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
            mismatchResult.error().code);
}

TEST(FieldTransportAtlas,
     IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling) {
  const TriMesh baselineMesh = make_square_mesh();
  const CrossFieldResult baselineField =
      make_zero_transport_field(baselineMesh);
  const IndependentOracleSummary baselineOracle =
      independent_oracle(baselineMesh, baselineField);
  ASSERT_TRUE(baselineOracle.reciprocal);
  EXPECT_EQ(1U, baselineOracle.traversableEdges);
  EXPECT_EQ(4U, baselineOracle.boundaryEdges);
  EXPECT_EQ(0, baselineOracle.handleGenerators);

  const auto baselineAuthority = make_source_authority(baselineMesh);
  ASSERT_TRUE(baselineAuthority.has_value());
  auto baseline = FieldTransportAtlas::make(
      baselineMesh, *baselineAuthority, {}, baselineField);
  ASSERT_TRUE(baseline);
  EXPECT_EQ(baselineOracle.traversableEdges,
            baseline.value().adjacencies().size());

  const TriMesh relabeledMesh = make_square_mesh(true);
  CrossFieldResult relabeledField = make_zero_transport_field(relabeledMesh);
  const auto interior = std::find_if(
      relabeledField.edgeTransitions.begin(),
      relabeledField.edgeTransitions.end(),
      [](const CrossFieldEdgeTransition &transition) {
        return transition.secondFace >= 0;
      });
  ASSERT_NE(relabeledField.edgeTransitions.end(), interior);
  // Per-face branch gauges 1 and 3 change the directed matching by two but do
  // not change the field's cycle signature or relative-boundary witness.
  relabeledField.primaryDirections.row(interior->firstFace) =
      Eigen::RowVector3d::UnitY();
  relabeledField.secondaryDirections.row(interior->firstFace) =
      -Eigen::RowVector3d::UnitX();
  relabeledField.primaryDirections.row(interior->secondFace) =
      -Eigen::RowVector3d::UnitY();
  relabeledField.secondaryDirections.row(interior->secondFace) =
      Eigen::RowVector3d::UnitX();
  interior->matching = 2;
  relabeledField.matching(interior->sourceEdge) = 2;
  const IndependentOracleSummary relabeledOracle =
      independent_oracle(relabeledMesh, relabeledField);
  ASSERT_TRUE(relabeledOracle.reciprocal);
  const auto relabeledAuthority = make_source_authority(relabeledMesh);
  ASSERT_TRUE(relabeledAuthority.has_value());
  auto relabeled = FieldTransportAtlas::make(
      relabeledMesh, *relabeledAuthority, {}, relabeledField);
  ASSERT_TRUE(relabeled);
  EXPECT_FALSE(independent_validate_snapshot(
      relabeledMesh, *relabeledAuthority, relabeledField, {},
      independent_snapshot(relabeled.value()))
                   .has_value());

  EXPECT_EQ(baselineOracle.traversableEdges,
            relabeledOracle.traversableEdges);
  EXPECT_EQ(baseline.value().component_topology().front().eulerCharacteristic,
            relabeled.value().component_topology().front().eulerCharacteristic);
  EXPECT_EQ(baseline.value().component_topology().front().boundaryLoopCount,
            relabeled.value().component_topology().front().boundaryLoopCount);
  EXPECT_EQ(baseline.value().quadrangulability().witnesses().front().indexSum,
            relabeled.value().quadrangulability().witnesses().front().indexSum);
  EXPECT_EQ(baseline.value().quadrangulability().source_digest(),
            relabeled.value().quadrangulability().source_digest());
  EXPECT_EQ(
      baseline.value().quadrangulability().witnesses().front()
          .holonomySignatureDigest,
      relabeled.value().quadrangulability().witnesses().front()
          .holonomySignatureDigest);
  EXPECT_EQ(FieldCycleKind::BoundaryLoop,
            relabeled.value().cycles().front().kind);
}

} // namespace
