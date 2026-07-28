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
#include <cstdint>
#include <future>
#include <iomanip>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
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
#include <directional/geometry/PatchDescriptor.h>
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
  MissingConfidence,
  UncoveredFaces,
  UnsupportedInput,
  InvalidRailTopology,
  EmptyFlowRepNetwork,
  MissingFlowRepCoverageEvidence,
  MissingFlowRepCycleEvidence,
  InvalidFlowRepCoverageEvidence,
  InvalidFlowRepCycleEvidence,
  InvalidFlowRepArcIdentity,
  IncompleteFlowRepProvenance,
  IncompleteFlowRepCycleCoverage,
  FlowRepMandatoryRailLoss,
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
  case SurfaceCellFailureCode::MissingConfidence:
    return "MissingConfidence";
  case SurfaceCellFailureCode::UncoveredFaces:
    return "UncoveredFaces";
  case SurfaceCellFailureCode::UnsupportedInput:
    return "UnsupportedInput";
  case SurfaceCellFailureCode::InvalidRailTopology:
    return "InvalidRailTopology";
  case SurfaceCellFailureCode::EmptyFlowRepNetwork:
    return "EmptyFlowRepNetwork";
  case SurfaceCellFailureCode::MissingFlowRepCoverageEvidence:
    return "MissingFlowRepCoverageEvidence";
  case SurfaceCellFailureCode::MissingFlowRepCycleEvidence:
    return "MissingFlowRepCycleEvidence";
  case SurfaceCellFailureCode::InvalidFlowRepCoverageEvidence:
    return "InvalidFlowRepCoverageEvidence";
  case SurfaceCellFailureCode::InvalidFlowRepCycleEvidence:
    return "InvalidFlowRepCycleEvidence";
  case SurfaceCellFailureCode::InvalidFlowRepArcIdentity:
    return "InvalidFlowRepArcIdentity";
  case SurfaceCellFailureCode::IncompleteFlowRepProvenance:
    return "IncompleteFlowRepProvenance";
  case SurfaceCellFailureCode::IncompleteFlowRepCycleCoverage:
    return "IncompleteFlowRepCycleCoverage";
  case SurfaceCellFailureCode::FlowRepMandatoryRailLoss:
    return "FlowRepMandatoryRailLoss";
  case SurfaceCellFailureCode::InjectedStageFailure:
    return "InjectedStageFailure";
  case SurfaceCellFailureCode::NotProductionReady:
    return "NotProductionReady";
  }
  return "Unknown";
}

inline SurfaceCellFailureCode surface_cell_failure_from_flow_rep(
    const geometry::FlowRepSelectionFailureCode code) {
  switch (code) {
  case geometry::FlowRepSelectionFailureCode::None:
    return SurfaceCellFailureCode::None;
  case geometry::FlowRepSelectionFailureCode::EmptyNetwork:
    return SurfaceCellFailureCode::EmptyFlowRepNetwork;
  case geometry::FlowRepSelectionFailureCode::MissingCoverageEvidence:
    return SurfaceCellFailureCode::MissingFlowRepCoverageEvidence;
  case geometry::FlowRepSelectionFailureCode::MissingCycleEvidence:
    return SurfaceCellFailureCode::MissingFlowRepCycleEvidence;
  case geometry::FlowRepSelectionFailureCode::InvalidCoverageEvidence:
    return SurfaceCellFailureCode::InvalidFlowRepCoverageEvidence;
  case geometry::FlowRepSelectionFailureCode::InvalidCycleEvidence:
    return SurfaceCellFailureCode::InvalidFlowRepCycleEvidence;
  case geometry::FlowRepSelectionFailureCode::InvalidArcIdentity:
    return SurfaceCellFailureCode::InvalidFlowRepArcIdentity;
  case geometry::FlowRepSelectionFailureCode::IncompleteArcProvenance:
    return SurfaceCellFailureCode::IncompleteFlowRepProvenance;
  case geometry::FlowRepSelectionFailureCode::IncompleteCycleCoverage:
    return SurfaceCellFailureCode::IncompleteFlowRepCycleCoverage;
  case geometry::FlowRepSelectionFailureCode::MandatoryRailLoss:
    return SurfaceCellFailureCode::FlowRepMandatoryRailLoss;
  }
  return SurfaceCellFailureCode::InvalidFlowRepCycleEvidence;
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
  /// Reject outputs whose quads are all boundaries of adjacent source-triangle
  /// pairs. This is an explicit proof-fixture gate rather than a general
  /// production check because a valid minimal completed patch can coincide
  /// geometrically with a two-triangle source region.
  bool rejectPairedSourceTriangleBoundaryOutput = false;
  bool useSkeletonHints = false;
  SurfaceCellFallbackPolicy fallbackPolicy = SurfaceCellFallbackPolicy::Fail;
  int injectFailureAfterStage = -1;
  double geometricTolerance = 1.0e-9;
  geometry::AdaptiveFeatureMapOptions featureMap;
  geometry::AdaptiveTargetSizeOptions targetSize;
  geometry::LocalThicknessOptions thickness;
  geometry::ReliefOptions relief;
  geometry::ReliefRootSelectionOptions reliefRoots;
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

struct SurfaceCellContextProductDebug {
  std::string name;
  std::string type;
  std::uint64_t structuralHash = 0U;
  std::size_t elementCount = 0U;
  bool available = false;
};

struct SurfaceCellPipelineContext {
  TriMesh sourceMesh;
  bool hasSourceMesh = false;

  fields::CrossFieldResult crossField;
  bool hasCrossField = false;
  bool crossFieldHasMatching = false;
  bool crossFieldHasSingularities = false;

  geometry::AdaptiveFeatureMap featureMap;
  bool hasFeatureMap = false;

  std::vector<geometry::SurfaceCellRail> authoritativeRails;
  bool hasAuthoritativeRails = false;


  geometry::AdaptiveTargetSizeResult metricField;
  bool hasMetricField = false;

  geometry::ReliefTopologyResult reliefResult;
  bool hasReliefResult = false;

  geometry::ReliefRootSelectionResult reliefRootSelection;
  bool hasReliefRootSelection = false;
  std::set<std::uint64_t> reliefBarrierEdges;
  bool hasReliefBarrierEdges = false;

  geometry::SourceSurfaceLabels sourceSurfaceLabels;
  bool hasSourceSurfaceLabels = false;

  geometry::SurfaceCellNetwork traceNetwork;
  bool hasTraceNetwork = false;

  std::vector<geometry::FlowRepArc> flowRepArcs;
  geometry::FlowRepSparseNetwork flowRepNetwork;
  bool hasFlowRepNetwork = false;

  std::vector<geometry::SurfaceArrangementArc> embeddedArrangementArcs;
  bool hasEmbeddedArrangementArcs = false;

  geometry::SurfaceCellComplex arrangement;
  bool hasArrangement = false;

  geometry::SurfaceCellComplex simplifiedComplex;
  bool hasSimplifiedComplex = false;

  std::vector<geometry::PatchDescriptor> patchDescriptors;
  bool hasPatchDescriptors = false;

  std::vector<geometry::PureQuadMesh> completedPatches;
  Eigen::MatrixXd completedVertices;
  Eigen::MatrixXi completedQuads;
  std::vector<geometry::SurfacePoint> completedProvenance;
  std::vector<geometry::PureQuadVertexLineage> completedVertexLineage;
  std::vector<geometry::PureQuadFaceLineage> completedQuadLineage;
  geometry::PureQuadOutputLineageValidation outputLineageValidation;
  bool hasCompletedPatches = false;

  geometry::SurfaceOptimizationResult optimizationResult;
  bool hasOptimizationResult = false;

  geometry::SurfaceFinalValidationReport validationResult;
  bool hasValidationResult = false;

  std::vector<SurfaceCellContextProductDebug> debugProducts;
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
  std::vector<directional::geometry::PureQuadVertexLineage> outputVertexLineage;
  std::vector<directional::geometry::PureQuadFaceLineage> outputQuadLineage;

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

  /// Typed SurfaceCells intermediates preserved for diagnostics and downstream stages.
  SurfaceCellPipelineContext surfaceCellContext;

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


inline void hash_combine_u64(std::uint64_t &seed, const std::uint64_t value) {
  seed ^= value + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
}

inline void hash_combine_i64(std::uint64_t &seed, const std::int64_t value) {
  hash_combine_u64(seed, static_cast<std::uint64_t>(value));
}

inline void hash_combine_double(std::uint64_t &seed, const double value) {
  const double sanitized = std::isfinite(value) ? value : 0.0;
  hash_combine_i64(seed, static_cast<std::int64_t>(std::llround(sanitized * 1.0e9)));
}

inline void hash_combine_string(std::uint64_t &seed, const std::string &value) {
  for (const char ch : value) {
    hash_combine_u64(seed, static_cast<unsigned char>(ch));
  }
}

inline std::uint64_t structural_hash_seed(const std::string &type) {
  std::uint64_t seed = 1469598103934665603ULL;
  hash_combine_string(seed, type);
  return seed;
}

inline void hash_matrix(std::uint64_t &seed, const Eigen::MatrixXd &matrix) {
  hash_combine_i64(seed, matrix.rows());
  hash_combine_i64(seed, matrix.cols());
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      hash_combine_double(seed, matrix(row, col));
    }
  }
}

inline void hash_matrix(std::uint64_t &seed, const Eigen::MatrixXi &matrix) {
  hash_combine_i64(seed, matrix.rows());
  hash_combine_i64(seed, matrix.cols());
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      hash_combine_i64(seed, matrix(row, col));
    }
  }
}

inline void hash_vector(std::uint64_t &seed, const Eigen::VectorXd &values) {
  hash_combine_i64(seed, values.size());
  for (Eigen::Index index = 0; index < values.size(); ++index) {
    hash_combine_double(seed, values(index));
  }
}

inline void hash_vector(std::uint64_t &seed, const std::vector<int> &values) {
  hash_combine_u64(seed, values.size());
  for (const int value : values) {
    hash_combine_i64(seed, value);
  }
}


inline void hash_row_vector(std::uint64_t &seed, const Eigen::RowVector3d &v) {
  hash_combine_double(seed, v.x());
  hash_combine_double(seed, v.y());
  hash_combine_double(seed, v.z());
}

inline void hash_surface_point(std::uint64_t &seed,
                               const geometry::SurfacePoint &point) {
  hash_combine_i64(seed, point.face);
  hash_combine_i64(seed, point.component);
  hash_combine_i64(seed, point.sheet);
  hash_combine_double(seed, point.barycentric.x());
  hash_combine_double(seed, point.barycentric.y());
  hash_combine_double(seed, point.barycentric.z());
  hash_combine_double(seed, point.position.x());
  hash_combine_double(seed, point.position.y());
  hash_combine_double(seed, point.position.z());
  hash_combine_double(seed, point.squaredDistance);
}

inline std::uint64_t hash_feature_map(
    const geometry::AdaptiveFeatureMap &map) {
  std::uint64_t seed = structural_hash_seed("feature");
  for (const auto &entry : map.edgeIndex) {
    hash_combine_i64(seed, entry.first.first);
    hash_combine_i64(seed, entry.first.second);
    hash_combine_i64(seed, entry.second);
  }
  for (const geometry::AdaptiveFeatureEdge &edge : map.edges) {
    hash_combine_i64(seed, edge.vertices.first);
    hash_combine_i64(seed, edge.vertices.second);
    hash_vector(seed, edge.incidentFaces);
    hash_combine_i64(seed, edge.component);
    hash_combine_i64(seed, edge.curve);
    hash_combine_double(seed, edge.angleRadians);
    hash_combine_double(seed, edge.strength);
    hash_combine_double(seed, edge.ridgeValleyConfidence);
    hash_combine_double(seed, edge.length);
    hash_combine_i64(seed, static_cast<int>(edge.edgeClass));
    hash_combine_i64(seed, edge.userTagged ? 1 : 0);
  }
  for (const geometry::AdaptiveFeatureCurve &curve : map.curves) {
    hash_combine_i64(seed, curve.id);
    hash_combine_i64(seed, curve.component);
    hash_vector(seed, curve.edges);
    hash_vector(seed, curve.vertices);
    hash_combine_i64(seed, curve.closed ? 1 : 0);
    hash_vector(seed, curve.corners);
    hash_vector(seed, curve.junctions);
  }
  for (const geometry::AdaptiveFeatureComponentStats &stats : map.componentStats) {
    hash_combine_u64(seed, stats.manifoldInteriorEdgeCount);
    hash_combine_double(seed, stats.p50Degrees);
    hash_combine_double(seed, stats.p75Degrees);
    hash_combine_double(seed, stats.p90Degrees);
    hash_combine_double(seed, stats.p95Degrees);
    hash_combine_double(seed, stats.p98Degrees);
    hash_combine_double(seed, stats.maxDegrees);
    hash_combine_i64(seed, stats.cadLike ? 1 : 0);
  }
  hash_vector(seed, map.vertexDensity);
  hash_combine_i64(seed, map.hasNonManifold ? 1 : 0);
  hash_combine_u64(seed, map.tangentRejectedEdges);
  hash_combine_u64(seed, map.indexedLookupCount);
  return seed;
}

