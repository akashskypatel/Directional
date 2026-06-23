// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_CURVATURE_H
#define DIRECTIONAL_GEOMETRY_CURVATURE_H

#include <numbers>
#include <set>
#include <unordered_map>

#include <Eigen/Core>


/**
 * @file Curvature.h
 * @brief Curvature estimators for triangle meshes.
 *
 * Declares Gaussian curvature and shape-operator routines used to derive discrete curvature information from mesh vertices, edges, faces, and normals.
 */

namespace directional {

/// @brief Computes boundary-aware discrete Gaussian curvature on vertices
/// (angle defect).
/// @param V #V by 3 vertices.
/// @param F #F by 3 triangles.
/// @param isBoundaryVertex #V boolean indicating if vertex is a boundary.
/// @param G #V discrete Gaussian curvature. sum(G) = eulerChar of mesh.
inline void gaussian_curvature(const Eigen::MatrixXd &V,
                               const Eigen::MatrixXi &F,
                               const Eigen::VectorXi &isBoundaryVertex,
                               Eigen::VectorXd &G) {

  G.resize(V.rows());
  for (int i = 0; i < V.rows(); i++)
    G(i) = (isBoundaryVertex(i) ? std::numbers::pi : 2.0 * std::numbers::pi);

  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < 3; j++) {
      Eigen::RowVector3d v1 = V.row(F(i, (j + 1) % 3)) - V.row(F(i, j));
      Eigen::RowVector3d v2 = V.row(F(i, (j + 2) % 3)) - V.row(F(i, j));
      double currAngle = std::acos(v1.dot(v2) / (v1.norm() * v2.norm()));
      G(F(i, j)) -= currAngle;
    }
  }
}

/// @brief Builds adjacency map from edge-vertex pairs.
/// @param EV #E by 2 edge-vertex pairs.
/// @return Adjacency map.
static std::unordered_map<int, std::set<int>>
build_adjacency(const Eigen::MatrixXi &EV) {
  std::unordered_map<int, std::set<int>> adj;
  for (int i = 0; i < EV.rows(); ++i) {
    int v0 = EV(i, 0);
    int v1 = EV(i, 1);
    adj[v0].insert(v1);
    adj[v1].insert(v0);
  }
  return adj;
}

/// @brief Compute shape operator (2x2 Hessian of interpolated height function
/// in tangent frame)
/// @param V #V by 3 vertices.
/// @param EV #E by 2 edge-vertex pairs.
/// @param VBx #V by 3 boundary tangent vector x.
/// @param VBy #V by 3 boundary tangent vector y.
/// @param vertexNormals #V by 3 vertex normals.
/// @param Sv #V shape operators.
inline void shape_operator(const Eigen::MatrixXd &V, const Eigen::MatrixXi &EV,
                    const Eigen::MatrixXd &VBx, const Eigen::MatrixXd &VBy,
                    const Eigen::MatrixXd &vertexNormals,
                    std::vector<Eigen::Matrix2d> &Sv) {

  Sv.resize(V.rows(),
            Eigen::Matrix2d::Constant(std::nan(""))); // default to NaNs

  auto adjacency = build_adjacency(EV);

  for (int vi = 0; vi < V.rows(); ++vi) {
    const auto &neighbors = adjacency[vi];

    const Eigen::RowVector3d origin = V.row(vi);
    const Eigen::RowVector3d normal = vertexNormals.row(vi).normalized();
    const Eigen::RowVector3d bx = VBx.row(vi).normalized();
    const Eigen::RowVector3d by = VBy.row(vi).normalized();

    Eigen::MatrixXd A(neighbors.size(), 5);
    Eigen::VectorXd rhs(neighbors.size());

    int currRow = 0;
    for (int nj : neighbors) {
      Eigen::RowVector3d delta = V.row(nj) - origin;
      double x = delta.dot(bx);
      double y = delta.dot(by);
      double z = delta.dot(normal); // height along normal direction

      A.row(currRow) << x * x, x * y, y * y, x, y;
      rhs(currRow) = z;
      currRow++;
    }

    Eigen::VectorXd coeffs = A.colPivHouseholderQr().solve(rhs);
    double a = coeffs(0), b = coeffs(1), c = coeffs(2);

    Eigen::Matrix2d H;
    H << 2 * a, b, b, 2 * c;

    Sv[vi] = -H;
  }
}

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_CURVATURE_H
