// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_TRI_FLOW_SIMPLIFICATION_DCEL_H
#define DIRECTIONAL_MESHING_TRI_FLOW_SIMPLIFICATION_DCEL_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/meshing/TriFlowSimplification.h>
#include <directional/numerics/ExactGeometry.h>

/**
 * @file TriFlowSimplificationDCEL.h
 * @brief Experimental TriFlow-style constrained QEM directly on FunctionDCEL.
 *
 * This header intentionally keeps the implementation separate from
 * NFunctionMesher::simplify_mesh().  The production mesher cleanup pass is a
 * field-integration/DCEL-arrangement algorithm.  This experimental pass instead
 * applies a TriFlow-inspired edge-collapse objective to the live FunctionDCEL:
 * it computes geometric quadrics from valid DCEL faces, optionally groups
 * vertices by supplied NVF/target positions, rejects protected field/seam
 * collapses, and mutates the DCEL in place under transaction rollback.
 */

namespace directional {

struct TriFlowSimplificationDCELOptions {
  /** Target number of valid DCEL vertices. If negative, targetVertexRatio is used. */
  int targetVertexCount = -1;

  /** Fraction of currently valid vertices to keep when targetVertexCount is negative. */
  double targetVertexRatio = 0.75;

  /** Optional target number of valid faces. Disabled when negative. */
  int targetFaceCount = -1;

  /** Optional fraction of valid faces to keep. Disabled when <= 0. */
  double targetFaceRatio = -1.0;

  /** Optional #dcel.vertices x 3 per-vertex NVF displacement t(v). */
  Eigen::MatrixXd vertexNvf;

  /** Optional #dcel.vertices x 3 per-vertex predicted target x(v). Overrides vertexNvf. */
  Eigen::MatrixXd vertexTargets;

  /** Explicit Phase 13 root label for each DCEL vertex. Overrides NVF roots. */
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

  /** Preserve vertices and edges that were on the initial DCEL boundary. */
  bool preserveBoundary = true;

  /** Reject collapses across function-isoline halfedges. */
  bool preserveFunctionEdges = true;

  /** Reject collapses across original-boundary/seam halfedges. */
  bool preserveOriginalBoundaryEdges = true;

  /** Reject collapses that invert adjacent face normals. */
  bool rejectFaceFlips = true;

  /** Update FunctionDCEL::VData::eCoords from the new floating-point position. */
  bool updateExactCoordinates = true;

  /** Require valid mutual twins before and after simplification. */
  bool requireConsistentTwins = true;

  /** Run a full DCEL consistency check after every accepted collapse. */
  bool validateAfterEachCollapse = true;

  /** Compact invalid DCEL records after the pass. Disabled by default to avoid remapping surprises. */
  bool compactAfter = false;

  /** Maximum failed candidates tested between accepted collapses. */
  int maxFailedCandidates = 10000;

