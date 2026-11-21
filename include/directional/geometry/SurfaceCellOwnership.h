// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H

#include <algorithm>
#include <array>
#include <limits>
#include <optional>
#include <cstdint>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include <directional/authority/AuthorityIds.h>

namespace directional::geometry {

struct SurfaceCellSourceChartIdentity {
  authority::FieldChartId chart;
  authority::SourceFaceTopologyKey face;

  auto operator<=>(const SurfaceCellSourceChartIdentity &) const = default;
};

struct SurfaceCellCanonicalIdentity {
  bool valid = false;
  std::vector<std::int64_t> values;

  // Exact typed semantic authority. Numeric `values` remain only for local
  // geometric/combinatorial representation. These fields are never decoded
  // from `values` and participate in exact equality/order.
  std::vector<authority::TopologyRegionId> topologyRegions;
  std::vector<authority::IsolationSheetId> isolationSheets;
  std::vector<authority::SurfaceCellOwnershipClassId> ownershipClasses;
  std::vector<SurfaceCellSourceChartIdentity> sourceCharts;
  std::vector<authority::HardRailId> hardRails;
  std::vector<authority::SourceVertexId> supportVertices;
  std::vector<authority::SourceEdgeTopologyKey> supportEdges;
  std::vector<authority::SourceFaceTopologyKey> supportFaces;

  [[nodiscard]] bool has_typed_authority() const noexcept {
    return !topologyRegions.empty() || !isolationSheets.empty() ||
           !ownershipClasses.empty() || !sourceCharts.empty() ||
           !hardRails.empty() || !supportVertices.empty() ||
           !supportEdges.empty() || !supportFaces.empty();
  }

  [[nodiscard]] std::uint64_t hash() const noexcept {
    std::uint64_t seed = 1469598103934665603ULL;
    const auto mix = [&](std::int64_t value) {
      seed ^= static_cast<std::uint64_t>(value);
      seed *= 1099511628211ULL;
    };
    mix(valid ? 1 : 0);
    mix(static_cast<std::int64_t>(values.size()));
    for (const std::int64_t value : values) {
      mix(value);
    }
    // Collision-domain hash only. Exact typed authority is deliberately not
    // numerically projected into this digest; equality below resolves all
    // collisions and remains the semantic authority.
    if (has_typed_authority()) {
      mix(0x54595045); // "TYPE"
      mix(static_cast<std::int64_t>(topologyRegions.size()));
      mix(static_cast<std::int64_t>(isolationSheets.size()));
      mix(static_cast<std::int64_t>(ownershipClasses.size()));
      mix(static_cast<std::int64_t>(sourceCharts.size()));
      mix(static_cast<std::int64_t>(hardRails.size()));
      mix(static_cast<std::int64_t>(supportVertices.size()));
      mix(static_cast<std::int64_t>(supportEdges.size()));
      mix(static_cast<std::int64_t>(supportFaces.size()));
    }
    return seed;
  }

  friend bool operator==(const SurfaceCellCanonicalIdentity &lhs,
                         const SurfaceCellCanonicalIdentity &rhs) {
    return std::tie(lhs.valid, lhs.values, lhs.topologyRegions,
                    lhs.isolationSheets, lhs.ownershipClasses,
                    lhs.sourceCharts, lhs.hardRails,
                    lhs.supportVertices, lhs.supportEdges,
                    lhs.supportFaces) ==
           std::tie(rhs.valid, rhs.values, rhs.topologyRegions,
                    rhs.isolationSheets, rhs.ownershipClasses,
                    rhs.sourceCharts, rhs.hardRails,
                    rhs.supportVertices, rhs.supportEdges,
                    rhs.supportFaces);
  }

