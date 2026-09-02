// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_GLOBAL_TOPOLOGY_PLAN_H
#define DIRECTIONAL_GEOMETRY_GLOBAL_TOPOLOGY_PLAN_H

#include <cstddef>
#include <cstdint>
#include <optional>
#include <variant>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/AuthorityIds.h>
#include <directional/geometry/SourceTopologyRegions.h>
#include <directional/geometry/RotationSystemDiagnostics.h>
#include <directional/geometry/SurfaceCellTracing.h>
#include <directional/geometry/SurfaceCutGraph.h>

namespace directional::geometry {

enum class GlobalTopologyArcKind : std::uint8_t {
  Mandatory = 0,
  Trace = 1,
  Cut = 2,
};

struct GlobalTopologyOrientedArc {
  authority::NetworkArcId arc;
  authority::Orientation orientation = authority::Orientation::Forward;

  auto operator<=>(const GlobalTopologyOrientedArc &) const = default;
};

/** One exact arc of the A2b embedded graph. */
struct GlobalTopologyArc {
  authority::NetworkArcId id;
  GlobalTopologyArcKind kind = GlobalTopologyArcKind::Mandatory;
  authority::NetworkNodeId firstNode;
  authority::NetworkNodeId secondNode;
  std::optional<authority::NetworkEdgeId> mandatoryEdge;
  std::optional<authority::TraceId> trace;
  std::optional<authority::SourceEdgeTopologyKey> cutEdge;
  std::size_t firstSegment = 0U;
  std::size_t onePastLastSegment = 0U;
  std::vector<authority::SourceFaceTopologyKey> sourceFaces;

  auto operator<=>(const GlobalTopologyArc &) const = default;
};

/** Counter-clockwise exact source-fan order of outgoing arc incidences. */
struct GlobalTopologyNodeRotation {
  authority::NetworkNodeId node;
  std::vector<GlobalTopologyOrientedArc> counterClockwise;

  auto operator<=>(const GlobalTopologyNodeRotation &) const = default;
};

/** One face of the embedded field-aligned network graph. */
struct GlobalTopologyRegion {
  authority::NetworkRegionId id;
  std::vector<GlobalTopologyOrientedArc> boundary;
  // Fragment support. The region boundary identifies the owning graph-face
  // orbit, so each entry denotes one (SourceFaceTopologyKey, orbit) fragment.
  // A source face crossed by traces may therefore occur in multiple regions.
  std::vector<authority::SourceFaceTopologyKey> sourceFaces;

  auto operator<=>(const GlobalTopologyRegion &) const = default;
};

/**
 * Exact per-region CP4b proof.  Conditions 1-3 are the necessary-and-
 * sufficient topological-disc proof; interiorSingularityFree is the separate
 * field-regularity requirement for quadrangulability.
 */
struct GlobalTopologyRegionDiscCertificate {
  explicit GlobalTopologyRegionDiscCertificate(authority::NetworkRegionId regionId)
      : region(regionId) {}

  authority::NetworkRegionId region;
  std::size_t boundaryWalkCount = 0U;
  bool sourceFacesConnected = false;
  int eulerCharacteristic = 0;
  // Number of source vertices strictly interior to the region (V_int).
  // The validated single boundary walk and no-pinch condition make
  // V_boundary == E_boundary, licensing their cancellation from chi.
  std::size_t vertexCount = 0U;
  // Number of interior fragment adjacencies (E_int) in the region dual graph.
  std::size_t edgeCount = 0U;
  // Number of owned (SourceFaceTopologyKey, orbit) fragments (F).
  std::size_t faceCount = 0U;
  bool interiorSingularityFree = false;
  std::vector<authority::FieldSingularityId> boundarySingularities;

  [[nodiscard]] bool proves_disc_topology() const noexcept {
    return boundaryWalkCount == 1U && sourceFacesConnected &&
           eulerCharacteristic == 1;
  }
  [[nodiscard]] bool proves_field_regularity() const noexcept {
    return interiorSingularityFree;
  }

