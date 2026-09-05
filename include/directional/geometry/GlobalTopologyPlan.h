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
#include <directional/authority/SourceSupport.h>
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

enum class UncutFaceComponentSeedState : std::uint8_t {
  None = 0,
  Unique = 1,
  Multiple = 2,
};

enum class UncutFaceComponentBarrierClass : std::uint8_t {
  None = 0,
  Mandatory = 1,
  Cut = 2,
  TraceTouched = 3,
};

enum class UncutFaceComponentNoSeedReason : std::uint8_t {
  IncidentFaceCountNotTwo = 0,
  Barrier = 1,
  OtherSideUnlabeled = 2,
  LabeledFaceHasNoOwner = 3,
  EdgeOrbitEvidenceMissing = 4,
  EdgeOrbitEvidenceNotUnique = 5,
};

enum class UncutFaceComponentSeedRule : std::uint8_t {
  SingleFaceOwner = 0,
  EdgeOrbitEvidence = 1,
};

enum class UncutFaceSourceFaceLocusKind : std::uint8_t {
  FirstUnlabeledFaceInIterationOrder = 0,
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
  RotationVertexTraceRaysExactlyCoincident = 62,
  VertexTraceSecondaryParameterUnavailable = 63,
};

enum class VertexTraceSecondaryParameterFailureReason : std::uint8_t {
  TraceRayFaceUnavailable = 0,
  SourceFaceRecordUnavailable = 1,
  LocusCornerUnavailable = 2,
  SecondPointUnavailable = 3,
  InvalidDenominator = 4,
};

enum class EdgeTraceSecondaryRankFailureReason : std::uint8_t {
  TraceRayFaceUnavailable = 0,
  SourceFaceRecordUnavailable = 1,
  ContactEdgeUnavailable = 2,
  OppositeCarrierNotInFace = 3,
  CoincidentLocalEdgeIndex = 4,
  SourceVertexFallbackUnbound = 5,
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

/** Exact authority used to bind a carrier-less trace segment to a face corner. */
enum class TraceCornerBindingProvenance : std::uint8_t {
  TraceOrigin = 0,
  SegmentEntrySupport = 1,
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

struct TraceCutFaceFragmentIncidenceDiagnostic {
  authority::TraceId trace;
  authority::NetworkArcId arc;
  std::size_t segmentIndex = 0U;
  authority::Orientation orientation = authority::Orientation::Forward;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  authority::SourceEdgeTopologyKey outgoingCarrier;
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  bool forwardOrbitDroppedByExteriorFilter = false;
  bool reverseOrbitDroppedByExteriorFilter = false;

  auto operator<=>(const TraceCutFaceFragmentIncidenceDiagnostic &) const =
      default;
};

struct TraceCutFaceEdgeOrbitEvidenceDiagnostic {
  authority::SourceEdgeTopologyKey sourceEdge;
  std::vector<std::size_t> orbitIds;
  std::size_t totalOrbitCount = 0U;
  bool truncated = false;

  auto operator<=>(const TraceCutFaceEdgeOrbitEvidenceDiagnostic &) const =
      default;
};

struct TraceCutFaceFragmentOwnerEvidenceDiagnostic {
  authority::SourceFaceTopologyKey sourceFace;
  std::optional<std::size_t> localFragmentCount;
  std::size_t ownerCount = 0U;
  std::size_t expectedFragmentCount = 0U;
  std::size_t ownerDeficit = 0U;
  std::size_t traceChordCount = 0U;
  bool chordsCrossInside = false;
  bool localArrangementEvaluated = false;
  std::vector<TraceCutFaceFragmentIncidenceDiagnostic> sharedOwnerChords;
  std::size_t sharedOwnerChordCount = 0U;
  bool sharedOwnerChordsTruncated = false;

  auto operator<=>(const TraceCutFaceFragmentOwnerEvidenceDiagnostic &) const =
      default;
};

struct TraceArcOwnerCensusDiagnostic {
  authority::NetworkArcId arc;
  std::optional<authority::TraceId> trace;
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  bool sharesOrbit = false;

