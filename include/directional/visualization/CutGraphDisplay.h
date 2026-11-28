// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_CUT_GRAPH_DISPLAY_H
#define DIRECTIONAL_VISUALIZATION_CUT_GRAPH_DISPLAY_H

#include <directional/geometry/GlobalTopologyPlan.h>
#include <directional/geometry/SurfaceCutGraph.h>

#include <Eigen/Core>

#include <cstddef>

namespace directional::visualization {

/// Face label for a face in no topology-plan region.
constexpr int kNoDiscRegion = -1;
/// Face label for a face that traces split among several regions.
constexpr int kSplitDiscRegion = -2;

/**
 * Display data for the A2a' cut graph and the A2b global topology plan.
 *
 * Diagnostic only: read from the published products without
 * reinterpretation; no pipeline stage reads it back.
 */
struct CutGraphDisplay {
  /// Cut-graph edges, 2C x 3 and C x 2.
  Eigen::MatrixXd cutPoints;
  Eigen::MatrixXi cutEdges;

  /// Embedded-graph arcs drawn from their exact source paths, one segment
  /// per path piece, with the arc's kind (0 mandatory, 1 trace, 2 cut) and
  /// ordinal.
  Eigen::MatrixXd arcPoints;
  Eigen::MatrixXi arcEdges;
  Eigen::VectorXi arcKind;
  Eigen::VectorXi arcIndex;

  /// Topology-plan region of each face row, or kNoDiscRegion /
  /// kSplitDiscRegion.
  Eigen::VectorXi faceRegion;

  bool hasCutGraph = false;
  bool hasTopologyPlan = false;
  std::size_t regionCount = 0;
  std::size_t splitFaceCount = 0;
  /// Regions whose certificate proves disc topology / an interior free of
  /// singularities.
  std::size_t discRegionCount = 0;
  std::size_t regularRegionCount = 0;
  std::size_t arcCount = 0;
};

/**
 * Reads either product when present (each pointer may be null).
 *
 * Throws std::invalid_argument when `V` is not n x 3, `F` is not m x 3, or a
 * product names a vertex or face that is not in the mesh.
 */
CutGraphDisplay cut_graph_display(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
                                  const geometry::SurfaceCutGraph *cutGraph,
                                  const geometry::GlobalTopologyPlan *plan);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_CUT_GRAPH_DISPLAY_H
