// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_RELIEF_TOPOLOGY_H
#define DIRECTIONAL_GEOMETRY_RELIEF_TOPOLOGY_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/geometry/AdaptiveTargetSize.h>

namespace directional::geometry {

enum class ReliefCriticalType : int {
  Regular = 0,
  Minimum = 1,
  Maximum = 2,
  Saddle = 3,
};

struct ReliefOptions {
  double featureWeight = 1.0;
  double curvatureWeight = 0.5;
  double densityWeight = 0.5;
  double thicknessWeight = 0.25;
  double patchEnergyWeight = 0.5;
  double baseSize = 1.0;
  double thicknessEpsilon = 1.0e-12;
  double persistenceThreshold = 0.0;
};

struct ReliefInput {
  Eigen::VectorXd salience;
  Eigen::VectorXd curvature;
  Eigen::VectorXd density;
  Eigen::VectorXd thickness;
  Eigen::VectorXd patchEnergy;
};

struct ReliefCriticalPoint {
  int vertex = -1;
  ReliefCriticalType type = ReliefCriticalType::Regular;
  int lowerComponents = 0;
  int upperComponents = 0;
  int multiplicity = 0;
  bool retained = true;
};

struct ReliefPersistencePair {
  int extremum = -1;
  int saddle = -1;
  bool minimumPair = true;
  double persistence = 0.0;
  bool canceled = false;
};

struct ReliefBranch {
  int saddle = -1;
  int extremum = -1;
  bool ascending = true;
  std::vector<int> vertices;
};

struct ReliefTopologyResult {
  Eigen::VectorXd relief;
  Eigen::VectorXi watershedLabels;
  std::vector<int> watershedRoots;
  std::vector<ReliefCriticalPoint> criticalPoints;
  std::vector<ReliefPersistencePair> persistencePairs;
  std::vector<ReliefBranch> branches;
};

struct ReliefRootSelectionOptions {
  double maximumNormalizedDistance = 1.0;
  std::vector<int> featureJunctions;
  std::vector<int> singularities;
  std::vector<int> skeletonAnchors;
  std::set<std::uint64_t> hardBarrierEdges;
};

struct ReliefRootSelectionResult {
  std::vector<int> roots;
  Eigen::VectorXi labels;
  Eigen::MatrixXd targets;
};

namespace relief_topology_detail {

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
std::uint64_t edge_key(const int a, const int b) {
  const auto lo = static_cast<std::uint32_t>(std::min(a, b));
  const auto hi = static_cast<std::uint32_t>(std::max(a, b));
  return (static_cast<std::uint64_t>(lo) << 32u) | hi;
}
#else
std::uint64_t edge_key(const int a, const int b);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
bool symbolic_less(const Eigen::VectorXd &relief, const int a,
                          const int b) {
  if (relief[a] != relief[b]) {
    return relief[a] < relief[b];
  }
  return a < b;
}
#else
bool symbolic_less(const Eigen::VectorXd &relief, const int a,
                          const int b);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex) {
  return {vertices(vertex, 0), vertices(vertex, 1), vertices(vertex, 2)};
}
#else
Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
std::vector<std::vector<int>>
vertex_neighbors_from_faces(const int vertexCount, const Eigen::MatrixXi &faces) {
  std::vector<std::set<int>> sets(static_cast<std::size_t>(vertexCount));
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      if (a < 0 || b < 0 || a >= vertexCount || b >= vertexCount || a == b) {
        continue;
      }
      sets[static_cast<std::size_t>(a)].insert(b);
      sets[static_cast<std::size_t>(b)].insert(a);
    }
  }
  std::vector<std::vector<int>> result(static_cast<std::size_t>(vertexCount));
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    result[static_cast<std::size_t>(vertex)].assign(
        sets[static_cast<std::size_t>(vertex)].begin(),
        sets[static_cast<std::size_t>(vertex)].end());
  }
  return result;
}
#else
std::vector<std::vector<int>>
vertex_neighbors_from_faces(const int vertexCount, const Eigen::MatrixXi &faces);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
std::map<int, std::set<int>>
link_adjacency(const Eigen::MatrixXi &faces, const int center) {
  std::map<int, std::set<int>> adjacency;
  for (int face = 0; face < faces.rows(); ++face) {
    int local = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (faces(face, corner) == center) {
        local = corner;
        break;
      }
    }
    if (local < 0) {
      continue;
    }
    const int a = faces(face, (local + 1) % 3);
    const int b = faces(face, (local + 2) % 3);
    adjacency[a].insert(b);
    adjacency[b].insert(a);
  }
  return adjacency;
}
#else
std::map<int, std::set<int>>
link_adjacency(const Eigen::MatrixXi &faces, const int center);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
int count_restricted_components(const std::map<int, std::set<int>> &graph,
                                       const std::set<int> &enabled) {
  if (enabled.empty()) {
    return 0;
  }
  std::set<int> visited;
  int components = 0;
  for (const int seed : enabled) {
    if (visited.count(seed) != 0) {
      continue;
    }
    ++components;
    std::vector<int> stack{seed};
    visited.insert(seed);
    while (!stack.empty()) {
      const int vertex = stack.back();
      stack.pop_back();
      const auto found = graph.find(vertex);
      if (found == graph.end()) {
        continue;
      }
      for (const int next : found->second) {
        if (enabled.count(next) != 0 && visited.insert(next).second) {
          stack.push_back(next);
        }
      }
    }
  }
  return components;
}
#else
int count_restricted_components(const std::map<int, std::set<int>> &graph,
                                       const std::set<int> &enabled);
