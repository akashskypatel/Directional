// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_FLOW_REP_STRANDS_H
#define DIRECTIONAL_GEOMETRY_FLOW_REP_STRANDS_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::geometry {

enum class FlowRepAffinityCue : int {
  ParallelAdjacent = 0,
  JunctionContinuation = 1,
  OrthogonalJunction = 2,
  GeometricCrossing = 3,
  FeatureConflict = 4,
  SameStrandCrossing = 5,
  None = 6,
};

enum class FlowRepEndpointTag : int {
  Boundary = 0,
  Feature = 1,
  NetworkJunction = 2,
  NeedsCompletion = 3,
};

enum class FlowRepPatchClass : int {
  Infeasible = 0,
  ThreeSided = 3,
  FourSided = 4,
  FiveSided = 5,
  SixSided = 6,
};

enum class FlowRepSelectionFailureCode : int {
  None = 0,
  EmptyNetwork = 1,
  MissingCoverageEvidence = 2,
  MissingCycleEvidence = 3,
  InvalidCoverageEvidence = 4,
  InvalidCycleEvidence = 5,
  InvalidArcIdentity = 6,
  IncompleteArcProvenance = 7,
  IncompleteCycleCoverage = 8,
  MandatoryRailLoss = 9,
};

const char *flow_rep_selection_failure_name(
    const FlowRepSelectionFailureCode code);

struct FlowRepArc {
  int id = -1;
  Eigen::RowVector3d start = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d end = Eigen::RowVector3d::Zero();
  int sourceFace = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  /// Canonical intrinsic endpoint identities mirror arrangement node keys.
  /// They prevent close but distinct surface points from being welded by a
  /// world-space tolerance while still identifying one source-edge point in
  /// both incident triangle charts.
  bool startIntrinsicEndpointKeyValid = false;
  bool endIntrinsicEndpointKeyValid = false;
  std::uint64_t startIntrinsicEndpointKey = 0U;
  std::uint64_t endIntrinsicEndpointKey = 0U;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<authority::IsolationSheetId> sourceIsolationSheet;
  int family = 0;
  int featureClass = 0;
  bool mandatoryRail = false;
  bool boundaryRail = false;
  bool hardFeatureRail = false;
  int strandProvenance = -1;
  int featureProvenance = -1;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  double dominance = 1.0;
  double alignmentCost = 0.0;
  int sameStrandHint = -1;
  bool initiallyActive = true;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  /// A field-aligned connector emitted from a boundary/feature rail seed.
  /// These arcs complete the layout graph but are not authoritative rails and
  /// may be simplified only when endpoint, coverage, and cycle guards permit.
  bool layoutSupport = false;
  int supportTraceId = -1;
  int supportSeedId = -1;
  int supportSegment = -1;
  /// Endpoint ownership is geometric, not restricted to endpoint equality:
  /// a trace can terminate in the interior of a retained rail/network arc.
  bool startEmbeddedAnchor = false;
  bool endEmbeddedAnchor = false;
  /// Required separatrix topology may be extended but never leaf-pruned.
  bool singularitySupport = false;
  std::vector<int> substitutions;
};

struct FlowRepCoverageSample {
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  int sourceFace = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<authority::IsolationSheetId> sourceIsolationSheet;
  double targetSize = 0.0;
  int sourceArcId = -1;
};

struct FlowRepAffinity {
  int firstArc = -1;
  int secondArc = -1;
  double score = 0.0;
  FlowRepAffinityCue cue = FlowRepAffinityCue::None;
};

struct FlowRepStrand {
  int id = -1;
  std::vector<int> arcIds;
  bool closed = false;
  bool mandatory = false;
  double length = 0.0;
  double curvaturePenalty = 0.0;
};

struct FlowRepFlowline {
  int id = -1;
  int strandId = -1;
  std::vector<int> arcIds;
  bool closed = false;
  bool mandatory = false;
  double length = 0.0;
};

struct FlowRepCycleInput {
  int id = -1;
  int proposalId = -1;
  std::vector<std::vector<int>> sideArcIds;
  std::vector<int> boundaryArcIds;
  std::vector<Eigen::RowVector3d> normals;
  std::vector<Eigen::RowVector3d> boundaryNormalA;
  std::vector<Eigen::RowVector3d> boundaryNormalB;
  std::vector<double> distanceA;
  std::vector<double> distanceB;
  std::vector<double> surfaceDistances;
  std::vector<int> sideCounts;
  double targetSize = 1.0;
  double normalThresholdRadians = 0.25;
  bool diskTopology = true;
  bool forbiddenTurn = false;
  bool unresolvedHardFeatureCrossing = false;
  bool impossibleSideCounts = false;
};

