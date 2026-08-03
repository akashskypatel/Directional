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
#include <map>
#include <numeric>
#include <set>
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
  std::set<int> railIds;
  std::set<int> curveIds;
};

struct PatchDescriptor {
  int cellId = -1;
  PureQuadPatch patch;
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
  std::vector<int> unresolvedSingularVertices;
  int feasible = 0;
  int rejected = 0;
};

enum class SurfaceCellOwnershipRepairAction : int {
  CompletionVariant = 0,
  BoundarySectorSubdivision = 1,
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
  SurfaceCellOwnershipRepairOutcome outcome =
      SurfaceCellOwnershipRepairOutcome::None;
  std::vector<int> affectedPatches;
  std::string failure;
};

struct SurfaceCellComplexCompletionOptions {
  PatchDescriptorOptions descriptorOptions;
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
  int maxSameCornerInsertedVertices = 8;
  const std::vector<int> *sourceFaceComponents = nullptr;
  const std::vector<int> *sourceFaceSheets = nullptr;
};

struct SurfaceCellComplexCompletionResult {
  bool success = false;
  SurfaceCellComplex preparedComplex;
  bool hasPreparedComplex = false;
  int parityOddCellsBefore = 0;
  int parityOddCellsAfter = 0;
  int paritySplitEdges = 0;
  int parityHardFeatureSplits = 0;
  int sideInfeasibleCellsBefore = 0;
  int sideInfeasibleCellsAfter = 0;
  int sideInitialEquationDefect = 0;
  int sideFinalEquationDefect = 0;
  int sidePropagationPasses = 0;
  int sideAttemptedInsertions = 0;
  int sideInsertedVertices = 0;
  int sideSplitEdges = 0;
  int sideHardFeatureSplits = 0;
  PatchDescriptorSet descriptors;
  std::vector<PureQuadMesh> completedPatches;
  PureQuadAssemblyResult assembly;
  int attemptedPatches = 0;
  int failedPatches = 0;
  int completionOwnershipRepairAttempts = 0;
  int completionOwnershipStructuralRepairAttempts = 0;
  int completionOwnershipInsertedBoundaryVertices = 0;
  int completionOwnershipStructuralCandidateBudget = 0;
  int completionOwnershipStructuralCandidatesConsumed = 0;
  int completionOwnershipVisitedStateCount = 0;
  int completionOwnershipFullRecomputationPasses = 0;
  int completionOwnershipIncrementalRecomputationPasses = 0;
  int completionOwnershipCurrentLiveCandidateComplexes = 0;
  int completionOwnershipPeakLiveCandidateComplexes = 0;
  int completionOwnershipLastCandidateHalfedge = -1;
  std::vector<int> completionOwnershipLastAffectedPatches;
  SurfaceCellStructuralRepairExhaustionReason
      completionOwnershipStructuralExhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::None;
  std::vector<SurfaceCellOwnershipRepairAttempt> ownershipRepairAttempts;
  PureQuadCompletionOwnershipRejection firstCompletionOwnershipRejection;
  std::string failure;
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

PatchDescriptor derive_patch_descriptor(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const PatchDescriptorOptions &options = {});

PatchDescriptorSet derive_patch_descriptors(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const PatchDescriptorOptions &options = {});

SurfaceCellComplexCompletionResult complete_surface_cell_complex(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options = {});

} // namespace directional::geometry

#endif
