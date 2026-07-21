// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H
#define DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H

#include <complex>
#include <limits>
#include <numbers>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/SurfacePoint.h>

namespace directional::fields {

struct PointCrossFieldSample {
  Eigen::Vector3d position = Eigen::Vector3d::Zero();
  Eigen::Vector3d direction = Eigen::Vector3d::UnitX();
  double weight = 1.0;
};

struct PointSampledCrossFieldOptions {
  bool normalizeDirections = true;
  double maximumProjectionDistance =
      std::numeric_limits<double>::infinity();
  double minimumConfidence = 1.0e-12;
};

struct PointSampledCrossFieldResult {
  CrossFieldResult field;
  Eigen::VectorXd faceConfidence;
  std::vector<geometry::SurfacePoint> sampleProvenance;
};

inline PointSampledCrossFieldResult project_point_sampled_cross_field(
    const TriMesh &mesh, const std::vector<PointCrossFieldSample> &samples,
    const PointSampledCrossFieldOptions &options =
        PointSampledCrossFieldOptions{}) {
  if (mesh.F.rows() == 0 || mesh.F.cols() != 3) {
    throw std::runtime_error(
        "point-sampled cross-field projection requires a triangular mesh.");
  }

  using Complex = std::complex<double>;
  Eigen::VectorXcd accum = Eigen::VectorXcd::Zero(mesh.F.rows());
  Eigen::VectorXd weights = Eigen::VectorXd::Zero(mesh.F.rows());
  PointSampledCrossFieldResult result;
  result.sampleProvenance.reserve(samples.size());
  const geometry::SurfaceProjectionBvh projectionBvh(mesh.V, mesh.F);

  for (const PointCrossFieldSample &sample : samples) {
    const geometry::SurfacePoint projected =
        projectionBvh.project(sample.position);
    result.sampleProvenance.push_back(projected);
    if (!projected.valid() || sample.weight <= 0.0 ||
        projected.squaredDistance >
            options.maximumProjectionDistance *
                options.maximumProjectionDistance) {
      continue;
    }

    const int face = projected.face;
    const Eigen::RowVector3d normal = mesh.faceNormals.row(face);
    const Eigen::RowVector3d tangent =
        project_tangent(sample.direction.transpose(), normal,
                        options.normalizeDirections);
    const double x = tangent.dot(mesh.FBx.row(face));
    const double y = tangent.dot(mesh.FBy.row(face));
    Complex z(x, y);
    const double magnitude = std::abs(z);
    if (magnitude <= options.minimumConfidence) {
      continue;
    }
    z /= magnitude;
    accum(face) += sample.weight * std::pow(z, kCrossFieldDegree);
    weights(face) += sample.weight;
  }

  result.faceConfidence = Eigen::VectorXd::Zero(mesh.F.rows());
  result.field.rawField.resize(mesh.F.rows(), 3 * kCrossFieldDegree);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    Complex power(1.0, 0.0);
    if (weights(face) > 0.0) {
      result.faceConfidence(face) = std::abs(accum(face)) / weights(face);
      if (std::abs(accum(face)) > options.minimumConfidence) {
        power = accum(face) / std::abs(accum(face));
      }
    }
    Complex root =
        std::pow(power, 1.0 / static_cast<double>(kCrossFieldDegree));
    const double rootMagnitude = std::abs(root);
    if (rootMagnitude > options.minimumConfidence) {
      root /= rootMagnitude;
    }
    for (int branch = 0; branch < kCrossFieldDegree; ++branch) {
      const double angle = 2.0 * std::numbers::pi *
                           static_cast<double>(branch) /
                           static_cast<double>(kCrossFieldDegree);
      const Complex rotated = root * std::exp(Complex(0.0, angle));
      Eigen::RowVector3d direction =
          rotated.real() * mesh.FBx.row(face) + rotated.imag() * mesh.FBy.row(face);
      if (options.normalizeDirections) {
        direction.normalize();
      }
      result.field.rawField.block(face, 3 * branch, 1, 3) = direction;
    }
  }

  result.field.primaryDirections = result.field.rawField.leftCols<3>();
  result.field.secondaryDirections = result.field.rawField.middleCols<3>(3);
  result.field.matching = Eigen::VectorXi::Zero(mesh.EV.rows());
  result.field.effort = Eigen::VectorXd::Zero(mesh.EV.rows());
  result.field.singularCycles.resize(0);
  result.field.singularIndices.resize(0);
  return result;
}

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H
