// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VALIDATION_VALIDATION_VISUALIZER_H
#define DIRECTIONAL_VALIDATION_VALIDATION_VISUALIZER_H

#include <Eigen/Core>

#include <directional/validation/MeshValidator.h>

namespace directional::validation {

struct ValidationDebugColors {
  Eigen::MatrixXd vertexColors;
  Eigen::MatrixXd faceColors;
};

ValidationDebugColors make_validation_debug_colors(
    const int vertexCount, const int faceCount,
    const MeshValidationResult &validation);

} // namespace directional::validation

#endif // DIRECTIONAL_VALIDATION_VALIDATION_VISUALIZER_H
