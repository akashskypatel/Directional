// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_H
#define DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <functional>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdexcept>
#include <vector>

#include <Eigen/Core>

namespace directional::geometry {

enum class AdaptiveFeatureClass : int {
  Smooth = 0,
  Boundary = 1,
  Soft = 2,
  Hard = 3,
  NonManifold = 4,
};

struct AdaptiveFeatureMapOptions {
  double cadP95Degrees = 45.0;
  double cadP98Degrees = 60.0;
  double cadAbsoluteLowDegrees = 15.0;
  double cadAbsoluteHighDegrees = 60.0;
  double organicAbsoluteLowDegrees = 8.0;
  double organicAbsoluteHighDegrees = 35.0;
  double relativeHighPaddingDegrees = 1.0;
  double hardSeedStrength = 0.80;
  double growStrength = 0.55;
  double cornerAngleDegrees = 45.0;
  double densityRadius = 0.0;
  std::size_t exactQuantileEdgeLimit = 200000;
  std::size_t sampledQuantileEdgeCount = 32768;
  bool failOnNonManifold = false;
  std::set<std::pair<int, int>> userHardEdges;
  std::set<std::pair<int, int>> userSoftEdges;
};

struct AdaptiveFeatureEdge {
  std::pair<int, int> vertices = {-1, -1};
  std::vector<int> incidentFaces;
  int component = -1;
  int curve = -1;
  double angleRadians = 0.0;
  double strength = 0.0;
  double length = 0.0;
  AdaptiveFeatureClass edgeClass = AdaptiveFeatureClass::Smooth;
  bool userTagged = false;
};

struct AdaptiveFeatureComponentStats {
  std::size_t manifoldInteriorEdgeCount = 0;
  double p50Degrees = 0.0;
  double p75Degrees = 0.0;
  double p90Degrees = 0.0;
  double p95Degrees = 0.0;
  double p98Degrees = 0.0;
  double maxDegrees = 0.0;
  bool cadLike = false;
};

struct AdaptiveFeatureCurve {
  int id = -1;
  int component = -1;
  std::vector<int> edges;
  std::vector<int> vertices;
  bool closed = false;
  std::vector<int> corners;
  std::vector<int> junctions;
};

struct AdaptiveFeatureMap {
  std::vector<AdaptiveFeatureEdge> edges;
  std::vector<AdaptiveFeatureComponentStats> componentStats;
  std::vector<AdaptiveFeatureCurve> curves;
  Eigen::VectorXd vertexDensity;
  bool hasNonManifold = false;

  [[nodiscard]] int find_edge(const std::pair<int, int> &edge) const {
    const std::pair<int, int> canonical = canonical_edge(edge.first, edge.second);
    for (int index = 0; index < static_cast<int>(edges.size()); ++index) {
      if (edges[static_cast<std::size_t>(index)].vertices == canonical) {
        return index;
      }
    }
    return -1;
  }

  [[nodiscard]] double strength(const std::pair<int, int> &edge) const {
    const int index = find_edge(edge);
    return index < 0 ? 0.0 : edges[static_cast<std::size_t>(index)].strength;
  }

  [[nodiscard]] AdaptiveFeatureClass
  edge_class(const std::pair<int, int> &edge) const {
    const int index = find_edge(edge);
    return index < 0 ? AdaptiveFeatureClass::Smooth
                     : edges[static_cast<std::size_t>(index)].edgeClass;
  }

