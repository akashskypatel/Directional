// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/authority/FieldTransportAtlas.h>

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
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

constexpr double kBranchTopologyTolerance = 1.0e-10;
constexpr double kTwoPi = 2.0 * std::numbers::pi;

std::optional<SourceFaceId> row_for_topology(
    const std::vector<SourceFaceTopologyKey> &rowTopology,
    const SourceFaceTopologyKey &topology) {
  for (std::size_t row = 0; row < rowTopology.size(); ++row) {
    if (rowTopology[row] == topology) return make_id<SourceFaceId>(row);
  }
  return std::nullopt;
}

std::optional<SourceEdgeTopologyKey> typed_edge(
    const SourceVertexId a, const SourceVertexId b) {
  const auto edge = SourceEdgeTopologyKey::make(a, b);
  return edge ? std::optional<SourceEdgeTopologyKey>(edge.value())
              : std::nullopt;
}

std::optional<Eigen::Vector3d> normalized_projected(
    const Eigen::Vector3d &direction, const Eigen::Vector3d &normal) {
  Eigen::Vector3d tangent = direction - direction.dot(normal) * normal;
  const double norm = tangent.norm();
  if (!std::isfinite(norm) || norm <= kBranchTopologyTolerance) {
    return std::nullopt;
  }
  tangent /= norm;
  if (!tangent.allFinite()) return std::nullopt;
  return tangent;
}

double positive_oriented_angle(const Eigen::Vector3d &from,
                               const Eigen::Vector3d &to,
                               const Eigen::Vector3d &normal) {
  double angle = std::atan2(normal.dot(from.cross(to)), from.dot(to));
  if (angle < 0.0) angle += kTwoPi;
  if (angle >= kTwoPi) angle -= kTwoPi;
  return angle;
}

struct BuiltFaceBranchFrame {
  FieldFaceBranchFrame published;
  int rawGauge = 0;
  std::array<Eigen::Vector3d, 4> canonicalDirections;
};

std::optional<FieldBranchBoundaryPairing> build_boundary_pairing(
    const TriMesh &sourceMesh, const SourceFaceId sourceFace,
    const SourceFaceTopologyKey &topology, const TopologyRegionId region,
    const FieldBranch branch, const Eigen::Vector3d &direction,
    FieldAtlasBuildError &error) {
  const auto &vertices = topology.vertices();
  const Eigen::Vector3d p0 = sourceMesh.V.row(
      static_cast<int>(vertices[0].index())).transpose();
  const Eigen::Vector3d p1 = sourceMesh.V.row(
      static_cast<int>(vertices[1].index())).transpose();
  const Eigen::Vector3d p2 = sourceMesh.V.row(
      static_cast<int>(vertices[2].index())).transpose();
  const Eigen::Vector3d e1 = p1 - p0;
  const Eigen::Vector3d e2 = p2 - p0;
  const double a = e1.dot(e1);
  const double b = e1.dot(e2);
  const double c = e2.dot(e2);
  const double det = a * c - b * b;
  if (!std::isfinite(det) || det <= kBranchTopologyTolerance) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::InvalidBranchBoundaryBasis, std::nullopt,
        sourceFace, std::nullopt, region};
    return std::nullopt;
  }
  const double r1 = e1.dot(direction);
  const double r2 = e2.dot(direction);
  const double u = (r1 * c - r2 * b) / det;
  const double v = (r2 * a - r1 * b) / det;
  const std::array<double, 3> dbary{-u - v, u, v};
  if (!std::isfinite(dbary[0]) || !std::isfinite(dbary[1]) ||
      !std::isfinite(dbary[2])) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::InvalidBranchBoundaryDerivative,
        std::nullopt, sourceFace, std::nullopt, region};
    return std::nullopt;
  }
  const auto exactU = FieldExactRational::from_double_exact(u);
  const auto exactV = FieldExactRational::from_double_exact(v);
  if (!exactU.has_value() || !exactV.has_value()) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::InvalidBranchBoundaryDerivative,
        std::nullopt, sourceFace, std::nullopt, region};
    return std::nullopt;
  }
  const FieldBranchDirection exactDirection{
      std::array<FieldExactRational, 3>{-*exactU - *exactV, *exactU, *exactV}};
  if (!exactDirection.is_barycentric()) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::BranchDirectionNotBarycentric,
        std::nullopt, sourceFace, std::nullopt, region, branch};
    return std::nullopt;
  }

  const std::array<std::pair<int, int>, 3> intervalVertices{{{0, 1}, {1, 2},
                                                             {2, 0}}};
  const std::array<int, 3> opposite{{2, 0, 1}};
  FieldBranchBoundaryPairing pairing;
  pairing.branch = branch;
  pairing.direction = exactDirection;
  pairing.intervals.reserve(3U);
  for (std::size_t index = 0; index < 3U; ++index) {
    const SourceVertexId start = vertices[static_cast<std::size_t>(
        intervalVertices[index].first)];
    const SourceVertexId end = vertices[static_cast<std::size_t>(
        intervalVertices[index].second)];
    const auto edge = typed_edge(start, end);
    if (!edge.has_value()) {
      error = FieldAtlasBuildError{
          FieldAtlasBuildErrorCode::InvalidBranchBoundaryEdge, std::nullopt,
          sourceFace, std::nullopt, region};
      return std::nullopt;
    }
    const FieldExactRational &derivative =
        exactDirection[static_cast<std::size_t>(opposite[index])];
    const FieldExactRational zero = FieldExactRational::from_integer(0);
    FieldBoundaryFlow flow = FieldBoundaryFlow::Tangent;
    if (derivative > zero) {
      flow = FieldBoundaryFlow::Inflow;
      pairing.incomingCarriers.push_back(*edge);
    } else if (derivative < zero) {
      flow = FieldBoundaryFlow::Outflow;
      pairing.outgoingCarriers.push_back(*edge);
    }
    pairing.intervals.push_back(
        FieldBranchBoundaryInterval{start, end, *edge, flow});
  }
  if (pairing.incomingCarriers.empty() || pairing.outgoingCarriers.empty()) {
    // Unreachable from valid FieldBranchDirection authority: a nonzero exact
    // triple summing to zero contains both signs. Unit falsifiers use a
    // deliberately tampered direction and are not production coverage.
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::InvalidBranchBoundaryFlow, std::nullopt,
        sourceFace, std::nullopt, region};
    return std::nullopt;
  }
  std::sort(pairing.incomingCarriers.begin(), pairing.incomingCarriers.end());
  std::sort(pairing.outgoingCarriers.begin(), pairing.outgoingCarriers.end());
  return pairing;
}

std::optional<BuiltFaceBranchFrame> build_face_branch_frame(
    const TriMesh &sourceMesh, const SourceFaceId row,
    const SourceFaceTopologyKey &topology, const TopologyRegionId region,
    const SourceComponentId component,
    const fields::CrossFieldResult &crossField,
    FieldAtlasBuildError &error) {
  const auto &vertices = topology.vertices();
  const Eigen::Vector3d p0 = sourceMesh.V.row(
      static_cast<int>(vertices[0].index())).transpose();
  const Eigen::Vector3d p1 = sourceMesh.V.row(
      static_cast<int>(vertices[1].index())).transpose();
  const Eigen::Vector3d p2 = sourceMesh.V.row(
      static_cast<int>(vertices[2].index())).transpose();
  Eigen::Vector3d normal = (p1 - p0).cross(p2 - p0);
  const double normalNorm = normal.norm();
  if (!std::isfinite(normalNorm) || normalNorm <= kBranchTopologyTolerance) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::InvalidBranchTopology, std::nullopt, row,
        std::nullopt, region};
    return std::nullopt;
  }
  normal /= normalNorm;
  const auto reference = normalized_projected(p1 - p0, normal);
  const auto primary = normalized_projected(
      crossField.primaryDirections.row(static_cast<int>(row.index())).transpose(),
      normal);
  const auto secondary = normalized_projected(
      crossField.secondaryDirections.row(static_cast<int>(row.index())).transpose(),
      normal);
  if (!reference.has_value() || !primary.has_value() ||
      !secondary.has_value()) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::InvalidBranchTopology, std::nullopt, row,
        std::nullopt, region};
    return std::nullopt;
  }
  if (std::abs(primary->dot(*secondary)) > 1.0 - 1.0e-8) {
    error = FieldAtlasBuildError{
        FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt, row,
        std::nullopt, region};
    return std::nullopt;
  }
  const std::array<Eigen::Vector3d, 4> rawDirections{
      *primary, *secondary, -*primary, -*secondary};
  std::array<double, 4> angles{};
  int gauge = 0;
  double best = std::numeric_limits<double>::infinity();
  for (int raw = 0; raw < 4; ++raw) {
    angles[static_cast<std::size_t>(raw)] = positive_oriented_angle(
        *reference, rawDirections[static_cast<std::size_t>(raw)], normal);
    if (angles[static_cast<std::size_t>(raw)] < best) {
      best = angles[static_cast<std::size_t>(raw)];
      gauge = raw;
    }
  }
  for (int raw = 0; raw < 4; ++raw) {
    if (raw != gauge &&
        std::abs(angles[static_cast<std::size_t>(raw)] - best) <=
            kBranchTopologyTolerance) {
      error = FieldAtlasBuildError{
          FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt, row,
          std::nullopt, region};
      return std::nullopt;
    }
  }

  BuiltFaceBranchFrame built{
      FieldFaceBranchFrame{topology, region, component, {}}, gauge, {}};
  built.published.branches.reserve(4U);
  for (int semantic = 0; semantic < 4; ++semantic) {
    const int raw = normalized_quarter_turn(gauge + semantic);
    built.canonicalDirections[static_cast<std::size_t>(semantic)] =
        rawDirections[static_cast<std::size_t>(raw)];
    const auto pairing = build_boundary_pairing(
        sourceMesh, row, topology, region, FieldBranch::from_integer(semantic),
        built.canonicalDirections[static_cast<std::size_t>(semantic)], error);
    if (!pairing.has_value()) {
      return std::nullopt;
    }
    built.published.branches.push_back(*pairing);
  }
  return built;
}

