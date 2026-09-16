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
#include <optional>
#include <utility>
#include <variant>
#include <vector>

#include <Eigen/Core>
#include <directional/geometry/GlobalConformityPlan.h>

namespace directional::geometry {

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
  std::uint64_t sourceDigest = 0U;
  std::uint64_t networkDigest = 0U;
  std::uint64_t cutGraphDigest = 0U;
  std::uint64_t topologyPlanDigest = 0U;
  std::uint64_t targetMetricDigest = 0U;
  std::uint64_t normalizedProblemDigest = 0U;

  bool operator==(const GlobalConformityBaselineCertificate &) const = default;
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
  [[nodiscard]] GlobalConformityBaselineValidationCandidate
  validation_candidate() const;

private:
  friend GlobalConformityBaselineBuildResult build_global_conformity_baseline(
      const GlobalTopologyPlan &, const GlobalConformityBaselineInput &);

  GlobalConformityBaselinePlan(
      std::vector<ConformityScheduleEntry> schedule,
      std::vector<BaselineConformityIncidence> incidences,
      GlobalConformityBaselineCertificate certificate,
      std::uint64_t semanticDigest)
      : schedule_(std::move(schedule)), incidences_(std::move(incidences)),
        certificate_(std::move(certificate)), semanticDigest_(semanticDigest) {}

  std::vector<ConformityScheduleEntry> schedule_;
  std::vector<BaselineConformityIncidence> incidences_;
  GlobalConformityBaselineCertificate certificate_;
  std::uint64_t semanticDigest_ = 0U;
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

[[nodiscard]] std::optional<GlobalConformityPlanError>
validate_global_conformity_baseline_candidate(
    const GlobalTopologyPlan &topology,
    const GlobalConformityBaselineInput &input,
    const GlobalConformityBaselineValidationCandidate &candidate);

[[nodiscard]] GlobalConformityBaselineBuildResult
validate_global_conformity_baseline(const GlobalTopologyPlan &topology,
                                    const GlobalConformityBaselineInput &input,
                                    const GlobalConformityBaselinePlan &plan);

} // namespace directional::geometry

#endif
