#pragma once

#ifndef DIRECTIONAL_MESHING_MESHER_DATA_H
#define DIRECTIONAL_MESHING_MESHER_DATA_H

#include <Eigen/Core>
#include <Eigen/Sparse>

namespace directional {

// Saving all necessary data for the isoline-mesher
struct MesherData {
  int N; // Number of meshed functions
  Eigen::VectorXd
      vertexNFunction; //"Compressed" vertex-based function on original mesh
  Eigen::SparseMatrix<double>
      orig2CutMat; // Producing the function on the cut-mesh, considering all
                   // symmetries.
  Eigen::SparseMatrix<int> exactOrig2CutMat; // The exact version
  Eigen::MatrixXd cutV;                      // Cut mesh vertices
  Eigen::MatrixXi cutF;                      // Cut mesh faces
  Eigen::VectorXi
      integerVars;        // Variables within vertexNFunction that are integer
  double exactResolution; // Rounding-off resolution for vertexNFunction

  bool verbose; // Printing output for the process

  MesherData() : exactResolution(10e-9), verbose(false) {}
  ~MesherData() {}
};

} // namespace directional

#endif // DIRECTIONAL_MESHING_MESHER_DATA_H