  auto operator<=>(const GlobalTopologyRegionDiscCertificate &) const = default;
};

enum class GlobalTopologyPlanErrorCode : std::uint8_t {
  RegionBoundaryNotSingleWalk = 0,
  RegionInteriorDisconnected = 1,
  RegionEulerCharacteristicNotOne = 2,
  RegionContainsInteriorSingularity = 3,
  RegionCoversNoSourceFace = 4,
  RegionSourceFaceUnowned = 5,
  RegionSourceFaceMultiplyOwned = 6,
  RegionBoundaryArcNotOwnedByNetwork = 7,
  MandatoryEdgeNotOnAnyRegionBoundary = 8,
  RotationSystemInconsistent = 9,
  InvalidNetworkBinding = 10,
  InvalidSourceBinding = 11,
  InvalidRegionCertificateBinding = 12,
  EmbeddedGraphHasNoInteriorFace = 13,
  RegionCutComponentCountDeficit = 14,
  RegionBoundaryEvidenceMissing = 15,
  RegionElectedCutComponentEmpty = 16,
  RegionFragmentPinchedAtVertex = 17,
  MandatoryEdgeTerminalOrderUnresolved = 18,
  RegionOwnedBoundaryEdgeMissingFromWalk = 19,
  TraceArcDoesNotSeparateItsSides = 20,
  SourceFaceCarriesMultipleTraceCuts = 21,
  TraceSegmentCarriersCoincide = 22,
  TraceSegmentTurnNotAdmissible = 23,
  TraceSegmentCarriersShareMultipleCorners = 24,
  TraceSegmentCarriersShareNoCorner = 25,
  SourcePortFaceAlreadyCarriesTraceChord = 26,
  TraceSourcePortCarrierNotAdmissible = 27,
  SourceFaceCarriesTraceChordAndRays = 28,
  RegionTraceSegmentCarriersCoincide = 29,
  RegionTraceSegmentTurnNotAdmissible = 30,
  RegionTraceSourcePortCarrierNotAdmissible = 31,
  TraceCutFaceFragmentCountMismatch = 32,
  UncutFaceComponentOrbitSeedNotUnique = 33,
  SourceFaceFragmentOrbitMissing = 34,
  SourceFaceFragmentOrbitHasNoRegionDraft = 35,
  RegionSourceFaceOwningFragmentMissing = 36,
  RegionInteriorVertexCornerOwnerMissing = 37,
  InvalidCutGraphBinding = 38,
};

enum class RotationSystemInconsistencyReason : std::uint8_t {
  TraceEventPositionInvalid = 0,
  TraceEventPositionNodeConflict = 1,
  EventNodeLocusMissing = 2,
  EventLocusMissingSourceEdge = 3,
  EventLocusSourceEdgeConflict = 4,
  VertexTraceFaceMissingFromFan = 5,
  VertexTracePortOrdinalInvalid = 6,
  EdgeTraceFaceSideInvalid = 7,
  EdgeTraceSecondaryRankInvalid = 8,
  ArcTraceOriginPortMissing = 9,
  ArcTraceSegmentsEmpty = 10,
  ArcTraceTerminalEventMissing = 11,
  ArcTraceTerminalCutPositionMismatch = 12,
  NodeLocusRegistrationMissing = 13,
  NodeLocusSourceVertexConflict = 14,
  RotationNodeOutgoingIncidenceEmpty = 15,
  RotationNodeLocusMissing = 16,
  RotationVertexFanSlotsUnavailable = 17,
  RotationVertexArcBindingMissing = 18,
  RotationVertexMandatoryArcMissingNetworkEdge = 19,
  RotationVertexMandatoryNetworkEdgeMissing = 20,
  RotationVertexSourceEdgeMissingFromFan = 21,
  RotationVertexTraceBindingMissing = 22,
  RotationVertexTraceMissing = 23,
  RotationVertexTraceRayFaceUnavailable = 24,
  RotationEdgeIncidentFacesMissing = 25,
  RotationEdgeIncidentFacesEmpty = 26,
  RotationEdgeSourceFaceMissing = 27,
  RotationEdgeRayCountInvalid = 28,
  RotationEdgeRayValenceInvalid = 29,
  RotationEdgeArcBindingMissing = 30,
  RotationEdgeNonTraceArcRequiresTwoRays = 31,
  RotationEdgeMandatoryArcMissingNetworkEdge = 32,
  RotationEdgeCutArcLocusMismatch = 33,
  RotationEdgeRayEndpointDirectionUnavailable = 34,
  RotationEdgeTraceBindingMissing = 35,
  RotationEdgeTraceMissing = 36,
  RotationNodeLocusUnsupported = 37,
  RotationRayOrderKeyCollision = 38,
  FaceWalkArcSetEmpty = 39,
  FaceWalkNodeRotationEmpty = 40,
  FaceWalkRotationDartOutOfRange = 41,
  FaceWalkSuccessorAlreadyAssigned = 42,
  FaceWalkIncidenceCountInvalid = 43,
  FaceWalkSuccessorMissing = 44,
  FaceWalkCurrentDartOutOfRange = 45,
  FaceWalkOrbitReenteredAtDifferentStart = 46,
  FaceWalkCycleDidNotCloseWithinDartBudget = 47,
  FaceWalkBoundaryEmpty = 48,
  ExteriorBoundaryDartOutOfRange = 49,
  FragmentCornerForwardDartOutOfRange = 50,
  FragmentCornerReverseDartOutOfRange = 51,
  FragmentCornerSourceCornerMismatch = 52,
  FragmentCornerRayOrdinalDuplicate = 53,
  FragmentCornerOrbitChainMismatch = 54,
  MandatoryBoundaryInteriorDartOutOfRange = 55,
  CutBoundaryInteriorDartOutOfRange = 56,
  TraceBoundaryForwardDartOutOfRange = 57,
  TraceBoundaryReverseDartOutOfRange = 58,
  RegionFragmentIncomingDartOutOfRange = 59,
  RegionOrbitMissing = 60,
  CandidateRotationSystemMismatch = 61,
};

enum class TraceEventPositionFailureReason : std::uint8_t {
  NoCarrierMatch = 0,
  AmbiguousCarrierMatch = 1,
};

enum class TraceEventPositionPass : std::uint8_t {
  FaceRestricted = 0,
  WideningFallback = 1,
  SourceEdgeUnavailable = 2,
};

enum class TraceEventPositionCarrierRole : std::uint8_t {
  Incoming = 0,
  Outgoing = 1,
};

struct TraceEventPositionCandidate {
  std::size_t position = 0U;
  std::size_t segmentIndex = 0U;
  authority::SourceEdgeTopologyKey carrier;
  TraceEventPositionCarrierRole carrierRole =
      TraceEventPositionCarrierRole::Incoming;