  friend bool operator!=(const SurfaceCellCanonicalIdentity &lhs,
                         const SurfaceCellCanonicalIdentity &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const SurfaceCellCanonicalIdentity &lhs,
                        const SurfaceCellCanonicalIdentity &rhs) {
    return std::tie(lhs.valid, lhs.values, lhs.topologyRegions,
                    lhs.isolationSheets, lhs.ownershipClasses,
                    lhs.sourceCharts, lhs.hardRails,
                    lhs.supportVertices, lhs.supportEdges,
                    lhs.supportFaces) <
           std::tie(rhs.valid, rhs.values, rhs.topologyRegions,
                    rhs.isolationSheets, rhs.ownershipClasses,
                    rhs.sourceCharts, rhs.hardRails,
                    rhs.supportVertices, rhs.supportEdges,
                    rhs.supportFaces);
  }
};


/** Exact projection chart identity. Component/sheet membership is owned by
 * SourceTopologyRegions and source-label authority, never copied here. */
struct SourceProjectionChart {
  authority::FieldChartId chart;
  // Canonical source simplex. Source-face row is resolved only at container
  // access leaves through SourceTopologyRegions.
  authority::SourceFaceTopologyKey face;

  SourceProjectionChart(authority::FieldChartId fieldChart,
                        authority::SourceFaceTopologyKey sourceFace)
      : chart(fieldChart), face(std::move(sourceFace)) {}

  [[nodiscard]] bool valid() const noexcept { return true; }

  auto operator<=>(const SourceProjectionChart &) const = default;
};


struct SurfaceCellOwnershipClassRecord {
  // Semantic ownership is the typed producer region. Component/sheet values
  // are projections of SourceTopologyRegions and are never authority here.
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  // Canonical face-row-independent membership authority. The registry itself
  // owns this exact typed chart set once; cells carry only a typed class ID.
  std::vector<SourceProjectionChart> exactCharts;

  [[nodiscard]] bool valid() const {
    return sourceTopologyRegion.has_value() && !exactCharts.empty() &&
           std::is_sorted(exactCharts.begin(), exactCharts.end()) &&
           std::adjacent_find(exactCharts.begin(), exactCharts.end()) ==
               exactCharts.end() &&
           std::all_of(exactCharts.begin(), exactCharts.end(),
                       [](const SourceProjectionChart &chart) {
                         return chart.valid();
                       });
  }

  friend bool operator==(const SurfaceCellOwnershipClassRecord &lhs,
                         const SurfaceCellOwnershipClassRecord &rhs) {
    return lhs.sourceTopologyRegion == rhs.sourceTopologyRegion &&
           lhs.exactCharts == rhs.exactCharts;
  }

  friend bool operator<(const SurfaceCellOwnershipClassRecord &lhs,
                        const SurfaceCellOwnershipClassRecord &rhs) {
    return std::tie(lhs.sourceTopologyRegion, lhs.exactCharts) <
           std::tie(rhs.sourceTopologyRegion, rhs.exactCharts);
  }
};

/** One-way representation projection for diagnostics/export only. Never decode
 * this value back into ownership authority. */
inline std::int64_t surface_cell_ownership_class_representation_leaf(
    const std::optional<authority::SurfaceCellOwnershipClassId> &identity) {
  return identity.has_value()
             ? static_cast<std::int64_t>(identity.value().index())
             : -1;
}

struct SurfaceCellDomainIdentity {
  bool valid = false;
  SurfaceCellCanonicalIdentity orientedBoundary;
  SurfaceCellCanonicalIdentity undirectedBoundary;
  SurfaceCellCanonicalIdentity sourceSupport;
  // Canonical physical cell-side identity. It may contain several adjacent
  // per-face local chart IDs. sourceChartMap preserves those exact chart IDs.
  std::optional<authority::SurfaceCellOwnershipClassId>
      sourceOwnershipClass;
  SurfaceCellCanonicalIdentity sourceChartMap;
  int boundaryNodeCount = 0;
  int boundaryHalfedgeCount = 0;
  int sourceSupportCount = 0;
  std::optional<authority::TopologyRegionId> sourceTopologyRegion;

