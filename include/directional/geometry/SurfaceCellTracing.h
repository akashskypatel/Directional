// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_CELL_TRACING_H
#define DIRECTIONAL_GEOMETRY_SURFACE_CELL_TRACING_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/fields/CrossField.h>
#include <directional/geometry/ReliefTopology.h>

namespace directional::geometry {

enum class SurfaceSeedProvenance : int {
  Boundary = 0,
  Feature = 1,
  Singularity = 2,
  ReliefCritical = 3,
  Separatrix = 4,
  Anchor = 5,
  AdaptiveFarthest = 6,
};

enum class TraceTerminationReason : int {
  Boundary = 0,
  Feature = 1,
  Captured = 2,
  Singularity = 3,
  RepeatedState = 4,
  Budget = 5,
  Degenerate = 6,
};

enum class CellRejectionReason : int {
  Accepted = 0,
  Closure = 1,
  Barrier = 2,
  Degenerate = 3,
};

enum class SurfaceCellRailKind : int {
  Boundary = 0,
  HardFeature = 1,
};

struct SurfaceTracePoint {
  int face = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
};

struct SurfaceCellRailSample {
  int sourceFace = -1;
  int sourceEdge = -1;
  double parameter = 0.0;
  double railParameter = 0.0;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
};

struct SurfaceCellRail {
  int id = -1;
  SurfaceCellRailKind kind = SurfaceCellRailKind::Boundary;
  int curveId = -1;
  int component = -1;
  bool closed = false;
  std::vector<int> sourceVertices;
  std::vector<int> sourceEdges;
  std::vector<SurfaceCellRailSample> samples;
};

struct SurfaceTraceSeed {
  int id = -1;
  SurfaceTracePoint point;
  SurfaceSeedProvenance provenance = SurfaceSeedProvenance::AdaptiveFarthest;
  int sourceId = -1;
};

struct SurfaceTraceSegment {
  int face = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  int family = 0;
  int sign = 1;
  int entryEdge = -1;
  int exitEdge = -1;
  int matching = 0;
  double matchingEffort = 0.0;
};

struct SurfaceTraceResult {
  std::vector<SurfaceTraceSegment> segments;
  TraceTerminationReason termination = TraceTerminationReason::Budget;
  double length = 0.0;
};

struct SurfaceCellProposal {
  int seedId = -1;
  bool accepted = false;
  CellRejectionReason rejection = CellRejectionReason::Accepted;
  double closureError = 0.0;
  std::array<SurfaceTracePoint, 4> corners;
  std::vector<SurfaceTraceSegment> sides;
  std::array<std::vector<SurfaceTraceSegment>, 4> boundaryPaths;
};

struct SurfaceWalkResult {
  SurfaceTracePoint point;
  SurfaceTraceResult trace;
};

struct SurfaceCellProposalStats {
  int attempted = 0;
  int accepted = 0;
  int rejectedClosure = 0;
  int rejectedBarrier = 0;
  int rejectedDegenerate = 0;
};

enum class SurfaceGuidePotentialStatus : int {
  SkippedUnresolved = 0,
  Available = 1,
};

struct SurfaceGuidePotential {
  SurfaceGuidePotentialStatus status =
      SurfaceGuidePotentialStatus::SkippedUnresolved;
};

struct SurfaceCellTracingOptions {
  double defaultTargetSize = 1.0;
  double coverageRadiusFactor = 1.0;
  double maxTraceLength = 1.0;
  int maxTraceSegments = 128;
  double captureRadius = 0.0;
  double closureToleranceFactor = 0.25;
  std::vector<int> singularityVertices;
  std::vector<int> reliefCriticalVertices;
  std::vector<int> separatrixVertices;
  std::vector<int> anchors;
  std::vector<SurfaceTracePoint> capturePoints;
  std::set<std::uint64_t> hardFeatureEdges;
  std::vector<SurfaceCellRail> authoritativeRails;
  bool followCompatibleHardFeatureRails = true;
  SurfaceGuidePotential guidePotential;
};

struct SurfaceCellNetwork {
  std::vector<SurfaceTraceSeed> seeds;
  std::vector<SurfaceTraceResult> traces;
  std::vector<SurfaceCellProposal> proposals;
  std::vector<SurfaceCellRail> authoritativeRails;
  SurfaceCellProposalStats stats;
};

struct SurfaceCellTracingOverlay {
  Eigen::MatrixXd crossGlyphStarts;
  Eigen::MatrixXd crossGlyphEnds;
  Eigen::VectorXi crossGlyphFamily;
  Eigen::MatrixXd seedPositions;
  Eigen::VectorXi seedProvenance;
  Eigen::MatrixXd traceSegmentStarts;
  Eigen::MatrixXd traceSegmentEnds;
  Eigen::VectorXi traceFamily;
  Eigen::VectorXi traceSign;
  Eigen::VectorXi traceTermination;
  Eigen::VectorXd cellClosureError;
  Eigen::VectorXi cellRejection;
};

namespace surface_cell_tracing_detail {

inline std::uint64_t edge_key(const int a, const int b) {
  return relief_topology_detail::edge_key(a, b);
}

inline Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex) {
  return {vertices(vertex, 0), vertices(vertex, 1), vertices(vertex, 2)};
}

inline Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}

inline Eigen::RowVector3d point_position(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &faces,
                                         const SurfaceTracePoint &point) {
  Eigen::RowVector3d p = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 3; ++corner) {
    p += point.barycentric[corner] * row3(vertices, faces(point.face, corner));
  }
  return p;
}

inline Eigen::RowVector3d face_normal(const Eigen::MatrixXd &vertices,
                                      const Eigen::MatrixXi &faces,
                                      const int face) {
  const Eigen::RowVector3d a = row3(vertices, faces(face, 0));
  const Eigen::RowVector3d b = row3(vertices, faces(face, 1));
  const Eigen::RowVector3d c = row3(vertices, faces(face, 2));
  Eigen::RowVector3d normal = cross3(b - a, c - a);
  const double norm = normal.norm();
  if (norm > 0.0) {
    normal /= norm;
  }
  return normal;
}

