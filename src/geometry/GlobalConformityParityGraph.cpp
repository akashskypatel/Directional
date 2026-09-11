#include "GlobalConformityParityGraph.h"
#include "GlobalConformityExactWeight.h"

#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

#include <lemon/list_graph.h>
#include <lemon/matching.h>

namespace directional::geometry::global_conformity_baseline_detail {
namespace {

EInt exact_from_size(std::size_t value) {
  EInt out(0);
  for (int bit = static_cast<int>(sizeof(std::size_t) * 8U) - 1; bit >= 0;
       --bit) {
    out *= EInt(2);
    if (((value >> static_cast<unsigned>(bit)) & std::size_t{1}) != 0U) {
      out += EInt(1);
    }
  }
  return out;
}

} // namespace

std::optional<EInt> minimum_t_join_cardinality(
    const ParityGraphProblem &problem, const ParityFixedChoices &fixed) {
  if (problem.vertexCount == 0U || problem.demand.size() != problem.vertexCount) {
    return std::nullopt;
  }

  std::size_t spanCount = 0U;
  for (const auto &edge : problem.edges) {
    if (edge.firstVertex >= problem.vertexCount ||
        edge.secondVertex >= problem.vertexCount) {
      return std::nullopt;
    }
    spanCount = std::max(spanCount, edge.spanIndex + 1U);
  }
  if (fixed.size() != spanCount) return std::nullopt;

  std::vector<bool> remainingDemand = problem.demand;
  EInt forcedCount(0);
  std::vector<std::vector<std::size_t>> adjacency(problem.vertexCount);

  for (const auto &edge : problem.edges) {
    const auto choice = fixed[edge.spanIndex];
    if (choice < -1 || choice > 1) return std::nullopt;
    if (choice == 1) {
      forcedCount += EInt(1);
      if (edge.firstVertex != edge.secondVertex) {
        remainingDemand[edge.firstVertex] = !remainingDemand[edge.firstVertex];
        remainingDemand[edge.secondVertex] = !remainingDemand[edge.secondVertex];
      }
      continue;
    }
    if (choice == 0 || edge.firstVertex == edge.secondVertex) continue;
    adjacency[edge.firstVertex].push_back(edge.secondVertex);
    adjacency[edge.secondVertex].push_back(edge.firstVertex);
  }

  std::vector<std::size_t> terminals;
  for (std::size_t vertex = 0U; vertex < problem.vertexCount; ++vertex) {
    if (remainingDemand[vertex]) terminals.push_back(vertex);
  }
  if ((terminals.size() & 1U) != 0U) return std::nullopt;
  if (terminals.empty()) return forcedCount;

  lemon::ListGraph matchingGraph;
  std::vector<lemon::ListGraph::Node> nodes;
  nodes.reserve(terminals.size());
  for (std::size_t index = 0U; index < terminals.size(); ++index) {
    nodes.push_back(matchingGraph.addNode());
  }
  lemon::ListGraph::EdgeMap<global_conformity_detail::ExactWeight> weights(
      matchingGraph);
  lemon::ListGraph::EdgeMap<std::size_t> distances(
      matchingGraph, std::numeric_limits<std::size_t>::max());

  constexpr std::size_t kUnreached = std::numeric_limits<std::size_t>::max();
  for (std::size_t sourceOrdinal = 0U; sourceOrdinal < terminals.size();
       ++sourceOrdinal) {
    std::vector<std::size_t> distance(problem.vertexCount, kUnreached);
    std::queue<std::size_t> queue;
    const auto source = terminals[sourceOrdinal];
    distance[source] = 0U;
    queue.push(source);
    while (!queue.empty()) {
      const auto current = queue.front();
      queue.pop();
      for (const auto next : adjacency[current]) {
        if (distance[next] != kUnreached) continue;
        distance[next] = distance[current] + 1U;
        queue.push(next);
      }
    }
    for (std::size_t targetOrdinal = sourceOrdinal + 1U;
         targetOrdinal < terminals.size(); ++targetOrdinal) {
      const auto d = distance[terminals[targetOrdinal]];
      if (d == kUnreached) continue;
      const auto edge = matchingGraph.addEdge(nodes[sourceOrdinal],
                                              nodes[targetOrdinal]);
      weights[edge] = global_conformity_detail::ExactWeight(-exact_from_size(d));
      distances[edge] = d;
    }
  }

  using Matching = lemon::MaxWeightedPerfectMatching<
      lemon::ListGraph,
      lemon::ListGraph::EdgeMap<global_conformity_detail::ExactWeight>>;
  Matching matching(matchingGraph, weights);
  if (!matching.run()) return std::nullopt;

  EInt freeCount(0);
  for (lemon::ListGraph::EdgeIt edge(matchingGraph); edge != lemon::INVALID;
       ++edge) {
    if (!matching.matching(edge)) continue;
    const auto d = distances[edge];
    if (d == kUnreached) return std::nullopt;
    freeCount += exact_from_size(d);
  }
  return forcedCount + freeCount;
}

} // namespace directional::geometry::global_conformity_baseline_detail
