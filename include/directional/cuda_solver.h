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

/// Persistent CUDA sparse solver that keeps matrix data resident on GPU
/// across multiple solve calls. Reuses symbolic analysis when sparsity
/// pattern is unchanged.
struct CudaSolver {
  // CSR matrix structure
  int rows = 0;
  int cols = 0;
  int nnz = 0;

  // Device pointers (owned)
  std::unique_ptr<int[], CudaFreer<int>> dRowPtr;
  std::unique_ptr<int[], CudaFreer<int>> dColInd;
  std::unique_ptr<double[], CudaFreer<double>> dVals;

  // cuSOLVER / cuSPARSE handles
  std::unique_ptr<cusolverSpContext, CusolverSpHandleDeleter> handle;
  std::unique_ptr<cusparseMatDescr, CusparseMatDescrDeleter> descr;

  // Symbolic analysis state
  bool analyzed = false;
  int lastRows = -1;
  int lastCols = -1;
  int lastNnz = -1;
  std::size_t lastRowPtrHash = 0;
  std::size_t lastColIndHash = 0;

  CudaSolver() = default;
  CudaSolver(const CudaSolver &) = delete;
  CudaSolver &operator=(const CudaSolver &) = delete;
  CudaSolver(CudaSolver &&) = default;
  CudaSolver &operator=(CudaSolver &&) = default;

  ~CudaSolver() = default;

  /// Reset all GPU resources and analysis state
  void reset() {
    dRowPtr.reset();
    dColInd.reset();
    dVals.reset();
    handle.reset();
    descr.reset();
    analyzed = false;
    rows = cols = nnz = 0;
    lastRows = lastCols = lastNnz = -1;
    lastRowPtrHash = lastColIndHash = 0;
  }

  /// Compute hash of CSR structure for pattern change detection
  static std::size_t hash_csr_structure(const int *rowPtr, const int *colInd, int rows, int nnz) {
    std::size_t h1 = 0, h2 = 0;
    for (int i = 0; i <= rows; ++i) {
      h1 = h1 * 31 + static_cast<std::size_t>(rowPtr[i]);
    }
    for (int i = 0; i < nnz; ++i) {
      h2 = h2 * 31 + static_cast<std::size_t>(colInd[i]);
    }
    return h1 * 31 + h2;
  }

  /// Initialize or re-initialize GPU-resident CSR data and handles.
  /// Returns true on success, false on allocation failure.
  bool init(int rows_, int cols_, int nnz_,
            const int *hRowPtr, const int *hColInd, const double *hVals,
            bool verbose = false,
            LinearSolveDiagnostics *diagnostics = nullptr) {
    if (rows_ <= 0 || cols_ <= 0 || nnz_ <= 0) {
      if (diagnostics) diagnostics->message = "Invalid matrix dimensions";
      return false;
    }

    // Check if we can reuse existing allocation
    if (analyzed && rows_ == rows && cols_ == cols && nnz_ == nnz) {
      // Same shape: check if pattern is identical
      std::size_t rowPtrHash = hash_csr_structure(hRowPtr, hColInd, rows_, nnz_);
      if (rowPtrHash == lastRowPtrHash && rowPtrHash == lastColIndHash) {
        // Pattern unchanged - only update values
        if (verbose) {
          std::cout << "[Directional::CudaSolver] Pattern unchanged, updating values only\n";
        }
        if (!cuda_copy_htod(dVals.get(), hVals, static_cast<std::size_t>(nnz_),
                            diagnostics, "csrVal", verbose)) {
          return false;
        }
        return true;
      }
    }

    // Pattern changed or first time: full re-initialization
    reset();

    rows = rows_;
    cols = cols_;
    nnz = nnz_;

    // Allocate device memory for CSR data
    int *dRowPtrRaw = nullptr;
    int *dColIndRaw = nullptr;
    double *dValsRaw = nullptr;

    if (!cuda_allocate(&dRowPtrRaw, static_cast<std::size_t>(rows + 1), diagnostics,
                       "csrRowPtr", verbose) ||
        !cuda_allocate(&dColIndRaw, static_cast<std::size_t>(nnz), diagnostics,
                       "csrColInd", verbose) ||
        !cuda_allocate(&dValsRaw, static_cast<std::size_t>(nnz), diagnostics,
                       "csrVal", verbose)) {
      cudaFree(dRowPtrRaw);
      cudaFree(dColIndRaw);
      cudaFree(dValsRaw);
      if (diagnostics) diagnostics->message = "CUDA device allocation failed";
      return false;
    }

    dRowPtr.reset(dRowPtrRaw);
    dColInd.reset(dColIndRaw);
    dVals.reset(dValsRaw);

    if (!cuda_copy_htod(dRowPtr.get(), hRowPtr, static_cast<std::size_t>(rows + 1),
                        diagnostics, "csrRowPtr", verbose) ||
        !cuda_copy_htod(dColInd.get(), hColInd, static_cast<std::size_t>(nnz),
                        diagnostics, "csrColInd", verbose) ||
        !cuda_copy_htod(dVals.get(), hVals, static_cast<std::size_t>(nnz),
                        diagnostics, "csrVal", verbose)) {
      if (diagnostics) diagnostics->message = "CUDA host-to-device copy failed";
      return false;
    }

    // Create cuSOLVER handle
    cusolverSpHandle_t rawHandle = nullptr;
    const cusolverStatus_t handleStatus = cusolverSpCreate(&rawHandle);
    if (handleStatus != CUSOLVER_STATUS_SUCCESS) {
      if (diagnostics) {
        diagnostics->message = "CUDA solver initialization failed: " +
                               std::string(cusolver_status_to_string(handleStatus));
      }
      return false;
    }
    handle.reset(rawHandle);

    // Create cuSPARSE descriptor
    cusparseMatDescr_t rawDescr = nullptr;
    const cusparseStatus_t descrStatus = cusparseCreateMatDescr(&rawDescr);
    if (descrStatus != CUSPARSE_STATUS_SUCCESS) {
      if (diagnostics) {
        diagnostics->message = "CUDA sparse descriptor creation failed: " +
                               std::string(cusparse_status_to_string(descrStatus));
      }
      return false;
    }
    descr.reset(rawDescr);
    cusparseSetMatType(descr.get(), CUSPARSE_MATRIX_TYPE_GENERAL);
    cusparseSetMatIndexBase(descr.get(), CUSPARSE_INDEX_BASE_ZERO);

    // Record pattern hash for future reuse
    lastRowPtrHash = hash_csr_structure(hRowPtr, hColInd, rows_, nnz_);
    lastColIndHash = lastRowPtrHash;  // Same hash for both in this implementation
    lastRows = rows_;
    lastCols = cols_;
    lastNnz = nnz_;

    analyzed = true;

    if (verbose) {
      std::cout << "[Directional::CudaSolver] Initialized: rows=" << rows
                << ", cols=" << cols << ", nnz=" << nnz << std::endl;
    }
    return true;
  }

