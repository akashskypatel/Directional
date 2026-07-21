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
#include <cmath>
#include <future>
#include <functional>
#include <iostream>
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
  Legacy,
  SurfaceCells
};

struct SurfaceCellOptions {
  bool enabled = false;
  bool strictValidation = true;
  double geometricTolerance = 1.0e-9;
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

  /// Reserved for future feature-aligned pipeline support.
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

  /// Enables Phase 08 component-level parallel remeshing. Disabled by default.
  bool parallelizeComponents = false;

  /// Maximum component worker tasks. 0 selects hardware concurrency.
  int maxComponentThreads = 0;

  /// Internal absolute target length override used for component remeshing.
  double absoluteTargetLength = -1.0;

  /// Selects the remeshing backend. SurfaceCells is default-off scaffold only.
  RemeshBackend backend = RemeshBackend::Legacy;

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
    result.success = false;
    result.diagnostics.surfaceCellValidationFailures = 1;
    result.diagnostics.overallPipelineSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - pipelineStart)
            .count() /
        1.0e6;
    return result;
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
    const geometry::BoundedMeshPreconditionerResult preconditioned =
        geometry::BoundedMeshPreconditioner::precondition(
            meshWhole.V, meshWhole.F, preconditionOptions);
    diagnostics.preconditioningSeconds += log_phase("input preconditioning");
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
