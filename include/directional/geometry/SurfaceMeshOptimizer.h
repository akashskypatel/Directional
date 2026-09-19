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
#include <compare>
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
  // Maximum unconstrained displacement at alpha=1, expressed in local target
  // cell widths. This trust region makes line-search behavior scale invariant
  // even when one energy term produces a very large raw gradient.
  double maxStepTargetFraction = 0.25;
  int maxLineSearchTrials = 24;
  double maxOptimizerTimeRatio = 0.25;
  bool enforceOptimizerTimeGate = true;
  // Raw multi-energy gradients can differ by several orders of magnitude on
  // irregular input triangulations. Keep halving far enough to find a
  // topology-safe projected step instead of declaring failure while the
  // smallest trial still crosses an output edge.
  std::array<double, 24> lineSearchSteps = {
      1.0,
      0.5,
      0.25,
      0.125,
      0.0625,
      0.03125,
      0.015625,
      0.0078125,
      0.00390625,
      0.001953125,
      0.0009765625,
      0.00048828125,
      0.000244140625,
      0.0001220703125,
      0.00006103515625,
      0.000030517578125,
      0.0000152587890625,
      0.00000762939453125,
      0.000003814697265625,
      0.0000019073486328125,
      0.00000095367431640625,
      0.000000476837158203125,
      0.0000002384185791015625,
      0.00000011920928955078125};
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
  double parameterStart = 0.0;
  double parameterEnd = 1.0;
  bool curveClosed = false;
  std::optional<authority::HardRailId> railId;
};

struct SurfaceFeatureSequenceKey {
  std::optional<authority::HardRailId> rail;
  int curveId = -1;

  auto operator<=>(const SurfaceFeatureSequenceKey &) const = default;
};

struct SurfaceOptimizationConstraints {
  Eigen::MatrixXd sourceVertices;
  Eigen::MatrixXi sourceFaces;
  Eigen::MatrixXd sourceNormals;
  Eigen::MatrixXd sourceFieldX;
  Eigen::MatrixXd sourceFieldY;
  // Complete source authority for all semantic region/component/sheet queries.
  // The pipeline owns this product for the complete optimizer lifetime.
  const SourceTopologyRegions *sourceAuthority = nullptr;
  // Authoritative source chart at each output quad center. Vertex provenance
  // is intentionally multi-chart on source vertices and edges, so it cannot
  // by itself select a stable orientation/field chart for the whole quad.
  std::vector<int> outputQuadSourceFaces;
  std::set<authority::SourceEdgeTopologyKey> sourceHardFeatureEdges;
  bool constrainVerticesToProvenanceEntities = false;
  std::vector<std::vector<int>> sourceVertexFaces;
  std::map<std::pair<int, int>, std::vector<int>> sourceEdgeFaces;
  Eigen::VectorXd localTargetSize;
  std::vector<int> fixedVertices;
  std::vector<int> featureVertices;
  std::vector<int> softFeatureVertices;
  std::vector<SurfaceFeatureCurveInterval> featureCurveIntervals;
  Eigen::VectorXi featureCurveIds;
  std::vector<std::optional<authority::HardRailId>> featureRailIds;
  Eigen::VectorXi featureIntervalIds;
  Eigen::VectorXd featureParameters;
  std::vector<int> orderedFeatureVertices;
  std::vector<SurfacePoint> vertexProvenance;
  std::vector<validation::SourceVertexChartAuthority> vertexChartAuthority;
  std::set<std::pair<int, int>> authoritativeBoundaryEdges;
  std::vector<int> authoritativeBoundaryLoop;
  std::vector<std::vector<int>> authoritativeBoundaryLoops;
  std::vector<std::vector<int>> authoritativeFeatureRails;
  std::size_t requiredFeatureRailCount = 0;
  std::vector<authority::HardRailId> missingFeatureRailIds;
  // Distinguishes an explicitly supplied empty authority set from callers
  // that never configured feature-rail authority. An empty authoritative set
  // is still meaningful: it proves that no hard feature rails are expected.
  bool featureRailAuthorityProvided = false;
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
  std::vector<validation::MeshValidationIssue> lastHardInvariantIssues;
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
  double maximumRawGradientRowNorm = 0.0;
  std::size_t trustRegionScaleCount = 0;
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
  // Retained for actionable production diagnostics; aggregate counters alone
  // cannot identify the offending output face, edge, or missing rail.
  std::vector<validation::MeshValidationIssue> strictValidationIssues;
  std::vector<authority::HardRailId> missingFeatureRailIds;
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

bool contains(const std::vector<int> &values, const int value);

bool armijo_sufficient_decrease(const double currentEnergy,
                                       const double trialEnergy,
                                       const double alpha,
                                       const double descentDirectionalDerivative,
                                       const double armijo);

Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v);

