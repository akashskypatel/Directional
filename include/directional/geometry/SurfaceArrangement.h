// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H
#define DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/SurfaceCellOwnership.h>
#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::geometry {

enum class SurfaceArrangementCellClass : int {
  Exterior = 0,
  RegularQuad = 1,
  PatchCandidate = 2,
  NonDisk = 3,
};

enum class SurfaceArrangementRejectReason : int {
  None = 0,
  NonAlternatingFamilies = 1,
  NotFourSided = 2,
  OddBoundaryParity = 3,
  HardFeatureCrossing = 4,
  Sliver = 5,
};

enum class SurfaceArrangementIncidenceFailure : int {
  None = 0,
  SourceTransitionUnavailable = 1,
  MissingWedge = 2,
  AmbiguousWedge = 3,
  AmbiguousRayOrder = 4,
  InvalidTwin = 5,
  MissingSuccessor = 6,
  DuplicatePredecessor = 7,
  EndpointDiscontinuity = 8,
  IncompletePermutation = 9,
  RepeatedHalfedgeCycle = 10,
  RepeatedNodeCycle = 11,
  RepeatedEdgeCycle = 12,
  ShortCycle = 13,
  NonManifoldSourceEdge = 14,
  ContradictoryBoundarySide = 15,
  BoundaryLoopOwnerCount = 16,
  BoundaryCoverageGap = 17,
  BoundaryCoverageOverlap = 18,
  BoundaryContinuationDiscontinuity = 19,
  BoundaryAliasConflict = 20,
  BoundaryLocalPermutationConflict = 21,
  BoundaryRotationalSystemConflict = 22,
  BoundaryFanSectorCoverConflict = 23,
};

inline const char *surface_arrangement_incidence_failure_name(
    const SurfaceArrangementIncidenceFailure failure) {
  switch (failure) {
  case SurfaceArrangementIncidenceFailure::None:
    return "None";
  case SurfaceArrangementIncidenceFailure::SourceTransitionUnavailable:
    return "SourceTransitionUnavailable";
  case SurfaceArrangementIncidenceFailure::MissingWedge:
    return "MissingWedge";
  case SurfaceArrangementIncidenceFailure::AmbiguousWedge:
    return "AmbiguousWedge";
  case SurfaceArrangementIncidenceFailure::AmbiguousRayOrder:
    return "AmbiguousRayOrder";
  case SurfaceArrangementIncidenceFailure::InvalidTwin:
    return "InvalidTwin";
  case SurfaceArrangementIncidenceFailure::MissingSuccessor:
    return "MissingSuccessor";
  case SurfaceArrangementIncidenceFailure::DuplicatePredecessor:
    return "DuplicatePredecessor";
  case SurfaceArrangementIncidenceFailure::EndpointDiscontinuity:
    return "EndpointDiscontinuity";
  case SurfaceArrangementIncidenceFailure::IncompletePermutation:
    return "IncompletePermutation";
  case SurfaceArrangementIncidenceFailure::RepeatedHalfedgeCycle:
    return "RepeatedHalfedgeCycle";
  case SurfaceArrangementIncidenceFailure::RepeatedNodeCycle:
    return "RepeatedNodeCycle";
  case SurfaceArrangementIncidenceFailure::RepeatedEdgeCycle:
    return "RepeatedEdgeCycle";
  case SurfaceArrangementIncidenceFailure::ShortCycle:
    return "ShortCycle";
  case SurfaceArrangementIncidenceFailure::NonManifoldSourceEdge:
    return "NonManifoldSourceEdge";
  case SurfaceArrangementIncidenceFailure::ContradictoryBoundarySide:
    return "ContradictoryBoundarySide";
  case SurfaceArrangementIncidenceFailure::BoundaryLoopOwnerCount:
    return "BoundaryLoopOwnerCount";
  case SurfaceArrangementIncidenceFailure::BoundaryCoverageGap:
    return "BoundaryCoverageGap";
  case SurfaceArrangementIncidenceFailure::BoundaryCoverageOverlap:
    return "BoundaryCoverageOverlap";
  case SurfaceArrangementIncidenceFailure::BoundaryContinuationDiscontinuity:
    return "BoundaryContinuationDiscontinuity";
  case SurfaceArrangementIncidenceFailure::BoundaryAliasConflict:
    return "BoundaryAliasConflict";
  case SurfaceArrangementIncidenceFailure::BoundaryLocalPermutationConflict:
    return "BoundaryLocalPermutationConflict";
  case SurfaceArrangementIncidenceFailure::BoundaryRotationalSystemConflict:
    return "BoundaryRotationalSystemConflict";
  case SurfaceArrangementIncidenceFailure::BoundaryFanSectorCoverConflict:
    return "BoundaryFanSectorCoverConflict";
  }
  return "Unknown";
}