  auto operator<=>(const TraceArcOwnerCensusDiagnostic &) const = default;
};

struct TraceTerminalSlitCensusDiagnostic {
  authority::TraceId trace;
  bool terminatesInTerminalSlit = false;

  auto operator<=>(const TraceTerminalSlitCensusDiagnostic &) const = default;
};

struct UncutFaceComponentBoundaryEdgeDiagnostic {
  authority::SourceEdgeTopologyKey sourceEdge;
  std::optional<authority::SourceFaceTopologyKey> componentFace;
  std::optional<authority::SourceFaceTopologyKey> labeledFace;
  bool otherSideLabeled = false;
  std::size_t labeledFaceOwnerCount = 0U;
  UncutFaceComponentBarrierClass barrierClass =
      UncutFaceComponentBarrierClass::None;
  std::optional<std::size_t> contributedSeed;
  std::optional<UncutFaceComponentSeedRule> seedRule;
  std::optional<UncutFaceComponentNoSeedReason> noSeedReason;
  bool minoritySeedOrbit = false;
  std::optional<std::size_t> componentSideCertifiedFace;
  std::optional<std::size_t> labeledSideCertifiedFace;

  auto operator<=>(const UncutFaceComponentBoundaryEdgeDiagnostic &) const =
      default;
};

struct UncutFaceCertificatePairDiagnostic {
  authority::SourceEdgeTopologyKey sourceEdge;
  authority::SourceFaceTopologyKey firstFace;
  authority::SourceFaceTopologyKey secondFace;
  std::optional<std::size_t> firstCertifiedFace;
  std::optional<std::size_t> secondCertifiedFace;

  auto operator<=>(const UncutFaceCertificatePairDiagnostic &) const = default;
};

struct UncutFaceComponentCertifiedFaceMultiplicityDiagnostic {
  std::size_t certifiedFace = 0U;
  std::size_t sourceFaceCount = 0U;

  auto operator<=>(
      const UncutFaceComponentCertifiedFaceMultiplicityDiagnostic &) const =
      default;
};

struct UncutFaceComponentCertifiedFaceObservationDiagnostic {
  authority::SourceFaceTopologyKey sourceFace;
  std::size_t certifiedFace = 0U;

  auto operator<=>(
      const UncutFaceComponentCertifiedFaceObservationDiagnostic &) const =
      default;
};

struct UncutFaceComponentBoundaryOrbitDiagnostic {
  std::size_t orbit = 0U;
  std::size_t boundaryEdgeCount = 0U;

  auto operator<=>(const UncutFaceComponentBoundaryOrbitDiagnostic &) const =
      default;
};

struct UncutFaceComponentSeedCensusDiagnostic {
  std::size_t component = 0U;
  std::size_t faceCount = 0U;
  std::size_t seedCount = 0U;
  UncutFaceComponentSeedState seedState = UncutFaceComponentSeedState::None;
  std::vector<std::size_t> seedOrbitIds;
  std::size_t seedOrbitCount = 0U;
  bool seedOrbitsTruncated = false;

  auto operator<=>(const UncutFaceComponentSeedCensusDiagnostic &) const =
      default;
};

struct TraceFragmentOwnerEvidenceDiagnostic {
  std::vector<TraceCutFaceFragmentOwnerEvidenceDiagnostic> faces;
  std::size_t faceCount = 0U;
  bool facesTruncated = false;
  std::vector<TraceArcOwnerCensusDiagnostic> arcs;
  std::size_t arcCount = 0U;
  bool arcsTruncated = false;
  std::vector<TraceTerminalSlitCensusDiagnostic> traces;
  std::size_t traceCount = 0U;
  bool tracesTruncated = false;
  std::size_t totalOrbitCount = 0U;
  std::size_t exteriorOrbitCount = 0U;
  std::size_t nonExteriorOrbitCount = 0U;
  std::vector<UncutFaceComponentSeedCensusDiagnostic> components;
  std::size_t componentCount = 0U;
  bool componentsTruncated = false;

