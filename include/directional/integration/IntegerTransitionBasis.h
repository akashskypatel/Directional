// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGER_TRANSITION_BASIS_H
#define DIRECTIONAL_INTEGRATION_INTEGER_TRANSITION_BASIS_H

#include <cstddef>
#include <vector>

#include <Eigen/Core>
#include <directional/core/Export.h>
#include <Eigen/Sparse>

namespace directional {

struct IntegerTransitionBasisOptions {
  bool reduceIntegerTransitionBasis = false;
};

struct IntegerTransitionBasisResult {
  std::size_t rawTransitionCount = 0;
  std::size_t rawIntegerVariableCount = 0;
  std::size_t reducedIntegerVariableCount = 0;
  std::size_t redundantIntegerVariableCount = 0;
  double reductionRatio = 0.0;
  double numericalRank = 0.0;
  double analysisSeconds = 0.0;
  bool exactReductionAvailable = false;
  bool reductionEnabled = false;
  Eigen::SparseMatrix<int> fullFromIndependent;
};

namespace detail {

class DIRECTIONAL_API IntegerTransitionBasis {
public:
  [[nodiscard]] static IntegerTransitionBasisResult analyze_relation_matrix(
      const Eigen::SparseMatrix<int> &relations,
      const IntegerTransitionBasisOptions &options = {});

  [[nodiscard]] static IntegerTransitionBasisResult
  analyze_expanded_integer_relations(
      const Eigen::SparseMatrix<int> &constraintMatrix,
      const Eigen::SparseMatrix<int> &linRed,
      const Eigen::SparseMatrix<int> &singularSpan,
      const Eigen::SparseMatrix<int> &integerSpan,
      const Eigen::VectorXi &integerVars, int reducedFunctionCount,
      const IntegerTransitionBasisOptions &options = {});
};

} // namespace detail

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGER_TRANSITION_BASIS_H
