// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_FACE_CURVATURE_H
#define DIRECTIONAL_GEOMETRY_FACE_CURVATURE_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <numbers>
#include <stdexcept>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include <Eigen/SVD>

namespace directional {

/**
 * @brief Configuration for face-based curvature estimation.
 */
struct FaceCurvatureOptions {
  /// Number of transport-aware one-ring tensor smoothing passes.
  int smoothingIterations = 1;

  /// Prevent tensor smoothing across edges whose dihedral exceeds this angle.
  bool preserveSharpFeatures = true;

  /// Dihedral threshold in degrees used when preserveSharpFeatures is enabled.
  double sharpFeatureAngleDegrees = 60.0;

  /// Reject triangles whose area is smaller than this fraction of h^2.
  double minimumRelativeArea = 1e-12;

  /// Reject least-squares systems with sigma_min / sigma_max below this value.
  double minimumSingularValueRatio = 1e-10;

  /// Curvature magnitude gate kappa_0 = magnitudeGateScale / averageEdgeLength.
  double magnitudeGateScale = 0.05;

  /// Exponential decay applied to the relative least-squares residual.
  double residualDecay = 4.0;
};

/**
 * @brief Face-based shape operators, principal curvatures, directions, and
 *        reliability diagnostics.
 */
struct FaceCurvatureResult {
  /// Per-face 2x2 shape operator in the supplied face basis.
  std::vector<Eigen::Matrix2d> shapeOperators;

  /// Principal direction for the smaller algebraic curvature.
  Eigen::MatrixXd principalDirectionsMin;

  /// Principal direction for the larger algebraic curvature.
  Eigen::MatrixXd principalDirectionsMax;

  /// Algebraically ordered signed curvatures [k_min, k_max].
  Eigen::MatrixXd principalCurvatures;

  /// Relative least-squares residual for each face.
  Eigen::VectorXd fitResiduals;

  /// Fit/conditioning quality independent of curvature anisotropy.
  Eigen::VectorXd fitQuality;

  /// Scale-independent directional confidence in [0, 1].
  Eigen::VectorXd confidence;

  /// One for valid faces and zero for rejected/failed faces.
  Eigen::VectorXi valid;
};

namespace face_curvature_detail {

inline double clamp_unit(const double value) {
  return std::max(-1.0, std::min(1.0, value));
}

inline bool finite_vector(const Eigen::Vector3d &value) {
  return value.array().isFinite().all();
}

inline bool finite_matrix(const Eigen::Matrix2d &value) {
  return value.array().isFinite().all();
}

inline Eigen::Matrix3d normal_transport_rotation(
    const Eigen::Vector3d &sourceNormal,
    const Eigen::Vector3d &targetNormal) {
  constexpr double epsilon = 1e-14;

  if (!finite_vector(sourceNormal) || !finite_vector(targetNormal) ||
      sourceNormal.squaredNorm() <= epsilon ||
      targetNormal.squaredNorm() <= epsilon) {
    throw std::invalid_argument(
        "normal_transport_rotation requires finite non-zero normals.");
  }

  const Eigen::Vector3d source = sourceNormal.normalized();
  const Eigen::Vector3d target = targetNormal.normalized();
  const double cosine = clamp_unit(source.dot(target));

  if (cosine >= 1.0 - epsilon) {
    return Eigen::Matrix3d::Identity();
  }

  if (cosine <= -1.0 + epsilon) {
    Eigen::Vector3d axis = source.unitOrthogonal();
    axis.normalize();
    return Eigen::AngleAxisd(std::numbers::pi, axis).toRotationMatrix();
  }

  Eigen::Vector3d axis = source.cross(target);
  const double sine = axis.norm();
  axis /= sine;
  return Eigen::AngleAxisd(std::atan2(sine, cosine), axis)
      .toRotationMatrix();
}

inline Eigen::Matrix3d ambient_tensor(const Eigen::Matrix2d &shapeOperator,
                                      const Eigen::Vector3d &basisX,
                                      const Eigen::Vector3d &basisY) {
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = basisX;
  basis.col(1) = basisY;
  return basis * shapeOperator * basis.transpose();
}

inline Eigen::Matrix2d restrict_tensor(const Eigen::Matrix3d &ambient,
                                       const Eigen::Vector3d &basisX,
                                       const Eigen::Vector3d &basisY) {
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = basisX;
  basis.col(1) = basisY;
  return basis.transpose() * ambient * basis;
}

inline Eigen::Matrix2d transport_tensor(
    const Eigen::Matrix2d &shapeOperator,
    const Eigen::Vector3d &sourceBasisX,
    const Eigen::Vector3d &sourceBasisY,
    const Eigen::Vector3d &sourceNormal,
    const Eigen::Vector3d &targetBasisX,
    const Eigen::Vector3d &targetBasisY,
    const Eigen::Vector3d &targetNormal) {
  const Eigen::Matrix3d rotation =
      normal_transport_rotation(sourceNormal, targetNormal);
  const Eigen::Matrix3d sourceAmbient =
      ambient_tensor(shapeOperator, sourceBasisX, sourceBasisY);
  const Eigen::Matrix3d targetAmbient =
      rotation * sourceAmbient * rotation.transpose();
  return restrict_tensor(targetAmbient, targetBasisX, targetBasisY);
}

inline double average_edge_length(const Eigen::MatrixXd &vertices,
                                  const Eigen::MatrixXi &faces) {
  double sum = 0.0;
  std::size_t count = 0;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      sum += (vertices.row(a) - vertices.row(b)).norm();
      ++count;
    }
  }
  return count == 0 ? 0.0 : sum / static_cast<double>(count);
}

