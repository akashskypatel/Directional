#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SourceChartTransitions.h>

namespace directional::geometry::surface_arrangement_detail {

template <typename T>
std::uint64_t vector_storage_bytes(const std::vector<T> &values) {
  return static_cast<std::uint64_t>(values.capacity()) * sizeof(T);
}

double cross2(const Eigen::Vector2d &a, const Eigen::Vector2d &b) {
  return a.x() * b.y() - a.y() * b.x();
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::Vector2d bary_to_uv(const Eigen::RowVector3d &bary) {
  return {bary[1], bary[2]};
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d uv_to_bary(const Eigen::Vector2d &uv) {
  return {1.0 - uv.x() - uv.y(), uv.x(), uv.y()};
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

double triangle_area_3d(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const int face) {
  const Eigen::RowVector3d a = vertices.row(faces(face, 0));
  const Eigen::RowVector3d b = vertices.row(faces(face, 1));
  const Eigen::RowVector3d c = vertices.row(faces(face, 2));
  return 0.5 * surface_cell_tracing_detail::cross3(b - a, c - a).norm();
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d face_normal_3d(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &faces,
                                         const int face) {
  if (face < 0 || face >= faces.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  const Eigen::RowVector3d a = vertices.row(faces(face, 0));
  const Eigen::RowVector3d b = vertices.row(faces(face, 1));
  const Eigen::RowVector3d c = vertices.row(faces(face, 2));
  Eigen::RowVector3d normal =
      surface_cell_tracing_detail::cross3(b - a, c - a);
  const double norm = normal.norm();
  if (!(norm > 1.0e-20) || !std::isfinite(norm)) {
    return Eigen::RowVector3d::Zero();
  }
  return normal / norm;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d barycentric_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int face, const Eigen::RowVector3d &barycentric) {
  if (face < 0 || face >= faces.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  return barycentric[0] * vertices.row(faces(face, 0)) +
         barycentric[1] * vertices.row(faces(face, 1)) +
         barycentric[2] * vertices.row(faces(face, 2));
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d node_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceArrangementNode &node) {
  return barycentric_position(vertices, faces, node.sourceFace,
                              node.barycentric);
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d node_barycentric_on_face(
    const SurfaceArrangementNode &node, const int face) {
  return node_barycentric_on_face(node, face, -1, -1);
}

Eigen::RowVector3d node_barycentric_on_face(
    const SurfaceArrangementNode &node, const int face,
    const int component, const int sheet) {
  const auto scopeCompatible = [](const int stored, const int requested) {
    return requested < 0 || stored < 0 || stored == requested;
  };
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    if (occurrence.sourceFace == face &&
        scopeCompatible(occurrence.sourceComponent, component) &&
        scopeCompatible(occurrence.sourceSheet, sheet)) {
      return occurrence.barycentric;
    }
  }
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    if (occurrence.sourceFace == face) {
      return occurrence.barycentric;
    }
  }
  if (node.sourceFace == face &&
      scopeCompatible(node.sourceComponent, component) &&
      scopeCompatible(node.sourceSheet, sheet)) {
    return node.barycentric;
  }
  return Eigen::RowVector3d::Constant(
      std::numeric_limits<double>::quiet_NaN());
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d node_reference_normal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceArrangementNode &node) {
  Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
  std::set<int> usedFaces;
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    if (usedFaces.insert(occurrence.sourceFace).second) {
      normal += face_normal_3d(vertices, faces, occurrence.sourceFace);
    }
  }
  if (usedFaces.empty() && node.sourceFace >= 0) {
    normal = face_normal_3d(vertices, faces, node.sourceFace);
  }
  const double norm = normal.norm();
  if (!(norm > 1.0e-14) || !std::isfinite(norm)) {
    return Eigen::RowVector3d::Zero();
  }
  return normal / norm;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool tangent_basis(const Eigen::RowVector3d &normal,
                          Eigen::RowVector3d &axisX,
                          Eigen::RowVector3d &axisY) {
  const double norm = normal.norm();
  if (!(norm > 1.0e-14) || !std::isfinite(norm)) {
    return false;
  }
  const Eigen::RowVector3d n = normal / norm;
  Eigen::RowVector3d seed = Eigen::RowVector3d::UnitX();
  if (std::abs(n.y()) < std::abs(n.x()) &&
      std::abs(n.y()) <= std::abs(n.z())) {
    seed = Eigen::RowVector3d::UnitY();
  } else if (std::abs(n.z()) < std::abs(n.x()) &&
             std::abs(n.z()) < std::abs(n.y())) {
    seed = Eigen::RowVector3d::UnitZ();
  }
  axisX = seed - seed.dot(n) * n;
  const double xNorm = axisX.norm();
  if (!(xNorm > 1.0e-14) || !std::isfinite(xNorm)) {
    return false;
  }
  axisX /= xNorm;
  axisY = surface_cell_tracing_detail::cross3(n, axisX);
  const double yNorm = axisY.norm();
  if (!(yNorm > 1.0e-14) || !std::isfinite(yNorm)) {
    return false;
  }
  axisY /= yNorm;
  return true;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool polygon_geometry(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &halfedges,
    const std::vector<SurfaceArrangementHalfedge> &allHalfedges,
    const std::vector<SurfaceArrangementNode> &nodes, double &signedArea,
    double &area, std::vector<int> &sourceFaces) {
  signedArea = 0.0;
  area = 0.0;
  sourceFaces.clear();
  if (halfedges.size() < 3U) {
    return false;
  }
  std::vector<Eigen::RowVector3d> points;
  points.reserve(halfedges.size());
  Eigen::RowVector3d referenceNormal = Eigen::RowVector3d::Zero();
  std::set<int> faceSet;
  for (const int halfedgeId : halfedges) {
    if (halfedgeId < 0 ||
        halfedgeId >= static_cast<int>(allHalfedges.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &halfedge =
        allHalfedges[static_cast<std::size_t>(halfedgeId)];
    if (halfedge.from < 0 ||
        halfedge.from >= static_cast<int>(nodes.size())) {
      return false;
    }
    points.push_back(node_position(vertices, faces,
                                   nodes[static_cast<std::size_t>(halfedge.from)]));
    if (halfedge.sourceFace >= 0 &&
        faceSet.insert(halfedge.sourceFace).second) {
      referenceNormal += face_normal_3d(vertices, faces, halfedge.sourceFace);
    }
    for (const SurfaceArrangementProvenance &provenance :
         halfedge.provenance) {
      if (provenance.sourceFace >= 0 &&
          faceSet.insert(provenance.sourceFace).second) {
        referenceNormal +=
            face_normal_3d(vertices, faces, provenance.sourceFace);
      }
    }
  }
  sourceFaces.assign(faceSet.begin(), faceSet.end());
  // The unweighted sum of incident face normals can cancel on a curved patch
  // even when its boundary is a perfectly valid embedded cycle. The closed
  // polygon's vector area is translation invariant and supplies the least-
  // squares projection normal directly. Prefer it whenever it is resolved;
  // retain the source-normal sum only for a near-zero vector-area boundary.
  Eigen::RowVector3d vectorArea = Eigen::RowVector3d::Zero();
  for (std::size_t index = 0; index < points.size(); ++index) {
    vectorArea += 0.5 * surface_cell_tracing_detail::cross3(
                            points[index], points[(index + 1U) % points.size()]);
  }
  if (vectorArea.squaredNorm() > 1.0e-28 && vectorArea.allFinite()) {
    if (referenceNormal.squaredNorm() > 1.0e-28 &&
        vectorArea.dot(referenceNormal) < 0.0) {
      vectorArea = -vectorArea;
    }
    referenceNormal = vectorArea;
  }
  const double normalNorm = referenceNormal.norm();
  if (!(normalNorm > 1.0e-14) || !std::isfinite(normalNorm)) {
    return false;
  }
  referenceNormal /= normalNorm;

  Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
  for (const Eigen::RowVector3d &point : points) {
    centroid += point;
  }
  centroid /= static_cast<double>(points.size());

  Eigen::RowVector3d axisX = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d axisY = Eigen::RowVector3d::Zero();
  if (!tangent_basis(referenceNormal, axisX, axisY)) {
    return false;
  }
  std::vector<Eigen::Vector2d> projected;
  projected.reserve(points.size());
  for (const Eigen::RowVector3d &point : points) {
    const Eigen::RowVector3d offset = point - centroid;
    projected.emplace_back(offset.dot(axisX), offset.dot(axisY));
  }

  double projectedArea = 0.0;
  for (std::size_t i = 0; i < projected.size(); ++i) {
    const Eigen::Vector2d &a = projected[i];
    const Eigen::Vector2d &b = projected[(i + 1U) % projected.size()];
    projectedArea += 0.5 * (a.x() * b.y() - a.y() * b.x());
  }
  if (!std::isfinite(projectedArea) ||
      std::abs(projectedArea) <= 1.0e-20) {
    return false;
  }

  // Ear clipping avoids the centroid-fan overlap that over-counts concave
  // arrangement cells. Triangle areas are accumulated in 3D so curved,
  // stitched multi-face cells retain their embedded geometry.
  std::vector<int> polygon(points.size());
  std::iota(polygon.begin(), polygon.end(), 0);
  if (projectedArea < 0.0) {
    std::reverse(polygon.begin(), polygon.end());
  }
  const auto orient2 = [&](const int a, const int b, const int c) {
    const Eigen::Vector2d ab = projected[static_cast<std::size_t>(b)] -
                               projected[static_cast<std::size_t>(a)];
    const Eigen::Vector2d ac = projected[static_cast<std::size_t>(c)] -
                               projected[static_cast<std::size_t>(a)];
    return ab.x() * ac.y() - ab.y() * ac.x();
  };
  const auto inside_triangle = [&](const int point, const int a, const int b,
                                   const int c) {
    constexpr double epsilon = 1.0e-12;
    return orient2(a, b, point) > epsilon &&
           orient2(b, c, point) > epsilon &&
           orient2(c, a, point) > epsilon;
  };

  double triangulatedArea = 0.0;
  while (polygon.size() > 3U) {
    bool clipped = false;
    for (std::size_t i = 0; i < polygon.size(); ++i) {
      const int previous = polygon[(i + polygon.size() - 1U) % polygon.size()];
      const int current = polygon[i];
      const int next = polygon[(i + 1U) % polygon.size()];
      if (orient2(previous, current, next) <= 1.0e-14) {
        continue;
      }
      bool containsVertex = false;
      for (const int candidate : polygon) {
        if (candidate == previous || candidate == current || candidate == next) {
          continue;
        }
        if (inside_triangle(candidate, previous, current, next)) {
          containsVertex = true;
          break;
        }
      }
      if (containsVertex) {
        continue;
      }
      triangulatedArea += 0.5 *
          surface_cell_tracing_detail::cross3(
              points[static_cast<std::size_t>(current)] -
                  points[static_cast<std::size_t>(previous)],
              points[static_cast<std::size_t>(next)] -
                  points[static_cast<std::size_t>(previous)])
              .norm();
      polygon.erase(polygon.begin() + static_cast<std::ptrdiff_t>(i));
      clipped = true;
      break;
    }
    if (!clipped) {
      signedArea = projectedArea;
      area = std::abs(projectedArea);
      return area > 1.0e-20;
    }
  }
  triangulatedArea += 0.5 *
      surface_cell_tracing_detail::cross3(
          points[static_cast<std::size_t>(polygon[1])] -
              points[static_cast<std::size_t>(polygon[0])],
          points[static_cast<std::size_t>(polygon[2])] -
              points[static_cast<std::size_t>(polygon[0])])
          .norm();
  if (!std::isfinite(triangulatedArea) || triangulatedArea <= 1.0e-20) {
    return false;
  }
  signedArea = projectedArea;
  area = triangulatedArea;
  return true;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

int source_edge(const Eigen::Vector2d &uv, const double eps) {
  const Eigen::RowVector3d bary = uv_to_bary(uv);
  for (int i = 0; i < 3; ++i) {
    if (std::abs(bary[i]) <= eps) {
      return i;
    }
  }
  return -1;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

Eigen::RowVector3d canonicalize_barycentric(
    const Eigen::RowVector3d &input, const double eps) {
  Eigen::RowVector3d result = input;
  for (int i = 0; i < 3; ++i) {
    if (std::abs(result[i]) <= eps) {
      result[i] = 0.0;
    } else if (std::abs(result[i] - 1.0) <= eps) {
      result[i] = 1.0;
    }
  }
  const double sum = result.sum();
  if (std::abs(sum) > 1.0e-20) {
    result /= sum;
  }
  return result;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

double local_edge_parameter(const Eigen::Vector2d &uv, const int edge) {
  const Eigen::RowVector3d b = canonicalize_barycentric(uv_to_bary(uv));
  if (edge == 0) {
    const double denom = std::max(1.0e-20, b[1] + b[2]);
    return b[2] / denom;
  }
  if (edge == 1) {
    const double denom = std::max(1.0e-20, b[0] + b[2]);
    return b[0] / denom;
  }
  if (edge == 2) {
    const double denom = std::max(1.0e-20, b[0] + b[1]);
    return b[1] / denom;
  }
  return 0.0;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

double canonical_edge_parameter(const Eigen::MatrixXi &faces,
                                       const int face, const int edge,
                                       const Eigen::Vector2d &uv) {
  const int localStart = faces(face, (edge + 1) % 3);
  const int localEnd = faces(face, (edge + 2) % 3);
  const double local = local_edge_parameter(uv, edge);
  return localStart <= localEnd ? local : 1.0 - local;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

std::uint64_t source_edge_key(const Eigen::MatrixXi &faces,
                                     const int face, const int edge) {
  const int a = faces(face, (edge + 1) % 3);
  const int b = faces(face, (edge + 2) % 3);
  return surface_cell_tracing_detail::edge_key(a, b);
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

int source_vertex(const Eigen::RowVector3d &bary,
                         const double eps) {
  const Eigen::RowVector3d canonical = canonicalize_barycentric(bary, eps);
  for (int i = 0; i < 3; ++i) {
    if (canonical[i] >= 1.0 - eps) {
      return i;
    }
  }
  return -1;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

NodeKey make_node_key(const Eigen::MatrixXi &faces, const int face,
                             const Eigen::Vector2d &uv) {
  const Eigen::RowVector3d bary = canonicalize_barycentric(uv_to_bary(uv));
  const Eigen::Vector2d canonicalUv = bary_to_uv(bary);
  const int edge = source_edge(canonicalUv);
  const double t =
      edge >= 0 ? canonical_edge_parameter(faces, face, edge, canonicalUv) : -1.0;
  const int vertexCorner = source_vertex(bary);
  if (vertexCorner >= 0) {
    return {0, -1, -1, -1, faces(face, vertexCorner), 0, 0};
  }
  if (edge >= 0) {
    const std::uint64_t key = source_edge_key(faces, face, edge);
    return {1,
            -1,
            static_cast<std::int64_t>(key),
            static_cast<std::int64_t>(std::llround(t * 1.0e10)),
            -1,
            0,
            0};
  }
  return {2,
          face,
          -1,
          -1,
          -1,
          static_cast<std::int64_t>(
              std::llround(canonicalUv.x() * 1.0e10)),
          static_cast<std::int64_t>(
              std::llround(canonicalUv.y() * 1.0e10))};
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

using ScopedNodeKey = std::tuple<NodeKey, int, int>;
using ScopedSourceEdgeKey = std::tuple<std::uint64_t, int>;
using FaceVertexKey = std::pair<int, int>;
using VertexFanScopes = std::map<FaceVertexKey, int>;

struct VertexFanWedge {
  int order = -1;
  int faceCount = 0;
  bool closed = false;
  double cornerAngle = 0.0;
};

using VertexFanWedges = std::map<FaceVertexKey, VertexFanWedge>;

int face_label(const std::vector<int> *labels, const int face) {
  if (labels == nullptr || face < 0 ||
      face >= static_cast<int>(labels->size())) {
    return -1;
  }
  return (*labels)[static_cast<std::size_t>(face)];
}

void complete_segment_scope(const SurfaceArrangementOptions &options,
                            Segment2 &segment) {
  if (segment.sourceComponent < 0) {
    segment.sourceComponent =
        face_label(options.sourceFaceComponents, segment.sourceFace);
  }
  if (segment.sourceSheet < 0) {
    segment.sourceSheet =
        face_label(options.sourceFaceSheets, segment.sourceFace);
  }
}

bool same_segment_scope(const Segment2 &a, const Segment2 &b) {
  return a.sourceComponent == b.sourceComponent &&
         a.sourceSheet == b.sourceSheet;
}

int canonical_node_sheet_scope(const NodeKey &key, const int sourceFace,
                               const int sourceSheet,
                               const VertexFanScopes &vertexFanScopes) {
  if (key.kind == 0) {
    const auto found = vertexFanScopes.find({sourceFace, key.vertex});
    return found == vertexFanScopes.end() ? sourceSheet : found->second;
  }
  // An edge-interior source point is intrinsically shared by both incident
  // triangle charts. Local sheet labels are chart labels and may differ
  // across that adjacency, so they must not split the same source edge.
  if (key.kind == 1) {
    return -1;
  }
  return sourceSheet;
}

ScopedNodeKey make_scoped_node_key(const Eigen::MatrixXi &faces,
                                   const Segment2 &segment,
                                   const Eigen::Vector2d &uv,
                                   const VertexFanScopes &vertexFanScopes) {
  const NodeKey key = make_node_key(faces, segment.sourceFace, uv);
  return {key, segment.sourceComponent,
          canonical_node_sheet_scope(key, segment.sourceFace,
                                     segment.sourceSheet, vertexFanScopes)};
}

int face_vertex_corner(const Eigen::MatrixXi &faces, const int face,
                       const int vertex) {
  if (face < 0 || face >= faces.rows()) {
    return -1;
  }
  for (int corner = 0; corner < 3; ++corner) {
    if (faces(face, corner) == vertex) {
      return corner;
    }
  }
  return -1;
}

int adjacent_face_across_vertex_edge(
    const Eigen::MatrixXi &faces,
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces,
    const VertexFanScopes &vertexFanScopes, const int face, const int vertex,
    const int scope, const bool acrossWedgeEnd) {
  const int corner = face_vertex_corner(faces, face, vertex);
  if (corner < 0) {
    return -1;
  }
  const int otherCorner =
      acrossWedgeEnd ? (corner + 2) % 3 : (corner + 1) % 3;
  const auto found = edgeFaces.find(
      surface_cell_tracing_detail::edge_key(vertex,
                                            faces(face, otherCorner)));
  if (found == edgeFaces.end()) {
    return -1;
  }
  for (const int candidate : found->second) {
    if (candidate < 0 || candidate == face) {
      continue;
    }
    const auto candidateScope = vertexFanScopes.find({candidate, vertex});
    if (candidateScope != vertexFanScopes.end() &&
        candidateScope->second == scope) {
      return candidate;
    }
  }
  return -1;
}

double vertex_corner_angle(const Eigen::MatrixXd &vertices,
                           const Eigen::MatrixXi &faces, const int face,
                           const int vertex) {
  const int corner = face_vertex_corner(faces, face, vertex);
  if (corner < 0) {
    return 0.0;
  }
  Eigen::RowVector3d first =
      vertices.row(faces(face, (corner + 1) % 3)) - vertices.row(vertex);
  Eigen::RowVector3d second =
      vertices.row(faces(face, (corner + 2) % 3)) - vertices.row(vertex);
  const double firstNorm = first.norm();
  const double secondNorm = second.norm();
  if (!(firstNorm > 1.0e-14) || !(secondNorm > 1.0e-14) ||
      !std::isfinite(firstNorm) || !std::isfinite(secondNorm)) {
    return 0.0;
  }
  first /= firstNorm;
  second /= secondNorm;
  return std::acos(std::clamp(first.dot(second), -1.0, 1.0));
}

VertexFanWedges build_vertex_fan_wedges(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces,
    const VertexFanScopes &vertexFanScopes) {
  std::map<std::pair<int, int>, std::vector<int>> facesByFan;
  for (const auto &[faceVertex, scope] : vertexFanScopes) {
    facesByFan[{faceVertex.second, scope}].push_back(faceVertex.first);
  }

  VertexFanWedges wedges;
  for (auto &[fan, incidentFaces] : facesByFan) {
    const int vertex = fan.first;
    const int scope = fan.second;
    std::sort(incidentFaces.begin(), incidentFaces.end());
    incidentFaces.erase(
        std::unique(incidentFaces.begin(), incidentFaces.end()),
        incidentFaces.end());
    if (incidentFaces.empty()) {
      continue;
    }

    int startFace = -1;
    for (const int face : incidentFaces) {
      if (adjacent_face_across_vertex_edge(
              faces, edgeFaces, vertexFanScopes, face, vertex, scope,
              false) < 0) {
        startFace = face;
        break;
      }
    }
    const bool closed = startFace < 0;
    if (closed) {
      startFace = incidentFaces.front();
    }

    std::set<int> visited;
    int face = startFace;
    int order = 0;
    while (face >= 0 && visited.insert(face).second) {
      wedges[{face, vertex}] =
          {order++, static_cast<int>(incidentFaces.size()), closed,
           vertex_corner_angle(vertices, faces, face, vertex)};
      face = adjacent_face_across_vertex_edge(
          faces, edgeFaces, vertexFanScopes, face, vertex, scope, true);
      if (closed && face == startFace) {
        break;
      }
    }

    // A nonmanifold or inconsistently oriented fan should already have been
    // separated by vertexFanScopes. Keep any residual faces deterministic,
    // but give them an invalid corner angle so the caller falls back to the
    // geometric ordering instead of pretending the fan is authoritative.
    for (const int residual : incidentFaces) {
      if (visited.count(residual) == 0U) {
        wedges[{residual, vertex}] =
            {order++, static_cast<int>(incidentFaces.size()), false, 0.0};
      }
    }
  }
  return wedges;
}

int node_source_vertex_id(const SurfaceArrangementNode &node,
                          const Eigen::MatrixXi &faces) {
  int vertex = -1;
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    const int corner = source_vertex(occurrence.barycentric);
    if (corner < 0 || occurrence.sourceFace < 0 ||
        occurrence.sourceFace >= faces.rows()) {
      continue;
    }
    const int candidate = faces(occurrence.sourceFace, corner);
    if (vertex >= 0 && vertex != candidate) {
      return -1;
    }
    vertex = candidate;
  }
  return vertex;
}

bool intrinsic_vertex_outgoing_parameter(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const VertexFanWedges &wedges,
    const std::vector<SurfaceArrangementNode> &nodes,
    const SurfaceArrangementHalfedge &halfedge, const int sourceVertex,
    double &parameter) {
  if (halfedge.from < 0 || halfedge.to < 0 ||
      halfedge.from >= static_cast<int>(nodes.size()) ||
      halfedge.to >= static_cast<int>(nodes.size()) ||
      halfedge.sourceFace < 0 || halfedge.sourceFace >= faces.rows()) {
    return false;
  }
  const int corner =
      face_vertex_corner(faces, halfedge.sourceFace, sourceVertex);
  const auto found = wedges.find({halfedge.sourceFace, sourceVertex});
  if (corner < 0 || found == wedges.end() ||
      !(found->second.cornerAngle > 1.0e-14)) {
    return false;
  }
  const Eigen::RowVector3d toBarycentric = node_barycentric_on_face(
      nodes[static_cast<std::size_t>(halfedge.to)], halfedge.sourceFace);
  if (!toBarycentric.allFinite()) {
    return false;
  }

  const Eigen::RowVector3d origin = vertices.row(sourceVertex);
  Eigen::RowVector3d start =
      vertices.row(faces(halfedge.sourceFace, (corner + 1) % 3)) - origin;
  Eigen::RowVector3d direction =
      barycentric_position(vertices, faces, halfedge.sourceFace,
                           toBarycentric) -
      origin;
  const Eigen::RowVector3d normal =
      face_normal_3d(vertices, faces, halfedge.sourceFace);
  const double startNorm = start.norm();
  const double directionNorm = direction.norm();
  if (!(startNorm > 1.0e-14) || !(directionNorm > 1.0e-14) ||
      !(normal.norm() > 1.0e-14)) {
    return false;
  }
  start /= startNorm;
  direction /= directionNorm;
  double localAngle = std::atan2(
      surface_cell_tracing_detail::cross3(start, direction).dot(normal),
      start.dot(direction));
  if (localAngle < -1.0e-12) {
    constexpr double twoPi = 6.283185307179586476925286766559;
    localAngle += twoPi;
  }
  const double cornerAngle = found->second.cornerAngle;
  if (localAngle < -1.0e-10 || localAngle > cornerAngle + 1.0e-10) {
    return false;
  }
  const double localFraction =
      std::clamp(localAngle / cornerAngle, 0.0, 1.0);
  parameter = static_cast<double>(found->second.order) + localFraction;
  if (found->second.closed && found->second.faceCount > 0 &&
      parameter >= static_cast<double>(found->second.faceCount) - 1.0e-10) {
    parameter = 0.0;
  }
  return std::isfinite(parameter);
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

int canonical_source_edge_id(const Eigen::MatrixXi &faces, const int face,
                                    const int edge) {
  if (edge < 0) {
    return -1;
  }
  return static_cast<int>(source_edge_key(faces, face, edge) & 0x7fffffffu);
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool clip_to_triangle(Eigen::Vector2d &a, Eigen::Vector2d &b,
                             double &ta, double &tb) {
  double lo = 0.0;
  double hi = 1.0;
  const Eigen::Vector2d d = b - a;
  const auto clip_lower = [&](const double value, const double delta) {
    if (std::abs(delta) <= 1.0e-14) {
      return value >= -1.0e-12;
    }
    const double t = -value / delta;
    if (delta > 0.0) {
      lo = std::max(lo, t);
    } else {
      hi = std::min(hi, t);
    }
    return lo <= hi + 1.0e-12;
  };
  if (!clip_lower(a.x(), d.x()) || !clip_lower(a.y(), d.y()) ||
      !clip_lower(1.0 - a.x() - a.y(), -d.x() - d.y())) {
    return false;
  }
  if (hi < -1.0e-12 || lo > 1.0 + 1.0e-12) {
    return false;
  }
  lo = std::clamp(lo, 0.0, 1.0);
  hi = std::clamp(hi, 0.0, 1.0);
  const Eigen::Vector2d oldA = a;
  const Eigen::Vector2d oldB = b;
  a = oldA + lo * (oldB - oldA);
  b = oldA + hi * (oldB - oldA);
  const double oldTa = ta;
  const double oldTb = tb;
  ta = oldTa + lo * (oldTb - oldTa);
  tb = oldTa + hi * (oldTb - oldTa);
  return (b - a).squaredNorm() > 1.0e-24;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool segment_intersection_params(const Segment2 &a, const Segment2 &b,
                                        double &ta, double &tb,
                                        Eigen::Vector2d &point) {
  constexpr double kAngularTolerance = 1.0e-12;
  constexpr double kSpatialCollinearityTolerance = 1.0e-12;
  constexpr double kParameterTolerance = 1.0e-12;
  const Eigen::Vector2d r = a.end - a.start;
  const Eigen::Vector2d s = b.end - b.start;
  const double rr = r.squaredNorm();
  const double ss = s.squaredNorm();
  if (rr <= 1.0e-24 || ss <= 1.0e-24) {
    return false;
  }
  const double rLength = std::sqrt(rr);
  const double sLength = std::sqrt(ss);
  const double denom = cross2(r, s);
  const Eigen::Vector2d qp = b.start - a.start;
  const double parallelTolerance =
      kAngularTolerance * rLength * sLength;
  if (std::abs(denom) <= parallelTolerance) {
    // Cross products have squared-length units. Convert the collinearity
    // check to an actual chart-space distance so short segments do not admit
    // large false offsets merely because their direction vector is small.
    if (std::abs(cross2(qp, r)) / rLength >
        kSpatialCollinearityTolerance) {
      return false;
    }
    const double t0 = (b.start - a.start).dot(r) / rr;
    const double t1 = (b.end - a.start).dot(r) / rr;
    const double lo = std::max(0.0, std::min(t0, t1));
    const double hi = std::min(1.0, std::max(t0, t1));
    if (lo > hi + kParameterTolerance) {
      return false;
    }
    ta = std::clamp(lo, 0.0, 1.0);
    const Eigen::Vector2d pointOnA = a.start + ta * r;
    tb = (pointOnA - b.start).dot(s) / ss;
    // The overlap tolerance must not turn two finite, disjoint segments into
    // an intersection whose parameter lies beyond either endpoint.
    if (tb < -kParameterTolerance || tb > 1.0 + kParameterTolerance) {
      return false;
    }
    tb = std::clamp(tb, 0.0, 1.0);
    const Eigen::Vector2d pointOnB = b.start + tb * s;
    if ((pointOnA - pointOnB).norm() >
        kSpatialCollinearityTolerance) {
      return false;
    }
    point = 0.5 * (pointOnA + pointOnB);
    return true;
  }
  ta = cross2(qp, s) / denom;
  tb = cross2(qp, r) / denom;
  if (ta < -kParameterTolerance || ta > 1.0 + kParameterTolerance ||
      tb < -kParameterTolerance || tb > 1.0 + kParameterTolerance) {
    return false;
  }
  ta = std::clamp(ta, 0.0, 1.0);
  tb = std::clamp(tb, 0.0, 1.0);
  point = a.start + ta * r;
  return true;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool point_on_segment(const Eigen::Vector2d &p, const Segment2 &s) {
  const Eigen::Vector2d ap = p - s.start;
  const Eigen::Vector2d ab = s.end - s.start;
  if (std::abs(cross2(ap, ab)) > 1.0e-10) {
    return false;
  }
  return ap.dot(ab) > 1.0e-10 && ap.dot(ab) < ab.squaredNorm() - 1.0e-10;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

double polygon_area(const std::vector<Eigen::Vector2d> &points) {
  double twice = 0.0;
  for (std::size_t i = 0; i < points.size(); ++i) {
    twice += cross2(points[i], points[(i + 1) % points.size()]);
  }
  return 0.5 * twice;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool point_in_polygon(const Eigen::Vector2d &point,
                             const std::vector<Eigen::Vector2d> &polygon) {
  bool inside = false;
  for (std::size_t i = 0, j = polygon.size() - 1; i < polygon.size();
       j = i++) {
    const Eigen::Vector2d &a = polygon[i];
    const Eigen::Vector2d &b = polygon[j];
    const bool straddles = (a.y() > point.y()) != (b.y() > point.y());
    if (!straddles) {
      continue;
    }
    const double x = (b.x() - a.x()) * (point.y() - a.y()) /
                         (b.y() - a.y()) +
                     a.x();
    if (point.x() < x) {
      inside = !inside;
    }
  }
  return inside;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

bool proper_transverse_crossing(const Segment2 &a, const Segment2 &b,
                                       const double ta, const double tb) {
  const Eigen::Vector2d da = a.end - a.start;
  const Eigen::Vector2d db = b.end - b.start;
  if (std::abs(cross2(da, db)) <= 1.0e-12) {
    return false;
  }
  return ta > 1.0e-10 && ta < 1.0 - 1.0e-10 && tb > 1.0e-10 &&
         tb < 1.0 - 1.0e-10;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

std::uint64_t complex_storage_bytes(const SurfaceCellComplex &complex) {
  std::uint64_t bytes = vector_storage_bytes(complex.sourceOwnershipRegistry) +
                        vector_storage_bytes(complex.nodes) +
                        vector_storage_bytes(complex.halfedges) +
                        vector_storage_bytes(complex.cells);
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    bytes += vector_storage_bytes(record.exactCharts);
    bytes += vector_storage_bytes(record.canonicalMembership.values);
  }
  for (const SurfaceArrangementNode &node : complex.nodes) {
    bytes += vector_storage_bytes(node.occurrences);
  }
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    bytes += vector_storage_bytes(halfedge.provenance);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    bytes += vector_storage_bytes(cell.sourceCharts);
    bytes += vector_storage_bytes(cell.sourceOwnershipClass.values);
    bytes += vector_storage_bytes(cell.sourceFaces);
    bytes += vector_storage_bytes(cell.halfedges);
    bytes += vector_storage_bytes(cell.sideFamilies);
    bytes += vector_storage_bytes(cell.sideEdgeCounts);
  }
  return bytes;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

int graph_component_count(
    const int vertexCount, const std::vector<std::pair<int, int>> &edges,
    const std::vector<unsigned char> *activeMask) {
  std::vector<std::vector<int>> adjacency(static_cast<std::size_t>(vertexCount));
  std::vector<unsigned char> active(static_cast<std::size_t>(vertexCount), 0);
  for (const auto &[a, b] : edges) {
    if (a < 0 || b < 0 || a >= vertexCount || b >= vertexCount) {
      continue;
    }
    adjacency[static_cast<std::size_t>(a)].push_back(b);
    adjacency[static_cast<std::size_t>(b)].push_back(a);
    active[static_cast<std::size_t>(a)] = 1;
    active[static_cast<std::size_t>(b)] = 1;
  }
  if (activeMask != nullptr) {
    active = *activeMask;
  }
  int count = 0;
  std::vector<unsigned char> visited(static_cast<std::size_t>(vertexCount), 0);
  for (int start = 0; start < vertexCount; ++start) {
    if (active[static_cast<std::size_t>(start)] == 0 ||
        visited[static_cast<std::size_t>(start)] != 0) {
      continue;
    }
    ++count;
    std::vector<int> stack{start};
    visited[static_cast<std::size_t>(start)] = 1;
    while (!stack.empty()) {
      const int current = stack.back();
      stack.pop_back();
      for (const int next : adjacency[static_cast<std::size_t>(current)]) {
        if (visited[static_cast<std::size_t>(next)] == 0) {
          visited[static_cast<std::size_t>(next)] = 1;
          stack.push_back(next);
        }
      }
    }
  }
  return count;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

std::pair<int, bool> boundary_loop_count(
    const int vertexCount, const std::vector<std::pair<int, int>> &edges) {
  if (edges.empty()) {
    return {0, true};
  }
  std::vector<int> degree(static_cast<std::size_t>(vertexCount), 0);
  std::vector<unsigned char> active(static_cast<std::size_t>(vertexCount), 0);
  for (const auto &[a, b] : edges) {
    if (a < 0 || b < 0 || a >= vertexCount || b >= vertexCount || a == b) {
      return {0, false};
    }
    ++degree[static_cast<std::size_t>(a)];
    ++degree[static_cast<std::size_t>(b)];
    active[static_cast<std::size_t>(a)] = 1;
    active[static_cast<std::size_t>(b)] = 1;
  }
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    if (active[static_cast<std::size_t>(vertex)] != 0 &&
        degree[static_cast<std::size_t>(vertex)] != 2) {
      return {0, false};
    }
  }
  return {graph_component_count(vertexCount, edges, &active), true};
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

int boundary_orientation_vote(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXi &faces,
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces) {
  int interiorVotes = 0;
  int exteriorVotes = 0;
  constexpr double epsilon = 1.0e-12;
  const Eigen::Vector2d triangleCentroid(1.0 / 3.0, 1.0 / 3.0);
  for (const int halfedgeId : cellHalfedges) {
    if (halfedgeId < 0 || halfedgeId >= static_cast<int>(halfedges.size())) {
      continue;
    }
    const SurfaceArrangementHalfedge &halfedge =
        halfedges[static_cast<std::size_t>(halfedgeId)];
    if (halfedge.family >= 0 || halfedge.sourceFace < 0 ||
        halfedge.from < 0 || halfedge.to < 0 ||
        halfedge.from >= static_cast<int>(nodes.size()) ||
        halfedge.to >= static_cast<int>(nodes.size())) {
      continue;
    }
    const Eigen::RowVector3d fromBary = node_barycentric_on_face(
        nodes[static_cast<std::size_t>(halfedge.from)], halfedge.sourceFace);
    const Eigen::RowVector3d toBary = node_barycentric_on_face(
        nodes[static_cast<std::size_t>(halfedge.to)], halfedge.sourceFace);
    if (!fromBary.allFinite() || !toBary.allFinite()) {
      continue;
    }
    int sourceEdge = -1;
    for (int coordinate = 0; coordinate < 3; ++coordinate) {
      if (std::abs(fromBary[coordinate]) <= epsilon &&
          std::abs(toBary[coordinate]) <= epsilon) {
        sourceEdge = coordinate;
        break;
      }
    }
    if (sourceEdge < 0) {
      continue;
    }
    const auto found = edgeFaces.find(
        source_edge_key(faces, halfedge.sourceFace, sourceEdge));
    if (found == edgeFaces.end() || found->second[1] >= 0) {
      // Interior hard-feature rails are not exterior boundaries.
      continue;
    }
    const Eigen::Vector2d from = bary_to_uv(fromBary);
    const Eigen::Vector2d to = bary_to_uv(toBary);
    const Eigen::Vector2d direction = to - from;
    const Eigen::Vector2d towardInterior =
        triangleCentroid - 0.5 * (from + to);
    const double side = direction.x() * towardInterior.y() -
                        direction.y() * towardInterior.x();
    if (side > epsilon) {
      ++interiorVotes;
    } else if (side < -epsilon) {
      ++exteriorVotes;
    }
  }
  if (interiorVotes == 0 && exteriorVotes == 0) {
    return 0;
  }
  return exteriorVotes > interiorVotes ? -1 : 1;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

void collect_cell_source_faces(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    std::vector<int> &sourceFaces) {
  std::set<int> faceSet;
  for (const int halfedgeId : cellHalfedges) {
    if (halfedgeId < 0 || halfedgeId >= static_cast<int>(halfedges.size())) {
      continue;
    }
    const SurfaceArrangementHalfedge &halfedge =
        halfedges[static_cast<std::size_t>(halfedgeId)];
    if (halfedge.sourceFace >= 0) {
      faceSet.insert(halfedge.sourceFace);
    }
    for (const SurfaceArrangementProvenance &provenance :
         halfedge.provenance) {
      if (provenance.sourceFace >= 0) {
        faceSet.insert(provenance.sourceFace);
      }
    }
  }
  sourceFaces.assign(faceSet.begin(), faceSet.end());
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry::surface_arrangement_detail {

static double consecutive_halfedge_alignment(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces) {
  if (a.to != b.from || a.from < 0 || a.to < 0 || b.to < 0 ||
      a.from >= static_cast<int>(nodes.size()) ||
      a.to >= static_cast<int>(nodes.size()) ||
      b.to >= static_cast<int>(nodes.size())) {
    return -1.0;
  }
  const SurfaceArrangementNode &join = nodes[static_cast<std::size_t>(a.to)];
  const Eigen::RowVector3d normal = node_reference_normal(vertices, faces, join);
  if (normal.squaredNorm() <= 1.0e-20) {
    return -1.0;
  }
  const Eigen::RowVector3d joinPosition = node_position(vertices, faces, join);
  Eigen::RowVector3d incoming =
      joinPosition -
      node_position(vertices, faces, nodes[static_cast<std::size_t>(a.from)]);
  Eigen::RowVector3d outgoing =
      node_position(vertices, faces, nodes[static_cast<std::size_t>(b.to)]) -
      joinPosition;
  incoming -= incoming.dot(normal) * normal;
  outgoing -= outgoing.dot(normal) * normal;
  const double incomingNorm = incoming.norm();
  const double outgoingNorm = outgoing.norm();
  if (!(incomingNorm > 1.0e-14) || !(outgoingNorm > 1.0e-14)) {
    return -1.0;
  }
  return incoming.dot(outgoing) / (incomingNorm * outgoingNorm);
}

bool same_family_collinear(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces) {
  if (a.family != b.family) {
    return false;
  }
  return consecutive_halfedge_alignment(a, b, nodes, vertices, faces) >=
         1.0 - 1.0e-8;
}

bool same_logical_side(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces) {
  const auto normalized_family = [](const int family) {
    return family < 0 ? family : ((family % 2) + 2) % 2;
  };
  if (a.to != b.from || normalized_family(a.family) !=
                            normalized_family(b.family)) {
    return false;
  }
  const bool sameRail = a.railId >= 0 && a.railId == b.railId &&
                        (a.curveId < 0 || b.curveId < 0 ||
                         a.curveId == b.curveId);
  const bool sameCurve = a.curveId >= 0 && a.curveId == b.curveId;
  const bool sameStrand = a.strand >= 0 && a.strand == b.strand;
  const bool sameProposalSide =
      a.proposalId >= 0 && a.proposalId == b.proposalId &&
      a.proposalSide >= 0 && a.proposalSide == b.proposalSide;
  bool sameSourceArc = a.sourceArc >= 0 && a.sourceArc == b.sourceArc;
  if (!sameSourceArc) {
    for (const SurfaceArrangementProvenance &first : a.provenance) {
      if (first.sourceArc < 0) {
        continue;
      }
      sameSourceArc = std::any_of(
          b.provenance.begin(), b.provenance.end(),
          [&](const SurfaceArrangementProvenance &second) {
            return second.sourceArc == first.sourceArc;
          });
      if (sameSourceArc) {
        break;
      }
    }
  }
  if (sameRail || sameCurve || sameStrand || sameProposalSide ||
      sameSourceArc) {
    // Identity establishes that both pieces belong to one embedded curve,
    // while this turn guard still splits closed rails and self-intersections
    // at actual corners.  Forty-five degrees permits piecewise-linear traces
    // to follow smooth source curvature without merging orthogonal sides.
    constexpr double minimumSmoothAlignment = 0.70710678118654752440;
    return consecutive_halfedge_alignment(a, b, nodes, vertices, faces) >=
           minimumSmoothAlignment;
  }

  SurfaceArrangementHalfedge normalizedA = a;
  SurfaceArrangementHalfedge normalizedB = b;
  normalizedA.family = normalized_family(a.family);
  normalizedB.family = normalized_family(b.family);
  // Two independently traced pieces of the same transported family can meet
  // after intersection planting or endpoint completion. Provenance identity
  // is then different even though the field supplies a unique smooth
  // continuation. Use the same branch-turn guard as identity-preserving
  // pieces; exact collinearity is not invariant under curved source-face
  // transport and was fragmenting one logical side at every such junction.
  constexpr double minimumSmoothAlignment = 0.70710678118654752440;
  return consecutive_halfedge_alignment(normalizedA, normalizedB, nodes,
                                        vertices, faces) >=
         minimumSmoothAlignment;
}

} // namespace directional::geometry::surface_arrangement_detail

namespace directional::geometry {

const SurfaceCellOwnershipClassRecord *find_surface_cell_ownership_class(
    const SurfaceCellComplex &complex,
    const SurfaceCellCanonicalIdentity &key) {
  int component = -1;
  int ordinal = -1;
  if (!decode_surface_cell_ownership_key(key, component, ordinal) ||
      ordinal < 0 ||
      ordinal >= static_cast<int>(complex.sourceOwnershipRegistry.size())) {
    return nullptr;
  }
  const SurfaceCellOwnershipClassRecord &record =
      complex.sourceOwnershipRegistry[static_cast<std::size_t>(ordinal)];
  return record.sourceComponent == component && record.valid() ? &record
                                                               : nullptr;
}

bool validate_surface_cell_ownership_registry(
    const SurfaceCellComplex &complex) {
  if (!std::is_sorted(complex.sourceOwnershipRegistry.begin(),
                      complex.sourceOwnershipRegistry.end()) ||
      std::adjacent_find(complex.sourceOwnershipRegistry.begin(),
                         complex.sourceOwnershipRegistry.end()) !=
          complex.sourceOwnershipRegistry.end()) {
    return false;
  }
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    if (!record.valid()) {
      return false;
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.sourceOwnershipClass.valid) {
      if (!cell.boundaryCycle &&
          cell.cellClass != SurfaceArrangementCellClass::Exterior) {
        return false;
      }
      continue;
    }
    const SurfaceCellOwnershipClassRecord *record =
        find_surface_cell_ownership_class(complex, cell.sourceOwnershipClass);
    if (record == nullptr || cell.sourceComponent != record->sourceComponent ||
        !std::is_sorted(cell.sourceCharts.begin(), cell.sourceCharts.end())) {
      return false;
    }
    for (const SurfaceCellSourceChart &chart : cell.sourceCharts) {
      if (!std::binary_search(record->exactCharts.begin(),
                              record->exactCharts.end(), chart)) {
        return false;
      }
    }
  }
  return true;
}

bool canonicalize_surface_cell_ownership(
    SurfaceCellComplex &complex, const Eigen::MatrixXi &faces) {
  if (faces.cols() != 3) {
    return false;
  }
  if (validate_surface_cell_ownership_registry(complex)) {
    return true;
  }

  std::vector<SurfaceCellOwnershipClassRecord> records;
  records.reserve(complex.cells.size());
  const auto face_for_vertices = [&](const std::array<int, 3> &vertices) {
    for (int face = 0; face < faces.rows(); ++face) {
      std::array<int, 3> candidate{{faces(face, 0), faces(face, 1),
                                    faces(face, 2)}};
      std::sort(candidate.begin(), candidate.end());
      if (candidate == vertices) {
        return face;
      }
    }
    return -1;
  };
  const auto membership_signature =
      [&](const std::vector<SurfaceCellSourceChart> &charts) {
        SurfaceCellCanonicalIdentity identity;
        std::vector<std::array<std::int64_t, 5>> members;
        members.reserve(charts.size());
        for (const SurfaceCellSourceChart &chart : charts) {
          if (!chart.valid()) {
            return SurfaceCellCanonicalIdentity{};
          }
          if (faces.rows() == 0) {
            members.push_back({chart.sourceComponent, chart.localSheet,
                               chart.sourceFace, -1, -1});
            continue;
          }
          if (chart.sourceFace >= faces.rows()) {
            return SurfaceCellCanonicalIdentity{};
          }
          std::array<int, 3> vertices{{faces(chart.sourceFace, 0),
                                       faces(chart.sourceFace, 1),
                                       faces(chart.sourceFace, 2)}};
          std::sort(vertices.begin(), vertices.end());
          members.push_back({chart.sourceComponent, chart.localSheet,
                             vertices[0], vertices[1], vertices[2]});
        }
        std::sort(members.begin(), members.end());
        members.erase(std::unique(members.begin(), members.end()),
                      members.end());
        if (members.empty()) {
          return identity;
        }
        identity.valid = true;
        identity.values.push_back(static_cast<std::int64_t>(members.size()));
        for (const auto &member : members) {
          identity.values.insert(identity.values.end(), member.begin(),
                                 member.end());
        }
        return identity;
      };
  const auto legacy_record = [&](const SurfaceArrangementCell &cell) {
    SurfaceCellOwnershipClassRecord record;
    record.sourceComponent = cell.sourceComponent;
    record.exactCharts = cell.sourceCharts;
    std::sort(record.exactCharts.begin(), record.exactCharts.end());
    record.exactCharts.erase(
        std::unique(record.exactCharts.begin(), record.exactCharts.end()),
        record.exactCharts.end());

    const auto &values = cell.sourceOwnershipClass.values;
    if (cell.sourceOwnershipClass.valid && values.size() >= 6U &&
        values[0] >= 1 &&
        values.size() == 1U + static_cast<std::size_t>(values[0]) * 5U) {
      record.exactCharts.clear();
      for (std::size_t offset = 1U; offset < values.size(); offset += 5U) {
        if (values[offset] < 0 || values[offset + 1U] < 0) {
          return SurfaceCellOwnershipClassRecord{};
        }
        std::array<int, 3> vertices{{static_cast<int>(values[offset + 2U]),
                                     static_cast<int>(values[offset + 3U]),
                                     static_cast<int>(values[offset + 4U])}};
        std::sort(vertices.begin(), vertices.end());
        const int face = face_for_vertices(vertices);
        if (face < 0) {
          return SurfaceCellOwnershipClassRecord{};
        }
        record.sourceComponent = static_cast<int>(values[offset]);
        record.exactCharts.push_back(
            {record.sourceComponent, face, static_cast<int>(values[offset + 1U])});
      }
      std::sort(record.exactCharts.begin(), record.exactCharts.end());
      record.exactCharts.erase(
          std::unique(record.exactCharts.begin(), record.exactCharts.end()),
          record.exactCharts.end());
    }
    if (record.exactCharts.empty() && cell.sourceComponent >= 0 &&
        cell.sourceSheet >= 0) {
      std::vector<int> sourceFaces = cell.sourceFaces;
      if (sourceFaces.empty() && cell.sourceFace >= 0) {
        sourceFaces.push_back(cell.sourceFace);
      }
      for (const int face : sourceFaces) {
        record.exactCharts.push_back(
            {cell.sourceComponent, face, cell.sourceSheet});
      }
      std::sort(record.exactCharts.begin(), record.exactCharts.end());
      record.exactCharts.erase(
          std::unique(record.exactCharts.begin(), record.exactCharts.end()),
          record.exactCharts.end());
    }
    if (record.sourceComponent < 0 && !record.exactCharts.empty()) {
      record.sourceComponent = record.exactCharts.front().sourceComponent;
    }
    record.canonicalMembership = membership_signature(record.exactCharts);
    return record;
  };

  std::vector<SurfaceCellOwnershipClassRecord> cellRecords;
  cellRecords.reserve(complex.cells.size());
  for (const SurfaceArrangementCell &cell : complex.cells) {
    SurfaceCellOwnershipClassRecord record = legacy_record(cell);
    if (!record.valid()) {
      if (cell.boundaryCycle || cell.cellClass ==
                                    SurfaceArrangementCellClass::Exterior) {
        cellRecords.push_back({});
        continue;
      }
      return false;
    }
    records.push_back(record);
    cellRecords.push_back(std::move(record));
  }
  std::sort(records.begin(), records.end());
  records.erase(std::unique(records.begin(), records.end()), records.end());
  complex.sourceOwnershipRegistry = records;
  for (std::size_t cellIndex = 0; cellIndex < complex.cells.size(); ++cellIndex) {
    SurfaceArrangementCell &cell = complex.cells[cellIndex];
    const SurfaceCellOwnershipClassRecord &record = cellRecords[cellIndex];
    if (!record.valid()) {
      cell.sourceOwnershipClass = {};
      continue;
    }
    const auto found = std::lower_bound(records.begin(), records.end(), record);
    if (found == records.end() || !(*found == record)) {
      return false;
    }
    const int ordinal = static_cast<int>(std::distance(records.begin(), found));
    cell.sourceComponent = record.sourceComponent;
    cell.sourceOwnershipClass =
        make_surface_cell_ownership_key(record.sourceComponent, ordinal);
    cell.sourceCharts.erase(
        std::remove_if(cell.sourceCharts.begin(), cell.sourceCharts.end(),
                       [&](const SurfaceCellSourceChart &chart) {
                         return !std::binary_search(record.exactCharts.begin(),
                                                    record.exactCharts.end(), chart);
                       }),
        cell.sourceCharts.end());
  }
  return validate_surface_cell_ownership_registry(complex);
}

SurfaceCellComplex build_surface_cell_complex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<SurfaceArrangementArc> &inputArcs,
    const SurfaceArrangementOptions &options) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("surface arrangement requires triangle mesh.");
  }
  using namespace surface_arrangement_detail;
  SurfaceCellComplex complex;
  bool embeddingValid = true;
  std::uint64_t peakOwnedBytes = 0;
  const auto update_peak_memory = [&](const std::uint64_t temporaryBytes = 0) {
    peakOwnedBytes = std::max(
        peakOwnedBytes,
        complex_storage_bytes(complex) + temporaryBytes);
  };
  std::vector<Segment2> segments;
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);

  // Ownership labels are optional at the public API boundary, but ownership
  // itself is not. Derive deterministic intrinsic defaults so topology-only
  // callers enter the same canonical path as fully labelled production calls.
  std::vector<std::vector<int>> faceAdjacency(
      static_cast<std::size_t>(faces.rows()));
  for (const auto &[key, incident] : edgeFaces) {
    (void)key;
    if (incident[0] >= 0 && incident[1] >= 0) {
      faceAdjacency[static_cast<std::size_t>(incident[0])].push_back(incident[1]);
      faceAdjacency[static_cast<std::size_t>(incident[1])].push_back(incident[0]);
    }
  }

  const bool hasExplicitComponents =
      options.sourceFaceComponents != nullptr &&
      options.sourceFaceComponents->size() ==
          static_cast<std::size_t>(faces.rows()) &&
      std::all_of(options.sourceFaceComponents->begin(),
                  options.sourceFaceComponents->end(),
                  [](const int component) { return component >= 0; });
  std::vector<int> resolvedComponents(static_cast<std::size_t>(faces.rows()),
                                      -1);
  if (hasExplicitComponents) {
    resolvedComponents = *options.sourceFaceComponents;
  } else {
    int rawComponentCount = 0;
    for (int seed = 0; seed < faces.rows(); ++seed) {
      if (resolvedComponents[static_cast<std::size_t>(seed)] >= 0) {
        continue;
      }
      std::queue<int> pending;
      pending.push(seed);
      resolvedComponents[static_cast<std::size_t>(seed)] = rawComponentCount;
      while (!pending.empty()) {
        const int face = pending.front();
        pending.pop();
        for (const int neighbor :
             faceAdjacency[static_cast<std::size_t>(face)]) {
          if (resolvedComponents[static_cast<std::size_t>(neighbor)] >= 0) {
            continue;
          }
          resolvedComponents[static_cast<std::size_t>(neighbor)] =
              rawComponentCount;
          pending.push(neighbor);
        }
      }
      ++rawComponentCount;
    }

    // Remap components by their intrinsic minimum source-triangle signature so
    // component ids do not depend on source-face row order.
    std::vector<std::array<int, 3>> componentSignatures(
        static_cast<std::size_t>(rawComponentCount),
        std::array<int, 3>{{std::numeric_limits<int>::max(),
                            std::numeric_limits<int>::max(),
                            std::numeric_limits<int>::max()}});
    for (int face = 0; face < faces.rows(); ++face) {
      std::array<int, 3> signature{{faces(face, 0), faces(face, 1),
                                    faces(face, 2)}};
      std::sort(signature.begin(), signature.end());
      const int raw = resolvedComponents[static_cast<std::size_t>(face)];
      componentSignatures[static_cast<std::size_t>(raw)] =
          std::min(componentSignatures[static_cast<std::size_t>(raw)],
                   signature);
    }
    std::vector<int> order(static_cast<std::size_t>(rawComponentCount));
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](const int lhs, const int rhs) {
      return componentSignatures[static_cast<std::size_t>(lhs)] <
             componentSignatures[static_cast<std::size_t>(rhs)];
    });
    std::vector<int> remap(static_cast<std::size_t>(rawComponentCount), -1);
    for (int ordinal = 0; ordinal < rawComponentCount; ++ordinal) {
      remap[static_cast<std::size_t>(order[static_cast<std::size_t>(ordinal)])] =
          ordinal;
    }
    for (int &component : resolvedComponents) {
      component = remap[static_cast<std::size_t>(component)];
    }
  }

  const bool hasExplicitSheets =
      options.sourceFaceSheets != nullptr &&
      options.sourceFaceSheets->size() ==
          static_cast<std::size_t>(faces.rows()) &&
      std::all_of(options.sourceFaceSheets->begin(),
                  options.sourceFaceSheets->end(),
                  [](const int sheet) { return sheet >= 0; });
  std::vector<int> resolvedSheets(static_cast<std::size_t>(faces.rows()), 0);
  if (hasExplicitSheets) {
    resolvedSheets = *options.sourceFaceSheets;
  }
  SurfaceArrangementOptions resolvedOptions = options;
  resolvedOptions.sourceFaceComponents = &resolvedComponents;
  resolvedOptions.sourceFaceSheets = &resolvedSheets;

  // R1 is the sole authority for source-chart connectivity. Build the graph
  // before node identity or radial incidence so hard rails, boundaries,
  // nonmanifold sectors, disconnected fans, and component barriers are never
  // reconstructed from raw labels or geometric proximity.
  const SourceChartTransitionGraph transitionGraph(
      faces, resolvedComponents, resolvedSheets,
      &resolvedOptions.hardFeatureEdges);
  if (!transitionGraph.available()) {
    embeddingValid = false;
    complex.diagnostics.incidenceFailure =
        SurfaceArrangementIncidenceFailure::SourceTransitionUnavailable;
  }

  VertexFanScopes vertexFanScopes;
  std::vector<std::pair<SurfaceCellCanonicalIdentity, FaceVertexKey>>
      vertexFanRecords;
  vertexFanRecords.reserve(static_cast<std::size_t>(faces.rows()) * 3U);
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      if (vertex < 0 || vertex >= vertices.rows()) {
        throw std::invalid_argument(
            "surface arrangement received an invalid face index.");
      }
      SurfaceCellCanonicalIdentity identity;
      if (transitionGraph.available()) {
        SurfacePoint point;
        point.face = face;
        point.component = resolvedComponents[static_cast<std::size_t>(face)];
        point.sheet = resolvedSheets[static_cast<std::size_t>(face)];
        point.barycentric = Eigen::Vector3d::Unit(corner);
        const SourceEntityId entity = transitionGraph.resolve_entity(point);
        if (entity.valid() && entity.kind == SourceEntityKind::SourceVertex &&
            entity.firstSourceIndex == vertex) {
          identity = entity.canonical;
        }
      }
      if (!identity.valid) {
        // Preserve a deterministic fail-closed scope when R1 is unavailable.
        // The topology-valid flag remains false; this only prevents unrelated
        // source vertices from being merged while diagnostics are produced.
        identity.valid = true;
        identity.values = {
            static_cast<std::int64_t>(SourceEntityKind::SourceVertex),
            resolvedComponents[static_cast<std::size_t>(face)], vertex, face};
      }
      vertexFanRecords.push_back({std::move(identity), {face, vertex}});
    }
  }
  std::sort(vertexFanRecords.begin(), vertexFanRecords.end(),
            [](const auto &lhs, const auto &rhs) {
              return std::tie(lhs.first, lhs.second) <
                     std::tie(rhs.first, rhs.second);
            });
  int nextVertexFanScope = -1;
  SurfaceCellCanonicalIdentity previousFan;
  for (const auto &[identity, faceVertex] : vertexFanRecords) {
    if (nextVertexFanScope < 0 || identity != previousFan) {
      ++nextVertexFanScope;
      previousFan = identity;
    }
    vertexFanScopes.emplace(faceVertex, nextVertexFanScope);
  }
  const VertexFanWedges vertexFanWedges = build_vertex_fan_wedges(
      vertices, faces, edgeFaces, vertexFanScopes);

  for (int face = 0; face < faces.rows(); ++face) {
    for (const auto &[a, b, edge] :
         {std::tuple<int, int, int>{0, 1, 2}, {1, 2, 0}, {2, 0, 1}}) {
      const std::uint64_t key = source_edge_key(faces, face, edge);
      const auto found = edgeFaces.find(key);
      const bool boundaryEdge =
          found == edgeFaces.end() || found->second[1] < 0;
      const bool hardFeature =
          resolvedOptions.hardFeatureEdges.count(key) != 0;
      if ((!resolvedOptions.insertBoundaryRails || !boundaryEdge) && !hardFeature) {
        continue;
      }
      Segment2 boundary;
      boundary.sourceArc = -1;
      boundary.sourceFace = face;
      boundary.start = bary_to_uv(Eigen::RowVector3d::Unit(a));
      boundary.end = bary_to_uv(Eigen::RowVector3d::Unit(b));
      boundary.family = -1;
      boundary.hardFeature = hardFeature || boundaryEdge;
      boundary.featureClass = edge;
      complete_segment_scope(resolvedOptions, boundary);
      segments.push_back(boundary);
    }
  }

  for (const SurfaceArrangementArc &arc : inputArcs) {
    if (arc.sourceFace < 0 || arc.sourceFace >= faces.rows()) {
      continue;
    }
    Segment2 segment;
    segment.sourceArc = arc.id;
    segment.provenance = arc.provenance;
    segment.sourceFace = arc.sourceFace;
    segment.start = bary_to_uv(arc.startBarycentric);
    segment.end = bary_to_uv(arc.endBarycentric);
    segment.family = arc.family;
    segment.strand = arc.strand;
    segment.featureClass = arc.featureClass;
    segment.hardFeature = arc.hardFeature;
    segment.layoutSupport = arc.layoutSupport;
    segment.singularitySupport = arc.singularitySupport;
    segment.railId = arc.railId;
    segment.curveId = arc.curveId;
    segment.sourceComponent = arc.sourceComponent;
    segment.sourceSheet = arc.sourceSheet;
    segment.proposalId = arc.proposalId;
    segment.proposalSeedId = arc.proposalSeedId;
    segment.proposalSide = arc.proposalSide;
    segment.proposalBoundarySegment = arc.proposalBoundarySegment;
    segment.railT0 = arc.railT0;
    segment.railT1 = arc.railT1;
    complete_segment_scope(resolvedOptions, segment);
    if (clip_to_triangle(segment.start, segment.end, segment.sourceT0,
                         segment.sourceT1)) {
      segments.push_back(segment);
    }
  }
  std::sort(segments.begin(), segments.end(), [](const Segment2 &a,
                                                 const Segment2 &b) {
    const auto qa = [](const double value) {
      return static_cast<std::int64_t>(std::llround(value * 1.0e10));
    };
    return std::make_tuple(a.sourceFace, qa(a.start.x()), qa(a.start.y()),
                           qa(a.end.x()), qa(a.end.y()), a.family, a.strand,
                           a.featureClass, a.hardFeature ? 1 : 0, a.sourceArc) <
           std::make_tuple(b.sourceFace, qa(b.start.x()), qa(b.start.y()),
                           qa(b.end.x()), qa(b.end.y()), b.family, b.strand,
                           b.featureClass, b.hardFeature ? 1 : 0, b.sourceArc);
  });

  complex.diagnostics.peakSegmentsPerFace = 0;
  for (int face = 0; face < faces.rows(); ++face) {
    int count = 0;
    for (const Segment2 &segment : segments) {
      if (segment.sourceFace == face) {
        ++count;
      }
    }
    complex.diagnostics.peakSegmentsPerFace =
        std::max(complex.diagnostics.peakSegmentsPerFace, count);
  }

  std::vector<std::vector<double>> splitParams(segments.size());
  for (auto &params : splitParams) {
    params = {0.0, 1.0};
  }
  const auto split_storage_bytes = [&]() {
    std::uint64_t bytes = vector_storage_bytes(splitParams);
    for (const auto &params : splitParams) {
      bytes += vector_storage_bytes(params);
    }
    return bytes;
  };
  update_peak_memory(vector_storage_bytes(segments) + split_storage_bytes());
  std::set<ScopedNodeKey> intersectionKeys;
  std::set<ScopedNodeKey> hardBarrierCrossingKeys;
  for (int i = 0; i < static_cast<int>(segments.size()); ++i) {
    for (int j = i + 1; j < static_cast<int>(segments.size()); ++j) {
      if (segments[static_cast<std::size_t>(i)].sourceFace !=
          segments[static_cast<std::size_t>(j)].sourceFace) {
        continue;
      }
      if (!same_segment_scope(segments[static_cast<std::size_t>(i)],
                              segments[static_cast<std::size_t>(j)])) {
        continue;
      }
      double ti = 0.0;
      double tj = 0.0;
      Eigen::Vector2d p;
      if (!segment_intersection_params(segments[static_cast<std::size_t>(i)],
                                       segments[static_cast<std::size_t>(j)], ti,
                                       tj, p)) {
        continue;
      }
      splitParams[static_cast<std::size_t>(i)].push_back(ti);
      splitParams[static_cast<std::size_t>(j)].push_back(tj);
      if (ti > 1.0e-10 && ti < 1.0 - 1.0e-10 && tj > 1.0e-10 &&
          tj < 1.0 - 1.0e-10) {
        ++complex.diagnostics.plantedIntersections;
        const bool aHard = segments[static_cast<std::size_t>(i)].hardFeature;
        const bool bHard = segments[static_cast<std::size_t>(j)].hardFeature;
        const bool aInput = segments[static_cast<std::size_t>(i)].sourceArc >= 0;
        const bool bInput = segments[static_cast<std::size_t>(j)].sourceArc >= 0;
        if (aHard != bHard && (aInput || bInput) &&
            proper_transverse_crossing(
                segments[static_cast<std::size_t>(i)],
                segments[static_cast<std::size_t>(j)], ti, tj)) {
          hardBarrierCrossingKeys.insert(make_scoped_node_key(
              faces, segments[static_cast<std::size_t>(i)], p,
              vertexFanScopes));
        }
      }
      intersectionKeys.insert(make_scoped_node_key(
          faces, segments[static_cast<std::size_t>(i)], p,
          vertexFanScopes));
    }
  }
  // A source edge is represented in both incident triangle charts.  If an
  // intersection splits an edge-aligned segment in one chart, every
  // coincident segment in the opposite chart must receive the same canonical
  // split.  Otherwise one chart contributes a direct endpoint-to-endpoint
  // chord while the other contributes a subdivided chain, creating a DCEL
  // bridge even though both describe the same intrinsic source edge.
  struct SourceEdgeSegmentRef {
    int segment = -1;
    int localEdge = -1;
    double canonicalStart = 0.0;
    double canonicalEnd = 0.0;
  };
  std::map<ScopedSourceEdgeKey, std::vector<SourceEdgeSegmentRef>>
      segmentsBySourceEdge;
  for (int segmentIndex = 0; segmentIndex < static_cast<int>(segments.size());
       ++segmentIndex) {
    const Segment2 &segment = segments[static_cast<std::size_t>(segmentIndex)];
    const Eigen::RowVector3d startBary =
        canonicalize_barycentric(uv_to_bary(segment.start));
    const Eigen::RowVector3d endBary =
        canonicalize_barycentric(uv_to_bary(segment.end));
    int localEdge = -1;
    for (int edge = 0; edge < 3; ++edge) {
      if (std::abs(startBary[edge]) <= 1.0e-10 &&
          std::abs(endBary[edge]) <= 1.0e-10) {
        localEdge = edge;
        break;
      }
    }
    if (localEdge < 0) {
      continue;
    }
    const double canonicalStart = canonical_edge_parameter(
        faces, segment.sourceFace, localEdge, segment.start);
    const double canonicalEnd = canonical_edge_parameter(
        faces, segment.sourceFace, localEdge, segment.end);
    if (!std::isfinite(canonicalStart) || !std::isfinite(canonicalEnd) ||
        std::abs(canonicalEnd - canonicalStart) <= 1.0e-14) {
      continue;
    }
    segmentsBySourceEdge[{source_edge_key(faces, segment.sourceFace,
                                          localEdge),
                          segment.sourceComponent}]
        .push_back(
            {segmentIndex, localEdge, canonicalStart, canonicalEnd});
  }
  for (const auto &[unusedEdgeKey, edgeSegments] : segmentsBySourceEdge) {
    (void)unusedEdgeKey;
    std::vector<double> canonicalSplits;
    for (const SourceEdgeSegmentRef &reference : edgeSegments) {
      const Segment2 &segment =
          segments[static_cast<std::size_t>(reference.segment)];
      for (const double parameter :
           splitParams[static_cast<std::size_t>(reference.segment)]) {
        const Eigen::Vector2d point =
            segment.start + parameter * (segment.end - segment.start);
        canonicalSplits.push_back(canonical_edge_parameter(
            faces, segment.sourceFace, reference.localEdge, point));
      }
    }
    std::sort(canonicalSplits.begin(), canonicalSplits.end());
    canonicalSplits.erase(
        std::unique(canonicalSplits.begin(), canonicalSplits.end(),
                    [](const double a, const double b) {
                      return std::abs(a - b) <= 1.0e-10;
                    }),
        canonicalSplits.end());
    for (const SourceEdgeSegmentRef &reference : edgeSegments) {
      const double denominator =
          reference.canonicalEnd - reference.canonicalStart;
      const double minimum =
          std::min(reference.canonicalStart, reference.canonicalEnd) - 1.0e-10;
      const double maximum =
          std::max(reference.canonicalStart, reference.canonicalEnd) + 1.0e-10;
      auto &parameters =
          splitParams[static_cast<std::size_t>(reference.segment)];
      for (const double canonical : canonicalSplits) {
        if (canonical < minimum || canonical > maximum) {
          continue;
        }
        const double parameter =
            (canonical - reference.canonicalStart) / denominator;
        if (parameter >= -1.0e-10 && parameter <= 1.0 + 1.0e-10) {
          parameters.push_back(std::clamp(parameter, 0.0, 1.0));
        }
      }
    }
  }

  complex.diagnostics.uniqueIntersections =
      static_cast<int>(intersectionKeys.size());
  complex.diagnostics.hardBarrierCrossings =
      static_cast<int>(hardBarrierCrossingKeys.size());
  update_peak_memory(vector_storage_bytes(segments));

  std::map<ScopedNodeKey, int> nodeByKey;
  std::vector<std::pair<int, int>> nodeScopes;
  const double positionTolerance =
      1.0e-9 * std::max(1.0, (vertices.colwise().maxCoeff() -
                             vertices.colwise().minCoeff()).norm());
  const auto node_id = [&](const Segment2 &segment,
                           const Eigen::Vector2d &rawUv,
                           const double segmentParameter) {
    const int face = segment.sourceFace;
    const Eigen::RowVector3d bary =
        canonicalize_barycentric(uv_to_bary(rawUv));
    const Eigen::Vector2d uv = bary_to_uv(bary);
    const ScopedNodeKey scopedKey =
        make_scoped_node_key(faces, segment, uv, vertexFanScopes);
    const NodeKey &key = std::get<0>(scopedKey);
    auto found = nodeByKey.find(scopedKey);
    if (found != nodeByKey.end()) {
      SurfaceArrangementNode &node =
          complex.nodes[static_cast<std::size_t>(found->second)];
      const Eigen::RowVector3d existingPosition =
          node_position(vertices, faces, node);
      const Eigen::RowVector3d occurrencePosition =
          barycentric_position(vertices, faces, face, bary);
      if (!existingPosition.allFinite() || !occurrencePosition.allFinite() ||
          (existingPosition - occurrencePosition).norm() > positionTolerance) {
        embeddingValid = false;
      }
      node.hardBarrierCrossing =
          node.hardBarrierCrossing ||
          hardBarrierCrossingKeys.count(scopedKey) != 0;
      const double sourceParameter =
          segment.sourceT0 + segmentParameter *
                                 (segment.sourceT1 - segment.sourceT0);
      const double railParameter =
          segment.railT0 + segmentParameter *
                               (segment.railT1 - segment.railT0);
      const bool occurrenceExists =
          std::any_of(node.occurrences.begin(), node.occurrences.end(),
                      [&](const SurfaceArrangementNodeOccurrence &occurrence) {
                        return occurrence.sourceFace == face &&
                               occurrence.sourceComponent ==
                                   segment.sourceComponent &&
                               occurrence.sourceSheet == segment.sourceSheet &&
                               occurrence.sourceArc == segment.sourceArc &&
                               occurrence.provenance == segment.provenance &&
                               (occurrence.barycentric - bary).norm() <= 1.0e-12;
                      });
      if (!occurrenceExists) {
        SurfaceArrangementNodeOccurrence occurrence;
        occurrence.sourceFace = face;
        occurrence.barycentric = bary;
        occurrence.sourceComponent = segment.sourceComponent;
        occurrence.sourceSheet = segment.sourceSheet;
        occurrence.sourceArc = segment.sourceArc;
        occurrence.provenance = segment.provenance;
        occurrence.railId = segment.railId;
        occurrence.curveId = segment.curveId;
        occurrence.sourceT0 = sourceParameter;
        occurrence.sourceT1 = sourceParameter;
        occurrence.railT0 = railParameter;
        occurrence.railT1 = railParameter;
        node.occurrences.push_back(std::move(occurrence));
        std::sort(node.occurrences.begin(), node.occurrences.end(),
                  [](const SurfaceArrangementNodeOccurrence &a,
                     const SurfaceArrangementNodeOccurrence &b) {
                    return std::tie(
                               a.sourceComponent, a.sourceSheet,
                               a.sourceFace, a.sourceArc, a.provenance,
                               a.railId, a.curveId, a.sourceT0, a.sourceT1,
                               a.railT0, a.railT1, a.barycentric[0],
                               a.barycentric[1], a.barycentric[2]) <
                           std::tie(
                               b.sourceComponent, b.sourceSheet,
                               b.sourceFace, b.sourceArc, b.provenance,
                               b.railId, b.curveId, b.sourceT0, b.sourceT1,
                               b.railT0, b.railT1, b.barycentric[0],
                               b.barycentric[1], b.barycentric[2]);
                  });
      }
      return found->second;
    }
    SurfaceArrangementNode node;
    node.id = static_cast<int>(complex.nodes.size());
    node.sourceFace = face;
    node.sourceComponent = segment.sourceComponent;
    node.sourceSheet = segment.sourceSheet;
    node.hardBarrierCrossing =
        hardBarrierCrossingKeys.count(scopedKey) != 0;
    node.barycentric = bary;
    node.sourceEdge =
        key.kind == 1 ? static_cast<int>(key.edge & 0x7fffffffu) : -1;
    node.sourceEdgeParameter =
        key.kind == 1 ? static_cast<double>(key.edgeT) / 1.0e10 : 0.0;
    SurfaceArrangementNodeOccurrence occurrence;
    occurrence.sourceFace = face;
    occurrence.barycentric = bary;
    occurrence.sourceComponent = segment.sourceComponent;
    occurrence.sourceSheet = segment.sourceSheet;
    occurrence.sourceArc = segment.sourceArc;
    occurrence.provenance = segment.provenance;
    occurrence.railId = segment.railId;
    occurrence.curveId = segment.curveId;
    occurrence.sourceT0 =
        segment.sourceT0 + segmentParameter *
                               (segment.sourceT1 - segment.sourceT0);
    occurrence.sourceT1 = occurrence.sourceT0;
    occurrence.railT0 =
        segment.railT0 + segmentParameter *
                             (segment.railT1 - segment.railT0);
    occurrence.railT1 = occurrence.railT0;
    node.occurrences.push_back(std::move(occurrence));
    nodeByKey.emplace(scopedKey, node.id);
    nodeScopes.emplace_back(std::get<1>(scopedKey),
                            std::get<2>(scopedKey));
    complex.nodes.push_back(node);
    return node.id;
  };

  std::map<std::pair<int, int>, int> halfedgeByUndirectedNodes;
  const auto append_provenance =
      [](SurfaceArrangementHalfedge &halfedge, const Segment2 &segment,
         const double sourceT0, const double sourceT1, const double railT0,
         const double railT1) {
        SurfaceArrangementProvenance value;
        value.sourceArc = segment.sourceArc;
        value.provenance = segment.provenance;
        value.sourceFace = segment.sourceFace;
        value.family = segment.family;
        value.strand = segment.strand;
        value.featureClass = segment.featureClass;
        value.hardFeature = segment.hardFeature;
        value.layoutSupport = segment.layoutSupport;
        value.singularitySupport = segment.singularitySupport;
        value.railId = segment.railId;
        value.curveId = segment.curveId;
        value.sourceComponent = segment.sourceComponent;
        value.sourceSheet = segment.sourceSheet;
        value.proposalId = segment.proposalId;
        value.proposalSeedId = segment.proposalSeedId;
        value.proposalSide = segment.proposalSide;
        value.proposalBoundarySegment = segment.proposalBoundarySegment;
        value.sourceT0 = sourceT0;
        value.sourceT1 = sourceT1;
        value.railT0 = railT0;
        value.railT1 = railT1;
        const auto same = [&](const SurfaceArrangementProvenance &existing) {
          return existing.sourceArc == value.sourceArc &&
                 existing.provenance == value.provenance &&
                 existing.sourceFace == value.sourceFace &&
                 existing.family == value.family &&
                 existing.strand == value.strand &&
                 existing.featureClass == value.featureClass &&
                 existing.hardFeature == value.hardFeature &&
                 existing.layoutSupport == value.layoutSupport &&
                 existing.singularitySupport == value.singularitySupport &&
                 existing.railId == value.railId &&
                 existing.curveId == value.curveId &&
                 existing.sourceComponent == value.sourceComponent &&
                 existing.sourceSheet == value.sourceSheet &&
                 existing.proposalId == value.proposalId &&
                 existing.proposalSeedId == value.proposalSeedId &&
                 existing.proposalSide == value.proposalSide &&
                 existing.proposalBoundarySegment ==
                     value.proposalBoundarySegment &&
                 std::abs(existing.sourceT0 - value.sourceT0) <= 1.0e-12 &&
                 std::abs(existing.sourceT1 - value.sourceT1) <= 1.0e-12 &&
                 std::abs(existing.railT0 - value.railT0) <= 1.0e-12 &&
                 std::abs(existing.railT1 - value.railT1) <= 1.0e-12;
        };
        if (std::none_of(halfedge.provenance.begin(), halfedge.provenance.end(),
                         same)) {
          halfedge.provenance.push_back(value);
        }
      };

  for (int segmentIndex = 0; segmentIndex < static_cast<int>(segments.size());
       ++segmentIndex) {
    auto &params = splitParams[static_cast<std::size_t>(segmentIndex)];
    params.erase(std::remove_if(params.begin(), params.end(), [](double value) {
                   return !std::isfinite(value) || value < -1.0e-12 ||
                          value > 1.0 + 1.0e-12;
                 }),
                 params.end());
    for (double &parameter : params) {
      parameter = std::clamp(parameter, 0.0, 1.0);
    }
    std::sort(params.begin(), params.end());
    params.erase(std::unique(params.begin(), params.end(), [](double a, double b) {
                   return std::abs(a - b) <= 1.0e-10;
                 }),
                 params.end());
    const Segment2 &segment = segments[static_cast<std::size_t>(segmentIndex)];
    for (int k = 0; k + 1 < static_cast<int>(params.size()); ++k) {
      const double t0 = params[static_cast<std::size_t>(k)];
      const double t1 = params[static_cast<std::size_t>(k + 1)];
      if (t1 - t0 <= 1.0e-12) {
        continue;
      }
      const Eigen::Vector2d p0 =
          segment.start + t0 * (segment.end - segment.start);
      const Eigen::Vector2d p1 =
          segment.start + t1 * (segment.end - segment.start);
      const int a = node_id(segment, p0, t0);
      const int b = node_id(segment, p1, t1);
      if (a == b) {
        continue;
      }

      const std::pair<int, int> edgeKey{std::min(a, b), std::max(a, b)};
      int forwardId = -1;
      auto foundEdge = halfedgeByUndirectedNodes.find(edgeKey);
      if (foundEdge == halfedgeByUndirectedNodes.end()) {
        SurfaceArrangementHalfedge h0;
        SurfaceArrangementHalfedge h1;
        h0.id = static_cast<int>(complex.halfedges.size());
        h1.id = h0.id + 1;
        h0.twin = h1.id;
        h1.twin = h0.id;
        h0.from = a;
        h0.to = b;
        h1.from = b;
        h1.to = a;
        complex.halfedges.push_back(h0);
        complex.halfedges.push_back(h1);
        halfedgeByUndirectedNodes.emplace(edgeKey, h0.id);
        forwardId = h0.id;
      } else {
        const int storedId = foundEdge->second;
        const SurfaceArrangementHalfedge &stored =
            complex.halfedges[static_cast<std::size_t>(storedId)];
        forwardId = stored.from == a && stored.to == b ? storedId : stored.twin;
      }

      SurfaceArrangementHalfedge &forward =
          complex.halfedges[static_cast<std::size_t>(forwardId)];
      SurfaceArrangementHalfedge &reverse =
          complex.halfedges[static_cast<std::size_t>(forward.twin)];
      const double source0 =
          segment.sourceT0 + t0 * (segment.sourceT1 - segment.sourceT0);
      const double source1 =
          segment.sourceT0 + t1 * (segment.sourceT1 - segment.sourceT0);
      const double rail0 =
          segment.railT0 + t0 * (segment.railT1 - segment.railT0);
      const double rail1 =
          segment.railT0 + t1 * (segment.railT1 - segment.railT0);
      append_provenance(forward, segment, source0, source1, rail0, rail1);
      append_provenance(reverse, segment, source1, source0, rail1, rail0);
    }
  }

  for (SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    std::sort(
        halfedge.provenance.begin(), halfedge.provenance.end(),
        [](const SurfaceArrangementProvenance &a,
           const SurfaceArrangementProvenance &b) {
          const auto key = [](const SurfaceArrangementProvenance &value) {
            return std::make_tuple(
                value.sourceArc >= 0 ? 0 : 1, value.hardFeature ? 0 : 1,
                value.layoutSupport ? 0 : 1,
                value.singularitySupport ? 0 : 1,
                value.sourceFace, value.sourceArc, value.provenance,
                value.family, value.strand, value.featureClass, value.railId,
                value.curveId, value.sourceComponent, value.sourceSheet,
                value.proposalId, value.proposalSeedId, value.proposalSide,
                value.proposalBoundarySegment,
                static_cast<std::int64_t>(
                    std::llround(value.sourceT0 * 1.0e10)),
                static_cast<std::int64_t>(
                    std::llround(value.sourceT1 * 1.0e10)),
                static_cast<std::int64_t>(
                    std::llround(value.railT0 * 1.0e10)),
                static_cast<std::int64_t>(
                    std::llround(value.railT1 * 1.0e10)));
          };
          return key(a) < key(b);
        });
    if (halfedge.provenance.empty()) {
      continue;
    }
    const SurfaceArrangementProvenance &primary = halfedge.provenance.front();
    const auto railPrimary = std::min_element(
        halfedge.provenance.begin(), halfedge.provenance.end(),
        [](const SurfaceArrangementProvenance &lhs,
           const SurfaceArrangementProvenance &rhs) {
          const auto key = [](const SurfaceArrangementProvenance &value) {
            return std::make_tuple(
                value.railId >= 0 ? 0 : 1,
                value.hardFeature ? 0 : 1,
                value.railId, value.curveId, value.sourceComponent,
                value.sourceSheet, value.sourceFace,
                static_cast<std::int64_t>(
                    std::llround(std::min(value.railT0, value.railT1) *
                                 1.0e10)),
                static_cast<std::int64_t>(
                    std::llround(std::max(value.railT0, value.railT1) *
                                 1.0e10)));
          };
          return key(lhs) < key(rhs);
        });
    const SurfaceArrangementProvenance *authoritativeRail =
        railPrimary != halfedge.provenance.end() &&
                railPrimary->railId >= 0
            ? &*railPrimary
            : nullptr;
    halfedge.sourceArc = primary.sourceArc;
    halfedge.family = primary.family;
    halfedge.strand = primary.strand;
    halfedge.featureClass = primary.featureClass;
    halfedge.sourceFace = primary.sourceFace;
    halfedge.sourceT0 = primary.sourceT0;
    halfedge.sourceT1 = primary.sourceT1;
    halfedge.hardFeature =
        std::any_of(halfedge.provenance.begin(), halfedge.provenance.end(),
                    [](const SurfaceArrangementProvenance &value) {
                      return value.hardFeature;
                    });
    halfedge.layoutSupport =
        std::any_of(halfedge.provenance.begin(), halfedge.provenance.end(),
                    [](const SurfaceArrangementProvenance &value) {
                      return value.layoutSupport;
                    });
    halfedge.singularitySupport =
        std::any_of(halfedge.provenance.begin(), halfedge.provenance.end(),
                    [](const SurfaceArrangementProvenance &value) {
                      return value.singularitySupport;
                    });
    halfedge.railId =
        authoritativeRail != nullptr ? authoritativeRail->railId
                                     : primary.railId;
    halfedge.curveId =
        authoritativeRail != nullptr ? authoritativeRail->curveId
                                     : primary.curveId;
    halfedge.sourceComponent =
        authoritativeRail != nullptr ? authoritativeRail->sourceComponent
                                     : primary.sourceComponent;
    halfedge.sourceSheet =
        authoritativeRail != nullptr ? authoritativeRail->sourceSheet
                                     : primary.sourceSheet;
    halfedge.proposalId = primary.proposalId;
    halfedge.proposalSeedId = primary.proposalSeedId;
    halfedge.proposalSide = primary.proposalSide;
    halfedge.proposalBoundarySegment = primary.proposalBoundarySegment;
    halfedge.railT0 =
        authoritativeRail != nullptr ? authoritativeRail->railT0
                                     : primary.railT0;
    halfedge.railT1 =
        authoritativeRail != nullptr ? authoritativeRail->railT1
                                     : primary.railT1;
  }

  struct DirectedWedgeWitness {
    int halfedge = -1;
    int sourceFace = -1;
    int sourceComponent = -1;
    int sourceSheet = -1;
    SourceEntityKind kind = SourceEntityKind::Invalid;
    double localParameter = 0.0;
    double leftScore = 0.0;
  };
  struct DirectedWedgeRay {
    int halfedge = -1;
    double parameter = 0.0;
    std::vector<DirectedWedgeWitness> witnesses;
  };

  bool directedIncidenceValid = transitionGraph.available();
  const auto record_incidence_failure =
      [&](const SurfaceArrangementIncidenceFailure failure, const int node,
          const int halfedge, const int twin, const int next) {
        directedIncidenceValid = false;
        embeddingValid = false;
        if (complex.diagnostics.incidenceFailure ==
            SurfaceArrangementIncidenceFailure::None) {
          complex.diagnostics.incidenceFailure = failure;
          complex.diagnostics.incidenceFailureNode = node;
          complex.diagnostics.incidenceFailureHalfedge = halfedge;
          complex.diagnostics.incidenceFailureTwin = twin;
          complex.diagnostics.incidenceFailureNext = next;
        }
      };

  const auto halfedge_source_charts =
      [&](const SurfaceArrangementHalfedge &halfedge) {
        std::set<SurfaceCellSourceChart> charts;
        for (const SurfaceArrangementProvenance &entry : halfedge.provenance) {
          const SurfaceCellSourceChart chart{entry.sourceComponent,
                                             entry.sourceFace,
                                             entry.sourceSheet};
          if (chart.valid()) {
            charts.insert(chart);
          }
        }
        const SurfaceCellSourceChart primary{halfedge.sourceComponent,
                                             halfedge.sourceFace,
                                             halfedge.sourceSheet};
        if (primary.valid()) {
          charts.insert(primary);
        }
        return std::vector<SurfaceCellSourceChart>(charts.begin(), charts.end());
      };

  const auto node_point_on_chart =
      [&](const int nodeId, const SurfaceCellSourceChart &chart,
          SurfacePoint &point) {
        point = {};
        if (nodeId < 0 || nodeId >= static_cast<int>(complex.nodes.size()) ||
            !chart.valid()) {
          return false;
        }
        const SurfaceArrangementNode &node =
            complex.nodes[static_cast<std::size_t>(nodeId)];
        Eigen::RowVector3d barycentric = node_barycentric_on_face(
            node, chart.sourceFace, chart.sourceComponent, chart.localSheet);
        if (!barycentric.allFinite()) {
          for (const SurfaceArrangementNodeOccurrence &occurrence :
               node.occurrences) {
            SurfacePoint source;
            source.face = occurrence.sourceFace;
            source.component = occurrence.sourceComponent;
            source.sheet = occurrence.sourceSheet;
            source.barycentric = occurrence.barycentric.transpose();
            SurfacePoint rebound;
            if (transitionGraph.rebind(source, chart.sourceFace, rebound) &&
                rebound.component == chart.sourceComponent &&
                rebound.sheet == chart.localSheet) {
              barycentric = rebound.barycentric.transpose();
              break;
            }
          }
        }
        if (!barycentric.allFinite()) {
          return false;
        }
        point.face = chart.sourceFace;
        point.component = chart.sourceComponent;
        point.sheet = chart.localSheet;
        point.barycentric = barycentric.transpose();
        return true;
      };

  const auto face_signature = [&](const int face) {
    std::array<int, 3> signature{{faces(face, 0), faces(face, 1),
                                  faces(face, 2)}};
    std::sort(signature.begin(), signature.end());
    return signature;
  };

  const auto directed_chart_parameter =
      [&](const SurfaceArrangementHalfedge &halfedge,
          const SurfaceCellSourceChart &chart, const SourceEntityId &entity,
          double &parameter, double &leftScore) {
        SurfacePoint fromPoint;
        SurfacePoint toPoint;
        if (!node_point_on_chart(halfedge.from, chart, fromPoint) ||
            !node_point_on_chart(halfedge.to, chart, toPoint)) {
          return false;
        }
        const Eigen::RowVector3d fromBary = fromPoint.barycentric.transpose();
        const Eigen::RowVector3d toBary = toPoint.barycentric.transpose();
        const Eigen::Vector2d fromUv = bary_to_uv(fromBary);
        const Eigen::Vector2d toUv = bary_to_uv(toBary);
        const Eigen::Vector2d directionUv = toUv - fromUv;
        if (!(directionUv.squaredNorm() > 1.0e-28) ||
            !directionUv.allFinite()) {
          return false;
        }
        const Eigen::Vector2d triangleCentroid(1.0 / 3.0, 1.0 / 3.0);
        leftScore = cross2(directionUv,
                           triangleCentroid - 0.5 * (fromUv + toUv));

        if (entity.kind == SourceEntityKind::SourceVertex) {
          SurfaceArrangementHalfedge chartHalfedge = halfedge;
          chartHalfedge.sourceFace = chart.sourceFace;
          chartHalfedge.sourceComponent = chart.sourceComponent;
          chartHalfedge.sourceSheet = chart.localSheet;
          return intrinsic_vertex_outgoing_parameter(
              vertices, faces, vertexFanWedges, complex.nodes, chartHalfedge,
              entity.firstSourceIndex, parameter);
        }
        if (entity.kind == SourceEntityKind::SourceEdge) {
          const int lowVertex = entity.firstSourceIndex;
          const int highVertex = entity.secondSourceIndex;
          if (lowVertex < 0 || highVertex < 0 || lowVertex >= vertices.rows() ||
              highVertex >= vertices.rows()) {
            return false;
          }
          int thirdVertex = -1;
          for (int corner = 0; corner < 3; ++corner) {
            const int candidate = faces(chart.sourceFace, corner);
            if (candidate != lowVertex && candidate != highVertex) {
              thirdVertex = candidate;
              break;
            }
          }
          if (thirdVertex < 0) {
            return false;
          }
          Eigen::RowVector3d edgeDirection =
              vertices.row(highVertex) - vertices.row(lowVertex);
          const double edgeNorm = edgeDirection.norm();
          if (!(edgeNorm > 1.0e-14) || !std::isfinite(edgeNorm)) {
            return false;
          }
          edgeDirection /= edgeNorm;
          const Eigen::RowVector3d fromPosition = barycentric_position(
              vertices, faces, chart.sourceFace, fromBary);
          const Eigen::RowVector3d toPosition = barycentric_position(
              vertices, faces, chart.sourceFace, toBary);
          Eigen::RowVector3d direction = toPosition - fromPosition;
          const double directionNorm = direction.norm();
          if (!(directionNorm > 1.0e-14) || !std::isfinite(directionNorm)) {
            return false;
          }
          direction /= directionNorm;
          const Eigen::RowVector3d edgeOrigin = vertices.row(lowVertex);
          Eigen::RowVector3d inward =
              vertices.row(thirdVertex) - edgeOrigin;
          inward -= inward.dot(edgeDirection) * edgeDirection;
          const double inwardNorm = inward.norm();
          if (!(inwardNorm > 1.0e-14) || !std::isfinite(inwardNorm)) {
            return false;
          }
          inward /= inwardNorm;
          double y = direction.dot(inward);
          if (y < -1.0e-10) {
            return false;
          }
          y = std::max(0.0, y);
          parameter = std::atan2(y, direction.dot(edgeDirection));
          return std::isfinite(parameter);
        }
        if (entity.kind == SourceEntityKind::FaceInterior) {
          parameter = std::atan2(directionUv.y(), directionUv.x());
          if (parameter < 0.0) {
            parameter += 6.283185307179586476925286766559;
          }
          return std::isfinite(parameter);
        }
        return false;
      };

  using DirectedWedgeMap =
      std::map<SurfaceCellCanonicalIdentity,
               std::map<int, std::vector<DirectedWedgeWitness>>>;
  std::vector<DirectedWedgeMap> wedgeWitnesses(complex.nodes.size());
  std::vector<std::vector<int>> outgoing(complex.nodes.size());
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.from < 0 ||
        halfedge.from >= static_cast<int>(complex.nodes.size())) {
      record_incidence_failure(SurfaceArrangementIncidenceFailure::MissingWedge,
                               halfedge.from, halfedge.id, halfedge.twin, -1);
      continue;
    }
    outgoing[static_cast<std::size_t>(halfedge.from)].push_back(halfedge.id);
    bool witnessed = false;
    for (const SurfaceCellSourceChart &chart :
         halfedge_source_charts(halfedge)) {
      if (!transitionGraph.available() ||
          transitionGraph.chart_component(SourceChartId{
              chart.sourceComponent, chart.localSheet, chart.sourceFace}) < 0) {
        continue;
      }
      SurfacePoint point;
      if (!node_point_on_chart(halfedge.from, chart, point)) {
        continue;
      }
      const SourceEntityId entity = transitionGraph.resolve_entity(point);
      if (!entity.valid()) {
        continue;
      }
      double parameter = 0.0;
      double leftScore = 0.0;
      if (!directed_chart_parameter(halfedge, chart, entity, parameter,
                                    leftScore)) {
        continue;
      }
      DirectedWedgeWitness witness;
      witness.halfedge = halfedge.id;
      witness.sourceFace = chart.sourceFace;
      witness.sourceComponent = chart.sourceComponent;
      witness.sourceSheet = chart.localSheet;
      witness.kind = entity.kind;
      witness.localParameter = parameter;
      witness.leftScore = leftScore;
      wedgeWitnesses[static_cast<std::size_t>(halfedge.from)][entity.canonical]
                    [halfedge.id]
                        .push_back(std::move(witness));
      witnessed = true;
    }
    if (!witnessed) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(SurfaceArrangementIncidenceFailure::MissingWedge,
                               halfedge.from, halfedge.id, halfedge.twin, -1);
    }
  }

  std::vector<std::map<SurfaceCellCanonicalIdentity,
                       std::vector<DirectedWedgeRay>>>
      orderedWedges(complex.nodes.size());
  std::vector<std::vector<SurfaceCellCanonicalIdentity>>
      halfedgeWedges(complex.halfedges.size());
  constexpr double twoPi = 6.283185307179586476925286766559;
  constexpr double parameterTolerance = 1.0e-10;
  for (int nodeId = 0; nodeId < static_cast<int>(wedgeWitnesses.size());
       ++nodeId) {
    for (auto &[wedgeIdentity, raysByHalfedge] :
         wedgeWitnesses[static_cast<std::size_t>(nodeId)]) {
      ++complex.diagnostics.directedWedgeCount;
      std::set<int> sourceFaceSet;
      SourceEntityKind wedgeKind = SourceEntityKind::Invalid;
      for (const auto &[halfedgeId, witnesses] : raysByHalfedge) {
        (void)halfedgeId;
        for (const DirectedWedgeWitness &witness : witnesses) {
          sourceFaceSet.insert(witness.sourceFace);
          if (wedgeKind == SourceEntityKind::Invalid) {
            wedgeKind = witness.kind;
          } else if (wedgeKind != witness.kind) {
            ++complex.diagnostics.successorAmbiguityCount;
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::AmbiguousWedge, nodeId,
                witness.halfedge,
                complex.halfedges[static_cast<std::size_t>(witness.halfedge)]
                    .twin,
                -1);
          }
        }
      }
      std::vector<int> wedgeFaces(sourceFaceSet.begin(), sourceFaceSet.end());
      std::sort(wedgeFaces.begin(), wedgeFaces.end(), [&](const int lhs,
                                                           const int rhs) {
        return std::make_tuple(face_signature(lhs), lhs) <
               std::make_tuple(face_signature(rhs), rhs);
      });
      if (wedgeKind == SourceEntityKind::SourceEdge && wedgeFaces.size() > 2U) {
        ++complex.diagnostics.successorAmbiguityCount;
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::AmbiguousWedge, nodeId, -1,
            -1, -1);
      }

      std::vector<DirectedWedgeRay> rays;
      rays.reserve(raysByHalfedge.size());
      for (auto &[halfedgeId, witnesses] : raysByHalfedge) {
        std::vector<double> parameters;
        parameters.reserve(witnesses.size());
        for (const DirectedWedgeWitness &witness : witnesses) {
          double mapped = witness.localParameter;
          if (wedgeKind == SourceEntityKind::SourceEdge &&
              wedgeFaces.size() == 2U) {
            const auto found = std::find(wedgeFaces.begin(), wedgeFaces.end(),
                                         witness.sourceFace);
            if (found == wedgeFaces.end()) {
              continue;
            }
            const int side =
                static_cast<int>(std::distance(wedgeFaces.begin(), found));
            if (side == 1) {
              mapped = twoPi - mapped;
            }
            if (std::abs(mapped - twoPi) <= parameterTolerance) {
              mapped = 0.0;
            }
          }
          parameters.push_back(mapped);
        }
        if (parameters.empty()) {
          ++complex.diagnostics.successorMissingCount;
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::MissingWedge, nodeId,
              halfedgeId,
              complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
              -1);
          continue;
        }
        std::sort(parameters.begin(), parameters.end());
        double canonicalParameter = parameters.front();
        for (const double parameter : parameters) {
          double difference = std::abs(parameter - canonicalParameter);
          if (wedgeKind == SourceEntityKind::SourceEdge) {
            difference = std::min(difference, std::abs(twoPi - difference));
          }
          if (difference > parameterTolerance) {
            ++complex.diagnostics.successorAmbiguityCount;
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::AmbiguousRayOrder, nodeId,
                halfedgeId,
                complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
                -1);
          }
        }
        DirectedWedgeRay ray;
        ray.halfedge = halfedgeId;
        ray.parameter = canonicalParameter;
        ray.witnesses = witnesses;
        rays.push_back(std::move(ray));
        halfedgeWedges[static_cast<std::size_t>(halfedgeId)].push_back(
            wedgeIdentity);
      }
      std::sort(rays.begin(), rays.end(), [&](const DirectedWedgeRay &lhs,
                                              const DirectedWedgeRay &rhs) {
        if (std::abs(lhs.parameter - rhs.parameter) > parameterTolerance) {
          return lhs.parameter < rhs.parameter;
        }
        return lhs.halfedge < rhs.halfedge;
      });
      for (std::size_t index = 1; index < rays.size(); ++index) {
        if (std::abs(rays[index].parameter - rays[index - 1U].parameter) <=
            parameterTolerance &&
            rays[index].halfedge != rays[index - 1U].halfedge) {
          ++complex.diagnostics.successorAmbiguityCount;
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::AmbiguousRayOrder, nodeId,
              rays[index].halfedge,
              complex.halfedges[static_cast<std::size_t>(rays[index].halfedge)]
                  .twin,
              rays[index - 1U].halfedge);
        }
      }
      orderedWedges[static_cast<std::size_t>(nodeId)].emplace(
          wedgeIdentity, std::move(rays));
    }
  }
  for (auto &memberships : halfedgeWedges) {
    std::sort(memberships.begin(), memberships.end());
    memberships.erase(std::unique(memberships.begin(), memberships.end()),
                      memberships.end());
  }

  std::vector<int> predecessorCount(complex.halfedges.size(), 0);
  std::vector<SurfaceCellCanonicalIdentity> successorWedge(
      complex.halfedges.size());
  for (SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    halfedge.next = -1;
    if (halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size())) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(SurfaceArrangementIncidenceFailure::InvalidTwin,
                               halfedge.to, halfedge.id, halfedge.twin, -1);
      continue;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (twin.twin != halfedge.id || twin.from != halfedge.to ||
        twin.to != halfedge.from || halfedge.to < 0 ||
        halfedge.to >= static_cast<int>(orderedWedges.size())) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(SurfaceArrangementIncidenceFailure::InvalidTwin,
                               halfedge.to, halfedge.id, halfedge.twin, -1);
      continue;
    }

    const auto &candidateWedges =
        halfedgeWedges[static_cast<std::size_t>(halfedge.twin)];
    if (candidateWedges.empty()) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::MissingSuccessor, halfedge.to,
          halfedge.id, halfedge.twin, -1);
      continue;
    }
    const SurfaceCellCanonicalIdentity *selectedWedge = nullptr;
    if (candidateWedges.size() == 1U) {
      selectedWedge = &candidateWedges.front();
    } else {
      std::vector<const SurfaceCellCanonicalIdentity *> leftCandidates;
      for (const SurfaceCellCanonicalIdentity &candidate : candidateWedges) {
        const auto wedgeFound =
            orderedWedges[static_cast<std::size_t>(halfedge.to)].find(candidate);
        if (wedgeFound ==
            orderedWedges[static_cast<std::size_t>(halfedge.to)].end()) {
          continue;
        }
        const auto rayFound = std::find_if(
            wedgeFound->second.begin(), wedgeFound->second.end(),
            [&](const DirectedWedgeRay &ray) {
              return ray.halfedge == halfedge.twin;
            });
        if (rayFound == wedgeFound->second.end()) {
          continue;
        }
        bool interiorOnLeft = false;
        for (const DirectedWedgeWitness &witness : rayFound->witnesses) {
          // The witness direction is the outgoing twin, opposite the incoming
          // halfedge. Negating its oriented side score gives the left side of
          // the incoming halfedge whose cell successor is being assigned.
          interiorOnLeft = interiorOnLeft ||
                           (-witness.leftScore > 1.0e-12);
        }
        if (interiorOnLeft) {
          leftCandidates.push_back(&candidate);
        }
      }
      if (leftCandidates.size() == 1U) {
        selectedWedge = leftCandidates.front();
      } else {
        ++complex.diagnostics.successorAmbiguityCount;
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::AmbiguousWedge, halfedge.to,
            halfedge.id, halfedge.twin, -1);
        continue;
      }
    }

    const auto wedgeFound =
        orderedWedges[static_cast<std::size_t>(halfedge.to)].find(
            *selectedWedge);
    if (wedgeFound ==
            orderedWedges[static_cast<std::size_t>(halfedge.to)].end() ||
        wedgeFound->second.empty()) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::MissingSuccessor, halfedge.to,
          halfedge.id, halfedge.twin, -1);
      continue;
    }
    const auto rayFound = std::find_if(
        wedgeFound->second.begin(), wedgeFound->second.end(),
        [&](const DirectedWedgeRay &ray) {
          return ray.halfedge == halfedge.twin;
        });
    if (rayFound == wedgeFound->second.end()) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::MissingSuccessor, halfedge.to,
          halfedge.id, halfedge.twin, -1);
      continue;
    }
    const int position =
        static_cast<int>(std::distance(wedgeFound->second.begin(), rayFound));
    const int predecessor =
        (position - 1 + static_cast<int>(wedgeFound->second.size())) %
        static_cast<int>(wedgeFound->second.size());
    const int next =
        wedgeFound->second[static_cast<std::size_t>(predecessor)].halfedge;
    if (next < 0 || next >= static_cast<int>(complex.halfedges.size()) ||
        complex.halfedges[static_cast<std::size_t>(next)].from != halfedge.to) {
      ++complex.diagnostics.successorMissingCount;
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::EndpointDiscontinuity,
          halfedge.to, halfedge.id, halfedge.twin, next);
      continue;
    }
    halfedge.next = next;
    successorWedge[static_cast<std::size_t>(halfedge.id)] = *selectedWedge;
    ++predecessorCount[static_cast<std::size_t>(next)];
  }

  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.next < 0) {
      continue;
    }
    const int multiplicity =
        predecessorCount[static_cast<std::size_t>(halfedge.id)];
    if (multiplicity != 1) {
      ++complex.diagnostics.predecessorMultiplicityFailureCount;
      record_incidence_failure(
          multiplicity == 0
              ? SurfaceArrangementIncidenceFailure::IncompletePermutation
              : SurfaceArrangementIncidenceFailure::DuplicatePredecessor,
          halfedge.from, halfedge.id, halfedge.twin, halfedge.next);
    }
  }
  const auto canonical_node_identity = [&](const int nodeId) {
    SurfaceCellCanonicalIdentity identity;
    if (nodeId < 0 || nodeId >= static_cast<int>(complex.nodes.size()) ||
        !transitionGraph.available()) {
      return identity;
    }
    std::vector<SurfaceCellCanonicalIdentity> entities;
    const SurfaceArrangementNode &node =
        complex.nodes[static_cast<std::size_t>(nodeId)];
    const auto add_entity = [&](const int face, const int component,
                                const int sheet,
                                const Eigen::RowVector3d &barycentric) {
      SurfacePoint point;
      point.face = face;
      point.component = component;
      point.sheet = sheet;
      point.barycentric = barycentric.transpose();
      const SourceEntityId entity = transitionGraph.resolve_entity(point);
      if (entity.valid() && entity.canonical.valid) {
        entities.push_back(entity.canonical);
      }
    };
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      add_entity(occurrence.sourceFace, occurrence.sourceComponent,
                 occurrence.sourceSheet, occurrence.barycentric);
    }
    add_entity(node.sourceFace, node.sourceComponent, node.sourceSheet,
               node.barycentric);
    std::sort(entities.begin(), entities.end());
    entities.erase(std::unique(entities.begin(), entities.end()), entities.end());
    if (entities.empty()) {
      return identity;
    }
    identity.valid = true;
    identity.values.push_back(static_cast<std::int64_t>(entities.size()));
    for (const SurfaceCellCanonicalIdentity &entity : entities) {
      identity.values.push_back(
          static_cast<std::int64_t>(entity.values.size()));
      identity.values.insert(identity.values.end(), entity.values.begin(),
                             entity.values.end());
    }
    return identity;
  };

  // Hash the complete successor permutation from canonical source entities,
  // not transient node or halfedge ordinals. This keeps diagnostics invariant
  // under source-face row order, traversal starts, and whole-mesh orientation.
  std::vector<std::vector<std::int64_t>> incidenceRecords;
  incidenceRecords.reserve(complex.halfedges.size());
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.next < 0 ||
        halfedge.next >= static_cast<int>(complex.halfedges.size()) ||
        halfedge.id < 0 ||
        halfedge.id >= static_cast<int>(successorWedge.size())) {
      continue;
    }
    const SurfaceCellCanonicalIdentity from =
        canonical_node_identity(halfedge.from);
    const SurfaceCellCanonicalIdentity to =
        canonical_node_identity(halfedge.to);
    const SurfaceArrangementHalfedge &next =
        complex.halfedges[static_cast<std::size_t>(halfedge.next)];
    const SurfaceCellCanonicalIdentity nextTo =
        canonical_node_identity(next.to);
    const SurfaceCellCanonicalIdentity &wedge =
        successorWedge[static_cast<std::size_t>(halfedge.id)];
    if (!from.valid || !to.valid || !nextTo.valid || !wedge.valid) {
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::MissingWedge, halfedge.to,
          halfedge.id, halfedge.twin, halfedge.next);
      continue;
    }
    std::vector<std::int64_t> record;
    const auto append_identity = [&](const SurfaceCellCanonicalIdentity &value) {
      record.push_back(static_cast<std::int64_t>(value.values.size()));
      record.insert(record.end(), value.values.begin(), value.values.end());
    };
    append_identity(wedge);
    append_identity(from);
    append_identity(to);
    append_identity(nextTo);
    record.push_back(halfedge.family);
    record.push_back(halfedge.strand);
    record.push_back(halfedge.hardFeature ? 1 : 0);
    record.push_back(halfedge.railId);
    record.push_back(halfedge.curveId);
    incidenceRecords.push_back(std::move(record));
  }
  std::sort(incidenceRecords.begin(), incidenceRecords.end());
  std::uint64_t directedIncidenceHash = 1469598103934665603ULL;
  const auto mix_incidence = [&](const std::int64_t value) {
    directedIncidenceHash ^= static_cast<std::uint64_t>(value);
    directedIncidenceHash *= 1099511628211ULL;
  };
  mix_incidence(static_cast<std::int64_t>(incidenceRecords.size()));
  for (const std::vector<std::int64_t> &record : incidenceRecords) {
    mix_incidence(static_cast<std::int64_t>(record.size()));
    for (const std::int64_t value : record) {
      mix_incidence(value);
    }
  }
  complex.diagnostics.directedIncidenceHash = directedIncidenceHash;

  std::vector<std::vector<int>> auditedCycles;
  if (directedIncidenceValid) {
    std::vector<unsigned char> visited(complex.halfedges.size(), 0U);
    for (int start = 0; start < static_cast<int>(complex.halfedges.size());
         ++start) {
      if (visited[static_cast<std::size_t>(start)] != 0U) {
        continue;
      }
      std::vector<int> cycle;
      std::set<int> localHalfedges;
      std::set<int> localNodes;
      std::set<std::pair<int, int>> localEdges;
      int current = start;
      bool closed = false;
      for (int guard = 0;
           guard <= static_cast<int>(complex.halfedges.size()); ++guard) {
        if (current < 0 ||
            current >= static_cast<int>(complex.halfedges.size())) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::MissingSuccessor, -1,
              current, -1, -1);
          break;
        }
        if (!localHalfedges.insert(current).second) {
          closed = current == start;
          if (!closed) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::RepeatedHalfedgeCycle,
                complex.halfedges[static_cast<std::size_t>(current)].from,
                current,
                complex.halfedges[static_cast<std::size_t>(current)].twin,
                complex.halfedges[static_cast<std::size_t>(current)].next);
          }
          break;
        }
        const SurfaceArrangementHalfedge &edge =
            complex.halfedges[static_cast<std::size_t>(current)];
        if (!localNodes.insert(edge.from).second) {
          ++complex.diagnostics.repeatedNodeCycleCount;
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::RepeatedNodeCycle,
              edge.from, edge.id, edge.twin, edge.next);
          break;
        }
        const std::pair<int, int> undirected{
            std::min(edge.from, edge.to), std::max(edge.from, edge.to)};
        if (!localEdges.insert(undirected).second) {
          ++complex.diagnostics.repeatedEdgeCycleCount;
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::RepeatedEdgeCycle,
              edge.from, edge.id, edge.twin, edge.next);
          break;
        }
        cycle.push_back(current);
        current = edge.next;
      }
      if (!directedIncidenceValid) {
        break;
      }
      if (!closed || cycle.size() < 3U) {
        record_incidence_failure(
            cycle.size() < 3U ? SurfaceArrangementIncidenceFailure::ShortCycle
                              : SurfaceArrangementIncidenceFailure::IncompletePermutation,
            cycle.empty()
                ? -1
                : complex.halfedges[static_cast<std::size_t>(cycle.front())]
                      .from,
            cycle.empty() ? start : cycle.front(),
            cycle.empty()
                ? -1
                : complex.halfedges[static_cast<std::size_t>(cycle.front())]
                      .twin,
            cycle.empty()
                ? -1
                : complex.halfedges[static_cast<std::size_t>(cycle.back())]
                      .next);
        break;
      }
      for (const int halfedgeId : cycle) {
        visited[static_cast<std::size_t>(halfedgeId)] = 1U;
      }
      auditedCycles.push_back(std::move(cycle));
    }
    if (directedIncidenceValid &&
        std::any_of(visited.begin(), visited.end(),
                    [](const unsigned char value) { return value == 0U; })) {
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::IncompletePermutation, -1, -1,
          -1, -1);
    }
  }

  std::vector<SurfaceArrangementCell> pendingCells;
  if (!directedIncidenceValid) {
    auditedCycles.clear();
  }
  for (const std::vector<int> &cycle : auditedCycles) {
    SurfaceArrangementCell cell;
    cell.id = -1;
    cell.halfedges = cycle;
    cell.closed = true;
    for (const int halfedgeId : cell.halfedges) {
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      if (cell.sourceFace < 0) {
        cell.sourceFace = halfedge.sourceFace;
      }
    }
    std::set<int> uniqueNodes;
    for (const int halfedge : cell.halfedges) {
      uniqueNodes.insert(
          complex.halfedges[static_cast<std::size_t>(halfedge)].from);
    }
    cell.boundaryComponentCount = 1;
    cell.eulerCharacteristic =
        static_cast<int>(uniqueNodes.size()) -
        static_cast<int>(cell.halfedges.size()) + 1;
    cell.disk = uniqueNodes.size() == cell.halfedges.size() &&
                cell.eulerCharacteristic == 1;
    const int boundaryVote = boundary_orientation_vote(
        cell.halfedges, complex.halfedges, complex.nodes, faces, edgeFaces);
    cell.boundaryCycle = cell.closed && boundaryVote < 0;
    if (!polygon_geometry(vertices, faces, cell.halfedges, complex.halfedges,
                          complex.nodes, cell.signedArea, cell.area,
                          cell.sourceFaces)) {
      collect_cell_source_faces(cell.halfedges, complex.halfedges,
                                cell.sourceFaces);
      if (cell.boundaryCycle) {
        // An exterior cycle can wrap a curved open surface and therefore need
        // not admit one non-degenerate global tangent-plane projection. It is
        // excluded from extracted-area accounting; retain only its topological
        // orientation contract here.
        cell.signedArea = -1.0;
        cell.area = 0.0;
      } else {
        embeddingValid = false;
        cell.signedArea = 0.0;
        cell.area = 0.0;
      }
    } else if (boundaryVote != 0) {
      cell.signedArea = boundaryVote < 0 ? -std::abs(cell.area)
                                         : std::abs(cell.area);
      cell.boundaryCycle = boundaryVote < 0;
    } else {
      cell.boundaryCycle = cell.closed && cell.signedArea < 0.0;
    }
    for (int index = 0; index < static_cast<int>(cell.halfedges.size()); ++index) {
      const auto &current =
          complex.halfedges[static_cast<std::size_t>(cell.halfedges[index])];
      bool continuesPrevious = false;
      if (index > 0 && !cell.sideFamilies.empty() &&
          cell.sideFamilies.back() == current.family) {
        const auto &previous = complex.halfedges[static_cast<std::size_t>(
            cell.halfedges[static_cast<std::size_t>(index - 1)])];
        continuesPrevious = same_logical_side(
            previous, current, complex.nodes, vertices, faces);
      }
      if (continuesPrevious) {
        ++cell.sideEdgeCounts.back();
      } else {
        cell.sideFamilies.push_back(current.family);
        cell.sideEdgeCounts.push_back(1);
      }
    }
    if (cell.sideFamilies.size() > 1U &&
        cell.sideFamilies.front() == cell.sideFamilies.back()) {
      const auto &last = complex.halfedges[static_cast<std::size_t>(
          cell.halfedges.back())];
      const auto &first = complex.halfedges[static_cast<std::size_t>(
          cell.halfedges.front())];
      if (same_logical_side(last, first, complex.nodes, vertices, faces)) {
        cell.sideEdgeCounts.front() += cell.sideEdgeCounts.back();
        cell.sideEdgeCounts.pop_back();
        cell.sideFamilies.pop_back();
      }
    }
    if (cell.boundaryCycle) {
      cell.cellClass = SurfaceArrangementCellClass::Exterior;
    } else if (!cell.disk) {
      cell.cellClass = SurfaceArrangementCellClass::NonDisk;
      cell.rejectReason = SurfaceArrangementRejectReason::NotFourSided;
    } else if (cell.area <= 1.0e-14) {
      cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
      cell.rejectReason = SurfaceArrangementRejectReason::Sliver;
    } else {
      const bool crossesHardBarrier = std::any_of(
          cell.halfedges.begin(), cell.halfedges.end(), [&](const int edge) {
            const SurfaceArrangementHalfedge &halfedge =
                complex.halfedges[static_cast<std::size_t>(edge)];
            return complex.nodes[static_cast<std::size_t>(halfedge.from)]
                       .hardBarrierCrossing ||
                   complex.nodes[static_cast<std::size_t>(halfedge.to)]
                       .hardBarrierCrossing;
          });
      if (crossesHardBarrier) {
        cell.rejectReason = SurfaceArrangementRejectReason::HardFeatureCrossing;
      }
      bool alternating = true;
      for (int i = 0; i < static_cast<int>(cell.sideFamilies.size()); ++i) {
        const int a = cell.sideFamilies[static_cast<std::size_t>(i)];
        const int b =
            cell.sideFamilies[static_cast<std::size_t>((i + 1) % cell.sideFamilies.size())];
        if (a >= 0 && b >= 0 && a == b) {
          alternating = false;
        }
      }
      const int boundaryCount = std::accumulate(cell.sideEdgeCounts.begin(),
                                                cell.sideEdgeCounts.end(), 0);
      if (cell.sideFamilies.size() == 4 && alternating &&
          cell.rejectReason != SurfaceArrangementRejectReason::HardFeatureCrossing) {
        cell.quadReady = true;
        cell.cellClass = SurfaceArrangementCellClass::RegularQuad;
      } else {
        cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
        if (cell.rejectReason != SurfaceArrangementRejectReason::HardFeatureCrossing) {
          cell.rejectReason = !alternating
                                  ? SurfaceArrangementRejectReason::NonAlternatingFamilies
                                  : (boundaryCount % 2 != 0
                                         ? SurfaceArrangementRejectReason::OddBoundaryParity
                                         : SurfaceArrangementRejectReason::NotFourSided);
        }
      }
    }
    pendingCells.push_back(std::move(cell));
  }

  // Cells are classified before ids are committed. Canonicalize the cycle
  // inventory by its embedded undirected edge set so source-face row order and
  // traversal start cannot change cell ordinals.
  const auto cell_cycle_key = [&](const SurfaceArrangementCell &cell) {
    using CanonicalEdge =
        std::pair<SurfaceCellCanonicalIdentity, SurfaceCellCanonicalIdentity>;
    std::vector<CanonicalEdge> edges;
    edges.reserve(cell.halfedges.size());
    for (const int halfedgeId : cell.halfedges) {
      const SurfaceArrangementHalfedge &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      SurfaceCellCanonicalIdentity first =
          canonical_node_identity(halfedge.from);
      SurfaceCellCanonicalIdentity second =
          canonical_node_identity(halfedge.to);
      if (second < first) {
        std::swap(first, second);
      }
      edges.emplace_back(std::move(first), std::move(second));
    }
    std::sort(edges.begin(), edges.end());
    std::vector<std::array<int, 3>> sourceFaces;
    sourceFaces.reserve(cell.sourceFaces.size());
    for (const int face : cell.sourceFaces) {
      if (face >= 0 && face < faces.rows()) {
        sourceFaces.push_back(face_signature(face));
      }
    }
    std::sort(sourceFaces.begin(), sourceFaces.end());
    sourceFaces.erase(std::unique(sourceFaces.begin(), sourceFaces.end()),
                      sourceFaces.end());
    return std::make_tuple(cell.boundaryCycle ? 1 : 0, sourceFaces, edges,
                           cell.halfedges.size());
  };
  std::sort(pendingCells.begin(), pendingCells.end(),
            [&](const SurfaceArrangementCell &lhs,
                const SurfaceArrangementCell &rhs) {
              return cell_cycle_key(lhs) < cell_cycle_key(rhs);
            });
  complex.cells.clear();
  complex.cells.reserve(pendingCells.size());
  for (SurfaceArrangementCell &cell : pendingCells) {
    cell.id = static_cast<int>(complex.cells.size());
    for (const int halfedgeId : cell.halfedges) {
      complex.halfedges[static_cast<std::size_t>(halfedgeId)].cell = cell.id;
    }
    complex.cells.push_back(std::move(cell));
  }

  // Build intrinsic equivalence classes for per-face local source charts.
  // Local sheet integers are chart-local labels: adjacent source faces can use
  // different values while still representing one physical cell side. Charts
  // are joined only when the already-stitched DCEL contains the same intrinsic
  // node occurrence on both source faces. Same-face labels are never joined,
  // which keeps close/opposing sheets distinct.
  using SourceChart = SurfaceCellSourceChart;
  std::set<SourceChart> allCharts;
  const auto addChart = [&](const int component, const int face,
                            const int sheet) {
    const SourceChart chart{component, face, sheet};
    if (chart.valid()) {
      allCharts.insert(chart);
    }
  };
  if (resolvedOptions.sourceFaceComponents != nullptr &&
      resolvedOptions.sourceFaceSheets != nullptr &&
      resolvedOptions.sourceFaceComponents->size() == resolvedOptions.sourceFaceSheets->size()) {
    for (int face = 0;
         face < static_cast<int>(resolvedOptions.sourceFaceComponents->size()); ++face) {
      addChart((*resolvedOptions.sourceFaceComponents)[static_cast<std::size_t>(face)],
               face,
               (*resolvedOptions.sourceFaceSheets)[static_cast<std::size_t>(face)]);
    }
  }
  for (const SurfaceArrangementNode &node : complex.nodes) {
    addChart(node.sourceComponent, node.sourceFace, node.sourceSheet);
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      addChart(occurrence.sourceComponent, occurrence.sourceFace,
               occurrence.sourceSheet);
    }
  }
  for (const SurfaceArrangementHalfedge &edge : complex.halfedges) {
    addChart(edge.sourceComponent, edge.sourceFace, edge.sourceSheet);
    for (const SurfaceArrangementProvenance &entry : edge.provenance) {
      addChart(entry.sourceComponent, entry.sourceFace, entry.sourceSheet);
    }
  }

  std::vector<SourceChart> chartList(allCharts.begin(), allCharts.end());
  std::map<SourceChart, int> chartIndex;
  for (int index = 0; index < static_cast<int>(chartList.size()); ++index) {
    chartIndex.emplace(chartList[static_cast<std::size_t>(index)], index);
  }
  std::vector<int> chartParent(chartList.size());
  std::iota(chartParent.begin(), chartParent.end(), 0);
  const auto findChart = [&](int index) {
    int root = index;
    while (chartParent[static_cast<std::size_t>(root)] != root) {
      root = chartParent[static_cast<std::size_t>(root)];
    }
    while (chartParent[static_cast<std::size_t>(index)] != index) {
      const int next = chartParent[static_cast<std::size_t>(index)];
      chartParent[static_cast<std::size_t>(index)] = root;
      index = next;
    }
    return root;
  };
  const auto unionCharts = [&](const SourceChart &a, const SourceChart &b) {
    const auto foundA = chartIndex.find(a);
    const auto foundB = chartIndex.find(b);
    if (foundA == chartIndex.end() || foundB == chartIndex.end() ||
        a.sourceComponent != b.sourceComponent ||
        a.sourceFace == b.sourceFace) {
      return;
    }
    const int rootA = findChart(foundA->second);
    const int rootB = findChart(foundB->second);
    if (rootA == rootB) {
      return;
    }
    const SourceChart &keyA = chartList[static_cast<std::size_t>(rootA)];
    const SourceChart &keyB = chartList[static_cast<std::size_t>(rootB)];
    if (keyB < keyA) {
      chartParent[static_cast<std::size_t>(rootA)] = rootB;
    } else {
      chartParent[static_cast<std::size_t>(rootB)] = rootA;
    }
  };
  if (!transitionGraph.available()) {
    embeddingValid = false;
  } else {
    // Ownership equivalence is derived from exact source incidence before
    // output-cell ownership is assigned.  A stitched node occurrence is
    // evidence that charts meet geometrically, but it is not authority to
    // cross a hard rail, nonmanifold sector, disconnected component, or
    // intrinsic vertex-fan boundary.
    std::map<int, SourceChart> representativeByTransitionComponent;
    for (const SourceChart &chart : chartList) {
      const int component = transitionGraph.chart_component(SourceChartId{
          chart.sourceComponent, chart.localSheet, chart.sourceFace});
      if (component < 0) {
        embeddingValid = false;
        continue;
      }
      const auto [found, inserted] =
          representativeByTransitionComponent.emplace(component, chart);
      if (!inserted) {
        unionCharts(found->second, chart);
      }
    }
  }
  const auto chartRoot = [&](const SourceChart &chart) {
    const auto found = chartIndex.find(chart);
    return found == chartIndex.end() ? -1 : findChart(found->second);
  };
  struct OwnershipBuildRecord {
    int root = -1;
    SurfaceCellOwnershipClassRecord record;
  };
  std::map<int, std::vector<SourceChart>> chartsByRoot;
  for (int index = 0; index < static_cast<int>(chartList.size()); ++index) {
    chartsByRoot[findChart(index)].push_back(
        chartList[static_cast<std::size_t>(index)]);
  }
  std::vector<OwnershipBuildRecord> ownershipRecords;
  ownershipRecords.reserve(chartsByRoot.size());
  for (auto &[root, charts] : chartsByRoot) {
    std::sort(charts.begin(), charts.end());
    charts.erase(std::unique(charts.begin(), charts.end()), charts.end());
    if (charts.empty()) {
      continue;
    }
    SurfaceCellOwnershipClassRecord record;
    record.sourceComponent = charts.front().sourceComponent;
    record.exactCharts = charts;
    std::vector<std::array<std::int64_t, 5>> members;
    members.reserve(charts.size());
    bool valid = true;
    for (const SourceChart &chart : charts) {
      if (chart.sourceComponent != record.sourceComponent ||
          chart.sourceFace < 0 || chart.sourceFace >= faces.rows()) {
        valid = false;
        break;
      }
      std::array<int, 3> vertices{{faces(chart.sourceFace, 0),
                                   faces(chart.sourceFace, 1),
                                   faces(chart.sourceFace, 2)}};
      std::sort(vertices.begin(), vertices.end());
      members.push_back({chart.sourceComponent, chart.localSheet, vertices[0],
                         vertices[1], vertices[2]});
    }
    if (!valid) {
      continue;
    }
    std::sort(members.begin(), members.end());
    members.erase(std::unique(members.begin(), members.end()), members.end());
    record.canonicalMembership.valid = !members.empty();
    record.canonicalMembership.values.push_back(
        static_cast<std::int64_t>(members.size()));
    for (const auto &member : members) {
      record.canonicalMembership.values.insert(
          record.canonicalMembership.values.end(), member.begin(),
          member.end());
    }
    if (record.valid()) {
      ownershipRecords.push_back({root, std::move(record)});
    }
  }
  std::sort(ownershipRecords.begin(), ownershipRecords.end(),
            [](const OwnershipBuildRecord &lhs,
               const OwnershipBuildRecord &rhs) {
              return lhs.record < rhs.record;
            });
  std::map<int, int> ownershipOrdinalByRoot;
  complex.sourceOwnershipRegistry.clear();
  complex.sourceOwnershipRegistry.reserve(ownershipRecords.size());
  for (const OwnershipBuildRecord &build : ownershipRecords) {
    const int ordinal =
        static_cast<int>(complex.sourceOwnershipRegistry.size());
    ownershipOrdinalByRoot.emplace(build.root, ordinal);
    complex.sourceOwnershipRegistry.push_back(build.record);
  }
  const auto ownershipIdentity = [&](const int root) {
    const auto found = ownershipOrdinalByRoot.find(root);
    if (found == ownershipOrdinalByRoot.end()) {
      return SurfaceCellCanonicalIdentity{};
    }
    const SurfaceCellOwnershipClassRecord &record =
        complex.sourceOwnershipRegistry[static_cast<std::size_t>(found->second)];
    return make_surface_cell_ownership_key(record.sourceComponent,
                                           found->second);
  };

  for (SurfaceArrangementCell &cell : complex.cells) {
    const std::set<int> cellFaces(cell.sourceFaces.begin(),
                                  cell.sourceFaces.end());
    std::set<int> sharedRoots;
    bool firstBoundary = true;
    for (const int halfedgeId : cell.halfedges) {
      const SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      std::vector<const SurfaceArrangementProvenance *> ownershipEntries;
      for (const SurfaceArrangementProvenance &entry : edge.provenance) {
        const SourceChart chart{entry.sourceComponent, entry.sourceFace,
                                entry.sourceSheet};
        if (!chart.valid() ||
            (!cellFaces.empty() && cellFaces.count(entry.sourceFace) == 0U)) {
          continue;
        }
        ownershipEntries.push_back(&entry);
      }
      const bool hasNonRail = std::any_of(
          ownershipEntries.begin(), ownershipEntries.end(),
          [](const SurfaceArrangementProvenance *entry) {
            return entry->railId < 0;
          });
      std::set<int> edgeRoots;
      for (const SurfaceArrangementProvenance *entry : ownershipEntries) {
        if (hasNonRail && entry->railId >= 0) {
          continue;
        }
        const int root = chartRoot({entry->sourceComponent, entry->sourceFace,
                                    entry->sourceSheet});
        if (root >= 0) {
          edgeRoots.insert(root);
        }
      }
      if (edgeRoots.empty()) {
        const int root = chartRoot(
            {edge.sourceComponent, edge.sourceFace, edge.sourceSheet});
        if (root >= 0) {
          edgeRoots.insert(root);
        }
      }
      if (firstBoundary) {
        sharedRoots = std::move(edgeRoots);
        firstBoundary = false;
      } else {
        std::set<int> intersection;
        std::set_intersection(sharedRoots.begin(), sharedRoots.end(),
                              edgeRoots.begin(), edgeRoots.end(),
                              std::inserter(intersection, intersection.end()));
        sharedRoots = std::move(intersection);
      }
    }

    // Source-face labels are authoritative when every supported face belongs
    // to one proven intrinsic class. Otherwise use the exact boundary-class
    // intersection above. Neither path chooses a class by frequency or order.
    std::set<int> faceRoots;
    if (resolvedOptions.sourceFaceComponents != nullptr &&
        resolvedOptions.sourceFaceSheets != nullptr) {
      for (const int face : cell.sourceFaces) {
        if (face < 0 ||
            face >= static_cast<int>(resolvedOptions.sourceFaceComponents->size()) ||
            face >= static_cast<int>(resolvedOptions.sourceFaceSheets->size())) {
          faceRoots.clear();
          break;
        }
        const int root = chartRoot(
            {(*resolvedOptions.sourceFaceComponents)[static_cast<std::size_t>(face)],
             face,
             (*resolvedOptions.sourceFaceSheets)[static_cast<std::size_t>(face)]});
        if (root < 0) {
          faceRoots.clear();
          break;
        }
        faceRoots.insert(root);
      }
    }
    const int selectedRoot = faceRoots.size() == 1U
                                 ? *faceRoots.begin()
                                 : (sharedRoots.size() == 1U
                                        ? *sharedRoots.begin()
                                        : -1);
    if (selectedRoot < 0) {
      embeddingValid = false;
      continue;
    }
    cell.sourceOwnershipClass = ownershipIdentity(selectedRoot);
    if (!cell.sourceOwnershipClass.valid) {
      embeddingValid = false;
      continue;
    }

    std::set<int> selectedFaces;
    std::set<SourceChart> selectedCharts;
    for (const int halfedgeId : cell.halfedges) {
      SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      std::vector<const SurfaceArrangementProvenance *> compatible;
      for (const SurfaceArrangementProvenance &entry : edge.provenance) {
        const SourceChart chart{entry.sourceComponent, entry.sourceFace,
                                entry.sourceSheet};
        if (chartRoot(chart) == selectedRoot &&
            (cellFaces.empty() || cellFaces.count(entry.sourceFace) != 0U)) {
          compatible.push_back(&entry);
        }
      }
      if (compatible.empty()) {
        for (const SurfaceArrangementProvenance &entry : edge.provenance) {
          const SourceChart chart{entry.sourceComponent, entry.sourceFace,
                                  entry.sourceSheet};
          if (chartRoot(chart) == selectedRoot) {
            compatible.push_back(&entry);
          }
        }
      }
      if (compatible.empty()) {
        embeddingValid = false;
        continue;
      }
      const auto key = [&](const SurfaceArrangementProvenance *value) {
        return std::make_tuple(
            value->railId >= 0 ? 1 : 0,
            cellFaces.count(value->sourceFace) != 0U ? 0 : 1,
            value->sourceFace, value->sourceComponent, value->sourceSheet,
            value->sourceArc, value->provenance, value->family, value->strand,
            value->featureClass, value->railId, value->curveId,
            static_cast<std::int64_t>(
                std::llround(value->sourceT0 * 1.0e10)),
            static_cast<std::int64_t>(
                std::llround(value->sourceT1 * 1.0e10)));
      };
      const SurfaceArrangementProvenance &primary = **std::min_element(
          compatible.begin(), compatible.end(),
          [&](const auto *lhs, const auto *rhs) { return key(lhs) < key(rhs); });
      const auto railEntry = std::min_element(
          edge.provenance.begin(), edge.provenance.end(),
          [](const SurfaceArrangementProvenance &lhs,
             const SurfaceArrangementProvenance &rhs) {
            const auto railKey = [](const SurfaceArrangementProvenance &value) {
              return std::make_tuple(
                  value.railId >= 0 ? 0 : 1,
                  value.hardFeature ? 0 : 1, value.railId, value.curveId,
                  value.sourceArc, value.sourceFace,
                  static_cast<std::int64_t>(
                      std::llround(value.railT0 * 1.0e10)),
                  static_cast<std::int64_t>(
                      std::llround(value.railT1 * 1.0e10)));
            };
            return railKey(lhs) < railKey(rhs);
          });
      const SurfaceArrangementProvenance *authoritativeRail =
          railEntry != edge.provenance.end() && railEntry->railId >= 0
              ? &*railEntry
              : nullptr;
      edge.sourceArc = primary.sourceArc;
      edge.family = primary.family;
      edge.strand = primary.strand;
      edge.featureClass = authoritativeRail != nullptr
                              ? authoritativeRail->featureClass
                              : primary.featureClass;
      edge.sourceFace = primary.sourceFace;
      edge.sourceComponent = primary.sourceComponent;
      edge.sourceSheet = primary.sourceSheet;
      edge.sourceT0 = primary.sourceT0;
      edge.sourceT1 = primary.sourceT1;
      edge.hardFeature = edge.hardFeature || primary.hardFeature;
      edge.layoutSupport = edge.layoutSupport || primary.layoutSupport;
      edge.singularitySupport =
          edge.singularitySupport || primary.singularitySupport;
      edge.railId = authoritativeRail != nullptr ? authoritativeRail->railId
                                                 : primary.railId;
      edge.curveId = authoritativeRail != nullptr ? authoritativeRail->curveId
                                                  : primary.curveId;
      edge.proposalId = primary.proposalId;
      edge.proposalSeedId = primary.proposalSeedId;
      edge.proposalSide = primary.proposalSide;
      edge.proposalBoundarySegment = primary.proposalBoundarySegment;
      edge.railT0 = authoritativeRail != nullptr ? authoritativeRail->railT0
                                                 : primary.railT0;
      edge.railT1 = authoritativeRail != nullptr ? authoritativeRail->railT1
                                                 : primary.railT1;
      selectedFaces.insert(edge.sourceFace);
      selectedCharts.insert(
          {edge.sourceComponent, edge.sourceFace, edge.sourceSheet});

      const auto ensureOccurrence = [&](const int nodeId,
                                        const double sourceParameter,
                                        const double railParameter) {
        if (nodeId < 0 || nodeId >= static_cast<int>(complex.nodes.size())) {
          return false;
        }
        SurfaceArrangementNode &node =
            complex.nodes[static_cast<std::size_t>(nodeId)];
        const auto existing = std::find_if(
            node.occurrences.begin(), node.occurrences.end(),
            [&](const SurfaceArrangementNodeOccurrence &occurrence) {
              return occurrence.sourceFace == edge.sourceFace &&
                     occurrence.sourceComponent == edge.sourceComponent &&
                     occurrence.sourceSheet == edge.sourceSheet;
            });
        if (existing != node.occurrences.end()) {
          return true;
        }
        Eigen::RowVector3d barycentric =
            node_barycentric_on_face(node, edge.sourceFace);
        if (!barycentric.allFinite()) {
          const auto tryRebind = [&](const int sourceFace,
                                     const int sourceComponent,
                                     const int sourceSheet,
                                     const Eigen::RowVector3d &sourceBarycentric) {
            SurfacePoint sourcePoint;
            sourcePoint.face = sourceFace;
            sourcePoint.component = sourceComponent;
            sourcePoint.sheet = sourceSheet;
            sourcePoint.barycentric = sourceBarycentric.transpose();
            SurfacePoint rebound;
            if (!transitionGraph.rebind(sourcePoint, edge.sourceFace,
                                        rebound)) {
              return false;
            }
            barycentric = rebound.barycentric.transpose();
            return barycentric.allFinite();
          };
          bool rebound = false;
          for (const SurfaceArrangementNodeOccurrence &candidate :
               node.occurrences) {
            if (tryRebind(candidate.sourceFace, candidate.sourceComponent,
                          candidate.sourceSheet, candidate.barycentric)) {
              rebound = true;
              break;
            }
          }
          if (!rebound) {
            rebound = tryRebind(node.sourceFace, node.sourceComponent,
                                node.sourceSheet, node.barycentric);
          }
          if (!rebound) {
            return false;
          }
        }
        SurfaceArrangementNodeOccurrence occurrence;
        occurrence.sourceFace = edge.sourceFace;
        occurrence.barycentric = barycentric;
        occurrence.sourceComponent = edge.sourceComponent;
        occurrence.sourceSheet = edge.sourceSheet;
        occurrence.sourceArc = edge.sourceArc;
        occurrence.provenance = primary.provenance;
        occurrence.railId = edge.railId;
        occurrence.curveId = edge.curveId;
        occurrence.sourceT0 = sourceParameter;
        occurrence.sourceT1 = sourceParameter;
        occurrence.railT0 = railParameter;
        occurrence.railT1 = railParameter;
        node.occurrences.push_back(std::move(occurrence));
        return true;
      };
      if (!ensureOccurrence(edge.from, edge.sourceT0, edge.railT0) ||
          !ensureOccurrence(edge.to, edge.sourceT1, edge.railT1)) {
        embeddingValid = false;
      }
    }
    cell.sourceCharts.assign(selectedCharts.begin(), selectedCharts.end());
    if (cell.sourceCharts.empty()) {
      embeddingValid = false;
      continue;
    }
    cell.sourceComponent = cell.sourceCharts.front().sourceComponent;
    cell.sourceSheet = cell.sourceCharts.front().localSheet;
    cell.sourceFaces.assign(selectedFaces.begin(), selectedFaces.end());
    cell.sourceFace = cell.sourceFaces.empty() ? -1 : cell.sourceFaces.front();
  }

  // A DCEL walk yields one oriented cycle at a time.  A bounded region may
  // nevertheless have nested, oppositely oriented cycles (holes).  Detect
  // those components explicitly so annular and multiply connected cells are
  // not silently reported as disks.
  std::vector<std::vector<Eigen::Vector2d>> cellPolygons(complex.cells.size());
  for (const SurfaceArrangementCell &cell : complex.cells) {
    auto &polygon = cellPolygons[static_cast<std::size_t>(cell.id)];
    if (cell.sourceFaces.size() != 1U) {
      continue;
    }
    const int polygonFace = cell.sourceFaces.front();
    polygon.reserve(cell.halfedges.size());
    for (const int halfedgeId : cell.halfedges) {
      const SurfaceArrangementHalfedge &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      const Eigen::RowVector3d barycentric = node_barycentric_on_face(
          complex.nodes[static_cast<std::size_t>(halfedge.from)], polygonFace);
      if (!barycentric.allFinite()) {
        polygon.clear();
        break;
      }
      polygon.push_back(bary_to_uv(barycentric));
    }
  }
  for (SurfaceArrangementCell &cell : complex.cells) {
    // The nesting pass may only disprove a disk. It must never erase the
    // repeated-node/self-touch evidence established by the DCEL incidence
    // walk above. The previous assignment of `disk` from boundary count alone
    // accidentally made pinched cycles topologically valid while leaving
    // their stale NonDisk class behind.
    if (cell.boundaryCycle || !cell.disk || !cell.closed ||
        cell.area <= 1.0e-14) {
      continue;
    }
    int nestedBoundaryCount = 0;
    const auto &outer = cellPolygons[static_cast<std::size_t>(cell.id)];
    for (const SurfaceArrangementCell &candidate : complex.cells) {
      if (!candidate.boundaryCycle || !candidate.closed ||
          cell.sourceFaces.size() != 1U ||
          candidate.sourceFaces != cell.sourceFaces || outer.empty() ||
          candidate.area >= cell.area - 1.0e-14) {
        continue;
      }
      const auto &hole =
          cellPolygons[static_cast<std::size_t>(candidate.id)];
      if (hole.empty()) {
        continue;
      }
      Eigen::Vector2d centroid = Eigen::Vector2d::Zero();
      for (const Eigen::Vector2d &point : hole) {
        centroid += point;
      }
      centroid /= static_cast<double>(std::max<std::size_t>(1U, hole.size()));
      if (point_in_polygon(centroid, outer)) {
        ++nestedBoundaryCount;
      }
    }
    if (nestedBoundaryCount > 0) {
      cell.boundaryComponentCount = 1 + nestedBoundaryCount;
      cell.eulerCharacteristic = 2 - cell.boundaryComponentCount;
      cell.disk = false;
      cell.quadReady = false;
      cell.cellClass = SurfaceArrangementCellClass::NonDisk;
      cell.rejectReason = SurfaceArrangementRejectReason::NotFourSided;
    }
  }
  update_peak_memory(vector_storage_bytes(segments) + split_storage_bytes() +
                     vector_storage_bytes(cellPolygons));

  for (int i = 0; i < static_cast<int>(segments.size()); ++i) {
    const Segment2 &a = segments[static_cast<std::size_t>(i)];
    for (int j = i + 1; j < static_cast<int>(segments.size()); ++j) {
      const Segment2 &b = segments[static_cast<std::size_t>(j)];
      if (a.sourceFace != b.sourceFace) {
        continue;
      }
      if (!same_segment_scope(a, b)) {
        continue;
      }
      double ta = 0.0;
      double tb = 0.0;
      Eigen::Vector2d p;
      if (segment_intersection_params(a, b, ta, tb, p) && ta > 1.0e-8 &&
          ta < 1.0 - 1.0e-8 && tb > 1.0e-8 && tb < 1.0 - 1.0e-8) {
        const ScopedNodeKey key =
            make_scoped_node_key(faces, a, p, vertexFanScopes);
        if (nodeByKey.count(key) == 0) {
          ++complex.diagnostics.unsplitCrossings;
        }
      }
    }
  }
  for (const SurfaceArrangementNode &node : complex.nodes) {
    bool foundTJunction = false;
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      const Eigen::Vector2d point = bary_to_uv(occurrence.barycentric);
      for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
        if (halfedge.sourceFace != occurrence.sourceFace ||
            halfedge.from == node.id || halfedge.to == node.id) {
          continue;
        }
        Segment2 scopeSegment;
        scopeSegment.sourceFace = occurrence.sourceFace;
        scopeSegment.sourceComponent = halfedge.sourceComponent;
        scopeSegment.sourceSheet = halfedge.sourceSheet;
        const ScopedNodeKey candidateScope = make_scoped_node_key(
            faces, scopeSegment, point, vertexFanScopes);
        const std::pair<int, int> expectedScope =
            nodeScopes[static_cast<std::size_t>(node.id)];
        if (std::get<1>(candidateScope) != expectedScope.first ||
            std::get<2>(candidateScope) != expectedScope.second) {
          continue;
        }
        const Eigen::RowVector3d startBarycentric = node_barycentric_on_face(
            complex.nodes[static_cast<std::size_t>(halfedge.from)],
            occurrence.sourceFace);
        const Eigen::RowVector3d endBarycentric = node_barycentric_on_face(
            complex.nodes[static_cast<std::size_t>(halfedge.to)],
            occurrence.sourceFace);
        if (!startBarycentric.allFinite() || !endBarycentric.allFinite()) {
          continue;
        }
        Segment2 split;
        split.sourceFace = occurrence.sourceFace;
        split.start = bary_to_uv(startBarycentric);
        split.end = bary_to_uv(endBarycentric);
        if (point_on_segment(point, split)) {
          ++complex.diagnostics.geometricTJunctions;
          foundTJunction = true;
          break;
        }
      }
      if (foundTJunction) {
        break;
      }
    }
  }

  std::map<int, double> coveredByArc;
  for (const SurfaceArrangementHalfedge &h : complex.halfedges) {
    if (h.id >= h.twin) {
      continue;
    }
    for (const SurfaceArrangementProvenance &value : h.provenance) {
      if (value.sourceArc >= 0) {
        coveredByArc[value.sourceArc] +=
            std::abs(value.sourceT1 - value.sourceT0);
      }
    }
  }
  for (const SurfaceArrangementArc &arc : inputArcs) {
    if (coveredByArc[arc.id] < 1.0 - 1.0e-8) {
      ++complex.diagnostics.incompleteArcChains;
    }
  }
  complex.diagnostics.supportedArea = 0.0;
  for (int face = 0; face < faces.rows(); ++face) {
    complex.diagnostics.supportedArea += triangle_area_3d(vertices, faces, face);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.boundaryCycle) {
      complex.diagnostics.extractedArea += cell.area;
    }
  }
  complex.diagnostics.relativeAreaError =
      std::abs(complex.diagnostics.extractedArea -
               complex.diagnostics.supportedArea) /
      std::max(1.0e-20, complex.diagnostics.supportedArea);
  const int undirectedEdges = static_cast<int>(complex.halfedges.size()) / 2;
  const int interiorCells = static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(),
      [](const SurfaceArrangementCell &cell) { return !cell.boundaryCycle; }));
  complex.diagnostics.eulerCharacteristic =
      static_cast<int>(complex.nodes.size()) - undirectedEdges + interiorCells;

  std::vector<std::pair<int, int>> arrangementEdges;
  arrangementEdges.reserve(static_cast<std::size_t>(undirectedEdges));
  std::vector<std::pair<int, int>> arrangementBoundaryEdges;
  bool incidenceValid = directedIncidenceValid;
  bool orientationValid = true;
  bool cellsDiskValid = true;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id < 0 || halfedge.id >= static_cast<int>(complex.halfedges.size()) ||
        halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size()) ||
        halfedge.next < 0 ||
        halfedge.next >= static_cast<int>(complex.halfedges.size()) ||
        halfedge.from < 0 ||
        halfedge.from >= static_cast<int>(complex.nodes.size()) ||
        halfedge.to < 0 ||
        halfedge.to >= static_cast<int>(complex.nodes.size()) ||
        halfedge.cell < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size())) {
      incidenceValid = false;
      continue;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (twin.twin != halfedge.id || twin.from != halfedge.to ||
        twin.to != halfedge.from) {
      incidenceValid = false;
    }
    const SurfaceArrangementHalfedge &next =
        complex.halfedges[static_cast<std::size_t>(halfedge.next)];
    if (next.from != halfedge.to) {
      incidenceValid = false;
    }
    if (halfedge.id < halfedge.twin) {
      arrangementEdges.emplace_back(halfedge.from, halfedge.to);
      const bool leftExterior =
          complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle;
      const bool rightExterior =
          complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle;
      if (leftExterior != rightExterior) {
        arrangementBoundaryEdges.emplace_back(halfedge.from, halfedge.to);
      }
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.closed || cell.halfedges.size() < 3U) {
      incidenceValid = false;
    }
    if (cell.boundaryCycle ? !(cell.signedArea < -1.0e-14)
                           : !(cell.signedArea > 1.0e-14)) {
      if (cell.rejectReason != SurfaceArrangementRejectReason::Sliver) {
        orientationValid = false;
      }
    }
    if (!cell.boundaryCycle && !cell.disk) {
      cellsDiskValid = false;
    }
    for (const int halfedgeId : cell.halfedges) {
      if (halfedgeId < 0 ||
          halfedgeId >= static_cast<int>(complex.halfedges.size()) ||
          complex.halfedges[static_cast<std::size_t>(halfedgeId)].cell !=
              cell.id) {
        incidenceValid = false;
      }
    }
  }
  complex.diagnostics.incidenceValid = incidenceValid;
  embeddingValid = embeddingValid &&
                   validate_surface_cell_ownership_registry(complex);
  complex.diagnostics.embeddingValid = embeddingValid;
  complex.diagnostics.orientationValid = orientationValid;
  complex.diagnostics.cellsDiskValid = cellsDiskValid;
  complex.diagnostics.connectedComponentCount = graph_component_count(
      static_cast<int>(complex.nodes.size()), arrangementEdges);
  const auto [boundaryLoops, boundaryValid] = boundary_loop_count(
      static_cast<int>(complex.nodes.size()), arrangementBoundaryEdges);
  complex.diagnostics.boundaryLoopCount = boundaryLoops;
  complex.diagnostics.boundaryLoopsValid = boundaryValid;

  std::set<std::uint64_t> sourceEdges;
  std::vector<std::pair<int, int>> sourceGraphEdges;
  std::vector<std::pair<int, int>> sourceBoundaryEdges;
  std::vector<unsigned char> sourceVertexUsed(
      static_cast<std::size_t>(vertices.rows()), 0);
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      sourceVertexUsed[static_cast<std::size_t>(faces(face, corner))] = 1;
    }
    for (int edge = 0; edge < 3; ++edge) {
      const std::uint64_t key = source_edge_key(faces, face, edge);
      if (sourceEdges.insert(key).second) {
        const int a = faces(face, (edge + 1) % 3);
        const int b = faces(face, (edge + 2) % 3);
        sourceGraphEdges.emplace_back(a, b);
        const auto found = edgeFaces.find(key);
        if (found == edgeFaces.end() || found->second[1] < 0) {
          sourceBoundaryEdges.emplace_back(a, b);
        }
      }
    }
  }
  const int sourceVertexCount = static_cast<int>(std::count(
      sourceVertexUsed.begin(), sourceVertexUsed.end(),
      static_cast<unsigned char>(1)));
  complex.diagnostics.sourceEulerCharacteristic =
      sourceVertexCount - static_cast<int>(sourceEdges.size()) + faces.rows();
  complex.diagnostics.sourceConnectedComponentCount = graph_component_count(
      static_cast<int>(vertices.rows()), sourceGraphEdges, &sourceVertexUsed);
  const auto [sourceBoundaryLoops, sourceBoundaryValid] = boundary_loop_count(
      static_cast<int>(vertices.rows()), sourceBoundaryEdges);
  complex.diagnostics.sourceBoundaryLoopCount = sourceBoundaryLoops;
  complex.diagnostics.eulerCharacteristicValid =
      complex.diagnostics.eulerCharacteristic ==
          complex.diagnostics.sourceEulerCharacteristic &&
      complex.diagnostics.connectedComponentCount ==
          complex.diagnostics.sourceConnectedComponentCount &&
      boundaryValid && sourceBoundaryValid &&
      complex.diagnostics.boundaryLoopCount ==
          complex.diagnostics.sourceBoundaryLoopCount;
  complex.diagnostics.topologyValid =
      complex.diagnostics.incidenceValid &&
      complex.diagnostics.embeddingValid &&
      complex.diagnostics.orientationValid &&
      complex.diagnostics.cellsDiskValid &&
      complex.diagnostics.boundaryLoopsValid &&
      complex.diagnostics.eulerCharacteristicValid &&
      complex.diagnostics.unsplitCrossings == 0 &&
      complex.diagnostics.geometricTJunctions == 0;

  complex.diagnostics.inputMemoryBytes =
      static_cast<std::uint64_t>(vertices.size()) * sizeof(double) +
      static_cast<std::uint64_t>(faces.size()) * sizeof(int) +
      static_cast<std::uint64_t>(inputArcs.capacity()) *
          sizeof(SurfaceArrangementArc);
  complex.diagnostics.retainedMemoryBytes = complex_storage_bytes(complex);
  update_peak_memory(vector_storage_bytes(segments) + split_storage_bytes());
  complex.diagnostics.peakMemoryBytes = std::max(
      peakOwnedBytes, complex.diagnostics.retainedMemoryBytes);
  complex.diagnostics.measuredMemoryRatio =
      static_cast<double>(complex.diagnostics.peakMemoryBytes) /
      static_cast<double>(std::max<std::uint64_t>(
          1U, complex.diagnostics.inputMemoryBytes));
  complex.diagnostics.memoryRatioEstimate =
      complex.diagnostics.measuredMemoryRatio;
  return complex;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceArrangementOverlay
