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
#include <sstream>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Geometry>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include "support/SkewSingularFieldWitness.h"

namespace {

using directional::TriMesh;
using directional::authority::FieldAtlasBuildError;
using directional::authority::FieldAtlasBuildErrorCode;
using directional::authority::FieldBoundaryFlow;
using directional::authority::FieldBranch;
using directional::authority::FieldBranchBoundaryPairing;
using directional::authority::FieldBranchTopology;
using directional::authority::FieldBranchTransportAdjacency;
using directional::authority::FieldComponentTopology;
using directional::authority::FieldCycleId;
using directional::authority::FieldCycleKind;
using directional::authority::FieldCycleWitness;
using directional::authority::FieldNonTraversableEdge;
using directional::authority::FieldQuadrangulabilityWitness;
using directional::authority::FieldQuadrangulabilityWitnessKind;
using directional::authority::FieldSingularityFact;
using directional::authority::FieldSourceBoundaryCycleAssociation;
using directional::authority::FieldSourceBoundaryCycleFact;
using directional::authority::FieldSingularityId;
using directional::authority::FieldSingularityPortAttachment;
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
using directional::test_support::IndependentEdgeMeasurement;
using directional::test_support::independent_edge_measurement;
using directional::test_support::independent_face_branches;
using directional::test_support::independent_signed_angle;
using directional::test_support::make_skew_four_triangle_fan;
using directional::test_support::make_skew_index_one_singularity_field;

std::string describe_field_atlas_build_error(const FieldAtlasBuildError &error) {
  std::ostringstream out;
  out << "code="
      << directional::authority::field_atlas_build_error_code_name(error.code);
  if (error.sourceEdge.has_value()) {
    out << ";sourceEdge=(" << error.sourceEdge->first().index() << ","
        << error.sourceEdge->second().index() << ")";
  }
  if (error.sourceFace.has_value()) {
    out << ";sourceFace=" << error.sourceFace->index();
  }
  if (error.sourceVertex.has_value()) {
    out << ";sourceVertex=" << error.sourceVertex->index();
  }
  if (error.topologyRegion.has_value()) {
    out << ";topologyRegion=" << error.topologyRegion->index();
  }
  if (error.incompleteCycleBasisReason.has_value()) {
    out << ";incompleteCycleBasisReason="
        << directional::authority::incomplete_cycle_basis_reason_name(
               *error.incompleteCycleBasisReason);
  }
  return out.str();
}

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

TriMesh make_two_interior_islands_disk() {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0,
              2.0, 0.0, 0.0,
              2.0, 2.0, 0.0,
              0.0, 2.0, 0.0,
              4.0 / 3.0, 2.0 / 3.0, 0.0,
              2.0 / 3.0, 4.0 / 3.0, 0.0;
  Eigen::MatrixXi faces(6, 3);
  faces << 0, 1, 4,
           1, 2, 4,
           2, 0, 4,
           0, 2, 5,
           2, 3, 5,
           3, 0, 5;
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return mesh;
}

TriMesh make_five_ring_annulus() {
  constexpr int kRings = 5;
  constexpr int kSegments = 8;
  Eigen::MatrixXd vertices(kRings * kSegments, 3);
  for (int ring = 0; ring < kRings; ++ring) {
    const double radius = 1.0 + static_cast<double>(ring);
    for (int segment = 0; segment < kSegments; ++segment) {
      const double angle =
          2.0 * std::numbers::pi * static_cast<double>(segment) /
          static_cast<double>(kSegments);
      vertices.row(ring * kSegments + segment) =
          Eigen::RowVector3d(radius * std::cos(angle),
                             radius * std::sin(angle), 0.0);
    }
  }

  std::vector<Eigen::Vector3i> faceRows;
  faceRows.reserve(static_cast<std::size_t>((kRings - 1) * kSegments * 2));
  for (int ring = 0; ring + 1 < kRings; ++ring) {
    for (int segment = 0; segment < kSegments; ++segment) {
      const int next = (segment + 1) % kSegments;
      const int inner = ring * kSegments + segment;
      const int innerNext = ring * kSegments + next;
      const int outer = (ring + 1) * kSegments + segment;
      const int outerNext = (ring + 1) * kSegments + next;
      faceRows.emplace_back(inner, outer, outerNext);
      faceRows.emplace_back(inner, outerNext, innerNext);
    }
  }
  Eigen::MatrixXi faces(static_cast<Eigen::Index>(faceRows.size()), 3);
  for (std::size_t row = 0; row < faceRows.size(); ++row) {
    faces.row(static_cast<Eigen::Index>(row)) = faceRows[row];
  }
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


void populate_zero_source_boundary_cycles(const TriMesh &mesh,
                                          CrossFieldResult &field) {
  struct LoopFact {
    std::vector<directional::authority::SourceVertexId> vertices;
    std::vector<directional::authority::SourceEdgeTopologyKey> edges;
  };
  std::vector<LoopFact> facts;
  const std::size_t vertexExtent = static_cast<std::size_t>(mesh.V.rows());
  for (const std::vector<int> &rawLoop : mesh.boundaryLoops) {
    std::vector<directional::authority::SourceVertexId> vertices;
    for (const int rawVertex : rawLoop) {
      vertices.push_back(directional::authority::SourceVertexId::from_index(
                             rawVertex, vertexExtent)
                             .value());
    }
    const auto best_rotation = [](const auto &input) {
      using Vertex = directional::authority::SourceVertexId;
      std::vector<Vertex> best;
      for (std::size_t start = 0; start < input.size(); ++start) {
        std::vector<Vertex> candidate;
        for (std::size_t offset = 0; offset < input.size(); ++offset) {
          candidate.push_back(input[(start + offset) % input.size()]);
        }
        if (best.empty() || candidate < best) best = std::move(candidate);
      }
      return best;
    };
    std::vector<directional::authority::SourceVertexId> forward =
        best_rotation(vertices);
    std::reverse(vertices.begin(), vertices.end());
    std::vector<directional::authority::SourceVertexId> reverse =
        best_rotation(vertices);
    vertices = reverse < forward ? std::move(reverse) : std::move(forward);
    std::vector<directional::authority::SourceEdgeTopologyKey> edges;
    for (std::size_t i = 0; i < vertices.size(); ++i) {
      edges.push_back(directional::authority::SourceEdgeTopologyKey::make(
                          vertices[i], vertices[(i + 1U) % vertices.size()])
                          .value());
    }
    facts.push_back(LoopFact{std::move(vertices), std::move(edges)});
  }
  std::sort(facts.begin(), facts.end(),
            [](const LoopFact &a, const LoopFact &b) {
              return a.vertices < b.vertices;
            });
  field.sourceBoundaryCycles.clear();
  for (std::size_t i = 0; i < facts.size(); ++i) {
    field.sourceBoundaryCycles.push_back(
        directional::fields::CrossFieldSourceBoundaryCycleFact{
            directional::authority::SourceBoundaryCycleId::from_index(
                i, facts.size())
                .value(),
            std::move(facts[i].vertices), std::move(facts[i].edges), 0});
  }
  field.sourceBoundaryCyclesComputed = true;
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
  populate_zero_source_boundary_cycles(mesh, field);
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
  std::vector<directional::authority::FieldFaceBranchFrame> branchFrames;
  std::vector<FieldBranchTransportAdjacency> branchTransports;
  std::vector<FieldSingularityPortAttachment> singularityPortAttachments;
  std::uint64_t branchTopologyDigest = 0U;
  std::vector<FieldNonTraversableEdge> nontraversableEdges;
  std::vector<FieldCycleWitness> cycles;
  std::vector<FieldSingularityFact> singularities;
  std::vector<FieldSourceBoundaryCycleFact> sourceBoundaryCycles;
  std::vector<FieldSourceBoundaryCycleAssociation> sourceBoundaryAssociations;
  std::vector<FieldComponentTopology> componentTopology;
  std::vector<FieldQuadrangulabilityWitness> witnesses;
  bool established = false;
  std::uint64_t sourceDigest = 0U;
  std::uint64_t atlasDigest = 0U;
};

IndependentAtlasSnapshot independent_snapshot(const FieldTransportAtlas &atlas) {
  return IndependentAtlasSnapshot{
      atlas.adjacencies(), atlas.branch_topology().frames(),
      atlas.branch_topology().transports(),
      atlas.branch_topology().singularity_port_attachments(),
      atlas.branch_topology().semantic_digest(),
      atlas.nontraversable_edges(), atlas.cycles(),
      atlas.singularities(), atlas.source_boundary_cycles(),
      atlas.source_boundary_cycle_associations(), atlas.component_topology(),
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

void independent_consume_exact(
    std::uint64_t &hash,
    const directional::authority::FieldExactRational &value) {
  const std::string numerator = value.numerator_string();
  const std::string denominator = value.denominator_string();
  independent_consume(hash, numerator.size());
  for (const unsigned char byte : numerator) independent_consume(hash, byte);
  independent_consume(hash, denominator.size());
  for (const unsigned char byte : denominator) independent_consume(hash, byte);
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

std::uint64_t independent_branch_topology_digest(
    const IndependentAtlasSnapshot &snapshot) {
  std::uint64_t hash = kIndependentFnvOffset;
  independent_consume(hash, snapshot.branchFrames.size());
  for (const auto &frame : snapshot.branchFrames) {
    independent_consume_face(hash, frame.sourceFace);
    independent_consume(hash, frame.branches.size());
    for (const FieldBranchBoundaryPairing &pairing : frame.branches) {
      independent_consume(hash, pairing.branch.value());
      for (const auto &coordinate : pairing.direction.barycentric) {
        independent_consume_exact(hash, coordinate);
      }
      independent_consume(hash, pairing.intervals.size());
      for (const auto &interval : pairing.intervals) {
        independent_consume(hash, interval.startVertex.index());
        independent_consume(hash, interval.endVertex.index());
        independent_consume(hash, interval.sourceEdge.first().index());
        independent_consume(hash, interval.sourceEdge.second().index());
        independent_consume(hash, static_cast<std::uint64_t>(interval.flow));
      }
      independent_consume(hash, pairing.incomingCarriers.size());
      for (const auto &edge : pairing.incomingCarriers) {
        independent_consume(hash, edge.first().index());
        independent_consume(hash, edge.second().index());
      }
      independent_consume(hash, pairing.outgoingCarriers.size());
      for (const auto &edge : pairing.outgoingCarriers) {
        independent_consume(hash, edge.first().index());
        independent_consume(hash, edge.second().index());
      }
    }
  }
  independent_consume(hash, snapshot.branchTransports.size());
  for (const auto &transport : snapshot.branchTransports) {
    independent_consume(hash, transport.sourceEdge.first().index());
    independent_consume(hash, transport.sourceEdge.second().index());
    independent_consume_face(hash, transport.firstFace);
    independent_consume_face(hash, transport.secondFace);
    independent_consume(hash, transport.forward.value());
    independent_consume(hash, transport.reverse.value());
    independent_consume_signed(hash, transport.forwardLift);
  }
  independent_consume(hash, snapshot.singularityPortAttachments.size());
  for (const auto &attachment : snapshot.singularityPortAttachments) {
    independent_consume(hash, attachment.sourceVertex.index());
    independent_consume_signed(hash, attachment.localSlot);
    independent_consume_face(hash, attachment.startFace);
    independent_consume(hash, attachment.branch.value());
    independent_consume(hash, attachment.firstOutgoingCarrier.first().index());
    independent_consume(hash, attachment.firstOutgoingCarrier.second().index());
  }
  return hash;
}

std::uint64_t independent_atlas_digest(
    const IndependentAtlasSnapshot &snapshot,
    const std::vector<SourceFaceTopologyKey> &rowTopology) {
  std::uint64_t hash = kIndependentFnvOffset;
  independent_consume(hash, snapshot.sourceDigest);
  independent_consume(hash, snapshot.branchTopologyDigest);

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

  std::vector<std::tuple<std::uint64_t, int, std::uint8_t>> singularities;
  singularities.reserve(snapshot.singularities.size());
  for (const FieldSingularityFact &singularity : snapshot.singularities) {
    singularities.emplace_back(
        singularity.sourceVertex.index(), singularity.indexNumerator,
        static_cast<std::uint8_t>(singularity.portPolicy));
  }
  std::sort(singularities.begin(), singularities.end());
  independent_consume(hash, singularities.size());
  for (const auto &[vertex, numerator, portPolicy] : singularities) {
    independent_consume(hash, vertex);
    independent_consume_signed(hash, numerator);
    independent_consume(hash, portPolicy);
  }

  std::vector<std::uint64_t> sourceBoundaryFactDigests;
  for (const FieldSourceBoundaryCycleFact &fact :
       snapshot.sourceBoundaryCycles) {
    std::uint64_t factHash = kIndependentFnvOffset;
    independent_consume(factHash, fact.sourceComponent.index());
    independent_consume_signed(factHash, fact.indexNumerator);
    independent_consume(factHash, fact.canonicalVertices.size());
    for (const SourceVertexId vertex : fact.canonicalVertices) {
      independent_consume(factHash, vertex.index());
    }
    independent_consume(factHash, fact.sourceEdges.size());
    for (const SourceEdgeTopologyKey &edge : fact.sourceEdges) {
      independent_consume(factHash, edge.first().index());
      independent_consume(factHash, edge.second().index());
    }
    sourceBoundaryFactDigests.push_back(factHash);
  }
  std::sort(sourceBoundaryFactDigests.begin(), sourceBoundaryFactDigests.end());
  independent_consume(hash, sourceBoundaryFactDigests.size());
  for (const std::uint64_t digest : sourceBoundaryFactDigests) {
    independent_consume(hash, digest);
  }

  std::vector<std::uint64_t> sourceBoundaryAssociationDigests;
  for (const FieldSourceBoundaryCycleAssociation &association :
       snapshot.sourceBoundaryAssociations) {
    if (association.regionalCycle.index() >= snapshot.cycles.size()) continue;
    std::uint64_t associationHash = kIndependentFnvOffset;
    independent_consume(associationHash, association.sourceBoundaryCycle.index());
    independent_consume(
        associationHash,
        independent_cycle_digest(snapshot.cycles[association.regionalCycle.index()],
                                 rowTopology));
    independent_consume(associationHash,
                        association.sourceBoundaryEdges.size());
    for (const SourceEdgeTopologyKey &edge :
         association.sourceBoundaryEdges) {
      independent_consume(associationHash, edge.first().index());
      independent_consume(associationHash, edge.second().index());
    }
    sourceBoundaryAssociationDigests.push_back(associationHash);
  }
  std::sort(sourceBoundaryAssociationDigests.begin(),
            sourceBoundaryAssociationDigests.end());
  independent_consume(hash, sourceBoundaryAssociationDigests.size());
  for (const std::uint64_t digest : sourceBoundaryAssociationDigests) {
    independent_consume(hash, digest);
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

std::optional<int> independent_face_gauge(
    const TriMesh &mesh, const CrossFieldResult &field, const int face,
    const SourceFaceTopologyKey &topology) {
  constexpr double tolerance = 1.0e-10;
  const auto &vertices = topology.vertices();
  const Eigen::Vector3d p0 =
      mesh.V.row(static_cast<int>(vertices[0].index())).transpose();
  const Eigen::Vector3d p1 =
      mesh.V.row(static_cast<int>(vertices[1].index())).transpose();
  const Eigen::Vector3d p2 =
      mesh.V.row(static_cast<int>(vertices[2].index())).transpose();
  Eigen::Vector3d normal = (p1 - p0).cross(p2 - p0);
  const double normalNorm = normal.norm();
  if (!std::isfinite(normalNorm) || normalNorm <= tolerance) {
    return std::nullopt;
  }
  normal /= normalNorm;

  const auto project = [&](const Eigen::Vector3d &direction)
      -> std::optional<Eigen::Vector3d> {
    Eigen::Vector3d tangent = direction - direction.dot(normal) * normal;
    const double norm = tangent.norm();
    if (!std::isfinite(norm) || norm <= tolerance) return std::nullopt;
    tangent /= norm;
    return tangent.allFinite() ? std::optional<Eigen::Vector3d>(tangent)
                               : std::nullopt;
  };

  const auto reference = project(p1 - p0);
  const auto primary = project(field.primaryDirections.row(face).transpose());
  const auto secondary =
      project(field.secondaryDirections.row(face).transpose());
  if (!reference.has_value() || !primary.has_value() ||
      !secondary.has_value() ||
      std::abs(primary->dot(*secondary)) > 1.0 - 1.0e-8) {
    return std::nullopt;
  }

  const std::array<Eigen::Vector3d, 4> rawDirections{
      *primary, *secondary, -*primary, -*secondary};
  std::array<double, 4> angles{};
  int gauge = 0;
  double best = std::numeric_limits<double>::infinity();
  for (int raw = 0; raw < 4; ++raw) {
    double angle = independent_signed_angle(
        *reference, rawDirections[static_cast<std::size_t>(raw)], normal);
    if (angle < 0.0) angle += 2.0 * std::numbers::pi;
    if (angle >= 2.0 * std::numbers::pi) angle -= 2.0 * std::numbers::pi;
    angles[static_cast<std::size_t>(raw)] = angle;
    if (angle < best) {
      best = angle;
      gauge = raw;
    }
  }
  for (int raw = 0; raw < 4; ++raw) {
    if (raw != gauge &&
        std::abs(angles[static_cast<std::size_t>(raw)] - best) <= tolerance) {
      return std::nullopt;
    }
  }
  return gauge;
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
  std::vector<IndependentSupportKey> orderedSupport;
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

struct IndependentPortOrderKey {
  std::size_t counterClockwiseFanSlot = 0U;
  double sectorAngle = 0.0;
};

std::optional<IndependentPortOrderKey> independent_port_order_key(
    const TriMesh &mesh, const CrossFieldResult &field,
    const std::vector<SourceFaceTopologyKey> &rowTopology,
    const SourceVertexId sourceVertex,
    const FieldSingularityPortAttachment &attachment) {
  constexpr double tolerance = 1.0e-10;
  struct FanFace {
    int row = -1;
    SourceFaceTopologyKey topology;
    SourceVertexId nextVertex;
    SourceVertexId previousVertex;
  };
  std::vector<FanFace> incident;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    int corner = -1;
    for (int local = 0; local < 3; ++local) {
      if (mesh.F(face, local) == static_cast<int>(sourceVertex.index())) {
        corner = local;
        break;
      }
    }
    if (corner < 0) continue;
    const auto next = SourceVertexId::from_index(
        mesh.F(face, (corner + 1) % 3),
        static_cast<std::size_t>(mesh.V.rows()));
    const auto previous = SourceVertexId::from_index(
        mesh.F(face, (corner + 2) % 3),
        static_cast<std::size_t>(mesh.V.rows()));
    if (!next || !previous || static_cast<std::size_t>(face) >= rowTopology.size()) {
      return std::nullopt;
    }
    incident.push_back(
        FanFace{face, rowTopology[static_cast<std::size_t>(face)], next.value(),
                previous.value()});
  }
  if (incident.size() < 3U) return std::nullopt;
  const auto start = std::min_element(
      incident.begin(), incident.end(),
      [](const FanFace &first, const FanFace &second) {
        return first.topology < second.topology;
      });
  if (start == incident.end()) return std::nullopt;

  // Walk directly counter-clockwise: cross the current previous-vertex ray
  // into the face whose next-vertex ray is the same source edge.
  std::vector<FanFace> counterClockwise;
  counterClockwise.reserve(incident.size());
  FanFace current = *start;
  std::set<SourceFaceTopologyKey> used;
  for (std::size_t step = 0U; step < incident.size(); ++step) {
    if (!used.insert(current.topology).second) return std::nullopt;
    counterClockwise.push_back(current);
    const auto next = std::find_if(
        incident.begin(), incident.end(), [&](const FanFace &candidate) {
          return candidate.nextVertex == current.previousVertex;
        });
    if (next == incident.end()) return std::nullopt;
    current = *next;
  }
  if (current.topology != counterClockwise.front().topology ||
      used.size() != incident.size()) {
    return std::nullopt;
  }
  const auto faceIt = std::find_if(
      counterClockwise.begin(), counterClockwise.end(),
      [&](const FanFace &candidate) {
        return candidate.topology == attachment.startFace;
      });
  if (faceIt == counterClockwise.end()) return std::nullopt;
  const auto gauge = independent_face_gauge(
      mesh, field, faceIt->row, faceIt->topology);
  if (!gauge.has_value()) return std::nullopt;
  const auto raw = independent_face_branches(field, faceIt->row);
  const std::size_t rawBranch = static_cast<std::size_t>(
      ((*gauge + static_cast<int>(attachment.branch.value())) % 4 + 4) % 4);
  Eigen::Vector3d direction = raw[rawBranch].transpose();

  const Eigen::Vector3d origin =
      mesh.V.row(static_cast<int>(sourceVertex.index())).transpose();
  Eigen::Vector3d startRay =
      mesh.V.row(static_cast<int>(faceIt->nextVertex.index())).transpose() -
      origin;
  Eigen::Vector3d endRay =
      mesh.V.row(static_cast<int>(faceIt->previousVertex.index())).transpose() -
      origin;
  Eigen::Vector3d normal = startRay.cross(endRay);
  const double normalNorm = normal.norm();
  const double startNorm = startRay.norm();
  const double endNorm = endRay.norm();
  if (!std::isfinite(normalNorm) || !std::isfinite(startNorm) ||
      !std::isfinite(endNorm) || normalNorm <= tolerance ||
      startNorm <= tolerance || endNorm <= tolerance) {
    return std::nullopt;
  }
  normal /= normalNorm;
  startRay /= startNorm;
  endRay /= endNorm;
  direction -= direction.dot(normal) * normal;
  const double directionNorm = direction.norm();
  if (!std::isfinite(directionNorm) || directionNorm <= tolerance) {
    return std::nullopt;
  }
  direction /= directionNorm;
  auto positiveAngle = [&](const Eigen::Vector3d &from,
                           const Eigen::Vector3d &to) {
    double angle = independent_signed_angle(from, to, normal);
    if (angle < 0.0) angle += 2.0 * std::numbers::pi;
    return angle;
  };
  const double sector = positiveAngle(startRay, endRay);
  const double angle = positiveAngle(startRay, direction);
  if (!std::isfinite(sector) || !std::isfinite(angle) || sector <= tolerance ||
      angle > sector + tolerance) {
    return std::nullopt;
  }
  return IndependentPortOrderKey{
      static_cast<std::size_t>(
          std::distance(counterClockwise.begin(), faceIt)),
      angle};
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
          independent_vertex_cycle(mesh, vertex), {}, {}, 0, QuarterTurn{}});
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

std::optional<std::vector<IndependentSupportKey>>
independent_canonical_component_order(
    std::vector<IndependentSupportKey> support);

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
    const auto orderedSupport =
        independent_canonical_component_order(row.support);
    if (!orderedSupport.has_value()) return std::nullopt;
    row.orderedSupport = *orderedSupport;
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

std::optional<std::vector<IndependentSupportKey>>
independent_canonical_component_order(
    std::vector<IndependentSupportKey> support) {
  const auto orderKey = [](const IndependentSupportKey &key) {
    return std::make_tuple(std::get<2>(key), std::get<3>(key),
                           std::get<0>(key), std::get<1>(key));
  };
  std::sort(support.begin(), support.end(),
            [&](const IndependentSupportKey &a,
                const IndependentSupportKey &b) {
              return orderKey(a) < orderKey(b);
            });

  std::map<std::uint64_t, std::size_t> successor;
  for (std::size_t index = 0; index < support.size(); ++index) {
    if (!successor.emplace(std::get<2>(support[index]), index).second) {
      return std::nullopt;
    }
  }

  std::vector<bool> used(support.size(), false);
  std::vector<IndependentSupportKey> ordered;
  ordered.reserve(support.size());
  while (ordered.size() < support.size()) {
    const auto firstUnused = std::find(used.begin(), used.end(), false);
    if (firstUnused == used.end()) break;
    const std::size_t firstIndex =
        static_cast<std::size_t>(firstUnused - used.begin());
    const std::uint64_t startFace = std::get<2>(support[firstIndex]);
    std::uint64_t currentFace = startFace;

    while (true) {
      const auto next = successor.find(currentFace);
      if (next == successor.end() || used[next->second]) {
        return std::nullopt;
      }
      used[next->second] = true;
      ordered.push_back(support[next->second]);
      currentFace = std::get<3>(support[next->second]);
      if (currentFace == startFace) break;
    }
  }

  if (ordered.size() != support.size() ||
      std::find(used.begin(), used.end(), false) != used.end()) {
    return std::nullopt;
  }
  return ordered;
}

bool independent_matches_canonical_component_order(
    const std::vector<IndependentSupportKey> &support,
    const std::vector<IndependentSupportKey> &publishedOrder) {
  const auto canonical = independent_canonical_component_order(support);
  return canonical.has_value() && *canonical == publishedOrder;
}

std::optional<std::size_t> independent_closed_component_count(
    const std::vector<IndependentSupportKey> &support) {
  const auto ordered = independent_canonical_component_order(support);
  if (!ordered.has_value()) return std::nullopt;
  std::size_t components = 0U;
  std::size_t index = 0U;
  while (index < ordered->size()) {
    const std::uint64_t startFace = std::get<2>((*ordered)[index]);
    std::uint64_t currentFace = startFace;
    do {
      if (index >= ordered->size() ||
          std::get<2>((*ordered)[index]) != currentFace) {
        return std::nullopt;
      }
      currentFace = std::get<3>((*ordered)[index]);
      ++index;
    } while (currentFace != startFace);
    ++components;
  }
  return components;
}

std::optional<FieldAtlasBuildErrorCode> independent_validate_snapshot(
    const TriMesh &mesh, const SourceTopologyRegions &sourceAuthority,
    const CrossFieldResult &field,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges,
    const IndependentAtlasSnapshot &snapshot) {
  const auto rowTopology = independent_row_topology(mesh, sourceAuthority);
  if (snapshot.branchTopologyDigest !=
      independent_branch_topology_digest(snapshot)) {
    return FieldAtlasBuildErrorCode::CanonicalBindingMismatch;
  }
  if (snapshot.branchFrames.size() != rowTopology.size()) {
    return FieldAtlasBuildErrorCode::InvalidBranchTopology;
  }
  std::set<SourceFaceTopologyKey> frameFaces;
  for (const auto &frame : snapshot.branchFrames) {
    if (!frameFaces.insert(frame.sourceFace).second ||
        frame.branches.size() != 4U) {
      return FieldAtlasBuildErrorCode::InvalidBranchTopology;
    }
    const auto &faceVertices = frame.sourceFace.vertices();
    std::set<SourceEdgeTopologyKey> faceEdges;
    for (int edge = 0; edge < 3; ++edge) {
      const auto typed = SourceEdgeTopologyKey::make(
          faceVertices[static_cast<std::size_t>(edge)],
          faceVertices[static_cast<std::size_t>((edge + 1) % 3)]);
      if (!typed) return FieldAtlasBuildErrorCode::InvalidBranchTopology;
      faceEdges.insert(typed.value());
    }
    for (std::size_t branch = 0; branch < 4U; ++branch) {
      const FieldBranchBoundaryPairing &pairing = frame.branches[branch];
      if (pairing.branch.value() != branch || pairing.intervals.size() != 3U ||
          pairing.incomingCarriers.empty() || pairing.outgoingCarriers.empty()) {
        return FieldAtlasBuildErrorCode::InvalidBranchTopology;
      }
      std::set<SourceEdgeTopologyKey> seen;
      for (const auto &interval : pairing.intervals) {
        if (faceEdges.count(interval.sourceEdge) == 0U ||
            !seen.insert(interval.sourceEdge).second) {
          return FieldAtlasBuildErrorCode::InvalidBranchTopology;
        }
        const bool listedIncoming =
            std::find(pairing.incomingCarriers.begin(),
                      pairing.incomingCarriers.end(), interval.sourceEdge) !=
            pairing.incomingCarriers.end();
        const bool listedOutgoing =
            std::find(pairing.outgoingCarriers.begin(),
                      pairing.outgoingCarriers.end(), interval.sourceEdge) !=
            pairing.outgoingCarriers.end();
        if ((interval.flow == FieldBoundaryFlow::Inflow &&
             (!listedIncoming || listedOutgoing)) ||
            (interval.flow == FieldBoundaryFlow::Outflow &&
             (!listedOutgoing || listedIncoming)) ||
            (interval.flow == FieldBoundaryFlow::Tangent &&
             (listedIncoming || listedOutgoing))) {
          return FieldAtlasBuildErrorCode::InvalidBranchTopology;
        }
      }
      if (seen != faceEdges) return FieldAtlasBuildErrorCode::InvalidBranchTopology;
      if (!pairing.direction.is_barycentric()) {
        return FieldAtlasBuildErrorCode::BranchDirectionNotBarycentric;
      }
    }
  }
  if (frameFaces != std::set<SourceFaceTopologyKey>(rowTopology.begin(),
                                                     rowTopology.end())) {
    return FieldAtlasBuildErrorCode::InvalidBranchTopology;
  }
  std::map<SourceEdgeTopologyKey, const FieldBranchTransportAdjacency *>
      branchTransportByEdge;
  for (const auto &transport : snapshot.branchTransports) {
    if (transport.reverse != transport.forward.inverse() ||
        QuarterTurn::from_integer(transport.forwardLift) != transport.forward ||
        frameFaces.count(transport.firstFace) == 0U ||
        frameFaces.count(transport.secondFace) == 0U ||
        !branchTransportByEdge.emplace(transport.sourceEdge, &transport).second) {
      return FieldAtlasBuildErrorCode::NonReciprocalAdjacency;
    }
  }
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
  std::map<std::uint64_t, int> rawBoundarySingularities;
  for (Eigen::Index index = 0; index < field.singularCycles.size(); ++index) {
    const int vertex = field.singularCycles(index);
    const int numerator = field.singularIndices(index);
    if (vertex < 0 || vertex >= mesh.V.rows() || numerator == 0) {
      return FieldAtlasBuildErrorCode::SingularityMismatch;
    }
    std::map<std::uint64_t, int> &owner =
        mesh.isBoundaryVertex(vertex) != 0 ? rawBoundarySingularities
                                           : rawSingularities;
    if (!owner.emplace(static_cast<std::uint64_t>(vertex), numerator).second) {
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
        std::abs(sourceMeasurement.effort - transition.effort) >= 1.0e-6 ||
        QuarterTurn::from_integer(sourceMeasurement.matching) !=
            QuarterTurn::from_integer(transition.matching) ||
        QuarterTurn::from_integer(sourceMeasurement.matching) != typed.forward) {
      return FieldAtlasBuildErrorCode::NonReciprocalAdjacency;
    }

    const auto branchFound = branchTransportByEdge.find(edge);
    if (branchFound == branchTransportByEdge.end()) {
      return FieldAtlasBuildErrorCode::MissingAdjacency;
    }
    const auto firstGauge = independent_face_gauge(
        mesh, field, transition.firstFace,
        rowTopology[static_cast<std::size_t>(transition.firstFace)]);
    const auto secondGauge = independent_face_gauge(
        mesh, field, transition.secondFace,
        rowTopology[static_cast<std::size_t>(transition.secondFace)]);
    if (!firstGauge.has_value() || !secondGauge.has_value()) {
      return FieldAtlasBuildErrorCode::InvalidBranchTopology;
    }
    const int canonicalLift =
        sourceMeasurement.matching + *firstGauge - *secondGauge;
    const SourceFaceTopologyKey &firstTopology =
        rowTopology[static_cast<std::size_t>(transition.firstFace)];
    const SourceFaceTopologyKey &secondTopology =
        rowTopology[static_cast<std::size_t>(transition.secondFace)];
    const bool canonicalForward = firstTopology < secondTopology;
    const QuarterTurn expectedForward = QuarterTurn::from_integer(
        canonicalForward ? canonicalLift : -canonicalLift);
    const double expectedEffort =
        canonicalForward ? sourceMeasurement.effort : -sourceMeasurement.effort;
    const FieldBranchTransportAdjacency &branch = *branchFound->second;
    if (branch.firstFace !=
            (canonicalForward ? firstTopology : secondTopology) ||
        branch.secondFace !=
            (canonicalForward ? secondTopology : firstTopology) ||
        branch.forward != expectedForward ||
        branch.reverse != expectedForward.inverse() ||
        QuarterTurn::from_integer(branch.forwardLift) != expectedForward ||
        std::abs(branch.effort - expectedEffort) >= 1.0e-6) {
      return FieldAtlasBuildErrorCode::NonReciprocalAdjacency;
    }
  }
  if (adjacency.size() != traversableCount ||
      branchTransportByEdge.size() != traversableCount) {
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
  std::set<std::uint64_t> reconciledBoundarySingularities;
  for (std::size_t loopIndex = 0; loopIndex < mesh.boundaryLoops.size();
       ++loopIndex) {
    const std::size_t cycleIndex = localCycles + loopIndex;
    if (cycleIndex >= expectedCycleFacts->size() ||
        (*expectedCycleFacts)[cycleIndex].kind != FieldCycleKind::BoundaryLoop) {
      return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
    }
    const int turningLift = (*expectedCycleFacts)[cycleIndex].turningLift;
    for (const int vertex : mesh.boundaryLoops[loopIndex]) {
      const auto supplied =
          rawBoundarySingularities.find(static_cast<std::uint64_t>(vertex));
      if (supplied == rawBoundarySingularities.end()) continue;
      if (supplied->second != turningLift ||
          !reconciledBoundarySingularities
               .insert(static_cast<std::uint64_t>(vertex))
               .second) {
        return FieldAtlasBuildErrorCode::SingularityMismatch;
      }
    }
  }
  if (reconciledBoundarySingularities.size() !=
      rawBoundarySingularities.size()) {
    return FieldAtlasBuildErrorCode::SingularityMismatch;
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
    std::vector<IndependentSupportKey> publishedOrder;
    publishedOrder.reserve(cycle.steps.size());
    for (const FieldTransportStep &step : cycle.steps) {
      publishedOrder.emplace_back(
          step.sourceEdge.first().index(), step.sourceEdge.second().index(),
          step.fromFace.index(), step.toFace.index());
    }
    if (expectedCycle.orderedSupport != publishedOrder) {
      return FieldAtlasBuildErrorCode::IncompleteCycleBasis;
    }

    QuarterTurn composed;
    for (const FieldTransportStep &step : cycle.steps) {
      if (step.adjacency.index() >= snapshot.adjacencies.size()) {
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

    if (singularity.portPolicy ==
        FieldSingularityFact::PortPolicy::BarrierAbsorbed) {
      if (!singularity.topologyRegion.has_value() ||
          !singularity.localCycle.has_value() ||
          singularity.localCycle->index() >= snapshot.cycles.size() ||
          snapshot.cycles[singularity.localCycle->index()].kind !=
              FieldCycleKind::BoundaryLoop) {
        return FieldAtlasBuildErrorCode::SingularityMismatch;
      }
      continue;
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

  std::map<FieldSingularityId, const FieldSingularityFact *> singularityById;
  for (const FieldSingularityFact &singularity : snapshot.singularities) {
    if (!singularityById.emplace(singularity.id, &singularity).second) {
      return FieldAtlasBuildErrorCode::SingularityMismatch;
    }
  }
  std::map<FieldSingularityId,
           std::vector<const FieldSingularityPortAttachment *>>
      attachmentsBySingularity;
  for (const FieldSingularityPortAttachment &attachment :
       snapshot.singularityPortAttachments) {
    const auto owner = singularityById.find(attachment.singularity);
    if (owner == singularityById.end() ||
        !owner->second->topologyRegion.has_value() ||
        attachment.sourceVertex != owner->second->sourceVertex ||
        attachment.topologyRegion != *owner->second->topologyRegion ||
        attachment.sourceComponent != owner->second->sourceComponent ||
        attachment.sourceVertex.index() >=
            static_cast<std::size_t>(mesh.V.rows()) ||
        frameFaces.count(attachment.startFace) == 0U) {
      return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
    }
    attachmentsBySingularity[attachment.singularity].push_back(&attachment);
    const auto &vertices = attachment.startFace.vertices();
    if (std::find(vertices.begin(), vertices.end(), attachment.sourceVertex) ==
        vertices.end()) {
      return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
    }
    const auto frame = std::find_if(
        snapshot.branchFrames.begin(), snapshot.branchFrames.end(),
        [&](const auto &candidate) {
          return candidate.sourceFace == attachment.startFace;
        });
    if (frame == snapshot.branchFrames.end() ||
        frame->topologyRegion != attachment.topologyRegion ||
        frame->sourceComponent != attachment.sourceComponent ||
        attachment.branch.value() >= frame->branches.size() ||
        std::find(
            frame->branches[attachment.branch.value()].outgoingCarriers.begin(),
            frame->branches[attachment.branch.value()].outgoingCarriers.end(),
            attachment.firstOutgoingCarrier) ==
            frame->branches[attachment.branch.value()].outgoingCarriers.end()) {
      return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
    }
  }
  for (const FieldSingularityFact &singularity : snapshot.singularities) {
    const int expected = 4 - singularity.indexNumerator;
    const auto found = attachmentsBySingularity.find(singularity.id);
    if (singularity.portPolicy ==
        FieldSingularityFact::PortPolicy::BarrierAbsorbed) {
      if (found != attachmentsBySingularity.end() && !found->second.empty()) {
        return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
      }
      continue;
    }
    if (expected <= 0 || expected > 4 ||
        found == attachmentsBySingularity.end() ||
        found->second.size() != static_cast<std::size_t>(expected)) {
      return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
    }
    std::vector<std::pair<IndependentPortOrderKey,
                          const FieldSingularityPortAttachment *>>
        ordered;
    ordered.reserve(found->second.size());
    for (const FieldSingularityPortAttachment *attachment : found->second) {
      const auto key = independent_port_order_key(
          mesh, field, rowTopology, singularity.sourceVertex, *attachment);
      if (!key.has_value()) {
        return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
      }
      ordered.emplace_back(*key, attachment);
    }
    std::sort(ordered.begin(), ordered.end(), [](const auto &first,
                                                  const auto &second) {
      if (first.first.counterClockwiseFanSlot !=
          second.first.counterClockwiseFanSlot) {
        return first.first.counterClockwiseFanSlot <
               second.first.counterClockwiseFanSlot;
      }
      return first.first.sectorAngle < second.first.sectorAngle;
    });
    for (std::size_t slot = 0; slot < ordered.size(); ++slot) {
      if (ordered[slot].second->localSlot != static_cast<int>(slot)) {
        return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
      }
      if (slot > 0U &&
          ordered[slot - 1U].first.counterClockwiseFanSlot ==
              ordered[slot].first.counterClockwiseFanSlot &&
          std::abs(ordered[slot - 1U].first.sectorAngle -
                   ordered[slot].first.sectorAngle) <= 1.0e-10) {
        return FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment;
      }
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

CrossFieldResult gauge_relabel_field(const TriMesh &mesh,
                                     const CrossFieldResult &baseline,
                                     const std::vector<int> &shifts) {
  CrossFieldResult result = baseline;
  EXPECT_EQ(static_cast<std::size_t>(mesh.F.rows()), shifts.size());
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d p = baseline.primaryDirections.row(face);
    const Eigen::RowVector3d s = baseline.secondaryDirections.row(face);
    const std::array<Eigen::RowVector3d, 4> branches{p, s, -p, -s};
    const int shift = ((shifts[static_cast<std::size_t>(face)] % 4) + 4) % 4;
    result.primaryDirections.row(face) = branches[static_cast<std::size_t>(shift)];
    result.secondaryDirections.row(face) =
        branches[static_cast<std::size_t>((shift + 1) % 4)];
  }
  for (CrossFieldEdgeTransition &transition : result.edgeTransitions) {
    if (transition.firstFace < 0 || transition.secondFace < 0) continue;
    transition.matching = baseline.edgeTransitions[static_cast<std::size_t>(
                              transition.sourceEdge)].matching +
                          shifts[static_cast<std::size_t>(transition.firstFace)] -
                          shifts[static_cast<std::size_t>(transition.secondFace)];
    result.matching(transition.sourceEdge) = transition.matching;
  }
  return result;
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

TEST(FieldTransportAtlas,
     IndependentCycleOrderingOracleHandlesMultipleClosedComponents) {
  const std::vector<IndependentSupportKey> support{
      {40U, 41U, 5U, 6U}, {42U, 43U, 6U, 5U},
      {20U, 21U, 1U, 2U}, {22U, 23U, 2U, 3U},
      {24U, 25U, 3U, 1U}};

  const auto canonical = independent_canonical_component_order(support);
  ASSERT_TRUE(canonical.has_value());
  ASSERT_EQ(5U, canonical->size());
  EXPECT_EQ(1U, std::get<2>((*canonical)[0]));
  EXPECT_EQ(2U, std::get<2>((*canonical)[1]));
  EXPECT_EQ(3U, std::get<2>((*canonical)[2]));
  EXPECT_EQ(5U, std::get<2>((*canonical)[3]));
  EXPECT_EQ(6U, std::get<2>((*canonical)[4]));
  EXPECT_EQ(2U, independent_closed_component_count(support));

  std::vector<IndependentSupportKey> reordered = *canonical;
  std::rotate(reordered.begin(), reordered.begin() + 3, reordered.end());
  EXPECT_NE(reordered, *canonical)
      << "component order must remain observable even when support is equal";
  EXPECT_TRUE(independent_matches_canonical_component_order(
      support, *canonical));
  EXPECT_FALSE(independent_matches_canonical_component_order(
      support, reordered));
  std::vector<IndependentSupportKey> reorderedSet = reordered;
  std::sort(reorderedSet.begin(), reorderedSet.end());
  std::vector<IndependentSupportKey> canonicalSet = *canonical;
  std::sort(canonicalSet.begin(), canonicalSet.end());
  EXPECT_EQ(canonicalSet, reorderedSet);

  auto open = support;
  std::get<3>(open[1]) = 7U;
  EXPECT_FALSE(independent_canonical_component_order(open).has_value());

  auto duplicateOrigin = support;
  std::get<2>(duplicateOrigin[1]) = std::get<2>(duplicateOrigin[0]);
  EXPECT_FALSE(
      independent_canonical_component_order(duplicateOrigin).has_value());
}

TEST(FieldTransportAtlas, PreservesSingleComponentCanonicalCycleSequence) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const CrossFieldResult field = make_zero_transport_field(mesh);
  const auto expected = independent_cycle_facts(mesh, field);
  ASSERT_TRUE(expected.has_value());

  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built) << describe_field_atlas_build_error(built.error());
  const auto found = std::find_if(
      expected->begin(), expected->end(), [](const IndependentCycleRow &row) {
        return row.kind == FieldCycleKind::LocalVertex && !row.support.empty();
      });
  ASSERT_NE(expected->end(), found);
  ASSERT_FALSE(found->orderedSupport.empty());
  EXPECT_EQ(1U, independent_closed_component_count(found->support));

  const auto published = std::find_if(
      built.value().cycles().begin(), built.value().cycles().end(),
      [&](const FieldCycleWitness &cycle) {
        return cycle.kind == found->kind && cycle.localVertex.has_value() &&
               found->localVertex.has_value() &&
               cycle.localVertex->index() == *found->localVertex;
      });
  ASSERT_NE(built.value().cycles().end(), published);
  std::vector<IndependentSupportKey> publishedOrder;
  for (const FieldTransportStep &step : published->steps) {
    publishedOrder.emplace_back(step.sourceEdge.first().index(),
                                step.sourceEdge.second().index(),
                                step.fromFace.index(), step.toFace.index());
  }
  EXPECT_EQ(found->orderedSupport, publishedOrder);
}

TEST(FieldTransportAtlas, IndependentOracleRejectsCycleOrderingTamper) {
  const TriMesh mesh = make_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  const CrossFieldResult field = make_zero_transport_field(mesh);
  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built) << describe_field_atlas_build_error(built.error());
  const IndependentAtlasSnapshot baseline = independent_snapshot(built.value());
  ASSERT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, baseline));

  const auto cycleIt = std::find_if(
      baseline.cycles.begin(), baseline.cycles.end(),
      [](const FieldCycleWitness &cycle) { return cycle.steps.size() >= 2U; });
  ASSERT_NE(baseline.cycles.end(), cycleIt);
  const std::size_t cycleIndex =
      static_cast<std::size_t>(cycleIt - baseline.cycles.begin());

  IndependentAtlasSnapshot open = baseline;
  open.cycles[cycleIndex].steps.back().toFace =
      open.cycles[cycleIndex].steps.front().toFace;
  EXPECT_EQ(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
            independent_validate_snapshot(
                mesh, *sourceAuthority, field, {}, open));

  IndependentAtlasSnapshot duplicateOrigin = baseline;
  duplicateOrigin.cycles[cycleIndex].steps[1].fromFace =
      duplicateOrigin.cycles[cycleIndex].steps[0].fromFace;
  EXPECT_EQ(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
            independent_validate_snapshot(
                mesh, *sourceAuthority, field, {}, duplicateOrigin));

  IndependentAtlasSnapshot invalidAdjacency = baseline;
  const std::size_t originalAdjacency =
      invalidAdjacency.cycles[cycleIndex].steps.front().adjacency.index();
  const auto replacement = std::find_if(
      invalidAdjacency.adjacencies.begin(), invalidAdjacency.adjacencies.end(),
      [&](const FieldTransportAdjacency &adjacency) {
        return adjacency.id.index() != originalAdjacency;
      });
  ASSERT_NE(invalidAdjacency.adjacencies.end(), replacement);
  invalidAdjacency.cycles[cycleIndex].steps.front().adjacency = replacement->id;
  EXPECT_EQ(FieldAtlasBuildErrorCode::CycleTransportMismatch,
            independent_validate_snapshot(
                mesh, *sourceAuthority, field, {}, invalidAdjacency));
}

TEST(FieldTransportAtlas,
     OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow) {
  const TriMesh mesh = make_two_interior_islands_disk();
  ASSERT_EQ(1U, mesh.boundaryLoops.size());
  const CrossFieldResult field = make_zero_transport_field(mesh);
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());

  // Establish the discriminating subject entirely from source topology before
  // atlas construction.  This disk has two interior degree-three stars, so the
  // algebraic boundary row is six directed support edges in two closed
  // components.
  const auto expected = independent_cycle_facts(mesh, field);
  ASSERT_TRUE(expected.has_value());
  const auto expectedBoundary = std::find_if(
      expected->begin(), expected->end(), [](const IndependentCycleRow &row) {
        return row.kind == FieldCycleKind::BoundaryLoop;
      });
  ASSERT_NE(expected->end(), expectedBoundary);
  ASSERT_EQ(6U, expectedBoundary->support.size());
  ASSERT_EQ(6U, expectedBoundary->orderedSupport.size());
  const auto componentCount =
      independent_closed_component_count(expectedBoundary->support);
  ASSERT_TRUE(componentCount.has_value());
  ASSERT_EQ(2U, *componentCount);
  const auto independentlyOrdered =
      independent_canonical_component_order(expectedBoundary->support);
  ASSERT_TRUE(independentlyOrdered.has_value());
  ASSERT_EQ(expectedBoundary->orderedSupport, *independentlyOrdered);

  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built) << describe_field_atlas_build_error(built.error());
  const auto &cycles = built.value().cycles();
  const auto published = std::find_if(
      cycles.begin(), cycles.end(), [](const FieldCycleWitness &cycle) {
        return cycle.kind == FieldCycleKind::BoundaryLoop;
      });
  ASSERT_NE(cycles.end(), published);
  ASSERT_EQ(6U, published->steps.size());

  std::vector<IndependentSupportKey> publishedOrder;
  publishedOrder.reserve(published->steps.size());
  std::set<SourceEdgeTopologyKey> publishedEdges;
  for (const FieldTransportStep &step : published->steps) {
    publishedOrder.emplace_back(step.sourceEdge.first().index(),
                                step.sourceEdge.second().index(),
                                step.fromFace.index(), step.toFace.index());
    EXPECT_TRUE(publishedEdges.insert(step.sourceEdge).second)
        << "every algebraic support edge must be consumed exactly once";
  }
  EXPECT_EQ(expectedBoundary->orderedSupport, publishedOrder);
  EXPECT_EQ(expectedBoundary->support,
            independent_published_support(*published));

  const IndependentAtlasSnapshot baseline = independent_snapshot(built.value());
  EXPECT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, baseline));

  // Falsifier: preserve the exact six-step multiset and each component's
  // internal order while swapping the two closed components.  The independent
  // snapshot validator must reject that producer ordering.
  const std::size_t cycleIndex = static_cast<std::size_t>(
      published - cycles.begin());
  std::size_t firstComponentSize = 0U;
  const std::uint64_t startFace =
      std::get<2>(expectedBoundary->orderedSupport.front());
  std::uint64_t currentFace = startFace;
  do {
    ASSERT_LT(firstComponentSize, expectedBoundary->orderedSupport.size());
    ASSERT_EQ(currentFace,
              std::get<2>(expectedBoundary->orderedSupport[firstComponentSize]));
    currentFace =
        std::get<3>(expectedBoundary->orderedSupport[firstComponentSize]);
    ++firstComponentSize;
  } while (currentFace != startFace);
  ASSERT_GT(firstComponentSize, 0U);
  ASSERT_LT(firstComponentSize, expectedBoundary->orderedSupport.size());

  IndependentAtlasSnapshot reordered = baseline;
  auto &reorderedSteps = reordered.cycles[cycleIndex].steps;
  std::rotate(reorderedSteps.begin(),
              reorderedSteps.begin() + firstComponentSize,
              reorderedSteps.end());
  EXPECT_EQ(independent_published_support(baseline.cycles[cycleIndex]),
            independent_published_support(reordered.cycles[cycleIndex]));
  EXPECT_EQ(FieldAtlasBuildErrorCode::IncompleteCycleBasis,
            independent_validate_snapshot(
                mesh, *sourceAuthority, field, {}, reordered));
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

TEST(FieldTransportAtlas,
     SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle) {
  constexpr int targetVertex = 4;
  const TriMesh mesh = make_skew_four_triangle_fan();
  ASSERT_EQ(0, mesh.isBoundaryVertex(targetVertex));

  const auto sourceEdge = [&](const int first, const int second) {
    return SourceEdgeTopologyKey::from_indices(
               first, second, static_cast<std::size_t>(mesh.V.rows()))
        .value();
  };
  const std::array<SourceEdgeTopologyKey, 2> targetHardEdges{
      sourceEdge(1, targetVertex), sourceEdge(3, targetVertex)};
  const std::set<SourceEdgeTopologyKey> hardEdges(targetHardEdges.begin(),
                                                   targetHardEdges.end());
  ASSERT_EQ(2U, hardEdges.size());

  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
  ASSERT_TRUE(sourceAuthority.has_value());
  ASSERT_EQ(2U, sourceAuthority->regions().size());

  std::set<std::set<int>> regionFaceSets;
  for (const auto &region : sourceAuthority->regions()) {
    std::set<int> rows;
    for (const SourceFaceId row : sourceAuthority->rows_for_region(region.id())) {
      rows.insert(static_cast<int>(row.index()));
    }
    regionFaceSets.insert(std::move(rows));
  }
  EXPECT_EQ((std::set<std::set<int>>{{0, 3}, {1, 2}}), regionFaceSets);

  const auto sourceEdgeRow = [&](const SourceEdgeTopologyKey &key) {
    for (int edge = 0; edge < mesh.EV.rows(); ++edge) {
      if (edge_key(mesh, edge) == key) return edge;
    }
    return -1;
  };
  std::set<directional::authority::TopologyRegionId> incidentRegions;
  std::size_t sameRegionTargetHardEdgeCount = 0U;
  for (const SourceEdgeTopologyKey &hardEdge : targetHardEdges) {
    ASSERT_NE(hardEdges.end(), hardEdges.find(hardEdge));
    EXPECT_TRUE(hardEdge.first().index() ==
                    static_cast<std::size_t>(targetVertex) ||
                hardEdge.second().index() ==
                    static_cast<std::size_t>(targetVertex));
    const int edge = sourceEdgeRow(hardEdge);
    ASSERT_GE(edge, 0);
    ASSERT_GE(mesh.EF(edge, 0), 0);
    ASSERT_GE(mesh.EF(edge, 1), 0);
    const SourceFaceId first = SourceFaceId::from_index(
        mesh.EF(edge, 0), static_cast<std::size_t>(mesh.F.rows())).value();
    const SourceFaceId second = SourceFaceId::from_index(
        mesh.EF(edge, 1), static_cast<std::size_t>(mesh.F.rows())).value();
    const auto firstRegion = sourceAuthority->region_for_row(first);
    const auto secondRegion = sourceAuthority->region_for_row(second);
    EXPECT_NE(firstRegion, secondRegion);
    incidentRegions.insert(firstRegion);
    incidentRegions.insert(secondRegion);
    sameRegionTargetHardEdgeCount += firstRegion == secondRegion ? 1U : 0U;
  }
  ASSERT_EQ(2U, incidentRegions.size());
  EXPECT_EQ(0U, sameRegionTargetHardEdgeCount)
      << "the target hard edges must be separating cuts, not same-region "
         "slits";
  const auto expectedOwnerRegion = *incidentRegions.begin();

  CrossFieldResult field;
  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  ASSERT_EQ(field.singularCycles.size(), field.singularIndices.size());
  std::size_t interiorSingularityCount = 0U;
  std::optional<int> targetIndex;
  for (Eigen::Index row = 0; row < field.singularCycles.size(); ++row) {
    const int vertex = field.singularCycles(row);
    ASSERT_GE(vertex, 0);
    ASSERT_LT(vertex, mesh.V.rows());
    if (mesh.isBoundaryVertex(vertex) != 0) continue;
    ++interiorSingularityCount;
    EXPECT_EQ(targetVertex, vertex);
    targetIndex = field.singularIndices(row);
  }
  ASSERT_EQ(1U, interiorSingularityCount);
  ASSERT_TRUE(targetIndex.has_value());
  ASSERT_EQ(1, *targetIndex);

  const std::vector<SourceFaceId> expectedOwnerRows =
      sourceAuthority->rows_for_region(expectedOwnerRegion);
  ASSERT_EQ(2U, expectedOwnerRows.size());
  std::set<int> expectedOwnerGlobalVertexSet;
  for (const SourceFaceId row : expectedOwnerRows) {
    ASSERT_LT(row.index(), static_cast<std::size_t>(mesh.F.rows()));
    for (int corner = 0; corner < 3; ++corner) {
      expectedOwnerGlobalVertexSet.insert(
          mesh.F(static_cast<int>(row.index()), corner));
    }
  }
  const std::vector<int> expectedOwnerGlobalVertices(
      expectedOwnerGlobalVertexSet.begin(), expectedOwnerGlobalVertexSet.end());
  std::map<int, int> expectedOwnerLocalByGlobal;
  Eigen::MatrixXd expectedOwnerVertices(
      static_cast<Eigen::Index>(expectedOwnerGlobalVertices.size()), 3);
  for (std::size_t local = 0; local < expectedOwnerGlobalVertices.size();
       ++local) {
    const int global = expectedOwnerGlobalVertices[local];
    expectedOwnerLocalByGlobal.emplace(global, static_cast<int>(local));
    expectedOwnerVertices.row(static_cast<Eigen::Index>(local)) =
        mesh.V.row(global);
  }
  Eigen::MatrixXi expectedOwnerFaces(
      static_cast<Eigen::Index>(expectedOwnerRows.size()), 3);
  Eigen::MatrixXd expectedOwnerPrimary(
      static_cast<Eigen::Index>(expectedOwnerRows.size()), 3);
  Eigen::MatrixXd expectedOwnerSecondary(
      static_cast<Eigen::Index>(expectedOwnerRows.size()), 3);
  for (std::size_t localFace = 0; localFace < expectedOwnerRows.size();
       ++localFace) {
    const int globalFace = static_cast<int>(expectedOwnerRows[localFace].index());
    for (int corner = 0; corner < 3; ++corner) {
      const auto localVertex = expectedOwnerLocalByGlobal.find(
          mesh.F(globalFace, corner));
      ASSERT_NE(expectedOwnerLocalByGlobal.end(), localVertex);
      expectedOwnerFaces(static_cast<Eigen::Index>(localFace), corner) =
          localVertex->second;
    }
    expectedOwnerPrimary.row(static_cast<Eigen::Index>(localFace)) =
        field.primaryDirections.row(globalFace);
    expectedOwnerSecondary.row(static_cast<Eigen::Index>(localFace)) =
        field.secondaryDirections.row(globalFace);
  }
  TriMesh expectedOwnerMesh;
  ASSERT_NO_THROW(
      expectedOwnerMesh.set_mesh(expectedOwnerVertices, expectedOwnerFaces));
  EXPECT_EQ(1, expectedOwnerMesh.V.rows() - expectedOwnerMesh.EV.rows() +
                   expectedOwnerMesh.F.rows());
  EXPECT_EQ(1,
            sourceAuthority->region(expectedOwnerRegion).euler_characteristic());
  ASSERT_EQ(1U, expectedOwnerMesh.boundaryLoops.size());
  EXPECT_EQ(1,
            sourceAuthority->region(expectedOwnerRegion).boundary_loop_count());

  std::size_t ownerInteriorVertexCount = 0U;
  for (int vertex = 0; vertex < expectedOwnerMesh.V.rows(); ++vertex) {
    ownerInteriorVertexCount +=
        expectedOwnerMesh.isBoundaryVertex(vertex) == 0 ? 1U : 0U;
  }
  EXPECT_EQ(0U, ownerInteriorVertexCount);

  const auto targetLocal = expectedOwnerLocalByGlobal.find(targetVertex);
  ASSERT_NE(expectedOwnerLocalByGlobal.end(), targetLocal);
  const auto &ownerBoundary = expectedOwnerMesh.boundaryLoops.front();
  ASSERT_NE(ownerBoundary.end(),
            std::find(ownerBoundary.begin(), ownerBoundary.end(),
                      targetLocal->second));

  CrossFieldResult expectedOwnerField;
  ASSERT_NO_THROW({
    directional::PCFaceTangentBundle ownerBundle;
    ownerBundle.init(expectedOwnerMesh);
    directional::CartesianField rawOwnerField;
    rawOwnerField.init(ownerBundle, directional::fieldTypeEnum::RAW_FIELD,
                       directional::fields::kCrossFieldDegree);
    rawOwnerField.set_extrinsic_field(directional::fields::make_raw_cross_field(
        expectedOwnerMesh, expectedOwnerPrimary, expectedOwnerSecondary));
    expectedOwnerField = directional::fields::finalize_cross_field_result(
        rawOwnerField, false, true);
  });
  const auto expectedOwnerCycleFacts =
      independent_cycle_facts(expectedOwnerMesh, expectedOwnerField);
  ASSERT_TRUE(expectedOwnerCycleFacts.has_value());
  ASSERT_EQ(1U, expectedOwnerCycleFacts->size());
  const IndependentCycleRow &expectedRelativeBoundary =
      expectedOwnerCycleFacts->front();
  ASSERT_EQ(FieldCycleKind::BoundaryLoop, expectedRelativeBoundary.kind);
  ASSERT_EQ(4, expectedRelativeBoundary.turningLift);
  ASSERT_NE(*targetIndex, expectedRelativeBoundary.turningLift)
      << "separating ownership is source-incidence/containment authority; "
         "the region-relative boundary lift is not the global vertex index";
  const int expectedRelativeLift = expectedRelativeBoundary.turningLift;

  auto built =
      FieldTransportAtlas::make(mesh, *sourceAuthority, hardEdges, field);
  ASSERT_TRUE(built) << describe_field_atlas_build_error(built.error());
  ASSERT_EQ(1U, built.value().source_boundary_cycles().size());
  const FieldSourceBoundaryCycleFact &globalBoundary =
      built.value().source_boundary_cycles().front();
  ASSERT_FALSE(globalBoundary.sourceEdges.empty());
  std::set<directional::authority::TopologyRegionId> boundarySupportRegions;
  std::set<SourceEdgeTopologyKey> coveredSourceBoundaryEdges;
  for (const FieldSourceBoundaryCycleAssociation &association :
       built.value().source_boundary_cycle_associations()) {
    if (association.sourceBoundaryCycle != globalBoundary.id) continue;
    boundarySupportRegions.insert(association.topologyRegion);
    for (const SourceEdgeTopologyKey &edge : association.sourceBoundaryEdges) {
      EXPECT_TRUE(coveredSourceBoundaryEdges.insert(edge).second)
          << "source-boundary regional support must be disjoint";
      EXPECT_EQ(0U, hardEdges.count(edge))
          << "hard-feature cut edges are not source-boundary support";
    }
  }
  EXPECT_EQ(incidentRegions, boundarySupportRegions);
  EXPECT_EQ(std::set<SourceEdgeTopologyKey>(globalBoundary.sourceEdges.begin(),
                                            globalBoundary.sourceEdges.end()),
            coveredSourceBoundaryEdges);
  const auto targetFacts = std::count_if(
      built.value().singularities().begin(), built.value().singularities().end(),
      [&](const FieldSingularityFact &singularity) {
        return singularity.sourceVertex.index() ==
               static_cast<std::size_t>(targetVertex);
      });
  ASSERT_EQ(1, targetFacts);
  const auto singularity = std::find_if(
      built.value().singularities().begin(), built.value().singularities().end(),
      [&](const FieldSingularityFact &candidate) {
        return candidate.sourceVertex.index() ==
               static_cast<std::size_t>(targetVertex);
      });
  ASSERT_NE(built.value().singularities().end(), singularity);
  EXPECT_EQ(1, singularity->indexNumerator);
  ASSERT_TRUE(singularity->topologyRegion.has_value());
  EXPECT_EQ(expectedOwnerRegion, *singularity->topologyRegion);
  ASSERT_TRUE(singularity->localCycle.has_value());
  ASSERT_LT(singularity->localCycle->index(), built.value().cycles().size());
  const FieldCycleWitness &ownerCycle =
      built.value().cycles()[singularity->localCycle->index()];
  EXPECT_EQ(FieldCycleKind::BoundaryLoop, ownerCycle.kind);
  EXPECT_EQ(expectedOwnerRegion, ownerCycle.topologyRegion);
  EXPECT_EQ(expectedRelativeLift, ownerCycle.turningLift);
  EXPECT_NE(singularity->indexNumerator, ownerCycle.turningLift);
  EXPECT_EQ(FieldSingularityFact::PortPolicy::BarrierAbsorbed,
            singularity->portPolicy);

  const auto originAttachments = std::count_if(
      built.value().branch_topology().singularity_port_attachments().begin(),
      built.value().branch_topology().singularity_port_attachments().end(),
      [&](const FieldSingularityPortAttachment &attachment) {
        return attachment.singularity == singularity->id;
      });
  EXPECT_EQ(0, originAttachments);

  const auto diagnostics = std::find_if(
      built.value().region_transport_diagnostics().begin(),
      built.value().region_transport_diagnostics().end(),
      [&](const auto &candidate) {
        return candidate.topologyRegion == expectedOwnerRegion;
      });
  ASSERT_NE(built.value().region_transport_diagnostics().end(), diagnostics);
  EXPECT_EQ(1U,
            diagnostics->separatingFeatureBoundaryBoundSingularityCount);
  EXPECT_EQ(0U, diagnostics->slitBoundaryBoundSingularityCount);
  for (const auto &region : built.value().region_transport_diagnostics()) {
    EXPECT_EQ(0U, region.unboundSingularityCount);
  }

  const std::vector<SourceFaceTopologyKey> baselineTopology =
      independent_row_topology(mesh, *sourceAuthority);
  ASSERT_EQ(static_cast<std::size_t>(mesh.F.rows()), baselineTopology.size());
  std::map<SourceFaceTopologyKey,
           std::pair<Eigen::RowVector3d, Eigen::RowVector3d>>
      semanticDirections;
  for (int row = 0; row < mesh.F.rows(); ++row) {
    const auto [it, inserted] = semanticDirections.emplace(
        baselineTopology[static_cast<std::size_t>(row)],
        std::make_pair(Eigen::RowVector3d(field.primaryDirections.row(row)),
                       Eigen::RowVector3d(field.secondaryDirections.row(row))));
    EXPECT_TRUE(inserted);
    (void)it;
  }

  Eigen::MatrixXi permutedFaces(mesh.F.rows(), 3);
  for (int row = 0; row < mesh.F.rows(); ++row) {
    permutedFaces.row(row) = mesh.F.row(mesh.F.rows() - 1 - row);
  }
  TriMesh permutedMesh;
  ASSERT_NO_THROW(permutedMesh.set_mesh(mesh.V, permutedFaces));
  const auto permutedAuthority = make_source_authority(permutedMesh, hardEdges);
  ASSERT_TRUE(permutedAuthority.has_value());
  EXPECT_EQ(sourceAuthority->regions(), permutedAuthority->regions())
      << "topology-region authority IDs must survive source-face row storage "
         "permutation";

  Eigen::MatrixXd permutedPrimary(permutedMesh.F.rows(), 3);
  Eigen::MatrixXd permutedSecondary(permutedMesh.F.rows(), 3);
  for (int row = 0; row < permutedMesh.F.rows(); ++row) {
    const SourceFaceId rowId = SourceFaceId::from_index(
        row, static_cast<std::size_t>(permutedMesh.F.rows())).value();
    const SourceFaceTopologyKey &topology =
        permutedAuthority->topology_for_row(rowId);
    const auto directions = semanticDirections.find(topology);
    ASSERT_NE(semanticDirections.end(), directions);
    permutedPrimary.row(row) = directions->second.first;
    permutedSecondary.row(row) = directions->second.second;
  }

  CrossFieldResult permutedField;
  ASSERT_NO_THROW({
    directional::PCFaceTangentBundle permutedBundle;
    permutedBundle.init(permutedMesh);
    directional::CartesianField rawPermutedField;
    rawPermutedField.init(permutedBundle, directional::fieldTypeEnum::RAW_FIELD,
                          directional::fields::kCrossFieldDegree);
    rawPermutedField.set_extrinsic_field(
        directional::fields::make_raw_cross_field(
            permutedMesh, permutedPrimary, permutedSecondary));
    permutedField = directional::fields::finalize_cross_field_result(
        rawPermutedField, false, true);
  });
  ASSERT_TRUE(permutedField.matchingComputed);
  ASSERT_TRUE(permutedField.singularitiesComputed);
  ASSERT_EQ(permutedField.singularCycles.size(),
            permutedField.singularIndices.size());
  std::size_t permutedInteriorSingularityCount = 0U;
  for (Eigen::Index row = 0; row < permutedField.singularCycles.size(); ++row) {
    const int vertex = permutedField.singularCycles(row);
    ASSERT_GE(vertex, 0);
    ASSERT_LT(vertex, permutedMesh.V.rows());
    if (permutedMesh.isBoundaryVertex(vertex) != 0) continue;
    ++permutedInteriorSingularityCount;
    EXPECT_EQ(targetVertex, vertex);
    EXPECT_EQ(1, permutedField.singularIndices(row));
  }
  ASSERT_EQ(1U, permutedInteriorSingularityCount);

  auto permutedBuilt = FieldTransportAtlas::make(
      permutedMesh, *permutedAuthority, hardEdges, permutedField);
  ASSERT_TRUE(permutedBuilt)
      << describe_field_atlas_build_error(permutedBuilt.error());
  EXPECT_EQ(built.value().source_boundary_cycles(),
            permutedBuilt.value().source_boundary_cycles());
  EXPECT_EQ(built.value().source_boundary_cycle_associations(),
            permutedBuilt.value().source_boundary_cycle_associations());
  const auto permutedSingularity = std::find_if(
      permutedBuilt.value().singularities().begin(),
      permutedBuilt.value().singularities().end(),
      [&](const FieldSingularityFact &candidate) {
        return candidate.sourceVertex.index() ==
               static_cast<std::size_t>(targetVertex);
      });
  ASSERT_NE(permutedBuilt.value().singularities().end(), permutedSingularity);
  EXPECT_EQ(1, permutedSingularity->indexNumerator);
  ASSERT_TRUE(permutedSingularity->topologyRegion.has_value());
  ASSERT_TRUE(permutedSingularity->localCycle.has_value());
  EXPECT_EQ(expectedOwnerRegion, *permutedSingularity->topologyRegion);
  EXPECT_EQ(*singularity->localCycle, *permutedSingularity->localCycle)
      << "canonical separating ownership must use stable authority identity, "
         "not source-face storage order";
  ASSERT_LT(permutedSingularity->localCycle->index(),
            permutedBuilt.value().cycles().size());
  const FieldCycleWitness &permutedOwnerCycle =
      permutedBuilt.value().cycles()[permutedSingularity->localCycle->index()];
  EXPECT_EQ(FieldCycleKind::BoundaryLoop, permutedOwnerCycle.kind);
  EXPECT_EQ(expectedOwnerRegion, permutedOwnerCycle.topologyRegion);
  EXPECT_EQ(4, permutedOwnerCycle.turningLift);
  EXPECT_EQ(expectedRelativeLift, permutedOwnerCycle.turningLift);
  EXPECT_EQ(FieldSingularityFact::PortPolicy::BarrierAbsorbed,
            permutedSingularity->portPolicy);
  const auto permutedOriginAttachments = std::count_if(
      permutedBuilt.value()
          .branch_topology()
          .singularity_port_attachments()
          .begin(),
      permutedBuilt.value()
          .branch_topology()
          .singularity_port_attachments()
          .end(),
      [&](const FieldSingularityPortAttachment &attachment) {
        return attachment.singularity == permutedSingularity->id;
      });
  EXPECT_EQ(0, permutedOriginAttachments);
}

TEST(FieldTransportAtlas,
     SingleFaceBoundaryRegionPublishesPartialGlobalBoundarySupport) {
  const TriMesh mesh = make_skew_four_triangle_fan();
  const auto sourceEdge = [&](const int first, const int second) {
    return SourceEdgeTopologyKey::from_indices(
               first, second, static_cast<std::size_t>(mesh.V.rows()))
        .value();
  };
  const std::set<SourceEdgeTopologyKey> hardEdges{
      sourceEdge(1, 4), sourceEdge(2, 4)};
  const auto sourceAuthority = make_source_authority(mesh, hardEdges);
  ASSERT_TRUE(sourceAuthority.has_value());

  std::optional<directional::authority::TopologyRegionId> singleFaceRegion;
  for (const auto &region : sourceAuthority->regions()) {
    const auto rows = sourceAuthority->rows_for_region(region.id());
    if (rows.size() == 1U && rows.front().index() == 1U) {
      singleFaceRegion = region.id();
      break;
    }
  }
  ASSERT_TRUE(singleFaceRegion.has_value());

  CrossFieldResult field;
  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  auto built = FieldTransportAtlas::make(
      mesh, *sourceAuthority, hardEdges, field);
  ASSERT_TRUE(built) << describe_field_atlas_build_error(built.error());
  ASSERT_EQ(1U, built.value().source_boundary_cycles().size());

  const SourceEdgeTopologyKey expectedSupport = sourceEdge(1, 2);
  const auto association = std::find_if(
      built.value().source_boundary_cycle_associations().begin(),
      built.value().source_boundary_cycle_associations().end(),
      [&](const FieldSourceBoundaryCycleAssociation &candidate) {
        return candidate.topologyRegion == *singleFaceRegion;
      });
  ASSERT_NE(built.value().source_boundary_cycle_associations().end(),
            association);
  ASSERT_EQ(1U, association->sourceBoundaryEdges.size());
  EXPECT_EQ(expectedSupport, association->sourceBoundaryEdges.front());
  EXPECT_EQ(0U, hardEdges.count(association->sourceBoundaryEdges.front()));
  ASSERT_LT(association->regionalCycle.index(), built.value().cycles().size());
  EXPECT_EQ(FieldCycleKind::BoundaryLoop,
            built.value().cycles()[association->regionalCycle.index()].kind);
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

TEST(FieldTransportAtlas, PublishesCanonicalBranchFramesAndBoundaryPairings) {
  const TriMesh mesh = make_skew_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built)
      << describe_field_atlas_build_error(built.error());
  const FieldBranchTopology &topology = built.value().branch_topology();
  ASSERT_EQ(static_cast<std::size_t>(mesh.F.rows()), topology.frames().size());
  ASSERT_FALSE(topology.transports().empty());
  bool sawDistinctCarriers = false;
  for (const auto &frame : topology.frames()) {
    ASSERT_EQ(4U, frame.branches.size());
    for (std::size_t branch = 0; branch < frame.branches.size(); ++branch) {
      const auto &pairing = frame.branches[branch];
      EXPECT_EQ(branch, pairing.branch.value());
      EXPECT_EQ(3U, pairing.intervals.size());
      EXPECT_FALSE(pairing.incomingCarriers.empty());
      EXPECT_FALSE(pairing.outgoingCarriers.empty());
      sawDistinctCarriers = sawDistinctCarriers ||
          pairing.incomingCarriers != pairing.outgoingCarriers;
    }
  }
  EXPECT_TRUE(sawDistinctCarriers);
  EXPECT_NE(0U, topology.semantic_digest());
  EXPECT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, independent_snapshot(built.value())));
}

TEST(FieldTransportAtlas, PublishesCheckedSingularityPortAttachments) {
  const TriMesh mesh = make_skew_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built)
      << describe_field_atlas_build_error(built.error());
  ASSERT_EQ(1U, built.value().singularities().size());
  EXPECT_EQ(1, built.value().singularities().front().indexNumerator);
  const auto &attachments =
      built.value().branch_topology().singularity_port_attachments();
  ASSERT_EQ(3U, attachments.size());
  for (std::size_t slot = 0; slot < attachments.size(); ++slot) {
    EXPECT_EQ(static_cast<int>(slot), attachments[slot].localSlot);
    EXPECT_EQ(built.value().singularities().front().id,
              attachments[slot].singularity);
    EXPECT_EQ(built.value().singularities().front().sourceVertex,
              attachments[slot].sourceVertex);
    const auto *frame = built.value().branch_topology().find_frame(
        attachments[slot].startFace);
    ASSERT_NE(nullptr, frame);
    ASSERT_LT(attachments[slot].branch.value(), frame->branches.size());
    const auto &outgoing = frame->branches[attachments[slot].branch.value()]
                               .outgoingCarriers;
    EXPECT_NE(outgoing.end(),
              std::find(outgoing.begin(), outgoing.end(),
                        attachments[slot].firstOutgoingCarrier));
  }

  const auto rowTopology = independent_row_topology(mesh, *sourceAuthority);
  std::optional<IndependentPortOrderKey> previousOrder;
  for (const auto &attachment : attachments) {
    const auto currentOrder = independent_port_order_key(
        mesh, field, rowTopology, attachment.sourceVertex, attachment);
    ASSERT_TRUE(currentOrder.has_value());
    if (previousOrder.has_value()) {
      EXPECT_TRUE(
          previousOrder->counterClockwiseFanSlot <
              currentOrder->counterClockwiseFanSlot ||
          (previousOrder->counterClockwiseFanSlot ==
               currentOrder->counterClockwiseFanSlot &&
           previousOrder->sectorAngle < currentOrder->sectorAngle));
    }
    previousOrder = currentOrder;
  }
  bool sawBranchDisambiguatedRepresentative = false;
  for (std::size_t first = 0; first < attachments.size(); ++first) {
    for (std::size_t second = first + 1U; second < attachments.size(); ++second) {
      sawBranchDisambiguatedRepresentative =
          sawBranchDisambiguatedRepresentative ||
          (attachments[first].startFace == attachments[second].startFace &&
           attachments[first].firstOutgoingCarrier ==
               attachments[second].firstOutgoingCarrier &&
           attachments[first].branch != attachments[second].branch);
    }
  }
  EXPECT_TRUE(sawBranchDisambiguatedRepresentative);

  CrossFieldResult mismatchedBoundary = field;
  bool mutatedBoundaryAlias = false;
  for (Eigen::Index row = 0; row < mismatchedBoundary.singularCycles.size();
       ++row) {
    const int vertex = mismatchedBoundary.singularCycles(row);
    ASSERT_GE(vertex, 0);
    ASSERT_LT(vertex, mesh.V.rows());
    if (mesh.isBoundaryVertex(vertex) == 0) continue;
    ++mismatchedBoundary.singularIndices(row);
    mutatedBoundaryAlias = true;
    break;
  }
  ASSERT_TRUE(mutatedBoundaryAlias);
  auto mismatched = FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, mismatchedBoundary);
  ASSERT_FALSE(mismatched);
  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
            mismatched.error().code);

  Eigen::Index boundaryAliasRow = -1;
  for (Eigen::Index row = 0; row < field.singularCycles.size(); ++row) {
    const int vertex = field.singularCycles(row);
    if (vertex >= 0 && vertex < mesh.V.rows() &&
        mesh.isBoundaryVertex(vertex) != 0) {
      boundaryAliasRow = row;
      break;
    }
  }
  ASSERT_GE(boundaryAliasRow, 0);

  CrossFieldResult missingBoundaryAlias = field;
  missingBoundaryAlias.singularCycles.resize(field.singularCycles.size() - 1);
  missingBoundaryAlias.singularIndices.resize(field.singularIndices.size() - 1);
  Eigen::Index out = 0;
  for (Eigen::Index row = 0; row < field.singularCycles.size(); ++row) {
    if (row == boundaryAliasRow) continue;
    missingBoundaryAlias.singularCycles(out) = field.singularCycles(row);
    missingBoundaryAlias.singularIndices(out) = field.singularIndices(row);
    ++out;
  }
  auto missingAlias = FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, missingBoundaryAlias);
  ASSERT_FALSE(missingAlias);
  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
            missingAlias.error().code);

  CrossFieldResult duplicateBoundaryAlias = field;
  duplicateBoundaryAlias.singularCycles.conservativeResize(
      field.singularCycles.size() + 1);
  duplicateBoundaryAlias.singularIndices.conservativeResize(
      field.singularIndices.size() + 1);
  duplicateBoundaryAlias.singularCycles(field.singularCycles.size()) =
      field.singularCycles(boundaryAliasRow);
  duplicateBoundaryAlias.singularIndices(field.singularIndices.size()) =
      field.singularIndices(boundaryAliasRow);
  auto duplicateAlias = FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, duplicateBoundaryAlias);
  ASSERT_FALSE(duplicateAlias);
  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
            duplicateAlias.error().code);

  CrossFieldResult missingBoundarySupport = field;
  ASSERT_FALSE(missingBoundarySupport.sourceBoundaryCycles.empty());
  ASSERT_GT(missingBoundarySupport.sourceBoundaryCycles.front().sourceEdges.size(),
            1U);
  missingBoundarySupport.sourceBoundaryCycles.front().sourceEdges.pop_back();
  auto missingSupport = FieldTransportAtlas::make(
      mesh, *sourceAuthority, {}, missingBoundarySupport);
  ASSERT_FALSE(missingSupport);
  EXPECT_EQ(FieldAtlasBuildErrorCode::SingularityMismatch,
            missingSupport.error().code);
}

