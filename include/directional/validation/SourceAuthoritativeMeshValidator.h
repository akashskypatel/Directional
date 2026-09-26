// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VALIDATION_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_H
#define DIRECTIONAL_VALIDATION_SOURCE_AUTHORITATIVE_MESH_VALIDATOR_H

#include <optional>
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
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <directional/authority/CanonicalRoute.h>

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

/** One exact hard-rail edge in an output vertex's retained source-chart
 * reachability graph. */
struct SourceHardRailChartEquivalence {
  int firstFrontEdge = -1;
  int secondFrontEdge = -1;
  std::optional<authority::HardRailId> rail;
  authority::CanonicalRoute route;

  auto operator<=>(const SourceHardRailChartEquivalence &) const = default;
};

/** Validation-only projection of the complete quotient lineage retained for
 * one output vertex. Scalar SurfacePoint authority remains separate. */
struct SourceVertexChartAuthority {
  bool retained = false;
  std::vector<geometry::SourceProjectionChart> sourceCharts;
  std::vector<SourceHardRailChartEquivalence> hardRailEquivalences;
};

struct SourceAuthoritativeMeshValidatorOptions {
  double geometricTolerance = 1.0e-9;
  const Eigen::MatrixXd *sourceVertices = nullptr;
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const geometry::SourceTopologyRegions *sourceAuthority = nullptr;
  const std::vector<geometry::SurfacePoint> *vertexProvenance = nullptr;
  const std::vector<SourceVertexChartAuthority> *vertexChartAuthority =
      nullptr;
  const std::vector<int> *outputQuadSourceFaces = nullptr;
  std::set<authority::SourceEdgeTopologyKey> sourceHardFeatureEdges;
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
  bool strictValidationUsed = false;
  bool provenanceValidationUsed = false;
  bool boundaryAuthorityUsed = false;
  bool featureRailAuthorityUsed = false;
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

struct SourceChartCompatibility {
  int chartComponent = -1;
  geometry::SourceChartComponentIdentity semanticSide;
  std::vector<int> chartFaces;
  std::vector<std::vector<int>> pointFaces;

  [[nodiscard]] bool valid() const {
    return chartComponent >= 0 && semanticSide.valid && !chartFaces.empty() &&
           !pointFaces.empty();
  }
};

/** Typed source ownership label used only for semantic comparison. */
struct SourceScopeLabel {
  authority::SourceComponentId component;
  authority::IsolationSheetId sheet;

  auto operator<=>(const SourceScopeLabel &) const = default;
};

struct SourcePointLabelSupport {
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const geometry::SourceTopologyRegions *authority = nullptr;
  geometry::SurfacePointSourceSupportResolver sourceSupport;
  geometry::SourceChartTransitionGraph transitionGraph;

  SourcePointLabelSupport(
      const Eigen::MatrixXi *faces,
      const geometry::SourceTopologyRegions *sourceAuthority,
      const std::set<authority::SourceEdgeTopologyKey> *hardFeatureEdges)
      : sourceFaces(faces), authority(sourceAuthority), sourceSupport(faces),
        transitionGraph(
            faces, sourceAuthority,
            hardFeatureEdges != nullptr ? *hardFeatureEdges
                                        : geometry::empty_hard_feature_edges()) {
    if (faces == nullptr || faces->cols() != 3 || faces->rows() <= 0) {
      return;
    }

    int maximumVertex = -1;
    for (int face = 0; face < faces->rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = (*faces)(face, corner);
        if (vertex < 0) {
          return;
        }
        maximumVertex = std::max(maximumVertex, vertex);
      }
    }
    if (maximumVertex < 0) {
      return;
    }

    const std::size_t vertexExtent =
        static_cast<std::size_t>(maximumVertex) + 1U;
    const std::size_t faceExtent = static_cast<std::size_t>(faces->rows());
    for (int face = 0; face < faces->rows(); ++face) {
      const auto faceId = authority::SourceFaceId::from_index(face, faceExtent);
      if (!faceId) {
        return;
      }
      sourceFaceRows.emplace(faceId.value(), face);
      for (int corner = 0; corner < 3; ++corner) {
        const int first = (*faces)(face, corner);
        const int second = (*faces)(face, (corner + 1) % 3);
        if (first == second) {
          return;
        }
        const auto firstId =
            authority::SourceVertexId::from_index(first, vertexExtent);
        const auto secondId =
            authority::SourceVertexId::from_index(second, vertexExtent);
        if (!firstId || !secondId) {
          return;
        }
        const auto topology = authority::SourceEdgeTopologyKey::make(
            firstId.value(), secondId.value());
        if (!topology) {
          return;
        }
        sourceEdgeFaces[topology.value()].push_back(face);

        if (hardFeatureEdges != nullptr &&
            hardFeatureEdges->count(topology.value()) != 0U) {
          hardFeatureTopologies.insert(topology.value());
        }
      }
    }
    for (auto &[edge, incidentFaces] : sourceEdgeFaces) {
      (void)edge;
      std::sort(incidentFaces.begin(), incidentFaces.end());
      incidentFaces.erase(
          std::unique(incidentFaces.begin(), incidentFaces.end()),
          incidentFaces.end());
    }
  }

