// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H
#define DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>
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
  std::string terminalFailureCode = "None";
  std::string terminalFailureStage;
  std::string outputOrigin = "None";
  double wallSeconds = 0.0;
  double integrationSeconds = 0.0;
  double mesherSeconds = 0.0;
};

enum class SurfaceCellOutputOrigin {
  None,
  CompletedSurfaceCells,
  LegacyFallback,
  InputMeshFallback,
  Mixed
};

const char *surface_cell_output_origin_name(
    const SurfaceCellOutputOrigin origin);


enum class SurfaceCellConsumptionKind {
  None,
  Full,
  Partial,
  Discontinuous
};

const char *surface_cell_consumption_kind_name(
    const SurfaceCellConsumptionKind kind);

struct SurfaceCellObjectIdentity {
  std::string type;
  std::uint64_t structuralHash = 0U;
  std::size_t elementCount = 0;
};

struct SurfaceCellStageLineage {
  std::string stage;
  SurfaceCellObjectIdentity inputObject;
  SurfaceCellObjectIdentity outputObject;
  std::string inputObjectHash;
  std::string outputObjectHash;
  std::size_t objectCount = 0;
  bool available = false;
  bool consumedByNextStage = false;
  SurfaceCellConsumptionKind consumptionKind = SurfaceCellConsumptionKind::None;
  bool noOp = false;
  std::size_t componentIndex = std::numeric_limits<std::size_t>::max();
  double durationSeconds = 0.0;
  std::string terminalFailureCode = "None";
  std::string terminalFailureStage;
};

