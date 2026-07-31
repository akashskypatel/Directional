// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_TRI_FLOW_SIMPLIFICATION_H
#define DIRECTIONAL_MESHING_TRI_FLOW_SIMPLIFICATION_H

#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

#include <Eigen/Core>

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#include <Eigen/Dense>
#endif

/**
 * @file TriFlowSimplification.h
 * @brief NVF-guided watershed clustering and constrained QEM simplification.
 *
 * This implements the mesh extraction / simplification stage described by
 * TriFlow: vertices are grouped by a nearest-vertex vector field (NVF) using a
 * priority watershed pass, then a quadric-error simplifier collapses only
 * topology-compatible edges and biases contraction positions toward the NVF
 * targets. It does not implement the neural SDF/NVF generator; callers must
 * supply per-vertex NVF displacements or per-vertex target positions to enable
 * topology-aware constraints.
 */

namespace directional {

struct TriFlowSimplificationOptions {
  /** Target number of output triangles. If negative, targetFaceRatio is used. */
  int targetFaceCount = -1;

  /** Fraction of input faces to keep when targetFaceCount is negative. */
  double targetFaceRatio = 0.5;

  /** Optional #V x 3 per-vertex NVF displacement t(v). */
  Eigen::MatrixXd vertexNvf;

  /** Optional #V x 3 per-vertex predicted target x(v). Overrides vertexNvf. */
  Eigen::MatrixXd vertexTargets;

  /** Explicit Phase 13 root label for each input vertex. Overrides NVF roots. */
  Eigen::VectorXi prescribedRootLabels;

  /** Explicit Phase 13 target position for each root label. */
  Eigen::MatrixXd prescribedRootTargets;

  /** Canonical edge keys that must not be collapsed. */
  std::vector<std::uint64_t> protectedEdgeKeys;

  /** Root threshold tau. If negative, 0.5 * bbox diagonal / voxelResolution. */
  double rootThreshold = -1.0;

  /** Resolution used only to derive the default root threshold. */
  int voxelResolution = 512;

  /** Weight of the positional target quadric. */
  double topologyWeight = 0.1;

  /** Optional relaxation distance for cross-root contractions. 0 keeps strict roots. */
  double rootRelaxationThreshold = 0.0;

  /** Keep initial mesh boundary vertices on boundary-compatible collapses. */
  bool preserveBoundary = true;

  /** Reject collapses that invert adjacent face normals. */
  bool rejectFaceFlips = true;

