#pragma once

#ifndef DIRECTIONAL_FIELDS_FIELD_COMBING_H
#define DIRECTIONAL_FIELDS_FIELD_COMBING_H

#include <Eigen/Core>
#include <cmath>
#include <directional/core/CartesianField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/util/GraphUtils.h>
#include <queue>
#include <vector>


namespace directional {

/// @brief Reorders the vectors in a tangent space (preserving CCW direction) so
/// that the prescribed matching across most TB edges is an identity, except for
/// seams.
/// @note Important: if the Raw field in not CCW ordered, the result is
/// unpredictable.
/// @param rawField a RAW_FIELD uncombed cartesian field object
/// @param combedField the combed field object, also RAW_FIELD
/// @param _spaceIsCut Optionally prescribing the TB edges (corresponding to
/// mesh faces) that must be a seam
inline void combing(const directional::CartesianField &rawField,
                    directional::CartesianField &combedField,
                    const Eigen::MatrixXi &_spaceIsCut = Eigen::MatrixXi()) {
  using namespace Eigen;
  combedField.init(*(rawField.tb), fieldTypeEnum::RAW_FIELD, rawField.N);
  Eigen::MatrixXi spaceIsCut(rawField.intField.rows(), 3);
  if (_spaceIsCut.rows() == 0)
    spaceIsCut.setZero();
  else
    spaceIsCut = _spaceIsCut;

  VectorXi spaceTurns(rawField.intField.rows());

  // flood-filling through the matching to comb field

  // dual tree to find combing routes
  VectorXi visitedSpaces = VectorXi::Constant(rawField.intField.rows(), 1, 0);
  std::queue<std::pair<int, int>> spaceMatchingQueue;
  spaceMatchingQueue.push(std::pair<int, int>(0, 0));
  MatrixXd combedIntField(combedField.intField.rows(),
                          combedField.intField.cols());
  do {
    std::pair<int, int> currSpaceMatching = spaceMatchingQueue.front();
    spaceMatchingQueue.pop();
    if (visitedSpaces(currSpaceMatching.first))
      continue;
    visitedSpaces(currSpaceMatching.first) = 1;

    // combing field to start from the matching index
    combedIntField.block(currSpaceMatching.first, 0, 1,
                         2 * (rawField.N - currSpaceMatching.second)) =
        rawField.intField.block(currSpaceMatching.first,
                                2 * currSpaceMatching.second, 1,
                                2 * (rawField.N - currSpaceMatching.second));
    combedIntField.block(currSpaceMatching.first,
                         2 * (rawField.N - currSpaceMatching.second), 1,
                         2 * currSpaceMatching.second) =
        rawField.intField.block(currSpaceMatching.first, 0, 1,
                                2 * currSpaceMatching.second);

    spaceTurns(currSpaceMatching.first) = currSpaceMatching.second;

    for (int i = 0; i < 3; i++) {
      int nextMatching =
          (rawField.matching(rawField.tb->oneRing(currSpaceMatching.first, i)));
      int nextFace =
          (rawField.tb->adjSpaces(
               rawField.tb->oneRing(currSpaceMatching.first, i), 0) ==
                   currSpaceMatching.first
               ? rawField.tb->adjSpaces(
                     rawField.tb->oneRing(currSpaceMatching.first, i), 1)
               : rawField.tb->adjSpaces(
                     rawField.tb->oneRing(currSpaceMatching.first, i), 0));
      nextMatching *= (rawField.tb->adjSpaces(
                           rawField.tb->oneRing(currSpaceMatching.first, i),
                           0) == currSpaceMatching.first
                           ? 1.0
                           : -1.0);
      nextMatching =
          (nextMatching + currSpaceMatching.second + 1000 * rawField.N) %
          rawField.N; // killing negatives
      assert("combing(): NextMatching is out of bounds! " &&
             (nextMatching >= 0 && nextMatching < rawField.N));
      if ((nextFace != -1) && (!visitedSpaces(nextFace)) &&
          (!spaceIsCut(currSpaceMatching.first, i)))
        spaceMatchingQueue.push(std::pair<int, int>(nextFace, nextMatching));
    }

  } while (!spaceMatchingQueue.empty());

  combedField.set_intrinsic_field(combedIntField);
  combedField.matching.resize(rawField.tb->adjSpaces.rows());
  // Combed matching
  for (int i = 0; i < rawField.tb->adjSpaces.rows(); i++) {
    if ((rawField.tb->adjSpaces(i, 0) == -1) ||
        (rawField.tb->adjSpaces(i, 1) == -1))
      combedField.matching(i) = -1;
    else
      combedField.matching(i) = (spaceTurns(rawField.tb->adjSpaces(i, 0)) -
                                 spaceTurns(rawField.tb->adjSpaces(i, 1)) +
                                 rawField.matching(i) + 1000 * rawField.N) %
                                rawField.N;
  }

  // TODO: only update effort.
  principal_matching(combedField);
}

} // namespace directional

#endif // DIRECTIONAL_FIELDS_FIELD_COMBING_H
