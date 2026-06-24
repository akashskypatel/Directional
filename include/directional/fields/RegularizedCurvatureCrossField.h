// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_REGULARIZED_CURVATURE_CROSS_FIELD_H
#define DIRECTIONAL_FIELDS_REGULARIZED_CURVATURE_CROSS_FIELD_H

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
#include <directional/fields/FieldMatching.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/FaceCurvature.h>
#include <directional/geometry/RegularizedProxyMesh.h>
#include <directional/util/Progress.h>

namespace directional::fields {

/**
 * @brief Options for the Phase-1 regularized-curvature cross-field pipeline.
 */
struct RegularizedCurvatureCrossFieldOptions {
  RegularizedProxyMeshOptions proxy;
  FaceCurvatureOptions curvature;

  /// Relative coefficient of the transported degree-4 smoothness energy.
  double fieldSmoothnessWeight = 1.0;

  /// Relative coefficient of confidence-weighted curvature alignment.
  double curvatureAlignmentWeight = 1.0;

  /// Confidence exponent applied before constructing alignment weights.
  double confidenceExponent = 2.0;

  /// Ignore curvature targets below this confidence.
  double minimumConfidence = 1e-3;

  /// Normalize all extracted raw cross directions.
  bool normalizeDirections = true;

  /// Compute principal matching and singularity diagnostics.
  bool computeMatching = true;