  /** Print simplification details to stderr. */
  bool verbose = false;
};

struct TriFlowSimplificationResult {
  bool success = false;
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::VectorXi rootLabels;
  int rootCount = 0;
  int collapsedEdges = 0;
  int rejectedCrossRootCandidates = 0;
  int rejectedProtectedEdges = 0;
};

namespace detail {

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
std::uint64_t edge_key(const int a, const int b) {
  const auto lo = static_cast<std::uint32_t>(std::min(a, b));
  const auto hi = static_cast<std::uint32_t>(std::max(a, b));
  return (static_cast<std::uint64_t>(lo) << 32u) | hi;
}
#else
std::uint64_t edge_key(const int a, const int b);
#endif

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
Eigen::Matrix4d plane_quadric(const Eigen::RowVector3d &a,
                                     const Eigen::RowVector3d &b,
                                     const Eigen::RowVector3d &c) {
  const Eigen::RowVector3d normal = (b - a).cross(c - a);
  const double norm = normal.norm();
  if (norm <= std::numeric_limits<double>::epsilon())
    return Eigen::Matrix4d::Zero();

  Eigen::Vector4d plane;
  plane.head<3>() = (normal / norm).transpose();
  plane[3] = -plane.head<3>().dot(a.transpose());
  return plane * plane.transpose();
}
#else
Eigen::Matrix4d plane_quadric(const Eigen::RowVector3d &a,
                                     const Eigen::RowVector3d &b,
                                     const Eigen::RowVector3d &c);
#endif

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
Eigen::Matrix4d point_quadric(const Eigen::RowVector3d &point) {
  Eigen::Matrix4d quadric = Eigen::Matrix4d::Zero();
  quadric(0, 0) = 1.0;
  quadric(1, 1) = 1.0;
  quadric(2, 2) = 1.0;
  quadric(0, 3) = quadric(3, 0) = -point.x();
  quadric(1, 3) = quadric(3, 1) = -point.y();
  quadric(2, 3) = quadric(3, 2) = -point.z();
  quadric(3, 3) = point.squaredNorm();
  return quadric;
}
#else
Eigen::Matrix4d point_quadric(const Eigen::RowVector3d &point);
#endif

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
double quadric_error(const Eigen::Matrix4d &quadric,
                            const Eigen::RowVector3d &point) {
  Eigen::Vector4d homogeneous;
  homogeneous << point.x(), point.y(), point.z(), 1.0;
  return homogeneous.dot(quadric * homogeneous);
}
#else
double quadric_error(const Eigen::Matrix4d &quadric,
                            const Eigen::RowVector3d &point);
#endif

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
Eigen::RowVector3d best_quadric_position(
    const Eigen::Matrix4d &quadric,
    const std::vector<Eigen::RowVector3d> &fallbacks) {
  const Eigen::Matrix3d a = quadric.topLeftCorner<3, 3>();
  const Eigen::Vector3d b = quadric.topRightCorner<3, 1>();

  if (std::abs(a.determinant()) > 1e-12) {
    const Eigen::Vector3d solved = a.fullPivLu().solve(-b);
    if (solved.allFinite())
      return solved.transpose();
  }

  double bestCost = std::numeric_limits<double>::infinity();
  Eigen::RowVector3d best = Eigen::RowVector3d::Zero();
  for (const Eigen::RowVector3d &candidate : fallbacks) {
    const double cost = quadric_error(quadric, candidate);
    if (cost < bestCost) {
      bestCost = cost;
      best = candidate;
    }
  }
  return best;
}
#else
Eigen::RowVector3d best_quadric_position(
    const Eigen::Matrix4d &quadric,
    const std::vector<Eigen::RowVector3d> &fallbacks);
#endif

template <typename Matrix>
inline void validate_matrix_shape(const Matrix &matrix, const Eigen::Index rows,
                                  const Eigen::Index columns,
                                  const char *name) {
  if (matrix.rows() != rows || matrix.cols() != columns) {
    throw std::runtime_error(std::string(name) + " must have shape (" +
                             std::to_string(rows) + ", " +
                             std::to_string(columns) + ").");
  }
}

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
class TriFlowSimplifier {
public:
  TriFlowSimplifier(const Eigen::MatrixXd &inputVertices,
                    const Eigen::MatrixXi &inputFaces,
                    TriFlowSimplificationOptions options)
      : options_(std::move(options)) {
    validate_matrix_shape(inputVertices, inputVertices.rows(), 3,
                          "Input vertices");
    validate_matrix_shape(inputFaces, inputFaces.rows(), 3, "Input faces");
    if (inputVertices.rows() <= 0 || inputFaces.rows() <= 0) {
      throw std::runtime_error("Simplification requires non-empty vertices and faces.");
    }

    vertices_.resize(static_cast<std::size_t>(inputVertices.rows()));
    validVertex_.assign(vertices_.size(), true);
    quadrics_.assign(vertices_.size(), Eigen::Matrix4d::Zero());
    rootLabel_.assign(vertices_.size(), -1);
    vertexVersion_.assign(vertices_.size(), 0);
    vertexFaces_.resize(vertices_.size());

    for (Eigen::Index i = 0; i < inputVertices.rows(); ++i)
      vertices_[static_cast<std::size_t>(i)] = inputVertices.row(i);

    faces_.reserve(static_cast<std::size_t>(inputFaces.rows()));
    validFace_.reserve(static_cast<std::size_t>(inputFaces.rows()));
    for (Eigen::Index face = 0; face < inputFaces.rows(); ++face) {
      std::array<int, 3> triangle{inputFaces(face, 0), inputFaces(face, 1),
                                  inputFaces(face, 2)};
      for (const int vertex : triangle) {
        if (vertex < 0 || vertex >= inputVertices.rows()) {
          throw std::runtime_error("Input face contains an out-of-range vertex index.");
        }
      }

      faces_.push_back(triangle);
      validFace_.push_back(triangle[0] != triangle[1] &&
                           triangle[1] != triangle[2] &&
                           triangle[2] != triangle[0]);
    }

    rebuild_vertex_faces();
    validFaceCount_ = 0;
    for (const bool valid : validFace_) {
      if (valid)
        ++validFaceCount_;
    }
  }

