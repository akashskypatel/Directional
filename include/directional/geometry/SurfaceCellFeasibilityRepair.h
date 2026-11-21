// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_FEASIBILITY_REPAIR_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_FEASIBILITY_REPAIR_H

#include <cstdint>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <directional/geometry/SurfaceArrangement.h>

namespace directional::geometry {

struct SurfaceCellReplacementScopeFailure {
  bool active = false;
  int originalCell = -1;
  int replacementCell = -1;
  int halfedge = -1;
  int twin = -1;
  int selectedComponent = -1;
  int selectedSheet = -1;
  std::vector<int> availableComponents;
  std::vector<int> availableSheets;
  std::string mutationPhase;
};

enum class SurfaceCellSubdivisionFailureKind : int {
  None = 0,
  InvalidInputIncidence = 1,
  InvalidInsertionCount = 2,
  InvalidHalfedge = 3,
  ConflictingTwinInsertionCount = 4,
  MissingCellSourceScope = 5,
  InvalidCellHalfedge = 6,
  MixedCellSourceScope = 7,
  InvalidTwinPair = 8,
  MissingCommonSourceChart = 9,
  InvalidMidpointEmbedding = 10,
  MissingHalfedgeReplacement = 11,
  InvalidSideMetadata = 12,
  MissingReplacementSourceOccurrence = 13,
  MissingCellSourceSupport = 14,
  InvalidReplacementBoundary = 15,
  InvalidOutputIncidence = 16,
  RollbackMismatch = 17,
};

inline const char *surface_cell_subdivision_failure_kind_name(
    const SurfaceCellSubdivisionFailureKind kind) {
  switch (kind) {
  case SurfaceCellSubdivisionFailureKind::None:
    return "None";
  case SurfaceCellSubdivisionFailureKind::InvalidInputIncidence:
    return "InvalidInputIncidence";
  case SurfaceCellSubdivisionFailureKind::InvalidInsertionCount:
    return "InvalidInsertionCount";
  case SurfaceCellSubdivisionFailureKind::InvalidHalfedge:
    return "InvalidHalfedge";
  case SurfaceCellSubdivisionFailureKind::ConflictingTwinInsertionCount:
    return "ConflictingTwinInsertionCount";
  case SurfaceCellSubdivisionFailureKind::MissingCellSourceScope:
    return "MissingCellSourceScope";
  case SurfaceCellSubdivisionFailureKind::InvalidCellHalfedge:
    return "InvalidCellHalfedge";
  case SurfaceCellSubdivisionFailureKind::MixedCellSourceScope:
    return "MixedCellSourceScope";
  case SurfaceCellSubdivisionFailureKind::InvalidTwinPair:
    return "InvalidTwinPair";
  case SurfaceCellSubdivisionFailureKind::MissingCommonSourceChart:
    return "MissingCommonSourceChart";
  case SurfaceCellSubdivisionFailureKind::InvalidMidpointEmbedding:
    return "InvalidMidpointEmbedding";
  case SurfaceCellSubdivisionFailureKind::MissingHalfedgeReplacement:
    return "MissingHalfedgeReplacement";
  case SurfaceCellSubdivisionFailureKind::InvalidSideMetadata:
    return "InvalidSideMetadata";
  case SurfaceCellSubdivisionFailureKind::MissingReplacementSourceOccurrence:
    return "MissingReplacementSourceOccurrence";
  case SurfaceCellSubdivisionFailureKind::MissingCellSourceSupport:
    return "MissingCellSourceSupport";
  case SurfaceCellSubdivisionFailureKind::InvalidReplacementBoundary:
    return "InvalidReplacementBoundary";
  case SurfaceCellSubdivisionFailureKind::InvalidOutputIncidence:
    return "InvalidOutputIncidence";
  case SurfaceCellSubdivisionFailureKind::RollbackMismatch:
    return "RollbackMismatch";
  }
  return "Unknown";
}

struct SurfaceCellSubdivisionProduct {
  SurfaceCellComplex complex;
  bool rollbackEquivalent = false;
  std::uint64_t rollbackIdentityHashBefore = 0U;
  std::uint64_t rollbackIdentityHashAfter = 0U;
  std::uint64_t rollbackUndoOwnedBytes = 0U;
  int splitUndirectedEdges = 0;
  int insertedVertices = 0;
  int hardFeatureSplits = 0;
  SurfaceCellReplacementScopeFailure firstScopeFailure;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
};

struct SurfaceCellSubdivisionFailure {
  SurfaceCellSubdivisionFailureKind kind = SurfaceCellSubdivisionFailureKind::None;
  std::string detail;
  bool rollbackEquivalent = false;
  std::uint64_t rollbackIdentityHashBefore = 0U;
  std::uint64_t rollbackIdentityHashAfter = 0U;
  std::uint64_t rollbackUndoOwnedBytes = 0U;
  int splitUndirectedEdges = 0;
  int insertedVertices = 0;
  int hardFeatureSplits = 0;
  SurfaceCellReplacementScopeFailure firstScopeFailure;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
};

class SurfaceCellSubdivisionResult {
public:
  using Product = SurfaceCellSubdivisionProduct;
  using Failure = SurfaceCellSubdivisionFailure;
  using Outcome = ProducerOutcome<Product, Failure>;