enum class SurfaceArrangementBoundaryFanConflict : int {
  None = 0,
  MissingCanonicalPair = 1,
  ExteriorPairMismatch = 2,
  ZeroChartWitness = 3,
  MultipleChartWitnesses = 4,
  NormalizedChartEntityMismatch = 5,
  TransitionRootMismatch = 6,
  ConflictingDuplicateWitnessScores = 7,
  InvalidOrientedInterval = 8,
  IncompleteIncomingTargetCover = 9,
  HardRailSeparatorOrOrbitConflict = 10,
};

enum class SurfaceArrangementIntervalFailure : int {
  None = 0,
  MissingFanIdentity = 1,
  MissingIdentityWedge = 2,
  MissingDirectedProvenance = 3,
  MissingChartWitness = 4,
  EntityMismatch = 5,
  RootMismatch = 6,
  NoAdmissibleLift = 7,
  MultipleAdmissibleLifts = 8,
  NonIntegralLiftTurn = 9,
  DuplicateLiftedAngle = 10,
  MissingSourceRay = 11,
  MissingTargetRay = 12,
  ReverseLiftedOrder = 13,
  NonAdjacentLiftedPair = 14,
  ThirdRayIntrusion = 15,
  InvalidLiftTurnDifference = 16,
  NonPositiveSpan = 17,
  SpanOutsideWedge = 18,
  IdentityIntervalConflict = 19,
};

inline const char *surface_arrangement_boundary_fan_conflict_name(
    const SurfaceArrangementBoundaryFanConflict conflict) {
  switch (conflict) {
  case SurfaceArrangementBoundaryFanConflict::None:
    return "None";
  case SurfaceArrangementBoundaryFanConflict::MissingCanonicalPair:
    return "MissingCanonicalPair";
  case SurfaceArrangementBoundaryFanConflict::ExteriorPairMismatch:
    return "ExteriorPairMismatch";
  case SurfaceArrangementBoundaryFanConflict::ZeroChartWitness:
    return "ZeroChartWitness";
  case SurfaceArrangementBoundaryFanConflict::MultipleChartWitnesses:
    return "MultipleChartWitnesses";
  case SurfaceArrangementBoundaryFanConflict::NormalizedChartEntityMismatch:
    return "NormalizedChartEntityMismatch";
  case SurfaceArrangementBoundaryFanConflict::TransitionRootMismatch:
    return "TransitionRootMismatch";
  case SurfaceArrangementBoundaryFanConflict::ConflictingDuplicateWitnessScores:
    return "ConflictingDuplicateWitnessScores";
  case SurfaceArrangementBoundaryFanConflict::InvalidOrientedInterval:
    return "InvalidOrientedInterval";
  case SurfaceArrangementBoundaryFanConflict::IncompleteIncomingTargetCover:
    return "IncompleteIncomingTargetCover";
  case SurfaceArrangementBoundaryFanConflict::HardRailSeparatorOrOrbitConflict:
    return "HardRailSeparatorOrOrbitConflict";
  }
  return "Unknown";
}

