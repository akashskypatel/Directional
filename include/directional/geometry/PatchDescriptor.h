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

namespace directional::geometry {

struct PatchDescriptorOptions {
  // Source-vertex cycle IDs and corresponding quarter-index numerators.
  // These are CrossFieldResult::singularCycles/singularIndices.
  Eigen::VectorXi singularCycles;
  Eigen::VectorXi singularIndices;
  double barycentricTolerance = 1.0e-10;
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
  int feasible = 0;
  int rejected = 0;
};

struct SurfaceCellComplexCompletionOptions {
  PatchDescriptorOptions descriptorOptions;
  int maxBoundaryEdges = 128;
  bool allowBoundedCombinatorialFallback = true;
  const std::vector<int> *sourceFaceComponents = nullptr;
  const std::vector<int> *sourceFaceSheets = nullptr;
};

struct SurfaceCellComplexCompletionResult {
  bool success = false;
  PatchDescriptorSet descriptors;
  std::vector<PureQuadMesh> completedPatches;
  PureQuadAssemblyResult assembly;
  int attemptedPatches = 0;
  int failedPatches = 0;
  std::string failure;
};

namespace patch_descriptor_detail {

inline const SurfaceArrangementNode *find_node(
    const SurfaceCellComplex &complex, const int id) {
  if (id >= 0 && id < static_cast<int>(complex.nodes.size()) &&
      complex.nodes[static_cast<std::size_t>(id)].id == id) {
    return &complex.nodes[static_cast<std::size_t>(id)];
  }
  const auto it = std::find_if(
      complex.nodes.begin(), complex.nodes.end(),
      [&](const SurfaceArrangementNode &node) { return node.id == id; });
  return it == complex.nodes.end() ? nullptr : &*it;
}

inline int normalized_family(const int family) {
  if (family < 0) {
    return family;
  }
  return family & 1;
}

inline int source_vertex_at_node(const SurfaceArrangementNode &node,
                                 const Eigen::MatrixXi &F,
                                 const double tolerance) {
  const auto inspect = [&](const int face, const Eigen::RowVector3d &bary) {
    if (face < 0 || face >= F.rows()) {
      return -1;
    }
    int corner = 0;
    bary.maxCoeff(&corner);
    if (bary(corner) >= 1.0 - tolerance) {
      return F(face, corner);
    }
    return -1;
  };
  int vertex = inspect(node.sourceFace, node.barycentric);
  if (vertex >= 0) {
    return vertex;
  }
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    vertex = inspect(occurrence.sourceFace, occurrence.barycentric);
    if (vertex >= 0) {
      return vertex;
    }
  }
  return -1;
}

inline SurfacePoint node_surface_point(const SurfaceArrangementNode &node,
                                       const Eigen::MatrixXd &V,
                                       const Eigen::MatrixXi &F,
                                       const SurfaceArrangementHalfedge &edge) {
  SurfacePoint point;
  point.face = node.sourceFace;
  point.component = edge.sourceComponent;
  point.sheet = edge.sourceSheet;
  point.barycentric = node.barycentric.transpose();
  if (point.face >= 0 && point.face < F.rows() && F.cols() == 3 &&
      V.cols() == 3) {
    point.position =
        point.barycentric(0) * V.row(F(point.face, 0)).transpose() +
        point.barycentric(1) * V.row(F(point.face, 1)).transpose() +
        point.barycentric(2) * V.row(F(point.face, 2)).transpose();
    point.squaredDistance = 0.0;
  }
  return point;
}

inline bool ordered_boundary(const SurfaceCellComplex &complex,
                             const SurfaceArrangementCell &cell,
                             std::vector<int> &ordered) {
  ordered.clear();
  if (cell.halfedges.empty()) {
    return false;
  }
  std::map<int, int> byFrom;
  for (const int id : cell.halfedges) {
    if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    if (edge.cell != cell.id || edge.from < 0 || edge.to < 0 ||
        !byFrom.emplace(edge.from, id).second) {
      return false;
    }
  }

  int current = *std::min_element(cell.halfedges.begin(), cell.halfedges.end());
  const int first = current;
  std::set<int> visited;
  while (visited.insert(current).second) {
    ordered.push_back(current);
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(current)];
    const auto next = byFrom.find(edge.to);
    if (next == byFrom.end()) {
      return false;
    }
    current = next->second;
  }
  return current == first && ordered.size() == cell.halfedges.size();
}

