#include <directional/validation/SourceAuthoritativeMeshValidator.h>

namespace directional::validation::source_authoritative_detail {

std::vector<int> face_vertices(const Eigen::MatrixXi &faces,
                                      const int face) {
  std::vector<int> vertices;
  for (int corner = 0; corner < faces.cols(); ++corner) {
    const int vertex = faces(face, corner);
    if (vertex >= 0) {
      vertices.push_back(vertex);
    }
  }
  return vertices;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

MeshTopologySummary summarize_topology(const Eigen::MatrixXi &faces) {
  MeshTopologySummary summary;
  std::set<int> usedVertices;
  std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
  std::vector<unsigned char> validFace(static_cast<std::size_t>(faces.rows()), 0);

  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> vertices = face_vertices(faces, face);
    if (vertices.size() < 3U) {
      continue;
    }
    validFace[static_cast<std::size_t>(face)] = 1;
    ++summary.faces;
    for (const int vertex : vertices) {
      usedVertices.insert(vertex);
    }
    for (std::size_t index = 0; index < vertices.size(); ++index) {
      edgeFaces[canonical_edge(vertices[index],
                               vertices[(index + 1U) % vertices.size()])]
          .push_back(face);
    }
  }
  summary.usedVertices = static_cast<int>(usedVertices.size());
  summary.edges = static_cast<int>(edgeFaces.size());
  summary.eulerCharacteristic =
      summary.usedVertices - summary.edges + summary.faces;

  std::vector<std::set<int>> faceAdjacency(
      static_cast<std::size_t>(faces.rows()));
  for (const auto &[edge, incidentFaces] : edgeFaces) {
    (void)edge;
    for (const int first : incidentFaces) {
      for (const int second : incidentFaces) {
        if (first != second) {
          faceAdjacency[static_cast<std::size_t>(first)].insert(second);
        }
      }
    }
  }
  std::vector<unsigned char> visitedFaces(
      static_cast<std::size_t>(faces.rows()), 0);
  for (int face = 0; face < faces.rows(); ++face) {
    if (!validFace[static_cast<std::size_t>(face)] ||
        visitedFaces[static_cast<std::size_t>(face)] != 0) {
      continue;
    }
    ++summary.connectedComponents;
    std::vector<int> stack{face};
    visitedFaces[static_cast<std::size_t>(face)] = 1;
    while (!stack.empty()) {
      const int current = stack.back();
      stack.pop_back();
      for (const int next : faceAdjacency[static_cast<std::size_t>(current)]) {
        if (visitedFaces[static_cast<std::size_t>(next)] == 0) {
          visitedFaces[static_cast<std::size_t>(next)] = 1;
          stack.push_back(next);
        }
      }
    }
  }

  std::map<int, std::set<int>> boundaryAdjacency;
  for (const auto &[edge, incidentFaces] : edgeFaces) {
    if (incidentFaces.size() == 1U) {
      boundaryAdjacency[edge.first].insert(edge.second);
      boundaryAdjacency[edge.second].insert(edge.first);
    }
  }
  for (const auto &[vertex, neighbors] : boundaryAdjacency) {
    (void)vertex;
    if (neighbors.size() != 2U) {
      summary.boundaryCyclesClosed = false;
    }
  }
  std::set<int> visitedBoundary;
  for (const auto &[start, neighbors] : boundaryAdjacency) {
    (void)neighbors;
    if (visitedBoundary.count(start) != 0) {
      continue;
    }
    ++summary.boundaryLoopCount;
    std::vector<int> stack{start};
    visitedBoundary.insert(start);
    while (!stack.empty()) {
      const int current = stack.back();
      stack.pop_back();
      for (const int next : boundaryAdjacency[current]) {
        if (visitedBoundary.insert(next).second) {
          stack.push_back(next);
        }
      }
    }
  }
  return summary;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

double orient2(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                      const Eigen::Vector2d &c) {
  return (b.x() - a.x()) * (c.y() - a.y()) -
         (b.y() - a.y()) * (c.x() - a.x());
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

int dominant_axis(const Eigen::Vector3d &normal) {
  const Eigen::Vector3d absolute = normal.cwiseAbs();
  int axis = 0;
  if (absolute(1) > absolute(axis)) {
    axis = 1;
  }
  if (absolute(2) > absolute(axis)) {
    axis = 2;
  }
  return axis;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

Eigen::Vector2d project2(const Eigen::Vector3d &point,
                                const int dropAxis) {
  if (dropAxis == 0) {
    return {point.y(), point.z()};
  }
  if (dropAxis == 1) {
    return {point.x(), point.z()};
  }
  return {point.x(), point.y()};
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool point_in_triangle2_strict(const Eigen::Vector2d &point,
                                      const Eigen::Vector2d &a,
                                      const Eigen::Vector2d &b,
                                      const Eigen::Vector2d &c,
                                      const double tolerance) {
  const double o0 = orient2(a, b, point);
  const double o1 = orient2(b, c, point);
  const double o2 = orient2(c, a, point);
  const bool positive = o0 > tolerance && o1 > tolerance && o2 > tolerance;
  const bool negative = o0 < -tolerance && o1 < -tolerance && o2 < -tolerance;
  return positive || negative;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool proper_segment_intersection2(const Eigen::Vector2d &a,
                                         const Eigen::Vector2d &b,
                                         const Eigen::Vector2d &c,
                                         const Eigen::Vector2d &d,
                                         const double tolerance) {
  const double o0 = orient2(a, b, c);
  const double o1 = orient2(a, b, d);
  const double o2 = orient2(c, d, a);
  const double o3 = orient2(c, d, b);
  return ((o0 > tolerance && o1 < -tolerance) ||
          (o0 < -tolerance && o1 > tolerance)) &&
         ((o2 > tolerance && o3 < -tolerance) ||
          (o2 < -tolerance && o3 > tolerance));
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool collinear_segment_overlap2(const Eigen::Vector2d &a,
                                       const Eigen::Vector2d &b,
                                       const Eigen::Vector2d &c,
                                       const Eigen::Vector2d &d,
                                       const double tolerance) {
  if (std::abs(orient2(a, b, c)) > tolerance ||
      std::abs(orient2(a, b, d)) > tolerance) {
    return false;
  }
  const Eigen::Vector2d direction = b - a;
  const int axis = std::abs(direction.x()) >= std::abs(direction.y()) ? 0 : 1;
  const double firstMin = std::min(a(axis), b(axis));
  const double firstMax = std::max(a(axis), b(axis));
  const double secondMin = std::min(c(axis), d(axis));
  const double secondMax = std::max(c(axis), d(axis));
  return std::min(firstMax, secondMax) - std::max(firstMin, secondMin) >
         tolerance;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool near_any(const Eigen::Vector3d &point,
                     const std::vector<Eigen::Vector3d> &allowed,
                     const double tolerance) {
  return std::any_of(allowed.begin(), allowed.end(), [&](const auto &candidate) {
    return (point - candidate).norm() <= tolerance;
  });
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool segment_triangle_intersection_point(
    const Eigen::Vector3d &p0, const Eigen::Vector3d &p1,
    const Eigen::Vector3d &a, const Eigen::Vector3d &b,
    const Eigen::Vector3d &c, const double tolerance,
    Eigen::Vector3d &intersection) {
  const Eigen::Vector3d direction = p1 - p0;
  const Eigen::Vector3d edge1 = b - a;
  const Eigen::Vector3d edge2 = c - a;
  const Eigen::Vector3d pvec = direction.cross(edge2);
  const double determinant = edge1.dot(pvec);
  const double scale =
      std::max({direction.norm(), edge1.norm(), edge2.norm(), tolerance});
  if (std::abs(determinant) <= tolerance * scale * scale) {
    return false;
  }
  const double inverse = 1.0 / determinant;
  const Eigen::Vector3d tvec = p0 - a;
  const double u = tvec.dot(pvec) * inverse;
  if (u < -tolerance || u > 1.0 + tolerance) {
    return false;
  }
  const Eigen::Vector3d qvec = tvec.cross(edge1);
  const double v = direction.dot(qvec) * inverse;
  if (v < -tolerance || u + v > 1.0 + tolerance) {
    return false;
  }
  const double t = edge2.dot(qvec) * inverse;
  if (t < -tolerance || t > 1.0 + tolerance) {
    return false;
  }
  intersection = p0 + t * direction;
  return true;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

std::vector<int> shared_vertices(const TrianglePrimitive &first,
                                        const TrianglePrimitive &second) {
  std::vector<int> shared;
  for (const int a : first.vertices) {
    for (const int b : second.vertices) {
      if (a == b) {
        shared.push_back(a);
      }
    }
  }
  std::sort(shared.begin(), shared.end());
  shared.erase(std::unique(shared.begin(), shared.end()), shared.end());
  return shared;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool coplanar_triangles_overlap(
    const std::array<Eigen::Vector3d, 3> &first,
    const std::array<Eigen::Vector3d, 3> &second,
    const std::vector<Eigen::Vector3d> &allowedTouches,
    const double tolerance) {
  const Eigen::Vector3d normal =
      (first[1] - first[0]).cross(first[2] - first[0]);
  const int axis = dominant_axis(normal);
  std::array<Eigen::Vector2d, 3> a;
  std::array<Eigen::Vector2d, 3> b;
  for (int index = 0; index < 3; ++index) {
    a[static_cast<std::size_t>(index)] =
        project2(first[static_cast<std::size_t>(index)], axis);
    b[static_cast<std::size_t>(index)] =
        project2(second[static_cast<std::size_t>(index)], axis);
  }
  for (int firstEdge = 0; firstEdge < 3; ++firstEdge) {
    for (int secondEdge = 0; secondEdge < 3; ++secondEdge) {
      const Eigen::Vector2d &a0 = a[static_cast<std::size_t>(firstEdge)];
      const Eigen::Vector2d &a1 =
          a[static_cast<std::size_t>((firstEdge + 1) % 3)];
      const Eigen::Vector2d &b0 = b[static_cast<std::size_t>(secondEdge)];
      const Eigen::Vector2d &b1 =
          b[static_cast<std::size_t>((secondEdge + 1) % 3)];
      if (proper_segment_intersection2(a0, a1, b0, b1, tolerance)) {
        return true;
      }
      if (collinear_segment_overlap2(a0, a1, b0, b1, tolerance)) {
        const bool firstIsAllowedEdge =
            near_any(first[static_cast<std::size_t>(firstEdge)], allowedTouches,
                     tolerance) &&
            near_any(first[static_cast<std::size_t>((firstEdge + 1) % 3)],
                     allowedTouches, tolerance);
        const bool secondIsAllowedEdge =
            near_any(second[static_cast<std::size_t>(secondEdge)], allowedTouches,
                     tolerance) &&
            near_any(second[static_cast<std::size_t>((secondEdge + 1) % 3)],
                     allowedTouches, tolerance);
        if (!(firstIsAllowedEdge && secondIsAllowedEdge)) {
          return true;
        }
      }
    }
  }
  for (int index = 0; index < 3; ++index) {
    if (point_in_triangle2_strict(a[static_cast<std::size_t>(index)], b[0],
                                  b[1], b[2], tolerance) ||
        point_in_triangle2_strict(b[static_cast<std::size_t>(index)], a[0],
                                  a[1], a[2], tolerance)) {
      return true;
    }
  }
  (void)allowedTouches;
  return false;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

bool triangles_intersect(
    const Eigen::MatrixXd &vertices, const TrianglePrimitive &first,
    const TrianglePrimitive &second, const double tolerance) {
  const std::vector<int> shared = shared_vertices(first, second);
  if (shared.size() >= 3U) {
    return false;
  }
  std::vector<Eigen::Vector3d> allowedTouches;
  for (const int vertex : shared) {
    allowedTouches.push_back(vertices.row(vertex).transpose());
  }

  std::array<Eigen::Vector3d, 3> a;
  std::array<Eigen::Vector3d, 3> b;
  for (int index = 0; index < 3; ++index) {
    a[static_cast<std::size_t>(index)] =
        vertices.row(first.vertices[static_cast<std::size_t>(index)]).transpose();
    b[static_cast<std::size_t>(index)] =
        vertices.row(second.vertices[static_cast<std::size_t>(index)]).transpose();
  }
  const Eigen::Vector3d normalA = (a[1] - a[0]).cross(a[2] - a[0]);
  const Eigen::Vector3d normalB = (b[1] - b[0]).cross(b[2] - b[0]);
  const double normalProduct = normalA.norm() * normalB.norm();
  const double edgeScale = std::max(
      { (a[1] - a[0]).norm(), (a[2] - a[0]).norm(),
        (b[1] - b[0]).norm(), (b[2] - b[0]).norm(), tolerance });
  const double angularTolerance =
      std::max(1.0e-12, tolerance / edgeScale);
  if (normalProduct > tolerance * tolerance &&
      normalA.cross(normalB).norm() <= angularTolerance * normalProduct &&
      std::abs(normalA.dot(b[0] - a[0])) <=
          tolerance * normalA.norm()) {
    return coplanar_triangles_overlap(a, b, allowedTouches, tolerance);
  }

  for (int edge = 0; edge < 3; ++edge) {
    Eigen::Vector3d point;
    if (segment_triangle_intersection_point(
            a[static_cast<std::size_t>(edge)],
            a[static_cast<std::size_t>((edge + 1) % 3)], b[0], b[1], b[2],
            tolerance, point) &&
        !near_any(point, allowedTouches, tolerance)) {
      return true;
    }
    if (segment_triangle_intersection_point(
            b[static_cast<std::size_t>(edge)],
            b[static_cast<std::size_t>((edge + 1) % 3)], a[0], a[1], a[2],
            tolerance, point) &&
        !near_any(point, allowedTouches, tolerance)) {
      return true;
    }
  }
  return false;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

std::vector<TrianglePrimitive>
triangulate_faces(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                  const double tolerance) {
  std::vector<TrianglePrimitive> triangles;
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, face);
    if (polygon.size() < 3U) {
      continue;
    }
    for (std::size_t index = 1; index + 1U < polygon.size(); ++index) {
      TrianglePrimitive triangle;
      triangle.vertices = {polygon[0], polygon[index], polygon[index + 1U]};
      triangle.parentFace = face;
      bool valid = true;
      for (const int vertex : triangle.vertices) {
        if (vertex < 0 || vertex >= vertices.rows()) {
          valid = false;
          break;
        }
        triangle.bounds.expand(vertices.row(vertex).transpose());
      }
      if (valid) {
        triangle.bounds.pad(tolerance);
        triangles.push_back(triangle);
      }
    }
  }
  return triangles;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

std::vector<std::vector<int>> extract_loops_from_edges(
    const std::set<std::pair<int, int>> &edges, bool &closed) {
  std::map<int, std::set<int>> adjacency;
  for (const auto &edge : edges) {
    adjacency[edge.first].insert(edge.second);
    adjacency[edge.second].insert(edge.first);
  }
  closed = true;
  for (const auto &[vertex, neighbors] : adjacency) {
    (void)vertex;
    if (neighbors.size() != 2U) {
      closed = false;
    }
  }
  std::set<std::pair<int, int>> visited;
  std::vector<std::vector<int>> loops;
  for (const auto &[start, neighbors] : adjacency) {
    for (const int firstNext : neighbors) {
      if (visited.count(canonical_edge(start, firstNext)) != 0) {
        continue;
      }
      std::vector<int> loop{start};
      int previous = start;
      int current = firstNext;
      visited.insert(canonical_edge(previous, current));
      while (current != start) {
        loop.push_back(current);
        const auto found = adjacency.find(current);
        if (found == adjacency.end()) {
          closed = false;
          break;
        }
        int next = -1;
        for (const int candidate : found->second) {
          if (candidate != previous &&
              visited.count(canonical_edge(current, candidate)) == 0) {
            next = candidate;
            break;
          }
        }
        if (next < 0 && found->second.count(start) != 0) {
          next = start;
        }
        if (next < 0 || loop.size() > adjacency.size() + 1U) {
          closed = false;
          break;
        }
        previous = current;
        current = next;
        visited.insert(canonical_edge(previous, current));
      }
      if (loop.size() >= 3U) {
        loops.push_back(loop);
      }
    }
  }
  return loops;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

std::vector<std::vector<int>> extract_boundary_loops(
    const Eigen::MatrixXi &faces, bool &closed) {
  std::map<std::pair<int, int>, int> incidence;
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, face);
    for (std::size_t index = 0; index < polygon.size(); ++index) {
      ++incidence[canonical_edge(polygon[index],
                                polygon[(index + 1U) % polygon.size()])];
    }
  }
  std::map<int, std::set<int>> adjacency;
  for (const auto &[edge, count] : incidence) {
    if (count == 1) {
      adjacency[edge.first].insert(edge.second);
      adjacency[edge.second].insert(edge.first);
    }
  }
  closed = true;
  for (const auto &[vertex, neighbors] : adjacency) {
    (void)vertex;
    if (neighbors.size() != 2U) {
      closed = false;
    }
  }

  std::set<std::pair<int, int>> visitedEdges;
  std::vector<std::vector<int>> loops;
  for (const auto &[start, neighbors] : adjacency) {
    for (const int firstNext : neighbors) {
      const auto firstEdge = canonical_edge(start, firstNext);
      if (visitedEdges.count(firstEdge) != 0) {
        continue;
      }
      std::vector<int> loop{start};
      int previous = -1;
      int current = start;
      int next = firstNext;
      while (true) {
        visitedEdges.insert(canonical_edge(current, next));
        previous = current;
        current = next;
        if (current == start) {
          break;
        }
        loop.push_back(current);
        const auto found = adjacency.find(current);
        if (found == adjacency.end() || found->second.empty()) {
          closed = false;
          break;
        }
        next = -1;
        for (const int candidate : found->second) {
          if (candidate != previous &&
              visitedEdges.count(canonical_edge(current, candidate)) == 0) {
            next = candidate;
            break;
          }
        }
        if (next < 0) {
          for (const int candidate : found->second) {
            if (candidate == start) {
              next = candidate;
              break;
            }
          }
        }
        if (next < 0 || loop.size() > adjacency.size() + 1U) {
          closed = false;
          break;
        }
      }
      if (loop.size() >= 3U) {
        loops.push_back(loop);
      }
    }
  }
  return loops;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

std::vector<int> canonical_loop(const std::vector<int> &input) {
  std::vector<int> loop = input;
  if (loop.size() > 1U && loop.front() == loop.back()) {
    loop.pop_back();
  }
  if (loop.empty()) {
    return loop;
  }
  std::vector<int> best;
  auto consider = [&](const std::vector<int> &candidate) {
    for (std::size_t offset = 0; offset < candidate.size(); ++offset) {
      std::vector<int> rotated;
      rotated.reserve(candidate.size());
      for (std::size_t index = 0; index < candidate.size(); ++index) {
        rotated.push_back(candidate[(offset + index) % candidate.size()]);
      }
      if (best.empty() || rotated < best) {
        best = std::move(rotated);
      }
    }
  };
  consider(loop);
  std::reverse(loop.begin(), loop.end());
  consider(loop);
  return best;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

SourceChartCompatibility SourcePointLabelSupport::resolve_compatible_chart(
    const std::vector<const geometry::SurfacePoint *> &points,
    const std::vector<const SourceVertexChartAuthority *> &authorities,
    const std::vector<geometry::SurfacePoint> *completePoints,
    const std::vector<SourceVertexChartAuthority> *completeAuthorities) const {
  SourceChartCompatibility result;
  if (!available() || points.empty() ||
      (!authorities.empty() && authorities.size() != points.size())) {
    return result;
  }

  struct PointCandidate {
    bool scalar = false;
    bool witnessed = false;
    std::set<int> exactFaces;
  };
  struct AuthorityGraph {
    std::set<int> scalarRoots;
    std::map<int, std::set<int>> exactFaces;
    std::map<int, std::set<int>> adjacency;
    std::set<int> reachable;
    std::set<int> witnessed;
  };

  const auto route_is_well_formed = [](
                                        const authority::CanonicalRoute &route) {
    if (route.empty()) return false;
    std::set<authority::SourceEdgeTopologyKey> uniqueTopology;
    for (const authority::TransitionStep &step : route.steps()) {
      if (step.kind() != authority::TransitionStepKind::Interior ||
          !step.interior().has_value() ||
          !uniqueTopology.insert(step.topology()).second) {
        return false;
      }
    }
    return true;
  };
  const auto point_touches_edge = [](
                                      const geometry::SurfacePointSourceSupport
                                          &support,
                                      const authority::SourceEdgeTopologyKey
                                          &topology) {
    if (!support.identity.has_value()) return false;
    if (const auto *edgeSupport =
            std::get_if<authority::SourceEdgeSupport>(&support.identity.value())) {
      return edgeSupport->edge == topology;
    }
    if (const auto *vertexSupport =
            std::get_if<authority::SourceVertexSupport>(&support.identity.value())) {
      return vertexSupport->vertex == topology.first() ||
             vertexSupport->vertex == topology.second();
    }
    return false;
  };
  const auto relation_components = [&](
                                        const SourceHardRailChartEquivalence
                                            &equivalence,
                                        const geometry::SurfacePointSourceSupport
                                            &support,
                                        std::pair<int, int> &components) {
    if (equivalence.firstFrontEdge < 0 ||
        equivalence.firstFrontEdge >= equivalence.secondFrontEdge ||
        !equivalence.rail.has_value() ||
        !route_is_well_formed(equivalence.route)) {
      return false;
    }
    bool touchesPoint = false;
    std::pair<int, int> separated{-1, -1};
    for (const authority::TransitionStep &step : equivalence.route.steps()) {
      const authority::SourceEdgeTopologyKey &topology = step.topology();
      const auto incidence = sourceEdgeFaces.find(topology);
      if (hardFeatureTopologies.count(topology) == 0U ||
          incidence == sourceEdgeFaces.end() ||
          incidence->second.size() != 2U) {
        return false;
      }
      const int firstComponent =
          transitionGraph.chart_component(incidence->second[0]);
      const int secondComponent =
          transitionGraph.chart_component(incidence->second[1]);
      if (firstComponent < 0 || secondComponent < 0 ||
          firstComponent == secondComponent) {
        return false;
      }
      const std::pair<int, int> edgeComponents{
          std::min(firstComponent, secondComponent),
          std::max(firstComponent, secondComponent)};
      if (separated.first < 0) {
        separated = edgeComponents;
      } else if (separated != edgeComponents) {
        return false;
      }
      touchesPoint = touchesPoint || point_touches_edge(support, topology);
    }
    if (!touchesPoint || separated.first < 0) {
      return false;
    }
    components = separated;
    return true;
  };
  const auto initialize_scalar_state = [&]
      (const geometry::SurfacePoint &point,
       geometry::SurfacePointSourceSupport &support,
       std::optional<geometry::SourceProjectionChart> &declared,
       std::set<int> &scalarComponents,
       std::map<int, std::set<int>> &exactFaces) {
    if (point.face < 0 || point.face >= sourceFaces->rows()) {
      return false;
    }
    declared = transitionGraph.chart(point.face);
    if (!declared.has_value()) {
      return false;
    }
    const auto declaredComponent =
        transitionGraph.source_component(declared.value());
    const auto declaredSheet =
        transitionGraph.isolation_sheet(declared.value());
    if (!declaredComponent.has_value() || !declaredSheet.has_value()) {
      return false;
    }
    support = sourceSupport.resolve(point);
    if (!support.valid()) {
      return false;
    }
    for (const authority::SourceFaceId sourceFace : support.incidentFaces) {
      const auto faceRow = sourceFaceRows.find(sourceFace);
      if (faceRow == sourceFaceRows.end()) {
        return false;
      }
      const int face = faceRow->second;
      geometry::SurfacePoint rebound;
      if (!transitionGraph.rebind(point, face, rebound)) {
        continue;
      }
      const int component = transitionGraph.chart_component(face);
      if (component >= 0) {
        scalarComponents.insert(component);
        exactFaces[component].insert(face);
      }
    }
    return !scalarComponents.empty();
  };

  std::vector<std::map<int, PointCandidate>> candidates(points.size());
  if (authorities.empty()) {
    for (std::size_t pointIndex = 0; pointIndex < points.size(); ++pointIndex) {
      const geometry::SurfacePoint *point = points[pointIndex];
      geometry::SurfacePointSourceSupport support;
      std::optional<geometry::SourceProjectionChart> declared;
      std::set<int> scalarComponents;
      std::map<int, std::set<int>> exactFaces;
      if (point == nullptr ||
          !initialize_scalar_state(*point, support, declared,
                                   scalarComponents, exactFaces)) {
        return {};
      }
      for (const int component : scalarComponents) {
        PointCandidate &candidate = candidates[pointIndex][component];
        candidate.scalar = true;
        candidate.witnessed = true;
        candidate.exactFaces = exactFaces[component];
      }
    }
  } else {
    if (completePoints == nullptr || completeAuthorities == nullptr ||
        completePoints->size() != completeAuthorities->size() ||
        completePoints->empty()) {
      return {};
    }

    std::map<const SourceVertexChartAuthority *, std::size_t>
        authorityIndices;
    std::vector<AuthorityGraph> graphs(completeAuthorities->size());
    std::map<SourceHardRailChartEquivalence, std::set<std::size_t>>
        relationOwners;
    for (std::size_t vertex = 0; vertex < completeAuthorities->size();
         ++vertex) {
      const SourceVertexChartAuthority &authority =
          (*completeAuthorities)[vertex];
      authorityIndices.emplace(&authority, vertex);
      if (!authority.retained || authority.sourceCharts.empty() ||
          !std::is_sorted(authority.sourceCharts.begin(),
                          authority.sourceCharts.end()) ||
          std::adjacent_find(authority.sourceCharts.begin(),
                             authority.sourceCharts.end()) !=
              authority.sourceCharts.end() ||
          !std::is_sorted(authority.hardRailEquivalences.begin(),
                          authority.hardRailEquivalences.end()) ||
          std::adjacent_find(authority.hardRailEquivalences.begin(),
                             authority.hardRailEquivalences.end()) !=
              authority.hardRailEquivalences.end()) {
        return {};
      }

      geometry::SurfacePointSourceSupport support;
      std::optional<geometry::SourceProjectionChart> declared;
      std::set<int> scalarComponents;
      std::map<int, std::set<int>> scalarFaces;
      if (!initialize_scalar_state((*completePoints)[vertex], support,
                                   declared, scalarComponents, scalarFaces)) {
        return {};
      }
      if (!declared.has_value() ||
          !std::binary_search(authority.sourceCharts.begin(),
                              authority.sourceCharts.end(), declared.value())) {
        return {};
      }

      AuthorityGraph &graph = graphs[vertex];
      for (const geometry::SourceProjectionChart &chart :
           authority.sourceCharts) {
        const auto sourceFaceId = transitionGraph.source_face_row(chart);
        if (!chart.valid() || !sourceFaceId.has_value() ||
            !std::binary_search(support.incidentFaces.begin(),
                                support.incidentFaces.end(),
                                sourceFaceId.value())) {
          return {};
        }
        const int sourceFace = static_cast<int>(sourceFaceId->index());
        const auto actual = transitionGraph.chart(sourceFace);
        if (!actual.has_value() || actual.value() != chart ||
            !declared.has_value()) {
          return {};
        }
        const auto actualComponent =
            transitionGraph.source_component(actual.value());
        const auto declaredComponent =
            transitionGraph.source_component(declared.value());
        if (!actualComponent.has_value() || !declaredComponent.has_value() ||
            actualComponent.value() != declaredComponent.value()) {
          return {};
        }
        const int component = transitionGraph.chart_component(actual.value());
        if (component < 0) {
          return {};
        }
        graph.exactFaces[component].insert(sourceFace);
      }
      for (const int component : scalarComponents) {
        if (graph.exactFaces.count(component) != 0U) {
          graph.scalarRoots.insert(component);
          graph.exactFaces[component].insert(
              scalarFaces[component].begin(), scalarFaces[component].end());
        }
      }
      if (graph.scalarRoots.empty()) {
        return {};
      }

      for (const SourceHardRailChartEquivalence &equivalence :
           authority.hardRailEquivalences) {
        std::pair<int, int> endpoints;
        if (!relation_components(equivalence, support, endpoints) ||
            graph.exactFaces.count(endpoints.first) == 0U ||
            graph.exactFaces.count(endpoints.second) == 0U) {
          return {};
        }
        graph.adjacency[endpoints.first].insert(endpoints.second);
        graph.adjacency[endpoints.second].insert(endpoints.first);
        relationOwners[equivalence].insert(vertex);
      }

      std::vector<int> stack(graph.scalarRoots.begin(),
                             graph.scalarRoots.end());
      graph.reachable.insert(graph.scalarRoots.begin(),
                             graph.scalarRoots.end());
      while (!stack.empty()) {
        const int component = stack.back();
        stack.pop_back();
        const auto adjacent = graph.adjacency.find(component);
        if (adjacent == graph.adjacency.end()) {
          continue;
        }
        for (const int next : adjacent->second) {
          if (graph.reachable.insert(next).second) {
            graph.witnessed.insert(next);
            stack.push_back(next);
          }
        }
      }
      for (const auto &[component, faces] : graph.exactFaces) {
        if (faces.empty() || graph.reachable.count(component) == 0U) {
          return {};
        }
      }
    }

    for (const auto &[equivalence, owners] : relationOwners) {
      (void)equivalence;
      if (owners.size() != 2U) {
        return {};
      }
    }

    for (std::size_t pointIndex = 0; pointIndex < points.size(); ++pointIndex) {
      const SourceVertexChartAuthority *authority = authorities[pointIndex];
      const auto found = authorityIndices.find(authority);
      if (authority == nullptr || found == authorityIndices.end() ||
          points[pointIndex] != &(*completePoints)[found->second]) {
        return {};
      }
      const AuthorityGraph &graph = graphs[found->second];
      for (const auto &[component, faces] : graph.exactFaces) {
        if (graph.reachable.count(component) == 0U) {
          continue;
        }
        PointCandidate &candidate = candidates[pointIndex][component];
        candidate.scalar = graph.scalarRoots.count(component) != 0U;
        candidate.witnessed = candidate.scalar ||
                              graph.witnessed.count(component) != 0U;
        candidate.exactFaces = faces;
      }
    }
  }

  std::set<int> commonComponents;
  for (const auto &[component, candidate] : candidates.front()) {
    (void)candidate;
    commonComponents.insert(component);
  }
  for (std::size_t pointIndex = 1; pointIndex < candidates.size();
       ++pointIndex) {
    std::set<int> intersection;
    for (const int component : commonComponents) {
      if (candidates[pointIndex].count(component) != 0U) {
        intersection.insert(component);
      }
    }
    commonComponents = std::move(intersection);
  }
  if (commonComponents.size() != 1U) {
    return {};
  }
  const int selectedComponent = *commonComponents.begin();
  for (std::size_t pointIndex = 0; pointIndex < candidates.size();
       ++pointIndex) {
    const PointCandidate &candidate =
        candidates[pointIndex].at(selectedComponent);
    if (!candidate.scalar && !candidate.witnessed) {
      return {};
    }
  }

  result.chartComponent = selectedComponent;
  result.semanticSide =
      transitionGraph.chart_component_identity(selectedComponent);
  result.chartFaces =
      transitionGraph.chart_component_faces(selectedComponent);
  result.pointFaces.reserve(candidates.size());
  for (const auto &pointCandidates : candidates) {
    const PointCandidate &candidate =
        pointCandidates.at(selectedComponent);
    result.pointFaces.emplace_back(candidate.exactFaces.begin(),
                                   candidate.exactFaces.end());
  }
  return result.valid() ? result : SourceChartCompatibility{};
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation::source_authoritative_detail {

Eigen::Vector3d polygon_normal(const Eigen::MatrixXd &vertices,
                                      const std::vector<int> &polygon) {
  Eigen::Vector3d normal = Eigen::Vector3d::Zero();
  if (polygon.size() < 3U) {
    return normal;
  }
  const Eigen::Vector3d origin = vertices.row(polygon[0]).transpose();
  for (std::size_t index = 1; index + 1U < polygon.size(); ++index) {
    const Eigen::Vector3d first =
        vertices.row(polygon[index]).transpose() - origin;
    const Eigen::Vector3d second =
        vertices.row(polygon[index + 1U]).transpose() - origin;
    normal += first.cross(second);
  }
  return normal;
}

} // namespace directional::validation::source_authoritative_detail

namespace directional::validation {

MeshTopologySummary summarize_mesh_topology(const Eigen::MatrixXi &faces) {
  return source_authoritative_detail::summarize_topology(faces);
}

} // namespace directional::validation

namespace directional::validation {

SourceAuthoritativeMeshValidationResult
validate_source_authoritative_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SourceAuthoritativeMeshValidatorOptions &options) {
  using namespace source_authoritative_detail;
  SourceAuthoritativeMeshValidationResult result;
  result.spatialAccelerationUsed = true;
  if (options.sourceVertices == nullptr || options.sourceFaces == nullptr ||
      options.sourceAuthority == nullptr || options.vertexProvenance == nullptr ||
      options.sourceVertices->cols() != 3 || options.sourceFaces->cols() != 3 ||
      !options.sourceAuthority->matches_source_faces(
          *options.sourceFaces,
          static_cast<std::size_t>(options.sourceVertices->rows()))) {
    result.fail({MeshValidationFailureCode::MissingSourceAuthority});
    return result;
  }
  result.sourceAuthorityUsed = true;
  result.strictValidationUsed =
      options.requireBoundaryAuthority && options.requireFeatureRailAuthority &&
      options.requireLocalSheetCompatibility;
  result.provenanceValidationUsed = true;
  result.featureRailAuthorityUsed = options.requireFeatureRailAuthority;
  result.sourceTopology = summarize_topology(*options.sourceFaces);
  result.boundaryAuthorityUsed =
      options.requireBoundaryAuthority && result.sourceTopology.boundaryLoopCount > 0;
  result.outputTopology = summarize_topology(faces);

  MeshValidatorOptions topologyOptions;
  topologyOptions.topologyOnly = true;
  topologyOptions.requireConsistentOrientation = true;
  topologyOptions.expectedConnectedComponents =
      static_cast<std::size_t>(std::max(0, result.sourceTopology.connectedComponents));
  topologyOptions.authoritativeBoundaryEdges =
      options.authoritativeBoundaryEdges;
  for (const auto &loop : options.authoritativeBoundaryLoops) {
    for (std::size_t index = 0; index < loop.size(); ++index) {
      topologyOptions.authoritativeBoundaryEdges.insert(canonical_edge(
          loop[index], loop[(index + 1U) % loop.size()]));
    }
  }
  topologyOptions.requireAuthoritativeBoundary =
      options.requireBoundaryAuthority &&
      result.sourceTopology.boundaryLoopCount > 0;
  const MeshValidationResult topology =
      MeshValidator::validate_surface_mesh(vertices, faces, topologyOptions);
  for (const MeshValidationIssue &issue : topology.issues) {
    result.fail(issue);
  }

  if (result.outputTopology.connectedComponents !=
      result.sourceTopology.connectedComponents) {
    result.fail({MeshValidationFailureCode::ComponentMerge});
  }
  if (result.outputTopology.eulerCharacteristic !=
      result.sourceTopology.eulerCharacteristic) {
    result.fail({MeshValidationFailureCode::ChangedEulerCharacteristic});
  }

  bool actualBoundaryClosed = true;
  std::vector<std::vector<int>> actualLoops =
      extract_boundary_loops(faces, actualBoundaryClosed);
  bool authorityBoundaryClosed = true;
  std::vector<std::vector<int>> expectedLoops =
      extract_loops_from_edges(topologyOptions.authoritativeBoundaryEdges,
                               authorityBoundaryClosed);
  if (topologyOptions.authoritativeBoundaryEdges.empty()) {
    expectedLoops = options.authoritativeBoundaryLoops;
  }
  for (auto &loop : actualLoops) {
    loop = canonical_loop(loop);
  }
  for (auto &loop : expectedLoops) {
    loop = canonical_loop(loop);
  }
  std::sort(actualLoops.begin(), actualLoops.end());
  std::sort(expectedLoops.begin(), expectedLoops.end());
  result.orderedBoundaryCyclesPassed =
      actualBoundaryClosed && authorityBoundaryClosed &&
      actualLoops == expectedLoops &&
      static_cast<int>(actualLoops.size()) ==
          result.sourceTopology.boundaryLoopCount;
  if (!result.orderedBoundaryCyclesPassed) {
    if (options.requireBoundaryAuthority &&
        result.sourceTopology.boundaryLoopCount > 0 && expectedLoops.empty()) {
      result.fail({MeshValidationFailureCode::MissingBoundaryAuthority});
    } else {
      result.fail({MeshValidationFailureCode::ChangedBoundaryLoop});
    }
  }

  std::map<std::pair<int, int>, int> outputEdges;
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, face);
    for (std::size_t index = 0; index < polygon.size(); ++index) {
      ++outputEdges[canonical_edge(polygon[index],
                                   polygon[(index + 1U) % polygon.size()])];
    }
  }
  result.featureRailsPassed =
      options.authoritativeFeatureRails.size() == options.expectedFeatureRailCount;
  for (const auto &rail : options.authoritativeFeatureRails) {
    if (rail.size() < 2U) {
      result.featureRailsPassed = false;
      continue;
    }
    for (std::size_t index = 0; index + 1U < rail.size(); ++index) {
      if (outputEdges.count(canonical_edge(rail[index], rail[index + 1U])) == 0) {
        result.featureRailsPassed = false;
      }
    }
  }
  if (options.requireFeatureRailAuthority && !result.featureRailsPassed) {
    result.fail({MeshValidationFailureCode::MissingFeatureRail});
  }

  const auto &provenance = *options.vertexProvenance;
  const SourcePointLabelSupport labelSupport(
      options.sourceFaces, options.sourceAuthority,
      &options.sourceHardFeatureEdges);
  const double sourceScale =
      options.sourceVertices->rows() == 0
          ? 1.0
          : std::max(
                std::numeric_limits<double>::epsilon(),
                (options.sourceVertices->colwise().maxCoeff() -
                 options.sourceVertices->colwise().minCoeff())
                    .norm());
  const double positionTolerance =
      std::max(options.geometricTolerance, 1.0e-12) * sourceScale * 32.0;
  result.provenanceCoverageComplete =
      provenance.size() >= static_cast<std::size_t>(vertices.rows());
  if (!result.provenanceCoverageComplete) {
    result.fail({MeshValidationFailureCode::MissingProvenance});
  }
  const bool chartAuthorityCardinalityValid =
      options.vertexChartAuthority == nullptr ||
      options.vertexChartAuthority->size() ==
          static_cast<std::size_t>(vertices.rows());

  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    if (static_cast<std::size_t>(vertex) >= provenance.size()) {
      continue;
    }
    const geometry::SurfacePoint &point =
        provenance[static_cast<std::size_t>(vertex)];
    if (!point.valid() || point.face < 0 ||
        point.face >= options.sourceFaces->rows() ||
        !point.barycentric.allFinite() ||
        std::abs(point.barycentric.sum() - 1.0) > 1.0e-7 ||
        point.barycentric.minCoeff() < -1.0e-8 ||
        point.barycentric.maxCoeff() > 1.0 + 1.0e-8) {
      result.provenanceCoverageComplete = false;
      result.fail({MeshValidationFailureCode::InvalidProvenance, vertex});
      continue;
    }
    const int a = (*options.sourceFaces)(point.face, 0);
    const int b = (*options.sourceFaces)(point.face, 1);
    const int c = (*options.sourceFaces)(point.face, 2);
    if (a < 0 || b < 0 || c < 0 || a >= options.sourceVertices->rows() ||
        b >= options.sourceVertices->rows() || c >= options.sourceVertices->rows()) {
      result.provenanceCoverageComplete = false;
      result.fail({MeshValidationFailureCode::InvalidProvenance, vertex});
      continue;
    }
    const Eigen::Vector3d reconstructed =
        point.barycentric(0) * options.sourceVertices->row(a).transpose() +
        point.barycentric(1) * options.sourceVertices->row(b).transpose() +
        point.barycentric(2) * options.sourceVertices->row(c).transpose();
    if ((vertices.row(vertex).transpose() - reconstructed).norm() >
            positionTolerance ||
        (point.position - reconstructed).norm() > positionTolerance) {
      result.provenanceCoverageComplete = false;
      result.fail({MeshValidationFailureCode::SourcePositionMismatch, vertex});
    }
    if (options.sourceAuthority != nullptr &&
        options.sourceAuthority->matches_source_faces(
            *options.sourceFaces,
            static_cast<std::size_t>(options.sourceVertices->rows()))) {
      const auto sourceFaceId = authority::SourceFaceId::from_index(
          point.face, options.sourceAuthority->face_count());
      if (!sourceFaceId) {
        result.fail({MeshValidationFailureCode::InvalidProvenance, vertex});
      }
    }
  }

  result.localSheetCompatibilityPassed = true;
  if (options.requireLocalSheetCompatibility &&
      (options.sourceAuthority == nullptr ||
       !options.sourceAuthority->matches_source_faces(
           *options.sourceFaces,
           static_cast<std::size_t>(options.sourceVertices->rows())) ||
       !chartAuthorityCardinalityValid)) {
    result.localSheetCompatibilityPassed = false;
    if (!chartAuthorityCardinalityValid) {
      result.fail({MeshValidationFailureCode::LocalSheetMismatch});
    } else {
      result.fail({MeshValidationFailureCode::MissingSourceAuthority});
    }
  }
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, face);
    std::vector<const geometry::SurfacePoint *> facePoints;
    std::vector<const SourceVertexChartAuthority *> faceAuthorities;
    facePoints.reserve(polygon.size());
    faceAuthorities.reserve(polygon.size());
    int invalidVertex = -1;
    bool faceProvenanceValid = chartAuthorityCardinalityValid;
    for (const int vertex : polygon) {
      if (vertex < 0 || static_cast<std::size_t>(vertex) >= provenance.size()) {
        invalidVertex = vertex;
        faceProvenanceValid = false;
        break;
      }
      facePoints.push_back(&provenance[static_cast<std::size_t>(vertex)]);
      if (options.vertexChartAuthority != nullptr &&
          chartAuthorityCardinalityValid) {
        faceAuthorities.push_back(&(*options.vertexChartAuthority)[
            static_cast<std::size_t>(vertex)]);
      }
    }
    const SourceChartCompatibility faceChart =
        faceProvenanceValid
            ? labelSupport.resolve_compatible_chart(facePoints,
                                                    faceAuthorities,
                                                    &provenance,
                                                    options.vertexChartAuthority)
            : SourceChartCompatibility{};
    if (options.requireLocalSheetCompatibility && !faceChart.valid()) {
      result.localSheetCompatibilityPassed = false;
      result.fail({MeshValidationFailureCode::LocalSheetMismatch,
                   invalidVertex, -1, -1, face});
    }

    const Eigen::Vector3d outputNormal = polygon_normal(vertices, polygon);
    Eigen::Vector3d sourceNormal = Eigen::Vector3d::Zero();
    int authoritativeSourceFace = -1;
    if (options.outputQuadSourceFaces != nullptr && face >= 0 &&
        face < static_cast<int>(options.outputQuadSourceFaces->size())) {
      authoritativeSourceFace =
          (*options.outputQuadSourceFaces)[static_cast<std::size_t>(face)];
      if (authoritativeSourceFace >= 0 && faceChart.valid() &&
          !std::binary_search(faceChart.chartFaces.begin(),
                              faceChart.chartFaces.end(),
                              authoritativeSourceFace)) {
        result.localSheetCompatibilityPassed = false;
        result.fail({MeshValidationFailureCode::LocalSheetMismatch,
                     -1, -1, -1, face});
        authoritativeSourceFace = -1;
      }
    }
    const auto accumulate_source_normal = [&](const int sourceFace) {
      if (sourceFace < 0 || sourceFace >= options.sourceFaces->rows()) {
        return;
      }
      const Eigen::Vector3d sa = options.sourceVertices->row(
          (*options.sourceFaces)(sourceFace, 0)).transpose();
      const Eigen::Vector3d sb = options.sourceVertices->row(
          (*options.sourceFaces)(sourceFace, 1)).transpose();
      const Eigen::Vector3d sc = options.sourceVertices->row(
          (*options.sourceFaces)(sourceFace, 2)).transpose();
      sourceNormal += (sb - sa).cross(sc - sa);
    };
    if (authoritativeSourceFace >= 0) {
      accumulate_source_normal(authoritativeSourceFace);
    } else if (faceChart.valid()) {
      std::set<int> exactFaceAuthority;
      for (const std::vector<int> &pointFaces : faceChart.pointFaces) {
        exactFaceAuthority.insert(pointFaces.begin(), pointFaces.end());
      }
      for (const int sourceFace : exactFaceAuthority) {
        accumulate_source_normal(sourceFace);
      }
    } else {
      for (const int vertex : polygon) {
        if (vertex < 0 ||
            static_cast<std::size_t>(vertex) >= provenance.size()) {
          continue;
        }
        accumulate_source_normal(
            provenance[static_cast<std::size_t>(vertex)].face);
      }
    }
    if (outputNormal.norm() > positionTolerance &&
        sourceNormal.norm() > positionTolerance &&
        outputNormal.dot(sourceNormal) <= 0.0) {
      result.fail({MeshValidationFailureCode::FlippedFace, -1, -1, -1,
                   face});
    }
  }

  const std::vector<TrianglePrimitive> triangles =
      triangulate_faces(vertices, faces, positionTolerance);
  std::vector<Aabb> triangleBoxes;
  triangleBoxes.reserve(triangles.size());
  for (const TrianglePrimitive &triangle : triangles) {
    triangleBoxes.push_back(triangle.bounds);
  }
  const AabbTree triangleTree(triangleBoxes);
  bool selfIntersectionFound = false;
  for (int first = 0; first < static_cast<int>(triangles.size()) &&
                      !selfIntersectionFound;
       ++first) {
    triangleTree.query(triangleBoxes[static_cast<std::size_t>(first)],
                       [&](const int second) {
      if (selfIntersectionFound || second <= first ||
          triangles[static_cast<std::size_t>(first)].parentFace ==
              triangles[static_cast<std::size_t>(second)].parentFace) {
        return;
      }
      const int firstParent =
          triangles[static_cast<std::size_t>(first)].parentFace;
      const int secondParent =
          triangles[static_cast<std::size_t>(second)].parentFace;
      const std::vector<int> firstPolygon =
          face_vertices(faces, firstParent);
      const std::vector<int> secondPolygon =
          face_vertices(faces, secondParent);
      const bool adjacentAtOutputVertex = std::any_of(
          firstPolygon.begin(), firstPolygon.end(), [&](const int vertex) {
            return std::find(secondPolygon.begin(), secondPolygon.end(),
                             vertex) != secondPolygon.end();
          });
      // Incident output faces are allowed to meet along their shared vertex
      // or edge. Their local fan is checked separately by incidence,
      // orientation, bow-tie, convexity, and Jacobian tests; treating a legal
      // shared-edge contact as a global self-intersection produces false
      // positives after polygon triangulation.
      if (adjacentAtOutputVertex) {
        return;
      }
      if (triangles_intersect(vertices,
                              triangles[static_cast<std::size_t>(first)],
                              triangles[static_cast<std::size_t>(second)],
                              positionTolerance)) {
        const int firstFace =
            triangles[static_cast<std::size_t>(first)].parentFace;
        const int secondFace =
            triangles[static_cast<std::size_t>(second)].parentFace;
        result.fail({MeshValidationFailureCode::SelfIntersectingFace, -1,
                     firstFace, secondFace, secondFace});
        selfIntersectionFound = true;
      }
    });
  }

  std::vector<Aabb> pointBoxes(static_cast<std::size_t>(vertices.rows()));
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    pointBoxes[static_cast<std::size_t>(vertex)].expand(
        vertices.row(vertex).transpose());
    pointBoxes[static_cast<std::size_t>(vertex)].pad(positionTolerance);
  }
  const AabbTree pointTree(pointBoxes);
  for (const auto &[edge, incidence] : outputEdges) {
    (void)incidence;
    const Eigen::Vector3d a = vertices.row(edge.first).transpose();
    const Eigen::Vector3d b = vertices.row(edge.second).transpose();
    const Eigen::Vector3d direction = b - a;
    const double lengthSquared = direction.squaredNorm();
    if (lengthSquared <= positionTolerance * positionTolerance) {
      continue;
    }
    Aabb edgeBox;
    edgeBox.expand(a);
    edgeBox.expand(b);
    edgeBox.pad(positionTolerance);
    pointTree.query(edgeBox, [&](const int vertex) {
      if (vertex == edge.first || vertex == edge.second ||
          static_cast<std::size_t>(std::max({vertex, edge.first, edge.second})) >=
              provenance.size()) {
        return;
      }
      const std::vector<const geometry::SurfacePoint *> edgePoints = {
          &provenance[static_cast<std::size_t>(vertex)],
          &provenance[static_cast<std::size_t>(edge.first)],
          &provenance[static_cast<std::size_t>(edge.second)]};
      std::vector<const SourceVertexChartAuthority *> edgeAuthorities;
      if (options.vertexChartAuthority != nullptr &&
          chartAuthorityCardinalityValid) {
        edgeAuthorities = {
            &(*options.vertexChartAuthority)[static_cast<std::size_t>(vertex)],
            &(*options.vertexChartAuthority)[
                static_cast<std::size_t>(edge.first)],
            &(*options.vertexChartAuthority)[
                static_cast<std::size_t>(edge.second)]};
      }
      if (!labelSupport.have_compatible_chart(edgePoints,
                                              edgeAuthorities, &provenance,
                                              options.vertexChartAuthority)) {
        return;
      }
      const Eigen::Vector3d point = vertices.row(vertex).transpose();
      const double parameter = (point - a).dot(direction) / lengthSquared;
      const double endpointTolerance =
          std::min(0.25, positionTolerance / std::sqrt(lengthSquared));
      if (parameter <= endpointTolerance ||
          parameter >= 1.0 - endpointTolerance) {
        return;
      }
      if ((point - (a + parameter * direction)).norm() <= positionTolerance) {
        result.fail({MeshValidationFailureCode::GeometricVertexOnUnsplitEdge,
                     vertex, edge.first, edge.second, -1});
      }
    });
  }

  return result;
}

} // namespace directional::validation