TEST(FieldTransportAtlas, BranchTopologyIsInvariantToEquivalentZ4Relabeling) {
  const TriMesh mesh = make_skew_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult baselineField;
  ASSERT_NO_FATAL_FAILURE(
      make_skew_index_one_singularity_field(mesh, baselineField));
  auto baseline =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, baselineField);
  ASSERT_TRUE(baseline)
      << describe_field_atlas_build_error(baseline.error());
  EXPECT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, baselineField, {},
      independent_snapshot(baseline.value())));

  const std::vector<int> shifts{0, 1, 3, 2};
  CrossFieldResult relabeledField = gauge_relabel_field(mesh, baselineField, shifts);
  bool rawChanged = false;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    rawChanged = rawChanged ||
        !baselineField.primaryDirections.row(face).isApprox(
            relabeledField.primaryDirections.row(face));
  }
  EXPECT_TRUE(rawChanged);
  bool matchingChanged = false;
  for (const auto &transition : relabeledField.edgeTransitions) {
    if (transition.secondFace < 0) continue;
    const auto baselineTransition = std::find_if(
        baselineField.edgeTransitions.begin(), baselineField.edgeTransitions.end(),
        [&](const auto &candidate) {
          return candidate.sourceEdge == transition.sourceEdge;
        });
    ASSERT_NE(baselineField.edgeTransitions.end(), baselineTransition);
    matchingChanged = matchingChanged ||
        transition.matching != baselineTransition->matching;
  }
  EXPECT_TRUE(matchingChanged);

  auto relabeled =
      FieldTransportAtlas::make(mesh, *sourceAuthority, {}, relabeledField);
  ASSERT_TRUE(relabeled)
      << describe_field_atlas_build_error(relabeled.error());
  EXPECT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, relabeledField, {},
      independent_snapshot(relabeled.value())));
  EXPECT_EQ(baseline.value().branch_topology().frames(),
            relabeled.value().branch_topology().frames());
  EXPECT_EQ(baseline.value().branch_topology().transports(),
            relabeled.value().branch_topology().transports());
  for (const auto &transport : relabeled.value().branch_topology().transports()) {
    EXPECT_EQ(static_cast<int>(transport.forward.value()), transport.forwardLift);
    EXPECT_GE(transport.forwardLift, 0);
    EXPECT_LT(transport.forwardLift, 4);
    EXPECT_EQ(transport.forward.inverse(), transport.reverse);
    EXPECT_EQ(QuarterTurn::from_integer(-transport.forwardLift),
              transport.reverse);
  }
  EXPECT_EQ(baseline.value().branch_topology().singularity_port_attachments(),
            relabeled.value().branch_topology().singularity_port_attachments());
  EXPECT_EQ(baseline.value().branch_topology().semantic_digest(),
            relabeled.value().branch_topology().semantic_digest());
  const bool sawNonzeroTransport = std::any_of(
      relabeled.value().branch_topology().transports().begin(),
      relabeled.value().branch_topology().transports().end(),
      [](const auto &transport) { return transport.forward.value() != 0U; });
  EXPECT_TRUE(sawNonzeroTransport);
}

