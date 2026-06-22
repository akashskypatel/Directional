// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_BARYCENTRIC_COORDINATES_H
#define DIRECTIONAL_GEOMETRY_BARYCENTRIC_COORDINATES_H

#include <limits>
#include <stdexcept>

#include <Eigen/Core>

/**
 * @file BarycentricCoordinates.h
 * @brief Row-wise barycentric coordinates for points in three-dimensional triangles.
 */

namespace directional {

/**
 * @brief Computes barycentric coordinates for corresponding point/triangle rows.
 *
 * Each row of @p points is evaluated against the triangle formed by the same
 * row in @p corner0, @p corner1, and @p corner2. The output columns contain
 * the weights for those three corners in the same order.
 *
 * @param points Query points as an N-by-3 matrix.
 * @param corner0 First triangle corners as an N-by-3 matrix.
 * @param corner1 Second triangle corners as an N-by-3 matrix.
 * @param corner2 Third triangle corners as an N-by-3 matrix.
 * @param coordinates Output N-by-3 barycentric-coordinate matrix.
 * @throws std::invalid_argument if the input dimensions do not match.
 *
 * Degenerate triangles produce quiet NaN coordinates.
 */
inline void barycentric_coordinates(const Eigen::MatrixXd &points,
                                    const Eigen::MatrixXd &corner0,
                                    const Eigen::MatrixXd &corner1,
                                    const Eigen::MatrixXd &corner2,
                                    Eigen::MatrixXd &coordinates) {
  const Eigen::Index rowCount = points.rows();
  const bool dimensionsMatch =
      points.cols() == 3 && corner0.rows() == rowCount &&
      corner1.rows() == rowCount && corner2.rows() == rowCount &&
      corner0.cols() == 3 && corner1.cols() == 3 && corner2.cols() == 3;
  if (!dimensionsMatch) {
    throw std::invalid_argument(
        "barycentric_coordinates expects matching N-by-3 matrices");
  }

  coordinates.resize(rowCount, 3);
  const double nan = std::numeric_limits<double>::quiet_NaN();

  for (Eigen::Index row = 0; row < rowCount; ++row) {
    const Eigen::RowVector3d edge0 = corner1.row(row) - corner0.row(row);
    const Eigen::RowVector3d edge1 = corner2.row(row) - corner0.row(row);
    const Eigen::RowVector3d offset = points.row(row) - corner0.row(row);

    const double dot00 = edge0.dot(edge0);
    const double dot01 = edge0.dot(edge1);
    const double dot11 = edge1.dot(edge1);
    const double dot20 = offset.dot(edge0);
    const double dot21 = offset.dot(edge1);
    const double denominator = dot00 * dot11 - dot01 * dot01;

    if (denominator == 0.0) {
      coordinates.row(row).setConstant(nan);
      continue;
    }

    const double weight1 = (dot11 * dot20 - dot01 * dot21) / denominator;
    const double weight2 = (dot00 * dot21 - dot01 * dot20) / denominator;
    coordinates(row, 0) = 1.0 - weight1 - weight2;
    coordinates(row, 1) = weight1;
    coordinates(row, 2) = weight2;
  }
}

} // namespace directional

#endif
