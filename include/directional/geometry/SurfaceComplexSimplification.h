// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H
#define DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/SurfaceArrangement.h>

namespace directional::geometry {

enum class SurfaceSimplificationCandidateType : int {
  RedundantStrand = 0,
  OpenStrip = 1,
  ClosedLoop = 2,
  ParallelCurveMerge = 3,
  ReliefArtifact = 4,
};

enum class SurfaceSimplificationRejectionReason : int {
  None = 0,
  ProtectedFeature = 1,
  ProtectedBoundary = 2,
  ProtectedRoot = 3,
  ProtectedSingularity = 4,
  TopologyChanged = 5,
  NonDiskPatch = 6,
  PatchInfeasible = 7,
  ObjectiveWorsened = 8,
  DescriptivenessWorsened = 9,
  StaleCandidate = 10,
  TargetReached = 11,
};

struct SurfaceSimplificationElement {
  int id = -1;
  int cellOrHalfedge = -1;
  bool active = true;
  bool hardFeature = false;
  bool boundary = false;
  bool basinRoot = false;
  bool rootLabelProtected = false;
  bool singularityProtected = false;
  bool handleCritical = false;
  double length = 1.0;
};

struct SurfaceSimplificationObjectiveWeights {
  double surface = 1.0;
  double normal = 1.0;
  double field = 1.0;
  double size = 1.0;
  double quad = 1.0;
  double feature = 1.0;
  double topology = 1.0;
};

struct SurfaceSimplificationCandidate {
  int stableId = -1;
  SurfaceSimplificationCandidateType type =
      SurfaceSimplificationCandidateType::OpenStrip;
  std::vector<int> elementIds;
  double deltaSurface = 0.0;
  double deltaNormal = 0.0;
  double deltaField = 0.0;
  double deltaSize = 0.0;
  double deltaQuad = 0.0;
  double featurePenalty = 0.0;
  double topologyPenalty = 0.0;
  double descriptivenessWorsening = 0.0;
  bool affectedPatchDisk = true;
  bool sideFeasible = true;
  bool changesTopology = false;
  bool invalidated = false;
};

struct SurfaceSimplificationOptions {
  SurfaceSimplificationObjectiveWeights weights;
  int targetActiveElements = 0;
  double objectiveTolerance = 0.0;
  double maxDescriptivenessWorsening = 0.05;
};

struct SurfaceSimplificationTransaction {
  int candidateId = -1;
  SurfaceSimplificationCandidateType type =
      SurfaceSimplificationCandidateType::OpenStrip;
  bool committed = false;
  SurfaceSimplificationRejectionReason rejection =
      SurfaceSimplificationRejectionReason::None;
  double objectiveCost = 0.0;
  std::uint64_t beforeHash = 0;
  std::uint64_t afterHash = 0;
};

struct SurfaceSimplificationResult {
  std::vector<SurfaceSimplificationElement> elements;
  SurfaceCellComplex complex;
  bool hasComplexOutput = false;
  std::vector<SurfaceSimplificationTransaction> transactions;
  int committed = 0;
  int rejected = 0;
  int invalidatedCandidates = 0;
  int recomputedCandidates = 0;
  int incidenceRebuilds = 0;
  int validationPasses = 0;
  int initialActiveElements = 0;
  int finalActiveElements = 0;
  std::uint64_t finalHash = 0;
  double empiricalWork = 0.0;
};

struct SurfaceSimplificationOverlay {
  Eigen::VectorXi candidateType;
  Eigen::VectorXi retained;
  Eigen::VectorXi removed;
  Eigen::VectorXi rejectionReason;
  Eigen::VectorXd objectiveCost;
};

namespace surface_simplification_detail {

inline bool element_protected(const SurfaceSimplificationElement &element) {
  return element.hardFeature || element.boundary || element.basinRoot ||
         element.rootLabelProtected || element.singularityProtected;
}

inline std::uint64_t structural_hash(
    const std::vector<SurfaceSimplificationElement> &elements) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  for (const SurfaceSimplificationElement &element : elements) {
    mix(element.id);
    mix(element.active ? 1 : 0);
    mix(element.hardFeature ? 1 : 0);
    mix(element.boundary ? 1 : 0);
    mix(element.basinRoot ? 1 : 0);
    mix(element.rootLabelProtected ? 1 : 0);
    mix(element.singularityProtected ? 1 : 0);
    mix(element.handleCritical ? 1 : 0);
  }
  return hash;
}

inline std::uint64_t complex_structural_hash(const SurfaceCellComplex &complex) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  mix(static_cast<int>(complex.nodes.size()));
  mix(static_cast<int>(complex.halfedges.size()));
  mix(static_cast<int>(complex.cells.size()));
  for (const SurfaceArrangementNode &node : complex.nodes) {
    mix(node.id);
    mix(node.sourceFace);
    mix(node.sourceEdge);
    mix(static_cast<std::int64_t>(
        std::llround(node.sourceEdgeParameter * 1.0e10)));
    for (int i = 0; i < 3; ++i) {
      mix(static_cast<std::int64_t>(std::llround(node.barycentric[i] * 1.0e10)));
    }
    mix(static_cast<int>(node.occurrences.size()));
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      mix(occurrence.sourceFace);
      for (int i = 0; i < 3; ++i) {
        mix(static_cast<std::int64_t>(
            std::llround(occurrence.barycentric[i] * 1.0e10)));
      }
    }
  }
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    mix(halfedge.id);
    mix(halfedge.twin);
    mix(halfedge.next);
    mix(halfedge.from);
    mix(halfedge.to);
    mix(halfedge.sourceArc);
    mix(halfedge.family);
    mix(halfedge.strand);
    mix(halfedge.featureClass);
    mix(halfedge.sourceFace);
    mix(static_cast<std::int64_t>(std::llround(halfedge.sourceT0 * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(halfedge.sourceT1 * 1.0e10)));
    mix(halfedge.hardFeature ? 1 : 0);
    mix(halfedge.sourceSheet);
    mix(halfedge.proposalId);
    mix(halfedge.proposalSeedId);
    mix(halfedge.proposalSide);
    mix(halfedge.proposalBoundarySegment);
    mix(static_cast<int>(halfedge.provenance.size()));
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      mix(value.sourceArc);
      mix(value.provenance);
      mix(value.sourceFace);
      mix(value.family);
      mix(value.strand);
      mix(value.featureClass);
      mix(value.hardFeature ? 1 : 0);
      mix(value.railId);
      mix(value.curveId);
      mix(value.sourceComponent);
      mix(value.sourceSheet);
      mix(value.proposalId);
      mix(value.proposalSeedId);
      mix(value.proposalSide);
      mix(value.proposalBoundarySegment);
      mix(static_cast<std::int64_t>(std::llround(value.sourceT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.sourceT1 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.railT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.railT1 * 1.0e10)));
    }
    mix(halfedge.cell);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    mix(cell.id);
    mix(cell.sourceFace);
    mix(static_cast<int>(cell.cellClass));
    mix(static_cast<int>(cell.rejectReason));
    mix(cell.disk ? 1 : 0);
    mix(cell.quadReady ? 1 : 0);
    for (const int halfedge : cell.halfedges) {
      mix(halfedge);
    }
    for (const int family : cell.sideFamilies) {
      mix(family);
    }
  }
  return hash;
}