inline Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &direction,
                                          const Eigen::RowVector3d &normal) {
  Eigen::RowVector3d tangent = direction - direction.dot(normal) * normal;
  const double norm = tangent.norm();
  if (norm > 0.0) {
    tangent /= norm;
  }
  return tangent;
}

inline std::map<std::uint64_t, std::array<int, 2>>
edge_faces(const Eigen::MatrixXi &faces) {
  std::map<std::uint64_t, std::array<int, 2>> result;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const std::uint64_t key =
          edge_key(faces(face, corner), faces(face, (corner + 1) % 3));
      auto found = result.find(key);
      if (found == result.end()) {
        result.emplace(key, std::array<int, 2>{face, -1});
      } else if (found->second[1] < 0) {
        found->second[1] = face;
      }
    }
  }
  return result;
}

inline std::map<std::uint64_t, int>
edge_matching_indices(const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces) {
  std::map<std::uint64_t, int> indices;
  int index = 0;
  for (const auto &[key, pair] : edgeFaces) {
    if (pair[0] >= 0 && pair[1] >= 0) {
      indices.emplace(key, index++);
    }
  }
  return indices;
}

inline bool contains_vertex(const std::vector<int> &vertices,
                            const int vertex) {
  return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
}

inline std::vector<std::vector<int>>
incident_faces_by_vertex(const int vertexCount, const Eigen::MatrixXi &faces) {
  std::vector<std::vector<int>> incident(static_cast<std::size_t>(vertexCount));
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      if (vertex >= 0 && vertex < vertexCount) {
        incident[static_cast<std::size_t>(vertex)].push_back(face);
      }
    }
  }
  for (auto &facesForVertex : incident) {
    std::sort(facesForVertex.begin(), facesForVertex.end());
    facesForVertex.erase(std::unique(facesForVertex.begin(),
                                     facesForVertex.end()),
                         facesForVertex.end());
  }
  return incident;
}

inline SurfaceTracePoint vertex_point(
    const int vertex, const std::vector<std::vector<int>> &incident,
    const Eigen::MatrixXi &faces) {
  SurfaceTracePoint point;
  if (vertex < 0 || vertex >= static_cast<int>(incident.size()) ||
      incident[static_cast<std::size_t>(vertex)].empty()) {
    return point;
  }
  point.face = incident[static_cast<std::size_t>(vertex)].front();
  for (int corner = 0; corner < 3; ++corner) {
    point.barycentric[corner] = faces(point.face, corner) == vertex ? 1.0 : 0.0;
  }
  return point;
}

inline double target_size_at_vertex(const Eigen::VectorXd &targetSize,
                                    const int vertex,
                                    const double fallback) {
  if (vertex >= 0 && vertex < targetSize.size() &&
      std::isfinite(targetSize[vertex]) && targetSize[vertex] > 0.0) {
    return targetSize[vertex];
  }
  return fallback;
}

inline void append_seed(std::vector<SurfaceTraceSeed> &seeds,
                        std::set<std::tuple<int, int, int, int>> &seen,
                        const SurfaceTracePoint &point,
                        const SurfaceSeedProvenance provenance,
                        const int sourceId) {
  if (point.face < 0) {
    return;
  }
  const auto key = std::make_tuple(
      point.face, static_cast<int>(std::llround(point.barycentric[0] * 1.0e9)),
      static_cast<int>(std::llround(point.barycentric[1] * 1.0e9)),
      static_cast<int>(std::llround(point.barycentric[2] * 1.0e9)));
  if (!seen.insert(key).second) {
    return;
  }
  SurfaceTraceSeed seed;
  seed.id = static_cast<int>(seeds.size());
  seed.point = point;
  seed.provenance = provenance;
  seed.sourceId = sourceId;
  seeds.push_back(seed);
}

inline bool point_on_edge(const Eigen::RowVector3d &bary, const int edgeCorner,
                          const double eps = 1.0e-10) {
  return std::abs(bary[edgeCorner]) <= eps;
}

inline int hit_vertex(const Eigen::RowVector3d &bary,
                      const double eps = 1.0e-10) {
  int one = -1;
  for (int corner = 0; corner < 3; ++corner) {
    if (bary[corner] >= 1.0 - eps) {
      one = corner;
    }
  }
  return one;
}

inline int dominant_vertex_corner(const Eigen::RowVector3d &bary) {
  int best = 0;
  for (int corner = 1; corner < 3; ++corner) {
    if (bary[corner] > bary[best]) {
      best = corner;
    }
  }
  return best;
}

inline Eigen::RowVector3d remap_barycentric_to_neighbor(
    const Eigen::MatrixXi &faces, const int fromFace, const int toFace,
    const Eigen::RowVector3d &fromBary) {
  Eigen::RowVector3d to = Eigen::RowVector3d::Zero();
  for (int fromCorner = 0; fromCorner < 3; ++fromCorner) {
    const int vertex = faces(fromFace, fromCorner);
    for (int toCorner = 0; toCorner < 3; ++toCorner) {
      if (faces(toFace, toCorner) == vertex) {
        to[toCorner] = fromBary[fromCorner];
      }
    }
  }
  return to;
}

inline bool barycentric_derivative(const Eigen::MatrixXd &vertices,
                                   const Eigen::MatrixXi &faces,
                                   const int face,
                                   const Eigen::RowVector3d &direction,
                                   Eigen::RowVector3d &dbary) {
  const Eigen::RowVector3d a = row3(vertices, faces(face, 0));
  const Eigen::RowVector3d b = row3(vertices, faces(face, 1));
  const Eigen::RowVector3d c = row3(vertices, faces(face, 2));
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = (b - a).transpose();
  basis.col(1) = (c - a).transpose();
  const Eigen::Vector2d uv =
      (basis.transpose() * basis).ldlt().solve(basis.transpose() *
                                               direction.transpose());
  if (!uv.allFinite()) {
    return false;
  }
  dbary << -uv[0] - uv[1], uv[0], uv[1];
  return dbary.allFinite() && dbary.squaredNorm() > 0.0;
}