  /// Optional progress callback.
  ProgressCallback progress;
};

/**
 * @brief Field result plus optimized proxy and curvature diagnostics.
 */
struct RegularizedCurvatureCrossFieldResult {
  CrossFieldResult field;
  Eigen::MatrixXd proxyVertices;
  Eigen::VectorXd proxyDisplacement;
  FaceCurvatureResult proxyCurvature;
  Eigen::VectorXi constrainedFaces;
  Eigen::MatrixXd constraintDirections;
  Eigen::VectorXd alignmentWeights;
  double smoothnessEnergy = 0.0;
  double alignmentEnergy = 0.0;
};

namespace regularized_cross_field_detail {

using Complex = std::complex<double>;
using ComplexSparseMatrix = Eigen::SparseMatrix<Complex>;
using ComplexTriplet = Eigen::Triplet<Complex>;

inline Eigen::Vector3d transport_proxy_direction_to_original(
    const Eigen::Vector3d &direction,
    const Eigen::Vector3d &proxyNormal,
    const Eigen::Vector3d &originalNormal) {
  Eigen::Vector3d transported =
      transport_rotation_between_normals(proxyNormal, originalNormal) *
      direction;
  transported -= transported.dot(originalNormal) * originalNormal;
  const double norm = transported.norm();
  if (!(norm > 1e-12) || !transported.array().isFinite().all()) {
    return Eigen::Vector3d::Zero();
  }
  return transported / norm;
}

inline Complex degree_four_target(const TriMesh &mesh, const int face,
                                  const Eigen::Vector3d &direction) {
  Complex intrinsic(direction.dot(mesh.FBx.row(face).transpose()),
                    direction.dot(mesh.FBy.row(face).transpose()));
  const double magnitude = std::abs(intrinsic);
  if (!(magnitude > 1e-14) || !std::isfinite(magnitude)) {
    throw std::runtime_error(
        "A curvature constraint could not be projected into its face basis.");
  }
  intrinsic /= magnitude;
  return std::pow(intrinsic, kCrossFieldDegree);
}

inline Eigen::VectorXcd solve_aligned_power_field(
    const TriMesh &mesh, const PCFaceTangentBundle &tangentBundle,
    const Eigen::VectorXi &constrainedFaces,
    const Eigen::MatrixXd &constraintDirections,
    const Eigen::VectorXd &confidenceWeights,
    const RegularizedCurvatureCrossFieldOptions &options,
    double &smoothnessEnergy, double &alignmentEnergy) {
  const int faceCount = tangentBundle.numSpaces;
  if (constrainedFaces.size() == 0) {
    throw std::invalid_argument(
        "solve_aligned_power_field requires at least one constraint.");
  }

  double totalSmoothMass = 0.0;
  for (int diagonal = 0; diagonal < tangentBundle.connectionMass.rows();
       ++diagonal) {
    totalSmoothMass += tangentBundle.connectionMass.coeff(diagonal, diagonal);
  }
  totalSmoothMass = std::max(totalSmoothMass, 1e-30);

  double totalConstraintMass = 0.0;
  for (int index = 0; index < constrainedFaces.size(); ++index) {
    const int face = constrainedFaces(index);
    totalConstraintMass +=
        tangentBundle.tangentSpaceMass.coeff(face, face);
  }
  totalConstraintMass = std::max(totalConstraintMass, 1e-30);

  std::vector<ComplexTriplet> triplets;
  triplets.reserve(static_cast<std::size_t>(
      4 * tangentBundle.innerAdjacencies.size() + constrainedFaces.size()));
  Eigen::VectorXcd rhs = Eigen::VectorXcd::Zero(faceCount);

  int innerEdge = 0;
  for (int edge = 0; edge < tangentBundle.adjSpaces.rows(); ++edge) {
    const int firstFace = tangentBundle.adjSpaces(edge, 0);
    const int secondFace = tangentBundle.adjSpaces(edge, 1);
    if (firstFace < 0 || secondFace < 0) {
      continue;
    }

    const double edgeMass =
        tangentBundle.connectionMass.coeff(innerEdge, innerEdge);
    const double weight =
        options.fieldSmoothnessWeight * edgeMass / totalSmoothMass;
    const Complex transport =
        std::pow(tangentBundle.connection(edge), kCrossFieldDegree);

    triplets.emplace_back(firstFace, firstFace,
                          weight * std::norm(transport));
    triplets.emplace_back(secondFace, secondFace, weight);
    triplets.emplace_back(firstFace, secondFace,
                          -weight * std::conj(transport));
    triplets.emplace_back(secondFace, firstFace, -weight * transport);
    ++innerEdge;
  }

  for (int index = 0; index < constrainedFaces.size(); ++index) {
    const int face = constrainedFaces(index);
    const double faceMass =
        tangentBundle.tangentSpaceMass.coeff(face, face);
    const double weight = options.curvatureAlignmentWeight *
                          confidenceWeights(index) * faceMass /
                          totalConstraintMass;
    const Complex target = degree_four_target(
        mesh, face, constraintDirections.row(index).transpose());
    triplets.emplace_back(face, face, weight);
    rhs(face) += weight * target;
  }

  ComplexSparseMatrix system(faceCount, faceCount);
  system.setFromTriplets(triplets.begin(), triplets.end());
  system.makeCompressed();

  Eigen::SimplicialLDLT<ComplexSparseMatrix> solver;
  solver.compute(system);
  if (solver.info() != Eigen::Success) {
    throw std::runtime_error(
        "Curvature-aligned power-field factorization failed.");
  }

  Eigen::VectorXcd power = solver.solve(rhs);
  if (solver.info() != Eigen::Success ||
      !power.array().isFinite().all()) {
    throw std::runtime_error("Curvature-aligned power-field solve failed.");
  }

  smoothnessEnergy = 0.0;
  innerEdge = 0;
  for (int edge = 0; edge < tangentBundle.adjSpaces.rows(); ++edge) {
    const int firstFace = tangentBundle.adjSpaces(edge, 0);
    const int secondFace = tangentBundle.adjSpaces(edge, 1);
    if (firstFace < 0 || secondFace < 0) {
      continue;
    }
    const double edgeMass =
        tangentBundle.connectionMass.coeff(innerEdge, innerEdge);
    const Complex transport =
        std::pow(tangentBundle.connection(edge), kCrossFieldDegree);
    smoothnessEnergy +=
        edgeMass * std::norm(power(secondFace) - transport * power(firstFace));
    ++innerEdge;
  }
  smoothnessEnergy *= options.fieldSmoothnessWeight / totalSmoothMass;

  alignmentEnergy = 0.0;
  for (int index = 0; index < constrainedFaces.size(); ++index) {
    const int face = constrainedFaces(index);
    const double faceMass =
        tangentBundle.tangentSpaceMass.coeff(face, face);
    const Complex target = degree_four_target(
        mesh, face, constraintDirections.row(index).transpose());
    alignmentEnergy +=
        confidenceWeights(index) * faceMass * std::norm(power(face) - target);
  }
  alignmentEnergy *=
      options.curvatureAlignmentWeight / totalConstraintMass;

  if (options.normalizeDirections) {
    for (int face = 0; face < power.size(); ++face) {
      const double magnitude = std::abs(power(face));
      if (!(magnitude > 1e-14) || !std::isfinite(magnitude)) {
        throw std::runtime_error(
            "Curvature-aligned power solve produced a degenerate face value.");
      }
      power(face) /= magnitude;
    }
  }
  return power;
}

inline CartesianField make_raw_field(const PCFaceTangentBundle &tangentBundle,
                                     const Eigen::VectorXcd &power,
                                     const bool normalizeDirections) {
  Eigen::MatrixXcd roots(tangentBundle.numSpaces, kCrossFieldDegree);
  for (int face = 0; face < tangentBundle.numSpaces; ++face) {
    Complex root =
        std::pow(power(face), 1.0 / static_cast<double>(kCrossFieldDegree));
    if (normalizeDirections) {
      const double magnitude = std::abs(root);
      if (!(magnitude > 1e-14)) {
        throw std::runtime_error(
            "Curvature-aligned field produced a degenerate root.");
      }
      root /= magnitude;
    }
    for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
      const double angle = 2.0 * std::numbers::pi * direction /
                           static_cast<double>(kCrossFieldDegree);
      roots(face, direction) = root * std::exp(Complex(0.0, angle));
    }
  }