  auto operator<=>(const TraceFragmentOwnerEvidenceDiagnostic &) const =
      default;
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
  std::optional<std::size_t> fragmentOrbitCount;
  std::optional<std::size_t> tracePieceCount;
  std::optional<std::size_t> expectedFragmentCount;
  bool embeddedGraphEulerCensusComplete = false;
  std::optional<std::size_t> embeddedGraphNodeCount;
  std::optional<std::size_t> embeddedGraphArcCount;
  std::optional<std::size_t> embeddedGraphFaceWalkOrbitCount;
  std::optional<std::size_t> embeddedGraphComponentCount;
  std::optional<std::int64_t> embeddedGraphSourceEulerCharacteristic;
  std::optional<std::int64_t> embeddedGraphEulerResidual;
  std::vector<TraceCutFaceFragmentIncidenceDiagnostic> fragmentIncidences;
  std::size_t fragmentIncidenceCount = 0U;
  bool fragmentIncidencesTruncated = false;
  std::vector<TraceCutFaceEdgeOrbitEvidenceDiagnostic>
      fragmentEdgeOrbitEvidence;
  std::optional<std::size_t> uncutFaceComponent;
  std::optional<std::size_t> uncutFaceComponentSeedCount;
  std::optional<UncutFaceComponentSeedState> uncutFaceComponentSeedState;
  std::optional<UncutFaceSourceFaceLocusKind> sourceFaceLocusKind;
  std::size_t uncutFaceComponentFaceCount = 0U;
  std::vector<authority::SourceFaceTopologyKey> uncutFaceComponentFaces;
  bool uncutFaceComponentFacesTruncated = false;
  std::optional<UncutComponentPartitionIdentity>
      uncutFaceComponentPartitionIdentity;
  std::optional<std::uint64_t> uncutFaceComponentFaceSetDigest;
  std::optional<std::size_t> uncutComponentCensusComponent;
  std::optional<UncutComponentPartitionIdentity>
      uncutComponentCensusPartitionIdentity;
  std::optional<std::uint64_t> uncutComponentCensusFaceSetDigest;
  std::optional<bool> uncutComponentCensusMatchesFailingComponent;
  std::size_t uncutFaceComponentBoundaryEdgeCount = 0U;
  std::vector<UncutFaceComponentBoundaryEdgeDiagnostic>
      uncutFaceComponentBoundaryEdges;
  bool uncutFaceComponentBoundaryEdgesTruncated = false;
  std::size_t uncutFaceComponentBoundaryOrbitCount = 0U;
  std::vector<UncutFaceComponentBoundaryOrbitDiagnostic>
      uncutFaceComponentBoundaryOrbits;
  bool uncutFaceComponentBoundaryOrbitsTruncated = false;
  std::optional<std::size_t> uncutFaceCertificatePairExaminedCount;
  std::optional<std::size_t> uncutFaceCertificatePairDifferingCount;
  std::vector<UncutFaceCertificatePairDiagnostic> uncutFaceCertificatePairs;
  bool uncutFaceCertificatePairsTruncated = false;
  std::optional<std::size_t> uncutFaceComponentCertifiedFaceObservationCount;
  std::vector<UncutFaceComponentCertifiedFaceObservationDiagnostic>
      uncutFaceComponentCertifiedFaceObservations;
  bool uncutFaceComponentCertifiedFaceObservationsTruncated = false;
  std::optional<std::size_t> uncutFaceComponentCertifiedFaceUnavailableCount;
  std::optional<std::size_t> uncutFaceComponentCertifiedFaceDistinctCount;
  std::vector<UncutFaceComponentCertifiedFaceMultiplicityDiagnostic>
      uncutFaceComponentCertifiedFaceMultiset;
  bool uncutFaceComponentCertifiedFaceMultisetTruncated = false;
  TraceFragmentOwnerEvidenceDiagnostic fragmentOwnerEvidence;
  std::optional<RotationSystemInconsistencyReason>
      rotationSystemInconsistencyReason;
  std::optional<VertexTraceSecondaryParameterFailureReason>
      vertexTraceSecondaryParameterFailureReason;
  std::optional<EdgeTraceSecondaryRankFailureReason>
      edgeTraceSecondaryRankFailureReason;
  std::optional<authority::Orientation> rotationTraceOrientation;
  std::optional<std::size_t> traceFirstSegment;
  std::optional<std::size_t> traceOnePastLastSegment;
  std::optional<authority::SourceEdgeTopologyKey> traceIncomingCarrier;
  std::optional<authority::SourceEdgeTopologyKey> traceOutgoingCarrier;
  std::optional<authority::Orientation> traceSegmentOrientation;
  std::optional<std::size_t> traceSegmentIndex;
  std::optional<bool> traceSegmentIsFirst;
  std::optional<authority::SingularityPortId> traceSourcePort;
  std::optional<authority::SourceVertexId> traceBoundCorner;
  std::optional<TraceCornerBindingProvenance> traceBoundCornerProvenance;
  std::optional<authority::SourceSupport> traceEntrySupport;
  std::optional<authority::SourceSupport> traceExitSupport;
  std::optional<std::size_t> edgeTraceContactIndex;
  std::optional<authority::SourceEdgeTopologyKey> edgeTraceOtherCarrier;
  std::optional<std::array<authority::SourceVertexId, 3>> edgeTraceFaceCorners;
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
  TraceFragmentOwnerEvidenceDiagnostic fragmentOwnerEvidence;
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
  [[nodiscard]] const TraceFragmentOwnerEvidenceDiagnostic &
  fragment_owner_evidence() const noexcept {
    return fragmentOwnerEvidence_;
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
                     std::uint64_t semanticDigest,
                     TraceFragmentOwnerEvidenceDiagnostic fragmentOwnerEvidence)
      : arcs_(std::move(arcs)), rotations_(std::move(rotations)),
        regions_(std::move(regions)),
        regionCertificates_(std::move(regionCertificates)),
        sourceDigest_(sourceDigest),
        networkDigest_(networkDigest), cutGraphDigest_(cutGraphDigest),
        semanticDigest_(semanticDigest),
        fragmentOwnerEvidence_(std::move(fragmentOwnerEvidence)) {}

