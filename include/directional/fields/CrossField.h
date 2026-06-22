// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_CROSS_FIELD_H
#define DIRECTIONAL_FIELDS_CROSS_FIELD_H

#include <stdexcept>
#include <cmath>
#include <complex>
#include <numbers>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

#include <directional/core/CartesianField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/core/TriMesh.h>

/**
 * @file CrossField.h
 * @brief Construction and extraction of face-based 4-RoSy cross fields.
 *
 * A cross field contains four tangent directions per triangle, separated by
 * ninety degrees. The mesh-only extractor computes a smooth degree-4 power
 * field, converts its four roots to ordered ambient vectors, and optionally
 * derives principal edge matching and singularity indices.
 */

namespace directional::fields {

/// Number of ordered directions in a cross field.
inline constexpr int kCrossFieldDegree = 4;

/**
 * @brief Options controlling mesh-only cross-field extraction.
 */
struct CrossFieldOptions {
  /// Normalize every extracted direction to unit length.
  bool normalizeDirections = true;

  /// Compute edge matching, transport effort, and singularities.
  bool computeMatching = true;
};

/**
 * @brief Extracted face-based degree-4 cross field and diagnostics.
 */
struct CrossFieldResult {
  /// Field degree. Always four for this API.
  int degree = kCrossFieldDegree;

  /// Ordered ambient directions: #F by 12, grouped as four xyz vectors.
  Eigen::MatrixXd rawField;

  /// First cross axis, equal to rawField columns [0, 3).
  Eigen::MatrixXd primaryDirections;

  /// Orthogonal cross axis, equal to rawField columns [3, 6).
  Eigen::MatrixXd secondaryDirections;

  /// Principal rotational offset across every mesh edge.
  Eigen::VectorXi matching;

  /// Summed parallel-transport deviation across every mesh edge.
  Eigen::VectorXd effort;

  /// Vertex/local-cycle ids containing field singularities.
  Eigen::VectorXi singularCycles;

  /// Integer singularity numerators; actual indices are singularIndices / 4.
  Eigen::VectorXi singularIndices;
};

/**
 * @brief Projects an ambient vector onto a face tangent plane.
 * @param vector Ambient vector to project.
 * @param normal Unit face normal.
 * @param normalize Whether to return a unit-length tangent vector.
 * @return Tangent-plane component of @p vector.
 * @throws std::runtime_error if the projected vector is degenerate.
 */
inline Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &vector,
                                          const Eigen::RowVector3d &normal,
                                          const bool normalize) {
  Eigen::RowVector3d tangent = vector - vector.dot(normal) * normal;
  const double norm = tangent.norm();
  if (norm <= 1e-12) {
    throw std::runtime_error(
        "Directional cross-field construction received a degenerate tangent "
        "direction.");
  }
  if (normalize) {
    tangent /= norm;
  }
  return tangent;
}

/**
 * @brief Builds an ordered raw 4-RoSy field from two tangent direction
 * families.
 * @param mesh Source mesh with face normals already computed.
 * @param primaryDirections One ambient direction per face.
 * @param secondaryDirections Orthogonal or user-specified second direction per
 * face.
 * @param normalizeDirections Whether tangent-projected directions are
 * normalized.
 * @return #F-by-12 raw field ordered as +primary, +secondary, -primary,
 * -secondary.
 */
inline Eigen::MatrixXd
make_raw_cross_field(const TriMesh &mesh,
                     const Eigen::MatrixXd &primaryDirections,
                     const Eigen::MatrixXd &secondaryDirections,
                     const bool normalizeDirections = true) {
  if (primaryDirections.rows() != mesh.F.rows() ||
      primaryDirections.cols() != 3) {
    throw std::runtime_error("primaryDirections must have shape (#F, 3).");
  }
  if (secondaryDirections.rows() != mesh.F.rows() ||
      secondaryDirections.cols() != 3) {
    throw std::runtime_error("secondaryDirections must have shape (#F, 3).");
  }

  Eigen::MatrixXd rawField(mesh.F.rows(), 12);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d primary = project_tangent(
        primaryDirections.row(face), normal, normalizeDirections);
    const Eigen::RowVector3d secondary = project_tangent(
        secondaryDirections.row(face), normal, normalizeDirections);

    rawField.block(face, 0, 1, 3) = primary;
    rawField.block(face, 3, 1, 3) = secondary;
    rawField.block(face, 6, 1, 3) = -primary;
    rawField.block(face, 9, 1, 3) = -secondary;
  }
  return rawField;
}

