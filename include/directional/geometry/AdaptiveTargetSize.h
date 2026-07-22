// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_ADAPTIVE_TARGET_SIZE_H
#define DIRECTIONAL_GEOMETRY_ADAPTIVE_TARGET_SIZE_H

#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>
#include <directional/geometry/AdaptiveFeatureMap.h>
#include <directional/geometry/FaceCurvature.h>
#include <directional/geometry/MeshComponents.h>
#include <directional/geometry/SurfacePoint.h>

namespace directional::geometry {

struct IntrinsicGraphDistanceResult {
  Eigen::VectorXd distance;
  Eigen::VectorXi previous;
  std::vector<std::pair<int, int>> edges;
};

struct LocalThicknessOptions {
  bool sameComponentOnly = true;
  bool requireOpposingNormals = true;
  double normalCompatibility = 0.85;
  double percentile = 0.25;
  double minimumDistance = 1.0e-12;
  std::vector<int> faceSheets;
};

struct LocalThicknessResult {
  Eigen::VectorXd thickness;
  Eigen::VectorXi candidateFace;
  Eigen::VectorXi component;
  Eigen::VectorXi validCandidateCount;
};

struct AdaptiveTargetSizeOptions {
  double baseSize = 1.0;
  double minSize = 0.0;
  double maxSize = std::numeric_limits<double>::infinity();
  double salienceWeight = 1.0;
  double featureDensityWeight = 1.0;
  double maxSurfaceErrorRatio = 0.05;
  double absoluteSurfaceError = -1.0;
  double thicknessScale = 0.35;
  double curvatureEpsilon = 1.0e-12;
  double gradationRatio = 2.0;
  int gradationPasses = 64;
  bool enableHeatDistance = false;
  bool enableSkeletonHints = false;
};

struct PrincipalVertexCurvatureResult {
  Eigen::VectorXd curvature;
  Eigen::VectorXd confidence;
};

struct AdaptiveTargetSizeInput {
  Eigen::VectorXd salience;
  Eigen::VectorXd featureDensity;
  Eigen::VectorXd curvature;
  Eigen::VectorXd thickness;
};

struct AdaptiveTargetSizeResult {
  Eigen::VectorXd normalizedSalience;
  Eigen::VectorXd normalizedFeatureDensity;
  Eigen::VectorXd curvature;
  Eigen::VectorXd thickness;
  Eigen::VectorXd salienceSize;
  Eigen::VectorXd curvatureSize;
  Eigen::VectorXd thicknessSize;
  Eigen::VectorXd targetSize;
  double resolvedSurfaceError = 0.0;
  bool allFinite = true;
};

namespace adaptive_target_size_detail {

inline std::pair<int, int> canonical_edge(const int a, const int b) {
  return a <= b ? std::pair<int, int>{a, b} : std::pair<int, int>{b, a};
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

inline Eigen::RowVector3d face_normal(const Eigen::MatrixXd &vertices,
                                      const Eigen::MatrixXi &faces,
                                      const int face) {
  const Eigen::RowVector3d a = row3(vertices, faces(face, 0));
  const Eigen::RowVector3d b = row3(vertices, faces(face, 1));
  const Eigen::RowVector3d c = row3(vertices, faces(face, 2));
  Eigen::RowVector3d normal = cross3(b - a, c - a);
  const double length = normal.norm();
  if (length > 0.0) {
    normal /= length;
  }
  return normal;
}

inline double percentile(std::vector<double> values, const double q) {
  if (values.empty()) {
    return std::numeric_limits<double>::infinity();
  }
  std::sort(values.begin(), values.end());
  const double clamped = std::clamp(q, 0.0, 1.0);
  const std::size_t index = static_cast<std::size_t>(
      std::floor(clamped * static_cast<double>(values.size() - 1) + 0.5));
  return values[index];
}

inline double robust_positive_scale(std::vector<double> values) {
  values.erase(std::remove_if(values.begin(), values.end(),
                              [](const double value) {
                                return !std::isfinite(value) || value <= 0.0;
                              }),
               values.end());
  if (values.empty()) {
    return 1.0;
  }
  std::sort(values.begin(), values.end());
  const std::size_t index = static_cast<std::size_t>(
      std::floor(0.95 * static_cast<double>(values.size() - 1) + 0.5));
  return std::max(values[index], std::numeric_limits<double>::epsilon());
}

inline Eigen::VectorXd robust_normalize(const Eigen::VectorXd &values,
                                        const int count) {
  Eigen::VectorXd normalized = Eigen::VectorXd::Zero(count);
  if (values.size() == 0) {
    return normalized;
  }
  if (values.size() != count) {
    throw std::invalid_argument("adaptive size input vector has wrong size.");
  }
  std::vector<double> positive;
  positive.reserve(static_cast<std::size_t>(count));
  for (int i = 0; i < count; ++i) {
    if (std::isfinite(values[i]) && values[i] > 0.0) {
      positive.push_back(values[i]);
    }
  }
  const double scale = robust_positive_scale(positive);
  for (int i = 0; i < count; ++i) {
    normalized[i] =
        std::isfinite(values[i]) ? std::clamp(values[i] / scale, 0.0, 1.0)
                                 : 0.0;
  }
  return normalized;
}

inline std::vector<std::vector<std::pair<int, double>>>
vertex_graph(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
             std::vector<std::pair<int, int>> *edgesOut = nullptr) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("vertex graph requires 3D triangle mesh.");
  }
  std::map<std::pair<int, int>, double> edgeLengths;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      if (a < 0 || b < 0 || a >= vertices.rows() || b >= vertices.rows() ||
          a == b) {
        continue;
      }
      const std::pair<int, int> edge = canonical_edge(a, b);
      const double length = (row3(vertices, a) - row3(vertices, b)).norm();
      const auto existing = edgeLengths.find(edge);
      if (existing == edgeLengths.end()) {
        edgeLengths.emplace(edge, length);
      } else {
        existing->second = std::min(existing->second, length);
      }
    }
  }

  std::vector<std::vector<std::pair<int, double>>> graph(
      static_cast<std::size_t>(vertices.rows()));
  if (edgesOut != nullptr) {
    edgesOut->clear();
    edgesOut->reserve(edgeLengths.size());
  }
  for (const auto &[edge, length] : edgeLengths) {
    graph[static_cast<std::size_t>(edge.first)].push_back({edge.second, length});
    graph[static_cast<std::size_t>(edge.second)].push_back({edge.first, length});
    if (edgesOut != nullptr) {
      edgesOut->push_back(edge);
    }
  }
  for (auto &adjacent : graph) {
    std::sort(adjacent.begin(), adjacent.end(),
              [](const auto &lhs, const auto &rhs) {
                return lhs.first < rhs.first;
              });
  }
  return graph;
}