  /** Print simplification details to stderr. */
  bool verbose = false;
};

struct TriFlowSimplificationDCELResult {
  bool success = false;
  int initialValidVertices = 0;
  int finalValidVertices = 0;
  int initialValidFaces = 0;
  int finalValidFaces = 0;
  int rootCount = 0;
  int collapsedEdges = 0;
  int rejectedCrossRootCandidates = 0;
  int rejectedProtectedEdges = 0;
  int rejectedCandidates = 0;
  int failedCollapses = 0;
};

namespace detail {

inline EVector3 triflow_dcel_exact_from_double(const Eigen::RowVector3d &p) {
  return EVector3{ENumber(p.x(), 1e-9), ENumber(p.y(), 1e-9),
                  ENumber(p.z(), 1e-9)};
}

template <typename FunctionDCEL> class TriFlowDCELSimplifier {
public:
  TriFlowDCELSimplifier(FunctionDCEL &dcel,
                        TriFlowSimplificationDCELOptions options)
      : dcel_(dcel), options_(std::move(options)) {}

  TriFlowSimplificationDCELResult run() {
    TriFlowSimplificationDCELResult result;

    if (!dcel_.check_consistency(options_.verbose, true,
                                 options_.requireConsistentTwins, false)) {
      if (options_.verbose) {
        std::cerr << "[Directional::tri_flow_simplify_dcel]: "
                  << "initial DCEL consistency check failed\n";
      }
      return result;
    }

    rebuild_topology_views();
    result.initialValidVertices = validVertexCount_;
    result.initialValidFaces = validFaceCount_;

    if (validVertexCount_ <= 0 || validFaceCount_ <= 0)
      return result;

    resolve_targets();
    prepare_targets_and_roots();
    compute_initial_boundary_state();

    const int targetVertexCount = resolve_target_vertex_count();
    const int targetFaceCount = resolve_target_face_count();

    if (options_.verbose) {
      std::cerr << "[Directional::tri_flow_simplify_dcel]: "
                << "inputVertices=" << validVertexCount_
                << " targetVertices=" << targetVertexCount
                << " inputFaces=" << validFaceCount_
                << " targetFaces=" << targetFaceCount
                << " roots=" << rootCount_ << '\n';
    }

    std::unordered_set<std::uint64_t> blockedEdges;
    int failedSinceCollapse = 0;

    while (needs_more_simplification(targetVertexCount, targetFaceCount)) {
      rebuild_topology_views();
      if (!needs_more_simplification(targetVertexCount, targetFaceCount))
        break;
      recompute_quadrics();

      Candidate candidate;
      if (!find_best_candidate(blockedEdges, candidate))
        break;

      if (!collapse_allowed(candidate)) {
        blockedEdges.insert(candidate.key);
        ++result.rejectedCandidates;
        if (++failedSinceCollapse >= options_.maxFailedCandidates)
          break;
        continue;
      }

      int keptVertex = -1;
      if (!collapse_candidate(candidate, keptVertex)) {
        blockedEdges.insert(candidate.key);
        ++result.failedCollapses;
        if (++failedSinceCollapse >= options_.maxFailedCandidates)
          break;
        continue;
      }

      ++result.collapsedEdges;
      failedSinceCollapse = 0;
      blockedEdges.clear();

      if (!dcel_.check_consistency(options_.verbose, true,
                                   options_.requireConsistentTwins, false)) {
        if (options_.verbose) {
          std::cerr << "[Directional::tri_flow_simplify_dcel]: "
                    << "DCEL became inconsistent after collapse; aborting\n";
        }
        break;
      }
    }

    rebuild_topology_views();

    if (options_.compactAfter) {
      if (!dcel_.clean_mesh(options_.verbose, false)) {
        if (options_.verbose) {
          std::cerr << "[Directional::tri_flow_simplify_dcel]: "
                    << "post-pass DCEL compaction failed\n";
        }
      } else {
        rebuild_topology_views();
      }
    }

    result.finalValidVertices = validVertexCount_;
    result.finalValidFaces = validFaceCount_;
    result.rootCount = rootCount_;
    result.success = dcel_.check_consistency(options_.verbose, true,
                                             options_.requireConsistentTwins,
                                             false);
    return result;
  }

private:
  struct Candidate {
    double cost = std::numeric_limits<double>::infinity();
    int halfedge = -1;
    int a = -1;
    int b = -1;
    std::uint64_t key = 0;
    Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  };

  FunctionDCEL &dcel_;
  TriFlowSimplificationDCELOptions options_;

  std::vector<unsigned char> validVertex_;
  std::vector<unsigned char> validFace_;
  std::vector<std::unordered_set<int>> vertexFaces_;
  std::vector<Eigen::RowVector3d> vertices_;
  std::vector<Eigen::Matrix4d> quadrics_;
  std::vector<int> rootLabel_;
  std::vector<Eigen::RowVector3d> rootTarget_;
  std::vector<unsigned char> initialBoundaryVertex_;
  std::unordered_set<std::uint64_t> initialBoundaryEdges_;
  std::unordered_set<std::uint64_t> protectedEdges_;
  Eigen::MatrixXd targets_;
  int validVertexCount_ = 0;
  int validFaceCount_ = 0;
  int rootCount_ = 0;
  bool hasNvf_ = false;

  bool valid_vertex(const int vertex) const {
    return vertex >= 0 && vertex < static_cast<int>(validVertex_.size()) &&
           validVertex_[static_cast<std::size_t>(vertex)] != 0;
  }

  bool valid_face(const int face) const {
    return face >= 0 && face < static_cast<int>(validFace_.size()) &&
           validFace_[static_cast<std::size_t>(face)] != 0;
  }

  bool valid_halfedge(const int halfedge) const {
    return dcel_.valid_halfedge(halfedge);
  }

  Eigen::RowVector3d vertex_position(const int vertex) const {
    return dcel_.vertices[static_cast<std::size_t>(vertex)].data.coords;
  }

  void set_vertex_position(const int vertex, const Eigen::RowVector3d &position) {
    auto &data = dcel_.vertices[static_cast<std::size_t>(vertex)].data;
    data.coords = position;
    if (options_.updateExactCoordinates)
      data.eCoords = triflow_dcel_exact_from_double(position);
  }

  bool collect_face_vertices(const int face, std::vector<int> &vertices) const {
    vertices.clear();
    std::vector<int> cycle;
    if (!dcel_.collect_face_cycle(face, cycle, options_.verbose))
      return false;
    vertices.reserve(cycle.size());
    for (const int halfedge : cycle) {
      const int vertex = dcel_.halfedges[static_cast<std::size_t>(halfedge)].vertex;
      if (!valid_vertex(vertex))
        return false;
      vertices.push_back(vertex);
    }
    return vertices.size() >= 3;
  }

  void rebuild_topology_views() {
    const int vertexCount = static_cast<int>(dcel_.vertices.size());
    const int faceCount = static_cast<int>(dcel_.faces.size());

    validVertex_.assign(static_cast<std::size_t>(vertexCount), 0);
    validFace_.assign(static_cast<std::size_t>(faceCount), 0);
    vertexFaces_.assign(static_cast<std::size_t>(vertexCount), {});
    vertices_.assign(static_cast<std::size_t>(vertexCount),
                     Eigen::RowVector3d::Zero());
    quadrics_.assign(static_cast<std::size_t>(vertexCount),
                     Eigen::Matrix4d::Zero());

    validVertexCount_ = 0;
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (!dcel_.valid_vertex(vertex))
        continue;
      validVertex_[static_cast<std::size_t>(vertex)] = 1;
      vertices_[static_cast<std::size_t>(vertex)] = vertex_position(vertex);
      ++validVertexCount_;
    }

    validFaceCount_ = 0;
    std::vector<int> faceVertices;
    for (int face = 0; face < faceCount; ++face) {
      if (!dcel_.valid_face(face))
        continue;
      if (!collect_face_vertices(face, faceVertices))
        continue;
      validFace_[static_cast<std::size_t>(face)] = 1;
      ++validFaceCount_;
      for (const int vertex : faceVertices)
        vertexFaces_[static_cast<std::size_t>(vertex)].insert(face);
    }
  }

