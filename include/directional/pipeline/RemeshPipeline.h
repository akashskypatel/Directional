// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
#define DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H

#include <chrono>
#include <algorithm>
#include <array>
#include <cmath>
#include <cctype>
#include <cstdint>
#include <future>
#include <iomanip>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/authority/FieldTransportAtlas.h>
#include <directional/diagnostics/RemeshDiagnostics.h>
#include <directional/fields/CrossFieldTransfer.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/AdaptiveTargetSize.h>
#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/GlobalTopologyPlan.h>
#include <directional/geometry/SurfaceCutGraph.h>
#include <directional/geometry/PatchDescriptor.h>
#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/ReliefTopology.h>
#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfaceComplexSimplification.h>
#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/SurfaceOptimizationRailConstraints.h>
#include <directional/geometry/BoundedMeshPreconditioner.h>
#include <directional/validation/SourceAuthoritativeMeshValidator.h>
#include <directional/geometry/MeshComponents.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/integration/Integrate.h>
#include <directional/integration/IntegrationData.h>
#include <directional/integration/IntegrationSolveStrategy.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/meshing/Mesher.h>
#include <directional/meshing/MesherData.h>
#include <directional/meshing/SetupMesher.h>
#include <directional/util/Progress.h>

/**
 * @file RemeshPipeline.h
 * @brief High-level remeshing pipeline API.
 *
 * Exposes convenience functions that convert mesh vertices, faces, and cross-field directions into a remeshed output by running tangent-bundle construction, matching, combing, integration, and meshing.
 */

namespace directional::pipeline {

enum class RemeshBackend {
  LegacyInteger,
  Legacy = LegacyInteger,
  SurfaceCells
};

enum class SurfaceCellFallbackPolicy {
  Fail,
  ReturnInputMesh,
  ReturnQuadDominant [[deprecated("Use ReturnInputMesh.")]] = ReturnInputMesh,
  TryLegacy [[deprecated(
      "Legacy integration fallback is disabled; use Fail.")]] = Fail
};

enum class SurfaceCellFailureCode {
  None,
  InvalidFieldDimensions,
  MissingMatching,
  MissingSingularities,
  InvalidFieldTransportAtlas,
  MissingConfidence,
  UncoveredFaces,
  UnsupportedInput,
  InvalidClassifierOptions,
  InvalidRailTopology,
  EmptyFlowRepNetwork,
  MissingFlowRepCoverageEvidence,
  MissingFlowRepCycleEvidence,
  InvalidFlowRepCoverageEvidence,
  InvalidFlowRepCycleEvidence,
  InvalidFlowRepArcIdentity,
  IncompleteFlowRepProvenance,
  IncompleteFlowRepCycleCoverage,
  FlowRepMandatoryRailLoss,
  InjectedStageFailure,
  NotProductionReady
};

std::string remesh_backend_name(const RemeshBackend backend);

std::string
surface_cell_fallback_policy_name(const SurfaceCellFallbackPolicy policy);

std::string
surface_cell_failure_code_name(const SurfaceCellFailureCode code);

SurfaceCellFailureCode surface_cell_failure_from_flow_rep(
    const geometry::FlowRepSelectionFailureCode code);

std::string normalize_option_token(std::string value);

RemeshBackend parse_remesh_backend(const std::string &value);

SurfaceCellFallbackPolicy
parse_surface_cell_fallback_policy(const std::string &value);

struct SurfaceCellOptions {
  bool enabled = false;
  bool strictValidation = true;
  bool requireMatching = true;
  bool requireSingularities = true;
  bool preserveDebugArtifacts = false;
  /// Retain heavyweight trace, arrangement, simplification, and completion
  /// geometry in SurfaceCellPipelineContext. Disabled by default so production
  /// callers receive scalar diagnostics and lineage without retaining every
  /// consumed stage payload simultaneously.
  bool retainIntermediateGeometry = false;
  /// Proof-fixture mode: skip source-grid recovery when completion returns
  /// only adjacent source-triangle pair boundaries. Pair-boundary-only output
  /// is never accepted as a production remesh; this option exposes that
  /// rejection path directly for tests and diagnostics.
  bool rejectPairedSourceTriangleBoundaryOutput = false;
  /// Prefer a uniquely identifiable field-aligned source-cell layout when it
  /// is available. Candidate source-triangle pairs identify cells only; each
  /// accepted cell is refined into four new quads using source-edge midpoints
  /// and a source-surface center. Ambiguous or incomplete source-cell matching
  /// leaves general patch completion authoritative.
  bool allowSourceGridRecovery = false;
  /// Maximum factor by which the topology-constrained source-grid recovery
  /// may relax the requested final edge size. Recovery has fixed connectivity;
  /// requests outside this bound remain visible as validation failures.
  double maxSourceGridRecoveryTargetRelaxation = 2.0;
  bool useSkeletonHints = false;
  /// Performance is a closeout/benchmark disposition by default, not a mesh
  /// validity invariant. Enable this only when a caller intentionally wants a
  /// slow but otherwise valid optimization to fail the backend request.
  bool enforceOptimizerTimeGate = false;
  double maxOptimizerTimeRatio = 0.25;
  int optimizerMaxIterations = 32;
  int optimizerMaxLineSearchTrials = 24;
  SurfaceCellFallbackPolicy fallbackPolicy = SurfaceCellFallbackPolicy::Fail;
  int injectFailureAfterStage = -1;
  /// Optional component-local injection target used by deterministic
  /// component-execution tests. -1 applies the injection to every component.
  int injectFailureComponentIndex = -1;
  double geometricTolerance = 1.0e-9;
  geometry::AdaptiveFeatureMapOptions featureMap;
  geometry::AdaptiveTargetSizeOptions targetSize;
  geometry::LocalThicknessOptions thickness;
  geometry::ReliefOptions relief;
  geometry::ReliefRootSelectionOptions reliefRoots;
  /// Scale-invariant local-sheet classifier policy. Invalid numeric ranges
  /// fail at source classification rather than silently changing charts.
  geometry::SourceSurfaceClassifierOptions sourceClassifier;
};

/**
 * @brief User-tunable parameters for the high-level remeshing pipeline.
 */
struct RemeshOptions {
  /// Target edge-length ratio passed to integration/meshing.
  double lengthRatio = 0.02;

  /// Whether integration should enforce integral seamlessness.
  bool integralSeamless = true;

  /// Whether seam values should be rounded during integration.
  bool roundSeams = false;

