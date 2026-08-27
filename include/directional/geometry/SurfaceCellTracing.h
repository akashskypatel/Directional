// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_TRACING_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_TRACING_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>

#include <Eigen/Dense>

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/CanonicalRoute.h>
#include <directional/authority/FieldTransportAtlas.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/ReliefTopology.h>
#include <directional/geometry/SourceTopologyRegions.h>

namespace directional {
class TriMesh;
}

namespace directional::geometry {

enum class SurfaceSeedProvenance : int {
  Boundary = 0,
  Feature = 1,
  Singularity = 2,
  ReliefCritical = 3,
  Separatrix = 4,
  Anchor = 5,
  AdaptiveFarthest = 6,
};

enum class TraceTerminationReason : int {
  Boundary = 0,
  Feature = 1,
  Captured = 2,
  Singularity = 3,
  RepeatedState = 4,
  Budget = 5,
  Degenerate = 6,
  FieldMetadata = 7,
  SourceSheet = 8,
};

enum class CellRejectionReason : int {
  Accepted = 0,
  Closure = 1,
  Barrier = 2,
  Degenerate = 3,
  SourceSheet = 4,
  FieldMetadata = 5,
  SelfIntersection = 6,
  Inverted = 7,
  DuplicateCorner = 8,
  OutOfSize = 9,
  HardRailCrossing = 10,
};

enum class SurfaceCellRailKind : int {
  Boundary = 0,
  HardFeature = 1,
};

struct SurfaceTracePoint {
  int face = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
};

struct SurfaceCellRailSample {
  int sourceFace = -1;
  int sourceEdge = -1;
  double parameter = 0.0;
  double railParameter = 0.0;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
};

struct SurfaceCellRail {
  explicit SurfaceCellRail(authority::HardRailId railId) : id(railId) {}

  authority::HardRailId id;
  SurfaceCellRailKind kind = SurfaceCellRailKind::Boundary;
  int curveId = -1;
  int component = -1;
  bool closed = false;
  std::vector<int> sourceVertices;
  std::vector<int> sourceEdges;
  std::vector<SurfaceCellRailSample> samples;
};


enum class FieldAlignedCurveNetworkErrorCode : int {
  InvalidSourceBinding = 0,
  InvalidAtlasBinding = 1,
  DuplicateRailId = 2,
  InvalidRailGeometry = 3,
  MissingMandatoryEdge = 4,
  DuplicateMandatoryEdge = 5,
  ForeignMandatoryEdge = 6,
  MandatoryKindMismatch = 7,
  MandatoryOwnerMismatch = 8,
  InvalidSingularityBinding = 9,
  InvalidSingularityPortCount = 10,
  InvalidSingularityPortOwnership = 11,
  InvalidCandidateTraceBinding = 12,
  InvalidCandidateTraceTransport = 13,
  InvalidNetworkEventBinding = 14,
  InvalidNetworkEventIncidence = 15,
  InvalidNetworkTerminalOwnership = 16,
  BranchDirectionNotBarycentric = 17,
  BranchContinuationNoOutflow = 18,
  BranchContinuationDegenerateEntry = 19,
  BranchContinuationMinimizerImpossible = 20,
  BranchContinuationOutsideOutflowSet = 21,
  BoundaryPointParameterOutOfRange = 22,
  BoundaryPointEdgeNotIncidentToFace = 23,
  VertexTransitSectorUnresolved = 24,
  // Retired production rejection. Grazing is now a classified continuation
  // and this value is retained only for stable historical diagnostics.
  BranchTransportFlowDisagreement = 25,
  TraceStateCycleDetected = 26,
  TraceStepBudgetExhausted = 27,
  BranchGrazingSlideDirectionAmbiguous = 28,
  // A trace re-entered a position-free (face, branch, incoming carrier) state
  // more times than a terminating trace ever needs. Until crash-on-contact
  // (DESIGN.md 4.6) is produced by A2a, this is the sound combinatorial
  // stand-in for it: it is exact, position-free, and never a tolerance.
  TraceCombinatorialRecurrenceExceeded = 29,
  // An exact continuation value grew past the deterministic magnitude policy.
  // Independent backstop for a circulation that never repeats a combinatorial
  // state; it declines to answer rather than answering approximately.
  BranchContinuationExactMagnitudeExceeded = 30,
};

struct FieldAlignedTraceStepDiagnostic {
  authority::SourceFaceTopologyKey sourceFace;
  authority::FieldBranch branch;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  authority::ExactUnitParameter entryParameter;

  auto operator<=>(const FieldAlignedTraceStepDiagnostic &) const = default;
};

struct FieldAlignedCurveNetworkError {
  FieldAlignedCurveNetworkErrorCode code =
      FieldAlignedCurveNetworkErrorCode::InvalidSourceBinding;
  std::optional<authority::SourceVertexId> sourceVertex;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
  std::optional<authority::HardRailId> rail;
  std::optional<authority::FieldSingularityId> singularity;
  std::optional<authority::SourceFaceTopologyKey> sourceFace;
  std::optional<authority::SourceFaceTopologyKey> relatedSourceFace;
  std::optional<authority::FieldBranch> branch;
  std::optional<authority::FieldBranch> relatedBranch;
  std::optional<int> signedLift;
  std::optional<authority::ExactUnitParameter> parameter;
  std::vector<authority::FieldExactRational> exactValues;
  std::vector<authority::SourceEdgeTopologyKey> publishedEdges;
  std::vector<authority::SourceFaceTopologyKey> publishedFaces;
  std::optional<authority::SourceVertexId> traceSeedVertex;
  std::optional<authority::FieldSingularityId> traceSeedSingularity;
  std::vector<FieldAlignedTraceStepDiagnostic> traceHistory;
  std::optional<std::size_t> traceSteps;
  std::optional<std::size_t> traceStepBudget;
  std::optional<std::size_t> traceCombinatorialVisits;
  std::optional<std::size_t> traceCombinatorialVisitAllowance;

  auto operator<=>(const FieldAlignedCurveNetworkError &) const = default;
};

struct FieldAlignedCurveNetworkNode {
  FieldAlignedCurveNetworkNode(authority::NetworkNodeId nodeId,
                               authority::SourceVertexId vertex)
      : id(nodeId), sourceVertex(vertex) {}

  authority::NetworkNodeId id;
  authority::SourceVertexId sourceVertex;

  auto operator<=>(const FieldAlignedCurveNetworkNode &) const = default;
};

struct FieldAlignedSingularityPort {
  FieldAlignedSingularityPort(
      authority::SingularityPortId portId,
      authority::FieldSingularityId singularityId,
      authority::NetworkNodeId nodeId, authority::SourceVertexId vertex,
      authority::SourceComponentId component,
      authority::TopologyRegionId topologyRegion, int index, int portOrdinal)
      : id(portId), singularity(singularityId), node(nodeId),
        sourceVertex(vertex), sourceComponent(component),
        sourceTopologyRegion(topologyRegion), indexNumerator(index),
        ordinal(portOrdinal) {}

  authority::SingularityPortId id;
  authority::FieldSingularityId singularity;
  authority::NetworkNodeId node;
  authority::SourceVertexId sourceVertex;
  authority::SourceComponentId sourceComponent;
  authority::TopologyRegionId sourceTopologyRegion;
  int indexNumerator = 0;
  int ordinal = 0;

  auto operator<=>(const FieldAlignedSingularityPort &) const = default;
};

struct FieldAlignedCandidateTraceTransition {
  FieldAlignedCandidateTraceTransition(
      authority::SourceEdgeTopologyKey sourceEdgeValue,
      authority::SourceFaceTopologyKey fromFaceValue,
      authority::SourceFaceTopologyKey toFaceValue,
      authority::FieldDirectedBranchTransport directedValue)
      : sourceEdge(std::move(sourceEdgeValue)),
        fromFace(std::move(fromFaceValue)), toFace(std::move(toFaceValue)),
        directed(std::move(directedValue)) {}

  authority::SourceEdgeTopologyKey sourceEdge;
  authority::SourceFaceTopologyKey fromFace;
  authority::SourceFaceTopologyKey toFace;
  authority::FieldDirectedBranchTransport directed;

  auto operator<=>(const FieldAlignedCandidateTraceTransition &) const = default;
};

struct FieldAlignedCandidateTraceSegment {
  FieldAlignedCandidateTraceSegment(
      authority::SourceFaceTopologyKey faceValue,
      authority::FieldBranch branchValue,
      authority::FieldBoundaryPoint entryPointValue,
      std::optional<authority::SourceEdgeTopologyKey> incomingCarrierValue,
      authority::SourceEdgeTopologyKey outgoingCarrierValue,
      std::optional<FieldAlignedCandidateTraceTransition> entryTransportValue)
      : sourceFace(std::move(faceValue)), branch(branchValue),
        entryPoint(std::move(entryPointValue)),
        incomingCarrier(std::move(incomingCarrierValue)),
        outgoingCarrier(std::move(outgoingCarrierValue)),
        entryTransport(std::move(entryTransportValue)) {}

  authority::SourceFaceTopologyKey sourceFace;
  authority::FieldBranch branch;
  authority::FieldBoundaryPoint entryPoint;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  authority::SourceEdgeTopologyKey outgoingCarrier;
  std::optional<FieldAlignedCandidateTraceTransition> entryTransport;
  std::optional<authority::FieldBoundaryPoint> edgeTransitExit;

  auto operator<=>(const FieldAlignedCandidateTraceSegment &) const = default;
};

struct FieldAlignedCandidateTrace {
  FieldAlignedCandidateTrace(
      authority::TraceId traceId, authority::SingularityPortId portId,
      authority::FieldSingularityId singularityId,
      authority::SourceVertexId sourceVertexValue,
      authority::SourceComponentId sourceComponentValue,
      authority::TopologyRegionId sourceTopologyRegionValue)
      : id(traceId), port(portId), singularity(singularityId),
        sourceVertex(sourceVertexValue), sourceComponent(sourceComponentValue),
        sourceTopologyRegion(sourceTopologyRegionValue) {}

