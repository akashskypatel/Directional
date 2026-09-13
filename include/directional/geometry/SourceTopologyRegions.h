// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SOURCE_TOPOLOGY_REGIONS_H
#define DIRECTIONAL_GEOMETRY_SOURCE_TOPOLOGY_REGIONS_H

#include <algorithm>
#include <cstddef>
#include <optional>
#include <set>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/AuthorityIds.h>

namespace directional::geometry {

/** Row-independent authority for one source face inside a topology region. */
struct SourceRegionFaceAuthority {
  authority::SourceFaceTopologyKey topology;
  authority::IsolationSheetId sheet;

  auto operator<=>(const SourceRegionFaceAuthority &) const = default;
};

/**
 * Complete source-adjacent producer region.
 *
 * Construction is checked and the published representation is immutable from
 * outside the class. Component ownership is stored once per region; isolation
 * sheet ownership is stored once per member face beside its row-independent
 * source-face topology key.
 */
class SurfaceTopologyRegion {
public:
  [[nodiscard]] static std::optional<SurfaceTopologyRegion>
  make(authority::TopologyRegionId id,
       authority::SourceComponentId sourceComponent,
       std::vector<SourceRegionFaceAuthority> faces,
       std::vector<authority::SourceEdgeTopologyKey> boundaryEdges,
       std::vector<authority::SourceEdgeTopologyKey> isolationSeams,
       int eulerCharacteristic, int boundaryLoopCount);

  [[nodiscard]] authority::TopologyRegionId id() const noexcept { return id_; }
  [[nodiscard]] authority::SourceComponentId component() const noexcept {
    return sourceComponent_;
  }
  [[nodiscard]] int euler_characteristic() const noexcept {
    return eulerCharacteristic_;
  }
  [[nodiscard]] int boundary_loop_count() const noexcept {
    return boundaryLoopCount_;
  }
  [[nodiscard]] const std::vector<SourceRegionFaceAuthority> &faces() const noexcept {
    return faces_;
  }
  [[nodiscard]] const std::vector<authority::SourceEdgeTopologyKey> &
  boundary_edges() const noexcept {
    return boundaryEdgeTopology_;
  }
  [[nodiscard]] const std::vector<authority::SourceEdgeTopologyKey> &
  isolation_seams() const noexcept {
    return internalIsolationSeamTopology_;
  }

  /** Derived diagnostic/query projection; sheet authority remains face-owned. */
  [[nodiscard]] std::vector<authority::IsolationSheetId> isolation_sheets() const {
    std::vector<authority::IsolationSheetId> result;
    result.reserve(faces_.size());
    for (const SourceRegionFaceAuthority &face : faces_) {
      result.push_back(face.sheet);
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
  }

  [[nodiscard]] const SourceRegionFaceAuthority *
  find_face(const authority::SourceFaceTopologyKey &topology) const noexcept {
    const auto it = std::lower_bound(
        faces_.begin(), faces_.end(), topology,
        [](const SourceRegionFaceAuthority &face,
           const authority::SourceFaceTopologyKey &key) {
          return face.topology < key;
        });
    return it != faces_.end() && it->topology == topology ? &*it : nullptr;
  }

  auto operator<=>(const SurfaceTopologyRegion &) const = default;

private:
  SurfaceTopologyRegion(
      authority::TopologyRegionId id,
      authority::SourceComponentId sourceComponent,
      std::vector<SourceRegionFaceAuthority> faces,
      std::vector<authority::SourceEdgeTopologyKey> boundaryEdges,
      std::vector<authority::SourceEdgeTopologyKey> isolationSeams,
      int eulerCharacteristic, int boundaryLoopCount)
      : id_(id), sourceComponent_(sourceComponent),
        eulerCharacteristic_(eulerCharacteristic),
        boundaryLoopCount_(boundaryLoopCount), faces_(std::move(faces)),
        boundaryEdgeTopology_(std::move(boundaryEdges)),
        internalIsolationSeamTopology_(std::move(isolationSeams)) {}

  authority::TopologyRegionId id_;
  authority::SourceComponentId sourceComponent_;
  int eulerCharacteristic_ = 0;
  int boundaryLoopCount_ = 0;
  std::vector<SourceRegionFaceAuthority> faces_;
  std::vector<authority::SourceEdgeTopologyKey> boundaryEdgeTopology_;
  std::vector<authority::SourceEdgeTopologyKey> internalIsolationSeamTopology_;
};

/**
 * Complete row-to-region/member bijection for source-topology authority.
 *
 * SourceFaceId is retained only as a checked matrix-row locator. Semantic
 * region/component/sheet identity is obtained from the row-independent member
 * authority stored by SurfaceTopologyRegion.
 */
class SourceTopologyRegions {
public:
  [[nodiscard]] static std::optional<SourceTopologyRegions>
  make(std::vector<authority::SourceFaceTopologyKey> rowTopology,
       const std::vector<authority::SourceComponentId> &rowComponents,
       const std::vector<authority::IsolationSheetId> &rowSheets,
       std::vector<SurfaceTopologyRegion> regions);

  [[nodiscard]] std::size_t face_count() const noexcept {
    return rowBindings_.size();
  }
  [[nodiscard]] bool complete_for_face_count(std::size_t faceCount) const noexcept {
    return rowBindings_.size() == faceCount && !regions_.empty();
  }

