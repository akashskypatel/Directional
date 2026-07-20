// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_CROSS_FIELD_TRANSFER_H
#define DIRECTIONAL_FIELDS_CROSS_FIELD_TRANSFER_H

#include <limits>
#include <stdexcept>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>

namespace directional {
namespace fields {

class CrossFieldTransfer {
public:
  [[nodiscard]] static Eigen::MatrixXd
  transfer_raw_field_nearest_face(const TriMesh &sourceMesh,
                                  const Eigen::MatrixXd &sourceRawField,
                                  const TriMesh &targetMesh,
                                  const bool normalizeDirections = true) {
    if (sourceRawField.rows() != sourceMesh.F.rows() ||
        sourceRawField.cols() != 12) {
      throw std::runtime_error(
          "sourceRawField must have shape (#sourceFaces, 12).");
    }
    Eigen::MatrixXd transferred(targetMesh.F.rows(), 12);
    for (int targetFace = 0; targetFace < targetMesh.F.rows(); ++targetFace) {
      const int sourceFace = nearest_source_face(
          sourceMesh, target_face_centroid(targetMesh, targetFace));
      Eigen::RowVector3d primary =
          sourceRawField.block(sourceFace, 0, 1, 3);
      Eigen::RowVector3d secondary =
          sourceRawField.block(sourceFace, 3, 1, 3);
      primary = project_tangent(primary, targetMesh.faceNormals.row(targetFace),
                                normalizeDirections);
      const Eigen::RowVector3d normal = targetMesh.faceNormals.row(targetFace);
      secondary = secondary - secondary.dot(normal) * normal;
      secondary = secondary - secondary.dot(primary) * primary;
      if (secondary.norm() <= 1.0e-12) {
        secondary = cross3(normal, primary);
      }
      if (secondary.norm() <= 1.0e-12) {
        throw std::runtime_error(
            "Cross-field transfer produced a degenerate secondary axis.");
      }
      if (normalizeDirections) {
        secondary.normalize();
      }
      transferred.block(targetFace, 0, 1, 3) = primary;
      transferred.block(targetFace, 3, 1, 3) = secondary;
      transferred.block(targetFace, 6, 1, 3) = -primary;
      transferred.block(targetFace, 9, 1, 3) = -secondary;
    }
    return transferred;
  }

private:
  [[nodiscard]] static Eigen::RowVector3d
  target_face_centroid(const TriMesh &mesh, const int face) {
    return (mesh.V.row(mesh.F(face, 0)) + mesh.V.row(mesh.F(face, 1)) +
            mesh.V.row(mesh.F(face, 2))) /
           3.0;
  }

  [[nodiscard]] static Eigen::RowVector3d
  cross3(const Eigen::RowVector3d &a, const Eigen::RowVector3d &b) {
    return Eigen::RowVector3d(a.y() * b.z() - a.z() * b.y(),
                              a.z() * b.x() - a.x() * b.z(),
                              a.x() * b.y() - a.y() * b.x());
  }

  [[nodiscard]] static int nearest_source_face(
      const TriMesh &sourceMesh, const Eigen::RowVector3d &point) {
    int bestFace = 0;
    double bestSquaredDistance = std::numeric_limits<double>::infinity();
    for (int face = 0; face < sourceMesh.F.rows(); ++face) {
      const Eigen::RowVector3d centroid = target_face_centroid(sourceMesh, face);
      const double squaredDistance = (centroid - point).squaredNorm();
      if (squaredDistance < bestSquaredDistance) {
        bestSquaredDistance = squaredDistance;
        bestFace = face;
      }
    }
    return bestFace;
  }
};

} // namespace fields
} // namespace directional

#endif // DIRECTIONAL_FIELDS_CROSS_FIELD_TRANSFER_H
