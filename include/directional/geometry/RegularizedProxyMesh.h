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
#include <stdexcept>
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

inline double cotangent(const Eigen::Vector3d &first,
                        const Eigen::Vector3d &second) {
  const double denominator = first.cross(second).norm();
  if (denominator <= 1e-30) {
    return 0.0;
  }
  return first.dot(second) / denominator;
}

inline double average_unique_edge_length(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &edges) {
  if (edges.rows() == 0) {
    return 0.0;
  }
  double sum = 0.0;
  for (int edge = 0; edge < edges.rows(); ++edge) {
    sum += (vertices.row(edges(edge, 0)) - vertices.row(edges(edge, 1)))
               .norm();
  }
  return sum / static_cast<double>(edges.rows());
}

inline void validate_proxy_inputs(const Eigen::MatrixXd &vertices,
                                  const Eigen::MatrixXi &faces,
                                  const Eigen::MatrixXi &edges,
                                  const Eigen::VectorXi &boundaryVertices,
                                  const RegularizedProxyMeshOptions &options) {
  if (vertices.rows() == 0 || faces.rows() == 0 || vertices.cols() != 3 ||
      faces.cols() != 3) {
    throw std::invalid_argument(
        "Proxy regularization requires a non-empty triangular 3D mesh.");
  }
  if (edges.cols() != 2 || boundaryVertices.size() != vertices.rows()) {
    throw std::invalid_argument(
        "Proxy regularization edge/boundary dimensions are inconsistent.");
  }
  if (!(options.fidelityWeight > 0.0) ||
      options.smoothnessWeight < 0.0) {
    throw std::invalid_argument(
        "Proxy fidelityWeight must be positive and smoothnessWeight must be "
        "non-negative.");
  }
}

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
inline RegularizedProxyMeshResult regularize_proxy_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXi &edges, const Eigen::VectorXi &boundaryVertices,
    const RegularizedProxyMeshOptions &options = {}) {
  using Eigen::SparseMatrix;
  using Eigen::Triplet;
  using namespace regularized_proxy_detail;

  validate_proxy_inputs(vertices, faces, edges, boundaryVertices, options);
  const int vertexCount = vertices.rows();

  Eigen::VectorXd lumpedMass = Eigen::VectorXd::Zero(vertexCount);
  std::vector<Triplet<double>> stiffnessTriplets;
  stiffnessTriplets.reserve(static_cast<std::size_t>(12 * faces.rows()));
  std::vector<double> diagonal(vertexCount, 0.0);

  const auto add_edge_weight = [&](const int first, const int second,
                                   double weight) {
    if (options.clampNegativeCotangents) {
      weight = std::max(0.0, weight);
    }
    if (std::abs(weight) <= 1e-30) {
      return;
    }
    diagonal[first] += weight;
    diagonal[second] += weight;
    stiffnessTriplets.emplace_back(first, second, -weight);
    stiffnessTriplets.emplace_back(second, first, -weight);
  };

  for (int face = 0; face < faces.rows(); ++face) {
    const int i = faces(face, 0);
    const int j = faces(face, 1);
    const int k = faces(face, 2);
    const Eigen::Vector3d vi = vertices.row(i).transpose();
    const Eigen::Vector3d vj = vertices.row(j).transpose();
    const Eigen::Vector3d vk = vertices.row(k).transpose();

    const double doubledArea = (vj - vi).cross(vk - vi).norm();
    if (!(doubledArea > 1e-30) || !std::isfinite(doubledArea)) {
      continue;
    }

    const double area = 0.5 * doubledArea;
    lumpedMass(i) += area / 3.0;
    lumpedMass(j) += area / 3.0;
    lumpedMass(k) += area / 3.0;

    // Each edge receives one half of the opposite-angle cotangent.
    add_edge_weight(j, k, 0.5 * cotangent(vj - vi, vk - vi));
    add_edge_weight(k, i, 0.5 * cotangent(vk - vj, vi - vj));
    add_edge_weight(i, j, 0.5 * cotangent(vi - vk, vj - vk));
  }

  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    stiffnessTriplets.emplace_back(vertex, vertex, diagonal[vertex]);
    if (!(lumpedMass(vertex) > 1e-30)) {
      lumpedMass(vertex) = 1.0;
    }
  }

  SparseMatrix<double> stiffness(vertexCount, vertexCount);
  stiffness.setFromTriplets(stiffnessTriplets.begin(),
                            stiffnessTriplets.end());
  stiffness.makeCompressed();

  std::vector<Triplet<double>> inverseMassTriplets;
  inverseMassTriplets.reserve(static_cast<std::size_t>(vertexCount));
  std::vector<Triplet<double>> massTriplets;
  massTriplets.reserve(static_cast<std::size_t>(vertexCount));
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    inverseMassTriplets.emplace_back(vertex, vertex,
                                     1.0 / lumpedMass(vertex));
    massTriplets.emplace_back(vertex, vertex, lumpedMass(vertex));
  }

  SparseMatrix<double> inverseMass(vertexCount, vertexCount);
  inverseMass.setFromTriplets(inverseMassTriplets.begin(),
                              inverseMassTriplets.end());
  SparseMatrix<double> mass(vertexCount, vertexCount);
  mass.setFromTriplets(massTriplets.begin(), massTriplets.end());

  const double averageEdgeLength =
      average_unique_edge_length(vertices, edges);
  const double scale = std::pow(std::max(averageEdgeLength, 1e-15), 4.0);
  SparseMatrix<double> system =
      options.fidelityWeight * mass +
      (options.smoothnessWeight * scale) *
          (stiffness.transpose() * inverseMass * stiffness);
  system.makeCompressed();
  Eigen::MatrixXd rhs = options.fidelityWeight * mass * vertices;

  Eigen::VectorXi fixedMask = Eigen::VectorXi::Zero(vertexCount);
  if (options.preserveBoundary) {
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (boundaryVertices(vertex) != 0) {
        fixedMask(vertex) = 1;
      }
    }
  }
  for (int index = 0; index < options.fixedVertices.size(); ++index) {
    const int vertex = options.fixedVertices(index);
    if (vertex < 0 || vertex >= vertexCount) {
      throw std::out_of_range("fixedVertices contains an invalid vertex id.");
    }
    fixedMask(vertex) = 1;
  }

  std::vector<int> freeVertices;
  freeVertices.reserve(static_cast<std::size_t>(vertexCount));
  Eigen::VectorXi freeIndex = Eigen::VectorXi::Constant(vertexCount, -1);
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    if (fixedMask(vertex) == 0) {
      freeIndex(vertex) = static_cast<int>(freeVertices.size());
      freeVertices.push_back(vertex);
    }
  }

  RegularizedProxyMeshResult result;
  result.vertices = vertices;
  result.fixedMask = fixedMask;
  result.averageEdgeLength = averageEdgeLength;

  if (!freeVertices.empty() && options.smoothnessWeight > 0.0) {
    std::vector<Triplet<double>> reducedTriplets;
    reducedTriplets.reserve(static_cast<std::size_t>(system.nonZeros()));
    Eigen::MatrixXd reducedRhs(freeVertices.size(), 3);
    for (std::size_t row = 0; row < freeVertices.size(); ++row) {
      reducedRhs.row(static_cast<int>(row)) = rhs.row(freeVertices[row]);
    }

    for (int outer = 0; outer < system.outerSize(); ++outer) {
      for (SparseMatrix<double>::InnerIterator entry(system, outer); entry;
           ++entry) {
        const int row = entry.row();
        const int column = entry.col();
        const int reducedRow = freeIndex(row);
        if (reducedRow < 0) {
          continue;
        }
        const int reducedColumn = freeIndex(column);
        if (reducedColumn >= 0) {
          reducedTriplets.emplace_back(reducedRow, reducedColumn,
                                       entry.value());
        } else {
          reducedRhs.row(reducedRow) -=
              entry.value() * vertices.row(column);
        }
      }
    }

    SparseMatrix<double> reducedSystem(freeVertices.size(),
                                       freeVertices.size());
    reducedSystem.setFromTriplets(reducedTriplets.begin(),
                                  reducedTriplets.end());
    reducedSystem.makeCompressed();

    Eigen::SimplicialLDLT<SparseMatrix<double>> solver;
    solver.compute(reducedSystem);
    if (solver.info() != Eigen::Success) {
      throw std::runtime_error(
          "Regularized proxy-mesh factorization failed.");
    }

    const Eigen::MatrixXd solution = solver.solve(reducedRhs);
    if (solver.info() != Eigen::Success ||
        !solution.array().isFinite().all()) {
      throw std::runtime_error("Regularized proxy-mesh solve failed.");
    }

    for (std::size_t row = 0; row < freeVertices.size(); ++row) {
      result.vertices.row(freeVertices[row]) = solution.row(row);
    }
  }

  result.displacement.resize(vertexCount);
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    result.displacement(vertex) =
        (result.vertices.row(vertex) - vertices.row(vertex)).norm();
  }
  return result;
}

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_REGULARIZED_PROXY_MESH_H