inline int choose_symbolic_outgoing_face(
    const int currentFace, const int vertex,
    const std::vector<std::vector<int>> &incident) {
  if (vertex < 0 || vertex >= static_cast<int>(incident.size())) {
    return -1;
  }
  const auto &candidates = incident[static_cast<std::size_t>(vertex)];
  for (const int face : candidates) {
    if (face > currentFace) {
      return face;
    }
  }
  for (const int face : candidates) {
    if (face != currentFace) {
      return face;
    }
  }
  return -1;
}

inline int quantized_barycentric(const double value) {
  return static_cast<int>(std::llround(value * 1.0e9));
}

inline int branch_from_family_sign(const int family, const int sign) {
  return (family == 0 ? 0 : 1) + (sign >= 0 ? 0 : 2);
}

inline void family_sign_from_branch(const int branch, int &family, int &sign) {
  const int normalized = ((branch % 4) + 4) % 4;
  family = normalized % 2;
  sign = normalized < 2 ? 1 : -1;
}

inline Eigen::RowVector3d axis_for_family(const Eigen::MatrixXd &faceAxisX,
                                          const Eigen::MatrixXd &faceAxisY,
                                          const int face, const int family,
                                          const int sign) {
  Eigen::RowVector3d axis =
      family == 0 ? faceAxisX.row(face) : faceAxisY.row(face);
  return (sign >= 0 ? 1.0 : -1.0) * axis;
}

inline Eigen::Vector2d project_for_quad_test(const Eigen::RowVector3d &point,
                                             const int dropAxis) {
  if (dropAxis == 0) {
    return {point.y(), point.z()};
  }
  if (dropAxis == 1) {
    return {point.x(), point.z()};
  }
  return {point.x(), point.y()};
}

inline double orient2d(const Eigen::Vector2d &a, const Eigen::Vector2d &b,
                       const Eigen::Vector2d &c) {
  return (b.x() - a.x()) * (c.y() - a.y()) -
         (b.y() - a.y()) * (c.x() - a.x());
}

inline bool segments_intersect_2d(const Eigen::Vector2d &a,
                                  const Eigen::Vector2d &b,
                                  const Eigen::Vector2d &c,
                                  const Eigen::Vector2d &d) {
  const double o1 = orient2d(a, b, c);
  const double o2 = orient2d(a, b, d);
  const double o3 = orient2d(c, d, a);
  const double o4 = orient2d(c, d, b);
  return o1 * o2 < -1.0e-14 && o3 * o4 < -1.0e-14;
}

inline bool quad_loop_is_valid(const std::array<Eigen::RowVector3d, 4> &corners,
                               const double h) {
  Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
  for (int i = 0; i < 4; ++i) {
    normal += cross3(corners[static_cast<std::size_t>(i)],
                     corners[static_cast<std::size_t>((i + 1) % 4)]);
  }
  int dropAxis = 2;
  if (std::abs(normal.x()) >= std::abs(normal.y()) &&
      std::abs(normal.x()) >= std::abs(normal.z())) {
    dropAxis = 0;
  } else if (std::abs(normal.y()) >= std::abs(normal.z())) {
    dropAxis = 1;
  }
  std::array<Eigen::Vector2d, 4> p;
  for (int i = 0; i < 4; ++i) {
    p[static_cast<std::size_t>(i)] =
        project_for_quad_test(corners[static_cast<std::size_t>(i)], dropAxis);
  }
  double area = 0.0;
  for (int i = 0; i < 4; ++i) {
    const Eigen::Vector2d &a = p[static_cast<std::size_t>(i)];
    const Eigen::Vector2d &b = p[static_cast<std::size_t>((i + 1) % 4)];
    area += a.x() * b.y() - a.y() * b.x();
    const double sideLength =
        (corners[static_cast<std::size_t>((i + 1) % 4)] -
         corners[static_cast<std::size_t>(i)])
            .norm();
    if (!std::isfinite(sideLength) || sideLength < 0.1 * h ||
        sideLength > 4.0 * h) {
      return false;
    }
  }
  if (area <= 1.0e-12 * std::max(1.0, h * h)) {
    return false;
  }
  if (segments_intersect_2d(p[0], p[1], p[2], p[3]) ||
      segments_intersect_2d(p[1], p[2], p[3], p[0])) {
    return false;
  }
  return true;
}

inline SurfaceTracePoint vertex_point_in_face(const Eigen::MatrixXi &faces,
                                              const int face,
                                              const int vertex) {
  SurfaceTracePoint point;
  point.face = face;
  for (int corner = 0; corner < 3; ++corner) {
    point.barycentric[corner] = faces(face, corner) == vertex ? 1.0 : 0.0;
  }
  return point;
}

struct AdaptiveSeedCandidate {
  double normalizedDistance = 0.0;
  int vertex = -1;

  bool operator<(const AdaptiveSeedCandidate &other) const {
    if (std::abs(normalizedDistance - other.normalizedDistance) > 1.0e-14) {
      return normalizedDistance < other.normalizedDistance;
    }
    return vertex > other.vertex;
  }
};

inline Eigen::VectorXd graph_distances_from_vertices(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &sourceVertices,
    const std::set<std::uint64_t> &barrierEdges = {}) {
  using QueueItem = std::pair<double, int>;
  struct Greater {
    bool operator()(const QueueItem &a, const QueueItem &b) const {
      if (a.first != b.first) {
        return a.first > b.first;
      }
      return a.second > b.second;
    }
  };
  const int vertexCount = static_cast<int>(vertices.rows());
  const auto graph =
      relief_topology_detail::vertex_neighbors_from_faces(vertexCount, faces);
  Eigen::VectorXd distance =
      Eigen::VectorXd::Constant(vertexCount, std::numeric_limits<double>::infinity());
  std::priority_queue<QueueItem, std::vector<QueueItem>, Greater> queue;
  for (const int source : sourceVertices) {
    if (source < 0 || source >= vertexCount || distance[source] == 0.0) {
      continue;
    }
    distance[source] = 0.0;
    queue.push({0.0, source});
  }
  while (!queue.empty()) {
    const auto [currentDistance, vertex] = queue.top();
    queue.pop();
    if (currentDistance != distance[vertex]) {
      continue;
    }
    for (const int neighbor : graph[static_cast<std::size_t>(vertex)]) {
      if (barrierEdges.count(edge_key(vertex, neighbor)) != 0) {
        continue;
      }
      const double edgeLength = (row3(vertices, vertex) - row3(vertices, neighbor)).norm();
      const double candidate = currentDistance + edgeLength;
      if (candidate + 1.0e-14 < distance[neighbor]) {
        distance[neighbor] = candidate;
        queue.push({candidate, neighbor});
      }
    }
  }
  return distance;
}

} // namespace surface_cell_tracing_detail