  TriFlowSimplificationResult run() {
    TriFlowSimplificationResult result;

    if (validFaceCount_ == 0)
      return result;

    const int targetFaceCount = resolve_target_face_count();
    prepare_targets_and_roots();
    compute_initial_boundary_state();
    recompute_quadrics();
    initialize_edge_queue();

    if (options_.verbose) {
      std::cerr << "[Directional::tri_flow_simplify]: inputFaces="
                << validFaceCount_ << " targetFaces=" << targetFaceCount
                << " roots=" << rootCount_ << '\n';
    }

    while (validFaceCount_ > targetFaceCount && !queue_.empty()) {
      const Candidate candidate = queue_.top();
      queue_.pop();

      if (!candidate_is_current(candidate))
        continue;

      Candidate refreshed;
      if (!make_candidate(candidate.a, candidate.b, refreshed))
        continue;

      if (!collapse_allowed(refreshed.a, refreshed.b, refreshed.position))
        continue;

      int keptVertex = -1;
      if (!collapse_edge(refreshed.a, refreshed.b, refreshed.position, keptVertex))
        continue;

      ++result.collapsedEdges;
      push_edges_around(keptVertex);
    }

    result.success = compact_result(result.vertices, result.faces,
                                    result.rootLabels);
    result.rootCount = rootCount_;
    return result;
  }

private:
  struct Candidate {
    double cost = std::numeric_limits<double>::infinity();
    int a = -1;
    int b = -1;
    int versionA = 0;
    int versionB = 0;
    Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  };

  struct CandidateGreater {
    bool operator()(const Candidate &lhs, const Candidate &rhs) const {
      if (lhs.cost != rhs.cost)
        return lhs.cost > rhs.cost;
      if (lhs.a != rhs.a)
        return lhs.a > rhs.a;
      return lhs.b > rhs.b;
    }
  };

  TriFlowSimplificationOptions options_;
  std::vector<Eigen::RowVector3d> vertices_;
  std::vector<std::array<int, 3>> faces_;
  std::vector<bool> validVertex_;
  std::vector<bool> validFace_;
  std::vector<Eigen::Matrix4d> quadrics_;
  std::vector<int> rootLabel_;
  std::vector<Eigen::RowVector3d> rootTarget_;
  std::vector<std::unordered_set<int>> vertexFaces_;
  std::vector<int> vertexVersion_;
  std::vector<bool> initialBoundaryVertex_;
  std::unordered_set<std::uint64_t> initialBoundaryEdges_;
  std::unordered_set<std::uint64_t> protectedEdges_;
  std::priority_queue<Candidate, std::vector<Candidate>, CandidateGreater>
      queue_;
  int validFaceCount_ = 0;
  int rootCount_ = 0;
  bool hasNvf_ = false;

  int resolve_target_face_count() const {
    if (options_.targetFaceCount >= 4)
      return std::min(options_.targetFaceCount, validFaceCount_);

    if (!std::isfinite(options_.targetFaceRatio) || options_.targetFaceRatio <= 0.0 ||
        options_.targetFaceRatio > 1.0) {
      throw std::runtime_error("targetFaceRatio must be in the range (0, 1].");
    }

    return std::max(4, static_cast<int>(std::ceil(
                           static_cast<double>(validFaceCount_) *
                           options_.targetFaceRatio)));
  }

  Eigen::RowVector3d bbox_min() const {
    Eigen::RowVector3d minCorner = vertices_.front();
    for (const Eigen::RowVector3d &vertex : vertices_)
      minCorner = minCorner.cwiseMin(vertex);
    return minCorner;
  }

  Eigen::RowVector3d bbox_max() const {
    Eigen::RowVector3d maxCorner = vertices_.front();
    for (const Eigen::RowVector3d &vertex : vertices_)
      maxCorner = maxCorner.cwiseMax(vertex);
    return maxCorner;
  }

  void prepare_targets_and_roots() {
    Eigen::MatrixXd targets;
    const Eigen::Index vertexCount = static_cast<Eigen::Index>(vertices_.size());

    protectedEdges_.clear();
    protectedEdges_.insert(options_.protectedEdgeKeys.begin(),
                           options_.protectedEdgeKeys.end());

    if (options_.prescribedRootLabels.size() > 0 ||
        options_.prescribedRootTargets.size() > 0) {
      validate_matrix_shape(options_.prescribedRootLabels, vertexCount, 1,
                            "prescribedRootLabels");
      if (options_.prescribedRootTargets.cols() != 3 ||
          options_.prescribedRootTargets.rows() <= 0) {
        throw std::runtime_error(
            "prescribedRootTargets must have shape (#roots, 3).");
      }
      rootLabel_.assign(vertices_.size(), -1);
      for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
        const int label = options_.prescribedRootLabels[vertex];
        if (label < 0 || label >= options_.prescribedRootTargets.rows()) {
          throw std::runtime_error(
              "prescribedRootLabels contains an out-of-range root label.");
        }
        rootLabel_[static_cast<std::size_t>(vertex)] = label;
      }
      rootTarget_.resize(static_cast<std::size_t>(
          options_.prescribedRootTargets.rows()));
      for (int root = 0; root < options_.prescribedRootTargets.rows(); ++root) {
        rootTarget_[static_cast<std::size_t>(root)] =
            options_.prescribedRootTargets.row(root);
      }
      rootCount_ = static_cast<int>(rootTarget_.size());
      hasNvf_ = true;
      return;
    }

