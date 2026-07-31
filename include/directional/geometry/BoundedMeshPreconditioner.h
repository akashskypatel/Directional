// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_BOUNDED_MESH_PRECONDITIONER_H
#define DIRECTIONAL_GEOMETRY_BOUNDED_MESH_PRECONDITIONER_H

#include <cstddef>

#include <Eigen/Core>

#include <directional/core/Export.h>
#include <directional/geometry/AdaptiveFeatureMap.h>

namespace directional {
namespace geometry {

struct BoundedMeshPreconditionerOptions {
  bool enabled = false;
  double targetFaceRatio = 1.0;
  double maxFaceRatio = 1.05;
  double minFaceRatio = 0.95;
  double sharpAngleDegrees = 45.0;
  AdaptiveFeatureMapOptions featureMap;
  int maxFlipPasses = 4;
};

struct MeshQualityMetrics {
  double minTriangleAngleDegrees = 0.0;
  double aspectRatioP95 = 0.0;
  double aspectRatioP99 = 0.0;
  double edgeLengthCoefficientOfVariation = 0.0;
};

struct BoundedMeshPreconditionerResult {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  double adaptiveFeatureMapSeconds = 0.0;
  std::size_t adaptiveFeatureHardEdgeCount = 0;
  std::size_t adaptiveFeatureSoftEdgeCount = 0;
  std::size_t adaptiveFeatureBoundaryEdgeCount = 0;
  std::size_t adaptiveFeatureNonManifoldEdgeCount = 0;
  std::size_t adaptiveFeatureCurveCount = 0;
  std::size_t adaptiveFeatureClosedCurveCount = 0;
  double adaptiveFeatureMaxDensity = 0.0;
  std::size_t flipsAccepted = 0;
  std::size_t collapsesAccepted = 0;
  std::size_t splitsAccepted = 0;
  std::size_t inputTriangleCount = 0;
  std::size_t outputTriangleCount = 0;
  MeshQualityMetrics before;
  MeshQualityMetrics after;
};

class DIRECTIONAL_API BoundedMeshPreconditioner {
public:
  [[nodiscard]] static BoundedMeshPreconditionerResult
  precondition(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
               const BoundedMeshPreconditionerOptions &options);

  [[nodiscard]] static MeshQualityMetrics
  evaluate_quality(const Eigen::MatrixXd &vertices,
                   const Eigen::MatrixXi &faces);
};

} // namespace geometry
} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_BOUNDED_MESH_PRECONDITIONER_H
