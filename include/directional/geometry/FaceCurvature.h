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
#include <array>
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

  /// Estimate normal differences with face-corner normals that do not blend
  /// across sharp features.
  bool useFeatureAwareCornerNormals = true;

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

double clamp_unit(const double value);

bool finite_vector(const Eigen::Vector3d &value);

bool finite_matrix(const Eigen::Matrix2d &value);

Eigen::Matrix3d normal_transport_rotation(
    const Eigen::Vector3d &sourceNormal,
    const Eigen::Vector3d &targetNormal);

Eigen::Matrix3d ambient_tensor(const Eigen::Matrix2d &shapeOperator,
                                      const Eigen::Vector3d &basisX,
                                      const Eigen::Vector3d &basisY);

Eigen::Matrix2d restrict_tensor(const Eigen::Matrix3d &ambient,
                                       const Eigen::Vector3d &basisX,
                                       const Eigen::Vector3d &basisY);

Eigen::Matrix2d transport_tensor(
    const Eigen::Matrix2d &shapeOperator,
    const Eigen::Vector3d &sourceBasisX,
    const Eigen::Vector3d &sourceBasisY,
    const Eigen::Vector3d &sourceNormal,
    const Eigen::Vector3d &targetBasisX,
    const Eigen::Vector3d &targetBasisY,
    const Eigen::Vector3d &targetNormal);

double average_edge_length(const Eigen::MatrixXd &vertices,
                                  const Eigen::MatrixXi &faces);

void validate_inputs(const Eigen::MatrixXd &vertices,
                            const Eigen::MatrixXi &faces,
                            const Eigen::MatrixXd &faceBasisX,
                            const Eigen::MatrixXd &faceBasisY,
                            const Eigen::MatrixXd &faceNormals,
                            const Eigen::VectorXd &faceAreas,
                            const Eigen::MatrixXi &faceAdjacency,
                            const Eigen::MatrixXd &vertexNormals);


std::vector<std::array<Eigen::Vector3d, 3>>
build_face_corner_normals(const Eigen::MatrixXi &faces,
                          const Eigen::MatrixXd &faceNormals,
                          const Eigen::VectorXd &faceAreas,
                          const Eigen::MatrixXd &vertexNormals,
                          const FaceCurvatureOptions &options);

void decompose_shape_operators(
    const Eigen::MatrixXd &faceBasisX, const Eigen::MatrixXd &faceBasisY,
    const double averageEdgeLength, const FaceCurvatureOptions &options,
    FaceCurvatureResult &result);

} // namespace face_curvature_detail

/**
 * @brief Minimal ambient rotation carrying one unit normal to another.
 */
Eigen::Matrix3d transport_rotation_between_normals(
    const Eigen::Vector3d &sourceNormal,
    const Eigen::Vector3d &targetNormal);

/**
 * @brief Estimates one symmetric shape operator per face from normal variation.
 *
 * For each triangle edge e with endpoint-normal difference dn, solves
 * S * e_tangent ~= dn_tangent for the three independent coefficients of S.
 */
FaceCurvatureResult estimate_face_curvature(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceBasisX, const Eigen::MatrixXd &faceBasisY,
    const Eigen::MatrixXd &faceNormals, const Eigen::VectorXd &faceAreas,
    const Eigen::MatrixXi &faceAdjacency,
    const Eigen::MatrixXd &vertexNormals,
    const FaceCurvatureOptions &options = {});

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_FACE_CURVATURE_H
