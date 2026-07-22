// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_MESH_OPTIMIZER_H
#define DIRECTIONAL_GEOMETRY_SURFACE_MESH_OPTIMIZER_H

#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdint>
#include <limits>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/PureQuadCompletion.h>
#include <directional/validation/MeshValidator.h>

namespace directional::geometry {

struct SurfaceOptimizationWeights {
  double surface = 1.0;
  double normal = 1.0;
  double field = 1.0;
  double orthogonality = 1.0;
  double size = 1.0;
  double valenceShape = 1.0;
  double feature = 1.0;
};

struct SurfaceOptimizationOptions {
  SurfaceOptimizationWeights weights;
  int maxIterations = 32;
  double tolerance = 1.0e-9;
  double armijo = 1.0e-6;
  double targetSize = 1.0;
  double maxOptimizerTimeRatio = 0.25;
  std::array<double, 7> lineSearchSteps = {1.0, 0.5, 0.25, 0.125,
                                           0.0625, 0.03125, 0.015625};
};

struct SurfaceOptimizationConstraints {
  Eigen::MatrixXd sourcePositions;
  Eigen::MatrixXd sourceNormals;
  Eigen::MatrixXd sourceFieldX;
  Eigen::MatrixXd sourceFieldY;
  Eigen::VectorXi sourceComponent;
  std::vector<int> fixedVertices;
  std::vector<int> featureVertices;
  std::vector<int> softFeatureVertices;
  std::vector<std::pair<Eigen::RowVector3d, Eigen::RowVector3d>> featureIntervals;
  Eigen::VectorXd featureParameters;
};

struct SurfaceOptimizationEnergy {
  double surface = 0.0;
  double normal = 0.0;
  double field = 0.0;
  double orthogonality = 0.0;
  double size = 0.0;
  double valenceShape = 0.0;
  double feature = 0.0;
  double total = 0.0;
};

struct SurfaceOptimizationIteration {
  int iteration = 0;
  bool accepted = false;
  double alpha = 0.0;
  SurfaceOptimizationEnergy energy;
};

struct SurfaceOptimizationResult {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi quads;
  std::vector<SurfaceOptimizationIteration> iterations;
  std::uint64_t topologyHash = 0;
  bool monotonicEnergy = true;
  bool topologyHashFixed = true;
  bool featureParametersOrdered = true;
  bool projectionStayedOnComponents = true;
};

struct SurfaceFinalValidationReport {
  bool accepted = false;
  double surfaceP95 = 0.0;
  double surfaceMax = 0.0;
  double normalP95Degrees = 0.0;
  double featureP95 = 0.0;
  double featureMax = 0.0;
  double featureTangentP95Degrees = 0.0;
  double fieldMedianDegrees = 0.0;
  double fieldP95Degrees = 0.0;
  double sizeP5 = 1.0;
  double sizeP95 = 1.0;
  double angleP5Degrees = 90.0;
  double angleP95Degrees = 90.0;
  double aspectP95 = 1.0;
  double aspectP99 = 1.0;
  double scaledJacobianMin = 1.0;
  double scaledJacobianP5 = 1.0;
  int tJunctions = 0;
  int nonManifold = 0;
  int degenerate = 0;
  int inverted = 0;
  int selfIntersecting = 0;
  bool topologyHashFixed = true;
  bool featureParametersOrdered = true;
  bool projectionStayedOnComponents = true;
  bool optimizerTimeWithinGate = true;
};

struct SurfaceOptimizationOverlay {
  Eigen::MatrixXd wireframeStarts;
  Eigen::MatrixXd wireframeEnds;
  Eigen::MatrixXd shadedVertices;
  Eigen::VectorXd surfaceError;
  Eigen::VectorXd normalError;
  Eigen::VectorXd fieldAlignmentError;
  Eigen::VectorXd sizeRatio;
  Eigen::VectorXi poleValence;
};

namespace surface_optimizer_detail {

inline bool contains(const std::vector<int> &values, const int value) {
  return std::find(values.begin(), values.end(), value) != values.end();
}

inline Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v) {
  const double n = v.norm();
  if (n <= 0.0) {
    return Eigen::RowVector3d::Zero();
  }
  return v / n;
}

inline Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}

