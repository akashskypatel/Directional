// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_FEASIBILITY_REPAIR_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_FEASIBILITY_REPAIR_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <directional/geometry/SurfaceArrangement.h>

namespace directional::geometry {

struct SurfaceCellReplacementScopeFailure {
  bool active = false;
  int originalCell = -1;
  int replacementCell = -1;
  int halfedge = -1;
  int twin = -1;
  int selectedComponent = -1;
  int selectedSheet = -1;
  std::vector<int> availableComponents;
  std::vector<int> availableSheets;
  std::string mutationPhase;
};

struct SurfaceCellSubdivisionResult {
  bool success = false;
  // True only when a failed transaction returned the exact committed input
  // complex. Callers may use the returned complex as rollback state only when
  // this proof is present.
  bool rollbackEquivalent = false;
  std::uint64_t rollbackIdentityHashBefore = 0U;
  std::uint64_t rollbackIdentityHashAfter = 0U;
  std::uint64_t rollbackUndoOwnedBytes = 0U;
  SurfaceCellComplex complex;
  int splitUndirectedEdges = 0;
  int insertedVertices = 0;
  int hardFeatureSplits = 0;
  SurfaceCellReplacementScopeFailure firstScopeFailure;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
  std::string failure;
};

/**
 * Subdivide canonical undirected arrangement edges transactionally.
 *
 * The map key is any halfedge ID; its twin is canonicalized automatically.
 * The value is the number of vertices inserted on that edge. Both incident
 * cell cycles, all provenance intervals, rail parameters, and side subdivision
 * counts are updated together.
 */
SurfaceCellSubdivisionResult subdivide_surface_cell_complex_edges(
    SurfaceCellComplex input,
    const std::map<int, int> &insertionsByHalfedge,
    const Eigen::MatrixXi *sourceFaces = nullptr);

struct SurfaceCellParityRepairResult {
  bool success = false;
  SurfaceCellComplex complex;
  std::vector<int> splitHalfedges;
  int oddCellsBefore = 0;
  int oddCellsAfter = 0;
  int hardFeatureSplits = 0;
  SurfaceCellReplacementScopeFailure firstScopeFailure;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
  std::string failure;
};

/**
 * Solve the all-quad disk boundary parity constraints on the cell dual graph.
 * A deterministic minimum-hard-edge spanning forest pairs odd cells (or joins
 * them to an exterior boundary), then performs conforming shared-edge splits.
 */
SurfaceCellParityRepairResult repair_surface_cell_boundary_parity(
    SurfaceCellComplex input);

struct SurfaceCellSideRepairOptions {
  int maxInsertedVertices = 100000;
  int maxLocalInsertedVertices = 512;
  int maxPropagationPasses = 4096;
  int maxStagnantPasses = 64;
};

struct SurfaceCellSideRepairResult {
  bool success = false;
  // A permitted failed solve may continue through the general completion
  // backend only when this exact rollback proof is true.
  bool rollbackEquivalent = false;
  std::uint64_t rollbackIdentityHashBefore = 0U;
  std::uint64_t rollbackIdentityHashAfter = 0U;
  std::uint64_t rollbackUndoOwnedBytes = 0U;
  SurfaceCellComplex complex;
  int infeasibleCellsBefore = 0;
  int infeasibleCellsAfter = 0;
  int initialEquationDefect = 0;
  int finalEquationDefect = 0;
  int propagationPasses = 0;
  int attemptedInsertions = 0;
  int insertedVertices = 0;
  int splitUndirectedEdges = 0;
  int hardFeatureSplits = 0;
  SurfaceCellDomainIdentityAudit firstDomainFailure;
  std::string failure;
};

/**
 * Balance the integer side-subdivision equations for every disk cell with
 * three through six logical sides. Insertions are shared variables on the
 * arrangement dual, so a subdivision is always applied to both incident
 * patches and the system is iterated until all coupled equations agree.
 */
SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
    SurfaceCellComplex input,
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const SurfaceCellSideRepairOptions &options = {});

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CELL_FEASIBILITY_REPAIR_H