  [[nodiscard]] static std::pair<int, int> canonical_edge(const int a,
                                                          const int b) {
    return a <= b ? std::pair<int, int>{a, b} : std::pair<int, int>{b, a};
  }
};

namespace adaptive_feature_detail {

constexpr double pi = 3.141592653589793238462643383279502884;

inline double radians_to_degrees(const double radians) {
  return radians * 180.0 / pi;
}

inline double degrees_to_radians(const double degrees) {
  return degrees * pi / 180.0;
}

inline double smoothstep(const double value, const double low,
                         const double high) {
  if (high <= low) {
    return value >= high ? 1.0 : 0.0;
  }
  const double t = std::clamp((value - low) / (high - low), 0.0, 1.0);
  return t * t * (3.0 - 2.0 * t);
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
  const double norm = normal.norm();
  if (norm > 0.0) {
    normal /= norm;
  }
  return normal;
}

inline std::uint64_t edge_hash(const std::pair<int, int> &edge) {
  std::uint64_t hash = 1469598103934665603ULL;
  hash ^= static_cast<std::uint64_t>(edge.first);
  hash *= 1099511628211ULL;
  hash ^= static_cast<std::uint64_t>(edge.second);
  hash *= 1099511628211ULL;
  return hash;
}

inline double percentile(std::vector<double> values, const double q) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const std::size_t index = static_cast<std::size_t>(std::round(
      std::clamp(q, 0.0, 1.0) * static_cast<double>(values.size() - 1)));
  return values[index];
}

inline std::vector<double>
quantile_values_for_component(const std::vector<double> &values,
                              const std::vector<std::pair<int, int>> &keys,
                              const AdaptiveFeatureMapOptions &options) {
  if (values.size() <= options.exactQuantileEdgeLimit ||
      options.sampledQuantileEdgeCount == 0 ||
      values.size() <= options.sampledQuantileEdgeCount) {
    return values;
  }

  std::vector<std::size_t> order(values.size());
  std::iota(order.begin(), order.end(), 0U);
  std::sort(order.begin(), order.end(), [&](const std::size_t a,
                                            const std::size_t b) {
    const std::uint64_t hashA = edge_hash(keys[a]);
    const std::uint64_t hashB = edge_hash(keys[b]);
    if (hashA != hashB) {
      return hashA < hashB;
    }
    return keys[a] < keys[b];
  });

  std::vector<double> sampled;
  sampled.reserve(options.sampledQuantileEdgeCount);
  for (std::size_t i = 0; i < options.sampledQuantileEdgeCount; ++i) {
    sampled.push_back(values[order[i]]);
  }
  return sampled;
}

} // namespace adaptive_feature_detail

class AdaptiveFeatureMapBuilder {
public:
  [[nodiscard]] static AdaptiveFeatureMap
  build(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
        const AdaptiveFeatureMapOptions &options = {}) {
    if (vertices.cols() != 3 || faces.cols() != 3) {
      throw std::invalid_argument(
          "AdaptiveFeatureMap requires #V-by-3 vertices and #F-by-3 faces.");
    }

    AdaptiveFeatureMap map;
    map.vertexDensity = Eigen::VectorXd::Zero(vertices.rows());
    std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
    for (int face = 0; face < faces.rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int a = faces(face, corner);
        const int b = faces(face, (corner + 1) % 3);
        if (a < 0 || b < 0 || a >= vertices.rows() || b >= vertices.rows()) {
          continue;
        }
        edgeFaces[AdaptiveFeatureMap::canonical_edge(a, b)].push_back(face);
      }
    }

    const std::vector<Eigen::RowVector3d> normals =
        compute_face_normals(vertices, faces);
    std::vector<int> faceComponents = compute_face_components(faces, edgeFaces);
    int componentCount = 0;
    for (const int component : faceComponents) {
      componentCount = std::max(componentCount, component + 1);
    }
    map.componentStats.resize(static_cast<std::size_t>(componentCount));

    std::vector<std::vector<double>> componentAngles(
        static_cast<std::size_t>(componentCount));
    std::vector<std::vector<std::pair<int, int>>> componentKeys(
        static_cast<std::size_t>(componentCount));

