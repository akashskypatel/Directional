// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H
#define DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/SurfaceArrangement.h>

namespace directional::geometry {

enum class SurfaceSimplificationCandidateType : int {
  RedundantStrand = 0,
  OpenStrip = 1,
  ClosedLoop = 2,
  ParallelCurveMerge = 3,
  ReliefArtifact = 4,
  RegionCollapse = 5,
  PoleRelocation = 6,
  TransitionRemoval = 7,
};

enum class SurfaceSimplificationRejectionReason : int {
  None = 0,
  ProtectedFeature = 1,
  ProtectedBoundary = 2,
  ProtectedRoot = 3,
  ProtectedSingularity = 4,
  TopologyChanged = 5,
  NonDiskPatch = 6,
  PatchInfeasible = 7,
  ObjectiveWorsened = 8,
  DescriptivenessWorsened = 9,
  StaleCandidate = 10,
  TargetReached = 11,
};

struct SurfaceSimplificationElement {
  int id = -1;
  int cellOrHalfedge = -1;
  bool active = true;
  bool hardFeature = false;
  bool boundary = false;
  bool basinRoot = false;
  bool rootLabelProtected = false;
  bool singularityProtected = false;
  bool handleCritical = false;
  double length = 1.0;
};

struct SurfaceSimplificationObjectiveWeights {
  double surface = 1.0;
  double normal = 1.0;
  double field = 1.0;
  double size = 1.0;
  double quad = 1.0;
  double feature = 1.0;
  double topology = 1.0;
};

struct SurfaceSimplificationCandidate {
  int stableId = -1;
  int generation = 0;
  std::uint64_t semanticHash = 0U;
  SurfaceSimplificationCandidateType type =
      SurfaceSimplificationCandidateType::OpenStrip;
  // Canonical arrangement halfedge IDs. Each undirected edge is represented
  // by the lower of the two twin IDs.
  std::vector<int> elementIds;
  std::vector<int> affectedNodeIds;
  std::vector<int> affectedCellIds;
  std::vector<int> affectedStrandIds;
  bool touchesHardFeature = false;
  bool touchesBoundary = false;
  bool touchesSingularity = false;
  bool touchesLocalSheetBoundary = false;
  double removedLength = 0.0;
  double deltaSurface = 0.0;
  double deltaNormal = 0.0;
  double deltaField = 0.0;
  double deltaSize = 0.0;
  double deltaQuad = 0.0;
  double featurePenalty = 0.0;
  double topologyPenalty = 0.0;
  double descriptivenessWorsening = 0.0;
  bool affectedPatchDisk = true;
  bool sideFeasible = true;
  bool changesTopology = false;
  /// Removal deletes an optional layout-support bridge whose two DCEL sides
  /// currently pinch a non-disk face. Trial acceptance requires a strict
  /// reduction in the non-disk defect while preserving source topology.
  bool topologyHealing = false;
  bool invalidated = false;
};

struct SurfaceSimplificationCandidateExtractionOptions {
  // Do not emit candidates whose complete support is smaller than this.
  int minimumElements = 1;
  // Candidate extraction is intentionally conservative at authoritative rails.
  bool includeProtectedCandidatesForDiagnostics = true;
  // A chain with matching end nodes is classified as a closed loop.
  bool classifyClosedLoops = true;
};

struct SurfaceSimplificationCandidateSet {
  std::vector<SurfaceSimplificationCandidate> candidates;
  int protectedCandidates = 0;
  int openStripCandidates = 0;
  int closedLoopCandidates = 0;
  int redundantStrandCandidates = 0;
  int regionCandidates = 0;
  int poleCandidates = 0;
  int transitionCandidates = 0;
  std::uint64_t structuralHash = 0;
};

struct SurfaceSimplificationOptions {
  SurfaceSimplificationObjectiveWeights weights;
  int targetActiveElements = 0;
  double objectiveTolerance = 0.0;
  double maxDescriptivenessWorsening = 0.05;
  /// Restrict the transactional queue to optional layout-support graph
  /// bridges whose removal strictly improves a non-disk arrangement cell.
  /// Production surface-cell integration uses this conservative mode until
  /// the general FlowRep edit operators have independent fidelity gates.
  bool topologyHealingOnly = false;
  /// Refresh the candidate frontier after every committed edit. This is the
  /// established fixed-point API contract. Set false only for an explicitly
  /// bounded one-transaction diagnostic call.
  bool refreshCandidatesAfterCommit = true;
  /// Optional hard limit on committed transactions. Negative is unbounded.
  int maxCommittedTransactions = -1;
  /// Preserve per-candidate transaction payloads. Production callers can
  /// disable this after scalar counters/hashes are sufficient, avoiding one
  /// retained vector-of-vectors record per evaluated simplification candidate.
  bool retainTransactionDetails = true;
};

struct SurfaceSimplificationTransaction {
  int candidateId = -1;
  SurfaceSimplificationCandidateType type =
      SurfaceSimplificationCandidateType::OpenStrip;
  bool topologyHealing = false;
  std::vector<int> elementIds;
  std::vector<int> affectedCellIds;
  bool committed = false;
  SurfaceSimplificationRejectionReason rejection =
      SurfaceSimplificationRejectionReason::None;
  double objectiveCost = 0.0;
  int beforeNonDiskDefect = -1;
  int afterNonDiskDefect = -1;
  int beforeNodeCount = -1;
  int afterNodeCount = -1;
  int beforeUndirectedEdgeCount = -1;
  int afterUndirectedEdgeCount = -1;
  int beforeInteriorCellCount = -1;
  int afterInteriorCellCount = -1;
  int beforeEulerCharacteristic = 0;
  int afterEulerCharacteristic = 0;
  int sourceEulerCharacteristic = 0;
  int beforeConnectedComponentCount = 0;
  int afterConnectedComponentCount = 0;
  int sourceConnectedComponentCount = 0;
  int beforeBoundaryLoopCount = 0;
  int afterBoundaryLoopCount = 0;
  int sourceBoundaryLoopCount = 0;
  int beforeUnsplitCrossings = 0;
  int afterUnsplitCrossings = 0;
  int beforeGeometricTJunctions = 0;
  int afterGeometricTJunctions = 0;
  bool trialBuilt = false;
  bool beforeEmbeddingValid = false;
  bool beforeOrientationValid = false;
  bool beforeBoundaryLoopsValid = false;
  bool beforeEulerCharacteristicValid = false;
  bool incidenceValid = false;
  bool embeddingValid = false;
  bool orientationValid = false;
  bool boundaryLoopsValid = false;
  bool eulerCharacteristicValid = false;
  bool noUnsplitCrossings = false;
  bool noGeometricTJunctions = false;
  bool topologyMismatchNotWorse = false;
  bool protectedSupportPreserved = false;
  std::uint64_t beforeHash = 0;
  std::uint64_t afterHash = 0;
};

struct SurfaceSimplificationResult {
  std::vector<SurfaceSimplificationElement> elements;
  SurfaceCellComplex complex;
  bool hasComplexOutput = false;
  std::vector<SurfaceSimplificationTransaction> transactions;
  int committed = 0;
  int rejected = 0;
  int invalidatedCandidates = 0;
  int recomputedCandidates = 0;
  int generatedCandidates = 0;
  int deduplicatedCandidates = 0;
  int staleGenerationCandidates = 0;
  int frontierGenerations = 0;
  int peakLiveCandidates = 0;
  int incidenceRebuilds = 0;
  int validationPasses = 0;
  int initialActiveElements = 0;
  int finalActiveElements = 0;
  std::uint64_t finalHash = 0;
  double empiricalWork = 0.0;
};

struct SurfaceSimplificationOverlay {
  Eigen::VectorXi candidateType;
  Eigen::VectorXi retained;
  Eigen::VectorXi removed;
  Eigen::VectorXi rejectionReason;
  Eigen::VectorXd objectiveCost;
};

namespace surface_simplification_detail {

bool element_protected(const SurfaceSimplificationElement &element);

std::uint64_t structural_hash(
    const std::vector<SurfaceSimplificationElement> &elements);

std::uint64_t complex_structural_hash(const SurfaceCellComplex &complex);

int active_count(const std::vector<SurfaceSimplificationElement> &elements);

double objective_cost(
    const SurfaceSimplificationCandidate &candidate,
    const SurfaceSimplificationObjectiveWeights &weights);

struct QueueEntry {
  double cost = 0.0;
  SurfaceSimplificationCandidateType type =
      SurfaceSimplificationCandidateType::OpenStrip;
  int stableId = -1;
  int index = -1;

