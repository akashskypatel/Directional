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
  std::vector<SurfaceSimplificationTransaction> transactions;
  int committed = 0;
  int rejected = 0;
  int invalidatedCandidates = 0;
  int recomputedCandidates = 0;
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