inline int active_count(const std::vector<SurfaceSimplificationElement> &elements) {
  return static_cast<int>(std::count_if(
      elements.begin(), elements.end(),
      [](const SurfaceSimplificationElement &element) { return element.active; }));
}

inline double objective_cost(
    const SurfaceSimplificationCandidate &candidate,
    const SurfaceSimplificationObjectiveWeights &weights) {
  if (candidate.changesTopology) {
    return std::numeric_limits<double>::infinity();
  }
  return weights.surface * candidate.deltaSurface +
         weights.normal * candidate.deltaNormal +
         weights.field * candidate.deltaField +
         weights.size * candidate.deltaSize +
         weights.quad * candidate.deltaQuad +
         weights.feature * candidate.featurePenalty +
         weights.topology * candidate.topologyPenalty;
}

struct QueueEntry {
  double cost = 0.0;
  SurfaceSimplificationCandidateType type =
      SurfaceSimplificationCandidateType::OpenStrip;
  int stableId = -1;
  int index = -1;

  bool operator<(const QueueEntry &other) const {
    if (std::abs(cost - other.cost) > 1.0e-14) {
      return cost > other.cost;
    }
    if (type != other.type) {
      return static_cast<int>(type) > static_cast<int>(other.type);
    }
    return stableId > other.stableId;
  }
};