  bool operator<(const QueueEntry &other) const {
    if (std::abs(cost - other.cost) > 1.0e-14) {
      return cost > other.cost;
    }
    if (type != other.type) {
      return static_cast<int>(type) > static_cast<int>(other.type);
    }
    return stableId > other.stableId;
  }
};

SurfaceSimplificationRejectionReason validate_candidate(
    const SurfaceSimplificationCandidate &candidate,
    const std::vector<SurfaceSimplificationElement> &elements,
    const SurfaceSimplificationOptions &options, const double cost);

enum class SurfaceCellIncidenceFailureKind : int {
  None = 0,
  NodeIdMismatch = 1,
  HalfedgeIdMismatch = 2,
  InvalidTwin = 3,
  TwinAsymmetry = 4,
  InvalidEndpoint = 5,
  DegenerateEdge = 6,
  InvalidCell = 7,
  InvalidNext = 8,
  NextEndpointMismatch = 9,
  CellIdMismatch = 10,
  CellNotClosed = 11,
  CellTooSmall = 12,
  NonDiskCell = 13,
  SideMetadataMismatch = 14,
  RepeatedCellHalfedge = 15,
  HalfedgeCellMismatch = 16,
  CellNextMismatch = 17,
  HalfedgeUseMismatch = 18,
  DirectedEdgeMultiplicity = 19,
  PredecessorMultiplicity = 20,
  OwnershipRegistryMismatch = 21,
};

inline const char *surface_cell_incidence_failure_name(
    const SurfaceCellIncidenceFailureKind failure) {
  switch (failure) {
  case SurfaceCellIncidenceFailureKind::None:
    return "none";
  case SurfaceCellIncidenceFailureKind::NodeIdMismatch:
    return "node-id-mismatch";
  case SurfaceCellIncidenceFailureKind::HalfedgeIdMismatch:
    return "halfedge-id-mismatch";
  case SurfaceCellIncidenceFailureKind::InvalidTwin:
    return "invalid-twin";
  case SurfaceCellIncidenceFailureKind::TwinAsymmetry:
    return "twin-asymmetry";
  case SurfaceCellIncidenceFailureKind::InvalidEndpoint:
    return "invalid-endpoint";
  case SurfaceCellIncidenceFailureKind::DegenerateEdge:
    return "degenerate-edge";
  case SurfaceCellIncidenceFailureKind::InvalidCell:
    return "invalid-cell";
  case SurfaceCellIncidenceFailureKind::InvalidNext:
    return "invalid-next";
  case SurfaceCellIncidenceFailureKind::NextEndpointMismatch:
    return "next-endpoint-mismatch";
  case SurfaceCellIncidenceFailureKind::CellIdMismatch:
    return "cell-id-mismatch";
  case SurfaceCellIncidenceFailureKind::CellNotClosed:
    return "cell-not-closed";
  case SurfaceCellIncidenceFailureKind::CellTooSmall:
    return "cell-too-small";
  case SurfaceCellIncidenceFailureKind::NonDiskCell:
    return "non-disk-cell";
  case SurfaceCellIncidenceFailureKind::SideMetadataMismatch:
    return "side-metadata-mismatch";
  case SurfaceCellIncidenceFailureKind::RepeatedCellHalfedge:
    return "repeated-cell-halfedge";
  case SurfaceCellIncidenceFailureKind::HalfedgeCellMismatch:
    return "halfedge-cell-mismatch";
  case SurfaceCellIncidenceFailureKind::CellNextMismatch:
    return "cell-next-mismatch";
  case SurfaceCellIncidenceFailureKind::HalfedgeUseMismatch:
    return "halfedge-use-mismatch";
  case SurfaceCellIncidenceFailureKind::DirectedEdgeMultiplicity:
    return "directed-edge-multiplicity";
  case SurfaceCellIncidenceFailureKind::PredecessorMultiplicity:
    return "predecessor-multiplicity";
  case SurfaceCellIncidenceFailureKind::OwnershipRegistryMismatch:
    return "ownership-registry-mismatch";
  }
  return "unknown";
}

struct SurfaceCellIncidenceAudit {
  bool valid = false;
  SurfaceCellIncidenceFailureKind failure =
      SurfaceCellIncidenceFailureKind::None;
  int node = -1;
  int halfedge = -1;
  int twin = -1;
  int next = -1;
  int cell = -1;
  int expected = -1;
  int actual = -1;
};

SurfaceCellIncidenceAudit audit_complex_incidence(
    const SurfaceCellComplex &complex, bool requireDiskCells = true);

bool validate_complex_incidence(const SurfaceCellComplex &complex,
                                bool requireDiskCells = true);

int non_disk_topology_defect(const SurfaceCellComplex &complex);

std::vector<std::int64_t> protected_node_signature(
    const SurfaceArrangementNode &node);

struct SourceScope {
  std::optional<authority::TopologyRegionId> region;
  std::optional<SourceProjectionChart> chart;

