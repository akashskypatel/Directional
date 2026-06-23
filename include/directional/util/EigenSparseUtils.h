// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_EIGEN_SPARSE_UTILS_H
#define DIRECTIONAL_EIGEN_SPARSE_UTILS_H

#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>


/**
 * @file EigenSparseUtils.h
 * @brief Sparse Eigen helper routines.
 *
 * Contains helpers for Kronecker-style field matrices and block diagonal sparse matrices.
 */

namespace directional {

/// @brief Computing a kronecker product of a sparse matrix with Id(N), in order
///        to make a matrix applicable to a raw N-field or N-function
/// @tparam Scalar The scalar type of the matrix.
/// @param singMat The sparse matrix to be used as the base for the kronecker
/// product.
/// @param N The degree for multiplication.
/// @param dRows The number of rows in the unit block.
/// @param dCols The number of columns in the unit block.
/// @return The resulting sparse matrix.
///
template <typename Scalar>
Eigen::SparseMatrix<Scalar>
single_to_N_matrix(const Eigen::SparseMatrix<Scalar> &singMat, const int N,
                   const int dRows, const int dCols) {
  Eigen::SparseMatrix<Scalar> NMat(singMat.rows() * N, singMat.cols() * N);
  std::vector<Eigen::Triplet<Scalar>> NMatTris;
  for (int k = 0; k < singMat.outerSize(); ++k)
    for (typename Eigen::SparseMatrix<Scalar>::InnerIterator it(singMat, k); it;
         ++it) {
      int rowPack = int(it.row() / dRows);
      int colPack = int(it.col() / dCols);
      int rowPos = it.row() % dRows;
      int colPos = it.col() % dCols;
      for (int j = 0; j < N; j++)
        NMatTris.push_back(Eigen::Triplet<Scalar>(
            N * dRows * rowPack + j * dRows + rowPos,
            N * dCols * colPack + j * dCols + colPos, it.value()));
    }

  NMat.setFromTriplets(NMatTris.begin(), NMatTris.end());
  return NMat;
}

/// @brief Computing a diagonal sparse matrix from a given vector of values.
/// @tparam Scalar The scalar type of the vector.
/// @param diagValues The vector of values to be used as diagonal entries.
/// @return The resulting sparse diagonal matrix.
///
template <typename Scalar>
Eigen::SparseMatrix<Scalar>
sparse_diagonal(const Eigen::Vector<Scalar, Eigen::Dynamic> &diagValues) {

  Eigen::SparseMatrix<Scalar> diagMatrix(diagValues.size(), diagValues.size());
  std::vector<Eigen::Triplet<Scalar>> diagMatTris;
  for (int i = 0; i < diagValues.size(); i++)
    diagMatTris.push_back(Eigen::Triplet<Scalar>(i, i, diagValues(i)));

  diagMatrix.setFromTriplets(diagMatTris.begin(), diagMatTris.end());
  return diagMatrix;
}

/// @brief A version that returns the matrix as a parameter
/// @tparam Scalar The scalar type of the matrix.
/// @param diagValues The vector of values to be used as diagonal entries.
/// @param diagMatrix The resulting sparse diagonal matrix.
///
template <typename Scalar>
inline void
sparse_diagonal(const std::vector<Eigen::SparseMatrix<Scalar>> &diagValues,
                Eigen::SparseMatrix<Scalar> &diagMatrix) {

  int numRows = 0, numCols = 0;
  Eigen::MatrixXi offsets(diagValues.size(), 2);
  for (int i = 0; i < diagValues.size(); i++) {
    offsets.row(i) << numRows, numCols;
    numRows += diagValues[i].rows();
    numCols += diagValues[i].cols();
  }
  diagMatrix.resize(numRows, numCols);
  std::vector<Eigen::Triplet<Scalar>> diagMatTris;
  for (int i = 0; i < diagValues.size(); i++) {
    for (int k = 0; k < diagValues[i].outerSize(); ++k) {
      for (Eigen::SparseMatrix<double>::InnerIterator it(diagValues[i], k); it;
           ++it) {
        diagMatTris.push_back(Eigen::Triplet<Scalar>(
            offsets(i, 0) + it.row(), offsets(i, 1) + it.col(), it.value()));
      }
    }
  }

  diagMatrix.setFromTriplets(diagMatTris.begin(), diagMatTris.end());
}

} // namespace directional

#endif