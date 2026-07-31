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

std::uint64_t edge_key(const int a, const int b);

Eigen::Matrix4d plane_quadric(const Eigen::RowVector3d &a,
                                     const Eigen::RowVector3d &b,
                                     const Eigen::RowVector3d &c);

Eigen::Matrix4d point_quadric(const Eigen::RowVector3d &point);

double quadric_error(const Eigen::Matrix4d &quadric,
                            const Eigen::RowVector3d &point);

Eigen::RowVector3d best_quadric_position(
    const Eigen::Matrix4d &quadric,
    const std::vector<Eigen::RowVector3d> &fallbacks);

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


} // namespace detail

TriFlowSimplificationResult
tri_flow_simplify(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                  const TriFlowSimplificationOptions &options = {});

} // namespace directional

#endif
