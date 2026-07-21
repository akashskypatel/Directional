// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_PATCH_REGION_H
#define DIRECTIONAL_MESHING_PATCH_REGION_H

#include <cstddef>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Core>

namespace directional {
namespace detail {

enum class PatchClass {
  Unsupported,
  FourSidedDisk,
  SimpleThreeSided,
  SimpleFiveSided,
  SimpleSixSided
};

struct PatchBoundaryEdge {
  int first = -1;
  int second = -1;

  [[nodiscard]] bool operator<(const PatchBoundaryEdge &other) const {
    if (first != other.first) {
      return first < other.first;
    }
    return second < other.second;
  }
};

struct PatchRegion {
  std::vector<int> boundaryVertices;
  std::vector<int> sideEdgeCounts;
  std::set<PatchBoundaryEdge> protectedBoundaryEdges;
  bool diskTopology = true;
};

struct PatchMesh {
  std::vector<int> vertices;
  Eigen::MatrixXd vertexPositions;
  std::vector<std::vector<int>> quads;
  std::vector<int> boundaryVertices;
};

[[nodiscard]] inline std::size_t
patch_boundary_edge_count(const PatchRegion &region) {
  std::size_t total = 0;
  for (const int count : region.sideEdgeCounts) {
    if (count <= 0) {
      return 0;
    }
    total += static_cast<std::size_t>(count);
  }
  return total;
}

[[nodiscard]] inline PatchBoundaryEdge
canonical_patch_edge(const int first, const int second) {
  return first <= second ? PatchBoundaryEdge{first, second}
                         : PatchBoundaryEdge{second, first};
}

} // namespace detail
} // namespace directional

#endif // DIRECTIONAL_MESHING_PATCH_REGION_H
