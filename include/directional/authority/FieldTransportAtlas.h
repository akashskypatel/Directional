// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_FIELD_TRANSPORT_ATLAS_H
#define DIRECTIONAL_AUTHORITY_FIELD_TRANSPORT_ATLAS_H

#include <array>
#include <bit>
#include <cmath>
#include <compare>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/authority/SourceSupport.h>
#include <directional/core/Export.h>

#ifdef USE_GMP_ENABLED
#include <directional/numerics/ENumberGMP.h>
#else
#include <directional/numerics/ExactNumber.h>
#endif

namespace directional {

class TriMesh;

namespace fields {
struct CrossFieldResult;
}

namespace geometry {
class SourceTopologyRegions;
}

namespace authority {

/** Gauge-invariant Z4 branch value in a canonical source-face frame. */
class FieldBranch {
public:
  constexpr FieldBranch() noexcept = default;

  [[nodiscard]] static constexpr FieldBranch from_integer(int value) noexcept {
    const int normalized = ((value % 4) + 4) % 4;
    return FieldBranch(static_cast<std::uint8_t>(normalized));
  }

  [[nodiscard]] constexpr std::uint8_t value() const noexcept { return value_; }

  [[nodiscard]] constexpr FieldBranch rotated(const int quarterTurns) const noexcept {
    return from_integer(static_cast<int>(value_) + quarterTurns);
  }

  auto operator<=>(const FieldBranch &) const = default;

private:
  explicit constexpr FieldBranch(const std::uint8_t value) noexcept
      : value_(value) {}

  std::uint8_t value_ = 0U;
};

enum class FieldTransportBarrierKind : std::uint8_t {
  SourceBoundary,
  HardFeature,
  NonTraversable,
};

enum class FieldCycleKind : std::uint8_t {
  LocalVertex,
  BoundaryLoop,
  HandleGenerator,
};

enum class FieldQuadrangulabilityWitnessKind : std::uint8_t {
  ClosedShenSufficient,
  RelativeBoundary,
};

enum class IncompleteCycleBasisReason : std::uint8_t {
  LocalTangentBundleInitializationFailed = 0,
  CycleDimensionCountMismatch = 1,
  CycleCoefficientInvalid = 2,
  CycleTransportAdjacencyMissing = 3,
  CycleEdgeIncidentFaceMissing = 4,
  CycleOrderingFailed = 5,
  CycleKindPartitionMismatch = 6,
  BoundaryCycleCountMismatch = 7,
};

struct FieldAtlasRegionCycleBasisDiagnostics {
  TopologyRegionId topologyRegion;
  bool localMeshAvailable = false;
  bool bundleInitialized = false;
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  std::size_t faceCount = 0U;
  int eulerCharacteristic = 0;
  int boundaryLoopCount = 0;
  int genus = -1;
  std::size_t interiorLocalVertexCount = 0U;
  int expectedCycleCount = -1;
  std::size_t cycleRowCount = 0U;
  std::size_t cycleCurvatureCount = 0U;
  std::size_t innerAdjacencyCount = 0U;

  auto operator<=>(const FieldAtlasRegionCycleBasisDiagnostics &) const = default;
};

struct FieldBarrierComponentDiagnostics {
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  int eulerCharacteristic = 0;
  bool tree = false;
  bool containsCycle = false;
  std::vector<SourceVertexId> tipVertices;
  std::vector<SourceVertexId> branchVertices;
  std::size_t regionBoundaryVertexCount = 0U;

  auto operator<=>(const FieldBarrierComponentDiagnostics &) const = default;
};

enum class FieldBarrierSingularityClass : std::uint8_t {
  Tip,
  InteriorArc,
  Branch,
};

struct FieldBarrierIncidentSingularityDiagnostics {
  SourceVertexId sourceVertex;
  int indexNumerator = 0;
  std::size_t barrierDegree = 0U;
  std::size_t transportStarComponentCount = 0U;
  FieldBarrierSingularityClass classification =
      FieldBarrierSingularityClass::InteriorArc;

  auto operator<=>(const FieldBarrierIncidentSingularityDiagnostics &) const =
      default;
};

/** Derived, non-authoritative diagnostics for one A1 transport domain. */
struct FieldTransportRegionDiagnostics {
  explicit FieldTransportRegionDiagnostics(TopologyRegionId topologyRegion)
      : topologyRegion(topologyRegion) {}