Eigen::RowVector3d tangent_direction(
    const Eigen::RowVector3d &vector,
    const Eigen::RowVector3d &surfaceNormal);

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b);

std::uint64_t topology_hash(const Eigen::MatrixXi &quads);

Eigen::RowVector3d project_to_interval(const Eigen::RowVector3d &p,
                                              const Eigen::RowVector3d &a,
                                              const Eigen::RowVector3d &b,
                                              double *parameter = nullptr);

struct SourceProjectionScope {
  std::optional<authority::SourceComponentId> component;
  std::optional<authority::IsolationSheetId> sheet;

  [[nodiscard]] bool constrained() const noexcept {
    return component.has_value() || sheet.has_value();
  }

  auto operator<=>(const SourceProjectionScope &) const = default;
};

[[nodiscard]] inline std::optional<SourceProjectionScope> source_face_scope(
    const SurfaceOptimizationConstraints &constraints, const int face) {
  if (constraints.sourceAuthority == nullptr || face < 0 ||
      face >= constraints.sourceFaces.rows() ||
      !constraints.sourceAuthority->matches_source_faces(
          constraints.sourceFaces,
          static_cast<std::size_t>(constraints.sourceVertices.rows()))) {
    return std::nullopt;
  }
  const auto row = authority::SourceFaceId::from_index(
      face, constraints.sourceAuthority->face_count());
  if (!row) {
    return std::nullopt;
  }
  return SourceProjectionScope{
      constraints.sourceAuthority->component_for_row(row.value()),
      constraints.sourceAuthority->sheet_for_row(row.value())};
}

[[nodiscard]] inline bool source_scope_matches(
    const SourceProjectionScope &candidate,
    const SourceProjectionScope &required) noexcept {
  return (!required.component.has_value() ||
          candidate.component == required.component) &&
         (!required.sheet.has_value() || candidate.sheet == required.sheet);
}

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
      const SourceProjectionScope &requiredScope) {
    if (!bvh.has_value() || !requiredScope.constrained()) {
      return nullptr;
    }
    const auto existing = allowedFaceMasks.find(requiredScope);
    if (existing != allowedFaceMasks.end()) {
      return &existing->second;
    }

    std::vector<unsigned char> mask(
        static_cast<std::size_t>(constraints->sourceFaces.rows()), 1);
    const bool authorityComplete =
        constraints->sourceAuthority != nullptr &&
        constraints->sourceAuthority->matches_source_faces(
            constraints->sourceFaces,
            static_cast<std::size_t>(constraints->sourceVertices.rows()));
    for (int face = 0; face < constraints->sourceFaces.rows(); ++face) {
      const auto row = authority::SourceFaceId::from_index(
          face, static_cast<std::size_t>(constraints->sourceFaces.rows()));
      if (!authorityComplete || !row) {
        mask[static_cast<std::size_t>(face)] = 0;
        continue;
      }
      const SourceProjectionScope candidate{
          constraints->sourceAuthority->component_for_row(row.value()),
          constraints->sourceAuthority->sheet_for_row(row.value())};
      if (!source_scope_matches(candidate, requiredScope)) {
        mask[static_cast<std::size_t>(face)] = 0;
      }
    }
    return &allowedFaceMasks.emplace(requiredScope, std::move(mask))
                .first->second;
  }

  [[nodiscard]] const std::vector<unsigned char> *allowed_faces(
      const std::vector<int> &requiredFaces) {
    if (!bvh.has_value() || requiredFaces.empty()) {
      return nullptr;
    }
    std::vector<int> key = requiredFaces;
    std::sort(key.begin(), key.end());
    key.erase(std::unique(key.begin(), key.end()), key.end());
    const auto existing = exactAllowedFaceMasks.find(key);
    if (existing != exactAllowedFaceMasks.end()) {
      return &existing->second;
    }
    std::vector<unsigned char> mask(
        static_cast<std::size_t>(constraints->sourceFaces.rows()), 0);
    for (const int face : key) {
      if (face >= 0 && face < constraints->sourceFaces.rows()) {
        mask[static_cast<std::size_t>(face)] = 1;
      }
    }
    return &exactAllowedFaceMasks.emplace(std::move(key), std::move(mask))
                .first->second;
  }

  [[nodiscard]] SurfacePoint project(
      const Eigen::RowVector3d &point,
      const std::optional<SourceProjectionScope> &requiredScope = std::nullopt) {
    ++queryCount;
    if (!bvh.has_value()) {
      return {};
    }
    SurfaceProjectionOptions options;
    options.allowedFaces =
        requiredScope.has_value() ? allowed_faces(*requiredScope) : nullptr;
    return bvh->project(point.transpose(), options);
  }

  [[nodiscard]] SurfacePoint project(const Eigen::RowVector3d &point,
                                     const std::vector<int> &requiredFaces) {
    ++queryCount;
    if (!bvh.has_value() || requiredFaces.empty()) {
      return {};
    }
    SurfaceProjectionOptions options;
    options.allowedFaces = allowed_faces(requiredFaces);
    return bvh->project(point.transpose(), options);
  }

  const SurfaceOptimizationConstraints *constraints = nullptr;
  std::optional<SurfaceProjectionBvh> bvh;
  std::map<SourceProjectionScope, std::vector<unsigned char>> allowedFaceMasks;
  std::map<std::vector<int>, std::vector<unsigned char>> exactAllowedFaceMasks;
  std::size_t queryCount = 0;
};