inline void hash_trace_segment(std::uint64_t &seed,
                               const geometry::SurfaceTraceSegment &segment) {
  hash_combine_i64(seed, segment.face);
  hash_row_vector(seed, segment.startBarycentric);
  hash_row_vector(seed, segment.endBarycentric);
  hash_combine_i64(seed, segment.family);
  hash_combine_i64(seed, segment.sign);
  hash_combine_i64(seed, segment.entryEdge);
  hash_combine_i64(seed, segment.exitEdge);
  hash_combine_i64(seed, segment.matching);
  hash_combine_double(seed, segment.matchingEffort);
  hash_combine_i64(seed, segment.railId);
  hash_combine_i64(seed, segment.curveId);
  hash_combine_i64(seed, segment.railIntervalIndex);
  hash_combine_i64(seed, segment.railSideSign);
  hash_combine_double(seed, segment.railT0);
  hash_combine_double(seed, segment.railT1);
}

inline void hash_trace_point(std::uint64_t &seed,
                             const geometry::SurfaceTracePoint &point) {
  hash_combine_i64(seed, point.face);
  hash_row_vector(seed, point.barycentric);
}

inline std::uint64_t hash_trace_network(
    const geometry::SurfaceCellNetwork &network) {
  std::uint64_t seed = structural_hash_seed("tracing");
  hash_vector(seed, network.reliefRootVertices);
  hash_combine_i64(seed, network.reliefRegionLabels.size());
  for (Eigen::Index index = 0; index < network.reliefRegionLabels.size(); ++index) {
    hash_combine_i64(seed, network.reliefRegionLabels(index));
  }
  hash_combine_u64(seed, network.reliefBarrierEdges.size());
  for (const std::uint64_t barrier : network.reliefBarrierEdges) {
    hash_combine_u64(seed, barrier);
  }
  hash_vector(seed, network.sourceFaceComponents);
  hash_vector(seed, network.sourceFaceSheets);
  hash_combine_u64(seed, network.authoritativeRails.size());
  for (const geometry::SurfaceCellRail &rail : network.authoritativeRails) {
    hash_combine_i64(seed, rail.id);
    hash_combine_i64(seed, static_cast<int>(rail.kind));
    hash_combine_i64(seed, rail.curveId);
    hash_combine_i64(seed, rail.component);
    hash_combine_i64(seed, rail.closed ? 1 : 0);
    hash_vector(seed, rail.sourceVertices);
    hash_vector(seed, rail.sourceEdges);
    hash_combine_u64(seed, rail.samples.size());
    for (const geometry::SurfaceCellRailSample &sample : rail.samples) {
      hash_combine_i64(seed, sample.sourceFace);
      hash_combine_i64(seed, sample.sourceEdge);
      hash_combine_double(seed, sample.parameter);
      hash_combine_double(seed, sample.railParameter);
      hash_row_vector(seed, sample.barycentric);
      hash_row_vector(seed, sample.position);
    }
  }
  hash_combine_u64(seed, network.seeds.size());
  for (const geometry::SurfaceTraceSeed &traceSeed : network.seeds) {
    hash_combine_i64(seed, traceSeed.id);
    hash_trace_point(seed, traceSeed.point);
    hash_combine_i64(seed, static_cast<int>(traceSeed.provenance));
    hash_combine_i64(seed, traceSeed.sourceId);
  }
  hash_combine_u64(seed, network.traces.size());
  for (const geometry::SurfaceTraceResult &trace : network.traces) {
    hash_combine_u64(seed, trace.segments.size());
    for (const geometry::SurfaceTraceSegment &segment : trace.segments) {
      hash_trace_segment(seed, segment);
    }
    hash_combine_i64(seed, static_cast<int>(trace.termination));
    hash_combine_double(seed, trace.length);
  }
  hash_combine_u64(seed, network.proposals.size());
  for (const geometry::SurfaceCellProposal &proposal : network.proposals) {
    hash_combine_i64(seed, proposal.seedId);
    hash_combine_i64(seed, proposal.accepted ? 1 : 0);
    hash_combine_i64(seed, static_cast<int>(proposal.rejection));
    hash_combine_double(seed, proposal.closureError);
    for (const geometry::SurfaceTracePoint &corner : proposal.corners) {
      hash_trace_point(seed, corner);
    }
    hash_combine_u64(seed, proposal.sides.size());
    for (const geometry::SurfaceTraceSegment &side : proposal.sides) {
      hash_trace_segment(seed, side);
    }
    hash_combine_u64(seed, proposal.boundaryPaths.size());
    for (const auto &path : proposal.boundaryPaths) {
      hash_combine_u64(seed, path.size());
      for (const geometry::SurfaceTraceSegment &segment : path) {
        hash_trace_segment(seed, segment);
      }
    }
  }
  hash_combine_i64(seed, network.stats.attempted);
  hash_combine_i64(seed, network.stats.accepted);
  hash_combine_i64(seed, network.stats.rejectedClosure);
  hash_combine_i64(seed, network.stats.rejectedBarrier);
  hash_combine_i64(seed, network.stats.rejectedDegenerate);
  hash_combine_i64(seed, network.stats.rejectedSourceSheet);
  hash_combine_i64(seed, network.stats.rejectedFieldMetadata);
  hash_combine_i64(seed, network.stats.rejectedSelfIntersection);
  hash_combine_i64(seed, network.stats.rejectedInverted);
  hash_combine_i64(seed, network.stats.rejectedDuplicateCorner);
  hash_combine_i64(seed, network.stats.rejectedOutOfSize);
  hash_combine_i64(seed, network.stats.rejectedHardRailCrossing);
  return seed;
}

inline std::uint64_t hash_sparse_network(
    const geometry::FlowRepSparseNetwork &network) {
  std::uint64_t seed = structural_hash_seed("strands");
  hash_combine_i64(seed, network.selectionSucceeded ? 1 : 0);
  hash_combine_i64(seed, static_cast<int>(network.failureCode));
  hash_vector(seed, network.retainedArcIds);
  hash_vector(seed, network.removedArcIds);
  for (const geometry::FlowRepEndpointTag tag : network.endpointTags) {
    hash_combine_i64(seed, static_cast<int>(tag));
  }
  for (const geometry::FlowRepCycleEvaluation &cycle : network.cycleEvaluations) {
    hash_combine_i64(seed, cycle.descriptive ? 1 : 0);
    hash_combine_i64(seed, cycle.quadrangulable ? 1 : 0);
    hash_combine_double(seed, cycle.normalP90);
    hash_combine_double(seed, cycle.surfaceP95);
    hash_combine_double(seed, cycle.sizePenalty);
    hash_combine_double(seed, cycle.quadPenalty);
    hash_combine_double(seed, cycle.energy);
    hash_combine_i64(seed, static_cast<int>(cycle.patchClass));
  }
  hash_combine_i64(seed, network.mandatoryRails);
  hash_combine_i64(seed, network.retainedMandatoryRails);
  hash_combine_i64(seed, network.acceptedTransactions);
  hash_combine_i64(seed, network.attemptedStrandTransactions);
  hash_combine_i64(seed, network.rejectedStrandTransactions);
  hash_combine_i64(seed, network.retainedFlowlines);
  hash_combine_i64(seed, network.removedFlowlines);
  hash_combine_i64(seed, network.cycleRebuilds);
  hash_combine_i64(seed, network.coverageSampleCount);
  hash_combine_i64(seed, network.cycleEvidenceCount);
  hash_combine_i64(seed, network.coverageEvidenceUsed ? 1 : 0);
  hash_combine_i64(seed, network.cycleEvidenceUsed ? 1 : 0);
  hash_combine_double(seed, network.denseCoverageMax);
  hash_combine_double(seed, network.sparseCoverageMax);
  return seed;
}

inline std::uint64_t hash_flow_rep_selection_input(
    const geometry::FlowRepSelectionInput &input) {
  std::uint64_t seed = structural_hash_seed("flow-rep-selection-input");
  hash_combine_u64(seed, input.arcs.size());
  for (const geometry::FlowRepArc &arc : input.arcs) {
    hash_combine_i64(seed, arc.id);
    hash_row_vector(seed, arc.start);
    hash_row_vector(seed, arc.end);
    hash_combine_i64(seed, arc.sourceFace);
    hash_row_vector(seed, arc.startBarycentric);
    hash_row_vector(seed, arc.endBarycentric);
    hash_combine_i64(seed, arc.sourceComponent);
    hash_combine_i64(seed, arc.sourceSheet);
    hash_combine_i64(seed, arc.family);
    hash_combine_i64(seed, arc.featureClass);
    hash_combine_i64(seed, arc.mandatoryRail ? 1 : 0);
    hash_combine_i64(seed, arc.boundaryRail ? 1 : 0);
    hash_combine_i64(seed, arc.hardFeatureRail ? 1 : 0);
    hash_combine_i64(seed, arc.strandProvenance);
    hash_combine_i64(seed, arc.featureProvenance);
    hash_combine_i64(seed, arc.railId);
    hash_combine_i64(seed, arc.curveId);
    hash_combine_double(seed, arc.railT0);
    hash_combine_double(seed, arc.railT1);
    hash_combine_double(seed, arc.dominance);
    hash_combine_double(seed, arc.alignmentCost);
    hash_combine_i64(seed, arc.sameStrandHint);
    hash_combine_i64(seed, arc.initiallyActive ? 1 : 0);
    hash_combine_i64(seed, arc.proposalId);
    hash_combine_i64(seed, arc.proposalSeedId);
    hash_combine_i64(seed, arc.proposalSide);
    hash_combine_i64(seed, arc.proposalBoundarySegment);
    hash_vector(seed, arc.substitutions);
  }
  hash_combine_u64(seed, input.coverageSamples.size());
  for (const geometry::FlowRepCoverageSample &sample : input.coverageSamples) {
    hash_row_vector(seed, sample.position);
    hash_combine_i64(seed, sample.sourceFace);
    hash_row_vector(seed, sample.barycentric);
    hash_combine_i64(seed, sample.sourceComponent);
    hash_combine_i64(seed, sample.sourceSheet);
    hash_combine_double(seed, sample.targetSize);
    hash_combine_i64(seed, sample.sourceArcId);
  }
  hash_combine_u64(seed, input.cycles.size());
  for (const geometry::FlowRepCycleInput &cycle : input.cycles) {
    hash_combine_i64(seed, cycle.id);
    hash_combine_i64(seed, cycle.proposalId);
    hash_combine_u64(seed, cycle.sideArcIds.size());
    for (const std::vector<int> &side : cycle.sideArcIds) {
      hash_vector(seed, side);
    }
    hash_vector(seed, cycle.boundaryArcIds);
    hash_vector(seed, cycle.sideCounts);
    hash_combine_u64(seed, cycle.normals.size());
    for (const Eigen::RowVector3d &normal : cycle.normals) {
      hash_row_vector(seed, normal);
    }
    for (const Eigen::RowVector3d &normal : cycle.boundaryNormalA) {
      hash_row_vector(seed, normal);
    }
    for (const Eigen::RowVector3d &normal : cycle.boundaryNormalB) {
      hash_row_vector(seed, normal);
    }
    hash_combine_u64(seed, cycle.distanceA.size());
    for (const double value : cycle.distanceA) {
      hash_combine_double(seed, value);
    }
    hash_combine_u64(seed, cycle.distanceB.size());
    for (const double value : cycle.distanceB) {
      hash_combine_double(seed, value);
    }
    hash_combine_u64(seed, cycle.surfaceDistances.size());
    for (const double value : cycle.surfaceDistances) {
      hash_combine_double(seed, value);
    }
    hash_combine_double(seed, cycle.targetSize);
    hash_combine_double(seed, cycle.normalThresholdRadians);
    hash_combine_i64(seed, cycle.diskTopology ? 1 : 0);
    hash_combine_i64(seed, cycle.forbiddenTurn ? 1 : 0);
    hash_combine_i64(seed, cycle.unresolvedHardFeatureCrossing ? 1 : 0);
    hash_combine_i64(seed, cycle.impossibleSideCounts ? 1 : 0);
  }
  return seed;
}

