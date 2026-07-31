// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_MESH_COMPONENTS_H
#define DIRECTIONAL_GEOMETRY_MESH_COMPONENTS_H

#include <algorithm>
#include <map>
#include <numeric>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>

namespace directional::geometry {

struct FaceComponent {
  std::vector<int> originalFaces;
  std::vector<int> originalVertices;
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd rawField;

  [[nodiscard]] int minimum_original_face() const {
    return originalFaces.empty()
               ? -1
               : *std::min_element(originalFaces.begin(), originalFaces.end());
  }
};

std::vector<std::vector<int>>
face_connected_components(const Eigen::MatrixXi &faces);

FaceComponent compact_face_component(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &componentFaces,
    const Eigen::MatrixXd *rawField = nullptr);

std::vector<FaceComponent>
compact_face_components(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd *rawField = nullptr);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_MESH_COMPONENTS_H
