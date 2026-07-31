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
#include <map>
#include <optional>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/validation/MeshValidator.h>
#include <directional/validation/SourceAuthoritativeMeshValidator.h>

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
  bool enforceOptimizerTimeGate = true;
  std::array<double, 12> lineSearchSteps = {
      1.0,       0.5,        0.25,       0.125,
      0.0625,    0.03125,    0.015625,   0.0078125,
      0.00390625, 0.001953125, 0.0009765625, 0.00048828125};
  double finiteDifferenceStep = 1.0e-6;
  bool enforceSourceAuthoritativeHardInvariants = true;
};

struct SurfaceFeatureCurveInterval {
  int curveId = -1;
  Eigen::RowVector3d start = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d end = Eigen::RowVector3d::Zero();
  int intervalId = -1;
  int order = 0;
  int sourceFace = -1;
  int component = -1;
  int sheet = -1;
  double parameterStart = 0.0;
  double parameterEnd = 1.0;
  bool curveClosed = false;
  int railId = -1;
};

struct SurfaceOptimizationConstraints {
  Eigen::MatrixXd sourceVertices;
  Eigen::MatrixXi sourceFaces;
  Eigen::MatrixXd sourcePositions;
  Eigen::MatrixXd sourceNormals;
  Eigen::MatrixXd sourceFieldX;
  Eigen::MatrixXd sourceFieldY;
  Eigen::VectorXi sourceComponent;
  std::vector<int> sourceFaceComponent;
  std::vector<int> sourceFaceSheet;
  std::vector<std::vector<int>> sourceVertexFaces;
  std::map<std::pair<int, int>, std::vector<int>> sourceEdgeFaces;
  Eigen::VectorXd localTargetSize;
  std::vector<int> fixedVertices;
  std::vector<int> featureVertices;
  std::vector<int> softFeatureVertices;
  std::vector<std::pair<Eigen::RowVector3d, Eigen::RowVector3d>> featureIntervals;
  std::vector<SurfaceFeatureCurveInterval> featureCurveIntervals;
  Eigen::VectorXi featureCurveIds;
  Eigen::VectorXi featureRailIds;
  Eigen::VectorXi featureIntervalIds;
  Eigen::VectorXd featureParameters;
  std::vector<int> orderedFeatureVertices;
  std::vector<SurfacePoint> vertexProvenance;
  std::set<std::pair<int, int>> authoritativeBoundaryEdges;
  std::vector<int> authoritativeBoundaryLoop;
  std::vector<std::vector<int>> authoritativeBoundaryLoops;
  std::vector<std::vector<int>> authoritativeFeatureRails;
  std::size_t requiredFeatureRailCount = 0;
  // Distinguishes an explicitly supplied empty authority set from callers
  // that never configured feature-rail authority. An empty authoritative set
  // is still meaningful: it proves that no hard feature rails are expected.
  bool featureRailAuthorityProvided = false;
  bool requireSourceAuthoritativeValidation = false;
  // Optional output-vertex valence contracts. Boundary targets override the
  // geometric boundary-corner inference used by P21. Required singularity
  // targets are authoritative and must match exactly when supplied.
  std::map<int, int> boundaryValenceTargets;
  std::map<int, int> requiredSingularityValenceTargets;
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

struct SurfaceOptimizationGradient {
  Eigen::MatrixXd surface;
  Eigen::MatrixXd normal;
  Eigen::MatrixXd field;
  Eigen::MatrixXd orthogonality;
  Eigen::MatrixXd size;
  Eigen::MatrixXd valenceShape;
  Eigen::MatrixXd feature;
  Eigen::MatrixXd total;
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
  std::vector<SurfacePoint> vertexProvenance;
  std::vector<SurfaceOptimizationIteration> iterations;
  std::uint64_t topologyHash = 0;
  bool monotonicEnergy = true;
  bool topologyHashFixed = true;
  bool featureParametersOrdered = true;
  bool projectionStayedOnComponents = true;
  bool projectionStayedOnSheets = true;
  bool projectionHasCompleteProvenance = true;
  bool sourceTriangleProjectionUsed = false;
  bool directGradientUsed = false;
  std::size_t directGradientEvaluationCount = 0;
  std::size_t sourceBvhBuildCount = 0;
  std::size_t projectionQueryCount = 0;
  std::size_t lineSearchTrialCount = 0;
  std::size_t lineSearchRejectionCount = 0;
  std::size_t projectionConstraintRejectionCount = 0;
  std::size_t orientationRejectionCount = 0;
  std::size_t armijoRejectionCount = 0;
  std::size_t hardInvariantRejectionCount = 0;
  bool rolledBackToInput = false;
  SurfaceOptimizationEnergy initialEnergy;
  SurfaceOptimizationEnergy finalEnergy;
};

struct SurfaceQuadQualityMetrics {
  bool convex = true;
  double signedScaledJacobian = 1.0;
  double warpageDegrees = 0.0;
  double minimumAngleDegrees = 90.0;
  double maximumAngleDegrees = 90.0;
  double aspectRatio = 1.0;
};

struct SurfaceFinalValidationReport {
  bool accepted = false;
  // Bidirectional, locally normalized surface approximation errors.
  double quadToSourceP95 = 0.0;
  double quadToSourceMax = 0.0;
  double sourceToOutputP95 = 0.0;
  double sourceToOutputMax = 0.0;
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
  double angleMinDegrees = 90.0;
  double angleMaxDegrees = 90.0;
  double angleP5Degrees = 90.0;
  double angleP95Degrees = 90.0;
  double warpageP95Degrees = 0.0;
  double warpageMaxDegrees = 0.0;
  double aspectP95 = 1.0;
  double aspectP99 = 1.0;
  double scaledJacobianMin = 1.0;
  double scaledJacobianP5 = 1.0;
  int tJunctions = 0;
  int nonManifold = 0;
  int degenerate = 0;
  int inverted = 0;
  int selfIntersecting = 0;
  int nonConvex = 0;
  int boundaryValenceTargetCount = 0;
  int boundaryValenceMismatchCount = 0;
  int requiredSingularityValenceTargetCount = 0;
  int requiredSingularityValenceMismatchCount = 0;
  std::size_t quadToSourceSampleCount = 0;
  std::size_t sourceToOutputSampleCount = 0;
  bool topologyHashFixed = true;
  bool featureParametersOrdered = true;
  bool projectionStayedOnComponents = true;
  bool optimizerTimeWithinGate = true;
  bool strictValidationUsed = false;
  bool authoritativeBoundaryUsed = false;
  bool authoritativeFeatureRailsUsed = false;
  bool provenanceValidationUsed = false;
  bool sourceAuthoritativeValidationUsed = false;
  bool spatialAccelerationUsed = false;
  bool orderedBoundaryCyclesPassed = false;
  bool authoritativeFeatureRailsPassed = false;
  bool localSheetCompatibilityPassed = false;
  int connectedComponentMismatchCount = 0;
  int eulerCharacteristicMismatchCount = 0;
  int boundaryCycleMismatchCount = 0;
  int featureRailMismatchCount = 0;
  int provenanceFailureCount = 0;
  int localSheetMismatchCount = 0;
  int duplicateFaceCount = 0;
  int bowTieVertexCount = 0;
};

struct SurfaceOptimizationOverlay {
  Eigen::MatrixXd wireframeStarts;
  Eigen::MatrixXd wireframeEnds;
  Eigen::MatrixXd shadedVertices;
  Eigen::VectorXd surfaceError;
  Eigen::VectorXd sourceToOutputError;
  Eigen::VectorXd normalError;
  Eigen::VectorXd fieldAlignmentError;
  Eigen::VectorXd sizeRatio;
  Eigen::VectorXi poleValence;
  Eigen::VectorXi targetValence;
  Eigen::VectorXi valenceError;
};

namespace surface_optimizer_detail {

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool contains(const std::vector<int> &values, const int value) {
  return std::find(values.begin(), values.end(), value) != values.end();
}
#else
bool contains(const std::vector<int> &values, const int value);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool armijo_sufficient_decrease(const double currentEnergy,
                                       const double trialEnergy,
                                       const double alpha,
                                       const double directionSquaredNorm,
                                       const double armijo) {
  return trialEnergy <=
         currentEnergy - armijo * alpha * directionSquaredNorm;
}
#else
bool armijo_sufficient_decrease(const double currentEnergy,
                                       const double trialEnergy,
                                       const double alpha,
                                       const double directionSquaredNorm,
                                       const double armijo);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v) {
  const double n = v.norm();
  if (n <= 0.0) {
    return Eigen::RowVector3d::Zero();
  }
  return v / n;
}
#else
Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d tangent_direction(
    const Eigen::RowVector3d &vector,
    const Eigen::RowVector3d &surfaceNormal) {
  const Eigen::RowVector3d normal = normalized_or_zero(surfaceNormal);
  if (normal.squaredNorm() == 0.0) {
    return normalized_or_zero(vector);
  }
  return normalized_or_zero(vector - vector.dot(normal) * normal);
}
#else
Eigen::RowVector3d tangent_direction(
    const Eigen::RowVector3d &vector,
    const Eigen::RowVector3d &surfaceNormal);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}
#else
Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::uint64_t topology_hash(const Eigen::MatrixXi &quads) {
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
#else
std::uint64_t topology_hash(const Eigen::MatrixXi &quads);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d project_to_interval(const Eigen::RowVector3d &p,
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
#else
Eigen::RowVector3d project_to_interval(const Eigen::RowVector3d &p,
                                              const Eigen::RowVector3d &a,
                                              const Eigen::RowVector3d &b,
                                              double *parameter = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d project_to_source(const Eigen::RowVector3d &p,
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
#else
Eigen::RowVector3d project_to_source(const Eigen::RowVector3d &p,
                                            const Eigen::MatrixXd &source,
                                            int *component,
                                            const Eigen::VectorXi &components);
#endif

struct SourceProjectionCache {
  explicit SourceProjectionCache(
      const SurfaceOptimizationConstraints &constraints)
      : constraints(&constraints) {
    if (constraints.sourceVertices.rows() > 0 &&
        constraints.sourceFaces.rows() > 0 &&
        constraints.sourceVertices.cols() == 3 &&
        constraints.sourceFaces.cols() == 3) {
      bvh.emplace(constraints.sourceVertices, constraints.sourceFaces);
    }
  }

  [[nodiscard]] const std::vector<unsigned char> *allowed_faces(
      const int requiredComponent, const int requiredSheet) {
    if (!bvh.has_value() ||
        (requiredComponent < 0 && requiredSheet < 0)) {
      return nullptr;
    }
    const std::pair<int, int> key{requiredComponent, requiredSheet};
    const auto existing = allowedFaceMasks.find(key);
    if (existing != allowedFaceMasks.end()) {
      return &existing->second;
    }

    std::vector<unsigned char> mask(
        static_cast<std::size_t>(constraints->sourceFaces.rows()), 1);
    const bool componentsComplete =
        constraints->sourceFaceComponent.size() ==
        static_cast<std::size_t>(constraints->sourceFaces.rows());
    const bool sheetsComplete =
        constraints->sourceFaceSheet.size() ==
        static_cast<std::size_t>(constraints->sourceFaces.rows());
    for (int face = 0; face < constraints->sourceFaces.rows(); ++face) {
      if (requiredComponent >= 0 &&
          (!componentsComplete ||
           constraints->sourceFaceComponent[static_cast<std::size_t>(face)] !=
               requiredComponent)) {
        mask[static_cast<std::size_t>(face)] = 0;
      }
      if (requiredSheet >= 0 &&
          (!sheetsComplete ||
           constraints->sourceFaceSheet[static_cast<std::size_t>(face)] !=
               requiredSheet)) {
        mask[static_cast<std::size_t>(face)] = 0;
      }
    }
    return &allowedFaceMasks.emplace(key, std::move(mask)).first->second;
  }

  [[nodiscard]] SurfacePoint project(const Eigen::RowVector3d &point,
                                     const int requiredComponent = -1,
                                     const int requiredSheet = -1) {
    ++queryCount;
    if (!bvh.has_value()) {
      return {};
    }
    SurfaceProjectionOptions options;
    options.allowedFaces = allowed_faces(requiredComponent, requiredSheet);
    if (constraints->sourceFaceComponent.size() ==
        static_cast<std::size_t>(constraints->sourceFaces.rows())) {
      options.faceComponents = &constraints->sourceFaceComponent;
    }
    if (constraints->sourceFaceSheet.size() ==
        static_cast<std::size_t>(constraints->sourceFaces.rows())) {
      options.faceSheets = &constraints->sourceFaceSheet;
    }
    return bvh->project(point.transpose(), options);
  }

  const SurfaceOptimizationConstraints *constraints = nullptr;
  std::optional<SurfaceProjectionBvh> bvh;
  std::map<std::pair<int, int>, std::vector<unsigned char>> allowedFaceMasks;
  std::size_t queryCount = 0;
};

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d source_point_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfacePoint &point) {
  if (!point.valid() || point.face < 0 || point.face >= faces.rows() ||
      faces.cols() != 3) {
    return point.position.transpose();
  }
  Eigen::RowVector3d p = Eigen::RowVector3d::Zero();
  for (int c = 0; c < 3; ++c) {
    const int vertex = faces(point.face, c);
    if (vertex >= 0 && vertex < vertices.rows()) {
      p += point.barycentric(c) * vertices.row(vertex);
    }
  }
  return p;
}
#else
Eigen::RowVector3d source_point_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfacePoint &point);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfacePoint nearest_source_point(
    const Eigen::RowVector3d &p, const SurfaceOptimizationConstraints &constraints,
    const int requiredComponent = -1, const int requiredSheet = -1,
    SourceProjectionCache *projectionCache = nullptr) {
  SurfacePoint projected;
  if (constraints.sourceVertices.rows() > 0 &&
      constraints.sourceFaces.rows() > 0 &&
      constraints.sourceFaces.cols() == 3) {
    SourceProjectionCache localCache(constraints);
    SourceProjectionCache *cache =
        projectionCache != nullptr ? projectionCache : &localCache;
    projected = cache->project(p, requiredComponent, requiredSheet);
    if (projected.valid()) {
      return projected;
    }
    // A triangle source is authoritative. Do not fall back to an unconstrained
    // point cloud when the requested component or sheet has no valid face.
    return projected;
  }

  int component = requiredComponent;
  projected.position =
      project_to_source(p, constraints.sourcePositions, &component,
                        constraints.sourceComponent)
          .transpose();
  projected.face = constraints.sourcePositions.rows() > 0 ? 0 : -1;
  projected.component = component;
  projected.sheet = requiredSheet;
  projected.barycentric << 1.0, 0.0, 0.0;
  projected.squaredDistance = (projected.position - p.transpose()).squaredNorm();
  return projected;
}
#else
SurfacePoint nearest_source_point(
    const Eigen::RowVector3d &p, const SurfaceOptimizationConstraints &constraints,
    const int requiredComponent = -1, const int requiredSheet = -1,
    SourceProjectionCache *projectionCache = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
int feature_curve_for_vertex(const SurfaceOptimizationConstraints &constraints,
                                    const int vertex) {
  if (constraints.featureCurveIds.size() == 0 ||
      vertex < 0 || vertex >= constraints.featureCurveIds.size()) {
    return vertex;
  }
  return constraints.featureCurveIds(vertex);
}
#else
int feature_curve_for_vertex(const SurfaceOptimizationConstraints &constraints,
                                    const int vertex);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
int feature_sequence_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex) {
  if (constraints.featureRailIds.size() > 0 && vertex >= 0 &&
      vertex < constraints.featureRailIds.size() &&
      constraints.featureRailIds(vertex) >= 0) {
    return constraints.featureRailIds(vertex);
  }
  return feature_curve_for_vertex(constraints, vertex);
}
#else
int feature_sequence_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
int feature_interval_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex) {
  if (constraints.featureIntervalIds.size() == 0 || vertex < 0 ||
      vertex >= constraints.featureIntervalIds.size()) {
    return -1;
  }
  return constraints.featureIntervalIds(vertex);
}
#else
int feature_interval_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex);
#endif

