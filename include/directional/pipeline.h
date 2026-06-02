#ifndef DIRECTIONAL_PIPELINE_H
#define DIRECTIONAL_PIPELINE_H

#include <cmath>
#include <stdexcept>

#include <Eigen/Core>

#include <directional/CartesianField.h>
#include <directional/PCFaceTangentBundle.h>
#include <directional/TriMesh.h>
#include <directional/integrate.h>
#include <directional/mesher.h>
#include <directional/principal_matching.h>
#include <directional/setup_integration.h>
#include <directional/setup_mesher.h>

namespace directional::pipeline {

struct RemeshOptions {
  double lengthRatio = 0.02;
  bool integralSeamless = true;
  bool roundSeams = false;
  bool featureAlign = false;
  bool verbose = false;
  bool normalizeDirections = true;
};

struct RemeshResult {
  bool success = false;
  Eigen::MatrixXd vertices;
  Eigen::VectorXi degrees;
  Eigen::MatrixXi faces;
  Eigen::MatrixXd cutVertices;
  Eigen::MatrixXi cutFaces;
  Eigen::MatrixXd cutFunctions;
  Eigen::MatrixXd cutCornerFunctions;
};

inline Eigen::RowVector3d project_tangent(
    const Eigen::RowVector3d& vector,
    const Eigen::RowVector3d& normal,
    const bool normalize) {
  Eigen::RowVector3d tangent = vector - vector.dot(normal) * normal;
  const double norm = tangent.norm();
  if (norm <= 1e-12) {
    throw std::runtime_error("Directional pipeline received a degenerate tangent direction.");
  }
  if (normalize) {
    tangent /= norm;
  }
  return tangent;
}

inline Eigen::MatrixXd make_raw_cross_field(
    const TriMesh& mesh,
    const Eigen::MatrixXd& primaryDirections,
    const Eigen::MatrixXd& secondaryDirections,
    const bool normalizeDirections) {
  if (primaryDirections.rows() != mesh.F.rows() || primaryDirections.cols() != 3) {
    throw std::runtime_error("primaryDirections must have shape (#F, 3).");
  }
  if (secondaryDirections.rows() != mesh.F.rows() || secondaryDirections.cols() != 3) {
    throw std::runtime_error("secondaryDirections must have shape (#F, 3).");
  }

  Eigen::MatrixXd rawField(mesh.F.rows(), 12);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d pd1 = project_tangent(primaryDirections.row(face), normal, normalizeDirections);
    const Eigen::RowVector3d pd2 = project_tangent(secondaryDirections.row(face), normal, normalizeDirections);

    rawField.block(face, 0, 1, 3) = pd1;
    rawField.block(face, 3, 1, 3) = pd2;
    rawField.block(face, 6, 1, 3) = -pd1;
    rawField.block(face, 9, 1, 3) = -pd2;
  }
  return rawField;
}

inline Eigen::MatrixXd orthogonal_complement(
    const TriMesh& mesh,
    const Eigen::MatrixXd& primaryDirections,
    const bool normalizeDirections) {
  if (primaryDirections.rows() != mesh.F.rows() || primaryDirections.cols() != 3) {
    throw std::runtime_error("primaryDirections must have shape (#F, 3).");
  }

  Eigen::MatrixXd secondary(mesh.F.rows(), 3);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d pd1 = project_tangent(primaryDirections.row(face), normal, normalizeDirections);
    Eigen::RowVector3d pd2 = normal.cross(pd1);
    const double norm = pd2.norm();
    if (norm <= 1e-12) {
      throw std::runtime_error("Failed to derive a secondary tangent direction from the primary direction.");
    }
    if (normalizeDirections) {
      pd2 /= norm;
    }
    secondary.row(face) = pd2;
  }
  return secondary;
}

inline RemeshResult remesh_from_raw_cross_field(
    const Eigen::MatrixXd& vertices,
    const Eigen::MatrixXi& faces,
    const Eigen::MatrixXd& rawCrossField,
    const RemeshOptions& options = {}) {
  if (rawCrossField.rows() != faces.rows() || rawCrossField.cols() != 12) {
    throw std::runtime_error("rawCrossField must have shape (#F, 12) for a 4-RoSy cross field.");
  }

  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);

  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(meshWhole);

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, 4);
  rawField.set_extrinsic_field(rawCrossField);
  principal_matching(rawField);

  IntegrationData integration(4);
  integration.lengthRatio = options.lengthRatio;
  integration.integralSeamless = options.integralSeamless;
  integration.roundSeams = options.roundSeams;
  integration.featureAlign = options.featureAlign;
  integration.verbose = options.verbose;

  TriMesh meshCut;
  CartesianField combedField;
  setup_integration(rawField, integration, meshCut, combedField);

  Eigen::MatrixXd cutFunctions;
  Eigen::MatrixXd cutCornerFunctions;
  integrate(combedField, integration, meshCut, cutFunctions, cutCornerFunctions);

  MesherData mesherData;
  mesherData.verbose = options.verbose;
  setup_mesher(meshCut, integration, mesherData);

  RemeshResult result;
  result.cutVertices = meshCut.V;
  result.cutFaces = meshCut.F;
  result.cutFunctions = cutFunctions;
  result.cutCornerFunctions = cutCornerFunctions;
  result.success = mesher(meshWhole, mesherData, result.vertices, result.degrees, result.faces);
  return result;
}

inline RemeshResult remesh_from_cross_field(
    const Eigen::MatrixXd& vertices,
    const Eigen::MatrixXi& faces,
    const Eigen::MatrixXd& primaryDirections,
    const Eigen::MatrixXd& secondaryDirections,
    const RemeshOptions& options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd rawField = make_raw_cross_field(
      meshWhole, primaryDirections, secondaryDirections, options.normalizeDirections);
  return remesh_from_raw_cross_field(vertices, faces, rawField, options);
}

inline RemeshResult remesh_from_cross_field(
    const Eigen::MatrixXd& vertices,
    const Eigen::MatrixXi& faces,
    const Eigen::MatrixXd& primaryDirections,
    const RemeshOptions& options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd secondaryDirections =
      orthogonal_complement(meshWhole, primaryDirections, options.normalizeDirections);
  return remesh_from_cross_field(vertices, faces, primaryDirections, secondaryDirections, options);
}

}  // namespace directional::pipeline

#endif
