#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

#include <Eigen/Core>
#include <directional/geometry/GlobalConformityPlan.h>

namespace directional::geometry::global_conformity_baseline_detail {

[[nodiscard]] std::optional<EInt> derive_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize);

// D7 preferred count (RA-216): the rounded integral of rho = 1/h along the
// span's physical path, independent of how the path is split into pieces.
// Not yet the scheduler's objective; derive_preferred_count_exact still is.
[[nodiscard]] std::optional<EInt> derive_partition_stable_preferred_count_exact(
    const ConformitySpanInput &span, const Eigen::MatrixXd &sourceVertices,
    const Eigen::VectorXd &targetSize);

[[nodiscard]] std::uint64_t
exact_target_metric_digest(const Eigen::VectorXd &targetSize);

[[nodiscard]] EInt exact_from_size(std::size_t value);
[[nodiscard]] std::optional<std::size_t> exact_to_size_checked(const EInt &value);

} // namespace directional::geometry::global_conformity_baseline_detail