inline SurfaceSimplificationRejectionReason validate_candidate(
    const SurfaceSimplificationCandidate &candidate,
    const std::vector<SurfaceSimplificationElement> &elements,
    const SurfaceSimplificationOptions &options, const double cost) {
  if (candidate.invalidated) {
    return SurfaceSimplificationRejectionReason::StaleCandidate;
  }
  if (candidate.changesTopology || !std::isfinite(cost)) {
    return SurfaceSimplificationRejectionReason::TopologyChanged;
  }
  if (!candidate.affectedPatchDisk) {
    return SurfaceSimplificationRejectionReason::NonDiskPatch;
  }
  if (!candidate.sideFeasible) {
    return SurfaceSimplificationRejectionReason::PatchInfeasible;
  }
  if (candidate.descriptivenessWorsening >
      options.maxDescriptivenessWorsening + 1.0e-14) {
    return SurfaceSimplificationRejectionReason::DescriptivenessWorsened;
  }
  if (cost > options.objectiveTolerance + 1.0e-14) {
    return SurfaceSimplificationRejectionReason::ObjectiveWorsened;
  }
  for (const int elementId : candidate.elementIds) {
    if (elementId < 0 || elementId >= static_cast<int>(elements.size()) ||
        !elements[static_cast<std::size_t>(elementId)].active) {
      return SurfaceSimplificationRejectionReason::StaleCandidate;
    }
    const SurfaceSimplificationElement &element =
        elements[static_cast<std::size_t>(elementId)];
    if (element.hardFeature) {
      return SurfaceSimplificationRejectionReason::ProtectedFeature;
    }
    if (element.boundary) {
      return SurfaceSimplificationRejectionReason::ProtectedBoundary;
    }
    if (element.basinRoot || element.rootLabelProtected) {
      return SurfaceSimplificationRejectionReason::ProtectedRoot;
    }
    if (element.singularityProtected) {
      return SurfaceSimplificationRejectionReason::ProtectedSingularity;
    }
    if (element.handleCritical) {
      return SurfaceSimplificationRejectionReason::TopologyChanged;
    }
  }
  return SurfaceSimplificationRejectionReason::None;
}

inline bool validate_complex_incidence(const SurfaceCellComplex &complex) {
  for (int i = 0; i < static_cast<int>(complex.nodes.size()); ++i) {
    if (complex.nodes[static_cast<std::size_t>(i)].id != i) {
      return false;
    }
  }
  for (int i = 0; i < static_cast<int>(complex.halfedges.size()); ++i) {
    const SurfaceArrangementHalfedge &h =
        complex.halfedges[static_cast<std::size_t>(i)];
    if (h.id != i || h.twin < 0 ||
        h.twin >= static_cast<int>(complex.halfedges.size()) || h.from < 0 ||
        h.from >= static_cast<int>(complex.nodes.size()) || h.to < 0 ||
        h.to >= static_cast<int>(complex.nodes.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(h.twin)];
    if (twin.twin != i || twin.from != h.to || twin.to != h.from) {
      return false;
    }
  }
  for (int i = 0; i < static_cast<int>(complex.cells.size()); ++i) {
    const SurfaceArrangementCell &cell =
        complex.cells[static_cast<std::size_t>(i)];
    if (cell.id != i) {
      return false;
    }
    std::set<int> seen;
    for (const int halfedge : cell.halfedges) {
      if (halfedge < 0 ||
          halfedge >= static_cast<int>(complex.halfedges.size()) ||
          seen.count(halfedge) != 0) {
        return false;
      }
      seen.insert(halfedge);
    }
  }
  return true;
}

inline SurfaceCellComplex rebuild_complex_after_halfedge_removal(
    const SurfaceCellComplex &complex, const std::set<int> &removeHalfedges) {
  SurfaceCellComplex rebuilt = complex;
  rebuilt.halfedges.clear();
  std::vector<int> oldToNew(complex.halfedges.size(), -1);
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (removeHalfedges.count(halfedge.id) != 0 ||
        removeHalfedges.count(halfedge.twin) != 0) {
      continue;
    }
    oldToNew[static_cast<std::size_t>(halfedge.id)] =
        static_cast<int>(rebuilt.halfedges.size());
    rebuilt.halfedges.push_back(halfedge);
  }
  for (SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    halfedge.id = oldToNew[static_cast<std::size_t>(halfedge.id)];
    halfedge.twin = halfedge.twin >= 0
                        ? oldToNew[static_cast<std::size_t>(halfedge.twin)]
                        : -1;
    halfedge.next = halfedge.next >= 0
                        ? oldToNew[static_cast<std::size_t>(halfedge.next)]
                        : -1;
    halfedge.cell = -1;
  }
  std::vector<SurfaceArrangementCell> rebuiltCells;
  for (SurfaceArrangementCell cell : complex.cells) {
    std::vector<int> halfedges;
    std::vector<int> families;
    halfedges.reserve(cell.halfedges.size());
    families.reserve(cell.sideFamilies.size());
    for (const int oldHalfedge : cell.halfedges) {
      if (oldHalfedge < 0 ||
          oldHalfedge >= static_cast<int>(oldToNew.size()) ||
          oldToNew[static_cast<std::size_t>(oldHalfedge)] < 0) {
        continue;
      }
      const int newHalfedge = oldToNew[static_cast<std::size_t>(oldHalfedge)];
      halfedges.push_back(newHalfedge);
      families.push_back(
          rebuilt.halfedges[static_cast<std::size_t>(newHalfedge)].family);
    }
    if (halfedges.size() < 3) {
      continue;
    }
    cell.id = static_cast<int>(rebuiltCells.size());
    cell.halfedges = std::move(halfedges);
    cell.sideFamilies = std::move(families);
    cell.sideEdgeCounts.assign(cell.sideFamilies.size(), 1);
    cell.disk = cell.disk && cell.halfedges.size() >= 3;
    cell.quadReady = cell.disk && cell.sideFamilies.size() == 4;
    cell.cellClass = cell.quadReady ? SurfaceArrangementCellClass::RegularQuad
                                    : SurfaceArrangementCellClass::PatchCandidate;
    rebuiltCells.push_back(std::move(cell));
  }
  rebuilt.cells = std::move(rebuiltCells);
  for (SurfaceArrangementCell &cell : rebuilt.cells) {
    for (const int halfedge : cell.halfedges) {
      rebuilt.halfedges[static_cast<std::size_t>(halfedge)].cell = cell.id;
    }
  }
  return rebuilt;
}

