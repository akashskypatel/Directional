// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_FUNCTION_SKELETON_BUILDER_H
#define DIRECTIONAL_MESHING_FUNCTION_SKELETON_BUILDER_H

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <map>
#include <set>
#include <utility>
#include <vector>

#include <directional/meshing/FunctionSkeleton.h>

namespace directional {
namespace detail {

class FunctionSkeletonBuilder {
public:
  template <typename DcelT>
  [[nodiscard]] static FunctionSkeleton build(const DcelT &dcel) {
    FunctionSkeleton skeleton;
    const int vertexCount = static_cast<int>(dcel.vertices.size());
    const int halfedgeCount = static_cast<int>(dcel.halfedges.size());
    if (vertexCount <= 0 || halfedgeCount <= 0) {
      return skeleton;
    }

    std::vector<std::vector<int>> incidentFunctionEdges(
        static_cast<std::size_t>(vertexCount));
    std::vector<unsigned char> boundaryVertex(static_cast<std::size_t>(vertexCount),
                                              static_cast<unsigned char>(0));
    std::vector<unsigned char> seamVertex(static_cast<std::size_t>(vertexCount),
                                          static_cast<unsigned char>(0));
    std::vector<int> canonicalEdge(halfedgeCount, -1);
    std::vector<FunctionEdgeRef> functionEdges;

    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (dcel.vertices[static_cast<std::size_t>(vertex)].valid) {
        ++skeleton.validDcelVertexCount;
      }
    }

    for (int he = 0; he < halfedgeCount; ++he) {
      if (!dcel.valid_halfedge(he)) {
        continue;
      }
      ++skeleton.validDcelHalfedgeCount;

      const auto &halfedge = dcel.halfedges[static_cast<std::size_t>(he)];
      const int origin = halfedge.vertex;
      if (halfedge.twin < 0 && origin >= 0 && origin < vertexCount) {
        boundaryVertex[static_cast<std::size_t>(origin)] =
            static_cast<unsigned char>(1);
      }
      if (!halfedge.data.isFunction) {
        continue;
      }

      ++skeleton.rawFunctionHalfedgeCount;
      const int twin = halfedge.twin;
      const int canonical = twin >= 0 ? std::min(he, twin) : he;
      if (canonicalEdge[static_cast<std::size_t>(he)] >= 0) {
        continue;
      }
      if (twin >= 0 && twin < halfedgeCount &&
          canonicalEdge[static_cast<std::size_t>(twin)] >= 0) {
        canonicalEdge[static_cast<std::size_t>(he)] =
            canonicalEdge[static_cast<std::size_t>(twin)];
        continue;
      }

      const int target =
          twin >= 0 && twin < halfedgeCount && dcel.valid_halfedge(twin)
              ? dcel.halfedges[static_cast<std::size_t>(twin)].vertex
              : -1;
      FunctionEdgeRef edge;
      edge.primaryHalfedge = he;
      edge.twinHalfedge = twin;
      edge.sourceVertex = origin;
      edge.targetVertex = target;
      edge.functionFamily = halfedge.data.origNFunctionIndex;
      edge.boundaryProtected = twin < 0;
      edge.seamProtected = false;
      functionEdges.push_back(edge);
      const int edgeIndex = static_cast<int>(functionEdges.size() - 1);
      canonicalEdge[static_cast<std::size_t>(he)] = edgeIndex;
      if (twin >= 0 && twin < halfedgeCount) {
        canonicalEdge[static_cast<std::size_t>(twin)] = edgeIndex;
      }
    }

    std::sort(functionEdges.begin(), functionEdges.end(),
              [](const FunctionEdgeRef &lhs, const FunctionEdgeRef &rhs) {
                return lhs.primaryHalfedge < rhs.primaryHalfedge;
              });

