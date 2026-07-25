// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
#define DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H

#include <chrono>
#include <algorithm>
#include <array>
#include <cmath>
#include <cctype>
#include <future>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

#include <Eigen/Core>

#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/diagnostics/RemeshDiagnostics.h>
#include <directional/fields/CrossFieldTransfer.h>
#include <directional/fields/CrossField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/AdaptiveTargetSize.h>
#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/ReliefTopology.h>
#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfaceComplexSimplification.h>
#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/geometry/BoundedMeshPreconditioner.h>
#include <directional/geometry/MeshComponents.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/integration/Integrate.h>
#include <directional/integration/IntegrationData.h>
#include <directional/integration/IntegrationSolveStrategy.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/meshing/Mesher.h>
#include <directional/meshing/MesherData.h>
#include <directional/meshing/SetupMesher.h>
#include <directional/util/Progress.h>

/**
 * @file RemeshPipeline.h
 * @brief High-level remeshing pipeline API.
 *
 * Exposes convenience functions that convert mesh vertices, faces, and cross-field directions into a remeshed output by running tangent-bundle construction, matching, combing, integration, and meshing.
 */

namespace directional::pipeline {

enum class RemeshBackend {
  LegacyInteger,
  Legacy = LegacyInteger,
  SurfaceCells
};

enum class SurfaceCellFallbackPolicy {
  Fail,
  ReturnQuadDominant,
  TryLegacy
};

enum class SurfaceCellFailureCode {
  None,
  InvalidFieldDimensions,
  MissingMatching,
  MissingSingularities,
  UnsupportedInput,
  InjectedStageFailure,
  NotProductionReady
};

inline std::string remesh_backend_name(const RemeshBackend backend) {
  switch (backend) {
  case RemeshBackend::LegacyInteger:
    return "LegacyInteger";
  case RemeshBackend::SurfaceCells:
    return "SurfaceCells";
  }
  return "Unknown";
}

inline std::string
surface_cell_fallback_policy_name(const SurfaceCellFallbackPolicy policy) {
  switch (policy) {
  case SurfaceCellFallbackPolicy::Fail:
    return "Fail";
  case SurfaceCellFallbackPolicy::ReturnQuadDominant:
    return "ReturnQuadDominant";
  case SurfaceCellFallbackPolicy::TryLegacy:
    return "TryLegacy";
  }
  return "Unknown";
}

inline std::string
surface_cell_failure_code_name(const SurfaceCellFailureCode code) {
  switch (code) {
  case SurfaceCellFailureCode::None:
    return "None";
  case SurfaceCellFailureCode::InvalidFieldDimensions:
    return "InvalidFieldDimensions";
  case SurfaceCellFailureCode::MissingMatching:
    return "MissingMatching";
  case SurfaceCellFailureCode::MissingSingularities:
    return "MissingSingularities";
  case SurfaceCellFailureCode::UnsupportedInput:
    return "UnsupportedInput";
  case SurfaceCellFailureCode::InjectedStageFailure:
    return "InjectedStageFailure";
  case SurfaceCellFailureCode::NotProductionReady:
    return "NotProductionReady";
  }
  return "Unknown";
}

inline std::string normalize_option_token(std::string value) {
  value.erase(std::remove_if(value.begin(), value.end(),
                             [](const char character) {
                               return character == '-' || character == '_';
                             }),
              value.end());
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

inline RemeshBackend parse_remesh_backend(const std::string &value) {
  const std::string token = normalize_option_token(value);
  if (token == "legacy" || token == "legacyinteger") {
    return RemeshBackend::LegacyInteger;
  }
  if (token == "surfacecells" || token == "surfacecell") {
    return RemeshBackend::SurfaceCells;
  }
  throw std::runtime_error(
      "Backend must be LegacyInteger or SurfaceCells.");
}

inline SurfaceCellFallbackPolicy
parse_surface_cell_fallback_policy(const std::string &value) {
  const std::string token = normalize_option_token(value);
  if (token == "fail") {
    return SurfaceCellFallbackPolicy::Fail;
  }
  if (token == "returnquaddominant" || token == "quaddominant") {
    return SurfaceCellFallbackPolicy::ReturnQuadDominant;
  }
  if (token == "trylegacy") {
    return SurfaceCellFallbackPolicy::TryLegacy;
  }
  throw std::runtime_error(
      "Surface-cell fallback must be Fail, ReturnQuadDominant, or TryLegacy.");
}

struct SurfaceCellOptions {
  bool enabled = false;
  bool strictValidation = true;
  bool requireMatching = true;
  bool requireSingularities = true;
  bool preserveDebugArtifacts = false;
  bool useSkeletonHints = false;
  SurfaceCellFallbackPolicy fallbackPolicy = SurfaceCellFallbackPolicy::Fail;
  int injectFailureAfterStage = -1;
  double geometricTolerance = 1.0e-9;
  geometry::AdaptiveFeatureMapOptions featureMap;
  geometry::AdaptiveTargetSizeOptions targetSize;
  geometry::LocalThicknessOptions thickness;
};

/**
 * @brief User-tunable parameters for the high-level remeshing pipeline.
 */
struct RemeshOptions {
  /// Target edge-length ratio passed to integration/meshing.
  double lengthRatio = 0.02;

  /// Whether integration should enforce integral seamlessness.
  bool integralSeamless = true;

  /// Whether seam values should be rounded during integration.
  bool roundSeams = false;

  /// Enables shared adaptive feature-map behavior for feature-aware consumers.
  bool featureAlign = false;

  /// Emits per-stage timing logs when true.
  bool verbose = false;

  /// Normalizes supplied direction vectors after tangent projection.
  bool normalizeDirections = true;

  /// Enables the experimental TriFlow-style generated-DCEL simplification pass.
  bool useTriFlowDcelSimplification = false;

  /// Enables the Phase 04 function-skeleton edit plan for safe mesher cleanup.
  bool useFunctionSkeletonCleanup = true;

  /// Enables Phase 05 local patch prevalidation before low-valence mutation.
  bool useLocalPatchPrevalidation = true;

  /// Enables Phase 06 local patch quadrangulation fallback. Disabled by
  /// default until non-trigger overhead and reinsertion behavior are stable.
  bool useLocalPatchQuadrangulationFallback = false;

  /// Enables Phase 07 bounded input triangle-mesh preconditioning.
  bool preconditionInputMesh = false;

  /// Target/preferred face-count ratio for input preconditioning.
  double preconditionTargetFaceRatio = 1.0;

  /// Maximum allowed face-count ratio for input preconditioning.
  double preconditionMaxFaceRatio = 1.05;

  /// Minimum allowed face-count ratio for input preconditioning.
  double preconditionMinFaceRatio = 0.95;

  /// Dihedral angle threshold for protected feature edges.
  double preconditionSharpAngleDegrees = 45.0;

  /// Shared adaptive feature-map options for Phase 11 feature consumers.
  geometry::AdaptiveFeatureMapOptions featureMap;

  /// Enables Phase 08 component-level parallel remeshing. Disabled by default.
  bool parallelizeComponents = false;

  /// Maximum component worker tasks. 0 selects hardware concurrency.
  int maxComponentThreads = 0;

  /// Internal absolute target length override used for component remeshing.
  double absoluteTargetLength = -1.0;

  /// Selects the remeshing backend. SurfaceCells is explicit experimental.
  RemeshBackend backend = RemeshBackend::LegacyInteger;

  /// Options for the default-off surface-cell backend scaffold.
  SurfaceCellOptions surfaceCells;

  /// Integration KKT solve strategy. DirectOnly remains the default reference.
  IntegrationSolveStrategy integrationSolveStrategy =
      IntegrationSolveStrategy::DirectOnly;

  /// Controls for the adaptive integration solve strategy.
  AdaptiveIntegrationOptions adaptiveIntegration;

  /// Controls mixed-integer rounding batch selection.
  IntegerBatchOptions integerBatching;

  /// Controls diagnostic/experimental integer transition basis reduction.
  IntegerTransitionBasisOptions integerTransitionBasis;

  /// Enables Phase 09 targeted parametrization stiffening. Disabled by default
  /// until benchmark gates justify making it default-on.
  bool useTargetedParametrizationStiffening = false;

  /// Controls the default-off targeted parametrization stiffening pass.
  TargetedStiffeningOptions targetedStiffening;

  /// Stops after field integration and returns integration diagnostics only.
  bool stopAfterIntegration = false;

  /// Skips QR constraint rank reduction for explicit benchmark probes.
  bool skipConstraintRankReduction = false;

  /// Optional progress callback invoked by remeshing stages.
  ProgressCallback progress;

  /// Optional benchmark hook invoked after setup_mesher prepares MesherData.
  std::function<void(const MesherData &)> mesherDataCallback;
};

/**
 * @brief Geometry and diagnostic outputs produced by the remeshing pipeline.
 */
struct RemeshResult {
  /// True when the final mesher emitted a valid output mesh.
  bool success = false;

  /// Generated output vertex positions.
  Eigen::MatrixXd vertices;

  /// Degree/valence metadata for generated vertices.
  Eigen::VectorXi degrees;

  /// Generated output faces.
  Eigen::MatrixXi faces;

  /// Vertices of the cut source mesh used for integration.
  Eigen::MatrixXd cutVertices;

  /// Faces of the cut source mesh used for integration.
  Eigen::MatrixXi cutFaces;

  /// Integrated N-function values on the cut mesh.
  Eigen::MatrixXd cutFunctions;

  /// Integrated N-function values at cut-mesh corners.
  Eigen::MatrixXd cutCornerFunctions;

  /// Source-surface provenance for generated output vertices.
  std::vector<directional::geometry::SurfacePoint> outputVertexProvenance;

  /// Ordered #F-by-12 cross field consumed by integration.
  Eigen::MatrixXd rawCrossField;

  /// Principal rotational matching across source-mesh edges.
  Eigen::VectorXi crossFieldMatching;

  /// Parallel-transport deviation across source-mesh edges.
  Eigen::VectorXd crossFieldEffort;

  /// Source-mesh local cycles containing cross-field singularities.
  Eigen::VectorXi crossFieldSingularCycles;

  /// Integer singularity numerators; actual indices are divided by four.
  Eigen::VectorXi crossFieldSingularIndices;

  /// Machine-readable timing and count diagnostics for this pipeline run.
  directional::RemeshDiagnostics diagnostics;
};

inline void copy_adaptive_feature_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::BoundedMeshPreconditionerResult &preconditioned) {
  diagnostics.adaptiveFeatureMapSeconds =
      preconditioned.adaptiveFeatureMapSeconds;
  diagnostics.adaptiveFeatureHardEdgeCount =
      preconditioned.adaptiveFeatureHardEdgeCount;
  diagnostics.adaptiveFeatureSoftEdgeCount =
      preconditioned.adaptiveFeatureSoftEdgeCount;
  diagnostics.adaptiveFeatureBoundaryEdgeCount =
      preconditioned.adaptiveFeatureBoundaryEdgeCount;
  diagnostics.adaptiveFeatureNonManifoldEdgeCount =
      preconditioned.adaptiveFeatureNonManifoldEdgeCount;
  diagnostics.adaptiveFeatureCurveCount =
      preconditioned.adaptiveFeatureCurveCount;
  diagnostics.adaptiveFeatureClosedCurveCount =
      preconditioned.adaptiveFeatureClosedCurveCount;
  diagnostics.adaptiveFeatureMaxDensity =
      preconditioned.adaptiveFeatureMaxDensity;
}

inline void copy_adaptive_feature_map_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::AdaptiveFeatureMap &featureMap) {
  diagnostics.adaptiveFeatureHardEdgeCount = 0;
  diagnostics.adaptiveFeatureSoftEdgeCount = 0;
  diagnostics.adaptiveFeatureBoundaryEdgeCount = 0;
  diagnostics.adaptiveFeatureNonManifoldEdgeCount = 0;
  for (const geometry::AdaptiveFeatureEdge &edge : featureMap.edges) {
    switch (edge.edgeClass) {
    case geometry::AdaptiveFeatureClass::Hard:
      ++diagnostics.adaptiveFeatureHardEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::Soft:
      ++diagnostics.adaptiveFeatureSoftEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::Boundary:
      ++diagnostics.adaptiveFeatureBoundaryEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::NonManifold:
      ++diagnostics.adaptiveFeatureNonManifoldEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::Smooth:
      break;
    }
  }
  diagnostics.adaptiveFeatureCurveCount = featureMap.curves.size();
  diagnostics.adaptiveFeatureClosedCurveCount = 0;
  for (const geometry::AdaptiveFeatureCurve &curve : featureMap.curves) {
    if (curve.closed) {
      ++diagnostics.adaptiveFeatureClosedCurveCount;
    }
  }
  diagnostics.adaptiveFeatureMaxDensity =
      featureMap.vertexDensity.size() == 0 ? 0.0
                                           : featureMap.vertexDensity.maxCoeff();
}