  Eigen::MatrixXd intrinsic(tangentBundle.numSpaces,
                            2 * kCrossFieldDegree);
  for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
    intrinsic.col(2 * direction) = roots.col(direction).real();
    intrinsic.col(2 * direction + 1) = roots.col(direction).imag();
  }

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, kCrossFieldDegree);
  rawField.set_intrinsic_field(intrinsic);
  return rawField;
}

inline CrossFieldResult make_cross_field_result(const CartesianField &rawField,
                                                const bool computeMatching) {
  CrossFieldResult result;
  result.rawField = rawField.extField;
  result.primaryDirections = rawField.extField.leftCols<3>();
  result.secondaryDirections = rawField.extField.middleCols<3>(3);
  if (computeMatching) {
    result.matching = rawField.matching;
    result.effort = rawField.effort;
    result.singularCycles = rawField.singLocalCycles;
    result.singularIndices = rawField.singIndices;
  }
  return result;
}

} // namespace regularized_cross_field_detail

/**
 * @brief Computes a smooth 4-RoSy field aligned to principal curvature of a
 *        fidelity-preserving regularized proxy mesh.
 *
 * This Phase-1 implementation is deliberately two-stage: first optimize a
 * same-topology proxy surface, then solve a transported degree-4 power field
 * with confidence-weighted soft curvature targets. The field does not feed
 * back into proxy optimization in this phase.
 */
