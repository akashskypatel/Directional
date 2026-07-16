// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_DIAGNOSTICS_INTEGRATION_DIAGNOSTICS_H
#define DIRECTIONAL_DIAGNOSTICS_INTEGRATION_DIAGNOSTICS_H

#include <cstddef>
#include <limits>
#include <vector>

namespace directional {

/** @brief Machine-readable timing, count, and quality data for integration. */
struct IntegrationDiagnostics {
  double totalSeconds = 0.0;
  double fullEnergyPrecomputeSeconds = 0.0;
  double freeVariableMapSeconds = 0.0;
  double reducedOperatorExtractionSeconds = 0.0;
  double constraintRankReductionSeconds = 0.0;
  double kktAssemblySeconds = 0.0;
  double rhsAssemblySeconds = 0.0;
  double symbolicAnalysisSeconds = 0.0;
  double numericFactorizationSeconds = 0.0;
  double backSubstitutionSeconds = 0.0;
  double fullSolutionReconstructionSeconds = 0.0;
  double integerCandidateSelectionSeconds = 0.0;

  std::size_t integerIterations = 0;
  std::size_t roundingBatches = 0;
  std::vector<std::size_t> roundingBatchHistogram;
  std::size_t directFactorizations = 0;
  std::size_t iterativeAttempts = 0;
  std::size_t iterativeSuccesses = 0;
  std::size_t iterativeFailures = 0;
  std::size_t directFallbacks = 0;
  std::size_t adaptiveDisabledAfterFailures = 0;
  std::size_t iterativeIterations = 0;
  std::size_t factorizationFailures = 0;
  std::size_t solveFailures = 0;
  std::size_t maximumFreeVariables = 0;
  std::size_t maximumConstraintRows = 0;
  std::size_t maximumSystemRows = 0;
  std::size_t maximumSystemNonZeros = 0;
  double iterativeSolverSeconds = 0.0;
  double directFactorizationSecondsAvoided = 0.0;
  double medianIterationsPerIterativeSolve = 0.0;

  double finalLinearSystemResidualNorm =
      std::numeric_limits<double>::quiet_NaN();
  double finalConstraintResidualNorm = std::numeric_limits<double>::quiet_NaN();
  double maximumUnresolvedIntegerResidual = 0.0;
  double finalIntegrationEnergy = std::numeric_limits<double>::quiet_NaN();

#ifdef USE_SUITESPARSE_ENABLED
  double umfpackTotalFlops = 0.0;
  double umfpackMaximumLNonzeros = 0.0;
  double umfpackMaximumUNonzeros = 0.0;
  double umfpackMaximumPeakMemory = 0.0;
#endif
};

} // namespace directional

#endif // DIRECTIONAL_DIAGNOSTICS_INTEGRATION_DIAGNOSTICS_H
