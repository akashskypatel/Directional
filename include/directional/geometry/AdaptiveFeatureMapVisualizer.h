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

AdaptiveFeatureMapOverlay
make_adaptive_feature_map_overlay(const AdaptiveFeatureMap &map);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_VISUALIZER_H
