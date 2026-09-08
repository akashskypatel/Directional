#pragma once

#include <algorithm>
#include <cstdint>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#include <directional/authority/FieldTransportAtlas.h>

namespace directional::geometry::detail {

inline void source_face_set_digest_consume(std::uint64_t &hash,
                                         const std::uint64_t value) noexcept {
  for (std::size_t byte = 0U; byte < sizeof(value); ++byte) {
    hash ^= (value >> (8U * byte)) & 0xffU;
    hash *= 1099511628211ULL;
  }
}

inline std::uint64_t source_face_set_digest(
    std::vector<authority::SourceFaceTopologyKey> faces) noexcept {
  std::sort(faces.begin(), faces.end());
  faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  std::uint64_t hash = 1469598103934665603ULL;
  source_face_set_digest_consume(hash, faces.size());
  for (const auto &face : faces) {
    const auto vertices = face.vertices();
    source_face_set_digest_consume(hash, vertices.size());
    for (const auto vertex : vertices) {
      source_face_set_digest_consume(hash, vertex.index());
    }
  }
  return hash;
}

struct SourceFaceComponentPartition {
  std::vector<std::vector<authority::SourceFaceTopologyKey>> components;
  std::map<authority::SourceFaceTopologyKey, std::size_t> componentByFace;
};

inline SourceFaceComponentPartition build_source_face_component_partition(
    std::vector<authority::SourceFaceTopologyKey> faces,
    const std::map<authority::SourceEdgeTopologyKey,
                   std::vector<authority::SourceFaceTopologyKey>> &incidentFaces,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  std::sort(faces.begin(), faces.end());
  faces.erase(std::unique(faces.begin(), faces.end()), faces.end());

  std::map<authority::SourceFaceTopologyKey, std::size_t> indexByFace;
  for (std::size_t index = 0U; index < faces.size(); ++index) {
    indexByFace.emplace(faces[index], index);
  }

  std::vector<std::size_t> parent(faces.size());
  std::iota(parent.begin(), parent.end(), 0U);
  const auto root = [&](const auto &self, const std::size_t value) -> std::size_t {
    return parent[value] == value ? value : self(self, parent[value]);
  };
  const auto unite = [&](const std::size_t first, const std::size_t second) {
    const std::size_t firstRoot = root(root, first);
    const std::size_t secondRoot = root(root, second);
    if (firstRoot == secondRoot) return;
    if (firstRoot < secondRoot) parent[secondRoot] = firstRoot;
    else parent[firstRoot] = secondRoot;
  };

  for (const auto &[edge, incident] : incidentFaces) {
    if (incident.size() != 2U || barriers.count(edge) != 0U) continue;
    const auto first = indexByFace.find(incident[0]);
    const auto second = indexByFace.find(incident[1]);
    if (first != indexByFace.end() && second != indexByFace.end()) {
      unite(first->second, second->second);
    }
  }

  std::map<std::size_t, std::vector<authority::SourceFaceTopologyKey>> grouped;
  for (std::size_t index = 0U; index < faces.size(); ++index) {
    grouped[root(root, index)].push_back(faces[index]);
  }

  SourceFaceComponentPartition result;
  result.components.reserve(grouped.size());
  for (auto &[rootIndex, component] : grouped) {
    (void)rootIndex;
    std::sort(component.begin(), component.end());
    result.components.push_back(std::move(component));
  }
  std::sort(result.components.begin(), result.components.end());
  for (std::size_t componentIndex = 0U;
       componentIndex < result.components.size(); ++componentIndex) {
    for (const auto &face : result.components[componentIndex]) {
      result.componentByFace.emplace(face, componentIndex);
    }
  }
  return result;
}

} // namespace directional::geometry::detail
