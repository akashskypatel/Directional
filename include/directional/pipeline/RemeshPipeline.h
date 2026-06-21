// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
#define DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H

#include <chrono>
#include <cmath>
#include <iostream>
#include <stdexcept>


#include <Eigen/Core>

#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/FieldMatching.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/integration/Integrate.h>
#include <directional/integration/IntegrationData.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/meshing/Mesher.h>
#include <directional/meshing/MesherData.h>
#include <directional/meshing/SetupMesher.h>



/**
 * @file RemeshPipeline.h
 * @brief High-level remeshing pipeline API.
 *
 * Exposes convenience functions that convert mesh vertices, faces, and cross-field directions into a remeshed output by running tangent-bundle construction, matching, combing, integration, and meshing.
 */

namespace directional::pipeline {

/**
 * @brief User-tunable parameters for the high-level remeshing pipeline.
 */
struct RemeshOptions {
  /// Target edge-length ratio passed to integration/meshing.
  double lengthRatio = 0.02;

  /// Whether integration should enforce integral seamlessness.
  bool integralSeamless = true;

  /// Whether seam values should be rounded during integration.
  bool roundSeams = false;

  /// Reserved for future feature-aligned pipeline support.
  bool featureAlign = false;

  /// Emits per-stage timing logs when true.
  bool verbose = false;

  /// Normalizes supplied direction vectors after tangent projection.
  bool normalizeDirections = true;
};

/**
 * @brief Geometry and diagnostic outputs produced by the remeshing pipeline.
 */
struct RemeshResult {
  /// True when the final mesher emitted a valid output mesh.
  bool success = false;

  /// Generated output vertex positions.
  Eigen::MatrixXd vertices;

  /// Degree/valence metadata for generated vertices.
  Eigen::VectorXi degrees;

  /// Generated output faces.
  Eigen::MatrixXi faces;

  /// Vertices of the cut source mesh used for integration.
  Eigen::MatrixXd cutVertices;

  /// Faces of the cut source mesh used for integration.
  Eigen::MatrixXi cutFaces;

  /// Integrated N-function values on the cut mesh.
  Eigen::MatrixXd cutFunctions;

  /// Integrated N-function values at cut-mesh corners.
  Eigen::MatrixXd cutCornerFunctions;
};

/**
 * @brief Projects a vector onto a face tangent plane.
 * @param vector Ambient vector to project.
 * @param normal Unit face normal.
 * @param normalize Whether to return a unit-length tangent vector.
 * @return Tangent-plane component of @p vector.
 * @throws std::runtime_error if the projected vector is degenerate.
 */
inline Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &vector,
                                          const Eigen::RowVector3d &normal,
                                          const bool normalize) {
  Eigen::RowVector3d tangent = vector - vector.dot(normal) * normal;
  const double norm = tangent.norm();
  if (norm <= 1e-12) {
    throw std::runtime_error(
        "Directional pipeline received a degenerate tangent direction.");
  }
  if (normalize) {
    tangent /= norm;
  }
  return tangent;
}

/**
 * @brief Builds an ordered raw 4-RoSy field from two tangent direction families.
 * @param mesh Source mesh with face normals already computed.
 * @param primaryDirections One ambient direction per face.
 * @param secondaryDirections Orthogonal or user-specified second direction per face.
 * @param normalizeDirections Whether tangent-projected directions are normalized.
 * @return #F-by-12 raw field ordered as +primary, +secondary, -primary, -secondary.
 */
inline Eigen::MatrixXd
make_raw_cross_field(const TriMesh &mesh,
                     const Eigen::MatrixXd &primaryDirections,
                     const Eigen::MatrixXd &secondaryDirections,
                     const bool normalizeDirections) {
  if (primaryDirections.rows() != mesh.F.rows() ||
      primaryDirections.cols() != 3) {
    throw std::runtime_error("primaryDirections must have shape (#F, 3).");
  }
  if (secondaryDirections.rows() != mesh.F.rows() ||
      secondaryDirections.cols() != 3) {
    throw std::runtime_error("secondaryDirections must have shape (#F, 3).");
  }

  Eigen::MatrixXd rawField(mesh.F.rows(), 12);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d pd1 = project_tangent(primaryDirections.row(face),
                                                   normal, normalizeDirections);
    const Eigen::RowVector3d pd2 = project_tangent(
        secondaryDirections.row(face), normal, normalizeDirections);

    rawField.block(face, 0, 1, 3) = pd1;
    rawField.block(face, 3, 1, 3) = pd2;
    rawField.block(face, 6, 1, 3) = -pd1;
    rawField.block(face, 9, 1, 3) = -pd2;
  }
  return rawField;
}

/**
 * @brief Derives a second cross-field direction by crossing face normals with primary directions.
 * @param mesh Source mesh with face normals already computed.
 * @param primaryDirections One ambient direction per face.
 * @param normalizeDirections Whether projected directions are normalized.
 * @return #F-by-3 matrix of secondary tangent directions.
 */
