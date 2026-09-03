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
#include <optional>
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
  SourceGridRecovery,
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

enum class SurfaceCellFeatureOptionRemapIssue {
  None,
  UnassignedHardEdge,
  UnassignedSoftEdge
};

const char *surface_cell_consumption_kind_name(
    const SurfaceCellConsumptionKind kind);

struct SurfaceCellObjectIdentity {
  std::string type;
  std::uint64_t structuralHash = 0U;
  std::size_t elementCount = 0;
};

struct SurfaceCellMemoryOwnershipEvent {
  std::string stage;
  std::string action;
  std::uint64_t logicalPayloadBytes = 0U;
  std::uint64_t retainedCapacityBytes = 0U;
  std::uint64_t simultaneousOwnedBytes = 0U;
};

struct SurfaceCellPeriodicHolonomyDiagnostics {
  int sourceComponent = -1;
  int sourceTopologyRegion = -1;
  int sourceSheet = -1;
  std::vector<int> sourceIsolationSheets;
  int quarterTurnRotation = 0;
  int translationU = 0;
  int translationV = 0;
  std::vector<int> routeTransitionIndices;
  std::vector<std::uint64_t> routeTopologyKeys;
  std::vector<int> cutSourceEdges;
  std::vector<std::uint64_t> cutSourceTopology;
};

struct SurfaceCellVertexTransitStateDiagnostics {
  std::array<std::size_t, 3> sourceFace{};
  int branch = 0;
  std::string outcome;
  std::vector<std::string> representativeDirection;
  std::vector<std::string> incomingDirection;
  std::optional<std::array<std::size_t, 2>> transportEdge;
  std::vector<std::array<std::size_t, 2>> transportPath;
  int composedQuarterTurn = 0;
  bool eligibleForElection = false;
  bool representativeInSector = false;
  bool incomingInSector = false;
};

struct SurfaceCellTraceStepDiagnostics {
  std::array<std::size_t, 3> sourceFace{};
  int branch = 0;
  std::optional<std::array<std::size_t, 2>> incomingCarrier;
  std::string entryParameter;
};

struct SurfaceCellRotationRayDiagnostics {
  std::string kind;
  std::size_t primary = 0U;
  std::size_t secondary = 0U;
  bool secondaryAvailable = true;
  std::size_t arc = 0U;
  std::optional<std::size_t> trace;
  std::string orientation;
  std::optional<std::array<std::size_t, 3>> sourceFace;
  std::optional<std::size_t> fanSlot;
  std::optional<int> originPortOrdinal;
  std::optional<std::size_t> originPortSourceVertex;
};

struct SurfaceCellRotationFanCensusDiagnostics {
  std::vector<SurfaceCellRotationRayDiagnostics> rays;
  std::size_t totalRayCount = 0U;
  bool truncated = false;
};

struct SurfaceCellTraceCutFaceFragmentIncidenceDiagnostics {
  std::size_t trace = 0U;
  std::size_t arc = 0U;
  std::size_t segmentIndex = 0U;
  std::string orientation;
  std::optional<std::array<std::size_t, 2>> incomingCarrier;
  std::array<std::size_t, 2> outgoingCarrier{};
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  bool forwardOrbitDroppedByExteriorFilter = false;
  bool reverseOrbitDroppedByExteriorFilter = false;
};

struct SurfaceCellTraceCutFaceEdgeOrbitEvidenceDiagnostics {
  std::array<std::size_t, 2> sourceEdge{};
  std::vector<std::size_t> orbitIds;
  std::size_t totalOrbitCount = 0U;
  bool truncated = false;
};

struct SurfaceCellTraceCutFaceFragmentOwnerEvidenceDiagnostics {
  std::array<std::size_t, 3> sourceFace{};
  std::optional<std::size_t> localFragmentCount;
  std::size_t ownerCount = 0U;
  std::size_t expectedFragmentCount = 0U;
  std::size_t ownerDeficit = 0U;
  std::size_t traceChordCount = 0U;
  bool chordsCrossInside = false;
  bool localArrangementEvaluated = false;
  std::vector<SurfaceCellTraceCutFaceFragmentIncidenceDiagnostics>
      sharedOwnerChords;
  std::size_t sharedOwnerChordCount = 0U;
  bool sharedOwnerChordsTruncated = false;
};

