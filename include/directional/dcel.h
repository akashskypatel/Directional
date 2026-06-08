// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2024 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_DCEL_H
#define DIRECTIONAL_DCEL_H

#include <Eigen/Core>
#include <vector>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <deque>
#include <iostream>
#include <limits>

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

    bool valid_halfedge(const int index) const {
      return valid_halfedge_index(index) && halfedges[index].valid;
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

    //Only used after having checked for consistency!
    void clean_mesh() {
        
        //Cleaning nonvalid vertices
        std::vector<int> transVertices(vertices.size());
        std::vector<Vertex> newVertices;  //TODO: from here
        //std::vector <Vertex> NewVertices;
        int counter=0;
        for (int i = 0; i < vertices.size(); i++) {
            if (!vertices[i].valid)
                continue;
            
            newVertices.push_back(vertices[i]);
            newVertices[newVertices.size()-1].ID = newVertices.size()-1;
            transVertices[i]=newVertices.size()-1;
        }
        
        vertices=newVertices;
        //updating references to these vertices
        for (int i=0;i<halfedges.size();i++){
            halfedges[i].vertex=transVertices[halfedges[i].vertex];
        }
        
        //Cleaning nonvalid faces
        std::vector<int> transFaces(faces.size());
        std::vector<Face> newFaces;
        for (int i = 0; i < faces.size(); i++) {
            if (!faces[i].valid)
                continue;
            
            newFaces.push_back(faces[i]);
            newFaces[newFaces.size()-1].ID = newFaces.size()-1;
            transFaces[i]=newFaces.size()-1;
        }
        faces = newFaces;
        for (int i = 0; i < halfedges.size(); i++)
            halfedges[i].face = transFaces[halfedges[i].face];
        
        //Cleaning nonvalid halfedges
        std::vector <Halfedge> newHalfedges;
        std::vector<int> transHalfedges(halfedges.size());
        for (int i = 0; i < halfedges.size(); i++) {
            if (!halfedges[i].valid)
                continue;
            
            Halfedge NewHalfedge = halfedges[i];
            NewHalfedge.ID = newHalfedges.size();
            newHalfedges.push_back(NewHalfedge);
            transHalfedges[i] = NewHalfedge.ID;
        }
        
        halfedges = newHalfedges;
        for (int i = 0; i < faces.size(); i++)
            faces[i].halfedge = transHalfedges[faces[i].halfedge];
        
        for (int i = 0; i < vertices.size(); i++)
            vertices[i].halfedge = transHalfedges[vertices[i].halfedge];
        
        for (int i = 0; i < edges.size(); i++)
            edges[i].halfedge = transHalfedges[edges[i].halfedge];
        
        for (int i = 0; i < halfedges.size(); i++) {
            if (halfedges[i].twin != -1)
                halfedges[i].twin = transHalfedges[halfedges[i].twin];
            halfedges[i].next = transHalfedges[halfedges[i].next];
            halfedges[i].prev = transHalfedges[halfedges[i].prev];
        }
        
        //cleaing non-valid edges
        std::vector<int> transEdges(edges.size());
        std::vector<Edge> newEdges;
        for (int i = 0; i < edges.size(); i++) {
            if (!edges[i].valid)
                continue;
            
            newEdges.push_back(edges[i]);
            newEdges[newEdges.size()-1].ID = newEdges.size()-1;
            transEdges[i]=newEdges.size()-1;
        }
        
        edges=newEdges;
        //updating references to these vertices
        for (int i=0;i<halfedges.size();i++){
            halfedges[i].edge=transEdges[halfedges[i].edge];
        }
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
        if (halfedges[heindex].twin < 0)
            return true;  //there is no joining of boundary faces
        
        int Face1 = halfedges[heindex].face;
        int Face2 = halfedges[halfedges[heindex].twin].face;
        
        /*int hebegin = faces[Face1].halfedge;
         int heiterate = hebegin;
         do {
         heiterate = halfedges[heiterate].next;
         } while (heiterate != hebegin);
         
         hebegin = faces[Face1].halfedge;
         heiterate = hebegin;
         do {
         heiterate = halfedges[heiterate].next;
         } while (heiterate != hebegin);*/
        
        //check if spike edge
        if ((halfedges[heindex].prev == halfedges[heindex].twin) ||
            (halfedges[heindex].next == halfedges[heindex].twin)) {
            
            
            int CloseEdge = heindex;
            if (halfedges[heindex].prev == halfedges[heindex].twin)
                CloseEdge = halfedges[heindex].twin;
            
            halfedges[CloseEdge].valid = halfedges[halfedges[CloseEdge].twin].valid = edges[halfedges[CloseEdge].edge] = false;
            
            vertices[halfedges[CloseEdge].vertex].halfedge = halfedges[halfedges[CloseEdge].twin].next;
            faces[Face1].halfedge = halfedges[CloseEdge].prev;
            
            halfedges[halfedges[CloseEdge].prev].next = halfedges[halfedges[CloseEdge].twin].next;
            halfedges[halfedges[halfedges[CloseEdge].twin].next].prev = halfedges[CloseEdge].prev;
            
            vertices[halfedges[halfedges[CloseEdge].twin].vertex].valid = false;
            //faces[Face1].Numvertices-=2;  //although one vertex should appear twice
            
            
            int hebegin = faces[Face1].halfedge;
            int heiterate = hebegin;
            do {
                
                heiterate = halfedges[heiterate].next;
            } while (heiterate != hebegin);
            
            hebegin = faces[Face1].halfedge;
            heiterate = hebegin;
            do {
                heiterate = halfedges[heiterate].next;
            } while (heiterate != hebegin);
            
            
            return true;
        }
        
        if (Face1 == Face2)
            return false;  //we don't remove non-spike edges with the same faces to not disconnect a chain
        
        /*int hebegin = faces[Face2].halfedge;
         int heiterate = hebegin;
         do {
         heiterate = halfedges[heiterate].next;
         } while (heiterate != hebegin);*/
        
        faces[Face1].halfedge = halfedges[heindex].next;
        faces[Face2].valid = false;
        
        //faces[Face2].halfedge=halfedges[halfedges[heindex].twin].next;
        
        halfedges[heindex].valid = halfedges[halfedges[heindex].twin].valid = false;
        
        halfedges[halfedges[heindex].next].prev = halfedges[halfedges[heindex].twin].prev;
        halfedges[halfedges[halfedges[heindex].twin].prev].next = halfedges[heindex].next;
        
        halfedges[halfedges[halfedges[heindex].twin].next].prev = halfedges[heindex].prev;
        halfedges[halfedges[heindex].prev].next = halfedges[halfedges[heindex].twin].next;
        
        vertices[halfedges[heindex].vertex].halfedge = halfedges[halfedges[heindex].twin].next;
        vertices[halfedges[halfedges[heindex].next].vertex].halfedge = halfedges[heindex].next;
        
        //all other floating halfedges should renounce this one
        for (int i = 0; i < halfedges.size(); i++)
            if (halfedges[i].face == Face2)
                halfedges[i].face = Face1;
        
        //faces[Face1].NumVertices+=faces[Face2].NumVertices-2;
        
        //DebugLog<<"Official number of vertices: "<<faces[Face1].NumVertices;
        
        /*hebegin = faces[Face1].halfedge;
         heiterate = hebegin;
         int currVertex = 0;
         do {
         //faces[Face1].Vertices[currVertex++]=halfedges[heiterate].vertex;
         heiterate = halfedges[heiterate].next;
         } while (heiterate != hebegin);*/
        
        return true;
        
        
    }
    
    void unify_edges(int heindex) {
        //if (halfedges[heindex].twin<0)
        //  return;
        //adjusting source
        
        //std::cout<<"Unifying halfedge "<<halfedges[heindex].prev<<" into halfedge "<<heindex<<" killing edge "<<halfedges[halfedges[heindex].prev].edge<<std::endl;
        vertices[halfedges[heindex].vertex].valid = false;
        halfedges[heindex].vertex = halfedges[halfedges[heindex].prev].vertex;
        //if (halfedges[heindex].data.prescribedAngle < 0.0)
        //    halfedges[heindex].data.prescribedAngle = halfedges[halfedges[heindex].prev].data.prescribedAngle;
        vertices[halfedges[heindex].vertex].halfedge = heindex;
        
        faces[halfedges[heindex].face].halfedge = halfedges[heindex].next;
        //faces[halfedges[heindex].face].NumVertices--;
        
        
        
        //adjusting halfedges
        halfedges[halfedges[heindex].prev].valid = false;
        edges[halfedges[halfedges[heindex].prev].edge].valid = false;
        halfedges[heindex].prev = halfedges[halfedges[heindex].prev].prev;
        halfedges[halfedges[heindex].prev].next = heindex;
        
        //adjusting twin, if exists
        if (halfedges[heindex].twin >= 0) {
            //if (halfedges[halfedges[heindex].twin].data.prescribedAngle < 0.0)
            //    halfedges[halfedges[heindex].twin].data.prescribedAngle = halfedges[halfedges[halfedges[heindex].twin].next].data.prescribedAngle;
            //std::cout<<"Unifying halfedge "<<halfedges[halfedges[heindex].twin].next<<" into halfedge "<<halfedges[heindex].twin<<" killing edge "<<halfedges[halfedges[halfedges[heindex].twin].next].edge<<std::endl;
            halfedges[halfedges[halfedges[heindex].twin].next].valid = false;
            edges[halfedges[halfedges[halfedges[heindex].twin].next].edge].valid = false;
            halfedges[halfedges[heindex].twin].next = halfedges[halfedges[halfedges[heindex].twin].next].next;
            halfedges[halfedges[halfedges[heindex].twin].next].prev = halfedges[heindex].twin;
            faces[halfedges[halfedges[heindex].twin].face].halfedge = halfedges[halfedges[heindex].twin].next;
            //faces[halfedges[halfedges[heindex].twin].face].NumVertices--;
        }
    }

    bool aggregate_dcel(
        const DCEL<VertexData, HalfedgeData, EdgeData, FaceData> &source,
        const bool verbose = false) {
      /*
       * Append `source` into this DCEL while rebasing all core topology
       * indices. The destination is unchanged if validation or allocation
       * fails before the final swaps.
       */

      const auto fail = [&](const std::string &message) {
        if (verbose) {
          std::cerr << "[Directional::DCEL::aggregate_dcel()]: " << message
                    << '\n';
        }

        return false;
      };

      /*
       * Self-aggregation is unsafe with the original implementation:
       *
       *     aggregate_dcel(*this)
       *
       * would append to the same vectors whose size controls the source
       * loops, potentially causing unbounded growth.
       */
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
                                   const std::size_t rhs) {
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
       * All topology references are stored as int.
       */
      if (finalVertexCount > maxIntIndex || finalHalfedgeCount > maxIntIndex ||
          finalEdgeCount > maxIntIndex || finalFaceCount > maxIntIndex) {
        return fail(
            "aggregated DCEL exceeds the range of int topology indices");
      }

      const int vertexOffset = static_cast<int>(dstVertexCount);

      const int halfedgeOffset = static_cast<int>(dstHalfedgeCount);

      const int edgeOffset = static_cast<int>(dstEdgeCount);

      const int faceOffset = static_cast<int>(dstFaceCount);

      /*
       * Validate a source-local index.
       *
       * -1 is the only accepted sentinel.
       */
      const auto validOptionalIndex = [](const int value,
                                         const std::size_t sourceCount) {
        if (value == -1)
          return true;

        if (value < -1)
          return false;

        return static_cast<std::size_t>(value) < sourceCount;
      };

      /*
       * Preserve -1 and rebase only nonnegative values.
       */
      const auto rebaseIndex = [](const int value, const int offset) {
        return value == -1 ? -1 : value + offset;
      };

      // ---------------------------------------------------------
      // Validate all source topology before modifying anything.
      // ---------------------------------------------------------

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

      // ---------------------------------------------------------
      // Build complete replacement vectors.
      //
      // The existing destination remains unchanged until swap().
      // ---------------------------------------------------------

      try {
        auto newVertices = vertices;
        auto newHalfedges = halfedges;
        auto newEdges = edges;
        auto newFaces = faces;

        newVertices.reserve(finalVertexCount);
        newHalfedges.reserve(finalHalfedgeCount);
        newEdges.reserve(finalEdgeCount);
        newFaces.reserve(finalFaceCount);

        for (std::size_t i = 0; i < srcVertexCount; ++i) {
          Vertex vertex = source.vertices[i];

          /*
           * Assign the real final index rather than doing:
           *
           *     vertex.ID += vertexOffset;
           *
           * Source IDs may be stale, -1, or non-contiguous.
           */
          vertex.ID = vertexOffset + static_cast<int>(i);

          vertex.halfedge = rebaseIndex(vertex.halfedge, halfedgeOffset);

          newVertices.push_back(std::move(vertex));
        }

        for (std::size_t i = 0; i < srcHalfedgeCount; ++i) {
          Halfedge halfedge = source.halfedges[i];

          halfedge.ID = halfedgeOffset + static_cast<int>(i);

          halfedge.vertex = rebaseIndex(halfedge.vertex, vertexOffset);

          halfedge.next = rebaseIndex(halfedge.next, halfedgeOffset);

          halfedge.prev = rebaseIndex(halfedge.prev, halfedgeOffset);

          halfedge.twin = rebaseIndex(halfedge.twin, halfedgeOffset);

          halfedge.face = rebaseIndex(halfedge.face, faceOffset);

          halfedge.edge = rebaseIndex(halfedge.edge, edgeOffset);

          newHalfedges.push_back(std::move(halfedge));
        }

        for (std::size_t i = 0; i < srcEdgeCount; ++i) {
          Edge edge = source.edges[i];

          edge.ID = edgeOffset + static_cast<int>(i);

          edge.halfedge = rebaseIndex(edge.halfedge, halfedgeOffset);

          newEdges.push_back(std::move(edge));
        }

        for (std::size_t i = 0; i < srcFaceCount; ++i) {
          Face face = source.faces[i];

          face.ID = faceOffset + static_cast<int>(i);

          face.halfedge = rebaseIndex(face.halfedge, halfedgeOffset);

          newFaces.push_back(std::move(face));
        }

        /*
         * Commit atomically at the vector level.
         */
        vertices.swap(newVertices);
        halfedges.swap(newHalfedges);
        edges.swap(newEdges);
        faces.swap(newFaces);
      } catch (const std::exception &exception) {
        return fail(std::string("failed while constructing aggregated DCEL: ") +
                    exception.what());
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
