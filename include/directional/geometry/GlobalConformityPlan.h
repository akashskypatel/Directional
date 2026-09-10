// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once
#ifndef DIRECTIONAL_GEOMETRY_GLOBAL_CONFORMITY_PLAN_H
#define DIRECTIONAL_GEOMETRY_GLOBAL_CONFORMITY_PLAN_H

#include <array>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include <Eigen/Core>
#include <directional/authority/AuthorityIds.h>
#include <directional/authority/FieldTransportAtlas.h>
#include <directional/authority/SourceSupport.h>
#include <directional/geometry/GlobalTopologyPlan.h>
#include <directional/numerics/ENumberGMP.h>

namespace directional::geometry {

class ConformitySpanId {
public:
  ConformitySpanId() = delete;
  [[nodiscard]] static ConformitySpanId from_network_arc(authority::NetworkArcId arc) noexcept { return ConformitySpanId(arc); }
  [[nodiscard]] authority::NetworkArcId network_arc() const noexcept { return arc_; }
  auto operator<=>(const ConformitySpanId &) const = default;
private:
  explicit ConformitySpanId(authority::NetworkArcId arc) noexcept : arc_(arc) {}
  authority::NetworkArcId arc_;
};

struct ConformityBoundaryIncidenceId {
  authority::NetworkRegionId region;
  std::size_t canonicalBoundaryOccurrenceOrdinal = 0U;
  auto operator<=>(const ConformityBoundaryIncidenceId &) const = default;
};
enum class ConformityFamily : std::uint8_t { U = 0, V = 1 };
enum class ConformitySign : std::int8_t { Negative = -1, Positive = 1 };

struct ConformityEdgePoint { authority::SourceEdgeTopologyKey edge; authority::FieldExactRational parameter; auto operator<=>(const ConformityEdgePoint &) const = default; };
struct ConformityFacePoint { authority::SourceFaceTopologyKey face; std::array<authority::FieldExactRational, 3> barycentric; auto operator<=>(const ConformityFacePoint &) const = default; };
using ConformitySourcePoint = std::variant<authority::SourceVertexId, ConformityEdgePoint, ConformityFacePoint>;
struct ConformitySupportPiece { authority::SourceSupport carrier; ConformitySourcePoint first; ConformitySourcePoint second; auto operator<=>(const ConformitySupportPiece &) const = default; };
struct ConformitySpanInput { ConformitySpanId id; std::vector<ConformitySupportPiece> supportPieces; auto operator<=>(const ConformitySpanInput &) const = default; };
struct ConformityIncidence {
  ConformityBoundaryIncidenceId id;
  ConformitySpanId span;
  ConformityFamily family = ConformityFamily::U;
  ConformitySign sign = ConformitySign::Positive;
  authority::Orientation orientation = authority::Orientation::Forward;
  auto operator<=>(const ConformityIncidence &) const = default;
};
struct GlobalConformityKnownFeasibleInput { Eigen::MatrixXd sourceVertices; Eigen::VectorXd targetSize; std::vector<ConformitySpanInput> spans; std::vector<ConformityIncidence> incidences; };
struct GlobalConformityInput { Eigen::MatrixXd sourceVertices; Eigen::VectorXd targetSize; std::vector<ConformitySpanInput> spans; std::vector<ConformityIncidence> incidences; };
struct ConformityConstraintRowId { authority::NetworkRegionId region; ConformityFamily family=ConformityFamily::U; auto operator<=>(const ConformityConstraintRowId &) const = default; };
struct ConformityBreakpointId { ConformitySpanId span; EInt exactOrdinal; friend bool operator==(const ConformityBreakpointId &a, const ConformityBreakpointId &b) { return a.span == b.span && a.exactOrdinal == b.exactOrdinal; } };
struct ConformityBreakpointLocation { ConformityBreakpointId id; std::size_t supportPieceIndex = 0U; EInt localNumerator; EInt localDenominator; bool firstEndpoint = false; bool lastEndpoint = false; };
struct ConformityScheduleEntry { ConformitySpanId span; EInt preferredCount; EInt count; std::vector<ConformitySupportPiece> supportPieces; };
struct ConformityObjectiveValue { EInt primaryDeviation; std::vector<EInt> canonicalCounts; EInt scalarValue; };
struct ConformityRefinementEvidence { ConformityObjectiveValue before; ConformityObjectiveValue after; std::size_t biMcfEdgeCount=0U,bMatchingNodeCount=0U,bMatchingEdgeCount=0U,wpmNodeCount=0U,wpmEdgeCount=0U; };
struct GlobalConformityWorkLedger {
  std::string algorithmIdentity = "HeistermannWarnettBommes2023ExactBiMDFRefinementM2";
  std::string assuranceClass = "FiniteExactConvergence(Corollary3.7+Theorem3.8+Corollary3.9,M=2)";
  std::string matchingPrimitiveIdentity = "LEMON-1.3.1-MaxWeightedPerfectMatching-exact-EInt-adapter";
  std::string matchingPrimitiveRevision = "seqan/lemon@813c63d4f1d603858d941ac6f04abbe57901996a";
  std::size_t semanticRowCount=0U, semanticSpanCount=0U, initializerNodeCount=0U, initializerArcCount=0U;
  bool initializerExactFeasibilityValidated=false;
  int refinementM=2;
  std::size_t refinementCount=0U, peakMatchingNodeCount=0U, peakMatchingEdgeCount=0U;
  std::size_t hBitWidth=0U,uBitWidth=0U,qBitWidth=0U,lBitWidth=0U;
  std::size_t maximumTargetBitWidth=0U,maximumCountBitWidth=0U,maximumCapacityBitWidth=0U,maximumCostBitWidth=0U;
  std::size_t maximumObservedExactIntegerBitWidth=0U;
  bool terminalExactNonImprovementValidated=false;
  EInt terminalRefinementCostChange;
  std::size_t retryResetCount=0U;
  std::vector<ConformityRefinementEvidence> refinements;
};

struct ConformityWpmEdgeWitness { std::size_t first=0U,second=0U; EInt weight; bool matched=false; };
struct ConformityWpmBlossomWitness { EInt dualValue; std::vector<std::size_t> nodes; };
struct ConformityTerminalRefinementWitness {
  int refinementM=2;
  std::vector<EInt> terminalCounts;
  std::size_t biMcfEdgeCount=0U,bMatchingNodeCount=0U,bMatchingEdgeCount=0U,wpmNodeCount=0U;
  std::vector<ConformityWpmEdgeWitness> wpmEdges;
  std::vector<EInt> nodeDualValues;
  std::vector<ConformityWpmBlossomWitness> blossoms;
  EInt matchingPrimalWeight,matchingDualValue,semanticCostChange;
  int matchingDualScale=4;
  std::uint64_t terminalProblemDigest=0U;
};
struct ConformityRowCertificate { ConformityConstraintRowId row; EInt signedBalance,unsignedBoundaryCount; bool parityEven=false; };
struct ConformityOptimalityTheoremEvidence {
  std::string theoremIdentity = "HeistermannWarnettBommes2023-Theorem3.8-fixed-M2";
  int refinementM=2;
  bool exactIntegralProblem=false;
  bool terminalZeroDemand=false;
  bool perfectMatchingOptimalityCertified=false;
};
struct GlobalConformityCertificate {
  std::size_t componentOrdinal=0U;
  std::vector<ConformitySpanId> spans;
  std::vector<ConformityBoundaryIncidenceId> incidenceIds;
  std::vector<ConformityScheduleEntry> schedule;
  std::vector<ConformityIncidence> incidences;
  std::vector<ConformityRowCertificate> rows;
  ConformityObjectiveValue objective;
  GlobalConformityWorkLedger workLedger;
  EInt finiteCapU,radixQ,lexicographicScaleL;
  ConformityTerminalRefinementWitness terminalWitness;
  ConformityOptimalityTheoremEvidence theoremEvidence;
  std::uint64_t sourceDigest=0U,networkDigest=0U,cutGraphDigest=0U,topologyPlanDigest=0U,targetMetricDigest=0U,normalizedProblemDigest=0U;
};
enum class ConformityInfeasibilityReason : std::uint8_t { BalanceCut=0,PositivityCut=1,ParityCut=2 };
struct ConformityInfeasibilityWitness {
  std::vector<std::size_t> rowOrdinals;
  std::size_t doubleCoverNodeCount=0U;
  std::vector<std::size_t> reachableDoubleCoverNodes;
  EInt requiredFlow,achievedFlow,cutCapacity;
};
struct ConformityInfeasibleSubset {
  std::size_t componentOrdinal=0U;
  std::vector<authority::NetworkRegionId> regions;
  std::vector<ConformitySpanId> spans;
  std::vector<ConformityBoundaryIncidenceId> incidenceIds;
  ConformityInfeasibilityReason reason=ConformityInfeasibilityReason::BalanceCut;
  ConformityInfeasibilityWitness witness;
  std::uint64_t sourceDigest=0U,networkDigest=0U,cutGraphDigest=0U,topologyPlanDigest=0U,targetMetricDigest=0U,normalizedProblemDigest=0U;
};

struct GlobalConformityPlanValidationCandidate {
  std::vector<ConformityScheduleEntry> schedule;
  std::vector<ConformityIncidence> incidences;
  ConformityObjectiveValue objective;
  GlobalConformityWorkLedger workLedger;
  EInt finiteCapU, radixQ, lexicographicScaleL;
  std::uint64_t sourceDigest=0U, networkDigest=0U, cutGraphDigest=0U, topologyPlanDigest=0U, targetMetricDigest=0U, semanticDigest=0U;
};

enum class GlobalConformityPlanErrorCode : std::uint8_t { InvalidSourceBinding=0,InvalidTopologyBinding=1,InvalidTargetMetric=2,DuplicateConformitySpan=3,InvalidBoundaryIncidence=4,DegenerateConformityPath=5,InvalidSourcePoint=6,UnsupportedIncidenceDegree=7,KnownFeasibleInitializationFailed=8,ExactMatchingFailed=9,ExactValidationFailed=10 };
struct GlobalConformityPlanError { GlobalConformityPlanErrorCode code=GlobalConformityPlanErrorCode::InvalidTopologyBinding; std::optional<ConformitySpanId> span; std::optional<ConformityBoundaryIncidenceId> incidence; std::string detail; };
class GlobalConformityPlanBuildResult;

class GlobalConformityPlan {
public:
  [[nodiscard]] static GlobalConformityPlanBuildResult make_known_feasible(const GlobalTopologyPlan&, const GlobalConformityKnownFeasibleInput&);
  [[nodiscard]] const std::vector<ConformityScheduleEntry>& schedule() const noexcept { return schedule_; }
  [[nodiscard]] const std::vector<ConformityIncidence>& incidences() const noexcept { return incidences_; }
  [[nodiscard]] const ConformityObjectiveValue& objective() const noexcept { return objective_; }
  [[nodiscard]] const GlobalConformityWorkLedger& work_ledger() const noexcept { return workLedger_; }
  [[nodiscard]] const EInt& finite_cap_u() const noexcept { return finiteCapU_; }
  [[nodiscard]] const EInt& radix_q() const noexcept { return radixQ_; }
  [[nodiscard]] const EInt& lexicographic_scale_l() const noexcept { return lexicographicScaleL_; }
  [[nodiscard]] std::uint64_t source_digest() const noexcept { return sourceDigest_; }
  [[nodiscard]] std::uint64_t network_digest() const noexcept { return networkDigest_; }
  [[nodiscard]] std::uint64_t cut_graph_digest() const noexcept { return cutGraphDigest_; }
  [[nodiscard]] std::uint64_t topology_plan_digest() const noexcept { return topologyPlanDigest_; }
  [[nodiscard]] std::uint64_t target_metric_digest() const noexcept { return targetMetricDigest_; }
  [[nodiscard]] std::uint64_t semantic_digest() const noexcept { return semanticDigest_; }
  [[nodiscard]] const ConformityScheduleEntry* find_schedule(ConformitySpanId) const noexcept;
  [[nodiscard]] std::optional<ConformityBreakpointLocation> breakpoint_location(ConformitySpanId,const EInt&) const;
  [[nodiscard]] GlobalConformityPlanValidationCandidate validation_candidate() const;
private:
  friend class GlobalConformityPlanBuildResult;
  GlobalConformityPlan(std::vector<ConformityScheduleEntry> schedule,std::vector<ConformityIncidence> incidences,ConformityObjectiveValue objective,GlobalConformityWorkLedger ledger,EInt finiteCapU,EInt radixQ,EInt lexicographicScaleL,std::uint64_t sourceDigest,std::uint64_t networkDigest,std::uint64_t cutGraphDigest,std::uint64_t topologyPlanDigest,std::uint64_t targetMetricDigest,std::uint64_t semanticDigest)
    : schedule_(std::move(schedule)),incidences_(std::move(incidences)),objective_(std::move(objective)),workLedger_(std::move(ledger)),finiteCapU_(std::move(finiteCapU)),radixQ_(std::move(radixQ)),lexicographicScaleL_(std::move(lexicographicScaleL)),sourceDigest_(sourceDigest),networkDigest_(networkDigest),cutGraphDigest_(cutGraphDigest),topologyPlanDigest_(topologyPlanDigest),targetMetricDigest_(targetMetricDigest),semanticDigest_(semanticDigest) {}
  std::vector<ConformityScheduleEntry> schedule_; std::vector<ConformityIncidence> incidences_; ConformityObjectiveValue objective_; GlobalConformityWorkLedger workLedger_; EInt finiteCapU_,radixQ_,lexicographicScaleL_; std::uint64_t sourceDigest_=0U,networkDigest_=0U,cutGraphDigest_=0U,topologyPlanDigest_=0U,targetMetricDigest_=0U,semanticDigest_=0U;
};

class GlobalConformityPlanBuildResult {
public:
  explicit GlobalConformityPlanBuildResult(GlobalConformityPlan p):state_(std::move(p)){}
  explicit GlobalConformityPlanBuildResult(GlobalConformityPlanError e):state_(std::move(e)){}
  [[nodiscard]] bool has_value()const noexcept{return std::holds_alternative<GlobalConformityPlan>(state_);} explicit operator bool()const noexcept{return has_value();}
  [[nodiscard]] const GlobalConformityPlan& value()const{return std::get<GlobalConformityPlan>(state_);} [[nodiscard]] GlobalConformityPlan& value(){return std::get<GlobalConformityPlan>(state_);} [[nodiscard]] const GlobalConformityPlanError& error()const{return std::get<GlobalConformityPlanError>(state_);}
private: std::variant<GlobalConformityPlan,GlobalConformityPlanError> state_;
};

struct GlobalConformityOutcome {
  std::vector<GlobalConformityCertificate> scheduledComponents;
  std::vector<ConformityInfeasibleSubset> infeasibleSubsets;
  std::optional<GlobalConformityPlan> feasiblePlan;
  std::uint64_t sourceDigest=0U,networkDigest=0U,cutGraphDigest=0U,topologyPlanDigest=0U,targetMetricDigest=0U,normalizedProblemDigest=0U,semanticDigest=0U;
};
class GlobalConformityOutcomeBuildResult {
public:
  explicit GlobalConformityOutcomeBuildResult(GlobalConformityOutcome o):state_(std::move(o)){}
  explicit GlobalConformityOutcomeBuildResult(GlobalConformityPlanError e):state_(std::move(e)){}
  [[nodiscard]] bool has_value()const noexcept{return std::holds_alternative<GlobalConformityOutcome>(state_);} explicit operator bool()const noexcept{return has_value();}
  [[nodiscard]] const GlobalConformityOutcome& value()const{return std::get<GlobalConformityOutcome>(state_);} [[nodiscard]] GlobalConformityOutcome& value(){return std::get<GlobalConformityOutcome>(state_);} [[nodiscard]] const GlobalConformityPlanError& error()const{return std::get<GlobalConformityPlanError>(state_);}
private: std::variant<GlobalConformityOutcome,GlobalConformityPlanError> state_;
};

[[nodiscard]] GlobalConformityOutcomeBuildResult build_global_conformity_outcome(const GlobalTopologyPlan&,const GlobalConformityInput&);
[[nodiscard]] std::optional<GlobalConformityPlanError> validate_global_conformity_outcome(const GlobalTopologyPlan&,const GlobalConformityInput&,const GlobalConformityOutcome&);
[[nodiscard]] const char* global_conformity_infeasibility_reason_name(ConformityInfeasibilityReason) noexcept;
[[nodiscard]] GlobalConformityPlanBuildResult validate_global_conformity_plan(const GlobalTopologyPlan&,const GlobalConformityKnownFeasibleInput&,const GlobalConformityPlan&);
[[nodiscard]] std::optional<GlobalConformityPlanError> validate_global_conformity_candidate(const GlobalTopologyPlan&,const GlobalConformityKnownFeasibleInput&,const GlobalConformityPlanValidationCandidate&);
[[nodiscard]] const char* global_conformity_plan_error_code_name(GlobalConformityPlanErrorCode) noexcept;

} // namespace directional::geometry
#endif
