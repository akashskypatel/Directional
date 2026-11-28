// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once
#ifndef DIRECTIONAL_GEOMETRY_GLOBAL_CONFORMITY_BASELINE_H
#define DIRECTIONAL_GEOMETRY_GLOBAL_CONFORMITY_BASELINE_H

#include <cstddef>
#include <cstdint>
#include <map>
#include <optional>
#include <utility>
#include <variant>
#include <vector>

#include <Eigen/Core>
#include <directional/geometry/GlobalConformityPlan.h>

namespace directional::geometry {

class FieldAlignedCurveNetwork;
struct AdaptiveFeatureCurve;

/** Family/sign-free occurrence of one A2b span in one region boundary walk. */
struct BaselineConformityIncidence {
  ConformityBoundaryIncidenceId id;
  ConformitySpanId span;
  authority::Orientation orientation = authority::Orientation::Forward;

  auto operator<=>(const BaselineConformityIncidence &) const = default;
};

struct BaselineConformitySpanParityReceipt {
  ConformitySpanId span;
  bool preferredOdd = false;
  bool selectedFlip = false;

  bool operator==(const BaselineConformitySpanParityReceipt &) const = default;
};

struct BaselineConformityRegionReceipt {
  authority::NetworkRegionId region;
  bool preferredResidualOdd = false;
  EInt finalBoundaryCount;
  bool finalParityEven = false;

  bool operator==(const BaselineConformityRegionReceipt &) const = default;
};

struct BaselineConformityComponentReceipt {
  std::size_t componentOrdinal = 0U;
  std::vector<authority::NetworkRegionId> regions;
  std::vector<ConformitySpanId> terminalSpans;
  bool hasExterior = false;
  bool exteriorDemandOdd = false;

  bool operator==(const BaselineConformityComponentReceipt &) const = default;
};

struct BaselineConformityDemandVertex {
  std::optional<authority::NetworkRegionId> region;
  std::optional<std::size_t> exteriorComponentOrdinal;

  bool operator==(const BaselineConformityDemandVertex &) const = default;
};

struct BaselineConformityLexReceipt {
  ConformitySpanId span;
  bool smallerCountRequiresFlip = false;
  bool trialFeasible = false;
  std::optional<EInt> trialMinimumFlipCount;
  bool selectedFlip = false;
  EInt selectedMinimumFlipCount;

  bool operator==(const BaselineConformityLexReceipt &) const = default;
};

struct BaselineConformityObjectiveValue {
  EInt primaryDeviation;
  std::vector<EInt> canonicalCounts;

  bool operator==(const BaselineConformityObjectiveValue &) const = default;
};

enum class BaselineConformityWorkPhase : std::uint8_t { Producer, Validator };

enum class BaselineConformityTJoinPurpose : std::uint8_t {
  InitialOptimum,
  TrialPrefix,
  SelectedPrefix
};

struct BaselineConformityTJoinWorkReceipt {
  BaselineConformityWorkPhase phase = BaselineConformityWorkPhase::Producer;
  BaselineConformityTJoinPurpose purpose =
      BaselineConformityTJoinPurpose::InitialOptimum;
  std::optional<ConformitySpanId> span;
  std::size_t fixedPrefixLength = 0U;
  std::size_t terminalCount = 0U;
  std::size_t matchingNodeCount = 0U;
  std::size_t matchingEdgeCount = 0U;
  bool matchingExecuted = false;
  std::size_t maximumMatchingDistanceBitWidth = 0U;

  bool operator==(const BaselineConformityTJoinWorkReceipt &) const = default;
};

struct BaselineConformityWorkReceipt {
  std::size_t spanCount = 0U;
  std::size_t parityVertexCount = 0U;
  std::size_t parityEdgeCount = 0U;
  std::size_t producerTJoinInvocationCount = 0U;
  std::size_t validatorTJoinInvocationCount = 0U;
  std::size_t aggregateTJoinInvocationCount = 0U;
  std::vector<BaselineConformityTJoinWorkReceipt> tJoinInvocations;
  std::size_t retryResetCount = 0U;
  bool producerInitialOptimumPending = false;
  std::size_t producerRemainingCanonicalSpanDecisions = 0U;
  bool validatorInitialOptimumPending = false;
  std::size_t validatorRemainingCanonicalSpanDecisions = 0U;