    for (int edgeIndex = 0; edgeIndex < static_cast<int>(functionEdges.size());
         ++edgeIndex) {
      const FunctionEdgeRef &edge =
          functionEdges[static_cast<std::size_t>(edgeIndex)];
      add_incident_edge(edge.sourceVertex, edgeIndex, incidentFunctionEdges);
      add_incident_edge(edge.targetVertex, edgeIndex, incidentFunctionEdges);
      mark_protected_vertex(edge.sourceVertex, edge, boundaryVertex, seamVertex);
      mark_protected_vertex(edge.targetVertex, edge, boundaryVertex, seamVertex);
    }

    skeleton.rawFunctionEdgeCount = functionEdges.size();
    std::vector<int> skeletonNodeForVertex(static_cast<std::size_t>(vertexCount),
                                           -1);
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (!dcel.vertices[static_cast<std::size_t>(vertex)].valid) {
        continue;
      }
      const int degree =
          static_cast<int>(incidentFunctionEdges[static_cast<std::size_t>(vertex)]
                               .size());
      const bool protectedVertex =
          boundaryVertex[static_cast<std::size_t>(vertex)] != 0 ||
          seamVertex[static_cast<std::size_t>(vertex)] != 0;
      if (degree == 0 || (degree == 2 && !protectedVertex)) {
        continue;
      }

      FunctionSkeletonNode node;
      node.dcelVertex = vertex;
      node.functionDegree = degree;
      node.boundaryProtected =
          boundaryVertex[static_cast<std::size_t>(vertex)] != 0;
      node.seamProtected = seamVertex[static_cast<std::size_t>(vertex)] != 0;
      node.branch = degree != 2;
      skeletonNodeForVertex[static_cast<std::size_t>(vertex)] =
          static_cast<int>(skeleton.nodes.size());
      skeleton.nodes.push_back(node);
    }

    std::vector<unsigned char> visitedEdges(functionEdges.size(),
                                            static_cast<unsigned char>(0));
    for (int edgeIndex = 0; edgeIndex < static_cast<int>(functionEdges.size());
         ++edgeIndex) {
      if (visitedEdges[static_cast<std::size_t>(edgeIndex)] != 0) {
        continue;
      }

      const FunctionEdgeRef &edge =
          functionEdges[static_cast<std::size_t>(edgeIndex)];
      const int sourceNode = node_for_or_create(edge.sourceVertex, dcel,
                                                incidentFunctionEdges,
                                                boundaryVertex, seamVertex,
                                                skeletonNodeForVertex, skeleton);
      append_chain_from(edgeIndex, edge.sourceVertex, edge.targetVertex,
                        sourceNode, dcel, functionEdges, incidentFunctionEdges,
                        skeletonNodeForVertex, visitedEdges, skeleton);
    }

    skeleton.matchesFunctionConnectivity =
        validate_connectivity(skeleton, functionEdges.size());
    return skeleton;
  }

private:
  struct FunctionEdgeRef {
    int primaryHalfedge = -1;
    int twinHalfedge = -1;
    int sourceVertex = -1;
    int targetVertex = -1;
    int functionFamily = -1;
    bool boundaryProtected = false;
    bool seamProtected = false;
  };

  static void add_incident_edge(
      const int vertex, const int edgeIndex,
      std::vector<std::vector<int>> &incidentFunctionEdges) {
    if (vertex < 0 ||
        vertex >= static_cast<int>(incidentFunctionEdges.size())) {
      return;
    }
    incidentFunctionEdges[static_cast<std::size_t>(vertex)].push_back(edgeIndex);
  }

  static void mark_protected_vertex(const int vertex, const FunctionEdgeRef &edge,
                                    std::vector<unsigned char> &boundaryVertex,
                                    std::vector<unsigned char> &seamVertex) {
    if (vertex < 0 || vertex >= static_cast<int>(boundaryVertex.size())) {
      return;
    }
    if (edge.boundaryProtected) {
      boundaryVertex[static_cast<std::size_t>(vertex)] =
          static_cast<unsigned char>(1);
    }
    if (edge.seamProtected) {
      seamVertex[static_cast<std::size_t>(vertex)] =
          static_cast<unsigned char>(1);
    }
  }