Eigen::RowVector3d source_point_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfacePoint &point);

SurfacePoint nearest_source_point(
    const Eigen::RowVector3d &p, const SurfaceOptimizationConstraints &constraints,
    const std::optional<SourceProjectionScope> &requiredScope = std::nullopt,
    SourceProjectionCache *projectionCache = nullptr);

int feature_curve_for_vertex(const SurfaceOptimizationConstraints &constraints,
                                    const int vertex);

SurfaceFeatureSequenceKey feature_sequence_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex);

int feature_interval_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex);

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

SurfaceFeatureProjection project_to_feature_curve(
    const Eigen::RowVector3d &point,
    const SurfaceOptimizationConstraints &constraints, const int vertex);

bool find_feature_interval(
    const SurfaceOptimizationConstraints &constraints, const int vertex,
    Eigen::RowVector3d *start, Eigen::RowVector3d *end);

Eigen::RowVector3d local_source_normal(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace);

struct LocalSourceCross {
  Eigen::RowVector3d x = {1.0, 0.0, 0.0};
  Eigen::RowVector3d y = {0.0, 1.0, 0.0};
};

Eigen::RowVector3d tangent_reference(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::RowVector3d &normal);

LocalSourceCross local_source_cross(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace);

std::vector<int> compatible_source_field_charts(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point);

double best_source_field_alignment(
    const Eigen::RowVector3d &edge,
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point, const int fallbackFace,
    const SurfacePoint *firstEndpoint = nullptr,
    const SurfacePoint *secondEndpoint = nullptr);

Eigen::RowVector3d source_triangle_scalar_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::VectorXd &values);

Eigen::RowVector3d local_target_size_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point);

double local_target_size(const SurfaceOptimizationConstraints &constraints,
                                const SurfacePoint &point,
                                const int fallbackVertex,
                                const double globalTargetSize);

inline constexpr double kMaxImmutableRailSizeRatio = 4.0;

bool immutable_rail_edge(
    const SurfaceOptimizationConstraints &constraints, const int firstVertex,
    const int secondVertex);

double effective_edge_target_size(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &firstPoint, const SurfacePoint &secondPoint,
    const int firstVertex, const int secondVertex, const double edgeLength,
    const double globalTargetSize);

bool provenance_is_complete(
    const SurfacePoint &point,
    const SurfaceOptimizationConstraints &constraints);

Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices, const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters = nullptr,
    bool *ordered = nullptr, bool *componentsOk = nullptr,
    bool *sheetsOk = nullptr, bool *completeProvenance = nullptr,
    std::vector<SurfacePoint> *provenance = nullptr,
    SourceProjectionCache *projectionCache = nullptr);

Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters, bool *ordered, bool *componentsOk,
    std::vector<SurfacePoint> *provenance);

Eigen::RowVector3d face_normal(const Eigen::MatrixXd &v,
                                      const Eigen::MatrixXi &q,
                                      const int face);

std::vector<double> sorted_percentiles(std::vector<double> values);

double percentile(std::vector<double> values, const double p);

double angle_degrees(const Eigen::RowVector3d &a,
                            const Eigen::RowVector3d &b);

struct FaceChartAuthorityView {
  bool valid = true;
  std::vector<const validation::SourceVertexChartAuthority *> vertices;
};