inline std::vector<PatchSideDescriptor>
extract_sides(const SurfaceCellComplex &complex,
              const SurfaceArrangementCell &cell,
              const std::vector<int> &boundary) {
  std::vector<PatchSideDescriptor> sides;
  if (boundary.empty()) {
    return sides;
  }
  const int declaredCount = std::accumulate(
      cell.sideEdgeCounts.begin(), cell.sideEdgeCounts.end(), 0);
  if (cell.sideEdgeCounts.size() >= 3 && cell.sideEdgeCounts.size() <= 6 &&
      declaredCount == static_cast<int>(boundary.size())) {
    std::size_t offset = 0;
    for (std::size_t sideIndex = 0; sideIndex < cell.sideEdgeCounts.size();
         ++sideIndex) {
      PatchSideDescriptor side;
      side.family = sideIndex < cell.sideFamilies.size()
                        ? normalized_family(cell.sideFamilies[sideIndex])
                        : normalized_family(complex.halfedges[
                              static_cast<std::size_t>(boundary[offset])].family);
      for (int local = 0; local < cell.sideEdgeCounts[sideIndex]; ++local) {
        const int id = boundary[offset++];
        const SurfaceArrangementHalfedge &edge =
            complex.halfedges[static_cast<std::size_t>(id)];
        side.halfedges.push_back(id);
        side.boundaryVertices.push_back(edge.from);
        ++side.subdivisionCount;
        side.hardFeature = side.hardFeature || edge.hardFeature;
        if (edge.railId >= 0) side.railIds.insert(edge.railId);
        if (edge.curveId >= 0) side.curveIds.insert(edge.curveId);
      }
      sides.push_back(std::move(side));
    }
    return sides;
  }
  for (const int id : boundary) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    const int family = normalized_family(edge.family);
    if (sides.empty() || sides.back().family != family) {
      PatchSideDescriptor side;
      side.family = family;
      sides.push_back(std::move(side));
    }
    PatchSideDescriptor &side = sides.back();
    side.halfedges.push_back(id);
    side.boundaryVertices.push_back(edge.from);
    ++side.subdivisionCount;
    side.hardFeature = side.hardFeature || edge.hardFeature;
    if (edge.railId >= 0) {
      side.railIds.insert(edge.railId);
    }
    if (edge.curveId >= 0) {
      side.curveIds.insert(edge.curveId);
    }
  }
  if (sides.size() > 1 && sides.front().family == sides.back().family) {
    PatchSideDescriptor tail = std::move(sides.back());
    sides.pop_back();
    PatchSideDescriptor &front = sides.front();
    front.halfedges.insert(front.halfedges.begin(), tail.halfedges.begin(),
                           tail.halfedges.end());
    front.boundaryVertices.insert(front.boundaryVertices.begin(),
                                  tail.boundaryVertices.begin(),
                                  tail.boundaryVertices.end());
    front.subdivisionCount += tail.subdivisionCount;
    front.hardFeature = front.hardFeature || tail.hardFeature;
    front.railIds.insert(tail.railIds.begin(), tail.railIds.end());
    front.curveIds.insert(tail.curveIds.begin(), tail.curveIds.end());
  }
  return sides;
}

inline bool source_vertex_is_in_cell(const int vertex,
                                     const SurfaceArrangementCell &cell,
                                     const Eigen::MatrixXi &F) {
  for (const int face : cell.sourceFaces) {
    if (face < 0 || face >= F.rows()) {
      continue;
    }
    for (int corner = 0; corner < F.cols(); ++corner) {
      if (F(face, corner) == vertex) {
        return true;
      }
    }
  }
  if (cell.sourceFaces.empty() && cell.sourceFace >= 0 &&
      cell.sourceFace < F.rows()) {
    for (int corner = 0; corner < F.cols(); ++corner) {
      if (F(cell.sourceFace, corner) == vertex) {
        return true;
      }
    }
  }
  return false;
}

} // namespace patch_descriptor_detail

