// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_FIELD_ALIGNED_NETWORK_POLYLINES_H
#define DIRECTIONAL_VISUALIZATION_FIELD_ALIGNED_NETWORK_POLYLINES_H

#include <directional/geometry/SurfaceCellTracing.h>

#include <Eigen/Core>

#include <cstddef>

namespace directional::visualization {

/// How a candidate trace ends, as published by the A2a network.
enum class FieldAlignedNetworkTerminal : int {
  Open = 0,
  Barrier = 1,
  Singularity = 2,
  Contact = 3,
  LimitCycle = 4
};

/**
 * Display geometry for a published A2a `FieldAlignedCurveNetwork`.
 *
 * Diagnostic only: positions are double approximations of the network's exact
 * points. Nothing here is semantic authority, and no pipeline stage reads it.
 */
struct FieldAlignedNetworkPolylines {
  /// Polyline vertices of every candidate trace, P x 3.
  Eigen::MatrixXd tracePoints;
  /// Consecutive point pairs of each trace polyline, E x 2 rows of tracePoints.
  Eigen::MatrixXi traceEdges;
  /// Candidate-trace ordinal that owns each trace edge, size E.
  Eigen::VectorXi traceEdgeTrace;
  /// `FieldAlignedNetworkTerminal` of the trace that owns each edge, size E.
  Eigen::VectorXi traceEdgeTerminal;

  /// Mandatory source edges (boundary and hard-feature rails), 2M x 3 and M x 2.
  Eigen::MatrixXd mandatoryPoints;
  Eigen::MatrixXi mandatoryEdges;

  /// One point per field singularity, S x 3, and its published index numerator.
  Eigen::MatrixXd singularityPoints;
  Eigen::VectorXi singularityIndex;

  std::size_t traceCount = 0;
  std::size_t segmentCount = 0;
};

/**
 * Converts the network into polylines over the source vertices `V`.
 *
 * Each trace starts at its source vertex, visits every segment's entry point
 * (and its edge-transit exit, when present), and ends at its published
 * terminal: barrier point, singularity vertex, contact point or limit-cycle
 * entry. A trace with no published terminal stays open. Edge points use the
 * edge's first-to-second exact parameter; contact barycentrics follow the
 * face key's sorted vertex order.
 *
 * Throws std::invalid_argument when `V` is not n x 3, when a referenced vertex
 * is outside `V`, when a parameter is outside [0, 1], or when a terminal
 * singularity has no published port.
 */
FieldAlignedNetworkPolylines field_aligned_network_polylines(
    const Eigen::MatrixXd &V, const geometry::FieldAlignedCurveNetwork &network);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_FIELD_ALIGNED_NETWORK_POLYLINES_H