  authority::TraceId id;
  authority::SingularityPortId port;
  authority::FieldSingularityId singularity;
  authority::SourceVertexId sourceVertex;
  authority::SourceComponentId sourceComponent;
  authority::TopologyRegionId sourceTopologyRegion;
  std::vector<FieldAlignedCandidateTraceSegment> segments;
  std::optional<authority::SourceEdgeTopologyKey> terminalBarrier;
  std::optional<authority::FieldBoundaryPoint> terminalPoint;
  std::optional<authority::FieldSingularityId> terminalSingularity;

  auto operator<=>(const FieldAlignedCandidateTrace &) const = default;
};

enum class FieldAlignedNetworkEventKind : std::uint8_t {
  SingularityPortOrigin = 0,
  FirstContact = 1,
  TraceIntersection = 2,
  MandatoryBarrierTermination = 3,
  SingularityTermination = 4,
};

enum class FieldAlignedTraceEventRole : std::uint8_t {
  Interior = 0,
  Origin = 1,
  Terminal = 2,
};

struct FieldAlignedNetworkEventIncidence {
  FieldAlignedNetworkEventIncidence(
      authority::TraceId traceValue, authority::SingularityPortId sourcePortValue,
      FieldAlignedTraceEventRole roleValue)
      : trace(traceValue), sourcePort(sourcePortValue), role(roleValue) {}

  authority::TraceId trace;
  authority::SingularityPortId sourcePort;
  FieldAlignedTraceEventRole role = FieldAlignedTraceEventRole::Interior;

  auto operator<=>(const FieldAlignedNetworkEventIncidence &) const = default;
};

struct FieldAlignedNetworkEvent {
  FieldAlignedNetworkEvent(
      authority::NetworkNodeId nodeValue, FieldAlignedNetworkEventKind kindValue,
      authority::SourceFaceTopologyKey sourceFaceValue,
      std::optional<authority::SourceEdgeTopologyKey> sourceEdgeValue,
      std::vector<FieldAlignedNetworkEventIncidence> incidencesValue)
      : node(nodeValue), kind(kindValue), sourceFace(std::move(sourceFaceValue)),
        sourceEdge(std::move(sourceEdgeValue)),
        incidences(std::move(incidencesValue)) {}

  authority::NetworkNodeId node;
  FieldAlignedNetworkEventKind kind =
      FieldAlignedNetworkEventKind::FirstContact;
  authority::SourceFaceTopologyKey sourceFace;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
  std::vector<FieldAlignedNetworkEventIncidence> incidences;

  auto operator<=>(const FieldAlignedNetworkEvent &) const = default;
};

struct FieldAlignedMandatoryEdge {
  FieldAlignedMandatoryEdge(
      authority::NetworkEdgeId edgeId, authority::HardRailId railId,
      authority::SourceEdgeTopologyKey sourceEdgeValue,
      SurfaceCellRailKind edgeKind, authority::NetworkNodeId first,
      authority::NetworkNodeId second,
      authority::SourceComponentId component,
      std::vector<authority::TopologyRegionId> topologyRegions)
      : id(edgeId), rail(railId), sourceEdge(std::move(sourceEdgeValue)),
        kind(edgeKind), firstNode(first), secondNode(second),
        sourceComponent(component),
        sourceTopologyRegions(std::move(topologyRegions)) {}

  authority::NetworkEdgeId id;
  authority::HardRailId rail;
  authority::SourceEdgeTopologyKey sourceEdge;
  SurfaceCellRailKind kind = SurfaceCellRailKind::Boundary;
  authority::NetworkNodeId firstNode;
  authority::NetworkNodeId secondNode;
  authority::SourceComponentId sourceComponent;
  std::vector<authority::TopologyRegionId> sourceTopologyRegions;

  auto operator<=>(const FieldAlignedMandatoryEdge &) const = default;
};

/**
 * Mutable representation snapshot accepted only by the checked construction
 * seam. It is not semantic authority and is exposed solely for independent
 * tamper/negative contracts.
 */
struct FieldAlignedCurveNetworkCandidate {
  std::vector<FieldAlignedCurveNetworkNode> nodes;
  std::vector<FieldAlignedSingularityPort> singularityPorts;
  std::vector<FieldAlignedMandatoryEdge> mandatoryEdges;
  std::vector<FieldAlignedCandidateTrace> candidateTraces;
  std::vector<FieldAlignedNetworkEvent> events;
  // Exact construction provenance. These bind validation snapshots to the
  // source/atlas instances that produced them; they are intentionally not the
  // network semantic identity.
  std::uint64_t sourceDigest = 0U;
  std::uint64_t atlasDigest = 0U;
};

class FieldAlignedCurveNetworkBuildResult;

/**
 * Immutable A2a ownership/tracing product. Construction is the only writer;
 * CP3b extends accepted branch-consistent candidate traces with a typed
 * first-contact/intersection/termination event graph. Global topology
 * selection, region emission, and schedules remain later-stage authority.
 */
class FieldAlignedCurveNetwork {
public:
  [[nodiscard]] static FieldAlignedCurveNetworkBuildResult make(
      const TriMesh &sourceMesh,
      const SourceTopologyRegions &sourceAuthority,
      const authority::FieldTransportAtlas &fieldTransportAtlas,
      const std::vector<SurfaceCellRail> &authoritativeRails);

  [[nodiscard]] static FieldAlignedCurveNetworkBuildResult make_from_candidate(
      const TriMesh &sourceMesh,
      const SourceTopologyRegions &sourceAuthority,
      const authority::FieldTransportAtlas &fieldTransportAtlas,
      const std::vector<SurfaceCellRail> &authoritativeRails,
      FieldAlignedCurveNetworkCandidate candidate);

  [[nodiscard]] const std::vector<FieldAlignedCurveNetworkNode> &nodes() const
      noexcept {
    return nodes_;
  }
  [[nodiscard]] const std::vector<FieldAlignedSingularityPort> &
  singularity_ports() const noexcept {
    return singularityPorts_;
  }
  [[nodiscard]] const std::vector<FieldAlignedMandatoryEdge> &
  mandatory_edges() const noexcept {
    return mandatoryEdges_;
  }
  [[nodiscard]] const std::vector<FieldAlignedCandidateTrace> &
  candidate_traces() const noexcept {
    return candidateTraces_;
  }
  [[nodiscard]] const std::vector<FieldAlignedNetworkEvent> &events() const
      noexcept {
    return events_;
  }

  [[nodiscard]] const FieldAlignedMandatoryEdge *find_mandatory_edge(
      const authority::SourceEdgeTopologyKey &sourceEdge) const noexcept;
  [[nodiscard]] bool
  has_singularity(authority::SourceVertexId sourceVertex) const noexcept;
  [[nodiscard]] std::optional<int> singularity_index_numerator(
      authority::SourceVertexId sourceVertex) const noexcept;
  [[nodiscard]] std::size_t singularity_port_count(
      authority::SourceVertexId sourceVertex) const noexcept;
  [[nodiscard]] std::vector<authority::SourceVertexId>
  singularity_vertices() const;

  [[nodiscard]] FieldAlignedCurveNetworkCandidate validation_candidate() const;
  [[nodiscard]] std::uint64_t source_digest() const noexcept {
    return sourceDigest_;
  }
  [[nodiscard]] std::uint64_t atlas_digest() const noexcept {
    return atlasDigest_;
  }
  [[nodiscard]] std::uint64_t semantic_digest() const noexcept {
    return semanticDigest_;
  }

private:
  friend class FieldAlignedCurveNetworkBuildResult;

  FieldAlignedCurveNetwork(
      std::vector<FieldAlignedCurveNetworkNode> nodes,
      std::vector<FieldAlignedSingularityPort> singularityPorts,
      std::vector<FieldAlignedMandatoryEdge> mandatoryEdges,
      std::vector<FieldAlignedCandidateTrace> candidateTraces,
      std::vector<FieldAlignedNetworkEvent> events,
      std::uint64_t sourceDigest, std::uint64_t atlasDigest,
      std::uint64_t semanticDigest)
      : nodes_(std::move(nodes)), singularityPorts_(std::move(singularityPorts)),
        mandatoryEdges_(std::move(mandatoryEdges)),
        candidateTraces_(std::move(candidateTraces)), events_(std::move(events)),
        sourceDigest_(sourceDigest), atlasDigest_(atlasDigest),
        semanticDigest_(semanticDigest) {}

  std::vector<FieldAlignedCurveNetworkNode> nodes_;
  std::vector<FieldAlignedSingularityPort> singularityPorts_;
  std::vector<FieldAlignedMandatoryEdge> mandatoryEdges_;
  std::vector<FieldAlignedCandidateTrace> candidateTraces_;
  std::vector<FieldAlignedNetworkEvent> events_;
  std::uint64_t sourceDigest_ = 0U;
  std::uint64_t atlasDigest_ = 0U;
  std::uint64_t semanticDigest_ = 0U;
};

class FieldAlignedCurveNetworkBuildResult {
public:
  explicit FieldAlignedCurveNetworkBuildResult(FieldAlignedCurveNetwork network)
      : state_(std::move(network)) {}
  explicit FieldAlignedCurveNetworkBuildResult(FieldAlignedCurveNetworkError error)
      : state_(std::move(error)) {}