inline std::vector<SurfaceTraceSeed> generate_deterministic_surface_seeds(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {}) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("surface seeds require a 3D triangle mesh.");
  }
  const int vertexCount = static_cast<int>(vertices.rows());
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  const auto incident =
      surface_cell_tracing_detail::incident_faces_by_vertex(vertexCount, faces);
  std::vector<SurfaceTraceSeed> seeds;
  std::set<std::tuple<int, int, int, int>> seen;

  if (!options.authoritativeRails.empty()) {
    for (const SurfaceCellRail &rail : options.authoritativeRails) {
      const SurfaceSeedProvenance provenance =
          rail.kind == SurfaceCellRailKind::Boundary
              ? SurfaceSeedProvenance::Boundary
              : SurfaceSeedProvenance::Feature;
      for (const SurfaceCellRailSample &sample : rail.samples) {
        if (sample.sourceFace < 0 || sample.sourceFace >= faces.rows()) {
          continue;
        }
        SurfaceTracePoint point;
        point.face = sample.sourceFace;
        point.barycentric = sample.barycentric;
        surface_cell_tracing_detail::append_seed(seeds, seen, point, provenance,
                                                 rail.id);
      }
    }
  } else {
    for (const auto &[key, pair] : edgeFaces) {
      if (pair[1] >= 0 && options.hardFeatureEdges.count(key) == 0) {
        continue;
      }
      const int a = static_cast<int>(key >> 32u);
      const int b = static_cast<int>(key & 0xffffffffu);
      const double h = 0.5 * (surface_cell_tracing_detail::target_size_at_vertex(
                                  targetSize, a, options.defaultTargetSize) +
                              surface_cell_tracing_detail::target_size_at_vertex(
                                  targetSize, b, options.defaultTargetSize));
      const double length =
          (surface_cell_tracing_detail::row3(vertices, a) -
           surface_cell_tracing_detail::row3(vertices, b))
              .norm();
      const int samples = std::max(1, static_cast<int>(std::ceil(length / h)));
      for (int sample = 0; sample <= samples; ++sample) {
        const double t = static_cast<double>(sample) / samples;
        SurfaceTracePoint point;
        point.face = pair[0];
        for (int corner = 0; corner < 3; ++corner) {
          if (faces(point.face, corner) == a) {
            point.barycentric[corner] = 1.0 - t;
          } else if (faces(point.face, corner) == b) {
            point.barycentric[corner] = t;
          }
        }
        surface_cell_tracing_detail::append_seed(
            seeds, seen, point,
            pair[1] < 0 ? SurfaceSeedProvenance::Boundary
                        : SurfaceSeedProvenance::Feature,
            static_cast<int>(key & 0x7fffffff));
      }
    }
  }

  const auto add_vertices = [&](const std::vector<int> &verticesToAdd,
                                const SurfaceSeedProvenance provenance) {
    std::vector<int> sorted = verticesToAdd;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    for (const int vertex : sorted) {
      surface_cell_tracing_detail::append_seed(
          seeds, seen,
          surface_cell_tracing_detail::vertex_point(vertex, incident, faces),
          provenance, vertex);
    }
  };
  add_vertices(options.singularityVertices, SurfaceSeedProvenance::Singularity);
  add_vertices(options.reliefCriticalVertices,
               SurfaceSeedProvenance::ReliefCritical);
  add_vertices(options.separatrixVertices, SurfaceSeedProvenance::Separatrix);
  add_vertices(options.anchors, SurfaceSeedProvenance::Anchor);

  Eigen::VectorXd nearest =
      Eigen::VectorXd::Constant(vertexCount, std::numeric_limits<double>::infinity());
  const auto update_nearest = [&]() {
    std::vector<int> sourceVertices;
    for (const SurfaceTraceSeed &seed : seeds) {
      if (seed.sourceId >= 0 && seed.sourceId < vertexCount) {
        sourceVertices.push_back(seed.sourceId);
      }
      for (int corner = 0; corner < 3; ++corner) {
        if (seed.point.face >= 0 && seed.point.barycentric[corner] > 1.0 - 1.0e-10) {
          sourceVertices.push_back(faces(seed.point.face, corner));
        }
      }
    }
    std::sort(sourceVertices.begin(), sourceVertices.end());
    sourceVertices.erase(std::unique(sourceVertices.begin(), sourceVertices.end()),
                         sourceVertices.end());
    nearest = surface_cell_tracing_detail::graph_distances_from_vertices(
        vertices, faces, sourceVertices, options.hardFeatureEdges);
  };

  if (seeds.empty() && vertexCount > 0) {
    surface_cell_tracing_detail::append_seed(
        seeds, seen, surface_cell_tracing_detail::vertex_point(0, incident, faces),
        SurfaceSeedProvenance::AdaptiveFarthest, 0);
  }
  update_nearest();
  while (true) {
    std::priority_queue<surface_cell_tracing_detail::AdaptiveSeedCandidate>
        uncovered;
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      const double h =
          options.coverageRadiusFactor *
          surface_cell_tracing_detail::target_size_at_vertex(
              targetSize, vertex, options.defaultTargetSize);
      const double normalized = h > 0.0 ? nearest[vertex] / h : 0.0;
      uncovered.push({normalized, vertex});
    }
    if (uncovered.empty() || uncovered.top().normalizedDistance <= 1.0) {
      break;
    }
    const int worstVertex = uncovered.top().vertex;
    surface_cell_tracing_detail::append_seed(
        seeds, seen,
        surface_cell_tracing_detail::vertex_point(worstVertex, incident, faces),
        SurfaceSeedProvenance::AdaptiveFarthest, worstVertex);
    update_nearest();
  }

  for (int index = 0; index < static_cast<int>(seeds.size()); ++index) {
    seeds[static_cast<std::size_t>(index)].id = index;
  }
  return seeds;
}