const FieldBranchTransportAdjacency *find_branch_transport_in(
    const std::vector<FieldBranchTransportAdjacency> &transports,
    const SourceEdgeTopologyKey &edge) {
  const auto found = std::lower_bound(
      transports.begin(), transports.end(), edge,
      [](const FieldBranchTransportAdjacency &candidate,
         const SourceEdgeTopologyKey &key) {
        return candidate.sourceEdge < key;
      });
  return found != transports.end() && found->sourceEdge == edge ? &*found
                                                                 : nullptr;
}

std::optional<FieldDirectedBranchTransport> directed_branch_transport(
    const FieldBranchTransportAdjacency &adjacency,
    const SourceFaceTopologyKey &fromFace,
    const SourceFaceTopologyKey &toFace) {
  if (adjacency.firstFace == fromFace && adjacency.secondFace == toFace) {
    return FieldDirectedBranchTransport{adjacency.forward,
                                        adjacency.forwardLift,
                                        adjacency.effort};
  }
  if (adjacency.secondFace == fromFace && adjacency.firstFace == toFace) {
    return FieldDirectedBranchTransport{adjacency.reverse,
                                        -adjacency.forwardLift,
                                        -adjacency.effort};
  }
  return std::nullopt;
}

std::optional<std::vector<FieldBranchTransportAdjacency>>
build_branch_transports(
    const std::vector<FieldTransportAdjacency> &adjacencies,
    const std::vector<int> &rawGaugeByRow) {
  std::vector<FieldBranchTransportAdjacency> result;
  result.reserve(adjacencies.size());
  for (const FieldTransportAdjacency &adjacency : adjacencies) {
    if (adjacency.firstFace.index() >= rawGaugeByRow.size() ||
        adjacency.secondFace.index() >= rawGaugeByRow.size()) {
      return std::nullopt;
    }
    const int canonicalLift =
        adjacency.forwardLift + rawGaugeByRow[adjacency.firstFace.index()] -
        rawGaugeByRow[adjacency.secondFace.index()];
    const bool canonicalForward =
        adjacency.firstFaceTopology < adjacency.secondFaceTopology;
    const int orientedLift = canonicalForward ? canonicalLift : -canonicalLift;
    const QuarterTurn forward = QuarterTurn::from_integer(orientedLift);
    // CP2b publishes Z4 branch transport.  Raw/gauge integer lifts that differ
    // by 4*k are the same semantic transport, so the nested branch authority
    // stores the unique canonical representative rather than leaking the raw
    // gauge representative into equality and semantic hashing.
    const int forwardLift = static_cast<int>(forward.value());
    result.push_back(FieldBranchTransportAdjacency{
        adjacency.sourceEdge,
        canonicalForward ? adjacency.firstFaceTopology
                         : adjacency.secondFaceTopology,
        canonicalForward ? adjacency.secondFaceTopology
                         : adjacency.firstFaceTopology,
        forward, forward.inverse(), forwardLift,
        canonicalForward ? adjacency.effort : -adjacency.effort});
  }
  std::sort(result.begin(), result.end(),
            [](const FieldBranchTransportAdjacency &a,
               const FieldBranchTransportAdjacency &b) {
              return a.sourceEdge < b.sourceEdge;
            });
  return result;
}

struct IncidentFanFace {
  SourceFaceId row;
  SourceFaceTopologyKey topology;
  SourceVertexId nextVertex;
  SourceVertexId previousVertex;
};

std::optional<std::vector<IncidentFanFace>> ordered_incident_fan(
    const TriMesh &sourceMesh, const std::vector<SourceFaceTopologyKey> &rowTopology,
    const SourceVertexId vertex) {
  std::vector<IncidentFanFace> incident;
  for (int face = 0; face < sourceMesh.F.rows(); ++face) {
    int corner = -1;
    for (int c = 0; c < 3; ++c) {
      if (sourceMesh.F(face, c) == static_cast<int>(vertex.index())) {
        corner = c;
        break;
      }
    }
    if (corner < 0) continue;
    const auto next = SourceVertexId::from_index(
        sourceMesh.F(face, (corner + 1) % 3),
        static_cast<std::size_t>(sourceMesh.V.rows()));
    const auto previous = SourceVertexId::from_index(
        sourceMesh.F(face, (corner + 2) % 3),
        static_cast<std::size_t>(sourceMesh.V.rows()));
    if (!next || !previous) return std::nullopt;
    const SourceFaceId row = make_id<SourceFaceId>(static_cast<std::size_t>(face));
    incident.push_back(
        IncidentFanFace{row, rowTopology[row.index()], next.value(),
                        previous.value()});
  }
  if (incident.size() < 3U) return std::nullopt;
  auto start = std::min_element(
      incident.begin(), incident.end(),
      [](const IncidentFanFace &a, const IncidentFanFace &b) {
        return a.topology < b.topology;
      });
  if (start == incident.end()) return std::nullopt;

  std::vector<IncidentFanFace> ordered;
  ordered.reserve(incident.size());
  IncidentFanFace current = *start;
  std::set<SourceFaceTopologyKey> used;
  for (std::size_t step = 0; step < incident.size(); ++step) {
    if (!used.insert(current.topology).second) return std::nullopt;
    ordered.push_back(current);
    const auto next = std::find_if(
        incident.begin(), incident.end(), [&](const IncidentFanFace &candidate) {
          return candidate.previousVertex == current.nextVertex;
        });
    if (next == incident.end()) return std::nullopt;
    current = *next;
  }
  if (current.topology != ordered.front().topology || used.size() != incident.size()) {
    return std::nullopt;
  }
  return ordered;
}

bool direction_in_incident_vertex_sector(
    const IncidentFanFace &face, const SourceVertexId vertex,
    const FieldBranchDirection &direction) {
  if (!direction.is_barycentric()) return false;
  const auto &vertices = face.topology.vertices();
  std::optional<std::size_t> vertexIndex;
  std::optional<std::size_t> nextIndex;
  std::optional<std::size_t> previousIndex;
  for (std::size_t index = 0U; index < vertices.size(); ++index) {
    if (vertices[index] == vertex) vertexIndex = index;
    if (vertices[index] == face.nextVertex) nextIndex = index;
    if (vertices[index] == face.previousVertex) previousIndex = index;
  }
  if (!vertexIndex.has_value() || !nextIndex.has_value() ||
      !previousIndex.has_value()) {
    return false;
  }
  const FieldExactRational zero = FieldExactRational::from_integer(0);
  // Exact half-open fan partition: include the next-vertex ray and exclude the
  // previous-vertex ray. Index by vertex identity because topology is canonical
  // and need not preserve the source mesh row's corner order.
  return direction[*nextIndex] > zero && direction[*previousIndex] >= zero;
}

std::optional<double> counter_clockwise_sector_angle(
    const TriMesh &sourceMesh, const IncidentFanFace &face,
    const SourceVertexId vertex, const Eigen::Vector3d &direction) {
  const Eigen::Vector3d origin =
      sourceMesh.V.row(static_cast<int>(vertex.index())).transpose();
  Eigen::Vector3d start =
      sourceMesh.V.row(static_cast<int>(face.nextVertex.index())).transpose() -
      origin;
  Eigen::Vector3d end =
      sourceMesh.V.row(static_cast<int>(face.previousVertex.index())).transpose() -
      origin;
  Eigen::Vector3d normal = start.cross(end);
  const double normalNorm = normal.norm();
  const double startNorm = start.norm();
  const double endNorm = end.norm();
  if (!std::isfinite(normalNorm) || !std::isfinite(startNorm) ||
      !std::isfinite(endNorm) || normalNorm <= kBranchTopologyTolerance ||
      startNorm <= kBranchTopologyTolerance ||
      endNorm <= kBranchTopologyTolerance) {
    return std::nullopt;
  }
  normal /= normalNorm;
  start /= startNorm;
  end /= endNorm;
  const auto tangent = normalized_projected(direction, normal);
  if (!tangent.has_value()) return std::nullopt;
  const double sector = positive_oriented_angle(start, end, normal);
  const double angle = positive_oriented_angle(start, *tangent, normal);
  if (!std::isfinite(sector) || !std::isfinite(angle) ||
      sector <= kBranchTopologyTolerance ||
      angle > sector + kBranchTopologyTolerance) {
    return std::nullopt;
  }
  return angle;
}

const FieldBranchBoundaryPairing *find_pairing(
    const FieldFaceBranchFrame &frame, const FieldBranch branch) {
  const auto found = std::find_if(
      frame.branches.begin(), frame.branches.end(),
      [&](const FieldBranchBoundaryPairing &candidate) {
        return candidate.branch == branch;
      });
  return found == frame.branches.end() ? nullptr : &*found;
}

bool contains_edge(const std::vector<SourceEdgeTopologyKey> &edges,
                   const SourceEdgeTopologyKey &edge) {
  return std::find(edges.begin(), edges.end(), edge) != edges.end();
}

