// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_PATCH_DESCRIPTOR_H
#define DIRECTIONAL_GEOMETRY_PATCH_DESCRIPTOR_H

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SurfaceArrangement.h>
#include <directional/geometry/SurfaceCellFeasibilityRepair.h>

namespace directional::geometry {

struct PatchDescriptorOptions {
  // Source-vertex cycle IDs and corresponding quarter-index numerators.
  // These are CrossFieldResult::singularCycles/singularIndices.
  Eigen::VectorXi singularCycles;
  Eigen::VectorXi singularIndices;
  double barycentricTolerance = 1.0e-10;
  bool enforceGlobalSingularityOwnership = false;
  std::set<int> embeddedSingularVertices;
  std::map<int, int> interiorSingularityOwner;
};

struct PatchSideDescriptor {
  int family = -1;
  std::vector<int> halfedges;
  std::vector<int> boundaryVertices;
  int subdivisionCount = 0;
  bool hardFeature = false;
  std::set<int> railIds;
  std::set<int> curveIds;
};

struct PatchDescriptor {
  int cellId = -1;
  PureQuadPatch patch;
  PureQuadPatchAdmissibility feasibility;
  std::vector<PatchSideDescriptor> sides;
  std::vector<int> singularSourceVertices;
  std::vector<int> singularNumerators;
  bool boundaryCycleValid = false;
  bool featureConstraintsValid = true;
};

struct PatchDescriptorSet {
  std::vector<PatchDescriptor> descriptors;
  SurfaceCellOwnershipConflict ownershipConflict;
  std::vector<int> unresolvedSingularVertices;
  int feasible = 0;
  int rejected = 0;
};

struct SurfaceCellComplexCompletionOptions {
  PatchDescriptorOptions descriptorOptions;
  int maxBoundaryEdges = 128;
  bool allowBoundedCombinatorialFallback = true;
  int maxCompletionOwnershipRepairs = 256;
  const std::vector<int> *sourceFaceComponents = nullptr;
  const std::vector<int> *sourceFaceSheets = nullptr;
};

struct SurfaceCellComplexCompletionResult {
  bool success = false;
  SurfaceCellComplex preparedComplex;
  bool hasPreparedComplex = false;
  int parityOddCellsBefore = 0;
  int parityOddCellsAfter = 0;
  int paritySplitEdges = 0;
  int parityHardFeatureSplits = 0;
  int sideInfeasibleCellsBefore = 0;
  int sideInfeasibleCellsAfter = 0;
  int sideInitialEquationDefect = 0;
  int sideFinalEquationDefect = 0;
  int sidePropagationPasses = 0;
  int sideAttemptedInsertions = 0;
  int sideInsertedVertices = 0;
  int sideSplitEdges = 0;
  int sideHardFeatureSplits = 0;
  PatchDescriptorSet descriptors;
  std::vector<PureQuadMesh> completedPatches;
  PureQuadAssemblyResult assembly;
  int attemptedPatches = 0;
  int failedPatches = 0;
  int completionOwnershipRepairAttempts = 0;
  PureQuadCompletionOwnershipRejection firstCompletionOwnershipRejection;
  std::string failure;
};

namespace patch_descriptor_detail {

const SurfaceArrangementNode *find_node(
    const SurfaceCellComplex &complex, const int id);

int normalized_family(const int family);

int source_vertex_at_node(const SurfaceArrangementNode &node,
                                 const Eigen::MatrixXi &F,
                                 const double tolerance);

SurfacePoint node_surface_point(const SurfaceArrangementNode &node,
                                       const Eigen::MatrixXd &V,
                                       const Eigen::MatrixXi &F,
                                       const SurfaceArrangementHalfedge &edge);

bool ordered_boundary(const SurfaceCellComplex &complex,
                             const SurfaceArrangementCell &cell,
                             std::vector<int> &ordered);

std::vector<PatchSideDescriptor>
extract_sides(const SurfaceCellComplex &complex,
              const SurfaceArrangementCell &cell,
              const std::vector<int> &boundary,
              const Eigen::MatrixXd &V,
              const Eigen::MatrixXi &F);

bool source_vertex_is_in_cell(const int vertex,
                                     const SurfaceArrangementCell &cell,
                                     const Eigen::MatrixXi &F);

} // namespace patch_descriptor_detail

PatchDescriptor derive_patch_descriptor(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const PatchDescriptorOptions &options = {});

PatchDescriptorSet derive_patch_descriptors(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const PatchDescriptorOptions &options = {});

SurfaceCellComplexCompletionResult complete_surface_cell_complex(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options = {});

} // namespace directional::geometry

#endif