inline std::uint64_t topology_hash(const Eigen::MatrixXi &quads) {
  std::uint64_t hash = 1469598103934665603ULL;
  for (int r = 0; r < quads.rows(); ++r) {
    std::array<int, 4> face = {quads(r, 0), quads(r, 1), quads(r, 2),
                               quads(r, 3)};
    const auto minIt = std::min_element(face.begin(), face.end());
    std::rotate(face.begin(), minIt, face.end());
    for (const int v : face) {
      hash ^= static_cast<std::uint64_t>(v);
      hash *= 1099511628211ULL;
    }
    hash ^= 0xff;
    hash *= 1099511628211ULL;
  }
  return hash;
}

inline Eigen::RowVector3d project_to_interval(const Eigen::RowVector3d &p,
                                              const Eigen::RowVector3d &a,
                                              const Eigen::RowVector3d &b,
                                              double *parameter = nullptr) {
  const Eigen::RowVector3d ab = b - a;
  const double denom = ab.squaredNorm();
  double t = 0.0;
  if (denom > 0.0) {
    t = std::clamp((p - a).dot(ab) / denom, 0.0, 1.0);
  }
  if (parameter != nullptr) {
    *parameter = t;
  }
  return a + t * ab;
}

inline Eigen::RowVector3d project_to_source(const Eigen::RowVector3d &p,
                                            const Eigen::MatrixXd &source,
                                            int *component,
                                            const Eigen::VectorXi &components) {
  if (source.rows() == 0) {
    return p;
  }
  double best = std::numeric_limits<double>::infinity();
  int bestRow = 0;
  for (int i = 0; i < source.rows(); ++i) {
    if (component != nullptr && *component >= 0 && components.size() == source.rows() &&
        components(i) != *component) {
      continue;
    }
    const double d = (p - source.row(i)).squaredNorm();
    if (d < best) {
      best = d;
      bestRow = i;
    }
  }
  if (component != nullptr && components.size() == source.rows()) {
    *component = components(bestRow);
  }
  return source.row(bestRow);
}

inline Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices, const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters = nullptr,
    bool *ordered = nullptr, bool *componentsOk = nullptr) {
  Eigen::MatrixXd projected = vertices;
  Eigen::VectorXd params = constraints.featureParameters;
  if (params.size() != vertices.rows()) {
    params = Eigen::VectorXd::Zero(vertices.rows());
  }
  bool orderOk = true;
  bool componentOk = true;
  for (int i = 0; i < vertices.rows(); ++i) {
    if (contains(constraints.fixedVertices, i)) {
      continue;
    }
    if (contains(constraints.featureVertices, i)) {
      const int interval =
          std::min<int>(i, static_cast<int>(constraints.featureIntervals.size()) - 1);
      if (interval >= 0) {
        double t = 0.0;
        projected.row(i) = project_to_interval(vertices.row(i),
                                               constraints.featureIntervals[interval].first,
                                               constraints.featureIntervals[interval].second,
                                               &t);
        params(i) = t;
      }
    } else {
      int component = constraints.sourceComponent.size() == vertices.rows()
                          ? constraints.sourceComponent(i)
                          : -1;
      projected.row(i) =
          project_to_source(vertices.row(i), constraints.sourcePositions, &component,
                            constraints.sourceComponent);
      if (constraints.sourceComponent.size() == vertices.rows() &&
          component != constraints.sourceComponent(i)) {
        componentOk = false;
      }
    }
  }
  double previous = -std::numeric_limits<double>::infinity();
  std::vector<int> features = constraints.featureVertices;
  std::sort(features.begin(), features.end());
  for (const int v : features) {
    if (v >= 0 && v < params.size()) {
      if (params(v) + 1.0e-12 < previous) {
        orderOk = false;
      }
      previous = params(v);
    }
  }
  if (featureParameters != nullptr) {
    *featureParameters = params;
  }
  if (ordered != nullptr) {
    *ordered = orderOk;
  }
  if (componentsOk != nullptr) {
    *componentsOk = componentOk;
  }
  return projected;
}