std::optional<std::vector<FieldSingularityPortAttachment>>
build_singularity_attachments(
    const TriMesh &sourceMesh,
    const std::vector<SourceFaceTopologyKey> &rowTopology,
    const std::vector<BuiltFaceBranchFrame> &builtFramesByRow,
    const std::vector<FieldBranchTransportAdjacency> &branchTransports,
    const std::vector<FieldSingularityFact> &singularities,
    FieldAtlasBuildError &error) {
  std::vector<FieldSingularityPortAttachment> result;
  for (const FieldSingularityFact &singularity : singularities) {
    const int expected = 4 - singularity.indexNumerator;
    if (expected < 3 || expected > 6 ||
        !singularity.topologyRegion.has_value()) {
      error = FieldAtlasBuildError{
          FieldAtlasBuildErrorCode::InvalidSingularityMetadata, std::nullopt,
          std::nullopt, singularity.sourceVertex, singularity.topologyRegion};
      return std::nullopt;
    }
    const auto fan = ordered_incident_fan(sourceMesh, rowTopology,
                                          singularity.sourceVertex);
    if (!fan.has_value()) {
      error = FieldAtlasBuildError{
          FieldAtlasBuildErrorCode::InvalidSingularityIncidentFan,
          std::nullopt, std::nullopt, singularity.sourceVertex,
          singularity.topologyRegion};
      return std::nullopt;
    }

    std::vector<FieldSingularityPortAttachment> incidences;
    std::vector<std::size_t> incidenceFanIndex;
    std::vector<std::vector<std::size_t>> incidenceByFan(fan->size());
    for (std::size_t fanIndex = 0; fanIndex < fan->size(); ++fanIndex) {
      const IncidentFanFace &face = (*fan)[fanIndex];
      if (face.row.index() >= builtFramesByRow.size()) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::InvalidSingularityFrameRow,
            std::nullopt, face.row, singularity.sourceVertex,
            singularity.topologyRegion};
        return std::nullopt;
      }
      const BuiltFaceBranchFrame &built = builtFramesByRow[face.row.index()];
      if (built.published.topologyRegion != *singularity.topologyRegion ||
          built.published.sourceComponent != singularity.sourceComponent) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::InvalidSingularityFrameOwnership,
            std::nullopt, face.row, singularity.sourceVertex,
            singularity.topologyRegion};
        return std::nullopt;
      }
      const auto opposite = typed_edge(face.nextVertex, face.previousVertex);
      if (!opposite.has_value()) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::InvalidSingularityOppositeEdge,
            std::nullopt, face.row, singularity.sourceVertex,
            singularity.topologyRegion};
        return std::nullopt;
      }

      for (const FieldBranchBoundaryPairing &pairing :
           built.published.branches) {
        const std::size_t branchIndex = pairing.branch.value();
        if (branchIndex >= built.canonicalDirections.size()) {
          error = FieldAtlasBuildError{
              FieldAtlasBuildErrorCode::InvalidSingularityBranchIndex,
              std::nullopt, face.row, singularity.sourceVertex,
              singularity.topologyRegion};
          return std::nullopt;
        }
        if (!direction_in_vertex_sector(sourceMesh, face.row,
                                        singularity.sourceVertex,
                                        pairing.direction)) {
          continue;
        }
        if (!contains_edge(pairing.outgoingCarriers, *opposite)) {
          error = FieldAtlasBuildError{
              FieldAtlasBuildErrorCode::InvalidSingularityOutgoingCarrier,
              *opposite, face.row, singularity.sourceVertex,
              singularity.topologyRegion};
          return std::nullopt;
        }
        const std::size_t incidenceIndex = incidences.size();
        incidences.push_back(FieldSingularityPortAttachment{
            singularity.id, singularity.sourceVertex, 0, face.topology,
            pairing.branch, *opposite, *singularity.topologyRegion,
            singularity.sourceComponent});
        incidenceFanIndex.push_back(fanIndex);
        incidenceByFan[fanIndex].push_back(incidenceIndex);
      }
    }
    if (incidences.empty()) {
      error = FieldAtlasBuildError{
          FieldAtlasBuildErrorCode::EmptySingularityIncidence, std::nullopt,
          std::nullopt, singularity.sourceVertex,
          singularity.topologyRegion};
      return std::nullopt;
    }

    std::vector<std::size_t> parent(incidences.size());
    std::iota(parent.begin(), parent.end(), 0U);
    const auto root = [&parent](std::size_t value) {
      while (parent[value] != value) {
        parent[value] = parent[parent[value]];
        value = parent[value];
      }
      return value;
    };
    const auto unite = [&parent, &root](const std::size_t first,
                                        const std::size_t second) {
      const std::size_t firstRoot = root(first);
      const std::size_t secondRoot = root(second);
      if (firstRoot == secondRoot) return;
      const std::size_t canonical = std::min(firstRoot, secondRoot);
      const std::size_t other = std::max(firstRoot, secondRoot);
      parent[other] = canonical;
    };

    std::vector<std::tuple<std::size_t, std::size_t, SourceEdgeTopologyKey, int>>
        partitionAdjacencies;
    for (std::size_t fanIndex = 0; fanIndex < fan->size(); ++fanIndex) {
      const std::size_t nextIndex = (fanIndex + 1U) % fan->size();
      const IncidentFanFace &face = (*fan)[fanIndex];
      const IncidentFanFace &nextFace = (*fan)[nextIndex];
      const auto radial =
          typed_edge(singularity.sourceVertex, face.nextVertex);
      if (!radial.has_value()) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::InvalidSingularityRadialEdge,
            std::nullopt, face.row, singularity.sourceVertex,
            singularity.topologyRegion};
        return std::nullopt;
      }
      const FieldBranchTransportAdjacency *transport =
          find_branch_transport_in(branchTransports, *radial);
      if (transport == nullptr) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::MissingSingularityBranchTransport,
            *radial, face.row, singularity.sourceVertex,
            singularity.topologyRegion};
        return std::nullopt;
      }
      const auto directed = directed_branch_transport(
          *transport, face.topology, nextFace.topology);
      if (!directed.has_value()) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::InvalidSingularityDirectedTransport,
            *radial, face.row, singularity.sourceVertex,
            singularity.topologyRegion};
        return std::nullopt;
      }
      partitionAdjacencies.emplace_back(
          fanIndex, nextIndex, *radial, directed->signedLift);

      for (const std::size_t sourceIndex : incidenceByFan[fanIndex]) {
        const FieldBranch targetBranch =
            incidences[sourceIndex].branch.rotated(
                directed->signedLift);
        for (const std::size_t targetIndex : incidenceByFan[nextIndex]) {
          if (incidences[targetIndex].branch == targetBranch) {
            unite(sourceIndex, targetIndex);
          }
        }
      }
    }

    std::map<std::size_t, std::vector<std::size_t>> classes;
    for (std::size_t index = 0; index < incidences.size(); ++index) {
      classes[root(index)].push_back(index);
    }

    std::vector<std::size_t> classByIncidence(incidences.size());
    std::size_t classOrdinal = 0;
    for (const auto &[unusedRoot, classIndices] : classes) {
      (void)unusedRoot;
      for (const std::size_t incidenceIndex : classIndices) {
        classByIncidence[incidenceIndex] = classOrdinal;
      }
      ++classOrdinal;
    }
    std::clog << "FieldTransportAtlas.partition summary singularity="
              << singularity.id.index()
              << " sourceVertex=" << singularity.sourceVertex.index()
              << " topologyRegion=" << singularity.topologyRegion->index()
              << " incidences=" << incidences.size()
              << " classes=" << classes.size()
              << " expectedClasses=" << expected << '\n';
    for (std::size_t index = 0; index < incidences.size(); ++index) {
      const FieldSingularityPortAttachment &incidence = incidences[index];
      const auto &faceVertices = incidence.startFace.vertices();
      std::clog << "FieldTransportAtlas.partition incidence singularity="
                << singularity.id.index() << " index=" << index
                << " fanIndex=" << incidenceFanIndex[index]
                << " startFace=(" << faceVertices[0].index() << ','
                << faceVertices[1].index() << ','
                << faceVertices[2].index() << ')'
                << " branch=" << static_cast<int>(incidence.branch.value())
                << " firstOutgoingCarrier=("
                << incidence.firstOutgoingCarrier.first().index() << ','
                << incidence.firstOutgoingCarrier.second().index() << ')'
                << " class=" << classByIncidence[index] << '\n';
    }
    for (const auto &[fanIndex, nextFanIndex, sourceEdge, signedLift] :
         partitionAdjacencies) {
      std::clog << "FieldTransportAtlas.partition adjacency singularity="
                << singularity.id.index() << " fanIndex=" << fanIndex
                << " nextFanIndex=" << nextFanIndex << " sourceEdge=("
                << sourceEdge.first().index() << ','
                << sourceEdge.second().index() << ')'
                << " signedLift=" << signedLift << '\n';
    }

    if (static_cast<int>(classes.size()) != expected) {
      error = FieldAtlasBuildError{
          FieldAtlasBuildErrorCode::SingularityPortClassCountMismatch,
          std::nullopt, std::nullopt, singularity.sourceVertex,
          singularity.topologyRegion};
      return std::nullopt;
    }

    const auto topologyKey = [&incidences](const std::size_t index) {
      return std::tie(incidences[index].startFace, incidences[index].branch,
                      incidences[index].firstOutgoingCarrier);
    };
    std::vector<FieldSingularityPortAttachment> representatives;
    representatives.reserve(classes.size());
    for (auto &[unusedRoot, classIndices] : classes) {
      (void)unusedRoot;
      std::sort(classIndices.begin(), classIndices.end(),
                [&](const std::size_t first, const std::size_t second) {
                  return topologyKey(first) < topologyKey(second);
                });
      for (std::size_t index = 1; index < classIndices.size(); ++index) {
        if (topologyKey(classIndices[index - 1U]) ==
            topologyKey(classIndices[index])) {
          const auto sourceFace = row_for_topology(
              rowTopology, incidences[classIndices[index]].startFace);
          error = FieldAtlasBuildError{
              FieldAtlasBuildErrorCode::DuplicateSingularityClassRepresentative,
              incidences[classIndices[index]].firstOutgoingCarrier, sourceFace,
              singularity.sourceVertex, singularity.topologyRegion};
          return std::nullopt;
        }
      }
      representatives.push_back(incidences[classIndices.front()]);
    }

    struct OrderedRepresentative {
      FieldSingularityPortAttachment attachment;
      std::size_t counterClockwiseFanSlot = 0U;
      double sectorAngle = 0.0;
    };
    std::vector<OrderedRepresentative> orderedRepresentatives;
    orderedRepresentatives.reserve(representatives.size());
    for (const FieldSingularityPortAttachment &representative :
         representatives) {
      const auto fanIt = std::find_if(
          fan->begin(), fan->end(), [&](const IncidentFanFace &face) {
            return face.topology == representative.startFace;
          });
      if (fanIt == fan->end() || fanIt->row.index() >= builtFramesByRow.size() ||
          representative.branch.value() >=
              builtFramesByRow[fanIt->row.index()].canonicalDirections.size()) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt,
            fanIt == fan->end() ? std::optional<SourceFaceId>{}
                                : std::optional<SourceFaceId>{fanIt->row},
            singularity.sourceVertex, singularity.topologyRegion};
        return std::nullopt;
      }
      const std::size_t clockwiseFanSlot =
          static_cast<std::size_t>(std::distance(fan->begin(), fanIt));
      const std::size_t counterClockwiseFanSlot =
          clockwiseFanSlot == 0U ? 0U : fan->size() - clockwiseFanSlot;
      const auto angle = counter_clockwise_sector_angle(
          sourceMesh, *fanIt, singularity.sourceVertex,
          builtFramesByRow[fanIt->row.index()]
              .canonicalDirections[representative.branch.value()]);
      if (!angle.has_value()) {
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt,
            fanIt->row, singularity.sourceVertex, singularity.topologyRegion};
        return std::nullopt;
      }
      orderedRepresentatives.push_back(OrderedRepresentative{
          representative, counterClockwiseFanSlot, *angle});
    }
    std::sort(orderedRepresentatives.begin(), orderedRepresentatives.end(),
              [](const OrderedRepresentative &first,
                 const OrderedRepresentative &second) {
                if (first.counterClockwiseFanSlot !=
                    second.counterClockwiseFanSlot) {
                  return first.counterClockwiseFanSlot <
                         second.counterClockwiseFanSlot;
                }
                return first.sectorAngle < second.sectorAngle;
              });
    for (std::size_t index = 1U; index < orderedRepresentatives.size(); ++index) {
      const auto &previous = orderedRepresentatives[index - 1U];
      const auto &current = orderedRepresentatives[index];
      if (previous.counterClockwiseFanSlot == current.counterClockwiseFanSlot &&
          std::abs(previous.sectorAngle - current.sectorAngle) <=
              kBranchTopologyTolerance) {
        const auto sourceFace =
            row_for_topology(rowTopology, current.attachment.startFace);
        error = FieldAtlasBuildError{
            FieldAtlasBuildErrorCode::AmbiguousBranchTopology, std::nullopt,
            sourceFace, singularity.sourceVertex, singularity.topologyRegion};
        return std::nullopt;
      }
    }
    for (std::size_t slot = 0; slot < orderedRepresentatives.size(); ++slot) {
      orderedRepresentatives[slot].attachment.localSlot =
          static_cast<int>(slot);
      result.push_back(orderedRepresentatives[slot].attachment);
    }
  }
  std::sort(result.begin(), result.end(),
            [](const FieldSingularityPortAttachment &a,
               const FieldSingularityPortAttachment &b) {
              return std::tie(a.sourceVertex, a.singularity, a.localSlot,
                              a.startFace, a.firstOutgoingCarrier) <
                     std::tie(b.sourceVertex, b.singularity, b.localSlot,
                              b.startFace, b.firstOutgoingCarrier);
            });
  return result;
}