  [[nodiscard]] bool has_value() const noexcept {
    return std::holds_alternative<FieldAlignedCurveNetwork>(state_);
  }
  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
  [[nodiscard]] const FieldAlignedCurveNetwork &value() const {
    return std::get<FieldAlignedCurveNetwork>(state_);
  }
  [[nodiscard]] FieldAlignedCurveNetwork &value() {
    return std::get<FieldAlignedCurveNetwork>(state_);
  }
  [[nodiscard]] const FieldAlignedCurveNetworkError &error() const {
    return std::get<FieldAlignedCurveNetworkError>(state_);
  }

private:
  std::variant<FieldAlignedCurveNetwork, FieldAlignedCurveNetworkError> state_;
};

[[nodiscard]] const char *field_aligned_curve_network_error_code_name(
    FieldAlignedCurveNetworkErrorCode code) noexcept;
[[nodiscard]] std::uint64_t field_aligned_curve_network_hash(
    const FieldAlignedCurveNetwork &network) noexcept;

namespace surface_cell_tracing_detail {

enum class FieldBranchExitTimeOrdering : std::int8_t {
  Less = -1,
  Equal = 0,
  Greater = 1,
};

enum class FieldBranchContinuationKind : std::uint8_t {
  EdgeExit = 0,
  VertexHit = 1,
  EdgeTransit = 2,
};

enum class FieldBranchEdgeFlowRelation : std::uint8_t {
  Inflow = 0,
  Tangent = 1,
  Outflow = 2,
};

enum class FieldVertexArrivalMode : std::uint8_t {
  FaceInterior = 0,
  EdgeTransit = 1,
};

struct FieldBranchContinuationDecision {
  FieldBranchContinuationKind kind = FieldBranchContinuationKind::EdgeExit;
  authority::FieldBoundaryPoint exitPoint;
  authority::SourceEdgeTopologyKey outgoingCarrier;
  std::optional<authority::SourceVertexId> sourceVertex;

  auto operator<=>(const FieldBranchContinuationDecision &) const = default;
};

using FieldBranchContinuationResult =
    std::variant<FieldBranchContinuationDecision, FieldAlignedCurveNetworkError>;

struct FieldVertexTransitDecision {
  FieldVertexTransitDecision(
      authority::SourceFaceTopologyKey faceValue,
      authority::FieldBranch branchValue)
      : nextFace(std::move(faceValue)), nextBranch(branchValue) {}

  authority::SourceFaceTopologyKey nextFace;
  authority::FieldBranch nextBranch;

  auto operator<=>(const FieldVertexTransitDecision &) const = default;
};

using FieldVertexTransitResult =
    std::variant<FieldVertexTransitDecision, FieldAlignedCurveNetworkError>;

struct FieldAlignedTraceTraversalState {
  authority::SourceFaceTopologyKey sourceFace;
  authority::FieldBranch branch;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  authority::FieldBoundaryPoint entryPoint;

  auto operator<=>(const FieldAlignedTraceTraversalState &) const = default;
};

enum class FieldAlignedTraceTraversalStatus : std::uint8_t {
  Advanced = 0,
  CycleDetected = 1,
  StepBudgetExhausted = 2,
  CombinatorialRecurrenceExceeded = 3,
};

/// Position-free traversal state: the combinatorial identity of a trace step
/// with the exact entry position deliberately removed.
struct FieldAlignedTraceCombinatorialState {
  authority::SourceFaceTopologyKey sourceFace;
  authority::FieldBranch branch;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;

  auto operator<=>(const FieldAlignedTraceCombinatorialState &) const = default;
};

/**
 * @brief How many times one position-free state may be entered by one trace.
 *
 * Measured on the prescribed sphere from the committed fixture: every trace that
 * terminates at a singularity enters each `(face, branch, incoming carrier)`
 * exactly **once**, while every circulating trace re-enters its whole circuit
 * indefinitely. The allowance is set to twice the observed terminating maximum
 * so a legitimate trace keeps headroom, and any circulation is still caught
 * within two laps.
 */
inline constexpr std::size_t kFieldAlignedTraceMaxCombinatorialVisits = 2U;

class FieldAlignedTraceTraversalGuard {
public:
  explicit FieldAlignedTraceTraversalGuard(std::size_t stepBudget)
      : stepBudget_(stepBudget) {}

  [[nodiscard]] FieldAlignedTraceTraversalStatus
  observe(const FieldAlignedTraceTraversalState &state) {
    if (visited_.find(state) != visited_.end()) {
      return FieldAlignedTraceTraversalStatus::CycleDetected;
    }
    if (steps_ >= stepBudget_) {
      return FieldAlignedTraceTraversalStatus::StepBudgetExhausted;
    }
    // The exact-state test above cannot see a circulation whose position drifts
    // every lap, and such a trace never repeats a full state. The position-free
    // counter below closes exactly that gap.
    const FieldAlignedTraceCombinatorialState combinatorial{
        state.sourceFace, state.branch, state.incomingCarrier};
    std::size_t &visits = combinatorialVisits_[combinatorial];
    if (visits >= kFieldAlignedTraceMaxCombinatorialVisits) {
      combinatorialRecurrence_ = visits + 1U;
      return FieldAlignedTraceTraversalStatus::CombinatorialRecurrenceExceeded;
    }
    ++visits;
    visited_.insert(state);
    ++steps_;
    return FieldAlignedTraceTraversalStatus::Advanced;
  }

  [[nodiscard]] std::size_t steps() const noexcept { return steps_; }
  [[nodiscard]] std::size_t step_budget() const noexcept { return stepBudget_; }
  [[nodiscard]] std::size_t combinatorial_recurrence() const noexcept {
    return combinatorialRecurrence_;
  }
  [[nodiscard]] static std::size_t combinatorial_visit_allowance() noexcept {
    return kFieldAlignedTraceMaxCombinatorialVisits;
  }

private:
  std::size_t stepBudget_ = 0U;
  std::size_t steps_ = 0U;
  std::size_t combinatorialRecurrence_ = 0U;
  std::set<FieldAlignedTraceTraversalState> visited_;
  std::map<FieldAlignedTraceCombinatorialState, std::size_t> combinatorialVisits_;
};

/**
 * @brief Deterministic magnitude policy for exact continuation values.
 *
 * Exact continuation recomputes each parameter from the published direction, so
 * a value's width grows with the number of steps a trace has taken. Measured on
 * the prescribed sphere from the committed fixture, every trace that terminates
 * at a singularity stays under 1500 bits; a circulating trace passes that within
 * a few laps and keeps growing linearly. The bound is set well above the
 * terminating maximum so it never binds on legitimate work, and well below the
 * width at which exact arithmetic stops being affordable.
 *
 * Exceeding it is a typed rejection, never a fallback to inexact arithmetic: the
 * producer declines to answer rather than answering approximately, so no
 * topological outcome is ever decided by a magnitude.
 */
inline constexpr std::size_t kFieldExactContinuationMagnitudeBits = 4096U;

[[nodiscard]] FieldBranchExitTimeOrdering compare_field_branch_exit_times(
    const authority::FieldExactRational &firstPosition,
    const authority::FieldExactRational &firstNegativeDirection,
    const authority::FieldExactRational &secondPosition,
    const authority::FieldExactRational &secondNegativeDirection);

[[nodiscard]] FieldBranchContinuationResult resolve_field_branch_continuation(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchBoundaryPairing &pairing,
    const authority::FieldBoundaryPoint &entryPoint);

[[nodiscard]] FieldBranchEdgeFlowRelation classify_field_branch_transport_flow(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchBoundaryPairing &sourcePairing,
    const authority::SourceFaceTopologyKey &targetFace,
    const authority::FieldBranchBoundaryPairing &targetPairing,
    const authority::SourceEdgeTopologyKey &carrier);

[[nodiscard]] FieldBranchContinuationResult resolve_field_branch_grazing_transit(
    const authority::SourceFaceTopologyKey &sourceFace,
    const authority::FieldBranchBoundaryPairing &sourcePairing,
    const authority::SourceFaceTopologyKey &targetFace,
    const authority::FieldBranchBoundaryPairing &targetPairing,
    const authority::SourceEdgeTopologyKey &carrier, int signedLift,
    const authority::ExactUnitParameter &entryParameter);

[[nodiscard]] FieldVertexTransitResult resolve_field_vertex_transit(
    const TriMesh &sourceMesh,
    const authority::FieldBranchTopology &topology,
    authority::SourceComponentId sourceComponent,
    authority::TopologyRegionId topologyRegion,
    const authority::SourceFaceTopologyKey &currentFace,
    authority::FieldBranch currentBranch,
    authority::SourceVertexId sourceVertex,
    FieldVertexArrivalMode arrivalMode = FieldVertexArrivalMode::FaceInterior);

[[nodiscard]] std::size_t field_aligned_trace_step_budget(
    const authority::FieldBranchTopology &topology) noexcept;

[[nodiscard]] FieldAlignedCurveNetworkError
field_aligned_trace_traversal_error(
    FieldAlignedTraceTraversalStatus status,
    const FieldAlignedTraceTraversalState &state,
    const FieldAlignedTraceTraversalGuard &guard);

void annotate_field_aligned_trace_seed(
    FieldAlignedCurveNetworkError &error,
    authority::SourceVertexId traceSeedVertex,
    authority::FieldSingularityId traceSeedSingularity);

[[nodiscard]] std::optional<FieldAlignedCurveNetworkError>
append_field_aligned_singularity_termination(
    FieldAlignedCurveNetworkCandidate &candidate,
    const FieldAlignedCandidateTrace &trace);

} // namespace surface_cell_tracing_detail

struct SurfaceTraceSeed {
  int id = -1;
  SurfaceTracePoint point;
  SurfaceSeedProvenance provenance = SurfaceSeedProvenance::AdaptiveFarthest;
  /// Provenance ID for source-vertex-like seed classes; never hard-rail authority.
  int sourceId = -1;
  /// Exact hard-rail owner for Boundary/Feature seeds emitted from authoritative rails.
  std::optional<authority::HardRailId> hardRailId;
};

struct SurfaceTraceSegment {
  int face = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  int family = 0;
  int sign = 1;
  int entryEdge = -1;
  int exitEdge = -1;
  int matching = 0;
  double matchingEffort = 0.0;
  /// Connected field chart containing this segment.
  std::optional<authority::FieldChartId> sourceChart;
  /// Canonical typed transport route crossed to enter this segment.
  /// The first interval has an empty route; every stored step is an interior
  /// transition and owns topology, transition identity, transport, and orientation.
  authority::CanonicalRoute entryRoute;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  int railIntervalIndex = -1;
  int railSideSign = 0;
  double railT0 = 0.0;
  double railT1 = 0.0;
};

/**
 * @brief Canonical intrinsic state used to detect deterministic trace cycles.
 *
 * `entryEdge` is the local edge index in `sourceFace`, not the edge index in
 * the preceding face. Barycentric coordinates are quantized so repeated-state
 * detection is independent of insignificant floating-point drift.
 */
struct SurfaceTraceState {
  int sourceFace = -1;
  int entryEdge = -1;
  int family = 0;
  int sign = 1;
  std::array<std::int64_t, 3> quantizedBarycentric{0, 0, 0};