inline std::vector<int> face_components_by_index(const Eigen::MatrixXi &faces) {
  std::vector<int> components(static_cast<std::size_t>(faces.rows()), -1);
  const std::vector<std::vector<int>> groups = face_connected_components(faces);
  for (int component = 0; component < static_cast<int>(groups.size());
       ++component) {
    for (const int face : groups[static_cast<std::size_t>(component)]) {
      components[static_cast<std::size_t>(face)] = component;
    }
  }
  return components;
}

inline Eigen::RowVector3d closest_point_on_triangle(
    const Eigen::RowVector3d &p, const Eigen::RowVector3d &a,
    const Eigen::RowVector3d &b, const Eigen::RowVector3d &c) {
  const Eigen::RowVector3d ab = b - a;
  const Eigen::RowVector3d ac = c - a;
  const Eigen::RowVector3d ap = p - a;
  const double d1 = ab.dot(ap);
  const double d2 = ac.dot(ap);
  if (d1 <= 0.0 && d2 <= 0.0) {
    return a;
  }

  const Eigen::RowVector3d bp = p - b;
  const double d3 = ab.dot(bp);
  const double d4 = ac.dot(bp);
  if (d3 >= 0.0 && d4 <= d3) {
    return b;
  }

  const double vc = d1 * d4 - d3 * d2;
  if (vc <= 0.0 && d1 >= 0.0 && d3 <= 0.0) {
    const double v = d1 / (d1 - d3);
    return a + v * ab;
  }

  const Eigen::RowVector3d cp = p - c;
  const double d5 = ab.dot(cp);
  const double d6 = ac.dot(cp);
  if (d6 >= 0.0 && d5 <= d6) {
    return c;
  }

  const double vb = d5 * d2 - d1 * d6;
  if (vb <= 0.0 && d2 >= 0.0 && d6 <= 0.0) {
    const double w = d2 / (d2 - d6);
    return a + w * ac;
  }

  const double va = d3 * d6 - d5 * d4;
  if (va <= 0.0 && (d4 - d3) >= 0.0 && (d5 - d6) >= 0.0) {
    const double w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
    return b + w * (c - b);
  }

  const double denom = 1.0 / (va + vb + vc);
  const double v = vb * denom;
  const double w = vc * denom;
  return a + ab * v + ac * w;
}

} // namespace adaptive_target_size_detail

