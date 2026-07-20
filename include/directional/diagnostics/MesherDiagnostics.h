// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_DIAGNOSTICS_MESHER_DIAGNOSTICS_H
#define DIRECTIONAL_DIAGNOSTICS_MESHER_DIAGNOSTICS_H

#include <cstddef>

namespace directional {

/** @brief Machine-readable timing and count data for generated meshing. */
struct MesherDiagnostics {
  double totalMesherSeconds = 0.0;
  double generateArrangementSeconds = 0.0;
  double simplifyTotalSeconds = 0.0;
  double initialConsistencySeconds = 0.0;
  double boundaryScanSeconds = 0.0;
  double boundaryStripSeconds = 0.0;
  double vertexMatchSeconds = 0.0;
  double representativeBuildSeconds = 0.0;
  double halfedgeRemapSeconds = 0.0;
  double degeneratePruneSeconds = 0.0;
  double retwinSeconds = 0.0;
  double danglingFunctionPruneSeconds = 0.0;
  double functionSkeletonBuildSeconds = 0.0;
  double functionSkeletonSimplificationSeconds = 0.0;
  double functionSkeletonEditPlanApplicationSeconds = 0.0;
  double regionClassificationSeconds = 0.0;
  double faceRealignmentSeconds = 0.0;
  double lowQualityFacePruneSeconds = 0.0;
  double lowValenceUnificationSeconds = 0.0;
  double localPatchPrevalidationSeconds = 0.0;
  double postUnificationRetwinSeconds = 0.0;
  double nonSimplePruneSeconds = 0.0;
  double holeFillSeconds = 0.0;
  double patchFallbackExtractionSeconds = 0.0;
  double patchFallbackClassificationSeconds = 0.0;
  double patchFallbackQuadrangulationSeconds = 0.0;
  double patchFallbackReinsertionSeconds = 0.0;
  double finalCleanSeconds = 0.0;
  double triFlowSeconds = 0.0;

  std::size_t verticesBeforeSimplification = 0;
  std::size_t facesBeforeSimplification = 0;
  std::size_t halfedgesBeforeSimplification = 0;
  std::size_t verticesAfterSimplification = 0;
  std::size_t facesAfterSimplification = 0;
  std::size_t halfedgesAfterSimplification = 0;
  std::size_t retwinCallCount = 0;
  std::size_t retwinCallsBeforeFunctionCleanup = 0;
  std::size_t retwinCallsAfterFunctionCleanup = 0;
  std::size_t retwinnedPairCount = 0;
  std::size_t danglingFunctionEdgesCleared = 0;
  std::size_t functionSkeletonNodeCount = 0;
  std::size_t functionSkeletonEdgeCount = 0;
  std::size_t functionSkeletonRawFunctionEdgeCount = 0;
  double functionSkeletonAverageHalfedgesPerEdge = 0.0;
  std::size_t functionSkeletonEditsPlanned = 0;
  std::size_t functionSkeletonEditsApplied = 0;
  std::size_t functionSkeletonEditsRejected = 0;
  bool functionSkeletonMatchesConnectivity = true;
  std::size_t lowQualityFacesPruned = 0;
  std::size_t lowValenceCandidatesConsidered = 0;
  std::size_t localPatchPrevalidationAccepted = 0;
  std::size_t localPatchPrevalidationRejected = 0;
  std::size_t localPatchInvalidPatchRejections = 0;
  std::size_t localPatchDisconnectedRegionRejections = 0;
  std::size_t localPatchRepeatedBoundaryVertexRejections = 0;
  std::size_t localPatchConsecutiveDuplicateEdgeRejections = 0;
  std::size_t localPatchFaceDegreeBelowThreeRejections = 0;
  std::size_t localPatchZeroLengthBoundaryEdgeRejections = 0;
  std::size_t localPatchEulerCharacteristicRejections = 0;
  std::size_t localPatchProtectedSeamRejections = 0;
  std::size_t localPatchComponentSplitRejections = 0;
  std::size_t localPatchNewBoundaryOnClosedRegionRejections = 0;
  std::size_t lowValenceMutationsAttempted = 0;
  std::size_t lowValenceOperationsAccepted = 0;
  std::size_t lowValenceOperationsRejected = 0;
  std::size_t cleanupRollbacks = 0;
  std::size_t boundaryHoleFillsAttempted = 0;
  std::size_t boundaryHoleFillsSucceeded = 0;
  std::size_t nonSimpleFacesPruned = 0;
  std::size_t patchFallbackRegionsDetected = 0;
  std::size_t patchFallbackPatchesAttempted = 0;
  std::size_t patchFallbackPatchesSucceeded = 0;
  std::size_t patchFallbackPatchesRejected = 0;
  std::size_t patchFallbackFacesRepaired = 0;
  std::size_t patchFallbackNonQuadFacesBefore = 0;
  std::size_t patchFallbackNonQuadFacesAfter = 0;
};

} // namespace directional

#endif // DIRECTIONAL_DIAGNOSTICS_MESHER_DIAGNOSTICS_H
