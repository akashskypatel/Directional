// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGRATION_SETUP_H
#define DIRECTIONAL_INTEGRATION_INTEGRATION_SETUP_H

#include <Eigen/Core>


namespace directional {
class CartesianField;
class TriMesh;
struct IntegrationData;
} // namespace directional


/**
 * @file SetupIntegration.h
 * @brief Assembly routines for integration linear systems.
 *
 * Builds sparse constraints, period jumps, reduced variables, and symmetry data needed before running the integration solver.
 */

namespace directional {
int eigen_index_to_int(const Eigen::Index value);
/// @brief Setting up the seamless integration algorithm
/// @details Seamless integration only works on IntrinsicFaceTangentBundle at
/// the moment.
/// @param field The raw field that is to be integrated
/// @param intData The integration data
/// @param meshCut The cut mesh
/// @param combedField The combed field
/// @note The raw field must be face-based
void setup_integration(const directional::CartesianField &field,
                              IntegrationData &intData,
                              directional::TriMesh &meshCut,
                              directional::CartesianField &combedField);

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGRATION_SETUP_H