inline void copy_adaptive_target_size_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::AdaptiveTargetSizeResult &targetSize) {
  diagnostics.adaptiveTargetSizeResolvedSurfaceError =
      targetSize.resolvedSurfaceError;
  diagnostics.adaptiveTargetSizeFiniteVertexCount = 0;
  diagnostics.adaptiveTargetSizeNonFiniteVertexCount = 0;
  diagnostics.adaptiveTargetSizeMin = 0.0;
  diagnostics.adaptiveTargetSizeMax = 0.0;
  bool initialized = false;
  for (int vertex = 0; vertex < targetSize.targetSize.size(); ++vertex) {
    const double value = targetSize.targetSize[vertex];
    if (std::isfinite(value)) {
      ++diagnostics.adaptiveTargetSizeFiniteVertexCount;
      if (!initialized) {
        diagnostics.adaptiveTargetSizeMin = value;
        diagnostics.adaptiveTargetSizeMax = value;
        initialized = true;
      } else {
        diagnostics.adaptiveTargetSizeMin =
            std::min(diagnostics.adaptiveTargetSizeMin, value);
        diagnostics.adaptiveTargetSizeMax =
            std::max(diagnostics.adaptiveTargetSizeMax, value);
      }
    } else {
      ++diagnostics.adaptiveTargetSizeNonFiniteVertexCount;
    }
  }
}

/**
 * @brief Compatibility wrapper for tangent projection.
 * @see directional::fields::project_tangent
 */
inline Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &vector,
                                          const Eigen::RowVector3d &normal,
                                          const bool normalize) {
  return fields::project_tangent(vector, normal, normalize);
}

/**
 * @brief Compatibility wrapper for constructing a raw 4-RoSy field.
 * @see directional::fields::make_raw_cross_field
 */
inline Eigen::MatrixXd
make_raw_cross_field(const TriMesh &mesh,
                     const Eigen::MatrixXd &primaryDirections,
                     const Eigen::MatrixXd &secondaryDirections,
                     const bool normalizeDirections) {
  return fields::make_raw_cross_field(mesh, primaryDirections,
                                      secondaryDirections,
                                      normalizeDirections);
}

/**
 * @brief Compatibility wrapper for constructing the second cross axis.
 * @see directional::fields::orthogonal_complement
 */
inline Eigen::MatrixXd
orthogonal_complement(const TriMesh &mesh,
                      const Eigen::MatrixXd &primaryDirections,
                      const bool normalizeDirections) {
  return fields::orthogonal_complement(mesh, primaryDirections,
                                       normalizeDirections);
}

inline void record_face_degree_histogram(RemeshResult &result) {
  result.diagnostics.faceDegreeHistogram.clear();
  for (Eigen::Index face = 0; face < result.degrees.size(); ++face) {
    const int degree = result.degrees(face);
    if (degree < 0) {
      continue;
    }
    const std::size_t index = static_cast<std::size_t>(degree);
    if (result.diagnostics.faceDegreeHistogram.size() <= index) {
      result.diagnostics.faceDegreeHistogram.resize(index + 1U, 0U);
    }
    ++result.diagnostics.faceDegreeHistogram[index];
  }
}

inline Eigen::MatrixXi build_quads_from_paired_source_triangles(const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &faces) {
  if (sourceVertices.cols() != 3 || faces.cols() != 3) {
    return Eigen::MatrixXi(0, 4);
  }
  std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      edgeFaces[{std::min(a, b), std::max(a, b)}].push_back(face);
    }
  }

  std::vector<std::array<int, 4>> quads;
  std::vector<unsigned char> used(static_cast<std::size_t>(faces.rows()), 0U);
  for (const auto &entry : edgeFaces) {
    const std::vector<int> &incident = entry.second;
    if (incident.size() != 2U) {
      continue;
    }
    const int firstFace = incident[0];
    const int secondFace = incident[1];
    if (used[static_cast<std::size_t>(firstFace)] != 0U ||
        used[static_cast<std::size_t>(secondFace)] != 0U) {
      continue;
    }
    std::set<int> quadVertices;
    for (int c = 0; c < 3; ++c) {
      quadVertices.insert(faces(firstFace, c));
      quadVertices.insert(faces(secondFace, c));
    }
    if (quadVertices.size() != 4U) {
      continue;
    }
    const auto edge_length = [&](const int a, const int b) -> double {
      if (a < 0 || b < 0 || a >= sourceVertices.rows() || b >= sourceVertices.rows()) {
        return -1.0;
      }
      return (sourceVertices.row(a) - sourceVertices.row(b)).norm();
    };
    const std::pair<int, int> sharedEdge = entry.first;
    const double sharedLength = edge_length(sharedEdge.first, sharedEdge.second);
    if (sharedLength <= 0.0) {
      continue;
    }
    double maxBoundaryLength = 0.0;
    bool boundaryLengthsValid = true;
    for (const int face : {firstFace, secondFace}) {
      for (int c = 0; c < 3; ++c) {
        const int a = faces(face, c);
        const int b = faces(face, (c + 1) % 3);
        const std::pair<int, int> key{std::min(a, b), std::max(a, b)};
        if (key == sharedEdge) {
          continue;
        }
        const double length = edge_length(a, b);
        boundaryLengthsValid = boundaryLengthsValid && length > 0.0;
        maxBoundaryLength = std::max(maxBoundaryLength, length);
      }
    }
    if (!boundaryLengthsValid || sharedLength <= maxBoundaryLength * 1.01) {
      continue;
    }
    std::map<int, std::vector<int>> boundaryAdjacency;
    const auto add_boundary_edge = [&](const int a, const int b) {
      const std::pair<int, int> key{std::min(a, b), std::max(a, b)};
      if (key != sharedEdge) {
        boundaryAdjacency[a].push_back(b);
        boundaryAdjacency[b].push_back(a);
      }
    };
    for (const int face : {firstFace, secondFace}) {
      for (int c = 0; c < 3; ++c) {
        add_boundary_edge(faces(face, c), faces(face, (c + 1) % 3));
      }
    }
    if (boundaryAdjacency.size() != 4U) {
      continue;
    }
    bool allDegreeTwo = true;
    for (const auto &node : boundaryAdjacency) {
      allDegreeTwo = allDegreeTwo && node.second.size() == 2U;
    }
    if (!allDegreeTwo) {
      continue;
    }
    std::array<int, 4> quad{};
    quad[0] = boundaryAdjacency.begin()->first;
    quad[1] = boundaryAdjacency[quad[0]][0];
    for (int i = 2; i < 4; ++i) {
      const std::vector<int> &neighbors = boundaryAdjacency[quad[i - 1]];
      quad[i] = neighbors[0] == quad[i - 2] ? neighbors[1] : neighbors[0];
    }
    if (boundaryAdjacency[quad[3]][0] != quad[0] &&
        boundaryAdjacency[quad[3]][1] != quad[0]) {
      continue;
    }
    quads.push_back(quad);
    used[static_cast<std::size_t>(firstFace)] = 1U;
    used[static_cast<std::size_t>(secondFace)] = 1U;
  }

  Eigen::MatrixXi result(static_cast<int>(quads.size()), 4);
  for (int row = 0; row < static_cast<int>(quads.size()); ++row) {
    for (int col = 0; col < 4; ++col) {
      result(row, col) = quads[static_cast<std::size_t>(row)][col];
    }
  }
  return result;
}
inline void orient_quads_to_source_normals(const Eigen::MatrixXd &vertices,
                                           const Eigen::MatrixXi &sourceFaces,
                                           Eigen::MatrixXi &quads) {
  if (vertices.cols() != 3 || sourceFaces.cols() != 3 || quads.cols() != 4) {
    return;
  }
  const geometry::SurfaceProjectionBvh projection(vertices, sourceFaces);
  for (int row = 0; row < quads.rows(); ++row) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    bool valid = true;
    for (int col = 0; col < 4; ++col) {
      const int vertex = quads(row, col);
      if (vertex < 0 || vertex >= vertices.rows()) {
        valid = false;
        break;
      }
      centroid += 0.25 * vertices.row(vertex);
    }
    if (!valid) {
      continue;
    }
    const geometry::SurfacePoint source =
        projection.project(centroid.transpose());
    if (!source.valid() || source.face < 0 || source.face >= sourceFaces.rows()) {
      continue;
    }
    const Eigen::RowVector3d a = vertices.row(quads(row, 0));
    const Eigen::RowVector3d b = vertices.row(quads(row, 1));
    const Eigen::RowVector3d c = vertices.row(quads(row, 2));
    Eigen::RowVector3d quadNormal = (b - a).cross(c - a);
    const Eigen::RowVector3d sa = vertices.row(sourceFaces(source.face, 0));
    const Eigen::RowVector3d sb = vertices.row(sourceFaces(source.face, 1));
    const Eigen::RowVector3d sc = vertices.row(sourceFaces(source.face, 2));
    Eigen::RowVector3d sourceNormal = (sb - sa).cross(sc - sa);
    if (quadNormal.norm() > 0.0 && sourceNormal.norm() > 0.0 &&
        quadNormal.dot(sourceNormal) < 0.0) {
      std::swap(quads(row, 1), quads(row, 3));
    }
  }
}
inline std::vector<geometry::SurfaceArrangementArc>
surface_arrangement_arcs_from_flow_rep(
    const std::vector<geometry::FlowRepArc> &arcs,
    const geometry::FlowRepSparseNetwork &sparseNetwork) {
  std::set<int> retained(sparseNetwork.retainedArcIds.begin(),
                         sparseNetwork.retainedArcIds.end());
  if (retained.empty() && sparseNetwork.removedArcIds.empty()) {
    for (const geometry::FlowRepArc &arc : arcs) {
      retained.insert(arc.id);
    }
  }
  std::vector<geometry::SurfaceArrangementArc> arrangementArcs;
  arrangementArcs.reserve(retained.size());
  for (const geometry::FlowRepArc &arc : arcs) {
    if (retained.count(arc.id) == 0 || arc.sourceFace < 0) {
      continue;
    }
    geometry::SurfaceArrangementArc arrangementArc;
    arrangementArc.id = static_cast<int>(arrangementArcs.size());
    arrangementArc.sourceFace = arc.sourceFace;
    arrangementArc.startBarycentric = arc.startBarycentric;
    arrangementArc.endBarycentric = arc.endBarycentric;
    arrangementArc.family = arc.family;
    arrangementArc.strand = arc.strandProvenance;
    arrangementArc.featureClass = arc.featureClass;
    arrangementArc.hardFeature = arc.hardFeatureRail || arc.mandatoryRail;
    arrangementArc.provenance = arc.id;
    arrangementArcs.push_back(arrangementArc);
  }
  return arrangementArcs;
}
/**
 * @brief Runs the full remeshing pipeline on an initialized TriMesh and raw cross field.
 * @param meshWhole Initialized source mesh.
 * @param rawCrossField #F-by-12 raw 4-RoSy field.
 * @param options Pipeline options.
 * @return Remeshing result with generated mesh and cut-mesh diagnostics.
 */