inline std::vector<SurfaceSimplificationCandidate> recompute_overlap_candidates(
    const SurfaceCellComplex &complex, const std::set<int> &affectedNodes,
    const int nextStableBase) {
  std::vector<SurfaceSimplificationCandidate> recomputed;
  std::set<int> usedHalfedges;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.hardFeature ||
        halfedge.family < 0 ||
        (affectedNodes.count(halfedge.from) == 0 &&
         affectedNodes.count(halfedge.to) == 0)) {
      continue;
    }
    if (usedHalfedges.count(halfedge.id) != 0 ||
        usedHalfedges.count(halfedge.twin) != 0) {
      continue;
    }
    usedHalfedges.insert(halfedge.id);
    usedHalfedges.insert(halfedge.twin);
    SurfaceSimplificationCandidate candidate;
    candidate.stableId = nextStableBase + static_cast<int>(recomputed.size());
    candidate.type = SurfaceSimplificationCandidateType::RedundantStrand;
    candidate.elementIds = {halfedge.id};
    candidate.deltaSurface = -0.25;
    recomputed.push_back(std::move(candidate));
  }
  return recomputed;
}

} // namespace surface_simplification_detail

inline std::vector<SurfaceSimplificationElement>
make_simplification_elements_from_complex(const SurfaceCellComplex &complex) {
  std::vector<SurfaceSimplificationElement> elements;
  elements.reserve(complex.halfedges.size());
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin) {
      continue;
    }
    SurfaceSimplificationElement element;
    element.id = static_cast<int>(elements.size());
    element.cellOrHalfedge = halfedge.id;
    element.hardFeature = halfedge.hardFeature;
    element.boundary = halfedge.family < 0;
    element.length = std::abs(halfedge.sourceT1 - halfedge.sourceT0);
    elements.push_back(element);
  }
  return elements;
}

inline SurfaceSimplificationCandidate make_removal_candidate(
    const int stableId, const SurfaceSimplificationCandidateType type,
    std::vector<int> elementIds, const double cost = -1.0) {
  SurfaceSimplificationCandidate candidate;
  candidate.stableId = stableId;
  candidate.type = type;
  candidate.elementIds = std::move(elementIds);
  candidate.deltaSurface = cost;
  return candidate;
}