/** @brief Aggregate machine-readable diagnostics for the remesh pipeline. */
struct RemeshDiagnostics {
  std::string remeshBackend = "LegacyInteger";
  std::string requestedBackend = "LegacyInteger";
  std::string executedBackend = "LegacyInteger";
  std::string surfaceCellFallbackPolicy = "Fail";
  std::string surfaceCellFallbackCause;
  std::string originalSurfaceCellFailureCode = "None";
  std::string originalSurfaceCellFailureStage;
  std::string terminalFailureCode = "None";
  std::string terminalFailureStage;
  bool surfaceCellFallbackAttempted = false;
  bool surfaceCellUsedLegacyFallback = false;
  bool surfaceCellReturnedInputMeshFallback = false;
  bool surfaceCellRemeshOccurred = false;
  bool surfaceCellSourceGridRecoveryUsed = false;
  bool surfaceCellSourceGridRecoveryTargetSizeRelaxed = false;
  double surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio = 1.0;
  SurfaceCellOutputOrigin surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
  bool surfaceCellDebugArtifactsPreserved = false;
  std::vector<std::string> surfaceCellDebugArtifacts;
  std::vector<SurfaceCellStageLineage> surfaceCellStageLineage;

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
  std::size_t surfaceCellFeatureCount = 0;
  std::size_t surfaceCellMetricSampleCount = 0;
  std::size_t surfaceCellReliefPatchCount = 0;
  std::size_t surfaceCellTraceSegmentCount = 0;
  std::size_t surfaceCellArrangementCellCount = 0;
  std::size_t surfaceCellSimplifiedCellCount = 0;
  std::size_t surfaceCellCompletedQuadCount = 0;
  std::size_t surfaceCellCompletionOwnershipRepairAttempts = 0;
  std::size_t surfaceCellCompletionOwnershipStructuralRepairAttempts = 0;
  std::size_t surfaceCellCompletionOwnershipInsertedBoundaryVertices = 0;
  std::size_t surfaceCellCompletionOwnershipStructuralCandidateBudget = 0;
  std::size_t surfaceCellCompletionOwnershipStructuralCandidatesConsumed = 0;
  std::size_t surfaceCellCompletionOwnershipVisitedStateCount = 0;
  std::size_t surfaceCellCompletionOwnershipFullRecomputationPasses = 0;
  std::size_t surfaceCellCompletionOwnershipIncrementalRecomputationPasses = 0;
  std::size_t surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes = 0;
  std::size_t surfaceCellCompletionOwnershipPeakLiveCandidateComplexes = 0;
  int surfaceCellCompletionOwnershipLastCandidateHalfedge = -1;
  std::vector<int> surfaceCellCompletionOwnershipLastCandidateHalfedges;
  std::vector<int> surfaceCellCompletionOwnershipLastAffectedPatches;
  std::size_t surfaceCellCompletionOwnershipRouteCandidateCount = 0;
  std::uint64_t surfaceCellCompletionOwnershipRollbackOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipCandidateOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipDescriptorOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipCompletedPatchOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipAssemblyOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipCurrentStructuralOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipPeakStructuralOwnedBytes = 0U;
  std::string surfaceCellCompletionOwnershipStructuralExhaustionReason =
      "none";
  bool surfaceCellCompletionOwnershipRejectionAvailable = false;
  std::string surfaceCellCompletionOwnershipFailure;
  int surfaceCellCompletionOwnershipSourcePatch = -1;
  int surfaceCellCompletionOwnershipLocalVertex = -1;
  bool surfaceCellCompletionOwnershipBoundaryVertex = false;
  int surfaceCellCompletionOwnershipBackend = -1;
  int surfaceCellCompletionOwnershipVariant = 0;
  int surfaceCellCompletionOwnershipStoredFace = -1;
  std::array<double, 3> surfaceCellCompletionOwnershipBarycentric{{0.0, 0.0,
                                                                  0.0}};
  int surfaceCellCompletionOwnershipEntityKind = 0;
  int surfaceCellCompletionOwnershipSourceVertex = -1;
  std::array<int, 2> surfaceCellCompletionOwnershipSourceEdge{{-1, -1}};
  std::vector<int> surfaceCellCompletionOwnershipCandidateFaces;
  std::vector<int> surfaceCellCompletionOwnershipPatchFaces;
  int surfaceCellCompletionOwnershipComponent = -1;
  int surfaceCellCompletionOwnershipSheet = -1;
  std::size_t surfaceCellOptimizationIterationCount = 0;
  bool surfaceCellValidationFailureCountAvailable = false;
  bool surfaceCellProvenanceVertexCountAvailable = false;
  bool surfaceCellFeatureCountAvailable = false;
  bool surfaceCellMetricSampleCountAvailable = false;
  bool surfaceCellReliefCountAvailable = false;
  bool surfaceCellTraceCountAvailable = false;
  bool surfaceCellArrangementCountAvailable = false;
  bool surfaceCellSimplifiedCountAvailable = false;
  bool surfaceCellCompletedQuadCountAvailable = false;
  bool surfaceCellCompletionOwnershipRepairAttemptsAvailable = false;
  bool surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable = false;
  bool surfaceCellCompletionOwnershipStructuralLedgerAvailable = false;
  bool surfaceCellOptimizationIterationCountAvailable = false;
  std::vector<std::size_t> faceDegreeHistogram;

  double adaptiveFeatureMapSeconds = 0.0;
  std::size_t adaptiveFeatureHardEdgeCount = 0;
  std::size_t adaptiveFeatureSoftEdgeCount = 0;
  std::size_t adaptiveFeatureBoundaryEdgeCount = 0;
  std::size_t adaptiveFeatureNonManifoldEdgeCount = 0;
  std::size_t adaptiveFeatureCurveCount = 0;
  std::size_t adaptiveFeatureClosedCurveCount = 0;
  double adaptiveFeatureMaxDensity = 0.0;
  double adaptiveTargetSizeSeconds = 0.0;
  double adaptiveTargetSizeResolvedSurfaceError = 0.0;
  double adaptiveTargetSizeMin = 0.0;
  double adaptiveTargetSizeMax = 0.0;
  std::size_t adaptiveTargetSizeFiniteVertexCount = 0;
  std::size_t adaptiveTargetSizeNonFiniteVertexCount = 0;

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
  bool overallPipelineTimeAvailable = false;

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
