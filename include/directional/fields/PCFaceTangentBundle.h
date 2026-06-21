// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_PIECWISE_CONSTANT_FACE_TANGENT_BUNDLE_H
#define DIRECTIONAL_FIELDS_PIECWISE_CONSTANT_FACE_TANGENT_BUNDLE_H

#include <iostream>

#include <Eigen/Geometry>
#include <Eigen/Sparse>

#include <directional/core/TangentBundle.h>
#include <directional/core/TriMesh.h>
#include <directional/geometry/MeshTopology.h>
#include <directional/util/EigenSparseUtils.h>

/***
 This class represents piecewise-constant face-based tangent bundles, where
 tangent spaces identify with the natural plane to every triangle of a
 2-manifold mesh, connections are across (dual) edges, and local cycles are
 around vertices, with curvature being discrete angle defect.
 ***/


/**
 * @file PCFaceTangentBundle.h
 * @brief Piecewise-constant face tangent bundle implementation.
 *
 * Defines a tangent bundle whose sources are mesh faces. It constructs per-face tangent bases, face adjacencies, connection rotations, local cycles, and mass matrices from a TriMesh.
 */

namespace directional {

/**
 * @brief Face-based piecewise-constant tangent bundle.
 *
 * Each triangle face contributes one tangent space located at its barycenter.
 * Adjacencies follow dual edges, and local bases are taken from the TriMesh face
 * frames.
 */
class PCFaceTangentBundle : public TangentBundle {
public:
  const TriMesh *mesh;

  discTangTypeEnum discTangType() const {
    return discTangTypeEnum::FACE_SPACES;
  }

  bool hasCochainSequence() const { return true; }
  bool hasEmbedding() const { return true; }

  PCFaceTangentBundle() {}
  ~PCFaceTangentBundle() override = default;

  void inline init(const TriMesh &_mesh) {

    intDimension = 2;
    numSpaces = static_cast<int>(_mesh.F.rows());
    avgAdjLength = _mesh.avgEdgeLength;
    typedef std::complex<double> Complex;
    mesh = &_mesh;

    // adjacency relation is by dual edges.
    adjSpaces = mesh->EF;
    oneRing = mesh->FE;
    sources = mesh->barycenters;
    normals = mesh->faceNormals;
    cycleSources = mesh->V;
    cycleNormals = mesh->vertexNormals;

    // connection is the ratio of the complex representation of edges
    connection.resize(mesh->EF.rows(),
                      1); // the difference in the angle representation of edge
                          // i from EF(i,0) to EF(i,1)
    Eigen::MatrixXd edgeVectors(mesh->EF.rows(), 3);
    for (int i = 0; i < mesh->EF.rows(); i++) {
      if (mesh->EF(i, 0) == -1 || mesh->EF(i, 1) == -1)
        continue;
      edgeVectors.row(i) =
          (mesh->V.row(mesh->EV(i, 1)) - mesh->V.row(mesh->EV(i, 0)))
              .normalized();
      Complex ef(edgeVectors.row(i).dot(mesh->FBx.row(mesh->EF(i, 0))),
                 edgeVectors.row(i).dot(mesh->FBy.row(mesh->EF(i, 0))));
      Complex eg(edgeVectors.row(i).dot(mesh->FBx.row(mesh->EF(i, 1))),
                 edgeVectors.row(i).dot(mesh->FBy.row(mesh->EF(i, 1))));
      connection(i) = eg / ef;
    }

    directional::dual_cycles(*mesh, cycles, cycleCurvatures, local2Cycle,
                             innerAdjacencies);

    // Face area is the natural mass for piecewise-constant face fields.

    tangentSpaceMass = directional::sparse_diagonal(mesh->faceAreas);
    Eigen::VectorXd invFaceAreas = mesh->faceAreas.array().inverse();
    invTangentSpaceMass = directional::sparse_diagonal(invFaceAreas);

    // The "harmonic" weights from [Brandt et al. 2020].
    Eigen::VectorXd connMassVector =
        Eigen::VectorXd::Zero(mesh->innerEdges.size());
    for (int i = 0; i < mesh->innerEdges.size(); i++) {
      // if ((mesh->EF(i,0)==-1)||(mesh->EF(i,1)==-1))
      //     continue;  //boundary edge

      double primalLengthSquared =
          (mesh->V.row(mesh->EV(mesh->innerEdges(i), 0)) -
           mesh->V.row(mesh->EV(mesh->innerEdges(i), 1)))
              .squaredNorm();
      connMassVector(i) = 3.0 * primalLengthSquared /
                          (mesh->faceAreas(mesh->EF(mesh->innerEdges(i), 0)) +
                           mesh->faceAreas(mesh->EF(mesh->innerEdges(i), 1)));
    }
    connectionMass = directional::sparse_diagonal(connMassVector);
  }

