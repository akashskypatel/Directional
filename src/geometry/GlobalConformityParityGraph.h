#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

#include <directional/numerics/ENumberGMP.h>

namespace directional::geometry::global_conformity_baseline_detail {

struct ParityGraphEdge {
  std::size_t spanIndex = 0U;
  std::size_t firstVertex = 0U;
  std::size_t secondVertex = 0U;
};

struct ParityGraphProblem {
  std::size_t vertexCount = 0U;
  std::vector<ParityGraphEdge> edges;
  std::vector<bool> demand;
};

// -1 = free, 0 = forced unselected, 1 = forced selected.
using ParityFixedChoices = std::vector<std::int8_t>;

struct MinimumTJoinWorkEvidence {
  std::size_t terminalCount = 0U;
  std::size_t matchingNodeCount = 0U;
  std::size_t matchingEdgeCount = 0U;
  bool matchingExecuted = false;
  std::size_t maximumMatchingDistanceBitWidth = 0U;
};

[[nodiscard]] std::optional<EInt> minimum_t_join_cardinality(
    const ParityGraphProblem &problem, const ParityFixedChoices &fixed,
    MinimumTJoinWorkEvidence *workEvidence = nullptr);

} // namespace directional::geometry::global_conformity_baseline_detail
