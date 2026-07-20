// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_FUNCTION_SKELETON_SIMPLIFIER_H
#define DIRECTIONAL_MESHING_FUNCTION_SKELETON_SIMPLIFIER_H

#include <algorithm>
#include <cstddef>
#include <deque>
#include <vector>

#include <directional/meshing/FunctionSkeleton.h>

namespace directional {
namespace detail {

class FunctionSkeletonSimplifier {
public:
  [[nodiscard]] static FunctionSkeletonEditPlan
  plan_read_only(const FunctionSkeleton &skeleton) {
    FunctionSkeletonEditPlan plan;
    for (const FunctionSkeletonNode &node : skeleton.nodes) {
      if (node.singularProtected || node.boundaryProtected ||
          node.seamProtected) {
        continue;
      }
      if (node.functionDegree == 1) {
        ++plan.degreeOneInteriorLeaves;
      } else if (node.functionDegree == 2 && !node.branch) {
        ++plan.redundantDegreeTwoNodes;
      }
    }

    // Phase 04A is diagnostic-only. Later substeps can promote these candidates
    // to planned/applied edits after exact topology guards are in place.
    plan.plannedEdits = 0;
    plan.appliedEdits = 0;
    plan.rejectedEdits = plan.degreeOneInteriorLeaves +
                         plan.redundantDegreeTwoNodes + plan.duplicateChains +
                         plan.tinyCycles;
    return plan;
  }

  [[nodiscard]] static FunctionSkeletonEditPlan
  plan_safe_cleanup(const FunctionSkeleton &skeleton) {
    FunctionSkeletonEditPlan plan = plan_read_only(skeleton);
    if (skeleton.nodes.empty() || skeleton.edges.empty()) {
      plan.rejectedEdits = 0;
      return plan;
    }

    std::vector<std::vector<int>> incidentEdges(skeleton.nodes.size());
    std::vector<int> degree(skeleton.nodes.size(), 0);
    for (int edgeIndex = 0; edgeIndex < static_cast<int>(skeleton.edges.size());
         ++edgeIndex) {
      const FunctionSkeletonEdge &edge =
          skeleton.edges[static_cast<std::size_t>(edgeIndex)];
      if (!edge.valid || edge.sourceNode < 0 || edge.targetNode < 0 ||
          edge.sourceNode >= static_cast<int>(skeleton.nodes.size()) ||
          edge.targetNode >= static_cast<int>(skeleton.nodes.size())) {
        ++plan.rejectedEdits;
        continue;
      }
      incidentEdges[static_cast<std::size_t>(edge.sourceNode)].push_back(
          edgeIndex);
      ++degree[static_cast<std::size_t>(edge.sourceNode)];
      if (edge.targetNode != edge.sourceNode) {
        incidentEdges[static_cast<std::size_t>(edge.targetNode)].push_back(
            edgeIndex);
        ++degree[static_cast<std::size_t>(edge.targetNode)];
      }
    }

    std::deque<int> pending;
    std::vector<unsigned char> queued(skeleton.nodes.size(),
                                      static_cast<unsigned char>(0));
    const auto protected_node = [&](const int nodeIndex) {
      const FunctionSkeletonNode &node =
          skeleton.nodes[static_cast<std::size_t>(nodeIndex)];
      return node.boundaryProtected || node.seamProtected ||
             node.singularProtected;
    };
    const auto queue_if_leaf = [&](const int nodeIndex) {
      if (nodeIndex < 0 || nodeIndex >= static_cast<int>(skeleton.nodes.size())) {
        return;
      }
      if (protected_node(nodeIndex)) {
        return;
      }
      if (degree[static_cast<std::size_t>(nodeIndex)] != 1) {
        return;
      }
      if (queued[static_cast<std::size_t>(nodeIndex)] != 0) {
        return;
      }
      queued[static_cast<std::size_t>(nodeIndex)] = static_cast<unsigned char>(1);
      pending.push_back(nodeIndex);
    };

    for (int nodeIndex = 0; nodeIndex < static_cast<int>(skeleton.nodes.size());
         ++nodeIndex) {
      queue_if_leaf(nodeIndex);
    }

    std::vector<unsigned char> removedEdge(skeleton.edges.size(),
                                           static_cast<unsigned char>(0));
    while (!pending.empty()) {
      const int nodeIndex = pending.front();
      pending.pop_front();
      queued[static_cast<std::size_t>(nodeIndex)] = static_cast<unsigned char>(0);
      if (protected_node(nodeIndex) ||
          degree[static_cast<std::size_t>(nodeIndex)] != 1) {
        continue;
      }

      int edgeIndex = -1;
      for (const int candidate :
           incidentEdges[static_cast<std::size_t>(nodeIndex)]) {
        if (removedEdge[static_cast<std::size_t>(candidate)] == 0) {
          edgeIndex = candidate;
          break;
        }
      }
      if (edgeIndex < 0) {
        continue;
      }

      const FunctionSkeletonEdge &edge =
          skeleton.edges[static_cast<std::size_t>(edgeIndex)];
      const int otherNode =
          edge.sourceNode == nodeIndex ? edge.targetNode : edge.sourceNode;
      if (edge.boundaryProtected || edge.seamProtected) {
        ++plan.rejectedEdits;
        continue;
      }

      removedEdge[static_cast<std::size_t>(edgeIndex)] =
          static_cast<unsigned char>(1);
      ++plan.plannedEdits;
      for (const int halfedge : edge.halfedgeChain) {
        if (halfedge >= 0) {
          plan.clearFunctionHalfedges.push_back(halfedge);
        }
      }

      --degree[static_cast<std::size_t>(nodeIndex)];
      if (otherNode >= 0 && otherNode < static_cast<int>(degree.size()) &&
          degree[static_cast<std::size_t>(otherNode)] > 0) {
        --degree[static_cast<std::size_t>(otherNode)];
        queue_if_leaf(otherNode);
      }
    }

    std::sort(plan.clearFunctionHalfedges.begin(),
              plan.clearFunctionHalfedges.end());
    plan.clearFunctionHalfedges.erase(
        std::unique(plan.clearFunctionHalfedges.begin(),
                    plan.clearFunctionHalfedges.end()),
        plan.clearFunctionHalfedges.end());
    plan.rejectedEdits =
        plan.redundantDegreeTwoNodes + plan.duplicateChains + plan.tinyCycles;
    return plan;
  }
};

} // namespace detail
} // namespace directional

#endif // DIRECTIONAL_MESHING_FUNCTION_SKELETON_SIMPLIFIER_H
