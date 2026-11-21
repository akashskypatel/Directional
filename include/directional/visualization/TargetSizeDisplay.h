// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_TARGET_SIZE_DISPLAY_H
#define DIRECTIONAL_VISUALIZATION_TARGET_SIZE_DISPLAY_H

#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/AdaptiveTargetSize.h>

#include <Eigen/Core>

#include <string>
#include <vector>

namespace directional::visualization {

/// One per-vertex scalar field, ready for a heatmap.
struct VertexScalarField {
  std::string name;
  Eigen::VectorXd values;
  /// Entries that were not finite; they are shown at the field's finite
  /// maximum (or 0 when no entry is finite).
  int nonFiniteCount = 0;
};

/**
 * Display data for the SurfaceCells target edge length (metric stage) and
 * the adaptive feature map (feature stage).
 *
 * Diagnostic only: values are copied from the published results; no
 * pipeline stage reads them back.
 */
struct TargetSizeDisplay {
  /// Target edge length first, then its per-criterion proposals and inputs.
  std::vector<VertexScalarField> vertexScalars;

  /// Feature edges that are not smooth (2E x 3, E x 2), with their class
  /// (1 boundary, 2 soft, 3 hard, 4 non-manifold), strength and dihedral
  /// angle in degrees.
  Eigen::MatrixXd featurePoints;
  Eigen::MatrixXi featureEdges;
  Eigen::VectorXi featureClass;
  Eigen::VectorXd featureStrength;
  Eigen::VectorXd featureAngleDegrees;

  bool hasTargetSize = false;
  bool hasFeatureMap = false;
  double resolvedSurfaceError = 0.0;
  /// Fields left out because their length is not the vertex count.
  std::vector<std::string> notes;
};

/**
 * Reads either result when present (each pointer may be null).
 *
 * Throws std::invalid_argument when `V` is not n x 3, `F` is not m x 3, or a
 * feature edge names a vertex outside `V`.
 */
TargetSizeDisplay target_size_display(const Eigen::MatrixXd &V,
                                      const Eigen::MatrixXi &F,
                                      const geometry::AdaptiveTargetSizeResult *targetSize,
                                      const geometry::AdaptiveFeatureMap *featureMap);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_TARGET_SIZE_DISPLAY_H