  int resolve_target_vertex_count() const {
    if (options_.targetVertexCount >= 1)
      return std::max(1, std::min(options_.targetVertexCount, validVertexCount_));

    if (!std::isfinite(options_.targetVertexRatio) ||
        options_.targetVertexRatio <= 0.0 || options_.targetVertexRatio > 1.0) {
      throw std::runtime_error("targetVertexRatio must be in the range (0, 1].");
    }

    return std::max(1, static_cast<int>(std::ceil(
                           static_cast<double>(validVertexCount_) *
                           options_.targetVertexRatio)));
  }

  int resolve_target_face_count() const {
    if (options_.targetFaceCount >= 0)
      return std::max(0, std::min(options_.targetFaceCount, validFaceCount_));

    if (options_.targetFaceRatio > 0.0) {
      if (!std::isfinite(options_.targetFaceRatio) ||
          options_.targetFaceRatio > 1.0) {
        throw std::runtime_error("targetFaceRatio must be in the range (0, 1].");
      }
      return std::max(0, static_cast<int>(std::ceil(
                             static_cast<double>(validFaceCount_) *
                             options_.targetFaceRatio)));
    }

    return -1;
  }

  bool needs_more_simplification(const int targetVertexCount,
                                 const int targetFaceCount) const {
    if (validVertexCount_ > targetVertexCount)
      return true;
    if (targetFaceCount >= 0 && validFaceCount_ > targetFaceCount)
      return true;
    return false;
  }

  Eigen::RowVector3d bbox_min() const {
    Eigen::RowVector3d minCorner = Eigen::RowVector3d::Constant(
        std::numeric_limits<double>::infinity());
    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      if (!valid_vertex(vertex))
        continue;
      minCorner = minCorner.cwiseMin(vertices_[static_cast<std::size_t>(vertex)]);
    }
    return minCorner;
  }