struct FlowRepCycleEvaluation {
  bool descriptive = false;
  bool quadrangulable = false;
  double normalP90 = 0.0;
  double surfaceP95 = 0.0;
  double sizePenalty = 0.0;
  double quadPenalty = std::numeric_limits<double>::infinity();
  double energy = std::numeric_limits<double>::infinity();
  FlowRepPatchClass patchClass = FlowRepPatchClass::Infeasible;
};

struct FlowRepSparseOptions {
  double parallelDotThreshold = 0.94;
  double adjacentDistance = 1.0e-8;
  double crossingPenalty = -10.0;
  double featureConflictPenalty = -8.0;
  double orthogonalPenalty = -2.0;
  double maxCoverageWorsening = 0.02;
  bool requireCoverageEvidence = true;
  bool requireCycleEvidence = true;
  bool requireCompleteProvenance = true;
};

struct FlowRepSparseNetwork {
  bool selectionSucceeded = false;
  FlowRepSelectionFailureCode failureCode =
      FlowRepSelectionFailureCode::None;
  std::vector<int> retainedArcIds;
  std::vector<int> removedArcIds;
  std::vector<FlowRepEndpointTag> endpointTags;
  std::vector<FlowRepCycleEvaluation> cycleEvaluations;
  int mandatoryRails = 0;
  int retainedMandatoryRails = 0;
  int acceptedTransactions = 0;
  int attemptedStrandTransactions = 0;
  int rejectedStrandTransactions = 0;
  int retainedFlowlines = 0;
  int removedFlowlines = 0;
  int cycleRebuilds = 0;
  int coverageSampleCount = 0;
  int cycleEvidenceCount = 0;
  bool coverageEvidenceUsed = false;
  bool cycleEvidenceUsed = false;
  double denseCoverageMax = 0.0;
  double sparseCoverageMax = 0.0;
};

struct FlowRepEndpointCompletionOptions {
  int maxEndpointTraces = 4096;
  int maxAddedArcs = 100000;
  double intersectionTolerance = 1.0e-9;
  bool requireAllEndpointsResolved = true;
};

enum class FlowRepEndpointResolution : int {
  AlreadyResolved = 0,
  SegmentIntersection = 1,
  IntrinsicNode = 2,
  InvalidSourceFace = 3,
  DegenerateSource = 4,
  EmptyTrace = 5,
  NoNetworkCapture = 6,
  AddedArcLimit = 7,
};

struct FlowRepEndpointCompletionDiagnostic {
  int sourceArcId = -1;
  bool startEndpoint = false;
  bool requiredSingularitySupport = false;
  bool hardFeatureRail = false;
  int family = -1;
  int sign = 0;
  TraceTerminationReason termination = TraceTerminationReason::Budget;
  int tracedSegments = 0;
  int skippedDegenerateSegments = 0;
  int terminalSourceFace = -1;
  int terminalSourceVertex = -1;
  int terminalSourceEdge0 = -1;
  int terminalSourceEdge1 = -1;
  double terminalSourceEdgeT = -1.0;
  Eigen::RowVector3d terminalBarycentric =
      Eigen::RowVector3d::Constant(std::numeric_limits<double>::quiet_NaN());
  int lastRepresentableSourceFace = -1;
  int lastRepresentableSourceVertex = -1;
  int lastRepresentableSourceEdge0 = -1;
  int lastRepresentableSourceEdge1 = -1;
  double lastRepresentableSourceEdgeT = -1.0;
  Eigen::RowVector3d lastRepresentableBarycentric =
      Eigen::RowVector3d::Constant(std::numeric_limits<double>::quiet_NaN());
  double terminalDistanceToLastRepresentable = -1.0;
  int terminalFeatureRailCandidates = 0;
  int terminalCompatibleFeatureRailCandidates = 0;
  int generatedSupportTraceId = -1;
  int captureTargetArcId = -1;
  int captureTraceSegment = -1;
  double captureTraceParameter = -1.0;
  double captureTargetParameter = -1.0;
  int captureTargetSourceFace = -1;
  Eigen::RowVector3d captureBarycentric =
      Eigen::RowVector3d::Constant(std::numeric_limits<double>::quiet_NaN());
  Eigen::RowVector3d captureTargetStartBarycentric =
      Eigen::RowVector3d::Constant(std::numeric_limits<double>::quiet_NaN());
  Eigen::RowVector3d captureTargetEndBarycentric =
      Eigen::RowVector3d::Constant(std::numeric_limits<double>::quiet_NaN());
  FlowRepEndpointResolution resolution =
      FlowRepEndpointResolution::NoNetworkCapture;
};

enum class FlowRepEndpointCompletionFailureKind : int {
  None = 0,
  InvalidOptions = 1,
  IncompleteCrossFieldAxes = 2,
  InvalidRetainedArcIdentity = 3,
  DuplicateRetainedArc = 4,
  IncompleteRetainedArcProvenance = 5,
  EndpointTraceLimitExceeded = 6,
  GeneratedEndpointArcMissingProvenance = 7,
  UnresolvedRequiredEndpoints = 8,
};