    if (options_.vertexTargets.size() > 0) {
      validate_matrix_shape(options_.vertexTargets, vertexCount, 3,
                            "vertexTargets");
      targets = options_.vertexTargets;
      hasNvf_ = true;
    } else if (options_.vertexNvf.size() > 0) {
      validate_matrix_shape(options_.vertexNvf, vertexCount, 3, "vertexNvf");
      targets.resize(vertexCount, 3);
      for (Eigen::Index i = 0; i < vertexCount; ++i)
        targets.row(i) = vertices_[static_cast<std::size_t>(i)] +
                         options_.vertexNvf.row(i);
      hasNvf_ = true;
    } else {
      std::fill(rootLabel_.begin(), rootLabel_.end(), 0);
      rootTarget_.assign(1, Eigen::RowVector3d::Zero());
      rootCount_ = 1;
      hasNvf_ = false;
      return;
    }

    double threshold = options_.rootThreshold;
    if (threshold < 0.0) {
      const double diagonal = (bbox_max() - bbox_min()).norm();
      const int resolution = std::max(1, options_.voxelResolution);
      threshold = 0.5 * diagonal / static_cast<double>(resolution);
    }

    struct QueueItem {
      double cost;
      int vertex;
      int root;
    };
    struct QueueItemGreater {
      bool operator()(const QueueItem &lhs, const QueueItem &rhs) const {
        if (lhs.cost != rhs.cost)
          return lhs.cost > rhs.cost;
        if (lhs.root != rhs.root)
          return lhs.root > rhs.root;
        return lhs.vertex > rhs.vertex;
      }
    };

    std::priority_queue<QueueItem, std::vector<QueueItem>, QueueItemGreater>
        queue;
    std::vector<int> rootVertex;
    rootVertex.reserve(vertices_.size());

    int bestRoot = 0;
    double bestRootNorm = std::numeric_limits<double>::infinity();

    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      const Eigen::RowVector3d displacement =
          targets.row(vertex) - vertices_[static_cast<std::size_t>(vertex)];
      const double infNorm = displacement.cwiseAbs().maxCoeff();
      if (infNorm < bestRootNorm) {
        bestRootNorm = infNorm;
        bestRoot = vertex;
      }
      if (infNorm <= threshold) {
        const int root = static_cast<int>(rootVertex.size());
        rootVertex.push_back(vertex);
        queue.push(QueueItem{0.0, vertex, root});
      }
    }

    if (rootVertex.empty()) {
      rootVertex.push_back(bestRoot);
      queue.push(QueueItem{0.0, bestRoot, 0});
    }

    std::fill(rootLabel_.begin(), rootLabel_.end(), -1);
    while (!queue.empty()) {
      const QueueItem item = queue.top();
      queue.pop();
      if (rootLabel_[static_cast<std::size_t>(item.vertex)] >= 0)
        continue;

      rootLabel_[static_cast<std::size_t>(item.vertex)] = item.root;
      const Eigen::RowVector3d rootTarget = targets.row(rootVertex[item.root]);

      for (const int face : vertexFaces_[static_cast<std::size_t>(item.vertex)]) {
        if (!validFace_[static_cast<std::size_t>(face)])
          continue;
        for (const int neighbor : faces_[static_cast<std::size_t>(face)]) {
          if (neighbor == item.vertex)
            continue;
          if (rootLabel_[static_cast<std::size_t>(neighbor)] >= 0)
            continue;
          const double cost =
              (targets.row(neighbor) - rootTarget).norm();
          queue.push(QueueItem{cost, neighbor, item.root});
        }
      }
    }

    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      if (rootLabel_[static_cast<std::size_t>(vertex)] >= 0)
        continue;

      int best = 0;
      double bestCost = std::numeric_limits<double>::infinity();
      for (int root = 0; root < static_cast<int>(rootVertex.size()); ++root) {
        const double cost =
            (targets.row(vertex) - targets.row(rootVertex[root])).norm();
        if (cost < bestCost) {
          bestCost = cost;
          best = root;
        }
      }
      rootLabel_[static_cast<std::size_t>(vertex)] = best;
    }