inline const char *surface_arrangement_interval_failure_name(
    const SurfaceArrangementIntervalFailure failure) {
  switch (failure) {
  case SurfaceArrangementIntervalFailure::None:
    return "None";
  case SurfaceArrangementIntervalFailure::MissingFanIdentity:
    return "MissingFanIdentity";
  case SurfaceArrangementIntervalFailure::MissingIdentityWedge:
    return "MissingIdentityWedge";
  case SurfaceArrangementIntervalFailure::MissingDirectedProvenance:
    return "MissingDirectedProvenance";
  case SurfaceArrangementIntervalFailure::MissingChartWitness:
    return "MissingChartWitness";
  case SurfaceArrangementIntervalFailure::EntityMismatch:
    return "EntityMismatch";
  case SurfaceArrangementIntervalFailure::RootMismatch:
    return "RootMismatch";
  case SurfaceArrangementIntervalFailure::NoAdmissibleLift:
    return "NoAdmissibleLift";
  case SurfaceArrangementIntervalFailure::MultipleAdmissibleLifts:
    return "MultipleAdmissibleLifts";
  case SurfaceArrangementIntervalFailure::NonIntegralLiftTurn:
    return "NonIntegralLiftTurn";
  case SurfaceArrangementIntervalFailure::DuplicateLiftedAngle:
    return "DuplicateLiftedAngle";
  case SurfaceArrangementIntervalFailure::MissingSourceRay:
    return "MissingSourceRay";
  case SurfaceArrangementIntervalFailure::MissingTargetRay:
    return "MissingTargetRay";
  case SurfaceArrangementIntervalFailure::ReverseLiftedOrder:
    return "ReverseLiftedOrder";
  case SurfaceArrangementIntervalFailure::NonAdjacentLiftedPair:
    return "NonAdjacentLiftedPair";
  case SurfaceArrangementIntervalFailure::ThirdRayIntrusion:
    return "ThirdRayIntrusion";
  case SurfaceArrangementIntervalFailure::InvalidLiftTurnDifference:
    return "InvalidLiftTurnDifference";
  case SurfaceArrangementIntervalFailure::NonPositiveSpan:
    return "NonPositiveSpan";
  case SurfaceArrangementIntervalFailure::SpanOutsideWedge:
    return "SpanOutsideWedge";
  case SurfaceArrangementIntervalFailure::IdentityIntervalConflict:
    return "IdentityIntervalConflict";
  }
  return "Unknown";
}

struct SurfaceArrangementOptions {
  bool insertBoundaryRails = true;
  /// Use complete proposal cycles as authoritative directed cell incidence.
  /// This bypasses fan-sector inference for the phase-front producer path.
  bool useAuthoritativeProposalCycles = false;
  std::set<authority::SourceEdgeTopologyKey> hardFeatureEdges;
  const SourceTopologyRegions *sourceAuthority = nullptr;
};

struct SurfaceArrangementArc {
  int id = -1;
  int sourceFace = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  int family = 0;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  int provenance = -1;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<SourceProjectionChart> sourceChart;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  bool layoutSupport = false;
  bool singularitySupport = false;
};

struct SurfaceArrangementNodeOccurrence {
  int sourceFace = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  // Exact source-chart scope. Edge-interior arrangement nodes may be shared
  // geometrically by two source sheets, so the node-level primary chart is
  // not sufficient to select an oriented halfedge endpoint.
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<SourceProjectionChart> sourceChart;
  int sourceArc = -1;
  int provenance = -1;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 0.0;
  double railT0 = 0.0;
  double railT1 = 0.0;
};

struct SurfaceArrangementProvenance {
  int sourceArc = -1;
  int provenance = -1;
  int sourceFace = -1;
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  bool layoutSupport = false;
  bool singularitySupport = false;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<SourceProjectionChart> sourceChart;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
  double railT0 = 0.0;
  double railT1 = 1.0;
};

