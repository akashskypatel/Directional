#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SourceChartTransitions.h>

#include <functional>

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

int canonical_node_sheet_scope(
    const NodeKey &key, const int sourceFace, const int sourceSheet,
    const VertexFanScopes &vertexFanScopes,
    const std::map<std::pair<int, int>, int> &sourceBoundaryLoopByVertexFan) {
  if (key.kind == 0) {
    const auto found = vertexFanScopes.find({sourceFace, key.vertex});
    const int fanScope =
        found == vertexFanScopes.end() ? sourceSheet : found->second;
    const auto boundary =
        sourceBoundaryLoopByVertexFan.find({key.vertex, fanScope});
    if (boundary != sourceBoundaryLoopByVertexFan.end()) {
      // A manifold source-boundary vertex fan is one physical arrangement
      // node. Hard rails may split its source-interior sectors, but they may
      // not clone the exterior endpoint. Distinct pinched fans retain distinct
      // R1 fan scopes and therefore remain separate.
      return -1 - boundary->second;
    }
    return fanScope;
  }
  // An edge-interior source point is intrinsically shared by both incident
  // triangle charts. Local sheet labels are chart labels and may differ
  // across that adjacency, so they must not split the same source edge.
  if (key.kind == 1) {
    return -1;
  }
  return sourceSheet;
}

ScopedNodeKey make_scoped_node_key(
    const Eigen::MatrixXi &faces, const Segment2 &segment,
    const Eigen::Vector2d &uv, const VertexFanScopes &vertexFanScopes,
    const std::map<std::pair<int, int>, int> &sourceBoundaryLoopByVertexFan) {
  const NodeKey key = make_node_key(faces, segment.sourceFace, uv);
  return {key, segment.sourceComponent,
          canonical_node_sheet_scope(key, segment.sourceFace,
                                     segment.sourceSheet, vertexFanScopes,
                                     sourceBoundaryLoopByVertexFan)};
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
    bytes += vector_storage_bytes(cell.boundaryCycleOffsets);
    bytes += vector_storage_bytes(cell.sourceBoundaryLoopIds);
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

struct SourceBoundaryEdgeRecord {
  std::uint64_t key = 0U;
  int sourceFace = -1;
  int sourceEdge = -1;
  int fromVertex = -1;
  int toVertex = -1;
};

struct SourceBoundaryLoopRecord {
  int id = -1;
  std::vector<SourceBoundaryEdgeRecord> edges;
  SurfaceCellCanonicalIdentity canonicalIdentity;
};

struct SourceBoundaryTopology {
  std::map<std::uint64_t, int> loopByEdge;
  std::map<std::uint64_t, int> edgeOrderByEdge;
  std::vector<SourceBoundaryLoopRecord> loops;
  int loopCount = 0;
  bool valid = true;
};

struct BoundarySubsegmentWitness {
  bool valid = false;
  int halfedge = -1;
  int loop = -1;
  int edgeOrder = -1;
  std::uint64_t sourceEdgeKey = 0U;
  int sourceFace = -1;
  int sourceEdge = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
  int side = 0;
  double parameter0 = 0.0;
  double parameter1 = 0.0;
  double low = 0.0;
  double high = 0.0;
};

SourceBoundaryTopology build_source_boundary_topology(
    const Eigen::MatrixXi &faces,
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces) {
  SourceBoundaryTopology topology;
  std::map<std::uint64_t, SourceBoundaryEdgeRecord> boundaryEdges;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int edge = 0; edge < 3; ++edge) {
      const std::uint64_t key = source_edge_key(faces, face, edge);
      const auto found = edgeFaces.find(key);
      if (found != edgeFaces.end() && found->second[1] >= 0) {
        continue;
      }
      SourceBoundaryEdgeRecord record;
      record.key = key;
      record.sourceFace = face;
      record.sourceEdge = edge;
      // This is the oriented triangle-boundary direction. The incident source
      // face lies on its left, so the twin direction is the exact exterior
      // side used below for authoritative boundary continuation.
      record.fromVertex = faces(face, (edge + 1) % 3);
      record.toVertex = faces(face, (edge + 2) % 3);
      if (!boundaryEdges.emplace(key, record).second) {
        topology.valid = false;
        return topology;
      }
    }
  }
  if (boundaryEdges.empty()) {
    return topology;
  }

  std::map<int, std::uint64_t> outgoingByVertex;
  std::map<int, std::uint64_t> incomingByVertex;
  for (const auto &[key, edge] : boundaryEdges) {
    if (edge.fromVertex < 0 || edge.toVertex < 0 ||
        edge.fromVertex == edge.toVertex ||
        !outgoingByVertex.emplace(edge.fromVertex, key).second ||
        !incomingByVertex.emplace(edge.toVertex, key).second) {
      topology.valid = false;
      return topology;
    }
  }
  if (outgoingByVertex.size() != incomingByVertex.size()) {
    topology.valid = false;
    return topology;
  }
  for (const auto &[vertex, outgoing] : outgoingByVertex) {
    (void)outgoing;
    if (incomingByVertex.count(vertex) != 1U) {
      topology.valid = false;
      return topology;
    }
  }

  std::set<std::uint64_t> unvisited;
  for (const auto &[key, edge] : boundaryEdges) {
    (void)edge;
    unvisited.insert(key);
  }
  while (!unvisited.empty()) {
    const std::uint64_t start = *unvisited.begin();
    std::uint64_t current = start;
    SourceBoundaryLoopRecord loop;
    std::size_t guard = 0U;
    do {
      const auto currentEdge = boundaryEdges.find(current);
      if (currentEdge == boundaryEdges.end() ||
          unvisited.erase(current) != 1U) {
        topology.valid = false;
        return topology;
      }
      loop.edges.push_back(currentEdge->second);
      const auto next = outgoingByVertex.find(currentEdge->second.toVertex);
      if (next == outgoingByVertex.end()) {
        topology.valid = false;
        return topology;
      }
      current = next->second;
      ++guard;
      if (guard > boundaryEdges.size()) {
        topology.valid = false;
        return topology;
      }
    } while (current != start);

    if (loop.edges.size() < 3U) {
      topology.valid = false;
      return topology;
    }
    std::vector<std::uint64_t> canonicalEdges;
    canonicalEdges.reserve(loop.edges.size());
    for (const SourceBoundaryEdgeRecord &edge : loop.edges) {
      canonicalEdges.push_back(edge.key);
    }
    std::sort(canonicalEdges.begin(), canonicalEdges.end());
    loop.canonicalIdentity.valid = true;
    loop.canonicalIdentity.values = {
        0x424f554e44415259LL,
        static_cast<std::int64_t>(canonicalEdges.size())};
    for (const std::uint64_t key : canonicalEdges) {
      loop.canonicalIdentity.values.push_back(
          static_cast<std::int64_t>((key >> 32U) & 0xffffffffULL));
      loop.canonicalIdentity.values.push_back(
          static_cast<std::int64_t>(key & 0xffffffffULL));
    }
    topology.loops.push_back(std::move(loop));
  }

  std::sort(topology.loops.begin(), topology.loops.end(),
            [](const SourceBoundaryLoopRecord &lhs,
               const SourceBoundaryLoopRecord &rhs) {
              return lhs.canonicalIdentity < rhs.canonicalIdentity;
            });
  topology.loopCount = static_cast<int>(topology.loops.size());
  for (int loopId = 0; loopId < topology.loopCount; ++loopId) {
    SourceBoundaryLoopRecord &loop =
        topology.loops[static_cast<std::size_t>(loopId)];
    loop.id = loopId;
    for (int edgeOrder = 0;
         edgeOrder < static_cast<int>(loop.edges.size()); ++edgeOrder) {
      const std::uint64_t key =
          loop.edges[static_cast<std::size_t>(edgeOrder)].key;
      if (!topology.loopByEdge.emplace(key, loopId).second ||
          !topology.edgeOrderByEdge.emplace(key, edgeOrder).second) {
        topology.valid = false;
        return topology;
      }
    }
  }
  return topology;
}

struct BoundarySideEvidence {
  std::vector<int> loopIds;
  int side = 0;
  bool contradictory = false;
  int failureHalfedge = -1;
};