inline RegularizedCurvatureCrossFieldResult
extract_regularized_curvature_cross_field(
    const TriMesh &mesh,
    const RegularizedCurvatureCrossFieldOptions &options = {}) {
  using namespace regularized_cross_field_detail;

  if (mesh.V.rows() == 0 || mesh.F.rows() == 0 || mesh.F.cols() != 3) {
    throw std::invalid_argument(
        "Regularized curvature cross-field extraction requires a non-empty "
        "triangular mesh.");
  }
  if (!(options.fieldSmoothnessWeight > 0.0) ||
      !(options.curvatureAlignmentWeight >= 0.0) ||
      options.confidenceExponent <= 0.0 ||
      options.minimumConfidence < 0.0 || options.minimumConfidence > 1.0) {
    throw std::invalid_argument(
        "Invalid regularized curvature cross-field weights or thresholds.");
  }

  constexpr std::size_t stageCount = 7;
  report_progress(options.progress, 1, stageCount,
                  "Optimizing regularized proxy mesh");
  const RegularizedProxyMeshResult proxyResult = regularize_proxy_mesh(
      mesh.V, mesh.F, mesh.EV, mesh.isBoundaryVertex, options.proxy);

  report_progress(options.progress, 2, stageCount,
                  "Initializing proxy geometry");
  TriMesh proxyMesh;
  proxyMesh.set_mesh(proxyResult.vertices, mesh.F);

  report_progress(options.progress, 3, stageCount,
                  "Estimating proxy principal curvature");
  FaceCurvatureResult curvature = estimate_face_curvature(
      proxyMesh.V, proxyMesh.F, proxyMesh.FBx, proxyMesh.FBy,
      proxyMesh.faceNormals, proxyMesh.faceAreas, proxyMesh.TT,
      proxyMesh.vertexNormals, options.curvature);

  std::vector<int> constrainedFaceList;
  std::vector<Eigen::Vector3d> directionList;
  std::vector<double> confidenceWeightList;
  constrainedFaceList.reserve(static_cast<std::size_t>(mesh.F.rows()));
  directionList.reserve(static_cast<std::size_t>(mesh.F.rows()));
  confidenceWeightList.reserve(static_cast<std::size_t>(mesh.F.rows()));

  for (int face = 0; face < mesh.F.rows(); ++face) {
    if (curvature.valid(face) == 0 ||
        curvature.confidence(face) < options.minimumConfidence) {
      continue;
    }

    const Eigen::Vector3d target = transport_proxy_direction_to_original(
        curvature.principalDirectionsMax.row(face).transpose(),
        proxyMesh.faceNormals.row(face).transpose(),
        mesh.faceNormals.row(face).transpose());
    if (target.squaredNorm() <= 1e-20) {
      continue;
    }

    const double confidenceWeight =
        std::pow(curvature.confidence(face), options.confidenceExponent);
    if (!(confidenceWeight > 0.0) || !std::isfinite(confidenceWeight)) {
      continue;
    }

    constrainedFaceList.push_back(face);
    directionList.push_back(target);
    confidenceWeightList.push_back(confidenceWeight);
  }

  Eigen::VectorXi constrainedFaces(constrainedFaceList.size());
  Eigen::MatrixXd constraintDirections(directionList.size(), 3);
  Eigen::VectorXd confidenceWeights(confidenceWeightList.size());
  Eigen::VectorXd alignmentWeights(confidenceWeightList.size());
  for (std::size_t index = 0; index < constrainedFaceList.size(); ++index) {
    constrainedFaces(static_cast<int>(index)) = constrainedFaceList[index];
    constraintDirections.row(static_cast<int>(index)) = directionList[index];
    confidenceWeights(static_cast<int>(index)) = confidenceWeightList[index];
    alignmentWeights(static_cast<int>(index)) =
        options.curvatureAlignmentWeight * confidenceWeightList[index];
  }

  report_progress(options.progress, 4, stageCount,
                  "Initializing original tangent bundle");
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(mesh);

  CartesianField rawField;
  double smoothnessEnergy = 0.0;
  double alignmentEnergy = 0.0;
  if (constrainedFaces.size() == 0 ||
      options.curvatureAlignmentWeight == 0.0) {
    report_progress(options.progress, 5, stageCount,
                    "Solving smooth fallback cross field");
    CrossFieldOptions fallbackOptions;
    fallbackOptions.normalizeDirections = options.normalizeDirections;
    fallbackOptions.computeMatching = options.computeMatching;
    const CrossFieldResult fallback = extract_cross_field(mesh, fallbackOptions);

    RegularizedCurvatureCrossFieldResult result;
    result.field = fallback;
    result.proxyVertices = proxyResult.vertices;
    result.proxyDisplacement = proxyResult.displacement;
    result.proxyCurvature = std::move(curvature);
    result.constrainedFaces = std::move(constrainedFaces);
    result.constraintDirections = std::move(constraintDirections);
    result.alignmentWeights = std::move(alignmentWeights);
    report_progress(options.progress, 6, stageCount,
                    "No reliable curvature constraints found");
    report_progress(options.progress, 7, stageCount,
                    "Finalizing cross field");
    return result;
  }

  report_progress(options.progress, 5, stageCount,
                  "Solving smooth curvature-aligned power field");
  const Eigen::VectorXcd power = solve_aligned_power_field(
      mesh, tangentBundle, constrainedFaces, constraintDirections,
      confidenceWeights, options, smoothnessEnergy, alignmentEnergy);

  report_progress(options.progress, 6, stageCount,
                  "Constructing raw cross directions");
  rawField = regularized_cross_field_detail::make_raw_field(
      tangentBundle, power, options.normalizeDirections);

  report_progress(options.progress, 7, stageCount,
                  options.computeMatching ? "Computing field matching"
                                          : "Finalizing cross field");
  if (options.computeMatching) {
    principal_matching(rawField);
  }

  RegularizedCurvatureCrossFieldResult result;
  result.field = make_cross_field_result(rawField, options.computeMatching);
  result.proxyVertices = proxyResult.vertices;
  result.proxyDisplacement = proxyResult.displacement;
  result.proxyCurvature = std::move(curvature);
  result.constrainedFaces = std::move(constrainedFaces);
  result.constraintDirections = std::move(constraintDirections);
  result.alignmentWeights = std::move(alignmentWeights);
  result.smoothnessEnergy = smoothnessEnergy;
  result.alignmentEnergy = alignmentEnergy;
  return result;
}

/**
 * @brief Array-based overload for regularized curvature cross-field extraction.
 */
inline RegularizedCurvatureCrossFieldResult
extract_regularized_curvature_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const RegularizedCurvatureCrossFieldOptions &options = {}) {
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return extract_regularized_curvature_cross_field(mesh, options);
}

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_REGULARIZED_CURVATURE_CROSS_FIELD_H