inline std::uint64_t hash_arrangement_arcs(
    const std::vector<geometry::SurfaceArrangementArc> &arcs) {
  std::uint64_t seed = structural_hash_seed("embedded-network");
  hash_combine_u64(seed, arcs.size());
  for (const geometry::SurfaceArrangementArc &arc : arcs) {
    hash_combine_i64(seed, arc.id);
    hash_combine_i64(seed, arc.sourceFace);
    hash_row_vector(seed, arc.startBarycentric);
    hash_row_vector(seed, arc.endBarycentric);
    hash_combine_i64(seed, arc.family);
    hash_combine_i64(seed, arc.strand);
    hash_combine_i64(seed, arc.featureClass);
    hash_combine_i64(seed, arc.hardFeature ? 1 : 0);
    hash_combine_i64(seed, arc.provenance);
    hash_combine_i64(seed, arc.railId);
    hash_combine_i64(seed, arc.curveId);
    hash_combine_i64(seed, arc.sourceComponent);
    hash_combine_i64(seed, arc.sourceSheet);
    hash_combine_i64(seed, arc.proposalId);
    hash_combine_i64(seed, arc.proposalSeedId);
    hash_combine_i64(seed, arc.proposalSide);
    hash_combine_i64(seed, arc.proposalBoundarySegment);
    hash_combine_double(seed, arc.railT0);
    hash_combine_double(seed, arc.railT1);
  }
  return seed;
}

inline std::uint64_t hash_surface_complex(
    const geometry::SurfaceCellComplex &complex) {
  std::uint64_t seed = structural_hash_seed("arrangement");
  for (const geometry::SurfaceArrangementNode &node : complex.nodes) {
    hash_combine_i64(seed, node.id);
    hash_combine_i64(seed, node.sourceFace);
    hash_combine_i64(seed, node.hardBarrierCrossing ? 1 : 0);
    hash_row_vector(seed, node.barycentric);
    hash_combine_i64(seed, static_cast<int>(node.occurrences.size()));
    for (const geometry::SurfaceArrangementNodeOccurrence &occurrence :
         node.occurrences) {
      hash_combine_i64(seed, occurrence.sourceFace);
      hash_row_vector(seed, occurrence.barycentric);
    }
    hash_combine_i64(seed, node.sourceEdge);
    hash_combine_double(seed, node.sourceEdgeParameter);
  }
  for (const geometry::SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    hash_combine_i64(seed, halfedge.id);
    hash_combine_i64(seed, halfedge.twin);
    hash_combine_i64(seed, halfedge.next);
    hash_combine_i64(seed, halfedge.from);
    hash_combine_i64(seed, halfedge.to);
    hash_combine_i64(seed, halfedge.sourceArc);
    hash_combine_i64(seed, halfedge.family);
    hash_combine_i64(seed, halfedge.strand);
    hash_combine_i64(seed, halfedge.featureClass);
    hash_combine_i64(seed, halfedge.sourceFace);
    hash_combine_double(seed, halfedge.sourceT0);
    hash_combine_double(seed, halfedge.sourceT1);
    hash_combine_i64(seed, halfedge.hardFeature ? 1 : 0);
    hash_combine_i64(seed, halfedge.railId);
    hash_combine_i64(seed, halfedge.curveId);
    hash_combine_i64(seed, halfedge.sourceComponent);
    hash_combine_i64(seed, halfedge.sourceSheet);
    hash_combine_i64(seed, halfedge.proposalId);
    hash_combine_i64(seed, halfedge.proposalSeedId);
    hash_combine_i64(seed, halfedge.proposalSide);
    hash_combine_i64(seed, halfedge.proposalBoundarySegment);
    hash_combine_double(seed, halfedge.railT0);
    hash_combine_double(seed, halfedge.railT1);
    hash_combine_i64(seed, halfedge.cell);
  }
  for (const geometry::SurfaceArrangementCell &cell : complex.cells) {
    hash_combine_i64(seed, cell.id);
    hash_combine_i64(seed, cell.sourceFace);
    hash_vector(seed, cell.sourceFaces);
    hash_vector(seed, cell.halfedges);
    hash_vector(seed, cell.sideFamilies);
    hash_vector(seed, cell.sideEdgeCounts);
    hash_combine_double(seed, cell.signedArea);
    hash_combine_double(seed, cell.area);
    hash_combine_i64(seed, cell.boundaryCycle ? 1 : 0);
    hash_combine_i64(seed, cell.closed ? 1 : 0);
    hash_combine_i64(seed, cell.disk ? 1 : 0);
    hash_combine_i64(seed, cell.boundaryComponentCount);
    hash_combine_i64(seed, cell.eulerCharacteristic);
    hash_combine_i64(seed, cell.quadReady ? 1 : 0);
    hash_combine_i64(seed, static_cast<int>(cell.cellClass));
    hash_combine_i64(seed, static_cast<int>(cell.rejectReason));
  }
  hash_combine_i64(seed, complex.diagnostics.plantedIntersections);
  hash_combine_i64(seed, complex.diagnostics.uniqueIntersections);
  hash_combine_i64(seed, complex.diagnostics.unsplitCrossings);
  hash_combine_i64(seed, complex.diagnostics.geometricTJunctions);
  hash_combine_i64(seed, complex.diagnostics.incompleteArcChains);
  hash_combine_i64(seed, complex.diagnostics.hardBarrierCrossings);
  hash_combine_i64(seed, complex.diagnostics.eulerCharacteristic);
  hash_combine_i64(seed, complex.diagnostics.sourceEulerCharacteristic);
  hash_combine_i64(seed, complex.diagnostics.connectedComponentCount);
  hash_combine_i64(seed, complex.diagnostics.sourceConnectedComponentCount);
  hash_combine_i64(seed, complex.diagnostics.boundaryLoopCount);
  hash_combine_i64(seed, complex.diagnostics.sourceBoundaryLoopCount);
  hash_combine_i64(seed, complex.diagnostics.incidenceValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.embeddingValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.orientationValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.cellsDiskValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.boundaryLoopsValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.eulerCharacteristicValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.topologyValid ? 1 : 0);
  hash_combine_double(seed, complex.diagnostics.supportedArea);
  hash_combine_double(seed, complex.diagnostics.extractedArea);
  hash_combine_double(seed, complex.diagnostics.relativeAreaError);
  hash_combine_double(seed, complex.diagnostics.memoryRatioEstimate);
  return seed;
}

inline std::uint64_t hash_completion_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const std::vector<geometry::SurfacePoint> &provenance) {
  std::uint64_t seed = structural_hash_seed("completion");
  hash_matrix(seed, vertices);
  hash_matrix(seed, quads);
  for (const geometry::SurfacePoint &point : provenance) {
    hash_surface_point(seed, point);
  }
  return seed;
}

inline std::uint64_t hash_completion(const geometry::PureQuadMesh &mesh) {
  std::uint64_t seed = structural_hash_seed("completion");
  hash_vector(seed, mesh.vertices);
  hash_matrix(seed, mesh.vertexPositions);
  hash_combine_u64(seed, mesh.quads.size());
  for (const std::vector<int> &quad : mesh.quads) {
    hash_vector(seed, quad);
  }
  for (const geometry::SurfacePoint &point : mesh.vertexProvenance) {
    hash_surface_point(seed, point);
  }
  hash_vector(seed, mesh.boundaryVertices);
  hash_combine_i64(seed, static_cast<int>(mesh.backend));
  hash_combine_i64(seed, mesh.usesCenterFan ? 1 : 0);
  return seed;
}
inline void hash_vector(std::uint64_t &seed, const Eigen::VectorXi &values) {
  hash_combine_i64(seed, values.size());
  for (Eigen::Index index = 0; index < values.size(); ++index) {
    hash_combine_i64(seed, values(index));
  }
}

inline std::uint64_t hash_relief_topology(
    const geometry::ReliefTopologyResult &topology) {
  std::uint64_t seed = structural_hash_seed("relief");
  hash_vector(seed, topology.relief);
  hash_vector(seed, topology.watershedLabels);
  hash_vector(seed, topology.watershedRoots);
  for (const geometry::ReliefCriticalPoint &point : topology.criticalPoints) {
    hash_combine_i64(seed, point.vertex);
    hash_combine_i64(seed, static_cast<int>(point.type));
    hash_combine_i64(seed, point.lowerComponents);
    hash_combine_i64(seed, point.upperComponents);
    hash_combine_i64(seed, point.multiplicity);
    hash_combine_i64(seed, point.retained ? 1 : 0);
  }
  for (const geometry::ReliefPersistencePair &pair : topology.persistencePairs) {
    hash_combine_i64(seed, pair.extremum);
    hash_combine_i64(seed, pair.saddle);
    hash_combine_i64(seed, pair.minimumPair ? 1 : 0);
    hash_combine_double(seed, pair.persistence);
    hash_combine_i64(seed, pair.canceled ? 1 : 0);
  }
  for (const geometry::ReliefBranch &branch : topology.branches) {
    hash_combine_i64(seed, branch.saddle);
    hash_combine_i64(seed, branch.extremum);
    hash_combine_i64(seed, branch.ascending ? 1 : 0);
    hash_vector(seed, branch.vertices);
  }
  return seed;
}

inline std::string structural_hash_string(const std::uint64_t hash) {
  std::ostringstream out;
  out << std::hex << std::setw(16) << std::setfill('0') << hash;
  return out.str();
}

inline SurfaceCellObjectIdentity make_surface_cell_identity(
    const std::string &type, const std::uint64_t hash,
    const std::size_t elementCount) {
  SurfaceCellObjectIdentity identity;
  identity.type = type;
  identity.structuralHash = hash;
  identity.elementCount = elementCount;
  return identity;
}

inline std::string surface_cell_identity_label(
    const SurfaceCellObjectIdentity &identity) {
  return identity.type + ":hash=" +
         structural_hash_string(identity.structuralHash) + ";count=" +
         std::to_string(identity.elementCount);
}

inline void normalize_surface_cell_cross_field_directions(
    fields::CrossFieldResult &crossField) {
  if (crossField.primaryDirections.rows() != crossField.rawField.rows() &&
      crossField.rawField.cols() >= 6) {
    crossField.primaryDirections =
        crossField.rawField.block(0, 0, crossField.rawField.rows(), 3);
    crossField.secondaryDirections =
        crossField.rawField.block(0, 3, crossField.rawField.rows(), 3);
  }
}

inline fields::CrossFieldResult make_surface_cell_cross_field_context(
    const Eigen::MatrixXd &rawCrossField) {
  fields::CrossFieldResult crossField;
  crossField.degree = fields::kCrossFieldDegree;
  crossField.rawField = rawCrossField;
  normalize_surface_cell_cross_field_directions(crossField);
  return crossField;
}