inline IntrinsicGraphDistanceResult compute_intrinsic_graph_distances(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &sourceVertices) {
  using Node = std::pair<double, int>;
  constexpr double infinity = std::numeric_limits<double>::infinity();
  IntrinsicGraphDistanceResult result;
  const int vertexCount = static_cast<int>(vertices.rows());
  result.distance = Eigen::VectorXd::Constant(vertexCount, infinity);
  result.previous = Eigen::VectorXi::Constant(vertexCount, -1);
  const auto graph =
      adaptive_target_size_detail::vertex_graph(vertices, faces, &result.edges);

  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;
  std::vector<int> sortedSources = sourceVertices;
  std::sort(sortedSources.begin(), sortedSources.end());
  sortedSources.erase(std::unique(sortedSources.begin(), sortedSources.end()),
                      sortedSources.end());
  for (const int source : sortedSources) {
    if (source < 0 || source >= vertexCount) {
      continue;
    }
    result.distance[source] = 0.0;
    result.previous[source] = source;
    queue.push({0.0, source});
  }

  while (!queue.empty()) {
    const auto [distance, vertex] = queue.top();
    queue.pop();
    if (distance != result.distance[vertex]) {
      continue;
    }
    for (const auto &[neighbor, length] :
         graph[static_cast<std::size_t>(vertex)]) {
      const double candidate = distance + length;
      if (candidate + 1.0e-14 < result.distance[neighbor] ||
          (std::abs(candidate - result.distance[neighbor]) <= 1.0e-14 &&
           vertex < result.previous[neighbor])) {
        result.distance[neighbor] = candidate;
        result.previous[neighbor] = vertex;
        queue.push({candidate, neighbor});
      }
    }
  }
  return result;
}

inline Eigen::VectorXd estimate_vertex_feature_salience(
    const int vertexCount, const AdaptiveFeatureMap &featureMap) {
  Eigen::VectorXd salience = Eigen::VectorXd::Zero(vertexCount);
  for (const AdaptiveFeatureEdge &edge : featureMap.edges) {
    const double strength = std::max(0.0, edge.strength);
    if (edge.vertices.first >= 0 && edge.vertices.first < vertexCount) {
      salience[edge.vertices.first] =
          std::max(salience[edge.vertices.first], strength);
    }
    if (edge.vertices.second >= 0 && edge.vertices.second < vertexCount) {
      salience[edge.vertices.second] =
          std::max(salience[edge.vertices.second], strength);
    }
  }
  return salience;
}

inline Eigen::VectorXd estimate_dihedral_vertex_curvature(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces) {
  using adaptive_target_size_detail::canonical_edge;
  using adaptive_target_size_detail::face_normal;
  using adaptive_target_size_detail::row3;
  std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      if (a >= 0 && b >= 0 && a < vertices.rows() && b < vertices.rows() &&
          a != b) {
        edgeFaces[canonical_edge(a, b)].push_back(face);
      }
    }
  }

  std::vector<Eigen::RowVector3d> normals;
  normals.reserve(static_cast<std::size_t>(faces.rows()));
  for (int face = 0; face < faces.rows(); ++face) {
    normals.push_back(face_normal(vertices, faces, face));
  }

  Eigen::VectorXd curvature = Eigen::VectorXd::Zero(vertices.rows());
  for (const auto &[edge, incidentFaces] : edgeFaces) {
    if (incidentFaces.size() != 2) {
      continue;
    }
    const double dot =
        std::clamp(normals[static_cast<std::size_t>(incidentFaces[0])].dot(
                       normals[static_cast<std::size_t>(incidentFaces[1])]),
                   -1.0, 1.0);
    const double angle = std::acos(dot);
    const double length = std::max(
        (row3(vertices, edge.first) - row3(vertices, edge.second)).norm(),
        std::numeric_limits<double>::epsilon());
    const double kappa = angle / length;
    curvature[edge.first] = std::max(curvature[edge.first], kappa);
    curvature[edge.second] = std::max(curvature[edge.second], kappa);
  }
  return curvature;
}