inline SurfaceSimplificationResult simplify_surface_complex(
    std::vector<SurfaceSimplificationElement> elements,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {}) {
  using namespace surface_simplification_detail;
  SurfaceSimplificationResult result;
  result.initialActiveElements = active_count(elements);

  std::priority_queue<QueueEntry> queue;
  for (int i = 0; i < static_cast<int>(candidates.size()); ++i) {
    const double cost = objective_cost(candidates[static_cast<std::size_t>(i)],
                                       options.weights);
    queue.push({cost, candidates[static_cast<std::size_t>(i)].type,
                candidates[static_cast<std::size_t>(i)].stableId, i});
  }

  while (!queue.empty()) {
    if (options.targetActiveElements > 0 &&
        active_count(elements) <= options.targetActiveElements) {
      break;
    }
    const QueueEntry entry = queue.top();
    queue.pop();
    ++result.empiricalWork;
    SurfaceSimplificationCandidate &candidate =
        candidates[static_cast<std::size_t>(entry.index)];
    const double cost = objective_cost(candidate, options.weights);
    SurfaceSimplificationTransaction transaction;
    transaction.candidateId = candidate.stableId;
    transaction.type = candidate.type;
    transaction.objectiveCost = cost;
    transaction.beforeHash = structural_hash(elements);
    const SurfaceSimplificationRejectionReason rejection =
        validate_candidate(candidate, elements, options, cost);
    if (rejection == SurfaceSimplificationRejectionReason::None) {
      std::vector<SurfaceSimplificationElement> trial = elements;
      for (const int elementId : candidate.elementIds) {
        trial[static_cast<std::size_t>(elementId)].active = false;
      }
      elements = std::move(trial);
      transaction.committed = true;
      transaction.rejection = SurfaceSimplificationRejectionReason::None;
      transaction.afterHash = structural_hash(elements);
      ++result.committed;

      std::set<int> removed(candidate.elementIds.begin(),
                            candidate.elementIds.end());
      for (SurfaceSimplificationCandidate &other : candidates) {
        if (other.stableId == candidate.stableId || other.invalidated) {
          continue;
        }
        for (const int elementId : other.elementIds) {
          if (removed.count(elementId) != 0) {
            other.invalidated = true;
            ++result.invalidatedCandidates;
            ++result.recomputedCandidates;
            break;
          }
        }
      }
    } else {
      transaction.committed = false;
      transaction.rejection = rejection;
      transaction.afterHash = structural_hash(elements);
      ++result.rejected;
    }
    result.transactions.push_back(transaction);
  }

  result.elements = std::move(elements);
  result.finalActiveElements = active_count(result.elements);
  result.finalHash = structural_hash(result.elements);
  return result;
}