    rootTarget_.resize(rootVertex.size());
    for (int root = 0; root < static_cast<int>(rootVertex.size()); ++root) {
      rootTarget_[static_cast<std::size_t>(root)] = targets.row(rootVertex[root]);
    }
    rootCount_ = static_cast<int>(rootTarget_.size());
  }

  void rebuild_vertex_faces() {
    for (std::unordered_set<int> &faces : vertexFaces_)
      faces.clear();

    for (int face = 0; face < static_cast<int>(faces_.size()); ++face) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      for (const int vertex : faces_[static_cast<std::size_t>(face)])
        vertexFaces_[static_cast<std::size_t>(vertex)].insert(face);
    }
  }

  void compute_initial_boundary_state() {
    initialBoundaryVertex_.assign(vertices_.size(), false);
    initialBoundaryEdges_.clear();

    std::unordered_map<std::uint64_t, int> counts;
    for (int face = 0; face < static_cast<int>(faces_.size()); ++face) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      for (int i = 0; i < 3; ++i) {
        const int a = triangle[i];
        const int b = triangle[(i + 1) % 3];
        ++counts[edge_key(a, b)];
      }
    }

    for (const auto &[key, count] : counts) {
      if (count != 1)
        continue;
      const int a = static_cast<int>(key >> 32u);
      const int b = static_cast<int>(key & 0xffffffffu);
      initialBoundaryEdges_.insert(key);
      initialBoundaryVertex_[static_cast<std::size_t>(a)] = true;
      initialBoundaryVertex_[static_cast<std::size_t>(b)] = true;
    }
  }

  void recompute_quadrics() {
    std::fill(quadrics_.begin(), quadrics_.end(), Eigen::Matrix4d::Zero());

    for (int face = 0; face < static_cast<int>(faces_.size()); ++face) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      const Eigen::Matrix4d quadric = plane_quadric(
          vertices_[static_cast<std::size_t>(triangle[0])],
          vertices_[static_cast<std::size_t>(triangle[1])],
          vertices_[static_cast<std::size_t>(triangle[2])]);
      for (const int vertex : triangle)
        quadrics_[static_cast<std::size_t>(vertex)] += quadric;
    }
  }

  void initialize_edge_queue() {
    while (!queue_.empty())
      queue_.pop();

    std::unordered_set<std::uint64_t> seen;
    for (int face = 0; face < static_cast<int>(faces_.size()); ++face) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      for (int i = 0; i < 3; ++i) {
        const int a = triangle[i];
        const int b = triangle[(i + 1) % 3];
        if (seen.insert(edge_key(a, b)).second)
          push_edge(a, b);
      }
    }
  }

  bool vertex_is_valid(const int vertex) const {
    return vertex >= 0 && vertex < static_cast<int>(vertices_.size()) &&
           validVertex_[static_cast<std::size_t>(vertex)];
  }

  bool face_is_current_edge(const int a, const int b) const {
    if (!vertex_is_valid(a) || !vertex_is_valid(b))
      return false;

    const auto &facesA = vertexFaces_[static_cast<std::size_t>(a)];
    const auto &facesB = vertexFaces_[static_cast<std::size_t>(b)];
    const auto &small = facesA.size() < facesB.size() ? facesA : facesB;
    const auto &large = facesA.size() < facesB.size() ? facesB : facesA;
    for (const int face : small) {
      if (large.contains(face) && validFace_[static_cast<std::size_t>(face)])
        return true;
    }
    return false;
  }

  bool candidate_is_current(const Candidate &candidate) const {
    return vertex_is_valid(candidate.a) && vertex_is_valid(candidate.b) &&
           vertexVersion_[static_cast<std::size_t>(candidate.a)] ==
               candidate.versionA &&
           vertexVersion_[static_cast<std::size_t>(candidate.b)] ==
               candidate.versionB &&
           face_is_current_edge(candidate.a, candidate.b);
  }

  Eigen::Matrix4d candidate_quadric(const int a, const int b) const {
    Eigen::Matrix4d quadric = 0.5 * (quadrics_[static_cast<std::size_t>(a)] +
                                    quadrics_[static_cast<std::size_t>(b)]);
    if (hasNvf_ && options_.topologyWeight > 0.0) {
      const int root = rootLabel_[static_cast<std::size_t>(a)];
      if (root >= 0 && root == rootLabel_[static_cast<std::size_t>(b)] &&
          root < static_cast<int>(rootTarget_.size())) {
        quadric += options_.topologyWeight *
                   point_quadric(rootTarget_[static_cast<std::size_t>(root)]);
      }
    }
    return quadric;
  }

  bool roots_compatible(const int a, const int b) const {
    if (!hasNvf_)
      return true;
    const int rootA = rootLabel_[static_cast<std::size_t>(a)];
    const int rootB = rootLabel_[static_cast<std::size_t>(b)];
    if (rootA == rootB)
      return true;
    if (options_.rootRelaxationThreshold <= 0.0)
      return false;
    if (rootA < 0 || rootB < 0 || rootA >= static_cast<int>(rootTarget_.size()) ||
        rootB >= static_cast<int>(rootTarget_.size()))
      return false;
    return (rootTarget_[static_cast<std::size_t>(rootA)] -
            rootTarget_[static_cast<std::size_t>(rootB)])
               .norm() <= options_.rootRelaxationThreshold;
  }

  bool edge_is_protected(const int a, const int b) const {
    return protectedEdges_.contains(edge_key(a, b));
  }

  bool make_candidate(const int inputA, const int inputB,
                      Candidate &candidate) const {
    if (!vertex_is_valid(inputA) || !vertex_is_valid(inputB) ||
        inputA == inputB || !face_is_current_edge(inputA, inputB))
      return false;

    int a = inputA;
    int b = inputB;
    if (a > b)
      std::swap(a, b);

    if (!roots_compatible(a, b) || edge_is_protected(a, b))
      return false;

    const Eigen::Matrix4d quadric = candidate_quadric(a, b);
    std::vector<Eigen::RowVector3d> fallbacks;
    fallbacks.reserve(4);
    fallbacks.push_back(vertices_[static_cast<std::size_t>(a)]);
    fallbacks.push_back(vertices_[static_cast<std::size_t>(b)]);
    fallbacks.push_back(0.5 * (vertices_[static_cast<std::size_t>(a)] +
                               vertices_[static_cast<std::size_t>(b)]));
    if (hasNvf_) {
      const int root = rootLabel_[static_cast<std::size_t>(a)];
      if (root >= 0 && root == rootLabel_[static_cast<std::size_t>(b)] &&
          root < static_cast<int>(rootTarget_.size()))
        fallbacks.push_back(rootTarget_[static_cast<std::size_t>(root)]);
    }

    candidate.a = a;
    candidate.b = b;
    candidate.versionA = vertexVersion_[static_cast<std::size_t>(a)];
    candidate.versionB = vertexVersion_[static_cast<std::size_t>(b)];
    candidate.position = best_quadric_position(quadric, fallbacks);
    candidate.cost = quadric_error(quadric, candidate.position);
    return std::isfinite(candidate.cost) && candidate.position.allFinite();
  }

  void push_edge(const int a, const int b) {
    Candidate candidate;
    if (make_candidate(a, b, candidate))
      queue_.push(candidate);
  }

  void push_edges_around(const int vertex) {
    if (!vertex_is_valid(vertex))
      return;

    std::unordered_set<std::uint64_t> seen;
    for (const int face : vertexFaces_[static_cast<std::size_t>(vertex)]) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      for (int i = 0; i < 3; ++i) {
        const int a = triangle[i];
        const int b = triangle[(i + 1) % 3];
        if (a == b || !vertex_is_valid(a) || !vertex_is_valid(b))
          continue;
        if (seen.insert(edge_key(a, b)).second)
          push_edge(a, b);
      }
    }
  }

  std::set<int> vertex_neighbors(const int vertex) const {
    std::set<int> neighbors;
    if (!vertex_is_valid(vertex))
      return neighbors;

    for (const int face : vertexFaces_[static_cast<std::size_t>(vertex)]) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      for (const int other : faces_[static_cast<std::size_t>(face)]) {
        if (other != vertex && vertex_is_valid(other))
          neighbors.insert(other);
      }
    }
    return neighbors;
  }

  std::vector<int> edge_faces(const int a, const int b) const {
    std::vector<int> result;
    const auto &facesA = vertexFaces_[static_cast<std::size_t>(a)];
    const auto &facesB = vertexFaces_[static_cast<std::size_t>(b)];
    const auto &small = facesA.size() < facesB.size() ? facesA : facesB;
    const auto &large = facesA.size() < facesB.size() ? facesB : facesA;
    for (const int face : small) {
      if (large.contains(face) && validFace_[static_cast<std::size_t>(face)])
        result.push_back(face);
    }
    return result;
  }

  bool link_condition_ok(const int keep, const int drop) const {
    const std::vector<int> incidentEdgeFaces = edge_faces(keep, drop);
    if (incidentEdgeFaces.empty() || incidentEdgeFaces.size() > 2)
      return false;

    std::set<int> expectedCommonNeighbors;
    for (const int face : incidentEdgeFaces) {
      for (const int vertex : faces_[static_cast<std::size_t>(face)]) {
        if (vertex != keep && vertex != drop)
          expectedCommonNeighbors.insert(vertex);
      }
    }

    const std::set<int> keepNeighbors = vertex_neighbors(keep);
    const std::set<int> dropNeighbors = vertex_neighbors(drop);
    std::set<int> actualCommonNeighbors;
    std::set_intersection(keepNeighbors.begin(), keepNeighbors.end(),
                          dropNeighbors.begin(), dropNeighbors.end(),
                          std::inserter(actualCommonNeighbors,
                                        actualCommonNeighbors.begin()));

    return actualCommonNeighbors == expectedCommonNeighbors;
  }

  bool face_flips_ok(const int keep, const int drop,
                     const Eigen::RowVector3d &newPosition) const {
    if (!options_.rejectFaceFlips)
      return true;

    for (const int face : vertexFaces_[static_cast<std::size_t>(drop)]) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;

      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      if (triangle[0] == keep || triangle[1] == keep || triangle[2] == keep)
        continue;

      Eigen::RowVector3d before[3];
      Eigen::RowVector3d after[3];
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = triangle[corner];
        before[corner] = vertices_[static_cast<std::size_t>(vertex)];
        after[corner] = vertex == drop ? newPosition : before[corner];
      }

      const Eigen::RowVector3d normalBefore =
          (before[1] - before[0]).cross(before[2] - before[0]);
      const Eigen::RowVector3d normalAfter =
          (after[1] - after[0]).cross(after[2] - after[0]);
      const double beforeNorm = normalBefore.norm();
      const double afterNorm = normalAfter.norm();
      if (beforeNorm <= 1e-15 || afterNorm <= 1e-15)
        return false;
      if (normalBefore.dot(normalAfter) <= 0.0)
        return false;
    }

    return true;
  }

  bool boundary_ok(const int keep, const int drop) const {
    if (!options_.preserveBoundary)
      return true;

    const bool keepBoundary = initialBoundaryVertex_[static_cast<std::size_t>(keep)];
    const bool dropBoundary = initialBoundaryVertex_[static_cast<std::size_t>(drop)];
    if (keepBoundary != dropBoundary)
      return false;
    if (keepBoundary && dropBoundary &&
        !initialBoundaryEdges_.contains(edge_key(keep, drop)))
      return false;
    return true;
  }

  bool collapse_allowed(const int a, const int b,
                        const Eigen::RowVector3d &position) const {
    if (!roots_compatible(a, b) || edge_is_protected(a, b) ||
        !boundary_ok(a, b))
      return false;
    if (!link_condition_ok(a, b))
      return false;
    return face_flips_ok(a, b, position);
  }

  int choose_keep_vertex(const int a, const int b) const {
    if (hasNvf_) {
      const int root = rootLabel_[static_cast<std::size_t>(a)];
      if (root >= 0 && root == rootLabel_[static_cast<std::size_t>(b)] &&
          root < static_cast<int>(rootTarget_.size())) {
        const double distanceA =
            (vertices_[static_cast<std::size_t>(a)] -
             rootTarget_[static_cast<std::size_t>(root)])
                .squaredNorm();
        const double distanceB =
            (vertices_[static_cast<std::size_t>(b)] -
             rootTarget_[static_cast<std::size_t>(root)])
                .squaredNorm();
        if (distanceB < distanceA)
          return b;
      }
    }
    return a;
  }

  void invalidate_face(const int face) {
    if (!validFace_[static_cast<std::size_t>(face)])
      return;

    for (const int vertex : faces_[static_cast<std::size_t>(face)]) {
      if (vertex >= 0 && vertex < static_cast<int>(vertexFaces_.size()))
        vertexFaces_[static_cast<std::size_t>(vertex)].erase(face);
    }
    validFace_[static_cast<std::size_t>(face)] = false;
    --validFaceCount_;
  }

  bool collapse_edge(const int inputA, const int inputB,
                     const Eigen::RowVector3d &newPosition, int &keptVertex) {
    int keep = choose_keep_vertex(inputA, inputB);
    int drop = keep == inputA ? inputB : inputA;
    keptVertex = keep;

    if (!vertex_is_valid(keep) || !vertex_is_valid(drop))
      return false;

    if (!collapse_allowed(keep, drop, newPosition))
      return false;

    const std::vector<int> dropFaces(vertexFaces_[static_cast<std::size_t>(drop)].begin(),
                                     vertexFaces_[static_cast<std::size_t>(drop)].end());
    std::vector<int> removedFaces;
    std::vector<int> changedFaces;

    vertices_[static_cast<std::size_t>(keep)] = newPosition;
    quadrics_[static_cast<std::size_t>(keep)] += quadrics_[static_cast<std::size_t>(drop)];

    if (hasNvf_ && rootLabel_[static_cast<std::size_t>(keep)] !=
                       rootLabel_[static_cast<std::size_t>(drop)]) {
      const int rootKeep = rootLabel_[static_cast<std::size_t>(keep)];
      const int rootDrop = rootLabel_[static_cast<std::size_t>(drop)];
      if (rootKeep < 0 ||
          (rootDrop >= 0 && rootDrop < static_cast<int>(rootTarget_.size()) &&
           rootKeep < static_cast<int>(rootTarget_.size()) &&
           (newPosition - rootTarget_[static_cast<std::size_t>(rootDrop)]).squaredNorm() <
               (newPosition - rootTarget_[static_cast<std::size_t>(rootKeep)]).squaredNorm())) {
        rootLabel_[static_cast<std::size_t>(keep)] = rootDrop;
      }
    }

    for (const int face : dropFaces) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;

      auto &triangle = faces_[static_cast<std::size_t>(face)];
      bool containsKeep = false;
      bool containsDrop = false;
      for (const int vertex : triangle) {
        containsKeep = containsKeep || vertex == keep;
        containsDrop = containsDrop || vertex == drop;
      }

      if (!containsDrop)
        continue;

      if (containsKeep) {
        removedFaces.push_back(face);
        continue;
      }

      for (int &vertex : triangle) {
        if (vertex == drop)
          vertex = keep;
      }
      changedFaces.push_back(face);
    }

    for (const int face : removedFaces)
      invalidate_face(face);

    for (const int face : changedFaces) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      vertexFaces_[static_cast<std::size_t>(drop)].erase(face);
      vertexFaces_[static_cast<std::size_t>(keep)].insert(face);
    }

    vertexFaces_[static_cast<std::size_t>(drop)].clear();
    validVertex_[static_cast<std::size_t>(drop)] = false;
    ++vertexVersion_[static_cast<std::size_t>(keep)];
    ++vertexVersion_[static_cast<std::size_t>(drop)];
    return true;
  }

  bool compact_result(Eigen::MatrixXd &outputVertices, Eigen::MatrixXi &outputFaces,
                      Eigen::VectorXi &outputRootLabels) const {
    std::vector<int> remap(vertices_.size(), -1);
    int usedVertexCount = 0;
    for (int face = 0; face < static_cast<int>(faces_.size()); ++face) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      for (const int vertex : triangle) {
        if (!vertex_is_valid(vertex))
          return false;
        if (remap[static_cast<std::size_t>(vertex)] < 0)
          remap[static_cast<std::size_t>(vertex)] = usedVertexCount++;
      }
    }

    outputVertices.resize(usedVertexCount, 3);
    outputRootLabels.resize(usedVertexCount);
    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      const int mapped = remap[static_cast<std::size_t>(vertex)];
      if (mapped < 0)
        continue;
      outputVertices.row(mapped) = vertices_[static_cast<std::size_t>(vertex)];
      outputRootLabels(mapped) = rootLabel_[static_cast<std::size_t>(vertex)];
    }

    outputFaces.resize(validFaceCount_, 3);
    int faceRow = 0;
    for (int face = 0; face < static_cast<int>(faces_.size()); ++face) {
      if (!validFace_[static_cast<std::size_t>(face)])
        continue;
      const auto &triangle = faces_[static_cast<std::size_t>(face)];
      outputFaces(faceRow, 0) = remap[static_cast<std::size_t>(triangle[0])];
      outputFaces(faceRow, 1) = remap[static_cast<std::size_t>(triangle[1])];
      outputFaces(faceRow, 2) = remap[static_cast<std::size_t>(triangle[2])];
      if (outputFaces(faceRow, 0) == outputFaces(faceRow, 1) ||
          outputFaces(faceRow, 1) == outputFaces(faceRow, 2) ||
          outputFaces(faceRow, 2) == outputFaces(faceRow, 0))
        return false;
      ++faceRow;
    }

    return faceRow > 0;
  }
};
#endif

} // namespace detail

#if defined(DIRECTIONAL_TRI_FLOW_SIMPLIFICATION_IMPLEMENTATION)
TriFlowSimplificationResult
tri_flow_simplify(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                  const TriFlowSimplificationOptions &options = {}) {
  detail::TriFlowSimplifier simplifier(vertices, faces, options);
  return simplifier.run();
}
#else
TriFlowSimplificationResult
tri_flow_simplify(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                  const TriFlowSimplificationOptions &options = {});
#endif

} // namespace directional

#endif
