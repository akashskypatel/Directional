// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/SurfaceCellTracingDisplay.h>

#include <algorithm>
#include <array>
#include <map>
#include <optional>
#include <set>
#include <stdexcept>
#include <utility>

namespace directional::visualization {
namespace {

std::string triple_text(const std::array<std::size_t, 3> &corners) {
  return std::to_string(corners[0]) + "," + std::to_string(corners[1]) + "," +
         std::to_string(corners[2]);
}

class StopCollector {
public:
  StopCollector(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F) : V_(V), F_(F) {
    for (Eigen::Index face = 0; face < F.rows(); ++face) {
      std::array<std::size_t, 3> key{static_cast<std::size_t>(F(face, 0)),
                                     static_cast<std::size_t>(F(face, 1)),
                                     static_cast<std::size_t>(F(face, 2))};
      std::sort(key.begin(), key.end());
      faceByCorners_.emplace(key, face);
      for (int corner = 0; corner < 3; ++corner) {
        const int a = F(face, corner);
        const int b = F(face, (corner + 1) % 3);
        ++edgeFaceCount_[{std::min(a, b), std::max(a, b)}];
      }
    }
    // The tracer numbers interior edges by their rank in vertex-pair order.
    for (const auto &[edge, count] : edgeFaceCount_) {
      if (count == 2) interiorEdges_.push_back(edge);
    }
  }

  void face_row(const int row, const int role, const char *what) {
    if (row < 0) return;
    if (row >= F_.rows()) {
      notes_.push_back(std::string(what) + " row " + std::to_string(row) +
                       " is not in the mesh");
      return;
    }
    faces_.emplace_back(row, role);
  }

  void face_corners(const std::optional<std::array<std::size_t, 3>> &corners,
                    const int role, const char *what) {
    if (!corners.has_value()) return;
    auto key = *corners;
    std::sort(key.begin(), key.end());
    const auto found = faceByCorners_.find(key);
    if (found == faceByCorners_.end()) {
      notes_.push_back(std::string(what) + " (" + triple_text(*corners) +
                       ") is not a mesh face");
      return;
    }
    faces_.emplace_back(found->second, role);
  }

  void edge(const std::optional<std::array<std::size_t, 2>> &ends, const char *what) {
    if (!ends.has_value()) return;
    const auto a = static_cast<Eigen::Index>((*ends)[0]);
    const auto b = static_cast<Eigen::Index>((*ends)[1]);
    if (a >= V_.rows() || b >= V_.rows()) {
      notes_.push_back(std::string(what) + " has a vertex outside the mesh");
      return;
    }
    edges_.emplace_back(a, b);
  }

  void interior_edge(const int rank, const char *what) {
    if (rank < 0) return;
    if (static_cast<std::size_t>(rank) >= interiorEdges_.size()) {
      notes_.push_back(std::string(what) + " index " + std::to_string(rank) +
                       " is not an interior edge");
      return;
    }
    const auto &[a, b] = interiorEdges_[static_cast<std::size_t>(rank)];
    edges_.emplace_back(a, b);
  }

  void vertex(const long long row, const char *what) {
    if (row < 0) return;
    if (row >= V_.rows()) {
      notes_.push_back(std::string(what) + " " + std::to_string(row) +
                       " is not in the mesh");
      return;
    }
    vertices_.push_back(static_cast<Eigen::Index>(row));
  }

  void note(const char *label, const std::string &value) {
    if (!value.empty()) notes_.push_back(std::string(label) + ": " + value);
  }

  void write(SurfaceCellTracingDisplay &display) const {
    // A face named twice keeps its first (stopping) role.
    std::map<Eigen::Index, int> roles;
    for (const auto &[row, role] : faces_) roles.emplace(row, role);
    display.stopFaceVertices.resize(3 * static_cast<Eigen::Index>(roles.size()), 3);
    display.stopFaces.resize(static_cast<Eigen::Index>(roles.size()), 3);
    display.stopFaceRole.resize(static_cast<Eigen::Index>(roles.size()));
    Eigen::Index next = 0;
    for (const auto &[row, role] : roles) {
      for (int corner = 0; corner < 3; ++corner) {
        display.stopFaceVertices.row(3 * next + corner) = V_.row(F_(row, corner));
        display.stopFaces(next, corner) = static_cast<int>(3 * next + corner);
      }
      display.stopFaceRole(next) = role;
      ++next;
    }

    std::set<std::pair<Eigen::Index, Eigen::Index>> edges;
    for (const auto &[a, b] : edges_) edges.emplace(std::min(a, b), std::max(a, b));
    display.stopEdgePoints.resize(2 * static_cast<Eigen::Index>(edges.size()), 3);
    display.stopEdges.resize(static_cast<Eigen::Index>(edges.size()), 2);
    next = 0;
    for (const auto &[a, b] : edges) {
      display.stopEdgePoints.row(2 * next) = V_.row(a);
      display.stopEdgePoints.row(2 * next + 1) = V_.row(b);
      display.stopEdges(next, 0) = static_cast<int>(2 * next);
      display.stopEdges(next, 1) = static_cast<int>(2 * next + 1);
      ++next;
    }

    const std::set<Eigen::Index> vertices(vertices_.begin(), vertices_.end());
    display.stopVertices.resize(static_cast<Eigen::Index>(vertices.size()), 3);
    next = 0;
    for (const Eigen::Index row : vertices) display.stopVertices.row(next++) = V_.row(row);
    display.stopNotes = notes_;
  }

private:
  const Eigen::MatrixXd &V_;
  const Eigen::MatrixXi &F_;
  std::map<std::array<std::size_t, 3>, Eigen::Index> faceByCorners_;
  std::map<std::pair<int, int>, int> edgeFaceCount_;
  std::vector<std::pair<int, int>> interiorEdges_;
  std::vector<std::pair<Eigen::Index, int>> faces_;
  std::vector<std::pair<Eigen::Index, Eigen::Index>> edges_;
  std::vector<Eigen::Index> vertices_;
  std::vector<std::string> notes_;
};

Eigen::RowVector3d trace_point(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
                               const int face, const Eigen::RowVector3d &barycentric) {
  if (face < 0 || face >= F.rows()) {
    throw std::invalid_argument("A traced cell references a face outside the mesh.");
  }
  Eigen::RowVector3d point = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 3; ++corner) {
    point += barycentric(corner) * V.row(F(face, corner));
  }
  return point;
}

} // namespace

