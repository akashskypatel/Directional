#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
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

[[nodiscard]] std::uint64_t
exact_target_metric_digest(const Eigen::VectorXd &targetSize);

[[nodiscard]] EInt exact_from_size(std::size_t value);
[[nodiscard]] std::optional<std::size_t> exact_to_size_checked(const EInt &value);

} // namespace directional::geometry::global_conformity_baseline_detail