/**
 * @brief Derives a second cross-field direction from face normals.
 * @param mesh Source mesh with face normals already computed.
 * @param primaryDirections One ambient direction per face.
 * @param normalizeDirections Whether projected directions are normalized.
 * @return #F-by-3 matrix of secondary tangent directions.
 */
inline Eigen::MatrixXd
orthogonal_complement(const TriMesh &mesh,
                      const Eigen::MatrixXd &primaryDirections,
                      const bool normalizeDirections = true) {
  if (primaryDirections.rows() != mesh.F.rows() ||
      primaryDirections.cols() != 3) {
    throw std::runtime_error("primaryDirections must have shape (#F, 3).");
  }

  Eigen::MatrixXd secondary(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d primary = project_tangent(
        primaryDirections.row(face), normal, normalizeDirections);
    Eigen::RowVector3d direction = normal.cross(primary);
    if (normalizeDirections) {
      direction.normalize();
    }
    secondary.row(face) = direction;
  }
  return secondary;
}

namespace {

using Complex = std::complex<double>;
using ComplexSparseMatrix = Eigen::SparseMatrix<Complex>;
using ComplexTriplet = Eigen::Triplet<Complex>;

inline Eigen::VectorXcd
solve_power_field(const PCFaceTangentBundle &tangentBundle,
                  const bool normalizeDirections) {
  const int faceCount = tangentBundle.numSpaces;
  Eigen::VectorXcd power = Eigen::VectorXcd::Ones(faceCount);
  if (faceCount == 1) {
    return power;
  }

  std::vector<ComplexTriplet> triplets;
  triplets.reserve(
      static_cast<std::size_t>(4 * tangentBundle.innerAdjacencies.size()));
  Eigen::VectorXcd rhs = Eigen::VectorXcd::Zero(faceCount - 1);

  const auto add_coefficient = [&](const int row, const int column,
                                   const Complex value) {
    if (row == 0) {
      return;
    }
    if (column == 0) {
      rhs(row - 1) -= value;
      return;
    }
    triplets.emplace_back(row - 1, column - 1, value);
  };

  int innerEdge = 0;
  for (int edge = 0; edge < tangentBundle.adjSpaces.rows(); ++edge) {
    const int firstFace = tangentBundle.adjSpaces(edge, 0);
    const int secondFace = tangentBundle.adjSpaces(edge, 1);
    if (firstFace == -1 || secondFace == -1) {
      continue;
    }

    const double weight =
        tangentBundle.connectionMass.coeff(innerEdge, innerEdge);
    const Complex transport =
        std::pow(tangentBundle.connection(edge), kCrossFieldDegree);

    add_coefficient(firstFace, firstFace, weight * std::norm(transport));
    add_coefficient(secondFace, secondFace, weight);
    add_coefficient(firstFace, secondFace, -weight * std::conj(transport));
    add_coefficient(secondFace, firstFace, -weight * transport);
    ++innerEdge;
  }

  ComplexSparseMatrix system(faceCount - 1, faceCount - 1);
  system.setFromTriplets(triplets.begin(), triplets.end());

  Eigen::SimplicialLDLT<ComplexSparseMatrix> solver;
  solver.compute(system);
  if (solver.info() != Eigen::Success) {
    throw std::runtime_error(
        "Cross-field power-system factorization failed. The mesh must be a "
        "connected manifold triangle mesh.");
  }

  power.tail(faceCount - 1) = solver.solve(rhs);
  if (solver.info() != Eigen::Success) {
    throw std::runtime_error("Cross-field power-system solve failed.");
  }

  if (normalizeDirections) {
    for (int face = 0; face < power.size(); ++face) {
      const double magnitude = std::abs(power(face));
      if (magnitude <= 1e-14) {
        throw std::runtime_error(
            "Cross-field extraction produced a degenerate power value.");
      }
      power(face) /= magnitude;
    }
  }

  return power;
}

inline CartesianField make_raw_field(const PCFaceTangentBundle &tangentBundle,
                                     const Eigen::VectorXcd &power,
                                     const bool normalizeDirections) {
  const int faceCount = tangentBundle.numSpaces;
  Eigen::MatrixXcd roots(faceCount, kCrossFieldDegree);

  for (int face = 0; face < faceCount; ++face) {
    Complex firstRoot =
        std::pow(power(face), 1.0 / static_cast<double>(kCrossFieldDegree));
    if (normalizeDirections) {
      const double magnitude = std::abs(firstRoot);
      if (magnitude <= 1e-14) {
        throw std::runtime_error(
            "Cross-field extraction produced a degenerate direction.");
      }
      firstRoot /= magnitude;
    }

    for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
      const double angle = 2.0 * std::numbers::pi * direction /
                           static_cast<double>(kCrossFieldDegree);
      roots(face, direction) = firstRoot * std::exp(Complex(0.0, angle));
    }
  }

