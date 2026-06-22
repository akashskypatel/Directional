
// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGRATION_DATA_H
#define DIRECTIONAL_INTEGRATION_INTEGRATION_DATA_H

#include <Eigen/Core>
#include <Eigen/Sparse>

#include <directional/util/Progress.h>


/**
 * @file IntegrationData.h
 * @brief Configuration and results storage for field integration.
 *
 * Stores period matrices, symmetry reductions, integer constraints, solved function values, and derived integrated field quantities used by the integration solver.
 */

namespace directional {
/**
 * @brief Mutable state exchanged between integration setup and solving.
 *
 * The structure contains symmetry reductions, period matrices, sparse linear
 * systems, solved N-function values, and derived per-corner functions.
 */
struct IntegrationData {
  /// Number of uncompressed parametric functions.
  int N;

  /// Number of independent parametric functions after symmetry reduction.
  int n;

  /// Linear reduction mapping independent functions to the full N-function set.
  Eigen::MatrixXi linRed;

  /// Integer period basis for the independent function lattice.
  Eigen::MatrixXi periodMat;

  /// Maps whole-mesh vertex/translation-jump values to cut-mesh vertex values.
  Eigen::SparseMatrix<double> vertexTrans2CutMat;

  /// Linear constraints generated from nonsingular nodes.
  Eigen::SparseMatrix<double> constraintMat;

  /// Sparse uncompression matrix from n reduced functions to N functions.
  Eigen::SparseMatrix<double> linRedMat;

  /// Sparse basis spanning translational jump variables.
  Eigen::SparseMatrix<double> intSpanMat;

  /// Sparse basis layer used to represent singularity-induced jumps.
  Eigen::SparseMatrix<double> singIntSpanMat;

  /// Vertices fixed by integration constraints.
  Eigen::VectorXi constrainedVertices;

  /// Variable ids that must take integer values.
  Eigen::VectorXi integerVars;

  /// #F-by-3 map of source face edges that become seams.
  Eigen::MatrixXi face2cut;

  /// Final compressed vertex N-function used by meshing.
  Eigen::VectorXd nVertexFunction;

  /// Indices fixed to remove translational null space.
  Eigen::VectorXi fixedIndices;

  /// Values assigned to @ref fixedIndices.
  Eigen::VectorXd fixedValues;

  /// Singular-vertex indices used by setup and meshing.
  Eigen::VectorXi singularIndices;

  /// Exact integer variant of @ref vertexTrans2CutMat.
  Eigen::SparseMatrix<int> vertexTrans2CutMatInteger;

  /// Exact integer variant of @ref constraintMat.
  Eigen::SparseMatrix<int> constraintMatInteger;

  /// Exact integer variant of @ref linRedMat.
  Eigen::SparseMatrix<int> linRedMatInteger;

  /// Exact integer variant of @ref intSpanMat.
  Eigen::SparseMatrix<int> intSpanMatInteger;

  /// Exact integer variant of @ref singIntSpanMat.
  Eigen::SparseMatrix<int> singIntSpanMatInteger;

  /// Global scaling applied to integrated functions.
  double lengthRatio;

  /// Enables full translational seamlessness constraints.
  bool integralSeamless;

  /// Rounds seam or singularity variables during integration.
  bool roundSeams;

  /// Emits solver logs when true.
  bool verbose;

  /// Optional progress callback invoked by integration solver stages.
  ProgressCallback progress;

  IntegrationData(int _N)
      : lengthRatio(0.02), integralSeamless(false), roundSeams(true),
        verbose(false) {
    N = _N;
    n = (N % 2 == 0 ? N / 2 : N);
    if (N % 2 == 0)
      set_sign_symmetry(N);
    else
      linRed = Eigen::MatrixXi::Identity(N, n);
    set_default_period_matrix(n);
  }
  ~IntegrationData() = default;

  /**
   * @brief Replaces the active linear reduction and period basis.
   * @param _linRed Full-to-reduced linear reduction matrix.
   * @param _periodMat Integer period matrix for the reduced functions.
   */
  inline void set_linear_reduction(const Eigen::MatrixXi &_linRed,
                                   const Eigen::MatrixXi &_periodMat) {
    linRed = _linRed;
    N = static_cast<int>(linRed.rows());
    n = static_cast<int>(linRed.cols());
    periodMat = _periodMat;
  }

  /**
   * @brief Sets sign symmetry for even-degree fields.
   * @param newN Even full field degree.
   * @throws std::runtime_error if @p newN is odd.
   */
  inline void set_sign_symmetry(int newN) {
    if (newN % 2 != 0) {
      throw std::runtime_error("set_sign_symmetry() only works with even N");
    }
    linRed.resize(newN, newN / 2);
    linRed << Eigen::MatrixXi::Identity(newN / 2, newN / 2),
        -Eigen::MatrixXi::Identity(newN / 2, newN / 2);
    n = newN / 2;
    set_default_period_matrix(n);
  }

  /**
   * @brief Sets triangular symmetry for degrees divisible by three.
   * @param newN Full field degree divisible by three.
   * @throws std::runtime_error if @p newN is not divisible by three.
   */
  inline void set_triangular_symmetry(int newN) {
    if (newN % 3 != 0) {
      throw std::runtime_error(
          "set_triangular_symmetry() only works with N%3==0");
    }
    if (newN % 2 == 0) {
      linRed.resize(newN, newN / 3);
      linRed.block(0, 0, newN / 2, newN / 3)
          << Eigen::MatrixXi::Identity(newN / 3, newN / 3),
          -Eigen::MatrixXi::Identity(newN / 6, newN / 6),
          Eigen::MatrixXi::Identity(newN / 6, newN / 6);
      linRed.block(newN / 2, 0, newN / 2, newN / 3) =
          -linRed.block(0, 0, newN / 2, newN / 3);
      n = newN / 3;
    } else {
      linRed.resize(newN, 2 * newN / 3);
      linRed << Eigen::MatrixXi::Identity(2 * newN / 3, 2 * newN / 3),
          -Eigen::MatrixXi::Identity(newN / 3, newN / 3),
          -Eigen::MatrixXi::Identity(newN / 3, newN / 3);
      n = 2 * newN / 3;
    }
    set_default_period_matrix(n);
  }

  /**
   * @brief Resets the period matrix to an identity lattice.
   * @param newn Number of independent functions.
   */
  inline void set_default_period_matrix(int newn) {
    periodMat = Eigen::MatrixXi::Identity(newn, newn);
  }
};
} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGRATION_DATA_H