inline fields::CrossFieldResult finalize_surface_cell_raw_cross_field(
    const TriMesh &meshWhole, const Eigen::MatrixXd &rawCrossField) {
  if (rawCrossField.rows() != meshWhole.F.rows() ||
      rawCrossField.cols() != 3 * fields::kCrossFieldDegree) {
    throw std::invalid_argument(
        "SurfaceCells raw cross field must have shape (#F, 12).");
  }
  for (Eigen::Index face = 0; face < rawCrossField.rows(); ++face) {
    for (Eigen::Index col = 0; col < rawCrossField.cols(); ++col) {
      if (!std::isfinite(rawCrossField(face, col))) {
        throw std::invalid_argument(
            "SurfaceCells raw cross field contains a nonfinite value.");
      }
    }
    for (int branch = 0; branch < fields::kCrossFieldDegree; ++branch) {
      if (rawCrossField.block(face, 3 * branch, 1, 3).norm() <= 1.0e-12) {
        throw std::invalid_argument(
            "SurfaceCells raw cross field contains a zero-length branch.");
      }
    }
  }
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(meshWhole);

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD,
                fields::kCrossFieldDegree);
  rawField.set_extrinsic_field(rawCrossField);

  fields::CrossFieldResult crossField =
      fields::finalize_cross_field_result(rawField, false, true);
  crossField.degree = fields::kCrossFieldDegree;
  normalize_surface_cell_cross_field_directions(crossField);
  return crossField;
}
inline std::uint64_t surface_cell_source_edge_key(const int a, const int b) {
  const int lo = std::min(a, b);
  const int hi = std::max(a, b);
  return (static_cast<std::uint64_t>(static_cast<std::uint32_t>(lo)) << 32u) |
         static_cast<std::uint32_t>(hi);
}

inline bool cross_field_transitions_match_source_edges(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField) {
  if (crossField.matching.size() != meshWhole.EF.rows() ||
      crossField.effort.size() != meshWhole.EF.rows()) {
    return false;
  }
  std::set<int> seenEdges;
  for (const fields::CrossFieldEdgeTransition &transition :
       crossField.edgeTransitions) {
    if (transition.sourceEdge < 0 ||
        transition.sourceEdge >= meshWhole.EF.rows() ||
        !seenEdges.insert(transition.sourceEdge).second) {
      return false;
    }
    const int edge = transition.sourceEdge;
    if (surface_cell_source_edge_key(transition.sourceVertex0,
                                     transition.sourceVertex1) !=
        surface_cell_source_edge_key(meshWhole.EV(edge, 0),
                                     meshWhole.EV(edge, 1))) {
      return false;
    }
    if (transition.firstFace != meshWhole.EF(edge, 0) ||
        transition.secondFace != meshWhole.EF(edge, 1)) {
      return false;
    }
    if (transition.matching != crossField.matching(edge) ||
        !std::isfinite(transition.effort) ||
        std::abs(transition.effort - crossField.effort(edge)) > 1.0e-12) {
      return false;
    }
  }
  for (int edge = 0; edge < meshWhole.EF.rows(); ++edge) {
    if (meshWhole.EF(edge, 0) >= 0 && meshWhole.EF(edge, 1) >= 0 &&
        seenEdges.count(edge) == 0) {
      return false;
    }
  }
  return true;
}

inline int surface_cell_local_edge_index(const Eigen::MatrixXi &faces,
                                         const int face, const int a,
                                         const int b) {
  if (face < 0 || face >= faces.rows()) {
    return -1;
  }
  for (const auto &[u, v, edge] :
       {std::tuple<int, int, int>{0, 1, 2}, {1, 2, 0}, {2, 0, 1}}) {
    const int fu = faces(face, u);
    const int fv = faces(face, v);
    if ((fu == a && fv == b) || (fu == b && fv == a)) {
      return edge;
    }
  }
  return -1;
}

inline geometry::SurfaceCellRailSample make_surface_cell_rail_sample(
    const TriMesh &meshWhole, const int face, const int a, const int b,
    const double t, const double railParameter) {
  geometry::SurfaceCellRailSample sample;
  sample.sourceFace = face;
  sample.sourceEdge = surface_cell_local_edge_index(meshWhole.F, face, a, b);
  sample.parameter = t;
  sample.railParameter = railParameter;
  if (face >= 0 && face < meshWhole.F.rows()) {
    for (int corner = 0; corner < 3; ++corner) {
      if (meshWhole.F(face, corner) == a) {
        sample.barycentric[corner] = 1.0 - t;
      } else if (meshWhole.F(face, corner) == b) {
        sample.barycentric[corner] = t;
      }
    }
    sample.position = sample.barycentric[0] * meshWhole.V.row(meshWhole.F(face, 0)) +
                      sample.barycentric[1] * meshWhole.V.row(meshWhole.F(face, 1)) +
                      sample.barycentric[2] * meshWhole.V.row(meshWhole.F(face, 2));
  }
  return sample;
}

inline bool surface_cell_feature_edge_is_rail(
    const geometry::AdaptiveFeatureEdge &edge) {
  return edge.edgeClass == geometry::AdaptiveFeatureClass::Boundary ||
         edge.edgeClass == geometry::AdaptiveFeatureClass::Hard;
}

struct SurfaceCellRailBuildResult {
  bool success = true;
  std::vector<geometry::SurfaceCellRail> rails;
  int failedEdgeIndex = -1;
  int failedRailId = -1;
  int failedIntervalIndex = -1;
  geometry::surface_cell_tracing_detail::RailBuildStatus validationStatus =
      geometry::surface_cell_tracing_detail::RailBuildStatus::Valid;
};

inline SurfaceCellRailBuildResult build_authoritative_surface_cell_rails(
    const TriMesh &meshWhole, const geometry::AdaptiveFeatureMap &featureMap) {
  SurfaceCellRailBuildResult result;
  std::set<int> coveredEdges;
  const auto fail_edge = [&](const int edgeIndex) {
    result.success = false;
    result.failedEdgeIndex = edgeIndex;
    result.rails.clear();
    return false;
  };
  const auto append_edge_interval = [&](geometry::SurfaceCellRail &rail,
                                        const geometry::AdaptiveFeatureEdge &edge,
                                        const int edgeIndex, const int a,
                                        const int b, const double t0,
                                        const double t1) {
    int face = -1;
    for (const int incidentFace : edge.incidentFaces) {
      if (incidentFace >= 0 && incidentFace < meshWhole.F.rows()) {
        face = incidentFace;
        break;
      }
    }
    if (face < 0 || a < 0 || b < 0 || a >= meshWhole.V.rows() ||
        b >= meshWhole.V.rows() || a == b) {
      return fail_edge(edgeIndex);
    }
    bool hasA = false;
    bool hasB = false;
    for (int corner = 0; corner < 3; ++corner) {
      hasA = hasA || meshWhole.F(face, corner) == a;
      hasB = hasB || meshWhole.F(face, corner) == b;
    }
    if (!hasA || !hasB) {
      return fail_edge(edgeIndex);
    }
    const geometry::SurfaceCellRailSample startSample =
        make_surface_cell_rail_sample(meshWhole, face, a, b, 0.0, t0);
    const geometry::SurfaceCellRailSample endSample =
        make_surface_cell_rail_sample(meshWhole, face, a, b, 1.0, t1);
    if (startSample.sourceEdge < 0 || endSample.sourceEdge < 0) {
      return fail_edge(edgeIndex);
    }
    rail.samples.push_back(startSample);
    rail.samples.push_back(endSample);
    return true;
  };

  struct OrderedCurveEdge {
    int edgeIndex = -1;
    int startVertex = -1;
    int endVertex = -1;
    bool isRail = false;
    geometry::SurfaceCellRailKind kind =
        geometry::SurfaceCellRailKind::Boundary;
  };

  const auto emit_run = [&](const geometry::AdaptiveFeatureCurve &curve,
                            const std::vector<OrderedCurveEdge> &ordered,
                            const std::vector<int> &run,
                            const bool closed) {
    if (run.empty()) {
      return true;
    }
    geometry::SurfaceCellRail rail;
    rail.id = static_cast<int>(result.rails.size());
    rail.kind = ordered[static_cast<std::size_t>(run.front())].kind;
    rail.curveId = curve.id;
    rail.component = curve.component;
    rail.closed = closed;
    rail.sourceVertices.push_back(
        ordered[static_cast<std::size_t>(run.front())].startVertex);
    for (int localIndex = 0; localIndex < static_cast<int>(run.size());
         ++localIndex) {
      const OrderedCurveEdge &entry =
          ordered[static_cast<std::size_t>(run[static_cast<std::size_t>(localIndex)])];
      if (entry.kind != rail.kind || !entry.isRail ||
          rail.sourceVertices.back() != entry.startVertex) {
        return fail_edge(entry.edgeIndex);
      }
      const geometry::AdaptiveFeatureEdge &edge =
          featureMap.edges[static_cast<std::size_t>(entry.edgeIndex)];
      const double t0 = static_cast<double>(localIndex) /
                        static_cast<double>(run.size());
      const double t1 = static_cast<double>(localIndex + 1) /
                        static_cast<double>(run.size());
      if (!append_edge_interval(rail, edge, entry.edgeIndex, entry.startVertex,
                                entry.endVertex, t0, t1)) {
        return false;
      }
      rail.sourceEdges.push_back(entry.edgeIndex);
      rail.sourceVertices.push_back(entry.endVertex);
      coveredEdges.insert(entry.edgeIndex);
    }
    if (closed) {
      if (rail.sourceVertices.front() != rail.sourceVertices.back()) {
        return fail_edge(rail.sourceEdges.back());
      }
      rail.sourceVertices.pop_back();
    }
    result.rails.push_back(std::move(rail));
    return true;
  };

  for (const geometry::AdaptiveFeatureCurve &curve : featureMap.curves) {
    const int edgeCount = static_cast<int>(curve.edges.size());
    if (edgeCount == 0) {
      continue;
    }
    const bool hasExplicitClosingVertex =
        curve.vertices.size() == static_cast<std::size_t>(edgeCount + 1);
    const bool hasImplicitClosingVertex =
        curve.closed &&
        curve.vertices.size() == static_cast<std::size_t>(edgeCount);
    if (!hasExplicitClosingVertex && !hasImplicitClosingVertex) {
      fail_edge(curve.edges.front());
      return result;
    }

    std::vector<OrderedCurveEdge> ordered;
    ordered.reserve(static_cast<std::size_t>(edgeCount));
    for (int index = 0; index < edgeCount; ++index) {
      const int edgeIndex = curve.edges[static_cast<std::size_t>(index)];
      if (edgeIndex < 0 ||
          edgeIndex >= static_cast<int>(featureMap.edges.size())) {
        fail_edge(edgeIndex);
        return result;
      }
      const geometry::AdaptiveFeatureEdge &edge =
          featureMap.edges[static_cast<std::size_t>(edgeIndex)];
      const int a = curve.vertices[static_cast<std::size_t>(index)];
      const int b = hasExplicitClosingVertex
                        ? curve.vertices[static_cast<std::size_t>(index + 1)]
                        : curve.vertices[static_cast<std::size_t>(
                              (index + 1) % edgeCount)];
      if (geometry::AdaptiveFeatureMap::canonical_edge(a, b) !=
          geometry::AdaptiveFeatureMap::canonical_edge(edge.vertices.first,
                                                       edge.vertices.second)) {
        fail_edge(edgeIndex);
        return result;
      }
      OrderedCurveEdge entry;
      entry.edgeIndex = edgeIndex;
      entry.startVertex = a;
      entry.endVertex = b;
      entry.isRail = surface_cell_feature_edge_is_rail(edge);
      entry.kind = edge.edgeClass == geometry::AdaptiveFeatureClass::Hard
                       ? geometry::SurfaceCellRailKind::HardFeature
                       : geometry::SurfaceCellRailKind::Boundary;
      ordered.push_back(entry);
    }

    const bool allRail = std::all_of(
        ordered.begin(), ordered.end(),
        [](const OrderedCurveEdge &entry) { return entry.isRail; });
    const bool oneKind = allRail &&
                         std::all_of(ordered.begin() + 1, ordered.end(),
                                     [&](const OrderedCurveEdge &entry) {
                                       return entry.kind == ordered.front().kind;
                                     });
    if (curve.closed && allRail && oneKind) {
      std::vector<int> run(static_cast<std::size_t>(edgeCount));
      std::iota(run.begin(), run.end(), 0);
      if (!emit_run(curve, ordered, run, true)) {
        return result;
      }
      continue;
    }

    int startIndex = 0;
    if (curve.closed) {
      for (int index = 0; index < edgeCount; ++index) {
        const int previous = (index + edgeCount - 1) % edgeCount;
        if (!ordered[static_cast<std::size_t>(index)].isRail ||
            !ordered[static_cast<std::size_t>(previous)].isRail ||
            ordered[static_cast<std::size_t>(index)].kind !=
                ordered[static_cast<std::size_t>(previous)].kind) {
          startIndex = index;
          break;
        }
      }
    }

    int processed = 0;
    int index = startIndex;
    while (processed < edgeCount) {
      const OrderedCurveEdge &entry =
          ordered[static_cast<std::size_t>(index)];
      if (!entry.isRail) {
        index = (index + 1) % edgeCount;
        ++processed;
        continue;
      }
      const geometry::SurfaceCellRailKind kind = entry.kind;
      std::vector<int> run;
      while (processed < edgeCount) {
        const OrderedCurveEdge &candidate =
            ordered[static_cast<std::size_t>(index)];
        if (!candidate.isRail || candidate.kind != kind) {
          break;
        }
        run.push_back(index);
        index = (index + 1) % edgeCount;
        ++processed;
      }
      if (!emit_run(curve, ordered, run, false)) {
        return result;
      }
    }
  }

  for (int edgeIndex = 0;
       edgeIndex < static_cast<int>(featureMap.edges.size()); ++edgeIndex) {
    if (coveredEdges.count(edgeIndex) != 0) {
      continue;
    }
    const geometry::AdaptiveFeatureEdge &edge =
        featureMap.edges[static_cast<std::size_t>(edgeIndex)];
    if (!surface_cell_feature_edge_is_rail(edge)) {
      continue;
    }
    geometry::SurfaceCellRail rail;
    rail.id = static_cast<int>(result.rails.size());
    rail.kind = edge.edgeClass == geometry::AdaptiveFeatureClass::Hard
                    ? geometry::SurfaceCellRailKind::HardFeature
                    : geometry::SurfaceCellRailKind::Boundary;
    rail.curveId = edge.curve;
    rail.component = edge.component;
    rail.closed = false;
    rail.sourceVertices = {edge.vertices.first, edge.vertices.second};
    rail.sourceEdges = {edgeIndex};
    if (!append_edge_interval(rail, edge, edgeIndex, edge.vertices.first,
                              edge.vertices.second, 0.0, 1.0)) {
      return result;
    }
    result.rails.push_back(std::move(rail));
  }

  const auto railValidation =
      geometry::surface_cell_tracing_detail::rail_interval_refs(
          result.rails, meshWhole.V, meshWhole.F,
          geometry::surface_cell_tracing_detail::edge_faces(meshWhole.F));
  if (railValidation.status !=
      geometry::surface_cell_tracing_detail::RailBuildStatus::Valid) {
    result.success = false;
    result.validationStatus = railValidation.status;
    result.failedRailId = railValidation.railId;
    result.failedIntervalIndex = railValidation.intervalIndex;
    if (railValidation.railId >= 0 &&
        railValidation.railId < static_cast<int>(result.rails.size()) &&
        railValidation.intervalIndex >= 0 &&
        railValidation.intervalIndex < static_cast<int>(
            result.rails[static_cast<std::size_t>(railValidation.railId)]
                .sourceEdges.size())) {
      result.failedEdgeIndex =
          result.rails[static_cast<std::size_t>(railValidation.railId)]
              .sourceEdges[static_cast<std::size_t>(
                  railValidation.intervalIndex)];
    }
    result.rails.clear();
  }
  return result;
}

