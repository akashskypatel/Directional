// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2022 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_CORE_TRIMESH_H
#define DIRECTIONAL_CORE_TRIMESH_H

#include <cassert>
#include <iostream>
#include <set>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Sparse>

#include <directional/core/DCEL.h>
#include <directional/geometry/Curvature.h>




/**
 * @file TriMesh.h
 * @brief Triangle mesh wrapper built on the Directional DCEL.
 *
 * Owns vertex and face matrices, edge/halfedge topology, and convenience accessors for halfedge traversal. This is the mesh representation used by field construction, integration, cutting, and meshing routines.
 */

namespace directional {

/**
 * @brief Triangle mesh geometry, topology, and derived differential quantities.
 *
 * The mesh stores raw vertex/face matrices plus derived edge topology, halfedge
 * connectivity, tangent bases, normals, areas, curvature estimates, and boundary
 * metadata. Call @ref set_mesh to initialize all derived data consistently.
 */
class TriMesh {
public:
  /// Vertex positions as a #V-by-3 matrix.
  Eigen::MatrixXd V;

  /// Triangle indices as a #F-by-3 matrix.
  Eigen::MatrixXi F;

  /// Edge-face, face-edge, edge-vertex, face-neighbor, edge-side, vertex-edge, and vertex-face adjacency tables.
  Eigen::MatrixXi EF, FE, EV, TT, EFi, VE, VF;

  /// Per-face edge lengths.
  Eigen::MatrixXd FEs;

  /// Interior edge ids, boundary edge ids, and outgoing vertex valences.
  Eigen::VectorXi innerEdges, boundEdges, vertexValence;

  /// Boundary flags for vertices and edges.
  Eigen::VectorXi isBoundaryVertex, isBoundaryEdge;

  /// DCEL specialization used by triangle meshes without custom payloads.
  typedef DCEL<int, int, int, int> TriMeshDCEL;

  /// Halfedge connectivity backing topology traversal helpers.
  TriMeshDCEL dcel;

  /** @name DCEL traversal helpers
   *  Lightweight accessors for representative halfedges, twins, next/previous
   *  halfedges, and incident vertex/face/edge ids.
   */
  /// @{
  inline int VH(const int index) const { return dcel.vertices[index].halfedge; }
  inline int twinH(const int index) const { return dcel.halfedges[index].twin; }
  inline int nextH(const int index) const { return dcel.halfedges[index].next; }
  inline int prevH(const int index) const { return dcel.halfedges[index].prev; }
  inline int HV(const int index) const { return dcel.halfedges[index].vertex; }
  inline int HF(const int index) const { return dcel.halfedges[index].face; }
  inline int HE(const int index) const { return dcel.halfedges[index].edge; }
  inline int EH(const int index, const int side) const {
    return (side == 0 ? dcel.edges[index].halfedge
                      : dcel.halfedges[dcel.edges[index].halfedge].twin);
  }
  inline int FH(const int index) const { return dcel.faces[index].halfedge; }
  inline int FH(const int index, const int inFace) const {
    int he = dcel.faces[index].halfedge;
    while (HV(he) != F(index, 0))
      he = nextH(he);
    for (int i = 0; i < inFace; i++)
      he = nextH(he);
    return he;
  }

  /// @}

  /// Per-face unit normals.
  Eigen::MatrixXd faceNormals;
  /// Per-face areas.
  Eigen::VectorXd faceAreas;
  /// Per-vertex area-weighted normals.
  Eigen::MatrixXd vertexNormals;
  /// Local tangent basis vectors per face.
  Eigen::MatrixXd FBx, FBy;

  /// Local tangent basis vectors per vertex.
  Eigen::MatrixXd VBx, VBy;

  /// Per-face barycenters.
  Eigen::MatrixXd barycenters;

  /// Per-edge midpoint positions.
  Eigen::MatrixXd midEdges;

  /// Per-vertex Gaussian curvature values.
  Eigen::VectorXd GaussianCurvature;
  std::vector<Eigen::Matrix2d> Sv, Sf;
  Eigen::MatrixXd minFacePrincipalDirections, minVertexPrincipalDirections;
  Eigen::MatrixXd maxFacePrincipalDirections, maxVertexPrincipalDirections;
  Eigen::MatrixXd facePrincipalCurvatures, vertexPrincipalCurvatures;