struct SurfaceArrangementNode {
  int id = -1;
  int sourceFace = -1;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<SourceProjectionChart> sourceChart;
  bool hardBarrierCrossing = false;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  int sourceEdge = -1;
  double sourceEdgeParameter = 0.0;
  std::vector<SurfaceArrangementNodeOccurrence> occurrences;
};

struct SurfaceArrangementHalfedge {
  int id = -1;
  int twin = -1;
  int next = -1;
  int from = -1;
  int to = -1;
  int sourceArc = -1;
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  int sourceFace = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
  bool hardFeature = false;
  bool layoutSupport = false;
  bool singularitySupport = false;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<SourceProjectionChart> sourceChart;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  // Exact transition-component root proven for the complete directed bounded
  // orbit. This is distinct from the halfedge's full provenance, which may
  // legitimately contain charts from both sides of a hard rail.
  int authoritativeChartRoot = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  std::vector<SurfaceArrangementProvenance> provenance;
  int cell = -1;
};

struct SurfaceArrangementCell {
  int id = -1;
  int sourceFace = -1;
  // Exact ownership scope of the oriented cell.  Source-face support is kept
  // separately because one cell can span many source triangles while still
  // belonging to one connected component and one source sheet.
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<authority::SurfaceCellOwnershipClassId>
      sourceOwnershipClass;
  std::vector<SourceProjectionChart> sourceCharts;
  std::vector<int> sourceFaces;
  std::vector<int> halfedges;
  // Start offsets of each directed boundary cycle in halfedges. A disk has
  // exactly one offset {0}; multiply connected bounded cells retain every
  // boundary cycle explicitly instead of flattening them into one fake walk.
  std::vector<int> boundaryCycleOffsets;
  // Canonical source-boundary loops touched by this arrangement region.
  // IDs are derived from exact source-edge connectivity and are independent
  // of source-face row order, traversal start, and whole-mesh orientation.
  std::vector<int> sourceBoundaryLoopIds;
  // -1 means this region owns the exterior side of every recorded source
  // boundary loop, +1 means it owns the interior side, and 0 means it has no
  // authoritative source-boundary witness.
  int sourceBoundarySide = 0;
  std::vector<int> sideFamilies;
  std::vector<int> sideEdgeCounts;
  double signedArea = 0.0;
  double area = 0.0;
  bool boundaryCycle = false;
  bool closed = false;
  bool disk = false;
  // A cut-cell disk has a complete face-boundary walk whose bridge tree joins
  // two or more simple boundary cores. The bridge is traversed once on each
  // side but is never decomposed after successor construction.
  bool cutCellDisk = false;
  // A bridge excursion is a dangling bridge tree attached to fewer than two
  // simple boundary cores. It remains an explicit non-disk repair candidate
  // and is never decomposed after successor construction.
  bool bridgeExcursion = false;
  // A support-only cycle has no non-bridge boundary core (for example an
  // isolated open layout strand). It remains an explicit non-disk candidate
  // so every directed halfedge has transactional cell ownership.
  bool supportOnlyCycle = false;
  int boundaryComponentCount = 0;
  int eulerCharacteristic = 0;
  bool quadReady = false;
  SurfaceArrangementCellClass cellClass =
      SurfaceArrangementCellClass::PatchCandidate;
  SurfaceArrangementRejectReason rejectReason =
      SurfaceArrangementRejectReason::None;
};