  /// Enables shared adaptive feature-map behavior for feature-aware consumers.
  bool featureAlign = false;

  /// Emits per-stage timing logs when true.
  bool verbose = false;

  /// Normalizes supplied direction vectors after tangent projection.
  bool normalizeDirections = true;

  /// Enables the experimental TriFlow-style generated-DCEL simplification pass.
  bool useTriFlowDcelSimplification = false;

  /// Enables the Phase 04 function-skeleton edit plan for safe mesher cleanup.
  bool useFunctionSkeletonCleanup = true;

  /// Enables Phase 05 local patch prevalidation before low-valence mutation.
  bool useLocalPatchPrevalidation = true;

  /// Enables Phase 06 local patch quadrangulation fallback. Disabled by
  /// default until non-trigger overhead and reinsertion behavior are stable.
  bool useLocalPatchQuadrangulationFallback = false;

  /// Enables Phase 07 bounded input triangle-mesh preconditioning.
  bool preconditionInputMesh = false;

  /// Target/preferred face-count ratio for input preconditioning.
  double preconditionTargetFaceRatio = 1.0;

  /// Maximum allowed face-count ratio for input preconditioning.
  double preconditionMaxFaceRatio = 1.05;

  /// Minimum allowed face-count ratio for input preconditioning.
  double preconditionMinFaceRatio = 0.95;

  /// Dihedral angle threshold for protected feature edges.
  double preconditionSharpAngleDegrees = 45.0;

  /// Shared adaptive feature-map options for Phase 11 feature consumers.
  geometry::AdaptiveFeatureMapOptions featureMap;

  /// Enables Phase 08 component-level parallel remeshing. Disabled by default.
  bool parallelizeComponents = false;

  /// Maximum component worker tasks. 0 selects hardware concurrency.
  int maxComponentThreads = 0;

  /// Internal absolute target length override used for component remeshing.
  double absoluteTargetLength = -1.0;

  /// Selects the remeshing backend. SurfaceCells is explicit experimental.
  RemeshBackend backend = RemeshBackend::LegacyInteger;

  /// Options for the default-off surface-cell backend scaffold.
  SurfaceCellOptions surfaceCells;

  /// Integration KKT solve strategy. DirectOnly remains the default reference.
  IntegrationSolveStrategy integrationSolveStrategy =
      IntegrationSolveStrategy::DirectOnly;

  /// Controls for the adaptive integration solve strategy.
  AdaptiveIntegrationOptions adaptiveIntegration;

  /// Controls mixed-integer rounding batch selection.
  IntegerBatchOptions integerBatching;

  /// Controls diagnostic/experimental integer transition basis reduction.
  IntegerTransitionBasisOptions integerTransitionBasis;

  /// Enables Phase 09 targeted parametrization stiffening. Disabled by default
  /// until benchmark gates justify making it default-on.
  bool useTargetedParametrizationStiffening = false;

  /// Controls the default-off targeted parametrization stiffening pass.
  TargetedStiffeningOptions targetedStiffening;

  /// Stops after field integration and returns integration diagnostics only.
  bool stopAfterIntegration = false;

  /// Skips QR constraint rank reduction for explicit benchmark probes.
  bool skipConstraintRankReduction = false;

  /// Optional progress callback invoked by remeshing stages.
  ProgressCallback progress;

  /// Optional benchmark hook invoked after setup_mesher prepares MesherData.
  std::function<void(const MesherData &)> mesherDataCallback;
};

struct SurfaceCellContextProductDebug {
  std::string name;
  std::string type;
  std::uint64_t structuralHash = 0U;
  std::size_t elementCount = 0U;
  bool available = false;
};

/**
 * @brief Diagnostic-only snapshots of stage products.
 *
 * These copies are one-way observation payloads. Production consumers must
 * use the declared stage products instead of reading these snapshots back as
 * semantic authority.
 */
struct SurfaceCellDiagnosticProductSnapshots {
  fields::CrossFieldResult crossField;
  bool hasCrossField = false;

  std::optional<authority::FieldTransportAtlas> fieldTransportAtlas;
  std::optional<authority::FieldAtlasBuildError> fieldTransportAtlasError;
  std::optional<geometry::FieldAlignedCurveNetwork> fieldAlignedCurveNetwork;
  std::optional<geometry::SurfaceCutGraph> surfaceCutGraph;
  std::optional<geometry::GlobalTopologyPlan> globalTopologyPlan;

  std::vector<geometry::SurfaceCellRail> authoritativeRails;
  bool hasAuthoritativeRails = false;

  geometry::SourceSurfaceLabels sourceSurfaceLabels;
  bool hasSourceSurfaceLabels = false;
  std::optional<geometry::SourceTopologyRegions> sourceTopologyRegions;

  geometry::SurfaceCellNetwork traceNetwork;
  std::vector<geometry::FlowRepArc> flowRepArcs;
  geometry::FlowRepSparseNetwork flowRepNetwork;
  std::vector<geometry::SurfaceArrangementArc> embeddedArrangementArcs;
  geometry::SurfaceCellComplex arrangement;

  std::vector<geometry::PureQuadMesh> completedPatches;
  geometry::PureQuadOutputLineageValidation outputLineageValidation;

  bool sourceGridRecoveryUsed = false;
  Eigen::VectorXd sourceGridRecoveryTargetSize;
  bool hasSourceGridRecoveryTargetSize = false;
  bool sourceGridRecoveryTargetSizeRelaxed = false;
  double sourceGridRecoveryTargetSizeMaxRelaxationRatio = 1.0;

  geometry::SurfaceOptimizationResult optimizationResult;
  bool hasOptimizationResult = false;
  geometry::SurfaceFinalValidationReport validationResult;
  bool hasValidationResult = false;
};

/**
 * @brief Diagnostic-only surface-cell observation context.
 *
 * This type must not carry semantic stage authority. Product-shaped members
 * are snapshots for diagnostics, retention, and benchmark observation only.
 */
struct SurfaceCellPipelineContext {
  SurfaceCellDiagnosticProductSnapshots productSnapshots;

  TriMesh sourceMesh;
  bool hasSourceMesh = false;

  bool crossFieldHasMatching = false;
  bool crossFieldHasSingularities = false;

  geometry::AdaptiveFeatureMap featureMap;
  bool hasFeatureMap = false;



  geometry::AdaptiveTargetSizeResult metricField;
  bool hasMetricField = false;

