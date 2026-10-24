// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/CutGraphDisplay.h>

#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

namespace directional::visualization {
namespace {

Eigen::RowVector3d vertex_position(const Eigen::MatrixXd &V,
                                   const authority::SourceVertexId vertex) {
  const std::size_t row = vertex.index();
  if (row >= static_cast<std::size_t>(V.rows())) {
    throw std::invalid_argument("Cut-graph vertex " + std::to_string(row) +
                                " is outside the source vertices.");
  }
  return V.row(static_cast<Eigen::Index>(row));
}

// Edge parameters run from the edge's first to its second vertex; face
// barycentrics follow the face key's sorted vertex order.
Eigen::RowVector3d point_position(const Eigen::MatrixXd &V,
                                  const authority::ExactSourcePoint &point) {
  if (const auto *vertex = std::get_if<authority::SourceVertexId>(&point)) {
    return vertex_position(V, *vertex);
  }
  if (const auto *edge = std::get_if<authority::ExactSourceEdgePoint>(&point)) {
    const double t = static_cast<double>(edge->parameter.to_double());
    return (1.0 - t) * vertex_position(V, edge->edge.first()) +
           t * vertex_position(V, edge->edge.second());
  }
  const auto &face = std::get<authority::ExactSourceFacePoint>(point);
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  for (std::size_t corner = 0; corner < 3; ++corner) {
    position += static_cast<double>(face.barycentric[corner].to_double()) *
                vertex_position(V, face.face.vertices()[corner]);
  }
  return position;
}

} // namespace

CutGraphDisplay cut_graph_display(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
                                  const geometry::SurfaceCutGraph *cutGraph,
                                  const geometry::GlobalTopologyPlan *plan) {
  if (V.cols() != 3 || F.cols() != 3) {
    throw std::invalid_argument("Display needs n x 3 vertices and m x 3 faces.");
  }
  CutGraphDisplay display;
  display.faceRegion = Eigen::VectorXi::Constant(F.rows(), kNoDiscRegion);

  if (cutGraph != nullptr) {
    display.hasCutGraph = true;
    const auto &edges = cutGraph->cut_edges();
    display.cutPoints.resize(2 * static_cast<Eigen::Index>(edges.size()), 3);
    display.cutEdges.resize(static_cast<Eigen::Index>(edges.size()), 2);
    for (std::size_t row = 0; row < edges.size(); ++row) {
      const auto index = static_cast<Eigen::Index>(row);
      display.cutPoints.row(2 * index) = vertex_position(V, edges[row].first());
      display.cutPoints.row(2 * index + 1) = vertex_position(V, edges[row].second());
      display.cutEdges(index, 0) = static_cast<int>(2 * index);
      display.cutEdges(index, 1) = static_cast<int>(2 * index + 1);
    }
  }

  if (plan == nullptr) return display;
  display.hasTopologyPlan = true;

  std::map<std::array<std::size_t, 3>, Eigen::Index> faceRow;
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    std::array<std::size_t, 3> key{static_cast<std::size_t>(F(face, 0)),
                                   static_cast<std::size_t>(F(face, 1)),
                                   static_cast<std::size_t>(F(face, 2))};
    std::sort(key.begin(), key.end());
    faceRow.emplace(key, face);
  }
  // A region lists each (face, graph-face orbit) fragment, so a face crossed
  // by traces can belong to several regions.
  std::vector<std::set<int>> regionsOfFace(static_cast<std::size_t>(F.rows()));
  for (std::size_t region = 0; region < plan->regions().size(); ++region) {
    for (const auto &key : plan->regions()[region].sourceFaces) {
      std::array<std::size_t, 3> corners{key.vertices()[0].index(),
                                         key.vertices()[1].index(),
                                         key.vertices()[2].index()};
      const auto found = faceRow.find(corners);
      if (found == faceRow.end()) {
        throw std::invalid_argument("A topology-plan region names a face that "
                                    "is not in the mesh.");
      }
      regionsOfFace[static_cast<std::size_t>(found->second)].insert(
          static_cast<int>(region));
    }
  }
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    const auto &owners = regionsOfFace[static_cast<std::size_t>(face)];
    if (owners.size() == 1U) {
      display.faceRegion(face) = *owners.begin();
    } else if (owners.size() > 1U) {
      display.faceRegion(face) = kSplitDiscRegion;
      ++display.splitFaceCount;
    }
  }
  display.regionCount = plan->regions().size();
  for (const auto &certificate : plan->region_certificates()) {
    if (certificate.proves_disc_topology()) ++display.discRegionCount;
    if (certificate.proves_field_regularity()) ++display.regularRegionCount;
  }

  std::vector<std::array<Eigen::RowVector3d, 2>> segments;
  std::vector<int> kinds;
  std::vector<int> owners;
  const auto &arcs = plan->arcs();
  for (std::size_t arc = 0; arc < arcs.size(); ++arc) {
    for (const auto &piece : arcs[arc].sourcePath) {
      const Eigen::RowVector3d first = point_position(V, piece.first);
      const Eigen::RowVector3d second = point_position(V, piece.second);
      if (first == second) continue;
      segments.push_back({first, second});
      kinds.push_back(static_cast<int>(arcs[arc].kind));
      owners.push_back(static_cast<int>(arc));
    }
  }
  display.arcCount = arcs.size();
  const auto count = static_cast<Eigen::Index>(segments.size());
  display.arcPoints.resize(2 * count, 3);
  display.arcEdges.resize(count, 2);
  display.arcKind.resize(count);
  display.arcIndex.resize(count);
  for (Eigen::Index row = 0; row < count; ++row) {
    const auto index = static_cast<std::size_t>(row);
    display.arcPoints.row(2 * row) = segments[index][0];
    display.arcPoints.row(2 * row + 1) = segments[index][1];
    display.arcEdges(row, 0) = static_cast<int>(2 * row);
    display.arcEdges(row, 1) = static_cast<int>(2 * row + 1);
    display.arcKind(row) = kinds[index];
    display.arcIndex(row) = owners[index];
  }
  return display;
}

} // namespace directional::visualization