struct FlowRepEndpointCompletionEvidence {
  int openEndpointsBefore = 0;
  int resolvedEndpoints = 0;
  int unresolvedEndpoints = 0;
  int unresolvedRequiredEndpoints = 0;
  int addedArcs = 0;
  std::array<int, 9> traceTerminationCounts{};
  std::vector<FlowRepEndpointCompletionDiagnostic> diagnostics;
};

struct FlowRepEndpointCompletionProduct {
  std::vector<FlowRepArc> arcs;
  std::vector<int> retainedArcIds;
  std::vector<FlowRepEndpointTag> endpointTags;
};

struct FlowRepEndpointCompletionFailure {
  FlowRepEndpointCompletionFailureKind kind =
      FlowRepEndpointCompletionFailureKind::None;
  std::string detail;
};

class FlowRepEndpointCompletionResult : public FlowRepEndpointCompletionEvidence {
public:
  using Product = FlowRepEndpointCompletionProduct;
  using Failure = FlowRepEndpointCompletionFailure;
  using Outcome = ProducerOutcome<Product, Failure>;

  FlowRepEndpointCompletionResult() = default;
  FlowRepEndpointCompletionResult(const FlowRepEndpointCompletionResult &) = default;
  FlowRepEndpointCompletionResult(FlowRepEndpointCompletionResult &&) noexcept = default;
  FlowRepEndpointCompletionResult &operator=(const FlowRepEndpointCompletionResult &) = default;
  FlowRepEndpointCompletionResult &operator=(FlowRepEndpointCompletionResult &&) noexcept = default;

  [[nodiscard]] static FlowRepEndpointCompletionResult produced(
      FlowRepEndpointCompletionEvidence evidence, Product product) {
    return FlowRepEndpointCompletionResult(
        std::move(evidence), Outcome{Produced<Product>{std::move(product)}});
  }

  [[nodiscard]] static FlowRepEndpointCompletionResult rejected(
      FlowRepEndpointCompletionEvidence evidence, Failure failure) {
    if (failure.kind == FlowRepEndpointCompletionFailureKind::None) {
      throw std::invalid_argument(
          "Rejected FlowRep endpoint completion requires a typed failure.");
    }
    return FlowRepEndpointCompletionResult(
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
  FlowRepEndpointCompletionResult(FlowRepEndpointCompletionEvidence evidence,
                                  Outcome outcome)
      : FlowRepEndpointCompletionEvidence(std::move(evidence)),
        outcome_(std::move(outcome)) {}

  Outcome outcome_{NotApplicable{}};
};

struct FlowRepSelectionInput {
  std::vector<FlowRepArc> arcs;
  std::vector<FlowRepCoverageSample> coverageSamples;
  std::vector<FlowRepCycleInput> cycles;
};

struct FlowRepOverlay {
  Eigen::MatrixXd rawArcStarts;
  Eigen::MatrixXd rawArcEnds;
  Eigen::VectorXi strandColor;
  Eigen::VectorXi retained;
  Eigen::VectorXi removed;
  Eigen::VectorXd cycleEnergy;
  Eigen::VectorXi patchClass;
};

namespace flow_rep_detail {

Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v);

double arc_length(const FlowRepArc &arc);

Eigen::RowVector3d arc_tangent(const FlowRepArc &arc);

bool close_points(const Eigen::RowVector3d &a,
                         const Eigen::RowVector3d &b, const double eps);

bool arcs_adjacent(const FlowRepArc &a, const FlowRepArc &b,
                          const double eps);

double cross2(const Eigen::RowVector3d &a, const Eigen::RowVector3d &b);

Eigen::RowVector3d barycentric_uv3(const Eigen::RowVector3d &bary);

Eigen::RowVector3d predicate_start(const FlowRepArc &arc);

Eigen::RowVector3d predicate_end(const FlowRepArc &arc);

FlowRepArc predicate_arc(const FlowRepArc &arc);

bool point_on_segment_2d(const Eigen::RowVector3d &p,
                                const Eigen::RowVector3d &a,
                                const Eigen::RowVector3d &b,
                                const double eps = 1.0e-10);

bool segments_cross_2d(const FlowRepArc &a, const FlowRepArc &b,
                              const bool countSharedEndpoints = false);

std::uint64_t point_key(const Eigen::RowVector3d &p);

std::uint64_t endpoint_key(const FlowRepArc &arc, const bool start);

double percentile(std::vector<double> values, const double p);

double point_segment_distance(const Eigen::RowVector3d &p,
                                     const FlowRepArc &arc);

bool finite_row3(const Eigen::RowVector3d &value);

bool valid_barycentric(const Eigen::RowVector3d &value,
                              const double tolerance = 1.0e-8);

bool arc_has_complete_provenance(const FlowRepArc &arc);

bool coverage_sample_is_valid(const FlowRepCoverageSample &sample);

bool sample_and_arc_are_intrinsically_compatible(
    const FlowRepCoverageSample &sample, const FlowRepArc &arc);

double normalized_intrinsic_sample_distance(
    const FlowRepCoverageSample &sample, const FlowRepArc &arc);

double coverage_max_distance(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds,
    const std::vector<FlowRepCoverageSample> &samples);

std::vector<FlowRepEndpointTag>
classify_endpoints(const std::vector<FlowRepArc> &arcs,
                   const std::vector<int> &activeArcIds);

} // namespace flow_rep_detail

std::vector<FlowRepArc> build_flow_rep_arcs_from_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellNetwork &network);

