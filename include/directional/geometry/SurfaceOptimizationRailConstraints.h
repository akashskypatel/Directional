// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_OPTIMIZATION_RAIL_CONSTRAINTS_H
#define DIRECTIONAL_GEOMETRY_SURFACE_OPTIMIZATION_RAIL_CONSTRAINTS_H

#include <algorithm>
#include <limits>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfaceMeshOptimizer.h>

namespace directional::geometry {

inline void fill_surface_optimization_rail_constraints(
    const std::vector<SurfaceCellRail> &rails,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints) {
  constraints.featureCurveIntervals.clear();
  constraints.featureIntervals.clear();
  constraints.featureVertices.clear();
  constraints.orderedFeatureVertices.clear();
  constraints.authoritativeBoundaryEdges.clear();
  constraints.authoritativeBoundaryLoop.clear();
  std::vector<int> firstClosedBoundaryLoop;
  int nextIntervalId = 0;
  for (const SurfaceCellRail &rail : rails) {
    const int curveId = rail.curveId >= 0 ? rail.curveId : rail.id;
    for (int sampleIndex = 0;
         sampleIndex + 1 < static_cast<int>(rail.samples.size());
         sampleIndex += 2) {
      const SurfaceCellRailSample &start =
          rail.samples[static_cast<std::size_t>(sampleIndex)];
      const SurfaceCellRailSample &end =
          rail.samples[static_cast<std::size_t>(sampleIndex + 1)];
      SurfaceFeatureCurveInterval interval;
      interval.curveId = curveId;
      interval.intervalId = nextIntervalId++;
      interval.railId = rail.id;
      interval.order = sampleIndex / 2;
      interval.sourceFace = start.sourceFace;
      interval.component = rail.component;
      interval.sheet =
          start.sourceFace >= 0 &&
                  start.sourceFace <
                      static_cast<int>(constraints.sourceFaceSheet.size())
              ? constraints.sourceFaceSheet[static_cast<std::size_t>(
                    start.sourceFace)]
              : -1;
      interval.parameterStart = start.railParameter;
      interval.parameterEnd = end.railParameter;
      interval.curveClosed = rail.closed;
      interval.start = start.position;
      interval.end = end.position;
      constraints.featureCurveIntervals.push_back(interval);
    }
    if (rail.kind != SurfaceCellRailKind::Boundary) {
      continue;
    }
    for (int index = 0; index + 1 < static_cast<int>(rail.sourceVertices.size());
         ++index) {
      const int a = rail.sourceVertices[static_cast<std::size_t>(index)];
      const int b = rail.sourceVertices[static_cast<std::size_t>(index + 1)];
      constraints.authoritativeBoundaryEdges.insert(
          {std::min(a, b), std::max(a, b)});
    }
    if (rail.closed && rail.sourceVertices.size() > 1U) {
      if (rail.sourceVertices.back() != rail.sourceVertices.front()) {
        constraints.authoritativeBoundaryEdges.insert(
            {std::min(rail.sourceVertices.back(), rail.sourceVertices.front()),
             std::max(rail.sourceVertices.back(), rail.sourceVertices.front())});
      }
      if (firstClosedBoundaryLoop.empty()) {
        firstClosedBoundaryLoop = rail.sourceVertices;
        if (firstClosedBoundaryLoop.size() > 1U &&
            firstClosedBoundaryLoop.front() == firstClosedBoundaryLoop.back()) {
          firstClosedBoundaryLoop.pop_back();
        }
      }
    }
  }
  constraints.authoritativeBoundaryLoop = firstClosedBoundaryLoop;

  constraints.featureCurveIds =
      Eigen::VectorXi::Constant(outputVertices.rows(), -1);
  constraints.featureRailIds =
      Eigen::VectorXi::Constant(outputVertices.rows(), -1);
  constraints.featureIntervalIds =
      Eigen::VectorXi::Constant(outputVertices.rows(), -1);
  constraints.featureParameters = Eigen::VectorXd::Zero(outputVertices.rows());
  if (outputVertices.rows() == 0 || constraints.featureCurveIntervals.empty()) {
    return;
  }

  const Eigen::RowVector3d minimum = outputVertices.colwise().minCoeff();
  const Eigen::RowVector3d maximum = outputVertices.colwise().maxCoeff();
  const double tolerance = 1.0e-9 * std::max(1.0, (maximum - minimum).norm());
  const double toleranceSquared = tolerance * tolerance;
  struct FeatureAssignment {
    int vertex = -1;
    int curveId = -1;
    int sequenceId = -1;
    int order = -1;
    double parameter = 0.0;
    double localParameter = 0.0;
  };
  std::vector<FeatureAssignment> assignments;
  for (int vertex = 0; vertex < outputVertices.rows(); ++vertex) {
    const SurfacePoint provenance =
        vertex < static_cast<int>(outputProvenance.size())
            ? outputProvenance[static_cast<std::size_t>(vertex)]
            : SurfacePoint{};
    double bestDistance = std::numeric_limits<double>::infinity();
    const SurfaceFeatureCurveInterval *best = nullptr;
    double bestLocalParameter = 0.0;
    bool bestMatchesSourceFace = false;
    struct IncidentInterval {
      const SurfaceFeatureCurveInterval *interval = nullptr;
      double localParameter = 0.0;
    };
    std::vector<IncidentInterval> incidentIntervals;
    for (const SurfaceFeatureCurveInterval &interval :
         constraints.featureCurveIntervals) {
      if (provenance.component >= 0 && interval.component >= 0 &&
          provenance.component != interval.component) {
        continue;
      }
      if (provenance.sheet >= 0 && interval.sheet >= 0 &&
          provenance.sheet != interval.sheet) {
        continue;
      }
      double localParameter = 0.0;
      const Eigen::RowVector3d projected =
          surface_optimizer_detail::project_to_interval(
              outputVertices.row(vertex), interval.start, interval.end,
              &localParameter);
      const double distance =
          (outputVertices.row(vertex) - projected).squaredNorm();
      if (distance <= toleranceSquared) {
        incidentIntervals.push_back({&interval, localParameter});
      }
      const bool matchesSourceFace =
          provenance.face >= 0 && interval.sourceFace == provenance.face;
      if (distance + 1.0e-24 < bestDistance ||
          (std::abs(distance - bestDistance) <= 1.0e-24 &&
           matchesSourceFace && !bestMatchesSourceFace)) {
        bestDistance = distance;
        best = &interval;
        bestLocalParameter = localParameter;
        bestMatchesSourceFace = matchesSourceFace;
      }
    }
    if (best == nullptr || bestDistance > toleranceSquared) {
      continue;
    }
    constraints.featureVertices.push_back(vertex);
    constraints.featureCurveIds(vertex) = best->curveId;
    constraints.featureRailIds(vertex) = best->railId;
    constraints.featureIntervalIds(vertex) = best->intervalId;
    constraints.featureParameters(vertex) =
        best->parameterStart +
        bestLocalParameter * (best->parameterEnd - best->parameterStart);
    assignments.push_back(
        {vertex, best->curveId,
         best->railId >= 0 ? best->railId : best->curveId, best->order,
         constraints.featureParameters(vertex), bestLocalParameter});
    bool fixed = false;
    for (std::size_t first = 0; first < incidentIntervals.size() && !fixed;
         ++first) {
      for (std::size_t second = first + 1;
           second < incidentIntervals.size(); ++second) {
        const SurfaceFeatureCurveInterval &a =
            *incidentIntervals[first].interval;
        const SurfaceFeatureCurveInterval &b =
            *incidentIntervals[second].interval;
        if (a.curveId != b.curveId || a.railId != b.railId) {
          fixed = true;
          break;
        }
        const Eigen::RowVector3d ta =
            surface_optimizer_detail::normalized_or_zero(a.end - a.start);
        const Eigen::RowVector3d tb =
            surface_optimizer_detail::normalized_or_zero(b.end - b.start);
        if (ta.squaredNorm() == 0.0 || tb.squaredNorm() == 0.0 ||
            std::abs(ta.dot(tb)) < 0.999) {
          fixed = true;
          break;
        }
      }
    }
    if (!fixed && incidentIntervals.size() == 1U) {
      const IncidentInterval &incident = incidentIntervals.front();
      fixed = !incident.interval->curveClosed &&
              (incident.localParameter <= 1.0e-12 ||
               incident.localParameter >= 1.0 - 1.0e-12);
    }
    if (fixed &&
        std::find(constraints.fixedVertices.begin(),
                  constraints.fixedVertices.end(), vertex) ==
            constraints.fixedVertices.end()) {
      constraints.fixedVertices.push_back(vertex);
    }
  }
  std::stable_sort(assignments.begin(), assignments.end(),
                   [](const FeatureAssignment &a, const FeatureAssignment &b) {
                     if (a.sequenceId != b.sequenceId) {
                       return a.sequenceId < b.sequenceId;
                     }
                     if (a.curveId != b.curveId) {
                       return a.curveId < b.curveId;
                     }
                     if (a.order != b.order) {
                       return a.order < b.order;
                     }
                     if (a.localParameter != b.localParameter) {
                       return a.localParameter < b.localParameter;
                     }
                     if (a.parameter != b.parameter) {
                       return a.parameter < b.parameter;
                     }
                     return a.vertex < b.vertex;
                   });
  for (const FeatureAssignment &assignment : assignments) {
    constraints.orderedFeatureVertices.push_back(assignment.vertex);
  }
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_OPTIMIZATION_RAIL_CONSTRAINTS_H
