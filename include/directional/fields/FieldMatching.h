
#pragma once

#ifndef DIRECTIONAL_FIELDS_FIELD_MATCHING_H
#define DIRECTIONAL_FIELDS_FIELD_MATCHING_H

#include <Eigen/Core>
#include <cmath>
#include <directional/core/TangentBundle.h>
#include <directional/fields/FieldMatching.h>
#include <numbers>
#include <vector>

namespace directional {

/// @brief Takes a field in raw form and computes both the principal effort and
/// the consequent principal matching on every edge
/// @note Important: if the Raw field in not CCW ordered, the result is
/// meaningless
///       The input and output are both a RAW_FIELD type cartesian field, in
///       which the matching, effort, and singularities are set.
/// @param field The field to compute the matching for
/// @param isSingularities Whether to compute singularities
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

    field.matching(i) =
        indexMinFromZero -
        round((currEffort - field.effort(i)) / (2.0 * std::numbers::pi));
  }

  // Getting final singularities and their indices
  if (isSingularities)
    effort_to_indices(field);
}
// Computes cycle-based indices from adjaced-space efforts of a directional
// field. Note: input is effort (sum of rotation angles), and not individual
// rotation angles Input:
//  basisCycles:    #c by #iE (inner edges of the mesh) the oriented basis
//  cycles around which the indices are measured effort:         #iE the effort
//  (sum of rotation angles) of matched vectors across the dual edge. Equal to
//  N*rotation angles for N-RoSy fields. cycleCurvature: #c the cycle curvature
//  (for instance, from directional::dual_cycles) N:              The degree of
//  the field
// Output:
//  indices:     #c the index of the cycle x N (always an integer).
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
    assert(fabs(std::round(dIndices(i)) - dIndices(i)) < 1e-6 &&
           "Indices are not naturally integer!");
    indices(i) = std::round(dIndices(i));
  }
}

// version that accepts a cartesian field object and operates on it as input and
// output.
inline void effort_to_indices(directional::CartesianField &field) {
  // field.effort = Eigen::VectorXd::Zero(field.adjSpaces.rows());
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
} // namespace directional

#endif // DIRECTIONAL_FIELDS_FIELD_MATCHING_H