inline SurfaceTraceResult trace_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTraceSeed &seed, const int family, const int sign,
    const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr) {
  if (faceAxisX.rows() != faces.rows() || faceAxisX.cols() != 3 ||
      faceAxisY.rows() != faces.rows() || faceAxisY.cols() != 3) {
    throw std::invalid_argument("face axes must have shape (#F, 3).");
  }
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  const auto edgeMatchingIndices =
      surface_cell_tracing_detail::edge_matching_indices(edgeFaces);
  const auto incident = surface_cell_tracing_detail::incident_faces_by_vertex(
      static_cast<int>(vertices.rows()), faces);
  SurfaceTraceResult result;
  SurfaceTracePoint current = seed.point;
  int currentFamily = family == 0 ? 0 : 1;
  int currentSign = sign >= 0 ? 1 : -1;
  int entryEdge = -1;
  Eigen::RowVector3d direction = surface_cell_tracing_detail::axis_for_family(
      faceAxisX, faceAxisY, current.face, currentFamily, currentSign);
  std::set<std::tuple<int, int, int, int, int, int, int>> states;

  for (int step = 0; step < options.maxTraceSegments &&
                     result.length < options.maxTraceLength;
       ++step) {
    const auto stateKey = std::make_tuple(
        current.face, entryEdge, currentFamily, currentSign,
        surface_cell_tracing_detail::quantized_barycentric(
            current.barycentric[0]),
        surface_cell_tracing_detail::quantized_barycentric(
            current.barycentric[1]),
        surface_cell_tracing_detail::quantized_barycentric(
            current.barycentric[2]));
    if (!states.insert(stateKey).second && step > 0) {
      result.termination = TraceTerminationReason::RepeatedState;
      return result;
    }

    const Eigen::RowVector3d normal =
        surface_cell_tracing_detail::face_normal(vertices, faces, current.face);
    direction = surface_cell_tracing_detail::project_tangent(direction, normal);
    if (direction.squaredNorm() == 0.0) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }

    Eigen::RowVector3d dbary;
    if (!surface_cell_tracing_detail::barycentric_derivative(
            vertices, faces, current.face, direction, dbary)) {
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    double bestT = std::numeric_limits<double>::infinity();
    int hitCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (dbary[corner] < -1.0e-14) {
        const double t = -current.barycentric[corner] / dbary[corner];
        if (t > 1.0e-12 &&
            (t < bestT - 1.0e-14 ||
             (std::abs(t - bestT) <= 1.0e-14 && corner < hitCorner))) {
          bestT = t;
          hitCorner = corner;
        }
      }
    }
    if (hitCorner < 0 || !std::isfinite(bestT)) {
      if (step > 0 &&
          (surface_cell_tracing_detail::point_on_edge(current.barycentric, 0) ||
           surface_cell_tracing_detail::point_on_edge(current.barycentric, 1) ||
           surface_cell_tracing_detail::point_on_edge(current.barycentric, 2))) {
        result.termination = TraceTerminationReason::RepeatedState;
        return result;
      }
      result.termination = TraceTerminationReason::Degenerate;
      return result;
    }
    Eigen::RowVector3d nextBary = current.barycentric + bestT * dbary;
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(nextBary[corner]) < 1.0e-10) {
        nextBary[corner] = 0.0;
      }
    }
    nextBary /= nextBary.sum();

    SurfaceTraceSegment segment;
    segment.face = current.face;
    segment.startBarycentric = current.barycentric;
    segment.endBarycentric = nextBary;
    segment.family = currentFamily;
    segment.sign = currentSign;
    segment.entryEdge = entryEdge;
    segment.exitEdge = hitCorner;
    result.segments.push_back(segment);

    const Eigen::RowVector3d start =
        surface_cell_tracing_detail::point_position(vertices, faces, current);
    SurfaceTracePoint nextPoint;
    nextPoint.face = current.face;
    nextPoint.barycentric = nextBary;
    const Eigen::RowVector3d end =
        surface_cell_tracing_detail::point_position(vertices, faces, nextPoint);
    const double segmentLength = (end - start).norm();
    const double remainingLength = options.maxTraceLength - result.length;
    if (segmentLength > remainingLength && remainingLength > 0.0) {
      const double ratio = remainingLength / segmentLength;
      segment.endBarycentric =
          current.barycentric + ratio * (nextBary - current.barycentric);
      segment.endBarycentric /= segment.endBarycentric.sum();
      result.segments.back() = segment;
      result.length = options.maxTraceLength;
      result.termination = TraceTerminationReason::Budget;
      return result;
    }
    result.length += segmentLength;

    if (options.captureRadius > 0.0) {
      for (const SurfaceTracePoint &capture : options.capturePoints) {
        if (capture.face < 0) {
          continue;
        }
        const Eigen::RowVector3d capturePosition =
            surface_cell_tracing_detail::point_position(vertices, faces,
                                                        capture);
        bool captured = false;
        if (capture.face == current.face) {
          captured = (end - capturePosition).norm() <= options.captureRadius;
        } else {
          const int currentVertex =
              faces(current.face, surface_cell_tracing_detail::dominant_vertex_corner(
                                      nextBary));
          const int captureVertex =
              faces(capture.face,
                    surface_cell_tracing_detail::dominant_vertex_corner(
                        capture.barycentric));
          const Eigen::VectorXd intrinsic =
              surface_cell_tracing_detail::graph_distances_from_vertices(
                  vertices, faces, {captureVertex}, options.hardFeatureEdges);
          captured = currentVertex >= 0 && currentVertex < intrinsic.size() &&
                     intrinsic[currentVertex] <= options.captureRadius;
        }
        if (captured) {
          if (capture.face == current.face) {
            result.segments.back().endBarycentric = capture.barycentric;
          }
          result.termination = TraceTerminationReason::Captured;
          return result;
        }
      }
    }

    const int hitVertexCorner =
        surface_cell_tracing_detail::hit_vertex(nextBary);
    if (hitVertexCorner >= 0) {
      const int hitVertex = faces(current.face, hitVertexCorner);
      if (surface_cell_tracing_detail::contains_vertex(
              options.singularityVertices, hitVertex)) {
        result.termination = TraceTerminationReason::Singularity;
        return result;
      }
      const int outgoingFace =
          surface_cell_tracing_detail::choose_symbolic_outgoing_face(
              current.face, hitVertex, incident);
      if (outgoingFace < 0) {
        result.termination = TraceTerminationReason::Boundary;
        return result;
      }
      current = surface_cell_tracing_detail::vertex_point_in_face(
          faces, outgoingFace, hitVertex);
      entryEdge = -1;
      const Eigen::RowVector3d nextNormal =
          surface_cell_tracing_detail::face_normal(vertices, faces,
                                                  outgoingFace);
      Eigen::RowVector3d nextDirection =
          surface_cell_tracing_detail::axis_for_family(
              faceAxisX, faceAxisY, outgoingFace, currentFamily, currentSign);
      nextDirection =
          surface_cell_tracing_detail::project_tangent(nextDirection, nextNormal);
      const Eigen::RowVector3d forward =
          surface_cell_tracing_detail::project_tangent(direction, nextNormal);
      if (nextDirection.dot(forward) < 0.0) {
        nextDirection *= -1.0;
      }
      direction = nextDirection;
      continue;
    }

    const int a = faces(current.face, (hitCorner + 1) % 3);
    const int b = faces(current.face, (hitCorner + 2) % 3);
    const std::uint64_t key = surface_cell_tracing_detail::edge_key(a, b);
    if (options.hardFeatureEdges.count(key) != 0) {
      const Eigen::RowVector3d edgeDirection =
          (surface_cell_tracing_detail::row3(vertices, b) -
           surface_cell_tracing_detail::row3(vertices, a))
              .normalized();
      const double railAlignment =
          std::abs(surface_cell_tracing_detail::project_tangent(edgeDirection, normal)
                       .dot(direction));
      if (options.followCompatibleHardFeatureRails && railAlignment >= 0.7) {
        Eigen::RowVector3d railBary = Eigen::RowVector3d::Zero();
        for (int corner = 0; corner < 3; ++corner) {
          if (faces(current.face, corner) == a || faces(current.face, corner) == b) {
            railBary[corner] = 0.5;
          }
        }
        current.barycentric = railBary;
        direction = edgeDirection.dot(direction) >= 0.0 ? edgeDirection : -edgeDirection;
        entryEdge = hitCorner;
        continue;
      }
      result.termination = TraceTerminationReason::Feature;
      return result;
    }
    const auto found = edgeFaces.find(key);
    if (found == edgeFaces.end() || found->second[1] < 0) {
      result.termination = TraceTerminationReason::Boundary;
      return result;
    }
    const int nextFace =
        found->second[0] == current.face ? found->second[1] : found->second[0];
    nextPoint.face = nextFace;
    nextPoint.barycentric =
        surface_cell_tracing_detail::remap_barycentric_to_neighbor(
            faces, current.face, nextFace, nextBary);
    int transportedFamily = currentFamily;
    int transportedSign = currentSign;
    int matching = 0;
    double effort = 0.0;
    const auto matchingIndex = edgeMatchingIndices.find(key);
    if (matchingIndex != edgeMatchingIndices.end()) {
      const int index = matchingIndex->second;
      if (edgeMatching != nullptr && index >= 0 && index < edgeMatching->size()) {
        matching = (*edgeMatching)[index];
        if (found->second[1] == current.face) {
          matching = -matching;
        }
        const int branch =
            surface_cell_tracing_detail::branch_from_family_sign(currentFamily,
                                                                 currentSign);
        surface_cell_tracing_detail::family_sign_from_branch(branch + matching,
                                                             transportedFamily,
                                                             transportedSign);
      }
      if (edgeEffort != nullptr && index >= 0 && index < edgeEffort->size()) {
        effort = (*edgeEffort)[index];
      }
    }
    result.segments.back().matching = matching;
    result.segments.back().matchingEffort = effort;
    const Eigen::RowVector3d nextNormal =
        surface_cell_tracing_detail::face_normal(vertices, faces, nextFace);
    Eigen::RowVector3d nextDirection =
        surface_cell_tracing_detail::axis_for_family(
            faceAxisX, faceAxisY, nextFace, transportedFamily, transportedSign);
    nextDirection =
        surface_cell_tracing_detail::project_tangent(nextDirection, nextNormal);
    const Eigen::RowVector3d forward =
        surface_cell_tracing_detail::project_tangent(direction, nextNormal);
    if (nextDirection.dot(forward) < 0.0) {
      nextDirection *= -1.0;
    }
    current = nextPoint;
    currentFamily = transportedFamily;
    currentSign = transportedSign;
    entryEdge = hitCorner;
    direction = nextDirection;
  }

  result.termination = TraceTerminationReason::Budget;
  return result;
}