#endif

class UnionFind {
public:
  explicit UnionFind(const int count) : parent_(static_cast<std::size_t>(count)),
                                        rank_(static_cast<std::size_t>(count), 0) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  int find(const int value) {
    int root = value;
    while (parent_[static_cast<std::size_t>(root)] != root) {
      root = parent_[static_cast<std::size_t>(root)];
    }
    int current = value;
    while (parent_[static_cast<std::size_t>(current)] != current) {
      const int next = parent_[static_cast<std::size_t>(current)];
      parent_[static_cast<std::size_t>(current)] = root;
      current = next;
    }
    return root;
  }

  int unite_keep(const int a, const int b, const int keep) {
    const int rootA = find(a);
    const int rootB = find(b);
    if (rootA == rootB) {
      return rootA;
    }
    const int drop = rootA == keep ? rootB : rootA;
    parent_[static_cast<std::size_t>(drop)] = keep;
    rank_[static_cast<std::size_t>(keep)] =
        std::max(rank_[static_cast<std::size_t>(keep)],
                 static_cast<unsigned char>(rank_[static_cast<std::size_t>(drop)] + 1));
    return keep;
  }

private:
  std::vector<int> parent_;
  std::vector<unsigned char> rank_;
};

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
void append_unique_sorted(std::vector<int> &values, const int value,
                                 const int vertexCount) {
  if (value >= 0 && value < vertexCount) {
    values.push_back(value);
  }
}
#else
void append_unique_sorted(std::vector<int> &values, const int value,
                                 const int vertexCount);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
Eigen::VectorXd zero_or_validate(const Eigen::VectorXd &values,
                                        const int count, const char *name) {
  if (values.size() == 0) {
    return Eigen::VectorXd::Zero(count);
  }
  if (values.size() != count) {
    throw std::invalid_argument(std::string(name) + " has the wrong size.");
  }
  return values;
}
#else
Eigen::VectorXd zero_or_validate(const Eigen::VectorXd &values,
                                        const int count, const char *name);
