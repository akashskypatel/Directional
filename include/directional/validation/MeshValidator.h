// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VALIDATION_MESH_VALIDATOR_H
#define DIRECTIONAL_VALIDATION_MESH_VALIDATOR_H

#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <set>
#include <string_view>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <directional/geometry/SurfacePoint.h>

namespace directional::validation {

enum class MeshValidationFailureCode {
  None,
  MissingVertex,
  OneSidedInteriorEdge,
  ThreeSidedInteriorEdge,
  WrongBoundaryEdge,
  GeometricVertexOnUnsplitEdge,
  DuplicateFace,
  BowTieVertex,
  FlippedFace,
  ZeroAreaFace,
  SelfIntersectingFace,
  ComponentMerge,
  ChangedBoundaryLoop
};

struct MeshValidationIssue {
  MeshValidationFailureCode code = MeshValidationFailureCode::None;
  int vertex = -1;
  int edgeFirst = -1;
  int edgeSecond = -1;
  int face = -1;
};

struct MeshValidationResult {
  bool accepted = true;
  std::vector<MeshValidationIssue> issues;

  void fail(const MeshValidationIssue &issue) {
    accepted = false;
    issues.push_back(issue);
  }
};

struct MeshValidatorOptions {
  double geometricTolerance = 1.0e-9;
  bool requireConsistentOrientation = false;
  std::size_t expectedConnectedComponents = 0;
  std::set<std::pair<int, int>> authoritativeBoundaryEdges;
  std::vector<int> authoritativeBoundaryLoop;
  std::vector<geometry::SurfacePoint> vertexProvenance;
};

inline std::pair<int, int> canonical_edge(const int a, const int b) {
  return a <= b ? std::pair<int, int>{a, b} : std::pair<int, int>{b, a};
}

inline std::string_view
mesh_validation_failure_name(const MeshValidationFailureCode code) {
  switch (code) {
  case MeshValidationFailureCode::None:
    return "None";
  case MeshValidationFailureCode::MissingVertex:
    return "MissingVertex";
  case MeshValidationFailureCode::OneSidedInteriorEdge:
    return "OneSidedInteriorEdge";
  case MeshValidationFailureCode::ThreeSidedInteriorEdge:
    return "ThreeSidedInteriorEdge";
  case MeshValidationFailureCode::WrongBoundaryEdge:
    return "WrongBoundaryEdge";
  case MeshValidationFailureCode::GeometricVertexOnUnsplitEdge:
    return "GeometricVertexOnUnsplitEdge";
  case MeshValidationFailureCode::DuplicateFace:
    return "DuplicateFace";
  case MeshValidationFailureCode::BowTieVertex:
    return "BowTieVertex";
  case MeshValidationFailureCode::FlippedFace:
    return "FlippedFace";
  case MeshValidationFailureCode::ZeroAreaFace:
    return "ZeroAreaFace";
  case MeshValidationFailureCode::SelfIntersectingFace:
    return "SelfIntersectingFace";
  case MeshValidationFailureCode::ComponentMerge:
    return "ComponentMerge";
  case MeshValidationFailureCode::ChangedBoundaryLoop:
    return "ChangedBoundaryLoop";
  }
  return "Unknown";
}

class MeshValidator {
public:
  [[nodiscard]] static MeshValidationResult
  validate_surface_mesh(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const MeshValidatorOptions &options = {}) {
    MeshValidationResult result;
    if (vertices.cols() != 3 || faces.cols() < 3) {
      result.fail({MeshValidationFailureCode::MissingVertex});
      return result;
    }

    std::map<std::pair<int, int>, std::vector<int>> edgeIncidence;
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>>
        edgeOrientation;
    std::set<std::vector<int>> uniqueFaces;
    std::vector<std::set<int>> vertexFaceNeighbors(
        static_cast<std::size_t>(vertices.rows()));

    for (int face = 0; face < faces.rows(); ++face) {
      std::vector<int> faceVertices;
      for (int corner = 0; corner < faces.cols(); ++corner) {
        const int vertex = faces(face, corner);
        if (vertex == -1) {
          continue;
        }
        if (vertex < 0 || vertex >= vertices.rows()) {
          result.fail({MeshValidationFailureCode::MissingVertex, vertex, -1,
                       -1, face});
          continue;
        }
        faceVertices.push_back(vertex);
        if (vertex >= 0 && vertex < vertices.rows()) {
          vertexFaceNeighbors[static_cast<std::size_t>(vertex)].insert(face);
        }
      }

      std::vector<int> sortedFace = faceVertices;
      std::sort(sortedFace.begin(), sortedFace.end());
      if (!uniqueFaces.insert(sortedFace).second) {
        result.fail({MeshValidationFailureCode::DuplicateFace, -1, -1, -1,
                     face});
      }

      if (has_repeated_vertex(faceVertices)) {
        result.fail(
            {MeshValidationFailureCode::ZeroAreaFace, -1, -1, -1, face});
      }
      if (face_area(vertices, faceVertices) <=
          options.geometricTolerance * options.geometricTolerance) {
        result.fail(
            {MeshValidationFailureCode::ZeroAreaFace, -1, -1, -1, face});
      }
      if (quad_self_intersects(vertices, faceVertices,
                               options.geometricTolerance)) {
        result.fail({MeshValidationFailureCode::SelfIntersectingFace, -1, -1,
                     -1, face});
      }

      for (std::size_t i = 0; i < faceVertices.size(); ++i) {
        const int a = faceVertices[i];
        const int b = faceVertices[(i + 1) % faceVertices.size()];
        if (a >= 0 && b >= 0 && a < vertices.rows() && b < vertices.rows()) {
          const std::pair<int, int> edge = canonical_edge(a, b);
          edgeIncidence[edge].push_back(face);
          edgeOrientation[edge].push_back({a, b});
        }
      }
    }

    std::set<std::pair<int, int>> authoritativeBoundary =
        options.authoritativeBoundaryEdges;
    if (!options.authoritativeBoundaryLoop.empty()) {
      for (std::size_t index = 0; index < options.authoritativeBoundaryLoop.size();
           ++index) {
        authoritativeBoundary.insert(canonical_edge(
            options.authoritativeBoundaryLoop[index],
            options.authoritativeBoundaryLoop[(index + 1) %
                                              options.authoritativeBoundaryLoop.size()]));
      }
    }

    for (const auto &[edge, incidentFaces] : edgeIncidence) {
      const bool isAuthoritativeBoundary =
          authoritativeBoundary.count(edge) != 0;
      if (isAuthoritativeBoundary) {
        if (incidentFaces.size() != 1) {
          result.fail({MeshValidationFailureCode::WrongBoundaryEdge, -1,
                       edge.first, edge.second, -1});
        }
      } else if (!options.authoritativeBoundaryEdges.empty()) {
        if (incidentFaces.size() == 1) {
          result.fail({MeshValidationFailureCode::OneSidedInteriorEdge, -1,
                       edge.first, edge.second, incidentFaces.front()});
        } else if (incidentFaces.size() != 2) {
          result.fail({MeshValidationFailureCode::ThreeSidedInteriorEdge, -1,
                       edge.first, edge.second, -1});
        }
      } else if (incidentFaces.size() > 2) {
        result.fail({MeshValidationFailureCode::ThreeSidedInteriorEdge, -1,
                     edge.first, edge.second, -1});
      }

      const auto orientation = edgeOrientation.find(edge);
      if (options.requireConsistentOrientation && incidentFaces.size() == 2 &&
          orientation != edgeOrientation.end() && orientation->second.size() == 2 &&
          orientation->second[0] == orientation->second[1]) {
        result.fail({MeshValidationFailureCode::FlippedFace, -1, edge.first,
                     edge.second, incidentFaces.back()});
      }
    }

    for (const auto &edge : authoritativeBoundary) {
      if (edgeIncidence.count(edge) == 0) {
        result.fail({MeshValidationFailureCode::ChangedBoundaryLoop, -1,
                     edge.first, edge.second, -1});
      }
    }

    validate_bow_tie_vertices(vertexFaceNeighbors, edgeIncidence, result);
    validate_component_count(faces.rows(), edgeIncidence, options, result);
    validate_geometric_t_junctions(vertices, edgeIncidence, options, result);
    return result;
  }

private:
  [[nodiscard]] static bool has_repeated_vertex(const std::vector<int> &face) {
    std::set<int> seen;
    for (const int vertex : face) {
      if (!seen.insert(vertex).second) {
        return true;
      }
    }
    return false;
  }