inline std::set<std::uint64_t> relief_barrier_edges_from_topology(
    const geometry::ReliefTopologyResult &topology) {
  std::set<std::uint64_t> barriers;
  for (const geometry::ReliefBranch &branch : topology.branches) {
    for (int index = 0; index + 1 < static_cast<int>(branch.vertices.size());
         ++index) {
      barriers.insert(surface_cell_source_edge_key(
          branch.vertices[static_cast<std::size_t>(index)],
          branch.vertices[static_cast<std::size_t>(index + 1)]));
    }
  }
  return barriers;
}

inline std::uint64_t hash_relief_operational_inputs(
    const geometry::ReliefRootSelectionResult &roots,
    const std::set<std::uint64_t> &barriers) {
  std::uint64_t seed = structural_hash_seed("relief-consumption");
  hash_vector(seed, roots.roots);
  hash_vector(seed, roots.labels);
  hash_matrix(seed, roots.targets);
  hash_combine_u64(seed, barriers.size());
  for (const std::uint64_t barrier : barriers) {
    hash_combine_u64(seed, barrier);
  }
  return seed;
}
inline std::set<std::uint64_t> hard_feature_edge_keys_from_rails(
    const std::vector<geometry::SurfaceCellRail> &rails) {
  std::set<std::uint64_t> keys;
  for (const geometry::SurfaceCellRail &rail : rails) {
    if (rail.kind != geometry::SurfaceCellRailKind::HardFeature) {
      continue;
    }
    for (int index = 0; index + 1 < static_cast<int>(rail.sourceVertices.size());
         ++index) {
      keys.insert(surface_cell_source_edge_key(
          rail.sourceVertices[static_cast<std::size_t>(index)],
          rail.sourceVertices[static_cast<std::size_t>(index + 1)]));
    }
    if (rail.closed && rail.sourceVertices.size() > 1U &&
        rail.sourceVertices.back() != rail.sourceVertices.front()) {
      keys.insert(surface_cell_source_edge_key(rail.sourceVertices.back(),
                                               rail.sourceVertices.front()));
    }
  }
  return keys;
}