inline RemeshResult
remesh_from_raw_cross_field_impl(const TriMesh &meshWhole,
                                 const Eigen::MatrixXd &rawCrossField,
                                 const RemeshOptions &options = {}) {
  using Clock = std::chrono::high_resolution_clock;
  const auto pipelineStart = Clock::now();
  auto phaseStart = pipelineStart;
  if (options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled) {
    RemeshResult result;
    result.diagnostics.remeshBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.requestedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.executedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    std::vector<std::string> completedSurfaceCellStages;
    auto preserve_completed_debug_artifacts = [&]() {
      result.diagnostics.surfaceCellDebugArtifactsPreserved =
          options.surfaceCells.preserveDebugArtifacts;
      if (options.surfaceCells.preserveDebugArtifacts) {
        result.diagnostics.surfaceCellDebugArtifacts =
            completedSurfaceCellStages;
      }
    };
    auto fail_surface_cells = [&](const SurfaceCellFailureCode code,
                                  const std::string &stage) {
      const std::string failureCode = surface_cell_failure_code_name(code);
      result.success = false;
      result.diagnostics.terminalFailureCode = failureCode;
      result.diagnostics.terminalFailureStage = stage;
      result.diagnostics.originalSurfaceCellFailureCode = failureCode;
      result.diagnostics.originalSurfaceCellFailureStage = stage;
      result.diagnostics.surfaceCellValidationFailures += 1U;
      preserve_completed_debug_artifacts();
      result.diagnostics.overallPipelineSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              Clock::now() - pipelineStart)
              .count() /
          1.0e6;

      if (options.surfaceCells.fallbackPolicy ==
          SurfaceCellFallbackPolicy::ReturnQuadDominant) {
        result.success = true;
        result.vertices = meshWhole.V;
        result.faces = meshWhole.F;
        result.degrees =
            Eigen::VectorXi::Constant(meshWhole.F.rows(), meshWhole.F.cols());
        result.diagnostics.surfaceCellFallbackAttempted = true;
        result.diagnostics.surfaceCellFallbackCause = failureCode;
        result.diagnostics.surfaceCellReturnedInputMeshFallback = true;
        result.diagnostics.surfaceCellRemeshOccurred = false;
        result.diagnostics.executedBackend = "InputMesh";
        result.diagnostics.remeshBackend = result.diagnostics.executedBackend;
        record_face_degree_histogram(result);
      } else if (options.surfaceCells.fallbackPolicy ==
                 SurfaceCellFallbackPolicy::TryLegacy) {
        result.diagnostics.surfaceCellFallbackAttempted = true;
        result.diagnostics.surfaceCellFallbackCause = failureCode;
        if (rawCrossField.rows() == meshWhole.F.rows() &&
            rawCrossField.cols() == 12) {
          RemeshOptions legacyOptions = options;
          legacyOptions.backend = RemeshBackend::LegacyInteger;
          legacyOptions.surfaceCells.enabled = false;
          legacyOptions.parallelizeComponents = false;
          RemeshResult legacyResult;
          try {
            legacyResult = remesh_from_raw_cross_field_impl(
                meshWhole, rawCrossField, legacyOptions);
          } catch (...) {
            return result;
          }
          legacyResult.diagnostics.requestedBackend =
              remesh_backend_name(RemeshBackend::SurfaceCells);
          legacyResult.diagnostics.executedBackend =
              remesh_backend_name(RemeshBackend::LegacyInteger);
          legacyResult.diagnostics.remeshBackend =
              legacyResult.diagnostics.executedBackend;
          legacyResult.diagnostics.surfaceCellFallbackPolicy =
              surface_cell_fallback_policy_name(
                  options.surfaceCells.fallbackPolicy);
          legacyResult.diagnostics.surfaceCellFallbackAttempted = true;
          legacyResult.diagnostics.surfaceCellUsedLegacyFallback = true;
          legacyResult.diagnostics.surfaceCellFallbackCause = failureCode;
          legacyResult.diagnostics.originalSurfaceCellFailureCode = failureCode;
          legacyResult.diagnostics.originalSurfaceCellFailureStage = stage;
          legacyResult.diagnostics.surfaceCellDebugArtifactsPreserved =
              result.diagnostics.surfaceCellDebugArtifactsPreserved;
          legacyResult.diagnostics.surfaceCellDebugArtifacts =
              result.diagnostics.surfaceCellDebugArtifacts;
          if (!legacyResult.success) {
            legacyResult.diagnostics.terminalFailureCode = failureCode;
            legacyResult.diagnostics.terminalFailureStage = stage;
          }
          legacyResult.diagnostics.surfaceCellRemeshOccurred =
              legacyResult.success && legacyResult.faces.rows() > 0;
          result = legacyResult;
        }
      }
      return result;
    };

    if (rawCrossField.rows() != meshWhole.F.rows() ||
        rawCrossField.cols() != 12) {
      return fail_surface_cells(SurfaceCellFailureCode::InvalidFieldDimensions,
                                "input-validation");
    }

    const auto featureStart = Clock::now();
    const geometry::AdaptiveFeatureMap featureMap =
        geometry::AdaptiveFeatureMapBuilder::build(
            meshWhole.V, meshWhole.F,
            options.featureAlign ? options.featureMap
                                 : options.surfaceCells.featureMap);
    result.diagnostics.surfaceCellFeatureSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - featureStart)
            .count() /
        1.0e6;
    result.diagnostics.adaptiveFeatureMapSeconds =
        result.diagnostics.surfaceCellFeatureSeconds;
    result.diagnostics.surfaceCellFeatureCount = featureMap.edges.size();
    copy_adaptive_feature_map_diagnostics(result.diagnostics, featureMap);
    completedSurfaceCellStages.push_back("feature");
    if (options.surfaceCells.injectFailureAfterStage == 0) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "feature");
    }
    const auto targetSizeStart = Clock::now();
    const geometry::AdaptiveTargetSizeResult targetSize =
        geometry::compute_adaptive_target_size(
            meshWhole.V, meshWhole.F, featureMap,
            options.surfaceCells.targetSize, options.surfaceCells.thickness);
    result.diagnostics.adaptiveTargetSizeSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - targetSizeStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellMetricSeconds =
        result.diagnostics.adaptiveTargetSizeSeconds;
    result.diagnostics.surfaceCellMetricSampleCount =
        static_cast<std::size_t>(targetSize.targetSize.size());
    copy_adaptive_target_size_diagnostics(result.diagnostics, targetSize);
    completedSurfaceCellStages.push_back("metric");

    if (options.surfaceCells.injectFailureAfterStage == 1) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "metric");
    }

    const auto reliefStart = Clock::now();
    geometry::ReliefInput reliefInput;
    reliefInput.salience = targetSize.normalizedSalience;
    reliefInput.curvature = targetSize.curvature;
    reliefInput.density = targetSize.normalizedFeatureDensity;
    reliefInput.thickness = targetSize.thickness;
    reliefInput.patchEnergy = Eigen::VectorXd::Zero(meshWhole.V.rows());
    const Eigen::VectorXd reliefValues =
        geometry::compute_salience_relief(reliefInput, geometry::ReliefOptions{});
    const geometry::ReliefTopologyResult reliefTopology =
        geometry::analyze_relief_topology(meshWhole.V, meshWhole.F, reliefValues);
    result.diagnostics.surfaceCellReliefSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - reliefStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellReliefPatchCount =
        reliefTopology.branches.size();
    result.diagnostics.surfaceCellReliefCountAvailable = true;
    completedSurfaceCellStages.push_back("relief");
    if (options.surfaceCells.injectFailureAfterStage == 2) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "relief");
    }

    const auto tracingStart = Clock::now();
    Eigen::MatrixXd faceAxisX = rawCrossField.block(0, 0, rawCrossField.rows(), 3);
    Eigen::MatrixXd faceAxisY = rawCrossField.block(0, 3, rawCrossField.rows(), 3);
    geometry::SurfaceCellTracingOptions tracingOptions;
    if (targetSize.targetSize.size() > 0) {
      tracingOptions.defaultTargetSize = targetSize.targetSize.mean();
    }
    for (const geometry::ReliefCriticalPoint &point :
         reliefTopology.criticalPoints) {
      if (point.retained && point.vertex >= 0) {
        tracingOptions.reliefCriticalVertices.push_back(point.vertex);
      }
    }
    const geometry::SurfaceCellNetwork traceNetwork =
        geometry::build_surface_cell_network(meshWhole.V, meshWhole.F, faceAxisX,
                                             faceAxisY, targetSize.targetSize,
                                             tracingOptions);
    std::size_t traceSegmentCount = 0U;
    for (const geometry::SurfaceTraceResult &trace : traceNetwork.traces) {
      traceSegmentCount += trace.segments.size();
    }
    for (const geometry::SurfaceCellProposal &proposal :
         traceNetwork.proposals) {
      traceSegmentCount += proposal.sides.size();
    }
    result.diagnostics.surfaceCellTracingSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - tracingStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellTraceSegmentCount = traceSegmentCount;
    result.diagnostics.surfaceCellTraceCountAvailable = true;
    completedSurfaceCellStages.push_back("tracing");
    if (options.surfaceCells.injectFailureAfterStage == 3) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "tracing");
    }

    const auto strandsStart = Clock::now();
    const std::vector<geometry::FlowRepArc> flowRepArcs =
        geometry::build_flow_rep_arcs_from_network(meshWhole.V, meshWhole.F,
                                                   traceNetwork);
    const geometry::FlowRepSparseNetwork sparseFlowRep =
        geometry::select_sparse_flow_rep_network(flowRepArcs);
    const std::vector<geometry::SurfaceArrangementArc> arrangementArcs =
        surface_arrangement_arcs_from_flow_rep(flowRepArcs, sparseFlowRep);
    result.diagnostics.surfaceCellArrangementCellCount = arrangementArcs.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    completedSurfaceCellStages.push_back("strands");
    if (options.surfaceCells.injectFailureAfterStage == 4) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "strands");
    }

    const auto arrangementStart = Clock::now();
    const geometry::SurfaceCellComplex arrangementComplex =
        geometry::build_surface_cell_complex(meshWhole.V, meshWhole.F,
                                             arrangementArcs);
    result.diagnostics.surfaceCellArrangementSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - arrangementStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount =
        arrangementComplex.cells.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    completedSurfaceCellStages.push_back("arrangement");
    if (options.surfaceCells.injectFailureAfterStage == 5) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "arrangement");
    }

    const auto simplificationStart = Clock::now();
    const geometry::SurfaceSimplificationResult simplified =
        geometry::simplify_surface_cell_complex(arrangementComplex, {});
    result.diagnostics.surfaceCellSimplificationSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - simplificationStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellSimplifiedCellCount =
        simplified.hasComplexOutput ? simplified.complex.cells.size() : 0U;
    result.diagnostics.surfaceCellSimplifiedCountAvailable = true;
    completedSurfaceCellStages.push_back("simplification");
    if (options.surfaceCells.injectFailureAfterStage == 6) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "simplification");
    }

    const auto completionStart = Clock::now();
    std::size_t completedQuadCount = 0U;
    Eigen::MatrixXd completedVertices;
    Eigen::MatrixXi completedQuads;
    std::vector<geometry::SurfacePoint> completedProvenance;
    const geometry::SurfaceCellComplex &completionComplex =
        simplified.hasComplexOutput ? simplified.complex : arrangementComplex;
    for (const geometry::SurfaceArrangementCell &cell : completionComplex.cells) {
      if (!cell.quadReady || cell.halfedges.empty() ||
          cell.sideEdgeCounts.size() != 4U) {
        continue;
      }
      geometry::PureQuadPatch patch;
      patch.sideEdgeCounts = cell.sideEdgeCounts;
      patch.turns.assign(patch.sideEdgeCounts.size(), 0);
      patch.diskTopology = cell.disk;
      patch.hardFeatureCrossing =
          completionComplex.diagnostics.hardBarrierCrossings > 0;
      patch.simple = true;
      for (const int halfedgeId : cell.halfedges) {
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(completionComplex.halfedges.size())) {
          continue;
        }
        const geometry::SurfaceArrangementHalfedge &halfedge =
            completionComplex.halfedges[static_cast<std::size_t>(halfedgeId)];
        if (halfedge.from < 0 ||
            halfedge.from >= static_cast<int>(completionComplex.nodes.size())) {
          continue;
        }
        const geometry::SurfaceArrangementNode &node =
            completionComplex.nodes[static_cast<std::size_t>(halfedge.from)];
        patch.boundaryVertices.push_back(node.id);
        geometry::SurfacePoint point;
        point.face = node.sourceFace;
        point.barycentric = node.barycentric.transpose();
        if (point.face >= 0 && point.face < meshWhole.F.rows()) {
          point.position =
              point.barycentric(0) * meshWhole.V.row(meshWhole.F(point.face, 0)).transpose() +
              point.barycentric(1) * meshWhole.V.row(meshWhole.F(point.face, 1)).transpose() +
              point.barycentric(2) * meshWhole.V.row(meshWhole.F(point.face, 2)).transpose();
          point.squaredDistance = 0.0;
        }
        patch.boundaryProvenance.push_back(point);
      }
      const int expectedBoundary = std::accumulate(
          patch.sideEdgeCounts.begin(), patch.sideEdgeCounts.end(), 0);
      if (static_cast<int>(patch.boundaryVertices.size()) != expectedBoundary) {
        continue;
      }
      const geometry::PureQuadCompletionResult completion =
          geometry::complete_pure_quad_patch(patch);
      if (!completion.success || completion.mesh.quads.empty()) {
        continue;
      }
      const int vertexOffset = static_cast<int>(completedVertices.rows());
      const int oldVertexRows = static_cast<int>(completedVertices.rows());
      completedVertices.conservativeResize(
          oldVertexRows + completion.mesh.vertexPositions.rows(), 3);
      completedVertices.block(oldVertexRows, 0,
                              completion.mesh.vertexPositions.rows(), 3) =
          completion.mesh.vertexPositions;
      completedProvenance.insert(completedProvenance.end(),
                                 completion.mesh.vertexProvenance.begin(),
                                 completion.mesh.vertexProvenance.end());
      const int oldQuadRows = static_cast<int>(completedQuads.rows());
      completedQuads.conservativeResize(
          oldQuadRows + static_cast<int>(completion.mesh.quads.size()), 4);
      std::map<int, int> vertexToRow;
      for (int row = 0; row < static_cast<int>(completion.mesh.vertices.size());
           ++row) {
        vertexToRow[completion.mesh.vertices[static_cast<std::size_t>(row)]] =
            vertexOffset + row;
      }
      for (int q = 0; q < static_cast<int>(completion.mesh.quads.size()); ++q) {
        for (int c = 0; c < 4; ++c) {
          completedQuads(oldQuadRows + q, c) =
              vertexToRow[completion.mesh.quads[static_cast<std::size_t>(q)]
                                    [static_cast<std::size_t>(c)]];
        }
      }
      completedQuadCount += completion.mesh.quads.size();
    }
    if (completedQuadCount == 0U) {
      completedQuads = build_quads_from_paired_source_triangles(meshWhole.V, meshWhole.F);
      if (completedQuads.rows() > 0) {
        completedVertices = meshWhole.V;
        completedProvenance.clear();
        completedProvenance.reserve(static_cast<std::size_t>(meshWhole.V.rows()));
        const geometry::SurfaceProjectionBvh sourceProjection(meshWhole.V,
                                                              meshWhole.F);
        for (int vertex = 0; vertex < meshWhole.V.rows(); ++vertex) {
          completedProvenance.push_back(sourceProjection.project(
              meshWhole.V.row(vertex).transpose()));
        }
        completedQuadCount = static_cast<std::size_t>(completedQuads.rows());
      }
    }
    result.diagnostics.surfaceCellCompletionSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - completionStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellCompletedQuadCount = completedQuadCount;
    result.diagnostics.surfaceCellCompletedQuadCountAvailable = true;
    completedSurfaceCellStages.push_back("completion");
    if (options.surfaceCells.injectFailureAfterStage == 7) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "completion");
    }

    const auto optimizationStart = Clock::now();
    if (completedVertices.rows() > 0 && completedQuads.rows() > 0) {
      orient_quads_to_source_normals(completedVertices, meshWhole.F,
                                     completedQuads);
      geometry::SurfaceOptimizationConstraints constraints;
      constraints.sourceVertices = meshWhole.V;
      constraints.sourceFaces = meshWhole.F;
      constraints.sourcePositions = meshWhole.V;
      constraints.sourceNormals = meshWhole.faceNormals;
      constraints.sourceFieldX = faceAxisX;
      constraints.sourceFieldY = faceAxisY;
      constraints.localTargetSize = targetSize.targetSize;
      constraints.vertexProvenance = completedProvenance;
      geometry::SurfaceOptimizationOptions optimizationOptions;
      optimizationOptions.targetSize = tracingOptions.defaultTargetSize;
      const geometry::SurfaceOptimizationResult optimization =
          geometry::optimize_projected_surface_mesh(completedVertices,
                                                    completedQuads,
                                                    constraints,
                                                    optimizationOptions);
      const geometry::SurfaceFinalValidationReport validation =
          geometry::validate_final_surface_mesh(optimization.vertices,
                                                optimization.quads,
                                                constraints, optimization,
                                                optimizationOptions, 0.0,
                                                1.0);
      result.diagnostics.surfaceCellOptimizationIterationCount =
          optimization.iterations.size();
      result.diagnostics.surfaceCellOptimizationSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              Clock::now() - optimizationStart)
              .count() /
          1.0e6;
      result.diagnostics.surfaceCellOptimizationIterationCountAvailable = true;
      completedSurfaceCellStages.push_back("optimization");
      if (options.surfaceCells.injectFailureAfterStage == 8) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "optimization");
      }
      if (validation.accepted) {
        result.success = true;
        result.vertices = optimization.vertices;
        result.faces = optimization.quads;
        result.degrees = Eigen::VectorXi::Constant(optimization.quads.rows(), 4);
        result.outputVertexProvenance = optimization.vertexProvenance;
        result.diagnostics.surfaceCellRemeshOccurred = true;
        result.diagnostics.terminalFailureCode = "None";
        result.diagnostics.terminalFailureStage.clear();
        result.diagnostics.surfaceCellValidationSeconds =
            std::chrono::duration_cast<std::chrono::microseconds>(
                Clock::now() - optimizationStart)
                .count() /
            1.0e6;
        record_face_degree_histogram(result);
        return result;
      }
    } else {
      result.diagnostics.surfaceCellOptimizationIterationCount = 0U;
    }
    if (!result.diagnostics.surfaceCellOptimizationIterationCountAvailable) {
      result.diagnostics.surfaceCellOptimizationSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              Clock::now() - optimizationStart)
              .count() /
          1.0e6;
      result.diagnostics.surfaceCellOptimizationIterationCountAvailable = true;
      completedSurfaceCellStages.push_back("optimization");
      if (options.surfaceCells.injectFailureAfterStage == 8) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "optimization");
      }
    }

    return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                              "production-gate");
  }
  const auto log_phase = [&](const char *label) {
    const auto now = Clock::now();
    const auto phaseSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now - phaseStart)
            .count() /
        1e+6;
    const auto totalSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now -
                                                              pipelineStart)
            .count() /
        1e+6;
    if (options.verbose) {
      std::cout
          << "[Directional::pipeline::remesh_from_raw_cross_field_impl()]: "
          << label << " completed in " << phaseSeconds << " s (total "
          << totalSeconds << " s)" << std::endl;
    }
    phaseStart = now;
    return phaseSeconds;
  };
  directional::RemeshDiagnostics diagnostics;
  diagnostics.remeshBackend = remesh_backend_name(RemeshBackend::LegacyInteger);
  diagnostics.requestedBackend =
      remesh_backend_name(RemeshBackend::LegacyInteger);
  diagnostics.executedBackend = remesh_backend_name(RemeshBackend::LegacyInteger);
  diagnostics.surfaceCellFallbackPolicy =
      surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);

  // if (options.featureAlign) {
  //   throw std::runtime_error("featureAlign is not supported by the headless "
  //                            "Directional pipeline yet.");
  // }
  if (rawCrossField.rows() != meshWhole.F.rows() ||
      rawCrossField.cols() != 12) {
    throw std::runtime_error(
        "rawCrossField must have shape (#F, 12) for a 4-RoSy cross field.");
  }

  TriMesh workingMesh = meshWhole;
  Eigen::MatrixXd workingRawCrossField = rawCrossField;
  if (options.preconditionInputMesh) {
    report_progress(options.progress, 3, 100, "Preconditioning input mesh");
    geometry::BoundedMeshPreconditionerOptions preconditionOptions;
    preconditionOptions.enabled = true;
    preconditionOptions.targetFaceRatio = options.preconditionTargetFaceRatio;
    preconditionOptions.maxFaceRatio = options.preconditionMaxFaceRatio;
    preconditionOptions.minFaceRatio = options.preconditionMinFaceRatio;
    preconditionOptions.sharpAngleDegrees =
        options.preconditionSharpAngleDegrees;
    preconditionOptions.featureMap = options.featureMap;
    const geometry::BoundedMeshPreconditionerResult preconditioned =
        geometry::BoundedMeshPreconditioner::precondition(
            meshWhole.V, meshWhole.F, preconditionOptions);
    diagnostics.preconditioningSeconds += log_phase("input preconditioning");
    copy_adaptive_feature_diagnostics(diagnostics, preconditioned);
    diagnostics.preconditioningFlipsAccepted = preconditioned.flipsAccepted;
    diagnostics.preconditioningCollapsesAccepted =
        preconditioned.collapsesAccepted;
    diagnostics.preconditioningSplitsAccepted = preconditioned.splitsAccepted;
    diagnostics.preconditioningInputTriangleCount =
        preconditioned.inputTriangleCount;
    diagnostics.preconditioningOutputTriangleCount =
        preconditioned.outputTriangleCount;
    diagnostics.preconditioningMinAngleBefore =
        preconditioned.before.minTriangleAngleDegrees;
    diagnostics.preconditioningMinAngleAfter =
        preconditioned.after.minTriangleAngleDegrees;
    diagnostics.preconditioningAspectRatioP95Before =
        preconditioned.before.aspectRatioP95;
    diagnostics.preconditioningAspectRatioP95After =
        preconditioned.after.aspectRatioP95;
    diagnostics.preconditioningAspectRatioP99Before =
        preconditioned.before.aspectRatioP99;
    diagnostics.preconditioningAspectRatioP99After =
        preconditioned.after.aspectRatioP99;
    diagnostics.preconditioningEdgeLengthCvBefore =
        preconditioned.before.edgeLengthCoefficientOfVariation;
    diagnostics.preconditioningEdgeLengthCvAfter =
        preconditioned.after.edgeLengthCoefficientOfVariation;
    try {
      workingMesh.set_mesh(preconditioned.vertices, preconditioned.faces);
      workingRawCrossField =
          fields::CrossFieldTransfer::transfer_raw_field_nearest_face(
              meshWhole, rawCrossField, workingMesh,
              options.normalizeDirections);
      diagnostics.fieldSetupSeconds += log_phase("cross-field transfer");
    } catch (const std::exception &) {
      workingMesh = meshWhole;
      workingRawCrossField = rawCrossField;
      diagnostics.preconditioningFlipsAccepted = 0;
      diagnostics.preconditioningCollapsesAccepted = 0;
      diagnostics.preconditioningSplitsAccepted = 0;
      diagnostics.preconditioningOutputTriangleCount =
          static_cast<std::size_t>(meshWhole.F.rows());
      diagnostics.preconditioningMinAngleAfter =
          diagnostics.preconditioningMinAngleBefore;
      diagnostics.preconditioningAspectRatioP95After =
          diagnostics.preconditioningAspectRatioP95Before;
      diagnostics.preconditioningAspectRatioP99After =
          diagnostics.preconditioningAspectRatioP99Before;
      diagnostics.preconditioningEdgeLengthCvAfter =
          diagnostics.preconditioningEdgeLengthCvBefore;
      log_phase("discard invalid preconditioning output");
    }
  } else {
    diagnostics.preconditioningInputTriangleCount =
        static_cast<std::size_t>(meshWhole.F.rows());
    diagnostics.preconditioningOutputTriangleCount =
        static_cast<std::size_t>(meshWhole.F.rows());
  }

  report_progress(options.progress, 5, 100, "Initializing tangent bundle");
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(workingMesh);
  diagnostics.tangentBundleInitializationSeconds +=
      log_phase("PCFaceTangentBundle::init");

  report_progress(options.progress, 10, 100, "Preparing raw cross field");
  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, 4);
  rawField.set_extrinsic_field(workingRawCrossField);
  diagnostics.fieldSetupSeconds +=
      log_phase("CartesianField::init + set_extrinsic_field");
  report_progress(options.progress, 15, 100, "Computing field matching");
  principal_matching(rawField);
  diagnostics.principalMatchingSeconds += log_phase("principal_matching");

  IntegrationData integration(4);
  integration.lengthRatio = options.lengthRatio;
  integration.absoluteTargetLength = options.absoluteTargetLength;
  integration.integralSeamless = options.integralSeamless;
  integration.roundSeams = options.roundSeams;
  integration.verbose = options.verbose;
  integration.solveStrategy = options.integrationSolveStrategy;
  integration.adaptiveOptions = options.adaptiveIntegration;
  integration.integerBatchOptions = options.integerBatching;
  integration.integerTransitionBasisOptions = options.integerTransitionBasis;
  integration.targetedStiffening = options.targetedStiffening;
  integration.targetedStiffening.enabled =
      options.useTargetedParametrizationStiffening &&
      options.targetedStiffening.enabled;
  integration.skipConstraintRankReduction = options.skipConstraintRankReduction;

  report_progress(options.progress, 20, 100, "Setting up integration");
  TriMesh meshCut;
  CartesianField combedField;
  setup_integration(rawField, integration, meshCut, combedField);
  diagnostics.setupIntegrationSeconds += log_phase("setup_integration");

  report_progress(options.progress, 21, 100, "Solving field integration");
  if (!options.verbose && options.progress) {
    integration.progress =
        [callback = options.progress](const std::size_t current,
                                      const std::size_t total,
                                      const std::string_view task) {
          constexpr std::size_t first = 21;
          constexpr std::size_t last = 75;
          const std::size_t safeTotal = std::max<std::size_t>(total, 1);
          const std::size_t safeCurrent =
              std::min(std::max<std::size_t>(current, 1), safeTotal);
          const std::size_t mapped =
              safeTotal == 1
                  ? last
                  : first + (safeCurrent - 1) * (last - first) /
                                (safeTotal - 1);
          report_progress(callback, mapped, 100, task);
        };
  }
  Eigen::MatrixXd cutFunctions;
  Eigen::MatrixXd cutCornerFunctions;
  if (!integrate(combedField, integration, meshCut, cutFunctions,
                 cutCornerFunctions)) {
    throw std::runtime_error(
        "Field integration failed; the mesher cannot continue.");
  }
  diagnostics.integrationTotalSeconds += log_phase("integrate");
  diagnostics.integration = integration.diagnostics;

  if (options.stopAfterIntegration) {
    RemeshResult result;
    result.success = true;
    result.rawCrossField = rawField.extField;
    result.crossFieldMatching = rawField.matching;
    result.crossFieldEffort = rawField.effort;
    result.crossFieldSingularCycles = rawField.singLocalCycles;
    result.crossFieldSingularIndices = rawField.singIndices;
    result.cutVertices = meshCut.V;
    result.cutFaces = meshCut.F;
    result.cutFunctions = cutFunctions;
    result.cutCornerFunctions = cutCornerFunctions;
    diagnostics.overallPipelineSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                              pipelineStart)
            .count() /
        1.0e6;
    result.diagnostics = diagnostics;
    report_progress(options.progress, 100, 100,
                    "Finalizing integration-only result");
    return result;
  }

  report_progress(options.progress, 80, 100, "Preparing mesher");
  MesherData mesherData;
  mesherData.verbose = options.verbose;
  mesherData.simplificationBackend =
      options.useTriFlowDcelSimplification
          ? MesherSimplificationBackend::TriFlowDCEL
          : MesherSimplificationBackend::Directional;
  mesherData.useFunctionSkeletonCleanup = options.useFunctionSkeletonCleanup;
  mesherData.useLocalPatchPrevalidation = options.useLocalPatchPrevalidation;
  mesherData.useLocalPatchQuadrangulationFallback =
      options.useLocalPatchQuadrangulationFallback;
  if (!options.verbose && options.progress) {
    mesherData.progress =
        [callback = options.progress](const std::size_t current,
                                      const std::size_t total,
                                      const std::string_view task) {
          constexpr std::size_t first = 81;
          constexpr std::size_t last = 99;
          const std::size_t safeTotal = std::max<std::size_t>(total, 1);
          const std::size_t safeCurrent =
              std::min(current, safeTotal);
          const std::size_t mapped =
              first + safeCurrent * (last - first) / safeTotal;
          report_progress(callback, mapped, 100, task);
        };
  }
  setup_mesher(meshCut, integration, mesherData);
  diagnostics.setupMesherSeconds += log_phase("setup_mesher");
  if (options.mesherDataCallback) {
    options.mesherDataCallback(mesherData);
  }

  RemeshResult result;
  result.rawCrossField = rawField.extField;
  result.crossFieldMatching = rawField.matching;
  result.crossFieldEffort = rawField.effort;
  result.crossFieldSingularCycles = rawField.singLocalCycles;
  result.crossFieldSingularIndices = rawField.singIndices;
  result.cutVertices = meshCut.V;
  result.cutFaces = meshCut.F;
  result.cutFunctions = cutFunctions;
  result.cutCornerFunctions = cutCornerFunctions;
  report_progress(options.progress, 81, 100, "Generating output mesh");
  result.success = mesher(workingMesh, mesherData, result.vertices,
                          result.degrees, result.faces);
  diagnostics.mesherTotalSeconds += log_phase("mesher");
  diagnostics.mesher = mesherData.diagnostics;
  diagnostics.overallPipelineSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            pipelineStart)
          .count() /
      1.0e6;
  result.diagnostics = diagnostics;
  record_face_degree_histogram(result);
  report_progress(options.progress, 100, 100, "Finalizing remesh result");
  return result;
}