  [[nodiscard]] static double face_area(const Eigen::MatrixXd &vertices,
                                        const std::vector<int> &face) {
    if (face.size() < 3) {
      return 0.0;
    }
    const Eigen::Vector3d origin = vertices.row(face[0]).transpose();
    double area = 0.0;
    for (std::size_t i = 1; i + 1 < face.size(); ++i) {
      const Eigen::Vector3d a = vertices.row(face[i]).transpose() - origin;
      const Eigen::Vector3d b = vertices.row(face[i + 1]).transpose() - origin;
      area += 0.5 * a.cross(b).norm();
    }
    return area;
  }

  [[nodiscard]] static int dominant_axis(const Eigen::Vector3d &normal) {
    Eigen::Vector3d absNormal = normal.cwiseAbs();
    int axis = 0;
    if (absNormal(1) > absNormal(axis)) {
      axis = 1;
    }
    if (absNormal(2) > absNormal(axis)) {
      axis = 2;
    }
    return axis;
  }

  [[nodiscard]] static Eigen::Vector2d project2(const Eigen::Vector3d &point,
                                                const int dropAxis) {
    if (dropAxis == 0) {
      return {point.y(), point.z()};
    }
    if (dropAxis == 1) {
      return {point.x(), point.z()};
    }
    return {point.x(), point.y()};
  }