inline PatchDescriptor derive_patch_descriptor(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const PatchDescriptorOptions &options = {}) {
  PatchDescriptor descriptor;
  descriptor.cellId = cell.id;
  PureQuadPatch &patch = descriptor.patch;
  patch.diskTopology = cell.disk && cell.eulerCharacteristic == 1;
  patch.boundaryLoopCount = cell.boundaryComponentCount;
  patch.sourceFaces = cell.sourceFaces;
  if (patch.sourceFaces.empty() && cell.sourceFace >= 0) {
    patch.sourceFaces.push_back(cell.sourceFace);
  }
  patch.simple = true;

  std::vector<int> boundary;
  descriptor.boundaryCycleValid =
      patch_descriptor_detail::ordered_boundary(complex, cell, boundary);
  if (!descriptor.boundaryCycleValid) {
    patch.diskTopology = false;
    descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
    return descriptor;
  }

  descriptor.sides =
      patch_descriptor_detail::extract_sides(complex, cell, boundary);
  patch.sideEdgeCounts.reserve(descriptor.sides.size());
  patch.turns.reserve(descriptor.sides.size());
  for (const PatchSideDescriptor &side : descriptor.sides) {
    patch.sideEdgeCounts.push_back(side.subdivisionCount);
    // Arrangement families encode the two orthogonal cross directions. A
    // change of family is one quarter turn; the cell orientation determines
    // its sign. Straight runs were merged into the same side above.
    patch.turns.push_back(1);
  }

  std::set<int> boundarySourceVertices;
  for (const int id : boundary) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    const SurfaceArrangementNode *node =
        patch_descriptor_detail::find_node(complex, edge.from);
    if (node == nullptr) {
      patch.diskTopology = false;
      descriptor.boundaryCycleValid = false;
      descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
      return descriptor;
    }
    patch.boundaryVertices.push_back(node->id);
    patch.boundaryRailIds.push_back(edge.railId);
    patch.boundaryCurveIds.push_back(edge.curveId);
    patch.boundaryProvenance.push_back(
        patch_descriptor_detail::node_surface_point(*node, V, F, edge));
    patch.hardFeatureCrossing =
        patch.hardFeatureCrossing || node->hardBarrierCrossing;
    const int sourceVertex = patch_descriptor_detail::source_vertex_at_node(
        *node, F, options.barycentricTolerance);
    if (sourceVertex >= 0) {
      boundarySourceVertices.insert(sourceVertex);
    }
  }

  descriptor.featureConstraintsValid = !patch.hardFeatureCrossing;
  const int singularCount =
      std::min(options.singularCycles.size(), options.singularIndices.size());
  for (int i = 0; i < singularCount; ++i) {
    const int sourceVertex = options.singularCycles(i);
    if (!patch_descriptor_detail::source_vertex_is_in_cell(sourceVertex, cell,
                                                            F)) {
      continue;
    }
    if (boundarySourceVertices.count(sourceVertex) != 0) {
      // Boundary singularities are represented by adjacent patches and do not
      // consume an interior irregular vertex in this patch.
      continue;
    }
    descriptor.singularSourceVertices.push_back(sourceVertex);
    descriptor.singularNumerators.push_back(options.singularIndices(i));
  }
  patch.singularityCount =
      static_cast<int>(descriptor.singularNumerators.size());
  patch.unmatchedInteriorSingularity = patch.singularityCount > 1;
  patch.singularIndexNumerator =
      patch.singularityCount == 1 ? descriptor.singularNumerators.front() : 0;

  descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
  return descriptor;
}

inline PatchDescriptorSet derive_patch_descriptors(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const PatchDescriptorOptions &options = {}) {
  PatchDescriptorSet result;
  result.descriptors.reserve(complex.cells.size());
  for (const SurfaceArrangementCell &cell : complex.cells) {
    // Exterior DCEL cycles describe the unbounded side of each connected
    // arrangement component. They are not authoritative surface patches and
    // must not participate in completion completeness checks.
    if (cell.cellClass == SurfaceArrangementCellClass::Exterior) {
      continue;
    }
    PatchDescriptor descriptor =
        derive_patch_descriptor(complex, cell, V, F, options);
    if (descriptor.feasibility.admissible) {
      ++result.feasible;
    } else {
      ++result.rejected;
    }
    result.descriptors.push_back(std::move(descriptor));
  }
  return result;
}

inline SurfaceCellComplexCompletionResult complete_surface_cell_complex(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options = {}) {
  SurfaceCellComplexCompletionResult result;
  result.descriptors = derive_patch_descriptors(
      complex, V, F, options.descriptorOptions);
  if (result.descriptors.descriptors.empty()) {
    result.failure = "NoPatchDescriptors";
    result.assembly.failure = result.failure;
    return result;
  }
  for (const PatchDescriptor &descriptor : result.descriptors.descriptors) {
    if (!descriptor.boundaryCycleValid ||
        !descriptor.feasibility.admissible) {
      ++result.failedPatches;
      continue;
    }
    ++result.attemptedPatches;
    PureQuadCompletionOptions completionOptions;
    completionOptions.sourcePatch = descriptor.cellId;
    completionOptions.maxBoundaryEdges = options.maxBoundaryEdges;
    completionOptions.allowBoundedCombinatorialFallback =
        options.allowBoundedCombinatorialFallback;
    completionOptions.sourceVertices = &V;
    completionOptions.sourceFaces = &F;
    completionOptions.sourceFaceComponents = options.sourceFaceComponents;
    completionOptions.sourceFaceSheets = options.sourceFaceSheets;
    const PureQuadCompletionResult completion =
        complete_pure_quad_patch(descriptor.patch, completionOptions);
    if (!completion.success || completion.mesh.quads.empty()) {
      ++result.failedPatches;
      continue;
    }
    result.completedPatches.push_back(completion.mesh);
  }
  if (result.failedPatches != 0 ||
      result.completedPatches.size() != result.descriptors.descriptors.size()) {
    result.failure = "IncompleteSurfaceCellComplex";
    result.assembly.failure = result.failure;
    return result;
  }
  result.assembly = stitch_pure_quad_patches(result.completedPatches);
  result.success = result.assembly.success;
  if (!result.success) {
    result.failure = result.assembly.failure;
  }
  return result;
}

} // namespace directional::geometry

#endif
