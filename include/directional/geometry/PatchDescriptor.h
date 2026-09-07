// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_PATCH_DESCRIPTOR_H
#define DIRECTIONAL_GEOMETRY_PATCH_DESCRIPTOR_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellFeasibilityRepair.h>

namespace directional::geometry {

struct PatchDescriptorOptions {
  // Source-vertex cycle IDs and corresponding quarter-index numerators.
  // These are CrossFieldResult::singularCycles/singularIndices.
  Eigen::VectorXi singularCycles;
  Eigen::VectorXi singularIndices;
  double barycentricTolerance = 1.0e-10;
  bool enforceGlobalSingularityOwnership = false;
  std::set<int> embeddedSingularVertices;
  std::map<int, int> interiorSingularityOwner;
};

struct PatchSideDescriptor {
  int family = -1;
  std::vector<int> halfedges;
  std::vector<int> boundaryVertices;
  int subdivisionCount = 0;
  bool hardFeature = false;
  std::set<authority::HardRailId> railIds;
  std::set<int> curveIds;
};

struct PatchDescriptor {
  int cellId = -1;
  PureQuadPatch patch;
  SurfaceCellDomainIdentityAudit domainIdentityAudit;
  PureQuadPatchAdmissibility feasibility;
  std::vector<PatchSideDescriptor> sides;
  std::vector<int> singularSourceVertices;
  std::vector<int> singularNumerators;
  bool boundaryCycleValid = false;
  bool featureConstraintsValid = true;
};

struct PatchDescriptorSet {
  std::vector<PatchDescriptor> descriptors;
  SurfaceCellOwnershipConflict ownershipConflict;
  SurfaceCellDomainIdentityAudit firstInvalidDomain;
  std::vector<int> unresolvedSingularVertices;
  int feasible = 0;
  int rejected = 0;
};

enum class SurfaceCellOwnershipRepairAction : int {
  CompletionVariant = 0,
  BoundarySectorSubdivision = 1,
  RouteCompleteBoundarySubdivision = 2,
};

enum class SurfaceCellOwnershipRepairOutcome : int {
  None = 0,
  SubdivisionFailed = 1,
  ValidationFailed = 2,
  RepeatedState = 3,
  NoProgress = 4,
  IntroducedOwnershipClaim = 5,
  Committed = 6,
  AssemblySucceeded = 7,
  BudgetExhausted = 8,
  IncompleteRoute = 9,
  RouteValidationFailed = 10,
  NoRouteCompleteCandidate = 11,
  StrictConflictReduction = 12,
  LatentClaimExposed = 13,
  ConflictRegression = 14,
};

inline const char *surface_cell_ownership_repair_outcome_name(
    const SurfaceCellOwnershipRepairOutcome outcome) {
  switch (outcome) {
  case SurfaceCellOwnershipRepairOutcome::None:
    return "none";
  case SurfaceCellOwnershipRepairOutcome::SubdivisionFailed:
    return "subdivision-failed";
  case SurfaceCellOwnershipRepairOutcome::ValidationFailed:
    return "validation-failed";
  case SurfaceCellOwnershipRepairOutcome::RepeatedState:
    return "repeated-state";
  case SurfaceCellOwnershipRepairOutcome::NoProgress:
    return "no-progress";
  case SurfaceCellOwnershipRepairOutcome::IntroducedOwnershipClaim:
    return "introduced-ownership-claim";
  case SurfaceCellOwnershipRepairOutcome::Committed:
    return "committed";
  case SurfaceCellOwnershipRepairOutcome::AssemblySucceeded:
    return "assembly-succeeded";
  case SurfaceCellOwnershipRepairOutcome::BudgetExhausted:
    return "budget-exhausted";
  case SurfaceCellOwnershipRepairOutcome::IncompleteRoute:
    return "incomplete-route";
  case SurfaceCellOwnershipRepairOutcome::RouteValidationFailed:
    return "route-validation-failed";
  case SurfaceCellOwnershipRepairOutcome::NoRouteCompleteCandidate:
    return "no-route-complete-candidate";
  case SurfaceCellOwnershipRepairOutcome::StrictConflictReduction:
    return "strict-conflict-reduction";
  case SurfaceCellOwnershipRepairOutcome::LatentClaimExposed:
    return "latent-claim-exposed";
  case SurfaceCellOwnershipRepairOutcome::ConflictRegression:
    return "conflict-regression";
  }
  return "unknown";
}

enum class SurfaceCellStructuralRepairExhaustionReason : int {
  None = 0,
  CandidateBudget = 1,
  StructuralAttemptBudget = 2,
  InsertedVertexBudget = 3,
  FullRecomputationBudget = 4,
  VisitedStateBudget = 5,
  RepeatedState = 6,
  NoProgress = 7,
  NoCandidate = 8,
  OwnershipOverlap = 9,
  IntroducedOwnershipClaim = 10,
  IncompleteRoute = 11,
  RouteValidationFailed = 12,
  NoRouteCompleteCandidate = 13,
};

inline const char *surface_cell_structural_repair_exhaustion_reason_name(
    const SurfaceCellStructuralRepairExhaustionReason reason) {
  switch (reason) {
  case SurfaceCellStructuralRepairExhaustionReason::None:
    return "none";
  case SurfaceCellStructuralRepairExhaustionReason::CandidateBudget:
    return "candidate-budget";
  case SurfaceCellStructuralRepairExhaustionReason::StructuralAttemptBudget:
    return "structural-attempt-budget";
  case SurfaceCellStructuralRepairExhaustionReason::InsertedVertexBudget:
    return "inserted-vertex-budget";
  case SurfaceCellStructuralRepairExhaustionReason::FullRecomputationBudget:
    return "full-recomputation-budget";
  case SurfaceCellStructuralRepairExhaustionReason::VisitedStateBudget:
    return "visited-state-budget";
  case SurfaceCellStructuralRepairExhaustionReason::RepeatedState:
    return "repeated-state";
  case SurfaceCellStructuralRepairExhaustionReason::NoProgress:
    return "no-progress";
  case SurfaceCellStructuralRepairExhaustionReason::NoCandidate:
    return "no-candidate";
  case SurfaceCellStructuralRepairExhaustionReason::OwnershipOverlap:
    return "ownership-overlap";
  case SurfaceCellStructuralRepairExhaustionReason::IntroducedOwnershipClaim:
    return "introduced-ownership-claim";
  case SurfaceCellStructuralRepairExhaustionReason::IncompleteRoute:
    return "incomplete-route";
  case SurfaceCellStructuralRepairExhaustionReason::RouteValidationFailed:
    return "route-validation-failed";
  case SurfaceCellStructuralRepairExhaustionReason::NoRouteCompleteCandidate:
    return "no-route-complete-candidate";
  }
  return "unknown";
}

inline const char *surface_cell_ownership_repair_action_name(
    const SurfaceCellOwnershipRepairAction action) {
  switch (action) {
  case SurfaceCellOwnershipRepairAction::CompletionVariant:
    return "completion-variant";
  case SurfaceCellOwnershipRepairAction::BoundarySectorSubdivision:
    return "boundary-sector-subdivision";
  case SurfaceCellOwnershipRepairAction::RouteCompleteBoundarySubdivision:
    return "route-complete-boundary-subdivision";
  }
  return "unknown";
}

struct SurfaceCellOwnershipRepairAttempt {
  int ordinal = -1;
  SurfaceCellOwnershipRepairAction action =
      SurfaceCellOwnershipRepairAction::CompletionVariant;
  SurfaceCellOwnershipConflictClass conflictClass =
      SurfaceCellOwnershipConflictClass::None;
  SurfaceCellOwnershipConflictClass resultingConflictClass =
      SurfaceCellOwnershipConflictClass::None;
  int firstPatch = -1;
  int secondPatch = -1;
  int selectedPatch = -1;
  int selectedHalfedge = -1;
  std::vector<int> selectedHalfedges;
  std::vector<std::uint64_t> sharedCornerIdentityHashes;
  std::uint64_t routeIdentityHash = 0U;
  int routeCandidateCount = 0;
  int routeIntervalCount = 0;
  std::uint64_t rollbackOwnedBytes = 0U;
  std::uint64_t candidateOwnedBytes = 0U;
  std::uint64_t descriptorOwnedBytes = 0U;
  std::uint64_t completedPatchOwnedBytes = 0U;
  std::uint64_t assemblyOwnedBytes = 0U;
  std::uint64_t totalStructuralOwnedBytes = 0U;
  PureQuadCompletionBackend backend = PureQuadCompletionBackend::ClosedForm;
  int fromVariant = 0;
  int toVariant = 0;
  int insertedVertices = 0;
  int splitUndirectedEdges = 0;
  int candidateEvaluation = 0;
  int structuralAttempt = 0;
  int fullRecomputationPass = 0;
  int visitedStateCount = 0;
  int globalInsertedVerticesBefore = 0;
  int globalInsertedVerticesAfter = 0;
  int liveCandidateComplexes = 0;
  bool completionSucceeded = false;
  bool committed = false;
  bool repeatedState = false;
  bool madeProgress = false;
  bool introducedOwnershipClaim = false;
  int preConflictCount = 0;
  int postConflictCount = 0;
  int retainedConflictCount = 0;
  int removedConflictCount = 0;
  int introducedConflictCount = 0;
  int reusedPatchCompletions = 0;
  int recomputedPatchCompletions = 0;
  std::uint64_t preConflictInventoryHash = 0U;
  std::uint64_t postConflictInventoryHash = 0U;
  SurfaceCellOwnershipRepairOutcome outcome =
      SurfaceCellOwnershipRepairOutcome::None;
  std::vector<int> affectedPatches;
  std::string failure;
};

struct SurfaceCellComplexCompletionOptions {
  PatchDescriptorOptions descriptorOptions;
  SurfaceCellSideRepairOptions sideRepairOptions;
  int maxBoundaryEdges = 128;
  bool allowBoundedCombinatorialFallback = true;
  int maxCompletionOwnershipRepairs = 256;
  // Global, invocation-owned structural repair budgets. These are never reset
  // by a candidate evaluation. Defaults permit an initial pass and at most two
  // full candidate passes, which keeps production work bounded while allowing
  // a deterministic first-fails/second-succeeds repair sequence.
  int maxSameCornerBoundaryRepairs = 2;
  int maxSameCornerCandidateEvaluations = 2;
  int maxSameCornerFullCompletionPasses = 3;
  int maxSameCornerVisitedStates = 3;
  // Negative selects the exact topology-derived interval count for the one
  // atomic frontier transaction. Nonnegative values remain explicit test and
  // caller caps.
  int maxSameCornerInsertedVertices = -1;
  const SourceTopologyRegions *sourceAuthority = nullptr;
  const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges = nullptr;
};

struct PatchCompletionReuseMismatch {
  int requestedCell = -1;
  int cachedCell = -1;
  bool hashMiss = false;
  bool sourceDomain = false;
  bool sideSubdivision = false;
  bool boundarySourceCoordinates = false;
  bool railCurveSupport = false;
  bool singularityRequirements = false;
  bool backendVariant = false;
  bool topologyTemplate = false;
  bool rebindValidation = false;
};

enum class SurfaceCellComplexCompletionFailureKind : int {
  None = 0,
  PreparationRejected = 1,
  InvalidDomainIdentity = 2,
  UnresolvedSingularityOwnership = 3,
  PatchCompletionRejected = 4,
  CompletionOwnershipRejected = 5,
  StructuralRepairExhausted = 6,
  AssemblyRejected = 7,
};

struct SurfaceCellComplexCompletionEvidence {
  int parityOddCellsBefore = 0;
  int parityOddCellsAfter = 0;
  int paritySplitEdges = 0;
  int parityHardFeatureSplits = 0;
  int parityAlternativeCandidateBudget = 0;
  int parityAlternativeCandidatesAttempted = 0;
  int parityAlternativeVisitedStates = 0;
  int parityAlternativeSelectedExclusion = -1;
  std::uint64_t parityAlternativeStateSequenceHash = 0U;
  SurfaceCellParityAlternativeDisposition parityAlternativeDisposition =
      SurfaceCellParityAlternativeDisposition::None;
  SurfaceCellReplacementScopeFailure firstParityScopeFailure;
  int sideInfeasibleCellsBefore = 0;
  int sideInfeasibleCellsAfter = 0;
  int sideInitialEquationDefect = 0;
  int sideFinalEquationDefect = 0;
  int sidePropagationPasses = 0;
  int sideAttemptedInsertions = 0;
  int sideInsertedVertices = 0;
  int sideSplitEdges = 0;
  int sideHardFeatureSplits = 0;
  bool sideRollbackEquivalent = false;
  std::uint64_t sideRollbackIdentityHashBefore = 0U;
  std::uint64_t sideRollbackIdentityHashAfter = 0U;
  std::uint64_t sideRollbackUndoOwnedBytes = 0U;
  SurfaceCellDomainIdentityAudit firstInvalidDomain;
  int attemptedPatches = 0;
  int failedPatches = 0;
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
  std::vector<PatchCompletionReuseMismatch>
      completionOwnershipProductCacheMismatchVector;
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
  std::uint64_t completionLogicalPayloadBytes = 0U;
  std::uint64_t completionRetainedCapacityBytes = 0U;
  SurfaceCellStructuralRepairExhaustionReason
      completionOwnershipStructuralExhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::None;
  std::vector<SurfaceCellOwnershipRepairAttempt> ownershipRepairAttempts;
  PureQuadCompletionOwnershipRejection firstCompletionOwnershipRejection;
  PureQuadEmbeddingFailure firstCompletionEmbeddingFailure;
};

struct SurfaceCellComplexCompletionProduct {
  SurfaceCellComplex preparedComplex;
  bool hasPreparedComplex = false;
  PatchDescriptorSet descriptors;
  std::vector<PureQuadMesh> completedPatches;
  PureQuadAssemblyResult assembly;
};

struct SurfaceCellComplexCompletionFailure {
  SurfaceCellComplexCompletionFailureKind kind =
      SurfaceCellComplexCompletionFailureKind::None;
  std::string detail;
  SurfaceCellOwnershipConflict ownershipConflict;
  std::vector<SurfaceCellOwnershipConflict> ownershipConflicts;
};

class SurfaceCellComplexCompletionResult
    : public SurfaceCellComplexCompletionEvidence {
public:
  using Product = SurfaceCellComplexCompletionProduct;
  using Failure = SurfaceCellComplexCompletionFailure;
  using Outcome = ProducerOutcome<Product, Failure>;

  SurfaceCellComplexCompletionResult() = default;
  SurfaceCellComplexCompletionResult(const SurfaceCellComplexCompletionResult &) = default;
  SurfaceCellComplexCompletionResult(SurfaceCellComplexCompletionResult &&) noexcept = default;
  SurfaceCellComplexCompletionResult &operator=(const SurfaceCellComplexCompletionResult &) = default;
  SurfaceCellComplexCompletionResult &operator=(SurfaceCellComplexCompletionResult &&) noexcept = default;

  [[nodiscard]] static SurfaceCellComplexCompletionResult produced(
      SurfaceCellComplexCompletionEvidence evidence, Product product) {
    if (!product.assembly.success || product.assembly.mesh.quads.empty()) {
      throw std::invalid_argument(
          "Produced surface-cell completion requires a successful assembly.");
    }
    return SurfaceCellComplexCompletionResult(
        std::move(evidence), Outcome{Produced<Product>{std::move(product)}});
  }

  [[nodiscard]] static SurfaceCellComplexCompletionResult rejected(
      SurfaceCellComplexCompletionEvidence evidence, Failure failure) {
    if (failure.kind == SurfaceCellComplexCompletionFailureKind::None) {
      throw std::invalid_argument(
          "Rejected surface-cell completion requires a typed failure.");
    }
    return SurfaceCellComplexCompletionResult(
        std::move(evidence), Outcome{Rejected<Failure>{std::move(failure)}});
  }

  [[nodiscard]] bool is_produced() const noexcept {
    return std::holds_alternative<Produced<Product>>(outcome_);
  }
  [[nodiscard]] bool is_rejected() const noexcept {
    return std::holds_alternative<Rejected<Failure>>(outcome_);
  }
  [[nodiscard]] bool is_not_applicable() const noexcept {
    return std::holds_alternative<NotApplicable>(outcome_);
  }
  [[nodiscard]] const Product *produced_product() const noexcept {
    const auto *produced = std::get_if<Produced<Product>>(&outcome_);
    return produced == nullptr ? nullptr : &produced->product;
  }
  [[nodiscard]] Product &product() & {
    return std::get<Produced<Product>>(outcome_).product;
  }
  [[nodiscard]] const Product &product() const & {
    return std::get<Produced<Product>>(outcome_).product;
  }
  [[nodiscard]] Product &&product() && {
    return std::move(std::get<Produced<Product>>(outcome_).product);
  }
  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }
  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }
  [[nodiscard]] Outcome &&outcome() && noexcept { return std::move(outcome_); }