  geometry::ReliefTopologyResult reliefResult;
  bool hasReliefResult = false;

  geometry::ReliefRootSelectionResult reliefRootSelection;
  bool hasReliefRootSelection = false;
  std::set<authority::SourceEdgeTopologyKey> reliefBarrierEdges;
  bool hasReliefBarrierEdges = false;



  bool hasTraceNetwork = false;
  /// Diagnostic proof of the production A2a cutover; semantic authority lives
  /// in the declared FieldAlignedCurveNetwork product, never these booleans.
  bool fieldAlignedNetworkAuthorityUsed = false;
  bool rawSingularityProjectionUsed = false;
  std::uint64_t tracingCurrentOwnedBytes = 0U;
  std::uint64_t tracingPeakOwnedBytes = 0U;
  bool traceStorageReleasedAfterFlowRep = false;

  bool flowRepEndpointCompletionAttempted = false;
  int flowRepOpenEndpointsBeforeCompletion = 0;
  int flowRepResolvedEndpoints = 0;
  int flowRepUnresolvedEndpoints = 0;
  int flowRepUnresolvedRequiredEndpoints = 0;
  int flowRepEndpointCompletionAddedArcs = 0;
  std::array<int, 9> flowRepEndpointTerminationCounts{};
  std::vector<geometry::FlowRepEndpointCompletionDiagnostic>
      flowRepEndpointDiagnostics;
  std::string flowRepEndpointCompletionFailure;
  bool hasFlowRepNetwork = false;
  std::uint64_t flowRepCurrentOwnedBytes = 0U;
  std::uint64_t flowRepPeakOwnedBytes = 0U;
  bool flowRepSelectionStorageReleasedAfterSelection = false;

  bool hasEmbeddedArrangementArcs = false;

  bool hasArrangement = false;
  std::uint64_t arrangementCurrentOwnedBytes = 0U;
  std::uint64_t arrangementPeakOwnedBytes = 0U;
  bool embeddedArrangementStorageReleasedAfterArrangement = false;
  std::uint64_t tracingLogicalPayloadBytes = 0U;
  std::uint64_t tracingRetainedCapacityBytes = 0U;
  std::uint64_t flowRepLogicalPayloadBytes = 0U;
  std::uint64_t flowRepRetainedCapacityBytes = 0U;
  std::uint64_t arrangementLogicalPayloadBytes = 0U;
  std::uint64_t arrangementRetainedCapacityBytes = 0U;
  std::uint64_t simplificationLogicalPayloadBytes = 0U;
  std::uint64_t simplificationRetainedCapacityBytes = 0U;
  std::uint64_t completionLogicalPayloadBytes = 0U;
  std::uint64_t completionRetainedCapacityBytes = 0U;
  std::uint64_t estimatedPeakSimultaneousOwnedBytes = 0U;
  std::vector<SurfaceCellMemoryOwnershipEvent> memoryOwnershipTimeline;

  geometry::SurfaceCellComplex simplifiedComplex;
  bool hasSimplifiedComplex = false;
  int simplificationCandidateCount = 0;
  int simplificationTopologyHealingCandidateCount = 0;
  int simplificationCommitted = 0;
  int simplificationRejected = 0;
  int simplificationGeneratedCandidates = 0;
  int simplificationDeduplicatedCandidates = 0;
  int simplificationInvalidatedCandidates = 0;
  int simplificationStaleGenerationCandidates = 0;
  int simplificationFrontierGenerations = 0;
  int simplificationPeakLiveCandidates = 0;
  double simplificationEvaluatedCandidates = 0.0;
  std::vector<geometry::SurfaceSimplificationCandidate>
      simplificationTopologyHealingCandidates;
  std::vector<geometry::SurfaceSimplificationTransaction>
      simplificationTransactions;
  bool hasSimplificationDiagnostics = false;
  std::uint64_t simplificationCurrentOwnedBytes = 0U;
  std::uint64_t simplificationPeakOwnedBytes = 0U;
  int maxSimultaneousLiveLargeStructures = 0;