  [[nodiscard]] std::uint64_t hash() const {
    std::uint64_t seed = 1469598103934665603ULL;
    const auto mix = [&](const std::uint64_t value) {
      seed ^= value;
      seed *= 1099511628211ULL;
    };
    mix(valid ? 1U : 0U);
    mix(orientedBoundary.hash());
    mix(undirectedBoundary.hash());
    mix(sourceSupport.hash());
    mix(static_cast<std::uint64_t>(
        surface_cell_ownership_class_representation_leaf(
            sourceOwnershipClass)));
    mix(sourceChartMap.hash());
    mix(static_cast<std::uint64_t>(boundaryNodeCount));
    mix(static_cast<std::uint64_t>(boundaryHalfedgeCount));
    mix(static_cast<std::uint64_t>(sourceSupportCount));
    mix(sourceTopologyRegion.has_value()
            ? static_cast<std::uint64_t>(sourceTopologyRegion->index())
            : std::numeric_limits<std::uint64_t>::max());
    return seed;
  }

  [[nodiscard]] bool same_source_ownership(
      const SurfaceCellDomainIdentity &other) const {
    if (!valid || !other.valid || !sourceTopologyRegion.has_value() ||
        !other.sourceTopologyRegion.has_value() ||
        sourceTopologyRegion != other.sourceTopologyRegion) {
      return false;
    }
    if (sourceOwnershipClass.has_value() ||
        other.sourceOwnershipClass.has_value()) {
      return sourceOwnershipClass.has_value() &&
             other.sourceOwnershipClass.has_value() &&
             sourceOwnershipClass == other.sourceOwnershipClass;
    }
    return true;
  }

  [[nodiscard]] bool same_oriented_domain(
      const SurfaceCellDomainIdentity &other) const {
    return same_source_ownership(other) &&
           sourceChartMap == other.sourceChartMap &&
           boundaryNodeCount == other.boundaryNodeCount &&
           boundaryHalfedgeCount == other.boundaryHalfedgeCount &&
           sourceSupportCount == other.sourceSupportCount &&
           orientedBoundary == other.orientedBoundary &&
           sourceSupport == other.sourceSupport;
  }

  [[nodiscard]] bool same_undirected_support(
      const SurfaceCellDomainIdentity &other) const {
    return same_source_ownership(other) &&
           sourceChartMap == other.sourceChartMap &&
           boundaryHalfedgeCount == other.boundaryHalfedgeCount &&
           sourceSupportCount == other.sourceSupportCount &&
           undirectedBoundary == other.undirectedBoundary &&
           sourceSupport == other.sourceSupport;
  }

  friend bool operator==(const SurfaceCellDomainIdentity &lhs,
                         const SurfaceCellDomainIdentity &rhs) {
    return lhs.valid == rhs.valid &&
           lhs.sourceTopologyRegion == rhs.sourceTopologyRegion &&
           lhs.sourceOwnershipClass == rhs.sourceOwnershipClass &&
           lhs.sourceChartMap == rhs.sourceChartMap &&
           lhs.boundaryNodeCount == rhs.boundaryNodeCount &&
           lhs.boundaryHalfedgeCount == rhs.boundaryHalfedgeCount &&
           lhs.sourceSupportCount == rhs.sourceSupportCount &&
           lhs.orientedBoundary == rhs.orientedBoundary &&
           lhs.undirectedBoundary == rhs.undirectedBoundary &&
           lhs.sourceSupport == rhs.sourceSupport;
  }