FieldTransportAtlasBuildResult fail(
    const FieldAtlasBuildErrorCode code,
    std::optional<SourceEdgeTopologyKey> sourceEdge = std::nullopt,
    std::optional<SourceFaceId> sourceFace = std::nullopt,
    std::optional<SourceVertexId> sourceVertex = std::nullopt,
    std::optional<TopologyRegionId> topologyRegion = std::nullopt,
    std::optional<FieldBranch> branch = std::nullopt) {
  return FieldTransportAtlasBuildResult(FieldAtlasBuildError{
      code, std::move(sourceEdge), sourceFace, sourceVertex, topologyRegion,
      branch});
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
  explicit LocalRegionMesh(TopologyRegionId topologyRegion)
      : diagnostics(topologyRegion) {}

  TriMesh mesh;
  std::vector<int> globalFaceByLocal;
  std::vector<int> globalVertexByLocal;
  std::set<int> barrierVertices;
  FieldTransportRegionDiagnostics diagnostics;
  bool uncutAuthorityMatches = false;
  bool cutIdentityValid = false;
};

std::optional<LocalRegionMesh> make_local_region_mesh(
    const TriMesh &sourceMesh,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const geometry::SurfaceTopologyRegion &region,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges) {
  const std::vector<SourceFaceId> rows =
      sourceAuthority.rows_for_region(region.id());
  if (rows.empty()) return std::nullopt;

  LocalRegionMesh result(region.id());
  result.diagnostics.hardFeatureEdgeCount = hardFeatureEdges.size();
  result.globalFaceByLocal.reserve(rows.size());
  std::set<int> regionFaces;
  std::set<int> globalVertices;
  for (const SourceFaceId row : rows) {
    const int face = static_cast<int>(row.index());
    if (face < 0 || face >= sourceMesh.F.rows()) return std::nullopt;
    result.globalFaceByLocal.push_back(face);
    regionFaces.insert(face);
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = sourceMesh.F(face, corner);
      if (vertex < 0 || vertex >= sourceMesh.V.rows()) return std::nullopt;
      globalVertices.insert(vertex);
    }
  }

  const std::vector<int> uncutGlobalVertices(globalVertices.begin(),
                                               globalVertices.end());
  std::map<int, int> uncutLocalVertex;
  for (int local = 0; local < static_cast<int>(uncutGlobalVertices.size());
       ++local) {
    uncutLocalVertex.emplace(
        uncutGlobalVertices[static_cast<std::size_t>(local)], local);
  }
  Eigen::MatrixXd uncutVertices(uncutGlobalVertices.size(), 3);
  for (int local = 0; local < uncutVertices.rows(); ++local) {
    uncutVertices.row(local) = sourceMesh.V.row(
        uncutGlobalVertices[static_cast<std::size_t>(local)]);
  }
  Eigen::MatrixXi uncutFaces(result.globalFaceByLocal.size(), 3);
  for (int localFace = 0; localFace < uncutFaces.rows(); ++localFace) {
    const int globalFace =
        result.globalFaceByLocal[static_cast<std::size_t>(localFace)];
    for (int corner = 0; corner < 3; ++corner) {
      const auto found = uncutLocalVertex.find(sourceMesh.F(globalFace, corner));
      if (found == uncutLocalVertex.end()) return std::nullopt;
      uncutFaces(localFace, corner) = found->second;
    }
  }
  TriMesh uncutMesh;
  try {
    uncutMesh.set_mesh(uncutVertices, uncutFaces);
  } catch (const std::exception &) {
    return std::nullopt;
  }
  result.diagnostics.uncutEulerCharacteristic = static_cast<int>(
      uncutMesh.V.rows() - uncutMesh.EV.rows() + uncutMesh.F.rows());
  result.diagnostics.uncutBoundaryLoopCount =
      static_cast<int>(uncutMesh.boundaryLoops.size());
  result.uncutAuthorityMatches =
      result.diagnostics.uncutEulerCharacteristic ==
          region.euler_characteristic() &&
      result.diagnostics.uncutBoundaryLoopCount == region.boundary_loop_count();

  std::map<SourceEdgeTopologyKey, int> sourceEdgeRow;
  for (int edge = 0; edge < sourceMesh.EV.rows(); ++edge) {
    const auto key = SourceEdgeTopologyKey::from_indices(
        sourceMesh.EV(edge, 0), sourceMesh.EV(edge, 1),
        static_cast<std::size_t>(sourceMesh.V.rows()));
    if (!key) return std::nullopt;
    sourceEdgeRow.emplace(key.value(), edge);
  }

  std::set<SourceEdgeTopologyKey> barrierEdges;
  for (const SourceEdgeTopologyKey &edge : hardFeatureEdges) {
    const auto found = sourceEdgeRow.find(edge);
    if (found == sourceEdgeRow.end()) return std::nullopt;
    const int sourceEdge = found->second;
    const int firstFace = sourceMesh.EF(sourceEdge, 0);
    const int secondFace = sourceMesh.EF(sourceEdge, 1);
    if (firstFace >= 0 && secondFace >= 0 &&
        regionFaces.count(firstFace) != 0U &&
        regionFaces.count(secondFace) != 0U) {
      barrierEdges.insert(edge);
      result.barrierVertices.insert(static_cast<int>(edge.first().index()));
      result.barrierVertices.insert(static_cast<int>(edge.second().index()));
    }
  }
  result.diagnostics.barrierEdges.assign(barrierEdges.begin(), barrierEdges.end());
  result.diagnostics.barrierVertexCount = result.barrierVertices.size();
  result.diagnostics.barrierEdgeCount = barrierEdges.size();
  result.diagnostics.barrierEulerCharacteristic =
      static_cast<int>(result.barrierVertices.size()) -
      static_cast<int>(barrierEdges.size());

  std::set<int> uncutBoundaryGlobalVertices;
  std::set<SourceEdgeTopologyKey> uncutBoundaryEdges;
  for (int localVertex = 0; localVertex < uncutMesh.V.rows(); ++localVertex) {
    if (uncutMesh.isBoundaryVertex(localVertex) != 0) {
      uncutBoundaryGlobalVertices.insert(
          uncutGlobalVertices[static_cast<std::size_t>(localVertex)]);
    }
  }
  for (int edge = 0; edge < uncutMesh.EV.rows(); ++edge) {
    if (uncutMesh.EF(edge, 1) >= 0) continue;
    const int first = uncutGlobalVertices[static_cast<std::size_t>(
        uncutMesh.EV(edge, 0))];
    const int second = uncutGlobalVertices[static_cast<std::size_t>(
        uncutMesh.EV(edge, 1))];
    const auto key = SourceEdgeTopologyKey::from_indices(
        first, second, static_cast<std::size_t>(sourceMesh.V.rows()));
    if (!key) return std::nullopt;
    uncutBoundaryEdges.insert(key.value());
  }
  for (const int vertex : result.barrierVertices) {
    if (uncutBoundaryGlobalVertices.count(vertex) != 0U) {
      ++result.diagnostics.barrierRegionBoundaryVertexCount;
    }
  }

  std::map<int, std::set<int>> barrierAdjacency;
  for (const SourceEdgeTopologyKey &edge : barrierEdges) {
    const int first = static_cast<int>(edge.first().index());
    const int second = static_cast<int>(edge.second().index());
    barrierAdjacency[first].insert(second);
    barrierAdjacency[second].insert(first);
  }
  std::set<int> unseenBarrierVertices = result.barrierVertices;
  while (!unseenBarrierVertices.empty()) {
    const int seed = *unseenBarrierVertices.begin();
    std::vector<int> stack{seed};
    std::set<int> componentVertices;
    unseenBarrierVertices.erase(seed);
    while (!stack.empty()) {
      const int vertex = stack.back();
      stack.pop_back();
      componentVertices.insert(vertex);
      const auto adjacency = barrierAdjacency.find(vertex);
      if (adjacency == barrierAdjacency.end()) continue;
      for (const int neighbor : adjacency->second) {
        if (unseenBarrierVertices.erase(neighbor) != 0U) {
          stack.push_back(neighbor);
        }
      }
    }
    std::size_t degreeSum = 0U;
    FieldBarrierComponentDiagnostics component;
    component.vertexCount = componentVertices.size();
    for (const int vertex : componentVertices) {
      const std::size_t degree = barrierAdjacency[vertex].size();
      degreeSum += degree;
      const SourceVertexId typed = make_id<SourceVertexId>(
          static_cast<std::size_t>(vertex));
      if (degree == 1U) component.tipVertices.push_back(typed);
      if (degree >= 3U) component.branchVertices.push_back(typed);
      if (uncutBoundaryGlobalVertices.count(vertex) != 0U) {
        ++component.regionBoundaryVertexCount;
      }
    }
    component.edgeCount = degreeSum / 2U;
    component.eulerCharacteristic = static_cast<int>(component.vertexCount) -
                                    static_cast<int>(component.edgeCount);
    component.tree = component.vertexCount == component.edgeCount + 1U;
    component.containsCycle = component.edgeCount >= component.vertexCount;
    result.diagnostics.barrierComponents.push_back(std::move(component));
  }
  result.diagnostics.barrierComponentCount =
      result.diagnostics.barrierComponents.size();

  std::map<std::pair<int, int>, int> localCopyByVertexFace;
  for (const int globalVertex : globalVertices) {
    std::vector<int> starFaces;
    for (const int globalFace : result.globalFaceByLocal) {
      for (int corner = 0; corner < 3; ++corner) {
        if (sourceMesh.F(globalFace, corner) == globalVertex) {
          starFaces.push_back(globalFace);
          break;
        }
      }
    }
    if (starFaces.empty()) return std::nullopt;

    std::map<int, std::set<int>> starAdjacency;
    for (const int face : starFaces) starAdjacency[face];
    for (int edge = 0; edge < sourceMesh.EV.rows(); ++edge) {
      if (sourceMesh.EV(edge, 0) != globalVertex &&
          sourceMesh.EV(edge, 1) != globalVertex) {
        continue;
      }
      const int firstFace = sourceMesh.EF(edge, 0);
      const int secondFace = sourceMesh.EF(edge, 1);
      if (firstFace < 0 || secondFace < 0 ||
          regionFaces.count(firstFace) == 0U ||
          regionFaces.count(secondFace) == 0U) {
        continue;
      }
      const auto key = SourceEdgeTopologyKey::from_indices(
          sourceMesh.EV(edge, 0), sourceMesh.EV(edge, 1),
          static_cast<std::size_t>(sourceMesh.V.rows()));
      if (!key) return std::nullopt;
      if (barrierEdges.count(key.value()) != 0U) continue;
      starAdjacency[firstFace].insert(secondFace);
      starAdjacency[secondFace].insert(firstFace);
    }

    std::set<int> unseen(starFaces.begin(), starFaces.end());
    std::vector<std::vector<int>> components;
    while (!unseen.empty()) {
      const int seed = *unseen.begin();
      unseen.erase(seed);
      std::vector<int> stack{seed};
      std::vector<int> component;
      while (!stack.empty()) {
        const int face = stack.back();
        stack.pop_back();
        component.push_back(face);
        for (const int neighbor : starAdjacency[face]) {
          if (unseen.erase(neighbor) != 0U) stack.push_back(neighbor);
        }
      }
      std::sort(component.begin(), component.end(), [&](const int first,
                                                        const int second) {
        const SourceFaceId firstId = make_id<SourceFaceId>(
            static_cast<std::size_t>(first));
        const SourceFaceId secondId = make_id<SourceFaceId>(
            static_cast<std::size_t>(second));
        return sourceAuthority.topology_for_row(firstId) <
               sourceAuthority.topology_for_row(secondId);
      });
      components.push_back(std::move(component));
    }
    std::sort(components.begin(), components.end(), [&](const auto &first,
                                                        const auto &second) {
      const SourceFaceId firstId = make_id<SourceFaceId>(
          static_cast<std::size_t>(first.front()));
      const SourceFaceId secondId = make_id<SourceFaceId>(
          static_cast<std::size_t>(second.front()));
      return sourceAuthority.topology_for_row(firstId) <
             sourceAuthority.topology_for_row(secondId);
    });
    for (const auto &component : components) {
      const int localVertex =
          static_cast<int>(result.globalVertexByLocal.size());
      result.globalVertexByLocal.push_back(globalVertex);
      for (const int face : component) {
        localCopyByVertexFace.emplace(std::make_pair(globalVertex, face),
                                      localVertex);
      }
    }
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
      const int globalVertex = sourceMesh.F(globalFace, corner);
      const auto found =
          localCopyByVertexFace.find(std::make_pair(globalVertex, globalFace));
      if (found == localCopyByVertexFace.end()) return std::nullopt;
      faces(localFace, corner) = found->second;
    }
  }

  try {
    result.mesh.set_mesh(vertices, faces);
  } catch (const std::exception &) {
    return std::nullopt;
  }
  result.diagnostics.cutEulerCharacteristic = static_cast<int>(
      result.mesh.V.rows() - result.mesh.EV.rows() + result.mesh.F.rows());
  result.diagnostics.cutBoundaryLoopCount =
      static_cast<int>(result.mesh.boundaryLoops.size());
  result.diagnostics.newSlitBoundaryLoopCount =
      result.diagnostics.cutBoundaryLoopCount -
      result.diagnostics.uncutBoundaryLoopCount;

  std::map<SourceEdgeTopologyKey, std::size_t> cutBoundaryMultiplicity;
  for (int edge = 0; edge < result.mesh.EV.rows(); ++edge) {
    if (result.mesh.EF(edge, 1) >= 0) continue;
    const int first = result.globalVertexByLocal[static_cast<std::size_t>(
        result.mesh.EV(edge, 0))];
    const int second = result.globalVertexByLocal[static_cast<std::size_t>(
        result.mesh.EV(edge, 1))];
    const auto key = SourceEdgeTopologyKey::from_indices(
        first, second, static_cast<std::size_t>(sourceMesh.V.rows()));
    if (!key) return std::nullopt;
    ++cutBoundaryMultiplicity[key.value()];
  }
  bool boundaryRealizationValid = true;
  for (const auto &[edge, count] : cutBoundaryMultiplicity) {
    const std::size_t expected = barrierEdges.count(edge) != 0U
                                     ? 2U
                                     : (uncutBoundaryEdges.count(edge) != 0U
                                            ? 1U
                                            : 0U);
    if (count != expected) boundaryRealizationValid = false;
  }
  for (const SourceEdgeTopologyKey &edge : barrierEdges) {
    if (cutBoundaryMultiplicity[edge] != 2U) boundaryRealizationValid = false;
  }
  for (const SourceEdgeTopologyKey &edge : uncutBoundaryEdges) {
    if (cutBoundaryMultiplicity[edge] != 1U) boundaryRealizationValid = false;
  }

  const int expectedCutEuler =
      region.euler_characteristic() -
      result.diagnostics.barrierEulerCharacteristic +
      static_cast<int>(result.diagnostics.barrierRegionBoundaryVertexCount);
  const int genusNumerator =
      2 - result.diagnostics.cutBoundaryLoopCount -
      result.diagnostics.cutEulerCharacteristic;
  result.cutIdentityValid =
      result.uncutAuthorityMatches &&
      result.diagnostics.cutEulerCharacteristic == expectedCutEuler &&
      result.diagnostics.newSlitBoundaryLoopCount >= 0 &&
      genusNumerator >= 0 && genusNumerator % 2 == 0 &&
      boundaryRealizationValid;
  return result;
}

