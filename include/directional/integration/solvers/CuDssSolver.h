// This file is part of Directional, a library for directional field processing.
// SPDX-License-Identifier: MPL-2.0

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_SOLVERS_CUDSS_SOLVER_H
#define DIRECTIONAL_INTEGRATION_SOLVERS_CUDSS_SOLVER_H

#ifdef DIRECTIONAL_HAS_CUDSS

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <cuda_runtime_api.h>
#include <cudss.h>

#include <directional/integration/IntegrationLinearSolver.h>

namespace directional::detail {

/** @brief Persistent cuDSS context used for general sparse KKT solves. */
class CuDssIntegrationSolver {
public:
  CuDssIntegrationSolver() = default;

  CuDssIntegrationSolver(const CuDssIntegrationSolver &) = delete;
  CuDssIntegrationSolver &operator=(const CuDssIntegrationSolver &) = delete;

  ~CuDssIntegrationSolver() {
    if (config_ != nullptr)
      cudssConfigDestroy(config_);
    if (handle_ != nullptr)
      cudssDestroy(handle_);
  }

  /**
   * @brief Solves one KKT system with cuDSS and validates the returned solution.
   *
   * The integration matrix is mathematically symmetric but has a structurally
   * zero multiplier diagonal. It is therefore supplied as a full general CSR
   * matrix so cuDSS can use its general LDU factorization and pivoting path.
   */
  bool solve(const Eigen::SparseMatrix<double> &matrix,
             const Eigen::VectorXd &rhs, Eigen::VectorXd &solution,
             IntegrationSolverTimings &timings,
             const CuDssSolverOptions &options, bool verbose) {
    using Clock = std::chrono::high_resolution_clock;
    const auto secondsSince = [](const auto &start) {
      return std::chrono::duration<double>(Clock::now() - start).count();
    };

    if (matrix.rows() != matrix.cols() || matrix.rows() != rhs.size()) {
      throw std::invalid_argument(
          "cuDSS integration solve requires a square matrix and matching RHS");
    }
    if (matrix.rows() > std::numeric_limits<int>::max() ||
        matrix.nonZeros() > std::numeric_limits<int>::max()) {
      throw std::overflow_error(
          "cuDSS INT32 CSR indices cannot represent the integration matrix");
    }
    if (options.iterativeRefinementSteps < 0 ||
        options.iterativeRefinementTolerance < 0.0 ||
        options.maximumRelativeResidual <= 0.0 ||
        options.maximumBackwardError <= 0.0) {
      throw std::invalid_argument("cuDSS solver tolerances are invalid");
    }

    ensureInitialized();
    configure(options);

    using RowMatrix = Eigen::SparseMatrix<double, Eigen::RowMajor, int>;
    RowMatrix csr = matrix;
    csr.makeCompressed();

    if (csr.nonZeros() == 0) {
      throw std::invalid_argument(
          "cuDSS integration solve received an empty matrix");
    }

    DeviceBuffer<int> rowOffsets(static_cast<std::size_t>(csr.rows() + 1));
    DeviceBuffer<int> columnIndices(static_cast<std::size_t>(csr.nonZeros()));
    DeviceBuffer<double> values(static_cast<std::size_t>(csr.nonZeros()));
    DeviceBuffer<double> deviceRhs(static_cast<std::size_t>(rhs.size()));
    DeviceBuffer<double> deviceSolution(static_cast<std::size_t>(rhs.size()));

    copyToDevice(rowOffsets, csr.outerIndexPtr());
    copyToDevice(columnIndices, csr.innerIndexPtr());
    copyToDevice(values, csr.valuePtr());
    copyToDevice(deviceRhs, rhs.data());
    checkCuda(cudaMemset(deviceSolution.get(), 0,
                         static_cast<std::size_t>(rhs.size()) * sizeof(double)),
              "cudaMemset(solution)");

    cudssData_t data = nullptr;
    cudssMatrix_t sparse = nullptr;
    cudssMatrix_t denseRhs = nullptr;
    cudssMatrix_t denseSolution = nullptr;

    auto cleanup = [&]() {
      if (sparse != nullptr)
        cudssMatrixDestroy(sparse);
      if (denseRhs != nullptr)
        cudssMatrixDestroy(denseRhs);
      if (denseSolution != nullptr)
        cudssMatrixDestroy(denseSolution);
      if (data != nullptr)
        cudssDataDestroy(handle_, data);
    };

    try {
      check(cudssDataCreate(handle_, &data), "cudssDataCreate");
      check(cudssMatrixCreateCsr(
                &sparse, csr.rows(), csr.cols(), csr.nonZeros(),
                rowOffsets.get(), nullptr, columnIndices.get(), values.get(),
                CUDSS_R_32I, CUDSS_R_32I, CUDSS_R_64F,
                CUDSS_MTYPE_GENERAL, CUDSS_MVIEW_FULL, CUDSS_BASE_ZERO),
            "cudssMatrixCreateCsr");
      check(cudssMatrixCreateDn(&denseRhs, rhs.size(), 1, rhs.size(),
                                deviceRhs.get(), CUDSS_R_64F,
                                CUDSS_LAYOUT_COL_MAJOR),
            "cudssMatrixCreateDn(rhs)");
      check(cudssMatrixCreateDn(&denseSolution, rhs.size(), 1, rhs.size(),
                                deviceSolution.get(), CUDSS_R_64F,
                                CUDSS_LAYOUT_COL_MAJOR),
            "cudssMatrixCreateDn(solution)");

      auto start = Clock::now();
      check(cudssExecute(handle_, CUDSS_PHASE_ANALYSIS, config_, data, sparse,
                         denseSolution, denseRhs),
            "cuDSS analysis");
      checkCuda(cudaDeviceSynchronize(), "cudaDeviceSynchronize(analysis)");
      timings.analysis += secondsSince(start);

      start = Clock::now();
      check(cudssExecute(handle_, CUDSS_PHASE_FACTORIZATION, config_, data,
                         sparse, denseSolution, denseRhs),
            "cuDSS factorization");
      checkCuda(cudaDeviceSynchronize(),
                "cudaDeviceSynchronize(factorization)");
      timings.factorization += secondsSince(start);

      start = Clock::now();
      const cudssStatus_t solveStatus =
          cudssExecute(handle_, CUDSS_PHASE_SOLVE, config_, data, sparse,
                       denseSolution, denseRhs);

      // cuDSS leaves the refined solution available when refinement reaches
      // its step limit. Validate that solution independently below.
      if (solveStatus != CUDSS_STATUS_SUCCESS &&
          solveStatus != CUDSS_STATUS_IR_FAILED) {
        check(solveStatus, "cuDSS solve");
      }

      checkCuda(cudaDeviceSynchronize(), "cudaDeviceSynchronize(solve)");
      timings.solve += secondsSince(start);

      solution.resize(rhs.size());
      checkCuda(cudaMemcpy(solution.data(), deviceSolution.get(),
                           static_cast<std::size_t>(rhs.size()) * sizeof(double),
                           cudaMemcpyDeviceToHost),
                "cudaMemcpy(solution)");

      const SolutionQuality quality = evaluateSolution(matrix, rhs, solution);

      if (verbose) {
        std::cout << "[Directional::integrate] cuDSS solve quality"
                  << " relativeResidual=" << quality.relativeResidual
                  << " backwardError=" << quality.backwardError
                  << " refinementStatus=" << statusName(solveStatus) << '\n';
      }

      const bool accepted =
          solution.allFinite() && std::isfinite(quality.relativeResidual) &&
          std::isfinite(quality.backwardError) &&
          quality.relativeResidual <= options.maximumRelativeResidual &&
          quality.backwardError <= options.maximumBackwardError;

      if (!accepted) {
        std::cerr << "[Directional::integrate] cuDSS solution rejected"
                  << " relativeResidual=" << quality.relativeResidual
                  << " limit=" << options.maximumRelativeResidual
                  << " backwardError=" << quality.backwardError
                  << " limit=" << options.maximumBackwardError
                  << " rows=" << csr.rows() << " nnz=" << csr.nonZeros()
                  << '\n';
      }

      cleanup();
      return accepted;
    } catch (const std::exception &error) {
      cleanup();
      std::cerr << "[Directional::integrate] cuDSS failure: " << error.what()
                << " rows=" << csr.rows() << " cols=" << csr.cols()
                << " nnz=" << csr.nonZeros() << '\n';
      return false;
    }
  }

private:
  struct SolutionQuality {
    double relativeResidual = std::numeric_limits<double>::infinity();
    double backwardError = std::numeric_limits<double>::infinity();
  };

