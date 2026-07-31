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
#include <Eigen/Geometry>

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
#if defined(DIRECTIONAL_IS_ORDER_PRESERVING_IMPLEMENTATION)
void is_order_preserving(const Eigen::MatrixXd &vertices,
                                const Eigen::MatrixXi &faces,
                                const Eigen::MatrixXd &rawField,
                                Eigen::VectorXi &isOrderPreserving,
                                Eigen::MatrixXd &products) {
  Eigen::MatrixXd normals(faces.rows(), 3);
  for (Eigen::Index face = 0; face < faces.rows(); ++face) {
    const Eigen::RowVector3d edge0 =
        vertices.row(faces(face, 1)) - vertices.row(faces(face, 0));
    const Eigen::RowVector3d edge1 =
        vertices.row(faces(face, 2)) - vertices.row(faces(face, 0));
    normals.row(face) = edge0.cross(edge1).normalized();
  }

  const int degree = static_cast<int>(rawField.cols() / 3);
  products.resize(rawField.rows(), degree);
  isOrderPreserving = Eigen::VectorXi::Ones(rawField.rows());

  for (Eigen::Index face = 0; face < rawField.rows(); ++face) {
    for (int direction = 0; direction < degree; ++direction) {
      const Eigen::RowVector3d first =
          rawField.block<1, 3>(face, 3 * direction);
      const Eigen::RowVector3d second =
          rawField.block<1, 3>(face, 3 * ((direction + 1) % degree));
      products(face, direction) = normals.row(face).dot(first.cross(second));
      if (products(face, direction) <= 0.0) {
        isOrderPreserving(face) = 0;
      }
    }
  }
}
#else
void is_order_preserving(const Eigen::MatrixXd &vertices,
                                const Eigen::MatrixXi &faces,
                                const Eigen::MatrixXd &rawField,
                                Eigen::VectorXi &isOrderPreserving,
                                Eigen::MatrixXd &products);
#endif

} // namespace directional

#endif
