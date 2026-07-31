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
#include <map>
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
  RegionCollapse = 5,
  PoleRelocation = 6,
  TransitionRemoval = 7,
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
  // Canonical arrangement halfedge IDs. Each undirected edge is represented
  // by the lower of the two twin IDs.
  std::vector<int> elementIds;
  std::vector<int> affectedNodeIds;
  std::vector<int> affectedCellIds;
  std::vector<int> affectedStrandIds;
  bool touchesHardFeature = false;
  bool touchesBoundary = false;
  bool touchesSingularity = false;
  bool touchesLocalSheetBoundary = false;
  double removedLength = 0.0;
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

struct SurfaceSimplificationCandidateExtractionOptions {
  // Do not emit candidates whose complete support is smaller than this.
  int minimumElements = 1;
  // Candidate extraction is intentionally conservative at authoritative rails.
  bool includeProtectedCandidatesForDiagnostics = true;
  // A chain with matching end nodes is classified as a closed loop.
  bool classifyClosedLoops = true;
};

struct SurfaceSimplificationCandidateSet {
  std::vector<SurfaceSimplificationCandidate> candidates;
  int protectedCandidates = 0;
  int openStripCandidates = 0;
  int closedLoopCandidates = 0;
  int redundantStrandCandidates = 0;
  int regionCandidates = 0;
  int poleCandidates = 0;
  int transitionCandidates = 0;
  std::uint64_t structuralHash = 0;
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

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
bool element_protected(const SurfaceSimplificationElement &element) {
  return element.hardFeature || element.boundary || element.basinRoot ||
         element.rootLabelProtected || element.singularityProtected;
}
#else
bool element_protected(const SurfaceSimplificationElement &element);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
std::uint64_t structural_hash(
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
#else
std::uint64_t structural_hash(
    const std::vector<SurfaceSimplificationElement> &elements);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
std::uint64_t complex_structural_hash(const SurfaceCellComplex &complex) {
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
    mix(node.hardBarrierCrossing ? 1 : 0);
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
    mix(halfedge.railId);
    mix(halfedge.curveId);
    mix(halfedge.sourceComponent);
    mix(halfedge.sourceSheet);
    mix(halfedge.proposalId);
    mix(halfedge.proposalSeedId);
    mix(halfedge.proposalSide);
    mix(halfedge.proposalBoundarySegment);
    mix(static_cast<std::int64_t>(std::llround(halfedge.railT0 * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(halfedge.railT1 * 1.0e10)));
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
    for (const int sourceFace : cell.sourceFaces) {
      mix(sourceFace);
    }
    mix(static_cast<int>(cell.cellClass));
    mix(static_cast<int>(cell.rejectReason));
    mix(cell.closed ? 1 : 0);
    mix(cell.boundaryCycle ? 1 : 0);
    mix(cell.disk ? 1 : 0);
    mix(cell.boundaryComponentCount);
    mix(cell.eulerCharacteristic);
    mix(cell.quadReady ? 1 : 0);
    mix(static_cast<std::int64_t>(std::llround(cell.signedArea * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(cell.area * 1.0e10)));
    for (const int halfedge : cell.halfedges) {
      mix(halfedge);
    }
    for (const int family : cell.sideFamilies) {
      mix(family);
    }
    for (const int count : cell.sideEdgeCounts) {
      mix(count);
    }
  }
  mix(complex.diagnostics.eulerCharacteristic);
  mix(complex.diagnostics.connectedComponentCount);
  mix(complex.diagnostics.boundaryLoopCount);
  mix(complex.diagnostics.incidenceValid ? 1 : 0);
  mix(complex.diagnostics.embeddingValid ? 1 : 0);
  mix(complex.diagnostics.orientationValid ? 1 : 0);
  mix(complex.diagnostics.cellsDiskValid ? 1 : 0);
  mix(complex.diagnostics.boundaryLoopsValid ? 1 : 0);
  mix(complex.diagnostics.eulerCharacteristicValid ? 1 : 0);
  mix(complex.diagnostics.topologyValid ? 1 : 0);
  return hash;
}
#else
std::uint64_t complex_structural_hash(const SurfaceCellComplex &complex);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
int active_count(const std::vector<SurfaceSimplificationElement> &elements) {
  return static_cast<int>(std::count_if(
      elements.begin(), elements.end(),
      [](const SurfaceSimplificationElement &element) { return element.active; }));
}
#else
int active_count(const std::vector<SurfaceSimplificationElement> &elements);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
double objective_cost(
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
#else
double objective_cost(
    const SurfaceSimplificationCandidate &candidate,
    const SurfaceSimplificationObjectiveWeights &weights);
#endif

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

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationRejectionReason validate_candidate(
    const SurfaceSimplificationCandidate &candidate,
    const std::vector<SurfaceSimplificationElement> &elements,
    const SurfaceSimplificationOptions &options, const double cost) {
  if (candidate.invalidated) {
    return SurfaceSimplificationRejectionReason::StaleCandidate;
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
  return SurfaceSimplificationRejectionReason::None;
}
#else
SurfaceSimplificationRejectionReason validate_candidate(
    const SurfaceSimplificationCandidate &candidate,
    const std::vector<SurfaceSimplificationElement> &elements,
    const SurfaceSimplificationOptions &options, const double cost);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
bool validate_complex_incidence(const SurfaceCellComplex &complex) {
  for (int i = 0; i < static_cast<int>(complex.nodes.size()); ++i) {
    if (complex.nodes[static_cast<std::size_t>(i)].id != i) {
      return false;
    }
  }
  std::vector<int> halfedgeUse(complex.halfedges.size(), 0);
  for (int i = 0; i < static_cast<int>(complex.halfedges.size()); ++i) {
    const SurfaceArrangementHalfedge &halfedge =
        complex.halfedges[static_cast<std::size_t>(i)];
    if (halfedge.id != i || halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size()) ||
        halfedge.next < 0 ||
        halfedge.next >= static_cast<int>(complex.halfedges.size()) ||
        halfedge.from < 0 ||
        halfedge.from >= static_cast<int>(complex.nodes.size()) ||
        halfedge.to < 0 || halfedge.to >= static_cast<int>(complex.nodes.size()) ||
        halfedge.from == halfedge.to || halfedge.cell < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (twin.twin != i || twin.from != halfedge.to ||
        twin.to != halfedge.from) {
      return false;
    }
  }
  for (int i = 0; i < static_cast<int>(complex.cells.size()); ++i) {
    const SurfaceArrangementCell &cell = complex.cells[static_cast<std::size_t>(i)];
    if (cell.id != i || !cell.closed || cell.halfedges.size() < 3U) {
      return false;
    }
    if (!cell.boundaryCycle &&
        (!cell.disk || cell.boundaryComponentCount != 1 ||
         cell.eulerCharacteristic != 1)) {
      return false;
    }
    if (cell.sideFamilies.size() != cell.sideEdgeCounts.size()) {
      return false;
    }
    std::set<int> seen;
    for (std::size_t j = 0; j < cell.halfedges.size(); ++j) {
      const int halfedgeId = cell.halfedges[j];
      if (halfedgeId < 0 ||
          halfedgeId >= static_cast<int>(complex.halfedges.size()) ||
          !seen.insert(halfedgeId).second) {
        return false;
      }
      const SurfaceArrangementHalfedge &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      const int expectedNext =
          cell.halfedges[(j + 1U) % cell.halfedges.size()];
      if (halfedge.cell != i || halfedge.next != expectedNext ||
          halfedge.to !=
              complex.halfedges[static_cast<std::size_t>(expectedNext)].from) {
        return false;
      }
      ++halfedgeUse[static_cast<std::size_t>(halfedgeId)];
    }
  }
  return std::all_of(halfedgeUse.begin(), halfedgeUse.end(),
                     [](const int count) { return count == 1; });
}
#else
bool validate_complex_incidence(const SurfaceCellComplex &complex);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
std::vector<std::int64_t> protected_node_signature(
    const SurfaceArrangementNode &node) {
  std::vector<std::int64_t> signature;
  signature.push_back(static_cast<std::int64_t>(node.occurrences.size()));
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    signature.push_back(occurrence.sourceFace);
    for (int i = 0; i < 3; ++i) {
      signature.push_back(static_cast<std::int64_t>(
          std::llround(occurrence.barycentric[i] * 1.0e10)));
    }
  }
  return signature;
}
#else
std::vector<std::int64_t> protected_node_signature(
    const SurfaceArrangementNode &node);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
std::multiset<std::vector<std::int64_t>> protected_support(
    const SurfaceCellComplex &complex) {
  std::multiset<std::vector<std::int64_t>> keys;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin ||
        (!halfedge.hardFeature && halfedge.family >= 0)) {
      continue;
    }
    if (halfedge.from < 0 || halfedge.to < 0 ||
        halfedge.from >= static_cast<int>(complex.nodes.size()) ||
        halfedge.to >= static_cast<int>(complex.nodes.size())) {
      keys.insert({std::numeric_limits<std::int64_t>::min()});
      continue;
    }
    std::vector<std::int64_t> from = protected_node_signature(
        complex.nodes[static_cast<std::size_t>(halfedge.from)]);
    std::vector<std::int64_t> to = protected_node_signature(
        complex.nodes[static_cast<std::size_t>(halfedge.to)]);
    if (to < from) {
      std::swap(from, to);
    }

    std::vector<std::vector<std::int64_t>> provenanceKeys;
    provenanceKeys.reserve(halfedge.provenance.size());
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      const double sourceLo = std::min(value.sourceT0, value.sourceT1);
      const double sourceHi = std::max(value.sourceT0, value.sourceT1);
      const double railLo = std::min(value.railT0, value.railT1);
      const double railHi = std::max(value.railT0, value.railT1);
      provenanceKeys.push_back({
          value.sourceArc,
          value.provenance,
          value.sourceFace,
          value.family,
          value.strand,
          value.featureClass,
          value.hardFeature ? 1 : 0,
          value.railId,
          value.curveId,
          value.sourceComponent,
          value.sourceSheet,
          value.proposalId,
          value.proposalSeedId,
          value.proposalSide,
          value.proposalBoundarySegment,
          static_cast<std::int64_t>(std::llround(sourceLo * 1.0e10)),
          static_cast<std::int64_t>(std::llround(sourceHi * 1.0e10)),
          static_cast<std::int64_t>(std::llround(railLo * 1.0e10)),
          static_cast<std::int64_t>(std::llround(railHi * 1.0e10))});
    }
    std::sort(provenanceKeys.begin(), provenanceKeys.end());

    std::vector<std::int64_t> key = {
        halfedge.hardFeature ? 1 : 0,
        halfedge.family < 0 ? 1 : 0,
        static_cast<std::int64_t>(from.size())};
    key.insert(key.end(), from.begin(), from.end());
    key.push_back(static_cast<std::int64_t>(to.size()));
    key.insert(key.end(), to.begin(), to.end());
    key.push_back(static_cast<std::int64_t>(provenanceKeys.size()));
    for (const auto &provenance : provenanceKeys) {
      key.push_back(static_cast<std::int64_t>(provenance.size()));
      key.insert(key.end(), provenance.begin(), provenance.end());
    }
    keys.insert(std::move(key));
  }
  return keys;
}
#else
std::multiset<std::vector<std::int64_t>> protected_support(
    const SurfaceCellComplex &complex);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
bool same_protected_support(const SurfaceCellComplex &before,
                                   const SurfaceCellComplex &after) {
  return protected_support(before) == protected_support(after);
}
#else
bool same_protected_support(const SurfaceCellComplex &before,
                                   const SurfaceCellComplex &after);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
bool order_boundary_cycle(const SurfaceCellComplex &complex,
                                 const std::vector<int> &input,
                                 std::vector<int> &ordered) {
  if (input.size() < 3) return false;
  std::map<int, std::vector<int>> outgoing;
  for (int hid : input) {
    if (hid < 0 || hid >= static_cast<int>(complex.halfedges.size())) return false;
    outgoing[complex.halfedges[static_cast<std::size_t>(hid)].from].push_back(hid);
  }
  for (auto &[node, ids] : outgoing) {
    std::sort(ids.begin(), ids.end());
    if (ids.size() != 1) return false;
  }
  ordered.clear();
  std::set<int> used;
  int current = *std::min_element(input.begin(), input.end());
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (!used.insert(current).second) return false;
    ordered.push_back(current);
    const int node = complex.halfedges[static_cast<std::size_t>(current)].to;
    const auto it = outgoing.find(node);
    if (it == outgoing.end() || it->second.size() != 1) return false;
    current = it->second.front();
  }
  return current == ordered.front() && used.size() == input.size();
}
#else
bool order_boundary_cycle(const SurfaceCellComplex &complex,
                                 const std::vector<int> &input,
                                 std::vector<int> &ordered);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
