// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_SHAPE_OPERATOR_ALIGNMENT_H
#define DIRECTIONAL_FIELDS_SHAPE_OPERATOR_ALIGNMENT_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <numbers>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Dense>

#include <directional/core/TriMesh.h>
#include <directional/geometry/FaceCurvature.h>
#include <directional/geometry/RegularizedProxyMesh.h>

namespace directional::fields {

/**
 * @brief Options for evaluating how well a cross field diagonalizes a mesh's
 *        regularized per-face shape operators.
 */
struct ShapeOperatorAlignmentOptions {
  /// If true, first builds the same-topology regularized proxy before curvature.
  bool useRegularizedProxy = true;

  /// Proxy options used when useRegularizedProxy is true.
  RegularizedProxyMeshOptions proxy;

  /// Face-curvature options used on the proxy or original mesh.
  FaceCurvatureOptions curvature;

  /// Ignore faces with lower curvature confidence.
  double minimumConfidence = 1e-3;

  /// Confidence exponent used for weighted summaries.
  double confidenceExponent = 2.0;
};

/**
 * @brief Per-face shape-operator alignment diagnostics for one cross field.
 */
struct ShapeOperatorAlignmentResult {
  Eigen::VectorXd angleDegrees;
  Eigen::VectorXd normalizedEnergy;
  Eigen::VectorXd confidence;
  Eigen::VectorXd weights;
  Eigen::VectorXi valid;
  Eigen::VectorXd anisotropy;
  Eigen::MatrixXd proxyVertices;
  Eigen::VectorXd proxyDisplacement;
  FaceCurvatureResult curvature;
  Eigen::Index validFaceCount = 0;
  double validAreaFraction = 0.0;
  double weightedMeanEnergy = 0.0;
};

namespace shape_operator_alignment_detail {

inline constexpr double pi = std::numbers::pi_v<double>;

Eigen::RowVector3d normalized_row(const Eigen::RowVector3d &value);

Eigen::Vector3d normalized_vector(const Eigen::Vector3d &value);

void validate_field(const Eigen::MatrixXd &field,
                           const Eigen::Index faceCount);

Eigen::Vector3d field_axis(const Eigen::MatrixXd &field,
                                  const Eigen::Index face,
                                  const int axis);

Eigen::Vector3d transport_axis_to_proxy(
    const Eigen::Vector3d &axis, const Eigen::Vector3d &originalNormal,
    const Eigen::Vector3d &proxyNormal);

Eigen::Vector2d coordinates_in_basis(
    const Eigen::Vector3d &axis, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);

double anisotropy_from_shape_operator(const Eigen::Matrix2d &shape);

double normalized_offdiagonal_ratio(const Eigen::Matrix2d &shape,
                                           const Eigen::Vector2d &axisA,
                                           const Eigen::Vector2d &axisB,
                                           const double anisotropy);

Eigen::Vector3d orthogonalized_second_axis(const Eigen::Vector3d &axisA,
                                                  const Eigen::Vector3d &axisB,
                                                  const Eigen::Vector3d &normal);

void ensure_valid_options(const ShapeOperatorAlignmentOptions &options);

} // namespace shape_operator_alignment_detail

/**
 * @brief Evaluates the NeurCross-style shape-operator criterion for one field.
 *
 * A cross is perfectly shape-aligned when its two axes diagonalize the local
 * shape operator, equivalently when the mixed term a^T S b is zero. The stored
 * normalized energy is (2 |a^T S b| / |k_max-k_min|)^2; it is 0 for perfect
 * alignment and approaches 1 at a 45-degree line-field mismatch.
 */
ShapeOperatorAlignmentResult evaluate_shape_operator_alignment(
    const TriMesh &mesh, const Eigen::MatrixXd &field,
    const ShapeOperatorAlignmentOptions &options = {});

ShapeOperatorAlignmentResult evaluate_shape_operator_alignment(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &field,
    const ShapeOperatorAlignmentOptions &options = {});

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_SHAPE_OPERATOR_ALIGNMENT_H