inline bool surface_arrangement_boundary_cycle_ranges(
    const SurfaceArrangementCell &cell,
    std::vector<std::pair<std::size_t, std::size_t>> &ranges) {
  ranges.clear();
  if (cell.halfedges.empty()) {
    return false;
  }
  std::vector<int> offsets = cell.boundaryCycleOffsets;
  if (offsets.empty()) {
    offsets.push_back(0);
  }
  if (offsets.front() != 0) {
    return false;
  }
  for (std::size_t index = 0; index < offsets.size(); ++index) {
    const int begin = offsets[index];
    const int end = index + 1U < offsets.size()
                        ? offsets[index + 1U]
                        : static_cast<int>(cell.halfedges.size());
    if (begin < 0 || end <= begin ||
        end > static_cast<int>(cell.halfedges.size()) ||
        (index > 0U && offsets[index - 1U] >= begin)) {
      ranges.clear();
      return false;
    }
    const int minimum = cell.supportOnlyCycle ? 2 : 3;
    if (end - begin < minimum) {
      ranges.clear();
      return false;
    }
    ranges.emplace_back(static_cast<std::size_t>(begin),
                        static_cast<std::size_t>(end));
  }
  return static_cast<int>(ranges.size()) == cell.boundaryComponentCount ||
         (cell.supportOnlyCycle && ranges.size() == 1U &&
          cell.boundaryComponentCount == 0);
}

struct SurfaceArrangementDiagnostics {
  int plantedIntersections = 0;
  int uniqueIntersections = 0;
  int unsplitCrossings = 0;
  int geometricTJunctions = 0;
  int incompleteArcChains = 0;
  int hardBarrierCrossings = 0;
  int eulerCharacteristic = 0;
  int sourceEulerCharacteristic = 0;
  int connectedComponentCount = 0;
  int sourceConnectedComponentCount = 0;
  int boundaryLoopCount = 0;
  int sourceBoundaryLoopCount = 0;
  int directedWedgeCount = 0;
  int successorMissingCount = 0;
  int successorAmbiguityCount = 0;
  int predecessorMultiplicityFailureCount = 0;
  int repeatedNodeCycleCount = 0;
  int repeatedEdgeCycleCount = 0;
  int boundaryRotationalNodeCount = 0;
  int boundaryDegreeTwoRotationalNodeCount = 0;
  int boundaryFanSectorNodeCount = 0;
  int boundaryCanonicalFanPairCount = 0;
  int boundaryExteriorSectorExclusionCount = 0;
  int boundaryInteriorSectorCount = 0;
  int boundaryHardRailSeparatorCount = 0;
  int boundaryCyclicWrapInteriorSectorCount = 0;
  int boundaryHardRailSidePairCount = 0;
  SurfaceArrangementBoundaryFanConflict boundaryFanConflict =
      SurfaceArrangementBoundaryFanConflict::None;
  int boundaryFanConflictNode = -1;
  int boundaryFanConflictIncoming = -1;
  int boundaryFanConflictSourceRay = -1;
  int boundaryFanConflictTarget = -1;
  SurfaceArrangementIntervalFailure boundaryFanIntervalFailure =
      SurfaceArrangementIntervalFailure::None;
  int boundaryFanIntervalSourceComponent = -1;
  int boundaryFanIntervalSourceFace = -1;
  int boundaryFanIntervalSourceSheet = -1;
  std::vector<std::int64_t> boundaryFanIntervalEntityKey;
  int boundaryFanIntervalTransitionRoot = -1;
  int boundaryFanIntervalIdentityCount = 0;
  int boundaryFanIntervalSourcePosition = -1;
  int boundaryFanIntervalTargetPosition = -1;
  double boundaryFanIntervalSourceRawAngle =
      std::numeric_limits<double>::quiet_NaN();
  double boundaryFanIntervalTargetRawAngle =
      std::numeric_limits<double>::quiet_NaN();
  double boundaryFanIntervalSourceLiftedAngle =
      std::numeric_limits<double>::quiet_NaN();
  double boundaryFanIntervalTargetLiftedAngle =
      std::numeric_limits<double>::quiet_NaN();
  int boundaryFanIntervalSourceLiftTurn = 0;
  int boundaryFanIntervalTargetLiftTurn = 0;
  int boundaryFanIntervalLiftTurnDifference = 0;
  double boundaryFanIntervalWedgeStart =
      std::numeric_limits<double>::quiet_NaN();
  double boundaryFanIntervalWedgeEnd =
      std::numeric_limits<double>::quiet_NaN();
  double boundaryFanIntervalWedgeSpan =
      std::numeric_limits<double>::quiet_NaN();
  int boundaryFanIntervalIntrudingHalfedge = -1;
  SurfaceCellCanonicalIdentity boundaryFanIntervalIdentity;
  SurfaceCellCanonicalIdentity boundaryFanIntervalIntrudingIdentity;
  SurfaceArrangementIncidenceFailure incidenceFailure =
      SurfaceArrangementIncidenceFailure::None;
  int incidenceFailureNode = -1;
  int incidenceFailureHalfedge = -1;
  int incidenceFailureTwin = -1;
  int incidenceFailureNext = -1;
  std::uint64_t directedIncidenceHash = 0U;
  bool incidenceValid = false;
  bool embeddingValid = false;
  bool orientationValid = false;
  bool cellsDiskValid = false;
  bool boundaryLoopsValid = false;
  bool eulerCharacteristicValid = false;
  bool topologyValid = false;
  int peakSegmentsPerFace = 0;
  double supportedArea = 0.0;
  double extractedArea = 0.0;
  double relativeAreaError = 0.0;
  double memoryRatioEstimate = 0.0;
  double measuredMemoryRatio = 0.0;
  std::uint64_t inputMemoryBytes = 0;
  std::uint64_t retainedMemoryBytes = 0;
  std::uint64_t peakMemoryBytes = 0;
};