void classify_rebuilt_cell_sides(
    SurfaceArrangementCell &cell, const SurfaceCellComplex &complex,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces) {
  cell.sideFamilies.clear();
  cell.sideEdgeCounts.clear();
  for (std::size_t index = 0; index < cell.halfedges.size(); ++index) {
    const SurfaceArrangementHalfedge &current =
        complex.halfedges[static_cast<std::size_t>(cell.halfedges[index])];
    bool continuesPrevious = false;
    if (index > 0U && !cell.sideFamilies.empty() &&
        cell.sideFamilies.back() == current.family) {
      const SurfaceArrangementHalfedge &previous =
          complex.halfedges[static_cast<std::size_t>(
              cell.halfedges[index - 1U])];
      continuesPrevious =
          vertices != nullptr && faces != nullptr
              ? surface_arrangement_detail::same_family_collinear(
                    previous, current, complex.nodes, *vertices, *faces)
              : previous.strand == current.strand;
    }
    if (continuesPrevious) {
      ++cell.sideEdgeCounts.back();
    } else {
      cell.sideFamilies.push_back(current.family);
      cell.sideEdgeCounts.push_back(1);
    }
  }
  if (cell.sideFamilies.size() > 1U &&
      cell.sideFamilies.front() == cell.sideFamilies.back()) {
    const SurfaceArrangementHalfedge &last =
        complex.halfedges[static_cast<std::size_t>(cell.halfedges.back())];
    const SurfaceArrangementHalfedge &first =
        complex.halfedges[static_cast<std::size_t>(cell.halfedges.front())];
    const bool closesSameSide =
        vertices != nullptr && faces != nullptr
            ? surface_arrangement_detail::same_family_collinear(
                  last, first, complex.nodes, *vertices, *faces)
            : last.strand == first.strand;
    if (closesSameSide) {
      cell.sideEdgeCounts.front() += cell.sideEdgeCounts.back();
      cell.sideEdgeCounts.pop_back();
      cell.sideFamilies.pop_back();
    }
  }
  cell.quadReady = !cell.boundaryCycle && cell.disk &&
                   cell.sideFamilies.size() == 4U;
  cell.cellClass = cell.boundaryCycle
                       ? SurfaceArrangementCellClass::Exterior
                       : (cell.quadReady
                              ? SurfaceArrangementCellClass::RegularQuad
                              : SurfaceArrangementCellClass::PatchCandidate);
  cell.rejectReason = cell.quadReady
                          ? SurfaceArrangementRejectReason::None
                          : SurfaceArrangementRejectReason::NotFourSided;
}
#else
void classify_rebuilt_cell_sides(
    SurfaceArrangementCell &cell, const SurfaceCellComplex &complex,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
void recompute_rebuilt_diagnostics(SurfaceCellComplex &complex) {
  const int undirectedEdges = static_cast<int>(complex.halfedges.size()) / 2;
  const int interiorCells = static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(),
      [](const SurfaceArrangementCell &cell) { return !cell.boundaryCycle; }));
  complex.diagnostics.eulerCharacteristic =
      static_cast<int>(complex.nodes.size()) - undirectedEdges + interiorCells;

  std::vector<std::pair<int, int>> arrangementEdges;
  std::vector<std::pair<int, int>> arrangementBoundaryEdges;
  arrangementEdges.reserve(static_cast<std::size_t>(undirectedEdges));
  bool orientationValid = true;
  bool cellsDiskValid = true;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id >= halfedge.twin) {
      continue;
    }
    arrangementEdges.emplace_back(halfedge.from, halfedge.to);
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell >= 0 && twin.cell >= 0 &&
        halfedge.cell < static_cast<int>(complex.cells.size()) &&
        twin.cell < static_cast<int>(complex.cells.size())) {
      const bool leftExterior =
          complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle;
      const bool rightExterior =
          complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle;
      if (leftExterior != rightExterior) {
        arrangementBoundaryEdges.emplace_back(halfedge.from, halfedge.to);
      }
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.boundaryCycle && !cell.disk) {
      cellsDiskValid = false;
    }
    if (cell.boundaryCycle ? !(cell.signedArea < -1.0e-14)
                           : !(cell.signedArea > 1.0e-14)) {
      if (cell.rejectReason != SurfaceArrangementRejectReason::Sliver) {
        orientationValid = false;
      }
    }
  }

  complex.diagnostics.incidenceValid = validate_complex_incidence(complex);
  complex.diagnostics.orientationValid = orientationValid;
  complex.diagnostics.cellsDiskValid = cellsDiskValid;
  complex.diagnostics.connectedComponentCount =
      surface_arrangement_detail::graph_component_count(
          static_cast<int>(complex.nodes.size()), arrangementEdges);
  const auto [boundaryLoops, boundaryValid] =
      surface_arrangement_detail::boundary_loop_count(
          static_cast<int>(complex.nodes.size()), arrangementBoundaryEdges);
  complex.diagnostics.boundaryLoopCount = boundaryLoops;
  complex.diagnostics.boundaryLoopsValid = boundaryValid;
  complex.diagnostics.eulerCharacteristicValid =
      complex.diagnostics.eulerCharacteristic ==
          complex.diagnostics.sourceEulerCharacteristic &&
      complex.diagnostics.connectedComponentCount ==
          complex.diagnostics.sourceConnectedComponentCount &&
      complex.diagnostics.boundaryLoopCount ==
          complex.diagnostics.sourceBoundaryLoopCount &&
      complex.diagnostics.boundaryLoopsValid;
  complex.diagnostics.extractedArea = 0.0;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.boundaryCycle) {
      complex.diagnostics.extractedArea += cell.area;
    }
  }
  complex.diagnostics.relativeAreaError =
      std::abs(complex.diagnostics.extractedArea -
               complex.diagnostics.supportedArea) /
      std::max(1.0e-20, complex.diagnostics.supportedArea);
  complex.diagnostics.retainedMemoryBytes =
      surface_arrangement_detail::complex_storage_bytes(complex);
  complex.diagnostics.peakMemoryBytes =
      std::max(complex.diagnostics.peakMemoryBytes,
               complex.diagnostics.retainedMemoryBytes);
  complex.diagnostics.measuredMemoryRatio =
      static_cast<double>(complex.diagnostics.peakMemoryBytes) /
      static_cast<double>(
          std::max<std::uint64_t>(1U, complex.diagnostics.inputMemoryBytes));
  complex.diagnostics.memoryRatioEstimate =
      complex.diagnostics.measuredMemoryRatio;
  complex.diagnostics.topologyValid =
      complex.diagnostics.incidenceValid &&
      complex.diagnostics.embeddingValid &&
      complex.diagnostics.orientationValid &&
      complex.diagnostics.cellsDiskValid &&
      complex.diagnostics.boundaryLoopsValid &&
      complex.diagnostics.eulerCharacteristicValid &&
      complex.diagnostics.unsplitCrossings == 0 &&
      complex.diagnostics.geometricTJunctions == 0;
}
#else
void recompute_rebuilt_diagnostics(SurfaceCellComplex &complex);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceCellComplex rebuild_complex_after_halfedge_removal(
    const SurfaceCellComplex &complex, const std::set<int> &requestedRemoval,
    const Eigen::MatrixXd *vertices = nullptr,
    const Eigen::MatrixXi *faces = nullptr) {
  SurfaceCellComplex invalid;
  if (requestedRemoval.empty()) return invalid;

  std::set<int> removeHalfedges;
  std::map<int, std::set<int>> mergeAdjacency;
  std::set<int> affectedCells;
  std::set<int> canonicalRequested;
  for (const int halfedgeId : requestedRemoval) {
    if (halfedgeId < 0 ||
        halfedgeId >= static_cast<int>(complex.halfedges.size())) {
      return invalid;
    }
    const SurfaceArrangementHalfedge &halfedge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    if (halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size())) {
      return invalid;
    }
    canonicalRequested.insert(std::min(halfedge.id, halfedge.twin));
  }

  for (const int canonical : canonicalRequested) {
    const SurfaceArrangementHalfedge &halfedge =
        complex.halfedges[static_cast<std::size_t>(canonical)];
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell < 0 || twin.cell < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size()) ||
        twin.cell >= static_cast<int>(complex.cells.size()) ||
        halfedge.cell == twin.cell ||
        complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle ||
        complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle) {
      return invalid;
    }
    removeHalfedges.insert(halfedge.id);
    removeHalfedges.insert(halfedge.twin);
    affectedCells.insert(halfedge.cell);
    affectedCells.insert(twin.cell);
    mergeAdjacency[halfedge.cell].insert(twin.cell);
    mergeAdjacency[twin.cell].insert(halfedge.cell);
  }
  if (affectedCells.empty()) return invalid;

  std::vector<std::vector<int>> mergeComponents;
  std::set<int> visitedCells;
  for (const int seed : affectedCells) {
    if (!visitedCells.insert(seed).second) continue;
    std::vector<int> component;
    std::queue<int> queue;
    queue.push(seed);
    while (!queue.empty()) {
      const int cell = queue.front();
      queue.pop();
      component.push_back(cell);
      for (const int neighbor : mergeAdjacency[cell]) {
        if (visitedCells.insert(neighbor).second) queue.push(neighbor);
      }
    }
    std::sort(component.begin(), component.end());
    if (component.size() < 2U) return invalid;
    mergeComponents.push_back(std::move(component));
  }
  std::sort(mergeComponents.begin(), mergeComponents.end(),
            [](const auto &a, const auto &b) { return a.front() < b.front(); });

  std::map<int, int> componentOfCell;
  for (int component = 0;
       component < static_cast<int>(mergeComponents.size()); ++component) {
    for (const int cell : mergeComponents[static_cast<std::size_t>(component)]) {
      componentOfCell[cell] = component;
    }
  }

  // An unselected edge may remain between two different merge regions, but an
  // edge internal to one merged region would become an orphan/self-adjacency.
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.cell < 0) continue;
    const int twinCell =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell;
    const auto left = componentOfCell.find(halfedge.cell);
    const auto right = componentOfCell.find(twinCell);
    if (halfedge.cell != twinCell && left != componentOfCell.end() &&
        right != componentOfCell.end() && left->second == right->second &&
        removeHalfedges.count(halfedge.id) == 0) {
      return invalid;
    }
  }

  struct CellRecord {
    SurfaceArrangementCell cell;
    std::vector<int> oldBoundary;
    bool merged = false;
  };
  std::vector<CellRecord> records;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (affectedCells.count(cell.id) == 0) {
      records.push_back({cell, cell.halfedges, false});
    }
  }

  for (const std::vector<int> &mergeComponent : mergeComponents) {
    const std::set<int> componentCells(mergeComponent.begin(),
                                       mergeComponent.end());
    std::vector<int> mergedBoundary;
    for (const int cellId : mergeComponent) {
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      for (const int halfedgeId : cell.halfedges) {
        if (removeHalfedges.count(halfedgeId) != 0) continue;
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        const int twinCell =
            halfedge.twin >= 0
                ? complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell
                : -1;
        if (componentCells.count(twinCell) == 0) {
          mergedBoundary.push_back(halfedgeId);
        }
      }
    }
    std::vector<int> orderedBoundary;
    if (!order_boundary_cycle(complex, mergedBoundary, orderedBoundary)) {
      return invalid;
    }

    SurfaceArrangementCell mergedCell;
    mergedCell.boundaryCycle = false;
    mergedCell.closed = true;
    mergedCell.disk = true;
    mergedCell.boundaryComponentCount = 1;
    mergedCell.eulerCharacteristic = 1;
    std::set<int> mergedSourceFaces;
    double fallbackArea = 0.0;
    for (const int cellId : mergeComponent) {
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      fallbackArea += cell.area;
      mergedSourceFaces.insert(cell.sourceFaces.begin(), cell.sourceFaces.end());
      if (cell.sourceFace >= 0) mergedSourceFaces.insert(cell.sourceFace);
    }
    mergedCell.sourceFaces.assign(mergedSourceFaces.begin(),
                                  mergedSourceFaces.end());
    mergedCell.sourceFace = mergedCell.sourceFaces.empty()
                                ? -1
                                : mergedCell.sourceFaces.front();
    mergedCell.area = fallbackArea;
    mergedCell.signedArea = fallbackArea;
    records.push_back(
        {std::move(mergedCell), std::move(orderedBoundary), true});
  }

  SurfaceCellComplex rebuilt = complex;
  std::vector<int> oldToNew(complex.halfedges.size(), -1);
  rebuilt.halfedges.clear();
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (removeHalfedges.count(halfedge.id) != 0) continue;
    oldToNew[static_cast<std::size_t>(halfedge.id)] =
        static_cast<int>(rebuilt.halfedges.size());
    rebuilt.halfedges.push_back(halfedge);
  }
  for (SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    const int oldId = halfedge.id;
    halfedge.id = oldToNew[static_cast<std::size_t>(oldId)];
    halfedge.twin = oldToNew[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.id < 0 || halfedge.twin < 0) return invalid;
    halfedge.next = -1;
    halfedge.cell = -1;
  }

  rebuilt.cells.clear();
  std::vector<unsigned char> rebuiltCellWasMerged;
  for (CellRecord &record : records) {
    SurfaceArrangementCell cell = std::move(record.cell);
    cell.id = static_cast<int>(rebuilt.cells.size());
    cell.halfedges.clear();
    for (const int oldHalfedgeId : record.oldBoundary) {
      if (oldHalfedgeId < 0 ||
          oldHalfedgeId >= static_cast<int>(oldToNew.size())) {
        return invalid;
      }
      const int newHalfedgeId = oldToNew[static_cast<std::size_t>(oldHalfedgeId)];
      if (newHalfedgeId < 0) return invalid;
      cell.halfedges.push_back(newHalfedgeId);
    }
    rebuiltCellWasMerged.push_back(record.merged ? 1U : 0U);
    rebuilt.cells.push_back(std::move(cell));
  }
  for (SurfaceArrangementCell &cell : rebuilt.cells) {
    for (std::size_t index = 0; index < cell.halfedges.size(); ++index) {
      SurfaceArrangementHalfedge &halfedge =
          rebuilt.halfedges[static_cast<std::size_t>(cell.halfedges[index])];
      if (halfedge.cell >= 0) return invalid;
      halfedge.cell = cell.id;
      halfedge.next = cell.halfedges[(index + 1U) % cell.halfedges.size()];
    }
  }

  std::vector<int> nodeUse(rebuilt.nodes.size(), 0);
  for (const SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    if (halfedge.from < 0 || halfedge.to < 0 ||
        halfedge.from >= static_cast<int>(nodeUse.size()) ||
        halfedge.to >= static_cast<int>(nodeUse.size())) {
      return invalid;
    }
    ++nodeUse[static_cast<std::size_t>(halfedge.from)];
    ++nodeUse[static_cast<std::size_t>(halfedge.to)];
  }
  std::vector<int> nodeMap(rebuilt.nodes.size(), -1);
  std::vector<SurfaceArrangementNode> compactNodes;
  for (std::size_t index = 0; index < rebuilt.nodes.size(); ++index) {
    if (nodeUse[index] == 0) continue;
    nodeMap[index] = static_cast<int>(compactNodes.size());
    SurfaceArrangementNode node = rebuilt.nodes[index];
    node.id = nodeMap[index];
    compactNodes.push_back(std::move(node));
  }
  for (SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    halfedge.from = nodeMap[static_cast<std::size_t>(halfedge.from)];
    halfedge.to = nodeMap[static_cast<std::size_t>(halfedge.to)];
    if (halfedge.from < 0 || halfedge.to < 0) return invalid;
  }
  rebuilt.nodes = std::move(compactNodes);

  for (std::size_t cellIndex = 0; cellIndex < rebuilt.cells.size(); ++cellIndex) {
    if (rebuiltCellWasMerged[cellIndex] == 0U) continue;
    SurfaceArrangementCell &merged = rebuilt.cells[cellIndex];
    if (vertices != nullptr && faces != nullptr) {
      if (!surface_arrangement_detail::polygon_geometry(
              *vertices, *faces, merged.halfedges, rebuilt.halfedges,
              rebuilt.nodes, merged.signedArea, merged.area,
              merged.sourceFaces)) {
        rebuilt.diagnostics.embeddingValid = false;
      }
      merged.sourceFace =
          merged.sourceFaces.empty() ? -1 : merged.sourceFaces.front();
    }
    classify_rebuilt_cell_sides(merged, rebuilt, vertices, faces);
  }
  recompute_rebuilt_diagnostics(rebuilt);
  return rebuilt;
}
#else
SurfaceCellComplex rebuild_complex_after_halfedge_removal(
    const SurfaceCellComplex &complex, const std::set<int> &requestedRemoval,
    const Eigen::MatrixXd *vertices = nullptr,
    const Eigen::MatrixXi *faces = nullptr);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
