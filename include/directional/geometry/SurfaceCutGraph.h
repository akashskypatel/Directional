// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CUT_GRAPH_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CUT_GRAPH_H

#include <cstddef>
#include <cstdint>
#include <optional>
#include <variant>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/FieldTransportAtlas.h>
#include <directional/geometry/SourceTopologyRegions.h>
#include <directional/geometry/RotationSystemDiagnostics.h>
#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::geometry {

enum class GlobalTopologyPlanErrorCode : std::uint8_t;
enum class TraceCornerBindingProvenance : std::uint8_t;
enum class RotationSystemInconsistencyReason : std::uint8_t;
enum class VertexTraceSecondaryParameterFailureReason : std::uint8_t;
enum class EdgeTraceSecondaryRankFailureReason : std::uint8_t;
enum class TraceEventPositionFailureReason : std::uint8_t;
enum class TraceEventPositionPass : std::uint8_t;
enum class TraceEventPositionCarrierRole : std::uint8_t;

enum class SurfaceCutGraphComplexKind : std::uint8_t {
  ActualEmbeddedGraph = 0,
};

enum class SurfaceCutCandidateClass : std::uint8_t {
  Admissible = 0,
  MandatoryAlreadyPresent = 1,
  TraceInteriorCrossing = 2,
};

struct SurfaceCutCandidateEvidence {
  authority::SourceEdgeTopologyKey sourceEdge;
  SurfaceCutCandidateClass classification = SurfaceCutCandidateClass::Admissible;
  bool selected = false;
  auto operator<=>(const SurfaceCutCandidateEvidence &) const = default;
};

struct SurfaceCutGraphFaceCertificate {
  std::size_t orbit = 0U;
  std::size_t boundaryWalkCount = 0U;
  std::size_t boundaryArcCount = 0U;
  bool discTopologyEstablished = false;
  [[nodiscard]] bool proves_disc_topology() const noexcept {
    return boundaryWalkCount == 1U && boundaryArcCount > 0U &&
           discTopologyEstablished;
  }
  auto operator<=>(const SurfaceCutGraphFaceCertificate &) const = default;
};

struct SurfaceCutGraphTraceFragmentSideOwner {
  authority::TraceId trace;
  std::size_t segmentIndex = 0U;
  authority::Orientation orientation = authority::Orientation::Forward;
  std::size_t orbit = 0U;
  auto operator<=>(const SurfaceCutGraphTraceFragmentSideOwner &) const = default;
};

enum class SurfaceCutGraphSourceFaceOwnershipStatus : std::uint8_t {
  Established = 0,
  Unavailable = 1,
  Conflicting = 2,
};

enum class SurfaceCutGraphCertifiedOwnerConflictBarrierClass : std::uint8_t {
  None = 0,
  TraceOutgoingCarrier = 1,
  TraceIncomingCarrier = 2,
  MandatoryEdge = 3,
  CutEdge = 4,
};

struct SurfaceCutGraphSourceFaceOwnership {
  authority::SourceFaceTopologyKey sourceFace;
  std::vector<std::size_t> certifiedFaceOrbits;
  std::vector<SurfaceCutGraphTraceFragmentSideOwner> traceFragmentSides;
  SurfaceCutGraphSourceFaceOwnershipStatus status =
      SurfaceCutGraphSourceFaceOwnershipStatus::Established;
  [[nodiscard]] bool trace_crossed() const noexcept {
    return !traceFragmentSides.empty();
  }
  [[nodiscard]] bool established() const noexcept {
    return status == SurfaceCutGraphSourceFaceOwnershipStatus::Established;
  }
  auto operator<=>(const SurfaceCutGraphSourceFaceOwnership &) const = default;
};

struct SurfaceCutGraphCertifiedOwnerConflict {
  authority::SourceEdgeTopologyKey sourceEdge;
  authority::SourceFaceTopologyKey firstFace;
  std::size_t firstOwner = 0U;
  authority::SourceFaceTopologyKey secondFace;
  std::size_t secondOwner = 0U;
  SurfaceCutGraphCertifiedOwnerConflictBarrierClass barrierClass =
      SurfaceCutGraphCertifiedOwnerConflictBarrierClass::None;
  auto operator<=>(const SurfaceCutGraphCertifiedOwnerConflict &) const =
      default;
};

