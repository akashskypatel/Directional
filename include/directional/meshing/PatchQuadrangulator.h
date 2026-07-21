// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_PATCH_QUADRANGULATOR_H
#define DIRECTIONAL_MESHING_PATCH_QUADRANGULATOR_H

#include <algorithm>
#include <map>
#include <set>
#include <vector>

#include <directional/meshing/PatchClassifier.h>
#include <directional/validation/MeshValidator.h>

namespace directional {
namespace detail {

struct PatchQuadrangulationResult {
  bool success = false;
  PatchClass patchClass = PatchClass::Unsupported;
  PatchMesh mesh;
};

class PatchQuadrangulator {
public:
  [[nodiscard]] static PatchQuadrangulationResult
  quadrangulate(const PatchRegion &region) {
    const PatchClassification classification = PatchClassifier::classify(region);
    if (!classification.accepted) {
      return {};
    }

    if (classification.patchClass == PatchClass::FourSidedDisk) {
      return quadrangulate_four_sided(region);
    }
    return quadrangulate_simple_fan(region, classification.patchClass);
  }

  [[nodiscard]] static bool boundary_is_preserved(const PatchRegion &region,
                                                  const PatchMesh &mesh) {
    return region.boundaryVertices == mesh.boundaryVertices;
  }

  [[nodiscard]] static bool output_is_pure_quad(const PatchMesh &mesh) {
    return std::all_of(mesh.quads.begin(), mesh.quads.end(),
                       [](const auto &face) { return face.size() == 4; });
  }

  [[nodiscard]] static bool output_has_no_t_junctions(const PatchMesh &mesh) {
    std::set<int> knownVertices(mesh.vertices.begin(), mesh.vertices.end());
    for (const int vertex : mesh.boundaryVertices) {
      if (knownVertices.count(vertex) == 0) {
        return false;
      }
    }
    for (const auto &quad : mesh.quads) {
      if (quad.size() != 4) {
        return false;
      }
      for (const int vertex : quad) {
        if (knownVertices.count(vertex) == 0) {
          return false;
        }
      }
    }
    if (mesh.vertexPositions.rows() ==
        static_cast<Eigen::Index>(mesh.vertices.size())) {
      return output_has_no_t_junctions(mesh, mesh.vertexPositions);
    }
    return true;
  }

  [[nodiscard]] static bool
  output_has_no_t_junctions(const PatchMesh &mesh,
                            const Eigen::MatrixXd &vertexPositions) {
    if (vertexPositions.rows() !=
            static_cast<Eigen::Index>(mesh.vertices.size()) ||
        vertexPositions.cols() != 3) {
      return false;
    }

    std::map<int, int> vertexToLocal;
    for (std::size_t index = 0; index < mesh.vertices.size(); ++index) {
      vertexToLocal[mesh.vertices[index]] = static_cast<int>(index);
    }

    Eigen::MatrixXi faces(static_cast<Eigen::Index>(mesh.quads.size()), 4);
    for (std::size_t face = 0; face < mesh.quads.size(); ++face) {
      if (mesh.quads[face].size() != 4) {
        return false;
      }
      for (int corner = 0; corner < 4; ++corner) {
        const auto found = vertexToLocal.find(mesh.quads[face][corner]);
        if (found == vertexToLocal.end()) {
          return false;
        }
        faces(static_cast<Eigen::Index>(face), corner) = found->second;
      }
    }

    directional::validation::MeshValidatorOptions options;
    for (std::size_t index = 0; index < mesh.boundaryVertices.size(); ++index) {
      const int first = mesh.boundaryVertices[index];
      const int second =
          mesh.boundaryVertices[(index + 1) % mesh.boundaryVertices.size()];
      const auto firstLocal = vertexToLocal.find(first);
      const auto secondLocal = vertexToLocal.find(second);
      if (firstLocal == vertexToLocal.end() ||
          secondLocal == vertexToLocal.end()) {
        return false;
      }
      options.authoritativeBoundaryEdges.insert(
          directional::validation::canonical_edge(firstLocal->second,
                                                  secondLocal->second));
    }

    const directional::validation::MeshValidationResult validation =
        directional::validation::MeshValidator::validate_surface_mesh(
            vertexPositions, faces, options);
    return validation.accepted;
  }

private:
  [[nodiscard]] static PatchQuadrangulationResult
  quadrangulate_four_sided(const PatchRegion &region) {
    const int width = region.sideEdgeCounts[0];
    const int height = region.sideEdgeCounts[1];
    const int rows = height + 1;
    const int columns = width + 1;
    std::vector<std::vector<int>> grid(static_cast<std::size_t>(rows),
                                       std::vector<int>(
                                           static_cast<std::size_t>(columns),
                                           -1));

    int nextGeneratedVertex = -1;
    auto nextInterior = [&]() { return nextGeneratedVertex--; };
    auto boundaryAt = [&](const int index) {
      const int count = static_cast<int>(region.boundaryVertices.size());
      return region.boundaryVertices[static_cast<std::size_t>(
          (index % count + count) % count)];
    };

    int boundaryIndex = 0;
    for (int x = 0; x <= width; ++x) {
      grid[0][static_cast<std::size_t>(x)] = boundaryAt(boundaryIndex++);
    }
    for (int y = 1; y <= height; ++y) {
      grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(width)] =
          boundaryAt(boundaryIndex++);
    }
    for (int x = width - 1; x >= 0; --x) {
      grid[static_cast<std::size_t>(height)][static_cast<std::size_t>(x)] =
          boundaryAt(boundaryIndex++);
    }
    for (int y = height - 1; y >= 1; --y) {
      grid[static_cast<std::size_t>(y)][0] = boundaryAt(boundaryIndex++);
    }

    PatchMesh mesh;
    mesh.boundaryVertices = region.boundaryVertices;
    mesh.vertices = region.boundaryVertices;
    for (int y = 1; y < height; ++y) {
      for (int x = 1; x < width; ++x) {
        const int interior = nextInterior();
        grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(x)] =
            interior;
        mesh.vertices.push_back(interior);
      }
    }

    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        mesh.quads.push_back({
            grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(x)],
            grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(x + 1)],
            grid[static_cast<std::size_t>(y + 1)]
                [static_cast<std::size_t>(x + 1)],
            grid[static_cast<std::size_t>(y + 1)][static_cast<std::size_t>(x)],
        });
      }
    }
    return {true, PatchClass::FourSidedDisk, mesh};
  }

  [[nodiscard]] static PatchQuadrangulationResult
  quadrangulate_simple_fan(const PatchRegion &region,
                           const PatchClass patchClass) {
    const int boundaryCount = static_cast<int>(region.boundaryVertices.size());
    if (boundaryCount < 6 || boundaryCount % 2 != 0) {
      return {};
    }

    PatchMesh mesh;
    mesh.boundaryVertices = region.boundaryVertices;
    mesh.vertices = region.boundaryVertices;
    const int centerVertex = -1;
    mesh.vertices.push_back(centerVertex);

    for (int index = 0; index < boundaryCount; index += 2) {
      mesh.quads.push_back({
          region.boundaryVertices[static_cast<std::size_t>(index)],
          region.boundaryVertices[static_cast<std::size_t>(index + 1)],
          region.boundaryVertices[static_cast<std::size_t>((index + 2) %
                                                           boundaryCount)],
          centerVertex,
      });
    }
    return {true, patchClass, mesh};
  }
};

} // namespace detail
} // namespace directional

#endif // DIRECTIONAL_MESHING_PATCH_QUADRANGULATOR_H