FaceChartAuthorityView quad_chart_authority(
    const Eigen::MatrixXi &quads, const int face,
    const SurfaceOptimizationConstraints &constraints,
    const std::size_t provenanceCount);

std::optional<SourceProjectionScope> consistent_source_scope(
    const Eigen::MatrixXi &quads, const int face,
    const std::vector<SurfacePoint> &provenance,
    const SurfaceOptimizationConstraints *constraints = nullptr);

SurfacePoint quad_reference_surface_point(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance,
    SourceProjectionCache *projectionCache = nullptr);

Eigen::RowVector3d quad_bilinear_sample(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const double u, const double v);

std::vector<Eigen::Vector3d> triangle_sample_barycentrics();

struct OutputProjectionCache {
  Eigen::MatrixXi triangles;
  std::vector<std::set<SourceProjectionScope>> faceScopes;
  std::optional<SurfaceProjectionBvh> bvh;
  std::map<SourceProjectionScope, std::vector<unsigned char>> masks;

  OutputProjectionCache(const Eigen::MatrixXd &vertices,
                         const Eigen::MatrixXi &quads,
                         const std::vector<SurfacePoint> &provenance,
                         const SurfaceOptimizationConstraints *constraints =
                             nullptr) {
    triangles.resize(2 * quads.rows(), 3);
    faceScopes.resize(static_cast<std::size_t>(2 * quads.rows()));
    const validation::source_authoritative_detail::SourcePointLabelSupport
        labelSupport(
            constraints != nullptr ? &constraints->sourceFaces : nullptr,
            constraints != nullptr ? constraints->sourceAuthority : nullptr,
            constraints != nullptr ? &constraints->sourceHardFeatureEdges
                                   : nullptr);
    for (int face = 0; face < quads.rows(); ++face) {
      triangles.row(2 * face) << quads(face, 0), quads(face, 1), quads(face, 2);
      triangles.row(2 * face + 1) << quads(face, 0), quads(face, 2), quads(face, 3);
      const auto fallbackScope =
          consistent_source_scope(quads, face, provenance, constraints);
      std::set<SourceProjectionScope> scopes;
      if (constraints != nullptr && labelSupport.available()) {
        std::vector<const SurfacePoint *> points;
        points.reserve(4);
        for (int corner = 0; corner < 4; ++corner) {
          const int vertex = quads(face, corner);
          if (vertex < 0 || vertex >= static_cast<int>(provenance.size())) {
            points.clear();
            break;
          }
          points.push_back(&provenance[static_cast<std::size_t>(vertex)]);
        }
        const FaceChartAuthorityView authority =
            quad_chart_authority(quads, face, *constraints,
                                 provenance.size());
        if (authority.valid) {
          const std::vector<int> chartFaces = labelSupport.compatible_chart_faces(
              points, authority.vertices, &provenance,
              &constraints->vertexChartAuthority);
          for (const int sourceFace : chartFaces) {
            const auto scope = source_face_scope(*constraints, sourceFace);
            if (scope.has_value()) {
              scopes.insert(*scope);
            }
          }
        }
      }
      if (scopes.empty() && fallbackScope.has_value()) {
        scopes.insert(*fallbackScope);
      }
      faceScopes[static_cast<std::size_t>(2 * face)] = scopes;
      faceScopes[static_cast<std::size_t>(2 * face + 1)] = std::move(scopes);
    }
    if (vertices.rows() > 0 && triangles.rows() > 0) {
      bvh.emplace(vertices, triangles);
    }
  }

  const std::vector<unsigned char> *allowed_faces(
      const SourceProjectionScope &requiredScope) {
    if (!requiredScope.constrained()) {
      return nullptr;
    }
    const auto existing = masks.find(requiredScope);
    if (existing != masks.end()) {
      return &existing->second;
    }
    std::vector<unsigned char> mask(
        static_cast<std::size_t>(triangles.rows()), 1);
    for (int face = 0; face < triangles.rows(); ++face) {
      const auto &scopes = faceScopes[static_cast<std::size_t>(face)];
      const bool supported = std::any_of(
          scopes.begin(), scopes.end(), [&](const SourceProjectionScope &scope) {
            return source_scope_matches(scope, requiredScope);
          });
      if (!supported) {
        mask[static_cast<std::size_t>(face)] = 0;
      }
    }
    return &masks.emplace(requiredScope, std::move(mask)).first->second;
  }

