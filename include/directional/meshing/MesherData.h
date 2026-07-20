// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_MESHER_DATA_H
#define DIRECTIONAL_MESHING_MESHER_DATA_H

#include <Eigen/Core>
#include <Eigen/Sparse>

#include <directional/diagnostics/MesherDiagnostics.h>
#include <directional/util/Progress.h>


/**
 * @file MesherData.h
 * @brief Container for meshing inputs and outputs.
 *
 * Stores the cut mesh, integrated field data, generated mesh matrices, and mapping arrays exchanged between setup, meshing, and downstream consumers.
 */

namespace directional {

/** @brief Generated-DCEL simplification backend used by NFunctionMesher. */
enum class MesherSimplificationBackend {
  /** Existing Directional generated-arrangement cleanup. */
  Directional,

  /** Experimental TriFlow-style constrained QEM pass on the generated DCEL. */
  TriFlowDCEL
};

/**
 * @brief Inputs and outputs shared by meshing setup and concrete meshers.
 *
 * Stores the cut mesh, integration data, generated mesh vertices/faces/degrees,
 * and maps between generated elements and source mesh elements.
 */
struct MesherData {
  /// Number of functions emitted by integration after symmetry reduction.
  int N = 0;

  /// Compressed vertex-based function values on the original mesh.
  Eigen::VectorXd vertexNFunction;

  /// Maps original mesh function values to cut-mesh function values.
  Eigen::SparseMatrix<double> orig2CutMat;

  /// Exact integer variant of @ref orig2CutMat.
  Eigen::SparseMatrix<int> exactOrig2CutMat;

  /// Cut mesh vertex positions.
  Eigen::MatrixXd cutV;

  /// Cut mesh triangle indices.
  Eigen::MatrixXi cutF;

  /// Indices of integer-valued entries in @ref vertexNFunction.
  Eigen::VectorXi integerVars;

  /// Resolution used when snapping values to exact rational/integer form.
  double exactResolution;

  /// Emits meshing progress logs when true.
  bool verbose;

  /// Optional progress callback invoked by meshing stages.
  ProgressCallback progress;

  /// Optional generated-DCEL simplification backend.
  MesherSimplificationBackend simplificationBackend;

  /// Target vertex ratio for the experimental TriFlow DCEL backend.
  double triFlowDcelTargetVertexRatio;

  /// Target face ratio for the experimental TriFlow DCEL backend.
  double triFlowDcelTargetFaceRatio;

  /// Positional target weight for the experimental TriFlow DCEL backend.
  double triFlowDcelTopologyWeight;

  /// Preserve function-isoline edges in the experimental TriFlow DCEL backend.
  bool triFlowDcelPreserveFunctionEdges;

  /// Preserve original seam/boundary edges in the experimental TriFlow DCEL backend.
  bool triFlowDcelPreserveOriginalBoundaryEdges;

  /// Use the Phase 04 function-skeleton edit plan for safe metadata cleanup.
  bool useFunctionSkeletonCleanup;

  /// Machine-readable diagnostics populated regardless of verbose logging.
  MesherDiagnostics diagnostics;

  MesherData()
      : exactResolution(10e-9), verbose(false),
        simplificationBackend(MesherSimplificationBackend::Directional),
        triFlowDcelTargetVertexRatio(0.95),
        triFlowDcelTargetFaceRatio(0.95), triFlowDcelTopologyWeight(0.1),
        triFlowDcelPreserveFunctionEdges(true),
        triFlowDcelPreserveOriginalBoundaryEdges(true),
        useFunctionSkeletonCleanup(true) {}
  ~MesherData() = default;
};

} // namespace directional

#endif // DIRECTIONAL_MESHING_MESHER_DATA_H