enum class UncutComponentPartitionDomainRule : std::uint8_t {
  NotTraceCut = 0,
  EmptyFragmentOrbits = 1,
};

struct UncutComponentPartitionBarrierComposition {
  bool cutGraphCutEdges = false;
  bool networkMandatoryEdges = false;
  bool embeddedMandatoryArcSourceEdges = false;
  bool embeddedCutArcSourceEdges = false;
  bool nonTerminalTraceCarrierEdges = false;
  auto operator<=>(const UncutComponentPartitionBarrierComposition &) const =
      default;
};

struct UncutComponentPartitionIdentity {
  UncutComponentPartitionDomainRule domainRule =
      UncutComponentPartitionDomainRule::NotTraceCut;
  UncutComponentPartitionBarrierComposition barriers;
  auto operator<=>(const UncutComponentPartitionIdentity &) const = default;
};

enum class SurfaceCutGraphUncutComponentArcKind : std::uint8_t {
  Mandatory = 0,
  Trace = 1,
  Cut = 2,
};

enum class SurfaceCutGraphUncutComponentSeedRule : std::uint8_t {
  SingleFaceOwner = 0,
  EdgeSideOwner = 1,
};

enum class SurfaceCutGraphTraceCutExclusionReason : std::uint8_t {
  TerminalSlit = 0,
  SegmentRangeInvalid = 1,
  TraceNotFound = 2,
  DartOutOfRange = 3,
  FaceNotFound = 4,
  Other = 5,
};

struct SurfaceCutGraphUncutComponentBoundaryEdgeCensus {
  authority::SourceEdgeTopologyKey sourceEdge;
  authority::SourceFaceTopologyKey componentFace;
  std::optional<authority::SourceFaceTopologyKey> oppositeFace;
  SurfaceCutGraphCertifiedOwnerConflictBarrierClass barrierClass =
      SurfaceCutGraphCertifiedOwnerConflictBarrierClass::None;
  bool barrierPresent = false;
  bool oppositeFaceTraceCut = false;
  bool sideOwnerExists = false;
  auto operator<=>(
      const SurfaceCutGraphUncutComponentBoundaryEdgeCensus &) const = default;
};

struct SurfaceCutGraphUncutComponentArcFaceCensus {
  authority::SourceFaceTopologyKey sourceFace;
  std::optional<std::size_t> certifierComponent;
  std::optional<std::size_t> planComponent;
  std::optional<SurfaceCutGraphTraceCutExclusionReason> notTraceCutReason;
  auto operator<=>(
      const SurfaceCutGraphUncutComponentArcFaceCensus &) const = default;
};

struct SurfaceCutGraphUncutComponentArcIncidenceCensus {
  authority::NetworkArcId arc;
  SurfaceCutGraphUncutComponentArcKind kind =
      SurfaceCutGraphUncutComponentArcKind::Mandatory;
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  std::size_t crossedFaceCount = 0U;
  std::vector<SurfaceCutGraphUncutComponentArcFaceCensus> crossedFaces;
  bool crossedFacesTruncated = false;
  auto operator<=>(
      const SurfaceCutGraphUncutComponentArcIncidenceCensus &) const = default;
};

struct SurfaceCutGraphUncutComponentVertexTransitCensus {
  authority::TraceId trace;
  std::size_t segmentIndex = 0U;
  authority::SourceVertexId sourceVertex;
  std::vector<authority::SourceFaceTopologyKey> incidentUncutFaces;
  bool adjacentAcrossNonBarrierEdge = false;
  std::optional<authority::SourceEdgeTopologyKey> adjacentNonBarrierEdge;
  std::optional<authority::SourceFaceTopologyKey> firstAdjacentFace;
  std::optional<authority::SourceFaceTopologyKey> secondAdjacentFace;
  auto operator<=>(
      const SurfaceCutGraphUncutComponentVertexTransitCensus &) const = default;
};

