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
#include <Eigen/QR>

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
void gaussian_curvature(const Eigen::MatrixXd &V,
                               const Eigen::MatrixXi &F,
                               const Eigen::VectorXi &isBoundaryVertex,
                               Eigen::VectorXd &G);

/// @brief Builds adjacency map from edge-vertex pairs.
/// @param EV #E by 2 edge-vertex pairs.
/// @return Adjacency map.
std::unordered_map<int, std::set<int>>
build_adjacency(const Eigen::MatrixXi &EV);

/// @brief Compute shape operator (2x2 Hessian of interpolated height function
/// in tangent frame)
/// @param V #V by 3 vertices.
/// @param EV #E by 2 edge-vertex pairs.
/// @param VBx #V by 3 boundary tangent vector x.
/// @param VBy #V by 3 boundary tangent vector y.
/// @param vertexNormals #V by 3 vertex normals.
/// @param Sv #V shape operators.
void shape_operator(const Eigen::MatrixXd &V, const Eigen::MatrixXi &EV,
                    const Eigen::MatrixXd &VBx, const Eigen::MatrixXd &VBy,
                    const Eigen::MatrixXd &vertexNormals,
                    std::vector<Eigen::Matrix2d> &Sv);

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_CURVATURE_H
