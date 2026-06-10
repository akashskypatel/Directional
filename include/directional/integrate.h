// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2021 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_INTEGRATE_H
#define DIRECTIONAL_INTEGRATE_H

#include <Eigen/Core>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <directional/CartesianField.h>
#include <directional/PCFaceTangentBundle.h>
#include <directional/TriMesh.h>
#include <directional/branched_gradient.h>
#include <directional/principal_matching.h>
#include <directional/setup_integration.h>
#include <directional/tree.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <type_traits>
#include <vector>

#ifdef USE_SUITESPARSE_ENABLED
#if __has_include(<umfpack.h>)
#include <umfpack.h>
#elif __has_include(<suitesparse/umfpack.h>)
#include <suitesparse/umfpack.h>
#else
#error "USE_SUITESPARSE_ENABLED is defined, but umfpack.h was not found"
#endif
#else
#include <Eigen/SparseLU>
#endif

#ifdef USE_SUITESPARSE_ENABLED
#ifndef DIRECTIONAL_UMFPACK_ORDERING
#define DIRECTIONAL_UMFPACK_ORDERING UMFPACK_ORDERING_AMD
#endif

#ifndef DIRECTIONAL_UMFPACK_STRATEGY
#define DIRECTIONAL_UMFPACK_STRATEGY UMFPACK_STRATEGY_SYMMETRIC
#endif

#ifndef DIRECTIONAL_UMFPACK_SCALE
#define DIRECTIONAL_UMFPACK_SCALE UMFPACK_SCALE_SUM
#endif
#endif