  bool operator==(const BaselineConformityWorkReceipt &) const = default;
};

struct BaselineConformityExactWidthReceipt {
  std::size_t preferredCountBits = 0U;
  std::size_t scheduledCountBits = 0U;
  std::size_t minimumFlipCountBits = 0U;
  std::size_t lexMinimumCountBits = 0U;
  std::size_t regionBoundaryCountBits = 0U;
  std::size_t matchingDistanceBits = 0U;
  std::size_t breakpointOrdinalBits = 0U;
  std::size_t breakpointNumeratorBits = 0U;
  std::size_t breakpointDenominatorBits = 0U;
  std::size_t overallMaximumBits = 0U;

  bool operator==(const BaselineConformityExactWidthReceipt &) const = default;
};

/**
 * One maximal straight run of a span's support, as the D7 count integrates it.
 * Breakpoints are shared across runs by metric and spaced linearly in length
 * within a run (RA-217).
 */
struct BaselineConformityMetricRun {
  std::size_t firstPiece = 0U;
  /** Fraction of the run's length at which each of its pieces starts. */
  std::vector<authority::FieldExactRational> pieceStarts;
  /** Exact square of the run's integral of 1/h. */
  authority::FieldExactRational squaredMetric;

  bool operator==(const BaselineConformityMetricRun &) const = default;
};

/** Exact §17.7 certificate for the family/sign-free production baseline. */
struct GlobalConformityBaselineCertificate {
  std::vector<BaselineConformitySpanParityReceipt> spanParity;
  std::vector<BaselineConformityRegionReceipt> regions;
  std::vector<BaselineConformityComponentReceipt> components;
  std::vector<BaselineConformityDemandVertex> demandedVertices;
  std::vector<ConformitySpanId> selectedFlips;
  std::vector<BaselineConformityLexReceipt> lexReceipts;
  EInt minimumFlipCount;
  BaselineConformityObjectiveValue objective;
  BaselineConformityWorkReceipt work;
  BaselineConformityExactWidthReceipt exactWidths;
  std::uint64_t sourceDigest = 0U;
  std::uint64_t networkDigest = 0U;
  std::uint64_t cutGraphDigest = 0U;
  std::uint64_t topologyPlanDigest = 0U;
  std::uint64_t targetMetricDigest = 0U;
  std::uint64_t normalizedProblemDigest = 0U;

  bool operator==(const GlobalConformityBaselineCertificate &) const = default;
};

/** D5 binding of one A2b arc to the span that schedules it (RA-219). */
struct BaselineConformityArcBinding {
  ConformitySpanId span;
  /** Ordinal of the arc in the span's chain; the identifying arc is 0. */
  std::size_t chainOrdinal = 0U;
  /** Orientation of the arc along the span's chain. */
  authority::Orientation orientation = authority::Orientation::Forward;
  /** Source-path pieces of the chain's arcs before this one. */
  std::size_t firstSupportPiece = 0U;

