// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_POINT_H
#define DIRECTIONAL_GEOMETRY_SURFACE_POINT_H

#include <algorithm>
#include <array>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace directional::geometry {

struct SurfacePoint {
  int face = -1;
  int component = -1;
  int sheet = -1;
  Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
  Eigen::Vector3d position = Eigen::Vector3d::Zero();
  double squaredDistance = std::numeric_limits<double>::infinity();

  [[nodiscard]] bool valid() const { return face >= 0; }
};

struct SurfaceProjectionOptions {
  double barycentricTolerance = 1.0e-10;
  const std::vector<unsigned char> *allowedFaces = nullptr;
  const std::vector<int> *faceComponents = nullptr;
  const std::vector<int> *faceSheets = nullptr;
};

namespace detail {

struct ProjectionAabb {
  Eigen::Vector3d minimum =
      Eigen::Vector3d::Constant(std::numeric_limits<double>::infinity());
  Eigen::Vector3d maximum =
      Eigen::Vector3d::Constant(-std::numeric_limits<double>::infinity());

  void expand(const Eigen::Vector3d &point) {
    minimum = minimum.cwiseMin(point);
    maximum = maximum.cwiseMax(point);
  }

  void expand(const ProjectionAabb &box) {
    minimum = minimum.cwiseMin(box.minimum);
    maximum = maximum.cwiseMax(box.maximum);
  }

  [[nodiscard]] double squared_distance(const Eigen::Vector3d &point) const {
    double distance = 0.0;
    for (int axis = 0; axis < 3; ++axis) {
      if (point(axis) < minimum(axis)) {
        const double delta = minimum(axis) - point(axis);
        distance += delta * delta;
      } else if (point(axis) > maximum(axis)) {
        const double delta = point(axis) - maximum(axis);
        distance += delta * delta;
      }
    }
    return distance;
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
};

struct ProjectionTriangle {
  int face = -1;
  std::array<int, 3> vertices = {-1, -1, -1};
  ProjectionAabb bounds;
  Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
};

#if defined(DIRECTIONAL_SURFACE_POINT_IMPLEMENTATION)
Eigen::Vector3d closest_point_on_triangle_barycentric(
    const Eigen::Vector3d &point, const Eigen::Vector3d &a,
    const Eigen::Vector3d &b, const Eigen::Vector3d &c) {
  const Eigen::Vector3d ab = b - a;
  const Eigen::Vector3d ac = c - a;
  const Eigen::Vector3d ap = point - a;
  const double d1 = ab.dot(ap);
  const double d2 = ac.dot(ap);
  if (d1 <= 0.0 && d2 <= 0.0) {
    return {1.0, 0.0, 0.0};
  }

  const Eigen::Vector3d bp = point - b;
  const double d3 = ab.dot(bp);
  const double d4 = ac.dot(bp);
  if (d3 >= 0.0 && d4 <= d3) {
    return {0.0, 1.0, 0.0};
  }

  const double vc = d1 * d4 - d3 * d2;
  if (vc <= 0.0 && d1 >= 0.0 && d3 <= 0.0) {
    const double v = d1 / (d1 - d3);
    return {1.0 - v, v, 0.0};
  }

  const Eigen::Vector3d cp = point - c;
  const double d5 = ab.dot(cp);
  const double d6 = ac.dot(cp);
  if (d6 >= 0.0 && d5 <= d6) {
    return {0.0, 0.0, 1.0};
  }

  const double vb = d5 * d2 - d1 * d6;
  if (vb <= 0.0 && d2 >= 0.0 && d6 <= 0.0) {
    const double w = d2 / (d2 - d6);
    return {1.0 - w, 0.0, w};
  }

  const double va = d3 * d6 - d5 * d4;
  if (va <= 0.0 && (d4 - d3) >= 0.0 && (d5 - d6) >= 0.0) {
    const double w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
    return {0.0, 1.0 - w, w};
  }

  const double denominator = 1.0 / (va + vb + vc);
  const double v = vb * denominator;
  const double w = vc * denominator;
  return {1.0 - v - w, v, w};
}
#else
Eigen::Vector3d closest_point_on_triangle_barycentric(
    const Eigen::Vector3d &point, const Eigen::Vector3d &a,
    const Eigen::Vector3d &b, const Eigen::Vector3d &c);
#endif

} // namespace detail

class SurfaceProjectionBvh {
public:
  SurfaceProjectionBvh(const Eigen::MatrixXd &vertices,
                       const Eigen::MatrixXi &faces)
      : vertices_(&vertices), faces_(&faces) {
    if (vertices.cols() != 3 || faces.cols() != 3) {
      throw std::invalid_argument(
          "SurfaceProjectionBvh: expected #V-by-3 vertices and #F-by-3 faces");
    }

    triangles_.reserve(static_cast<std::size_t>(faces.rows()));
    for (int face = 0; face < faces.rows(); ++face) {
      const int ia = faces(face, 0);
      const int ib = faces(face, 1);
      const int ic = faces(face, 2);
      if (ia < 0 || ib < 0 || ic < 0 || ia >= vertices.rows() ||
          ib >= vertices.rows() || ic >= vertices.rows()) {
        continue;
      }

      detail::ProjectionTriangle triangle;
      triangle.face = face;
      triangle.vertices = {ia, ib, ic};
      const Eigen::Vector3d a = vertices.row(ia).transpose();
      const Eigen::Vector3d b = vertices.row(ib).transpose();
      const Eigen::Vector3d c = vertices.row(ic).transpose();
      triangle.bounds.expand(a);
      triangle.bounds.expand(b);
      triangle.bounds.expand(c);
      triangle.centroid = (a + b + c) / 3.0;
      triangles_.push_back(triangle);
    }

    if (!triangles_.empty()) {
      build_node(0, triangles_.size());
    }
  }

