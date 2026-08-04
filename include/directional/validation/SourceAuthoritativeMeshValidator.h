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
#include <cstdint>
#include <limits>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/geometry/SurfacePointSupport.h>
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
  const std::vector<int> *outputQuadSourceFaces = nullptr;
  std::set<std::uint64_t> sourceHardFeatureEdges;
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

std::vector<int> face_vertices(const Eigen::MatrixXi &faces,
                                      const int face);

MeshTopologySummary summarize_topology(const Eigen::MatrixXi &faces);

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

double orient2(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                      const Eigen::Vector2d &c);

int dominant_axis(const Eigen::Vector3d &normal);

Eigen::Vector2d project2(const Eigen::Vector3d &point,
                                const int dropAxis);

bool point_in_triangle2_strict(const Eigen::Vector2d &point,
                                      const Eigen::Vector2d &a,
                                      const Eigen::Vector2d &b,
                                      const Eigen::Vector2d &c,
                                      const double tolerance);

bool proper_segment_intersection2(const Eigen::Vector2d &a,
                                         const Eigen::Vector2d &b,
                                         const Eigen::Vector2d &c,
                                         const Eigen::Vector2d &d,
                                         const double tolerance);

bool collinear_segment_overlap2(const Eigen::Vector2d &a,
                                       const Eigen::Vector2d &b,
                                       const Eigen::Vector2d &c,
                                       const Eigen::Vector2d &d,
                                       const double tolerance);

bool near_any(const Eigen::Vector3d &point,
                     const std::vector<Eigen::Vector3d> &allowed,
                     const double tolerance);

bool segment_triangle_intersection_point(
    const Eigen::Vector3d &p0, const Eigen::Vector3d &p1,
    const Eigen::Vector3d &a, const Eigen::Vector3d &b,
    const Eigen::Vector3d &c, const double tolerance,
    Eigen::Vector3d &intersection);

struct TrianglePrimitive {
  std::array<int, 3> vertices = {-1, -1, -1};
  int parentFace = -1;
  Aabb bounds;
};

std::vector<int> shared_vertices(const TrianglePrimitive &first,
                                        const TrianglePrimitive &second);

bool coplanar_triangles_overlap(
    const std::array<Eigen::Vector3d, 3> &first,
    const std::array<Eigen::Vector3d, 3> &second,
    const std::vector<Eigen::Vector3d> &allowedTouches,
    const double tolerance);

bool triangles_intersect(
    const Eigen::MatrixXd &vertices, const TrianglePrimitive &first,
    const TrianglePrimitive &second, const double tolerance);

std::vector<TrianglePrimitive>
triangulate_faces(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                  const double tolerance);

std::vector<std::vector<int>> extract_loops_from_edges(
    const std::set<std::pair<int, int>> &edges, bool &closed);

std::vector<std::vector<int>> extract_boundary_loops(
    const Eigen::MatrixXi &faces, bool &closed);

std::vector<int> canonical_loop(const std::vector<int> &input);

struct SourcePointLabelSupport {
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const std::vector<int> *components = nullptr;
  const std::vector<int> *sheets = nullptr;
  geometry::SurfacePointSourceSupportResolver sourceSupport;
  geometry::SourceChartTransitionGraph transitionGraph;

  SourcePointLabelSupport(
      const Eigen::MatrixXi *faces,
      const std::vector<int> *sourceComponents,
      const std::vector<int> *sourceSheets,
      const std::set<std::uint64_t> *hardFeatureEdges = nullptr)
      : sourceFaces(faces), components(sourceComponents), sheets(sourceSheets),
        sourceSupport(faces),
        transitionGraph(faces, sourceComponents, sourceSheets,
                        hardFeatureEdges) {}

  [[nodiscard]] bool available() const {
    return sourceSupport.available() && transitionGraph.available() &&
           components != nullptr && sheets != nullptr &&
           components->size() == static_cast<std::size_t>(sourceFaces->rows()) &&
           sheets->size() == static_cast<std::size_t>(sourceFaces->rows());
  }