struct SurfaceFeatureProjection {
  bool valid = false;
  int curveId = -1;
  int intervalId = -1;
  int intervalOrder = 0;
  double localParameter = 0.0;
  double orderCoordinate = 0.0;
  double parameter = 0.0;
  double squaredDistance = std::numeric_limits<double>::infinity();
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d tangent = Eigen::RowVector3d::Zero();
};

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceFeatureProjection project_to_feature_curve(
    const Eigen::RowVector3d &point,
    const SurfaceOptimizationConstraints &constraints, const int vertex) {
  SurfaceFeatureProjection best;
  const int curveId = feature_curve_for_vertex(constraints, vertex);
  const int requiredInterval = feature_interval_for_vertex(constraints, vertex);
  for (const SurfaceFeatureCurveInterval &interval :
       constraints.featureCurveIntervals) {
    if (interval.curveId != curveId ||
        (requiredInterval >= 0 && interval.intervalId != requiredInterval)) {
      continue;
    }
    double localParameter = 0.0;
    const Eigen::RowVector3d projected = project_to_interval(
        point, interval.start, interval.end, &localParameter);
    const double curveParameter =
        interval.parameterStart +
        localParameter * (interval.parameterEnd - interval.parameterStart);
    const double distance = (point - projected).squaredNorm();
    const bool better =
        !best.valid || distance + 1.0e-24 < best.squaredDistance ||
        (std::abs(distance - best.squaredDistance) <= 1.0e-24 &&
         std::pair<int, int>{interval.order, interval.intervalId} <
             std::pair<int, int>{best.intervalOrder, best.intervalId});
    if (!better) {
      continue;
    }
    best.valid = true;
    best.curveId = interval.curveId;
    best.intervalId = interval.intervalId;
    best.intervalOrder = interval.order;
    best.localParameter = localParameter;
    best.orderCoordinate =
        static_cast<double>(interval.order) + localParameter;
    best.parameter = curveParameter;
    best.squaredDistance = distance;
    best.position = projected;
    best.tangent = interval.end - interval.start;
  }

  if (best.valid) {
    return best;
  }

  const int legacyIndex =
      vertex >= 0 && vertex < static_cast<int>(constraints.featureIntervals.size())
          ? vertex
          : -1;
  if (legacyIndex >= 0) {
    double parameter = 0.0;
    best.valid = true;
    best.curveId = curveId;
    best.intervalId = legacyIndex;
    best.intervalOrder = legacyIndex;
    best.position = project_to_interval(
        point, constraints.featureIntervals[static_cast<std::size_t>(legacyIndex)].first,
        constraints.featureIntervals[static_cast<std::size_t>(legacyIndex)].second,
        &parameter);
    best.localParameter = parameter;
    best.orderCoordinate = parameter;
    best.parameter = parameter;
    best.squaredDistance = (point - best.position).squaredNorm();
    best.tangent =
        constraints.featureIntervals[static_cast<std::size_t>(legacyIndex)].second -
        constraints.featureIntervals[static_cast<std::size_t>(legacyIndex)].first;
  }
  return best;
}
#else
SurfaceFeatureProjection project_to_feature_curve(
    const Eigen::RowVector3d &point,
    const SurfaceOptimizationConstraints &constraints, const int vertex);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool find_feature_interval(
    const SurfaceOptimizationConstraints &constraints, const int vertex,
    Eigen::RowVector3d *start, Eigen::RowVector3d *end) {
  const int curveId = feature_curve_for_vertex(constraints, vertex);
  const int intervalId = feature_interval_for_vertex(constraints, vertex);
  for (const SurfaceFeatureCurveInterval &interval :
       constraints.featureCurveIntervals) {
    if (interval.curveId == curveId &&
        (intervalId < 0 || interval.intervalId == intervalId)) {
      if (start != nullptr) {
        *start = interval.start;
      }
      if (end != nullptr) {
        *end = interval.end;
      }
      return true;
    }
  }
  const int legacyIndex = vertex >= 0 &&
                                  vertex < static_cast<int>(
                                               constraints.featureIntervals.size())
                              ? vertex
                              : -1;
  if (legacyIndex >= 0) {
    if (start != nullptr) {
      *start = constraints.featureIntervals[legacyIndex].first;
    }
    if (end != nullptr) {
      *end = constraints.featureIntervals[legacyIndex].second;
    }
    return true;
  }
  return false;
}
#else
bool find_feature_interval(
    const SurfaceOptimizationConstraints &constraints, const int vertex,
    Eigen::RowVector3d *start, Eigen::RowVector3d *end);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d local_source_normal(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace) {
  if (point.valid() && point.face >= 0 &&
      point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3) {
    if (constraints.sourceNormals.rows() == constraints.sourceVertices.rows()) {
      Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = constraints.sourceFaces(point.face, corner);
        if (vertex >= 0 && vertex < constraints.sourceNormals.rows()) {
          normal += point.barycentric(corner) *
                    constraints.sourceNormals.row(vertex);
        }
      }
      const Eigen::RowVector3d interpolated = normalized_or_zero(normal);
      if (interpolated.squaredNorm() > 0.0) {
        return interpolated;
      }
    }
    if (constraints.sourceNormals.rows() == constraints.sourceFaces.rows()) {
      const Eigen::RowVector3d normal =
          normalized_or_zero(constraints.sourceNormals.row(point.face));
      if (normal.squaredNorm() > 0.0) {
        return normal;
      }
    }
    if (constraints.sourceVertices.rows() > 0) {
      const int ia = constraints.sourceFaces(point.face, 0);
      const int ib = constraints.sourceFaces(point.face, 1);
      const int ic = constraints.sourceFaces(point.face, 2);
      if (ia >= 0 && ib >= 0 && ic >= 0 &&
          ia < constraints.sourceVertices.rows() &&
          ib < constraints.sourceVertices.rows() &&
          ic < constraints.sourceVertices.rows()) {
        const Eigen::RowVector3d normal = normalized_or_zero(cross3(
            constraints.sourceVertices.row(ib) -
                constraints.sourceVertices.row(ia),
            constraints.sourceVertices.row(ic) -
                constraints.sourceVertices.row(ia)));
        if (normal.squaredNorm() > 0.0) {
          return normal;
        }
      }
    }
  }
  if (constraints.sourceNormals.rows() > 0) {
    return normalized_or_zero(
        constraints.sourceNormals.row(std::clamp(fallbackFace, 0,
                                                 static_cast<int>(
                                                     constraints.sourceNormals.rows()) -
                                                     1)));
  }
  return {0.0, 0.0, 1.0};
}
#else
Eigen::RowVector3d local_source_normal(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace);
#endif