std::vector<FieldAtlasRegionCycleBasisDiagnostics>
collect_cycle_basis_diagnostics(
    const TriMesh &sourceMesh,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges) {
  std::vector<FieldAtlasRegionCycleBasisDiagnostics> diagnostics;
  diagnostics.reserve(sourceAuthority.regions().size());
  for (const auto &region : sourceAuthority.regions()) {
    FieldAtlasRegionCycleBasisDiagnostics row{region.id()};
    const auto local = make_local_region_mesh(sourceMesh, sourceAuthority, region, hardFeatureEdges);
    if (!local.has_value()) {
      diagnostics.push_back(std::move(row));
      continue;
    }

    row.localMeshAvailable = true;
    row.vertexCount = static_cast<std::size_t>(local->mesh.V.rows());
    row.edgeCount = static_cast<std::size_t>(local->mesh.EV.rows());
    row.faceCount = static_cast<std::size_t>(local->mesh.F.rows());
    row.eulerCharacteristic = static_cast<int>(
        local->mesh.V.rows() - local->mesh.EV.rows() + local->mesh.F.rows());
    row.boundaryLoopCount = static_cast<int>(local->mesh.boundaryLoops.size());
    const int genusNumerator =
        2 - row.boundaryLoopCount - row.eulerCharacteristic;
    if (genusNumerator >= 0 && genusNumerator % 2 == 0) {
      row.genus = genusNumerator / 2;
    }
    for (int vertex = 0; vertex < local->mesh.V.rows(); ++vertex) {
      if (local->mesh.isBoundaryVertex(vertex) == 0) {
        ++row.interiorLocalVertexCount;
      }
    }
    if (row.genus >= 0) {
      row.expectedCycleCount =
          static_cast<int>(row.interiorLocalVertexCount) +
          row.boundaryLoopCount + 2 * row.genus;
    }

    PCFaceTangentBundle bundle;
    try {
      bundle.init(local->mesh);
      row.bundleInitialized = true;
      row.cycleRowCount = static_cast<std::size_t>(bundle.cycles.rows());
      row.cycleCurvatureCount = bundle.cycleCurvatures.size();
      row.innerAdjacencyCount =
          static_cast<std::size_t>(bundle.innerAdjacencies.size());
    } catch (const std::exception &) {
      row.bundleInitialized = false;
    }
    diagnostics.push_back(std::move(row));
  }
  return diagnostics;
}

