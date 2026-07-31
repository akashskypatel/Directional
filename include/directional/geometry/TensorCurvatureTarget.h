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
#if defined(DIRECTIONAL_TENSOR_CURVATURE_TARGET_IMPLEMENTATION)
TensorCurvatureTarget tensor_curvature_target(
    const Eigen::Matrix2d &shapeOperator,
    const double epsilon = 1e-14) {
  TensorCurvatureTarget result;
  if (!shapeOperator.array().isFinite().all()) {
    return result;
  }

  const Eigen::Matrix2d symmetric =
      0.5 * (shapeOperator + shapeOperator.transpose());
  const double a = symmetric(0, 0);
  const double b = symmetric(0, 1);
  const double c = symmetric(1, 1);

  const std::complex<double> t2(a - c, 2.0 * b);
  const double deviatorNorm = std::abs(t2);
  if (!(deviatorNorm > epsilon) || !std::isfinite(deviatorNorm)) {
    return result;
  }

  const double trace = a + c;
  const double halfTrace = 0.5 * trace;
  const double k0 = halfTrace - 0.5 * deviatorNorm;
  const double k1 = halfTrace + 0.5 * deviatorNorm;

  const std::complex<double> unit = t2 / deviatorNorm;
  result.q4 = unit * unit;
  result.anisotropy = deviatorNorm;
  result.magnitude = std::abs(k0) + std::abs(k1);
  result.valid = result.q4.real() == result.q4.real() &&
                 result.q4.imag() == result.q4.imag();
  return result;
}
#else
TensorCurvatureTarget tensor_curvature_target(
    const Eigen::Matrix2d &shapeOperator,
    const double epsilon = 1e-14);
#endif

/**
 * @brief Restricts an ambient symmetric tensor to a face tangent basis.
 */
#if defined(DIRECTIONAL_TENSOR_CURVATURE_TARGET_IMPLEMENTATION)
Eigen::Matrix2d restrict_tensor_to_basis(
    const Eigen::Matrix3d &ambientTensor, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = basisX;
  basis.col(1) = basisY;
  return basis.transpose() * ambientTensor * basis;
}
#else
Eigen::Matrix2d restrict_tensor_to_basis(
    const Eigen::Matrix3d &ambientTensor, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);
#endif

/**
 * @brief Lifts a face-basis tensor to ambient 3D coordinates.
 */
#if defined(DIRECTIONAL_TENSOR_CURVATURE_TARGET_IMPLEMENTATION)
Eigen::Matrix3d lift_tensor_to_ambient(
    const Eigen::Matrix2d &shapeOperator, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = basisX;
  basis.col(1) = basisY;
  return basis * shapeOperator * basis.transpose();
}
#else
Eigen::Matrix3d lift_tensor_to_ambient(
    const Eigen::Matrix2d &shapeOperator, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);
#endif

/**
 * @brief Transports a face shape operator between tangent planes using the
 *        minimal normal-to-normal rotation, then restricts it to the target
 *        tangent basis.
 */
#if defined(DIRECTIONAL_TENSOR_CURVATURE_TARGET_IMPLEMENTATION)
Eigen::Matrix2d transport_shape_operator_between_faces(
    const Eigen::Matrix2d &sourceShapeOperator,
    const Eigen::Vector3d &sourceBasisX, const Eigen::Vector3d &sourceBasisY,
    const Eigen::Vector3d &sourceNormal, const Eigen::Vector3d &targetBasisX,
    const Eigen::Vector3d &targetBasisY,
    const Eigen::Vector3d &targetNormal) {
  const Eigen::Matrix3d rotation =
      transport_rotation_between_normals(sourceNormal, targetNormal);
  const Eigen::Matrix3d sourceAmbient = lift_tensor_to_ambient(
      sourceShapeOperator, sourceBasisX, sourceBasisY);
  const Eigen::Matrix3d transportedAmbient =
      rotation * sourceAmbient * rotation.transpose();
  return restrict_tensor_to_basis(transportedAmbient, targetBasisX,
                                  targetBasisY);
}
#else
Eigen::Matrix2d transport_shape_operator_between_faces(
    const Eigen::Matrix2d &sourceShapeOperator,
    const Eigen::Vector3d &sourceBasisX, const Eigen::Vector3d &sourceBasisY,
    const Eigen::Vector3d &sourceNormal, const Eigen::Vector3d &targetBasisX,
    const Eigen::Vector3d &targetBasisY,
    const Eigen::Vector3d &targetNormal);
#endif

/**
 * @brief Picks one representative direction from a degree-4 target in a face
 *        basis. The branch is arbitrary and should only be used for diagnostics.
 */
#if defined(DIRECTIONAL_TENSOR_CURVATURE_TARGET_IMPLEMENTATION)
Eigen::Vector3d representative_direction_from_q4(
    const std::complex<double> &q4, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  const double angle = 0.25 * std::atan2(q4.imag(), q4.real());
  Eigen::Vector3d direction = std::cos(angle) * basisX +
                              std::sin(angle) * basisY;
  const double norm = direction.norm();
  if (!(norm > 1e-14) || !direction.array().isFinite().all()) {
    return Eigen::Vector3d::Zero();
  }
  return direction / norm;
}
#else
Eigen::Vector3d representative_direction_from_q4(
    const std::complex<double> &q4, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY);
#endif

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_TENSOR_CURVATURE_TARGET_H