  TopologyRegionId topologyRegion;
  std::size_t hardFeatureEdgeCount = 0U;
  std::vector<SourceEdgeTopologyKey> barrierEdges;
  std::vector<FieldBarrierComponentDiagnostics> barrierComponents;
  std::size_t barrierVertexCount = 0U;
  std::size_t barrierEdgeCount = 0U;
  std::size_t barrierComponentCount = 0U;
  int barrierEulerCharacteristic = 0;
  std::size_t barrierRegionBoundaryVertexCount = 0U;
  std::size_t barrierIncidentSingularityCount = 0U;
  std::vector<FieldBarrierIncidentSingularityDiagnostics>
      barrierIncidentSingularities;
  int uncutEulerCharacteristic = 0;
  int uncutBoundaryLoopCount = 0;
  int cutEulerCharacteristic = 0;
  int cutBoundaryLoopCount = 0;
  int newSlitBoundaryLoopCount = 0;
  FieldQuadrangulabilityWitnessKind witnessKind =
      FieldQuadrangulabilityWitnessKind::ClosedShenSufficient;
  int requiredIndexSum = 0;
  int interiorIndexSum = 0;
  int boundaryIndexSum = 0;
  int absorbedCorrection = 0;
  std::size_t prescribedSingularityCount = 0U;
  std::size_t localVertexBoundSingularityCount = 0U;
  std::size_t slitBoundaryBoundSingularityCount = 0U;
  std::size_t sourceBoundaryBoundSingularityCount = 0U;
  std::size_t unboundSingularityCount = 0U;

  auto operator<=>(const FieldTransportRegionDiagnostics &) const = default;
};

enum class FieldAtlasBuildErrorCode : std::uint8_t {
  InvalidInput,
  CanonicalBindingMismatch,
  MissingAdjacency,
  DuplicateAdjacency,
  NonReciprocalAdjacency,
  IncompleteCycleBasis,
  NonIntegralCycleLift,
  CycleTransportMismatch,
  SingularityMismatch,
  InvalidBranchTopology,
  AmbiguousBranchTopology,
  InvalidSingularityPortAttachment,
  GaussBonnetPoincareHopfMismatch,
  UnestablishedAdmissibility,
  InvalidBranchBoundaryBasis,
  InvalidBranchBoundaryDerivative,
  InvalidBranchBoundaryEdge,
  InvalidBranchBoundaryFlow,
  InvalidSingularityMetadata,
  InvalidSingularityIncidentFan,
  InvalidSingularityFrameRow,
  InvalidSingularityFrameOwnership,
  InvalidSingularityOppositeEdge,
  InvalidSingularityBranchIndex,
  InvalidSingularityOutgoingCarrier,
  EmptySingularityIncidence,
  InvalidSingularityRadialEdge,
  MissingSingularityBranchTransport,
  InvalidSingularityDirectedTransport,
  SingularityPortClassCountMismatch,
  DuplicateSingularityClassRepresentative,
  DuplicateSingularityPortRepresentative,
  BranchDirectionNotBarycentric,
  CutTransportDomainIdentityMismatch,
};

struct FieldAtlasBuildError {
  FieldAtlasBuildErrorCode code = FieldAtlasBuildErrorCode::InvalidInput;
  std::optional<SourceEdgeTopologyKey> sourceEdge;
  std::optional<SourceFaceId> sourceFace;
  std::optional<SourceVertexId> sourceVertex;
  std::optional<TopologyRegionId> topologyRegion;
  std::optional<FieldBranch> branch;
  std::optional<IncompleteCycleBasisReason> incompleteCycleBasisReason;
  std::vector<FieldAtlasRegionCycleBasisDiagnostics> regionCycleBasisDiagnostics;
  std::vector<FieldTransportRegionDiagnostics> regionTransportDiagnostics;

  auto operator<=>(const FieldAtlasBuildError &) const = default;
};

struct FieldTransportAdjacency {
  FieldTransportAdjacencyId id;
  SourceEdgeTopologyKey sourceEdge;
  SourceFaceId firstFace;
  SourceFaceId secondFace;
  SourceFaceTopologyKey firstFaceTopology;
  SourceFaceTopologyKey secondFaceTopology;
  TopologyRegionId topologyRegion;
  SourceComponentId sourceComponent;
  QuarterTurn forward;
  QuarterTurn reverse;
  int forwardLift = 0;
  double effort = 0.0;