inline SurfaceWalkResult walk_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTracePoint &start, const int family, const int sign,
    const double distance, const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr) {
  SurfaceCellTracingOptions walkOptions = options;
  walkOptions.maxTraceLength = std::max(0.0, distance);
  SurfaceTraceSeed seed;
  seed.point = start;
  SurfaceWalkResult walk;
  walk.point = start;
  walk.trace = trace_surface_field(vertices, faces, faceAxisX, faceAxisY, seed,
                                   family, sign, walkOptions, edgeMatching,
                                   edgeEffort);
  if (!walk.trace.segments.empty()) {
    const SurfaceTraceSegment &last = walk.trace.segments.back();
    walk.point.face = last.face;
    walk.point.barycentric = last.endBarycentric;
  }
  return walk;
}

inline void cross_field_axes(const fields::CrossFieldResult &crossField,
                             Eigen::MatrixXd &faceAxisX,
                             Eigen::MatrixXd &faceAxisY) {
  if (crossField.primaryDirections.cols() == 3 &&
      crossField.secondaryDirections.cols() == 3 &&
      crossField.primaryDirections.rows() == crossField.secondaryDirections.rows()) {
    faceAxisX = crossField.primaryDirections;
    faceAxisY = crossField.secondaryDirections;
    return;
  }
  if (crossField.rawField.cols() < 6) {
    throw std::invalid_argument(
        "CrossFieldResult must contain primary/secondary directions or #F-by-12 rawField.");
  }
  faceAxisX = crossField.rawField.block(0, 0, crossField.rawField.rows(), 3);
  faceAxisY = crossField.rawField.block(0, 3, crossField.rawField.rows(), 3);
}

