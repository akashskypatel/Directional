#include <directional/geometry/SurfaceCellTracing.h>

#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/authority/LegacyAuthorityAdapters.h>

#include <Eigen/SparseCholesky>

#include <optional>

namespace directional::geometry::surface_cell_tracing_detail {

std::uint64_t edge_key(const int a, const int b) {
  return relief_topology_detail::edge_key(a, b);
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

std::map<std::uint64_t, std::array<int, 2>>
edge_faces(const Eigen::MatrixXi &faces) {
  std::map<std::uint64_t, std::array<int, 2>> result;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const std::uint64_t key =
          edge_key(faces(face, corner), faces(face, (corner + 1) % 3));
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

std::map<std::uint64_t, std::array<int, 2>>
edge_faces(const Eigen::MatrixXi &faces, const std::vector<int> &activeFaces) {
  std::map<std::uint64_t, std::array<int, 2>> result;
  for (const int face : activeFaces) {
    if (face < 0 || face >= faces.rows()) {
      continue;
    }
    for (int corner = 0; corner < 3; ++corner) {
      const std::uint64_t key =
          edge_key(faces(face, corner), faces(face, (corner + 1) % 3));
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

std::map<std::uint64_t, int>
edge_matching_indices(const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces) {
  std::map<std::uint64_t, int> indices;
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
  const auto consume_int = [&](const int value) {
    consume(static_cast<std::uint64_t>(static_cast<std::int64_t>(value)));
  };
  consume_int(certificate.sourceComponent);
  consume_int(certificate.sourceTopologyRegion);
  consume(certificate.sourceEdgeTopology);
  consume_int(certificate.sourceEdgeIndex);
  for (const int vertex : certificate.firstSourceFaceTopology) {
    consume_int(vertex);
  }
  for (const int vertex : certificate.secondSourceFaceTopology) {
    consume_int(vertex);
  }
  consume_int(certificate.firstIsolationSheet);
  consume_int(certificate.secondIsolationSheet);
  consume_int(certificate.forwardQuarterTurn);
  consume_int(certificate.reverseQuarterTurn);
  return hash;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

EdgeTransitionLookup edge_transition_lookup(
    const std::vector<fields::CrossFieldEdgeTransition> &transitions) {
  EdgeTransitionLookup lookup;
  for (const fields::CrossFieldEdgeTransition &transition : transitions) {
    if (transition.sourceVertex0 < 0 || transition.sourceVertex1 < 0) {
      lookup.duplicate = true;
      continue;
    }
    const std::uint64_t key =
        edge_key(transition.sourceVertex0, transition.sourceVertex1);
    if (!lookup.byEdge.emplace(key, transition).second) {
      lookup.duplicate = true;
    }
  }
  return lookup;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool contains_vertex(const std::vector<int> &vertices,
                            const int vertex) {
  return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
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

void append_seed(std::vector<SurfaceTraceSeed> &seeds,
                        std::set<std::tuple<int, std::int64_t, std::int64_t,
                                                std::int64_t>> &seen,
                        const SurfaceTracePoint &point,
                        const SurfaceSeedProvenance provenance,
                        const int sourceId) {
  if (point.face < 0) {
    return;
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
    return;
  }
  SurfaceTraceSeed seed;
  seed.id = static_cast<int>(seeds.size());
  seed.point = point;
  seed.provenance = provenance;
  seed.sourceId = sourceId;
  seeds.push_back(seed);
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

bool source_label_arrays_enabled(
    const SurfaceCellTracingOptions &options) {
  return !options.sourceFaceComponents.empty() || !options.sourceFaceSheets.empty();
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_label_arrays_valid(const SurfaceCellTracingOptions &options,
                                      const int faceCount) {
  if (!source_label_arrays_enabled(options)) {
    return true;
  }
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
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_faces_compatible(const SurfaceCellTracingOptions &options,
                                    const int a, const int b) {
  if (!source_label_arrays_enabled(options)) {
    return true;
  }
  if (a < 0 || b < 0 ||
      a >= static_cast<int>(options.sourceFaceComponents.size()) ||
      b >= static_cast<int>(options.sourceFaceComponents.size()) ||
      a >= static_cast<int>(options.sourceFaceSheets.size()) ||
      b >= static_cast<int>(options.sourceFaceSheets.size())) {
    return false;
  }
  return options.sourceFaceComponents[static_cast<std::size_t>(a)] ==
             options.sourceFaceComponents[static_cast<std::size_t>(b)] &&
         options.sourceFaceSheets[static_cast<std::size_t>(a)] ==
             options.sourceFaceSheets[static_cast<std::size_t>(b)];
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

bool source_edge_is_authoritative_local_boundary(
    const SurfaceCellTracingOptions &options, const int faceCount,
    const int localFace, const std::array<int, 2> &fullIncident,
    const std::uint64_t edgeKey) {
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
  if (!source_label_arrays_enabled(options)) {
    return true;
  }
  if (a < 0 || b < 0 ||
      a >= static_cast<int>(options.sourceFaceComponents.size()) ||
      b >= static_cast<int>(options.sourceFaceComponents.size())) {
    return false;
  }
  return options.sourceFaceComponents[static_cast<std::size_t>(a)] ==
         options.sourceFaceComponents[static_cast<std::size_t>(b)];
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

int local_edge_for_key(const Eigen::MatrixXi &faces, const int face,
                              const std::uint64_t key) {
  if (face < 0 || face >= faces.rows()) {
    return -1;
  }
  for (int edge = 0; edge < 3; ++edge) {
    const int a = faces(face, (edge + 1) % 3);
    const int b = faces(face, (edge + 2) % 3);
    if (edge_key(a, b) == key) {
      return edge;
    }
  }
  return -1;
}

} // namespace directional::geometry::surface_cell_tracing_detail

namespace directional::geometry::surface_cell_tracing_detail {

std::uint64_t local_edge_key(const Eigen::MatrixXi &faces,
                                    const int face, const int edge) {
  if (face < 0 || face >= faces.rows() || edge < 0 || edge >= 3) {
    return 0;
  }
  return edge_key(faces(face, (edge + 1) % 3),
                  faces(face, (edge + 2) % 3));
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
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces) {
  RailIntervalBuildResult result;
  std::set<int> railIds;
  std::map<std::uint64_t, int> edgeOwners;
  for (const SurfaceCellRail &rail : rails) {
    if (rail.id < 0) {
      result.status = RailBuildStatus::InvalidRailId;
      result.railId = rail.id;
      return result;
    }
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

      const std::uint64_t key =
          local_edge_key(faces, a.sourceFace, a.sourceEdge);
      if (key == 0) {
        result.status = RailBuildStatus::InvalidSourceEdge;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      const auto owner = edgeOwners.find(key);
      if (owner != edgeOwners.end()) {
        result.status = RailBuildStatus::DuplicateInterval;
        result.railId = rail.id;
        result.intervalIndex = interval;
        return result;
      }
      edgeOwners.emplace(key, rail.id);

      SurfaceCellRailIntervalRef ref;
      ref.railId = rail.id;
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

std::vector<std::uint64_t> canonical_cycle_topology(
    const std::vector<std::uint64_t> &values) {
  if (values.empty()) return {};
  std::vector<std::uint64_t> best;
  const auto consider = [&](const std::vector<std::uint64_t> &candidate,
                            std::vector<std::uint64_t> &currentBest) {
    for (std::size_t offset = 0; offset < candidate.size(); ++offset) {
      std::vector<std::uint64_t> rotated;
      rotated.reserve(candidate.size());
      for (std::size_t i = 0; i < candidate.size(); ++i) {
        rotated.push_back(candidate[(offset + i) % candidate.size()]);
      }
      if (currentBest.empty() || rotated < currentBest) {
        currentBest = std::move(rotated);
      }
    }
  };
  consider(values, best);
  std::vector<std::uint64_t> reversed(values.rbegin(), values.rend());
  consider(reversed, best);
  return best;
}

std::vector<std::uint64_t> canonical_path_topology(
    const std::vector<std::uint64_t> &values) {
  std::vector<std::uint64_t> reversed(values.rbegin(), values.rend());
  return reversed < values ? reversed : values;
}

Eigen::Vector2i rotate_lattice_quarter_turn(const Eigen::Vector2i &value,
                                             const int quarterTurns) {
  switch (normalized_branch(quarterTurns)) {
  case 0: return value;
  case 1: return Eigen::Vector2i(-value.y(), value.x());
  case 2: return Eigen::Vector2i(-value.x(), -value.y());
  case 3: return Eigen::Vector2i(value.y(), -value.x());
  }
  return value;
}

int translation_orientation_rank(const Eigen::Vector2i &translation) {
  if (translation.x() != 0) return translation.x() > 0 ? 0 : 1;
  if (translation.y() != 0) return translation.y() > 0 ? 0 : 1;
  return 2;
}

auto periodic_relation_key(const SurfacePeriodicHolonomy &relation) {
  return std::tuple{
      relation.sourceComponent,
      relation.sourceTopologyRegion,
      relation.sourceSheet,
      relation.quarterTurnRotation,
      relation.latticeTranslation.x(),
      relation.latticeTranslation.y(),
      relation.sourceRouteTopology,
      relation.cutSourceTopology};
}

bool periodic_relation_shape_valid(const SurfacePeriodicHolonomy &relation) {
  const bool hasRegionScope =
      relation.sourceTopologyRegion >= 0 && !relation.sourceIsolationSheets.empty();
  const bool hasLegacySheetScope = relation.sourceSheet >= 0;
  return relation.sourceComponent >= 0 && (hasRegionScope || hasLegacySheetScope) &&
         relation.latticeTranslation.squaredNorm() > 0 &&
         !relation.sourceRouteEdges.empty() &&
         relation.sourceRouteEdges.size() == relation.sourceRouteTopology.size() &&
         !relation.cutSourceEdges.empty() &&
         relation.cutSourceEdges.size() == relation.cutSourceTopology.size();
}

} // namespace

SurfacePeriodicHolonomy canonicalize_periodic_holonomy(
    SurfacePeriodicHolonomy relation) {
  relation.quarterTurnRotation = normalized_branch(relation.quarterTurnRotation);
  std::sort(relation.sourceIsolationSheets.begin(),
            relation.sourceIsolationSheets.end());
  relation.sourceIsolationSheets.erase(
      std::unique(relation.sourceIsolationSheets.begin(),
                  relation.sourceIsolationSheets.end()),
      relation.sourceIsolationSheets.end());
  relation.sourceRouteTopology =
      canonical_cycle_topology(relation.sourceRouteTopology);
  relation.cutSourceTopology = canonical_path_topology(relation.cutSourceTopology);

  SurfacePeriodicHolonomy inverse = relation;
  inverse.quarterTurnRotation = normalized_branch(-relation.quarterTurnRotation);
  inverse.latticeTranslation = -rotate_lattice_quarter_turn(
      relation.latticeTranslation, inverse.quarterTurnRotation);

  const auto action_key = [](const SurfacePeriodicHolonomy &candidate) {
    return std::tuple{translation_orientation_rank(candidate.latticeTranslation),
                      candidate.quarterTurnRotation,
                      std::abs(candidate.latticeTranslation.x()),
                      std::abs(candidate.latticeTranslation.y()),
                      candidate.latticeTranslation.x(),
                      candidate.latticeTranslation.y()};
  };
  if (action_key(inverse) < action_key(relation)) {
    relation.quarterTurnRotation = inverse.quarterTurnRotation;
    relation.latticeTranslation = inverse.latticeTranslation;
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
        existing.sourceComponent == relation.sourceComponent &&
        ((existing.sourceTopologyRegion >= 0 && relation.sourceTopologyRegion >= 0)
             ? existing.sourceTopologyRegion == relation.sourceTopologyRegion
             : existing.sourceSheet == relation.sourceSheet);
    if (!sameScope) continue;
    if (existing.sourceRouteTopology == relation.sourceRouteTopology ||
        existing.cutSourceTopology == relation.cutSourceTopology) {
      return SurfacePeriodicHolonomyInsertStatus::Incompatible;
    }

    // This G4 slice intentionally does not guess a basis inside one source
    // sheet. Distinct same-sheet cycles require a later topology-basis solver;
    // retaining one by discovery order would be unsound. Multiple relations
    // on distinct authoritative sheets/components remain valid and are kept.
    return SurfacePeriodicHolonomyInsertStatus::AmbiguousBasis;
  }

  relations.push_back(std::move(relation));
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
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces,
    const std::map<std::uint64_t, int> &edgeMatchingIndices,
    const EdgeTransitionLookup &transitionLookup, const std::uint64_t edgeKey,
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
  if (edgeTransitions != nullptr) {
    const auto found = transitionLookup.byEdge.find(edgeKey);
    if (found == transitionLookup.byEdge.end()) {
      return result;
    }

    const std::size_t sourceFaceExtent =
        static_cast<std::size_t>(faces.rows());
    const std::size_t sourceVertexExtent =
        static_cast<std::size_t>(vertices.rows());
    const auto sourceFaceResult = authority::LegacyAuthorityAdapters::source_face(
        sourceFace, sourceFaceExtent);
    const auto targetFaceResult = authority::LegacyAuthorityAdapters::source_face(
        targetFace, sourceFaceExtent);
    const auto firstFaceResult = authority::LegacyAuthorityAdapters::source_face(
        found->second.firstFace, sourceFaceExtent);
    const auto secondFaceResult = authority::LegacyAuthorityAdapters::source_face(
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
        authority::LegacyAuthorityAdapters::source_vertex(
            found->second.sourceVertex0, sourceVertexExtent);
    const auto secondVertexResult =
        authority::LegacyAuthorityAdapters::source_vertex(
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
    const std::uint64_t transitionEdgeKey = edge_key(
        static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
            sourceEdge.first())),
        static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
            sourceEdge.second())));
    if (transitionEdgeKey != edgeKey) {
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
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces) {
  std::map<int, std::vector<VertexPathStep>> adjacency;
  for (const auto &[key, pair] : edgeFaces) {
    const int a = static_cast<int>(key >> 32u);
    const int b = static_cast<int>(key & 0xffffffffu);
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

bool source_edge_provenance(
    const std::uint64_t edgeKey,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge);

VertexContinuationResult resolve_vertex_continuation(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces,
    const std::map<std::uint64_t, int> &edgeMatchingIndices,
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
      if (path.visited.count(step.face) != 0) {
        continue;
      }
      if (options.hardFeatureEdges.count(step.edgeKey) != 0 ||
          (options.reliefBarriersEmbedded &&
           options.reliefBarrierEdges.count(step.edgeKey) != 0)) {
        featureBlocked = true;
        continue;
      }
      if (!source_faces_share_component(options, path.face, step.face)) {
        sourceSheetBlocked = true;
        continue;
      }
      const BranchTransitionResult transition = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, edgeFaces,
          edgeMatchingIndices, transitionLookup, step.edgeKey, path.face,
          step.face, path.family, path.sign, path.direction, edgeMatching,
          edgeEffort, edgeTransitions);
      if (!transition.valid) {
        metadataFailure = true;
        continue;
      }

      int sourceEdge = -1;
      if (!source_edge_provenance(
              step.edgeKey, edgeFaces, edgeMatchingIndices, transitionLookup,
              edgeTransitions, sourceEdge)) {
        metadataFailure = true;
        continue;
      }
      const auto firstVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey >> 32U),
          static_cast<std::size_t>(vertices.rows()));
      const auto secondVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey & 0xffffffffULL),
          static_cast<std::size_t>(vertices.rows()));
      if (!firstVertex || !secondVertex) {
        metadataFailure = true;
        continue;
      }
      const auto topology = authority::SourceEdgeTopologyKey::make(
          firstVertex.value(), secondVertex.value());
      if (!topology) {
        metadataFailure = true;
        continue;
      }
      const std::uint64_t compatibilityTopology = edge_key(
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().first())),
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().second())));
      if (compatibilityTopology != step.edgeKey) {
        metadataFailure = true;
        continue;
      }
      const auto interiorTransition =
          authority::LegacyAuthorityAdapters::interior_transition(
              sourceEdge, edgeMatchingIndices.size());
      if (!interiorTransition) {
        metadataFailure = true;
        continue;
      }
      const auto typedStep = authority::TransitionStep::interior(
          topology.value(),
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

std::set<std::uint64_t> combined_barrier_edges(
    const SurfaceCellTracingOptions &options) {
  std::set<std::uint64_t> barriers = options.hardFeatureEdges;
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
    const std::set<std::uint64_t> &barrierEdges,
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
  std::map<std::uint64_t, EdgeIncidence> edgeIncidence;
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
      const std::uint64_t key = edge_key(vertex, next);
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

  std::vector<std::vector<std::pair<int, std::uint64_t>>> adjacency(
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
    const int a = static_cast<int>(key >> 32u);
    const int b = static_cast<int>(key & 0xffffffffu);
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

namespace directional::geometry::surface_cell_tracing_detail {

SourceTopologyRegions build_source_topology_regions(
    const Eigen::MatrixXi &faces, const SurfaceCellTracingOptions &options) {
  SourceTopologyRegions result;
  const int faceCount = static_cast<int>(faces.rows());
  result.regionByFace.assign(static_cast<std::size_t>(faceCount), -1);
  if (faces.cols() != 3 || !source_label_arrays_valid(options, faceCount)) {
    result.valid = false;
    return result;
  }

  const auto fullIncident = edge_faces(faces);
  std::vector<std::vector<std::pair<int, std::uint64_t>>> adjacency(
      static_cast<std::size_t>(faceCount));
  for (const auto &[key, incident] : fullIncident) {
    const int first = incident[0];
    const int second = incident[1];
    if (first < 0) {
      result.valid = false;
      return result;
    }
    if (second < 0) continue;
    if (first >= faceCount || second >= faceCount || first == second) {
      result.valid = false;
      return result;
    }
    if (!source_faces_share_component(options, first, second)) continue;
    const bool hardBarrier = options.hardFeatureEdges.count(key) != 0U;
    // Embedded relief is an internal cut authority, not a parent producer
    // region splitter. The selected producer must either represent the cut
    // explicitly or reject the entire applicable region.
    if (hardBarrier) continue;
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
    if (visited[static_cast<std::size_t>(seed)]) continue;
    ProvisionalRegion region;
    std::queue<int> queue;
    queue.push(seed);
    visited[static_cast<std::size_t>(seed)] = true;
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      region.faces.push_back(face);
      for (const auto &[neighbor, key] : adjacency[static_cast<std::size_t>(face)]) {
        (void)key;
        if (!visited[static_cast<std::size_t>(neighbor)]) {
          visited[static_cast<std::size_t>(neighbor)] = true;
          queue.push(neighbor);
        }
      }
    }
    std::sort(region.faces.begin(), region.faces.end(), [&](const int a, const int b) {
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

  result.regions.reserve(provisional.size());
  for (int regionId = 0; regionId < static_cast<int>(provisional.size()); ++regionId) {
    const ProvisionalRegion &source = provisional[static_cast<std::size_t>(regionId)];
    SurfaceTopologyRegion region;
    region.id = regionId;
    region.sourceFaces = source.faces;
    if (region.sourceFaces.empty()) {
      result.valid = false;
      return result;
    }
    region.sourceComponent = face_label_or_default(
        options.sourceFaceComponents, region.sourceFaces.front(), 0);
    std::set<int> isolationSheets;
    for (const int face : region.sourceFaces) {
      result.regionByFace[static_cast<std::size_t>(face)] = regionId;
      if (face_label_or_default(options.sourceFaceComponents, face, 0) !=
          region.sourceComponent) {
        result.valid = false;
        return result;
      }
      const int sheet = face_label_or_default(options.sourceFaceSheets, face,
                                               region.sourceComponent);
      if (sheet < 0) {
        result.valid = false;
        return result;
      }
      isolationSheets.insert(sheet);
    }
    region.isolationSheets.assign(isolationSheets.begin(), isolationSheets.end());
    result.regions.push_back(std::move(region));
  }

  // Region topology is evaluated from exact source incidence. A local-sheet
  // transition inside the same region is recorded as an internal isolation
  // seam but never as an exterior producer boundary.
  for (SurfaceTopologyRegion &region : result.regions) {
    std::set<int> regionFaces(region.sourceFaces.begin(), region.sourceFaces.end());
    std::set<int> regionVertices;
    std::set<std::uint64_t> regionEdges;
    std::map<int, std::vector<int>> boundaryAdjacency;
    for (const int face : region.sourceFaces) {
      for (int corner = 0; corner < 3; ++corner) {
        regionVertices.insert(faces(face, corner));
        const int a = faces(face, corner);
        const int b = faces(face, (corner + 1) % 3);
        const std::uint64_t key = edge_key(a, b);
        regionEdges.insert(key);
        const auto incident = fullIncident.find(key);
        if (incident == fullIncident.end()) {
          result.valid = false;
          return result;
        }
        const int first = incident->second[0];
        const int second = incident->second[1];
        const int opposite = first == face ? second : (second == face ? first : -2);
        if (opposite == -2) {
          result.valid = false;
          return result;
        }
        if (opposite >= 0 && regionFaces.count(opposite) != 0U) {
          if (face < opposite &&
              source_edge_is_internal_isolation_seam(
                  options, faceCount, result.regionByFace, face, opposite, key)) {
            region.internalIsolationSeamTopology.push_back(key);
          }
          continue;
        }
        region.boundaryEdgeTopology.push_back(key);
        boundaryAdjacency[a].push_back(b);
        boundaryAdjacency[b].push_back(a);
      }
    }
    std::sort(region.boundaryEdgeTopology.begin(), region.boundaryEdgeTopology.end());
    region.boundaryEdgeTopology.erase(
        std::unique(region.boundaryEdgeTopology.begin(),
                    region.boundaryEdgeTopology.end()),
        region.boundaryEdgeTopology.end());
    std::sort(region.internalIsolationSeamTopology.begin(),
              region.internalIsolationSeamTopology.end());
    region.internalIsolationSeamTopology.erase(
        std::unique(region.internalIsolationSeamTopology.begin(),
                    region.internalIsolationSeamTopology.end()),
        region.internalIsolationSeamTopology.end());
    region.eulerCharacteristic = static_cast<int>(regionVertices.size()) -
                                 static_cast<int>(regionEdges.size()) +
                                 static_cast<int>(region.sourceFaces.size());
    std::set<int> unvisitedBoundary;
    for (auto &[vertex, neighbors] : boundaryAdjacency) {
      std::sort(neighbors.begin(), neighbors.end());
      neighbors.erase(std::unique(neighbors.begin(), neighbors.end()), neighbors.end());
      if (neighbors.size() != 2U) {
        result.valid = false;
        return result;
      }
      unvisitedBoundary.insert(vertex);
    }
    while (!unvisitedBoundary.empty()) {
      ++region.boundaryLoopCount;
      std::vector<int> stack{*unvisitedBoundary.begin()};
      while (!stack.empty()) {
        const int vertex = stack.back();
        stack.pop_back();
        if (unvisitedBoundary.erase(vertex) == 0U) continue;
        for (const int neighbor : boundaryAdjacency[vertex]) {
          if (unvisitedBoundary.count(neighbor) != 0U) stack.push_back(neighbor);
        }
      }
    }

    std::uint64_t hash = 1469598103934665603ULL;
    const auto consume = [&](const std::uint64_t value) {
      hash ^= value;
      hash *= 1099511628211ULL;
    };
    consume(static_cast<std::uint64_t>(region.eulerCharacteristic));
    consume(static_cast<std::uint64_t>(region.boundaryLoopCount));
    for (const int face : region.sourceFaces) {
      const auto key = canonical_face(face);
      consume(static_cast<std::uint64_t>(key[0]));
      consume(static_cast<std::uint64_t>(key[1]));
      consume(static_cast<std::uint64_t>(key[2]));
    }
    for (const std::uint64_t key : region.boundaryEdgeTopology) consume(key);
    for (const std::uint64_t key : region.internalIsolationSeamTopology) consume(key);
    region.structuralHash = hash;
  }
  return result;
}

bool source_edge_is_internal_isolation_seam(
    const SurfaceCellTracingOptions &options, const int faceCount,
    const std::vector<int> &regionByFace, const int firstFace,
    const int secondFace, const std::uint64_t edgeKey) {
  if (faceCount <= 0 || firstFace < 0 || secondFace < 0 ||
      firstFace >= faceCount || secondFace >= faceCount ||
      static_cast<int>(regionByFace.size()) != faceCount ||
      regionByFace[static_cast<std::size_t>(firstFace)] < 0 ||
      regionByFace[static_cast<std::size_t>(firstFace)] !=
          regionByFace[static_cast<std::size_t>(secondFace)] ||
      !source_label_arrays_valid(options, faceCount) ||
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
    const std::set<std::uint64_t> &barrierEdges) {
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
    const int vertex0 = static_cast<int>(key >> 32u);
    const int vertex1 = static_cast<int>(key & 0xffffffffu);
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
    const std::set<std::uint64_t> &barrierEdges) {
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
  if (!surface_cell_tracing_detail::source_label_arrays_valid(
          options, static_cast<int>(faces.rows()))) {
    throw std::invalid_argument(
        "source face component/sheet labels must cover every source face.");
  }
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  const std::set<std::uint64_t> barrierEdges =
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
        surface_cell_tracing_detail::append_seed(seeds, seen, point, provenance,
                                                 rail.id);
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
              surface_cell_tracing_detail::edge_key(a, b));
          if (found != edgeFaces.end() && found->second[1] >= 0) {
            const int neighbor = found->second[0] == sample.sourceFace
                                     ? found->second[1]
                                     : found->second[0];
            SurfaceTracePoint opposite;
            opposite.face = neighbor;
            opposite.barycentric =
                surface_cell_tracing_detail::remap_barycentric_to_neighbor(
                    faces, sample.sourceFace, neighbor, sample.barycentric);
            surface_cell_tracing_detail::append_seed(
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
      const int a = static_cast<int>(key >> 32u);
      const int b = static_cast<int>(key & 0xffffffffu);
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
            static_cast<int>(key & 0x7fffffff));
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
  add_vertices(options.singularityVertices, SurfaceSeedProvenance::Singularity);
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
  segment.matching = (4 - (segment.matching % 4) + 4) % 4;
  std::reverse(segment.transitionSourceEdges.begin(),
               segment.transitionSourceEdges.end());
  std::reverse(segment.transitionSourceTopology.begin(),
               segment.transitionSourceTopology.end());
  segment.transitionSourceEdge = segment.transitionSourceEdges.empty()
                                     ? -1
                                     : segment.transitionSourceEdges.back();
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
  const std::set<std::uint64_t> barrierEdges =
      surface_cell_tracing_detail::combined_barrier_edges(options);
  const auto edgeMatchingIndices =
      surface_cell_tracing_detail::edge_matching_indices(edgeFaces);
  const surface_cell_tracing_detail::EdgeTransitionLookup transitionLookup =
      edgeTransitions != nullptr
          ? surface_cell_tracing_detail::edge_transition_lookup(*edgeTransitions)
          : surface_cell_tracing_detail::EdgeTransitionLookup{};
  const surface_cell_tracing_detail::RailIntervalBuildResult railBuild =
      surface_cell_tracing_detail::rail_interval_refs(
          options.authoritativeRails, vertices, faces, edgeFaces);
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
  if (!surface_cell_tracing_detail::source_label_arrays_valid(
          options, static_cast<int>(faces.rows()))) {
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
    if (surface_cell_tracing_detail::contains_vertex(
            options.singularityVertices, initialVertex) &&
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
      const std::uint64_t key =
          surface_cell_tracing_detail::edge_key(a, b);
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
      if (surface_cell_tracing_detail::contains_vertex(
              options.singularityVertices, hitVertex)) {
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
    const std::uint64_t key = surface_cell_tracing_detail::edge_key(a, b);
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
  /// Connected source chart of equal branch orientation.
  std::vector<int> faceChart;
};

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
                     const std::vector<int> &activeFaces,
                     const Eigen::Vector2d &uv, SurfaceTracePoint &point) {
  constexpr double tolerance = 1.0e-10;
  for (const int face : activeFaces) {
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
    std::uint64_t edgeKey,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge);

bool build_planar_phase_frame(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::vector<int> &activeFaces,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
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
  for (const int face : activeFaces) {
    if (face < 0 || face >= faces.rows()) {
      set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::InvalidInput);
      return false;
    }
  }
  const int referenceFace = activeFaces.front();
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
  for (const int face : activeFaces) {
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

  frame.faceBranchRotation.assign(static_cast<std::size_t>(faces.rows()), -1);
  for (const int face : activeFaces) {
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
      effectiveTransitions != nullptr
          ? edge_transition_lookup(*effectiveTransitions)
          : EdgeTransitionLookup{};
  if (effectiveTransitions != nullptr && transitionLookup.duplicate) {
    set_phase_front_failure(failure, SurfacePhaseFrontFailureReason::DuplicateTransitionMetadata);
    return false;
  }

  std::vector<std::vector<int>> equalOrientationAdjacency(
      static_cast<std::size_t>(faces.rows()));
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
    if (frame.faceBranchRotation[static_cast<std::size_t>(first)] ==
        frame.faceBranchRotation[static_cast<std::size_t>(second)]) {
      equalOrientationAdjacency[static_cast<std::size_t>(first)].push_back(
          second);
      equalOrientationAdjacency[static_cast<std::size_t>(second)].push_back(
          first);
    }
  }

  frame.faceChart.assign(static_cast<std::size_t>(faces.rows()), -1);
  int nextChart = 0;
  for (const int seed : activeFaces) {
    if (frame.faceChart[static_cast<std::size_t>(seed)] >= 0) {
      continue;
    }
    std::queue<int> queue;
    queue.push(seed);
    frame.faceChart[static_cast<std::size_t>(seed)] = nextChart;
    while (!queue.empty()) {
      const int face = queue.front();
      queue.pop();
      for (const int adjacent :
           equalOrientationAdjacency[static_cast<std::size_t>(face)]) {
        if (frame.faceChart[static_cast<std::size_t>(adjacent)] >= 0) {
          continue;
        }
        frame.faceChart[static_cast<std::size_t>(adjacent)] = nextChart;
        queue.push(adjacent);
      }
    }
    ++nextChart;
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
  for (const int face : activeFaces) {
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
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces,
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
    std::set<std::pair<int, std::uint64_t>> unique;
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
    const std::uint64_t edgeKey,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
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
        edge_key(found->second.sourceVertex0,
                 found->second.sourceVertex1) != edgeKey ||
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
    const UniformPhaseFrame &frame, const std::vector<int> &activeFaces,
    const Eigen::Vector2d &start,
    const Eigen::Vector2d &end, const int globalBranch,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
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
  for (const int face : activeFaces) {
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
        frame.faceChart[static_cast<std::size_t>(selectedFace)] < 0) {
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
      effectiveTransitions != nullptr
          ? edge_transition_lookup(*effectiveTransitions)
          : EdgeTransitionLookup{};
  if (effectiveTransitions != nullptr && transitionLookup.duplicate) {
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
    std::uint64_t sharedKey = 0;
    int previousEdge = -1;
    int currentEdge = -1;
    for (int firstEdge = 0; firstEdge < 3 && previousEdge < 0; ++firstEdge) {
      const std::uint64_t firstKey = local_edge_key(faces, previous.face, firstEdge);
      for (int secondEdge = 0; secondEdge < 3; ++secondEdge) {
        if (firstKey == local_edge_key(faces, current.face, secondEdge)) {
          sharedKey = firstKey;
          previousEdge = firstEdge;
          currentEdge = secondEdge;
          route.push_back({current.face, sharedKey});
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
      previousEdge = local_edge_for_key(faces, previous.face, route.front().edgeKey);
      currentEdge = local_edge_for_key(faces, current.face, route.back().edgeKey);
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
    std::vector<std::uint64_t> sourceTopology;
    std::vector<authority::TransitionStep> observedSteps;
    sourceEdges.reserve(route.size());
    sourceTopology.reserve(route.size());
    observedSteps.reserve(route.size());
    for (const VertexPathStep &step : route) {
      const bool crossesIsolationSheet =
          !source_faces_compatible(options, transitFace, step.face);
      if (!source_faces_share_component(options, transitFace, step.face) ||
          options.hardFeatureEdges.count(step.edgeKey) != 0 ||
          (options.reliefBarriersEmbedded &&
           options.reliefBarrierEdges.count(step.edgeKey) != 0)) {
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
          transitionLookup, step.edgeKey, transitFace, step.face,
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
              step.edgeKey, sourceEdgeFaces, sourceMatchingIndices,
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
      const auto firstVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey >> 32U),
          static_cast<std::size_t>(vertices.rows()));
      const auto secondVertex = authority::LegacyAuthorityAdapters::source_vertex(
          static_cast<std::int64_t>(step.edgeKey & 0xffffffffULL),
          static_cast<std::size_t>(vertices.rows()));
      if (!firstVertex || !secondVertex) {
        return rejectStepAuthority();
      }
      const auto topology = authority::SourceEdgeTopologyKey::make(
          firstVertex.value(), secondVertex.value());
      if (!topology) {
        return rejectStepAuthority();
      }
      const auto compatibilityTopology = edge_key(
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().first())),
          static_cast<int>(authority::LegacyAuthorityAdapters::to_legacy_index(
              topology.value().second())));
      if (compatibilityTopology != step.edgeKey) {
        return rejectStepAuthority();
      }
      const auto interiorTransition =
          authority::LegacyAuthorityAdapters::interior_transition(
              sourceEdge, sourceMatchingIndices.size());
      if (!interiorTransition) {
        return rejectStepAuthority();
      }
      const auto typedStep = authority::TransitionStep::interior(
          topology.value(),
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
      sourceTopology.push_back(step.edgeKey);
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
    current.transitionSourceEdges = std::move(sourceEdges);
    current.transitionSourceTopology = std::move(sourceTopology);
    current.transitionSourceEdge = current.transitionSourceEdges.empty()
                                       ? -1
                                       : current.transitionSourceEdges.back();
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

bool phase_front_cell_source_scope(
    const SurfacePhaseFrontCell &cell,
    const SurfaceCellTracingOptions &options, int &component, int &sheet,
    std::vector<int> &isolationSheets) {
  component = -1;
  sheet = -1;
  std::set<int> sheets;
  const auto consume_face = [&](const int face) {
    if (face < 0) return false;
    const int candidateComponent =
        face_label_or_default(options.sourceFaceComponents, face, 0);
    const int candidateSheet =
        face_label_or_default(options.sourceFaceSheets, face, candidateComponent);
    if (candidateComponent < 0 || candidateSheet < 0) return false;
    if (component < 0) component = candidateComponent;
    if (component != candidateComponent) return false;
    sheets.insert(candidateSheet);
    return true;
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
  isolationSheets.assign(sheets.begin(), sheets.end());
  if (isolationSheets.size() == 1U) sheet = isolationSheets.front();
  return component >= 0 && !isolationSheets.empty();
}

SurfacePhaseFrontFailureReason assign_open_front_boundary_authority(
    const Eigen::MatrixXi &faces, const SurfaceCellTracingOptions &options,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const std::vector<SurfaceTraceSegment> &path, SurfaceFrontEdge &edge) {
  if (faces.cols() != 3 || path.empty() ||
      !edge.sourceRouteEdges.empty() || !edge.sourceRouteTopology.empty()) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  const auto &incident = sourceEdgeFaces;
  const auto &sourceEdgeIndices = sourceMatchingIndices;
  std::optional<SurfaceFrontBoundaryKind> kind;
  std::set<std::uint64_t> seenTopology;
  int railId = -1;
  constexpr double tolerance = 1.0e-9;
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
    const std::uint64_t topology = edge_key(a, b);
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
      segmentKind = SurfaceFrontBoundaryKind::HardRail;
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
    if (edge.sourceRouteTopology.empty() ||
        edge.sourceRouteTopology.back() != topology) {
      if (!seenTopology.insert(topology).second) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      edge.sourceRouteTopology.push_back(topology);
      if (segmentKind != SurfaceFrontBoundaryKind::GenuineSourceBoundary) {
        edge.sourceRouteEdges.push_back(foundIndex->second);
      }
    }
    if (segment.railId >= 0) {
      if (railId >= 0 && railId != segment.railId) {
        return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
      }
      railId = segment.railId;
    }
  }
  if (!kind.has_value() || edge.sourceRouteTopology.empty()) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
  if ((*kind == SurfaceFrontBoundaryKind::GenuineSourceBoundary &&
       !edge.sourceRouteEdges.empty()) ||
      (*kind != SurfaceFrontBoundaryKind::GenuineSourceBoundary &&
       (edge.sourceRouteEdges.size() != edge.sourceRouteTopology.size() ||
        std::any_of(edge.sourceRouteEdges.begin(), edge.sourceRouteEdges.end(),
                    [](const int sourceEdge) { return sourceEdge < 0; })))) {
    return SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority;
  }
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
    const SurfaceCellTracingOptions &options, SurfacePhaseFrontCell &cell) {
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
  if (!phase_front_cell_source_scope(cell, options, cell.sourceComponent,
                                     cell.sourceSheet, cell.sourceIsolationSheets)) {
    return false;
  }
  cell.orientationValidated = true;
  return true;
}

} // namespace

SurfacePhaseFrontResult build_uniform_phase_front_for_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const std::vector<int> &activeFaces,
    const SurfaceCellTracingOptions &options,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching,
    const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontResult result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted) {
    return result;
  }

  // Applicability is decided before authoritative transition metadata is
  // consumed. The bounded uniform producer currently covers planar,
  // rectangular, globally phase-compatible domains without singularities.
  // Unsupported topology is NotApplicable; malformed authoritative metadata
  // on an applicable domain is Rejected and must remain fail-closed.
  if (!options.singularityVertices.empty()) {
    return result;
  }
  UniformPhaseFrame applicabilityFrame;
  SurfacePhaseFrontFailure applicabilityFailure;
  if (!build_planar_phase_frame(vertices, faces, faceAxisX, faceAxisY,
                                activeFaces, sourceEdgeFaces,
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
                                activeFaces, sourceEdgeFaces,
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
    int cell = -1;
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
      SurfacePhaseFrontCell cell;
      cell.id = static_cast<int>(result.cells.size());
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
            sourceFace >= static_cast<int>(frame.faceChart.size())) {
          set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::MissingFaceState, cell.id, corner, sourceFace);
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
                edgeMatching, edgeEffort, edgeTransitions, options, cell.id,
                side, result.failure,
                cell.boundaryPaths[static_cast<std::size_t>(side)])) {
          return result;
        }
      }
      if (!orient_and_validate_phase_front_cell(
              vertices, faces, frame, std::min(stepU, stepV), options, cell)) {
        set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidCellOrientation, cell.id);
        return result;
      }

      const int cellId = cell.id;
      for (int side = 0; side < 4; ++side) {
        const auto &path = cell.boundaryPaths[static_cast<std::size_t>(side)];
        SurfaceFrontEdge edge;
        edge.from = cell.corners[static_cast<std::size_t>(side)];
        edge.to = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
        const Eigen::Vector2i latticeDelta =
            cell.lattice[static_cast<std::size_t>((side + 1) % 4)]
                .latticeCoordinate -
            cell.lattice[static_cast<std::size_t>(side)].latticeCoordinate;
        if (latticeDelta == Eigen::Vector2i(1, 0)) {
          edge.family = 0;
          edge.advanceSign = 1;
        } else if (latticeDelta == Eigen::Vector2i(0, 1)) {
          edge.family = 1;
          edge.advanceSign = 1;
        } else if (latticeDelta == Eigen::Vector2i(-1, 0)) {
          edge.family = 0;
          edge.advanceSign = -1;
        } else if (latticeDelta == Eigen::Vector2i(0, -1)) {
          edge.family = 1;
          edge.advanceSign = -1;
        } else {
          set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidLatticeEdge, cell.id, side);
          return result;
        }
        edge.fromLattice = cell.lattice[static_cast<std::size_t>(side)];
        edge.toLattice =
            cell.lattice[static_cast<std::size_t>((side + 1) % 4)];
        edge.filledCell = cellId;
        edge.filledSide = side;
        edge.sourceComponent = cell.sourceComponent;
        edge.sourceSheet = cell.sourceSheet;
        edge.sourceIsolationSheets = cell.sourceIsolationSheets;
        const int edgeId = static_cast<int>(result.edges.size());
        result.edges.push_back(edge);
        const Eigen::Vector2i from = edge.fromLattice.latticeCoordinate;
        const Eigen::Vector2i to = edge.toLattice.latticeCoordinate;
        const int fromNode = node_index(from.x(), from.y());
        const int toNode = node_index(to.x(), to.y());
        const auto key = std::minmax(fromNode, toNode);
        const std::pair<int, int> canonical{key.first, key.second};
        const auto found = openEdges.find(canonical);
        if (found == openEdges.end()) {
          openEdges.emplace(canonical, EdgeOwner{edgeId, cellId});
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
              first.sourceComponent != second.sourceComponent) {
            set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::FrontOwnershipConflict, cell.id, side);
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
  for (const auto &[key, owner] : openEdges) {
    (void)key;
    SurfaceFrontEdge &edge =
        result.edges[static_cast<std::size_t>(owner.edge)];
    if (edge.filledCell < 0 ||
        edge.filledCell >= static_cast<int>(result.cells.size()) ||
        edge.filledSide < 0 || edge.filledSide >= 4) {
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority,
          edge.filledCell, edge.filledSide);
      return result;
    }
    const auto boundaryReason = assign_open_front_boundary_authority(
        faces, options, sourceEdgeFaces, sourceMatchingIndices,
        result.cells[static_cast<std::size_t>(edge.filledCell)]
            .boundaryPaths[static_cast<std::size_t>(edge.filledSide)],
        edge);
    if (boundaryReason != SurfacePhaseFrontFailureReason::None) {
      set_phase_front_failure(result.failure, boundaryReason, edge.filledCell,
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
    if (!cell.orientationValidated || cell.sourceComponent < 0 ||
        cell.sourceIsolationSheets.empty()) {
      set_phase_front_failure(result.failure, SurfacePhaseFrontFailureReason::InvalidFinalCellState, cell.id);
      return result;
    }
  }
  for (const SurfaceFrontEdge &edge : result.edges) {
    const bool hasTwin = edge.oppositeEdge >= 0;
    if (edge.filledCell < 0 || edge.unfilledSide != 0 ||
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
  int face = -1;
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
                             SurfaceTracePoint &point) {
  constexpr double tolerance = kPeriodicChartCoverageTolerance;
  bool found = false;
  std::array<int, 3> bestKey{
      std::numeric_limits<int>::max(), std::numeric_limits<int>::max(),
      std::numeric_limits<int>::max()};
  Eigen::RowVector3d bestBarycentric = Eigen::RowVector3d::Zero();
  int bestFace = -1;
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
      bestFace = triangle.face;
    }
  }
  if (!found) {
    return false;
  }
  if (!canonicalize_periodic_chart_barycentric(bestBarycentric)) {
    return false;
  }
  point.face = bestFace;
  point.barycentric = bestBarycentric;
  return true;
}

std::vector<SurfaceTraceSegment> periodic_chart_segment(
    const std::vector<PeriodicChartTriangle> &triangles,
    const Eigen::Vector2d &start, const Eigen::Vector2d &end,
    const int family, const int sign,
    const std::map<std::uint64_t, int> &matchingIndices,
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
    SurfaceTraceSegment segment;
    segment.face = selected->face;
    segment.startBarycentric = bary0;
    segment.endBarycentric = bary1;
    segment.family = family;
    segment.sign = sign;
    segment.sourceChart = 0;
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
    if (selected == nullptr || selected->face < 0 ||
        selected->face >= static_cast<int>(faceBranchRotation.size()) ||
        faceBranchRotation[static_cast<std::size_t>(selected->face)] < 0) {
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
        faceBranchRotation[static_cast<std::size_t>(selected->face)] +
        globalBranch);
    int family = 0;
    int sign = 1;
    family_sign_from_branch(localBranch, family, sign);

    SurfaceTraceSegment segment;
    segment.face = selected->face;
    segment.startBarycentric = bary0;
    segment.endBarycentric = bary1;
    segment.family = family;
    segment.sign = sign;
    segment.sourceChart = 0;
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

SurfacePhaseFrontResult build_periodic_annulus_phase_front_for_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const std::vector<int> &activeFaces,
    const SurfaceCellTracingOptions &options,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontResult result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted || !options.singularityVertices.empty() ||
      activeFaces.empty()) {
    return result;
  }

  std::set<int> activeVertices;
  std::map<std::uint64_t, std::vector<int>> edgeFaces;
  std::map<std::uint64_t, std::pair<int, int>> edgeVertices;
  std::map<int, std::set<int>> vertexAdjacency;
  for (const int face : activeFaces) {
    if (face < 0 || face >= faces.rows()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicTopology);
      return result;
    }
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
      const std::uint64_t key = edge_key(a, b);
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
    std::vector<int> candidates;
    for (const int face : activeFaces) {
      if (face_contains_only(faces, face, quadVertices)) candidates.push_back(face);
    }
    std::sort(candidates.begin(), candidates.end(), [&](int a, int b) {
      return canonical_face_vertices(faces, a) < canonical_face_vertices(faces, b);
    });
    return candidates;
  };

  // Adjacent graph-distance rings can admit more than one source-topologically
  // valid bijection through a triangulated strip (for example, the two
  // diagonals of the same logical strip).  Source vertex numbering is not an
  // authority for choosing between them.  Build the same reciprocal field
  // transition authority used by tracing/holonomy before selecting any ring
  // correspondence, then choose the unique candidate with minimum transported
  // cross-field alignment energy.  Exact/effectively-equal field candidates
  // are rejected rather than tie-broken by source IDs or enumeration order.
  const auto incident = edge_faces(faces, activeFaces);
  const auto &matchingIndices = sourceMatchingIndices;
  const bool hasTransitions = edgeTransitions != nullptr && !edgeTransitions->empty();
  const EdgeTransitionLookup transitionLookup =
      hasTransitions ? edge_transition_lookup(*edgeTransitions) : EdgeTransitionLookup{};
  if (hasTransitions && transitionLookup.duplicate) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }

  struct RingCandidateAuthority {
    std::vector<int> vertices;
    std::set<int> stripFaces;
    double score = std::numeric_limits<double>::infinity();
    int seedBranch = -1;
    bool branchAmbiguous = false;
  };
  struct DualNeighbor {
    int face = -1;
    std::uint64_t edge = 0;
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
    std::map<int, std::vector<DualNeighbor>> dual;
    for (const int face : candidate.stripFaces) dual[face] = {};
    for (const auto &[key, pair] : incident) {
      if (pair[0] < 0 || pair[1] < 0 ||
          candidate.stripFaces.count(pair[0]) == 0U ||
          candidate.stripFaces.count(pair[1]) == 0U) {
        continue;
      }
      dual[pair[0]].push_back({pair[1], key});
      dual[pair[1]].push_back({pair[0], key});
    }
    if (dual.size() != candidate.stripFaces.size()) return false;
    for (auto &[face, neighbors] : dual) {
      (void)face;
      std::sort(neighbors.begin(), neighbors.end(), [&](const DualNeighbor &a,
                                                        const DualNeighbor &b) {
        const auto aKey = canonical_face_vertices(faces, a.face);
        const auto bKey = canonical_face_vertices(faces, b.face);
        if (aKey != bKey) return aKey < bKey;
        return a.edge < b.edge;
      });
    }
    int startFace = -1;
    std::array<int, 3> startKey{std::numeric_limits<int>::max(),
                                std::numeric_limits<int>::max(),
                                std::numeric_limits<int>::max()};
    for (const int face : candidate.stripFaces) {
      const auto key = canonical_face_vertices(faces, face);
      if (key < startKey) {
        startKey = key;
        startFace = face;
      }
    }
    if (startFace < 0) return false;

    std::array<double, 4> branchScores{
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::infinity()};
    for (int seedBranch = 0; seedBranch < 4; ++seedBranch) {
      std::map<int, int> branchByFace;
      std::queue<int> pending;
      branchByFace[startFace] = seedBranch;
      pending.push(startFace);
      bool validBranch = true;
      while (!pending.empty() && validBranch) {
        const int sourceFace = pending.front();
        pending.pop();
        const int sourceBranch = branchByFace[sourceFace];
        int sourceFamily = 0;
        int sourceSign = 1;
        family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
        const Eigen::RowVector3d sourceDirection = project_tangent(
            axis_for_family(faceAxisX, faceAxisY, sourceFace, sourceFamily,
                            sourceSign),
            face_normal(vertices, faces, sourceFace));
        if (sourceDirection.squaredNorm() == 0.0) {
          validBranch = false;
          break;
        }
        for (const DualNeighbor &neighbor : dual[sourceFace]) {
          if (branchByFace.find(neighbor.face) != branchByFace.end()) {
            continue; // Cycle closure is validated by periodic holonomy below.
          }
          const BranchTransitionResult forward = resolve_branch_transition(
              vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
              transitionLookup, neighbor.edge, sourceFace, neighbor.face,
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
              axis_for_family(faceAxisX, faceAxisY, neighbor.face, targetFamily,
                              targetSign),
              face_normal(vertices, faces, neighbor.face));
          const BranchTransitionResult reverse = resolve_branch_transition(
              vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
              transitionLookup, neighbor.edge, neighbor.face, sourceFace,
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
        const auto found = incident.find(edge_key(a, b));
        if (found == incident.end()) return false;
        bool observed = false;
        for (const int face : found->second) {
          if (face < 0 || candidate.stripFaces.count(face) == 0U) continue;
          const auto branchFound = branchByFace.find(face);
          if (branchFound == branchByFace.end()) return false;
          const int expectedBranch =
              normalized_branch(branchFound->second + branchOffset);
          int family = 0;
          int sign = 1;
          family_sign_from_branch(expectedBranch, family, sign);
          const Eigen::RowVector3d fieldDirection = project_tangent(
              axis_for_family(faceAxisX, faceAxisY, face, family, sign),
              face_normal(vertices, faces, face));
          const Eigen::RowVector3d edgeDirection =
              edge_direction_in_face(a, b, face);
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
        // The V-family is oriented from the previous source ring to the next.
        if (!accumulate_edge_score(
                previous[static_cast<std::size_t>(u)],
                candidate.vertices[static_cast<std::size_t>(u)], 0, true)) {
          validBranch = false;
          break;
        }
        // The periodic U-family is the reciprocal orthogonal family.  Its line
        // orientation is intentionally sign-free because 4-RoSy family lines
        // are unoriented around the annulus.
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
    std::map<std::vector<int>, std::set<int>> topologyCandidates;
    for (int direction : {1, -1}) {
      for (int offset = 0; offset < ringSize; ++offset) {
        std::vector<int> candidate(static_cast<std::size_t>(ringSize));
        for (int u = 0; u < ringSize; ++u) {
          const int index = (offset + direction * u) % ringSize;
          candidate[static_cast<std::size_t>(u)] =
              raw[static_cast<std::size_t>((index + ringSize) % ringSize)];
        }
        bool compatible = true;
        std::set<int> stripFaces;
        for (int u = 0; u < ringSize && compatible; ++u) {
          const int next = (u + 1) % ringSize;
          if (edgeFaces.count(edge_key(previous[static_cast<std::size_t>(u)],
                                       candidate[static_cast<std::size_t>(u)])) == 0U) {
            compatible = false;
            break;
          }
          const std::array<int, 4> quad{
              previous[static_cast<std::size_t>(u)],
              previous[static_cast<std::size_t>(next)],
              candidate[static_cast<std::size_t>(next)],
              candidate[static_cast<std::size_t>(u)]};
          const std::vector<int> pair = quad_faces(quad);
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
      if (edgeFaces.count(edge_key(a, b)) == 0U) return result;
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
  for (const int face : activeFaces) {
    PeriodicChartTriangle triangle;
    triangle.face = face;
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
  std::set<int> firstStripFaces;
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
  std::map<int, std::vector<int>> dual;
  for (const int face : firstStripFaces) dual[face] = {};
  for (const auto &[key, pair] : incident) {
    if (pair[0] >= 0 && pair[1] >= 0 && firstStripFaces.count(pair[0]) != 0U &&
        firstStripFaces.count(pair[1]) != 0U) {
      dual[pair[0]].push_back(pair[1]);
      dual[pair[1]].push_back(pair[0]);
    }
  }
  for (auto &[face, neighbors] : dual) {
    (void)face;
    std::sort(neighbors.begin(), neighbors.end(), [&](int a, int b) {
      return canonical_face_vertices(faces, a) < canonical_face_vertices(faces, b);
    });
    if (neighbors.size() != 2U) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
  }
  auto canonical_face_cycle = [&](int firstNeighborIndex) {
    int startFace = -1;
    std::array<int, 3> startKey{std::numeric_limits<int>::max(),
                                std::numeric_limits<int>::max(),
                                std::numeric_limits<int>::max()};
    for (const auto &[face, neighbors] : dual) {
      (void)neighbors;
      const auto key = canonical_face_vertices(faces, face);
      if (key < startKey) { startKey = key; startFace = face; }
    }
    std::vector<int> cycle;
    cycle.reserve(dual.size());
    cycle.push_back(startFace);
    int previous = startFace;
    int current = dual[startFace][static_cast<std::size_t>(firstNeighborIndex)];
    while (current != startFace && cycle.size() <= dual.size()) {
      cycle.push_back(current);
      const auto &neighbors = dual[current];
      const int next = neighbors[0] == previous ? neighbors[1] : neighbors[0];
      previous = current;
      current = next;
    }
    if (current != startFace || cycle.size() != dual.size()) return std::vector<int>{};
    return cycle;
  };
  std::vector<int> faceCycleA = canonical_face_cycle(0);
  std::vector<int> faceCycleB = canonical_face_cycle(1);
  auto face_cycle_key = [&](const std::vector<int> &cycle) {
    std::vector<std::array<int, 3>> key;
    for (const int face : cycle) key.push_back(canonical_face_vertices(faces, face));
    return key;
  };
  const std::vector<int> faceCycle =
      face_cycle_key(faceCycleB) < face_cycle_key(faceCycleA) ? faceCycleB : faceCycleA;
  if (faceCycle.empty()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }
  int totalMatching = 0;
  std::vector<int> holonomyRoute;
  std::vector<std::uint64_t> holonomyRouteTopology;
  for (std::size_t index = 0; index < faceCycle.size(); ++index) {
    const int sourceFace = faceCycle[index];
    const int targetFace = faceCycle[(index + 1U) % faceCycle.size()];
    std::uint64_t sharedKey = 0;
    for (int a = 0; a < 3 && sharedKey == 0; ++a) {
      const std::uint64_t key = local_edge_key(faces, sourceFace, a);
      if (local_edge_for_key(faces, targetFace, key) >= 0) sharedKey = key;
    }
    if (sharedKey == 0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                              -1, -1, sourceFace, targetFace);
      return result;
    }
    int sourceEdge = -1;
    if (!source_edge_provenance(
            sharedKey, sourceEdgeFaces, sourceMatchingIndices,
            transitionLookup, hasTransitions ? edgeTransitions : nullptr,
            sourceEdge)) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                              -1, -1, sourceFace, targetFace, -1, sourceEdge);
      return result;
    }
    holonomyRoute.push_back(sourceEdge);
    holonomyRouteTopology.push_back(sharedKey);
    if (hasTransitions) {
      const auto found = transitionLookup.byEdge.find(sharedKey);
      if (found == transitionLookup.byEdge.end() ||
          !transition_faces_match(found->second, sourceFace, targetFace)) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                                -1, -1, sourceFace, targetFace, -1, sourceEdge);
        return result;
      }
      int matching = found->second.matching;
      if (found->second.secondFace == sourceFace) matching = -matching;
      totalMatching += matching;
    } else if (edgeMatching != nullptr && edgeMatching->size() > 0) {
      const auto matchingIndex = matchingIndices.find(sharedKey);
      if (matchingIndex == matchingIndices.end() ||
          matchingIndex->second >= edgeMatching->size()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch,
                                -1, -1, sourceFace, targetFace, -1, sourceEdge);
        return result;
      }
      int matching = (*edgeMatching)[matchingIndex->second];
      const auto topology = incident.find(sharedKey);
      if (topology != incident.end() && topology->second[1] == sourceFace) matching = -matching;
      totalMatching += matching;
    }
  }
  if (normalized_branch(totalMatching) != 0) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
    return result;
  }

  result.disposition = SurfaceCellProducerDisposition::Rejected;
  result.periodicHolonomies.emplace_back();
  SurfacePeriodicHolonomy &periodicHolonomy = result.periodicHolonomies.back();
  periodicHolonomy.quarterTurnRotation = 0;
  periodicHolonomy.latticeTranslation = {result.gridU, 0};
  periodicHolonomy.sourceRouteEdges = std::move(holonomyRoute);
  periodicHolonomy.sourceRouteTopology = std::move(holonomyRouteTopology);
  const int component = face_label_or_default(options.sourceFaceComponents,
                                               activeFaces.front(), 0);
  const int sheet = face_label_or_default(options.sourceFaceSheets,
                                           activeFaces.front(), component);
  periodicHolonomy.sourceComponent = component;
  periodicHolonomy.sourceSheet = sheet;
  for (int layer = 0; layer < maxDistance; ++layer) {
    const std::uint64_t key = edge_key(
        rings[static_cast<std::size_t>(layer)][0],
        rings[static_cast<std::size_t>(layer + 1)][0]);
    int sourceEdge = -1;
    if (!source_edge_provenance(
            key, sourceEdgeFaces, sourceMatchingIndices, transitionLookup,
            hasTransitions ? edgeTransitions : nullptr, sourceEdge)) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::PeriodicHolonomyMismatch);
      return result;
    }
    periodicHolonomy.cutSourceEdges.push_back(sourceEdge);
    periodicHolonomy.cutSourceTopology.push_back(key);
  }
  periodicHolonomy =
      surface_cell_tracing_detail::canonicalize_periodic_holonomy(
          std::move(periodicHolonomy));

  const double stepV = height / static_cast<double>(result.gridV);
  const int columns = result.gridU + 1;
  const int rows = result.gridV + 1;
  std::vector<SurfaceTracePoint> points(static_cast<std::size_t>(columns * rows));
  const auto node_index = [columns](int u, int v) { return v * columns + u; };
  for (int v = 0; v < rows; ++v) {
    for (int u = 0; u < columns; ++u) {
      const Eigen::Vector2d uv(
          periodicCoordinates[static_cast<std::size_t>(u)], stepV * v);
      if (!point_on_periodic_chart(chartTriangles, uv,
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
  const auto canonical_node = [&](const Eigen::Vector2i &coordinate) {
    int u = coordinate.x();
    if (u == result.gridU) u = 0;
    return coordinate.y() * result.gridU + u;
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
      SurfacePhaseFrontCell cell;
      cell.id = static_cast<int>(result.cells.size());
      cell.sourceComponent = component;
      cell.sourceSheet = sheet;
      for (int corner = 0; corner < 4; ++corner) {
        cell.corners[static_cast<std::size_t>(corner)] =
            points[static_cast<std::size_t>(nodeIds[corner])];
        auto &state = cell.lattice[static_cast<std::size_t>(corner)];
        state.phase = uv[static_cast<std::size_t>(corner)];
        state.latticeCoordinate = {
            corner == 1 || corner == 2 ? u + 1 : u,
            corner >= 2 ? v + 1 : v};
        state.sourceChart = 0;
      }
      for (int side = 0; side < 4; ++side) {
        const Eigen::Vector2i delta =
            cell.lattice[static_cast<std::size_t>((side + 1) % 4)].latticeCoordinate -
            cell.lattice[static_cast<std::size_t>(side)].latticeCoordinate;
        const int family = delta.x() != 0 ? 0 : 1;
        const int sign = (delta.x() + delta.y()) >= 0 ? 1 : -1;
        cell.boundaryPaths[static_cast<std::size_t>(side)] = periodic_chart_segment(
            chartTriangles, uv[static_cast<std::size_t>(side)],
            uv[static_cast<std::size_t>((side + 1) % 4)], family, sign,
            matchingIndices, transitionLookup,
            hasTransitions ? edgeTransitions : nullptr);
        if (cell.boundaryPaths[static_cast<std::size_t>(side)].empty()) {
          set_phase_front_failure(result.failure,
                                  SurfacePhaseFrontFailureReason::InvalidPeriodicChart,
                                  cell.id, side);
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
                                cell.id);
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
                                cell.id);
        return result;
      }
      if (loopNormal.dot(expectedNormal) < 0.0) {
        reverse_phase_front_cell_cycle(cell);
        positions = phase_front_corner_positions(vertices, faces, cell);
        loopNormal = phase_front_loop_normal(positions);
      }
      if (loopNormal.dot(expectedNormal) <= 0.0 ||
          !phase_front_cell_source_scope(cell, options, cell.sourceComponent,
                                         cell.sourceSheet,
                                         cell.sourceIsolationSheets)) {
        set_phase_front_failure(result.failure,
                                SurfacePhaseFrontFailureReason::InvalidCellOrientation,
                                cell.id);
        return result;
      }
      cell.orientationValidated = true;

      for (int side = 0; side < 4; ++side) {
        SurfaceFrontEdge edge;
        edge.from = cell.corners[static_cast<std::size_t>(side)];
        edge.to = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
        edge.fromLattice = cell.lattice[static_cast<std::size_t>(side)];
        edge.toLattice = cell.lattice[static_cast<std::size_t>((side + 1) % 4)];
        const Eigen::Vector2i delta = edge.toLattice.latticeCoordinate -
                                      edge.fromLattice.latticeCoordinate;
        edge.family = delta.x() != 0 ? 0 : 1;
        edge.advanceSign = (delta.x() + delta.y()) >= 0 ? 1 : -1;
        edge.filledCell = cell.id;
        edge.filledSide = side;
        edge.sourceComponent = cell.sourceComponent;
        edge.sourceSheet = cell.sourceSheet;
        edge.sourceIsolationSheets = cell.sourceIsolationSheets;
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
                                    cell.id, side);
            return result;
          }
          first.oppositeEdge = edgeId;
          second.oppositeEdge = found->second.edge;
          first.unfilledSide = 0;
          second.unfilledSide = 0;
          const bool periodic =
              first.fromLattice.latticeCoordinate.x() !=
                  second.toLattice.latticeCoordinate.x() ||
              first.toLattice.latticeCoordinate.x() !=
                  second.fromLattice.latticeCoordinate.x();
          if (periodic) {
            first.boundaryKind = SurfaceFrontBoundaryKind::PeriodicCut;
            second.boundaryKind = SurfaceFrontBoundaryKind::PeriodicCut;
            first.periodicRelation = 0;
            second.periodicRelation = 0;
            first.sourceRouteEdges = periodicHolonomy.cutSourceEdges;
            second.sourceRouteEdges = periodicHolonomy.cutSourceEdges;
            first.sourceRouteTopology = periodicHolonomy.cutSourceTopology;
            second.sourceRouteTopology = periodicHolonomy.cutSourceTopology;
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
  for (const auto &[key, owner] : openEdges) {
    (void)key;
    auto &edge = result.edges[static_cast<std::size_t>(owner.edge)];
    if (edge.family != 0 ||
        (edge.fromLattice.latticeCoordinate.y() != 0 &&
         edge.fromLattice.latticeCoordinate.y() != result.gridV)) {
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
                              edge.filledCell, owner.edge);
      return result;
    }
    if (edge.filledCell < 0 ||
        edge.filledCell >= static_cast<int>(result.cells.size()) ||
        edge.filledSide < 0 || edge.filledSide >= 4) {
      set_phase_front_failure(
          result.failure,
          SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority,
          edge.filledCell, edge.filledSide);
      return result;
    }
    const auto boundaryReason = assign_open_front_boundary_authority(
        faces, options, sourceEdgeFaces, sourceMatchingIndices,
        result.cells[static_cast<std::size_t>(edge.filledCell)]
            .boundaryPaths[static_cast<std::size_t>(edge.filledSide)],
        edge);
    if (boundaryReason != SurfacePhaseFrontFailureReason::None) {
      set_phase_front_failure(result.failure, boundaryReason, edge.filledCell,
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
    if (edge.filledCell < 0 || edge.unfilledSide != 0 || hasTwin == edge.exterior ||
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


SurfacePhaseFrontResult build_curved_bounded_disk_phase_front_for_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const std::vector<int> &activeFaces,
    const SurfaceCellTracingOptions &options,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontResult result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted || !options.singularityVertices.empty() ||
      activeFaces.empty()) {
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
  for (const int face : activeFaces) {
    if (face < 0 || face >= faces.rows()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(result.failure,
                              SurfacePhaseFrontFailureReason::InvalidInput,
                              -1, -1, face);
      return result;
    }
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
  // the source-face dual graph, independently of row enumeration.
  std::set<int> activeFaceSet(activeFaces.begin(), activeFaces.end());
  std::set<int> visitedFaces;
  std::queue<int> faceQueue;
  faceQueue.push(activeFaces.front());
  while (!faceQueue.empty()) {
    const int face = faceQueue.front();
    faceQueue.pop();
    if (!visitedFaces.insert(face).second) continue;
    for (int corner = 0; corner < 3; ++corner) {
      const auto found = incident.find(local_edge_key(faces, face, corner));
      if (found == incident.end()) continue;
      for (const int adjacent : found->second) {
        if (adjacent >= 0 && adjacent != face &&
            activeFaceSet.count(adjacent) != 0U &&
            visitedFaces.count(adjacent) == 0U) {
          faceQueue.push(adjacent);
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

  std::set<std::uint64_t> boundaryEdgeKeys;
  std::map<int, std::vector<int>> boundaryAdjacency;
  std::map<std::uint64_t, int> boundaryFace;
  for (const auto &[key, pair] : incident) {
    if (pair[1] >= 0) continue;
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
    boundaryFace[key] = face;

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
      const std::uint64_t key = edge_key(a, b);
      const auto foundFace = boundaryFace.find(key);
      if (foundFace == boundaryFace.end()) return false;
      const int face = foundFace->second;
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
  int rootFace = -1;
  std::array<std::array<double, 3>, 3> rootKey{};
  bool haveRoot = false;
  bool ambiguousRoot = false;
  for (const int face : activeFaces) {
    const auto key = face_geometry_key(face);
    if (!haveRoot || key < rootKey) {
      rootFace = face;
      rootKey = key;
      haveRoot = true;
      ambiguousRoot = false;
    } else if (key == rootKey && face != rootFace) {
      ambiguousRoot = true;
    }
  }
  if (!haveRoot || ambiguousRoot) {
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
      hasTransitions ? edge_transition_lookup(*edgeTransitions) : EdgeTransitionLookup{};
  if (hasTransitions && transitionLookup.duplicate) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport);
    return result;
  }

  struct DualStep {
    int face = -1;
    std::uint64_t edge = 0;
  };
  std::vector<std::vector<DualStep>> dual(static_cast<std::size_t>(faces.rows()));
  for (const auto &[key, pair] : incident) {
    if (pair[0] < 0 || pair[1] < 0) continue;
    dual[static_cast<std::size_t>(pair[0])].push_back({pair[1], key});
    dual[static_cast<std::size_t>(pair[1])].push_back({pair[0], key});
  }
  for (const int face : activeFaces) {
    auto &neighbors = dual[static_cast<std::size_t>(face)];
    std::sort(neighbors.begin(), neighbors.end(), [&](const DualStep &a,
                                                      const DualStep &b) {
      const auto ak = face_geometry_key(a.face);
      const auto bk = face_geometry_key(b.face);
      if (ak != bk) return ak < bk;
      return a.edge < b.edge;
    });
  }

  std::vector<int> faceBranchRotation(static_cast<std::size_t>(faces.rows()), -1);
  faceBranchRotation[static_cast<std::size_t>(rootFace)] = 0;
  std::queue<int> pending;
  pending.push(rootFace);
  while (!pending.empty()) {
    const int sourceFace = pending.front();
    pending.pop();
    const int sourceBranch =
        faceBranchRotation[static_cast<std::size_t>(sourceFace)];
    int sourceFamily = 0;
    int sourceSign = 1;
    family_sign_from_branch(sourceBranch, sourceFamily, sourceSign);
    const Eigen::RowVector3d sourceDirection = project_tangent(
        axis_for_family(faceAxisX, faceAxisY, sourceFace, sourceFamily,
                        sourceSign),
        face_normal(vertices, faces, sourceFace));
    if (sourceDirection.squaredNorm() == 0.0) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
          -1, -1, sourceFace);
      return result;
    }
    for (const DualStep &neighbor : dual[static_cast<std::size_t>(sourceFace)]) {
      const BranchTransitionResult forward = resolve_branch_transition(
          vertices, faces, faceAxisX, faceAxisY, incident, matchingIndices,
          transitionLookup, neighbor.edge, sourceFace, neighbor.face,
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
            -1, -1, sourceFace, neighbor.face, -1, sourceEdge);
        return result;
      }
      const int targetBranch =
          branch_from_family_sign(forward.family, forward.sign);
      int &stored = faceBranchRotation[static_cast<std::size_t>(neighbor.face)];
      if (stored < 0) {
        stored = targetBranch;
        pending.push(neighbor.face);
      } else if (stored != targetBranch) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskTransport,
            -1, -1, sourceFace, neighbor.face);
        return result;
      }
    }
  }
  for (const int face : activeFaces) {
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
    const std::uint64_t key = edge_key(a, b);
    const auto foundFace = boundaryFace.find(key);
    if (foundFace == boundaryFace.end()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
      return result;
    }
    const int face = foundFace->second;
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

  const int component = face_label_or_default(options.sourceFaceComponents,
                                               activeFaces.front(), 0);
  const int sheet = face_label_or_default(options.sourceFaceSheets,
                                           activeFaces.front(), component);
  SurfaceBoundedDiskBoundaryPhase boundaryPhase;
  boundaryPhase.sourceComponent = component;
  boundaryPhase.sourceSheet = sheet;
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
      const std::uint64_t edgeTopology = edge_key(a, b);
      const auto foundFace = boundaryFace.find(edgeTopology);
      const auto foundFull = fullIncident.find(edgeTopology);
      if (foundFace == boundaryFace.end() || foundFull == fullIncident.end()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure,
            SurfacePhaseFrontFailureReason::InvalidBoundedDiskBoundaryPhase);
        return result;
      }
      run.sourceFaces.push_back(foundFace->second);
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
            -1, -1, foundFace->second);
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
  consume_boundary_i64(boundaryPhase.sourceComponent);
  consume_boundary_i64(boundaryPhase.sourceSheet);
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
    for (const std::uint64_t edgeTopology : run.sourceEdgeTopology) {
      consume_boundary_hash(edgeTopology);
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
  for (const int face : activeFaces) {
    PeriodicChartTriangle triangle;
    triangle.face = face;
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
              chartTriangles, uv,
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
      SurfacePhaseFrontCell cell;
      cell.id = static_cast<int>(result.cells.size());
      cell.sourceComponent = component;
      cell.sourceSheet = sheet;
      for (int corner = 0; corner < 4; ++corner) {
        cell.corners[static_cast<std::size_t>(corner)] =
            points[static_cast<std::size_t>(nodeIds[corner])];
        const int sourceFace = cell.corners[static_cast<std::size_t>(corner)].face;
        if (sourceFace < 0 ||
            sourceFace >= static_cast<int>(faceBranchRotation.size()) ||
            faceBranchRotation[static_cast<std::size_t>(sourceFace)] < 0) {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::MissingFaceState,
              cell.id, corner, sourceFace);
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
        state.sourceChart = 0;
      }
      const std::array<int, 4> globalBranches{
          chartUBranch, normalized_branch(chartUBranch + 1),
          normalized_branch(chartUBranch + 2),
          normalized_branch(chartUBranch + 3)};
      for (int side = 0; side < 4; ++side) {
        cell.boundaryPaths[static_cast<std::size_t>(side)] =
            bounded_disk_chart_segment(
                chartTriangles, uv[static_cast<std::size_t>(side)],
                uv[static_cast<std::size_t>((side + 1) % 4)],
                globalBranches[static_cast<std::size_t>(side)],
                faceBranchRotation);
        if (cell.boundaryPaths[static_cast<std::size_t>(side)].empty()) {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskChart,
              cell.id, side);
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
            cell.id);
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
            cell.id);
        return result;
      }
      if (loopNormal.dot(expectedNormal) < 0.0) {
        reverse_phase_front_cell_cycle(cell);
        positions = phase_front_corner_positions(vertices, faces, cell);
        loopNormal = phase_front_loop_normal(positions);
      }
      if (loopNormal.dot(expectedNormal) <= 0.0 ||
          !phase_front_cell_source_scope(cell, options, cell.sourceComponent,
                                         cell.sourceSheet,
                                         cell.sourceIsolationSheets)) {
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::InvalidCellOrientation,
            cell.id);
        return result;
      }
      cell.orientationValidated = true;

      for (int side = 0; side < 4; ++side) {
        SurfaceFrontEdge edge;
        edge.from = cell.corners[static_cast<std::size_t>(side)];
        edge.to = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
        edge.fromLattice = cell.lattice[static_cast<std::size_t>(side)];
        edge.toLattice = cell.lattice[static_cast<std::size_t>((side + 1) % 4)];
        const Eigen::Vector2i delta = edge.toLattice.latticeCoordinate -
                                      edge.fromLattice.latticeCoordinate;
        if (delta == Eigen::Vector2i(1, 0)) {
          edge.family = 0;
          edge.advanceSign = 1;
        } else if (delta == Eigen::Vector2i(0, 1)) {
          edge.family = 1;
          edge.advanceSign = 1;
        } else if (delta == Eigen::Vector2i(-1, 0)) {
          edge.family = 0;
          edge.advanceSign = -1;
        } else if (delta == Eigen::Vector2i(0, -1)) {
          edge.family = 1;
          edge.advanceSign = -1;
        } else {
          set_phase_front_failure(
              result.failure, SurfacePhaseFrontFailureReason::InvalidLatticeEdge,
              cell.id, side);
          return result;
        }
        edge.filledCell = cell.id;
        edge.filledSide = side;
        edge.sourceComponent = cell.sourceComponent;
        edge.sourceSheet = cell.sourceSheet;
        edge.sourceIsolationSheets = cell.sourceIsolationSheets;
        const int edgeId = static_cast<int>(result.edges.size());
        result.edges.push_back(edge);
        const int a = node_index(edge.fromLattice.latticeCoordinate.x(),
                                 edge.fromLattice.latticeCoordinate.y());
        const int b = node_index(edge.toLattice.latticeCoordinate.x(),
                                 edge.toLattice.latticeCoordinate.y());
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
              first.sourceComponent != second.sourceComponent) {
            set_phase_front_failure(
                result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing,
                cell.id, side);
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
          if (boundaryEdgeKeys.count(edge_key(a, b)) != 0U) {
            supported = true;
            break;
          }
        }
      }
      if (!supported) return false;
    }
    return !path.empty();
  };
  for (const auto &[key, owner] : openEdges) {
    (void)key;
    auto &edge = result.edges[static_cast<std::size_t>(owner.edge)];
    const Eigen::Vector2i a = edge.fromLattice.latticeCoordinate;
    const Eigen::Vector2i b = edge.toLattice.latticeCoordinate;
    const bool onBoundary =
        (a.x() == 0 && b.x() == 0) ||
        (a.x() == result.gridU && b.x() == result.gridU) ||
        (a.y() == 0 && b.y() == 0) ||
        (a.y() == result.gridV && b.y() == result.gridV);
    if (!onBoundary || edge.filledCell < 0 ||
        edge.filledCell >= static_cast<int>(result.cells.size())) {
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidBoundedDiskFrontPairing,
          edge.filledCell, owner.edge);
      return result;
    }
    const auto &cell = result.cells[static_cast<std::size_t>(edge.filledCell)];
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
          edge.filledCell, owner.edge);
      return result;
    }
    const auto boundaryReason = assign_open_front_boundary_authority(
        faces, options, sourceEdgeFaces, sourceMatchingIndices,
        cell.boundaryPaths[static_cast<std::size_t>(side)], edge);
    if (boundaryReason != SurfacePhaseFrontFailureReason::None) {
      set_phase_front_failure(result.failure, boundaryReason, edge.filledCell,
                              side);
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
    if (edge.filledCell < 0 || edge.unfilledSide != 0 ||
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
    const SurfaceCellTracingOptions &options,
    const std::vector<int> &topologyRegionByFace,
    const std::vector<SurfaceTopologyRegion> &topologyRegions,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    std::vector<SurfaceIsolationSeamTransportCertificate> &certificates) {
  certificates.clear();
  if (faces.cols() != 3 || vertices.cols() != 3 ||
      faceAxisX.rows() != faces.rows() || faceAxisX.cols() != 3 ||
      faceAxisY.rows() != faces.rows() || faceAxisY.cols() != 3 ||
      topologyRegionByFace.size() != static_cast<std::size_t>(faces.rows()) ||
      !source_label_arrays_valid(options, faces.rows())) {
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
      effectiveTransitions != nullptr
          ? edge_transition_lookup(*effectiveTransitions)
          : EdgeTransitionLookup{};
  if (transitionLookup.duplicate) return false;

  std::set<std::pair<int, std::uint64_t>> seen;
  for (const SurfaceTopologyRegion &region : topologyRegions) {
    for (const std::uint64_t seam : region.internalIsolationSeamTopology) {
      const auto foundIncident = incident.find(seam);
      const auto foundIndex = matchingIndices.find(seam);
      if (region.id < 0 || region.sourceComponent < 0 ||
          !seen.insert({region.id, seam}).second ||
          foundIncident == incident.end() || foundIncident->second[0] < 0 ||
          foundIncident->second[1] < 0 ||
          foundIndex == matchingIndices.end() || foundIndex->second < 0) {
        return false;
      }

      int firstFace = foundIncident->second[0];
      int secondFace = foundIncident->second[1];
      if (firstFace == secondFace || firstFace >= faces.rows() ||
          secondFace >= faces.rows() ||
          topologyRegionByFace[static_cast<std::size_t>(firstFace)] !=
              region.id ||
          topologyRegionByFace[static_cast<std::size_t>(secondFace)] !=
              region.id ||
          face_label_or_default(options.sourceFaceComponents, firstFace, 0) !=
              region.sourceComponent ||
          face_label_or_default(options.sourceFaceComponents, secondFace, 0) !=
              region.sourceComponent) {
        return false;
      }

      std::array<int, 3> firstTopology =
          canonical_face_vertices(faces, firstFace);
      std::array<int, 3> secondTopology =
          canonical_face_vertices(faces, secondFace);
      if (firstTopology == secondTopology) return false;
      if (secondTopology < firstTopology) {
        std::swap(firstFace, secondFace);
        std::swap(firstTopology, secondTopology);
      }
      const int firstSheet = face_label_or_default(
          options.sourceFaceSheets, firstFace, region.sourceComponent);
      const int secondSheet = face_label_or_default(
          options.sourceFaceSheets, secondFace, region.sourceComponent);
      if (firstSheet < 0 || secondSheet < 0 || firstSheet == secondSheet ||
          !std::binary_search(region.isolationSheets.begin(),
                              region.isolationSheets.end(), firstSheet) ||
          !std::binary_search(region.isolationSheets.begin(),
                              region.isolationSheets.end(), secondSheet)) {
        return false;
      }
      if (effectiveTransitions != nullptr) {
        const auto transition = transitionLookup.byEdge.find(seam);
        if (transition == transitionLookup.byEdge.end() ||
            transition->second.sourceEdge < 0) {
          return false;
        }
      }

      std::optional<int> forwardQuarterTurn;
      std::optional<int> reverseQuarterTurn;
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
        const int candidateForward = normalized_branch(forward.matching);
        const int candidateReverse = normalized_branch(reverse.matching);
        if (!reverse.valid || targetBranch !=
                                  normalized_branch(sourceBranch +
                                                    candidateForward) ||
            branch_from_family_sign(reverse.family, reverse.sign) !=
                sourceBranch ||
            normalized_branch(candidateForward + candidateReverse) != 0 ||
            (forwardQuarterTurn.has_value() &&
             *forwardQuarterTurn != candidateForward) ||
            (reverseQuarterTurn.has_value() &&
             *reverseQuarterTurn != candidateReverse)) {
          return false;
        }
        forwardQuarterTurn = candidateForward;
        reverseQuarterTurn = candidateReverse;
      }
      if (!forwardQuarterTurn.has_value() ||
          !reverseQuarterTurn.has_value()) {
        return false;
      }

      SurfaceIsolationSeamTransportCertificate certificate;
      certificate.sourceComponent = region.sourceComponent;
      certificate.sourceTopologyRegion = region.id;
      certificate.sourceEdgeTopology = seam;
      certificate.sourceEdgeIndex = foundIndex->second;
      certificate.firstSourceFaceTopology = firstTopology;
      certificate.secondSourceFaceTopology = secondTopology;
      certificate.firstIsolationSheet = firstSheet;
      certificate.secondIsolationSheet = secondSheet;
      certificate.forwardQuarterTurn = *forwardQuarterTurn;
      certificate.reverseQuarterTurn = *reverseQuarterTurn;
      certificate.structuralHash =
          isolation_seam_transport_certificate_hash(certificate);
      certificates.push_back(std::move(certificate));
    }
  }
  std::sort(certificates.begin(), certificates.end());
  return std::adjacent_find(certificates.begin(), certificates.end(),
                            [](const auto &first, const auto &second) {
                              return first.sourceTopologyRegion ==
                                         second.sourceTopologyRegion &&
                                     first.sourceEdgeTopology ==
                                         second.sourceEdgeTopology;
                            }) == certificates.end();
}


SurfacePhaseFrontResult build_uniform_phase_front(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions) {
  SurfacePhaseFrontResult result;
  result.attempted = options.enableUniformPhaseFront;
  if (!result.attempted) return result;
  if (!source_label_arrays_valid(options, faces.rows())) {
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

  const SourceTopologyRegions topology =
      build_source_topology_regions(faces, options);
  if (!topology.valid || topology.regionByFace.size() !=
                             static_cast<std::size_t>(faces.rows()) ||
      (faces.rows() > 0 && topology.regions.empty())) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(result.failure,
                            SurfacePhaseFrontFailureReason::InvalidTopologyRegion);
    return result;
  }
  result.sourceTopologyRegionByFace = topology.regionByFace;
  result.topologyRegions = topology.regions;

  struct RegionWork {
    const SurfaceTopologyRegion *region = nullptr;
    std::vector<int> canonicalVertices;
  };
  std::vector<RegionWork> regions;
  regions.reserve(result.topologyRegions.size());
  for (const SurfaceTopologyRegion &region : result.topologyRegions) {
    RegionWork work;
    work.region = &region;
    std::set<int> uniqueVertices;
    for (const int face : region.sourceFaces) {
      for (int corner = 0; corner < 3; ++corner) {
        uniqueVertices.insert(faces(face, corner));
      }
    }
    work.canonicalVertices.assign(uniqueVertices.begin(), uniqueVertices.end());
    regions.push_back(std::move(work));
  }
  std::sort(regions.begin(), regions.end(), [](const RegionWork &a,
                                                const RegionWork &b) {
    if (a.region->structuralHash != b.region->structuralHash) {
      return a.region->structuralHash < b.region->structuralHash;
    }
    return a.canonicalVertices < b.canonicalVertices;
  });

  struct RegionBuild {
    const RegionWork *work = nullptr;
    SurfacePhaseFrontResult result;
  };
  std::vector<RegionBuild> regionBuilds;
  regionBuilds.reserve(regions.size());
  bool anyProduced = false;
  int firstUnsupportedRegion = -1;

  const auto normalize_scope = [&](SurfacePhaseFrontResult &local,
                                   const SurfaceTopologyRegion &region) {
    const int singleIsolationSheet =
        region.isolationSheets.size() == 1U ? region.isolationSheets.front() : -1;
    const auto normalize_sheets = [&](std::vector<int> &sheets) {
      std::sort(sheets.begin(), sheets.end());
      sheets.erase(std::unique(sheets.begin(), sheets.end()), sheets.end());
      if (sheets.empty()) sheets = region.isolationSheets;
      for (const int sheet : sheets) {
        if (!std::binary_search(region.isolationSheets.begin(),
                                region.isolationSheets.end(), sheet)) {
          return false;
        }
      }
      return true;
    };
    for (auto &relation : local.periodicHolonomies) {
      relation.sourceComponent = region.sourceComponent;
      relation.sourceTopologyRegion = region.id;
      relation.sourceSheet = singleIsolationSheet;
      relation.sourceIsolationSheets = region.isolationSheets;
      relation = canonicalize_periodic_holonomy(std::move(relation));
    }
    for (auto &phase : local.boundedDiskBoundaryPhases) {
      phase.sourceComponent = region.sourceComponent;
      phase.sourceTopologyRegion = region.id;
      phase.sourceSheet = singleIsolationSheet;
      phase.sourceIsolationSheets = region.isolationSheets;
    }
    for (auto &cell : local.cells) {
      cell.sourceTopologyRegion = region.id;
      if (cell.sourceComponent != region.sourceComponent ||
          !normalize_sheets(cell.sourceIsolationSheets)) {
        return false;
      }
      cell.sourceSheet = cell.sourceIsolationSheets.size() == 1U
                             ? cell.sourceIsolationSheets.front()
                             : -1;
    }
    for (auto &edge : local.edges) {
      edge.sourceTopologyRegion = region.id;
      edge.sourceComponent = region.sourceComponent;
      if (!normalize_sheets(edge.sourceIsolationSheets)) return false;
      edge.sourceSheet = edge.sourceIsolationSheets.size() == 1U
                             ? edge.sourceIsolationSheets.front()
                             : singleIsolationSheet;
    }
    return true;
  };

  const auto retain_bounded_disk_boundary_phases =
      [&](SurfacePhaseFrontResult &local) {
        for (auto &phase : local.boundedDiskBoundaryPhases) {
          result.boundedDiskBoundaryPhases.push_back(std::move(phase));
        }
        local.boundedDiskBoundaryPhases.clear();
      };

  for (const RegionWork &work : regions) {
    const SurfaceTopologyRegion &region = *work.region;
    SurfacePhaseFrontResult local = build_uniform_phase_front_for_faces(
        vertices, faces, faceAxisX, faceAxisY, targetSize, region.sourceFaces,
        options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,
        edgeEffort, edgeTransitions);
    if (local.disposition == SurfaceCellProducerDisposition::NotApplicable) {
      local = build_periodic_annulus_phase_front_for_faces(
          vertices, faces, faceAxisX, faceAxisY, targetSize, region.sourceFaces,
          options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,
          edgeEffort, edgeTransitions);
    }
    if (local.disposition == SurfaceCellProducerDisposition::NotApplicable) {
      local = build_curved_bounded_disk_phase_front_for_faces(
          vertices, faces, faceAxisX, faceAxisY, targetSize, region.sourceFaces,
          options, sourceEdgeFaces, sourceMatchingIndices, edgeMatching,
          edgeEffort, edgeTransitions);
    }
    if (!normalize_scope(local, region)) {
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
      if (!local.succeeded || local.cells.empty()) {
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
    if (!anyProduced) return result;
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    const SurfaceTopologyRegion &unsupported =
        *regionBuilds[static_cast<std::size_t>(firstUnsupportedRegion)]
             .work->region;
    const int canonicalFace = unsupported.sourceFaces.empty()
                                  ? -1
                                  : unsupported.sourceFaces.front();
    // Keep the established public reason while producer ownership is migrated
    // from local isolation sheets to exact source-topological regions.
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::UnsupportedSourceSheetTopology,
        -1, -1, canonicalFace);
    return result;
  }

  int cellOffset = 0;
  int edgeOffset = 0;
  std::set<int> coveredRegions;
  for (RegionBuild &build : regionBuilds) {
    const SurfaceTopologyRegion &region = *build.work->region;
    SurfacePhaseFrontResult &local = build.result;
    bool localCoverage = false;
    std::set<int> coveredIsolationSheets;
    for (SurfacePhaseFrontCell &cell : local.cells) {
      if (cell.sourceComponent != region.sourceComponent ||
          cell.sourceTopologyRegion != region.id ||
          cell.sourceIsolationSheets.empty()) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage,
            cell.id, -1, cell.corners.front().face);
        return result;
      }
      for (const int sheet : cell.sourceIsolationSheets) {
        coveredIsolationSheets.insert(sheet);
      }
      localCoverage = true;
      cell.id += cellOffset;
      result.cells.push_back(std::move(cell));
    }
    const std::set<int> requiredIsolationSheets(region.isolationSheets.begin(),
                                                 region.isolationSheets.end());
    if (!localCoverage || coveredIsolationSheets != requiredIsolationSheets ||
        !coveredRegions.insert(region.id).second) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage,
          -1, -1, region.sourceFaces.empty() ? -1 : region.sourceFaces.front());
      return result;
    }
    for (SurfaceFrontEdge &edge : local.edges) {
      if (edge.sourceComponent != region.sourceComponent ||
          edge.sourceTopologyRegion != region.id) {
        result.disposition = SurfaceCellProducerDisposition::Rejected;
        set_phase_front_failure(
            result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage,
            -1, -1, region.sourceFaces.empty() ? -1 : region.sourceFaces.front());
        return result;
      }
      if (edge.boundaryKind == SurfaceFrontBoundaryKind::PeriodicCut) {
        if (edge.periodicRelation < 0 ||
            edge.periodicRelation >=
                static_cast<int>(local.periodicHolonomies.size())) {
          result.disposition = SurfaceCellProducerDisposition::Rejected;
          set_phase_front_failure(
              result.failure,
              SurfacePhaseFrontFailureReason::InvalidPeriodicFrontPairing,
              edge.filledCell, edge.filledSide);
          return result;
        }
        const auto key = periodic_relation_key(
            local.periodicHolonomies[static_cast<std::size_t>(
                edge.periodicRelation)]);
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
              edge.filledCell, edge.filledSide);
          return result;
        }
        edge.periodicRelation = static_cast<int>(
            std::distance(result.periodicHolonomies.begin(), owner));
      }
      edge.filledCell += cellOffset;
      if (edge.oppositeEdge >= 0) edge.oppositeEdge += edgeOffset;
      result.edges.push_back(std::move(edge));
    }
    for (SurfaceFrontEvent &event : local.events) {
      if (event.firstEdge >= 0) event.firstEdge += edgeOffset;
      if (event.secondEdge >= 0) event.secondEdge += edgeOffset;
      result.events.push_back(std::move(event));
    }
    cellOffset = static_cast<int>(result.cells.size());
    edgeOffset = static_cast<int>(result.edges.size());
  }

  if (coveredRegions.size() != result.topologyRegions.size()) {
    result.disposition = SurfaceCellProducerDisposition::Rejected;
    set_phase_front_failure(
        result.failure, SurfacePhaseFrontFailureReason::IncompleteSourceSheetCoverage);
    return result;
  }

  // A hard feature separates producer charts, but it does not create an
  // output boundary. Pair the two chart copies by exact source-simplex
  // support and ordered rail topology; geometry is never a merge predicate.
  struct HardRailPairKey {
    int component = -1;
    std::vector<std::int64_t> firstEndpoint;
    std::vector<std::int64_t> secondEndpoint;
    std::vector<std::uint64_t> route;
    bool operator<(const HardRailPairKey &other) const {
      return std::tie(component, firstEndpoint, secondEndpoint, route) <
             std::tie(other.component, other.firstEndpoint,
                      other.secondEndpoint, other.route);
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

  std::map<HardRailPairKey, std::vector<int>> hardRailGroups;
  for (int edgeIndex = 0; edgeIndex < static_cast<int>(result.edges.size());
       ++edgeIndex) {
    const SurfaceFrontEdge &edge =
        result.edges[static_cast<std::size_t>(edgeIndex)];
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::HardRail) continue;
    std::vector<std::int64_t> from = support_key(edge.from);
    std::vector<std::int64_t> to = support_key(edge.to);
    if (edge.oppositeEdge >= 0 || !edge.exterior || from.empty() || to.empty() ||
        edge.sourceRouteTopology.empty()) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidHardRailPairing,
          edge.filledCell, edge.filledSide);
      return result;
    }
    if (to < from) std::swap(from, to);
    std::vector<std::uint64_t> route = edge.sourceRouteTopology;
    std::vector<std::uint64_t> reversed(route.rbegin(), route.rend());
    if (reversed < route) route = std::move(reversed);
    hardRailGroups[{edge.sourceComponent, std::move(from), std::move(to),
                    std::move(route)}]
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
                       : result.edges[static_cast<std::size_t>(pair.front())]
                             .filledCell,
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
        first.family != second.family ||
        first.advanceSign == second.advanceSign) {
      result.disposition = SurfaceCellProducerDisposition::Rejected;
      set_phase_front_failure(
          result.failure, SurfacePhaseFrontFailureReason::InvalidHardRailPairing,
          first.filledCell, first.filledSide);
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
          vertices, faces, faceAxisX, faceAxisY, options,
          result.sourceTopologyRegionByFace, result.topologyRegions,
          sourceEdgeFaces, sourceMatchingIndices, edgeMatching, edgeEffort,
          edgeTransitions,
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
  network.sourceFaceComponents = options.sourceFaceComponents;
  network.sourceFaceSheets = options.sourceFaceSheets;
  network.reliefRootVertices = options.reliefRootVertices;
  network.reliefRegionLabels = options.reliefRegionLabels;
  network.reliefBarrierEdges = options.reliefBarrierEdges;
  network.phaseFront =
      surface_cell_tracing_detail::build_uniform_phase_front(
          vertices, faces, faceAxisX, faceAxisY, targetSize, options,
          edgeMatching, edgeEffort, edgeTransitions);
  network.sourceFaceTopologyRegions =
      network.phaseFront.sourceTopologyRegionByFace;
  network.topologyRegions = network.phaseFront.topologyRegions;
  if (network.phaseFront.disposition ==
      SurfaceCellProducerDisposition::Produced) {
    network.proposals.reserve(network.phaseFront.cells.size());
    for (const SurfacePhaseFrontCell &cell : network.phaseFront.cells) {
      SurfaceCellProposal proposal;
      proposal.seedId = cell.id;
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
  if (network.phaseFront.disposition ==
      SurfaceCellProducerDisposition::Rejected) {
    return network;
  }
  network.seeds =
      generate_deterministic_surface_seeds(vertices, faces, targetSize, options);
  for (const SurfaceTraceSeed &seed : network.seeds) {
    for (int family = 0; family < 2; ++family) {
      for (const int sign : {-1, 1}) {
        network.traces.push_back(trace_surface_field(
            vertices, faces, faceAxisX, faceAxisY, seed, family, sign, options,
            edgeMatching, edgeEffort, edgeTransitions));
      }
    }
    SurfaceCellProposal proposal = make_surface_cell_proposal(
        vertices, faces, faceAxisX, faceAxisY, targetSize, seed, options,
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
  if (!options.singularityIndexNumerators.empty()) {
    SurfaceSingularitySeparatrixStats &stats =
        network.singularSeparatrixStats;
    stats.singularityCount =
        static_cast<int>(options.singularityVertices.size());
    if (options.singularityIndexNumerators.size() !=
        options.singularityVertices.size()) {
      stats.metadataValid = false;
      stats.incompleteSingularities = stats.singularityCount;
      return network;
    }

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
    const auto other_face = [&](const std::uint64_t edge, const int face) {
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
         singularity < options.singularityVertices.size(); ++singularity) {
      const int vertex = options.singularityVertices[singularity];
      const int index = options.singularityIndexNumerators[singularity];
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
            vertex, wedge.startNeighbor);
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
                              vertex, wedge.endNeighbor),
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