  auto operator<=>(const FieldTransportAdjacency &) const = default;
};

struct FieldNonTraversableEdge {
  SourceEdgeTopologyKey sourceEdge;
  FieldTransportBarrierKind kind = FieldTransportBarrierKind::NonTraversable;
  std::optional<SourceFaceId> firstFace;
  std::optional<SourceFaceId> secondFace;

  auto operator<=>(const FieldNonTraversableEdge &) const = default;
};

struct FieldTransportStep {
  FieldTransportAdjacencyId adjacency;
  SourceEdgeTopologyKey sourceEdge;
  SourceFaceId fromFace;
  SourceFaceId toFace;
  QuarterTurn transport;
  int signedLift = 0;

  auto operator<=>(const FieldTransportStep &) const = default;
};

struct FieldCycleWitness {
  FieldCycleId id;
  FieldCycleKind kind = FieldCycleKind::LocalVertex;
  TopologyRegionId topologyRegion;
  SourceComponentId sourceComponent;
  std::optional<SourceVertexId> localVertex;
  std::vector<FieldTransportStep> steps;
  QuarterTurn composedTransport;
  int turningLift = 0;

  auto operator<=>(const FieldCycleWitness &) const = default;
};

struct FieldSingularityFact {
  enum class PortPolicy : std::uint8_t {
    Emit,
    BarrierAbsorbed,
  };

  FieldSingularityId id;
  SourceVertexId sourceVertex;
  SourceComponentId sourceComponent;
  int indexNumerator = 0;
  std::optional<TopologyRegionId> topologyRegion;
  std::optional<FieldCycleId> localCycle;
  PortPolicy portPolicy = PortPolicy::Emit;

  auto operator<=>(const FieldSingularityFact &) const = default;
};

struct FieldComponentTopology {
  TopologyRegionId topologyRegion;
  SourceComponentId sourceComponent;
  int eulerCharacteristic = 0;
  int boundaryLoopCount = 0;
  int genus = 0;
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  std::size_t faceCount = 0U;
  std::size_t localCycleCount = 0U;
  std::size_t handleGeneratorCount = 0U;

  auto operator<=>(const FieldComponentTopology &) const = default;
};

struct FieldQuadrangulabilityWitness {
  TopologyRegionId topologyRegion;
  SourceComponentId sourceComponent;
  FieldQuadrangulabilityWitnessKind kind =
      FieldQuadrangulabilityWitnessKind::ClosedShenSufficient;
  std::vector<int> fullSignature;
  std::vector<FieldCycleId> exactCycleLifts;
  std::vector<FieldCycleId> boundaryCycles;
  int numeratorGcd = 0;
  int indexSum = 0;
  int requiredIndexSum = 0;
  std::uint64_t holonomySignatureDigest = 0U;
  std::vector<int> singularityNumerators;

  auto operator<=>(const FieldQuadrangulabilityWitness &) const = default;
};

class FieldQuadrangulabilityCertificate {
public:
  [[nodiscard]] const std::vector<FieldQuadrangulabilityWitness> &
  witnesses() const noexcept {
    return witnesses_;
  }

  [[nodiscard]] bool established() const noexcept { return established_; }

  [[nodiscard]] std::uint64_t source_digest() const noexcept {
    return sourceDigest_;
  }

  [[nodiscard]] std::uint64_t atlas_digest() const noexcept {
    return atlasDigest_;
  }

  auto operator<=>(const FieldQuadrangulabilityCertificate &) const = default;

private:
  friend class FieldTransportAtlas;

  explicit FieldQuadrangulabilityCertificate(
      std::vector<FieldQuadrangulabilityWitness> witnesses,
      bool established, std::uint64_t sourceDigest,
      std::uint64_t atlasDigest)
      : witnesses_(std::move(witnesses)), established_(established),
        sourceDigest_(sourceDigest), atlasDigest_(atlasDigest) {}

  std::vector<FieldQuadrangulabilityWitness> witnesses_;
  bool established_ = false;
  std::uint64_t sourceDigest_ = 0U;
  std::uint64_t atlasDigest_ = 0U;
};

struct FieldDirectedTransport {
  FieldTransportAdjacencyId adjacency;
  QuarterTurn transport;
  int signedLift = 0;
  double effort = 0.0;