struct LocalSourceCross {
  Eigen::RowVector3d x = {1.0, 0.0, 0.0};
  Eigen::RowVector3d y = {0.0, 1.0, 0.0};
};

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d tangent_reference(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::RowVector3d &normal) {
  Eigen::RowVector3d reference = Eigen::RowVector3d::Zero();
  if (point.valid() && point.face >= 0 &&
      point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3) {
    const int a = constraints.sourceFaces(point.face, 0);
    const int b = constraints.sourceFaces(point.face, 1);
    if (a >= 0 && b >= 0 && a < constraints.sourceVertices.rows() &&
        b < constraints.sourceVertices.rows()) {
      reference = constraints.sourceVertices.row(b) -
                  constraints.sourceVertices.row(a);
    }
  }
  reference -= reference.dot(normal) * normal;
  reference = normalized_or_zero(reference);
  if (reference.squaredNorm() == 0.0) {
    const Eigen::RowVector3d axis =
        std::abs(normal.x()) < 0.8 ? Eigen::RowVector3d(1.0, 0.0, 0.0)
                                   : Eigen::RowVector3d(0.0, 1.0, 0.0);
    reference = normalized_or_zero(axis - axis.dot(normal) * normal);
  }
  return reference;
}
#else
Eigen::RowVector3d tangent_reference(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::RowVector3d &normal);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
LocalSourceCross local_source_cross(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace) {
  const Eigen::RowVector3d normal =
      local_source_normal(constraints, point, fallbackFace);
  const Eigen::RowVector3d basisX =
      tangent_reference(constraints, point, normal);
  const Eigen::RowVector3d basisY = normalized_or_zero(cross3(normal, basisX));

  const bool vertexField =
      point.valid() && point.face >= 0 &&
      point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3 &&
      constraints.sourceFieldX.rows() == constraints.sourceVertices.rows();
  if (vertexField) {
    std::complex<double> power(0.0, 0.0);
    double totalWeight = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = constraints.sourceFaces(point.face, corner);
      if (vertex < 0 || vertex >= constraints.sourceFieldX.rows()) {
        continue;
      }
      Eigen::RowVector3d direction = constraints.sourceFieldX.row(vertex);
      direction -= direction.dot(normal) * normal;
      direction = normalized_or_zero(direction);
      if (direction.squaredNorm() == 0.0) {
        continue;
      }
      const double angle =
          std::atan2(direction.dot(basisY), direction.dot(basisX));
      const double weight = std::max(0.0, point.barycentric(corner));
      power += weight *
               std::complex<double>(std::cos(4.0 * angle),
                                    std::sin(4.0 * angle));
      totalWeight += weight;
    }
    if (totalWeight > 0.0 && std::abs(power) > 1.0e-15) {
      const double angle = 0.25 * std::arg(power);
      LocalSourceCross cross;
      cross.x = normalized_or_zero(std::cos(angle) * basisX +
                                   std::sin(angle) * basisY);
      cross.y = normalized_or_zero(cross3(normal, cross.x));
      return cross;
    }
  }

  Eigen::RowVector3d x = basisX;
  if (point.valid() && constraints.sourceFieldX.rows() ==
                           constraints.sourceFaces.rows() &&
      point.face >= 0 && point.face < constraints.sourceFieldX.rows()) {
    x = constraints.sourceFieldX.row(point.face);
  } else if (constraints.sourceFieldX.rows() > 0) {
    x = constraints.sourceFieldX.row(std::clamp(
        fallbackFace, 0, static_cast<int>(constraints.sourceFieldX.rows()) - 1));
  }
  x -= x.dot(normal) * normal;
  x = normalized_or_zero(x);
  if (x.squaredNorm() == 0.0) {
    x = basisX;
  }
  LocalSourceCross cross;
  cross.x = x;
  cross.y = normalized_or_zero(cross3(normal, x));
  return cross;
}
#else
LocalSourceCross local_source_cross(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::vector<int> compatible_source_field_charts(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point) {
  std::vector<int> charts;
  if (!point.valid() || point.face < 0 ||
      point.face >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      constraints.sourceFieldX.rows() != constraints.sourceFaces.rows()) {
    return charts;
  }

  std::vector<int> supportCorners;
  for (int corner = 0; corner < 3; ++corner) {
    if (point.barycentric(corner) > 1.0e-8) {
      supportCorners.push_back(corner);
    }
  }
  if (supportCorners.size() == 1U) {
    const int vertex =
        constraints.sourceFaces(point.face, supportCorners.front());
    if (vertex >= 0 &&
        vertex < static_cast<int>(constraints.sourceVertexFaces.size())) {
      charts = constraints.sourceVertexFaces[static_cast<std::size_t>(vertex)];
    }
  } else if (supportCorners.size() == 2U) {
    const int first =
        constraints.sourceFaces(point.face, supportCorners[0]);
    const int second =
        constraints.sourceFaces(point.face, supportCorners[1]);
    const auto found =
        constraints.sourceEdgeFaces.find(std::minmax(first, second));
    if (found != constraints.sourceEdgeFaces.end()) {
      charts = found->second;
    }
  }
  if (charts.empty()) {
    charts.push_back(point.face);
  } else if (std::find(charts.begin(), charts.end(), point.face) ==
             charts.end()) {
    charts.push_back(point.face);
  }

  charts.erase(
      std::remove_if(charts.begin(), charts.end(), [&](const int face) {
        return face < 0 || face >= constraints.sourceFaces.rows();
      }),
      charts.end());
  std::sort(charts.begin(), charts.end());
  charts.erase(std::unique(charts.begin(), charts.end()), charts.end());
  return charts;
}
#else
std::vector<int> compatible_source_field_charts(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double best_source_field_alignment(
    const Eigen::RowVector3d &edge,
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point, const int fallbackFace,
    const SurfacePoint *firstEndpoint = nullptr,
    const SurfacePoint *secondEndpoint = nullptr) {
  std::vector<int> charts =
      compatible_source_field_charts(constraints, point);
  if (firstEndpoint != nullptr && secondEndpoint != nullptr) {
    const std::vector<int> firstCharts =
        compatible_source_field_charts(constraints, *firstEndpoint);
    const std::vector<int> secondCharts =
        compatible_source_field_charts(constraints, *secondEndpoint);
    std::vector<int> commonCharts;
    std::set_intersection(firstCharts.begin(), firstCharts.end(),
                          secondCharts.begin(), secondCharts.end(),
                          std::back_inserter(commonCharts));
    if (!commonCharts.empty()) {
      charts = std::move(commonCharts);
    }
  }
  if (charts.empty()) {
    charts.push_back(point.valid() ? point.face : fallbackFace);
  }
  double best = 0.0;
  for (const int chart : charts) {
    SurfacePoint chartPoint = point;
    chartPoint.face = chart;
    const LocalSourceCross cross =
        local_source_cross(constraints, chartPoint, fallbackFace);
    const Eigen::RowVector3d normal =
        local_source_normal(constraints, chartPoint, fallbackFace);
    const Eigen::RowVector3d direction = tangent_direction(edge, normal);
    best = std::max(
        best, std::max(std::abs(direction.dot(cross.x)),
                       std::abs(direction.dot(cross.y))));
  }
  return std::clamp(best, 0.0, 1.0);
}
#else
double best_source_field_alignment(
    const Eigen::RowVector3d &edge,
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point, const int fallbackFace,
    const SurfacePoint *firstEndpoint = nullptr,
    const SurfacePoint *secondEndpoint = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d source_triangle_scalar_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::VectorXd &values) {
  if (!point.valid() || point.face < 0 ||
      point.face >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      constraints.sourceVertices.cols() != 3 ||
      values.size() != constraints.sourceVertices.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  const int i0 = constraints.sourceFaces(point.face, 0);
  const int i1 = constraints.sourceFaces(point.face, 1);
  const int i2 = constraints.sourceFaces(point.face, 2);
  if (i0 < 0 || i1 < 0 || i2 < 0 ||
      i0 >= constraints.sourceVertices.rows() ||
      i1 >= constraints.sourceVertices.rows() ||
      i2 >= constraints.sourceVertices.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  const Eigen::RowVector3d e1 =
      constraints.sourceVertices.row(i1) - constraints.sourceVertices.row(i0);
  const Eigen::RowVector3d e2 =
      constraints.sourceVertices.row(i2) - constraints.sourceVertices.row(i0);
  Eigen::Matrix2d gram;
  gram << e1.dot(e1), e1.dot(e2),
      e1.dot(e2), e2.dot(e2);
  const double determinant = gram.determinant();
  if (std::abs(determinant) <= 1.0e-24) {
    return Eigen::RowVector3d::Zero();
  }
  Eigen::Vector2d difference;
  difference << values(i1) - values(i0), values(i2) - values(i0);
  const Eigen::Vector2d coefficients = gram.inverse() * difference;
  return coefficients(0) * e1 + coefficients(1) * e2;
}
#else
Eigen::RowVector3d source_triangle_scalar_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::VectorXd &values);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d local_target_size_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point) {
  if (constraints.localTargetSize.size() !=
      constraints.sourceVertices.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  return source_triangle_scalar_gradient(constraints, point,
                                         constraints.localTargetSize);
}
#else
Eigen::RowVector3d local_target_size_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double local_target_size(const SurfaceOptimizationConstraints &constraints,
                                const SurfacePoint &point,
                                const int fallbackVertex,
                                const double globalTargetSize) {
  if (point.valid() &&
      point.face >= 0 && point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3) {
    if (constraints.localTargetSize.size() ==
        constraints.sourceVertices.rows()) {
      double target = 0.0;
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = constraints.sourceFaces(point.face, corner);
        if (vertex >= 0 && vertex < constraints.localTargetSize.size()) {
          target += point.barycentric(corner) *
                    constraints.localTargetSize(vertex);
        }
      }
      if (target > 0.0) {
        return std::max(1.0e-12, target);
      }
    }
    if (constraints.localTargetSize.size() == constraints.sourceFaces.rows()) {
      return std::max(1.0e-12, constraints.localTargetSize(point.face));
    }
  }
  if (constraints.localTargetSize.size() > fallbackVertex &&
      fallbackVertex >= 0) {
    return std::max(1.0e-12, constraints.localTargetSize(fallbackVertex));
  }
  return std::max(1.0e-12, globalTargetSize);
}
#else
double local_target_size(const SurfaceOptimizationConstraints &constraints,
                                const SurfacePoint &point,
                                const int fallbackVertex,
                                const double globalTargetSize);
#endif

inline constexpr double kMaxImmutableRailSizeRatio = 4.0;

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool immutable_rail_edge(
    const SurfaceOptimizationConstraints &constraints, const int firstVertex,
    const int secondVertex) {
  if (firstVertex < 0 || secondVertex < 0 ||
      !contains(constraints.fixedVertices, firstVertex) ||
      !contains(constraints.fixedVertices, secondVertex) ||
      !contains(constraints.featureVertices, firstVertex) ||
      !contains(constraints.featureVertices, secondVertex) ||
      constraints.featureRailIds.size() <= firstVertex ||
      constraints.featureRailIds.size() <= secondVertex) {
    return false;
  }
  const int firstRail = constraints.featureRailIds(firstVertex);
  const int secondRail = constraints.featureRailIds(secondVertex);
  return firstRail >= 0 && firstRail == secondRail;
}
#else
bool immutable_rail_edge(
    const SurfaceOptimizationConstraints &constraints, const int firstVertex,
    const int secondVertex);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double effective_edge_target_size(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &firstPoint, const SurfacePoint &secondPoint,
    const int firstVertex, const int secondVertex, const double edgeLength,
    const double globalTargetSize) {
  const double localTarget =
      0.5 * (local_target_size(constraints, firstPoint, firstVertex,
                               globalTargetSize) +
             local_target_size(constraints, secondPoint, secondVertex,
                               globalTargetSize));
  // A rail segment whose endpoints are both fixed has no positional degree of
  // freedom. For a bounded mismatch, treat its realized length as the feasible
  // target rather than asking the optimizer to violate an authoritative rail.
  // Extreme target-size requests remain observable and fail validation.
  if (immutable_rail_edge(constraints, firstVertex, secondVertex)) {
    const double safeLength = std::max(1.0e-12, edgeLength);
    const double safeTarget = std::max(1.0e-12, localTarget);
    const double mismatch =
        std::max(safeLength / safeTarget, safeTarget / safeLength);
    if (mismatch <= kMaxImmutableRailSizeRatio) {
      return safeLength;
    }
  }
  return localTarget;
}
#else
double effective_edge_target_size(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &firstPoint, const SurfacePoint &secondPoint,
    const int firstVertex, const int secondVertex, const double edgeLength,
    const double globalTargetSize);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool provenance_is_complete(
    const SurfacePoint &point,
    const SurfaceOptimizationConstraints &constraints) {
  if (!point.valid() || !point.position.allFinite() ||
      !point.barycentric.allFinite()) {
    return false;
  }
  const double barycentricSum = point.barycentric.sum();
  if (std::abs(barycentricSum - 1.0) > 1.0e-8 ||
      point.barycentric.minCoeff() < -1.0e-10 ||
      point.barycentric.maxCoeff() > 1.0 + 1.0e-10) {
    return false;
  }
  const bool componentsAuthoritative =
      constraints.sourceFaces.rows() > 0 &&
      constraints.sourceFaceComponent.size() ==
          static_cast<std::size_t>(constraints.sourceFaces.rows());
  const bool sheetsAuthoritative =
      constraints.sourceFaces.rows() > 0 &&
      constraints.sourceFaceSheet.size() ==
          static_cast<std::size_t>(constraints.sourceFaces.rows());
  return (!componentsAuthoritative || point.component >= 0) &&
         (!sheetsAuthoritative || point.sheet >= 0);
}
#else
bool provenance_is_complete(
    const SurfacePoint &point,
    const SurfaceOptimizationConstraints &constraints);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices, const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters = nullptr,
    bool *ordered = nullptr, bool *componentsOk = nullptr,
    bool *sheetsOk = nullptr, bool *completeProvenance = nullptr,
    std::vector<SurfacePoint> *provenance = nullptr,
    SourceProjectionCache *projectionCache = nullptr) {
  Eigen::MatrixXd projected = vertices;
  Eigen::VectorXd params = constraints.featureParameters;
  if (params.size() != vertices.rows()) {
    params = Eigen::VectorXd::Zero(vertices.rows());
  }
  Eigen::VectorXd orderCoordinates = params;
  bool orderOk = true;
  bool componentOk = true;
  bool sheetOk = true;
  bool provenanceComplete = true;
  SourceProjectionCache localCache(constraints);
  SourceProjectionCache *cache =
      projectionCache != nullptr ? projectionCache : &localCache;
  std::vector<SurfacePoint> projectedProvenance(
      static_cast<std::size_t>(vertices.rows()));
  for (int i = 0; i < vertices.rows(); ++i) {
    const int requiredComponent =
        i < static_cast<int>(constraints.vertexProvenance.size())
            ? constraints.vertexProvenance[static_cast<std::size_t>(i)].component
            : (constraints.sourceComponent.size() == vertices.rows()
                   ? constraints.sourceComponent(i)
                   : -1);
    const int requiredSheet =
        i < static_cast<int>(constraints.vertexProvenance.size())
            ? constraints.vertexProvenance[static_cast<std::size_t>(i)].sheet
            : -1;
    const bool fixed = contains(constraints.fixedVertices, i);
    const bool feature = contains(constraints.featureVertices, i);
    if (fixed) {
      Eigen::RowVector3d constrainedPoint = vertices.row(i);
      if (feature) {
        const SurfaceFeatureProjection featureProjection =
            project_to_feature_curve(constrainedPoint, constraints, i);
        if (featureProjection.valid) {
          constrainedPoint = featureProjection.position;
          params(i) = featureProjection.parameter;
          orderCoordinates(i) = featureProjection.orderCoordinate;
        } else {
          provenanceComplete = false;
        }
      }
      SurfacePoint source = nearest_source_point(
          constrainedPoint, constraints, requiredComponent, requiredSheet,
          cache);
      if (source.valid()) {
        projected.row(i) = source.position.transpose();
      }
      projectedProvenance[static_cast<std::size_t>(i)] = source;
      provenanceComplete =
          provenanceComplete && provenance_is_complete(source, constraints);
      if (requiredComponent >= 0 &&
          (!source.valid() || source.component != requiredComponent)) {
        componentOk = false;
      }
      if (requiredSheet >= 0 &&
          (!source.valid() || source.sheet != requiredSheet)) {
        sheetOk = false;
      }
      continue;
    }
    if (feature) {
      const SurfaceFeatureProjection feature =
          project_to_feature_curve(vertices.row(i), constraints, i);
      if (feature.valid) {
        projected.row(i) = feature.position;
        params(i) = feature.parameter;
        orderCoordinates(i) = feature.orderCoordinate;
      } else {
        provenanceComplete = false;
      }
      projectedProvenance[static_cast<std::size_t>(i)] =
          nearest_source_point(projected.row(i), constraints,
                               requiredComponent, requiredSheet, cache);
      const SurfacePoint &source =
          projectedProvenance[static_cast<std::size_t>(i)];
      provenanceComplete =
          provenanceComplete && provenance_is_complete(source, constraints);
      if (requiredComponent >= 0 &&
          (!source.valid() || source.component != requiredComponent)) {
        componentOk = false;
      }
      if (requiredSheet >= 0 &&
          (!source.valid() || source.sheet != requiredSheet)) {
        sheetOk = false;
      }
    } else {
      SurfacePoint source =
          nearest_source_point(vertices.row(i), constraints, requiredComponent,
                               requiredSheet, cache);
      if (source.valid()) {
        projected.row(i) = source.position.transpose();
      }
      projectedProvenance[static_cast<std::size_t>(i)] = source;
      provenanceComplete =
          provenanceComplete && provenance_is_complete(source, constraints);
      if (requiredComponent >= 0 &&
          (!source.valid() || source.component != requiredComponent)) {
        componentOk = false;
      }
      if (requiredSheet >= 0 &&
          (!source.valid() || source.sheet != requiredSheet)) {
        sheetOk = false;
      }
    }
  }
  std::vector<int> features = constraints.orderedFeatureVertices;
  if (features.empty()) {
    features = constraints.featureVertices;
  }
  int previousSequence = std::numeric_limits<int>::min();
  double previous = -std::numeric_limits<double>::infinity();
  for (const int v : features) {
    if (v >= 0 && v < params.size()) {
      const int sequenceId = feature_sequence_for_vertex(constraints, v);
      if (sequenceId != previousSequence) {
        previousSequence = sequenceId;
        previous = -std::numeric_limits<double>::infinity();
      }
      if (orderCoordinates(v) + 1.0e-12 < previous) {
        orderOk = false;
      }
      previous = orderCoordinates(v);
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
  if (sheetsOk != nullptr) {
    *sheetsOk = sheetOk;
  }
  if (completeProvenance != nullptr) {
    *completeProvenance = provenanceComplete;
  }
  if (provenance != nullptr) {
    *provenance = std::move(projectedProvenance);
  }
  return projected;
}
#else
Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices, const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters = nullptr,
    bool *ordered = nullptr, bool *componentsOk = nullptr,
    bool *sheetsOk = nullptr, bool *completeProvenance = nullptr,
    std::vector<SurfacePoint> *provenance = nullptr,
    SourceProjectionCache *projectionCache = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters, bool *ordered, bool *componentsOk,
    std::vector<SurfacePoint> *provenance) {
  return project_vertices(vertices, constraints, featureParameters, ordered,
                          componentsOk, nullptr, nullptr, provenance, nullptr);
}
#else
Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters, bool *ordered, bool *componentsOk,
    std::vector<SurfacePoint> *provenance);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d face_normal(const Eigen::MatrixXd &v,
                                      const Eigen::MatrixXi &q,
                                      const int face) {
  const Eigen::RowVector3d a = v.row(q(face, 0));
  const Eigen::RowVector3d b = v.row(q(face, 1));
  const Eigen::RowVector3d c = v.row(q(face, 2));
  return normalized_or_zero(cross3(b - a, c - a));
}
#else
Eigen::RowVector3d face_normal(const Eigen::MatrixXd &v,
                                      const Eigen::MatrixXi &q,
                                      const int face);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::vector<double> sorted_percentiles(std::vector<double> values) {
  std::sort(values.begin(), values.end());
  return values;
}
#else
std::vector<double> sorted_percentiles(std::vector<double> values);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double percentile(std::vector<double> values, const double p) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const int index = static_cast<int>(
      std::floor(std::clamp(p, 0.0, 1.0) * static_cast<double>(values.size() - 1)));
  return values[static_cast<std::size_t>(index)];
}
#else
double percentile(std::vector<double> values, const double p);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double angle_degrees(const Eigen::RowVector3d &a,
                            const Eigen::RowVector3d &b) {
  const Eigen::RowVector3d na = normalized_or_zero(a);
  const Eigen::RowVector3d nb = normalized_or_zero(b);
  const double dot = std::clamp(na.dot(nb), -1.0, 1.0);
  return std::acos(dot) * 180.0 / 3.14159265358979323846;
}
#else
double angle_degrees(const Eigen::RowVector3d &a,
                            const Eigen::RowVector3d &b);
#endif


