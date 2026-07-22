// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H
#define DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H

#include <cstddef>
#include <vector>

#include <directional/diagnostics/IntegrationDiagnostics.h>
#include <directional/diagnostics/MesherDiagnostics.h>

namespace directional {

/** @brief Per-component summary for Phase 08 component-level remeshing. */
struct ComponentRemeshDiagnostics {
  std::size_t componentIndex = 0;
  std::size_t minimumOriginalFace = 0;
  std::size_t inputFaceCount = 0;
  std::size_t outputVertexCount = 0;
  std::size_t outputFaceCount = 0;
  bool success = false;
  double wallSeconds = 0.0;
  double integrationSeconds = 0.0;
  double mesherSeconds = 0.0;
};

/** @brief Aggregate machine-readable diagnostics for the remesh pipeline. */
struct RemeshDiagnostics {
  double surfaceCellFeatureSeconds = 0.0;
  double surfaceCellMetricSeconds = 0.0;
  double surfaceCellReliefSeconds = 0.0;
  double surfaceCellTracingSeconds = 0.0;
  double surfaceCellArrangementSeconds = 0.0;
  double surfaceCellSimplificationSeconds = 0.0;
  double surfaceCellCompletionSeconds = 0.0;
  double surfaceCellOptimizationSeconds = 0.0;
  double surfaceCellValidationSeconds = 0.0;

  std::size_t surfaceCellValidationFailures = 0;
  std::size_t surfaceCellProvenanceVertexCount = 0;

  double adaptiveFeatureMapSeconds = 0.0;
  std::size_t adaptiveFeatureHardEdgeCount = 0;
  std::size_t adaptiveFeatureSoftEdgeCount = 0;
  std::size_t adaptiveFeatureBoundaryEdgeCount = 0;
  std::size_t adaptiveFeatureNonManifoldEdgeCount = 0;
  std::size_t adaptiveFeatureCurveCount = 0;
  std::size_t adaptiveFeatureClosedCurveCount = 0;
  double adaptiveFeatureMaxDensity = 0.0;

  double componentSplitSeconds = 0.0;
  double componentParallelWallSeconds = 0.0;
  double componentMergeSeconds = 0.0;
  double preconditioningSeconds = 0.0;
  double tangentBundleInitializationSeconds = 0.0;
  double fieldSetupSeconds = 0.0;
  double principalMatchingSeconds = 0.0;
  double setupIntegrationSeconds = 0.0;
  double integrationTotalSeconds = 0.0;
  double setupMesherSeconds = 0.0;
  double mesherTotalSeconds = 0.0;
  double overallPipelineSeconds = 0.0;

  std::size_t preconditioningFlipsAccepted = 0;
  std::size_t preconditioningCollapsesAccepted = 0;
  std::size_t preconditioningSplitsAccepted = 0;
  std::size_t preconditioningInputTriangleCount = 0;
  std::size_t preconditioningOutputTriangleCount = 0;
  double preconditioningMinAngleBefore = 0.0;
  double preconditioningMinAngleAfter = 0.0;
  double preconditioningAspectRatioP95Before = 0.0;
  double preconditioningAspectRatioP95After = 0.0;
  double preconditioningAspectRatioP99Before = 0.0;
  double preconditioningAspectRatioP99After = 0.0;
  double preconditioningEdgeLengthCvBefore = 0.0;
  double preconditioningEdgeLengthCvAfter = 0.0;

  std::size_t componentCount = 1;
  std::size_t componentThreadsRequested = 1;
  std::size_t componentThreadsUsed = 1;
  std::size_t componentPeakConcurrentTasks = 1;
  std::size_t failedComponentIndex = static_cast<std::size_t>(-1);
  std::size_t failedComponentMinimumOriginalFace = static_cast<std::size_t>(-1);
  std::vector<ComponentRemeshDiagnostics> components;

  IntegrationDiagnostics integration;
  MesherDiagnostics mesher;
};

} // namespace directional

#endif // DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H