struct SurfaceCutGraphUncutComponentSeedAttribution {
  authority::SourceEdgeTopologyKey sourceEdge;
  authority::SourceFaceTopologyKey componentFace;
  authority::SourceFaceTopologyKey oppositeFace;
  std::size_t orbit = 0U;
  SurfaceCutGraphUncutComponentSeedRule rule =
      SurfaceCutGraphUncutComponentSeedRule::SingleFaceOwner;
  auto operator<=>(
      const SurfaceCutGraphUncutComponentSeedAttribution &) const = default;
};

struct SurfaceCutGraphUncutComponentCensus {
  std::size_t component = 0U;
  std::vector<authority::SourceFaceTopologyKey> faces;
  UncutComponentPartitionIdentity partitionIdentity;
  std::uint64_t faceSetDigest = 0U;
  bool boundaryCensusPublished = false;
  std::size_t boundaryEdgeCount = 0U;
  std::vector<SurfaceCutGraphUncutComponentBoundaryEdgeCensus> boundaryEdges;
  bool boundaryEdgesTruncated = false;
  bool interiorArcIncidenceCensusPublished = false;
  std::size_t interiorArcIncidenceCount = 0U;
  std::vector<SurfaceCutGraphUncutComponentArcIncidenceCensus>
      interiorArcIncidences;
  bool interiorArcIncidencesTruncated = false;
  bool vertexTransitCensusPublished = false;
  std::size_t vertexTransitCount = 0U;
  std::vector<SurfaceCutGraphUncutComponentVertexTransitCensus> vertexTransits;
  bool vertexTransitsTruncated = false;
  SurfaceCutGraphSourceFaceOwnershipStatus ownershipStatus =
      SurfaceCutGraphSourceFaceOwnershipStatus::Unavailable;
  std::vector<std::size_t> seedOrbitMultiset;
  std::vector<std::size_t> seedOrbits;
  std::size_t seedAttributionCount = 0U;
  std::vector<SurfaceCutGraphUncutComponentSeedAttribution> seedAttributions;
  bool seedAttributionsTruncated = false;
  auto operator<=>(const SurfaceCutGraphUncutComponentCensus &) const =
      default;
};

struct SurfaceCutGraphCellularityCertificate {
  SurfaceCutGraphComplexKind complex = SurfaceCutGraphComplexKind::ActualEmbeddedGraph;
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  std::size_t totalOrbitCount = 0U;
  std::size_t excludedBoundaryOrbitCount = 0U;
  std::size_t sourceBoundaryLoopCount = 0U;
  std::size_t faceCount = 0U;
  std::size_t graphComponentCount = 0U;
  std::size_t sourceComponentCount = 0U;
  // For a source with s connected components and an embedded graph with c
  // components, joining graph components within each source component by
  // c-s non-crossing complement bridges preserves F and gives the ordinary
  // connected-graph Euler identity. Therefore the corrected identity is
  // V - E + F - (c - s) = chi(S). For the connected-source case frozen by
  // DEFN-R1 this reduces to V - E + F - (c - 1) = chi(S).
  int disconnectedComponentCorrection = 0;
  int eulerCharacteristic = 0;
  int sourceEulerCharacteristic = 0;
  bool saturationUsed = false;
  std::optional<authority::SourceFaceTopologyKey> saturationLocus;
  std::size_t saturationPromotedEdgeCount = 0U;
  std::vector<SurfaceCutGraphFaceCertificate> faces;
  std::size_t sourceFaceCount = 0U;
  std::vector<SurfaceCutGraphSourceFaceOwnership> sourceFaceOwners;
  bool certifiedOwnerConflictCensusPublished = false;
  std::vector<SurfaceCutGraphCertifiedOwnerConflict>
      certifiedOwnerConflictCensus;
  bool uncutComponentCensusPublished = false;
  std::vector<SurfaceCutGraphUncutComponentCensus> uncutComponentCensuses;
  std::vector<SurfaceCutCandidateEvidence> cutCandidates;
  [[nodiscard]] bool proves_embedded_cellularity() const noexcept;
  [[nodiscard]] bool proves_cellularity() const noexcept;
  [[nodiscard]] const SurfaceCutGraphSourceFaceOwnership *
  find_source_face_owner(const authority::SourceFaceTopologyKey &sourceFace) const noexcept;
  auto operator<=>(const SurfaceCutGraphCellularityCertificate &) const = default;
};

