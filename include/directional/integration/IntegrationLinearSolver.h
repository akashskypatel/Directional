// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGRATION_LINEAR_SOLVER_H
#define DIRECTIONAL_INTEGRATION_INTEGRATION_LINEAR_SOLVER_H

namespace directional {

/** @brief Sparse direct solver used by the integer-integration KKT systems. */
enum class IntegrationLinearSolver {
  /** Select the best backend compiled into the current build. */
  Default,
  /** Use Intel oneMKL PARDISO symmetric-indefinite LDLT. */
  Pardiso,
  /** Use NVIDIA cuDSS general sparse LDU factorization. */
  CuDss,
  /** Use SuiteSparse UMFPACK general sparse LU factorization. */
  Umfpack,
  /** Use Eigen SparseLU general sparse LU factorization. */
  EigenSparseLU
};

/**
 * @brief Resolves the default solver to a backend available in this build.
 *
 * PARDISO remains preferred when both optional backends are enabled because it
 * is the currently validated production backend for the integration KKT solve.
 * cuDSS is selected automatically when it is the only optional backend.
 */
[[nodiscard]] constexpr IntegrationLinearSolver
resolve_default_integration_linear_solver() noexcept {
#if defined(DIRECTIONAL_HAS_PARDISO)
  return IntegrationLinearSolver::Pardiso;
#elif defined(DIRECTIONAL_HAS_CUDSS)
  return IntegrationLinearSolver::CuDss;
#elif defined(USE_SUITESPARSE_ENABLED)
  return IntegrationLinearSolver::Umfpack;
#else
  return IntegrationLinearSolver::EigenSparseLU;
#endif
}

/** @brief Returns a human-readable backend name for diagnostics. */
[[nodiscard]] constexpr const char *
integration_linear_solver_name(IntegrationLinearSolver solver) noexcept {
  switch (solver) {
  case IntegrationLinearSolver::Pardiso:
    return "PARDISO";
  case IntegrationLinearSolver::CuDss:
    return "cuDSS";
  case IntegrationLinearSolver::Umfpack:
    return "UMFPACK";
  case IntegrationLinearSolver::EigenSparseLU:
    return "Eigen SparseLU";
  case IntegrationLinearSolver::Default:
    return "Default (automatic)";
  }
  return "Unknown";
}


/** @brief Returns the concrete factorization used by an integration backend. */
[[nodiscard]] constexpr const char *
integration_linear_solver_factorization(
    IntegrationLinearSolver solver) noexcept {
  switch (solver) {
  case IntegrationLinearSolver::Pardiso:
    return "oneMKL PARDISO symmetric-indefinite LDL^T (mtype=-2)";
  case IntegrationLinearSolver::CuDss:
    return "NVIDIA cuDSS general sparse LDU (CUDSS_MTYPE_GENERAL)";
  case IntegrationLinearSolver::Umfpack:
    return "SuiteSparse UMFPACK general sparse LU";
  case IntegrationLinearSolver::EigenSparseLU:
    return "Eigen SparseLU general sparse LU";
  case IntegrationLinearSolver::Default:
    return "automatic backend selection";
  }
  return "unknown factorization";
}

/** @brief Numerical-stability controls for the cuDSS KKT backend. */
struct CuDssSolverOptions {
  int iterativeRefinementSteps = 8;
  double iterativeRefinementTolerance = 0.0;
  bool enableMatching = false;
  bool enableScaledPivotEpsilon = false;
  bool enableGlobalPivoting = false;
  double maximumRelativeResidual = 1.0e-8;
  double maximumBackwardError = 1.0e-12;
};

/** @brief Timing values returned by optional integration solver backends. */
struct IntegrationSolverTimings {
  double analysis = 0.0;
  double factorization = 0.0;
  double solve = 0.0;
};

} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGRATION_LINEAR_SOLVER_H