  friend bool operator!=(const SurfaceCellDomainIdentity &lhs,
                         const SurfaceCellDomainIdentity &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const SurfaceCellDomainIdentity &lhs,
                        const SurfaceCellDomainIdentity &rhs) {
    if (lhs.valid != rhs.valid) {
      return lhs.valid < rhs.valid;
    }
    if (lhs.sourceTopologyRegion != rhs.sourceTopologyRegion) {
      return lhs.sourceTopologyRegion < rhs.sourceTopologyRegion;
    }
    if (lhs.sourceOwnershipClass != rhs.sourceOwnershipClass) {
      return lhs.sourceOwnershipClass < rhs.sourceOwnershipClass;
    }
    if (lhs.sourceChartMap != rhs.sourceChartMap) {
      return lhs.sourceChartMap < rhs.sourceChartMap;
    }
    if (lhs.sourceSupportCount != rhs.sourceSupportCount) {
      return lhs.sourceSupportCount < rhs.sourceSupportCount;
    }
    if (lhs.boundaryHalfedgeCount != rhs.boundaryHalfedgeCount) {
      return lhs.boundaryHalfedgeCount < rhs.boundaryHalfedgeCount;
    }
    if (lhs.boundaryNodeCount != rhs.boundaryNodeCount) {
      return lhs.boundaryNodeCount < rhs.boundaryNodeCount;
    }
    if (lhs.sourceSupport != rhs.sourceSupport) {
      return lhs.sourceSupport < rhs.sourceSupport;
    }
    if (lhs.orientedBoundary != rhs.orientedBoundary) {
      return lhs.orientedBoundary < rhs.orientedBoundary;
    }
    return lhs.undirectedBoundary < rhs.undirectedBoundary;
  }
};

enum class SurfaceCellDomainIdentityFailureKind : int {
  None = 0,
  EmptyBoundary = 1,
  OpenBoundary = 2,
  InvalidHalfedge = 3,
  InvalidTwin = 4,
  InvalidNext = 5,
  InvalidCellIncidence = 6,
  InvalidEndpointNode = 7,
  MissingEndpointSourceOccurrence = 8,
  InvalidEndpointBarycentric = 9,
  MixedSourceComponent = 10,
  MixedSourceSheet = 11,
  InvalidSourceSupport = 12,
  InvalidOrientedBoundaryIdentity = 13,
  InvalidUndirectedBoundaryIdentity = 14,
  RepeatedBoundaryNode = 15,
  RepeatedBoundaryHalfedge = 16,
  NonSimpleBoundary = 17,
  MissingSourceChart = 18,
  OwnershipRegistryMismatch = 19,
};

inline const char *surface_cell_domain_identity_failure_name(
    const SurfaceCellDomainIdentityFailureKind value) {
  switch (value) {
  case SurfaceCellDomainIdentityFailureKind::None:
    return "none";
  case SurfaceCellDomainIdentityFailureKind::EmptyBoundary:
    return "empty-boundary";
  case SurfaceCellDomainIdentityFailureKind::OpenBoundary:
    return "open-boundary";
  case SurfaceCellDomainIdentityFailureKind::InvalidHalfedge:
    return "invalid-halfedge";
  case SurfaceCellDomainIdentityFailureKind::InvalidTwin:
    return "invalid-twin";
  case SurfaceCellDomainIdentityFailureKind::InvalidNext:
    return "invalid-next";
  case SurfaceCellDomainIdentityFailureKind::InvalidCellIncidence:
    return "invalid-cell-incidence";
  case SurfaceCellDomainIdentityFailureKind::InvalidEndpointNode:
    return "invalid-endpoint-node";
  case SurfaceCellDomainIdentityFailureKind::MissingEndpointSourceOccurrence:
    return "missing-endpoint-source-occurrence";
  case SurfaceCellDomainIdentityFailureKind::InvalidEndpointBarycentric:
    return "invalid-endpoint-barycentric";
  case SurfaceCellDomainIdentityFailureKind::MixedSourceComponent:
    return "mixed-source-component";
  case SurfaceCellDomainIdentityFailureKind::MixedSourceSheet:
    return "mixed-source-sheet";
  case SurfaceCellDomainIdentityFailureKind::InvalidSourceSupport:
    return "invalid-source-support";
  case SurfaceCellDomainIdentityFailureKind::InvalidOrientedBoundaryIdentity:
    return "invalid-oriented-boundary-identity";
  case SurfaceCellDomainIdentityFailureKind::InvalidUndirectedBoundaryIdentity:
    return "invalid-undirected-boundary-identity";
  case SurfaceCellDomainIdentityFailureKind::RepeatedBoundaryNode:
    return "repeated-boundary-node";
  case SurfaceCellDomainIdentityFailureKind::RepeatedBoundaryHalfedge:
    return "repeated-boundary-halfedge";
  case SurfaceCellDomainIdentityFailureKind::NonSimpleBoundary:
    return "non-simple-boundary";
  case SurfaceCellDomainIdentityFailureKind::MissingSourceChart:
    return "missing-source-chart";
  case SurfaceCellDomainIdentityFailureKind::OwnershipRegistryMismatch:
    return "ownership-registry-mismatch";
  }
  return "unknown";
}

struct SurfaceCellDomainIdentityAudit {
  bool valid = false;
  SurfaceCellDomainIdentity identity;
  SurfaceCellDomainIdentityFailureKind failure =
      SurfaceCellDomainIdentityFailureKind::None;
  int cellId = -1;
  int halfedgeId = -1;
  int nodeId = -1;
  int sourceFace = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
};

enum class PureQuadStitchIdentityKind : int {
  Invalid = 0,
  ArrangementBoundaryNode = 1,
  CanonicalSourcePoint = 2,
  OrderedFeatureInterval = 3,
  GeneratedPatchInterior = 4,
};

inline const char *pure_quad_stitch_identity_kind_name(
    const PureQuadStitchIdentityKind value) {
  switch (value) {
  case PureQuadStitchIdentityKind::Invalid:
    return "invalid";
  case PureQuadStitchIdentityKind::ArrangementBoundaryNode:
    return "arrangement-node";
  case PureQuadStitchIdentityKind::CanonicalSourcePoint:
    return "source-point";
  case PureQuadStitchIdentityKind::OrderedFeatureInterval:
    return "feature-interval";
  case PureQuadStitchIdentityKind::GeneratedPatchInterior:
    return "patch-interior";
  }
  return "invalid";
}

struct PureQuadStitchIdentity {
  PureQuadStitchIdentityKind kind = PureQuadStitchIdentityKind::Invalid;
  SurfaceCellCanonicalIdentity canonical;