  bool operator<(const SurfaceTraceState &other) const {
    return std::tie(sourceFace, entryEdge, family, sign,
                    quantizedBarycentric) <
           std::tie(other.sourceFace, other.entryEdge, other.family,
                    other.sign, other.quantizedBarycentric);
  }

  bool operator==(const SurfaceTraceState &other) const {
    return sourceFace == other.sourceFace && entryEdge == other.entryEdge &&
           family == other.family && sign == other.sign &&
           quantizedBarycentric == other.quantizedBarycentric;
  }
};

struct SurfaceTraceResult {
  std::vector<SurfaceTraceState> states;
  std::vector<SurfaceTraceSegment> segments;
  TraceTerminationReason termination = TraceTerminationReason::Budget;
  double length = 0.0;
};

/** Authoritative local lattice state carried by the constructive front. */
struct LocalLatticeState {
  Eigen::Vector2d phase = Eigen::Vector2d::Zero();
  authority::LatticeTranslation latticeCoordinate;
  /// Local branch index that represents the domain +U lattice direction.
  int branchRotation = 0;
  int scaleLevel = 0;
  /// Authoritative field chart owning this point's selected source face.
  std::optional<authority::FieldChartId> sourceChart;
};

enum class SurfaceFrontEventKind : int {
  CompatibleFrontMerge = 0,
  BoundaryTermination = 1,
  HardRailCapture = 2,
  PhaseMismatch = 3,
  PeriodicHolonomyConflict = 4,
  PeriodicFrontMerge = 5,
  HardRailMerge = 6,
};

/** Source-authoritative ownership of one constructive-front side. */
enum class SurfaceFrontBoundaryKind : int {
  OrdinaryInterior = 0,
  GenuineSourceBoundary = 1,
  HardRail = 2,
  EmbeddedReliefCut = 3,
  PeriodicCut = 4,
};

/**
 * Reciprocal source-field transport across one retained local-isolation seam.
 *
 * Face identities are canonical sorted source-vertex triples so certificate
 * identity does not depend on face-row or discovery order. The published
 * certificate is immutable and can only be created by the checked factory.
 */
enum class SurfaceIsolationSeamTransportCertificateErrorCode : int {
  UnknownRegion = 0,
  SeamNotOwnedByRegion = 1,
  NonCanonicalFaceOrder = 2,
  FaceNotOwnedByRegion = 3,
  SeamIncidenceMismatch = 4,
  SheetOwnershipMismatch = 5,
  SameSheet = 6,
  NonReciprocalTransport = 7,
};

struct SurfaceIsolationSeamTransportCertificateError {
  SurfaceIsolationSeamTransportCertificateErrorCode code =
      SurfaceIsolationSeamTransportCertificateErrorCode::UnknownRegion;
  std::optional<authority::TopologyRegionId> region;
  std::optional<authority::SourceEdgeTopologyKey> seam;
  std::optional<authority::InteriorTransitionId> transition;
  std::optional<authority::SourceFaceTopologyKey> firstFace;
  std::optional<authority::SourceFaceTopologyKey> secondFace;
  std::optional<authority::IsolationSheetId> firstSheet;
  std::optional<authority::IsolationSheetId> secondSheet;
};

class SurfaceIsolationSeamTransportCertificate {
public:
  using ConstructionResult =
      std::variant<SurfaceIsolationSeamTransportCertificate,
                   SurfaceIsolationSeamTransportCertificateError>;

  [[nodiscard]] static ConstructionResult
  make(const SourceTopologyRegions &sourceAuthority,
       authority::TopologyRegionId region,
       authority::SourceEdgeTopologyKey seam,
       authority::InteriorTransitionId transition,
       authority::SourceFaceTopologyKey firstFace,
       authority::SourceFaceTopologyKey secondFace,
       authority::IsolationSheetId firstSheet,
       authority::IsolationSheetId secondSheet,
       authority::QuarterTurn forward, authority::QuarterTurn reverse);

  [[nodiscard]] authority::TopologyRegionId region() const noexcept {
    return region_;
  }
  [[nodiscard]] const authority::SourceEdgeTopologyKey &seam() const noexcept {
    return seam_;
  }
  [[nodiscard]] authority::InteriorTransitionId transition() const noexcept {
    return transition_;
  }
  [[nodiscard]] const authority::SourceFaceTopologyKey &firstFace() const noexcept {
    return firstFace_;
  }
  [[nodiscard]] const authority::SourceFaceTopologyKey &secondFace() const noexcept {
    return secondFace_;
  }
  [[nodiscard]] authority::IsolationSheetId firstSheet() const noexcept {
    return firstSheet_;
  }
  [[nodiscard]] authority::IsolationSheetId secondSheet() const noexcept {
    return secondSheet_;
  }
  [[nodiscard]] authority::QuarterTurn forward() const noexcept {
    return forward_;
  }
  [[nodiscard]] authority::QuarterTurn reverse() const noexcept {
    return reverse_;
  }

  auto operator<=>(const SurfaceIsolationSeamTransportCertificate &) const = default;

private:
  SurfaceIsolationSeamTransportCertificate(
      authority::TopologyRegionId regionValue,
      authority::SourceEdgeTopologyKey seamValue,
      authority::InteriorTransitionId transitionValue,
      authority::SourceFaceTopologyKey firstFaceValue,
      authority::SourceFaceTopologyKey secondFaceValue,
      authority::IsolationSheetId firstSheetValue,
      authority::IsolationSheetId secondSheetValue,
      authority::QuarterTurn forwardValue, authority::QuarterTurn reverseValue)
      : region_(regionValue), seam_(seamValue), transition_(transitionValue),
        firstFace_(firstFaceValue), secondFace_(secondFaceValue),
        firstSheet_(firstSheetValue), secondSheet_(secondSheetValue),
        forward_(forwardValue), reverse_(reverseValue) {}

  authority::TopologyRegionId region_;
  authority::SourceEdgeTopologyKey seam_;
  authority::InteriorTransitionId transition_;
  authority::SourceFaceTopologyKey firstFace_;
  authority::SourceFaceTopologyKey secondFace_;
  authority::IsolationSheetId firstSheet_;
  authority::IsolationSheetId secondSheet_;
  authority::QuarterTurn forward_;
  authority::QuarterTurn reverse_;
};

struct SurfaceFrontEdge {
  SurfaceFrontEdge(authority::TopologyRegionId region, authority::CellId owner)
      : filledCell(owner), sourceTopologyRegion(region) {}

  SurfaceTracePoint from;
  SurfaceTracePoint to;
  int family = 0;
  int advanceSign = 1;
  LocalLatticeState fromLattice;
  LocalLatticeState toLattice;
  authority::CellId filledCell;
  /// Counter-clockwise side of filledCell represented by this edge.
  int filledSide = -1;
  int oppositeEdge = -1;
  int unfilledSide = 1;
  bool exterior = false;
  /// Authoritative topology region owning this front side.
  authority::TopologyRegionId sourceTopologyRegion;
  SurfaceFrontBoundaryKind boundaryKind =
      SurfaceFrontBoundaryKind::OrdinaryInterior;
  /// Exact owner in SurfacePhaseFrontProduct::periodicHolonomies.
  std::optional<authority::PeriodicRelationId> periodicRelation;
  /// Optional exact rail owner.
  std::optional<authority::HardRailId> railId;
  /// Canonical source route carrying topology, transition identity, and transport.
  authority::CanonicalRoute route;
};

struct SurfaceFrontEvent {
  SurfaceFrontEventKind kind = SurfaceFrontEventKind::BoundaryTermination;
  int firstEdge = -1;
  int secondEdge = -1;
};

/** Exact quotient relation between the two copies of an intrinsic annulus cut. */
enum class SurfacePeriodicHolonomyErrorCode : int {
  ZeroTranslation = 0,
  MissingRoute = 1,
  MissingCutRoute = 2,
};

struct SurfacePeriodicHolonomyError {
  SurfacePeriodicHolonomyErrorCode code =
      SurfacePeriodicHolonomyErrorCode::ZeroTranslation;
  std::optional<authority::PeriodicRelationId> id;
  std::optional<authority::TopologyRegionId> region;
};

class SurfacePeriodicHolonomy {
public:
  using ConstructionResult =
      std::variant<SurfacePeriodicHolonomy, SurfacePeriodicHolonomyError>;

  [[nodiscard]] static ConstructionResult
  make(authority::PeriodicRelationId id,
       authority::TopologyRegionId sourceTopologyRegion,
       authority::GridAutomorphism action,
       authority::CanonicalRoute route,
       authority::CanonicalRoute cutRoute);