  [[nodiscard]] static SurfaceCellSubdivisionResult produced(Product product) {
    return SurfaceCellSubdivisionResult(
        Outcome{Produced<Product>{std::move(product)}}, std::nullopt);
  }

  [[nodiscard]] static SurfaceCellSubdivisionResult rejected(
      Failure failure,
      std::optional<SurfaceCellComplex> rollbackEvidence = std::nullopt) {
    if (failure.kind == SurfaceCellSubdivisionFailureKind::None) {
      throw std::invalid_argument(
          "Rejected subdivision outcome requires a typed failure.");
    }
    return SurfaceCellSubdivisionResult(
        Outcome{Rejected<Failure>{std::move(failure)}},
        std::move(rollbackEvidence));
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

  [[nodiscard]] const Product &product() const {
    return std::get<Produced<Product>>(outcome_).product;
  }

  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }

  [[nodiscard]] bool rollback_matches(
      const SurfaceCellComplex &expected) const;

  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }
  [[nodiscard]] Outcome &&outcome() && noexcept { return std::move(outcome_); }

private:
  SurfaceCellSubdivisionResult(
      Outcome outcome, std::optional<SurfaceCellComplex> rollbackEvidence)
      : outcome_(std::move(outcome)),
        rollbackEvidence_(std::move(rollbackEvidence)) {}

  Outcome outcome_;
  std::optional<SurfaceCellComplex> rollbackEvidence_;
};

/**
 * Subdivide canonical undirected arrangement edges transactionally.
 *
 * The map key is any halfedge ID; its twin is canonicalized automatically.
 * The value is the number of vertices inserted on that edge. Both incident
 * cell cycles, all provenance intervals, rail parameters, and side subdivision
 * counts are updated together.
 */
SurfaceCellSubdivisionResult subdivide_surface_cell_complex_edges(
    SurfaceCellComplex input,
    const std::map<int, int> &insertionsByHalfedge,
    const Eigen::MatrixXi *sourceFaces = nullptr);

enum class SurfaceCellParityAlternativeDisposition : int {
  None = 0,
  Committed = 1,
  NoCandidate = 2,
  CycleDetected = 3,
  BudgetExhausted = 4,
  AllInvalid = 5,
};

inline const char *surface_cell_parity_alternative_disposition_name(
    const SurfaceCellParityAlternativeDisposition disposition) {
  switch (disposition) {
  case SurfaceCellParityAlternativeDisposition::None:
    return "none";
  case SurfaceCellParityAlternativeDisposition::Committed:
    return "committed";
  case SurfaceCellParityAlternativeDisposition::NoCandidate:
    return "no-candidate";
  case SurfaceCellParityAlternativeDisposition::CycleDetected:
    return "cycle-detected";
  case SurfaceCellParityAlternativeDisposition::BudgetExhausted:
    return "budget-exhausted";
  case SurfaceCellParityAlternativeDisposition::AllInvalid:
    return "all-invalid";
  }
  return "unknown";
}