inline double derive_absolute_target_length(const Eigen::MatrixXd &vertices,
                                            const RemeshOptions &options) {
  if (options.absoluteTargetLength >= 0.0) {
    return options.absoluteTargetLength;
  }
  if (vertices.rows() == 0) {
    return 0.0;
  }
  return (vertices.colwise().maxCoeff() - vertices.colwise().minCoeff())
             .norm() *
         options.lengthRatio;
}

inline void append_matrix_rows(Eigen::MatrixXd &target,
                               const Eigen::MatrixXd &source) {
  if (source.rows() == 0) {
    return;
  }
  if (target.rows() == 0) {
    target = source;
    return;
  }
  const Eigen::Index oldRows = target.rows();
  target.conservativeResize(oldRows + source.rows(), source.cols());
  target.block(oldRows, 0, source.rows(), source.cols()) = source;
}

inline void append_matrix_rows(Eigen::MatrixXi &target,
                               const Eigen::MatrixXi &source,
                               const int indexOffset = 0) {
  if (source.rows() == 0) {
    return;
  }
  Eigen::MatrixXi shifted = source;
  if (indexOffset != 0) {
    shifted.array() += indexOffset;
  }
  if (target.rows() == 0) {
    target = shifted;
    return;
  }
  const Eigen::Index oldRows = target.rows();
  target.conservativeResize(oldRows + shifted.rows(), shifted.cols());
  target.block(oldRows, 0, shifted.rows(), shifted.cols()) = shifted;
}

