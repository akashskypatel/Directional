#pragma once

#include "SourceFaceComponentPartition.h"

#include <directional/geometry/SurfaceCutGraph.h>

#include <cstddef>
#include <map>
#include <optional>
#include <vector>

namespace directional::geometry::detail {

struct CertifiedSourceFaceOwnerComponentConsistency {
  std::size_t component = 0U;
  std::vector<authority::SourceFaceTopologyKey> faces;
  std::map<std::size_t, std::size_t> ownerMultiplicity;
  std::optional<authority::SourceFaceTopologyKey> invalidFace;
};

struct CertifiedSourceFaceOwnerConsistency {
  std::vector<CertifiedSourceFaceOwnerComponentConsistency> components;
  std::optional<std::size_t> firstConflictComponent;

  [[nodiscard]] bool consistent() const noexcept {
    return !firstConflictComponent.has_value();
  }
};

inline CertifiedSourceFaceOwnerConsistency
check_certified_source_face_owner_consistency(
    const SourceFaceComponentPartition &partition,
    const SurfaceCutGraphCellularityCertificate &certificate) {
  CertifiedSourceFaceOwnerConsistency result;
  result.components.reserve(partition.components.size());

  for (std::size_t component = 0U; component < partition.components.size();
       ++component) {
    CertifiedSourceFaceOwnerComponentConsistency row;
    row.component = component;
    row.faces = partition.components[component];

    for (const auto &face : row.faces) {
      const auto *owner = certificate.find_source_face_owner(face);
      if (owner == nullptr || owner->trace_crossed() ||
          !owner->established() ||
          owner->certifiedFaceOrbits.size() != 1U) {
        if (!row.invalidFace.has_value()) row.invalidFace = face;
        if (owner != nullptr) {
          for (const std::size_t orbit : owner->certifiedFaceOrbits) {
            ++row.ownerMultiplicity[orbit];
          }
        }
        continue;
      }
      ++row.ownerMultiplicity[owner->certifiedFaceOrbits.front()];
    }

    const bool conflict = row.invalidFace.has_value() ||
                          row.ownerMultiplicity.size() != 1U;
    result.components.push_back(std::move(row));
    if (conflict && !result.firstConflictComponent.has_value()) {
      result.firstConflictComponent = component;
    }
  }

  return result;
}

} // namespace directional::geometry::detail