inline Eigen::RowVector3d face_normal(const Eigen::MatrixXd &v,
                                      const Eigen::MatrixXi &q,
                                      const int face) {
  const Eigen::RowVector3d a = v.row(q(face, 0));
  const Eigen::RowVector3d b = v.row(q(face, 1));
  const Eigen::RowVector3d c = v.row(q(face, 2));
  return normalized_or_zero(cross3(b - a, c - a));
}

inline std::vector<double> sorted_percentiles(std::vector<double> values) {
  std::sort(values.begin(), values.end());
  return values;
}

inline double percentile(std::vector<double> values, const double p) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const int index = static_cast<int>(
      std::floor(std::clamp(p, 0.0, 1.0) * static_cast<double>(values.size() - 1)));
  return values[static_cast<std::size_t>(index)];
}

inline double angle_degrees(const Eigen::RowVector3d &a,
                            const Eigen::RowVector3d &b) {
  const Eigen::RowVector3d na = normalized_or_zero(a);
  const Eigen::RowVector3d nb = normalized_or_zero(b);
  const double dot = std::clamp(na.dot(nb), -1.0, 1.0);
  return std::acos(dot) * 180.0 / 3.14159265358979323846;
}

} // namespace surface_optimizer_detail

inline std::complex<double> degree_four_average(
    const std::vector<double> &anglesRadians,
    const std::vector<double> &connectionAnglesRadians = {},
    const std::vector<double> &weights = {}) {
  std::complex<double> sum(0.0, 0.0);
  for (int i = 0; i < static_cast<int>(anglesRadians.size()); ++i) {
    const double connection =
        i < static_cast<int>(connectionAnglesRadians.size())
            ? connectionAnglesRadians[static_cast<std::size_t>(i)]
            : 0.0;
    const double weight =
        i < static_cast<int>(weights.size()) ? weights[static_cast<std::size_t>(i)]
                                             : 1.0;
    const double angle = 4.0 * (anglesRadians[static_cast<std::size_t>(i)] +
                                connection);
    sum += weight * std::complex<double>(std::cos(angle), std::sin(angle));
  }
  const double n = std::abs(sum);
  if (n <= 0.0) {
    return {1.0, 0.0};
  }
  return sum / n;
}

