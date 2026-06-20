#pragma once

#ifndef DIRECTIONAL_MESHING_SETUP_MESHER_H
#define DIRECTIONAL_MESHING_SETUP_MESHER_H

#include <Eigen/Sparse>
#include <directional/core/TriMesh.h>
#include <directional/geometry/MeshTopology.h>
#include <directional/integration/IntegrationData.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/meshing/MesherData.h>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>

namespace directional {

/// @brief setups the meshing data from the (in-house) integration data
/// @param meshCut Cut mesh
/// @param intData IntegrationData object from the integrator
/// @param mesherData MesherData object suitable to pass to the mesher
void setup_mesher(const directional::TriMesh &meshCut,
                  const IntegrationData &intData, MesherData &mesherData) {

  mesherData.cutV = meshCut.V;
  mesherData.cutF = meshCut.F;
  mesherData.vertexNFunction = intData.nVertexFunction;
  bool signSymmetry = (intData.N % 2 == 0);
  Eigen::SparseMatrix<double> orig2CutMatFull =
      intData.vertexTrans2CutMat * intData.linRedMat * intData.singIntSpanMat *
      intData.intSpanMat;
  Eigen::SparseMatrix<int> exactOrig2CutMatFull =
      intData.vertexTrans2CutMatInteger * intData.linRedMatInteger *
      intData.singIntSpanMatInteger * intData.intSpanMatInteger;

  // cuttting the matrices from sign symmetrry
  if (signSymmetry) {
    mesherData.N = intData.N / 2;
    // cutting the latter N/2 from each N packet.
    std::vector<Eigen::Triplet<double>> orig2CutTriplets;
    std::vector<Eigen::Triplet<int>> exactorig2CutTriplets;
    for (int k = 0; k < orig2CutMatFull.outerSize(); ++k) {
      for (Eigen::SparseMatrix<double>::InnerIterator it(orig2CutMatFull, k);
           it; ++it) {
        int relativeRow = it.row() % intData.N;
        if (relativeRow < intData.N / 2)
          orig2CutTriplets.push_back(
              Eigen::Triplet<double>((it.row() - relativeRow) / 2 + relativeRow,
                                     it.col(), it.value()));
      }
    }

    for (int k = 0; k < exactOrig2CutMatFull.outerSize(); ++k) {
      for (Eigen::SparseMatrix<int>::InnerIterator it(exactOrig2CutMatFull, k);
           it; ++it) {
        int relativeRow = it.row() % intData.N;
        if (relativeRow < intData.N / 2)
          exactorig2CutTriplets.push_back(
              Eigen::Triplet<int>((it.row() - relativeRow) / 2 + relativeRow,
                                  it.col(), it.value()));
      }
    }

    mesherData.orig2CutMat.resize(orig2CutMatFull.rows() / 2,
                                  orig2CutMatFull.cols());
    mesherData.orig2CutMat.setFromTriplets(orig2CutTriplets.begin(),
                                           orig2CutTriplets.end());

    mesherData.exactOrig2CutMat.resize(exactOrig2CutMatFull.rows() / 2,
                                       exactOrig2CutMatFull.cols());
    mesherData.exactOrig2CutMat.setFromTriplets(exactorig2CutTriplets.begin(),
                                                exactorig2CutTriplets.end());

  } else {
    mesherData.N = intData.N;
    mesherData.orig2CutMat = orig2CutMatFull;
    mesherData.exactOrig2CutMat = exactOrig2CutMatFull;
  }

  mesherData.integerVars.resize(intData.n * intData.integerVars.size());
  for (int j = 0; j < intData.integerVars.size(); j++)
    for (int k = 0; k < intData.n; k++)
      mesherData.integerVars(intData.n * j + k) =
          intData.n * intData.integerVars(j) + k;
}

} // namespace directional

#endif // DIRECTIONAL_MESHING_SETUP_MESHER_H