inline Eigen::MatrixXd
orthogonal_complement(const TriMesh &mesh,
                      const Eigen::MatrixXd &primaryDirections,
                      const bool normalizeDirections) {
  if (primaryDirections.rows() != mesh.F.rows() ||
      primaryDirections.cols() != 3) {
    throw std::runtime_error("primaryDirections must have shape (#F, 3).");
  }

  Eigen::MatrixXd secondary(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d pd1 = project_tangent(primaryDirections.row(face),
                                                   normal, normalizeDirections);
    Eigen::RowVector3d pd2 = normal.cross(pd1);
    if (normalizeDirections) {
      pd2.normalize();
    }
    secondary.row(face) = pd2;
  }
  return secondary;
}

/**
 * @brief Runs the full remeshing pipeline on an initialized TriMesh and raw cross field.
 * @param meshWhole Initialized source mesh.
 * @param rawCrossField #F-by-12 raw 4-RoSy field.
 * @param options Pipeline options.
 * @return Remeshing result with generated mesh and cut-mesh diagnostics.
 */
inline RemeshResult
remesh_from_raw_cross_field_impl(const TriMesh &meshWhole,
                                 const Eigen::MatrixXd &rawCrossField,
                                 const RemeshOptions &options = {}) {
  using Clock = std::chrono::high_resolution_clock;
  const auto pipelineStart = Clock::now();
  auto phaseStart = pipelineStart;
  const auto log_phase = [&](const char *label) {
    if (!options.verbose)
      return;
    const auto now = Clock::now();
    const auto phaseSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now - phaseStart)
            .count() /
        1e+6;
    const auto totalSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now -
                                                              pipelineStart)
            .count() /
        1e+6;
    std::cout << "[Directional::pipeline::remesh_from_raw_cross_field_impl()]: "
              << label << " completed in " << phaseSeconds << " s (total "
              << totalSeconds << " s)" << std::endl;
    phaseStart = now;
  };

  if (options.featureAlign) {
    throw std::runtime_error("featureAlign is not supported by the headless "
                             "Directional pipeline yet.");
  }
  if (rawCrossField.rows() != meshWhole.F.rows() ||
      rawCrossField.cols() != 12) {
    throw std::runtime_error(
        "rawCrossField must have shape (#F, 12) for a 4-RoSy cross field.");
  }

  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(meshWhole);
  log_phase("PCFaceTangentBundle::init");

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, 4);
  rawField.set_extrinsic_field(rawCrossField);
  log_phase("CartesianField::init + set_extrinsic_field");
  principal_matching(rawField);
  log_phase("principal_matching");

  IntegrationData integration(4);
  integration.lengthRatio = options.lengthRatio;
  integration.integralSeamless = options.integralSeamless;
  integration.roundSeams = options.roundSeams;
  integration.verbose = options.verbose;

  TriMesh meshCut;
  CartesianField combedField;
  setup_integration(rawField, integration, meshCut, combedField);
  log_phase("setup_integration");

  Eigen::MatrixXd cutFunctions;
  Eigen::MatrixXd cutCornerFunctions;
  integrate(combedField, integration, meshCut, cutFunctions,
            cutCornerFunctions);
  log_phase("integrate");

  MesherData mesherData;
  mesherData.verbose = options.verbose;
  setup_mesher(meshCut, integration, mesherData);
  log_phase("setup_mesher");

  RemeshResult result;
  result.cutVertices = meshCut.V;
  result.cutFaces = meshCut.F;
  result.cutFunctions = cutFunctions;
  result.cutCornerFunctions = cutCornerFunctions;
  result.success = mesher(meshWhole, mesherData, result.vertices,
                          result.degrees, result.faces);
  log_phase("mesher");
  return result;
}

/**
 * @brief Runs remeshing from raw mesh matrices and a raw 4-RoSy cross field.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param rawCrossField #F-by-12 raw field.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
inline RemeshResult remesh_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  return remesh_from_raw_cross_field_impl(meshWhole, rawCrossField, options);
}

/**
 * @brief Runs remeshing from two direction families per face.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param primaryDirections Primary ambient/tangent direction per face.
 * @param secondaryDirections Secondary ambient/tangent direction per face.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
inline RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const Eigen::MatrixXd &secondaryDirections,
                        const RemeshOptions &options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd rawField =
      make_raw_cross_field(meshWhole, primaryDirections, secondaryDirections,
                           options.normalizeDirections);
  return remesh_from_raw_cross_field_impl(meshWhole, rawField, options);
}

/**
 * @brief Runs remeshing from one direction family per face.
 *
 * The secondary direction is generated as the tangent-plane orthogonal
 * complement of the supplied primary direction.
 *
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param primaryDirections Primary ambient/tangent direction per face.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
inline RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const RemeshOptions &options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd secondaryDirections = orthogonal_complement(
      meshWhole, primaryDirections, options.normalizeDirections);
  const Eigen::MatrixXd rawField =
      make_raw_cross_field(meshWhole, primaryDirections, secondaryDirections,
                           options.normalizeDirections);
  return remesh_from_raw_cross_field_impl(meshWhole, rawField, options);
}

} // namespace directional::pipeline

#endif // DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