  void ensureInitialized() {
    if (handle_ != nullptr)
      return;

    check(cudssCreate(&handle_), "cudssCreate");
    try {
      check(cudssConfigCreate(&config_), "cudssConfigCreate");
    } catch (...) {
      cudssDestroy(handle_);
      handle_ = nullptr;
      throw;
    }
  }

  void configure(const CuDssSolverOptions &options) {
    int refinementSteps = options.iterativeRefinementSteps;
    double refinementTolerance = options.iterativeRefinementTolerance;

    check(cudssConfigSet(config_, CUDSS_CONFIG_IR_N_STEPS, &refinementSteps,
                         sizeof(refinementSteps)),
          "cudssConfigSet(CUDSS_CONFIG_IR_N_STEPS)");
    check(cudssConfigSet(config_, CUDSS_CONFIG_IR_TOL, &refinementTolerance,
                         sizeof(refinementTolerance)),
          "cudssConfigSet(CUDSS_CONFIG_IR_TOL)");

    const cudssMatchingAlg_t matchingAlgorithm =
        options.enableMatching ? CUDSS_MATCHING_ALG_AUTO
                               : CUDSS_MATCHING_ALG_NONE;
    check(cudssConfigSet(config_, CUDSS_CONFIG_MATCHING_ALG,
                         &matchingAlgorithm, sizeof(matchingAlgorithm)),
          "cudssConfigSet(CUDSS_CONFIG_MATCHING_ALG)");

    const cudssPivotEpsilonAlg_t pivotEpsilonAlgorithm =
        options.enableScaledPivotEpsilon
            ? CUDSS_PIVOT_EPSILON_ALG_SCALED
            : CUDSS_PIVOT_EPSILON_ALG_DEFAULT;
    check(cudssConfigSet(config_, CUDSS_CONFIG_PIVOT_EPSILON_ALG,
                         &pivotEpsilonAlgorithm,
                         sizeof(pivotEpsilonAlgorithm)),
          "cudssConfigSet(CUDSS_CONFIG_PIVOT_EPSILON_ALG)");

    const cudssReorderingAlg_t reorderingAlgorithm =
        options.enableGlobalPivoting ? CUDSS_REORDERING_ALG_BTF_COLAMD
                                     : CUDSS_REORDERING_ALG_DEFAULT;
    check(cudssConfigSet(config_, CUDSS_CONFIG_REORDERING_ALG,
                         &reorderingAlgorithm, sizeof(reorderingAlgorithm)),
          "cudssConfigSet(CUDSS_CONFIG_REORDERING_ALG)");
  }

