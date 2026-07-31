// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_FIELD_MATCHING_H
#define DIRECTIONAL_FIELDS_FIELD_MATCHING_H

#include <cmath>
#include <numbers>
#include <vector>

#include <Eigen/Core>

#include <directional/core/CartesianField.h>


/**
 * @file FieldMatching.h
 * @brief Matching and singularity utilities for N-direction fields.
 *
 * Computes edge-wise rotational matching, transport effort, and singularity indices for fields defined on tangent bundles.
 */

namespace directional {
/**
 * @brief Converts transported field effort into integer cycle indices.
 * @param basisCycles Oriented cycle-edge incidence matrix over interior adjacencies.
 * @param effort Transport effort per interior adjacency, expressed as summed rotations.
 * @param cycleCurvature Curvature associated with each measured cycle.
 * @param N Field degree.
 * @param indices Output cycle indices multiplied by @p N.
 * @throws std::runtime_error if numerical values are not close to integers.
 */
void effort_to_indices(const Eigen::SparseMatrix<double> &basisCycles,
                              const Eigen::VectorXd &effort,
                              const Eigen::VectorXd &cycleCurvature,
                              const int N, Eigen::VectorXi &indices);

/**
 * @brief Computes singularity cycle ids and indices in-place for a field.
 * @param field Cartesian field with populated matching effort and tangent-bundle cycles.
 */
void effort_to_indices(directional::CartesianField &field);
/**
 * @brief Computes principal rotational matching and transport effort for a raw field.
 * @param field Raw Cartesian field to update with matching, effort, and optionally singularities.
 * @param isSingularities When true, derives singularity indices after matching.
 *
 * The raw directions in each tangent space must be ordered counter-clockwise;
 * otherwise the rotational offsets are not meaningful.
 */
void principal_matching(directional::CartesianField &field,
                               const bool isSingularities = true);
} // namespace directional

#endif // DIRECTIONAL_FIELDS_FIELD_MATCHING_H
