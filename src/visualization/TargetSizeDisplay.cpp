// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/TargetSizeDisplay.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <string>
#include <utility>

namespace directional::visualization {
namespace {

constexpr double kRadiansToDegrees = 180.0 / 3.14159265358979323846;

void add_vertex_scalar(TargetSizeDisplay &display, const Eigen::Index vertexCount,
                       const char *name, const Eigen::VectorXd &values) {
  if (values.size() == 0) return;
  if (values.size() != vertexCount) {
    display.notes.push_back(std::string(name) + " has " +
                            std::to_string(values.size()) +
                            " entries, not one per vertex");
    return;
  }
  VertexScalarField field;
  field.name = name;
  field.values = values;
  // Heatmaps cannot color infinities; show them at the finite maximum.
  double finiteMax = -std::numeric_limits<double>::infinity();
  for (Eigen::Index i = 0; i < values.size(); ++i) {
    if (std::isfinite(values(i))) {
      finiteMax = std::max(finiteMax, values(i));
    } else {
      ++field.nonFiniteCount;
    }
  }
  if (field.nonFiniteCount > 0) {
    const double fill = std::isfinite(finiteMax) ? finiteMax : 0.0;
    for (Eigen::Index i = 0; i < values.size(); ++i) {
      if (!std::isfinite(field.values(i))) field.values(i) = fill;
    }
  }
  display.vertexScalars.push_back(std::move(field));
}

} // namespace

TargetSizeDisplay target_size_display(const Eigen::MatrixXd &V,
                                      const Eigen::MatrixXi &F,
                                      const geometry::AdaptiveTargetSizeResult *targetSize,
                                      const geometry::AdaptiveFeatureMap *featureMap) {
  if (V.cols() != 3 || F.cols() != 3) {
    throw std::invalid_argument("Display needs n x 3 vertices and m x 3 faces.");
  }
  TargetSizeDisplay display;
  const Eigen::Index vertexCount = V.rows();
  if (targetSize != nullptr) {
    display.hasTargetSize = true;
    display.resolvedSurfaceError = targetSize->resolvedSurfaceError;
    add_vertex_scalar(display, vertexCount, "target edge length", targetSize->targetSize);
    add_vertex_scalar(display, vertexCount, "salience size", targetSize->salienceSize);
    add_vertex_scalar(display, vertexCount, "curvature size", targetSize->curvatureSize);
    add_vertex_scalar(display, vertexCount, "thickness size", targetSize->thicknessSize);
    add_vertex_scalar(display, vertexCount, "normalized salience",
                      targetSize->normalizedSalience);
    add_vertex_scalar(display, vertexCount, "normalized feature density",
                      targetSize->normalizedFeatureDensity);
    add_vertex_scalar(display, vertexCount, "curvature", targetSize->curvature);
    add_vertex_scalar(display, vertexCount, "thickness", targetSize->thickness);
  }
  if (featureMap == nullptr) return display;

  display.hasFeatureMap = true;
  add_vertex_scalar(display, vertexCount, "feature vertex density",
                    featureMap->vertexDensity);
  std::vector<const geometry::AdaptiveFeatureEdge *> features;
  for (const auto &edge : featureMap->edges) {
    if (edge.edgeClass == geometry::AdaptiveFeatureClass::Smooth) continue;
    if (edge.vertices.first < 0 || edge.vertices.second < 0 ||
        edge.vertices.first >= vertexCount || edge.vertices.second >= vertexCount) {
      throw std::invalid_argument("A feature edge names a vertex outside the mesh.");
    }
    features.push_back(&edge);
  }
  const auto count = static_cast<Eigen::Index>(features.size());
  display.featurePoints.resize(2 * count, 3);
  display.featureEdges.resize(count, 2);
  display.featureClass.resize(count);
  display.featureStrength.resize(count);
  display.featureAngleDegrees.resize(count);
  for (Eigen::Index row = 0; row < count; ++row) {
    const auto &edge = *features[static_cast<std::size_t>(row)];
    display.featurePoints.row(2 * row) = V.row(edge.vertices.first);
    display.featurePoints.row(2 * row + 1) = V.row(edge.vertices.second);
    display.featureEdges(row, 0) = static_cast<int>(2 * row);
    display.featureEdges(row, 1) = static_cast<int>(2 * row + 1);
    display.featureClass(row) = static_cast<int>(edge.edgeClass);
    display.featureStrength(row) = edge.strength;
    display.featureAngleDegrees(row) = edge.angleRadians * kRadiansToDegrees;
  }
  return display;
}

} // namespace directional::visualization