  [[nodiscard]] bool valid() const {
    return kind != PureQuadStitchIdentityKind::Invalid && canonical.valid;
  }

  [[nodiscard]] std::uint64_t hash() const {
    std::uint64_t seed = canonical.hash();
    seed ^= static_cast<std::uint64_t>(kind);
    seed *= 1099511628211ULL;
    return seed;
  }

  friend bool operator==(const PureQuadStitchIdentity &lhs,
                         const PureQuadStitchIdentity &rhs) {
    return lhs.kind == rhs.kind && lhs.canonical == rhs.canonical;
  }

  friend bool operator!=(const PureQuadStitchIdentity &lhs,
                         const PureQuadStitchIdentity &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const PureQuadStitchIdentity &lhs,
                        const PureQuadStitchIdentity &rhs) {
    if (lhs.kind != rhs.kind) {
      return static_cast<int>(lhs.kind) < static_cast<int>(rhs.kind);
    }
    return lhs.canonical < rhs.canonical;
  }
};

enum class SurfaceCellOwnershipConflictClass : int {
  None = 0,
  DuplicateOrientedDomain = 1,
  OverlappingUndirectedBoundary = 2,
  FalseVertexEquivalence = 3,
  CompletionTemplateOwnership = 4,
  SameCornerDistinctBoundaryClaim = 5,
  InvalidDomainIdentity = 6,
  Unclassified = 7,
};

inline const char *surface_cell_ownership_conflict_name(
    const SurfaceCellOwnershipConflictClass value) {
  switch (value) {
  case SurfaceCellOwnershipConflictClass::None:
    return "none";
  case SurfaceCellOwnershipConflictClass::DuplicateOrientedDomain:
    return "same-domain";
  case SurfaceCellOwnershipConflictClass::OverlappingUndirectedBoundary:
    return "overlapping-boundary";
  case SurfaceCellOwnershipConflictClass::FalseVertexEquivalence:
    return "false-merge";
  case SurfaceCellOwnershipConflictClass::CompletionTemplateOwnership:
    return "completion-template";
  case SurfaceCellOwnershipConflictClass::SameCornerDistinctBoundaryClaim:
    return "same-corner-distinct-boundary";
  case SurfaceCellOwnershipConflictClass::InvalidDomainIdentity:
    return "invalid-domain";
  case SurfaceCellOwnershipConflictClass::Unclassified:
    return "unclassified";
  }
  return "unclassified";
}

// Compact exact identity for one completed face owner. Hashes remain useful for
// diagnostics, but repair progress and state equality compare these values.
struct SurfaceCellCompletedFaceOwnerIdentity {
  SurfaceCellDomainIdentity domain;
  std::array<PureQuadStitchIdentity, 4> canonicalStitchCycle;
  std::array<PureQuadStitchIdentity, 4> canonicalAuthoritativeCycle;
  int sourcePatch = -1;
  int localQuad = -1;
  int completionBackend = -1;
  int completionVariant = 0;
  int boundaryVertexCount = 0;
  std::vector<int> sideEdgeCounts;