  bool operator==(const BaselineConformityArcBinding &) const = default;
};

/**
 * Baseline A3 input. Boundary incidences are intentionally not caller supplied:
 * they are rebuilt from GlobalTopologyPlan region boundary walks so family/sign
 * cannot enter baseline validity through an optional compatibility field.
 */
struct GlobalConformityBaselineInput {
  Eigen::MatrixXd sourceVertices;
  Eigen::VectorXd targetSize;
  std::vector<ConformitySpanInput> spans;
  /**
   * D5 chains (RA-219): the A2b arcs each multi-arc span covers, in order, with
   * the identifying arc first. A span without a chain covers only its
   * identifying arc.
   */
  std::vector<std::vector<GlobalTopologyOrientedArc>> chains;
};

struct GlobalConformityBaselineValidationCandidate {
  std::vector<ConformityScheduleEntry> schedule;
  std::vector<BaselineConformityIncidence> incidences;
  GlobalConformityBaselineCertificate certificate;
  std::uint64_t semanticDigest = 0U;
};

class GlobalConformityBaselineBuildResult;

class GlobalConformityBaselinePlan {
public:
  [[nodiscard]] const std::vector<ConformityScheduleEntry> &schedule() const noexcept {
    return schedule_;
  }
  [[nodiscard]] const std::vector<BaselineConformityIncidence> &incidences() const noexcept {
    return incidences_;
  }
  [[nodiscard]] const GlobalConformityBaselineCertificate &certificate() const noexcept {
    return certificate_;
  }
  [[nodiscard]] std::uint64_t source_digest() const noexcept {
    return certificate_.sourceDigest;
  }
  [[nodiscard]] std::uint64_t network_digest() const noexcept {
    return certificate_.networkDigest;
  }
  [[nodiscard]] std::uint64_t cut_graph_digest() const noexcept {
    return certificate_.cutGraphDigest;
  }
  [[nodiscard]] std::uint64_t topology_plan_digest() const noexcept {
    return certificate_.topologyPlanDigest;
  }
  [[nodiscard]] std::uint64_t target_metric_digest() const noexcept {
    return certificate_.targetMetricDigest;
  }
  [[nodiscard]] std::uint64_t normalized_problem_digest() const noexcept {
    return certificate_.normalizedProblemDigest;
  }
  [[nodiscard]] std::uint64_t semantic_digest() const noexcept {
    return semanticDigest_;
  }
  [[nodiscard]] const ConformityScheduleEntry *
  find_schedule(ConformitySpanId span) const noexcept;
  [[nodiscard]] std::optional<ConformityBreakpointLocation>
  breakpoint_location(ConformitySpanId span, const EInt &exactOrdinal) const;
  /** O37: the span's breakpoints 0..count in one pass, each equal to
   *  breakpoint_location for its ordinal. */
  [[nodiscard]] std::optional<std::vector<ConformityBreakpointLocation>>
  breakpoint_locations(ConformitySpanId span) const;
  [[nodiscard]] const BaselineConformityArcBinding *
  find_arc_binding(authority::NetworkArcId arc) const noexcept;
  [[nodiscard]] GlobalConformityBaselineValidationCandidate
  validation_candidate() const;

private:
  friend GlobalConformityBaselineBuildResult build_global_conformity_baseline(
      const GlobalTopologyPlan &, const GlobalConformityBaselineInput &);

  GlobalConformityBaselinePlan(
      std::vector<ConformityScheduleEntry> schedule,
      std::vector<BaselineConformityIncidence> incidences,
      GlobalConformityBaselineCertificate certificate,
      std::uint64_t semanticDigest,
      std::vector<std::vector<BaselineConformityMetricRun>> metricRuns,
      std::map<authority::NetworkArcId, BaselineConformityArcBinding> arcBindings)
      : schedule_(std::move(schedule)), incidences_(std::move(incidences)),
        certificate_(std::move(certificate)), semanticDigest_(semanticDigest),
        metricRuns_(std::move(metricRuns)),
        arcBindings_(std::move(arcBindings)) {}

  std::vector<ConformityScheduleEntry> schedule_;
  std::vector<BaselineConformityIncidence> incidences_;
  GlobalConformityBaselineCertificate certificate_;
  std::uint64_t semanticDigest_ = 0U;
  /** D7 runs of each schedule entry, in schedule order (RA-217). */
  std::vector<std::vector<BaselineConformityMetricRun>> metricRuns_;
  /** D5 span of every A2b arc (RA-219). */
  std::map<authority::NetworkArcId, BaselineConformityArcBinding> arcBindings_;
};

class GlobalConformityBaselineBuildResult {
public:
  explicit GlobalConformityBaselineBuildResult(GlobalConformityBaselinePlan plan)
      : state_(std::move(plan)) {}
  explicit GlobalConformityBaselineBuildResult(GlobalConformityPlanError error)
      : state_(std::move(error)) {}