FieldTransportAtlasBuildResult incomplete_cycle_basis_failure(
    const TriMesh &sourceMesh,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const IncompleteCycleBasisReason reason,
    std::optional<SourceEdgeTopologyKey> sourceEdge,
    const TopologyRegionId topologyRegion,
    const std::set<SourceEdgeTopologyKey> &hardFeatureEdges) {
  FieldAtlasBuildError error;
  error.code = FieldAtlasBuildErrorCode::IncompleteCycleBasis;
  error.sourceEdge = std::move(sourceEdge);
  error.topologyRegion = topologyRegion;
  error.incompleteCycleBasisReason = reason;
  error.regionCycleBasisDiagnostics =
      collect_cycle_basis_diagnostics(sourceMesh, sourceAuthority, hardFeatureEdges);
  for (const auto &region : sourceAuthority.regions()) {
    const auto local = make_local_region_mesh(
        sourceMesh, sourceAuthority, region, hardFeatureEdges);
    if (local.has_value()) {
      error.regionTransportDiagnostics.push_back(local->diagnostics);
    }
  }
  return FieldTransportAtlasBuildResult(std::move(error));
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

void consume_exact(std::uint64_t &hash,
                   const FieldExactRational &value) noexcept {
  const std::string numerator = value.numerator_string();
  const std::string denominator = value.denominator_string();
  consume_hash(hash, numerator.size());
  for (const unsigned char byte : numerator) consume_hash(hash, byte);
  consume_hash(hash, denominator.size());
  for (const unsigned char byte : denominator) consume_hash(hash, byte);
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

std::uint64_t branch_topology_digest(
    const std::vector<FieldFaceBranchFrame> &frames,
    const std::vector<FieldBranchTransportAdjacency> &transports,
    const std::vector<FieldSingularityPortAttachment> &attachments) {
  std::uint64_t hash = kFnvOffset;
  consume_hash(hash, frames.size());
  for (const FieldFaceBranchFrame &frame : frames) {
    consume_face_topology(hash, frame.sourceFace);
    consume_hash(hash, frame.branches.size());
    for (const FieldBranchBoundaryPairing &pairing : frame.branches) {
      consume_hash(hash, pairing.branch.value());
      for (const FieldExactRational &coordinate : pairing.direction.barycentric) {
        consume_exact(hash, coordinate);
      }
      consume_hash(hash, pairing.intervals.size());
      for (const FieldBranchBoundaryInterval &interval : pairing.intervals) {
        consume_hash(hash, interval.startVertex.index());
        consume_hash(hash, interval.endVertex.index());
        consume_hash(hash, interval.sourceEdge.first().index());
        consume_hash(hash, interval.sourceEdge.second().index());
        consume_hash(hash, static_cast<std::uint64_t>(interval.flow));
      }
      consume_hash(hash, pairing.incomingCarriers.size());
      for (const SourceEdgeTopologyKey &edge : pairing.incomingCarriers) {
        consume_hash(hash, edge.first().index());
        consume_hash(hash, edge.second().index());
      }
      consume_hash(hash, pairing.outgoingCarriers.size());
      for (const SourceEdgeTopologyKey &edge : pairing.outgoingCarriers) {
        consume_hash(hash, edge.first().index());
        consume_hash(hash, edge.second().index());
      }
    }
  }
  consume_hash(hash, transports.size());
  for (const FieldBranchTransportAdjacency &transport : transports) {
    consume_hash(hash, transport.sourceEdge.first().index());
    consume_hash(hash, transport.sourceEdge.second().index());
    consume_face_topology(hash, transport.firstFace);
    consume_face_topology(hash, transport.secondFace);
    consume_hash(hash, transport.forward.value());
    consume_hash(hash, transport.reverse.value());
    consume_signed(hash, transport.forwardLift);
  }
  consume_hash(hash, attachments.size());
  for (const FieldSingularityPortAttachment &attachment : attachments) {
    consume_hash(hash, attachment.sourceVertex.index());
    consume_signed(hash, attachment.localSlot);
    consume_face_topology(hash, attachment.startFace);
    consume_hash(hash, attachment.branch.value());
    consume_hash(hash, attachment.firstOutgoingCarrier.first().index());
    consume_hash(hash, attachment.firstOutgoingCarrier.second().index());
  }
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
    const std::vector<FieldQuadrangulabilityWitness> &witnesses,
    const std::uint64_t branchTopologyDigest) {
  std::uint64_t hash = kFnvOffset;
  consume_hash(hash, sourceDigest);
  consume_hash(hash, branchTopologyDigest);

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

bool direction_in_vertex_sector(const TriMesh &sourceMesh,
                                const SourceFaceId sourceFace,
                                const SourceVertexId vertex,
                                const FieldBranchDirection &direction) {
  if (sourceFace.index() >= static_cast<std::size_t>(sourceMesh.F.rows()) ||
      vertex.index() >= static_cast<std::size_t>(sourceMesh.V.rows())) {
    return false;
  }
  const int row = static_cast<int>(sourceFace.index());
  int corner = -1;
  for (int c = 0; c < 3; ++c) {
    if (sourceMesh.F(row, c) == static_cast<int>(vertex.index())) {
      corner = c;
      break;
    }
  }
  if (corner < 0) return false;
  const auto next = SourceVertexId::from_index(
      sourceMesh.F(row, (corner + 1) % 3),
      static_cast<std::size_t>(sourceMesh.V.rows()));
  const auto previous = SourceVertexId::from_index(
      sourceMesh.F(row, (corner + 2) % 3),
      static_cast<std::size_t>(sourceMesh.V.rows()));
  if (!next || !previous) return false;
  const auto topology = SourceFaceTopologyKey::make(std::array<SourceVertexId, 3>{
      vertex, next.value(), previous.value()});
  if (!topology) return false;
  return direction_in_incident_vertex_sector(
      IncidentFanFace{sourceFace, topology.value(), next.value(),
                      previous.value()},
      vertex, direction);
}

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
      crossField.primaryDirections.rows() != sourceMesh.F.rows() ||
      crossField.primaryDirections.cols() != 3 ||
      crossField.secondaryDirections.rows() != sourceMesh.F.rows() ||
      crossField.secondaryDirections.cols() != 3 ||
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

  std::vector<BuiltFaceBranchFrame> builtFramesByRow;
  builtFramesByRow.reserve(faceExtent);
  std::vector<int> rawGaugeByRow(faceExtent, 0);
  for (std::size_t row = 0; row < faceExtent; ++row) {
    const SourceFaceId face = make_id<SourceFaceId>(row);
    FieldAtlasBuildError branchError{
        FieldAtlasBuildErrorCode::InvalidBranchTopology, std::nullopt, face,
        std::nullopt, rowRegions[row]};
    const auto built = build_face_branch_frame(
        sourceMesh, face, rowTopology[row], rowRegions[row], rowComponents[row],
        crossField, branchError);
    if (!built.has_value()) {
      return fail(branchError.code, branchError.sourceEdge,
                  branchError.sourceFace, branchError.sourceVertex,
                  branchError.topologyRegion, branchError.branch);
    }
    rawGaugeByRow[row] = built->rawGauge;
    builtFramesByRow.push_back(*built);
  }
  std::vector<FieldFaceBranchFrame> branchFrames;
  branchFrames.reserve(builtFramesByRow.size());
  for (const BuiltFaceBranchFrame &built : builtFramesByRow) {
    branchFrames.push_back(built.published);
  }
  std::sort(branchFrames.begin(), branchFrames.end(),
            [](const FieldFaceBranchFrame &a,
               const FieldFaceBranchFrame &b) {
              return a.sourceFace < b.sourceFace;
            });

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

  const auto branchTransports =
      build_branch_transports(adjacencies, rawGaugeByRow);
  if (!branchTransports.has_value()) {
    return fail(FieldAtlasBuildErrorCode::InvalidBranchTopology);
  }

  std::map<int, int> rawSingularity;
  std::map<int, int> rawBoundarySingularity;
  for (Eigen::Index index = 0; index < crossField.singularCycles.size();
       ++index) {
    const int vertex = crossField.singularCycles(index);
    const int numerator = crossField.singularIndices(index);
    const auto typed = SourceVertexId::from_index(vertex, vertexExtent);
    if (!typed || numerator == 0) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt,
                  typed ? std::optional<SourceVertexId>(typed.value())
                        : std::nullopt);
    }
    std::map<int, int> &owner = sourceMesh.isBoundaryVertex(vertex) != 0
                                    ? rawBoundarySingularity
                                    : rawSingularity;
    if (!owner.emplace(vertex, numerator).second) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, typed.value());
    }
  }

  std::vector<FieldCycleWitness> cycles;
  std::vector<FieldComponentTopology> componentTopology;
  std::vector<FieldQuadrangulabilityWitness> certificateWitnesses;
  std::vector<FieldTransportRegionDiagnostics> regionTransportDiagnostics;
  std::map<int, std::pair<TopologyRegionId, FieldCycleId>>
      localCycleByGlobalVertex;
  std::map<int, std::pair<TopologyRegionId, FieldCycleId>>
      boundaryCycleByGlobalVertex;
  std::map<int, std::pair<TopologyRegionId, FieldCycleId>>
      slitCycleByGlobalVertex;

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
      FieldTransportRegionDiagnostics regionDiagnostics(region.id());
      regionDiagnostics.hardFeatureEdgeCount = hardFeatureEdges.size();
      regionDiagnostics.uncutEulerCharacteristic = 1;
      regionDiagnostics.uncutBoundaryLoopCount = 1;
      regionDiagnostics.cutEulerCharacteristic = 1;
      regionDiagnostics.cutBoundaryLoopCount = 1;
      regionDiagnostics.witnessKind =
          FieldQuadrangulabilityWitnessKind::RelativeBoundary;
      regionDiagnostics.requiredIndexSum = requiredIndexSum;
      regionDiagnostics.boundaryIndexSum = requiredIndexSum;
      regionTransportDiagnostics.push_back(std::move(regionDiagnostics));
      for (const int vertex : sourceVertices) {
        if (sourceMesh.isBoundaryVertex(vertex) == 0 ||
            rawBoundarySingularity.find(vertex) ==
                rawBoundarySingularity.end()) {
          continue;
        }
        if (!boundaryCycleByGlobalVertex
                 .emplace(vertex,
                          std::make_pair(region.id(), boundaryCycleId))
                 .second) {
          return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                      std::nullopt, std::nullopt,
                      make_id<SourceVertexId>(static_cast<std::size_t>(vertex)),
                      region.id());
        }
      }
      continue;
    }

    const auto local = make_local_region_mesh(sourceMesh, sourceAuthority,
                                               region, hardFeatureEdges);
    if (!local.has_value()) {
      return fail(FieldAtlasBuildErrorCode::CanonicalBindingMismatch,
                  std::nullopt, std::nullopt, std::nullopt, region.id());
    }
    const int eulerCharacteristic = local->diagnostics.cutEulerCharacteristic;
    const int boundaryLoopCount = local->diagnostics.cutBoundaryLoopCount;
    const int genusNumerator =
        2 - boundaryLoopCount - eulerCharacteristic;
    if (!local->cutIdentityValid) {
      FieldAtlasBuildError error;
      error.code = FieldAtlasBuildErrorCode::CutTransportDomainIdentityMismatch;
      error.topologyRegion = region.id();
      error.regionTransportDiagnostics = regionTransportDiagnostics;
      error.regionTransportDiagnostics.push_back(local->diagnostics);
      return FieldTransportAtlasBuildResult(std::move(error));
    }
    const int genus = genusNumerator / 2;

    PCFaceTangentBundle bundle;
    try {
      bundle.init(local->mesh);
    } catch (const std::exception &) {
      return incomplete_cycle_basis_failure(
          sourceMesh, sourceAuthority,
          IncompleteCycleBasisReason::LocalTangentBundleInitializationFailed,
          std::nullopt, region.id(), hardFeatureEdges);
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
      return incomplete_cycle_basis_failure(
          sourceMesh, sourceAuthority,
          IncompleteCycleBasisReason::CycleDimensionCountMismatch, std::nullopt,
          region.id(), hardFeatureEdges);
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
          return incomplete_cycle_basis_failure(
              sourceMesh, sourceAuthority,
              IncompleteCycleBasisReason::CycleCoefficientInvalid, std::nullopt,
              region.id(), hardFeatureEdges);
        }
        const int localEdge = bundle.innerAdjacencies(it.col());
        const SourceEdgeTopologyKey edge =
            global_edge_key(*local, localEdge, vertexExtent);
        const FieldTransportAdjacency *adjacency =
            find_adjacency_in(adjacencies, edge);
        if (adjacency == nullptr) {
          return incomplete_cycle_basis_failure(
              sourceMesh, sourceAuthority,
              IncompleteCycleBasisReason::CycleTransportAdjacencyMissing, edge,
              region.id(), hardFeatureEdges);
        }
        const int firstLocal = local->mesh.EF(localEdge, 0);
        const int secondLocal = local->mesh.EF(localEdge, 1);
        if (firstLocal < 0 || secondLocal < 0) {
          return incomplete_cycle_basis_failure(
              sourceMesh, sourceAuthority,
              IncompleteCycleBasisReason::CycleEdgeIncidentFaceMissing, edge,
              region.id(), hardFeatureEdges);
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
        return incomplete_cycle_basis_failure(
            sourceMesh, sourceAuthority,
            IncompleteCycleBasisReason::CycleOrderingFailed, std::nullopt,
            region.id(), hardFeatureEdges);
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
      return incomplete_cycle_basis_failure(
          sourceMesh, sourceAuthority,
          IncompleteCycleBasisReason::CycleKindPartitionMismatch, std::nullopt,
          region.id(), hardFeatureEdges);
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
    int boundaryIndexSum = 0;
    int absorbedCorrection = 0;
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
      for (const std::size_t cycleIndex : boundaryCycleIndices) {
        boundaryIndexSum += cycles[cycleIndex].turningLift;
        witness.boundaryCycles.push_back(cycles[cycleIndex].id);
      }
      const int correction =
          requiredIndexSum - interiorIndexSum - boundaryIndexSum;
      absorbedCorrection = correction;
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
    if (boundaryCycleIndices.size() != local->mesh.boundaryLoops.size()) {
      return incomplete_cycle_basis_failure(
          sourceMesh, sourceAuthority,
          IncompleteCycleBasisReason::BoundaryCycleCountMismatch, std::nullopt,
          region.id(), hardFeatureEdges);
    }
    for (std::size_t loopIndex = 0;
         loopIndex < local->mesh.boundaryLoops.size(); ++loopIndex) {
      const FieldCycleId boundaryCycle =
          cycles[boundaryCycleIndices[loopIndex]].id;
      for (const int localVertex : local->mesh.boundaryLoops[loopIndex]) {
        if (localVertex < 0 || localVertex >= local->mesh.V.rows()) {
          return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                      std::nullopt, std::nullopt, std::nullopt, region.id());
        }
        const int globalVertex = local->globalVertexByLocal[
            static_cast<std::size_t>(localVertex)];
        const auto owner = std::make_pair(region.id(), boundaryCycle);
        if (sourceMesh.isBoundaryVertex(globalVertex) != 0 &&
            rawBoundarySingularity.find(globalVertex) !=
                rawBoundarySingularity.end()) {
          const auto inserted =
              boundaryCycleByGlobalVertex.emplace(globalVertex, owner);
          if (!inserted.second && inserted.first->second != owner) {
            return fail(
                FieldAtlasBuildErrorCode::SingularityMismatch, std::nullopt,
                std::nullopt,
                make_id<SourceVertexId>(static_cast<std::size_t>(globalVertex)),
                region.id());
          }
        }
        if (sourceMesh.isBoundaryVertex(globalVertex) == 0 &&
            local->barrierVertices.count(globalVertex) != 0U &&
            rawSingularity.find(globalVertex) != rawSingularity.end()) {
          const auto inserted =
              slitCycleByGlobalVertex.emplace(globalVertex, owner);
          if (!inserted.second && inserted.first->second != owner) {
            return fail(
                FieldAtlasBuildErrorCode::SingularityMismatch, std::nullopt,
                std::nullopt,
                make_id<SourceVertexId>(static_cast<std::size_t>(globalVertex)),
                region.id());
          }
        }
      }
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
    const FieldQuadrangulabilityWitnessKind witnessKind = witness.kind;
    certificateWitnesses.push_back(std::move(witness));
    componentTopology.push_back(FieldComponentTopology{
        region.id(), region.component(), eulerCharacteristic,
        boundaryLoopCount, genus,
        static_cast<std::size_t>(local->mesh.V.rows()),
        static_cast<std::size_t>(local->mesh.EV.rows()),
        static_cast<std::size_t>(local->mesh.F.rows()),
        localCycleIndices.size(), handleCycleIndices.size()});
    FieldTransportRegionDiagnostics regionDiagnostics = local->diagnostics;
    regionDiagnostics.witnessKind = witnessKind;
    regionDiagnostics.requiredIndexSum = requiredIndexSum;
    regionDiagnostics.interiorIndexSum = interiorIndexSum;
    regionDiagnostics.boundaryIndexSum = boundaryIndexSum;
    regionDiagnostics.absorbedCorrection = absorbedCorrection;
    regionTransportDiagnostics.push_back(std::move(regionDiagnostics));
  }

  const auto region_diagnostics = [&](const TopologyRegionId region)
      -> FieldTransportRegionDiagnostics * {
    const auto found = std::find_if(
        regionTransportDiagnostics.begin(), regionTransportDiagnostics.end(),
        [&](const FieldTransportRegionDiagnostics &candidate) {
          return candidate.topologyRegion == region;
        });
    return found == regionTransportDiagnostics.end() ? nullptr : &*found;
  };

  for (const auto &[rawVertex, numerator] : rawBoundarySingularity) {
    const SourceVertexId vertex =
        make_id<SourceVertexId>(static_cast<std::size_t>(rawVertex));
    const auto owner = boundaryCycleByGlobalVertex.find(rawVertex);
    if (owner == boundaryCycleByGlobalVertex.end() ||
        owner->second.second.index() >= cycles.size()) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex);
    }
    const FieldCycleWitness &boundaryCycle =
        cycles[owner->second.second.index()];
    if (boundaryCycle.kind != FieldCycleKind::BoundaryLoop ||
        boundaryCycle.turningLift != numerator) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex, owner->second.first);
    }
    FieldTransportRegionDiagnostics *diagnostics =
        region_diagnostics(owner->second.first);
    if (diagnostics == nullptr) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex, owner->second.first);
    }
    ++diagnostics->sourceBoundaryBoundSingularityCount;
  }

  std::vector<FieldSingularityFact> singularities;
  singularities.reserve(rawSingularity.size());
  for (const auto &[rawVertex, numerator] : rawSingularity) {
    const SourceVertexId vertex =
        make_id<SourceVertexId>(static_cast<std::size_t>(rawVertex));
    const auto localOwner = localCycleByGlobalVertex.find(rawVertex);
    const auto slitOwner = slitCycleByGlobalVertex.find(rawVertex);
    if ((localOwner == localCycleByGlobalVertex.end()) ==
        (slitOwner == slitCycleByGlobalVertex.end())) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex);
    }
    const auto &owner = localOwner != localCycleByGlobalVertex.end()
                            ? localOwner->second
                            : slitOwner->second;
    if (owner.second.index() >= cycles.size()) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex, owner.first);
    }
    FieldTransportRegionDiagnostics *diagnostics =
        region_diagnostics(owner.first);
    if (diagnostics == nullptr) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, vertex, owner.first);
    }
    ++diagnostics->prescribedSingularityCount;
    if (localOwner != localCycleByGlobalVertex.end()) {
      ++diagnostics->localVertexBoundSingularityCount;
    } else {
      ++diagnostics->slitBoundaryBoundSingularityCount;
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
        numerator, owner.first, owner.second});
  }
  for (FieldTransportRegionDiagnostics &diagnostics :
       regionTransportDiagnostics) {
    diagnostics.unboundSingularityCount =
        diagnostics.prescribedSingularityCount -
        diagnostics.localVertexBoundSingularityCount -
        diagnostics.slitBoundaryBoundSingularityCount;
    if (diagnostics.unboundSingularityCount != 0U) {
      return fail(FieldAtlasBuildErrorCode::SingularityMismatch,
                  std::nullopt, std::nullopt, std::nullopt,
                  diagnostics.topologyRegion);
    }
  }

  FieldAtlasBuildError attachmentError{
      FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment};
  const auto singularityAttachments = build_singularity_attachments(
      sourceMesh, rowTopology, builtFramesByRow, *branchTransports,
      singularities, attachmentError);
  if (!singularityAttachments.has_value()) {
    return fail(attachmentError.code, attachmentError.sourceEdge,
                attachmentError.sourceFace, attachmentError.sourceVertex,
                attachmentError.topologyRegion);
  }
  const std::uint64_t branchDigest = branch_topology_digest(
      branchFrames, *branchTransports, *singularityAttachments);
  const std::uint64_t atlasDigest = atlas_fact_digest(
      sourceDigest, rowTopology, adjacencies, nontraversableEdges, cycles,
      singularities, componentTopology, certificateWitnesses, branchDigest);
  FieldBranchTopology branchTopology(
      std::move(branchFrames), std::move(*branchTransports),
      std::move(*singularityAttachments), branchDigest);
  FieldQuadrangulabilityCertificate certificate(
      std::move(certificateWitnesses), true, sourceDigest, atlasDigest);
  return FieldTransportAtlasBuildResult(FieldTransportAtlas(
      vertexExtent, std::move(rowTopology), std::move(rowRegions),
      std::move(rowComponents), std::move(adjacencies),
      std::move(nontraversableEdges), std::move(cycles),
      std::move(singularities), std::move(componentTopology),
      std::move(regionTransportDiagnostics), std::move(branchTopology),
      std::move(certificate)));
}