inline void append_vector(Eigen::VectorXi &target,
                          const Eigen::VectorXi &source) {
  if (source.size() == 0) {
    return;
  }
  if (target.size() == 0) {
    target = source;
    return;
  }
  const Eigen::Index oldRows = target.size();
  target.conservativeResize(oldRows + source.size());
  target.segment(oldRows, source.size()) = source;
}

inline void append_vector(Eigen::VectorXd &target,
                          const Eigen::VectorXd &source) {
  if (source.size() == 0) {
    return;
  }
  if (target.size() == 0) {
    target = source;
    return;
  }
  const Eigen::Index oldRows = target.size();
  target.conservativeResize(oldRows + source.size());
  target.segment(oldRows, source.size()) = source;
}

inline void accumulate_component_diagnostics(
    directional::RemeshDiagnostics &target,
    const directional::RemeshDiagnostics &source) {
  if (target.terminalFailureCode == "None" &&
      source.terminalFailureCode != "None") {
    target.terminalFailureCode = source.terminalFailureCode;
    target.terminalFailureStage = source.terminalFailureStage;
  }
  if (target.originalSurfaceCellFailureCode == "None" &&
      source.originalSurfaceCellFailureCode != "None") {
    target.originalSurfaceCellFailureCode =
        source.originalSurfaceCellFailureCode;
    target.originalSurfaceCellFailureStage =
        source.originalSurfaceCellFailureStage;
  }
  if (target.requestedBackend == "LegacyInteger" &&
      source.requestedBackend != "LegacyInteger") {
    target.requestedBackend = source.requestedBackend;
  }
  if (target.executedBackend != source.executedBackend) {
    target.executedBackend =
        target.executedBackend.empty() ? source.executedBackend : "Mixed";
    target.remeshBackend = target.executedBackend;
  }
  if (target.surfaceCellFallbackCause.empty() &&
      !source.surfaceCellFallbackCause.empty()) {
    target.surfaceCellFallbackCause = source.surfaceCellFallbackCause;
  }
  target.surfaceCellFallbackAttempted =
      target.surfaceCellFallbackAttempted || source.surfaceCellFallbackAttempted;
  target.surfaceCellUsedLegacyFallback =
      target.surfaceCellUsedLegacyFallback || source.surfaceCellUsedLegacyFallback;
  target.surfaceCellReturnedQuadDominantFallback =
      target.surfaceCellReturnedQuadDominantFallback ||
      source.surfaceCellReturnedQuadDominantFallback;
  target.surfaceCellReturnedInputMeshFallback =
      target.surfaceCellReturnedInputMeshFallback ||
      source.surfaceCellReturnedInputMeshFallback;
  target.surfaceCellRemeshOccurred =
      target.surfaceCellRemeshOccurred || source.surfaceCellRemeshOccurred;
  target.surfaceCellDebugArtifactsPreserved =
      target.surfaceCellDebugArtifactsPreserved ||
      source.surfaceCellDebugArtifactsPreserved;
  target.surfaceCellDebugArtifacts.insert(
      target.surfaceCellDebugArtifacts.end(),
      source.surfaceCellDebugArtifacts.begin(),
      source.surfaceCellDebugArtifacts.end());

  target.surfaceCellFeatureSeconds += source.surfaceCellFeatureSeconds;
  target.surfaceCellMetricSeconds += source.surfaceCellMetricSeconds;
  target.surfaceCellReliefSeconds += source.surfaceCellReliefSeconds;
  target.surfaceCellTracingSeconds += source.surfaceCellTracingSeconds;
  target.surfaceCellArrangementSeconds += source.surfaceCellArrangementSeconds;
  target.surfaceCellSimplificationSeconds +=
      source.surfaceCellSimplificationSeconds;
  target.surfaceCellCompletionSeconds += source.surfaceCellCompletionSeconds;
  target.surfaceCellOptimizationSeconds +=
      source.surfaceCellOptimizationSeconds;
  target.surfaceCellValidationSeconds += source.surfaceCellValidationSeconds;
  target.surfaceCellValidationFailures +=
      source.surfaceCellValidationFailures;
  target.surfaceCellProvenanceVertexCount +=
      source.surfaceCellProvenanceVertexCount;
  target.surfaceCellFeatureCount += source.surfaceCellFeatureCount;
  target.surfaceCellMetricSampleCount += source.surfaceCellMetricSampleCount;
  target.surfaceCellReliefPatchCount += source.surfaceCellReliefPatchCount;
  target.surfaceCellTraceSegmentCount += source.surfaceCellTraceSegmentCount;
  target.surfaceCellArrangementCellCount +=
      source.surfaceCellArrangementCellCount;
  target.surfaceCellSimplifiedCellCount +=
      source.surfaceCellSimplifiedCellCount;
  target.surfaceCellCompletedQuadCount += source.surfaceCellCompletedQuadCount;
  target.surfaceCellOptimizationIterationCount +=
      source.surfaceCellOptimizationIterationCount;
  target.surfaceCellReliefCountAvailable =
      target.surfaceCellReliefCountAvailable ||
      source.surfaceCellReliefCountAvailable;
  target.surfaceCellTraceCountAvailable =
      target.surfaceCellTraceCountAvailable ||
      source.surfaceCellTraceCountAvailable;
  target.surfaceCellArrangementCountAvailable =
      target.surfaceCellArrangementCountAvailable ||
      source.surfaceCellArrangementCountAvailable;
  target.surfaceCellSimplifiedCountAvailable =
      target.surfaceCellSimplifiedCountAvailable ||
      source.surfaceCellSimplifiedCountAvailable;
  target.surfaceCellCompletedQuadCountAvailable =
      target.surfaceCellCompletedQuadCountAvailable ||
      source.surfaceCellCompletedQuadCountAvailable;
  target.surfaceCellOptimizationIterationCountAvailable =
      target.surfaceCellOptimizationIterationCountAvailable ||
      source.surfaceCellOptimizationIterationCountAvailable;

  target.adaptiveFeatureMapSeconds += source.adaptiveFeatureMapSeconds;
  target.adaptiveFeatureHardEdgeCount += source.adaptiveFeatureHardEdgeCount;
  target.adaptiveFeatureSoftEdgeCount += source.adaptiveFeatureSoftEdgeCount;
  target.adaptiveFeatureBoundaryEdgeCount +=
      source.adaptiveFeatureBoundaryEdgeCount;
  target.adaptiveFeatureNonManifoldEdgeCount +=
      source.adaptiveFeatureNonManifoldEdgeCount;
  target.adaptiveFeatureCurveCount += source.adaptiveFeatureCurveCount;
  target.adaptiveFeatureClosedCurveCount +=
      source.adaptiveFeatureClosedCurveCount;
  target.adaptiveFeatureMaxDensity =
      std::max(target.adaptiveFeatureMaxDensity,
               source.adaptiveFeatureMaxDensity);

  target.preconditioningSeconds += source.preconditioningSeconds;
  target.tangentBundleInitializationSeconds +=
      source.tangentBundleInitializationSeconds;
  target.fieldSetupSeconds += source.fieldSetupSeconds;
  target.principalMatchingSeconds += source.principalMatchingSeconds;
  target.setupIntegrationSeconds += source.setupIntegrationSeconds;
  target.integrationTotalSeconds += source.integrationTotalSeconds;
  target.setupMesherSeconds += source.setupMesherSeconds;
  target.mesherTotalSeconds += source.mesherTotalSeconds;

  target.preconditioningFlipsAccepted += source.preconditioningFlipsAccepted;
  target.preconditioningCollapsesAccepted +=
      source.preconditioningCollapsesAccepted;
  target.preconditioningSplitsAccepted += source.preconditioningSplitsAccepted;
  target.preconditioningInputTriangleCount +=
      source.preconditioningInputTriangleCount;
  target.preconditioningOutputTriangleCount +=
      source.preconditioningOutputTriangleCount;

  target.integration.totalSeconds += source.integration.totalSeconds;
  target.integration.parametrizationQualityAnalysisSeconds +=
      source.integration.parametrizationQualityAnalysisSeconds;
  target.integration.targetedStiffeningExtraSolveSeconds +=
      source.integration.targetedStiffeningExtraSolveSeconds;
  target.integration.directFactorizations += source.integration.directFactorizations;
  target.integration.roundingBatches += source.integration.roundingBatches;
  target.integration.integerIterations += source.integration.integerIterations;
  target.integration.parametrizationInitialBadFaceCount +=
      source.integration.parametrizationInitialBadFaceCount;
  target.integration.parametrizationPostStiffeningBadFaceCount +=
      source.integration.parametrizationPostStiffeningBadFaceCount;
  target.integration.parametrizationInvertedFaceCount +=
      source.integration.parametrizationInvertedFaceCount;
  target.integration.parametrizationNearDegenerateFaceCount +=
      source.integration.parametrizationNearDegenerateFaceCount;
  target.integration.targetedStiffeningPasses +=
      source.integration.targetedStiffeningPasses;
  target.integration.targetedStiffeningExtraFactorizations +=
      source.integration.targetedStiffeningExtraFactorizations;
  target.integration.maximumFreeVariables =
      std::max(target.integration.maximumFreeVariables,
               source.integration.maximumFreeVariables);
  target.integration.maximumConstraintRows =
      std::max(target.integration.maximumConstraintRows,
               source.integration.maximumConstraintRows);
  target.integration.maximumSystemRows =
      std::max(target.integration.maximumSystemRows,
               source.integration.maximumSystemRows);
  target.integration.maximumSystemNonZeros =
      std::max(target.integration.maximumSystemNonZeros,
               source.integration.maximumSystemNonZeros);

  target.mesher.totalMesherSeconds += source.mesher.totalMesherSeconds;
  target.mesher.generateArrangementSeconds +=
      source.mesher.generateArrangementSeconds;
  target.mesher.simplifyTotalSeconds += source.mesher.simplifyTotalSeconds;
  target.mesher.verticesBeforeSimplification +=
      source.mesher.verticesBeforeSimplification;
  target.mesher.facesBeforeSimplification +=
      source.mesher.facesBeforeSimplification;
  target.mesher.halfedgesBeforeSimplification +=
      source.mesher.halfedgesBeforeSimplification;
  target.mesher.verticesAfterSimplification +=
      source.mesher.verticesAfterSimplification;
  target.mesher.facesAfterSimplification +=
      source.mesher.facesAfterSimplification;
  target.mesher.halfedgesAfterSimplification +=
      source.mesher.halfedgesAfterSimplification;
}

