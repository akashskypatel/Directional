// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H
#define DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H

#include <complex>
#include <limits>
#include <numbers>
#include <queue>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/SurfacePoint.h>


namespace directional::fields {

struct PointCrossFieldSample {
  Eigen::Vector3d position = Eigen::Vector3d::Zero();
  Eigen::Vector3d direction = Eigen::Vector3d::UnitX();
  double weight = 1.0;
  int requiredFace = -1;
  int requiredComponent = -1;
  int requiredSheet = -1;
};

enum class UncoveredFacePolicy {
  Fail,
  PropagateWithinComponent
};

struct PointSampledCrossFieldOptions {
  bool normalizeDirections = true;
  double maximumProjectionDistance =
      std::numeric_limits<double>::infinity();
  double minimumConfidence = 1.0e-12;
  UncoveredFacePolicy uncoveredFacePolicy = UncoveredFacePolicy::Fail;
  bool combDirections = true;
  bool computeMatching = true;
  std::vector<int> faceComponents;
  std::vector<int> faceSheets;
};

struct PointSampledCrossFieldResult {
  CrossFieldResult field;
  Eigen::VectorXd faceConfidence;
  std::vector<geometry::SurfacePoint> sampleProvenance;
};

PointSampledCrossFieldResult project_point_sampled_cross_field(
    const TriMesh &mesh, const std::vector<PointCrossFieldSample> &samples,
    const PointSampledCrossFieldOptions &options =
        PointSampledCrossFieldOptions{});

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H