  auto operator<=>(const SourceScope &) const = default;
};

struct SourceAwareIdentity {
  std::vector<std::int64_t> values;
  std::vector<SourceScope> sourceScopes;

  auto operator<=>(const SourceAwareIdentity &) const = default;
};

std::multiset<SourceAwareIdentity> protected_support(
    const SurfaceCellComplex &complex);

bool same_protected_support(const SurfaceCellComplex &before,
                                   const SurfaceCellComplex &after);

bool order_boundary_cycle(const SurfaceCellComplex &complex,
                                 const std::vector<int> &input,
                                 std::vector<int> &ordered);

void classify_rebuilt_cell_sides(
    SurfaceArrangementCell &cell, const SurfaceCellComplex &complex,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces);

void recompute_rebuilt_diagnostics(SurfaceCellComplex &complex);

SurfaceCellComplex rebuild_complex_after_halfedge_removal(
    const SurfaceCellComplex &complex, const std::set<int> &requestedRemoval,
    const Eigen::MatrixXd *vertices = nullptr,
    const Eigen::MatrixXi *faces = nullptr);

std::vector<SurfaceSimplificationCandidate> recompute_overlap_candidates(
    const SurfaceCellComplex &complex, const std::set<int> &affectedNodes,
    const int nextStableBase);

} // namespace surface_simplification_detail


SurfaceSimplificationCandidateSet
extract_surface_simplification_candidates_impl(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd *vertices,
    const Eigen::MatrixXi *faces,
    const SurfaceSimplificationCandidateExtractionOptions &options);

SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceSimplificationCandidateExtractionOptions &options = {});

SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    const SurfaceSimplificationCandidateExtractionOptions &options = {});

std::vector<SurfaceSimplificationElement>
make_simplification_elements_from_complex(const SurfaceCellComplex &complex);

SurfaceSimplificationCandidate make_removal_candidate(
    const int stableId, const SurfaceSimplificationCandidateType type,
    std::vector<int> elementIds, const double cost = -1.0);

SurfaceSimplificationResult simplify_surface_complex(
    std::vector<SurfaceSimplificationElement> elements,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {});

SurfaceSimplificationResult simplify_surface_cell_complex_impl(
    SurfaceCellComplex inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces,
    const SurfaceSimplificationOptions &options);

SurfaceSimplificationResult simplify_surface_cell_complex(
    SurfaceCellComplex inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {});

SurfaceSimplificationResult simplify_surface_cell_complex(
    SurfaceCellComplex inputComplex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {});

SurfaceSimplificationOverlay
make_surface_simplification_overlay(const SurfaceSimplificationResult &result);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H