#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::pair<int, int> consistent_component_sheet(
    const Eigen::MatrixXi &quads, const int face,
    const std::vector<SurfacePoint> &provenance,
    const SurfaceOptimizationConstraints *constraints = nullptr) {
  if (constraints != nullptr) {
    const validation::source_authoritative_detail::SourcePointLabelSupport
        labelSupport(&constraints->sourceFaces,
                     &constraints->sourceFaceComponent,
                     &constraints->sourceFaceSheet);
    if (labelSupport.available()) {
      std::set<std::pair<int, int>> commonLabels;
      bool firstPoint = true;
      for (int corner = 0; corner < 4; ++corner) {
        const int vertex = quads(face, corner);
        if (vertex < 0 || vertex >= static_cast<int>(provenance.size())) {
          commonLabels.clear();
          break;
        }
        const SurfacePoint &point =
            provenance[static_cast<std::size_t>(vertex)];
        const std::set<std::pair<int, int>> labels =
            labelSupport.supported_labels(point);
        if (labels.empty()) {
          commonLabels.clear();
          break;
        }
        if (point.component >= 0 && point.sheet >= 0 &&
            labels.count({point.component, point.sheet}) == 0U) {
          commonLabels.clear();
          break;
        }
        if (firstPoint) {
          commonLabels = labels;
          firstPoint = false;
        } else {
          std::set<std::pair<int, int>> intersection;
          std::set_intersection(
              commonLabels.begin(), commonLabels.end(), labels.begin(),
              labels.end(), std::inserter(intersection, intersection.end()));
          commonLabels = std::move(intersection);
        }
        if (commonLabels.empty()) {
          break;
        }
      }
      if (!commonLabels.empty()) {
        return *commonLabels.begin();
      }
    }
  }

  constexpr int incompatibleLabel = std::numeric_limits<int>::max();
  int component = -1;
  int sheet = -1;
  bool componentAssigned = false;
  bool sheetAssigned = false;
  for (int corner = 0; corner < 4; ++corner) {
    const int vertex = quads(face, corner);
    if (vertex < 0 || vertex >= static_cast<int>(provenance.size())) {
      continue;
    }
    const SurfacePoint &point = provenance[static_cast<std::size_t>(vertex)];
    if (!point.valid()) {
      continue;
    }
    if (point.component >= 0 && component != incompatibleLabel) {
      if (!componentAssigned) {
        component = point.component;
        componentAssigned = true;
      } else if (point.component != component) {
        component = incompatibleLabel;
      }
    }
    if (point.sheet >= 0 && sheet != incompatibleLabel) {
      if (!sheetAssigned) {
        sheet = point.sheet;
        sheetAssigned = true;
      } else if (point.sheet != sheet) {
        sheet = incompatibleLabel;
      }
    }
  }
  return {component, sheet};
}
#else
std::pair<int, int> consistent_component_sheet(
    const Eigen::MatrixXi &quads, const int face,
    const std::vector<SurfacePoint> &provenance,
    const SurfaceOptimizationConstraints *constraints = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfacePoint quad_reference_surface_point(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance,
    SourceProjectionCache *projectionCache = nullptr) {
  Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 4; ++corner) {
    centroid += 0.25 * vertices.row(quads(face, corner));
  }
  const auto [component, sheet] =
      consistent_component_sheet(quads, face, provenance, &constraints);
  SurfacePoint point = nearest_source_point(centroid, constraints, component,
                                            sheet, projectionCache);
  if (point.valid()) {
    return point;
  }
  for (int corner = 0; corner < 4; ++corner) {
    const int vertex = quads(face, corner);
    if (vertex >= 0 && vertex < static_cast<int>(provenance.size()) &&
        provenance[static_cast<std::size_t>(vertex)].valid()) {
      return provenance[static_cast<std::size_t>(vertex)];
    }
  }
  return {};
}
#else
SurfacePoint quad_reference_surface_point(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance,
    SourceProjectionCache *projectionCache = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d quad_bilinear_sample(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const double u, const double v) {
  const Eigen::RowVector3d p0 = vertices.row(quads(face, 0));
  const Eigen::RowVector3d p1 = vertices.row(quads(face, 1));
  const Eigen::RowVector3d p2 = vertices.row(quads(face, 2));
  const Eigen::RowVector3d p3 = vertices.row(quads(face, 3));
  return (1.0 - u) * (1.0 - v) * p0 + u * (1.0 - v) * p1 +
         u * v * p2 + (1.0 - u) * v * p3;
}
#else
Eigen::RowVector3d quad_bilinear_sample(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const double u, const double v);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::vector<Eigen::Vector3d> triangle_sample_barycentrics() {
  return {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},
          {0.5, 0.5, 0.0}, {0.0, 0.5, 0.5}, {0.5, 0.0, 0.5},
          {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0}};
}
#else
std::vector<Eigen::Vector3d> triangle_sample_barycentrics();
#endif

struct OutputProjectionCache {
  Eigen::MatrixXi triangles;
  std::vector<int> faceComponents;
  std::vector<int> faceSheets;
  std::optional<SurfaceProjectionBvh> bvh;
  std::map<std::pair<int, int>, std::vector<unsigned char>> masks;

  OutputProjectionCache(const Eigen::MatrixXd &vertices,
                         const Eigen::MatrixXi &quads,
                         const std::vector<SurfacePoint> &provenance,
                         const SurfaceOptimizationConstraints *constraints =
                             nullptr) {
    triangles.resize(2 * quads.rows(), 3);
    faceComponents.resize(static_cast<std::size_t>(2 * quads.rows()), -1);
    faceSheets.resize(static_cast<std::size_t>(2 * quads.rows()), -1);
    for (int face = 0; face < quads.rows(); ++face) {
      triangles.row(2 * face) << quads(face, 0), quads(face, 1), quads(face, 2);
      triangles.row(2 * face + 1) << quads(face, 0), quads(face, 2), quads(face, 3);
      const auto [component, sheet] =
          consistent_component_sheet(quads, face, provenance, constraints);
      faceComponents[static_cast<std::size_t>(2 * face)] = component;
      faceComponents[static_cast<std::size_t>(2 * face + 1)] = component;
      faceSheets[static_cast<std::size_t>(2 * face)] = sheet;
      faceSheets[static_cast<std::size_t>(2 * face + 1)] = sheet;
    }
    if (vertices.rows() > 0 && triangles.rows() > 0) {
      bvh.emplace(vertices, triangles);
    }
  }

  const std::vector<unsigned char> *allowed_faces(const int component,
                                                   const int sheet) {
    if (component < 0 && sheet < 0) {
      return nullptr;
    }
    const std::pair<int, int> key{component, sheet};
    const auto existing = masks.find(key);
    if (existing != masks.end()) {
      return &existing->second;
    }
    std::vector<unsigned char> mask(static_cast<std::size_t>(triangles.rows()), 1);
    for (int face = 0; face < triangles.rows(); ++face) {
      if (component >= 0 &&
          faceComponents[static_cast<std::size_t>(face)] != component) {
        mask[static_cast<std::size_t>(face)] = 0;
      }
      if (sheet >= 0 && faceSheets[static_cast<std::size_t>(face)] != sheet) {
        mask[static_cast<std::size_t>(face)] = 0;
      }
    }
    return &masks.emplace(key, std::move(mask)).first->second;
  }

  SurfacePoint project(const Eigen::RowVector3d &point, const int component,
                       const int sheet) {
    if (!bvh.has_value()) {
      return {};
    }
    SurfaceProjectionOptions options;
    options.allowedFaces = allowed_faces(component, sheet);
    options.faceComponents = &faceComponents;
    options.faceSheets = &faceSheets;
    return bvh->project(point.transpose(), options);
  }
};

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::map<std::pair<int, int>, int> quad_edge_incidence(
    const Eigen::MatrixXi &quads) {
  std::map<std::pair<int, int>, int> incidence;
  for (int face = 0; face < quads.rows(); ++face) {
    for (int corner = 0; corner < 4; ++corner) {
      int a = quads(face, corner);
      int b = quads(face, (corner + 1) % 4);
      if (a > b) {
        std::swap(a, b);
      }
      ++incidence[{a, b}];
    }
  }
  return incidence;
}
#else
std::map<std::pair<int, int>, int> quad_edge_incidence(
    const Eigen::MatrixXi &quads);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::vector<std::set<int>> quad_vertex_neighbors(
    const Eigen::MatrixXi &quads, const int vertexCount) {
  std::vector<std::set<int>> neighbors(static_cast<std::size_t>(vertexCount));
  for (int face = 0; face < quads.rows(); ++face) {
    for (int corner = 0; corner < 4; ++corner) {
      const int a = quads(face, corner);
      const int b = quads(face, (corner + 1) % 4);
      if (a >= 0 && b >= 0 && a < vertexCount && b < vertexCount) {
        neighbors[static_cast<std::size_t>(a)].insert(b);
        neighbors[static_cast<std::size_t>(b)].insert(a);
      }
    }
  }
  return neighbors;
}
#else
std::vector<std::set<int>> quad_vertex_neighbors(
    const Eigen::MatrixXi &quads, const int vertexCount);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::map<int, std::vector<int>> quad_boundary_neighbors(
    const Eigen::MatrixXi &quads) {
  std::map<int, std::vector<int>> result;
  for (const auto &[edge, count] : quad_edge_incidence(quads)) {
    if (count != 1) {
      continue;
    }
    result[edge.first].push_back(edge.second);
    result[edge.second].push_back(edge.first);
  }
  return result;
}
#else
std::map<int, std::vector<int>> quad_boundary_neighbors(
    const Eigen::MatrixXi &quads);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