inline void validate_inputs(const Eigen::MatrixXd &vertices,
                            const Eigen::MatrixXi &faces,
                            const Eigen::MatrixXd &faceBasisX,
                            const Eigen::MatrixXd &faceBasisY,
                            const Eigen::MatrixXd &faceNormals,
                            const Eigen::VectorXd &faceAreas,
                            const Eigen::MatrixXi &faceAdjacency,
                            const Eigen::MatrixXd &vertexNormals) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument(
        "Face curvature requires 3D vertices and triangular faces.");
  }
  if (faceBasisX.rows() != faces.rows() || faceBasisX.cols() != 3 ||
      faceBasisY.rows() != faces.rows() || faceBasisY.cols() != 3 ||
      faceNormals.rows() != faces.rows() || faceNormals.cols() != 3 ||
      faceAreas.size() != faces.rows() ||
      faceAdjacency.rows() != faces.rows() || faceAdjacency.cols() != 3 ||
      vertexNormals.rows() != vertices.rows() || vertexNormals.cols() != 3) {
    throw std::invalid_argument(
        "Face curvature input dimensions are inconsistent.");
  }
}

inline void decompose_shape_operators(
    const Eigen::MatrixXd &faceBasisX, const Eigen::MatrixXd &faceBasisY,
    const double averageEdgeLength, const FaceCurvatureOptions &options,
    FaceCurvatureResult &result) {
  const int faceCount = static_cast<int>(result.shapeOperators.size());
  result.principalDirectionsMin =
      Eigen::MatrixXd::Constant(faceCount, 3,
                                std::numeric_limits<double>::quiet_NaN());
  result.principalDirectionsMax = result.principalDirectionsMin;
  result.principalCurvatures =
      Eigen::MatrixXd::Constant(faceCount, 2,
                                std::numeric_limits<double>::quiet_NaN());
  result.confidence = Eigen::VectorXd::Zero(faceCount);

  const double safeEdgeLength = std::max(averageEdgeLength, 1e-15);
  const double curvatureScale = options.magnitudeGateScale / safeEdgeLength;

  for (int face = 0; face < faceCount; ++face) {
    if (result.valid(face) == 0 ||
        !finite_matrix(result.shapeOperators[face])) {
      result.valid(face) = 0;
      continue;
    }

    const Eigen::Matrix2d symmetric =
        0.5 * (result.shapeOperators[face] +
               result.shapeOperators[face].transpose());
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> solver(symmetric);
    if (solver.info() != Eigen::Success ||
        !solver.eigenvalues().array().isFinite().all() ||
        !solver.eigenvectors().array().isFinite().all()) {
      result.valid(face) = 0;
      continue;
    }

    const double kMin = solver.eigenvalues()(0);
    const double kMax = solver.eigenvalues()(1);
    result.shapeOperators[face] = symmetric;
    result.principalCurvatures.row(face) << kMin, kMax;

    const Eigen::Vector2d minIntrinsic = solver.eigenvectors().col(0);
    const Eigen::Vector2d maxIntrinsic = solver.eigenvectors().col(1);
    Eigen::Vector3d minDirection =
        minIntrinsic(0) * faceBasisX.row(face).transpose() +
        minIntrinsic(1) * faceBasisY.row(face).transpose();
    Eigen::Vector3d maxDirection =
        maxIntrinsic(0) * faceBasisX.row(face).transpose() +
        maxIntrinsic(1) * faceBasisY.row(face).transpose();

    if (minDirection.squaredNorm() <= 1e-20 ||
        maxDirection.squaredNorm() <= 1e-20) {
      result.valid(face) = 0;
      continue;
    }

    result.principalDirectionsMin.row(face) = minDirection.normalized();
    result.principalDirectionsMax.row(face) = maxDirection.normalized();

    const double magnitude = std::abs(kMin) + std::abs(kMax);
    const double anisotropy =
        std::abs(kMax - kMin) /
        (magnitude + 1e-12 / safeEdgeLength);
    const double magnitudeGate =
        magnitude / (magnitude + curvatureScale + 1e-30);
    const double confidence =
        std::clamp(anisotropy * magnitudeGate * result.fitQuality(face),
                   0.0, 1.0);
    result.confidence(face) = confidence;
  }
}

} // namespace face_curvature_detail