  auto operator<=>(const FieldDirectedTransport &) const = default;
};

enum class FieldBoundaryFlow : std::uint8_t {
  Inflow,
  Outflow,
  Tangent,
};

/** Exact rational used by A1/A2a field-continuation topology decisions. */
class FieldExactRational {
public:
  FieldExactRational() : value_(EInt(0)) {}

  [[nodiscard]] static std::optional<FieldExactRational>
  from_double_exact(const double value) {
    if (!std::isfinite(value)) return std::nullopt;
    const std::uint64_t bits = std::bit_cast<std::uint64_t>(value);
    const bool negative = (bits >> 63U) != 0U;
    const std::uint64_t exponentBits = (bits >> 52U) & 0x7ffU;
    const std::uint64_t fractionBits = bits & ((std::uint64_t{1} << 52U) - 1U);
    if (exponentBits == 0U && fractionBits == 0U) {
      return FieldExactRational(ENumber(EInt(0)));
    }

    const std::uint64_t mantissa =
        exponentBits == 0U ? fractionBits
                           : ((std::uint64_t{1} << 52U) | fractionBits);
    const int exponent = exponentBits == 0U
                             ? -1074
                             : static_cast<int>(exponentBits) - 1023 - 52;
    EInt numerator = integer_from_unsigned(mantissa);
    EInt denominator(1);
    if (exponent > 0) {
      numerator = numerator * power_of_two(exponent);
    } else if (exponent < 0) {
      denominator = power_of_two(-exponent);
    }
    if (negative) numerator = -numerator;
    return FieldExactRational(ENumber(numerator, denominator, true));
  }

  [[nodiscard]] static FieldExactRational from_integer(const std::int64_t value) {
    const bool negative = value < 0;
    const std::uint64_t magnitude =
        negative ? static_cast<std::uint64_t>(-(value + 1)) + 1U
                 : static_cast<std::uint64_t>(value);
    EInt integer = integer_from_unsigned(magnitude);
    if (negative) integer = -integer;
    return FieldExactRational(ENumber(integer));
  }

  [[nodiscard]] static std::optional<FieldExactRational>
  from_ratio(const std::int64_t numerator, const std::int64_t denominator) {
    if (denominator == 0) return std::nullopt;
    const auto n = from_integer(numerator);
    const auto d = from_integer(denominator);
    return FieldExactRational(n.value_ / d.value_);
  }

  [[nodiscard]] bool is_zero() const { return value_ == ENumber(EInt(0)); }
  [[nodiscard]] long double to_double(const int maxDigits = 18) const {
    return value_.to_double(maxDigits);
  }
  [[nodiscard]] std::string numerator_string() const {
    return enumber_num(value_).to_string();
  }
  [[nodiscard]] std::string denominator_string() const {
    return enumber_den(value_).to_string();
  }

  /**
   * @brief Deterministic bit-width of the widest of numerator and denominator.
   *
   * Exact continuation recomputes every parameter from the published direction,
   * so a value's width grows with the number of steps a trace has taken. This
   * measure lets a consumer bound the cost of exact arithmetic deterministically
   * instead of discovering the cost as an unbounded run time. It is a size, not
   * a numeric value: it never participates in a topological decision and it is
   * never compared against another rational.
   */
  [[nodiscard]] std::size_t magnitude_bits() const noexcept {
    const std::size_t numeratorBits = enumber_num(value_).magnitude_bits();
    const std::size_t denominatorBits = enumber_den(value_).magnitude_bits();
    return numeratorBits > denominatorBits ? numeratorBits : denominatorBits;
  }

  friend FieldExactRational operator+(const FieldExactRational &a,
                                      const FieldExactRational &b) {
    return FieldExactRational(a.value_ + b.value_);
  }
  friend FieldExactRational operator-(const FieldExactRational &a,
                                      const FieldExactRational &b) {
    return FieldExactRational(a.value_ - b.value_);
  }
  friend FieldExactRational operator-(const FieldExactRational &value) {
    return FieldExactRational(-value.value_);
  }
  friend FieldExactRational operator*(const FieldExactRational &a,
                                      const FieldExactRational &b) {
    return FieldExactRational(a.value_ * b.value_);
  }
  friend FieldExactRational operator/(const FieldExactRational &a,
                                      const FieldExactRational &b) {
    return FieldExactRational(a.value_ / b.value_);
  }
  friend bool operator==(const FieldExactRational &a,
                         const FieldExactRational &b) {
    return a.value_ == b.value_;
  }
  friend std::strong_ordering operator<=>(const FieldExactRational &a,
                                           const FieldExactRational &b) {
    if (a.value_ < b.value_) return std::strong_ordering::less;
    if (a.value_ > b.value_) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
  }

private:
  explicit FieldExactRational(const ENumber &value)
      : value_(ENumber(enumber_num(value), enumber_den(value), true)) {}

