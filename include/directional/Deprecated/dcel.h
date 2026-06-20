// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2024 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_DCEL_H
#define DIRECTIONAL_DCEL_H

#include <Eigen/Core>

#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace directional
{
//This header file represents a class inplementing the doubly-connected edge list, which is the underlying structure for reprsenting triangle meshes in Directional.
template<typename VertexData, typename HalfedgeData, typename EdgeData, typename FaceData>
class DCEL{
public:
    
    struct Vertex{
        int ID;
        bool valid;
        int halfedge;
        VertexData data;
        
        Vertex():valid(true), halfedge(-1), ID(-1){};
    };
    
    struct Halfedge{
        int ID;
        bool valid;
        int vertex, face, edge;
        int next, prev, twin;
        HalfedgeData data;
        
        Halfedge():valid(true), vertex(-1), face(-1), edge(-1), next(-1), prev(-1), twin(-1){}
    };
    
    struct Edge{
        int ID;
        bool valid;
        int halfedge;
        EdgeData data;
        
        Edge():valid(true), halfedge(-1){}
    };
    
    struct Face{
        int ID;
        bool valid;
        int halfedge;
        FaceData data;
        
        Face():valid(true), halfedge(-1){}
    };
    
    std::vector<Vertex> vertices;
    std::vector<Halfedge> halfedges;
    std::vector<Edge> edges;
    std::vector<Face> faces;
    
    DCEL(){}
    ~DCEL(){}
    
    struct TwinFinder{
        int index;
        int v1,v2;
        
        TwinFinder(int i, int vv1, int vv2):index(i), v1(vv1), v2(vv2){}
        ~TwinFinder(){}
        
        const bool operator<(const TwinFinder& tf) const
        {
            if (v1<tf.v1) return false;
            if (v1>tf.v1) return true;
            
            if (v2<tf.v2) return false;
            if (v2>tf.v2) return true;
            
            return false;
        }
    };

    bool valid_vertex_index(const int index) const {
      return index >= 0 && index < static_cast<int>(vertices.size());
    }

    bool valid_halfedge_index(const int index) const {
      return index >= 0 && index < static_cast<int>(halfedges.size());
    }

    bool valid_edge_index(const int index) const {
      return index >= 0 && index < static_cast<int>(edges.size());
    }

    bool valid_face_index(const int index) const {
      return index >= 0 && index < static_cast<int>(faces.size());
    }

    bool valid_vertex(const int index) const {
      return valid_vertex_index(index) && vertices[index].valid;
    }

    bool valid_halfedge(const int index) const {
      return valid_halfedge_index(index) && halfedges[index].valid;
    }

    bool valid_edge(const int index) const {
      return valid_edge_index(index) && edges[index].valid;
    }

    bool valid_face(const int index) const {
      return valid_face_index(index) && faces[index].valid;
    }

    bool rebuild_representative_halfedges(
        const bool verbose = false,
        const bool invalidateIsolatedVertices = true) {
      const int vertexCount = static_cast<int>(vertices.size());
      const int halfedgeCount = static_cast<int>(halfedges.size());
      const int edgeCount = static_cast<int>(edges.size());
      const int faceCount = static_cast<int>(faces.size());

      const auto fail = [&](const char *message, const int index = -1) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::"
                       "rebuild_representative_halfedges()]: "
                    << message;

          if (index >= 0)
            std::cerr << " (index " << index << ")";

          std::cerr << '\n';
        }

        return false;
      };

      for (Vertex &vertex : vertices)
        vertex.halfedge = -1;

      for (Edge &edge : edges)
        edge.halfedge = -1;

      for (Face &face : faces)
        face.halfedge = -1;

      for (int he = 0; he < halfedgeCount; ++he) {
        if (!halfedges[he].valid)
          continue;

        const int vertex = halfedges[he].vertex;
        const int edge = halfedges[he].edge;
        const int face = halfedges[he].face;

        if (!valid_vertex(vertex)) {
          return fail("valid halfedge references invalid vertex", he);
        }

        if (!valid_edge(edge)) {
          return fail("valid halfedge references invalid edge", he);
        }

        if (!valid_face(face)) {
          return fail("valid halfedge references invalid face", he);
        }

        if (vertices[vertex].halfedge < 0)
          vertices[vertex].halfedge = he;

        if (edges[edge].halfedge < 0)
          edges[edge].halfedge = he;

        if (faces[face].halfedge < 0)
          faces[face].halfedge = he;
      }

      for (int vertex = 0; vertex < vertexCount; ++vertex) {
        if (!vertices[vertex].valid)
          continue;

        if (vertices[vertex].halfedge >= 0)
          continue;

        if (invalidateIsolatedVertices) {
          vertices[vertex].valid = false;
          continue;
        }

        return fail("valid vertex has no valid outgoing halfedge", vertex);
      }

      for (int edge = 0; edge < edgeCount; ++edge) {
        if (!edges[edge].valid)
          continue;

        if (edges[edge].halfedge < 0) {
          return fail("valid edge has no valid representative halfedge", edge);
        }
      }

      for (int face = 0; face < faceCount; ++face) {
        if (!faces[face].valid)
          continue;

        if (faces[face].halfedge < 0) {
          return fail("valid face has no valid representative halfedge", face);
        }
      }

      return true;
    }

    bool collect_face_cycle(const int faceIndex, std::vector<int> &cycle,
                            const bool verbose = false) const {
      cycle.clear();

      const int halfedgeCount = static_cast<int>(halfedges.size());

      const auto fail = [&](const char *message, const int index = -1) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::collect_face_cycle()]: " << message;

          if (index >= 0)
            std::cerr << " (index " << index << ")";

          std::cerr << '\n';
        }

        cycle.clear();
        return false;
      };

      if (!valid_face(faceIndex)) {
        return fail("invalid face", faceIndex);
      }

      const int start = faces[faceIndex].halfedge;

      if (!valid_halfedge(start)) {
        return fail("face references invalid starting halfedge", start);
      }

      std::vector<unsigned char> visited(
          static_cast<std::size_t>(halfedgeCount),
          static_cast<unsigned char>(0));

      int current = start;

      for (int step = 0; step < halfedgeCount; ++step) {
        if (!valid_halfedge(current)) {
          return fail("face walk reached invalid halfedge", current);
        }

        if (visited[current]) {
          if (current == start)
            return !cycle.empty();

          return fail("face walk entered non-start cycle", current);
        }

        if (halfedges[current].face != faceIndex) {
          return fail("face cycle contains halfedge owned by another face",
                      current);
        }

        visited[current] = 1;
        cycle.push_back(current);

        const int next = halfedges[current].next;

        if (!valid_halfedge(next)) {
          return fail("face cycle has invalid next link", current);
        }

        if (halfedges[next].prev != current) {
          return fail("next.prev does not point back", next);
        }

        current = next;

        if (current == start) {
          return true;
        }
      }

      return fail("face cycle exceeded traversal bound", start);
    }

    bool retire_halfedge(const int halfedgeIndex, const bool verbose = false) {
      const auto fail = [&](const char *message, const int index = -1) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::retire_halfedge()]: " << message;

          if (index >= 0)
            std::cerr << " (index " << index << ")";

          std::cerr << '\n';
        }

        return false;
      };

      if (!valid_halfedge(halfedgeIndex)) {
        return fail("cannot retire invalid halfedge", halfedgeIndex);
      }

      Halfedge &halfedge = halfedges[halfedgeIndex];

      const int twin = halfedge.twin;
      const int edge = halfedge.edge;

      if (!valid_edge(edge)) {
        return fail("halfedge references invalid edge", halfedgeIndex);
      }

      if (twin < -1) {
        return fail("halfedge has invalid negative twin", halfedgeIndex);
      }

      if (twin >= 0) {
        if (!valid_halfedge(twin)) {
          return fail("halfedge references invalid twin", halfedgeIndex);
        }

        if (halfedges[twin].twin != halfedgeIndex) {
          return fail("halfedge twin relation is not mutual", halfedgeIndex);
        }

        halfedges[twin].twin = -1;

        edges[edge].valid = true;
        edges[edge].halfedge = twin;
      } else {
        edges[edge].valid = false;
        edges[edge].halfedge = -1;
      }

      halfedge.twin = -1;
      halfedge.valid = false;

      return true;
    }

    bool remove_degenerate_edge(const int halfedgeIndex,
                                const bool verbose = false) {
      /*
       * One transaction covers both sides of the degenerate edge.
       * No intermediate consistency check is performed while only one
       * side has been removed.
       */
      const auto oldVertices = vertices;
      const auto oldHalfedges = halfedges;
      const auto oldEdges = edges;
      const auto oldFaces = faces;

      const auto rollback = [&]() {
        vertices = oldVertices;
        halfedges = oldHalfedges;
        edges = oldEdges;
        faces = oldFaces;
      };

      const auto fail = [&](const char *message, const int index = -1) -> bool {
        rollback();

        if (verbose) {
          std::cerr << "[Directional::DCEL::"
                       "remove_degenerate_edge()]: "
                    << message;

          if (index >= 0) {
            std::cerr << " (index " << index << ")";
          }

          std::cerr << '\n';
        }

        return false;
      };

      const int halfedgeCount = static_cast<int>(halfedges.size());

      const int edgeCount = static_cast<int>(edges.size());

      /*
       * Describes what must happen to one incident face.
       *
       * If removeWholeFace is true, every halfedge in cycle is removed.
       * Otherwise only targetHalfedge is spliced from the face cycle.
       */
      struct SideAction {
        int targetHalfedge = -1;
        int face = -1;
        bool removeWholeFace = false;
        std::vector<int> cycle;
      };

      /*
       * ------------------------------------------------------------
       * 1. Validate the requested degenerate halfedge.
       * ------------------------------------------------------------
       */
      if (!valid_halfedge(halfedgeIndex)) {
        return fail("invalid input halfedge", halfedgeIndex);
      }

      const int primaryNext = halfedges[halfedgeIndex].next;

      if (!valid_halfedge(primaryNext)) {
        return fail("input halfedge has an invalid next link", halfedgeIndex);
      }

      /*
       * In this DCEL representation, halfedge.vertex is the origin and
       * halfedge.next.vertex is the target. Equal vertices imply a
       * zero-length edge.
       */
      if (halfedges[halfedgeIndex].vertex != halfedges[primaryNext].vertex) {
        return fail("input halfedge is not geometrically degenerate",
                    halfedgeIndex);
      }

      const int originalTwin = halfedges[halfedgeIndex].twin;

      const int originalEdge = halfedges[halfedgeIndex].edge;

      if (!valid_edge(originalEdge)) {
        return fail("input halfedge references an invalid edge", halfedgeIndex);
      }

      if (originalTwin < -1) {
        return fail("input halfedge has an invalid negative twin",
                    halfedgeIndex);
      }

      if (originalTwin >= 0) {
        if (!valid_halfedge(originalTwin)) {
          return fail("input halfedge references an invalid twin",
                      originalTwin);
        }

        if (halfedges[originalTwin].twin != halfedgeIndex) {
          return fail("input twin relation is not mutual", halfedgeIndex);
        }

        if (halfedges[originalTwin].edge != originalEdge) {
          return fail("input halfedge and twin reference different edges",
                      halfedgeIndex);
        }

        const int twinNext = halfedges[originalTwin].next;

        if (!valid_halfedge(twinNext)) {
          return fail("twin halfedge has an invalid next link", originalTwin);
        }

        /*
         * A true zero-length edge must be degenerate on both sides.
         */
        if (halfedges[originalTwin].vertex != halfedges[twinNext].vertex) {
          return fail("twin halfedge is not geometrically degenerate",
                      originalTwin);
        }
      }

      /*
       * ------------------------------------------------------------
       * 2. Build and validate the action for each incident side.
       * ------------------------------------------------------------
       */
      std::vector<SideAction> actions;
      actions.reserve(originalTwin >= 0 ? 2u : 1u);

      const auto prepareSide = [&](const int targetHalfedge) -> bool {
        if (!valid_halfedge(targetHalfedge)) {
          return false;
        }

        SideAction action;
        action.targetHalfedge = targetHalfedge;
        action.face = halfedges[targetHalfedge].face;

        if (!valid_face(action.face)) {
          return false;
        }

        if (!collect_face_cycle(action.face, action.cycle, verbose)) {
          return false;
        }

        if (action.cycle.size() < 3) {
          return false;
        }

        const auto targetIterator =
            std::find(action.cycle.begin(), action.cycle.end(), targetHalfedge);

        if (targetIterator == action.cycle.end()) {
          return false;
        }

        if (std::count(action.cycle.begin(), action.cycle.end(),
                       targetHalfedge) != 1) {
          return false;
        }

        const int prev = halfedges[targetHalfedge].prev;

        const int next = halfedges[targetHalfedge].next;

        if (!valid_halfedge(prev) || !valid_halfedge(next)) {
          return false;
        }

        if (halfedges[prev].next != targetHalfedge) {
          return false;
        }

        if (halfedges[next].prev != targetHalfedge) {
          return false;
        }

        if (halfedges[prev].face != action.face ||
            halfedges[next].face != action.face) {
          return false;
        }

        /*
         * Confirm that this specific halfedge is zero-length.
         */
        if (halfedges[targetHalfedge].vertex != halfedges[next].vertex) {
          return false;
        }

        /*
         * Removing one halfedge from a triangle would leave a
         * two-halfedge face, so remove the entire triangle instead.
         */
        action.removeWholeFace = action.cycle.size() <= 3;

        actions.push_back(std::move(action));
        return true;
      };

      if (!prepareSide(halfedgeIndex)) {
        return fail("failed to validate the primary incident face",
                    halfedgeIndex);
      }

      if (originalTwin >= 0) {
        if (!prepareSide(originalTwin)) {
          return fail("failed to validate the twin incident face",
                      originalTwin);
        }

        /*
         * A twin pair should not ordinarily belong to the same face.
         * Supporting that topology would require a separate collapse
         * operation.
         */
        if (actions.size() == 2 && actions[0].face == actions[1].face) {
          return fail("degenerate twin halfedges belong to the same face",
                      actions[0].face);
        }
      }

      /*
       * ------------------------------------------------------------
       * 3. Build the complete halfedge-removal set.
       *
       * This is done before mutation so edge/twin repair decisions can
       * account for both incident sides and any triangle faces removed
       * in their entirety.
       * ------------------------------------------------------------
       */
      std::vector<unsigned char> removeHalfedge(
          static_cast<std::size_t>(halfedgeCount),
          static_cast<unsigned char>(0));

      std::vector<unsigned char> removeFace(faces.size(),
                                            static_cast<unsigned char>(0));

      for (const SideAction &action : actions) {
        if (action.removeWholeFace) {
          removeFace[action.face] = 1;

          for (const int he : action.cycle) {
            if (!valid_halfedge(he)) {
              return fail("triangle-removal cycle contains an invalid halfedge",
                          he);
            }

            removeHalfedge[he] = 1;
          }
        } else {
          removeHalfedge[action.targetHalfedge] = 1;
        }
      }

      /*
       * Validate every halfedge that will be removed, including unrelated
       * edges belonging to an incident triangle that must be deleted.
       */
      for (int he = 0; he < halfedgeCount; ++he) {
        if (!removeHalfedge[he]) {
          continue;
        }

        if (!valid_halfedge(he)) {
          return fail("removal set contains an invalid halfedge", he);
        }

        const int edge = halfedges[he].edge;

        const int twin = halfedges[he].twin;

        if (!valid_edge(edge)) {
          return fail("removal halfedge references an invalid edge", he);
        }

        if (twin < -1) {
          return fail("removal halfedge has an invalid negative twin", he);
        }

        if (twin >= 0) {
          if (!valid_halfedge(twin)) {
            return fail("removal halfedge references an invalid twin", he);
          }

          if (halfedges[twin].twin != he) {
            return fail("removal halfedge twin relation is not mutual", he);
          }

          if (halfedges[twin].edge != edge) {
            return fail("removal twin references a different edge", he);
          }
        }
      }

      /*
       * ------------------------------------------------------------
       * 4. Splice degenerate halfedges from surviving polygon faces.
       *
       * Do this before invalidating any halfedge. Both sides remain
       * available during validation and rewiring.
       * ------------------------------------------------------------
       */
      for (const SideAction &action : actions) {
        if (action.removeWholeFace) {
          continue;
        }

        const int target = action.targetHalfedge;

        const int prev = halfedges[target].prev;

        const int next = halfedges[target].next;

        /*
         * The side was already validated, but recheck before committing
         * because another action may share nearby topology.
         */
        if (!valid_halfedge(target) || !valid_halfedge(prev) ||
            !valid_halfedge(next)) {
          return fail("splice neighborhood became invalid before mutation",
                      target);
        }

        if (halfedges[prev].next != target || halfedges[next].prev != target) {
          return fail("splice neighborhood changed before mutation", target);
        }

        if (halfedges[target].vertex != halfedges[next].vertex) {
          return fail("splice target is no longer geometrically degenerate",
                      target);
        }

        halfedges[prev].next = next;
        halfedges[next].prev = prev;

        if (faces[action.face].halfedge == target) {
          faces[action.face].halfedge = next;
        }
      }

      /*
       * ------------------------------------------------------------
       * 5. Invalidate whole faces.
       * ------------------------------------------------------------
       */
      for (int face = 0; face < static_cast<int>(faces.size()); ++face) {
        if (!removeFace[face]) {
          continue;
        }

        if (!valid_face(face)) {
          return fail("face scheduled for removal became invalid", face);
        }

        faces[face].valid = false;
        faces[face].halfedge = -1;
      }

      /*
       * ------------------------------------------------------------
       * 6. Repair edge and twin records in one batch.
       *
       * Each edge is processed once. If exactly one side survives, that
       * halfedge becomes a boundary halfedge. If neither side survives,
       * the edge record is invalidated.
       * ------------------------------------------------------------
       */
      std::vector<unsigned char> processedEdge(
          static_cast<std::size_t>(edgeCount), static_cast<unsigned char>(0));

      for (int he = 0; he < halfedgeCount; ++he) {
        if (!removeHalfedge[he]) {
          continue;
        }

        const int edge = halfedges[he].edge;

        if (!valid_edge_index(edge)) {
          return fail("removed halfedge has an out-of-range edge", he);
        }

        if (processedEdge[edge]) {
          continue;
        }

        processedEdge[edge] = 1;

        const int twin = halfedges[he].twin;

        int survivingHalfedge = -1;

        if (twin >= 0 && !removeHalfedge[twin]) {
          survivingHalfedge = twin;
        }

        if (survivingHalfedge >= 0) {
          if (!valid_halfedge(survivingHalfedge)) {
            return fail("surviving twin is invalid", survivingHalfedge);
          }

          halfedges[survivingHalfedge].twin = -1;

          edges[edge].valid = true;
          edges[edge].halfedge = survivingHalfedge;
        } else {
          edges[edge].valid = false;
          edges[edge].halfedge = -1;
        }
      }

      /*
       * ------------------------------------------------------------
       * 7. Invalidate all scheduled halfedges.
       * ------------------------------------------------------------
       */
      for (int he = 0; he < halfedgeCount; ++he) {
        if (!removeHalfedge[he]) {
          continue;
        }

        halfedges[he].twin = -1;
        halfedges[he].valid = false;
      }

      /*
       * ------------------------------------------------------------
       * 8. Rebuild representative pointers once, after both sides and
       * all incident triangle faces have been fully processed.
       * ------------------------------------------------------------
       */
      if (!rebuild_representative_halfedges(verbose, true)) {
        return fail("failed to rebuild representative halfedges");
      }

      /*
       * ------------------------------------------------------------
       * 9. Validate only the final state.
       *
       * This is the key difference from the previous implementation:
       * no consistency check occurs after processing only one side of
       * an interior degenerate edge.
       * ------------------------------------------------------------
       */
      if (!check_consistency(verbose, true, true, false)) {
        return fail("final DCEL consistency check failed");
      }

      return true;
    }

    bool walk_boundary(
        int &currentHalfedge, const bool verbose = false,
        const char *context = "[Directional::DCEL::walk_boundary()]") {
      const int halfedgeCount = static_cast<int>(halfedges.size());

      const auto fail = [&](const char *message, const int index = -1) -> bool {
        if (verbose) {
          std::cerr << "[Directional::DCEL::walk_boundary()]: " << context
                    << ": " << message;

          if (index >= 0) {
            std::cerr << " (halfedge " << index << ")";
          }

          std::cerr << '\n';
        }

        return false;
      };

      if (halfedgeCount == 0) {
        return fail("DCEL contains no halfedges");
      }

      if (!valid_halfedge(currentHalfedge)) {
        return fail("invalid starting halfedge", currentHalfedge);
      }

      /*
       * Preserve the caller's index on failure.
       */
      const int originalHalfedge = currentHalfedge;
      int cursor = currentHalfedge;

      std::vector<unsigned char> visited(
          static_cast<std::size_t>(halfedgeCount),
          static_cast<unsigned char>(0));

      /*
       * At most one new halfedge may be visited per iteration.
       * Therefore halfedgeCount iterations are sufficient to
       * either reach a boundary or prove that traversal is cyclic.
       */
      for (int step = 0; step < halfedgeCount; ++step) {

        if (!valid_halfedge(cursor)) {
          currentHalfedge = originalHalfedge;
          return fail("walk reached an invalid halfedge", cursor);
        }

        if (visited[cursor]) {
          currentHalfedge = originalHalfedge;

          if (cursor == originalHalfedge) {
            return fail("walk returned to its starting halfedge "
                        "without reaching a boundary",
                        cursor);
          }

          return fail("walk entered a non-start cycle", cursor);
        }

        visited[cursor] = 1;

        const int next = halfedges[cursor].next;

        if (!valid_halfedge_index(next)) {
          currentHalfedge = originalHalfedge;
          return fail("halfedge has an out-of-range next link", cursor);
        }

        if (!halfedges[next].valid) {
          currentHalfedge = originalHalfedge;
          return fail("halfedge next link points to an invalid "
                      "halfedge",
                      cursor);
        }

        cursor = next;

        /*
         * The next halfedge is itself on the boundary.
         */
        const int twin = halfedges[cursor].twin;

        if (twin == -1) {
          currentHalfedge = cursor;
          return true;
        }

        if (twin < -1) {
          currentHalfedge = originalHalfedge;
          return fail("halfedge has an invalid negative twin", cursor);
        }

        if (!valid_halfedge_index(twin)) {
          currentHalfedge = originalHalfedge;
          return fail("halfedge has an out-of-range twin", cursor);
        }

        if (!halfedges[twin].valid) {
          currentHalfedge = originalHalfedge;
          return fail("halfedge twin points to an invalid "
                      "halfedge",
                      cursor);
        }

        if (halfedges[twin].twin != cursor) {
          currentHalfedge = originalHalfedge;
          return fail("halfedge twin relation is not mutual", cursor);
        }

        cursor = twin;
      }

      currentHalfedge = originalHalfedge;

      return fail("walk exceeded the halfedge traversal bound",
                  originalHalfedge);
    }

    bool stitch_twins(const bool verbose = false,
                      const bool clearExistingTwins = true) {
      /*
       * Rebuild twin links from directed halfedge endpoints.
       *
       * Boundary halfedges are left with twin == -1.
       * Interior halfedges are paired only when the exact reverse directed
       * edge is found. Invalid topology is reported instead of being
       * dereferenced blindly.
       */
      const int halfedgeCount = static_cast<int>(halfedges.size());

      const int vertexCount = static_cast<int>(vertices.size());

      const auto fail = [&](const std::string &message, const int he = -1) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::stitch_twins()]: " << message;

          if (he >= 0)
            std::cerr << " at halfedge " << he;

          std::cerr << std::endl;
        }

        return false;
      };

      /*
       * Existing twin links are often stale after topology edits.
       * Rebuilding from scratch is safer than trying to preserve them.
       */
      if (clearExistingTwins) {
        for (int i = 0; i < halfedgeCount; ++i) {
          if (halfedges[i].valid)
            halfedges[i].twin = -1;
        }
      }

      /*
       * Stores unmatched directed edges:
       *
       *     key = (source, target)
       *     value = halfedge index
       *
       * When we see the reverse key, we stitch the pair.
       */
      std::map<std::pair<int, int>, int> unmatched;

      for (int i = 0; i < halfedgeCount; ++i) {
        if (!halfedges[i].valid)
          continue;

        if (!clearExistingTwins && halfedges[i].twin >= 0) {
          continue;
        }

        const int next = halfedges[i].next;

        if (!valid_halfedge(next))
          return fail("invalid next link", i);

        const int source = halfedges[i].origin;
        const int target = halfedges[next].origin;

        if (!valid_vertex_index(source))
          return fail("invalid source/origin vertex", i);

        if (!valid_vertex_index(target))
          return fail("invalid target vertex from next halfedge", i);

        if (source == target)
          return fail("degenerate directed edge with identical endpoints", i);

        const std::pair<int, int> key(source, target);
        const std::pair<int, int> reverseKey(target, source);

        auto reverseIt = unmatched.find(reverseKey);

        if (reverseIt != unmatched.end()) {
          const int twin = reverseIt->second;

          if (!valid_halfedge(twin))
            return fail("stored reverse halfedge is invalid", i);

          halfedges[i].twin = twin;
          halfedges[twin].twin = i;

          unmatched.erase(reverseIt);
          continue;
        }

        /*
         * A duplicate directed edge means two faces use the same
         * orientation along the same edge. That is not a valid
         * orientable two-manifold DCEL relation for twin stitching.
         */
        if (unmatched.find(key) != unmatched.end()) {
          return fail("duplicate directed edge; non-manifold or inconsistent "
                      "orientation",
                      i);
        }

        unmatched.emplace(key, i);
      }

      /*
       * Validate all generated twin links. Unmatched entries in the map
       * are boundary halfedges and intentionally remain twin == -1.
       */
      for (int i = 0; i < halfedgeCount; ++i) {
        if (!halfedges[i].valid)
          continue;

        const int twin = halfedges[i].twin;

        if (twin < 0)
          continue;

        if (!valid_halfedge(twin))
          return fail("invalid generated twin", i);

        if (halfedges[twin].twin != i)
          return fail("generated twin link is not mutual", i);

        const int iNext = halfedges[i].next;
        const int tNext = halfedges[twin].next;

        if (!valid_halfedge(iNext) || !valid_halfedge(tNext)) {
          return fail("invalid next link while validating generated twin", i);
        }

        const int iSource = halfedges[i].origin;
        const int iTarget = halfedges[iNext].origin;

        const int tSource = halfedges[twin].origin;
        const int tTarget = halfedges[tNext].origin;

        if (iSource != tTarget || iTarget != tSource) {
          return fail("generated twin endpoints are not reversed", i);
        }
      }

      return true;
    }

    bool check_compact_storage(const bool verbose = false) const {
      const auto fail = [&](const char *message, const int index = -1) -> bool {
        if (verbose) {
          std::cerr << "[Directional::DCEL::check_compact_storage()]: "
                    << message;

          if (index >= 0) {
            std::cerr << " (index " << index << ")";
          }

          std::cerr << '\n';
        }

        return false;
      };

      for (int index = 0; index < static_cast<int>(vertices.size()); ++index) {
        if (!vertices[index].valid) {
          return fail("invalid vertex remains", index);
        }

        if (vertices[index].ID != index) {
          return fail("vertex ID does not equal storage index", index);
        }
      }

      for (int index = 0; index < static_cast<int>(halfedges.size()); ++index) {
        if (!halfedges[index].valid) {
          return fail("invalid halfedge remains", index);
        }

        if (halfedges[index].ID != index) {
          return fail("halfedge ID does not equal storage index", index);
        }
      }

      for (int index = 0; index < static_cast<int>(edges.size()); ++index) {
        if (!edges[index].valid) {
          return fail("invalid edge remains", index);
        }

        if (edges[index].ID != index) {
          return fail("edge ID does not equal storage index", index);
        }
      }

      for (int index = 0; index < static_cast<int>(faces.size()); ++index) {
        if (!faces[index].valid) {
          return fail("invalid face remains", index);
        }

        if (faces[index].ID != index) {
          return fail("face ID does not equal storage index", index);
        }
      }

      return true;
    }

    bool check_consistency(const bool verbose,
                           const bool checkHalfedgeRepetition = true,
                           const bool checkTwinGaps = true,
                           const bool checkPureBoundary = true) {
      const int vertexCount = static_cast<int>(vertices.size());
      const int halfedgeCount = static_cast<int>(halfedges.size());
      const int edgeCount = static_cast<int>(edges.size());
      const int faceCount = static_cast<int>(faces.size());

      const auto fail = [&](const std::string &message, const int index = -1) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::check_consistency()]: " << message;

          if (index >= 0)
            std::cerr << " " << index;

          std::cerr << '\n';
        }

        return false;
      };

      /*
       * Safely walk one face cycle.
       *
       * The callback is invoked only after all references for the
       * current halfedge have been validated.
       */
      const auto walkFace = [&](const int faceIndex, auto &&callback) -> bool {
        if (!valid_face_index(faceIndex))
          return fail("invalid face index", faceIndex);

        if (!faces[faceIndex].valid)
          return fail("attempted to walk invalid face", faceIndex);

        const int start = faces[faceIndex].halfedge;

        if (!valid_halfedge_index(start))
          return fail("face references out-of-range halfedge", start);

        if (!halfedges[start].valid)
          return fail("face references invalid halfedge", start);

        std::vector<unsigned char> visited(
            static_cast<std::size_t>(halfedgeCount), 0);

        int current = start;

        for (int step = 0; step < halfedgeCount; ++step) {
          if (!valid_halfedge_index(current))
            return fail("face walk reached out-of-range halfedge", current);

          if (!halfedges[current].valid)
            return fail("face walk reached invalid halfedge", current);

          if (visited[current]) {
            if (current == start)
              return true;

            return fail("face walk entered a cycle that does not "
                        "return to its starting halfedge",
                        current);
          }

          visited[current] = 1;

          if (halfedges[current].face != faceIndex)
            return fail("halfedge in face cycle points to another face",
                        current);

          callback(current);

          const int next = halfedges[current].next;

          if (!valid_halfedge_index(next))
            return fail("face walk encountered invalid next index", next);

          current = next;

          if (current == start)
            return true;
        }

        return fail("face walk exceeded the halfedge safety bound", faceIndex);
      };

      // ---------------------------------------------------------
      // 1. Validate vertices.
      // ---------------------------------------------------------

      for (int i = 0; i < vertexCount; ++i) {
        if (!vertices[i].valid)
          continue;

        const int he = vertices[i].halfedge;

        if (!valid_halfedge_index(he))
          return fail("valid vertex references out-of-range halfedge", i);

        if (!halfedges[he].valid)
          return fail("valid vertex references invalid halfedge", i);

        if (halfedges[he].vertex != i)
          return fail("vertex incident halfedge does not point back", i);
      }

      // ---------------------------------------------------------
      // 2. Validate halfedges.
      // ---------------------------------------------------------

      for (int i = 0; i < halfedgeCount; ++i) {
        if (!halfedges[i].valid)
          continue;

        const int next = halfedges[i].next;
        const int prev = halfedges[i].prev;
        const int twin = halfedges[i].twin;
        const int vertex = halfedges[i].vertex;
        const int face = halfedges[i].face;
        const int edge = halfedges[i].edge;

        // Validate every index before dereferencing it.
        if (!valid_halfedge_index(next))
          return fail("halfedge has out-of-range next", i);

        if (!valid_halfedge_index(prev))
          return fail("halfedge has out-of-range prev", i);

        if (!valid_vertex_index(vertex))
          return fail("halfedge has out-of-range origin vertex", i);

        if (!valid_face_index(face))
          return fail("halfedge has out-of-range face", i);

        if (!valid_edge_index(edge))
          return fail("halfedge has out-of-range edge", i);

        if (!halfedges[next].valid)
          return fail("halfedge next points to invalid halfedge", i);

        if (!halfedges[prev].valid)
          return fail("halfedge prev points to invalid halfedge", i);

        if (!vertices[vertex].valid)
          return fail("halfedge origin vertex is invalid", i);

        if (!faces[face].valid)
          return fail("halfedge face is invalid", i);

        if (!edges[edge].valid)
          return fail("halfedge edge is invalid", i);

        if (halfedges[next].prev != i)
          return fail("halfedge next does not point back through prev", i);

        if (halfedges[prev].next != i)
          return fail("halfedge prev does not point back through next", i);

        if (halfedges[next].vertex == vertex)
          return fail("halfedge is geometrically degenerate", i);

        if (twin < -1)
          return fail("halfedge has an invalid negative twin value", i);

        if (twin >= 0) {
          if (!valid_halfedge_index(twin))
            return fail("halfedge has out-of-range twin", i);

          if (!halfedges[twin].valid)
            return fail("halfedge twin is invalid", i);

          if (halfedges[twin].twin != i)
            return fail("halfedge twin does not point back", i);

          const int twinNext = halfedges[twin].next;

          if (!valid_halfedge_index(twinNext))
            return fail("twin halfedge has out-of-range next", twin);

          if (!halfedges[twinNext].valid)
            return fail("twin halfedge next is invalid", twin);

          const int source = vertex;
          const int target = halfedges[next].vertex;

          const int twinSource = halfedges[twin].vertex;

          const int twinTarget = halfedges[twinNext].vertex;

          if (source != twinTarget || target != twinSource) {
            return fail("twin halfedges do not have reversed endpoints", i);
          }
        }

        if (prev == twin && twin >= 0)
          return fail("halfedge prev and twin are identical", i);

        if (next == twin && twin >= 0)
          return fail("halfedge next and twin are identical", i);
      }

      // ---------------------------------------------------------
      // 3. Validate edges.
      // ---------------------------------------------------------

      for (int i = 0; i < edgeCount; ++i) {
        if (!edges[i].valid)
          continue;

        const int he = edges[i].halfedge;

        if (!valid_halfedge_index(he))
          return fail("edge references out-of-range halfedge", i);

        if (!halfedges[he].valid)
          return fail("edge references invalid halfedge", i);

        if (halfedges[he].edge != i)
          return fail("edge halfedge does not point back", i);

        const int twin = halfedges[he].twin;

        if (twin >= 0) {
          if (!valid_halfedge_index(twin))
            return fail("edge halfedge has invalid twin", i);

          if (!halfedges[twin].valid)
            return fail("edge halfedge twin is invalid", i);

          if (halfedges[twin].edge != i)
            return fail("both halfedges of an edge do not share "
                        "the same edge record",
                        i);
        }
      }

      // ---------------------------------------------------------
      // 4. Validate face cycles and collect membership.
      // ---------------------------------------------------------

      std::vector<std::set<int>> halfedgesInFace(
          static_cast<std::size_t>(faceCount));

      std::vector<std::set<int>> verticesInFace(
          static_cast<std::size_t>(faceCount));

      for (int faceIndex = 0; faceIndex < faceCount; ++faceIndex) {
        if (!faces[faceIndex].valid)
          continue;

        const bool walkSucceeded = walkFace(faceIndex, [&](const int he) {
          const int vertex = halfedges[he].vertex;

          if (!valid_vertex_index(vertex))
            return;

          if (verbose && verticesInFace[faceIndex].count(vertex) != 0) {
            std::cerr << "[Directional::DCEL::"
                         "check_consistency()]: "
                      << "vertex " << vertex
                      << " appears more than once in face " << faceIndex
                      << '\n';
          }

          verticesInFace[faceIndex].insert(vertex);
          halfedgesInFace[faceIndex].insert(he);
        });

        if (!walkSucceeded)
          return false;
      }

      // Every valid halfedge must be in its face's actual cycle.
      for (int i = 0; i < halfedgeCount; ++i) {
        if (!halfedges[i].valid)
          continue;

        const int face = halfedges[i].face;

        if (!valid_face_index(face))
          return fail("halfedge references invalid face while checking "
                      "floating halfedges",
                      i);

        if (halfedgesInFace[face].count(i) == 0)
          return fail("halfedge is floating outside its face cycle", i);
      }

      // ---------------------------------------------------------
      // 5. Detect repeated directed halfedges.
      // ---------------------------------------------------------

      if (checkHalfedgeRepetition) {
        std::map<std::pair<int, int>, int> directedEdges;

        for (int i = 0; i < halfedgeCount; ++i) {
          if (!halfedges[i].valid)
            continue;

          const int next = halfedges[i].next;

          // Already validated above, but do not rely on that
          // ordering if this block is later moved.
          if (!valid_halfedge_index(next) || !halfedges[next].valid) {
            return fail("invalid next while checking repeated edges", i);
          }

          const int source = halfedges[i].vertex;

          const int target = halfedges[next].vertex;

          const auto key = std::make_pair(source, target);

          const auto existing = directedEdges.find(key);

          if (existing != directedEdges.end()) {
            if (verbose) {
              std::cerr << "[Directional::DCEL::"
                           "check_consistency()]: "
                        << "directed edge (" << source << ", " << target
                        << ") appears in halfedges " << existing->second
                        << " and " << i << '\n';
            }

            return false;
          }

          directedEdges.emplace(key, i);
        }
      }

      // ---------------------------------------------------------
      // 6. Detect reverse-edge twin gaps.
      // ---------------------------------------------------------

      if (checkTwinGaps) {
        std::map<std::pair<int, int>, int> unmatched;

        for (int i = 0; i < halfedgeCount; ++i) {
          if (!halfedges[i].valid)
            continue;

          const int next = halfedges[i].next;

          if (!valid_halfedge_index(next) || !halfedges[next].valid) {
            return fail("invalid next while checking twin gaps", i);
          }

          const int source = halfedges[i].vertex;

          const int target = halfedges[next].vertex;

          const auto reverseKey = std::make_pair(target, source);

          const auto reverse = unmatched.find(reverseKey);

          if (reverse != unmatched.end()) {
            const int other = reverse->second;

            if (halfedges[i].twin != other || halfedges[other].twin != i) {
              if (verbose) {
                std::cerr << "[Directional::DCEL::"
                             "check_consistency()]: "
                          << "halfedges " << i << " and " << other
                          << " have reversed endpoints but are "
                             "not mutual twins\n";
              }

              return false;
            }

            unmatched.erase(reverse);
          } else {
            unmatched.emplace(std::make_pair(source, target), i);
          }
        }
      }

      // ---------------------------------------------------------
      // 7. Optional pure-boundary face test.
      // ---------------------------------------------------------

      if (checkPureBoundary) {
        for (int faceIndex = 0; faceIndex < faceCount; ++faceIndex) {
          if (!faces[faceIndex].valid)
            continue;

          bool hasInteriorEdge = false;

          const bool walkSucceeded = walkFace(faceIndex, [&](const int he) {
            // Twin index zero is valid.
            if (halfedges[he].twin >= 0)
              hasInteriorEdge = true;
          });

          if (!walkSucceeded)
            return false;

          if (!hasInteriorEdge)
            return fail("face is composed entirely of boundary edges",
                        faceIndex);
        }
      }

      return true;
    }

    /**
     * Compact the DCEL by removing invalid entities and remapping every
     * surviving reference.
     *
     * The operation is transactional:
     *
     *   1. Validate the current DCEL.
     *   2. Build old-to-new translation tables initialized to -1.
     *   3. Construct a separate compacted DCEL.
     *   4. Remap and validate every surviving reference.
     *   5. Run a strict consistency check on the compacted DCEL.
     *   6. Commit with vector swaps only after every check succeeds.
     *
     * On failure the original DCEL remains unchanged.
     */
    bool clean_mesh(const bool verbose = false,
                    const bool checkPureBoundaryFaces = true) {
      const int oldVertexCount = static_cast<int>(vertices.size());
      const int oldHalfedgeCount = static_cast<int>(halfedges.size());
      const int oldEdgeCount = static_cast<int>(edges.size());
      const int oldFaceCount = static_cast<int>(faces.size());

      const auto fail = [&](const std::string &message,
                            const int index = -1) -> bool {
        if (verbose) {
          std::cerr << "[Directional::DCEL::clean_mesh()]: " << message;

          if (index >= 0) {
            std::cerr << " (index " << index << ")";
          }

          std::cerr << '\n';
        }

        return false;
      };

      /*
       * The current topology must be fully valid before compaction.
       *
       * Compaction is not a repair operation. It only removes records that
       * have already been marked invalid and updates surviving indices.
       */
      if (!check_consistency(verbose, true, true, checkPureBoundaryFaces)) {
        return fail("pre-compaction consistency check failed");
      }

      /*
       * Translation arrays use -1 as the unmapped sentinel.
       *
       * This is important: zero is a valid compacted index and must never
       * serve as an implicit fallback.
       */
      std::vector<int> vertexMap(static_cast<std::size_t>(oldVertexCount), -1);

      std::vector<int> halfedgeMap(static_cast<std::size_t>(oldHalfedgeCount),
                                   -1);

      std::vector<int> edgeMap(static_cast<std::size_t>(oldEdgeCount), -1);

      std::vector<int> faceMap(static_cast<std::size_t>(oldFaceCount), -1);

      int newVertexCount = 0;
      int newHalfedgeCount = 0;
      int newEdgeCount = 0;
      int newFaceCount = 0;

      for (int oldIndex = 0; oldIndex < oldVertexCount; ++oldIndex) {
        if (vertices[oldIndex].valid) {
          vertexMap[oldIndex] = newVertexCount++;
        }
      }

      for (int oldIndex = 0; oldIndex < oldHalfedgeCount; ++oldIndex) {
        if (halfedges[oldIndex].valid) {
          halfedgeMap[oldIndex] = newHalfedgeCount++;
        }
      }

      for (int oldIndex = 0; oldIndex < oldEdgeCount; ++oldIndex) {
        if (edges[oldIndex].valid) {
          edgeMap[oldIndex] = newEdgeCount++;
        }
      }

      for (int oldIndex = 0; oldIndex < oldFaceCount; ++oldIndex) {
        if (faces[oldIndex].valid) {
          faceMap[oldIndex] = newFaceCount++;
        }
      }

      /*
       * Build a separate candidate DCEL. The live topology is not changed
       * until this candidate has passed strict validation.
       */
      DCEL compacted;

      compacted.vertices.reserve(static_cast<std::size_t>(newVertexCount));

      compacted.halfedges.reserve(static_cast<std::size_t>(newHalfedgeCount));

      compacted.edges.reserve(static_cast<std::size_t>(newEdgeCount));

      compacted.faces.reserve(static_cast<std::size_t>(newFaceCount));

      /*
       * Copy surviving records first. References are remapped in a separate
       * phase so that all translation tables are already complete.
       */
      for (int oldIndex = 0; oldIndex < oldVertexCount; ++oldIndex) {
        if (vertexMap[oldIndex] < 0) {
          continue;
        }

        Vertex vertex = vertices[oldIndex];
        vertex.ID = vertexMap[oldIndex];
        vertex.valid = true;

        compacted.vertices.push_back(std::move(vertex));
      }

      for (int oldIndex = 0; oldIndex < oldHalfedgeCount; ++oldIndex) {
        if (halfedgeMap[oldIndex] < 0) {
          continue;
        }

        Halfedge halfedge = halfedges[oldIndex];
        halfedge.ID = halfedgeMap[oldIndex];
        halfedge.valid = true;

        compacted.halfedges.push_back(std::move(halfedge));
      }

      for (int oldIndex = 0; oldIndex < oldEdgeCount; ++oldIndex) {
        if (edgeMap[oldIndex] < 0) {
          continue;
        }

        Edge edge = edges[oldIndex];
        edge.ID = edgeMap[oldIndex];
        edge.valid = true;

        compacted.edges.push_back(std::move(edge));
      }

      for (int oldIndex = 0; oldIndex < oldFaceCount; ++oldIndex) {
        if (faceMap[oldIndex] < 0) {
          continue;
        }

        Face face = faces[oldIndex];
        face.ID = faceMap[oldIndex];
        face.valid = true;

        compacted.faces.push_back(std::move(face));
      }

      const auto mappedVertex = [&](const int oldIndex, const char *context,
                                    const int owner) -> int {
        if (!valid_vertex_index(oldIndex) || vertexMap[oldIndex] < 0) {
          if (verbose) {
            std::cerr << "[Directional::DCEL::clean_mesh()]: " << context
                      << " references an invalid or removed vertex " << oldIndex
                      << " (owner " << owner << ")\n";
          }

          return -1;
        }

        return vertexMap[oldIndex];
      };

      const auto mappedHalfedge = [&](const int oldIndex, const char *context,
                                      const int owner) -> int {
        if (!valid_halfedge_index(oldIndex) || halfedgeMap[oldIndex] < 0) {
          if (verbose) {
            std::cerr << "[Directional::DCEL::clean_mesh()]: " << context
                      << " references an invalid or removed halfedge "
                      << oldIndex << " (owner " << owner << ")\n";
          }

          return -1;
        }

        return halfedgeMap[oldIndex];
      };

      const auto mappedEdge = [&](const int oldIndex, const char *context,
                                  const int owner) -> int {
        if (!valid_edge_index(oldIndex) || edgeMap[oldIndex] < 0) {
          if (verbose) {
            std::cerr << "[Directional::DCEL::clean_mesh()]: " << context
                      << " references an invalid or removed edge " << oldIndex
                      << " (owner " << owner << ")\n";
          }

          return -1;
        }

        return edgeMap[oldIndex];
      };

      const auto mappedFace = [&](const int oldIndex, const char *context,
                                  const int owner) -> int {
        if (!valid_face_index(oldIndex) || faceMap[oldIndex] < 0) {
          if (verbose) {
            std::cerr << "[Directional::DCEL::clean_mesh()]: " << context
                      << " references an invalid or removed face " << oldIndex
                      << " (owner " << owner << ")\n";
          }

          return -1;
        }

        return faceMap[oldIndex];
      };

      /*
       * Remap vertex representatives.
       */
      for (int oldIndex = 0; oldIndex < oldVertexCount; ++oldIndex) {
        const int newIndex = vertexMap[oldIndex];

        if (newIndex < 0) {
          continue;
        }

        const int newHalfedge = mappedHalfedge(
            vertices[oldIndex].halfedge, "vertex representative", oldIndex);

        if (newHalfedge < 0) {
          return false;
        }

        compacted.vertices[newIndex].halfedge = newHalfedge;
      }

      /*
       * Remap face representatives.
       */
      for (int oldIndex = 0; oldIndex < oldFaceCount; ++oldIndex) {
        const int newIndex = faceMap[oldIndex];

        if (newIndex < 0) {
          continue;
        }

        const int newHalfedge = mappedHalfedge(faces[oldIndex].halfedge,
                                               "face representative", oldIndex);

        if (newHalfedge < 0) {
          return false;
        }

        compacted.faces[newIndex].halfedge = newHalfedge;
      }

      /*
       * Remap edge representatives.
       */
      for (int oldIndex = 0; oldIndex < oldEdgeCount; ++oldIndex) {
        const int newIndex = edgeMap[oldIndex];

        if (newIndex < 0) {
          continue;
        }

        const int newHalfedge = mappedHalfedge(edges[oldIndex].halfedge,
                                               "edge representative", oldIndex);

        if (newHalfedge < 0) {
          return false;
        }

        compacted.edges[newIndex].halfedge = newHalfedge;
      }

      /*
       * Remap every surviving halfedge reference.
       */
      for (int oldIndex = 0; oldIndex < oldHalfedgeCount; ++oldIndex) {
        const int newIndex = halfedgeMap[oldIndex];

        if (newIndex < 0) {
          continue;
        }

        const Halfedge &oldHalfedge = halfedges[oldIndex];
        Halfedge &newHalfedge = compacted.halfedges[newIndex];

        const int vertex =
            mappedVertex(oldHalfedge.vertex, "halfedge origin", oldIndex);

        const int face =
            mappedFace(oldHalfedge.face, "halfedge face", oldIndex);

        const int edge =
            mappedEdge(oldHalfedge.edge, "halfedge edge", oldIndex);

        const int next =
            mappedHalfedge(oldHalfedge.next, "halfedge next", oldIndex);

        const int prev =
            mappedHalfedge(oldHalfedge.prev, "halfedge prev", oldIndex);

        if (vertex < 0 || face < 0 || edge < 0 || next < 0 || prev < 0) {
          return false;
        }

        int twin = -1;

        if (oldHalfedge.twin >= 0) {
          twin = mappedHalfedge(oldHalfedge.twin, "halfedge twin", oldIndex);

          if (twin < 0) {
            return false;
          }
        } else if (oldHalfedge.twin != -1) {
          return fail("surviving halfedge has invalid negative twin", oldIndex);
        }

        newHalfedge.vertex = vertex;
        newHalfedge.face = face;
        newHalfedge.edge = edge;
        newHalfedge.next = next;
        newHalfedge.prev = prev;
        newHalfedge.twin = twin;
      }

      /*
       * Rebuild representatives from the compacted halfedges instead of
       * trusting that copied representative choices remain ideal.
       *
       * false means that an isolated valid vertex is treated as an error,
       * not silently invalidated after the translation maps were finalized.
       */
      if (!compacted.rebuild_representative_halfedges(verbose, false)) {
        return fail("failed to rebuild compacted representative "
                    "halfedges");
      }

      /*
       * Validate IDs and validity flags explicitly. check_consistency()
       * verifies topology, but IDs are an additional storage invariant.
       */
      if (!compacted.check_compact_storage(verbose)) {
        return fail("candidate storage is not compact");
      }

      /*
       * Strict post-compaction validation occurs before commit.
       */
      if (!compacted.check_consistency(verbose, true, true,
                                       checkPureBoundaryFaces)) {
        return fail("compacted candidate failed consistency check");
      }

      /*
       * Commit. Vector swaps are effectively non-throwing for standard
       * allocators and leave no partially compacted live DCEL.
       */
      vertices.swap(compacted.vertices);
      halfedges.swap(compacted.halfedges);
      edges.swap(compacted.edges);
      faces.swap(compacted.faces);

      return true;
    }

    void ComputeTwins() {
        //twinning up edges
        std::set <TwinFinder> Twinning;
        for (int i = 0; i < halfedges.size(); i++) {
            if (halfedges[i].twin >= 0)
                continue;
            
            typename std::set<TwinFinder>::iterator Twinit = Twinning.find(
                                                                           TwinFinder(0, halfedges[halfedges[i].next].vertex, halfedges[i].vertex));
            if (Twinit != Twinning.end()) {
                halfedges[Twinit->index].twin = i;
                halfedges[i].twin = Twinit->index;
                Twinning.erase(*Twinit);
            } else {
                Twinning.insert(TwinFinder(i, halfedges[i].vertex, halfedges[halfedges[i].next].vertex));
            }
        }
    }
    
    bool JoinFace(const int heindex) {
      const int twin = halfedges[heindex].twin;

      if (twin < 0) {
        return true;
      }

      const int face1 = halfedges[heindex].face;
      const int face2 = halfedges[twin].face;

      /*
       * Spike edge: remove both halfedges and the vertex collapsed by the
       * spike, but keep the remaining face.
       */
      if (halfedges[heindex].prev == twin || halfedges[heindex].next == twin) {
        int closeEdge = heindex;

        if (halfedges[heindex].prev == twin) {
          closeEdge = twin;
        }

        const int closeTwin = halfedges[closeEdge].twin;

        halfedges[closeEdge].valid = false;
        halfedges[closeTwin].valid = false;
        edges[halfedges[closeEdge].edge].valid = false;

        vertices[halfedges[closeEdge].vertex].halfedge =
            halfedges[closeTwin].next;

        faces[face1].halfedge = halfedges[closeEdge].prev;

        halfedges[halfedges[closeEdge].prev].next = halfedges[closeTwin].next;
        halfedges[halfedges[closeTwin].next].prev = halfedges[closeEdge].prev;

        vertices[halfedges[closeTwin].vertex].valid = false;

        return true;
      }

      /*
       * Do not remove non-spike edges whose two sides belong to the same face:
       * that can disconnect a chain.
       */
      if (face1 == face2) {
        return false;
      }

      faces[face1].halfedge = halfedges[heindex].next;
      faces[face2].valid = false;

      halfedges[heindex].valid = false;
      halfedges[twin].valid = false;

      halfedges[halfedges[heindex].next].prev = halfedges[twin].prev;
      halfedges[halfedges[twin].prev].next = halfedges[heindex].next;

      halfedges[halfedges[twin].next].prev = halfedges[heindex].prev;
      halfedges[halfedges[heindex].prev].next = halfedges[twin].next;

      vertices[halfedges[heindex].vertex].halfedge = halfedges[twin].next;
      vertices[halfedges[halfedges[heindex].next].vertex].halfedge =
          halfedges[heindex].next;

      for (int i = 0; i < static_cast<int>(halfedges.size()); ++i) {
        if (halfedges[i].face == face2) {
          halfedges[i].face = face1;
        }
      }

      return true;
    }

    /**
     * Perform one low-valence edge unification directly on the live DCEL.
     *
     * This function does not create its own rollback snapshot. The caller must
     * provide transaction safety when:
     *
     *     rebuildGlobalRepresentatives == false
     *     runGlobalConsistencyCheck == false
     *
     * The optimized low-valence batch in NFunctionMesher does this by backing
     * up the complete DCEL once before processing all candidate vertices.
     *
     * When called through try_unify_edges(), both global operations are enabled
     * and the wrapper restores the original DCEL if this function fails.
     */
    bool unify_edges_in_place(const int heindex, const bool verbose = false,
                              const bool rebuildGlobalRepresentatives = true,
                              const bool runGlobalConsistencyCheck = true) {
      const auto fail = [&](const char *message, const int index = -1) -> bool {
        if (verbose) {
          std::cerr << "[Directional::DCEL::unify_edges_in_place()]: "
                    << message;

          if (index >= 0) {
            std::cerr << " (index " << index << ")";
          }

          std::cerr << '\n';
        }

        return false;
      };

      /*
       * ------------------------------------------------------------
       * Phase 1: validate the complete local neighborhood before
       * changing anything.
       * ------------------------------------------------------------
       */
      if (!valid_halfedge(heindex)) {
        return fail("invalid target halfedge", heindex);
      }

      const int prev = halfedges[heindex].prev;
      const int next = halfedges[heindex].next;
      const int face = halfedges[heindex].face;
      const int twin = halfedges[heindex].twin;
      const int killedVertex = halfedges[heindex].vertex;

      if (!valid_halfedge(prev)) {
        return fail("target halfedge has invalid prev", prev);
      }

      if (!valid_halfedge(next)) {
        return fail("target halfedge has invalid next", next);
      }

      if (!valid_face(face)) {
        return fail("target halfedge has invalid face", face);
      }

      if (!valid_vertex(killedVertex)) {
        return fail("target halfedge has invalid origin vertex", killedVertex);
      }

      if (halfedges[prev].next != heindex || halfedges[next].prev != heindex) {
        return fail("target halfedge neighborhood is inconsistent", heindex);
      }

      const int prevPrev = halfedges[prev].prev;

      if (!valid_halfedge(prevPrev)) {
        return fail("previous halfedge has invalid prev", prevPrev);
      }

      if (halfedges[prevPrev].next != prev) {
        return fail("previous chain is inconsistent", prevPrev);
      }

      const int replacementVertex = halfedges[prev].vertex;

      if (!valid_vertex(replacementVertex)) {
        return fail("replacement vertex is invalid", replacementVertex);
      }

      if (replacementVertex == killedVertex) {
        return fail("unification would preserve a degenerate vertex",
                    killedVertex);
      }

      std::vector<int> primaryCycle;

      if (!collect_face_cycle(face, primaryCycle, verbose)) {
        return false;
      }

      if (primaryCycle.size() <= 3) {
        return fail("cannot remove an edge from a triangle face", face);
      }

      /*
       * Values used only when the edge has an opposite face.
       */
      int twinNext = -1;
      int twinSuccessor = -1;
      int twinFace = -1;

      if (twin >= 0) {
        if (!valid_halfedge(twin)) {
          return fail("target halfedge has invalid twin", twin);
        }

        if (halfedges[twin].twin != heindex) {
          return fail("target twin relation is not mutual", heindex);
        }

        twinNext = halfedges[twin].next;
        twinFace = halfedges[twin].face;

        if (!valid_halfedge(twinNext)) {
          return fail("twin halfedge has invalid next", twinNext);
        }

        twinSuccessor = halfedges[twinNext].next;

        if (!valid_halfedge(twinSuccessor)) {
          return fail("twin-next has invalid successor", twinSuccessor);
        }

        if (halfedges[twinSuccessor].prev != twinNext) {
          return fail("twin-side next/prev chain is inconsistent", twinNext);
        }

        if (!valid_face(twinFace)) {
          return fail("twin halfedge references invalid face", twinFace);
        }

        std::vector<int> twinCycle;

        if (!collect_face_cycle(twinFace, twinCycle, verbose)) {
          return false;
        }

        if (twinCycle.size() <= 3) {
          return fail("cannot remove an edge from twin triangle face",
                      twinFace);
        }

        if (twinNext == heindex || twinNext == prev || twinNext == twin) {
          return fail("twin-side removal overlaps primary neighborhood",
                      twinNext);
        }

        /*
         * For the degree-two low-valence case, twinNext is the second
         * outgoing halfedge of killedVertex.
         */
        if (halfedges[twinNext].vertex != killedVertex) {
          return fail("twin-next does not originate at killed vertex",
                      twinNext);
        }
      }

      /*
       * The representative of killedVertex must be one of the locally
       * removed or redirected halfedges.
       *
       * This replaces the expensive full scan over every halfedge.
       */
      const int killedRepresentative = vertices[killedVertex].halfedge;

      if (killedRepresentative != heindex && killedRepresentative != twinNext) {
        return fail("killed vertex representative lies outside "
                    "the unification neighborhood",
                    killedRepresentative);
      }

      /*
       * ------------------------------------------------------------
       * Phase 2: mutate the primary face.
       *
       * heindex changes origin from killedVertex to replacementVertex.
       * prev is removed from the primary face cycle.
       * ------------------------------------------------------------
       */
      halfedges[heindex].vertex = replacementVertex;

      halfedges[prevPrev].next = heindex;
      halfedges[heindex].prev = prevPrev;

      if (faces[face].halfedge == prev) {
        faces[face].halfedge = heindex;
      }

      /*
       * Locally repair the replacement vertex representative before
       * retiring prev.
       *
       * This replaces a global representative rebuild after every
       * unification.
       */
      if (vertices[replacementVertex].halfedge == prev ||
          !valid_halfedge(vertices[replacementVertex].halfedge)) {
        vertices[replacementVertex].halfedge = heindex;
      }

      if (!retire_halfedge(prev, verbose)) {
        return false;
      }

      /*
       * ------------------------------------------------------------
       * Phase 3: mutate the opposite face.
       * ------------------------------------------------------------
       */
      if (twin >= 0) {
        halfedges[twin].next = twinSuccessor;
        halfedges[twinSuccessor].prev = twin;

        if (faces[twinFace].halfedge == twinNext) {
          faces[twinFace].halfedge = twin;
        }

        if (!retire_halfedge(twinNext, verbose)) {
          return false;
        }
      }

      /*
       * ------------------------------------------------------------
       * Phase 4: retire killedVertex.
       *
       * No global halfedge scan is performed here.
       *
       * For the optimized batch path, the caller guarantees that this is
       * a low-valence candidate and performs one full consistency check
       * after the complete batch.
       *
       * For standalone use, try_unify_edges() enables a full consistency
       * check before committing.
       * ------------------------------------------------------------
       */
      vertices[killedVertex].halfedge = -1;
      vertices[killedVertex].valid = false;

      /*
       * Ensure the replacement vertex has a valid local representative.
       */
      if (!valid_halfedge(vertices[replacementVertex].halfedge) ||
          halfedges[vertices[replacementVertex].halfedge].vertex !=
              replacementVertex) {
        vertices[replacementVertex].halfedge = heindex;
      }

      /*
       * Optional global representative repair.
       *
       * Disabled by the optimized bulk path and run once after the entire
       * batch in NFunctionMesher.
       */
      if (rebuildGlobalRepresentatives) {
        if (!rebuild_representative_halfedges(verbose, true)) {
          return false;
        }
      }

      /*
       * Optional full DCEL consistency validation.
       *
       * Disabled by the optimized bulk path and run once after the entire
       * batch in NFunctionMesher.
       */
      if (runGlobalConsistencyCheck) {
        if (!check_consistency(verbose, true, true, false)) {
          return false;
        }
      }

      return true;
    }

    /**
     * Transaction-safe standalone edge unification.
     *
     * This wrapper preserves the previous behavior:
     *
     * - complete DCEL rollback on failure;
     * - global representative rebuild;
     * - full consistency validation.
     *
     * The optimized NFunctionMesher batch does not call this function. It
     * calls unify_edges_in_place() after creating one backup for the entire
     * low-valence phase.
     */
    bool try_unify_edges(const int heindex, const bool verbose = false) {
      const auto oldVertices = vertices;
      const auto oldHalfedges = halfedges;
      const auto oldEdges = edges;
      const auto oldFaces = faces;

      const auto rollback = [&]() {
        vertices = oldVertices;
        halfedges = oldHalfedges;
        edges = oldEdges;
        faces = oldFaces;
      };

      if (!unify_edges_in_place(heindex, verbose, true, true)) {
        rollback();

        if (verbose) {
          std::cerr << "[Directional::DCEL::try_unify_edges()]: "
                    << "transaction rolled back"
                    << " (halfedge " << heindex << ")\n";
        }

        return false;
      }

      return true;
    }

    void unify_edges(const int heindex) {
      if (!try_unify_edges(heindex, false)) {
        throw std::runtime_error(
            "DCEL::unify_edges(): topology-safe unification failed");
      }
    }

    bool aggregate_dcel(const DCEL &source, const bool verbose = false,
                        const bool validateSource = true) {
      const auto fail = [&](const std::string &message) -> bool {
        if (verbose) {
          std::cerr << "[Directional::DCEL::aggregate_dcel()]: " << message
                    << '\n';
        }

        return false;
      };

      if (this == &source) {
        return fail("source and destination are the same DCEL; "
                    "self-aggregation is not supported");
      }

      constexpr std::size_t maxIntIndex =
          static_cast<std::size_t>(std::numeric_limits<int>::max());

      const std::size_t dstVertexCount = vertices.size();

      const std::size_t dstHalfedgeCount = halfedges.size();

      const std::size_t dstEdgeCount = edges.size();

      const std::size_t dstFaceCount = faces.size();

      const std::size_t srcVertexCount = source.vertices.size();

      const std::size_t srcHalfedgeCount = source.halfedges.size();

      const std::size_t srcEdgeCount = source.edges.size();

      const std::size_t srcFaceCount = source.faces.size();

      const auto additionFits = [](const std::size_t lhs,
                                   const std::size_t rhs) noexcept {
        return rhs <= std::numeric_limits<std::size_t>::max() - lhs;
      };

      if (!additionFits(dstVertexCount, srcVertexCount) ||
          !additionFits(dstHalfedgeCount, srcHalfedgeCount) ||
          !additionFits(dstEdgeCount, srcEdgeCount) ||
          !additionFits(dstFaceCount, srcFaceCount)) {
        return fail("container-size overflow while aggregating");
      }

      const std::size_t finalVertexCount = dstVertexCount + srcVertexCount;

      const std::size_t finalHalfedgeCount =
          dstHalfedgeCount + srcHalfedgeCount;

      const std::size_t finalEdgeCount = dstEdgeCount + srcEdgeCount;

      const std::size_t finalFaceCount = dstFaceCount + srcFaceCount;

      /*
       * Indices range from zero through count - 1. A count of
       * INT_MAX + 1 would still produce INT_MAX as the final index, but
       * keeping count <= INT_MAX is simpler and consistent with the rest
       * of the codebase.
       */
      if (finalVertexCount > maxIntIndex || finalHalfedgeCount > maxIntIndex ||
          finalEdgeCount > maxIntIndex || finalFaceCount > maxIntIndex) {
        return fail("aggregated DCEL exceeds int topology-index range");
      }

      const int vertexOffset = static_cast<int>(dstVertexCount);

      const int halfedgeOffset = static_cast<int>(dstHalfedgeCount);

      const int edgeOffset = static_cast<int>(dstEdgeCount);

      const int faceOffset = static_cast<int>(dstFaceCount);

      const auto validOptionalIndex =
          [](const int value, const std::size_t sourceCount) noexcept {
            if (value == -1) {
              return true;
            }

            if (value < -1) {
              return false;
            }

            return static_cast<std::size_t>(value) < sourceCount;
          };

      const auto rebaseIndex = [](const int value, const int offset) noexcept {
        return value < 0 ? -1 : value + offset;
      };

      /*
       * Validate source-local references before modifying destination
       * sizes. Since local triangle DCELs are small, this validation is
       * inexpensive compared with global aggregation.
       */
      if (validateSource) {
        for (std::size_t i = 0; i < srcVertexCount; ++i) {
          const Vertex &vertex = source.vertices[i];

          if (!validOptionalIndex(vertex.halfedge, srcHalfedgeCount)) {
            return fail("source vertex " + std::to_string(i) +
                        " has invalid halfedge index " +
                        std::to_string(vertex.halfedge));
          }
        }

        for (std::size_t i = 0; i < srcHalfedgeCount; ++i) {
          const Halfedge &halfedge = source.halfedges[i];

          if (!validOptionalIndex(halfedge.vertex, srcVertexCount)) {
            return fail("source halfedge " + std::to_string(i) +
                        " has invalid vertex index " +
                        std::to_string(halfedge.vertex));
          }

          if (!validOptionalIndex(halfedge.next, srcHalfedgeCount)) {
            return fail("source halfedge " + std::to_string(i) +
                        " has invalid next index " +
                        std::to_string(halfedge.next));
          }

          if (!validOptionalIndex(halfedge.prev, srcHalfedgeCount)) {
            return fail("source halfedge " + std::to_string(i) +
                        " has invalid prev index " +
                        std::to_string(halfedge.prev));
          }

          if (!validOptionalIndex(halfedge.twin, srcHalfedgeCount)) {
            return fail("source halfedge " + std::to_string(i) +
                        " has invalid twin index " +
                        std::to_string(halfedge.twin));
          }

          if (!validOptionalIndex(halfedge.face, srcFaceCount)) {
            return fail("source halfedge " + std::to_string(i) +
                        " has invalid face index " +
                        std::to_string(halfedge.face));
          }

          if (!validOptionalIndex(halfedge.edge, srcEdgeCount)) {
            return fail("source halfedge " + std::to_string(i) +
                        " has invalid edge index " +
                        std::to_string(halfedge.edge));
          }
        }

        for (std::size_t i = 0; i < srcEdgeCount; ++i) {
          const Edge &edge = source.edges[i];

          if (!validOptionalIndex(edge.halfedge, srcHalfedgeCount)) {
            return fail("source edge " + std::to_string(i) +
                        " has invalid halfedge index " +
                        std::to_string(edge.halfedge));
          }
        }

        for (std::size_t i = 0; i < srcFaceCount; ++i) {
          const Face &face = source.faces[i];

          if (!validOptionalIndex(face.halfedge, srcHalfedgeCount)) {
            return fail("source face " + std::to_string(i) +
                        " has invalid halfedge index " +
                        std::to_string(face.halfedge));
          }
        }
      }

      /*
       * Grow capacity geometrically instead of reserving the exact final
       * size on every triangle. Exact reserve(finalCount) can cause one
       * complete reallocation per aggregation call.
       */
      const auto geometricCapacity =
          [](const std::size_t currentCapacity,
             const std::size_t requiredSize) -> std::size_t {
        if (requiredSize <= currentCapacity) {
          return currentCapacity;
        }

        std::size_t grown =
            currentCapacity == 0 ? std::size_t{8} : currentCapacity;

        while (grown < requiredSize) {
          if (grown > std::numeric_limits<std::size_t>::max() / 2) {
            return requiredSize;
          }

          grown *= 2;
        }

        return grown;
      };

      /*
       * Reserve all capacities before changing logical sizes. A successful
       * reserve may change capacity, but never topology or entity counts.
       */
      try {
        if (finalVertexCount > vertices.capacity()) {
          vertices.reserve(
              geometricCapacity(vertices.capacity(), finalVertexCount));
        }

        if (finalHalfedgeCount > halfedges.capacity()) {
          halfedges.reserve(
              geometricCapacity(halfedges.capacity(), finalHalfedgeCount));
        }

        if (finalEdgeCount > edges.capacity()) {
          edges.reserve(geometricCapacity(edges.capacity(), finalEdgeCount));
        }

        if (finalFaceCount > faces.capacity()) {
          faces.reserve(geometricCapacity(faces.capacity(), finalFaceCount));
        }
      } catch (const std::exception &exception) {
        return fail(std::string("failed to reserve aggregation capacity: ") +
                    exception.what());
      }

      /*
       * Rollback restores logical sizes if copying any source entity
       * throws. Existing destination entities are never modified.
       */
      const auto rollback = [&]() noexcept {
        vertices.resize(dstVertexCount);
        halfedges.resize(dstHalfedgeCount);
        edges.resize(dstEdgeCount);
        faces.resize(dstFaceCount);
      };

      try {
        /*
         * Append vertices.
         */
        for (std::size_t i = 0; i < srcVertexCount; ++i) {
          vertices.push_back(source.vertices[i]);

          Vertex &vertex = vertices.back();

          vertex.ID = vertexOffset + static_cast<int>(i);

          vertex.halfedge = rebaseIndex(vertex.halfedge, halfedgeOffset);
        }

        /*
         * Append halfedges.
         */
        for (std::size_t i = 0; i < srcHalfedgeCount; ++i) {
          halfedges.push_back(source.halfedges[i]);

          Halfedge &halfedge = halfedges.back();

          halfedge.ID = halfedgeOffset + static_cast<int>(i);

          halfedge.vertex = rebaseIndex(halfedge.vertex, vertexOffset);

          halfedge.next = rebaseIndex(halfedge.next, halfedgeOffset);

          halfedge.prev = rebaseIndex(halfedge.prev, halfedgeOffset);

          halfedge.twin = rebaseIndex(halfedge.twin, halfedgeOffset);

          halfedge.face = rebaseIndex(halfedge.face, faceOffset);

          halfedge.edge = rebaseIndex(halfedge.edge, edgeOffset);
        }

        /*
         * Append edges.
         */
        for (std::size_t i = 0; i < srcEdgeCount; ++i) {
          edges.push_back(source.edges[i]);

          Edge &edge = edges.back();

          edge.ID = edgeOffset + static_cast<int>(i);

          edge.halfedge = rebaseIndex(edge.halfedge, halfedgeOffset);
        }

        /*
         * Append faces.
         */
        for (std::size_t i = 0; i < srcFaceCount; ++i) {
          faces.push_back(source.faces[i]);

          Face &face = faces.back();

          face.ID = faceOffset + static_cast<int>(i);

          face.halfedge = rebaseIndex(face.halfedge, halfedgeOffset);
        }
      } catch (const std::exception &exception) {
        rollback();

        return fail(std::string("failed while appending source DCEL: ") +
                    exception.what());
      } catch (...) {
        rollback();

        return fail("unknown failure while appending source DCEL");
      }

      return true;
    }

    bool RemoveVertex(const int vindex, std::deque<int> &removeVertexQueue,
                      const bool verbose = false) {
      /*
       * Transactional vertex removal.
       *
       * Returns:
       *   true  = vertex was removed successfully
       *   false = vertex was not removed; DCEL is left unchanged
       */

      struct RemovalOp {
        int outgoing;   // halfedge starting at removed vertex
        int twin;       // opposite halfedge
        int nextEdge;   // outgoing.next
        int prevAcross; // outgoing.twin.prev
        int nextFace;
        int prevFace;
        int outgoingEdge;
        int twinEdge;
      };

      const int vertexCount = static_cast<int>(vertices.size());

      const int halfedgeCount = static_cast<int>(halfedges.size());

      const int faceCount = static_cast<int>(faces.size());

      const int edgeCount = static_cast<int>(edges.size());

      const auto logFail = [&](const char *message, const int id = -1) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::RemoveVertex()]: " << message;

          if (id >= 0)
            std::cerr << " " << id;

          std::cerr << '\n';
        }
      };

      if (!valid_vertex_index(vindex)) {
        logFail("invalid vertex index", vindex);
        return false;
      }

      const int heBegin = vertices[vindex].halfedge;

      if (!valid_halfedge_index(heBegin)) {
        logFail("vertex references invalid halfedge", heBegin);
        return false;
      }

      if (halfedges[heBegin].vertex != vindex) {
        logFail("vertex incident halfedge has different origin", heBegin);
        return false;
      }

      const int remainingFace = halfedges[heBegin].face;

      if (!valid_face_index(remainingFace)) {
        logFail("incident halfedge references invalid remaining face",
                remainingFace);
        return false;
      }

      /*
       * Phase 1: collect the complete closed one-ring around the vertex.
       *
       * Original traversal:
       *     he = halfedges[halfedges[he].prev].twin;
       *
       * This only works for an interior vertex. If a twin is -1, the
       * vertex is on a boundary and should not be removed by this routine.
       */
      std::vector<RemovalOp> ops;
      std::vector<unsigned char> visited(
          static_cast<std::size_t>(halfedgeCount), 0);

      int he = heBegin;

      for (int steps = 0; steps < halfedgeCount; ++steps) {
        if (!valid_halfedge_index(he)) {
          logFail("invalid halfedge while walking vertex fan", he);
          return false;
        }

        if (visited[he]) {
          if (he == heBegin)
            break;

          logFail("vertex fan walk entered a non-start cycle", he);
          return false;
        }

        visited[he] = 1;

        if (halfedges[he].vertex != vindex) {
          logFail("fan halfedge does not originate at target vertex", he);
          return false;
        }

        const int prev = halfedges[he].prev;
        const int next = halfedges[he].next;
        const int twin = halfedges[he].twin;

        if (!valid_halfedge_index(prev)) {
          logFail("fan halfedge has invalid prev", he);
          return false;
        }

        if (!valid_halfedge_index(next)) {
          logFail("fan halfedge has invalid next", he);
          return false;
        }

        /*
         * Boundary vertex. Original code returned here, but only because
         * it had not mutated anything yet. Keep that behavior as a safe
         * no-op.
         */
        if (twin < 0) {
          logFail("vertex is on boundary; removal skipped", vindex);
          return false;
        }

        if (!valid_halfedge_index(twin)) {
          logFail("fan halfedge has invalid twin", he);
          return false;
        }

        if (halfedges[twin].twin != he) {
          logFail("fan halfedge twin is not mutual", he);
          return false;
        }

        const int prevAcross = halfedges[twin].prev;

        if (!valid_halfedge_index(prevAcross)) {
          logFail("twin halfedge has invalid prev", twin);
          return false;
        }

        const int nextFace = halfedges[next].face;
        const int prevFace = halfedges[prevAcross].face;

        if (!valid_face_index(nextFace)) {
          logFail("next edge references invalid face", nextFace);
          return false;
        }

        if (!valid_face_index(prevFace)) {
          logFail("previous-across edge references invalid face", prevFace);
          return false;
        }

        const int outgoingEdge = halfedges[he].edge;
        const int twinEdge = halfedges[twin].edge;

        if (!valid_edge_index(outgoingEdge)) {
          logFail("outgoing halfedge references invalid edge", outgoingEdge);
          return false;
        }

        if (!valid_edge_index(twinEdge)) {
          logFail("twin halfedge references invalid edge", twinEdge);
          return false;
        }

        ops.push_back(RemovalOp{he, twin, next, prevAcross, nextFace, prevFace,
                                outgoingEdge, twinEdge});

        const int nextAroundVertex = halfedges[prev].twin;

        if (nextAroundVertex < 0) {
          logFail(
              "vertex fan reached boundary while expecting closed interior fan",
              he);
          return false;
        }

        if (!valid_halfedge_index(nextAroundVertex)) {
          logFail("next fan halfedge is invalid", nextAroundVertex);
          return false;
        }

        he = nextAroundVertex;

        if (he == heBegin)
          break;
      }

      if (ops.empty()) {
        logFail("no removable fan halfedges collected", vindex);
        return false;
      }

      if (he != heBegin) {
        logFail("vertex fan did not close within traversal bound", vindex);
        return false;
      }

      const int newRemainingFaceHalfedge = halfedges[heBegin].next;

      if (!valid_halfedge_index(newRemainingFaceHalfedge)) {
        logFail("new remaining face halfedge is invalid",
                newRemainingFaceHalfedge);
        return false;
      }

      /*
       * Phase 2: snapshot. Anything after this point can rollback.
       *
       * This is intentionally simple. RemoveVertex is a topology-editing
       * operation, not a hot inner numeric kernel.
       */
      const auto oldVertices = vertices;
      const auto oldHalfedges = halfedges;
      const auto oldFaces = faces;
      const auto oldEdges = edges;
      const auto oldQueue = removeVertexQueue;

      const auto rollback = [&]() {
        vertices = oldVertices;
        halfedges = oldHalfedges;
        faces = oldFaces;
        edges = oldEdges;
        removeVertexQueue = oldQueue;
      };

      /*
       * Phase 3: commit rewiring.
       */

      vertices[vindex].valid = false;

      faces[remainingFace].halfedge = newRemainingFaceHalfedge;

      for (const RemovalOp &op : ops) {
        halfedges[op.nextEdge].prev = op.prevAcross;

        halfedges[op.prevAcross].next = op.nextEdge;

        if (op.nextFace != remainingFace)
          faces[op.nextFace].valid = false;

        if (op.prevFace != remainingFace)
          faces[op.prevFace].valid = false;

        halfedges[op.nextEdge].face = remainingFace;

        halfedges[op.prevAcross].face = remainingFace;

        halfedges[op.outgoing].valid = false;
        halfedges[op.twin].valid = false;

        edges[op.outgoingEdge].valid = false;
        edges[op.twinEdge].valid = false;
      }

      /*
       * Phase 4: clean the merged face.
       *
       * This is now bounded and rollback-protected. If the new face cycle
       * is broken, the original DCEL is restored.
       */
      int current = faces[remainingFace].halfedge;

      if (!valid_halfedge_index(current)) {
        rollback();
        logFail("merged face references invalid halfedge after commit",
                current);
        return false;
      }

      std::vector<unsigned char> faceVisited(
          static_cast<std::size_t>(halfedgeCount), 0);

      for (int steps = 0; steps < halfedgeCount; ++steps) {
        if (!valid_halfedge_index(current)) {
          rollback();
          logFail("merged face walk reached invalid halfedge", current);
          return false;
        }

        if (faceVisited[current]) {
          if (current == faces[remainingFace].halfedge)
            return true;

          rollback();
          logFail("merged face walk entered non-start cycle", current);
          return false;
        }

        faceVisited[current] = 1;

        const int origin = halfedges[current].vertex;

        if (!valid_vertex_index(origin)) {
          rollback();
          logFail("merged face contains invalid origin vertex", origin);
          return false;
        }

        halfedges[current].face = remainingFace;

        vertices[origin].halfedge = current;

        removeVertexQueue.push_front(origin);

        const int next = halfedges[current].next;

        if (!valid_halfedge_index(next)) {
          rollback();
          logFail("merged face halfedge has invalid next", current);
          return false;
        }

        current = next;

        if (current == faces[remainingFace].halfedge)
          return true;
      }

      rollback();
      logFail("merged face walk exceeded traversal bound", remainingFace);
      return false;
    }

    //Initializing DCEL from faces, assuming this is a triangle mesh
    void init(const Eigen::MatrixXd& V,
              const Eigen::MatrixXi& F){
        
        halfedges.resize(3*F.rows());
        vertices.resize(V.rows());
        faces.resize(F.rows());
        edges.clear();
        
        for (int i=0;i<F.rows();i++) {
            faces[i].ID=i;
            faces[i].halfedge=3*i;
            for (int j=0;j<3;j++){
                halfedges[3*i+j].ID = 3*i+j;
                halfedges[3*i+j].vertex=F(i,j);
                vertices[halfedges[3*i+j].vertex].halfedge=3*i+j;
                halfedges[3*i+j].next=3*i+(j+1)%3;
                halfedges[3*i+j].prev=3*i+(j+2)%3;
                halfedges[3*i+j].face = i;
                halfedges[3*i+j].edge = -1;
            }
        }
        
        for (int i=0;i<vertices.size();i++)
            vertices[i].ID=i;
        
        struct ComparePairs {
            bool operator()(const std::pair<std::pair<int, int>, int>& a, const std::pair<std::pair<int, int>, int>& b) const {
                if (a.first.first == b.first.first) {
                    return a.first.second < b.first.second;
                } else {
                    return a.first.first < b.first.first;
                }
            }
        };
        
        //finding twins
        typedef std::pair<std::pair<int, int>, int> pairPlusOne;
        std::set<pairPlusOne, ComparePairs> edgeSet;
        std::vector<int> EHList;
        for (int i=0;i<halfedges.size();i++){
            std::pair<int,int> oppEdge(halfedges[halfedges[i].next].vertex, halfedges[i].vertex);
            pairPlusOne oppEdgePlus(oppEdge, -1);
            std::set<pairPlusOne>::iterator si = edgeSet.find(oppEdgePlus);
            if (si == edgeSet.end()) {
                edgeSet.insert(pairPlusOne(std::pair<int, int>( halfedges[i].vertex, halfedges[halfedges[i].next].vertex), i));
                EHList.push_back(i);
            } else {  //found matching twin
                halfedges[si->second].twin = i;
                halfedges[i].twin = si->second;
            }
        }
        
        //creating edges
        for (int i=0;i<halfedges.size();i++) {
            if (halfedges[i].edge!=-1)
                continue;
            
            edges.push_back(Edge());
            edges[edges.size()-1].ID=edges.size()-1;
            edges[edges.size()-1].halfedge=i;
            halfedges[i].edge=edges.size()-1;
            if (halfedges[i].twin!=-1)
                halfedges[halfedges[i].twin].edge=edges.size()-1;
            
        }
        
        //reorienting vertex halfedges in case of boundaries
        for (int i=0;i<halfedges.size();i++)
            if (halfedges[i].twin==-1)
                vertices[halfedges[i].vertex].halfedge = i;
        
        
        //assert(check_consistency(true) && "dcel::init(): something is wrong with the mesh!");
    }

    
};

}


#endif