TEST(FieldTransportAtlas, RejectsAmbiguousOrIncompleteBranchTopology) {
  const TriMesh mesh = make_skew_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  field.secondaryDirections.row(0) = field.primaryDirections.row(0);
  auto ambiguous = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_FALSE(ambiguous);
  EXPECT_EQ(FieldAtlasBuildErrorCode::AmbiguousBranchTopology,
            ambiguous.error().code);

  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  field.primaryDirections.row(0).setZero();
  auto incomplete = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_FALSE(incomplete);
  EXPECT_EQ(FieldAtlasBuildErrorCode::InvalidBranchTopology,
            incomplete.error().code);
}

TEST(FieldTransportAtlas,
     IndependentOracleRejectsBranchPairingOrPortAttachmentTamper) {
  const TriMesh mesh = make_skew_four_triangle_fan();
  const auto sourceAuthority = make_source_authority(mesh);
  ASSERT_TRUE(sourceAuthority.has_value());
  CrossFieldResult field;
  ASSERT_NO_FATAL_FAILURE(make_skew_index_one_singularity_field(mesh, field));
  auto built = FieldTransportAtlas::make(mesh, *sourceAuthority, {}, field);
  ASSERT_TRUE(built)
      << describe_field_atlas_build_error(built.error());
  const IndependentAtlasSnapshot baseline = independent_snapshot(built.value());
  ASSERT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, baseline));

  const auto rowTopology = independent_row_topology(mesh, *sourceAuthority);

  IndependentAtlasSnapshot pairingTamper = baseline;
  ASSERT_FALSE(pairingTamper.branchFrames.empty());
  ASSERT_FALSE(pairingTamper.branchFrames.front().branches.empty());
  ASSERT_FALSE(pairingTamper.branchFrames.front().branches.front().intervals.empty());
  pairingTamper.branchFrames.front().branches.front().intervals.front().flow =
      pairingTamper.branchFrames.front().branches.front().intervals.front().flow ==
              FieldBoundaryFlow::Inflow
          ? FieldBoundaryFlow::Outflow
          : FieldBoundaryFlow::Inflow;
  pairingTamper.branchTopologyDigest =
      independent_branch_topology_digest(pairingTamper);
  pairingTamper.atlasDigest =
      independent_atlas_digest(pairingTamper, rowTopology);
  const auto pairingRejection = independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, pairingTamper);
  ASSERT_TRUE(pairingRejection.has_value());
  EXPECT_EQ(FieldAtlasBuildErrorCode::InvalidBranchTopology,
            *pairingRejection);

  IndependentAtlasSnapshot attachmentTamper = baseline;
  ASSERT_EQ(3U, attachmentTamper.singularityPortAttachments.size());
  attachmentTamper.singularityPortAttachments.front().localSlot = 7;
  attachmentTamper.branchTopologyDigest =
      independent_branch_topology_digest(attachmentTamper);
  attachmentTamper.atlasDigest =
      independent_atlas_digest(attachmentTamper, rowTopology);
  const auto attachmentRejection = independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, attachmentTamper);
  ASSERT_TRUE(attachmentRejection.has_value());
  EXPECT_EQ(FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment,
            *attachmentRejection);

  IndependentAtlasSnapshot duplicateIdentityTamper = baseline;
  ASSERT_EQ(3U, duplicateIdentityTamper.singularityPortAttachments.size());
  duplicateIdentityTamper.singularityPortAttachments[1].startFace =
      duplicateIdentityTamper.singularityPortAttachments[0].startFace;
  duplicateIdentityTamper.singularityPortAttachments[1].branch =
      duplicateIdentityTamper.singularityPortAttachments[0].branch;
  duplicateIdentityTamper.singularityPortAttachments[1].firstOutgoingCarrier =
      duplicateIdentityTamper.singularityPortAttachments[0].firstOutgoingCarrier;
  duplicateIdentityTamper.branchTopologyDigest =
      independent_branch_topology_digest(duplicateIdentityTamper);
  duplicateIdentityTamper.atlasDigest =
      independent_atlas_digest(duplicateIdentityTamper, rowTopology);
  const auto duplicateIdentityRejection = independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, duplicateIdentityTamper);
  ASSERT_TRUE(duplicateIdentityRejection.has_value());
  EXPECT_EQ(FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment,
            *duplicateIdentityRejection);

  IndependentAtlasSnapshot nonEquivalentLiftTamper = baseline;
  ASSERT_FALSE(nonEquivalentLiftTamper.branchTransports.empty());
  auto &nonEquivalent = nonEquivalentLiftTamper.branchTransports.front();
  ++nonEquivalent.forwardLift;
  nonEquivalent.forward = QuarterTurn::from_integer(nonEquivalent.forwardLift);
  nonEquivalent.reverse = nonEquivalent.forward.inverse();
  nonEquivalentLiftTamper.branchTopologyDigest =
      independent_branch_topology_digest(nonEquivalentLiftTamper);
  nonEquivalentLiftTamper.atlasDigest =
      independent_atlas_digest(nonEquivalentLiftTamper, rowTopology);
  const auto nonEquivalentLiftRejection = independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, nonEquivalentLiftTamper);
  ASSERT_TRUE(nonEquivalentLiftRejection.has_value());
  EXPECT_EQ(FieldAtlasBuildErrorCode::NonReciprocalAdjacency,
            *nonEquivalentLiftRejection);

  IndependentAtlasSnapshot equivalentLiftRepresentative = baseline;
  ASSERT_FALSE(equivalentLiftRepresentative.branchTransports.empty());
  equivalentLiftRepresentative.branchTransports.front().forwardLift += 4;
  equivalentLiftRepresentative.branchTopologyDigest =
      independent_branch_topology_digest(equivalentLiftRepresentative);
  equivalentLiftRepresentative.atlasDigest =
      independent_atlas_digest(equivalentLiftRepresentative, rowTopology);
  EXPECT_FALSE(independent_validate_snapshot(
      mesh, *sourceAuthority, field, {}, equivalentLiftRepresentative));
}

} // namespace
