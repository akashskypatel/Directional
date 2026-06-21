// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_UTIL_EIGEN_INDEX_UTILS_H
#define DIRECTIONAL_UTIL_EIGEN_INDEX_UTILS_H

#include <set>
#include <vector>

#include <Eigen/Core>


/**
 * @file EigenIndexUtils.h
 * @brief Small Eigen indexing helpers.
 *
 * Contains utility routines for vector set difference and indexed matrix slicing used by the geometry and integration code.
 */

namespace directional {

/// @brief Set Difference between two vectors A/B, putting the result in C, and
///        outputting in IA the indices into A of all elements in B.
/// @param[in] A        input vector
/// @param[in] B        input vector
/// @param[out] C       output vector with elements in A but not in B
/// @param[out] IA      indices into A of elements in C
template <typename T>
inline void set_diff(const Eigen::Matrix<T, Eigen::Dynamic, 1> &A,
                     const Eigen::Matrix<T, Eigen::Dynamic, 1> &B,
                     Eigen::Matrix<T, Eigen::Dynamic, 1> &C,
                     Eigen::VectorXi &IA) {

  std::vector<T> CList;
  std::vector<int> IAList;
  std::set<T> BSet(B.begin(), B.end());
  for (int i = 0; i < A.size(); i++) {
    if (BSet.find(A[i]) !=
        BSet.end()) // found in both A and B and thus not included
      continue;

    CList.push_back(A[i]);
    IAList.push_back(i);
  }
  C.resize(CList.size());
  IA.resize(IAList.size());
  std::copy(CList.begin(), CList.end(), C.data());
  std::copy(IAList.begin(), IAList.end(), IA.data());
}

/// @brief Slicing a matrix by rowIndices and colIndices, and outputting the
/// results in
///        B.
/// @param[in] A            input matrix
/// @param[in] rowIndices   row indices to slice
/// @param[in] colIndices   column indices to slice
/// @param[out] B           output matrix with elements at rowIndices and
/// colIndices
template <typename T>
inline void
matrix_slice(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> A,
             const Eigen::VectorXi &rowIndices,
             const Eigen::VectorXi &colIndices,
             Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> &B) {

  B.resize(rowIndices.size(), colIndices.size());
  for (int i = 0; i < rowIndices.size(); i++)
    for (int j = 0; j < colIndices.size(); j++)
      B(i, j) = A(rowIndices(i), colIndices(j));
}

} // namespace directional

#endif