  [[nodiscard]] authority::PeriodicRelationId id() const noexcept { return id_; }
  [[nodiscard]] authority::TopologyRegionId sourceTopologyRegion() const noexcept {
    return sourceTopologyRegion_;
  }
  [[nodiscard]] const authority::GridAutomorphism &action() const noexcept {
    return action_;
  }
  [[nodiscard]] const authority::CanonicalRoute &route() const noexcept {
    return route_;
  }
  [[nodiscard]] const authority::CanonicalRoute &cutRoute() const noexcept {
    return cutRoute_;
  }

  [[nodiscard]] SurfacePeriodicHolonomy
  with_id(authority::PeriodicRelationId id) const {
    return SurfacePeriodicHolonomy(id, sourceTopologyRegion_, action_, route_,
                                   cutRoute_);
  }

  auto operator<=>(const SurfacePeriodicHolonomy &) const = default;

private:
  SurfacePeriodicHolonomy(authority::PeriodicRelationId id,
                          authority::TopologyRegionId sourceTopologyRegion,
                          authority::GridAutomorphism action,
                          authority::CanonicalRoute route,
                          authority::CanonicalRoute cutRoute)
      : id_(id), sourceTopologyRegion_(sourceTopologyRegion),
        action_(action), route_(std::move(route)), cutRoute_(std::move(cutRoute)) {}

  authority::PeriodicRelationId id_;
  authority::TopologyRegionId sourceTopologyRegion_;
  authority::GridAutomorphism action_ = authority::GridAutomorphism::identity();
  authority::CanonicalRoute route_;
  authority::CanonicalRoute cutRoute_;
};

enum class SurfacePeriodicHolonomyInsertStatus : int {
  Inserted = 0,
  Equivalent = 1,
  AmbiguousBasis = 2,
  Incompatible = 3,
};

/** Provenance flags for one source edge on a bounded-disk chart boundary. */
struct SurfaceBoundedDiskBoundaryEdgeAuthority {
  bool sourceBoundary = false;
  bool hardFeature = false;
  bool sourceSheet = false;
};

/**
 * One maximal transported 4-RoSy run on an authoritative bounded-disk boundary.
 *
 * Source vertex/face IDs are retained only as provenance. Semantic ordering is
 * the source-attached cyclic boundary order canonicalized from source geometry.
 */
struct SurfaceBoundedDiskBoundaryRun {
  int branch = -1;
  int family = 0;
  int sign = 1;
  int startVertex = -1;
  int endVertex = -1;
  int signedQuarterTurnToNext = 0;
  double cumulativeIntrinsicLength = 0.0;
  double intrinsicLength = 0.0;
  Eigen::Vector2d chartStart = Eigen::Vector2d::Zero();
  Eigen::Vector2d chartEnd = Eigen::Vector2d::Zero();
  std::vector<int> sourceVertices;
  std::vector<int> sourceFaces;
  std::vector<authority::SourceEdgeTopologyKey> sourceEdgeTopology;
  std::vector<SurfaceBoundedDiskBoundaryEdgeAuthority> edgeAuthority;
};

/**
 * First-class transported boundary phase for one source-authoritative disk.
 *
 * The phase is valid only after every run is field-authoritative and the
 * oriented cyclic quarter-turn index closes. `rectangular` identifies the
 * legacy four-left-turn special case; non-rectangular phases keep their exact
 * run/corner authority for polygonal chart construction.
 */
struct SurfaceBoundedDiskBoundaryPhase {
  explicit SurfaceBoundedDiskBoundaryPhase(authority::TopologyRegionId region)
      : sourceTopologyRegion(region) {}

  authority::TopologyRegionId sourceTopologyRegion;
  int chartUBranch = 0;
  int signedQuarterTurnSum = 0;
  double totalIntrinsicLength = 0.0;
  bool rectangular = false;
  bool polygonClosed = false;
  bool chartConstructed = false;
  std::uint64_t structuralHash = 0;
  std::vector<SurfaceBoundedDiskBoundaryRun> runs;
};

struct SurfacePhaseFrontCell {
  SurfacePhaseFrontCell(authority::TopologyRegionId region, authority::CellId cell)
      : id(cell), sourceTopologyRegion(region) {}

  authority::CellId id;
  /// Authoritative source-topology region owning this cell.
  authority::TopologyRegionId sourceTopologyRegion;
  bool orientationValidated = false;
  std::array<SurfaceTracePoint, 4> corners;
  std::array<LocalLatticeState, 4> lattice;
  std::array<std::vector<SurfaceTraceSegment>, 4> boundaryPaths;
};

enum class SurfacePhaseFrontFailureReason : int {
  None = 0,
  InvalidInput = 1,
  DegenerateReferenceFrame = 2,
  NonPlanarSource = 3,
  InconsistentFaceOrientation = 4,
  IncompatibleFaceBranch = 5,
  IncompatibleSecondaryBranch = 6,
  DuplicateTransitionMetadata = 7,
  InvalidOrdinaryTransition = 8,
  NonReciprocalOrdinaryTransition = 9,
  NonRectangularDomain = 10,
  InvalidTargetSize = 11,
  InvalidGridStep = 12,
  PointProjectionFailure = 13,
  MissingFaceState = 14,
  MissingSegmentCoverage = 15,
  DisconnectedSegmentAttachment = 16,
  NonManifoldVertexFan = 17,
  AmbiguousVertexFan = 18,
  InvalidVertexFanTransition = 19,
  VertexFanBranchMismatch = 20,
  MissingTransitionProvenance = 21,
  InvalidCellOrientation = 22,
  InvalidLatticeEdge = 23,
  FrontOwnershipConflict = 24,
  InvalidFinalCellState = 25,
  InvalidFinalEdgeState = 26,
  InvalidPeriodicTopology = 27,
  InvalidPeriodicChart = 28,
  PeriodicHolonomyMismatch = 29,
  InvalidPeriodicFrontPairing = 30,
  InvalidPeriodicRingCorrespondence = 31,
  AmbiguousPeriodicRingCorrespondence = 32,
  AmbiguousPeriodicRelationBasis = 33,
  IncompatiblePeriodicRelation = 34,
  UnsupportedSourceSheetTopology = 35,
  IncompleteSourceSheetCoverage = 36,
  InvalidBoundedDiskTopology = 37,
  InvalidBoundedDiskTransport = 38,
  InvalidBoundedDiskBoundaryPhase = 39,
  InvalidBoundedDiskChart = 40,
  InvalidBoundedDiskFrontPairing = 41,
  InvalidBoundedDiskBoundaryTurn = 42,
  InvalidBoundedDiskBoundaryIndex = 43,
  InvalidTopologyRegion = 44,
  InvalidTopologyRegionTransport = 45,
  InvalidFrontBoundaryAuthority = 46,
  UnsupportedEmbeddedReliefCut = 47,
  InvalidHardRailPairing = 48,
  InvalidIsolationSeamTransportCertificate = 49,
};

struct SurfacePhaseFrontFailure {
  SurfacePhaseFrontFailureReason reason = SurfacePhaseFrontFailureReason::None;
  int cell = -1;
  int side = -1;
  int face = -1;
  int targetFace = -1;
  int sourceVertex = -1;
  int sourceEdge = -1;
  int secondarySourceEdge = -1;
};

const char *surface_phase_front_failure_reason_name(
    SurfacePhaseFrontFailureReason reason);

enum class SurfaceCellProducerDisposition : int {
  NotApplicable = 0,
  Produced = 1,
  Rejected = 2,
};

const char *surface_cell_producer_disposition_name(
    SurfaceCellProducerDisposition disposition);

enum class SurfacePhaseFrontProductErrorCode : int {
  InvalidSourceAuthority = 0,
  EmptyCells = 1,
  EmptyEdges = 2,
  DuplicateCellId = 3,
  InvalidCellRegion = 4,
  InvalidEdgeCell = 5,
  InvalidEdgeRegion = 6,
  InvalidOppositeEdge = 7,
  InvalidEventEdge = 8,
  DuplicatePeriodicRelationId = 9,
  InvalidPeriodicRelationRegion = 10,
  MissingPeriodicRelationOwner = 11,
  InvalidPeriodicRelationOwner = 12,
  DuplicateIsolationCertificate = 13,
  IsolationCertificateBijectionMismatch = 14,
  InvalidBoundedDiskRegion = 15,
  DuplicateBoundedDiskRegion = 16,
};

struct SurfacePhaseFrontProductError {
  SurfacePhaseFrontProductErrorCode code =
      SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority;
  int edge = -1;
  int event = -1;
  std::optional<authority::CellId> cell;
  std::optional<authority::TopologyRegionId> region;
  std::optional<authority::PeriodicRelationId> periodicRelation;
};

class SurfacePhaseFrontProduct {
public:
  using ConstructionResult =
      std::variant<SurfacePhaseFrontProduct, SurfacePhaseFrontProductError>;

  [[nodiscard]] static ConstructionResult
  make(int gridU, int gridV, SourceTopologyRegions sourceTopologyRegions,
       std::vector<SurfaceIsolationSeamTransportCertificate>
           isolationSeamTransportCertificates,
       std::vector<SurfacePeriodicHolonomy> periodicHolonomies,
       std::vector<SurfaceBoundedDiskBoundaryPhase> boundedDiskBoundaryPhases,
       std::vector<SurfaceFrontEdge> edges,
       std::vector<SurfaceFrontEvent> events,
       std::vector<SurfacePhaseFrontCell> cells);

