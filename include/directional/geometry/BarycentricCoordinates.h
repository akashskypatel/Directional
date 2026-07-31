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
void barycentric_coordinates(const Eigen::MatrixXd &points,
                                    const Eigen::MatrixXd &corner0,
                                    const Eigen::MatrixXd &corner1,
                                    const Eigen::MatrixXd &corner2,
                                    Eigen::MatrixXd &coordinates);

} // namespace directional

#endif