enum class SurfaceCutGraphErrorCode : std::uint8_t {
  InvalidSourceBinding = 0,
  InvalidAtlasBinding = 1,
  InvalidNetworkBinding = 2,
  NonManifoldSource = 3,
  CellularityNotEstablished = 4,
  CutSearchExhaustedBeforeCellularity = 5,
  EmptyNetworkOnClosedSurface = 6,
  SourceFaceOwnershipNotEstablished = 7,
};

struct SurfaceCutGraphTraceEventPositionCandidate {
  std::size_t position = 0U;
  std::size_t segmentIndex = 0U;
  authority::SourceEdgeTopologyKey carrier;
  TraceEventPositionCarrierRole carrierRole;

  auto operator<=>(const SurfaceCutGraphTraceEventPositionCandidate &) const =
      default;
};

struct SurfaceCutGraphError {
  SurfaceCutGraphErrorCode code = SurfaceCutGraphErrorCode::InvalidSourceBinding;
  std::optional<authority::SourceVertexId> sourceVertex;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
  std::optional<authority::SourceFaceTopologyKey> sourceFace;
  std::optional<authority::FieldSingularityId> singularity;
  std::optional<GlobalTopologyPlanErrorCode> originatingTopologyError;
  std::optional<std::size_t> nonDiscComponentCount;
  std::optional<std::size_t> remainingAdmissibleEdgeCount;
  std::vector<SurfaceCutCandidateEvidence> cutCandidates;
  std::optional<std::size_t> certificationAttemptIndex;
  std::optional<std::size_t> certificationCutEdgeCount;
  bool embeddedGraphEulerCensusComplete = false;
  std::optional<std::size_t> embeddedGraphNodeCount;
  std::optional<std::size_t> embeddedGraphArcCount;
  std::optional<std::size_t> embeddedGraphFaceWalkOrbitCount;
  std::optional<std::size_t> embeddedGraphComponentCount;
  std::optional<std::int64_t> embeddedGraphSourceEulerCharacteristic;
  std::optional<std::int64_t> embeddedGraphEulerResidual;
  std::optional<RotationSystemInconsistencyReason>
      originatingRotationSystemInconsistencyReason;
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
  std::optional<authority::NetworkArcId> arc;
  std::optional<authority::NetworkArcId> secondArc;
  std::optional<authority::TraceId> trace;
  std::optional<authority::TraceId> secondTrace;
  std::optional<authority::SourceFaceTopologyKey> secondSourceFace;
  std::optional<std::size_t> traceEventIndex;
  std::optional<TraceEventPositionFailureReason> traceEventPositionFailureReason;
  std::optional<TraceEventPositionPass> traceEventPositionPass;
  std::vector<SurfaceCutGraphTraceEventPositionCandidate>
      traceEventPositionCandidates;
  std::optional<RotationRayOrderDiagnostic> rotationPreviousRay;
  std::optional<RotationRayOrderDiagnostic> rotationCurrentRay;
  RotationRayOrderCensus rotationFanCensus;
  auto operator<=>(const SurfaceCutGraphError &) const = default;
};

struct SurfaceCutGraphCandidate {
  std::vector<authority::SourceEdgeTopologyKey> cutEdges;
  SurfaceCutGraphCellularityCertificate certificate;
  std::uint64_t sourceDigest = 0U;
  std::uint64_t atlasDigest = 0U;
  std::uint64_t networkDigest = 0U;
  auto operator<=>(const SurfaceCutGraphCandidate &) const = default;
};

class SurfaceCutGraphBuildResult;