  [[nodiscard]] int gridU() const noexcept { return gridU_; }
  [[nodiscard]] int gridV() const noexcept { return gridV_; }
  [[nodiscard]] const SourceTopologyRegions &sourceTopologyRegions() const noexcept {
    return sourceTopologyRegions_;
  }
  [[nodiscard]] const std::vector<SurfaceIsolationSeamTransportCertificate> &
  isolationSeamTransportCertificates() const noexcept {
    return isolationSeamTransportCertificates_;
  }
  [[nodiscard]] const std::vector<SurfacePeriodicHolonomy> &
  periodicHolonomies() const noexcept {
    return periodicHolonomies_;
  }
  [[nodiscard]] const std::vector<SurfaceBoundedDiskBoundaryPhase> &
  boundedDiskBoundaryPhases() const noexcept {
    return boundedDiskBoundaryPhases_;
  }
  [[nodiscard]] const std::vector<SurfaceFrontEdge> &edges() const noexcept {
    return edges_;
  }
  [[nodiscard]] const std::vector<SurfaceFrontEvent> &events() const noexcept {
    return events_;
  }
  [[nodiscard]] const std::vector<SurfacePhaseFrontCell> &cells() const noexcept {
    return cells_;
  }

private:
  SurfacePhaseFrontProduct(
      int gridU, int gridV, SourceTopologyRegions sourceTopologyRegions,
      std::vector<SurfaceIsolationSeamTransportCertificate>
          isolationSeamTransportCertificates,
      std::vector<SurfacePeriodicHolonomy> periodicHolonomies,
      std::vector<SurfaceBoundedDiskBoundaryPhase> boundedDiskBoundaryPhases,
      std::vector<SurfaceFrontEdge> edges,
      std::vector<SurfaceFrontEvent> events,
      std::vector<SurfacePhaseFrontCell> cells)
      : gridU_(gridU), gridV_(gridV),
        sourceTopologyRegions_(std::move(sourceTopologyRegions)),
        isolationSeamTransportCertificates_(
            std::move(isolationSeamTransportCertificates)),
        periodicHolonomies_(std::move(periodicHolonomies)),
        boundedDiskBoundaryPhases_(std::move(boundedDiskBoundaryPhases)),
        edges_(std::move(edges)), events_(std::move(events)),
        cells_(std::move(cells)) {}

  int gridU_ = 0;
  int gridV_ = 0;
  SourceTopologyRegions sourceTopologyRegions_;
  std::vector<SurfaceIsolationSeamTransportCertificate>
      isolationSeamTransportCertificates_;
  std::vector<SurfacePeriodicHolonomy> periodicHolonomies_;
  std::vector<SurfaceBoundedDiskBoundaryPhase> boundedDiskBoundaryPhases_;
  std::vector<SurfaceFrontEdge> edges_;
  std::vector<SurfaceFrontEvent> events_;
  std::vector<SurfacePhaseFrontCell> cells_;
};

struct NotApplicable {};

template <typename T> struct Produced {
  T product;
};

template <typename Failure> struct Rejected {
  Failure failure;
};

template <typename T, typename Failure = SurfacePhaseFrontFailure>
using ProducerOutcome =
    std::variant<NotApplicable, Produced<T>, Rejected<Failure>>;

class SurfacePhaseFrontResult {
public:
  using Product = SurfacePhaseFrontProduct;
  using Outcome = ProducerOutcome<Product>;

  SurfacePhaseFrontResult() = default;

  [[nodiscard]] static SurfacePhaseFrontResult not_applicable() {
    return SurfacePhaseFrontResult(Outcome{NotApplicable{}});
  }

  [[nodiscard]] static SurfacePhaseFrontResult produced(Product product) {
    if (product.cells().empty() || product.edges().empty() ||
        product.sourceTopologyRegions().regions().empty() ||
        product.sourceTopologyRegions().face_count() == 0U) {
      throw std::invalid_argument(
          "Produced phase-front outcome requires a complete nonempty product.");
    }
    return SurfacePhaseFrontResult(Outcome{Produced<Product>{std::move(product)}});
  }

  [[nodiscard]] static SurfacePhaseFrontResult rejected(
      SurfacePhaseFrontFailure failure) {
    if (failure.reason == SurfacePhaseFrontFailureReason::None) {
      throw std::invalid_argument(
          "Rejected phase-front outcome requires a typed failure.");
    }
    return SurfacePhaseFrontResult(
        Outcome{Rejected<SurfacePhaseFrontFailure>{std::move(failure)}});
  }

  [[nodiscard]] SurfaceCellProducerDisposition disposition() const noexcept {
    if (std::holds_alternative<Produced<Product>>(outcome_)) {
      return SurfaceCellProducerDisposition::Produced;
    }
    if (std::holds_alternative<Rejected<SurfacePhaseFrontFailure>>(outcome_)) {
      return SurfaceCellProducerDisposition::Rejected;
    }
    return SurfaceCellProducerDisposition::NotApplicable;
  }

  [[nodiscard]] bool is_produced() const noexcept {
    return std::holds_alternative<Produced<Product>>(outcome_);
  }

  [[nodiscard]] bool is_rejected() const noexcept {
    return std::holds_alternative<Rejected<SurfacePhaseFrontFailure>>(outcome_);
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

  [[nodiscard]] SurfacePhaseFrontFailure *rejection() noexcept {
    auto *rejected =
        std::get_if<Rejected<SurfacePhaseFrontFailure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }

  [[nodiscard]] const SurfacePhaseFrontFailure *rejection() const noexcept {
    const auto *rejected =
        std::get_if<Rejected<SurfacePhaseFrontFailure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }

  [[nodiscard]] SurfacePhaseFrontFailureReason rejection_reason() const noexcept {
    const SurfacePhaseFrontFailure *failure = rejection();
    return failure == nullptr ? SurfacePhaseFrontFailureReason::None
                              : failure->reason;
  }

  [[nodiscard]] const Outcome &outcome() const noexcept { return outcome_; }

private:
  explicit SurfacePhaseFrontResult(Outcome outcome)
      : outcome_(std::move(outcome)) {}

  Outcome outcome_{NotApplicable{}};
};

/**
 * One cross-field separatrix emitted by a source-field singularity.
 *
 * A degree-four field singularity with integer numerator `k` owns `4-k`
 * outgoing branches.  These branches cannot be represented by the four
 * generic `(family, sign)` traces launched from one arbitrary incident face:
 * the field branch can move between families while the one-ring is unrolled.
 */
struct SurfaceSingularitySeparatrix {
  int sourceVertex = -1;
  int singularityIndexNumerator = 0;
  int expectedValence = 0;
  int branch = -1;
  int initialFace = -1;
  int family = -1;
  int sign = 0;
  double oneRingAngle = 0.0;
  SurfaceTraceResult trace;
};

struct SurfaceSingularitySeparatrixStats {
  int singularityCount = 0;
  int expectedBranches = 0;
  int enumeratedBranches = 0;
  int nonemptyBranches = 0;
  int reconciledSingularities = 0;
  int incompleteSingularities = 0;
  int invalidIndexCount = 0;
  bool metadataValid = true;
};

struct SurfaceCellProposal {
  int seedId = -1;
  bool accepted = false;
  CellRejectionReason rejection = CellRejectionReason::Accepted;
  double closureError = 0.0;
  std::array<SurfaceTracePoint, 4> corners;
  std::vector<SurfaceTraceSegment> sides;
  std::array<std::vector<SurfaceTraceSegment>, 4> boundaryPaths;
};

struct SurfaceWalkResult {
  SurfaceTracePoint point;
  SurfaceTraceResult trace;
};

struct SurfaceCellProposalStats {
  int attempted = 0;
  int accepted = 0;
  int rejectedClosure = 0;
  int rejectedBarrier = 0;
  int rejectedDegenerate = 0;
  int rejectedSourceSheet = 0;
  int rejectedFieldMetadata = 0;
  int rejectedSelfIntersection = 0;
  int rejectedInverted = 0;
  int rejectedDuplicateCorner = 0;
  int rejectedOutOfSize = 0;
  int rejectedHardRailCrossing = 0;
};

enum class SurfaceGuidePotentialStatus : int {
  SkippedUnresolved = 0,
  Available = 1,
};

struct SurfaceGuidePotential {
  SurfaceGuidePotentialStatus status =
      SurfaceGuidePotentialStatus::SkippedUnresolved;
};

struct SourceSurfaceLabels {
  std::vector<int> componentByFace;
  std::vector<int> localSheetByFace;
};

/**
 * Policy for intrinsic source-face charts used to prevent proximity-based
 * capture and projection from jumping between nearby surface sheets.
 */
struct SourceSurfaceClassifierOptions {
  /// Ordinary manifold curvature is traversable unless an edge is explicitly
  /// supplied in barrierEdges. Set false to split at adjacent face-normal dots
  /// below normalCompatibility.
  bool traverseUnmarkedSharpBends = true;
  /// Unitless cosine threshold in [0, 1]. It is used both by the optional
  /// sharp-bend split and, with opposite sign, to identify opposing sheets.
  double normalCompatibility = 0.25;
  /// Euclidean close-sheet search radius measured in mean source-edge lengths.
  double closeSheetRadiusMeanEdges = 2.5;
  /// Faces within this many source-edge adjacency rings are intrinsically
  /// local and therefore excluded from close/opposing-sheet conflicts.
  int geodesicExclusionDepth = 2;
};

struct SurfaceCellTracingOptions {
  /// Enable the bounded uniform phase-labelled advancing-front proof.
  bool enableUniformPhaseFront = true;
  double defaultTargetSize = 1.0;
  double coverageRadiusFactor = 1.0;
  double maxTraceLength = 1.0;
  int maxTraceSegments = 128;
  double captureRadius = 0.0;
  double closureToleranceFactor = 0.25;
  double minimumCellSideFactor = 0.1;
  double maximumCellSideFactor = 4.0;
  double duplicateCornerToleranceFactor = 1.0e-6;
  std::vector<int> singularityVertices;
  /// Integer index numerators parallel to singularityVertices. When present,
  /// the tracer emits the exact `4-index` one-ring separatrix valence.
  std::vector<int> singularityIndexNumerators;
  std::vector<int> reliefCriticalVertices;
  std::vector<int> reliefRootVertices;
  Eigen::VectorXi reliefRegionLabels;
  std::set<authority::SourceEdgeTopologyKey> reliefBarrierEdges;
  /// Relief separatrices remain guidance until the arrangement embeds them.
  /// Only embedded separatrices are allowed to stop traces as hard barriers.
  bool reliefBarriersEmbedded = false;
  std::vector<int> separatrixVertices;
  std::vector<int> anchors;
  std::vector<SurfaceTracePoint> capturePoints;
  std::set<authority::SourceEdgeTopologyKey> hardFeatureEdges;
  std::vector<SurfaceCellRail> authoritativeRails;
  bool followCompatibleHardFeatureRails = true;
  // Raw classifier labels are ingress-only. Once SourceTopologyRegions is
  // constructed, downstream semantic consumers use sourceAuthority instead.
  std::vector<int> sourceFaceComponents;
  std::vector<int> sourceFaceSheets;
  const SourceTopologyRegions *sourceAuthority = nullptr;
  /// Production cross-field branch transport authority. Raw matching/effort
  /// inputs remain available only to legacy and focused test seams when this
  /// pointer is null.
  const authority::FieldTransportAtlas *fieldTransportAtlas = nullptr;
  /// Checked A2a ownership authority. When non-null it is authoritative for
  /// singularity membership/index/ports and mandatory rail ownership; raw
  /// singularity vectors remain legacy/focused-test ingress only.
  const FieldAlignedCurveNetwork *fieldAlignedNetwork = nullptr;
  [[nodiscard]] bool has_legacy_raw_singularity_ingress() const noexcept {
    return !singularityVertices.empty() || !singularityIndexNumerators.empty();
  }
  SurfaceGuidePotential guidePotential;
};

struct SurfaceCellNetwork {
  SurfacePhaseFrontResult phaseFront;
  std::vector<SurfaceTraceSeed> seeds;
  std::vector<SurfaceTraceResult> traces;
  std::vector<SurfaceSingularitySeparatrix> singularSeparatrices;
  SurfaceSingularitySeparatrixStats singularSeparatrixStats;
  std::vector<SurfaceCellProposal> proposals;
  std::vector<SurfaceCellRail> authoritativeRails;
  std::optional<SourceTopologyRegions> sourceTopologyRegions;
  std::vector<int> reliefRootVertices;
  Eigen::VectorXi reliefRegionLabels;
  std::set<authority::SourceEdgeTopologyKey> reliefBarrierEdges;
  SurfaceCellProposalStats stats;
};

struct SurfaceCellTracingOverlay {
  Eigen::MatrixXd crossGlyphStarts;
  Eigen::MatrixXd crossGlyphEnds;
  Eigen::VectorXi crossGlyphFamily;
  Eigen::MatrixXd seedPositions;
  Eigen::VectorXi seedProvenance;
  Eigen::MatrixXd traceSegmentStarts;
  Eigen::MatrixXd traceSegmentEnds;
  Eigen::VectorXi traceFamily;
  Eigen::VectorXi traceSign;
  Eigen::VectorXi traceTermination;
  Eigen::VectorXd cellClosureError;
  Eigen::VectorXi cellRejection;
};

namespace surface_cell_tracing_detail {

std::size_t source_vertex_extent(const Eigen::MatrixXi &faces);
authority::SourceEdgeTopologyKey edge_key(const int a, const int b,
                                           std::size_t vertexExtent);

Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex);

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b);

Eigen::RowVector3d point_position(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &faces,
                                         const SurfaceTracePoint &point);

Eigen::RowVector3d face_normal(const Eigen::MatrixXd &vertices,
                                      const Eigen::MatrixXi &faces,
                                      const int face);

Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &direction,
                                          const Eigen::RowVector3d &normal);

