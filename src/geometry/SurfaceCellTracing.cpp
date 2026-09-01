#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SourceChartTransitions.h>

#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/core/TriMesh.h>
#include <Eigen/SparseCholesky>

#include <bit>
#include <cassert>
#include <cmath>
#include <exception>
#include <functional>
#include <limits>
#include <optional>
#include <queue>

namespace directional::geometry::surface_cell_tracing_detail {

std::size_t source_vertex_extent(const Eigen::MatrixXi &faces) {
  int maximumVertex = -1;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < faces.cols(); ++corner) {
      maximumVertex = std::max(maximumVertex, faces(face, corner));
    }
  }
  return static_cast<std::size_t>(std::max(0, maximumVertex + 1));
}

authority::SourceEdgeTopologyKey edge_key(const int a, const int b,
                                           const std::size_t vertexExtent) {
  const auto key = authority::SourceEdgeTopologyKey::from_indices(
      a, b, vertexExtent);
  if (!key) {
    throw std::invalid_argument("invalid source-edge topology key");
  }
  return key.value();
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex) {
  return {vertices(vertex, 0), vertices(vertex, 1), vertices(vertex, 2)};
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d point_position(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &faces,
                                         const SurfaceTracePoint &point) {
  Eigen::RowVector3d p = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 3; ++corner) {
    p += point.barycentric[corner] * row3(vertices, faces(point.face, corner));
  }
  return p;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d face_normal(const Eigen::MatrixXd &vertices,
                                      const Eigen::MatrixXi &faces,
                                      const int face) {
  const Eigen::RowVector3d a = row3(vertices, faces(face, 0));
  const Eigen::RowVector3d b = row3(vertices, faces(face, 1));
  const Eigen::RowVector3d c = row3(vertices, faces(face, 2));
  Eigen::RowVector3d normal = cross3(b - a, c - a);
  const double norm = normal.norm();
  if (norm > 0.0) {
    normal /= norm;
  }
  return normal;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &direction,
                                          const Eigen::RowVector3d &normal) {
  Eigen::RowVector3d tangent = direction - direction.dot(normal) * normal;
  const double norm = tangent.norm();
  if (norm > 0.0) {
    tangent /= norm;
  }
  return tangent;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
edge_faces(const Eigen::MatrixXi &faces) {
  std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> result;
  const std::size_t vertexExtent = source_vertex_extent(faces);
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const auto key = edge_key(faces(face, corner),
                                faces(face, (corner + 1) % 3),
                                vertexExtent);
      auto found = result.find(key);
      if (found == result.end()) {
        result.emplace(key, std::array<int, 2>{face, -1});
      } else if (found->second[1] < 0) {
        found->second[1] = face;
      }
    }
  }
  return result;
}

std::optional<int> source_face_row(const authority::SourceFaceId faceId,
                                   const int faceCount) {
  if (faceCount <= 0) return std::nullopt;
  const std::size_t row = faceId.index();
  if (row >= static_cast<std::size_t>(faceCount)) return std::nullopt;
  return static_cast<int>(row);
}

std::optional<authority::SourceFaceId> source_face_id(const int row,
                                                      const int faceCount) {
  if (faceCount <= 0) return std::nullopt;
  const auto id = authority::SourceFaceId::from_index(
      row, static_cast<std::size_t>(faceCount));
  return id ? std::optional<authority::SourceFaceId>(id.value()) : std::nullopt;
}

std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
edge_faces(const Eigen::MatrixXi &faces,
           const std::vector<authority::SourceFaceId> &activeFaces) {
  std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> result;
  const std::size_t vertexExtent = source_vertex_extent(faces);
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) {
      continue;
    }
    const int face = *faceRow;
    for (int corner = 0; corner < 3; ++corner) {
      const auto key = edge_key(faces(face, corner),
                                faces(face, (corner + 1) % 3),
                                vertexExtent);
      auto found = result.find(key);
      if (found == result.end()) {
        result.emplace(key, std::array<int, 2>{face, -1});
      } else if (found->second[1] < 0) {
        found->second[1] = face;
      }
    }
  }
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::map<authority::SourceEdgeTopologyKey, int>
edge_matching_indices(
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
        &edgeFaces) {
  std::map<authority::SourceEdgeTopologyKey, int> indices;
  int index = 0;
  for (const auto &[key, pair] : edgeFaces) {
    if (pair[0] >= 0 && pair[1] >= 0) {
      indices.emplace(key, index++);
    }
  }
  return indices;
}

std::uint64_t isolation_seam_transport_certificate_hash(
    const SurfaceIsolationSeamTransportCertificate &certificate) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto consume = [&](const std::uint64_t value) {
    hash ^= value;
    hash *= 1099511628211ULL;
  };
  consume(certificate.region().index());
  consume(certificate.seam().first().index());
  consume(certificate.seam().second().index());
  consume(certificate.transition().index());
  for (const authority::SourceVertexId vertex :
       certificate.firstFace().vertices()) {
    consume(vertex.index());
  }
  for (const authority::SourceVertexId vertex :
       certificate.secondFace().vertices()) {
    consume(vertex.index());
  }
  consume(certificate.firstSheet().index());
  consume(certificate.secondSheet().index());
  consume(certificate.forward().value());
  consume(certificate.reverse().value());
  return hash;
}

} // namespace directional::geometry::surface_cell_tracing_detail



namespace directional::geometry::surface_cell_tracing_detail {

namespace {

FieldAlignedCurveNetworkError continuation_error(
    const FieldAlignedCurveNetworkErrorCode code,
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranch branch,
    std::optional<authority::SourceEdgeTopologyKey> sourceEdge = std::nullopt,
    std::optional<authority::SourceVertexId> sourceVertex = std::nullopt,
    std::optional<authority::ExactUnitParameter> parameter = std::nullopt,
    std::vector<authority::FieldExactRational> exactValues = {},
    std::vector<authority::SourceEdgeTopologyKey> publishedEdges = {}) {
  FieldAlignedCurveNetworkError error;
  error.code = code;
  error.sourceEdge = std::move(sourceEdge);
  error.sourceVertex = sourceVertex;
  error.sourceFace = sourceFace;
  error.branch = branch;
  error.parameter = std::move(parameter);
  error.exactValues = std::move(exactValues);
  error.publishedEdges = std::move(publishedEdges);
  return error;
}

std::optional<std::array<authority::FieldExactRational, 3>>
field_boundary_point_barycentric(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBoundaryPoint &point) {
  const auto &vertices = sourceFace.vertices();
  std::array<authority::FieldExactRational, 3> barycentric{
      authority::FieldExactRational::from_integer(0),
      authority::FieldExactRational::from_integer(0),
      authority::FieldExactRational::from_integer(0)};
  std::optional<std::size_t> firstIndex;
  std::optional<std::size_t> secondIndex;
  for (std::size_t index = 0; index < vertices.size(); ++index) {
    if (vertices[index] == point.edge.first()) firstIndex = index;
    if (vertices[index] == point.edge.second()) secondIndex = index;
  }
  if (!firstIndex.has_value() || !secondIndex.has_value()) return std::nullopt;
  const auto one = authority::FieldExactRational::from_integer(1);
  barycentric[*firstIndex] = one - point.parameter.value;
  barycentric[*secondIndex] = point.parameter.value;
  return barycentric;
}

std::optional<authority::SourceEdgeTopologyKey> field_face_opposite_edge(
    const authority::SourceFaceTopologyKey &sourceFace,
    const std::size_t oppositeIndex) {
  if (oppositeIndex >= 3U) return std::nullopt;
  const auto &vertices = sourceFace.vertices();
  const auto edge = authority::SourceEdgeTopologyKey::make(
      vertices[(oppositeIndex + 1U) % 3U], vertices[(oppositeIndex + 2U) % 3U]);
  return edge ? std::optional<authority::SourceEdgeTopologyKey>{edge.value()}
              : std::nullopt;
}

std::optional<std::size_t> field_face_opposite_index(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::SourceEdgeTopologyKey &edge) {
  const auto &vertices = sourceFace.vertices();
  for (std::size_t index = 0U; index < vertices.size(); ++index) {
    if (vertices[index] != edge.first() && vertices[index] != edge.second()) {
      return index;
    }
  }
  return std::nullopt;
}

std::optional<std::size_t> field_face_vertex_index(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::SourceVertexId sourceVertex) {
  const auto &vertices = sourceFace.vertices();
  const auto found = std::find(vertices.begin(), vertices.end(), sourceVertex);
  return found == vertices.end()
             ? std::optional<std::size_t>{}
             : std::optional<std::size_t>{
                   static_cast<std::size_t>(std::distance(vertices.begin(), found))};
}

std::optional<authority::FieldBoundaryPoint> field_boundary_point_from_barycentric(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::SourceEdgeTopologyKey &edge,
    const std::array<authority::FieldExactRational, 3> &barycentric) {
  const auto &vertices = sourceFace.vertices();
  std::optional<std::size_t> firstIndex;
  std::optional<std::size_t> secondIndex;
  for (std::size_t index = 0; index < vertices.size(); ++index) {
    if (vertices[index] == edge.first()) firstIndex = index;
    if (vertices[index] == edge.second()) secondIndex = index;
  }
  if (!firstIndex.has_value() || !secondIndex.has_value()) return std::nullopt;
  authority::FieldBoundaryPoint point{
      edge, authority::ExactUnitParameter{barycentric[*secondIndex]}};
  return point.parameter.in_unit_interval()
             ? std::optional<authority::FieldBoundaryPoint>{std::move(point)}
             : std::nullopt;
}


std::optional<authority::FieldBoundaryPoint> field_boundary_point_at_vertex(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::SourceVertexId sourceVertex) {
  std::vector<authority::SourceEdgeTopologyKey> incident;
  for (const authority::SourceVertexId other : sourceFace.vertices()) {
    if (other == sourceVertex) continue;
    const auto edge = authority::SourceEdgeTopologyKey::make(sourceVertex, other);
    if (edge) incident.push_back(edge.value());
  }
  if (incident.size() != 2U) return std::nullopt;
  std::sort(incident.begin(), incident.end());
  const authority::SourceEdgeTopologyKey edge = incident.front();
  const authority::FieldExactRational endpoint =
      edge.first() == sourceVertex
          ? authority::FieldExactRational::from_integer(0)
          : authority::FieldExactRational::from_integer(1);
  return authority::FieldBoundaryPoint{
      edge, authority::ExactUnitParameter{endpoint}};
}

std::optional<authority::SourceFaceId> field_face_row(
    const TriMesh &sourceMesh,
    const authority::SourceFaceTopologyKey &sourceFace) {
  for (int row = 0; row < sourceMesh.F.rows(); ++row) {
    const auto first = authority::SourceVertexId::from_index(
        sourceMesh.F(row, 0), static_cast<std::size_t>(sourceMesh.V.rows()));
    const auto second = authority::SourceVertexId::from_index(
        sourceMesh.F(row, 1), static_cast<std::size_t>(sourceMesh.V.rows()));
    const auto third = authority::SourceVertexId::from_index(
        sourceMesh.F(row, 2), static_cast<std::size_t>(sourceMesh.V.rows()));
    if (!first || !second || !third) return std::nullopt;
    const auto topology = authority::SourceFaceTopologyKey::make(
        std::array<authority::SourceVertexId, 3>{
            first.value(), second.value(), third.value()});
    if (!topology) return std::nullopt;
    if (topology.value() == sourceFace) {
      const auto face = authority::SourceFaceId::from_index(
          row, static_cast<std::size_t>(sourceMesh.F.rows()));
      return face ? std::optional<authority::SourceFaceId>{face.value()}
                  : std::nullopt;
    }
  }
  return std::nullopt;
}


} // namespace

FieldBranchExitTimeOrdering compare_field_branch_exit_times(
    const authority::FieldExactRational &firstPosition,
    const authority::FieldExactRational &firstNegativeDirection,
    const authority::FieldExactRational &secondPosition,
    const authority::FieldExactRational &secondNegativeDirection) {
  const auto first = firstPosition * secondNegativeDirection;
  const auto second = secondPosition * firstNegativeDirection;
  if (first < second) return FieldBranchExitTimeOrdering::Less;
  if (first > second) return FieldBranchExitTimeOrdering::Greater;
  return FieldBranchExitTimeOrdering::Equal;
}

FieldBranchContinuationResult resolve_field_branch_continuation(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchBoundaryPairing &pairing,
    const authority::FieldBoundaryPoint &entryPoint) {
  if (!entryPoint.parameter.in_unit_interval()) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BoundaryPointParameterOutOfRange,
        sourceFace, pairing.branch, entryPoint.edge, std::nullopt,
        entryPoint.parameter);
  }
  // Deterministic magnitude policy, checked before any exact arithmetic runs on
  // the entry value. Declining to answer is the fail-closed outcome; a
  // magnitude never decides a topological question and never selects an
  // approximate path.
  if (entryPoint.parameter.value.magnitude_bits() >
      kFieldExactContinuationMagnitudeBits) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::
            BranchContinuationExactMagnitudeExceeded,
        sourceFace, pairing.branch, entryPoint.edge, std::nullopt,
        entryPoint.parameter);
  }
  const auto entryBarycentric =
      field_boundary_point_barycentric(sourceFace, entryPoint);
  if (!entryBarycentric.has_value()) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BoundaryPointEdgeNotIncidentToFace,
        sourceFace, pairing.branch, entryPoint.edge);
  }

  const auto zero = authority::FieldExactRational::from_integer(0);
  const bool zeroDirection =
      pairing.direction[0] == zero && pairing.direction[1] == zero &&
      pairing.direction[2] == zero;
  std::vector<std::size_t> negative;
  for (std::size_t index = 0U; index < 3U; ++index) {
    if (pairing.direction[index] < zero) negative.push_back(index);
  }

  if (negative.size() == 3U) {
    // Unreachable from valid barycentric authority because three negatives
    // cannot sum to zero. The unit falsifier deliberately tampers direction.
    std::vector<authority::FieldExactRational> times;
    times.reserve(3U);
    for (const std::size_t index : negative) {
      times.push_back((*entryBarycentric)[index] / (-pairing.direction[index]));
    }
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchContinuationMinimizerImpossible,
        sourceFace, pairing.branch, entryPoint.edge, std::nullopt,
        entryPoint.parameter, std::move(times));
  }
  if (negative.empty() && !zeroDirection) {
    // Unreachable from valid barycentric authority because a nonzero exact
    // triple summing to zero must contain a negative coordinate. The unit
    // falsifier deliberately tampers direction.
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchContinuationNoOutflow,
        sourceFace, pairing.branch, entryPoint.edge);
  }
  if (zeroDirection || !pairing.direction.is_barycentric()) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchDirectionNotBarycentric,
        sourceFace, pairing.branch);
  }

  std::vector<std::size_t> minimizers{negative.front()};
  for (std::size_t candidateIndex = 1U; candidateIndex < negative.size();
       ++candidateIndex) {
    const std::size_t candidate = negative[candidateIndex];
    const std::size_t incumbent = minimizers.front();
    const auto ordering = compare_field_branch_exit_times(
        (*entryBarycentric)[candidate], -pairing.direction[candidate],
        (*entryBarycentric)[incumbent], -pairing.direction[incumbent]);
    if (ordering == FieldBranchExitTimeOrdering::Less) {
      minimizers.assign(1U, candidate);
    } else if (ordering == FieldBranchExitTimeOrdering::Equal) {
      minimizers.push_back(candidate);
    }
  }
  if (minimizers.empty() || minimizers.size() > 2U) {
    // Unreachable from valid barycentric authority: |M| <= |N| <= 2. The unit
    // falsifier deliberately tampers direction.
    std::vector<authority::FieldExactRational> times;
    times.reserve(negative.size());
    for (const std::size_t index : negative) {
      times.push_back((*entryBarycentric)[index] / (-pairing.direction[index]));
    }
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchContinuationMinimizerImpossible,
        sourceFace, pairing.branch, entryPoint.edge, std::nullopt,
        entryPoint.parameter, std::move(times));
  }

  const std::size_t firstMinimizer = minimizers.front();
  const auto time = (*entryBarycentric)[firstMinimizer] /
                    (-pairing.direction[firstMinimizer]);
  if (time == zero) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry,
        sourceFace, pairing.branch, entryPoint.edge, std::nullopt,
        entryPoint.parameter, std::vector<authority::FieldExactRational>{time});
  }

  std::vector<authority::SourceEdgeTopologyKey> minimizingEdges;
  minimizingEdges.reserve(minimizers.size());
  for (const std::size_t minimizer : minimizers) {
    const auto edge = field_face_opposite_edge(sourceFace, minimizer);
    if (!edge.has_value() ||
        std::find(pairing.outgoingCarriers.begin(), pairing.outgoingCarriers.end(),
                  *edge) == pairing.outgoingCarriers.end()) {
      return continuation_error(
          FieldAlignedCurveNetworkErrorCode::BranchContinuationOutsideOutflowSet,
          sourceFace, pairing.branch,
          edge.has_value() ? std::optional<authority::SourceEdgeTopologyKey>{*edge}
                           : std::optional<authority::SourceEdgeTopologyKey>{},
          std::nullopt, entryPoint.parameter, {}, pairing.outgoingCarriers);
    }
    minimizingEdges.push_back(*edge);
  }

  std::array<authority::FieldExactRational, 3> exitBarycentric =
      *entryBarycentric;
  for (std::size_t index = 0U; index < 3U; ++index) {
    exitBarycentric[index] =
        exitBarycentric[index] + time * pairing.direction[index];
  }

  if (minimizers.size() == 1U) {
    const authority::SourceEdgeTopologyKey outgoing = minimizingEdges.front();
    const auto exitPoint = field_boundary_point_from_barycentric(
        sourceFace, outgoing, exitBarycentric);
    if (!exitPoint.has_value()) {
      return continuation_error(
          FieldAlignedCurveNetworkErrorCode::BoundaryPointParameterOutOfRange,
          sourceFace, pairing.branch, outgoing);
    }
    const auto support = exitPoint->source_support();
    if (support.has_value()) {
      if (const auto *vertexSupport =
              std::get_if<authority::SourceVertexSupport>(&*support)) {
        return FieldBranchContinuationDecision{
            FieldBranchContinuationKind::VertexHit, *exitPoint, outgoing,
            vertexSupport->vertex};
      }
    }
    return FieldBranchContinuationDecision{
        FieldBranchContinuationKind::EdgeExit, *exitPoint, outgoing,
        std::nullopt};
  }

  std::sort(minimizingEdges.begin(), minimizingEdges.end());
  const auto &vertices = sourceFace.vertices();
  std::optional<std::size_t> sharedIndex;
  for (std::size_t index = 0U; index < 3U; ++index) {
    if (std::find(minimizers.begin(), minimizers.end(), index) ==
        minimizers.end()) {
      sharedIndex = index;
      break;
    }
  }
  if (!sharedIndex.has_value()) {
    return continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchContinuationMinimizerImpossible,
        sourceFace, pairing.branch, entryPoint.edge);
  }
  const authority::SourceVertexId sharedVertex = vertices[*sharedIndex];
  const authority::SourceEdgeTopologyKey representative = minimizingEdges.front();
  const authority::FieldExactRational endpoint =
      representative.first() == sharedVertex
          ? authority::FieldExactRational::from_integer(0)
          : authority::FieldExactRational::from_integer(1);
  return FieldBranchContinuationDecision{
      FieldBranchContinuationKind::VertexHit,
      authority::FieldBoundaryPoint{
          representative, authority::ExactUnitParameter{endpoint}},
      representative, sharedVertex};
}

namespace {

using VertexStarRational = authority::FieldExactRational;

struct VertexStarExactVector3 {
  std::array<VertexStarRational, 3> value{};
};

VertexStarRational vertex_star_zero() {
  return VertexStarRational::from_integer(0);
}
VertexStarRational vertex_star_one() {
  return VertexStarRational::from_integer(1);
}

std::optional<VertexStarExactVector3>
vertex_star_exact_position(const TriMesh &sourceMesh,
                           const authority::SourceVertexId vertex) {
  if (vertex.index() >= static_cast<std::size_t>(sourceMesh.V.rows())) {
    return std::nullopt;
  }
  VertexStarExactVector3 result;
  for (std::size_t coordinate = 0U; coordinate < 3U; ++coordinate) {
    const auto exact = VertexStarRational::from_double_exact(
        sourceMesh.V(static_cast<int>(vertex.index()),
                     static_cast<int>(coordinate)));
    if (!exact.has_value()) return std::nullopt;
    result.value[coordinate] = *exact;
  }
  return result;
}

VertexStarExactVector3 vertex_star_subtract(const VertexStarExactVector3 &a,
                                             const VertexStarExactVector3 &b) {
  VertexStarExactVector3 result;
  for (std::size_t coordinate = 0U; coordinate < 3U; ++coordinate) {
    result.value[coordinate] = a.value[coordinate] - b.value[coordinate];
  }
  return result;
}

VertexStarRational vertex_star_dot(const VertexStarExactVector3 &a,
                                   const VertexStarExactVector3 &b) {
  VertexStarRational result = vertex_star_zero();
  for (std::size_t coordinate = 0U; coordinate < 3U; ++coordinate) {
    result = result + a.value[coordinate] * b.value[coordinate];
  }
  return result;
}

std::optional<VertexStarExactVector3> vertex_star_exact_direction(
    const TriMesh &sourceMesh,
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchDirection &direction) {
  if (!direction.is_barycentric()) return std::nullopt;
  VertexStarExactVector3 result;
  for (auto &coordinate : result.value) coordinate = vertex_star_zero();
  const auto &vertices = sourceFace.vertices();
  for (std::size_t index = 0U; index < vertices.size(); ++index) {
    const auto point = vertex_star_exact_position(sourceMesh, vertices[index]);
    if (!point.has_value()) return std::nullopt;
    for (std::size_t coordinate = 0U; coordinate < 3U; ++coordinate) {
      result.value[coordinate] = result.value[coordinate] +
          direction[index] * point->value[coordinate];
    }
  }
  return result;
}

struct VertexStarAngleTerm {
  VertexStarRational dot;
  VertexStarRational normProduct;
  VertexStarRational crossSquared;
};

std::optional<VertexStarAngleTerm>
vertex_star_angle_term(const VertexStarExactVector3 &first,
                       const VertexStarExactVector3 &second) {
  const VertexStarRational firstNorm = vertex_star_dot(first, first);
  const VertexStarRational secondNorm = vertex_star_dot(second, second);
  const VertexStarRational product = firstNorm * secondNorm;
  if (product <= vertex_star_zero()) return std::nullopt;
  const VertexStarRational dot = vertex_star_dot(first, second);
  const VertexStarRational crossSquared = product - dot * dot;
  if (crossSquared < vertex_star_zero()) return std::nullopt;
  return VertexStarAngleTerm{dot, product, crossSquared};
}

struct VertexStarRadicalRepresentation {
  VertexStarRational coefficient = vertex_star_one();
  std::size_t mask = 0U;
};

class VertexStarRadicalBasis {
public:
  VertexStarRadicalBasis() : products_{vertex_star_one()} {}

  [[nodiscard]] std::optional<VertexStarRadicalRepresentation>
  represent_square_root(const VertexStarRational &radicand) {
    if (radicand < vertex_star_zero()) return std::nullopt;
    if (radicand == vertex_star_zero()) {
      return VertexStarRadicalRepresentation{vertex_star_zero(), 0U};
    }
    if (const auto found = find_square_root(radicand)) return found;
    if (basis_.size() >= sizeof(std::size_t) * 8U - 1U) {
      return std::nullopt;
    }
    const std::size_t oldSize = products_.size();
    basis_.push_back(radicand);
    products_.resize(oldSize * 2U);
    for (std::size_t mask = 0U; mask < oldSize; ++mask) {
      products_[oldSize + mask] = products_[mask] * radicand;
    }
    return VertexStarRadicalRepresentation{vertex_star_one(), oldSize};
  }

  [[nodiscard]] std::optional<VertexStarRadicalRepresentation>
  find_square_root(const VertexStarRational &radicand) const {
    if (radicand < vertex_star_zero()) return std::nullopt;
    if (radicand == vertex_star_zero()) {
      return VertexStarRadicalRepresentation{vertex_star_zero(), 0U};
    }
    for (std::size_t mask = 0U; mask < products_.size(); ++mask) {
      const VertexStarRational ratio = radicand / products_[mask];
      const auto root = ratio.rational_square_root();
      if (root.has_value()) {
        return VertexStarRadicalRepresentation{*root, mask};
      }
    }
    return std::nullopt;
  }

  [[nodiscard]] std::size_t dimension() const noexcept { return basis_.size(); }
  [[nodiscard]] std::size_t coefficient_count() const noexcept {
    return products_.size();
  }
  [[nodiscard]] const std::vector<VertexStarRational> &basis() const noexcept {
    return basis_;
  }
  [[nodiscard]] const VertexStarRational &product(const std::size_t mask) const {
    return products_[mask];
  }

private:
  std::vector<VertexStarRational> basis_;
  std::vector<VertexStarRational> products_;
};

struct VertexStarAlgebraicValue {
  std::vector<VertexStarRational> coefficients;
};
struct VertexStarComplexValue {
  VertexStarAlgebraicValue real;
  VertexStarAlgebraicValue imaginary;
};

VertexStarComplexValue
vertex_star_complex_one(const VertexStarRadicalBasis &basis) {
  VertexStarComplexValue result;
  result.real.coefficients.assign(basis.coefficient_count(), vertex_star_zero());
  result.imaginary.coefficients.assign(basis.coefficient_count(),
                                       vertex_star_zero());
  result.real.coefficients[0] = vertex_star_one();
  return result;
}

VertexStarRational vertex_star_radical_monomial_coefficient(
    const VertexStarRadicalBasis &basis, const std::size_t existingMask,
    const VertexStarRadicalRepresentation &radical) {
  return radical.coefficient * basis.product(existingMask & radical.mask);
}

void vertex_star_multiply_angle_factor(
    VertexStarComplexValue &value, const VertexStarRadicalBasis &basis,
    const VertexStarAngleTerm &term,
    const VertexStarRadicalRepresentation &radical,
    const int orientation) {
  std::vector<VertexStarRational> nextReal(
      basis.coefficient_count(), vertex_star_zero());
  std::vector<VertexStarRational> nextImaginary(
      basis.coefficient_count(), vertex_star_zero());
  const VertexStarRational orientationValue =
      VertexStarRational::from_integer(orientation);
  for (std::size_t mask = 0U; mask < basis.coefficient_count(); ++mask) {
    const VertexStarRational &real = value.real.coefficients[mask];
    const VertexStarRational &imaginary = value.imaginary.coefficients[mask];
    nextReal[mask] = nextReal[mask] + real * term.dot;
    nextImaginary[mask] = nextImaginary[mask] + imaginary * term.dot;
    const std::size_t radicalMask = mask ^ radical.mask;
    const VertexStarRational radicalCoefficient =
        vertex_star_radical_monomial_coefficient(basis, mask, radical);
    nextReal[radicalMask] = nextReal[radicalMask] -
        orientationValue * imaginary * radicalCoefficient;
    nextImaginary[radicalMask] = nextImaginary[radicalMask] +
        orientationValue * real * radicalCoefficient;
  }
  value.real.coefficients = std::move(nextReal);
  value.imaginary.coefficients = std::move(nextImaginary);
}

bool vertex_star_algebraic_zero(const VertexStarAlgebraicValue &value) {
  const VertexStarRational zero = vertex_star_zero();
  return std::all_of(value.coefficients.begin(), value.coefficients.end(),
                     [&](const VertexStarRational &coefficient) {
                       return coefficient == zero;
                     });
}

std::optional<int> vertex_star_algebraic_sign_at_precision(
    const VertexStarAlgebraicValue &value,
    const VertexStarRadicalBasis &basis, const std::size_t fractionalBits) {
  if (vertex_star_algebraic_zero(value)) return 0;
  std::vector<VertexStarRational> radicalLower(basis.dimension(),
                                               vertex_star_zero());
  std::vector<VertexStarRational> radicalUpper(basis.dimension(),
                                               vertex_star_zero());
  for (std::size_t index = 0U; index < basis.dimension(); ++index) {
    const auto bounds = basis.basis()[index].sqrt_bounds(fractionalBits);
    if (!bounds.has_value()) return std::nullopt;
    radicalLower[index] = bounds->first;
    radicalUpper[index] = bounds->second;
  }
  std::vector<VertexStarRational> monomialLower(
      basis.coefficient_count(), vertex_star_one());
  std::vector<VertexStarRational> monomialUpper(
      basis.coefficient_count(), vertex_star_one());
  for (std::size_t mask = 1U; mask < basis.coefficient_count(); ++mask) {
    std::size_t bit = 0U;
    while (((mask >> bit) & 1U) == 0U) ++bit;
    const std::size_t previous = mask & ~(std::size_t{1} << bit);
    monomialLower[mask] = monomialLower[previous] * radicalLower[bit];
    monomialUpper[mask] = monomialUpper[previous] * radicalUpper[bit];
  }
  VertexStarRational lower = vertex_star_zero();
  VertexStarRational upper = vertex_star_zero();
  const VertexStarRational zero = vertex_star_zero();
  for (std::size_t mask = 0U; mask < basis.coefficient_count(); ++mask) {
    const VertexStarRational &coefficient = value.coefficients[mask];
    if (coefficient == zero) continue;
    if (coefficient > zero) {
      lower = lower + coefficient * monomialLower[mask];
      upper = upper + coefficient * monomialUpper[mask];
    } else {
      lower = lower + coefficient * monomialUpper[mask];
      upper = upper + coefficient * monomialLower[mask];
    }
  }
  if (lower > zero) return 1;
  if (upper < zero) return -1;
  return std::nullopt;
}

VertexStarAlgebraicValue vertex_star_algebraic_multiply(
    const VertexStarAlgebraicValue &first,
    const VertexStarAlgebraicValue &second,
    const VertexStarRadicalBasis &basis, const std::size_t dimension) {
  const std::size_t coefficientCount = std::size_t{1} << dimension;
  assert(first.coefficients.size() == coefficientCount);
  assert(second.coefficients.size() == coefficientCount);
  VertexStarAlgebraicValue result;
  result.coefficients.assign(coefficientCount, vertex_star_zero());
  const VertexStarRational zero = vertex_star_zero();
  for (std::size_t firstMask = 0U; firstMask < coefficientCount; ++firstMask) {
    if (first.coefficients[firstMask] == zero) continue;
    for (std::size_t secondMask = 0U; secondMask < coefficientCount;
         ++secondMask) {
      if (second.coefficients[secondMask] == zero) continue;
      const std::size_t targetMask = firstMask ^ secondMask;
      const VertexStarRational repeatedRadicals =
          basis.product(firstMask & secondMask);
      result.coefficients[targetMask] = result.coefficients[targetMask] +
          first.coefficients[firstMask] * second.coefficients[secondMask] *
              repeatedRadicals;
    }
  }
  return result;
}

int vertex_star_algebraic_sign_exact_recursive(
    const VertexStarAlgebraicValue &value,
    const VertexStarRadicalBasis &basis, const std::size_t dimension) {
  if (vertex_star_algebraic_zero(value)) return 0;
  if (dimension == 0U) {
    const VertexStarRational zero = vertex_star_zero();
    return value.coefficients[0] < zero ? -1 : 1;
  }

  const std::size_t half = std::size_t{1} << (dimension - 1U);
  VertexStarAlgebraicValue rationalPart;
  VertexStarAlgebraicValue radicalPart;
  rationalPart.coefficients.assign(value.coefficients.begin(),
                                   value.coefficients.begin() + half);
  radicalPart.coefficients.assign(value.coefficients.begin() + half,
                                  value.coefficients.end());

  const int rationalSign = vertex_star_algebraic_sign_exact_recursive(
      rationalPart, basis, dimension - 1U);
  const int radicalSign = vertex_star_algebraic_sign_exact_recursive(
      radicalPart, basis, dimension - 1U);
  if (radicalSign == 0) return rationalSign;
  if (rationalSign == 0) return radicalSign;
  if (rationalSign == radicalSign) return rationalSign;

  // Successively eliminate the highest radical.  For
  // x = a + b*sqrt(q), opposite signs of a and b reduce the decision to
  // sign(a^2 - q*b^2) in the smaller multiquadratic field.  Every recursive
  // call removes one radical, so this exact fallback always terminates.
  VertexStarAlgebraicValue difference = vertex_star_algebraic_multiply(
      rationalPart, rationalPart, basis, dimension - 1U);
  const VertexStarAlgebraicValue radicalSquared =
      vertex_star_algebraic_multiply(radicalPart, radicalPart, basis,
                                     dimension - 1U);
  const VertexStarRational &radicand = basis.basis()[dimension - 1U];
  for (std::size_t mask = 0U; mask < half; ++mask) {
    difference.coefficients[mask] = difference.coefficients[mask] -
        radicand * radicalSquared.coefficients[mask];
  }
  const int magnitudeOrdering = vertex_star_algebraic_sign_exact_recursive(
      difference, basis, dimension - 1U);
  if (magnitudeOrdering == 0) return 0;
  return magnitudeOrdering > 0 ? rationalSign : radicalSign;
}

int vertex_star_algebraic_sign_exact(const VertexStarAlgebraicValue &value,
                                     const VertexStarRadicalBasis &basis) {
  assert(value.coefficients.size() == basis.coefficient_count());
  return vertex_star_algebraic_sign_exact_recursive(value, basis,
                                                     basis.dimension());
}

std::optional<int> vertex_star_algebraic_sign_filter(
    const VertexStarAlgebraicValue &value,
    const VertexStarRadicalBasis &basis) {
  if (vertex_star_algebraic_zero(value)) return 0;
  std::size_t precision = 32U;
  while (true) {
    if (const auto sign =
            vertex_star_algebraic_sign_at_precision(value, basis, precision)) {
      return sign;
    }
    if (precision >
        static_cast<std::size_t>(std::numeric_limits<int>::max() / 4)) {
      // A certified filter is allowed to defer.  The exact elimination
      // fallback owns the decision from here; no approximate answer escapes.
      return std::nullopt;
    }
    precision *= 2U;
  }
}

struct VertexStarAngleAccumulator {
  VertexStarComplexValue value;
  int halfTurns = 0;
};
using VertexStarSignFilter = std::function<std::optional<int>(
    const VertexStarAlgebraicValue &, const VertexStarRadicalBasis &)>;

std::optional<VertexStarAngleAccumulator> vertex_star_accumulate_angles(
    const std::vector<VertexStarAngleTerm> &terms,
    const VertexStarRadicalBasis &basis, const VertexStarSignFilter &sign) {
  VertexStarAngleAccumulator accumulator{vertex_star_complex_one(basis), 0};
  for (const VertexStarAngleTerm &term : terms) {
    const auto radical = basis.find_square_root(term.crossSquared);
    if (!radical.has_value()) return std::nullopt;
    vertex_star_multiply_angle_factor(accumulator.value, basis, term, *radical,
                                      +1);
    const auto imaginarySign = sign(accumulator.value.imaginary, basis);
    if (!imaginarySign.has_value()) return std::nullopt;
    if (*imaginarySign == 0) {
      ++accumulator.halfTurns;
      continue;
    }
    const int expected = (accumulator.halfTurns % 2 == 0) ? 1 : -1;
    if (*imaginarySign != expected) ++accumulator.halfTurns;
  }
  return accumulator;
}

std::optional<int> vertex_star_compare_angle_sums_with_sign(
    const std::vector<VertexStarAngleTerm> &first,
    const std::vector<VertexStarAngleTerm> &second,
    const bool filterOnly) {
  VertexStarRadicalBasis basis;
  for (const VertexStarAngleTerm &term : first) {
    if (!basis.represent_square_root(term.crossSquared).has_value()) {
      return std::nullopt;
    }
  }
  for (const VertexStarAngleTerm &term : second) {
    if (!basis.represent_square_root(term.crossSquared).has_value()) {
      return std::nullopt;
    }
  }
  const VertexStarSignFilter sign =
      [&](const VertexStarAlgebraicValue &value,
          const VertexStarRadicalBasis &activeBasis) -> std::optional<int> {
    return filterOnly
        ? vertex_star_algebraic_sign_filter(value, activeBasis)
        : std::optional<int>{vertex_star_algebraic_sign_exact(value,
                                                               activeBasis)};
  };
  const auto firstAccumulator = vertex_star_accumulate_angles(first, basis, sign);
  const auto secondAccumulator =
      vertex_star_accumulate_angles(second, basis, sign);
  if (!firstAccumulator.has_value() || !secondAccumulator.has_value()) {
    return std::nullopt;
  }
  if (firstAccumulator->halfTurns != secondAccumulator->halfTurns) {
    return firstAccumulator->halfTurns < secondAccumulator->halfTurns ? -1 : 1;
  }
  VertexStarComplexValue difference = vertex_star_complex_one(basis);
  for (const VertexStarAngleTerm &term : first) {
    const auto radical = basis.find_square_root(term.crossSquared);
    if (!radical.has_value()) return std::nullopt;
    vertex_star_multiply_angle_factor(difference, basis, term, *radical, +1);
  }
  for (const VertexStarAngleTerm &term : second) {
    const auto radical = basis.find_square_root(term.crossSquared);
    if (!radical.has_value()) return std::nullopt;
    vertex_star_multiply_angle_factor(difference, basis, term, *radical, -1);
  }
  if (filterOnly && vertex_star_algebraic_zero(difference.imaginary)) {
    return std::nullopt;
  }
  return sign(difference.imaginary, basis);
}

struct VertexStarAngleComparison {
  int ordering = 0;
  VertexStarDecisionKernelRoute route = VertexStarDecisionKernelRoute::Filter;
};

VertexStarAngleComparison vertex_star_compare_angle_sums(
    const std::vector<VertexStarAngleTerm> &first,
    const std::vector<VertexStarAngleTerm> &second) {
  if (const auto filtered =
          vertex_star_compare_angle_sums_with_sign(first, second, true)) {
    return VertexStarAngleComparison{*filtered,
                                     VertexStarDecisionKernelRoute::Filter};
  }
  const auto exact = vertex_star_compare_angle_sums_with_sign(first, second,
                                                               false);
  if (!exact.has_value()) {
    throw std::runtime_error("vertex-star exact angle comparison unavailable");
  }
  return VertexStarAngleComparison{*exact,
                                   VertexStarDecisionKernelRoute::ExactFallback};
}

void vertex_star_merge_kernel_route(VertexStarDecisionKernelRoute &target,
                                    const VertexStarDecisionKernelRoute route) {
  if (route == VertexStarDecisionKernelRoute::ExactFallback ||
      target == VertexStarDecisionKernelRoute::ExactFallback) {
    target = VertexStarDecisionKernelRoute::ExactFallback;
  } else if (route == VertexStarDecisionKernelRoute::RationalShortCircuit ||
             target == VertexStarDecisionKernelRoute::RationalShortCircuit) {
    target = VertexStarDecisionKernelRoute::RationalShortCircuit;
  } else {
    target = route;
  }
}

struct VertexStarSector {
  authority::SourceFaceTopologyKey sourceFace;
  authority::SourceFaceId sourceRow;
  authority::FieldBranch branch;
  authority::SourceVertexId nextRadialVertex;
  authority::SourceVertexId previousRadialVertex;
  authority::FieldBranchDirection representativeDirection;
  VertexStarAngleTerm angle;
  bool representativeInOwnSector = false;
};

std::optional<VertexStarSector> vertex_star_sector(
    const TriMesh &sourceMesh,
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranch branch,
    const authority::FieldBranchDirection &representativeDirection,
    const authority::SourceVertexId sourceVertex) {
  const auto row = field_face_row(sourceMesh, sourceFace);
  if (!row.has_value()) return std::nullopt;
  const int sourceRow = static_cast<int>(row->index());
  int corner = -1;
  for (int index = 0; index < 3; ++index) {
    if (sourceMesh.F(sourceRow, index) ==
        static_cast<int>(sourceVertex.index())) {
      corner = index;
      break;
    }
  }
  if (corner < 0) return std::nullopt;
  const auto next = authority::SourceVertexId::from_index(
      sourceMesh.F(sourceRow, (corner + 1) % 3),
      static_cast<std::size_t>(sourceMesh.V.rows()));
  const auto previous = authority::SourceVertexId::from_index(
      sourceMesh.F(sourceRow, (corner + 2) % 3),
      static_cast<std::size_t>(sourceMesh.V.rows()));
  if (!next || !previous) return std::nullopt;
  const auto origin = vertex_star_exact_position(sourceMesh, sourceVertex);
  const auto nextPoint = vertex_star_exact_position(sourceMesh, next.value());
  const auto previousPoint =
      vertex_star_exact_position(sourceMesh, previous.value());
  if (!origin || !nextPoint || !previousPoint) return std::nullopt;
  const auto angle = vertex_star_angle_term(
      vertex_star_subtract(*nextPoint, *origin),
      vertex_star_subtract(*previousPoint, *origin));
  if (!angle.has_value()) return std::nullopt;
  return VertexStarSector{
      sourceFace, *row, branch, next.value(), previous.value(),
      representativeDirection, *angle,
      authority::direction_in_vertex_sector(sourceMesh, *row, sourceVertex,
                                             representativeDirection)};
}

bool vertex_star_has_transport(
    const authority::FieldBranchTopology &topology,
    const authority::SourceVertexId sourceVertex,
    const VertexStarSector &from, const VertexStarSector &to) {
  if (from.previousRadialVertex != to.nextRadialVertex) return false;
  const auto edge = authority::SourceEdgeTopologyKey::make(
      sourceVertex, from.previousRadialVertex);
  return edge && topology.transport(edge.value(), from.sourceFace,
                                    to.sourceFace).has_value();
}

std::optional<std::vector<VertexStarSector>> vertex_star_order_sectors(
    const authority::FieldBranchTopology &topology,
    const authority::SourceVertexId sourceVertex,
    const authority::SourceFaceTopologyKey &arrivalFace,
    const std::vector<VertexStarSector> &input, bool &closed) {
  if (input.empty()) return std::nullopt;
  std::vector<std::optional<std::size_t>> successor(input.size());
  std::vector<std::optional<std::size_t>> predecessor(input.size());
  for (std::size_t first = 0U; first < input.size(); ++first) {
    for (std::size_t second = 0U; second < input.size(); ++second) {
      if (first == second) continue;
      if (!vertex_star_has_transport(topology, sourceVertex, input[first],
                                     input[second])) continue;
      if (successor[first].has_value() || predecessor[second].has_value()) {
        return std::nullopt;
      }
      successor[first] = second;
      predecessor[second] = first;
    }
  }
  const std::size_t noSuccessor = static_cast<std::size_t>(std::count_if(
      successor.begin(), successor.end(),
      [](const auto &value) { return !value.has_value(); }));
  const std::size_t noPredecessor = static_cast<std::size_t>(std::count_if(
      predecessor.begin(), predecessor.end(),
      [](const auto &value) { return !value.has_value(); }));
  closed = noSuccessor == 0U && noPredecessor == 0U;
  if (!closed && (noSuccessor != 1U || noPredecessor != 1U)) {
    return std::nullopt;
  }
  std::size_t start = 0U;
  if (closed) {
    const auto found = std::find_if(
        input.begin(), input.end(), [&](const VertexStarSector &sector) {
          return sector.sourceFace == arrivalFace;
        });
    if (found == input.end()) return std::nullopt;
    start = static_cast<std::size_t>(std::distance(input.begin(), found));
  } else {
    const auto found = std::find_if(
        predecessor.begin(), predecessor.end(),
        [](const auto &value) { return !value.has_value(); });
    if (found == predecessor.end()) return std::nullopt;
    start = static_cast<std::size_t>(std::distance(predecessor.begin(), found));
  }
  std::vector<VertexStarSector> ordered;
  ordered.reserve(input.size());
  std::set<std::size_t> seen;
  std::size_t current = start;
  while (seen.insert(current).second) {
    ordered.push_back(input[current]);
    if (!successor[current].has_value()) break;
    current = *successor[current];
    if (closed && current == start) break;
  }
  if (ordered.size() != input.size()) return std::nullopt;
  return ordered;
}

bool vertex_star_source_boundary_edge(
    const TriMesh &sourceMesh, const authority::SourceVertexId sourceVertex,
    const authority::SourceVertexId radialVertex) {
  const auto edge = authority::SourceEdgeTopologyKey::make(sourceVertex,
                                                            radialVertex);
  if (!edge) return false;
  for (int row = 0; row < sourceMesh.EV.rows(); ++row) {
    const auto candidate = authority::SourceEdgeTopologyKey::from_indices(
        sourceMesh.EV(row, 0), sourceMesh.EV(row, 1),
        static_cast<std::size_t>(sourceMesh.V.rows()));
    if (!candidate || candidate.value() != edge.value()) continue;
    return sourceMesh.EF(row, 0) < 0 || sourceMesh.EF(row, 1) < 0;
  }
  return false;
}

std::vector<VertexStarAngleTerm> vertex_star_twice(
    const std::vector<VertexStarAngleTerm> &terms) {
  std::vector<VertexStarAngleTerm> result;
  result.reserve(terms.size() * 2U);
  result.insert(result.end(), terms.begin(), terms.end());
  result.insert(result.end(), terms.begin(), terms.end());
  return result;
}
void vertex_star_append(std::vector<VertexStarAngleTerm> &target,
                        const std::vector<VertexStarAngleTerm> &source) {
  target.insert(target.end(), source.begin(), source.end());
}

std::optional<authority::SourceVertexId> vertex_star_arrival_radial_ray(
    const TriMesh &sourceMesh, const authority::SourceFaceId sourceFace,
    const authority::SourceFaceTopologyKey &sourceTopology,
    const authority::SourceVertexId sourceVertex,
    const authority::FieldBranchDirection &direction) {
  if (sourceFace.index() >= static_cast<std::size_t>(sourceMesh.F.rows()))
    return std::nullopt;
  const int row = static_cast<int>(sourceFace.index());
  int corner = -1;
  for (int index = 0; index < 3; ++index) {
    if (sourceMesh.F(row, index) == static_cast<int>(sourceVertex.index())) {
      corner = index;
      break;
    }
  }
  if (corner < 0) return std::nullopt;
  const auto next = authority::SourceVertexId::from_index(
      sourceMesh.F(row, (corner + 1) % 3),
      static_cast<std::size_t>(sourceMesh.V.rows()));
  const auto previous = authority::SourceVertexId::from_index(
      sourceMesh.F(row, (corner + 2) % 3),
      static_cast<std::size_t>(sourceMesh.V.rows()));
  if (!next || !previous) return std::nullopt;

  const auto &vertices = sourceTopology.vertices();
  const auto nextIndex = std::find(vertices.begin(), vertices.end(), next.value());
  const auto previousIndex =
      std::find(vertices.begin(), vertices.end(), previous.value());
  if (nextIndex == vertices.end() || previousIndex == vertices.end())
    return std::nullopt;
  const auto zero = vertex_star_zero();
  const auto nextOffset =
      static_cast<std::size_t>(std::distance(vertices.begin(), nextIndex));
  const auto previousOffset =
      static_cast<std::size_t>(std::distance(vertices.begin(), previousIndex));
  if (direction[nextOffset] > zero && direction[previousOffset] == zero)
    return next.value();
  if (direction[nextOffset] == zero && direction[previousOffset] > zero)
    return previous.value();
  return std::nullopt;
}

authority::FieldBranchDirection vertex_star_membership_witness(
    const VertexStarSector &sector, const authority::SourceVertexId sourceVertex,
    const bool onNextRadial) {
  authority::FieldBranchDirection result;
  const auto zero = vertex_star_zero();
  const auto one = vertex_star_one();
  for (std::size_t index = 0U; index < sector.sourceFace.vertices().size();
       ++index) {
    const auto vertex = sector.sourceFace.vertices()[index];
    if (vertex == sourceVertex) {
      result.barycentric[index] = onNextRadial ? -one : -one - one;
    } else if (vertex == sector.nextRadialVertex) {
      result.barycentric[index] = one;
    } else if (vertex == sector.previousRadialVertex) {
      result.barycentric[index] = onNextRadial ? zero : one;
    }
  }
  return result;
}

} // namespace

FieldVertexTransitResult resolve_field_vertex_transit(
    const TriMesh &sourceMesh,
    const authority::FieldBranchTopology &topology,
    const authority::SourceComponentId sourceComponent,
    const authority::TopologyRegionId topologyRegion,
    const authority::SourceFaceTopologyKey &currentFace,
    const authority::FieldBranch currentBranch,
    const authority::SourceVertexId sourceVertex,
    const FieldVertexArrivalMode arrivalMode,
    const std::optional<authority::TraceId> provenanceTrace,
    const std::optional<std::size_t> provenanceEvent) {
  struct TransitState {
    authority::SourceFaceTopologyKey sourceFace;
    authority::FieldBranch branch;
    std::vector<authority::SourceEdgeTopologyKey> transportPath;
    int composedSignedLift = 0;
  };
  using StateKey =
      std::pair<authority::SourceFaceTopologyKey, authority::FieldBranch>;

  std::vector<FieldVertexTransitStateDiagnostic> diagnostics;
  std::optional<VertexStarTransitAudit> audit{VertexStarTransitAudit{}};
  const auto record =
      [&](const authority::SourceFaceTopologyKey &sourceFace,
          const authority::FieldBranch branch,
          const FieldVertexTransitStateOutcome outcome,
          const std::optional<authority::FieldBranchDirection> &representative,
          const std::optional<authority::SourceEdgeTopologyKey> &transportEdge,
          const std::vector<authority::SourceEdgeTopologyKey> &transportPath,
          const int composedSignedLift, const bool eligible = false,
          const bool representativeInSector = false) {
        diagnostics.push_back(FieldVertexTransitStateDiagnostic{
            sourceFace, branch, representative, std::nullopt, transportEdge,
            transportPath, ((composedSignedLift % 4) + 4) % 4, outcome,
            eligible, representativeInSector, false});
      };
  const auto failure = [&](const FieldAlignedCurveNetworkErrorCode code) {
    FieldAlignedCurveNetworkError error = continuation_error(
        code, currentFace, currentBranch, std::nullopt, sourceVertex);
    error.topologyRegion = topologyRegion;
    error.vertexArrivalMode = arrivalMode;
    error.vertexTransitStates = diagnostics;
    error.vertexStarTransit = audit;
    return error;
  };
  const auto unique_pairing = [](const authority::FieldFaceBranchFrame &frame,
                                 const authority::FieldBranch branch,
                                 bool &ambiguous) {
    const authority::FieldBranchBoundaryPairing *result = nullptr;
    ambiguous = false;
    for (const auto &candidate : frame.branches) {
      if (candidate.branch != branch) continue;
      if (result != nullptr) {
        ambiguous = true;
        return static_cast<const authority::FieldBranchBoundaryPairing *>(
            nullptr);
      }
      result = &candidate;
    }
    return result;
  };

  const auto *currentFrame = topology.find_frame(currentFace);
  if (currentFrame == nullptr) {
    record(currentFace, currentBranch,
           FieldVertexTransitStateOutcome::SeedFrameUnavailable, std::nullopt,
           std::nullopt, {}, 0);
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  if (currentFrame->sourceComponent != sourceComponent ||
      currentFrame->topologyRegion != topologyRegion) {
    record(currentFace, currentBranch,
           FieldVertexTransitStateOutcome::SeedAuthorityMismatch, std::nullopt,
           std::nullopt, {}, 0);
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  bool currentPairingAmbiguous = false;
  const auto *currentPairing =
      unique_pairing(*currentFrame, currentBranch, currentPairingAmbiguous);
  if (currentPairing == nullptr) {
    record(currentFace, currentBranch,
           currentPairingAmbiguous
               ? FieldVertexTransitStateOutcome::SeedBranchPairingAmbiguous
               : FieldVertexTransitStateOutcome::SeedBranchPairingMissing,
           std::nullopt, std::nullopt, {}, 0);
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  authority::FieldBranchDirection arrivalRay = currentPairing->direction;
  for (VertexStarRational &coordinate : arrivalRay.barycentric) {
    coordinate = -coordinate;
  }
  audit->seed = VertexStarRaySeed{sourceVertex, currentFace, currentBranch,
                                  arrivalRay, arrivalMode, false, std::nullopt,
                                  provenanceTrace, provenanceEvent};
  if (!currentPairing->direction.is_barycentric()) {
    record(currentFace, currentBranch,
           FieldVertexTransitStateOutcome::SeedDirectionNotBarycentric,
           currentPairing->direction, std::nullopt, {}, 0);
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }

  const auto currentRow = field_face_row(sourceMesh, currentFace);
  if (!currentRow.has_value()) {
    record(currentFace, currentBranch,
           FieldVertexTransitStateOutcome::SeedArrivalFaceRowUnavailable,
           currentPairing->direction, std::nullopt, {}, 0);
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  if (!authority::direction_in_closed_vertex_wedge(
          sourceMesh, *currentRow, sourceVertex, arrivalRay)) {
    record(currentFace, currentBranch,
           FieldVertexTransitStateOutcome::SeedDirectionOutsideClosedWedge,
           currentPairing->direction, std::nullopt, {}, 0);
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  audit->seed->radialRay = vertex_star_arrival_radial_ray(
      sourceMesh, *currentRow, currentFace, sourceVertex, arrivalRay);
  audit->seed->onRadialRay = audit->seed->radialRay.has_value();

  std::vector<TransitState> pending{{currentFace, currentBranch, {}, 0}};
  std::set<StateKey> visited;
  std::map<authority::SourceFaceTopologyKey, TransitState> reachable;
  std::size_t evaluatedStates = 0U;
  bool walkIncomplete = false;

  for (std::size_t cursor = 0U; cursor < pending.size(); ++cursor) {
    const TransitState state = pending[cursor];
    if (!visited.insert(StateKey{state.sourceFace, state.branch}).second) {
      record(state.sourceFace, state.branch,
             FieldVertexTransitStateOutcome::DuplicateStateSuppressed,
             std::nullopt, std::nullopt, state.transportPath,
             state.composedSignedLift);
      continue;
    }
    const auto *frame = topology.find_frame(state.sourceFace);
    if (frame == nullptr) {
      record(state.sourceFace, state.branch,
             FieldVertexTransitStateOutcome::StateFrameUnavailable,
             std::nullopt, std::nullopt, state.transportPath,
             state.composedSignedLift);
      walkIncomplete = true;
      continue;
    }
    if (frame->sourceComponent != sourceComponent ||
        frame->topologyRegion != topologyRegion) {
      record(state.sourceFace, state.branch,
             FieldVertexTransitStateOutcome::StateAuthorityMismatch,
             std::nullopt, std::nullopt, state.transportPath,
             state.composedSignedLift);
      walkIncomplete = true;
      continue;
    }
    bool pairingAmbiguous = false;
    const auto *pairing = unique_pairing(*frame, state.branch, pairingAmbiguous);
    if (pairing == nullptr) {
      record(state.sourceFace, state.branch,
             pairingAmbiguous
                 ? FieldVertexTransitStateOutcome::StateBranchPairingAmbiguous
                 : FieldVertexTransitStateOutcome::StateBranchPairingMissing,
             std::nullopt, std::nullopt, state.transportPath,
             state.composedSignedLift);
      walkIncomplete = true;
      continue;
    }
    if (!pairing->direction.is_barycentric()) {
      record(state.sourceFace, state.branch,
             FieldVertexTransitStateOutcome::StateRepresentativeDirectionNotBarycentric,
             pairing->direction, std::nullopt, state.transportPath,
             state.composedSignedLift);
      walkIncomplete = true;
      continue;
    }
    const auto row = field_face_row(sourceMesh, state.sourceFace);
    if (!row.has_value()) {
      record(state.sourceFace, state.branch,
             FieldVertexTransitStateOutcome::StateSourceFaceRowUnavailable,
             pairing->direction, std::nullopt, state.transportPath,
             state.composedSignedLift);
      walkIncomplete = true;
      continue;
    }
    const bool eligible = arrivalMode == FieldVertexArrivalMode::EdgeTransit ||
                          state.sourceFace != currentFace;
    const bool representativeInSector = authority::direction_in_vertex_sector(
        sourceMesh, *row, sourceVertex, pairing->direction);
    record(state.sourceFace, state.branch,
           FieldVertexTransitStateOutcome::Evaluated, pairing->direction,
           std::nullopt, state.transportPath, state.composedSignedLift, eligible,
           representativeInSector);
    ++evaluatedStates;
    const auto [found, inserted] = reachable.emplace(state.sourceFace, state);
    if (!inserted && found->second.branch != state.branch) {
      return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
    }

    for (const auto &adjacency : topology.transports()) {
      if (adjacency.sourceEdge.first() != sourceVertex &&
          adjacency.sourceEdge.second() != sourceVertex) continue;
      std::optional<authority::SourceFaceTopologyKey> nextFace;
      if (adjacency.firstFace == state.sourceFace) {
        nextFace = adjacency.secondFace;
      } else if (adjacency.secondFace == state.sourceFace) {
        nextFace = adjacency.firstFace;
      } else {
        continue;
      }
      const auto directed = topology.transport(adjacency.sourceEdge,
                                               state.sourceFace, *nextFace);
      if (!directed.has_value()) {
        record(state.sourceFace, state.branch,
               FieldVertexTransitStateOutcome::DirectedTransportUnavailable,
               pairing->direction, adjacency.sourceEdge, state.transportPath,
               state.composedSignedLift);
        walkIncomplete = true;
        continue;
      }
      auto transportPath = state.transportPath;
      transportPath.push_back(adjacency.sourceEdge);
      const auto nextBranch = state.branch.rotated(directed->signedLift);
      const int nextSignedLift = state.composedSignedLift + directed->signedLift;
      const auto *nextFrame = topology.find_frame(*nextFace);
      if (nextFrame == nullptr) {
        record(*nextFace, nextBranch,
               FieldVertexTransitStateOutcome::TransportTargetFrameUnavailable,
               std::nullopt, adjacency.sourceEdge, transportPath,
               nextSignedLift);
        walkIncomplete = true;
        continue;
      }
      if (nextFrame->sourceComponent != sourceComponent ||
          nextFrame->topologyRegion != topologyRegion) {
        record(*nextFace, nextBranch,
               FieldVertexTransitStateOutcome::TransportTargetAuthorityMismatch,
               std::nullopt, adjacency.sourceEdge, transportPath,
               nextSignedLift);
        walkIncomplete = true;
        continue;
      }
      bool nextPairingAmbiguous = false;
      const auto *nextPairing =
          unique_pairing(*nextFrame, nextBranch, nextPairingAmbiguous);
      if (nextPairing == nullptr) {
        record(*nextFace, nextBranch,
               nextPairingAmbiguous
                   ? FieldVertexTransitStateOutcome::TransportTargetBranchPairingAmbiguous
                   : FieldVertexTransitStateOutcome::TransportTargetBranchPairingMissing,
               std::nullopt, adjacency.sourceEdge, transportPath,
               nextSignedLift);
        walkIncomplete = true;
        continue;
      }
      if (!nextPairing->direction.is_barycentric()) {
        record(*nextFace, nextBranch,
               FieldVertexTransitStateOutcome::TransportTargetDirectionNotBarycentric,
               nextPairing->direction, adjacency.sourceEdge, transportPath,
               nextSignedLift);
        walkIncomplete = true;
        continue;
      }
      pending.push_back(
          TransitState{*nextFace, nextBranch, std::move(transportPath),
                       nextSignedLift});
    }
  }

  if (evaluatedStates == 0U || reachable.empty()) {
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitWalkUnexamined);
  }
  if (walkIncomplete) {
    // Amendment 19 requires every failed walk state to be diagnosed before it
    // can be skipped. Once such a state exists, the admissible fan is not
    // certified complete, so fail closed rather than elect from a subset.
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
  }

  std::vector<VertexStarSector> sectors;
  sectors.reserve(reachable.size());
  for (const auto &[face, state] : reachable) {
    const auto *frame = topology.find_frame(face);
    bool ambiguous = false;
    const auto *pairing = frame == nullptr
                              ? nullptr
                              : unique_pairing(*frame, state.branch, ambiguous);
    if (pairing == nullptr) {
      return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
    }
    const auto sector = vertex_star_sector(sourceMesh, face, state.branch,
                                           pairing->direction, sourceVertex);
    if (!sector.has_value()) {
      return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
    }
    sectors.push_back(*sector);
  }

  bool closedFan = false;
  const auto ordered = vertex_star_order_sectors(
      topology, sourceVertex, currentFace, sectors, closedFan);
  if (!ordered.has_value()) {
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
  }
  sectors = *ordered;
  audit->closedFan = closedFan;
  audit->fanLength = sectors.size();
  audit->sectors.reserve(sectors.size());
  for (const VertexStarSector &sector : sectors) {
    audit->sectors.push_back(VertexStarSectorAudit{
        sector.sourceFace, sector.branch, sector.nextRadialVertex,
        sector.previousRadialVertex, sector.angle.dot, sector.angle.normProduct,
        sector.angle.crossSquared,
        arrivalMode == FieldVertexArrivalMode::EdgeTransit ||
            sector.sourceFace != currentFace,
        false, sector.representativeInOwnSector});
    if (sector.angle.crossSquared == vertex_star_zero()) {
      audit->state = VertexStarTransitState::DegenerateSector;
      return failure(FieldAlignedCurveNetworkErrorCode::VertexStarDegenerateSector);
    }
  }
  if (sectors.size() > kVertexStarExactFanLengthBudget) {
    audit->state = VertexStarTransitState::ExactBudgetExceeded;
    audit->kernelRoute = VertexStarDecisionKernelRoute::NotRun;
    return failure(FieldAlignedCurveNetworkErrorCode::VertexStarExactBudgetExceeded);
  }

  const auto arrivalFound = std::find_if(
      sectors.begin(), sectors.end(), [&](const VertexStarSector &sector) {
        return sector.sourceFace == currentFace;
      });
  if (arrivalFound == sectors.end()) {
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  const std::size_t arrivalIndex =
      static_cast<std::size_t>(std::distance(sectors.begin(), arrivalFound));
  const auto origin = vertex_star_exact_position(sourceMesh, sourceVertex);
  const auto startPoint =
      vertex_star_exact_position(sourceMesh, arrivalFound->nextRadialVertex);
  const auto ray = vertex_star_exact_direction(sourceMesh, currentFace,
                                                arrivalRay);
  if (!origin || !startPoint || !ray) {
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  const auto alpha = vertex_star_angle_term(
      vertex_star_subtract(*startPoint, *origin), *ray);
  if (!alpha.has_value()) {
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }
  if (alpha->crossSquared == vertex_star_zero() &&
      alpha->dot <= vertex_star_zero()) {
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable);
  }

  std::vector<VertexStarAngleTerm> alphaTerms;
  if (alpha->crossSquared != vertex_star_zero()) alphaTerms.push_back(*alpha);
  std::vector<VertexStarAngleTerm> thetaTerms;
  thetaTerms.reserve(sectors.size());
  for (const VertexStarSector &sector : sectors) thetaTerms.push_back(sector.angle);

  VertexStarDecisionKernelRoute kernelRoute =
      VertexStarDecisionKernelRoute::Filter;
  std::size_t ownerIndex = sectors.size();
  bool onRadialRay = false;
  std::optional<authority::SourceVertexId> radialRay;

  if (closedFan) {
    std::vector<VertexStarAngleTerm> right = thetaTerms;
    vertex_star_append(right, vertex_star_twice(alphaTerms));
    std::vector<VertexStarAngleTerm> prefix;
    for (std::size_t index = 0U; index < sectors.size(); ++index) {
      prefix.push_back(sectors[index].angle);
      const auto comparison =
          vertex_star_compare_angle_sums(vertex_star_twice(prefix), right);
      vertex_star_merge_kernel_route(kernelRoute, comparison.route);
      if (comparison.ordering < 0) continue;
      if (comparison.ordering == 0) {
        ownerIndex = (index + 1U) % sectors.size();
        onRadialRay = true;
        radialRay = sectors[index].previousRadialVertex;
      } else {
        ownerIndex = index;
      }
      break;
    }
    if (ownerIndex == sectors.size()) ownerIndex = 0U;
  } else {
    audit->truncationReason =
        vertex_star_source_boundary_edge(sourceMesh, sourceVertex,
                                         sectors.front().nextRadialVertex) ||
                vertex_star_source_boundary_edge(
                    sourceMesh, sourceVertex,
                    sectors.back().previousRadialVertex)
            ? "SourceBoundary"
            : "Barrier";
    std::vector<VertexStarAngleTerm> alphaGlobal;
    for (std::size_t index = 0U; index < arrivalIndex; ++index) {
      alphaGlobal.push_back(sectors[index].angle);
    }
    vertex_star_append(alphaGlobal, alphaTerms);
    const auto truncationComparison = vertex_star_compare_angle_sums(
        vertex_star_twice(alphaGlobal), thetaTerms);
    vertex_star_merge_kernel_route(kernelRoute, truncationComparison.route);
    if (truncationComparison.ordering >= 0) {
      audit->kernelRoute = kernelRoute;
      audit->state = VertexStarTransitState::TruncatedBeforeContinuation;
      return failure(FieldAlignedCurveNetworkErrorCode::
                         VertexStarTruncatedBeforeContinuation);
    }
    std::vector<VertexStarAngleTerm> target = thetaTerms;
    vertex_star_append(target, vertex_star_twice(alphaGlobal));
    std::vector<VertexStarAngleTerm> prefix;
    for (std::size_t index = 0U; index < sectors.size(); ++index) {
      prefix.push_back(sectors[index].angle);
      const auto comparison =
          vertex_star_compare_angle_sums(vertex_star_twice(prefix), target);
      vertex_star_merge_kernel_route(kernelRoute, comparison.route);
      if (comparison.ordering < 0) continue;
      if (comparison.ordering == 0) {
        if (index + 1U == sectors.size()) {
          audit->kernelRoute = kernelRoute;
          audit->state = VertexStarTransitState::TruncatedBeforeContinuation;
          audit->onRadialRay = true;
          audit->radialRay = sectors[index].previousRadialVertex;
          return failure(FieldAlignedCurveNetworkErrorCode::
                             VertexStarTruncatedBeforeContinuation);
        }
        ownerIndex = index + 1U;
        onRadialRay = true;
        radialRay = sectors[index].previousRadialVertex;
      } else {
        ownerIndex = index;
      }
      break;
    }
  }

  if (ownerIndex >= sectors.size()) {
    audit->kernelRoute = kernelRoute;
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
  }
  const VertexStarSector &owner = sectors[ownerIndex];
  const bool eligible = arrivalMode == FieldVertexArrivalMode::EdgeTransit ||
                        owner.sourceFace != currentFace;
  if (!eligible) {
    audit->kernelRoute = kernelRoute;
    audit->ownerFace = owner.sourceFace;
    audit->ownerBranch = owner.branch;
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
  }
  const authority::FieldBranchDirection membershipWitness =
      vertex_star_membership_witness(owner, sourceVertex, onRadialRay);
  if (!authority::direction_in_vertex_sector(sourceMesh, owner.sourceRow,
                                             sourceVertex,
                                             membershipWitness)) {
    audit->kernelRoute = kernelRoute;
    return failure(FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved);
  }
  audit->kernelRoute = kernelRoute;
  audit->state = VertexStarTransitState::Owner;
  audit->ownerCardinality = 1U;
  audit->ownerFace = owner.sourceFace;
  audit->ownerBranch = owner.branch;
  audit->onRadialRay = onRadialRay;
  audit->radialRay = radialRay;
  audit->sectors[ownerIndex].containsContinuation = true;
  return FieldVertexTransitDecision{owner.sourceFace, owner.branch, audit};
}

std::size_t field_aligned_trace_step_budget(
    const authority::FieldBranchTopology &topology) noexcept {
  std::size_t branchStates = 0U;
  for (const authority::FieldFaceBranchFrame &frame : topology.frames()) {
    if (branchStates > std::numeric_limits<std::size_t>::max() -
                           frame.branches.size()) {
      return std::numeric_limits<std::size_t>::max();
    }
    branchStates += frame.branches.size();
  }
  // One (face, branch) state can be entered through any of the face's three
  // edges or at any of its three vertices, so a trace has exactly six
  // position-free entry modes per branch state. Multiplying by the guard's
  // per-state visit allowance gives the largest step count the recurrence guard
  // can permit, which makes the budget a provable envelope rather than an
  // independent policy: it can never fire before the recurrence guard does.
  //
  // The previous expression multiplied by the transport count as well, which on
  // the prescribed sphere produced 1,775,616 steps. Exact continuation values
  // grow with every step, so that budget could never be reached - the arithmetic
  // became unaffordable first - and the guard was inert.
  constexpr std::size_t kEntryModesPerBranchState = 6U;
  constexpr std::size_t kStatesPerStep =
      kEntryModesPerBranchState * kFieldAlignedTraceMaxCombinatorialVisits;
  if (branchStates > std::numeric_limits<std::size_t>::max() / kStatesPerStep) {
    return std::numeric_limits<std::size_t>::max();
  }
  return std::max<std::size_t>(64U, branchStates * kStatesPerStep);
}

FieldAlignedCurveNetworkError field_aligned_trace_traversal_error(
    const FieldAlignedTraceTraversalStatus status,
    const FieldAlignedTraceTraversalState &state,
    const FieldAlignedTraceTraversalGuard &guard) {
  FieldAlignedCurveNetworkErrorCode code =
      FieldAlignedCurveNetworkErrorCode::TraceStepBudgetExhausted;
  if (status == FieldAlignedTraceTraversalStatus::CycleDetected) {
    code = FieldAlignedCurveNetworkErrorCode::TraceStateCycleDetected;
  } else if (status ==
             FieldAlignedTraceTraversalStatus::CombinatorialRecurrenceExceeded) {
    code = FieldAlignedCurveNetworkErrorCode::TraceCombinatorialRecurrenceExceeded;
  }
  FieldAlignedCurveNetworkError error = continuation_error(
      code, state.sourceFace, state.branch, state.incomingCarrier, std::nullopt,
      state.entryPoint.parameter);
  error.traceSteps = guard.steps();
  error.traceStepBudget = guard.step_budget();
  error.traceCombinatorialVisits = guard.combinatorial_recurrence();
  error.traceCombinatorialVisitAllowance =
      FieldAlignedTraceTraversalGuard::combinatorial_visit_allowance();
  return error;
}

FieldBranchEdgeFlowRelation classify_field_branch_transport_flow(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchBoundaryPairing &sourcePairing,
    const authority::SourceFaceTopologyKey &targetFace,
    const authority::FieldBranchBoundaryPairing &targetPairing,
    const authority::SourceEdgeTopologyKey &carrier) {
  (void)sourceFace;
  assert(std::find(sourcePairing.outgoingCarriers.begin(),
                   sourcePairing.outgoingCarriers.end(), carrier) !=
         sourcePairing.outgoingCarriers.end());
  const auto targetOpposite = field_face_opposite_index(targetFace, carrier);
  assert(targetOpposite.has_value());
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto &derivative = targetPairing.direction[*targetOpposite];
  if (derivative > zero) return FieldBranchEdgeFlowRelation::Inflow;
  if (derivative < zero) return FieldBranchEdgeFlowRelation::Outflow;
  return FieldBranchEdgeFlowRelation::Tangent;
}

FieldBranchContinuationResult resolve_field_branch_grazing_transit(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchBoundaryPairing &sourcePairing,
    const authority::SourceFaceTopologyKey &targetFace,
    const authority::FieldBranchBoundaryPairing &targetPairing,
    const authority::SourceEdgeTopologyKey &carrier, const int signedLift,
    const authority::ExactUnitParameter &entryParameter) {
  assert(classify_field_branch_transport_flow(
             sourceFace, sourcePairing, targetFace, targetPairing, carrier) ==
         FieldBranchEdgeFlowRelation::Outflow);
  const auto sourceOpposite = field_face_opposite_index(sourceFace, carrier);
  const auto targetOpposite = field_face_opposite_index(targetFace, carrier);
  const auto sourceSecond = field_face_vertex_index(sourceFace, carrier.second());
  const auto targetSecond = field_face_vertex_index(targetFace, carrier.second());
  assert(sourceOpposite.has_value() && targetOpposite.has_value());
  assert(sourceSecond.has_value() && targetSecond.has_value());

  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto &sourceDerivative = sourcePairing.direction[*sourceOpposite];
  const auto &targetDerivative = targetPairing.direction[*targetOpposite];
  const auto &sourceRate = sourcePairing.direction[*sourceSecond];
  const auto &targetRate = targetPairing.direction[*targetSecond];

  const bool positive = sourceRate > zero && targetRate > zero;
  const bool negative = sourceRate < zero && targetRate < zero;
  if (!positive && !negative) {
    FieldAlignedCurveNetworkError error = continuation_error(
        FieldAlignedCurveNetworkErrorCode::BranchGrazingSlideDirectionAmbiguous,
        sourceFace, sourcePairing.branch, carrier, std::nullopt, entryParameter,
        {sourceDerivative, targetDerivative, sourceRate, targetRate});
    error.relatedSourceFace = targetFace;
    error.relatedBranch = targetPairing.branch;
    error.signedLift = signedLift;
    return error;
  }

  const authority::SourceVertexId endpoint =
      positive ? carrier.second() : carrier.first();
  const authority::FieldExactRational endpointParameter =
      authority::FieldExactRational::from_integer(positive ? 1 : 0);
  return FieldBranchContinuationDecision{
      FieldBranchContinuationKind::EdgeTransit,
      authority::FieldBoundaryPoint{
          carrier, authority::ExactUnitParameter{endpointParameter}},
      carrier, endpoint};
}

void annotate_field_aligned_trace_seed(
    FieldAlignedCurveNetworkError &error,
    const authority::SourceVertexId traceSeedVertex,
    const authority::FieldSingularityId traceSeedSingularity) {
  error.traceSeedVertex = traceSeedVertex;
  error.traceSeedSingularity = traceSeedSingularity;
}

void annotate_field_aligned_trace_history(
    FieldAlignedCurveNetworkError &error,
    const FieldAlignedCandidateTrace &trace,
    const FieldAlignedTraceTraversalState &state) {
  error.traceHistory.clear();
  error.traceHistory.reserve(trace.segments.size() + 1U);
  for (const FieldAlignedCandidateTraceSegment &segment : trace.segments) {
    error.traceHistory.push_back(FieldAlignedTraceStepDiagnostic{
        segment.sourceFace, segment.branch, segment.incomingCarrier,
        segment.entryPoint.parameter});
  }
  const FieldAlignedTraceStepDiagnostic current{
      state.sourceFace, state.branch, state.incomingCarrier,
      state.entryPoint.parameter};
  if (error.traceHistory.empty() || error.traceHistory.back() != current) {
    error.traceHistory.push_back(current);
  }
}

FieldAlignedCurveNetworkError trace_scoped_field_aligned_error(
    const FieldAlignedCurveNetworkErrorCode code,
    const authority::SourceVertexId traceSeedVertex,
    const authority::FieldSingularityId traceSeedSingularity,
    std::optional<authority::SourceVertexId> sourceVertex = std::nullopt,
    std::optional<authority::SourceEdgeTopologyKey> sourceEdge = std::nullopt,
    std::optional<authority::SourceFaceTopologyKey> sourceFace = std::nullopt,
    std::optional<authority::FieldBranch> branch = std::nullopt,
    std::optional<authority::FieldSingularityId> singularity = std::nullopt) {
  FieldAlignedCurveNetworkError error;
  error.code = code;
  error.sourceVertex = sourceVertex;
  error.sourceEdge = std::move(sourceEdge);
  error.sourceFace = std::move(sourceFace);
  error.branch = branch;
  error.singularity = singularity;
  annotate_field_aligned_trace_seed(error, traceSeedVertex,
                                    traceSeedSingularity);
  return error;
}

std::optional<FieldAlignedCurveNetworkError>
append_field_aligned_singularity_termination(
    FieldAlignedCurveNetworkCandidate &candidate,
    const FieldAlignedCandidateTrace &trace) {
  if (!trace.terminalSingularity.has_value() ||
      !trace.terminalPoint.has_value() || trace.segments.empty()) {
    FieldAlignedCurveNetworkError error = trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
        trace.sourceVertex, trace.singularity);
    if (!trace.segments.empty()) {
      error.sourceFace = trace.segments.back().sourceFace;
      error.branch = trace.segments.back().branch;
    }
    if (trace.terminalPoint.has_value()) {
      error.sourceEdge = trace.terminalPoint->edge;
    }
    return error;
  }
  const auto support = trace.terminalPoint->source_support();
  const auto *vertexSupport =
      support.has_value()
          ? std::get_if<authority::SourceVertexSupport>(&*support)
          : nullptr;
  const auto terminalPort = std::find_if(
      candidate.singularityPorts.begin(), candidate.singularityPorts.end(),
      [&](const FieldAlignedSingularityPort &port) {
        return port.singularity == *trace.terminalSingularity;
      });
  if (vertexSupport == nullptr ||
      terminalPort == candidate.singularityPorts.end() ||
      terminalPort->sourceVertex != vertexSupport->vertex) {
    FieldAlignedCurveNetworkError error = trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
        trace.sourceVertex, trace.singularity, std::nullopt,
        trace.terminalPoint->edge, trace.segments.back().sourceFace,
        trace.segments.back().branch);
    return error;
  }

  const authority::SourceFaceTopologyKey sourceFace =
      trace.segments.back().sourceFace;
  candidate.events.emplace_back(
      terminalPort->node, FieldAlignedNetworkEventKind::FirstContact,
      sourceFace, trace.terminalPoint->edge,
      std::vector<FieldAlignedNetworkEventIncidence>{
          FieldAlignedNetworkEventIncidence(
              trace.id, trace.port, FieldAlignedTraceEventRole::Interior)});
  candidate.events.emplace_back(
      terminalPort->node, FieldAlignedNetworkEventKind::SingularityTermination,
      sourceFace, trace.terminalPoint->edge,
      std::vector<FieldAlignedNetworkEventIncidence>{
          FieldAlignedNetworkEventIncidence(
              trace.id, trace.port, FieldAlignedTraceEventRole::Terminal)});
  return std::nullopt;
}

FieldAlignedArrivalOrdering field_aligned_compare_arrivals(
    const FieldAlignedArrivalMeasure &first,
    const FieldAlignedArrivalMeasure &second) noexcept {
  const double firstUpper = first.value + first.bound;
  const double firstLower = first.value - first.bound;
  const double secondUpper = second.value + second.bound;
  const double secondLower = second.value - second.bound;
  if (firstUpper < secondLower) return FieldAlignedArrivalOrdering::Earlier;
  if (secondUpper < firstLower) return FieldAlignedArrivalOrdering::Later;
  return FieldAlignedArrivalOrdering::Inconclusive;
}

FieldAlignedSegmentContactClassification
classify_field_aligned_barycentric_contact(
    const std::array<authority::FieldExactRational, 3> &firstEntry,
    const std::array<authority::FieldExactRational, 3> &firstExit,
    const std::array<authority::FieldExactRational, 3> &secondEntry,
    const std::array<authority::FieldExactRational, 3> &secondExit) {
  FieldAlignedSegmentContactClassification result;
  const auto orient = [](
                          const std::array<authority::FieldExactRational, 3> &a,
                          const std::array<authority::FieldExactRational, 3> &b,
                          const std::array<authority::FieldExactRational, 3> &c) {
    return (b[0] - a[0]) * (c[1] - a[1]) -
           (b[1] - a[1]) * (c[0] - a[0]);
  };
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto abFirst = orient(firstEntry, firstExit, secondEntry);
  const auto abSecond = orient(firstEntry, firstExit, secondExit);
  const auto cdFirst = orient(secondEntry, secondExit, firstEntry);
  const auto cdSecond = orient(secondEntry, secondExit, firstExit);

  const bool abOpposite = abFirst != zero && abSecond != zero &&
                          ((abFirst < zero) != (abSecond < zero));
  const bool cdOpposite = cdFirst != zero && cdSecond != zero &&
                          ((cdFirst < zero) != (cdSecond < zero));
  if (abOpposite && cdOpposite) {
    const auto firstDx = firstExit[0] - firstEntry[0];
    const auto firstDy = firstExit[1] - firstEntry[1];
    const auto secondDx = secondExit[0] - secondEntry[0];
    const auto secondDy = secondExit[1] - secondEntry[1];
    const auto denominator = firstDx * secondDy - firstDy * secondDx;
    if (denominator == zero) {
      result.kind = FieldAlignedSegmentContactKind::Unevaluated;
      return result;
    }
    const auto offsetX = secondEntry[0] - firstEntry[0];
    const auto offsetY = secondEntry[1] - firstEntry[1];
    const auto t = (offsetX * secondDy - offsetY * secondDx) / denominator;
    std::array<authority::FieldExactRational, 3> point{
        authority::FieldExactRational::from_integer(0),
        authority::FieldExactRational::from_integer(0),
        authority::FieldExactRational::from_integer(0)};
    for (std::size_t coordinate = 0U; coordinate < point.size(); ++coordinate) {
      point[coordinate] = firstEntry[coordinate] +
                          t * (firstExit[coordinate] - firstEntry[coordinate]);
    }
    result.kind = FieldAlignedSegmentContactKind::ProperCrossing;
    result.barycentric = std::move(point);
    return result;
  }

  const auto between = [](const authority::FieldExactRational &first,
                          const authority::FieldExactRational &second,
                          const authority::FieldExactRational &value) {
    return (first <= value && value <= second) ||
           (second <= value && value <= first);
  };
  const auto onSegment = [&](
                             const std::array<authority::FieldExactRational, 3> &a,
                             const std::array<authority::FieldExactRational, 3> &b,
                             const std::array<authority::FieldExactRational, 3> &point) {
    if (orient(a, b, point) != zero) return false;
    for (std::size_t coordinate = 0U; coordinate < point.size(); ++coordinate) {
      if (!between(a[coordinate], b[coordinate], point[coordinate])) return false;
    }
    return true;
  };

  const bool allCollinear = abFirst == zero && abSecond == zero &&
                            cdFirst == zero && cdSecond == zero;
  if (allCollinear) {
    std::vector<std::array<authority::FieldExactRational, 3>> overlapPoints;
    const auto consider = [&](
                              const std::array<authority::FieldExactRational, 3> &point) {
      if (!onSegment(firstEntry, firstExit, point) ||
          !onSegment(secondEntry, secondExit, point)) {
        return;
      }
      if (std::find(overlapPoints.begin(), overlapPoints.end(), point) ==
          overlapPoints.end()) {
        overlapPoints.push_back(point);
      }
    };
    consider(firstEntry);
    consider(firstExit);
    consider(secondEntry);
    consider(secondExit);
    if (overlapPoints.empty()) return result;
    result.barycentric = overlapPoints.front();
    result.kind = overlapPoints.size() == 1U
                      ? FieldAlignedSegmentContactKind::EndpointTouch
                      : FieldAlignedSegmentContactKind::CollinearOverlap;
    return result;
  }

  const auto publishEndpointTouch = [&](
                                        const std::array<authority::FieldExactRational, 3> &point) {
    result.kind = FieldAlignedSegmentContactKind::EndpointTouch;
    result.barycentric = point;
  };
  if (onSegment(firstEntry, firstExit, secondEntry)) {
    publishEndpointTouch(secondEntry);
  } else if (onSegment(firstEntry, firstExit, secondExit)) {
    publishEndpointTouch(secondExit);
  } else if (onSegment(secondEntry, secondExit, firstEntry)) {
    publishEndpointTouch(firstEntry);
  } else if (onSegment(secondEntry, secondExit, firstExit)) {
    publishEndpointTouch(firstExit);
  }
  return result;
}

namespace {

using FieldAlignedCandidateResult =
    std::variant<FieldAlignedCurveNetworkCandidate,
                 FieldAlignedCurveNetworkError>;

using FieldAlignedCandidateTraceResult =
    std::variant<std::vector<FieldAlignedCandidateTrace>,
                 FieldAlignedCurveNetworkError>;

FieldAlignedCurveNetworkError field_aligned_error(
    const FieldAlignedCurveNetworkErrorCode code,
    std::optional<authority::SourceVertexId> sourceVertex = std::nullopt,
    std::optional<authority::SourceEdgeTopologyKey> sourceEdge = std::nullopt,
    std::optional<authority::HardRailId> rail = std::nullopt,
    std::optional<authority::FieldSingularityId> singularity = std::nullopt) {
  FieldAlignedCurveNetworkError error;
  error.code = code;
  error.sourceVertex = sourceVertex;
  error.sourceEdge = std::move(sourceEdge);
  error.rail = rail;
  error.singularity = singularity;
  return error;
}

template <typename Id>
Id field_aligned_id(const std::size_t value, const std::size_t extent) {
  return Id::from_index(static_cast<std::int64_t>(value), extent).value();
}

const authority::FieldBranchBoundaryPairing *field_aligned_branch_pairing(
    const authority::FieldFaceBranchFrame &frame,
    const authority::FieldBranch branch) {
  const authority::FieldBranchBoundaryPairing *result = nullptr;
  for (const authority::FieldBranchBoundaryPairing &pairing : frame.branches) {
    if (pairing.branch != branch) continue;
    if (result != nullptr) return nullptr;
    result = &pairing;
  }
  return result;
}

const authority::FieldSingularityFact *field_aligned_singularity_at(
    const authority::FieldTransportAtlas &atlas,
    const authority::SourceVertexId sourceVertex,
    const authority::SourceComponentId sourceComponent,
    const authority::TopologyRegionId topologyRegion) {
  const authority::FieldSingularityFact *result = nullptr;
  for (const authority::FieldSingularityFact &singularity : atlas.singularities()) {
    if (singularity.sourceVertex != sourceVertex ||
        singularity.sourceComponent != sourceComponent ||
        !singularity.topologyRegion.has_value() ||
        *singularity.topologyRegion != topologyRegion) {
      continue;
    }
    if (result != nullptr) return nullptr;
    result = &singularity;
  }
  return result;
}

std::optional<authority::SourceFaceTopologyKey> field_aligned_next_face(
    const authority::FieldBranchTopology &topology,
    const authority::SourceEdgeTopologyKey &carrier,
    const authority::SourceFaceTopologyKey &currentFace) {
  std::optional<authority::SourceFaceTopologyKey> result;
  for (const authority::FieldBranchTransportAdjacency &adjacency :
       topology.transports()) {
    if (adjacency.sourceEdge != carrier) continue;
    std::optional<authority::SourceFaceTopologyKey> candidate;
    if (adjacency.firstFace == currentFace) {
      candidate = adjacency.secondFace;
    } else if (adjacency.secondFace == currentFace) {
      candidate = adjacency.firstFace;
    } else {
      continue;
    }
    if (result.has_value() && *result != *candidate) return std::nullopt;
    result = std::move(candidate);
  }
  return result;
}

FieldAlignedCandidateTraceResult legacy_canonical_field_aligned_traces(
    const TriMesh &sourceMesh,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<FieldAlignedSingularityPort> &ports,
    const std::map<authority::SourceEdgeTopologyKey,
                   const authority::FieldNonTraversableEdge *> &mandatoryByEdge) {
  const authority::FieldBranchTopology &topology =
      fieldTransportAtlas.branch_topology();
  std::vector<FieldAlignedCandidateTrace> traces;
  traces.reserve(ports.size());

  for (std::size_t traceIndex = 0; traceIndex < ports.size(); ++traceIndex) {
    const FieldAlignedSingularityPort &port = ports[traceIndex];
    const authority::FieldSingularityPortAttachment *attachment = nullptr;
    for (const authority::FieldSingularityPortAttachment &candidate :
         topology.singularity_port_attachments()) {
      if (candidate.singularity != port.singularity ||
          candidate.localSlot != port.ordinal) {
        continue;
      }
      if (attachment != nullptr) {
        return field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
            port.sourceVertex, std::nullopt, std::nullopt, port.singularity);
      }
      attachment = &candidate;
    }
    if (attachment == nullptr || attachment->sourceVertex != port.sourceVertex ||
        attachment->sourceComponent != port.sourceComponent ||
        attachment->topologyRegion != port.sourceTopologyRegion) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
          port.sourceVertex, std::nullopt, std::nullopt, port.singularity);
    }

    FieldAlignedCandidateTrace trace(
        field_aligned_id<authority::TraceId>(traceIndex, ports.size()), port.id,
        port.singularity, port.sourceVertex, port.sourceComponent,
        port.sourceTopologyRegion);
    authority::SourceFaceTopologyKey currentFace = attachment->startFace;
    authority::FieldBranch currentBranch = attachment->branch;
    std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
    std::optional<FieldAlignedCandidateTraceTransition> entryTransport;
    auto currentEntryPoint =
        field_boundary_point_at_vertex(currentFace, port.sourceVertex);
    if (!currentEntryPoint.has_value()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
          port.sourceVertex, std::nullopt, std::nullopt, port.singularity);
    }

    FieldAlignedTraceTraversalGuard traversalGuard(
        field_aligned_trace_step_budget(topology));

    while (true) {
      const FieldAlignedTraceTraversalState state{
          currentFace, currentBranch, incomingCarrier, *currentEntryPoint};
      const auto traceError = [&](FieldAlignedCurveNetworkError error) {
        annotate_field_aligned_trace_seed(error, port.sourceVertex,
                                          port.singularity);
        annotate_field_aligned_trace_history(error, trace, state);
        return error;
      };
      const FieldAlignedTraceTraversalStatus traversalStatus =
          traversalGuard.observe(state);
      if (traversalStatus != FieldAlignedTraceTraversalStatus::Advanced) {
        FieldAlignedCurveNetworkError error =
            field_aligned_trace_traversal_error(traversalStatus, state,
                                                traversalGuard);
        return traceError(std::move(error));
      }

      const authority::FieldFaceBranchFrame *frame =
          topology.find_frame(currentFace);
      if (frame == nullptr || frame->sourceComponent != trace.sourceComponent ||
          frame->topologyRegion != trace.sourceTopologyRegion) {
        return traceError(field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
            port.sourceVertex, std::nullopt, std::nullopt, port.singularity));
      }
      const authority::FieldBranchBoundaryPairing *pairing =
          field_aligned_branch_pairing(*frame, currentBranch);
      if (pairing == nullptr) {
        return traceError(trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
            port.sourceVertex, port.singularity, std::nullopt, std::nullopt,
            currentFace, currentBranch));
      }

      auto continuation = resolve_field_branch_continuation(
          currentFace, *pairing, *currentEntryPoint);
      if (auto *error =
              std::get_if<FieldAlignedCurveNetworkError>(&continuation)) {
        return traceError(std::move(*error));
      }
      const FieldBranchContinuationDecision decision =
          std::get<FieldBranchContinuationDecision>(continuation);

      if (!incomingCarrier.has_value() && trace.segments.empty() &&
          decision.outgoingCarrier != attachment->firstOutgoingCarrier) {
        return traceError(trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
            port.sourceVertex, port.singularity, std::nullopt,
            decision.outgoingCarrier, currentFace, currentBranch));
      }

      trace.segments.emplace_back(
          currentFace, currentBranch, *currentEntryPoint, incomingCarrier,
          decision.outgoingCarrier, entryTransport);

      if (decision.kind == FieldBranchContinuationKind::VertexHit) {
        if (!decision.sourceVertex.has_value()) {
          return traceError(trace_scoped_field_aligned_error(
              FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
              port.sourceVertex, port.singularity, std::nullopt,
              decision.outgoingCarrier, currentFace, currentBranch));
        }
        trace.terminalPoint = decision.exitPoint;
        const authority::FieldSingularityFact *terminalSingularity =
            field_aligned_singularity_at(
                fieldTransportAtlas, *decision.sourceVertex,
                trace.sourceComponent, trace.sourceTopologyRegion);
        if (terminalSingularity != nullptr) {
          trace.terminalSingularity = terminalSingularity->id;
          break;
        }

        auto transit = resolve_field_vertex_transit(
            sourceMesh, topology, trace.sourceComponent,
            trace.sourceTopologyRegion, currentFace, currentBranch,
            *decision.sourceVertex, FieldVertexArrivalMode::FaceInterior,
            trace.id, trace.segments.size() - 1U);
        if (auto *error = std::get_if<FieldAlignedCurveNetworkError>(&transit)) {
          return traceError(std::move(*error));
        }
        const FieldVertexTransitDecision vertexTransit =
            std::get<FieldVertexTransitDecision>(transit);
        const auto nextEntryPoint = field_boundary_point_at_vertex(
            vertexTransit.nextFace, *decision.sourceVertex);
        if (!nextEntryPoint.has_value()) {
          return traceError(trace_scoped_field_aligned_error(
              FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
              port.sourceVertex, port.singularity, decision.sourceVertex,
              decision.outgoingCarrier, vertexTransit.nextFace,
              vertexTransit.nextBranch));
        }
        currentFace = vertexTransit.nextFace;
        currentBranch = vertexTransit.nextBranch;
        currentEntryPoint = nextEntryPoint;
        incomingCarrier.reset();
        entryTransport.reset();
        trace.terminalPoint.reset();
        continue;
      }

      if (mandatoryByEdge.count(decision.outgoingCarrier) != 0U) {
        trace.terminalBarrier = decision.outgoingCarrier;
        trace.terminalPoint = decision.exitPoint;
        break;
      }

      const auto nextFace =
          field_aligned_next_face(topology, decision.outgoingCarrier, currentFace);
      if (!nextFace.has_value()) {
        return traceError(trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
            port.sourceVertex, port.singularity, std::nullopt,
            decision.outgoingCarrier, currentFace, currentBranch));
      }
      const auto directed = topology.transport(
          decision.outgoingCarrier, currentFace, *nextFace);
      if (!directed.has_value()) {
        return traceError(trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
            port.sourceVertex, port.singularity, std::nullopt,
            decision.outgoingCarrier, currentFace, currentBranch));
      }
      const authority::FieldBranch nextBranch =
          currentBranch.rotated(directed->signedLift);
      const authority::FieldFaceBranchFrame *nextFrame =
          topology.find_frame(*nextFace);
      const authority::FieldBranchBoundaryPairing *nextPairing =
          nextFrame == nullptr
              ? nullptr
              : field_aligned_branch_pairing(*nextFrame, nextBranch);
      if (nextPairing == nullptr) {
        return traceError(trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
            port.sourceVertex, port.singularity, std::nullopt,
            decision.outgoingCarrier, *nextFace, nextBranch));
      }
      const FieldBranchEdgeFlowRelation targetFlow =
          classify_field_branch_transport_flow(
              currentFace, *pairing, *nextFace, *nextPairing,
              decision.outgoingCarrier);
      if (targetFlow == FieldBranchEdgeFlowRelation::Outflow) {
        auto transit = resolve_field_branch_grazing_transit(
            currentFace, *pairing, *nextFace, *nextPairing,
            decision.outgoingCarrier, directed->signedLift,
            decision.exitPoint.parameter);
        if (auto *error =
                std::get_if<FieldAlignedCurveNetworkError>(&transit)) {
          return traceError(std::move(*error));
        }
        const FieldBranchContinuationDecision edgeTransit =
            std::get<FieldBranchContinuationDecision>(transit);
        if (edgeTransit.kind != FieldBranchContinuationKind::EdgeTransit ||
            !edgeTransit.sourceVertex.has_value()) {
          return traceError(trace_scoped_field_aligned_error(
              FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
              port.sourceVertex, port.singularity, std::nullopt,
              decision.outgoingCarrier, currentFace, currentBranch));
        }
        trace.segments.back().edgeTransitExit = edgeTransit.exitPoint;
        trace.terminalPoint = edgeTransit.exitPoint;
        const authority::FieldSingularityFact *terminalSingularity =
            field_aligned_singularity_at(
                fieldTransportAtlas, *edgeTransit.sourceVertex,
                trace.sourceComponent, trace.sourceTopologyRegion);
        if (terminalSingularity != nullptr) {
          trace.terminalSingularity = terminalSingularity->id;
          break;
        }

        auto vertexTransit = resolve_field_vertex_transit(
            sourceMesh, topology, trace.sourceComponent,
            trace.sourceTopologyRegion, currentFace, currentBranch,
            *edgeTransit.sourceVertex, FieldVertexArrivalMode::EdgeTransit,
            trace.id, trace.segments.size() - 1U);
        if (auto *error =
                std::get_if<FieldAlignedCurveNetworkError>(&vertexTransit)) {
          return traceError(std::move(*error));
        }
        const FieldVertexTransitDecision next =
            std::get<FieldVertexTransitDecision>(vertexTransit);
        const auto nextEntryPoint =
            field_boundary_point_at_vertex(next.nextFace, *edgeTransit.sourceVertex);
        if (!nextEntryPoint.has_value()) {
          return traceError(trace_scoped_field_aligned_error(
              FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
              port.sourceVertex, port.singularity, edgeTransit.sourceVertex,
              decision.outgoingCarrier, next.nextFace, next.nextBranch));
        }
        currentFace = next.nextFace;
        currentBranch = next.nextBranch;
        currentEntryPoint = nextEntryPoint;
        incomingCarrier.reset();
        entryTransport.reset();
        trace.terminalPoint.reset();
        continue;
      }

      entryTransport.emplace(decision.outgoingCarrier, currentFace, *nextFace,
                             *directed);
      incomingCarrier = decision.outgoingCarrier;
      currentFace = *nextFace;
      currentBranch = nextBranch;
      currentEntryPoint = decision.exitPoint;
    }

    if (trace.segments.empty()) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          port.sourceVertex, port.singularity, std::nullopt, std::nullopt,
          currentFace, currentBranch);
    }
    traces.push_back(std::move(trace));
  }
  return traces;
}

void field_aligned_sort_event(FieldAlignedNetworkEvent &event) {
  std::sort(event.incidences.begin(), event.incidences.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.trace, lhs.sourcePort, lhs.role) <
                     std::tie(rhs.trace, rhs.sourcePort, rhs.role);
            });
}

void field_aligned_sort_events(std::vector<FieldAlignedNetworkEvent> &events) {
  for (FieldAlignedNetworkEvent &event : events) {
    field_aligned_sort_event(event);
  }
  std::sort(events.begin(), events.end(), [](const auto &lhs, const auto &rhs) {
    return std::tie(lhs.sourceFace, lhs.sourceEdge, lhs.kind, lhs.node,
                    lhs.incidences) <
           std::tie(rhs.sourceFace, rhs.sourceEdge, rhs.kind, rhs.node,
                    rhs.incidences);
  });
}

const FieldAlignedSingularityPort *field_aligned_port_for_trace(
    const FieldAlignedCurveNetworkCandidate &candidate,
    const FieldAlignedCandidateTrace &trace) {
  const auto found = std::find_if(
      candidate.singularityPorts.begin(), candidate.singularityPorts.end(),
      [&](const FieldAlignedSingularityPort &port) { return port.id == trace.port; });
  return found == candidate.singularityPorts.end() ? nullptr : &*found;
}

std::optional<authority::SourceEdgeTopologyKey> field_aligned_common_carrier(
    const FieldAlignedCandidateTraceSegment &first,
    const FieldAlignedCandidateTraceSegment &second) {
  std::vector<authority::SourceEdgeTopologyKey> firstCarriers{first.outgoingCarrier};
  if (first.incomingCarrier.has_value()) {
    firstCarriers.push_back(*first.incomingCarrier);
  }
  std::vector<authority::SourceEdgeTopologyKey> secondCarriers{
      second.outgoingCarrier};
  if (second.incomingCarrier.has_value()) {
    secondCarriers.push_back(*second.incomingCarrier);
  }
  std::sort(firstCarriers.begin(), firstCarriers.end());
  firstCarriers.erase(std::unique(firstCarriers.begin(), firstCarriers.end()),
                      firstCarriers.end());
  std::sort(secondCarriers.begin(), secondCarriers.end());
  secondCarriers.erase(
      std::unique(secondCarriers.begin(), secondCarriers.end()),
      secondCarriers.end());
  std::vector<authority::SourceEdgeTopologyKey> common;
  std::set_intersection(firstCarriers.begin(), firstCarriers.end(),
                        secondCarriers.begin(), secondCarriers.end(),
                        std::back_inserter(common));
  return common.empty()
             ? std::optional<authority::SourceEdgeTopologyKey>{}
             : std::optional<authority::SourceEdgeTopologyKey>{common.front()};
}

struct FieldAlignedTraceContact {
  std::size_t segmentIndex = 0U;
  std::size_t existingTraceIndex = 0U;
  std::size_t existingSegmentIndex = 0U;
  authority::SourceFaceTopologyKey sourceFace;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
};

std::optional<FieldAlignedTraceContact> field_aligned_first_trace_contact(
    const std::vector<FieldAlignedCandidateTrace> &traces,
    const std::size_t traceIndex) {
  const FieldAlignedCandidateTrace &trace = traces[traceIndex];
  for (std::size_t segmentIndex = 0U; segmentIndex < trace.segments.size();
       ++segmentIndex) {
    const FieldAlignedCandidateTraceSegment &segment = trace.segments[segmentIndex];
    for (std::size_t existingIndex = 0U; existingIndex < traceIndex;
         ++existingIndex) {
      const FieldAlignedCandidateTrace &existing = traces[existingIndex];
      for (std::size_t existingSegmentIndex = 0U;
           existingSegmentIndex < existing.segments.size();
           ++existingSegmentIndex) {
        const FieldAlignedCandidateTraceSegment &existingSegment =
            existing.segments[existingSegmentIndex];
        if (segment.sourceFace != existingSegment.sourceFace) continue;
        // A shared singularity origin is declared independently as an explicit
        // junction event; it is not a terminal first contact for either ray.
        if (segmentIndex == 0U && existingSegmentIndex == 0U &&
            trace.singularity == existing.singularity &&
            trace.sourceVertex == existing.sourceVertex) {
          continue;
        }
        return FieldAlignedTraceContact{
            segmentIndex, existingIndex, existingSegmentIndex,
            segment.sourceFace,
            field_aligned_common_carrier(segment, existingSegment)};
      }
    }
  }
  return std::nullopt;
}

std::optional<bool> field_aligned_segments_properly_cross(
    const authority::FieldBranchTopology &topology,
    const FieldAlignedCandidateTraceSegment &first,
    const FieldAlignedCandidateTraceSegment &second) {
  if (first.sourceFace != second.sourceFace) return false;

  const auto segment_exit = [&](
                                const FieldAlignedCandidateTraceSegment &segment)
      -> std::optional<authority::FieldBoundaryPoint> {
    const authority::FieldFaceBranchFrame *frame =
        topology.find_frame(segment.sourceFace);
    const authority::FieldBranchBoundaryPairing *pairing =
        frame == nullptr ? nullptr
                         : field_aligned_branch_pairing(*frame, segment.branch);
    if (pairing == nullptr) return std::nullopt;
    FieldBranchContinuationResult continuation =
        resolve_field_branch_continuation(segment.sourceFace, *pairing,
                                          segment.entryPoint);
    const auto *decision =
        std::get_if<FieldBranchContinuationDecision>(&continuation);
    return decision == nullptr
               ? std::optional<authority::FieldBoundaryPoint>{}
               : std::optional<authority::FieldBoundaryPoint>{
                     decision->exitPoint};
  };

  const auto firstEntry =
      field_boundary_point_barycentric(first.sourceFace, first.entryPoint);
  const auto secondEntry =
      field_boundary_point_barycentric(second.sourceFace, second.entryPoint);
  const auto firstExitPoint = segment_exit(first);
  const auto secondExitPoint = segment_exit(second);
  if (!firstEntry.has_value() || !secondEntry.has_value() ||
      !firstExitPoint.has_value() || !secondExitPoint.has_value()) {
    return std::nullopt;
  }
  const auto firstExit =
      field_boundary_point_barycentric(first.sourceFace, *firstExitPoint);
  const auto secondExit =
      field_boundary_point_barycentric(second.sourceFace, *secondExitPoint);
  if (!firstExit.has_value() || !secondExit.has_value()) return std::nullopt;

  const auto orient = [](
                          const std::array<authority::FieldExactRational, 3> &a,
                          const std::array<authority::FieldExactRational, 3> &b,
                          const std::array<authority::FieldExactRational, 3> &c) {
    return (b[0] - a[0]) * (c[1] - a[1]) -
           (b[1] - a[1]) * (c[0] - a[0]);
  };
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto abFirst = orient(*firstEntry, *firstExit, *secondEntry);
  const auto abSecond = orient(*firstEntry, *firstExit, *secondExit);
  const auto cdFirst = orient(*secondEntry, *secondExit, *firstEntry);
  const auto cdSecond = orient(*secondEntry, *secondExit, *firstExit);
  if (abFirst == zero || abSecond == zero || cdFirst == zero ||
      cdSecond == zero) {
    return false;
  }
  const bool abOpposite = (abFirst < zero) != (abSecond < zero);
  const bool cdOpposite = (cdFirst < zero) != (cdSecond < zero);
  return abOpposite && cdOpposite;
}

FieldAlignedContactCensusPriorTerminalKind field_aligned_prior_terminal_kind(
    const FieldAlignedCandidateTrace &trace) {
  if (trace.terminalSingularity.has_value()) {
    return FieldAlignedContactCensusPriorTerminalKind::Singularity;
  }
  if (trace.terminalBarrier.has_value()) {
    return FieldAlignedContactCensusPriorTerminalKind::Barrier;
  }
  return FieldAlignedContactCensusPriorTerminalKind::None;
}

std::optional<authority::NetworkNodeId> field_aligned_append_contact_node(
    FieldAlignedCurveNetworkCandidate &candidate,
    const authority::SourceFaceTopologyKey &sourceFace) {
  const std::size_t nodeIndex = candidate.nodes.size();
  const auto node = authority::NetworkNodeId::from_index(
      static_cast<std::int64_t>(nodeIndex), nodeIndex + 1U);
  if (!node) return std::nullopt;
  // `sourceVertex` remains source-topology provenance only. Exact contact
  // position lives on FieldAlignedCandidateTrace::terminalContact and neither
  // NetworkNodeId nor this provenance field acquires positional meaning.
  candidate.nodes.emplace_back(node.value(), sourceFace.vertices().front());
  return node.value();
}


struct FieldAlignedFilteredScalar {
  double value = 0.0;
  double bound = 0.0;
};

double field_aligned_rounding_bound(const double value) noexcept {
  if (!std::isfinite(value)) return std::numeric_limits<double>::infinity();
  const double up = std::nextafter(value, std::numeric_limits<double>::infinity());
  const double down = std::nextafter(value, -std::numeric_limits<double>::infinity());
  return std::max(std::abs(up - value), std::abs(value - down));
}

FieldAlignedFilteredScalar field_aligned_filtered_add(
    const FieldAlignedFilteredScalar first,
    const FieldAlignedFilteredScalar second) noexcept {
  const double value = first.value + second.value;
  return {value, first.bound + second.bound + field_aligned_rounding_bound(value)};
}

FieldAlignedFilteredScalar field_aligned_filtered_subtract(
    const FieldAlignedFilteredScalar first,
    const FieldAlignedFilteredScalar second) noexcept {
  const double value = first.value - second.value;
  return {value, first.bound + second.bound + field_aligned_rounding_bound(value)};
}

FieldAlignedFilteredScalar field_aligned_filtered_multiply(
    const FieldAlignedFilteredScalar first,
    const FieldAlignedFilteredScalar second) noexcept {
  const double value = first.value * second.value;
  const double propagated = std::abs(first.value) * second.bound +
                            std::abs(second.value) * first.bound +
                            first.bound * second.bound;
  return {value, propagated + field_aligned_rounding_bound(value)};
}

FieldAlignedFilteredScalar field_aligned_filtered_sqrt(
    const FieldAlignedFilteredScalar input) noexcept {
  if (input.value < 0.0 || !std::isfinite(input.value) ||
      !std::isfinite(input.bound)) {
    return {std::numeric_limits<double>::infinity(),
            std::numeric_limits<double>::infinity()};
  }
  const double value = std::sqrt(input.value);
  const double lower = std::sqrt(std::max(0.0, input.value - input.bound));
  const double upper = std::sqrt(std::max(0.0, input.value + input.bound));
  const double propagated = std::max(value - lower, upper - value);
  return {value, propagated + field_aligned_rounding_bound(value)};
}

FieldAlignedFilteredScalar field_aligned_filtered_exact(
    const authority::FieldExactRational &value) noexcept {
  const double converted = static_cast<double>(
      value.to_double(std::numeric_limits<double>::max_digits10));
  return {converted, field_aligned_rounding_bound(converted)};
}

std::optional<authority::FieldBoundaryPoint> field_aligned_segment_exit_point(
    const authority::FieldBranchTopology &topology,
    const FieldAlignedCandidateTraceSegment &segment) {
  const authority::FieldFaceBranchFrame *frame =
      topology.find_frame(segment.sourceFace);
  const authority::FieldBranchBoundaryPairing *pairing =
      frame == nullptr ? nullptr
                       : field_aligned_branch_pairing(*frame, segment.branch);
  if (pairing == nullptr) return std::nullopt;
  FieldBranchContinuationResult continuation =
      resolve_field_branch_continuation(segment.sourceFace, *pairing,
                                        segment.entryPoint);
  const auto *decision = std::get_if<FieldBranchContinuationDecision>(&continuation);
  return decision == nullptr
             ? std::optional<authority::FieldBoundaryPoint>{}
             : std::optional<authority::FieldBoundaryPoint>{decision->exitPoint};
}

FieldAlignedSegmentContactClassification
classify_field_aligned_segment_contact_with_second_exit(
    const authority::FieldBranchTopology &topology,
    const FieldAlignedCandidateTraceSegment &first,
    const FieldAlignedCandidateTraceSegment &second,
    const std::optional<std::array<authority::FieldExactRational, 3>>
        &secondExitOverride = std::nullopt) {
  FieldAlignedSegmentContactClassification result;
  if (first.sourceFace != second.sourceFace) return result;

  const auto firstEntry =
      field_boundary_point_barycentric(first.sourceFace, first.entryPoint);
  const auto secondEntry =
      field_boundary_point_barycentric(second.sourceFace, second.entryPoint);
  const auto firstExitPoint = field_aligned_segment_exit_point(topology, first);
  const auto secondExitPoint = secondExitOverride.has_value()
                                   ? std::optional<authority::FieldBoundaryPoint>{}
                                   : field_aligned_segment_exit_point(topology, second);
  if (!firstEntry.has_value() || !secondEntry.has_value() ||
      !firstExitPoint.has_value() ||
      (!secondExitOverride.has_value() && !secondExitPoint.has_value())) {
    result.kind = FieldAlignedSegmentContactKind::Unevaluated;
    return result;
  }
  const auto firstExit =
      field_boundary_point_barycentric(first.sourceFace, *firstExitPoint);
  const auto secondExit = secondExitOverride.has_value()
                              ? secondExitOverride
                              : field_boundary_point_barycentric(
                                    second.sourceFace, *secondExitPoint);
  if (!firstExit.has_value() || !secondExit.has_value()) {
    result.kind = FieldAlignedSegmentContactKind::Unevaluated;
    return result;
  }
  return classify_field_aligned_barycentric_contact(
      *firstEntry, *firstExit, *secondEntry, *secondExit);
}

FieldAlignedSegmentContactClassification
classify_field_aligned_segment_contact_impl(
    const authority::FieldBranchTopology &topology,
    const FieldAlignedCandidateTraceSegment &first,
    const FieldAlignedCandidateTraceSegment &second) {
  return classify_field_aligned_segment_contact_with_second_exit(
      topology, first, second);
}

std::optional<std::array<FieldAlignedFilteredScalar, 3>>
field_aligned_filtered_position(
    const TriMesh &sourceMesh,
    const authority::SourceFaceTopologyKey &sourceFace,
    const std::array<authority::FieldExactRational, 3> &barycentric) {
  std::array<FieldAlignedFilteredScalar, 3> position{};
  const auto &vertices = sourceFace.vertices();
  for (std::size_t axis = 0U; axis < 3U; ++axis) {
    FieldAlignedFilteredScalar coordinate{};
    for (std::size_t corner = 0U; corner < 3U; ++corner) {
      const std::size_t row = vertices[corner].index();
      if (row >= static_cast<std::size_t>(sourceMesh.V.rows())) return std::nullopt;
      const FieldAlignedFilteredScalar weight =
          field_aligned_filtered_exact(barycentric[corner]);
      const FieldAlignedFilteredScalar source{
          sourceMesh.V(static_cast<int>(row), static_cast<int>(axis)), 0.0};
      coordinate = field_aligned_filtered_add(
          coordinate, field_aligned_filtered_multiply(weight, source));
    }
    position[axis] = coordinate;
  }
  return position;
}

std::optional<FieldAlignedFilteredScalar> field_aligned_filtered_length(
    const TriMesh &sourceMesh,
    const authority::SourceFaceTopologyKey &sourceFace,
    const std::array<authority::FieldExactRational, 3> &first,
    const std::array<authority::FieldExactRational, 3> &second) {
  const auto firstPosition =
      field_aligned_filtered_position(sourceMesh, sourceFace, first);
  const auto secondPosition =
      field_aligned_filtered_position(sourceMesh, sourceFace, second);
  if (!firstPosition.has_value() || !secondPosition.has_value()) return std::nullopt;
  FieldAlignedFilteredScalar squared{};
  for (std::size_t axis = 0U; axis < 3U; ++axis) {
    const auto difference = field_aligned_filtered_subtract(
        (*secondPosition)[axis], (*firstPosition)[axis]);
    squared = field_aligned_filtered_add(
        squared, field_aligned_filtered_multiply(difference, difference));
  }
  return field_aligned_filtered_sqrt(squared);
}

FieldAlignedArrivalMeasure field_aligned_arrival_advance(
    const FieldAlignedArrivalMeasure start,
    const FieldAlignedFilteredScalar length) noexcept {
  const double value = start.value + length.value;
  return FieldAlignedArrivalMeasure{
      value, start.bound + length.bound + field_aligned_rounding_bound(value),
      start.segmentCount + 1U};
}

std::optional<FieldAlignedArrivalMeasure> field_aligned_arrival_at_barycentric(
    const TriMesh &sourceMesh,
    const FieldAlignedCandidateTraceSegment &segment,
    const FieldAlignedArrivalMeasure start,
    const std::array<authority::FieldExactRational, 3> &point) {
  const auto entry =
      field_boundary_point_barycentric(segment.sourceFace, segment.entryPoint);
  if (!entry.has_value()) return std::nullopt;
  const auto length = field_aligned_filtered_length(
      sourceMesh, segment.sourceFace, *entry, point);
  return length.has_value()
             ? std::optional<FieldAlignedArrivalMeasure>{
                   field_aligned_arrival_advance(start, *length)}
             : std::nullopt;
}

enum class FieldAlignedProposalDisposition : std::uint8_t {
  Advance = 0,
  TerminalSingularity = 1,
  TerminalBarrier = 2,
};

struct FieldAlignedTraceProposal {
  explicit FieldAlignedTraceProposal(FieldAlignedCandidateTraceSegment value)
      : segment(std::move(value)) {}

  FieldAlignedCandidateTraceSegment segment;
  FieldAlignedProposalDisposition disposition =
      FieldAlignedProposalDisposition::Advance;
  std::optional<authority::SourceFaceTopologyKey> nextFace;
  std::optional<authority::FieldBranch> nextBranch;
  std::optional<authority::FieldBoundaryPoint> nextEntryPoint;
  std::optional<authority::SourceEdgeTopologyKey> nextIncomingCarrier;
  std::optional<FieldAlignedCandidateTraceTransition> nextEntryTransport;
  std::optional<authority::FieldSingularityId> terminalSingularity;
  std::optional<authority::SourceEdgeTopologyKey> terminalBarrier;
  std::optional<authority::FieldBoundaryPoint> terminalPoint;
  FieldAlignedArrivalMeasure endArrival;
};

struct FieldAlignedTraceRuntime {
  FieldAlignedTraceRuntime(
      const authority::SourceFaceTopologyKey &face,
      const authority::FieldBranch branch,
      const authority::FieldBoundaryPoint &entry,
      const std::size_t stepBudget)
      : currentFace(face), currentBranch(branch), currentEntryPoint(entry),
        traversalGuard(stepBudget) {}

  authority::SourceFaceTopologyKey currentFace;
  authority::FieldBranch currentBranch;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  std::optional<FieldAlignedCandidateTraceTransition> entryTransport;
  authority::FieldBoundaryPoint currentEntryPoint;
  FieldAlignedTraceTraversalGuard traversalGuard;
  FieldAlignedArrivalMeasure arrival;
  bool active = true;
  std::optional<FieldAlignedTraceProposal> proposal;
  std::vector<FieldAlignedArrivalMeasure> segmentStarts;
};

using FieldAlignedTraceProposalResult =
    std::variant<FieldAlignedTraceProposal, FieldAlignedCurveNetworkError>;

FieldAlignedTraceProposalResult field_aligned_next_trace_proposal(
    const TriMesh &sourceMesh,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::map<authority::SourceEdgeTopologyKey,
                   const authority::FieldNonTraversableEdge *> &mandatoryByEdge,
    FieldAlignedCandidateTrace &trace,
    FieldAlignedTraceRuntime &runtime) {
  const authority::FieldBranchTopology &topology =
      fieldTransportAtlas.branch_topology();
  const FieldAlignedTraceTraversalState state{
      runtime.currentFace, runtime.currentBranch, runtime.incomingCarrier,
      runtime.currentEntryPoint};
  const auto traceError = [&](FieldAlignedCurveNetworkError error) {
    annotate_field_aligned_trace_seed(error, trace.sourceVertex, trace.singularity);
    annotate_field_aligned_trace_history(error, trace, state);
    return error;
  };
  const FieldAlignedTraceTraversalStatus traversalStatus =
      runtime.traversalGuard.observe(state);
  if (traversalStatus != FieldAlignedTraceTraversalStatus::Advanced) {
    return traceError(field_aligned_trace_traversal_error(
        traversalStatus, state, runtime.traversalGuard));
  }

  const authority::FieldFaceBranchFrame *frame =
      topology.find_frame(runtime.currentFace);
  if (frame == nullptr || frame->sourceComponent != trace.sourceComponent ||
      frame->topologyRegion != trace.sourceTopologyRegion) {
    return traceError(field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
        trace.sourceVertex, std::nullopt, std::nullopt, trace.singularity));
  }
  const authority::FieldBranchBoundaryPairing *pairing =
      field_aligned_branch_pairing(*frame, runtime.currentBranch);
  if (pairing == nullptr) {
    return traceError(trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
        trace.sourceVertex, trace.singularity, std::nullopt, std::nullopt,
        runtime.currentFace, runtime.currentBranch));
  }

  auto continuation = resolve_field_branch_continuation(
      runtime.currentFace, *pairing, runtime.currentEntryPoint);
  if (auto *error = std::get_if<FieldAlignedCurveNetworkError>(&continuation)) {
    return traceError(std::move(*error));
  }
  const FieldBranchContinuationDecision decision =
      std::get<FieldBranchContinuationDecision>(continuation);

  FieldAlignedCandidateTraceSegment segment(
      runtime.currentFace, runtime.currentBranch, runtime.currentEntryPoint,
      runtime.incomingCarrier, decision.outgoingCarrier, runtime.entryTransport);
  FieldAlignedTraceProposal proposal(std::move(segment));

  const auto entryBarycentric = field_boundary_point_barycentric(
      runtime.currentFace, runtime.currentEntryPoint);
  const auto exitBarycentric = field_boundary_point_barycentric(
      runtime.currentFace, decision.exitPoint);
  if (!entryBarycentric.has_value() || !exitBarycentric.has_value()) {
    return traceError(trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
        trace.sourceVertex, trace.singularity, std::nullopt,
        decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
  }
  auto segmentLength = field_aligned_filtered_length(
      sourceMesh, runtime.currentFace, *entryBarycentric, *exitBarycentric);
  if (!segmentLength.has_value()) {
    return traceError(trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
        trace.sourceVertex, trace.singularity, std::nullopt,
        decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
  }

  if (decision.kind == FieldBranchContinuationKind::VertexHit) {
    if (!decision.sourceVertex.has_value()) {
      return traceError(trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, std::nullopt,
          decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
    }
    proposal.terminalPoint = decision.exitPoint;
    const authority::FieldSingularityFact *terminalSingularity =
        field_aligned_singularity_at(
            fieldTransportAtlas, *decision.sourceVertex, trace.sourceComponent,
            trace.sourceTopologyRegion);
    if (terminalSingularity != nullptr) {
      proposal.disposition = FieldAlignedProposalDisposition::TerminalSingularity;
      proposal.terminalSingularity = terminalSingularity->id;
      proposal.endArrival =
          field_aligned_arrival_advance(runtime.arrival, *segmentLength);
      return proposal;
    }

    auto transit = resolve_field_vertex_transit(
        sourceMesh, topology, trace.sourceComponent, trace.sourceTopologyRegion,
        runtime.currentFace, runtime.currentBranch, *decision.sourceVertex,
        FieldVertexArrivalMode::FaceInterior, trace.id, trace.segments.size());
    if (auto *error = std::get_if<FieldAlignedCurveNetworkError>(&transit)) {
      return traceError(std::move(*error));
    }
    const FieldVertexTransitDecision vertexTransit =
        std::get<FieldVertexTransitDecision>(transit);
    const auto nextEntryPoint = field_boundary_point_at_vertex(
        vertexTransit.nextFace, *decision.sourceVertex);
    if (!nextEntryPoint.has_value()) {
      return traceError(trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, decision.sourceVertex,
          decision.outgoingCarrier, vertexTransit.nextFace,
          vertexTransit.nextBranch));
    }
    proposal.nextFace = vertexTransit.nextFace;
    proposal.nextBranch = vertexTransit.nextBranch;
    proposal.nextEntryPoint = *nextEntryPoint;
    proposal.endArrival =
        field_aligned_arrival_advance(runtime.arrival, *segmentLength);
    return proposal;
  }

  if (mandatoryByEdge.count(decision.outgoingCarrier) != 0U) {
    proposal.disposition = FieldAlignedProposalDisposition::TerminalBarrier;
    proposal.terminalBarrier = decision.outgoingCarrier;
    proposal.terminalPoint = decision.exitPoint;
    proposal.endArrival =
        field_aligned_arrival_advance(runtime.arrival, *segmentLength);
    return proposal;
  }

  const auto nextFace =
      field_aligned_next_face(topology, decision.outgoingCarrier,
                              runtime.currentFace);
  if (!nextFace.has_value()) {
    return traceError(trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
        trace.sourceVertex, trace.singularity, std::nullopt,
        decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
  }
  const auto directed = topology.transport(decision.outgoingCarrier,
                                           runtime.currentFace, *nextFace);
  if (!directed.has_value()) {
    return traceError(trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
        trace.sourceVertex, trace.singularity, std::nullopt,
        decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
  }
  const authority::FieldBranch nextBranch =
      runtime.currentBranch.rotated(directed->signedLift);
  const authority::FieldFaceBranchFrame *nextFrame = topology.find_frame(*nextFace);
  const authority::FieldBranchBoundaryPairing *nextPairing =
      nextFrame == nullptr ? nullptr
                           : field_aligned_branch_pairing(*nextFrame, nextBranch);
  if (nextPairing == nullptr) {
    return traceError(trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
        trace.sourceVertex, trace.singularity, std::nullopt,
        decision.outgoingCarrier, *nextFace, nextBranch));
  }
  const FieldBranchEdgeFlowRelation targetFlow =
      classify_field_branch_transport_flow(
          runtime.currentFace, *pairing, *nextFace, *nextPairing,
          decision.outgoingCarrier);
  if (targetFlow == FieldBranchEdgeFlowRelation::Outflow) {
    auto transit = resolve_field_branch_grazing_transit(
        runtime.currentFace, *pairing, *nextFace, *nextPairing,
        decision.outgoingCarrier, directed->signedLift,
        decision.exitPoint.parameter);
    if (auto *error = std::get_if<FieldAlignedCurveNetworkError>(&transit)) {
      return traceError(std::move(*error));
    }
    const FieldBranchContinuationDecision edgeTransit =
        std::get<FieldBranchContinuationDecision>(transit);
    if (edgeTransit.kind != FieldBranchContinuationKind::EdgeTransit ||
        !edgeTransit.sourceVertex.has_value()) {
      return traceError(trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, std::nullopt,
          decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
    }
    proposal.segment.edgeTransitExit = edgeTransit.exitPoint;
    proposal.terminalPoint = edgeTransit.exitPoint;
    const auto transitExitBarycentric = field_boundary_point_barycentric(
        runtime.currentFace, edgeTransit.exitPoint);
    if (!transitExitBarycentric.has_value()) {
      return traceError(trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, edgeTransit.sourceVertex,
          decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
    }
    const auto transitLength = field_aligned_filtered_length(
        sourceMesh, runtime.currentFace, *exitBarycentric,
        *transitExitBarycentric);
    if (!transitLength.has_value()) {
      return traceError(trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, edgeTransit.sourceVertex,
          decision.outgoingCarrier, runtime.currentFace, runtime.currentBranch));
    }
    segmentLength = field_aligned_filtered_add(*segmentLength, *transitLength);

    const authority::FieldSingularityFact *terminalSingularity =
        field_aligned_singularity_at(
            fieldTransportAtlas, *edgeTransit.sourceVertex,
            trace.sourceComponent, trace.sourceTopologyRegion);
    if (terminalSingularity != nullptr) {
      proposal.disposition = FieldAlignedProposalDisposition::TerminalSingularity;
      proposal.terminalSingularity = terminalSingularity->id;
      proposal.endArrival =
          field_aligned_arrival_advance(runtime.arrival, *segmentLength);
      return proposal;
    }

    auto vertexTransit = resolve_field_vertex_transit(
        sourceMesh, topology, trace.sourceComponent, trace.sourceTopologyRegion,
        runtime.currentFace, runtime.currentBranch, *edgeTransit.sourceVertex,
        FieldVertexArrivalMode::EdgeTransit, trace.id, trace.segments.size());
    if (auto *error = std::get_if<FieldAlignedCurveNetworkError>(&vertexTransit)) {
      return traceError(std::move(*error));
    }
    const FieldVertexTransitDecision next =
        std::get<FieldVertexTransitDecision>(vertexTransit);
    const auto nextEntryPoint =
        field_boundary_point_at_vertex(next.nextFace, *edgeTransit.sourceVertex);
    if (!nextEntryPoint.has_value()) {
      return traceError(trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, edgeTransit.sourceVertex,
          decision.outgoingCarrier, next.nextFace, next.nextBranch));
    }
    proposal.nextFace = next.nextFace;
    proposal.nextBranch = next.nextBranch;
    proposal.nextEntryPoint = *nextEntryPoint;
    proposal.endArrival =
        field_aligned_arrival_advance(runtime.arrival, *segmentLength);
    return proposal;
  }

  proposal.nextFace = *nextFace;
  proposal.nextBranch = nextBranch;
  proposal.nextEntryPoint = decision.exitPoint;
  proposal.nextIncomingCarrier = decision.outgoingCarrier;
  proposal.nextEntryTransport.emplace(
      decision.outgoingCarrier, runtime.currentFace, *nextFace, *directed);
  proposal.endArrival =
      field_aligned_arrival_advance(runtime.arrival, *segmentLength);
  return proposal;
}

void field_aligned_publish_origin_events(
    FieldAlignedCurveNetworkCandidate &candidate,
    const std::vector<FieldAlignedTraceRuntime> &runtimes) {
  std::map<authority::NetworkNodeId, std::vector<std::size_t>> tracesByNode;
  for (std::size_t traceIndex = 0U;
       traceIndex < candidate.candidateTraces.size(); ++traceIndex) {
    const auto *port = field_aligned_port_for_trace(
        candidate, candidate.candidateTraces[traceIndex]);
    if (port != nullptr) tracesByNode[port->node].push_back(traceIndex);
  }
  for (const auto &[node, traceIndices] : tracesByNode) {
    if (traceIndices.empty()) continue;
    const FieldAlignedCandidateTrace &firstTrace =
        candidate.candidateTraces[traceIndices.front()];
    const FieldAlignedSingularityPort *firstPort =
        field_aligned_port_for_trace(candidate, firstTrace);
    if (firstPort == nullptr) continue;
    authority::SourceFaceTopologyKey sourceFace =
        runtimes[traceIndices.front()].currentFace;
    std::vector<FieldAlignedNetworkEventIncidence> origins;
    std::vector<FieldAlignedNetworkEventIncidence> junction;
    origins.reserve(traceIndices.size());
    junction.reserve(traceIndices.size());
    for (const std::size_t traceIndex : traceIndices) {
      sourceFace = std::min(sourceFace, runtimes[traceIndex].currentFace);
      const auto &trace = candidate.candidateTraces[traceIndex];
      origins.emplace_back(trace.id, trace.port, FieldAlignedTraceEventRole::Origin);
      junction.emplace_back(trace.id, trace.port,
                            FieldAlignedTraceEventRole::Interior);
    }
    candidate.events.emplace_back(
        node, FieldAlignedNetworkEventKind::SingularityPortOrigin, sourceFace,
        std::nullopt, std::move(origins));
    if (traceIndices.size() > 1U) {
      candidate.events.emplace_back(
          node, FieldAlignedNetworkEventKind::SingularityPortJunction,
          sourceFace, std::nullopt, std::move(junction));
    }
  }
}

std::optional<FieldAlignedCurveNetworkError>
field_aligned_publish_barrier_termination(
    FieldAlignedCurveNetworkCandidate &candidate,
    const FieldAlignedCandidateTrace &trace) {
  if (!trace.terminalBarrier.has_value() || !trace.terminalPoint.has_value() ||
      trace.segments.empty()) {
    return trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
        trace.sourceVertex, trace.singularity);
  }
  const auto mandatory = std::find_if(
      candidate.mandatoryEdges.begin(), candidate.mandatoryEdges.end(),
      [&](const FieldAlignedMandatoryEdge &edge) {
        return edge.sourceEdge == *trace.terminalBarrier;
      });
  if (mandatory == candidate.mandatoryEdges.end()) {
    return trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
        trace.sourceVertex, trace.singularity, std::nullopt,
        trace.terminalBarrier, trace.segments.back().sourceFace,
        trace.segments.back().branch);
  }
  const authority::SourceFaceTopologyKey sourceFace =
      trace.segments.back().sourceFace;
  const auto terminalNode =
      field_aligned_append_contact_node(candidate, sourceFace);
  if (!terminalNode.has_value()) {
    return trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
        trace.sourceVertex, trace.singularity, std::nullopt,
        trace.terminalBarrier, sourceFace, trace.segments.back().branch);
  }
  candidate.events.emplace_back(
      *terminalNode, FieldAlignedNetworkEventKind::FirstContact, sourceFace,
      trace.terminalBarrier,
      std::vector<FieldAlignedNetworkEventIncidence>{
          FieldAlignedNetworkEventIncidence(
              trace.id, trace.port, FieldAlignedTraceEventRole::Interior)});
  candidate.events.emplace_back(
      *terminalNode, FieldAlignedNetworkEventKind::MandatoryBarrierTermination,
      sourceFace, trace.terminalBarrier,
      std::vector<FieldAlignedNetworkEventIncidence>{
          FieldAlignedNetworkEventIncidence(
              trace.id, trace.port, FieldAlignedTraceEventRole::Terminal)});
  return std::nullopt;
}

FieldAlignedArrivalOrdering field_aligned_compare_priority_arrivals(
    const FieldTraceArrivalPriority priority,
    const FieldAlignedArrivalMeasure &first,
    const FieldAlignedArrivalMeasure &second,
    const std::size_t firstTraceIndex,
    const std::size_t secondTraceIndex) noexcept {
  switch (priority) {
  case FieldTraceArrivalPriority::ArcLengthFiltered:
    return field_aligned_compare_arrivals(first, second);
  case FieldTraceArrivalPriority::StepCount:
    if (first.segmentCount < second.segmentCount)
      return FieldAlignedArrivalOrdering::Earlier;
    if (first.segmentCount > second.segmentCount)
      return FieldAlignedArrivalOrdering::Later;
    return FieldAlignedArrivalOrdering::Inconclusive;
  case FieldTraceArrivalPriority::BarycentricTime:
    if (first.value < second.value) return FieldAlignedArrivalOrdering::Earlier;
    if (first.value > second.value) return FieldAlignedArrivalOrdering::Later;
    return FieldAlignedArrivalOrdering::Inconclusive;
  case FieldTraceArrivalPriority::TraceSeniority:
    if (firstTraceIndex < secondTraceIndex)
      return FieldAlignedArrivalOrdering::Earlier;
    if (firstTraceIndex > secondTraceIndex)
      return FieldAlignedArrivalOrdering::Later;
    return FieldAlignedArrivalOrdering::Inconclusive;
  }
  return FieldAlignedArrivalOrdering::Inconclusive;
}

double field_aligned_priority_key(
    const FieldTraceArrivalPriority priority,
    const FieldAlignedArrivalMeasure &arrival,
    const std::size_t traceIndex) noexcept {
  switch (priority) {
  case FieldTraceArrivalPriority::ArcLengthFiltered:
  case FieldTraceArrivalPriority::BarycentricTime:
    return arrival.value;
  case FieldTraceArrivalPriority::StepCount:
    return static_cast<double>(arrival.segmentCount);
  case FieldTraceArrivalPriority::TraceSeniority:
    return static_cast<double>(traceIndex);
  }
  return arrival.value;
}

enum class FieldAlignedQueueEventKind : std::uint8_t {
  Contact = 0,
  SegmentEnd = 1,
};

struct FieldAlignedQueueEvent {
  explicit FieldAlignedQueueEvent(
      const authority::SourceFaceTopologyKey &face)
      : sourceFace(face) {}

  FieldAlignedQueueEventKind kind = FieldAlignedQueueEventKind::SegmentEnd;
  double key = 0.0;
  std::size_t firstTrace = 0U;
  std::size_t secondTrace = 0U;
  std::size_t secondSegment = 0U;
  bool secondIsProposal = false;
  FieldAlignedArrivalOrdering ordering =
      FieldAlignedArrivalOrdering::Inconclusive;
  authority::SourceFaceTopologyKey sourceFace;
  std::array<authority::FieldExactRational, 3> barycentric{};
};

struct FieldAlignedQueueEventLaterFirst {
  bool operator()(const FieldAlignedQueueEvent &first,
                  const FieldAlignedQueueEvent &second) const noexcept {
    if (first.key != second.key) return first.key > second.key;
    if (first.kind != second.kind) return first.kind > second.kind;
    if (first.sourceFace != second.sourceFace)
      return first.sourceFace > second.sourceFace;
    if (first.firstTrace != second.firstTrace)
      return first.firstTrace > second.firstTrace;
    if (first.secondTrace != second.secondTrace)
      return first.secondTrace > second.secondTrace;
    return first.secondSegment > second.secondSegment;
  }
};

void field_aligned_commit_current_proposal(
    FieldAlignedCurveNetworkCandidate &candidate,
    std::vector<FieldAlignedTraceRuntime> &runtimes,
    const std::size_t traceIndex) {
  FieldAlignedCandidateTrace &trace = candidate.candidateTraces[traceIndex];
  FieldAlignedTraceRuntime &runtime = runtimes[traceIndex];
  runtime.segmentStarts.push_back(runtime.arrival);
  trace.segments.push_back(runtime.proposal->segment);
}

std::optional<FieldAlignedCurveNetworkError> field_aligned_publish_contact(
    FieldAlignedCurveNetworkCandidate &candidate,
    std::vector<FieldAlignedTraceRuntime> &runtimes,
    const FieldAlignedQueueEvent &event) {
  const std::size_t firstIndex = event.firstTrace;
  const std::size_t secondIndex = event.secondTrace;
  FieldAlignedCandidateTrace &firstTrace = candidate.candidateTraces[firstIndex];
  FieldAlignedCandidateTrace &secondTrace = candidate.candidateTraces[secondIndex];
  FieldAlignedTraceRuntime &firstRuntime = runtimes[firstIndex];
  FieldAlignedTraceRuntime &secondRuntime = runtimes[secondIndex];
  const std::size_t firstPendingSegmentIndex = firstTrace.segments.size();
  const std::size_t secondPendingSegmentIndex = secondTrace.segments.size();

  const bool selfContact = firstIndex == secondIndex;
  const FieldAlignedContactTerminationDecision termination =
      field_aligned_contact_termination_decision(event.ordering, selfContact);
  const bool terminateFirst = termination.terminateFirst;
  const bool terminateSecond = termination.terminateSecond;

  if (terminateFirst && firstRuntime.active) {
    if (!firstRuntime.proposal.has_value()) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
          firstTrace.sourceVertex, firstTrace.singularity);
    }
    const std::size_t struckSegment =
        event.secondIsProposal ? secondPendingSegmentIndex : event.secondSegment;
    field_aligned_commit_current_proposal(candidate, runtimes, firstIndex);
    firstTrace.terminalBarrier.reset();
    firstTrace.terminalPoint.reset();
    firstTrace.terminalSingularity.reset();
    firstTrace.terminalContact = FieldAlignedTerminalContact{
        event.sourceFace, event.barycentric, secondTrace.id, struckSegment};
    firstRuntime.active = false;
    firstRuntime.proposal.reset();
  }

  if (!selfContact && terminateSecond && secondRuntime.active) {
    if (event.secondIsProposal) {
      if (!secondRuntime.proposal.has_value()) {
        return trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
            secondTrace.sourceVertex, secondTrace.singularity);
      }
      const std::size_t struckSegment = firstPendingSegmentIndex;
      field_aligned_commit_current_proposal(candidate, runtimes, secondIndex);
      secondTrace.terminalBarrier.reset();
      secondTrace.terminalPoint.reset();
      secondTrace.terminalSingularity.reset();
      secondTrace.terminalContact = FieldAlignedTerminalContact{
          event.sourceFace, event.barycentric, firstTrace.id, struckSegment};
      secondRuntime.active = false;
      secondRuntime.proposal.reset();
    } else {
      // The wall segment may have been committed while its trace is still
      // live. An inconclusive filtered comparison at the same exact crossing
      // is the frozen symmetric case: both traces terminate there. Because no
      // terminal event is published until a trace retires, an active wall can
      // be shortened back to the struck segment without undoing published
      // topology. A retired wall would require retroactive event repair and is
      // therefore a typed fail-closed outcome.
      if (!secondRuntime.active || event.secondSegment >= secondTrace.segments.size()) {
        return trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
            secondTrace.sourceVertex, secondTrace.singularity, std::nullopt,
            std::nullopt, event.sourceFace);
      }
      const std::size_t retainedSegmentCount = event.secondSegment + 1U;
      secondTrace.segments.erase(
          secondTrace.segments.begin() +
              static_cast<std::ptrdiff_t>(retainedSegmentCount),
          secondTrace.segments.end());
      secondRuntime.segmentStarts.erase(
          secondRuntime.segmentStarts.begin() +
              static_cast<std::ptrdiff_t>(retainedSegmentCount),
          secondRuntime.segmentStarts.end());
      secondTrace.terminalBarrier.reset();
      secondTrace.terminalPoint.reset();
      secondTrace.terminalSingularity.reset();
      secondTrace.terminalContact = FieldAlignedTerminalContact{
          event.sourceFace, event.barycentric, firstTrace.id,
          firstPendingSegmentIndex};
      secondRuntime.active = false;
      secondRuntime.proposal.reset();
    }
  }

  const auto contactNode =
      field_aligned_append_contact_node(candidate, event.sourceFace);
  if (!contactNode.has_value()) {
    return trace_scoped_field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
        firstTrace.sourceVertex, firstTrace.singularity, std::nullopt,
        std::nullopt, event.sourceFace);
  }

  const auto sourceEdge = [&]()
      -> std::optional<authority::SourceEdgeTopologyKey> {
    const FieldAlignedCandidateTraceSegment *firstSegment = nullptr;
    const FieldAlignedCandidateTraceSegment *secondSegment = nullptr;
    if (terminateFirst && !firstTrace.segments.empty()) {
      firstSegment = &firstTrace.segments.back();
    } else if (firstRuntime.proposal.has_value()) {
      firstSegment = &firstRuntime.proposal->segment;
    }
    if (selfContact || !event.secondIsProposal) {
      if (event.secondSegment < secondTrace.segments.size())
        secondSegment = &secondTrace.segments[event.secondSegment];
    } else if (terminateSecond && !secondTrace.segments.empty()) {
      secondSegment = &secondTrace.segments.back();
    } else if (secondRuntime.proposal.has_value()) {
      secondSegment = &secondRuntime.proposal->segment;
    }
    return firstSegment != nullptr && secondSegment != nullptr
               ? field_aligned_common_carrier(*firstSegment, *secondSegment)
               : std::optional<authority::SourceEdgeTopologyKey>{};
  }();

  std::vector<FieldAlignedNetworkEventIncidence> firstContact;
  std::vector<FieldAlignedNetworkEventIncidence> terminal;
  if (selfContact) {
    firstContact.emplace_back(firstTrace.id, firstTrace.port,
                              FieldAlignedTraceEventRole::Interior);
    terminal.emplace_back(firstTrace.id, firstTrace.port,
                          FieldAlignedTraceEventRole::Terminal);
  } else {
    firstContact.emplace_back(firstTrace.id, firstTrace.port,
                              FieldAlignedTraceEventRole::Interior);
    firstContact.emplace_back(secondTrace.id, secondTrace.port,
                              FieldAlignedTraceEventRole::Interior);
    terminal.emplace_back(firstTrace.id, firstTrace.port,
                          terminateFirst ? FieldAlignedTraceEventRole::Terminal
                                         : FieldAlignedTraceEventRole::Interior);
    terminal.emplace_back(secondTrace.id, secondTrace.port,
                          terminateSecond ? FieldAlignedTraceEventRole::Terminal
                                          : FieldAlignedTraceEventRole::Interior);
  }
  candidate.events.emplace_back(
      *contactNode, FieldAlignedNetworkEventKind::FirstContact,
      event.sourceFace, sourceEdge, std::move(firstContact));
  candidate.events.emplace_back(
      *contactNode,
      selfContact ? FieldAlignedNetworkEventKind::TraceSelfClosure
                  : FieldAlignedNetworkEventKind::TraceIntersection,
      event.sourceFace, sourceEdge, std::move(terminal));
  return std::nullopt;
}

std::optional<FieldAlignedCurveNetworkError>
canonical_field_aligned_traces_and_events(
    const TriMesh &sourceMesh,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::map<authority::SourceEdgeTopologyKey,
                   const authority::FieldNonTraversableEdge *> &mandatoryByEdge,
    FieldAlignedCurveNetworkCandidate &candidate,
    const FieldTraceArrivalPriority priority) {
  const authority::FieldBranchTopology &topology =
      fieldTransportAtlas.branch_topology();
  candidate.arrivalPriority = priority;
  candidate.candidateTraces.clear();
  candidate.candidateTraces.reserve(candidate.singularityPorts.size());
  std::vector<FieldAlignedTraceRuntime> runtimes;
  runtimes.reserve(candidate.singularityPorts.size());

  for (std::size_t traceIndex = 0U;
       traceIndex < candidate.singularityPorts.size(); ++traceIndex) {
    const FieldAlignedSingularityPort &port = candidate.singularityPorts[traceIndex];
    const authority::FieldSingularityPortAttachment *attachment = nullptr;
    for (const authority::FieldSingularityPortAttachment &candidateAttachment :
         topology.singularity_port_attachments()) {
      if (candidateAttachment.singularity != port.singularity ||
          candidateAttachment.localSlot != port.ordinal) {
        continue;
      }
      if (attachment != nullptr) {
        return field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
            port.sourceVertex, std::nullopt, std::nullopt, port.singularity);
      }
      attachment = &candidateAttachment;
    }
    if (attachment == nullptr || attachment->sourceVertex != port.sourceVertex ||
        attachment->sourceComponent != port.sourceComponent ||
        attachment->topologyRegion != port.sourceTopologyRegion) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
          port.sourceVertex, std::nullopt, std::nullopt, port.singularity);
    }
    const auto entry =
        field_boundary_point_at_vertex(attachment->startFace, port.sourceVertex);
    if (!entry.has_value()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
          port.sourceVertex, std::nullopt, std::nullopt, port.singularity);
    }
    candidate.candidateTraces.emplace_back(
        field_aligned_id<authority::TraceId>(
            traceIndex, candidate.singularityPorts.size()),
        port.id, port.singularity, port.sourceVertex, port.sourceComponent,
        port.sourceTopologyRegion);
    runtimes.emplace_back(attachment->startFace, attachment->branch, *entry,
                          field_aligned_trace_step_budget(topology));
  }

  const auto ensure_proposal = [&](const std::size_t traceIndex)
      -> std::optional<FieldAlignedCurveNetworkError> {
    FieldAlignedTraceRuntime &runtime = runtimes[traceIndex];
    if (!runtime.active || runtime.proposal.has_value()) return std::nullopt;
    auto proposed = field_aligned_next_trace_proposal(
        sourceMesh, fieldTransportAtlas, mandatoryByEdge,
        candidate.candidateTraces[traceIndex], runtime);
    if (auto *error = std::get_if<FieldAlignedCurveNetworkError>(&proposed)) {
      return *error;
    }
    runtime.proposal =
        std::get<FieldAlignedTraceProposal>(std::move(proposed));
    return std::nullopt;
  };

  for (std::size_t traceIndex = 0U; traceIndex < runtimes.size(); ++traceIndex) {
    if (const auto error = ensure_proposal(traceIndex); error.has_value()) {
      return *error;
    }
  }
  field_aligned_publish_origin_events(candidate, runtimes);

  while (std::any_of(runtimes.begin(), runtimes.end(),
                     [](const auto &runtime) { return runtime.active; })) {
    for (std::size_t traceIndex = 0U; traceIndex < runtimes.size(); ++traceIndex) {
      if (const auto error = ensure_proposal(traceIndex); error.has_value()) {
        return *error;
      }
    }

    std::priority_queue<FieldAlignedQueueEvent,
                        std::vector<FieldAlignedQueueEvent>,
                        FieldAlignedQueueEventLaterFirst>
        queue;

    for (std::size_t traceIndex = 0U; traceIndex < runtimes.size(); ++traceIndex) {
      const auto &runtime = runtimes[traceIndex];
      if (!runtime.active || !runtime.proposal.has_value()) continue;
      FieldAlignedQueueEvent event(runtime.proposal->segment.sourceFace);
      event.kind = FieldAlignedQueueEventKind::SegmentEnd;
      event.key = field_aligned_priority_key(
          priority, runtime.proposal->endArrival, traceIndex);
      event.firstTrace = traceIndex;
      event.sourceFace = runtime.proposal->segment.sourceFace;
      queue.push(std::move(event));
    }

    // Contacts between simultaneously pending segments. This is what makes
    // equal-arrival crossings symmetric rather than dependent on queue order.
    for (std::size_t firstIndex = 0U; firstIndex < runtimes.size(); ++firstIndex) {
      const auto &firstRuntime = runtimes[firstIndex];
      if (!firstRuntime.active || !firstRuntime.proposal.has_value()) continue;
      const auto &firstTrace = candidate.candidateTraces[firstIndex];
      for (std::size_t secondIndex = firstIndex + 1U;
           secondIndex < runtimes.size(); ++secondIndex) {
        const auto &secondRuntime = runtimes[secondIndex];
        if (!secondRuntime.active || !secondRuntime.proposal.has_value()) continue;
        const auto &secondTrace = candidate.candidateTraces[secondIndex];
        if (firstTrace.segments.empty() && secondTrace.segments.empty() &&
            firstTrace.singularity == secondTrace.singularity &&
            firstTrace.sourceVertex == secondTrace.sourceVertex) {
          continue;
        }
        const auto contact = classify_field_aligned_segment_contact_impl(
            topology, firstRuntime.proposal->segment,
            secondRuntime.proposal->segment);
        if (contact.kind != FieldAlignedSegmentContactKind::ProperCrossing ||
            !contact.barycentric.has_value()) {
          continue;
        }
        const auto firstArrival = field_aligned_arrival_at_barycentric(
            sourceMesh, firstRuntime.proposal->segment, firstRuntime.arrival,
            *contact.barycentric);
        const auto secondArrival = field_aligned_arrival_at_barycentric(
            sourceMesh, secondRuntime.proposal->segment, secondRuntime.arrival,
            *contact.barycentric);
        if (!firstArrival.has_value() || !secondArrival.has_value()) continue;
        FieldAlignedQueueEvent event(firstRuntime.proposal->segment.sourceFace);
        event.kind = FieldAlignedQueueEventKind::Contact;
        event.firstTrace = firstIndex;
        event.secondTrace = secondIndex;
        event.secondSegment = secondTrace.segments.size();
        event.secondIsProposal = true;
        event.ordering = field_aligned_compare_priority_arrivals(
            priority, *firstArrival, *secondArrival, firstIndex, secondIndex);
        const double firstKey =
            field_aligned_priority_key(priority, *firstArrival, firstIndex);
        const double secondKey =
            field_aligned_priority_key(priority, *secondArrival, secondIndex);
        // A conclusive crash happens when the later trace arrives. An
        // inconclusive same-point comparison is the frozen symmetric case, so
        // schedule it before either containing segment can advance past the
        // crossing.
        event.key =
            event.ordering == FieldAlignedArrivalOrdering::Inconclusive
                ? std::min(firstKey, secondKey)
                : std::max(firstKey, secondKey);
        event.sourceFace = firstRuntime.proposal->segment.sourceFace;
        event.barycentric = *contact.barycentric;
        queue.push(std::move(event));
      }
    }

    // Contacts with walls already laid, including the trace's own earlier
    // segments. Only a wall that is conclusively earlier can crash the pending
    // trace; an equal/inconclusive same-point encounter cannot be resolved by
    // seniority and therefore fails closed if the other trace has already been
    // retired.
    for (std::size_t movingIndex = 0U; movingIndex < runtimes.size(); ++movingIndex) {
      const auto &movingRuntime = runtimes[movingIndex];
      if (!movingRuntime.active || !movingRuntime.proposal.has_value()) continue;
      const auto &movingTrace = candidate.candidateTraces[movingIndex];
      for (std::size_t wallIndex = 0U; wallIndex < runtimes.size(); ++wallIndex) {
        const auto &wallRuntime = runtimes[wallIndex];
        const auto &wallTrace = candidate.candidateTraces[wallIndex];
        for (std::size_t wallSegmentIndex = 0U;
             wallSegmentIndex < wallTrace.segments.size(); ++wallSegmentIndex) {
          if (wallSegmentIndex >= wallRuntime.segmentStarts.size()) continue;
          if (movingTrace.segments.empty() && wallSegmentIndex == 0U &&
              movingTrace.singularity == wallTrace.singularity &&
              movingTrace.sourceVertex == wallTrace.sourceVertex) {
            continue;
          }
          const std::optional<std::array<authority::FieldExactRational, 3>>
              wallTerminalContact =
                  wallTrace.terminalContact.has_value() &&
                          wallSegmentIndex + 1U == wallTrace.segments.size()
                      ? std::optional<std::array<authority::FieldExactRational, 3>>{
                            wallTrace.terminalContact->barycentric}
                      : std::nullopt;
          const auto contact =
              classify_field_aligned_segment_contact_with_second_exit(
                  topology, movingRuntime.proposal->segment,
                  wallTrace.segments[wallSegmentIndex], wallTerminalContact);
          if (contact.kind != FieldAlignedSegmentContactKind::ProperCrossing ||
              !contact.barycentric.has_value()) {
            continue;
          }
          const auto movingArrival = field_aligned_arrival_at_barycentric(
              sourceMesh, movingRuntime.proposal->segment, movingRuntime.arrival,
              *contact.barycentric);
          const auto wallArrival = field_aligned_arrival_at_barycentric(
              sourceMesh, wallTrace.segments[wallSegmentIndex],
              wallRuntime.segmentStarts[wallSegmentIndex], *contact.barycentric);
          if (!movingArrival.has_value() || !wallArrival.has_value()) continue;
          const auto ordering = field_aligned_compare_priority_arrivals(
              priority, *movingArrival, *wallArrival, movingIndex, wallIndex);
          if (ordering == FieldAlignedArrivalOrdering::Earlier) continue;
          if (ordering == FieldAlignedArrivalOrdering::Inconclusive &&
              !wallRuntime.active) {
            return trace_scoped_field_aligned_error(
                FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
                movingTrace.sourceVertex, movingTrace.singularity,
                std::nullopt, std::nullopt,
                movingRuntime.proposal->segment.sourceFace);
          }
          FieldAlignedQueueEvent event(movingRuntime.proposal->segment.sourceFace);
          event.kind = FieldAlignedQueueEventKind::Contact;
          event.firstTrace = movingIndex;
          event.secondTrace = wallIndex;
          event.secondSegment = wallSegmentIndex;
          event.secondIsProposal = false;
          // `Later` means the moving trace crashes. For a self-contact the
          // later segment is necessarily the pending segment.
          event.ordering = ordering;
          event.key = std::max(
              field_aligned_priority_key(priority, *movingArrival, movingIndex),
              field_aligned_priority_key(priority, *wallArrival, wallIndex));
          event.sourceFace = movingRuntime.proposal->segment.sourceFace;
          event.barycentric = *contact.barycentric;
          queue.push(std::move(event));
        }
      }
    }

    if (queue.empty()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership);
    }
    const FieldAlignedQueueEvent event = queue.top();
    queue.pop();

    if (event.kind == FieldAlignedQueueEventKind::Contact) {
      if (const auto error =
              field_aligned_publish_contact(candidate, runtimes, event);
          error.has_value()) {
        return *error;
      }
      continue;
    }

    const std::size_t traceIndex = event.firstTrace;
    FieldAlignedTraceRuntime &runtime = runtimes[traceIndex];
    if (!runtime.active || !runtime.proposal.has_value()) continue;
    FieldAlignedCandidateTrace &trace = candidate.candidateTraces[traceIndex];
    const FieldAlignedTraceProposal proposal = *runtime.proposal;
    field_aligned_commit_current_proposal(candidate, runtimes, traceIndex);
    runtime.arrival = proposal.endArrival;
    runtime.proposal.reset();

    if (proposal.disposition == FieldAlignedProposalDisposition::TerminalSingularity) {
      trace.terminalPoint = proposal.terminalPoint;
      trace.terminalSingularity = proposal.terminalSingularity;
      trace.terminalBarrier.reset();
      trace.terminalContact.reset();
      runtime.active = false;
      if (const auto error = append_field_aligned_singularity_termination(
              candidate, trace);
          error.has_value()) {
        return *error;
      }
      continue;
    }
    if (proposal.disposition == FieldAlignedProposalDisposition::TerminalBarrier) {
      trace.terminalPoint = proposal.terminalPoint;
      trace.terminalBarrier = proposal.terminalBarrier;
      trace.terminalSingularity.reset();
      trace.terminalContact.reset();
      runtime.active = false;
      if (const auto error =
              field_aligned_publish_barrier_termination(candidate, trace);
          error.has_value()) {
        return *error;
      }
      continue;
    }

    if (!proposal.nextFace.has_value() || !proposal.nextBranch.has_value() ||
        !proposal.nextEntryPoint.has_value()) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          trace.sourceVertex, trace.singularity, std::nullopt, std::nullopt,
          trace.segments.back().sourceFace, trace.segments.back().branch);
    }
    runtime.currentFace = *proposal.nextFace;
    runtime.currentBranch = *proposal.nextBranch;
    runtime.currentEntryPoint = *proposal.nextEntryPoint;
    runtime.incomingCarrier = proposal.nextIncomingCarrier;
    runtime.entryTransport = proposal.nextEntryTransport;
  }

  for (const FieldAlignedCandidateTrace &trace : candidate.candidateTraces) {
    const std::size_t terminalKinds =
        static_cast<std::size_t>(trace.terminalSingularity.has_value()) +
        static_cast<std::size_t>(trace.terminalBarrier.has_value()) +
        static_cast<std::size_t>(trace.terminalContact.has_value());
    if (trace.segments.empty() || terminalKinds != 1U) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
          trace.sourceVertex, trace.singularity);
    }
  }

  std::sort(candidate.nodes.begin(), candidate.nodes.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.sourceVertex, lhs.id) <
                     std::tie(rhs.sourceVertex, rhs.id);
            });
  field_aligned_sort_events(candidate.events);
  return std::nullopt;
}

std::optional<FieldAlignedCurveNetworkError> finalize_field_aligned_events(
    const authority::FieldBranchTopology &topology,
    FieldAlignedCurveNetworkCandidate &candidate,
    FieldAlignedContactCensus *contactCensus = nullptr) {
  candidate.events.clear();
  if (contactCensus != nullptr) *contactCensus = FieldAlignedContactCensus{};

  std::map<authority::FieldSingularityId, std::vector<std::size_t>>
      tracesBySingularity;
  for (std::size_t traceIndex = 0U;
       traceIndex < candidate.candidateTraces.size(); ++traceIndex) {
    const FieldAlignedCandidateTrace &trace = candidate.candidateTraces[traceIndex];
    if (trace.segments.empty() ||
        field_aligned_port_for_trace(candidate, trace) == nullptr) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
          trace.sourceVertex, trace.singularity, std::nullopt, std::nullopt,
          trace.segments.empty()
              ? std::optional<authority::SourceFaceTopologyKey>{}
              : trace.segments.front().sourceFace,
          trace.segments.empty()
              ? std::optional<authority::FieldBranch>{}
              : std::optional<authority::FieldBranch>(
                    trace.segments.front().branch));
    }
    tracesBySingularity[trace.singularity].push_back(traceIndex);
  }

  // Publish the singularity/port junction first. Each source port is consumed
  // exactly once here; the companion intersection record declares the
  // multi-trace junction without consuming the ports again.
  for (const auto &[singularity, traceIndices] : tracesBySingularity) {
    if (traceIndices.empty()) continue;
    const FieldAlignedCandidateTrace &firstTrace =
        candidate.candidateTraces[traceIndices.front()];
    const FieldAlignedSingularityPort *firstPort =
        field_aligned_port_for_trace(candidate, firstTrace);
    if (firstPort == nullptr) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
          firstTrace.sourceVertex, firstTrace.singularity, std::nullopt,
          std::nullopt, firstTrace.segments.front().sourceFace,
          firstTrace.segments.front().branch);
    }
    authority::SourceFaceTopologyKey sourceFace =
        firstTrace.segments.front().sourceFace;
    std::vector<FieldAlignedNetworkEventIncidence> origins;
    std::vector<FieldAlignedNetworkEventIncidence> junction;
    origins.reserve(traceIndices.size());
    junction.reserve(traceIndices.size());
    for (const std::size_t traceIndex : traceIndices) {
      const FieldAlignedCandidateTrace &trace = candidate.candidateTraces[traceIndex];
      const FieldAlignedSingularityPort *port =
          field_aligned_port_for_trace(candidate, trace);
      if (port == nullptr || port->node != firstPort->node ||
          trace.sourceVertex != firstTrace.sourceVertex) {
        return trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
            trace.sourceVertex, trace.singularity, std::nullopt, std::nullopt,
            trace.segments.front().sourceFace, trace.segments.front().branch);
      }
      sourceFace = std::min(sourceFace, trace.segments.front().sourceFace);
      origins.emplace_back(trace.id, trace.port,
                           FieldAlignedTraceEventRole::Origin);
      junction.emplace_back(trace.id, trace.port,
                            FieldAlignedTraceEventRole::Interior);
    }
    candidate.events.emplace_back(
        firstPort->node, FieldAlignedNetworkEventKind::SingularityPortOrigin,
        sourceFace, std::nullopt, std::move(origins));
    if (traceIndices.size() > 1U) {
      candidate.events.emplace_back(
          firstPort->node, FieldAlignedNetworkEventKind::TraceIntersection,
          sourceFace, std::nullopt, std::move(junction));
      if (contactCensus != nullptr) {
        ++contactCensus->siteA;
        contactCensus->contactNodes.push_back(FieldAlignedContactCensusNode{
            firstPort->node, firstTrace.sourceVertex,
            FieldAlignedContactCensusSite::SingularityJunction});
      }
    }
  }

  for (std::size_t traceIndex = 0U;
       traceIndex < candidate.candidateTraces.size(); ++traceIndex) {
    FieldAlignedCandidateTrace &trace = candidate.candidateTraces[traceIndex];
    const auto contact =
        field_aligned_first_trace_contact(candidate.candidateTraces, traceIndex);
    if (contact.has_value()) {
      if (contactCensus != nullptr) {
        const FieldAlignedCandidateTrace &existing =
            candidate.candidateTraces[contact->existingTraceIndex];
        contactCensus->sharedFaceContacts.push_back(
            FieldAlignedContactCensusObservation{
                trace.id, contact->segmentIndex, existing.id,
                contact->existingSegmentIndex, contact->sourceFace,
                contact->sourceEdge,
                field_aligned_segments_properly_cross(
                    topology, trace.segments[contact->segmentIndex],
                    existing.segments[contact->existingSegmentIndex]),
                field_aligned_prior_terminal_kind(trace)});
        ++contactCensus->siteB;
      }
      trace.segments.erase(
          trace.segments.begin() + static_cast<std::ptrdiff_t>(contact->segmentIndex + 1U),
          trace.segments.end());
      trace.terminalBarrier.reset();
      trace.terminalPoint.reset();
      trace.terminalSingularity.reset();
      const auto contactNode =
          field_aligned_append_contact_node(candidate, contact->sourceFace);
      if (!contactNode.has_value()) {
        return trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
            trace.sourceVertex, trace.singularity, std::nullopt,
            contact->sourceEdge, contact->sourceFace,
            trace.segments[contact->segmentIndex].branch);
      }
      const FieldAlignedCandidateTrace &existing =
          candidate.candidateTraces[contact->existingTraceIndex];
      std::vector<FieldAlignedNetworkEventIncidence> firstContact{
          FieldAlignedNetworkEventIncidence(
              existing.id, existing.port, FieldAlignedTraceEventRole::Interior),
          FieldAlignedNetworkEventIncidence(
              trace.id, trace.port, FieldAlignedTraceEventRole::Interior)};
      std::vector<FieldAlignedNetworkEventIncidence> intersection{
          FieldAlignedNetworkEventIncidence(
              existing.id, existing.port, FieldAlignedTraceEventRole::Interior),
          FieldAlignedNetworkEventIncidence(
              trace.id, trace.port, FieldAlignedTraceEventRole::Terminal)};
      candidate.events.emplace_back(
          *contactNode, FieldAlignedNetworkEventKind::FirstContact,
          contact->sourceFace, contact->sourceEdge, std::move(firstContact));
      candidate.events.emplace_back(
          *contactNode, FieldAlignedNetworkEventKind::TraceIntersection,
          contact->sourceFace, contact->sourceEdge, std::move(intersection));
      if (contactCensus != nullptr) {
        contactCensus->contactNodes.push_back(FieldAlignedContactCensusNode{
            *contactNode, contact->sourceFace.vertices().front(),
            FieldAlignedContactCensusSite::SharedFaceTraceContact});
      }
      continue;
    }

    if (trace.terminalSingularity.has_value()) {
      const auto error = append_field_aligned_singularity_termination(
          candidate, trace);
      if (error.has_value()) return *error;
      continue;
    }

    if (trace.terminalBarrier.has_value()) {
      const auto mandatory = std::find_if(
          candidate.mandatoryEdges.begin(), candidate.mandatoryEdges.end(),
          [&](const FieldAlignedMandatoryEdge &edge) {
            return edge.sourceEdge == *trace.terminalBarrier;
          });
      if (mandatory == candidate.mandatoryEdges.end()) {
        return trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
            trace.sourceVertex, trace.singularity, std::nullopt,
            trace.terminalBarrier, trace.segments.back().sourceFace,
            trace.segments.back().branch);
      }
      const authority::SourceFaceTopologyKey sourceFace =
          trace.segments.back().sourceFace;
      const auto terminalNode =
          field_aligned_append_contact_node(candidate, sourceFace);
      if (!terminalNode.has_value()) {
        return trace_scoped_field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
            trace.sourceVertex, trace.singularity, std::nullopt,
            trace.terminalBarrier, sourceFace, trace.segments.back().branch);
      }
      candidate.events.emplace_back(
          *terminalNode, FieldAlignedNetworkEventKind::FirstContact, sourceFace,
          trace.terminalBarrier,
          std::vector<FieldAlignedNetworkEventIncidence>{
              FieldAlignedNetworkEventIncidence(
                  trace.id, trace.port, FieldAlignedTraceEventRole::Interior)});
      candidate.events.emplace_back(
          *terminalNode, FieldAlignedNetworkEventKind::MandatoryBarrierTermination,
          sourceFace, trace.terminalBarrier,
          std::vector<FieldAlignedNetworkEventIncidence>{
              FieldAlignedNetworkEventIncidence(
                  trace.id, trace.port, FieldAlignedTraceEventRole::Terminal)});
      continue;
    }

    const FieldAlignedCandidateTraceSegment &last = trace.segments.back();
    const auto nextFace =
        field_aligned_next_face(topology, last.outgoingCarrier, last.sourceFace);
    const bool closesOnEarlierState =
        nextFace.has_value() &&
        std::any_of(trace.segments.begin(), trace.segments.end(),
                    [&](const FieldAlignedCandidateTraceSegment &segment) {
                      return segment.sourceFace == *nextFace;
                    });
    if (!closesOnEarlierState) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership,
          trace.sourceVertex, trace.singularity, std::nullopt,
          last.outgoingCarrier, last.sourceFace, last.branch);
    }
    const auto contactNode = field_aligned_append_contact_node(candidate, *nextFace);
    if (!contactNode.has_value()) {
      return trace_scoped_field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
          trace.sourceVertex, trace.singularity, std::nullopt,
          last.outgoingCarrier, last.sourceFace, last.branch);
    }
    candidate.events.emplace_back(
        *contactNode, FieldAlignedNetworkEventKind::FirstContact, *nextFace,
        last.outgoingCarrier,
        std::vector<FieldAlignedNetworkEventIncidence>{
            FieldAlignedNetworkEventIncidence(
                trace.id, trace.port, FieldAlignedTraceEventRole::Interior)});
    candidate.events.emplace_back(
        *contactNode, FieldAlignedNetworkEventKind::TraceIntersection, *nextFace,
        last.outgoingCarrier,
        std::vector<FieldAlignedNetworkEventIncidence>{
            FieldAlignedNetworkEventIncidence(
                trace.id, trace.port, FieldAlignedTraceEventRole::Terminal)});
    if (contactCensus != nullptr) {
      ++contactCensus->siteC;
      contactCensus->contactNodes.push_back(FieldAlignedContactCensusNode{
          *contactNode, nextFace->vertices().front(),
          FieldAlignedContactCensusSite::SelfClosure});
    }
  }

  if (contactCensus != nullptr) {
    contactCensus->nodeCount = candidate.nodes.size();
    for (const FieldAlignedNetworkEvent &event : candidate.events) {
      ++contactCensus->eventKindHistogram[event.kind];
    }
  }

  std::sort(candidate.nodes.begin(), candidate.nodes.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.sourceVertex, lhs.id) <
                     std::tie(rhs.sourceVertex, rhs.id);
            });
  field_aligned_sort_events(candidate.events);
  return std::nullopt;
}

struct FieldAlignedRailSupport {
  FieldAlignedRailSupport(authority::HardRailId railValue,
                          const SurfaceCellRailKind kindValue)
      : rail(railValue), kind(kindValue) {}
  authority::HardRailId rail;
  SurfaceCellRailKind kind = SurfaceCellRailKind::Boundary;
};

std::optional<authority::TopologyRegionId> singularity_region_from_source(
    const Eigen::MatrixXi &sourceFaces,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldSingularityFact &singularity) {
  std::set<authority::TopologyRegionId> regions;
  std::optional<authority::SourceComponentId> component;
  for (int face = 0; face < sourceFaces.rows(); ++face) {
    bool incident = false;
    for (int corner = 0; corner < 3; ++corner) {
      incident = incident ||
                 sourceFaces(face, corner) ==
                     static_cast<int>(singularity.sourceVertex.index());
    }
    if (!incident) continue;
    const auto sourceFace = authority::SourceFaceId::from_index(
        face, static_cast<std::size_t>(sourceFaces.rows()));
    if (!sourceFace) return std::nullopt;
    const authority::SourceComponentId faceComponent =
        sourceAuthority.component_for_row(sourceFace.value());
    if (!component.has_value()) {
      component = faceComponent;
    } else if (*component != faceComponent) {
      return std::nullopt;
    }
    regions.insert(sourceAuthority.region_for_row(sourceFace.value()));
  }
  if (!component.has_value() || *component != singularity.sourceComponent ||
      regions.empty()) {
    return std::nullopt;
  }
  if (singularity.topologyRegion.has_value()) {
    return regions.count(*singularity.topologyRegion) == 1U
               ? singularity.topologyRegion
               : std::nullopt;
  }
  return regions.size() == 1U
             ? std::optional<authority::TopologyRegionId>{*regions.begin()}
             : std::nullopt;
}

FieldAlignedCandidateResult canonical_field_aligned_candidate(
    const TriMesh &sourceMesh,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<SurfaceCellRail> &authoritativeRails,
    FieldAlignedContactCensus *contactCensus = nullptr,
    const FieldTraceArrivalPriority priority =
        FieldTraceArrivalPriority::ArcLengthFiltered) {
  const Eigen::MatrixXi &sourceFaces = sourceMesh.F;
  const std::size_t sourceVertexCount =
      static_cast<std::size_t>(sourceMesh.V.rows());
  if (sourceMesh.V.cols() != 3 || sourceFaces.cols() != 3 ||
      sourceFaces.rows() <= 0 || sourceVertexCount == 0U ||
      !sourceAuthority.matches_source_faces(sourceFaces, sourceVertexCount)) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidSourceBinding);
  }
  if (!fieldTransportAtlas.matches_source_faces(
          sourceFaces, sourceAuthority, sourceVertexCount) ||
      !fieldTransportAtlas.quadrangulability().established()) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidAtlasBinding);
  }

  std::set<authority::HardRailId> railIds;
  std::map<authority::SourceEdgeTopologyKey, FieldAlignedRailSupport>
      supportByEdge;
  for (const SurfaceCellRail &rail : authoritativeRails) {
    if (!railIds.insert(rail.id).second) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::DuplicateRailId, std::nullopt,
          std::nullopt, rail.id);
    }
    const bool hasValidSourceIntervalTopology =
        rail.closed
            ? (rail.sourceEdges.size() >= 3U &&
               rail.sourceVertices.size() == rail.sourceEdges.size())
            : (rail.sourceVertices.size() == rail.sourceEdges.size() + 1U);
    if (rail.sourceEdges.empty() || !hasValidSourceIntervalTopology) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidRailGeometry,
          std::nullopt, std::nullopt, rail.id);
    }
    for (std::size_t interval = 0; interval < rail.sourceEdges.size();
         ++interval) {
      const std::size_t nextVertex =
          rail.closed ? (interval + 1U) % rail.sourceVertices.size()
                      : interval + 1U;
      const auto key = authority::SourceEdgeTopologyKey::from_indices(
          rail.sourceVertices[interval], rail.sourceVertices[nextVertex],
          sourceVertexCount);
      if (!key) {
        return field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::InvalidRailGeometry,
            std::nullopt, std::nullopt, rail.id);
      }
      if (!supportByEdge
               .emplace(key.value(), FieldAlignedRailSupport{rail.id, rail.kind})
               .second) {
        return field_aligned_error(
            FieldAlignedCurveNetworkErrorCode::DuplicateMandatoryEdge,
            std::nullopt, key.value(), rail.id);
      }
    }
  }

  std::map<authority::SourceEdgeTopologyKey,
           const authority::FieldNonTraversableEdge *>
      mandatoryByEdge;
  for (const authority::FieldNonTraversableEdge &edge :
       fieldTransportAtlas.nontraversable_edges()) {
    if (edge.kind != authority::FieldTransportBarrierKind::SourceBoundary &&
        edge.kind != authority::FieldTransportBarrierKind::HardFeature) {
      continue;
    }
    mandatoryByEdge.emplace(edge.sourceEdge, &edge);
  }
  for (const auto &[sourceEdge, support] : supportByEdge) {
    if (mandatoryByEdge.count(sourceEdge) == 0U) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::ForeignMandatoryEdge,
          std::nullopt, sourceEdge, support.rail);
    }
  }
  for (const auto &[sourceEdge, barrier] : mandatoryByEdge) {
    (void)barrier;
    if (supportByEdge.count(sourceEdge) == 0U) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge,
          std::nullopt, sourceEdge);
    }
  }

  std::set<authority::SourceVertexId> nodeVertices;
  std::map<authority::FieldSingularityId, authority::TopologyRegionId>
      singularityRegions;
  std::vector<const authority::FieldSingularityFact *> singularities;
  singularities.reserve(fieldTransportAtlas.singularities().size());
  std::size_t totalPortCount = 0U;
  for (const authority::FieldSingularityFact &singularity :
       fieldTransportAtlas.singularities()) {
    if (singularity.sourceVertex.index() >= sourceVertexCount) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidSingularityBinding,
          singularity.sourceVertex, std::nullopt, std::nullopt,
          singularity.id);
    }
    const auto region = singularity_region_from_source(
        sourceFaces, sourceAuthority, singularity);
    const int expectedValence = 4 - singularity.indexNumerator;
    if (!region.has_value() || expectedValence < 3 || expectedValence > 6 ||
        !singularityRegions.emplace(singularity.id, *region).second) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidSingularityBinding,
          singularity.sourceVertex, std::nullopt, std::nullopt,
          singularity.id);
    }
    nodeVertices.insert(singularity.sourceVertex);
    singularities.push_back(&singularity);
    if (singularity.portPolicy ==
        authority::FieldSingularityFact::PortPolicy::Emit) {
      totalPortCount += static_cast<std::size_t>(expectedValence);
    }
  }
  std::sort(singularities.begin(), singularities.end(),
            [](const auto *lhs, const auto *rhs) {
              return std::tie(lhs->sourceVertex, lhs->id) <
                     std::tie(rhs->sourceVertex, rhs->id);
            });

  for (const auto &[sourceEdge, barrier] : mandatoryByEdge) {
    nodeVertices.insert(sourceEdge.first());
    nodeVertices.insert(sourceEdge.second());
    const auto support = supportByEdge.find(sourceEdge);
    if (support == supportByEdge.end()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge,
          std::nullopt, sourceEdge);
    }
    const SurfaceCellRailKind expectedKind =
        barrier->kind == authority::FieldTransportBarrierKind::SourceBoundary
            ? SurfaceCellRailKind::Boundary
            : SurfaceCellRailKind::HardFeature;
    if (support->second.kind != expectedKind) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MandatoryKindMismatch,
          std::nullopt, sourceEdge, support->second.rail);
    }
  }

  FieldAlignedCurveNetworkCandidate candidate;
  candidate.sourceDigest = fieldTransportAtlas.quadrangulability().source_digest();
  candidate.atlasDigest = authority::field_transport_atlas_hash(fieldTransportAtlas);
  candidate.nodes.reserve(nodeVertices.size());
  std::map<authority::SourceVertexId, authority::NetworkNodeId> nodeByVertex;
  std::size_t nodeIndex = 0U;
  for (const authority::SourceVertexId vertex : nodeVertices) {
    const authority::NetworkNodeId node = field_aligned_id<authority::NetworkNodeId>(
        nodeIndex++, nodeVertices.size());
    nodeByVertex.emplace(vertex, node);
    candidate.nodes.emplace_back(node, vertex);
  }

  candidate.singularityPorts.reserve(totalPortCount);
  std::size_t portIndex = 0U;
  for (const authority::FieldSingularityFact *singularity : singularities) {
    if (singularity->portPolicy ==
        authority::FieldSingularityFact::PortPolicy::BarrierAbsorbed) {
      continue;
    }
    const int expectedValence = 4 - singularity->indexNumerator;
    const auto region = singularityRegions.find(singularity->id);
    const auto node = nodeByVertex.find(singularity->sourceVertex);
    if (region == singularityRegions.end() || node == nodeByVertex.end()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidSingularityBinding,
          singularity->sourceVertex, std::nullopt, std::nullopt,
          singularity->id);
    }
    for (int ordinal = 0; ordinal < expectedValence; ++ordinal) {
      candidate.singularityPorts.emplace_back(
          field_aligned_id<authority::SingularityPortId>(
              portIndex++, totalPortCount),
          singularity->id, node->second, singularity->sourceVertex,
          singularity->sourceComponent, region->second,
          singularity->indexNumerator, ordinal);
    }
  }

  candidate.mandatoryEdges.reserve(mandatoryByEdge.size());
  std::size_t edgeIndex = 0U;
  for (const auto &[sourceEdge, barrier] : mandatoryByEdge) {
    const auto support = supportByEdge.find(sourceEdge);
    const auto firstNode = nodeByVertex.find(sourceEdge.first());
    const auto secondNode = nodeByVertex.find(sourceEdge.second());
    if (support == supportByEdge.end() || firstNode == nodeByVertex.end() ||
        secondNode == nodeByVertex.end()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MandatoryOwnerMismatch,
          std::nullopt, sourceEdge,
          support == supportByEdge.end()
              ? std::optional<authority::HardRailId>{}
              : std::optional<authority::HardRailId>{support->second.rail});
    }

    std::vector<authority::TopologyRegionId> regions;
    std::optional<authority::SourceComponentId> component;
    const auto consume_face = [&](const std::optional<authority::SourceFaceId> face) {
      if (!face.has_value() ||
          face->index() >= static_cast<std::size_t>(sourceFaces.rows())) {
        return !face.has_value();
      }
      const authority::SourceComponentId faceComponent =
          sourceAuthority.component_for_row(*face);
      if (!component.has_value()) {
        component = faceComponent;
      } else if (*component != faceComponent) {
        return false;
      }
      regions.push_back(sourceAuthority.region_for_row(*face));
      return true;
    };
    if (!consume_face(barrier->firstFace) || !consume_face(barrier->secondFace) ||
        !component.has_value() || regions.empty()) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MandatoryOwnerMismatch,
          std::nullopt, sourceEdge, support->second.rail);
    }
    std::sort(regions.begin(), regions.end());
    regions.erase(std::unique(regions.begin(), regions.end()), regions.end());

    candidate.mandatoryEdges.emplace_back(
        field_aligned_id<authority::NetworkEdgeId>(
            edgeIndex++, mandatoryByEdge.size()),
        support->second.rail, sourceEdge, support->second.kind,
        firstNode->second, secondNode->second, *component, std::move(regions));
  }

  if (contactCensus != nullptr) {
    // S1 remains a frozen observation of the predecessor mechanism. It is a
    // diagnostic-only authority and must not feed the corrected production
    // topology after S2-S6.
    const FieldAlignedCandidateTraceResult traceResult =
        legacy_canonical_field_aligned_traces(
            sourceMesh, fieldTransportAtlas, candidate.singularityPorts,
            mandatoryByEdge);
    if (const auto *error =
            std::get_if<FieldAlignedCurveNetworkError>(&traceResult)) {
      return *error;
    }
    candidate.candidateTraces =
        std::get<std::vector<FieldAlignedCandidateTrace>>(traceResult);
    if (const auto eventError = finalize_field_aligned_events(
            fieldTransportAtlas.branch_topology(), candidate, contactCensus);
        eventError.has_value()) {
      return *eventError;
    }
    return candidate;
  }

  if (const auto tracingError = canonical_field_aligned_traces_and_events(
          sourceMesh, fieldTransportAtlas, mandatoryByEdge, candidate,
          priority);
      tracingError.has_value()) {
    return *tracingError;
  }
  return candidate;
}

constexpr std::uint64_t kFieldAlignedFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFieldAlignedFnvPrime = 1099511628211ULL;

void field_aligned_hash_consume(std::uint64_t &hash,
                                const std::uint64_t value) noexcept {
  hash ^= value;
  hash *= kFieldAlignedFnvPrime;
}

template <typename Id>
void field_aligned_hash_id(std::uint64_t &hash, const Id id) noexcept {
  field_aligned_hash_consume(
      hash, static_cast<std::uint64_t>(Id::domain()));
  field_aligned_hash_consume(hash, id.index());
}

void field_aligned_hash_edge(
    std::uint64_t &hash,
    const authority::SourceEdgeTopologyKey &edge) noexcept {
  field_aligned_hash_id(hash, edge.first());
  field_aligned_hash_id(hash, edge.second());
}


void field_aligned_hash_exact(
    std::uint64_t &hash,
    const authority::FieldExactRational &value) noexcept {
  const std::string numerator = value.numerator_string();
  const std::string denominator = value.denominator_string();
  field_aligned_hash_consume(hash, numerator.size());
  for (const unsigned char byte : numerator) {
    field_aligned_hash_consume(hash, byte);
  }
  field_aligned_hash_consume(hash, denominator.size());
  for (const unsigned char byte : denominator) {
    field_aligned_hash_consume(hash, byte);
  }
}

void field_aligned_hash_boundary_point(
    std::uint64_t &hash,
    const authority::FieldBoundaryPoint &point) noexcept {
  field_aligned_hash_edge(hash, point.edge);
  field_aligned_hash_exact(hash, point.parameter.value);
}

void field_aligned_hash_face(
    std::uint64_t &hash,
    const authority::SourceFaceTopologyKey &face) noexcept {
  for (const authority::SourceVertexId vertex : face.vertices()) {
    field_aligned_hash_id(hash, vertex);
  }
}

std::uint64_t field_aligned_candidate_digest(
    const FieldAlignedCurveNetworkCandidate &candidate,
    const SourceTopologyRegions &sourceAuthority,
    const std::uint64_t sourceDigest,
    const std::uint64_t branchTopologyDigest) noexcept {
  std::uint64_t hash = kFieldAlignedFnvOffset;
  field_aligned_hash_consume(hash, sourceDigest);
  field_aligned_hash_consume(hash, branchTopologyDigest);
  field_aligned_hash_consume(hash, static_cast<std::uint64_t>(candidate.arrivalPriority));
  field_aligned_hash_consume(hash, candidate.nodes.size());
  for (const FieldAlignedCurveNetworkNode &node : candidate.nodes) {
    field_aligned_hash_id(hash, node.id);
    field_aligned_hash_id(hash, node.sourceVertex);
  }
  field_aligned_hash_consume(hash, candidate.singularityPorts.size());
  for (const FieldAlignedSingularityPort &port : candidate.singularityPorts) {
    field_aligned_hash_id(hash, port.id);
    field_aligned_hash_id(hash, port.singularity);
    field_aligned_hash_id(hash, port.node);
    field_aligned_hash_id(hash, port.sourceVertex);
    field_aligned_hash_id(hash, port.sourceComponent);
    field_aligned_hash_consume(
        hash, surface_topology_region_hash(
                  sourceAuthority.region(port.sourceTopologyRegion)));
    field_aligned_hash_consume(
        hash, static_cast<std::uint64_t>(static_cast<std::int64_t>(
                  port.indexNumerator)));
    field_aligned_hash_consume(hash, static_cast<std::uint64_t>(port.ordinal));
  }
  field_aligned_hash_consume(hash, candidate.mandatoryEdges.size());
  for (const FieldAlignedMandatoryEdge &edge : candidate.mandatoryEdges) {
    field_aligned_hash_id(hash, edge.id);
    field_aligned_hash_id(hash, edge.rail);
    field_aligned_hash_id(hash, edge.sourceEdge.first());
    field_aligned_hash_id(hash, edge.sourceEdge.second());
    field_aligned_hash_consume(hash, static_cast<std::uint64_t>(edge.kind));
    field_aligned_hash_id(hash, edge.firstNode);
    field_aligned_hash_id(hash, edge.secondNode);
    field_aligned_hash_id(hash, edge.sourceComponent);
    field_aligned_hash_consume(hash, edge.sourceTopologyRegions.size());
    for (const authority::TopologyRegionId region : edge.sourceTopologyRegions) {
      field_aligned_hash_consume(
          hash, surface_topology_region_hash(sourceAuthority.region(region)));
    }
  }
  field_aligned_hash_consume(hash, candidate.candidateTraces.size());
  for (const FieldAlignedCandidateTrace &trace : candidate.candidateTraces) {
    field_aligned_hash_id(hash, trace.id);
    field_aligned_hash_id(hash, trace.port);
    field_aligned_hash_id(hash, trace.singularity);
    field_aligned_hash_id(hash, trace.sourceVertex);
    field_aligned_hash_id(hash, trace.sourceComponent);
    field_aligned_hash_consume(
        hash, surface_topology_region_hash(
                  sourceAuthority.region(trace.sourceTopologyRegion)));
    field_aligned_hash_consume(hash, trace.segments.size());
    for (const FieldAlignedCandidateTraceSegment &segment : trace.segments) {
      field_aligned_hash_face(hash, segment.sourceFace);
      field_aligned_hash_consume(hash, segment.branch.value());
      field_aligned_hash_boundary_point(hash, segment.entryPoint);
      field_aligned_hash_consume(hash, segment.incomingCarrier.has_value());
      if (segment.incomingCarrier.has_value()) {
        field_aligned_hash_edge(hash, *segment.incomingCarrier);
      }
      field_aligned_hash_edge(hash, segment.outgoingCarrier);
      field_aligned_hash_consume(hash, segment.entryTransport.has_value());
      if (segment.entryTransport.has_value()) {
        const FieldAlignedCandidateTraceTransition &transition =
            *segment.entryTransport;
        field_aligned_hash_edge(hash, transition.sourceEdge);
        field_aligned_hash_face(hash, transition.fromFace);
        field_aligned_hash_face(hash, transition.toFace);
        field_aligned_hash_consume(hash, transition.directed.transport.value());
        field_aligned_hash_consume(
            hash, static_cast<std::uint64_t>(static_cast<std::int64_t>(
                      transition.directed.signedLift)));
        field_aligned_hash_consume(
            hash, std::bit_cast<std::uint64_t>(transition.directed.effort));
      }
      field_aligned_hash_consume(hash, segment.edgeTransitExit.has_value());
      if (segment.edgeTransitExit.has_value()) {
        field_aligned_hash_boundary_point(hash, *segment.edgeTransitExit);
      }
    }
    field_aligned_hash_consume(hash, trace.terminalBarrier.has_value());
    if (trace.terminalBarrier.has_value()) {
      field_aligned_hash_edge(hash, *trace.terminalBarrier);
    }
    field_aligned_hash_consume(hash, trace.terminalPoint.has_value());
    if (trace.terminalPoint.has_value()) {
      field_aligned_hash_boundary_point(hash, *trace.terminalPoint);
    }
    field_aligned_hash_consume(hash, trace.terminalSingularity.has_value());
    if (trace.terminalSingularity.has_value()) {
      field_aligned_hash_id(hash, *trace.terminalSingularity);
    }
    field_aligned_hash_consume(hash, trace.terminalContact.has_value());
    if (trace.terminalContact.has_value()) {
      const FieldAlignedTerminalContact &contact = *trace.terminalContact;
      field_aligned_hash_face(hash, contact.sourceFace);
      for (const authority::FieldExactRational &coordinate : contact.barycentric) {
        field_aligned_hash_exact(hash, coordinate);
      }
      field_aligned_hash_id(hash, contact.struckTrace);
      field_aligned_hash_consume(hash, contact.struckSegmentIndex);
    }
  }
  field_aligned_hash_consume(hash, candidate.events.size());
  for (const FieldAlignedNetworkEvent &event : candidate.events) {
    field_aligned_hash_id(hash, event.node);
    field_aligned_hash_consume(hash, static_cast<std::uint64_t>(event.kind));
    field_aligned_hash_face(hash, event.sourceFace);
    field_aligned_hash_consume(hash, event.sourceEdge.has_value());
    if (event.sourceEdge.has_value()) {
      field_aligned_hash_edge(hash, *event.sourceEdge);
    }
    field_aligned_hash_consume(hash, event.incidences.size());
    for (const FieldAlignedNetworkEventIncidence &incidence :
         event.incidences) {
      field_aligned_hash_id(hash, incidence.trace);
      field_aligned_hash_id(hash, incidence.sourcePort);
      field_aligned_hash_consume(hash,
                                 static_cast<std::uint64_t>(incidence.role));
    }
  }
  return hash;
}

std::optional<FieldAlignedCurveNetworkError> validate_field_aligned_candidate(
    const TriMesh &sourceMesh,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<SurfaceCellRail> &authoritativeRails,
    FieldAlignedCurveNetworkCandidate candidate) {
  const FieldAlignedCandidateResult canonical = canonical_field_aligned_candidate(
      sourceMesh, sourceAuthority, fieldTransportAtlas, authoritativeRails);
  if (const auto *error =
          std::get_if<FieldAlignedCurveNetworkError>(&canonical)) {
    return *error;
  }
  const FieldAlignedCurveNetworkCandidate &expected =
      std::get<FieldAlignedCurveNetworkCandidate>(canonical);

  if (candidate.sourceDigest != expected.sourceDigest) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidSourceBinding);
  }
  if (candidate.atlasDigest != expected.atlasDigest) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidAtlasBinding);
  }

  std::sort(candidate.nodes.begin(), candidate.nodes.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.sourceVertex, lhs.id) <
                     std::tie(rhs.sourceVertex, rhs.id);
            });
  if (candidate.nodes != expected.nodes) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidSourceBinding);
  }

  if (candidate.singularityPorts.size() != expected.singularityPorts.size()) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortCount);
  }
  std::sort(candidate.singularityPorts.begin(), candidate.singularityPorts.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.sourceVertex, lhs.singularity, lhs.ordinal,
                              lhs.id) <
                     std::tie(rhs.sourceVertex, rhs.singularity, rhs.ordinal,
                              rhs.id);
            });
  if (candidate.singularityPorts != expected.singularityPorts) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortOwnership);
  }

  std::set<authority::SourceEdgeTopologyKey> candidateEdges;
  std::map<authority::SourceEdgeTopologyKey, const FieldAlignedMandatoryEdge *>
      expectedByEdge;
  for (const FieldAlignedMandatoryEdge &edge : expected.mandatoryEdges) {
    expectedByEdge.emplace(edge.sourceEdge, &edge);
  }
  for (const FieldAlignedMandatoryEdge &edge : candidate.mandatoryEdges) {
    if (!candidateEdges.insert(edge.sourceEdge).second) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::DuplicateMandatoryEdge,
          std::nullopt, edge.sourceEdge, edge.rail);
    }
    if (expectedByEdge.count(edge.sourceEdge) == 0U) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::ForeignMandatoryEdge,
          std::nullopt, edge.sourceEdge, edge.rail);
    }
  }
  if (candidate.mandatoryEdges.size() < expected.mandatoryEdges.size()) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge);
  }
  if (candidate.mandatoryEdges.size() > expected.mandatoryEdges.size()) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::DuplicateMandatoryEdge);
  }
  std::sort(candidate.mandatoryEdges.begin(), candidate.mandatoryEdges.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.sourceEdge, lhs.rail, lhs.id) <
                     std::tie(rhs.sourceEdge, rhs.rail, rhs.id);
            });
  for (std::size_t index = 0; index < candidate.mandatoryEdges.size(); ++index) {
    const FieldAlignedMandatoryEdge &actual = candidate.mandatoryEdges[index];
    const FieldAlignedMandatoryEdge &wanted = expected.mandatoryEdges[index];
    if (actual.sourceEdge != wanted.sourceEdge) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::ForeignMandatoryEdge,
          std::nullopt, actual.sourceEdge, actual.rail);
    }
    if (actual.kind != wanted.kind) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MandatoryKindMismatch,
          std::nullopt, actual.sourceEdge, actual.rail);
    }
    if (actual != wanted) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::MandatoryOwnerMismatch,
          std::nullopt, actual.sourceEdge, actual.rail);
    }
  }

  if (candidate.arrivalPriority != expected.arrivalPriority) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding);
  }

  if (candidate.candidateTraces.size() != expected.candidateTraces.size()) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding);
  }
  std::sort(candidate.candidateTraces.begin(), candidate.candidateTraces.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.port, lhs.id) < std::tie(rhs.port, rhs.id);
            });
  for (std::size_t index = 0; index < candidate.candidateTraces.size();
       ++index) {
    const FieldAlignedCandidateTrace &actual = candidate.candidateTraces[index];
    const FieldAlignedCandidateTrace &wanted = expected.candidateTraces[index];
    if (actual.id != wanted.id || actual.port != wanted.port ||
        actual.singularity != wanted.singularity ||
        actual.sourceVertex != wanted.sourceVertex ||
        actual.sourceComponent != wanted.sourceComponent ||
        actual.sourceTopologyRegion != wanted.sourceTopologyRegion) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
          actual.sourceVertex, std::nullopt, std::nullopt, actual.singularity);
    }
    if (actual.segments != wanted.segments ||
        actual.terminalBarrier != wanted.terminalBarrier ||
        actual.terminalPoint != wanted.terminalPoint ||
        actual.terminalSingularity != wanted.terminalSingularity) {
      const std::optional<authority::SourceEdgeTopologyKey> sourceEdge =
          actual.segments.empty()
              ? std::optional<authority::SourceEdgeTopologyKey>{}
              : std::optional<authority::SourceEdgeTopologyKey>{
                    actual.segments.front().outgoingCarrier};
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport,
          actual.sourceVertex, sourceEdge, std::nullopt, actual.singularity);
    }
    if (actual.terminalContact != wanted.terminalContact) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding,
          actual.sourceVertex, std::nullopt, std::nullopt, actual.singularity);
    }
  }

  if (candidate.events.size() != expected.events.size()) {
    return field_aligned_error(
        FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding);
  }
  field_aligned_sort_events(candidate.events);
  for (std::size_t index = 0; index < candidate.events.size(); ++index) {
    const FieldAlignedNetworkEvent &actual = candidate.events[index];
    const FieldAlignedNetworkEvent &wanted = expected.events[index];
    if (actual.node != wanted.node || actual.kind != wanted.kind ||
        actual.sourceFace != wanted.sourceFace ||
        actual.sourceEdge != wanted.sourceEdge) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding,
          std::nullopt, actual.sourceEdge);
    }
    if (actual.incidences != wanted.incidences) {
      return field_aligned_error(
          FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventIncidence,
          std::nullopt, actual.sourceEdge);
    }
  }
  return std::nullopt;
}

} // namespace

std::optional<FieldAlignedArrivalMeasure>
field_aligned_filtered_arrival_measure(
    const TriMesh &sourceMesh,
    const authority::SourceFaceTopologyKey &sourceFace,
    const std::array<authority::FieldExactRational, 3> &first,
    const std::array<authority::FieldExactRational, 3> &second) {
  const auto length =
      field_aligned_filtered_length(sourceMesh, sourceFace, first, second);
  if (!length.has_value()) return std::nullopt;
  return field_aligned_arrival_advance(FieldAlignedArrivalMeasure{}, *length);
}

FieldAlignedSegmentContactClassification classify_field_aligned_segment_contact(
    const authority::FieldBranchTopology &topology,
    const FieldAlignedCandidateTraceSegment &first,
    const FieldAlignedCandidateTraceSegment &second) {
  return classify_field_aligned_segment_contact_impl(topology, first, second);
}

FieldAlignedContactCensusResult diagnose_field_aligned_contact_census(
    const TriMesh &sourceMesh,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<SurfaceCellRail> &authoritativeRails) {
  try {
    FieldAlignedContactCensus census;
    const FieldAlignedCandidateResult canonical = canonical_field_aligned_candidate(
        sourceMesh, sourceAuthority, fieldTransportAtlas, authoritativeRails,
        &census);
    if (const auto *error =
            std::get_if<FieldAlignedCurveNetworkError>(&canonical)) {
      return *error;
    }
    return census;
  } catch (const std::exception &) {
    FieldAlignedCurveNetworkError error;
    error.code = FieldAlignedCurveNetworkErrorCode::
        BranchContinuationExactMagnitudeExceeded;
    return error;
  }
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry {

FieldAlignedCurveNetworkBuildResult FieldAlignedCurveNetwork::make(
    const TriMesh &sourceMesh,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<SurfaceCellRail> &authoritativeRails) {
  // A2a is a closed producer (DESIGN.md 6.5): every outcome is a typed value.
  // The exact-rational backend signals its own runaway guards by throwing, and
  // an exception escaping here would leave the producer with no outcome at all.
  // The magnitude and recurrence guards are the primary policy and are expected
  // to fire first; this converts anything that still escapes into the same
  // typed rejection rather than into an abort.
  try {
    const auto canonical =
        surface_cell_tracing_detail::canonical_field_aligned_candidate(
            sourceMesh, sourceAuthority, fieldTransportAtlas,
            authoritativeRails);
    if (const auto *error =
            std::get_if<FieldAlignedCurveNetworkError>(&canonical)) {
      return FieldAlignedCurveNetworkBuildResult(*error);
    }
    return make_from_candidate(
        sourceMesh, sourceAuthority, fieldTransportAtlas, authoritativeRails,
        std::get<FieldAlignedCurveNetworkCandidate>(canonical));
  } catch (const std::exception &) {
    FieldAlignedCurveNetworkError error;
    error.code = FieldAlignedCurveNetworkErrorCode::
        BranchContinuationExactMagnitudeExceeded;
    return FieldAlignedCurveNetworkBuildResult(error);
  }
}

FieldAlignedCurveNetworkBuildResult
FieldAlignedCurveNetwork::diagnose_with_arrival_priority(
    const TriMesh &sourceMesh,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<SurfaceCellRail> &authoritativeRails,
    const FieldTraceArrivalPriority priority) {
  try {
    const auto canonical =
        surface_cell_tracing_detail::canonical_field_aligned_candidate(
            sourceMesh, sourceAuthority, fieldTransportAtlas,
            authoritativeRails, nullptr, priority);
    if (const auto *error =
            std::get_if<FieldAlignedCurveNetworkError>(&canonical)) {
      return FieldAlignedCurveNetworkBuildResult(*error);
    }
    FieldAlignedCurveNetworkCandidate published =
        std::get<FieldAlignedCurveNetworkCandidate>(canonical);
    const std::uint64_t sourceDigest =
        fieldTransportAtlas.quadrangulability().source_digest();
    const std::uint64_t atlasDigest =
        authority::field_transport_atlas_hash(fieldTransportAtlas);
    const std::uint64_t branchTopologyDigest =
        fieldTransportAtlas.branch_topology().semantic_digest();
    const std::uint64_t semanticDigest =
        surface_cell_tracing_detail::field_aligned_candidate_digest(
            published, sourceAuthority, sourceDigest, branchTopologyDigest);
    return FieldAlignedCurveNetworkBuildResult(FieldAlignedCurveNetwork(
        std::move(published.nodes), std::move(published.singularityPorts),
        std::move(published.mandatoryEdges),
        std::move(published.candidateTraces), std::move(published.events),
        published.arrivalPriority, sourceDigest, atlasDigest, semanticDigest));
  } catch (const std::exception &) {
    FieldAlignedCurveNetworkError error;
    error.code = FieldAlignedCurveNetworkErrorCode::
        BranchContinuationExactMagnitudeExceeded;
    return FieldAlignedCurveNetworkBuildResult(error);
  }
}

FieldAlignedCurveNetworkBuildResult
FieldAlignedCurveNetwork::make_from_candidate(
    const TriMesh &sourceMesh,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const std::vector<SurfaceCellRail> &authoritativeRails,
    FieldAlignedCurveNetworkCandidate candidate) {
  const auto error = surface_cell_tracing_detail::validate_field_aligned_candidate(
      sourceMesh, sourceAuthority, fieldTransportAtlas, authoritativeRails,
      candidate);
  if (error.has_value()) return FieldAlignedCurveNetworkBuildResult(*error);

  const auto canonical =
      surface_cell_tracing_detail::canonical_field_aligned_candidate(
          sourceMesh, sourceAuthority, fieldTransportAtlas, authoritativeRails);
  if (const auto *canonicalError =
          std::get_if<FieldAlignedCurveNetworkError>(&canonical)) {
    return FieldAlignedCurveNetworkBuildResult(*canonicalError);
  }
  FieldAlignedCurveNetworkCandidate published =
      std::get<FieldAlignedCurveNetworkCandidate>(canonical);
  const std::uint64_t sourceDigest =
      fieldTransportAtlas.quadrangulability().source_digest();
  const std::uint64_t atlasDigest =
      authority::field_transport_atlas_hash(fieldTransportAtlas);
  const std::uint64_t branchTopologyDigest =
      fieldTransportAtlas.branch_topology().semantic_digest();
  const std::uint64_t semanticDigest =
      surface_cell_tracing_detail::field_aligned_candidate_digest(
          published, sourceAuthority, sourceDigest, branchTopologyDigest);
  return FieldAlignedCurveNetworkBuildResult(FieldAlignedCurveNetwork(
      std::move(published.nodes), std::move(published.singularityPorts),
      std::move(published.mandatoryEdges),
      std::move(published.candidateTraces), std::move(published.events),
      published.arrivalPriority, sourceDigest, atlasDigest, semanticDigest));
}

const FieldAlignedMandatoryEdge *FieldAlignedCurveNetwork::find_mandatory_edge(
    const authority::SourceEdgeTopologyKey &sourceEdge) const noexcept {
  const auto found = std::lower_bound(
      mandatoryEdges_.begin(), mandatoryEdges_.end(), sourceEdge,
      [](const FieldAlignedMandatoryEdge &candidate,
         const authority::SourceEdgeTopologyKey &key) {
        return candidate.sourceEdge < key;
      });
  return found != mandatoryEdges_.end() && found->sourceEdge == sourceEdge
             ? &*found
             : nullptr;
}

bool FieldAlignedCurveNetwork::has_singularity(
    const authority::SourceVertexId sourceVertex) const noexcept {
  return std::any_of(
      singularityPorts_.begin(), singularityPorts_.end(),
      [&](const FieldAlignedSingularityPort &port) {
        return port.sourceVertex == sourceVertex;
      });
}

std::optional<int> FieldAlignedCurveNetwork::singularity_index_numerator(
    const authority::SourceVertexId sourceVertex) const noexcept {
  for (const FieldAlignedSingularityPort &port : singularityPorts_) {
    if (port.sourceVertex == sourceVertex) return port.indexNumerator;
  }
  return std::nullopt;
}

std::size_t FieldAlignedCurveNetwork::singularity_port_count(
    const authority::SourceVertexId sourceVertex) const noexcept {
  return static_cast<std::size_t>(std::count_if(
      singularityPorts_.begin(), singularityPorts_.end(),
      [&](const FieldAlignedSingularityPort &port) {
        return port.sourceVertex == sourceVertex;
      }));
}

std::vector<authority::SourceVertexId>
FieldAlignedCurveNetwork::singularity_vertices() const {
  std::vector<authority::SourceVertexId> vertices;
  for (const FieldAlignedSingularityPort &port : singularityPorts_) {
    if (vertices.empty() || vertices.back() != port.sourceVertex) {
      vertices.push_back(port.sourceVertex);
    }
  }
  return vertices;
}

FieldAlignedCurveNetworkCandidate
FieldAlignedCurveNetwork::validation_candidate() const {
  return FieldAlignedCurveNetworkCandidate{
      nodes_, singularityPorts_, mandatoryEdges_, candidateTraces_, events_,
      arrivalPriority_, sourceDigest_, atlasDigest_};
}

const char *field_aligned_curve_network_error_code_name(
    const FieldAlignedCurveNetworkErrorCode code) noexcept {
  switch (code) {
  case FieldAlignedCurveNetworkErrorCode::InvalidSourceBinding:
    return "InvalidSourceBinding";
  case FieldAlignedCurveNetworkErrorCode::InvalidAtlasBinding:
    return "InvalidAtlasBinding";
  case FieldAlignedCurveNetworkErrorCode::DuplicateRailId:
    return "DuplicateRailId";
  case FieldAlignedCurveNetworkErrorCode::InvalidRailGeometry:
    return "InvalidRailGeometry";
  case FieldAlignedCurveNetworkErrorCode::MissingMandatoryEdge:
    return "MissingMandatoryEdge";
  case FieldAlignedCurveNetworkErrorCode::DuplicateMandatoryEdge:
    return "DuplicateMandatoryEdge";
  case FieldAlignedCurveNetworkErrorCode::ForeignMandatoryEdge:
    return "ForeignMandatoryEdge";
  case FieldAlignedCurveNetworkErrorCode::MandatoryKindMismatch:
    return "MandatoryKindMismatch";
  case FieldAlignedCurveNetworkErrorCode::MandatoryOwnerMismatch:
    return "MandatoryOwnerMismatch";
  case FieldAlignedCurveNetworkErrorCode::InvalidSingularityBinding:
    return "InvalidSingularityBinding";
  case FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortCount:
    return "InvalidSingularityPortCount";
  case FieldAlignedCurveNetworkErrorCode::InvalidSingularityPortOwnership:
    return "InvalidSingularityPortOwnership";
  case FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceBinding:
    return "InvalidCandidateTraceBinding";
  case FieldAlignedCurveNetworkErrorCode::InvalidCandidateTraceTransport:
    return "InvalidCandidateTraceTransport";
  case FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventBinding:
    return "InvalidNetworkEventBinding";
  case FieldAlignedCurveNetworkErrorCode::InvalidNetworkEventIncidence:
    return "InvalidNetworkEventIncidence";
  case FieldAlignedCurveNetworkErrorCode::InvalidNetworkTerminalOwnership:
    return "InvalidNetworkTerminalOwnership";
  case FieldAlignedCurveNetworkErrorCode::BranchDirectionNotBarycentric:
    return "BranchDirectionNotBarycentric";
  case FieldAlignedCurveNetworkErrorCode::BranchContinuationNoOutflow:
    return "BranchContinuationNoOutflow";
  case FieldAlignedCurveNetworkErrorCode::BranchContinuationDegenerateEntry:
    return "BranchContinuationDegenerateEntry";
  case FieldAlignedCurveNetworkErrorCode::BranchContinuationMinimizerImpossible:
    return "BranchContinuationMinimizerImpossible";
  case FieldAlignedCurveNetworkErrorCode::BranchContinuationOutsideOutflowSet:
    return "BranchContinuationOutsideOutflowSet";
  case FieldAlignedCurveNetworkErrorCode::BoundaryPointParameterOutOfRange:
    return "BoundaryPointParameterOutOfRange";
  case FieldAlignedCurveNetworkErrorCode::BoundaryPointEdgeNotIncidentToFace:
    return "BoundaryPointEdgeNotIncidentToFace";
  case FieldAlignedCurveNetworkErrorCode::VertexTransitSectorUnresolved:
    return "VertexTransitSectorUnresolved";
  case FieldAlignedCurveNetworkErrorCode::BranchTransportFlowDisagreement:
    return "BranchTransportFlowDisagreement";
  case FieldAlignedCurveNetworkErrorCode::TraceStateCycleDetected:
    return "TraceStateCycleDetected";
  case FieldAlignedCurveNetworkErrorCode::TraceStepBudgetExhausted:
    return "TraceStepBudgetExhausted";
  case FieldAlignedCurveNetworkErrorCode::BranchGrazingSlideDirectionAmbiguous:
    return "BranchGrazingSlideDirectionAmbiguous";
  case FieldAlignedCurveNetworkErrorCode::TraceCombinatorialRecurrenceExceeded:
    return "TraceCombinatorialRecurrenceExceeded";
  case FieldAlignedCurveNetworkErrorCode::
      BranchContinuationExactMagnitudeExceeded:
    return "BranchContinuationExactMagnitudeExceeded";
  case FieldAlignedCurveNetworkErrorCode::VertexTransitSeedUnavailable:
    return "VertexTransitSeedUnavailable";
  case FieldAlignedCurveNetworkErrorCode::VertexTransitWalkUnexamined:
    return "VertexTransitWalkUnexamined";
  case FieldAlignedCurveNetworkErrorCode::VertexStarTruncatedBeforeContinuation:
    return "VertexStarTruncatedBeforeContinuation";
  case FieldAlignedCurveNetworkErrorCode::VertexStarDegenerateSector:
    return "VertexStarDegenerateSector";
  case FieldAlignedCurveNetworkErrorCode::VertexStarExactBudgetExceeded:
    return "VertexStarExactBudgetExceeded";
  }
  return "Unknown";
}

const char *field_vertex_transit_state_outcome_name(
    const FieldVertexTransitStateOutcome outcome) noexcept {
  switch (outcome) {
  case FieldVertexTransitStateOutcome::Evaluated:
    return "Evaluated";
  case FieldVertexTransitStateOutcome::SeedFrameUnavailable:
    return "SeedFrameUnavailable";
  case FieldVertexTransitStateOutcome::SeedAuthorityMismatch:
    return "SeedAuthorityMismatch";
  case FieldVertexTransitStateOutcome::SeedBranchPairingMissing:
    return "SeedBranchPairingMissing";
  case FieldVertexTransitStateOutcome::SeedBranchPairingAmbiguous:
    return "SeedBranchPairingAmbiguous";
  case FieldVertexTransitStateOutcome::StateFrameUnavailable:
    return "StateFrameUnavailable";
  case FieldVertexTransitStateOutcome::StateAuthorityMismatch:
    return "StateAuthorityMismatch";
  case FieldVertexTransitStateOutcome::StateBranchPairingMissing:
    return "StateBranchPairingMissing";
  case FieldVertexTransitStateOutcome::StateBranchPairingAmbiguous:
    return "StateBranchPairingAmbiguous";
  case FieldVertexTransitStateOutcome::StateSourceFaceRowUnavailable:
    return "StateSourceFaceRowUnavailable";
  case FieldVertexTransitStateOutcome::DirectedTransportUnavailable:
    return "DirectedTransportUnavailable";
  case FieldVertexTransitStateOutcome::TransportTargetFrameUnavailable:
    return "TransportTargetFrameUnavailable";
  case FieldVertexTransitStateOutcome::TransportTargetAuthorityMismatch:
    return "TransportTargetAuthorityMismatch";
  case FieldVertexTransitStateOutcome::TransportTargetBranchPairingMissing:
    return "TransportTargetBranchPairingMissing";
  case FieldVertexTransitStateOutcome::TransportTargetBranchPairingAmbiguous:
    return "TransportTargetBranchPairingAmbiguous";
  case FieldVertexTransitStateOutcome::SeedDirectionNotBarycentric:
    return "SeedDirectionNotBarycentric";
  case FieldVertexTransitStateOutcome::StateRepresentativeDirectionNotBarycentric:
    return "StateRepresentativeDirectionNotBarycentric";
  case FieldVertexTransitStateOutcome::StateIncomingDirectionNotBarycentric:
    return "StateIncomingDirectionNotBarycentric";
  case FieldVertexTransitStateOutcome::TransportTargetDirectionNotBarycentric:
    return "TransportTargetDirectionNotBarycentric";
  case FieldVertexTransitStateOutcome::DuplicateStateSuppressed:
    return "DuplicateStateSuppressed";
  case FieldVertexTransitStateOutcome::SeedArrivalFaceRowUnavailable:
    return "SeedArrivalFaceRowUnavailable";
  case FieldVertexTransitStateOutcome::SeedDirectionOutsideClosedWedge:
    return "SeedDirectionOutsideClosedWedge";
  }
  return "Unknown";
}

std::uint64_t field_aligned_curve_network_hash(
    const FieldAlignedCurveNetwork &network) noexcept {
  return network.semantic_digest();
}

} // namespace directional::geometry

namespace directional::geometry::surface_cell_tracing_detail {

EdgeTransitionLookup edge_transition_lookup(
    const std::vector<fields::CrossFieldEdgeTransition> &transitions,
    const std::size_t vertexExtent) {
  EdgeTransitionLookup lookup;
  for (const fields::CrossFieldEdgeTransition &transition : transitions) {
    if (transition.sourceVertex0 < 0 || transition.sourceVertex1 < 0) {
      lookup.duplicate = true;
      continue;
    }
    const auto key = edge_key(transition.sourceVertex0,
                              transition.sourceVertex1, vertexExtent);
    if (!lookup.byEdge.emplace(key, transition).second) {
      lookup.duplicate = true;
    }
  }
  return lookup;
}

EdgeTransitionLookup edge_transition_lookup(
    const authority::FieldTransportAtlas &atlas) {
  EdgeTransitionLookup lookup;
  lookup.atlas = &atlas;
  return lookup;
}

EdgeTransitionLookup authoritative_edge_transition_lookup(
    const authority::FieldTransportAtlas *atlas,
    const std::vector<fields::CrossFieldEdgeTransition> *transitions,
    const std::size_t vertexExtent) {
  if (atlas != nullptr) return edge_transition_lookup(*atlas);
  return transitions != nullptr
             ? edge_transition_lookup(*transitions, vertexExtent)
             : EdgeTransitionLookup{};
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool contains_vertex(const std::vector<int> &vertices,
                            const int vertex) {
  return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool tracing_has_singularities(const SurfaceCellTracingOptions &options) {
  return options.fieldAlignedNetwork != nullptr
             ? !options.fieldAlignedNetwork->singularity_ports().empty()
             : !options.singularityVertices.empty();
}

bool tracing_is_singularity_vertex(const SurfaceCellTracingOptions &options,
                                   const Eigen::MatrixXi &faces,
                                   const int vertex) {
  if (options.fieldAlignedNetwork == nullptr) {
    return contains_vertex(options.singularityVertices, vertex);
  }
  const auto typed = authority::SourceVertexId::from_index(
      vertex, source_vertex_extent(faces));
  return typed && options.fieldAlignedNetwork->has_singularity(typed.value());
}

std::optional<std::vector<std::pair<int, int>>> tracing_singularity_inputs(
    const SurfaceCellTracingOptions &options, const Eigen::MatrixXi &faces) {
  std::vector<std::pair<int, int>> result;
  if (options.fieldAlignedNetwork != nullptr) {
    for (const authority::SourceVertexId vertex :
         options.fieldAlignedNetwork->singularity_vertices()) {
      const auto index =
          options.fieldAlignedNetwork->singularity_index_numerator(vertex);
      if (!index.has_value() ||
          options.fieldAlignedNetwork->singularity_port_count(vertex) !=
              static_cast<std::size_t>(4 - *index)) {
        return std::nullopt;
      }
      result.emplace_back(static_cast<int>(vertex.index()), *index);
    }
    return result;
  }
  // Legacy/focused-test ingress historically permits membership-only
  // singularity vectors. Exact separatrix enumeration is enabled only when
  // the parallel index vector is present.
  if (options.singularityIndexNumerators.empty()) return result;
  if (options.singularityIndexNumerators.size() !=
      options.singularityVertices.size()) {
    return std::nullopt;
  }
  for (std::size_t index = 0; index < options.singularityVertices.size();
       ++index) {
    result.emplace_back(options.singularityVertices[index],
                        options.singularityIndexNumerators[index]);
  }
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::vector<std::vector<int>>
incident_faces_by_vertex(const int vertexCount, const Eigen::MatrixXi &faces) {
  std::vector<std::vector<int>> incident(static_cast<std::size_t>(vertexCount));
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      if (vertex >= 0 && vertex < vertexCount) {
        incident[static_cast<std::size_t>(vertex)].push_back(face);
      }
    }
  }
  for (auto &facesForVertex : incident) {
    std::sort(facesForVertex.begin(), facesForVertex.end());
    facesForVertex.erase(std::unique(facesForVertex.begin(),
                                     facesForVertex.end()),
                         facesForVertex.end());
  }
  return incident;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

SurfaceTracePoint vertex_point(
    const int vertex, const std::vector<std::vector<int>> &incident,
    const Eigen::MatrixXi &faces) {
  SurfaceTracePoint point;
  if (vertex < 0 || vertex >= static_cast<int>(incident.size()) ||
      incident[static_cast<std::size_t>(vertex)].empty()) {
    return point;
  }
  point.face = incident[static_cast<std::size_t>(vertex)].front();
  for (int corner = 0; corner < 3; ++corner) {
    point.barycentric[corner] = faces(point.face, corner) == vertex ? 1.0 : 0.0;
  }
  return point;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double target_size_at_vertex(const Eigen::VectorXd &targetSize,
                                    const int vertex,
                                    const double fallback) {
  if (vertex >= 0 && vertex < targetSize.size() &&
      std::isfinite(targetSize[vertex]) && targetSize[vertex] > 0.0) {
    return targetSize[vertex];
  }
  return fallback;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool initialize_seed(
    const std::vector<SurfaceTraceSeed> &seeds,
    std::set<std::tuple<int, std::int64_t, std::int64_t, std::int64_t>> &seen,
    const SurfaceTracePoint &point, const SurfaceSeedProvenance provenance,
    SurfaceTraceSeed &seed) {
  if (point.face < 0) {
    return false;
  }
  const auto key = std::make_tuple(
      point.face,
      static_cast<std::int64_t>(
          std::llround(point.barycentric[0] * 1.0e15)),
      static_cast<std::int64_t>(
          std::llround(point.barycentric[1] * 1.0e15)),
      static_cast<std::int64_t>(
          std::llround(point.barycentric[2] * 1.0e15)));
  if (!seen.insert(key).second) {
    return false;
  }
  seed.id = static_cast<int>(seeds.size());
  seed.point = point;
  seed.provenance = provenance;
  return true;
}

void append_seed(std::vector<SurfaceTraceSeed> &seeds,
                 std::set<std::tuple<int, std::int64_t, std::int64_t,
                                     std::int64_t>> &seen,
                 const SurfaceTracePoint &point,
                 const SurfaceSeedProvenance provenance,
                 const int sourceId) {
  SurfaceTraceSeed seed;
  if (!initialize_seed(seeds, seen, point, provenance, seed)) {
    return;
  }
  seed.sourceId = sourceId;
  seeds.push_back(std::move(seed));
}

void append_hard_rail_seed(
    std::vector<SurfaceTraceSeed> &seeds,
    std::set<std::tuple<int, std::int64_t, std::int64_t, std::int64_t>> &seen,
    const SurfaceTracePoint &point, const SurfaceSeedProvenance provenance,
    const authority::HardRailId railId) {
  SurfaceTraceSeed seed;
  if (!initialize_seed(seeds, seen, point, provenance, seed)) {
    return;
  }
  seed.hardRailId = railId;
  seeds.push_back(std::move(seed));
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool point_on_edge(const Eigen::RowVector3d &bary, const int edgeCorner,
                          const double eps) {
  return std::abs(bary[edgeCorner]) <= eps;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int hit_vertex(const Eigen::RowVector3d &bary,
                      const double eps) {
  int one = -1;
  for (int corner = 0; corner < 3; ++corner) {
    if (bary[corner] >= 1.0 - eps) {
      one = corner;
    }
  }
  return one;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int dominant_vertex_corner(const Eigen::RowVector3d &bary) {
  int best = 0;
  for (int corner = 1; corner < 3; ++corner) {
    if (bary[corner] > bary[best]) {
      best = corner;
    }
  }
  return best;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d remap_barycentric_to_neighbor(
    const Eigen::MatrixXi &faces, const int fromFace, const int toFace,
    const Eigen::RowVector3d &fromBary) {
  Eigen::RowVector3d to = Eigen::RowVector3d::Zero();
  for (int fromCorner = 0; fromCorner < 3; ++fromCorner) {
    const int vertex = faces(fromFace, fromCorner);
    for (int toCorner = 0; toCorner < 3; ++toCorner) {
      if (faces(toFace, toCorner) == vertex) {
        to[toCorner] = fromBary[fromCorner];
      }
    }
  }
  return to;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool barycentric_derivative(const Eigen::MatrixXd &vertices,
                                   const Eigen::MatrixXi &faces,
                                   const int face,
                                   const Eigen::RowVector3d &direction,
                                   Eigen::RowVector3d &dbary) {
  const Eigen::RowVector3d a = row3(vertices, faces(face, 0));
  const Eigen::RowVector3d b = row3(vertices, faces(face, 1));
  const Eigen::RowVector3d c = row3(vertices, faces(face, 2));
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = (b - a).transpose();
  basis.col(1) = (c - a).transpose();
  const Eigen::Vector2d uv =
      (basis.transpose() * basis).ldlt().solve(basis.transpose() *
                                               direction.transpose());
  if (!uv.allFinite()) {
    return false;
  }
  dbary << -uv[0] - uv[1], uv[0], uv[1];
  return dbary.allFinite() && dbary.squaredNorm() > 0.0;
}

/**
 * Orient one matched cross-field family into the target face after an edge
 * crossing. A 4-RoSy family contains both opposite rays; authoritative
 * matching determines the family, while the trace orientation must choose
 * the ray whose barycentric derivative moves away from the shared edge.
 */
bool orient_transition_into_face_from_edge(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int targetFace, const int entryEdge,
    BranchTransitionResult &transition) {
  if (!transition.valid || targetFace < 0 || targetFace >= faces.rows() ||
      entryEdge < 0 || entryEdge >= 3) {
    return false;
  }
  Eigen::RowVector3d derivative;
  if (!barycentric_derivative(vertices, faces, targetFace,
                              transition.direction, derivative)) {
    return false;
  }
  constexpr double entryTolerance = 1.0e-12;
  if (derivative[entryEdge] > entryTolerance) {
    return true;
  }
  if (derivative[entryEdge] >= -entryTolerance) {
    return false;
  }

  transition.direction *= -1.0;
  transition.sign *= -1;
  if (!barycentric_derivative(vertices, faces, targetFace,
                              transition.direction, derivative) ||
      derivative[entryEdge] <= entryTolerance) {
    return false;
  }
  transition.turnAngle = std::acos(std::clamp(
      transition.transportedInput.dot(transition.direction), -1.0, 1.0));
  transition.valid = std::isfinite(transition.turnAngle) &&
                     transition.direction.array().isFinite().all();
  return transition.valid;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_authority_valid(const SurfaceCellTracingOptions &options,
                            const Eigen::MatrixXi &faces) {
  if (options.sourceAuthority == nullptr) {
    return options.fieldTransportAtlas == nullptr;
  }
  return options.sourceAuthority->matches_source_faces(faces) &&
         (options.fieldTransportAtlas == nullptr ||
          options.fieldTransportAtlas->matches_source_faces(
              faces, *options.sourceAuthority, source_vertex_extent(faces)));
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_faces_compatible(const SurfaceCellTracingOptions &options,
                             const int a, const int b) {
  if (options.sourceAuthority == nullptr) {
    return true;
  }
  if (a < 0 || b < 0 ||
      static_cast<std::size_t>(a) >= options.sourceAuthority->face_count() ||
      static_cast<std::size_t>(b) >= options.sourceAuthority->face_count()) {
    return false;
  }
  const auto first = authority::SourceFaceId::from_index(
      a, options.sourceAuthority->face_count());
  const auto second = authority::SourceFaceId::from_index(
      b, options.sourceAuthority->face_count());
  return first && second &&
         options.sourceAuthority->component_for_row(first.value()) ==
             options.sourceAuthority->component_for_row(second.value()) &&
         options.sourceAuthority->sheet_for_row(first.value()) ==
             options.sourceAuthority->sheet_for_row(second.value());
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_edge_is_authoritative_local_boundary(
    const SurfaceCellTracingOptions &options, const int faceCount,
    const int localFace, const std::array<int, 2> &fullIncident,
    const authority::SourceEdgeTopologyKey &edgeKey) {
  if (faceCount <= 0 || localFace < 0 || localFace >= faceCount) {
    return false;
  }

  int localIncidentCount = 0;
  int incidentCount = 0;
  int oppositeFace = -1;
  for (const int incidentFace : fullIncident) {
    if (incidentFace < 0) {
      continue;
    }
    if (incidentFace >= faceCount) {
      return false;
    }
    ++incidentCount;
    if (incidentFace == localFace) {
      ++localIncidentCount;
      continue;
    }
    if (oppositeFace >= 0) {
      return false;
    }
    oppositeFace = incidentFace;
  }

  if (localIncidentCount != 1) {
    return false;
  }
  if (incidentCount == 1) {
    return true;
  }
  if (incidentCount != 2 || oppositeFace < 0) {
    return false;
  }
  if (options.hardFeatureEdges.count(edgeKey) != 0U) {
    return true;
  }
  if (options.reliefBarriersEmbedded &&
      options.reliefBarrierEdges.count(edgeKey) != 0U) {
    return true;
  }
  // Local isolation-sheet disagreement alone is not a physical producer
  // boundary. If both source faces are present across a non-hard manifold edge,
  // producer topology remains connected through exact source adjacency.
  return false;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_faces_share_component(const SurfaceCellTracingOptions &options,
                                  const int a, const int b) {
  if (options.sourceAuthority == nullptr) {
    return true;
  }
  if (a < 0 || b < 0 ||
      static_cast<std::size_t>(a) >= options.sourceAuthority->face_count() ||
      static_cast<std::size_t>(b) >= options.sourceAuthority->face_count()) {
    return false;
  }
  const auto first = authority::SourceFaceId::from_index(
      a, options.sourceAuthority->face_count());
  const auto second = authority::SourceFaceId::from_index(
      b, options.sourceAuthority->face_count());
  return first && second &&
         options.sourceAuthority->component_for_row(first.value()) ==
             options.sourceAuthority->component_for_row(second.value());
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int local_edge_for_key(const Eigen::MatrixXi &faces, const int face,
                       const authority::SourceEdgeTopologyKey &key) {
  if (face < 0 || face >= faces.rows()) {
    return -1;
  }
  const std::size_t vertexExtent = source_vertex_extent(faces);
  for (int edge = 0; edge < 3; ++edge) {
    const int a = faces(face, (edge + 1) % 3);
    const int b = faces(face, (edge + 2) % 3);
    if (edge_key(a, b, vertexExtent) == key) {
      return edge;
    }
  }
  return -1;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

authority::SourceEdgeTopologyKey local_edge_key(const Eigen::MatrixXi &faces,
                                                 const int face,
                                                 const int edge) {
  if (face < 0 || face >= faces.rows() || edge < 0 || edge >= 3) {
    throw std::invalid_argument("invalid local source edge");
  }
  return edge_key(faces(face, (edge + 1) % 3),
                  faces(face, (edge + 2) % 3), source_vertex_extent(faces));
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool rail_sample_is_finite(const SurfaceCellRailSample &sample) {
  return std::isfinite(sample.parameter) &&
         std::isfinite(sample.railParameter) &&
         sample.barycentric.allFinite() && sample.position.allFinite();
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double rail_position_tolerance(const Eigen::RowVector3d &a,
                                      const Eigen::RowVector3d &b) {
  return 1.0e-8 * std::max({1.0, a.norm(), b.norm()});
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double rail_parameter_tolerance(const double a, const double b) {
  return 1.0e-10 * std::max({1.0, std::abs(a), std::abs(b)});
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int rail_sample_source_vertex(const Eigen::MatrixXi &faces,
                                     const SurfaceCellRailSample &sample) {
  constexpr double tolerance = 1.0e-8;
  if (sample.sourceFace < 0 || sample.sourceFace >= faces.rows() ||
      sample.sourceEdge < 0 || sample.sourceEdge >= 3 ||
      !sample.barycentric.allFinite()) {
    return -1;
  }
  int vertexCorner = -1;
  for (int corner = 0; corner < 3; ++corner) {
    const double value = sample.barycentric[corner];
    if (std::abs(value - 1.0) <= tolerance) {
      if (vertexCorner >= 0) {
        return -1;
      }
      vertexCorner = corner;
    } else if (std::abs(value) > tolerance) {
      return -1;
    }
  }
  if (vertexCorner < 0 || vertexCorner == sample.sourceEdge) {
    return -1;
  }
  return faces(sample.sourceFace, vertexCorner);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool rail_sample_geometry_is_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellRailSample &sample) {
  constexpr double tolerance = 1.0e-8;
  if (!rail_sample_is_finite(sample) || sample.sourceFace < 0 ||
      sample.sourceFace >= faces.rows() || sample.sourceEdge < 0 ||
      sample.sourceEdge >= 3 || sample.parameter < -tolerance ||
      sample.parameter > 1.0 + tolerance ||
      std::abs(sample.barycentric.sum() - 1.0) > tolerance ||
      std::abs(sample.barycentric[sample.sourceEdge]) > tolerance) {
    return false;
  }
  for (int corner = 0; corner < 3; ++corner) {
    if (sample.barycentric[corner] < -tolerance ||
        sample.barycentric[corner] > 1.0 + tolerance) {
      return false;
    }
  }
  const int sourceVertex = rail_sample_source_vertex(faces, sample);
  if (sourceVertex < 0 || sourceVertex >= vertices.rows()) {
    return false;
  }
  const Eigen::RowVector3d expected = vertices.row(sourceVertex);
  return (expected - sample.position).norm() <=
         rail_position_tolerance(expected, sample.position);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

RailIntervalBuildResult
rail_interval_refs(
    const std::vector<SurfaceCellRail> &rails,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces,
    const FieldAlignedCurveNetwork *fieldAlignedNetwork) {
  RailIntervalBuildResult result;
  std::set<authority::HardRailId> railIds;
  std::map<authority::SourceEdgeTopologyKey, authority::HardRailId> edgeOwners;
  std::set<authority::NetworkEdgeId> matchedMandatoryEdges;
  for (const SurfaceCellRail &rail : rails) {
    if (!railIds.insert(rail.id).second) {
      result.status = RailBuildStatus::DuplicateRailId;
      result.railId = rail.id;
      return result;
    }
    if (rail.samples.empty()) {
      result.status = RailBuildStatus::EmptyRail;
      result.railId = rail.id;
      return result;
    }
    if ((rail.samples.size() % 2U) != 0U) {
      result.status = RailBuildStatus::OddSampleCount;
      result.railId = rail.id;
      result.intervalIndex = static_cast<int>(rail.samples.size() / 2U);
      return result;
    }
    const int intervalCount = static_cast<int>(rail.samples.size()) / 2;
    const std::size_t railStart = result.intervals.size();
    int firstStartVertex = -1;
    int previousEndVertex = -1;
    Eigen::RowVector3d firstStartPosition = Eigen::RowVector3d::Zero();
    Eigen::RowVector3d previousEndPosition = Eigen::RowVector3d::Zero();
    double previousEndParameter = 0.0;
    int railParameterDirection = 0;
    for (int interval = 0; interval < intervalCount; ++interval) {
      const int i = 2 * interval;
      const SurfaceCellRailSample &a =
          rail.samples[static_cast<std::size_t>(i)];
      const SurfaceCellRailSample &b =
          rail.samples[static_cast<std::size_t>(i + 1)];
      if (a.sourceFace < 0 || a.sourceFace >= faces.rows() ||
          a.sourceEdge < 0 || a.sourceEdge >= 3 ||
          b.sourceFace != a.sourceFace || b.sourceEdge != a.sourceEdge) {
        result.status = RailBuildStatus::InvalidSamplePair;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      if (!rail_sample_geometry_is_valid(vertices, faces, a) ||
          !rail_sample_geometry_is_valid(vertices, faces, b)) {
        result.status = RailBuildStatus::InvalidSampleGeometry;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      const int startVertex = rail_sample_source_vertex(faces, a);
      const int endVertex = rail_sample_source_vertex(faces, b);
      const bool localParametersValid =
          (std::abs(a.parameter) <= 1.0e-8 &&
           std::abs(b.parameter - 1.0) <= 1.0e-8) ||
          (std::abs(a.parameter - 1.0) <= 1.0e-8 &&
           std::abs(b.parameter) <= 1.0e-8);
      const double parameterDelta = b.railParameter - a.railParameter;
      const double parameterTolerance =
          rail_parameter_tolerance(a.railParameter, b.railParameter);
      if (!localParametersValid || startVertex < 0 || endVertex < 0 ||
          startVertex == endVertex ||
          (a.position - b.position).norm() <=
              rail_position_tolerance(a.position, b.position) ||
          std::abs(parameterDelta) <= parameterTolerance) {
        result.status = RailBuildStatus::InvalidRailParameters;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      const int parameterDirection = parameterDelta > 0.0 ? 1 : -1;
      if (railParameterDirection == 0) {
        railParameterDirection = parameterDirection;
      } else if (parameterDirection != railParameterDirection) {
        result.status = RailBuildStatus::InvalidRailParameters;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      if (interval == 0) {
        firstStartVertex = startVertex;
        firstStartPosition = a.position;
      } else {
        if (startVertex != previousEndVertex ||
            (a.position - previousEndPosition).norm() >
                rail_position_tolerance(a.position, previousEndPosition)) {
          result.status = RailBuildStatus::DisconnectedIntervals;
          result.railId = rail.id;
          result.intervalIndex = interval;
          return result;
        }
        if (std::abs(a.railParameter - previousEndParameter) >
            rail_parameter_tolerance(a.railParameter,
                                     previousEndParameter)) {
          result.status = RailBuildStatus::NonContiguousIntervals;
          result.railId = rail.id;
          result.intervalIndex = interval;
          return result;
        }
      }
      previousEndVertex = endVertex;
      previousEndPosition = b.position;
      previousEndParameter = b.railParameter;

      const authority::SourceEdgeTopologyKey key =
          local_edge_key(faces, a.sourceFace, a.sourceEdge);
      if (fieldAlignedNetwork != nullptr) {
        const FieldAlignedMandatoryEdge *mandatory =
            fieldAlignedNetwork->find_mandatory_edge(key);
        if (mandatory == nullptr || mandatory->rail != rail.id ||
            mandatory->kind != rail.kind) {
          result.status = RailBuildStatus::TypedAuthorityMismatch;
          result.railId = rail.id;
          result.intervalIndex = interval;
          return result;
        }
        matchedMandatoryEdges.insert(mandatory->id);
      }
      const auto owner = edgeOwners.find(key);
      if (owner != edgeOwners.end()) {
        result.status = RailBuildStatus::DuplicateInterval;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      edgeOwners.emplace(key, rail.id);

      SurfaceCellRailIntervalRef ref(rail.id);
      ref.curveId = rail.curveId;
      ref.intervalIndex = interval;
      ref.sourceFace = a.sourceFace;
      ref.sourceEdge = a.sourceEdge;
      ref.edgeKey = key;
      ref.closed = rail.closed;
      ref.kind = rail.kind;
      ref.start = a;
      ref.end = b;
      const auto found = edgeFaces.find(key);
      if (found == edgeFaces.end()) {
        result.status = RailBuildStatus::InvalidIncidentSides;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      for (const int sideFace : found->second) {
        if (sideFace < 0) {
          continue;
        }
        const int sideEdge = local_edge_for_key(faces, sideFace, key);
        if (sideEdge < 0) {
          continue;
        }
        SurfaceCellRailIntervalRef::FaceSideEmbedding side;
        side.sourceFace = sideFace;
        side.sourceEdge = sideEdge;
        side.startBarycentric = remap_barycentric_to_neighbor(
            faces, a.sourceFace, sideFace, a.barycentric);
        side.endBarycentric = remap_barycentric_to_neighbor(
            faces, a.sourceFace, sideFace, b.barycentric);
        const int localEndCorner = (sideEdge + 2) % 3;
        const double localDelta = side.endBarycentric[localEndCorner] -
                                  side.startBarycentric[localEndCorner];
        side.sideSign = localDelta * parameterDelta >= 0.0 ? 1 : -1;
        ref.incidentSides.push_back(side);
      }
      std::sort(ref.incidentSides.begin(), ref.incidentSides.end(),
                [](const auto &lhs, const auto &rhs) {
                  return std::tie(lhs.sourceFace, lhs.sourceEdge) <
                         std::tie(rhs.sourceFace, rhs.sourceEdge);
                });
      if (ref.incidentSides.empty() ||
          (ref.incidentSides.size() == 2U &&
           ref.incidentSides[0].sideSign == ref.incidentSides[1].sideSign)) {
        result.status = RailBuildStatus::InvalidIncidentSides;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      result.intervals.push_back(std::move(ref));
    }
    if (result.intervals.size() - railStart !=
        static_cast<std::size_t>(intervalCount)) {
      result.status = RailBuildStatus::NonContiguousIntervals;
      result.railId = rail.id;
      return result;
    }
    if (rail.closed) {
      if (intervalCount < 2 || previousEndVertex != firstStartVertex ||
          (previousEndPosition - firstStartPosition).norm() >
              rail_position_tolerance(previousEndPosition,
                                      firstStartPosition)) {
        result.status = RailBuildStatus::InvalidClosedLoop;
        result.railId = rail.id;
        return result;
      }
    }
  }
  if (fieldAlignedNetwork != nullptr &&
      matchedMandatoryEdges.size() !=
          fieldAlignedNetwork->mandatory_edges().size()) {
    result.status = RailBuildStatus::TypedAuthorityMismatch;
    return result;
  }
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

SurfaceCellRailIntervalSelection find_rail_interval(
    const std::vector<SurfaceCellRailIntervalRef> &intervals, const int face,
    const int edge) {
  for (const SurfaceCellRailIntervalRef &interval : intervals) {
    if (interval.kind != SurfaceCellRailKind::HardFeature) {
      continue;
    }
    for (const SurfaceCellRailIntervalRef::FaceSideEmbedding &side :
         interval.incidentSides) {
      if (side.sourceFace == face && side.sourceEdge == edge) {
        return {&interval, side};
      }
    }
  }
  return {};
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

RailContinuationResult find_next_rail_interval(
    const std::vector<SurfaceCellRailIntervalRef> &intervals,
    const SurfaceCellRailIntervalSelection &current, const int direction,
    const SurfaceCellTracingOptions &options) {
  if (current.interval == nullptr) {
    return {RailContinuationStatus::MissingInterval, {}};
  }
  int target = current.interval->intervalIndex + (direction >= 0 ? 1 : -1);
  int count = 0;
  for (const SurfaceCellRailIntervalRef &interval : intervals) {
    if (interval.railId == current.interval->railId) {
      ++count;
    }
  }
  if (current.interval->closed) {
    if (count > 0) {
      target = (target % count + count) % count;
    }
  } else if (target < 0 || target >= count) {
    return {RailContinuationStatus::OpenEndpoint, {}};
  }
  for (const SurfaceCellRailIntervalRef &interval : intervals) {
    if (interval.railId != current.interval->railId ||
        interval.intervalIndex != target) {
      continue;
    }
    bool hasSameSide = false;
    for (const SurfaceCellRailIntervalRef::FaceSideEmbedding &side :
         interval.incidentSides) {
      if (side.sideSign != current.side.sideSign) {
        continue;
      }
      hasSameSide = true;
      if (side.sourceFace == current.side.sourceFace &&
          source_faces_share_component(options, current.side.sourceFace,
                                  side.sourceFace)) {
        return {RailContinuationStatus::Found, {&interval, side}};
      }
    }
    for (const SurfaceCellRailIntervalRef::FaceSideEmbedding &side :
         interval.incidentSides) {
      if (side.sideSign == current.side.sideSign &&
          source_faces_share_component(options, current.side.sourceFace,
                                  side.sourceFace)) {
        return {RailContinuationStatus::Found, {&interval, side}};
      }
    }
    return {hasSameSide ? RailContinuationStatus::SourceSheetBlocked
                        : RailContinuationStatus::SideDiscontinuity,
            {}};
  }
  return {RailContinuationStatus::MissingInterval, {}};
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double rail_parameter_at_position(
    const SurfaceCellRailIntervalRef &interval,
    const Eigen::RowVector3d &position) {
  const Eigen::RowVector3d delta =
      interval.end.position - interval.start.position;
  const double lengthSquared = delta.squaredNorm();
  if (lengthSquared <= 0.0) {
    return interval.start.railParameter;
  }
  const double u = std::clamp(
      (position - interval.start.position).dot(delta) / lengthSquared,
      0.0, 1.0);
  return interval.start.railParameter +
         u * (interval.end.railParameter - interval.start.railParameter);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d rail_direction(
    const SurfaceCellRailIntervalRef &interval, const int direction) {
  Eigen::RowVector3d delta = interval.end.position - interval.start.position;
  if (direction < 0) {
    delta *= -1.0;
  }
  const double norm = delta.norm();
  if (norm > 0.0) {
    delta /= norm;
    return delta;
  }
  return Eigen::RowVector3d::Zero();
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int branch_from_family_sign(const int family, const int sign) {
  return (family == 0 ? 0 : 1) + (sign >= 0 ? 0 : 2);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

void family_sign_from_branch(const int branch, int &family, int &sign) {
  const int normalized = ((branch % 4) + 4) % 4;
  family = normalized % 2;
  sign = normalized < 2 ? 1 : -1;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d axis_for_family(const Eigen::MatrixXd &faceAxisX,
                                          const Eigen::MatrixXd &faceAxisY,
                                          const int face, const int family,
                                          const int sign) {
  Eigen::RowVector3d axis =
      family == 0 ? faceAxisX.row(face) : faceAxisY.row(face);
  return (sign >= 0 ? 1.0 : -1.0) * axis;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::int64_t quantized_barycentric_value(const double value) {
  return static_cast<std::int64_t>(std::llround(value * 1.0e9));
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

SurfaceTraceState make_trace_state(const SurfaceTracePoint &point,
                                          const int entryEdge,
                                          const int family,
                                          const int sign) {
  SurfaceTraceState state;
  state.sourceFace = point.face;
  state.entryEdge = entryEdge;
  state.family = family == 0 ? 0 : 1;
  state.sign = sign >= 0 ? 1 : -1;
  for (int corner = 0; corner < 3; ++corner) {
    state.quantizedBarycentric[static_cast<std::size_t>(corner)] =
        quantized_barycentric_value(point.barycentric[corner]);
  }
  return state;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int normalized_branch(const int branch) {
  return ((branch % 4) + 4) % 4;
}

namespace {

int translation_orientation_rank(
    const authority::LatticeTranslation &translation) {
  if (translation.x != 0) return translation.x > 0 ? 0 : 1;
  if (translation.y != 0) return translation.y > 0 ? 0 : 1;
  return 2;
}

auto periodic_relation_key(const SurfacePeriodicHolonomy &relation) {
  return std::tuple{relation.sourceTopologyRegion(), relation.action(),
                    relation.route(), relation.cutRoute()};
}

bool periodic_relation_shape_valid(const SurfacePeriodicHolonomy &relation) {
  const bool nonzeroTranslation =
      relation.action().shift.x != 0 || relation.action().shift.y != 0;
  return nonzeroTranslation && !relation.route().empty() &&
         !relation.cutRoute().empty();
}

} // namespace

SurfacePeriodicHolonomy canonicalize_periodic_holonomy(
    SurfacePeriodicHolonomy relation) {
  const authority::GridAutomorphism inverseAction = relation.action().inverse();
  const auto action_key = [](const authority::GridAutomorphism &action) {
    return std::tuple{translation_orientation_rank(action.shift),
                      action.rotation.value(),
                      std::abs(action.shift.x),
                      std::abs(action.shift.y),
                      action.shift.x, action.shift.y};
  };
  if (action_key(inverseAction) < action_key(relation.action())) {
    const auto rebuilt = SurfacePeriodicHolonomy::make(
        relation.id(), relation.sourceTopologyRegion(), inverseAction,
        relation.route(), relation.cutRoute());
    const auto *value = std::get_if<SurfacePeriodicHolonomy>(&rebuilt);
    if (value != nullptr) relation = *value;
  }
  return relation;
}

SurfacePeriodicHolonomyInsertStatus insert_periodic_holonomy(
    std::vector<SurfacePeriodicHolonomy> &relations,
    SurfacePeriodicHolonomy relation) {
  relation = canonicalize_periodic_holonomy(std::move(relation));
  if (!periodic_relation_shape_valid(relation)) {
    return SurfacePeriodicHolonomyInsertStatus::Incompatible;
  }

  for (const SurfacePeriodicHolonomy &existing : relations) {
    if (periodic_relation_key(existing) == periodic_relation_key(relation)) {
      return SurfacePeriodicHolonomyInsertStatus::Equivalent;
    }
    const bool sameScope =
        existing.sourceTopologyRegion() == relation.sourceTopologyRegion();
    if (!sameScope) continue;
    if (existing.route() == relation.route() ||
        existing.cutRoute() == relation.cutRoute()) {
      return SurfacePeriodicHolonomyInsertStatus::Incompatible;
    }

    // This G4 slice intentionally does not guess a basis inside one source
    // sheet. Distinct same-sheet cycles require a later topology-basis solver;
    // retaining one by discovery order would be unsound. Multiple relations
    // on distinct authoritative sheets/components remain valid and are kept.
    return SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis;
  }

  // Allocate ownership from the occupied typed-ID set, not from relation
  // vector position. Existing owners never change when storage is reordered or
  // a later relation is inserted.
  const std::size_t ownerExtent = relations.size() + 1U;
  std::optional<authority::PeriodicRelationId> allocatedId;
  for (std::size_t candidateIndex = 0; candidateIndex < ownerExtent;
       ++candidateIndex) {
    const auto candidate = authority::PeriodicRelationId::from_index(
        static_cast<std::int64_t>(candidateIndex), ownerExtent);
    if (!candidate) return SurfacePeriodicHolonomyInsertStatus::Incompatible;
    const bool occupied = std::any_of(
        relations.begin(), relations.end(), [&](const auto &existing) {
          return existing.id() == candidate.value();
        });
    if (!occupied) {
      allocatedId = candidate.value();
      break;
    }
  }
  if (!allocatedId.has_value()) {
    return SurfacePeriodicHolonomyInsertStatus::Incompatible;
  }
  relation = relation.with_id(*allocatedId);
  relations.push_back(std::move(relation));

  // Storage order is deterministic only; semantic ownership is the typed ID.
  std::sort(relations.begin(), relations.end(),
            [](const SurfacePeriodicHolonomy &a,
               const SurfacePeriodicHolonomy &b) {
              return periodic_relation_key(a) < periodic_relation_key(b);
            });
  return SurfacePeriodicHolonomyInsertStatus::Inserted;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::RowVector3d transport_direction_between_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int sourceFace, const int targetFace,
    const Eigen::RowVector3d &direction) {
  const Eigen::RowVector3d sourceNormal =
      face_normal(vertices, faces, sourceFace);
  const Eigen::RowVector3d targetNormal =
      face_normal(vertices, faces, targetFace);
  if (sourceNormal.squaredNorm() == 0.0 || targetNormal.squaredNorm() == 0.0) {
    return Eigen::RowVector3d::Zero();
  }

  const Eigen::Vector3d source = sourceNormal.transpose();
  const Eigen::Vector3d target = targetNormal.transpose();
  const Eigen::Vector3d input = direction.transpose();
  const double cosine = std::clamp(source.dot(target), -1.0, 1.0);
  const Eigen::Vector3d cross = source.cross(target);
  const double sine = cross.norm();
  Eigen::Vector3d transported;
  if (sine > 1.0e-14) {
    const Eigen::Vector3d axis = cross / sine;
    transported = cosine * input + sine * axis.cross(input) +
                  (1.0 - cosine) * axis.dot(input) * axis;
  } else if (cosine >= 0.0) {
    transported = input;
  } else {
    Eigen::Vector3d reference = Eigen::Vector3d::UnitX();
    if (std::abs(source.y()) <= std::abs(source.x()) &&
        std::abs(source.y()) <= std::abs(source.z())) {
      reference = Eigen::Vector3d::UnitY();
    } else if (std::abs(source.z()) <= std::abs(source.x())) {
      reference = Eigen::Vector3d::UnitZ();
    }
    Eigen::Vector3d axis = source.cross(reference);
    const double axisNorm = axis.norm();
    if (axisNorm <= 1.0e-14) {
      return Eigen::RowVector3d::Zero();
    }
    axis /= axisNorm;
    transported = 2.0 * axis.dot(input) * axis - input;
  }
  return project_tangent(transported.transpose(), targetNormal);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool transition_faces_match(
    const fields::CrossFieldEdgeTransition &transition, const int sourceFace,
    const int targetFace) {
  return (transition.firstFace == sourceFace &&
          transition.secondFace == targetFace) ||
         (transition.firstFace == targetFace &&
          transition.secondFace == sourceFace);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

BranchTransitionResult resolve_branch_transition(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &edgeMatchingIndices,
    const EdgeTransitionLookup &transitionLookup, const authority::SourceEdgeTopologyKey &edgeKey,
    const int sourceFace, const int targetFace, const int sourceFamily,
    const int sourceSign, const Eigen::RowVector3d &sourceDirection,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  BranchTransitionResult result;
  const auto topology = edgeFaces.find(edgeKey);
  if (topology == edgeFaces.end() || topology->second[0] < 0 ||
      topology->second[1] < 0 ||
      !((topology->second[0] == sourceFace &&
         topology->second[1] == targetFace) ||
        (topology->second[1] == sourceFace &&
         topology->second[0] == targetFace))) {
    return result;
  }

  result.transportedInput = transport_direction_between_faces(
      vertices, faces, sourceFace, targetFace, sourceDirection);
  if (result.transportedInput.squaredNorm() == 0.0) {
    return result;
  }

  const int sourceBranch = branch_from_family_sign(sourceFamily, sourceSign);
  bool authoritativeMatching = false;
  std::optional<authority::QuarterTurn> authoritativeTransitionTransport;
  if (transitionLookup.atlas != nullptr) {
    const auto typedSourceFace = authority::SourceFaceId::from_index(
        sourceFace, static_cast<std::size_t>(faces.rows()));
    const auto typedTargetFace = authority::SourceFaceId::from_index(
        targetFace, static_cast<std::size_t>(faces.rows()));
    if (!typedSourceFace || !typedTargetFace) return result;
    const auto transport = transitionLookup.atlas->transport(
        edgeKey, typedSourceFace.value(), typedTargetFace.value());
    if (!transport.has_value()) return result;
    authoritativeTransitionTransport = transport->transport;
    result.matching = transport->signedLift;
    result.effort = transport->effort;
    authoritativeMatching = true;
  } else if (edgeTransitions != nullptr) {
    const auto found = transitionLookup.byEdge.find(edgeKey);
    if (found == transitionLookup.byEdge.end()) {
      return result;
    }

    const std::size_t sourceFaceExtent =
        static_cast<std::size_t>(faces.rows());
    const std::size_t sourceVertexExtent =
        static_cast<std::size_t>(vertices.rows());
    const auto sourceFaceResult = directional::authority::SourceFaceId::from_index(
        sourceFace, sourceFaceExtent);
    const auto targetFaceResult = directional::authority::SourceFaceId::from_index(
        targetFace, sourceFaceExtent);
    const auto firstFaceResult = directional::authority::SourceFaceId::from_index(
        found->second.firstFace, sourceFaceExtent);
    const auto secondFaceResult = directional::authority::SourceFaceId::from_index(
        found->second.secondFace, sourceFaceExtent);
    if (!sourceFaceResult || !targetFaceResult || !firstFaceResult ||
        !secondFaceResult) {
      return result;
    }

    const authority::SourceFaceId typedSourceFace = sourceFaceResult.value();
    const authority::SourceFaceId typedTargetFace = targetFaceResult.value();
    const authority::SourceFaceId typedFirstFace = firstFaceResult.value();
    const authority::SourceFaceId typedSecondFace = secondFaceResult.value();
    const bool forwardTraversal = typedFirstFace == typedSourceFace &&
                                  typedSecondFace == typedTargetFace;
    const bool reverseTraversal = typedFirstFace == typedTargetFace &&
                                  typedSecondFace == typedSourceFace;
    if (!forwardTraversal && !reverseTraversal) {
      return result;
    }

    const auto firstVertexResult =
        directional::authority::SourceVertexId::from_index(
            found->second.sourceVertex0, sourceVertexExtent);
    const auto secondVertexResult =
        directional::authority::SourceVertexId::from_index(
            found->second.sourceVertex1, sourceVertexExtent);
    if (!firstVertexResult || !secondVertexResult) {
      return result;
    }
    const auto sourceEdgeResult = authority::SourceEdgeTopologyKey::make(
        firstVertexResult.value(), secondVertexResult.value());
    if (!sourceEdgeResult) {
      return result;
    }
    const authority::SourceEdgeTopologyKey sourceEdge = sourceEdgeResult.value();
    if (edgeKey != sourceEdge) {
      return result;
    }

    authority::QuarterTurn transport =
        authority::QuarterTurn::from_integer(found->second.matching);
    if (reverseTraversal) {
      transport = transport.inverse();
    }
    authoritativeTransitionTransport = transport;

    result.matching = found->second.matching;
    if (reverseTraversal) {
      result.matching = -result.matching;
    }
    result.effort = found->second.effort;
    authoritativeMatching = true;
  } else {
    const auto matchingIndex = edgeMatchingIndices.find(edgeKey);
    if (edgeMatching != nullptr) {
      if (matchingIndex == edgeMatchingIndices.end() ||
          matchingIndex->second < 0 ||
          matchingIndex->second >= edgeMatching->size()) {
        return result;
      }
      result.matching = (*edgeMatching)[matchingIndex->second];
      if (topology->second[1] == sourceFace) {
        result.matching = -result.matching;
      }
      authoritativeMatching = true;
    }
    if (edgeEffort != nullptr) {
      if (matchingIndex == edgeMatchingIndices.end() ||
          matchingIndex->second < 0 ||
          matchingIndex->second >= edgeEffort->size()) {
        return result;
      }
      result.effort = (*edgeEffort)[matchingIndex->second];
    }
  }

  int targetBranch = sourceBranch;
  if (authoritativeTransitionTransport.has_value()) {
    targetBranch = normalized_branch(
        sourceBranch +
        static_cast<int>(authoritativeTransitionTransport->value()));
  } else if (authoritativeMatching) {
    targetBranch = normalized_branch(sourceBranch + result.matching);
  } else {
    double bestTurn = std::numeric_limits<double>::infinity();
    int bestBranch = 0;
    for (int branch = 0; branch < 4; ++branch) {
      int candidateFamily = 0;
      int candidateSign = 1;
      family_sign_from_branch(branch, candidateFamily, candidateSign);
      const Eigen::RowVector3d candidate = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, targetFace, candidateFamily,
                          candidateSign),
          face_normal(vertices, faces, targetFace));
      if (candidate.squaredNorm() == 0.0) {
        continue;
      }
      const double turn = std::acos(std::clamp(
          result.transportedInput.dot(candidate), -1.0, 1.0));
      if (turn < bestTurn - 1.0e-14 ||
          (std::abs(turn - bestTurn) <= 1.0e-14 && branch < bestBranch)) {
        bestTurn = turn;
        bestBranch = branch;
      }
    }
    if (!std::isfinite(bestTurn)) {
      return result;
    }
    targetBranch = bestBranch;
    result.matching = normalized_branch(targetBranch - sourceBranch);
    result.effort = bestTurn;
  }

  family_sign_from_branch(targetBranch, result.family, result.sign);
  result.direction = project_tangent(
      axis_for_family(faceAxisX, faceAxisY, targetFace, result.family,
                      result.sign),
      face_normal(vertices, faces, targetFace));
  if (result.direction.squaredNorm() == 0.0) {
    return result;
  }

  // Preserve the matched family, but use the oriented branch that continues
  // forward after intrinsic transport.
  if (result.direction.dot(result.transportedInput) < 0.0) {
    result.direction *= -1.0;
    result.sign *= -1;
  }
  result.turnAngle = std::acos(std::clamp(
      result.transportedInput.dot(result.direction), -1.0, 1.0));
  result.valid = std::isfinite(result.effort) &&
                 std::isfinite(result.turnAngle) &&
                 result.direction.array().isFinite().all();
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool direction_enters_face_from_vertex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int face, const int vertex, const Eigen::RowVector3d &direction) {
  int vertexCorner = -1;
  for (int corner = 0; corner < 3; ++corner) {
    if (faces(face, corner) == vertex) {
      vertexCorner = corner;
      break;
    }
  }
  if (vertexCorner < 0) {
    return false;
  }
  Eigen::RowVector3d derivative;
  if (!barycentric_derivative(vertices, faces, face, direction, derivative)) {
    return false;
  }
  if (derivative[vertexCorner] >= -1.0e-12) {
    return false;
  }
  for (int corner = 0; corner < 3; ++corner) {
    if (corner != vertexCorner && derivative[corner] < -1.0e-12) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::map<int, std::vector<VertexPathStep>> vertex_face_adjacency(
    const int vertex,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces) {
  std::map<int, std::vector<VertexPathStep>> adjacency;
  for (const auto &[key, pair] : edgeFaces) {
    const int a = static_cast<int>(key.first().index());
    const int b = static_cast<int>(key.second().index());
    if ((a != vertex && b != vertex) || pair[0] < 0 || pair[1] < 0) {
      continue;
    }
    adjacency[pair[0]].push_back({pair[1], key});
    adjacency[pair[1]].push_back({pair[0], key});
  }
  for (auto &[face, neighbors] : adjacency) {
    (void)face;
    std::sort(neighbors.begin(), neighbors.end(),
              [](const VertexPathStep &lhs, const VertexPathStep &rhs) {
                return std::tie(lhs.face, lhs.edgeKey) <
                       std::tie(rhs.face, rhs.edgeKey);
              });
  }
  return adjacency;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool continuation_is_better(const VertexContinuationResult &candidate,
                                   const VertexContinuationResult &best) {
  if (candidate.turnAngle < best.turnAngle - 1.0e-14) {
    return true;
  }
  if (std::abs(candidate.turnAngle - best.turnAngle) > 1.0e-14) {
    return false;
  }
  if (candidate.matchingEffort < best.matchingEffort - 1.0e-14) {
    return true;
  }
  if (std::abs(candidate.matchingEffort - best.matchingEffort) > 1.0e-14) {
    return false;
  }
  if (candidate.face != best.face) {
    return candidate.face < best.face;
  }
  return candidate.facePath < best.facePath;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool continuation_source_edge_provenance(
    const authority::SourceEdgeTopologyKey &edgeKey,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge) {
  sourceEdge = -1;
  const auto incidence = sourceEdgeFaces.find(edgeKey);
  const auto compactIndex = sourceMatchingIndices.find(edgeKey);
  if (incidence == sourceEdgeFaces.end() || incidence->second[0] < 0 ||
      incidence->second[1] < 0 ||
      compactIndex == sourceMatchingIndices.end() ||
      compactIndex->second < 0) {
    return false;
  }
  if (edgeTransitions != nullptr) {
    const auto found = transitionLookup.byEdge.find(edgeKey);
    if (found == transitionLookup.byEdge.end() || found->second.sourceEdge < 0 ||
        !((found->second.sourceVertex0 == edgeKey.first().index() &&
           found->second.sourceVertex1 == edgeKey.second().index()) ||
          (found->second.sourceVertex0 == edgeKey.second().index() &&
           found->second.sourceVertex1 == edgeKey.first().index())) ||
        !transition_faces_match(found->second, incidence->second[0],
                                incidence->second[1])) {
      return false;
    }
  }
  sourceEdge = compactIndex->second;
  return true;
}

VertexContinuationResult resolve_vertex_continuation(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &edgeMatchingIndices,
    const EdgeTransitionLookup &transitionLookup, const int currentFace,
    const int vertex, const int currentFamily, const int currentSign,
    const Eigen::RowVector3d &incomingDirection,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  VertexContinuationResult best;
  const auto adjacency = vertex_face_adjacency(vertex, edgeFaces);
  if (adjacency.find(currentFace) == adjacency.end()) {
    return best;
  }

  struct PathState {
    int face = -1;
    int family = 0;
    int sign = 1;
    double effort = 0.0;
    std::vector<authority::TransitionStep> routeSteps;
    Eigen::RowVector3d direction = Eigen::RowVector3d::Zero();
    Eigen::RowVector3d transportedIncoming = Eigen::RowVector3d::Zero();
    std::vector<int> faces;
    std::set<int> visited;
  };

  bool sourceSheetBlocked = false;
  bool featureBlocked = false;
  bool metadataFailure = false;
  std::vector<PathState> stack;
  PathState initial;
  initial.face = currentFace;
  initial.family = currentFamily;
  initial.sign = currentSign;
  initial.direction = incomingDirection;
  initial.transportedIncoming = incomingDirection;
  initial.faces = {currentFace};
  initial.visited.insert(currentFace);
  stack.push_back(std::move(initial));

  constexpr std::size_t kMaximumEnumeratedPaths = 4096;
  std::size_t enumerated = 0;
  while (!stack.empty()) {
    PathState path = std::move(stack.back());
    stack.pop_back();
    if (++enumerated > kMaximumEnumeratedPaths) {
      metadataFailure = true;
      break;
    }
    const auto neighbors = adjacency.find(path.face);
    if (neighbors == adjacency.end()) {
      continue;
    }
    for (auto iterator = neighbors->second.rbegin();
         iterator != neighbors->second.rend(); ++iterator) {
      const VertexPathStep &step = *iterator;
      if (!step.edgeKey.has_value()) {
        metadataFailure = true;
        continue;
      }
      if (path.visited.count(step.face) != 0) {
        continue;
      }
      if (options.hardFeatureEdges.count(*step.edgeKey) != 0 ||
          (options.reliefBarriersEmbedded &&
           options.reliefBarrierEdges.count(*step.edgeKey) != 0)) {
        featureBlocked = true;
        continue;
      }
      if (!source_faces_share_component(options, path.face, step.face)) {
        sourceSheetBlocked = true;
        continue;
      }
      const BranchTransitionResult transition = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, edgeFaces,
          edgeMatchingIndices, transitionLookup, *step.edgeKey, path.face,
          step.face, path.family, path.sign, path.direction, edgeMatching,
          edgeEffort, edgeTransitions);
      if (!transition.valid) {
        metadataFailure = true;
        continue;
      }

      int sourceEdge = -1;
      if (!continuation_source_edge_provenance(
              *step.edgeKey, edgeFaces, edgeMatchingIndices, transitionLookup,
              edgeTransitions, sourceEdge)) {
        metadataFailure = true;
        continue;
      }
      const authority::SourceEdgeTopologyKey &topology = *step.edgeKey;
      const auto interiorTransition =
          directional::authority::InteriorTransitionId::from_index(
              sourceEdge, edgeMatchingIndices.size());
      if (!interiorTransition) {
        metadataFailure = true;
        continue;
      }
      const auto typedStep = authority::TransitionStep::interior(
          topology,
          std::optional<authority::InteriorTransitionId>{
              interiorTransition.value()},
          authority::GridAutomorphism{
              authority::QuarterTurn::from_integer(transition.matching),
              authority::LatticeTranslation{0, 0}},
          authority::Orientation::Forward);
      if (!typedStep) {
        metadataFailure = true;
        continue;
      }

      PathState next = path;
      next.face = step.face;
      next.family = transition.family;
      next.sign = transition.sign;
      next.routeSteps.push_back(typedStep.value());
      next.effort += std::abs(transition.effort);
      next.direction = transition.direction;
      next.transportedIncoming = transport_direction_between_faces(
          vertices, faces, path.face, step.face, path.transportedIncoming);
      if (next.transportedIncoming.squaredNorm() == 0.0) {
        metadataFailure = true;
        continue;
      }
      next.faces.push_back(step.face);
      next.visited.insert(step.face);

      if (direction_enters_face_from_vertex(vertices, faces, next.face, vertex,
                                            next.direction)) {
        VertexContinuationResult candidate;
        candidate.status = VertexContinuationStatus::Found;
        candidate.face = next.face;
        candidate.family = next.family;
        candidate.sign = next.sign;
        const authority::CanonicalRoute typedRoute =
            authority::CanonicalRoute::from_observed_steps(next.routeSteps);
        authority::GridAutomorphism routeTransport =
            authority::GridAutomorphism::identity();
        for (const authority::TransitionStep &routeStep :
             typedRoute.oriented_steps()) {
          routeTransport = compose(routeStep.transport(), routeTransport);
        }
        candidate.matching =
            static_cast<int>(routeTransport.rotation.value());
        candidate.matchingEffort = next.effort;
        candidate.turnAngle = std::acos(std::clamp(
            next.transportedIncoming.dot(next.direction), -1.0, 1.0));
        candidate.direction = next.direction;
        candidate.facePath = next.faces;
        if (best.status != VertexContinuationStatus::Found ||
            continuation_is_better(candidate, best)) {
          best = std::move(candidate);
        }
      }
      stack.push_back(std::move(next));
    }
  }

  if (metadataFailure) {
    best.status = VertexContinuationStatus::FieldMetadata;
    return best;
  }
  if (best.status == VertexContinuationStatus::Found) {
    return best;
  }
  if (sourceSheetBlocked) {
    best.status = VertexContinuationStatus::SourceSheet;
  } else if (featureBlocked) {
    best.status = VertexContinuationStatus::Feature;
  } else {
    best.status = VertexContinuationStatus::Boundary;
  }
  return best;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::Vector2d project_for_quad_test(const Eigen::RowVector3d &point,
                                             const int dropAxis) {
  if (dropAxis == 0) {
    return {point.y(), point.z()};
  }
  if (dropAxis == 1) {
    return {point.x(), point.z()};
  }
  return {point.x(), point.y()};
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double orient2d(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                       const Eigen::Vector2d &c) {
  return (b.x() - a.x()) * (c.y() - a.y()) -
         (b.y() - a.y()) * (c.x() - a.x());
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool segments_intersect_2d(const Eigen::Vector2d &a,
                                  const Eigen::Vector2d &b,
                                  const Eigen::Vector2d &c,
                                  const Eigen::Vector2d &d) {
  const double o1 = orient2d(a, b, c);
  const double o2 = orient2d(a, b, d);
  const double o3 = orient2d(c, d, a);
  const double o4 = orient2d(c, d, b);
  return o1 * o2 < -1.0e-14 && o3 * o4 < -1.0e-14;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool point_on_segment_2d(const Eigen::Vector2d &point,
                                const Eigen::Vector2d &a,
                                const Eigen::Vector2d &b,
                                const double tolerance) {
  if (std::abs(orient2d(a, b, point)) > tolerance) {
    return false;
  }
  return point.x() >= std::min(a.x(), b.x()) - tolerance &&
         point.x() <= std::max(a.x(), b.x()) + tolerance &&
         point.y() >= std::min(a.y(), b.y()) - tolerance &&
         point.y() <= std::max(a.y(), b.y()) + tolerance;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool segments_intersect_beyond_shared_endpoint_2d(
    const Eigen::Vector2d &a, const Eigen::Vector2d &b,
    const Eigen::Vector2d &c, const Eigen::Vector2d &d) {
  if (segments_intersect_2d(a, b, c, d)) {
    return true;
  }

  const double scale = std::max(
      {1.0, (b - a).norm(), (d - c).norm(), (c - a).norm(), (d - a).norm()});
  const double tolerance = 1.0e-12 * scale * scale;
  const double pointTolerance = 1.0e-12 * scale;
  const auto same_point = [&](const Eigen::Vector2d &lhs,
                              const Eigen::Vector2d &rhs) {
    return (lhs - rhs).norm() <= pointTolerance;
  };
  const auto endpoint_on_interior = [&](const Eigen::Vector2d &point,
                                        const Eigen::Vector2d &start,
                                        const Eigen::Vector2d &end) {
    return point_on_segment_2d(point, start, end, tolerance) &&
           !same_point(point, start) && !same_point(point, end);
  };

  if (endpoint_on_interior(a, c, d) || endpoint_on_interior(b, c, d) ||
      endpoint_on_interior(c, a, b) || endpoint_on_interior(d, a, b)) {
    return true;
  }

  const bool collinear = std::abs(orient2d(a, b, c)) <= tolerance &&
                         std::abs(orient2d(a, b, d)) <= tolerance;
  if (!collinear) {
    return false;
  }
  const int axis = std::abs(b.x() - a.x()) >= std::abs(b.y() - a.y()) ? 0 : 1;
  const auto coordinate = [axis](const Eigen::Vector2d &point) {
    return axis == 0 ? point.x() : point.y();
  };
  const double overlap =
      std::min(std::max(coordinate(a), coordinate(b)),
               std::max(coordinate(c), coordinate(d))) -
      std::max(std::min(coordinate(a), coordinate(b)),
               std::min(coordinate(c), coordinate(d)));
  return overlap > pointTolerance;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

CellRejectionReason classify_quad_loop(
    const std::array<Eigen::RowVector3d, 4> &corners, const double h,
    const Eigen::RowVector3d &expectedNormal,
    const SurfaceCellTracingOptions &options) {
  const double duplicateTolerance =
      std::max(1.0e-14, options.duplicateCornerToleranceFactor * h);
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      const double distance =
          (corners[static_cast<std::size_t>(i)] -
           corners[static_cast<std::size_t>(j)])
              .norm();
      if (!std::isfinite(distance) || distance <= duplicateTolerance) {
        return CellRejectionReason::DuplicateCorner;
      }
    }
  }

  Eigen::RowVector3d loopNormal = Eigen::RowVector3d::Zero();
  for (int i = 0; i < 4; ++i) {
    loopNormal += cross3(corners[static_cast<std::size_t>(i)],
                         corners[static_cast<std::size_t>((i + 1) % 4)]);
  }
  const Eigen::RowVector3d projectionNormal =
      loopNormal.squaredNorm() > 0.0 ? loopNormal : expectedNormal;
  int dropAxis = 2;
  if (std::abs(projectionNormal.x()) >= std::abs(projectionNormal.y()) &&
      std::abs(projectionNormal.x()) >= std::abs(projectionNormal.z())) {
    dropAxis = 0;
  } else if (std::abs(projectionNormal.y()) >=
             std::abs(projectionNormal.z())) {
    dropAxis = 1;
  }
  std::array<Eigen::Vector2d, 4> projected;
  for (int i = 0; i < 4; ++i) {
    projected[static_cast<std::size_t>(i)] =
        project_for_quad_test(corners[static_cast<std::size_t>(i)], dropAxis);
  }
  if (segments_intersect_2d(projected[0], projected[1], projected[2],
                            projected[3]) ||
      segments_intersect_2d(projected[1], projected[2], projected[3],
                            projected[0])) {
    return CellRejectionReason::SelfIntersection;
  }

  if (!loopNormal.allFinite() ||
      loopNormal.squaredNorm() <=
          1.0e-24 * std::max(1.0, h * h * h * h)) {
    return CellRejectionReason::Degenerate;
  }
  if (expectedNormal.squaredNorm() > 0.0 &&
      loopNormal.dot(expectedNormal) <= 0.0) {
    return CellRejectionReason::Inverted;
  }

  for (int i = 0; i < 4; ++i) {
    const double sideLength =
        (corners[static_cast<std::size_t>((i + 1) % 4)] -
         corners[static_cast<std::size_t>(i)])
            .norm();
    if (!std::isfinite(sideLength) ||
        sideLength < options.minimumCellSideFactor * h ||
        sideLength > options.maximumCellSideFactor * h) {
      return CellRejectionReason::OutOfSize;
    }
  }
  return CellRejectionReason::Accepted;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool quad_loop_is_valid(const std::array<Eigen::RowVector3d, 4> &corners,
                               const double h) {
  SurfaceCellTracingOptions options;
  Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
  for (int i = 0; i < 4; ++i) {
    normal += cross3(corners[static_cast<std::size_t>(i)],
                     corners[static_cast<std::size_t>((i + 1) % 4)]);
  }
  return classify_quad_loop(corners, h, normal, options) ==
         CellRejectionReason::Accepted;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool trace_segment_crosses_authoritative_rail(
    const SurfaceTraceSegment &segment,
    const std::vector<SurfaceCellRail> &rails) {
  const Eigen::Vector2d a(segment.startBarycentric[1],
                          segment.startBarycentric[2]);
  const Eigen::Vector2d b(segment.endBarycentric[1],
                          segment.endBarycentric[2]);
  for (const SurfaceCellRail &rail : rails) {
    if (segment.railId == rail.id) {
      continue;
    }
    // Rail samples are stored as independent interval endpoint pairs:
    // [a0,b0,a1,b1,...]. Never connect b_i to a_{i+1}; those endpoints may
    // belong to different source faces or disjoint pieces of the same rail.
    for (std::size_t index = 0; index + 1 < rail.samples.size(); index += 2) {
      const SurfaceCellRailSample &first = rail.samples[index];
      const SurfaceCellRailSample &second = rail.samples[index + 1];
      if (first.sourceFace != segment.face || second.sourceFace != segment.face) {
        continue;
      }
      const Eigen::Vector2d c(first.barycentric[1], first.barycentric[2]);
      const Eigen::Vector2d d(second.barycentric[1], second.barycentric[2]);
      if (segments_intersect_2d(a, b, c, d)) {
        return true;
      }
    }
  }
  return false;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

CellRejectionReason validate_closed_boundary_paths(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::array<SurfaceTracePoint, 4> &corners,
    const std::array<std::vector<SurfaceTraceSegment>, 4> &boundaryPaths,
    const double tolerance) {
  const auto segment_point = [&](const SurfaceTraceSegment &segment,
                                 const bool start) {
    SurfaceTracePoint point;
    point.face = segment.face;
    point.barycentric =
        start ? segment.startBarycentric : segment.endBarycentric;
    return point;
  };
  const auto valid = [&](const SurfaceTracePoint &point) {
    return point.face >= 0 && point.face < faces.rows() &&
           point.barycentric.array().isFinite().all() &&
           std::abs(point.barycentric.sum() - 1.0) <= 1.0e-8 &&
           point.barycentric.minCoeff() >= -1.0e-8;
  };
  const auto close = [&](const SurfaceTracePoint &a,
                         const SurfaceTracePoint &b) {
    if (!valid(a) || !valid(b)) {
      return false;
    }
    return (point_position(vertices, faces, a) -
            point_position(vertices, faces, b))
               .norm() <= tolerance;
  };

  for (int side = 0; side < 4; ++side) {
    const auto &path = boundaryPaths[static_cast<std::size_t>(side)];
    if (path.empty()) {
      return CellRejectionReason::Closure;
    }
    const SurfaceTracePoint start = segment_point(path.front(), true);
    const SurfaceTracePoint end = segment_point(path.back(), false);
    if (!close(start, corners[static_cast<std::size_t>(side)]) ||
        !close(end, corners[static_cast<std::size_t>((side + 1) % 4)])) {
      return CellRejectionReason::Closure;
    }
    for (std::size_t segment = 0; segment + 1 < path.size(); ++segment) {
      if (!close(segment_point(path[segment], false),
                 segment_point(path[segment + 1], true))) {
        return CellRejectionReason::Closure;
      }
    }
  }

  struct IndexedSegment {
    int side = -1;
    int index = -1;
    const SurfaceTraceSegment *segment = nullptr;
  };
  std::vector<IndexedSegment> segments;
  for (int side = 0; side < 4; ++side) {
    const auto &path = boundaryPaths[static_cast<std::size_t>(side)];
    for (int index = 0; index < static_cast<int>(path.size()); ++index) {
      segments.push_back({side, index, &path[static_cast<std::size_t>(index)]});
    }
  }
  for (std::size_t i = 0; i < segments.size(); ++i) {
    const SurfaceTraceSegment &first = *segments[i].segment;
    for (std::size_t j = i + 1; j < segments.size(); ++j) {
      const SurfaceTraceSegment &second = *segments[j].segment;
      if (first.face != second.face) {
        continue;
      }
      const Eigen::Vector2d a(first.startBarycentric[1],
                              first.startBarycentric[2]);
      const Eigen::Vector2d b(first.endBarycentric[1],
                              first.endBarycentric[2]);
      const Eigen::Vector2d c(second.startBarycentric[1],
                              second.startBarycentric[2]);
      const Eigen::Vector2d d(second.endBarycentric[1],
                              second.endBarycentric[2]);
      if (segments_intersect_beyond_shared_endpoint_2d(a, b, c, d)) {
        return CellRejectionReason::SelfIntersection;
      }
    }
  }
  return CellRejectionReason::Accepted;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

SurfaceTracePoint vertex_point_in_face(const Eigen::MatrixXi &faces,
                                              const int face,
                                              const int vertex) {
  SurfaceTracePoint point;
  point.face = face;
  for (int corner = 0; corner < 3; ++corner) {
    point.barycentric[corner] = faces(face, corner) == vertex ? 1.0 : 0.0;
  }
  return point;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::set<authority::SourceEdgeTopologyKey> combined_barrier_edges(
    const SurfaceCellTracingOptions &options) {
  std::set<authority::SourceEdgeTopologyKey> barriers = options.hardFeatureEdges;
  if (options.reliefBarriersEmbedded) {
    barriers.insert(options.reliefBarrierEdges.begin(),
                    options.reliefBarrierEdges.end());
  }
  return barriers;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int seed_anchor_vertex(const SurfaceTraceSeed &seed,
                              const Eigen::MatrixXi &faces,
                              const int vertexCount) {
  switch (seed.provenance) {
  case SurfaceSeedProvenance::Singularity:
  case SurfaceSeedProvenance::ReliefCritical:
  case SurfaceSeedProvenance::Separatrix:
  case SurfaceSeedProvenance::Anchor:
  case SurfaceSeedProvenance::AdaptiveFarthest:
    if (seed.sourceId >= 0 && seed.sourceId < vertexCount) {
      return seed.sourceId;
    }
    break;
  case SurfaceSeedProvenance::Boundary:
  case SurfaceSeedProvenance::Feature:
    break;
  }
  if (seed.point.face >= 0 && seed.point.face < faces.rows()) {
    return faces(seed.point.face,
                 dominant_vertex_corner(seed.point.barycentric));
  }
  return -1;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int face_label_or_default(const std::vector<int> &labels,
                                 const int face,
                                 const int fallback) {
  return face >= 0 && face < static_cast<int>(labels.size())
             ? labels[static_cast<std::size_t>(face)]
             : fallback;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool trace_respects_face_labels(const SurfaceTraceResult &trace,
                                       const std::vector<int> &components,
                                       const std::vector<int> &sheets) {
  int expectedComponent = -1;
  int expectedSheet = -1;
  for (const SurfaceTraceSegment &segment : trace.segments) {
    const int component = face_label_or_default(components, segment.face, -1);
    const int sheet = face_label_or_default(sheets, segment.face, component);
    if (expectedComponent < 0) {
      expectedComponent = component;
      expectedSheet = sheet;
    } else if (component != expectedComponent || sheet != expectedSheet) {
      return false;
    }
  }
  return true;
}

bool trace_respects_source_component(const SurfaceTraceResult &trace,
                                     const std::vector<int> &components) {
  int expectedComponent = -1;
  for (const SurfaceTraceSegment &segment : trace.segments) {
    const int component = face_label_or_default(components, segment.face, -1);
    if (component < 0) {
      return false;
    }
    if (expectedComponent < 0) {
      expectedComponent = component;
    } else if (component != expectedComponent) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_surface_classifier_options_valid(
    const SourceSurfaceClassifierOptions &options) {
  return std::isfinite(options.normalCompatibility) &&
         options.normalCompatibility >= 0.0 &&
         options.normalCompatibility <= 1.0 &&
         std::isfinite(options.closeSheetRadiusMeanEdges) &&
         options.closeSheetRadiusMeanEdges > 0.0 &&
         options.geodesicExclusionDepth >= 0 &&
         options.geodesicExclusionDepth <= 64;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

SourceSurfaceLabels classify_source_surface_labels(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::set<authority::SourceEdgeTopologyKey> &barrierEdges,
    const SourceSurfaceClassifierOptions &options) {
  if (vertices.cols() != 3 || faces.cols() != 3 ||
      !vertices.array().isFinite().all()) {
    throw std::invalid_argument(
        "source-surface classification requires finite 3D triangles.");
  }
  if (!source_surface_classifier_options_valid(options)) {
    throw std::invalid_argument("invalid source-surface classifier policy.");
  }

  SourceSurfaceLabels labels;
  const int faceCount = static_cast<int>(faces.rows());
  labels.componentByFace.assign(static_cast<std::size_t>(faceCount), -1);
  labels.localSheetByFace.assign(static_cast<std::size_t>(faceCount), -1);

  struct EdgeIncidence {
    int firstFace = -1;
    int secondFace = -1;
    int firstOrientation = 0;
  };
  std::map<authority::SourceEdgeTopologyKey, EdgeIncidence> edgeIncidence;
  for (int face = 0; face < faceCount; ++face) {
    std::set<int> uniqueVertices;
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      if (vertex < 0 || vertex >= vertices.rows() ||
          !uniqueVertices.insert(vertex).second) {
        throw std::invalid_argument(
            "source-surface classification received an invalid face.");
      }
      const int next = faces(face, (corner + 1) % 3);
      if (next < 0 || next >= vertices.rows()) {
        throw std::invalid_argument(
            "source-surface classification received an invalid index.");
      }
      const authority::SourceEdgeTopologyKey key = edge_key(vertex, next, source_vertex_extent(faces));
      const int orientation = vertex < next ? 1 : -1;
      EdgeIncidence &incidence = edgeIncidence[key];
      if (incidence.firstFace < 0) {
        incidence.firstFace = face;
        incidence.firstOrientation = orientation;
      } else if (incidence.secondFace < 0) {
        if (incidence.firstOrientation == orientation) {
          throw std::invalid_argument(
              "source-surface classification requires consistent winding.");
        }
        incidence.secondFace = face;
      } else {
        throw std::invalid_argument(
            "source-surface classification requires manifold edges.");
      }
    }
  }

  std::vector<std::vector<std::pair<int, authority::SourceEdgeTopologyKey>>> adjacency(
      static_cast<std::size_t>(faceCount));
  for (const auto &[key, incidence] : edgeIncidence) {
    if (incidence.firstFace >= 0 && incidence.secondFace >= 0) {
      adjacency[static_cast<std::size_t>(incidence.firstFace)].push_back(
          {incidence.secondFace, key});
      adjacency[static_cast<std::size_t>(incidence.secondFace)].push_back(
          {incidence.firstFace, key});
    }
  }
  for (auto &neighbors : adjacency) {
    std::sort(neighbors.begin(), neighbors.end());
  }

  std::vector<Eigen::RowVector3d> centroids(static_cast<std::size_t>(faceCount));
  std::vector<Eigen::RowVector3d> normals(static_cast<std::size_t>(faceCount));
  double totalEdgeLength = 0.0;
  int edgeLengthCount = 0;
  for (int face = 0; face < faceCount; ++face) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      centroid += row3(vertices, a) / 3.0;
    }
    centroids[static_cast<std::size_t>(face)] = centroid;
    normals[static_cast<std::size_t>(face)] = face_normal(vertices, faces, face);
    if (normals[static_cast<std::size_t>(face)].squaredNorm() == 0.0) {
      throw std::invalid_argument(
          "source-surface classification requires nondegenerate faces.");
    }
  }
  for (const auto &[key, incidence] : edgeIncidence) {
    (void)incidence;
    const int a = static_cast<int>(key.first().index());
    const int b = static_cast<int>(key.second().index());
    const double length = (row3(vertices, a) - row3(vertices, b)).norm();
    if (!(length > 0.0) || !std::isfinite(length)) {
      throw std::invalid_argument(
          "source-surface classification requires finite source edges.");
    }
    totalEdgeLength += length;
    ++edgeLengthCount;
  }
  const double meanEdgeLength =
      edgeLengthCount > 0 ? totalEdgeLength / static_cast<double>(edgeLengthCount)
                          : 0.0;
  const double closeSheetRadius =
      options.closeSheetRadiusMeanEdges * meanEdgeLength;
  if (faceCount > 0 && (!(closeSheetRadius > 0.0) ||
                        !std::isfinite(closeSheetRadius))) {
    throw std::invalid_argument(
        "source-surface close-sheet radius is not representable.");
  }

  using GridKey = std::array<std::int64_t, 3>;
  Eigen::RowVector3d gridOrigin = Eigen::RowVector3d::Zero();
  if (faceCount > 0) {
    gridOrigin = centroids.front();
    for (const Eigen::RowVector3d &centroid : centroids) {
      gridOrigin = gridOrigin.cwiseMin(centroid);
    }
  }
  const auto grid_key = [&](const Eigen::RowVector3d &position) {
    GridKey key{};
    for (int axis = 0; axis < 3; ++axis) {
      const long double coordinate =
          (static_cast<long double>(position[axis]) -
           static_cast<long double>(gridOrigin[axis])) /
          static_cast<long double>(closeSheetRadius);
      if (!std::isfinite(coordinate) ||
          coordinate <
              static_cast<long double>(std::numeric_limits<std::int64_t>::min()) +
                  2.0L ||
          coordinate >
              static_cast<long double>(std::numeric_limits<std::int64_t>::max()) -
                  2.0L) {
        throw std::invalid_argument(
            "source-surface spatial index coordinate is out of range.");
      }
      key[static_cast<std::size_t>(axis)] =
          static_cast<std::int64_t>(std::floor(coordinate));
    }
    return key;
  };
  std::map<GridKey, std::vector<int>> spatialBins;
  std::vector<GridKey> faceGridKeys(static_cast<std::size_t>(faceCount));
  for (int face = 0; face < faceCount; ++face) {
    const GridKey key = grid_key(centroids[static_cast<std::size_t>(face)]);
    faceGridKeys[static_cast<std::size_t>(face)] = key;
    spatialBins[key].push_back(face);
  }

  std::vector<std::vector<int>> geodesicNeighborhoods(
      static_cast<std::size_t>(faceCount));
  std::vector<bool> geodesicNeighborhoodReady(
      static_cast<std::size_t>(faceCount), false);
  std::vector<int> visitStamp(static_cast<std::size_t>(faceCount), 0);
  std::vector<int> visitDepth(static_cast<std::size_t>(faceCount), 0);
  int nextVisitStamp = 0;
  const auto ensure_geodesic_neighborhood = [&](const int source) {
    if (geodesicNeighborhoodReady[static_cast<std::size_t>(source)]) {
      return;
    }
    if (nextVisitStamp == std::numeric_limits<int>::max()) {
      std::fill(visitStamp.begin(), visitStamp.end(), 0);
      nextVisitStamp = 0;
    }
    const int stamp = ++nextVisitStamp;
    std::queue<int> queue;
    queue.push(source);
    visitStamp[static_cast<std::size_t>(source)] = stamp;
    visitDepth[static_cast<std::size_t>(source)] = 0;
    std::vector<int> &neighborhood =
        geodesicNeighborhoods[static_cast<std::size_t>(source)];
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      neighborhood.push_back(face);
      if (visitDepth[static_cast<std::size_t>(face)] >=
          options.geodesicExclusionDepth) {
        continue;
      }
      for (const auto &[neighbor, key] :
           adjacency[static_cast<std::size_t>(face)]) {
        (void)key;
        if (visitStamp[static_cast<std::size_t>(neighbor)] == stamp) {
          continue;
        }
        visitStamp[static_cast<std::size_t>(neighbor)] = stamp;
        visitDepth[static_cast<std::size_t>(neighbor)] =
            visitDepth[static_cast<std::size_t>(face)] + 1;
        queue.push(neighbor);
      }
    }
    std::sort(neighborhood.begin(), neighborhood.end());
    geodesicNeighborhoodReady[static_cast<std::size_t>(source)] = true;
  };
  const auto geodesically_near = [&](const int source, const int target) {
    ensure_geodesic_neighborhood(source);
    const std::vector<int> &neighborhood =
        geodesicNeighborhoods[static_cast<std::size_t>(source)];
    return std::binary_search(neighborhood.begin(), neighborhood.end(), target);
  };

  int nextComponent = 0;
  for (int seed = 0; seed < faceCount; ++seed) {
    if (labels.componentByFace[static_cast<std::size_t>(seed)] >= 0) {
      continue;
    }
    std::queue<int> queue;
    queue.push(seed);
    labels.componentByFace[static_cast<std::size_t>(seed)] = nextComponent;
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      for (const auto &[neighbor, key] :
           adjacency[static_cast<std::size_t>(face)]) {
        (void)key;
        if (labels.componentByFace[static_cast<std::size_t>(neighbor)] >= 0) {
          continue;
        }
        labels.componentByFace[static_cast<std::size_t>(neighbor)] =
            nextComponent;
        queue.push(neighbor);
      }
    }
    ++nextComponent;
  }

  int nextSheet = 0;
  for (int seed = 0; seed < faceCount; ++seed) {
    if (labels.localSheetByFace[static_cast<std::size_t>(seed)] >= 0) {
      continue;
    }
    std::queue<int> queue;
    queue.push(seed);
    labels.localSheetByFace[static_cast<std::size_t>(seed)] = nextSheet;
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      for (const auto &[neighbor, key] :
           adjacency[static_cast<std::size_t>(face)]) {
        if (labels.localSheetByFace[static_cast<std::size_t>(neighbor)] >= 0 ||
            barrierEdges.count(key) != 0 ||
            labels.componentByFace[static_cast<std::size_t>(neighbor)] !=
                labels.componentByFace[static_cast<std::size_t>(face)]) {
          continue;
        }
        if (!options.traverseUnmarkedSharpBends &&
            normals[static_cast<std::size_t>(face)].dot(
                normals[static_cast<std::size_t>(neighbor)]) <
                options.normalCompatibility) {
          continue;
        }
        bool closeSheetConflict = false;
        const GridKey candidateKey =
            faceGridKeys[static_cast<std::size_t>(neighbor)];
        for (int dx = -1; dx <= 1 && !closeSheetConflict; ++dx) {
          for (int dy = -1; dy <= 1 && !closeSheetConflict; ++dy) {
            for (int dz = -1; dz <= 1 && !closeSheetConflict; ++dz) {
              const GridKey queryKey{
                  candidateKey[0] + dx, candidateKey[1] + dy,
                  candidateKey[2] + dz};
              const auto bin = spatialBins.find(queryKey);
              if (bin == spatialBins.end()) {
                continue;
              }
              for (const int sheetFace : bin->second) {
                if (labels.localSheetByFace[
                        static_cast<std::size_t>(sheetFace)] != nextSheet ||
                    geodesically_near(neighbor, sheetFace) ||
                    (centroids[static_cast<std::size_t>(neighbor)] -
                     centroids[static_cast<std::size_t>(sheetFace)])
                            .norm() > closeSheetRadius) {
                  continue;
                }
                if (normals[static_cast<std::size_t>(neighbor)].dot(
                        normals[static_cast<std::size_t>(sheetFace)]) <
                    -options.normalCompatibility) {
                  closeSheetConflict = true;
                  break;
                }
              }
            }
          }
        }
        if (closeSheetConflict) {
          continue;
        }
        labels.localSheetByFace[static_cast<std::size_t>(neighbor)] = nextSheet;
        queue.push(neighbor);
      }
    }
    ++nextSheet;
  }
  return labels;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry {

std::optional<SurfaceTopologyRegion> SurfaceTopologyRegion::make(
    authority::TopologyRegionId id,
    authority::SourceComponentId sourceComponent,
    std::vector<SourceRegionFaceAuthority> faces,
    std::vector<authority::SourceEdgeTopologyKey> boundaryEdges,
    std::vector<authority::SourceEdgeTopologyKey> isolationSeams,
    const int eulerCharacteristic, const int boundaryLoopCount) {
  const auto facesSorted = std::is_sorted(
      faces.begin(), faces.end(),
      [](const SourceRegionFaceAuthority &a,
         const SourceRegionFaceAuthority &b) { return a.topology < b.topology; });
  const auto duplicateFace = std::adjacent_find(
      faces.begin(), faces.end(),
      [](const SourceRegionFaceAuthority &a,
         const SourceRegionFaceAuthority &b) { return a.topology == b.topology; });
  const auto sortedUnique = [](const auto &values) {
    return std::is_sorted(values.begin(), values.end()) &&
           std::adjacent_find(values.begin(), values.end()) == values.end();
  };
  if (faces.empty() || !facesSorted || duplicateFace != faces.end() ||
      !sortedUnique(boundaryEdges) || !sortedUnique(isolationSeams) ||
      boundaryLoopCount < 0) {
    return std::nullopt;
  }
  for (const auto &edge : isolationSeams) {
    if (std::binary_search(boundaryEdges.begin(), boundaryEdges.end(), edge)) {
      return std::nullopt;
    }
  }
  return SurfaceTopologyRegion(
      id, sourceComponent, std::move(faces), std::move(boundaryEdges),
      std::move(isolationSeams), eulerCharacteristic, boundaryLoopCount);
}

std::optional<SourceTopologyRegions> SourceTopologyRegions::make(
    std::vector<authority::SourceFaceTopologyKey> rowTopology,
    const std::vector<authority::SourceComponentId> &rowComponents,
    const std::vector<authority::IsolationSheetId> &rowSheets,
    std::vector<SurfaceTopologyRegion> regions) {
  const std::size_t faceCount = rowTopology.size();
  if (faceCount == 0U || regions.empty() || rowComponents.size() != faceCount ||
      rowSheets.size() != faceCount) {
    return std::nullopt;
  }

  const std::size_t regionExtent = regions.size();
  for (std::size_t index = 0; index < regions.size(); ++index) {
    const auto expected = authority::TopologyRegionId::from_index(
        static_cast<std::int64_t>(index), regionExtent);
    if (!expected || regions[index].id() != expected.value()) {
      return std::nullopt;
    }
  }

  std::vector<TopologyRow> topologyRows;
  topologyRows.reserve(faceCount);
  for (std::size_t rowIndex = 0; rowIndex < faceCount; ++rowIndex) {
    const auto row = authority::SourceFaceId::from_index(
        static_cast<std::int64_t>(rowIndex), faceCount);
    if (!row) {
      return std::nullopt;
    }
    topologyRows.emplace_back(rowTopology[rowIndex], row.value());
  }
  std::sort(topologyRows.begin(), topologyRows.end(),
            [](const TopologyRow &a, const TopologyRow &b) {
              return a.topology < b.topology;
            });
  if (std::adjacent_find(
          topologyRows.begin(), topologyRows.end(),
          [](const TopologyRow &a, const TopologyRow &b) {
            return a.topology == b.topology;
          }) != topologyRows.end()) {
    return std::nullopt;
  }

  using ScratchBinding =
      std::pair<authority::TopologyRegionId, std::size_t>;
  std::vector<std::optional<ScratchBinding>> scratchBindings(faceCount);
  for (const SurfaceTopologyRegion &region : regions) {
    for (std::size_t memberIndex = 0; memberIndex < region.faces().size();
         ++memberIndex) {
      const SourceRegionFaceAuthority &member = region.faces()[memberIndex];
      const auto found = std::lower_bound(
          topologyRows.begin(), topologyRows.end(), member.topology,
          [](const TopologyRow &entry,
             const authority::SourceFaceTopologyKey &key) {
            return entry.topology < key;
          });
      if (found == topologyRows.end() || found->topology != member.topology ||
          scratchBindings[found->row.index()].has_value() ||
          rowComponents[found->row.index()] != region.component() ||
          rowSheets[found->row.index()] != member.sheet) {
        return std::nullopt;
      }
      scratchBindings[found->row.index()] =
          ScratchBinding{region.id(), memberIndex};
    }
  }

  std::vector<RowBinding> rowBindings;
  rowBindings.reserve(faceCount);
  for (const auto &binding : scratchBindings) {
    if (!binding.has_value()) {
      return std::nullopt;
    }
    rowBindings.emplace_back(binding->first, binding->second);
  }
  return SourceTopologyRegions(std::move(regions), std::move(rowBindings),
                               std::move(topologyRows));
}

namespace {

bool face_contains_edge(const authority::SourceFaceTopologyKey &face,
                        const authority::SourceEdgeTopologyKey &edge) {
  const auto &vertices = face.vertices();
  const auto contains = [&](authority::SourceVertexId vertex) {
    return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
  };
  return contains(edge.first()) && contains(edge.second());
}

const SurfaceTopologyRegion *find_region(
    const SourceTopologyRegions &authority,
    authority::TopologyRegionId id) noexcept {
  if (id.index() >= authority.regions().size()) return nullptr;
  const SurfaceTopologyRegion &region = authority.regions()[id.index()];
  return region.id() == id ? &region : nullptr;
}

std::optional<authority::CellId> phase_front_cell_id_from_lattice(
    const int u, const int v, const int gridU, const int gridV) {
  if (u < 0 || v < 0 || gridU <= 0 || gridV <= 0 || u >= gridU ||
      v >= gridV) {
    return std::nullopt;
  }
  const std::size_t width = static_cast<std::size_t>(gridU);
  const std::size_t height = static_cast<std::size_t>(gridV);
  if (width > std::numeric_limits<std::size_t>::max() / height) {
    return std::nullopt;
  }
  const std::size_t extent = width * height;
  const std::size_t ordinal = static_cast<std::size_t>(v) * width +
                              static_cast<std::size_t>(u);
  if (ordinal > static_cast<std::size_t>(
                    std::numeric_limits<std::int64_t>::max())) {
    return std::nullopt;
  }
  const auto id = authority::CellId::from_index(
      static_cast<std::int64_t>(ordinal), extent);
  return id ? std::optional<authority::CellId>(id.value()) : std::nullopt;
}

std::optional<std::map<authority::CellId, std::size_t>>
phase_front_cell_storage_index(
    const std::vector<SurfacePhaseFrontCell> &cells) {
  std::map<authority::CellId, std::size_t> indexById;
  for (std::size_t index = 0; index < cells.size(); ++index) {
    if (!indexById.emplace(cells[index].id, index).second) {
      return std::nullopt;
    }
  }
  return indexById;
}

} // namespace

SurfaceIsolationSeamTransportCertificate::ConstructionResult
SurfaceIsolationSeamTransportCertificate::make(
    const SourceTopologyRegions &sourceAuthority,
    authority::TopologyRegionId region,
    authority::SourceEdgeTopologyKey seam,
    authority::InteriorTransitionId transition,
    authority::SourceFaceTopologyKey firstFace,
    authority::SourceFaceTopologyKey secondFace,
    authority::IsolationSheetId firstSheet,
    authority::IsolationSheetId secondSheet,
    authority::QuarterTurn forward, authority::QuarterTurn reverse) {
  SurfaceIsolationSeamTransportCertificateError error;
  error.region = region;
  error.seam = seam;
  error.transition = transition;
  error.firstFace = firstFace;
  error.secondFace = secondFace;
  error.firstSheet = firstSheet;
  error.secondSheet = secondSheet;

  const SurfaceTopologyRegion *owner = find_region(sourceAuthority, region);
  if (owner == nullptr) {
    error.code = SurfaceIsolationSeamTransportCertificateErrorCode::UnknownRegion;
    return error;
  }
  if (!std::binary_search(owner->isolation_seams().begin(),
                          owner->isolation_seams().end(), seam)) {
    error.code =
        SurfaceIsolationSeamTransportCertificateErrorCode::SeamNotOwnedByRegion;
    return error;
  }
  if (!(firstFace < secondFace)) {
    error.code =
        SurfaceIsolationSeamTransportCertificateErrorCode::NonCanonicalFaceOrder;
    return error;
  }
  const SourceRegionFaceAuthority *first = owner->find_face(firstFace);
  const SourceRegionFaceAuthority *second = owner->find_face(secondFace);
  if (first == nullptr || second == nullptr) {
    error.code =
        SurfaceIsolationSeamTransportCertificateErrorCode::FaceNotOwnedByRegion;
    return error;
  }
  if (!face_contains_edge(firstFace, seam) || !face_contains_edge(secondFace, seam)) {
    error.code =
        SurfaceIsolationSeamTransportCertificateErrorCode::SeamIncidenceMismatch;
    return error;
  }
  if (first->sheet != firstSheet || second->sheet != secondSheet) {
    error.code =
        SurfaceIsolationSeamTransportCertificateErrorCode::SheetOwnershipMismatch;
    return error;
  }
  if (firstSheet == secondSheet) {
    error.code = SurfaceIsolationSeamTransportCertificateErrorCode::SameSheet;
    return error;
  }
  if (compose(forward, reverse) != authority::QuarterTurn{}) {
    error.code =
        SurfaceIsolationSeamTransportCertificateErrorCode::NonReciprocalTransport;
    return error;
  }
  return SurfaceIsolationSeamTransportCertificate(
      region, seam, transition, firstFace, secondFace, firstSheet, secondSheet,
      forward, reverse);
}

SurfacePeriodicHolonomy::ConstructionResult SurfacePeriodicHolonomy::make(
    authority::PeriodicRelationId id,
    authority::TopologyRegionId sourceTopologyRegion,
    authority::GridAutomorphism action, authority::CanonicalRoute route,
    authority::CanonicalRoute cutRoute) {
  SurfacePeriodicHolonomyError error;
  error.id = id;
  error.region = sourceTopologyRegion;
  if (action.shift.x == 0 && action.shift.y == 0) {
    error.code = SurfacePeriodicHolonomyErrorCode::ZeroTranslation;
    return error;
  }
  if (route.empty()) {
    error.code = SurfacePeriodicHolonomyErrorCode::MissingRoute;
    return error;
  }
  if (cutRoute.empty()) {
    error.code = SurfacePeriodicHolonomyErrorCode::MissingCutRoute;
    return error;
  }
  return SurfacePeriodicHolonomy(id, sourceTopologyRegion, action,
                                 std::move(route), std::move(cutRoute));
}

SurfacePhaseFrontProduct::ConstructionResult SurfacePhaseFrontProduct::make(
    int gridU, int gridV, SourceTopologyRegions sourceTopologyRegions,
    std::vector<SurfaceIsolationSeamTransportCertificate>
        isolationSeamTransportCertificates,
    std::vector<SurfacePeriodicHolonomy> periodicHolonomies,
    std::vector<SurfaceBoundedDiskBoundaryPhase> boundedDiskBoundaryPhases,
    std::vector<SurfaceFrontEdge> edges,
    std::vector<SurfaceFrontEvent> events,
    std::vector<SurfacePhaseFrontCell> cells) {
  SurfacePhaseFrontProductError error;
  if (sourceTopologyRegions.regions().empty() ||
      sourceTopologyRegions.face_count() == 0U) {
    error.code = SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority;
    return error;
  }
  if (cells.empty()) {
    error.code = SurfacePhaseFrontProductErrorCode::EmptyCells;
    return error;
  }
  if (edges.empty()) {
    error.code = SurfacePhaseFrontProductErrorCode::EmptyEdges;
    return error;
  }

  std::map<authority::CellId, const SurfacePhaseFrontCell *> cellById;
  for (const SurfacePhaseFrontCell &cell : cells) {
    if (!cellById.emplace(cell.id, &cell).second) {
      error.code = SurfacePhaseFrontProductErrorCode::DuplicateCellId;
      error.cell = cell.id;
      return error;
    }
    if (find_region(sourceTopologyRegions, cell.sourceTopologyRegion) == nullptr) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidCellRegion;
      error.cell = cell.id;
      error.region = cell.sourceTopologyRegion;
      return error;
    }
  }

  std::map<authority::PeriodicRelationId, const SurfacePeriodicHolonomy *>
      relationById;
  for (const SurfacePeriodicHolonomy &relation : periodicHolonomies) {
    if (!relationById.emplace(relation.id(), &relation).second) {
      error.code = SurfacePhaseFrontProductErrorCode::DuplicatePeriodicRelationId;
      error.periodicRelation = relation.id();
      return error;
    }
    if (find_region(sourceTopologyRegions, relation.sourceTopologyRegion()) == nullptr) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidPeriodicRelationRegion;
      error.periodicRelation = relation.id();
      error.region = relation.sourceTopologyRegion();
      return error;
    }
  }

  for (std::size_t edgeIndex = 0; edgeIndex < edges.size(); ++edgeIndex) {
    const SurfaceFrontEdge &edge = edges[edgeIndex];
    const auto cellOwner = cellById.find(edge.filledCell);
    if (cellOwner == cellById.end()) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidEdgeCell;
      error.edge = static_cast<int>(edgeIndex);
      error.cell = edge.filledCell;
      return error;
    }
    if (cellOwner->second->sourceTopologyRegion != edge.sourceTopologyRegion ||
        find_region(sourceTopologyRegions, edge.sourceTopologyRegion) == nullptr) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidEdgeRegion;
      error.edge = static_cast<int>(edgeIndex);
      error.region = edge.sourceTopologyRegion;
      return error;
    }
    if (edge.oppositeEdge >= 0) {
      if (edge.oppositeEdge >= static_cast<int>(edges.size()) ||
          edges[static_cast<std::size_t>(edge.oppositeEdge)].oppositeEdge !=
              static_cast<int>(edgeIndex)) {
        error.code = SurfacePhaseFrontProductErrorCode::InvalidOppositeEdge;
        error.edge = static_cast<int>(edgeIndex);
        return error;
      }
    }
    if (edge.boundaryKind == SurfaceFrontBoundaryKind::PeriodicCut) {
      if (!edge.periodicRelation.has_value()) {
        error.code = SurfacePhaseFrontProductErrorCode::MissingPeriodicRelationOwner;
        error.edge = static_cast<int>(edgeIndex);
        return error;
      }
      const auto owner = relationById.find(*edge.periodicRelation);
      if (owner == relationById.end() ||
          owner->second->sourceTopologyRegion() != edge.sourceTopologyRegion) {
        error.code = SurfacePhaseFrontProductErrorCode::InvalidPeriodicRelationOwner;
        error.edge = static_cast<int>(edgeIndex);
        error.periodicRelation = edge.periodicRelation;
        return error;
      }
    } else if (edge.periodicRelation.has_value()) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidPeriodicRelationOwner;
      error.edge = static_cast<int>(edgeIndex);
      error.periodicRelation = edge.periodicRelation;
      return error;
    }
  }

  for (std::size_t eventIndex = 0; eventIndex < events.size(); ++eventIndex) {
    const SurfaceFrontEvent &event = events[eventIndex];
    if (event.firstEdge < 0 || event.firstEdge >= static_cast<int>(edges.size()) ||
        event.secondEdge >= static_cast<int>(edges.size())) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidEventEdge;
      error.event = static_cast<int>(eventIndex);
      return error;
    }
  }

  std::set<std::pair<authority::TopologyRegionId,
                     authority::SourceEdgeTopologyKey>> certificateKeys;
  for (const SurfaceIsolationSeamTransportCertificate &certificate :
       isolationSeamTransportCertificates) {
    const auto key = std::pair{certificate.region(), certificate.seam()};
    if (!certificateKeys.insert(key).second) {
      error.code = SurfacePhaseFrontProductErrorCode::DuplicateIsolationCertificate;
      error.region = certificate.region();
      return error;
    }
  }
  std::set<std::pair<authority::TopologyRegionId,
                     authority::SourceEdgeTopologyKey>> expectedCertificateKeys;
  for (const SurfaceTopologyRegion &region : sourceTopologyRegions.regions()) {
    for (const authority::SourceEdgeTopologyKey &seam : region.isolation_seams()) {
      expectedCertificateKeys.emplace(region.id(), seam);
    }
  }
  if (certificateKeys != expectedCertificateKeys) {
    error.code = SurfacePhaseFrontProductErrorCode::IsolationCertificateBijectionMismatch;
    return error;
  }

  std::set<authority::TopologyRegionId> boundedDiskRegions;
  for (const SurfaceBoundedDiskBoundaryPhase &phase : boundedDiskBoundaryPhases) {
    if (find_region(sourceTopologyRegions, phase.sourceTopologyRegion) == nullptr) {
      error.code = SurfacePhaseFrontProductErrorCode::InvalidBoundedDiskRegion;
      error.region = phase.sourceTopologyRegion;
      return error;
    }
    if (!boundedDiskRegions.insert(phase.sourceTopologyRegion).second) {
      error.code = SurfacePhaseFrontProductErrorCode::DuplicateBoundedDiskRegion;
      error.region = phase.sourceTopologyRegion;
      return error;
    }
  }

  return SurfacePhaseFrontProduct(
      gridU, gridV, std::move(sourceTopologyRegions),
      std::move(isolationSeamTransportCertificates),
      std::move(periodicHolonomies), std::move(boundedDiskBoundaryPhases),
      std::move(edges), std::move(events), std::move(cells));
}

} // namespace directional::geometry

namespace directional::geometry::surface_cell_tracing_detail {

std::optional<SourceTopologyRegions> build_source_topology_regions(
    const Eigen::MatrixXi &faces, const SurfaceCellTracingOptions &options) {
  const int faceCount = static_cast<int>(faces.rows());
  const bool rawLabelsEnabled = !options.sourceFaceComponents.empty() ||
                                !options.sourceFaceSheets.empty();
  const auto raw_labels_valid = [&]() {
    if (!rawLabelsEnabled) return true;
    if (static_cast<int>(options.sourceFaceComponents.size()) != faceCount ||
        static_cast<int>(options.sourceFaceSheets.size()) != faceCount) {
      return false;
    }
    for (int face = 0; face < faceCount; ++face) {
      if (options.sourceFaceComponents[static_cast<std::size_t>(face)] < 0 ||
          options.sourceFaceSheets[static_cast<std::size_t>(face)] < 0) {
        return false;
      }
    }
    return true;
  };
  const auto raw_component = [&](const int face) {
    return face_label_or_default(options.sourceFaceComponents, face, 0);
  };
  const auto raw_sheet = [&](const int face) {
    return face_label_or_default(options.sourceFaceSheets, face, 0);
  };
  const auto raw_share_component = [&](const int first, const int second) {
    return raw_component(first) == raw_component(second);
  };
  const auto raw_compatible = [&](const int first, const int second) {
    return raw_share_component(first, second) &&
           raw_sheet(first) == raw_sheet(second);
  };
  if (faces.cols() != 3 || faceCount <= 0 || !raw_labels_valid()) {
    return std::nullopt;
  }

  int maxVertex = -1;
  for (int face = 0; face < faceCount; ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      maxVertex = std::max(maxVertex, faces(face, corner));
    }
  }
  if (maxVertex < 0) {
    return std::nullopt;
  }
  const std::size_t vertexExtent = static_cast<std::size_t>(maxVertex) + 1U;
  int maxComponent = 0;
  int maxSheet = 0;
  for (int face = 0; face < faceCount; ++face) {
    maxComponent = std::max(
        maxComponent,
        raw_component(face));
    maxSheet = std::max(
        maxSheet, raw_sheet(face));
  }
  const std::size_t componentExtent =
      static_cast<std::size_t>(std::max(0, maxComponent)) + 1U;
  const std::size_t sheetExtent =
      static_cast<std::size_t>(std::max(0, maxSheet)) + 1U;

  const auto fullIncident = edge_faces(faces);
  std::vector<std::vector<std::pair<int, authority::SourceEdgeTopologyKey>>> adjacency(
      static_cast<std::size_t>(faceCount));
  for (const auto &[key, incident] : fullIncident) {
    const int first = incident[0];
    const int second = incident[1];
    if (first < 0) {
      return std::nullopt;
    }
    if (second < 0) {
      continue;
    }
    if (first >= faceCount || second >= faceCount || first == second) {
      return std::nullopt;
    }
    if (!raw_share_component(first, second)) {
      continue;
    }
    if (options.hardFeatureEdges.count(key) != 0U) {
      continue;
    }
    adjacency[static_cast<std::size_t>(first)].push_back({second, key});
    adjacency[static_cast<std::size_t>(second)].push_back({first, key});
  }
  for (auto &neighbors : adjacency) {
    std::sort(neighbors.begin(), neighbors.end());
  }

  struct ProvisionalRegion {
    std::vector<int> faces;
    std::vector<int> canonicalFaceTopology;
  };
  std::vector<ProvisionalRegion> provisional;
  std::vector<bool> visited(static_cast<std::size_t>(faceCount), false);
  const auto canonical_face = [&](const int face) {
    std::array<int, 3> values{faces(face, 0), faces(face, 1), faces(face, 2)};
    std::sort(values.begin(), values.end());
    return values;
  };
  for (int seed = 0; seed < faceCount; ++seed) {
    if (visited[static_cast<std::size_t>(seed)]) {
      continue;
    }
    ProvisionalRegion region;
    std::queue<int> queue;
    queue.push(seed);
    visited[static_cast<std::size_t>(seed)] = true;
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      region.faces.push_back(face);
      for (const auto &[neighbor, key] :
           adjacency[static_cast<std::size_t>(face)]) {
        (void)key;
        if (!visited[static_cast<std::size_t>(neighbor)]) {
          visited[static_cast<std::size_t>(neighbor)] = true;
          queue.push(neighbor);
        }
      }
    }
    std::sort(region.faces.begin(), region.faces.end(),
              [&](const int a, const int b) {
                const auto ca = canonical_face(a);
                const auto cb = canonical_face(b);
                return ca != cb ? ca < cb : a < b;
              });
    for (const int face : region.faces) {
      const auto key = canonical_face(face);
      region.canonicalFaceTopology.insert(region.canonicalFaceTopology.end(),
                                          key.begin(), key.end());
    }
    provisional.push_back(std::move(region));
  }
  std::sort(provisional.begin(), provisional.end(),
            [](const ProvisionalRegion &a, const ProvisionalRegion &b) {
              return a.canonicalFaceTopology < b.canonicalFaceTopology;
            });

  struct RegionScratch {
    int id = -1;
    int sourceComponent = -1;
    int eulerCharacteristic = 0;
    int boundaryLoopCount = 0;
    std::vector<int> sourceFaces;
    std::vector<int> sourceSheets;
    std::vector<authority::SourceEdgeTopologyKey> boundaryEdges;
    std::vector<authority::SourceEdgeTopologyKey> isolationSeams;
  };

  std::vector<int> scratchRegionByFace(static_cast<std::size_t>(faceCount), -1);
  std::vector<RegionScratch> scratchRegions;
  scratchRegions.reserve(provisional.size());
  for (int regionId = 0; regionId < static_cast<int>(provisional.size());
       ++regionId) {
    const ProvisionalRegion &source =
        provisional[static_cast<std::size_t>(regionId)];
    if (source.faces.empty()) {
      return std::nullopt;
    }
    RegionScratch region;
    region.id = regionId;
    region.sourceFaces = source.faces;
    region.sourceComponent = raw_component(region.sourceFaces.front());
    if (region.sourceComponent < 0) {
      return std::nullopt;
    }
    region.sourceSheets.reserve(region.sourceFaces.size());
    for (const int face : region.sourceFaces) {
      scratchRegionByFace[static_cast<std::size_t>(face)] = regionId;
      if (raw_component(face) !=
          region.sourceComponent) {
        return std::nullopt;
      }
      const int sheet = raw_sheet(face);
      if (sheet < 0) {
        return std::nullopt;
      }
      region.sourceSheets.push_back(sheet);
    }
    scratchRegions.push_back(std::move(region));
  }

  const auto scratch_internal_isolation_seam =
      [&](const int firstFace, const int secondFace,
          const authority::SourceEdgeTopologyKey &edgeKey) {
        return firstFace >= 0 && secondFace >= 0 && firstFace < faceCount &&
               secondFace < faceCount &&
               scratchRegionByFace[static_cast<std::size_t>(firstFace)] >= 0 &&
               scratchRegionByFace[static_cast<std::size_t>(firstFace)] ==
                   scratchRegionByFace[static_cast<std::size_t>(secondFace)] &&
               raw_labels_valid() &&
               raw_share_component(firstFace, secondFace) &&
               !raw_compatible(firstFace, secondFace) &&
               options.hardFeatureEdges.count(edgeKey) == 0U &&
               (!options.reliefBarriersEmbedded ||
                options.reliefBarrierEdges.count(edgeKey) == 0U);
      };

  for (RegionScratch &region : scratchRegions) {
    std::set<int> regionFaces(region.sourceFaces.begin(),
                              region.sourceFaces.end());
    std::set<int> regionVertices;
    std::set<authority::SourceEdgeTopologyKey> regionEdges;
    std::map<int, std::vector<int>> boundaryAdjacency;
    for (const int face : region.sourceFaces) {
      for (int corner = 0; corner < 3; ++corner) {
        regionVertices.insert(faces(face, corner));
        const int a = faces(face, corner);
        const int b = faces(face, (corner + 1) % 3);
        const authority::SourceEdgeTopologyKey key = edge_key(a, b, source_vertex_extent(faces));
        regionEdges.insert(key);
        const auto incident = fullIncident.find(key);
        if (incident == fullIncident.end()) {
          return std::nullopt;
        }
        const int first = incident->second[0];
        const int second = incident->second[1];
        const int opposite =
            first == face ? second : (second == face ? first : -2);
        if (opposite == -2) {
          return std::nullopt;
        }
        if (opposite >= 0 && regionFaces.count(opposite) != 0U) {
          if (face < opposite &&
              scratch_internal_isolation_seam(face, opposite, key)) {
            region.isolationSeams.push_back(key);
          }
          continue;
        }
        region.boundaryEdges.push_back(key);
        boundaryAdjacency[a].push_back(b);
        boundaryAdjacency[b].push_back(a);
      }
    }
    std::sort(region.boundaryEdges.begin(), region.boundaryEdges.end());
    region.boundaryEdges.erase(
        std::unique(region.boundaryEdges.begin(), region.boundaryEdges.end()),
        region.boundaryEdges.end());
    std::sort(region.isolationSeams.begin(), region.isolationSeams.end());
    region.isolationSeams.erase(
        std::unique(region.isolationSeams.begin(), region.isolationSeams.end()),
        region.isolationSeams.end());
    region.eulerCharacteristic = static_cast<int>(regionVertices.size()) -
                                 static_cast<int>(regionEdges.size()) +
                                 static_cast<int>(region.sourceFaces.size());
    std::set<int> unvisitedBoundary;
    for (auto &[vertex, neighbors] : boundaryAdjacency) {
      std::sort(neighbors.begin(), neighbors.end());
      neighbors.erase(std::unique(neighbors.begin(), neighbors.end()),
                      neighbors.end());
      if (neighbors.size() != 2U) {
        return std::nullopt;
      }
      unvisitedBoundary.insert(vertex);
    }
    while (!unvisitedBoundary.empty()) {
      ++region.boundaryLoopCount;
      std::vector<int> stack{*unvisitedBoundary.begin()};
      while (!stack.empty()) {
        const int vertex = stack.back();
        stack.pop_back();
        if (unvisitedBoundary.erase(vertex) == 0U) {
          continue;
        }
        for (const int neighbor : boundaryAdjacency[vertex]) {
          if (unvisitedBoundary.count(neighbor) != 0U) {
            stack.push_back(neighbor);
          }
        }
      }
    }
  }

  const auto typed_face = [&](const int rawFace)
      -> std::optional<authority::SourceFaceTopologyKey> {
    if (rawFace < 0 || rawFace >= faceCount) {
      return std::nullopt;
    }
    const auto a = authority::SourceVertexId::from_index(
        faces(rawFace, 0), vertexExtent);
    const auto b = authority::SourceVertexId::from_index(
        faces(rawFace, 1), vertexExtent);
    const auto c = authority::SourceVertexId::from_index(
        faces(rawFace, 2), vertexExtent);
    if (!a || !b || !c) {
      return std::nullopt;
    }
    const auto key = authority::SourceFaceTopologyKey::make(
        std::array<authority::SourceVertexId, 3>{a.value(), b.value(), c.value()});
    return key ? std::optional<authority::SourceFaceTopologyKey>(key.value())
               : std::nullopt;
  };

  std::vector<SurfaceTopologyRegion> publishedRegions;
  publishedRegions.reserve(scratchRegions.size());
  for (const RegionScratch &scratch : scratchRegions) {
    const auto regionId = authority::TopologyRegionId::from_index(
        scratch.id, scratchRegions.size());
    const auto component = authority::SourceComponentId::from_index(
        scratch.sourceComponent, componentExtent);
    if (!regionId || !component ||
        scratch.sourceFaces.size() != scratch.sourceSheets.size()) {
      return std::nullopt;
    }

    std::vector<SourceRegionFaceAuthority> regionFaces;
    regionFaces.reserve(scratch.sourceFaces.size());
    for (std::size_t member = 0; member < scratch.sourceFaces.size(); ++member) {
      const auto face = typed_face(scratch.sourceFaces[member]);
      const auto sheet = authority::IsolationSheetId::from_index(
          scratch.sourceSheets[member], sheetExtent);
      if (!face || !sheet) {
        return std::nullopt;
      }
      regionFaces.push_back(SourceRegionFaceAuthority{*face, sheet.value()});
    }
    std::sort(regionFaces.begin(), regionFaces.end(),
              [](const SourceRegionFaceAuthority &a,
                 const SourceRegionFaceAuthority &b) {
                return a.topology < b.topology;
              });

    std::vector<authority::SourceEdgeTopologyKey> boundaryEdges =
        scratch.boundaryEdges;
    std::vector<authority::SourceEdgeTopologyKey> isolationSeams =
        scratch.isolationSeams;
    const auto region = SurfaceTopologyRegion::make(
        regionId.value(), component.value(), std::move(regionFaces),
        std::move(boundaryEdges), std::move(isolationSeams),
        scratch.eulerCharacteristic, scratch.boundaryLoopCount);
    if (!region) {
      return std::nullopt;
    }
    publishedRegions.push_back(*region);
  }
  std::vector<authority::SourceFaceTopologyKey> rowTopology;
  std::vector<authority::SourceComponentId> rowComponents;
  std::vector<authority::IsolationSheetId> rowSheets;
  rowTopology.reserve(static_cast<std::size_t>(faceCount));
  rowComponents.reserve(static_cast<std::size_t>(faceCount));
  rowSheets.reserve(static_cast<std::size_t>(faceCount));
  for (int rawFace = 0; rawFace < faceCount; ++rawFace) {
    const auto topology = typed_face(rawFace);
    const auto component = authority::SourceComponentId::from_index(
        raw_component(rawFace), componentExtent);
    const auto sheet = authority::IsolationSheetId::from_index(
        raw_sheet(rawFace), sheetExtent);
    if (!topology || !component || !sheet) {
      return std::nullopt;
    }
    rowTopology.push_back(*topology);
    rowComponents.push_back(component.value());
    rowSheets.push_back(sheet.value());
  }
  return SourceTopologyRegions::make(
      std::move(rowTopology), rowComponents, rowSheets,
      std::move(publishedRegions));
}

std::uint64_t surface_topology_region_hash_impl(const SurfaceTopologyRegion &region) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto consume = [&](const std::uint64_t value) {
    hash ^= value;
    hash *= 1099511628211ULL;
  };
  consume(region.id().index());
  consume(region.component().index());
  consume(static_cast<std::uint64_t>(region.euler_characteristic()));
  consume(static_cast<std::uint64_t>(region.boundary_loop_count()));
  for (const SourceRegionFaceAuthority &face : region.faces()) {
    for (const authority::SourceVertexId vertex : face.topology.vertices()) {
      consume(vertex.index());
    }
    consume(face.sheet.index());
  }
  for (const authority::SourceEdgeTopologyKey &edge :
       region.boundary_edges()) {
    consume(edge.first().index());
    consume(edge.second().index());
  }
  for (const authority::SourceEdgeTopologyKey &edge :
       region.isolation_seams()) {
    consume(edge.first().index());
    consume(edge.second().index());
  }
  return hash;
}

bool source_edge_is_internal_isolation_seam(
    const SurfaceCellTracingOptions &options, const Eigen::MatrixXi &faces,
    const std::vector<authority::TopologyRegionId> &regionByFace,
    const int firstFace, const int secondFace, const authority::SourceEdgeTopologyKey &edgeKey) {
  const int faceCount = faces.rows();
  if (faceCount <= 0 || firstFace < 0 || secondFace < 0 ||
      firstFace >= faceCount || secondFace >= faceCount ||
      static_cast<int>(regionByFace.size()) != faceCount ||
      regionByFace[static_cast<std::size_t>(firstFace)] !=
          regionByFace[static_cast<std::size_t>(secondFace)] ||
      !source_authority_valid(options, faces) ||
      !source_faces_share_component(options, firstFace, secondFace) ||
      source_faces_compatible(options, firstFace, secondFace) ||
      options.hardFeatureEdges.count(edgeKey) != 0U ||
      (options.reliefBarriersEmbedded &&
       options.reliefBarrierEdges.count(edgeKey) != 0U)) {
    return false;
  }
  return true;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool trace_point_is_valid(const SurfaceTracePoint &point,
                                 const Eigen::MatrixXi &faces) {
  return point.face >= 0 && point.face < faces.rows() &&
         point.barycentric.array().isFinite().all() &&
         std::abs(point.barycentric.sum() - 1.0) <= 1.0e-8 &&
         point.barycentric.minCoeff() >= -1.0e-8;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

IntrinsicSurfaceGraph build_intrinsic_surface_graph(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellTracingOptions &options,
    const std::set<authority::SourceEdgeTopologyKey> &barrierEdges) {
  IntrinsicSurfaceGraph graph;
  graph.faceCount = static_cast<int>(faces.rows());
  graph.adjacency.resize(static_cast<std::size_t>(faces.rows() * 3));

  const auto add_arc = [&](const int a, const int b, const double length) {
    graph.adjacency[static_cast<std::size_t>(a)].push_back({b, length});
    graph.adjacency[static_cast<std::size_t>(b)].push_back({a, length});
  };
  for (int face = 0; face < faces.rows(); ++face) {
    for (int a = 0; a < 3; ++a) {
      for (int b = a + 1; b < 3; ++b) {
        const double length =
            (row3(vertices, faces(face, a)) -
             row3(vertices, faces(face, b)))
                .norm();
        add_arc(graph.node(face, a), graph.node(face, b), length);
      }
    }
  }

  const auto edgeFaces = edge_faces(faces);
  for (const auto &[key, pair] : edgeFaces) {
    if (pair[0] < 0 || pair[1] < 0 || barrierEdges.count(key) != 0 ||
        !source_faces_share_component(options, pair[0], pair[1])) {
      continue;
    }
    const int vertex0 = static_cast<int>(key.first().index());
    const int vertex1 = static_cast<int>(key.second().index());
    for (const int vertex : {vertex0, vertex1}) {
      int firstCorner = -1;
      int secondCorner = -1;
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(pair[0], corner) == vertex) {
          firstCorner = corner;
        }
        if (faces(pair[1], corner) == vertex) {
          secondCorner = corner;
        }
      }
      if (firstCorner >= 0 && secondCorner >= 0) {
        add_arc(graph.node(pair[0], firstCorner),
                graph.node(pair[1], secondCorner), 0.0);
      }
    }
  }

  for (auto &neighbors : graph.adjacency) {
    std::sort(neighbors.begin(), neighbors.end(),
              [](const auto &lhs, const auto &rhs) {
                return std::tie(lhs.first, lhs.second) <
                       std::tie(rhs.first, rhs.second);
              });
  }
  return graph;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::VectorXd intrinsic_distances_from_points(
    const IntrinsicSurfaceGraph &graph, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    const std::vector<SurfaceTracePoint> &sources) {
  using QueueItem = std::pair<double, int>;
  struct Greater {
    bool operator()(const QueueItem &a, const QueueItem &b) const {
      if (a.first != b.first) {
        return a.first > b.first;
      }
      return a.second > b.second;
    }
  };

  Eigen::VectorXd distance = Eigen::VectorXd::Constant(
      static_cast<int>(graph.adjacency.size()),
      std::numeric_limits<double>::infinity());
  std::priority_queue<QueueItem, std::vector<QueueItem>, Greater> queue;
  for (const SurfaceTracePoint &source : sources) {
    if (!trace_point_is_valid(source, faces)) {
      continue;
    }
    const Eigen::RowVector3d position =
        point_position(vertices, faces, source);
    for (int corner = 0; corner < 3; ++corner) {
      const int node = graph.node(source.face, corner);
      const double initial =
          (position - row3(vertices, faces(source.face, corner))).norm();
      if (initial < distance[node]) {
        distance[node] = initial;
        queue.push({initial, node});
      }
    }
  }

  while (!queue.empty()) {
    const auto [currentDistance, node] = queue.top();
    queue.pop();
    if (currentDistance != distance[node]) {
      continue;
    }
    for (const auto &[neighbor, length] :
         graph.adjacency[static_cast<std::size_t>(node)]) {
      const double candidate = currentDistance + length;
      if (candidate + 1.0e-14 < distance[neighbor]) {
        distance[neighbor] = candidate;
        queue.push({candidate, neighbor});
      }
    }
  }
  return distance;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double intrinsic_distance_to_point(
    const IntrinsicSurfaceGraph &graph, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces, const Eigen::VectorXd &distance,
    const SurfaceTracePoint &target) {
  if (!trace_point_is_valid(target, faces) ||
      distance.size() != static_cast<int>(graph.adjacency.size())) {
    return std::numeric_limits<double>::infinity();
  }
  const Eigen::RowVector3d position = point_position(vertices, faces, target);
  double result = std::numeric_limits<double>::infinity();
  for (int corner = 0; corner < 3; ++corner) {
    const int node = graph.node(target.face, corner);
    result = std::min(
        result, distance[node] +
                    (position - row3(vertices, faces(target.face, corner))).norm());
  }
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

double intrinsic_same_sheet_distance(
    const IntrinsicSurfaceGraph &graph, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces, const SurfaceTracePoint &source,
    const SurfaceTracePoint &target) {
  if (!trace_point_is_valid(source, faces) ||
      !trace_point_is_valid(target, faces)) {
    return std::numeric_limits<double>::infinity();
  }
  if (source.face == target.face) {
    return (point_position(vertices, faces, source) -
            point_position(vertices, faces, target))
        .norm();
  }
  const Eigen::VectorXd distance =
      intrinsic_distances_from_points(graph, vertices, faces, {source});
  return intrinsic_distance_to_point(graph, vertices, faces, distance, target);
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

Eigen::VectorXd graph_distances_from_vertices(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &sourceVertices,
    const std::set<authority::SourceEdgeTopologyKey> &barrierEdges) {
  SurfaceCellTracingOptions options;
  const IntrinsicSurfaceGraph graph =
      build_intrinsic_surface_graph(vertices, faces, options, barrierEdges);
  std::vector<SurfaceTracePoint> sources;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      if (std::find(sourceVertices.begin(), sourceVertices.end(),
                    faces(face, corner)) == sourceVertices.end()) {
        continue;
      }
      SurfaceTracePoint point;
      point.face = face;
      point.barycentric[corner] = 1.0;
      sources.push_back(point);
    }
  }
  const Eigen::VectorXd cornerDistance =
      intrinsic_distances_from_points(graph, vertices, faces, sources);
  Eigen::VectorXd vertexDistance = Eigen::VectorXd::Constant(
      vertices.rows(), std::numeric_limits<double>::infinity());
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      vertexDistance[vertex] =
          std::min(vertexDistance[vertex],
                   cornerDistance[graph.node(face, corner)]);
    }
  }
  return vertexDistance;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry {

std::vector<SurfaceTraceSeed> generate_deterministic_surface_seeds(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("surface seeds require a 3D triangle mesh.");
  }
  const int vertexCount = static_cast<int>(vertices.rows());
  if (!surface_cell_tracing_detail::source_authority_valid(
          options, faces)) {
    throw std::invalid_argument(
        "source face component/sheet labels must cover every source face.");
  }
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  const std::set<authority::SourceEdgeTopologyKey> barrierEdges =
      surface_cell_tracing_detail::combined_barrier_edges(options);
  const auto incident =
      surface_cell_tracing_detail::incident_faces_by_vertex(vertexCount, faces);
  std::vector<SurfaceTraceSeed> seeds;
  std::set<std::tuple<int, std::int64_t, std::int64_t, std::int64_t>> seen;

  if (!options.authoritativeRails.empty()) {
    for (const SurfaceCellRail &rail : options.authoritativeRails) {
      const SurfaceSeedProvenance provenance =
          rail.kind == SurfaceCellRailKind::Boundary
              ? SurfaceSeedProvenance::Boundary
              : SurfaceSeedProvenance::Feature;
      for (const SurfaceCellRailSample &sample : rail.samples) {
        if (sample.sourceFace < 0 || sample.sourceFace >= faces.rows()) {
          continue;
        }
        SurfaceTracePoint point;
        point.face = sample.sourceFace;
        point.barycentric = sample.barycentric;
        surface_cell_tracing_detail::append_hard_rail_seed(
            seeds, seen, point, provenance, rail.id);
        // A hard feature is embedded in both incident face charts. Seed both
        // sides so transverse field branches connect the rail to cells on each
        // side instead of depending on the arbitrary provenance face.
        if (rail.kind == SurfaceCellRailKind::HardFeature &&
            sample.sourceEdge >= 0 && sample.sourceEdge < 3) {
          const int a =
              faces(sample.sourceFace, (sample.sourceEdge + 1) % 3);
          const int b =
              faces(sample.sourceFace, (sample.sourceEdge + 2) % 3);
          const auto found = edgeFaces.find(
              surface_cell_tracing_detail::edge_key(a, b, surface_cell_tracing_detail::source_vertex_extent(faces)));
          if (found != edgeFaces.end() && found->second[1] >= 0) {
            const int neighbor = found->second[0] == sample.sourceFace
                                     ? found->second[1]
                                     : found->second[0];
            SurfaceTracePoint opposite;
            opposite.face = neighbor;
            opposite.barycentric =
                surface_cell_tracing_detail::remap_barycentric_to_neighbor(
                    faces, sample.sourceFace, neighbor, sample.barycentric);
            surface_cell_tracing_detail::append_hard_rail_seed(
                seeds, seen, opposite, provenance, rail.id);
          }
        }
      }
    }
  } else {
    for (const auto &[key, pair] : edgeFaces) {
      if (pair[1] >= 0 && options.hardFeatureEdges.count(key) == 0) {
        continue;
      }
      const int a = static_cast<int>(key.first().index());
      const int b = static_cast<int>(key.second().index());
      const double h = 0.5 * (surface_cell_tracing_detail::target_size_at_vertex(
                                  targetSize, a, options.defaultTargetSize) +
                              surface_cell_tracing_detail::target_size_at_vertex(
                                  targetSize, b, options.defaultTargetSize));
      const double length =
          (surface_cell_tracing_detail::row3(vertices, a) -
           surface_cell_tracing_detail::row3(vertices, b))
              .norm();
      const int samples = std::max(1, static_cast<int>(std::ceil(length / h)));
      for (int sample = 0; sample <= samples; ++sample) {
        const double t = static_cast<double>(sample) / samples;
        SurfaceTracePoint point;
        point.face = pair[0];
        for (int corner = 0; corner < 3; ++corner) {
          if (faces(point.face, corner) == a) {
            point.barycentric[corner] = 1.0 - t;
          } else if (faces(point.face, corner) == b) {
            point.barycentric[corner] = t;
          }
        }
        surface_cell_tracing_detail::append_seed(
            seeds, seen, point,
            pair[1] < 0 ? SurfaceSeedProvenance::Boundary
                        : SurfaceSeedProvenance::Feature,
            static_cast<int>((
                (static_cast<std::uint64_t>(key.first().index()) *
                 1099511628211ULL) ^
                static_cast<std::uint64_t>(key.second().index())) &
                0x7fffffffULL));
      }
    }
  }

  const auto add_vertices = [&](const std::vector<int> &verticesToAdd,
                                const SurfaceSeedProvenance provenance) {
    std::vector<int> sorted = verticesToAdd;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    for (const int vertex : sorted) {
      surface_cell_tracing_detail::append_seed(
          seeds, seen,
          surface_cell_tracing_detail::vertex_point(vertex, incident, faces),
          provenance, vertex);
    }
  };
  if (options.fieldAlignedNetwork != nullptr) {
    for (const authority::SourceVertexId vertex :
         options.fieldAlignedNetwork->singularity_vertices()) {
      surface_cell_tracing_detail::append_seed(
          seeds, seen,
          surface_cell_tracing_detail::vertex_point(
              static_cast<int>(vertex.index()), incident, faces),
          SurfaceSeedProvenance::Singularity,
          static_cast<int>(vertex.index()));
    }
  } else {
    add_vertices(options.singularityVertices,
                 SurfaceSeedProvenance::Singularity);
  }
  add_vertices(options.reliefCriticalVertices,
               SurfaceSeedProvenance::ReliefCritical);
  add_vertices(options.reliefRootVertices, SurfaceSeedProvenance::ReliefCritical);

  if (options.reliefRegionLabels.size() == vertexCount) {
    std::map<int, int> representativeByRegion;
    std::set<int> seededRegions;
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      const int region = options.reliefRegionLabels[vertex];
      if (region < 0) {
        continue;
      }
      representativeByRegion.emplace(region, vertex);
    }
    for (const SurfaceTraceSeed &seed : seeds) {
      const int vertex =
          surface_cell_tracing_detail::seed_anchor_vertex(seed, faces,
                                                          vertexCount);
      if (vertex >= 0 && vertex < vertexCount) {
        const int region = options.reliefRegionLabels[vertex];
        if (region >= 0) {
          seededRegions.insert(region);
        }
      }
    }
    for (const auto &[region, representative] : representativeByRegion) {
      if (seededRegions.count(region) == 0) {
        surface_cell_tracing_detail::append_seed(
            seeds, seen,
            surface_cell_tracing_detail::vertex_point(representative, incident,
                                                      faces),
            SurfaceSeedProvenance::ReliefCritical, representative);
      }
    }
  }
  add_vertices(options.separatrixVertices, SurfaceSeedProvenance::Separatrix);
  add_vertices(options.anchors, SurfaceSeedProvenance::Anchor);

  const surface_cell_tracing_detail::IntrinsicSurfaceGraph intrinsicGraph =
      surface_cell_tracing_detail::build_intrinsic_surface_graph(
          vertices, faces, options, barrierEdges);
  Eigen::VectorXd nearest = Eigen::VectorXd::Constant(
      static_cast<int>(intrinsicGraph.adjacency.size()),
      std::numeric_limits<double>::infinity());
  const auto update_nearest = [&]() {
    std::vector<SurfaceTracePoint> sourcePoints;
    sourcePoints.reserve(seeds.size());
    for (const SurfaceTraceSeed &seed : seeds) {
      if (surface_cell_tracing_detail::trace_point_is_valid(seed.point, faces)) {
        sourcePoints.push_back(seed.point);
      }
    }
    nearest = surface_cell_tracing_detail::intrinsic_distances_from_points(
        intrinsicGraph, vertices, faces, sourcePoints);
  };

  if (seeds.empty() && faces.rows() > 0) {
    SurfaceTracePoint point;
    point.face = 0;
    point.barycentric[0] = 1.0;
    surface_cell_tracing_detail::append_seed(
        seeds, seen, point, SurfaceSeedProvenance::AdaptiveFarthest,
        faces(0, 0));
  }
  update_nearest();
  while (true) {
    std::priority_queue<surface_cell_tracing_detail::AdaptiveSeedCandidate>
        uncovered;
    for (int face = 0; face < faces.rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = faces(face, corner);
        const double h =
            options.coverageRadiusFactor *
            surface_cell_tracing_detail::target_size_at_vertex(
                targetSize, vertex, options.defaultTargetSize);
        const int node = intrinsicGraph.node(face, corner);
        const double normalized = h > 0.0 ? nearest[node] / h : 0.0;
        uncovered.push({normalized, face, corner, vertex});
      }
    }
    if (uncovered.empty() || uncovered.top().normalizedDistance <= 1.0) {
      break;
    }

    const auto worst = uncovered.top();
    SurfaceTracePoint point;
    point.face = worst.face;
    // Coverage candidates are cell centers, not topological anchors. Move the
    // selected corner toward its face centroid by a target-size-relative
    // amount. The resulting seed stays within h/4 of the uncovered corner, so
    // the coverage iteration makes progress while avoiding vertex ambiguity.
    const double h =
        options.coverageRadiusFactor *
        surface_cell_tracing_detail::target_size_at_vertex(
            targetSize, worst.vertex, options.defaultTargetSize);
    const Eigen::RowVector3d vertexPosition =
        surface_cell_tracing_detail::row3(vertices, worst.vertex);
    Eigen::RowVector3d faceCentroid = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      faceCentroid += surface_cell_tracing_detail::row3(
                          vertices, faces(worst.face, corner)) /
                      3.0;
    }
    const double cornerToCentroid =
        (faceCentroid - vertexPosition).norm();
    if (!(h > 0.0) || !(cornerToCentroid > 0.0)) {
      throw std::runtime_error(
          "intrinsic farthest-point sampling found a degenerate candidate.");
    }
    const double blend =
        std::clamp(0.25 * h / cornerToCentroid, 1.0e-12, 0.5);
    point.barycentric = Eigen::RowVector3d::Constant(blend / 3.0);
    point.barycentric[worst.corner] += 1.0 - blend;
    const std::size_t oldSize = seeds.size();
    surface_cell_tracing_detail::append_seed(
        seeds, seen, point, SurfaceSeedProvenance::AdaptiveFarthest,
        worst.vertex);
    if (seeds.size() == oldSize) {
      throw std::runtime_error(
          "intrinsic farthest-point sampling made no progress.");
    }
    update_nearest();
  }

  for (int index = 0; index < static_cast<int>(seeds.size()); ++index) {
    seeds[static_cast<std::size_t>(index)].id = index;
  }
  return seeds;
}

} // namespace directional::geometry

namespace directional::geometry::surface_cell_tracing_detail {

struct ProposalFlowline {
  std::vector<SurfaceTraceSegment> segments;
};

struct ProposalFlowlineIntersection {
  bool valid = false;
  SurfaceTracePoint point;
  double firstParameter = 0.0;
  double secondParameter = 0.0;
};

SurfaceTraceSegment reversed_trace_segment(SurfaceTraceSegment segment) {
  std::swap(segment.startBarycentric, segment.endBarycentric);
  std::swap(segment.entryEdge, segment.exitEdge);
  std::swap(segment.railT0, segment.railT1);
  segment.sign = -segment.sign;
  segment.railSideSign = -segment.railSideSign;
  segment.matching = static_cast<int>(
      authority::QuarterTurn::from_integer(segment.matching).inverse().value());
  segment.entryRoute = segment.entryRoute.reversed();
  return segment;
}

bool proposal_trace_is_blocked(const SurfaceTraceResult &trace) {
  return trace.termination == TraceTerminationReason::Feature ||
         trace.termination == TraceTerminationReason::FieldMetadata ||
         trace.termination == TraceTerminationReason::SourceSheet ||
         trace.termination == TraceTerminationReason::Degenerate;
}

bool build_proposal_flowline(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTracePoint &center, const int family, const double halfLength,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    ProposalFlowline &flowline) {
  flowline.segments.clear();
  const SurfaceWalkResult negative = walk_surface_field(
      vertices, faces, faceAxisX, faceAxisY, center, family, -1, halfLength,
      options, edgeMatching, edgeEffort, edgeTransitions);
  const SurfaceWalkResult positive = walk_surface_field(
      vertices, faces, faceAxisX, faceAxisY, center, family, 1, halfLength,
      options, edgeMatching, edgeEffort, edgeTransitions);
  if (proposal_trace_is_blocked(negative.trace) ||
      proposal_trace_is_blocked(positive.trace) ||
      negative.trace.segments.empty() || positive.trace.segments.empty()) {
    return false;
  }
  flowline.segments.reserve(negative.trace.segments.size() +
                            positive.trace.segments.size());
  for (auto segment = negative.trace.segments.rbegin();
       segment != negative.trace.segments.rend(); ++segment) {
    flowline.segments.push_back(reversed_trace_segment(*segment));
  }
  flowline.segments.insert(flowline.segments.end(),
                           positive.trace.segments.begin(),
                           positive.trace.segments.end());
  return true;
}

double cross2(const Eigen::Vector2d &first, const Eigen::Vector2d &second) {
  return first.x() * second.y() - first.y() * second.x();
}

ProposalFlowlineIntersection intersect_proposal_flowlines(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const ProposalFlowline &first, const ProposalFlowline &second,
    const Eigen::RowVector3d &expectedPosition) {
  ProposalFlowlineIntersection best;
  double bestDistance = std::numeric_limits<double>::infinity();
  for (int firstIndex = 0;
       firstIndex < static_cast<int>(first.segments.size()); ++firstIndex) {
    const SurfaceTraceSegment &firstSegment =
        first.segments[static_cast<std::size_t>(firstIndex)];
    for (int secondIndex = 0;
         secondIndex < static_cast<int>(second.segments.size()); ++secondIndex) {
      const SurfaceTraceSegment &secondSegment =
          second.segments[static_cast<std::size_t>(secondIndex)];
      if (firstSegment.face < 0 ||
          firstSegment.face != secondSegment.face) {
        continue;
      }
      const Eigen::Vector2d firstStart(
          firstSegment.startBarycentric[1],
          firstSegment.startBarycentric[2]);
      const Eigen::Vector2d firstDirection(
          firstSegment.endBarycentric[1] -
              firstSegment.startBarycentric[1],
          firstSegment.endBarycentric[2] -
              firstSegment.startBarycentric[2]);
      const Eigen::Vector2d secondStart(
          secondSegment.startBarycentric[1],
          secondSegment.startBarycentric[2]);
      const Eigen::Vector2d secondDirection(
          secondSegment.endBarycentric[1] -
              secondSegment.startBarycentric[1],
          secondSegment.endBarycentric[2] -
              secondSegment.startBarycentric[2]);
      const double denominator = cross2(firstDirection, secondDirection);
      const double directionScale =
          firstDirection.norm() * secondDirection.norm();
      if (!(directionScale > 1.0e-15) ||
          std::abs(denominator) <= 1.0e-10 * directionScale) {
        continue;
      }
      const Eigen::Vector2d offset = secondStart - firstStart;
      const double firstT = cross2(offset, secondDirection) / denominator;
      const double secondT = cross2(offset, firstDirection) / denominator;
      constexpr double parameterTolerance = 1.0e-9;
      if (firstT < -parameterTolerance || firstT > 1.0 + parameterTolerance ||
          secondT < -parameterTolerance ||
          secondT > 1.0 + parameterTolerance) {
        continue;
      }
      SurfaceTracePoint point;
      point.face = firstSegment.face;
      point.barycentric =
          firstSegment.startBarycentric +
          std::clamp(firstT, 0.0, 1.0) *
              (firstSegment.endBarycentric -
               firstSegment.startBarycentric);
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        if (std::abs(point.barycentric[coordinate]) <= 1.0e-12) {
          point.barycentric[coordinate] = 0.0;
        }
      }
      const double barycentricSum = point.barycentric.sum();
      if (!(std::abs(barycentricSum) > 1.0e-15) ||
          !point.barycentric.allFinite()) {
        continue;
      }
      point.barycentric /= barycentricSum;
      const Eigen::RowVector3d position =
          point_position(vertices, faces, point);
      const double distance = (position - expectedPosition).squaredNorm();
      const double firstParameter =
          static_cast<double>(firstIndex) + std::clamp(firstT, 0.0, 1.0);
      const double secondParameter =
          static_cast<double>(secondIndex) + std::clamp(secondT, 0.0, 1.0);
      if (distance < bestDistance - 1.0e-24 ||
          (std::abs(distance - bestDistance) <= 1.0e-24 &&
           std::tie(firstParameter, secondParameter, point.face) <
               std::tie(best.firstParameter, best.secondParameter,
                        best.point.face))) {
        bestDistance = distance;
        best.valid = true;
        best.point = point;
        best.firstParameter = firstParameter;
        best.secondParameter = secondParameter;
      }
    }
  }
  return best;
}

std::vector<SurfaceTraceSegment> reverse_trace_path(
    const std::vector<SurfaceTraceSegment> &path) {
  std::vector<SurfaceTraceSegment> reversed;
  reversed.reserve(path.size());
  for (auto segment = path.rbegin(); segment != path.rend(); ++segment) {
    reversed.push_back(reversed_trace_segment(*segment));
  }
  return reversed;
}

std::vector<SurfaceTraceSegment> extract_proposal_flowline_path(
    const ProposalFlowline &flowline, const double startParameter,
    const double endParameter, const SurfaceTracePoint &startPoint,
    const SurfaceTracePoint &endPoint) {
  if (endParameter + 1.0e-12 < startParameter) {
    return reverse_trace_path(extract_proposal_flowline_path(
        flowline, endParameter, startParameter, endPoint, startPoint));
  }
  std::vector<SurfaceTraceSegment> path;
  if (flowline.segments.empty() ||
      endParameter - startParameter <= 1.0e-12) {
    return path;
  }
  const int lastAvailable = static_cast<int>(flowline.segments.size()) - 1;
  const int firstIndex = std::clamp(
      static_cast<int>(std::floor(startParameter)), 0, lastAvailable);
  const int lastIndex = std::clamp(
      static_cast<int>(std::floor(
          std::min(endParameter,
                   std::nextafter(static_cast<double>(flowline.segments.size()),
                                  0.0)))),
      0, lastAvailable);
  for (int index = firstIndex; index <= lastIndex; ++index) {
    SurfaceTraceSegment segment =
        flowline.segments[static_cast<std::size_t>(index)];
    if (index == firstIndex) {
      if (segment.face != startPoint.face) {
        return {};
      }
      segment.startBarycentric = startPoint.barycentric;
    }
    if (index == lastIndex) {
      if (segment.face != endPoint.face) {
        return {};
      }
      segment.endBarycentric = endPoint.barycentric;
    }
    if ((segment.endBarycentric - segment.startBarycentric).norm() >
        1.0e-12) {
      path.push_back(segment);
    }
  }
  return path;
}

double trace_path_length(const Eigen::MatrixXd &vertices,
                         const Eigen::MatrixXi &faces,
                         const std::vector<SurfaceTraceSegment> &path) {
  double length = 0.0;
  for (const SurfaceTraceSegment &segment : path) {
    length +=
        (point_position(vertices, faces,
                        SurfaceTracePoint{segment.face,
                                          segment.endBarycentric}) -
         point_position(vertices, faces,
                        SurfaceTracePoint{segment.face,
                                          segment.startBarycentric}))
            .norm();
  }
  return length;
}

bool make_intersection_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTraceSeed &seed, const double h,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    SurfaceCellProposal &proposal) {
  const auto offset = [&](const int family, const int sign) {
    return walk_surface_field(vertices, faces, faceAxisX, faceAxisY, seed.point,
                              family, sign, 0.5 * h, options, edgeMatching,
                              edgeEffort, edgeTransitions);
  };
  const SurfaceWalkResult leftCenter = offset(0, -1);
  const SurfaceWalkResult rightCenter = offset(0, 1);
  const SurfaceWalkResult bottomCenter = offset(1, -1);
  const SurfaceWalkResult topCenter = offset(1, 1);
  for (const SurfaceWalkResult *walk :
       {&leftCenter, &rightCenter, &bottomCenter, &topCenter}) {
    if (walk->point.face < 0 || proposal_trace_is_blocked(walk->trace)) {
      return false;
    }
  }

  ProposalFlowline bottom;
  ProposalFlowline right;
  ProposalFlowline top;
  ProposalFlowline left;
  if (!build_proposal_flowline(
          vertices, faces, faceAxisX, faceAxisY, bottomCenter.point, 0, h,
          options, edgeMatching, edgeEffort, edgeTransitions, bottom) ||
      !build_proposal_flowline(
          vertices, faces, faceAxisX, faceAxisY, rightCenter.point, 1, h,
          options, edgeMatching, edgeEffort, edgeTransitions, right) ||
      !build_proposal_flowline(
          vertices, faces, faceAxisX, faceAxisY, topCenter.point, 0, h,
          options, edgeMatching, edgeEffort, edgeTransitions, top) ||
      !build_proposal_flowline(
          vertices, faces, faceAxisX, faceAxisY, leftCenter.point, 1, h,
          options, edgeMatching, edgeEffort, edgeTransitions, left)) {
    return false;
  }

  Eigen::RowVector3d axisX = project_tangent(
      faceAxisX.row(seed.point.face),
      face_normal(vertices, faces, seed.point.face));
  Eigen::RowVector3d axisY = project_tangent(
      faceAxisY.row(seed.point.face),
      face_normal(vertices, faces, seed.point.face));
  if (!(axisX.norm() > 1.0e-12) || !(axisY.norm() > 1.0e-12)) {
    return false;
  }
  axisX.normalize();
  axisY.normalize();
  const Eigen::RowVector3d seedPosition =
      point_position(vertices, faces, seed.point);
  const auto expected = [&](const int xSign, const int ySign) {
    return seedPosition + 0.5 * h *
                              (static_cast<double>(xSign) * axisX +
                               static_cast<double>(ySign) * axisY);
  };

  const ProposalFlowlineIntersection bottomLeft =
      intersect_proposal_flowlines(vertices, faces, bottom, left,
                                   expected(-1, -1));
  const ProposalFlowlineIntersection bottomRight =
      intersect_proposal_flowlines(vertices, faces, bottom, right,
                                   expected(1, -1));
  const ProposalFlowlineIntersection topRight =
      intersect_proposal_flowlines(vertices, faces, top, right,
                                   expected(1, 1));
  const ProposalFlowlineIntersection topLeft =
      intersect_proposal_flowlines(vertices, faces, top, left,
                                   expected(-1, 1));
  if (!bottomLeft.valid || !bottomRight.valid || !topRight.valid ||
      !topLeft.valid) {
    return false;
  }

  proposal.seedId = seed.id;
  proposal.corners = {bottomLeft.point, bottomRight.point, topRight.point,
                      topLeft.point};
  proposal.boundaryPaths[0] = extract_proposal_flowline_path(
      bottom, bottomLeft.firstParameter, bottomRight.firstParameter,
      bottomLeft.point, bottomRight.point);
  proposal.boundaryPaths[1] = extract_proposal_flowline_path(
      right, bottomRight.secondParameter, topRight.secondParameter,
      bottomRight.point, topRight.point);
  proposal.boundaryPaths[2] = extract_proposal_flowline_path(
      top, topRight.firstParameter, topLeft.firstParameter, topRight.point,
      topLeft.point);
  proposal.boundaryPaths[3] = extract_proposal_flowline_path(
      left, topLeft.secondParameter, bottomLeft.secondParameter, topLeft.point,
      bottomLeft.point);
  if (std::any_of(proposal.boundaryPaths.begin(),
                  proposal.boundaryPaths.end(),
                  [](const auto &path) { return path.empty(); })) {
    return false;
  }

  std::array<Eigen::RowVector3d, 4> cornerPositions;
  for (int corner = 0; corner < 4; ++corner) {
    cornerPositions[static_cast<std::size_t>(corner)] = point_position(
        vertices, faces, proposal.corners[static_cast<std::size_t>(corner)]);
  }
  const Eigen::RowVector3d seedNormal = face_normal(
      vertices, faces, seed.point.face);
  const CellRejectionReason loopRejection =
      classify_quad_loop(cornerPositions, h, seedNormal, options);
  if (loopRejection != CellRejectionReason::Accepted) {
    return false;
  }
  for (const auto &path : proposal.boundaryPaths) {
    const double length = trace_path_length(vertices, faces, path);
    if (!std::isfinite(length) ||
        length < options.minimumCellSideFactor * h ||
        length > options.maximumCellSideFactor * h) {
      return false;
    }
    for (const SurfaceTraceSegment &segment : path) {
      if (trace_segment_crosses_authoritative_rail(
              segment, options.authoritativeRails)) {
        return false;
      }
      proposal.sides.push_back(segment);
    }
  }
  const CellRejectionReason boundaryRejection = validate_closed_boundary_paths(
      vertices, faces, proposal.corners, proposal.boundaryPaths,
      options.closureToleranceFactor * h);
  if (boundaryRejection != CellRejectionReason::Accepted) {
    proposal.sides.clear();
    return false;
  }
  proposal.accepted = true;
  proposal.rejection = CellRejectionReason::Accepted;
  proposal.closureError = 0.0;
  return true;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry {

SurfaceTraceResult trace_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTraceSeed &seed, const int family, const int sign,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching,
    const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  if (faceAxisX.rows() != faces.rows() || faceAxisX.cols() != 3 ||
      faceAxisY.rows() != faces.rows() || faceAxisY.cols() != 3) {
    throw std::invalid_argument("face axes must have shape (#F, 3).");
  }
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  const std::set<authority::SourceEdgeTopologyKey> barrierEdges =
      surface_cell_tracing_detail::combined_barrier_edges(options);
  const auto edgeMatchingIndices =
      surface_cell_tracing_detail::edge_matching_indices(edgeFaces);
  const surface_cell_tracing_detail::EdgeTransitionLookup transitionLookup =
      surface_cell_tracing_detail::authoritative_edge_transition_lookup(
          options.fieldTransportAtlas, edgeTransitions,
          surface_cell_tracing_detail::source_vertex_extent(faces));
  const surface_cell_tracing_detail::RailIntervalBuildResult railBuild =
      surface_cell_tracing_detail::rail_interval_refs(
          options.authoritativeRails, vertices, faces, edgeFaces,
          options.fieldAlignedNetwork);
  SurfaceTraceResult result;
  if (railBuild.status != surface_cell_tracing_detail::RailBuildStatus::Valid) {
    result.termination = TraceTerminationReason::FieldMetadata;
    return result;
  }
  const std::vector<surface_cell_tracing_detail::SurfaceCellRailIntervalRef>
      &railIntervals = railBuild.intervals;
  if (transitionLookup.duplicate) {
    result.termination = TraceTerminationReason::FieldMetadata;
    return result;
  }
  if (!surface_cell_tracing_detail::source_authority_valid(
          options, faces)) {
    result.termination = TraceTerminationReason::FieldMetadata;
    return result;
  }
  if (!surface_cell_tracing_detail::trace_point_is_valid(seed.point, faces)) {
    result.termination = TraceTerminationReason::FieldMetadata;
    return result;
  }

  SurfaceTracePoint current = seed.point;
  int currentFamily = family == 0 ? 0 : 1;
  int currentSign = sign >= 0 ? 1 : -1;
  int entryEdge = -1;
  surface_cell_tracing_detail::SurfaceCellRailIntervalSelection activeRail;
  int activeRailDirection = 1;
  double activeRailT = 0.0;
  Eigen::RowVector3d direction = surface_cell_tracing_detail::axis_for_family(
      faceAxisX, faceAxisY, current.face, currentFamily, currentSign);
  std::set<SurfaceTraceState> visitedStates;

  surface_cell_tracing_detail::IntrinsicSurfaceGraph captureGraph;
  Eigen::VectorXd captureDistance;
  if (options.captureRadius > 0.0 && !options.capturePoints.empty()) {
    captureGraph = surface_cell_tracing_detail::build_intrinsic_surface_graph(
        vertices, faces, options, barrierEdges);
    std::vector<SurfaceTracePoint> validCapturePoints;
    validCapturePoints.reserve(options.capturePoints.size());
    for (const SurfaceTracePoint &capture : options.capturePoints) {
      if (surface_cell_tracing_detail::trace_point_is_valid(capture, faces)) {
        validCapturePoints.push_back(capture);
      }
    }
    captureDistance =
        surface_cell_tracing_detail::intrinsic_distances_from_points(
            captureGraph, vertices, faces, validCapturePoints);
  }

  // Vertex-backed seeds are deterministic anchors, but the face used to store
  // their provenance is arbitrary. Resolve the incident wedge entered by this
  // particular cross-field branch before taking its first finite step.
  const int initialVertexCorner =
      surface_cell_tracing_detail::hit_vertex(current.barycentric);
  if (initialVertexCorner >= 0) {
    const int initialVertex = faces(current.face, initialVertexCorner);
    if (surface_cell_tracing_detail::tracing_is_singularity_vertex(
            options, faces, initialVertex) &&
        seed.provenance != SurfaceSeedProvenance::Singularity) {
      result.termination = TraceTerminationReason::Singularity;
      return result;
    }
    const Eigen::RowVector3d initialNormal =
        surface_cell_tracing_detail::face_normal(vertices, faces, current.face);
    direction =
        surface_cell_tracing_detail::project_tangent(direction, initialNormal);
    if (direction.squaredNorm() == 0.0) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    if (!surface_cell_tracing_detail::direction_enters_face_from_vertex(
            vertices, faces, current.face, initialVertex, direction)) {
      const surface_cell_tracing_detail::VertexContinuationResult continuation =
          surface_cell_tracing_detail::resolve_vertex_continuation(
              vertices, faces, faceAxisX, faceAxisY, edgeFaces,
              edgeMatchingIndices, transitionLookup, current.face,
              initialVertex, currentFamily, currentSign, direction, options,
              edgeMatching, edgeEffort, edgeTransitions);
      if (continuation.status !=
          surface_cell_tracing_detail::VertexContinuationStatus::Found) {
        switch (continuation.status) {
        case surface_cell_tracing_detail::VertexContinuationStatus::Feature:
          result.termination = TraceTerminationReason::Feature;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::SourceSheet:
          result.termination = TraceTerminationReason::SourceSheet;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::FieldMetadata:
          result.termination = TraceTerminationReason::FieldMetadata;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::Boundary:
          result.termination = TraceTerminationReason::Boundary;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::Found:
          break;
        }
        return result;
      }
      current = surface_cell_tracing_detail::vertex_point_in_face(
          faces, continuation.face, initialVertex);
      currentFamily = continuation.family;
      currentSign = continuation.sign;
      direction = continuation.direction;
    }
  }

  // Edge-backed rail seeds need the same wedge resolution as vertex seeds.
  // Without it, a branch pointing into the opposite incident face starts at
  // barycentric zero and marches outside the current triangle because the
  // zero-length edge exit is ignored by the positive-step intersection test.
  if (initialVertexCorner < 0) {
    int initialEdge = -1;
    for (int edge = 0; edge < 3; ++edge) {
      if (surface_cell_tracing_detail::point_on_edge(current.barycentric,
                                                     edge)) {
        initialEdge = edge;
        break;
      }
    }
    if (initialEdge >= 0) {
      const Eigen::RowVector3d initialNormal =
          surface_cell_tracing_detail::face_normal(vertices, faces,
                                                   current.face);
      direction =
          surface_cell_tracing_detail::project_tangent(direction, initialNormal);
      Eigen::RowVector3d derivative;
      if (direction.squaredNorm() == 0.0 ||
          !surface_cell_tracing_detail::barycentric_derivative(
              vertices, faces, current.face, direction, derivative)) {
        result.termination = TraceTerminationReason::Degenerate;
        return result;
      }
      const int a = faces(current.face, (initialEdge + 1) % 3);
      const int b = faces(current.face, (initialEdge + 2) % 3);
      const authority::SourceEdgeTopologyKey key = surface_cell_tracing_detail::edge_key(a, b, surface_cell_tracing_detail::source_vertex_extent(faces));
      const bool hardBarrier = options.hardFeatureEdges.count(key) != 0;
      const bool reliefBarrier =
          options.reliefBarriersEmbedded &&
          options.reliefBarrierEdges.count(key) != 0;
      const Eigen::RowVector3d edgeDirection =
          (surface_cell_tracing_detail::row3(vertices, b) -
           surface_cell_tracing_detail::row3(vertices, a))
              .normalized();
      const double railAlignment = std::abs(edgeDirection.dot(direction));

      if (hardBarrier && options.followCompatibleHardFeatureRails &&
          railAlignment >= 0.7) {
        activeRail = surface_cell_tracing_detail::find_rail_interval(
            railIntervals, current.face, initialEdge);
        if (activeRail.interval == nullptr) {
          result.termination = TraceTerminationReason::Feature;
          return result;
        }
        const Eigen::RowVector3d railDelta =
            activeRail.interval->end.position -
            activeRail.interval->start.position;
        activeRailDirection = railDelta.dot(direction) >= 0.0 ? 1 : -1;
        activeRailT =
            surface_cell_tracing_detail::rail_parameter_at_position(
                *activeRail.interval,
                surface_cell_tracing_detail::point_position(vertices, faces,
                                                             current));
        direction = surface_cell_tracing_detail::rail_direction(
            *activeRail.interval, activeRailDirection);
        entryEdge = initialEdge;
      } else if (derivative[initialEdge] < -1.0e-12) {
        if (hardBarrier || reliefBarrier) {
          result.termination = TraceTerminationReason::Feature;
          return result;
        }
        const auto found = edgeFaces.find(key);
        if (found == edgeFaces.end() || found->second[1] < 0) {
          result.termination = TraceTerminationReason::Boundary;
          return result;
        }
        const int nextFace = found->second[0] == current.face
                                 ? found->second[1]
                                 : found->second[0];
        if (!surface_cell_tracing_detail::source_faces_share_component(
                options, current.face, nextFace)) {
          result.termination = TraceTerminationReason::SourceSheet;
          return result;
        }
        surface_cell_tracing_detail::BranchTransitionResult transition =
            surface_cell_tracing_detail::resolve_branch_transition(
                vertices, faces, faceAxisX, faceAxisY, edgeFaces,
                edgeMatchingIndices, transitionLookup, key, current.face,
                nextFace, currentFamily, currentSign, direction, edgeMatching,
                edgeEffort, edgeTransitions);
        if (!transition.valid) {
          result.termination = TraceTerminationReason::FieldMetadata;
          return result;
        }
        const int nextEntryEdge =
            surface_cell_tracing_detail::local_edge_for_key(faces, nextFace,
                                                            key);
        if (nextEntryEdge < 0) {
          result.termination = TraceTerminationReason::FieldMetadata;
          return result;
        }
        if (!surface_cell_tracing_detail::orient_transition_into_face_from_edge(
                vertices, faces, nextFace, nextEntryEdge, transition)) {
          result.termination = TraceTerminationReason::Degenerate;
          return result;
        }
        current.barycentric =
            surface_cell_tracing_detail::remap_barycentric_to_neighbor(
                faces, current.face, nextFace, current.barycentric);
        current.face = nextFace;
        currentFamily = transition.family;
        currentSign = transition.sign;
        direction = transition.direction;
        entryEdge = nextEntryEdge;
      }
    }
  }

  for (int step = 0; step < options.maxTraceSegments &&
                     result.length < options.maxTraceLength;
       ++step) {
    const SurfaceTraceState state =
        surface_cell_tracing_detail::make_trace_state(
            current, entryEdge, currentFamily, currentSign);
    result.states.push_back(state);
    if (!visitedStates.insert(state).second && step > 0) {
      result.termination = TraceTerminationReason::RepeatedState;
      return result;
    }

    const Eigen::RowVector3d normal =
        surface_cell_tracing_detail::face_normal(vertices, faces, current.face);
    if (activeRail.interval != nullptr) {
      direction = surface_cell_tracing_detail::rail_direction(
          *activeRail.interval, activeRailDirection);
    }
    direction = surface_cell_tracing_detail::project_tangent(direction, normal);
    if (direction.squaredNorm() == 0.0) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }

    Eigen::RowVector3d dbary;
    if (!surface_cell_tracing_detail::barycentric_derivative(
            vertices, faces, current.face, direction, dbary)) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    double bestT = std::numeric_limits<double>::infinity();
    int hitCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (dbary[corner] < -1.0e-14) {
        const double t = -current.barycentric[corner] / dbary[corner];
        if (t > 1.0e-12 &&
            (t < bestT - 1.0e-14 ||
             (std::abs(t - bestT) <= 1.0e-14 && corner < hitCorner))) {
          bestT = t;
          hitCorner = corner;
        }
      }
    }
    if (hitCorner < 0 || !std::isfinite(bestT)) {
      if (step > 0 &&
          (surface_cell_tracing_detail::point_on_edge(current.barycentric, 0) ||
           surface_cell_tracing_detail::point_on_edge(current.barycentric, 1) ||
           surface_cell_tracing_detail::point_on_edge(current.barycentric, 2))) {
        result.termination = TraceTerminationReason::RepeatedState;
        return result;
      }
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    Eigen::RowVector3d nextBary = current.barycentric + bestT * dbary;
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(nextBary[corner]) < 1.0e-10) {
        nextBary[corner] = 0.0;
      }
    }
    const double nextBarySum = nextBary.sum();
    if (!nextBary.array().isFinite().all() ||
        !std::isfinite(nextBarySum) || std::abs(nextBarySum) <= 1.0e-14) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    nextBary /= nextBarySum;
    if (nextBary.minCoeff() < -1.0e-10 ||
        nextBary.maxCoeff() > 1.0 + 1.0e-10) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }

    SurfaceTracePoint nextPoint;
    nextPoint.face = current.face;
    nextPoint.barycentric = nextBary;
    const Eigen::RowVector3d start =
        surface_cell_tracing_detail::point_position(vertices, faces, current);
    const Eigen::RowVector3d end =
        surface_cell_tracing_detail::point_position(vertices, faces, nextPoint);

    SurfaceTraceSegment segment;
    segment.face = current.face;
    segment.startBarycentric = current.barycentric;
    segment.endBarycentric = nextBary;
    segment.family = currentFamily;
    segment.sign = currentSign;
    segment.entryEdge = entryEdge;
    segment.exitEdge = hitCorner;
    if (activeRail.interval != nullptr) {
      segment.railId = activeRail.interval->railId;
      segment.curveId = activeRail.interval->curveId;
      segment.railIntervalIndex = activeRail.interval->intervalIndex;
      segment.railSideSign = activeRail.side.sideSign;
      segment.railT0 = activeRailT;
      segment.railT1 =
          surface_cell_tracing_detail::rail_parameter_at_position(
              *activeRail.interval, end);
    }
    result.segments.push_back(segment);

    const double segmentLength = (end - start).norm();
    const double remainingLength = options.maxTraceLength - result.length;
    if (segmentLength > remainingLength && remainingLength > 0.0) {
      const double ratio = remainingLength / segmentLength;
      segment.endBarycentric =
          current.barycentric + ratio * (nextBary - current.barycentric);
      segment.endBarycentric /= segment.endBarycentric.sum();
      if (activeRail.interval != nullptr) {
        const SurfaceTracePoint clippedPoint{current.face,
                                             segment.endBarycentric};
        const Eigen::RowVector3d clippedEnd =
            surface_cell_tracing_detail::point_position(vertices, faces,
                                                        clippedPoint);
        segment.railT1 =
            surface_cell_tracing_detail::rail_parameter_at_position(
                *activeRail.interval, clippedEnd);
      }
      result.segments.back() = segment;
      result.length = options.maxTraceLength;
      result.termination = TraceTerminationReason::Budget;
      return result;
    }
    result.length += segmentLength;

    if (options.captureRadius > 0.0) {
      const SurfaceTracePoint traceEndpoint{current.face, nextBary};
      for (const SurfaceTracePoint &capture : options.capturePoints) {
        if (!surface_cell_tracing_detail::trace_point_is_valid(capture, faces) ||
            capture.face != current.face) {
          continue;
        }
        if ((end - surface_cell_tracing_detail::point_position(
                       vertices, faces, capture))
                .norm() <= options.captureRadius) {
          result.segments.back().endBarycentric = capture.barycentric;
          result.termination = TraceTerminationReason::Captured;
          return result;
        }
      }
      if (captureDistance.size() ==
              static_cast<int>(captureGraph.adjacency.size()) &&
          surface_cell_tracing_detail::intrinsic_distance_to_point(
              captureGraph, vertices, faces, captureDistance,
              traceEndpoint) <= options.captureRadius) {
        result.termination = TraceTerminationReason::Captured;
        return result;
      }
    }

    const int hitVertexCorner =
        surface_cell_tracing_detail::hit_vertex(nextBary);
    if (hitVertexCorner >= 0) {
      const int hitVertex = faces(current.face, hitVertexCorner);
      if (surface_cell_tracing_detail::tracing_is_singularity_vertex(
              options, faces, hitVertex)) {
        result.termination = TraceTerminationReason::Singularity;
        return result;
      }
      if (activeRail.interval != nullptr) {
        const surface_cell_tracing_detail::RailContinuationResult continuation =
            surface_cell_tracing_detail::find_next_rail_interval(
                railIntervals, activeRail, activeRailDirection, options);
        if (continuation.status !=
            surface_cell_tracing_detail::RailContinuationStatus::Found) {
          switch (continuation.status) {
          case surface_cell_tracing_detail::RailContinuationStatus::OpenEndpoint:
            result.termination = TraceTerminationReason::Feature;
            break;
          case surface_cell_tracing_detail::RailContinuationStatus::SourceSheetBlocked:
            result.termination = TraceTerminationReason::SourceSheet;
            break;
          case surface_cell_tracing_detail::RailContinuationStatus::MissingInterval:
          case surface_cell_tracing_detail::RailContinuationStatus::SideDiscontinuity:
            result.termination = TraceTerminationReason::FieldMetadata;
            break;
          case surface_cell_tracing_detail::RailContinuationStatus::Found:
            break;
          }
          return result;
        }
        const surface_cell_tracing_detail::SurfaceCellRailIntervalSelection nextRail =
            continuation.selection;
        if (!surface_cell_tracing_detail::source_faces_share_component(
                options, activeRail.side.sourceFace, nextRail.side.sourceFace)) {
          result.termination = TraceTerminationReason::SourceSheet;
          return result;
        }
        activeRail = nextRail;
        current.face = activeRail.side.sourceFace;
        current.barycentric = activeRailDirection >= 0
                                  ? activeRail.side.startBarycentric
                                  : activeRail.side.endBarycentric;
        activeRailT = activeRailDirection >= 0
                          ? activeRail.interval->start.railParameter
                          : activeRail.interval->end.railParameter;
        entryEdge = -1;
        direction = surface_cell_tracing_detail::rail_direction(
            *activeRail.interval, activeRailDirection);
        continue;
      }
      const surface_cell_tracing_detail::VertexContinuationResult continuation =
          surface_cell_tracing_detail::resolve_vertex_continuation(
              vertices, faces, faceAxisX, faceAxisY, edgeFaces,
              edgeMatchingIndices, transitionLookup, current.face, hitVertex,
              currentFamily, currentSign, direction, options, edgeMatching,
              edgeEffort, edgeTransitions);
      if (continuation.status !=
          surface_cell_tracing_detail::VertexContinuationStatus::Found) {
        switch (continuation.status) {
        case surface_cell_tracing_detail::VertexContinuationStatus::Feature:
          result.termination = TraceTerminationReason::Feature;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::SourceSheet:
          result.termination = TraceTerminationReason::SourceSheet;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::FieldMetadata:
          result.termination = TraceTerminationReason::FieldMetadata;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::Boundary:
          result.termination = TraceTerminationReason::Boundary;
          break;
        case surface_cell_tracing_detail::VertexContinuationStatus::Found:
          break;
        }
        return result;
      }
      result.segments.back().matching = continuation.matching;
      result.segments.back().matchingEffort = continuation.matchingEffort;
      current = surface_cell_tracing_detail::vertex_point_in_face(
          faces, continuation.face, hitVertex);
      currentFamily = continuation.family;
      currentSign = continuation.sign;
      entryEdge = -1;
      direction = continuation.direction;
      continue;
    }

    const int a = faces(current.face, (hitCorner + 1) % 3);
    const int b = faces(current.face, (hitCorner + 2) % 3);
    const authority::SourceEdgeTopologyKey key = surface_cell_tracing_detail::edge_key(a, b, surface_cell_tracing_detail::source_vertex_extent(faces));
    if (options.hardFeatureEdges.count(key) != 0) {
      const Eigen::RowVector3d edgeDirection =
          (surface_cell_tracing_detail::row3(vertices, b) -
           surface_cell_tracing_detail::row3(vertices, a))
              .normalized();
      const double railAlignment =
          std::abs(surface_cell_tracing_detail::project_tangent(edgeDirection, normal)
                       .dot(direction));
      if (options.followCompatibleHardFeatureRails && railAlignment >= 0.7) {
        const surface_cell_tracing_detail::SurfaceCellRailIntervalSelection rail =
            surface_cell_tracing_detail::find_rail_interval(
                railIntervals, current.face, hitCorner);
        if (rail.interval == nullptr) {
          result.termination = TraceTerminationReason::Feature;
          return result;
        }
        const Eigen::RowVector3d railDelta =
            rail.interval->end.position - rail.interval->start.position;
        activeRailDirection = railDelta.dot(direction) >= 0.0 ? 1 : -1;
        activeRail = rail;
        activeRailT =
            surface_cell_tracing_detail::rail_parameter_at_position(
                *activeRail.interval, end);
        current.barycentric = nextBary;
        direction = surface_cell_tracing_detail::rail_direction(
            *activeRail.interval, activeRailDirection);
        entryEdge = hitCorner;
        continue;
      }
      result.termination = TraceTerminationReason::Feature;
      return result;
    }
    if (options.reliefBarriersEmbedded &&
        options.reliefBarrierEdges.count(key) != 0) {
      result.termination = TraceTerminationReason::Feature;
      return result;
    }
    const auto found = edgeFaces.find(key);
    if (found == edgeFaces.end() || found->second[1] < 0) {
      result.termination = TraceTerminationReason::Boundary;
      return result;
    }
    const int nextFace =
        found->second[0] == current.face ? found->second[1] : found->second[0];
    if (!surface_cell_tracing_detail::source_faces_share_component(options,
                                                              current.face,
                                                              nextFace)) {
      result.termination = TraceTerminationReason::SourceSheet;
      return result;
    }
    nextPoint.face = nextFace;
    nextPoint.barycentric =
        surface_cell_tracing_detail::remap_barycentric_to_neighbor(
            faces, current.face, nextFace, nextBary);
    surface_cell_tracing_detail::BranchTransitionResult transition =
        surface_cell_tracing_detail::resolve_branch_transition(
            vertices, faces, faceAxisX, faceAxisY, edgeFaces,
            edgeMatchingIndices, transitionLookup, key, current.face, nextFace,
            currentFamily, currentSign, direction, edgeMatching, edgeEffort,
            edgeTransitions);
    if (!transition.valid) {
      result.termination = TraceTerminationReason::FieldMetadata;
      return result;
    }
    const int nextEntryEdge =
        surface_cell_tracing_detail::local_edge_for_key(faces, nextFace, key);
    if (nextEntryEdge < 0) {
      result.termination = TraceTerminationReason::FieldMetadata;
      return result;
    }
    if (!surface_cell_tracing_detail::orient_transition_into_face_from_edge(
            vertices, faces, nextFace, nextEntryEdge, transition)) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    result.segments.back().matching = transition.matching;
    result.segments.back().matchingEffort = transition.effort;
    current = nextPoint;
    currentFamily = transition.family;
    currentSign = transition.sign;
    entryEdge = nextEntryEdge;
    direction = transition.direction;
  }

  result.termination = TraceTerminationReason::Budget;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceWalkResult walk_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTracePoint &start, const int family, const int sign,
    const double distance, const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching,
    const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfaceCellTracingOptions walkOptions = options;
  walkOptions.maxTraceLength = std::max(0.0, distance);
  SurfaceTraceSeed seed;
  seed.point = start;
  SurfaceWalkResult walk;
  walk.point = start;
  walk.trace = trace_surface_field(vertices, faces, faceAxisX, faceAxisY, seed,
                                   family, sign, walkOptions, edgeMatching,
                                   edgeEffort, edgeTransitions);
  if (!walk.trace.segments.empty()) {
    const SurfaceTraceSegment &last = walk.trace.segments.back();
    walk.point.face = last.face;
    walk.point.barycentric = last.endBarycentric;
  }
  return walk;
}

} // namespace directional::geometry

namespace directional::geometry {

void cross_field_axes(const fields::CrossFieldResult &crossField,
                             Eigen::MatrixXd &faceAxisX,
                             Eigen::MatrixXd &faceAxisY) {
  if (crossField.primaryDirections.cols() == 3 &&
      crossField.secondaryDirections.cols() == 3 &&
      crossField.primaryDirections.rows() == crossField.secondaryDirections.rows()) {
    faceAxisX = crossField.primaryDirections;
    faceAxisY = crossField.secondaryDirections;
    return;
  }
  if (crossField.rawField.cols() < 6) {
    throw std::invalid_argument(
        "CrossFieldResult must contain primary/secondary directions or #F-by-12 rawField.");
  }
  faceAxisX = crossField.rawField.block(0, 0, crossField.rawField.rows(), 3);
  faceAxisY = crossField.rawField.block(0, 3, crossField.rawField.rows(), 3);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceTraceResult trace_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const SurfaceTraceSeed &seed,
    const int family, const int sign,
    const SurfaceCellTracingOptions &options) {
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  cross_field_axes(crossField, faceAxisX, faceAxisY);
  return trace_surface_field(vertices, faces, faceAxisX, faceAxisY, seed, family,
                             sign, options, &crossField.matching,
                             &crossField.effort,
                             &crossField.edgeTransitions);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching,
    const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfaceCellProposal proposal;
  proposal.seedId = seed.id;
  proposal.corners.fill(seed.point);
  const int face = seed.point.face;
  if (face < 0) {
    proposal.rejection = CellRejectionReason::Degenerate;
    return proposal;
  }
  double h = 0.0;
  for (int corner = 0; corner < 3; ++corner) {
    h += seed.point.barycentric[corner] *
         surface_cell_tracing_detail::target_size_at_vertex(
             targetSize, faces(face, corner), options.defaultTargetSize);
  }
  const double hx = h;
  const double hy = h;

  if (surface_cell_tracing_detail::make_intersection_surface_cell_proposal(
          vertices, faces, faceAxisX, faceAxisY, seed, h, options,
          edgeMatching, edgeEffort, edgeTransitions, proposal)) {
    return proposal;
  }

  const std::array<std::pair<int, int>, 4> cornerSigns{
      std::pair<int, int>{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
  for (int corner = 0; corner < 4; ++corner) {
      const int sx = cornerSigns[static_cast<std::size_t>(corner)].first;
      const int sy = cornerSigns[static_cast<std::size_t>(corner)].second;
      const SurfaceWalkResult xFirst = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, 0, sx, 0.5 * hx,
          options, edgeMatching, edgeEffort, edgeTransitions);
      const SurfaceWalkResult xy = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, xFirst.point, 1, sy, 0.5 * hy,
          options, edgeMatching, edgeEffort, edgeTransitions);
      const SurfaceWalkResult yFirst = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, 1, sy, 0.5 * hy,
          options, edgeMatching, edgeEffort, edgeTransitions);
      const SurfaceWalkResult yx = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, yFirst.point, 0, sx, 0.5 * hx,
          options, edgeMatching, edgeEffort, edgeTransitions);

      if (xFirst.trace.termination == TraceTerminationReason::SourceSheet ||
          xy.trace.termination == TraceTerminationReason::SourceSheet ||
          yFirst.trace.termination == TraceTerminationReason::SourceSheet ||
          yx.trace.termination == TraceTerminationReason::SourceSheet) {
        proposal.rejection = CellRejectionReason::SourceSheet;
        return proposal;
      }
      if (xFirst.trace.termination == TraceTerminationReason::FieldMetadata ||
          xy.trace.termination == TraceTerminationReason::FieldMetadata ||
          yFirst.trace.termination == TraceTerminationReason::FieldMetadata ||
          yx.trace.termination == TraceTerminationReason::FieldMetadata) {
        proposal.rejection = CellRejectionReason::FieldMetadata;
        return proposal;
      }
      if (xFirst.trace.termination == TraceTerminationReason::Feature ||
          xy.trace.termination == TraceTerminationReason::Feature ||
          yFirst.trace.termination == TraceTerminationReason::Feature ||
          yx.trace.termination == TraceTerminationReason::Feature) {
        proposal.rejection = CellRejectionReason::Barrier;
        return proposal;
      }
      if (xy.point.face < 0 || yx.point.face < 0) {
        proposal.rejection = CellRejectionReason::Degenerate;
        return proposal;
      }
      const Eigen::RowVector3d xyPosition =
          surface_cell_tracing_detail::point_position(vertices, faces, xy.point);
      const Eigen::RowVector3d yxPosition =
          surface_cell_tracing_detail::point_position(vertices, faces, yx.point);
      proposal.closureError =
          std::max(proposal.closureError, (xyPosition - yxPosition).norm());
      proposal.corners[static_cast<std::size_t>(corner)] = xy.point;
  }
  if (proposal.closureError >
      options.closureToleranceFactor * std::min(hx, hy)) {
    proposal.rejection = CellRejectionReason::Closure;
    return proposal;
  }
  std::array<Eigen::RowVector3d, 4> cornerPositions;
  for (int corner = 0; corner < 4; ++corner) {
    cornerPositions[static_cast<std::size_t>(corner)] =
        surface_cell_tracing_detail::point_position(
            vertices, faces, proposal.corners[static_cast<std::size_t>(corner)]);
  }
  const Eigen::RowVector3d seedFaceNormal =
      surface_cell_tracing_detail::cross3(
          vertices.row(faces(face, 1)) - vertices.row(faces(face, 0)),
          vertices.row(faces(face, 2)) - vertices.row(faces(face, 0)));
  const CellRejectionReason loopRejection =
      surface_cell_tracing_detail::classify_quad_loop(
          cornerPositions, std::min(hx, hy), seedFaceNormal, options);
  if (loopRejection != CellRejectionReason::Accepted) {
    proposal.rejection = loopRejection;
    return proposal;
  }

  const std::array<std::tuple<int, int, double>, 4> sideWalks{
      std::tuple<int, int, double>{0, 1, hx},
      std::tuple<int, int, double>{1, 1, hy},
      std::tuple<int, int, double>{0, -1, hx},
      std::tuple<int, int, double>{1, -1, hy}};
  for (int sideIndex = 0; sideIndex < 4; ++sideIndex) {
    const auto [sideFamily, sideSign, sideLength] =
        sideWalks[static_cast<std::size_t>(sideIndex)];
    const SurfaceTracePoint &startCorner =
        proposal.corners[static_cast<std::size_t>(sideIndex)];
    const SurfaceTracePoint &endCorner =
        proposal.corners[static_cast<std::size_t>((sideIndex + 1) % 4)];
    const SurfaceWalkResult side = walk_surface_field(
        vertices, faces, faceAxisX, faceAxisY, startCorner, sideFamily, sideSign,
        sideLength, options, edgeMatching, edgeEffort, edgeTransitions);
    if (side.trace.termination == TraceTerminationReason::SourceSheet) {
      proposal.rejection = CellRejectionReason::SourceSheet;
      return proposal;
    }
    if (side.trace.termination == TraceTerminationReason::FieldMetadata) {
      proposal.rejection = CellRejectionReason::FieldMetadata;
      return proposal;
    }
    if (side.trace.termination == TraceTerminationReason::Feature) {
      proposal.rejection = CellRejectionReason::Barrier;
      return proposal;
    }
    if (side.trace.segments.empty()) {
      proposal.rejection = CellRejectionReason::Degenerate;
      return proposal;
    }
    if (!std::isfinite(side.trace.length) ||
        side.trace.length < options.minimumCellSideFactor * sideLength ||
        side.trace.length > options.maximumCellSideFactor * sideLength) {
      proposal.rejection = CellRejectionReason::OutOfSize;
      return proposal;
    }
    const Eigen::RowVector3d actualEnd =
        surface_cell_tracing_detail::point_position(vertices, faces, side.point);
    const Eigen::RowVector3d expectedEnd =
        surface_cell_tracing_detail::point_position(vertices, faces, endCorner);
    const double sideClosure = (actualEnd - expectedEnd).norm();
    proposal.closureError = std::max(proposal.closureError, sideClosure);
    if (sideClosure > options.closureToleranceFactor * std::min(hx, hy)) {
      proposal.rejection = CellRejectionReason::Closure;
      return proposal;
    }
    for (const SurfaceTraceSegment &segment : side.trace.segments) {
      if (surface_cell_tracing_detail::trace_segment_crosses_authoritative_rail(
              segment, options.authoritativeRails)) {
        proposal.rejection = CellRejectionReason::HardRailCrossing;
        return proposal;
      }
    }
    std::vector<SurfaceTraceSegment> closedPath = side.trace.segments;
    if (!closedPath.empty() && closedPath.back().face == endCorner.face) {
      closedPath.back().endBarycentric = endCorner.barycentric;
    }
    proposal.boundaryPaths[static_cast<std::size_t>(sideIndex)] = closedPath;
    proposal.sides.insert(proposal.sides.end(), closedPath.begin(),
                          closedPath.end());
  }
  if (proposal.sides.empty()) {
    proposal.rejection = CellRejectionReason::Degenerate;
    return proposal;
  }
  const CellRejectionReason boundaryRejection =
      surface_cell_tracing_detail::validate_closed_boundary_paths(
          vertices, faces, proposal.corners, proposal.boundaryPaths,
          options.closureToleranceFactor * std::min(hx, hy));
  if (boundaryRejection != CellRejectionReason::Accepted) {
    proposal.rejection = boundaryRejection;
    return proposal;
  }
  proposal.accepted = true;
  proposal.rejection = CellRejectionReason::Accepted;
  return proposal;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const Eigen::VectorXd &targetSize,
    const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options) {
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  cross_field_axes(crossField, faceAxisX, faceAxisY);
  return make_surface_cell_proposal(vertices, faces, faceAxisX, faceAxisY,
                                     targetSize, seed, options,
                                     &crossField.matching, &crossField.effort,
                                     &crossField.edgeTransitions);
}

} // namespace directional::geometry

namespace directional::geometry::surface_cell_tracing_detail {

namespace {

void set_phase_front_failure(
    SurfacePhaseFrontFailure &failure,
    const SurfacePhaseFrontFailureReason reason, const int cell = -1,
    const int side = -1, const int face = -1, const int targetFace = -1,
    const int sourceVertex = -1, const int sourceEdge = -1,
    const int secondarySourceEdge = -1) {
  if (failure.reason != SurfacePhaseFrontFailureReason::None) {
    return;
  }
  failure.reason = reason;
  failure.cell = cell;
  failure.side = side;
  failure.face = face;
  failure.targetFace = targetFace;
  failure.sourceVertex = sourceVertex;
  failure.sourceEdge = sourceEdge;
  failure.secondarySourceEdge = secondarySourceEdge;
}

struct UniformPhaseFrame {
  Eigen::RowVector3d origin = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d axisU = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d axisV = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
  double minU = 0.0;
  double maxU = 0.0;
  double minV = 0.0;
  double maxV = 0.0;
  /// Per-face local branch that represents the global +U lattice direction.
  std::vector<int> faceBranchRotation;
  /// Canonical full-source chart authority for each selected source face.
  /// Field branch orientation remains separately owned by faceBranchRotation.
  std::vector<std::optional<authority::FieldChartId>> faceChart;
};

bool phase_front_cells_have_field_chart_authority(
    const std::vector<SurfacePhaseFrontCell> &cells) {
  for (const SurfacePhaseFrontCell &cell : cells) {
    for (const LocalLatticeState &state : cell.lattice) {
      if (!state.sourceChart.has_value()) {
        return false;
      }
    }
  }
  return true;
}

Eigen::Vector2d phase_uv(const UniformPhaseFrame &frame,
                         const Eigen::RowVector3d &point) {
  const Eigen::RowVector3d offset = point - frame.origin;
  return {offset.dot(frame.axisU), offset.dot(frame.axisV)};
}

bool face_barycentric_from_uv(const Eigen::MatrixXd &vertices,
                              const Eigen::MatrixXi &faces,
                              const UniformPhaseFrame &frame, const int face,
                              const Eigen::Vector2d &uv,
                              Eigen::RowVector3d &barycentric) {
  const Eigen::Vector2d a =
      phase_uv(frame, row3(vertices, faces(face, 0)));
  const Eigen::Vector2d b =
      phase_uv(frame, row3(vertices, faces(face, 1)));
  const Eigen::Vector2d c =
      phase_uv(frame, row3(vertices, faces(face, 2)));
  Eigen::Matrix2d matrix;
  matrix.col(0) = b - a;
  matrix.col(1) = c - a;
  const double determinant = matrix.determinant();
  if (!std::isfinite(determinant) || std::abs(determinant) <= 1.0e-18) {
    return false;
  }
  const Eigen::Vector2d coordinates = matrix.inverse() * (uv - a);
  if (!coordinates.allFinite()) {
    return false;
  }
  barycentric << 1.0 - coordinates.x() - coordinates.y(), coordinates.x(),
      coordinates.y();
  return barycentric.allFinite();
}

bool point_on_source(const Eigen::MatrixXd &vertices,
                     const Eigen::MatrixXi &faces,
                     const UniformPhaseFrame &frame,
                     const std::vector<authority::SourceFaceId> &activeFaces,
                     const Eigen::Vector2d &uv, SurfaceTracePoint &point) {
  constexpr double tolerance = 1.0e-10;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return false;
    const int face = *faceRow;
    Eigen::RowVector3d barycentric;
    if (!face_barycentric_from_uv(vertices, faces, frame, face, uv,
                                  barycentric) ||
        barycentric.minCoeff() < -tolerance ||
        barycentric.maxCoeff() > 1.0 + tolerance) {
      continue;
    }
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(barycentric[corner]) <= tolerance) {
        barycentric[corner] = 0.0;
      } else if (std::abs(barycentric[corner] - 1.0) <= tolerance) {
        barycentric[corner] = 1.0;
      }
    }
    const double sum = barycentric.sum();
    if (!(std::abs(sum) > 1.0e-18)) {
      continue;
    }
    barycentric /= sum;
    point.face = face;
    point.barycentric = barycentric;
    return true;
  }
  return false;
}

bool source_edge_provenance(
    const authority::SourceEdgeTopologyKey &edgeKey,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge);

bool build_planar_phase_frame(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::vector<authority::SourceFaceId> &activeFaces,
    const SourceTopologyRegions &sourceAuthority,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    const SurfaceCellTracingOptions *tracingOptions,
    SurfacePhaseFrontFailure &failure, UniformPhaseFrame &frame) {
  if (vertices.rows() < 3 || faces.rows() < 1 || faces.cols() != 3 ||
      faceAxisX.rows() != faces.rows() || faceAxisY.rows() != faces.rows() ||
      activeFaces.empty()) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::InvalidInput);
    return false;
  }
  for (const authority::SourceFaceId faceId : activeFaces) {
    if (!source_face_row(faceId, faces.rows()).has_value()) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::InvalidInput);
      return false;
    }
  }
  const auto referenceRow = source_face_row(activeFaces.front(), faces.rows());
  if (!referenceRow.has_value()) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::InvalidInput);
    return false;
  }
  const int referenceFace = *referenceRow;
  frame.origin = row3(vertices, faces(referenceFace, 0));
  frame.normal = face_normal(vertices, faces, referenceFace);
  if (!(frame.normal.norm() > 0.0)) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::DegenerateReferenceFrame);
    return false;
  }
  frame.axisU = project_tangent(faceAxisX.row(referenceFace), frame.normal);
  frame.axisV = project_tangent(faceAxisY.row(referenceFace), frame.normal);
  frame.axisV -= frame.axisV.dot(frame.axisU) * frame.axisU;
  if (!(frame.axisU.norm() > 0.0) || !(frame.axisV.norm() > 0.0)) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::DegenerateReferenceFrame);
    return false;
  }
  frame.axisU.normalize();
  frame.axisV.normalize();
  if (cross3(frame.axisU, frame.axisV).dot(frame.normal) < 0.0) {
    frame.axisV *= -1.0;
  }

  std::set<int> activeVertices;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return false;
    const int face = *faceRow;
    for (int corner = 0; corner < 3; ++corner) {
      activeVertices.insert(faces(face, corner));
    }
  }
  double scale = 0.0;
  for (const int vertex : activeVertices) {
    scale = std::max(scale, (row3(vertices, vertex) - frame.origin).norm());
  }
  const double planeTolerance = std::max(1.0e-10, 1.0e-9 * scale);
  for (const int vertex : activeVertices) {
    if (std::abs((row3(vertices, vertex) - frame.origin).dot(frame.normal)) >
        planeTolerance) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::NonPlanarSource, -1, -1, -1, -1, vertex);
      return false;
    }
  }

  SourceChartTransitionGraph canonicalSourceCharts(
      &faces, &sourceAuthority,
      tracingOptions != nullptr ? tracingOptions->hardFeatureEdges
                                : empty_hard_feature_edges());
  if (!canonicalSourceCharts.available()) {
    set_phase_front_failure(
        failure, SurfacePhaseFrontFailureReason::MissingFaceState);
    return false;
  }

  frame.faceBranchRotation.assign(static_cast<std::size_t>(faces.rows()), -1);
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return false;
    const int face = *faceRow;
    const Eigen::RowVector3d normal = face_normal(vertices, faces, face);
    if (normal.dot(frame.normal) < 1.0 - 1.0e-8) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::InconsistentFaceOrientation, -1, -1, face);
      return false;
    }
    int bestBranch = -1;
    double bestAlignment = -std::numeric_limits<double>::infinity();
    for (int branch = 0; branch < 4; ++branch) {
      int family = 0;
      int sign = 1;
      family_sign_from_branch(branch, family, sign);
      const Eigen::RowVector3d direction = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, face, family, sign), normal);
      const double alignment = direction.dot(frame.axisU);
      if (alignment > bestAlignment) {
        bestAlignment = alignment;
        bestBranch = branch;
      }
    }
    if (bestBranch < 0 || bestAlignment < 1.0 - 1.0e-8) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::IncompatibleFaceBranch, -1, -1, face);
      return false;
    }
    int vFamily = 0;
    int vSign = 1;
    family_sign_from_branch(normalized_branch(bestBranch + 1), vFamily, vSign);
    const Eigen::RowVector3d localV = project_tangent(
        axis_for_family(faceAxisX, faceAxisY, face, vFamily, vSign), normal);
    if (localV.dot(frame.axisV) < 1.0 - 1.0e-8) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::IncompatibleSecondaryBranch, -1, -1, face);
      return false;
    }
    frame.faceBranchRotation[static_cast<std::size_t>(face)] = bestBranch;
  }

  const auto incident = edge_faces(faces, activeFaces);
  const auto &matchingIndices = sourceMatchingIndices;
  // A prescribed raw field may intentionally omit precomputed matching and
  // transition containers. Treat empty containers as absent metadata so the
  // planar phase front can prove an exact physical zero-turn transport. Once
  // any authoritative transition metadata is present, keep the strict
  // fail-closed lookup and reciprocal validation below.
  const bool hasEdgeTransitions =
      edgeTransitions != nullptr && !edgeTransitions->empty();
  const bool hasEdgeMatching =
      edgeMatching != nullptr && edgeMatching->size() > 0;
  const bool hasEdgeEffort = edgeEffort != nullptr && edgeEffort->size() > 0;
  const auto *effectiveTransitions =
      hasEdgeTransitions ? edgeTransitions : nullptr;
  const auto *effectiveMatching = hasEdgeMatching ? edgeMatching : nullptr;
  const auto *effectiveEffort = hasEdgeEffort ? edgeEffort : nullptr;
  const EdgeTransitionLookup transitionLookup =
      authoritative_edge_transition_lookup(
          tracingOptions != nullptr ? tracingOptions->fieldTransportAtlas
                                    : nullptr,
          effectiveTransitions, source_vertex_extent(faces));
  if (transitionLookup.duplicate) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::DuplicateTransitionMetadata);
    return false;
  }

  for (const auto &[key, pair] : incident) {
    if (pair[0] < 0 || pair[1] < 0) {
      continue;
    }
    const int first = pair[0];
    const int second = pair[1];
    for (int globalBranch = 0; globalBranch < 2; ++globalBranch) {
      const int sourceBranch = normalized_branch(
          frame.faceBranchRotation[static_cast<std::size_t>(first)] +
          globalBranch);
      int sourceFamily = 0;
      int sourceSign = 1;
      family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
      const Eigen::RowVector3d sourceDirection = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, first, sourceFamily,
                          sourceSign),
          face_normal(vertices, faces, first));
      const BranchTransitionResult forward = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, key, first, second, sourceFamily, sourceSign,
          sourceDirection, effectiveMatching, effectiveEffort,
          effectiveTransitions);
      const int expectedTargetBranch = normalized_branch(
          frame.faceBranchRotation[static_cast<std::size_t>(second)] +
          globalBranch);
      if (!forward.valid ||
          branch_from_family_sign(forward.family, forward.sign) !=
              expectedTargetBranch) {
        int sourceEdge = -1;
        source_edge_provenance(key, sourceEdgeFaces, sourceMatchingIndices,
                               transitionLookup, effectiveTransitions,
                               sourceEdge);
        const auto reason =
            tracingOptions != nullptr &&
                    !source_faces_compatible(*tracingOptions, first, second)
                ? SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport
                : SurfacePhaseFrontFailureReason::InvalidOrdinaryTransition;
        set_phase_front_failure(failure, reason, -1, -1, first, second, -1, sourceEdge);
        return false;
      }

      int targetFamily = 0;
      int targetSign = 1;
      family_sign_from_branch(expectedTargetBranch, targetFamily, targetSign);
      const Eigen::RowVector3d targetDirection = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, second, targetFamily,
                          targetSign),
          face_normal(vertices, faces, second));
      const BranchTransitionResult reverse = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, key, second, first, targetFamily, targetSign,
          targetDirection, effectiveMatching, effectiveEffort,
          effectiveTransitions);
      if (!reverse.valid ||
          branch_from_family_sign(reverse.family, reverse.sign) !=
              sourceBranch ||
          normalized_branch(forward.matching + reverse.matching) != 0) {
        int sourceEdge = -1;
        source_edge_provenance(key, sourceEdgeFaces, sourceMatchingIndices,
                               transitionLookup, effectiveTransitions,
                               sourceEdge);
        const auto reason =
            tracingOptions != nullptr &&
                    !source_faces_compatible(*tracingOptions, first, second)
                ? SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport
                : SurfacePhaseFrontFailureReason::NonReciprocalOrdinaryTransition;
        set_phase_front_failure(failure, reason, -1, -1, first, second, -1, sourceEdge);
        return false;
      }
    }
  }

  frame.faceChart.assign(static_cast<std::size_t>(faces.rows()), std::nullopt);
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return false;
    const int face = *faceRow;
    const auto canonicalChart = canonicalSourceCharts.chart(face);
    if (!canonicalChart.has_value()) {
      set_phase_front_failure(
          failure, SurfacePhaseFrontFailureReason::MissingFaceState,
          -1, -1, face);
      return false;
    }
    frame.faceChart[static_cast<std::size_t>(face)] =
        canonicalChart->chart;
  }

  frame.minU = frame.minV = std::numeric_limits<double>::infinity();
  frame.maxU = frame.maxV = -std::numeric_limits<double>::infinity();
  for (const int vertex : activeVertices) {
    const Eigen::Vector2d uv = phase_uv(frame, row3(vertices, vertex));
    frame.minU = std::min(frame.minU, uv.x());
    frame.maxU = std::max(frame.maxU, uv.x());
    frame.minV = std::min(frame.minV, uv.y());
    frame.maxV = std::max(frame.maxV, uv.y());
  }
  const double width = frame.maxU - frame.minU;
  const double height = frame.maxV - frame.minV;
  if (!(width > planeTolerance) || !(height > planeTolerance)) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::NonRectangularDomain);
    return false;
  }

  double projectedArea = 0.0;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return false;
    const int face = *faceRow;
    const Eigen::Vector2d a =
        phase_uv(frame, row3(vertices, faces(face, 0)));
    const Eigen::Vector2d b =
        phase_uv(frame, row3(vertices, faces(face, 1)));
    const Eigen::Vector2d c =
        phase_uv(frame, row3(vertices, faces(face, 2)));
    projectedArea += 0.5 * std::abs((b - a).x() * (c - a).y() -
                                    (b - a).y() * (c - a).x());
  }
  if (std::abs(projectedArea - width * height) >
      1.0e-8 * std::max(1.0, width * height)) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::NonRectangularDomain);
    return false;
  }

  const double boundaryTolerance = 1.0e-8 * std::max(width, height);
  for (const auto &[key, pair] : incident) {
    if (pair[1] >= 0) {
      continue;
    }
    const int face = pair[0];
    int localEdge = -1;
    for (int edge = 0; edge < 3; ++edge) {
      if (local_edge_key(faces, face, edge) == key) {
        localEdge = edge;
        break;
      }
    }
    if (localEdge < 0) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::NonRectangularDomain, -1, -1, face);
      return false;
    }
    const Eigen::Vector2d a = phase_uv(
        frame, row3(vertices, faces(face, (localEdge + 1) % 3)));
    const Eigen::Vector2d b = phase_uv(
        frame, row3(vertices, faces(face, (localEdge + 2) % 3)));
    const bool onU =
        (std::abs(a.x() - frame.minU) <= boundaryTolerance &&
         std::abs(b.x() - frame.minU) <= boundaryTolerance) ||
        (std::abs(a.x() - frame.maxU) <= boundaryTolerance &&
         std::abs(b.x() - frame.maxU) <= boundaryTolerance);
    const bool onV =
        (std::abs(a.y() - frame.minV) <= boundaryTolerance &&
         std::abs(b.y() - frame.minV) <= boundaryTolerance) ||
        (std::abs(a.y() - frame.maxV) <= boundaryTolerance &&
         std::abs(b.y() - frame.maxV) <= boundaryTolerance);
    if (!onU && !onV) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::NonRectangularDomain, -1, -1, face);
      return false;
    }
  }
  return true;
}

enum class OrderedVertexFanStatus : int {
  Found = 0,
  Disconnected = 1,
  NonManifold = 2,
  Ambiguous = 3,
};

struct OrderedVertexFanResult {
  OrderedVertexFanStatus status = OrderedVertexFanStatus::Disconnected;
  std::vector<VertexPathStep> steps;
};

int shared_transition_vertex(const Eigen::MatrixXi &faces,
                             const SurfaceTraceSegment &previous,
                             const SurfaceTraceSegment &current) {
  constexpr double tolerance = 1.0e-10;
  int previousVertex = -1;
  int currentVertex = -1;
  for (int corner = 0; corner < 3; ++corner) {
    if (previous.endBarycentric[corner] >= 1.0 - tolerance) {
      if (previousVertex >= 0) {
        return -1;
      }
      previousVertex = faces(previous.face, corner);
    }
    if (current.startBarycentric[corner] >= 1.0 - tolerance) {
      if (currentVertex >= 0) {
        return -1;
      }
      currentVertex = faces(current.face, corner);
    }
  }
  return previousVertex >= 0 && previousVertex == currentVertex
             ? previousVertex
             : -1;
}

int directed_face_side(const Eigen::MatrixXd &vertices,
                       const Eigen::MatrixXi &faces, const int face,
                       const int sourceVertex,
                       const Eigen::RowVector3d &direction,
                       const Eigen::RowVector3d &normal,
                       const double tolerance) {
  bool positive = false;
  bool negative = false;
  const Eigen::RowVector3d origin = row3(vertices, sourceVertex);
  for (int corner = 0; corner < 3; ++corner) {
    const int vertex = faces(face, corner);
    if (vertex == sourceVertex) {
      continue;
    }
    const double side = normal.dot(cross3(direction, row3(vertices, vertex) - origin));
    positive = positive || side > tolerance;
    negative = negative || side < -tolerance;
  }
  if (positive && negative) {
    return 2;
  }
  if (positive) {
    return 1;
  }
  if (negative) {
    return -1;
  }
  return 0;
}

OrderedVertexFanResult ordered_vertex_fan_path(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces,
    const int sourceVertex, const int sourceFace, const int targetFace,
    const Eigen::RowVector3d &segmentDirection,
    const Eigen::RowVector3d &sourceNormal) {
  OrderedVertexFanResult result;
  if (sourceVertex < 0 || sourceVertex >= vertices.rows() ||
      sourceFace < 0 || sourceFace >= faces.rows() || targetFace < 0 ||
      targetFace >= faces.rows() || sourceFace == targetFace ||
      segmentDirection.squaredNorm() == 0.0 ||
      sourceNormal.squaredNorm() == 0.0) {
    return result;
  }
  const auto adjacency = vertex_face_adjacency(sourceVertex, edgeFaces);
  const auto sourceFound = adjacency.find(sourceFace);
  const auto targetFound = adjacency.find(targetFace);
  if (sourceFound == adjacency.end() || targetFound == adjacency.end()) {
    return result;
  }
  for (const auto &[face, neighbors] : adjacency) {
    (void)face;
    std::set<std::pair<int, std::optional<authority::SourceEdgeTopologyKey>>> unique;
    for (const VertexPathStep &step : neighbors) {
      unique.emplace(step.face, step.edgeKey);
    }
    if (unique.size() != neighbors.size() || neighbors.size() > 2U) {
      result.status = OrderedVertexFanStatus::NonManifold;
      return result;
    }
  }

  std::vector<std::vector<VertexPathStep>> candidates;
  for (const VertexPathStep &first : sourceFound->second) {
    std::vector<VertexPathStep> path;
    std::set<int> visited{sourceFace};
    int previous = sourceFace;
    VertexPathStep current = first;
    bool valid = true;
    while (true) {
      if (!visited.insert(current.face).second) {
        valid = false;
        break;
      }
      path.push_back(current);
      if (current.face == targetFace) {
        break;
      }
      const auto found = adjacency.find(current.face);
      if (found == adjacency.end()) {
        valid = false;
        break;
      }
      std::vector<VertexPathStep> forward;
      for (const VertexPathStep &candidate : found->second) {
        if (candidate.face != previous) {
          forward.push_back(candidate);
        }
      }
      if (forward.size() != 1U) {
        valid = false;
        break;
      }
      previous = current.face;
      current = forward.front();
    }
    if (valid && !path.empty() && path.back().face == targetFace) {
      candidates.push_back(std::move(path));
    }
  }
  if (candidates.empty()) {
    return result;
  }

  const double scale = std::max(1.0, segmentDirection.norm());
  const double tolerance = 1.0e-12 * scale;
  const int sourceSide = directed_face_side(
      vertices, faces, sourceFace, sourceVertex, segmentDirection,
      sourceNormal, tolerance);
  const int targetSide = directed_face_side(
      vertices, faces, targetFace, sourceVertex, segmentDirection,
      sourceNormal, tolerance);
  if (sourceSide == 2 || targetSide == 2 || sourceSide == 0 ||
      targetSide == 0 || sourceSide != targetSide) {
    result.status = OrderedVertexFanStatus::Ambiguous;
    return result;
  }

  std::vector<std::vector<VertexPathStep>> sideCompatible;
  for (const auto &path : candidates) {
    bool compatible = true;
    int face = sourceFace;
    if (directed_face_side(vertices, faces, face, sourceVertex,
                           segmentDirection, sourceNormal, tolerance) !=
        sourceSide) {
      compatible = false;
    }
    for (const VertexPathStep &step : path) {
      const int side = directed_face_side(vertices, faces, step.face,
                                          sourceVertex, segmentDirection,
                                          sourceNormal, tolerance);
      if (side == 2 || (side != 0 && side != sourceSide)) {
        compatible = false;
        break;
      }
      face = step.face;
    }
    if (compatible && face == targetFace) {
      sideCompatible.push_back(path);
    }
  }
  if (sideCompatible.size() != 1U) {
    result.status = sideCompatible.empty() ? OrderedVertexFanStatus::Disconnected
                                           : OrderedVertexFanStatus::Ambiguous;
    return result;
  }
  result.status = OrderedVertexFanStatus::Found;
  result.steps = std::move(sideCompatible.front());
  return result;
}

bool source_edge_provenance(
    const authority::SourceEdgeTopologyKey &edgeKey,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge) {
  sourceEdge = -1;
  const auto incidence = sourceEdgeFaces.find(edgeKey);
  const auto compactIndex = sourceMatchingIndices.find(edgeKey);
  if (incidence == sourceEdgeFaces.end() || incidence->second[0] < 0 ||
      incidence->second[1] < 0 ||
      compactIndex == sourceMatchingIndices.end() ||
      compactIndex->second < 0) {
    return false;
  }
  if (edgeTransitions != nullptr) {
    const auto found = transitionLookup.byEdge.find(edgeKey);
    if (found == transitionLookup.byEdge.end() || found->second.sourceEdge < 0 ||
        !((found->second.sourceVertex0 == edgeKey.first().index() &&
           found->second.sourceVertex1 == edgeKey.second().index()) ||
          (found->second.sourceVertex0 == edgeKey.second().index() &&
           found->second.sourceVertex1 == edgeKey.first().index())) ||
        !transition_faces_match(found->second, incidence->second[0],
                                incidence->second[1])) {
      return false;
    }
  }
  sourceEdge = compactIndex->second;
  return true;
}

bool segment_on_source(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const UniformPhaseFrame &frame, const std::vector<authority::SourceFaceId> &activeFaces,
    const Eigen::Vector2d &start,
    const Eigen::Vector2d &end, const int globalBranch,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    const SurfaceCellTracingOptions &options, const int cellId,
    const int sideId, SurfacePhaseFrontFailure &failure,
    std::vector<SurfaceTraceSegment> &segments) {
  struct Interval {
    double begin = 0.0;
    double end = 0.0;
    int face = -1;
  };
  std::vector<double> breaks{0.0, 1.0};
  std::vector<Interval> intervals;
  constexpr double tolerance = 1.0e-12;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return false;
    const int face = *faceRow;
    Eigen::RowVector3d baryStart;
    Eigen::RowVector3d baryEnd;
    if (!face_barycentric_from_uv(vertices, faces, frame, face, start,
                                  baryStart) ||
        !face_barycentric_from_uv(vertices, faces, frame, face, end,
                                  baryEnd)) {
      continue;
    }
    double low = 0.0;
    double high = 1.0;
    for (int corner = 0; corner < 3; ++corner) {
      const double value = baryStart[corner];
      const double slope = baryEnd[corner] - value;
      if (std::abs(slope) <= tolerance) {
        if (value < -tolerance) {
          low = 1.0;
          high = 0.0;
          break;
        }
        continue;
      }
      const double root = -value / slope;
      if (slope > 0.0) {
        low = std::max(low, root);
      } else {
        high = std::min(high, root);
      }
    }
    low = std::clamp(low, 0.0, 1.0);
    high = std::clamp(high, 0.0, 1.0);
    if (high - low > tolerance) {
      intervals.push_back({low, high, face});
      breaks.push_back(low);
      breaks.push_back(high);
    }
  }
  std::sort(breaks.begin(), breaks.end());
  breaks.erase(std::unique(breaks.begin(), breaks.end(), [](double a, double b) {
                 return std::abs(a - b) <= 1.0e-11;
               }),
               breaks.end());
  segments.clear();
  for (std::size_t index = 0; index + 1U < breaks.size(); ++index) {
    const double low = breaks[index];
    const double high = breaks[index + 1U];
    if (high - low <= tolerance) {
      continue;
    }
    const double middle = 0.5 * (low + high);
    int selectedFace = -1;
    for (const Interval &interval : intervals) {
      if (middle >= interval.begin - tolerance &&
          middle <= interval.end + tolerance &&
          (selectedFace < 0 || interval.face < selectedFace)) {
        selectedFace = interval.face;
      }
    }
    if (selectedFace < 0) {
      set_phase_front_failure(failure,
                              SurfacePhaseFrontFailureReason::MissingSegmentCoverage,
                              cellId, sideId);
      return false;
    }
    if (selectedFace >= static_cast<int>(frame.faceBranchRotation.size()) ||
        frame.faceBranchRotation[static_cast<std::size_t>(selectedFace)] < 0 ||
        selectedFace >= static_cast<int>(frame.faceChart.size()) ||
        !frame.faceChart[static_cast<std::size_t>(selectedFace)].has_value()) {
      set_phase_front_failure(failure,
                              SurfacePhaseFrontFailureReason::MissingFaceState,
                              cellId, sideId, selectedFace);
      return false;
    }
    const Eigen::Vector2d uv0 = start + low * (end - start);
    const Eigen::Vector2d uv1 = start + high * (end - start);
    Eigen::RowVector3d bary0;
    Eigen::RowVector3d bary1;
    if (!face_barycentric_from_uv(vertices, faces, frame, selectedFace, uv0,
                                  bary0) ||
        !face_barycentric_from_uv(vertices, faces, frame, selectedFace, uv1,
                                  bary1)) {
      set_phase_front_failure(failure,
                              SurfacePhaseFrontFailureReason::PointProjectionFailure,
                              cellId, sideId, selectedFace);
      return false;
    }
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(bary0[corner]) <= 1.0e-10) {
        bary0[corner] = 0.0;
      }
      if (std::abs(bary1[corner]) <= 1.0e-10) {
        bary1[corner] = 0.0;
      }
    }
    bary0 /= bary0.sum();
    bary1 /= bary1.sum();

    const int localBranch = normalized_branch(
        frame.faceBranchRotation[static_cast<std::size_t>(selectedFace)] +
        globalBranch);
    int family = 0;
    int sign = 1;
    family_sign_from_branch(localBranch, family, sign);
    if (!segments.empty() && segments.back().face == selectedFace &&
        segments.back().family == family && segments.back().sign == sign &&
        (segments.back().endBarycentric - bary0).norm() <= 1.0e-10) {
      segments.back().endBarycentric = bary1;
      continue;
    }
    SurfaceTraceSegment segment;
    segment.face = selectedFace;
    segment.startBarycentric = bary0;
    segment.endBarycentric = bary1;
    segment.family = family;
    segment.sign = sign;
    segment.sourceChart =
        frame.faceChart[static_cast<std::size_t>(selectedFace)];
    segments.push_back(std::move(segment));
  }
  if (segments.empty()) {
    set_phase_front_failure(failure,
                            SurfacePhaseFrontFailureReason::MissingSegmentCoverage,
                            cellId, sideId);
    return false;
  }

  const auto incident = edge_faces(faces, activeFaces);
  const auto &matchingIndices = sourceMatchingIndices;
  const bool hasEdgeTransitions =
      edgeTransitions != nullptr && !edgeTransitions->empty();
  const bool hasEdgeMatching = edgeMatching != nullptr && edgeMatching->size() > 0;
  const bool hasEdgeEffort = edgeEffort != nullptr && edgeEffort->size() > 0;
  const auto *effectiveTransitions = hasEdgeTransitions ? edgeTransitions : nullptr;
  const auto *effectiveMatching = hasEdgeMatching ? edgeMatching : nullptr;
  const auto *effectiveEffort = hasEdgeEffort ? edgeEffort : nullptr;
  const EdgeTransitionLookup transitionLookup =
      authoritative_edge_transition_lookup(
          options.fieldTransportAtlas, effectiveTransitions,
          source_vertex_extent(faces));
  if (transitionLookup.duplicate) {
    set_phase_front_failure(
        failure, SurfacePhaseFrontFailureReason::DuplicateTransitionMetadata,
        cellId, sideId);
    return false;
  }
  const Eigen::RowVector3d segmentDirection =
      (end.x() - start.x()) * frame.axisU +
      (end.y() - start.y()) * frame.axisV;
  for (std::size_t index = 1; index < segments.size(); ++index) {
    SurfaceTraceSegment &previous = segments[index - 1U];
    SurfaceTraceSegment &current = segments[index];
    std::vector<VertexPathStep> route;
    std::optional<authority::SourceEdgeTopologyKey> sharedKey;
    int previousEdge = -1;
    int currentEdge = -1;
    for (int firstEdge = 0; firstEdge < 3 && previousEdge < 0; ++firstEdge) {
      const authority::SourceEdgeTopologyKey firstKey = local_edge_key(faces, previous.face, firstEdge);
      for (int secondEdge = 0; secondEdge < 3; ++secondEdge) {
        if (firstKey == local_edge_key(faces, current.face, secondEdge)) {
          sharedKey = firstKey;
          previousEdge = firstEdge;
          currentEdge = secondEdge;
          route.push_back({current.face, *sharedKey});
          break;
        }
      }
    }

    int sourceVertex = -1;
    if (route.empty()) {
      sourceVertex = shared_transition_vertex(faces, previous, current);
      if (sourceVertex < 0) {
        set_phase_front_failure(
            failure,
            SurfacePhaseFrontFailureReason::DisconnectedSegmentAttachment,
            cellId, sideId, previous.face, current.face);
        return false;
      }
      const OrderedVertexFanResult fan = ordered_vertex_fan_path(
          vertices, faces, incident, sourceVertex, previous.face, current.face,
          segmentDirection, frame.normal);
      if (fan.status != OrderedVertexFanStatus::Found) {
        const auto reason =
            fan.status == OrderedVertexFanStatus::NonManifold
                ? SurfacePhaseFrontFailureReason::NonManifoldVertexFan
                : fan.status == OrderedVertexFanStatus::Ambiguous
                      ? SurfacePhaseFrontFailureReason::AmbiguousVertexFan
                      : SurfacePhaseFrontFailureReason::DisconnectedSegmentAttachment;
        set_phase_front_failure(failure, reason, cellId, sideId, previous.face,
                                current.face, sourceVertex);
        return false;
      }
      route = fan.steps;
      if (route.empty() || !route.front().edgeKey.has_value() ||
          !route.back().edgeKey.has_value()) {
        set_phase_front_failure(
            failure, SurfacePhaseFrontFailureReason::DisconnectedSegmentAttachment,
            cellId, sideId, previous.face, current.face, sourceVertex);
        return false;
      }
      previousEdge = local_edge_for_key(faces, previous.face, *route.front().edgeKey);
      currentEdge = local_edge_for_key(faces, current.face, *route.back().edgeKey);
      if (previousEdge < 0 || currentEdge < 0) {
        set_phase_front_failure(
            failure,
            SurfacePhaseFrontFailureReason::DisconnectedSegmentAttachment,
            cellId, sideId, previous.face, current.face, sourceVertex);
        return false;
      }
    }

    int transitFace = previous.face;
    int transitFamily = previous.family;
    int transitSign = previous.sign;
    Eigen::RowVector3d transitDirection = project_tangent(
        axis_for_family(faceAxisX, faceAxisY, transitFace, transitFamily,
                        transitSign),
        face_normal(vertices, faces, transitFace));
    double totalEffort = 0.0;
    std::vector<int> sourceEdges;
    std::vector<authority::TransitionStep> observedSteps;
    sourceEdges.reserve(route.size());
    observedSteps.reserve(route.size());
    for (const VertexPathStep &step : route) {
      if (!step.edgeKey.has_value()) {
        set_phase_front_failure(
            failure, SurfacePhaseFrontFailureReason::MissingTransitionProvenance,
            cellId, sideId, transitFace, step.face, sourceVertex);
        return false;
      }
      const bool crossesIsolationSheet =
          !source_faces_compatible(options, transitFace, step.face);
      if (!source_faces_share_component(options, transitFace, step.face) ||
          options.hardFeatureEdges.count(*step.edgeKey) != 0 ||
          (options.reliefBarriersEmbedded &&
           options.reliefBarrierEdges.count(*step.edgeKey) != 0)) {
        set_phase_front_failure(
            failure,
            sourceVertex >= 0
                ? SurfacePhaseFrontFailureReason::InvalidVertexFanTransition
                : SurfacePhaseFrontFailureReason::InvalidOrdinaryTransition,
            cellId, sideId, transitFace, step.face, sourceVertex);
        return false;
      }
      const BranchTransitionResult transition = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, *step.edgeKey, transitFace, step.face,
          transitFamily, transitSign, transitDirection, effectiveMatching,
          effectiveEffort, effectiveTransitions);
      if (!transition.valid) {
        set_phase_front_failure(
            failure,
            crossesIsolationSheet
                ? SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport
                : (sourceVertex >= 0
                       ? SurfacePhaseFrontFailureReason::InvalidVertexFanTransition
                       : SurfacePhaseFrontFailureReason::InvalidOrdinaryTransition),
            cellId, sideId, transitFace, step.face, sourceVertex);
        return false;
      }
      int sourceEdge = -1;
      if (!source_edge_provenance(
              *step.edgeKey, sourceEdgeFaces, sourceMatchingIndices,
              transitionLookup, effectiveTransitions, sourceEdge)) {
        set_phase_front_failure(
            failure,
            crossesIsolationSheet
                ? SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport
                : SurfacePhaseFrontFailureReason::MissingTransitionProvenance,
            cellId, sideId, transitFace, step.face, sourceVertex);
        return false;
      }
      const auto rejectStepAuthority = [&]() {
        set_phase_front_failure(
            failure,
            crossesIsolationSheet
                ? SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport
                : SurfacePhaseFrontFailureReason::MissingTransitionProvenance,
            cellId, sideId, transitFace, step.face, sourceVertex);
        return false;
      };
      const authority::SourceEdgeTopologyKey &topology = *step.edgeKey;
      const auto interiorTransition =
          directional::authority::InteriorTransitionId::from_index(
              sourceEdge, sourceMatchingIndices.size());
      if (!interiorTransition) {
        return rejectStepAuthority();
      }
      const auto typedStep = authority::TransitionStep::interior(
          topology,
          std::optional<authority::InteriorTransitionId>{
              interiorTransition.value()},
          authority::GridAutomorphism{
              authority::QuarterTurn::from_integer(transition.matching),
              authority::LatticeTranslation{0, 0}},
          authority::Orientation::Forward);
      if (!typedStep) {
        return rejectStepAuthority();
      }
      sourceEdges.push_back(sourceEdge);
      observedSteps.push_back(typedStep.value());
      totalEffort += std::abs(transition.effort);
      transitFace = step.face;
      transitFamily = transition.family;
      transitSign = transition.sign;
      transitDirection = transition.direction;
    }
    if (transitFace != current.face || transitFamily != current.family ||
        transitSign != current.sign) {
      set_phase_front_failure(
          failure,
          sourceVertex >= 0
              ? SurfacePhaseFrontFailureReason::VertexFanBranchMismatch
              : SurfacePhaseFrontFailureReason::InvalidOrdinaryTransition,
          cellId, sideId, previous.face, current.face, sourceVertex,
          sourceEdges.empty() ? -1 : sourceEdges.front(),
          sourceEdges.empty() ? -1 : sourceEdges.back());
      return false;
    }
    const authority::CanonicalRoute typedRoute =
        authority::CanonicalRoute::from_observed_steps(std::move(observedSteps));
    authority::GridAutomorphism routeTransport =
        authority::GridAutomorphism::identity();
    for (const authority::TransitionStep &step : typedRoute.oriented_steps()) {
      routeTransport = compose(step.transport(), routeTransport);
    }
    previous.exitEdge = previousEdge;
    current.entryEdge = currentEdge;
    current.matching = static_cast<int>(routeTransport.rotation.value());
    current.matchingEffort = totalEffort;
    current.entryRoute = typedRoute;
  }
  return true;
}


std::array<Eigen::RowVector3d, 4> phase_front_corner_positions(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfacePhaseFrontCell &cell) {
  std::array<Eigen::RowVector3d, 4> positions;
  for (int corner = 0; corner < 4; ++corner) {
    positions[static_cast<std::size_t>(corner)] = point_position(
        vertices, faces, cell.corners[static_cast<std::size_t>(corner)]);
  }
  return positions;
}

Eigen::RowVector3d phase_front_loop_normal(
    const std::array<Eigen::RowVector3d, 4> &positions) {
  Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 4; ++corner) {
    normal += cross3(positions[static_cast<std::size_t>(corner)],
                     positions[static_cast<std::size_t>((corner + 1) % 4)]);
  }
  return normal;
}

void reverse_phase_front_cell_cycle(SurfacePhaseFrontCell &cell) {
  const SurfacePhaseFrontCell original = cell;
  constexpr std::array<int, 4> reverseCorners{0, 3, 2, 1};
  constexpr std::array<int, 4> reversePaths{3, 2, 1, 0};
  for (int corner = 0; corner < 4; ++corner) {
    cell.corners[static_cast<std::size_t>(corner)] =
        original.corners[static_cast<std::size_t>(reverseCorners[corner])];
    cell.lattice[static_cast<std::size_t>(corner)] =
        original.lattice[static_cast<std::size_t>(reverseCorners[corner])];
    cell.boundaryPaths[static_cast<std::size_t>(corner)] = reverse_trace_path(
        original.boundaryPaths[static_cast<std::size_t>(reversePaths[corner])]);
  }
}

std::size_t source_label_authority_extent(const std::vector<int> &labels) {
  if (labels.empty()) {
    return 1U;
  }
  int maximum = -1;
  for (const int label : labels) {
    if (label < 0) return 0U;
    maximum = std::max(maximum, label);
  }
  return maximum >= 0 ? static_cast<std::size_t>(maximum) + 1U : 0U;
}

bool phase_front_cell_matches_region(
    const SurfacePhaseFrontCell &cell,
    const SourceTopologyRegions &sourceAuthority,
    const SurfaceTopologyRegion &region) {
  const auto consume_face = [&](const int face) {
    const auto row = authority::SourceFaceId::from_index(
        face, sourceAuthority.face_count());
    return row.has_value() &&
           sourceAuthority.region_for_row(row.value()) == region.id() &&
           sourceAuthority.component_for_row(row.value()) ==
               region.component();
  };
  for (const SurfaceTracePoint &corner : cell.corners) {
    if (!consume_face(corner.face)) return false;
  }
  for (const auto &path : cell.boundaryPaths) {
    if (path.empty()) return false;
    for (const SurfaceTraceSegment &segment : path) {
      if (!consume_face(segment.face)) return false;
    }
  }
  return cell.sourceTopologyRegion == region.id();
}

SurfacePhaseFrontFailureReason assign_open_front_boundary_authority(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellTracingOptions &options,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const std::vector<SurfaceTraceSegment> &path, SurfaceFrontEdge &edge) {
  if (faces.cols() != 3 || path.empty() || !edge.route.empty()) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  const auto &incident = sourceEdgeFaces;
  const auto &sourceEdgeIndices = sourceMatchingIndices;
  const RailIntervalBuildResult railBuild =
      rail_interval_refs(options.authoritativeRails, vertices, faces,
                         sourceEdgeFaces, options.fieldAlignedNetwork);
  if (railBuild.status != RailBuildStatus::Valid) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  std::optional<SurfaceFrontBoundaryKind> kind;
  std::set<authority::SourceEdgeTopologyKey> seenTopology;
  std::optional<authority::SourceEdgeTopologyKey> lastTopology;
  std::optional<SurfaceFrontBoundaryKind> runKind;
  std::optional<double> runStartParameter;
  std::optional<double> runEndParameter;
  std::vector<authority::TransitionStep> observedSteps;
  std::optional<authority::HardRailId> railId;
  constexpr double tolerance = 1.0e-9;

  const auto canonical_retained_edge_parameter =
      [&](const int supportedCorner, const int a, const int b,
          const Eigen::RowVector3d &barycentric) -> std::optional<double> {
    if (a == b || supportedCorner < 0 || supportedCorner >= 3) {
      return std::nullopt;
    }
    const int aCorner = (supportedCorner + 1) % 3;
    const int bCorner = (supportedCorner + 2) % 3;
    const double aWeight = barycentric[aCorner];
    const double bWeight = barycentric[bCorner];
    const double totalWeight = aWeight + bWeight;
    if (!std::isfinite(aWeight) || !std::isfinite(bWeight) ||
        !std::isfinite(totalWeight) || std::abs(totalWeight) <= tolerance) {
      return std::nullopt;
    }
    const double highWeight = a < b ? bWeight : aWeight;
    const double parameter = highWeight / totalWeight;
    if (!std::isfinite(parameter) || parameter < -tolerance ||
        parameter > 1.0 + tolerance) {
      return std::nullopt;
    }
    return std::clamp(parameter, 0.0, 1.0);
  };

  const auto publish_retained_edge_run = [&]() -> bool {
    if (!lastTopology.has_value() || !runKind.has_value() ||
        !runStartParameter.has_value() || !runEndParameter.has_value()) {
      return false;
    }
    const double delta = *runEndParameter - *runStartParameter;
    if (!std::isfinite(delta) || std::abs(delta) <= tolerance) {
      return false;
    }
    const authority::Orientation runOrientation =
        delta > 0.0 ? authority::Orientation::Forward
                    : authority::Orientation::Reverse;
    if (*runKind == SurfaceFrontBoundaryKind::GenuineSourceBoundary) {
      observedSteps.push_back(authority::TransitionStep::boundary(
          *lastTopology, authority::GridAutomorphism::identity(),
          runOrientation));
      return true;
    }
    const auto foundIndex = sourceEdgeIndices.find(*lastTopology);
    if (foundIndex == sourceEdgeIndices.end()) {
      return false;
    }
    const auto transition = authority::InteriorTransitionId::from_index(
        foundIndex->second, sourceEdgeIndices.size());
    if (!transition) {
      return false;
    }
    const auto step = authority::TransitionStep::interior(
        *lastTopology, transition.value(),
        authority::GridAutomorphism::identity(), runOrientation);
    if (!step) {
      return false;
    }
    observedSteps.push_back(step.value());
    return true;
  };

  for (const SurfaceTraceSegment &segment : path) {
    if (segment.face < 0 || segment.face >= faces.rows() ||
        !segment.startBarycentric.allFinite() ||
        !segment.endBarycentric.allFinite()) {
      return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
    }
    int supportedCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(segment.startBarycentric[corner]) <= tolerance &&
          std::abs(segment.endBarycentric[corner]) <= tolerance) {
        if (supportedCorner >= 0) {
          return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
        }
        supportedCorner = corner;
      }
    }
    if (supportedCorner < 0) {
      return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
    }
    const int a = faces(segment.face, (supportedCorner + 1) % 3);
    const int b = faces(segment.face, (supportedCorner + 2) % 3);
    const authority::SourceEdgeTopologyKey topology = edge_key(a, b, source_vertex_extent(faces));
    const auto foundIncident = incident.find(topology);
    const auto foundIndex = sourceEdgeIndices.find(topology);
    if (foundIncident == incident.end() || foundIncident->second[0] < 0 ||
        (foundIncident->second[0] != segment.face &&
         foundIncident->second[1] != segment.face)) {
      return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
    }
    SurfaceFrontBoundaryKind segmentKind;
    if (foundIncident->second[1] < 0) {
      if (foundIndex != sourceEdgeIndices.end()) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      segmentKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
    } else if (options.hardFeatureEdges.count(topology) != 0U) {
      if (foundIndex == sourceEdgeIndices.end()) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      const SurfaceCellRailIntervalSelection exactOwner =
          find_rail_interval(railBuild.intervals, segment.face, supportedCorner);
      if (exactOwner.interval == nullptr ||
          (railId.has_value() && railId != exactOwner.interval->railId) ||
          (segment.railId.has_value() &&
           segment.railId != exactOwner.interval->railId)) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      segmentKind = SurfaceFrontBoundaryKind::HardRail;
      railId = exactOwner.interval->railId;
    } else if (options.reliefBarriersEmbedded &&
               options.reliefBarrierEdges.count(topology) != 0U) {
      if (foundIndex == sourceEdgeIndices.end()) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      segmentKind = SurfaceFrontBoundaryKind::EmbeddedReliefCut;
    } else {
      return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
    }
    if (kind.has_value() && *kind != segmentKind) {
      return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
    }
    kind = segmentKind;

    const auto startParameter = canonical_retained_edge_parameter(
        supportedCorner, a, b, segment.startBarycentric);
    const auto endParameter = canonical_retained_edge_parameter(
        supportedCorner, a, b, segment.endBarycentric);
    if (!startParameter.has_value() || !endParameter.has_value()) {
      return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
    }

    if (!lastTopology.has_value() || lastTopology.value() != topology) {
      if (lastTopology.has_value() && !publish_retained_edge_run()) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      if (!seenTopology.insert(topology).second) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      lastTopology = topology;
      runKind = segmentKind;
      runStartParameter = *startParameter;
      runEndParameter = *endParameter;
    } else {
      if (!runKind.has_value() || *runKind != segmentKind ||
          !runEndParameter.has_value() ||
          std::abs(*runEndParameter - *startParameter) > tolerance) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      runEndParameter = *endParameter;
    }

    if (segment.railId.has_value()) {
      if (railId.has_value() && railId != segment.railId) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      railId = segment.railId;
    }
  }

  if (!publish_retained_edge_run()) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  if (!kind.has_value() || observedSteps.empty()) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  const bool expectBoundary =
      *kind == SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  if (std::any_of(observedSteps.begin(), observedSteps.end(),
                  [&](const authority::TransitionStep &step) {
                    return (step.kind() == authority::TransitionStepKind::Boundary) !=
                           expectBoundary;
                  })) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  edge.route =
      authority::CanonicalRoute::from_observed_steps(std::move(observedSteps));
  edge.boundaryKind = *kind;
  edge.railId = railId;
  if (*kind == SurfaceFrontBoundaryKind::EmbeddedReliefCut) {
    return SurfacePhaseFrontFailureReason::UnsupportedEmbeddedReliefCut;
  }
  return SurfacePhaseFrontFailureReason::None;
}

bool orient_and_validate_phase_front_cell(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const UniformPhaseFrame &frame, const double target,
    const SurfaceCellTracingOptions &options, const SurfaceTopologyRegion &region,
    const SourceTopologyRegions &sourceAuthority, SurfacePhaseFrontCell &cell) {
  if (!(target > 0.0) || !std::isfinite(target)) {
    return false;
  }
  for (const SurfaceTracePoint &corner : cell.corners) {
    if (!trace_point_is_valid(corner, faces)) {
      return false;
    }
  }
  const double pointTolerance = std::max(1.0e-12, 1.0e-9 * target);
  auto positions = phase_front_corner_positions(vertices, faces, cell);
  for (int first = 0; first < 4; ++first) {
    for (int second = first + 1; second < 4; ++second) {
      if ((positions[static_cast<std::size_t>(first)] -
           positions[static_cast<std::size_t>(second)])
              .norm() <= pointTolerance) {
        return false;
      }
    }
  }
  if (validate_closed_boundary_paths(vertices, faces, cell.corners,
                                     cell.boundaryPaths,
                                     pointTolerance) !=
      CellRejectionReason::Accepted) {
    return false;
  }
  Eigen::RowVector3d loopNormal = phase_front_loop_normal(positions);
  if (!loopNormal.allFinite() || loopNormal.squaredNorm() <= 1.0e-24) {
    return false;
  }
  if (loopNormal.dot(frame.normal) < 0.0) {
    reverse_phase_front_cell_cycle(cell);
    positions = phase_front_corner_positions(vertices, faces, cell);
    loopNormal = phase_front_loop_normal(positions);
  }
  if (loopNormal.dot(frame.normal) <= 0.0 ||
      classify_quad_loop(positions, target, frame.normal, options) !=
          CellRejectionReason::Accepted ||
      validate_closed_boundary_paths(vertices, faces, cell.corners,
                                     cell.boundaryPaths,
                                     pointTolerance) !=
          CellRejectionReason::Accepted) {
    return false;
  }
  if (!phase_front_cell_matches_region(cell, sourceAuthority, region)) {
    return false;
  }
  cell.orientationValidated = true;
  return true;
}

} // namespace

struct SurfacePhaseFrontBuildState {
  SurfaceCellProducerDisposition disposition =
      SurfaceCellProducerDisposition::NotApplicable;
  bool attempted = false;
  bool succeeded = false;
  int gridU = 0;
  int gridV = 0;
  std::optional<SourceTopologyRegions> sourceTopologyRegions;
  std::vector<SurfaceIsolationSeamTransportCertificate>
      isolationSeamTransportCertificates;
  std::vector<SurfacePeriodicHolonomy> periodicHolonomies;
  std::vector<SurfaceBoundedDiskBoundaryPhase> boundedDiskBoundaryPhases;
  SurfacePhaseFrontFailure failure;
  std::vector<SurfaceFrontEdge> edges;
  std::vector<SurfaceFrontEvent> events;
  std::vector<SurfacePhaseFrontCell> cells;
};

SurfacePhaseFrontResult publish_phase_front_result(
    SurfacePhaseFrontBuildState state) {
  if (state.disposition == SurfaceCellProducerDisposition::NotApplicable) {
    return SurfacePhaseFrontResult::not_applicable();
  }
  if (state.disposition == SurfaceCellProducerDisposition::Rejected) {
    if (state.failure.reason == SurfacePhaseFrontFailureReason::None) {
      state.failure.reason = SurfacePhaseFrontFailureReason::InvalidFinalCellState;
    }
    return SurfacePhaseFrontResult::rejected(std::move(state.failure));
  }
  if (!state.succeeded || state.cells.empty() || state.edges.empty()) {
    if (state.failure.reason == SurfacePhaseFrontFailureReason::None) {
      state.failure.reason = SurfacePhaseFrontFailureReason::InvalidFinalCellState;
    }
    return SurfacePhaseFrontResult::rejected(std::move(state.failure));
  }

  if (!state.sourceTopologyRegions.has_value()) {
    state.failure.reason = SurfacePhaseFrontFailureReason::InvalidTopologyRegion;
    return SurfacePhaseFrontResult::rejected(std::move(state.failure));
  }
  auto product = SurfacePhaseFrontProduct::make(
      state.gridU, state.gridV, std::move(*state.sourceTopologyRegions),
      std::move(state.isolationSeamTransportCertificates),
      std::move(state.periodicHolonomies),
      std::move(state.boundedDiskBoundaryPhases), std::move(state.edges),
      std::move(state.events), std::move(state.cells));
  if (auto *value = std::get_if<SurfacePhaseFrontProduct>(&product)) {
    return SurfacePhaseFrontResult::produced(std::move(*value));
  }
  state.failure.reason = SurfacePhaseFrontFailureReason::InvalidFinalCellState;
  return SurfacePhaseFrontResult::rejected(std::move(state.failure));
}

SurfacePhaseFrontBuildState build_uniform_phase_front_for_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const std::vector<authority::SourceFaceId> &activeFaces,
    const SurfaceTopologyRegion &region,
    const SourceTopologyRegions &sourceAuthority,
    const SurfaceCellTracingOptions &options,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching,
    const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontBuildState result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted) {
    return result;
  }

  // Applicability is decided before authoritative transition metadata is
  // consumed. The bounded uniform producer currently covers planar,
  // rectangular, globally phase-compatible domains without singularities.
  // Unsupported topology is NotApplicable; malformed authoritative metadata
  // on an applicable domain is Rejected and must remain fail-closed.
  if (surface_cell_tracing_detail::tracing_has_singularities(options)) {
    return result;
  }
  UniformPhaseFrame applicabilityFrame;
  SurfacePhaseFrontFailure applicabilityFailure;
  if (!build_planar_phase_frame(vertices, faces, faceAxisX, faceAxisY,
                                activeFaces, sourceAuthority, sourceEdgeFaces,
                                sourceMatchingIndices, nullptr, nullptr,
                                nullptr, &options, applicabilityFailure,
                                applicabilityFrame)) {
    switch (applicabilityFailure.reason) {
    case SurfacePhaseFrontFailureReason::InvalidInput:
    case SurfacePhaseFrontFailureReason::DegenerateReferenceFrame:
    case SurfacePhaseFrontFailureReason::InconsistentFaceOrientation:
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      result.failure = applicabilityFailure;
      break;
    default:
      // Non-planar, non-rectangular, or globally non-uniform phase domains are
      // outside this bounded producer. A separately selected producer may run.
      break;
    }
    return result;
  }

  result.disposition = SurfaceCellProducerDisposition::Rejected;
  UniformPhaseFrame frame;
  if (!build_planar_phase_frame(vertices, faces, faceAxisX, faceAxisY,
                                activeFaces, sourceAuthority, sourceEdgeFaces,
                                sourceMatchingIndices, edgeMatching, edgeEffort,
                                edgeTransitions, &options, result.failure,
                                frame)) {
    return result;
  }
  double target = options.defaultTargetSize;
  if (targetSize.size() > 0 && targetSize.allFinite() &&
      targetSize.minCoeff() > 0.0) {
    target = targetSize.mean();
  }
  if (!(target > 0.0) || !std::isfinite(target)) {
    set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidTargetSize);
    return result;
  }
  const double width = frame.maxU - frame.minU;
  const double height = frame.maxV - frame.minV;
  result.gridU = std::max(1, static_cast<int>(std::llround(width / target)));
  result.gridV = std::max(1, static_cast<int>(std::llround(height / target)));
  const double stepU = width / static_cast<double>(result.gridU);
  const double stepV = height / static_cast<double>(result.gridV);
  if (!(stepU > 0.0) || !(stepV > 0.0)) {
    set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidGridStep);
    return result;
  }

  const int nodeColumns = result.gridU + 1;
  const int nodeRows = result.gridV + 1;
  std::vector<SurfaceTracePoint> points(
      static_cast<std::size_t>(nodeColumns * nodeRows));
  const auto node_index = [nodeColumns](const int u, const int v) {
    return v * nodeColumns + u;
  };
  for (int v = 0; v < nodeRows; ++v) {
    for (int u = 0; u < nodeColumns; ++u) {
      const Eigen::Vector2d uv(frame.minU + stepU * u,
                               frame.minV + stepV * v);
      if (!point_on_source(vertices, faces, frame, activeFaces, uv,
                           points[static_cast<std::size_t>(node_index(u, v))])) {
        set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::PointProjectionFailure);
        return result;
      }
    }
  }

  struct EdgeOwner {
    int edge = -1;
  };
  std::map<std::pair<int, int>, EdgeOwner> openEdges;
  for (int v = 0; v < result.gridV; ++v) {
    for (int u = 0; u < result.gridU; ++u) {
      const std::array<int, 4> nodeIds{
          node_index(u, v), node_index(u + 1, v),
          node_index(u + 1, v + 1), node_index(u, v + 1)};
      const std::array<Eigen::Vector2d, 4> uv{
          Eigen::Vector2d(frame.minU + stepU * u, frame.minV + stepV * v),
          Eigen::Vector2d(frame.minU + stepU * (u + 1),
                          frame.minV + stepV * v),
          Eigen::Vector2d(frame.minU + stepU * (u + 1),
                          frame.minV + stepV * (v + 1)),
          Eigen::Vector2d(frame.minU + stepU * u,
                          frame.minV + stepV * (v + 1))};
      const auto cellId = phase_front_cell_id_from_lattice(
          u, v, result.gridU, result.gridV);
      if (!cellId) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
        return result;
      }
      SurfacePhaseFrontCell cell(region.id(), cellId.value());
      for (int corner = 0; corner < 4; ++corner) {
        cell.corners[static_cast<std::size_t>(corner)] =
            points[static_cast<std::size_t>(nodeIds[corner])];
        LocalLatticeState &state =
            cell.lattice[static_cast<std::size_t>(corner)];
        state.phase = uv[static_cast<std::size_t>(corner)] -
                      Eigen::Vector2d(frame.minU, frame.minV);
        const int sourceFace =
            cell.corners[static_cast<std::size_t>(corner)].face;
        if (sourceFace < 0 ||
            sourceFace >= static_cast<int>(frame.faceBranchRotation.size()) ||
            sourceFace >= static_cast<int>(frame.faceChart.size()) ||
            !frame.faceChart[static_cast<std::size_t>(sourceFace)].has_value()) {
          set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::MissingFaceState, static_cast<int>(cell.id.index()), corner, sourceFace);
          return result;
        }
        state.branchRotation =
            frame.faceBranchRotation[static_cast<std::size_t>(sourceFace)];
        state.sourceChart =
            frame.faceChart[static_cast<std::size_t>(sourceFace)];
      }
      cell.lattice[0].latticeCoordinate = {u, v};
      cell.lattice[1].latticeCoordinate = {u + 1, v};
      cell.lattice[2].latticeCoordinate = {u + 1, v + 1};
      cell.lattice[3].latticeCoordinate = {u, v + 1};
      const std::array<int, 4> globalBranches{0, 1, 2, 3};
      for (int side = 0; side < 4; ++side) {
        if (!segment_on_source(
                vertices, faces, frame, activeFaces, uv[side],
                uv[(side + 1) % 4],
                globalBranches[static_cast<std::size_t>(side)], faceAxisX,
                faceAxisY, sourceEdgeFaces, sourceMatchingIndices,
                edgeMatching, edgeEffort, edgeTransitions, options,
                static_cast<int>(cell.id.index()), side, result.failure,
                cell.boundaryPaths[static_cast<std::size_t>(side)])) {
          return result;
        }
      }
      if (!orient_and_validate_phase_front_cell(
              vertices, faces, frame, std::min(stepU, stepV), options, region,
              sourceAuthority, cell)) {
        set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidCellOrientation, static_cast<int>(cell.id.index()));
        return result;
      }

      for (int side = 0; side < 4; ++side) {
        const auto &path = cell.boundaryPaths[static_cast<std::size_t>(side)];
        SurfaceFrontEdge edge(region.id(), cell.id);
        edge.from = cell.corners[static_cast<std::size_t>(side)];
        edge.to = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
        const authority::LatticeTranslation latticeDelta =
            cell.lattice[static_cast<std::size_t>((side + 1) % 4)]
                .latticeCoordinate -
            cell.lattice[static_cast<std::size_t>(side)].latticeCoordinate;
        if (latticeDelta == authority::LatticeTranslation{1, 0}) {
          edge.family = 0;
          edge.advanceSign = 1;
        } else if (latticeDelta == authority::LatticeTranslation{0, 1}) {
          edge.family = 1;
          edge.advanceSign = 1;
        } else if (latticeDelta == authority::LatticeTranslation{-1, 0}) {
          edge.family = 0;
          edge.advanceSign = -1;
        } else if (latticeDelta == authority::LatticeTranslation{0, -1}) {
          edge.family = 1;
          edge.advanceSign = -1;
        } else {
          set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidLatticeEdge, static_cast<int>(cell.id.index()), side);
          return result;
        }
        edge.fromLattice = cell.lattice[static_cast<std::size_t>(side)];
        edge.toLattice =
            cell.lattice[static_cast<std::size_t>((side + 1) % 4)];
        edge.filledSide = side;
        const int edgeId = static_cast<int>(result.edges.size());
        result.edges.push_back(edge);
        const authority::LatticeTranslation from =
            edge.fromLattice.latticeCoordinate;
        const authority::LatticeTranslation to =
            edge.toLattice.latticeCoordinate;
        const int fromNode = node_index(static_cast<int>(from.x),
                                        static_cast<int>(from.y));
        const int toNode = node_index(static_cast<int>(to.x),
                                      static_cast<int>(to.y));
        const auto key = std::minmax(fromNode, toNode);
        const std::pair<int, int> canonical{key.first, key.second};
        const auto found = openEdges.find(canonical);
        if (found == openEdges.end()) {
          openEdges.emplace(canonical, EdgeOwner{edgeId});
        } else {
          SurfaceFrontEdge &first =
              result.edges[static_cast<std::size_t>(found->second.edge)];
          SurfaceFrontEdge &second =
              result.edges[static_cast<std::size_t>(edgeId)];
          if (first.filledCell == second.filledCell ||
              first.fromLattice.latticeCoordinate !=
                  second.toLattice.latticeCoordinate ||
              first.toLattice.latticeCoordinate !=
                  second.fromLattice.latticeCoordinate ||
              first.family != second.family ||
              first.advanceSign == second.advanceSign ||
              first.sourceTopologyRegion != second.sourceTopologyRegion) {
            set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::FrontOwnershipConflict, static_cast<int>(cell.id.index()), side);
            return result;
          }
          first.oppositeEdge = edgeId;
          second.oppositeEdge = found->second.edge;
          first.unfilledSide = 0;
          second.unfilledSide = 0;
          SurfaceFrontEvent event;
          event.kind = SurfaceFrontEventKind::CompatibleFrontMerge;
          event.firstEdge = found->second.edge;
          event.secondEdge = edgeId;
          result.events.push_back(event);
          openEdges.erase(found);
        }
      }
      result.cells.push_back(std::move(cell));
    }
  }
  const auto cellIndexById = phase_front_cell_storage_index(result.cells);
  if (!cellIndexById) {
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
    return result;
  }
  for (const auto &[key, owner] : openEdges) {
    (void)key;
    SurfaceFrontEdge &edge =
        result.edges[static_cast<std::size_t>(owner.edge)];
    const auto ownerCell = cellIndexById->find(edge.filledCell);
    if (ownerCell == cellIndexById->end() ||
        edge.filledSide < 0 || edge.filledSide >= 4) {
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority,
          static_cast<int>(edge.filledCell.index()), edge.filledSide);
      return result;
    }
    const auto boundaryReason = assign_open_front_boundary_authority(
        vertices, faces, options, sourceEdgeFaces, sourceMatchingIndices,
        result.cells[ownerCell->second]
            .boundaryPaths[static_cast<std::size_t>(edge.filledSide)],
        edge);
    if (boundaryReason != SurfacePhaseFrontFailureReason::None) {
      set_phase_front_failure(result.failure, boundaryReason,
                              static_cast<int>(edge.filledCell.index()),
                              edge.filledSide);
      return result;
    }
    edge.exterior = true;
    edge.unfilledSide = 0;
    SurfaceFrontEvent event;
    event.kind = SurfaceFrontEventKind::BoundaryTermination;
    event.firstEdge = owner.edge;
    result.events.push_back(event);
  }
  for (const SurfacePhaseFrontCell &cell : result.cells) {
    if (!cell.orientationValidated ||
        cell.sourceTopologyRegion != region.id()) {
      set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState, static_cast<int>(cell.id.index()));
      return result;
    }
  }
  for (const SurfaceFrontEdge &edge : result.edges) {
    const bool hasTwin = edge.oppositeEdge >= 0;
    if (cellIndexById->find(edge.filledCell) == cellIndexById->end() || edge.unfilledSide != 0 ||
        hasTwin == edge.exterior ||
        (hasTwin && (edge.oppositeEdge >= static_cast<int>(result.edges.size()) ||
                     result.edges[static_cast<std::size_t>(edge.oppositeEdge)]
                             .oppositeEdge !=
                         static_cast<int>(&edge - result.edges.data())))) {
      set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidFinalEdgeState, -1, static_cast<int>(&edge - result.edges.data()));
      return result;
    }
  }
  result.succeeded =
      !result.cells.empty() &&
      result.cells.size() ==
          static_cast<std::size_t>(result.gridU * result.gridV);
  if (result.succeeded) {
    result.disposition = SurfaceCellProducerDisposition::Produced;
  } else {
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidFinalCellState);
  }
  return result;
}

namespace {

struct PeriodicChartTriangle {
  explicit PeriodicChartTriangle(authority::SourceFaceId sourceFaceValue)
      : sourceFace(sourceFaceValue) {}

  authority::SourceFaceId sourceFace;
  std::array<Eigen::Vector2d, 3> uv;
  std::array<int, 3> vertices{{-1, -1, -1}};
};

std::array<int, 3> canonical_face_vertices(const Eigen::MatrixXi &faces,
                                           const int face) {
  std::array<int, 3> key{faces(face, 0), faces(face, 1), faces(face, 2)};
  std::sort(key.begin(), key.end());
  return key;
}

std::vector<int> canonical_cycle(const std::map<int, std::vector<int>> &adjacency) {
  if (adjacency.size() < 3U) {
    return {};
  }
  const int start = adjacency.begin()->first;
  const auto found = adjacency.find(start);
  if (found == adjacency.end() || found->second.size() != 2U) {
    return {};
  }
  const auto walk = [&](const int first) {
    std::vector<int> cycle;
    cycle.reserve(adjacency.size());
    int previous = start;
    int current = first;
    cycle.push_back(start);
    while (current != start && cycle.size() <= adjacency.size()) {
      cycle.push_back(current);
      const auto neighbors = adjacency.find(current);
      if (neighbors == adjacency.end() || neighbors->second.size() != 2U) {
        return std::vector<int>{};
      }
      const int next = neighbors->second[0] == previous
                           ? neighbors->second[1]
                           : neighbors->second[0];
      previous = current;
      current = next;
    }
    if (current != start || cycle.size() != adjacency.size()) {
      return std::vector<int>{};
    }
    return cycle;
  };
  std::vector<int> first = walk(found->second[0]);
  std::vector<int> second = walk(found->second[1]);
  if (first.empty()) return second;
  if (second.empty()) return first;
  return second < first ? second : first;
}

bool face_contains_only(const Eigen::MatrixXi &faces, const int face,
                        const std::set<int> &vertices) {
  for (int corner = 0; corner < 3; ++corner) {
    if (vertices.count(faces(face, corner)) == 0U) {
      return false;
    }
  }
  return true;
}

bool chart_barycentric(const PeriodicChartTriangle &triangle,
                       const Eigen::Vector2d &uv,
                       Eigen::RowVector3d &barycentric) {
  Eigen::Matrix2d matrix;
  matrix.col(0) = triangle.uv[1] - triangle.uv[0];
  matrix.col(1) = triangle.uv[2] - triangle.uv[0];
  const double determinant = matrix.determinant();
  if (!std::isfinite(determinant) || std::abs(determinant) <= 1.0e-18) {
    return false;
  }
  const Eigen::Vector2d local = matrix.inverse() * (uv - triangle.uv[0]);
  if (!local.allFinite()) {
    return false;
  }
  barycentric << 1.0 - local.x() - local.y(), local.x(), local.y();
  return barycentric.allFinite();
}

constexpr double kPeriodicChartCoverageTolerance = 1.0e-10;

bool canonicalize_periodic_chart_barycentric(
    Eigen::RowVector3d &barycentric) {
  if (!barycentric.allFinite()) {
    return false;
  }
  for (int coordinate = 0; coordinate < 3; ++coordinate) {
    if (barycentric[coordinate] < -kPeriodicChartCoverageTolerance ||
        barycentric[coordinate] > 1.0 + kPeriodicChartCoverageTolerance) {
      return false;
    }
    if (std::abs(barycentric[coordinate]) <=
        kPeriodicChartCoverageTolerance) {
      barycentric[coordinate] = 0.0;
    } else if (std::abs(barycentric[coordinate] - 1.0) <=
               kPeriodicChartCoverageTolerance) {
      barycentric[coordinate] = 1.0;
    } else {
      barycentric[coordinate] =
          std::clamp(barycentric[coordinate], 0.0, 1.0);
    }
  }

  int exactVertex = -1;
  for (int coordinate = 0; coordinate < 3; ++coordinate) {
    if (barycentric[coordinate] == 1.0) {
      if (exactVertex >= 0) {
        return false;
      }
      exactVertex = coordinate;
    }
  }
  if (exactVertex >= 0) {
    for (int coordinate = 0; coordinate < 3; ++coordinate) {
      barycentric[coordinate] = coordinate == exactVertex ? 1.0 : 0.0;
    }
    return true;
  }

  const double sum = barycentric.sum();
  if (!std::isfinite(sum) || sum <= 1.0e-18) {
    return false;
  }
  barycentric /= sum;
  for (int coordinate = 0; coordinate < 3; ++coordinate) {
    if (std::abs(barycentric[coordinate]) <=
        kPeriodicChartCoverageTolerance) {
      barycentric[coordinate] = 0.0;
    } else if (std::abs(barycentric[coordinate] - 1.0) <=
               kPeriodicChartCoverageTolerance) {
      for (int other = 0; other < 3; ++other) {
        barycentric[other] = other == coordinate ? 1.0 : 0.0;
      }
      return true;
    }
  }
  const double canonicalSum = barycentric.sum();
  if (!std::isfinite(canonicalSum) || canonicalSum <= 1.0e-18) {
    return false;
  }
  barycentric /= canonicalSum;
  return barycentric.allFinite();
}

bool point_on_periodic_chart(const std::vector<PeriodicChartTriangle> &triangles,
                             const Eigen::Vector2d &uv,
                             const int sourceFaceCount,
                             SurfaceTracePoint &point) {
  constexpr double tolerance = kPeriodicChartCoverageTolerance;
  bool found = false;
  std::array<int, 3> bestKey{
      std::numeric_limits<int>::max(), std::numeric_limits<int>::max(),
      std::numeric_limits<int>::max()};
  Eigen::RowVector3d bestBarycentric = Eigen::RowVector3d::Zero();
  std::optional<authority::SourceFaceId> bestFace;
  for (const PeriodicChartTriangle &triangle : triangles) {
    Eigen::RowVector3d barycentric;
    if (!chart_barycentric(triangle, uv, barycentric) ||
        barycentric.minCoeff() < -tolerance ||
        barycentric.maxCoeff() > 1.0 + tolerance) {
      continue;
    }
    const std::array<int, 3> key = triangle.vertices;
    if (!found || key < bestKey) {
      found = true;
      bestKey = key;
      bestBarycentric = barycentric;
      bestFace = triangle.sourceFace;
    }
  }
  if (!found) {
    return false;
  }
  if (!canonicalize_periodic_chart_barycentric(bestBarycentric)) {
    return false;
  }
  const auto bestFaceRow = source_face_row(*bestFace, sourceFaceCount);
  if (!bestFaceRow.has_value()) return false;
  point.face = *bestFaceRow;
  point.barycentric = bestBarycentric;
  return true;
}

std::vector<SurfaceTraceSegment> periodic_chart_segment(
    const std::vector<PeriodicChartTriangle> &triangles,
    const SourceChartTransitionGraph &sourceCharts,
    const int sourceFaceCount,
    const Eigen::Vector2d &start, const Eigen::Vector2d &end,
    const int family, const int sign,
    const std::map<authority::SourceEdgeTopologyKey, int> &matchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  struct Interval {
    double lo = 0.0;
    double hi = 0.0;
    const PeriodicChartTriangle *triangle = nullptr;
  };
  std::vector<Interval> intervals;
  std::vector<double> breaks{0.0, 1.0};
  constexpr double tolerance = kPeriodicChartCoverageTolerance;
  for (const PeriodicChartTriangle &triangle : triangles) {
    Eigen::RowVector3d b0;
    Eigen::RowVector3d b1;
    if (!chart_barycentric(triangle, start, b0) ||
        !chart_barycentric(triangle, end, b1)) {
      continue;
    }
    double lo = 0.0;
    double hi = 1.0;
    bool valid = true;
    for (int coordinate = 0; coordinate < 3; ++coordinate) {
      const double a = b0[coordinate];
      const double d = b1[coordinate] - b0[coordinate];
      if (std::abs(d) <= 1.0e-15) {
        if (a < -tolerance) valid = false;
        continue;
      }

      // Coverage may extend by tolerance so a segment exactly on a source
      // triangle boundary remains owned.  Emitted geometry must not inherit
      // that expansion: exact zero-barycentric crossings are the canonical
      // chart breakpoints.
      const double coverageBound = (-tolerance - a) / d;
      if (d > 0.0) {
        lo = std::max(lo, coverageBound);
      } else {
        hi = std::min(hi, coverageBound);
      }
      double exactBound = -a / d;
      if (exactBound >= -tolerance && exactBound <= 1.0 + tolerance) {
        exactBound = std::clamp(exactBound, 0.0, 1.0);
        breaks.push_back(exactBound);
      }
    }
    lo = std::clamp(lo, 0.0, 1.0);
    hi = std::clamp(hi, 0.0, 1.0);
    if (valid && hi - lo > 1.0e-12) {
      intervals.push_back({lo, hi, &triangle});
    }
  }
  std::sort(breaks.begin(), breaks.end());
  breaks.erase(std::unique(breaks.begin(), breaks.end(), [](double a, double b) {
                 return std::abs(a - b) <= 1.0e-10;
               }),
               breaks.end());
  std::vector<SurfaceTraceSegment> path;
  for (std::size_t index = 0; index + 1U < breaks.size(); ++index) {
    const double lo = breaks[index];
    const double hi = breaks[index + 1U];
    if (hi - lo <= 1.0e-12) continue;
    const double mid = 0.5 * (lo + hi);
    const PeriodicChartTriangle *selected = nullptr;
    for (const Interval &interval : intervals) {
      if (mid < interval.lo - tolerance || mid > interval.hi + tolerance) {
        continue;
      }
      if (selected == nullptr || interval.triangle->vertices < selected->vertices) {
        selected = interval.triangle;
      }
    }
    if (selected == nullptr) {
      return {};
    }
    const Eigen::Vector2d uv0 = start + lo * (end - start);
    const Eigen::Vector2d uv1 = start + hi * (end - start);
    Eigen::RowVector3d bary0;
    Eigen::RowVector3d bary1;
    if (!chart_barycentric(*selected, uv0, bary0) ||
        !chart_barycentric(*selected, uv1, bary1) ||
        !canonicalize_periodic_chart_barycentric(bary0) ||
        !canonicalize_periodic_chart_barycentric(bary1)) {
      return {};
    }
    if ((bary1 - bary0).cwiseAbs().maxCoeff() <= 1.0e-12) {
      continue;
    }
    const auto selectedFaceRow =
        source_face_row(selected->sourceFace, sourceFaceCount);
    if (!selectedFaceRow.has_value()) return {};
    SurfaceTraceSegment segment;
    segment.face = *selectedFaceRow;
    segment.startBarycentric = bary0;
    segment.endBarycentric = bary1;
    segment.family = family;
    segment.sign = sign;
    const auto canonicalChart = sourceCharts.chart(segment.face);
    if (!canonicalChart.has_value()) {
      return {};
    }
    segment.sourceChart = canonicalChart->chart;
    if (!path.empty() && path.back().face == segment.face) {
      path.back().endBarycentric = segment.endBarycentric;
      continue;
    }
    path.push_back(std::move(segment));
  }
  if (path.empty()) {
    return {};
  }
  // Each chart segment is source-attached. Cross-face transition provenance
  // is authoritative in the periodic holonomy route; individual side paths
  // remain geometric subdivisions of that same cut-open chart.
  (void)matchingIndices;
  (void)transitionLookup;
  (void)edgeTransitions;
  return path;
}

std::vector<SurfaceTraceSegment> bounded_disk_chart_segment(
    const std::vector<PeriodicChartTriangle> &triangles,
    const SourceChartTransitionGraph &sourceCharts,
    const int sourceFaceCount,
    const Eigen::Vector2d &start, const Eigen::Vector2d &end,
    const int globalBranch,
    const std::vector<int> &faceBranchRotation) {
  struct Interval {
    double lo = 0.0;
    double hi = 0.0;
    const PeriodicChartTriangle *triangle = nullptr;
  };
  std::vector<Interval> intervals;
  std::vector<double> breaks{0.0, 1.0};
  constexpr double tolerance = kPeriodicChartCoverageTolerance;
  for (const PeriodicChartTriangle &triangle : triangles) {
    Eigen::RowVector3d b0;
    Eigen::RowVector3d b1;
    if (!chart_barycentric(triangle, start, b0) ||
        !chart_barycentric(triangle, end, b1)) {
      continue;
    }
    double lo = 0.0;
    double hi = 1.0;
    bool valid = true;
    for (int coordinate = 0; coordinate < 3; ++coordinate) {
      const double a = b0[coordinate];
      const double d = b1[coordinate] - b0[coordinate];
      if (std::abs(d) <= 1.0e-15) {
        if (a < -tolerance) valid = false;
        continue;
      }
      const double coverageBound = (-tolerance - a) / d;
      if (d > 0.0) {
        lo = std::max(lo, coverageBound);
      } else {
        hi = std::min(hi, coverageBound);
      }
      double exactBound = -a / d;
      if (exactBound >= -tolerance && exactBound <= 1.0 + tolerance) {
        exactBound = std::clamp(exactBound, 0.0, 1.0);
        breaks.push_back(exactBound);
      }
    }
    lo = std::clamp(lo, 0.0, 1.0);
    hi = std::clamp(hi, 0.0, 1.0);
    if (valid && hi - lo > 1.0e-12) {
      intervals.push_back({lo, hi, &triangle});
    }
  }
  std::sort(breaks.begin(), breaks.end());
  breaks.erase(std::unique(breaks.begin(), breaks.end(), [](double a, double b) {
                 return std::abs(a - b) <= 1.0e-10;
               }),
               breaks.end());

  std::vector<SurfaceTraceSegment> path;
  for (std::size_t index = 0; index + 1U < breaks.size(); ++index) {
    const double lo = breaks[index];
    const double hi = breaks[index + 1U];
    if (hi - lo <= 1.0e-12) continue;
    const double mid = 0.5 * (lo + hi);
    const PeriodicChartTriangle *selected = nullptr;
    for (const Interval &interval : intervals) {
      if (mid < interval.lo - tolerance || mid > interval.hi + tolerance) {
        continue;
      }
      if (selected == nullptr || interval.triangle->vertices < selected->vertices) {
        selected = interval.triangle;
      }
    }
    if (selected == nullptr) return {};
    const auto selectedFaceRow =
        source_face_row(selected->sourceFace, sourceFaceCount);
    if (!selectedFaceRow.has_value() ||
        *selectedFaceRow >= static_cast<int>(faceBranchRotation.size()) ||
        faceBranchRotation[static_cast<std::size_t>(*selectedFaceRow)] < 0) {
      return {};
    }
    const Eigen::Vector2d uv0 = start + lo * (end - start);
    const Eigen::Vector2d uv1 = start + hi * (end - start);
    Eigen::RowVector3d bary0;
    Eigen::RowVector3d bary1;
    if (!chart_barycentric(*selected, uv0, bary0) ||
        !chart_barycentric(*selected, uv1, bary1) ||
        !canonicalize_periodic_chart_barycentric(bary0) ||
        !canonicalize_periodic_chart_barycentric(bary1)) {
      return {};
    }
    if ((bary1 - bary0).cwiseAbs().maxCoeff() <= 1.0e-12) continue;

    const int localBranch = normalized_branch(
        faceBranchRotation[static_cast<std::size_t>(*selectedFaceRow)] +
        globalBranch);
    int family = 0;
    int sign = 1;
    family_sign_from_branch(localBranch, family, sign);

    SurfaceTraceSegment segment;
    segment.face = *selectedFaceRow;
    segment.startBarycentric = bary0;
    segment.endBarycentric = bary1;
    segment.family = family;
    segment.sign = sign;
    const auto canonicalChart = sourceCharts.chart(segment.face);
    if (!canonicalChart.has_value()) {
      return {};
    }
    segment.sourceChart = canonicalChart->chart;
    if (!path.empty() && path.back().face == segment.face &&
        path.back().family == segment.family && path.back().sign == segment.sign &&
        (path.back().endBarycentric - segment.startBarycentric).norm() <= 1.0e-10) {
      path.back().endBarycentric = segment.endBarycentric;
      continue;
    }
    path.push_back(std::move(segment));
  }
  return path;
}

} // namespace

SurfacePhaseFrontBuildState build_periodic_annulus_phase_front_for_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const std::vector<authority::SourceFaceId> &activeFaces,
    const SurfaceTopologyRegion &region,
    const SourceTopologyRegions &sourceAuthority,
    const SurfaceCellTracingOptions &options,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontBuildState result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted ||
      surface_cell_tracing_detail::tracing_has_singularities(options) ||
      activeFaces.empty()) {
    return result;
  }
  SourceChartTransitionGraph canonicalSourceCharts(
      &faces, &sourceAuthority, options.hardFeatureEdges);
  if (!canonicalSourceCharts.available()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
    return result;
  }

  std::set<int> activeVertices;
  std::map<authority::SourceEdgeTopologyKey, std::vector<int>> edgeFaces;
  std::map<authority::SourceEdgeTopologyKey, std::pair<int, int>> edgeVertices;
  std::map<int, std::set<int>> vertexAdjacency;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
      return result;
    }
    const int face = *faceRow;
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      if (a < 0 || b < 0 || a >= vertices.rows() || b >= vertices.rows() || a == b) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidPeriodicTopology,
                                -1, -1, face);
        return result;
      }
      activeVertices.insert(a);
      activeVertices.insert(b);
      const authority::SourceEdgeTopologyKey key = edge_key(a, b, source_vertex_extent(faces));
      edgeFaces[key].push_back(face);
      edgeVertices[key] = {std::min(a, b), std::max(a, b)};
      vertexAdjacency[a].insert(b);
      vertexAdjacency[b].insert(a);
    }
  }
  for (const auto &[key, incident] : edgeFaces) {
    (void)key;
    if (incident.empty() || incident.size() > 2U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
      return result;
    }
  }
  const int euler = static_cast<int>(activeVertices.size()) -
                    static_cast<int>(edgeFaces.size()) +
                    static_cast<int>(activeFaces.size());
  if (euler != 0) {
    return result;
  }

  std::map<int, std::vector<int>> boundaryAdjacency;
  for (const auto &[key, incident] : edgeFaces) {
    if (incident.size() != 1U) continue;
    const auto endpoints = edgeVertices[key];
    boundaryAdjacency[endpoints.first].push_back(endpoints.second);
    boundaryAdjacency[endpoints.second].push_back(endpoints.first);
  }
  for (auto &[vertex, neighbors] : boundaryAdjacency) {
    (void)vertex;
    std::sort(neighbors.begin(), neighbors.end());
    neighbors.erase(std::unique(neighbors.begin(), neighbors.end()), neighbors.end());
    if (neighbors.size() != 2U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
      return result;
    }
  }
  std::vector<std::vector<int>> boundaryCycles;
  std::set<int> remainingBoundary;
  for (const auto &[vertex, neighbors] : boundaryAdjacency) {
    (void)neighbors;
    remainingBoundary.insert(vertex);
  }
  while (!remainingBoundary.empty()) {
    const int seed = *remainingBoundary.begin();
    std::map<int, std::vector<int>> component;
    std::vector<int> stack{seed};
    std::set<int> seen;
    while (!stack.empty()) {
      const int vertex = stack.back();
      stack.pop_back();
      if (!seen.insert(vertex).second) continue;
      component[vertex] = boundaryAdjacency[vertex];
      for (const int neighbor : boundaryAdjacency[vertex]) {
        if (seen.count(neighbor) == 0U) stack.push_back(neighbor);
      }
    }
    std::vector<int> cycle = canonical_cycle(component);
    if (cycle.empty()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
      return result;
    }
    for (const int vertex : cycle) remainingBoundary.erase(vertex);
    boundaryCycles.push_back(std::move(cycle));
  }
  if (boundaryCycles.size() != 2U ||
      boundaryCycles[0].size() != boundaryCycles[1].size()) {
    return result;
  }
  std::sort(boundaryCycles.begin(), boundaryCycles.end());
  const std::vector<int> &firstBoundary = boundaryCycles.front();
  const std::set<int> secondBoundary(boundaryCycles.back().begin(),
                                     boundaryCycles.back().end());
  const int ringSize = static_cast<int>(firstBoundary.size());
  if (ringSize < 3) return result;

  std::map<int, int> distance;
  std::queue<int> queue;
  for (const int vertex : firstBoundary) {
    distance[vertex] = 0;
    queue.push(vertex);
  }
  while (!queue.empty()) {
    const int vertex = queue.front();
    queue.pop();
    for (const int neighbor : vertexAdjacency[vertex]) {
      if (distance.find(neighbor) == distance.end()) {
        distance[neighbor] = distance[vertex] + 1;
        queue.push(neighbor);
      }
    }
  }
  if (distance.size() != activeVertices.size()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
    return result;
  }
  int maxDistance = 0;
  for (const auto &[vertex, value] : distance) {
    (void)vertex;
    maxDistance = std::max(maxDistance, value);
  }
  if (maxDistance < 1) return result;
  for (const int vertex : secondBoundary) {
    if (distance[vertex] != maxDistance) return result;
  }

  std::vector<std::vector<int>> rings(static_cast<std::size_t>(maxDistance + 1));
  rings.front() = firstBoundary;
  for (int layer = 1; layer <= maxDistance; ++layer) {
    std::map<int, std::vector<int>> ringAdjacency;
    for (const auto &[vertex, value] : distance) {
      if (value != layer) continue;
      for (const int neighbor : vertexAdjacency[vertex]) {
        if (distance[neighbor] == layer) ringAdjacency[vertex].push_back(neighbor);
      }
      std::sort(ringAdjacency[vertex].begin(), ringAdjacency[vertex].end());
    }
    if (ringAdjacency.size() != static_cast<std::size_t>(ringSize)) return result;
    std::vector<int> ring = canonical_cycle(ringAdjacency);
    if (ring.size() != static_cast<std::size_t>(ringSize)) return result;
    rings[static_cast<std::size_t>(layer)] = std::move(ring);
  }

  auto quad_faces = [&](const std::array<int, 4> &quad) {
    std::set<int> quadVertices(quad.begin(), quad.end());
    std::vector<authority::SourceFaceId> candidates;
    for (const authority::SourceFaceId faceId : activeFaces) {
      const auto faceRow = source_face_row(faceId, faces.rows());
      if (!faceRow.has_value()) return std::vector<authority::SourceFaceId>{};
      if (face_contains_only(faces, *faceRow, quadVertices)) {
        candidates.push_back(faceId);
      }
    }
    std::sort(candidates.begin(), candidates.end(),
              [&](const authority::SourceFaceId a,
                  const authority::SourceFaceId b) {
                return sourceAuthority.topology_for_row(a) <
                       sourceAuthority.topology_for_row(b);
              });
    return candidates;
  };

  // Adjacent graph-distance rings can admit more than one source-topologically
  // valid bijection through a triangulated strip (for example, the two
  // diagonals of the same logical strip). Source-face scheduling remains typed
  // through candidate selection and field-transport traversal; row projection
  // occurs only at direct matrix/vector call boundaries.
  const auto incident = edge_faces(faces, activeFaces);
  const auto &matchingIndices = sourceMatchingIndices;
  const bool hasTransitions = edgeTransitions != nullptr && !edgeTransitions->empty();
  const EdgeTransitionLookup transitionLookup =
      authoritative_edge_transition_lookup(
          options.fieldTransportAtlas,
          hasTransitions ? edgeTransitions : nullptr,
          source_vertex_extent(faces));
  if (transitionLookup.duplicate) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }

  struct RingCandidateAuthority {
    std::vector<int> vertices;
    std::set<authority::SourceFaceId> stripFaces;
    double score = std::numeric_limits<double>::infinity();
    int seedBranch = -1;
    bool branchAmbiguous = false;
  };
  struct DualNeighbor {
    authority::SourceFaceId face;
    authority::SourceEdgeTopologyKey edge;
  };
  const auto score_equal = [](const double a, const double b) {
    if (!std::isfinite(a) || !std::isfinite(b)) return false;
    const double scale = std::max({1.0, std::abs(a), std::abs(b)});
    return std::abs(a - b) <=
           256.0 * std::numeric_limits<double>::epsilon() * scale;
  };
  const auto edge_direction_in_face = [&](const int a, const int b,
                                          const int face) {
    return project_tangent(row3(vertices, b) - row3(vertices, a),
                           face_normal(vertices, faces, face));
  };
  const auto score_ring_candidate = [&](RingCandidateAuthority &candidate,
                                        const std::vector<int> &previous) {
    std::map<authority::SourceFaceId, std::vector<DualNeighbor>> dual;
    for (const authority::SourceFaceId face : candidate.stripFaces) {
      dual[face] = {};
    }
    for (const auto &[key, pair] : incident) {
      if (pair[0] < 0 || pair[1] < 0) continue;
      const auto firstFace = source_face_id(pair[0], faces.rows());
      const auto secondFace = source_face_id(pair[1], faces.rows());
      if (!firstFace.has_value() || !secondFace.has_value()) return false;
      if (candidate.stripFaces.count(*firstFace) == 0U ||
          candidate.stripFaces.count(*secondFace) == 0U) {
        continue;
      }
      dual[*firstFace].push_back(DualNeighbor{*secondFace, key});
      dual[*secondFace].push_back(DualNeighbor{*firstFace, key});
    }
    if (dual.size() != candidate.stripFaces.size()) return false;
    for (auto &[face, neighbors] : dual) {
      (void)face;
      std::sort(neighbors.begin(), neighbors.end(), [&](const DualNeighbor &a,
                                                        const DualNeighbor &b) {
        const auto &aKey = sourceAuthority.topology_for_row(a.face);
        const auto &bKey = sourceAuthority.topology_for_row(b.face);
        if (aKey != bKey) return aKey < bKey;
        return a.edge < b.edge;
      });
    }
    std::optional<authority::SourceFaceId> startFace;
    for (const authority::SourceFaceId face : candidate.stripFaces) {
      if (!startFace.has_value() ||
          sourceAuthority.topology_for_row(face) <
              sourceAuthority.topology_for_row(*startFace)) {
        startFace = face;
      }
    }
    if (!startFace.has_value()) return false;

    std::array<double, 4> branchScores{
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity()};
    for (int seedBranch = 0; seedBranch < 4; ++seedBranch) {
      std::map<authority::SourceFaceId, int> branchByFace;
      std::queue<authority::SourceFaceId> pending;
      branchByFace[*startFace] = seedBranch;
      pending.push(*startFace);
      bool validBranch = true;
      while (!pending.empty() && validBranch) {
        const authority::SourceFaceId sourceFace = pending.front();
        pending.pop();
        const auto sourceFaceRow = source_face_row(sourceFace, faces.rows());
        if (!sourceFaceRow.has_value()) {
          validBranch = false;
          break;
        }
        const int sourceBranch = branchByFace[sourceFace];
        int sourceFamily = 0;
        int sourceSign = 1;
        family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
        const Eigen::RowVector3d sourceDirection = project_tangent(
            axis_for_family(faceAxisX, faceAxisY, *sourceFaceRow, sourceFamily,
                            sourceSign),
            face_normal(vertices, faces, *sourceFaceRow));
        if (sourceDirection.squaredNorm() == 0.0) {
          validBranch = false;
          break;
        }
        for (const DualNeighbor &neighbor : dual[sourceFace]) {
          if (branchByFace.find(neighbor.face) != branchByFace.end()) {
            continue; // Cycle closure is validated by periodic holonomy below.
          }
          const auto neighborRow = source_face_row(neighbor.face, faces.rows());
          if (!neighborRow.has_value()) {
            validBranch = false;
            break;
          }
          const BranchTransitionResult forward = resolve_branch_transition(
              vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
              transitionLookup, neighbor.edge, *sourceFaceRow, *neighborRow,
              sourceFamily, sourceSign, sourceDirection, edgeMatching,
              edgeEffort, hasTransitions ? edgeTransitions : nullptr);
          if (!forward.valid) {
            validBranch = false;
            break;
          }
          const int targetBranch =
              branch_from_family_sign(forward.family, forward.sign);
          int targetFamily = 0;
          int targetSign = 1;
          family_sign_from_branch(targetBranch, targetFamily, targetSign);
          const Eigen::RowVector3d targetDirection = project_tangent(
              axis_for_family(faceAxisX, faceAxisY, *neighborRow, targetFamily,
                              targetSign),
              face_normal(vertices, faces, *neighborRow));
          const BranchTransitionResult reverse = resolve_branch_transition(
              vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
              transitionLookup, neighbor.edge, *neighborRow, *sourceFaceRow,
              targetFamily, targetSign, targetDirection, edgeMatching,
              edgeEffort, hasTransitions ? edgeTransitions : nullptr);
          if (!reverse.valid ||
              branch_from_family_sign(reverse.family, reverse.sign) !=
                  sourceBranch ||
              normalized_branch(forward.matching + reverse.matching) != 0) {
            validBranch = false;
            break;
          }
          branchByFace[neighbor.face] = targetBranch;
          pending.push(neighbor.face);
        }
      }
      if (!validBranch || branchByFace.size() != candidate.stripFaces.size()) {
        continue;
      }

      double score = 0.0;
      int observations = 0;
      const auto accumulate_edge_score = [&](const int a, const int b,
                                             const int branchOffset,
                                             const bool oriented) {
        const auto found = incident.find(edge_key(a, b, source_vertex_extent(faces)));
        if (found == incident.end()) return false;
        bool observed = false;
        for (const int faceRow : found->second) {
          if (faceRow < 0) continue;
          const auto face = source_face_id(faceRow, faces.rows());
          if (!face.has_value() || candidate.stripFaces.count(*face) == 0U) {
            continue;
          }
          const auto branchFound = branchByFace.find(*face);
          if (branchFound == branchByFace.end()) return false;
          const int expectedBranch =
              normalized_branch(branchFound->second + branchOffset);
          int family = 0;
          int sign = 1;
          family_sign_from_branch(expectedBranch, family, sign);
          const Eigen::RowVector3d fieldDirection = project_tangent(
              axis_for_family(faceAxisX, faceAxisY, faceRow, family, sign),
              face_normal(vertices, faces, faceRow));
          const Eigen::RowVector3d edgeDirection =
              edge_direction_in_face(a, b, faceRow);
          if (fieldDirection.squaredNorm() == 0.0 ||
              edgeDirection.squaredNorm() == 0.0) {
            return false;
          }
          double cosine = fieldDirection.dot(edgeDirection);
          if (!oriented) cosine = std::abs(cosine);
          const double angle = std::acos(std::clamp(cosine, -1.0, 1.0));
          if (!std::isfinite(angle)) return false;
          score += angle * angle;
          ++observations;
          observed = true;
        }
        return observed;
      };

      for (int u = 0; u < ringSize && validBranch; ++u) {
        const int next = (u + 1) % ringSize;
        if (!accumulate_edge_score(
                previous[static_cast<std::size_t>(u)],
                candidate.vertices[static_cast<std::size_t>(u)], 0, true)) {
          validBranch = false;
          break;
        }
        if (!accumulate_edge_score(
                previous[static_cast<std::size_t>(u)],
                previous[static_cast<std::size_t>(next)], 1, false) ||
            !accumulate_edge_score(
                candidate.vertices[static_cast<std::size_t>(u)],
                candidate.vertices[static_cast<std::size_t>(next)], 1, false)) {
          validBranch = false;
          break;
        }
      }
      if (!validBranch || observations <= 0) continue;
      branchScores[static_cast<std::size_t>(seedBranch)] =
          score / static_cast<double>(observations);
    }

    double bestScore = std::numeric_limits<double>::infinity();
    int bestBranch = -1;
    bool ambiguousBranch = false;
    for (int branch = 0; branch < 4; ++branch) {
      const double score = branchScores[static_cast<std::size_t>(branch)];
      if (!std::isfinite(score)) continue;
      if (score < bestScore && !score_equal(score, bestScore)) {
        bestScore = score;
        bestBranch = branch;
        ambiguousBranch = false;
      } else if (score_equal(score, bestScore)) {
        ambiguousBranch = true;
      }
    }
    if (bestBranch < 0 || !std::isfinite(bestScore)) return false;
    candidate.score = bestScore;
    candidate.seedBranch = bestBranch;
    candidate.branchAmbiguous = ambiguousBranch;
    return true;
  };

  for (int layer = 1; layer <= maxDistance; ++layer) {
    const std::vector<int> previous = rings[static_cast<std::size_t>(layer - 1)];
    const std::vector<int> raw = rings[static_cast<std::size_t>(layer)];
    std::map<std::vector<int>, std::set<authority::SourceFaceId>> topologyCandidates;
    for (int direction : {1, -1}) {
      for (int offset = 0; offset < ringSize; ++offset) {
        std::vector<int> candidate(static_cast<std::size_t>(ringSize));
        for (int u = 0; u < ringSize; ++u) {
          const int index = (offset + direction * u) % ringSize;
          candidate[static_cast<std::size_t>(u)] =
              raw[static_cast<std::size_t>((index + ringSize) % ringSize)];
        }
        bool compatible = true;
        std::set<authority::SourceFaceId> stripFaces;
        for (int u = 0; u < ringSize && compatible; ++u) {
          const int next = (u + 1) % ringSize;
          if (edgeFaces.count(edge_key(previous[static_cast<std::size_t>(u)],
                                       candidate[static_cast<std::size_t>(u)],
                                       source_vertex_extent(faces))) == 0U) {
            compatible = false;
            break;
          }
          const std::array<int, 4> quad{
              previous[static_cast<std::size_t>(u)],
              previous[static_cast<std::size_t>(next)],
              candidate[static_cast<std::size_t>(next)],
              candidate[static_cast<std::size_t>(u)]};
          const std::vector<authority::SourceFaceId> pair = quad_faces(quad);
          if (pair.size() != 2U) {
            compatible = false;
            break;
          }
          stripFaces.insert(pair.begin(), pair.end());
        }
        if (compatible &&
            stripFaces.size() == static_cast<std::size_t>(2 * ringSize)) {
          topologyCandidates.emplace(std::move(candidate), std::move(stripFaces));
        }
      }
    }
    if (topologyCandidates.empty()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidPeriodicRingCorrespondence);
      return result;
    }

    std::vector<RingCandidateAuthority> authoritativeCandidates;
    authoritativeCandidates.reserve(topologyCandidates.size());
    for (const auto &[candidateVertices, stripFaces] : topologyCandidates) {
      RingCandidateAuthority candidate;
      candidate.vertices = candidateVertices;
      candidate.stripFaces = stripFaces;
      if (score_ring_candidate(candidate, previous)) {
        authoritativeCandidates.push_back(std::move(candidate));
      }
    }
    if (authoritativeCandidates.empty()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidPeriodicRingCorrespondence);
      return result;
    }

    double bestScore = std::numeric_limits<double>::infinity();
    int bestCandidate = -1;
    bool ambiguous = false;
    for (int index = 0;
         index < static_cast<int>(authoritativeCandidates.size()); ++index) {
      const RingCandidateAuthority &candidate =
          authoritativeCandidates[static_cast<std::size_t>(index)];
      if (candidate.score < bestScore &&
          !score_equal(candidate.score, bestScore)) {
        bestScore = candidate.score;
        bestCandidate = index;
        ambiguous = candidate.branchAmbiguous;
      } else if (score_equal(candidate.score, bestScore)) {
        ambiguous = true;
      }
    }
    if (bestCandidate < 0 || ambiguous) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::AmbiguousPeriodicRingCorrespondence);
      return result;
    }
    rings[static_cast<std::size_t>(layer)] =
        authoritativeCandidates[static_cast<std::size_t>(bestCandidate)].vertices;
  }

  std::vector<double> s(static_cast<std::size_t>(ringSize + 1), 0.0);
  for (int u = 0; u < ringSize; ++u) {
    const int next = (u + 1) % ringSize;
    double length = 0.0;
    for (const auto &ring : rings) {
      length += (row3(vertices, ring[static_cast<std::size_t>(next)]) -
                 row3(vertices, ring[static_cast<std::size_t>(u)])).norm();
    }
    length /= static_cast<double>(rings.size());
    if (!(length > 0.0) || !std::isfinite(length)) return result;
    s[static_cast<std::size_t>(u + 1)] = s[static_cast<std::size_t>(u)] + length;
  }
  std::vector<double> t(rings.size(), 0.0);
  for (int layer = 0; layer < maxDistance; ++layer) {
    double length = 0.0;
    for (int u = 0; u < ringSize; ++u) {
      const int a = rings[static_cast<std::size_t>(layer)][static_cast<std::size_t>(u)];
      const int b = rings[static_cast<std::size_t>(layer + 1)][static_cast<std::size_t>(u)];
      if (edgeFaces.count(edge_key(a, b, source_vertex_extent(faces))) == 0U) return result;
      length += (row3(vertices, b) - row3(vertices, a)).norm();
    }
    length /= static_cast<double>(ringSize);
    if (!(length > 0.0) || !std::isfinite(length)) return result;
    t[static_cast<std::size_t>(layer + 1)] =
        t[static_cast<std::size_t>(layer)] + length;
  }
  const double period = s.back();
  const double height = t.back();
  double target = options.defaultTargetSize;
  if (targetSize.size() > 0 && targetSize.allFinite() &&
      targetSize.minCoeff() > 0.0) {
    target = targetSize.mean();
  }
  if (!(period > 0.0) || !(height > 0.0) || !(target > 0.0) ||
      !std::isfinite(target)) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
    return result;
  }

  // Every canonical annulus strip boundary is a mandatory periodic lattice
  // breakpoint.  Subdivide each strip independently from its intrinsic length
  // and local target field so no accepted cell side bridges a source-ring
  // corner merely because a globally uniform period/target count misses it.
  std::vector<int> stripSubdivisions(static_cast<std::size_t>(ringSize), 1);
  int periodicSubdivisionCount = 0;
  for (int u = 0; u < ringSize; ++u) {
    const int next = (u + 1) % ringSize;
    const double stripLength =
        s[static_cast<std::size_t>(u + 1)] - s[static_cast<std::size_t>(u)];
    double localTargetSum = 0.0;
    int localTargetSamples = 0;
    for (const auto &ring : rings) {
      const int a = ring[static_cast<std::size_t>(u)];
      const int b = ring[static_cast<std::size_t>(next)];
      for (const int vertex : {a, b}) {
        const double sample = target_size_at_vertex(targetSize, vertex, target);
        if (!(sample > 0.0) || !std::isfinite(sample)) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
          return result;
        }
        localTargetSum += sample;
        ++localTargetSamples;
      }
    }
    const double localTarget =
        localTargetSum / static_cast<double>(localTargetSamples);
    if (!(stripLength > 0.0) || !std::isfinite(stripLength) ||
        !(localTarget > 0.0) || !std::isfinite(localTarget)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
      return result;
    }
    const double subdivisionRatio = stripLength / localTarget;
    if (!std::isfinite(subdivisionRatio) ||
        subdivisionRatio > static_cast<double>(std::numeric_limits<int>::max())) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
      return result;
    }
    const int subdivisions = std::max(
        1, static_cast<int>(std::llround(subdivisionRatio)));
    if (periodicSubdivisionCount >
        std::numeric_limits<int>::max() - subdivisions) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
      return result;
    }
    stripSubdivisions[static_cast<std::size_t>(u)] = subdivisions;
    periodicSubdivisionCount += subdivisions;
  }
  result.gridU = periodicSubdivisionCount;
  result.gridV = std::max(1, static_cast<int>(std::llround(height / target)));

  std::vector<double> periodicCoordinates;
  periodicCoordinates.reserve(static_cast<std::size_t>(result.gridU + 1));
  periodicCoordinates.push_back(0.0);
  for (int u = 0; u < ringSize; ++u) {
    const double stripStart = s[static_cast<std::size_t>(u)];
    const double stripEnd = s[static_cast<std::size_t>(u + 1)];
    const int subdivisions = stripSubdivisions[static_cast<std::size_t>(u)];
    for (int division = 1; division <= subdivisions; ++division) {
      const double coordinate =
          division == subdivisions
              ? stripEnd
              : stripStart + (stripEnd - stripStart) *
                                 (static_cast<double>(division) /
                                  static_cast<double>(subdivisions));
      if (!std::isfinite(coordinate) ||
          coordinate <= periodicCoordinates.back()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
        return result;
      }
      periodicCoordinates.push_back(coordinate);
    }
  }
  if (periodicCoordinates.size() !=
          static_cast<std::size_t>(result.gridU + 1) ||
      std::abs(periodicCoordinates.back() - period) >
          1.0e-12 * std::max(1.0, period)) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidPeriodicChart);
    return result;
  }

  std::map<int, std::pair<int, int>> vertexChartIndex;
  for (int layer = 0; layer <= maxDistance; ++layer) {
    for (int u = 0; u < ringSize; ++u) {
      vertexChartIndex[rings[static_cast<std::size_t>(layer)][static_cast<std::size_t>(u)]] = {u, layer};
    }
  }
  std::vector<PeriodicChartTriangle> chartTriangles;
  chartTriangles.reserve(activeFaces.size());
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return result;
    const int face = *faceRow;
    PeriodicChartTriangle triangle(faceId);
    triangle.vertices = canonical_face_vertices(faces, face);
    std::array<int, 3> columns{};
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      const auto found = vertexChartIndex.find(vertex);
      if (found == vertexChartIndex.end()) return result;
      columns[static_cast<std::size_t>(corner)] = found->second.first;
      triangle.uv[static_cast<std::size_t>(corner)] = {
          s[static_cast<std::size_t>(found->second.first)],
          t[static_cast<std::size_t>(found->second.second)]};
    }
    const int minColumn = *std::min_element(columns.begin(), columns.end());
    const int maxColumn = *std::max_element(columns.begin(), columns.end());
    if (minColumn == 0 && maxColumn == ringSize - 1) {
      for (int corner = 0; corner < 3; ++corner) {
        if (columns[static_cast<std::size_t>(corner)] == 0) {
          triangle.uv[static_cast<std::size_t>(corner)].x() = period;
        }
      }
    }
    chartTriangles.push_back(std::move(triangle));
  }
  std::sort(chartTriangles.begin(), chartTriangles.end(),
            [](const PeriodicChartTriangle &a, const PeriodicChartTriangle &b) {
              return a.vertices < b.vertices;
            });

  // Derive one complete periodic source route from the first topological strip.
  // Face-cycle ownership stays typed; only matrix/transition calls receive a
  // checked row projection.
  std::set<authority::SourceFaceId> firstStripFaces;
  for (int u = 0; u < ringSize; ++u) {
    const int next = (u + 1) % ringSize;
    const std::array<int, 4> quad{
        rings[0][static_cast<std::size_t>(u)],
        rings[0][static_cast<std::size_t>(next)],
        rings[1][static_cast<std::size_t>(next)],
        rings[1][static_cast<std::size_t>(u)]};
    const auto pair = quad_faces(quad);
    firstStripFaces.insert(pair.begin(), pair.end());
  }
  std::map<authority::SourceFaceId, std::vector<authority::SourceFaceId>> dual;
  for (const authority::SourceFaceId face : firstStripFaces) dual[face] = {};
  for (const auto &[key, pair] : incident) {
    (void)key;
    if (pair[0] < 0 || pair[1] < 0) continue;
    const auto firstFace = source_face_id(pair[0], faces.rows());
    const auto secondFace = source_face_id(pair[1], faces.rows());
    if (!firstFace.has_value() || !secondFace.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
    if (firstStripFaces.count(*firstFace) != 0U &&
        firstStripFaces.count(*secondFace) != 0U) {
      dual[*firstFace].push_back(*secondFace);
      dual[*secondFace].push_back(*firstFace);
    }
  }
  for (auto &[face, neighbors] : dual) {
    (void)face;
    std::sort(neighbors.begin(), neighbors.end(),
              [&](const authority::SourceFaceId a,
                  const authority::SourceFaceId b) {
                return sourceAuthority.topology_for_row(a) <
                       sourceAuthority.topology_for_row(b);
              });
    if (neighbors.size() != 2U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
  }
  auto canonical_face_cycle = [&](const int firstNeighborIndex) {
    std::optional<authority::SourceFaceId> startFace;
    for (const auto &[face, neighbors] : dual) {
      (void)neighbors;
      if (!startFace.has_value() ||
          sourceAuthority.topology_for_row(face) <
              sourceAuthority.topology_for_row(*startFace)) {
        startFace = face;
      }
    }
    if (!startFace.has_value()) return std::vector<authority::SourceFaceId>{};
    std::vector<authority::SourceFaceId> cycle;
    cycle.reserve(dual.size());
    cycle.push_back(*startFace);
    authority::SourceFaceId previous = *startFace;
    authority::SourceFaceId current =
        dual[*startFace][static_cast<std::size_t>(firstNeighborIndex)];
    while (current != *startFace && cycle.size() <= dual.size()) {
      cycle.push_back(current);
      const auto &neighbors = dual[current];
      const authority::SourceFaceId next =
          neighbors[0] == previous ? neighbors[1] : neighbors[0];
      previous = current;
      current = next;
    }
    if (current != *startFace || cycle.size() != dual.size()) {
      return std::vector<authority::SourceFaceId>{};
    }
    return cycle;
  };
  std::vector<authority::SourceFaceId> faceCycleA = canonical_face_cycle(0);
  std::vector<authority::SourceFaceId> faceCycleB = canonical_face_cycle(1);
  auto face_cycle_key = [&](const std::vector<authority::SourceFaceId> &cycle) {
    std::vector<authority::SourceFaceTopologyKey> key;
    key.reserve(cycle.size());
    for (const authority::SourceFaceId face : cycle) {
      key.push_back(sourceAuthority.topology_for_row(face));
    }
    return key;
  };
  const std::vector<authority::SourceFaceId> faceCycle =
      face_cycle_key(faceCycleB) < face_cycle_key(faceCycleA) ? faceCycleB
                                                             : faceCycleA;
  if (faceCycle.empty()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }
  std::vector<authority::TransitionStep> observedSteps;
  observedSteps.reserve(faceCycle.size());
  for (std::size_t index = 0; index < faceCycle.size(); ++index) {
    const auto sourceFaceRow = source_face_row(faceCycle[index], faces.rows());
    const auto targetFaceRow = source_face_row(
        faceCycle[(index + 1U) % faceCycle.size()], faces.rows());
    if (!sourceFaceRow.has_value() || !targetFaceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
    const int sourceFace = *sourceFaceRow;
    const int targetFace = *targetFaceRow;
    std::optional<authority::SourceEdgeTopologyKey> sharedKey;
    for (int a = 0; a < 3 && !sharedKey.has_value(); ++a) {
      const authority::SourceEdgeTopologyKey key = local_edge_key(faces, sourceFace, a);
      if (local_edge_for_key(faces, targetFace, key) >= 0) sharedKey = key;
    }
    if (!sharedKey.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                              -1, -1, sourceFace, targetFace);
      return result;
    }
    int sourceEdge = -1;
    if (!source_edge_provenance(
            *sharedKey, sourceEdgeFaces, sourceMatchingIndices,
            transitionLookup, hasTransitions ? edgeTransitions : nullptr,
            sourceEdge)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                              -1, -1, sourceFace, targetFace, -1, sourceEdge);
      return result;
    }
    int matching = 0;
    if (hasTransitions) {
      const auto found = transitionLookup.byEdge.find(*sharedKey);
      if (found == transitionLookup.byEdge.end() ||
          !transition_faces_match(found->second, sourceFace, targetFace)) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                                -1, -1, sourceFace, targetFace, -1, sourceEdge);
        return result;
      }
      matching = found->second.matching;
      if (found->second.secondFace == sourceFace) matching = -matching;
    } else if (edgeMatching != nullptr && edgeMatching->size() > 0) {
      const auto matchingIndex = matchingIndices.find(*sharedKey);
      if (matchingIndex == matchingIndices.end() ||
          matchingIndex->second >= edgeMatching->size()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                                -1, -1, sourceFace, targetFace, -1, sourceEdge);
        return result;
      }
      matching = (*edgeMatching)[matchingIndex->second];
      const auto topology = incident.find(*sharedKey);
      if (topology != incident.end() && topology->second[1] == sourceFace) matching = -matching;
    }

    const authority::SourceEdgeTopologyKey &topology = *sharedKey;
    const auto interiorTransition =
        directional::authority::InteriorTransitionId::from_index(
            sourceEdge, sourceMatchingIndices.size());
    if (!interiorTransition) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                              -1, -1, sourceFace, targetFace, -1, sourceEdge);
      return result;
    }
    const auto typedStep = authority::TransitionStep::interior(
        topology,
        std::optional<authority::InteriorTransitionId>{
            interiorTransition.value()},
        authority::GridAutomorphism{
            authority::QuarterTurn::from_integer(matching),
            authority::LatticeTranslation{0, 0}},
        authority::Orientation::Forward);
    if (!typedStep) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                              -1, -1, sourceFace, targetFace, -1, sourceEdge);
      return result;
    }
    observedSteps.push_back(typedStep.value());
  }
  const authority::CanonicalRoute typedRoute =
      authority::CanonicalRoute::from_observed_steps(std::move(observedSteps));
  authority::GridAutomorphism routeTransport =
      authority::GridAutomorphism::identity();
  for (const authority::TransitionStep &step : typedRoute.oriented_steps()) {
    routeTransport = compose(step.transport(), routeTransport);
  }
  if (routeTransport.rotation.value() != 0U) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }

  result.disposition = SurfaceCellProducerDisposition::Rejected;
  const authority::GridAutomorphism periodicAction{
      authority::QuarterTurn{},
      authority::LatticeTranslation{result.gridU, 0}};
  std::vector<authority::TransitionStep> cutSteps;
  cutSteps.reserve(static_cast<std::size_t>(maxDistance));
  for (int layer = 0; layer < maxDistance; ++layer) {
    const authority::SourceEdgeTopologyKey key = edge_key(
        rings[static_cast<std::size_t>(layer)][0],
        rings[static_cast<std::size_t>(layer + 1)][0],
        source_vertex_extent(faces));
    int sourceEdge = -1;
    if (!source_edge_provenance(
            key, sourceEdgeFaces, sourceMatchingIndices, transitionLookup,
            hasTransitions ? edgeTransitions : nullptr, sourceEdge)) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
    const authority::SourceEdgeTopologyKey &topology = key;
    const auto transition = authority::InteriorTransitionId::from_index(
        sourceEdge, sourceMatchingIndices.size());
    if (!transition) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
    const auto step = authority::TransitionStep::interior(
        topology, transition.value(),
        authority::GridAutomorphism::identity(),
        authority::Orientation::Forward);
    if (!step) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
    cutSteps.push_back(step.value());
  }
  const authority::CanonicalRoute cutRoute =
      authority::CanonicalRoute::from_observed_steps(std::move(cutSteps));
  const auto relationId = authority::PeriodicRelationId::from_index(0, 1);
  if (!relationId) {
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
    return result;
  }
  auto periodicConstruction = SurfacePeriodicHolonomy::make(
      relationId.value(), region.id(), periodicAction, typedRoute, cutRoute);
  auto *periodicValue =
      std::get_if<SurfacePeriodicHolonomy>(&periodicConstruction);
  if (periodicValue == nullptr) {
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }
  result.periodicHolonomies.push_back(
      surface_cell_tracing_detail::canonicalize_periodic_holonomy(
          std::move(*periodicValue)));
  const SurfacePeriodicHolonomy &periodicHolonomy =
      result.periodicHolonomies.back();

  const double stepV = height / static_cast<double>(result.gridV);
  const int columns = result.gridU + 1;
  const int rows = result.gridV + 1;
  std::vector<SurfaceTracePoint> points(static_cast<std::size_t>(columns * rows));
  const auto node_index = [columns](int u, int v) { return v * columns + u; };
  for (int v = 0; v < rows; ++v) {
    for (int u = 0; u < columns; ++u) {
      const Eigen::Vector2d uv(
          periodicCoordinates[static_cast<std::size_t>(u)], stepV * v);
      if (!point_on_periodic_chart(
              chartTriangles, uv, faces.rows(),
              points[static_cast<std::size_t>(node_index(u, v))])) {
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidPeriodicChart,
                                -1, -1, -1, -1, -1);
        return result;
      }
    }
  }

  struct EdgeOwner { int edge = -1; };
  std::map<std::pair<int, int>, EdgeOwner> openEdges;
  const auto canonical_node = [&](const authority::LatticeTranslation coordinate) {
    int u = static_cast<int>(coordinate.x);
    if (u == result.gridU) u = 0;
    return static_cast<int>(coordinate.y) * result.gridU + u;
  };
  for (int v = 0; v < result.gridV; ++v) {
    for (int u = 0; u < result.gridU; ++u) {
      const std::array<int, 4> nodeIds{
          node_index(u, v), node_index(u + 1, v),
          node_index(u + 1, v + 1), node_index(u, v + 1)};
      const double u0 = periodicCoordinates[static_cast<std::size_t>(u)];
      const double u1 = periodicCoordinates[static_cast<std::size_t>(u + 1)];
      const std::array<Eigen::Vector2d, 4> uv{
          Eigen::Vector2d(u0, stepV * v),
          Eigen::Vector2d(u1, stepV * v),
          Eigen::Vector2d(u1, stepV * (v + 1)),
          Eigen::Vector2d(u0, stepV * (v + 1))};
      const auto cellId = phase_front_cell_id_from_lattice(
          u, v, result.gridU, result.gridV);
      if (!cellId) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
        return result;
      }
      SurfacePhaseFrontCell cell(region.id(), cellId.value());
      for (int corner = 0; corner < 4; ++corner) {
        cell.corners[static_cast<std::size_t>(corner)] =
            points[static_cast<std::size_t>(nodeIds[corner])];
        auto &state = cell.lattice[static_cast<std::size_t>(corner)];
        state.phase = uv[static_cast<std::size_t>(corner)];
        state.latticeCoordinate = {
            corner == 1 || corner == 2 ? u + 1 : u,
            corner >= 2 ? v + 1 : v};
        const int canonicalFace =
            cell.corners[static_cast<std::size_t>(corner)].face;
        const auto canonicalChart =
            canonicalSourceCharts.chart(canonicalFace);
        if (!canonicalChart.has_value()) {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidPeriodicChart,
              static_cast<int>(cell.id.index()), corner, canonicalFace);
          return result;
        }
        state.sourceChart = canonicalChart->chart;
      }
      for (int side = 0; side < 4; ++side) {
        const authority::LatticeTranslation delta =
            cell.lattice[static_cast<std::size_t>((side + 1) % 4)].latticeCoordinate -
            cell.lattice[static_cast<std::size_t>(side)].latticeCoordinate;
        const int family = delta.x != 0 ? 0 : 1;
        const int sign = (delta.x + delta.y) >= 0 ? 1 : -1;
        cell.boundaryPaths[static_cast<std::size_t>(side)] = periodic_chart_segment(
            chartTriangles, canonicalSourceCharts, faces.rows(),
            uv[static_cast<std::size_t>(side)],
            uv[static_cast<std::size_t>((side + 1) % 4)], family, sign,
            matchingIndices, transitionLookup,
            hasTransitions ? edgeTransitions : nullptr);
        if (cell.boundaryPaths[static_cast<std::size_t>(side)].empty()) {
          set_phase_front_failure(result.failure,
                                  SurfacePhaseFrontFailureReason::InvalidPeriodicChart,
                                  static_cast<int>(cell.id.index()), side);
          return result;
        }
      }
      const double tolerance =
          1.0e-7 * std::max({1.0, u1 - u0, stepV});
      if (validate_closed_boundary_paths(vertices, faces, cell.corners,
                                         cell.boundaryPaths, tolerance) !=
          CellRejectionReason::Accepted) {
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidPeriodicChart,
                                static_cast<int>(cell.id.index()));
        return result;
      }
      std::array<Eigen::RowVector3d, 4> positions =
          phase_front_corner_positions(vertices, faces, cell);
      Eigen::RowVector3d loopNormal = phase_front_loop_normal(positions);
      Eigen::RowVector3d expectedNormal = Eigen::RowVector3d::Zero();
      for (const auto &corner : cell.corners) expectedNormal += face_normal(vertices, faces, corner.face);
      if (!loopNormal.allFinite() || !expectedNormal.allFinite() ||
          loopNormal.squaredNorm() <= 1.0e-24 || expectedNormal.squaredNorm() <= 1.0e-24) {
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidCellOrientation,
                                static_cast<int>(cell.id.index()));
        return result;
      }
      if (loopNormal.dot(expectedNormal) < 0.0) {
        reverse_phase_front_cell_cycle(cell);
        positions = phase_front_corner_positions(vertices, faces, cell);
        loopNormal = phase_front_loop_normal(positions);
      }
      if (loopNormal.dot(expectedNormal) <= 0.0 ||
          !phase_front_cell_matches_region(cell, sourceAuthority, region)) {
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidCellOrientation,
                                static_cast<int>(cell.id.index()));
        return result;
      }
      cell.orientationValidated = true;

      for (int side = 0; side < 4; ++side) {
        SurfaceFrontEdge edge(region.id(), cell.id);
        edge.from = cell.corners[static_cast<std::size_t>(side)];
        edge.to = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
        edge.fromLattice = cell.lattice[static_cast<std::size_t>(side)];
        edge.toLattice = cell.lattice[static_cast<std::size_t>((side + 1) % 4)];
        const authority::LatticeTranslation delta =
            edge.toLattice.latticeCoordinate - edge.fromLattice.latticeCoordinate;
        edge.family = delta.x != 0 ? 0 : 1;
        edge.advanceSign = (delta.x + delta.y) >= 0 ? 1 : -1;
        edge.filledSide = side;
        const int edgeId = static_cast<int>(result.edges.size());
        result.edges.push_back(edge);
        const int a = canonical_node(edge.fromLattice.latticeCoordinate);
        const int b = canonical_node(edge.toLattice.latticeCoordinate);
        const auto ordered = std::minmax(a, b);
        const std::pair<int, int> key{ordered.first, ordered.second};
        const auto found = openEdges.find(key);
        if (found == openEdges.end()) {
          openEdges.emplace(key, EdgeOwner{edgeId});
        } else {
          auto &first = result.edges[static_cast<std::size_t>(found->second.edge)];
          auto &second = result.edges[static_cast<std::size_t>(edgeId)];
          if (first.filledCell == second.filledCell || first.family != second.family ||
              first.advanceSign == second.advanceSign) {
            set_phase_front_failure(result.failure,
                                    SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
                                    static_cast<int>(cell.id.index()), side);
            return result;
          }
          first.oppositeEdge = edgeId;
          second.oppositeEdge = found->second.edge;
          first.unfilledSide = 0;
          second.unfilledSide = 0;
          const bool periodic =
              first.fromLattice.latticeCoordinate.x !=
                  second.toLattice.latticeCoordinate.x ||
              first.toLattice.latticeCoordinate.x !=
                  second.fromLattice.latticeCoordinate.x;
          if (periodic) {
            first.boundaryKind = SurfaceFrontBoundaryKind::PeriodicCut;
            second.boundaryKind = SurfaceFrontBoundaryKind::PeriodicCut;
            first.periodicRelation = periodicHolonomy.id();
            second.periodicRelation = periodicHolonomy.id();
            first.route = periodicHolonomy.cutRoute();
            second.route = periodicHolonomy.cutRoute().reversed();
          }
          SurfaceFrontEvent event;
          event.kind = periodic ? SurfaceFrontEventKind::PeriodicFrontMerge
                                : SurfaceFrontEventKind::CompatibleFrontMerge;
          event.firstEdge = found->second.edge;
          event.secondEdge = edgeId;
          result.events.push_back(event);
          openEdges.erase(found);
        }
      }
      result.cells.push_back(std::move(cell));
    }
  }
  const auto cellIndexById = phase_front_cell_storage_index(result.cells);
  if (!cellIndexById) {
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
    return result;
  }
  for (const auto &[key, owner] : openEdges) {
    (void)key;
    auto &edge = result.edges[static_cast<std::size_t>(owner.edge)];
    if (edge.family != 0 ||
        (edge.fromLattice.latticeCoordinate.y != 0 &&
         edge.fromLattice.latticeCoordinate.y != result.gridV)) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
                              static_cast<int>(edge.filledCell.index()), owner.edge);
      return result;
    }
    const auto ownerCell = cellIndexById->find(edge.filledCell);
    if (ownerCell == cellIndexById->end() ||
        edge.filledSide < 0 || edge.filledSide >= 4) {
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority,
          static_cast<int>(edge.filledCell.index()), edge.filledSide);
      return result;
    }
    const auto boundaryReason = assign_open_front_boundary_authority(
        vertices, faces, options, sourceEdgeFaces, sourceMatchingIndices,
        result.cells[ownerCell->second]
            .boundaryPaths[static_cast<std::size_t>(edge.filledSide)],
        edge);
    if (boundaryReason != SurfacePhaseFrontFailureReason::None) {
      set_phase_front_failure(result.failure, boundaryReason,
                              static_cast<int>(edge.filledCell.index()),
                              edge.filledSide);
      return result;
    }
    edge.exterior = true;
    edge.unfilledSide = 0;
    SurfaceFrontEvent event;
    event.kind = SurfaceFrontEventKind::BoundaryTermination;
    event.firstEdge = owner.edge;
    result.events.push_back(event);
  }
  for (int edgeIndex = 0; edgeIndex < static_cast<int>(result.edges.size()); ++edgeIndex) {
    const auto &edge = result.edges[static_cast<std::size_t>(edgeIndex)];
    const bool hasTwin = edge.oppositeEdge >= 0;
    if (cellIndexById->find(edge.filledCell) == cellIndexById->end() || edge.unfilledSide != 0 || hasTwin == edge.exterior ||
        (hasTwin && (edge.oppositeEdge >= static_cast<int>(result.edges.size()) ||
                     result.edges[static_cast<std::size_t>(edge.oppositeEdge)].oppositeEdge != edgeIndex))) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
                              -1, edgeIndex);
      return result;
    }
  }
  result.succeeded = !result.cells.empty() &&
                     result.cells.size() == static_cast<std::size_t>(result.gridU * result.gridV);
  if (!result.succeeded) {
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidFinalCellState);
    return result;
  }
  result.disposition = SurfaceCellProducerDisposition::Produced;
  return result;
}


SurfacePhaseFrontBuildState build_curved_bounded_disk_phase_front_for_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const std::vector<authority::SourceFaceId> &activeFaces,
    const SurfaceTopologyRegion &region,
    const SourceTopologyRegions &sourceAuthority,
    const SurfaceCellTracingOptions &options,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontBuildState result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted ||
      surface_cell_tracing_detail::tracing_has_singularities(options) ||
      activeFaces.empty()) {
    return result;
  }
  SourceChartTransitionGraph canonicalSourceCharts(
      &faces, &sourceAuthority, options.hardFeatureEdges);
  if (!canonicalSourceCharts.available()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::MissingFaceState);
    return result;
  }
  if (vertices.rows() < 3 || faces.rows() < 1 || faces.cols() != 3 ||
      faceAxisX.rows() != faces.rows() || faceAxisY.rows() != faces.rows()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidInput);
    return result;
  }

  const auto incident = edge_faces(faces, activeFaces);
  const auto &fullIncident = sourceEdgeFaces;
  std::set<int> activeVertices;
  std::map<int, std::set<int>> vertexAdjacency;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidInput);
      return result;
    }
    const int face = *faceRow;
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      if (a < 0 || b < 0 || a >= vertices.rows() || b >= vertices.rows() ||
          a == b) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology,
            -1, -1, face);
        return result;
      }
      activeVertices.insert(a);
      activeVertices.insert(b);
      vertexAdjacency[a].insert(b);
      vertexAdjacency[b].insert(a);
    }
  }
  for (const auto &[key, pair] : incident) {
    (void)key;
    if (pair[0] < 0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
      return result;
    }
  }

  const int euler = static_cast<int>(activeVertices.size()) -
                    static_cast<int>(incident.size()) +
                    static_cast<int>(activeFaces.size());
  if (euler != 1) {
    return result;
  }

  // A disk producer owns only one connected sheet. Connectivity is proved on
  // the source-face dual graph with typed face identity; row enumeration is
  // projected only for direct matrix-edge lookup.
  const std::set<authority::SourceFaceId> activeFaceSet(activeFaces.begin(),
                                                        activeFaces.end());
  std::set<authority::SourceFaceId> visitedFaces;
  std::queue<authority::SourceFaceId> faceQueue;
  faceQueue.push(activeFaces.front());
  while (!faceQueue.empty()) {
    const authority::SourceFaceId faceId = faceQueue.front();
    faceQueue.pop();
    if (!visitedFaces.insert(faceId).second) continue;
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
      return result;
    }
    for (int corner = 0; corner < 3; ++corner) {
      const auto found = incident.find(local_edge_key(faces, *faceRow, corner));
      if (found == incident.end()) continue;
      for (const int adjacentRow : found->second) {
        if (adjacentRow < 0 || adjacentRow == *faceRow) continue;
        const auto adjacent = source_face_id(adjacentRow, faces.rows());
        if (!adjacent.has_value()) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
          return result;
        }
        if (activeFaceSet.count(*adjacent) != 0U &&
            visitedFaces.count(*adjacent) == 0U) {
          faceQueue.push(*adjacent);
        }
      }
    }
  }
  if (visitedFaces.size() != activeFaceSet.size()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
    return result;
  }

  std::set<authority::SourceEdgeTopologyKey> boundaryEdgeKeys;
  std::map<int, std::vector<int>> boundaryAdjacency;
  std::map<authority::SourceEdgeTopologyKey, authority::SourceFaceId> boundaryFace;
  for (const auto &[key, pair] : incident) {
    if (pair[1] >= 0) continue;
    const auto faceId = source_face_id(pair[0], faces.rows());
    if (!faceId.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
      return result;
    }
    const int face = pair[0];
    int localEdge = local_edge_for_key(faces, face, key);
    if (localEdge < 0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology,
          -1, -1, face);
      return result;
    }
    const int a = faces(face, (localEdge + 1) % 3);
    const int b = faces(face, (localEdge + 2) % 3);
    boundaryEdgeKeys.insert(key);
    boundaryAdjacency[a].push_back(b);
    boundaryAdjacency[b].push_back(a);
    boundaryFace.emplace(key, *faceId);

    // A local sheet boundary must be a genuine source boundary or an
    // authoritative hard-feature/source-sheet rail.  A hidden cut through an
    // ordinary same-sheet source edge is not a bounded-disk chart boundary.
    const auto full = fullIncident.find(key);
    if (full == fullIncident.end()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology,
          -1, -1, face);
      return result;
    }
    if (!source_edge_is_authoritative_local_boundary(
            options, faces.rows(), face, full->second, key)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology,
          -1, -1, face);
      return result;
    }
  }
  if (boundaryEdgeKeys.size() < 4U || boundaryAdjacency.size() < 4U) {
    return result;
  }
  for (auto &[vertex, neighbors] : boundaryAdjacency) {
    (void)vertex;
    std::sort(neighbors.begin(), neighbors.end());
    neighbors.erase(std::unique(neighbors.begin(), neighbors.end()), neighbors.end());
    if (neighbors.size() != 2U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology,
          -1, -1, -1, -1, vertex);
      return result;
    }
  }

  const auto vertex_geometry_key = [&](const int vertex) {
    return std::array<double, 3>{vertices(vertex, 0), vertices(vertex, 1),
                                 vertices(vertex, 2)};
  };
  int boundaryStart = -1;
  std::array<double, 3> startKey{
      std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity()};
  bool ambiguousStart = false;
  for (const auto &[vertex, neighbors] : boundaryAdjacency) {
    (void)neighbors;
    const auto key = vertex_geometry_key(vertex);
    if (key < startKey) {
      startKey = key;
      boundaryStart = vertex;
      ambiguousStart = false;
    } else if (key == startKey && vertex != boundaryStart) {
      ambiguousStart = true;
    }
  }
  if (boundaryStart < 0 || ambiguousStart) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
    return result;
  }

  const auto walk_boundary = [&](const int firstNeighbor) {
    std::vector<int> cycle;
    cycle.reserve(boundaryAdjacency.size());
    cycle.push_back(boundaryStart);
    int previous = boundaryStart;
    int current = firstNeighbor;
    while (current != boundaryStart && cycle.size() <= boundaryAdjacency.size()) {
      cycle.push_back(current);
      const auto found = boundaryAdjacency.find(current);
      if (found == boundaryAdjacency.end() || found->second.size() != 2U) {
        return std::vector<int>{};
      }
      const int next = found->second[0] == previous ? found->second[1]
                                                    : found->second[0];
      previous = current;
      current = next;
    }
    if (current != boundaryStart || cycle.size() != boundaryAdjacency.size()) {
      return std::vector<int>{};
    }
    return cycle;
  };
  const auto &startNeighbors = boundaryAdjacency[boundaryStart];
  std::vector<int> cycleA = walk_boundary(startNeighbors[0]);
  std::vector<int> cycleB = walk_boundary(startNeighbors[1]);
  if (cycleA.empty() || cycleB.empty()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
    return result;
  }
  const auto follows_source_orientation = [&](const std::vector<int> &cycle) {
    for (std::size_t index = 0; index < cycle.size(); ++index) {
      const int a = cycle[index];
      const int b = cycle[(index + 1U) % cycle.size()];
      const authority::SourceEdgeTopologyKey key = edge_key(a, b, source_vertex_extent(faces));
      const auto foundFace = boundaryFace.find(key);
      if (foundFace == boundaryFace.end()) return false;
      const auto faceRow = source_face_row(foundFace->second, faces.rows());
      if (!faceRow.has_value()) return false;
      const int face = *faceRow;
      bool oriented = false;
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(face, corner) == a && faces(face, (corner + 1) % 3) == b) {
          oriented = true;
          break;
        }
      }
      if (!oriented) return false;
    }
    return true;
  };
  const bool orientedA = follows_source_orientation(cycleA);
  const bool orientedB = follows_source_orientation(cycleB);
  if (orientedA == orientedB) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
    return result;
  }
  std::vector<int> boundaryCycle = orientedA ? std::move(cycleA) : std::move(cycleB);
  result.disposition = SurfaceCellProducerDisposition::Rejected;

  // Establish one global 4-RoSy gauge by reciprocal source-edge transport.
  // The root face is chosen by geometric triangle identity, never face-row ID.
  const auto face_geometry_key = [&](const int face) {
    std::array<std::array<double, 3>, 3> points{};
    for (int corner = 0; corner < 3; ++corner) {
      points[static_cast<std::size_t>(corner)] =
          vertex_geometry_key(faces(face, corner));
    }
    std::sort(points.begin(), points.end());
    return points;
  };
  std::optional<authority::SourceFaceId> rootFace;
  std::array<std::array<double, 3>, 3> rootKey{};
  bool ambiguousRoot = false;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
      return result;
    }
    const auto key = face_geometry_key(*faceRow);
    if (!rootFace.has_value() || key < rootKey) {
      rootFace = faceId;
      rootKey = key;
      ambiguousRoot = false;
    } else if (key == rootKey && faceId != *rootFace) {
      ambiguousRoot = true;
    }
  }
  if (!rootFace.has_value() || ambiguousRoot) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology);
    return result;
  }

  const auto &matchingIndices = sourceMatchingIndices;
  const bool hasTransitions = edgeTransitions != nullptr && !edgeTransitions->empty();
  const bool hasMatching = edgeMatching != nullptr && edgeMatching->size() > 0;
  const bool hasEffort = edgeEffort != nullptr && edgeEffort->size() > 0;
  const auto *effectiveTransitions = hasTransitions ? edgeTransitions : nullptr;
  const auto *effectiveMatching = hasMatching ? edgeMatching : nullptr;
  const auto *effectiveEffort = hasEffort ? edgeEffort : nullptr;
  const EdgeTransitionLookup transitionLookup =
      authoritative_edge_transition_lookup(
          options.fieldTransportAtlas,
          hasTransitions ? edgeTransitions : nullptr,
          source_vertex_extent(faces));
  if (transitionLookup.duplicate) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
    return result;
  }

  struct DualStep {
    authority::SourceFaceId face;
    authority::SourceEdgeTopologyKey edge;
  };
  std::map<authority::SourceFaceId, std::vector<DualStep>> dual;
  for (const authority::SourceFaceId faceId : activeFaces) dual[faceId] = {};
  for (const auto &[key, pair] : incident) {
    if (pair[0] < 0 || pair[1] < 0) continue;
    const auto firstFace = source_face_id(pair[0], faces.rows());
    const auto secondFace = source_face_id(pair[1], faces.rows());
    if (!firstFace.has_value() || !secondFace.has_value() ||
        activeFaceSet.count(*firstFace) == 0U ||
        activeFaceSet.count(*secondFace) == 0U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
      return result;
    }
    dual[*firstFace].push_back(DualStep{*secondFace, key});
    dual[*secondFace].push_back(DualStep{*firstFace, key});
  }
  for (const authority::SourceFaceId faceId : activeFaces) {
    auto &neighbors = dual[faceId];
    std::sort(neighbors.begin(), neighbors.end(), [&](const DualStep &a,
                                                      const DualStep &b) {
      const auto aRow = source_face_row(a.face, faces.rows());
      const auto bRow = source_face_row(b.face, faces.rows());
      if (!aRow.has_value() || !bRow.has_value()) return a.face < b.face;
      const auto ak = face_geometry_key(*aRow);
      const auto bk = face_geometry_key(*bRow);
      if (ak != bk) return ak < bk;
      return a.edge < b.edge;
    });
  }

  const auto rootFaceRow = source_face_row(*rootFace, faces.rows());
  if (!rootFaceRow.has_value()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
    return result;
  }
  std::vector<int> faceBranchRotation(static_cast<std::size_t>(faces.rows()), -1);
  faceBranchRotation[static_cast<std::size_t>(*rootFaceRow)] = 0;
  std::queue<authority::SourceFaceId> pending;
  pending.push(*rootFace);
  while (!pending.empty()) {
    const authority::SourceFaceId sourceFace = pending.front();
    pending.pop();
    const auto sourceFaceRow = source_face_row(sourceFace, faces.rows());
    if (!sourceFaceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
      return result;
    }
    const int sourceBranch =
        faceBranchRotation[static_cast<std::size_t>(*sourceFaceRow)];
    int sourceFamily = 0;
    int sourceSign = 1;
    family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
    const Eigen::RowVector3d sourceDirection = project_tangent(
        axis_for_family(faceAxisX, faceAxisY, *sourceFaceRow, sourceFamily,
                        sourceSign),
        face_normal(vertices, faces, *sourceFaceRow));
    if (sourceDirection.squaredNorm() == 0.0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
          -1, -1, *sourceFaceRow);
      return result;
    }
    for (const DualStep &neighbor : dual[sourceFace]) {
      const auto neighborRow = source_face_row(neighbor.face, faces.rows());
      if (!neighborRow.has_value()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
        return result;
      }
      const BranchTransitionResult forward = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, neighbor.edge, *sourceFaceRow, *neighborRow,
          sourceFamily, sourceSign, sourceDirection, effectiveMatching,
          effectiveEffort, effectiveTransitions);
      if (!forward.valid) {
        int sourceEdge = -1;
        source_edge_provenance(neighbor.edge, sourceEdgeFaces,
                               sourceMatchingIndices, transitionLookup,
                               effectiveTransitions, sourceEdge);
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
            -1, -1, *sourceFaceRow, *neighborRow, -1, sourceEdge);
        return result;
      }
      const int targetBranch =
          branch_from_family_sign(forward.family, forward.sign);
      int &stored = faceBranchRotation[static_cast<std::size_t>(*neighborRow)];
      if (stored < 0) {
        stored = targetBranch;
        pending.push(neighbor.face);
      } else if (stored != targetBranch) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
            -1, -1, *sourceFaceRow, *neighborRow);
        return result;
      }
    }
  }
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
      return result;
    }
    const int face = *faceRow;
    if (faceBranchRotation[static_cast<std::size_t>(face)] < 0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
          -1, -1, face);
      return result;
    }
  }

  // Validate reciprocal transport for both lattice families on every interior
  // source edge.  This proves the simply-connected chart has no hidden branch
  // defect before boundary phase or parameterization is considered.
  for (const auto &[key, pair] : incident) {
    if (pair[0] < 0 || pair[1] < 0) continue;
    for (const int globalBranch : {0, 1}) {
      const int sourceBranch = normalized_branch(
          faceBranchRotation[static_cast<std::size_t>(pair[0])] + globalBranch);
      int sourceFamily = 0;
      int sourceSign = 1;
      family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
      const Eigen::RowVector3d sourceDirection = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, pair[0], sourceFamily,
                          sourceSign),
          face_normal(vertices, faces, pair[0]));
      const BranchTransitionResult forward = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, key, pair[0], pair[1], sourceFamily, sourceSign,
          sourceDirection, effectiveMatching, effectiveEffort,
          effectiveTransitions);
      const int expectedTargetBranch = normalized_branch(
          faceBranchRotation[static_cast<std::size_t>(pair[1])] + globalBranch);
      if (!forward.valid ||
          branch_from_family_sign(forward.family, forward.sign) !=
              expectedTargetBranch) {
        int sourceEdge = -1;
        source_edge_provenance(key, sourceEdgeFaces, sourceMatchingIndices,
                               transitionLookup, effectiveTransitions,
                               sourceEdge);
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
            -1, -1, pair[0], pair[1], -1, sourceEdge);
        return result;
      }
      int targetFamily = 0;
      int targetSign = 1;
      family_sign_from_branch(expectedTargetBranch, targetFamily, targetSign);
      const Eigen::RowVector3d targetDirection = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, pair[1], targetFamily,
                          targetSign),
          face_normal(vertices, faces, pair[1]));
      const BranchTransitionResult reverse = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, key, pair[1], pair[0], targetFamily, targetSign,
          targetDirection, effectiveMatching, effectiveEffort,
          effectiveTransitions);
      if (!reverse.valid ||
          branch_from_family_sign(reverse.family, reverse.sign) != sourceBranch ||
          normalized_branch(forward.matching + reverse.matching) != 0) {
        int sourceEdge = -1;
        source_edge_provenance(key, sourceEdgeFaces, sourceMatchingIndices,
                               transitionLookup, effectiveTransitions,
                               sourceEdge);
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
            -1, -1, pair[0], pair[1], -1, sourceEdge);
        return result;
      }
    }
  }

  std::vector<int> boundaryBranches(boundaryCycle.size(), -1);
  constexpr double kBoundaryAlignment = 0.7;
  for (std::size_t index = 0; index < boundaryCycle.size(); ++index) {
    const int a = boundaryCycle[index];
    const int b = boundaryCycle[(index + 1U) % boundaryCycle.size()];
    const authority::SourceEdgeTopologyKey key = edge_key(a, b, source_vertex_extent(faces));
    const auto foundFace = boundaryFace.find(key);
    if (foundFace == boundaryFace.end()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
      return result;
    }
    const auto faceRow = source_face_row(foundFace->second, faces.rows());
    if (!faceRow.has_value()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
      return result;
    }
    const int face = *faceRow;
    const Eigen::RowVector3d edgeDirection = project_tangent(
        row3(vertices, b) - row3(vertices, a), face_normal(vertices, faces, face));
    if (edgeDirection.squaredNorm() == 0.0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase,
          -1, -1, face);
      return result;
    }
    double bestAlignment = -std::numeric_limits<double>::infinity();
    double secondAlignment = -std::numeric_limits<double>::infinity();
    int bestGlobalBranch = -1;
    for (int localBranch = 0; localBranch < 4; ++localBranch) {
      int family = 0;
      int sign = 1;
      family_sign_from_branch(localBranch, family, sign);
      const Eigen::RowVector3d fieldDirection = project_tangent(
          axis_for_family(faceAxisX, faceAxisY, face, family, sign),
          face_normal(vertices, faces, face));
      if (fieldDirection.squaredNorm() == 0.0) continue;
      const double alignment = fieldDirection.dot(edgeDirection);
      if (alignment > bestAlignment) {
        secondAlignment = bestAlignment;
        bestAlignment = alignment;
        bestGlobalBranch = normalized_branch(
            localBranch - faceBranchRotation[static_cast<std::size_t>(face)]);
      } else if (alignment > secondAlignment) {
        secondAlignment = alignment;
      }
    }
    const double ambiguityTolerance =
        256.0 * std::numeric_limits<double>::epsilon() *
        std::max(1.0, std::abs(bestAlignment));
    if (bestGlobalBranch < 0 || bestAlignment < kBoundaryAlignment ||
        std::abs(bestAlignment - secondAlignment) <= ambiguityTolerance) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase,
          -1, -1, face);
      return result;
    }
    boundaryBranches[index] = bestGlobalBranch;
  }

  const auto rebuild_run_starts = [&](const std::vector<int> &branches) {
    std::vector<int> starts;
    for (int index = 0; index < static_cast<int>(branches.size()); ++index) {
      const int previous =
          (index + static_cast<int>(branches.size()) - 1) %
          static_cast<int>(branches.size());
      if (branches[static_cast<std::size_t>(index)] !=
          branches[static_cast<std::size_t>(previous)]) {
        starts.push_back(index);
      }
    }
    return starts;
  };

  std::vector<int> runStarts = rebuild_run_starts(boundaryBranches);
  if (runStarts.empty()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
    return result;
  }
  int canonicalRun = -1;
  std::array<double, 3> canonicalRunKey{
      std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity()};
  bool ambiguousRun = false;
  for (const int start : runStarts) {
    const auto key = vertex_geometry_key(
        boundaryCycle[static_cast<std::size_t>(start)]);
    if (key < canonicalRunKey) {
      canonicalRunKey = key;
      canonicalRun = start;
      ambiguousRun = false;
    } else if (key == canonicalRunKey && start != canonicalRun) {
      ambiguousRun = true;
    }
  }
  if (canonicalRun < 0 || ambiguousRun) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
    return result;
  }
  std::rotate(boundaryCycle.begin(),
              boundaryCycle.begin() + canonicalRun, boundaryCycle.end());
  std::rotate(boundaryBranches.begin(),
              boundaryBranches.begin() + canonicalRun, boundaryBranches.end());
  runStarts = rebuild_run_starts(boundaryBranches);
  if (runStarts.empty() || runStarts.front() != 0) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
    return result;
  }

  SurfaceBoundedDiskBoundaryPhase boundaryPhase(region.id());
  boundaryPhase.chartUBranch = boundaryBranches.front();
  boundaryPhase.runs.reserve(runStarts.size());

  double cumulativeBoundaryLength = 0.0;
  for (int runIndex = 0; runIndex < static_cast<int>(runStarts.size());
       ++runIndex) {
    const int begin = runStarts[static_cast<std::size_t>(runIndex)];
    const int end = runIndex + 1 < static_cast<int>(runStarts.size())
                        ? runStarts[static_cast<std::size_t>(runIndex + 1)]
                        : static_cast<int>(boundaryCycle.size());
    if (end <= begin) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
      return result;
    }

    SurfaceBoundedDiskBoundaryRun run;
    run.branch = boundaryBranches[static_cast<std::size_t>(begin)];
    family_sign_from_branch(run.branch, run.family, run.sign);
    run.startVertex = boundaryCycle[static_cast<std::size_t>(begin)];
    run.cumulativeIntrinsicLength = cumulativeBoundaryLength;
    for (int index = begin; index <= end; ++index) {
      const int wrapped = index % static_cast<int>(boundaryCycle.size());
      const int vertex = boundaryCycle[static_cast<std::size_t>(wrapped)];
      if (run.sourceVertices.empty() || run.sourceVertices.back() != vertex) {
        run.sourceVertices.push_back(vertex);
      }
      if (index == end) continue;
      const int nextWrapped =
          (wrapped + 1) % static_cast<int>(boundaryCycle.size());
      const int a = boundaryCycle[static_cast<std::size_t>(wrapped)];
      const int b = boundaryCycle[static_cast<std::size_t>(nextWrapped)];
      const authority::SourceEdgeTopologyKey edgeTopology = edge_key(a, b, source_vertex_extent(faces));
      const auto foundFace = boundaryFace.find(edgeTopology);
      const auto foundFull = fullIncident.find(edgeTopology);
      if (foundFace == boundaryFace.end() || foundFull == fullIncident.end()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure,
            SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
        return result;
      }
      const auto faceRow = source_face_row(foundFace->second, faces.rows());
      if (!faceRow.has_value()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure,
            SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
        return result;
      }
      run.sourceFaces.push_back(*faceRow);
      run.sourceEdgeTopology.push_back(edgeTopology);

      const auto &fullPair = foundFull->second;
      int fullCount = 0;
      for (const int incidentFace : fullPair) {
        if (incidentFace >= 0) ++fullCount;
      }
      SurfaceBoundedDiskBoundaryEdgeAuthority authority;
      authority.sourceBoundary = fullCount == 1;
      authority.hardFeature =
          options.hardFeatureEdges.count(edgeTopology) != 0U;
      authority.sourceSheet = false;
      run.edgeAuthority.push_back(authority);

      const double edgeLength = (row3(vertices, b) - row3(vertices, a)).norm();
      if (!(edgeLength > 0.0) || !std::isfinite(edgeLength)) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure,
            SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase,
            -1, -1, *faceRow);
        return result;
      }
      run.intrinsicLength += edgeLength;
    }
    if (run.sourceVertices.size() < 2U || run.sourceFaces.empty() ||
        run.sourceEdgeTopology.size() != run.sourceFaces.size() ||
        run.edgeAuthority.size() != run.sourceFaces.size() ||
        !(run.intrinsicLength > 0.0) || !std::isfinite(run.intrinsicLength)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
      return result;
    }
    run.endVertex = run.sourceVertices.back();
    cumulativeBoundaryLength += run.intrinsicLength;
    boundaryPhase.runs.push_back(std::move(run));
  }
  boundaryPhase.totalIntrinsicLength = cumulativeBoundaryLength;

  for (std::size_t runIndex = 0; runIndex < boundaryPhase.runs.size(); ++runIndex) {
    auto &run = boundaryPhase.runs[runIndex];
    const auto &next =
        boundaryPhase.runs[(runIndex + 1U) % boundaryPhase.runs.size()];
    const int delta = normalized_branch(next.branch - run.branch);
    if (delta == 1) {
      run.signedQuarterTurnToNext = 1;
    } else if (delta == 3) {
      run.signedQuarterTurnToNext = -1;
    } else {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryTurn,
          -1, -1, -1, -1, run.endVertex);
      return result;
    }
    boundaryPhase.signedQuarterTurnSum += run.signedQuarterTurnToNext;
  }
  if (boundaryPhase.signedQuarterTurnSum != 4) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure,
        SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryIndex);
    return result;
  }
  boundaryPhase.rectangular = boundaryPhase.runs.size() == 4U &&
      std::all_of(boundaryPhase.runs.begin(), boundaryPhase.runs.end(),
                  [](const SurfaceBoundedDiskBoundaryRun &run) {
                    return run.signedQuarterTurnToNext == 1;
                  });

  // Canonical boundary identity is independent of source face-row enumeration.
  // Raw source IDs remain provenance only; geometry and exact source-edge
  // topology determine the stable run sequence already fixed above.
  std::uint64_t boundaryHash = 1469598103934665603ULL;
  const auto consume_boundary_hash = [&](const std::uint64_t value) {
    boundaryHash ^= value;
    boundaryHash *= 1099511628211ULL;
  };
  const auto consume_boundary_i64 = [&](const std::int64_t value) {
    consume_boundary_hash(static_cast<std::uint64_t>(value));
  };
  consume_boundary_i64(static_cast<std::int64_t>(
      boundaryPhase.sourceTopologyRegion.index()));
  consume_boundary_i64(boundaryPhase.chartUBranch);
  consume_boundary_i64(boundaryPhase.signedQuarterTurnSum);
  consume_boundary_hash(boundaryPhase.runs.size());
  for (const auto &run : boundaryPhase.runs) {
    consume_boundary_i64(run.branch);
    consume_boundary_i64(run.signedQuarterTurnToNext);
    consume_boundary_i64(static_cast<std::int64_t>(
        std::llround(run.intrinsicLength * 1.0e12)));
    for (const int vertex : {run.startVertex, run.endVertex}) {
      const auto key = vertex_geometry_key(vertex);
      for (const double coordinate : key) {
        consume_boundary_i64(static_cast<std::int64_t>(
            std::llround(coordinate * 1.0e12)));
      }
    }
    consume_boundary_hash(run.sourceEdgeTopology.size());
    for (const authority::SourceEdgeTopologyKey &edgeTopology : run.sourceEdgeTopology) {
      consume_boundary_i64(edgeTopology.first().index());
      consume_boundary_i64(edgeTopology.second().index());
    }
    for (const auto &authority : run.edgeAuthority) {
      consume_boundary_i64(authority.sourceBoundary ? 1 : 0);
      consume_boundary_i64(authority.hardFeature ? 1 : 0);
      consume_boundary_i64(authority.sourceSheet ? 1 : 0);
    }
  }
  boundaryPhase.structuralHash = boundaryHash;
  result.boundedDiskBoundaryPhases.push_back(std::move(boundaryPhase));
  SurfaceBoundedDiskBoundaryPhase &phaseRecord =
      result.boundedDiskBoundaryPhases.back();
  const int chartUBranch = phaseRecord.chartUBranch;

  std::map<int, Eigen::Vector2d> vertexUv;
  double width = 0.0;
  double height = 0.0;
  double chartAreaScale = 1.0;
  if (phaseRecord.rectangular) {
    // Preserve the established four-run rectangle semantics exactly: opposite
    // intrinsic side lengths are averaged before boundary parameterization.
    width = 0.5 * (phaseRecord.runs[0].intrinsicLength +
                   phaseRecord.runs[2].intrinsicLength);
    height = 0.5 * (phaseRecord.runs[1].intrinsicLength +
                    phaseRecord.runs[3].intrinsicLength);
    if (!(width > 0.0) || !(height > 0.0) || !std::isfinite(width) ||
        !std::isfinite(height)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
      return result;
    }
    const std::array<Eigen::Vector2d, 4> sideStart{
        Eigen::Vector2d(0.0, 0.0), Eigen::Vector2d(width, 0.0),
        Eigen::Vector2d(width, height), Eigen::Vector2d(0.0, height)};
    const std::array<Eigen::Vector2d, 4> sideEnd{
        Eigen::Vector2d(width, 0.0), Eigen::Vector2d(width, height),
        Eigen::Vector2d(0.0, height), Eigen::Vector2d(0.0, 0.0)};
    for (int side = 0; side < 4; ++side) {
      auto &run = phaseRecord.runs[static_cast<std::size_t>(side)];
      run.chartStart = sideStart[static_cast<std::size_t>(side)];
      run.chartEnd = sideEnd[static_cast<std::size_t>(side)];
      double cumulative = 0.0;
      for (std::size_t index = 0; index < run.sourceVertices.size(); ++index) {
        if (index > 0) {
          cumulative +=
              (row3(vertices, run.sourceVertices[index]) -
               row3(vertices, run.sourceVertices[index - 1U]))
                  .norm();
        }
        const double alpha = std::clamp(cumulative / run.intrinsicLength,
                                        0.0, 1.0);
        const Eigen::Vector2d uv = run.chartStart +
                                   alpha * (run.chartEnd - run.chartStart);
        const int vertex = run.sourceVertices[index];
        const auto existing = vertexUv.find(vertex);
        if (existing != vertexUv.end() &&
            (existing->second - uv).norm() >
                1.0e-10 * std::max({1.0, width, height})) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
              -1, -1, -1, -1, vertex);
          return result;
        }
        vertexUv[vertex] = uv;
      }
    }
    phaseRecord.polygonClosed = true;
    chartAreaScale = std::max(1.0, width * height);
  } else {
    // Develop the source-attached run sequence into its intrinsic orthogonal
    // polygon.  No run is inserted, deleted, split, merged, or length-corrected.
    std::vector<Eigen::Vector2d> polygonCorners(
        phaseRecord.runs.size() + 1U, Eigen::Vector2d::Zero());
    const auto chart_direction = [&](const int branch) {
      switch (normalized_branch(branch - chartUBranch)) {
      case 0: return Eigen::Vector2d(1.0, 0.0);
      case 1: return Eigen::Vector2d(0.0, 1.0);
      case 2: return Eigen::Vector2d(-1.0, 0.0);
      default: return Eigen::Vector2d(0.0, -1.0);
      }
    };
    for (std::size_t runIndex = 0; runIndex < phaseRecord.runs.size(); ++runIndex) {
      auto &run = phaseRecord.runs[runIndex];
      run.chartStart = polygonCorners[runIndex];
      run.chartEnd = run.chartStart +
                     run.intrinsicLength * chart_direction(run.branch);
      polygonCorners[runIndex + 1U] = run.chartEnd;
    }
    const double polygonTolerance =
        1.0e-10 * std::max(1.0, phaseRecord.totalIntrinsicLength);
    if ((polygonCorners.back() - polygonCorners.front()).norm() >
        polygonTolerance) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
      return result;
    }
    polygonCorners.back() = polygonCorners.front();
    phaseRecord.runs.back().chartEnd = polygonCorners.front();
    phaseRecord.polygonClosed = true;

    const auto cross2 = [](const Eigen::Vector2d &a,
                           const Eigen::Vector2d &b) {
      return a.x() * b.y() - a.y() * b.x();
    };
    double signedDoubleArea = 0.0;
    Eigen::Vector2d minimum = polygonCorners.front();
    Eigen::Vector2d maximum = polygonCorners.front();
    for (std::size_t index = 0; index < phaseRecord.runs.size(); ++index) {
      signedDoubleArea +=
          cross2(polygonCorners[index], polygonCorners[index + 1U]);
      minimum = minimum.cwiseMin(polygonCorners[index]);
      maximum = maximum.cwiseMax(polygonCorners[index]);
    }
    width = maximum.x() - minimum.x();
    height = maximum.y() - minimum.y();
    chartAreaScale = std::max(1.0, width * height);
    if (!(signedDoubleArea > 1.0e-14 * chartAreaScale) ||
        !(width > 0.0) || !(height > 0.0) || !std::isfinite(width) ||
        !std::isfinite(height)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
      return result;
    }

    const auto point_on_segment = [&](const Eigen::Vector2d &point,
                                      const Eigen::Vector2d &a,
                                      const Eigen::Vector2d &b) {
      const Eigen::Vector2d ab = b - a;
      const Eigen::Vector2d ap = point - a;
      if (std::abs(cross2(ab, ap)) > polygonTolerance) return false;
      return point.x() >= std::min(a.x(), b.x()) - polygonTolerance &&
             point.x() <= std::max(a.x(), b.x()) + polygonTolerance &&
             point.y() >= std::min(a.y(), b.y()) - polygonTolerance &&
             point.y() <= std::max(a.y(), b.y()) + polygonTolerance;
    };
    const auto segments_intersect = [&](const Eigen::Vector2d &a,
                                        const Eigen::Vector2d &b,
                                        const Eigen::Vector2d &c,
                                        const Eigen::Vector2d &d) {
      const double abC = cross2(b - a, c - a);
      const double abD = cross2(b - a, d - a);
      const double cdA = cross2(d - c, a - c);
      const double cdB = cross2(d - c, b - c);
      if (((abC > polygonTolerance && abD < -polygonTolerance) ||
           (abC < -polygonTolerance && abD > polygonTolerance)) &&
          ((cdA > polygonTolerance && cdB < -polygonTolerance) ||
           (cdA < -polygonTolerance && cdB > polygonTolerance))) {
        return true;
      }
      return (std::abs(abC) <= polygonTolerance && point_on_segment(c, a, b)) ||
             (std::abs(abD) <= polygonTolerance && point_on_segment(d, a, b)) ||
             (std::abs(cdA) <= polygonTolerance && point_on_segment(a, c, d)) ||
             (std::abs(cdB) <= polygonTolerance && point_on_segment(b, c, d));
    };
    for (std::size_t first = 0; first < phaseRecord.runs.size(); ++first) {
      for (std::size_t second = first + 1U;
           second < phaseRecord.runs.size(); ++second) {
        const bool adjacent = second == first + 1U ||
            (first == 0U && second + 1U == phaseRecord.runs.size());
        if (adjacent) continue;
        if (segments_intersect(polygonCorners[first], polygonCorners[first + 1U],
                               polygonCorners[second],
                               polygonCorners[second + 1U])) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
          return result;
        }
      }
    }

    const double uvTolerance =
        1.0e-10 * std::max({1.0, width, height});
    for (auto &run : phaseRecord.runs) {
      double cumulative = 0.0;
      for (std::size_t index = 0; index < run.sourceVertices.size(); ++index) {
        if (index > 0) {
          cumulative +=
              (row3(vertices, run.sourceVertices[index]) -
               row3(vertices, run.sourceVertices[index - 1U]))
                  .norm();
        }
        const double alpha = std::clamp(cumulative / run.intrinsicLength,
                                        0.0, 1.0);
        const Eigen::Vector2d uv = run.chartStart +
                                   alpha * (run.chartEnd - run.chartStart);
        const int vertex = run.sourceVertices[index];
        const auto existing = vertexUv.find(vertex);
        if (existing != vertexUv.end() &&
            (existing->second - uv).norm() > uvTolerance) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
              -1, -1, -1, -1, vertex);
          return result;
        }
        vertexUv[vertex] = uv;
      }
    }
  }

  std::vector<int> interiorVertices;
  for (const int vertex : activeVertices) {
    if (boundaryAdjacency.count(vertex) == 0U) interiorVertices.push_back(vertex);
  }
  std::sort(interiorVertices.begin(), interiorVertices.end());
  if (!interiorVertices.empty()) {
    std::map<int, int> interiorIndex;
    for (int row = 0; row < static_cast<int>(interiorVertices.size()); ++row) {
      interiorIndex[interiorVertices[static_cast<std::size_t>(row)]] = row;
    }
    std::vector<Eigen::Triplet<double>> triplets;
    Eigen::MatrixXd rhs =
        Eigen::MatrixXd::Zero(static_cast<int>(interiorVertices.size()), 2);
    for (int row = 0; row < static_cast<int>(interiorVertices.size()); ++row) {
      const int vertex = interiorVertices[static_cast<std::size_t>(row)];
      const auto adjacent = vertexAdjacency.find(vertex);
      if (adjacent == vertexAdjacency.end() || adjacent->second.empty()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
            -1, -1, -1, -1, vertex);
        return result;
      }
      double degree = 0.0;
      for (const int neighbor : adjacent->second) {
        if (activeVertices.count(neighbor) == 0U) continue;
        degree += 1.0;
        const auto interiorNeighbor = interiorIndex.find(neighbor);
        if (interiorNeighbor != interiorIndex.end()) {
          triplets.emplace_back(row, interiorNeighbor->second, -1.0);
        } else {
          const auto boundaryUv = vertexUv.find(neighbor);
          if (boundaryUv == vertexUv.end()) {
            result.disposition = SurfaceCellProducerDisposition::Rejected;
            set_phase_front_failure(
                result.failure,
                SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
                -1, -1, -1, -1, neighbor);
            return result;
          }
          rhs.row(row) += boundaryUv->second.transpose();
        }
      }
      if (!(degree > 0.0)) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
            -1, -1, -1, -1, vertex);
        return result;
      }
      triplets.emplace_back(row, row, degree);
    }
    Eigen::SparseMatrix<double> laplacian(
        static_cast<int>(interiorVertices.size()),
        static_cast<int>(interiorVertices.size()));
    laplacian.setFromTriplets(triplets.begin(), triplets.end());
    Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> solver;
    solver.compute(laplacian);
    if (solver.info() != Eigen::Success) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
      return result;
    }
    const Eigen::MatrixXd solution = solver.solve(rhs);
    if (solver.info() != Eigen::Success || !solution.allFinite()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
      return result;
    }
    for (int row = 0; row < static_cast<int>(interiorVertices.size()); ++row) {
      vertexUv[interiorVertices[static_cast<std::size_t>(row)]] =
          solution.row(row).transpose();
    }
  }
  if (vertexUv.size() != activeVertices.size()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
    return result;
  }

  std::vector<PeriodicChartTriangle> chartTriangles;
  chartTriangles.reserve(activeFaces.size());
  const double chartAreaTolerance = 1.0e-14 * chartAreaScale;
  for (const authority::SourceFaceId faceId : activeFaces) {
    const auto faceRow = source_face_row(faceId, faces.rows());
    if (!faceRow.has_value()) return result;
    const int face = *faceRow;
    PeriodicChartTriangle triangle(faceId);
    triangle.vertices = canonical_face_vertices(faces, face);
    for (int corner = 0; corner < 3; ++corner) {
      const auto found = vertexUv.find(faces(face, corner));
      if (found == vertexUv.end()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
            -1, -1, face);
        return result;
      }
      triangle.uv[static_cast<std::size_t>(corner)] = found->second;
    }
    const Eigen::Vector2d ab = triangle.uv[1] - triangle.uv[0];
    const Eigen::Vector2d ac = triangle.uv[2] - triangle.uv[0];
    const double signedDoubleArea = ab.x() * ac.y() - ab.y() * ac.x();
    if (!(signedDoubleArea > chartAreaTolerance) ||
        !std::isfinite(signedDoubleArea)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
          -1, -1, face);
      return result;
    }
    chartTriangles.push_back(std::move(triangle));
  }
  std::sort(chartTriangles.begin(), chartTriangles.end(),
            [](const PeriodicChartTriangle &a, const PeriodicChartTriangle &b) {
              return a.vertices < b.vertices;
            });
  phaseRecord.chartConstructed = true;

  // Polygonal phase/chart authority is now explicit and validated.  Lattice
  // clipping/pairing for a non-rectangular domain remains a distinct deeper
  // front-construction contract; fail there rather than coercing the polygon
  // back to a rectangle or emitting partial cells.
  if (!phaseRecord.rectangular) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure,
        SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing);
    return result;
  }

  double target = options.defaultTargetSize;
  if (targetSize.size() > 0 && targetSize.allFinite() &&
      targetSize.minCoeff() > 0.0) {
    target = targetSize.mean();
  }
  if (!(target > 0.0) || !std::isfinite(target)) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidTargetSize);
    return result;
  }
  result.gridU = std::max(1, static_cast<int>(std::llround(width / target)));
  result.gridV = std::max(1, static_cast<int>(std::llround(height / target)));
  const double stepU = width / static_cast<double>(result.gridU);
  const double stepV = height / static_cast<double>(result.gridV);
  if (!(stepU > 0.0) || !(stepV > 0.0)) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidGridStep);
    return result;
  }

  const int columns = result.gridU + 1;
  const int rows = result.gridV + 1;
  std::vector<SurfaceTracePoint> points(static_cast<std::size_t>(columns * rows));
  const auto node_index = [columns](const int u, const int v) {
    return v * columns + u;
  };
  for (int v = 0; v < rows; ++v) {
    for (int u = 0; u < columns; ++u) {
      const Eigen::Vector2d uv(stepU * u, stepV * v);
      if (!point_on_periodic_chart(
              chartTriangles, uv, faces.rows(),
              points[static_cast<std::size_t>(node_index(u, v))])) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart);
        return result;
      }
    }
  }

  struct EdgeOwner {
    int edge = -1;
  };
  std::map<std::pair<int, int>, EdgeOwner> openEdges;
  for (int v = 0; v < result.gridV; ++v) {
    for (int u = 0; u < result.gridU; ++u) {
      const std::array<int, 4> nodeIds{
          node_index(u, v), node_index(u + 1, v),
          node_index(u + 1, v + 1), node_index(u, v + 1)};
      const std::array<Eigen::Vector2d, 4> uv{
          Eigen::Vector2d(stepU * u, stepV * v),
          Eigen::Vector2d(stepU * (u + 1), stepV * v),
          Eigen::Vector2d(stepU * (u + 1), stepV * (v + 1)),
          Eigen::Vector2d(stepU * u, stepV * (v + 1))};
      const auto cellId = phase_front_cell_id_from_lattice(
          u, v, result.gridU, result.gridV);
      if (!cellId) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
        return result;
      }
      SurfacePhaseFrontCell cell(region.id(), cellId.value());
      for (int corner = 0; corner < 4; ++corner) {
        cell.corners[static_cast<std::size_t>(corner)] =
            points[static_cast<std::size_t>(nodeIds[corner])];
        const int sourceFace = cell.corners[static_cast<std::size_t>(corner)].face;
        if (sourceFace < 0 ||
            sourceFace >= static_cast<int>(faceBranchRotation.size()) ||
            faceBranchRotation[static_cast<std::size_t>(sourceFace)] < 0) {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::MissingFaceState,
              static_cast<int>(cell.id.index()), corner, sourceFace);
          return result;
        }
        auto &state = cell.lattice[static_cast<std::size_t>(corner)];
        state.phase = uv[static_cast<std::size_t>(corner)];
        state.latticeCoordinate = {
            corner == 1 || corner == 2 ? u + 1 : u,
            corner >= 2 ? v + 1 : v};
        state.branchRotation = normalized_branch(
            faceBranchRotation[static_cast<std::size_t>(sourceFace)] +
            chartUBranch);
        const auto canonicalChart =
            canonicalSourceCharts.chart(sourceFace);
        if (!canonicalChart.has_value()) {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::MissingFaceState,
              static_cast<int>(cell.id.index()), corner, sourceFace);
          return result;
        }
        state.sourceChart = canonicalChart->chart;
      }
      const std::array<int, 4> globalBranches{
          chartUBranch, normalized_branch(chartUBranch + 1),
          normalized_branch(chartUBranch + 2),
          normalized_branch(chartUBranch + 3)};
      for (int side = 0; side < 4; ++side) {
        cell.boundaryPaths[static_cast<std::size_t>(side)] =
            bounded_disk_chart_segment(
                chartTriangles, canonicalSourceCharts, faces.rows(),
                uv[static_cast<std::size_t>(side)],
                uv[static_cast<std::size_t>((side + 1) % 4)],
                globalBranches[static_cast<std::size_t>(side)],
                faceBranchRotation);
        if (cell.boundaryPaths[static_cast<std::size_t>(side)].empty()) {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
              static_cast<int>(cell.id.index()), side);
          return result;
        }
      }
      const double pointTolerance =
          1.0e-7 * std::max({1.0, stepU, stepV});
      if (validate_closed_boundary_paths(vertices, faces, cell.corners,
                                         cell.boundaryPaths, pointTolerance) !=
          CellRejectionReason::Accepted) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
            static_cast<int>(cell.id.index()));
        return result;
      }
      auto positions = phase_front_corner_positions(vertices, faces, cell);
      Eigen::RowVector3d loopNormal = phase_front_loop_normal(positions);
      Eigen::RowVector3d expectedNormal = Eigen::RowVector3d::Zero();
      for (const auto &corner : cell.corners) {
        expectedNormal += face_normal(vertices, faces, corner.face);
      }
      if (!loopNormal.allFinite() || !expectedNormal.allFinite() ||
          loopNormal.squaredNorm() <= 1.0e-24 ||
          expectedNormal.squaredNorm() <= 1.0e-24) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidCellOrientation,
            static_cast<int>(cell.id.index()));
        return result;
      }
      if (loopNormal.dot(expectedNormal) < 0.0) {
        reverse_phase_front_cell_cycle(cell);
        positions = phase_front_corner_positions(vertices, faces, cell);
        loopNormal = phase_front_loop_normal(positions);
      }
      if (loopNormal.dot(expectedNormal) <= 0.0 ||
          !phase_front_cell_matches_region(cell, sourceAuthority, region)) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidCellOrientation,
            static_cast<int>(cell.id.index()));
        return result;
      }
      cell.orientationValidated = true;

      for (int side = 0; side < 4; ++side) {
        SurfaceFrontEdge edge(region.id(), cell.id);
        edge.from = cell.corners[static_cast<std::size_t>(side)];
        edge.to = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
        edge.fromLattice = cell.lattice[static_cast<std::size_t>(side)];
        edge.toLattice = cell.lattice[static_cast<std::size_t>((side + 1) % 4)];
        const authority::LatticeTranslation delta =
            edge.toLattice.latticeCoordinate - edge.fromLattice.latticeCoordinate;
        if (delta == authority::LatticeTranslation{1, 0}) {
          edge.family = 0;
          edge.advanceSign = 1;
        } else if (delta == authority::LatticeTranslation{0, 1}) {
          edge.family = 1;
          edge.advanceSign = 1;
        } else if (delta == authority::LatticeTranslation{-1, 0}) {
          edge.family = 0;
          edge.advanceSign = -1;
        } else if (delta == authority::LatticeTranslation{0, -1}) {
          edge.family = 1;
          edge.advanceSign = -1;
        } else {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidLatticeEdge,
              static_cast<int>(cell.id.index()), side);
          return result;
        }
        edge.filledSide = side;
        const int edgeId = static_cast<int>(result.edges.size());
        result.edges.push_back(edge);
        const int a = node_index(
            static_cast<int>(edge.fromLattice.latticeCoordinate.x),
            static_cast<int>(edge.fromLattice.latticeCoordinate.y));
        const int b = node_index(
            static_cast<int>(edge.toLattice.latticeCoordinate.x),
            static_cast<int>(edge.toLattice.latticeCoordinate.y));
        const auto ordered = std::minmax(a, b);
        const std::pair<int, int> key{ordered.first, ordered.second};
        const auto found = openEdges.find(key);
        if (found == openEdges.end()) {
          openEdges.emplace(key, EdgeOwner{edgeId});
        } else {
          auto &first = result.edges[static_cast<std::size_t>(found->second.edge)];
          auto &second = result.edges[static_cast<std::size_t>(edgeId)];
          if (first.filledCell == second.filledCell ||
              first.fromLattice.latticeCoordinate !=
                  second.toLattice.latticeCoordinate ||
              first.toLattice.latticeCoordinate !=
                  second.fromLattice.latticeCoordinate ||
              first.family != second.family ||
              first.advanceSign == second.advanceSign ||
              first.sourceTopologyRegion != second.sourceTopologyRegion) {
            set_phase_front_failure(
                result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing,
                static_cast<int>(cell.id.index()), side);
            return result;
          }
          first.oppositeEdge = edgeId;
          second.oppositeEdge = found->second.edge;
          first.unfilledSide = 0;
          second.unfilledSide = 0;
          SurfaceFrontEvent event;
          event.kind = SurfaceFrontEventKind::CompatibleFrontMerge;
          event.firstEdge = found->second.edge;
          event.secondEdge = edgeId;
          result.events.push_back(event);
          openEdges.erase(found);
        }
      }
      result.cells.push_back(std::move(cell));
    }
  }

  const auto path_on_authoritative_boundary = [&](const auto &path) {
    constexpr double tolerance = 1.0e-9;
    for (const SurfaceTraceSegment &segment : path) {
      bool supported = false;
      for (int corner = 0; corner < 3; ++corner) {
        if (std::abs(segment.startBarycentric[corner]) <= tolerance &&
            std::abs(segment.endBarycentric[corner]) <= tolerance) {
          const int a = faces(segment.face, (corner + 1) % 3);
          const int b = faces(segment.face, (corner + 2) % 3);
          if (boundaryEdgeKeys.count(edge_key(a, b, source_vertex_extent(faces))) != 0U) {
            supported = true;
            break;
          }
        }
      }
      if (!supported) return false;
    }
    return !path.empty();
  };
  const auto cellIndexById = phase_front_cell_storage_index(result.cells);
  if (!cellIndexById) {
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
    return result;
  }
  for (const auto &[key, owner] : openEdges) {
    (void)key;
    auto &edge = result.edges[static_cast<std::size_t>(owner.edge)];
    const authority::LatticeTranslation a =
        edge.fromLattice.latticeCoordinate;
    const authority::LatticeTranslation b = edge.toLattice.latticeCoordinate;
    const bool onBoundary =
        (a.x == 0 && b.x == 0) ||
        (a.x == result.gridU && b.x == result.gridU) ||
        (a.y == 0 && b.y == 0) ||
        (a.y == result.gridV && b.y == result.gridV);
    const auto ownerCell = cellIndexById->find(edge.filledCell);
    if (!onBoundary || ownerCell == cellIndexById->end()) {
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing,
          static_cast<int>(edge.filledCell.index()), owner.edge);
      return result;
    }
    const auto &cell = result.cells[ownerCell->second];
    int side = -1;
    for (int candidate = 0; candidate < 4; ++candidate) {
      const auto &from = cell.lattice[static_cast<std::size_t>(candidate)]
                             .latticeCoordinate;
      const auto &to = cell.lattice[static_cast<std::size_t>((candidate + 1) % 4)]
                           .latticeCoordinate;
      if (from == edge.fromLattice.latticeCoordinate &&
          to == edge.toLattice.latticeCoordinate) {
        side = candidate;
        break;
      }
    }
    if (side < 0 ||
        !path_on_authoritative_boundary(
            cell.boundaryPaths[static_cast<std::size_t>(side)])) {
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing,
          static_cast<int>(edge.filledCell.index()), owner.edge);
      return result;
    }
    const auto boundaryReason = assign_open_front_boundary_authority(
        vertices, faces, options, sourceEdgeFaces, sourceMatchingIndices,
        cell.boundaryPaths[static_cast<std::size_t>(side)], edge);
    if (boundaryReason != SurfacePhaseFrontFailureReason::None) {
      set_phase_front_failure(result.failure, boundaryReason,
                              static_cast<int>(edge.filledCell.index()), side);
      return result;
    }
    edge.exterior = true;
    edge.unfilledSide = 0;
    SurfaceFrontEvent event;
    event.kind = SurfaceFrontEventKind::BoundaryTermination;
    event.firstEdge = owner.edge;
    result.events.push_back(event);
  }

  for (int edgeIndex = 0; edgeIndex < static_cast<int>(result.edges.size()); ++edgeIndex) {
    const auto &edge = result.edges[static_cast<std::size_t>(edgeIndex)];
    const bool hasTwin = edge.oppositeEdge >= 0;
    if (cellIndexById->find(edge.filledCell) == cellIndexById->end() || edge.unfilledSide != 0 ||
        hasTwin == edge.exterior ||
        (hasTwin &&
         (edge.oppositeEdge >= static_cast<int>(result.edges.size()) ||
          result.edges[static_cast<std::size_t>(edge.oppositeEdge)].oppositeEdge !=
              edgeIndex))) {
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing,
          -1, edgeIndex);
      return result;
    }
  }
  result.succeeded = !result.cells.empty() &&
                     result.cells.size() ==
                         static_cast<std::size_t>(result.gridU * result.gridV);
  if (!result.succeeded) {
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidFinalCellState);
    return result;
  }
  result.disposition = SurfaceCellProducerDisposition::Produced;
  return result;
}

bool build_isolation_seam_transport_certificates(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SourceTopologyRegions &sourceAuthority,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    const authority::FieldTransportAtlas *fieldTransportAtlas,
    std::vector<SurfaceIsolationSeamTransportCertificate> &certificates) {
  certificates.clear();
  if (faces.cols() != 3 || vertices.cols() != 3 ||
      faceAxisX.rows() != faces.rows() || faceAxisX.cols() != 3 ||
      faceAxisY.rows() != faces.rows() || faceAxisY.cols() != 3 ||
      sourceAuthority.face_count() != static_cast<std::size_t>(faces.rows())) {
    return false;
  }

  const auto &incident = sourceEdgeFaces;
  const auto &matchingIndices = sourceMatchingIndices;
  const bool hasTransitions =
      edgeTransitions != nullptr && !edgeTransitions->empty();
  const bool hasMatching = edgeMatching != nullptr && edgeMatching->size() > 0;
  const bool hasEffort = edgeEffort != nullptr && edgeEffort->size() > 0;
  const auto *effectiveTransitions = hasTransitions ? edgeTransitions : nullptr;
  const auto *effectiveMatching = hasMatching ? edgeMatching : nullptr;
  const auto *effectiveEffort = hasEffort ? edgeEffort : nullptr;
  const EdgeTransitionLookup transitionLookup =
      authoritative_edge_transition_lookup(
          fieldTransportAtlas, effectiveTransitions,
          source_vertex_extent(faces));
  if (transitionLookup.duplicate) return false;

  const auto &incidentByTopology = incident;
  const auto &matchingIndexByTopology = matchingIndices;

  const auto typed_row = [&](const int face)
      -> std::optional<authority::SourceFaceId> {
    const auto row =
        authority::SourceFaceId::from_index(face, sourceAuthority.face_count());
    return row ? std::optional<authority::SourceFaceId>(row.value())
               : std::nullopt;
  };

  std::set<std::pair<authority::TopologyRegionId,
                     authority::SourceEdgeTopologyKey>> seen;
  for (const SurfaceTopologyRegion &region : sourceAuthority.regions()) {
    for (const authority::SourceEdgeTopologyKey &seam :
         region.isolation_seams()) {
      const auto foundIncident = incidentByTopology.find(seam);
      const auto foundIndex = matchingIndexByTopology.find(seam);
      if (!seen.insert({region.id(), seam}).second ||
          foundIncident == incidentByTopology.end() || foundIncident->second[0] < 0 ||
          foundIncident->second[1] < 0 ||
          foundIndex == matchingIndexByTopology.end() ||
          foundIndex->second < 0) {
        return false;
      }
      const auto transitionId = authority::InteriorTransitionId::from_index(
          foundIndex->second, matchingIndices.size());
      if (!transitionId) return false;

      int firstFace = foundIncident->second[0];
      int secondFace = foundIncident->second[1];
      const auto firstRow = typed_row(firstFace);
      const auto secondRow = typed_row(secondFace);
      if (!firstRow || !secondRow || firstFace == secondFace ||
          sourceAuthority.region_for_row(firstRow.value()) != region.id() ||
          sourceAuthority.region_for_row(secondRow.value()) != region.id() ||
          sourceAuthority.component_for_row(firstRow.value()) !=
              region.component() ||
          sourceAuthority.component_for_row(secondRow.value()) !=
              region.component()) {
        return false;
      }

      auto firstTopology = sourceAuthority.topology_for_row(firstRow.value());
      auto secondTopology = sourceAuthority.topology_for_row(secondRow.value());
      auto firstSheet = sourceAuthority.sheet_for_row(firstRow.value());
      auto secondSheet = sourceAuthority.sheet_for_row(secondRow.value());
      if (firstTopology == secondTopology || firstSheet == secondSheet) {
        return false;
      }
      if (secondTopology < firstTopology) {
        std::swap(firstFace, secondFace);
        std::swap(firstTopology, secondTopology);
        std::swap(firstSheet, secondSheet);
      }
      if (effectiveTransitions != nullptr) {
        const auto transition = transitionLookup.byEdge.find(seam);
        if (transition == transitionLookup.byEdge.end() ||
            transition->second.sourceEdge < 0) {
          return false;
        }
      }

      std::optional<authority::QuarterTurn> forwardQuarterTurn;
      std::optional<authority::QuarterTurn> reverseQuarterTurn;
      for (int sourceBranch = 0; sourceBranch < 4; ++sourceBranch) {
        int sourceFamily = 0;
        int sourceSign = 1;
        family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
        const Eigen::RowVector3d sourceDirection = project_tangent(
            axis_for_family(faceAxisX, faceAxisY, firstFace, sourceFamily,
                            sourceSign),
            face_normal(vertices, faces, firstFace));
        const BranchTransitionResult forward = resolve_branch_transition(
            vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
            transitionLookup, seam, firstFace, secondFace, sourceFamily,
            sourceSign, sourceDirection, effectiveMatching, effectiveEffort,
            effectiveTransitions);
        if (!forward.valid) return false;
        const int targetBranch =
            branch_from_family_sign(forward.family, forward.sign);
        const Eigen::RowVector3d targetDirection = project_tangent(
            axis_for_family(faceAxisX, faceAxisY, secondFace, forward.family,
                            forward.sign),
            face_normal(vertices, faces, secondFace));
        const BranchTransitionResult reverse = resolve_branch_transition(
            vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
            transitionLookup, seam, secondFace, firstFace, forward.family,
            forward.sign, targetDirection, effectiveMatching, effectiveEffort,
            effectiveTransitions);
        const authority::QuarterTurn candidateForward =
            authority::QuarterTurn::from_integer(forward.matching);
        const authority::QuarterTurn candidateReverse =
            authority::QuarterTurn::from_integer(reverse.matching);
        if (!reverse.valid ||
            targetBranch != normalized_branch(
                                sourceBranch +
                                static_cast<int>(candidateForward.value())) ||
            branch_from_family_sign(reverse.family, reverse.sign) != sourceBranch ||
            candidateReverse != candidateForward.inverse() ||
            (forwardQuarterTurn.has_value() &&
             *forwardQuarterTurn != candidateForward) ||
            (reverseQuarterTurn.has_value() &&
             *reverseQuarterTurn != candidateReverse)) {
          return false;
        }
        forwardQuarterTurn = candidateForward;
        reverseQuarterTurn = candidateReverse;
      }
      if (!forwardQuarterTurn.has_value() || !reverseQuarterTurn.has_value()) {
        return false;
      }

      const auto certificate = SurfaceIsolationSeamTransportCertificate::make(
          sourceAuthority, region.id(), seam, transitionId.value(), firstTopology,
          secondTopology, firstSheet, secondSheet, *forwardQuarterTurn,
          *reverseQuarterTurn);
      const auto *value =
          std::get_if<SurfaceIsolationSeamTransportCertificate>(&certificate);
      if (value == nullptr) return false;
      certificates.push_back(*value);
    }
  }
  std::sort(certificates.begin(), certificates.end());
  return std::adjacent_find(
             certificates.begin(), certificates.end(),
             [](const auto &first, const auto &second) {
               return first.region() == second.region() && first.seam() == second.seam();
             }) == certificates.end();
}



SurfacePhaseFrontBuildState build_uniform_phase_front_state(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize,
    const SourceTopologyRegions &sourceAuthority,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontBuildState result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted) return result;
  if (!source_authority_valid(options, faces)) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidInput);
    return result;
  }

  // All materializer-facing numeric routes share this single source-wide
  // compact interior-transition domain. Regional producers retain their local
  // incidence for traversal only; they never rebuild serialized indices.
  const auto sourceEdgeFaces = edge_faces(faces);
  const auto sourceMatchingIndices = edge_matching_indices(sourceEdgeFaces);

  if (!sourceAuthority.matches_source_faces(
          faces, static_cast<std::size_t>(vertices.rows())) ||
      (faces.rows() > 0 && sourceAuthority.regions().empty())) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidTopologyRegion);
    return result;
  }
  result.sourceTopologyRegions = sourceAuthority;

  struct RegionWork {
    const SurfaceTopologyRegion *region = nullptr;
    std::vector<authority::SourceFaceId> sourceRows;
    std::vector<int> canonicalVertices;
  };
  std::vector<RegionWork> regions;
  regions.reserve(result.sourceTopologyRegions->regions().size());
  for (const SurfaceTopologyRegion &region : result.sourceTopologyRegions->regions()) {
    RegionWork work;
    work.region = &region;
    std::set<int> uniqueVertices;
    work.sourceRows.reserve(region.faces().size());
    for (const SourceRegionFaceAuthority &member : region.faces()) {
      const auto faceId = result.sourceTopologyRegions->row_for_topology(member.topology);
      if (!faceId.has_value()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidTopologyRegion);
        return result;
      }
      work.sourceRows.push_back(*faceId);
      const int face = static_cast<int>(faceId->index());
      for (int corner = 0; corner < 3; ++corner) {
        uniqueVertices.insert(faces(face, corner));
      }
    }
    std::sort(work.sourceRows.begin(), work.sourceRows.end());
    work.canonicalVertices.assign(uniqueVertices.begin(), uniqueVertices.end());
    regions.push_back(std::move(work));
  }
  std::sort(regions.begin(), regions.end(), [](const RegionWork &a,
                                                const RegionWork &b) {
    // Producer scheduling is ordered directly by the typed canonical region
    // authority. The numeric structural hash remains diagnostic-only and can
    // no longer influence producer work order.
    if (*a.region != *b.region) {
      return *a.region < *b.region;
    }
    return a.canonicalVertices < b.canonicalVertices;
  });

  struct RegionBuild {
    const RegionWork *work = nullptr;
    SurfacePhaseFrontBuildState result;
  };
  std::vector<RegionBuild> regionBuilds;
  regionBuilds.reserve(regions.size());
  bool anyProduced = false;
  int firstUnsupportedRegion = -1;

  const auto validate_region_scope = [&](const SurfacePhaseFrontBuildState &local,
                                         const SurfaceTopologyRegion &region) {
    for (const auto &relation : local.periodicHolonomies) {
      if (relation.sourceTopologyRegion() != region.id()) return false;
    }
    for (const auto &phase : local.boundedDiskBoundaryPhases) {
      if (phase.sourceTopologyRegion != region.id()) return false;
    }
    for (const auto &cell : local.cells) {
      if (cell.sourceTopologyRegion != region.id() ||
          !phase_front_cell_matches_region(cell, sourceAuthority, region)) {
        return false;
      }
    }
    for (const auto &edge : local.edges) {
      if (edge.sourceTopologyRegion != region.id()) return false;
      const auto owner = std::find_if(
          local.cells.begin(), local.cells.end(),
          [&](const SurfacePhaseFrontCell &cell) {
            return cell.id == edge.filledCell;
          });
      if (owner == local.cells.end() ||
          owner->sourceTopologyRegion != edge.sourceTopologyRegion) {
        return false;
      }
    }
    return true;
  };

  const auto retain_bounded_disk_boundary_phases =
      [&](SurfacePhaseFrontBuildState &local) {
        for (auto &phase : local.boundedDiskBoundaryPhases) {
          result.boundedDiskBoundaryPhases.push_back(std::move(phase));
        }
        local.boundedDiskBoundaryPhases.clear();
      };

  for (const RegionWork &work : regions) {
    const SurfaceTopologyRegion &region = *work.region;
    SurfacePhaseFrontBuildState local = build_uniform_phase_front_for_faces(
        vertices, faces, faceAxisX, faceAxisY, targetSize, work.sourceRows,
        region, *result.sourceTopologyRegions, options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,
        edgeEffort, edgeTransitions);
    if (local.disposition == SurfaceCellProducerDisposition::NotApplicable) {
      local = build_periodic_annulus_phase_front_for_faces(
          vertices, faces, faceAxisX, faceAxisY, targetSize, work.sourceRows,
          region, *result.sourceTopologyRegions, options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,
          edgeEffort, edgeTransitions);
    }
    if (local.disposition == SurfaceCellProducerDisposition::NotApplicable) {
      local = build_curved_bounded_disk_phase_front_for_faces(
          vertices, faces, faceAxisX, faceAxisY, targetSize, work.sourceRows,
          region, *result.sourceTopologyRegions, options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,
          edgeEffort, edgeTransitions);
    }
    if (!validate_region_scope(local, region)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidTopologyRegion);
      return result;
    }
    retain_bounded_disk_boundary_phases(local);
    if (local.disposition == SurfaceCellProducerDisposition::Rejected) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      result.failure = local.failure;
      return result;
    }
    if (local.disposition == SurfaceCellProducerDisposition::NotApplicable) {
      if (firstUnsupportedRegion < 0) {
        firstUnsupportedRegion = static_cast<int>(regionBuilds.size());
      }
    } else {
      if (!local.succeeded || local.cells.empty() ||
          !phase_front_cells_have_field_chart_authority(local.cells)) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        result.failure = local.failure;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
        return result;
      }
      anyProduced = true;
      result.gridU = std::max(result.gridU, local.gridU);
      result.gridV = std::max(result.gridV, local.gridV);
      for (SurfacePeriodicHolonomy relation : local.periodicHolonomies) {
        const auto insertion = insert_periodic_holonomy(
            result.periodicHolonomies, std::move(relation));
        if (insertion == SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::AmbiguousPeriodicRelationBasis);
          return result;
        }
        if (insertion == SurfacePeriodicHolonomyInsertStatus::Incompatible) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::IncompatiblePeriodicRelation);
          return result;
        }
      }
    }
    regionBuilds.push_back(RegionBuild{&work, std::move(local)});
  }

  if (firstUnsupportedRegion >= 0) {
    // Reaching firstUnsupportedRegion means the uniform, periodic-annulus, and
    // curved bounded-disk producers all returned NotApplicable for that exact
    // topology region. Ordinary no-feature inputs retain the historical
    // NotApplicable fallback when no authoritative region was produced. Once
    // hard-feature authority is present, however, falling back would discard a
    // mandatory topology barrier; publish the existing typed unsupported
    // outcome instead.
    if (!anyProduced && options.hardFeatureEdges.empty()) return result;
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    const SurfaceTopologyRegion &unsupported =
        *regionBuilds[static_cast<std::size_t>(firstUnsupportedRegion)]
             .work->region;
    int canonicalFace = -1;
    if (!unsupported.faces().empty()) {
      const auto row = result.sourceTopologyRegions->row_for_topology(
          unsupported.faces().front().topology);
      if (row.has_value()) {
        canonicalFace = static_cast<int>(row->index());
      }
    }
    // Keep the established public reason while producer ownership is migrated
    // from local isolation sheets to exact source-topological regions.
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::UnsupportedSourceSheetTopology,
        -1, -1, canonicalFace);
    return result;
  }

  const std::size_t finalCellExtent = std::accumulate(
      regionBuilds.begin(), regionBuilds.end(), std::size_t{0},
      [](const std::size_t count, const RegionBuild &build) {
        return count + build.result.cells.size();
      });
  using FinalCellOwnerKey =
      std::pair<authority::TopologyRegionId, authority::CellId>;
  std::set<FinalCellOwnerKey> finalCellOwnerKeys;
  for (const RegionBuild &build : regionBuilds) {
    for (const SurfacePhaseFrontCell &cell : build.result.cells) {
      if (!finalCellOwnerKeys.emplace(cell.sourceTopologyRegion, cell.id).second) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState,
            static_cast<int>(cell.id.index()));
        return result;
      }
    }
  }
  if (finalCellOwnerKeys.size() != finalCellExtent) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
    return result;
  }
  std::map<FinalCellOwnerKey, authority::CellId> finalCellIdByOwner;
  std::size_t canonicalCellOrdinal = 0U;
  for (const FinalCellOwnerKey &owner : finalCellOwnerKeys) {
    const auto finalCellId = authority::CellId::from_index(
        static_cast<std::int64_t>(canonicalCellOrdinal), finalCellExtent);
    if (!finalCellId ||
        !finalCellIdByOwner.emplace(owner, finalCellId.value()).second) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState);
      return result;
    }
    ++canonicalCellOrdinal;
  }
  int edgeOffset = 0;
  std::set<authority::TopologyRegionId> coveredRegions;
  for (RegionBuild &build : regionBuilds) {
    const SurfaceTopologyRegion &region = *build.work->region;
    SurfacePhaseFrontBuildState &local = build.result;
    bool localCoverage = false;
    const authority::TopologyRegionId typedRegion = region.id();
    std::map<authority::CellId, authority::CellId> finalCellByLocalOwner;
    for (SurfacePhaseFrontCell &cell : local.cells) {
      if (cell.sourceTopologyRegion != typedRegion ||
          !phase_front_cell_matches_region(cell, sourceAuthority, region)) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage,
            static_cast<int>(cell.id.index()), -1, cell.corners.front().face);
        return result;
      }
      localCoverage = true;
      const auto finalCellId =
          finalCellIdByOwner.find(FinalCellOwnerKey{typedRegion, cell.id});
      if (finalCellId == finalCellIdByOwner.end() ||
          !finalCellByLocalOwner.emplace(cell.id, finalCellId->second).second) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState,
            static_cast<int>(cell.id.index()));
        return result;
      }
      cell.id = finalCellId->second;
      result.cells.push_back(std::move(cell));
    }
    if (!localCoverage || !coveredRegions.insert(region.id()).second) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage,
          -1, -1, build.work->sourceRows.empty() ? -1 : static_cast<int>(build.work->sourceRows.front().index()));
      return result;
    }
    for (SurfaceFrontEdge &edge : local.edges) {
      if (edge.sourceTopologyRegion != typedRegion) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage,
            -1, -1, build.work->sourceRows.empty() ? -1 : static_cast<int>(build.work->sourceRows.front().index()));
        return result;
      }
      if (edge.boundaryKind == SurfaceFrontBoundaryKind::PeriodicCut) {
        if (!edge.periodicRelation.has_value()) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
              static_cast<int>(edge.filledCell.index()), edge.filledSide);
          return result;
        }
        const auto localOwner = std::find_if(
            local.periodicHolonomies.begin(), local.periodicHolonomies.end(),
            [&](const SurfacePeriodicHolonomy &candidate) {
              return candidate.id() == *edge.periodicRelation;
            });
        if (localOwner == local.periodicHolonomies.end()) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
              static_cast<int>(edge.filledCell.index()), edge.filledSide);
          return result;
        }
        const auto key = periodic_relation_key(*localOwner);
        const auto owner = std::find_if(
            result.periodicHolonomies.begin(),
            result.periodicHolonomies.end(), [&](const auto &candidate) {
              return periodic_relation_key(candidate) == key;
            });
        if (owner == result.periodicHolonomies.end()) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
              static_cast<int>(edge.filledCell.index()), edge.filledSide);
          return result;
        }
        edge.periodicRelation = owner->id();
      }
      const auto finalFilledCell = finalCellByLocalOwner.find(edge.filledCell);
      if (finalFilledCell == finalCellByLocalOwner.end()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidFinalEdgeState,
            static_cast<int>(edge.filledCell.index()), edge.filledSide);
        return result;
      }
      edge.filledCell = finalFilledCell->second;
      if (edge.oppositeEdge >= 0) edge.oppositeEdge += edgeOffset;
      result.edges.push_back(std::move(edge));
    }
    for (SurfaceFrontEvent &event : local.events) {
      if (event.firstEdge >= 0) event.firstEdge += edgeOffset;
      if (event.secondEdge >= 0) event.secondEdge += edgeOffset;
      result.events.push_back(std::move(event));
    }
    edgeOffset = static_cast<int>(result.edges.size());
  }

  if (coveredRegions.size() != result.sourceTopologyRegions->regions().size()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage);
    return result;
  }

  // A hard feature separates producer charts, but it does not create an
  // output boundary. Pair the two chart copies by exact source-simplex
  // support and ordered rail topology; geometry is never a merge predicate.
  struct HardRailPairKey {
    authority::SourceComponentId component;
    std::vector<std::int64_t> firstEndpoint;
    std::vector<std::int64_t> secondEndpoint;
    // CanonicalRoute::reversed() preserves canonical steps and flips only the
    // route's canonical orientation. Group chart copies by canonical route
    // content; orientation remains a per-edge invariant checked before
    // oppositeEdge is published.
    std::vector<authority::TransitionStep> routeSteps;
    bool operator<(const HardRailPairKey &other) const {
      return std::tie(component, firstEndpoint, secondEndpoint, routeSteps) <
             std::tie(other.component, other.firstEndpoint,
                      other.secondEndpoint, other.routeSteps);
    }
  };
  const auto support_key = [&](const SurfaceTracePoint &point) {
    std::vector<std::int64_t> key;
    if (!trace_point_is_valid(point, faces)) return key;
    constexpr double tolerance = 1.0e-9;
    constexpr double scale = 1.0e12;
    int vertexCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(point.barycentric[corner] - 1.0) <= tolerance) {
        vertexCorner = corner;
      }
    }
    if (vertexCorner >= 0) {
      return std::vector<std::int64_t>{
          0, faces(point.face, vertexCorner)};
    }
    int zeroCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(point.barycentric[corner]) <= tolerance) {
        if (zeroCorner >= 0) return std::vector<std::int64_t>{};
        zeroCorner = corner;
      }
    }
    if (zeroCorner >= 0) {
      const int firstCorner = (zeroCorner + 1) % 3;
      const int secondCorner = (zeroCorner + 2) % 3;
      const int firstVertex = faces(point.face, firstCorner);
      const int secondVertex = faces(point.face, secondCorner);
      const int low = std::min(firstVertex, secondVertex);
      const int high = std::max(firstVertex, secondVertex);
      const double highWeight = firstVertex == high
                                    ? point.barycentric[firstCorner]
                                    : point.barycentric[secondCorner];
      return std::vector<std::int64_t>{
          1, low, high, static_cast<std::int64_t>(std::llround(
                            std::clamp(highWeight, 0.0, 1.0) * scale))};
    }
    std::array<std::pair<int, double>, 3> weightedVertices;
    for (int corner = 0; corner < 3; ++corner) {
      weightedVertices[static_cast<std::size_t>(corner)] =
          {faces(point.face, corner), point.barycentric[corner]};
    }
    std::sort(weightedVertices.begin(), weightedVertices.end());
    key.push_back(2);
    for (const auto &[vertex, weight] : weightedVertices) {
      key.push_back(vertex);
      key.push_back(static_cast<std::int64_t>(
          std::llround(std::clamp(weight, 0.0, 1.0) * scale)));
    }
    return key;
  };

  const auto region_for_id = [&](const authority::TopologyRegionId id)
      -> const SurfaceTopologyRegion * {
    if (!result.sourceTopologyRegions.has_value() ||
        id.index() >= result.sourceTopologyRegions->regions().size()) {
      return nullptr;
    }
    return &result.sourceTopologyRegions->region(id);
  };
  std::map<HardRailPairKey, std::vector<int>> hardRailGroups;
  for (int edgeIndex = 0; edgeIndex < static_cast<int>(result.edges.size());
       ++edgeIndex) {
    const SurfaceFrontEdge &edge =
        result.edges[static_cast<std::size_t>(edgeIndex)];
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::HardRail) continue;
    std::vector<std::int64_t> from = support_key(edge.from);
    std::vector<std::int64_t> to = support_key(edge.to);
    const SurfaceTopologyRegion *edgeRegion =
        region_for_id(edge.sourceTopologyRegion);
    if (edge.oppositeEdge >= 0 || !edge.exterior || from.empty() || to.empty() ||
        edgeRegion == nullptr || edge.route.empty()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidHardRailPairing,
          static_cast<int>(edge.filledCell.index()), edge.filledSide);
      return result;
    }
    if (to < from) std::swap(from, to);
    hardRailGroups[{edgeRegion->component(), std::move(from),
                    std::move(to), edge.route.steps()}]
        .push_back(edgeIndex);
  }
  std::set<int> pairedHardEdges;
  for (const auto &[key, pair] : hardRailGroups) {
    (void)key;
    if (pair.size() != 2U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidHardRailPairing,
          pair.empty() ? -1
                        : static_cast<int>(
                             result.edges[static_cast<std::size_t>(pair.front())]
                                 .filledCell.index()),
          pair.empty() ? -1
                       : result.edges[static_cast<std::size_t>(pair.front())]
                             .filledSide);
      return result;
    }
    SurfaceFrontEdge &first =
        result.edges[static_cast<std::size_t>(pair[0])];
    SurfaceFrontEdge &second =
        result.edges[static_cast<std::size_t>(pair[1])];
    if (first.sourceTopologyRegion == second.sourceTopologyRegion ||
        support_key(first.from) != support_key(second.to) ||
        support_key(first.to) != support_key(second.from) ||
        first.route != second.route.reversed() ||
        (first.railId.has_value() && second.railId.has_value() &&
         first.railId != second.railId) ||
        first.family != second.family ||
        first.advanceSign == second.advanceSign) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidHardRailPairing,
          static_cast<int>(first.filledCell.index()), first.filledSide);
      return result;
    }
    first.oppositeEdge = pair[1];
    second.oppositeEdge = pair[0];
    first.exterior = false;
    second.exterior = false;
    pairedHardEdges.insert(pair.begin(), pair.end());
    result.events.push_back(
        {SurfaceFrontEventKind::HardRailMerge, pair[0], pair[1]});
  }
  result.events.erase(
      std::remove_if(result.events.begin(), result.events.end(),
                     [&](const SurfaceFrontEvent &event) {
                       return event.kind ==
                                  SurfaceFrontEventKind::BoundaryTermination &&
                              pairedHardEdges.count(event.firstEdge) != 0U;
                     }),
      result.events.end());

  if (!build_isolation_seam_transport_certificates(
          vertices, faces, faceAxisX, faceAxisY, *result.sourceTopologyRegions,
          sourceEdgeFaces, sourceMatchingIndices, edgeMatching, edgeEffort,
          edgeTransitions, options.fieldTransportAtlas,
          result.isolationSeamTransportCertificates)) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    result.succeeded = false;
    result.cells.clear();
    result.edges.clear();
    result.events.clear();
    result.periodicHolonomies.clear();
    result.isolationSeamTransportCertificates.clear();
    set_phase_front_failure(
        result.failure,
        SurfacePhaseFrontFailureReason::InvalidIsolationSeamTransportCertificate);
    return result;
  }

  result.succeeded = !result.cells.empty();
  if (result.succeeded) result.disposition = SurfaceCellProducerDisposition::Produced;
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry {

std::uint64_t surface_topology_region_hash(const SurfaceTopologyRegion &region) {
  return surface_cell_tracing_detail::surface_topology_region_hash_impl(region);
}

const char *surface_cell_producer_disposition_name(
    const SurfaceCellProducerDisposition disposition) {
  switch (disposition) {
  case SurfaceCellProducerDisposition::NotApplicable: return "NotApplicable";
  case SurfaceCellProducerDisposition::Produced: return "Produced";
  case SurfaceCellProducerDisposition::Rejected: return "Rejected";
  }
  return "Unknown";
}

const char *surface_phase_front_failure_reason_name(
    const SurfacePhaseFrontFailureReason reason) {
  switch (reason) {
  case SurfacePhaseFrontFailureReason::None: return "None";
  case SurfacePhaseFrontFailureReason::InvalidInput: return "InvalidInput";
  case SurfacePhaseFrontFailureReason::DegenerateReferenceFrame: return "DegenerateReferenceFrame";
  case SurfacePhaseFrontFailureReason::NonPlanarSource: return "NonPlanarSource";
  case SurfacePhaseFrontFailureReason::InconsistentFaceOrientation: return "InconsistentFaceOrientation";
  case SurfacePhaseFrontFailureReason::IncompatibleFaceBranch: return "IncompatibleFaceBranch";
  case SurfacePhaseFrontFailureReason::IncompatibleSecondaryBranch: return "IncompatibleSecondaryBranch";
  case SurfacePhaseFrontFailureReason::DuplicateTransitionMetadata: return "DuplicateTransitionMetadata";
  case SurfacePhaseFrontFailureReason::InvalidOrdinaryTransition: return "InvalidOrdinaryTransition";
  case SurfacePhaseFrontFailureReason::NonReciprocalOrdinaryTransition: return "NonReciprocalOrdinaryTransition";
  case SurfacePhaseFrontFailureReason::NonRectangularDomain: return "NonRectangularDomain";
  case SurfacePhaseFrontFailureReason::InvalidTargetSize: return "InvalidTargetSize";
  case SurfacePhaseFrontFailureReason::InvalidGridStep: return "InvalidGridStep";
  case SurfacePhaseFrontFailureReason::PointProjectionFailure: return "PointProjectionFailure";
  case SurfacePhaseFrontFailureReason::MissingFaceState: return "MissingFaceState";
  case SurfacePhaseFrontFailureReason::MissingSegmentCoverage: return "MissingSegmentCoverage";
  case SurfacePhaseFrontFailureReason::DisconnectedSegmentAttachment: return "DisconnectedSegmentAttachment";
  case SurfacePhaseFrontFailureReason::NonManifoldVertexFan: return "NonManifoldVertexFan";
  case SurfacePhaseFrontFailureReason::AmbiguousVertexFan: return "AmbiguousVertexFan";
  case SurfacePhaseFrontFailureReason::InvalidVertexFanTransition: return "InvalidVertexFanTransition";
  case SurfacePhaseFrontFailureReason::VertexFanBranchMismatch: return "VertexFanBranchMismatch";
  case SurfacePhaseFrontFailureReason::MissingTransitionProvenance: return "MissingTransitionProvenance";
  case SurfacePhaseFrontFailureReason::InvalidCellOrientation: return "InvalidCellOrientation";
  case SurfacePhaseFrontFailureReason::InvalidLatticeEdge: return "InvalidLatticeEdge";
  case SurfacePhaseFrontFailureReason::FrontOwnershipConflict: return "FrontOwnershipConflict";
  case SurfacePhaseFrontFailureReason::InvalidFinalCellState: return "InvalidFinalCellState";
  case SurfacePhaseFrontFailureReason::InvalidFinalEdgeState: return "InvalidFinalEdgeState";
  case SurfacePhaseFrontFailureReason::InvalidPeriodicTopology: return "InvalidPeriodicTopology";
  case SurfacePhaseFrontFailureReason::InvalidPeriodicChart: return "InvalidPeriodicChart";
  case SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch: return "PeriodicHolonomyMismatch";
  case SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing: return "InvalidPeriodicFrontPairing";
  case SurfacePhaseFrontFailureReason::InvalidPeriodicRingCorrespondence: return "InvalidPeriodicRingCorrespondence";
  case SurfacePhaseFrontFailureReason::AmbiguousPeriodicRingCorrespondence: return "AmbiguousPeriodicRingCorrespondence";
  case SurfacePhaseFrontFailureReason::AmbiguousPeriodicRelationBasis: return "AmbiguousPeriodicRelationBasis";
  case SurfacePhaseFrontFailureReason::IncompatiblePeriodicRelation: return "IncompatiblePeriodicRelation";
  case SurfacePhaseFrontFailureReason::UnsupportedSourceSheetTopology: return "UnsupportedSourceSheetTopology";
  case SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage: return "IncompleteSourceSheetCoverage";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskTopology: return "InvalidBoundedDiskTopology";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport: return "InvalidBoundedDiskTransport";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase: return "InvalidBoundedDiskBoundaryPhase";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart: return "InvalidBoundedDiskChart";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing: return "InvalidBoundedDiskFrontPairing";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryTurn: return "InvalidBoundedDiskBoundaryTurn";
  case SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryIndex: return "InvalidBoundedDiskBoundaryIndex";
  case SurfacePhaseFrontFailureReason::InvalidTopologyRegion: return "InvalidTopologyRegion";
  case SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport: return "InvalidTopologyRegionTransport";
  case SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority: return "InvalidFrontBoundaryAuthority";
  case SurfacePhaseFrontFailureReason::UnsupportedEmbeddedReliefCut: return "UnsupportedEmbeddedReliefCut";
  case SurfacePhaseFrontFailureReason::InvalidHardRailPairing: return "InvalidHardRailPairing";
  case SurfacePhaseFrontFailureReason::InvalidIsolationSeamTransportCertificate: return "InvalidIsolationSeamTransportCertificate";
  }
  return "Unknown";
}

SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching,
    const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfaceCellNetwork network;
  network.authoritativeRails = options.authoritativeRails;
  network.reliefRootVertices = options.reliefRootVertices;
  network.reliefRegionLabels = options.reliefRegionLabels;
  network.reliefBarrierEdges = options.reliefBarrierEdges;
  if (options.sourceAuthority != nullptr &&
      options.sourceAuthority->matches_source_faces(
          faces, static_cast<std::size_t>(vertices.rows()))) {
    network.sourceTopologyRegions = *options.sourceAuthority;
  } else {
    network.sourceTopologyRegions =
        surface_cell_tracing_detail::build_source_topology_regions(faces,
                                                                   options);
  }
  if (!network.sourceTopologyRegions.has_value()) {
    SurfacePhaseFrontFailure failure;
    failure.reason = SurfacePhaseFrontFailureReason::InvalidTopologyRegion;
    network.phaseFront = SurfacePhaseFrontResult::rejected(std::move(failure));
    return network;
  }
  if (options.fieldTransportAtlas != nullptr &&
      !options.fieldTransportAtlas->matches_source_faces(
          faces, *network.sourceTopologyRegions,
          static_cast<std::size_t>(vertices.rows()))) {
    SurfacePhaseFrontFailure failure;
    failure.reason = SurfacePhaseFrontFailureReason::InvalidTopologyRegionTransport;
    network.phaseFront = SurfacePhaseFrontResult::rejected(std::move(failure));
    return network;
  }
  SurfaceCellTracingOptions authoritativeOptions = options;
  authoritativeOptions.sourceFaceComponents.clear();
  authoritativeOptions.sourceFaceSheets.clear();
  authoritativeOptions.sourceAuthority = &*network.sourceTopologyRegions;
  network.phaseFront = surface_cell_tracing_detail::publish_phase_front_result(
      surface_cell_tracing_detail::build_uniform_phase_front_state(
          vertices, faces, faceAxisX, faceAxisY, targetSize,
          *network.sourceTopologyRegions, authoritativeOptions,
          edgeMatching, edgeEffort, edgeTransitions));
  if (network.phaseFront.is_produced()) {
    const SurfacePhaseFrontProduct &phaseFront = network.phaseFront.product();
    network.proposals.reserve(phaseFront.cells().size());
    for (const SurfacePhaseFrontCell &cell : phaseFront.cells()) {
      SurfaceCellProposal proposal;
      // Phase-front cells are not seed-owned; never mirror CellId into seed provenance.
      proposal.seedId = -1;
      proposal.accepted = true;
      proposal.rejection = CellRejectionReason::Accepted;
      proposal.corners = cell.corners;
      proposal.boundaryPaths = cell.boundaryPaths;
      for (const auto &path : proposal.boundaryPaths) {
        proposal.sides.insert(proposal.sides.end(), path.begin(), path.end());
      }
      network.proposals.push_back(std::move(proposal));
    }
    network.stats.attempted = static_cast<int>(network.proposals.size());
    network.stats.accepted = static_cast<int>(network.proposals.size());
    return network;
  }
  if (network.phaseFront.is_rejected()) {
    return network;
  }
  network.seeds =
      generate_deterministic_surface_seeds(vertices, faces, targetSize, authoritativeOptions);
  for (const SurfaceTraceSeed &seed : network.seeds) {
    for (int family = 0; family < 2; ++family) {
      for (const int sign : {-1, 1}) {
        network.traces.push_back(trace_surface_field(
            vertices, faces, faceAxisX, faceAxisY, seed, family, sign, authoritativeOptions,
            edgeMatching, edgeEffort, edgeTransitions));
      }
    }
    SurfaceCellProposal proposal = make_surface_cell_proposal(
        vertices, faces, faceAxisX, faceAxisY, targetSize, seed, authoritativeOptions,
        edgeMatching, edgeEffort, edgeTransitions);
    ++network.stats.attempted;
    switch (proposal.rejection) {
    case CellRejectionReason::Accepted:
      ++network.stats.accepted;
      break;
    case CellRejectionReason::Closure:
      ++network.stats.rejectedClosure;
      break;
    case CellRejectionReason::Barrier:
      ++network.stats.rejectedBarrier;
      break;
    case CellRejectionReason::Degenerate:
      ++network.stats.rejectedDegenerate;
      break;
    case CellRejectionReason::SourceSheet:
      ++network.stats.rejectedSourceSheet;
      break;
    case CellRejectionReason::FieldMetadata:
      ++network.stats.rejectedFieldMetadata;
      break;
    case CellRejectionReason::SelfIntersection:
      ++network.stats.rejectedSelfIntersection;
      break;
    case CellRejectionReason::Inverted:
      ++network.stats.rejectedInverted;
      break;
    case CellRejectionReason::DuplicateCorner:
      ++network.stats.rejectedDuplicateCorner;
      break;
    case CellRejectionReason::OutOfSize:
      ++network.stats.rejectedOutOfSize;
      break;
    case CellRejectionReason::HardRailCrossing:
      ++network.stats.rejectedHardRailCrossing;
      break;
    }
    network.proposals.push_back(std::move(proposal));
  }

  // Enumerate singular branches in an intrinsically unrolled one-ring.  The
  // four generic traces above remain stable API evidence for every seed, but
  // they cannot express the 3/5-valent topology of nonzero cross-field
  // indices.  A branch is owned by the incident face wedge containing its
  // outgoing field ray; rays on shared wedge boundaries are canonicalized.
  const auto authoritativeSingularities =
      surface_cell_tracing_detail::tracing_singularity_inputs(options, faces);
  if (!authoritativeSingularities.has_value()) {
    network.singularSeparatrixStats.metadataValid = false;
    network.singularSeparatrixStats.incompleteSingularities =
        surface_cell_tracing_detail::tracing_has_singularities(options) ? 1 : 0;
    return network;
  }
  if (!authoritativeSingularities->empty()) {
    SurfaceSingularitySeparatrixStats &stats =
        network.singularSeparatrixStats;
    stats.singularityCount =
        static_cast<int>(authoritativeSingularities->size());

    struct Wedge {
      int face = -1;
      int corner = -1;
      int startNeighbor = -1;
      int endNeighbor = -1;
      double angle = 0.0;
      double offset = 0.0;
    };
    struct BranchCandidate {
      int face = -1;
      int family = -1;
      int sign = 0;
      double angle = 0.0;
      bool synthesized = false;
    };
    const auto incident =
        surface_cell_tracing_detail::incident_faces_by_vertex(
            static_cast<int>(vertices.rows()), faces);
    const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
    constexpr double pi = 3.141592653589793238462643383279502884;
    constexpr double angularTolerance = 1.0e-7;
    const auto other_face = [&](const authority::SourceEdgeTopologyKey &edge,
                                const int face) {
      const auto found = edgeFaces.find(edge);
      if (found == edgeFaces.end()) {
        return -1;
      }
      if (found->second[0] == face) {
        return found->second[1];
      }
      if (found->second[1] == face) {
        return found->second[0];
      }
      return -1;
    };
    const auto face_corner = [&](const int face, const int vertex) {
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(face, corner) == vertex) {
          return corner;
        }
      }
      return -1;
    };
    const auto make_wedge = [&](const int face, const int vertex) {
      Wedge wedge;
      wedge.face = face;
      wedge.corner = face_corner(face, vertex);
      if (wedge.corner < 0) {
        return wedge;
      }
      wedge.startNeighbor = faces(face, (wedge.corner + 1) % 3);
      wedge.endNeighbor = faces(face, (wedge.corner + 2) % 3);
      Eigen::RowVector3d start =
          surface_cell_tracing_detail::row3(vertices, wedge.startNeighbor) -
          surface_cell_tracing_detail::row3(vertices, vertex);
      Eigen::RowVector3d end =
          surface_cell_tracing_detail::row3(vertices, wedge.endNeighbor) -
          surface_cell_tracing_detail::row3(vertices, vertex);
      if (start.norm() > 0.0 && end.norm() > 0.0) {
        start.normalize();
        end.normalize();
        wedge.angle = std::acos(std::clamp(start.dot(end), -1.0, 1.0));
      }
      return wedge;
    };

    for (std::size_t singularity = 0;
         singularity < authoritativeSingularities->size(); ++singularity) {
      const auto [vertex, index] =
          (*authoritativeSingularities)[singularity];
      const int expectedValence = 4 - index;
      if (vertex < 0 || vertex >= vertices.rows() || expectedValence < 3 ||
          expectedValence > 6 ||
          incident[static_cast<std::size_t>(vertex)].empty()) {
        ++stats.invalidIndexCount;
        ++stats.incompleteSingularities;
        stats.metadataValid = false;
        continue;
      }
      stats.expectedBranches += expectedValence;

      std::map<int, Wedge> wedgeByFace;
      for (const int face : incident[static_cast<std::size_t>(vertex)]) {
        Wedge wedge = make_wedge(face, vertex);
        if (wedge.corner < 0 || !(wedge.angle > 0.0) ||
            !std::isfinite(wedge.angle)) {
          continue;
        }
        wedgeByFace.emplace(face, wedge);
      }
      if (wedgeByFace.size() !=
          incident[static_cast<std::size_t>(vertex)].size()) {
        ++stats.incompleteSingularities;
        stats.metadataValid = false;
        continue;
      }

      int firstFace = wedgeByFace.begin()->first;
      bool closedOneRing = true;
      for (const auto &[face, wedge] : wedgeByFace) {
        const auto startEdge = surface_cell_tracing_detail::edge_key(
            vertex, wedge.startNeighbor,
            surface_cell_tracing_detail::source_vertex_extent(faces));
        const auto found = edgeFaces.find(startEdge);
        const bool boundary =
            found == edgeFaces.end() || found->second[1] < 0;
        if (boundary) {
          firstFace = face;
          closedOneRing = false;
          break;
        }
      }

      std::vector<Wedge> ordered;
      std::set<int> visited;
      int face = firstFace;
      double offset = 0.0;
      while (face >= 0 && visited.insert(face).second) {
        const auto found = wedgeByFace.find(face);
        if (found == wedgeByFace.end()) {
          break;
        }
        Wedge wedge = found->second;
        wedge.offset = offset;
        offset += wedge.angle;
        ordered.push_back(wedge);
        face = other_face(surface_cell_tracing_detail::edge_key(
                              vertex, wedge.endNeighbor,
                              surface_cell_tracing_detail::source_vertex_extent(faces)),
                          face);
      }
      if (ordered.size() != wedgeByFace.size() ||
          (closedOneRing && face != firstFace)) {
        ++stats.incompleteSingularities;
        stats.metadataValid = false;
        continue;
      }

      std::vector<BranchCandidate> candidates;
      for (const Wedge &wedge : ordered) {
        const Eigen::RowVector3d vertexPosition =
            surface_cell_tracing_detail::row3(vertices, vertex);
        Eigen::RowVector3d start =
            surface_cell_tracing_detail::row3(vertices,
                                              wedge.startNeighbor) -
            vertexPosition;
        const Eigen::RowVector3d normal =
            surface_cell_tracing_detail::face_normal(vertices, faces,
                                                     wedge.face);
        start = surface_cell_tracing_detail::project_tangent(start, normal);
        if (start.squaredNorm() <= 0.0 || normal.squaredNorm() <= 0.0) {
          continue;
        }
        for (int family = 0; family < 2; ++family) {
          for (const int sign : {-1, 1}) {
            Eigen::RowVector3d direction =
                sign * (family == 0 ? faceAxisX.row(wedge.face)
                                    : faceAxisY.row(wedge.face));
            direction = surface_cell_tracing_detail::project_tangent(
                direction, normal);
            if (direction.squaredNorm() <= 0.0) {
              continue;
            }
            double localAngle = std::atan2(
                normal.dot(surface_cell_tracing_detail::cross3(start,
                                                               direction)),
                start.dot(direction));
            if (localAngle < -angularTolerance) {
              localAngle += 2.0 * pi;
            }
            if (localAngle > 2.0 * pi - angularTolerance) {
              localAngle = 0.0;
            }
            if (localAngle < -angularTolerance ||
                localAngle > wedge.angle + angularTolerance) {
              continue;
            }
            candidates.push_back(
                {wedge.face, family, sign,
                 wedge.offset + std::clamp(localAngle, 0.0, wedge.angle)});
          }
        }
      }
      std::stable_sort(candidates.begin(), candidates.end(),
                       [](const BranchCandidate &a,
                          const BranchCandidate &b) {
                         return std::tie(a.angle, a.face, a.family, a.sign) <
                                std::tie(b.angle, b.face, b.family, b.sign);
                       });
      std::vector<BranchCandidate> uniqueCandidates;
      for (const BranchCandidate &candidate : candidates) {
        if (!uniqueCandidates.empty() &&
            std::abs(candidate.angle - uniqueCandidates.back().angle) <=
                angularTolerance) {
          continue;
        }
        uniqueCandidates.push_back(candidate);
      }
      if (closedOneRing && uniqueCandidates.size() > 1U &&
          uniqueCandidates.front().angle <= angularTolerance &&
          offset - uniqueCandidates.back().angle <= angularTolerance) {
        uniqueCandidates.pop_back();
      }
      stats.enumeratedBranches +=
          static_cast<int>(uniqueCandidates.size());

      std::vector<BranchCandidate> selectedCandidates = uniqueCandidates;
      if (static_cast<int>(selectedCandidates.size()) != expectedValence) {
        // The integer index comes from principal matching and is the
        // authoritative topology. Facewise constant axes can put a ray on
        // opposite sides of a wedge boundary in its two incident faces,
        // producing one missing or duplicate raw candidate. Reconcile that
        // representation deterministically with an equally spaced one-ring
        // star whose phase minimizes distance to the observed field rays.
        ++stats.reconciledSingularities;
        const double spacing = offset / static_cast<double>(expectedValence);
        std::vector<double> phaseTrials = {0.0};
        for (const BranchCandidate &candidate : uniqueCandidates) {
          double phase = std::fmod(candidate.angle, spacing);
          if (phase < 0.0) {
            phase += spacing;
          }
          phaseTrials.push_back(phase);
        }
        std::sort(phaseTrials.begin(), phaseTrials.end());
        phaseTrials.erase(
            std::unique(phaseTrials.begin(), phaseTrials.end(),
                        [](const double a, const double b) {
                          return std::abs(a - b) <= angularTolerance;
                        }),
            phaseTrials.end());
        const auto circular_distance = [&](const double a, const double b) {
          const double difference = std::abs(a - b);
          return std::min(difference, offset - difference);
        };
        double bestPhase = 0.0;
        double bestCost = std::numeric_limits<double>::infinity();
        for (const double phase : phaseTrials) {
          double cost = 0.0;
          for (int branch = 0; branch < expectedValence; ++branch) {
            const double desired = phase + branch * spacing;
            double nearest = spacing;
            for (const BranchCandidate &candidate : uniqueCandidates) {
              nearest = std::min(
                  nearest, circular_distance(desired, candidate.angle));
            }
            cost += nearest * nearest;
          }
          if (cost < bestCost - 1.0e-15 ||
              (std::abs(cost - bestCost) <= 1.0e-15 && phase < bestPhase)) {
            bestCost = cost;
            bestPhase = phase;
          }
        }

        selectedCandidates.clear();
        for (int branch = 0; branch < expectedValence; ++branch) {
          double desired = bestPhase + branch * spacing;
          if (desired >= offset) {
            desired -= offset;
          }
          const Wedge *owner = nullptr;
          for (const Wedge &wedge : ordered) {
            if (desired >= wedge.offset - angularTolerance &&
                desired <= wedge.offset + wedge.angle + angularTolerance) {
              owner = &wedge;
              break;
            }
          }
          if (owner == nullptr) {
            continue;
          }
          const Eigen::RowVector3d normal =
              surface_cell_tracing_detail::face_normal(vertices, faces,
                                                       owner->face);
          Eigen::RowVector3d radial =
              surface_cell_tracing_detail::row3(
                  vertices, owner->startNeighbor) -
              surface_cell_tracing_detail::row3(vertices, vertex);
          radial = surface_cell_tracing_detail::project_tangent(radial,
                                                                normal);
          const double localAngle =
              std::clamp(desired - owner->offset, 0.0, owner->angle);
          radial = std::cos(localAngle) * radial +
                   std::sin(localAngle) *
                       surface_cell_tracing_detail::cross3(normal, radial);
          radial.normalize();
          int bestFamily = -1;
          int bestSign = 0;
          double bestAlignment = -std::numeric_limits<double>::infinity();
          for (int family = 0; family < 2; ++family) {
            for (const int sign : {-1, 1}) {
              Eigen::RowVector3d axis =
                  sign * (family == 0 ? faceAxisX.row(owner->face)
                                      : faceAxisY.row(owner->face));
              axis = surface_cell_tracing_detail::project_tangent(axis,
                                                                  normal);
              const double alignment = radial.dot(axis);
              if (alignment > bestAlignment + 1.0e-15) {
                bestAlignment = alignment;
                bestFamily = family;
                bestSign = sign;
              }
            }
          }
          if (bestFamily >= 0) {
            selectedCandidates.push_back(
                {owner->face, bestFamily, bestSign, desired, true});
          }
        }
      }

      int seedId = -1;
      for (const SurfaceTraceSeed &candidateSeed : network.seeds) {
        if (candidateSeed.provenance == SurfaceSeedProvenance::Singularity &&
            candidateSeed.sourceId == vertex) {
          seedId = candidateSeed.id;
          break;
        }
      }
      int nonemptyForSingularity = 0;
      for (int branch = 0;
           branch < static_cast<int>(selectedCandidates.size()); ++branch) {
        const BranchCandidate &candidate =
            selectedCandidates[static_cast<std::size_t>(branch)];
        SurfaceTraceSeed seed;
        seed.id = seedId;
        seed.provenance = SurfaceSeedProvenance::Singularity;
        seed.sourceId = vertex;
        const SurfaceTracePoint vertexPoint =
            surface_cell_tracing_detail::vertex_point_in_face(
                faces, candidate.face, vertex);
        seed.point = vertexPoint;
        if (candidate.synthesized) {
          const Wedge *synthesizedWedge = nullptr;
          for (const Wedge &orderedWedge : ordered) {
            if (orderedWedge.face == candidate.face) {
              synthesizedWedge = &orderedWedge;
              break;
            }
          }
          if (synthesizedWedge == nullptr) {
            continue;
          }
          const Wedge &wedge = *synthesizedWedge;
          const Eigen::RowVector3d vertexPosition =
              surface_cell_tracing_detail::row3(vertices, vertex);
          const Eigen::RowVector3d edge0 =
              surface_cell_tracing_detail::row3(vertices,
                                                wedge.startNeighbor) -
              vertexPosition;
          const Eigen::RowVector3d edge1 =
              surface_cell_tracing_detail::row3(vertices,
                                                wedge.endNeighbor) -
              vertexPosition;
          const Eigen::RowVector3d normal =
              surface_cell_tracing_detail::face_normal(vertices, faces,
                                                       candidate.face);
          Eigen::RowVector3d radial =
              surface_cell_tracing_detail::project_tangent(edge0, normal);
          const double localAngle =
              std::clamp(candidate.angle - wedge.offset, 0.0, wedge.angle);
          radial = std::cos(localAngle) * radial +
                   std::sin(localAngle) *
                       surface_cell_tracing_detail::cross3(normal, radial);
          const double g00 = edge0.dot(edge0);
          const double g01 = edge0.dot(edge1);
          const double g11 = edge1.dot(edge1);
          const double determinant = g00 * g11 - g01 * g01;
          if (!(determinant > 1.0e-24)) {
            continue;
          }
          double coefficient0 =
              (g11 * edge0.dot(radial) - g01 * edge1.dot(radial)) /
              determinant;
          double coefficient1 =
              (g00 * edge1.dot(radial) - g01 * edge0.dot(radial)) /
              determinant;
          if (coefficient0 < -1.0e-10 || coefficient1 < -1.0e-10) {
            continue;
          }
          coefficient0 = std::max(0.0, coefficient0);
          coefficient1 = std::max(0.0, coefficient1);
          const double coefficientSum = coefficient0 + coefficient1;
          if (!(coefficientSum > 0.0)) {
            continue;
          }
          constexpr double microStep = 1.0e-6;
          seed.point.barycentric = Eigen::RowVector3d::Zero();
          seed.point.barycentric[wedge.corner] = 1.0 - microStep;
          seed.point.barycentric[(wedge.corner + 1) % 3] =
              microStep * coefficient0 / coefficientSum;
          seed.point.barycentric[(wedge.corner + 2) % 3] =
              microStep * coefficient1 / coefficientSum;
        }
        SurfaceSingularitySeparatrix separatrix;
        separatrix.sourceVertex = vertex;
        separatrix.singularityIndexNumerator = index;
        separatrix.expectedValence = expectedValence;
        separatrix.branch = branch;
        separatrix.initialFace = candidate.face;
        separatrix.family = candidate.family;
        separatrix.sign = candidate.sign;
        separatrix.oneRingAngle = candidate.angle;
        separatrix.trace = trace_surface_field(
            vertices, faces, faceAxisX, faceAxisY, seed, candidate.family,
            candidate.sign, options, edgeMatching, edgeEffort,
            edgeTransitions);
        if (candidate.synthesized) {
          SurfaceTraceSegment prefix;
          prefix.face = candidate.face;
          prefix.startBarycentric = vertexPoint.barycentric;
          prefix.endBarycentric = seed.point.barycentric;
          prefix.family = candidate.family;
          prefix.sign = candidate.sign;
          separatrix.trace.segments.insert(separatrix.trace.segments.begin(),
                                           prefix);
          separatrix.trace.length +=
              (surface_cell_tracing_detail::point_position(vertices, faces,
                                                            seed.point) -
               surface_cell_tracing_detail::point_position(vertices, faces,
                                                            vertexPoint))
                  .norm();
        }
        if (!separatrix.trace.segments.empty()) {
          ++stats.nonemptyBranches;
          ++nonemptyForSingularity;
        }
        network.singularSeparatrices.push_back(std::move(separatrix));
      }
      if (static_cast<int>(selectedCandidates.size()) != expectedValence ||
          nonemptyForSingularity != expectedValence) {
        ++stats.incompleteSingularities;
      }
    }
  }
  return network;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options) {
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  cross_field_axes(crossField, faceAxisX, faceAxisY);
  if (options.fieldTransportAtlas != nullptr) {
    return build_surface_cell_network(vertices, faces, faceAxisX, faceAxisY,
                                      targetSize, options, nullptr, nullptr,
                                      nullptr);
  }
  // Explicit legacy/test ingress. Production callers publish an atlas in the
  // options above and never reconstruct branch authority from raw containers.
  return build_surface_cell_network(vertices, faces, faceAxisX, faceAxisY,
                                    targetSize, options, &crossField.matching,
                                    &crossField.effort,
                                    &crossField.edgeTransitions);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceCellTracingOverlay make_surface_cell_tracing_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
    const double glyphScale) {
  SurfaceCellTracingOverlay overlay;

  overlay.crossGlyphStarts.resize(2 * faces.rows(), 3);
  overlay.crossGlyphEnds.resize(2 * faces.rows(), 3);
  overlay.crossGlyphFamily.resize(2 * faces.rows());
  for (int face = 0; face < faces.rows(); ++face) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    double h = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      centroid += surface_cell_tracing_detail::row3(
                      vertices, faces(face, corner)) /
                  3.0;
      h += surface_cell_tracing_detail::target_size_at_vertex(
               targetSize, faces(face, corner), 1.0) /
           3.0;
    }
    const Eigen::RowVector3d normal =
        surface_cell_tracing_detail::face_normal(vertices, faces, face);
    const std::array<Eigen::RowVector3d, 2> axes = {
        surface_cell_tracing_detail::project_tangent(faceAxisX.row(face),
                                                     normal),
        surface_cell_tracing_detail::project_tangent(faceAxisY.row(face),
                                                     normal)};
    for (int family = 0; family < 2; ++family) {
      const int row = 2 * face + family;
      overlay.crossGlyphStarts.row(row) =
          centroid - glyphScale * h * axes[static_cast<std::size_t>(family)];
      overlay.crossGlyphEnds.row(row) =
          centroid + glyphScale * h * axes[static_cast<std::size_t>(family)];
      overlay.crossGlyphFamily(row) = family;
    }
  }

  overlay.seedPositions.resize(static_cast<int>(network.seeds.size()), 3);
  overlay.seedProvenance.resize(static_cast<int>(network.seeds.size()));
  for (int index = 0; index < static_cast<int>(network.seeds.size()); ++index) {
    const SurfaceTraceSeed &seed = network.seeds[static_cast<std::size_t>(index)];
    overlay.seedPositions.row(index) =
        surface_cell_tracing_detail::point_position(vertices, faces, seed.point);
    overlay.seedProvenance(index) = static_cast<int>(seed.provenance);
  }

  int segmentCount = 0;
  for (const SurfaceTraceResult &trace : network.traces) {
    segmentCount += static_cast<int>(trace.segments.size());
  }
  overlay.traceSegmentStarts.resize(segmentCount, 3);
  overlay.traceSegmentEnds.resize(segmentCount, 3);
  overlay.traceFamily.resize(segmentCount);
  overlay.traceSign.resize(segmentCount);
  overlay.traceTermination.resize(segmentCount);
  int segmentIndex = 0;
  for (const SurfaceTraceResult &trace : network.traces) {
    for (const SurfaceTraceSegment &segment : trace.segments) {
      overlay.traceSegmentStarts.row(segmentIndex) =
          surface_cell_tracing_detail::point_position(
              vertices, faces,
              SurfaceTracePoint{segment.face, segment.startBarycentric});
      overlay.traceSegmentEnds.row(segmentIndex) =
          surface_cell_tracing_detail::point_position(
              vertices, faces,
              SurfaceTracePoint{segment.face, segment.endBarycentric});
      overlay.traceFamily(segmentIndex) = segment.family;
      overlay.traceSign(segmentIndex) = segment.sign;
      overlay.traceTermination(segmentIndex) =
          static_cast<int>(trace.termination);
      ++segmentIndex;
    }
  }

  overlay.cellClosureError.resize(static_cast<int>(network.proposals.size()));
  overlay.cellRejection.resize(static_cast<int>(network.proposals.size()));
  for (int index = 0; index < static_cast<int>(network.proposals.size());
       ++index) {
    const SurfaceCellProposal &proposal =
        network.proposals[static_cast<std::size_t>(index)];
    overlay.cellClosureError(index) = proposal.closureError;
    overlay.cellRejection(index) = static_cast<int>(proposal.rejection);
  }
  return overlay;
}

} // namespace directional::geometry