inline SurfaceTraceResult trace_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const SurfaceTraceSeed &seed,
    const int family, const int sign,
    const SurfaceCellTracingOptions &options = {}) {
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  cross_field_axes(crossField, faceAxisX, faceAxisY);
  return trace_surface_field(vertices, faces, faceAxisX, faceAxisY, seed, family,
                             sign, options, &crossField.matching,
                             &crossField.effort);
}

inline SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr) {
  SurfaceCellProposal proposal;
  proposal.seedId = seed.id;
  proposal.corners.fill(seed.point);
  const int face = seed.point.face;
  if (face < 0) {
    proposal.rejection = CellRejectionReason::Degenerate;
    return proposal;
  }
  double h = 0.0;
  for (int corner = 0; corner < 3; ++corner) {
    h += seed.point.barycentric[corner] *
         surface_cell_tracing_detail::target_size_at_vertex(
             targetSize, faces(face, corner), options.defaultTargetSize);
  }
  const double hx = h;
  const double hy = h;

  const std::array<std::pair<int, int>, 4> cornerSigns{
      std::pair<int, int>{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
  for (int corner = 0; corner < 4; ++corner) {
      const int sx = cornerSigns[static_cast<std::size_t>(corner)].first;
      const int sy = cornerSigns[static_cast<std::size_t>(corner)].second;
      const SurfaceWalkResult xFirst = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, 0, sx, 0.5 * hx,
          options, edgeMatching, edgeEffort);
      const SurfaceWalkResult xy = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, xFirst.point, 1, sy, 0.5 * hy,
          options, edgeMatching, edgeEffort);
      const SurfaceWalkResult yFirst = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, 1, sy, 0.5 * hy,
          options, edgeMatching, edgeEffort);
      const SurfaceWalkResult yx = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, yFirst.point, 0, sx, 0.5 * hx,
          options, edgeMatching, edgeEffort);

      if (xFirst.trace.termination == TraceTerminationReason::Feature ||
          xy.trace.termination == TraceTerminationReason::Feature ||
          yFirst.trace.termination == TraceTerminationReason::Feature ||
          yx.trace.termination == TraceTerminationReason::Feature) {
        proposal.rejection = CellRejectionReason::Barrier;
        return proposal;
      }
      if (xy.point.face < 0 || yx.point.face < 0) {
        proposal.rejection = CellRejectionReason::Degenerate;
        return proposal;
      }
      const Eigen::RowVector3d xyPosition =
          surface_cell_tracing_detail::point_position(vertices, faces, xy.point);
      const Eigen::RowVector3d yxPosition =
          surface_cell_tracing_detail::point_position(vertices, faces, yx.point);
      proposal.closureError =
          std::max(proposal.closureError, (xyPosition - yxPosition).norm());
      proposal.corners[static_cast<std::size_t>(corner)] = xy.point;
  }
  if (proposal.closureError >
      options.closureToleranceFactor * std::min(hx, hy)) {
    proposal.rejection = CellRejectionReason::Closure;
    return proposal;
  }
  std::array<Eigen::RowVector3d, 4> cornerPositions;
  for (int corner = 0; corner < 4; ++corner) {
    cornerPositions[static_cast<std::size_t>(corner)] =
        surface_cell_tracing_detail::point_position(
            vertices, faces, proposal.corners[static_cast<std::size_t>(corner)]);
  }
  if (!surface_cell_tracing_detail::quad_loop_is_valid(cornerPositions,
                                                       std::min(hx, hy))) {
    proposal.rejection = CellRejectionReason::Degenerate;
    return proposal;
  }

  const std::array<std::tuple<int, int, double>, 4> sideWalks{
      std::tuple<int, int, double>{0, 1, hx},
      std::tuple<int, int, double>{1, 1, hy},
      std::tuple<int, int, double>{0, -1, hx},
      std::tuple<int, int, double>{1, -1, hy}};
  for (int sideIndex = 0; sideIndex < 4; ++sideIndex) {
    const auto [sideFamily, sideSign, sideLength] =
        sideWalks[static_cast<std::size_t>(sideIndex)];
    const SurfaceTracePoint &startCorner =
        proposal.corners[static_cast<std::size_t>(sideIndex)];
    const SurfaceTracePoint &endCorner =
        proposal.corners[static_cast<std::size_t>((sideIndex + 1) % 4)];
    const SurfaceWalkResult side = walk_surface_field(
        vertices, faces, faceAxisX, faceAxisY, startCorner, sideFamily, sideSign,
        sideLength, options, edgeMatching, edgeEffort);
    if (side.trace.termination == TraceTerminationReason::Feature) {
      proposal.rejection = CellRejectionReason::Barrier;
      return proposal;
    }
    if (side.trace.segments.empty()) {
      proposal.rejection = CellRejectionReason::Degenerate;
      return proposal;
    }
    const Eigen::RowVector3d actualEnd =
        surface_cell_tracing_detail::point_position(vertices, faces, side.point);
    const Eigen::RowVector3d expectedEnd =
        surface_cell_tracing_detail::point_position(vertices, faces, endCorner);
    const double sideClosure = (actualEnd - expectedEnd).norm();
    proposal.closureError = std::max(proposal.closureError, sideClosure);
    if (sideClosure > options.closureToleranceFactor * std::min(hx, hy)) {
      proposal.rejection = CellRejectionReason::Closure;
      return proposal;
    }
    proposal.boundaryPaths[static_cast<std::size_t>(sideIndex)] =
        side.trace.segments;
    proposal.sides.insert(proposal.sides.end(), side.trace.segments.begin(),
                          side.trace.segments.end());
  }
  if (proposal.sides.empty()) {
    proposal.rejection = CellRejectionReason::Degenerate;
    return proposal;
  }
  proposal.accepted = true;
  proposal.rejection = CellRejectionReason::Accepted;
  return proposal;
}