SurfaceCellTracingDisplay surface_cell_tracing_display(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const directional::RemeshDiagnostics &diagnostics,
    const geometry::SurfaceCellNetwork *traceNetwork) {
  if (V.cols() != 3 || F.cols() != 3) {
    throw std::invalid_argument("Display needs n x 3 vertices and m x 3 faces.");
  }
  SurfaceCellTracingDisplay display;
  const bool requestedStop = diagnostics.terminalFailureCode == "InjectedStageFailure";
  StopCollector stop(V, F);
  if (diagnostics.terminalFailureCode != "None" && !requestedStop) {
    const auto &locus = diagnostics.terminalFailureLocus;
    stop.note("stage", diagnostics.terminalFailureStage);
    stop.note("code", diagnostics.terminalFailureCode);
    stop.note("network condition", locus.networkErrorCondition);
    stop.note("rotation system", locus.rotationSystemInconsistencyReason);
    stop.note("vertex trace", locus.vertexTraceSecondaryParameterFailureReason);
    stop.note("edge trace", locus.edgeTraceSecondaryRankFailureReason);
    stop.face_corners(locus.sourceFace, 0, "stopping face");
    stop.face_corners(locus.relatedSourceFace, 1, "related face");
    stop.face_corners(locus.edgeTraceFaceCorners, 1, "edge-trace face");
    stop.edge(locus.sourceEdge, "stopping edge");
    stop.edge(locus.traceIncomingCarrier, "incoming carrier");
    stop.edge(locus.traceOutgoingCarrier, "outgoing carrier");
    stop.edge(locus.edgeTraceOtherCarrier, "other carrier");
    if (locus.sourceVertex.has_value()) {
      stop.vertex(static_cast<long long>(*locus.sourceVertex), "stopping vertex");
    }
  }

  if (traceNetwork != nullptr) {
    const auto &phaseFront = traceNetwork->phaseFront;
    if (const auto *failure = phaseFront.rejection(); failure != nullptr) {
      stop.note("quad tracing",
                geometry::surface_phase_front_failure_reason_name(failure->reason));
      stop.note("factory site", failure->publishedProductSourceAuthoritySite);
      stop.note("hard-rail route", failure->hardRailRouteDiagnostic);
      stop.face_row(failure->face, 0, "quad-tracing face");
      stop.face_row(failure->targetFace, 1, "quad-tracing target face");
      stop.vertex(failure->sourceVertex, "quad-tracing vertex");
      stop.interior_edge(failure->sourceEdge, "quad-tracing edge");
      stop.interior_edge(failure->secondarySourceEdge, "quad-tracing second edge");
    }
    if (const auto *product = phaseFront.produced_product(); product != nullptr) {
      std::vector<std::array<Eigen::RowVector3d, 2>> segments;
      std::map<std::array<double, 3>, Eigen::RowVector3d> corners;
      for (const auto &cell : product->cells()) {
        for (const auto &corner : cell.corners) {
          const Eigen::RowVector3d point =
              trace_point(V, F, corner.face, corner.barycentric);
          corners.emplace(std::array<double, 3>{point.x(), point.y(), point.z()}, point);
        }
        for (const auto &path : cell.boundaryPaths) {
          for (const auto &segment : path) {
            segments.push_back({trace_point(V, F, segment.face, segment.startBarycentric),
                                trace_point(V, F, segment.face, segment.endBarycentric)});
          }
        }
      }
      display.cellCount = product->cells().size();
      const auto count = static_cast<Eigen::Index>(segments.size());
      display.cellPoints.resize(2 * count, 3);
      display.cellEdges.resize(count, 2);
      for (Eigen::Index row = 0; row < count; ++row) {
        display.cellPoints.row(2 * row) = segments[static_cast<std::size_t>(row)][0];
        display.cellPoints.row(2 * row + 1) = segments[static_cast<std::size_t>(row)][1];
        display.cellEdges(row, 0) = static_cast<int>(2 * row);
        display.cellEdges(row, 1) = static_cast<int>(2 * row + 1);
      }
      display.cellCorners.resize(static_cast<Eigen::Index>(corners.size()), 3);
      Eigen::Index next = 0;
      for (const auto &[key, point] : corners) display.cellCorners.row(next++) = point;
    }
  }
  stop.write(display);
  return display;
}

} // namespace directional::visualization