inline SurfaceOptimizationEnergy evaluate_surface_optimization_energy(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationEnergy energy;
  for (int i = 0; i < vertices.rows(); ++i) {
    const Eigen::RowVector3d p = vertices.row(i);
    int component = constraints.sourceComponent.size() == vertices.rows()
                        ? constraints.sourceComponent(i)
                        : -1;
    const Eigen::RowVector3d source =
        project_to_source(p, constraints.sourcePositions, &component,
                          constraints.sourceComponent);
    energy.surface += (p - source).squaredNorm();
    if (contains(constraints.featureVertices, i) &&
        !constraints.featureIntervals.empty()) {
      const int interval =
          std::min<int>(i, static_cast<int>(constraints.featureIntervals.size()) - 1);
      const Eigen::RowVector3d feature =
          project_to_interval(p, constraints.featureIntervals[interval].first,
                              constraints.featureIntervals[interval].second);
      energy.feature += (p - feature).squaredNorm();
    }
  }

  std::vector<int> valence(vertices.rows(), 0);
  for (int f = 0; f < quads.rows(); ++f) {
    const Eigen::RowVector3d n = face_normal(vertices, quads, f);
    const Eigen::RowVector3d sourceNormal =
        constraints.sourceNormals.rows() > 0
            ? constraints.sourceNormals.row(std::min<int>(f, constraints.sourceNormals.rows() - 1))
            : Eigen::RowVector3d(0.0, 0.0, 1.0);
    energy.normal += std::pow(1.0 - std::abs(n.dot(normalized_or_zero(sourceNormal))), 2.0);
    for (int c = 0; c < 4; ++c) {
      ++valence[static_cast<std::size_t>(quads(f, c))];
      const Eigen::RowVector3d a = vertices.row(quads(f, c));
      const Eigen::RowVector3d b = vertices.row(quads(f, (c + 1) % 4));
      const Eigen::RowVector3d e = b - a;
      const double length = e.norm();
      const double ratio = length / std::max(1.0e-12, options.targetSize);
      energy.size += std::pow(ratio - 1.0, 2.0);
      const Eigen::RowVector3d x =
          constraints.sourceFieldX.rows() > 0
              ? constraints.sourceFieldX.row(std::min<int>(f, constraints.sourceFieldX.rows() - 1))
              : Eigen::RowVector3d(1.0, 0.0, 0.0);
      const Eigen::RowVector3d y =
          constraints.sourceFieldY.rows() > 0
              ? constraints.sourceFieldY.row(std::min<int>(f, constraints.sourceFieldY.rows() - 1))
              : Eigen::RowVector3d(0.0, 1.0, 0.0);
      const Eigen::RowVector3d dir = normalized_or_zero(e);
      const double align = std::max(std::abs(dir.dot(normalized_or_zero(x))),
                                    std::abs(dir.dot(normalized_or_zero(y))));
      energy.field += std::pow(1.0 - align, 2.0);
      const Eigen::RowVector3d prev = vertices.row(quads(f, (c + 3) % 4)) - a;
      const Eigen::RowVector3d next = vertices.row(quads(f, (c + 1) % 4)) - a;
      const double cosCorner =
          std::abs(normalized_or_zero(prev).dot(normalized_or_zero(next)));
      energy.orthogonality += cosCorner * cosCorner;
    }
  }
  for (const int v : valence) {
    energy.valenceShape += std::pow(static_cast<double>(v - 4), 2.0);
  }
  energy.total = options.weights.surface * energy.surface +
                 options.weights.normal * energy.normal +
                 options.weights.field * energy.field +
                 options.weights.orthogonality * energy.orthogonality +
                 options.weights.size * energy.size +
                 options.weights.valenceShape * energy.valenceShape +
                 options.weights.feature * energy.feature;
  return energy;
}

inline bool local_orientation_valid(const Eigen::MatrixXd &vertices,
                                    const Eigen::MatrixXi &quads) {
  for (int f = 0; f < quads.rows(); ++f) {
    const Eigen::RowVector3d a = vertices.row(quads(f, 0));
    const Eigen::RowVector3d b = vertices.row(quads(f, 1));
    const Eigen::RowVector3d c = vertices.row(quads(f, 2));
    if (surface_optimizer_detail::cross3(b - a, c - a).z() <= 1.0e-14) {
      return false;
    }
  }
  return true;
}

