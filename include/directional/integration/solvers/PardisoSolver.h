// This file is part of Directional, a library for directional field processing.
// SPDX-License-Identifier: MPL-2.0

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_SOLVERS_PARDISO_SOLVER_H
#define DIRECTIONAL_INTEGRATION_SOLVERS_PARDISO_SOLVER_H

#ifdef DIRECTIONAL_HAS_PARDISO

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <mkl.h>

#include <directional/integration/IntegrationLinearSolver.h>

namespace directional {

/** @brief Fill-reducing ordering used by oneMKL PARDISO phase 11. */
enum class PardisoOrdering : MKL_INT {
  MinimumDegree = 0,
  MetisNestedDissection = 2,
  ParallelNestedDissection = 3
};

/** @brief Optional switch that can preserve the oneMKL library default. */
enum class PardisoOptionSwitch : int {
  LibraryDefault = -1,
  Disabled = 0,
  Enabled = 1
};

/**
 * @brief Easily editable controls for benchmarking oneMKL PARDISO.
 *
 * The integration code does not need to change when these values change.
 * Edit default_pardiso_benchmark_options() below, or construct a solver with an
 * explicit options object when comparing configurations programmatically.
 */
struct PardisoBenchmarkOptions {
  /** 0 keeps oneMKL's current thread setting. */
  int threadCount = 0;

  /** Phase-11 fill-reducing ordering. */
  PardisoOrdering ordering = PardisoOrdering::ParallelNestedDissection;

  /** Maximum iterative-refinement steps; -1 preserves pardisoinit defaults. */
  int iterativeRefinementSteps = -1;

  /** Pivot perturbation exponent; -1 preserves pardisoinit defaults. */
  int pivotPerturbationExponent = -1;

  /** Nonsymmetric permutation/scaling, iparm(11). */
  PardisoOptionSwitch scaling = PardisoOptionSwitch::Disabled;

  /** Maximum weighted matching, iparm(13). */
  PardisoOptionSwitch matching = PardisoOptionSwitch::Disabled;

  /** Enable PARDISO's expensive CSR matrix checker, iparm(27). */
  bool matrixChecker = false;

  /** Ask PARDISO to collect factor nonzero and MFLOP statistics. */
  bool collectFactorStatistics = true;

  /** Print PARDISO's built-in phase statistics (msglvl=1). */
  bool printPardisoStatistics = false;

  /** Print Directional's concise configuration banner once per solver. */
  bool printConfiguration = true;

  /** Print phase statistics after every solve. Useful only for benchmarking. */
  bool printPhaseSummaryEverySolve = false;

  /**
   * Reuse phase 11 when the CSR pattern is exactly identical.
   *
   * Reuse is automatically disabled unless scaling and matching are both
   * explicitly disabled, because those preprocessing steps can depend on
   * numerical values.
   */
  bool reuseSymbolicAnalysisForIdenticalPattern = true;
};

/** @brief Returns a readable name for a PARDISO ordering setting. */
[[nodiscard]] constexpr std::string_view
pardiso_ordering_name(PardisoOrdering ordering) noexcept {
  switch (ordering) {
  case PardisoOrdering::MinimumDegree:
    return "minimum degree (iparm[1]=0)";
  case PardisoOrdering::MetisNestedDissection:
    return "METIS nested dissection (iparm[1]=2)";
  case PardisoOrdering::ParallelNestedDissection:
    return "parallel nested dissection (iparm[1]=3)";
  }
  return "unknown";
}

/**
 * @brief Central benchmark profile used by the default solver constructor.
 *
 * Modify only this function to benchmark a different thread count or ordering
 * without touching integration code. Suggested experiments on an 8-core CPU:
 *
 *   options.threadCount = 4, 8, or 16;
 *   options.ordering = PardisoOrdering::MinimumDegree,
 *                      PardisoOrdering::MetisNestedDissection, or
 *                      PardisoOrdering::ParallelNestedDissection;
 */
[[nodiscard]] inline PardisoBenchmarkOptions
default_pardiso_benchmark_options() {
  PardisoBenchmarkOptions options;
  options.threadCount = 4;
  options.ordering = PardisoOrdering::MinimumDegree;

  options.scaling = PardisoOptionSwitch::LibraryDefault;
  options.matching = PardisoOptionSwitch::LibraryDefault;

  options.reuseSymbolicAnalysisForIdenticalPattern = false;
  options.iterativeRefinementSteps = 2;

  options.matrixChecker = false;
  options.printPardisoStatistics = false;
  options.printPhaseSummaryEverySolve = false;
  return options;
}

} // namespace directional

