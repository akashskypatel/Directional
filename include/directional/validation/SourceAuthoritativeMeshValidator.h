// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VALIDATION_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_H
#define DIRECTIONAL_VALIDATION_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <limits>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <directional/geometry/SurfacePoint.h>
#include <directional/validation/MeshValidator.h>

namespace directional::validation {

struct MeshTopologySummary {
  int usedVertices = 0;
  int edges = 0;
  int faces = 0;
  int connectedComponents = 0;
  int eulerCharacteristic = 0;
  int boundaryLoopCount = 0;
  bool boundaryCyclesClosed = true;
};

struct SourceAuthoritativeMeshValidatorOptions {
  double geometricTolerance = 1.0e-9;
  const Eigen::MatrixXd *sourceVertices = nullptr;
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const std::vector<int> *sourceFaceComponents = nullptr;
  const std::vector<int> *sourceFaceSheets = nullptr;
  const std::vector<geometry::SurfacePoint> *vertexProvenance = nullptr;
  std::set<std::pair<int, int>> authoritativeBoundaryEdges;
  std::vector<std::vector<int>> authoritativeBoundaryLoops;
  std::vector<std::vector<int>> authoritativeFeatureRails;
  std::size_t expectedFeatureRailCount = 0;
  bool requireBoundaryAuthority = true;
  bool requireFeatureRailAuthority = true;
  bool requireLocalSheetCompatibility = true;
};

struct SourceAuthoritativeMeshValidationResult : MeshValidationResult {
  MeshTopologySummary sourceTopology;
  MeshTopologySummary outputTopology;
  bool sourceAuthorityUsed = false;
  bool provenanceCoverageComplete = false;
  bool localSheetCompatibilityPassed = false;
  bool orderedBoundaryCyclesPassed = false;
  bool featureRailsPassed = false;
  bool spatialAccelerationUsed = false;
};

namespace source_authoritative_detail {

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
std::vector<int> face_vertices(const Eigen::MatrixXi &faces,
                                      const int face);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
MeshTopologySummary summarize_topology(const Eigen::MatrixXi &faces);
#endif

struct Aabb {
  Eigen::Vector3d minimum =
      Eigen::Vector3d::Constant(std::numeric_limits<double>::infinity());
  Eigen::Vector3d maximum =
      Eigen::Vector3d::Constant(-std::numeric_limits<double>::infinity());

  void expand(const Eigen::Vector3d &point) {
    minimum = minimum.cwiseMin(point);
    maximum = maximum.cwiseMax(point);
  }
  void expand(const Aabb &box) {
    minimum = minimum.cwiseMin(box.minimum);
    maximum = maximum.cwiseMax(box.maximum);
  }
  void pad(const double value) {
    minimum.array() -= value;
    maximum.array() += value;
  }
  [[nodiscard]] bool overlaps(const Aabb &other) const {
    return (minimum.array() <= other.maximum.array()).all() &&
           (maximum.array() >= other.minimum.array()).all();
  }
  [[nodiscard]] int longest_axis() const {
    const Eigen::Vector3d extent = maximum - minimum;
    int axis = 0;
    if (extent(1) > extent(axis)) {
      axis = 1;
    }
    if (extent(2) > extent(axis)) {
      axis = 2;
    }
    return axis;
  }
  [[nodiscard]] Eigen::Vector3d centroid() const {
    return 0.5 * (minimum + maximum);
  }
};

class AabbTree {
public:
  explicit AabbTree(const std::vector<Aabb> &boxes) : boxes_(&boxes) {
    order_.resize(boxes.size());
    std::iota(order_.begin(), order_.end(), 0);
    if (!boxes.empty()) {
      build(0, order_.size());
    }
  }