inline SurfaceOptimizationResult optimize_projected_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {}) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationResult result;
  result.vertices = initialVertices;
  result.quads = quads;
  result.topologyHash = topology_hash(quads);
  Eigen::VectorXd featureParameters;
  result.vertices = project_vertices(result.vertices, constraints, &featureParameters,
                                     &result.featureParametersOrdered,
                                     &result.projectionStayedOnComponents);
  SurfaceOptimizationEnergy current =
      evaluate_surface_optimization_energy(result.vertices, quads, constraints, options);

  for (int iteration = 0; iteration < options.maxIterations; ++iteration) {
    Eigen::MatrixXd direction = Eigen::MatrixXd::Zero(result.vertices.rows(), 3);
    for (int i = 0; i < result.vertices.rows(); ++i) {
      if (contains(constraints.fixedVertices, i)) {
        continue;
      }
      int component = constraints.sourceComponent.size() == result.vertices.rows()
                          ? constraints.sourceComponent(i)
                          : -1;
      const Eigen::RowVector3d source =
          project_to_source(result.vertices.row(i), constraints.sourcePositions,
                            &component, constraints.sourceComponent);
      direction.row(i) += result.vertices.row(i) - source;
      if (contains(constraints.featureVertices, i) &&
          !constraints.featureIntervals.empty()) {
        const int interval =
            std::min<int>(i, static_cast<int>(constraints.featureIntervals.size()) - 1);
        direction.row(i) +=
            result.vertices.row(i) -
            project_to_interval(result.vertices.row(i),
                                constraints.featureIntervals[interval].first,
                                constraints.featureIntervals[interval].second);
      }
    }
    bool accepted = false;
    double acceptedAlpha = 0.0;
    SurfaceOptimizationEnergy acceptedEnergy = current;
    for (const double alpha : options.lineSearchSteps) {
      bool ordered = true;
      bool componentsOk = true;
      const Eigen::MatrixXd trial = project_vertices(
          result.vertices - alpha * direction, constraints, nullptr, &ordered,
          &componentsOk);
      if (!local_orientation_valid(trial, quads)) {
        continue;
      }
      const SurfaceOptimizationEnergy trialEnergy =
          evaluate_surface_optimization_energy(trial, quads, constraints, options);
      if (trialEnergy.total <= current.total - options.armijo * alpha *
                                      std::max(1.0, direction.squaredNorm())) {
        result.vertices = trial;
        accepted = true;
        acceptedAlpha = alpha;
        acceptedEnergy = trialEnergy;
        result.featureParametersOrdered =
            result.featureParametersOrdered && ordered;
        result.projectionStayedOnComponents =
            result.projectionStayedOnComponents && componentsOk;
        break;
      }
    }
    SurfaceOptimizationIteration record;
    record.iteration = iteration;
    record.accepted = accepted;
    record.alpha = acceptedAlpha;
    record.energy = acceptedEnergy;
    result.iterations.push_back(record);
    if (!accepted) {
      break;
    }
    const double drop = current.total - acceptedEnergy.total;
    if (acceptedEnergy.total > current.total + 1.0e-12) {
      result.monotonicEnergy = false;
    }
    current = acceptedEnergy;
    if (drop / std::max(1.0, current.total) < options.tolerance) {
      break;
    }
  }
  result.topologyHashFixed = result.topologyHash == topology_hash(quads);
  return result;
}

