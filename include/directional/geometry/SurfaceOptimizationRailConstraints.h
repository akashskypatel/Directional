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

#include <directional/authority/AuthorityIds.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfaceMeshOptimizer.h>

namespace directional::geometry {

namespace surface_optimization_rail_detail {

bool source_face_contains_vertex(
    const Eigen::MatrixXi &faces, authority::SourceFaceId face,
    authority::SourceVertexId vertex);

bool provenance_supports_interval_sheet(
    const SurfacePoint &provenance,
    const SurfaceFeatureCurveInterval &interval,
    const SurfaceOptimizationConstraints &constraints);

} // namespace surface_optimization_rail_detail

void fill_surface_optimization_rail_constraints(
    const std::vector<SurfaceCellRail> &rails,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_OPTIMIZATION_RAIL_CONSTRAINTS_H