inline SurfaceSimplificationResult simplify_surface_cell_complex(
    const SurfaceCellComplex &inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {}) {
  using namespace surface_simplification_detail;
  SurfaceSimplificationResult result;
  result.hasComplexOutput = true;
  SurfaceCellComplex complex = inputComplex;
  result.initialActiveElements =
      static_cast<int>(complex.halfedges.size()) / 2;

  std::priority_queue<QueueEntry> queue;
  for (int i = 0; i < static_cast<int>(candidates.size()); ++i) {
    const double cost = objective_cost(candidates[static_cast<std::size_t>(i)],
                                       options.weights);
    queue.push({cost, candidates[static_cast<std::size_t>(i)].type,
                candidates[static_cast<std::size_t>(i)].stableId, i});
  }

  int nextStableBase = 1000000;
  while (!queue.empty()) {
    if (options.targetActiveElements > 0 &&
        static_cast<int>(complex.halfedges.size()) / 2 <=
            options.targetActiveElements) {
      break;
    }
    const QueueEntry entry = queue.top();
    queue.pop();
    ++result.empiricalWork;
    if (entry.index < 0 || entry.index >= static_cast<int>(candidates.size())) {
      continue;
    }
    SurfaceSimplificationCandidate &candidate =
        candidates[static_cast<std::size_t>(entry.index)];
    const double cost = objective_cost(candidate, options.weights);
    SurfaceSimplificationTransaction transaction;
    transaction.candidateId = candidate.stableId;
    transaction.type = candidate.type;
    transaction.objectiveCost = cost;
    transaction.beforeHash = complex_structural_hash(complex);

    std::set<int> removeHalfedges;
    std::set<int> affectedNodes;
    SurfaceSimplificationRejectionReason rejection =
        candidate.invalidated ? SurfaceSimplificationRejectionReason::StaleCandidate
                              : SurfaceSimplificationRejectionReason::None;
    if (candidate.changesTopology || !std::isfinite(cost)) {
      rejection = SurfaceSimplificationRejectionReason::TopologyChanged;
    } else if (!candidate.affectedPatchDisk) {
      rejection = SurfaceSimplificationRejectionReason::NonDiskPatch;
    } else if (!candidate.sideFeasible) {
      rejection = SurfaceSimplificationRejectionReason::PatchInfeasible;
    } else if (candidate.descriptivenessWorsening >
               options.maxDescriptivenessWorsening + 1.0e-14) {
      rejection = SurfaceSimplificationRejectionReason::DescriptivenessWorsened;
    } else if (cost > options.objectiveTolerance + 1.0e-14) {
      rejection = SurfaceSimplificationRejectionReason::ObjectiveWorsened;
    }

    if (rejection == SurfaceSimplificationRejectionReason::None) {
      for (const int halfedgeId : candidate.elementIds) {
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(complex.halfedges.size())) {
          rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
          break;
        }
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        if (halfedge.hardFeature) {
          rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
          break;
        }
        if (halfedge.family < 0) {
          rejection = SurfaceSimplificationRejectionReason::ProtectedBoundary;
          break;
        }
        removeHalfedges.insert(halfedge.id);
        removeHalfedges.insert(halfedge.twin);
        affectedNodes.insert(halfedge.from);
        affectedNodes.insert(halfedge.to);
      }
    }

    if (rejection == SurfaceSimplificationRejectionReason::None) {
      SurfaceCellComplex trial =
          rebuild_complex_after_halfedge_removal(complex, removeHalfedges);
      ++result.incidenceRebuilds;
      if (!validate_complex_incidence(trial)) {
        rejection = SurfaceSimplificationRejectionReason::TopologyChanged;
      } else {
        ++result.validationPasses;
        complex = std::move(trial);
        transaction.committed = true;
        transaction.afterHash = complex_structural_hash(complex);
        ++result.committed;

        for (SurfaceSimplificationCandidate &other : candidates) {
          if (other.stableId == candidate.stableId || other.invalidated) {
            continue;
          }
          for (const int halfedgeId : other.elementIds) {
            if (removeHalfedges.count(halfedgeId) != 0) {
              other.invalidated = true;
              ++result.invalidatedCandidates;
              break;
            }
          }
        }
        std::vector<SurfaceSimplificationCandidate> recomputed =
            recompute_overlap_candidates(complex, affectedNodes, nextStableBase);
        nextStableBase += 1000;
        for (SurfaceSimplificationCandidate &recomputedCandidate : recomputed) {
          const int index = static_cast<int>(candidates.size());
          const double recomputedCost =
              objective_cost(recomputedCandidate, options.weights);
          queue.push({recomputedCost, recomputedCandidate.type,
                      recomputedCandidate.stableId, index});
          candidates.push_back(std::move(recomputedCandidate));
          ++result.recomputedCandidates;
        }
      }
    }

    if (rejection != SurfaceSimplificationRejectionReason::None) {
      transaction.committed = false;
      transaction.rejection = rejection;
      transaction.afterHash = complex_structural_hash(complex);
      ++result.rejected;
    }
    result.transactions.push_back(transaction);
  }

  result.complex = std::move(complex);
  result.finalActiveElements =
      static_cast<int>(result.complex.halfedges.size()) / 2;
  result.finalHash = complex_structural_hash(result.complex);
  return result;
}

inline SurfaceSimplificationOverlay
make_surface_simplification_overlay(const SurfaceSimplificationResult &result) {
  SurfaceSimplificationOverlay overlay;
  const int transactionCount = static_cast<int>(result.transactions.size());
  overlay.candidateType.resize(transactionCount);
  overlay.retained.resize(static_cast<int>(result.elements.size()));
  overlay.removed.resize(static_cast<int>(result.elements.size()));
  overlay.rejectionReason.resize(transactionCount);
  overlay.objectiveCost.resize(transactionCount);
  for (int i = 0; i < transactionCount; ++i) {
    const SurfaceSimplificationTransaction &transaction =
        result.transactions[static_cast<std::size_t>(i)];
    overlay.candidateType(i) = static_cast<int>(transaction.type);
    overlay.rejectionReason(i) = static_cast<int>(transaction.rejection);
    overlay.objectiveCost(i) = transaction.objectiveCost;
  }
  for (int i = 0; i < static_cast<int>(result.elements.size()); ++i) {
    const bool active = result.elements[static_cast<std::size_t>(i)].active;
    overlay.retained(i) = active ? 1 : 0;
    overlay.removed(i) = active ? 0 : 1;
  }
  return overlay;
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H