int inferred_boundary_valence_target(
    const Eigen::MatrixXd &vertices, const int vertex,
    const std::vector<int> &boundaryNeighbors) {
  if (vertex < 0 || vertex >= vertices.rows() ||
      boundaryNeighbors.size() != 2U) {
    return 3;
  }
  const Eigen::RowVector3d first =
      vertices.row(boundaryNeighbors[0]) - vertices.row(vertex);
  const Eigen::RowVector3d second =
      vertices.row(boundaryNeighbors[1]) - vertices.row(vertex);
  // Straight boundary samples have two nearly opposite boundary tangents and
  // need one interior edge (valence 3). Geometric corners need no additional
  // boundary-parallel continuation and have target valence 2.
  return angle_degrees(first, second) < 150.0 ? 2 : 3;
}
#else
int inferred_boundary_valence_target(
    const Eigen::MatrixXd &vertices, const int vertex,
    const std::vector<int> &boundaryNeighbors);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d normalized_pullback(
    const Eigen::RowVector3d &raw,
    const Eigen::RowVector3d &normalizedGradient) {
  const double length = raw.norm();
  if (length <= 1.0e-20) {
    return Eigen::RowVector3d::Zero();
  }
  const Eigen::RowVector3d unit = raw / length;
  return (normalizedGradient -
          unit * unit.dot(normalizedGradient)) /
         length;
}
#else
Eigen::RowVector3d normalized_pullback(
    const Eigen::RowVector3d &raw,
    const Eigen::RowVector3d &normalizedGradient);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::RowVector3d feature_order_coordinate_gradient(
    const SurfaceFeatureProjection &projection) {
  if (!projection.valid || projection.localParameter <= 1.0e-12 ||
      projection.localParameter >= 1.0 - 1.0e-12) {
    return Eigen::RowVector3d::Zero();
  }
  const double squaredLength = projection.tangent.squaredNorm();
  if (squaredLength <= 1.0e-20) {
    return Eigen::RowVector3d::Zero();
  }
  return projection.tangent / squaredLength;
}
#else
Eigen::RowVector3d feature_order_coordinate_gradient(
    const SurfaceFeatureProjection &projection);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::vector<int> ordered_feature_vertices(
    const SurfaceOptimizationConstraints &constraints) {
  if (!constraints.orderedFeatureVertices.empty()) {
    return constraints.orderedFeatureVertices;
  }
  return constraints.featureVertices;
}
#else
std::vector<int> ordered_feature_vertices(
    const SurfaceOptimizationConstraints &constraints);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double feature_order_energy(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints) {
  const std::vector<int> features = ordered_feature_vertices(constraints);
  int previousSequence = std::numeric_limits<int>::min();
  int previousVertex = -1;
  SurfaceFeatureProjection previousProjection;
  double energy = 0.0;
  for (const int vertex : features) {
    if (vertex < 0 || vertex >= vertices.rows()) {
      continue;
    }
    const int sequence = feature_sequence_for_vertex(constraints, vertex);
    const SurfaceFeatureProjection projection =
        project_to_feature_curve(vertices.row(vertex), constraints, vertex);
    if (!projection.valid) {
      previousSequence = std::numeric_limits<int>::min();
      previousVertex = -1;
      previousProjection = {};
      continue;
    }
    if (sequence == previousSequence && previousVertex >= 0) {
      const double violation =
          previousProjection.orderCoordinate - projection.orderCoordinate;
      if (violation > 0.0) {
        energy += violation * violation;
      }
    }
    previousSequence = sequence;
    previousVertex = vertex;
    previousProjection = projection;
  }
  return energy;
}
#else
double feature_order_energy(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationGradient zero_surface_optimization_gradient(
    const int vertexCount, const int dimensions) {
  SurfaceOptimizationGradient gradient;
  gradient.surface = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.normal = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.field = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.orthogonality = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.size = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.valenceShape = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.feature = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.total = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  return gradient;
}
#else
SurfaceOptimizationGradient zero_surface_optimization_gradient(
    const int vertexCount, const int dimensions);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
void add_edge_length_gradient(Eigen::MatrixXd &gradient,
                                     const int firstVertex,
                                     const int secondVertex,
                                     const Eigen::RowVector3d &edge,
                                     const double derivativeByLength) {
  const double length = edge.norm();
  if (length <= 1.0e-20 || derivativeByLength == 0.0) {
    return;
  }
  const Eigen::RowVector3d edgeGradient =
      derivativeByLength * edge / length;
  gradient.row(firstVertex) -= edgeGradient;
  gradient.row(secondVertex) += edgeGradient;
}
#else
void add_edge_length_gradient(Eigen::MatrixXd &gradient,
                                     const int firstVertex,
                                     const int secondVertex,
                                     const Eigen::RowVector3d &edge,
                                     const double derivativeByLength);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
void zero_fixed_gradient_rows(
    SurfaceOptimizationGradient &gradient,
    const SurfaceOptimizationConstraints &constraints) {
  for (const int vertex : constraints.fixedVertices) {
    if (vertex < 0 || vertex >= gradient.total.rows()) {
      continue;
    }
    gradient.surface.row(vertex).setZero();
    gradient.normal.row(vertex).setZero();
    gradient.field.row(vertex).setZero();
    gradient.orthogonality.row(vertex).setZero();
    gradient.size.row(vertex).setZero();
    gradient.valenceShape.row(vertex).setZero();
    gradient.feature.row(vertex).setZero();
    gradient.total.row(vertex).setZero();
  }
}
#else
void zero_fixed_gradient_rows(
    SurfaceOptimizationGradient &gradient,
    const SurfaceOptimizationConstraints &constraints);
#endif

} // namespace surface_optimizer_detail

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::complex<double> degree_four_average(
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
#else
std::complex<double> degree_four_average(
    const std::vector<double> &anglesRadians,
    const std::vector<double> &connectionAnglesRadians = {},
    const std::vector<double> &weights = {});
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationEnergy evaluate_surface_optimization_energy_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationEnergy energy;
  std::vector<SurfacePoint> provenance;
  project_vertices(vertices, constraints, nullptr, nullptr, nullptr, nullptr,
                   nullptr, &provenance, &projectionCache);
  for (int i = 0; i < vertices.rows(); ++i) {
    const Eigen::RowVector3d p = vertices.row(i);
    const SurfacePoint &sourcePoint = provenance[static_cast<std::size_t>(i)];
    const Eigen::RowVector3d source =
        sourcePoint.valid() ? sourcePoint.position.transpose()
                            : project_to_source(p, constraints.sourcePositions,
                                                nullptr,
                                                constraints.sourceComponent);
    energy.surface += (p - source).squaredNorm();
    if (contains(constraints.featureVertices, i)) {
      const SurfaceFeatureProjection feature =
          project_to_feature_curve(p, constraints, i);
      if (feature.valid) {
        energy.feature += (p - feature.position).squaredNorm();
      }
    }
  }
  energy.feature += feature_order_energy(vertices, constraints);

  std::vector<int> valence(vertices.rows(), 0);
  for (int f = 0; f < quads.rows(); ++f) {
    const Eigen::RowVector3d n = face_normal(vertices, quads, f);
    SurfacePoint faceSource;
    std::vector<SurfacePoint> facePoints;
    for (int c = 0; c < 4; ++c) {
      const int vertex = quads(f, c);
      if (vertex >= 0 && vertex < static_cast<int>(provenance.size())) {
        facePoints.push_back(provenance[static_cast<std::size_t>(vertex)]);
      }
    }
    if (!facePoints.empty()) {
      faceSource = facePoints.front();
    }
    const Eigen::RowVector3d sourceNormal =
        local_source_normal(constraints, faceSource, f);
    energy.normal +=
        std::pow(1.0 - std::abs(n.dot(normalized_or_zero(sourceNormal))), 2.0);
    std::array<double, 4> faceLengths = {};
    for (int c = 0; c < 4; ++c) {
      ++valence[static_cast<std::size_t>(quads(f, c))];
      const Eigen::RowVector3d a = vertices.row(quads(f, c));
      const Eigen::RowVector3d b = vertices.row(quads(f, (c + 1) % 4));
      const Eigen::RowVector3d e = b - a;
      const double length = e.norm();
      faceLengths[static_cast<std::size_t>(c)] = length;
      const int firstVertex = quads(f, c);
      const int secondVertex = quads(f, (c + 1) % 4);
      const double target = effective_edge_target_size(
          constraints, provenance[static_cast<std::size_t>(firstVertex)],
          provenance[static_cast<std::size_t>(secondVertex)], firstVertex,
          secondVertex, length, options.targetSize);
      const double ratio = length / std::max(1.0e-12, target);
      energy.size += std::pow(ratio - 1.0, 2.0);
      const LocalSourceCross cross =
          local_source_cross(constraints, faceSource, f);
      const Eigen::RowVector3d dir = tangent_direction(e, sourceNormal);
      const double align =
          std::max(std::abs(dir.dot(cross.x)), std::abs(dir.dot(cross.y)));
      energy.field += std::pow(1.0 - align, 2.0);
      const Eigen::RowVector3d prev = vertices.row(quads(f, (c + 3) % 4)) - a;
      const Eigen::RowVector3d next = vertices.row(quads(f, (c + 1) % 4)) - a;
      const double cosCorner =
          std::abs(normalized_or_zero(prev).dot(normalized_or_zero(next)));
      energy.orthogonality += cosCorner * cosCorner;
    }
    const auto [minLength, maxLength] =
        std::minmax_element(faceLengths.begin(), faceLengths.end());
    energy.valenceShape +=
        std::pow((*maxLength / std::max(1.0e-12, *minLength)) - 1.0, 2.0);
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
#else
SurfaceOptimizationEnergy evaluate_surface_optimization_energy_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationEnergy evaluate_surface_optimization_energy(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  surface_optimizer_detail::SourceProjectionCache projectionCache(constraints);
  return evaluate_surface_optimization_energy_cached(
      vertices, quads, constraints, options, projectionCache);
}
#else
SurfaceOptimizationEnergy evaluate_surface_optimization_energy(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
double signed_scaled_jacobian(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads, const int face,
    const Eigen::RowVector3d &sourceNormal) {
  double minimum = std::numeric_limits<double>::infinity();
  for (int c = 0; c < 4; ++c) {
    const Eigen::RowVector3d p = vertices.row(quads(face, c));
    const Eigen::RowVector3d e0 =
        vertices.row(quads(face, (c + 1) % 4)) - p;
    const Eigen::RowVector3d e1 =
        vertices.row(quads(face, (c + 3) % 4)) - p;
    const double denom = std::max(1.0e-20, e0.norm() * e1.norm());
    const double signedCorner =
        surface_optimizer_detail::cross3(e0, e1)
            .dot(surface_optimizer_detail::normalized_or_zero(sourceNormal)) /
        denom;
    minimum = std::min(minimum, signedCorner);
  }
  return minimum == std::numeric_limits<double>::infinity() ? 0.0 : minimum;
}
#else
double signed_scaled_jacobian(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads, const int face,
    const Eigen::RowVector3d &sourceNormal);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
std::vector<unsigned char> source_boundary_vertex_mask(
    const Eigen::MatrixXi &sourceFaces, const int sourceVertexCount) {
  std::map<std::pair<int, int>, int> edgeIncidence;
  for (int face = 0; face < sourceFaces.rows(); ++face) {
    if (sourceFaces.cols() != 3) {
      break;
    }
    for (int corner = 0; corner < 3; ++corner) {
      int first = sourceFaces(face, corner);
      int second = sourceFaces(face, (corner + 1) % 3);
      if (first > second) {
        std::swap(first, second);
      }
      ++edgeIncidence[{first, second}];
    }
  }

  std::vector<unsigned char> boundary(
      static_cast<std::size_t>(std::max(0, sourceVertexCount)), 0);
  for (const auto &[edge, incidence] : edgeIncidence) {
    if (incidence != 1) {
      continue;
    }
    for (const int vertex : {edge.first, edge.second}) {
      if (vertex >= 0 && vertex < sourceVertexCount) {
        boundary[static_cast<std::size_t>(vertex)] = 1;
      }
    }
  }
  return boundary;
}
#else
std::vector<unsigned char> source_boundary_vertex_mask(
    const Eigen::MatrixXi &sourceFaces, const int sourceVertexCount);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
void fill_required_singularity_valence_targets(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const Eigen::VectorXi &singularCycles,
    const Eigen::VectorXi &singularIndices,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints) {
  constraints.requiredSingularityValenceTargets.clear();
  const std::vector<unsigned char> sourceBoundary =
      source_boundary_vertex_mask(sourceFaces, sourceVertices.rows());
  const int count = std::min(singularCycles.size(), singularIndices.size());
  for (int index = 0; index < count; ++index) {
    const int sourceVertex = singularCycles(index);
    if (sourceVertex < 0 || sourceVertex >= sourceVertices.rows()) {
      continue;
    }
    // Cross-field index-to-valence conversion differs at the source boundary.
    // Interior poles have target valence 4-indexNumerator. A regular boundary
    // sample has valence three, so boundary poles use 3-indexNumerator. This
    // prevents ordinary 90-degree boundary corners (index +1) from being
    // incorrectly forced to interior valence three instead of corner valence two.
    const bool boundarySingularity =
        sourceVertex < static_cast<int>(sourceBoundary.size()) &&
        sourceBoundary[static_cast<std::size_t>(sourceVertex)] != 0;
    const int regularValence = boundarySingularity ? 3 : 4;
    const int targetValence = regularValence - singularIndices(index);
    if (targetValence < 2 || targetValence > 8) {
      continue;
    }
    int bestOutput = -1;
    double bestDistance = std::numeric_limits<double>::infinity();
    for (int output = 0; output < outputVertices.rows(); ++output) {
      if (output >= static_cast<int>(outputProvenance.size())) {
        continue;
      }
      const SurfacePoint &point =
          outputProvenance[static_cast<std::size_t>(output)];
      if (!point.valid() || point.face < 0 || point.face >= sourceFaces.rows()) {
        continue;
      }
      bool incident = false;
      for (int corner = 0; corner < 3; ++corner) {
        incident = incident || sourceFaces(point.face, corner) == sourceVertex;
      }
      if (!incident) {
        continue;
      }
      const double distance =
          (outputVertices.row(output) - sourceVertices.row(sourceVertex))
              .squaredNorm();
      if (distance < bestDistance) {
        bestDistance = distance;
        bestOutput = output;
      }
    }
    if (bestOutput < 0) {
      continue;
    }
    const auto existing =
        constraints.requiredSingularityValenceTargets.find(bestOutput);
    if (existing == constraints.requiredSingularityValenceTargets.end() ||
        existing->second == targetValence) {
      constraints.requiredSingularityValenceTargets[bestOutput] = targetValence;
    } else {
      // Two authoritative singularities cannot consume one output pole with
      // incompatible valences. Record an impossible target so validation fails
      // closed instead of silently dropping one requirement.
      constraints.requiredSingularityValenceTargets[bestOutput] = 0;
    }
  }
}
#else
void fill_required_singularity_valence_targets(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const Eigen::VectorXi &singularCycles,
    const Eigen::VectorXi &singularIndices,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceQuadQualityMetrics evaluate_surface_quad_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const Eigen::RowVector3d &sourceNormal) {
  using namespace surface_optimizer_detail;
  SurfaceQuadQualityMetrics quality;
  const Eigen::RowVector3d normal = normalized_or_zero(sourceNormal);
  std::array<double, 4> lengths{};
  quality.minimumAngleDegrees = std::numeric_limits<double>::infinity();
  quality.maximumAngleDegrees = 0.0;
  for (int corner = 0; corner < 4; ++corner) {
    const Eigen::RowVector3d point = vertices.row(quads(face, corner));
    const Eigen::RowVector3d next =
        vertices.row(quads(face, (corner + 1) % 4)) - point;
    const Eigen::RowVector3d previous =
        vertices.row(quads(face, (corner + 3) % 4)) - point;
    lengths[static_cast<std::size_t>(corner)] = next.norm();
    const double signedCorner = cross3(next, previous).dot(normal);
    quality.convex = quality.convex && signedCorner > 1.0e-14;
    const double angle = angle_degrees(previous, next);
    quality.minimumAngleDegrees =
        std::min(quality.minimumAngleDegrees, angle);
    quality.maximumAngleDegrees =
        std::max(quality.maximumAngleDegrees, angle);
  }
  if (!std::isfinite(quality.minimumAngleDegrees)) {
    quality.minimumAngleDegrees = 0.0;
  }
  const auto [minimumLength, maximumLength] =
      std::minmax_element(lengths.begin(), lengths.end());
  quality.aspectRatio =
      *maximumLength / std::max(1.0e-12, *minimumLength);
  quality.signedScaledJacobian =
      signed_scaled_jacobian(vertices, quads, face, normal);

  const Eigen::RowVector3d p0 = vertices.row(quads(face, 0));
  const Eigen::RowVector3d p1 = vertices.row(quads(face, 1));
  const Eigen::RowVector3d p2 = vertices.row(quads(face, 2));
  const Eigen::RowVector3d p3 = vertices.row(quads(face, 3));
  const Eigen::RowVector3d n012 = normalized_or_zero(cross3(p1 - p0, p2 - p0));
  const Eigen::RowVector3d n023 = normalized_or_zero(cross3(p2 - p0, p3 - p0));
  const Eigen::RowVector3d n013 = normalized_or_zero(cross3(p1 - p0, p3 - p0));
  const Eigen::RowVector3d n123 = normalized_or_zero(cross3(p2 - p1, p3 - p1));
  const double diagonal02 = angle_degrees(n012, n023);
  const double diagonal13 = angle_degrees(n013, n123);
  quality.warpageDegrees = std::max(diagonal02, diagonal13);
  return quality;
}
#else
SurfaceQuadQualityMetrics evaluate_surface_quad_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const Eigen::RowVector3d &sourceNormal);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool local_orientation_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints *constraints = nullptr,
    const std::vector<SurfacePoint> *vertexProvenance = nullptr,
    surface_optimizer_detail::SourceProjectionCache *projectionCache = nullptr) {
  const std::vector<SurfacePoint> *authoritativeProvenance =
      vertexProvenance != nullptr
          ? vertexProvenance
          : (constraints != nullptr ? &constraints->vertexProvenance : nullptr);
  for (int f = 0; f < quads.rows(); ++f) {
    const Eigen::RowVector3d a = vertices.row(quads(f, 0));
    const Eigen::RowVector3d b = vertices.row(quads(f, 1));
    const Eigen::RowVector3d c = vertices.row(quads(f, 2));
    Eigen::RowVector3d normal(0.0, 0.0, 1.0);
    if (constraints != nullptr) {
      const SurfacePoint reference =
          authoritativeProvenance != nullptr
              ? surface_optimizer_detail::quad_reference_surface_point(
                    vertices, quads, f, *constraints,
                    *authoritativeProvenance, projectionCache)
              : SurfacePoint{};
      normal = surface_optimizer_detail::local_source_normal(
          *constraints, reference, f);
    }
    if (surface_optimizer_detail::cross3(b - a, c - a).dot(normal) <=
        1.0e-14) {
      return false;
    }
  }
  return true;
}
#else
bool local_orientation_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints *constraints = nullptr,
    const std::vector<SurfacePoint> *vertexProvenance = nullptr,
    surface_optimizer_detail::SourceProjectionCache *projectionCache = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
validation::SourceAuthoritativeMeshValidatorOptions
make_source_authoritative_validator_options(
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance) {
  validation::SourceAuthoritativeMeshValidatorOptions validatorOptions;
  validatorOptions.sourceVertices = &constraints.sourceVertices;
  validatorOptions.sourceFaces = &constraints.sourceFaces;
  validatorOptions.sourceFaceComponents = &constraints.sourceFaceComponent;
  validatorOptions.sourceFaceSheets = &constraints.sourceFaceSheet;
  validatorOptions.vertexProvenance = &provenance;
  validatorOptions.authoritativeBoundaryEdges =
      constraints.authoritativeBoundaryEdges;
  validatorOptions.authoritativeBoundaryLoops =
      constraints.authoritativeBoundaryLoops;
  if (validatorOptions.authoritativeBoundaryLoops.empty() &&
      !constraints.authoritativeBoundaryLoop.empty()) {
    validatorOptions.authoritativeBoundaryLoops.push_back(
        constraints.authoritativeBoundaryLoop);
  }
  validatorOptions.authoritativeFeatureRails =
      constraints.authoritativeFeatureRails;
  validatorOptions.expectedFeatureRailCount =
      constraints.requiredFeatureRailCount;
  validatorOptions.requireBoundaryAuthority = true;
  validatorOptions.requireFeatureRailAuthority =
      constraints.featureRailAuthorityProvided;
  validatorOptions.requireLocalSheetCompatibility = true;
  return validatorOptions;
}
#else
validation::SourceAuthoritativeMeshValidatorOptions
make_source_authoritative_validator_options(
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
bool source_authoritative_hard_invariants_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance) {
  if (!constraints.requireSourceAuthoritativeValidation) {
    return true;
  }
  const auto validation = validation::validate_source_authoritative_surface_mesh(
      vertices, quads,
      make_source_authoritative_validator_options(constraints, provenance));
  return validation.accepted;
}
#else
bool source_authoritative_hard_invariants_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance);
#endif