FlowRepSelectionInput build_flow_rep_selection_input(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
    const double defaultTargetSize = 1.0);

FlowRepAffinity compute_flow_rep_affinity(
    const FlowRepArc &a, const FlowRepArc &b,
    const FlowRepSparseOptions &options = {});

std::vector<FlowRepAffinity> compute_flow_rep_affinities(
    const std::vector<FlowRepArc> &arcs,
    const FlowRepSparseOptions &options = {});

bool strand_merge_is_simple(const std::vector<FlowRepArc> &arcs,
                                   const std::vector<int> &clusterA,
                                   const std::vector<int> &clusterB);

std::vector<FlowRepStrand> cluster_flow_rep_strands(
    const std::vector<FlowRepArc> &arcs,
    const FlowRepSparseOptions &options = {});

std::vector<FlowRepFlowline> extract_flow_rep_flowlines(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<FlowRepStrand> &strands);

FlowRepCycleEvaluation
evaluate_flow_rep_cycle(const FlowRepCycleInput &cycle);

namespace flow_rep_detail {

bool substitution_preserves_cycle_boundary(const FlowRepArc &original,
                                                   const FlowRepArc &candidate);

int resolve_cycle_arc(const FlowRepCycleInput &cycle,
                             const std::vector<FlowRepArc> &arcs,
                             const std::vector<unsigned char> &active,
                             const int originalArcId);

FlowRepCycleEvaluation rebuild_cycle_evaluation(
    const FlowRepCycleInput &cycle, const std::vector<FlowRepArc> &arcs,
    const std::vector<unsigned char> &active);

bool cycle_input_is_structurally_valid(
    const FlowRepCycleInput &cycle, const std::vector<FlowRepArc> &arcs);

bool cycle_evaluations_are_valid(
    const std::vector<FlowRepCycleEvaluation> &evaluations);

} // namespace flow_rep_detail


namespace flow_rep_detail {

struct FlowRepLogicalStrandKey {
  int kind = 0;
  std::optional<authority::HardRailId> rail;
  int primary = -1;
  int secondary = -1;
  int family = 0;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;

  auto operator<=>(const FlowRepLogicalStrandKey &) const = default;
};

FlowRepLogicalStrandKey logical_strand_key(const FlowRepArc &arc);

std::uint64_t embedded_endpoint_key(const FlowRepArc &arc,
                                    const bool start);

void assign_intrinsic_endpoint_keys(FlowRepArc &arc,
                                    const Eigen::MatrixXi &faces);

std::vector<FlowRepFlowline> extract_transactional_flowlines(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds);

std::map<std::uint64_t, int> protected_endpoint_degrees(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds);

bool preserves_protected_endpoint_degrees(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds,
    const std::map<std::uint64_t, int> &requiredDegrees);

int count_closed_boundary_cycles(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds);

} // namespace flow_rep_detail

FlowRepSparseNetwork select_sparse_flow_rep_network(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<FlowRepCoverageSample> &coverageSamples = {},
    const std::vector<FlowRepCycleInput> &cycles = {},
    const FlowRepSparseOptions &options = {});

/**
 * Extend every non-authoritative open flowline endpoint along its transported
 * cross-field branch until it reaches the retained embedded network or an
 * authoritative source boundary/feature. Intersections are computed in the
 * source triangle's barycentric chart, so a nearby point on another sheet can
 * never capture an endpoint.
 */
FlowRepEndpointCompletionResult complete_flow_rep_endpoints(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField,
    const SurfaceCellTracingOptions &tracingOptions,
    std::vector<FlowRepArc> arcs,
    std::vector<int> retainedArcIds,
    const FlowRepEndpointCompletionOptions &options = {});

FlowRepOverlay make_flow_rep_overlay(
    const std::vector<FlowRepArc> &arcs, const std::vector<FlowRepStrand> &strands,
    const FlowRepSparseNetwork &network);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_FLOW_REP_STRANDS_H