struct SurfaceCellTraceArcOwnerCensusDiagnostics {
  std::size_t arc = 0U;
  std::optional<std::size_t> trace;
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  bool sharesOrbit = false;
};

struct SurfaceCellTraceTerminalSlitCensusDiagnostics {
  std::size_t trace = 0U;
  bool terminatesInTerminalSlit = false;
};

struct SurfaceCellUncutFaceComponentBoundaryEdgeDiagnostics {
  std::array<std::size_t, 2> sourceEdge{};
  bool otherSideLabeled = false;
  std::size_t labeledFaceOwnerCount = 0U;
  std::string barrierClass;
  std::optional<std::size_t> contributedSeed;
  std::string noSeedReason;
};

struct SurfaceCellUncutFaceComponentSeedCensusDiagnostics {
  std::size_t component = 0U;
  std::size_t faceCount = 0U;
  std::size_t seedCount = 0U;
  std::string seedState;
  std::vector<std::size_t> seedOrbitIds;
  std::size_t seedOrbitCount = 0U;
  bool seedOrbitsTruncated = false;
};

struct SurfaceCellTraceFragmentOwnerEvidenceDiagnostics {
  std::vector<SurfaceCellTraceCutFaceFragmentOwnerEvidenceDiagnostics> faces;
  std::size_t faceCount = 0U;
  bool facesTruncated = false;
  std::vector<SurfaceCellTraceArcOwnerCensusDiagnostics> arcs;
  std::size_t arcCount = 0U;
  bool arcsTruncated = false;
  std::vector<SurfaceCellTraceTerminalSlitCensusDiagnostics> traces;
  std::size_t traceCount = 0U;
  bool tracesTruncated = false;
  std::size_t totalOrbitCount = 0U;
  std::size_t exteriorOrbitCount = 0U;
  std::size_t nonExteriorOrbitCount = 0U;
  std::vector<SurfaceCellUncutFaceComponentSeedCensusDiagnostics> components;
  std::size_t componentCount = 0U;
  bool componentsTruncated = false;
};

