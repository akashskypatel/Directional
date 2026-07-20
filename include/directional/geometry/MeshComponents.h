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

inline std::vector<std::vector<int>>
face_connected_components(const Eigen::MatrixXi &faces) {
  if (faces.cols() != 3) {
    throw std::runtime_error("face_connected_components expects triangle faces.");
  }

  std::map<int, std::vector<int>> incidentFacesByVertex;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      incidentFacesByVertex[faces(face, corner)].push_back(face);
    }
  }

  std::vector<unsigned char> visited(static_cast<std::size_t>(faces.rows()), 0);
  std::vector<std::vector<int>> components;
  for (int seed = 0; seed < faces.rows(); ++seed) {
    if (visited[static_cast<std::size_t>(seed)] != 0) {
      continue;
    }
    std::vector<int> component;
    std::vector<int> stack{seed};
    visited[static_cast<std::size_t>(seed)] = 1;
    while (!stack.empty()) {
      const int face = stack.back();
      stack.pop_back();
      component.push_back(face);
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = faces(face, corner);
        for (const int adjacent : incidentFacesByVertex[vertex]) {
          if (visited[static_cast<std::size_t>(adjacent)] == 0) {
            visited[static_cast<std::size_t>(adjacent)] = 1;
            stack.push_back(adjacent);
          }
        }
      }
    }
    std::sort(component.begin(), component.end());
    components.push_back(std::move(component));
  }

  std::sort(components.begin(), components.end(),
            [](const std::vector<int> &lhs, const std::vector<int> &rhs) {
              return lhs.front() < rhs.front();
            });
  return components;
}

inline FaceComponent compact_face_component(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &componentFaces,
    const Eigen::MatrixXd *rawField = nullptr) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::runtime_error("compact_face_component expects 3D triangles.");
  }
  if (rawField != nullptr &&
      (rawField->rows() != faces.rows() || rawField->cols() != 12)) {
    throw std::runtime_error(
        "component raw field must have shape (#faces, 12).");
  }

  FaceComponent component;
  component.originalFaces = componentFaces;
  std::sort(component.originalFaces.begin(), component.originalFaces.end());

  std::map<int, int> localVertexByOriginal;
  for (const int originalFace : component.originalFaces) {
    if (originalFace < 0 || originalFace >= faces.rows()) {
      throw std::runtime_error("component face index is out of range.");
    }
    for (int corner = 0; corner < 3; ++corner) {
      const int originalVertex = faces(originalFace, corner);
      if (localVertexByOriginal.count(originalVertex) == 0) {
        const int localVertex =
            static_cast<int>(localVertexByOriginal.size());
        localVertexByOriginal[originalVertex] = localVertex;
        component.originalVertices.push_back(originalVertex);
      }
    }
  }

  component.vertices.resize(
      static_cast<Eigen::Index>(component.originalVertices.size()), 3);
  for (std::size_t local = 0; local < component.originalVertices.size();
       ++local) {
    component.vertices.row(static_cast<Eigen::Index>(local)) =
        vertices.row(component.originalVertices[local]);
  }

  component.faces.resize(static_cast<Eigen::Index>(component.originalFaces.size()),
                         3);
  if (rawField != nullptr) {
    component.rawField.resize(
        static_cast<Eigen::Index>(component.originalFaces.size()), 12);
  }
  for (std::size_t localFace = 0; localFace < component.originalFaces.size();
       ++localFace) {
    const int originalFace = component.originalFaces[localFace];
    for (int corner = 0; corner < 3; ++corner) {
      component.faces(static_cast<Eigen::Index>(localFace), corner) =
          localVertexByOriginal.at(faces(originalFace, corner));
    }
    if (rawField != nullptr) {
      component.rawField.row(static_cast<Eigen::Index>(localFace)) =
          rawField->row(originalFace);
    }
  }

  return component;
}

inline std::vector<FaceComponent>
compact_face_components(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd *rawField = nullptr) {
  std::vector<FaceComponent> result;
  for (const std::vector<int> &faceComponent :
       face_connected_components(faces)) {
    result.push_back(
        compact_face_component(vertices, faces, faceComponent, rawField));
  }
  return result;
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_MESH_COMPONENTS_H