  auto operator<=>(const TraceEventPositionCandidate &) const = default;
};

struct GlobalTopologyPlanError {
  GlobalTopologyPlanErrorCode code =
      GlobalTopologyPlanErrorCode::InvalidSourceBinding;
  std::optional<authority::NetworkRegionId> region;
  std::optional<authority::NetworkRegionId> secondRegion;
  std::optional<authority::NetworkArcId> arc;
  std::optional<authority::NetworkArcId> secondArc;
  std::optional<authority::NetworkEdgeId> networkEdge;
  std::optional<authority::TraceId> trace;
  std::optional<authority::TraceId> secondTrace;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
  std::optional<authority::SourceFaceTopologyKey> sourceFace;
  std::optional<authority::SourceFaceTopologyKey> secondSourceFace;
  std::optional<authority::FieldSingularityId> singularity;
  std::optional<authority::SourceVertexId> sourceVertex;
  std::optional<int> eulerCharacteristic;
  std::optional<std::size_t> vertexCount;
  std::optional<std::size_t> edgeCount;
  std::optional<std::size_t> faceCount;
  std::optional<RotationSystemInconsistencyReason>
      rotationSystemInconsistencyReason;
  std::optional<std::size_t> traceEventIndex;
  std::optional<TraceEventPositionFailureReason> traceEventPositionFailureReason;
  std::optional<TraceEventPositionPass> traceEventPositionPass;
  std::vector<TraceEventPositionCandidate> traceEventPositionCandidates;
  std::optional<RotationRayOrderDiagnostic> rotationPreviousRay;
  std::optional<RotationRayOrderDiagnostic> rotationCurrentRay;
  RotationRayOrderCensus rotationFanCensus;

  auto operator<=>(const GlobalTopologyPlanError &) const = default;
};

/**
 * Mutable construction snapshot accepted only by the checked publication seam.
 * It is not semantic authority and exists solely for independent tamper tests.
 */
struct GlobalTopologyPlanCandidate {
  std::vector<GlobalTopologyArc> arcs;
  std::vector<GlobalTopologyNodeRotation> rotations;
  std::vector<GlobalTopologyRegion> regions;
  std::vector<GlobalTopologyRegionDiscCertificate> regionCertificates;
  std::uint64_t sourceDigest = 0U;
  std::uint64_t networkDigest = 0U;
  std::uint64_t cutGraphDigest = 0U;
};

class GlobalTopologyPlanBuildResult;

/**
 * Immutable A2b topology-plan authority. CP4a derives the embedded graph's
 * exact rotation system and graph faces. CP4b publishes one checked disc proof
 * and separate field-regularity proof for every emitted region.
 */
class GlobalTopologyPlan {
public:
  [[nodiscard]] static GlobalTopologyPlanBuildResult make(
      const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
      const SourceTopologyRegions &sourceAuthority,
      const FieldAlignedCurveNetwork &network,
      const SurfaceCutGraph &cutGraph);

  [[nodiscard]] static GlobalTopologyPlanBuildResult make_from_candidate(
      const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
      const SourceTopologyRegions &sourceAuthority,
      const FieldAlignedCurveNetwork &network,
      const SurfaceCutGraph &cutGraph,
      GlobalTopologyPlanCandidate candidate);

