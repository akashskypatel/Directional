// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SOURCE_CHART_TRANSITIONS_H
#define DIRECTIONAL_GEOMETRY_SOURCE_CHART_TRANSITIONS_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/geometry/SurfaceCellOwnership.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/geometry/SurfacePointSupport.h>

namespace directional::geometry {

/** Exact per-face projection chart. Local-sheet remains authoritative
 * provenance. Exact manifold adjacency may cross local-sheet labels, while
 * component, hard-rail, boundary, and nonmanifold barriers remain authoritative. */
struct SourceProjectionChart {
  int component = -1;
  int localSheet = -1;
  int sourceFace = -1;

  [[nodiscard]] bool valid() const {
    return component >= 0 && localSheet >= 0 && sourceFace >= 0;
  }

  friend bool operator==(const SourceProjectionChart &lhs, const SourceProjectionChart &rhs) {
    return std::tie(lhs.component, lhs.localSheet, lhs.sourceFace) ==
           std::tie(rhs.component, rhs.localSheet, rhs.sourceFace);
  }
  friend bool operator<(const SourceProjectionChart &lhs, const SourceProjectionChart &rhs) {
    return std::tie(lhs.component, lhs.localSheet, lhs.sourceFace) <
           std::tie(rhs.component, rhs.localSheet, rhs.sourceFace);
  }
};

enum class SourceEntityKind : int {
  Invalid = 0,
  SourceVertex = 1,
  SourceEdge = 2,
  FaceInterior = 3,
};

struct SourceEntityId {
  SourceEntityKind kind = SourceEntityKind::Invalid;
  int component = -1;
  int firstSourceIndex = -1;
  int secondSourceIndex = -1;
  int intrinsicFan = -1;
  SurfaceCellCanonicalIdentity canonical;

  [[nodiscard]] bool valid() const {
    return kind != SourceEntityKind::Invalid && component >= 0 &&
           firstSourceIndex >= 0 && intrinsicFan >= 0 && canonical.valid;
  }

  friend bool operator==(const SourceEntityId &lhs,
                         const SourceEntityId &rhs) {
    return lhs.kind == rhs.kind && lhs.component == rhs.component &&
           lhs.firstSourceIndex == rhs.firstSourceIndex &&
           lhs.secondSourceIndex == rhs.secondSourceIndex &&
           lhs.intrinsicFan == rhs.intrinsicFan &&
           lhs.canonical == rhs.canonical;
  }
};

struct SourceChartTransition {
  SourceProjectionChart from;
  SourceProjectionChart to;
  SourceEntityId sharedEntity;
  // +1 preserves the canonical source-edge endpoint order, -1 reverses it.
  int orientation = 1;
  std::array<int, 3> fromCornerToTarget{{-1, -1, -1}};
  std::uint64_t structuralHash = 0U;

  [[nodiscard]] bool valid() const {
    return from.valid() && to.valid() && sharedEntity.valid() &&
           (orientation == 1 || orientation == -1);
  }
};

/**
 * Canonical source-chart transition graph.
 *
 * Connectivity is derived only from exact source topology, source-component
 * labels, and hard-edge barriers. World-space proximity and source-triangle
 * pairing never participate. Local-sheet labels remain in chart identity,
 * provenance, and hashes, but do not split an otherwise admissible exact
 * manifold transition within one source component.
 */
class SourceChartTransitionGraph {
public:
  SourceChartTransitionGraph(
      const Eigen::MatrixXi *sourceFaces,
      const std::vector<int> *sourceFaceComponents,
      const std::vector<int> *sourceFaceSheets,
      const std::set<std::uint64_t> *hardFeatureEdges = nullptr,
      const double barycentricTolerance = 1.0e-8)
      : faces_(sourceFaces), components_(sourceFaceComponents),
        sheets_(sourceFaceSheets), hardFeatureEdges_(hardFeatureEdges),
        supportResolver_(sourceFaces, barycentricTolerance),
        barycentricTolerance_(std::max(0.0, barycentricTolerance)) {
    build();
  }