  [[nodiscard]] bool empty() const { return nodes_.empty(); }

  [[nodiscard]] SurfacePoint
  project(const Eigen::Vector3d &point,
          const SurfaceProjectionOptions &options =
              SurfaceProjectionOptions{}) const {
    SurfacePoint best;
    if (nodes_.empty()) {
      return best;
    }

    std::vector<std::size_t> stack{0};
    while (!stack.empty()) {
      const std::size_t nodeIndex = stack.back();
      stack.pop_back();
      const Node &node = nodes_[nodeIndex];
      if (node.bounds.squared_distance(point) > best.squaredDistance) {
        continue;
      }

      if (node.leaf()) {
        for (std::size_t index = node.begin; index < node.end; ++index) {
          project_triangle(point, triangles_[index], options, best);
        }
      } else {
        const Node &left = nodes_[static_cast<std::size_t>(node.left)];
        const Node &right = nodes_[static_cast<std::size_t>(node.right)];
        const double leftDistance = left.bounds.squared_distance(point);
        const double rightDistance = right.bounds.squared_distance(point);
        if (leftDistance < rightDistance) {
          if (rightDistance <= best.squaredDistance) {
            stack.push_back(static_cast<std::size_t>(node.right));
          }
          if (leftDistance <= best.squaredDistance) {
            stack.push_back(static_cast<std::size_t>(node.left));
          }
        } else {
          if (leftDistance <= best.squaredDistance) {
            stack.push_back(static_cast<std::size_t>(node.left));
          }
          if (rightDistance <= best.squaredDistance) {
            stack.push_back(static_cast<std::size_t>(node.right));
          }
        }
      }
    }
    return best;
  }

private:
  struct Node {
    detail::ProjectionAabb bounds;
    std::size_t begin = 0;
    std::size_t end = 0;
    int left = -1;
    int right = -1;

    [[nodiscard]] bool leaf() const { return left < 0 && right < 0; }
  };

  static constexpr std::size_t leafSize = 8;

  std::size_t build_node(const std::size_t begin, const std::size_t end) {
    const std::size_t nodeIndex = nodes_.size();
    nodes_.push_back({});
    Node &node = nodes_.back();
    node.begin = begin;
    node.end = end;
    for (std::size_t index = begin; index < end; ++index) {
      node.bounds.expand(triangles_[index].bounds);
    }

    if (end - begin <= leafSize) {
      return nodeIndex;
    }

    const int axis = node.bounds.longest_axis();
    const std::size_t middle = begin + (end - begin) / 2;
    std::nth_element(
        triangles_.begin() + static_cast<std::ptrdiff_t>(begin),
        triangles_.begin() + static_cast<std::ptrdiff_t>(middle),
        triangles_.begin() + static_cast<std::ptrdiff_t>(end),
        [axis](const detail::ProjectionTriangle &a,
               const detail::ProjectionTriangle &b) {
          return a.centroid(axis) < b.centroid(axis);
        });

    const std::size_t left = build_node(begin, middle);
    const std::size_t right = build_node(middle, end);
    nodes_[nodeIndex].left = static_cast<int>(left);
    nodes_[nodeIndex].right = static_cast<int>(right);
    return nodeIndex;
  }

