// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_FIELD_MATCHING_H
#define DIRECTIONAL_FIELDS_FIELD_MATCHING_H

#include <cmath>
#include <numbers>
#include <vector>

#include <Eigen/Core>

#include <directional/core/CartesianField.h>


/**
 * @file FieldMatching.h
 * @brief Matching and singularity utilities for N-direction fields.
 *
 * Computes edge-wise rotational matching, transport effort, and singularity indices for fields defined on tangent bundles.
 */

namespace directional {
/**
 * @brief Converts transported field effort into integer cycle indices.
 * @param basisCycles Oriented cycle-edge incidence matrix over interior adjacencies.
 * @param effort Transport effort per interior adjacency, expressed as summed rotations.
 * @param cycleCurvature Curvature associated with each measured cycle.
 * @param N Field degree.
 * @param indices Output cycle indices multiplied by @p N.
 * @throws std::runtime_error if numerical values are not close to integers.
 */
inline void effort_to_indices(const Eigen::SparseMatrix<double> &basisCycles,
                              const Eigen::VectorXd &effort,
                              const Eigen::VectorXd &cycleCurvature,
                              const int N, Eigen::VectorXi &indices) {
  using namespace std;
  Eigen::VectorXd dIndices =
      ((basisCycles * effort + (double)N * cycleCurvature).array() /
       (2.0 * std::numbers::pi)); // this should already be an integer up to
                                  // numerical precision

  indices.conservativeResize(dIndices.size());
  for (int i = 0; i < indices.size(); i++) {
    if (fabs(std::round(dIndices(i)) - dIndices(i)) >= 1e-6) {
      throw std::runtime_error("Indices are not naturally integer!");
    }
    indices(i) = static_cast<int>(std::round(dIndices(i)));
  }
}

/**
 * @brief Computes singularity cycle ids and indices in-place for a field.
 * @param field Cartesian field with populated matching effort and tangent-bundle cycles.
 */
inline void effort_to_indices(directional::CartesianField &field) {
  Eigen::VectorXd effortInner(field.tb->innerAdjacencies.size());
  for (int i = 0; i < field.tb->innerAdjacencies.size(); i++)
    effortInner(i) = field.effort(field.tb->innerAdjacencies(i));
  Eigen::VectorXi fullIndices;
  directional::effort_to_indices(field.tb->cycles, effortInner,
                                 field.tb->cycleCurvatures, field.N,
                                 fullIndices);

  Eigen::VectorXi indices(field.tb->local2Cycle.size());
  for (int i = 0; i < field.tb->local2Cycle.size(); i++)
    indices(i) = fullIndices(field.tb->local2Cycle(i));

  std::vector<int> singCyclesList;
  std::vector<int> singIndicesList;
  for (int i = 0; i < field.tb->local2Cycle.size(); i++)
    if (indices(i) != 0) {
      singCyclesList.push_back(i);
      singIndicesList.push_back(indices(i));
    }

  Eigen::VectorXi singCycles(singCyclesList.size());
  Eigen::VectorXi singIndices(singIndicesList.size());
  for (int i = 0; i < singCyclesList.size(); i++) {
    singCycles(i) = singCyclesList[i];
    singIndices(i) = singIndicesList[i];
  }
  field.set_singularities(singCycles, singIndices);
}
/**
 * @brief Computes principal rotational matching and transport effort for a raw field.
 * @param field Raw Cartesian field to update with matching, effort, and optionally singularities.
 * @param isSingularities When true, derives singularity indices after matching.
 *
 * The raw directions in each tangent space must be ordered counter-clockwise;
 * otherwise the rotational offsets are not meaningful.
 */
inline void principal_matching(directional::CartesianField &field,
                               const bool isSingularities = true) {

  typedef std::complex<double> Complex;
  using namespace Eigen;
  using namespace std;

  field.matching.conservativeResize(field.tb->adjSpaces.rows());
  field.matching.setConstant(-1);

  field.effort = VectorXd::Zero(field.tb->adjSpaces.rows());
  for (int i = 0; i < field.tb->adjSpaces.rows(); i++) {
    if (field.tb->adjSpaces(i, 0) == -1 || field.tb->adjSpaces(i, 1) == -1)
      continue;

    double minRotAngle = 10000.0;
    int indexMinFromZero = 0;

    // computing some effort and the extracting principal one
    Complex freeCoeff(1.0, 0.0);
    // finding where the 0 vector in EF(i,0) goes to with smallest rotation
    // angle in EF(i,1), computing the effort, and then adjusting the matching
    // to have principal effort.
    RowVector2d vec0f =
        field.intField.block(field.tb->adjSpaces(i, 0), 0, 1, 2);
    Complex vec0fc = Complex(vec0f(0), vec0f(1));
    Complex transvec0fc = vec0fc * field.tb->connection(i);
    for (int j = 0; j < field.N; j++) {
      RowVector2d vecjf =
          field.intField.block(field.tb->adjSpaces(i, 0), 2 * j, 1, 2);
      Complex vecjfc = Complex(vecjf(0), vecjf(1));
      RowVector2d vecjg =
          field.intField.block(field.tb->adjSpaces(i, 1), 2 * j, 1, 2);
      Complex vecjgc = Complex(vecjg(0), vecjg(1));
      Complex transvecjfc = vecjfc * field.tb->connection(i);
      freeCoeff *= (vecjgc / transvecjfc);
      double currRotAngle = arg(vecjgc / transvec0fc);
      if (abs(currRotAngle) < abs(minRotAngle)) {
        indexMinFromZero = j;
        minRotAngle = currRotAngle;
      }

      // taking principal effort
    }
    field.effort(i) = arg(freeCoeff);

    // finding the matching that implements effort(i)
    // This is still not perfect
    double currEffort = 0;
    for (int j = 0; j < field.N; j++) {
      RowVector2d vecjf =
          field.intField.block(field.tb->adjSpaces(i, 0), 2 * j, 1, 2);
      Complex vecjfc = Complex(vecjf(0), vecjf(1));
      RowVector2d vecjg = field.intField.block(
          field.tb->adjSpaces(i, 1),
          2 * ((j + indexMinFromZero + field.N) % field.N), 1, 2);
      Complex vecjgc = Complex(vecjg(0), vecjg(1));
      Complex transvecjfc = vecjfc * field.tb->connection(i);
      currEffort += arg(vecjgc / transvecjfc);
    }

    field.matching(i) = static_cast<int>(
        indexMinFromZero -
        std::round((currEffort - field.effort(i)) / (2.0 * std::numbers::pi)));
  }

  // Getting final singularities and their indices
  if (isSingularities)
    effort_to_indices(field);
}
} // namespace directional

#endif // DIRECTIONAL_FIELDS_FIELD_MATCHING_H