  SourceChartTransitionGraph(
      const Eigen::MatrixXi &sourceFaces,
      const std::vector<int> &sourceFaceComponents,
      const std::vector<int> &sourceFaceSheets,
      const std::set<std::uint64_t> *hardFeatureEdges = nullptr,
      const double barycentricTolerance = 1.0e-8)
      : SourceChartTransitionGraph(&sourceFaces, &sourceFaceComponents,
                                   &sourceFaceSheets, hardFeatureEdges,
                                   barycentricTolerance) {}

  [[nodiscard]] bool available() const {
    return faces_ != nullptr && faces_->cols() == 3 && components_ != nullptr &&
           sheets_ != nullptr &&
           components_->size() == static_cast<std::size_t>(faces_->rows()) &&
           sheets_->size() == static_cast<std::size_t>(faces_->rows()) &&
           consistent_ && faceChartComponent_.size() ==
               static_cast<std::size_t>(faces_->rows());
  }

  [[nodiscard]] SourceProjectionChart chart(const int sourceFace) const {
    if (!available() || sourceFace < 0 || sourceFace >= faces_->rows()) {
      return {};
    }
    return {(*components_)[static_cast<std::size_t>(sourceFace)],
            (*sheets_)[static_cast<std::size_t>(sourceFace)], sourceFace};
  }

  [[nodiscard]] int chart_component(const int sourceFace) const {
    if (!available() || sourceFace < 0 ||
        sourceFace >= static_cast<int>(faceChartComponent_.size())) {
      return -1;
    }
    return faceChartComponent_[static_cast<std::size_t>(sourceFace)];
  }

  [[nodiscard]] int chart_component(const SourceProjectionChart &value) const {
    if (!value.valid() || value.sourceFace < 0 || !available() ||
        value.sourceFace >= faces_->rows()) {
      return -1;
    }
    const SourceProjectionChart actual = chart(value.sourceFace);
    if (actual.component != value.component ||
        actual.localSheet != value.localSheet) {
      return -1;
    }
    return chart_component(value.sourceFace);
  }

  [[nodiscard]] bool same_chart_component(const SourceProjectionChart &first,
                                          const SourceProjectionChart &second) const {
    const int a = chart_component(first);
    const int b = chart_component(second);
    return a >= 0 && a == b;
  }

  [[nodiscard]] const std::vector<int> &chart_component_faces(
      const int componentOrdinal) const {
    static const std::vector<int> empty;
    if (componentOrdinal < 0 ||
        componentOrdinal >= static_cast<int>(chartComponentFaces_.size())) {
      return empty;
    }
    return chartComponentFaces_[static_cast<std::size_t>(componentOrdinal)];
  }

  [[nodiscard]] const SurfaceCellCanonicalIdentity &chart_component_identity(
      const int componentOrdinal) const {
    static const SurfaceCellCanonicalIdentity invalid;
    if (componentOrdinal < 0 || componentOrdinal >=
                                    static_cast<int>(chartComponentIdentity_.size())) {
      return invalid;
    }
    return chartComponentIdentity_[static_cast<std::size_t>(componentOrdinal)];
  }

  [[nodiscard]] const std::vector<SourceChartTransition> &transitions() const {
    return transitions_;
  }

  [[nodiscard]] bool is_hard_edge(const int firstVertex,
                                  const int secondVertex) const {
    return hardFeatureEdges_ != nullptr &&
           hardFeatureEdges_->count(edge_key(firstVertex, secondVertex)) != 0U;
  }