  void project_triangle(const Eigen::Vector3d &point,
                        const detail::ProjectionTriangle &triangle,
                        const SurfaceProjectionOptions &options,
                        SurfacePoint &best) const {
    if (options.allowedFaces != nullptr) {
      const std::size_t faceIndex = static_cast<std::size_t>(triangle.face);
      if (faceIndex >= options.allowedFaces->size() ||
          (*options.allowedFaces)[faceIndex] == 0) {
        return;
      }
    }
    const Eigen::Vector3d a =
        vertices_->row(triangle.vertices[0]).transpose();
    const Eigen::Vector3d b =
        vertices_->row(triangle.vertices[1]).transpose();
    const Eigen::Vector3d c =
        vertices_->row(triangle.vertices[2]).transpose();
    Eigen::Vector3d bary =
        detail::closest_point_on_triangle_barycentric(point, a, b, c);
    for (int i = 0; i < 3; ++i) {
      if (std::abs(bary(i)) <= options.barycentricTolerance) {
        bary(i) = 0.0;
      }
      bary(i) = std::clamp(bary(i), 0.0, 1.0);
    }
    const double sum = bary.sum();
    if (sum > 0.0) {
      bary /= sum;
    }
    const Eigen::Vector3d projected = bary(0) * a + bary(1) * b + bary(2) * c;
    const double squaredDistance = (projected - point).squaredNorm();
    if (squaredDistance < best.squaredDistance) {
      best.face = triangle.face;
      if (options.faceComponents != nullptr &&
          static_cast<std::size_t>(triangle.face) <
              options.faceComponents->size()) {
        best.component =
            (*options.faceComponents)[static_cast<std::size_t>(triangle.face)];
      }
      if (options.faceSheets != nullptr &&
          static_cast<std::size_t>(triangle.face) < options.faceSheets->size()) {
        best.sheet =
            (*options.faceSheets)[static_cast<std::size_t>(triangle.face)];
      }
      best.barycentric = bary;
      best.position = projected;
      best.squaredDistance = squaredDistance;
    }
  }

  const Eigen::MatrixXd *vertices_ = nullptr;
  const Eigen::MatrixXi *faces_ = nullptr;
  std::vector<detail::ProjectionTriangle> triangles_;
  std::vector<Node> nodes_;
};

#if defined(DIRECTIONAL_SURFACE_POINT_IMPLEMENTATION)
SurfacePoint project_to_surface(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::Vector3d &point,
    const SurfaceProjectionOptions &options = SurfaceProjectionOptions{}) {
  return SurfaceProjectionBvh(vertices, faces).project(point, options);
}
#else
SurfacePoint project_to_surface(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::Vector3d &point,
    const SurfaceProjectionOptions &options = SurfaceProjectionOptions{});
#endif

#if defined(DIRECTIONAL_SURFACE_POINT_IMPLEMENTATION)
std::vector<SurfacePoint>
project_vertices_to_surface(const Eigen::MatrixXd &sourceVertices,
                            const Eigen::MatrixXi &sourceFaces,
                            const Eigen::MatrixXd &queryVertices) {
  std::vector<SurfacePoint> provenance;
  provenance.reserve(static_cast<std::size_t>(queryVertices.rows()));
  const SurfaceProjectionBvh bvh(sourceVertices, sourceFaces);
  for (int row = 0; row < queryVertices.rows(); ++row) {
    provenance.push_back(bvh.project(queryVertices.row(row).transpose()));
  }
  return provenance;
}
#else
std::vector<SurfacePoint>
project_vertices_to_surface(const Eigen::MatrixXd &sourceVertices,
                            const Eigen::MatrixXi &sourceFaces,
                            const Eigen::MatrixXd &queryVertices);
#endif

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_POINT_H