  [[nodiscard]] static EInt integer_from_unsigned(std::uint64_t value) {
    EInt result(0);
    EInt two(2);
    for (int bit = 63; bit >= 0; --bit) {
      result = result * two;
      if (((value >> static_cast<unsigned>(bit)) & 1U) != 0U) {
        result = result + EInt(1);
      }
    }
    return result;
  }

  [[nodiscard]] static EInt power_of_two(int exponent) {
    EInt result(1);
    EInt base(2);
    while (exponent > 0) {
      if ((exponent & 1) != 0) result = result * base;
      exponent >>= 1;
      if (exponent != 0) base = base * base;
    }
    return result;
  }

  ENumber value_;
};

struct ExactUnitParameter {
  FieldExactRational value;

  [[nodiscard]] bool in_unit_interval() const {
    return value >= FieldExactRational::from_integer(0) &&
           value <= FieldExactRational::from_integer(1);
  }

  auto operator<=>(const ExactUnitParameter &) const = default;
};

struct FieldBoundaryPoint {
  SourceEdgeTopologyKey edge;
  ExactUnitParameter parameter;

  [[nodiscard]] std::optional<SourceSupport> source_support() const {
    if (!parameter.in_unit_interval()) return std::nullopt;
    if (parameter.value == FieldExactRational::from_integer(0)) {
      return SourceSupport{SourceVertexSupport{edge.first()}};
    }
    if (parameter.value == FieldExactRational::from_integer(1)) {
      return SourceSupport{SourceVertexSupport{edge.second()}};
    }
    return SourceSupport{SourceEdgeSupport{edge}};
  }

  auto operator<=>(const FieldBoundaryPoint &) const = default;
};

struct FieldBranchDirection {
  std::array<FieldExactRational, 3> barycentric{};

  [[nodiscard]] bool is_barycentric() const {
    const FieldExactRational zero = FieldExactRational::from_integer(0);
    return barycentric[0] + barycentric[1] + barycentric[2] == zero &&
           !(barycentric[0] == zero && barycentric[1] == zero &&
             barycentric[2] == zero);
  }

  [[nodiscard]] const FieldExactRational &operator[](const std::size_t index) const {
    return barycentric[index];
  }

  auto operator<=>(const FieldBranchDirection &) const = default;
};

/** Half-open canonical source-face boundary carrier [startVertex,endVertex). */
struct FieldBranchBoundaryInterval {
  SourceVertexId startVertex;
  SourceVertexId endVertex;
  SourceEdgeTopologyKey sourceEdge;
  FieldBoundaryFlow flow = FieldBoundaryFlow::Tangent;

  auto operator<=>(const FieldBranchBoundaryInterval &) const = default;
};

struct FieldBranchBoundaryPairing {
  FieldBranch branch;
  FieldBranchDirection direction;
  std::vector<FieldBranchBoundaryInterval> intervals;
  std::vector<SourceEdgeTopologyKey> incomingCarriers;
  std::vector<SourceEdgeTopologyKey> outgoingCarriers;

  auto operator<=>(const FieldBranchBoundaryPairing &) const = default;
};

struct FieldFaceBranchFrame {
  SourceFaceTopologyKey sourceFace;
  TopologyRegionId topologyRegion;
  SourceComponentId sourceComponent;
  std::vector<FieldBranchBoundaryPairing> branches;

  auto operator<=>(const FieldFaceBranchFrame &) const = default;
};

struct FieldBranchTransportAdjacency {
  SourceEdgeTopologyKey sourceEdge;
  SourceFaceTopologyKey firstFace;
  SourceFaceTopologyKey secondFace;
  QuarterTurn forward;
  QuarterTurn reverse;
  int forwardLift = 0;
  double effort = 0.0;

  auto operator<=>(const FieldBranchTransportAdjacency &) const = default;
};

struct FieldDirectedBranchTransport {
  QuarterTurn transport;
  int signedLift = 0;
  double effort = 0.0;