/**
 * @brief Minimal ambient rotation carrying one unit normal to another.
 */
inline Eigen::Matrix3d transport_rotation_between_normals(
    const Eigen::Vector3d &sourceNormal,
    const Eigen::Vector3d &targetNormal) {
  return face_curvature_detail::normal_transport_rotation(sourceNormal,
                                                           targetNormal);
}

/**
 * @brief Estimates one symmetric shape operator per face from normal variation.
 *
 * For each triangle edge e with endpoint-normal difference dn, solves
 * S * e_tangent ~= dn_tangent for the three independent coefficients of S.
 */
inline FaceCurvatureResult estimate_face_curvature(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceBasisX, const Eigen::MatrixXd &faceBasisY,
    const Eigen::MatrixXd &faceNormals, const Eigen::VectorXd &faceAreas,
    const Eigen::MatrixXi &faceAdjacency,
    const Eigen::MatrixXd &vertexNormals,
    const FaceCurvatureOptions &options = {}) {
  using namespace face_curvature_detail;

  validate_inputs(vertices, faces, faceBasisX, faceBasisY, faceNormals,
                  faceAreas, faceAdjacency, vertexNormals);
  if (options.smoothingIterations < 0) {
    throw std::invalid_argument("smoothingIterations must be non-negative.");
  }
  if (options.minimumSingularValueRatio <= 0.0 ||
      options.minimumSingularValueRatio >= 1.0) {
    throw std::invalid_argument(
        "minimumSingularValueRatio must lie in (0, 1).");
  }

  const int faceCount = faces.rows();
  const double edgeLength = average_edge_length(vertices, faces);
  const double minimumArea =
      options.minimumRelativeArea * edgeLength * edgeLength;
  const double nan = std::numeric_limits<double>::quiet_NaN();

  FaceCurvatureResult result;
  result.shapeOperators.assign(faceCount, Eigen::Matrix2d::Constant(nan));
  result.fitResiduals = Eigen::VectorXd::Constant(faceCount, nan);
  result.fitQuality = Eigen::VectorXd::Zero(faceCount);
  result.valid = Eigen::VectorXi::Zero(faceCount);

  for (int face = 0; face < faceCount; ++face) {
    if (!std::isfinite(faceAreas(face)) || faceAreas(face) <= minimumArea ||
        !faceBasisX.row(face).array().isFinite().all() ||
        !faceBasisY.row(face).array().isFinite().all() ||
        !faceNormals.row(face).array().isFinite().all()) {
      continue;
    }

    Eigen::Matrix<double, 6, 3> system;
    Eigen::Matrix<double, 6, 1> rhs;
    bool finite = true;

    for (int opposite = 0; opposite < 3; ++opposite) {
      const int cornerA = (opposite + 1) % 3;
      const int cornerB = (opposite + 2) % 3;
      const int vertexA = faces(face, cornerA);
      const int vertexB = faces(face, cornerB);

      const Eigen::Vector3d edge =
          (vertices.row(vertexB) - vertices.row(vertexA)).transpose();
      const Eigen::Vector3d normalDifference =
          (vertexNormals.row(vertexB) - vertexNormals.row(vertexA))
              .transpose();

      if (!finite_vector(edge) || !finite_vector(normalDifference)) {
        finite = false;
        break;
      }

      const Eigen::Vector3d bx = faceBasisX.row(face).transpose();
      const Eigen::Vector3d by = faceBasisY.row(face).transpose();
      const double edgeX = edge.dot(bx);
      const double edgeY = edge.dot(by);
      const double normalX = normalDifference.dot(bx);
      const double normalY = normalDifference.dot(by);

      system.row(2 * opposite) << edgeX, edgeY, 0.0;
      system.row(2 * opposite + 1) << 0.0, edgeX, edgeY;
      rhs(2 * opposite) = normalX;
      rhs(2 * opposite + 1) = normalY;
    }

    if (!finite) {
      continue;
    }

    Eigen::JacobiSVD<Eigen::Matrix<double, 6, 3>> svd(
        system, Eigen::ComputeFullU | Eigen::ComputeFullV);
    const Eigen::Vector3d singularValues = svd.singularValues();
    if (!singularValues.array().isFinite().all() ||
        singularValues(0) <= 1e-15) {
      continue;
    }

    const double singularRatio =
        singularValues(2) / std::max(singularValues(0), 1e-30);
    if (singularRatio < options.minimumSingularValueRatio) {
      continue;
    }

    const Eigen::Vector3d coefficients = svd.solve(rhs);
    if (!coefficients.array().isFinite().all()) {
      continue;
    }

    Eigen::Matrix2d shapeOperator;
    shapeOperator << coefficients(0), coefficients(1), coefficients(1),
        coefficients(2);

    const double residualSquared =
        (system * coefficients - rhs).squaredNorm();
    const double relativeResidual =
        residualSquared / (rhs.squaredNorm() + 1e-30);
    const double residualQuality =
        std::exp(-options.residualDecay * relativeResidual);
    const double conditioningQuality =
        std::clamp(singularRatio / 1e-2, 0.0, 1.0);

    result.shapeOperators[face] = shapeOperator;
    result.fitResiduals(face) = relativeResidual;
    result.fitQuality(face) = residualQuality * conditioningQuality;
    result.valid(face) = 1;
  }

  const double sharpCosine = std::cos(
      options.sharpFeatureAngleDegrees * std::numbers::pi / 180.0);

  for (int iteration = 0; iteration < options.smoothingIterations;
       ++iteration) {
    std::vector<Eigen::Matrix2d> smoothed = result.shapeOperators;

    for (int face = 0; face < faceCount; ++face) {
      if (result.valid(face) == 0) {
        continue;
      }

      const Eigen::Vector3d targetBx = faceBasisX.row(face).transpose();
      const Eigen::Vector3d targetBy = faceBasisY.row(face).transpose();
      const Eigen::Vector3d targetNormal = faceNormals.row(face).transpose();

      double totalWeight =
          std::max(faceAreas(face), 1e-30) *
          std::max(result.fitQuality(face), 1e-6);
      Eigen::Matrix2d weighted =
          totalWeight * result.shapeOperators[face];

      for (int corner = 0; corner < 3; ++corner) {
        const int neighbor = faceAdjacency(face, corner);
        if (neighbor < 0 || neighbor >= faceCount ||
            result.valid(neighbor) == 0) {
          continue;
        }

        const Eigen::Vector3d neighborNormal =
            faceNormals.row(neighbor).transpose();
        if (options.preserveSharpFeatures &&
            targetNormal.normalized().dot(neighborNormal.normalized()) <
                sharpCosine) {
          continue;
        }

        const Eigen::Matrix2d transported = transport_tensor(
            result.shapeOperators[neighbor],
            faceBasisX.row(neighbor).transpose(),
            faceBasisY.row(neighbor).transpose(), neighborNormal, targetBx,
            targetBy, targetNormal);
        const double weight =
            std::max(faceAreas(neighbor), 1e-30) *
            std::max(result.fitQuality(neighbor), 1e-6);
        weighted += weight * transported;
        totalWeight += weight;
      }

      if (totalWeight > 0.0) {
        smoothed[face] = weighted / totalWeight;
      }
    }

    result.shapeOperators = std::move(smoothed);
  }

  decompose_shape_operators(faceBasisX, faceBasisY, edgeLength, options,
                            result);
  return result;
}

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_FACE_CURVATURE_H