  [[nodiscard]] bool available() const {
    return sourceSupport.available() && transitionGraph.available() &&
           authority != nullptr && sourceFaces != nullptr &&
           authority->matches_source_faces(*sourceFaces);
  }

  [[nodiscard]] std::vector<authority::SourceFaceId>
  supported_faces(const geometry::SurfacePoint &point) const {
    if (!available()) {
      return {};
    }
    return sourceSupport.resolve(point).incidentFaces;
  }

  [[nodiscard]] std::set<SourceScopeLabel>
  supported_labels(const geometry::SurfacePoint &point) const {
    std::set<SourceScopeLabel> labels;
    for (const authority::SourceFaceId sourceFace : supported_faces(point)) {
      const std::size_t face = sourceFace.index();
      if (face >= static_cast<std::size_t>(sourceFaces->rows())) {
        continue;
      }
      labels.insert({authority->component_for_row(sourceFace),
                     authority->sheet_for_row(sourceFace)});
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

  // A completed output face may live on one source chart component or reach
  // one through exact quotient-retained hard-rail relations. Complete output
  // authority establishes reciprocity; proximity, row order, and a global
  // hard-feature union never establish compatibility.
  [[nodiscard]] SourceChartCompatibility resolve_compatible_chart(
      const std::vector<const geometry::SurfacePoint *> &points,
      const std::vector<const SourceVertexChartAuthority *> &authorities = {},
      const std::vector<geometry::SurfacePoint> *completePoints = nullptr,
      const std::vector<SourceVertexChartAuthority> *completeAuthorities =
          nullptr) const;

  [[nodiscard]] std::vector<int> compatible_chart_faces(
      const std::vector<const geometry::SurfacePoint *> &points,
      const std::vector<const SourceVertexChartAuthority *> &authorities = {},
      const std::vector<geometry::SurfacePoint> *completePoints = nullptr,
      const std::vector<SourceVertexChartAuthority> *completeAuthorities =
          nullptr) const {
    return resolve_compatible_chart(points, authorities, completePoints,
                                    completeAuthorities)
        .chartFaces;
  }

  [[nodiscard]] std::set<SourceScopeLabel> chart_labels(
      const std::vector<int> &chartFaces) const {
    std::set<SourceScopeLabel> labels;
    if (!available()) {
      return labels;
    }
    for (const int face : chartFaces) {
      if (face >= 0 && face < sourceFaces->rows()) {
        const auto sourceFaceId = authority::SourceFaceId::from_index(
            face, authority->face_count());
        if (sourceFaceId) {
          labels.insert({authority->component_for_row(sourceFaceId.value()),
                         authority->sheet_for_row(sourceFaceId.value())});
        }
      }
    }
    return labels;
  }

  [[nodiscard]] bool have_compatible_chart(
      const std::vector<const geometry::SurfacePoint *> &points,
      const std::vector<const SourceVertexChartAuthority *> &authorities = {},
      const std::vector<geometry::SurfacePoint> *completePoints = nullptr,
      const std::vector<SourceVertexChartAuthority> *completeAuthorities =
          nullptr) const {
    return resolve_compatible_chart(points, authorities, completePoints,
                                    completeAuthorities)
        .valid();
  }

  [[nodiscard]] bool have_common_label(
      const std::vector<const geometry::SurfacePoint *> &points) const {
    if (!available() || points.empty()) {
      return false;
    }
    std::set<SourceScopeLabel> common;
    bool first = true;
    for (const geometry::SurfacePoint *point : points) {
      if (point == nullptr) {
        return false;
      }
      const std::set<SourceScopeLabel> labels = supported_labels(*point);
      if (labels.empty()) {
        return false;
      }
      if (first) {
        common = labels;
        first = false;
      } else {
        std::set<SourceScopeLabel> intersection;
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

  // Semantic validator queries stay typed after the raw source-matrix ingress.
  std::set<authority::SourceEdgeTopologyKey> hardFeatureTopologies;
  std::map<authority::SourceEdgeTopologyKey, std::vector<int>> sourceEdgeFaces;
  // Representation-only locator: typed face identity to the checked source row.
  std::map<authority::SourceFaceId, int> sourceFaceRows;
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