inline void fill_surface_cell_rail_constraints(
    const std::vector<geometry::SurfaceCellRail> &rails,
    geometry::SurfaceOptimizationConstraints &constraints) {
  std::vector<int> firstClosedBoundaryLoop;
  for (const geometry::SurfaceCellRail &rail : rails) {
    if (rail.samples.size() >= 2U) {
      geometry::SurfaceFeatureCurveInterval interval;
      interval.curveId = rail.curveId >= 0 ? rail.curveId : rail.id;
      interval.start = rail.samples.front().position;
      interval.end = rail.samples.back().position;
      constraints.featureCurveIntervals.push_back(interval);
      constraints.featureIntervals.push_back({interval.start, interval.end});
    }
    if (rail.kind != geometry::SurfaceCellRailKind::Boundary) {
      continue;
    }
    for (int index = 0; index + 1 < static_cast<int>(rail.sourceVertices.size());
         ++index) {
      const int a = rail.sourceVertices[static_cast<std::size_t>(index)];
      const int b = rail.sourceVertices[static_cast<std::size_t>(index + 1)];
      constraints.authoritativeBoundaryEdges.insert({std::min(a, b), std::max(a, b)});
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
}

inline std::uint64_t hash_surface_cell_rails(
    const std::vector<geometry::SurfaceCellRail> &rails) {
  std::uint64_t seed = structural_hash_seed("rails");
  hash_combine_u64(seed, rails.size());
  for (const geometry::SurfaceCellRail &rail : rails) {
    hash_combine_i64(seed, rail.id);
    hash_combine_i64(seed, static_cast<int>(rail.kind));
    hash_combine_i64(seed, rail.curveId);
    hash_combine_i64(seed, rail.component);
    hash_combine_i64(seed, rail.closed ? 1 : 0);
    hash_vector(seed, rail.sourceVertices);
    hash_vector(seed, rail.sourceEdges);
    hash_combine_u64(seed, rail.samples.size());
    for (const geometry::SurfaceCellRailSample &sample : rail.samples) {
      hash_combine_i64(seed, sample.sourceFace);
      hash_combine_i64(seed, sample.sourceEdge);
      hash_combine_double(seed, sample.parameter);
      hash_combine_double(seed, sample.railParameter);
      hash_row_vector(seed, sample.barycentric);
      hash_row_vector(seed, sample.position);
    }
  }
  return seed;
}
inline void record_surface_cell_context_product(
    SurfaceCellPipelineContext &context, const std::string &name,
    const SurfaceCellObjectIdentity &identity, const bool available = true) {
  SurfaceCellContextProductDebug product;
  product.name = name;
  product.type = identity.type;
  product.structuralHash = identity.structuralHash;
  product.elementCount = identity.elementCount;
  product.available = available;
  context.debugProducts.push_back(product);
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
    arrangementArc.railId = arc.railId;
    arrangementArc.curveId = arc.curveId;
    arrangementArc.sourceComponent = arc.sourceComponent;
    arrangementArc.sourceSheet = arc.sourceSheet;
    arrangementArc.proposalId = arc.proposalId;
    arrangementArc.proposalSeedId = arc.proposalSeedId;
    arrangementArc.proposalSide = arc.proposalSide;
    arrangementArc.proposalBoundarySegment = arc.proposalBoundarySegment;
    arrangementArc.railT0 = arc.railT0;
    arrangementArc.railT1 = arc.railT1;
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
                                 const RemeshOptions &options = {},
                                 const fields::CrossFieldResult *authoritativeCrossField = nullptr) {
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
    result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
    result.surfaceCellContext.sourceMesh = meshWhole;
    result.surfaceCellContext.hasSourceMesh = true;
    if (authoritativeCrossField != nullptr) {
      result.surfaceCellContext.crossField = *authoritativeCrossField;
    } else {
      try {
        result.surfaceCellContext.crossField =
            finalize_surface_cell_raw_cross_field(meshWhole, rawCrossField);
      } catch (const std::invalid_argument &) {
        result.diagnostics.terminalFailureCode =
            surface_cell_failure_code_name(
                SurfaceCellFailureCode::InvalidFieldDimensions);
        result.diagnostics.terminalFailureStage = "cross-field-validation";
        result.diagnostics.originalSurfaceCellFailureCode =
            result.diagnostics.terminalFailureCode;
        result.diagnostics.originalSurfaceCellFailureStage =
            result.diagnostics.terminalFailureStage;
        result.diagnostics.surfaceCellValidationFailures = 1U;
        result.diagnostics.overallPipelineSeconds =
            std::chrono::duration_cast<std::chrono::microseconds>(
                Clock::now() - pipelineStart)
                .count() /
            1.0e6;
        return result;
      } catch (const std::runtime_error &) {
        result.diagnostics.terminalFailureCode =
            surface_cell_failure_code_name(
                SurfaceCellFailureCode::MissingMatching);
        result.diagnostics.terminalFailureStage = "cross-field-validation";
        result.diagnostics.originalSurfaceCellFailureCode =
            result.diagnostics.terminalFailureCode;
        result.diagnostics.originalSurfaceCellFailureStage =
            result.diagnostics.terminalFailureStage;
        result.diagnostics.surfaceCellValidationFailures = 1U;
        result.diagnostics.overallPipelineSeconds =
            std::chrono::duration_cast<std::chrono::microseconds>(
                Clock::now() - pipelineStart)
                .count() /
            1.0e6;
        return result;
      }
    }
    normalize_surface_cell_cross_field_directions(
        result.surfaceCellContext.crossField);
    result.surfaceCellContext.hasCrossField = true;
    result.surfaceCellContext.crossFieldHasMatching =
        result.surfaceCellContext.crossField.matchingComputed;
    result.surfaceCellContext.crossFieldHasSingularities =
        result.surfaceCellContext.crossField.singularitiesComputed;
    result.rawCrossField = result.surfaceCellContext.crossField.rawField;
    result.crossFieldMatching = result.surfaceCellContext.crossField.matching;
    result.crossFieldEffort = result.surfaceCellContext.crossField.effort;
    result.crossFieldSingularCycles =
        result.surfaceCellContext.crossField.singularCycles;
    result.crossFieldSingularIndices =
        result.surfaceCellContext.crossField.singularIndices;
    std::vector<std::string> completedSurfaceCellStages;
    auto make_identity = [](const std::string &type,
                            const std::uint64_t hash,
                            const std::size_t count) {
      return make_surface_cell_identity(type, hash, count);
    };
    auto record_surface_cell_stage = [&](const std::string &stage,
                                         const SurfaceCellObjectIdentity &input,
                                         const SurfaceCellObjectIdentity &output,
                                         const bool available,
                                         const double durationSeconds) {
      SurfaceCellStageLineage lineage;
      lineage.stage = stage;
      lineage.inputObject = input;
      lineage.outputObject = output;
      lineage.inputObjectHash = surface_cell_identity_label(input);
      lineage.outputObjectHash = surface_cell_identity_label(output);
      lineage.objectCount = output.elementCount;
      lineage.available = available;
      lineage.noOp = input.structuralHash == output.structuralHash &&
                     input.type == output.type;
      lineage.durationSeconds = durationSeconds;
      result.diagnostics.surfaceCellStageLineage.push_back(lineage);
      record_surface_cell_context_product(result.surfaceCellContext, stage,
                                          output, available);
    };
    auto mark_stage_consumed = [&](const std::string &stage,
                                   const SurfaceCellObjectIdentity &identity,
                                   const SurfaceCellConsumptionKind kind) {
      for (SurfaceCellStageLineage &lineage :
           result.diagnostics.surfaceCellStageLineage) {
        if (lineage.stage != stage) {
          continue;
        }
        const bool identityMatches =
            lineage.outputObject.structuralHash == identity.structuralHash &&
            lineage.outputObject.type == identity.type;
        lineage.consumedByNextStage =
            identityMatches && kind != SurfaceCellConsumptionKind::None &&
            kind != SurfaceCellConsumptionKind::Discontinuous;
        lineage.consumptionKind = identityMatches
                                      ? kind
                                      : SurfaceCellConsumptionKind::Discontinuous;
        return;
      }
    };
    std::uint64_t sourceHash = structural_hash_seed("source");
    hash_matrix(sourceHash, meshWhole.V);
    hash_matrix(sourceHash, meshWhole.F);
    const SurfaceCellObjectIdentity sourceIdentity = make_identity(
        "source", sourceHash, static_cast<std::size_t>(meshWhole.F.rows()));
    record_surface_cell_context_product(result.surfaceCellContext, "source",
                                        sourceIdentity, true);
    std::uint64_t crossFieldHash = structural_hash_seed("cross-field");
    hash_matrix(crossFieldHash, result.surfaceCellContext.crossField.rawField);
    hash_vector(crossFieldHash, result.surfaceCellContext.crossField.matching);
    hash_vector(crossFieldHash, result.surfaceCellContext.crossField.effort);
    hash_combine_u64(
        crossFieldHash,
        result.surfaceCellContext.crossField.edgeTransitions.size());
    for (const fields::CrossFieldEdgeTransition &transition :
         result.surfaceCellContext.crossField.edgeTransitions) {
      hash_combine_i64(crossFieldHash, transition.sourceEdge);
      hash_combine_i64(crossFieldHash, transition.sourceVertex0);
      hash_combine_i64(crossFieldHash, transition.sourceVertex1);
      hash_combine_i64(crossFieldHash, transition.firstFace);
      hash_combine_i64(crossFieldHash, transition.secondFace);
      hash_combine_i64(crossFieldHash, transition.matching);
      hash_combine_double(crossFieldHash, transition.effort);
    }
    hash_vector(crossFieldHash,
                result.surfaceCellContext.crossField.singularCycles);
    hash_vector(crossFieldHash,
                result.surfaceCellContext.crossField.singularIndices);
    hash_vector(crossFieldHash, result.surfaceCellContext.crossField.confidence);
    hash_vector(crossFieldHash,
                result.surfaceCellContext.crossField.uncoveredFaces);
    hash_combine_i64(crossFieldHash,
                     result.surfaceCellContext.crossField.matchingComputed ? 1 : 0);
    hash_combine_i64(
        crossFieldHash,
        result.surfaceCellContext.crossField.singularitiesComputed ? 1 : 0);
    hash_combine_i64(crossFieldHash,
                     result.surfaceCellContext.crossField.confidenceComputed ? 1 : 0);
    hash_combine_i64(
        crossFieldHash,
        result.surfaceCellContext.crossField.uncoveredFacePolicyApplied ? 1 : 0);
    record_surface_cell_context_product(
        result.surfaceCellContext, "cross-field",
        make_identity("cross-field", crossFieldHash,
                      static_cast<std::size_t>(
                          result.surfaceCellContext.crossField.rawField.rows())),
        result.surfaceCellContext.hasCrossField);
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
      result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
      result.diagnostics.surfaceCellRemeshOccurred = false;
      if (!result.diagnostics.surfaceCellStageLineage.empty()) {
        SurfaceCellStageLineage &lineage =
            result.diagnostics.surfaceCellStageLineage.back();
        if (lineage.stage == stage) {
          lineage.terminalFailureCode = failureCode;
          lineage.terminalFailureStage = stage;
          lineage.consumedByNextStage = false;
          lineage.consumptionKind = SurfaceCellConsumptionKind::None;
        }
      }
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
        result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::InputMeshFallback;
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
          legacyResult.diagnostics.surfaceCellStageLineage =
              result.diagnostics.surfaceCellStageLineage;
          legacyResult.surfaceCellContext = result.surfaceCellContext;
          legacyResult.diagnostics.surfaceCellOutputOrigin =
              legacyResult.success ? SurfaceCellOutputOrigin::LegacyFallback : SurfaceCellOutputOrigin::None;
          if (!legacyResult.success) {
            legacyResult.diagnostics.terminalFailureCode = failureCode;
            legacyResult.diagnostics.terminalFailureStage = stage;
          }
          legacyResult.diagnostics.surfaceCellRemeshOccurred = false;
          result = legacyResult;
        }
      }
      return result;
    };

    if (result.surfaceCellContext.crossField.degree != fields::kCrossFieldDegree ||
        result.surfaceCellContext.crossField.rawField.rows() != meshWhole.F.rows() ||
        result.surfaceCellContext.crossField.rawField.cols() != 12 ||
        result.surfaceCellContext.crossField.primaryDirections.rows() !=
            meshWhole.F.rows() ||
        result.surfaceCellContext.crossField.secondaryDirections.rows() !=
            meshWhole.F.rows()) {
      return fail_surface_cells(SurfaceCellFailureCode::InvalidFieldDimensions,
                                "cross-field-validation");
    }
    if (options.surfaceCells.requireMatching &&
        (!result.surfaceCellContext.crossField.matchingComputed ||
         result.surfaceCellContext.crossField.matching.size() == 0 ||
         result.surfaceCellContext.crossField.effort.size() !=
             result.surfaceCellContext.crossField.matching.size() ||
         !cross_field_transitions_match_source_edges(
             meshWhole, result.surfaceCellContext.crossField))) {
      return fail_surface_cells(SurfaceCellFailureCode::MissingMatching,
                                "cross-field-validation");
    }
    if (options.surfaceCells.requireSingularities &&
        !result.surfaceCellContext.crossField.singularitiesComputed) {
      return fail_surface_cells(SurfaceCellFailureCode::MissingSingularities,
                                "cross-field-validation");
    }
    if (!result.surfaceCellContext.crossField.confidenceComputed ||
        result.surfaceCellContext.crossField.confidence.rows() != meshWhole.F.rows()) {
      return fail_surface_cells(SurfaceCellFailureCode::MissingConfidence,
                                "cross-field-validation");
    }
    if (!result.surfaceCellContext.crossField.uncoveredFacePolicyApplied ||
        result.surfaceCellContext.crossField.uncoveredFaces.size() > 0) {
      return fail_surface_cells(SurfaceCellFailureCode::UncoveredFaces,
                                "cross-field-validation");
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
    result.surfaceCellContext.featureMap = featureMap;
    result.surfaceCellContext.hasFeatureMap = true;
    const std::uint64_t featureHash = hash_feature_map(featureMap);
    const SurfaceCellObjectIdentity featureIdentity = make_identity(
        "feature", featureHash, featureMap.edges.size());
    record_surface_cell_stage("feature", sourceIdentity, featureIdentity, true,
                              result.diagnostics.surfaceCellFeatureSeconds);
    completedSurfaceCellStages.push_back("feature");
    const SurfaceCellRailBuildResult railBuild =
        build_authoritative_surface_cell_rails(meshWhole, featureMap);
    if (!railBuild.success) {
      return fail_surface_cells(SurfaceCellFailureCode::InvalidRailTopology,
                                "feature");
    }
    const std::vector<geometry::SurfaceCellRail> &authoritativeRails =
        railBuild.rails;
    const std::set<std::uint64_t> hardFeatureRailEdges =
        hard_feature_edge_keys_from_rails(authoritativeRails);
    result.surfaceCellContext.authoritativeRails = authoritativeRails;
    result.surfaceCellContext.hasAuthoritativeRails = true;
    const SurfaceCellObjectIdentity railsIdentity = make_identity(
        "rails", hash_surface_cell_rails(authoritativeRails),
        authoritativeRails.size());
    record_surface_cell_context_product(result.surfaceCellContext, "rails",
                                        railsIdentity, true);
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
    result.surfaceCellContext.metricField = targetSize;
    result.surfaceCellContext.hasMetricField = true;
    std::uint64_t metricHash = structural_hash_seed("metric");
    hash_combine_u64(metricHash, featureIdentity.structuralHash);
    hash_vector(metricHash, targetSize.targetSize);
    hash_vector(metricHash, targetSize.normalizedSalience);
    const SurfaceCellObjectIdentity metricIdentity = make_identity(
        "metric", metricHash, result.diagnostics.surfaceCellMetricSampleCount);
    mark_stage_consumed("feature", featureIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("metric", featureIdentity, metricIdentity, true,
                              result.diagnostics.surfaceCellMetricSeconds);
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
    const geometry::ReliefOptions reliefOptions = options.surfaceCells.relief;
    const Eigen::VectorXd reliefValues =
        geometry::compute_salience_relief(reliefInput, reliefOptions);
    const geometry::ReliefTopologyResult reliefTopology =
        geometry::analyze_relief_topology(meshWhole.V, meshWhole.F, reliefValues,
                                          hardFeatureRailEdges, reliefOptions);
    const std::set<std::uint64_t> reliefBarrierEdges =
        relief_barrier_edges_from_topology(reliefTopology);
    std::set<std::uint64_t> operationalBarrierEdges = hardFeatureRailEdges;
    operationalBarrierEdges.insert(reliefBarrierEdges.begin(),
                                   reliefBarrierEdges.end());
    geometry::ReliefRootSelectionOptions reliefRootOptions =
        options.surfaceCells.reliefRoots;
    reliefRootOptions.hardBarrierEdges = operationalBarrierEdges;
    const geometry::ReliefRootSelectionResult reliefRootSelection =
        geometry::select_relief_roots(meshWhole.V, meshWhole.F, reliefTopology,
                                      targetSize.targetSize, reliefRootOptions);
    result.diagnostics.surfaceCellReliefSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - reliefStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellReliefPatchCount =
        reliefTopology.branches.size();
    result.diagnostics.surfaceCellReliefCountAvailable = true;
    result.surfaceCellContext.reliefResult = reliefTopology;
    result.surfaceCellContext.hasReliefResult = true;
    result.surfaceCellContext.reliefRootSelection = reliefRootSelection;
    result.surfaceCellContext.hasReliefRootSelection = true;
    result.surfaceCellContext.reliefBarrierEdges = reliefBarrierEdges;
    result.surfaceCellContext.hasReliefBarrierEdges = true;
    const std::uint64_t reliefHash = hash_relief_topology(reliefTopology);
    const SurfaceCellObjectIdentity reliefIdentity = make_identity(
        "relief", reliefHash, result.diagnostics.surfaceCellReliefPatchCount);
    mark_stage_consumed("metric", metricIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("relief", metricIdentity, reliefIdentity, true,
                              result.diagnostics.surfaceCellReliefSeconds);
    const SurfaceCellObjectIdentity reliefConsumptionIdentity = make_identity(
        "relief-consumption",
        hash_relief_operational_inputs(reliefRootSelection, reliefBarrierEdges),
        reliefRootSelection.roots.size() + reliefBarrierEdges.size());
    record_surface_cell_context_product(result.surfaceCellContext,
                                        "relief-consumption",
                                        reliefConsumptionIdentity, true);
    completedSurfaceCellStages.push_back("relief");
    if (options.surfaceCells.injectFailureAfterStage == 2) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "relief");
    }

    const auto tracingStart = Clock::now();
    const Eigen::MatrixXd &faceAxisX =
        result.surfaceCellContext.crossField.primaryDirections;
    const Eigen::MatrixXd &faceAxisY =
        result.surfaceCellContext.crossField.secondaryDirections;
    geometry::SurfaceCellTracingOptions tracingOptions;
    tracingOptions.authoritativeRails = authoritativeRails;
    tracingOptions.hardFeatureEdges = hardFeatureRailEdges;
    tracingOptions.reliefRootVertices = reliefRootSelection.roots;
    tracingOptions.reliefRegionLabels = reliefRootSelection.labels;
    tracingOptions.reliefBarrierEdges = reliefBarrierEdges;
    const geometry::SourceSurfaceLabels sourceSurfaceLabels =
        geometry::surface_cell_tracing_detail::classify_source_surface_labels(
            meshWhole.V, meshWhole.F, hardFeatureRailEdges);
    result.surfaceCellContext.sourceSurfaceLabels = sourceSurfaceLabels;
    result.surfaceCellContext.hasSourceSurfaceLabels = true;
    std::uint64_t sourceLabelHash = structural_hash_seed("source-labels");
    hash_vector(sourceLabelHash, sourceSurfaceLabels.componentByFace);
    hash_vector(sourceLabelHash, sourceSurfaceLabels.localSheetByFace);
    record_surface_cell_context_product(
        result.surfaceCellContext, "source-labels",
        make_identity("source-labels", sourceLabelHash,
                      sourceSurfaceLabels.localSheetByFace.size()),
        true);
    tracingOptions.sourceFaceComponents = sourceSurfaceLabels.componentByFace;
    tracingOptions.sourceFaceSheets = sourceSurfaceLabels.localSheetByFace;
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
        geometry::build_surface_cell_network(
            meshWhole.V, meshWhole.F, result.surfaceCellContext.crossField,
            targetSize.targetSize, tracingOptions);
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
    result.surfaceCellContext.traceNetwork = traceNetwork;
    result.surfaceCellContext.hasTraceNetwork = true;
    const std::uint64_t tracingHash = hash_trace_network(traceNetwork);
    const SurfaceCellObjectIdentity tracingIdentity = make_identity(
        "tracing", tracingHash, result.diagnostics.surfaceCellTraceSegmentCount);
    mark_stage_consumed("relief", reliefIdentity,
                        SurfaceCellConsumptionKind::Partial);
    record_surface_cell_stage("tracing", reliefIdentity, tracingIdentity, true,
                              result.diagnostics.surfaceCellTracingSeconds);
    completedSurfaceCellStages.push_back("tracing");
    if (options.surfaceCells.injectFailureAfterStage == 3) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "tracing");
    }

    const auto strandsStart = Clock::now();
    const geometry::FlowRepSelectionInput flowRepInput =
        geometry::build_flow_rep_selection_input(
            meshWhole.V, meshWhole.F, targetSize.targetSize, traceNetwork,
            tracingOptions.defaultTargetSize);
    const std::vector<geometry::FlowRepArc> &flowRepArcs = flowRepInput.arcs;
    const geometry::FlowRepSparseNetwork sparseFlowRep =
        geometry::select_sparse_flow_rep_network(
            flowRepArcs, flowRepInput.coverageSamples, flowRepInput.cycles);
    const double surfaceCellStrandsSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - strandsStart)
            .count() /
        1.0e6;
    result.surfaceCellContext.flowRepArcs = flowRepArcs;
    result.surfaceCellContext.flowRepNetwork = sparseFlowRep;
    result.surfaceCellContext.hasFlowRepNetwork = true;
    std::uint64_t strandsHash = hash_sparse_network(sparseFlowRep);
    hash_combine_u64(strandsHash,
                     hash_flow_rep_selection_input(flowRepInput));
    const SurfaceCellObjectIdentity strandsIdentity = make_identity(
        "strands", strandsHash, sparseFlowRep.retainedArcIds.size());
    mark_stage_consumed("tracing", tracingIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("strands", tracingIdentity, strandsIdentity,
                              sparseFlowRep.selectionSucceeded,
                              surfaceCellStrandsSeconds);
    if (!sparseFlowRep.selectionSucceeded) {
      return fail_surface_cells(
          surface_cell_failure_from_flow_rep(sparseFlowRep.failureCode),
          "strands");
    }
    completedSurfaceCellStages.push_back("strands");
    if (options.surfaceCells.injectFailureAfterStage == 4) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "strands");
    }

    const auto embeddingStart = Clock::now();
    const std::vector<geometry::SurfaceArrangementArc> arrangementArcs =
        surface_arrangement_arcs_from_flow_rep(flowRepArcs, sparseFlowRep);
    const double surfaceCellEmbeddingSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - embeddingStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount = arrangementArcs.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    result.surfaceCellContext.embeddedArrangementArcs = arrangementArcs;
    result.surfaceCellContext.hasEmbeddedArrangementArcs = true;
    const SurfaceCellObjectIdentity retainedNetworkIdentity = make_identity(
        "embedded-network", hash_arrangement_arcs(arrangementArcs),
        arrangementArcs.size());
    mark_stage_consumed("strands", strandsIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("embedding", strandsIdentity,
                              retainedNetworkIdentity, true,
                              surfaceCellEmbeddingSeconds);
    completedSurfaceCellStages.push_back("embedding");
    if (options.surfaceCells.injectFailureAfterStage == 5) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "embedding");
    }

    const auto arrangementStart = Clock::now();
    geometry::SurfaceArrangementOptions arrangementOptions;
    arrangementOptions.insertBoundaryRails = authoritativeRails.empty();
    arrangementOptions.hardFeatureEdges = hardFeatureRailEdges;
    const geometry::SurfaceCellComplex arrangementComplex =
        geometry::build_surface_cell_complex(meshWhole.V, meshWhole.F,
                                             arrangementArcs, arrangementOptions);
    result.diagnostics.surfaceCellArrangementSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - arrangementStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount =
        arrangementComplex.cells.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    result.surfaceCellContext.arrangement = arrangementComplex;
    result.surfaceCellContext.hasArrangement = true;
    const std::uint64_t arrangementHash = hash_surface_complex(arrangementComplex);
    const SurfaceCellObjectIdentity arrangementIdentity = make_identity(
        "arrangement", arrangementHash,
        result.diagnostics.surfaceCellArrangementCellCount);
    mark_stage_consumed("embedding", retainedNetworkIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("arrangement", retainedNetworkIdentity,
                              arrangementIdentity, true,
                              result.diagnostics.surfaceCellArrangementSeconds);
    completedSurfaceCellStages.push_back("arrangement");
    if (options.surfaceCells.injectFailureAfterStage == 6) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "arrangement");
    }

    const auto simplificationStart = Clock::now();
    const geometry::SurfaceSimplificationCandidateSet simplificationCandidates =
        geometry::extract_surface_simplification_candidates(
            arrangementComplex, meshWhole.V, meshWhole.F);
    const geometry::SurfaceSimplificationResult simplified =
        geometry::simplify_surface_cell_complex(
            arrangementComplex, meshWhole.V, meshWhole.F,
            simplificationCandidates.candidates);
    result.diagnostics.surfaceCellSimplificationSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - simplificationStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellSimplifiedCellCount =
        simplified.hasComplexOutput ? simplified.complex.cells.size() : 0U;
    result.diagnostics.surfaceCellSimplifiedCountAvailable = true;
    const geometry::SurfaceCellComplex &simplifiedComplexForHash =
        simplified.hasComplexOutput ? simplified.complex : arrangementComplex;
    result.surfaceCellContext.simplifiedComplex = simplifiedComplexForHash;
    result.surfaceCellContext.hasSimplifiedComplex = true;
    const std::uint64_t simplificationHash =
        hash_surface_complex(simplifiedComplexForHash);
    const SurfaceCellObjectIdentity simplificationIdentity = make_identity(
        "arrangement", simplificationHash,
        result.diagnostics.surfaceCellSimplifiedCellCount);
    mark_stage_consumed("arrangement", arrangementIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("simplification", arrangementIdentity,
                              simplificationIdentity, true,
                              result.diagnostics.surfaceCellSimplificationSeconds);
    completedSurfaceCellStages.push_back("simplification");
    if (options.surfaceCells.injectFailureAfterStage == 7) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "simplification");
    }

    const auto completionStart = Clock::now();
    std::size_t completedQuadCount = 0U;
    Eigen::MatrixXd completedVertices;
    Eigen::MatrixXi completedQuads;
    std::vector<geometry::SurfacePoint> completedProvenance;
    std::vector<geometry::PureQuadVertexLineage> completedVertexLineage;
    std::vector<geometry::PureQuadFaceLineage> completedQuadLineage;
    const geometry::SurfaceCellComplex &completionComplex =
        simplified.hasComplexOutput ? simplified.complex : arrangementComplex;
    geometry::PatchDescriptorOptions patchDescriptorOptions;
    patchDescriptorOptions.singularCycles =
        result.surfaceCellContext.crossField.singularCycles;
    patchDescriptorOptions.singularIndices =
        result.surfaceCellContext.crossField.singularIndices;
    geometry::PatchDescriptorSet patchDescriptors =
        geometry::derive_patch_descriptors(completionComplex, meshWhole.V,
                                           meshWhole.F,
                                           patchDescriptorOptions);
    result.surfaceCellContext.patchDescriptors = patchDescriptors.descriptors;
    result.surfaceCellContext.hasPatchDescriptors =
        !patchDescriptors.descriptors.empty();
    for (const geometry::PatchDescriptor &descriptor :
         patchDescriptors.descriptors) {
      if (!descriptor.boundaryCycleValid ||
          !descriptor.feasibility.admissible) {
        continue;
      }
      geometry::PureQuadCompletionOptions completionOptions;
      completionOptions.sourcePatch = descriptor.cellId;
      const geometry::PureQuadCompletionResult completion =
          geometry::complete_pure_quad_patch(descriptor.patch, completionOptions);
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
      for (const geometry::PureQuadVertexLineage &localLineage :
           completion.mesh.vertexLineage) {
        geometry::PureQuadVertexLineage lineage = localLineage;
        const auto localIt = std::find(completion.mesh.vertices.begin(),
                                       completion.mesh.vertices.end(),
                                       localLineage.outputVertex);
        if (localIt != completion.mesh.vertices.end()) {
          lineage.outputVertex = vertexOffset + static_cast<int>(
              std::distance(completion.mesh.vertices.begin(), localIt));
        }
        completedVertexLineage.push_back(std::move(lineage));
      }
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
      for (const geometry::PureQuadFaceLineage &localLineage :
           completion.mesh.quadLineage) {
        geometry::PureQuadFaceLineage lineage = localLineage;
        lineage.outputQuad = oldQuadRows + localLineage.outputQuad;
        completedQuadLineage.push_back(std::move(lineage));
      }
      completedQuadCount += completion.mesh.quads.size();
      result.surfaceCellContext.completedPatches.push_back(completion.mesh);
    }

    result.diagnostics.surfaceCellCompletionSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - completionStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellCompletedQuadCount = completedQuadCount;
    result.diagnostics.surfaceCellCompletedQuadCountAvailable = true;
    result.surfaceCellContext.completedVertices = completedVertices;
    result.surfaceCellContext.completedQuads = completedQuads;
    result.surfaceCellContext.completedProvenance = completedProvenance;
    result.surfaceCellContext.completedVertexLineage = completedVertexLineage;
    result.surfaceCellContext.completedQuadLineage = completedQuadLineage;
    geometry::PureQuadMesh aggregateLineageMesh;
    aggregateLineageMesh.sourcePatch = completedQuadLineage.empty()
                                           ? -1
                                           : completedQuadLineage.front().sourcePatch;
    aggregateLineageMesh.vertices.resize(static_cast<std::size_t>(completedVertices.rows()));
    std::iota(aggregateLineageMesh.vertices.begin(), aggregateLineageMesh.vertices.end(), 0);
    aggregateLineageMesh.vertexProvenance = completedProvenance;
    aggregateLineageMesh.vertexLineage = completedVertexLineage;
    aggregateLineageMesh.quadLineage = completedQuadLineage;
    aggregateLineageMesh.quads.reserve(static_cast<std::size_t>(completedQuads.rows()));
    for (int q = 0; q < completedQuads.rows(); ++q) {
      aggregateLineageMesh.quads.push_back({completedQuads(q,0), completedQuads(q,1), completedQuads(q,2), completedQuads(q,3)});
    }
    // Aggregate quads may originate from different patches, so validate each
    // lineage record independently. Geometric coincidence with paired source
    // triangles is always detected, but it is rejected only when the explicit
    // proof-fixture gate is enabled. A valid minimal completed patch can
    // otherwise coincide with the boundary of two source triangles.
    geometry::PureQuadOutputLineageValidation lineageValidation;
    lineageValidation.allVerticesMapped =
        completedVertexLineage.size() ==
            static_cast<std::size_t>(completedVertices.rows()) &&
        std::all_of(completedVertexLineage.begin(),
                    completedVertexLineage.end(),
                    [](const auto &lineage) { return lineage.valid(); });
    lineageValidation.allQuadsMapped =
        completedQuadLineage.size() ==
            static_cast<std::size_t>(completedQuads.rows()) &&
        std::all_of(completedQuadLineage.begin(), completedQuadLineage.end(),
                    [](const auto &lineage) { return lineage.valid(); });
    lineageValidation.solelyPairedSourceTriangleBoundaries =
        geometry::output_is_only_paired_source_triangle_boundaries(
            aggregateLineageMesh, meshWhole.F);
    const bool pairedBoundaryOutputRejected =
        options.surfaceCells.rejectPairedSourceTriangleBoundaryOutput &&
        lineageValidation.solelyPairedSourceTriangleBoundaries;
    lineageValidation.valid = lineageValidation.allVerticesMapped &&
                              lineageValidation.allQuadsMapped &&
                              !pairedBoundaryOutputRejected;
    if (!lineageValidation.allVerticesMapped) {
      lineageValidation.failure = "MissingOutputVertexLineage";
    } else if (!lineageValidation.allQuadsMapped) {
      lineageValidation.failure = "MissingOutputQuadLineage";
    } else if (pairedBoundaryOutputRejected) {
      lineageValidation.failure = "PairedSourceTriangleBoundaryOutput";
    }
    result.surfaceCellContext.outputLineageValidation = lineageValidation;
    result.surfaceCellContext.hasCompletedPatches =
        !result.surfaceCellContext.completedPatches.empty();
    const std::uint64_t completionHash = hash_completion_mesh(
        completedVertices, completedQuads, completedProvenance);
    const SurfaceCellObjectIdentity completionIdentity = make_identity(
        "completion", completionHash, completedQuadCount);
    mark_stage_consumed("simplification", simplificationIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("completion", simplificationIdentity,
                              completionIdentity, true,
                              result.diagnostics.surfaceCellCompletionSeconds);
    completedSurfaceCellStages.push_back("completion");
    if (options.surfaceCells.injectFailureAfterStage == 8) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "completion");
    }
    if (completedQuadCount == 0U ||
        !result.surfaceCellContext.outputLineageValidation.valid) {
      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
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
      constraints.sourceFaceComponent =
          result.surfaceCellContext.sourceSurfaceLabels.componentByFace;
      constraints.sourceFaceSheet =
          result.surfaceCellContext.sourceSurfaceLabels.localSheetByFace;
      constraints.localTargetSize = targetSize.targetSize;
      constraints.vertexProvenance = completedProvenance;
      fill_surface_cell_rail_constraints(authoritativeRails, constraints);
      geometry::SurfaceOptimizationOptions optimizationOptions;
      optimizationOptions.targetSize = tracingOptions.defaultTargetSize;
      const geometry::SurfaceOptimizationResult optimization =
          geometry::optimize_projected_surface_mesh(completedVertices,
                                                    completedQuads,
                                                    constraints,
                                                    optimizationOptions);
      const auto validationStart = Clock::now();
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
      std::uint64_t optimizationHash = structural_hash_seed("optimization");
      hash_combine_u64(optimizationHash, completionIdentity.structuralHash);
      hash_matrix(optimizationHash, optimization.vertices);
      hash_matrix(optimizationHash, optimization.quads);
      result.surfaceCellContext.optimizationResult = optimization;
      result.surfaceCellContext.hasOptimizationResult = true;
      const SurfaceCellObjectIdentity optimizationIdentity = make_identity(
          "optimization", optimizationHash,
          static_cast<std::size_t>(optimization.quads.rows()));
      mark_stage_consumed("completion", completionIdentity,
                          SurfaceCellConsumptionKind::Full);
      record_surface_cell_stage("optimization", completionIdentity,
                                optimizationIdentity, true,
                                result.diagnostics.surfaceCellOptimizationSeconds);

      completedSurfaceCellStages.push_back("optimization");
      if (options.surfaceCells.injectFailureAfterStage == 9) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "optimization");
      }
      result.surfaceCellContext.validationResult = validation;
      result.surfaceCellContext.hasValidationResult = true;
      result.diagnostics.surfaceCellValidationSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              Clock::now() - validationStart)
              .count() /
          1.0e6;
      const SurfaceCellObjectIdentity validationIdentity = make_identity(
          "optimization", optimizationIdentity.structuralHash,
          static_cast<std::size_t>(optimization.quads.rows()));
      mark_stage_consumed("optimization", optimizationIdentity,
                          SurfaceCellConsumptionKind::Full);
      record_surface_cell_stage("validation", optimizationIdentity,
                                validationIdentity, true,
                                result.diagnostics.surfaceCellValidationSeconds);
      if (validation.accepted) {
        result.success = true;
        result.vertices = optimization.vertices;
        result.faces = optimization.quads;
        result.degrees = Eigen::VectorXi::Constant(optimization.quads.rows(), 4);
        result.outputVertexProvenance = optimization.vertexProvenance;
        result.outputVertexLineage = completedVertexLineage;
        result.outputQuadLineage = completedQuadLineage;
        result.diagnostics.surfaceCellRemeshOccurred = true;
        result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::CompletedSurfaceCells;
        result.diagnostics.surfaceCellProvenanceVertexCount =
            result.outputVertexProvenance.size();
        result.diagnostics.terminalFailureCode = "None";
        result.diagnostics.terminalFailureStage.clear();

        result.diagnostics.overallPipelineSeconds =
            std::chrono::duration_cast<std::chrono::microseconds>(
                Clock::now() - pipelineStart)
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
      const SurfaceCellObjectIdentity emptyOptimizationIdentity = make_identity(
          "optimization", structural_hash_seed("optimization"), 0U);
      mark_stage_consumed("completion", completionIdentity,
                          SurfaceCellConsumptionKind::Full);
      record_surface_cell_stage("optimization", completionIdentity,
                                emptyOptimizationIdentity, true,
                                result.diagnostics.surfaceCellOptimizationSeconds);

      completedSurfaceCellStages.push_back("optimization");
      if (options.surfaceCells.injectFailureAfterStage == 9) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "optimization");
      }
    }

    return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                              "validation");
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