const FieldFaceBranchFrame *FieldBranchTopology::find_frame(
    const SourceFaceTopologyKey &sourceFace) const noexcept {
  const auto found = std::lower_bound(
      frames_.begin(), frames_.end(), sourceFace,
      [](const FieldFaceBranchFrame &candidate,
         const SourceFaceTopologyKey &key) {
        return candidate.sourceFace < key;
      });
  return found != frames_.end() && found->sourceFace == sourceFace ? &*found
                                                                   : nullptr;
}

std::optional<FieldDirectedBranchTransport> FieldBranchTopology::transport(
    const SourceEdgeTopologyKey &sourceEdge,
    const SourceFaceTopologyKey &fromFace,
    const SourceFaceTopologyKey &toFace) const noexcept {
  const FieldBranchTransportAdjacency *adjacency =
      find_branch_transport_in(transports_, sourceEdge);
  return adjacency == nullptr
             ? std::nullopt
             : directed_branch_transport(*adjacency, fromFace, toFace);
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
  case FieldAtlasBuildErrorCode::InvalidBranchTopology:
    return "InvalidBranchTopology";
  case FieldAtlasBuildErrorCode::AmbiguousBranchTopology:
    return "AmbiguousBranchTopology";
  case FieldAtlasBuildErrorCode::InvalidSingularityPortAttachment:
    return "InvalidSingularityPortAttachment";
  case FieldAtlasBuildErrorCode::GaussBonnetPoincareHopfMismatch:
    return "GaussBonnetPoincareHopfMismatch";
  case FieldAtlasBuildErrorCode::UnestablishedAdmissibility:
    return "UnestablishedAdmissibility";
  case FieldAtlasBuildErrorCode::InvalidBranchBoundaryBasis:
    return "InvalidBranchBoundaryBasis";
  case FieldAtlasBuildErrorCode::InvalidBranchBoundaryDerivative:
    return "InvalidBranchBoundaryDerivative";
  case FieldAtlasBuildErrorCode::InvalidBranchBoundaryEdge:
    return "InvalidBranchBoundaryEdge";
  case FieldAtlasBuildErrorCode::InvalidBranchBoundaryFlow:
    return "InvalidBranchBoundaryFlow";
  case FieldAtlasBuildErrorCode::InvalidSingularityMetadata:
    return "InvalidSingularityMetadata";
  case FieldAtlasBuildErrorCode::InvalidSingularityIncidentFan:
    return "InvalidSingularityIncidentFan";
  case FieldAtlasBuildErrorCode::InvalidSingularityFrameRow:
    return "InvalidSingularityFrameRow";
  case FieldAtlasBuildErrorCode::InvalidSingularityFrameOwnership:
    return "InvalidSingularityFrameOwnership";
  case FieldAtlasBuildErrorCode::InvalidSingularityOppositeEdge:
    return "InvalidSingularityOppositeEdge";
  case FieldAtlasBuildErrorCode::InvalidSingularityBranchIndex:
    return "InvalidSingularityBranchIndex";
  case FieldAtlasBuildErrorCode::InvalidSingularityOutgoingCarrier:
    return "InvalidSingularityOutgoingCarrier";
  case FieldAtlasBuildErrorCode::EmptySingularityIncidence:
    return "EmptySingularityIncidence";
  case FieldAtlasBuildErrorCode::InvalidSingularityRadialEdge:
    return "InvalidSingularityRadialEdge";
  case FieldAtlasBuildErrorCode::MissingSingularityBranchTransport:
    return "MissingSingularityBranchTransport";
  case FieldAtlasBuildErrorCode::InvalidSingularityDirectedTransport:
    return "InvalidSingularityDirectedTransport";
  case FieldAtlasBuildErrorCode::SingularityPortClassCountMismatch:
    return "SingularityPortClassCountMismatch";
  case FieldAtlasBuildErrorCode::DuplicateSingularityClassRepresentative:
    return "DuplicateSingularityClassRepresentative";
  case FieldAtlasBuildErrorCode::DuplicateSingularityPortRepresentative:
    return "DuplicateSingularityPortRepresentative";
  case FieldAtlasBuildErrorCode::BranchDirectionNotBarycentric:
    return "BranchDirectionNotBarycentric";
  case FieldAtlasBuildErrorCode::CutTransportDomainIdentityMismatch:
    return "CutTransportDomainIdentityMismatch";
  }
  return "Unknown";
}