    map.edges.reserve(edgeFaces.size());
    for (const auto &[edge, incidentFaces] : edgeFaces) {
      AdaptiveFeatureEdge featureEdge;
      featureEdge.vertices = edge;
      featureEdge.incidentFaces = incidentFaces;
      featureEdge.length =
          (adaptive_feature_detail::row3(vertices, edge.second) -
           adaptive_feature_detail::row3(vertices, edge.first))
              .norm();
      featureEdge.component =
          incidentFaces.empty() ? -1 : faceComponents[incidentFaces.front()];
      if (incidentFaces.size() == 1) {
        featureEdge.edgeClass = AdaptiveFeatureClass::Boundary;
        featureEdge.strength = 1.0;
      } else if (incidentFaces.size() != 2) {
        map.hasNonManifold = true;
        if (options.failOnNonManifold) {
          throw std::runtime_error("AdaptiveFeatureMap found a non-manifold edge.");
        }
        featureEdge.edgeClass = AdaptiveFeatureClass::NonManifold;
        featureEdge.strength = 1.0;
      } else {
        const Eigen::RowVector3d &n0 = normals[incidentFaces[0]];
        const Eigen::RowVector3d &n1 = normals[incidentFaces[1]];
        if (n0.squaredNorm() > 0.0 && n1.squaredNorm() > 0.0) {
          featureEdge.angleRadians =
              std::acos(std::clamp(n0.dot(n1), -1.0, 1.0));
        }
        if (featureEdge.component >= 0) {
          componentAngles[static_cast<std::size_t>(featureEdge.component)]
              .push_back(adaptive_feature_detail::radians_to_degrees(
                  featureEdge.angleRadians));
          componentKeys[static_cast<std::size_t>(featureEdge.component)]
              .push_back(edge);
        }
      }
      map.edges.push_back(std::move(featureEdge));
    }

    compute_component_stats(componentAngles, componentKeys, options, map);
    classify_edges(options, map);
    extract_curves(vertices, map, options);
    compute_density(vertices, map, options);
    return map;
  }

