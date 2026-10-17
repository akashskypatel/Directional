// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <cstddef>
#include <map>
#include <optional>
#include <set>
#include <utility>
#include <vector>

#include <directional/authority/AuthorityIds.h>

namespace directional::geometry::global_topology_certificate_diagnostics_detail {

using SourceFace = authority::SourceFaceTopologyKey;
using SourceEdge = authority::SourceEdgeTopologyKey;
using CertifiedFaceBySourceFace =
    std::map<SourceFace, std::optional<std::size_t>>;
using CertifiedFacesBySourceEdgeSide =
    std::map<std::pair<SourceFace, SourceEdge>, std::set<std::size_t>>;

struct CertificateFaceProjection {
  CertifiedFaceBySourceFace certifiedFaceBySourceFace;
  CertifiedFacesBySourceEdgeSide directCertifiedFacesBySourceEdgeSide;
};

/**
 * Diagnostic-only projection of actual embedded-graph certificate-face orbits
 * onto source triangles that are not cut through their interior by a trace.
 *
 * All labels originate in direct face-walk dart orbits supplied by the caller
 * and are filtered through the set of faces actually present in the
 * SurfaceCutGraph cellularity certificate. The propagation below only extends
 * a unique certified label across source-face adjacency that contains no
 * embedded graph edge and no trace-cut source face. It never reads or derives
 * from GlobalTopologyPlan seed ownership.
 */
inline CertificateFaceProjection resolve_certificate_face_projection(
    const std::vector<SourceFace> &sourceFaces,
    const std::map<SourceEdge, std::vector<SourceFace>> &incidentFaces,
    const std::set<SourceFace> &traceCutFaces,
    const std::set<SourceEdge> &embeddedGraphSourceEdges,
    const std::map<SourceFace, std::set<std::size_t>> &directCertifiedFaces,
    const CertifiedFacesBySourceEdgeSide &directCertifiedFacesBySourceEdgeSide,
    const std::set<std::size_t> &certificateFaceOrbits) {
  CertificateFaceProjection result;

  const auto filtered = [&](const std::set<std::size_t> &orbits) {
    std::set<std::size_t> retained;
    for (const std::size_t orbit : orbits) {
      if (certificateFaceOrbits.count(orbit) != 0U) retained.insert(orbit);
    }
    return retained;
  };

  for (const auto &[key, orbits] : directCertifiedFacesBySourceEdgeSide) {
    const auto retained = filtered(orbits);
    if (!retained.empty()) {
      result.directCertifiedFacesBySourceEdgeSide.emplace(key, retained);
    }
  }

  std::vector<SourceFace> eligible;
  eligible.reserve(sourceFaces.size());
  std::map<SourceFace, std::size_t> indexByFace;
  for (const SourceFace &face : sourceFaces) {
    result.certifiedFaceBySourceFace.emplace(face, std::nullopt);
    if (traceCutFaces.count(face) != 0U) continue;
    indexByFace.emplace(face, eligible.size());
    eligible.push_back(face);
  }

  std::vector<std::size_t> parent(eligible.size());
  for (std::size_t index = 0U; index < parent.size(); ++index) parent[index] = index;
  const auto find_root = [&](std::size_t index, const auto &self) -> std::size_t {
    if (parent[index] == index) return index;
    parent[index] = self(parent[index], self);
    return parent[index];
  };
  const auto unite = [&](const std::size_t first, const std::size_t second) {
    const std::size_t firstRoot = find_root(first, find_root);
    const std::size_t secondRoot = find_root(second, find_root);
    if (firstRoot == secondRoot) return;
    if (firstRoot < secondRoot) parent[secondRoot] = firstRoot;
    else parent[firstRoot] = secondRoot;
  };

  for (const auto &[edge, incident] : incidentFaces) {
    if (incident.size() != 2U || embeddedGraphSourceEdges.count(edge) != 0U)
      continue;
    const auto first = indexByFace.find(incident[0]);
    const auto second = indexByFace.find(incident[1]);
    if (first == indexByFace.end() || second == indexByFace.end()) continue;
    unite(first->second, second->second);
  }

  std::map<std::size_t, std::set<std::size_t>> certifiedFacesByComponent;
  for (const SourceFace &face : eligible) {
    const std::size_t root = find_root(indexByFace.at(face), find_root);
    const auto direct = directCertifiedFaces.find(face);
    if (direct != directCertifiedFaces.end()) {
      const auto retained = filtered(direct->second);
      certifiedFacesByComponent[root].insert(retained.begin(), retained.end());
    }
  }

  // A trace-cut neighboring face can certify the open edge side of an uncut
  // triangle without giving that cut triangle a single whole-face owner.
  for (const auto &[edge, incident] : incidentFaces) {
    if (incident.size() != 2U || embeddedGraphSourceEdges.count(edge) != 0U)
      continue;
    for (std::size_t side = 0U; side < 2U; ++side) {
      const auto uncut = indexByFace.find(incident[side]);
      if (uncut == indexByFace.end()) continue;
      const SourceFace &other = incident[side ^ 1U];
      if (traceCutFaces.count(other) == 0U) continue;
      const auto direct = result.directCertifiedFacesBySourceEdgeSide.find(
          std::make_pair(other, edge));
      if (direct == result.directCertifiedFacesBySourceEdgeSide.end() ||
          direct->second.size() != 1U) {
        continue;
      }
      const std::size_t root = find_root(uncut->second, find_root);
      certifiedFacesByComponent[root].insert(*direct->second.begin());
    }
  }

  for (const SourceFace &face : eligible) {
    const std::size_t root = find_root(indexByFace.at(face), find_root);
    const auto owners = certifiedFacesByComponent.find(root);
    if (owners != certifiedFacesByComponent.end() && owners->second.size() == 1U) {
      result.certifiedFaceBySourceFace[face] = *owners->second.begin();
    }
  }

  return result;
}

inline std::optional<std::size_t> certified_face_on_source_edge_side(
    const CertificateFaceProjection &projection, const SourceFace &face,
    const SourceEdge &edge) {
  const auto direct = projection.directCertifiedFacesBySourceEdgeSide.find(
      std::make_pair(face, edge));
  if (direct != projection.directCertifiedFacesBySourceEdgeSide.end() &&
      direct->second.size() == 1U) {
    return *direct->second.begin();
  }
  const auto wholeFace = projection.certifiedFaceBySourceFace.find(face);
  if (wholeFace != projection.certifiedFaceBySourceFace.end()) {
    return wholeFace->second;
  }
  return std::nullopt;
}

struct CertificatePairMeasurement {
  std::size_t examinedPairCount = 0U;
  std::size_t differingPairCount = 0U;
  struct Pair {
    SourceEdge sourceEdge;
    SourceFace firstFace;
    SourceFace secondFace;
    std::optional<std::size_t> firstCertifiedFace;
    std::optional<std::size_t> secondCertifiedFace;
  };
  std::vector<Pair> pairs;
  bool truncated = false;
};

inline CertificatePairMeasurement measure_uncut_certificate_pairs(
    const std::map<SourceEdge, std::vector<SourceFace>> &incidentFaces,
    const std::set<SourceFace> &uncutFaces,
    const std::set<SourceEdge> &componentBarriers,
    const CertifiedFaceBySourceFace &certifiedFaceBySourceFace,
    const std::size_t evidenceLimit) {
  CertificatePairMeasurement result;
  for (const auto &[edge, incident] : incidentFaces) {
    if (incident.size() != 2U || componentBarriers.count(edge) != 0U ||
        uncutFaces.count(incident[0]) == 0U ||
        uncutFaces.count(incident[1]) == 0U) {
      continue;
    }
    ++result.examinedPairCount;
    std::optional<std::size_t> first;
    std::optional<std::size_t> second;
    const auto firstFound = certifiedFaceBySourceFace.find(incident[0]);
    if (firstFound != certifiedFaceBySourceFace.end()) first = firstFound->second;
    const auto secondFound = certifiedFaceBySourceFace.find(incident[1]);
    if (secondFound != certifiedFaceBySourceFace.end()) second = secondFound->second;
    if (first.has_value() && second.has_value() && *first != *second) {
      ++result.differingPairCount;
    }
    if (result.pairs.size() < evidenceLimit) {
      result.pairs.push_back(
          CertificatePairMeasurement::Pair{edge, incident[0], incident[1],
                                           first, second});
    }
  }
  result.truncated = result.examinedPairCount > result.pairs.size();
  return result;
}

} // namespace directional::geometry::global_topology_certificate_diagnostics_detail