  /// Average edge length, used as a scale parameter by downstream algorithms.
  double avgEdgeLength = 0.0;

  /// Axis-aligned bounding-box corners.
  Eigen::RowVector3d minBox, maxBox;

  /// Euler characteristic of the mesh.
  int eulerChar = 0;

  /// Number of topological generators inferred from Euler characteristic and boundaries.
  int numGenerators = 0;

  /// Boundary loops represented as ordered vertex ids.
  std::vector<std::vector<int>> boundaryLoops;

  TriMesh() = default;
  ~TriMesh() = default;

  /**
   * @brief Builds edge, face, vertex, and halfedge adjacency tables.
   * @param verbose When true, prints detailed DCEL consistency failures.
   */
  void inline compute_edge_quantities(const bool verbose = false) {

    struct ComparePairs {
      bool operator()(const std::pair<std::pair<int, int>, int> &a,
                      const std::pair<std::pair<int, int>, int> &b) const {
        if (a.first.first == b.first.first) {
          return a.first.second < b.first.second;
        } else {
          return a.first.first < b.first.first;
        }
      }
    };

    // This is done in the polyscope compatible fashion
    dcel.init(V, F);
    if (!dcel.check_consistency(verbose, true, true, true)) {
      throw std::runtime_error(
          "compute_edge_quantities(): DCEL consistency check failed");
    }
    EV.resize(dcel.edges.size(), 2);
    EF = Eigen::MatrixXi::Constant(dcel.edges.size(), 2, -1);
    EFi = Eigen::MatrixXi::Constant(dcel.edges.size(), 2, -1);
    FE.resize(F.rows(), 3);
    FEs.resize(F.rows(), 3);
    TT = Eigen::MatrixXi::Constant(F.rows(), 3, -1);
    for (int i = 0; i < dcel.edges.size(); i++) {
      EV.row(i) << dcel.halfedges[dcel.edges[i].halfedge].vertex,
          dcel.halfedges[dcel.halfedges[dcel.edges[i].halfedge].next].vertex;
      EF(i, 0) = dcel.halfedges[dcel.edges[i].halfedge].face;
      if (dcel.halfedges[dcel.edges[i].halfedge].twin != -1)
        EF(i, 1) =
            dcel.halfedges[dcel.halfedges[dcel.edges[i].halfedge].twin].face;

      EFi(i, 0) = (dcel.edges[i].halfedge + 0) % 3;
      if (dcel.halfedges[dcel.edges[i].halfedge].twin != -1)
        EFi(i, 1) = (dcel.halfedges[dcel.edges[i].halfedge].twin + 0) % 3;
    }
    for (int i = 0; i < dcel.faces.size(); i++) {
      int hebegin = dcel.faces[i].halfedge;
      int heiterate = hebegin;
      int inFaceCounter = 0;
      do {
        FE(i, inFaceCounter) = dcel.halfedges[heiterate].edge;
        FEs(i, inFaceCounter) =
            (dcel.edges[dcel.halfedges[heiterate].edge].halfedge == heiterate
                 ? 1
                 : -1);
        if (dcel.halfedges[heiterate].twin != -1)
          TT(i, inFaceCounter) =
              dcel.halfedges[dcel.halfedges[heiterate].twin].face;
        inFaceCounter++;
        heiterate = dcel.halfedges[heiterate].next;
      } while (heiterate != hebegin);
    }

    // gathering all boundary halfedges
    std::vector<int> innerEdgesList, boundEdgesList, boundHalfedgesList;
    isBoundaryVertex = Eigen::VectorXi::Zero(V.rows());
    isBoundaryEdge = Eigen::VectorXi::Zero(EV.rows());
    for (int i = 0; i < dcel.edges.size(); i++) {
      if (dcel.halfedges[dcel.edges[i].halfedge].twin == -1) {
        boundEdgesList.push_back(i);
        boundHalfedgesList.push_back(dcel.edges[i].halfedge);
        isBoundaryEdge(i) = 1;
        isBoundaryVertex(EV(i, 0)) = 1;
        isBoundaryVertex(EV(i, 1)) = 1;
      } else
        innerEdgesList.push_back(i);
    }

    innerEdges = Eigen::Map<Eigen::VectorXi, Eigen::Unaligned>(
        innerEdgesList.data(), innerEdgesList.size());
    boundEdges = Eigen::Map<Eigen::VectorXi, Eigen::Unaligned>(
        boundEdgesList.data(), boundEdgesList.size());

    // creating boundary loops
    Eigen::VectorXi isVisited =
        Eigen::VectorXi::Constant(dcel.halfedges.size(), 0);
    while (isVisited.sum() != boundHalfedgesList.size()) {
      // choose a first one
      int beginHE;
      for (beginHE = 0; beginHE < boundHalfedgesList.size(); beginHE++)
        if (isVisited(boundHalfedgesList[beginHE]) == 0)
          break;

      beginHE = boundHalfedgesList[beginHE]; // in the global indexing
      int currHE = beginHE;
      std::vector<int> currBoundaryLoop;
      do {
        currBoundaryLoop.push_back(dcel.halfedges[currHE].vertex);
        isVisited(currHE) = 1;
        // finding the next boundary halfedge
        currHE = dcel.halfedges[currHE].next;
        while (dcel.halfedges[currHE].twin != -1)
          currHE = dcel.halfedges[dcel.halfedges[currHE].twin].next;
      } while (currHE != beginHE);
      boundaryLoops.push_back(currBoundaryLoop);
    }
  }

