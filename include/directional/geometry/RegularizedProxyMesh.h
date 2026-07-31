// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_REGULARIZED_PROXY_MESH_H
#define DIRECTIONAL_GEOMETRY_REGULARIZED_PROXY_MESH_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

namespace directional {

/**
 * @brief Options for a same-topology, fidelity-preserving regularized proxy.
 */
struct RegularizedProxyMeshOptions {
  /// Positional fidelity coefficient.
  double fidelityWeight = 1.0;

  /// Scale-normalized biharmonic regularization coefficient.
  double smoothnessWeight = 1e-2;

  /// Keep all boundary vertices fixed at their input positions.
  bool preserveBoundary = true;

  /// Keep vertices incident to sharp dihedral edges fixed.
  bool preserveSharpFeatures = true;

  /// Dihedral threshold in degrees used when preserveSharpFeatures is enabled.
  double sharpFeatureAngleDegrees = 60.0;

  /// Clamp negative cotangent edge weights to zero for a robust SPD system.
  bool clampNegativeCotangents = true;

  /// Additional caller-provided fixed vertex ids.
  Eigen::VectorXi fixedVertices;
};

/**
 * @brief Output and diagnostics from proxy-mesh regularization.
 */
struct RegularizedProxyMeshResult {
  Eigen::MatrixXd vertices;
  Eigen::VectorXd displacement;
  Eigen::VectorXi fixedMask;
  double averageEdgeLength = 0.0;
};

namespace regularized_proxy_detail {

double cotangent(const Eigen::Vector3d &first,
                        const Eigen::Vector3d &second);

double average_unique_edge_length(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &edges);

void validate_proxy_inputs(const Eigen::MatrixXd &vertices,
                                  const Eigen::MatrixXi &faces,
                                  const Eigen::MatrixXi &edges,
                                  const Eigen::VectorXi &boundaryVertices,
                                  const RegularizedProxyMeshOptions &options);

} // namespace regularized_proxy_detail

/**
 * @brief Builds a fidelity-preserving, same-topology regularized mesh.
 *
 * Solves
 *   min_X lambda_f ||X - V||_M^2
 *       + lambda_s h^4 ||L X||_{M^-1}^2,
 * where L is a cotangent stiffness matrix, M is lumped vertex area, and h is
 * average edge length. Boundary and caller-selected vertices can be eliminated
 * as exact positional constraints.
 */
RegularizedProxyMeshResult regularize_proxy_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXi &edges, const Eigen::VectorXi &boundaryVertices,
    const RegularizedProxyMeshOptions &options = {});

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_REGULARIZED_PROXY_MESH_H
