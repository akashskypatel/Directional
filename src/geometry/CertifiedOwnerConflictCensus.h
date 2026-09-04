#pragma once

#include <directional/geometry/SurfaceCutGraph.h>

#include <map>
#include <set>
#include <utility>
#include <vector>

namespace directional::geometry::detail {

inline std::vector<SurfaceCutGraphCertifiedOwnerConflict>
build_certified_owner_conflict_census(
    const std::map<authority::SourceEdgeTopologyKey,
                   std::vector<authority::SourceFaceTopologyKey>>
        &incidentFaces,
    const std::vector<SurfaceCutGraphSourceFaceOwnership> &owners,
    const std::set<authority::SourceEdgeTopologyKey> &barriers,
    const std::map<authority::SourceEdgeTopologyKey,
                   SurfaceCutGraphCertifiedOwnerConflictBarrierClass>
        &barrierClasses) {
  std::map<authority::SourceFaceTopologyKey,
           const SurfaceCutGraphSourceFaceOwnership *>
      ownerByFace;
  for (const auto &owner : owners) ownerByFace.emplace(owner.sourceFace, &owner);

  std::vector<SurfaceCutGraphCertifiedOwnerConflict> result;
  for (const auto &[edge, incident] : incidentFaces) {
    if (barriers.count(edge) != 0U || incident.size() != 2U) continue;

    const auto first = ownerByFace.find(incident[0]);
    const auto second = ownerByFace.find(incident[1]);
    if (first == ownerByFace.end() || second == ownerByFace.end()) continue;
    if (!first->second->established() || !second->second->established() ||
        first->second->certifiedFaceOrbits.size() != 1U ||
        second->second->certifiedFaceOrbits.size() != 1U) {
      continue;
    }

    const std::size_t firstOwner =
        first->second->certifiedFaceOrbits.front();
    const std::size_t secondOwner =
        second->second->certifiedFaceOrbits.front();
    if (firstOwner == secondOwner) continue;

    SurfaceCutGraphCertifiedOwnerConflict row;
    row.sourceEdge = edge;
    row.firstFace = incident[0];
    row.firstOwner = firstOwner;
    row.secondFace = incident[1];
    row.secondOwner = secondOwner;
    const auto classification = barrierClasses.find(edge);
    if (classification != barrierClasses.end()) {
      row.barrierClass = classification->second;
    }
    result.push_back(std::move(row));
  }
  return result;
}

} // namespace directional::geometry::detail