make_surface_arrangement_overlay(const SurfaceCellComplex &complex) {
  SurfaceArrangementOverlay overlay;
  const int edgeCount = static_cast<int>(complex.halfedges.size());
  overlay.splitSegmentStarts.resize(edgeCount, 3);
  overlay.splitSegmentEnds.resize(edgeCount, 3);
  overlay.sideFamily.resize(edgeCount);
  overlay.cellId.resize(edgeCount);
  overlay.hardRailCrossing.resize(edgeCount);
  for (int i = 0; i < edgeCount; ++i) {
    const SurfaceArrangementHalfedge &h = complex.halfedges[static_cast<std::size_t>(i)];
    overlay.splitSegmentStarts.row(i) =
        complex.nodes[static_cast<std::size_t>(h.from)].barycentric;
    overlay.splitSegmentEnds.row(i) =
        complex.nodes[static_cast<std::size_t>(h.to)].barycentric;
    overlay.sideFamily(i) = h.family;
    overlay.cellId(i) = h.cell;
    overlay.hardRailCrossing(i) = h.hardFeature ? 1 : 0;
  }
  overlay.cellClass.resize(static_cast<int>(complex.cells.size()));
  overlay.sliverCycle.resize(static_cast<int>(complex.cells.size()));
  for (int i = 0; i < static_cast<int>(complex.cells.size()); ++i) {
    const SurfaceArrangementCell &cell = complex.cells[static_cast<std::size_t>(i)];
    overlay.cellClass(i) = static_cast<int>(cell.cellClass);
    overlay.sliverCycle(i) =
        cell.rejectReason == SurfaceArrangementRejectReason::Sliver ? 1 : 0;
  }
  return overlay;
}

} // namespace directional::geometry