const char *incomplete_cycle_basis_reason_name(
    const IncompleteCycleBasisReason reason) noexcept {
  switch (reason) {
  case IncompleteCycleBasisReason::LocalTangentBundleInitializationFailed:
    return "LocalTangentBundleInitializationFailed";
  case IncompleteCycleBasisReason::CycleDimensionCountMismatch:
    return "CycleDimensionCountMismatch";
  case IncompleteCycleBasisReason::CycleCoefficientInvalid:
    return "CycleCoefficientInvalid";
  case IncompleteCycleBasisReason::CycleTransportAdjacencyMissing:
    return "CycleTransportAdjacencyMissing";
  case IncompleteCycleBasisReason::CycleEdgeIncidentFaceMissing:
    return "CycleEdgeIncidentFaceMissing";
  case IncompleteCycleBasisReason::CycleOrderingFailed:
    return "CycleOrderingFailed";
  case IncompleteCycleBasisReason::CycleKindPartitionMismatch:
    return "CycleKindPartitionMismatch";
  case IncompleteCycleBasisReason::BoundaryCycleCountMismatch:
    return "BoundaryCycleCountMismatch";
  }
  return "Unknown";
}

std::uint64_t field_transport_atlas_hash(
    const FieldTransportAtlas &atlas) noexcept {
  return atlas.quadrangulability().atlas_digest();
}

} // namespace directional::authority