#endif

} // namespace relief_topology_detail

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
Eigen::VectorXd compute_salience_relief(const ReliefInput &input,
                                               const ReliefOptions &options) {
  const int count = static_cast<int>(
      std::max({input.salience.size(), input.curvature.size(),
                input.density.size(), input.thickness.size(),
                input.patchEnergy.size()}));
  if (count <= 0) {
    return {};
  }

  const Eigen::VectorXd salience =
      relief_topology_detail::zero_or_validate(input.salience, count,
                                               "salience");
  const Eigen::VectorXd curvature =
      relief_topology_detail::zero_or_validate(input.curvature, count,
                                               "curvature");
  const Eigen::VectorXd density =
      relief_topology_detail::zero_or_validate(input.density, count, "density");
  const Eigen::VectorXd thickness =
      relief_topology_detail::zero_or_validate(input.thickness, count,
                                               "thickness");
  const Eigen::VectorXd patchEnergy =
      relief_topology_detail::zero_or_validate(input.patchEnergy, count,
                                               "patchEnergy");

  Eigen::VectorXd inverseThickness(count);
  for (int vertex = 0; vertex < count; ++vertex) {
    inverseThickness[vertex] =
        std::isfinite(thickness[vertex])
            ? options.baseSize / (std::max(0.0, thickness[vertex]) +
                                  options.thicknessEpsilon)
            : 0.0;
  }

  const Eigen::VectorXd normalizedSalience =
      adaptive_target_size_detail::robust_normalize(salience, count);
  const Eigen::VectorXd normalizedCurvature =
      adaptive_target_size_detail::robust_normalize(curvature.cwiseAbs(), count);
  const Eigen::VectorXd normalizedDensity =
      adaptive_target_size_detail::robust_normalize(density, count);
  const Eigen::VectorXd normalizedThickness =
      adaptive_target_size_detail::robust_normalize(inverseThickness, count);
  const Eigen::VectorXd normalizedPatch =
      adaptive_target_size_detail::robust_normalize(patchEnergy, count);

  Eigen::VectorXd relief(count);
  for (int vertex = 0; vertex < count; ++vertex) {
    relief[vertex] =
        options.featureWeight * normalizedSalience[vertex] +
        options.curvatureWeight * normalizedCurvature[vertex] +
        options.densityWeight * normalizedDensity[vertex] +
        options.thicknessWeight * normalizedThickness[vertex] +
        options.patchEnergyWeight * normalizedPatch[vertex];
  }
  return relief;
}
#else
Eigen::VectorXd compute_salience_relief(const ReliefInput &input,
                                               const ReliefOptions &options);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
std::vector<ReliefCriticalPoint>
classify_pl_critical_points(const Eigen::MatrixXi &faces,
                            const Eigen::VectorXd &relief) {
  const int vertexCount = static_cast<int>(relief.size());
  std::vector<ReliefCriticalPoint> points(static_cast<std::size_t>(vertexCount));
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    const std::map<int, std::set<int>> link =
        relief_topology_detail::link_adjacency(faces, vertex);
    std::set<int> lower;
    std::set<int> upper;
    for (const auto &[neighbor, adjacent] : link) {
      (void)adjacent;
      if (relief_topology_detail::symbolic_less(relief, neighbor, vertex)) {
        lower.insert(neighbor);
      } else {
        upper.insert(neighbor);
      }
    }
    ReliefCriticalPoint point;
    point.vertex = vertex;
    point.lowerComponents =
        relief_topology_detail::count_restricted_components(link, lower);
    point.upperComponents =
        relief_topology_detail::count_restricted_components(link, upper);
    if (lower.empty()) {
      point.type = ReliefCriticalType::Minimum;
    } else if (upper.empty()) {
      point.type = ReliefCriticalType::Maximum;
    } else if (point.lowerComponents == 1 && point.upperComponents == 1) {
      point.type = ReliefCriticalType::Regular;
    } else {
      point.type = ReliefCriticalType::Saddle;
      point.multiplicity =
          std::max(point.lowerComponents, point.upperComponents) - 1;
    }
    points[static_cast<std::size_t>(vertex)] = point;
  }
  return points;
}
#else
std::vector<ReliefCriticalPoint>
classify_pl_critical_points(const Eigen::MatrixXi &faces,
                            const Eigen::VectorXd &relief);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
