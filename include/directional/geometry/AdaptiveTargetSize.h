// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_ADAPTIVE_TARGET_SIZE_H
#define DIRECTIONAL_GEOMETRY_ADAPTIVE_TARGET_SIZE_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>
#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/FaceCurvature.h>
#include <directional/geometry/MeshComponents.h>
#include <directional/geometry/SurfacePoint.h>

namespace directional::geometry {

struct IntrinsicGraphDistanceResult {
  Eigen::VectorXd distance;
  Eigen::VectorXi previous;
  std::vector<std::pair<int, int>> edges;
};

struct LocalThicknessOptions {
  bool sameComponentOnly = true;
  bool requireOpposingNormals = true;
  double normalCompatibility = 0.85;
  double percentile = 0.25;
  double minimumDistance = 1.0e-12;
  std::vector<int> faceSheets;
};

struct LocalThicknessResult {
  Eigen::VectorXd thickness;
  Eigen::VectorXi candidateFace;
  Eigen::VectorXi component;
  Eigen::VectorXi validCandidateCount;
};

struct AdaptiveTargetSizeOptions {
  double baseSize = 1.0;
  double minSize = 0.0;
  double maxSize = std::numeric_limits<double>::infinity();
  double salienceWeight = 1.0;
  double featureDensityWeight = 1.0;
  double maxSurfaceErrorRatio = 0.05;
  double absoluteSurfaceError = -1.0;
  double thicknessScale = 0.35;
  double curvatureEpsilon = 1.0e-12;
  double gradationRatio = 2.0;
  int gradationPasses = 64;
  bool enableHeatDistance = false;
  bool enableSkeletonHints = false;
};

struct PrincipalVertexCurvatureResult {
  Eigen::VectorXd curvature;
  Eigen::VectorXd confidence;
};

struct AdaptiveTargetSizeInput {
  Eigen::VectorXd salience;
  Eigen::VectorXd featureDensity;
  Eigen::VectorXd curvature;
  Eigen::VectorXd thickness;
};

struct AdaptiveTargetSizeResult {
  Eigen::VectorXd normalizedSalience;
  Eigen::VectorXd normalizedFeatureDensity;
  Eigen::VectorXd curvature;
  Eigen::VectorXd thickness;
  Eigen::VectorXd salienceSize;
  Eigen::VectorXd curvatureSize;
  Eigen::VectorXd thicknessSize;
  Eigen::VectorXd targetSize;
  double resolvedSurfaceError = 0.0;
  bool allFinite = true;
};

namespace adaptive_target_size_detail {

std::pair<int, int> canonical_edge(const int a, const int b);

Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex);

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b);

Eigen::RowVector3d face_normal(const Eigen::MatrixXd &vertices,
                                      const Eigen::MatrixXi &faces,
                                      const int face);

double percentile(std::vector<double> values, const double q);

double robust_positive_scale(std::vector<double> values);

Eigen::VectorXd robust_normalize(const Eigen::VectorXd &values,
                                        const int count);

std::vector<std::vector<std::pair<int, double>>>
vertex_graph(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
             std::vector<std::pair<int, int>> *edgesOut = nullptr);

std::vector<int> face_components_by_index(const Eigen::MatrixXi &faces);

Eigen::RowVector3d closest_point_on_triangle(
    const Eigen::RowVector3d &p, const Eigen::RowVector3d &a,
    const Eigen::RowVector3d &b, const Eigen::RowVector3d &c);

} // namespace adaptive_target_size_detail

IntrinsicGraphDistanceResult compute_intrinsic_graph_distances(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &sourceVertices);

Eigen::VectorXd estimate_vertex_feature_salience(
    const int vertexCount, const AdaptiveFeatureMap &featureMap);

Eigen::VectorXd estimate_dihedral_vertex_curvature(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces);

PrincipalVertexCurvatureResult estimate_principal_vertex_curvature(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const FaceCurvatureOptions &options = {});

LocalThicknessResult estimate_local_thickness(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const LocalThicknessOptions &options = {});

Eigen::VectorXd apply_size_gradation(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &sizes, const double ratio, const int maxPasses);

AdaptiveTargetSizeResult compute_adaptive_target_size(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const AdaptiveTargetSizeInput &input,
    const AdaptiveTargetSizeOptions &options = {});

AdaptiveTargetSizeResult compute_adaptive_target_size(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const AdaptiveFeatureMap &featureMap,
    const AdaptiveTargetSizeOptions &options = {},
    const LocalThicknessOptions &thicknessOptions = {});

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_ADAPTIVE_TARGET_SIZE_H