inline RemeshResult remesh_components_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options) {
  using Clock = std::chrono::high_resolution_clock;
  const auto pipelineStart = Clock::now();
  const auto splitStart = Clock::now();
  std::vector<geometry::FaceComponent> components =
      geometry::compact_face_components(vertices, faces, &rawCrossField);
  const double splitSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            splitStart)
          .count() /
      1.0e6;

  if (components.size() <= 1U) {
    RemeshOptions sequentialOptions = options;
    sequentialOptions.parallelizeComponents = false;
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    return remesh_from_raw_cross_field_impl(meshWhole, rawCrossField,
                                            sequentialOptions);
  }

  const unsigned int hardwareThreads =
      std::max(1U, std::thread::hardware_concurrency());
  const std::size_t requestedThreads =
      options.maxComponentThreads > 0
          ? static_cast<std::size_t>(options.maxComponentThreads)
          : static_cast<std::size_t>(hardwareThreads);
  const std::size_t workerCount =
      std::max<std::size_t>(1, std::min(requestedThreads, components.size()));
  const double absoluteTargetLength =
      derive_absolute_target_length(vertices, options);

  struct ComponentRun {
    RemeshResult result;
    bool threw = false;
    std::string error;
    double wallSeconds = 0.0;
  };

  auto runComponent = [&](const std::size_t componentIndex) {
    const auto componentStart = Clock::now();
    ComponentRun run;
    try {
      const geometry::FaceComponent &component = components[componentIndex];
      TriMesh componentMesh;
      componentMesh.set_mesh(component.vertices, component.faces);
      RemeshOptions componentOptions = options;
      componentOptions.parallelizeComponents = false;
      componentOptions.progress = nullptr;
      componentOptions.mesherDataCallback = nullptr;
      componentOptions.absoluteTargetLength = absoluteTargetLength;
      run.result = remesh_from_raw_cross_field_impl(
          componentMesh, component.rawField, componentOptions);
    } catch (const std::exception &exception) {
      run.threw = true;
      run.error = exception.what();
    } catch (...) {
      run.threw = true;
      run.error = "Unknown component remesh failure.";
    }
    run.wallSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                              componentStart)
            .count() /
        1.0e6;
    return run;
  };

  const auto parallelStart = Clock::now();
  std::vector<ComponentRun> runs(components.size());
  if (workerCount == 1U) {
    for (std::size_t index = 0; index < components.size(); ++index) {
      runs[index] = runComponent(index);
    }
  } else {
    std::vector<std::future<ComponentRun>> active;
    std::vector<std::size_t> activeIndices;
    for (std::size_t next = 0; next < components.size(); ++next) {
      activeIndices.push_back(next);
      active.push_back(
          std::async(std::launch::async, runComponent, next));
      if (active.size() == workerCount || next + 1 == components.size()) {
        for (std::size_t activeIndex = 0; activeIndex < active.size();
             ++activeIndex) {
          runs[activeIndices[activeIndex]] = active[activeIndex].get();
        }
        active.clear();
        activeIndices.clear();
      }
    }
  }
  const double parallelSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            parallelStart)
          .count() /
      1.0e6;

  const auto mergeStart = Clock::now();
  RemeshResult merged;
  merged.success = true;
  merged.diagnostics.remeshBackend = remesh_backend_name(options.backend);
  merged.diagnostics.requestedBackend = remesh_backend_name(options.backend);
  merged.diagnostics.executedBackend.clear();
  merged.diagnostics.surfaceCellFallbackPolicy =
      surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
  merged.diagnostics.componentSplitSeconds = splitSeconds;
  merged.diagnostics.componentParallelWallSeconds = parallelSeconds;
  merged.diagnostics.componentCount = components.size();
  merged.diagnostics.componentThreadsRequested = requestedThreads;
  merged.diagnostics.componentThreadsUsed = workerCount;
  merged.diagnostics.componentPeakConcurrentTasks = workerCount;

  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    directional::ComponentRemeshDiagnostics componentDiagnostics;
    componentDiagnostics.componentIndex = index;
    componentDiagnostics.minimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    componentDiagnostics.inputFaceCount = component.originalFaces.size();
    componentDiagnostics.success =
        !runs[index].threw && runs[index].result.success;
    componentDiagnostics.wallSeconds = runs[index].wallSeconds;
    componentDiagnostics.integrationSeconds =
        runs[index].result.diagnostics.integrationTotalSeconds;
    componentDiagnostics.mesherSeconds =
        runs[index].result.diagnostics.mesherTotalSeconds;
    componentDiagnostics.outputVertexCount =
        static_cast<std::size_t>(runs[index].result.vertices.rows());
    componentDiagnostics.outputFaceCount =
        static_cast<std::size_t>(runs[index].result.faces.rows());
    merged.diagnostics.components.push_back(componentDiagnostics);

    if (!componentDiagnostics.success) {
      merged.success = false;
      merged.diagnostics.failedComponentIndex = index;
      merged.diagnostics.failedComponentMinimumOriginalFace =
          componentDiagnostics.minimumOriginalFace;
      break;
    }

    const int outputVertexOffset = static_cast<int>(merged.vertices.rows());
    append_matrix_rows(merged.vertices, runs[index].result.vertices);
    append_matrix_rows(merged.faces, runs[index].result.faces,
                       outputVertexOffset);
    append_vector(merged.degrees, runs[index].result.degrees);

    const int cutVertexOffset = static_cast<int>(merged.cutVertices.rows());
    append_matrix_rows(merged.cutVertices, runs[index].result.cutVertices);
    append_matrix_rows(merged.cutFaces, runs[index].result.cutFaces,
                       cutVertexOffset);
    append_matrix_rows(merged.cutFunctions, runs[index].result.cutFunctions);
    append_matrix_rows(merged.cutCornerFunctions,
                       runs[index].result.cutCornerFunctions);
    append_matrix_rows(merged.rawCrossField, runs[index].result.rawCrossField);
    append_vector(merged.crossFieldMatching,
                  runs[index].result.crossFieldMatching);
    append_vector(merged.crossFieldEffort, runs[index].result.crossFieldEffort);
    append_vector(merged.crossFieldSingularCycles,
                  runs[index].result.crossFieldSingularCycles);
    append_vector(merged.crossFieldSingularIndices,
                  runs[index].result.crossFieldSingularIndices);

    accumulate_component_diagnostics(merged.diagnostics,
                                     runs[index].result.diagnostics);
  }

  merged.diagnostics.componentMergeSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            mergeStart)
          .count() /
      1.0e6;
  merged.diagnostics.overallPipelineSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            pipelineStart)
          .count() /
      1.0e6;
  return merged;
}

