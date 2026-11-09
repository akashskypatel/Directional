#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <set>
#include <vector>

#include <Eigen/Core>
#include <directional/geometry/GlobalConformityBaseline.h>
#include <directional/geometry/GlobalConformityPlan.h>

namespace directional::geometry::global_conformity_baseline_detail {

[[nodiscard]] std::optional<EInt> derive_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize);

// D7 preferred count (RA-216): the rounded integral of rho = 1/h along the
// span's physical path, independent of how the path is split into pieces.
// It is the scheduler's objective: derive_preferred_count_exact delegates here.
[[nodiscard]] std::optional<EInt> derive_partition_stable_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize);

// D7 runs (RA-217): the maximal straight runs that the D7 count integrates
// over. The count and breakpoint placement are both derived from them.
[[nodiscard]] std::optional<std::vector<BaselineConformityMetricRun>>
derive_partition_stable_metric_runs(const ConformitySpanInput &span,
                                    const Eigen::MatrixXd &sourceVertices,
                                    const Eigen::VectorXd &targetSize);

// D7b breakpoint `ordinal` of `count` (RA-217): runs share the ordinals by
// metric and each run spaces its share linearly in length. A single-piece
// span keeps the unreduced fraction (ordinal, count).
[[nodiscard]] std::optional<ConformityBreakpointLocation>
derive_metric_breakpoint_location(
    ConformitySpanId span, std::size_t pieceCount,
    const std::vector<BaselineConformityMetricRun> &runs, const EInt &count,
    const EInt &ordinal);

// D5 maximal Mandatory chain (RA-218): consecutive oriented A2b arcs, each
// starting at the node where the previous one ends.
struct BaselineMandatoryChain {
  std::vector<GlobalTopologyOrientedArc> arcs;
  bool operator==(const BaselineMandatoryChain &) const = default;
};

// D5 partition (RA-218): every A2b arc in exactly one chain. Two Mandatory
// arcs join at a node outside stopNodes whose rotation holds exactly those two
// arcs, when their network edges lie on one hard rail. Other arcs, and the arcs
// of a join cycle with no stop, stay single. A chain reads from its lower-id
// end; chains are ordered by first arc.
[[nodiscard]] std::optional<std::vector<BaselineMandatoryChain>>
derive_mandatory_chain_partition(
    const std::vector<GlobalTopologyArc> &arcs,
    const std::vector<GlobalTopologyNodeRotation> &rotations,
    const std::vector<FieldAlignedMandatoryEdge> &mandatoryEdges,
    const std::set<authority::NetworkNodeId> &stopNodes);

// D5 chain support (RA-218): the arcs' exact paths in chain orientation.
[[nodiscard]] std::optional<std::vector<ConformitySupportPiece>>
derive_mandatory_chain_support(const BaselineMandatoryChain &chain,
                               const std::vector<GlobalTopologyArc> &arcs);

[[nodiscard]] std::uint64_t
exact_target_metric_digest(const Eigen::VectorXd &targetSize);

[[nodiscard]] EInt exact_from_size(std::size_t value);

} // namespace directional::geometry::global_conformity_baseline_detail