  /// Solve A*x = b using the pre-initialized matrix.
  /// Returns true on success.
  bool solve(const double *hB, int bSize, double *hX,
             const LinearSolveOptions &options,
             LinearSolveDiagnostics *diagnostics) {
    if (!analyzed || !handle || !descr) {
      if (diagnostics) diagnostics->message = "CudaSolver not initialized";
      return false;
    }
    if (bSize != rows) {
      if (diagnostics) diagnostics->message = "RHS size mismatch";
      return false;
    }

    // Device RHS and solution buffers
    std::unique_ptr<double[], CudaFreer<double>> dB;
    std::unique_ptr<double[], CudaFreer<double>> dX;

    double *dBRaw = nullptr;
    double *dXRaw = nullptr;

    if (!cuda_allocate(&dBRaw, static_cast<std::size_t>(rows), diagnostics, "rhs", options.verbose) ||
        !cuda_allocate(&dXRaw, static_cast<std::size_t>(rows), diagnostics, "solution", options.verbose)) {
      cudaFree(dBRaw);
      cudaFree(dXRaw);
      if (diagnostics) diagnostics->message = "CUDA RHS/solution allocation failed";
      return false;
    }

    dB.reset(dBRaw);
    dX.reset(dXRaw);

    if (!cuda_copy_htod(dB.get(), hB, static_cast<std::size_t>(rows),
                        diagnostics, "rhs", options.verbose)) {
      if (diagnostics) diagnostics->message = "CUDA RHS copy failed";
      return false;
    }

    int singularity = -1;
    constexpr double tolerance = 1e-12;
    constexpr int reorder = 0;

    const cusolverStatus_t solveStatus = cusolverSpDcsrlsvqr(
        handle.get(), rows, nnz, descr.get(),
        dVals.get(), dRowPtr.get(), dColInd.get(),
        dB.get(), tolerance, reorder, dX.get(), &singularity);

    if (options.verbose) {
      const cudaError_t postSolveCudaError = cudaGetLastError();
      std::cout << "[Directional::CudaSolver] Solve status: "
                << cusolver_status_to_string(solveStatus)
                << ", cuda_last_error=" << cuda_error_to_string(postSolveCudaError)
                << ", singularity=" << singularity << std::endl;
    }

    if (solveStatus != CUSOLVER_STATUS_SUCCESS) {
      std::ostringstream reason;
      reason << "CUDA sparse QR failed: " << cusolver_status_to_string(solveStatus);
      if (singularity >= 0) {
        reason << ", singularity=" << singularity;
      }
      reason << ", cuda_last_error=" << cuda_error_to_string(cudaGetLastError());
      if (diagnostics) diagnostics->message = reason.str();
      return false;
    }

    if (singularity >= 0) {
      std::ostringstream message;
      message << "CUDA sparse QR reported singularity at row " << singularity;
      if (diagnostics) diagnostics->message = message.str();
      return false;
    }

    if (!cuda_copy_dtoh(hX, dX.get(), static_cast<std::size_t>(rows),
                        diagnostics, "solution", options.verbose)) {
      if (diagnostics) diagnostics->message = "CUDA solution copy failed";
      return false;
    }

    if (diagnostics) {
      diagnostics->usedCuda = true;
      diagnostics->usedFallback = false;
      diagnostics->message = "Solved with persistent CUDA sparse QR.";
    }
    return true;
  }
};

/// Backward-compatible one-shot solve (creates temporary CudaSolver internally).
/// Kept for existing callers that don't want persistent state.
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

  CudaSolver solver;
  if (!solver.init(rows, cols, nnz,
                   csrA.outerIndexPtr(), csrA.innerIndexPtr(), csrA.valuePtr(),
                   options.verbose, diagnostics)) {
    return solve_on_cpu(A, b, x, diagnostics,
                        solver.analyzed ? "CUDA solver init failed; fell back to CPU."
                                        : "CUDA solver allocation failed; fell back to CPU.");
  }

  x.resize(rows);
  if (!solver.solve(b.data(), rows, x.data(), options, diagnostics)) {
    return solve_on_cpu(A, b, x, diagnostics,
                        diagnostics ? diagnostics->message + "; fell back to CPU."
                                    : "CUDA solve failed; fell back to CPU.");
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