  Eigen::MatrixXd intrinsic(faceCount, 2 * kCrossFieldDegree);
  for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
    intrinsic.col(2 * direction) = roots.col(direction).real();
    intrinsic.col(2 * direction + 1) = roots.col(direction).imag();
  }

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, kCrossFieldDegree);
  rawField.set_intrinsic_field(intrinsic);
  return rawField;
}

} // namespace

/**
 * @brief Computes a smooth face-based 4-RoSy cross field from a mesh.
 *
 * The field is obtained by minimizing the degree-4 power-field smoothness
 * energy. With no user constraints, the first face fixes the otherwise free
 * global rotation, making the result deterministic for a fixed mesh ordering.
 *
 * @param mesh Initialized triangle mesh.
 * @param options Extraction options.
 * @return Raw cross directions and optional matching/singularity diagnostics.
 */
inline CrossFieldResult
extract_cross_field(const TriMesh &mesh,
                    const CrossFieldOptions &options = {}) {
  if (mesh.V.rows() == 0 || mesh.F.rows() == 0) {
    throw std::runtime_error(
        "Cross-field extraction requires a non-empty triangle mesh.");
  }
  if (mesh.F.cols() != 3) {
    throw std::runtime_error(
        "Cross-field extraction requires triangular faces.");
  }

  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(mesh);

  const Eigen::VectorXcd power =
      solve_power_field(tangentBundle, options.normalizeDirections);
  CartesianField rawField =
      make_raw_field(tangentBundle, power, options.normalizeDirections);

  if (options.computeMatching) {
    principal_matching(rawField);
  }

  CrossFieldResult result;
  result.rawField = rawField.extField;
  result.primaryDirections = rawField.extField.leftCols<3>();
  result.secondaryDirections = rawField.extField.middleCols<3>(3);

  if (options.computeMatching) {
    result.matching = rawField.matching;
    result.effort = rawField.effort;
    result.singularCycles = rawField.singLocalCycles;
    result.singularIndices = rawField.singIndices;
  }

  return result;
}

/**
 * @brief Computes a smooth face-based 4-RoSy cross field from raw mesh arrays.
 * @param vertices #V-by-3 vertex positions.
 * @param faces #F-by-3 triangle indices.
 * @param options Extraction options.
 * @return Raw cross directions and optional matching/singularity diagnostics.
 */
inline CrossFieldResult
extract_cross_field(const Eigen::MatrixXd &vertices,
                    const Eigen::MatrixXi &faces,
                    const CrossFieldOptions &options = {}) {
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return extract_cross_field(mesh, options);
}

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_CROSS_FIELD_H