BoundarySideEvidence boundary_side_evidence(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXi &faces,
    const SourceBoundaryTopology &topology) {
  BoundarySideEvidence evidence;
  constexpr double epsilon = 1.0e-12;
  const Eigen::Vector2d triangleCentroid(1.0 / 3.0, 1.0 / 3.0);
  std::map<int, int> sideByLoop;
  for (const int halfedgeId : cellHalfedges) {
    if (halfedgeId < 0 || halfedgeId >= static_cast<int>(halfedges.size())) {
      continue;
    }
    const SurfaceArrangementHalfedge &halfedge =
        halfedges[static_cast<std::size_t>(halfedgeId)];
    if (halfedge.from < 0 || halfedge.to < 0 ||
        halfedge.from >= static_cast<int>(nodes.size()) ||
        halfedge.to >= static_cast<int>(nodes.size())) {
      continue;
    }
    std::set<int> candidateFaces;
    if (halfedge.sourceFace >= 0) {
      candidateFaces.insert(halfedge.sourceFace);
    }
    for (const SurfaceArrangementProvenance &entry : halfedge.provenance) {
      if (entry.sourceFace >= 0) {
        candidateFaces.insert(entry.sourceFace);
      }
    }
    for (const int sourceFace : candidateFaces) {
      if (sourceFace < 0 || sourceFace >= faces.rows()) {
        continue;
      }
      const Eigen::RowVector3d fromBary = node_barycentric_on_face(
          nodes[static_cast<std::size_t>(halfedge.from)], sourceFace);
      const Eigen::RowVector3d toBary = node_barycentric_on_face(
          nodes[static_cast<std::size_t>(halfedge.to)], sourceFace);
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
      const auto loop = topology.loopByEdge.find(
          source_edge_key(faces, sourceFace, sourceEdge));
      if (loop == topology.loopByEdge.end()) {
        continue;
      }
      const Eigen::Vector2d from = bary_to_uv(fromBary);
      const Eigen::Vector2d to = bary_to_uv(toBary);
      const Eigen::Vector2d direction = to - from;
      const Eigen::Vector2d towardInterior =
          triangleCentroid - 0.5 * (from + to);
      const double signedSide = cross2(direction, towardInterior);
      const int side = signedSide > epsilon ? 1 :
                       signedSide < -epsilon ? -1 : 0;
      if (side == 0) {
        continue;
      }
      const auto [found, inserted] = sideByLoop.emplace(loop->second, side);
      if (!inserted && found->second != side) {
        evidence.contradictory = true;
        evidence.failureHalfedge = halfedgeId;
      }
    }
  }
  for (const auto &[loop, side] : sideByLoop) {
    evidence.loopIds.push_back(loop);
    if (evidence.side == 0) {
      evidence.side = side;
    } else if (evidence.side != side) {
      evidence.contradictory = true;
      if (evidence.failureHalfedge < 0 && !cellHalfedges.empty()) {
        evidence.failureHalfedge = cellHalfedges.front();
      }
    }
  }
  return evidence;
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
    for (const SurfaceCellProjectionChart &chart : cell.sourceCharts) {
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
      [&](const std::vector<SurfaceCellProjectionChart> &charts) {
        SurfaceCellCanonicalIdentity identity;
        std::vector<std::array<std::int64_t, 5>> members;
        members.reserve(charts.size());
        for (const SurfaceCellProjectionChart &chart : charts) {
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
                       [&](const SurfaceCellProjectionChart &chart) {
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

  // The compact edge_faces helper stores at most two incident faces. Perform
  // an authoritative full source-topology preflight before constructing chart
  // transitions so a third incident face can never be hidden by local-sheet
  // labels or by the two-entry compatibility map.
  std::map<std::uint64_t, int> sourceEdgeIncidenceCount;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int edge = 0; edge < 3; ++edge) {
      ++sourceEdgeIncidenceCount[source_edge_key(faces, face, edge)];
    }
  }
  const auto nonManifoldSourceEdge = std::find_if(
      sourceEdgeIncidenceCount.begin(), sourceEdgeIncidenceCount.end(),
      [](const auto &entry) { return entry.second > 2; });
  if (nonManifoldSourceEdge != sourceEdgeIncidenceCount.end()) {
    complex.diagnostics.incidenceFailure =
        SurfaceArrangementIncidenceFailure::NonManifoldSourceEdge;
    complex.diagnostics.incidenceValid = false;
    complex.diagnostics.embeddingValid = false;
    complex.diagnostics.orientationValid = false;
    complex.diagnostics.cellsDiskValid = false;
    complex.diagnostics.boundaryLoopsValid = false;
    complex.diagnostics.eulerCharacteristicValid = false;
    complex.diagnostics.topologyValid = false;
    complex.diagnostics.inputMemoryBytes =
        static_cast<std::uint64_t>(vertices.size()) * sizeof(double) +
        static_cast<std::uint64_t>(faces.size()) * sizeof(int) +
        static_cast<std::uint64_t>(inputArcs.capacity()) *
            sizeof(SurfaceArrangementArc);
    complex.diagnostics.retainedMemoryBytes = complex_storage_bytes(complex);
    complex.diagnostics.peakMemoryBytes =
        complex.diagnostics.retainedMemoryBytes;
    if (complex.diagnostics.inputMemoryBytes > 0U) {
      complex.diagnostics.measuredMemoryRatio =
          static_cast<double>(complex.diagnostics.peakMemoryBytes) /
          static_cast<double>(complex.diagnostics.inputMemoryBytes);
      complex.diagnostics.memoryRatioEstimate =
          complex.diagnostics.measuredMemoryRatio;
    }
    return complex;
  }
  const SourceBoundaryTopology sourceBoundaryTopology =
      build_source_boundary_topology(faces, edgeFaces);

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

  std::map<std::pair<int, int>, int> sourceBoundaryLoopByVertexFan;
  bool sourceBoundaryVertexAliasesValid = sourceBoundaryTopology.valid;
  if (sourceBoundaryVertexAliasesValid) {
    for (const SourceBoundaryLoopRecord &loop : sourceBoundaryTopology.loops) {
      for (const SourceBoundaryEdgeRecord &edge : loop.edges) {
        for (const int vertex : {edge.fromVertex, edge.toVertex}) {
          const auto fan = vertexFanScopes.find({edge.sourceFace, vertex});
          if (fan == vertexFanScopes.end()) {
            sourceBoundaryVertexAliasesValid = false;
            break;
          }
          const auto [found, inserted] =
              sourceBoundaryLoopByVertexFan.emplace(
                  std::make_pair(vertex, fan->second), loop.id);
          if (!inserted && found->second != loop.id) {
            sourceBoundaryVertexAliasesValid = false;
            break;
          }
        }
        if (!sourceBoundaryVertexAliasesValid) {
          break;
        }
      }
      if (!sourceBoundaryVertexAliasesValid) {
        break;
      }
    }
  }

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
              vertexFanScopes, sourceBoundaryLoopByVertexFan));
        }
      }
      intersectionKeys.insert(make_scoped_node_key(
          faces, segments[static_cast<std::size_t>(i)], p,
          vertexFanScopes, sourceBoundaryLoopByVertexFan));
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
        make_scoped_node_key(faces, segment, uv, vertexFanScopes,
                             sourceBoundaryLoopByVertexFan);
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

  const auto record_boundary_fan_conflict =
      [&](const SurfaceArrangementBoundaryFanConflict conflict,
          const int node, const int incoming, const int sourceRay,
          const int target) {
        if (complex.diagnostics.boundaryFanConflict ==
            SurfaceArrangementBoundaryFanConflict::None) {
          complex.diagnostics.boundaryFanConflict = conflict;
          complex.diagnostics.boundaryFanConflictNode = node;
          complex.diagnostics.boundaryFanConflictIncoming = incoming;
          complex.diagnostics.boundaryFanConflictSourceRay = sourceRay;
          complex.diagnostics.boundaryFanConflictTarget = target;
        }
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::
                BoundaryFanSectorCoverConflict,
            node, incoming, sourceRay, target);
      };

  const auto halfedge_source_charts =
      [&](const SurfaceArrangementHalfedge &halfedge) {
        std::set<SurfaceCellProjectionChart> charts;
        for (const SurfaceArrangementProvenance &entry : halfedge.provenance) {
          const SurfaceCellProjectionChart chart{entry.sourceComponent,
                                             entry.sourceFace,
                                             entry.sourceSheet};
          if (chart.valid()) {
            charts.insert(chart);
          }
        }
        const SurfaceCellProjectionChart primary{halfedge.sourceComponent,
                                             halfedge.sourceFace,
                                             halfedge.sourceSheet};
        if (primary.valid()) {
          charts.insert(primary);
        }
        return std::vector<SurfaceCellProjectionChart>(charts.begin(), charts.end());
      };

  const auto node_point_on_chart =
      [&](const int nodeId, const SurfaceCellProjectionChart &chart,
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
          const SurfaceCellProjectionChart &chart, const SourceEntityId &entity,
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

  std::vector<int> candidateNext(complex.halfedges.size(), -1);
  std::vector<int> predecessorCount(complex.halfedges.size(), 0);
  std::vector<SurfaceCellCanonicalIdentity> successorWedge(
      complex.halfedges.size());
  std::vector<unsigned char> authoritativeBoundaryExterior(
      complex.halfedges.size(), 0U);
  std::vector<int> authoritativeBoundaryLoop(complex.halfedges.size(), -1);
  std::vector<int> authoritativeBoundarySide(complex.halfedges.size(), 0);
  std::vector<SurfaceCellCanonicalIdentity> authoritativeBoundarySegment(
      complex.halfedges.size());
  std::vector<BoundarySubsegmentWitness> boundaryWitnesses(
      complex.halfedges.size());
  std::vector<int> successorChartRoot(complex.halfedges.size(), -1);
  std::vector<int> candidateOrbitChartRoot(complex.halfedges.size(), -1);
  std::vector<std::pair<int, int>> hardRailOrbitSeeds;

  if (resolvedOptions.useAuthoritativeProposalCycles) {
    struct ProposalOccurrence {
      int halfedge = -1;
      int side = -1;
      int segment = -1;
      double sourceT0 = 0.0;
      double sourceT1 = 0.0;
    };
    std::map<int, std::vector<ProposalOccurrence>> occurrencesByProposal;
    for (SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
      halfedge.next = -1;
      halfedge.authoritativeChartRoot = -1;
      if (halfedge.twin < 0 ||
          halfedge.twin >= static_cast<int>(complex.halfedges.size()) ||
          complex.halfedges[static_cast<std::size_t>(halfedge.twin)].twin !=
              halfedge.id) {
        record_incidence_failure(SurfaceArrangementIncidenceFailure::InvalidTwin,
                                 halfedge.to, halfedge.id, halfedge.twin, -1);
        continue;
      }
      for (const SurfaceArrangementProvenance &entry : halfedge.provenance) {
        if (entry.proposalId < 0 || entry.proposalSide < 0 ||
            entry.proposalBoundarySegment < 0 ||
            !(entry.sourceT1 > entry.sourceT0 + 1.0e-12)) {
          continue;
        }
        occurrencesByProposal[entry.proposalId].push_back(
            {halfedge.id, entry.proposalSide,
             entry.proposalBoundarySegment, entry.sourceT0, entry.sourceT1});
      }
    }
    if (occurrencesByProposal.empty()) {
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::MissingSuccessor, -1, -1, -1,
          -1);
    }
    for (auto &[proposalId, occurrences] : occurrencesByProposal) {
      std::sort(occurrences.begin(), occurrences.end(),
                [](const ProposalOccurrence &lhs,
                   const ProposalOccurrence &rhs) {
                  return std::tie(lhs.side, lhs.segment, lhs.sourceT0,
                                  lhs.sourceT1, lhs.halfedge) <
                         std::tie(rhs.side, rhs.segment, rhs.sourceT0,
                                  rhs.sourceT1, rhs.halfedge);
                });
      occurrences.erase(
          std::unique(occurrences.begin(), occurrences.end(),
                      [](const ProposalOccurrence &lhs,
                         const ProposalOccurrence &rhs) {
                        return lhs.halfedge == rhs.halfedge;
                      }),
          occurrences.end());
      std::set<int> sides;
      for (const ProposalOccurrence &occurrence : occurrences) {
        sides.insert(occurrence.side);
      }
      if (occurrences.size() < 4U || sides != std::set<int>({0, 1, 2, 3})) {
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::IncompletePermutation, -1,
            occurrences.empty() ? -1 : occurrences.front().halfedge, -1, -1);
        break;
      }
      SurfaceCellCanonicalIdentity proposalIdentity;
      proposalIdentity.valid = true;
      proposalIdentity.values = {0x50524f504f53414cLL, proposalId};
      for (std::size_t index = 0; index < occurrences.size(); ++index) {
        const int current = occurrences[index].halfedge;
        const int next = occurrences[(index + 1U) % occurrences.size()].halfedge;
        if (current < 0 || next < 0 ||
            complex.halfedges[static_cast<std::size_t>(current)].to !=
                complex.halfedges[static_cast<std::size_t>(next)].from ||
            (candidateNext[static_cast<std::size_t>(current)] >= 0 &&
             candidateNext[static_cast<std::size_t>(current)] != next)) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::EndpointDiscontinuity,
              current >= 0
                  ? complex.halfedges[static_cast<std::size_t>(current)].to
                  : -1,
              current, current >= 0
                           ? complex.halfedges[static_cast<std::size_t>(current)]
                                 .twin
                           : -1,
              next);
          break;
        }
        candidateNext[static_cast<std::size_t>(current)] = next;
        successorWedge[static_cast<std::size_t>(current)] = proposalIdentity;
      }
      if (!directedIncidenceValid) {
        break;
      }
    }

    if (directedIncidenceValid) {
      std::vector<std::vector<int>> unassignedOutgoing(complex.nodes.size());
      for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
        if (candidateNext[static_cast<std::size_t>(halfedge.id)] < 0 &&
            halfedge.from >= 0 &&
            halfedge.from < static_cast<int>(unassignedOutgoing.size())) {
          unassignedOutgoing[static_cast<std::size_t>(halfedge.from)]
              .push_back(halfedge.id);
        }
      }
      SurfaceCellCanonicalIdentity exteriorIdentity;
      exteriorIdentity.valid = true;
      exteriorIdentity.values = {0x4558544552494f52LL};
      for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
        if (candidateNext[static_cast<std::size_t>(halfedge.id)] >= 0) {
          continue;
        }
        std::vector<int> candidates;
        if (halfedge.to >= 0 &&
            halfedge.to < static_cast<int>(unassignedOutgoing.size())) {
          for (const int candidate :
               unassignedOutgoing[static_cast<std::size_t>(halfedge.to)]) {
            if (candidate != halfedge.twin) {
              candidates.push_back(candidate);
            }
          }
        }
        if (candidates.size() != 1U) {
          record_incidence_failure(
              candidates.empty()
                  ? SurfaceArrangementIncidenceFailure::MissingSuccessor
                  : SurfaceArrangementIncidenceFailure::DuplicatePredecessor,
              halfedge.to, halfedge.id, halfedge.twin,
              candidates.empty() ? -1 : candidates.front());
          break;
        }
        candidateNext[static_cast<std::size_t>(halfedge.id)] = candidates.front();
        successorWedge[static_cast<std::size_t>(halfedge.id)] = exteriorIdentity;
      }
    }
  } else {
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
    for (const SurfaceCellProjectionChart &chart :
         halfedge_source_charts(halfedge)) {
      if (!transitionGraph.available() ||
          transitionGraph.chart_component(SourceProjectionChart{
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

  for (SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    halfedge.next = -1;
    halfedge.authoritativeChartRoot = -1;
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
    candidateNext[static_cast<std::size_t>(halfedge.id)] = next;
    successorWedge[static_cast<std::size_t>(halfedge.id)] = *selectedWedge;
  }

  // Source-boundary exterior continuation is authoritative source topology,
  // not a generic wedge choice. Build an exact subsegment inventory and install
  // the exterior successor permutation before the complete orbit audit. This
  // prevents boundary-ending traces and interior hard rails from partitioning
  // the unbounded side of one source boundary loop.
  if (directedIncidenceValid && resolvedOptions.insertBoundaryRails) {
    if (!sourceBoundaryTopology.valid ||
        !sourceBoundaryVertexAliasesValid) {
      record_incidence_failure(
          sourceBoundaryTopology.valid
              ? SurfaceArrangementIncidenceFailure::BoundaryAliasConflict
              : SurfaceArrangementIncidenceFailure::BoundaryLoopOwnerCount,
          -1, -1, -1, -1);
    } else {
      constexpr double boundaryParameterTolerance = 1.0e-10;
      using SideBuckets = std::array<std::vector<int>, 2>;
      std::vector<std::vector<SideBuckets>> boundaryByLoopEdge;
      boundaryByLoopEdge.reserve(sourceBoundaryTopology.loops.size());
      for (const SourceBoundaryLoopRecord &loop :
           sourceBoundaryTopology.loops) {
        boundaryByLoopEdge.emplace_back(loop.edges.size());
      }

      const auto quantized_parameter = [](const double value) {
        return static_cast<std::int64_t>(std::llround(value * 1.0e12));
      };
      const auto witness_key = [&](const BoundarySubsegmentWitness &witness) {
        return std::make_tuple(
            witness.loop, witness.edgeOrder, witness.sourceEdgeKey,
            witness.sourceFace, witness.sourceEdge, witness.sourceComponent,
            witness.sourceSheet, witness.side,
            quantized_parameter(witness.parameter0),
            quantized_parameter(witness.parameter1));
      };

      for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
        std::vector<BoundarySubsegmentWitness> candidates;
        for (const SurfaceArrangementProvenance &entry : halfedge.provenance) {
          if (entry.sourceArc >= 0 || entry.family >= 0 ||
              !entry.hardFeature || entry.sourceFace < 0 ||
              entry.sourceFace >= faces.rows()) {
            continue;
          }
          if (halfedge.from < 0 || halfedge.to < 0 ||
              halfedge.from >= static_cast<int>(complex.nodes.size()) ||
              halfedge.to >= static_cast<int>(complex.nodes.size())) {
            continue;
          }
          const Eigen::RowVector3d fromBary = node_barycentric_on_face(
              complex.nodes[static_cast<std::size_t>(halfedge.from)],
              entry.sourceFace);
          const Eigen::RowVector3d toBary = node_barycentric_on_face(
              complex.nodes[static_cast<std::size_t>(halfedge.to)],
              entry.sourceFace);
          if (!fromBary.allFinite() || !toBary.allFinite()) {
            continue;
          }
          int sourceEdge = -1;
          for (int coordinate = 0; coordinate < 3; ++coordinate) {
            if (std::abs(fromBary[coordinate]) <= 1.0e-12 &&
                std::abs(toBary[coordinate]) <= 1.0e-12) {
              sourceEdge = coordinate;
              break;
            }
          }
          if (sourceEdge < 0 || entry.featureClass != sourceEdge ||
              !std::isfinite(entry.sourceT0) ||
              !std::isfinite(entry.sourceT1)) {
            continue;
          }
          const std::uint64_t edgeKey =
              source_edge_key(faces, entry.sourceFace, sourceEdge);
          const auto loopFound = sourceBoundaryTopology.loopByEdge.find(edgeKey);
          const auto orderFound =
              sourceBoundaryTopology.edgeOrderByEdge.find(edgeKey);
          if (loopFound == sourceBoundaryTopology.loopByEdge.end() ||
              orderFound == sourceBoundaryTopology.edgeOrderByEdge.end()) {
            continue;
          }
          double parameter0 = canonical_edge_parameter(
              faces, entry.sourceFace, sourceEdge, bary_to_uv(fromBary));
          double parameter1 = canonical_edge_parameter(
              faces, entry.sourceFace, sourceEdge, bary_to_uv(toBary));
          if (parameter0 < -boundaryParameterTolerance ||
              parameter0 > 1.0 + boundaryParameterTolerance ||
              parameter1 < -boundaryParameterTolerance ||
              parameter1 > 1.0 + boundaryParameterTolerance ||
              std::abs(parameter1 - parameter0) <=
                  boundaryParameterTolerance) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::BoundaryCoverageOverlap,
                halfedge.from, halfedge.id, halfedge.twin, -1);
            break;
          }
          parameter0 = std::clamp(parameter0, 0.0, 1.0);
          parameter1 = std::clamp(parameter1, 0.0, 1.0);
          const SourceBoundaryEdgeRecord &loopEdge =
              sourceBoundaryTopology
                  .loops[static_cast<std::size_t>(loopFound->second)]
                  .edges[static_cast<std::size_t>(orderFound->second)];
          const bool loopDirectionIncreasesCanonicalParameter =
              loopEdge.fromVertex < loopEdge.toVertex;
          const bool halfedgeIncreasesCanonicalParameter =
              parameter1 > parameter0;
          BoundarySubsegmentWitness witness;
          witness.valid = true;
          witness.halfedge = halfedge.id;
          witness.loop = loopFound->second;
          witness.edgeOrder = orderFound->second;
          witness.sourceEdgeKey = edgeKey;
          witness.sourceFace = entry.sourceFace;
          witness.sourceEdge = sourceEdge;
          witness.sourceComponent =
              resolvedComponents[static_cast<std::size_t>(entry.sourceFace)];
          witness.sourceSheet =
              resolvedSheets[static_cast<std::size_t>(entry.sourceFace)];
          if ((entry.sourceComponent >= 0 &&
               entry.sourceComponent != witness.sourceComponent) ||
              (entry.sourceSheet >= 0 &&
               entry.sourceSheet != witness.sourceSheet)) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    ContradictoryBoundarySide,
                halfedge.from, halfedge.id, halfedge.twin, -1);
            break;
          }
          // Canonical edge parameters are orientation independent. The
          // operational side is derived separately by comparing the directed
          // halfedge with the ordered face-oriented source-boundary edge.
          witness.side =
              halfedgeIncreasesCanonicalParameter ==
                      loopDirectionIncreasesCanonicalParameter
                  ? 1
                  : -1;
          witness.parameter0 = parameter0;
          witness.parameter1 = parameter1;
          witness.low = std::min(parameter0, parameter1);
          witness.high = std::max(parameter0, parameter1);
          candidates.push_back(std::move(witness));
        }
        if (!directedIncidenceValid) {
          break;
        }
        if (candidates.empty()) {
          continue;
        }
        std::sort(candidates.begin(), candidates.end(),
                  [&](const BoundarySubsegmentWitness &lhs,
                      const BoundarySubsegmentWitness &rhs) {
                    return witness_key(lhs) < witness_key(rhs);
                  });
        candidates.erase(
            std::unique(candidates.begin(), candidates.end(),
                        [&](const BoundarySubsegmentWitness &lhs,
                            const BoundarySubsegmentWitness &rhs) {
                          return witness_key(lhs) == witness_key(rhs);
                        }),
            candidates.end());
        if (candidates.size() != 1U) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::ContradictoryBoundarySide,
              halfedge.from, halfedge.id, halfedge.twin, -1);
          break;
        }
        const BoundarySubsegmentWitness &witness = candidates.front();
        if (witness.loop < 0 ||
            witness.loop >= static_cast<int>(boundaryByLoopEdge.size()) ||
            witness.edgeOrder < 0 ||
            witness.edgeOrder >= static_cast<int>(
                                     boundaryByLoopEdge[static_cast<std::size_t>(
                                         witness.loop)]
                                         .size())) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::BoundaryCoverageGap,
              halfedge.from, halfedge.id, halfedge.twin, -1);
          break;
        }
        boundaryWitnesses[static_cast<std::size_t>(halfedge.id)] = witness;
        const int sideIndex = witness.side < 0 ? 0 : 1;
        boundaryByLoopEdge[static_cast<std::size_t>(witness.loop)]
                          [static_cast<std::size_t>(witness.edgeOrder)]
                              [static_cast<std::size_t>(sideIndex)]
                                  .push_back(halfedge.id);
      }

      const auto validate_boundary_coverage =
          [&](std::vector<int> &bucket, const int loop, const int edgeOrder,
              const int side) {
            if (bucket.empty()) {
              record_incidence_failure(
                  SurfaceArrangementIncidenceFailure::BoundaryCoverageGap,
                  -1, -1, -1, loop);
              return false;
            }
            std::sort(bucket.begin(), bucket.end(), [&](const int lhs,
                                                        const int rhs) {
              const BoundarySubsegmentWitness &a =
                  boundaryWitnesses[static_cast<std::size_t>(lhs)];
              const BoundarySubsegmentWitness &b =
                  boundaryWitnesses[static_cast<std::size_t>(rhs)];
              return std::tie(a.low, a.high, a.halfedge) <
                     std::tie(b.low, b.high, b.halfedge);
            });
            double covered = 0.0;
            for (const int halfedgeId : bucket) {
              const BoundarySubsegmentWitness &witness =
                  boundaryWitnesses[static_cast<std::size_t>(halfedgeId)];
              if (witness.loop != loop || witness.edgeOrder != edgeOrder ||
                  witness.side != side) {
                record_incidence_failure(
                    SurfaceArrangementIncidenceFailure::BoundaryCoverageOverlap,
                    complex.halfedges[static_cast<std::size_t>(halfedgeId)].from,
                    halfedgeId,
                    complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
                    -1);
                return false;
              }
              if (witness.low > covered + boundaryParameterTolerance) {
                record_incidence_failure(
                    SurfaceArrangementIncidenceFailure::BoundaryCoverageGap,
                    complex.halfedges[static_cast<std::size_t>(halfedgeId)].from,
                    halfedgeId,
                    complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
                    loop);
                return false;
              }
              if (witness.low < covered - boundaryParameterTolerance) {
                record_incidence_failure(
                    SurfaceArrangementIncidenceFailure::BoundaryCoverageOverlap,
                    complex.halfedges[static_cast<std::size_t>(halfedgeId)].from,
                    halfedgeId,
                    complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
                    loop);
                return false;
              }
              covered = std::max(covered, witness.high);
            }
            if (covered < 1.0 - boundaryParameterTolerance) {
              const int last = bucket.back();
              record_incidence_failure(
                  SurfaceArrangementIncidenceFailure::BoundaryCoverageGap,
                  complex.halfedges[static_cast<std::size_t>(last)].to, last,
                  complex.halfedges[static_cast<std::size_t>(last)].twin, loop);
              return false;
            }
            return true;
          };

      for (int loop = 0;
           directedIncidenceValid &&
           loop < static_cast<int>(boundaryByLoopEdge.size());
           ++loop) {
        for (int edgeOrder = 0;
             directedIncidenceValid &&
             edgeOrder < static_cast<int>(
                             boundaryByLoopEdge[static_cast<std::size_t>(loop)]
                                 .size());
             ++edgeOrder) {
          for (int sideIndex = 0; sideIndex < 2; ++sideIndex) {
            const int side = sideIndex == 0 ? -1 : 1;
            validate_boundary_coverage(
                boundaryByLoopEdge[static_cast<std::size_t>(loop)]
                                  [static_cast<std::size_t>(edgeOrder)]
                                  [static_cast<std::size_t>(sideIndex)],
                loop, edgeOrder, side);
            if (!directedIncidenceValid) {
              break;
            }
          }
        }
      }

      const auto make_boundary_segment_identity =
          [&](const BoundarySubsegmentWitness &witness) {
            SurfaceCellCanonicalIdentity identity;
            if (!witness.valid || witness.loop < 0 ||
                witness.loop >=
                    static_cast<int>(sourceBoundaryTopology.loops.size())) {
              return identity;
            }
            identity = sourceBoundaryTopology
                           .loops[static_cast<std::size_t>(witness.loop)]
                           .canonicalIdentity;
            identity.values.push_back(0x5345474d454e54LL);
            identity.values.push_back(static_cast<std::int64_t>(
                (witness.sourceEdgeKey >> 32U) & 0xffffffffULL));
            identity.values.push_back(static_cast<std::int64_t>(
                witness.sourceEdgeKey & 0xffffffffULL));
            identity.values.push_back(quantized_parameter(witness.low));
            identity.values.push_back(quantized_parameter(witness.high));
            return identity;
          };

      std::vector<int> desiredExteriorNext(complex.halfedges.size(), -1);
      std::vector<std::vector<int>> exteriorIncomingByNode(
          complex.nodes.size());
      for (int loop = 0;
           directedIncidenceValid &&
           loop < static_cast<int>(sourceBoundaryTopology.loops.size());
           ++loop) {
        const SourceBoundaryLoopRecord &loopRecord =
            sourceBoundaryTopology.loops[static_cast<std::size_t>(loop)];
        std::vector<int> exteriorSequence;
        exteriorSequence.reserve(loopRecord.edges.size());
        // Exterior traversal is opposite the operational source loop. Visit
        // source edges in reverse loop order, then order exact subsegments by
        // their canonical source-edge start parameter in that travel direction.
        for (int reverseIndex = static_cast<int>(loopRecord.edges.size()) - 1;
             reverseIndex >= 0; --reverseIndex) {
          const SourceBoundaryEdgeRecord &loopEdge =
              loopRecord.edges[static_cast<std::size_t>(reverseIndex)];
          const bool exteriorIncreasesCanonicalParameter =
              loopEdge.fromVertex > loopEdge.toVertex;
          std::vector<int> edgeSegments =
              boundaryByLoopEdge[static_cast<std::size_t>(loop)]
                                [static_cast<std::size_t>(reverseIndex)][0];
          std::sort(edgeSegments.begin(), edgeSegments.end(),
                    [&](const int lhs, const int rhs) {
                      const BoundarySubsegmentWitness &a =
                          boundaryWitnesses[static_cast<std::size_t>(lhs)];
                      const BoundarySubsegmentWitness &b =
                          boundaryWitnesses[static_cast<std::size_t>(rhs)];
                      if (std::abs(a.parameter0 - b.parameter0) >
                          boundaryParameterTolerance) {
                        return exteriorIncreasesCanonicalParameter
                                   ? a.parameter0 < b.parameter0
                                   : a.parameter0 > b.parameter0;
                      }
                      return a.halfedge < b.halfedge;
                    });
          for (const int halfedgeId : edgeSegments) {
            const BoundarySubsegmentWitness &witness =
                boundaryWitnesses[static_cast<std::size_t>(halfedgeId)];
            const bool witnessIncreases =
                witness.parameter1 > witness.parameter0;
            if (witness.side != -1 ||
                witnessIncreases != exteriorIncreasesCanonicalParameter) {
              record_incidence_failure(
                  SurfaceArrangementIncidenceFailure::ContradictoryBoundarySide,
                  complex.halfedges[static_cast<std::size_t>(halfedgeId)].from,
                  halfedgeId,
                  complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
                  loop);
              break;
            }
            exteriorSequence.push_back(halfedgeId);
          }
        }
        if (!directedIncidenceValid) {
          break;
        }
        if (exteriorSequence.size() < 3U) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::BoundaryCoverageGap, -1, -1,
              -1, loop);
          break;
        }
        for (std::size_t index = 0; index < exteriorSequence.size(); ++index) {
          const int currentId = exteriorSequence[index];
          const int nextId =
              exteriorSequence[(index + 1U) % exteriorSequence.size()];
          const SurfaceArrangementHalfedge &current =
              complex.halfedges[static_cast<std::size_t>(currentId)];
          const SurfaceArrangementHalfedge &next =
              complex.halfedges[static_cast<std::size_t>(nextId)];
          if (current.to != next.from) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryContinuationDiscontinuity,
                current.to, currentId, current.twin, nextId);
            break;
          }
          int &desired =
              desiredExteriorNext[static_cast<std::size_t>(currentId)];
          if (desired >= 0 && desired != nextId) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryLocalPermutationConflict,
                current.to, currentId, current.twin, nextId);
            break;
          }
          desired = nextId;
          authoritativeBoundaryExterior[static_cast<std::size_t>(currentId)] =
              1U;
          authoritativeBoundaryLoop[static_cast<std::size_t>(currentId)] = loop;
          authoritativeBoundarySide[static_cast<std::size_t>(currentId)] = -1;
          authoritativeBoundarySegment[static_cast<std::size_t>(currentId)] =
              make_boundary_segment_identity(
                  boundaryWitnesses[static_cast<std::size_t>(currentId)]);
          successorWedge[static_cast<std::size_t>(currentId)] =
              loopRecord.canonicalIdentity;
          if (current.to < 0 ||
              current.to >= static_cast<int>(exteriorIncomingByNode.size())) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::BoundaryAliasConflict,
                current.to, currentId, current.twin, nextId);
            break;
          }
          exteriorIncomingByNode[static_cast<std::size_t>(current.to)]
              .push_back(currentId);
        }
      }

      // Retain canonical boundary identity for both directed twins. Hashing and
      // later diagnostics treat one physical source-boundary segment as one
      // incidence object rather than mixing an authoritative exterior record
      // with an operational generic record for its interior twin.
      for (std::size_t halfedge = 0; halfedge < boundaryWitnesses.size();
           ++halfedge) {
        const BoundarySubsegmentWitness &witness =
            boundaryWitnesses[halfedge];
        if (!witness.valid) {
          continue;
        }
        authoritativeBoundaryLoop[halfedge] = witness.loop;
        authoritativeBoundarySide[halfedge] = witness.side;
        authoritativeBoundarySegment[halfedge] =
            make_boundary_segment_identity(witness);
      }

      // Reconstruct each boundary-node rotation transactionally. Degree-two
      // nodes retain the audited explicit exterior/interior construction. Nodes
      // with three or more rays are assembled from the complete set of R1-selected
      // source-interior fan sectors plus the one authoritative exterior sector.
      // No common wedge is required to span hard-rail-separated fan scopes.
      for (int node = 0;
           directedIncidenceValid &&
           node < static_cast<int>(exteriorIncomingByNode.size()); ++node) {
        auto &forced = exteriorIncomingByNode[static_cast<std::size_t>(node)];
        std::sort(forced.begin(), forced.end());
        forced.erase(std::unique(forced.begin(), forced.end()), forced.end());
        if (forced.empty()) {
          continue;
        }
        if (forced.size() != 1U) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::
                  BoundaryRotationalSystemConflict,
              node, forced.front(),
              complex.halfedges[static_cast<std::size_t>(forced.front())].twin,
              -1);
          break;
        }

        const int exteriorIncoming = forced.front();
        const int exteriorOutgoing =
            desiredExteriorNext[static_cast<std::size_t>(exteriorIncoming)];
        if (exteriorOutgoing < 0 ||
            exteriorOutgoing >= static_cast<int>(complex.halfedges.size()) ||
            complex.halfedges[static_cast<std::size_t>(exteriorIncoming)].to !=
                node ||
            complex.halfedges[static_cast<std::size_t>(exteriorOutgoing)].from !=
                node) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::BoundaryAliasConflict, node,
              exteriorIncoming,
              complex.halfedges[static_cast<std::size_t>(exteriorIncoming)].twin,
              exteriorOutgoing);
          break;
        }

        std::vector<int> localOutgoing;
        for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
          if (halfedge.from == node) {
            localOutgoing.push_back(halfedge.id);
          }
        }
        std::sort(localOutgoing.begin(), localOutgoing.end());
        if (localOutgoing.size() < 2U) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::
                  BoundaryRotationalSystemConflict,
              node, exteriorIncoming,
              complex.halfedges[static_cast<std::size_t>(exteriorIncoming)].twin,
              exteriorOutgoing);
          break;
        }

        const auto &nodeWedges = orderedWedges[static_cast<std::size_t>(node)];
        const int exteriorTwin =
            complex.halfedges[static_cast<std::size_t>(exteriorIncoming)].twin;
        const bool degreeTwoRotation = localOutgoing.size() == 2U;
        std::map<int, int> localTargetCount;
        std::set<int> localIncoming;

        if (degreeTwoRotation) {
          // Preserve the R2E5 degree-two producer exactly. One common
          // SourceVertex/SourceEdge identity is still required for the exact
          // two-ray inventory because no fan-scope cover is necessary.
          std::vector<SurfaceCellCanonicalIdentity> commonWedges =
              halfedgeWedges[static_cast<std::size_t>(localOutgoing.front())];
          for (std::size_t index = 1;
               index < localOutgoing.size() && !commonWedges.empty(); ++index) {
            std::vector<SurfaceCellCanonicalIdentity> intersection;
            const auto &memberships = halfedgeWedges[static_cast<std::size_t>(
                localOutgoing[index])];
            std::set_intersection(commonWedges.begin(), commonWedges.end(),
                                  memberships.begin(), memberships.end(),
                                  std::back_inserter(intersection));
            commonWedges = std::move(intersection);
          }

          std::vector<const SurfaceCellCanonicalIdentity *> rotationCandidates;
          for (const SurfaceCellCanonicalIdentity &identity : commonWedges) {
            const auto found = nodeWedges.find(identity);
            if (found == nodeWedges.end() ||
                found->second.size() != localOutgoing.size()) {
              continue;
            }
            std::vector<int> candidateRays;
            candidateRays.reserve(found->second.size());
            bool intrinsicBoundaryEntity = true;
            for (const DirectedWedgeRay &ray : found->second) {
              candidateRays.push_back(ray.halfedge);
              const bool rayHasBoundaryEntity = std::any_of(
                  ray.witnesses.begin(), ray.witnesses.end(),
                  [](const DirectedWedgeWitness &witness) {
                    return witness.kind == SourceEntityKind::SourceVertex ||
                           witness.kind == SourceEntityKind::SourceEdge;
                  });
              intrinsicBoundaryEntity =
                  intrinsicBoundaryEntity && rayHasBoundaryEntity;
            }
            std::sort(candidateRays.begin(), candidateRays.end());
            if (intrinsicBoundaryEntity && candidateRays == localOutgoing) {
              rotationCandidates.push_back(&identity);
            }
          }
          if (rotationCandidates.size() != 1U) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryRotationalSystemConflict,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }

          const SurfaceCellCanonicalIdentity &rotationIdentity =
              *rotationCandidates.front();
          const auto rotationFound = nodeWedges.find(rotationIdentity);
          if (rotationFound == nodeWedges.end() ||
              rotationFound->second.size() != 2U) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryRotationalSystemConflict,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }
          const std::vector<DirectedWedgeRay> &rays = rotationFound->second;
          const auto exteriorTwinFound = std::find_if(
              rays.begin(), rays.end(), [&](const DirectedWedgeRay &ray) {
                return ray.halfedge == exteriorTwin;
              });
          const auto exteriorOutgoingFound = std::find_if(
              rays.begin(), rays.end(), [&](const DirectedWedgeRay &ray) {
                return ray.halfedge == exteriorOutgoing;
              });
          const int complementaryIncoming =
              complex.halfedges[static_cast<std::size_t>(exteriorOutgoing)].twin;
          std::set<int> twoRayInventory;
          for (const DirectedWedgeRay &ray : rays) {
            twoRayInventory.insert(ray.halfedge);
          }
          if (exteriorTwinFound == rays.end() ||
              exteriorOutgoingFound == rays.end() ||
              exteriorTwin == exteriorOutgoing ||
              twoRayInventory.size() != 2U ||
              twoRayInventory !=
                  std::set<int>{exteriorTwin, exteriorOutgoing} ||
              complementaryIncoming < 0 ||
              complementaryIncoming >=
                  static_cast<int>(complex.halfedges.size()) ||
              complementaryIncoming == exteriorIncoming ||
              complex.halfedges[static_cast<std::size_t>(exteriorIncoming)].to !=
                  node ||
              complex.halfedges[static_cast<std::size_t>(complementaryIncoming)]
                      .to !=
                  node ||
              complex.halfedges[static_cast<std::size_t>(exteriorTwin)].from !=
                  node ||
              complex.halfedges[static_cast<std::size_t>(exteriorOutgoing)]
                      .from !=
                  node) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryRotationalSystemConflict,
                node, exteriorIncoming, complementaryIncoming,
                exteriorOutgoing);
            break;
          }

          candidateNext[static_cast<std::size_t>(exteriorIncoming)] =
              exteriorOutgoing;
          candidateNext[static_cast<std::size_t>(complementaryIncoming)] =
              exteriorTwin;
          successorWedge[static_cast<std::size_t>(exteriorIncoming)] =
              rotationIdentity;
          successorWedge[static_cast<std::size_t>(complementaryIncoming)] =
              rotationIdentity;
          localIncoming.insert(exteriorIncoming);
          localIncoming.insert(complementaryIncoming);
          ++localTargetCount[exteriorOutgoing];
          ++localTargetCount[exteriorTwin];
        } else {
          struct BoundaryFanSector {
            int incoming = -1;
            int sourceRay = -1;
            int target = -1;
            SurfaceCellCanonicalIdentity fanIdentity;
            SurfaceCellProjectionChart chart;
            int chartRoot = -1;
            double sourceLeftScore = 0.0;
            double targetLeftScore = 0.0;
            double targetAngle = 0.0;
            double sourceAngle = 0.0;
            bool exterior = false;
            bool cyclicWrap = false;
          };
          struct ChartCornerRay {
            int halfedge = -1;
            int fanPosition = -1;
            // Authoritative chart-local coordinate. This is the unique
            // rawAngle + liftTurn * 2pi representative inside the validated
            // source-entity wedge.
            double angle = 0.0;
            double rawAngle = 0.0;
            int liftTurn = 0;
            double leftScore = 0.0;
            std::vector<SurfaceCellCanonicalIdentity> fanIdentities;
          };

          std::vector<BoundaryFanSector> sectors;
          sectors.reserve(localOutgoing.size());
          const int exteriorLoop = authoritativeBoundaryLoop
              [static_cast<std::size_t>(exteriorIncoming)];
          if (exteriorLoop < 0 ||
              exteriorLoop >=
                  static_cast<int>(sourceBoundaryTopology.loops.size()) ||
              exteriorTwin < 0 ||
              !std::binary_search(localOutgoing.begin(), localOutgoing.end(),
                                  exteriorTwin) ||
              !std::binary_search(localOutgoing.begin(), localOutgoing.end(),
                                  exteriorOutgoing)) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::
                    ExteriorPairMismatch,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }
          sectors.push_back(
              {exteriorIncoming, exteriorTwin, exteriorOutgoing,
               sourceBoundaryTopology
                   .loops[static_cast<std::size_t>(exteriorLoop)]
                   .canonicalIdentity,
               {}, -1, 0.0, 0.0, 0.0, 0.0, true, false});

          const auto is_authoritative_source_rail =
              [&](const int outgoingRay) {
                if (outgoingRay < 0 ||
                    outgoingRay >= static_cast<int>(complex.halfedges.size()) ||
                    boundaryWitnesses[static_cast<std::size_t>(outgoingRay)]
                        .valid) {
                  return false;
                }
                const SurfaceArrangementHalfedge &halfedge =
                    complex.halfedges[static_cast<std::size_t>(outgoingRay)];
                return halfedge.hardFeature &&
                       std::any_of(
                           halfedge.provenance.begin(),
                           halfedge.provenance.end(),
                           [](const SurfaceArrangementProvenance &entry) {
                             return entry.sourceArc < 0 && entry.family < 0 &&
                                    entry.hardFeature;
                           });
              };

          struct CanonicalFanPairKey {
            int incoming = -1;
            int sourceRay = -1;
            int target = -1;

            bool operator<(const CanonicalFanPairKey &other) const {
              return std::tie(incoming, sourceRay, target) <
                     std::tie(other.incoming, other.sourceRay, other.target);
            }
          };
          struct PairLocalIntervalDiagnosticContext {
            SurfaceCellProjectionChart chart;
            std::vector<std::int64_t> canonicalEntityKey;
            int transitionRoot = -1;
            int identityCount = 0;
            int sourcePosition = -1;
            int targetPosition = -1;
            double sourceRawAngle =
                std::numeric_limits<double>::quiet_NaN();
            double targetRawAngle =
                std::numeric_limits<double>::quiet_NaN();
            double sourceLiftedAngle =
                std::numeric_limits<double>::quiet_NaN();
            double targetLiftedAngle =
                std::numeric_limits<double>::quiet_NaN();
            int sourceLiftTurn = 0;
            int targetLiftTurn = 0;
            int liftTurnDifference = 0;
            double wedgeStart = std::numeric_limits<double>::quiet_NaN();
            double wedgeEnd = std::numeric_limits<double>::quiet_NaN();
            double wedgeSpan = std::numeric_limits<double>::quiet_NaN();
            int intrudingHalfedge = -1;
            SurfaceCellCanonicalIdentity identity;
            SurfaceCellCanonicalIdentity intrudingIdentity;
          };
          const auto record_pair_interval_failure =
              [&](const SurfaceArrangementIntervalFailure failure,
                  const CanonicalFanPairKey &key,
                  const PairLocalIntervalDiagnosticContext &context) {
                if (complex.diagnostics.boundaryFanIntervalFailure ==
                    SurfaceArrangementIntervalFailure::None) {
                  complex.diagnostics.boundaryFanIntervalFailure = failure;
                  complex.diagnostics.boundaryFanIntervalSourceComponent =
                      context.chart.sourceComponent;
                  complex.diagnostics.boundaryFanIntervalSourceFace =
                      context.chart.sourceFace;
                  complex.diagnostics.boundaryFanIntervalSourceSheet =
                      context.chart.localSheet;
                  complex.diagnostics.boundaryFanIntervalEntityKey =
                      context.canonicalEntityKey;
                  complex.diagnostics.boundaryFanIntervalTransitionRoot =
                      context.transitionRoot;
                  complex.diagnostics.boundaryFanIntervalIdentityCount =
                      context.identityCount;
                  complex.diagnostics.boundaryFanIntervalSourcePosition =
                      context.sourcePosition;
                  complex.diagnostics.boundaryFanIntervalTargetPosition =
                      context.targetPosition;
                  complex.diagnostics.boundaryFanIntervalSourceRawAngle =
                      context.sourceRawAngle;
                  complex.diagnostics.boundaryFanIntervalTargetRawAngle =
                      context.targetRawAngle;
                  complex.diagnostics.boundaryFanIntervalSourceLiftedAngle =
                      context.sourceLiftedAngle;
                  complex.diagnostics.boundaryFanIntervalTargetLiftedAngle =
                      context.targetLiftedAngle;
                  complex.diagnostics.boundaryFanIntervalSourceLiftTurn =
                      context.sourceLiftTurn;
                  complex.diagnostics.boundaryFanIntervalTargetLiftTurn =
                      context.targetLiftTurn;
                  complex.diagnostics.boundaryFanIntervalLiftTurnDifference =
                      context.liftTurnDifference;
                  complex.diagnostics.boundaryFanIntervalWedgeStart =
                      context.wedgeStart;
                  complex.diagnostics.boundaryFanIntervalWedgeEnd =
                      context.wedgeEnd;
                  complex.diagnostics.boundaryFanIntervalWedgeSpan =
                      context.wedgeSpan;
                  complex.diagnostics.boundaryFanIntervalIntrudingHalfedge =
                      context.intrudingHalfedge;
                  complex.diagnostics.boundaryFanIntervalIdentity =
                      context.identity;
                  complex.diagnostics.boundaryFanIntervalIntrudingIdentity =
                      context.intrudingIdentity;
                }
                record_boundary_fan_conflict(
                    SurfaceArrangementBoundaryFanConflict::
                        InvalidOrientedInterval,
                    node, key.incoming, key.sourceRay, key.target);
              };
          const auto combined_pair_fan_identity =
              [](const std::vector<SurfaceCellCanonicalIdentity> &identities) {
                SurfaceCellCanonicalIdentity combined;
                if (identities.empty()) {
                  return combined;
                }
                combined.valid = true;
                combined.values.push_back(0x5041495246414eLL);
                combined.values.push_back(
                    static_cast<std::int64_t>(identities.size()));
                for (const SurfaceCellCanonicalIdentity &identity :
                     identities) {
                  combined.values.push_back(
                      static_cast<std::int64_t>(identity.values.size()));
                  combined.values.insert(combined.values.end(),
                                         identity.values.begin(),
                                         identity.values.end());
                }
                return combined;
              };
          struct CanonicalFanPairRecord {
            CanonicalFanPairKey key;
            std::vector<std::int64_t> canonicalEntityKey;
            // Non-exterior pairs require one exact common root. The excluded
            // exterior continuation instead retains endpoint-specific chart
            // roots because an authoritative hard rail may separate its two
            // incident boundary-side charts.
            int transitionRoot = -1;
            std::vector<SurfaceCellCanonicalIdentity> fanIdentities;
            SurfaceCellCanonicalIdentity sourceBoundaryIdentity;
            bool exterior = false;
            bool cyclicWrap = false;
            SurfaceCellProjectionChart exteriorSourceChart;
            SurfaceCellProjectionChart exteriorTargetChart;
            int exteriorSourceRoot = -1;
            int exteriorTargetRoot = -1;
            int exteriorSourceSide = 0;
            int exteriorTargetSide = 0;
            std::vector<SurfaceCellCanonicalIdentity>
                exteriorSourceFanIdentities;
            std::vector<SurfaceCellCanonicalIdentity>
                exteriorTargetFanIdentities;
          };

          std::vector<BoundaryFanSector> interiorSectors;
          std::map<CanonicalFanPairKey, CanonicalFanPairRecord>
              canonicalPairInventory;
          std::map<CanonicalFanPairKey, std::vector<BoundaryFanSector>>
              candidatesByPair;
          constexpr double cornerAngleTolerance = 1.0e-10;

          const auto canonical_entity_key = [](
                                                const SurfaceCellCanonicalIdentity
                                                    &identity) {
            std::vector<std::int64_t> key = identity.values;
            if (key.empty()) {
              return std::vector<std::int64_t>{};
            }
            const auto kind = static_cast<SourceEntityKind>(key.front());
            if ((kind == SourceEntityKind::SourceVertex ||
                 kind == SourceEntityKind::SourceEdge) &&
                key.size() >= 2U) {
              key.pop_back();
            }
            return key;
          };
          const auto ray_transition_roots = [&](const DirectedWedgeRay &ray) {
            std::set<int> roots;
            for (const DirectedWedgeWitness &witness : ray.witnesses) {
              if (witness.kind != SourceEntityKind::SourceVertex &&
                  witness.kind != SourceEntityKind::SourceEdge) {
                continue;
              }
              const SurfaceCellProjectionChart chart{
                  witness.sourceComponent, witness.sourceFace,
                  witness.sourceSheet};
              const int root =
                  chart.valid()
                      ? transitionGraph.chart_component(SourceProjectionChart{
                            chart.sourceComponent, chart.localSheet,
                            chart.sourceFace})
                      : -1;
              if (root >= 0) {
                roots.insert(root);
              }
            }
            return roots;
          };

          struct BoundaryAuthoritativeRayProjection {
            bool valid = false;
            SurfaceCellProjectionChart chart;
            std::vector<std::int64_t> canonicalEntityKey;
            int transitionRoot = -1;
            int sourceBoundaryLoop = -1;
            int side = 0;
          };
          const auto project_boundary_authoritative_ray =
              [&](const int outgoingRay,
                  const BoundarySubsegmentWitness &boundaryWitness) {
                BoundaryAuthoritativeRayProjection projection;
                if (!boundaryWitness.valid ||
                    boundaryWitness.halfedge != outgoingRay ||
                    boundaryWitness.sourceFace < 0 ||
                    boundaryWitness.sourceFace >= faces.rows() ||
                    boundaryWitness.sourceComponent < 0 ||
                    boundaryWitness.sourceSheet < 0) {
                  return projection;
                }
                projection.chart = {boundaryWitness.sourceComponent,
                                    boundaryWitness.sourceFace,
                                    boundaryWitness.sourceSheet};
                if (!projection.chart.valid() ||
                    resolvedComponents[static_cast<std::size_t>(
                        boundaryWitness.sourceFace)] !=
                        projection.chart.sourceComponent ||
                    resolvedSheets[static_cast<std::size_t>(
                        boundaryWitness.sourceFace)] !=
                        projection.chart.localSheet) {
                  return projection;
                }
                SurfacePoint nodePoint;
                if (!node_point_on_chart(node, projection.chart, nodePoint)) {
                  return projection;
                }
                const SourceEntityId entity =
                    transitionGraph.resolve_entity(nodePoint);
                if (!entity.valid() ||
                    (entity.kind != SourceEntityKind::SourceVertex &&
                     entity.kind != SourceEntityKind::SourceEdge)) {
                  return projection;
                }
                projection.canonicalEntityKey =
                    canonical_entity_key(entity.canonical);
                projection.transitionRoot = transitionGraph.chart_component(
                    SourceProjectionChart{projection.chart.sourceComponent,
                                  projection.chart.localSheet,
                                  projection.chart.sourceFace});
                projection.sourceBoundaryLoop = boundaryWitness.loop;
                projection.side = boundaryWitness.side;
                projection.valid =
                    !projection.canonicalEntityKey.empty() &&
                    projection.transitionRoot >= 0 &&
                    projection.sourceBoundaryLoop >= 0 &&
                    projection.side != 0;
                return projection;
              };

          struct BoundaryRayProvenanceReconciliation {
            std::vector<SurfaceCellCanonicalIdentity> agreeingIdentities;
            bool contradictoryBoundaryClaim = false;
          };
          const auto reconcile_boundary_ray_provenance =
              [&](const int outgoingRay,
                  const BoundaryAuthoritativeRayProjection &projection) {
                BoundaryRayProvenanceReconciliation reconciliation;
                for (const auto &[fanIdentity, fanRays] : nodeWedges) {
                  if (!fanIdentity.valid) {
                    continue;
                  }
                  const auto rayFound = std::find_if(
                      fanRays.begin(), fanRays.end(),
                      [&](const DirectedWedgeRay &ray) {
                        return ray.halfedge == outgoingRay;
                      });
                  if (rayFound == fanRays.end()) {
                    continue;
                  }
                  const std::vector<std::int64_t> entityKey =
                      canonical_entity_key(fanIdentity);
                  for (const DirectedWedgeWitness &witness :
                       rayFound->witnesses) {
                    const SurfaceCellProjectionChart witnessChart{
                        witness.sourceComponent, witness.sourceFace,
                        witness.sourceSheet};
                    if (witnessChart != projection.chart) {
                      continue;
                    }
                    const int witnessRoot = transitionGraph.chart_component(
                        SourceProjectionChart{witness.sourceComponent,
                                      witness.sourceSheet,
                                      witness.sourceFace});
                    if (entityKey != projection.canonicalEntityKey ||
                        witnessRoot != projection.transitionRoot) {
                      reconciliation.contradictoryBoundaryClaim = true;
                      continue;
                    }
                    reconciliation.agreeingIdentities.push_back(fanIdentity);
                  }
                }
                std::sort(reconciliation.agreeingIdentities.begin(),
                          reconciliation.agreeingIdentities.end());
                reconciliation.agreeingIdentities.erase(
                    std::unique(reconciliation.agreeingIdentities.begin(),
                                reconciliation.agreeingIdentities.end()),
                    reconciliation.agreeingIdentities.end());
                return reconciliation;
              };

          const CanonicalFanPairKey exteriorPairKey{
              exteriorIncoming, exteriorTwin, exteriorOutgoing};
          const SurfaceCellCanonicalIdentity exteriorBoundaryIdentity =
              sourceBoundaryTopology
                  .loops[static_cast<std::size_t>(exteriorLoop)]
                  .canonicalIdentity;
          const BoundarySubsegmentWitness &exteriorSourceWitness =
              boundaryWitnesses[static_cast<std::size_t>(exteriorTwin)];
          const BoundarySubsegmentWitness &exteriorTargetWitness =
              boundaryWitnesses[static_cast<std::size_t>(exteriorOutgoing)];
          if (!exteriorBoundaryIdentity.valid ||
              !exteriorSourceWitness.valid ||
              !exteriorTargetWitness.valid ||
              exteriorSourceWitness.loop != exteriorLoop ||
              exteriorTargetWitness.loop != exteriorLoop ||
              exteriorSourceWitness.side != 1 ||
              exteriorTargetWitness.side != -1) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::ExteriorPairMismatch,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }

          const BoundaryAuthoritativeRayProjection exteriorSourceProjection =
              project_boundary_authoritative_ray(exteriorTwin,
                                                 exteriorSourceWitness);
          const BoundaryAuthoritativeRayProjection exteriorTargetProjection =
              project_boundary_authoritative_ray(exteriorOutgoing,
                                                 exteriorTargetWitness);
          if (!exteriorSourceProjection.valid ||
              !exteriorTargetProjection.valid ||
              exteriorSourceProjection.sourceBoundaryLoop != exteriorLoop ||
              exteriorTargetProjection.sourceBoundaryLoop != exteriorLoop ||
              exteriorSourceProjection.side != 1 ||
              exteriorTargetProjection.side != -1 ||
              exteriorSourceProjection.canonicalEntityKey !=
                  exteriorTargetProjection.canonicalEntityKey) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::ExteriorPairMismatch,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }

          const BoundaryRayProvenanceReconciliation
              exteriorSourceProvenance = reconcile_boundary_ray_provenance(
                  exteriorTwin, exteriorSourceProjection);
          const BoundaryRayProvenanceReconciliation
              exteriorTargetProvenance = reconcile_boundary_ray_provenance(
                  exteriorOutgoing, exteriorTargetProjection);
          if (exteriorSourceProvenance.contradictoryBoundaryClaim ||
              exteriorTargetProvenance.contradictoryBoundaryClaim ||
              exteriorSourceProvenance.agreeingIdentities.empty() ||
              exteriorTargetProvenance.agreeingIdentities.empty()) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::ExteriorPairMismatch,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }
          std::vector<SurfaceCellCanonicalIdentity> exteriorFanIdentities =
              exteriorSourceProvenance.agreeingIdentities;
          exteriorFanIdentities.insert(
              exteriorFanIdentities.end(),
              exteriorTargetProvenance.agreeingIdentities.begin(),
              exteriorTargetProvenance.agreeingIdentities.end());
          std::sort(exteriorFanIdentities.begin(),
                    exteriorFanIdentities.end());
          exteriorFanIdentities.erase(
              std::unique(exteriorFanIdentities.begin(),
                          exteriorFanIdentities.end()),
              exteriorFanIdentities.end());
          CanonicalFanPairRecord exteriorPairRecord;
          exteriorPairRecord.key = exteriorPairKey;
          exteriorPairRecord.canonicalEntityKey =
              exteriorSourceProjection.canonicalEntityKey;
          exteriorPairRecord.transitionRoot = -1;
          exteriorPairRecord.fanIdentities = exteriorFanIdentities;
          exteriorPairRecord.sourceBoundaryIdentity =
              exteriorBoundaryIdentity;
          exteriorPairRecord.exterior = true;
          exteriorPairRecord.cyclicWrap = false;
          exteriorPairRecord.exteriorSourceChart =
              exteriorSourceProjection.chart;
          exteriorPairRecord.exteriorTargetChart =
              exteriorTargetProjection.chart;
          exteriorPairRecord.exteriorSourceRoot =
              exteriorSourceProjection.transitionRoot;
          exteriorPairRecord.exteriorTargetRoot =
              exteriorTargetProjection.transitionRoot;
          exteriorPairRecord.exteriorSourceSide =
              exteriorSourceProjection.side;
          exteriorPairRecord.exteriorTargetSide =
              exteriorTargetProjection.side;
          exteriorPairRecord.exteriorSourceFanIdentities =
              exteriorSourceProvenance.agreeingIdentities;
          exteriorPairRecord.exteriorTargetFanIdentities =
              exteriorTargetProvenance.agreeingIdentities;
          canonicalPairInventory.emplace(exteriorPairKey,
                                         std::move(exteriorPairRecord));

          // Build one node-level canonical pair inventory before chart-corner
          // filtering. Equivalent fan records may contribute provenance to one
          // directed key, but conflicting normalized source entities or
          // transition roots fail closed rather than selecting a subset.
          for (const auto &[fanIdentity, fanRays] : nodeWedges) {
            if (!fanIdentity.valid || fanRays.size() < 2U) {
              continue;
            }
            const std::vector<std::int64_t> entityKey =
                canonical_entity_key(fanIdentity);
            if (entityKey.empty()) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::MissingCanonicalPair,
                  node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
              break;
            }
            for (std::size_t targetIndex = 0; targetIndex < fanRays.size();
                 ++targetIndex) {
              const std::size_t sourceIndex =
                  (targetIndex + 1U) % fanRays.size();
              const DirectedWedgeRay &source = fanRays[sourceIndex];
              const DirectedWedgeRay &target = fanRays[targetIndex];
              if (source.halfedge < 0 || target.halfedge < 0 ||
                  source.halfedge >=
                      static_cast<int>(complex.halfedges.size()) ||
                  target.halfedge >=
                      static_cast<int>(complex.halfedges.size()) ||
                  source.halfedge == target.halfedge) {
                record_boundary_fan_conflict(
                    SurfaceArrangementBoundaryFanConflict::
                        MissingCanonicalPair,
                    node, -1, source.halfedge, target.halfedge);
                break;
              }
              const int incoming =
                  complex.halfedges[static_cast<std::size_t>(source.halfedge)]
                      .twin;
              if (incoming < 0 ||
                  incoming >= static_cast<int>(complex.halfedges.size()) ||
                  complex.halfedges[static_cast<std::size_t>(incoming)].to !=
                      node) {
                record_boundary_fan_conflict(
                    SurfaceArrangementBoundaryFanConflict::
                        MissingCanonicalPair,
                    node, incoming, source.halfedge, target.halfedge);
                break;
              }

              const CanonicalFanPairKey key{incoming, source.halfedge,
                                            target.halfedge};

              // The excluded exterior continuation is authoritative before
              // generic fan enumeration. Reconcile each endpoint against its
              // independently projected boundary chart/root/side rather than
              // forcing the two sides to share one transition root.
              if (!(key < exteriorPairKey) &&
                  !(exteriorPairKey < key)) {
                auto exteriorFound = canonicalPairInventory.find(key);
                if (exteriorFound == canonicalPairInventory.end() ||
                    !exteriorFound->second.exterior) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          ExteriorPairMismatch,
                      node, incoming, source.halfedge, target.halfedge);
                  break;
                }
                CanonicalFanPairRecord &record = exteriorFound->second;
                const BoundarySubsegmentWitness &sourceBoundary =
                    boundaryWitnesses[static_cast<std::size_t>(
                        source.halfedge)];
                const BoundarySubsegmentWitness &targetBoundary =
                    boundaryWitnesses[static_cast<std::size_t>(
                        target.halfedge)];
                if (!sourceBoundary.valid || !targetBoundary.valid ||
                    sourceBoundary.loop != exteriorLoop ||
                    targetBoundary.loop != exteriorLoop ||
                    sourceBoundary.side != 1 ||
                    targetBoundary.side != -1 ||
                    record.sourceBoundaryIdentity !=
                        exteriorBoundaryIdentity ||
                    record.canonicalEntityKey !=
                        exteriorSourceProjection.canonicalEntityKey ||
                    record.exteriorSourceChart !=
                        exteriorSourceProjection.chart ||
                    record.exteriorTargetChart !=
                        exteriorTargetProjection.chart ||
                    record.exteriorSourceRoot !=
                        exteriorSourceProjection.transitionRoot ||
                    record.exteriorTargetRoot !=
                        exteriorTargetProjection.transitionRoot ||
                    record.exteriorSourceSide != 1 ||
                    record.exteriorTargetSide != -1) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          ExteriorPairMismatch,
                      node, incoming, source.halfedge, target.halfedge);
                  break;
                }

                const auto reconcile_endpoint_claim =
                    [&](const DirectedWedgeRay &ray,
                        const BoundaryAuthoritativeRayProjection &projection) {
                      std::pair<bool, bool> result{false, false};
                      for (const DirectedWedgeWitness &witness :
                           ray.witnesses) {
                        if (witness.kind !=
                                SourceEntityKind::SourceVertex &&
                            witness.kind != SourceEntityKind::SourceEdge) {
                          continue;
                        }
                        const SurfaceCellProjectionChart witnessChart{
                            witness.sourceComponent, witness.sourceFace,
                            witness.sourceSheet};
                        if (witnessChart != projection.chart) {
                          continue;
                        }
                        const int witnessRoot =
                            transitionGraph.chart_component(SourceProjectionChart{
                                witness.sourceComponent,
                                witness.sourceSheet,
                                witness.sourceFace});
                        if (entityKey != projection.canonicalEntityKey ||
                            witnessRoot != projection.transitionRoot) {
                          result.second = true;
                        } else {
                          result.first = true;
                        }
                      }
                      return result;
                    };
                const auto [sourceAgrees, sourceContradicts] =
                    reconcile_endpoint_claim(source,
                                             exteriorSourceProjection);
                const auto [targetAgrees, targetContradicts] =
                    reconcile_endpoint_claim(target,
                                             exteriorTargetProjection);
                if (sourceContradicts || targetContradicts) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          ExteriorPairMismatch,
                      node, incoming, source.halfedge, target.halfedge);
                  break;
                }
                if (sourceAgrees && targetAgrees) {
                  record.fanIdentities.push_back(fanIdentity);
                  record.exteriorSourceFanIdentities.push_back(fanIdentity);
                  record.exteriorTargetFanIdentities.push_back(fanIdentity);
                }
                // A membership on an unrelated chart is not exterior
                // authority and must not veto or replace the projected pair.
                continue;
              }

              const std::set<int> sourceRoots =
                  ray_transition_roots(source);
              const std::set<int> targetRoots =
                  ray_transition_roots(target);
              std::set<int> commonRoots;
              std::set_intersection(sourceRoots.begin(), sourceRoots.end(),
                                    targetRoots.begin(), targetRoots.end(),
                                    std::inserter(commonRoots,
                                                  commonRoots.end()));
              if (commonRoots.size() != 1U) {
                record_boundary_fan_conflict(
                    SurfaceArrangementBoundaryFanConflict::
                        TransitionRootMismatch,
                    node, incoming, source.halfedge, target.halfedge);
                break;
              }

              const int transitionRoot = *commonRoots.begin();
              auto [found, inserted] = canonicalPairInventory.emplace(
                  key, CanonicalFanPairRecord{key, entityKey, transitionRoot,
                                              {fanIdentity}, {}, false,
                                              false});
              if (!inserted) {
                CanonicalFanPairRecord &record = found->second;
                if (record.exterior) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          ExteriorPairMismatch,
                      node, incoming, source.halfedge, target.halfedge);
                  break;
                }
                if (record.canonicalEntityKey != entityKey) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          NormalizedChartEntityMismatch,
                      node, incoming, source.halfedge, target.halfedge);
                  break;
                }
                if (record.transitionRoot != transitionRoot) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          TransitionRootMismatch,
                      node, incoming, source.halfedge, target.halfedge);
                  break;
                }
                record.fanIdentities.push_back(fanIdentity);
              }
            }
            if (!directedIncidenceValid) {
              break;
            }
          }
          if (!directedIncidenceValid) {
            break;
          }
          for (auto &[key, record] : canonicalPairInventory) {
            (void)key;
            std::sort(record.fanIdentities.begin(),
                      record.fanIdentities.end());
            record.fanIdentities.erase(
                std::unique(record.fanIdentities.begin(),
                            record.fanIdentities.end()),
                record.fanIdentities.end());
            if (record.exterior) {
              std::sort(record.exteriorSourceFanIdentities.begin(),
                        record.exteriorSourceFanIdentities.end());
              record.exteriorSourceFanIdentities.erase(
                  std::unique(record.exteriorSourceFanIdentities.begin(),
                              record.exteriorSourceFanIdentities.end()),
                  record.exteriorSourceFanIdentities.end());
              std::sort(record.exteriorTargetFanIdentities.begin(),
                        record.exteriorTargetFanIdentities.end());
              record.exteriorTargetFanIdentities.erase(
                  std::unique(record.exteriorTargetFanIdentities.begin(),
                              record.exteriorTargetFanIdentities.end()),
                  record.exteriorTargetFanIdentities.end());
            }
            if (record.fanIdentities.empty() ||
                (record.exterior &&
                 (record.exteriorSourceFanIdentities.empty() ||
                  record.exteriorTargetFanIdentities.empty()))) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::MissingCanonicalPair,
                  node, record.key.incoming, record.key.sourceRay,
                  record.key.target);
              break;
            }
          }
          if (!directedIncidenceValid) {
            break;
          }

          const auto exteriorRecord =
              canonicalPairInventory.find(exteriorPairKey);
          if (exteriorRecord == canonicalPairInventory.end() ||
              !exteriorRecord->second.exterior ||
              exteriorRecord->second.sourceBoundaryIdentity !=
                  exteriorBoundaryIdentity ||
              exteriorRecord->second.canonicalEntityKey !=
                  exteriorSourceProjection.canonicalEntityKey ||
              exteriorRecord->second.exteriorSourceChart !=
                  exteriorSourceProjection.chart ||
              exteriorRecord->second.exteriorTargetChart !=
                  exteriorTargetProjection.chart ||
              exteriorRecord->second.exteriorSourceRoot !=
                  exteriorSourceProjection.transitionRoot ||
              exteriorRecord->second.exteriorTargetRoot !=
                  exteriorTargetProjection.transitionRoot ||
              exteriorRecord->second.exteriorSourceSide != 1 ||
              exteriorRecord->second.exteriorTargetSide != -1 ||
              exteriorRecord->second.exteriorSourceFanIdentities.empty() ||
              exteriorRecord->second.exteriorTargetFanIdentities.empty()) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::ExteriorPairMismatch,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }

          struct IdentityPairChartEvidence {
            SurfaceCellCanonicalIdentity identity;
            SurfaceCellProjectionChart chart;
            std::map<int, DirectedWedgeWitness> rays;
          };
          struct PairLocalRayEvidence {
            DirectedWedgeWitness witness;
            std::vector<SurfaceCellCanonicalIdentity> identities;
          };

          // Resolve interval geometry independently for every already-owned
          // non-exterior canonical pair. Only the complete exact identity set
          // recorded on that pair may contribute rays. Unrelated node/chart
          // memberships remain available for their own pairs but cannot
          // intrude here.
          for (const auto &[key, record] : canonicalPairInventory) {
            if (record.exterior) {
              continue;
            }

            PairLocalIntervalDiagnosticContext context;
            context.canonicalEntityKey = record.canonicalEntityKey;
            context.transitionRoot = record.transitionRoot;
            context.identityCount =
                static_cast<int>(record.fanIdentities.size());
            if (record.fanIdentities.empty()) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingFanIdentity, key,
                  context);
              break;
            }

            bool commonChartSet = false;
            SurfaceCellProjectionChart commonChart;
            std::vector<IdentityPairChartEvidence> identityEvidence;
            identityEvidence.reserve(record.fanIdentities.size());

            for (const SurfaceCellCanonicalIdentity &identity :
                 record.fanIdentities) {
              context.identity = identity;
              if (!identity.valid) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingFanIdentity,
                    key, context);
                break;
              }
              const auto fanFound = nodeWedges.find(identity);
              if (fanFound == nodeWedges.end()) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingIdentityWedge,
                    key, context);
                break;
              }
              if (canonical_entity_key(identity) !=
                  record.canonicalEntityKey) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::EntityMismatch, key,
                    context);
                break;
              }

              const std::vector<DirectedWedgeRay> &fanRays =
                  fanFound->second;
              const DirectedWedgeRay *sourceFanRay = nullptr;
              const DirectedWedgeRay *targetFanRay = nullptr;
              int directedPairCount = 0;
              for (std::size_t targetIndex = 0;
                   targetIndex < fanRays.size(); ++targetIndex) {
                const std::size_t sourceIndex =
                    (targetIndex + 1U) % fanRays.size();
                if (fanRays[targetIndex].halfedge == key.target) {
                  targetFanRay = &fanRays[targetIndex];
                }
                if (fanRays[sourceIndex].halfedge == key.sourceRay) {
                  sourceFanRay = &fanRays[sourceIndex];
                }
                if (fanRays[sourceIndex].halfedge == key.sourceRay &&
                    fanRays[targetIndex].halfedge == key.target) {
                  ++directedPairCount;
                }
              }
              if (sourceFanRay == nullptr) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingSourceRay, key,
                    context);
                break;
              }
              if (targetFanRay == nullptr) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingTargetRay, key,
                    context);
                break;
              }
              if (directedPairCount == 0) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::
                        MissingDirectedProvenance,
                    key, context);
                break;
              }
              if (directedPairCount != 1) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::
                        IdentityIntervalConflict,
                    key, context);
                break;
              }

              std::set<SurfaceCellProjectionChart> candidateCharts;
              bool sawSharedChart = false;
              bool sawEntityMatch = false;
              bool sawRootMatch = false;
              SurfaceCellProjectionChart firstSharedChart;
              for (const DirectedWedgeWitness &sourceWitness :
                   sourceFanRay->witnesses) {
                if (sourceWitness.kind != SourceEntityKind::SourceVertex &&
                    sourceWitness.kind != SourceEntityKind::SourceEdge) {
                  continue;
                }
                const SurfaceCellProjectionChart sourceChart{
                    sourceWitness.sourceComponent, sourceWitness.sourceFace,
                    sourceWitness.sourceSheet};
                if (!sourceChart.valid()) {
                  continue;
                }
                for (const DirectedWedgeWitness &targetWitness :
                     targetFanRay->witnesses) {
                  if (targetWitness.kind != SourceEntityKind::SourceVertex &&
                      targetWitness.kind != SourceEntityKind::SourceEdge) {
                    continue;
                  }
                  const SurfaceCellProjectionChart targetChart{
                      targetWitness.sourceComponent,
                      targetWitness.sourceFace,
                      targetWitness.sourceSheet};
                  if (sourceChart != targetChart) {
                    continue;
                  }
                  if (!sawSharedChart) {
                    firstSharedChart = sourceChart;
                  }
                  sawSharedChart = true;
                  SurfacePoint nodePoint;
                  if (!node_point_on_chart(node, sourceChart, nodePoint)) {
                    continue;
                  }
                  const SourceEntityId entity =
                      transitionGraph.resolve_entity(nodePoint);
                  if (!entity.valid() ||
                      (entity.kind != SourceEntityKind::SourceVertex &&
                       entity.kind != SourceEntityKind::SourceEdge) ||
                      sourceWitness.kind != entity.kind ||
                      targetWitness.kind != entity.kind ||
                      canonical_entity_key(entity.canonical) !=
                          record.canonicalEntityKey) {
                    continue;
                  }
                  sawEntityMatch = true;
                  const int root = transitionGraph.chart_component(
                      SourceProjectionChart{sourceChart.sourceComponent,
                                    sourceChart.localSheet,
                                    sourceChart.sourceFace});
                  if (root != record.transitionRoot) {
                    continue;
                  }
                  sawRootMatch = true;
                  candidateCharts.insert(sourceChart);
                }
              }

              if (candidateCharts.empty()) {
                context.chart = firstSharedChart;
                SurfaceArrangementIntervalFailure failure =
                    SurfaceArrangementIntervalFailure::MissingChartWitness;
                if (sawSharedChart && !sawEntityMatch) {
                  failure =
                      SurfaceArrangementIntervalFailure::EntityMismatch;
                } else if (sawEntityMatch && !sawRootMatch) {
                  failure = SurfaceArrangementIntervalFailure::RootMismatch;
                }
                record_pair_interval_failure(failure, key, context);
                break;
              }
              if (candidateCharts.size() != 1U) {
                context.chart = *candidateCharts.begin();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::
                        IdentityIntervalConflict,
                    key, context);
                break;
              }
              const SurfaceCellProjectionChart identityChart =
                  *candidateCharts.begin();
              context.chart = identityChart;
              if (!commonChartSet) {
                commonChart = identityChart;
                commonChartSet = true;
              } else if (commonChart != identityChart) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::
                        IdentityIntervalConflict,
                    key, context);
                break;
              }

              SurfacePoint nodePoint;
              if (!node_point_on_chart(node, identityChart, nodePoint)) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingChartWitness,
                    key, context);
                break;
              }
              const SourceEntityId identityEntity =
                  transitionGraph.resolve_entity(nodePoint);
              if (!identityEntity.valid() ||
                  canonical_entity_key(identityEntity.canonical) !=
                      record.canonicalEntityKey) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::EntityMismatch, key,
                    context);
                break;
              }

              IdentityPairChartEvidence evidence;
              evidence.identity = identity;
              evidence.chart = identityChart;
              for (const DirectedWedgeRay &ray : fanRays) {
                const DirectedWedgeWitness *selectedWitness = nullptr;
                for (const DirectedWedgeWitness &witness : ray.witnesses) {
                  const SurfaceCellProjectionChart witnessChart{
                      witness.sourceComponent, witness.sourceFace,
                      witness.sourceSheet};
                  if (witnessChart != identityChart ||
                      witness.kind != identityEntity.kind) {
                    continue;
                  }
                  const int witnessRoot = transitionGraph.chart_component(
                      SourceProjectionChart{witness.sourceComponent,
                                    witness.sourceSheet,
                                    witness.sourceFace});
                  if (witnessRoot != record.transitionRoot) {
                    continue;
                  }
                  if (selectedWitness != nullptr &&
                      (selectedWitness->kind != witness.kind ||
                       std::abs(selectedWitness->localParameter -
                                witness.localParameter) > 1.0e-10 ||
                       std::abs(selectedWitness->leftScore -
                                witness.leftScore) > 1.0e-10)) {
                    record_pair_interval_failure(
                        SurfaceArrangementIntervalFailure::
                            IdentityIntervalConflict,
                        key, context);
                    break;
                  }
                  selectedWitness = &witness;
                }
                if (!directedIncidenceValid) {
                  break;
                }
                if (selectedWitness != nullptr &&
                    !evidence.rays.emplace(ray.halfedge, *selectedWitness)
                         .second) {
                  record_pair_interval_failure(
                      SurfaceArrangementIntervalFailure::
                          IdentityIntervalConflict,
                      key, context);
                  break;
                }
              }
              if (!directedIncidenceValid) {
                break;
              }
              if (evidence.rays.count(key.sourceRay) != 1U) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingSourceRay, key,
                    context);
                break;
              }
              if (evidence.rays.count(key.target) != 1U) {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingTargetRay, key,
                    context);
                break;
              }
              identityEvidence.push_back(std::move(evidence));
            }
            if (!directedIncidenceValid) {
              break;
            }
            if (!commonChartSet ||
                identityEvidence.size() != record.fanIdentities.size()) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingChartWitness, key,
                  context);
              break;
            }

            context.chart = commonChart;
            std::map<int, PairLocalRayEvidence> pairLocalRays;
            for (const IdentityPairChartEvidence &evidence :
                 identityEvidence) {
              for (const auto &[halfedge, witness] : evidence.rays) {
                auto [found, inserted] = pairLocalRays.emplace(
                    halfedge,
                    PairLocalRayEvidence{witness, {evidence.identity}});
                if (!inserted) {
                  const DirectedWedgeWitness &existing =
                      found->second.witness;
                  if (existing.kind != witness.kind ||
                      existing.sourceComponent != witness.sourceComponent ||
                      existing.sourceFace != witness.sourceFace ||
                      existing.sourceSheet != witness.sourceSheet ||
                      std::abs(existing.localParameter -
                               witness.localParameter) > 1.0e-10 ||
                      std::abs(existing.leftScore - witness.leftScore) >
                          1.0e-10) {
                    context.identity = evidence.identity;
                    record_pair_interval_failure(
                        SurfaceArrangementIntervalFailure::
                            IdentityIntervalConflict,
                        key, context);
                    break;
                  }
                  found->second.identities.push_back(evidence.identity);
                  std::sort(found->second.identities.begin(),
                            found->second.identities.end());
                  found->second.identities.erase(
                      std::unique(found->second.identities.begin(),
                                  found->second.identities.end()),
                      found->second.identities.end());
                }
              }
              if (!directedIncidenceValid) {
                break;
              }
            }
            if (!directedIncidenceValid) {
              break;
            }

            SurfacePoint nodePoint;
            if (!node_point_on_chart(node, commonChart, nodePoint)) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingChartWitness, key,
                  context);
              break;
            }
            const SourceEntityId entity =
                transitionGraph.resolve_entity(nodePoint);
            if (!entity.valid() ||
                (entity.kind != SourceEntityKind::SourceVertex &&
                 entity.kind != SourceEntityKind::SourceEdge) ||
                canonical_entity_key(entity.canonical) !=
                    record.canonicalEntityKey) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::EntityMismatch, key,
                  context);
              break;
            }
            const int root = transitionGraph.chart_component(SourceProjectionChart{
                commonChart.sourceComponent, commonChart.localSheet,
                commonChart.sourceFace});
            if (root != record.transitionRoot) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::RootMismatch, key,
                  context);
              break;
            }

            int startCorner = -1;
            int endCorner = -1;
            if (entity.kind == SourceEntityKind::SourceVertex) {
              const int corner = face_vertex_corner(
                  faces, commonChart.sourceFace, entity.firstSourceIndex);
              if (corner >= 0) {
                startCorner = (corner + 1) % 3;
                endCorner = (corner + 2) % 3;
              }
            } else {
              for (int edge = 0; edge < 3; ++edge) {
                const int first =
                    faces(commonChart.sourceFace, (edge + 1) % 3);
                const int second =
                    faces(commonChart.sourceFace, (edge + 2) % 3);
                if (std::min(first, second) == entity.firstSourceIndex &&
                    std::max(first, second) == entity.secondSourceIndex) {
                  startCorner = (edge + 2) % 3;
                  endCorner = (edge + 1) % 3;
                  break;
                }
              }
            }
            if (startCorner < 0 || endCorner < 0) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingChartWitness, key,
                  context);
              break;
            }

            const Eigen::Vector2d nodeUv =
                bary_to_uv(nodePoint.barycentric.transpose());
            const Eigen::Vector2d startDirection =
                bary_to_uv(Eigen::RowVector3d::Unit(startCorner)) - nodeUv;
            const Eigen::Vector2d endDirection =
                bary_to_uv(Eigen::RowVector3d::Unit(endCorner)) - nodeUv;
            if (!(startDirection.squaredNorm() > 1.0e-28) ||
                !(endDirection.squaredNorm() > 1.0e-28) ||
                !startDirection.allFinite() || !endDirection.allFinite()) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingChartWitness, key,
                  context);
              break;
            }
            double wedgeStart =
                std::atan2(startDirection.y(), startDirection.x());
            double wedgeEnd =
                std::atan2(endDirection.y(), endDirection.x());
            while (wedgeEnd <= wedgeStart + cornerAngleTolerance) {
              wedgeEnd += twoPi;
            }
            const double wedgeSpan = wedgeEnd - wedgeStart;
            context.wedgeStart = wedgeStart;
            context.wedgeEnd = wedgeEnd;
            context.wedgeSpan = wedgeSpan;
            if (!(wedgeSpan > cornerAngleTolerance) ||
                wedgeSpan > 3.1415926535897932384626433832795 +
                                cornerAngleTolerance) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::SpanOutsideWedge, key,
                  context);
              break;
            }

            std::vector<ChartCornerRay> chartRays;
            chartRays.reserve(pairLocalRays.size());
            for (auto &[halfedgeId, rayEvidence] : pairLocalRays) {
              SurfacePoint toPoint;
              if (!node_point_on_chart(
                      complex.halfedges[static_cast<std::size_t>(halfedgeId)]
                          .to,
                      commonChart, toPoint)) {
                context.intrudingHalfedge = halfedgeId;
                context.intrudingIdentity =
                    rayEvidence.identities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : rayEvidence.identities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingChartWitness,
                    key, context);
                break;
              }
              const Eigen::Vector2d direction =
                  bary_to_uv(toPoint.barycentric.transpose()) - nodeUv;
              if (!(direction.squaredNorm() > 1.0e-28) ||
                  !direction.allFinite()) {
                context.intrudingHalfedge = halfedgeId;
                context.intrudingIdentity =
                    rayEvidence.identities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : rayEvidence.identities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::MissingChartWitness,
                    key, context);
                break;
              }
              const double rawAngle =
                  std::atan2(direction.y(), direction.x());
              struct AdmissibleLift {
                double angle = 0.0;
                int turn = 0;
              };
              std::vector<AdmissibleLift> admissibleLifts;
              bool nonIntegralLift = false;
              for (int turn = -2; turn <= 2; ++turn) {
                const double candidate = rawAngle + turn * twoPi;
                if (candidate >= wedgeStart - cornerAngleTolerance &&
                    candidate <= wedgeEnd + cornerAngleTolerance) {
                  const double reconstructedTurn =
                      (candidate - rawAngle) / twoPi;
                  if (!std::isfinite(candidate) ||
                      !std::isfinite(reconstructedTurn) ||
                      std::abs(reconstructedTurn -
                               static_cast<double>(turn)) >
                          cornerAngleTolerance) {
                    nonIntegralLift = true;
                    break;
                  }
                  admissibleLifts.push_back({candidate, turn});
                }
              }
              if (nonIntegralLift) {
                context.intrudingHalfedge = halfedgeId;
                context.intrudingIdentity =
                    rayEvidence.identities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : rayEvidence.identities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::NonIntegralLiftTurn,
                    key, context);
                break;
              }
              if (admissibleLifts.empty()) {
                context.intrudingHalfedge = halfedgeId;
                context.intrudingIdentity =
                    rayEvidence.identities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : rayEvidence.identities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::NoAdmissibleLift, key,
                    context);
                break;
              }
              if (admissibleLifts.size() != 1U) {
                context.intrudingHalfedge = halfedgeId;
                context.intrudingIdentity =
                    rayEvidence.identities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : rayEvidence.identities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::
                        MultipleAdmissibleLifts,
                    key, context);
                break;
              }
              std::sort(rayEvidence.identities.begin(),
                        rayEvidence.identities.end());
              rayEvidence.identities.erase(
                  std::unique(rayEvidence.identities.begin(),
                              rayEvidence.identities.end()),
                  rayEvidence.identities.end());
              chartRays.push_back(
                  {halfedgeId, -1, admissibleLifts.front().angle, rawAngle,
                   admissibleLifts.front().turn,
                   rayEvidence.witness.leftScore,
                   rayEvidence.identities});
            }
            if (!directedIncidenceValid) {
              break;
            }

            std::sort(chartRays.begin(), chartRays.end(),
                      [&](const ChartCornerRay &lhs,
                          const ChartCornerRay &rhs) {
                        if (std::abs(lhs.angle - rhs.angle) >
                            cornerAngleTolerance) {
                          return lhs.angle < rhs.angle;
                        }
                        return lhs.halfedge < rhs.halfedge;
                      });
            for (std::size_t index = 1; index < chartRays.size(); ++index) {
              if (std::abs(chartRays[index].angle -
                           chartRays[index - 1U].angle) <=
                      cornerAngleTolerance &&
                  chartRays[index].halfedge !=
                      chartRays[index - 1U].halfedge) {
                context.intrudingHalfedge = chartRays[index].halfedge;
                context.intrudingIdentity =
                    chartRays[index].fanIdentities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : chartRays[index].fanIdentities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::DuplicateLiftedAngle,
                    key, context);
                break;
              }
            }
            if (!directedIncidenceValid) {
              break;
            }

            std::map<int, std::size_t> liftedPositionByHalfedge;
            std::map<int, ChartCornerRay> chartRayByHalfedge;
            for (std::size_t index = 0; index < chartRays.size(); ++index) {
              chartRays[index].fanPosition = static_cast<int>(index);
              if (!liftedPositionByHalfedge
                       .emplace(chartRays[index].halfedge, index)
                       .second ||
                  !chartRayByHalfedge
                       .emplace(chartRays[index].halfedge, chartRays[index])
                       .second) {
                context.intrudingHalfedge = chartRays[index].halfedge;
                context.intrudingIdentity =
                    chartRays[index].fanIdentities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : chartRays[index].fanIdentities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::
                        IdentityIntervalConflict,
                    key, context);
                break;
              }
            }
            if (!directedIncidenceValid) {
              break;
            }

            const auto sourceRay = chartRayByHalfedge.find(key.sourceRay);
            const auto targetRay = chartRayByHalfedge.find(key.target);
            if (sourceRay == chartRayByHalfedge.end()) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingSourceRay, key,
                  context);
              break;
            }
            if (targetRay == chartRayByHalfedge.end()) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingTargetRay, key,
                  context);
              break;
            }
            const auto sourcePosition =
                liftedPositionByHalfedge.find(key.sourceRay);
            const auto targetPosition =
                liftedPositionByHalfedge.find(key.target);
            if (sourcePosition == liftedPositionByHalfedge.end() ||
                targetPosition == liftedPositionByHalfedge.end()) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::NonAdjacentLiftedPair,
                  key, context);
              break;
            }

            context.sourcePosition =
                static_cast<int>(sourcePosition->second);
            context.targetPosition =
                static_cast<int>(targetPosition->second);
            context.sourceRawAngle = sourceRay->second.rawAngle;
            context.targetRawAngle = targetRay->second.rawAngle;
            context.sourceLiftedAngle = sourceRay->second.angle;
            context.targetLiftedAngle = targetRay->second.angle;
            context.sourceLiftTurn = sourceRay->second.liftTurn;
            context.targetLiftTurn = targetRay->second.liftTurn;
            context.liftTurnDifference =
                sourceRay->second.liftTurn - targetRay->second.liftTurn;

            if (sourcePosition->second <= targetPosition->second) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::ReverseLiftedOrder, key,
                  context);
              break;
            }
            if (sourcePosition->second != targetPosition->second + 1U) {
              if (targetPosition->second + 1U < chartRays.size() &&
                  targetPosition->second + 1U < sourcePosition->second) {
                const ChartCornerRay &intruder =
                    chartRays[targetPosition->second + 1U];
                context.intrudingHalfedge = intruder.halfedge;
                context.intrudingIdentity =
                    intruder.fanIdentities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : intruder.fanIdentities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::ThirdRayIntrusion, key,
                    context);
              } else {
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::NonAdjacentLiftedPair,
                    key, context);
              }
              break;
            }

            const double targetAngle = targetRay->second.angle;
            const double sourceAngle = sourceRay->second.angle;
            const double orientedSpan = sourceAngle - targetAngle;
            if (!(orientedSpan > cornerAngleTolerance)) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::NonPositiveSpan, key,
                  context);
              break;
            }
            if (orientedSpan > wedgeSpan + cornerAngleTolerance ||
                targetAngle < wedgeStart - cornerAngleTolerance ||
                sourceAngle > wedgeEnd + cornerAngleTolerance) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::SpanOutsideWedge, key,
                  context);
              break;
            }
            if (context.liftTurnDifference != 0 &&
                context.liftTurnDifference != 1) {
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::
                      InvalidLiftTurnDifference,
                  key, context);
              break;
            }

            for (const ChartCornerRay &other : chartRays) {
              if (other.halfedge == key.sourceRay ||
                  other.halfedge == key.target) {
                continue;
              }
              if (other.angle > targetAngle + cornerAngleTolerance &&
                  other.angle < sourceAngle - cornerAngleTolerance) {
                context.intrudingHalfedge = other.halfedge;
                context.intrudingIdentity =
                    other.fanIdentities.empty()
                        ? SurfaceCellCanonicalIdentity{}
                        : other.fanIdentities.front();
                record_pair_interval_failure(
                    SurfaceArrangementIntervalFailure::ThirdRayIntrusion, key,
                    context);
                break;
              }
            }
            if (!directedIncidenceValid) {
              break;
            }

            candidatesByPair[key].push_back(
                {key.incoming, key.sourceRay, key.target,
                 combined_pair_fan_identity(record.fanIdentities), commonChart,
                 root, sourceRay->second.leftScore,
                 targetRay->second.leftScore, targetAngle, sourceAngle, false,
                 context.liftTurnDifference == 1});
          }
          if (!directedIncidenceValid) {
            break;
          }

          int exteriorExclusionCount = 0;
          for (const auto &[key, record] : canonicalPairInventory) {
            if (record.exterior) {
              if (!(key.incoming == exteriorIncoming &&
                    key.sourceRay == exteriorTwin &&
                    key.target == exteriorOutgoing) ||
                  record.sourceBoundaryIdentity !=
                      exteriorBoundaryIdentity ||
                  record.canonicalEntityKey !=
                      exteriorSourceProjection.canonicalEntityKey ||
                  record.exteriorSourceChart !=
                      exteriorSourceProjection.chart ||
                  record.exteriorTargetChart !=
                      exteriorTargetProjection.chart ||
                  record.exteriorSourceRoot !=
                      exteriorSourceProjection.transitionRoot ||
                  record.exteriorTargetRoot !=
                      exteriorTargetProjection.transitionRoot ||
                  record.exteriorSourceSide != 1 ||
                  record.exteriorTargetSide != -1) {
                record_boundary_fan_conflict(
                    SurfaceArrangementBoundaryFanConflict::
                        ExteriorPairMismatch,
                    node, key.incoming, key.sourceRay, key.target);
                break;
              }
              ++exteriorExclusionCount;
              continue;
            }

            auto candidates = candidatesByPair[key];
            const auto quantized_angle = [](const double value) {
              return static_cast<std::int64_t>(
                  std::llround(value * 1.0e12));
            };
            const auto witness_key = [&](const BoundaryFanSector &sector) {
              return std::make_tuple(
                  sector.incoming, sector.sourceRay, sector.target,
                  sector.chart, sector.chartRoot,
                  quantized_angle(sector.targetAngle),
                  quantized_angle(sector.sourceAngle));
            };
            std::sort(candidates.begin(), candidates.end(),
                      [&](const BoundaryFanSector &lhs,
                          const BoundaryFanSector &rhs) {
                        return witness_key(lhs) < witness_key(rhs);
                      });
            std::vector<BoundaryFanSector> agreeingCandidates;
            for (const BoundaryFanSector &candidate : candidates) {
              if (!agreeingCandidates.empty() &&
                  witness_key(agreeingCandidates.back()) ==
                      witness_key(candidate)) {
                if (std::abs(agreeingCandidates.back().sourceLeftScore -
                             candidate.sourceLeftScore) > 1.0e-10 ||
                    std::abs(agreeingCandidates.back().targetLeftScore -
                             candidate.targetLeftScore) > 1.0e-10) {
                  record_boundary_fan_conflict(
                      SurfaceArrangementBoundaryFanConflict::
                          ConflictingDuplicateWitnessScores,
                      node, key.incoming, key.sourceRay, key.target);
                  break;
                }
                agreeingCandidates.back().cyclicWrap =
                    agreeingCandidates.back().cyclicWrap ||
                    candidate.cyclicWrap;
                continue;
              }
              agreeingCandidates.push_back(candidate);
            }
            if (!directedIncidenceValid) {
              break;
            }
            if (agreeingCandidates.empty()) {
              PairLocalIntervalDiagnosticContext context;
              context.canonicalEntityKey = record.canonicalEntityKey;
              context.transitionRoot = record.transitionRoot;
              context.identityCount =
                  static_cast<int>(record.fanIdentities.size());
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::MissingChartWitness, key,
                  context);
              break;
            }
            if (agreeingCandidates.size() != 1U) {
              PairLocalIntervalDiagnosticContext context;
              context.canonicalEntityKey = record.canonicalEntityKey;
              context.transitionRoot = record.transitionRoot;
              context.identityCount =
                  static_cast<int>(record.fanIdentities.size());
              record_pair_interval_failure(
                  SurfaceArrangementIntervalFailure::
                      IdentityIntervalConflict,
                  key, context);
              break;
            }
            if (agreeingCandidates.front().chartRoot !=
                record.transitionRoot) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::
                      TransitionRootMismatch,
                  node, key.incoming, key.sourceRay, key.target);
              break;
            }
            interiorSectors.push_back(agreeingCandidates.front());
          }
          if (!directedIncidenceValid) {
            break;
          }
          if (exteriorExclusionCount != 1) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::ExteriorPairMismatch,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }
          const int canonicalFanPairCount =
              static_cast<int>(canonicalPairInventory.size());

          const auto sector_key = [](const BoundaryFanSector &sector) {
            return std::tie(sector.incoming, sector.sourceRay, sector.target,
                            sector.fanIdentity, sector.chart,
                            sector.chartRoot);
          };
          std::sort(interiorSectors.begin(), interiorSectors.end(),
                    [&](const BoundaryFanSector &lhs,
                        const BoundaryFanSector &rhs) {
                      return sector_key(lhs) < sector_key(rhs);
                    });
          interiorSectors.erase(
              std::unique(
                  interiorSectors.begin(), interiorSectors.end(),
                  [&](const BoundaryFanSector &lhs,
                      const BoundaryFanSector &rhs) {
                    return sector_key(lhs) == sector_key(rhs);
                  }),
              interiorSectors.end());
          for (const BoundaryFanSector &sector : interiorSectors) {
            // Exact source-face corners are source-interior authority. A face
            // corner may never duplicate the independently proven exterior
            // boundary continuation.
            if (sector.incoming == exteriorIncoming ||
                sector.target == exteriorOutgoing) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::
                      IncompleteIncomingTargetCover,
                  node, sector.incoming, sector.sourceRay, sector.target);
              break;
            }
            sectors.push_back(sector);
          }
          if (!directedIncidenceValid) {
            break;
          }

          std::map<int, std::size_t> sectorByIncoming;
          std::map<int, std::size_t> sectorByTarget;
          std::set<std::tuple<int, int, SurfaceCellCanonicalIdentity,
                              SurfaceCellProjectionChart>>
              canonicalSectors;
          for (std::size_t sectorIndex = 0; sectorIndex < sectors.size();
               ++sectorIndex) {
            const BoundaryFanSector &sector = sectors[sectorIndex];
            if (!sectorByIncoming.emplace(sector.incoming, sectorIndex).second ||
                !sectorByTarget.emplace(sector.target, sectorIndex).second ||
                !canonicalSectors
                     .emplace(sector.incoming, sector.target,
                              sector.fanIdentity, sector.chart)
                     .second) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::
                      IncompleteIncomingTargetCover,
                  node, sector.incoming, sector.sourceRay, sector.target);
              break;
            }
          }
          if (!directedIncidenceValid) {
            break;
          }

          int hardRailSeparatorCount = 0;
          int hardRailSidePairCount = 0;
          for (const int separatorRay : localOutgoing) {
            if (!is_authoritative_source_rail(separatorRay)) {
              continue;
            }
            const int separatorIncoming =
                complex.halfedges[static_cast<std::size_t>(separatorRay)].twin;
            const auto owned = sectorByIncoming.find(separatorIncoming);
            const auto targeted = sectorByTarget.find(separatorRay);
            std::set<SurfaceCellProjectionChart> incidentCharts;
            const SurfaceArrangementHalfedge &rail =
                complex.halfedges[static_cast<std::size_t>(separatorRay)];
            for (const SurfaceArrangementProvenance &entry : rail.provenance) {
              if (entry.sourceArc >= 0 || entry.family >= 0 ||
                  !entry.hardFeature) {
                continue;
              }
              const SurfaceCellProjectionChart chart{
                  entry.sourceComponent, entry.sourceFace, entry.sourceSheet};
              if (chart.valid() &&
                  transitionGraph.chart_component(SourceProjectionChart{
                      chart.sourceComponent, chart.localSheet,
                      chart.sourceFace}) >= 0) {
                incidentCharts.insert(chart);
              }
            }
            if (owned == sectorByIncoming.end() ||
                targeted == sectorByTarget.end() ||
                incidentCharts.size() != 2U) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::
                      HardRailSeparatorOrOrbitConflict,
                  node, separatorIncoming, separatorRay,
                  targeted == sectorByTarget.end()
                      ? -1
                      : sectors[targeted->second].incoming);
              break;
            }
            const BoundaryFanSector &ownedSector = sectors[owned->second];
            const BoundaryFanSector &targetedSector = sectors[targeted->second];
            std::set<int> incidentRoots;
            for (const SurfaceCellProjectionChart &chart : incidentCharts) {
              incidentRoots.insert(
                  transitionGraph.chart_component(SourceProjectionChart{
                      chart.sourceComponent, chart.localSheet,
                      chart.sourceFace}));
            }
            const std::set<int> selectedRoots{
                ownedSector.chartRoot, targetedSector.chartRoot};
            if (ownedSector.exterior || targetedSector.exterior ||
                ownedSector.sourceRay != separatorRay ||
                targetedSector.target != separatorRay ||
                ownedSector.chart == targetedSector.chart ||
                incidentCharts.count(ownedSector.chart) != 1U ||
                incidentCharts.count(targetedSector.chart) != 1U ||
                incidentRoots.size() != 2U || selectedRoots != incidentRoots ||
                !(ownedSector.sourceLeftScore < -1.0e-12) ||
                !(targetedSector.targetLeftScore > 1.0e-12)) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::
                      HardRailSeparatorOrOrbitConflict,
                  node, separatorIncoming, separatorRay,
                  targetedSector.incoming);
              break;
            }
            hardRailOrbitSeeds.emplace_back(ownedSector.incoming,
                                            ownedSector.chartRoot);
            hardRailOrbitSeeds.emplace_back(targetedSector.incoming,
                                            targetedSector.chartRoot);
            ++hardRailSeparatorCount;
            ++hardRailSidePairCount;
          }
          if (!directedIncidenceValid) {
            break;
          }

          if (sectors.size() != localOutgoing.size() ||
              sectorByIncoming.size() != localOutgoing.size() ||
              sectorByTarget.size() != localOutgoing.size() ||
              sectorByIncoming.count(exteriorIncoming) != 1U ||
              sectorByTarget.count(exteriorOutgoing) != 1U) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::
                    IncompleteIncomingTargetCover,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
            break;
          }
          for (const int outgoingRay : localOutgoing) {
            const int incoming =
                complex.halfedges[static_cast<std::size_t>(outgoingRay)].twin;
            if (sectorByIncoming.count(incoming) != 1U ||
                sectorByTarget.count(outgoingRay) != 1U) {
              record_boundary_fan_conflict(
                  SurfaceArrangementBoundaryFanConflict::
                      IncompleteIncomingTargetCover,
                  node, incoming, outgoingRay, -1);
              break;
            }
          }
          if (!directedIncidenceValid) {
            break;
          }

          // Publish only after the direct exact-corner inventory proves a
          // complete one-to-one cover. No R2E7 generic successor is consulted.
          for (const BoundaryFanSector &sector : sectors) {
            candidateNext[static_cast<std::size_t>(sector.incoming)] =
                sector.target;
            successorWedge[static_cast<std::size_t>(sector.incoming)] =
                sector.fanIdentity;
            if (!sector.exterior) {
              successorChartRoot[static_cast<std::size_t>(sector.incoming)] =
                  sector.chartRoot;
            }
            localIncoming.insert(sector.incoming);
            ++localTargetCount[sector.target];
          }
          ++complex.diagnostics.boundaryFanSectorNodeCount;
          complex.diagnostics.boundaryCanonicalFanPairCount +=
              canonicalFanPairCount;
          complex.diagnostics.boundaryExteriorSectorExclusionCount +=
              exteriorExclusionCount;
          complex.diagnostics.boundaryInteriorSectorCount +=
              static_cast<int>(sectors.size()) - 1;
          complex.diagnostics.boundaryHardRailSeparatorCount +=
              hardRailSeparatorCount;
          complex.diagnostics.boundaryHardRailSidePairCount +=
              hardRailSidePairCount;
          complex.diagnostics.boundaryCyclicWrapInteriorSectorCount +=
              static_cast<int>(std::count_if(
                  sectors.begin(), sectors.end(),
                  [](const BoundaryFanSector &sector) {
                    return !sector.exterior && sector.cyclicWrap;
                  }));
        }

        if (candidateNext[static_cast<std::size_t>(exteriorIncoming)] !=
                exteriorOutgoing ||
            localIncoming.size() != localOutgoing.size() ||
            localTargetCount.size() != localOutgoing.size() ||
            std::any_of(localTargetCount.begin(), localTargetCount.end(),
                        [](const auto &entry) { return entry.second != 1; })) {
          if (degreeTwoRotation) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryRotationalSystemConflict,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
          } else {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::
                    IncompleteIncomingTargetCover,
                node, exteriorIncoming, exteriorTwin, exteriorOutgoing);
          }
          break;
        }

        if (degreeTwoRotation) {
          ++complex.diagnostics.boundaryDegreeTwoRotationalNodeCount;
        }

        // Keep the exterior sector's semantic loop identity. Interior sectors
        // retain their canonical R1 fan identity assigned above.
        successorWedge[static_cast<std::size_t>(exteriorIncoming)] =
            sourceBoundaryTopology
                .loops[static_cast<std::size_t>(
                    authoritativeBoundaryLoop[static_cast<std::size_t>(
                        exteriorIncoming)])]
                .canonicalIdentity;
        ++complex.diagnostics.boundaryRotationalNodeCount;
      }

      // Prove each exact hard-rail side against the complete predicted
      // successor orbit before any relation is published to the DCEL. A
      // separator edge can carry provenance from both incident charts, but
      // every bounded side must retain one common transition-component root.
      std::sort(hardRailOrbitSeeds.begin(), hardRailOrbitSeeds.end());
      hardRailOrbitSeeds.erase(
          std::unique(hardRailOrbitSeeds.begin(), hardRailOrbitSeeds.end()),
          hardRailOrbitSeeds.end());
      const auto halfedge_transition_roots = [&](const int halfedgeId) {
        std::set<int> roots;
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(complex.halfedges.size())) {
          return roots;
        }
        for (const SurfaceCellProjectionChart &chart : halfedge_source_charts(
                 complex.halfedges[static_cast<std::size_t>(halfedgeId)])) {
          const int root = transitionGraph.chart_component(SourceProjectionChart{
              chart.sourceComponent, chart.localSheet, chart.sourceFace});
          if (root >= 0) {
            roots.insert(root);
          }
        }
        return roots;
      };
      for (const auto &[seed, expectedRoot] : hardRailOrbitSeeds) {
        if (seed < 0 ||
            seed >= static_cast<int>(complex.halfedges.size()) ||
            expectedRoot < 0) {
          record_boundary_fan_conflict(
              SurfaceArrangementBoundaryFanConflict::
                  HardRailSeparatorOrOrbitConflict,
              -1, seed, -1, expectedRoot);
          break;
        }
        std::set<int> visited;
        std::vector<int> orbit;
        int current = seed;
        while (visited.insert(current).second) {
          orbit.push_back(current);
          if (authoritativeBoundaryExterior
                  [static_cast<std::size_t>(current)] != 0U ||
              (successorChartRoot[static_cast<std::size_t>(current)] >= 0 &&
               successorChartRoot[static_cast<std::size_t>(current)] !=
                   expectedRoot) ||
              halfedge_transition_roots(current).count(expectedRoot) != 1U) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::
                    HardRailSeparatorOrOrbitConflict,
                complex.halfedges[static_cast<std::size_t>(current)].to,
                current,
                complex.halfedges[static_cast<std::size_t>(current)].twin,
                candidateNext[static_cast<std::size_t>(current)]);
            break;
          }
          const int next = candidateNext[static_cast<std::size_t>(current)];
          if (next < 0 ||
              next >= static_cast<int>(complex.halfedges.size()) ||
              complex.halfedges[static_cast<std::size_t>(next)].from !=
                  complex.halfedges[static_cast<std::size_t>(current)].to) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::
                    HardRailSeparatorOrOrbitConflict,
                complex.halfedges[static_cast<std::size_t>(current)].to,
                current,
                complex.halfedges[static_cast<std::size_t>(current)].twin,
                next);
            break;
          }
          current = next;
        }
        if (!directedIncidenceValid) {
          break;
        }
        if (current != seed || orbit.empty()) {
          record_boundary_fan_conflict(
              SurfaceArrangementBoundaryFanConflict::
                  HardRailSeparatorOrOrbitConflict,
              complex.halfedges[static_cast<std::size_t>(seed)].to, seed,
              complex.halfedges[static_cast<std::size_t>(seed)].twin,
              current);
          break;
        }
        for (const int halfedgeId : orbit) {
          int &assignedRoot = candidateOrbitChartRoot
              [static_cast<std::size_t>(halfedgeId)];
          if (assignedRoot >= 0 && assignedRoot != expectedRoot) {
            record_boundary_fan_conflict(
                SurfaceArrangementBoundaryFanConflict::
                    HardRailSeparatorOrOrbitConflict,
                complex.halfedges[static_cast<std::size_t>(halfedgeId)].to,
                halfedgeId,
                complex.halfedges[static_cast<std::size_t>(halfedgeId)].twin,
                candidateNext[static_cast<std::size_t>(halfedgeId)]);
            break;
          }
          assignedRoot = expectedRoot;
        }
        if (!directedIncidenceValid) {
          break;
        }
      }

      // Validate the authoritative exterior relation before publishing any
      // successor.  Every exterior halfedge must follow its exact ordered-loop
      // continuation, and each source loop must close once without entering an
      // interior sector.
      for (int loop = 0;
           directedIncidenceValid &&
           loop < static_cast<int>(sourceBoundaryTopology.loops.size()); ++loop) {
        std::vector<int> loopExterior;
        for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
          if (authoritativeBoundaryExterior
                      [static_cast<std::size_t>(halfedge.id)] != 0U &&
              authoritativeBoundaryLoop[static_cast<std::size_t>(halfedge.id)] ==
                  loop) {
            loopExterior.push_back(halfedge.id);
          }
        }
        if (loopExterior.empty()) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::
                  BoundaryRotationalSystemConflict,
              -1, -1, -1, loop);
          break;
        }
        std::set<int> exteriorSet(loopExterior.begin(), loopExterior.end());
        std::set<int> visited;
        int current = loopExterior.front();
        while (visited.insert(current).second) {
          const int next = candidateNext[static_cast<std::size_t>(current)];
          if (next != desiredExteriorNext[static_cast<std::size_t>(current)] ||
              exteriorSet.count(next) == 0U) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::
                    BoundaryRotationalSystemConflict,
                complex.halfedges[static_cast<std::size_t>(current)].to,
                current,
                complex.halfedges[static_cast<std::size_t>(current)].twin,
                next);
            break;
          }
          current = next;
        }
        if (!directedIncidenceValid) {
          break;
        }
        if (current != loopExterior.front() ||
            visited.size() != exteriorSet.size()) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::
                  BoundaryRotationalSystemConflict,
              -1, loopExterior.front(), -1, current);
          break;
        }
      }
    }
  }

  }

  // Audit the complete transactional candidate relation once. No successor is
  // published to the complex until endpoint continuity and one-to-one global
  // predecessor ownership both hold.
  std::fill(predecessorCount.begin(), predecessorCount.end(), 0);
  if (directedIncidenceValid) {
    for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
      const int next = candidateNext[static_cast<std::size_t>(halfedge.id)];
      if (next < 0 || next >= static_cast<int>(complex.halfedges.size())) {
        ++complex.diagnostics.successorMissingCount;
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::MissingSuccessor, halfedge.to,
            halfedge.id, halfedge.twin, next);
        break;
      }
      if (complex.halfedges[static_cast<std::size_t>(next)].from !=
          halfedge.to) {
        ++complex.diagnostics.successorMissingCount;
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::EndpointDiscontinuity,
            halfedge.to, halfedge.id, halfedge.twin, next);
        break;
      }
      ++predecessorCount[static_cast<std::size_t>(next)];
    }
  }

  if (directedIncidenceValid) {
    for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
      const int multiplicity =
          predecessorCount[static_cast<std::size_t>(halfedge.id)];
      if (multiplicity != 1) {
        ++complex.diagnostics.predecessorMultiplicityFailureCount;
        record_incidence_failure(
            multiplicity == 0
                ? SurfaceArrangementIncidenceFailure::IncompletePermutation
                : SurfaceArrangementIncidenceFailure::DuplicatePredecessor,
            halfedge.from, halfedge.id, halfedge.twin,
            candidateNext[static_cast<std::size_t>(halfedge.id)]);
        break;
      }
    }
  }

  if (directedIncidenceValid) {
    for (SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
      halfedge.next = candidateNext[static_cast<std::size_t>(halfedge.id)];
      halfedge.authoritativeChartRoot =
          candidateOrbitChartRoot[static_cast<std::size_t>(halfedge.id)];
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
    std::vector<std::int64_t> record;
    const auto append_identity = [&](const SurfaceCellCanonicalIdentity &value) {
      record.push_back(static_cast<std::int64_t>(value.values.size()));
      record.insert(record.end(), value.values.begin(), value.values.end());
    };
    const SurfaceCellCanonicalIdentity &boundarySegment =
        authoritativeBoundarySegment[static_cast<std::size_t>(halfedge.id)];
    if (boundarySegment.valid) {
      // Encode the directed twins of one physical source-boundary subsegment as
      // one canonical incidence object. The exact loop, interval, endpoints,
      // and feature role remain invariant when all source triangles reverse
      // orientation, while the validated successor permutation remains the
      // independent topology authority.
      if (halfedge.twin < 0 ||
          halfedge.twin >= static_cast<int>(complex.halfedges.size()) ||
          halfedge.id > halfedge.twin) {
        continue;
      }
      const int loop =
          authoritativeBoundaryLoop[static_cast<std::size_t>(halfedge.id)];
      const SurfaceCellCanonicalIdentity &twinSegment =
          authoritativeBoundarySegment[static_cast<std::size_t>(halfedge.twin)];
      const int twinLoop =
          authoritativeBoundaryLoop[static_cast<std::size_t>(halfedge.twin)];
      if (loop < 0 ||
          loop >= static_cast<int>(sourceBoundaryTopology.loops.size()) ||
          twinLoop != loop || !twinSegment.valid ||
          twinSegment != boundarySegment ||
          authoritativeBoundarySide[static_cast<std::size_t>(halfedge.id)] ==
              authoritativeBoundarySide[static_cast<std::size_t>(halfedge.twin)]) {
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::BoundaryAliasConflict,
            halfedge.to, halfedge.id, halfedge.twin, halfedge.next);
        continue;
      }
      const SurfaceCellCanonicalIdentity from =
          canonical_node_identity(halfedge.from);
      const SurfaceCellCanonicalIdentity to =
          canonical_node_identity(halfedge.to);
      if (!from.valid || !to.valid) {
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::MissingWedge, halfedge.to,
            halfedge.id, halfedge.twin, halfedge.next);
        continue;
      }
      record.push_back(0x424f554e44415259LL);
      append_identity(sourceBoundaryTopology
                          .loops[static_cast<std::size_t>(loop)]
                          .canonicalIdentity);
      append_identity(boundarySegment);
      if (to < from) {
        append_identity(to);
        append_identity(from);
      } else {
        append_identity(from);
        append_identity(to);
      }
      record.push_back(halfedge.hardFeature ? 1 : 0);
      incidenceRecords.push_back(std::move(record));
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
    record.push_back(0x5745444745LL);
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

  struct AuditedCycle {
    std::vector<int> halfedges;
    std::vector<std::vector<int>> coreCycles;
    bool cutCellDisk = false;
    bool bridgeExcursion = false;
    bool supportOnlyCycle = false;
  };

  const auto analyze_cycle =
      [&](const std::vector<int> &cycle, AuditedCycle &audited,
          SurfaceArrangementIncidenceFailure &failure, int &failureNode,
          int &failureHalfedge, int &failureTwin, int &failureNext) {
        audited = {};
        audited.halfedges = cycle;
        failure = SurfaceArrangementIncidenceFailure::None;
        failureNode = failureHalfedge = failureTwin = failureNext = -1;
        if (cycle.size() < 2U) {
          failure = SurfaceArrangementIncidenceFailure::ShortCycle;
          failureHalfedge = cycle.empty() ? -1 : cycle.front();
          return false;
        }

        using UndirectedEdge = std::pair<int, int>;
        std::map<UndirectedEdge, std::vector<int>> occurrences;
        std::map<int, std::vector<std::pair<int, UndirectedEdge>>> adjacency;
        const auto fail_from_halfedge =
            [&](const SurfaceArrangementIncidenceFailure kind,
                const int halfedgeId) {
              failure = kind;
              failureHalfedge = halfedgeId;
              if (halfedgeId < 0 ||
                  halfedgeId >= static_cast<int>(complex.halfedges.size())) {
                return;
              }
              const SurfaceArrangementHalfedge &edge =
                  complex.halfedges[static_cast<std::size_t>(halfedgeId)];
              failureNode = edge.from;
              failureTwin = edge.twin;
              failureNext = edge.next;
            };
        for (const int halfedgeId : cycle) {
          if (halfedgeId < 0 ||
              halfedgeId >= static_cast<int>(complex.halfedges.size())) {
            fail_from_halfedge(
                SurfaceArrangementIncidenceFailure::MissingSuccessor,
                halfedgeId);
            return false;
          }
          const SurfaceArrangementHalfedge &edge =
              complex.halfedges[static_cast<std::size_t>(halfedgeId)];
          if (edge.from < 0 || edge.to < 0 ||
              edge.from >= static_cast<int>(complex.nodes.size()) ||
              edge.to >= static_cast<int>(complex.nodes.size()) ||
              edge.from == edge.to) {
            fail_from_halfedge(
                SurfaceArrangementIncidenceFailure::EndpointDiscontinuity,
                halfedgeId);
            return false;
          }
          const UndirectedEdge key{std::min(edge.from, edge.to),
                                   std::max(edge.from, edge.to)};
          occurrences[key].push_back(edge.id);
        }
        for (const auto &[key, ids] : occurrences) {
          (void)ids;
          adjacency[key.first].push_back({key.second, key});
          adjacency[key.second].push_back({key.first, key});
        }
        for (auto &[node, incident] : adjacency) {
          (void)node;
          std::sort(incident.begin(), incident.end());
        }

        // Tarjan bridge classification is linear in the cycle graph. A bridge
        // in a face boundary must appear exactly as its two directed twins.
        std::map<int, int> discovery;
        std::map<int, int> low;
        std::set<UndirectedEdge> bridgeEdges;
        int discoveryClock = 0;
        const UndirectedEdge noParent{-1, -1};
        std::function<void(int, const UndirectedEdge &)> visit =
            [&](const int node, const UndirectedEdge &parentEdge) {
              discovery[node] = low[node] = ++discoveryClock;
              const auto found = adjacency.find(node);
              if (found == adjacency.end()) {
                return;
              }
              for (const auto &[neighbor, edgeKey] : found->second) {
                if (edgeKey == parentEdge) {
                  continue;
                }
                if (discovery.count(neighbor) == 0U) {
                  visit(neighbor, edgeKey);
                  low[node] = std::min(low[node], low[neighbor]);
                  if (low[neighbor] > discovery[node]) {
                    bridgeEdges.insert(edgeKey);
                  }
                } else {
                  low[node] = std::min(low[node], discovery[neighbor]);
                }
              }
            };
        for (const auto &[node, incident] : adjacency) {
          (void)incident;
          if (discovery.count(node) == 0U) {
            visit(node, noParent);
          }
        }

        std::map<UndirectedEdge, int> coreHalfedge;
        std::map<int, std::set<int>> coreAdjacency;
        std::map<int, std::set<int>> bridgeAdjacency;
        for (const auto &[key, ids] : occurrences) {
          const bool isBridge = bridgeEdges.count(key) != 0U;
          if (isBridge) {
            if (ids.size() != 2U) {
              fail_from_halfedge(
                  SurfaceArrangementIncidenceFailure::IncompletePermutation,
                  ids.empty() ? -1 : ids.front());
              return false;
            }
            const SurfaceArrangementHalfedge &first =
                complex.halfedges[static_cast<std::size_t>(ids[0])];
            const SurfaceArrangementHalfedge &second =
                complex.halfedges[static_cast<std::size_t>(ids[1])];
            if (first.twin != second.id || second.twin != first.id) {
              fail_from_halfedge(
                  SurfaceArrangementIncidenceFailure::RepeatedEdgeCycle,
                  first.id);
              return false;
            }
            bridgeAdjacency[key.first].insert(key.second);
            bridgeAdjacency[key.second].insert(key.first);
            continue;
          }
          if (ids.size() != 1U) {
            fail_from_halfedge(
                SurfaceArrangementIncidenceFailure::RepeatedEdgeCycle,
                ids.empty() ? -1 : ids.front());
            return false;
          }
          coreHalfedge.emplace(key, ids.front());
          coreAdjacency[key.first].insert(key.second);
          coreAdjacency[key.second].insert(key.first);
        }

        // Every non-bridge component must be one directed simple cycle. This
        // rejects figure-eights and theta graphs without rejecting bridge
        // excursions that a valid planar/surface face walk traverses twice.
        std::map<int, int> coreComponentByNode;
        std::set<int> visitedCore;
        for (const auto &[seed, seedNeighbors] : coreAdjacency) {
          (void)seedNeighbors;
          if (visitedCore.count(seed) != 0U) {
            continue;
          }
          std::set<int> componentNodes;
          std::set<UndirectedEdge> componentEdges;
          std::vector<int> pending{seed};
          visitedCore.insert(seed);
          while (!pending.empty()) {
            const int node = pending.back();
            pending.pop_back();
            componentNodes.insert(node);
            const auto found = coreAdjacency.find(node);
            if (found == coreAdjacency.end() || found->second.size() != 2U) {
              const auto edge = found == coreAdjacency.end() ||
                                        found->second.empty()
                                    ? UndirectedEdge{node, node}
                                    : UndirectedEdge{
                                          std::min(node, *found->second.begin()),
                                          std::max(node, *found->second.begin())};
              const auto occurrence = coreHalfedge.find(edge);
              fail_from_halfedge(
                  SurfaceArrangementIncidenceFailure::RepeatedNodeCycle,
                  occurrence == coreHalfedge.end() ? -1
                                                   : occurrence->second);
              failureNode = node;
              return false;
            }
            for (const int neighbor : found->second) {
              const UndirectedEdge edge{std::min(node, neighbor),
                                        std::max(node, neighbor)};
              componentEdges.insert(edge);
              if (visitedCore.insert(neighbor).second) {
                pending.push_back(neighbor);
              }
            }
          }
          if (componentEdges.size() < 3U ||
              componentEdges.size() != componentNodes.size()) {
            fail_from_halfedge(
                SurfaceArrangementIncidenceFailure::ShortCycle,
                componentEdges.empty()
                    ? -1
                    : coreHalfedge.at(*componentEdges.begin()));
            return false;
          }

          std::map<int, int> outgoingCore;
          std::map<int, int> incomingUse;
          for (const UndirectedEdge &key : componentEdges) {
            const int halfedgeId = coreHalfedge.at(key);
            const SurfaceArrangementHalfedge &edge =
                complex.halfedges[static_cast<std::size_t>(halfedgeId)];
            if (componentNodes.count(edge.from) == 0U ||
                componentNodes.count(edge.to) == 0U ||
                !outgoingCore.emplace(edge.from, edge.id).second) {
              fail_from_halfedge(
                  SurfaceArrangementIncidenceFailure::RepeatedNodeCycle,
                  edge.id);
              return false;
            }
            ++incomingUse[edge.to];
          }
          if (outgoingCore.size() != componentNodes.size() ||
              std::any_of(incomingUse.begin(), incomingUse.end(),
                          [](const auto &entry) {
                            return entry.second != 1;
                          })) {
            fail_from_halfedge(
                SurfaceArrangementIncidenceFailure::EndpointDiscontinuity,
                coreHalfedge.at(*componentEdges.begin()));
            return false;
          }

          const auto startEdge = std::min_element(
              componentEdges.begin(), componentEdges.end(),
              [&](const UndirectedEdge &lhs, const UndirectedEdge &rhs) {
                return coreHalfedge.at(lhs) < coreHalfedge.at(rhs);
              });
          if (startEdge == componentEdges.end()) {
            failure = SurfaceArrangementIncidenceFailure::ShortCycle;
            return false;
          }
          const int startHalfedge = coreHalfedge.at(*startEdge);
          std::vector<int> ordered;
          std::set<int> used;
          int current = startHalfedge;
          for (std::size_t guard = 0; guard <= componentEdges.size(); ++guard) {
            if (!used.insert(current).second) {
              break;
            }
            ordered.push_back(current);
            const SurfaceArrangementHalfedge &edge =
                complex.halfedges[static_cast<std::size_t>(current)];
            const auto next = outgoingCore.find(edge.to);
            if (next == outgoingCore.end()) {
              fail_from_halfedge(
                  SurfaceArrangementIncidenceFailure::EndpointDiscontinuity,
                  current);
              return false;
            }
            current = next->second;
          }
          if (current != startHalfedge || used.size() != componentEdges.size()) {
            fail_from_halfedge(
                SurfaceArrangementIncidenceFailure::IncompletePermutation,
                ordered.empty() ? -1 : ordered.back());
            return false;
          }
          const int component =
              static_cast<int>(audited.coreCycles.size());
          for (const int node : componentNodes) {
            coreComponentByNode.emplace(node, component);
          }
          audited.coreCycles.push_back(std::move(ordered));
        }

        audited.supportOnlyCycle = audited.coreCycles.empty();
        if (bridgeEdges.empty()) {
          if (audited.coreCycles.size() != 1U) {
            failure = SurfaceArrangementIncidenceFailure::IncompletePermutation;
            return false;
          }
          return true;
        }
        if (audited.supportOnlyCycle) {
          return true;
        }

        std::vector<int> coreParent(audited.coreCycles.size());
        std::iota(coreParent.begin(), coreParent.end(), 0);
        const auto find_core = [&](int index) {
          int root = index;
          while (coreParent[static_cast<std::size_t>(root)] != root) {
            root = coreParent[static_cast<std::size_t>(root)];
          }
          while (coreParent[static_cast<std::size_t>(index)] != index) {
            const int next = coreParent[static_cast<std::size_t>(index)];
            coreParent[static_cast<std::size_t>(index)] = root;
            index = next;
          }
          return root;
        };
        const auto unite_core = [&](const int lhs, const int rhs) {
          const int a = find_core(lhs);
          const int b = find_core(rhs);
          if (a != b) {
            coreParent[static_cast<std::size_t>(std::max(a, b))] =
                std::min(a, b);
          }
        };

        bool danglingBridge = false;
        std::set<int> visitedBridge;
        for (const auto &[seed, seedNeighbors] : bridgeAdjacency) {
          (void)seedNeighbors;
          if (visitedBridge.count(seed) != 0U) {
            continue;
          }
          std::set<int> attachedCoreComponents;
          std::vector<int> pending{seed};
          visitedBridge.insert(seed);
          while (!pending.empty()) {
            const int node = pending.back();
            pending.pop_back();
            const auto core = coreComponentByNode.find(node);
            if (core != coreComponentByNode.end()) {
              attachedCoreComponents.insert(core->second);
            }
            const auto found = bridgeAdjacency.find(node);
            if (found == bridgeAdjacency.end()) {
              continue;
            }
            if (found->second.size() == 1U &&
                coreComponentByNode.count(node) == 0U) {
              danglingBridge = true;
            }
            for (const int neighbor : found->second) {
              if (visitedBridge.insert(neighbor).second) {
                pending.push_back(neighbor);
              }
            }
          }
          if (attachedCoreComponents.size() < 2U) {
            danglingBridge = true;
          } else {
            const int representative = *attachedCoreComponents.begin();
            for (const int component : attachedCoreComponents) {
              unite_core(representative, component);
            }
          }
        }
        if (danglingBridge) {
          audited.bridgeExcursion = true;
          return true;
        }
        const int root = find_core(0);
        for (int component = 1;
             component < static_cast<int>(audited.coreCycles.size());
             ++component) {
          if (find_core(component) != root) {
            failure = SurfaceArrangementIncidenceFailure::IncompletePermutation;
            return false;
          }
        }
        audited.cutCellDisk = audited.coreCycles.size() >= 2U;
        if (!audited.cutCellDisk) {
          audited.bridgeExcursion = true;
        }
        return true;
      };

  std::vector<AuditedCycle> auditedCycles;
  if (directedIncidenceValid) {
    std::vector<unsigned char> visited(complex.halfedges.size(), 0U);
    for (int start = 0; start < static_cast<int>(complex.halfedges.size());
         ++start) {
      if (visited[static_cast<std::size_t>(start)] != 0U) {
        continue;
      }
      std::vector<int> cycle;
      std::set<int> localHalfedges;
      int current = start;
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
          if (current != start) {
            const SurfaceArrangementHalfedge &edge =
                complex.halfedges[static_cast<std::size_t>(current)];
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::RepeatedHalfedgeCycle,
                edge.from, edge.id, edge.twin, edge.next);
          }
          break;
        }
        cycle.push_back(current);
        current =
            complex.halfedges[static_cast<std::size_t>(current)].next;
      }
      if (!directedIncidenceValid) {
        break;
      }
      if (current != start) {
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::IncompletePermutation,
            cycle.empty()
                ? -1
                : complex.halfedges[static_cast<std::size_t>(cycle.back())].to,
            cycle.empty() ? start : cycle.back(),
            cycle.empty()
                ? -1
                : complex.halfedges[static_cast<std::size_t>(cycle.back())]
                      .twin,
            current);
        break;
      }

      AuditedCycle audited;
      SurfaceArrangementIncidenceFailure cycleFailure =
          SurfaceArrangementIncidenceFailure::None;
      int failureNode = -1;
      int failureHalfedge = -1;
      int failureTwin = -1;
      int failureNext = -1;
      if (!analyze_cycle(cycle, audited, cycleFailure, failureNode,
                         failureHalfedge, failureTwin, failureNext)) {
        if (cycleFailure ==
            SurfaceArrangementIncidenceFailure::RepeatedNodeCycle) {
          ++complex.diagnostics.repeatedNodeCycleCount;
        } else if (cycleFailure ==
                   SurfaceArrangementIncidenceFailure::RepeatedEdgeCycle) {
          ++complex.diagnostics.repeatedEdgeCycleCount;
        }
        record_incidence_failure(cycleFailure, failureNode, failureHalfedge,
                                 failureTwin, failureNext);
        break;
      }
      for (const int halfedgeId : cycle) {
        visited[static_cast<std::size_t>(halfedgeId)] = 1U;
      }
      auditedCycles.push_back(std::move(audited));
    }
    if (directedIncidenceValid &&
        std::any_of(visited.begin(), visited.end(),
                    [](const unsigned char value) { return value == 0U; })) {
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::IncompletePermutation, -1, -1,
          -1, -1);
    }
  }

  struct PendingCellRecord {
    SurfaceArrangementCell cell;
    std::vector<int> geometryHalfedges;
    std::vector<Eigen::Vector2d> polygon;
    int sourceBoundarySide = 0;
    double rawSignedArea = 0.0;
    bool geometryAvailable = false;
    bool consumed = false;
  };

  std::vector<PendingCellRecord> pendingRecords;
  if (!directedIncidenceValid) {
    auditedCycles.clear();
  }
  pendingRecords.reserve(auditedCycles.size());
  for (const AuditedCycle &audited : auditedCycles) {
    PendingCellRecord record;
    SurfaceArrangementCell &cell = record.cell;
    cell.id = -1;
    cell.halfedges = audited.halfedges;
    cell.boundaryCycleOffsets = {0};
    cell.closed = true;
    cell.cutCellDisk = audited.cutCellDisk;
    cell.bridgeExcursion = audited.bridgeExcursion;
    cell.supportOnlyCycle = audited.supportOnlyCycle;
    record.geometryHalfedges =
        audited.coreCycles.size() == 1U ? audited.coreCycles.front()
                                        : cell.halfedges;
    for (const int halfedgeId : cell.halfedges) {
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      if (cell.sourceFace < 0) {
        cell.sourceFace = halfedge.sourceFace;
      }
    }

    std::set<int> uniqueNodes;
    std::set<std::pair<int, int>> uniqueUndirectedEdges;
    for (const int halfedge : cell.halfedges) {
      const SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(halfedge)];
      uniqueNodes.insert(edge.from);
      uniqueUndirectedEdges.insert(
          {std::min(edge.from, edge.to), std::max(edge.from, edge.to)});
    }
    const bool simpleCycle =
        !cell.cutCellDisk && !cell.bridgeExcursion &&
        !cell.supportOnlyCycle && audited.coreCycles.size() == 1U &&
        uniqueNodes.size() == cell.halfedges.size() &&
        uniqueUndirectedEdges.size() == cell.halfedges.size();
    if (cell.supportOnlyCycle) {
      cell.boundaryComponentCount = 0;
      cell.eulerCharacteristic = 0;
      cell.disk = false;
    } else {
      cell.boundaryComponentCount = 1;
      cell.disk = simpleCycle || cell.cutCellDisk;
      cell.eulerCharacteristic = cell.disk ? 1 : 0;
    }

    const BoundarySideEvidence boundaryEvidence = boundary_side_evidence(
        cell.halfedges, complex.halfedges, complex.nodes, faces,
        sourceBoundaryTopology);
    cell.sourceBoundaryLoopIds = boundaryEvidence.loopIds;
    cell.sourceBoundarySide = boundaryEvidence.side;
    record.sourceBoundarySide = boundaryEvidence.side;
    if (boundaryEvidence.contradictory) {
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::ContradictoryBoundarySide,
          boundaryEvidence.failureHalfedge >= 0
              ? complex.halfedges[static_cast<std::size_t>(
                    boundaryEvidence.failureHalfedge)]
                    .from
              : -1,
          boundaryEvidence.failureHalfedge, -1, -1);
    }
    // Exact oriented source-side evidence is authoritative. Geometry and
    // traversal sign are never used to decide whether a source-boundary orbit
    // is exterior.
    cell.boundaryCycle = cell.closed && record.sourceBoundarySide < 0;

    std::vector<int> supportSourceFaces;
    collect_cell_source_faces(cell.halfedges, complex.halfedges,
                              supportSourceFaces);
    std::sort(supportSourceFaces.begin(), supportSourceFaces.end());
    supportSourceFaces.erase(
        std::unique(supportSourceFaces.begin(), supportSourceFaces.end()),
        supportSourceFaces.end());
    std::vector<int> geometrySourceFaces;
    record.geometryAvailable =
        !cell.supportOnlyCycle && !record.geometryHalfedges.empty() &&
        polygon_geometry(vertices, faces, record.geometryHalfedges,
                         complex.halfedges, complex.nodes, cell.signedArea,
                         cell.area, geometrySourceFaces);
    record.rawSignedArea = cell.signedArea;
    std::sort(geometrySourceFaces.begin(), geometrySourceFaces.end());
    geometrySourceFaces.erase(
        std::unique(geometrySourceFaces.begin(), geometrySourceFaces.end()),
        geometrySourceFaces.end());
    std::set_union(geometrySourceFaces.begin(), geometrySourceFaces.end(),
                   supportSourceFaces.begin(), supportSourceFaces.end(),
                   std::back_inserter(cell.sourceFaces));

    if (!record.geometryAvailable) {
      if (cell.boundaryCycle) {
        cell.signedArea = -1.0;
        cell.area = 0.0;
        record.rawSignedArea = -1.0;
      } else if (cell.cutCellDisk) {
        // A curved cut disk can span charts without one global projection.
        // Its audited source support supplies area only after the complete
        // bridge/core descriptor has passed structural validation.
        cell.area = 0.0;
        for (const int sourceFace : cell.sourceFaces) {
          cell.area += triangle_area_3d(vertices, faces, sourceFace);
        }
        cell.signedArea = cell.area;
        record.rawSignedArea = cell.signedArea;
        if (!(cell.area > 1.0e-20) || !std::isfinite(cell.area)) {
          embeddingValid = false;
          cell.area = 0.0;
          cell.signedArea = 0.0;
          record.rawSignedArea = 0.0;
        }
      } else if (cell.bridgeExcursion || cell.supportOnlyCycle) {
        cell.signedArea = 0.0;
        cell.area = 0.0;
        record.rawSignedArea = 0.0;
      } else {
        embeddingValid = false;
        cell.signedArea = 0.0;
        cell.area = 0.0;
        record.rawSignedArea = 0.0;
      }
    }

    if (record.geometryAvailable && cell.sourceFaces.size() == 1U) {
      const int polygonFace = cell.sourceFaces.front();
      record.polygon.reserve(record.geometryHalfedges.size());
      for (const int halfedgeId : record.geometryHalfedges) {
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        const Eigen::RowVector3d barycentric = node_barycentric_on_face(
            complex.nodes[static_cast<std::size_t>(halfedge.from)],
            polygonFace);
        if (!barycentric.allFinite()) {
          record.polygon.clear();
          break;
        }
        record.polygon.push_back(bary_to_uv(barycentric));
      }
    }

    // Side metadata describes one logical boundary. Bridge excursions use
    // their single area-bearing core; multiply connected cells clear this
    // metadata after their additional boundaries are attached below.
    const std::vector<int> &sideBoundary = record.geometryHalfedges.empty()
                                               ? cell.halfedges
                                               : record.geometryHalfedges;
    for (int index = 0; index < static_cast<int>(sideBoundary.size());
         ++index) {
      const auto &current = complex.halfedges[static_cast<std::size_t>(
          sideBoundary[static_cast<std::size_t>(index)])];
      bool continuesPrevious = false;
      if (index > 0 && !cell.sideFamilies.empty() &&
          cell.sideFamilies.back() == current.family) {
        const auto &previous = complex.halfedges[static_cast<std::size_t>(
            sideBoundary[static_cast<std::size_t>(index - 1)])];
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
          sideBoundary.back())];
      const auto &first = complex.halfedges[static_cast<std::size_t>(
          sideBoundary.front())];
      if (same_logical_side(last, first, complex.nodes, vertices, faces)) {
        cell.sideEdgeCounts.front() += cell.sideEdgeCounts.back();
        cell.sideEdgeCounts.pop_back();
        cell.sideFamilies.pop_back();
      }
    }
    pendingRecords.push_back(std::move(record));
  }

  // Every canonical source-boundary loop has exactly one arrangement orbit
  // on its exterior side. Interior hard rails carry no source-boundary loop
  // identity and therefore cannot manufacture additional exterior owners.
  if (directedIncidenceValid && resolvedOptions.insertBoundaryRails) {
    if (!sourceBoundaryTopology.valid) {
      record_incidence_failure(
          SurfaceArrangementIncidenceFailure::BoundaryLoopOwnerCount, -1, -1,
          -1, -1);
    } else {
      std::vector<int> exteriorOwners(
          static_cast<std::size_t>(sourceBoundaryTopology.loopCount), 0);
      for (const PendingCellRecord &record : pendingRecords) {
        if (record.sourceBoundarySide >= 0) {
          continue;
        }
        for (const int loop : record.cell.sourceBoundaryLoopIds) {
          if (loop < 0 || loop >= sourceBoundaryTopology.loopCount) {
            record_incidence_failure(
                SurfaceArrangementIncidenceFailure::BoundaryLoopOwnerCount,
                -1, -1, -1, -1);
            break;
          }
          ++exteriorOwners[static_cast<std::size_t>(loop)];
        }
        if (!directedIncidenceValid) {
          break;
        }
      }
      if (directedIncidenceValid) {
        const auto invalidOwner = std::find_if(
            exteriorOwners.begin(), exteriorOwners.end(),
            [](const int count) { return count != 1; });
        if (invalidOwner != exteriorOwners.end()) {
          record_incidence_failure(
              SurfaceArrangementIncidenceFailure::BoundaryLoopOwnerCount, -1,
              -1, -1,
              static_cast<int>(std::distance(exteriorOwners.begin(),
                                             invalidOwner)));
        }
      }
    }
  }
  if (!directedIncidenceValid) {
    pendingRecords.clear();
  }

  // Resolve no-witness internal cycles from the complete structural inventory.
  // A negatively oriented cycle contained by the smallest larger positive
  // cycle is an additional boundary of that bounded cell. If no such bounded
  // owner exists it is the unbounded arrangement orbit. This uses exact
  // successor cycles plus containment, rather than treating negative area as
  // source-topology exterior evidence.
  for (std::size_t holeIndex = 0; holeIndex < pendingRecords.size();
       ++holeIndex) {
    PendingCellRecord &hole = pendingRecords[holeIndex];
    if (hole.consumed || hole.cell.boundaryCycle ||
        hole.sourceBoundarySide != 0 || !hole.geometryAvailable ||
        hole.rawSignedArea >= -1.0e-14 || hole.polygon.size() < 3U ||
        hole.cell.supportOnlyCycle || hole.cell.bridgeExcursion ||
        hole.cell.cutCellDisk) {
      continue;
    }
    Eigen::Vector2d sample = Eigen::Vector2d::Zero();
    for (const Eigen::Vector2d &point : hole.polygon) {
      sample += point;
    }
    sample /= static_cast<double>(hole.polygon.size());

    int ownerIndex = -1;
    double ownerArea = std::numeric_limits<double>::infinity();
    for (std::size_t candidateIndex = 0;
         candidateIndex < pendingRecords.size(); ++candidateIndex) {
      if (candidateIndex == holeIndex) {
        continue;
      }
      PendingCellRecord &candidate = pendingRecords[candidateIndex];
      if (candidate.consumed || candidate.cell.boundaryCycle ||
          !candidate.geometryAvailable ||
          candidate.rawSignedArea <= 1.0e-14 ||
          candidate.cell.sourceFaces != hole.cell.sourceFaces ||
          candidate.polygon.size() < 3U ||
          candidate.cell.area <= hole.cell.area + 1.0e-14 ||
          !point_in_polygon(sample, candidate.polygon)) {
        continue;
      }
      if (candidate.cell.area < ownerArea) {
        ownerArea = candidate.cell.area;
        ownerIndex = static_cast<int>(candidateIndex);
      }
    }

    if (ownerIndex < 0) {
      hole.cell.boundaryCycle = true;
      continue;
    }

    PendingCellRecord &owner =
        pendingRecords[static_cast<std::size_t>(ownerIndex)];
    owner.cell.boundaryCycleOffsets.push_back(
        static_cast<int>(owner.cell.halfedges.size()));
    owner.cell.halfedges.insert(owner.cell.halfedges.end(),
                                hole.cell.halfedges.begin(),
                                hole.cell.halfedges.end());
    ++owner.cell.boundaryComponentCount;
    owner.cell.eulerCharacteristic = 2 - owner.cell.boundaryComponentCount;
    owner.cell.disk = false;
    owner.cell.quadReady = false;
    owner.cell.sideFamilies.clear();
    owner.cell.sideEdgeCounts.clear();
    owner.cell.area = std::max(0.0, owner.cell.area - hole.cell.area);
    owner.rawSignedArea = owner.cell.area;
    owner.cell.signedArea = owner.cell.area;
    hole.consumed = true;
  }

  std::vector<SurfaceArrangementCell> pendingCells;
  pendingCells.reserve(pendingRecords.size());
  for (PendingCellRecord &record : pendingRecords) {
    if (record.consumed) {
      continue;
    }
    SurfaceArrangementCell &cell = record.cell;
    if (cell.boundaryCycle) {
      cell.signedArea = -std::max(cell.area, 1.0e-12);
      cell.cellClass = SurfaceArrangementCellClass::Exterior;
      cell.quadReady = false;
    } else {
      cell.signedArea = std::abs(cell.area);
      if (!cell.disk) {
        cell.cellClass = SurfaceArrangementCellClass::NonDisk;
        cell.rejectReason = SurfaceArrangementRejectReason::NotFourSided;
        cell.quadReady = false;
      } else if (cell.area <= 1.0e-14) {
        cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
        cell.rejectReason = SurfaceArrangementRejectReason::Sliver;
      } else {
        const bool crossesHardBarrier = std::any_of(
            cell.halfedges.begin(), cell.halfedges.end(),
            [&](const int edge) {
              const SurfaceArrangementHalfedge &halfedge =
                  complex.halfedges[static_cast<std::size_t>(edge)];
              return complex.nodes[static_cast<std::size_t>(halfedge.from)]
                         .hardBarrierCrossing ||
                     complex.nodes[static_cast<std::size_t>(halfedge.to)]
                         .hardBarrierCrossing;
            });
        if (crossesHardBarrier) {
          cell.rejectReason =
              SurfaceArrangementRejectReason::HardFeatureCrossing;
        }
        bool alternating = true;
        for (int side = 0;
             side < static_cast<int>(cell.sideFamilies.size()); ++side) {
          const int first =
              cell.sideFamilies[static_cast<std::size_t>(side)];
          const int second = cell.sideFamilies[static_cast<std::size_t>(
              (side + 1) % static_cast<int>(cell.sideFamilies.size()))];
          if (first >= 0 && second >= 0 && first == second) {
            alternating = false;
          }
        }
        const int boundaryCount = std::accumulate(
            cell.sideEdgeCounts.begin(), cell.sideEdgeCounts.end(), 0);
        if (cell.sideFamilies.size() == 4U && alternating &&
            cell.rejectReason !=
                SurfaceArrangementRejectReason::HardFeatureCrossing) {
          cell.quadReady = true;
          cell.cellClass = SurfaceArrangementCellClass::RegularQuad;
        } else {
          cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
          if (cell.rejectReason !=
              SurfaceArrangementRejectReason::HardFeatureCrossing) {
            cell.rejectReason =
                !alternating
                    ? SurfaceArrangementRejectReason::NonAlternatingFamilies
                    : (boundaryCount % 2 != 0
                           ? SurfaceArrangementRejectReason::OddBoundaryParity
                           : SurfaceArrangementRejectReason::NotFourSided);
          }
        }
      }
    }
    pendingCells.push_back(std::move(cell));
  }

  // Cells are classified before ids are committed. Canonicalize the complete
  // boundary-cycle inventory by embedded undirected edges so source-face row
  // order and traversal starts cannot change cell ordinals.
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
    return std::make_tuple(
        cell.boundaryCycle ? 1 : 0, cell.cutCellDisk ? 1 : 0,
        cell.supportOnlyCycle ? 1 : 0, cell.bridgeExcursion ? 1 : 0,
        cell.sourceBoundarySide, cell.sourceBoundaryLoopIds,
        cell.boundaryComponentCount, sourceFaces, edges,
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
      SurfaceArrangementHalfedge &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      if (halfedge.cell >= 0) {
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::DuplicatePredecessor,
            halfedge.from, halfedge.id, halfedge.twin, halfedge.next);
        break;
      }
      halfedge.cell = cell.id;
    }
    complex.cells.push_back(std::move(cell));
  }
  if (directedIncidenceValid) {
    for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
      if (halfedge.cell < 0 ||
          halfedge.cell >= static_cast<int>(complex.cells.size())) {
        record_incidence_failure(
            SurfaceArrangementIncidenceFailure::IncompletePermutation,
            halfedge.from, halfedge.id, halfedge.twin, halfedge.next);
        break;
      }
    }
  }
  if (!directedIncidenceValid) {
    complex.cells.clear();
    for (SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
      halfedge.cell = -1;
    }
  }

  // Build intrinsic equivalence classes for per-face local source charts.
  // Local sheet integers are chart-local labels: adjacent source faces can use
  // different values while still representing one physical cell side. Charts
  // are joined only when the already-stitched DCEL contains the same intrinsic
  // node occurrence on both source faces. Same-face labels are never joined,
  // which keeps close/opposing sheets distinct.
  using SourceChart = SurfaceCellProjectionChart;
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
      const int component = transitionGraph.chart_component(SourceProjectionChart{
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
    std::set<int> authoritativeOrbitRoots;
    std::size_t authoritativeOrbitHalfedgeCount = 0U;
    bool firstBoundary = true;
    for (const int halfedgeId : cell.halfedges) {
      const SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      if (edge.authoritativeChartRoot >= 0) {
        authoritativeOrbitRoots.insert(edge.authoritativeChartRoot);
        ++authoritativeOrbitHalfedgeCount;
      }
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
    int selectedRoot = -1;
    if (authoritativeOrbitHalfedgeCount > 0U) {
      // Hard-rail authority is valid only for a complete directed bounded
      // orbit. Partial or conflicting publication is an embedding failure; no
      // root is selected by frequency, source-face order, or provenance order.
      if (authoritativeOrbitHalfedgeCount != cell.halfedges.size() ||
          authoritativeOrbitRoots.size() != 1U || cell.boundaryCycle) {
        embeddingValid = false;
        continue;
      }
      selectedRoot = *authoritativeOrbitRoots.begin();
    } else {
      selectedRoot = faceRoots.size() == 1U
                         ? *faceRoots.begin()
                         : (sharedRoots.size() == 1U
                                ? *sharedRoots.begin()
                                : -1);
    }
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

  // Multiply connected bounded cells were assembled transactionally from the
  // complete successor-orbit inventory before cell ids were published. No
  // post-publication cycle decomposition or topology relabeling is permitted.
  update_peak_memory(vector_storage_bytes(segments) + split_storage_bytes());

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
            make_scoped_node_key(faces, a, p, vertexFanScopes,
                                 sourceBoundaryLoopByVertexFan);
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
            faces, scopeSegment, point, vertexFanScopes,
            sourceBoundaryLoopByVertexFan);
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
    if (!cell.boundaryCycle && !cell.supportOnlyCycle) {
      complex.diagnostics.extractedArea += cell.area;
    }
  }
  complex.diagnostics.relativeAreaError =
      std::abs(complex.diagnostics.extractedArea -
               complex.diagnostics.supportedArea) /
      std::max(1.0e-20, complex.diagnostics.supportedArea);
  const int undirectedEdges = static_cast<int>(complex.halfedges.size()) / 2;
  const int boundedEulerContribution = std::accumulate(
      complex.cells.begin(), complex.cells.end(), 0,
      [](const int sum, const SurfaceArrangementCell &cell) {
        return sum + (!cell.boundaryCycle && !cell.supportOnlyCycle
                          ? cell.eulerCharacteristic
                          : 0);
      });
  complex.diagnostics.eulerCharacteristic =
      static_cast<int>(complex.nodes.size()) - undirectedEdges +
      boundedEulerContribution;

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
    const bool validSupportOnlyCycle =
        cell.supportOnlyCycle && cell.halfedges.size() == 2U &&
        complex.halfedges[static_cast<std::size_t>(cell.halfedges[0])].twin ==
            cell.halfedges[1] &&
        complex.halfedges[static_cast<std::size_t>(cell.halfedges[1])].twin ==
            cell.halfedges[0];
    std::vector<std::pair<std::size_t, std::size_t>> boundaryRanges;
    const bool validBoundaryRanges =
        surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges);
    if (!cell.closed || !validBoundaryRanges ||
        (cell.halfedges.size() < 3U && !validSupportOnlyCycle)) {
      incidenceValid = false;
    }
    if (!cell.supportOnlyCycle &&
        (cell.boundaryCycle ? !(cell.signedArea < -1.0e-14)
                            : !(cell.signedArea > 1.0e-14))) {
      if (cell.rejectReason != SurfaceArrangementRejectReason::Sliver) {
        orientationValid = false;
      }
    }
    if (!cell.boundaryCycle && !cell.disk) {
      cellsDiskValid = false;
    }
    std::set<int> seenCellHalfedges;
    for (const auto &[begin, end] : boundaryRanges) {
      for (std::size_t index = begin; index < end; ++index) {
        const int halfedgeId = cell.halfedges[index];
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(complex.halfedges.size()) ||
            !seenCellHalfedges.insert(halfedgeId).second ||
            complex.halfedges[static_cast<std::size_t>(halfedgeId)].cell !=
                cell.id) {
          incidenceValid = false;
          continue;
        }
        const int expectedNext =
            cell.halfedges[index + 1U < end ? index + 1U : begin];
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        if (halfedge.next != expectedNext ||
            halfedge.to !=
                complex.halfedges[static_cast<std::size_t>(expectedNext)].from) {
          incidenceValid = false;
        }
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
  bool boundaryValid = false;
  if (resolvedOptions.insertBoundaryRails) {
    std::vector<int> exteriorOwners(
        static_cast<std::size_t>(sourceBoundaryTopology.loopCount), 0);
    boundaryValid = sourceBoundaryTopology.valid;
    for (const SurfaceArrangementCell &cell : complex.cells) {
      if (!cell.boundaryCycle) {
        continue;
      }
      if (cell.sourceBoundarySide != -1 ||
          cell.sourceBoundaryLoopIds.empty()) {
        boundaryValid = false;
        continue;
      }
      for (const int loop : cell.sourceBoundaryLoopIds) {
        if (loop < 0 || loop >= sourceBoundaryTopology.loopCount) {
          boundaryValid = false;
          continue;
        }
        ++exteriorOwners[static_cast<std::size_t>(loop)];
      }
    }
    boundaryValid =
        boundaryValid &&
        std::all_of(exteriorOwners.begin(), exteriorOwners.end(),
                    [](const int owners) { return owners == 1; });
    complex.diagnostics.boundaryLoopCount =
        sourceBoundaryTopology.loopCount;
  } else {
    const auto arrangementBoundary = boundary_loop_count(
        static_cast<int>(complex.nodes.size()), arrangementBoundaryEdges);
    complex.diagnostics.boundaryLoopCount = arrangementBoundary.first;
    boundaryValid = arrangementBoundary.second;
  }
  complex.diagnostics.boundaryLoopsValid = boundaryValid;

  std::set<std::uint64_t> sourceEdges;
  std::vector<std::pair<int, int>> sourceGraphEdges;
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
  const bool sourceBoundaryValid = sourceBoundaryTopology.valid;
  complex.diagnostics.sourceBoundaryLoopCount =
      sourceBoundaryTopology.loopCount;
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
    for (const SurfaceCellProjectionChart &chart : record.exactCharts) {
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
    for (const SurfaceCellProjectionChart &chart : cell.sourceCharts) {
      mix(chart.sourceComponent);
      mix(chart.sourceFace);
      mix(chart.localSheet);
    }
    mix(cell.closed ? 1 : 0);
    mix(cell.disk ? 1 : 0);
    mix(cell.cutCellDisk ? 1 : 0);
    mix(cell.boundaryCycle ? 1 : 0);
    mix(cell.bridgeExcursion ? 1 : 0);
    mix(cell.supportOnlyCycle ? 1 : 0);
    mix(cell.sourceBoundarySide);
    for (const int loop : cell.sourceBoundaryLoopIds) {
      mix(loop);
    }
    mix(cell.boundaryComponentCount);
    mix(cell.eulerCharacteristic);
    std::vector<std::pair<std::size_t, std::size_t>> boundaryRanges;
    if (surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges)) {
      mix(static_cast<std::int64_t>(boundaryRanges.size()));
      for (const auto &[begin, end] : boundaryRanges) {
        mix(static_cast<std::int64_t>(end - begin));
      }
    } else {
      mix(-1);
    }
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