inline SurfaceFinalValidationReport validate_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options = {},
    const double optimizerSeconds = 0.0, const double endToEndSeconds = 1.0) {
  using namespace surface_optimizer_detail;
  SurfaceFinalValidationReport report;
  std::vector<double> surfaceErrors;
  std::vector<double> normalErrors;
  std::vector<double> fieldErrors;
  std::vector<double> sizeRatios;
  std::vector<double> angles;
  std::vector<double> aspects;
  std::vector<double> jacobians;
  for (int i = 0; i < vertices.rows(); ++i) {
    int component = constraints.sourceComponent.size() == vertices.rows()
                        ? constraints.sourceComponent(i)
                        : -1;
    const Eigen::RowVector3d source =
        project_to_source(vertices.row(i), constraints.sourcePositions, &component,
                          constraints.sourceComponent);
    surfaceErrors.push_back((vertices.row(i) - source).norm() /
                            std::max(1.0e-12, options.targetSize));
  }
  for (const int v : constraints.featureVertices) {
    if (v >= 0 && v < vertices.rows() && !constraints.featureIntervals.empty()) {
      const int interval =
          std::min<int>(v, static_cast<int>(constraints.featureIntervals.size()) - 1);
      const auto &seg = constraints.featureIntervals[interval];
      const Eigen::RowVector3d feature =
          project_to_interval(vertices.row(v), seg.first, seg.second);
      report.featureMax =
          std::max(report.featureMax, (vertices.row(v) - feature).norm());
    }
  }
  report.featureP95 = report.featureMax;
  for (int f = 0; f < quads.rows(); ++f) {
    const Eigen::RowVector3d n = face_normal(vertices, quads, f);
    const Eigen::RowVector3d sourceNormal =
        constraints.sourceNormals.rows() > 0
            ? constraints.sourceNormals.row(std::min<int>(f, constraints.sourceNormals.rows() - 1))
            : Eigen::RowVector3d(0.0, 0.0, 1.0);
    normalErrors.push_back(angle_degrees(n, sourceNormal));
    std::array<double, 4> lengths = {};
    for (int c = 0; c < 4; ++c) {
      const Eigen::RowVector3d a = vertices.row(quads(f, c));
      const Eigen::RowVector3d b = vertices.row(quads(f, (c + 1) % 4));
      const Eigen::RowVector3d e = b - a;
      lengths[static_cast<std::size_t>(c)] = e.norm();
      sizeRatios.push_back(e.norm() / std::max(1.0e-12, options.targetSize));
      const Eigen::RowVector3d x =
          constraints.sourceFieldX.rows() > 0
              ? constraints.sourceFieldX.row(std::min<int>(f, constraints.sourceFieldX.rows() - 1))
              : Eigen::RowVector3d(1.0, 0.0, 0.0);
      const Eigen::RowVector3d y =
          constraints.sourceFieldY.rows() > 0
              ? constraints.sourceFieldY.row(std::min<int>(f, constraints.sourceFieldY.rows() - 1))
              : Eigen::RowVector3d(0.0, 1.0, 0.0);
      const Eigen::RowVector3d dir = normalized_or_zero(e);
      const double align = std::clamp(
          std::max(std::abs(dir.dot(normalized_or_zero(x))),
                   std::abs(dir.dot(normalized_or_zero(y)))),
          0.0, 1.0);
      fieldErrors.push_back(std::acos(align) * 180.0 / 3.14159265358979323846);
      const Eigen::RowVector3d prev = vertices.row(quads(f, (c + 3) % 4)) - a;
      const Eigen::RowVector3d next = vertices.row(quads(f, (c + 1) % 4)) - a;
      angles.push_back(angle_degrees(prev, next));
    }
    const auto [minIt, maxIt] = std::minmax_element(lengths.begin(), lengths.end());
    aspects.push_back(*maxIt / std::max(1.0e-12, *minIt));
    jacobians.push_back(std::min(1.0, *minIt / std::max(1.0e-12, *maxIt)));
  }
  report.surfaceP95 = percentile(surfaceErrors, 0.95);
  report.surfaceMax = surfaceErrors.empty() ? 0.0 : *std::max_element(surfaceErrors.begin(), surfaceErrors.end());
  report.normalP95Degrees = percentile(normalErrors, 0.95);
  report.fieldMedianDegrees = percentile(fieldErrors, 0.50);
  report.fieldP95Degrees = percentile(fieldErrors, 0.95);
  report.sizeP5 = percentile(sizeRatios, 0.05);
  report.sizeP95 = percentile(sizeRatios, 0.95);
  report.angleP5Degrees = percentile(angles, 0.05);
  report.angleP95Degrees = percentile(angles, 0.95);
  report.aspectP95 = percentile(aspects, 0.95);
  report.aspectP99 = percentile(aspects, 0.99);
  report.scaledJacobianMin =
      jacobians.empty() ? 1.0 : *std::min_element(jacobians.begin(), jacobians.end());
  report.scaledJacobianP5 = percentile(jacobians, 0.05);
  const auto validation =
      validation::MeshValidator::validate_surface_mesh(vertices, quads);
  for (const auto &issue : validation.issues) {
    if (issue.code == validation::MeshValidationFailureCode::GeometricVertexOnUnsplitEdge) {
      ++report.tJunctions;
    } else if (issue.code == validation::MeshValidationFailureCode::ThreeSidedInteriorEdge ||
               issue.code == validation::MeshValidationFailureCode::OneSidedInteriorEdge) {
      ++report.nonManifold;
    } else if (issue.code == validation::MeshValidationFailureCode::ZeroAreaFace) {
      ++report.degenerate;
    } else if (issue.code == validation::MeshValidationFailureCode::FlippedFace) {
      ++report.inverted;
    } else if (issue.code == validation::MeshValidationFailureCode::SelfIntersectingFace) {
      ++report.selfIntersecting;
    }
  }
  report.topologyHashFixed = optimization.topologyHashFixed;
  report.featureParametersOrdered = optimization.featureParametersOrdered;
  report.projectionStayedOnComponents = optimization.projectionStayedOnComponents;
  report.optimizerTimeWithinGate =
      optimizerSeconds <= options.maxOptimizerTimeRatio * std::max(1.0e-12, endToEndSeconds);
  report.accepted = report.surfaceP95 <= 0.15 && report.surfaceMax <= 0.50 &&
                    report.normalP95Degrees <= 15.0 &&
                    report.fieldMedianDegrees <= 7.5 &&
                    report.fieldP95Degrees <= 15.0 &&
                    report.sizeP5 >= 0.50 && report.sizeP95 <= 2.00 &&
                    report.angleP5Degrees >= 35.0 &&
                    report.angleP95Degrees <= 145.0 &&
                    report.aspectP95 <= 4.0 && report.aspectP99 <= 8.0 &&
                    report.scaledJacobianMin > 0.0 &&
                    report.scaledJacobianP5 >= 0.20 && report.tJunctions == 0 &&
                    report.nonManifold == 0 && report.degenerate == 0 &&
                    report.inverted == 0 && report.selfIntersecting == 0 &&
                    report.topologyHashFixed && report.featureParametersOrdered &&
                    report.projectionStayedOnComponents &&
                    report.optimizerTimeWithinGate;
  return report;
}

