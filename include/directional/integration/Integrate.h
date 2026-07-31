// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGRATE_H
#define DIRECTIONAL_INTEGRATION_INTEGRATE_H

#include <Eigen/Core>


namespace directional {
class CartesianField;
class TriMesh;
struct IntegrationData;
} // namespace directional


/**
 * @file Integrate.h
 * @brief Integer-grid integration solver for directional fields.
 *
 * Implements the mixed-integer style integration stage used to convert a combed field into an N-function. The solver builds candidate integer period shifts, evaluates objectives, and records timing diagnostics.
 */

namespace directional {

// Integrates an N-directional fields into an N-function by solving the seamless
// Poisson equation. Respects *valid* linear reductions where the field is
// reducible to an n-field for n<=M, and consequently the function is reducible
// to an n-function. This function only works with face-based fields on triangle
// meshes. Input:
//  field:              The face-based field to be integrated, on the original
//  mesh intData:            Integration data, which must be obtained from
//  directional::setup_integration(). This is altered by the function. meshCut:
//  Cut mesh (obtained from setup_integration())
// Output:
//  NFunction:          #cV x N parameterization functions per cut vertex (full
//  version with all symmetries unpacked) NCornerFunctions   (3*N) x #F
//  parameterization functions per corner of whole mesh
bool
integrate(const directional::CartesianField &field, IntegrationData &intData,
          const directional::TriMesh &meshCut, Eigen::MatrixXd &NFunction,
          Eigen::MatrixXd &NCornerFunctions);

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGRATE_H