std::vector<ReliefPersistencePair>
compute_relief_persistence_pairs(const Eigen::MatrixXd &vertices,
                                 const Eigen::MatrixXi &faces,
                                 const Eigen::VectorXd &relief,
                                 const double threshold = 0.0) {
  const int vertexCount = static_cast<int>(relief.size());
  const auto graph =
      relief_topology_detail::vertex_neighbors_from_faces(vertexCount, faces);
  std::vector<ReliefPersistencePair> pairs;

  const auto run_pass = [&](const bool ascending) {
    std::vector<int> order(vertexCount);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](const int a, const int b) {
      if (ascending) {
        return relief_topology_detail::symbolic_less(relief, a, b);
      }
      return relief_topology_detail::symbolic_less(relief, b, a);
    });

    relief_topology_detail::UnionFind uf(vertexCount);
    std::vector<unsigned char> active(static_cast<std::size_t>(vertexCount), 0);
    std::vector<int> extremum(static_cast<std::size_t>(vertexCount), -1);
    for (const int vertex : order) {
      active[static_cast<std::size_t>(vertex)] = 1;
      extremum[static_cast<std::size_t>(vertex)] = vertex;
      std::set<int> adjacentRoots;
      for (const int neighbor : graph[static_cast<std::size_t>(vertex)]) {
        if (active[static_cast<std::size_t>(neighbor)] != 0) {
          adjacentRoots.insert(uf.find(neighbor));
        }
      }
      if (adjacentRoots.empty()) {
        continue;
      }

      int keepRoot = *adjacentRoots.begin();
      for (const int root : adjacentRoots) {
        const int currentExtremum = extremum[static_cast<std::size_t>(root)];
        const int keepExtremum = extremum[static_cast<std::size_t>(keepRoot)];
        const bool rootIsBetter =
            ascending ? relief_topology_detail::symbolic_less(
                            relief, currentExtremum, keepExtremum)
                      : relief_topology_detail::symbolic_less(
                            relief, keepExtremum, currentExtremum);
        if (rootIsBetter) {
          keepRoot = root;
        }
      }
      uf.unite_keep(vertex, keepRoot, keepRoot);
      for (const int root : adjacentRoots) {
        const int currentRoot = uf.find(root);
        const int currentExtremum =
            extremum[static_cast<std::size_t>(currentRoot)];
        const int keepExtremum = extremum[static_cast<std::size_t>(keepRoot)];
        if (currentExtremum == keepExtremum) {
          continue;
        }
        ReliefPersistencePair pair;
        pair.extremum = currentExtremum;
        pair.saddle = vertex;
        pair.minimumPair = ascending;
        pair.persistence = std::abs(relief[vertex] - relief[currentExtremum]);
        pair.canceled = pair.persistence < threshold;
        pairs.push_back(pair);
        uf.unite_keep(keepRoot, currentRoot, keepRoot);
        extremum[static_cast<std::size_t>(uf.find(keepRoot))] = keepExtremum;
      }
    }
  };

  (void)vertices;
  run_pass(true);
  run_pass(false);
  std::sort(pairs.begin(), pairs.end(),
            [](const ReliefPersistencePair &a,
               const ReliefPersistencePair &b) {
              if (a.persistence != b.persistence) {
                return a.persistence < b.persistence;
              }
              if (a.extremum != b.extremum) {
                return a.extremum < b.extremum;
              }
              if (a.saddle != b.saddle) {
                return a.saddle < b.saddle;
              }
              return a.minimumPair > b.minimumPair;
            });
  return pairs;
}
#else
std::vector<ReliefPersistencePair>
compute_relief_persistence_pairs(const Eigen::MatrixXd &vertices,
                                 const Eigen::MatrixXi &faces,
                                 const Eigen::VectorXd &relief,
                                 const double threshold = 0.0);
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
Eigen::VectorXi watershed_to_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &roots,
    const std::set<std::uint64_t> &barrierEdges = {}) {
  using QueueItem = std::tuple<double, int, int>;
  struct Greater {
    bool operator()(const QueueItem &a, const QueueItem &b) const {
      if (std::get<0>(a) != std::get<0>(b)) {
        return std::get<0>(a) > std::get<0>(b);
      }
      if (std::get<1>(a) != std::get<1>(b)) {
        return std::get<1>(a) > std::get<1>(b);
      }
      return std::get<2>(a) > std::get<2>(b);
    }
  };

  const int vertexCount = static_cast<int>(vertices.rows());
  const auto graph =
      relief_topology_detail::vertex_neighbors_from_faces(vertexCount, faces);
  Eigen::VectorXi labels = Eigen::VectorXi::Constant(vertexCount, -1);
  Eigen::VectorXd costs =
      Eigen::VectorXd::Constant(vertexCount, std::numeric_limits<double>::infinity());
  std::priority_queue<QueueItem, std::vector<QueueItem>, Greater> queue;

  std::vector<int> sortedRoots = roots;
  std::sort(sortedRoots.begin(), sortedRoots.end());
  sortedRoots.erase(std::unique(sortedRoots.begin(), sortedRoots.end()),
                    sortedRoots.end());
  for (int rootIndex = 0; rootIndex < static_cast<int>(sortedRoots.size());
       ++rootIndex) {
    const int root = sortedRoots[static_cast<std::size_t>(rootIndex)];
    if (root < 0 || root >= vertexCount) {
      continue;
    }
    labels[root] = rootIndex;
    costs[root] = 0.0;
    queue.push({0.0, rootIndex, root});
  }

  while (!queue.empty()) {
    const auto [cost, root, vertex] = queue.top();
    queue.pop();
    if (labels[vertex] != root || cost != costs[vertex]) {
      continue;
    }
    for (const int neighbor : graph[static_cast<std::size_t>(vertex)]) {
      if (barrierEdges.count(relief_topology_detail::edge_key(vertex, neighbor)) != 0) {
        continue;
      }
      const double edgeLength =
          (relief_topology_detail::row3(vertices, vertex) -
           relief_topology_detail::row3(vertices, neighbor))
              .norm();
      const double candidate = cost + edgeLength;
      if (candidate + 1.0e-14 < costs[neighbor] ||
          (std::abs(candidate - costs[neighbor]) <= 1.0e-14 &&
           root < labels[neighbor])) {
        costs[neighbor] = candidate;
        labels[neighbor] = root;
        queue.push({candidate, root, neighbor});
      }
    }
  }
  return labels;
}
#else
Eigen::VectorXi watershed_to_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &roots,
    const std::set<std::uint64_t> &barrierEdges = {});
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
Eigen::VectorXd normalized_dijkstra_to_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &roots, const Eigen::VectorXd &targetSize,
    const std::set<std::uint64_t> &barrierEdges = {}) {
  using QueueItem = std::pair<double, int>;
  struct Greater {
    bool operator()(const QueueItem &a, const QueueItem &b) const {
      if (a.first != b.first) {
        return a.first > b.first;
      }
      return a.second > b.second;
    }
  };
  const int vertexCount = static_cast<int>(vertices.rows());
  const auto graph =
      relief_topology_detail::vertex_neighbors_from_faces(vertexCount, faces);
  Eigen::VectorXd distances =
      Eigen::VectorXd::Constant(vertexCount, std::numeric_limits<double>::infinity());
  std::priority_queue<QueueItem, std::vector<QueueItem>, Greater> queue;
  for (const int root : roots) {
    if (root < 0 || root >= vertexCount) {
      continue;
    }
    if (distances[root] > 0.0) {
      distances[root] = 0.0;
      queue.push({0.0, root});
    }
  }
  const auto safe_size = [&](const int vertex) {
    if (vertex >= 0 && vertex < targetSize.size() && std::isfinite(targetSize[vertex]) &&
        targetSize[vertex] > 0.0) {
      return targetSize[vertex];
    }
    return 1.0;
  };
  while (!queue.empty()) {
    const auto [distance, vertex] = queue.top();
    queue.pop();
    if (distance != distances[vertex]) {
      continue;
    }
    for (const int neighbor : graph[static_cast<std::size_t>(vertex)]) {
      if (barrierEdges.count(relief_topology_detail::edge_key(vertex, neighbor)) != 0) {
        continue;
      }
      const double h = 0.5 * (safe_size(vertex) + safe_size(neighbor));
      const double edgeLength =
          (relief_topology_detail::row3(vertices, vertex) -
           relief_topology_detail::row3(vertices, neighbor))
              .norm();
      const double candidate = distance + edgeLength / std::max(h, 1.0e-12);
      if (candidate + 1.0e-14 < distances[neighbor]) {
        distances[neighbor] = candidate;
        queue.push({candidate, neighbor});
      }
    }
  }
  return distances;
}
#else
Eigen::VectorXd normalized_dijkstra_to_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &roots, const Eigen::VectorXd &targetSize,
    const std::set<std::uint64_t> &barrierEdges = {});
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
std::vector<ReliefBranch> trace_relief_branches(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &relief,
    const std::vector<ReliefCriticalPoint> &criticalPoints,
    const std::set<std::uint64_t> &barrierEdges = {}) {
  const int vertexCount = static_cast<int>(vertices.rows());
  const auto graph =
      relief_topology_detail::vertex_neighbors_from_faces(vertexCount, faces);
  std::vector<ReliefBranch> branches;

  const auto better = [&](const int a, const int b, const bool ascending) {
    return ascending ? relief_topology_detail::symbolic_less(relief, a, b)
                     : relief_topology_detail::symbolic_less(relief, b, a);
  };
  const auto is_extremum = [&](const int vertex, const bool ascending) {
    if (vertex < 0 || vertex >= static_cast<int>(criticalPoints.size())) {
      return false;
    }
    return ascending
               ? criticalPoints[static_cast<std::size_t>(vertex)].type ==
                     ReliefCriticalType::Maximum
               : criticalPoints[static_cast<std::size_t>(vertex)].type ==
                     ReliefCriticalType::Minimum;
  };

  for (const ReliefCriticalPoint &point : criticalPoints) {
    if (point.type != ReliefCriticalType::Saddle) {
      continue;
    }
    for (const bool ascending : {false, true}) {
      std::vector<int> seeds;
      for (const int neighbor : graph[static_cast<std::size_t>(point.vertex)]) {
        if (barrierEdges.count(relief_topology_detail::edge_key(point.vertex,
                                                                neighbor)) != 0) {
          continue;
        }
        if (better(point.vertex, neighbor, ascending)) {
          seeds.push_back(neighbor);
        }
      }
      std::sort(seeds.begin(), seeds.end(), [&](const int a, const int b) {
        if (relief[a] != relief[b]) {
          return ascending ? relief[a] > relief[b] : relief[a] < relief[b];
        }
        return a < b;
      });
      seeds.erase(std::unique(seeds.begin(), seeds.end()), seeds.end());

      for (const int seed : seeds) {
        ReliefBranch branch;
        branch.saddle = point.vertex;
        branch.ascending = ascending;
        branch.vertices = {point.vertex, seed};
        std::set<int> visited{point.vertex, seed};
        int current = seed;
        while (!is_extremum(current, ascending)) {
          int next = -1;
          for (const int neighbor : graph[static_cast<std::size_t>(current)]) {
            if (visited.count(neighbor) != 0) {
              continue;
            }
            if (barrierEdges.count(
                    relief_topology_detail::edge_key(current, neighbor)) != 0) {
              continue;
            }
            if (!better(current, neighbor, ascending)) {
              continue;
            }
            if (next < 0 ||
                (ascending ? relief_topology_detail::symbolic_less(relief, next,
                                                                    neighbor)
                           : relief_topology_detail::symbolic_less(relief,
                                                                    neighbor,
                                                                    next))) {
              next = neighbor;
            }
          }
          if (next < 0) {
            break;
          }
          branch.vertices.push_back(next);
          visited.insert(next);
          current = next;
        }
        branch.extremum = current;
        branches.push_back(std::move(branch));
      }
    }
  }

  std::sort(branches.begin(), branches.end(),
            [](const ReliefBranch &a, const ReliefBranch &b) {
              if (a.saddle != b.saddle) {
                return a.saddle < b.saddle;
              }
              if (a.ascending != b.ascending) {
                return a.ascending < b.ascending;
              }
              if (a.extremum != b.extremum) {
                return a.extremum < b.extremum;
              }
              return a.vertices < b.vertices;
            });
  return branches;
}
#else
std::vector<ReliefBranch> trace_relief_branches(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &relief,
    const std::vector<ReliefCriticalPoint> &criticalPoints,
    const std::set<std::uint64_t> &barrierEdges = {});
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
ReliefTopologyResult analyze_relief_topology(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &relief,
    const std::set<std::uint64_t> &barrierEdges = {},
    const ReliefOptions &options = {}) {
  ReliefTopologyResult result;
  result.relief = relief;
  result.criticalPoints = classify_pl_critical_points(faces, relief);
  result.persistencePairs =
      compute_relief_persistence_pairs(vertices, faces, relief,
                                       options.persistenceThreshold);

  std::set<int> canceledMinima;
  std::set<int> canceledMaxima;
  for (const ReliefPersistencePair &pair : result.persistencePairs) {
    if (pair.minimumPair && pair.canceled) {
      canceledMinima.insert(pair.extremum);
    } else if (!pair.minimumPair && pair.canceled) {
      canceledMaxima.insert(pair.extremum);
    }
  }
  for (ReliefCriticalPoint &point : result.criticalPoints) {
    if (point.type == ReliefCriticalType::Minimum &&
        canceledMinima.count(point.vertex) != 0) {
      point.retained = false;
    }
    if (point.type == ReliefCriticalType::Maximum &&
        canceledMaxima.count(point.vertex) != 0) {
      point.retained = false;
    }
  }

  if (relief.size() > 0) {
    const double range = relief.maxCoeff() - relief.minCoeff();
    if (std::abs(range) <= 1.0e-14) {
      for (ReliefCriticalPoint &point : result.criticalPoints) {
        if (point.type != ReliefCriticalType::Regular) {
          point.retained = false;
        }
      }
    }
  }

  result.branches =
      trace_relief_branches(vertices, faces, relief, result.criticalPoints,
                            barrierEdges);
  result.branches.erase(
      std::remove_if(result.branches.begin(), result.branches.end(),
                     [&](const ReliefBranch &branch) {
                       if (branch.saddle < 0 ||
                           branch.saddle >= static_cast<int>(result.criticalPoints.size()) ||
                           branch.extremum < 0 ||
                           branch.extremum >= static_cast<int>(result.criticalPoints.size())) {
                         return true;
                       }
                       const ReliefCriticalPoint &saddle =
                           result.criticalPoints[static_cast<std::size_t>(branch.saddle)];
                       const ReliefCriticalPoint &extremum =
                           result.criticalPoints[static_cast<std::size_t>(branch.extremum)];
                       return !saddle.retained || !extremum.retained;
                     }),
      result.branches.end());

  for (const ReliefCriticalPoint &point : result.criticalPoints) {
    if (point.type == ReliefCriticalType::Minimum && point.retained) {
      result.watershedRoots.push_back(point.vertex);
    }
  }
  if (result.watershedRoots.empty() && relief.size() > 0) {
    int best = 0;
    for (int vertex = 1; vertex < relief.size(); ++vertex) {
      if (relief_topology_detail::symbolic_less(relief, vertex, best)) {
        best = vertex;
      }
    }
    result.watershedRoots.push_back(best);
  }
  result.watershedLabels =
      watershed_to_roots(vertices, faces, result.watershedRoots, barrierEdges);
  return result;
}
#else
ReliefTopologyResult analyze_relief_topology(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &relief,
    const std::set<std::uint64_t> &barrierEdges = {},
    const ReliefOptions &options = {});