  template <typename DcelT>
  static int node_for_or_create(
      const int vertex, const DcelT &dcel,
      const std::vector<std::vector<int>> &incidentFunctionEdges,
      const std::vector<unsigned char> &boundaryVertex,
      const std::vector<unsigned char> &seamVertex,
      std::vector<int> &skeletonNodeForVertex, FunctionSkeleton &skeleton) {
    if (vertex < 0 || vertex >= static_cast<int>(skeletonNodeForVertex.size())) {
      return -1;
    }
    int &nodeIndex = skeletonNodeForVertex[static_cast<std::size_t>(vertex)];
    if (nodeIndex >= 0) {
      return nodeIndex;
    }

    FunctionSkeletonNode node;
    node.dcelVertex = vertex;
    node.functionDegree =
        static_cast<int>(incidentFunctionEdges[static_cast<std::size_t>(vertex)]
                             .size());
    node.boundaryProtected =
        boundaryVertex[static_cast<std::size_t>(vertex)] != 0;
    node.seamProtected = seamVertex[static_cast<std::size_t>(vertex)] != 0;
    node.branch = node.functionDegree != 2;
    (void)dcel;
    nodeIndex = static_cast<int>(skeleton.nodes.size());
    skeleton.nodes.push_back(node);
    return nodeIndex;
  }

  template <typename DcelT>
  static void append_chain_from(
      const int firstEdgeIndex, const int startVertex, const int nextVertex,
      const int sourceNode, const DcelT &dcel,
      const std::vector<FunctionEdgeRef> &functionEdges,
      const std::vector<std::vector<int>> &incidentFunctionEdges,
      std::vector<int> &skeletonNodeForVertex,
      std::vector<unsigned char> &visitedEdges, FunctionSkeleton &skeleton) {
    FunctionSkeletonEdge skeletonEdge;
    skeletonEdge.sourceNode = sourceNode;
    skeletonEdge.functionFamily =
        functionEdges[static_cast<std::size_t>(firstEdgeIndex)].functionFamily;
    int previousVertex = startVertex;
    int currentVertex = nextVertex;
    int currentEdgeIndex = firstEdgeIndex;

    for (int guard = 0; guard < static_cast<int>(functionEdges.size()) + 1;
         ++guard) {
      if (currentEdgeIndex < 0 ||
          currentEdgeIndex >= static_cast<int>(functionEdges.size())) {
        break;
      }
      if (visitedEdges[static_cast<std::size_t>(currentEdgeIndex)] != 0) {
        break;
      }

      const FunctionEdgeRef &edge =
          functionEdges[static_cast<std::size_t>(currentEdgeIndex)];
      visitedEdges[static_cast<std::size_t>(currentEdgeIndex)] =
          static_cast<unsigned char>(1);
      skeletonEdge.halfedgeChain.push_back(edge.primaryHalfedge);
      if (edge.twinHalfedge >= 0) {
        skeletonEdge.halfedgeChain.push_back(edge.twinHalfedge);
      }
      skeletonEdge.boundaryProtected =
          skeletonEdge.boundaryProtected || edge.boundaryProtected;
      skeletonEdge.seamProtected =
          skeletonEdge.seamProtected || edge.seamProtected;
      append_region(edge.primaryHalfedge, dcel, skeletonEdge.incidentRegionIds);
      append_region(edge.twinHalfedge, dcel, skeletonEdge.incidentRegionIds);
      skeletonEdge.geometricLength +=
          edge_length(edge.sourceVertex, edge.targetVertex, dcel);

      if (currentVertex < 0 ||
          currentVertex >= static_cast<int>(skeletonNodeForVertex.size())) {
        break;
      }
      if (skeletonNodeForVertex[static_cast<std::size_t>(currentVertex)] >= 0 &&
          currentVertex != startVertex) {
        skeletonEdge.targetNode =
            skeletonNodeForVertex[static_cast<std::size_t>(currentVertex)];
        break;
      }

      const std::vector<int> &incident =
          incidentFunctionEdges[static_cast<std::size_t>(currentVertex)];
      if (incident.size() != 2) {
        skeletonEdge.targetNode = node_for_or_create_unprotected(
            currentVertex, dcel, incidentFunctionEdges, skeletonNodeForVertex,
            skeleton);
        break;
      }

      int nextEdgeIndex = -1;
      for (const int incidentEdge : incident) {
        if (incidentEdge != currentEdgeIndex) {
          nextEdgeIndex = incidentEdge;
          break;
        }
      }
      if (nextEdgeIndex < 0 ||
          visitedEdges[static_cast<std::size_t>(nextEdgeIndex)] != 0) {
        skeletonEdge.targetNode = sourceNode;
        break;
      }

      const FunctionEdgeRef &nextEdge =
          functionEdges[static_cast<std::size_t>(nextEdgeIndex)];
      const int followingVertex =
          nextEdge.sourceVertex == currentVertex ? nextEdge.targetVertex
                                                 : nextEdge.sourceVertex;
      previousVertex = currentVertex;
      currentVertex = followingVertex;
      currentEdgeIndex = nextEdgeIndex;
    }

    if (skeletonEdge.targetNode < 0) {
      skeletonEdge.targetNode = sourceNode;
    }
    (void)previousVertex;
    normalize_unique(skeletonEdge.incidentRegionIds);
    skeleton.edges.push_back(std::move(skeletonEdge));
  }