  [[nodiscard]] static double orient2(const Eigen::Vector2d &a,
                                      const Eigen::Vector2d &b,
                                      const Eigen::Vector2d &c) {
    return (b.x() - a.x()) * (c.y() - a.y()) -
           (b.y() - a.y()) * (c.x() - a.x());
  }

  [[nodiscard]] static bool segments_intersect_strict(
      const Eigen::Vector2d &a, const Eigen::Vector2d &b,
      const Eigen::Vector2d &c, const Eigen::Vector2d &d,
      const double tolerance) {
    const double o1 = orient2(a, b, c);
    const double o2 = orient2(a, b, d);
    const double o3 = orient2(c, d, a);
    const double o4 = orient2(c, d, b);
    return ((o1 > tolerance && o2 < -tolerance) ||
            (o1 < -tolerance && o2 > tolerance)) &&
           ((o3 > tolerance && o4 < -tolerance) ||
            (o3 < -tolerance && o4 > tolerance));
  }

  [[nodiscard]] static bool
  quad_self_intersects(const Eigen::MatrixXd &vertices,
                       const std::vector<int> &face, const double tolerance) {
    if (face.size() != 4) {
      return false;
    }
    const Eigen::Vector3d p0 = vertices.row(face[0]).transpose();
    const Eigen::Vector3d p1 = vertices.row(face[1]).transpose();
    const Eigen::Vector3d p2 = vertices.row(face[2]).transpose();
    const Eigen::Vector3d p3 = vertices.row(face[3]).transpose();
    const Eigen::Vector3d normal = (p1 - p0).cross(p2 - p0);
    const int axis = dominant_axis(normal);
    return segments_intersect_strict(project2(p0, axis), project2(p1, axis),
                                     project2(p2, axis), project2(p3, axis),
                                     tolerance) ||
           segments_intersect_strict(project2(p1, axis), project2(p2, axis),
                                     project2(p3, axis), project2(p0, axis),
                                     tolerance);
  }

  [[nodiscard]] static bool same_source_sheet(
      const int vertex, const int a, const int b,
      const MeshValidatorOptions &options) {
    if (options.vertexProvenance.empty()) {
      return true;
    }
    const std::size_t maxIndex =
        static_cast<std::size_t>(std::max({vertex, a, b}));
    if (maxIndex >= options.vertexProvenance.size()) {
      return true;
    }
    const int face = options.vertexProvenance[static_cast<std::size_t>(vertex)].face;
    return face >= 0 &&
           face == options.vertexProvenance[static_cast<std::size_t>(a)].face &&
           face == options.vertexProvenance[static_cast<std::size_t>(b)].face;
  }

