// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_AUTHORITY_FIELD_TRANSPORT_ATLAS_H
#define DIRECTIONAL_AUTHORITY_FIELD_TRANSPORT_ATLAS_H

#include <compare>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <set>
#include <utility>
#include <variant>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/AuthorityIds.h>
#include <directional/authority/GridAutomorphism.h>
#include <directional/core/Export.h>

namespace directional {

class TriMesh;

namespace fields {
struct CrossFieldResult;
}

namespace geometry {
class SourceTopologyRegions;
}

namespace authority {

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
  GaussBonnetPoincareHopfMismatch,
  UnestablishedAdmissibility,
};

struct FieldAtlasBuildError {
  FieldAtlasBuildErrorCode code = FieldAtlasBuildErrorCode::InvalidInput;
  std::optional<SourceEdgeTopologyKey> sourceEdge;
  std::optional<SourceFaceId> sourceFace;
  std::optional<SourceVertexId> sourceVertex;
  std::optional<TopologyRegionId> topologyRegion;

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
  FieldSingularityId id;
  SourceVertexId sourceVertex;
  SourceComponentId sourceComponent;
  int indexNumerator = 0;
  std::optional<TopologyRegionId> topologyRegion;
  std::optional<FieldCycleId> localCycle;

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
      FieldQuadrangulabilityCertificate quadrangulability)
      : sourceVertexCount_(sourceVertexCount),
        rowTopology_(std::move(rowTopology)),
        rowRegions_(std::move(rowRegions)),
        rowComponents_(std::move(rowComponents)),
        adjacencies_(std::move(adjacencies)),
        nontraversableEdges_(std::move(nontraversableEdges)),
        cycles_(std::move(cycles)), singularities_(std::move(singularities)),
        componentTopology_(std::move(componentTopology)),
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

[[nodiscard]] DIRECTIONAL_API std::uint64_t
field_transport_atlas_hash(const FieldTransportAtlas &atlas) noexcept;

} // namespace authority
} // namespace directional

#endif // DIRECTIONAL_AUTHORITY_FIELD_TRANSPORT_ATLAS_H
