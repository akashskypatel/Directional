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
#include <queue>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>
#include <directional/fields/CrossField.h>
#include <directional/geometry/SurfacePoint.h>

#if defined(DIRECTIONAL_POINT_SAMPLED_CROSS_FIELD_IMPLEMENTATION)
#include <directional/core/CartesianField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#endif

namespace directional::fields {

struct PointCrossFieldSample {
  Eigen::Vector3d position = Eigen::Vector3d::Zero();
  Eigen::Vector3d direction = Eigen::Vector3d::UnitX();
  double weight = 1.0;
  int requiredFace = -1;
  int requiredComponent = -1;
  int requiredSheet = -1;
};

enum class UncoveredFacePolicy {
  Fail,
  PropagateWithinComponent
};

struct PointSampledCrossFieldOptions {
  bool normalizeDirections = true;
  double maximumProjectionDistance =
      std::numeric_limits<double>::infinity();
  double minimumConfidence = 1.0e-12;
  UncoveredFacePolicy uncoveredFacePolicy = UncoveredFacePolicy::Fail;
  bool combDirections = true;
  bool computeMatching = true;
  std::vector<int> faceComponents;
  std::vector<int> faceSheets;
};

struct PointSampledCrossFieldResult {
  CrossFieldResult field;
  Eigen::VectorXd faceConfidence;
  std::vector<geometry::SurfacePoint> sampleProvenance;
};

#if defined(DIRECTIONAL_POINT_SAMPLED_CROSS_FIELD_IMPLEMENTATION)
PointSampledCrossFieldResult project_point_sampled_cross_field(
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
    std::vector<unsigned char> allowedFaces;
    if (sample.requiredFace >= 0 || sample.requiredComponent >= 0 ||
        sample.requiredSheet >= 0) {
      allowedFaces.assign(static_cast<std::size_t>(mesh.F.rows()), 0);
      for (int face = 0; face < mesh.F.rows(); ++face) {
        bool allowed = true;
        if (sample.requiredFace >= 0 && face != sample.requiredFace) {
          allowed = false;
        }
        if (sample.requiredComponent >= 0) {
          const std::size_t index = static_cast<std::size_t>(face);
          allowed = allowed && index < options.faceComponents.size() &&
                    options.faceComponents[index] == sample.requiredComponent;
        }
        if (sample.requiredSheet >= 0) {
          const std::size_t index = static_cast<std::size_t>(face);
          allowed = allowed && index < options.faceSheets.size() &&
                    options.faceSheets[index] == sample.requiredSheet;
        }
        allowedFaces[static_cast<std::size_t>(face)] =
            static_cast<unsigned char>(allowed ? 1 : 0);
      }
    }
    geometry::SurfaceProjectionOptions projectionOptions;
    projectionOptions.allowedFaces =
        allowedFaces.empty() ? nullptr : &allowedFaces;
    projectionOptions.faceComponents =
        options.faceComponents.empty() ? nullptr : &options.faceComponents;
    projectionOptions.faceSheets =
        options.faceSheets.empty() ? nullptr : &options.faceSheets;
    const geometry::SurfacePoint projected =
        projectionBvh.project(sample.position, projectionOptions);
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

  const auto propagate_uncovered = [&]() {
    std::queue<int> frontier;
    for (int face = 0; face < mesh.F.rows(); ++face) {
      if (weights(face) > 0.0 && std::abs(accum(face)) > options.minimumConfidence) {
        frontier.push(face);
      }
    }
    while (!frontier.empty()) {
      const int face = frontier.front();
      frontier.pop();
      for (int corner = 0; corner < mesh.TT.cols(); ++corner) {
        const int neighbor = mesh.TT(face, corner);
        if (neighbor < 0 || weights(neighbor) > 0.0) {
          continue;
        }
        const std::size_t faceIndex = static_cast<std::size_t>(face);
        const std::size_t neighborIndex = static_cast<std::size_t>(neighbor);
        if (!options.faceComponents.empty() &&
            (faceIndex >= options.faceComponents.size() ||
             neighborIndex >= options.faceComponents.size() ||
             options.faceComponents[faceIndex] !=
                 options.faceComponents[neighborIndex])) {
          continue;
        }
        if (!options.faceSheets.empty() &&
            (faceIndex >= options.faceSheets.size() ||
             neighborIndex >= options.faceSheets.size() ||
             options.faceSheets[faceIndex] != options.faceSheets[neighborIndex])) {
          continue;
        }
        accum(neighbor) = accum(face);
        weights(neighbor) = weights(face);
        frontier.push(neighbor);
      }
    }
  };

  if (options.uncoveredFacePolicy == UncoveredFacePolicy::PropagateWithinComponent) {
    propagate_uncovered();
  }

  for (int face = 0; face < mesh.F.rows(); ++face) {
    if (weights(face) <= 0.0 || std::abs(accum(face)) <= options.minimumConfidence) {
      throw std::runtime_error(
          "point-sampled cross-field projection left an uncovered or "
          "ambiguous face; provide same-component samples or enable explicit "
          "propagation.");
    }
  }

  result.faceConfidence = Eigen::VectorXd::Zero(mesh.F.rows());
  Eigen::MatrixXd intrinsic(mesh.F.rows(), 2 * kCrossFieldDegree);
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
      intrinsic(face, 2 * branch) = rotated.real();
      intrinsic(face, 2 * branch + 1) = rotated.imag();
    }
  }

  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(mesh);
  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, kCrossFieldDegree);
  rawField.set_intrinsic_field(intrinsic);
  result.field = finalize_cross_field_result(
      rawField, options.combDirections, options.computeMatching);
  return result;
}
#else
PointSampledCrossFieldResult project_point_sampled_cross_field(
    const TriMesh &mesh, const std::vector<PointCrossFieldSample> &samples,
    const PointSampledCrossFieldOptions &options =
        PointSampledCrossFieldOptions{});
#endif

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_POINT_SAMPLED_CROSS_FIELD_H
