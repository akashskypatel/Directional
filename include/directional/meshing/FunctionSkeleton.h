// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_FUNCTION_SKELETON_H
#define DIRECTIONAL_MESHING_FUNCTION_SKELETON_H

#include <cstddef>
#include <vector>

namespace directional {

struct FunctionSkeletonNode {
  int dcelVertex = -1;
  int functionDegree = 0;
  bool boundaryProtected = false;
  bool seamProtected = false;
  bool singularProtected = false;
  bool branch = false;
};

struct FunctionSkeletonEdge {
  int sourceNode = -1;
  int targetNode = -1;
  int functionFamily = -1;
  bool boundaryProtected = false;
  bool seamProtected = false;
  bool valid = true;
  double geometricLength = 0.0;
  std::vector<int> halfedgeChain;
  std::vector<int> incidentRegionIds;
};

struct FunctionSkeleton {
  std::vector<FunctionSkeletonNode> nodes;
  std::vector<FunctionSkeletonEdge> edges;
  std::size_t rawFunctionHalfedgeCount = 0;
  std::size_t rawFunctionEdgeCount = 0;
  std::size_t validDcelVertexCount = 0;
  std::size_t validDcelHalfedgeCount = 0;
  bool matchesFunctionConnectivity = true;

  [[nodiscard]] double averageHalfedgesPerSkeletonEdge() const {
    if (edges.empty()) {
      return 0.0;
    }

    std::size_t chainHalfedges = 0;
    for (const FunctionSkeletonEdge &edge : edges) {
      chainHalfedges += edge.halfedgeChain.size();
    }
    return static_cast<double>(chainHalfedges) /
           static_cast<double>(edges.size());
  }
};

struct FunctionSkeletonEditPlan {
  std::size_t degreeOneInteriorLeaves = 0;
  std::size_t redundantDegreeTwoNodes = 0;
  std::size_t duplicateChains = 0;
  std::size_t tinyCycles = 0;
  std::size_t plannedEdits = 0;
  std::size_t appliedEdits = 0;
  std::size_t rejectedEdits = 0;
  std::vector<int> clearFunctionHalfedges;
};

} // namespace directional

#endif // DIRECTIONAL_MESHING_FUNCTION_SKELETON_H