namespace directional::detail {

/** @brief Restores the previous thread-local oneMKL thread setting on exit. */
class PardisoThreadScope {
public:
  explicit PardisoThreadScope(int requestedThreads) {
    if (requestedThreads > 0) {
      previousThreads_ = mkl_set_num_threads_local(requestedThreads);
      active_ = true;
    }
  }

  PardisoThreadScope(const PardisoThreadScope &) = delete;
  PardisoThreadScope &operator=(const PardisoThreadScope &) = delete;

  ~PardisoThreadScope() {
    if (active_)
      mkl_set_num_threads_local(previousThreads_);
  }

private:
  int previousThreads_ = 0;
  bool active_ = false;
};

/**
 * @brief Persistent oneMKL PARDISO context for symmetric-indefinite KKT solves.
 *
 * PARDISO uses mtype=-2 and phases 11, 22, and 33. Phase-11 state is retained
 * only when the next matrix has exactly the same CSR structure and options make
 * symbolic reuse numerically valid. Otherwise, the prior PARDISO state is
 * released and rebuilt.
 */
class PardisoIntegrationSolver {
public:
  PardisoIntegrationSolver() : options_(default_pardiso_benchmark_options()) {}

  explicit PardisoIntegrationSolver(PardisoBenchmarkOptions options)
      : options_(std::move(options)) {
    validateOptions();
  }

  PardisoIntegrationSolver(const PardisoIntegrationSolver &) = delete;
  PardisoIntegrationSolver &
  operator=(const PardisoIntegrationSolver &) = delete;

  ~PardisoIntegrationSolver() { release(); }

  /** @brief Returns the active benchmark configuration. */
  [[nodiscard]] const PardisoBenchmarkOptions &options() const noexcept {
    return options_;
  }

  /**
   * @brief Replaces benchmark options and invalidates reusable symbolic state.
   */
  void setOptions(PardisoBenchmarkOptions options) {
    validateOptions(options);
    release();
    options_ = std::move(options);
    configurationReported_ = false;
  }