  void inline compute_geometric_quantities() {

    // barycenters and local bases
    barycenters.resize(F.rows(), 3);
    FBx.resize(F.rows(), 3);
    FBy.resize(F.rows(), 3);
    faceNormals.resize(F.rows(), 3);
    faceAreas.resize(F.rows());
    for (int i = 0; i < F.rows(); i++) {
      barycenters.row(i) =
          (V.row(F(i, 0)) + V.row(F(i, 1)) + V.row(F(i, 2))) / 3;
      Eigen::RowVector3d localx = V.row(F(i, 1)) - V.row(F(i, 0));
      Eigen::RowVector3d localy = V.row(F(i, 2)) - V.row(F(i, 0));
      Eigen::RowVector3d localz = localx.cross(localy);
      faceAreas(i) = localz.norm() / 2.0;
      localy = localz.cross(localx);
      FBx.row(i) = localx.normalized();
      FBy.row(i) = localy.normalized();
      faceNormals.row(i) = localz.normalized();
    }

    // computing vertex normals by area-weighted aveage of face normals
    vertexNormals = Eigen::MatrixXd::Zero(V.rows(), 3);
    for (int i = 0; i < F.rows(); i++)
      for (int j = 0; j < 3; j++)
        vertexNormals.row(F(i, j)).array() +=
            faceNormals.row(i).array() * faceAreas(i);

    vertexNormals.rowwise().normalize();

    // computing a local basis that aligns with the first projected edge of each
    // triangle
    VBx.resize(V.rows(), 3);
    VBy.resize(V.rows(), 3);
    for (int i = 0; i < V.rows(); i++) {
      Eigen::RowVector3d firstEdge =
          V.row(dcel.halfedges[dcel.halfedges[dcel.vertices[i].halfedge].next]
                    .vertex) -
          V.row(i);
      VBx.row(i) = firstEdge -
                   (firstEdge.dot(vertexNormals.row(i))) * vertexNormals.row(i);
      VBx.row(i).normalize();
      Eigen::RowVector3d currx = VBx.row(i);
      Eigen::RowVector3d currn = vertexNormals.row(i);
      VBy.row(i) = currn.cross(currx);
      VBy.row(i).normalize();
    }

    midEdges.resize(EV.rows(), 3);
    for (int i = 0; i < EV.rows(); i++)
      midEdges.row(i) = (V.row(EV(i, 0)) + V.row(EV(i, 1))) / 2.0;

    gaussian_curvature(V, F, isBoundaryVertex, GaussianCurvature);
    directional::shape_operator(V, EV, VBx, VBy, vertexNormals, Sv);
    minVertexPrincipalDirections.resize(V.rows(), 3);
    maxVertexPrincipalDirections.resize(V.rows(), 3);
    vertexPrincipalCurvatures.resize(V.rows(), 2);
    for (int i = 0; i < V.rows(); i++) {
      Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> eigensolver(Sv[i]);
      int minAbsIndex;
      eigensolver.eigenvalues().cwiseAbs().minCoeff(&minAbsIndex);
      int minIndex, maxIndex;
      minIndex =
          eigensolver.eigenvalues()(0) >= eigensolver.eigenvalues()(1) ? 1 : 0;
      maxIndex =
          eigensolver.eigenvalues()(0) >= eigensolver.eigenvalues()(1) ? 0 : 1;
      vertexPrincipalCurvatures.row(i) << eigensolver.eigenvalues()(minIndex),
          eigensolver.eigenvalues()(maxIndex);
      Eigen::RowVector2d minDirection =
          eigensolver.eigenvectors().col(minIndex).transpose();
      Eigen::RowVector2d maxDirection =
          eigensolver.eigenvectors().col(maxIndex).transpose();
      minVertexPrincipalDirections.row(i) =
          minDirection(0) * VBx.row(i) + minDirection(1) * VBy.row(i);
      maxVertexPrincipalDirections.row(i) =
          maxDirection(0) * VBx.row(i) + maxDirection(1) * VBy.row(i);
    }

    // Average edge length
    double sumEdgeLength = 0.0;
    for (int i = 0; i < EV.rows(); i++)
      sumEdgeLength += (V.row(EV(i, 0)) - V.row(EV(i, 1))).norm();

    avgEdgeLength = sumEdgeLength / (double)EV.rows();
  }