/**
 * @brief Runs remeshing from raw mesh matrices and a raw 4-RoSy cross field.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param rawCrossField #F-by-12 raw field.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
inline RemeshResult remesh_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options = {}) {
  if (options.parallelizeComponents) {
    return remesh_components_from_raw_cross_field(vertices, faces, rawCrossField,
                                                 options);
  }
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  return remesh_from_raw_cross_field_impl(meshWhole, rawCrossField, options);
}

inline RemeshResult
remesh_from_cross_field_result(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const fields::CrossFieldResult &crossField,
                               const RemeshOptions &options = {}) {
  const bool surfaceCellsRequested =
      options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled;
  if (crossField.degree != fields::kCrossFieldDegree ||
      crossField.rawField.rows() != faces.rows() ||
      crossField.rawField.cols() != 12) {
    if (!surfaceCellsRequested) {
      throw std::runtime_error(
          "CrossFieldResult must contain a #F-by-12 degree-4 raw field.");
    }
    RemeshResult result;
    result.diagnostics.remeshBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.requestedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.executedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    result.diagnostics.terminalFailureCode =
        surface_cell_failure_code_name(
            SurfaceCellFailureCode::InvalidFieldDimensions);
    result.diagnostics.terminalFailureStage = "cross-field-validation";
    result.diagnostics.originalSurfaceCellFailureCode =
        result.diagnostics.terminalFailureCode;
    result.diagnostics.originalSurfaceCellFailureStage =
        result.diagnostics.terminalFailureStage;
    result.diagnostics.surfaceCellValidationFailures = 1U;
    return result;
  }
  if (surfaceCellsRequested && options.surfaceCells.requireMatching &&
      crossField.matching.size() == 0) {
    RemeshResult result;
    result.diagnostics.remeshBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.requestedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.executedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    result.diagnostics.terminalFailureCode =
        surface_cell_failure_code_name(SurfaceCellFailureCode::MissingMatching);
    result.diagnostics.terminalFailureStage = "cross-field-validation";
    result.diagnostics.originalSurfaceCellFailureCode =
        result.diagnostics.terminalFailureCode;
    result.diagnostics.originalSurfaceCellFailureStage =
        result.diagnostics.terminalFailureStage;
    result.diagnostics.surfaceCellValidationFailures = 1U;
    return result;
  }
  if (surfaceCellsRequested && options.surfaceCells.requireSingularities &&
      crossField.singularCycles.size() == 0 &&
      crossField.singularIndices.size() == 0) {
    RemeshResult result;
    result.diagnostics.remeshBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.requestedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.executedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    result.diagnostics.terminalFailureCode =
        surface_cell_failure_code_name(
            SurfaceCellFailureCode::MissingSingularities);
    result.diagnostics.terminalFailureStage = "cross-field-validation";
    result.diagnostics.originalSurfaceCellFailureCode =
        result.diagnostics.terminalFailureCode;
    result.diagnostics.originalSurfaceCellFailureStage =
        result.diagnostics.terminalFailureStage;
    result.diagnostics.surfaceCellValidationFailures = 1U;
    return result;
  }
  RemeshResult result =
      remesh_from_raw_cross_field(vertices, faces, crossField.rawField, options);
  result.crossFieldMatching = crossField.matching;
  result.crossFieldEffort = crossField.effort;
  result.crossFieldSingularCycles = crossField.singularCycles;
  result.crossFieldSingularIndices = crossField.singularIndices;
  return result;
}

/**
 * @brief Runs remeshing from two direction families per face.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param primaryDirections Primary ambient/tangent direction per face.
 * @param secondaryDirections Secondary ambient/tangent direction per face.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
inline RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const Eigen::MatrixXd &secondaryDirections,
                        const RemeshOptions &options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd rawField =
      fields::make_raw_cross_field(meshWhole, primaryDirections,
                                   secondaryDirections,
                                   options.normalizeDirections);
  return remesh_from_raw_cross_field_impl(meshWhole, rawField, options);
}

/**
 * @brief Runs remeshing from one direction family per face.
 *
 * The secondary direction is generated as the tangent-plane orthogonal
 * complement of the supplied primary direction.
 *
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param primaryDirections Primary ambient/tangent direction per face.
 * @param options Pipeline options.
 * @return Remeshing result.
 */