  template <typename Callback>
  void query(const Aabb &box, Callback callback) const {
    if (nodes_.empty()) {
      return;
    }
    std::vector<int> stack{0};
    while (!stack.empty()) {
      const int nodeIndex = stack.back();
      stack.pop_back();
      const Node &node = nodes_[static_cast<std::size_t>(nodeIndex)];
      if (!node.bounds.overlaps(box)) {
        continue;
      }
      if (node.left < 0) {
        for (std::size_t index = node.begin; index < node.end; ++index) {
          const int primitive = order_[index];
          if ((*boxes_)[static_cast<std::size_t>(primitive)].overlaps(box)) {
            callback(primitive);
          }
        }
      } else {
        stack.push_back(node.left);
        stack.push_back(node.right);
      }
    }
  }

private:
  struct Node {
    Aabb bounds;
    std::size_t begin = 0;
    std::size_t end = 0;
    int left = -1;
    int right = -1;
  };

  int build(const std::size_t begin, const std::size_t end) {
    const int nodeIndex = static_cast<int>(nodes_.size());
    nodes_.push_back({});
    nodes_[static_cast<std::size_t>(nodeIndex)].begin = begin;
    nodes_[static_cast<std::size_t>(nodeIndex)].end = end;
    for (std::size_t index = begin; index < end; ++index) {
      nodes_[static_cast<std::size_t>(nodeIndex)].bounds.expand(
          (*boxes_)[static_cast<std::size_t>(order_[index])]);
    }
    if (end - begin <= 8U) {
      return nodeIndex;
    }
    const int axis =
        nodes_[static_cast<std::size_t>(nodeIndex)].bounds.longest_axis();
    const std::size_t middle = begin + (end - begin) / 2U;
    std::nth_element(order_.begin() + static_cast<std::ptrdiff_t>(begin),
                     order_.begin() + static_cast<std::ptrdiff_t>(middle),
                     order_.begin() + static_cast<std::ptrdiff_t>(end),
                     [&](const int first, const int second) {
                       return (*boxes_)[static_cast<std::size_t>(first)]
                                  .centroid()(axis) <
                              (*boxes_)[static_cast<std::size_t>(second)]
                                  .centroid()(axis);
                     });
    const int left = build(begin, middle);
    const int right = build(middle, end);
    nodes_[static_cast<std::size_t>(nodeIndex)].left = left;
    nodes_[static_cast<std::size_t>(nodeIndex)].right = right;
    return nodeIndex;
  }

