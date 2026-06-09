// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2021 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_INTEGRATE_H
#define DIRECTIONAL_INTEGRATE_H

#include <Eigen/Core>
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
#include <chrono>
#include <vector>

#ifdef USE_SUITESPARSE_ENABLED
#include <Eigen/UmfPackSupport>
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
        std::chrono::duration_cast<std::chrono::microseconds>(now - integrateStart)
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

  while (true) {
    if (solveIteration >= maximumSolveIterations) {
      if (intData.verbose) {
        std::cerr
            << "[Directional::integrate] exceeded the maximum number of "
               "mixed-integer solve iterations ("
            << maximumSolveIterations << ")\n";
      }
      return false;
    }

    const int requestedFixedCount = count_requested_fixed_variables();
    const int completedFixedCount = count_completed_fixed_variables();

    if (intData.verbose) {
      std::cout << "[Directional::integrate] rounding solve: "
                << (solveIteration + 1) << " (fixed "
                << completedFixedCount << "/" << requestedFixedCount
                << " requested variables)" << std::endl;
    }

    const int freeVariableCount = numVars - alreadyFixed.sum();
    if (freeVariableCount < 0) {
      throw std::runtime_error(
          "integrate(): alreadyFixed contains more entries than numVars");
    }

    // Map the current free variables into the complete reduced vector.
    var2AllMat.resize(numVars, freeVariableCount);
    int varCounter = 0;
    vector<Triplet<double>> var2AllTriplets;
    var2AllTriplets.reserve(static_cast<std::size_t>(freeVariableCount));

    for (int i = 0; i < numVars; ++i) {
      if (!alreadyFixed(i)) {
        var2AllTriplets.emplace_back(i, varCounter++, 1.0);
      }
    }

    if (varCounter != freeVariableCount) {
      throw std::runtime_error(
          "integrate(): free-variable map size is inconsistent");
    }

    var2AllMat.setFromTriplets(var2AllTriplets.begin(),
                               var2AllTriplets.end());

    SparseMatrix<double> Epart = Efull * var2AllMat;
    VectorXd torhs = -Efull * fixedValues;
    SparseMatrix<double> EtE = Epart.transpose() * M1 * Epart;
    SparseMatrix<double> Cpart = Cfull * var2AllMat;

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

    VectorXd b = VectorXd::Zero(EtE.rows() + Cpart.rows());
    b.segment(0, EtE.rows()) =
        Epart.transpose() * M1 * (gamma + torhs);

    VectorXd bfull = -Cfull * fixedValues;
    VectorXd bpart(CpartRank);
    for (int k = 0; k < CpartRank; ++k) {
      bpart(k) = bfull(PIndices(k));
    }
    b.segment(EtE.rows(), Cpart.rows()) = bpart;

#ifdef USE_SUITESPARSE_ENABLED
    UmfPackLU<SparseMatrix<double>> lusolver;
#else
    SparseLU<SparseMatrix<double>> lusolver;
#endif

    lusolver.compute(A);
    if (lusolver.info() != Success) {
      if (intData.verbose) {
        std::cout << "[Directional::integrate] LU decomposition failed at "
                  << "rounding solve " << (solveIteration + 1) << std::endl;
      }
      return false;
    }

    x = lusolver.solve(b);
    if (lusolver.info() != Success) {
      if (intData.verbose) {
        std::cout << "[Directional::integrate] LU solve failed at rounding "
                  << "solve " << (solveIteration + 1) << std::endl;
      }
      return false;
    }

    if (x.size() < freeVariableCount) {
      throw std::runtime_error(
          "integrate(): reduced solution is smaller than the free-variable "
          "count");
    }

    fullx = var2AllMat * x.head(freeVariableCount) + fixedValues;

    if (intData.verbose) {
      std::cout << "[Directional::integrate] solved reduced system iteration "
                << (solveIteration + 1) << " with size A=" << A.rows() << "x"
                << A.cols() << ", constraints=" << Cpart.rows()
                << std::endl;
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

    double minIntDiff = std::numeric_limits<double>::max();
    int minIntDiffIndex = -1;

    for (int i = 0; i < numVars; ++i) {
      if (fixedMask(i) && !alreadyFixed(i)) {
        const double value = fullx(i);
        const double currentDifference =
            std::abs(value - std::round(value));

        if (currentDifference < minIntDiff) {
          minIntDiff = currentDifference;
          minIntDiffIndex = i;
        }
      }
    }

    if (minIntDiffIndex < 0) {
      if (intData.verbose) {
        std::cerr
            << "[Directional::integrate] no unresolved requested integer "
               "variable could be selected\n";
      }
      return false;
    }

    const double preRoundValue = fullx(minIntDiffIndex);
    const double roundedValue = std::round(preRoundValue);

    alreadyFixed(minIntDiffIndex) = 1;
    fixedValues(minIntDiffIndex) = roundedValue;
    integerVariableWasFixed[static_cast<std::size_t>(minIntDiffIndex)] = 1;

    if (intData.verbose) {
      std::cout << "[Directional::integrate] fixed integer variable "
                << minIntDiffIndex << " from " << preRoundValue << " to "
                << roundedValue << " (residual " << minIntDiff << ")"
                << std::endl;
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
                    << "never fixed: " << variableIndex << " finalValue="
                    << value << '\n';
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
              << "  unresolved count: " << unresolvedReducedIntegerCount
              << '\n'
              << "  never-fixed count: " << neverFixedReducedIntegerCount
              << '\n'
              << "  maximum residual: " << maximumReducedIntegerResidual
              << '\n'
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
  log_phase("Iterative seamless solve");

  // the results are packets of N functions for each vertex, and need to be
  // allocated for corners
  VectorXd NFunctionVec = intData.vertexTrans2CutMat * intData.linRedMat *
                          intData.singIntSpanMat * intData.intSpanMat * fullx;
  NFunction.resize(meshCut.V.rows(), intData.N);
  for (int i = 0; i < NFunction.rows(); i++)
    NFunction.row(i)
        << NFunctionVec.segment(intData.N * i, intData.N).transpose();

  // nFunction = fullx;

  // allocating per corner
  NCornerFunctions.resize(meshWhole.F.rows(), intData.N * 3);
  for (int i = 0; i < meshWhole.F.rows(); i++)
    for (int j = 0; j < 3; j++)
      NCornerFunctions.block(i, intData.N * j, 1, intData.N) =
          NFunction.row(meshCut.F(i, j));
  log_phase("Corner allocation pass 1");

  SparseMatrix<double> G;
  // MatrixXd FN;
  // igl::per_face_normals(cutV, meshCut, FN);
  branched_gradient(meshCut, intData.N, G);
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
  NFunctionVec = intData.vertexTrans2CutMat * intData.linRedMat *
                 intData.singIntSpanMat * intData.intSpanMat * fullx;
  NFunction.resize(meshCut.V.rows(), intData.N);
  for (int i = 0; i < NFunction.rows(); i++)
    NFunction.row(i)
        << NFunctionVec.segment(intData.N * i, intData.N).transpose();

  intData.nVertexFunction = fullx;

  // nFunction = fullx;

  // cout<<"paramFuncsd: "<<paramFuncsd<<endl;

  // allocating per corner
  NCornerFunctions.resize(meshWhole.F.rows(), intData.N * 3);
  for (int i = 0; i < meshWhole.F.rows(); i++)
    for (int j = 0; j < 3; j++)
      NCornerFunctions.block(i, intData.N * j, 1, intData.N) =
          NFunction.row(meshCut.F(i, j)).array();
  log_phase("Final corner allocation");

  return success;
}

} // namespace directional

#endif