std::vector<SurfaceSimplificationCandidate> recompute_overlap_candidates(
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
#else
std::vector<SurfaceSimplificationCandidate> recompute_overlap_candidates(
    const SurfaceCellComplex &complex, const std::set<int> &affectedNodes,
    const int nextStableBase);
#endif

} // namespace surface_simplification_detail


#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationCandidateSet
extract_surface_simplification_candidates_impl(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd *vertices,
    const Eigen::MatrixXi *faces,
    const SurfaceSimplificationCandidateExtractionOptions &options) {
  using namespace surface_simplification_detail;
  SurfaceSimplificationCandidateSet result;

  struct EdgeRecord {
    int halfedge = -1;
    int from = -1;
    int to = -1;
    int family = -1;
    int strand = -1;
    std::set<int> sourceSheets;
    bool hardFeature = false;
    bool boundary = false;
    double length = 0.0;
    std::set<int> cells;
  };

  const auto cell_is_exterior = [&](const int cellId) {
    return cellId < 0 || cellId >= static_cast<int>(complex.cells.size()) ||
           complex.cells[static_cast<std::size_t>(cellId)].boundaryCycle;
  };

  std::vector<EdgeRecord> edges;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size())) {
      continue;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    EdgeRecord record;
    record.halfedge = halfedge.id;
    record.from = halfedge.from;
    record.to = halfedge.to;
    record.family = halfedge.family;
    record.strand = halfedge.strand;
    record.hardFeature = halfedge.hardFeature || twin.hardFeature;
    record.boundary = halfedge.family < 0 || twin.family < 0 ||
                      cell_is_exterior(halfedge.cell) ||
                      cell_is_exterior(twin.cell);
    if (halfedge.sourceSheet >= 0) record.sourceSheets.insert(halfedge.sourceSheet);
    if (twin.sourceSheet >= 0) record.sourceSheets.insert(twin.sourceSheet);
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      if (value.sourceSheet >= 0) record.sourceSheets.insert(value.sourceSheet);
    }
    for (const SurfaceArrangementProvenance &value : twin.provenance) {
      if (value.sourceSheet >= 0) record.sourceSheets.insert(value.sourceSheet);
    }
    if (halfedge.cell >= 0) record.cells.insert(halfedge.cell);
    if (twin.cell >= 0) record.cells.insert(twin.cell);

    if (vertices != nullptr && faces != nullptr && record.from >= 0 &&
        record.to >= 0 && record.from < static_cast<int>(complex.nodes.size()) &&
        record.to < static_cast<int>(complex.nodes.size())) {
      const Eigen::RowVector3d from = surface_arrangement_detail::node_position(
          *vertices, *faces,
          complex.nodes[static_cast<std::size_t>(record.from)]);
      const Eigen::RowVector3d to = surface_arrangement_detail::node_position(
          *vertices, *faces,
          complex.nodes[static_cast<std::size_t>(record.to)]);
      record.length = (to - from).norm();
    } else {
      record.length = std::abs(halfedge.sourceT1 - halfedge.sourceT0);
    }
    record.length = std::max(record.length, 1.0e-12);
    edges.push_back(std::move(record));
  }

  std::vector<std::vector<int>> nodeEdges(complex.nodes.size());
  for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
    const EdgeRecord &edge = edges[static_cast<std::size_t>(i)];
    if (edge.from >= 0 && edge.from < static_cast<int>(nodeEdges.size())) {
      nodeEdges[static_cast<std::size_t>(edge.from)].push_back(i);
    }
    if (edge.to >= 0 && edge.to < static_cast<int>(nodeEdges.size())) {
      nodeEdges[static_cast<std::size_t>(edge.to)].push_back(i);
    }
  }

  std::vector<unsigned char> boundaryNode(complex.nodes.size(), 0);
  for (const EdgeRecord &edge : edges) {
    if (!edge.boundary) continue;
    if (edge.from >= 0 && edge.from < static_cast<int>(boundaryNode.size())) {
      boundaryNode[static_cast<std::size_t>(edge.from)] = 1;
    }
    if (edge.to >= 0 && edge.to < static_cast<int>(boundaryNode.size())) {
      boundaryNode[static_cast<std::size_t>(edge.to)] = 1;
    }
  }
  std::vector<unsigned char> singularNode(complex.nodes.size(), 0);
  for (std::size_t node = 0; node < nodeEdges.size(); ++node) {
    if (!boundaryNode[node] && nodeEdges[node].size() != 4U) {
      singularNode[node] = 1;
    }
  }

  auto populate = [&](SurfaceSimplificationCandidate &candidate,
                      const std::vector<int> &edgeIndices) {
    std::set<int> nodes;
    std::set<int> cells;
    std::set<int> strands;
    std::set<int> sheets;
    for (const int edgeIndex : edgeIndices) {
      const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
      candidate.elementIds.push_back(edge.halfedge);
      nodes.insert(edge.from);
      nodes.insert(edge.to);
      cells.insert(edge.cells.begin(), edge.cells.end());
      if (edge.strand >= 0) strands.insert(edge.strand);
      sheets.insert(edge.sourceSheets.begin(), edge.sourceSheets.end());
      candidate.touchesHardFeature =
          candidate.touchesHardFeature || edge.hardFeature;
      candidate.touchesBoundary = candidate.touchesBoundary || edge.boundary;
      candidate.removedLength += edge.length;
    }
    std::sort(candidate.elementIds.begin(), candidate.elementIds.end());
    candidate.elementIds.erase(
        std::unique(candidate.elementIds.begin(), candidate.elementIds.end()),
        candidate.elementIds.end());
    candidate.affectedNodeIds.assign(nodes.begin(), nodes.end());
    candidate.affectedCellIds.assign(cells.begin(), cells.end());
    candidate.affectedStrandIds.assign(strands.begin(), strands.end());
    candidate.touchesLocalSheetBoundary = sheets.size() > 1U;
    for (const int node : candidate.affectedNodeIds) {
      if (node >= 0 && node < static_cast<int>(singularNode.size()) &&
          singularNode[static_cast<std::size_t>(node)] != 0U) {
        candidate.touchesSingularity = true;
      }
    }

    candidate.affectedPatchDisk = true;
    candidate.sideFeasible = true;
    for (const int cellId : candidate.affectedCellIds) {
      if (cellId < 0 || cellId >= static_cast<int>(complex.cells.size())) {
        candidate.affectedPatchDisk = false;
        candidate.sideFeasible = false;
        continue;
      }
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      if (cell.boundaryCycle) {
        candidate.touchesBoundary = true;
        continue;
      }
      candidate.affectedPatchDisk = candidate.affectedPatchDisk && cell.disk;
      candidate.sideFeasible = candidate.sideFeasible && cell.closed &&
                               cell.boundaryComponentCount == 1;
    }
    candidate.changesTopology = candidate.touchesLocalSheetBoundary ||
                                candidate.touchesSingularity;
    candidate.deltaSurface = -candidate.removedLength;
    candidate.deltaSize =
        -0.25 * static_cast<double>(candidate.elementIds.size());
    candidate.deltaQuad = candidate.sideFeasible ? -0.1 : 1.0;
    candidate.featurePenalty = candidate.touchesHardFeature ? 1.0e6 : 0.0;
    candidate.topologyPenalty =
        (candidate.touchesBoundary || candidate.changesTopology) ? 1.0e6 : 0.0;
    candidate.descriptivenessWorsening =
        candidate.touchesHardFeature ? 1.0 : 0.0;
  };

  const auto append_candidate = [&](SurfaceSimplificationCandidate candidate) {
    const bool protectedCandidate =
        candidate.touchesHardFeature || candidate.touchesBoundary ||
        candidate.touchesSingularity || candidate.changesTopology;
    if (protectedCandidate &&
        !options.includeProtectedCandidatesForDiagnostics) {
      return;
    }
    switch (candidate.type) {
    case SurfaceSimplificationCandidateType::OpenStrip:
      ++result.openStripCandidates;
      break;
    case SurfaceSimplificationCandidateType::ClosedLoop:
      ++result.closedLoopCandidates;
      break;
    case SurfaceSimplificationCandidateType::RedundantStrand:
      ++result.redundantStrandCandidates;
      break;
    case SurfaceSimplificationCandidateType::RegionCollapse:
      ++result.regionCandidates;
      break;
    case SurfaceSimplificationCandidateType::PoleRelocation:
      ++result.poleCandidates;
      break;
    case SurfaceSimplificationCandidateType::TransitionRemoval:
      ++result.transitionCandidates;
      break;
    default:
      break;
    }
    if (protectedCandidate) ++result.protectedCandidates;
    result.candidates.push_back(std::move(candidate));
  };

  std::map<std::pair<int, int>, std::vector<int>> grouped;
  for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
    const EdgeRecord &edge = edges[static_cast<std::size_t>(i)];
    if (edge.family >= 0) grouped[{edge.family, edge.strand}].push_back(i);
  }

  int stableId = 0;
  for (const auto &[key, group] : grouped) {
    (void)key;
    const std::set<int> groupSet(group.begin(), group.end());
    std::set<int> visited;
    for (const int seed : group) {
      if (!visited.insert(seed).second) continue;
      std::vector<int> component;
      std::queue<int> queue;
      queue.push(seed);
      while (!queue.empty()) {
        const int current = queue.front();
        queue.pop();
        component.push_back(current);
        const EdgeRecord &edge = edges[static_cast<std::size_t>(current)];
        for (const int node : {edge.from, edge.to}) {
          if (node < 0 || node >= static_cast<int>(nodeEdges.size())) continue;
          for (const int neighbor : nodeEdges[static_cast<std::size_t>(node)]) {
            if (groupSet.count(neighbor) != 0 &&
                visited.insert(neighbor).second) {
              queue.push(neighbor);
            }
          }
        }
      }
      std::sort(component.begin(), component.end(),
                [&](const int a, const int b) {
                  return edges[static_cast<std::size_t>(a)].halfedge <
                         edges[static_cast<std::size_t>(b)].halfedge;
                });
      if (static_cast<int>(component.size()) < options.minimumElements) {
        continue;
      }

      std::map<int, int> degree;
      for (const int edgeIndex : component) {
        const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
        ++degree[edge.from];
        ++degree[edge.to];
      }
      const int degreeOne = static_cast<int>(std::count_if(
          degree.begin(), degree.end(),
          [](const auto &entry) { return entry.second == 1; }));
      const bool allDegreeAtMostTwo = std::all_of(
          degree.begin(), degree.end(),
          [](const auto &entry) { return entry.second == 1 || entry.second == 2; });
      const bool closed = options.classifyClosedLoops && !component.empty() &&
                          std::all_of(degree.begin(), degree.end(),
                                      [](const auto &entry) {
                                        return entry.second == 2;
                                      });
      const bool open = allDegreeAtMostTwo && degreeOne == 2;

      SurfaceSimplificationCandidate candidate;
      candidate.stableId = stableId++;
      candidate.type = closed
                           ? SurfaceSimplificationCandidateType::ClosedLoop
                           : (open
                                  ? SurfaceSimplificationCandidateType::OpenStrip
                                  : SurfaceSimplificationCandidateType::RegionCollapse);
      populate(candidate, component);
      if (!closed && !open) {
        candidate.sideFeasible = false;
        candidate.changesTopology = true;
        candidate.topologyPenalty = 1.0e6;
      }
      append_candidate(std::move(candidate));

      if (component.size() > 1U) {
        SurfaceSimplificationCandidate redundant;
        redundant.stableId = stableId++;
        redundant.type = SurfaceSimplificationCandidateType::RedundantStrand;
        populate(redundant, component);
        if (!closed && !open) {
          redundant.sideFeasible = false;
          redundant.changesTopology = true;
          redundant.topologyPenalty = 1.0e6;
        }
        append_candidate(std::move(redundant));
      }
    }
  }

  std::sort(result.candidates.begin(), result.candidates.end(),
            [](const SurfaceSimplificationCandidate &a,
               const SurfaceSimplificationCandidate &b) {
              if (a.type != b.type) {
                return static_cast<int>(a.type) < static_cast<int>(b.type);
              }
              if (a.elementIds != b.elementIds) return a.elementIds < b.elementIds;
              return a.stableId < b.stableId;
            });
  for (int i = 0; i < static_cast<int>(result.candidates.size()); ++i) {
    result.candidates[static_cast<std::size_t>(i)].stableId = i;
  }

  std::uint64_t hash = complex_structural_hash(complex);
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  for (const SurfaceSimplificationCandidate &candidate : result.candidates) {
    mix(candidate.stableId);
    mix(static_cast<int>(candidate.type));
    for (const int value : candidate.elementIds) mix(value);
    for (const int value : candidate.affectedNodeIds) mix(value);
    for (const int value : candidate.affectedCellIds) mix(value);
    mix(candidate.touchesHardFeature ? 1 : 0);
    mix(candidate.touchesBoundary ? 1 : 0);
    mix(candidate.touchesSingularity ? 1 : 0);
    mix(candidate.touchesLocalSheetBoundary ? 1 : 0);
    mix(candidate.changesTopology ? 1 : 0);
    mix(candidate.sideFeasible ? 1 : 0);
    mix(static_cast<std::int64_t>(std::llround(candidate.removedLength * 1.0e10)));
  }
  result.structuralHash = hash;
  return result;
}
#else
SurfaceSimplificationCandidateSet
extract_surface_simplification_candidates_impl(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd *vertices,
    const Eigen::MatrixXi *faces,
    const SurfaceSimplificationCandidateExtractionOptions &options);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceSimplificationCandidateExtractionOptions &options = {}) {
  return extract_surface_simplification_candidates_impl(complex, nullptr, nullptr,
                                                         options);
}
#else
SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceSimplificationCandidateExtractionOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    const SurfaceSimplificationCandidateExtractionOptions &options = {}) {
  return extract_surface_simplification_candidates_impl(complex, &vertices, &faces,
                                                         options);
}
#else
SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    const SurfaceSimplificationCandidateExtractionOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
std::vector<SurfaceSimplificationElement>
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
#else
std::vector<SurfaceSimplificationElement>
make_simplification_elements_from_complex(const SurfaceCellComplex &complex);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationCandidate make_removal_candidate(
    const int stableId, const SurfaceSimplificationCandidateType type,
    std::vector<int> elementIds, const double cost = -1.0) {
  SurfaceSimplificationCandidate candidate;
  candidate.stableId = stableId;
  candidate.type = type;
  candidate.elementIds = std::move(elementIds);
  candidate.deltaSurface = cost;
  return candidate;
}
#else
SurfaceSimplificationCandidate make_removal_candidate(
    const int stableId, const SurfaceSimplificationCandidateType type,
    std::vector<int> elementIds, const double cost = -1.0);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationResult simplify_surface_complex(
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
#else
SurfaceSimplificationResult simplify_surface_complex(
    std::vector<SurfaceSimplificationElement> elements,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationResult simplify_surface_cell_complex_impl(
    const SurfaceCellComplex &inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces,
    const SurfaceSimplificationOptions &options) {
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
    SurfaceSimplificationRejectionReason rejection =
        SurfaceSimplificationRejectionReason::None;
    if (candidate.invalidated) {
      rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
    } else if (candidate.touchesHardFeature) {
      rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
    } else if (candidate.touchesBoundary) {
      rejection = SurfaceSimplificationRejectionReason::ProtectedBoundary;
    } else if (candidate.touchesSingularity) {
      rejection = SurfaceSimplificationRejectionReason::ProtectedSingularity;
    } else if (candidate.touchesLocalSheetBoundary || candidate.changesTopology ||
               !std::isfinite(cost)) {
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
      if (candidate.elementIds.empty()) {
        rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
      }
      for (const int halfedgeId : candidate.elementIds) {
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(complex.halfedges.size())) {
          rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
          break;
        }
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        if (halfedge.twin < 0 ||
            halfedge.twin >= static_cast<int>(complex.halfedges.size()) ||
            halfedge.id > halfedge.twin ||
            !removeHalfedges.insert(halfedge.id).second) {
          rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
          break;
        }
        const SurfaceArrangementHalfedge &twin =
            complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
        if (halfedge.hardFeature || twin.hardFeature) {
          rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
          break;
        }
        const bool boundary =
            halfedge.family < 0 || twin.family < 0 || halfedge.cell < 0 ||
            twin.cell < 0 ||
            halfedge.cell >= static_cast<int>(complex.cells.size()) ||
            twin.cell >= static_cast<int>(complex.cells.size()) ||
            complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle ||
            complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle;
        if (boundary) {
          rejection = SurfaceSimplificationRejectionReason::ProtectedBoundary;
          break;
        }
        removeHalfedges.insert(halfedge.twin);
      }
    }

    if (rejection == SurfaceSimplificationRejectionReason::None) {
      SurfaceCellComplex trial = rebuild_complex_after_halfedge_removal(
          complex, removeHalfedges, vertices, faces);
      ++result.incidenceRebuilds;
      if (!validate_complex_incidence(trial) ||
          !trial.diagnostics.topologyValid) {
        rejection = SurfaceSimplificationRejectionReason::TopologyChanged;
      } else if (!same_protected_support(complex, trial)) {
        rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
      } else {
        ++result.validationPasses;
        complex = std::move(trial);
        transaction.committed = true;
        transaction.rejection = SurfaceSimplificationRejectionReason::None;
        transaction.afterHash = complex_structural_hash(complex);
        ++result.committed;

        for (SurfaceSimplificationCandidate &other : candidates) {
          if (other.stableId == candidate.stableId || other.invalidated) {
            continue;
          }
          other.invalidated = true;
          ++result.invalidatedCandidates;
        }
        const SurfaceSimplificationCandidateSet refreshed =
            vertices != nullptr && faces != nullptr
                ? extract_surface_simplification_candidates(
                      complex, *vertices, *faces)
                : extract_surface_simplification_candidates(complex);
        for (SurfaceSimplificationCandidate recomputedCandidate :
             refreshed.candidates) {
          recomputedCandidate.stableId = nextStableBase++;
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
#else
SurfaceSimplificationResult simplify_surface_cell_complex_impl(
    const SurfaceCellComplex &inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces,
    const SurfaceSimplificationOptions &options);
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationResult simplify_surface_cell_complex(
    const SurfaceCellComplex &inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {}) {
  return simplify_surface_cell_complex_impl(inputComplex, std::move(candidates),
                                             nullptr, nullptr, options);
}
#else
SurfaceSimplificationResult simplify_surface_cell_complex(
    const SurfaceCellComplex &inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationResult simplify_surface_cell_complex(
    const SurfaceCellComplex &inputComplex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {}) {
  return simplify_surface_cell_complex_impl(inputComplex, std::move(candidates),
                                             &vertices, &faces, options);
}
#else
SurfaceSimplificationResult simplify_surface_cell_complex(
    const SurfaceCellComplex &inputComplex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options = {});
#endif

#if defined(DIRECTIONAL_SURFACE_COMPLEX_SIMPLIFICATION_IMPLEMENTATION)
SurfaceSimplificationOverlay
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
#else
SurfaceSimplificationOverlay
make_surface_simplification_overlay(const SurfaceSimplificationResult &result);
#endif

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_COMPLEX_SIMPLIFICATION_H