  SurfacePoint project(
      const Eigen::RowVector3d &point,
      const std::optional<SourceProjectionScope> &requiredScope) {
    if (!bvh.has_value() || !requiredScope.has_value() ||
        !requiredScope->constrained()) {
      return {};
    }
    SurfaceProjectionOptions options;
    options.allowedFaces = allowed_faces(*requiredScope);
    return bvh->project(point.transpose(), options);
  }
};

std::map<std::pair<int, int>, int> quad_edge_incidence(
    const Eigen::MatrixXi &quads);

std::vector<std::set<int>> quad_vertex_neighbors(
    const Eigen::MatrixXi &quads, const int vertexCount);

std::map<int, std::vector<int>> quad_boundary_neighbors(
    const Eigen::MatrixXi &quads);

int inferred_boundary_valence_target(
    const Eigen::MatrixXd &vertices, const int vertex,
    const std::vector<int> &boundaryNeighbors);

Eigen::RowVector3d normalized_pullback(
    const Eigen::RowVector3d &raw,
    const Eigen::RowVector3d &normalizedGradient);

Eigen::RowVector3d feature_order_coordinate_gradient(
    const SurfaceFeatureProjection &projection);

std::vector<int> ordered_feature_vertices(
    const SurfaceOptimizationConstraints &constraints);

double feature_order_energy(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints);

SurfaceOptimizationGradient zero_surface_optimization_gradient(
    const int vertexCount, const int dimensions);

void add_edge_length_gradient(Eigen::MatrixXd &gradient,
                                     const int firstVertex,
                                     const int secondVertex,
                                     const Eigen::RowVector3d &edge,
                                     const double derivativeByLength);

void zero_fixed_gradient_rows(
    SurfaceOptimizationGradient &gradient,
    const SurfaceOptimizationConstraints &constraints);

} // namespace surface_optimizer_detail

std::complex<double> degree_four_average(
    const std::vector<double> &anglesRadians,
    const std::vector<double> &connectionAnglesRadians = {},
    const std::vector<double> &weights = {});

SurfaceOptimizationEnergy evaluate_surface_optimization_energy_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache);

SurfaceOptimizationEnergy evaluate_surface_optimization_energy(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options);

double signed_scaled_jacobian(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads, const int face,
    const Eigen::RowVector3d &sourceNormal);

std::vector<unsigned char> source_boundary_vertex_mask(
    const Eigen::MatrixXi &sourceFaces, const int sourceVertexCount);

void fill_required_singularity_valence_targets(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const Eigen::VectorXi &singularCycles,
    const Eigen::VectorXi &singularIndices,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints);

SurfaceQuadQualityMetrics evaluate_surface_quad_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const Eigen::RowVector3d &sourceNormal);

bool local_orientation_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints *constraints = nullptr,
    const std::vector<SurfacePoint> *vertexProvenance = nullptr,
    surface_optimizer_detail::SourceProjectionCache *projectionCache = nullptr);

validation::SourceAuthoritativeMeshValidatorOptions
make_source_authoritative_validator_options(
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance);

bool source_optimization_has_complete_authority(
    const SurfaceOptimizationConstraints &constraints);

bool source_authoritative_hard_invariants_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance,
    std::vector<validation::MeshValidationIssue> *issues = nullptr);

// Computes the optimizer derivative directly per enabled energy. Geometric
// terms use closed-form derivatives. Source-normal and 4-RoSy transport
// depend on piecewise source-triangle projection and normalized barycentric
// interpolation, so only those local source-data pullbacks use centered
// differences; the full objective is never finite-differenced by the optimizer.
SurfaceOptimizationGradient evaluate_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache);

SurfaceOptimizationGradient evaluate_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});

Eigen::MatrixXd finite_difference_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache);

Eigen::MatrixXd finite_difference_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});

// Generic/non-SurfaceCells optimizer entry point. Production SurfaceCells
// publication must use optimize_source_authoritative_surface_mesh().
SurfaceOptimizationResult optimize_projected_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});

SurfaceOptimizationResult optimize_source_authoritative_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});

// Generic/non-SurfaceCells validation entry point. Production SurfaceCells
// publication must use validate_source_authoritative_final_surface_mesh().
SurfaceFinalValidationReport validate_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options = {},
    const double optimizerSeconds = 0.0, const double endToEndSeconds = 1.0);

SurfaceFinalValidationReport validate_source_authoritative_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options = {},
    const double optimizerSeconds = 0.0, const double endToEndSeconds = 1.0);

SurfaceOptimizationOverlay make_surface_optimization_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options = {});

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_MESH_OPTIMIZER_H
