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

struct SurfaceTracePoint {
  int face = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
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
  SurfaceGuidePotential guidePotential;
};

struct SurfaceCellNetwork {
  std::vector<SurfaceTraceSeed> seeds;
  std::vector<SurfaceTraceResult> traces;
  std::vector<SurfaceCellProposal> proposals;
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
    nearest.setConstant(std::numeric_limits<double>::infinity());
    for (const SurfaceTraceSeed &seed : seeds) {
      const Eigen::RowVector3d seedPosition =
          surface_cell_tracing_detail::point_position(vertices, faces,
                                                      seed.point);
      for (int vertex = 0; vertex < vertexCount; ++vertex) {
        const double distance =
            (surface_cell_tracing_detail::row3(vertices, vertex) - seedPosition)
                .norm();
        nearest[vertex] = std::min(nearest[vertex], distance);
      }
    }
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
    const SurfaceCellTracingOptions &options = {}) {
  if (faceAxisX.rows() != faces.rows() || faceAxisX.cols() != 3 ||
      faceAxisY.rows() != faces.rows() || faceAxisY.cols() != 3) {
    throw std::invalid_argument("face axes must have shape (#F, 3).");
  }
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  const auto incident = surface_cell_tracing_detail::incident_faces_by_vertex(
      static_cast<int>(vertices.rows()), faces);
  SurfaceTraceResult result;
  SurfaceTracePoint current = seed.point;
  Eigen::RowVector3d direction =
      (family == 0 ? faceAxisX.row(current.face) : faceAxisY.row(current.face));
  direction *= sign >= 0 ? 1.0 : -1.0;
  std::set<std::tuple<int, int, int>> states;
  std::set<std::tuple<int, int>> faceFamilyStates;

  for (int step = 0; step < options.maxTraceSegments &&
                     result.length < options.maxTraceLength;
       ++step) {
    const int branchSign = direction.sum() >= 0.0 ? 1 : -1;
    const auto stateKey = std::make_tuple(current.face, family, branchSign);
    if (!states.insert(stateKey).second && step > 0) {
      result.termination = TraceTerminationReason::RepeatedState;
      return result;
    }
    const auto faceFamilyKey = std::make_tuple(current.face, family);
    const bool repeatedFaceFamily =
        !faceFamilyStates.insert(faceFamilyKey).second && step > 0;
    if (repeatedFaceFamily &&
        (surface_cell_tracing_detail::point_on_edge(current.barycentric, 0) ||
         surface_cell_tracing_detail::point_on_edge(current.barycentric, 1) ||
         surface_cell_tracing_detail::point_on_edge(current.barycentric, 2))) {
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
    segment.family = family;
    segment.sign = sign >= 0 ? 1 : -1;
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
        if ((end - capturePosition).norm() <= options.captureRadius) {
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
      const Eigen::RowVector3d nextNormal =
          surface_cell_tracing_detail::face_normal(vertices, faces,
                                                  outgoingFace);
      const Eigen::RowVector3d preferred =
          family == 0 ? faceAxisX.row(outgoingFace) : faceAxisY.row(outgoingFace);
      Eigen::RowVector3d nextDirection =
          surface_cell_tracing_detail::project_tangent(preferred, nextNormal);
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
    const Eigen::RowVector3d nextNormal =
        surface_cell_tracing_detail::face_normal(vertices, faces, nextFace);
    const Eigen::RowVector3d preferred =
        family == 0 ? faceAxisX.row(nextFace) : faceAxisY.row(nextFace);
    Eigen::RowVector3d nextDirection =
        surface_cell_tracing_detail::project_tangent(preferred, nextNormal);
    const Eigen::RowVector3d forward =
        surface_cell_tracing_detail::project_tangent(direction, nextNormal);
    if (nextDirection.dot(forward) < 0.0) {
      nextDirection *= -1.0;
    }
    current = nextPoint;
    direction = nextDirection;
  }

  result.termination = TraceTerminationReason::Budget;
  return result;
}

inline SurfaceWalkResult walk_surface_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const SurfaceTracePoint &start, const int family, const int sign,
    const double distance, const SurfaceCellTracingOptions &options = {}) {
  SurfaceCellTracingOptions walkOptions = options;
  walkOptions.maxTraceLength = std::max(0.0, distance);
  SurfaceTraceSeed seed;
  seed.point = start;
  SurfaceWalkResult walk;
  walk.point = start;
  walk.trace = trace_surface_field(vertices, faces, faceAxisX, faceAxisY, seed,
                                   family, sign, walkOptions);
  if (!walk.trace.segments.empty()) {
    const SurfaceTraceSegment &last = walk.trace.segments.back();
    walk.point.face = last.face;
    walk.point.barycentric = last.endBarycentric;
  }
  return walk;
}

inline SurfaceCellProposal make_surface_cell_proposal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize, const SurfaceTraceSeed &seed,
    const SurfaceCellTracingOptions &options = {}) {
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

  int cornerIndex = 0;
  for (const int sx : {-1, 1}) {
    for (const int sy : {-1, 1}) {
      const SurfaceWalkResult xFirst = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, 0, sx, 0.5 * hx,
          options);
      const SurfaceWalkResult xy = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, xFirst.point, 1, sy, 0.5 * hy,
          options);
      const SurfaceWalkResult yFirst = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, 1, sy, 0.5 * hy,
          options);
      const SurfaceWalkResult yx = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, yFirst.point, 0, sx, 0.5 * hx,
          options);

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
      proposal.corners[static_cast<std::size_t>(cornerIndex++)] = xy.point;
    }
  }
  if (proposal.closureError >
      options.closureToleranceFactor * std::min(hx, hy)) {
    proposal.rejection = CellRejectionReason::Closure;
    return proposal;
  }

  for (int family = 0; family < 2; ++family) {
    for (const int sign : {-1, 1}) {
      const SurfaceWalkResult side = walk_surface_field(
          vertices, faces, faceAxisX, faceAxisY, seed.point, family, sign,
          0.5 * (family == 0 ? hx : hy), options);
      if (side.trace.termination == TraceTerminationReason::Feature) {
        proposal.rejection = CellRejectionReason::Barrier;
        return proposal;
      }
      proposal.sides.insert(proposal.sides.end(), side.trace.segments.begin(),
                            side.trace.segments.end());
    }
  }
  if (proposal.sides.empty()) {
    proposal.rejection = CellRejectionReason::Degenerate;
    return proposal;
  }
  proposal.accepted = true;
  proposal.rejection = CellRejectionReason::Accepted;
  return proposal;
}

inline SurfaceCellNetwork build_surface_cell_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &faceAxisX, const Eigen::MatrixXd &faceAxisY,
    const Eigen::VectorXd &targetSize,
    const SurfaceCellTracingOptions &options = {}) {
  SurfaceCellNetwork network;
  network.seeds =
      generate_deterministic_surface_seeds(vertices, faces, targetSize, options);
  for (const SurfaceTraceSeed &seed : network.seeds) {
    for (int family = 0; family < 2; ++family) {
      for (const int sign : {-1, 1}) {
        network.traces.push_back(trace_surface_field(
            vertices, faces, faceAxisX, faceAxisY, seed, family, sign, options));
      }
    }
    SurfaceCellProposal proposal = make_surface_cell_proposal(
        vertices, faces, faceAxisX, faceAxisY, targetSize, seed, options);
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