  template <typename DcelT>
  static int node_for_or_create_unprotected(
      const int vertex, const DcelT &dcel,
      const std::vector<std::vector<int>> &incidentFunctionEdges,
      std::vector<int> &skeletonNodeForVertex, FunctionSkeleton &skeleton) {
    std::vector<unsigned char> unprotected(skeletonNodeForVertex.size(),
                                           static_cast<unsigned char>(0));
    return node_for_or_create(vertex, dcel, incidentFunctionEdges, unprotected,
                              unprotected, skeletonNodeForVertex, skeleton);
  }

  template <typename DcelT>
  static void append_region(const int halfedge, const DcelT &dcel,
                            std::vector<int> &regions) {
    if (halfedge < 0 || halfedge >= static_cast<int>(dcel.halfedges.size()) ||
        !dcel.valid_halfedge(halfedge)) {
      return;
    }
    const int face = dcel.halfedges[static_cast<std::size_t>(halfedge)].face;
    if (face >= 0) {
      regions.push_back(face);
    }
  }

  template <typename DcelT>
  static double edge_length(const int source, const int target,
                            const DcelT &dcel) {
    if (source < 0 || target < 0 ||
        source >= static_cast<int>(dcel.vertices.size()) ||
        target >= static_cast<int>(dcel.vertices.size())) {
      return 0.0;
    }
    const auto delta = dcel.vertices[static_cast<std::size_t>(source)]
                           .data.coords -
                       dcel.vertices[static_cast<std::size_t>(target)]
                           .data.coords;
    return std::sqrt(delta.squaredNorm());
  }

  static void normalize_unique(std::vector<int> &values) {
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
  }

  static bool validate_connectivity(const FunctionSkeleton &skeleton,
                                    const std::size_t rawFunctionEdgeCount) {
    std::size_t representedEdges = 0;
    for (const FunctionSkeletonEdge &edge : skeleton.edges) {
      if (!edge.valid || edge.sourceNode < 0 || edge.targetNode < 0) {
        return false;
      }
      representedEdges += edge.halfedgeChain.empty()
                              ? 0
                              : (edge.halfedgeChain.size() + 1) / 2;
    }
    return representedEdges == rawFunctionEdgeCount;
  }
};

} // namespace detail
} // namespace directional

#endif // DIRECTIONAL_MESHING_FUNCTION_SKELETON_BUILDER_H