private:
  [[nodiscard]] static std::vector<Eigen::RowVector3d>
  compute_face_normals(const Eigen::MatrixXd &vertices,
                       const Eigen::MatrixXi &faces) {
    std::vector<Eigen::RowVector3d> normals(
        static_cast<std::size_t>(faces.rows()), Eigen::RowVector3d::Zero());
    for (int face = 0; face < faces.rows(); ++face) {
      normals[static_cast<std::size_t>(face)] =
          adaptive_feature_detail::face_normal(vertices, faces, face);
    }
    return normals;
  }

  [[nodiscard]] static std::vector<int> compute_face_components(
      const Eigen::MatrixXi &faces,
      const std::map<std::pair<int, int>, std::vector<int>> &edgeFaces) {
    std::vector<std::vector<int>> adjacency(static_cast<std::size_t>(faces.rows()));
    for (const auto &[edge, incidentFaces] : edgeFaces) {
      (void)edge;
      for (const int a : incidentFaces) {
        for (const int b : incidentFaces) {
          if (a != b && a >= 0 && b >= 0 && a < faces.rows() &&
              b < faces.rows()) {
            adjacency[static_cast<std::size_t>(a)].push_back(b);
          }
        }
      }
    }

    std::vector<int> components(static_cast<std::size_t>(faces.rows()), -1);
    int component = 0;
    for (int face = 0; face < faces.rows(); ++face) {
      if (components[static_cast<std::size_t>(face)] >= 0) {
        continue;
      }
      std::vector<int> stack{face};
      components[static_cast<std::size_t>(face)] = component;
      while (!stack.empty()) {
        const int current = stack.back();
        stack.pop_back();
        for (const int next : adjacency[static_cast<std::size_t>(current)]) {
          if (components[static_cast<std::size_t>(next)] < 0) {
            components[static_cast<std::size_t>(next)] = component;
            stack.push_back(next);
          }
        }
      }
      ++component;
    }
    return components;
  }

  static void compute_component_stats(
      const std::vector<std::vector<double>> &componentAngles,
      const std::vector<std::vector<std::pair<int, int>>> &componentKeys,
      const AdaptiveFeatureMapOptions &options, AdaptiveFeatureMap &map) {
    for (std::size_t component = 0; component < componentAngles.size();
         ++component) {
      const std::vector<double> values =
          adaptive_feature_detail::quantile_values_for_component(
              componentAngles[component], componentKeys[component], options);
      AdaptiveFeatureComponentStats &stats = map.componentStats[component];
      stats.manifoldInteriorEdgeCount = values.size();
      stats.p50Degrees = adaptive_feature_detail::percentile(values, 0.50);
      stats.p75Degrees = adaptive_feature_detail::percentile(values, 0.75);
      stats.p90Degrees = adaptive_feature_detail::percentile(values, 0.90);
      stats.p95Degrees = adaptive_feature_detail::percentile(values, 0.95);
      stats.p98Degrees = adaptive_feature_detail::percentile(values, 0.98);
      stats.maxDegrees = adaptive_feature_detail::percentile(values, 1.00);
      stats.cadLike = stats.p95Degrees > options.cadP95Degrees ||
                      stats.p98Degrees > options.cadP98Degrees;
    }
  }

  static void classify_edges(const AdaptiveFeatureMapOptions &options,
                             AdaptiveFeatureMap &map) {
    const std::set<std::pair<int, int>> hardTags =
        canonicalize_edges(options.userHardEdges);
    const std::set<std::pair<int, int>> softTags =
        canonicalize_edges(options.userSoftEdges);

    for (AdaptiveFeatureEdge &edge : map.edges) {
      if (hardTags.count(edge.vertices) != 0) {
        edge.userTagged = true;
        edge.strength = 1.0;
        edge.edgeClass = AdaptiveFeatureClass::Hard;
        continue;
      }
      if (softTags.count(edge.vertices) != 0) {
        edge.userTagged = true;
        edge.strength = std::max(edge.strength, options.growStrength);
        edge.edgeClass = AdaptiveFeatureClass::Soft;
        continue;
      }
      if (edge.edgeClass == AdaptiveFeatureClass::Boundary ||
          edge.edgeClass == AdaptiveFeatureClass::NonManifold) {
        continue;
      }
      if (edge.component < 0 ||
          edge.component >= static_cast<int>(map.componentStats.size())) {
        continue;
      }

      const AdaptiveFeatureComponentStats &stats =
          map.componentStats[static_cast<std::size_t>(edge.component)];
      const double relativeLow = stats.cadLike ? stats.p90Degrees : stats.p75Degrees;
      const double relativeHigh = std::max(
          stats.cadLike ? stats.p98Degrees : stats.p95Degrees,
          relativeLow + options.relativeHighPaddingDegrees);
      const double absoluteLow = stats.cadLike ? options.cadAbsoluteLowDegrees
                                               : options.organicAbsoluteLowDegrees;
      const double absoluteHigh = stats.cadLike ? options.cadAbsoluteHighDegrees
                                                : options.organicAbsoluteHighDegrees;
      const double angle = adaptive_feature_detail::radians_to_degrees(
          edge.angleRadians);
      const bool relativePlateau =
          stats.maxDegrees <= relativeLow + options.relativeHighPaddingDegrees;
      const double relativeScore =
          stats.manifoldInteriorEdgeCount < 4 ||
                  (relativePlateau && angle >= relativeLow)
              ? 1.0
              : adaptive_feature_detail::smoothstep(angle, relativeLow,
                                                    relativeHigh);
      edge.strength = std::sqrt(
          relativeScore *
          adaptive_feature_detail::smoothstep(angle, absoluteLow, absoluteHigh));
      if (edge.strength >= options.hardSeedStrength) {
        edge.edgeClass = AdaptiveFeatureClass::Hard;
      } else if (edge.strength >= options.growStrength) {
        edge.edgeClass = AdaptiveFeatureClass::Soft;
      } else {
        edge.edgeClass = AdaptiveFeatureClass::Smooth;
      }
    }
  }

  [[nodiscard]] static std::set<std::pair<int, int>>
  canonicalize_edges(const std::set<std::pair<int, int>> &edges) {
    std::set<std::pair<int, int>> canonical;
    for (const auto &edge : edges) {
      canonical.insert(AdaptiveFeatureMap::canonical_edge(edge.first, edge.second));
    }
    return canonical;
  }

  static void extract_curves(const Eigen::MatrixXd &vertices,
                             AdaptiveFeatureMap &map,
                             const AdaptiveFeatureMapOptions &options) {
    std::map<int, std::vector<int>> vertexEdges;
    for (int edgeIndex = 0; edgeIndex < static_cast<int>(map.edges.size());
         ++edgeIndex) {
      const AdaptiveFeatureEdge &edge = map.edges[static_cast<std::size_t>(edgeIndex)];
      if (!curve_candidate(edge, options)) {
        continue;
      }
      vertexEdges[edge.vertices.first].push_back(edgeIndex);
      vertexEdges[edge.vertices.second].push_back(edgeIndex);
    }

    std::vector<unsigned char> visited(map.edges.size(), 0);
    for (int seed = 0; seed < static_cast<int>(map.edges.size()); ++seed) {
      const AdaptiveFeatureEdge &seedEdge = map.edges[static_cast<std::size_t>(seed)];
      if (visited[static_cast<std::size_t>(seed)] || !curve_candidate(seedEdge, options) ||
          seedEdge.strength < options.hardSeedStrength) {
        continue;
      }

      AdaptiveFeatureCurve curve;
      curve.id = static_cast<int>(map.curves.size());
      curve.component = seedEdge.component;
      std::vector<int> stack{seed};
      visited[static_cast<std::size_t>(seed)] = 1;
      while (!stack.empty()) {
        const int current = stack.back();
        stack.pop_back();
        AdaptiveFeatureEdge &edge = map.edges[static_cast<std::size_t>(current)];
        edge.curve = curve.id;
        curve.edges.push_back(current);
        for (const int vertex : {edge.vertices.first, edge.vertices.second}) {
          curve.vertices.push_back(vertex);
          for (const int next : vertexEdges[vertex]) {
            const AdaptiveFeatureEdge &candidate =
                map.edges[static_cast<std::size_t>(next)];
            if (visited[static_cast<std::size_t>(next)] ||
                !compatible_curve_edge(seedEdge, candidate, options)) {
              continue;
            }
            visited[static_cast<std::size_t>(next)] = 1;
            stack.push_back(next);
          }
        }
      }
      finalize_curve(vertices, vertexEdges, map, options, curve);
      map.curves.push_back(std::move(curve));
    }
  }

  [[nodiscard]] static bool
  curve_candidate(const AdaptiveFeatureEdge &edge,
                  const AdaptiveFeatureMapOptions &options) {
    return edge.edgeClass == AdaptiveFeatureClass::Boundary ||
           edge.edgeClass == AdaptiveFeatureClass::NonManifold ||
           edge.strength >= options.growStrength;
  }

  [[nodiscard]] static bool compatible_curve_edge(
      const AdaptiveFeatureEdge &seed, const AdaptiveFeatureEdge &candidate,
      const AdaptiveFeatureMapOptions &options) {
    if (!curve_candidate(candidate, options) ||
        candidate.component != seed.component) {
      return false;
    }
    if (seed.edgeClass == AdaptiveFeatureClass::Boundary ||
        candidate.edgeClass == AdaptiveFeatureClass::Boundary) {
      return seed.edgeClass == candidate.edgeClass;
    }
    return true;
  }

  static void finalize_curve(
      const Eigen::MatrixXd &vertices, const std::map<int, std::vector<int>> &vertexEdges,
      const AdaptiveFeatureMap &map, const AdaptiveFeatureMapOptions &options,
      AdaptiveFeatureCurve &curve) {
    std::sort(curve.vertices.begin(), curve.vertices.end());
    curve.vertices.erase(std::unique(curve.vertices.begin(), curve.vertices.end()),
                         curve.vertices.end());

    int degreeOne = 0;
    for (const int vertex : curve.vertices) {
      int degree = 0;
      const auto found = vertexEdges.find(vertex);
      if (found != vertexEdges.end()) {
        for (const int edge : found->second) {
          if (map.edges[static_cast<std::size_t>(edge)].curve == curve.id ||
              std::find(curve.edges.begin(), curve.edges.end(), edge) !=
                  curve.edges.end()) {
            ++degree;
          }
        }
      }
      if (degree == 1) {
        ++degreeOne;
      } else if (degree > 2) {
        curve.junctions.push_back(vertex);
      } else if (degree == 2 && is_corner(vertices, map, curve, vertex, options)) {
        curve.corners.push_back(vertex);
      }
    }
    curve.closed = degreeOne == 0 && curve.junctions.empty() &&
                   !curve.edges.empty();
  }

  [[nodiscard]] static bool
  is_corner(const Eigen::MatrixXd &vertices, const AdaptiveFeatureMap &map,
            const AdaptiveFeatureCurve &curve, const int vertex,
            const AdaptiveFeatureMapOptions &options) {
    std::vector<Eigen::RowVector3d> directions;
    for (const int edgeIndex : curve.edges) {
      const AdaptiveFeatureEdge &edge = map.edges[static_cast<std::size_t>(edgeIndex)];
      int other = -1;
      if (edge.vertices.first == vertex) {
        other = edge.vertices.second;
      } else if (edge.vertices.second == vertex) {
        other = edge.vertices.first;
      }
      if (other >= 0) {
        Eigen::RowVector3d direction =
            adaptive_feature_detail::row3(vertices, other) -
            adaptive_feature_detail::row3(vertices, vertex);
        const double norm = direction.norm();
        if (norm > 0.0) {
          directions.push_back(direction / norm);
        }
      }
    }
    if (directions.size() != 2) {
      return false;
    }
    const double angle = std::acos(std::clamp(
        std::abs(directions[0].dot(directions[1])), -1.0, 1.0));
    return adaptive_feature_detail::radians_to_degrees(angle) >=
           options.cornerAngleDegrees;
  }

  static void compute_density(const Eigen::MatrixXd &vertices,
                              AdaptiveFeatureMap &map,
                              const AdaptiveFeatureMapOptions &options) {
    double radius = options.densityRadius;
    if (!(radius > 0.0)) {
      double totalLength = 0.0;
      int count = 0;
      for (const AdaptiveFeatureEdge &edge : map.edges) {
        if (curve_candidate(edge, options)) {
          totalLength += edge.length;
          ++count;
        }
      }
      radius = count > 0 ? 2.0 * totalLength / static_cast<double>(count) : 0.0;
    }
    if (!(radius > 0.0)) {
      return;
    }

    const std::vector<std::vector<std::pair<int, double>>> graph =
        vertex_graph(vertices, map.edges);
    for (const AdaptiveFeatureEdge &edge : map.edges) {
      if (!curve_candidate(edge, options) || edge.length <= 0.0) {
        continue;
      }
      accumulate_density_from_vertex(edge.vertices.first, edge.strength,
                                     0.5 * edge.length, radius, graph, map);
      accumulate_density_from_vertex(edge.vertices.second, edge.strength,
                                     0.5 * edge.length, radius, graph, map);
    }
  }

  [[nodiscard]] static std::vector<std::vector<std::pair<int, double>>>
  vertex_graph(const Eigen::MatrixXd &vertices,
               const std::vector<AdaptiveFeatureEdge> &edges) {
    std::vector<std::vector<std::pair<int, double>>> graph(
        static_cast<std::size_t>(vertices.rows()));
    for (const AdaptiveFeatureEdge &edge : edges) {
      const double length =
          (adaptive_feature_detail::row3(vertices, edge.vertices.second) -
           adaptive_feature_detail::row3(vertices, edge.vertices.first))
              .norm();
      graph[static_cast<std::size_t>(edge.vertices.first)].push_back(
          {edge.vertices.second, length});
      graph[static_cast<std::size_t>(edge.vertices.second)].push_back(
          {edge.vertices.first, length});
    }
    return graph;
  }

  static void accumulate_density_from_vertex(
      const int source, const double strength, const double mass,
      const double radius,
      const std::vector<std::vector<std::pair<int, double>>> &graph,
      AdaptiveFeatureMap &map) {
    using QueueEntry = std::pair<double, int>;
    std::priority_queue<QueueEntry, std::vector<QueueEntry>,
                        std::greater<QueueEntry>>
        queue;
    std::vector<double> distance(static_cast<std::size_t>(map.vertexDensity.rows()),
                                 std::numeric_limits<double>::infinity());
    distance[static_cast<std::size_t>(source)] = 0.0;
    queue.push({0.0, source});
    while (!queue.empty()) {
      const auto [currentDistance, vertex] = queue.top();
      queue.pop();
      if (currentDistance != distance[static_cast<std::size_t>(vertex)] ||
          currentDistance >= radius) {
        continue;
      }
      const double t = currentDistance / radius;
      const double kernel = (1.0 - t * t) * (1.0 - t * t);
      map.vertexDensity(vertex) += strength * mass * kernel;
      for (const auto &[next, length] : graph[static_cast<std::size_t>(vertex)]) {
        const double nextDistance = currentDistance + length;
        if (nextDistance < radius &&
            nextDistance < distance[static_cast<std::size_t>(next)]) {
          distance[static_cast<std::size_t>(next)] = nextDistance;
          queue.push({nextDistance, next});
        }
      }
    }
  }
};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_ADAPTIVE_FEATURE_MAP_H