struct SurfaceCellComplex {
  // Exact canonical ownership memberships are stored once per complex. Cells
  // retain only a fixed-size {component, ordinal} key and their incident chart
  // map, preventing O(cells * component-faces) duplication.
  std::vector<SurfaceCellOwnershipClassRecord> sourceOwnershipRegistry;
  std::vector<SurfaceArrangementNode> nodes;
  std::vector<SurfaceArrangementHalfedge> halfedges;
  std::vector<SurfaceArrangementCell> cells;
  SurfaceArrangementDiagnostics diagnostics;
};

struct SurfaceArrangementOverlay {
  Eigen::MatrixXd splitSegmentStarts;
  Eigen::MatrixXd splitSegmentEnds;
  Eigen::VectorXi sideFamily;
  Eigen::VectorXi cellId;
  Eigen::VectorXi cellClass;
  Eigen::VectorXi sliverCycle;
  Eigen::VectorXi hardRailCrossing;
};

namespace surface_arrangement_detail {

struct Segment2 {
  int sourceArc = -1;
  int provenance = -1;
  int sourceFace = -1;
  Eigen::Vector2d start = Eigen::Vector2d::Zero();
  Eigen::Vector2d end = Eigen::Vector2d::Zero();
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  bool layoutSupport = false;
  bool singularitySupport = false;
  std::optional<authority::HardRailId> railId;
  int curveId = -1;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  std::optional<SourceProjectionChart> sourceChart;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
};

struct NodeKey {
  int kind = 2;
  int face = -1;
  std::optional<authority::SourceEdgeTopologyKey> edge;
  std::int64_t edgeT = -1;
  int vertex = -1;
  std::int64_t u = 0;
  std::int64_t v = 0;

  bool operator<(const NodeKey &other) const {
    return std::tie(kind, vertex, edge, edgeT, face, u, v) <
           std::tie(other.kind, other.vertex, other.edge, other.edgeT,
                    other.face, other.u, other.v);
  }
};

double cross2(const Eigen::Vector2d &a, const Eigen::Vector2d &b);

Eigen::Vector2d bary_to_uv(const Eigen::RowVector3d &bary);

Eigen::RowVector3d uv_to_bary(const Eigen::Vector2d &uv);

double triangle_area_3d(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const int face);

Eigen::RowVector3d face_normal_3d(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &faces,
                                         const int face);

Eigen::RowVector3d barycentric_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int face, const Eigen::RowVector3d &barycentric);