  // projecting an arbitrary set of extrinsic vectors (e.g. coming from
  // user-prescribed constraints) into intrinsic vectors.
  Eigen::MatrixXd virtual inline project_to_intrinsic(
      const Eigen::VectorXi &tangentSpaces,
      const Eigen::MatrixXd &extDirectionals) const {
    if (tangentSpaces.rows() != extDirectionals.rows()) {
      throw std::runtime_error("tangentSpaces and extDirectionals must have "
                               "the same number of rows");
    }

    int N = static_cast<int>(extDirectionals.cols() / 3);
    Eigen::MatrixXd intDirectionals(tangentSpaces.rows(), 2 * N);

    for (int i = 0; i < tangentSpaces.rows(); i++)
      for (int j = 0; j < N; j++)
        intDirectionals.block(i, 2 * j, 1, 2)
            << (extDirectionals.block(i, 3 * j, 1, 3).array() *
                mesh->FBx.row(tangentSpaces(i)).array())
                   .sum(),
            (extDirectionals.block(i, 3 * j, 1, 3).array() *
             mesh->FBy.row(tangentSpaces(i)).array())
                .sum();

    return intDirectionals;
  }

  // projecting intrinsic to extrinsic
  Eigen::MatrixXd virtual inline project_to_extrinsic(
      const Eigen::VectorXi &tangentSpaces,
      const Eigen::MatrixXd &intDirectionals) const {

    if (tangentSpaces.rows() != intDirectionals.rows() &&
        tangentSpaces.rows() != 0) {
      throw std::runtime_error("tangentSpaces and intDirectionals must have "
                               "the same number of rows");
    }
    Eigen::VectorXi actualTangentSpaces;
    if (tangentSpaces.rows() == 0)
      actualTangentSpaces =
          Eigen::VectorXi::LinSpaced(static_cast<int>(sources.rows()), 0,
                                     static_cast<int>(sources.rows() - 1));
    else
      actualTangentSpaces = tangentSpaces;

    Eigen::MatrixXd extDirectionals(actualTangentSpaces.rows(), 3);

    extDirectionals.conservativeResize(intDirectionals.rows(),
                                       intDirectionals.cols() * 3 / 2);
    for (int i = 0; i < intDirectionals.rows(); i++)
      for (int j = 0; j < intDirectionals.cols(); j += 2)
        extDirectionals.block(i, 3 * j / 2, 1, 3) =
            mesh->FBx.row(actualTangentSpaces(i)) * intDirectionals(i, j) +
            mesh->FBy.row(actualTangentSpaces(i)) * intDirectionals(i, j + 1);

    return extDirectionals;
  }

  void inline interpolate(const Eigen::MatrixXi &elemIndices,
                          const Eigen::MatrixXd &baryCoords,
                          const Eigen::MatrixXd &intDirectionals,
                          Eigen::MatrixXd &interpSources,
                          Eigen::MatrixXd &interpNormals,
                          Eigen::MatrixXd &interpField) const {

    if (elemIndices.rows() != baryCoords.rows() ||
        baryCoords.rows() != intDirectionals.rows()) {
      throw std::runtime_error("elemIndices, baryCoords, and intDirectionals "
                               "must have the same number of rows");
    }

    int N = static_cast<int>(intDirectionals.cols() / 2);
    interpSources = Eigen::MatrixXd::Zero(elemIndices.rows(), 3);
    interpNormals = Eigen::MatrixXd::Zero(elemIndices.rows(), 3);
    interpField = Eigen::MatrixXd::Zero(elemIndices.rows(), 3 * N);

    // in face based fields the only thing that matters is the identity of the
    // face
    for (int i = 0; i < elemIndices.rows(); i++) {
      for (int j = 0; j < 3; j++)
        interpSources.row(i).array() +=
            mesh->V.row(mesh->F(elemIndices(i), j)).array() * baryCoords(i, j);
      interpNormals.row(i) = mesh->faceNormals.row(elemIndices(i));
      for (int j = 0; j < N; j++)
        interpField.block(i, j * 3, 1, 3) =
            intDirectionals(elemIndices(i), j * 2) *
                mesh->FBx.row(elemIndices(i)) +
            intDirectionals(elemIndices(i), j * 2 + 1) *
                mesh->FBy.row(elemIndices(i));
    }
  }
};

} // namespace directional

#endif // DIRECTIONAL_FIELDS_PIECWISE_CONSTANT_FACE_TANGENT_BUNDLE_H