  [[nodiscard]] std::uint64_t hash() const {
    std::uint64_t seed = 1469598103934665603ULL;
    const auto mix = [&](const std::uint64_t value) {
      seed ^= value;
      seed *= 1099511628211ULL;
    };
    mix(domain.hash());
    for (const PureQuadStitchIdentity &identity : canonicalStitchCycle) {
      mix(identity.hash());
    }
    for (const PureQuadStitchIdentity &identity : canonicalAuthoritativeCycle) {
      mix(identity.hash());
    }
    mix(static_cast<std::uint64_t>(sourcePatch));
    mix(static_cast<std::uint64_t>(localQuad));
    mix(static_cast<std::uint64_t>(completionBackend));
    mix(static_cast<std::uint64_t>(completionVariant));
    mix(static_cast<std::uint64_t>(boundaryVertexCount));
    mix(static_cast<std::uint64_t>(sideEdgeCounts.size()));
    for (const int count : sideEdgeCounts) {
      mix(static_cast<std::uint64_t>(count));
    }
    return seed;
  }

  friend bool operator==(const SurfaceCellCompletedFaceOwnerIdentity &lhs,
                         const SurfaceCellCompletedFaceOwnerIdentity &rhs) {
    return std::tie(lhs.domain, lhs.canonicalStitchCycle,
                    lhs.canonicalAuthoritativeCycle, lhs.sourcePatch,
                    lhs.localQuad, lhs.completionBackend,
                    lhs.completionVariant, lhs.boundaryVertexCount,
                    lhs.sideEdgeCounts) ==
           std::tie(rhs.domain, rhs.canonicalStitchCycle,
                    rhs.canonicalAuthoritativeCycle, rhs.sourcePatch,
                    rhs.localQuad, rhs.completionBackend,
                    rhs.completionVariant, rhs.boundaryVertexCount,
                    rhs.sideEdgeCounts);
  }

