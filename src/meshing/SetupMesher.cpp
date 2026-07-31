#include <directional/meshing/SetupMesher.h>

#include <vector>

#include <Eigen/Sparse>

#include <directional/core/TriMesh.h>
#include <directional/integration/IntegrationData.h>
#include <directional/meshing/MesherData.h>

namespace directional {

void setup_mesher(const TriMesh &meshCut, const IntegrationData &intData,
                  MesherData &mesherData) {
  mesherData.cutV = meshCut.V;
  mesherData.cutF = meshCut.F;
  mesherData.vertexNFunction = intData.nVertexFunction;
  const bool signSymmetry = intData.N % 2 == 0;
  Eigen::SparseMatrix<double> orig2CutMatFull =
      intData.vertexTrans2CutMat * intData.linRedMat * intData.singIntSpanMat *
      intData.intSpanMat;
  Eigen::SparseMatrix<int> exactOrig2CutMatFull =
      intData.vertexTrans2CutMatInteger * intData.linRedMatInteger *
      intData.singIntSpanMatInteger * intData.intSpanMatInteger;

  if (signSymmetry) {
    mesherData.N = intData.N / 2;
    std::vector<Eigen::Triplet<double>> orig2CutTriplets;
    std::vector<Eigen::Triplet<int>> exactOrig2CutTriplets;
    for (int k = 0; k < orig2CutMatFull.outerSize(); ++k) {
      for (Eigen::SparseMatrix<double>::InnerIterator it(orig2CutMatFull, k);
           it; ++it) {
        const int relativeRow = static_cast<int>(it.row() % intData.N);
        if (relativeRow < intData.N / 2) {
          orig2CutTriplets.emplace_back(
              static_cast<int>((it.row() - relativeRow) / 2 + relativeRow),
              static_cast<int>(it.col()), it.value());
        }
      }
    }

    for (int k = 0; k < exactOrig2CutMatFull.outerSize(); ++k) {
      for (Eigen::SparseMatrix<int>::InnerIterator it(exactOrig2CutMatFull, k);
           it; ++it) {
        const int relativeRow = static_cast<int>(it.row() % intData.N);
        if (relativeRow < intData.N / 2) {
          exactOrig2CutTriplets.emplace_back(
              static_cast<int>((it.row() - relativeRow) / 2 + relativeRow),
              static_cast<int>(it.col()), it.value());
        }
      }
    }

    mesherData.orig2CutMat.resize(orig2CutMatFull.rows() / 2,
                                  orig2CutMatFull.cols());
    mesherData.orig2CutMat.setFromTriplets(orig2CutTriplets.begin(),
                                           orig2CutTriplets.end());
    mesherData.exactOrig2CutMat.resize(exactOrig2CutMatFull.rows() / 2,
                                       exactOrig2CutMatFull.cols());
    mesherData.exactOrig2CutMat.setFromTriplets(exactOrig2CutTriplets.begin(),
                                                exactOrig2CutTriplets.end());
  } else {
    mesherData.N = intData.N;
    mesherData.orig2CutMat = orig2CutMatFull;
    mesherData.exactOrig2CutMat = exactOrig2CutMatFull;
  }

  mesherData.integerVars.resize(intData.n * intData.integerVars.size());
  for (int variable = 0; variable < intData.integerVars.size(); ++variable) {
    for (int coordinate = 0; coordinate < intData.n; ++coordinate) {
      mesherData.integerVars(intData.n * variable + coordinate) =
          intData.n * intData.integerVars(variable) + coordinate;
    }
  }
}

} // namespace directional
