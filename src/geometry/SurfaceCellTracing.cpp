#include <directional/geometry/SurfaceCellTracing.h>

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
  if (edgeTransitions != nullptr) {
    const auto found = transitionLookup.byEdge.find(edgeKey);
    if (found == transitionLookup.byEdge.end() ||
        !transition_faces_match(found->second, sourceFace, targetFace) ||
        edge_key(found->second.sourceVertex0,
                 found->second.sourceVertex1) != edgeKey) {
      return result;
    }
    result.matching = found->second.matching;
    if (found->second.secondFace == sourceFace) {
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
  if (authoritativeMatching) {
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
    int matching = 0;
    double effort = 0.0;
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
          options.reliefBarrierEdges.count(step.edgeKey) != 0) {
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

      PathState next = path;
      next.face = step.face;
      next.family = transition.family;
      next.sign = transition.sign;
      next.matching += transition.matching;
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
        candidate.matching = next.matching;
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
        const surface_cell_tracing_detail::BranchTransitionResult transition =
            surface_cell_tracing_detail::resolve_branch_transition(
                vertices, faces, faceAxisX, faceAxisY, edgeFaces,
                edgeMatchingIndices, transitionLookup, key, current.face,
                nextFace, currentFamily, currentSign, direction, edgeMatching,
                edgeEffort, edgeTransitions);
        if (!transition.valid) {
          result.termination = TraceTerminationReason::FieldMetadata;
          return result;
        }
        current.barycentric =
            surface_cell_tracing_detail::remap_barycentric_to_neighbor(
                faces, current.face, nextFace, current.barycentric);
        current.face = nextFace;
        currentFamily = transition.family;
        currentSign = transition.sign;
        direction = transition.direction;
        entryEdge =
            surface_cell_tracing_detail::local_edge_for_key(faces, nextFace,
                                                            key);
        if (entryEdge < 0) {
          result.termination = TraceTerminationReason::FieldMetadata;
          return result;
        }
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
    const surface_cell_tracing_detail::BranchTransitionResult transition =
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

namespace directional::geometry {

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