  static void validate_geometric_t_junctions(
      const Eigen::MatrixXd &vertices,
      const std::map<std::pair<int, int>, std::vector<int>> &edgeIncidence,
      const MeshValidatorOptions &options, MeshValidationResult &result) {
    const double tolerance = options.geometricTolerance;
    for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
      const Eigen::Vector3d p = vertices.row(vertex).transpose();
      for (const auto &[edge, incidentFaces] : edgeIncidence) {
        const int aIndex = edge.first;
        const int bIndex = edge.second;
        if (vertex == aIndex || vertex == bIndex) {
          continue;
        }
        if (!same_source_sheet(vertex, aIndex, bIndex, options)) {
          continue;
        }
        const Eigen::Vector3d a = vertices.row(aIndex).transpose();
        const Eigen::Vector3d b = vertices.row(bIndex).transpose();
        const Eigen::Vector3d ab = b - a;
        const double lengthSquared = ab.squaredNorm();
        if (lengthSquared <= tolerance * tolerance) {
          continue;
        }
        const double t = (p - a).dot(ab) / lengthSquared;
        if (t <= tolerance || t >= 1.0 - tolerance) {
          continue;
        }
        const Eigen::Vector3d closest = a + t * ab;
        if ((closest - p).norm() <= tolerance) {
          result.fail({MeshValidationFailureCode::GeometricVertexOnUnsplitEdge,
                       vertex, aIndex, bIndex,
                       incidentFaces.empty() ? -1 : incidentFaces.front()});
        }
      }
    }
  }

  static void validate_bow_tie_vertices(
      const std::vector<std::set<int>> &vertexFaceNeighbors,
      const std::map<std::pair<int, int>, std::vector<int>> &edgeIncidence,
      MeshValidationResult &result) {
    for (std::size_t vertex = 0; vertex < vertexFaceNeighbors.size();
         ++vertex) {
      const std::set<int> &incidentFaces = vertexFaceNeighbors[vertex];
      if (incidentFaces.size() <= 1) {
        continue;
      }
      std::map<int, std::set<int>> adjacency;
      for (const int face : incidentFaces) {
        adjacency[face];
      }
      for (const auto &[edge, faces] : edgeIncidence) {
        if (edge.first != static_cast<int>(vertex) &&
            edge.second != static_cast<int>(vertex)) {
          continue;
        }
        for (const int a : faces) {
          for (const int b : faces) {
            if (a != b && incidentFaces.count(a) && incidentFaces.count(b)) {
              adjacency[a].insert(b);
            }
          }
        }
      }
      std::set<int> visited;
      int components = 0;
      for (const auto &[face, neighbors] : adjacency) {
        if (visited.count(face)) {
          continue;
        }
        ++components;
        std::vector<int> stack{face};
        visited.insert(face);
        while (!stack.empty()) {
          const int current = stack.back();
          stack.pop_back();
          for (const int next : adjacency[current]) {
            if (visited.insert(next).second) {
              stack.push_back(next);
            }
          }
        }
      }
      if (components > 1) {
        result.fail({MeshValidationFailureCode::BowTieVertex,
                     static_cast<int>(vertex), -1, -1, -1});
      }
    }
  }

  static void validate_component_count(
      const int faceCount,
      const std::map<std::pair<int, int>, std::vector<int>> &edgeIncidence,
      const MeshValidatorOptions &options, MeshValidationResult &result) {
    if (options.expectedConnectedComponents == 0 || faceCount == 0) {
      return;
    }
    std::vector<std::set<int>> adjacency(static_cast<std::size_t>(faceCount));
    for (const auto &[edge, faces] : edgeIncidence) {
      (void)edge;
      for (const int a : faces) {
        for (const int b : faces) {
          if (a != b && a >= 0 && b >= 0 && a < faceCount && b < faceCount) {
            adjacency[static_cast<std::size_t>(a)].insert(b);
          }
        }
      }
    }
    std::vector<unsigned char> visited(static_cast<std::size_t>(faceCount), 0);
    std::size_t components = 0;
    for (int face = 0; face < faceCount; ++face) {
      if (visited[static_cast<std::size_t>(face)]) {
        continue;
      }
      ++components;
      std::vector<int> stack{face};
      visited[static_cast<std::size_t>(face)] = 1;
      while (!stack.empty()) {
        const int current = stack.back();
        stack.pop_back();
        for (const int next : adjacency[static_cast<std::size_t>(current)]) {
          if (!visited[static_cast<std::size_t>(next)]) {
            visited[static_cast<std::size_t>(next)] = 1;
            stack.push_back(next);
          }
        }
      }
    }
    if (components != options.expectedConnectedComponents) {
      result.fail({MeshValidationFailureCode::ComponentMerge});
    }
  }
};

class SurfaceCellComplexValidator {
public:
  [[nodiscard]] static MeshValidationResult
  validate(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
           const MeshValidatorOptions &options = {}) {
    return MeshValidator::validate_surface_mesh(vertices, faces, options);
  }
};

} // namespace directional::validation

#endif // DIRECTIONAL_VALIDATION_MESH_VALIDATOR_H