namespace directional::geometry {

std::uint64_t hash_surface_cell_complex(const SurfaceCellComplex &complex) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  mix(static_cast<std::int64_t>(complex.sourceOwnershipRegistry.size()));
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    mix(record.sourceComponent);
    mix(record.canonicalMembership.valid ? 1 : 0);
    mix(static_cast<std::int64_t>(record.canonicalMembership.values.size()));
    for (const std::int64_t value : record.canonicalMembership.values) {
      mix(value);
    }
    mix(static_cast<std::int64_t>(record.exactCharts.size()));
    for (const SurfaceCellSourceChart &chart : record.exactCharts) {
      mix(chart.sourceComponent);
      mix(chart.sourceFace);
      mix(chart.localSheet);
    }
  }
  mix(static_cast<int>(complex.nodes.size()));
  mix(static_cast<int>(complex.halfedges.size()));
  mix(static_cast<int>(complex.cells.size()));
  for (const SurfaceArrangementNode &node : complex.nodes) {
    mix(node.hardBarrierCrossing ? 1 : 0);
    mix(node.sourceFace);
    mix(node.sourceComponent);
    mix(node.sourceSheet);
    mix(node.sourceEdge);
    mix(static_cast<std::int64_t>(std::llround(node.sourceEdgeParameter * 1.0e10)));
    for (int i = 0; i < 3; ++i) {
      mix(static_cast<std::int64_t>(std::llround(node.barycentric[i] * 1.0e10)));
    }
    mix(static_cast<int>(node.occurrences.size()));
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      mix(occurrence.sourceFace);
      mix(occurrence.sourceComponent);
      mix(occurrence.sourceSheet);
      mix(occurrence.sourceArc);
      mix(occurrence.provenance);
      mix(occurrence.railId);
      mix(occurrence.curveId);
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.sourceT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.sourceT1 * 1.0e10)));
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.railT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.railT1 * 1.0e10)));
      for (int i = 0; i < 3; ++i) {
        mix(static_cast<std::int64_t>(
            std::llround(occurrence.barycentric[i] * 1.0e10)));
      }
    }
  }
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    mix(halfedge.from);
    mix(halfedge.to);
    mix(static_cast<int>(halfedge.provenance.size()));
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      mix(value.sourceArc);
      mix(value.provenance);
      mix(value.sourceFace);
      mix(value.family);
      mix(value.strand);
      mix(value.featureClass);
      mix(value.hardFeature ? 1 : 0);
      mix(value.layoutSupport ? 1 : 0);
      mix(value.singularitySupport ? 1 : 0);
      mix(value.railId);
      mix(value.curveId);
      mix(value.sourceComponent);
      mix(value.sourceSheet);
      mix(value.proposalId);
      mix(value.proposalSeedId);
      mix(value.proposalSide);
      mix(value.proposalBoundarySegment);
      mix(static_cast<std::int64_t>(std::llround(value.sourceT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.sourceT1 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.railT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.railT1 * 1.0e10)));
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    mix(cell.sourceComponent);
    mix(cell.sourceSheet);
    mix(cell.sourceOwnershipClass.valid ? 1 : 0);
    for (const std::int64_t value : cell.sourceOwnershipClass.values) {
      mix(value);
    }
    for (const SurfaceCellSourceChart &chart : cell.sourceCharts) {
      mix(chart.sourceComponent);
      mix(chart.sourceFace);
      mix(chart.localSheet);
    }
    mix(cell.closed ? 1 : 0);
    mix(cell.disk ? 1 : 0);
    mix(cell.boundaryCycle ? 1 : 0);
    mix(cell.boundaryComponentCount);
    mix(cell.eulerCharacteristic);
    for (const int sourceFace : cell.sourceFaces) {
      mix(sourceFace);
    }
    mix(static_cast<int>(cell.cellClass));
    mix(static_cast<int>(cell.rejectReason));
    mix(static_cast<std::int64_t>(std::llround(cell.signedArea * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(cell.area * 1.0e10)));
    for (const int family : cell.sideFamilies) {
      mix(family);
    }
    for (const int count : cell.sideEdgeCounts) {
      mix(count);
    }
  }
  return hash;
}

} // namespace directional::geometry