  [[nodiscard]] std::vector<int>
  supported_faces(const geometry::SurfacePoint &point) const {
    if (!available()) {
      return {};
    }
    return sourceSupport.resolve(point).supportedFaces;
  }

  [[nodiscard]] std::set<std::pair<int, int>>
  supported_labels(const geometry::SurfacePoint &point) const {
    std::set<std::pair<int, int>> labels;
    for (const int face : supported_faces(point)) {
      if (face < 0 || face >= sourceFaces->rows()) {
        continue;
      }
      labels.insert({(*components)[static_cast<std::size_t>(face)],
                     (*sheets)[static_cast<std::size_t>(face)]});
    }
    return labels;
  }

  [[nodiscard]] bool faces_share_source_edge(const int firstFace,
                                              const int secondFace) const {
    if (!available() || firstFace < 0 || secondFace < 0 ||
        firstFace >= sourceFaces->rows() || secondFace >= sourceFaces->rows() ||
        firstFace == secondFace) {
      return false;
    }
    int sharedVertices = 0;
    for (int firstCorner = 0; firstCorner < 3; ++firstCorner) {
      const int vertex = (*sourceFaces)(firstFace, firstCorner);
      for (int secondCorner = 0; secondCorner < 3; ++secondCorner) {
        if (vertex == (*sourceFaces)(secondFace, secondCorner)) {
          ++sharedVertices;
          break;
        }
      }
    }
    return sharedVertices == 2;
  }

  // A completed output face may live on one source triangle or cross exactly
  // one genuine source edge between two adjacent projection charts.  This is
  // intentionally stricter than component-only compatibility: non-adjacent
  // close/opposing sheets can never satisfy the contract.
  [[nodiscard]] std::vector<int> compatible_chart_faces(
      const std::vector<const geometry::SurfacePoint *> &points) const {
    if (!available() || points.empty()) {
      return {};
    }
    // First preserve the strict per-point declared-chart contract. A point may
    // be rebound only through an exact source-edge/source-vertex transition;
    // proximity and triangle-row coincidence are never accepted as identity.
    for (const geometry::SurfacePoint *point : points) {
      if (point == nullptr || point->face < 0 ||
          point->face >= sourceFaces->rows()) {
        return {};
      }
      const geometry::SourceChartId declared = transitionGraph.chart(point->face);
      if (!declared.valid() ||
          (point->component >= 0 && point->component != declared.component) ||
          (point->sheet >= 0 && point->sheet != declared.localSheet)) {
        return {};
      }
    }
    const int component = transitionGraph.compatible_chart_component(points);
    if (component < 0) {
      return {};
    }
    return transitionGraph.chart_component_faces(component);
  }

  [[nodiscard]] std::set<std::pair<int, int>> chart_labels(
      const std::vector<int> &chartFaces) const {
    std::set<std::pair<int, int>> labels;
    if (!available()) {
      return labels;
    }
    for (const int face : chartFaces) {
      if (face >= 0 && face < sourceFaces->rows()) {
        labels.insert({(*components)[static_cast<std::size_t>(face)],
                       (*sheets)[static_cast<std::size_t>(face)]});
      }
    }
    return labels;
  }

  [[nodiscard]] bool have_compatible_chart(
      const std::vector<const geometry::SurfacePoint *> &points) const {
    return !compatible_chart_faces(points).empty();
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

Eigen::Vector3d polygon_normal(const Eigen::MatrixXd &vertices,
                                      const std::vector<int> &polygon);

} // namespace source_authoritative_detail

MeshTopologySummary summarize_mesh_topology(const Eigen::MatrixXi &faces);

SourceAuthoritativeMeshValidationResult
validate_source_authoritative_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SourceAuthoritativeMeshValidatorOptions &options);

} // namespace directional::validation

#endif // DIRECTIONAL_VALIDATION_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_H