inline SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const Eigen::VectorXd &targetSize,
    const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options = {}) {
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  cross_field_axes(crossField, faceAxisX, faceAxisY);
  return make_surface_cell_proposal(vertices, faces, faceAxisX, faceAxisY,
                                    targetSize, seed, options,
                                    &crossField.matching, &crossField.effort);
}

inline SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {},
    const Eigen::VectorXi *edgeMatching = nullptr,
    const Eigen::VectorXd *edgeEffort = nullptr) {
  SurfaceCellNetwork network;
  network.authoritativeRails = options.authoritativeRails;
  network.seeds =
      generate_deterministic_surface_seeds(vertices, faces, targetSize, options);
  for (const SurfaceTraceSeed &seed : network.seeds) {
    for (int family = 0; family < 2; ++family) {
      for (const int sign : {-1, 1}) {
        network.traces.push_back(trace_surface_field(
            vertices, faces, faceAxisX, faceAxisY, seed, family, sign, options,
            edgeMatching, edgeEffort));
      }
    }
    SurfaceCellProposal proposal = make_surface_cell_proposal(
        vertices, faces, faceAxisX, faceAxisY, targetSize, seed, options,
        edgeMatching, edgeEffort);
    ++network.stats.attempted;
    if (proposal.accepted) {
      ++network.stats.accepted;
    } else if (proposal.rejection == CellRejectionReason::Closure) {
      ++network.stats.rejectedClosure;
    } else if (proposal.rejection == CellRejectionReason::Barrier) {
      ++network.stats.rejectedBarrier;
    } else {
      ++network.stats.rejectedDegenerate;
    }
    network.proposals.push_back(std::move(proposal));
  }
  return network;
}

inline SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField, const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {}) {
  Eigen::MatrixXd faceAxisX;
  Eigen::MatrixXd faceAxisY;
  cross_field_axes(crossField, faceAxisX, faceAxisY);
  return build_surface_cell_network(vertices, faces, faceAxisX, faceAxisY,
                                    targetSize, options, &crossField.matching,
                                    &crossField.effort);
}

inline SurfaceCellTracingOverlay make_surface_cell_tracing_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
    const double glyphScale = 0.25) {
  SurfaceCellTracingOverlay overlay;

  overlay.crossGlyphStarts.resize(2 * faces.rows(), 3);
  overlay.crossGlyphEnds.resize(2 * faces.rows(), 3);
  overlay.crossGlyphFamily.resize(2 * faces.rows());
  for (int face = 0; face < faces.rows(); ++face) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    double h = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      centroid += surface_cell_tracing_detail::row3(
                      vertices, faces(face, corner)) /
                  3.0;
      h += surface_cell_tracing_detail::target_size_at_vertex(
               targetSize, faces(face, corner), 1.0) /
           3.0;
    }
    const Eigen::RowVector3d normal =
        surface_cell_tracing_detail::face_normal(vertices, faces, face);
    const std::array<Eigen::RowVector3d, 2> axes = {
        surface_cell_tracing_detail::project_tangent(faceAxisX.row(face),
                                                     normal),
        surface_cell_tracing_detail::project_tangent(faceAxisY.row(face),
                                                     normal)};
    for (int family = 0; family < 2; ++family) {
      const int row = 2 * face + family;
      overlay.crossGlyphStarts.row(row) =
          centroid - glyphScale * h * axes[static_cast<std::size_t>(family)];
      overlay.crossGlyphEnds.row(row) =
          centroid + glyphScale * h * axes[static_cast<std::size_t>(family)];
      overlay.crossGlyphFamily(row) = family;
    }
  }

  overlay.seedPositions.resize(static_cast<int>(network.seeds.size()), 3);
  overlay.seedProvenance.resize(static_cast<int>(network.seeds.size()));
  for (int index = 0; index < static_cast<int>(network.seeds.size()); ++index) {
    const SurfaceTraceSeed &seed = network.seeds[static_cast<std::size_t>(index)];
    overlay.seedPositions.row(index) =
        surface_cell_tracing_detail::point_position(vertices, faces, seed.point);
    overlay.seedProvenance(index) = static_cast<int>(seed.provenance);
  }

  int segmentCount = 0;
  for (const SurfaceTraceResult &trace : network.traces) {
    segmentCount += static_cast<int>(trace.segments.size());
  }
  overlay.traceSegmentStarts.resize(segmentCount, 3);
  overlay.traceSegmentEnds.resize(segmentCount, 3);
  overlay.traceFamily.resize(segmentCount);
  overlay.traceSign.resize(segmentCount);
  overlay.traceTermination.resize(segmentCount);
  int segmentIndex = 0;
  for (const SurfaceTraceResult &trace : network.traces) {
    for (const SurfaceTraceSegment &segment : trace.segments) {
      overlay.traceSegmentStarts.row(segmentIndex) =
          surface_cell_tracing_detail::point_position(
              vertices, faces,
              SurfaceTracePoint{segment.face, segment.startBarycentric});
      overlay.traceSegmentEnds.row(segmentIndex) =
          surface_cell_tracing_detail::point_position(
              vertices, faces,
              SurfaceTracePoint{segment.face, segment.endBarycentric});
      overlay.traceFamily(segmentIndex) = segment.family;
      overlay.traceSign(segmentIndex) = segment.sign;
      overlay.traceTermination(segmentIndex) =
          static_cast<int>(trace.termination);
      ++segmentIndex;
    }
  }

  overlay.cellClosureError.resize(static_cast<int>(network.proposals.size()));
  overlay.cellRejection.resize(static_cast<int>(network.proposals.size()));
  for (int index = 0; index < static_cast<int>(network.proposals.size());
       ++index) {
    const SurfaceCellProposal &proposal =
        network.proposals[static_cast<std::size_t>(index)];
    overlay.cellClosureError(index) = proposal.closureError;
    overlay.cellRejection(index) = static_cast<int>(proposal.rejection);
  }
  return overlay;
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_CELL_TRACING_H