// Computes the optimizer derivative directly per enabled energy. Geometric
// terms use closed-form derivatives. Source-normal and 4-RoSy transport
// depend on piecewise source-triangle projection and normalized barycentric
// interpolation, so only those local source-data pullbacks use centered
// differences; the full objective is never finite-differenced by the optimizer.
#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationGradient evaluate_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationGradient gradient =
      zero_surface_optimization_gradient(vertices.rows(), vertices.cols());

  std::vector<SurfacePoint> provenance;
  project_vertices(vertices, constraints, nullptr, nullptr, nullptr, nullptr,
                   nullptr, &provenance, &projectionCache);

  std::vector<SurfaceFeatureProjection> featureProjections(
      static_cast<std::size_t>(vertices.rows()));
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    const Eigen::RowVector3d point = vertices.row(vertex);
    const SurfacePoint &sourcePoint =
        provenance[static_cast<std::size_t>(vertex)];
    const Eigen::RowVector3d source =
        sourcePoint.valid()
            ? sourcePoint.position.transpose()
            : project_to_source(point, constraints.sourcePositions, nullptr,
                                constraints.sourceComponent);
    gradient.surface.row(vertex) += 2.0 * (point - source);

    if (!contains(constraints.featureVertices, vertex)) {
      continue;
    }
    SurfaceFeatureProjection projection =
        project_to_feature_curve(point, constraints, vertex);
    featureProjections[static_cast<std::size_t>(vertex)] = projection;
    if (projection.valid) {
      gradient.feature.row(vertex) +=
          2.0 * (point - projection.position);
    }
  }

  const std::vector<int> orderedFeatures =
      ordered_feature_vertices(constraints);
  int previousSequence = std::numeric_limits<int>::min();
  int previousVertex = -1;
  SurfaceFeatureProjection previousProjection;
  for (const int vertex : orderedFeatures) {
    if (vertex < 0 || vertex >= vertices.rows()) {
      continue;
    }
    const int sequence = feature_sequence_for_vertex(constraints, vertex);
    SurfaceFeatureProjection projection =
        featureProjections[static_cast<std::size_t>(vertex)];
    if (!projection.valid) {
      projection = project_to_feature_curve(vertices.row(vertex), constraints,
                                            vertex);
      featureProjections[static_cast<std::size_t>(vertex)] = projection;
    }
    if (!projection.valid) {
      previousSequence = std::numeric_limits<int>::min();
      previousVertex = -1;
      previousProjection = {};
      continue;
    }
    if (sequence == previousSequence && previousVertex >= 0) {
      const double violation =
          previousProjection.orderCoordinate - projection.orderCoordinate;
      if (violation > 0.0) {
        gradient.feature.row(previousVertex) +=
            2.0 * violation *
            feature_order_coordinate_gradient(previousProjection);
        gradient.feature.row(vertex) -=
            2.0 * violation * feature_order_coordinate_gradient(projection);
      }
    }
    previousSequence = sequence;
    previousVertex = vertex;
    previousProjection = projection;
  }

  for (int face = 0; face < quads.rows(); ++face) {
    std::array<int, 4> faceVertices = {};
    std::array<Eigen::RowVector3d, 4> faceEdges = {};
    std::array<double, 4> faceLengths = {};
    for (int corner = 0; corner < 4; ++corner) {
      faceVertices[static_cast<std::size_t>(corner)] = quads(face, corner);
      const int first = quads(face, corner);
      const int second = quads(face, (corner + 1) % 4);
      faceEdges[static_cast<std::size_t>(corner)] =
          vertices.row(second) - vertices.row(first);
      faceLengths[static_cast<std::size_t>(corner)] =
          faceEdges[static_cast<std::size_t>(corner)].norm();
    }

    SurfacePoint faceSource;
    int faceSourceVertex = -1;
    for (const int vertex : faceVertices) {
      if (vertex >= 0 && vertex < static_cast<int>(provenance.size()) &&
          provenance[static_cast<std::size_t>(vertex)].valid()) {
        faceSource = provenance[static_cast<std::size_t>(vertex)];
        faceSourceVertex = vertex;
        break;
      }
    }
    const Eigen::RowVector3d sourceNormal = normalized_or_zero(
        local_source_normal(constraints, faceSource, face));
    const LocalSourceCross sourceCross =
        local_source_cross(constraints, faceSource, face);

    const int aIndex = faceVertices[0];
    const int bIndex = faceVertices[1];
    const int cIndex = faceVertices[2];
    const Eigen::RowVector3d edgeAB =
        vertices.row(bIndex) - vertices.row(aIndex);
    const Eigen::RowVector3d edgeAC =
        vertices.row(cIndex) - vertices.row(aIndex);
    const Eigen::RowVector3d rawNormal = cross3(edgeAB, edgeAC);
    const double rawNormalLength = rawNormal.norm();
    if (rawNormalLength > 1.0e-20 && sourceNormal.squaredNorm() > 0.0) {
      const Eigen::RowVector3d faceNormal = rawNormal / rawNormalLength;
      const double dot = faceNormal.dot(sourceNormal);
      const double sign = dot >= 0.0 ? 1.0 : -1.0;
      const Eigen::RowVector3d normalGradient =
          2.0 * (std::abs(dot) - 1.0) * sign * sourceNormal;
      const Eigen::RowVector3d rawNormalGradient =
          normalized_pullback(rawNormal, normalGradient);
      const Eigen::RowVector3d edgeABGradient =
          cross3(edgeAC, rawNormalGradient);
      const Eigen::RowVector3d edgeACGradient =
          cross3(rawNormalGradient, edgeAB);
      gradient.normal.row(aIndex) -= edgeABGradient + edgeACGradient;
      gradient.normal.row(bIndex) += edgeABGradient;
      gradient.normal.row(cIndex) += edgeACGradient;
    }

    if (faceSourceVertex >= 0 && rawNormalLength > 1.0e-20) {
      const Eigen::RowVector3d faceNormal = rawNormal / rawNormalLength;
      const double eps = std::max(1.0e-8, options.finiteDifferenceStep);
      const int requiredComponent = faceSource.component;
      const int requiredSheet = faceSource.sheet;
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        Eigen::RowVector3d plusPoint = vertices.row(faceSourceVertex);
        Eigen::RowVector3d minusPoint = vertices.row(faceSourceVertex);
        plusPoint(coordinate) += eps;
        minusPoint(coordinate) -= eps;
        const SurfacePoint plusSource = nearest_source_point(
            plusPoint, constraints, requiredComponent, requiredSheet,
            &projectionCache);
        const SurfacePoint minusSource = nearest_source_point(
            minusPoint, constraints, requiredComponent, requiredSheet,
            &projectionCache);
        const Eigen::RowVector3d plusNormal = normalized_or_zero(
            local_source_normal(constraints, plusSource, face));
        const Eigen::RowVector3d minusNormal = normalized_or_zero(
            local_source_normal(constraints, minusSource, face));
        const double plusDot = faceNormal.dot(plusNormal);
        const double minusDot = faceNormal.dot(minusNormal);
        const double plusEnergy =
            std::pow(1.0 - std::abs(plusDot), 2.0);
        const double minusEnergy =
            std::pow(1.0 - std::abs(minusDot), 2.0);
        gradient.normal(faceSourceVertex, coordinate) +=
            (plusEnergy - minusEnergy) / (2.0 * eps);
      }
    }

    for (int corner = 0; corner < 4; ++corner) {
      const int first = faceVertices[static_cast<std::size_t>(corner)];
      const int second =
          faceVertices[static_cast<std::size_t>((corner + 1) % 4)];
      const Eigen::RowVector3d edge =
          faceEdges[static_cast<std::size_t>(corner)];
      const double length = faceLengths[static_cast<std::size_t>(corner)];
      if (length > 1.0e-20) {
        const SurfacePoint &firstPoint =
            provenance[static_cast<std::size_t>(first)];
        const SurfacePoint &secondPoint =
            provenance[static_cast<std::size_t>(second)];
        const double firstTarget = local_target_size(
            constraints, firstPoint, first, options.targetSize);
        const double secondTarget = local_target_size(
            constraints, secondPoint, second, options.targetSize);
        const double rawTarget = 0.5 * (firstTarget + secondTarget);
        const double target = effective_edge_target_size(
            constraints, firstPoint, secondPoint, first, second, length,
            options.targetSize);
        const double safeTarget = std::max(1.0e-12, target);
        const double ratio = length / safeTarget;
        add_edge_length_gradient(gradient.size, first, second, edge,
                                 2.0 * (ratio - 1.0) / safeTarget);
        const bool immutableOverride =
            immutable_rail_edge(constraints, first, second) &&
            std::abs(target - length) <=
                1.0e-12 * std::max({1.0, target, length}) &&
            std::abs(rawTarget - target) >
                1.0e-12 * std::max({1.0, rawTarget, target});
        if (!immutableOverride) {
          const double derivativeByTarget =
              -2.0 * (ratio - 1.0) * length /
              (safeTarget * safeTarget);
          gradient.size.row(first) +=
              0.5 * derivativeByTarget *
              local_target_size_gradient(constraints, firstPoint);
          gradient.size.row(second) +=
              0.5 * derivativeByTarget *
              local_target_size_gradient(constraints, secondPoint);
        }

        const Eigen::RowVector3d projectedEdge =
            edge - edge.dot(sourceNormal) * sourceNormal;
        const double projectedLength = projectedEdge.norm();
        if (projectedLength > 1.0e-20) {
          const Eigen::RowVector3d direction = projectedEdge / projectedLength;
          const double dotX = direction.dot(sourceCross.x);
          const double dotY = direction.dot(sourceCross.y);
          const bool chooseX = std::abs(dotX) >= std::abs(dotY);
          const double selectedDot = chooseX ? dotX : dotY;
          const Eigen::RowVector3d selectedAxis =
              chooseX ? sourceCross.x : sourceCross.y;
          const double selectedSign = selectedDot >= 0.0 ? 1.0 : -1.0;
          const double alignment = std::abs(selectedDot);
          const Eigen::RowVector3d directionGradient =
              2.0 * (alignment - 1.0) * selectedSign * selectedAxis;
          const Eigen::RowVector3d projectedGradient =
              normalized_pullback(projectedEdge, directionGradient);
          const Eigen::RowVector3d edgeGradient =
              projectedGradient -
              projectedGradient.dot(sourceNormal) * sourceNormal;
          gradient.field.row(first) -= edgeGradient;
          gradient.field.row(second) += edgeGradient;
        }
      }

      const int center = faceVertices[static_cast<std::size_t>(corner)];
      const int previous =
          faceVertices[static_cast<std::size_t>((corner + 3) % 4)];
      const int next =
          faceVertices[static_cast<std::size_t>((corner + 1) % 4)];
      const Eigen::RowVector3d previousEdge =
          vertices.row(previous) - vertices.row(center);
      const Eigen::RowVector3d nextEdge =
          vertices.row(next) - vertices.row(center);
      const double previousLength = previousEdge.norm();
      const double nextLength = nextEdge.norm();
      if (previousLength > 1.0e-20 && nextLength > 1.0e-20) {
        const Eigen::RowVector3d previousDirection =
            previousEdge / previousLength;
        const Eigen::RowVector3d nextDirection = nextEdge / nextLength;
        const double cosine = previousDirection.dot(nextDirection);
        const Eigen::RowVector3d previousGradient =
            2.0 * cosine *
            (nextDirection - cosine * previousDirection) / previousLength;
        const Eigen::RowVector3d nextGradient =
            2.0 * cosine *
            (previousDirection - cosine * nextDirection) / nextLength;
        gradient.orthogonality.row(previous) += previousGradient;
        gradient.orthogonality.row(next) += nextGradient;
        gradient.orthogonality.row(center) -=
            previousGradient + nextGradient;
      }
    }

    if (faceSourceVertex >= 0) {
      const double eps = std::max(1.0e-8, options.finiteDifferenceStep);
      const int requiredComponent = faceSource.component;
      const int requiredSheet = faceSource.sheet;
      const auto fieldEnergyForSource = [&](const SurfacePoint &source) {
        const LocalSourceCross cross =
            local_source_cross(constraints, source, face);
        const Eigen::RowVector3d fieldNormal =
            local_source_normal(constraints, source, face);
        double value = 0.0;
        for (int edgeIndex = 0; edgeIndex < 4; ++edgeIndex) {
          const Eigen::RowVector3d edge =
              faceEdges[static_cast<std::size_t>(edgeIndex)];
          const Eigen::RowVector3d direction =
              tangent_direction(edge, fieldNormal);
          if (direction.squaredNorm() == 0.0) {
            continue;
          }
          const double alignment =
              std::max(std::abs(direction.dot(cross.x)),
                       std::abs(direction.dot(cross.y)));
          value += std::pow(1.0 - alignment, 2.0);
        }
        return value;
      };
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        Eigen::RowVector3d plusPoint = vertices.row(faceSourceVertex);
        Eigen::RowVector3d minusPoint = vertices.row(faceSourceVertex);
        plusPoint(coordinate) += eps;
        minusPoint(coordinate) -= eps;
        const SurfacePoint plusSource = nearest_source_point(
            plusPoint, constraints, requiredComponent, requiredSheet,
            &projectionCache);
        const SurfacePoint minusSource = nearest_source_point(
            minusPoint, constraints, requiredComponent, requiredSheet,
            &projectionCache);
        const double plusEnergy = fieldEnergyForSource(plusSource);
        const double minusEnergy = fieldEnergyForSource(minusSource);
        gradient.field(faceSourceVertex, coordinate) +=
            (plusEnergy - minusEnergy) / (2.0 * eps);
      }
    }

    int minimumEdge = 0;
    int maximumEdge = 0;
    for (int edge = 1; edge < 4; ++edge) {
      if (faceLengths[static_cast<std::size_t>(edge)] <
          faceLengths[static_cast<std::size_t>(minimumEdge)]) {
        minimumEdge = edge;
      }
      if (faceLengths[static_cast<std::size_t>(edge)] >
          faceLengths[static_cast<std::size_t>(maximumEdge)]) {
        maximumEdge = edge;
      }
    }
    const double minimumLength =
        faceLengths[static_cast<std::size_t>(minimumEdge)];
    const double maximumLength =
        faceLengths[static_cast<std::size_t>(maximumEdge)];
    if (minimumLength > 1.0e-20 && maximumEdge != minimumEdge) {
      const double ratio = maximumLength / minimumLength;
      const double residual = ratio - 1.0;
      const int minimumFirst =
          faceVertices[static_cast<std::size_t>(minimumEdge)];
      const int minimumSecond =
          faceVertices[static_cast<std::size_t>((minimumEdge + 1) % 4)];
      const int maximumFirst =
          faceVertices[static_cast<std::size_t>(maximumEdge)];
      const int maximumSecond =
          faceVertices[static_cast<std::size_t>((maximumEdge + 1) % 4)];
      add_edge_length_gradient(
          gradient.valenceShape, maximumFirst, maximumSecond,
          faceEdges[static_cast<std::size_t>(maximumEdge)],
          2.0 * residual / minimumLength);
      add_edge_length_gradient(
          gradient.valenceShape, minimumFirst, minimumSecond,
          faceEdges[static_cast<std::size_t>(minimumEdge)],
          -2.0 * residual * maximumLength /
              (minimumLength * minimumLength));
    }
    // The valence/pole penalty is topological for fixed connectivity. Its
    // positional derivative is exactly zero; the shape portion above carries
    // the differentiable contribution of this combined energy.
  }

  gradient.total = options.weights.surface * gradient.surface +
                   options.weights.normal * gradient.normal +
                   options.weights.field * gradient.field +
                   options.weights.orthogonality * gradient.orthogonality +
                   options.weights.size * gradient.size +
                   options.weights.valenceShape * gradient.valenceShape +
                   options.weights.feature * gradient.feature;
  zero_fixed_gradient_rows(gradient, constraints);
  return gradient;
}
#else
SurfaceOptimizationGradient evaluate_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationGradient evaluate_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {}) {
  surface_optimizer_detail::SourceProjectionCache projectionCache(constraints);
  return evaluate_surface_optimization_gradient_cached(
      vertices, quads, constraints, options, projectionCache);
}
#else
SurfaceOptimizationGradient evaluate_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::MatrixXd finite_difference_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache) {
  Eigen::MatrixXd gradient = Eigen::MatrixXd::Zero(vertices.rows(), vertices.cols());
  const double eps = std::max(1.0e-9, options.finiteDifferenceStep);
  for (int r = 0; r < vertices.rows(); ++r) {
    if (surface_optimizer_detail::contains(constraints.fixedVertices, r)) {
      continue;
    }
    for (int c = 0; c < vertices.cols(); ++c) {
      Eigen::MatrixXd plus = vertices;
      Eigen::MatrixXd minus = vertices;
      plus(r, c) += eps;
      minus(r, c) -= eps;
      const double ePlus =
          evaluate_surface_optimization_energy_cached(
              plus, quads, constraints, options, projectionCache)
              .total;
      const double eMinus =
          evaluate_surface_optimization_energy_cached(
              minus, quads, constraints, options, projectionCache)
              .total;
      gradient(r, c) = (ePlus - eMinus) / (2.0 * eps);
    }
  }
  return gradient;
}
#else
Eigen::MatrixXd finite_difference_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
Eigen::MatrixXd finite_difference_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {}) {
  surface_optimizer_detail::SourceProjectionCache projectionCache(constraints);
  return finite_difference_surface_optimization_gradient_cached(
      vertices, quads, constraints, options, projectionCache);
}
#else
Eigen::MatrixXd finite_difference_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationResult optimize_projected_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {}) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationResult result;
  result.vertices = initialVertices;
  result.quads = quads;
  result.topologyHash = topology_hash(quads);
  SourceProjectionCache projectionCache(constraints);
  Eigen::VectorXd featureParameters;
  result.vertices = project_vertices(result.vertices, constraints, &featureParameters,
                                     &result.featureParametersOrdered,
                                     &result.projectionStayedOnComponents,
                                     &result.projectionStayedOnSheets,
                                     &result.projectionHasCompleteProvenance,
                                     &result.vertexProvenance, &projectionCache);
  result.sourceTriangleProjectionUsed =
      constraints.sourceVertices.rows() > 0 && constraints.sourceFaces.rows() > 0 &&
      std::all_of(result.vertexProvenance.begin(), result.vertexProvenance.end(),
                  [](const SurfacePoint &point) {
                    return point.valid() && point.face >= 0;
                  });
  SurfaceOptimizationEnergy current =
      evaluate_surface_optimization_energy_cached(
          result.vertices, quads, constraints, options, projectionCache);
  result.initialEnergy = current;
  result.finalEnergy = current;

  for (int iteration = 0; iteration < options.maxIterations; ++iteration) {
    const SurfaceOptimizationGradient derivative =
        evaluate_surface_optimization_gradient_cached(
            result.vertices, quads, constraints, options, projectionCache);
    Eigen::MatrixXd direction = derivative.total;
    result.directGradientUsed = true;
    ++result.directGradientEvaluationCount;
    bool accepted = false;
    double acceptedAlpha = 0.0;
    SurfaceOptimizationEnergy acceptedEnergy = current;
    for (const double alpha : options.lineSearchSteps) {
      ++result.lineSearchTrialCount;
      bool ordered = true;
      bool componentsOk = true;
      bool sheetsOk = true;
      bool provenanceComplete = true;
      std::vector<SurfacePoint> trialProvenance;
      const Eigen::MatrixXd trial = project_vertices(
          result.vertices - alpha * direction, constraints, nullptr, &ordered,
          &componentsOk, &sheetsOk, &provenanceComplete, &trialProvenance,
          &projectionCache);
      if (!ordered || !componentsOk || !sheetsOk || !provenanceComplete) {
        ++result.lineSearchRejectionCount;
        ++result.projectionConstraintRejectionCount;
        continue;
      }
      if (!local_orientation_valid(trial, quads, &constraints,
                                   &trialProvenance, &projectionCache)) {
        ++result.lineSearchRejectionCount;
        ++result.orientationRejectionCount;
        continue;
      }
      if (options.enforceSourceAuthoritativeHardInvariants &&
          !source_authoritative_hard_invariants_valid(
              trial, quads, constraints, trialProvenance)) {
        ++result.lineSearchRejectionCount;
        ++result.hardInvariantRejectionCount;
        continue;
      }
      const SurfaceOptimizationEnergy trialEnergy =
          evaluate_surface_optimization_energy_cached(
              trial, quads, constraints, options, projectionCache);
      if (armijo_sufficient_decrease(current.total, trialEnergy.total, alpha,
                                     direction.squaredNorm(),
                                     options.armijo)) {
        result.vertices = trial;
        accepted = true;
        acceptedAlpha = alpha;
        acceptedEnergy = trialEnergy;
        result.featureParametersOrdered =
            result.featureParametersOrdered && ordered;
        result.projectionStayedOnComponents =
            result.projectionStayedOnComponents && componentsOk;
        result.projectionStayedOnSheets =
            result.projectionStayedOnSheets && sheetsOk;
        result.projectionHasCompleteProvenance =
            result.projectionHasCompleteProvenance && provenanceComplete;
        project_vertices(result.vertices, constraints, nullptr, nullptr, nullptr,
                         nullptr, nullptr, &result.vertexProvenance,
                         &projectionCache);
        break;
      }
      ++result.lineSearchRejectionCount;
      ++result.armijoRejectionCount;
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
    result.finalEnergy = current;
    if (drop / std::max(1.0, current.total) < options.tolerance) {
      break;
    }
  }
  result.topologyHashFixed = result.topologyHash == topology_hash(quads);
  result.sourceBvhBuildCount = projectionCache.bvh.has_value() ? 1U : 0U;
  result.projectionQueryCount = projectionCache.queryCount;
  result.finalEnergy = current;
  return result;
}
#else
SurfaceOptimizationResult optimize_projected_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceFinalValidationReport validate_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options = {},
    const double optimizerSeconds = 0.0, const double endToEndSeconds = 1.0) {
  using namespace surface_optimizer_detail;
  SurfaceFinalValidationReport report;
  std::vector<double> quadToSourceErrors;
  std::vector<double> sourceToOutputErrors;
  std::vector<double> normalErrors;
  std::vector<double> featureErrors;
  std::vector<double> featureTangentErrors;
  std::vector<double> fieldErrors;
  std::vector<double> sizeRatios;
  std::vector<double> angles;
  std::vector<double> warpages;
  std::vector<double> aspects;
  std::vector<double> jacobians;
  const std::vector<SurfacePoint> &provenance = optimization.vertexProvenance;
  SourceProjectionCache sourceProjection(constraints);

  // Sample the complete output faces, not only their vertices. Bilinear 3x3
  // sampling observes bowed edges and warped interiors while remaining
  // deterministic and inexpensive for the P21 quality gate.
  constexpr std::array<double, 3> quadSamples = {0.0, 0.5, 1.0};
  if (constraints.sourceVertices.rows() > 0 &&
      constraints.sourceFaces.rows() > 0) {
  for (int face = 0; face < quads.rows(); ++face) {
    const auto [component, sheet] =
        consistent_component_sheet(quads, face, provenance, &constraints);
    for (const double u : quadSamples) {
      for (const double v : quadSamples) {
        const Eigen::RowVector3d sample =
            quad_bilinear_sample(vertices, quads, face, u, v);
        const SurfacePoint sourcePoint = nearest_source_point(
            sample, constraints, component, sheet, &sourceProjection);
        if (!sourcePoint.valid()) {
          quadToSourceErrors.push_back(
              std::numeric_limits<double>::infinity());
          continue;
        }
        const double target = local_target_size(
            constraints, sourcePoint, 0, options.targetSize);
        quadToSourceErrors.push_back(
            std::sqrt(sourcePoint.squaredDistance) /
            std::max(1.0e-12, target));
      }
    }
  }
  }

  // Retain a point-cloud fallback for legacy standalone optimizer fixtures.
  if (quadToSourceErrors.empty()) {
    for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
      const SurfacePoint sourcePoint =
          vertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(vertex)]
              : nearest_source_point(vertices.row(vertex), constraints);
      const Eigen::RowVector3d source =
          sourcePoint.valid()
              ? sourcePoint.position.transpose()
              : project_to_source(vertices.row(vertex),
                                  constraints.sourcePositions, nullptr,
                                  constraints.sourceComponent);
      quadToSourceErrors.push_back(
          (vertices.row(vertex) - source).norm() /
          std::max(1.0e-12, options.targetSize));
    }
  }

  // Sample every source triangle in the reverse direction. Output triangles
  // inherit component/sheet authority from their quad provenance so nearby
  // disconnected or folded sheets cannot hide a coverage hole.
  if (constraints.sourceVertices.rows() > 0 &&
      constraints.sourceFaces.rows() > 0 && quads.rows() > 0) {
    OutputProjectionCache outputProjection(vertices, quads, provenance,
                                           &constraints);
    const std::vector<Eigen::Vector3d> barycentrics =
        triangle_sample_barycentrics();
    for (int face = 0; face < constraints.sourceFaces.rows(); ++face) {
      const int component =
          face < static_cast<int>(constraints.sourceFaceComponent.size())
              ? constraints.sourceFaceComponent[static_cast<std::size_t>(face)]
              : -1;
      const int sheet =
          face < static_cast<int>(constraints.sourceFaceSheet.size())
              ? constraints.sourceFaceSheet[static_cast<std::size_t>(face)]
              : -1;
      for (const Eigen::Vector3d &barycentric : barycentrics) {
        SurfacePoint sourcePoint;
        sourcePoint.face = face;
        sourcePoint.component = component;
        sourcePoint.sheet = sheet;
        sourcePoint.barycentric = barycentric;
        sourcePoint.position = source_point_position(
                                   constraints.sourceVertices,
                                   constraints.sourceFaces, sourcePoint)
                                   .transpose();
        sourcePoint.squaredDistance = 0.0;
        const SurfacePoint outputPoint = outputProjection.project(
            sourcePoint.position.transpose(), component, sheet);
        if (!outputPoint.valid()) {
          sourceToOutputErrors.push_back(
              std::numeric_limits<double>::infinity());
          continue;
        }
        const double target = local_target_size(
            constraints, sourcePoint, 0, options.targetSize);
        sourceToOutputErrors.push_back(
            std::sqrt(outputPoint.squaredDistance) /
            std::max(1.0e-12, target));
      }
    }
  } else if (constraints.sourceVertices.rows() > 0 &&
             constraints.sourceFaces.rows() > 0 && quads.rows() == 0) {
    sourceToOutputErrors.push_back(std::numeric_limits<double>::infinity());
  } else if (constraints.sourcePositions.rows() > 0 && vertices.rows() > 0) {
    for (int source = 0; source < constraints.sourcePositions.rows(); ++source) {
      double best = std::numeric_limits<double>::infinity();
      for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
        best = std::min(best, (constraints.sourcePositions.row(source) -
                              vertices.row(vertex))
                                 .norm());
      }
      sourceToOutputErrors.push_back(
          best / std::max(1.0e-12, options.targetSize));
    }
  }

  for (const int vertex : constraints.featureVertices) {
    Eigen::RowVector3d start;
    Eigen::RowVector3d end;
    if (vertex < 0 || vertex >= vertices.rows() ||
        !find_feature_interval(constraints, vertex, &start, &end)) {
      continue;
    }
    const Eigen::RowVector3d projected =
        project_to_interval(vertices.row(vertex), start, end);
    featureErrors.push_back((vertices.row(vertex) - projected).norm());
    const Eigen::RowVector3d railTangent = normalized_or_zero(end - start);
    double bestTangentError = std::numeric_limits<double>::infinity();
    for (int face = 0; face < quads.rows(); ++face) {
      for (int corner = 0; corner < 4; ++corner) {
        if (quads(face, corner) != vertex) {
          continue;
        }
        for (const int offset : {-1, 1}) {
          const int adjacent = quads(face, (corner + offset + 4) % 4);
          if (adjacent < 0 || adjacent >= vertices.rows() ||
              !contains(constraints.featureVertices, adjacent) ||
              feature_sequence_for_vertex(constraints, adjacent) !=
                  feature_sequence_for_vertex(constraints, vertex)) {
            continue;
          }
          const double error = angle_degrees(
              railTangent, vertices.row(adjacent) - vertices.row(vertex));
          bestTangentError =
              std::min(bestTangentError, std::min(error, 180.0 - error));
        }
      }
    }
    if (std::isfinite(bestTangentError)) {
      featureTangentErrors.push_back(bestTangentError);
    }
  }

  for (int face = 0; face < quads.rows(); ++face) {
    const SurfacePoint faceSource = quad_reference_surface_point(
        vertices, quads, face, constraints, provenance, &sourceProjection);
    const Eigen::RowVector3d sourceNormal =
        local_source_normal(constraints, faceSource, face);
    normalErrors.push_back(
        angle_degrees(face_normal(vertices, quads, face), sourceNormal));
    const SurfaceQuadQualityMetrics quality =
        evaluate_surface_quad_quality(vertices, quads, face, sourceNormal);
    if (!quality.convex) {
      ++report.nonConvex;
    }
    angles.push_back(quality.minimumAngleDegrees);
    angles.push_back(quality.maximumAngleDegrees);
    warpages.push_back(quality.warpageDegrees);
    aspects.push_back(quality.aspectRatio);
    jacobians.push_back(quality.signedScaledJacobian);

    for (int corner = 0; corner < 4; ++corner) {
      const int firstVertex = quads(face, corner);
      const int secondVertex = quads(face, (corner + 1) % 4);
      const Eigen::RowVector3d first = vertices.row(firstVertex);
      const Eigen::RowVector3d second = vertices.row(secondVertex);
      const Eigen::RowVector3d edge = second - first;
      const SurfacePoint firstPoint =
          firstVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(firstVertex)]
              : SurfacePoint{};
      const SurfacePoint secondPoint =
          secondVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(secondVertex)]
              : SurfacePoint{};
      const double target = effective_edge_target_size(
          constraints, firstPoint, secondPoint, firstVertex, secondVertex,
          edge.norm(), options.targetSize);
      sizeRatios.push_back(edge.norm() / std::max(1.0e-12, target));
      const int component = firstPoint.valid() ? firstPoint.component : -1;
      const int sheet = firstPoint.valid() ? firstPoint.sheet : -1;
      const SurfacePoint edgeSource = nearest_source_point(
          0.5 * (first + second), constraints, component, sheet,
          &sourceProjection);
      const double alignment = best_source_field_alignment(
          edge, constraints, edgeSource.valid() ? edgeSource : faceSource,
          face, &firstPoint, &secondPoint);
      fieldErrors.push_back(
          std::acos(alignment) * 180.0 / 3.14159265358979323846);
    }
  }

  report.quadToSourceSampleCount = quadToSourceErrors.size();
  report.sourceToOutputSampleCount = sourceToOutputErrors.size();
  report.quadToSourceP95 = percentile(quadToSourceErrors, 0.95);
  report.quadToSourceMax =
      quadToSourceErrors.empty()
          ? 0.0
          : *std::max_element(quadToSourceErrors.begin(),
                              quadToSourceErrors.end());
  report.sourceToOutputP95 = percentile(sourceToOutputErrors, 0.95);
  report.sourceToOutputMax =
      sourceToOutputErrors.empty()
          ? 0.0
          : *std::max_element(sourceToOutputErrors.begin(),
                              sourceToOutputErrors.end());
  report.surfaceP95 =
      std::max(report.quadToSourceP95, report.sourceToOutputP95);
  report.surfaceMax =
      std::max(report.quadToSourceMax, report.sourceToOutputMax);
  report.normalP95Degrees = percentile(normalErrors, 0.95);
  report.featureP95 = percentile(featureErrors, 0.95);
  report.featureMax =
      featureErrors.empty()
          ? 0.0
          : *std::max_element(featureErrors.begin(), featureErrors.end());
  report.featureTangentP95Degrees = percentile(featureTangentErrors, 0.95);
  report.fieldMedianDegrees = percentile(fieldErrors, 0.50);
  report.fieldP95Degrees = percentile(fieldErrors, 0.95);
  report.sizeP5 = percentile(sizeRatios, 0.05);
  report.sizeP95 = percentile(sizeRatios, 0.95);
  report.angleMinDegrees =
      angles.empty() ? 90.0 : *std::min_element(angles.begin(), angles.end());
  report.angleMaxDegrees =
      angles.empty() ? 90.0 : *std::max_element(angles.begin(), angles.end());
  report.angleP5Degrees = percentile(angles, 0.05);
  report.angleP95Degrees = percentile(angles, 0.95);
  report.warpageP95Degrees = percentile(warpages, 0.95);
  report.warpageMaxDegrees =
      warpages.empty() ? 0.0 : *std::max_element(warpages.begin(), warpages.end());
  report.aspectP95 = percentile(aspects, 0.95);
  report.aspectP99 = percentile(aspects, 0.99);
  report.scaledJacobianMin =
      jacobians.empty() ? 1.0
                        : *std::min_element(jacobians.begin(), jacobians.end());
  report.scaledJacobianP5 = percentile(jacobians, 0.05);

  const std::vector<std::set<int>> neighbors =
      quad_vertex_neighbors(quads, vertices.rows());
  const std::map<int, std::vector<int>> boundary =
      quad_boundary_neighbors(quads);
  for (const auto &[vertex, boundaryNeighbors] : boundary) {
    const auto explicitTarget = constraints.boundaryValenceTargets.find(vertex);
    const int target =
        explicitTarget != constraints.boundaryValenceTargets.end()
            ? explicitTarget->second
            : inferred_boundary_valence_target(vertices, vertex,
                                                boundaryNeighbors);
    ++report.boundaryValenceTargetCount;
    if (vertex < 0 || vertex >= static_cast<int>(neighbors.size()) ||
        static_cast<int>(neighbors[static_cast<std::size_t>(vertex)].size()) !=
            target) {
      ++report.boundaryValenceMismatchCount;
    }
  }
  for (const auto &[vertex, target] :
       constraints.requiredSingularityValenceTargets) {
    ++report.requiredSingularityValenceTargetCount;
    if (vertex < 0 || vertex >= static_cast<int>(neighbors.size()) ||
        static_cast<int>(neighbors[static_cast<std::size_t>(vertex)].size()) !=
            target) {
      ++report.requiredSingularityValenceMismatchCount;
    }
  }

  report.strictValidationUsed = true;
  report.provenanceValidationUsed = true;
  report.authoritativeBoundaryUsed =
      !constraints.authoritativeBoundaryEdges.empty() ||
      !constraints.authoritativeBoundaryLoop.empty() ||
      !constraints.authoritativeBoundaryLoops.empty();
  report.authoritativeFeatureRailsUsed =
      constraints.featureRailAuthorityProvided;
  std::vector<validation::MeshValidationIssue> validationIssues;
  bool strictValidationAccepted = false;
  if (constraints.requireSourceAuthoritativeValidation) {
    const auto sourceValidation =
        validation::validate_source_authoritative_surface_mesh(
            vertices, quads,
            make_source_authoritative_validator_options(constraints,
                                                        provenance));
    strictValidationAccepted = sourceValidation.accepted;
    validationIssues = sourceValidation.issues;
    report.sourceAuthoritativeValidationUsed =
        sourceValidation.sourceAuthorityUsed;
    report.spatialAccelerationUsed =
        sourceValidation.spatialAccelerationUsed;
    report.orderedBoundaryCyclesPassed =
        sourceValidation.orderedBoundaryCyclesPassed;
    report.authoritativeFeatureRailsPassed =
        sourceValidation.featureRailsPassed;
    report.localSheetCompatibilityPassed =
        sourceValidation.localSheetCompatibilityPassed;
  } else {
    validation::MeshValidatorOptions validatorOptions;
    validatorOptions.requireConsistentOrientation = true;
    validatorOptions.requireVertexProvenanceForGeometry = true;
    validatorOptions.vertexProvenance = provenance;
    validatorOptions.authoritativeBoundaryEdges =
        constraints.authoritativeBoundaryEdges;
    validatorOptions.authoritativeBoundaryLoop =
        constraints.authoritativeBoundaryLoop;
    validatorOptions.requireAuthoritativeBoundary =
        !constraints.authoritativeBoundaryEdges.empty() ||
        !constraints.authoritativeBoundaryLoop.empty();
    const auto basicValidation =
        validation::MeshValidator::validate_surface_mesh(
            vertices, quads, validatorOptions);
    strictValidationAccepted = basicValidation.accepted;
    validationIssues = basicValidation.issues;
    report.orderedBoundaryCyclesPassed =
        basicValidation.accepted ||
        (!validatorOptions.requireAuthoritativeBoundary &&
         constraints.authoritativeBoundaryLoops.empty());
    report.authoritativeFeatureRailsPassed =
        constraints.requiredFeatureRailCount == 0U;
    report.localSheetCompatibilityPassed =
        optimization.projectionStayedOnSheets;
  }
  for (const auto &issue : validationIssues) {
    if (issue.code ==
        validation::MeshValidationFailureCode::GeometricVertexOnUnsplitEdge) {
      ++report.tJunctions;
    } else if (issue.code ==
                   validation::MeshValidationFailureCode::ThreeSidedInteriorEdge ||
               issue.code ==
                   validation::MeshValidationFailureCode::OneSidedInteriorEdge) {
      ++report.nonManifold;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::ZeroAreaFace) {
      ++report.degenerate;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::FlippedFace) {
      ++report.inverted;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::SelfIntersectingFace) {
      ++report.selfIntersecting;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::DuplicateFace) {
      ++report.duplicateFaceCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::BowTieVertex) {
      ++report.bowTieVertexCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::ComponentMerge) {
      ++report.connectedComponentMismatchCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::ChangedEulerCharacteristic) {
      ++report.eulerCharacteristicMismatchCount;
    } else if (issue.code ==
                   validation::MeshValidationFailureCode::ChangedBoundaryLoop ||
               issue.code ==
                   validation::MeshValidationFailureCode::MissingBoundaryAuthority ||
               issue.code ==
                   validation::MeshValidationFailureCode::WrongBoundaryEdge) {
      ++report.boundaryCycleMismatchCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::MissingFeatureRail) {
      ++report.featureRailMismatchCount;
    } else if (issue.code ==
                   validation::MeshValidationFailureCode::MissingProvenance ||
               issue.code ==
                   validation::MeshValidationFailureCode::MissingSourceAuthority ||
               issue.code ==
                   validation::MeshValidationFailureCode::InvalidProvenance ||
               issue.code ==
                   validation::MeshValidationFailureCode::SourceComponentMismatch ||
               issue.code ==
                   validation::MeshValidationFailureCode::SourceSheetMismatch ||
               issue.code ==
                   validation::MeshValidationFailureCode::SourcePositionMismatch) {
      ++report.provenanceFailureCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::LocalSheetMismatch) {
      ++report.localSheetMismatchCount;
    }
  }
  report.topologyHashFixed = optimization.topologyHashFixed;
  report.featureParametersOrdered = optimization.featureParametersOrdered;
  report.projectionStayedOnComponents =
      optimization.projectionStayedOnComponents;
  report.optimizerTimeWithinGate =
      optimizerSeconds <=
      options.maxOptimizerTimeRatio * std::max(1.0e-12, endToEndSeconds);
  report.accepted =
      strictValidationAccepted &&
      report.quadToSourceP95 <= 0.15 && report.quadToSourceMax <= 0.50 &&
      report.sourceToOutputP95 <= 0.15 && report.sourceToOutputMax <= 0.50 &&
      report.normalP95Degrees <= 15.0 &&
      report.fieldMedianDegrees <= 7.5 && report.fieldP95Degrees <= 15.0 &&
      report.sizeP5 >= 0.50 && report.sizeP95 <= 2.00 &&
      report.angleP5Degrees >= 35.0 && report.angleP95Degrees <= 145.0 &&
      report.warpageP95Degrees <= 30.0 && report.warpageMaxDegrees <= 60.0 &&
      report.aspectP95 <= 4.0 && report.aspectP99 <= 8.0 &&
      report.scaledJacobianMin > 0.0 && report.scaledJacobianP5 >= 0.20 &&
      report.nonConvex == 0 && report.boundaryValenceMismatchCount == 0 &&
      report.requiredSingularityValenceMismatchCount == 0 &&
      report.tJunctions == 0 && report.nonManifold == 0 &&
      report.degenerate == 0 && report.inverted == 0 &&
      report.selfIntersecting == 0 && report.topologyHashFixed &&
      report.featureParametersOrdered && report.projectionStayedOnComponents &&
      (!options.enforceOptimizerTimeGate || report.optimizerTimeWithinGate);
  return report;
}
#else
SurfaceFinalValidationReport validate_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options = {},
    const double optimizerSeconds = 0.0, const double endToEndSeconds = 1.0);
