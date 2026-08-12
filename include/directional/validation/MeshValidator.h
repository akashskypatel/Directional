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
  ChangedBoundaryLoop,
  MissingProvenance,
  MissingBoundaryAuthority,
  MissingSourceAuthority,
  InvalidProvenance,
  SourceComponentMismatch,
  SourceSheetMismatch,
  SourcePositionMismatch,
  LocalSheetMismatch,
  ChangedEulerCharacteristic,
  MissingFeatureRail
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
  bool topologyOnly = false;
  bool requireVertexProvenanceForGeometry = false;
  bool requireAuthoritativeBoundary = false;
};

std::pair<int, int> canonical_edge(const int a, const int b);

std::string_view
mesh_validation_failure_name(const MeshValidationFailureCode code);

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
    std::vector<std::vector<int>> validFaceVertices;

    for (int face = 0; face < faces.rows(); ++face) {
      std::vector<int> faceVertices;
      bool faceIndicesValid = true;
      for (int corner = 0; corner < faces.cols(); ++corner) {
        const int vertex = faces(face, corner);
        if (vertex == -1) {
          continue;
        }
        if (vertex < 0 || vertex >= vertices.rows()) {
          result.fail({MeshValidationFailureCode::MissingVertex, vertex, -1,
                       -1, face});
          faceIndicesValid = false;
          continue;
        }
        faceVertices.push_back(vertex);
        if (vertex >= 0 && vertex < vertices.rows()) {
          vertexFaceNeighbors[static_cast<std::size_t>(vertex)].insert(face);
        }
      }
      if (faceIndicesValid && faceVertices.size() >= 3) {
        validFaceVertices.push_back(faceVertices);
      } else {
        validFaceVertices.push_back({});
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
    if (options.requireAuthoritativeBoundary && authoritativeBoundary.empty()) {
      result.fail({MeshValidationFailureCode::MissingBoundaryAuthority});
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
    if (!options.topologyOnly) {
      validate_face_to_face_intersections(vertices, validFaceVertices,
                                          options, result);
      validate_geometric_t_junctions(vertices, edgeIncidence, options, result);
    }
    return result;
  }

  [[nodiscard]] static MeshValidationResult
  validate_topology_only(const Eigen::MatrixXd &vertices,
                         const Eigen::MatrixXi &faces,
                         MeshValidatorOptions options = {}) {
    options.topologyOnly = true;
    return validate_surface_mesh(vertices, faces, options);
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

  [[nodiscard]] static bool point_in_triangle3(
      const Eigen::Vector3d &point, const Eigen::Vector3d &a,
      const Eigen::Vector3d &b, const Eigen::Vector3d &c,
      const double tolerance) {
    const Eigen::Vector3d v0 = b - a;
    const Eigen::Vector3d v1 = c - a;
    const Eigen::Vector3d v2 = point - a;
    const Eigen::Vector3d normal = v0.cross(v1);
    const double normalNorm = normal.norm();
    const double scale = std::max({v0.norm(), v1.norm(), (c - b).norm(), tolerance});
    if (normalNorm <= tolerance * scale ||
        std::abs(normal.dot(v2)) > tolerance * normalNorm * scale) {
      return false;
    }
    const double d00 = v0.dot(v0);
    const double d01 = v0.dot(v1);
    const double d11 = v1.dot(v1);
    const double d20 = v2.dot(v0);
    const double d21 = v2.dot(v1);
    const double denominator = d00 * d11 - d01 * d01;
    if (std::abs(denominator) <= tolerance * tolerance) {
      return false;
    }
    const double v = (d11 * d20 - d01 * d21) / denominator;
    const double w = (d00 * d21 - d01 * d20) / denominator;
    const double u = 1.0 - v - w;
    return u >= -tolerance && v >= -tolerance && w >= -tolerance &&
           u <= 1.0 + tolerance && v <= 1.0 + tolerance &&
           w <= 1.0 + tolerance;
  }

  [[nodiscard]] static bool segment_intersects_triangle(
      const Eigen::Vector3d &p0, const Eigen::Vector3d &p1,
      const Eigen::Vector3d &a, const Eigen::Vector3d &b,
      const Eigen::Vector3d &c, const double tolerance) {
    const Eigen::Vector3d direction = p1 - p0;
    const Eigen::Vector3d normal = (b - a).cross(c - a);
    const double denominator = normal.dot(direction);
    if (std::abs(denominator) <= tolerance * normal.norm() *
                                      std::max(direction.norm(), tolerance)) {
      return false;
    }
    const double t = normal.dot(a - p0) / denominator;
    if (t < -tolerance || t > 1.0 + tolerance) {
      return false;
    }
    const Eigen::Vector3d point = p0 + t * direction;
    return point_in_triangle3(point, a, b, c, tolerance);
  }

  [[nodiscard]] static bool triangles_intersect3(
      const Eigen::MatrixXd &vertices, const std::array<int, 3> &first,
      const std::array<int, 3> &second, const double tolerance) {
    const Eigen::Vector3d a0 = vertices.row(first[0]).transpose();
    const Eigen::Vector3d a1 = vertices.row(first[1]).transpose();
    const Eigen::Vector3d a2 = vertices.row(first[2]).transpose();
    const Eigen::Vector3d b0 = vertices.row(second[0]).transpose();
    const Eigen::Vector3d b1 = vertices.row(second[1]).transpose();
    const Eigen::Vector3d b2 = vertices.row(second[2]).transpose();
    const std::array<Eigen::Vector3d, 3> a = {a0, a1, a2};
    const std::array<Eigen::Vector3d, 3> b = {b0, b1, b2};
    for (int i = 0; i < 3; ++i) {
      if (segment_intersects_triangle(a[i], a[(i + 1) % 3], b0, b1, b2,
                                      tolerance)) {
        return true;
      }
      if (segment_intersects_triangle(b[i], b[(i + 1) % 3], a0, a1, a2,
                                      tolerance)) {
        return true;
      }
    }
    return point_in_triangle3(a0, b0, b1, b2, tolerance) ||
           point_in_triangle3(b0, a0, a1, a2, tolerance);
  }

  [[nodiscard]] static bool faces_share_vertex(const std::vector<int> &first,
                                               const std::vector<int> &second) {
    for (const int a : first) {
      for (const int b : second) {
        if (a == b) {
          return true;
        }
      }
    }
    return false;
  }

  static void validate_face_to_face_intersections(
      const Eigen::MatrixXd &vertices,
      const std::vector<std::vector<int>> &validFaceVertices,
      const MeshValidatorOptions &options, MeshValidationResult &result) {
    (void)options;
    for (std::size_t firstFace = 0; firstFace < validFaceVertices.size();
         ++firstFace) {
      const std::vector<int> &first = validFaceVertices[firstFace];
      if (first.size() < 3) {
        continue;
      }
      for (std::size_t secondFace = firstFace + 1;
           secondFace < validFaceVertices.size(); ++secondFace) {
        const std::vector<int> &second = validFaceVertices[secondFace];
        if (second.size() < 3 || faces_share_vertex(first, second)) {
          continue;
        }
        for (std::size_t i = 1; i + 1 < first.size(); ++i) {
          const std::array<int, 3> firstTriangle = {
              first[0], first[i], first[i + 1]};
          for (std::size_t j = 1; j + 1 < second.size(); ++j) {
            const std::array<int, 3> secondTriangle = {
                second[0], second[j], second[j + 1]};
            if (triangles_intersect3(vertices, firstTriangle, secondTriangle,
                                     options.geometricTolerance)) {
              result.fail({MeshValidationFailureCode::SelfIntersectingFace,
                           -1, -1, -1,
                           static_cast<int>(secondFace)});
              return;
            }
          }
        }
      }
    }
  }

  [[nodiscard]] static bool same_source_face(
      const int vertex, const int a, const int b,
      const MeshValidatorOptions &options) {
    if (options.vertexProvenance.empty()) {
      return !options.requireVertexProvenanceForGeometry;
    }
    const std::size_t maxIndex =
        static_cast<std::size_t>(std::max({vertex, a, b}));
    if (maxIndex >= options.vertexProvenance.size()) {
      return false;
    }
    const geometry::SurfacePoint &p =
        options.vertexProvenance[static_cast<std::size_t>(vertex)];
    const geometry::SurfacePoint &pa =
        options.vertexProvenance[static_cast<std::size_t>(a)];
    const geometry::SurfacePoint &pb =
        options.vertexProvenance[static_cast<std::size_t>(b)];
    if (!p.valid() || !pa.valid() || !pb.valid()) {
      return false;
    }
    // Generic validation has no typed cross-chart authority. Raw projection
    // mirrors may be exported for diagnostics, but they never prove that
    // different source faces belong to one semantic sheet.
    return p.face == pa.face && p.face == pb.face;
  }

  static void validate_geometric_t_junctions(
      const Eigen::MatrixXd &vertices,
      const std::map<std::pair<int, int>, std::vector<int>> &edgeIncidence,
      const MeshValidatorOptions &options, MeshValidationResult &result) {
    const double tolerance = options.geometricTolerance;
    if (options.requireVertexProvenanceForGeometry &&
        options.vertexProvenance.size() <
            static_cast<std::size_t>(vertices.rows())) {
      result.fail({MeshValidationFailureCode::MissingProvenance});
      return;
    }

    std::vector<int> sortedByX(static_cast<std::size_t>(vertices.rows()));
    for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
      sortedByX[static_cast<std::size_t>(vertex)] = vertex;
    }
    std::sort(sortedByX.begin(), sortedByX.end(),
              [&](const int lhs, const int rhs) {
                return vertices(lhs, 0) < vertices(rhs, 0);
              });

    for (const auto &[edge, incidentFaces] : edgeIncidence) {
      const int aIndex = edge.first;
      const int bIndex = edge.second;
      const Eigen::Vector3d a = vertices.row(aIndex).transpose();
      const Eigen::Vector3d b = vertices.row(bIndex).transpose();
      const Eigen::Vector3d ab = b - a;
      const double lengthSquared = ab.squaredNorm();
      if (lengthSquared <= tolerance * tolerance) {
        continue;
      }
      const double minX = std::min(a.x(), b.x()) - tolerance;
      const double maxX = std::max(a.x(), b.x()) + tolerance;
      const auto lower = std::lower_bound(
          sortedByX.begin(), sortedByX.end(), minX,
          [&](const int vertex, const double value) {
            return vertices(vertex, 0) < value;
          });
      for (auto it = lower; it != sortedByX.end(); ++it) {
        const int vertex = *it;
        if (vertices(vertex, 0) > maxX) {
          break;
        }
        if (vertex == aIndex || vertex == bIndex) {
          continue;
        }
        if (!same_source_face(vertex, aIndex, bIndex, options)) {
          continue;
        }
        const Eigen::Vector3d p = vertices.row(vertex).transpose();
        if (p.y() < std::min(a.y(), b.y()) - tolerance ||
            p.y() > std::max(a.y(), b.y()) + tolerance ||
            p.z() < std::min(a.z(), b.z()) - tolerance ||
            p.z() > std::max(a.z(), b.z()) + tolerance) {
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