std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
edge_faces(const Eigen::MatrixXi &faces);

std::map<authority::SourceEdgeTopologyKey, int>
edge_matching_indices(
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces);

std::uint64_t isolation_seam_transport_certificate_hash(
    const SurfaceIsolationSeamTransportCertificate &certificate);

struct EdgeTransitionLookup {
  std::map<authority::SourceEdgeTopologyKey, fields::CrossFieldEdgeTransition> byEdge;
  const authority::FieldTransportAtlas *atlas = nullptr;
  bool duplicate = false;
};

EdgeTransitionLookup edge_transition_lookup(
    const std::vector<fields::CrossFieldEdgeTransition> &transitions,
    std::size_t vertexExtent);

EdgeTransitionLookup edge_transition_lookup(
    const authority::FieldTransportAtlas &atlas);

bool contains_vertex(const std::vector<int> &vertices,
                            const int vertex);

std::vector<std::vector<int>>
incident_faces_by_vertex(const int vertexCount, const Eigen::MatrixXi &faces);

SurfaceTracePoint vertex_point(
    const int vertex, const std::vector<std::vector<int>> &incident,
    const Eigen::MatrixXi &faces);

double target_size_at_vertex(const Eigen::VectorXd &targetSize,
                                    const int vertex,
                                    const double fallback);

void append_seed(std::vector<SurfaceTraceSeed> &seeds,
                        std::set<std::tuple<int, std::int64_t, std::int64_t,
                                                std::int64_t>> &seen,
                        const SurfaceTracePoint &point,
                        const SurfaceSeedProvenance provenance,
                        const int sourceId);

void append_hard_rail_seed(
    std::vector<SurfaceTraceSeed> &seeds,
    std::set<std::tuple<int, std::int64_t, std::int64_t, std::int64_t>> &seen,
    const SurfaceTracePoint &point, const SurfaceSeedProvenance provenance,
    authority::HardRailId railId);

bool point_on_edge(const Eigen::RowVector3d &bary, const int edgeCorner,
                          const double eps = 1.0e-10);

int hit_vertex(const Eigen::RowVector3d &bary,
                      const double eps = 1.0e-10);

int dominant_vertex_corner(const Eigen::RowVector3d &bary);

Eigen::RowVector3d remap_barycentric_to_neighbor(
    const Eigen::MatrixXi &faces, const int fromFace, const int toFace,
    const Eigen::RowVector3d &fromBary);

bool barycentric_derivative(const Eigen::MatrixXd &vertices,
                                   const Eigen::MatrixXi &faces,
                                   const int face,
                                   const Eigen::RowVector3d &direction,
                                   Eigen::RowVector3d &dbary);

bool source_faces_compatible(const SurfaceCellTracingOptions &options,
                                    const int a, const int b);

bool source_edge_is_authoritative_local_boundary(
    const SurfaceCellTracingOptions &options, const int faceCount,
    const int localFace, const std::array<int, 2> &fullIncident,
    const authority::SourceEdgeTopologyKey &edgeKey);

bool source_faces_share_component(const SurfaceCellTracingOptions &options,
                                  const int a, const int b);

struct SurfaceCellRailIntervalRef {
  explicit SurfaceCellRailIntervalRef(authority::HardRailId rail)
      : railId(rail) {}

  authority::HardRailId railId;
  int curveId = -1;
  int intervalIndex = -1;
  int sourceFace = -1;
  int sourceEdge = -1;
  std::optional<authority::SourceEdgeTopologyKey> edgeKey;
  bool closed = false;
  SurfaceCellRailKind kind = SurfaceCellRailKind::Boundary;
  SurfaceCellRailSample start;
  SurfaceCellRailSample end;
  struct FaceSideEmbedding {
    int sourceFace = -1;
    int sourceEdge = -1;
    int sideSign = 0;
    Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
    Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  };
  std::vector<FaceSideEmbedding> incidentSides;
};

struct SurfaceCellRailIntervalSelection {
  const SurfaceCellRailIntervalRef *interval = nullptr;
  SurfaceCellRailIntervalRef::FaceSideEmbedding side;
};

enum class RailBuildStatus : int {
  Valid = 0,
  OddSampleCount = 1,
  InvalidSamplePair = 2,
  InvalidSourceEdge = 3,
  DuplicateRailId = 4,
  DuplicateInterval = 5,
  NonContiguousIntervals = 6,
  InvalidClosedLoop = 7,
  InvalidIncidentSides = 8,
  InvalidRailId = 9,
  EmptyRail = 10,
  InvalidSampleGeometry = 11,
  InvalidRailParameters = 12,
  DisconnectedIntervals = 13,
  TypedAuthorityMismatch = 14,
};

struct RailIntervalBuildResult {
  RailBuildStatus status = RailBuildStatus::Valid;
  std::vector<SurfaceCellRailIntervalRef> intervals;
  std::optional<authority::HardRailId> railId;
  int intervalIndex = -1;
};

enum class RailContinuationStatus : int {
  Found = 0,
  OpenEndpoint = 1,
  MissingInterval = 2,
  SideDiscontinuity = 3,
  SourceSheetBlocked = 4,
};

struct RailContinuationResult {
  RailContinuationStatus status = RailContinuationStatus::MissingInterval;
  SurfaceCellRailIntervalSelection selection;
};

int local_edge_for_key(const Eigen::MatrixXi &faces, const int face,
                       const authority::SourceEdgeTopologyKey &key);

authority::SourceEdgeTopologyKey local_edge_key(
    const Eigen::MatrixXi &faces, const int face, const int edge);

bool rail_sample_is_finite(const SurfaceCellRailSample &sample);

double rail_position_tolerance(const Eigen::RowVector3d &a,
                                      const Eigen::RowVector3d &b);

double rail_parameter_tolerance(const double a, const double b);

int rail_sample_source_vertex(const Eigen::MatrixXi &faces,
                                     const SurfaceCellRailSample &sample);

bool rail_sample_geometry_is_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellRailSample &sample);

RailIntervalBuildResult
rail_interval_refs(
    const std::vector<SurfaceCellRail> &rails,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
        &edgeFaces,
    const FieldAlignedCurveNetwork *fieldAlignedNetwork = nullptr);

