// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_VISUALIZER_H
#define DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_VISUALIZER_H

#include <algorithm>
#include <set>
#include <vector>

#include <Eigen/Core>

#include <directional/geometry/AdaptiveFeatureMap.h>

namespace directional::geometry {

struct AdaptiveFeatureMapOverlay {
  Eigen::VectorXd edgeStrength;
  Eigen::VectorXi edgeClass;
  Eigen::VectorXi edgeCurveId;
  Eigen::VectorXd vertexDensity;
  Eigen::VectorXi cornerVertices;
  Eigen::VectorXi junctionVertices;
};

#if defined(DIRECTIONAL_ADAPTIVE_FEATURE_MAP_VISUALIZER_IMPLEMENTATION)
AdaptiveFeatureMapOverlay
make_adaptive_feature_map_overlay(const AdaptiveFeatureMap &map) {
  AdaptiveFeatureMapOverlay overlay;
  overlay.edgeStrength.resize(static_cast<int>(map.edges.size()));
  overlay.edgeClass.resize(static_cast<int>(map.edges.size()));
  overlay.edgeCurveId.resize(static_cast<int>(map.edges.size()));
  for (int index = 0; index < static_cast<int>(map.edges.size()); ++index) {
    const AdaptiveFeatureEdge &edge = map.edges[static_cast<std::size_t>(index)];
    overlay.edgeStrength(index) = edge.strength;
    overlay.edgeClass(index) = static_cast<int>(edge.edgeClass);
    overlay.edgeCurveId(index) = edge.curve;
  }
  overlay.vertexDensity = map.vertexDensity;

  std::set<int> corners;
  std::set<int> junctions;
  for (const AdaptiveFeatureCurve &curve : map.curves) {
    corners.insert(curve.corners.begin(), curve.corners.end());
    junctions.insert(curve.junctions.begin(), curve.junctions.end());
  }
  overlay.cornerVertices.resize(static_cast<int>(corners.size()));
  overlay.junctionVertices.resize(static_cast<int>(junctions.size()));
  int row = 0;
  for (const int vertex : corners) {
    overlay.cornerVertices(row++) = vertex;
  }
  row = 0;
  for (const int vertex : junctions) {
    overlay.junctionVertices(row++) = vertex;
  }
  return overlay;
}
#else
AdaptiveFeatureMapOverlay
make_adaptive_feature_map_overlay(const AdaptiveFeatureMap &map);
#endif

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_VISUALIZER_H