namespace directional {

// Integrates an N-directional fields into an N-function by solving the seamless
// Poisson equation. Respects *valid* linear reductions where the field is
// reducible to an n-field for n<=M, and consequently the function is reducible
// to an n-function. This function only works with face-based fields on triangle
// meshes. Input:
//  field:              The face-based field to be integrated, on the original
//  mesh intData:            Integration data, which must be obtained from
//  directional::setup_integration(). This is altered by the function. meshCut:
//  Cut mesh (obtained from setup_integration())
// Output:
//  NFunction:          #cV x N parameterization functions per cut vertex (full
//  version with all symmetries unpacked) NCornerFunctions   (3*N) x #F
//  parameterization functions per corner of whole mesh
inline bool
integrate(const directional::CartesianField &field, IntegrationData &intData,
          const directional::TriMesh &meshCut, Eigen::MatrixXd &NFunction,
          Eigen::MatrixXd &NCornerFunctions)

{
  using namespace Eigen;
  using namespace std;
  using Clock = std::chrono::high_resolution_clock;

  const auto integrateStart = Clock::now();
  auto phaseStart = integrateStart;
  const auto log_phase = [&](const char *label) {
    if (!intData.verbose)
      return;
    const auto now = Clock::now();
    const auto phaseSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now - phaseStart)
            .count() /
        1e+6;
    const auto totalSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now -
                                                              integrateStart)
            .count() /
        1e+6;
    cout << "[Directional::integrate] " << label << " completed in "
         << phaseSeconds << " s (total " << totalSeconds << " s)" << endl;
    phaseStart = now;
  };
  const auto should_log_progress = [&](int index, int total) {
    if (!intData.verbose || total <= 0)
      return false;
    if (index == 0 || index + 1 == total)
      return true;
    const int step = std::max(1, total / 10);
    return ((index + 1) % step) == 0;
  };
  const auto log_progress = [&](const char *label, int index, int total) {
    if (!should_log_progress(index, total))
      return;
    cout << "[Directional::integrate] " << label << ": " << (index + 1) << "/"
         << total << endl;
  };

  const auto seconds_since = [](const Clock::time_point &start) -> double {
    return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                                 start)
               .count() /
           1.0e6;
  };

  struct IterativeSolveTimings {
    double fullEnergyPrecompute = 0.0;
    double freeVariableMap = 0.0;
    double reducedOperatorExtraction = 0.0;
    double constraintRankReduction = 0.0;
    double kktMatrixAssembly = 0.0;
    double rhsAssembly = 0.0;
    double symbolicAnalysis = 0.0;
    double numericFactorization = 0.0;
    double backSubstitution = 0.0;
    double fullSolutionReconstruction = 0.0;
    double integerCandidateSelection = 0.0;

    std::size_t iterations = 0;
    std::size_t factorizationFailures = 0;
    std::size_t solveFailures = 0;

#ifdef USE_SUITESPARSE_ENABLED
    double umfpackTotalFlops = 0.0;
    double umfpackMaximumLNonzeros = 0.0;
    double umfpackMaximumUNonzeros = 0.0;
    double umfpackMaximumPeakMemory = 0.0;
#endif

    Eigen::Index maximumSystemRows = 0;
    Eigen::Index maximumSystemNonZeros = 0;
    Eigen::Index maximumConstraintRows = 0;
    Eigen::Index maximumFreeVariables = 0;
  };

  IterativeSolveTimings iterativeTimings;

  const auto print_iterative_timing_summary = [&]() {
    if (!intData.verbose)
      return;

    const double measuredTotal = iterativeTimings.fullEnergyPrecompute +
                                 iterativeTimings.freeVariableMap +
                                 iterativeTimings.reducedOperatorExtraction +
                                 iterativeTimings.constraintRankReduction +
                                 iterativeTimings.kktMatrixAssembly +
                                 iterativeTimings.rhsAssembly +
                                 iterativeTimings.symbolicAnalysis +
                                 iterativeTimings.numericFactorization +
                                 iterativeTimings.backSubstitution +
                                 iterativeTimings.fullSolutionReconstruction +
                                 iterativeTimings.integerCandidateSelection;

    std::cout << "[Directional::integrate] iterative solve timing summary\n"
              << "  iterations:                    "
              << iterativeTimings.iterations << '\n'
              << "  full energy precompute:        "
              << iterativeTimings.fullEnergyPrecompute << " s\n"
              << "  free-variable map:             "
              << iterativeTimings.freeVariableMap << " s\n"
              << "  reduced operator extraction:   "
              << iterativeTimings.reducedOperatorExtraction << " s\n"
              << "  constraint rank reduction:     "
              << iterativeTimings.constraintRankReduction << " s\n"
              << "  KKT matrix assembly:           "
              << iterativeTimings.kktMatrixAssembly << " s\n"
              << "  RHS assembly:                  "
              << iterativeTimings.rhsAssembly << " s\n"
              << "  symbolic analysis:             "
              << iterativeTimings.symbolicAnalysis << " s\n"
              << "  numeric factorization:          "
              << iterativeTimings.numericFactorization << " s\n"
              << "  back substitution:             "
              << iterativeTimings.backSubstitution << " s\n"
              << "  full-solution reconstruction:  "
              << iterativeTimings.fullSolutionReconstruction << " s\n"
              << "  integer candidate selection:   "
              << iterativeTimings.integerCandidateSelection << " s\n"
              << "  measured iterative total:      " << measuredTotal << " s\n"
              << "  factorization failures:        "
              << iterativeTimings.factorizationFailures << '\n'
              << "  solve failures:                "
              << iterativeTimings.solveFailures << '\n'
#ifdef USE_SUITESPARSE_ENABLED
              << "  UMFPACK total estimated flops: "
              << iterativeTimings.umfpackTotalFlops << '\n'
              << "  UMFPACK maximum L nonzeros:     "
              << iterativeTimings.umfpackMaximumLNonzeros << '\n'
              << "  UMFPACK maximum U nonzeros:     "
              << iterativeTimings.umfpackMaximumUNonzeros << '\n'
              << "  UMFPACK maximum peak memory:    "
              << iterativeTimings.umfpackMaximumPeakMemory << '\n'
#endif
              << "  maximum free variables:        "
              << iterativeTimings.maximumFreeVariables << '\n'
              << "  maximum constraint rows:       "
              << iterativeTimings.maximumConstraintRows << '\n'
              << "  maximum system rows:           "
              << iterativeTimings.maximumSystemRows << '\n'
              << "  maximum system nonzeros:       "
              << iterativeTimings.maximumSystemNonZeros << '\n';
  };

  assert(field.tb->discTangType() == discTangTypeEnum::FACE_SPACES &&
         "Integrate() only works with face-based fields");
  const directional::TriMesh &meshWhole =
      *((PCFaceTangentBundle *)field.tb)->mesh;

  VectorXd edgeWeights = VectorXd::Constant(meshWhole.FE.maxCoeff() + 1, 1.0);
  double paramLength =
      (meshWhole.V.colwise().maxCoeff() - meshWhole.V.colwise().minCoeff())
          .norm() *
      intData.lengthRatio;

  MatrixXd rawField = field.extField;
  double avgGradNorm = 0;
  for (int i = 0; i < meshWhole.F.rows(); i++)
    for (int j = 0; j < intData.N; j++)
      avgGradNorm += rawField.block(i, 3 * j, 1, 3).norm();

  avgGradNorm /= (double)(intData.N * meshWhole.F.rows());

  rawField.array() /= avgGradNorm;
  paramLength /= avgGradNorm;
  log_phase("Field normalization");

  int numVars = intData.linRedMat.cols();
  // constructing face differentials
  // TODO: convert to the common branched gradient operator
  vector<Triplet<double>> d0Triplets;
  vector<Triplet<double>> M1Triplets;
  VectorXd gamma(3 * intData.N * meshWhole.F.rows());
  for (int i = 0; i < meshCut.F.rows(); i++) {
    log_progress("differential assembly", i, meshCut.F.rows());
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < intData.N; k++) {
        d0Triplets.emplace_back(3 * intData.N * i + intData.N * j + k,
                                intData.N * meshCut.F(i, j) + k, -1.0);
        d0Triplets.emplace_back(3 * intData.N * i + intData.N * j + k,
                                intData.N * meshCut.F(i, (j + 1) % 3) + k, 1.0);
        Vector3d edgeVector = (meshCut.V.row(meshCut.F(i, (j + 1) % 3)) -
                               meshCut.V.row(meshCut.F(i, j)))
                                  .transpose();
        gamma(3 * intData.N * i + intData.N * j + k) =
            (rawField.block(i, 3 * k, 1, 3) * edgeVector)(0, 0) / paramLength;
        M1Triplets.emplace_back(3 * intData.N * i + intData.N * j + k,
                                3 * intData.N * i + intData.N * j + k,
                                edgeWeights(meshWhole.FE(i, j)));
      }
    }
  }
  SparseMatrix<double> d0(3 * intData.N * meshWhole.F.rows(),
                          intData.N * meshCut.V.rows());
  d0.setFromTriplets(d0Triplets.begin(), d0Triplets.end());
  SparseMatrix<double> M1(3 * intData.N * meshWhole.F.rows(),
                          3 * intData.N * meshWhole.F.rows());
  M1.setFromTriplets(M1Triplets.begin(), M1Triplets.end());
  SparseMatrix<double> d0T = d0.transpose();
  log_phase("Differential matrix assembly");

  // creating face vector mass matrix
  std::vector<Triplet<double>> MxTri;
  VectorXd darea = meshCut.faceAreas / 2.0;
  // igl::doublearea(meshCut.V,meshCut.F,darea);
  for (int i = 0; i < meshCut.F.rows(); i++)
    for (int j = 0; j < intData.N; j++)
      for (int k = 0; k < 3; k++)
        MxTri.push_back(Triplet<double>(i * 3 * intData.N + 3 * j + k,
                                        3 * i * intData.N + 3 * j + k,
                                        darea(i) / 2.0));

  SparseMatrix<double> Mx(3 * intData.N * meshCut.F.rows(),
                          3 * intData.N * meshCut.F.rows());
  Mx.setFromTriplets(MxTri.begin(), MxTri.end());
  log_phase("Face mass matrix assembly");

  // The variables that should be fixed in the end
  VectorXi fixedMask(numVars);
  fixedMask.setZero();

  for (int i = 0; i < intData.fixedIndices.size(); i++)
    fixedMask(intData.fixedIndices(i)) = 1;

  bool roundedSingularities =
      false; // if all singularities have been rounded (only relevant to
             // intData.roundSeams=false)
  if (intData.integralSeamless) {
    if (intData.roundSeams) {
      for (int i = 0; i < intData.integerVars.size(); i++)
        for (int j = 0; j < intData.n; j++)
          fixedMask(intData.n * intData.integerVars(i) + j) = 1;
    } else {
      for (int i = 0; i < intData.singularIndices.size(); i++)
        fixedMask(intData.singularIndices(i)) = 1;
    }
  }

  // the variables that were already fixed to begin with
  VectorXi alreadyFixed(numVars);
  alreadyFixed.setZero();

  for (int i = 0; i < intData.fixedIndices.size(); i++)
    alreadyFixed(intData.fixedIndices(i)) = 1;

  // the values for the fixed variables (size is as all variables)
  VectorXd fixedValues(numVars);
  fixedValues.setZero(); // for everything but the originally fixed values
  for (int i = 0; i < intData.fixedValues.size(); i++)
    fixedValues(intData.fixedIndices(i)) = intData.fixedValues(i);

  SparseMatrix<double> Efull = d0 * intData.vertexTrans2CutMat *
                               intData.linRedMat * intData.singIntSpanMat *
                               intData.intSpanMat;
  VectorXd x, xprev;

  // until then all the N depedencies should be resolved?

  // reducing constraintMat
  SparseQR<SparseMatrix<double>, COLAMDOrdering<int>> qrsolver;
  SparseMatrix<double> Cfull = intData.constraintMat * intData.linRedMat *
                               intData.singIntSpanMat * intData.intSpanMat;
  if (Cfull.rows() != 0) {
    qrsolver.compute(Cfull.transpose());
    int CRank = qrsolver.rank();

    // creating sliced permutation matrix
    VectorXi PIndices = qrsolver.colsPermutation().indices();

    vector<Triplet<double>> CTriplets;
    for (int k = 0; k < Cfull.outerSize(); ++k) {
      for (SparseMatrix<double>::InnerIterator it(Cfull, k); it; ++it) {
        for (int j = 0; j < CRank; j++)
          if (it.row() == PIndices(j))
            CTriplets.emplace_back(j, it.col(), it.value());
      }
    }

    Cfull.resize(CRank, Cfull.cols());
    Cfull.setFromTriplets(CTriplets.begin(), CTriplets.end());
  }
  log_phase("Constraint reduction");

  /*
   * Precompute the full quadratic energy once:
   *
   *   H = E^T M E
   *   q = E^T M gamma
   *
   * The previous implementation rebuilt
   *
   *   Epart = E * P
   *   EtE   = Epart^T M Epart
   *
   * on every mixed-integer solve. Since P only selects the currently free
   * variables, each reduced system can instead be extracted directly from H.
   *
   * The reduced right-hand side is:
   *
   *   q_free - (H * fixedValues)_free
   */
  const auto fullEnergyPrecomputeStart = Clock::now();

  SparseMatrix<double> fullEnergy = Efull.transpose() * M1 * Efull;

  fullEnergy.makeCompressed();

  const VectorXd fullEnergyRhs = Efull.transpose() * M1 * gamma;

  iterativeTimings.fullEnergyPrecompute +=
      seconds_since(fullEnergyPrecomputeStart);

  if (fullEnergy.rows() != numVars || fullEnergy.cols() != numVars ||
      fullEnergyRhs.size() != numVars) {
    throw std::runtime_error(
        "integrate(): precomputed full energy has inconsistent dimensions");
  }

  if (intData.verbose) {
    std::cout << "[Directional::integrate] full energy precompute"
              << " time=" << iterativeTimings.fullEnergyPrecompute
              << " s rows=" << fullEnergy.rows()
              << " cols=" << fullEnergy.cols()
              << " nnz=" << fullEnergy.nonZeros() << '\n';
  }

  SparseMatrix<double> var2AllMat;
  VectorXd fullx(numVars);
  fullx.setZero();

  /*
   * Track every reduced variable that has actually been fixed by the
   * iterative mixed-integer solve. The previous fixed-count for-loop could
   * terminate immediately after fixing the last variable, without performing
   * the final continuous re-solve that incorporates that last integer value.
   *
   * This loop instead follows the required sequence:
   *
   *   solve current reduced system
   *   -> if all requested variables are fixed, finish
   *   -> choose one unresolved integer variable
   *   -> fix it to its nearest integer
   *   -> solve again
   */
  std::vector<unsigned char> integerVariableWasFixed(
      static_cast<std::size_t>(numVars), static_cast<unsigned char>(0));

  for (int i = 0; i < numVars; ++i) {
    if (alreadyFixed(i)) {
      integerVariableWasFixed[static_cast<std::size_t>(i)] = 1;
    }
  }

  const auto count_requested_fixed_variables = [&]() -> int {
    int count = 0;
    for (int i = 0; i < numVars; ++i) {
      if (fixedMask(i)) {
        ++count;
      }
    }
    return count;
  };

  const auto count_completed_fixed_variables = [&]() -> int {
    int count = 0;
    for (int i = 0; i < numVars; ++i) {
      if (fixedMask(i) && alreadyFixed(i)) {
        ++count;
      }
    }
    return count;
  };

  int solveIteration = 0;
  const int maximumSolveIterations = numVars + 2;

  /*
   * Conservative batched rounding:
   *
   * - Always fix the single closest unresolved integer variable.
   * - Fix up to three additional variables only when their residual is both
   *   absolutely small and close to the best residual in this solve.
   *
   * This reduces expensive sparse factorizations while avoiding aggressive
   * rounding of ambiguous variables.
   */
  constexpr int maximumRoundingBatchSize = 8;
  constexpr double maximumAdditionalBatchResidual = 0.12;
  constexpr double relativeBatchResidualFactor = 1.5;
  constexpr double minimumRelativeBatchWindow = 1.0e-12;

  std::size_t totalVariablesFixedByBatching = 0;
  int maximumObservedBatchSize = 0;
  std::array<std::size_t, maximumRoundingBatchSize + 1>
      roundingBatchHistogram{};

  while (true) {
    if (solveIteration >= maximumSolveIterations) {
      if (intData.verbose) {
        std::cerr << "[Directional::integrate] exceeded the maximum number of "
                     "mixed-integer solve iterations ("
                  << maximumSolveIterations << ")\n";
      }
      return false;
    }

    const int requestedFixedCount = count_requested_fixed_variables();
    const int completedFixedCount = count_completed_fixed_variables();

    if (intData.verbose) {
      std::cout << "[Directional::integrate] rounding solve: "
                << (solveIteration + 1) << " (fixed " << completedFixedCount
                << "/" << requestedFixedCount << " requested variables)"
                << std::endl;
    }

    const int freeVariableCount = numVars - alreadyFixed.sum();
    if (freeVariableCount < 0) {
      throw std::runtime_error(
          "integrate(): alreadyFixed contains more entries than numVars");
    }

    const auto freeVariableMapStart = Clock::now();

    // Map the current free variables into the complete reduced vector.
    var2AllMat.resize(numVars, freeVariableCount);

    std::vector<int> freeToFull(static_cast<std::size_t>(freeVariableCount),
                                -1);

    std::vector<int> fullToFree(static_cast<std::size_t>(numVars), -1);

    int varCounter = 0;

    vector<Triplet<double>> var2AllTriplets;
    var2AllTriplets.reserve(static_cast<std::size_t>(freeVariableCount));

    for (int i = 0; i < numVars; ++i) {
      if (alreadyFixed(i)) {
        continue;
      }

      freeToFull[static_cast<std::size_t>(varCounter)] = i;

      fullToFree[static_cast<std::size_t>(i)] = varCounter;

      var2AllTriplets.emplace_back(i, varCounter, 1.0);

      ++varCounter;
    }

    if (varCounter != freeVariableCount) {
      throw std::runtime_error(
          "integrate(): free-variable map size is inconsistent");
    }

    var2AllMat.setFromTriplets(var2AllTriplets.begin(), var2AllTriplets.end());

    iterativeTimings.freeVariableMap += seconds_since(freeVariableMapStart);

    iterativeTimings.maximumFreeVariables =
        std::max(iterativeTimings.maximumFreeVariables,
                 static_cast<Eigen::Index>(freeVariableCount));

    const auto reducedOperatorStart = Clock::now();

    /*
     * Extract H_ff directly from the precomputed full energy matrix.
     * fullEnergy is column-major, so each free full column can be scanned
     * once and retained rows are translated through fullToFree.
     */
    std::vector<Triplet<double>> reducedEnergyTriplets;
    reducedEnergyTriplets.reserve(static_cast<std::size_t>(
        std::max<Eigen::Index>(freeVariableCount, fullEnergy.nonZeros())));

    for (int freeColumn = 0; freeColumn < freeVariableCount; ++freeColumn) {
      const int fullColumn = freeToFull[static_cast<std::size_t>(freeColumn)];

      for (SparseMatrix<double>::InnerIterator entry(fullEnergy, fullColumn);
           entry; ++entry) {
        const int fullRow = static_cast<int>(entry.row());

        const int freeRow = fullToFree[static_cast<std::size_t>(fullRow)];

        if (freeRow < 0) {
          continue;
        }

        reducedEnergyTriplets.emplace_back(freeRow, freeColumn, entry.value());
      }
    }

    SparseMatrix<double> EtE(freeVariableCount, freeVariableCount);

    EtE.setFromTriplets(reducedEnergyTriplets.begin(),
                        reducedEnergyTriplets.end());

    EtE.makeCompressed();

    /*
     * Cpart is only a column selection from Cfull. Build it directly
     * rather than multiplying by the selector matrix.
     */
    std::vector<Triplet<double>> reducedConstraintTriplets;
    reducedConstraintTriplets.reserve(
        static_cast<std::size_t>(Cfull.nonZeros()));

    for (int freeColumn = 0; freeColumn < freeVariableCount; ++freeColumn) {
      const int fullColumn = freeToFull[static_cast<std::size_t>(freeColumn)];

      for (SparseMatrix<double>::InnerIterator entry(Cfull, fullColumn); entry;
           ++entry) {
        reducedConstraintTriplets.emplace_back(entry.row(), freeColumn,
                                               entry.value());
      }
    }

    SparseMatrix<double> Cpart(Cfull.rows(), freeVariableCount);

    Cpart.setFromTriplets(reducedConstraintTriplets.begin(),
                          reducedConstraintTriplets.end());

    Cpart.makeCompressed();

    iterativeTimings.reducedOperatorExtraction +=
        seconds_since(reducedOperatorStart);

    const auto constraintReductionStart = Clock::now();

    // Reduce the rank of the current constraint matrix.
    int CpartRank = 0;
    VectorXi PIndices(0);
    if (Cpart.rows() != 0) {
      qrsolver.compute(Cpart.transpose());
      CpartRank = qrsolver.rank();
      PIndices = qrsolver.colsPermutation().indices();

      vector<Triplet<double>> CPartTriplets;
      for (int k = 0; k < Cpart.outerSize(); ++k) {
        for (SparseMatrix<double>::InnerIterator it(Cpart, k); it; ++it) {
          for (int j = 0; j < CpartRank; ++j) {
            if (it.row() == PIndices(j)) {
              CPartTriplets.emplace_back(j, it.col(), it.value());
            }
          }
        }
      }

      Cpart.resize(CpartRank, Cpart.cols());
      Cpart.setFromTriplets(CPartTriplets.begin(), CPartTriplets.end());
    }

    iterativeTimings.constraintRankReduction +=
        seconds_since(constraintReductionStart);

    iterativeTimings.maximumConstraintRows =
        std::max(iterativeTimings.maximumConstraintRows,
                 static_cast<Eigen::Index>(Cpart.rows()));

    const auto kktAssemblyStart = Clock::now();

    SparseMatrix<double> A(EtE.rows() + Cpart.rows(),
                           EtE.rows() + Cpart.rows());

    vector<Triplet<double>> ATriplets;
    for (int k = 0; k < EtE.outerSize(); ++k) {
      for (SparseMatrix<double>::InnerIterator it(EtE, k); it; ++it) {
        ATriplets.emplace_back(it.row(), it.col(), it.value());
      }
    }

    for (int k = 0; k < Cpart.outerSize(); ++k) {
      for (SparseMatrix<double>::InnerIterator it(Cpart, k); it; ++it) {
        ATriplets.emplace_back(it.row() + EtE.rows(), it.col(), it.value());
        ATriplets.emplace_back(it.col(), it.row() + EtE.rows(), it.value());
      }
    }

    A.setFromTriplets(ATriplets.begin(), ATriplets.end());

    iterativeTimings.kktMatrixAssembly += seconds_since(kktAssemblyStart);

    iterativeTimings.maximumSystemRows =
        std::max(iterativeTimings.maximumSystemRows, A.rows());

    iterativeTimings.maximumSystemNonZeros =
        std::max(iterativeTimings.maximumSystemNonZeros, A.nonZeros());

    const auto rhsAssemblyStart = Clock::now();

    VectorXd b = VectorXd::Zero(EtE.rows() + Cpart.rows());

    const VectorXd fullFixedContribution = fullEnergy * fixedValues;

    for (int freeIndex = 0; freeIndex < freeVariableCount; ++freeIndex) {
      const int fullIndex = freeToFull[static_cast<std::size_t>(freeIndex)];

      b(freeIndex) =
          fullEnergyRhs(fullIndex) - fullFixedContribution(fullIndex);
    }

    VectorXd bfull = -Cfull * fixedValues;
    VectorXd bpart(CpartRank);
    for (int k = 0; k < CpartRank; ++k) {
      bpart(k) = bfull(PIndices(k));
    }
    b.segment(EtE.rows(), Cpart.rows()) = bpart;

    iterativeTimings.rhsAssembly += seconds_since(rhsAssemblyStart);

#ifdef USE_SUITESPARSE_ENABLED
    /*
     * Native UMFPACK path.
     *
     * Eigen's UmfPackLU wrapper does not expose UMFPACK's strategy,
     * ordering, scaling, or factorization statistics. The KKT matrix is
     * structurally symmetric but numerically indefinite, so retain UMFPACK's
     * robust LU factorization while requesting the configured strategy and
     * ordering. When DIRECTIONAL_SUITESPARSE_HAS_METIS is defined, the default
     * ordering request is UMFPACK_ORDERING_METIS; otherwise it remains AMD.
     */
    A.makeCompressed();

    if (A.rows() != A.cols()) {
      throw std::runtime_error(
          "integrate(): UMFPACK system matrix must be square");
    }

    if (A.rows() > static_cast<Eigen::Index>(std::numeric_limits<int>::max())) {
      throw std::runtime_error(
          "integrate(): UMFPACK di interface cannot represent matrix size");
    }

    static_assert(
        std::is_same_v<typename SparseMatrix<double>::StorageIndex, int>,
        "Native umfpack_di_* calls require Eigen sparse indices to be int");

    std::array<double, UMFPACK_CONTROL> umfpackControl{};
    std::array<double, UMFPACK_INFO> umfpackInfo{};

    umfpack_di_defaults(umfpackControl.data());

    umfpackControl[UMFPACK_PRL] = intData.verbose ? 1.0 : 0.0;

    /*
     * These must be assigned before umfpack_di_symbolic().
     * The symbolic phase performs the ordering; changing ORDERING after
     * symbolic analysis has no effect on the selected ordering.
     */
    umfpackControl[UMFPACK_STRATEGY] = DIRECTIONAL_UMFPACK_STRATEGY;

    umfpackControl[UMFPACK_ORDERING] = DIRECTIONAL_UMFPACK_ORDERING;

    umfpackControl[UMFPACK_SCALE] = DIRECTIONAL_UMFPACK_SCALE;

    /*
     * Retain iterative refinement. It is inexpensive relative to the
     * factorization and provides additional robustness for indefinite KKT
     * systems.
     */
    umfpackControl[UMFPACK_IRSTEP] = 2.0;

    void *umfpackSymbolic = nullptr;
    void *umfpackNumeric = nullptr;

    const int systemSize = static_cast<int>(A.rows());

    const int *columnPointers = A.outerIndexPtr();

    const int *rowIndices = A.innerIndexPtr();

    const double *values = A.valuePtr();

    const auto symbolicAnalysisStart = Clock::now();

    const int requestedUmfpackOrdering =
        static_cast<int>(umfpackControl[UMFPACK_ORDERING]);

    const int requestedUmfpackStrategy =
        static_cast<int>(umfpackControl[UMFPACK_STRATEGY]);

    int symbolicStatus = umfpack_di_symbolic(
        systemSize, systemSize, columnPointers, rowIndices, values,
        &umfpackSymbolic, umfpackControl.data(), umfpackInfo.data());

    int usedUmfpackOrdering =
        static_cast<int>(umfpackInfo[UMFPACK_ORDERING_USED]);

    int usedUmfpackStrategy =
        static_cast<int>(umfpackInfo[UMFPACK_STRATEGY_USED]);

    if (intData.verbose) {
      std::cout << "[Directional::integrate] UMFPACK ordering"
                << " requested=" << requestedUmfpackOrdering
                << " used=" << usedUmfpackOrdering
                << " requestedStrategy=" << requestedUmfpackStrategy
                << " usedStrategy=" << usedUmfpackStrategy
                << " status=" << symbolicStatus
                << '\n';
    }

    /*
     * If METIS fails during symbolic analysis, retry the same system with AMD.
     * This preserves the existing robust behavior while proving whether the
     * current UMFPACK binary can actually execute METIS ordering.
     */
    if (requestedUmfpackOrdering == UMFPACK_ORDERING_METIS &&
        (symbolicStatus != UMFPACK_OK || umfpackSymbolic == nullptr)) {
      if (umfpackSymbolic != nullptr) {
        umfpack_di_free_symbolic(&umfpackSymbolic);
      }

      if (intData.verbose) {
        std::cerr
            << "[Directional::integrate] WARNING: "
            << "UMFPACK METIS symbolic analysis failed at rounding solve "
            << (solveIteration + 1)
            << " with status " << symbolicStatus
            << "; retrying with UMFPACK_ORDERING_AMD\n";
      }

      umfpackControl[UMFPACK_ORDERING] = UMFPACK_ORDERING_AMD;

      std::fill(
          umfpackInfo.begin(),
          umfpackInfo.end(),
          0.0);

      symbolicStatus = umfpack_di_symbolic(
          systemSize, systemSize, columnPointers, rowIndices, values,
          &umfpackSymbolic, umfpackControl.data(), umfpackInfo.data());

      usedUmfpackOrdering =
          static_cast<int>(umfpackInfo[UMFPACK_ORDERING_USED]);

      usedUmfpackStrategy =
          static_cast<int>(umfpackInfo[UMFPACK_STRATEGY_USED]);

      if (intData.verbose) {
        std::cout << "[Directional::integrate] UMFPACK ordering retry"
                  << " requested=" << UMFPACK_ORDERING_AMD
                  << " used=" << usedUmfpackOrdering
                  << " requestedStrategy=" << requestedUmfpackStrategy
                  << " usedStrategy=" << usedUmfpackStrategy
                  << " status=" << symbolicStatus
                  << '\n';
      }
    }

    if (requestedUmfpackOrdering == UMFPACK_ORDERING_METIS &&
        symbolicStatus == UMFPACK_OK &&
        usedUmfpackOrdering != UMFPACK_ORDERING_METIS) {
      std::cerr << "[Directional::integrate] WARNING: "
                << "METIS ordering was requested before symbolic analysis, "
                << "but UMFPACK used ordering " << usedUmfpackOrdering
                << ". This UMFPACK build likely lacks usable METIS support, "
                << "or UMFPACK rejected METIS for this matrix.\n";
    }

    iterativeTimings.symbolicAnalysis += seconds_since(symbolicAnalysisStart);

    if (symbolicStatus != UMFPACK_OK || umfpackSymbolic == nullptr) {
      ++iterativeTimings.factorizationFailures;

      if (umfpackSymbolic != nullptr) {
        umfpack_di_free_symbolic(&umfpackSymbolic);
      }

      if (intData.verbose) {
        std::cerr
            << "[Directional::integrate] UMFPACK symbolic analysis failed at "
            << "rounding solve " << (solveIteration + 1) << " with status "
            << symbolicStatus << '\n';
      }

      return false;
    }

    const auto numericFactorizationStart = Clock::now();

    const int numericStatus = umfpack_di_numeric(
        columnPointers, rowIndices, values, umfpackSymbolic, &umfpackNumeric,
        umfpackControl.data(), umfpackInfo.data());

    iterativeTimings.numericFactorization +=
        seconds_since(numericFactorizationStart);

    /*
     * Numeric no longer needs Symbolic after construction.
     */
    umfpack_di_free_symbolic(&umfpackSymbolic);

    if (numericStatus != UMFPACK_OK || umfpackNumeric == nullptr) {
      ++iterativeTimings.factorizationFailures;

      if (umfpackNumeric != nullptr) {
        umfpack_di_free_numeric(&umfpackNumeric);
      }

      if (intData.verbose) {
        std::cerr << "[Directional::integrate] UMFPACK numeric factorization "
                  << "failed at rounding solve " << (solveIteration + 1)
                  << " with status " << numericStatus << '\n';
      }

      return false;
    }

    iterativeTimings.umfpackTotalFlops += umfpackInfo[UMFPACK_FLOPS];

    iterativeTimings.umfpackMaximumLNonzeros = std::max(
        iterativeTimings.umfpackMaximumLNonzeros, umfpackInfo[UMFPACK_LNZ]);

    iterativeTimings.umfpackMaximumUNonzeros = std::max(
        iterativeTimings.umfpackMaximumUNonzeros, umfpackInfo[UMFPACK_UNZ]);

    iterativeTimings.umfpackMaximumPeakMemory =
        std::max(iterativeTimings.umfpackMaximumPeakMemory,
                 umfpackInfo[UMFPACK_PEAK_MEMORY]);

    const auto backSubstitutionStart = Clock::now();

    x.resize(systemSize);

    const int solveStatus = umfpack_di_solve(
        UMFPACK_A, columnPointers, rowIndices, values, x.data(), b.data(),
        umfpackNumeric, umfpackControl.data(), umfpackInfo.data());

    iterativeTimings.backSubstitution += seconds_since(backSubstitutionStart);

    umfpack_di_free_numeric(&umfpackNumeric);

    if (solveStatus != UMFPACK_OK) {
      ++iterativeTimings.solveFailures;

      if (intData.verbose) {
        std::cerr
            << "[Directional::integrate] UMFPACK solve failed at rounding "
            << "solve " << (solveIteration + 1) << " with status "
            << solveStatus << '\n';
      }

      return false;
    }
#else
    SparseLU<SparseMatrix<double>> lusolver;

    const auto symbolicAnalysisStart = Clock::now();

    lusolver.analyzePattern(A);

    iterativeTimings.symbolicAnalysis += seconds_since(symbolicAnalysisStart);

    if (lusolver.info() != Success) {
      ++iterativeTimings.factorizationFailures;

      if (intData.verbose) {
        std::cout << "[Directional::integrate] symbolic analysis failed at "
                  << "rounding solve " << (solveIteration + 1) << std::endl;
      }

      return false;
    }

    const auto numericFactorizationStart = Clock::now();

    lusolver.factorize(A);

    iterativeTimings.numericFactorization +=
        seconds_since(numericFactorizationStart);

    if (lusolver.info() != Success) {
      ++iterativeTimings.factorizationFailures;

      if (intData.verbose) {
        std::cout << "[Directional::integrate] numeric factorization failed at "
                  << "rounding solve " << (solveIteration + 1) << std::endl;
      }

      return false;
    }

    const auto backSubstitutionStart = Clock::now();

    x = lusolver.solve(b);

    iterativeTimings.backSubstitution += seconds_since(backSubstitutionStart);

    if (lusolver.info() != Success) {
      ++iterativeTimings.solveFailures;

      if (intData.verbose) {
        std::cout
            << "[Directional::integrate] LU solve failed at rounding solve "
            << (solveIteration + 1) << std::endl;
      }

      return false;
    }
#endif

    if (x.size() < freeVariableCount) {
      throw std::runtime_error(
          "integrate(): reduced solution is smaller than the free-variable "
          "count");
    }

    const auto reconstructionStart = Clock::now();

    fullx = var2AllMat * x.head(freeVariableCount) + fixedValues;

    iterativeTimings.fullSolutionReconstruction +=
        seconds_since(reconstructionStart);

    ++iterativeTimings.iterations;

    if (intData.verbose) {
      std::cout << "[Directional::integrate] solved reduced system iteration "
                << (solveIteration + 1) << " with size A=" << A.rows() << "x"
                << A.cols() << ", constraints=" << Cpart.rows() << std::endl;

      if (solveIteration == 0 || ((solveIteration + 1) % 25) == 0) {
        std::cout << "[Directional::integrate] iteration timing checkpoint"
                  << " iteration=" << (solveIteration + 1)
                  << " freeVars=" << freeVariableCount << " rows=" << A.rows()
                  << " nnz=" << A.nonZeros()
                  << " cumulativeSymbolic=" << iterativeTimings.symbolicAnalysis
                  << " cumulativeNumeric="
                  << iterativeTimings.numericFactorization
                  << " cumulativeSolve=" << iterativeTimings.backSubstitution
                  << '\n';
      }
    }

    ++solveIteration;

    /*
     * If every currently requested variable was already fixed before this
     * solve, fullx is now the required final continuous solution under all
     * integer constraints.
     */
    if (count_completed_fixed_variables() ==
        count_requested_fixed_variables()) {
      if ((!intData.roundSeams) && (!roundedSingularities) &&
          intData.integralSeamless) {
        /*
         * Singularities were rounded first. Now request all seam variables
         * and continue; the next solve will include them as they are fixed.
         */
        for (int i = 0; i < intData.integerVars.size(); ++i) {
          for (int j = 0; j < intData.n; ++j) {
            const int index = intData.n * intData.integerVars(i) + j;
            if (index < 0 || index >= numVars) {
              throw std::runtime_error(
                  "integrate(): expanded seam integer index is out of range");
            }
            fixedMask(index) = 1;
          }
        }
        roundedSingularities = true;

        if (count_completed_fixed_variables() !=
            count_requested_fixed_variables()) {
          continue;
        }
      }

      break;
    }

    const auto candidateSelectionStart = Clock::now();

    struct IntegerCandidate {
      int index = -1;
      double value = 0.0;
      double roundedValue = 0.0;
      double residual = std::numeric_limits<double>::infinity();
    };

    std::vector<IntegerCandidate> candidates;
    candidates.reserve(static_cast<std::size_t>(
        std::max(0, requestedFixedCount - completedFixedCount)));

    for (int i = 0; i < numVars; ++i) {
      if (!fixedMask(i) || alreadyFixed(i)) {
        continue;
      }

      const double value = fullx(i);

      if (!std::isfinite(value)) {
        throw std::runtime_error(
            "integrate(): unresolved integer candidate is non-finite");
      }

      const double roundedValue = std::round(value);

      candidates.push_back(IntegerCandidate{i, value, roundedValue,
                                            std::abs(value - roundedValue)});
    }

    std::sort(candidates.begin(), candidates.end(),
              [](const IntegerCandidate &lhs, const IntegerCandidate &rhs) {
                if (lhs.residual != rhs.residual) {
                  return lhs.residual < rhs.residual;
                }

                return lhs.index < rhs.index;
              });

    iterativeTimings.integerCandidateSelection +=
        seconds_since(candidateSelectionStart);

    if (candidates.empty()) {
      if (intData.verbose) {
        std::cerr << "[Directional::integrate] no unresolved requested integer "
                     "variable could be selected\n";
      }

      return false;
    }

    const double bestResidual = candidates.front().residual;

    // const double additionalResidualLimit =
    //     std::min(
    //         maximumAdditionalBatchResidual,
    //         std::max(
    //             minimumRelativeBatchWindow,
    //             relativeBatchResidualFactor * bestResidual));
    const double additionalResidualLimit = std::min(0.10, bestResidual + 0.025);

    int batchSize = 0;

    for (const IntegerCandidate &candidate : candidates) {
      if (batchSize >= maximumRoundingBatchSize) {
        break;
      }

      /*
       * Always accept the best candidate. Additional candidates must be
       * confidently close to an integer and near the best residual.
       */
      if (batchSize > 0 && candidate.residual > additionalResidualLimit) {
        break;
      }

      alreadyFixed(candidate.index) = 1;
      fixedValues(candidate.index) = candidate.roundedValue;

      integerVariableWasFixed[static_cast<std::size_t>(candidate.index)] = 1;

      ++batchSize;

      if (intData.verbose) {
        std::cout << "[Directional::integrate] fixed integer variable "
                  << candidate.index << " from " << candidate.value << " to "
                  << candidate.roundedValue << " (residual "
                  << candidate.residual << ", batch position " << batchSize
                  << "/" << maximumRoundingBatchSize << ")" << std::endl;
      }
    }

    if (batchSize <= 0) {
      throw std::runtime_error(
          "integrate(): candidate selection produced an empty rounding batch");
    }

    if (batchSize > maximumRoundingBatchSize) {
      throw std::runtime_error(
          "integrate(): rounding batch exceeded configured maximum");
    }

    ++roundingBatchHistogram[static_cast<std::size_t>(batchSize)];

    totalVariablesFixedByBatching += static_cast<std::size_t>(batchSize);

    maximumObservedBatchSize = std::max(maximumObservedBatchSize, batchSize);
  }

  if (intData.verbose) {
    std::cout << "[Directional::integrate] batched rounding summary\n"
              << "  total variables fixed:          "
              << totalVariablesFixedByBatching << '\n'
              << "  maximum observed batch size:    "
              << maximumObservedBatchSize << '\n'
              << "  configured maximum batch size:  "
              << maximumRoundingBatchSize << '\n'
              << "  additional residual cap:        "
              << maximumAdditionalBatchResidual << '\n'
              << "  relative residual factor:       "
              << relativeBatchResidualFactor << '\n'
              << "  batch-size histogram:\n";

    for (int size = 1; size <= maximumRoundingBatchSize; ++size) {
      std::cout << "    size " << size << ": "
                << roundingBatchHistogram[static_cast<std::size_t>(size)]
                << '\n';
    }
  }

  // Validate the reduced integer variables that integration actually owns.
  std::size_t unresolvedReducedIntegerCount = 0;
  std::size_t neverFixedReducedIntegerCount = 0;
  double maximumReducedIntegerResidual = 0.0;
  int maximumReducedIntegerResidualIndex = -1;

  for (int i = 0; i < intData.integerVars.size(); ++i) {
    for (int j = 0; j < intData.n; ++j) {
      const int variableIndex = intData.n * intData.integerVars(i) + j;
      if (variableIndex < 0 || variableIndex >= numVars) {
        throw std::runtime_error(
            "integrate(): final expanded integer-variable index is out of "
            "range");
      }

      const double value = fullx(variableIndex);
      const double nearestInteger = std::round(value);
      const double residual = std::abs(value - nearestInteger);

      if (residual > 1.0e-8) {
        ++unresolvedReducedIntegerCount;
        if (intData.verbose && unresolvedReducedIntegerCount <= 30) {
          std::cerr << "[Directional::integrate] unresolved reduced integer "
                    << "variable=" << variableIndex << " value=" << value
                    << " nearestInteger=" << nearestInteger
                    << " residual=" << residual << '\n';
        }
      }

      if (!integerVariableWasFixed[static_cast<std::size_t>(variableIndex)] &&
          !alreadyFixed(variableIndex)) {
        ++neverFixedReducedIntegerCount;
        if (intData.verbose && neverFixedReducedIntegerCount <= 30) {
          std::cerr << "[Directional::integrate] reduced integer variable was "
                    << "never fixed: " << variableIndex
                    << " finalValue=" << value << '\n';
        }
      }

      if (residual > maximumReducedIntegerResidual) {
        maximumReducedIntegerResidual = residual;
        maximumReducedIntegerResidualIndex = variableIndex;
      }
    }
  }

  if (intData.verbose) {
    std::cout << "[Directional::integrate] final reduced integer validation\n"
              << "  solve iterations: " << solveIteration << '\n'
              << "  expanded reduced integer count: "
              << intData.integerVars.size() * intData.n << '\n'
              << "  unresolved count: " << unresolvedReducedIntegerCount << '\n'
              << "  never-fixed count: " << neverFixedReducedIntegerCount
              << '\n'
              << "  maximum residual: " << maximumReducedIntegerResidual << '\n'
              << "  maximum residual variable: "
              << maximumReducedIntegerResidualIndex << std::endl;
  }

  if (unresolvedReducedIntegerCount != 0) {
    if (intData.verbose) {
      std::cerr << "[Directional::integrate] final reduced solution still "
                   "contains unresolved integer variables\n";
    }
    return false;
  }

  print_iterative_timing_summary();
  log_phase("Iterative seamless solve");

  // the results are packets of N functions for each vertex, and need to be
  // allocated for corners
  const auto firstFunctionExpansionStart = Clock::now();

  VectorXd NFunctionVec = intData.vertexTrans2CutMat * intData.linRedMat *
                          intData.singIntSpanMat * intData.intSpanMat * fullx;

  if (intData.verbose) {
    std::cout << "[Directional::integrate] first function expansion: "
              << seconds_since(firstFunctionExpansionStart) << " s\n";
  }

  const auto firstVertexCopyStart = Clock::now();
  NFunction.resize(meshCut.V.rows(), intData.N);
  for (int i = 0; i < NFunction.rows(); i++)
    NFunction.row(i)
        << NFunctionVec.segment(intData.N * i, intData.N).transpose();

  if (intData.verbose) {
    std::cout << "[Directional::integrate] first vertex-function copy: "
              << seconds_since(firstVertexCopyStart) << " s\n";
  }

  // nFunction = fullx;

  // allocating per corner
  const auto firstCornerAllocationStart = Clock::now();

  NCornerFunctions.resize(meshWhole.F.rows(), intData.N * 3);
  for (int i = 0; i < meshWhole.F.rows(); i++)
    for (int j = 0; j < 3; j++)
      NCornerFunctions.block(i, intData.N * j, 1, intData.N) =
          NFunction.row(meshCut.F(i, j));

  if (intData.verbose) {
    std::cout << "[Directional::integrate] first corner allocation detail: "
              << seconds_since(firstCornerAllocationStart) << " s\n";
  }

  log_phase("Corner allocation pass 1");

  SparseMatrix<double> G;
  // MatrixXd FN;
  // igl::per_face_normals(cutV, meshCut, FN);
  const auto branchedGradientStart = Clock::now();

  branched_gradient(meshCut, intData.N, G);

  if (intData.verbose) {
    std::cout << "[Directional::integrate] branched_gradient detail: "
              << seconds_since(branchedGradientStart) << " s, rows=" << G.rows()
              << ", cols=" << G.cols() << ", nnz=" << G.nonZeros() << '\n';
  }
  log_phase("branched_gradient");
  // cout<<"cutF.rows(): "<<cutF.rows()<<endl;
  SparseMatrix<double> Gd = G * intData.vertexTrans2CutMat * intData.linRedMat *
                            intData.singIntSpanMat * intData.intSpanMat;
  SparseMatrix<double> x2CornerMat =
      intData.vertexTrans2CutMat * intData.linRedMat * intData.singIntSpanMat *
      intData.intSpanMat;
  // igl::matlab::MatlabWorkspace mw;
  VectorXi integerIndices(intData.integerVars.size() * intData.n);
  for (int i = 0; i < intData.integerVars.size(); i++)
    for (int j = 0; j < intData.n; j++)
      integerIndices(intData.n * i + j) =
          intData.n * intData.integerVars(i) + j;

  // bool success=directional::iterative_rounding(Efull, field.extField,
  // intData.fixedIndices, intData.fixedValues, intData.singularIndices,
  // integerIndices, intData.lengthRatio, gamma, Cfull, Gd, meshCut.faceNormals,
  // intData.N, intData.n, meshCut.V, meshCut.F, x2CornerMat,
  // intData.integralSeamless, intData.roundSeams, intData.localInjectivity,
  // intData.verbose, fullx);
  bool success = true;

  // if ((!success)&&(intData.verbose))
  //     cout<<"Rounding has failed!"<<endl;

  // the results are packets of N functions for each vertex, and need to be
  // allocated for corners
  const auto finalFunctionExpansionStart = Clock::now();

  NFunctionVec = intData.vertexTrans2CutMat * intData.linRedMat *
                 intData.singIntSpanMat * intData.intSpanMat * fullx;

  if (intData.verbose) {
    std::cout << "[Directional::integrate] final function expansion: "
              << seconds_since(finalFunctionExpansionStart) << " s\n";
  }

  const auto finalVertexCopyStart = Clock::now();

  NFunction.resize(meshCut.V.rows(), intData.N);
  for (int i = 0; i < NFunction.rows(); i++)
    NFunction.row(i)
        << NFunctionVec.segment(intData.N * i, intData.N).transpose();

  if (intData.verbose) {
    std::cout << "[Directional::integrate] final vertex-function copy: "
              << seconds_since(finalVertexCopyStart) << " s\n";
  }

  intData.nVertexFunction = fullx;

  // nFunction = fullx;

  // cout<<"paramFuncsd: "<<paramFuncsd<<endl;

  // allocating per corner
  const auto finalCornerAllocationStart = Clock::now();

  NCornerFunctions.resize(meshWhole.F.rows(), intData.N * 3);
  for (int i = 0; i < meshWhole.F.rows(); i++)
    for (int j = 0; j < 3; j++)
      NCornerFunctions.block(i, intData.N * j, 1, intData.N) =
          NFunction.row(meshCut.F(i, j)).array();

  if (intData.verbose) {
    std::cout << "[Directional::integrate] final corner allocation detail: "
              << seconds_since(finalCornerAllocationStart) << " s\n";
  }

  log_phase("Final corner allocation");

  return success;
}

} // namespace directional

#endif