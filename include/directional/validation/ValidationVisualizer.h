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

#if defined(DIRECTIONAL_VALIDATION_VISUALIZER_IMPLEMENTATION)
ValidationDebugColors make_validation_debug_colors(
    const int vertexCount, const int faceCount,
    const MeshValidationResult &validation) {
  ValidationDebugColors colors;
  colors.vertexColors = Eigen::MatrixXd::Constant(vertexCount, 3, 0.75);
  colors.faceColors = Eigen::MatrixXd::Constant(faceCount, 3, 0.75);

  for (const MeshValidationIssue &issue : validation.issues) {
    if (issue.vertex >= 0 && issue.vertex < vertexCount) {
      colors.vertexColors.row(issue.vertex) << 1.0, 0.0, 0.0;
    }
    if (issue.edgeFirst >= 0 && issue.edgeFirst < vertexCount) {
      colors.vertexColors.row(issue.edgeFirst) << 1.0, 0.55, 0.0;
    }
    if (issue.edgeSecond >= 0 && issue.edgeSecond < vertexCount) {
      colors.vertexColors.row(issue.edgeSecond) << 1.0, 0.55, 0.0;
    }
    if (issue.face >= 0 && issue.face < faceCount) {
      colors.faceColors.row(issue.face) << 0.85, 0.0, 1.0;
    }
  }
  return colors;
}
#else
ValidationDebugColors make_validation_debug_colors(
    const int vertexCount, const int faceCount,
    const MeshValidationResult &validation);
#endif

} // namespace directional::validation

#endif // DIRECTIONAL_VALIDATION_VALIDATION_VISUALIZER_H