enum class SurfaceCellParityRepairFailureKind : int {
  None = 0,
  InvalidInputIncidence = 1,
  DisconnectedDualComponent = 2,
  UnpairableOddCell = 3,
  UnpairableClosedComponentParity = 4,
  SubdivisionRejected = 5,
  UnexpectedSubdivisionNotApplicable = 6,
  ParityRepairIncomplete = 7,
};

inline const char *surface_cell_parity_repair_failure_kind_name(
    const SurfaceCellParityRepairFailureKind kind) {
  switch (kind) {
  case SurfaceCellParityRepairFailureKind::None:
    return "None";
  case SurfaceCellParityRepairFailureKind::InvalidInputIncidence:
    return "InvalidInputIncidence";
  case SurfaceCellParityRepairFailureKind::DisconnectedDualComponent:
    return "DisconnectedDualComponent";
  case SurfaceCellParityRepairFailureKind::UnpairableOddCell:
    return "UnpairableOddCell";
  case SurfaceCellParityRepairFailureKind::UnpairableClosedComponentParity:
    return "UnpairableClosedComponentParity";
  case SurfaceCellParityRepairFailureKind::SubdivisionRejected:
    return "SubdivisionRejected";
  case SurfaceCellParityRepairFailureKind::UnexpectedSubdivisionNotApplicable:
    return "UnexpectedSubdivisionNotApplicable";
  case SurfaceCellParityRepairFailureKind::ParityRepairIncomplete:
    return "ParityRepairIncomplete";
  }
  return "Unknown";
}

struct SurfaceCellParityRepairProduct {
  SurfaceCellComplex complex;
  std::vector<int> splitHalfedges;
  int oddCellsBefore = 0;
  int oddCellsAfter = 0;
  int hardFeatureSplits = 0;
  int alternativeCandidateBudget = 0;
  int alternativeCandidatesAttempted = 0;
  int alternativeVisitedStates = 0;
  int alternativeSelectedExclusion = -1;
  std::uint64_t alternativeStateSequenceHash = 0U;
  std::vector<std::uint64_t> alternativeStateHashes;
  SurfaceCellParityAlternativeDisposition alternativeDisposition =
      SurfaceCellParityAlternativeDisposition::None;
  SurfaceCellReplacementScopeFailure firstScopeFailure;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
};

struct SurfaceCellParityRepairFailure {
  SurfaceCellParityRepairFailureKind kind = SurfaceCellParityRepairFailureKind::None;
  std::string detail;
  std::vector<int> splitHalfedges;
  int oddCellsBefore = 0;
  int oddCellsAfter = 0;
  int hardFeatureSplits = 0;
  int alternativeCandidateBudget = 0;
  int alternativeCandidatesAttempted = 0;
  int alternativeVisitedStates = 0;
  int alternativeSelectedExclusion = -1;
  std::uint64_t alternativeStateSequenceHash = 0U;
  std::vector<std::uint64_t> alternativeStateHashes;
  SurfaceCellParityAlternativeDisposition alternativeDisposition =
      SurfaceCellParityAlternativeDisposition::None;
  SurfaceCellReplacementScopeFailure firstScopeFailure;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
  std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure;
};

class SurfaceCellParityRepairResult {
public:
  using Product = SurfaceCellParityRepairProduct;
  using Failure = SurfaceCellParityRepairFailure;
  using Outcome = ProducerOutcome<Product, Failure>;

  [[nodiscard]] static SurfaceCellParityRepairResult produced(Product product) {
    return SurfaceCellParityRepairResult(
        Outcome{Produced<Product>{std::move(product)}});
  }