private:
  SurfaceCellComplexCompletionResult(
      SurfaceCellComplexCompletionEvidence evidence, Outcome outcome)
      : SurfaceCellComplexCompletionEvidence(std::move(evidence)),
        outcome_(std::move(outcome)) {}

  Outcome outcome_{NotApplicable{}};
};

namespace patch_descriptor_detail {

const SurfaceArrangementNode *find_node(
    const SurfaceCellComplex &complex, const int id);

int normalized_family(const int family);

int source_vertex_at_node(const SurfaceArrangementNode &node,
                                 const Eigen::MatrixXi &F,
                                 const double tolerance);

SurfacePoint node_surface_point(const SurfaceArrangementNode &node,
                                       const Eigen::MatrixXd &V,
                                       const Eigen::MatrixXi &F,
                                       const SurfaceArrangementHalfedge &edge);

bool ordered_boundary(const SurfaceCellComplex &complex,
                             const SurfaceArrangementCell &cell,
                             std::vector<int> &ordered);

std::vector<PatchSideDescriptor>
extract_sides(const SurfaceCellComplex &complex,
              const SurfaceArrangementCell &cell,
              const std::vector<int> &boundary,
              const Eigen::MatrixXd &V,
              const Eigen::MatrixXi &F);

bool source_vertex_is_in_cell(const int vertex,
                                     const SurfaceArrangementCell &cell,
                                     const Eigen::MatrixXi &F);

} // namespace patch_descriptor_detail

SurfaceCellDomainIdentityAudit audit_surface_cell_domain_identity(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::vector<int> &boundary, const Eigen::MatrixXi &F);

PatchDescriptor derive_patch_descriptor(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const PatchDescriptorOptions &options = {});

PatchDescriptorSet derive_patch_descriptors(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const PatchDescriptorOptions &options = {});

SurfaceCellComplexCompletionResult complete_surface_cell_complex(
    SurfaceCellComplex complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options);

} // namespace directional::geometry

#endif