struct SurfaceCellFailureLocusDiagnostics {
  std::optional<std::size_t> sourceVertex;
  std::optional<std::array<std::size_t, 2>> sourceEdge;
  std::optional<std::size_t> rail;
  std::optional<std::size_t> singularity;
  std::optional<std::array<std::size_t, 3>> sourceFace;
  std::optional<std::array<std::size_t, 3>> relatedSourceFace;
  std::optional<int> branch;
  std::optional<int> relatedBranch;
  std::optional<std::size_t> topologyRegion;
  std::string networkErrorCondition;
  std::string rotationSystemInconsistencyReason;
  std::string vertexTraceSecondaryParameterFailureReason;
  std::string edgeTraceSecondaryRankFailureReason;
  std::string rotationTraceOrientation;
  std::optional<std::size_t> traceFirstSegment;
  std::optional<std::size_t> traceOnePastLastSegment;
  std::optional<std::array<std::size_t, 2>> traceIncomingCarrier;
  std::optional<std::array<std::size_t, 2>> traceOutgoingCarrier;
  std::string traceSegmentOrientation;
  std::optional<std::size_t> traceSegmentIndex;
  std::optional<bool> traceSegmentIsFirst;
  std::optional<std::size_t> traceSourcePort;
  std::optional<std::size_t> traceBoundCorner;
  std::string traceBoundCornerProvenance;
  std::string traceEntrySupport;
  std::string traceExitSupport;
  std::optional<std::size_t> edgeTraceContactIndex;
  std::optional<std::array<std::size_t, 2>> edgeTraceOtherCarrier;
  std::optional<std::array<std::size_t, 3>> edgeTraceFaceCorners;
  std::optional<std::size_t> arc;
  std::optional<std::size_t> secondArc;
  std::optional<std::size_t> trace;
  std::optional<std::size_t> secondTrace;
  std::optional<std::size_t> fragmentOrbitCount;
  std::optional<std::size_t> tracePieceCount;
  std::optional<std::size_t> expectedFragmentCount;
  std::vector<SurfaceCellTraceCutFaceFragmentIncidenceDiagnostics>
      fragmentIncidences;
  std::size_t fragmentIncidenceCount = 0U;
  bool fragmentIncidencesTruncated = false;
  std::vector<SurfaceCellTraceCutFaceEdgeOrbitEvidenceDiagnostics>
      fragmentEdgeOrbitEvidence;
  std::optional<std::size_t> uncutFaceComponent;
  std::optional<std::size_t> uncutFaceComponentSeedCount;
  std::string uncutFaceComponentSeedState;
  std::string sourceFaceLocusKind;
  std::size_t uncutFaceComponentFaceCount = 0U;
  std::vector<std::array<std::size_t, 3>> uncutFaceComponentFaces;
  bool uncutFaceComponentFacesTruncated = false;
  std::size_t uncutFaceComponentBoundaryEdgeCount = 0U;
  std::vector<SurfaceCellUncutFaceComponentBoundaryEdgeDiagnostics>
      uncutFaceComponentBoundaryEdges;
  bool uncutFaceComponentBoundaryEdgesTruncated = false;
  SurfaceCellTraceFragmentOwnerEvidenceDiagnostics fragmentOwnerEvidence;
  std::optional<SurfaceCellRotationRayDiagnostics> rotationPreviousRay;
  std::optional<SurfaceCellRotationRayDiagnostics> rotationCurrentRay;
  SurfaceCellRotationFanCensusDiagnostics rotationFanCensus;
  std::optional<std::size_t> traceEventIndex;
  std::string traceEventPositionFailureReason;
  std::string traceEventPositionPass;
  std::optional<std::size_t> cutCandidateCount;
  std::optional<std::size_t> nonDiscComponentCount;
  std::optional<std::size_t> remainingAdmissibleEdgeCount;
  std::optional<std::size_t> certificationAttemptIndex;
  std::optional<std::size_t> certificationCutEdgeCount;
  std::optional<int> signedLift;
  std::optional<std::string> parameter;
  std::vector<std::string> exactValues;
  std::vector<std::array<std::size_t, 2>> publishedEdges;
  std::vector<std::array<std::size_t, 3>> publishedFaces;
  std::optional<std::size_t> traceSeedVertex;
  std::optional<std::size_t> traceSeedSingularity;
  std::vector<SurfaceCellTraceStepDiagnostics> traceHistory;
  std::size_t traceHistoryCount = 0U;
  bool traceHistoryTruncated = false;
  std::optional<std::size_t> traceSteps;
  std::optional<std::size_t> traceStepBudget;
  std::optional<std::size_t> traceCombinatorialVisits;
  std::optional<std::size_t> traceCombinatorialVisitAllowance;
  std::string vertexArrivalMode;
  std::optional<bool> barrierAbsorbed;
  std::optional<bool> barrierIncident;
  std::optional<std::size_t> barrierDegree;
  std::optional<std::size_t> transportStarComponentCount;