  [[nodiscard]] static SurfaceCellParityRepairResult rejected(Failure failure) {
    if (failure.kind == SurfaceCellParityRepairFailureKind::None) {
      throw std::invalid_argument(
          "Rejected parity-repair outcome requires a typed failure.");
    }
    return SurfaceCellParityRepairResult(
        Outcome{Rejected<Failure>{std::move(failure)}});
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

  [[nodiscard]] const Product &product() const {
    return std::get<Produced<Product>>(outcome_).product;
  }

  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }

  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }
  [[nodiscard]] Outcome &&outcome() && noexcept { return std::move(outcome_); }

private:
  explicit SurfaceCellParityRepairResult(Outcome outcome)
      : outcome_(std::move(outcome)) {}

  Outcome outcome_;
};

/**
 * Solve the all-quad disk boundary parity constraints on the cell dual graph.
 * A deterministic minimum-hard-edge spanning forest pairs odd cells (or joins
 * them to an exterior boundary), then performs conforming shared-edge splits.
 */
SurfaceCellParityRepairResult repair_surface_cell_boundary_parity(
    SurfaceCellComplex input);

struct SurfaceCellSideRepairOptions {
  int maxInsertedVertices = 100000;
  int maxLocalInsertedVertices = 512;
  int maxPropagationPasses = 4096;
  int maxStagnantPasses = 64;
};

enum class SurfaceCellSideRepairFailureKind : int {
  None = 0,
  InvalidSideRepairOptions = 1,
  InvalidInputIncidence = 2,
  LocalSideInsertionLimit = 3,
  MissingSideSubdivisionEdge = 4,
  SideRepairStalled = 5,
  CoupledSideRepairStalled = 6,
  SideRepairInsertionLimit = 7,
  SideRepairPropagationLimit = 8,
  SubdivisionRejected = 9,
  UnexpectedSubdivisionNotApplicable = 10,
  SideRepairIncomplete = 11,
  RollbackMismatch = 12,
};

inline const char *surface_cell_side_repair_failure_kind_name(
    const SurfaceCellSideRepairFailureKind kind) {
  switch (kind) {
  case SurfaceCellSideRepairFailureKind::None:
    return "None";
  case SurfaceCellSideRepairFailureKind::InvalidSideRepairOptions:
    return "InvalidSideRepairOptions";
  case SurfaceCellSideRepairFailureKind::InvalidInputIncidence:
    return "InvalidInputIncidence";
  case SurfaceCellSideRepairFailureKind::LocalSideInsertionLimit:
    return "LocalSideInsertionLimit";
  case SurfaceCellSideRepairFailureKind::MissingSideSubdivisionEdge:
    return "MissingSideSubdivisionEdge";
  case SurfaceCellSideRepairFailureKind::SideRepairStalled:
    return "SideRepairStalled";
  case SurfaceCellSideRepairFailureKind::CoupledSideRepairStalled:
    return "CoupledSideRepairStalled";
  case SurfaceCellSideRepairFailureKind::SideRepairInsertionLimit:
    return "SideRepairInsertionLimit";
  case SurfaceCellSideRepairFailureKind::SideRepairPropagationLimit:
    return "SideRepairPropagationLimit";
  case SurfaceCellSideRepairFailureKind::SubdivisionRejected:
    return "SubdivisionRejected";
  case SurfaceCellSideRepairFailureKind::UnexpectedSubdivisionNotApplicable:
    return "UnexpectedSubdivisionNotApplicable";
  case SurfaceCellSideRepairFailureKind::SideRepairIncomplete:
    return "SideRepairIncomplete";
  case SurfaceCellSideRepairFailureKind::RollbackMismatch:
    return "RollbackMismatch";
  }
  return "Unknown";
}

enum class SurfaceCellSideRepairProductKind : int {
  Repaired = 0,
  GeneralFallbackPreparation = 1,
};