  [[nodiscard]] SourceEntityId resolve_entity(const SurfacePoint &point) const {
    SourceEntityId entity;
    if (!available() || point.face < 0 || point.face >= faces_->rows()) {
      return entity;
    }
    const SourceProjectionChart sourceChart = chart(point.face);
    if ((point.component >= 0 && point.component != sourceChart.component) ||
        (point.sheet >= 0 && point.sheet != sourceChart.localSheet)) {
      return entity;
    }
    const SurfacePointSourceSupport support = supportResolver_.resolve(point);
    if (!support.valid()) {
      return entity;
    }
    entity.component = sourceChart.component;
    const int chartComponent = chart_component(point.face);
    if (const auto *faceSupport =
            std::get_if<authority::SourceFaceInteriorSupport>(
                &support.identity.value())) {
      entity.kind = SourceEntityKind::FaceInterior;
      entity.firstSourceIndex =
          static_cast<int>(faceSupport->face.index());
      entity.intrinsicFan = chartComponent;
      entity.canonical = face_identity(entity.firstSourceIndex, chartComponent);
      return entity;
    }
    if (const auto *edgeSupport =
            std::get_if<authority::SourceEdgeSupport>(
                &support.identity.value())) {
      entity.kind = SourceEntityKind::SourceEdge;
      entity.firstSourceIndex =
          static_cast<int>(edgeSupport->edge.first().index());
      entity.secondSourceIndex =
          static_cast<int>(edgeSupport->edge.second().index());
      entity.intrinsicFan = chartComponent;
      entity.canonical.valid = chartComponent >= 0;
      entity.canonical.values = {
          static_cast<std::int64_t>(SourceEntityKind::SourceEdge),
          entity.component, entity.firstSourceIndex, entity.secondSourceIndex,
          chartComponent};
      return entity;
    }
    if (const auto *vertexSupport =
            std::get_if<authority::SourceVertexSupport>(
                &support.identity.value())) {
      const int sourceVertex =
          static_cast<int>(vertexSupport->vertex.index());
      const auto found = vertexFanOrdinal_.find({point.face, sourceVertex});
      if (found == vertexFanOrdinal_.end()) {
        return {};
      }
      entity.kind = SourceEntityKind::SourceVertex;
      entity.firstSourceIndex = sourceVertex;
      entity.intrinsicFan = found->second;
      entity.canonical.valid = true;
      entity.canonical.values = {
          static_cast<std::int64_t>(SourceEntityKind::SourceVertex),
          entity.component, sourceVertex, entity.intrinsicFan};
      return entity;
    }
    return {};
  }

  /** Re-express an edge/vertex SurfacePoint in another exact chart. */
  [[nodiscard]] bool rebind(const SurfacePoint &point, const int targetFace,
                            SurfacePoint &rebound) const {
    rebound = {};
    if (!available() || targetFace < 0 || targetFace >= faces_->rows()) {
      return false;
    }
    const SourceEntityId sourceEntity = resolve_entity(point);
    if (!sourceEntity.valid()) {
      return false;
    }
    const SourceProjectionChart targetChart = chart(targetFace);
    if (targetChart.component != sourceEntity.component) {
      return false;
    }

    Eigen::Vector3d targetBarycentric = Eigen::Vector3d::Zero();
    if (sourceEntity.kind == SourceEntityKind::FaceInterior) {
      if (targetFace != point.face) {
        return false;
      }
      targetBarycentric = point.barycentric;
    } else if (sourceEntity.kind == SourceEntityKind::SourceVertex) {
      const auto fan = vertexFanOrdinal_.find(
          {targetFace, sourceEntity.firstSourceIndex});
      if (fan == vertexFanOrdinal_.end() || fan->second != sourceEntity.intrinsicFan) {
        return false;
      }
      const int targetCorner =
          face_corner(targetFace, sourceEntity.firstSourceIndex);
      if (targetCorner < 0) {
        return false;
      }
      targetBarycentric(targetCorner) = 1.0;
    } else if (sourceEntity.kind == SourceEntityKind::SourceEdge) {
      if (chart_component(targetFace) != sourceEntity.intrinsicFan) {
        return false;
      }
      const int sourceFirstCorner =
          face_corner(point.face, sourceEntity.firstSourceIndex);
      const int sourceSecondCorner =
          face_corner(point.face, sourceEntity.secondSourceIndex);
      const int targetFirstCorner =
          face_corner(targetFace, sourceEntity.firstSourceIndex);
      const int targetSecondCorner =
          face_corner(targetFace, sourceEntity.secondSourceIndex);
      if (sourceFirstCorner < 0 || sourceSecondCorner < 0 ||
          targetFirstCorner < 0 || targetSecondCorner < 0) {
        return false;
      }
      targetBarycentric(targetFirstCorner) = point.barycentric(sourceFirstCorner);
      targetBarycentric(targetSecondCorner) =
          point.barycentric(sourceSecondCorner);
    } else {
      return false;
    }

    const double sum = targetBarycentric.sum();
    if (!targetBarycentric.allFinite() || !(sum > 0.0)) {
      return false;
    }
    targetBarycentric /= sum;
    for (int corner = 0; corner < 3; ++corner) {
      if (std::abs(targetBarycentric(corner)) <= barycentricTolerance_) {
        targetBarycentric(corner) = 0.0;
      }
    }
    rebound = point;
    rebound.face = targetFace;
    rebound.component = targetChart.component;
    rebound.sheet = targetChart.localSheet;
    rebound.barycentric = targetBarycentric;
    return true;
  }

