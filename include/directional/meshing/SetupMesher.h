// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_SETUP_MESHER_H
#define DIRECTIONAL_MESHING_SETUP_MESHER_H

#include <fstream>
#include <iosfwd>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>

#include <Eigen/Sparse>

#include <directional/core/TriMesh.h>
#include <directional/geometry/MeshTopology.h>
#include <directional/integration/IntegrationData.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/meshing/MesherData.h>


/**
 * @file SetupMesher.h
 * @brief Mesher setup routine.
 *
 * Transfers cut-mesh and integration data into a MesherData instance and prepares the structures consumed by NFunctionMesher.
 */

namespace directional {

/**
 * @brief Converts integration output into mesher input data.
 * @param meshCut Cut mesh used by the integration stage.
 * @param intData Integration state produced by setup/integrate.
 * @param mesherData Output structure consumed by @ref mesher or @ref NFunctionMesher.
 *
 * Handles sign-symmetry reduction, exact integer transfer matrices, and the
 * per-vertex N-function layout expected by the meshing stage.
 */
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

  // Reduce duplicated sign-symmetric packets when N is even.
  if (signSymmetry) {
    mesherData.N = intData.N / 2;
    // cutting the latter N/2 from each N packet.
    std::vector<Eigen::Triplet<double>> orig2CutTriplets;
    std::vector<Eigen::Triplet<int>> exactorig2CutTriplets;
    for (int k = 0; k < orig2CutMatFull.outerSize(); ++k) {
      for (Eigen::SparseMatrix<double>::InnerIterator it(orig2CutMatFull, k);
           it; ++it) {
        int relativeRow = static_cast<int>(it.row() % intData.N);
        if (relativeRow < intData.N / 2)
          orig2CutTriplets.push_back(Eigen::Triplet<double>(
              static_cast<int>((it.row() - relativeRow) / 2 + relativeRow),
              static_cast<int>(it.col()), it.value()));
      }
    }

    for (int k = 0; k < exactOrig2CutMatFull.outerSize(); ++k) {
      for (Eigen::SparseMatrix<int>::InnerIterator it(exactOrig2CutMatFull, k);
           it; ++it) {
        int relativeRow = static_cast<int>(it.row() % intData.N);
        if (relativeRow < intData.N / 2)
          exactorig2CutTriplets.push_back(Eigen::Triplet<int>(
              static_cast<int>((it.row() - relativeRow) / 2 + relativeRow),
              static_cast<int>(it.col()), it.value()));
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