inline RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const RemeshOptions &options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd secondaryDirections = fields::orthogonal_complement(
      meshWhole, primaryDirections, options.normalizeDirections);
  const Eigen::MatrixXd rawField =
      fields::make_raw_cross_field(meshWhole, primaryDirections,
                                   secondaryDirections,
                                   options.normalizeDirections);
  return remesh_from_raw_cross_field_impl(meshWhole, rawField, options);
}

/**
 * @brief Extracts a smooth 4-RoSy cross field and runs the full remeshing pipeline.
 * @param vertices Source vertex positions.
 * @param faces Source triangle indices.
 * @param options Remeshing and direction-normalization options.
 * @return Remeshing result including the automatically extracted raw cross field.
 */
inline RemeshResult
remesh_from_mesh(const Eigen::MatrixXd &vertices,
                 const Eigen::MatrixXi &faces,
                 const RemeshOptions &options = {}) {
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  if (options.preconditionInputMesh) {
    const auto preconditionStart = std::chrono::high_resolution_clock::now();
    geometry::BoundedMeshPreconditionerOptions preconditionOptions;
    preconditionOptions.enabled = true;
    preconditionOptions.targetFaceRatio = options.preconditionTargetFaceRatio;
    preconditionOptions.maxFaceRatio = options.preconditionMaxFaceRatio;
    preconditionOptions.minFaceRatio = options.preconditionMinFaceRatio;
    preconditionOptions.sharpAngleDegrees =
        options.preconditionSharpAngleDegrees;
    preconditionOptions.featureMap = options.featureMap;
    const geometry::BoundedMeshPreconditionerResult preconditioned =
        geometry::BoundedMeshPreconditioner::precondition(
            meshWhole.V, meshWhole.F, preconditionOptions);
    const double preconditioningSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() - preconditionStart)
            .count() /
        1.0e6;
    bool appliedPreconditioning = false;
    try {
      meshWhole.set_mesh(preconditioned.vertices, preconditioned.faces);
      appliedPreconditioning = true;
    } catch (const std::exception &) {
      meshWhole.set_mesh(vertices, faces);
    }
    RemeshOptions preconditionedOptions = options;
    preconditionedOptions.preconditionInputMesh = false;

    report_progress(options.progress, 10, 110,
                    "Extracting source cross field");
    fields::CrossFieldOptions crossFieldOptions;
    crossFieldOptions.normalizeDirections = options.normalizeDirections;
    crossFieldOptions.computeMatching = false;
    const fields::CrossFieldResult crossField =
        fields::extract_cross_field(meshWhole, crossFieldOptions);
    RemeshResult result =
        remesh_from_raw_cross_field(meshWhole.V, meshWhole.F,
                                    crossField.rawField, preconditionedOptions);
    result.diagnostics.preconditioningSeconds = preconditioningSeconds;
    copy_adaptive_feature_diagnostics(result.diagnostics, preconditioned);
    result.diagnostics.preconditioningFlipsAccepted =
        appliedPreconditioning ? preconditioned.flipsAccepted : 0;
    result.diagnostics.preconditioningCollapsesAccepted =
        appliedPreconditioning ? preconditioned.collapsesAccepted : 0;
    result.diagnostics.preconditioningSplitsAccepted =
        appliedPreconditioning ? preconditioned.splitsAccepted : 0;
    result.diagnostics.preconditioningInputTriangleCount =
        preconditioned.inputTriangleCount;
    result.diagnostics.preconditioningOutputTriangleCount =
        appliedPreconditioning ? preconditioned.outputTriangleCount
                               : static_cast<std::size_t>(faces.rows());
    result.diagnostics.preconditioningMinAngleBefore =
        preconditioned.before.minTriangleAngleDegrees;
    result.diagnostics.preconditioningMinAngleAfter =
        appliedPreconditioning ? preconditioned.after.minTriangleAngleDegrees
                               : preconditioned.before.minTriangleAngleDegrees;
    result.diagnostics.preconditioningAspectRatioP95Before =
        preconditioned.before.aspectRatioP95;
    result.diagnostics.preconditioningAspectRatioP95After =
        appliedPreconditioning ? preconditioned.after.aspectRatioP95
                               : preconditioned.before.aspectRatioP95;
    result.diagnostics.preconditioningAspectRatioP99Before =
        preconditioned.before.aspectRatioP99;
    result.diagnostics.preconditioningAspectRatioP99After =
        appliedPreconditioning ? preconditioned.after.aspectRatioP99
                               : preconditioned.before.aspectRatioP99;
    result.diagnostics.preconditioningEdgeLengthCvBefore =
        preconditioned.before.edgeLengthCoefficientOfVariation;
    result.diagnostics.preconditioningEdgeLengthCvAfter =
        appliedPreconditioning
            ? preconditioned.after.edgeLengthCoefficientOfVariation
            : preconditioned.before.edgeLengthCoefficientOfVariation;
    return result;
  }

  report_progress(options.progress, 10, 110, "Extracting source cross field");
  fields::CrossFieldOptions crossFieldOptions;
  crossFieldOptions.normalizeDirections = options.normalizeDirections;
  crossFieldOptions.computeMatching = false;
  const fields::CrossFieldResult crossField =
      fields::extract_cross_field(meshWhole, crossFieldOptions);

  RemeshOptions remeshOptions = options;
  remeshOptions.progress =
      [callback = options.progress](const std::size_t current,
                                    const std::size_t total,
                                    const std::string_view task) {
        const std::size_t safeTotal = std::max<std::size_t>(total, 1);
        const std::size_t safeCurrent =
            std::min(std::max<std::size_t>(current, 1), safeTotal);
        const std::size_t mapped =
            10 + safeCurrent * 100 / safeTotal;
        report_progress(callback, std::min<std::size_t>(mapped, 110), 110,
                        task);
      };
  return remesh_from_raw_cross_field(meshWhole.V, meshWhole.F,
                                     crossField.rawField, remeshOptions);
}

} // namespace directional::pipeline

#endif // DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