  Eigen::RowVector3d bbox_max() const {
    Eigen::RowVector3d maxCorner = Eigen::RowVector3d::Constant(
        -std::numeric_limits<double>::infinity());
    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      if (!valid_vertex(vertex))
        continue;
      maxCorner = maxCorner.cwiseMax(vertices_[static_cast<std::size_t>(vertex)]);
    }
    return maxCorner;
  }

  void resolve_targets() {
    const Eigen::Index vertexCount = static_cast<Eigen::Index>(dcel_.vertices.size());

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
      targets_ = options_.prescribedRootTargets;
      hasNvf_ = true;
      return;
    }

    if (options_.vertexTargets.size() > 0) {
      validate_matrix_shape(options_.vertexTargets, vertexCount, 3,
                            "vertexTargets");
      targets_ = options_.vertexTargets;
      hasNvf_ = true;
      return;
    }

    if (options_.vertexNvf.size() > 0) {
      validate_matrix_shape(options_.vertexNvf, vertexCount, 3, "vertexNvf");
      targets_.resize(vertexCount, 3);
      for (Eigen::Index i = 0; i < vertexCount; ++i) {
        if (dcel_.valid_vertex(static_cast<int>(i)))
          targets_.row(i) = vertex_position(static_cast<int>(i)) +
                            options_.vertexNvf.row(i);
        else
          targets_.row(i).setZero();
      }
      hasNvf_ = true;
      return;
    }

    targets_.resize(0, 0);
    hasNvf_ = false;
  }

  void prepare_targets_and_roots() {
    rootLabel_.assign(dcel_.vertices.size(), -1);
    rootTarget_.clear();
    rootCount_ = 0;

    if (options_.prescribedRootLabels.size() > 0 ||
        options_.prescribedRootTargets.size() > 0) {
      for (int vertex = 0; vertex < static_cast<int>(dcel_.vertices.size());
           ++vertex) {
        if (!valid_vertex(vertex)) {
          continue;
        }
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
      return;
    }

    if (!hasNvf_) {
      std::fill(rootLabel_.begin(), rootLabel_.end(), 0);
      rootTarget_.push_back(Eigen::RowVector3d::Zero());
      rootCount_ = 1;
      return;
    }

    double threshold = options_.rootThreshold;
    if (threshold < 0.0) {
      const double diagonal = (bbox_max() - bbox_min()).norm();
      const int resolution = std::max(1, options_.voxelResolution);
      threshold = 0.5 * diagonal / static_cast<double>(resolution);
    }

    struct QueueItem {
      double cost = 0.0;
      int vertex = -1;
      int root = -1;
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
    int bestRoot = -1;
    double bestRootNorm = std::numeric_limits<double>::infinity();

    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      if (!valid_vertex(vertex))
        continue;
      const Eigen::RowVector3d displacement =
          targets_.row(vertex) - vertices_[static_cast<std::size_t>(vertex)];
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

    if (rootVertex.empty() && bestRoot >= 0) {
      rootVertex.push_back(bestRoot);
      queue.push(QueueItem{0.0, bestRoot, 0});
    }

    while (!queue.empty()) {
      const QueueItem item = queue.top();
      queue.pop();

      if (!valid_vertex(item.vertex) ||
          rootLabel_[static_cast<std::size_t>(item.vertex)] >= 0)
        continue;

      rootLabel_[static_cast<std::size_t>(item.vertex)] = item.root;
      const Eigen::RowVector3d rootTarget = targets_.row(rootVertex[item.root]);

      for (const int neighbor : vertex_neighbors(item.vertex)) {
        if (rootLabel_[static_cast<std::size_t>(neighbor)] >= 0)
          continue;
        const double cost = (targets_.row(neighbor) - rootTarget).norm();
        queue.push(QueueItem{cost, neighbor, item.root});
      }
    }

    for (int vertex = 0; vertex < static_cast<int>(vertices_.size()); ++vertex) {
      if (!valid_vertex(vertex) || rootLabel_[static_cast<std::size_t>(vertex)] >= 0)
        continue;

      int best = 0;
      double bestCost = std::numeric_limits<double>::infinity();
      for (int root = 0; root < static_cast<int>(rootVertex.size()); ++root) {
        const double cost =
            (targets_.row(vertex) - targets_.row(rootVertex[root])).norm();
        if (cost < bestCost) {
          bestCost = cost;
          best = root;
        }
      }
      rootLabel_[static_cast<std::size_t>(vertex)] = best;
    }

    rootTarget_.resize(rootVertex.size());
    for (int root = 0; root < static_cast<int>(rootVertex.size()); ++root)
      rootTarget_[static_cast<std::size_t>(root)] = targets_.row(rootVertex[root]);

    rootCount_ = static_cast<int>(rootTarget_.size());
  }

  void compute_initial_boundary_state() {
    initialBoundaryVertex_.assign(dcel_.vertices.size(), 0);
    initialBoundaryEdges_.clear();

    for (int he = 0; he < static_cast<int>(dcel_.halfedges.size()); ++he) {
      if (!valid_halfedge(he))
        continue;
      if (dcel_.halfedges[static_cast<std::size_t>(he)].twin >= 0)
        continue;

      const int a = dcel_.halfedges[static_cast<std::size_t>(he)].vertex;
      const int next = dcel_.halfedges[static_cast<std::size_t>(he)].next;
      if (!valid_halfedge(next))
        continue;
      const int b = dcel_.halfedges[static_cast<std::size_t>(next)].vertex;
      if (!valid_vertex(a) || !valid_vertex(b))
        continue;

      initialBoundaryVertex_[static_cast<std::size_t>(a)] = 1;
      initialBoundaryVertex_[static_cast<std::size_t>(b)] = 1;
      initialBoundaryEdges_.insert(edge_key(a, b));
    }
  }

  void recompute_quadrics() {
    std::fill(quadrics_.begin(), quadrics_.end(), Eigen::Matrix4d::Zero());

    std::vector<int> faceVertices;
    for (int face = 0; face < static_cast<int>(dcel_.faces.size()); ++face) {
      if (!valid_face(face) || !collect_face_vertices(face, faceVertices))
        continue;

      const int anchor = faceVertices.front();
      for (int i = 1; i + 1 < static_cast<int>(faceVertices.size()); ++i) {
        const Eigen::Matrix4d quadric = plane_quadric(
            vertices_[static_cast<std::size_t>(anchor)],
            vertices_[static_cast<std::size_t>(faceVertices[i])],
            vertices_[static_cast<std::size_t>(faceVertices[i + 1])]);
        for (const int vertex : faceVertices)
          quadrics_[static_cast<std::size_t>(vertex)] += quadric;
      }
    }
  }

  std::set<int> vertex_neighbors(const int vertex) const {
    std::set<int> neighbors;
    if (!valid_vertex(vertex))
      return neighbors;

    for (int he = 0; he < static_cast<int>(dcel_.halfedges.size()); ++he) {
      if (!valid_halfedge(he))
        continue;
      const int next = dcel_.halfedges[static_cast<std::size_t>(he)].next;
      if (!valid_halfedge(next))
        continue;
      const int a = dcel_.halfedges[static_cast<std::size_t>(he)].vertex;
      const int b = dcel_.halfedges[static_cast<std::size_t>(next)].vertex;
      if (!valid_vertex(a) || !valid_vertex(b) || a == b)
        continue;
      if (a == vertex)
        neighbors.insert(b);
      if (b == vertex)
        neighbors.insert(a);
    }

    return neighbors;
  }

  std::vector<int> edge_halfedges(const int a, const int b) const {
    std::vector<int> result;
    for (int he = 0; he < static_cast<int>(dcel_.halfedges.size()); ++he) {
      if (!valid_halfedge(he))
        continue;
      const int next = dcel_.halfedges[static_cast<std::size_t>(he)].next;
      if (!valid_halfedge(next))
        continue;
      const int source = dcel_.halfedges[static_cast<std::size_t>(he)].vertex;
      const int target = dcel_.halfedges[static_cast<std::size_t>(next)].vertex;
      if ((source == a && target == b) || (source == b && target == a))
        result.push_back(he);
    }
    return result;
  }

  bool edge_faces(const int a, const int b, std::set<int> &faces) const {
    faces.clear();
    for (const int he : edge_halfedges(a, b)) {
      const int face = dcel_.halfedges[static_cast<std::size_t>(he)].face;
      if (valid_face(face))
        faces.insert(face);
    }
    return !faces.empty();
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

  bool halfedge_is_protected(const int he) const {
    if (!valid_halfedge(he))
      return false;
    const auto &halfedge = dcel_.halfedges[static_cast<std::size_t>(he)];
    if (options_.preserveFunctionEdges && halfedge.data.isFunction)
      return true;
    if (options_.preserveOriginalBoundaryEdges && halfedge.data.origHalfedge >= 0)
      return true;
    return false;
  }

  bool edge_is_protected(const int a, const int b) const {
    if (protectedEdges_.contains(edge_key(a, b)))
      return true;
    for (const int he : edge_halfedges(a, b)) {
      if (halfedge_is_protected(he))
        return true;
      const int twin = dcel_.halfedges[static_cast<std::size_t>(he)].twin;
      if (valid_halfedge(twin) && halfedge_is_protected(twin))
        return true;
    }
    return false;
  }

  bool boundary_ok(const int a, const int b) const {
    if (!options_.preserveBoundary)
      return true;
    const bool boundaryA = initialBoundaryVertex_[static_cast<std::size_t>(a)] != 0;
    const bool boundaryB = initialBoundaryVertex_[static_cast<std::size_t>(b)] != 0;
    if (boundaryA != boundaryB)
      return false;
    if (boundaryA && boundaryB && !initialBoundaryEdges_.contains(edge_key(a, b)))
      return false;
    return true;
  }

  bool make_candidate(const int he, Candidate &candidate) const {
    if (!valid_halfedge(he))
      return false;

    const int next = dcel_.halfedges[static_cast<std::size_t>(he)].next;
    if (!valid_halfedge(next))
      return false;

    int a = dcel_.halfedges[static_cast<std::size_t>(he)].vertex;
    int b = dcel_.halfedges[static_cast<std::size_t>(next)].vertex;

    if (!valid_vertex(a) || !valid_vertex(b) || a == b)
      return false;

    if (a > b)
      std::swap(a, b);

    const std::uint64_t key = edge_key(a, b);

    if (!roots_compatible(a, b) || !boundary_ok(a, b) ||
        edge_is_protected(a, b))
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

    candidate.halfedge = he;
    candidate.a = a;
    candidate.b = b;
    candidate.key = key;
    candidate.position = best_quadric_position(quadric, fallbacks);
    candidate.cost = quadric_error(quadric, candidate.position);
    return std::isfinite(candidate.cost) && candidate.position.allFinite();
  }

  bool find_best_candidate(const std::unordered_set<std::uint64_t> &blockedEdges,
                           Candidate &best) const {
    best = Candidate{};
    std::unordered_set<std::uint64_t> seen;

    for (int he = 0; he < static_cast<int>(dcel_.halfedges.size()); ++he) {
      Candidate candidate;
      if (!make_candidate(he, candidate))
        continue;
      if (!seen.insert(candidate.key).second)
        continue;
      if (blockedEdges.contains(candidate.key))
        continue;
      if (candidate.cost < best.cost ||
          (candidate.cost == best.cost && candidate.key < best.key)) {
        best = candidate;
      }
    }

    return best.halfedge >= 0;
  }

  bool replacement_faces_ok(const int keep, const int drop) const {
    std::set<int> incidentEdgeFaces;
    edge_faces(keep, drop, incidentEdgeFaces);
    if (incidentEdgeFaces.empty() || incidentEdgeFaces.size() > 2)
      return false;

    int removedFaceCount = 0;
    std::vector<int> edgeFaceVertices;
    for (const int face : incidentEdgeFaces) {
      if (!collect_face_vertices(face, edgeFaceVertices))
        return false;
      if (edgeFaceVertices.size() <= 3)
        ++removedFaceCount;
    }
    if (validFaceCount_ - removedFaceCount <= 0)
      return false;

    std::vector<int> faceVertices;
    for (const int face : vertexFaces_[static_cast<std::size_t>(drop)]) {
      if (!valid_face(face) || !collect_face_vertices(face, faceVertices))
        return false;

      int keepCount = 0;
      int dropCount = 0;
      for (const int vertex : faceVertices) {
        keepCount += vertex == keep ? 1 : 0;
        dropCount += vertex == drop ? 1 : 0;
      }

      if (dropCount != 1 || keepCount > 1)
        return false;

      if (keepCount == 1) {
        if (!incidentEdgeFaces.contains(face))
          return false;
        if (faceVertices.size() > 3 && faceVertices.size() - 1 < 3)
          return false;
      }
    }

    return true;
  }

  bool link_condition_ok(const int keep, const int drop) const {
    std::set<int> expectedCommonNeighbors;

    const std::vector<int> edgeHalfedges = edge_halfedges(keep, drop);
    if (edgeHalfedges.empty() || edgeHalfedges.size() > 2)
      return false;

    for (const int he : edgeHalfedges) {
      const int prev = dcel_.halfedges[static_cast<std::size_t>(he)].prev;
      const int next = dcel_.halfedges[static_cast<std::size_t>(he)].next;
      if (!valid_halfedge(prev) || !valid_halfedge(next))
        return false;
      const int nextNext = dcel_.halfedges[static_cast<std::size_t>(next)].next;
      if (!valid_halfedge(nextNext))
        return false;

      const int before = dcel_.halfedges[static_cast<std::size_t>(prev)].vertex;
      const int after = dcel_.halfedges[static_cast<std::size_t>(nextNext)].vertex;
      if (valid_vertex(before) && before != keep && before != drop)
        expectedCommonNeighbors.insert(before);
      if (valid_vertex(after) && after != keep && after != drop)
        expectedCommonNeighbors.insert(after);
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

  static Eigen::RowVector3d polygon_normal(
      const std::vector<Eigen::RowVector3d> &points) {
    Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
    if (points.size() < 3)
      return normal;

    const Eigen::RowVector3d anchor = points.front();
    for (int i = 1; i + 1 < static_cast<int>(points.size()); ++i)
      normal += (points[static_cast<std::size_t>(i)] - anchor)
                    .cross(points[static_cast<std::size_t>(i + 1)] - anchor);
    return normal;
  }

  bool face_flips_ok(const int keep, const int drop,
                     const Eigen::RowVector3d &newPosition) const {
    if (!options_.rejectFaceFlips)
      return true;

    std::vector<int> faceVertices;
    for (const int face : vertexFaces_[static_cast<std::size_t>(drop)]) {
      if (!valid_face(face) || !collect_face_vertices(face, faceVertices))
        return false;

      bool containsKeep = false;
      for (const int vertex : faceVertices)
        containsKeep = containsKeep || vertex == keep;
      if (containsKeep)
        continue;

      std::vector<Eigen::RowVector3d> before;
      std::vector<Eigen::RowVector3d> after;
      before.reserve(faceVertices.size());
      after.reserve(faceVertices.size());
      for (const int vertex : faceVertices) {
        before.push_back(vertices_[static_cast<std::size_t>(vertex)]);
        after.push_back(vertex == drop
                            ? newPosition
                            : vertices_[static_cast<std::size_t>(vertex)]);
      }

      const Eigen::RowVector3d normalBefore = polygon_normal(before);
      const Eigen::RowVector3d normalAfter = polygon_normal(after);
      const double beforeNorm = normalBefore.norm();
      const double afterNorm = normalAfter.norm();
      if (beforeNorm <= 1e-15 || afterNorm <= 1e-15)
        return false;
      if (normalBefore.dot(normalAfter) <= 0.0)
        return false;
    }

    return true;
  }

  bool collapse_allowed(const Candidate &candidate) const {
    if (!valid_vertex(candidate.a) || !valid_vertex(candidate.b))
      return false;

    const int keep = choose_keep_vertex(candidate.a, candidate.b,
                                        candidate.position);
    const int drop = keep == candidate.a ? candidate.b : candidate.a;

    if (!roots_compatible(keep, drop) || !boundary_ok(keep, drop) ||
        edge_is_protected(keep, drop))
      return false;
    if (!replacement_faces_ok(keep, drop))
      return false;
    if (!link_condition_ok(keep, drop))
      return false;
    return face_flips_ok(keep, drop, candidate.position);
  }

  int choose_keep_vertex(const int a, const int b,
                         const Eigen::RowVector3d &position) const {
    const bool boundaryA = options_.preserveBoundary &&
                           initialBoundaryVertex_[static_cast<std::size_t>(a)] != 0;
    const bool boundaryB = options_.preserveBoundary &&
                           initialBoundaryVertex_[static_cast<std::size_t>(b)] != 0;
    if (boundaryA != boundaryB)
      return boundaryA ? a : b;

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

    (void)position;
    return a;
  }

  bool remove_degenerate_edges_after_collapse() {
    bool removedAny = true;
    int guard = 0;
    const int maxSteps = std::max(1, static_cast<int>(dcel_.halfedges.size()) * 4);

    while (removedAny) {
      if (++guard > maxSteps)
        return false;

      removedAny = false;
      for (int he = 0; he < static_cast<int>(dcel_.halfedges.size()); ++he) {
        if (!dcel_.valid_halfedge(he))
          continue;
        const int next = dcel_.halfedges[static_cast<std::size_t>(he)].next;
        if (!dcel_.valid_halfedge(next))
          return false;
        if (dcel_.halfedges[static_cast<std::size_t>(he)].vertex !=
            dcel_.halfedges[static_cast<std::size_t>(next)].vertex)
          continue;
        if (!dcel_.remove_degenerate_edge(he, options_.verbose))
          return false;
        removedAny = true;
        break;
      }
    }

    return true;
  }

  bool collapse_candidate(const Candidate &candidate, int &keptVertex) {
    keptVertex = -1;
    const int keep = choose_keep_vertex(candidate.a, candidate.b,
                                        candidate.position);
    const int drop = keep == candidate.a ? candidate.b : candidate.a;

    if (!collapse_allowed(candidate))
      return false;

    const auto oldVertices = dcel_.vertices;
    const auto oldHalfedges = dcel_.halfedges;
    const auto oldEdges = dcel_.edges;
    const auto oldFaces = dcel_.faces;
    const std::vector<int> oldRootLabel = rootLabel_;

    const auto rollback = [&]() {
      dcel_.vertices = oldVertices;
      dcel_.halfedges = oldHalfedges;
      dcel_.edges = oldEdges;
      dcel_.faces = oldFaces;
      rootLabel_ = oldRootLabel;
    };

    set_vertex_position(keep, candidate.position);

    if (hasNvf_ && rootLabel_[static_cast<std::size_t>(keep)] !=
                       rootLabel_[static_cast<std::size_t>(drop)]) {
      const int rootKeep = rootLabel_[static_cast<std::size_t>(keep)];
      const int rootDrop = rootLabel_[static_cast<std::size_t>(drop)];
      if (rootKeep < 0 ||
          (rootDrop >= 0 && rootDrop < static_cast<int>(rootTarget_.size()) &&
           rootKeep < static_cast<int>(rootTarget_.size()) &&
           (candidate.position - rootTarget_[static_cast<std::size_t>(rootDrop)])
                   .squaredNorm() <
               (candidate.position -
                rootTarget_[static_cast<std::size_t>(rootKeep)])
                   .squaredNorm())) {
        rootLabel_[static_cast<std::size_t>(keep)] = rootDrop;
      }
    }

    for (auto &halfedge : dcel_.halfedges) {
      if (halfedge.valid && halfedge.vertex == drop)
        halfedge.vertex = keep;
    }

    dcel_.vertices[static_cast<std::size_t>(drop)].valid = false;
    dcel_.vertices[static_cast<std::size_t>(drop)].halfedge = -1;

    if (!remove_degenerate_edges_after_collapse()) {
      rollback();
      return false;
    }

    if (!dcel_.rebuild_representative_halfedges(options_.verbose, true)) {
      rollback();
      return false;
    }

    if (options_.validateAfterEachCollapse &&
        !dcel_.check_consistency(options_.verbose, true,
                                 options_.requireConsistentTwins, false)) {
      rollback();
      return false;
    }

    keptVertex = keep;
    return true;
  }
};

} // namespace detail

template <typename FunctionDCEL>
using TriFlowSimplificationDCEL = detail::TriFlowDCELSimplifier<FunctionDCEL>;

/* Backward-compatible alias for the common DECL typo in early task notes. */
template <typename FunctionDCEL>
using TriFlowSimplificationDECL = detail::TriFlowDCELSimplifier<FunctionDCEL>;

template <typename FunctionDCEL>
inline TriFlowSimplificationDCELResult
tri_flow_simplify_dcel(FunctionDCEL &dcel,
                       const TriFlowSimplificationDCELOptions &options = {}) {
  detail::TriFlowDCELSimplifier<FunctionDCEL> simplifier(dcel, options);
  return simplifier.run();
}

template <typename FunctionDCEL>
inline TriFlowSimplificationDCELResult
tri_flow_simplify_decl(FunctionDCEL &dcel,
                       const TriFlowSimplificationDCELOptions &options = {}) {
  return tri_flow_simplify_dcel(dcel, options);
}

} // namespace directional

#endif // DIRECTIONAL_MESHING_TRI_FLOW_SIMPLIFICATION_DCEL_H
