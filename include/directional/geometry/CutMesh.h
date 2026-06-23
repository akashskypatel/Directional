// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_CUT_MESH_H
#define DIRECTIONAL_INTEGRATION_CUT_MESH_H

#include <set>
#include <vector>

#include <Eigen/Core>


/**
 * @file CutMesh.h
 * @brief Mesh cutting utilities driven by singularities and matching.
 *
 * Cuts a mesh along selected halfedges so that field singularities and branch cuts can be represented as an explicitly cut triangle mesh.
 */

namespace directional {

/**
 * @brief Computes a face-edge cut mask that opens a mesh around singularities.
 * @param mesh Source mesh with populated DCEL and face adjacency data.
 * @param singularities Vertex ids that must lie on the cut boundary.
 * @param face2cut Output #F-by-3 matrix; nonzero entries mark face edges to cut.
 *
 * The routine builds a spanning disk by flood filling across dual edges, then
 * retracts valence-one cut branches that do not terminate at singularities. The
 * output uses the source mesh's per-face edge ordering.
 */
inline void cut_mesh_with_singularities(const TriMesh &mesh,
                                        const Eigen::VectorXi &singularities,
                                        Eigen::MatrixXi &face2cut) {

  // Flood-fill across dual edges to keep a disk-like spanning region.
  std::queue<std::pair<int, int>> faceQueue;
  Eigen::VectorXi isHECut = Eigen::VectorXi::Ones(mesh.dcel.halfedges.size());
  Eigen::VectorXi isFaceVisited = Eigen::VectorXi::Zero(mesh.F.rows());
  std::vector<int> cutVertices;
  int currFace = 0;
  faceQueue.push(std::pair<int, int>(currFace, -1));
  while (!faceQueue.empty()) {
    std::pair<int, int> currFaceHE = faceQueue.front();
    int queuedFace = currFaceHE.first;
    int prevHE = currFaceHE.second;
    faceQueue.pop();
    if (isFaceVisited[queuedFace] == 1)
      continue;

    isFaceVisited[queuedFace] = 1;
    if (prevHE != -1) {
      isHECut(prevHE) = 0;
      isHECut(mesh.dcel.halfedges[prevHE].twin) = 0;
    }
    int hebegin = mesh.dcel.faces[queuedFace].halfedge;
    int heiterate = hebegin;
    for (int i = 0; i < 3; i++) {
      int currHE = heiterate; // mesh.FH(queuedFace,i);
      if (mesh.dcel.halfedges[currHE].twin == -1) {
        isHECut(currHE) = 0;
        heiterate = mesh.dcel.halfedges[heiterate].next;
        continue;
      }
      int nextFace = mesh.dcel.halfedges[mesh.dcel.halfedges[currHE].twin].face;
      if (!isFaceVisited[nextFace]) // can spill into that face
        faceQueue.push(std::pair<int, int>(nextFace, currHE));
      heiterate = mesh.dcel.halfedges[heiterate].next;
    }
  }

  // Retract valence-one branches that are not needed to expose singularities.
  Eigen::VectorXi cutValences = Eigen::VectorXi::Zero(mesh.V.rows());

  // Mark singular vertices and initialize cut valences.
  Eigen::VectorXi isSingularity = Eigen::VectorXi::Zero(mesh.V.rows());
  for (int i = 0; i < singularities.size(); i++)
    isSingularity(singularities(i)) = 1;
  for (int i = 0; i < mesh.dcel.halfedges.size(); i++) {
    if ((isHECut(i)) ||
        (mesh.dcel.halfedges[i].twin == -1)) // if cut or a boundary
      cutValences(
          mesh.dcel.halfedges[i].vertex)++; // the twin should already be inside
  }

  std::queue<int> cutQueue;
  for (int i = 0; i < mesh.dcel.halfedges.size(); i++)
    if ((isHECut(i)) && (cutValences(mesh.dcel.halfedges[i].vertex) == 1) &&
        (!isSingularity(mesh.dcel.halfedges[i].vertex)))
      cutQueue.push(i);

  while (!cutQueue.empty()) {
    int currHE = cutQueue.front();
    cutQueue.pop();
    if (!isHECut(currHE))
      continue;
    if (cutValences(mesh.dcel.halfedges[currHE].vertex) != 1)
      continue;
    if (isSingularity(mesh.dcel.halfedges[currHE].vertex))
      continue;

    isHECut(currHE) = 0;
    isHECut(mesh.dcel.halfedges[currHE].twin) = 0;
    // finding the next edge
    int nextVertex =
        mesh.dcel.halfedges[mesh.dcel.halfedges[currHE].next].vertex;
    if (mesh.isBoundaryVertex(nextVertex))
      continue;
    cutValences(nextVertex)--;
    cutValences(mesh.dcel.halfedges[currHE].vertex)--;
    if (cutValences(nextVertex) == 1) { // finding next edge
      int hebegin = mesh.dcel.vertices[nextVertex].halfedge;
      int hecurr = hebegin;
      do {
        if (isHECut(hecurr))
          break;
        hecurr = mesh.dcel.halfedges[mesh.dcel.halfedges[hecurr].prev].twin;
        // hecurr = mesh.twinH(mesh.prevH(hecurr));
      } while (hecurr != hebegin);
      if (!isHECut(hecurr)) {
        throw std::runtime_error("hecurr is not cut!");
      }
      cutQueue.push(hecurr);
    }
  }


  // Connecting all singularities to the cut graph



  face2cut.resize(mesh.F.rows(), 3);
  for (int i = 0; i < mesh.F.rows(); i++) {
    int hebegin = mesh.dcel.faces[i].halfedge;
    // resetting to the first halfedges
    while (mesh.HV(hebegin) != mesh.F(i, 0))
      hebegin = mesh.nextH(hebegin);

    int heiterate = hebegin;
    for (int j = 0; j < 3; j++) {
      face2cut(i, j) = isHECut(heiterate);
      heiterate = mesh.dcel.halfedges[heiterate].next;
    }
  }
}

}; // namespace directional

#endif