  geometry::SurfaceCellComplex completionComplex;
  bool hasCompletionComplex = false;
  int completionOddCellsBeforeRepair = 0;
  int completionOddCellsAfterRepair = 0;
  int completionParitySplitEdges = 0;
  int completionParityHardFeatureSplits = 0;
  int completionParityAlternativeCandidateBudget = 0;
  int completionParityAlternativeCandidatesAttempted = 0;
  int completionParityAlternativeVisitedStates = 0;
  int completionParityAlternativeSelectedExclusion = -1;
  std::uint64_t completionParityAlternativeStateSequenceHash = 0U;
  geometry::SurfaceCellParityAlternativeDisposition
      completionParityAlternativeDisposition =
          geometry::SurfaceCellParityAlternativeDisposition::None;
  int completionSideInfeasibleBeforeRepair = 0;
  int completionSideInfeasibleAfterRepair = 0;
  int completionSideInitialEquationDefect = 0;
  int completionSideFinalEquationDefect = 0;
  int completionSidePropagationPasses = 0;
  int completionSideAttemptedInsertions = 0;
  int completionSideInsertedVertices = 0;
  int completionSideSplitEdges = 0;
  int completionSideHardFeatureSplits = 0;
  bool completionSideRollbackEquivalent = false;
  std::uint64_t completionSideRollbackIdentityHashBefore = 0U;
  std::uint64_t completionSideRollbackIdentityHashAfter = 0U;
  std::uint64_t completionSideRollbackUndoOwnedBytes = 0U;
  int completionAttemptedPatches = 0;
  int completionFailedPatches = 0;
  int completionOwnershipRepairAttempts = 0;
  int completionTemplateInitialConflictCount = 0;
  int completionTemplateFinalConflictCount = 0;
  int completionTemplateConflictComponentCount = 0;
  int completionTemplateChangedPatchCount = 0;
  int completionTemplateAssemblyPasses = 0;
  int completionOwnershipStructuralRepairAttempts = 0;
  int completionOwnershipInsertedBoundaryVertices = 0;
  int completionOwnershipStructuralCandidateBudget = 0;
  int completionOwnershipStructuralCandidatesConsumed = 0;
  int completionOwnershipVisitedStateCount = 0;
  int completionOwnershipFullRecomputationPasses = 0;
  int completionOwnershipIncrementalRecomputationPasses = 0;
  int completionOwnershipPreConflictCount = 0;
  int completionOwnershipPostConflictCount = 0;
  int completionOwnershipRetainedConflictCount = 0;
  int completionOwnershipRemovedConflictCount = 0;
  int completionOwnershipIntroducedConflictCount = 0;
  int completionOwnershipConflictComponentCount = 0;
  int completionOwnershipIndependentComponentCount = 0;
  int completionOwnershipReusedPatchCompletions = 0;
  int completionOwnershipRecomputedPatchCompletions = 0;
  int completionOwnershipProductCacheHashMisses = 0;
  int completionOwnershipProductCacheExactMismatches = 0;
  std::uint64_t completionOwnershipPreConflictInventoryHash = 0U;
  std::uint64_t completionOwnershipPostConflictInventoryHash = 0U;
  std::uint64_t completionOwnershipConflictFrontierOwnedBytes = 0U;
  std::uint64_t completionOwnershipProductCacheOwnedBytes = 0U;
  int completionOwnershipCurrentLiveCandidateComplexes = 0;
  int completionOwnershipPeakLiveCandidateComplexes = 0;
  int completionOwnershipLastCandidateHalfedge = -1;
  std::vector<int> completionOwnershipLastCandidateHalfedges;
  std::vector<int> completionOwnershipLastAffectedPatches;
  int completionOwnershipRouteCandidateCount = 0;
  std::uint64_t completionOwnershipRollbackOwnedBytes = 0U;
  std::uint64_t completionOwnershipCandidateOwnedBytes = 0U;
  std::uint64_t completionOwnershipDescriptorOwnedBytes = 0U;
  std::uint64_t completionOwnershipCompletedPatchOwnedBytes = 0U;
  std::uint64_t completionOwnershipAssemblyOwnedBytes = 0U;
  std::uint64_t completionOwnershipCurrentStructuralOwnedBytes = 0U;
  std::uint64_t completionOwnershipPeakStructuralOwnedBytes = 0U;
  geometry::SurfaceCellStructuralRepairExhaustionReason
      completionOwnershipStructuralExhaustionReason =
          geometry::SurfaceCellStructuralRepairExhaustionReason::None;
  std::vector<geometry::SurfaceCellOwnershipRepairAttempt>
      completionOwnershipRepairLog;
  geometry::PureQuadCompletionOwnershipRejection
      firstCompletionOwnershipRejection;
  geometry::PureQuadEmbeddingFailure firstCompletionEmbeddingFailure;
  std::string completionFailure;
  geometry::SurfaceCellDomainIdentityAudit completionDomainIdentityAudit;
  bool hasCompletionDomainIdentityAudit = false;
  geometry::SurfaceCellReplacementScopeFailure completionParityScopeFailure;
  bool hasCompletionParityScopeFailure = false;
  std::vector<geometry::PatchCompletionReuseMismatch>
      completionOwnershipProductCacheMismatchVector;

  std::vector<geometry::PatchDescriptor> patchDescriptors;
  std::vector<int> completionUnresolvedSingularVertices;
  bool hasPatchDescriptors = false;

  Eigen::MatrixXd completedVertices;
  Eigen::MatrixXi completedQuads;
  std::vector<geometry::SurfacePoint> completedProvenance;
  std::vector<geometry::PureQuadVertexLineage> completedVertexLineage;
  std::vector<geometry::PureQuadFaceLineage> completedQuadLineage;
  bool hasCompletedPatches = false;



  // Final disconnected-aggregate source-authoritative oracle evidence is
  // independent of whether every component published a legacy aggregate
  // validation report. This distinguishes "oracle ran and passed" from
  // "oracle result unavailable" without fabricating incomplete aggregate
  // quality metrics.
  validation::SourceAuthoritativeMeshValidationResult
      finalSourceAuthorityValidationResult;
  bool hasFinalSourceAuthorityValidationResult = false;
  bool componentValidationReportsComplete = false;

  std::vector<SurfaceCellContextProductDebug> debugProducts;
};
/**
 * @brief Closed semantic payload produced by the remeshing pipeline.
 */
struct RemeshProduct {
  /// Generated output vertex positions.
  Eigen::MatrixXd vertices;

  /// Degree/valence metadata for generated vertices.
  Eigen::VectorXi degrees;

  /// Generated output faces.
  Eigen::MatrixXi faces;

  /// Vertices of the cut source mesh used for integration.
  Eigen::MatrixXd cutVertices;

  /// Faces of the cut source mesh used for integration.
  Eigen::MatrixXi cutFaces;

  /// Integrated N-function values on the cut mesh.
  Eigen::MatrixXd cutFunctions;

  /// Integrated N-function values at cut-mesh corners.
  Eigen::MatrixXd cutCornerFunctions;

  /// Source-surface provenance for generated output vertices.
  std::vector<directional::geometry::SurfacePoint> outputVertexProvenance;
  std::vector<directional::geometry::PureQuadVertexLineage> outputVertexLineage;
  std::vector<directional::geometry::PureQuadFaceLineage> outputQuadLineage;

  /// Ordered #F-by-12 cross field consumed by integration.
  Eigen::MatrixXd rawCrossField;

  /// Principal rotational matching across source-mesh edges.
  Eigen::VectorXi crossFieldMatching;

  /// Parallel-transport deviation across source-mesh edges.
  Eigen::VectorXd crossFieldEffort;

  /// Source-mesh local cycles containing cross-field singularities.
  Eigen::VectorXi crossFieldSingularCycles;

  /// Integer singularity numerators; actual indices are divided by four.
  Eigen::VectorXi crossFieldSingularIndices;
};

enum class RemeshProductKind {
  Meshed,
  IntegrationOnly,
  InputMeshFallback
};

struct RemeshPublishedProduct {
  RemeshProduct output;
  RemeshProductKind kind = RemeshProductKind::Meshed;
  bool crossFieldAccepted = false;
};

enum class RemeshFailureKind {
  None,
  SurfaceCellRejected,
  MesherRejected,
  ComponentRejected,
  Exception
};

struct RemeshFailure {
  RemeshFailureKind kind = RemeshFailureKind::None;
  SurfaceCellFailureCode surfaceCellFailure = SurfaceCellFailureCode::None;
  std::string stage;
  bool crossFieldAccepted = false;
};

/**
 * @brief Closed remeshing outcome plus diagnostic-only observation channels.
 */
class RemeshResult {
public:
  using Product = RemeshPublishedProduct;
  using Failure = RemeshFailure;
  using Outcome =
      geometry::ProducerOutcome<Product, Failure>;