  std::vector<GlobalTopologyArc> arcs_;
  std::vector<GlobalTopologyNodeRotation> rotations_;
  std::vector<GlobalTopologyRegion> regions_;
  std::vector<GlobalTopologyRegionDiscCertificate> regionCertificates_;
  std::uint64_t sourceDigest_ = 0U;
  std::uint64_t networkDigest_ = 0U;
  std::uint64_t cutGraphDigest_ = 0U;
  std::uint64_t semanticDigest_ = 0U;
  TraceFragmentOwnerEvidenceDiagnostic fragmentOwnerEvidence_;
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
[[nodiscard]] const char *uncut_face_component_seed_state_name(
    UncutFaceComponentSeedState state) noexcept;
[[nodiscard]] const char *uncut_face_component_barrier_class_name(
    UncutFaceComponentBarrierClass barrierClass) noexcept;
[[nodiscard]] const char *uncut_face_component_no_seed_reason_name(
    UncutFaceComponentNoSeedReason reason) noexcept;
[[nodiscard]] const char *uncut_face_component_seed_rule_name(
    UncutFaceComponentSeedRule rule) noexcept;
[[nodiscard]] const char *uncut_face_source_face_locus_kind_name(
    UncutFaceSourceFaceLocusKind kind) noexcept;
[[nodiscard]] const char *rotation_system_inconsistency_reason_name(
    RotationSystemInconsistencyReason reason) noexcept;
[[nodiscard]] const char *vertex_trace_secondary_parameter_failure_reason_name(
    VertexTraceSecondaryParameterFailureReason reason) noexcept;
[[nodiscard]] const char *edge_trace_secondary_rank_failure_reason_name(
    EdgeTraceSecondaryRankFailureReason reason) noexcept;
[[nodiscard]] const char *trace_event_position_failure_reason_name(
    TraceEventPositionFailureReason reason) noexcept;
[[nodiscard]] const char *trace_event_position_pass_name(
    TraceEventPositionPass pass) noexcept;
[[nodiscard]] const char *trace_event_position_carrier_role_name(
    TraceEventPositionCarrierRole role) noexcept;
[[nodiscard]] const char *trace_corner_binding_provenance_name(
    TraceCornerBindingProvenance provenance) noexcept;
[[nodiscard]] std::uint64_t
    global_topology_plan_hash(const GlobalTopologyPlan &plan) noexcept;

} // namespace directional::geometry

#endif
