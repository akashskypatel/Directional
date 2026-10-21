// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_SURFACE_CELL_TRACING_DISPLAY_H
#define DIRECTIONAL_VISUALIZATION_SURFACE_CELL_TRACING_DISPLAY_H

#include <directional/diagnostics/RemeshDiagnostics.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <Eigen/Core>

#include <cstddef>
#include <string>
#include <vector>

namespace directional::visualization {

/**
 * Display data for where a SurfaceCells run stopped and, when quad tracing
 * (A4) produced its phase front, the traced cells.
 *
 * Diagnostic only: everything is read from the run's reported failure locus
 * and retained phase front, and no pipeline stage reads it back.
 */
struct SurfaceCellTracingDisplay {
  /// Faces named by the stop, as a small mesh: `stopFaces` index
  /// `stopFaceVertices`; `stopFaceRole` is 0 for the stopping face and 1 for
  /// a related face.
  Eigen::MatrixXd stopFaceVertices;
  Eigen::MatrixXi stopFaces;
  Eigen::VectorXi stopFaceRole;
  /// Source edges named by the stop (2E x 3 points, E x 2 edges).
  Eigen::MatrixXd stopEdgePoints;
  Eigen::MatrixXi stopEdges;
  /// Source vertices named by the stop.
  Eigen::MatrixXd stopVertices;
  /// Stage, reason and locus text, plus any named entity not in the mesh.
  std::vector<std::string> stopNotes;

  /// Boundary-path segments of every traced cell (2S x 3, S x 2) and the
  /// distinct cell corners.
  Eigen::MatrixXd cellPoints;
  Eigen::MatrixXi cellEdges;
  Eigen::MatrixXd cellCorners;
  std::size_t cellCount = 0;

  [[nodiscard]] bool has_stop_location() const {
    return stopFaces.rows() > 0 || stopEdges.rows() > 0 || stopVertices.rows() > 0;
  }
};

/**
 * Reads the run's terminal failure locus and, when present, the retained A4
 * phase front of `traceNetwork`.
 *
 * A rejected phase front adds its failure's face, target face, source vertex
 * and source edges. Its source edges are compact interior-edge indices, the
 * rank of the edge among interior edges sorted by vertex pair, as assigned by
 * the tracer. A produced phase front adds its cells. An injected stop
 * (`InjectedStageFailure`) is a requested stop, so it names no location.
 *
 * Throws std::invalid_argument when `V` is not n x 3 or `F` is not m x 3.
 */
SurfaceCellTracingDisplay surface_cell_tracing_display(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const directional::RemeshDiagnostics &diagnostics,
    const geometry::SurfaceCellNetwork *traceNetwork);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_SURFACE_CELL_TRACING_DISPLAY_H
