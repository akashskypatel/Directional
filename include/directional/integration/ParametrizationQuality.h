// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_PARAMETRIZATION_QUALITY_H
#define DIRECTIONAL_INTEGRATION_PARAMETRIZATION_QUALITY_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Eigenvalues>

namespace directional {

struct ParametrizationQualityThresholds {
  double determinantEpsilon = 1.0e-8;
  double minimumSingularValue = 1.0e-6;
  double maximumConditionNumber = 100.0;
  double maximumScaleDistortion = 100.0;
};

struct ParametrizationFaceQuality {
  double determinant = 0.0;
  double sigmaMin = 0.0;
  double sigmaMax = 0.0;
  double conditionNumber = std::numeric_limits<double>::infinity();
  double scaleDistortion = std::numeric_limits<double>::infinity();
  bool inverted = false;
  bool nearDegenerate = false;
  bool highCondition = false;
  bool highScaleDistortion = false;
  bool bad = false;
};

struct ParametrizationQualityReport {
  std::vector<ParametrizationFaceQuality> faces;
  std::size_t invertedFaceCount = 0;
  std::size_t nearDegenerateFaceCount = 0;
  std::size_t highConditionFaceCount = 0;
  std::size_t highScaleDistortionFaceCount = 0;
  std::size_t badFaceCount = 0;
  double maximumConditionNumber = 0.0;
  double maximumScaleDistortion = 0.0;
  double meanConditionNumber = 0.0;
  double meanScaleDistortion = 0.0;
};

struct TargetedStiffeningOptions {
  bool enabled = false;
  int maximumPasses = 1;
  double badFaceWeight = 8.0;
  double neighborDecay = 0.35;
  double maximumBadFaceFraction = 0.25;
  ParametrizationQualityThresholds thresholds;
};

struct TargetedStiffeningWeights {
  Eigen::VectorXd faceWeights;
  std::vector<int> badFaces;
};

namespace detail {

Eigen::Matrix2d triangle_source_basis(const Eigen::MatrixXd &vertices,
                                             const Eigen::Vector3i &face);

bool faces_share_vertex(const Eigen::Vector3i &a,
                               const Eigen::Vector3i &b);

} // namespace detail

ParametrizationQualityReport analyze_parametrization_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &parameterFunctions,
    const ParametrizationQualityThresholds &thresholds =
        ParametrizationQualityThresholds{});

TargetedStiffeningWeights build_targeted_stiffening_weights(
    const Eigen::MatrixXi &faces, const ParametrizationQualityReport &report,
    const TargetedStiffeningOptions &options = TargetedStiffeningOptions{});

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_PARAMETRIZATION_QUALITY_H
