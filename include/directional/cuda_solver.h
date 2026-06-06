#ifndef DIRECTIONAL_CUDA_SOLVER_H
#define DIRECTIONAL_CUDA_SOLVER_H

#include <cstddef>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include <Eigen/Core>
#include <Eigen/SparseCore>
#include <Eigen/SparseLU>

#if defined(DIRECTIONAL_ENABLE_CUDA)
#include <cuda_runtime.h>
#include <cusolverSp.h>
#include <cusparse.h>
#endif

namespace directional {

struct LinearSolveOptions {
  bool preferCuda = true;
  bool verbose = false;
};

struct LinearSolveDiagnostics {
  bool usedCuda = false;
  bool usedFallback = false;
  std::string message;
};

namespace detail {

#if defined(DIRECTIONAL_ENABLE_CUDA)
inline const char *cuda_error_to_string(const cudaError_t error) {
  return cudaGetErrorString(error);
}

inline const char *cusolver_status_to_string(const cusolverStatus_t status) {
  switch (status) {
  case CUSOLVER_STATUS_SUCCESS:
    return "CUSOLVER_STATUS_SUCCESS";
  case CUSOLVER_STATUS_NOT_INITIALIZED:
    return "CUSOLVER_STATUS_NOT_INITIALIZED";
  case CUSOLVER_STATUS_ALLOC_FAILED:
    return "CUSOLVER_STATUS_ALLOC_FAILED";
  case CUSOLVER_STATUS_INVALID_VALUE:
    return "CUSOLVER_STATUS_INVALID_VALUE";
  case CUSOLVER_STATUS_ARCH_MISMATCH:
    return "CUSOLVER_STATUS_ARCH_MISMATCH";
  case CUSOLVER_STATUS_MAPPING_ERROR:
    return "CUSOLVER_STATUS_MAPPING_ERROR";
  case CUSOLVER_STATUS_EXECUTION_FAILED:
    return "CUSOLVER_STATUS_EXECUTION_FAILED";
  case CUSOLVER_STATUS_INTERNAL_ERROR:
    return "CUSOLVER_STATUS_INTERNAL_ERROR";
  case CUSOLVER_STATUS_MATRIX_TYPE_NOT_SUPPORTED:
    return "CUSOLVER_STATUS_MATRIX_TYPE_NOT_SUPPORTED";
  case CUSOLVER_STATUS_NOT_SUPPORTED:
    return "CUSOLVER_STATUS_NOT_SUPPORTED";
  case CUSOLVER_STATUS_ZERO_PIVOT:
    return "CUSOLVER_STATUS_ZERO_PIVOT";
  default:
    return "CUSOLVER_STATUS_UNKNOWN";
  }
}

inline const char *cusparse_status_to_string(const cusparseStatus_t status) {
  switch (status) {
  case CUSPARSE_STATUS_SUCCESS:
    return "CUSPARSE_STATUS_SUCCESS";
  case CUSPARSE_STATUS_NOT_INITIALIZED:
    return "CUSPARSE_STATUS_NOT_INITIALIZED";
  case CUSPARSE_STATUS_ALLOC_FAILED:
    return "CUSPARSE_STATUS_ALLOC_FAILED";
  case CUSPARSE_STATUS_INVALID_VALUE:
    return "CUSPARSE_STATUS_INVALID_VALUE";
  case CUSPARSE_STATUS_ARCH_MISMATCH:
    return "CUSPARSE_STATUS_ARCH_MISMATCH";
  case CUSPARSE_STATUS_MAPPING_ERROR:
    return "CUSPARSE_STATUS_MAPPING_ERROR";
  case CUSPARSE_STATUS_EXECUTION_FAILED:
    return "CUSPARSE_STATUS_EXECUTION_FAILED";
  case CUSPARSE_STATUS_INTERNAL_ERROR:
    return "CUSPARSE_STATUS_INTERNAL_ERROR";
  case CUSPARSE_STATUS_MATRIX_TYPE_NOT_SUPPORTED:
    return "CUSPARSE_STATUS_MATRIX_TYPE_NOT_SUPPORTED";
  default:
    return "CUSPARSE_STATUS_UNKNOWN";
  }
}

inline std::string cuda_memory_snapshot() {
  std::ostringstream out;
  std::size_t freeBytes = 0;
  std::size_t totalBytes = 0;
  const cudaError_t err = cudaMemGetInfo(&freeBytes, &totalBytes);
  if (err != cudaSuccess) {
    out << "cudaMemGetInfo failed: " << cuda_error_to_string(err);
    return out.str();
  }
  out << "free=" << (freeBytes / (1024.0 * 1024.0)) << " MiB"
      << ", total=" << (totalBytes / (1024.0 * 1024.0)) << " MiB";
  return out.str();
}

template <typename T>
inline bool cuda_allocate(T **ptr, std::size_t count,
                          LinearSolveDiagnostics *diagnostics,
                          const char *label, bool verbose = false) {
  if (verbose) {
    std::cout << "[Directional::integrate] CUDA allocate " << label << ": "
              << count << " elements (" << (sizeof(T) * count) << " bytes)"
              << std::endl;
  }
  const cudaError_t err =
      cudaMalloc(reinterpret_cast<void **>(ptr), sizeof(T) * count);
  if (err != cudaSuccess) {
    if (verbose) {
      std::cout << "[Directional::integrate] CUDA allocate " << label
                << " failed: " << cuda_error_to_string(err) << std::endl;
    }
    if (diagnostics != nullptr) {
      diagnostics->message = std::string(label) + " allocation failed: " +
                             cuda_error_to_string(err);
    }
    return false;
  }
  return true;
}

template <typename T>
inline bool cuda_copy_htod(T *dst, const T *src, std::size_t count,
                            LinearSolveDiagnostics *diagnostics,
                            const char *label, bool verbose = false) {
  if (verbose) {
    std::cout << "[Directional::integrate] CUDA copy H->D " << label << ": "
              << count << " elements (" << (sizeof(T) * count) << " bytes)"
              << std::endl;
  }
  const cudaError_t err =
      cudaMemcpy(dst, src, sizeof(T) * count, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    if (verbose) {
      std::cout << "[Directional::integrate] CUDA copy H->D " << label
                << " failed: " << cuda_error_to_string(err) << std::endl;
    }
    if (diagnostics != nullptr) {
      diagnostics->message = std::string(label) +
                             " host->device copy failed: " +
                             cuda_error_to_string(err);
    }
    return false;
  }
  return true;
}

template <typename T>
inline bool cuda_copy_dtoh(T *dst, const T *src, std::size_t count,
                            LinearSolveDiagnostics *diagnostics,
                            const char *label, bool verbose = false) {
  if (verbose) {
    std::cout << "[Directional::integrate] CUDA copy D->H " << label << ": "
              << count << " elements (" << (sizeof(T) * count) << " bytes)"
              << std::endl;
  }
  const cudaError_t err =
      cudaMemcpy(dst, src, sizeof(T) * count, cudaMemcpyDeviceToHost);
  if (err != cudaSuccess) {
    if (verbose) {
      std::cout << "[Directional::integrate] CUDA copy D->H " << label
                << " failed: " << cuda_error_to_string(err) << std::endl;
    }
    if (diagnostics != nullptr) {
      diagnostics->message = std::string(label) +
                             " device->host copy failed: " +
                             cuda_error_to_string(err);
    }
    return false;
  }
  return true;
}
#endif

inline bool solve_on_cpu(const Eigen::SparseMatrix<double> &A,
                         const Eigen::VectorXd &b, Eigen::VectorXd &x,
                         LinearSolveDiagnostics *diagnostics,
                         const std::string &reason) {
  Eigen::SparseLU<Eigen::SparseMatrix<double>> solver;
  solver.compute(A);
  if (solver.info() != Eigen::Success) {
    if (diagnostics != nullptr) {
      diagnostics->usedCuda = false;
      diagnostics->usedFallback = false;
      diagnostics->message = "CPU SparseLU decomposition failed.";
    }
    return false;
  }

  x = solver.solve(b);
  if (solver.info() != Eigen::Success) {
    if (diagnostics != nullptr) {
      diagnostics->usedCuda = false;
      diagnostics->usedFallback = false;
      diagnostics->message = "CPU SparseLU solve failed.";
    }
    return false;
  }

  if (diagnostics != nullptr) {
    diagnostics->usedCuda = false;
    diagnostics->usedFallback = !reason.empty();
    diagnostics->message = reason.empty() ? "Solved on CPU." : reason;
  }
  return true;
}

#if defined(DIRECTIONAL_ENABLE_CUDA)
template <typename T> struct CudaFreer {
  void operator()(T *ptr) const {
    if (ptr != nullptr) {
      cudaFree(ptr);
    }
  }
};

struct CusolverSpHandleDeleter {
  void operator()(cusolverSpContext *handle) const {
    if (handle != nullptr) {
      cusolverSpDestroy(handle);
    }
  }
};

struct CusparseMatDescrDeleter {
  void operator()(cusparseMatDescr *descr) const {
    if (descr != nullptr) {
      cusparseDestroyMatDescr(descr);
    }
  }
};

inline bool solve_on_cuda_sparse(const Eigen::SparseMatrix<double> &A,
                                 const Eigen::VectorXd &b,
                                 const LinearSolveOptions &options,
                                 Eigen::VectorXd &x,
                                 LinearSolveDiagnostics *diagnostics) {
  if (A.rows() != A.cols()) {
    return solve_on_cpu(
        A, b, x, diagnostics,
        "CUDA solver skipped because the reduced system is not square.");
  }

  const int n = static_cast<int>(A.rows());
  if (n == 0) {
    x.resize(0);
    if (diagnostics != nullptr) {
      diagnostics->usedCuda = true;
      diagnostics->usedFallback = false;
      diagnostics->message = "Solved empty system on CUDA path.";
    }
    return true;
  }

  Eigen::SparseMatrix<double, Eigen::RowMajor, int> csrA = A;
  csrA.makeCompressed();
  const int rows = static_cast<int>(csrA.rows());
  const int cols = static_cast<int>(csrA.cols());
  const int nnz = static_cast<int>(csrA.nonZeros());

  if (options.verbose) {
    std::cout << "[Directional::integrate] CUDA sparse QR input: rows="
              << rows << ", cols=" << cols << ", nnz=" << nnz
              << ", rowPtr[0]=" << csrA.outerIndexPtr()[0]
              << ", rowPtr[n]=" << csrA.outerIndexPtr()[rows] << std::endl;
    std::cout << "[Directional::integrate] CUDA device memory snapshot: "
              << cuda_memory_snapshot() << std::endl;
    int zeroRows = 0;
    int maxRowNNZ = 0;
    for (int r = 0; r < rows; ++r) {
      const int rowNNZ = csrA.outerIndexPtr()[r + 1] - csrA.outerIndexPtr()[r];
      if (rowNNZ == 0) {
        ++zeroRows;
      }
      if (rowNNZ > maxRowNNZ) {
        maxRowNNZ = rowNNZ;
      }
    }
    const double avgRowNNZ =
        rows > 0 ? static_cast<double>(nnz) / static_cast<double>(rows) : 0.0;
    std::cout << "[Directional::integrate] CUDA sparse QR row stats: zero_rows="
              << zeroRows << ", max_row_nnz=" << maxRowNNZ
              << ", avg_row_nnz=" << avgRowNNZ << std::endl;
  }

  cusolverSpHandle_t rawHandle = nullptr;
  const cusolverStatus_t handleStatus = cusolverSpCreate(&rawHandle);
  if (handleStatus != CUSOLVER_STATUS_SUCCESS) {
    std::ostringstream reason;
    reason << "CUDA solver initialization failed: "
           << cusolver_status_to_string(handleStatus);
    if (options.verbose) {
      std::cout << "[Directional::integrate] CUDA solver handle creation failed: "
                << cusolver_status_to_string(handleStatus) << std::endl;
    }
    if (diagnostics != nullptr) {
      diagnostics->message = reason.str();
    }
    return solve_on_cpu(A, b, x, diagnostics, reason.str() + "; fell back to CPU.");
  }
  std::unique_ptr<cusolverSpContext, CusolverSpHandleDeleter> handle(rawHandle);

  cusparseMatDescr_t rawDescr = nullptr;
  const cusparseStatus_t descrStatus = cusparseCreateMatDescr(&rawDescr);
  if (descrStatus != CUSPARSE_STATUS_SUCCESS) {
    std::ostringstream reason;
    reason << "CUDA sparse descriptor creation failed: "
           << cusparse_status_to_string(descrStatus);
    if (options.verbose) {
      std::cout << "[Directional::integrate] CUDA sparse descriptor creation failed: "
                << cusparse_status_to_string(descrStatus) << std::endl;
    }
    if (diagnostics != nullptr) {
      diagnostics->message = reason.str();
    }
    return solve_on_cpu(
        A, b, x, diagnostics, reason.str() + "; fell back to CPU.");
  }
  std::unique_ptr<cusparseMatDescr, CusparseMatDescrDeleter> descr(rawDescr);
  cusparseSetMatType(descr.get(), CUSPARSE_MATRIX_TYPE_GENERAL);
  cusparseSetMatIndexBase(descr.get(), CUSPARSE_INDEX_BASE_ZERO);

  int *dRowPtr = nullptr;
  int *dColInd = nullptr;
  double *dVals = nullptr;
  double *dB = nullptr;
  double *dX = nullptr;

  if (!cuda_allocate(&dRowPtr, static_cast<std::size_t>(rows + 1), diagnostics,
                     "csrRowPtr", options.verbose) ||
      !cuda_allocate(&dColInd, static_cast<std::size_t>(nnz), diagnostics,
                     "csrColInd", options.verbose) ||
      !cuda_allocate(&dVals, static_cast<std::size_t>(nnz), diagnostics,
                     "csrVal", options.verbose) ||
      !cuda_allocate(&dB, static_cast<std::size_t>(rows), diagnostics, "rhs",
                     options.verbose) ||
      !cuda_allocate(&dX, static_cast<std::size_t>(rows), diagnostics,
                     "solution", options.verbose)) {
    cudaFree(dRowPtr);
    cudaFree(dColInd);
    cudaFree(dVals);
      cudaFree(dB);
      cudaFree(dX);
    return solve_on_cpu(A, b, x, diagnostics,
                        "CUDA device allocation failed; fell back to CPU.");
  }

  if (!cuda_copy_htod(dRowPtr, csrA.outerIndexPtr(),
                      static_cast<std::size_t>(rows + 1), diagnostics,
                      "csrRowPtr", options.verbose) ||
      !cuda_copy_htod(dColInd, csrA.innerIndexPtr(),
                      static_cast<std::size_t>(nnz), diagnostics,
                      "csrColInd", options.verbose) ||
      !cuda_copy_htod(dVals, csrA.valuePtr(), static_cast<std::size_t>(nnz),
                      diagnostics, "csrVal", options.verbose) ||
      !cuda_copy_htod(dB, b.data(), static_cast<std::size_t>(rows),
                      diagnostics, "rhs", options.verbose)) {
    cudaFree(dRowPtr);
    cudaFree(dColInd);
    cudaFree(dVals);
      cudaFree(dB);
      cudaFree(dX);
    return solve_on_cpu(A, b, x, diagnostics,
                        "CUDA host-to-device copy failed; fell back to CPU.");
  }

  x.resize(rows);
  int singularity = -1;
  constexpr double tolerance = 1e-12;
  constexpr int reorder = 0;
  const cusolverStatus_t solveStatus = cusolverSpDcsrlsvqr(
      rawHandle, rows, nnz, descr.get(), dVals, dRowPtr, dColInd, dB,
      tolerance, reorder, dX, &singularity);

  if (options.verbose) {
    const cudaError_t postSolveCudaError = cudaGetLastError();
    std::cout << "[Directional::integrate] CUDA sparse QR post-call status: "
              << cusolver_status_to_string(solveStatus)
              << ", cuda_last_error="
              << cuda_error_to_string(postSolveCudaError)
              << ", singularity=" << singularity << std::endl;
  }

  if (solveStatus != CUSOLVER_STATUS_SUCCESS) {
    std::ostringstream reason;
    reason << "CUDA sparse QR failed: "
           << cusolver_status_to_string(solveStatus);
    if (singularity >= 0) {
      reason << ", singularity=" << singularity;
    }
    reason << ", cuda_last_error=" << cuda_error_to_string(cudaGetLastError());
    if (options.verbose) {
      std::cout << "[Directional::integrate] CUDA sparse QR execution failed. "
                << "Inspect the post-call status, singularity, and matrix stats "
                << "above for the failure mode." << std::endl;
    }
    if (diagnostics != nullptr) {
      diagnostics->message = reason.str();
    }
    cudaFree(dRowPtr);
    cudaFree(dColInd);
    cudaFree(dVals);
    cudaFree(dB);
    cudaFree(dX);
    return solve_on_cpu(A, b, x, diagnostics,
                        reason.str() + "; fell back to CPU.");
  }

  if (options.verbose) {
    std::cout << "[Directional::integrate] CUDA sparse QR singularity index="
              << singularity << std::endl;
  }
  if (singularity >= 0) {
    std::ostringstream message;
    message << "CUDA sparse QR reported singularity at row " << singularity
            << "; fell back to CPU.";
    cudaFree(dRowPtr);
    cudaFree(dColInd);
    cudaFree(dVals);
    cudaFree(dB);
    cudaFree(dX);
    return solve_on_cpu(A, b, x, diagnostics, message.str());
  }

  if (!cuda_copy_dtoh(x.data(), dX, static_cast<std::size_t>(rows),
                      diagnostics, "solution", options.verbose)) {
    cudaFree(dRowPtr);
    cudaFree(dColInd);
    cudaFree(dVals);
    cudaFree(dB);
    cudaFree(dX);
    return solve_on_cpu(
        A, b, x, diagnostics,
        "CUDA device-to-host copy failed; fell back to CPU.");
  }

  cudaFree(dRowPtr);
  cudaFree(dColInd);
  cudaFree(dVals);
  cudaFree(dB);
  cudaFree(dX);

  if (options.verbose) {
    std::cout << "[Directional::integrate] CUDA sparse QR device resources released"
              << std::endl;
  }

  if (diagnostics != nullptr) {
    diagnostics->usedCuda = true;
    diagnostics->usedFallback = false;
    diagnostics->message = "Solved reduced system with CUDA sparse QR.";
  }
  if (options.verbose) {
    std::cout << "[Directional::integrate] CUDA sparse QR solve succeeded for "
              << rows << "x" << cols << " reduced system with " << nnz
              << " nonzeros" << std::endl;
  }
  return true;
}
#endif

} // namespace detail

inline bool cuda_solver_available() {
#if defined(DIRECTIONAL_ENABLE_CUDA)
  return true;
#else
  return false;
#endif
}

inline bool
solve_sparse_linear_system(const Eigen::SparseMatrix<double> &A,
                           const Eigen::VectorXd &b,
                           const LinearSolveOptions &options, Eigen::VectorXd &x,
                           LinearSolveDiagnostics *diagnostics = nullptr) {
  if (diagnostics != nullptr) {
    diagnostics->usedCuda = false;
    diagnostics->usedFallback = false;
    diagnostics->message.clear();
  }

#if defined(DIRECTIONAL_ENABLE_CUDA)
  if (options.preferCuda) {
    return detail::solve_on_cuda_sparse(A, b, options, x, diagnostics);
  }
  return detail::solve_on_cpu(A, b, x, diagnostics, std::string{});
#else
  return detail::solve_on_cpu(
      A, b, x, diagnostics,
      options.preferCuda
          ? "CUDA solver was requested, but Directional was built without CUDA support."
          : std::string{});
#endif
}

} // namespace directional

#endif