  RemeshResult() = default;
  RemeshResult(const RemeshResult &) = default;
  RemeshResult(RemeshResult &&) noexcept = default;
  RemeshResult &operator=(const RemeshResult &) = default;
  RemeshResult &operator=(RemeshResult &&) noexcept = default;

  [[nodiscard]] static RemeshResult produced(
      RemeshProduct output, RemeshProductKind kind, bool crossFieldAccepted,
      SurfaceCellPipelineContext diagnosticsContext = {},
      directional::RemeshDiagnostics diagnostics = {}) {
    if (kind != RemeshProductKind::IntegrationOnly &&
        (output.vertices.rows() == 0 || output.faces.rows() == 0)) {
      throw std::invalid_argument(
          "Produced remesh outcome requires a nonempty output mesh.");
    }
    Product product;
    product.output = std::move(output);
    product.kind = kind;
    product.crossFieldAccepted = crossFieldAccepted;
    return RemeshResult(
        Outcome{geometry::Produced<Product>{
            std::move(product)}},
        std::move(diagnosticsContext), std::move(diagnostics));
  }

  [[nodiscard]] static RemeshResult rejected(
      Failure failure, SurfaceCellPipelineContext diagnosticsContext = {},
      directional::RemeshDiagnostics diagnostics = {}) {
    if (failure.kind == RemeshFailureKind::None) {
      throw std::invalid_argument(
          "Rejected remesh outcome requires a typed failure.");
    }
    return RemeshResult(
        Outcome{geometry::Rejected<Failure>{
            std::move(failure)}},
        std::move(diagnosticsContext), std::move(diagnostics));
  }

  [[nodiscard]] bool is_produced() const noexcept {
    return std::holds_alternative<
        geometry::Produced<Product>>(outcome_);
  }
  [[nodiscard]] bool is_rejected() const noexcept {
    return std::holds_alternative<
        geometry::Rejected<Failure>>(outcome_);
  }
  [[nodiscard]] bool is_not_applicable() const noexcept {
    return std::holds_alternative<
        geometry::NotApplicable>(outcome_);
  }
  [[nodiscard]] Product *produced_product() noexcept {
    auto *produced = std::get_if<
        geometry::Produced<Product>>(&outcome_);
    return produced == nullptr ? nullptr : &produced->product;
  }
  [[nodiscard]] const Product *produced_product() const noexcept {
    const auto *produced = std::get_if<
        geometry::Produced<Product>>(&outcome_);
    return produced == nullptr ? nullptr : &produced->product;
  }
  [[nodiscard]] RemeshProduct &product() & {
    return std::get<
               geometry::Produced<Product>>(
               outcome_)
        .product.output;
  }
  [[nodiscard]] const RemeshProduct &product() const & {
    return std::get<
               geometry::Produced<Product>>(
               outcome_)
        .product.output;
  }
  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<
        geometry::Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }
  [[nodiscard]] bool cross_field_accepted() const noexcept {
    if (const Product *product = produced_product()) {
      return product->crossFieldAccepted;
    }
    if (const Failure *failure = rejection()) {
      return failure->crossFieldAccepted;
    }
    return false;
  }
  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }
  [[nodiscard]] Outcome &&outcome() && noexcept { return std::move(outcome_); }

  /// Diagnostic-only surface-cell snapshots and counters.
  SurfaceCellPipelineContext surfaceCellContext;

  /// Runtime diagnostics and timing measurements.
  directional::RemeshDiagnostics diagnostics;

private:
  RemeshResult(Outcome outcome, SurfaceCellPipelineContext diagnosticsContext,
               directional::RemeshDiagnostics diagnosticsValue)
      : surfaceCellContext(std::move(diagnosticsContext)),
        diagnostics(std::move(diagnosticsValue)), outcome_(std::move(outcome)) {}

  Outcome outcome_;
};

/** Compile-visible result of explicit constructive-front quotient assembly. */
struct AuthoritativePhaseFrontMeshResult {
  bool success = false;
  int invalidCell = -1;
  int invalidEdge = -1;
  int connectedComponents = 0;
  int boundaryLoopCount = 0;
  int eulerCharacteristic = 0;
  std::size_t consumedTopologyRegions = 0U;
  std::size_t consumedInternalIsolationSeams = 0U;
  std::size_t consumedPeriodicHolonomies = 0U;
  std::string failure;
  geometry::PureQuadMesh mesh;
};

AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const geometry::SurfacePhaseFrontProduct &phaseFront);

using RemeshPipelineClock = std::chrono::steady_clock;

double remesh_elapsed_seconds(
    const RemeshPipelineClock::time_point start);

void set_overall_pipeline_time(
    RemeshResult &result, const RemeshPipelineClock::time_point start);

void copy_adaptive_feature_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::BoundedMeshPreconditionerResult &preconditioned);

void copy_adaptive_feature_map_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::AdaptiveFeatureMap &featureMap);

void copy_adaptive_target_size_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::AdaptiveTargetSizeResult &targetSize);

/**
 * @brief Compatibility wrapper for tangent projection.
 * @see directional::fields::project_tangent
 */
Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &vector,
                                          const Eigen::RowVector3d &normal,
                                          const bool normalize);

/**
 * @brief Compatibility wrapper for constructing a raw 4-RoSy field.
 * @see directional::fields::make_raw_cross_field
 */
Eigen::MatrixXd
make_raw_cross_field(const TriMesh &mesh,
                     const Eigen::MatrixXd &primaryDirections,
                     const Eigen::MatrixXd &secondaryDirections,
                     const bool normalizeDirections);

/**
 * @brief Compatibility wrapper for constructing the second cross axis.
 * @see directional::fields::orthogonal_complement
 */
Eigen::MatrixXd
orthogonal_complement(const TriMesh &mesh,
                      const Eigen::MatrixXd &primaryDirections,
                      const bool normalizeDirections);


void hash_combine_u64(std::uint64_t &seed, const std::uint64_t value);

void hash_combine_i64(std::uint64_t &seed, const std::int64_t value);

void hash_combine_double(std::uint64_t &seed, const double value);

void hash_combine_string(std::uint64_t &seed, const std::string &value);

std::uint64_t structural_hash_seed(const std::string &type);

void hash_matrix(std::uint64_t &seed, const Eigen::MatrixXd &matrix);

void hash_matrix(std::uint64_t &seed, const Eigen::MatrixXi &matrix);

void hash_vector(std::uint64_t &seed, const Eigen::VectorXd &values);

