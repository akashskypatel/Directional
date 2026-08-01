#include <directional/geometry/SurfaceArrangement.h>

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
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    if (occurrence.sourceFace == face) {
      return occurrence.barycentric;
    }
  }
  return node.sourceFace == face ? node.barycentric
                                 : Eigen::RowVector3d::Constant(
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
  const Eigen::Vector2d r = a.end - a.start;
  const Eigen::Vector2d s = b.end - b.start;
  const double denom = cross2(r, s);
  const Eigen::Vector2d qp = b.start - a.start;
  if (std::abs(denom) <= 1.0e-12) {
    if (std::abs(cross2(qp, r)) > 1.0e-12) {
      return false;
    }
    const double rr = std::max(1.0e-20, r.squaredNorm());
    const double t0 = (b.start - a.start).dot(r) / rr;
    const double t1 = (b.end - a.start).dot(r) / rr;
    const double lo = std::max(0.0, std::min(t0, t1));
    const double hi = std::min(1.0, std::max(t0, t1));
    if (lo > hi + 1.0e-12) {
      return false;
    }
    ta = lo;
    point = a.start + ta * r;
    const double ss = std::max(1.0e-20, s.squaredNorm());
    tb = (point - b.start).dot(s) / ss;
    return true;
  }
  ta = cross2(qp, s) / denom;
  tb = cross2(qp, r) / denom;
  if (ta < -1.0e-12 || ta > 1.0 + 1.0e-12 || tb < -1.0e-12 ||
      tb > 1.0 + 1.0e-12) {
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
  std::uint64_t bytes = vector_storage_bytes(complex.nodes) +
                        vector_storage_bytes(complex.halfedges) +
                        vector_storage_bytes(complex.cells);
  for (const SurfaceArrangementNode &node : complex.nodes) {
    bytes += vector_storage_bytes(node.occurrences);
  }
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    bytes += vector_storage_bytes(halfedge.provenance);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
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

SurfaceCellComplex build_surface_cell_complex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<SurfaceArrangementArc> &inputArcs,
    const SurfaceArrangementOptions &options) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("surface arrangement requires triangle mesh.");
  }
  using namespace surface_arrangement_detail;
  SurfaceCellComplex complex;
  std::uint64_t peakOwnedBytes = 0;
  const auto update_peak_memory = [&](const std::uint64_t temporaryBytes = 0) {
    peakOwnedBytes = std::max(
        peakOwnedBytes,
        complex_storage_bytes(complex) + temporaryBytes);
  };
  std::vector<Segment2> segments;
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);

  for (int face = 0; face < faces.rows(); ++face) {
    for (const auto &[a, b, edge] :
         {std::tuple<int, int, int>{0, 1, 2}, {1, 2, 0}, {2, 0, 1}}) {
      const std::uint64_t key = source_edge_key(faces, face, edge);
      const auto found = edgeFaces.find(key);
      const bool boundaryEdge =
          found == edgeFaces.end() || found->second[1] < 0;
      const bool hardFeature =
          options.hardFeatureEdges.count(key) != 0;
      if ((!options.insertBoundaryRails || !boundaryEdge) && !hardFeature) {
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
  std::set<NodeKey> intersectionKeys;
  std::set<NodeKey> hardBarrierCrossingKeys;
  for (int i = 0; i < static_cast<int>(segments.size()); ++i) {
    for (int j = i + 1; j < static_cast<int>(segments.size()); ++j) {
      if (segments[static_cast<std::size_t>(i)].sourceFace !=
          segments[static_cast<std::size_t>(j)].sourceFace) {
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
          hardBarrierCrossingKeys.insert(make_node_key(
              faces, segments[static_cast<std::size_t>(i)].sourceFace, p));
        }
      }
      intersectionKeys.insert(make_node_key(
          faces, segments[static_cast<std::size_t>(i)].sourceFace, p));
    }
  }
  complex.diagnostics.uniqueIntersections =
      static_cast<int>(intersectionKeys.size());
  complex.diagnostics.hardBarrierCrossings =
      static_cast<int>(hardBarrierCrossingKeys.size());
  update_peak_memory(vector_storage_bytes(segments));

  std::map<NodeKey, int> nodeByKey;
  bool embeddingValid = true;
  const double positionTolerance =
      1.0e-9 * std::max(1.0, (vertices.colwise().maxCoeff() -
                             vertices.colwise().minCoeff()).norm());
  const auto node_id = [&](const int face, const Eigen::Vector2d &rawUv) {
    const Eigen::RowVector3d bary =
        canonicalize_barycentric(uv_to_bary(rawUv));
    const Eigen::Vector2d uv = bary_to_uv(bary);
    const NodeKey key = make_node_key(faces, face, uv);
    auto found = nodeByKey.find(key);
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
          node.hardBarrierCrossing || hardBarrierCrossingKeys.count(key) != 0;
      const bool occurrenceExists =
          std::any_of(node.occurrences.begin(), node.occurrences.end(),
                      [&](const SurfaceArrangementNodeOccurrence &occurrence) {
                        return occurrence.sourceFace == face &&
                               (occurrence.barycentric - bary).norm() <= 1.0e-12;
                      });
      if (!occurrenceExists) {
        node.occurrences.push_back({face, bary});
        std::sort(node.occurrences.begin(), node.occurrences.end(),
                  [](const SurfaceArrangementNodeOccurrence &a,
                     const SurfaceArrangementNodeOccurrence &b) {
                    if (a.sourceFace != b.sourceFace) {
                      return a.sourceFace < b.sourceFace;
                    }
                    return std::tie(a.barycentric[0], a.barycentric[1],
                                    a.barycentric[2]) <
                           std::tie(b.barycentric[0], b.barycentric[1],
                                    b.barycentric[2]);
                  });
      }
      return found->second;
    }
    SurfaceArrangementNode node;
    node.id = static_cast<int>(complex.nodes.size());
    node.sourceFace = face;
    node.hardBarrierCrossing = hardBarrierCrossingKeys.count(key) != 0;
    node.barycentric = bary;
    node.sourceEdge =
        key.kind == 1 ? static_cast<int>(key.edge & 0x7fffffffu) : -1;
    node.sourceEdgeParameter =
        key.kind == 1 ? static_cast<double>(key.edgeT) / 1.0e10 : 0.0;
    node.occurrences.push_back({face, bary});
    nodeByKey.emplace(key, node.id);
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
      const int a = node_id(segment.sourceFace, p0);
      const int b = node_id(segment.sourceFace, p1);
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
    halfedge.railId = primary.railId;
    halfedge.curveId = primary.curveId;
    halfedge.sourceComponent = primary.sourceComponent;
    halfedge.sourceSheet = primary.sourceSheet;
    halfedge.proposalId = primary.proposalId;
    halfedge.proposalSeedId = primary.proposalSeedId;
    halfedge.proposalSide = primary.proposalSide;
    halfedge.proposalBoundarySegment = primary.proposalBoundarySegment;
    halfedge.railT0 = primary.railT0;
    halfedge.railT1 = primary.railT1;
  }

  std::vector<std::vector<int>> outgoing(complex.nodes.size());
  for (const SurfaceArrangementHalfedge &h : complex.halfedges) {
    outgoing[static_cast<std::size_t>(h.from)].push_back(h.id);
  }
  for (int nodeId = 0; nodeId < static_cast<int>(outgoing.size()); ++nodeId) {
    auto &list = outgoing[static_cast<std::size_t>(nodeId)];
    Eigen::RowVector3d axisX = Eigen::RowVector3d::Zero();
    Eigen::RowVector3d axisY = Eigen::RowVector3d::Zero();
    const Eigen::RowVector3d normal = node_reference_normal(
        vertices, faces, complex.nodes[static_cast<std::size_t>(nodeId)]);
    if (!tangent_basis(normal, axisX, axisY)) {
      embeddingValid = false;
    }
    const Eigen::RowVector3d origin = node_position(
        vertices, faces, complex.nodes[static_cast<std::size_t>(nodeId)]);
    std::sort(list.begin(), list.end(), [&](const int lhs, const int rhs) {
      const auto &a = complex.halfedges[static_cast<std::size_t>(lhs)];
      const auto &b = complex.halfedges[static_cast<std::size_t>(rhs)];
      Eigen::RowVector3d au =
          node_position(vertices, faces,
                        complex.nodes[static_cast<std::size_t>(a.to)]) -
          origin;
      Eigen::RowVector3d bu =
          node_position(vertices, faces,
                        complex.nodes[static_cast<std::size_t>(b.to)]) -
          origin;
      au -= au.dot(normal) * normal;
      bu -= bu.dot(normal) * normal;
      const double aa = std::atan2(au.dot(axisY), au.dot(axisX));
      const double ba = std::atan2(bu.dot(axisY), bu.dot(axisX));
      if (std::abs(aa - ba) > 1.0e-14) {
        return aa < ba;
      }
      return lhs < rhs;
    });
  }
  for (SurfaceArrangementHalfedge &h : complex.halfedges) {
    const int at = h.to;
    const int twin = h.twin;
    const auto &list = outgoing[static_cast<std::size_t>(at)];
    const auto found = std::find(list.begin(), list.end(), twin);
    if (list.empty() || found == list.end()) {
      embeddingValid = false;
      h.next = -1;
      continue;
    }
    const int pos = static_cast<int>(std::distance(list.begin(), found));
    const int nextPos = (pos - 1 + static_cast<int>(list.size())) %
                        static_cast<int>(list.size());
    h.next = list[static_cast<std::size_t>(nextPos)];
  }

  std::vector<unsigned char> visited(complex.halfedges.size(), 0);
  for (int start = 0; start < static_cast<int>(complex.halfedges.size()); ++start) {
    if (visited[static_cast<std::size_t>(start)] != 0) {
      continue;
    }
    SurfaceArrangementCell cell;
    cell.id = static_cast<int>(complex.cells.size());
    int h = start;
    for (int guard = 0; guard < static_cast<int>(complex.halfedges.size()) + 1;
         ++guard) {
      if (h < 0 || h >= static_cast<int>(complex.halfedges.size())) {
        embeddingValid = false;
        break;
      }
      if (visited[static_cast<std::size_t>(h)] != 0) {
        break;
      }
      visited[static_cast<std::size_t>(h)] = 1;
      cell.halfedges.push_back(h);
      const auto &he = complex.halfedges[static_cast<std::size_t>(h)];
      if (cell.sourceFace < 0) {
        cell.sourceFace = he.sourceFace;
      }
      h = he.next;
      if (h == start) {
        break;
      }
    }
    cell.closed = h == start;
    if (cell.halfedges.size() < 3 || !cell.closed) {
      embeddingValid = false;
      continue;
    }
    for (const int halfedgeId : cell.halfedges) {
      complex.halfedges[static_cast<std::size_t>(halfedgeId)].cell = cell.id;
    }
    // Establish the topological disk invariant from incidence before any
    // geometric area calculation. A curved multi-face cycle may not admit a
    // nondegenerate single-plane projection, but that cannot turn a closed,
    // simple DCEL cycle into a non-disk.
    std::set<int> uniqueNodes;
    for (const int halfedge : cell.halfedges) {
      uniqueNodes.insert(
          complex.halfedges[static_cast<std::size_t>(halfedge)].from);
    }
    cell.boundaryComponentCount = cell.closed ? 1 : 0;
    cell.eulerCharacteristic =
        static_cast<int>(uniqueNodes.size()) -
        static_cast<int>(cell.halfedges.size()) + (cell.closed ? 1 : 0);
    cell.disk = cell.closed && cell.boundaryComponentCount == 1 &&
                uniqueNodes.size() == cell.halfedges.size() &&
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
    complex.cells.push_back(cell);
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
    if (cell.boundaryCycle || !cell.closed || cell.area <= 1.0e-14) {
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
    cell.boundaryComponentCount = 1 + nestedBoundaryCount;
    cell.eulerCharacteristic = 2 - cell.boundaryComponentCount;
    cell.disk = cell.closed && cell.boundaryComponentCount == 1 &&
                cell.eulerCharacteristic == 1;
    if (!cell.disk) {
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
      double ta = 0.0;
      double tb = 0.0;
      Eigen::Vector2d p;
      if (segment_intersection_params(a, b, ta, tb, p) && ta > 1.0e-8 &&
          ta < 1.0 - 1.0e-8 && tb > 1.0e-8 && tb < 1.0 - 1.0e-8) {
        const NodeKey key = make_node_key(faces, a.sourceFace, p);
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
  bool incidenceValid = true;
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
  mix(static_cast<int>(complex.nodes.size()));
  mix(static_cast<int>(complex.halfedges.size()));
  mix(static_cast<int>(complex.cells.size()));
  for (const SurfaceArrangementNode &node : complex.nodes) {
    mix(node.hardBarrierCrossing ? 1 : 0);
    mix(node.sourceFace);
    mix(node.sourceEdge);
    mix(static_cast<std::int64_t>(std::llround(node.sourceEdgeParameter * 1.0e10)));
    for (int i = 0; i < 3; ++i) {
      mix(static_cast<std::int64_t>(std::llround(node.barycentric[i] * 1.0e10)));
    }
    mix(static_cast<int>(node.occurrences.size()));
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      mix(occurrence.sourceFace);
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