  /** Returns one deterministic intrinsic chart component covering all points. */
  [[nodiscard]] int compatible_chart_component(
      const std::vector<const SurfacePoint *> &points) const {
    if (!available() || points.empty()) {
      return -1;
    }
    std::set<int> common;
    bool firstPoint = true;
    for (const SurfacePoint *point : points) {
      if (point == nullptr) {
        return -1;
      }
      const SurfacePointSourceSupport support = supportResolver_.resolve(*point);
      if (!support.valid()) {
        return -1;
      }
      std::set<int> pointComponents;
      for (const authority::SourceFaceId sourceFace : support.incidentFaces) {
        const int face = static_cast<int>(sourceFace.index());
        SurfacePoint rebound;
        if (rebind(*point, face, rebound)) {
          const int component = chart_component(face);
          if (component >= 0) {
            pointComponents.insert(component);
          }
        }
      }
      if (pointComponents.empty()) {
        return -1;
      }
      if (firstPoint) {
        common = std::move(pointComponents);
        firstPoint = false;
      } else {
        std::set<int> intersection;
        std::set_intersection(common.begin(), common.end(),
                              pointComponents.begin(), pointComponents.end(),
                              std::inserter(intersection, intersection.end()));
        common = std::move(intersection);
      }
      if (common.empty()) {
        return -1;
      }
    }
    return common.size() == 1U ? *common.begin() : -1;
  }

  [[nodiscard]] std::uint64_t transition_component_hash(
      const int componentOrdinal) const {
    const SurfaceCellCanonicalIdentity &identity =
        chart_component_identity(componentOrdinal);
    return identity.hash();
  }

private:
  struct EdgeIncidence {
    int face = -1;
    int localEdge = -1;
  };

  [[nodiscard]] static std::uint64_t edge_key(const int first,
                                               const int second) {
    const auto low = static_cast<std::uint32_t>(std::min(first, second));
    const auto high = static_cast<std::uint32_t>(std::max(first, second));
    return (static_cast<std::uint64_t>(low) << 32U) |
           static_cast<std::uint64_t>(high);
  }

  [[nodiscard]] int face_corner(const int face, const int sourceVertex) const {
    if (faces_ == nullptr || face < 0 || face >= faces_->rows()) {
      return -1;
    }
    for (int corner = 0; corner < 3; ++corner) {
      if ((*faces_)(face, corner) == sourceVertex) {
        return corner;
      }
    }
    return -1;
  }

  [[nodiscard]] SurfaceCellCanonicalIdentity
  face_identity(const int face, const int componentOrdinal) const {
    SurfaceCellCanonicalIdentity identity;
    if (!available() || face < 0 || face >= faces_->rows() ||
        componentOrdinal < 0) {
      return identity;
    }
    std::array<int, 3> vertices{{(*faces_)(face, 0), (*faces_)(face, 1),
                                 (*faces_)(face, 2)}};
    std::sort(vertices.begin(), vertices.end());
    identity.valid = true;
    identity.values = {
        static_cast<std::int64_t>(SourceEntityKind::FaceInterior),
        (*components_)[static_cast<std::size_t>(face)], vertices[0],
        vertices[1], vertices[2], componentOrdinal};
    return identity;
  }

