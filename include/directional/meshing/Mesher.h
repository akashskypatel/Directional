// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_MESHER_H
#define DIRECTIONAL_MESHING_MESHER_H

#include <chrono>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>

#include <Eigen/Sparse>

#include <directional/core/TriMesh.h>
#include <directional/geometry/MeshTopology.h>
#include <directional/meshing/GenerateMesh.h>
#include <directional/meshing/MesherData.h>
#include <directional/meshing/NFunctionMesher.h>
#include <directional/meshing/SetupMesher.h>



/**
 * @file Mesher.h
 * @brief Abstract mesher interface.
 *
 * Defines the small common interface for meshing backends that consume prepared meshing data and generate output geometry.
 */

namespace directional {

/**
 * @brief Generates a polygonal mesh from integrated integer isolines.
 * @param origMesh Original uncut source mesh.
 * @param mData Meshing data prepared by @ref setup_mesher.
 * @param VOutput Output generated vertex positions.
 * @param DOutput Output face degrees/valences.
 * @param FOutput Output polygon vertex indices, padded to max degree.
 * @return True when simplification and output assembly succeed.
 */
inline bool mesher(const directional::TriMesh &origMesh, const MesherData &mData,
            Eigen::MatrixXd &VOutput, Eigen::VectorXi &DOutput,
            Eigen::MatrixXi &FOutput) {

  report_progress(mData.progress, 1, 3, "Initializing mesh generator");
  NFunctionMesher functionMesher(origMesh, mData);
  functionMesher.init();

  if (mData.verbose)
    std::cout << "[Directional::mesher()]: " << "Generating mesh" << std::endl;

  report_progress(mData.progress, 2, 3, "Generating mesh topology");
  functionMesher.generate_mesh();
  if (mData.verbose)
    std::cout << "[Directional::mesher()]: " << "Done generating!" << std::endl;

  Eigen::VectorXi genInnerEdges, genTF;
  Eigen::MatrixXi genEV, genEFi, genEF, genFE, genTEdges;
  Eigen::MatrixXd genFEs, genCEdges, genVEdges;

  report_progress(mData.progress, 3, 3, "Simplifying generated mesh");
  bool success;
  if (mData.verbose) {
    std::cout << "[Directional::mesher()]: " << "Cleaning Mesh" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    success = functionMesher.simplify_mesh();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "[Directional::mesher()]: " << "Mesh simplification time: "
              << duration.count() / 1e+6 << " seconds" << std::endl;
  } else {
    success = functionMesher.simplify_mesh();
  }

  if (success) {
    if (mData.verbose)
      std::cout << "[Directional::mesher()]: " << "Cleaning succeeded!"
                << std::endl;

    functionMesher.to_polygonal(VOutput, DOutput, FOutput);
  } else if (mData.verbose)
    std::cout << "[Directional::mesher()]: " << "Cleaning failed!" << std::endl;

  return success;
}

} // namespace directional

#endif // DIRECTIONAL_MESHING_MESHER_H
