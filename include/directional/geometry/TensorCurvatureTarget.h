// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_TENSOR_CURVATURE_TARGET_H
#define DIRECTIONAL_GEOMETRY_TENSOR_CURVATURE_TARGET_H

#include <cmath>
#include <complex>
#include <limits>
#include <stdexcept>

#include <Eigen/Core>

#include <directional/geometry/FaceCurvature.h>

namespace directional {

/**
 * @brief Degree-4 curvature-alignment target derived directly from a
 *        symmetric 2x2 shape operator.
 */
struct TensorCurvatureTarget {
  /// Unit complex degree-4 target. Valid for 4-RoSy/cross-field alignment.
  std::complex<double> q4 = {1.0, 0.0};

  /// Eigenvalue gap of the shape operator.
  double anisotropy = 0.0;

  /// Sum of absolute principal curvatures.
  double magnitude = 0.0;

  /// False when the tensor is non-finite or nearly isotropic.
  bool valid = false;
};

/**
 * @brief Converts a symmetric 2x2 shape operator into a degree-4 target.
 *
 * The directional information of a symmetric tensor is stored in its traceless
 * deviatoric part. If S = [a b; b c], the complex number
 *   t2 = (a - c) + i 2b
 * stores twice the principal angle. Squaring its unit representative gives the
 * degree-4 cross-field target without choosing an eigenvector branch.
 */
TensorCurvatureTarget tensor_curvature_target(
    const Eigen::Matrix2d &shapeOperator,
    const double epsilon = 1e-14);

/**
 * @brief Restricts an ambient symmetric tensor to a face tangent basis.
 */
Eigen::Matrix2d restrict_tensor_to_basis(
    const Eigen::Matrix3d &ambientTensor, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);

/**
 * @brief Lifts a face-basis tensor to ambient 3D coordinates.
 */
Eigen::Matrix3d lift_tensor_to_ambient(
    const Eigen::Matrix2d &shapeOperator, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);

/**
 * @brief Transports a face shape operator between tangent planes using the
 *        minimal normal-to-normal rotation, then restricts it to the target
 *        tangent basis.
 */
Eigen::Matrix2d transport_shape_operator_between_faces(
    const Eigen::Matrix2d &sourceShapeOperator,
    const Eigen::Vector3d &sourceBasisX, const Eigen::Vector3d &sourceBasisY,
    const Eigen::Vector3d &sourceNormal, const Eigen::Vector3d &targetBasisX,
    const Eigen::Vector3d &targetBasisY,
    const Eigen::Vector3d &targetNormal);

/**
 * @brief Picks one representative direction from a degree-4 target in a face
 *        basis. The branch is arbitrary and should only be used for diagnostics.
 */
Eigen::Vector3d representative_direction_from_q4(
    const std::complex<double> &q4, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_TENSOR_CURVATURE_TARGET_H