void hash_vector(std::uint64_t &seed, const std::vector<int> &values);


void hash_row_vector(std::uint64_t &seed, const Eigen::RowVector3d &v);

void hash_surface_point(std::uint64_t &seed,
                               const geometry::SurfacePoint &point);

std::uint64_t hash_feature_map(
    const geometry::AdaptiveFeatureMap &map);

void hash_trace_segment(std::uint64_t &seed,
                               const geometry::SurfaceTraceSegment &segment);

void hash_trace_point(std::uint64_t &seed,
                             const geometry::SurfaceTracePoint &point);

std::uint64_t hash_trace_network(
    const geometry::SurfaceCellNetwork &network);

std::uint64_t hash_sparse_network(
    const geometry::FlowRepSparseNetwork &network);

std::uint64_t hash_flow_rep_selection_input(
    const geometry::FlowRepSelectionInput &input);

std::uint64_t hash_arrangement_arcs(
    const std::vector<geometry::SurfaceArrangementArc> &arcs);

std::uint64_t hash_surface_complex(
    const geometry::SurfaceCellComplex &complex);

std::uint64_t hash_completion_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const std::vector<geometry::SurfacePoint> &provenance);

std::uint64_t hash_completion(const geometry::PureQuadMesh &mesh);
void hash_vector(std::uint64_t &seed, const Eigen::VectorXi &values);

std::uint64_t hash_relief_topology(
    const geometry::ReliefTopologyResult &topology);

std::string structural_hash_string(const std::uint64_t hash);

SurfaceCellObjectIdentity make_surface_cell_identity(
    const std::string &type, const std::uint64_t hash,
    const std::size_t elementCount);

std::string surface_cell_identity_label(
    const SurfaceCellObjectIdentity &identity);

void normalize_surface_cell_cross_field_directions(
    fields::CrossFieldResult &crossField);

fields::CrossFieldResult make_surface_cell_cross_field_context(
    const Eigen::MatrixXd &rawCrossField);

fields::CrossFieldResult finalize_surface_cell_raw_cross_field(
    const TriMesh &meshWhole, const Eigen::MatrixXd &rawCrossField);
authority::SourceEdgeTopologyKey surface_cell_source_edge_key(
    int a, int b, std::size_t vertexExtent);

bool cross_field_transitions_match_source_edges(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField);

SurfaceCellFailureCode validate_surface_cell_cross_field(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const SurfaceCellOptions &options);

int surface_cell_local_edge_index(const Eigen::MatrixXi &faces,
                                         const int face, const int a,
                                         const int b);

geometry::SurfaceCellRailSample make_surface_cell_rail_sample(
    const TriMesh &meshWhole, const int face, const int a, const int b,
    const double t, const double railParameter);

bool surface_cell_feature_edge_is_rail(
    const geometry::AdaptiveFeatureEdge &edge);

struct SurfaceCellRailBuildProduct {
  std::vector<geometry::SurfaceCellRail> rails;
};

enum class SurfaceCellRailBuildFailureKind {
  None,
  InvalidFeatureEdge,
  InvalidRailIntervals
};

struct SurfaceCellRailBuildFailure {
  SurfaceCellRailBuildFailureKind kind = SurfaceCellRailBuildFailureKind::None;
  int failedEdgeIndex = -1;
  int failedRailId = -1;
  int failedIntervalIndex = -1;
  geometry::surface_cell_tracing_detail::RailBuildStatus validationStatus =
      geometry::surface_cell_tracing_detail::RailBuildStatus::Valid;
};

class SurfaceCellRailBuildResult {
public:
  using Product = SurfaceCellRailBuildProduct;
  using Failure = SurfaceCellRailBuildFailure;
  using Outcome =
      geometry::ProducerOutcome<Product, Failure>;

  SurfaceCellRailBuildResult() = default;

  [[nodiscard]] static SurfaceCellRailBuildResult produced(Product product) {
    return SurfaceCellRailBuildResult(
        Outcome{geometry::Produced<Product>{
            std::move(product)}});
  }
  [[nodiscard]] static SurfaceCellRailBuildResult rejected(Failure failure) {
    if (failure.kind == SurfaceCellRailBuildFailureKind::None) {
      throw std::invalid_argument(
          "Rejected rail-build outcome requires a typed failure.");
    }
    return SurfaceCellRailBuildResult(
        Outcome{geometry::Rejected<Failure>{
            std::move(failure)}});
  }
  [[nodiscard]] bool is_produced() const noexcept {
    return std::holds_alternative<
        geometry::Produced<Product>>(outcome_);
  }
  [[nodiscard]] bool is_rejected() const noexcept {
    return std::holds_alternative<
        geometry::Rejected<Failure>>(outcome_);
  }
  [[nodiscard]] bool is_not_applicable() const noexcept {
    return std::holds_alternative<
        geometry::NotApplicable>(outcome_);
  }
  [[nodiscard]] const Product *produced_product() const noexcept {
    const auto *produced = std::get_if<
        geometry::Produced<Product>>(&outcome_);
    return produced == nullptr ? nullptr : &produced->product;
  }
  [[nodiscard]] const Product &product() const {
    return std::get<
               geometry::Produced<Product>>(
               outcome_)
        .product;
  }
  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<
        geometry::Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }
  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }

private:
  explicit SurfaceCellRailBuildResult(Outcome outcome)
      : outcome_(std::move(outcome)) {}

  Outcome outcome_;
};

SurfaceCellRailBuildResult build_authoritative_surface_cell_rails(
    const TriMesh &meshWhole, const geometry::AdaptiveFeatureMap &featureMap);

std::set<authority::SourceEdgeTopologyKey> relief_barrier_edges_from_topology(
    const geometry::ReliefTopologyResult &topology, std::size_t vertexExtent);

std::uint64_t hash_relief_operational_inputs(
    const geometry::ReliefRootSelectionResult &roots,
    const std::set<authority::SourceEdgeTopologyKey> &barriers);
std::set<authority::SourceEdgeTopologyKey> hard_feature_edge_keys_from_rails(
    const std::vector<geometry::SurfaceCellRail> &rails,
    std::size_t vertexExtent);

bool project_surface_cell_vertex_chart_authority(
    const std::vector<geometry::PureQuadVertexLineage> &lineages,
    int outputVertexCount, std::size_t railCount,
    std::vector<validation::SourceVertexChartAuthority> &projected);