  auto operator<=>(const FieldDirectedBranchTransport &) const = default;
};

struct FieldSingularityPortAttachment {
  FieldSingularityId singularity;
  SourceVertexId sourceVertex;
  int localSlot = 0;
  SourceFaceTopologyKey startFace;
  FieldBranch branch;
  SourceEdgeTopologyKey firstOutgoingCarrier;
  TopologyRegionId topologyRegion;
  SourceComponentId sourceComponent;

  auto operator<=>(const FieldSingularityPortAttachment &) const = default;
};

[[nodiscard]] DIRECTIONAL_API bool direction_in_vertex_sector(
    const TriMesh &sourceMesh, SourceFaceId sourceFace, SourceVertexId vertex,
    const FieldBranchDirection &direction);

/** Immutable canonical local branch topology nested inside the A1 atlas. */
class FieldBranchTopology {
public:
  [[nodiscard]] const std::vector<FieldFaceBranchFrame> &frames() const noexcept {
    return frames_;
  }

  [[nodiscard]] const std::vector<FieldBranchTransportAdjacency> &
  transports() const noexcept {
    return transports_;
  }

  [[nodiscard]] const std::vector<FieldSingularityPortAttachment> &
  singularity_port_attachments() const noexcept {
    return singularityPortAttachments_;
  }

  [[nodiscard]] std::uint64_t semantic_digest() const noexcept {
    return semanticDigest_;
  }

  [[nodiscard]] DIRECTIONAL_API const FieldFaceBranchFrame *
  find_frame(const SourceFaceTopologyKey &sourceFace) const noexcept;

  [[nodiscard]] DIRECTIONAL_API std::optional<FieldDirectedBranchTransport>
  transport(const SourceEdgeTopologyKey &sourceEdge,
            const SourceFaceTopologyKey &fromFace,
            const SourceFaceTopologyKey &toFace) const noexcept;

  auto operator<=>(const FieldBranchTopology &) const = default;

private:
  friend class FieldTransportAtlas;

  explicit FieldBranchTopology(
      std::vector<FieldFaceBranchFrame> frames,
      std::vector<FieldBranchTransportAdjacency> transports,
      std::vector<FieldSingularityPortAttachment> singularityPortAttachments,
      std::uint64_t semanticDigest)
      : frames_(std::move(frames)), transports_(std::move(transports)),
        singularityPortAttachments_(std::move(singularityPortAttachments)),
        semanticDigest_(semanticDigest) {}

  std::vector<FieldFaceBranchFrame> frames_;
  std::vector<FieldBranchTransportAdjacency> transports_;
  std::vector<FieldSingularityPortAttachment> singularityPortAttachments_;
  std::uint64_t semanticDigest_ = 0U;
};

class FieldTransportAtlasBuildResult;

/**
 * Immutable A1 authority for cross-field transport and conservative
 * field-quadrangulability.  Construction is the only validation seam; callers
 * receive no mutable access to adjacency, cycle, singularity, or certificate
 * storage.
 */
class FieldTransportAtlas {
public:
  [[nodiscard]] static DIRECTIONAL_API FieldTransportAtlasBuildResult make(
      const TriMesh &sourceMesh,
      const geometry::SourceTopologyRegions &sourceAuthority,
      const std::set<SourceEdgeTopologyKey> &hardFeatureEdges,
      const fields::CrossFieldResult &crossField);

  [[nodiscard]] const std::vector<FieldTransportAdjacency> &
  adjacencies() const noexcept {
    return adjacencies_;
  }
  [[nodiscard]] const std::vector<FieldNonTraversableEdge> &
  nontraversable_edges() const noexcept {
    return nontraversableEdges_;
  }
  [[nodiscard]] const std::vector<FieldCycleWitness> &cycles() const noexcept {
    return cycles_;
  }
  [[nodiscard]] const std::vector<FieldSingularityFact> &
  singularities() const noexcept {
    return singularities_;
  }
  [[nodiscard]] const std::vector<FieldComponentTopology> &
  component_topology() const noexcept {
    return componentTopology_;
  }
  [[nodiscard]] const FieldQuadrangulabilityCertificate &
  quadrangulability() const noexcept {
    return quadrangulability_;
  }
  [[nodiscard]] const FieldBranchTopology &branch_topology() const noexcept {
    return branchTopology_;
  }
  [[nodiscard]] const std::vector<FieldTransportRegionDiagnostics> &
  region_transport_diagnostics() const noexcept {
    return regionTransportDiagnostics_;
  }