  friend bool operator!=(const SurfaceCellCompletedFaceOwnerIdentity &lhs,
                         const SurfaceCellCompletedFaceOwnerIdentity &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const SurfaceCellCompletedFaceOwnerIdentity &lhs,
                        const SurfaceCellCompletedFaceOwnerIdentity &rhs) {
    return std::tie(lhs.domain, lhs.canonicalStitchCycle,
                    lhs.canonicalAuthoritativeCycle, lhs.sourcePatch,
                    lhs.localQuad, lhs.completionBackend,
                    lhs.completionVariant, lhs.boundaryVertexCount,
                    lhs.sideEdgeCounts) <
           std::tie(rhs.domain, rhs.canonicalStitchCycle,
                    rhs.canonicalAuthoritativeCycle, rhs.sourcePatch,
                    rhs.localQuad, rhs.completionBackend,
                    rhs.completionVariant, rhs.boundaryVertexCount,
                    rhs.sideEdgeCounts);
  }
};

struct SurfaceCellOwnershipConflict {
  SurfaceCellOwnershipConflictClass classification =
      SurfaceCellOwnershipConflictClass::None;
  SurfaceCellCompletedFaceOwnerIdentity firstOwner;
  SurfaceCellCompletedFaceOwnerIdentity secondOwner;
  int firstPatch = -1;
  int firstLocalQuad = -1;
  int secondPatch = -1;
  int secondLocalQuad = -1;
  std::uint64_t firstDomainHash = 0U;
  std::uint64_t secondDomainHash = 0U;
  std::uint64_t firstBoundaryNodeHash = 0U;
  std::uint64_t secondBoundaryNodeHash = 0U;
  std::uint64_t firstBoundaryHalfedgeHash = 0U;
  std::uint64_t secondBoundaryHalfedgeHash = 0U;
  std::uint64_t firstSourceSupportHash = 0U;
  std::uint64_t secondSourceSupportHash = 0U;
  int firstSourceSupportCount = 0;
  int secondSourceSupportCount = 0;
  int firstComponent = -1;
  int firstSheet = -1;
  int secondComponent = -1;
  int secondSheet = -1;
  int firstCompletionBackend = -1;
  int secondCompletionBackend = -1;
  int firstCompletionVariant = 0;
  int secondCompletionVariant = 0;
  int firstBoundaryNodeCount = 0;
  int secondBoundaryNodeCount = 0;
  int firstBoundaryHalfedgeCount = 0;
  int secondBoundaryHalfedgeCount = 0;
  int firstBoundaryVertexCount = 0;
  int secondBoundaryVertexCount = 0;
  std::vector<int> firstSideEdgeCounts;
  std::vector<int> secondSideEdgeCounts;
  std::array<int, 4> firstCornerIdentityKinds{{0, 0, 0, 0}};
  std::array<int, 4> secondCornerIdentityKinds{{0, 0, 0, 0}};
  std::array<std::uint64_t, 4> firstCornerIdentityHashes{{0, 0, 0, 0}};
  std::array<std::uint64_t, 4> secondCornerIdentityHashes{{0, 0, 0, 0}};
  std::array<std::uint64_t, 4> firstCornerAuthoritativeHashes{{0, 0, 0, 0}};
  std::array<std::uint64_t, 4> secondCornerAuthoritativeHashes{{0, 0, 0, 0}};
  std::array<int, 4> firstLocalVertices{{-1, -1, -1, -1}};
  std::array<int, 4> secondLocalVertices{{-1, -1, -1, -1}};
  std::array<int, 4> firstGlobalVertices{{-1, -1, -1, -1}};
  std::array<int, 4> secondGlobalVertices{{-1, -1, -1, -1}};

  [[nodiscard]] bool active() const {
    return classification != SurfaceCellOwnershipConflictClass::None;
  }

  [[nodiscard]] std::uint64_t exact_hash() const {
    std::uint64_t seed = 1469598103934665603ULL;
    const auto mix = [&](const std::uint64_t value) {
      seed ^= value;
      seed *= 1099511628211ULL;
    };
    mix(static_cast<std::uint64_t>(classification));
    mix(firstOwner.hash());
    mix(secondOwner.hash());
    return seed;
  }

  friend bool operator==(const SurfaceCellOwnershipConflict &lhs,
                         const SurfaceCellOwnershipConflict &rhs) {
    return lhs.classification == rhs.classification &&
           lhs.firstOwner == rhs.firstOwner &&
           lhs.secondOwner == rhs.secondOwner;
  }

  friend bool operator!=(const SurfaceCellOwnershipConflict &lhs,
                         const SurfaceCellOwnershipConflict &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const SurfaceCellOwnershipConflict &lhs,
                        const SurfaceCellOwnershipConflict &rhs) {
    return std::tie(lhs.classification, lhs.firstOwner, lhs.secondOwner) <
           std::tie(rhs.classification, rhs.firstOwner, rhs.secondOwner);
  }
};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H