void fill_surface_cell_rail_constraints(
    const std::vector<geometry::SurfaceCellRail> &rails,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<geometry::SurfacePoint> &outputProvenance,
    geometry::SurfaceOptimizationConstraints &constraints);

// Compatibility overload for callers that only need authoritative rail
// topology. Vertex-to-rail assignments require output geometry and provenance
// and are intentionally left empty here.
void fill_surface_cell_rail_constraints(
    const std::vector<geometry::SurfaceCellRail> &rails,
    geometry::SurfaceOptimizationConstraints &constraints);

std::uint64_t hash_surface_cell_rails(
    const std::vector<geometry::SurfaceCellRail> &rails);
void record_surface_cell_context_product(
    SurfaceCellPipelineContext &context, const std::string &name,
    const SurfaceCellObjectIdentity &identity, const bool available = true);
void record_face_degree_histogram(RemeshResult &result);


std::size_t surface_cell_validation_failure_count(
    const geometry::SurfaceFinalValidationReport &validation,
    const bool enforceOptimizerTimeGate = false);

std::uint64_t hash_surface_cell_validation(
    const geometry::SurfaceFinalValidationReport &validation,
    const bool enforceOptimizerTimeGate = false);

void clear_unavailable_surface_cell_counts(
    directional::RemeshDiagnostics &diagnostics);

void copy_surface_cell_stage_diagnostics(
    const directional::RemeshDiagnostics &source,
    directional::RemeshDiagnostics &target);

void orient_quads_to_source_normals(
    const Eigen::MatrixXd &outputVertices,
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const std::vector<geometry::SurfacePoint> &outputProvenance,
    Eigen::MatrixXi &quads,
    const std::vector<geometry::PureQuadFaceLineage> *quadLineage = nullptr);
std::vector<geometry::SurfaceArrangementArc>
surface_arrangement_arcs_from_flow_rep(
    const std::vector<geometry::FlowRepArc> &arcs,
    const geometry::FlowRepSparseNetwork &sparseNetwork,
    const Eigen::MatrixXi &sourceFaces,
    const geometry::SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *hardFeatureEdges);

struct FieldAlignedSourceQuadRecoveryResult {
  bool success = false;
  geometry::PureQuadMesh mesh;
  std::size_t strictCandidatePairCount = 0;
  std::size_t candidatePairCount = 0;
  std::size_t matchedPairCount = 0;
  std::size_t unmatchedFaceCount = 0;
  std::size_t triangleTemplateCount = 0;
  bool usedGeneralMatching = false;
  std::string failure;
};

std::array<int, 4> ordered_source_quad_boundary(
    const TriMesh &mesh, const int firstFace, const int secondFace);

int source_quad_edge_family(
    const TriMesh &mesh, const fields::CrossFieldResult &crossField,
    const int firstFace, const int secondFace, const int a, const int b,
    double &alignment);

FieldAlignedSourceQuadRecoveryResult
recover_unique_field_aligned_source_quads(
    const TriMesh &mesh, const fields::CrossFieldResult &crossField,
    const geometry::SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *excludedDiagonalEdges);

struct SourceGridRecoveryTargetSizeResult {
  Eigen::VectorXd targetSize;
  bool valid = false;
  bool relaxed = false;
  double maxRelaxationRatio = 1.0;
  std::string failure;
};

SourceGridRecoveryTargetSizeResult
make_source_grid_recovery_target_size(
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const Eigen::MatrixXd &outputVertices,
    const Eigen::MatrixXi &outputQuads,
    const std::vector<geometry::SurfacePoint> &outputProvenance,
    const double requestedTargetSize,
    const double maxRelaxationRatio);

double derive_absolute_target_length(const Eigen::MatrixXd &vertices,
                                     const RemeshOptions &options);

/**
 * @brief Runs the full remeshing pipeline on an initialized TriMesh and raw cross field.
 * @param meshWhole Initialized source mesh.
 * @param rawCrossField #F-by-12 raw 4-RoSy field.
 * @param options Pipeline options.
 * @return Remeshing result with generated mesh and cut-mesh diagnostics.
 */
RemeshResult
remesh_from_raw_cross_field_impl(const TriMesh &meshWhole,
                                 const Eigen::MatrixXd &rawCrossField,
                                 const RemeshOptions &options,
                                 const fields::CrossFieldResult *authoritativeCrossField);

RemeshResult remesh_surface_cells_from_cross_field_impl(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const RemeshOptions &options);

double derive_absolute_target_length(const Eigen::MatrixXd &vertices,
                                            const RemeshOptions &options);

fields::CrossFieldResult remap_surface_cell_cross_field_component(
    const TriMesh &sourceMesh, const geometry::FaceComponent &component,
    const TriMesh &componentMesh,
    const fields::CrossFieldResult &sourceCrossField);

geometry::SurfacePoint remap_component_surface_point(
    geometry::SurfacePoint point, const geometry::FaceComponent &component,
    std::size_t componentIndex,
    std::optional<authority::IsolationSheetId> typedGlobalSheet);

struct ComponentTypedAuthorityRemapDomain {
  std::map<authority::TopologyRegionId, authority::TopologyRegionId>
      topologyRegions;
  std::map<authority::IsolationSheetId, authority::IsolationSheetId>
      isolationSheets;
  std::map<authority::FieldChartId, authority::FieldChartId> fieldCharts;
  std::set<std::pair<authority::TopologyRegionId,
                     authority::IsolationSheetId>>
      localRegionSheets;
  std::vector<geometry::SourceProjectionChart> localChartsByFace;
  std::vector<authority::TopologyRegionId> localRegionsByFace;
  std::vector<authority::IsolationSheetId> localSheetsByFace;
  std::size_t nextTopologyRegion = 0U;
  std::size_t nextIsolationSheet = 0U;
  std::size_t nextFieldChart = 0U;

  [[nodiscard]] bool complete() const noexcept {
    return !topologyRegions.empty() && !isolationSheets.empty() &&
           !fieldCharts.empty() && !localRegionSheets.empty() &&
           localChartsByFace.size() == localRegionsByFace.size() &&
           localChartsByFace.size() == localSheetsByFace.size() &&
           !localChartsByFace.empty();
  }
};

std::optional<ComponentTypedAuthorityRemapDomain>
make_component_typed_authority_remap_domain(
    const geometry::FaceComponent &component,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges,
    std::size_t topologyRegionBase, std::size_t isolationSheetBase,
    std::size_t fieldChartBase);

