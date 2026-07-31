// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_CROSS_FIELD_H
#define DIRECTIONAL_FIELDS_CROSS_FIELD_H

#include <vector>

#include <Eigen/Core>

#include <directional/core/Export.h>
#include <directional/util/Progress.h>

namespace directional {

class CartesianField;
class TriMesh;

namespace fields {

/// Number of ordered directions in a cross field.
inline constexpr int kCrossFieldDegree = 4;

/** @brief Options controlling mesh-only cross-field extraction. */
struct CrossFieldOptions {
  /// Normalize every extracted direction to unit length.
  bool normalizeDirections = true;

  /// Reorder the four branches so branch indices are locally coherent.
  bool combDirections = true;

  /// Return edge matching, transport effort, and singularity diagnostics.
  bool computeMatching = true;

  /// Optional progress callback invoked by extraction stages.
  ProgressCallback progress;
};

/** @brief Source-edge-keyed transition metadata for a finalized field. */
struct CrossFieldEdgeTransition {
  int sourceEdge = -1;
  int sourceVertex0 = -1;
  int sourceVertex1 = -1;
  int firstFace = -1;
  int secondFace = -1;
  int matching = 0;
  double effort = 0.0;
};

/** @brief Extracted face-based degree-4 cross field and diagnostics. */
struct CrossFieldResult {
  int degree = kCrossFieldDegree;
  Eigen::MatrixXd rawField;
  Eigen::MatrixXd primaryDirections;
  Eigen::MatrixXd secondaryDirections;
  Eigen::VectorXi matching;
  Eigen::VectorXd effort;
  std::vector<CrossFieldEdgeTransition> edgeTransitions;
  Eigen::VectorXi singularCycles;
  Eigen::VectorXi singularIndices;
  Eigen::VectorXd confidence;
  Eigen::VectorXi uncoveredFaces;
  bool matchingComputed = false;
  bool singularitiesComputed = false;
  bool confidenceComputed = false;
  bool uncoveredFacePolicyApplied = false;
};

/** @brief Populates source-edge transition records from a Cartesian field. */
DIRECTIONAL_API void
populate_cross_field_edge_transitions(const CartesianField &field,
                                      CrossFieldResult &result);

/** @brief Finalizes matching, optional combing, and output diagnostics. */
DIRECTIONAL_API CrossFieldResult
finalize_cross_field_result(CartesianField &rawField, bool combDirections,
                            bool includeDiagnostics);

/** @brief Projects an ambient vector onto a face tangent plane. */
DIRECTIONAL_API Eigen::RowVector3d
project_tangent(const Eigen::RowVector3d &vector,
                const Eigen::RowVector3d &normal, bool normalize);

/** @brief Builds an ordered raw 4-RoSy field from two tangent families. */
DIRECTIONAL_API Eigen::MatrixXd
make_raw_cross_field(const TriMesh &mesh,
                     const Eigen::MatrixXd &primaryDirections,
                     const Eigen::MatrixXd &secondaryDirections,
                     bool normalizeDirections = true);

/** @brief Derives a second cross-field direction from face normals. */
DIRECTIONAL_API Eigen::MatrixXd
orthogonal_complement(const TriMesh &mesh,
                      const Eigen::MatrixXd &primaryDirections,
                      bool normalizeDirections = true);

/** @brief Computes a smooth face-based 4-RoSy cross field from a mesh. */
DIRECTIONAL_API CrossFieldResult
extract_cross_field(const TriMesh &mesh,
                    const CrossFieldOptions &options = {});

/** @brief Computes a smooth cross field from raw mesh arrays. */
DIRECTIONAL_API CrossFieldResult
extract_cross_field(const Eigen::MatrixXd &vertices,
                    const Eigen::MatrixXi &faces,
                    const CrossFieldOptions &options = {});

} // namespace fields
} // namespace directional

#endif // DIRECTIONAL_FIELDS_CROSS_FIELD_H