  static SolutionQuality
  evaluateSolution(const Eigen::SparseMatrix<double> &matrix,
                   const Eigen::VectorXd &rhs,
                   const Eigen::VectorXd &solution) {
    const Eigen::VectorXd residual = matrix * solution - rhs;
    const double minimumDenominator = std::numeric_limits<double>::min();

    SolutionQuality quality;
    quality.relativeResidual =
        residual.norm() / std::max(rhs.norm(), minimumDenominator);

    Eigen::VectorXd absoluteRowSums =
        Eigen::VectorXd::Zero(matrix.rows());
    for (Eigen::Index column = 0; column < matrix.outerSize(); ++column) {
      for (Eigen::SparseMatrix<double>::InnerIterator entry(matrix, column);
           entry; ++entry) {
        absoluteRowSums(entry.row()) += std::abs(entry.value());
      }
    }

    const double matrixInfinityNorm =
        absoluteRowSums.size() == 0 ? 0.0 : absoluteRowSums.maxCoeff();
    const double solutionInfinityNorm =
        solution.size() == 0 ? 0.0 : solution.cwiseAbs().maxCoeff();
    const double rhsInfinityNorm =
        rhs.size() == 0 ? 0.0 : rhs.cwiseAbs().maxCoeff();
    const double residualInfinityNorm =
        residual.size() == 0 ? 0.0 : residual.cwiseAbs().maxCoeff();

    quality.backwardError = residualInfinityNorm /
        std::max(matrixInfinityNorm * solutionInfinityNorm + rhsInfinityNorm,
                 minimumDenominator);
    return quality;
  }

