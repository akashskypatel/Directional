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

[[nodiscard]] std::uint64_t
exact_target_metric_digest(const Eigen::VectorXd &targetSize);

[[nodiscard]] EInt exact_from_size(std::size_t value);
[[nodiscard]] std::optional<std::size_t> exact_to_size_checked(const EInt &value);

} // namespace directional::geometry::global_conformity_baseline_detail
