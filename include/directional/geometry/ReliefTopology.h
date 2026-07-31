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

std::uint64_t edge_key(const int a, const int b);

bool symbolic_less(const Eigen::VectorXd &relief, const int a,
                          const int b);

Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex);

std::vector<std::vector<int>>
vertex_neighbors_from_faces(const int vertexCount, const Eigen::MatrixXi &faces);

std::map<int, std::set<int>>
link_adjacency(const Eigen::MatrixXi &faces, const int center);

int count_restricted_components(const std::map<int, std::set<int>> &graph,
                                       const std::set<int> &enabled);

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

void append_unique_sorted(std::vector<int> &values, const int value,
                                 const int vertexCount);

Eigen::VectorXd zero_or_validate(const Eigen::VectorXd &values,
                                        const int count, const char *name);

} // namespace relief_topology_detail

Eigen::VectorXd compute_salience_relief(const ReliefInput &input,
                                               const ReliefOptions &options);

std::vector<ReliefCriticalPoint>
classify_pl_critical_points(const Eigen::MatrixXi &faces,
                            const Eigen::VectorXd &relief);

std::vector<ReliefPersistencePair>
compute_relief_persistence_pairs(const Eigen::MatrixXd &vertices,
                                 const Eigen::MatrixXi &faces,
                                 const Eigen::VectorXd &relief,
                                 const double threshold = 0.0);

Eigen::VectorXi watershed_to_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &roots,
    const std::set<std::uint64_t> &barrierEdges = {});

Eigen::VectorXd normalized_dijkstra_to_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &roots, const Eigen::VectorXd &targetSize,
    const std::set<std::uint64_t> &barrierEdges = {});

std::vector<ReliefBranch> trace_relief_branches(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &relief,
    const std::vector<ReliefCriticalPoint> &criticalPoints,
    const std::set<std::uint64_t> &barrierEdges = {});

ReliefTopologyResult analyze_relief_topology(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &relief,
    const std::set<std::uint64_t> &barrierEdges = {},
    const ReliefOptions &options = {});

ReliefRootSelectionResult select_relief_roots(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const ReliefTopologyResult &topology, const Eigen::VectorXd &targetSize,
    const ReliefRootSelectionOptions &options = {});

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_RELIEF_TOPOLOGY_H