  [[nodiscard]] SurfaceCellCanonicalIdentity
  component_membership_identity(const std::vector<int> &memberFaces) const {
    SurfaceCellCanonicalIdentity identity;
    if (memberFaces.empty()) {
      return identity;
    }
    std::vector<std::array<std::int64_t, 5>> members;
    members.reserve(memberFaces.size());
    for (const int face : memberFaces) {
      if (face < 0 || face >= faces_->rows()) {
        return {};
      }
      std::array<int, 3> vertices{{(*faces_)(face, 0), (*faces_)(face, 1),
                                   (*faces_)(face, 2)}};
      std::sort(vertices.begin(), vertices.end());
      members.push_back({(*components_)[static_cast<std::size_t>(face)],
                         (*sheets_)[static_cast<std::size_t>(face)],
                         vertices[0], vertices[1], vertices[2]});
    }
    std::sort(members.begin(), members.end());
    identity.valid = true;
    identity.values.push_back(static_cast<std::int64_t>(members.size()));
    for (const auto &member : members) {
      identity.values.insert(identity.values.end(), member.begin(),
                             member.end());
    }
    return identity;
  }

  void build() {
    if (faces_ == nullptr || faces_->cols() != 3 || components_ == nullptr ||
        sheets_ == nullptr ||
        components_->size() != static_cast<std::size_t>(faces_->rows()) ||
        sheets_->size() != static_cast<std::size_t>(faces_->rows())) {
      return;
    }

    const int faceCount = faces_->rows();
    std::map<std::uint64_t, std::vector<EdgeIncidence>> edgeIncidence;
    int maximumVertex = -1;
    for (int face = 0; face < faceCount; ++face) {
      std::set<int> uniqueVertices;
      for (int corner = 0; corner < 3; ++corner) {
        const int sourceVertex = (*faces_)(face, corner);
        if (sourceVertex < 0 || !uniqueVertices.insert(sourceVertex).second) {
          consistent_ = false;
          return;
        }
        maximumVertex = std::max(maximumVertex, sourceVertex);
        const int first = (*faces_)(face, corner);
        const int second = (*faces_)(face, (corner + 1) % 3);
        edgeIncidence[edge_key(first, second)].push_back({face, corner});
      }
    }

    std::vector<int> parent(static_cast<std::size_t>(faceCount));
    std::iota(parent.begin(), parent.end(), 0);
    const auto find = [&](int value) {
      int root = value;
      while (parent[static_cast<std::size_t>(root)] != root) {
        root = parent[static_cast<std::size_t>(root)];
      }
      while (parent[static_cast<std::size_t>(value)] != value) {
        const int next = parent[static_cast<std::size_t>(value)];
        parent[static_cast<std::size_t>(value)] = root;
        value = next;
      }
      return root;
    };
    const auto unite = [&](const int first, const int second) {
      int a = find(first);
      int b = find(second);
      if (a == b) {
        return;
      }
      if (a > b) {
        std::swap(a, b);
      }
      parent[static_cast<std::size_t>(b)] = a;
    };

    std::vector<std::vector<int>> faceAdjacency(
        static_cast<std::size_t>(faceCount));
    for (const auto &[key, incident] : edgeIncidence) {
      if (incident.size() != 2U ||
          (hardFeatureEdges_ != nullptr &&
           hardFeatureEdges_->count(key) != 0U)) {
        continue;
      }
      const int firstFace = incident[0].face;
      const int secondFace = incident[1].face;
      if ((*components_)[static_cast<std::size_t>(firstFace)] !=
          (*components_)[static_cast<std::size_t>(secondFace)]) {
        continue;
      }
      // Exact manifold topology, not a local projection-chart label, owns
      // intrinsic adjacency. Local-sheet labels remain attached to each chart
      // and still constrain non-topological capture and projection consumers.
      unite(firstFace, secondFace);
      faceAdjacency[static_cast<std::size_t>(firstFace)].push_back(secondFace);
      faceAdjacency[static_cast<std::size_t>(secondFace)].push_back(firstFace);

      const int lowVertex = static_cast<int>(key >> 32U);
      const int highVertex = static_cast<int>(key & 0xffffffffU);
      SourceChartTransition forward;
      forward.from = chart_unchecked(firstFace);
      forward.to = chart_unchecked(secondFace);
      forward.sharedEntity.kind = SourceEntityKind::SourceEdge;
      forward.sharedEntity.component = forward.from.component;
      forward.sharedEntity.firstSourceIndex = lowVertex;
      forward.sharedEntity.secondSourceIndex = highVertex;
      forward.orientation = edge_orientation(firstFace, secondFace,
                                             lowVertex, highVertex);
      if (forward.orientation != -1) {
        // An oriented manifold source must traverse a shared edge in opposite
        // directions. Reject inconsistent chart composition before identity
        // or output ownership can be committed.
        consistent_ = false;
        transitions_.clear();
        faceChartComponent_.clear();
        return;
      }
      for (int corner = 0; corner < 3; ++corner) {
        forward.fromCornerToTarget[static_cast<std::size_t>(corner)] =
            face_corner(secondFace, (*faces_)(firstFace, corner));
      }
      transitions_.push_back(forward);

      SourceChartTransition reverse = forward;
      std::swap(reverse.from, reverse.to);
      reverse.orientation = forward.orientation;
      for (int corner = 0; corner < 3; ++corner) {
        reverse.fromCornerToTarget[static_cast<std::size_t>(corner)] =
            face_corner(firstFace, (*faces_)(secondFace, corner));
      }
      transitions_.push_back(reverse);
    }

    std::map<int, std::vector<int>> facesByRoot;
    for (int face = 0; face < faceCount; ++face) {
      facesByRoot[find(face)].push_back(face);
    }
    struct ComponentBuild {
      SurfaceCellCanonicalIdentity identity;
      std::vector<int> faces;
    };
    std::vector<ComponentBuild> components;
    components.reserve(facesByRoot.size());
    for (auto &[root, memberFaces] : facesByRoot) {
      (void)root;
      std::sort(memberFaces.begin(), memberFaces.end());
      components.push_back(
          {component_membership_identity(memberFaces), memberFaces});
    }
    std::sort(components.begin(), components.end(),
              [](const ComponentBuild &lhs, const ComponentBuild &rhs) {
                return lhs.identity < rhs.identity;
              });
    faceChartComponent_.assign(static_cast<std::size_t>(faceCount), -1);
    for (int ordinal = 0; ordinal < static_cast<int>(components.size());
         ++ordinal) {
      chartComponentFaces_.push_back(
          components[static_cast<std::size_t>(ordinal)].faces);
      chartComponentIdentity_.push_back(
          components[static_cast<std::size_t>(ordinal)].identity);
      for (const int face : components[static_cast<std::size_t>(ordinal)].faces) {
        faceChartComponent_[static_cast<std::size_t>(face)] = ordinal;
      }
    }

    // Intrinsic source-vertex fans are connected components of incident
    // charts through admissible manifold edges that contain the vertex.
    std::vector<std::vector<int>> incidentFaces(
        static_cast<std::size_t>(std::max(0, maximumVertex + 1)));
    for (int face = 0; face < faceCount; ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = (*faces_)(face, corner);
        if (vertex >= 0) {
          incidentFaces[static_cast<std::size_t>(vertex)].push_back(face);
        }
      }
    }
    for (int vertex = 0; vertex < static_cast<int>(incidentFaces.size());
         ++vertex) {
      std::vector<int> faces = incidentFaces[static_cast<std::size_t>(vertex)];
      std::sort(faces.begin(), faces.end());
      faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
      std::set<int> unvisited(faces.begin(), faces.end());
      struct FanBuild {
        SurfaceCellCanonicalIdentity identity;
        std::vector<int> faces;
      };
      std::vector<FanBuild> fans;
      while (!unvisited.empty()) {
        const int seed = *unvisited.begin();
        unvisited.erase(unvisited.begin());
        std::vector<int> stack{seed};
        std::vector<int> fanFaces;
        while (!stack.empty()) {
          const int face = stack.back();
          stack.pop_back();
          fanFaces.push_back(face);
          for (const int neighbor :
               faceAdjacency[static_cast<std::size_t>(face)]) {
            if (face_corner(neighbor, vertex) < 0 ||
                unvisited.erase(neighbor) == 0U) {
              continue;
            }
            stack.push_back(neighbor);
          }
        }
        std::sort(fanFaces.begin(), fanFaces.end());
        SurfaceCellCanonicalIdentity identity =
            component_membership_identity(fanFaces);
        identity.values.insert(identity.values.begin(), vertex);
        fans.push_back({std::move(identity), std::move(fanFaces)});
      }
      std::sort(fans.begin(), fans.end(),
                [](const FanBuild &lhs, const FanBuild &rhs) {
                  return lhs.identity < rhs.identity;
                });
      for (int ordinal = 0; ordinal < static_cast<int>(fans.size()); ++ordinal) {
        for (const int face : fans[static_cast<std::size_t>(ordinal)].faces) {
          vertexFanOrdinal_[{face, vertex}] = ordinal;
        }
      }
    }