  /**
   * Exact binding check between this authority product and a supplied source
   * triangle matrix.  Face count alone is not sufficient authority: each row
   * must reconstruct the same row-independent topology key owned at ingress.
   * When sourceVertexCount is nonzero it is also the checked vertex-ID extent;
   * callers without a vertex container may pass zero to infer the minimum
   * extent from the matrix after rejecting negative/repeated vertices.
   */
  [[nodiscard]] bool matches_source_faces(
      const Eigen::MatrixXi &sourceFaces,
      std::size_t sourceVertexCount = 0U) const noexcept {
    if (sourceFaces.cols() != 3 || sourceFaces.rows() <= 0 ||
        !complete_for_face_count(
            static_cast<std::size_t>(sourceFaces.rows()))) {
      return false;
    }
    if (sourceVertexCount == 0U) {
      int maximumVertex = -1;
      for (int face = 0; face < sourceFaces.rows(); ++face) {
        for (int corner = 0; corner < 3; ++corner) {
          const int vertex = sourceFaces(face, corner);
          if (vertex < 0) return false;
          maximumVertex = std::max(maximumVertex, vertex);
        }
      }
      if (maximumVertex < 0) return false;
      sourceVertexCount = static_cast<std::size_t>(maximumVertex) + 1U;
    }
    for (int face = 0; face < sourceFaces.rows(); ++face) {
      const auto first = authority::SourceVertexId::from_index(
          sourceFaces(face, 0), sourceVertexCount);
      const auto second = authority::SourceVertexId::from_index(
          sourceFaces(face, 1), sourceVertexCount);
      const auto third = authority::SourceVertexId::from_index(
          sourceFaces(face, 2), sourceVertexCount);
      if (!first || !second || !third) return false;
      const auto topology = authority::SourceFaceTopologyKey::make(
          {first.value(), second.value(), third.value()});
      const auto row = authority::SourceFaceId::from_index(
          face, static_cast<std::size_t>(sourceFaces.rows()));
      if (!topology || !row ||
          topology.value() != topology_for_row(row.value())) {
        return false;
      }
    }
    return true;
  }
  [[nodiscard]] const std::vector<SurfaceTopologyRegion> &regions() const noexcept {
    return regions_;
  }

  [[nodiscard]] authority::TopologyRegionId
  region_for_row(authority::SourceFaceId row) const {
    return rowBindings_.at(row.index()).region;
  }
  [[nodiscard]] const SourceRegionFaceAuthority &
  face_authority(authority::SourceFaceId row) const {
    const RowBinding &binding = rowBindings_.at(row.index());
    return regions_.at(binding.region.index()).faces().at(binding.memberIndex);
  }
  [[nodiscard]] const SurfaceTopologyRegion &
  region(authority::TopologyRegionId id) const {
    return regions_.at(id.index());
  }
  [[nodiscard]] authority::SourceComponentId
  component_for_row(authority::SourceFaceId row) const {
    return region(region_for_row(row)).component();
  }
  [[nodiscard]] authority::IsolationSheetId
  sheet_for_row(authority::SourceFaceId row) const {
    return face_authority(row).sheet;
  }
  [[nodiscard]] const authority::SourceFaceTopologyKey &
  topology_for_row(authority::SourceFaceId row) const {
    return face_authority(row).topology;
  }
  [[nodiscard]] std::vector<authority::SourceFaceId>
  rows_for_region(authority::TopologyRegionId id) const {
    std::vector<authority::SourceFaceId> rows;
    const SurfaceTopologyRegion &owner = region(id);
    rows.reserve(owner.faces().size());
    for (const SourceRegionFaceAuthority &face : owner.faces()) {
      const auto row = row_for_topology(face.topology);
      if (row.has_value()) {
        rows.push_back(*row);
      }
    }
    std::sort(rows.begin(), rows.end());
    return rows;
  }

  [[nodiscard]] std::optional<authority::SourceFaceId>
  row_for_topology(const authority::SourceFaceTopologyKey &topology) const {
    const auto it = std::lower_bound(
        topologyRows_.begin(), topologyRows_.end(), topology,
        [](const TopologyRow &entry,
           const authority::SourceFaceTopologyKey &key) {
          return entry.topology < key;
        });
    if (it == topologyRows_.end() || it->topology != topology) {
      return std::nullopt;
    }
    return it->row;
  }

  /** Derived row locator projection for matrix/container access only. */
  [[nodiscard]] std::vector<authority::TopologyRegionId> region_by_face() const {
    std::vector<authority::TopologyRegionId> result;
    result.reserve(rowBindings_.size());
    for (const RowBinding &binding : rowBindings_) {
      result.push_back(binding.region);
    }
    return result;
  }

private:
  struct RowBinding {
    RowBinding(authority::TopologyRegionId regionValue, std::size_t member)
        : region(regionValue), memberIndex(member) {}
    authority::TopologyRegionId region;
    std::size_t memberIndex = 0;
  };

  struct TopologyRow {
    TopologyRow(authority::SourceFaceTopologyKey topologyValue,
                authority::SourceFaceId rowValue)
        : topology(std::move(topologyValue)), row(rowValue) {}
    authority::SourceFaceTopologyKey topology;
    authority::SourceFaceId row;
  };

  SourceTopologyRegions(std::vector<SurfaceTopologyRegion> regions,
                        std::vector<RowBinding> rowBindings,
                        std::vector<TopologyRow> topologyRows)
      : regions_(std::move(regions)), rowBindings_(std::move(rowBindings)),
        topologyRows_(std::move(topologyRows)) {}

  std::vector<SurfaceTopologyRegion> regions_;
  std::vector<RowBinding> rowBindings_;
  std::vector<TopologyRow> topologyRows_;
};

[[nodiscard]] std::uint64_t
surface_topology_region_hash(const SurfaceTopologyRegion &region);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SOURCE_TOPOLOGY_REGIONS_H
