#pragma once

#include "SourceFaceComponentPartition.h"

#include <directional/geometry/SurfaceCutGraph.h>

#include <algorithm>
#include <map>
#include <set>
#include <variant>
#include <vector>

namespace directional::geometry::detail {

inline std::vector<std::vector<SurfaceCutGraphUncutComponentVertexTransitCensus>>
build_uncut_component_vertex_transit_census(
    const std::vector<FieldAlignedCandidateTrace> &traces,
    const std::map<authority::SourceVertexId,
                   std::vector<authority::SourceFaceTopologyKey>>
        &incidentFacesByVertex,
    const std::map<authority::SourceEdgeTopologyKey,
                   std::vector<authority::SourceFaceTopologyKey>> &incidentFaces,
    const SourceFaceComponentPartition &partition,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  std::vector<std::vector<SurfaceCutGraphUncutComponentVertexTransitCensus>>
      result(partition.components.size());

  for (const auto &trace : traces) {
    for (std::size_t segmentIndex = 0U; segmentIndex < trace.segments.size();
         ++segmentIndex) {
      const auto support = trace.segments[segmentIndex].entryPoint.source_support();
      if (!support.has_value()) continue;
      const auto *vertex = std::get_if<authority::SourceVertexSupport>(&*support);
      if (vertex == nullptr) continue;

      const auto incident = incidentFacesByVertex.find(vertex->vertex);
      if (incident == incidentFacesByVertex.end()) continue;
      std::map<std::size_t, std::vector<authority::SourceFaceTopologyKey>>
          facesByComponent;
      for (const auto &face : incident->second) {
        const auto component = partition.componentByFace.find(face);
        if (component == partition.componentByFace.end()) continue;
        facesByComponent[component->second].push_back(face);
      }

      for (auto &[component, faces] : facesByComponent) {
        std::sort(faces.begin(), faces.end());
        faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
        SurfaceCutGraphUncutComponentVertexTransitCensus row{
            trace.id, segmentIndex, vertex->vertex, faces};

        const std::set<authority::SourceFaceTopologyKey> componentFaces(
            faces.begin(), faces.end());
        for (const auto &[edge, edgeFaces] : incidentFaces) {
          if (row.adjacentAcrossNonBarrierEdge || barriers.count(edge) != 0U ||
              (edge.first() != vertex->vertex &&
               edge.second() != vertex->vertex)) {
            continue;
          }
          std::vector<authority::SourceFaceTopologyKey> localFaces;
          for (const auto &face : edgeFaces) {
            if (componentFaces.count(face) != 0U) localFaces.push_back(face);
          }
          if (localFaces.size() < 2U) continue;
          std::sort(localFaces.begin(), localFaces.end());
          row.adjacentAcrossNonBarrierEdge = true;
          row.adjacentNonBarrierEdge = edge;
          row.firstAdjacentFace = localFaces[0];
          row.secondAdjacentFace = localFaces[1];
        }
        result[component].push_back(std::move(row));
      }
    }
  }

  for (auto &rows : result) std::sort(rows.begin(), rows.end());
  return result;
}

} // namespace directional::geometry::detail