inline PrincipalVertexCurvatureResult estimate_principal_vertex_curvature(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const FaceCurvatureOptions &options = {}) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument(
        "principal vertex curvature expects 3D triangles.");
  }
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  const FaceCurvatureResult faceCurvature = estimate_face_curvature(
      mesh.V, mesh.F, mesh.FBx, mesh.FBy, mesh.faceNormals, mesh.faceAreas,
      mesh.TT, mesh.vertexNormals, options);

  PrincipalVertexCurvatureResult result;
  result.curvature = Eigen::VectorXd::Zero(vertices.rows());
  result.confidence = Eigen::VectorXd::Zero(vertices.rows());
  Eigen::VectorXd weights = Eigen::VectorXd::Zero(vertices.rows());
  for (int face = 0; face < faces.rows(); ++face) {
    if (faceCurvature.valid(face) == 0) {
      continue;
    }
    const double kappa =
        std::max(std::abs(faceCurvature.principalCurvatures(face, 0)),
                 std::abs(faceCurvature.principalCurvatures(face, 1)));
    const double confidence = std::clamp(faceCurvature.confidence(face), 0.0, 1.0);
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      if (vertex < 0 || vertex >= vertices.rows()) {
        continue;
      }
      const double weight = std::max(mesh.faceAreas(face), 1.0e-30);
      result.curvature[vertex] += weight * confidence * kappa;
      result.confidence[vertex] += weight * confidence;
      weights[vertex] += weight;
    }
  }
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    if (result.confidence[vertex] > 0.0) {
      result.curvature[vertex] /= result.confidence[vertex];
    }
    if (weights[vertex] > 0.0) {
      result.confidence[vertex] /= weights[vertex];
    }
  }
  return result;
}