  template <typename T> class DeviceBuffer {
  public:
    explicit DeviceBuffer(std::size_t count) : count_(count) {
      checkCuda(
          cudaMalloc(reinterpret_cast<void **>(&pointer_), count * sizeof(T)),
          "cudaMalloc");
    }
    ~DeviceBuffer() { cudaFree(pointer_); }
    DeviceBuffer(const DeviceBuffer &) = delete;
    DeviceBuffer &operator=(const DeviceBuffer &) = delete;
    T *get() const { return pointer_; }
    std::size_t count() const { return count_; }

  private:
    T *pointer_ = nullptr;
    std::size_t count_ = 0;
  };

  template <typename T>
  static void copyToDevice(const DeviceBuffer<T> &destination,
                           const T *source) {
    checkCuda(cudaMemcpy(destination.get(), source,
                         destination.count() * sizeof(T),
                         cudaMemcpyHostToDevice),
              "cudaMemcpy(host-to-device)");
  }

  static const char *statusName(cudssStatus_t status) noexcept {
    switch (status) {
    case CUDSS_STATUS_SUCCESS:
      return "CUDSS_STATUS_SUCCESS";
    case CUDSS_STATUS_NOT_INITIALIZED:
      return "CUDSS_STATUS_NOT_INITIALIZED";
    case CUDSS_STATUS_ALLOC_FAILED:
      return "CUDSS_STATUS_ALLOC_FAILED";
    case CUDSS_STATUS_INVALID_VALUE:
      return "CUDSS_STATUS_INVALID_VALUE";
    case CUDSS_STATUS_NOT_SUPPORTED:
      return "CUDSS_STATUS_NOT_SUPPORTED";
    case CUDSS_STATUS_EXECUTION_FAILED:
      return "CUDSS_STATUS_EXECUTION_FAILED";
    case CUDSS_STATUS_INTERNAL_ERROR:
      return "CUDSS_STATUS_INTERNAL_ERROR";
    case CUDSS_STATUS_IR_FAILED:
      return "CUDSS_STATUS_IR_FAILED";
    default:
      return "CUDSS_STATUS_UNKNOWN";
    }
  }

  static void check(cudssStatus_t status, const char *operation) {
    if (status != CUDSS_STATUS_SUCCESS) {
      throw std::runtime_error(std::string(operation) + " failed: " +
                               statusName(status) + " (" +
                               std::to_string(static_cast<int>(status)) + ")");
    }
  }

  static void checkCuda(cudaError_t status, const char *operation) {
    if (status != cudaSuccess) {
      throw std::runtime_error(std::string(operation) + " failed: " +
                               cudaGetErrorString(status));
    }
  }

  cudssHandle_t handle_ = nullptr;
  cudssConfig_t config_ = nullptr;
};

} // namespace directional::detail

#endif // DIRECTIONAL_HAS_CUDSS
#endif // DIRECTIONAL_INTEGRATION_SOLVERS_CUDSS_SOLVER_H