  // Amendment 22/23 vertex-star transit projection. Exact rationals remain
  // exact reduced strings; no topological value is re-expressed as floating point.
  std::optional<std::array<std::size_t, 3>> vertexStarArrivalFace;
  std::optional<int> vertexStarArrivalBranch;
  std::vector<std::string> vertexStarArrivalRay;
  bool vertexStarArrivalOnRadialRay = false;
  std::optional<std::size_t> vertexStarArrivalRadialRay;
  std::optional<std::size_t> vertexStarProvenanceTrace;
  std::optional<std::size_t> vertexStarProvenanceEvent;
  std::string vertexStarKernelRoute;
  std::string vertexStarState;
  std::size_t vertexStarFanLength = 0U;
  std::size_t vertexStarExactFanLengthBudget = 0U;
  bool vertexStarClosedFan = false;
  std::string vertexStarTruncationReason;
  std::string vertexStarConeAngleDefinition;
  std::vector<std::array<std::size_t, 3>> vertexStarFanFaces;
  std::vector<int> vertexStarFanBranches;
  std::vector<std::size_t> vertexStarFanNextRadialVertices;
  std::vector<std::size_t> vertexStarFanPreviousRadialVertices;
  std::vector<std::array<std::string, 3>> vertexStarSectorExactDPQ;
  std::vector<bool> vertexStarSectorEligibleForElection;
  std::vector<bool> vertexStarSectorContainsContinuation;
  std::vector<bool> vertexStarCandidateRepresentativeInOwnSector;
  std::size_t vertexStarOwnerCardinality = 0U;
  std::optional<std::array<std::size_t, 3>> vertexStarOwnerFace;
  std::optional<int> vertexStarOwnerBranch;
  bool vertexStarOnRadialRay = false;
  std::optional<std::size_t> vertexStarRadialRay;
  std::vector<SurfaceCellVertexTransitStateDiagnostics> vertexTransitStates;
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
  std::string originalSurfaceCellFailureDetailCode = "None";
  SurfaceCellFailureLocusDiagnostics originalSurfaceCellFailureLocus;
  std::string terminalFailureCode = "None";
  std::string terminalFailureStage;
  std::string terminalFailureDetailCode = "None";
  SurfaceCellFailureLocusDiagnostics terminalFailureLocus;
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
  std::uint64_t surfaceCellTracingCurrentOwnedBytes = 0U;
  std::uint64_t surfaceCellTracingPeakOwnedBytes = 0U;
  std::uint64_t surfaceCellFlowRepCurrentOwnedBytes = 0U;
  std::uint64_t surfaceCellFlowRepPeakOwnedBytes = 0U;
  std::uint64_t surfaceCellArrangementCurrentOwnedBytes = 0U;
  std::uint64_t surfaceCellArrangementPeakOwnedBytes = 0U;
  std::uint64_t surfaceCellSimplificationCurrentOwnedBytes = 0U;
  std::uint64_t surfaceCellSimplificationPeakOwnedBytes = 0U;
  std::size_t surfaceCellMaxSimultaneousLiveLargeStructures = 0;
  bool surfaceCellTraceStorageReleasedAfterFlowRep = false;
  bool surfaceCellFlowRepSelectionStorageReleasedAfterSelection = false;
  bool surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement = false;
  std::uint64_t surfaceCellTracingLogicalPayloadBytes = 0U;
  std::uint64_t surfaceCellTracingRetainedCapacityBytes = 0U;
  std::uint64_t surfaceCellFlowRepLogicalPayloadBytes = 0U;
  std::uint64_t surfaceCellFlowRepRetainedCapacityBytes = 0U;
  std::uint64_t surfaceCellArrangementLogicalPayloadBytes = 0U;
  std::uint64_t surfaceCellArrangementRetainedCapacityBytes = 0U;
  std::uint64_t surfaceCellSimplificationLogicalPayloadBytes = 0U;
  std::uint64_t surfaceCellSimplificationRetainedCapacityBytes = 0U;
  std::uint64_t surfaceCellCompletionLogicalPayloadBytes = 0U;
  std::uint64_t surfaceCellCompletionRetainedCapacityBytes = 0U;
  std::uint64_t surfaceCellEstimatedPeakSimultaneousOwnedBytes = 0U;
  std::vector<SurfaceCellMemoryOwnershipEvent>
      surfaceCellMemoryOwnershipTimeline;

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
  std::size_t surfaceCellCompletionOwnershipPreConflictCount = 0;
  std::size_t surfaceCellCompletionOwnershipPostConflictCount = 0;
  std::size_t surfaceCellCompletionOwnershipRetainedConflictCount = 0;
  std::size_t surfaceCellCompletionOwnershipRemovedConflictCount = 0;
  std::size_t surfaceCellCompletionOwnershipIntroducedConflictCount = 0;
  std::size_t surfaceCellCompletionOwnershipConflictComponentCount = 0;
  std::size_t surfaceCellCompletionOwnershipIndependentComponentCount = 0;
  std::size_t surfaceCellCompletionOwnershipReusedPatchCompletions = 0;
  std::size_t surfaceCellCompletionOwnershipRecomputedPatchCompletions = 0;
  std::uint64_t surfaceCellCompletionOwnershipPreConflictInventoryHash = 0U;
  std::uint64_t surfaceCellCompletionOwnershipPostConflictInventoryHash = 0U;
  std::uint64_t surfaceCellCompletionOwnershipConflictFrontierOwnedBytes = 0U;
  std::uint64_t surfaceCellCompletionOwnershipProductCacheOwnedBytes = 0U;
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
  bool surfaceCellCompletionParityScopeFailureAvailable = false;
  int surfaceCellCompletionParityOriginalCell = -1;
  int surfaceCellCompletionParityReplacementCell = -1;
  int surfaceCellCompletionParityHalfedge = -1;
  int surfaceCellCompletionParityTwin = -1;
  int surfaceCellCompletionParitySelectedComponent = -1;
  int surfaceCellCompletionParitySelectedSheet = -1;
  std::vector<int> surfaceCellCompletionParityAvailableComponents;
  std::vector<int> surfaceCellCompletionParityAvailableSheets;
  std::string surfaceCellCompletionParityMutationPhase;
  std::string surfaceCellAuthoritativeProducerDisposition;
  bool surfaceCellUniformPhaseFrontProducerDeclined = false;
  bool surfaceCellPeriodicPhaseFrontProducerDeclined = false;
  bool surfaceCellBoundedDiskPhaseFrontProducerDeclined = false;
  std::size_t surfaceCellTopologyRegionCount = 0U;
  std::size_t surfaceCellInternalIsolationSeamCount = 0U;
  std::size_t surfaceCellConsumedTopologyRegionCount = 0U;
  std::size_t surfaceCellConsumedInternalIsolationSeamCount = 0U;
  std::size_t surfaceCellConsumedPeriodicHolonomyCount = 0U;
  int surfaceCellMaterializedConnectedComponentCount = 0;
  int surfaceCellMaterializedBoundaryLoopCount = 0;
  int surfaceCellMaterializedEulerCharacteristic = 0;
  std::vector<std::uint64_t> surfaceCellTopologyRegionHashes;
  std::vector<int> surfaceCellTopologyRegionEulerCharacteristics;
  std::vector<int> surfaceCellTopologyRegionBoundaryLoopCounts;
  std::vector<std::size_t> surfaceCellTopologyRegionIsolationSheetCounts;
  std::size_t surfaceCellBoundedDiskBoundaryPhaseCount = 0U;
  std::size_t surfaceCellBoundedDiskBoundaryRunCount = 0U;
  std::size_t surfaceCellPolygonalBoundedDiskBoundaryPhaseCount = 0U;
  std::size_t surfaceCellBoundedDiskConstructedChartCount = 0U;
  std::vector<std::uint64_t> surfaceCellBoundedDiskBoundaryPhaseHashes;
  std::vector<SurfaceCellPeriodicHolonomyDiagnostics>
      surfaceCellPeriodicHolonomies;
  bool surfaceCellPeriodicHolonomyAvailable = false;
  int surfaceCellPeriodicHolonomyQuarterTurnRotation = 0;
  int surfaceCellPeriodicHolonomyTranslationU = 0;
  int surfaceCellPeriodicHolonomyTranslationV = 0;
  std::size_t surfaceCellPeriodicHolonomyRouteEdgeCount = 0U;
  std::size_t surfaceCellPeriodicCutEdgeCount = 0U;
  std::string surfaceCellFirstInvalidProducerStage;
  std::string surfaceCellFirstInvalidProducerReason;
  std::string surfaceCellFirstInvalidProducerValidationIssue;
  std::vector<std::string> surfaceCellFinalSourceAuthorityValidationIssues;
  int surfaceCellFirstInvalidProducerCell = -1;
  int surfaceCellFirstInvalidProducerHalfedge = -1;
  int surfaceCellFirstInvalidProducerTwin = -1;
  int surfaceCellFirstInvalidProducerNode = -1;
  int surfaceCellFirstInvalidProducerFace = -1;
  int surfaceCellFirstInvalidProducerVertex = -1;
  int surfaceCellFirstInvalidProducerEdgeFirst = -1;
  int surfaceCellFirstInvalidProducerEdgeSecond = -1;
  std::size_t surfaceCellAggregateIdentityBoundaryCacheRebuildCount = 0U;
  std::size_t surfaceCellUserHardFeatureEdgeRequestedCount = 0U;
  std::size_t surfaceCellUserHardFeatureEdgeRemappedCount = 0U;
  std::size_t surfaceCellUserHardFeatureEdgeUnassignedCount = 0U;
  std::size_t surfaceCellUserSoftFeatureEdgeRequestedCount = 0U;
  std::size_t surfaceCellUserSoftFeatureEdgeRemappedCount = 0U;
  std::size_t surfaceCellUserSoftFeatureEdgeUnassignedCount = 0U;
  SurfaceCellFeatureOptionRemapIssue surfaceCellFeatureOptionFirstIssue =
      SurfaceCellFeatureOptionRemapIssue::None;
  std::array<int, 2> surfaceCellFirstUnassignedFeatureEdge{{-1, -1}};
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