bool remap_component_typed_lineage_authority(
    geometry::PureQuadVertexLineage &lineage,
    const geometry::FaceComponent &component,
    std::size_t globalSourceVertexCount, std::size_t globalSourceFaceCount,
    const ComponentTypedAuthorityRemapDomain &domain);

namespace remesh_pipeline_detail {

/**
 * Diagnostic-only projection used by the production surface-cell failure path.
 * Tests may call this seam to verify that network error provenance survives the
 * exact projection consumed by CP4c failure rendering.
 */
SurfaceCellFailureLocusDiagnostics
project_field_aligned_curve_network_failure_locus(
    const geometry::FieldAlignedCurveNetworkError &error,
    const authority::FieldTransportAtlas &atlas);

/** Diagnostic-only projection used by the production cut-graph failure path. */
SurfaceCellFailureLocusDiagnostics
project_surface_cut_graph_failure_locus(
    const geometry::SurfaceCutGraphError &error);

/** Diagnostic-only projection used by the production topology-plan failure path. */
SurfaceCellFailureLocusDiagnostics
project_global_topology_plan_failure_locus(
    const geometry::GlobalTopologyPlanError &error);

struct SurfaceCellComponentStageProducts {
  std::optional<geometry::SourceTopologyRegions> sourceTopologyRegions;
  std::optional<authority::FieldTransportAtlas> fieldTransportAtlas;
  std::optional<geometry::FieldAlignedCurveNetwork> fieldAlignedCurveNetwork;
  std::optional<geometry::SurfaceCutGraph> surfaceCutGraph;
  std::optional<geometry::GlobalTopologyPlan> globalTopologyPlan;
  std::vector<geometry::SurfaceCellRail> authoritativeRails;
  std::optional<geometry::SourceSurfaceLabels> sourceSurfaceLabels;
  std::vector<geometry::PureQuadMesh> completedPatches;
  bool sourceGridRecoveryUsed = false;
  Eigen::VectorXd sourceGridRecoveryTargetSize;
  bool hasSourceGridRecoveryTargetSize = false;
  bool sourceGridRecoveryTargetSizeRelaxed = false;
  double sourceGridRecoveryTargetSizeMaxRelaxationRatio = 1.0;
  std::optional<geometry::SurfaceOptimizationResult> optimizationResult;
  std::optional<geometry::SurfaceFinalValidationReport> validationResult;
};

using ComponentAggregationInputMutator =
    std::function<void(std::size_t, RemeshResult &,
                       SurfaceCellComponentStageProducts &)>;
using FinalAggregateValidationAuthorityMutator = std::function<void(
    validation::SourceAuthoritativeMeshValidatorOptions &)>;

/**
 * Counterfactual seam over the production disconnected-component aggregator.
 * The mutator runs after each component has completed and before the first
 * aggregation read. It receives both the component result representation and
 * the declared stage-product authority consumed by aggregation, so tests can
 * mutate the same semantic boundary as production without reconstructing
 * stage products from SurfaceCellPipelineContext.
 */
RemeshResult remesh_surface_cell_components_from_cross_field_counterfactual(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options,
    const ComponentAggregationInputMutator &beforeAggregation);

/**
 * Counterfactual seam immediately before the final disconnected-aggregate
 * source-authoritative oracle. Component seam/capture checks have already
 * passed, so this hook can prove the final oracle independently rejects
 * missing or corrupted globally remapped authority. Production entry points
 * never supply this mutator.
 */
RemeshResult
remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options,
    const FinalAggregateValidationAuthorityMutator &beforeFinalValidation);

} // namespace remesh_pipeline_detail

void append_polygon_faces(
    Eigen::MatrixXi &targetFaces, Eigen::VectorXi &targetDegrees,
    const Eigen::MatrixXi &sourceFaces, const Eigen::VectorXi &sourceDegrees,
    const int vertexOffset);

void accumulate_surface_optimization_energy(
    geometry::SurfaceOptimizationEnergy &target,
    const geometry::SurfaceOptimizationEnergy &source);

void accumulate_surface_optimization_result(
    geometry::SurfaceOptimizationResult &target,
    const geometry::SurfaceOptimizationResult &source,
    const bool firstComponent);

void accumulate_surface_validation_report(
    geometry::SurfaceFinalValidationReport &target,
    const geometry::SurfaceFinalValidationReport &source,
    const bool firstComponent);

void append_matrix_rows(Eigen::MatrixXd &target,
                               const Eigen::MatrixXd &source);

void append_matrix_rows(Eigen::MatrixXi &target,
                               const Eigen::MatrixXi &source,
                               const int indexOffset = 0);

void append_vector(Eigen::VectorXi &target,
                          const Eigen::VectorXi &source);

void append_vector(Eigen::VectorXd &target,
                          const Eigen::VectorXd &source);

void accumulate_component_diagnostics(
    directional::RemeshDiagnostics &target,
    const directional::RemeshDiagnostics &source,
    const std::size_t componentIndex,
    const bool firstComponent);

void accumulate_component_diagnostics(
    directional::RemeshDiagnostics &target,
    const directional::RemeshDiagnostics &source);

RemeshResult remesh_surface_cell_components_from_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options);

RemeshResult remesh_components_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options);

/**
 * @brief Runs remeshing from raw mesh matrices and a raw 4-RoSy cross field.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param rawCrossField #F-by-12 raw field.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
RemeshResult remesh_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options = {});

RemeshResult
remesh_from_cross_field_result(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const fields::CrossFieldResult &crossField,
                               const RemeshOptions &options = {});

/**
 * @brief Runs remeshing from two direction families per face.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param primaryDirections Primary ambient/tangent direction per face.
 * @param secondaryDirections Secondary ambient/tangent direction per face.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const Eigen::MatrixXd &secondaryDirections,
                        const RemeshOptions &options = {});

/**
 * @brief Runs remeshing from one direction family per face.
 *
 * The secondary direction is generated as the tangent-plane orthogonal
 * complement of the supplied primary direction.
 *
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param primaryDirections Primary ambient/tangent direction per face.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const RemeshOptions &options = {});

/**
 * @brief Extracts a smooth 4-RoSy cross field and runs the full remeshing pipeline.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param options Remeshing and direction-normalization options.
 * @return Remeshing result including the automatically extracted raw cross field.
 */
RemeshResult
remesh_from_mesh(const Eigen::MatrixXd &vertices,
                 const Eigen::MatrixXi &faces,
                 const RemeshOptions &options = {});

} // namespace directional::pipeline

#endif // DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
