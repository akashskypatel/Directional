// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <algorithm>
#include <cstddef>
#include <map>
#include <set>
#include <variant>
#include <vector>

#include "EmbeddedGraphTopology.h"

namespace directional::geometry::global_topology_plan_detail {

using FragmentCornerIncidence =
    std::map<authority::SourceFaceTopologyKey,
             std::map<std::size_t, std::set<authority::SourceVertexId>>>;

using RegionCornerVerticesResult =
    std::variant<std::set<authority::SourceVertexId>, GlobalTopologyPlanError>;

inline RegionCornerVerticesResult region_corner_vertices(
    const embedded_graph_topology_detail::SourceTopologyIndex &topology,
    const GlobalTopologyRegion &region, const std::size_t owningOrbit,
    const FragmentCornerIncidence &fragmentCorners) {
  std::set<authority::SourceVertexId> candidateVertices;
  for (const auto &faceKey : region.sourceFaces) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) {
      GlobalTopologyPlanError failure;
      failure.code = GlobalTopologyPlanErrorCode::InvalidSourceBinding;
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    const auto cutFace = fragmentCorners.find(faceKey);
    if (cutFace == fragmentCorners.end()) {
      candidateVertices.insert(face->second.vertices.begin(),
                               face->second.vertices.end());
      continue;
    }
    const auto fragment = cutFace->second.find(owningOrbit);
    if (fragment == cutFace->second.end()) {
      GlobalTopologyPlanError failure;
      failure.code =
          GlobalTopologyPlanErrorCode::RegionSourceFaceOwningFragmentMissing;
      failure.region = region.id;
      failure.sourceFace = faceKey;
      failure.regionOwningFragmentOrbit = owningOrbit;
      failure.regionOwningFragmentOrbitIds.reserve(cutFace->second.size());
      for (const auto &[orbit, corners] : cutFace->second) {
        (void)corners;
        failure.regionOwningFragmentOrbitIds.push_back(orbit);
      }
      failure.regionOwningFragmentOrbitCount =
          failure.regionOwningFragmentOrbitIds.size();
      failure.regionOwningFragmentOrbitPresent =
          std::binary_search(failure.regionOwningFragmentOrbitIds.begin(),
                             failure.regionOwningFragmentOrbitIds.end(),
                             owningOrbit);
      return failure;
    }
    candidateVertices.insert(fragment->second.begin(), fragment->second.end());
  }
  return candidateVertices;
}

using RegionSingularityValidationResult =
    std::variant<std::vector<authority::FieldSingularityId>, GlobalTopologyPlanError>;

inline RegionSingularityValidationResult validate_region_interior_singularities(
    const std::vector<FieldAlignedSingularityPort> &ports,
    const GlobalTopologyRegion &region,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById,
    const std::set<authority::SourceVertexId> &candidateVertices) {
  std::set<authority::NetworkNodeId> boundaryNodes;
  for (const auto incidence : region.boundary) {
    const auto found = arcById.find(incidence.arc);
    if (found == arcById.end()) {
      GlobalTopologyPlanError failure;
      failure.code =
          GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork;
      failure.region = region.id;
      failure.arc = incidence.arc;
      return failure;
    }
    boundaryNodes.insert(found->second->firstNode);
    boundaryNodes.insert(found->second->secondNode);
  }

  std::map<authority::SourceVertexId, authority::FieldSingularityId>
      singularityAtVertex;
  for (const auto &port : ports) {
    singularityAtVertex.emplace(port.sourceVertex, port.singularity);
  }

  std::vector<authority::FieldSingularityId> boundarySingularities;
  for (const auto &[sourceVertex, singularity] : singularityAtVertex) {
    if (candidateVertices.count(sourceVertex) == 0U) continue;
    const bool onBoundary = std::any_of(
        ports.begin(), ports.end(),
        [&](const auto &port) {
          return port.singularity == singularity &&
                 boundaryNodes.count(port.node) != 0U;
        });
    if (!onBoundary) {
      GlobalTopologyPlanError failure;
      failure.code =
          GlobalTopologyPlanErrorCode::RegionContainsInteriorSingularity;
      failure.region = region.id;
      failure.singularity = singularity;
      failure.sourceVertex = sourceVertex;
      return failure;
    }
    boundarySingularities.push_back(singularity);
  }
  std::sort(boundarySingularities.begin(), boundarySingularities.end());
  boundarySingularities.erase(
      std::unique(boundarySingularities.begin(), boundarySingularities.end()),
      boundarySingularities.end());
  return boundarySingularities;
}

} // namespace directional::geometry::global_topology_plan_detail