  [[nodiscard]] DIRECTIONAL_API const FieldTransportAdjacency *
  find_adjacency(const SourceEdgeTopologyKey &sourceEdge) const noexcept;

  [[nodiscard]] DIRECTIONAL_API std::optional<FieldDirectedTransport>
  transport(const SourceEdgeTopologyKey &sourceEdge, SourceFaceId fromFace,
            SourceFaceId toFace) const noexcept;

  [[nodiscard]] DIRECTIONAL_API bool matches_source_faces(
      const Eigen::MatrixXi &sourceFaces,
      const geometry::SourceTopologyRegions &sourceAuthority,
      std::size_t sourceVertexCount) const noexcept;

  auto operator<=>(const FieldTransportAtlas &) const = default;

private:
  friend class FieldTransportAtlasBuildResult;

  FieldTransportAtlas(
      std::size_t sourceVertexCount,
      std::vector<SourceFaceTopologyKey> rowTopology,
      std::vector<TopologyRegionId> rowRegions,
      std::vector<SourceComponentId> rowComponents,
      std::vector<FieldTransportAdjacency> adjacencies,
      std::vector<FieldNonTraversableEdge> nontraversableEdges,
      std::vector<FieldCycleWitness> cycles,
      std::vector<FieldSingularityFact> singularities,
      std::vector<FieldComponentTopology> componentTopology,
      std::vector<FieldTransportRegionDiagnostics> regionTransportDiagnostics,
      FieldBranchTopology branchTopology,
      FieldQuadrangulabilityCertificate quadrangulability)
      : sourceVertexCount_(sourceVertexCount),
        rowTopology_(std::move(rowTopology)),
        rowRegions_(std::move(rowRegions)),
        rowComponents_(std::move(rowComponents)),
        adjacencies_(std::move(adjacencies)),
        nontraversableEdges_(std::move(nontraversableEdges)),
        cycles_(std::move(cycles)), singularities_(std::move(singularities)),
        componentTopology_(std::move(componentTopology)),
        regionTransportDiagnostics_(std::move(regionTransportDiagnostics)),
        branchTopology_(std::move(branchTopology)),
        quadrangulability_(std::move(quadrangulability)) {}

  std::size_t sourceVertexCount_ = 0U;
  std::vector<SourceFaceTopologyKey> rowTopology_;
  std::vector<TopologyRegionId> rowRegions_;
  std::vector<SourceComponentId> rowComponents_;
  std::vector<FieldTransportAdjacency> adjacencies_;
  std::vector<FieldNonTraversableEdge> nontraversableEdges_;
  std::vector<FieldCycleWitness> cycles_;
  std::vector<FieldSingularityFact> singularities_;
  std::vector<FieldComponentTopology> componentTopology_;
  std::vector<FieldTransportRegionDiagnostics> regionTransportDiagnostics_;
  FieldBranchTopology branchTopology_;
  FieldQuadrangulabilityCertificate quadrangulability_;
};

class FieldTransportAtlasBuildResult {
public:
  explicit FieldTransportAtlasBuildResult(FieldTransportAtlas atlas)
      : state_(std::move(atlas)) {}
  explicit FieldTransportAtlasBuildResult(FieldAtlasBuildError error)
      : state_(std::move(error)) {}

  [[nodiscard]] bool has_value() const noexcept {
    return std::holds_alternative<FieldTransportAtlas>(state_);
  }
  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
  [[nodiscard]] const FieldTransportAtlas &value() const {
    return std::get<FieldTransportAtlas>(state_);
  }
  [[nodiscard]] FieldTransportAtlas &value() {
    return std::get<FieldTransportAtlas>(state_);
  }
  [[nodiscard]] const FieldAtlasBuildError &error() const {
    return std::get<FieldAtlasBuildError>(state_);
  }

private:
  std::variant<FieldTransportAtlas, FieldAtlasBuildError> state_;
};

[[nodiscard]] DIRECTIONAL_API const char *
field_atlas_build_error_code_name(FieldAtlasBuildErrorCode code) noexcept;

[[nodiscard]] DIRECTIONAL_API const char *
incomplete_cycle_basis_reason_name(IncompleteCycleBasisReason reason) noexcept;

[[nodiscard]] DIRECTIONAL_API std::uint64_t
field_transport_atlas_hash(const FieldTransportAtlas &atlas) noexcept;

} // namespace authority
} // namespace directional

#endif // DIRECTIONAL_AUTHORITY_FIELD_TRANSPORT_ATLAS_H