#endif

#if defined(DIRECTIONAL_RELIEF_TOPOLOGY_IMPLEMENTATION)
ReliefRootSelectionResult select_relief_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const ReliefTopologyResult &topology, const Eigen::VectorXd &targetSize,
    const ReliefRootSelectionOptions &options = {}) {
  const int vertexCount = static_cast<int>(vertices.rows());
  std::vector<int> roots;
  std::set<int> canceledCriticalVertices;
  for (const ReliefCriticalPoint &point : topology.criticalPoints) {
    if (!point.retained && point.type != ReliefCriticalType::Regular &&
        point.vertex >= 0 && point.vertex < vertexCount) {
      canceledCriticalVertices.insert(point.vertex);
    }
    if (point.retained && point.type != ReliefCriticalType::Regular) {
      roots.push_back(point.vertex);
    }
  }
  for (const int vertex : options.featureJunctions) {
    relief_topology_detail::append_unique_sorted(roots, vertex, vertexCount);
  }
  for (const int vertex : options.singularities) {
    relief_topology_detail::append_unique_sorted(roots, vertex, vertexCount);
  }
  for (const int vertex : options.skeletonAnchors) {
    relief_topology_detail::append_unique_sorted(roots, vertex, vertexCount);
  }
  std::sort(roots.begin(), roots.end());
  roots.erase(std::unique(roots.begin(), roots.end()), roots.end());
  roots.erase(std::remove_if(roots.begin(), roots.end(),
                             [&](const int vertex) {
                               return canceledCriticalVertices.count(vertex) !=
                                      0;
                             }),
              roots.end());
  if (roots.empty() && vertexCount > 0) {
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (canceledCriticalVertices.count(vertex) == 0) {
        roots.push_back(vertex);
        break;
      }
    }
    if (roots.empty()) {
      roots.push_back(0);
    }
  }

  Eigen::VectorXd safeSize =
      targetSize.size() == vertexCount
          ? targetSize
          : Eigen::VectorXd::Constant(vertexCount, 1.0);
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    if (!std::isfinite(safeSize[vertex]) || safeSize[vertex] <= 0.0) {
      safeSize[vertex] = 1.0;
    }
  }

  while (!roots.empty()) {
    const Eigen::VectorXi labels =
        watershed_to_roots(vertices, faces, roots, options.hardBarrierEdges);
    const Eigen::VectorXd normalizedDistance = normalized_dijkstra_to_roots(
        vertices, faces, roots, safeSize, options.hardBarrierEdges);
    double worst = 0.0;
    int worstVertex = -1;
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (canceledCriticalVertices.count(vertex) != 0) {
        continue;
      }
      if (labels[vertex] < 0) {
        continue;
      }
      const double distance = normalizedDistance[vertex];
      if (!std::isfinite(distance)) {
        continue;
      }
      if (distance > worst + 1.0e-14 ||
          (std::abs(distance - worst) <= 1.0e-14 && vertex < worstVertex)) {
        worst = distance;
        worstVertex = vertex;
      }
    }
    if (worstVertex < 0 || worst <= options.maximumNormalizedDistance) {
      break;
    }
    roots.push_back(worstVertex);
    std::sort(roots.begin(), roots.end());
    roots.erase(std::unique(roots.begin(), roots.end()), roots.end());
  }

  ReliefRootSelectionResult result;
  result.roots = roots;
  result.labels =
      watershed_to_roots(vertices, faces, result.roots, options.hardBarrierEdges);
  result.targets.resize(static_cast<int>(result.roots.size()), 3);
  for (int root = 0; root < static_cast<int>(result.roots.size()); ++root) {
    result.targets.row(root) =
        vertices.row(result.roots[static_cast<std::size_t>(root)]);
  }
  return result;
}
#else
ReliefRootSelectionResult select_relief_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const ReliefTopologyResult &topology, const Eigen::VectorXd &targetSize,
    const ReliefRootSelectionOptions &options = {});
#endif

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_RELIEF_TOPOLOGY_H
