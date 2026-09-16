#pragma once

#include <cstdint>
#include <utility>
#include <variant>
#include <vector>

#include <directional/geometry/GlobalConformityPlan.h>
#include "GlobalConformityExactSolver.h"

namespace directional::geometry::global_conformity_detail {

struct NormalizedConformityProblem {
  std::vector<ConformitySpanInput> spans;
  std::vector<ConformityIncidence> incidences;
  std::vector<EInt> preferred;
  std::vector<SolverSpan> solver;
  std::vector<ConformityConstraintRowId> rows;
  std::size_t rowCount = 0U;
  std::uint64_t targetMetricDigest = 0U;
};
using NormalizedConformityProblemResult =
    std::variant<NormalizedConformityProblem, GlobalConformityPlanError>;

[[nodiscard]] NormalizedConformityProblemResult normalize_global_conformity_problem(
    const GlobalTopologyPlan &, const GlobalConformityKnownFeasibleInput &);

}  // namespace directional::geometry::global_conformity_detail