  [[nodiscard]] bool has_value() const noexcept {
    return std::holds_alternative<GlobalConformityBaselinePlan>(state_);
  }
  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
  [[nodiscard]] const GlobalConformityBaselinePlan &value() const {
    return std::get<GlobalConformityBaselinePlan>(state_);
  }
  [[nodiscard]] GlobalConformityBaselinePlan &value() {
    return std::get<GlobalConformityBaselinePlan>(state_);
  }
  [[nodiscard]] const GlobalConformityPlanError &error() const {
    return std::get<GlobalConformityPlanError>(state_);
  }

private:
  std::variant<GlobalConformityBaselinePlan, GlobalConformityPlanError> state_;
};

[[nodiscard]] GlobalConformityBaselineBuildResult
build_global_conformity_baseline(const GlobalTopologyPlan &topology,
                                 const GlobalConformityBaselineInput &input);

/** D5 A3 input over an A2b plan (RA-220): one span per arc, with each arc's
 *  support copied verbatim, except that the source-boundary arcs of one rail
 *  between stops form one chained span. Boundary field-corner source vertices
 *  also stop chains. Nothing when the plan and network differ. */
[[nodiscard]] std::optional<GlobalConformityBaselineInput>
make_chained_global_conformity_baseline_input(
    const Eigen::MatrixXd &sourceVertices, const Eigen::VectorXd &targetSize,
    const GlobalTopologyPlan &topology, const FieldAlignedCurveNetwork &network,
    const std::vector<AdaptiveFeatureCurve> &featureCurves,
    const std::vector<authority::SourceVertexId> &fieldCornerVertices = {});

[[nodiscard]] std::optional<GlobalConformityPlanError>
validate_global_conformity_baseline_candidate(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineInput &input,
    const GlobalConformityBaselineValidationCandidate &candidate);

[[nodiscard]] GlobalConformityBaselineBuildResult
validate_global_conformity_baseline(const GlobalTopologyPlan &topology,
                                    const GlobalConformityBaselineInput &input,
                                    const GlobalConformityBaselinePlan &plan);

/** Why a region's boundary walk could not be bound to the A3 plan. */
enum class RegionBoundaryScheduleFailureReason : std::uint8_t {
  /** The A3 plan was built for a different A2b plan. */
  TopologyPlanMismatch = 0,
  /** No A3 span has the arc's path as the support slice its binding names. */
  ArcNotScheduled = 1,
  /** No A3 incidence carries this walk occurrence with the arc's span and
   *  orientation. */
  IncidenceNotFound = 2,
};

[[nodiscard]] const char *region_boundary_schedule_failure_reason_name(
    RegionBoundaryScheduleFailureReason reason) noexcept;

/** One occurrence of an A2b arc in a region's boundary walk, bound to the A3
 *  span that schedules it. */
struct RegionBoundaryScheduleSide {
  GlobalTopologyOrientedArc arc;
  /** The walk enters the arc at startNode and leaves it at endNode. */
  authority::NetworkNodeId startNode;
  authority::NetworkNodeId endNode;
  ConformitySpanId span;
  ConformityBoundaryIncidenceId incidence;
  /** Position of the arc in its span's chain; 0 for a single-arc span. */
  std::size_t chainOrdinal = 0U;
  /** True when the walk runs in the span's chain direction. */
  bool alongSpan = true;
  EInt spanCount;
};

/** The A3 boundary schedule of one A2b region, in the region's walk order.
 *  boundaryCount adds each incidence's span count once. */
struct RegionBoundarySchedule {
  authority::NetworkRegionId region;
  std::vector<RegionBoundaryScheduleSide> sides;
  EInt boundaryCount;
};

struct RegionBoundaryScheduleFailure {
  RegionBoundaryScheduleFailureReason reason =
      RegionBoundaryScheduleFailureReason::TopologyPlanMismatch;
  std::optional<authority::NetworkRegionId> region;
  std::optional<std::size_t> boundaryOrdinal;
};

using RegionBoundaryScheduleResult =
    std::variant<std::vector<RegionBoundarySchedule>,
                 RegionBoundaryScheduleFailure>;

/**
 * The input A4 consumes per region: every region of the A2b plan, in plan
 * order, with each walk occurrence bound to its A3 span, incidence and count,
 * or the first occurrence that cannot be bound. Read-only over both plans.
 * An arc shared by two regions binds to the same span from both walks
 * (DESIGN §7.4).
 */
[[nodiscard]] RegionBoundaryScheduleResult
build_region_boundary_schedules(const GlobalTopologyPlan &topology,
                                const GlobalConformityBaselinePlan &baseline);

/** Why a region's boundary corners could not be read from the field. */
enum class RegionCornerSidesFailureReason : std::uint8_t {
  /** A schedule names a region or arc the A2b plan does not have. */
  TopologyPlanMismatch = 0,
  /** The A2a network is not the one the A2b plan was built from. */
  NetworkMismatch = 1,
  /** A walk node joins a mandatory or cut arc. */
  UnsupportedArcKind = 2,
  /** A walk node that is not a singularity port node joins two trace arcs
   *  that neither continue one trace nor meet at a three-arc T-node. */
  UnsupportedContactNode = 3,
  /** At a singularity port node an arc end is neither its trace's departure
   *  from a port of that node nor its arrival at one. */
  PortNotFound = 4,
  /** A region certified free of interior singularities does not turn by
   *  exactly four quarter turns: the sum of (2 - gap) over its walk nodes. */
  TurningNotFourQuarterTurns = 5,
};

[[nodiscard]] const char *region_corner_sides_failure_reason_name(
    RegionCornerSidesFailureReason reason) noexcept;

/** A walk node where the region's boundary turns: its interior gap is not two
 *  field quarter turns. */
struct RegionBoundaryCorner {
  authority::NetworkNodeId node;
  /** The schedule side the walk leaves this node along. */
  std::size_t scheduleSide = 0U;
  /** Interior angle at the node in field quarter turns. */
  int quarterTurns = 0;
};

/** The schedule sides between two consecutive corners. */
struct RegionCornerSide {
  /** First schedule side; the run continues cyclically for sideCount sides. */
  std::size_t firstScheduleSide = 0U;
  std::size_t scheduleSideCount = 0U;
  /** Sum of the run's span counts. */
  EInt count;
};

/** The corners of one region's boundary and the sides they delimit. Corners
 *  follow the schedule's walk order starting at the corner with the lowest
 *  schedule side; sides[k] runs from corners[k] to the next corner. A region
 *  without corners has no sides. */
struct RegionCornerSides {
  authority::NetworkRegionId region;
  std::vector<RegionBoundaryCorner> corners;
  std::vector<RegionCornerSide> sides;
};

struct RegionCornerSidesFailure {
  RegionCornerSidesFailureReason reason =
      RegionCornerSidesFailureReason::TopologyPlanMismatch;
  std::optional<authority::NetworkRegionId> region;
  /** The schedule side leaving the failing node. */
  std::optional<std::size_t> scheduleSide;
};

using RegionCornerSidesResult =
    std::variant<std::vector<RegionCornerSides>, RegionCornerSidesFailure>;

/**
 * The field turning at every walk node of every region schedule, in field
 * quarter turns, from the walk's incoming arc to its outgoing arc on the
 * region's side: 2 where one trace continues through the node; 1 at a
 * three-arc T-node between two traces; at a singularity port node, the number
 * of port sectors swept counter-clockwise from the outgoing arc's port to the
 * incoming arc's port (the region lies counter-clockwise of its outgoing arc
 * in the plan's rotation system). Corners are the nodes whose gap is not 2.
 * Every other node is a typed failure, as is a region certified free of
 * interior singularities whose sum of (2 - gap) is not 4. Read-only over the
 * schedules, the plan and the network.
 */
[[nodiscard]] RegionCornerSidesResult
build_region_corner_sides(const GlobalTopologyPlan &topology,
                          const FieldAlignedCurveNetwork &network,
                          const std::vector<RegionBoundarySchedule> &schedules);

} // namespace directional::geometry

#endif
