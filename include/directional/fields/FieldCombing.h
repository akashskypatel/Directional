// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_FIELD_COMBING_H
#define DIRECTIONAL_FIELDS_FIELD_COMBING_H

#include <cmath>
#include <queue>
#include <vector>

#include <Eigen/Core>

#include <directional/core/CartesianField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/util/GraphUtils.h>


/**
 * @file FieldCombing.h
 * @brief Field combing utilities for raw Cartesian fields.
 *
 * Contains the combing routine that propagates vector ordering across tangent-space adjacencies using a spanning tree and the field matching information.
 */

namespace directional {

/// @brief Reorders the vectors in a tangent space (preserving CCW direction) so
/// that the prescribed matching across most TB edges is an identity, except for
/// seams.
/// @note Important: if the Raw field in not CCW ordered, the result is
/// unpredictable.
/// @param rawField a RAW_FIELD uncombed cartesian field object
/// @param combedField the combed field object, also RAW_FIELD
/// @param _spaceIsCut Optionally prescribing the TB edges (corresponding to
/// mesh faces) that must be a seam
void combing(const directional::CartesianField &rawField,
                    directional::CartesianField &combedField,
                    const Eigen::MatrixXi &_spaceIsCut = Eigen::MatrixXi());

} // namespace directional

#endif // DIRECTIONAL_FIELDS_FIELD_COMBING_H