  bool solve(const Eigen::SparseMatrix<double> &matrix,
             const Eigen::VectorXd &rhs, Eigen::VectorXd &solution,
             IntegrationSolverTimings &timings, bool verbose) {
    using Clock = std::chrono::high_resolution_clock;
    const auto secondsSince = [](const auto &start) {
      return std::chrono::duration<double>(Clock::now() - start).count();
    };

    validateOptions();

    if (matrix.rows() != matrix.cols() || matrix.rows() != rhs.size())
      throw std::invalid_argument("PARDISO integration solve requires a square "
                                  "matrix and matching RHS");
    if (matrix.rows() > std::numeric_limits<MKL_INT>::max())
      throw std::overflow_error(
          "PARDISO indices cannot represent the integration matrix");

    PardisoThreadScope threadScope(options_.threadCount);

    using RowMatrix = Eigen::SparseMatrix<double, Eigen::RowMajor, MKL_INT>;
    std::vector<Eigen::Triplet<double, MKL_INT>> upperTriplets;
    upperTriplets.reserve(
        static_cast<std::size_t>(matrix.nonZeros() / 2 + matrix.rows()));
    std::vector<unsigned char> hasDiagonal(
        static_cast<std::size_t>(matrix.rows()), 0);

    for (Eigen::Index outer = 0; outer < matrix.outerSize(); ++outer) {
      for (Eigen::SparseMatrix<double>::InnerIterator entry(matrix, outer);
           entry; ++entry) {
        if (entry.col() < entry.row())
          continue;
        upperTriplets.emplace_back(static_cast<MKL_INT>(entry.row()),
                                   static_cast<MKL_INT>(entry.col()),
                                   entry.value());
        if (entry.row() == entry.col())
          hasDiagonal[static_cast<std::size_t>(entry.row())] = 1;
      }
    }

    for (MKL_INT row = 0; row < static_cast<MKL_INT>(matrix.rows()); ++row) {
      if (!hasDiagonal[static_cast<std::size_t>(row)])
        upperTriplets.emplace_back(row, row, 0.0);
    }

    RowMatrix upper(matrix.rows(), matrix.cols());
    upper.setFromTriplets(upperTriplets.begin(), upperTriplets.end());
    upper.makeCompressed();

    const bool reuseAnalysis = canReuseAnalysis(upper);
    if (!reuseAnalysis) {
      release();
      initialize();
      rememberPattern(upper);
    }

    n_ = static_cast<MKL_INT>(matrix.rows());
    solution.resize(matrix.rows());
    solution.setZero();

    if (verbose && options_.printConfiguration && !configurationReported_) {
      printConfiguration(reuseAnalysis);
      configurationReported_ = true;
    }

    if (!reuseAnalysis) {
      const MKL_INT phase = 11;
      const auto start = Clock::now();
      call(phase, upper, rhs, solution);
      timings.analysis += secondsSince(start);
      if (!check(phase, verbose)) {
        release();
        return false;
      }
      analyzed_ = true;
    }

    {
      const MKL_INT phase = 22;
      const auto start = Clock::now();
      call(phase, upper, rhs, solution);
      timings.factorization += secondsSince(start);
      if (!check(phase, verbose)) {
        release();
        return false;
      }
    }

    {
      const MKL_INT phase = 33;
      const auto start = Clock::now();
      call(phase, upper, rhs, solution);
      timings.solve += secondsSince(start);
      if (!check(phase, verbose)) {
        release();
        return false;
      }
    }

    if (verbose && options_.printPhaseSummaryEverySolve)
      printPhaseSummary(reuseAnalysis);

    if (!solution.allFinite()) {
      if (verbose) {
        std::cerr << "[Directional::integrate] PARDISO returned "
                     "non-finite solution values\n";
      }

      return false;
    }

    const Eigen::VectorXd residual = matrix * solution - rhs;

    const double minimumDenominator = std::numeric_limits<double>::min();

    const double rhsNorm = std::max(rhs.norm(), minimumDenominator);

    const double relativeResidual = residual.norm() / rhsNorm;

    /*
     * Eigen sparse expressions do not support rowwise(). Compute the matrix
     * infinity norm explicitly as the maximum absolute row sum.
     */
    Eigen::VectorXd absoluteRowSums = Eigen::VectorXd::Zero(matrix.rows());

    for (Eigen::Index outer = 0; outer < matrix.outerSize(); ++outer) {
      for (std::decay_t<decltype(matrix)>::InnerIterator entry(matrix, outer);
           entry; ++entry) {
        absoluteRowSums(entry.row()) += std::abs(entry.value());
      }
    }

    const double matrixInfinityNorm =
        absoluteRowSums.size() > 0 ? absoluteRowSums.maxCoeff() : 0.0;

    const double solutionInfinityNorm = solution.lpNorm<Eigen::Infinity>();

    const double rhsInfinityNorm = rhs.lpNorm<Eigen::Infinity>();

    const double backwardErrorDenominator =
        matrixInfinityNorm * solutionInfinityNorm + rhsInfinityNorm;

    const double backwardError =
        residual.lpNorm<Eigen::Infinity>() /
        std::max(backwardErrorDenominator, minimumDenominator);

    const double maximumSolutionMagnitude =
        solution.size() > 0 ? solution.cwiseAbs().maxCoeff() : 0.0;

    if (verbose) {
      std::cout << "[Directional::integrate] PARDISO solve quality"
                << " relativeResidual=" << relativeResidual
                << " backwardError=" << backwardError
                << " maxAbsSolution=" << maximumSolutionMagnitude
                << " perturbedPivots=" << iparm_[13]
                << " refinementSteps=" << iparm_[6] << '\n';
    }

    constexpr double maximumRelativeResidual = 1.0e-8;
    constexpr double maximumBackwardError = 1.0e-12;
    constexpr double maximumReasonableSolutionMagnitude = 1.0e12;

    if (!std::isfinite(relativeResidual) || !std::isfinite(backwardError) ||
        !std::isfinite(maximumSolutionMagnitude) ||
        relativeResidual > maximumRelativeResidual ||
        backwardError > maximumBackwardError ||
        maximumSolutionMagnitude > maximumReasonableSolutionMagnitude) {
      if (verbose) {
        std::cerr << "[Directional::integrate] PARDISO solution rejected"
                  << " relativeResidual=" << relativeResidual
                  << " backwardError=" << backwardError
                  << " maxAbsSolution=" << maximumSolutionMagnitude << '\n';
      }

      return false;
    }

    return true;
  }

private:
  static void validateOptions(const PardisoBenchmarkOptions &options) {
    if (options.threadCount < 0)
      throw std::invalid_argument("PARDISO thread count cannot be negative");
    if (options.iterativeRefinementSteps < -1)
      throw std::invalid_argument(
          "PARDISO iterative refinement steps must be -1 or non-negative");
    if (options.pivotPerturbationExponent < -1)
      throw std::invalid_argument(
          "PARDISO pivot perturbation exponent must be -1 or non-negative");
  }