  [[nodiscard]] const std::vector<GlobalTopologyArc> &arcs() const noexcept {
    return arcs_;
  }
  [[nodiscard]] const std::vector<GlobalTopologyNodeRotation> &
  rotation_system() const noexcept {
    return rotations_;
  }
  [[nodiscard]] const std::vector<GlobalTopologyRegion> &regions() const
      noexcept {
    return regions_;
  }
  [[nodiscard]] const std::vector<GlobalTopologyRegionDiscCertificate> &
  region_certificates() const noexcept {
    return regionCertificates_;
  }

  [[nodiscard]] const GlobalTopologyArc *
  find_arc(authority::NetworkArcId arc) const noexcept;
  [[nodiscard]] const GlobalTopologyNodeRotation *
  find_rotation(authority::NetworkNodeId node) const noexcept;
  [[nodiscard]] const GlobalTopologyRegionDiscCertificate *
  find_region_certificate(authority::NetworkRegionId region) const noexcept;

  [[nodiscard]] GlobalTopologyPlanCandidate validation_candidate() const;
  [[nodiscard]] std::uint64_t source_digest() const noexcept {
    return sourceDigest_;
  }
  [[nodiscard]] std::uint64_t network_digest() const noexcept {
    return networkDigest_;
  }
  [[nodiscard]] std::uint64_t cut_graph_digest() const noexcept {
    return cutGraphDigest_;
  }
  [[nodiscard]] std::uint64_t semantic_digest() const noexcept {
    return semanticDigest_;
  }

private:
  friend class GlobalTopologyPlanBuildResult;

  GlobalTopologyPlan(std::vector<GlobalTopologyArc> arcs,
                     std::vector<GlobalTopologyNodeRotation> rotations,
                     std::vector<GlobalTopologyRegion> regions,
                     std::vector<GlobalTopologyRegionDiscCertificate> regionCertificates,
                     std::uint64_t sourceDigest,
                     std::uint64_t networkDigest,
                     std::uint64_t cutGraphDigest,
                     std::uint64_t semanticDigest)
      : arcs_(std::move(arcs)), rotations_(std::move(rotations)),
        regions_(std::move(regions)),
        regionCertificates_(std::move(regionCertificates)),
        sourceDigest_(sourceDigest),
        networkDigest_(networkDigest), cutGraphDigest_(cutGraphDigest),
        semanticDigest_(semanticDigest) {}

  std::vector<GlobalTopologyArc> arcs_;
  std::vector<GlobalTopologyNodeRotation> rotations_;
  std::vector<GlobalTopologyRegion> regions_;
  std::vector<GlobalTopologyRegionDiscCertificate> regionCertificates_;
  std::uint64_t sourceDigest_ = 0U;
  std::uint64_t networkDigest_ = 0U;
  std::uint64_t cutGraphDigest_ = 0U;
  std::uint64_t semanticDigest_ = 0U;
};

class GlobalTopologyPlanBuildResult {
public:
  explicit GlobalTopologyPlanBuildResult(GlobalTopologyPlan plan)
      : state_(std::move(plan)) {}
  explicit GlobalTopologyPlanBuildResult(GlobalTopologyPlanError error)
      : state_(std::move(error)) {}

  [[nodiscard]] bool has_value() const noexcept {
    return std::holds_alternative<GlobalTopologyPlan>(state_);
  }
  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
  [[nodiscard]] const GlobalTopologyPlan &value() const {
    return std::get<GlobalTopologyPlan>(state_);
  }
  [[nodiscard]] GlobalTopologyPlan &value() {
    return std::get<GlobalTopologyPlan>(state_);
  }
  [[nodiscard]] const GlobalTopologyPlanError &error() const {
    return std::get<GlobalTopologyPlanError>(state_);
  }

private:
  std::variant<GlobalTopologyPlan, GlobalTopologyPlanError> state_;
};

[[nodiscard]] const char *global_topology_plan_error_code_name(
    GlobalTopologyPlanErrorCode code) noexcept;
[[nodiscard]] const char *rotation_system_inconsistency_reason_name(
    RotationSystemInconsistencyReason reason) noexcept;
[[nodiscard]] const char *trace_event_position_failure_reason_name(
    TraceEventPositionFailureReason reason) noexcept;
[[nodiscard]] const char *trace_event_position_pass_name(
    TraceEventPositionPass pass) noexcept;
[[nodiscard]] const char *trace_event_position_carrier_role_name(
    TraceEventPositionCarrierRole role) noexcept;
[[nodiscard]] std::uint64_t
    global_topology_plan_hash(const GlobalTopologyPlan &plan) noexcept;

} // namespace directional::geometry

#endif
