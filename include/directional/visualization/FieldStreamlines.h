// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_FIELD_STREAMLINES_H
#define DIRECTIONAL_VISUALIZATION_FIELD_STREAMLINES_H

#include <Eigen/Core>

#include <cstddef>

namespace directional::visualization {

/// Lengths are in units of the mesh's average edge length.
struct FieldStreamlineOptions {
  /// Minimum distance between seed face barycenters; 0 seeds every face.
  double seedSpacing = 2.0;
  /// Tracing steps; each advances every live line by `stepLength`.
  int steps = 60;
  double stepLength = 0.5;
  /// Lift of each segment along its face normal, to avoid z-fighting.
  double surfaceOffset = 0.02;
  /// Seed of the deterministic seed-selection order.
  unsigned int randomSeed = 1;
};

/**
 * Streamlines of a cross field, for display.
 *
 * Each seed starts four half-lines, one per field direction. The two
 * half-lines of one direction family (directions d and d + 2) form one
 * streamline through the seed and share its line id.
 */
struct FieldStreamlines {
  Eigen::MatrixXd points;      ///< 2S x 3 segment endpoints.
  Eigen::MatrixXi edges;       ///< S x 2 rows of `points`.
  Eigen::VectorXi edgeLine;    ///< Streamline id of each segment.
  Eigen::VectorXi edgeFamily;  ///< Direction family (0 or 1) of each segment.
  Eigen::VectorXi seedFaces;   ///< Seed face of each seed.
  std::size_t lineCount = 0;   ///< Two per seed.
  double averageEdgeLength = 0.0;
};

/**
 * Traces streamlines of a raw cross field (one 12-value cross per face) with
 * the library tracer. Seeds are face barycenters chosen by deterministic dart
 * throwing, so equal inputs give equal lines. Field vectors are normalized,
 * so a half-line is at most `steps * stepLength` edge lengths long; lines
 * stop early at boundaries and vanishing vectors.
 *
 * Throws std::invalid_argument for a non-triangular or empty mesh, a field
 * that is not F x 12, or non-positive steps or step length.
 */
FieldStreamlines trace_field_streamlines(const Eigen::MatrixXd &V,
                                         const Eigen::MatrixXi &F,
                                         const Eigen::MatrixXd &rawField,
                                         const FieldStreamlineOptions &options);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_FIELD_STREAMLINES_H
