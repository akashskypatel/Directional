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

/** Exact source-face support proof for one component of the cut surface. */
struct SurfaceCutGraphComponentCertificate {
  std::vector<authority::SourceFaceTopologyKey> sourceFaces;
  std::size_t boundaryWalkCount = 0U;
  bool sourceFacesConnected = false;
  int eulerCharacteristic = 0;
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  std::size_t faceCount = 0U;

  [[nodiscard]] bool proves_disc_topology() const noexcept {
    return boundaryWalkCount == 1U && sourceFacesConnected &&
           eulerCharacteristic == 1;
  }

  auto operator<=>(const SurfaceCutGraphComponentCertificate &) const = default;
};

/** A2a' certificate that the network plus published cuts is cellular. */
struct SurfaceCutGraphCellularityCertificate {
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  std::size_t faceCount = 0U;
  int eulerCharacteristic = 0;
  int sourceEulerCharacteristic = 0;
  std::vector<SurfaceCutGraphComponentCertificate> components;

  [[nodiscard]] bool proves_cellularity() const noexcept;

  auto operator<=>(const SurfaceCutGraphCellularityCertificate &) const = default;
};

enum class SurfaceCutGraphErrorCode : std::uint8_t {
  InvalidSourceBinding = 0,
  InvalidAtlasBinding = 1,
  InvalidNetworkBinding = 2,
  NonManifoldSource = 3,
  CellularityNotEstablished = 4,
};

struct SurfaceCutGraphError {
  SurfaceCutGraphErrorCode code = SurfaceCutGraphErrorCode::InvalidSourceBinding;
  std::optional<authority::SourceEdgeTopologyKey> sourceEdge;
  std::optional<authority::SourceFaceTopologyKey> sourceFace;

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

/**
 * Immutable A2a' cut authority. It may only add existing source edges and is
 * constructed before any GlobalTopologyPlan region exists.
 */
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

  [[nodiscard]] const std::vector<authority::SourceEdgeTopologyKey> &
  cut_edges() const noexcept {
    return cutEdges_;
  }
  [[nodiscard]] const SurfaceCutGraphCellularityCertificate &
  certificate() const noexcept {
    return certificate_;
  }
  [[nodiscard]] std::uint64_t source_digest() const noexcept {
    return sourceDigest_;
  }
  [[nodiscard]] std::uint64_t atlas_digest() const noexcept {
    return atlasDigest_;
  }
  [[nodiscard]] std::uint64_t network_digest() const noexcept {
    return networkDigest_;
  }
  [[nodiscard]] std::uint64_t semantic_digest() const noexcept {
    return semanticDigest_;
  }

private:
  friend class SurfaceCutGraphBuildResult;

  SurfaceCutGraph(std::vector<authority::SourceEdgeTopologyKey> cutEdges,
                  SurfaceCutGraphCellularityCertificate certificate,
                  std::uint64_t sourceDigest, std::uint64_t atlasDigest,
                  std::uint64_t networkDigest, std::uint64_t semanticDigest)
      : cutEdges_(std::move(cutEdges)), certificate_(std::move(certificate)),
        sourceDigest_(sourceDigest), atlasDigest_(atlasDigest),
        networkDigest_(networkDigest), semanticDigest_(semanticDigest) {}

  std::vector<authority::SourceEdgeTopologyKey> cutEdges_;
  SurfaceCutGraphCellularityCertificate certificate_;
  std::uint64_t sourceDigest_ = 0U;
  std::uint64_t atlasDigest_ = 0U;
  std::uint64_t networkDigest_ = 0U;
  std::uint64_t semanticDigest_ = 0U;
};

class SurfaceCutGraphBuildResult {
public:
  explicit SurfaceCutGraphBuildResult(SurfaceCutGraph graph)
      : state_(std::move(graph)) {}
  explicit SurfaceCutGraphBuildResult(SurfaceCutGraphError error)
      : state_(std::move(error)) {}

  [[nodiscard]] bool has_value() const noexcept {
    return std::holds_alternative<SurfaceCutGraph>(state_);
  }
  [[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
  [[nodiscard]] const SurfaceCutGraph &value() const {
    return std::get<SurfaceCutGraph>(state_);
  }
  [[nodiscard]] SurfaceCutGraph &value() {
    return std::get<SurfaceCutGraph>(state_);
  }
  [[nodiscard]] const SurfaceCutGraphError &error() const {
    return std::get<SurfaceCutGraphError>(state_);
  }

private:
  std::variant<SurfaceCutGraph, SurfaceCutGraphError> state_;
};

[[nodiscard]] const char *surface_cut_graph_error_code_name(
    SurfaceCutGraphErrorCode code) noexcept;
[[nodiscard]] std::uint64_t
surface_cut_graph_hash(const SurfaceCutGraph &graph) noexcept;

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CUT_GRAPH_H
