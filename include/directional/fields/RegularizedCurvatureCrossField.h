// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_REGULARIZED_CURVATURE_CROSS_FIELD_H
#define DIRECTIONAL_FIELDS_REGULARIZED_CURVATURE_CROSS_FIELD_H

#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <numbers>
#include <stdexcept>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/FaceCurvature.h>
#include <directional/geometry/RegularizedProxyMesh.h>
#include <directional/util/Progress.h>

namespace directional::fields {

/**
 * @brief Source of an alignment constraint used by the regularized solver.
 */
enum class RegularizedCrossFieldConstraintType : int {
  Curvature = 0,
  Boundary = 1,
  SharpFeature = 2,
};

/**
 * @brief Options for the Phase-1 regularized-curvature cross-field pipeline.
 */
struct RegularizedCurvatureCrossFieldOptions {
  RegularizedProxyMeshOptions proxy;
  FaceCurvatureOptions curvature;
  geometry::AdaptiveFeatureMapOptions featureMap;

  /// Relative coefficient of the transported degree-4 smoothness energy.
  double fieldSmoothnessWeight = 1.0;

  /// Relative coefficient of confidence-weighted curvature alignment.
  double curvatureAlignmentWeight = 1.0;

  /// Relative coefficient of boundary-edge alignment.
  double boundaryAlignmentWeight = 1.0;

  /// Relative coefficient of sharp-feature-edge alignment.
  double sharpFeatureAlignmentWeight = 1.0;

  /// Confidence exponent applied before constructing curvature weights.
  double confidenceExponent = 2.0;

  /// Ignore curvature targets below this confidence.
  double minimumConfidence = 1e-3;

  /// Normalize all extracted raw cross directions.
  bool normalizeDirections = true;

  /// Reorder the four branches so branch indices are locally coherent.
  /// Non-trivial topology still requires seams where a global ordering is
  /// impossible.
  bool combDirections = true;

  /// Return principal matching and singularity diagnostics.
  /// Matching is still computed internally when combDirections is true.
  bool computeMatching = true;

  /// Optional progress callback.
  ProgressCallback progress;
};

/**
 * @brief Field result plus optimized proxy, curvature, and constraint
 *        diagnostics.
 */
struct RegularizedCurvatureCrossFieldResult {
  CrossFieldResult field;
  Eigen::MatrixXd proxyVertices;
  Eigen::VectorXd proxyDisplacement;
  FaceCurvatureResult proxyCurvature;
  Eigen::VectorXi constrainedFaces;
  Eigen::MatrixXd constraintDirections;
  Eigen::VectorXd alignmentWeights;
  Eigen::VectorXi constraintTypes;
  double smoothnessEnergy = 0.0;
  double alignmentEnergy = 0.0;
  double curvatureAlignmentEnergy = 0.0;
  double boundaryAlignmentEnergy = 0.0;
  double sharpFeatureAlignmentEnergy = 0.0;
};

namespace regularized_cross_field_detail {

using Complex = std::complex<double>;
using ComplexSparseMatrix = Eigen::SparseMatrix<Complex>;
using ComplexTriplet = Eigen::Triplet<Complex>;

struct AlignmentConstraint {
  int face = -1;
  Eigen::Vector3d direction = Eigen::Vector3d::Zero();
  double confidence = 1.0;
  double mass = 1.0;
  RegularizedCrossFieldConstraintType type =
      RegularizedCrossFieldConstraintType::Curvature;
};

struct AlignmentEnergyBreakdown {
  double curvature = 0.0;
  double boundary = 0.0;
  double sharpFeature = 0.0;

  [[nodiscard]] double total() const {
    return curvature + boundary + sharpFeature;
  }
};

std::size_t constraint_type_index(
    const RegularizedCrossFieldConstraintType type);

double constraint_group_weight(
    const RegularizedCurvatureCrossFieldOptions &options,
    const RegularizedCrossFieldConstraintType type);

double &constraint_group_energy(
    AlignmentEnergyBreakdown &energy,
    const RegularizedCrossFieldConstraintType type);

Eigen::Vector3d transport_proxy_direction_to_original(
    const Eigen::Vector3d &direction,
    const Eigen::Vector3d &proxyNormal,
    const Eigen::Vector3d &originalNormal);

Eigen::Vector3d projected_edge_direction(const TriMesh &mesh,
                                                const int edge,
                                                const int face);

bool is_sharp_edge(const TriMesh &mesh, const int edge,
                          const double thresholdDegrees);

Complex degree_four_target(const TriMesh &mesh, const int face,
                                  const Eigen::Vector3d &direction);

Eigen::VectorXcd solve_aligned_power_field(
    const TriMesh &mesh, const PCFaceTangentBundle &tangentBundle,
    const std::vector<AlignmentConstraint> &constraints,
    const RegularizedCurvatureCrossFieldOptions &options,
    double &smoothnessEnergy, AlignmentEnergyBreakdown &alignmentEnergy);

CartesianField make_raw_field(const PCFaceTangentBundle &tangentBundle,
                                     const Eigen::VectorXcd &power,
                                     const bool normalizeDirections);

} // namespace regularized_cross_field_detail

/**
 * @brief Computes a smooth 4-RoSy field aligned to curvature, boundary edges,
 *        and sharp feature edges of a fidelity-preserving regularized proxy.
 */
RegularizedCurvatureCrossFieldResult
extract_regularized_curvature_cross_field(
    const TriMesh &mesh,
    const RegularizedCurvatureCrossFieldOptions &options = {});

/**
 * @brief Array-based overload for regularized curvature cross-field extraction.
 */
RegularizedCurvatureCrossFieldResult
extract_regularized_curvature_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const RegularizedCurvatureCrossFieldOptions &options = {});

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_REGULARIZED_CURVATURE_CROSS_FIELD_H