  void inline set_mesh(const Eigen::MatrixXd &_V, const Eigen::MatrixXi &_F,
                       const Eigen::MatrixXi &_EV = Eigen::MatrixXi(),
                       const Eigen::MatrixXi &_FE = Eigen::MatrixXi(),
                       const Eigen::MatrixXi &_EF = Eigen::MatrixXi(),
                       const bool verbose = false) {

    V = _V;
    F = _F;
    if (_EV.rows() == 0) {
      compute_edge_quantities(verbose);
    } else {
      EV = _EV;
      FE = _FE;
      EF = _EF;
    }

    compute_geometric_quantities();

    eulerChar = static_cast<int>(V.rows() - EV.rows() + F.rows());
    numGenerators = static_cast<int>((2 - eulerChar) / 2 -
                                     static_cast<int>(boundaryLoops.size()));
    minBox = V.colwise().minCoeff();
    maxBox = V.colwise().maxCoeff();

    // hedra::dcel(Eigen::VectorXi::Constant(F.rows(),3),F,EV,EF,EFi,
    // innerEdges,VH,EH,FH,HV,HE,HF,nextH,prevH,twinH);
    vertexValence = Eigen::VectorXi::Zero(V.rows());
    for (int i = 0; i < EV.rows(); i++) {
      vertexValence(EV(i, 0))++;
      vertexValence(EV(i, 1))++;
    }

    VE.resize(V.rows(), vertexValence.maxCoeff());
    VF.resize(V.rows(), vertexValence.maxCoeff());
    for (int i = 0; i < V.rows(); i++) {
      int counter = 0;
      int hebegin = dcel.vertices[i].halfedge;
      if (isBoundaryVertex(i)) // winding up hebegin to the first boundary edge
        while (dcel.halfedges[hebegin].twin != -1)
          hebegin = dcel.halfedges[dcel.halfedges[hebegin].twin].next;

      // resetting dcel pointer for future reference
      dcel.vertices[i].halfedge = hebegin;
      int heiterate = hebegin;
      do {
        VE(i, counter) = dcel.halfedges[heiterate].edge;
        VF(i, counter++) = dcel.halfedges[heiterate].face;
        if (dcel.halfedges[dcel.halfedges[heiterate].prev].twin == -1) {
          VE(i, counter) = dcel.halfedges[dcel.halfedges[heiterate].prev]
                               .edge; // note counter is already ahead
          break;
        }
        heiterate = dcel.halfedges[dcel.halfedges[heiterate].prev].twin;
      } while (hebegin != heiterate);
    }
  }
};

} // namespace directional

#endif // DIRECTIONAL_CORE_TRIMESH_H