Eigen::RowVector3d node_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceArrangementNode &node);

Eigen::RowVector3d node_barycentric_on_face(
    const SurfaceArrangementNode &node, const int face);

Eigen::RowVector3d node_barycentric_on_face(
    const SurfaceArrangementNode &node, const int face,
    const int component, const int sheet);

Eigen::RowVector3d node_reference_normal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceArrangementNode &node);

bool tangent_basis(const Eigen::RowVector3d &normal,
                          Eigen::RowVector3d &axisX,
                          Eigen::RowVector3d &axisY);

bool polygon_geometry(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &halfedges,
    const std::vector<SurfaceArrangementHalfedge> &allHalfedges,
    const std::vector<SurfaceArrangementNode> &nodes, double &signedArea,
    double &area, std::vector<int> &sourceFaces);

int source_edge(const Eigen::Vector2d &uv, const double eps = 1.0e-10);

Eigen::RowVector3d canonicalize_barycentric(
    const Eigen::RowVector3d &input, const double eps = 1.0e-10);

double local_edge_parameter(const Eigen::Vector2d &uv, const int edge);

double canonical_edge_parameter(const Eigen::MatrixXi &faces,
                                       const int face, const int edge,
                                       const Eigen::Vector2d &uv);

authority::SourceEdgeTopologyKey source_edge_key(
    const Eigen::MatrixXi &faces, const int face, const int edge);

int source_vertex(const Eigen::RowVector3d &bary,
                         const double eps = 1.0e-10);

NodeKey make_node_key(const Eigen::MatrixXi &faces, const int face,
                             const Eigen::Vector2d &uv);


bool clip_to_triangle(Eigen::Vector2d &a, Eigen::Vector2d &b,
                             double &ta, double &tb);

bool segment_intersection_params(const Segment2 &a, const Segment2 &b,
                                        double &ta, double &tb,
                                        Eigen::Vector2d &point);

bool point_on_segment(const Eigen::Vector2d &p, const Segment2 &s);

double polygon_area(const std::vector<Eigen::Vector2d> &points);

bool point_in_polygon(const Eigen::Vector2d &point,
                             const std::vector<Eigen::Vector2d> &polygon);

bool proper_transverse_crossing(const Segment2 &a, const Segment2 &b,
                                       const double ta, const double tb);

std::uint64_t complex_storage_bytes(const SurfaceCellComplex &complex);

int graph_component_count(
    const int vertexCount, const std::vector<std::pair<int, int>> &edges,
    const std::vector<unsigned char> *activeMask = nullptr);

std::pair<int, bool> boundary_loop_count(
    const int vertexCount, const std::vector<std::pair<int, int>> &edges);

int boundary_orientation_vote(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXi &faces,
    const std::map<authority::SourceEdgeTopologyKey, std::array<int, 2>> &edgeFaces);

void collect_cell_source_faces(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    std::vector<int> &sourceFaces);

bool same_family_collinear(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces);

/** Return whether two consecutive halfedges are one logical field line side. */
bool same_logical_side(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces);

} // namespace surface_arrangement_detail


const SurfaceCellOwnershipClassRecord *find_surface_cell_ownership_class(
    const SurfaceCellComplex &complex,
    const std::optional<authority::TopologyRegionId> &sourceRegion,
    const std::optional<authority::SurfaceCellOwnershipClassId> &key);

bool validate_surface_cell_ownership_registry(
    const SurfaceCellComplex &complex);

bool canonicalize_surface_cell_ownership(
    SurfaceCellComplex &complex, const Eigen::MatrixXi &faces);

SurfaceCellComplex build_surface_cell_complex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<SurfaceArrangementArc> &inputArcs,
    const SurfaceArrangementOptions &options = {});

SurfaceArrangementOverlay
make_surface_arrangement_overlay(const SurfaceCellComplex &complex);

std::uint64_t hash_surface_cell_complex(const SurfaceCellComplex &complex);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H