class SurfaceCutGraph {
public:
  [[nodiscard]] static SurfaceCutGraphBuildResult make(
      const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
      const SourceTopologyRegions &sourceAuthority,
      const authority::FieldTransportAtlas &fieldTransportAtlas,
      const FieldAlignedCurveNetwork &network);
  [[nodiscard]] static SurfaceCutGraphBuildResult make_from_candidate(
      const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
      const SourceTopologyRegions &sourceAuthority,
      const authority::FieldTransportAtlas &fieldTransportAtlas,
      const FieldAlignedCurveNetwork &network,
      SurfaceCutGraphCandidate candidate);
  [[nodiscard]] const std::vector<authority::SourceEdgeTopologyKey> &cut_edges() const noexcept { return cutEdges_; }
  [[nodiscard]] const SurfaceCutGraphCellularityCertificate &certificate() const noexcept { return certificate_; }
  [[nodiscard]] std::uint64_t source_digest() const noexcept { return sourceDigest_; }
  [[nodiscard]] std::uint64_t atlas_digest() const noexcept { return atlasDigest_; }
  [[nodiscard]] std::uint64_t network_digest() const noexcept { return networkDigest_; }
  [[nodiscard]] std::uint64_t semantic_digest() const noexcept { return semanticDigest_; }
  [[nodiscard]] std::uint64_t provenance_digest() const noexcept { return provenanceDigest_; }
private:
  friend class SurfaceCutGraphBuildResult;
  SurfaceCutGraph(std::vector<authority::SourceEdgeTopologyKey> cutEdges,
                  SurfaceCutGraphCellularityCertificate certificate,
                  std::uint64_t sourceDigest, std::uint64_t atlasDigest,
                  std::uint64_t networkDigest, std::uint64_t semanticDigest,
                  std::uint64_t provenanceDigest)
      : cutEdges_(std::move(cutEdges)), certificate_(std::move(certificate)),
        sourceDigest_(sourceDigest), atlasDigest_(atlasDigest),
        networkDigest_(networkDigest), semanticDigest_(semanticDigest),
        provenanceDigest_(provenanceDigest) {}
  std::vector<authority::SourceEdgeTopologyKey> cutEdges_;
  SurfaceCutGraphCellularityCertificate certificate_;
  std::uint64_t sourceDigest_ = 0U;
  std::uint64_t atlasDigest_ = 0U;
  std::uint64_t networkDigest_ = 0U;
  std::uint64_t semanticDigest_ = 0U;
  std::uint64_t provenanceDigest_ = 0U;
};

class SurfaceCutGraphBuildResult {
public:
  explicit SurfaceCutGraphBuildResult(SurfaceCutGraph graph) : state_(std::move(graph)) {}
  explicit SurfaceCutGraphBuildResult(SurfaceCutGraphError error) : state_(std::move(error)) {}
  [[nodiscard]] bool has_value() const noexcept { return std::holds_alternative<SurfaceCutGraph>(state_); }
  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
  [[nodiscard]] const SurfaceCutGraph &value() const { return std::get<SurfaceCutGraph>(state_); }
  [[nodiscard]] SurfaceCutGraph &value() { return std::get<SurfaceCutGraph>(state_); }
  [[nodiscard]] const SurfaceCutGraphError &error() const { return std::get<SurfaceCutGraphError>(state_); }
private:
  std::variant<SurfaceCutGraph, SurfaceCutGraphError> state_;
};

[[nodiscard]] const char *surface_cut_graph_error_code_name(SurfaceCutGraphErrorCode code) noexcept;
[[nodiscard]] const char *surface_cut_candidate_class_name(SurfaceCutCandidateClass classification) noexcept;
[[nodiscard]] const char *surface_cut_graph_complex_kind_name(SurfaceCutGraphComplexKind kind) noexcept;
[[nodiscard]] const char *surface_cut_graph_source_face_ownership_status_name(
    SurfaceCutGraphSourceFaceOwnershipStatus status) noexcept;
[[nodiscard]] const char *surface_cut_graph_certified_owner_conflict_barrier_class_name(
    SurfaceCutGraphCertifiedOwnerConflictBarrierClass barrierClass) noexcept;
[[nodiscard]] const char *uncut_component_partition_domain_rule_name(
    UncutComponentPartitionDomainRule rule) noexcept;
[[nodiscard]] const char *surface_cut_graph_uncut_component_arc_kind_name(
    SurfaceCutGraphUncutComponentArcKind kind) noexcept;
[[nodiscard]] const char *surface_cut_graph_uncut_component_seed_rule_name(
    SurfaceCutGraphUncutComponentSeedRule rule) noexcept;
[[nodiscard]] const char *surface_cut_graph_trace_cut_exclusion_reason_name(
    SurfaceCutGraphTraceCutExclusionReason reason) noexcept;
[[nodiscard]] std::uint64_t surface_cut_graph_hash(const SurfaceCutGraph &graph) noexcept;

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CUT_GRAPH_H
