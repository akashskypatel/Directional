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
  double regionClassificationSeconds = 0.0;
  double faceRealignmentSeconds = 0.0;
  double lowQualityFacePruneSeconds = 0.0;
  double lowValenceUnificationSeconds = 0.0;
  double finalCleanSeconds = 0.0;
  double triFlowSeconds = 0.0;

  std::size_t verticesBeforeSimplification = 0;
  std::size_t facesBeforeSimplification = 0;
  std::size_t halfedgesBeforeSimplification = 0;
  std::size_t verticesAfterSimplification = 0;
  std::size_t facesAfterSimplification = 0;
  std::size_t halfedgesAfterSimplification = 0;
  std::size_t retwinnedPairCount = 0;
  std::size_t danglingFunctionEdgesCleared = 0;
  std::size_t lowQualityFacesPruned = 0;
  std::size_t lowValenceCandidatesConsidered = 0;
  std::size_t lowValenceOperationsAccepted = 0;
  std::size_t lowValenceOperationsRejected = 0;
  std::size_t cleanupRollbacks = 0;
  std::size_t boundaryHoleFillsAttempted = 0;
  std::size_t boundaryHoleFillsSucceeded = 0;
  std::size_t nonSimpleFacesPruned = 0;
};

} // namespace directional

#endif // DIRECTIONAL_DIAGNOSTICS_MESHER_DIAGNOSTICS_H