#endif

#if defined(DIRECTIONAL_SURFACE_MESH_OPTIMIZER_IMPLEMENTATION)
SurfaceOptimizationOverlay make_surface_optimization_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {}) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationOverlay overlay;
  overlay.wireframeStarts.resize(4 * quads.rows(), 3);
  overlay.wireframeEnds.resize(4 * quads.rows(), 3);
  overlay.shadedVertices = vertices;
  overlay.surfaceError = Eigen::VectorXd::Zero(vertices.rows());
  overlay.normalError = Eigen::VectorXd::Zero(quads.rows());
  overlay.fieldAlignmentError = Eigen::VectorXd::Zero(4 * quads.rows());
  overlay.sizeRatio = Eigen::VectorXd::Zero(4 * quads.rows());
  overlay.poleValence = Eigen::VectorXi::Zero(vertices.rows());
  overlay.targetValence = Eigen::VectorXi::Constant(vertices.rows(), 4);
  overlay.valenceError = Eigen::VectorXi::Zero(vertices.rows());

  std::vector<SurfacePoint> provenance;
  SourceProjectionCache sourceProjection(constraints);
  project_vertices(vertices, constraints, nullptr, nullptr, nullptr, nullptr,
                   nullptr, &provenance, &sourceProjection);
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    const SurfacePoint point =
        vertex < static_cast<int>(provenance.size())
            ? provenance[static_cast<std::size_t>(vertex)]
            : nearest_source_point(vertices.row(vertex), constraints);
    if (point.valid()) {
      const double target =
          local_target_size(constraints, point, vertex, options.targetSize);
      overlay.surfaceError(vertex) =
          (vertices.row(vertex) - point.position.transpose()).norm() /
          std::max(1.0e-12, target);
    }
  }

  for (int face = 0; face < quads.rows(); ++face) {
    const SurfacePoint faceSource = quad_reference_surface_point(
        vertices, quads, face, constraints, provenance, &sourceProjection);
    overlay.normalError(face) = angle_degrees(
        face_normal(vertices, quads, face),
        local_source_normal(constraints, faceSource, face));
    for (int corner = 0; corner < 4; ++corner) {
      const int row = 4 * face + corner;
      const int firstVertex = quads(face, corner);
      const int secondVertex = quads(face, (corner + 1) % 4);
      const Eigen::RowVector3d first = vertices.row(firstVertex);
      const Eigen::RowVector3d second = vertices.row(secondVertex);
      overlay.wireframeStarts.row(row) = first;
      overlay.wireframeEnds.row(row) = second;
      const SurfacePoint firstPoint =
          firstVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(firstVertex)]
              : SurfacePoint{};
      const SurfacePoint secondPoint =
          secondVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(secondVertex)]
              : SurfacePoint{};
      const double target = effective_edge_target_size(
          constraints, firstPoint, secondPoint, firstVertex, secondVertex,
          (second - first).norm(), options.targetSize);
      overlay.sizeRatio(row) =
          (second - first).norm() / std::max(1.0e-12, target);

      const int component = firstPoint.valid() ? firstPoint.component : -1;
      const int sheet = firstPoint.valid() ? firstPoint.sheet : -1;
      const SurfacePoint edgeSource = nearest_source_point(
          0.5 * (first + second), constraints, component, sheet,
          &sourceProjection);
      const double alignment = best_source_field_alignment(
          second - first, constraints,
          edgeSource.valid() ? edgeSource : faceSource, face, &firstPoint,
          &secondPoint);
      overlay.fieldAlignmentError(row) =
          std::acos(alignment) * 180.0 / 3.14159265358979323846;
    }
  }

  const std::vector<std::set<int>> overlayNeighbors =
      quad_vertex_neighbors(quads, vertices.rows());
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    overlay.poleValence(vertex) = static_cast<int>(
        overlayNeighbors[static_cast<std::size_t>(vertex)].size());
  }

  const std::map<int, std::vector<int>> boundary =
      quad_boundary_neighbors(quads);
  for (const auto &[vertex, boundaryNeighbors] : boundary) {
    const auto explicitTarget = constraints.boundaryValenceTargets.find(vertex);
    overlay.targetValence(vertex) =
        explicitTarget != constraints.boundaryValenceTargets.end()
            ? explicitTarget->second
            : inferred_boundary_valence_target(vertices, vertex,
                                                boundaryNeighbors);
  }
  for (const auto &[vertex, target] :
       constraints.requiredSingularityValenceTargets) {
    if (vertex >= 0 && vertex < overlay.targetValence.size()) {
      overlay.targetValence(vertex) = target;
    }
  }
  overlay.valenceError = overlay.poleValence - overlay.targetValence;

  const int sourceSampleCount =
      constraints.sourceVertices.rows() > 0
          ? constraints.sourceVertices.rows()
          : constraints.sourcePositions.rows();
  overlay.sourceToOutputError = Eigen::VectorXd::Zero(sourceSampleCount);
  if (sourceSampleCount > 0 && quads.rows() > 0) {
    OutputProjectionCache outputProjection(vertices, quads, provenance,
                                           &constraints);
    for (int source = 0; source < sourceSampleCount; ++source) {
      const Eigen::RowVector3d position =
          constraints.sourceVertices.rows() > 0
              ? constraints.sourceVertices.row(source)
              : constraints.sourcePositions.row(source);
      int component = -1;
      int sheet = -1;
      SurfacePoint sourcePoint;
      if (constraints.sourceVertices.rows() > 0 &&
          constraints.sourceFaces.rows() > 0) {
        for (int face = 0; face < constraints.sourceFaces.rows(); ++face) {
          for (int corner = 0; corner < 3; ++corner) {
            if (constraints.sourceFaces(face, corner) != source) {
              continue;
            }
            sourcePoint.face = face;
            sourcePoint.barycentric.setZero();
            sourcePoint.barycentric(corner) = 1.0;
            sourcePoint.position = position.transpose();
            sourcePoint.component =
                face < static_cast<int>(constraints.sourceFaceComponent.size())
                    ? constraints.sourceFaceComponent[static_cast<std::size_t>(face)]
                    : -1;
            sourcePoint.sheet =
                face < static_cast<int>(constraints.sourceFaceSheet.size())
                    ? constraints.sourceFaceSheet[static_cast<std::size_t>(face)]
                    : -1;
            component = sourcePoint.component;
            sheet = sourcePoint.sheet;
            break;
          }
          if (sourcePoint.valid()) {
            break;
          }
        }
      }
      const SurfacePoint projected =
          outputProjection.project(position, component, sheet);
      if (projected.valid()) {
        const double target = sourcePoint.valid()
                                  ? local_target_size(constraints, sourcePoint,
                                                      source, options.targetSize)
                                  : options.targetSize;
        overlay.sourceToOutputError(source) =
            std::sqrt(projected.squaredDistance) /
            std::max(1.0e-12, target);
      } else {
        overlay.sourceToOutputError(source) =
            std::numeric_limits<double>::infinity();
      }
    }
  }
  return overlay;
}
#else
SurfaceOptimizationOverlay make_surface_optimization_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});
#endif

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_MESH_OPTIMIZER_H