    for (SourceChartTransition &transition : transitions_) {
      transition.sharedEntity.intrinsicFan =
          chart_component(transition.from.sourceFace);
      transition.sharedEntity.canonical.valid = true;
      transition.sharedEntity.canonical.values = {
          static_cast<std::int64_t>(SourceEntityKind::SourceEdge),
          transition.sharedEntity.component,
          transition.sharedEntity.firstSourceIndex,
          transition.sharedEntity.secondSourceIndex,
          transition.sharedEntity.intrinsicFan};
      std::uint64_t hash = 1469598103934665603ULL;
      const auto mix = [&](const std::int64_t value) {
        hash ^= static_cast<std::uint64_t>(value);
        hash *= 1099511628211ULL;
      };
      mix(transition.from.component);
      mix(transition.from.localSheet);
      mix(transition.from.sourceFace);
      mix(transition.to.component);
      mix(transition.to.localSheet);
      mix(transition.to.sourceFace);
      mix(transition.orientation);
      mix(static_cast<std::int64_t>(transition.sharedEntity.canonical.hash()));
      transition.structuralHash = hash;
    }
    std::sort(transitions_.begin(), transitions_.end(),
              [](const SourceChartTransition &lhs,
                 const SourceChartTransition &rhs) {
                return std::tie(lhs.from, lhs.to, lhs.structuralHash) <
                       std::tie(rhs.from, rhs.to, rhs.structuralHash);
              });
  }