  void validateOptions() const { validateOptions(options_); }

  void initialize() {
    pt_.fill(nullptr);
    iparm_.fill(0);
    error_ = 0;
    released_ = false;
    analyzed_ = false;

    pardisoinit(pt_.data(), &mtype_, iparm_.data());

    iparm_[1] = static_cast<MKL_INT>(options_.ordering);
    iparm_[34] = 1; // zero-based CSR indexing
    iparm_[26] = options_.matrixChecker ? 1 : 0;

    if (options_.iterativeRefinementSteps >= 0)
      iparm_[7] = static_cast<MKL_INT>(options_.iterativeRefinementSteps);
    if (options_.pivotPerturbationExponent >= 0)
      iparm_[9] = static_cast<MKL_INT>(options_.pivotPerturbationExponent);

    applySwitch(iparm_[10], options_.scaling);
    applySwitch(iparm_[12], options_.matching);

    if (options_.collectFactorStatistics) {
      iparm_[17] = -1; // factor nonzero count
      iparm_[18] = -1; // factorization operation count
    }

    msglvl_ = options_.printPardisoStatistics ? 1 : 0;
  }

  static void applySwitch(MKL_INT &parameter, PardisoOptionSwitch value) {
    if (value != PardisoOptionSwitch::LibraryDefault)
      parameter = value == PardisoOptionSwitch::Enabled ? 1 : 0;
  }

  template <typename RowMatrix>
  [[nodiscard]] bool canReuseAnalysis(const RowMatrix &matrix) const {
    if (!options_.reuseSymbolicAnalysisForIdenticalPattern || !analyzed_ ||
        released_)
      return false;

    if (options_.scaling != PardisoOptionSwitch::Disabled ||
        options_.matching != PardisoOptionSwitch::Disabled)
      return false;

    if (n_ != static_cast<MKL_INT>(matrix.rows()))
      return false;

    const auto rowCount = static_cast<std::size_t>(matrix.rows()) + 1;
    const auto nonZeroCount = static_cast<std::size_t>(matrix.nonZeros());

    return previousRowOffsets_.size() == rowCount &&
           previousColumnIndices_.size() == nonZeroCount &&
           std::equal(previousRowOffsets_.begin(), previousRowOffsets_.end(),
                      matrix.outerIndexPtr()) &&
           std::equal(previousColumnIndices_.begin(),
                      previousColumnIndices_.end(), matrix.innerIndexPtr());
  }

  template <typename RowMatrix> void rememberPattern(const RowMatrix &matrix) {
    previousRowOffsets_.assign(matrix.outerIndexPtr(),
                               matrix.outerIndexPtr() + matrix.rows() + 1);
    previousColumnIndices_.assign(matrix.innerIndexPtr(),
                                  matrix.innerIndexPtr() + matrix.nonZeros());
    n_ = static_cast<MKL_INT>(matrix.rows());
  }

  template <typename RowMatrix>
  void call(MKL_INT phase, const RowMatrix &matrix, const Eigen::VectorXd &rhs,
            Eigen::VectorXd &solution) {
    MKL_INT permutationPlaceholder = 0;
    error_ = 0;

    pardiso(pt_.data(), &maxfct_, &mnum_, &mtype_, &phase, &n_,
            const_cast<double *>(matrix.valuePtr()),
            const_cast<MKL_INT *>(matrix.outerIndexPtr()),
            const_cast<MKL_INT *>(matrix.innerIndexPtr()),
            &permutationPlaceholder, &nrhs_, iparm_.data(), &msglvl_,
            const_cast<double *>(rhs.data()), solution.data(), &error_);
  }

