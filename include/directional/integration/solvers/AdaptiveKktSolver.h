// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_SOLVERS_ADAPTIVE_KKT_SOLVER_H
#define DIRECTIONAL_INTEGRATION_SOLVERS_ADAPTIVE_KKT_SOLVER_H

#include <chrono>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Cholesky>
#include <Eigen/IterativeLinearSolvers>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

#include <directional/integration/IntegrationSolveStrategy.h>

namespace directional::detail {

struct AdaptiveKktSolveResult {
  bool accepted = false;
  bool converged = false;
  bool finite = false;
  bool symmetric = false;
  int iterations = 0;
  double solverSeconds = 0.0;
  double relativeResidual = std::numeric_limits<double>::infinity();
  double absoluteResidual = std::numeric_limits<double>::infinity();
  double constraintResidual = std::numeric_limits<double>::infinity();
  Eigen::VectorXd solution;
};

class AdaptiveKktSolver {
public:
  [[nodiscard]] static Eigen::VectorXd
  map_warm_start(const Eigen::VectorXd &previousFullSolution,
                 const std::vector<int> &freeToFull,
                 const Eigen::Index systemSize,
                 const AdaptiveIntegrationOptions &options) {
    Eigen::VectorXd guess = Eigen::VectorXd::Zero(systemSize);
    if (!options.useWarmStart || previousFullSolution.size() == 0) {
      return guess;
    }

    if (systemSize < static_cast<Eigen::Index>(freeToFull.size())) {
      throw std::runtime_error(
          "AdaptiveKktSolver warm start system size is too small");
    }

    for (std::size_t freeIndex = 0; freeIndex < freeToFull.size();
         ++freeIndex) {
      const int fullIndex = freeToFull[freeIndex];
      if (fullIndex >= 0 && fullIndex < previousFullSolution.size()) {
        guess(static_cast<Eigen::Index>(freeIndex)) =
            previousFullSolution(fullIndex);
      }
    }
    return guess;
  }

  [[nodiscard]] static bool
  is_symmetric(const Eigen::SparseMatrix<double> &matrix,
               const double tolerance = 1.0e-10) {
    if (matrix.rows() != matrix.cols()) {
      return false;
    }
    Eigen::SparseMatrix<double> transpose = matrix.transpose();
    Eigen::SparseMatrix<double> delta = matrix - transpose;
    delta.makeCompressed();
    const double scale = std::max(1.0, matrix.norm());
    return delta.norm() <= tolerance * scale;
  }

  [[nodiscard]] static AdaptiveKktSolveResult
  solve(const Eigen::SparseMatrix<double> &system,
        const Eigen::VectorXd &rhs, const Eigen::VectorXd &initialGuess,
        const Eigen::Index constraintRows,
        const AdaptiveIntegrationOptions &options) {
    using Clock = std::chrono::high_resolution_clock;
    AdaptiveKktSolveResult result;

    if (system.rows() != system.cols() || system.rows() != rhs.size() ||
        initialGuess.size() != rhs.size()) {
      throw std::runtime_error(
          "AdaptiveKktSolver received inconsistent system dimensions");
    }

    if (rhs.size() == 0) {
      result.accepted = true;
      result.converged = true;
      result.finite = true;
      result.symmetric = true;
      result.solution.resize(0);
      result.relativeResidual = 0.0;
      result.absoluteResidual = 0.0;
      result.constraintResidual = 0.0;
      return result;
    }

    if (options.maxIterations <= 1 || !rhs.allFinite()) {
      return result;
    }

    result.symmetric = is_symmetric(system);
    if (!result.symmetric) {
      return result;
    }

    result = solve_with_schur_reduction(system, rhs, constraintRows, options);
    if (result.accepted) {
      return result;
    }

    Eigen::MINRES<Eigen::SparseMatrix<double>, Eigen::Lower,
                  Eigen::IdentityPreconditioner>
        solver;
    solver.setMaxIterations(options.maxIterations);
    solver.setTolerance(options.relativeResidualTolerance);

    const auto solveStart = Clock::now();
    solver.compute(system);
    result.solution = solver.solveWithGuess(rhs, initialGuess);
    result.solverSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - solveStart)
            .count() /
        1.0e6;

    result.symmetric = true;
    result.iterations = static_cast<int>(solver.iterations());
    result.converged = solver.info() == Eigen::Success;
    evaluate_candidate(system, rhs, constraintRows, options, result);
    return result;
  }

private:
  static void
  evaluate_candidate(const Eigen::SparseMatrix<double> &system,
                     const Eigen::VectorXd &rhs,
                     const Eigen::Index constraintRows,
                     const AdaptiveIntegrationOptions &options,
                     AdaptiveKktSolveResult &result) {
    result.finite =
        result.solution.size() == rhs.size() && result.solution.allFinite();
    if (!result.finite) {
      return;
    }

    const Eigen::VectorXd residual = system * result.solution - rhs;
    const double residualNorm = residual.norm();
    const double rhsScale = std::max(1.0, rhs.norm());
    result.relativeResidual = residualNorm / rhsScale;
    result.absoluteResidual =
        residualNorm /
        std::sqrt(static_cast<double>(std::max<Eigen::Index>(rhs.size(), 1)));

    const Eigen::Index clampedConstraintRows = std::max<Eigen::Index>(
        0, std::min<Eigen::Index>(constraintRows, rhs.size()));
    if (clampedConstraintRows == 0) {
      result.constraintResidual = 0.0;
    } else {
      const double constraintScale =
          std::max(1.0, rhs.tail(clampedConstraintRows).norm());
      result.constraintResidual =
          residual.tail(clampedConstraintRows).norm() / constraintScale;
    }

    result.accepted =
        result.relativeResidual <= options.relativeResidualTolerance &&
        result.absoluteResidual <= options.absoluteResidualTolerance &&
        result.constraintResidual <= options.constraintResidualTolerance;
  }