  [[nodiscard]] SourceProjectionChart chart_unchecked(const int sourceFace) const {
    return {(*components_)[static_cast<std::size_t>(sourceFace)],
            (*sheets_)[static_cast<std::size_t>(sourceFace)], sourceFace};
  }

  [[nodiscard]] int edge_orientation(const int firstFace, const int secondFace,
                                     const int lowVertex,
                                     const int highVertex) const {
    const auto direction = [&](const int face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int first = (*faces_)(face, corner);
        const int second = (*faces_)(face, (corner + 1) % 3);
        if (first == lowVertex && second == highVertex) {
          return 1;
        }
        if (first == highVertex && second == lowVertex) {
          return -1;
        }
      }
      return 0;
    };
    const int firstDirection = direction(firstFace);
    const int secondDirection = direction(secondFace);
    if (firstDirection == 0 || secondDirection == 0) {
      return 1;
    }
    // Consistently oriented manifold triangles traverse their shared edge in
    // opposite directions; the coordinate map still preserves canonical
    // low->high endpoint order.
    return firstDirection == -secondDirection ? -1 : 1;
  }

  const Eigen::MatrixXi *faces_ = nullptr;
  const std::vector<int> *components_ = nullptr;
  const std::vector<int> *sheets_ = nullptr;
  const std::set<std::uint64_t> *hardFeatureEdges_ = nullptr;
  SurfacePointSourceSupportResolver supportResolver_;
  double barycentricTolerance_ = 1.0e-8;
  std::vector<int> faceChartComponent_;
  std::vector<std::vector<int>> chartComponentFaces_;
  std::vector<SurfaceCellCanonicalIdentity> chartComponentIdentity_;
  std::map<std::pair<int, int>, int> vertexFanOrdinal_;
  std::vector<SourceChartTransition> transitions_;
  bool consistent_ = true;
};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SOURCE_CHART_TRANSITIONS_H
