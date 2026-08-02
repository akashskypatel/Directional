// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H

#include <cstdint>
#include <string>
#include <utility>
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
    mix(static_cast<std::uint64_t>(sourceComponent));
    mix(static_cast<std::uint64_t>(sourceSheet));
    return seed;
  }

  [[nodiscard]] bool same_oriented_domain(
      const SurfaceCellDomainIdentity &other) const {
    return valid && other.valid &&
           sourceComponent == other.sourceComponent &&
           sourceSheet == other.sourceSheet &&
           orientedBoundary == other.orientedBoundary &&
           sourceSupport == other.sourceSupport;
  }

  [[nodiscard]] bool same_undirected_support(
      const SurfaceCellDomainIdentity &other) const {
    return valid && other.valid &&
           sourceComponent == other.sourceComponent &&
           sourceSheet == other.sourceSheet &&
           undirectedBoundary == other.undirectedBoundary &&
           sourceSupport == other.sourceSupport;
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
    if (lhs.sourceSupport != rhs.sourceSupport) {
      return lhs.sourceSupport < rhs.sourceSupport;
    }
    if (lhs.orientedBoundary != rhs.orientedBoundary) {
      return lhs.orientedBoundary < rhs.orientedBoundary;
    }
    return lhs.undirectedBoundary < rhs.undirectedBoundary;
  }
};

enum class SurfaceCellOwnershipConflictClass : int {
  None = 0,
  DuplicateOrientedDomain = 1,
  OverlappingUndirectedBoundary = 2,
  FalseVertexEquivalence = 3,
  CompletionTemplateOwnership = 4,
  InvalidDomainIdentity = 5,
  Unclassified = 6,
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
  case SurfaceCellOwnershipConflictClass::InvalidDomainIdentity:
    return "invalid-domain";
  case SurfaceCellOwnershipConflictClass::Unclassified:
    return "unclassified";
  }
  return "unclassified";
}

struct SurfaceCellOwnershipConflict {
  SurfaceCellOwnershipConflictClass classification =
      SurfaceCellOwnershipConflictClass::None;
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
  int firstComponent = -1;
  int firstSheet = -1;
  int secondComponent = -1;
  int secondSheet = -1;
  std::vector<std::uint64_t> firstCornerIdentityHashes;
  std::vector<std::uint64_t> secondCornerIdentityHashes;

  [[nodiscard]] bool active() const {
    return classification != SurfaceCellOwnershipConflictClass::None;
  }
};

enum class PureQuadStitchIdentityKind : int {
  Invalid = 0,
  ArrangementBoundaryNode = 1,
  CanonicalSourcePoint = 2,
  OrderedFeatureInterval = 3,
  GeneratedPatchInterior = 4,
};

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

  friend bool operator<(const PureQuadStitchIdentity &lhs,
                        const PureQuadStitchIdentity &rhs) {
    if (lhs.kind != rhs.kind) {
      return static_cast<int>(lhs.kind) < static_cast<int>(rhs.kind);
    }
    return lhs.canonical < rhs.canonical;
  }
};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CELL_OWNERSHIP_H