enum class SurfaceCellSideRepairPreparationReason : int {
  None = 0,
  LocalSideInsertionLimit = 1,
  CoupledSideRepairStalled = 2,
  SideRepairInsertionLimit = 3,
  SideRepairPropagationLimit = 4,
};

struct SurfaceCellSideRepairProduct {
  SurfaceCellSideRepairProductKind kind = SurfaceCellSideRepairProductKind::Repaired;
  SurfaceCellSideRepairPreparationReason preparationReason =
      SurfaceCellSideRepairPreparationReason::None;
  std::string preparationDetail;
  SurfaceCellComplex complex;
  bool rollbackEquivalent = false;
  std::uint64_t rollbackIdentityHashBefore = 0U;
  std::uint64_t rollbackIdentityHashAfter = 0U;
  std::uint64_t rollbackUndoOwnedBytes = 0U;
  int infeasibleCellsBefore = 0;
  int infeasibleCellsAfter = 0;
  int initialEquationDefect = 0;
  int finalEquationDefect = 0;
  int propagationPasses = 0;
  int attemptedInsertions = 0;
  int insertedVertices = 0;
  int splitUndirectedEdges = 0;
  int hardFeatureSplits = 0;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
};

struct SurfaceCellSideRepairFailure {
  SurfaceCellSideRepairFailureKind kind = SurfaceCellSideRepairFailureKind::None;
  std::string detail;
  bool rollbackEquivalent = false;
  std::uint64_t rollbackIdentityHashBefore = 0U;
  std::uint64_t rollbackIdentityHashAfter = 0U;
  std::uint64_t rollbackUndoOwnedBytes = 0U;
  int infeasibleCellsBefore = 0;
  int infeasibleCellsAfter = 0;
  int initialEquationDefect = 0;
  int finalEquationDefect = 0;
  int propagationPasses = 0;
  int attemptedInsertions = 0;
  int insertedVertices = 0;
  int splitUndirectedEdges = 0;
  int hardFeatureSplits = 0;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
  std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure;
};

class SurfaceCellSideRepairResult {
public:
  using Product = SurfaceCellSideRepairProduct;
  using Failure = SurfaceCellSideRepairFailure;
  using Outcome = ProducerOutcome<Product, Failure>;

  [[nodiscard]] static SurfaceCellSideRepairResult produced(Product product) {
    return SurfaceCellSideRepairResult(
        Outcome{Produced<Product>{std::move(product)}}, std::nullopt);
  }

  [[nodiscard]] static SurfaceCellSideRepairResult rejected(
      Failure failure,
      std::optional<SurfaceCellComplex> rollbackEvidence = std::nullopt) {
    if (failure.kind == SurfaceCellSideRepairFailureKind::None) {
      throw std::invalid_argument(
          "Rejected side-repair outcome requires a typed failure.");
    }
    return SurfaceCellSideRepairResult(
        Outcome{Rejected<Failure>{std::move(failure)}},
        std::move(rollbackEvidence));
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

  [[nodiscard]] const Product &product() const {
    return std::get<Produced<Product>>(outcome_).product;
  }

  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }

  [[nodiscard]] bool rollback_matches(
      const SurfaceCellComplex &expected) const;

  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }
  [[nodiscard]] Outcome &&outcome() && noexcept { return std::move(outcome_); }

private:
  SurfaceCellSideRepairResult(
      Outcome outcome, std::optional<SurfaceCellComplex> rollbackEvidence)
      : outcome_(std::move(outcome)),
        rollbackEvidence_(std::move(rollbackEvidence)) {}

  Outcome outcome_;
  std::optional<SurfaceCellComplex> rollbackEvidence_;
};

/**
 * Balance the integer side-subdivision equations for every disk cell with
 * three through six logical sides. Insertions are shared variables on the
 * arrangement dual, so a subdivision is always applied to both incident
 * patches and the system is iterated until all coupled equations agree.
 */
SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
    SurfaceCellComplex input,
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const SurfaceCellSideRepairOptions &options = {});

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CELL_FEASIBILITY_REPAIR_H
