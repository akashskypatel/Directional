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
#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::geometry {

enum class GlobalTopologyPlanErrorCode : std::uint8_t;
enum class RotationSystemInconsistencyReason : std::uint8_t;

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
  std::vector<SurfaceCutCandidateEvidence> cutCandidates;
  [[nodiscard]] bool proves_cellularity() const noexcept;
  auto operator<=>(const SurfaceCutGraphCellularityCertificate &) const = default;
};

enum class SurfaceCutGraphErrorCode : std::uint8_t {
  InvalidSourceBinding = 0,
  InvalidAtlasBinding = 1,
  InvalidNetworkBinding = 2,
  NonManifoldSource = 3,
  CellularityNotEstablished = 4,
  CutSearchExhaustedBeforeCellularity = 5,
};

struct SurfaceCutGraphError {
  SurfaceCutGraphErrorCode code = SurfaceCutGraphErrorCode::InvalidSourceBinding;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
  std::optional<authority::SourceFaceTopologyKey> sourceFace;
  std::optional<GlobalTopologyPlanErrorCode> originatingTopologyError;
  std::size_t nonDiscComponentCount = 0U;
  std::size_t remainingAdmissibleEdgeCount = 0U;
  std::vector<SurfaceCutCandidateEvidence> cutCandidates;
  std::optional<RotationSystemInconsistencyReason>
      originatingRotationSystemInconsistencyReason;
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
[[nodiscard]] std::uint64_t surface_cut_graph_hash(const SurfaceCutGraph &graph) noexcept;

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CUT_GRAPH_H
