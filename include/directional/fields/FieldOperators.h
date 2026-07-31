// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_FIELD_OPERATORS_H
#define DIRECTIONAL_FIELDS_FIELD_OPERATORS_H

#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>

#include <directional/core/TriMesh.h>


/**
 * @file FieldOperators.h
 * @brief Sparse operators for branched field integration.
 *
 * Builds the branched gradient operator that maps scalar N-functions to per-face differential quantities while accounting for field matching across adjacent tangent spaces.
 */

namespace directional {

/// @brief Computes the branched gradient matrix for a mesh with N-fold
/// symmetry.
/// @param mesh The mesh to compute the gradient for.
/// @param N The number of folds (symmetry order).
/// @param G The resulting gradient matrix.
void branched_gradient(const TriMesh &mesh, const int N,
                              Eigen::SparseMatrix<double> &G);

} // namespace directional

#endif // DIRECTIONAL_FIELDS_FIELD_OPERATORS_H
