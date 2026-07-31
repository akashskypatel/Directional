// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2021 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_UTIL_IS_ORDER_PRESERVING_H
#define DIRECTIONAL_UTIL_IS_ORDER_PRESERVING_H

#include <Eigen/Core>

/**
 * @file IsOrderPreserving.h
 * @brief Tests whether per-face directional vectors retain counter-clockwise order.
 */

namespace directional {

/**
 * @brief Evaluates the orientation of consecutive vectors in each face.
 * @param vertices Mesh vertex positions.
 * @param faces Triangle vertex indices.
 * @param rawField Per-face vectors stacked in groups of three columns.
 * @param isOrderPreserving Output flag per face; one when every consecutive pair
 *        has positive orientation around the face normal.
 * @param products Output signed cross products for every face and vector pair.
 */
void is_order_preserving(const Eigen::MatrixXd &vertices,
                         const Eigen::MatrixXi &faces,
                         const Eigen::MatrixXd &rawField,
                         Eigen::VectorXi &isOrderPreserving,
                         Eigen::MatrixXd &products);

} // namespace directional

#endif