  [[nodiscard]] bool check(MKL_INT phase, bool verbose) const {
    if (error_ == 0)
      return true;

    if (verbose) {
      std::cerr << "[Directional::integrate] PARDISO phase " << phase
                << " failed with error " << error_ << '\n';
    }
    return false;
  }

  void printConfiguration(bool reusedAnalysis) const {
    std::cout << "[Directional::integrate] PARDISO backend confirmed\n"
              << "  implementation: Intel oneMKL PARDISO\n"
              << "  matrix type:    real symmetric-indefinite (mtype=-2)\n"
              << "  factorization:  LDL^T with PARDISO pivoting\n"
              << "  phase sequence: 11 symbolic, 22 numeric, 33 solve\n"
              << "  ordering:       "
              << pardiso_ordering_name(options_.ordering) << "\n"
              << "  threads:        requested=";

    if (options_.threadCount > 0)
      std::cout << options_.threadCount;
    else
      std::cout << "oneMKL default";

    std::cout << " effective-max=" << mkl_get_max_threads() << "\n"
              << "  scaling:        " << switchName(options_.scaling) << "\n"
              << "  matching:       " << switchName(options_.matching) << "\n"
              << "  matrix checker: "
              << (options_.matrixChecker ? "enabled" : "disabled") << "\n"
              << "  phase-11 reuse: "
              << (options_.reuseSymbolicAnalysisForIdenticalPattern
                      ? "enabled for identical patterns"
                      : "disabled")
              << "\n"
              << "  current reuse:  " << (reusedAnalysis ? "yes" : "no") << "\n"
              << "  fallback:       none; errors are returned to integration\n";
  }

  void printPhaseSummary(bool reusedAnalysis) const {
    std::cout << "[Directional::integrate] PARDISO phase summary\n"
              << "  symbolic reused:             "
              << (reusedAnalysis ? "yes" : "no") << "\n"
              << "  peak symbolic memory:        " << iparm_[14] << " KB\n"
              << "  permanent symbolic memory:   " << iparm_[15] << " KB\n"
              << "  numeric factor memory:       " << iparm_[16] << " KB\n"
              << "  factor nonzeros:             " << iparm_[17] << "\n"
              << "  factorization operation stat:" << iparm_[18] << "\n"
              << "  perturbed pivots:            " << iparm_[13] << "\n"
              << "  iterative refinement steps:  " << iparm_[6] << "\n";
  }

  static constexpr std::string_view
  switchName(PardisoOptionSwitch value) noexcept {
    switch (value) {
    case PardisoOptionSwitch::LibraryDefault:
      return "oneMKL default";
    case PardisoOptionSwitch::Disabled:
      return "disabled";
    case PardisoOptionSwitch::Enabled:
      return "enabled";
    }
    return "unknown";
  }

  void release() noexcept {
    if (released_)
      return;

    MKL_INT phase = -1;
    MKL_INT n = n_;
    MKL_INT permutationPlaceholder = 0;
    double scalar = 0.0;

    pardiso(pt_.data(), &maxfct_, &mnum_, &mtype_, &phase, &n, &scalar, nullptr,
            nullptr, &permutationPlaceholder, &nrhs_, iparm_.data(), &msglvl_,
            &scalar, &scalar, &error_);

    pt_.fill(nullptr);
    released_ = true;
    analyzed_ = false;
    n_ = 0;
    previousRowOffsets_.clear();
    previousColumnIndices_.clear();
  }

  PardisoBenchmarkOptions options_;
  std::array<void *, 64> pt_{};
  std::array<MKL_INT, 64> iparm_{};
  std::vector<MKL_INT> previousRowOffsets_;
  std::vector<MKL_INT> previousColumnIndices_;

  MKL_INT maxfct_ = 1;
  MKL_INT mnum_ = 1;
  MKL_INT mtype_ = -2;
  MKL_INT nrhs_ = 1;
  MKL_INT msglvl_ = 0;
  MKL_INT n_ = 0;
  MKL_INT error_ = 0;

  bool released_ = true;
  bool analyzed_ = false;
  bool configurationReported_ = false;
};

} // namespace directional::detail

#endif // DIRECTIONAL_HAS_PARDISO
#endif // DIRECTIONAL_INTEGRATION_SOLVERS_PARDISO_SOLVER_H