inline LocalThicknessResult estimate_local_thickness(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const LocalThicknessOptions &options = {}) {
  using adaptive_target_size_detail::closest_point_on_triangle;
  using adaptive_target_size_detail::face_normal;
  using adaptive_target_size_detail::percentile;
  using adaptive_target_size_detail::row3;
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("estimate_local_thickness expects 3D triangles.");
  }

  const int vertexCount = static_cast<int>(vertices.rows());
  const int faceCount = static_cast<int>(faces.rows());
  LocalThicknessResult result;
  result.thickness =
      Eigen::VectorXd::Constant(vertexCount, std::numeric_limits<double>::infinity());
  result.candidateFace = Eigen::VectorXi::Constant(vertexCount, -1);
  result.component = Eigen::VectorXi::Constant(vertexCount, -1);
  result.validCandidateCount = Eigen::VectorXi::Zero(vertexCount);

  const std::vector<int> faceComponents =
      adaptive_target_size_detail::face_components_by_index(faces);
  const bool hasSheets =
      options.faceSheets.size() == static_cast<std::size_t>(faceCount);
  std::vector<std::set<int>> incidentFaces(static_cast<std::size_t>(vertexCount));
  std::vector<std::set<int>> adjacentVertices(static_cast<std::size_t>(vertexCount));
  for (int face = 0; face < faceCount; ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = faces(face, corner);
      const int b = faces(face, (corner + 1) % 3);
      if (a < 0 || b < 0 || a >= vertexCount || b >= vertexCount) {
        continue;
      }
      incidentFaces[static_cast<std::size_t>(a)].insert(face);
      adjacentVertices[static_cast<std::size_t>(a)].insert(b);
      adjacentVertices[static_cast<std::size_t>(b)].insert(a);
      if (result.component[a] < 0) {
        result.component[a] = faceComponents[static_cast<std::size_t>(face)];
      }
    }
  }

  std::vector<std::set<int>> excludedFaces = incidentFaces;
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    std::set<int> oneRing = adjacentVertices[static_cast<std::size_t>(vertex)];
    std::set<int> twoRing = oneRing;
    for (const int neighbor : oneRing) {
      const auto &neighborsOfNeighbor =
          adjacentVertices[static_cast<std::size_t>(neighbor)];
      twoRing.insert(neighborsOfNeighbor.begin(), neighborsOfNeighbor.end());
    }
    for (const int nearVertex : twoRing) {
      const auto &nearFaces = incidentFaces[static_cast<std::size_t>(nearVertex)];
      excludedFaces[static_cast<std::size_t>(vertex)].insert(nearFaces.begin(),
                                                            nearFaces.end());
    }
  }

  std::vector<Eigen::RowVector3d> faceNormals;
  faceNormals.reserve(static_cast<std::size_t>(faceCount));
  for (int face = 0; face < faceCount; ++face) {
    faceNormals.push_back(face_normal(vertices, faces, face));
  }
  std::vector<Eigen::RowVector3d> vertexNormals(
      static_cast<std::size_t>(vertexCount), Eigen::RowVector3d::Zero());
  for (int face = 0; face < faceCount; ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = faces(face, corner);
      if (vertex >= 0 && vertex < vertexCount) {
        vertexNormals[static_cast<std::size_t>(vertex)] +=
            faceNormals[static_cast<std::size_t>(face)];
      }
    }
  }
  for (Eigen::RowVector3d &normal : vertexNormals) {
    const double length = normal.norm();
    if (length > 0.0) {
      normal /= length;
    }
  }

  const SurfaceProjectionBvh projectionBvh(vertices, faces);
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    const Eigen::RowVector3d point = row3(vertices, vertex);
    std::vector<unsigned char> allowedFaces(static_cast<std::size_t>(faceCount),
                                            0);
    int allowedCount = 0;
    for (int face = 0; face < faceCount; ++face) {
      if (excludedFaces[static_cast<std::size_t>(vertex)].count(face) != 0) {
        continue;
      }
      if (options.sameComponentOnly &&
          result.component[vertex] != faceComponents[static_cast<std::size_t>(face)]) {
        continue;
      }
      if (hasSheets && result.component[vertex] >= 0) {
        const int referenceSheet = [&]() {
          for (const int incident :
               incidentFaces[static_cast<std::size_t>(vertex)]) {
            if (incident >= 0 && incident < faceCount) {
              return options.faceSheets[static_cast<std::size_t>(incident)];
            }
          }
          return -1;
        }();
        if (referenceSheet >= 0 &&
            options.faceSheets[static_cast<std::size_t>(face)] !=
                referenceSheet) {
          continue;
        }
      }
      if (options.requireOpposingNormals &&
          vertexNormals[static_cast<std::size_t>(vertex)].squaredNorm() > 0.0 &&
          faceNormals[static_cast<std::size_t>(face)].squaredNorm() > 0.0 &&
          vertexNormals[static_cast<std::size_t>(vertex)].dot(
              faceNormals[static_cast<std::size_t>(face)]) >
              -std::abs(options.normalCompatibility)) {
        continue;
      }
      allowedFaces[static_cast<std::size_t>(face)] = 1;
      ++allowedCount;
    }
    result.validCandidateCount[vertex] = allowedCount;
    if (allowedCount > 0) {
      SurfaceProjectionOptions projectionOptions;
      projectionOptions.allowedFaces = &allowedFaces;
      const SurfacePoint projected =
          projectionBvh.project(point.transpose(), projectionOptions);
      if (projected.valid()) {
        const double distance = std::sqrt(projected.squaredDistance);
        if (std::isfinite(distance) && distance > options.minimumDistance) {
          result.thickness[vertex] = distance;
          result.candidateFace[vertex] = projected.face;
        }
      }
    }
  }
  return result;
}

inline Eigen::VectorXd apply_size_gradation(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &sizes, const double ratio, const int maxPasses) {
  if (sizes.size() != vertices.rows()) {
    throw std::invalid_argument("gradation size vector has wrong size.");
  }
  std::vector<std::pair<int, int>> edges;
  adaptive_target_size_detail::vertex_graph(vertices, faces, &edges);
  Eigen::VectorXd graded = sizes;
  const double safeRatio = std::max(1.0, ratio);
  for (int pass = 0; pass < maxPasses; ++pass) {
    bool changed = false;
    for (const auto &[a, b] : edges) {
      if (std::isfinite(graded[a]) && std::isfinite(graded[b])) {
        if (graded[a] > safeRatio * graded[b]) {
          graded[a] = safeRatio * graded[b];
          changed = true;
        }
        if (graded[b] > safeRatio * graded[a]) {
          graded[b] = safeRatio * graded[a];
          changed = true;
        }
      }
    }
    if (!changed) {
      break;
    }
  }
  return graded;
}

