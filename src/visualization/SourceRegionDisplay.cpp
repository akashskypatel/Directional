// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/SourceRegionDisplay.h>

#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace directional::visualization {
namespace {

Eigen::RowVector3d vertex_position(const Eigen::MatrixXd &V,
                                   const authority::SourceVertexId vertex) {
  const std::size_t row = vertex.index();
  if (row >= static_cast<std::size_t>(V.rows())) {
    throw std::invalid_argument("Topology region vertex " +
                                std::to_string(row) +
                                " is outside the source vertices.");
  }
  return V.row(static_cast<Eigen::Index>(row));
}

void write_segments(
    const Eigen::MatrixXd &V,
    const std::vector<authority::SourceEdgeTopologyKey> &edges,
    Eigen::MatrixXd &points, Eigen::MatrixXi &segments) {
  points.resize(2 * static_cast<Eigen::Index>(edges.size()), 3);
  segments.resize(static_cast<Eigen::Index>(edges.size()), 2);
  for (std::size_t row = 0; row < edges.size(); ++row) {
    const auto index = static_cast<Eigen::Index>(row);
    points.row(2 * index) = vertex_position(V, edges[row].first());
    points.row(2 * index + 1) = vertex_position(V, edges[row].second());
    segments(index, 0) = static_cast<int>(2 * index);
    segments(index, 1) = static_cast<int>(2 * index + 1);
  }
}

} // namespace

SourceRegionDisplay source_region_display(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const geometry::SourceTopologyRegions &regions) {
  if (V.cols() != 3) {
    throw std::invalid_argument("Source vertices must be an n x 3 matrix.");
  }
  const auto faceCount = static_cast<std::size_t>(F.rows());
  if (!regions.complete_for_face_count(faceCount)) {
    throw std::invalid_argument(
        "Topology regions do not cover exactly the source faces.");
  }

  SourceRegionDisplay result;
  result.faceRegion.resize(F.rows());
  result.faceSheet.resize(F.rows());
  result.faceComponent.resize(F.rows());
  std::set<std::size_t> sheets;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const auto row = authority::SourceFaceId::from_index(face, faceCount);
    if (!row) {
      throw std::invalid_argument("Source face row is outside the regions.");
    }
    result.faceRegion(face) =
        static_cast<int>(regions.region_for_row(row.value()).index());
    const std::size_t sheet = regions.sheet_for_row(row.value()).index();
    result.faceSheet(face) = static_cast<int>(sheet);
    result.faceComponent(face) =
        static_cast<int>(regions.component_for_row(row.value()).index());
    sheets.insert(sheet);
  }
  result.sheetCount = sheets.size();
  result.regionCount = regions.regions().size();

  // A seam is interior to one region; a boundary between two regions is
  // published by both, so both lists are deduplicated by edge.
  std::map<authority::SourceEdgeTopologyKey, int> seamOwner;
  std::set<authority::SourceEdgeTopologyKey> boundary;
  for (const auto &region : regions.regions()) {
    for (const auto &edge : region.isolation_seams()) {
      seamOwner.emplace(edge, static_cast<int>(region.id().index()));
    }
    boundary.insert(region.boundary_edges().begin(),
                    region.boundary_edges().end());
  }

  std::vector<authority::SourceEdgeTopologyKey> seamEdges;
  result.seamRegion.resize(static_cast<Eigen::Index>(seamOwner.size()));
  for (const auto &[edge, owner] : seamOwner) {
    result.seamRegion(static_cast<Eigen::Index>(seamEdges.size())) = owner;
    seamEdges.push_back(edge);
  }
  write_segments(V, seamEdges, result.seamPoints, result.seamEdges);
  const std::vector<authority::SourceEdgeTopologyKey> boundaryEdges(
      boundary.begin(), boundary.end());
  write_segments(V, boundaryEdges, result.boundaryPoints, result.boundaryEdges);
  return result;
}

} // namespace directional::visualization