inline RemeshResult remesh_surface_cells_from_cross_field_impl(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const RemeshOptions &options) {
  return remesh_from_raw_cross_field_impl(meshWhole, crossField.rawField,
                                          options, &crossField);
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
  if (target.surfaceCellOutputOrigin == SurfaceCellOutputOrigin::None) {
    target.surfaceCellOutputOrigin = source.surfaceCellOutputOrigin;
  } else if (source.surfaceCellOutputOrigin != SurfaceCellOutputOrigin::None &&
             target.surfaceCellOutputOrigin != source.surfaceCellOutputOrigin) {
    target.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::Mixed;
  }
  target.surfaceCellDebugArtifactsPreserved =
      target.surfaceCellDebugArtifactsPreserved ||
      source.surfaceCellDebugArtifactsPreserved;
  target.surfaceCellDebugArtifacts.insert(
      target.surfaceCellDebugArtifacts.end(),
      source.surfaceCellDebugArtifacts.begin(),
      source.surfaceCellDebugArtifacts.end());
  target.surfaceCellStageLineage.insert(
      target.surfaceCellStageLineage.end(),
      source.surfaceCellStageLineage.begin(),
      source.surfaceCellStageLineage.end());

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
    const fields::CrossFieldResult crossField =
        finalize_surface_cell_raw_cross_field(meshWhole, rawCrossField);
    return remesh_surface_cells_from_cross_field_impl(meshWhole, crossField,
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
      const fields::CrossFieldResult crossField =
          finalize_surface_cell_raw_cross_field(componentMesh, component.rawField);
      run.result = remesh_surface_cells_from_cross_field_impl(
          componentMesh, crossField, componentOptions);
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

inline RemeshResult unsupported_parallel_surface_cells_result(
    const RemeshOptions &options) {
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
      surface_cell_failure_code_name(SurfaceCellFailureCode::UnsupportedInput);
  result.diagnostics.terminalFailureStage = "component-scheduling";
  result.diagnostics.originalSurfaceCellFailureCode =
      result.diagnostics.terminalFailureCode;
  result.diagnostics.originalSurfaceCellFailureStage =
      result.diagnostics.terminalFailureStage;
  result.diagnostics.surfaceCellValidationFailures = 1U;
  return result;
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
  const bool surfaceCellsRequested =
      options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled;
  if (options.parallelizeComponents) {
    if (surfaceCellsRequested) {
      return unsupported_parallel_surface_cells_result(options);
    }
    return remesh_components_from_raw_cross_field(vertices, faces, rawCrossField,
                                                 options);
  }
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  if (surfaceCellsRequested) {
    return remesh_from_raw_cross_field_impl(meshWhole, rawCrossField, options);
  }
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
      (!crossField.matchingComputed || crossField.matching.size() == 0 ||
       crossField.effort.size() != crossField.matching.size())) {
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
      !crossField.singularitiesComputed) {
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
  if (surfaceCellsRequested && options.parallelizeComponents) {
    return unsupported_parallel_surface_cells_result(options);
  }
  RemeshResult result;
  if (surfaceCellsRequested && !options.parallelizeComponents) {
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    result = remesh_surface_cells_from_cross_field_impl(meshWhole, crossField,
                                                        options);
  } else {
    result = remesh_from_raw_cross_field(vertices, faces, crossField.rawField,
                                         options);
  }
  result.crossFieldMatching = crossField.matching;
  result.crossFieldEffort = crossField.effort;
  result.crossFieldSingularCycles = crossField.singularCycles;
  result.crossFieldSingularIndices = crossField.singularIndices;
  if (result.surfaceCellContext.hasCrossField) {
    result.surfaceCellContext.crossField = crossField;
    normalize_surface_cell_cross_field_directions(
        result.surfaceCellContext.crossField);
    result.surfaceCellContext.crossFieldHasMatching =
        result.surfaceCellContext.crossField.matchingComputed;
    result.surfaceCellContext.crossFieldHasSingularities =
        result.surfaceCellContext.crossField.singularitiesComputed;
  }
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
  return remesh_from_raw_cross_field(vertices, faces, rawField, options);
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
  return remesh_from_raw_cross_field(vertices, faces, rawField, options);
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
    crossFieldOptions.computeMatching = true;
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
  crossFieldOptions.computeMatching = true;
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
  return remesh_from_cross_field_result(meshWhole.V, meshWhole.F, crossField,
                                        remeshOptions);
}

} // namespace directional::pipeline

#endif // DIRECTIONAL_PIPELINE_REMESH_PIPELINE_H