  [[nodiscard]] static AdaptiveKktSolveResult solve_with_schur_reduction(
      const Eigen::SparseMatrix<double> &system, const Eigen::VectorXd &rhs,
      const Eigen::Index constraintRows,
      const AdaptiveIntegrationOptions &options) {
    using Clock = std::chrono::high_resolution_clock;
    AdaptiveKktSolveResult result;
    result.symmetric = true;

    const Eigen::Index clampedConstraintRows = std::max<Eigen::Index>(
        0, std::min<Eigen::Index>(constraintRows, rhs.size()));
    const Eigen::Index freeRows = rhs.size() - clampedConstraintRows;
    if (freeRows <= 0) {
      return result;
    }

    const auto solveStart = Clock::now();
    std::vector<Eigen::Triplet<double>> hTriplets;
    std::vector<Eigen::Triplet<double>> cTriplets;
    hTriplets.reserve(static_cast<std::size_t>(system.nonZeros()));
    cTriplets.reserve(static_cast<std::size_t>(system.nonZeros()));

    for (Eigen::Index outer = 0; outer < system.outerSize(); ++outer) {
      for (Eigen::SparseMatrix<double>::InnerIterator entry(system, outer);
           entry; ++entry) {
        if (entry.row() < freeRows && entry.col() < freeRows) {
          hTriplets.emplace_back(static_cast<int>(entry.row()),
                                 static_cast<int>(entry.col()), entry.value());
        } else if (entry.row() >= freeRows && entry.col() < freeRows) {
          cTriplets.emplace_back(static_cast<int>(entry.row() - freeRows),
                                 static_cast<int>(entry.col()), entry.value());
        }
      }
    }

    Eigen::SparseMatrix<double> h(freeRows, freeRows);
    h.setFromTriplets(hTriplets.begin(), hTriplets.end());
    h.makeCompressed();

    Eigen::SparseMatrix<double> c(clampedConstraintRows, freeRows);
    if (clampedConstraintRows > 0) {
      c.setFromTriplets(cTriplets.begin(), cTriplets.end());
      c.makeCompressed();
    }

    Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> hFactor;
    hFactor.compute(h);
    if (hFactor.info() != Eigen::Success) {
      result.solverSeconds = elapsed_seconds(solveStart);
      return result;
    }

    Eigen::MatrixXd rhsBlock(freeRows, clampedConstraintRows + 1);
    rhsBlock.col(0) = rhs.head(freeRows);
    if (clampedConstraintRows > 0) {
      rhsBlock.rightCols(clampedConstraintRows) =
          Eigen::MatrixXd(c.transpose());
    }

    const Eigen::MatrixXd hInverseBlock = hFactor.solve(rhsBlock);
    if (hFactor.info() != Eigen::Success || !hInverseBlock.allFinite()) {
      result.solverSeconds = elapsed_seconds(solveStart);
      return result;
    }

    Eigen::VectorXd primal = hInverseBlock.col(0);
    Eigen::VectorXd multiplier =
        Eigen::VectorXd::Zero(clampedConstraintRows);
    if (clampedConstraintRows > 0) {
      const Eigen::MatrixXd z =
          hInverseBlock.rightCols(clampedConstraintRows);
      const Eigen::MatrixXd schur = c * z;
      const Eigen::VectorXd schurRhs =
          c * primal - rhs.tail(clampedConstraintRows);
      const Eigen::LDLT<Eigen::MatrixXd> schurFactor(schur);
      if (schurFactor.info() != Eigen::Success) {
        result.solverSeconds = elapsed_seconds(solveStart);
        return result;
      }
      multiplier = schurFactor.solve(schurRhs);
      if (!multiplier.allFinite()) {
        result.solverSeconds = elapsed_seconds(solveStart);
        return result;
      }
      primal -= z * multiplier;
    }

    result.solution.resize(rhs.size());
    result.solution.head(freeRows) = primal;
    if (clampedConstraintRows > 0) {
      result.solution.tail(clampedConstraintRows) = multiplier;
    }
    result.iterations = 0;
    result.converged = true;
    result.solverSeconds = elapsed_seconds(solveStart);
    evaluate_candidate(system, rhs, constraintRows, options, result);
    return result;
  }

  template <typename StartTime>
  [[nodiscard]] static double elapsed_seconds(const StartTime &start) {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::high_resolution_clock::now() - start)
               .count() /
           1.0e6;
  }
};

} // namespace directional::detail

#endif // DIRECTIONAL_INTEGRATION_SOLVERS_ADAPTIVE_KKT_SOLVER_H
