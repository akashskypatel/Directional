#pragma once

#include <utility>
#include <vector>

namespace directional::geometry {

struct GeneralGraphMatchingEdge {
  int first = -1;
  int second = -1;
  double cost = 0.0;
};

struct GeneralGraphMatchingResult {
  std::vector<int> mate;
  int matchedEdgeCount = 0;

  [[nodiscard]] bool perfect() const {
    return !mate.empty() && matchedEdgeCount * 2 == static_cast<int>(mate.size());
  }
};

// Deterministic Edmonds blossom maximum-cardinality matching. Edge costs do
// not change cardinality; they define stable adjacency order so geometrically
// preferable augmenting paths are selected first.
GeneralGraphMatchingResult maximum_cardinality_matching(
    int vertexCount, const std::vector<GeneralGraphMatchingEdge> &edges);

} // namespace directional::geometry