SurfaceCellRailIntervalSelection find_rail_interval(
    const std::vector<SurfaceCellRailIntervalRef> &intervals, const int face,
    const int edge);

RailContinuationResult find_next_rail_interval(
    const std::vector<SurfaceCellRailIntervalRef> &intervals,
    const SurfaceCellRailIntervalSelection &current, const int direction,
    const SurfaceCellTracingOptions &options);

double rail_parameter_at_position(
    const SurfaceCellRailIntervalRef &interval,
    const Eigen::RowVector3d &position);

Eigen::RowVector3d rail_direction(
    const SurfaceCellRailIntervalRef &interval, const int direction);

int branch_from_family_sign(const int family, const int sign);

void family_sign_from_branch(const int branch, int &family, int &sign);

Eigen::RowVector3d axis_for_family(const Eigen::MatrixXd &faceAxisX,
                                          const Eigen::MatrixXd &faceAxisY,
                                          const int face, const int family,
                                          const int sign);

std::int64_t quantized_barycentric_value(const double value);

SurfaceTraceState make_trace_state(const SurfaceTracePoint &point,
                                          const int entryEdge,
                                          const int family,
                                          const int sign);

int normalized_branch(const int branch);

SurfacePeriodicHolonomy canonicalize_periodic_holonomy(
    SurfacePeriodicHolonomy relation);

SurfacePeriodicHolonomyInsertStatus insert_periodic_holonomy(
    std::vector<SurfacePeriodicHolonomy> &relations,
    SurfacePeriodicHolonomy relation);

Eigen::RowVector3d transport_direction_between_faces(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int sourceFace, const int targetFace,
    const Eigen::RowVector3d &direction);

struct BranchTransitionResult {
  bool valid = false;
  int matching = 0;
  double effort = 0.0;
  int family = 0;
  int sign = 1;
  double turnAngle = std::numeric_limits<double>::infinity();
  Eigen::RowVector3d direction = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d transportedInput = Eigen::RowVector3d::Zero();
};

bool transition_faces_match(
    const fields::CrossFieldEdgeTransition &transition, const int sourceFace,
    const int targetFace);

BranchTransitionResult resolve_branch_transition(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
        &edgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &edgeMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const authority::SourceEdgeTopologyKey &edgeKey,
    const int sourceFace, const int targetFace, const int sourceFamily,
    const int sourceSign, const Eigen::RowVector3d &sourceDirection,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions);

bool direction_enters_face_from_vertex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int face, const int vertex, const Eigen::RowVector3d &direction);

enum class VertexContinuationStatus : int {
  Found = 0,
  Boundary = 1,
  Feature = 2,
  SourceSheet = 3,
  FieldMetadata = 4,
};

struct VertexContinuationResult {
  VertexContinuationStatus status = VertexContinuationStatus::Boundary;
  int face = -1;
  int family = 0;
  int sign = 1;
  int matching = 0;
  double matchingEffort = 0.0;
  double turnAngle = std::numeric_limits<double>::infinity();
  Eigen::RowVector3d direction = Eigen::RowVector3d::Zero();
  std::vector<int> facePath;
};

struct VertexPathStep {
  int face = -1;
  std::optional<authority::SourceEdgeTopologyKey> edgeKey;
};

std::map<int, std::vector<VertexPathStep>> vertex_face_adjacency(
    const int vertex,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
        &edgeFaces);

bool continuation_is_better(const VertexContinuationResult &candidate,
                                   const VertexContinuationResult &best);

VertexContinuationResult resolve_vertex_continuation(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>>
        &edgeFaces,
    const std::map<authority::SourceEdgeTopologyKey, int> &edgeMatchingIndices,
    const EdgeTransitionLookup &transitionLookup, const int currentFace,
    const int vertex, const int currentFamily, const int currentSign,
    const Eigen::RowVector3d &incomingDirection,
    const SurfaceCellTracingOptions &options,
    const Eigen::VectorXi *edgeMatching, const Eigen::VectorXd *edgeEffort,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions);

Eigen::Vector2d project_for_quad_test(const Eigen::RowVector3d &point,
                                             const int dropAxis);

double orient2d(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                       const Eigen::Vector2d &c);

bool segments_intersect_2d(const Eigen::Vector2d &a,
                                  const Eigen::Vector2d &b,
                                  const Eigen::Vector2d &c,
                                  const Eigen::Vector2d &d);

bool point_on_segment_2d(const Eigen::Vector2d &point,
                                const Eigen::Vector2d &a,
                                const Eigen::Vector2d &b,
                                const double tolerance);

bool segments_intersect_beyond_shared_endpoint_2d(
    const Eigen::Vector2d &a, const Eigen::Vector2d &b,
    const Eigen::Vector2d &c, const Eigen::Vector2d &d);

CellRejectionReason classify_quad_loop(
    const std::array<Eigen::RowVector3d, 4> &corners, const double h,
    const Eigen::RowVector3d &expectedNormal,
    const SurfaceCellTracingOptions &options);

bool quad_loop_is_valid(const std::array<Eigen::RowVector3d, 4> &corners,
                               const double h);


bool trace_segment_crosses_authoritative_rail(
    const SurfaceTraceSegment &segment,
    const std::vector<SurfaceCellRail> &rails);

CellRejectionReason validate_closed_boundary_paths(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::array<SurfaceTracePoint, 4> &corners,
    const std::array<std::vector<SurfaceTraceSegment>, 4> &boundaryPaths,
    const double tolerance);

SurfaceTracePoint vertex_point_in_face(const Eigen::MatrixXi &faces,
                                              const int face,
                                              const int vertex);

struct AdaptiveSeedCandidate {
  double normalizedDistance = 0.0;
  int face = -1;
  int corner = -1;
  int vertex = -1;

  bool operator<(const AdaptiveSeedCandidate &other) const {
    if (std::abs(normalizedDistance - other.normalizedDistance) > 1.0e-14) {
      return normalizedDistance < other.normalizedDistance;
    }
    return std::tie(face, corner, vertex) >
           std::tie(other.face, other.corner, other.vertex);
  }
};

std::set<authority::SourceEdgeTopologyKey> combined_barrier_edges(
    const SurfaceCellTracingOptions &options);

int seed_anchor_vertex(const SurfaceTraceSeed &seed,
                              const Eigen::MatrixXi &faces,
                              const int vertexCount);

int face_label_or_default(const std::vector<int> &labels,
                                 const int face,
                                 const int fallback);

bool trace_respects_face_labels(const SurfaceTraceResult &trace,
                                       const std::vector<int> &components,
                                       const std::vector<int> &sheets);

/**
 * Topological field traces may cross local sheet-chart boundaries through
 * source adjacency, but may never cross a connected-component boundary.
 */
bool trace_respects_source_component(const SurfaceTraceResult &trace,
                                     const std::vector<int> &components);

SourceSurfaceLabels classify_source_surface_labels(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::set<authority::SourceEdgeTopologyKey> &barrierEdges = {},
    const SourceSurfaceClassifierOptions &options = {});

std::optional<SourceTopologyRegions> build_source_topology_regions(
    const Eigen::MatrixXi &faces,
    const SurfaceCellTracingOptions &options);

bool source_edge_is_internal_isolation_seam(
    const SurfaceCellTracingOptions &options, const int faceCount,
    const std::vector<authority::TopologyRegionId> &regionByFace,
    const int firstFace,
    const int secondFace, const authority::SourceEdgeTopologyKey &edgeKey);

bool source_surface_classifier_options_valid(
    const SourceSurfaceClassifierOptions &options);
struct IntrinsicSurfaceGraph {
  std::vector<std::vector<std::pair<int, double>>> adjacency;
  int faceCount = 0;

  int node(const int face, const int corner) const {
    return face * 3 + corner;
  }
};

bool trace_point_is_valid(const SurfaceTracePoint &point,
                                 const Eigen::MatrixXi &faces);

IntrinsicSurfaceGraph build_intrinsic_surface_graph(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellTracingOptions &options,
    const std::set<authority::SourceEdgeTopologyKey> &barrierEdges);

Eigen::VectorXd intrinsic_distances_from_points(
    const IntrinsicSurfaceGraph &graph, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    const std::vector<SurfaceTracePoint> &sources);

double intrinsic_distance_to_point(
    const IntrinsicSurfaceGraph &graph, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces, const Eigen::VectorXd &distance,
    const SurfaceTracePoint &target);

double intrinsic_same_sheet_distance(
    const IntrinsicSurfaceGraph &graph, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces, const SurfaceTracePoint &source,
    const SurfaceTracePoint &target);

Eigen::VectorXd graph_distances_from_vertices(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &sourceVertices,
    const std::set<authority::SourceEdgeTopologyKey> &barrierEdges = {});

} // namespace surface_cell_tracing_detail

std::vector<SurfaceTraceSeed> generate_deterministic_surface_seeds(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {});

SurfaceTraceResult trace_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTraceSeed &seed, const int family, const int sign,
    const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions =
        nullptr);

SurfaceWalkResult walk_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTracePoint &start, const int family, const int sign,
    const double distance, const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions =
        nullptr);

void cross_field_axes(const fields::CrossFieldResult &crossField,
                             Eigen::MatrixXd &faceAxisX,
                             Eigen::MatrixXd &faceAxisY);

SurfaceTraceResult trace_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const SurfaceTraceSeed &seed,
    const int family, const int sign,
    const SurfaceCellTracingOptions &options = {});

SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions =
        nullptr);

SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const Eigen::VectorXd &targetSize,
    const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options = {});

SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions =
        nullptr);

SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {});

SurfaceCellTracingOverlay make_surface_cell_tracing_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
    const double glyphScale = 0.25);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CELL_TRACING_H
