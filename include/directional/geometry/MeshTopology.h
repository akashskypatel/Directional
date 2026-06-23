// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_MESH_TOPOLOGY_H
#define DIRECTIONAL_GEOMETRY_MESH_TOPOLOGY_H

#include <numbers>
#include <set>
#include <unordered_map>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>

#include <directional/util/EigenIndexUtils.h>
#include <directional/util/GraphUtils.h>


/**
 * @file MeshTopology.h
 * @brief Topology construction routines for primal and dual mesh cycles.
 *
 * Builds polygonal edge topology and cycle bases used by tangent bundles, field matching, integration constraints, and boundary handling.
 */

namespace directional {

/// @brief Initialize Edges and their topological relations
/// @param D eigen int vector     #F by 1 - face degrees
/// @param F eigen int matrix     #F by max(D) - vertex indices in face
/// @param EV #E by 2, Stores the edge description as pair of indices to
/// vertices
/// @param FE : #F by max(D), Stores the Face-Edge relation
/// @param EF : #E by 2: Stores the Edge-Face relation
/// @param EFi: #E by 2: corresponding to EF and stores the relative position of
/// the edge in the face (e.g., if the edge is (v1,v2) and the face has
/// (vx,vy,v2,v1,vz,va), then the value is 2) FEs: #F by max(D): if the edge is
/// oriented positively or negatively in the face (e.g. in the example above we
/// get -1) InnerEdges: indices into EV of which edges are internal (not
/// boundary)
inline void polygonal_edge_topology(const Eigen::VectorXi &D,
                                    const Eigen::MatrixXi &F,
                                    Eigen::MatrixXi &EV, Eigen::MatrixXi &FE,
                                    Eigen::MatrixXi &EF, Eigen::MatrixXi &EFi,
                                    Eigen::MatrixXd &FEs,
                                    Eigen::VectorXi &InnerEdges) {
  // Only needs to be edge-manifold
  std::vector<std::vector<int>> ETT;
  for (int f = 0; f < D.rows(); ++f)
    for (int i = 0; i < D(f); ++i) {
      // v1 v2 f vi
      int v1 = F(f, i);
      int v2 = F(f, (i + 1) % D(f));
      if (v1 > v2)
        std::swap(v1, v2);
      std::vector<int> r(4);
      r[0] = v1;
      r[1] = v2;
      r[2] = f;
      r[3] = i;
      ETT.push_back(r);
    }
  std::sort(ETT.begin(), ETT.end());

  // count the number of edges (assume manifoldness)
  int En = 1; // the last is always counted
  for (unsigned i = 0; i < ETT.size() - 1; ++i)
    if (!((ETT[i][0] == ETT[i + 1][0]) && (ETT[i][1] == ETT[i + 1][1])))
      ++En;

  EV = Eigen::MatrixXi::Constant((int)(En), 2, -1);
  FE = Eigen::MatrixXi::Constant((int)(F.rows()), (int)(F.cols()), -1);
  EF = Eigen::MatrixXi::Constant((int)(En), 2, -1);
  En = 0;

  for (unsigned i = 0; i < ETT.size(); ++i) {
    if (i == ETT.size() - 1 ||
        !((ETT[i][0] == ETT[i + 1][0]) && (ETT[i][1] == ETT[i + 1][1]))) {
      // Border edge
      std::vector<int> &r1 = ETT[i];
      EV(En, 0) = r1[0];
      EV(En, 1) = r1[1];
      EF(En, 0) = r1[2];
      FE(r1[2], r1[3]) = En;
    } else {
      std::vector<int> &r1 = ETT[i];
      std::vector<int> &r2 = ETT[i + 1];
      EV(En, 0) = r1[0];
      EV(En, 1) = r1[1];
      EF(En, 0) = r1[2];
      EF(En, 1) = r2[2];
      FE(r1[2], r1[3]) = En;
      FE(r2[2], r2[3]) = En;
      ++i; // skip the next one
    }
    ++En;
  }

  // Sort the relation EF, accordingly to EV
  // the first one is the face on the left of the edge

  for (int i = 0; i < EF.rows(); ++i) {
    int fid = EF(i, 0);
    bool flip = true;
    // search for edge EV.row(i)
    for (int j = 0; j < D(fid); ++j) {
      if ((F(fid, j) == EV(i, 0)) && (F(fid, (j + 1) % D(fid)) == EV(i, 1)))
        flip = false;
    }

    if (flip) {
      int tmp = EF(i, 0);
      EF(i, 0) = EF(i, 1);
      EF(i, 1) = tmp;
    }
  }

  std::vector<int> InnerEdgesVec;
  EFi = Eigen::MatrixXi::Constant(EF.rows(), 2, -1);
  FEs = Eigen::MatrixXd::Zero(FE.rows(), FE.cols());
  for (int i = 0; i < EF.rows(); i++)
    for (int k = 0; k < 2; k++) {
      if (EF(i, k) == -1)
        continue;

      for (int j = 0; j < D(EF(i, k)); j++)
        if (FE(EF(i, k), j) == i)
          EFi(i, k) = j;
    }

  for (int i = 0; i < EF.rows(); i++) {
    if (EFi(i, 0) != -1)
      FEs(EF(i, 0), EFi(i, 0)) = 1.0;
    if (EFi(i, 1) != -1)
      FEs(EF(i, 1), EFi(i, 1)) = -1.0;
    if ((EF(i, 0) != -1) && (EF(i, 1) != -1))
      InnerEdgesVec.push_back(i);
  }

  InnerEdges.resize(InnerEdgesVec.size());
  for (int i = 0; i < InnerEdgesVec.size(); i++)
    InnerEdges(i) = InnerEdgesVec[i];
}

/// @brief Creates the set of independent dual cycles (closed loops of connected
/// faces that cannot be morphed to each other) on a mesh. Primarily used for
/// index prescription. The basis cycle matrix first contains #V-#b cycles for
/// every inner vertex (by order), then #b boundary cycles, and finally 2*g
/// generator cycles around all handles. Total #c cycles.The cycle matrix sums
/// information on the dual edges between the faces, and is indexed into the
/// inner edges alone (excluding boundary)
/// @param mesh TriMesh &mesh: #V by 3 vertices.
/// @param basisCycles #c by #iE basis cycles
/// @param cycleCurvature #c by 1 curvatures of each cycle (for inner-vertex
/// cycles, simply the Gaussian curvature. vertex2cycle:     #v by 1 map between
/// vertex and corresponding cycle (for comfort of input from the user's side;
/// inner vertices map to their cycles, boundary vertices to the bigger boundary
/// cycle. innerEdges:       #iE by 1 the subset of #EV that are inner edges,
/// and with the same ordering as the columns of basisCycles.
inline void dual_cycles(const TriMesh &mesh,
                        Eigen::SparseMatrix<double> &basisCycles,
                        Eigen::VectorXd &cycleCurvature,
                        Eigen::VectorXi &vertex2cycle,
                        Eigen::VectorXi &innerEdges) {
  using namespace Eigen;
  using namespace std;
  int numV = static_cast<int>(mesh.F.maxCoeff() + 1);
  int eulerChar = static_cast<int>(numV - mesh.EV.rows() + mesh.F.rows());
  vertex2cycle.conservativeResize(mesh.V.rows());

  int numBoundaries = static_cast<int>(mesh.boundaryLoops.size());
  int numGenerators = 2 - numBoundaries - eulerChar;

  vector<Triplet<double>> basisCycleTriplets(mesh.EV.rows() * 2);

  // all 1-ring cycles, including boundaries
  for (int i = 0; i < mesh.EV.rows(); i++) {
    basisCycleTriplets[2 * i] = Triplet<double>(mesh.EV(i, 0), i, -1.0);
    basisCycleTriplets[2 * i + 1] = Triplet<double>(mesh.EV(i, 1), i, 1.0);
  }

  // Creating boundary cycles by building a matrix the sums up boundary loops
  // and zeros out boundary vertex cycles - it will be multiplied from the left
  // to basisCyclesMat
  VectorXi isBoundary(mesh.V.rows());
  isBoundary.setZero();
  for (int i = 0; i < static_cast<int>(mesh.boundaryLoops.size()); i++)
    for (int j = 0; j < static_cast<int>(mesh.boundaryLoops[i].size()); j++)
      isBoundary(mesh.boundaryLoops[i][j]) = 1;

  VectorXi pureInnerEdgeMask = VectorXi::Constant(mesh.EV.rows(), 1);
  for (int i = 0; i < mesh.EV.rows(); i++)
    if ((isBoundary(mesh.EV(i, 0))) || (isBoundary(mesh.EV(i, 1))))
      pureInnerEdgeMask(i) = 0;

  int currGeneratorCycle = 0;
  int currBoundaryCycle = 0;

  if ((numGenerators != 0) /*||(numBoundaries!=0)*/) {
    MatrixXi reducedEV(mesh.EV);
    for (int i = 1; i < reducedEV.rows(); i++)
      if (isBoundary(reducedEV(i, 0)) || isBoundary(reducedEV(i, 1)))
        reducedEV(i, 0) = -1;

    VectorXi primalTreeEdges, primalTreeFathers;
    VectorXi dualTreeEdges, dualTreeFathers;
    tree(reducedEV, primalTreeEdges, primalTreeFathers);
    // creating a set of dual edges that do not cross edges in the primal tree
    VectorXi fullIndices =
        VectorXi::LinSpaced(static_cast<int>(mesh.EV.rows()), 0,
                            static_cast<int>(mesh.EV.rows() - 1));
    VectorXi reducedEFIndices, inFullIndices;
    MatrixXi reducedEF;
    directional::set_diff(fullIndices, primalTreeEdges, reducedEFIndices,
                          inFullIndices);
    VectorXi Two = VectorXi::LinSpaced(2, 0, 1);

    // cout<<"mesh.EF: "<<mesh.EF<<endl;
    // cout<<"reducedEFIndices: "<<reducedEFIndices<<endl;
    directional::matrix_slice(mesh.EF, reducedEFIndices, Two, reducedEF);
    // cout<<"reducedEF: "<<reducedEF<<endl;
    tree(reducedEF, dualTreeEdges, dualTreeFathers);
    // converting dualTreeEdges from reducedEF to EF
    for (int i = 0; i < dualTreeEdges.size(); i++)
      dualTreeEdges(i) = inFullIndices(dualTreeEdges(i));

    for (int i = 0; i < dualTreeFathers.size(); i++)
      if (dualTreeFathers(i) != -1 && dualTreeFathers(i) != -2)
        dualTreeFathers(i) = inFullIndices(dualTreeFathers(i));

    // building tree co-tree based homological cycles
    // finding dual edge which are not in the tree, and following their faces to
    // the end
    VectorXi isinTree = VectorXi::Zero(mesh.EF.rows());
    for (int i = 0; i < dualTreeEdges.size(); i++) {
      isinTree(dualTreeEdges(i)) = 1;
    }
    for (int i = 0; i < primalTreeEdges.size(); i++) {
      isinTree(primalTreeEdges(i)) = 1;
    }

    for (int i = 0; i < isinTree.size(); i++) {
      if (isinTree(i))
        continue;

      // otherwise, follow both end faces to the root and this is the dual cycle
      if (mesh.EF(i, 0) == -1 || mesh.EF(i, 1) == -1)
        continue;
      std::vector<Triplet<double>> candidateTriplets;
      // candidateTriplets.push_back(Triplet<double>(0, i, 1.0));
      Vector2i currLeaves;
      currLeaves << mesh.EF(i, 0), mesh.EF(i, 1);
      VectorXi visitedOnce = VectorXi::Zero(
          mesh.EF.rows()); // used to remove the tail from the LCA to the root
      bool isBoundaryCycle = true;
      for (int leaf = 0; leaf < 2; leaf++) { // on leaves
        int currTreeEdge = -1;               // indexing within dualTreeEdges
        int currFace = currLeaves(leaf);
        currTreeEdge = dualTreeFathers(currFace);
        if (currTreeEdge == -2) {
          break;
        }

        while (currTreeEdge != -1) {
          // determining orientation of current edge vs. face
          double sign =
              ((mesh.EF(currTreeEdge, 0) == currFace) != (leaf == 0) ? 1.0
                                                                     : -1.0);
          visitedOnce(currTreeEdge) = 1 - visitedOnce(currTreeEdge);
          candidateTriplets.push_back(Triplet<double>(0, currTreeEdge, sign));
          currFace =
              (mesh.EF(currTreeEdge, 0) == currFace ? mesh.EF(currTreeEdge, 1)
                                                    : mesh.EF(currTreeEdge, 0));
          currTreeEdge = dualTreeFathers(currFace);
        }
      }

      // only putting in dual edges that are below the LCA
      for (int candidateIndex = 0;
           candidateIndex < static_cast<int>(candidateTriplets.size());
           candidateIndex++)
        if ((visitedOnce(candidateTriplets[candidateIndex].col())) &&
            (pureInnerEdgeMask(candidateTriplets[candidateIndex].col())))
          isBoundaryCycle = false;

      if (isBoundaryCycle)
        continue; // ignoring those

      int currRow = (isBoundaryCycle ? numV + currBoundaryCycle
                                     : numV + currGeneratorCycle);
      (isBoundaryCycle ? currBoundaryCycle++ : currGeneratorCycle++);

      basisCycleTriplets.push_back(Triplet<double>(currRow, i, 1.0));
      for (std::size_t candidateIndex = 0;
           candidateIndex < candidateTriplets.size(); candidateIndex++)
        if (visitedOnce(candidateTriplets[candidateIndex].col())) {
          Triplet<double> trueTriplet(
              currRow, candidateTriplets[candidateIndex].col(),
              candidateTriplets[candidateIndex].value());
          basisCycleTriplets.push_back(trueTriplet);
        }
    }
    // assert(currBoundaryCycle==numBoundaries &&
    // currGeneratorCycle==numGenerators);
  }

  numGenerators = currGeneratorCycle;

  SparseMatrix<double> sumBoundaryLoops(numV + numBoundaries + numGenerators,
                                        numV + numGenerators);
  vector<Triplet<double>> sumBoundaryLoopsTriplets;
  vector<int> innerVerticesList, innerEdgesList;
  VectorXi remainRows, remainColumns;

  for (int i = 0; i < numV; i++) {
    sumBoundaryLoopsTriplets.push_back(
        Triplet<double>(i, i, 1.0 - isBoundary[i]));
    if (!isBoundary(i)) {
      innerVerticesList.push_back(i);
      vertex2cycle(i) = static_cast<int>(innerVerticesList.size() - 1);
    }
  }

  for (int i = 0; i < mesh.EV.rows(); i++)
    if ((mesh.EF(i, 0) != -1) && (mesh.EF(i, 1) != -1))
      innerEdgesList.push_back(i);

  // summing up boundary loops
  for (int i = 0; i < static_cast<int>(mesh.boundaryLoops.size()); i++)
    for (int j = 0; j < static_cast<int>(mesh.boundaryLoops[i].size()); j++) {
      sumBoundaryLoopsTriplets.push_back(
          Triplet<double>(numV + i, mesh.boundaryLoops[i][j], 1.0));
      vertex2cycle(mesh.boundaryLoops[i][j]) =
          static_cast<int>(innerVerticesList.size()) + i;
    }

  // just passing generators through;
  for (int i = numV; i < numV + numGenerators; i++)
    sumBoundaryLoopsTriplets.push_back(Triplet<double>(i, i, 1.0));

  // Creating a matrix that aggregates basic cycles on boundary vertices
  sumBoundaryLoops.setFromTriplets(sumBoundaryLoopsTriplets.begin(),
                                   sumBoundaryLoopsTriplets.end());

  basisCycles.resize(numV + numGenerators, mesh.EV.rows());
  basisCycles.setFromTriplets(basisCycleTriplets.begin(),
                              basisCycleTriplets.end());
  basisCycles = sumBoundaryLoops * basisCycles;

  // removing rows and columns of boundary vertices
  remainRows.resize(innerVerticesList.size() + numBoundaries + numGenerators);
  remainColumns.resize(innerEdgesList.size());
  for (int i = 0; i < innerVerticesList.size(); i++)
    remainRows(i) = innerVerticesList[i];

  for (int i = 0; i < numBoundaries + numGenerators; i++)
    remainRows(innerVerticesList.size() + i) = numV + i;

  for (int i = 0; i < innerEdgesList.size(); i++)
    remainColumns(i) = innerEdgesList[i];

  // creating slicing matrices
  std::vector<Triplet<double>> rowSliceTriplets, colSliceTriplets;
  for (int i = 0; i < remainRows.size(); i++)
    rowSliceTriplets.push_back(Triplet<double>(i, remainRows(i), 1.0));
  for (int i = 0; i < remainColumns.size(); i++)
    colSliceTriplets.push_back(Triplet<double>(remainColumns(i), i, 1.0));

  SparseMatrix<double> rowSliceMat(remainRows.rows(), basisCycles.rows());
  rowSliceMat.setFromTriplets(rowSliceTriplets.begin(), rowSliceTriplets.end());

  SparseMatrix<double> colSliceMat(basisCycles.cols(), remainColumns.rows());
  colSliceMat.setFromTriplets(colSliceTriplets.begin(), colSliceTriplets.end());

  basisCycles = rowSliceMat * basisCycles * colSliceMat;

  innerEdges.conservativeResize(innerEdgesList.size());
  for (int i = 0; i < innerEdgesList.size(); i++)
    innerEdges(i) = innerEdgesList[i];

  // Correct computation of cycle curvature by adding angles
  // getting corner angle sum
  VectorXd allAngles(3 * mesh.F.rows());
  for (int i = 0; i < mesh.F.rows(); i++) {
    for (int j = 0; j < 3; j++) {
      RowVector3d edgeVec12 =
          mesh.V.row(mesh.F(i, (j + 1) % 3)) - mesh.V.row(mesh.F(i, j));
      RowVector3d edgeVec13 =
          mesh.V.row(mesh.F(i, (j + 2) % 3)) - mesh.V.row(mesh.F(i, j));
      allAngles(3 * i + j) =
          acos(edgeVec12.normalized().dot(edgeVec13.normalized()));
    }
  }

  // for each cycle, summing up all its internal angles negatively  + either
  // 2*pi*|cycle| for internal cycles or pi*|cycle| for boundary cycles.
  cycleCurvature = VectorXd::Zero(basisCycles.rows());
  VectorXi isBigCycle = VectorXi::Ones(
      basisCycles.rows());

  for (int i = 0; i < mesh.V.rows(); i++) // inner cycles
    if (!isBoundary(i))
      isBigCycle(vertex2cycle(i)) = 0;

  // getting the 4 corners of each edge to allocated later to cycles according
  // to the sign of the edge.
  vector<set<int>> cornerSets(basisCycles.rows());
  vector<set<int>> vertexSets(basisCycles.rows());
  MatrixXi edgeCorners(innerEdges.size(), 4);
  for (int i = 0; i < innerEdges.rows(); i++) {
    int inFace1 = 0;
    while (mesh.F(mesh.EF(innerEdges(i), 0), inFace1) !=
           mesh.EV(innerEdges(i), 0))
      inFace1 = (inFace1 + 1) % 3;
    int inFace2 = 0;
    while (mesh.F(mesh.EF(innerEdges(i), 1), inFace2) !=
           mesh.EV(innerEdges(i), 1))
      inFace2 = (inFace2 + 1) % 3;

    edgeCorners(i, 0) = mesh.EF(innerEdges(i), 0) * 3 + inFace1;
    edgeCorners(i, 1) = mesh.EF(innerEdges(i), 1) * 3 + (inFace2 + 1) % 3;
    edgeCorners(i, 2) = mesh.EF(innerEdges(i), 0) * 3 + (inFace1 + 1) % 3;
    edgeCorners(i, 3) = mesh.EF(innerEdges(i), 1) * 3 + inFace2;
  }

  for (int k = 0; k < basisCycles.outerSize(); ++k)
    for (SparseMatrix<double>::InnerIterator it(basisCycles, k); it; ++it) {
      cornerSets[it.row()].insert(
          edgeCorners(it.col(), it.value() < 0 ? 0 : 2));
      cornerSets[it.row()].insert(
          edgeCorners(it.col(), it.value() < 0 ? 1 : 3));
      vertexSets[it.row()].insert(
          mesh.EV(innerEdges(it.col()), it.value() < 0 ? 0 : 1));
    }

  for (int i = 0; i < cornerSets.size(); i++) {
    if (isBigCycle(i))
      cycleCurvature(i) = std::numbers::pi * (double)(vertexSets[i].size());
    else
      cycleCurvature(i) = 2.0 * std::numbers::pi;
    for (set<int>::iterator si = cornerSets[i].begin();
         si != cornerSets[i].end(); si++)
      cycleCurvature(i) -= allAngles(*si);
  }
}

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_MESH_TOPOLOGY_H
