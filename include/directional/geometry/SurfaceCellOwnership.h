// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H

#include <array>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

namespace directional::geometry {

struct SurfaceCellCanonicalIdentity {
  bool valid = false;
  std::vector<std::int64_t> values;

  [[nodiscard]] std::uint64_t hash() const {
    std::uint64_t seed = 1469598103934665603ULL;
    const auto mix = [&](const std::int64_t value) {
      seed ^= static_cast<std::uint64_t>(value);
      seed *= 1099511628211ULL;
    };
    mix(valid ? 1 : 0);
    mix(static_cast<std::int64_t>(values.size()));
    for (const std::int64_t value : values) {
      mix(value);
    }
    return seed;
  }

  friend bool operator==(const SurfaceCellCanonicalIdentity &lhs,
                         const SurfaceCellCanonicalIdentity &rhs) {
    return lhs.valid == rhs.valid && lhs.values == rhs.values;
  }

  friend bool operator!=(const SurfaceCellCanonicalIdentity &lhs,
                         const SurfaceCellCanonicalIdentity &rhs) {
    return !(lhs == rhs);
  }

  friend bool operator<(const SurfaceCellCanonicalIdentity &lhs,
                        const SurfaceCellCanonicalIdentity &rhs) {
    if (lhs.valid != rhs.valid) {
      return lhs.valid < rhs.valid;
    }
    return lhs.values < rhs.values;
  }
};

struct SurfaceCellDomainIdentity {
  bool valid = false;
  SurfaceCellCanonicalIdentity orientedBoundary;
  SurfaceCellCanonicalIdentity undirectedBoundary;
  SurfaceCellCanonicalIdentity sourceSupport;
  int boundaryNodeCount = 0;
  int boundaryHalfedgeCount = 0;
  int sourceSupportCount = 0;
  int sourceComponent = -1;
  int sourceSheet = -1;

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
    mix(static_cast<std::uint64_t>(boundaryNodeCount));
    mix(static_cast<std::uint64_t>(boundaryHalfedgeCount));
    mix(static_cast<std::uint64_t>(sourceSupportCount));
    mix(static_cast<std::uint64_t>(sourceComponent));
    mix(static_cast<std::uint64_t>(sourceSheet));
    return seed;
  }

  [[nodiscard]] bool same_oriented_domain(
      const SurfaceCellDomainIdentity &other) const {
    return valid && other.valid &&
           sourceComponent == other.sourceComponent &&
           sourceSheet == other.sourceSheet &&
           boundaryNodeCount == other.boundaryNodeCount &&
           boundaryHalfedgeCount == other.boundaryHalfedgeCount &&
           sourceSupportCount == other.sourceSupportCount &&
           orientedBoundary == other.orientedBoundary &&
           sourceSupport == other.sourceSupport;
  }

  [[nodiscard]] bool same_undirected_support(
      const SurfaceCellDomainIdentity &other) const {
    return valid && other.valid &&
           sourceComponent == other.sourceComponent &&
           sourceSheet == other.sourceSheet &&
           boundaryHalfedgeCount == other.boundaryHalfedgeCount &&
           sourceSupportCount == other.sourceSupportCount &&
           undirectedBoundary == other.undirectedBoundary &&
           sourceSupport == other.sourceSupport;
  }

  friend bool operator==(const SurfaceCellDomainIdentity &lhs,
                         const SurfaceCellDomainIdentity &rhs) {
    return lhs.valid == rhs.valid &&
           lhs.sourceComponent == rhs.sourceComponent &&
           lhs.sourceSheet == rhs.sourceSheet &&
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
    if (lhs.sourceComponent != rhs.sourceComponent) {
      return lhs.sourceComponent < rhs.sourceComponent;
    }
    if (lhs.sourceSheet != rhs.sourceSheet) {
      return lhs.sourceSheet < rhs.sourceSheet;
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
