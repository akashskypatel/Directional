#include <directional/geometry/GeneralGraphMatching.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>
#include <tuple>

namespace directional::geometry {
namespace {

class BlossomMatcher {
public:
  BlossomMatcher(const int vertexCount,
                 const std::vector<GeneralGraphMatchingEdge> &edges)
      : graph_(static_cast<std::size_t>(vertexCount)),
        mate_(static_cast<std::size_t>(vertexCount), -1),
        parent_(static_cast<std::size_t>(vertexCount), -1),
        base_(static_cast<std::size_t>(vertexCount)),
        used_(static_cast<std::size_t>(vertexCount), false),
        blossom_(static_cast<std::size_t>(vertexCount), false) {
    struct Neighbor {
      int vertex = -1;
      double cost = 0.0;
    };
    std::vector<std::vector<Neighbor>> ordered(
        static_cast<std::size_t>(vertexCount));
    for (const GeneralGraphMatchingEdge &edge : edges) {
      if (edge.first < 0 || edge.second < 0 || edge.first >= vertexCount ||
          edge.second >= vertexCount || edge.first == edge.second ||
          !std::isfinite(edge.cost)) {
        continue;
      }
      ordered[static_cast<std::size_t>(edge.first)].push_back(
          {edge.second, edge.cost});
      ordered[static_cast<std::size_t>(edge.second)].push_back(
          {edge.first, edge.cost});
    }
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      auto &neighbors = ordered[static_cast<std::size_t>(vertex)];
      std::sort(neighbors.begin(), neighbors.end(),
                [](const Neighbor &lhs, const Neighbor &rhs) {
                  return std::tie(lhs.cost, lhs.vertex) <
                         std::tie(rhs.cost, rhs.vertex);
                });
      neighbors.erase(
          std::unique(neighbors.begin(), neighbors.end(),
                      [](const Neighbor &lhs, const Neighbor &rhs) {
                        return lhs.vertex == rhs.vertex;
                      }),
          neighbors.end());
      graph_[static_cast<std::size_t>(vertex)].reserve(neighbors.size());
      for (const Neighbor &neighbor : neighbors) {
        graph_[static_cast<std::size_t>(vertex)].push_back(neighbor.vertex);
      }
    }
  }

  GeneralGraphMatchingResult solve() {
    for (int vertex = 0; vertex < static_cast<int>(graph_.size()); ++vertex) {
      if (mate_[static_cast<std::size_t>(vertex)] < 0) {
        augment_from(vertex);
      }
    }
    GeneralGraphMatchingResult result;
    result.mate = mate_;
    result.matchedEdgeCount = static_cast<int>(std::count_if(
                                  mate_.begin(), mate_.end(),
                                  [](const int mate) { return mate >= 0; })) /
                              2;
    return result;
  }

private:
  int least_common_ancestor(int first, int second) {
    std::vector<bool> path(graph_.size(), false);
    while (true) {
      first = base_[static_cast<std::size_t>(first)];
      path[static_cast<std::size_t>(first)] = true;
      const int mate = mate_[static_cast<std::size_t>(first)];
      if (mate < 0) {
        break;
      }
      first = parent_[static_cast<std::size_t>(mate)];
    }
    while (true) {
      second = base_[static_cast<std::size_t>(second)];
      if (path[static_cast<std::size_t>(second)]) {
        return second;
      }
      const int mate = mate_[static_cast<std::size_t>(second)];
      if (mate < 0) {
        return second;
      }
      second = parent_[static_cast<std::size_t>(mate)];
    }
  }

  void mark_blossom_path(int vertex, const int blossomBase, int child) {
    while (base_[static_cast<std::size_t>(vertex)] != blossomBase) {
      const int mate = mate_[static_cast<std::size_t>(vertex)];
      blossom_[static_cast<std::size_t>(base_[static_cast<std::size_t>(vertex)])] =
          true;
      blossom_[static_cast<std::size_t>(base_[static_cast<std::size_t>(mate)])] =
          true;
      parent_[static_cast<std::size_t>(vertex)] = child;
      child = mate;
      vertex = parent_[static_cast<std::size_t>(mate)];
    }
  }

  bool augment_from(const int root) {
    std::fill(used_.begin(), used_.end(), false);
    std::fill(parent_.begin(), parent_.end(), -1);
    std::iota(base_.begin(), base_.end(), 0);

    std::queue<int> queue;
    queue.push(root);
    used_[static_cast<std::size_t>(root)] = true;

    while (!queue.empty()) {
      const int vertex = queue.front();
      queue.pop();
      for (const int neighbor : graph_[static_cast<std::size_t>(vertex)]) {
        if (base_[static_cast<std::size_t>(vertex)] ==
                base_[static_cast<std::size_t>(neighbor)] ||
            mate_[static_cast<std::size_t>(vertex)] == neighbor) {
          continue;
        }

        const int neighborMate = mate_[static_cast<std::size_t>(neighbor)];
        if (neighbor == root ||
            (neighborMate >= 0 &&
             parent_[static_cast<std::size_t>(neighborMate)] >= 0)) {
          const int blossomBase = least_common_ancestor(vertex, neighbor);
          std::fill(blossom_.begin(), blossom_.end(), false);
          mark_blossom_path(vertex, blossomBase, neighbor);
          mark_blossom_path(neighbor, blossomBase, vertex);
          for (int candidate = 0; candidate < static_cast<int>(graph_.size());
               ++candidate) {
            if (!blossom_[static_cast<std::size_t>(
                    base_[static_cast<std::size_t>(candidate)])]) {
              continue;
            }
            base_[static_cast<std::size_t>(candidate)] = blossomBase;
            if (!used_[static_cast<std::size_t>(candidate)]) {
              used_[static_cast<std::size_t>(candidate)] = true;
              queue.push(candidate);
            }
          }
          continue;
        }

        if (parent_[static_cast<std::size_t>(neighbor)] >= 0) {
          continue;
        }
        parent_[static_cast<std::size_t>(neighbor)] = vertex;
        if (neighborMate < 0) {
          int current = neighbor;
          while (current >= 0) {
            const int previous = parent_[static_cast<std::size_t>(current)];
            const int next = previous >= 0
                                 ? mate_[static_cast<std::size_t>(previous)]
                                 : -1;
            mate_[static_cast<std::size_t>(current)] = previous;
            if (previous >= 0) {
              mate_[static_cast<std::size_t>(previous)] = current;
            }
            current = next;
          }
          return true;
        }
        used_[static_cast<std::size_t>(neighborMate)] = true;
        queue.push(neighborMate);
      }
    }
    return false;
  }

  std::vector<std::vector<int>> graph_;
  std::vector<int> mate_;
  std::vector<int> parent_;
  std::vector<int> base_;
  std::vector<bool> used_;
  std::vector<bool> blossom_;
};

} // namespace

GeneralGraphMatchingResult maximum_cardinality_matching(
    const int vertexCount,
    const std::vector<GeneralGraphMatchingEdge> &edges) {
  if (vertexCount <= 0) {
    return {};
  }
  return BlossomMatcher(vertexCount, edges).solve();
}

} // namespace directional::geometry