inline AdaptiveTargetSizeResult compute_adaptive_target_size(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const AdaptiveTargetSizeInput &input,
    const AdaptiveTargetSizeOptions &options = {}) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("adaptive target size expects 3D triangles.");
  }
  if (!(options.baseSize > 0.0)) {
    throw std::invalid_argument("adaptive target size baseSize must be positive.");
  }
  if (options.minSize < 0.0 || options.maxSize < options.minSize) {
    throw std::invalid_argument("adaptive target size clamp range is invalid.");
  }
  if (options.enableHeatDistance) {
    throw std::invalid_argument(
        "Heat-method distance is unsupported in Phase 12 MVP; use deterministic graph distances.");
  }
  if (options.enableSkeletonHints) {
    throw std::invalid_argument(
        "Curve-skeleton hints are unsupported in Phase 12 MVP; leave skeleton hints disabled.");
  }

  const int vertexCount = static_cast<int>(vertices.rows());
  AdaptiveTargetSizeResult result;
  result.normalizedSalience =
      adaptive_target_size_detail::robust_normalize(input.salience, vertexCount);
  result.normalizedFeatureDensity =
      adaptive_target_size_detail::robust_normalize(input.featureDensity,
                                                    vertexCount);
  result.curvature = input.curvature.size() == 0
                         ? Eigen::VectorXd::Zero(vertexCount)
                         : input.curvature;
  result.thickness =
      input.thickness.size() == 0
          ? Eigen::VectorXd::Constant(vertexCount,
                                      std::numeric_limits<double>::infinity())
          : input.thickness;
  if (result.curvature.size() != vertexCount ||
      result.thickness.size() != vertexCount) {
    throw std::invalid_argument("adaptive target size input vector has wrong size.");
  }

  result.resolvedSurfaceError =
      options.absoluteSurfaceError > 0.0
          ? options.absoluteSurfaceError
          : std::max(0.0, options.maxSurfaceErrorRatio) * options.baseSize;
  result.salienceSize.resize(vertexCount);
  result.curvatureSize.resize(vertexCount);
  result.thicknessSize.resize(vertexCount);
  result.targetSize.resize(vertexCount);

  const double clampMax = options.maxSize;
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    const double salienceDenominator =
        1.0 + options.salienceWeight * result.normalizedSalience[vertex] +
        options.featureDensityWeight * result.normalizedFeatureDensity[vertex];
    result.salienceSize[vertex] =
        options.baseSize / std::max(salienceDenominator,
                                    std::numeric_limits<double>::epsilon());
    const double kappa =
        std::isfinite(result.curvature[vertex]) ? std::abs(result.curvature[vertex])
                                                : 0.0;
    result.curvatureSize[vertex] = std::sqrt(
        8.0 * result.resolvedSurfaceError / (kappa + options.curvatureEpsilon));
    result.thicknessSize[vertex] =
        std::isfinite(result.thickness[vertex])
            ? options.thicknessScale * result.thickness[vertex]
            : std::numeric_limits<double>::infinity();
    double size = std::min({result.salienceSize[vertex],
                            result.curvatureSize[vertex],
                            result.thicknessSize[vertex]});
    if (!std::isfinite(size)) {
      size = clampMax;
    }
    size = std::clamp(size, options.minSize, clampMax);
    result.targetSize[vertex] = size;
    result.allFinite = result.allFinite && std::isfinite(size);
  }

  result.targetSize = apply_size_gradation(vertices, faces, result.targetSize,
                                           options.gradationRatio,
                                           options.gradationPasses);
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    result.targetSize[vertex] =
        std::clamp(result.targetSize[vertex], options.minSize, clampMax);
    result.allFinite =
        result.allFinite && std::isfinite(result.targetSize[vertex]);
  }
  return result;
}

inline AdaptiveTargetSizeResult compute_adaptive_target_size(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const AdaptiveFeatureMap &featureMap,
    const AdaptiveTargetSizeOptions &options = {},
    const LocalThicknessOptions &thicknessOptions = {}) {
  AdaptiveTargetSizeInput input;
  input.salience =
      estimate_vertex_feature_salience(static_cast<int>(vertices.rows()), featureMap);
  input.featureDensity = featureMap.vertexDensity;
  input.curvature = estimate_principal_vertex_curvature(vertices, faces).curvature;
  input.thickness =
      estimate_local_thickness(vertices, faces, thicknessOptions).thickness;
  return compute_adaptive_target_size(vertices, faces, input, options);
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_ADAPTIVE_TARGET_SIZE_H