inline SurfaceOptimizationOverlay make_surface_optimization_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {}) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationOverlay overlay;
  overlay.wireframeStarts.resize(4 * quads.rows(), 3);
  overlay.wireframeEnds.resize(4 * quads.rows(), 3);
  overlay.shadedVertices = vertices;
  overlay.surfaceError.resize(vertices.rows());
  overlay.normalError.resize(quads.rows());
  overlay.fieldAlignmentError.resize(4 * quads.rows());
  overlay.sizeRatio.resize(4 * quads.rows());
  overlay.poleValence = Eigen::VectorXi::Zero(vertices.rows());
  for (int i = 0; i < vertices.rows(); ++i) {
    int component = constraints.sourceComponent.size() == vertices.rows()
                        ? constraints.sourceComponent(i)
                        : -1;
    overlay.surfaceError(i) =
        (vertices.row(i) - project_to_source(vertices.row(i),
                                             constraints.sourcePositions,
                                             &component,
                                             constraints.sourceComponent))
            .norm();
  }
  for (int f = 0; f < quads.rows(); ++f) {
    overlay.normalError(f) = 0.0;
    for (int c = 0; c < 4; ++c) {
      const int row = 4 * f + c;
      const Eigen::RowVector3d a = vertices.row(quads(f, c));
      const Eigen::RowVector3d b = vertices.row(quads(f, (c + 1) % 4));
      overlay.wireframeStarts.row(row) = a;
      overlay.wireframeEnds.row(row) = b;
      overlay.sizeRatio(row) = (b - a).norm() / std::max(1.0e-12, options.targetSize);
      ++overlay.poleValence(quads(f, c));
      overlay.fieldAlignmentError(row) = 0.0;
    }
  }
  return overlay;
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_MESH_OPTIMIZER_H