  const std::vector<Aabb> *boxes_ = nullptr;
  std::vector<int> order_;
  std::vector<Node> nodes_;
};

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
double orient2(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                      const Eigen::Vector2d &c) {
  return (b.x() - a.x()) * (c.y() - a.y()) -
         (b.y() - a.y()) * (c.x() - a.x());
}
#else
double orient2(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                      const Eigen::Vector2d &c);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
int dominant_axis(const Eigen::Vector3d &normal);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
Eigen::Vector2d project2(const Eigen::Vector3d &point,
                                const int dropAxis);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
bool point_in_triangle2_strict(const Eigen::Vector2d &point,
                                      const Eigen::Vector2d &a,
                                      const Eigen::Vector2d &b,
                                      const Eigen::Vector2d &c,
                                      const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
bool proper_segment_intersection2(const Eigen::Vector2d &a,
                                         const Eigen::Vector2d &b,
                                         const Eigen::Vector2d &c,
                                         const Eigen::Vector2d &d,
                                         const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
bool collinear_segment_overlap2(const Eigen::Vector2d &a,
                                       const Eigen::Vector2d &b,
                                       const Eigen::Vector2d &c,
                                       const Eigen::Vector2d &d,
                                       const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
bool near_any(const Eigen::Vector3d &point,
                     const std::vector<Eigen::Vector3d> &allowed,
                     const double tolerance) {
  return std::any_of(allowed.begin(), allowed.end(), [&](const auto &candidate) {
    return (point - candidate).norm() <= tolerance;
  });
}
#else
bool near_any(const Eigen::Vector3d &point,
                     const std::vector<Eigen::Vector3d> &allowed,
                     const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
  const double scale = std::max({direction.norm(), edge1.norm(), edge2.norm(),
                                 1.0});
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
#else
bool segment_triangle_intersection_point(
    const Eigen::Vector3d &p0, const Eigen::Vector3d &p1,
    const Eigen::Vector3d &a, const Eigen::Vector3d &b,
    const Eigen::Vector3d &c, const double tolerance,
    Eigen::Vector3d &intersection);
#endif

struct TrianglePrimitive {
  std::array<int, 3> vertices = {-1, -1, -1};
  int parentFace = -1;
  Aabb bounds;
};

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
std::vector<int> shared_vertices(const TrianglePrimitive &first,
                                        const TrianglePrimitive &second);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
bool coplanar_triangles_overlap(
    const std::array<Eigen::Vector3d, 3> &first,
    const std::array<Eigen::Vector3d, 3> &second,
    const std::vector<Eigen::Vector3d> &allowedTouches,
    const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
  const double normalScale = std::max(normalA.norm() * normalB.norm(), 1.0);
  if (normalA.cross(normalB).norm() <= tolerance * normalScale &&
      std::abs(normalA.dot(b[0] - a[0])) <=
          tolerance * std::max(normalA.norm(), 1.0)) {
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
#else
bool triangles_intersect(
    const Eigen::MatrixXd &vertices, const TrianglePrimitive &first,
    const TrianglePrimitive &second, const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
std::vector<TrianglePrimitive>
triangulate_faces(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                  const double tolerance);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
std::vector<std::vector<int>> extract_loops_from_edges(
    const std::set<std::pair<int, int>> &edges, bool &closed);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
std::vector<std::vector<int>> extract_boundary_loops(
    const Eigen::MatrixXi &faces, bool &closed);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
std::vector<int> canonical_loop(const std::vector<int> &input);
#endif

struct SourcePointLabelSupport {
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const std::vector<int> *components = nullptr;
  const std::vector<int> *sheets = nullptr;
  std::vector<std::vector<int>> vertexFaces;
  std::map<std::pair<int, int>, std::vector<int>> edgeFaces;

  SourcePointLabelSupport(
      const Eigen::MatrixXi *faces,
      const std::vector<int> *sourceComponents,
      const std::vector<int> *sourceSheets)
      : sourceFaces(faces), components(sourceComponents), sheets(sourceSheets) {
    if (sourceFaces == nullptr || sourceFaces->cols() != 3) {
      return;
    }
    int maximumVertex = -1;
    for (int face = 0; face < sourceFaces->rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        maximumVertex = std::max(maximumVertex, (*sourceFaces)(face, corner));
      }
    }
    vertexFaces.resize(static_cast<std::size_t>(std::max(0, maximumVertex + 1)));
    for (int face = 0; face < sourceFaces->rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = (*sourceFaces)(face, corner);
        if (vertex >= 0 && vertex < static_cast<int>(vertexFaces.size())) {
          vertexFaces[static_cast<std::size_t>(vertex)].push_back(face);
        }
        const int next = (*sourceFaces)(face, (corner + 1) % 3);
        if (vertex >= 0 && next >= 0 && vertex != next) {
          edgeFaces[canonical_edge(vertex, next)].push_back(face);
        }
      }
    }
    for (auto &facesAtVertex : vertexFaces) {
      std::sort(facesAtVertex.begin(), facesAtVertex.end());
      facesAtVertex.erase(
          std::unique(facesAtVertex.begin(), facesAtVertex.end()),
          facesAtVertex.end());
    }
    for (auto &[edge, facesAtEdge] : edgeFaces) {
      (void)edge;
      std::sort(facesAtEdge.begin(), facesAtEdge.end());
      facesAtEdge.erase(std::unique(facesAtEdge.begin(), facesAtEdge.end()),
                        facesAtEdge.end());
    }
  }

  [[nodiscard]] bool available() const {
    return sourceFaces != nullptr && components != nullptr && sheets != nullptr &&
           components->size() == static_cast<std::size_t>(sourceFaces->rows()) &&
           sheets->size() == static_cast<std::size_t>(sourceFaces->rows());
  }

  [[nodiscard]] std::set<std::pair<int, int>>
  supported_labels(const geometry::SurfacePoint &point) const {
    std::set<std::pair<int, int>> labels;
    if (!available() || !point.valid() || point.face < 0 ||
        point.face >= sourceFaces->rows() || !point.barycentric.allFinite()) {
      return labels;
    }
    std::vector<int> supportCorners;
    for (int corner = 0; corner < 3; ++corner) {
      if (point.barycentric(corner) > 1.0e-8) {
        supportCorners.push_back(corner);
      }
    }

    std::vector<int> candidateFaces;
    if (supportCorners.size() == 1U) {
      const int vertex = (*sourceFaces)(point.face, supportCorners.front());
      if (vertex >= 0 && vertex < static_cast<int>(vertexFaces.size())) {
        candidateFaces = vertexFaces[static_cast<std::size_t>(vertex)];
      }
    } else if (supportCorners.size() == 2U) {
      const int first = (*sourceFaces)(point.face, supportCorners[0]);
      const int second = (*sourceFaces)(point.face, supportCorners[1]);
      const auto found = edgeFaces.find(canonical_edge(first, second));
      if (found != edgeFaces.end()) {
        candidateFaces = found->second;
      }
    }
    if (candidateFaces.empty()) {
      candidateFaces.push_back(point.face);
    } else if (std::find(candidateFaces.begin(), candidateFaces.end(),
                         point.face) == candidateFaces.end()) {
      candidateFaces.push_back(point.face);
    }

    for (const int face : candidateFaces) {
      if (face < 0 || face >= sourceFaces->rows()) {
        continue;
      }
      labels.insert({(*components)[static_cast<std::size_t>(face)],
                     (*sheets)[static_cast<std::size_t>(face)]});
    }
    return labels;
  }

  [[nodiscard]] bool have_common_label(
      const std::vector<const geometry::SurfacePoint *> &points) const {
    if (!available() || points.empty()) {
      return false;
    }
    std::set<std::pair<int, int>> common;
    bool first = true;
    for (const geometry::SurfacePoint *point : points) {
      if (point == nullptr) {
        return false;
      }
      const std::set<std::pair<int, int>> labels = supported_labels(*point);
      if (labels.empty()) {
        return false;
      }
      if (first) {
        common = labels;
        first = false;
      } else {
        std::set<std::pair<int, int>> intersection;
        std::set_intersection(common.begin(), common.end(), labels.begin(),
                              labels.end(),
                              std::inserter(intersection, intersection.end()));
        common = std::move(intersection);
      }
      if (common.empty()) {
        return false;
      }
    }
    return !common.empty();
  }
};

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
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
#else
Eigen::Vector3d polygon_normal(const Eigen::MatrixXd &vertices,
                                      const std::vector<int> &polygon);
#endif

} // namespace source_authoritative_detail

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
MeshTopologySummary summarize_mesh_topology(const Eigen::MatrixXi &faces) {
  return source_authoritative_detail::summarize_topology(faces);
}
#else
MeshTopologySummary summarize_mesh_topology(const Eigen::MatrixXi &faces);
#endif

#if defined(DIRECTIONAL_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_IMPLEMENTATION)
SourceAuthoritativeMeshValidationResult
validate_source_authoritative_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SourceAuthoritativeMeshValidatorOptions &options) {
  using namespace source_authoritative_detail;
  SourceAuthoritativeMeshValidationResult result;
  result.spatialAccelerationUsed = true;
  if (options.sourceVertices == nullptr || options.sourceFaces == nullptr ||
      options.vertexProvenance == nullptr ||
      options.sourceVertices->cols() != 3 || options.sourceFaces->cols() != 3) {
    result.fail({MeshValidationFailureCode::MissingSourceAuthority});
    return result;
  }
  result.sourceAuthorityUsed = true;
  result.sourceTopology = summarize_topology(*options.sourceFaces);
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
      options.sourceFaces, options.sourceFaceComponents,
      options.sourceFaceSheets);
  const double sourceScale =
      options.sourceVertices->rows() == 0
          ? 1.0
          : std::max(1.0,
                     (options.sourceVertices->colwise().maxCoeff() -
                      options.sourceVertices->colwise().minCoeff())
                         .norm());
  const double positionTolerance =
      std::max(options.geometricTolerance, 1.0e-9) * sourceScale * 32.0;
  result.provenanceCoverageComplete =
      provenance.size() >= static_cast<std::size_t>(vertices.rows());
  if (!result.provenanceCoverageComplete) {
    result.fail({MeshValidationFailureCode::MissingProvenance});
  }

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
    if (options.sourceFaceComponents != nullptr) {
      if (static_cast<std::size_t>(point.face) >=
              options.sourceFaceComponents->size() ||
          point.component != (*options.sourceFaceComponents)[
                                 static_cast<std::size_t>(point.face)]) {
        result.fail({MeshValidationFailureCode::SourceComponentMismatch,
                     vertex});
      }
    }
    if (options.sourceFaceSheets != nullptr) {
      if (static_cast<std::size_t>(point.face) >=
              options.sourceFaceSheets->size() ||
          point.sheet != (*options.sourceFaceSheets)[
                             static_cast<std::size_t>(point.face)]) {
        result.fail({MeshValidationFailureCode::SourceSheetMismatch, vertex});
      }
    }
  }

  result.localSheetCompatibilityPassed = true;
  if (options.requireLocalSheetCompatibility &&
      (options.sourceFaceComponents == nullptr ||
       options.sourceFaceSheets == nullptr)) {
    result.localSheetCompatibilityPassed = false;
    result.fail({MeshValidationFailureCode::MissingSourceAuthority});
  }
  for (int face = 0; face < faces.rows(); ++face) {
    const std::vector<int> polygon = face_vertices(faces, face);
    if (options.requireLocalSheetCompatibility) {
      std::vector<const geometry::SurfacePoint *> facePoints;
      facePoints.reserve(polygon.size());
      int invalidVertex = -1;
      bool faceProvenanceValid = true;
      for (const int vertex : polygon) {
        if (vertex < 0 || static_cast<std::size_t>(vertex) >= provenance.size()) {
          invalidVertex = vertex;
          faceProvenanceValid = false;
          break;
        }
        facePoints.push_back(
            &provenance[static_cast<std::size_t>(vertex)]);
      }
      if (!faceProvenanceValid ||
          !labelSupport.have_common_label(facePoints)) {
        result.localSheetCompatibilityPassed = false;
        result.fail({MeshValidationFailureCode::LocalSheetMismatch,
                     invalidVertex, -1, -1, face});
      }
    }

    const Eigen::Vector3d outputNormal = polygon_normal(vertices, polygon);
    Eigen::Vector3d sourceNormal = Eigen::Vector3d::Zero();
    for (const int vertex : polygon) {
      if (vertex < 0 || static_cast<std::size_t>(vertex) >= provenance.size()) {
        continue;
      }
      const int sourceFace = provenance[static_cast<std::size_t>(vertex)].face;
      if (sourceFace < 0 || sourceFace >= options.sourceFaces->rows()) {
        continue;
      }
      const Eigen::Vector3d sa = options.sourceVertices->row(
          (*options.sourceFaces)(sourceFace, 0)).transpose();
      const Eigen::Vector3d sb = options.sourceVertices->row(
          (*options.sourceFaces)(sourceFace, 1)).transpose();
      const Eigen::Vector3d sc = options.sourceVertices->row(
          (*options.sourceFaces)(sourceFace, 2)).transpose();
      sourceNormal += (sb - sa).cross(sc - sa);
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
      if (triangles_intersect(vertices,
                              triangles[static_cast<std::size_t>(first)],
                              triangles[static_cast<std::size_t>(second)],
                              positionTolerance)) {
        result.fail({MeshValidationFailureCode::SelfIntersectingFace, -1, -1,
                     -1,
                     triangles[static_cast<std::size_t>(second)].parentFace});
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
      if (!labelSupport.have_common_label(edgePoints)) {
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
#else
SourceAuthoritativeMeshValidationResult
validate_source_authoritative_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SourceAuthoritativeMeshValidatorOptions &options);
#endif

} // namespace directional::validation

#endif // DIRECTIONAL_VALIDATION_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_H
