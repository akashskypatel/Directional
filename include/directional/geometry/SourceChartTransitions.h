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
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/geometry/SourceTopologyRegions.h>
#include <directional/geometry/SurfaceCellOwnership.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/geometry/SurfacePointSupport.h>

namespace directional::geometry {

enum class SourceEntityKind : int {
  Invalid = 0,
  SourceVertex = 1,
  SourceEdge = 2,
  FaceInterior = 3,
};

[[nodiscard]] inline SourceEntityKind
source_entity_kind(const authority::SourceSupport &support) {
  switch (authority::support_kind(support)) {
  case authority::SourceSupportKind::Vertex:
    return SourceEntityKind::SourceVertex;
  case authority::SourceSupportKind::Edge:
    return SourceEntityKind::SourceEdge;
  case authority::SourceSupportKind::FaceInterior:
    return SourceEntityKind::FaceInterior;
  }
  return SourceEntityKind::Invalid;
}

/**
 * Resolved source-entity authority.
 *
 * Source support and projection chart are typed authority. A vertex-fan id is
 * present only when the same source vertex has more than one intrinsic fan.
 * canonical is a deterministic derived representation for hashing/sorting; it
 * is never read back as source authority.
 */
struct ResolvedSourceEntity {
  authority::SourceSupport support;
  SourceProjectionChart chart;
  std::optional<authority::SourceVertexFanId> vertexFan;
  SurfaceCellCanonicalIdentity canonical;

  ResolvedSourceEntity(authority::SourceSupport sourceSupport,
                       SourceProjectionChart projectionChart,
                       std::optional<authority::SourceVertexFanId> fan,
                       SurfaceCellCanonicalIdentity derivedCanonical)
      : support(std::move(sourceSupport)), chart(std::move(projectionChart)),
        vertexFan(fan), canonical(std::move(derivedCanonical)) {}

  [[nodiscard]] bool valid() const noexcept { return canonical.valid; }
  [[nodiscard]] SourceEntityKind kind() const {
    return source_entity_kind(support);
  }

  friend bool operator==(const ResolvedSourceEntity &lhs,
                         const ResolvedSourceEntity &rhs) {
    return lhs.support == rhs.support && lhs.chart == rhs.chart &&
           lhs.vertexFan == rhs.vertexFan;
  }

  friend bool operator<(const ResolvedSourceEntity &lhs,
                        const ResolvedSourceEntity &rhs) {
    return std::tie(lhs.support, lhs.chart, lhs.vertexFan) <
           std::tie(rhs.support, rhs.chart, rhs.vertexFan);
  }
};

struct SourceChartTransition {
  SourceProjectionChart from;
  SourceProjectionChart to;
  authority::SourceEdgeSupport sharedEntity;
  // +1 preserves the canonical source-edge endpoint order, -1 reverses it.
  int orientation = 1;
  std::array<int, 3> fromCornerToTarget{{-1, -1, -1}};
  /// Derived diagnostic digest; never semantic authority.
  std::uint64_t structuralHash = 0U;

  SourceChartTransition(SourceProjectionChart source,
                        SourceProjectionChart target,
                        authority::SourceEdgeSupport shared)
      : from(std::move(source)), to(std::move(target)),
        sharedEntity(std::move(shared)) {}

  [[nodiscard]] bool valid() const {
    return orientation == 1 || orientation == -1;
  }
};

/**
 * Canonical source-chart transition graph.
 *
 * Connectivity is derived only from exact source topology, the published
 * SourceTopologyRegions product, and hard-edge barriers. World-space
 * proximity and raw classifier arrays never participate. SurfacePoint's raw
 * component/sheet fields are representation leaves and are never trusted as
 * source authority by this graph.
 */
class SourceChartTransitionGraph {
public:
  SourceChartTransitionGraph(
      const Eigen::MatrixXi *sourceFaces,
      const SourceTopologyRegions *sourceAuthority,
      const std::set<std::uint64_t> *hardFeatureEdges = nullptr,
      const double barycentricTolerance = 1.0e-8)
      : faces_(sourceFaces), authority_(sourceAuthority),
        hardFeatureEdges_(hardFeatureEdges),
        supportResolver_(sourceFaces, barycentricTolerance),
        barycentricTolerance_(std::max(0.0, barycentricTolerance)) {
    build();
  }

  SourceChartTransitionGraph(
      const Eigen::MatrixXi &sourceFaces,
      const SourceTopologyRegions &sourceAuthority,
      const std::set<std::uint64_t> *hardFeatureEdges = nullptr,
      const double barycentricTolerance = 1.0e-8)
      : SourceChartTransitionGraph(&sourceFaces, &sourceAuthority,
                                   hardFeatureEdges, barycentricTolerance) {}

  [[nodiscard]] bool available() const {
    return faces_ != nullptr && faces_->cols() == 3 && authority_ != nullptr &&
           authority_->matches_source_faces(*faces_) &&
           consistent_ && faceChartComponent_.size() ==
                              static_cast<std::size_t>(faces_->rows());
  }

  [[nodiscard]] std::optional<SourceProjectionChart>
  chart(const int sourceFace) const {
    if (!available() || sourceFace < 0 || sourceFace >= faces_->rows() ||
        sourceFace >= static_cast<int>(faceFieldChart_.size()) ||
        !faceFieldChart_[static_cast<std::size_t>(sourceFace)].has_value()) {
      return std::nullopt;
    }
    const auto faceId = source_face_id(sourceFace);
    if (!faceId.has_value()) {
      return std::nullopt;
    }
    return SourceProjectionChart(
        faceFieldChart_[static_cast<std::size_t>(sourceFace)].value(),
        faceId.value());
  }

  [[nodiscard]] int chart_component(const int sourceFace) const {
    if (!available() || sourceFace < 0 ||
        sourceFace >= static_cast<int>(faceChartComponent_.size())) {
      return -1;
    }
    return faceChartComponent_[static_cast<std::size_t>(sourceFace)];
  }

  [[nodiscard]] int chart_component(const SourceProjectionChart &value) const {
    if (!available() ||
        value.face.index() >= static_cast<std::size_t>(faces_->rows())) {
      return -1;
    }
    const int sourceFace = static_cast<int>(value.face.index());
    const auto actual = chart(sourceFace);
    if (!actual.has_value() || actual.value() != value) {
      return -1;
    }
    return chart_component(sourceFace);
  }

  [[nodiscard]] std::optional<authority::SourceComponentId>
  source_component(const SourceProjectionChart &value) const {
    if (chart_component(value) < 0 || authority_ == nullptr) {
      return std::nullopt;
    }
    return authority_->component_for_row(value.face);
  }

  [[nodiscard]] std::optional<authority::IsolationSheetId>
  isolation_sheet(const SourceProjectionChart &value) const {
    if (chart_component(value) < 0 || authority_ == nullptr) {
      return std::nullopt;
    }
    return authority_->sheet_for_row(value.face);
  }

  [[nodiscard]] std::optional<authority::TopologyRegionId>
  topology_region(const SourceProjectionChart &value) const {
    if (chart_component(value) < 0 || authority_ == nullptr) {
      return std::nullopt;
    }
    return authority_->region_for_row(value.face);
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
    if (componentOrdinal < 0 ||
        componentOrdinal >= static_cast<int>(chartComponentIdentity_.size())) {
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

  [[nodiscard]] std::optional<ResolvedSourceEntity>
  resolve_entity(const SurfacePoint &point) const {
    if (!available() || point.face < 0 || point.face >= faces_->rows()) {
      return std::nullopt;
    }
    const auto sourceChart = chart(point.face);
    if (!sourceChart.has_value()) {
      return std::nullopt;
    }
    const SurfacePointSourceSupport resolved = supportResolver_.resolve(point);
    if (!resolved.valid()) {
      return std::nullopt;
    }
    const authority::SourceSupport &support = resolved.identity.value();
    const auto component = source_component(sourceChart.value());
    if (!component.has_value()) {
      return std::nullopt;
    }

    SurfaceCellCanonicalIdentity canonical;
    std::optional<authority::SourceVertexFanId> vertexFan;
    if (const auto *faceSupport =
            std::get_if<authority::SourceFaceInteriorSupport>(&support)) {
      canonical = face_identity(
          static_cast<int>(faceSupport->face.index()),
          sourceChart->chart);
    } else if (const auto *edgeSupport =
                   std::get_if<authority::SourceEdgeSupport>(&support)) {
      canonical.valid = true;
      canonical.values = {
          static_cast<std::int64_t>(SourceEntityKind::SourceEdge),
          static_cast<std::int64_t>(component->index()),
          static_cast<std::int64_t>(edgeSupport->edge.first().index()),
          static_cast<std::int64_t>(edgeSupport->edge.second().index()),
          static_cast<std::int64_t>(sourceChart->chart.index())};
    } else if (const auto *vertexSupport =
                   std::get_if<authority::SourceVertexSupport>(&support)) {
      const int sourceVertex = static_cast<int>(vertexSupport->vertex.index());
      const auto found = vertexFan_.find({point.face, sourceVertex});
      if (found == vertexFan_.end()) {
        return std::nullopt;
      }
      vertexFan = found->second;
      canonical.valid = true;
      canonical.values = {
          static_cast<std::int64_t>(SourceEntityKind::SourceVertex),
          static_cast<std::int64_t>(component->index()),
          static_cast<std::int64_t>(vertexSupport->vertex.index()),
          static_cast<std::int64_t>(vertexFan->index())};
    } else {
      return std::nullopt;
    }
    if (!canonical.valid) {
      return std::nullopt;
    }
    return ResolvedSourceEntity(support, sourceChart.value(), vertexFan,
                                std::move(canonical));
  }

  /** Re-express an edge/vertex SurfacePoint in another exact chart. */
  [[nodiscard]] bool rebind(const SurfacePoint &point, const int targetFace,
                            SurfacePoint &rebound) const {
    rebound = {};
    if (!available() || targetFace < 0 || targetFace >= faces_->rows()) {
      return false;
    }
    const auto sourceEntity = resolve_entity(point);
    if (!sourceEntity.has_value()) {
      return false;
    }
    const auto targetChart = chart(targetFace);
    if (!targetChart.has_value()) {
      return false;
    }
    const auto sourceComponent = source_component(sourceEntity->chart);
    const auto targetComponent = source_component(targetChart.value());
    if (!sourceComponent.has_value() || !targetComponent.has_value() ||
        sourceComponent.value() != targetComponent.value()) {
      return false;
    }

    Eigen::Vector3d targetBarycentric = Eigen::Vector3d::Zero();
    if (const auto *faceSupport =
            std::get_if<authority::SourceFaceInteriorSupport>(
                &sourceEntity->support)) {
      if (targetFace != static_cast<int>(faceSupport->face.index())) {
        return false;
      }
      targetBarycentric = point.barycentric;
    } else if (const auto *vertexSupport =
                   std::get_if<authority::SourceVertexSupport>(
                       &sourceEntity->support)) {
      const int sourceVertex = static_cast<int>(vertexSupport->vertex.index());
      const auto fan = vertexFan_.find({targetFace, sourceVertex});
      if (fan == vertexFan_.end() || !sourceEntity->vertexFan.has_value() ||
          fan->second != sourceEntity->vertexFan.value()) {
        return false;
      }
      const int targetCorner = face_corner(targetFace, sourceVertex);
      if (targetCorner < 0) {
        return false;
      }
      targetBarycentric(targetCorner) = 1.0;
    } else if (const auto *edgeSupport =
                   std::get_if<authority::SourceEdgeSupport>(
                       &sourceEntity->support)) {
      if (targetChart->chart != sourceEntity->chart.chart) {
        return false;
      }
      const int firstSourceVertex =
          static_cast<int>(edgeSupport->edge.first().index());
      const int secondSourceVertex =
          static_cast<int>(edgeSupport->edge.second().index());
      const int sourceFirstCorner = face_corner(point.face, firstSourceVertex);
      const int sourceSecondCorner = face_corner(point.face, secondSourceVertex);
      const int targetFirstCorner = face_corner(targetFace, firstSourceVertex);
      const int targetSecondCorner = face_corner(targetFace, secondSourceVertex);
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
    rebound.component = static_cast<int>(targetComponent->index());
    const auto targetSheet = isolation_sheet(targetChart.value());
    if (!targetSheet.has_value()) {
      return false;
    }
    rebound.sheet = static_cast<int>(targetSheet->index());
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

  [[nodiscard]] std::optional<authority::SourceFaceId>
  source_face_id(const int face) const {
    if (faces_ == nullptr || face < 0 || face >= faces_->rows()) {
      return std::nullopt;
    }
    const auto id = authority::SourceFaceId::from_index(
        face, static_cast<std::size_t>(faces_->rows()));
    return id ? std::optional<authority::SourceFaceId>(id.value())
              : std::nullopt;
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
  face_identity(const int face, const authority::FieldChartId chartId) const {
    SurfaceCellCanonicalIdentity identity;
    const auto row = source_face_id(face);
    if (!available() || !row.has_value() || authority_ == nullptr) {
      return identity;
    }
    const auto component = authority_->component_for_row(row.value());
    const auto &topology = authority_->topology_for_row(row.value());
    const auto &vertices = topology.vertices();
    identity.valid = true;
    identity.values = {
        static_cast<std::int64_t>(SourceEntityKind::FaceInterior),
        static_cast<std::int64_t>(component.index()),
        static_cast<std::int64_t>(vertices[0].index()),
        static_cast<std::int64_t>(vertices[1].index()),
        static_cast<std::int64_t>(vertices[2].index()),
        static_cast<std::int64_t>(chartId.index())};
    return identity;
  }

  [[nodiscard]] SurfaceCellCanonicalIdentity
  component_membership_identity(const std::vector<int> &memberFaces) const {
    SurfaceCellCanonicalIdentity identity;
    if (memberFaces.empty() || authority_ == nullptr) {
      return identity;
    }
    std::vector<std::array<std::int64_t, 5>> members;
    members.reserve(memberFaces.size());
    for (const int face : memberFaces) {
      const auto row = source_face_id(face);
      if (!row.has_value()) {
        return {};
      }
      const auto component = authority_->component_for_row(row.value());
      const auto sheet = authority_->sheet_for_row(row.value());
      const auto &vertices = authority_->topology_for_row(row.value()).vertices();
      members.push_back({static_cast<std::int64_t>(component.index()),
                         static_cast<std::int64_t>(sheet.index()),
                         static_cast<std::int64_t>(vertices[0].index()),
                         static_cast<std::int64_t>(vertices[1].index()),
                         static_cast<std::int64_t>(vertices[2].index())});
    }
    std::sort(members.begin(), members.end());
    identity.valid = true;
    identity.values.push_back(static_cast<std::int64_t>(members.size()));
    for (const auto &member : members) {
      identity.values.insert(identity.values.end(), member.begin(), member.end());
    }
    return identity;
  }

  void build() {
    if (faces_ == nullptr || faces_->cols() != 3 || authority_ == nullptr ||
        !authority_->matches_source_faces(*faces_)) {
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
    const std::size_t vertexExtent =
        static_cast<std::size_t>(std::max(0, maximumVertex + 1));

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

    struct PendingTransition {
      int firstFace = -1;
      int secondFace = -1;
      authority::SourceEdgeTopologyKey edge;
      int orientation = 1;

      PendingTransition(int first, int second,
                        authority::SourceEdgeTopologyKey sourceEdge,
                        int edgeOrientation)
          : firstFace(first), secondFace(second), edge(std::move(sourceEdge)),
            orientation(edgeOrientation) {}
    };

    std::vector<std::vector<int>> faceAdjacency(
        static_cast<std::size_t>(faceCount));
    std::vector<PendingTransition> pendingTransitions;
    for (const auto &[key, incident] : edgeIncidence) {
      if (incident.size() != 2U ||
          (hardFeatureEdges_ != nullptr && hardFeatureEdges_->count(key) != 0U)) {
        continue;
      }
      const int firstFace = incident[0].face;
      const int secondFace = incident[1].face;
      const auto firstRow = source_face_id(firstFace);
      const auto secondRow = source_face_id(secondFace);
      if (!firstRow.has_value() || !secondRow.has_value() ||
          authority_->component_for_row(firstRow.value()) !=
              authority_->component_for_row(secondRow.value())) {
        continue;
      }
      unite(firstFace, secondFace);
      faceAdjacency[static_cast<std::size_t>(firstFace)].push_back(secondFace);
      faceAdjacency[static_cast<std::size_t>(secondFace)].push_back(firstFace);

      const int lowVertex = static_cast<int>(key >> 32U);
      const int highVertex = static_cast<int>(key & 0xffffffffU);
      const auto low = authority::SourceVertexId::from_index(lowVertex, vertexExtent);
      const auto high = authority::SourceVertexId::from_index(highVertex, vertexExtent);
      if (!low || !high) {
        consistent_ = false;
        return;
      }
      const auto edge = authority::SourceEdgeTopologyKey::make(
          low.value(), high.value());
      if (!edge) {
        consistent_ = false;
        return;
      }
      const int orientation =
          edge_orientation(firstFace, secondFace, lowVertex, highVertex);
      if (orientation != -1) {
        consistent_ = false;
        transitions_.clear();
        faceChartComponent_.clear();
        return;
      }
      pendingTransitions.emplace_back(firstFace, secondFace, edge.value(),
                                      orientation);
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
    faceFieldChart_.assign(static_cast<std::size_t>(faceCount), std::nullopt);
    for (int ordinal = 0; ordinal < static_cast<int>(components.size()); ++ordinal) {
      const auto chartId = authority::FieldChartId::from_index(
          ordinal, components.size());
      if (!chartId) {
        consistent_ = false;
        faceChartComponent_.clear();
        faceFieldChart_.clear();
        return;
      }
      chartComponentFaces_.push_back(
          components[static_cast<std::size_t>(ordinal)].faces);
      chartComponentIdentity_.push_back(
          components[static_cast<std::size_t>(ordinal)].identity);
      for (const int face : components[static_cast<std::size_t>(ordinal)].faces) {
        faceChartComponent_[static_cast<std::size_t>(face)] = ordinal;
        faceFieldChart_[static_cast<std::size_t>(face)] = chartId.value();
      }
    }

    transitions_.reserve(2U * pendingTransitions.size());
    for (const PendingTransition &pending : pendingTransitions) {
      SourceChartTransition forward(
          chart_unchecked(pending.firstFace), chart_unchecked(pending.secondFace),
          authority::SourceEdgeSupport{pending.edge});
      forward.orientation = pending.orientation;
      for (int corner = 0; corner < 3; ++corner) {
        forward.fromCornerToTarget[static_cast<std::size_t>(corner)] =
            face_corner(pending.secondFace, (*faces_)(pending.firstFace, corner));
      }
      transitions_.push_back(forward);

      SourceChartTransition reverse = forward;
      std::swap(reverse.from, reverse.to);
      for (int corner = 0; corner < 3; ++corner) {
        reverse.fromCornerToTarget[static_cast<std::size_t>(corner)] =
            face_corner(pending.firstFace, (*faces_)(pending.secondFace, corner));
      }
      transitions_.push_back(reverse);
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
    for (int vertex = 0; vertex < static_cast<int>(incidentFaces.size()); ++vertex) {
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
          for (const int neighbor : faceAdjacency[static_cast<std::size_t>(face)]) {
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
        const auto fanId = authority::SourceVertexFanId::from_index(
            ordinal, fans.size());
        if (!fanId) {
          consistent_ = false;
          vertexFan_.clear();
          return;
        }
        for (const int face : fans[static_cast<std::size_t>(ordinal)].faces) {
          vertexFan_.emplace(std::make_pair(face, vertex), fanId.value());
        }
      }
    }

    for (SourceChartTransition &transition : transitions_) {
      std::uint64_t hash = 1469598103934665603ULL;
      const auto mix = [&](const std::int64_t value) {
        hash ^= static_cast<std::uint64_t>(value);
        hash *= 1099511628211ULL;
      };
      mix(static_cast<std::int64_t>(transition.from.chart.index()));
      mix(static_cast<std::int64_t>(transition.from.face.index()));
      mix(static_cast<std::int64_t>(transition.to.chart.index()));
      mix(static_cast<std::int64_t>(transition.to.face.index()));
      mix(transition.orientation);
      mix(static_cast<std::int64_t>(transition.sharedEntity.edge.first().index()));
      mix(static_cast<std::int64_t>(transition.sharedEntity.edge.second().index()));
      transition.structuralHash = hash;
    }
    std::sort(transitions_.begin(), transitions_.end(),
              [](const SourceChartTransition &lhs,
                 const SourceChartTransition &rhs) {
                return std::tie(lhs.from, lhs.to, lhs.sharedEntity.edge,
                                lhs.orientation, lhs.fromCornerToTarget) <
                       std::tie(rhs.from, rhs.to, rhs.sharedEntity.edge,
                                rhs.orientation, rhs.fromCornerToTarget);
              });
  }

  [[nodiscard]] SourceProjectionChart chart_unchecked(const int sourceFace) const {
    const auto faceId = source_face_id(sourceFace);
    if (!faceId.has_value() || sourceFace < 0 ||
        sourceFace >= static_cast<int>(faceFieldChart_.size()) ||
        !faceFieldChart_[static_cast<std::size_t>(sourceFace)].has_value()) {
      throw std::logic_error(
          "Source projection chart requested before publication");
    }
    return SourceProjectionChart(
        faceFieldChart_[static_cast<std::size_t>(sourceFace)].value(),
        faceId.value());
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
    return firstDirection == -secondDirection ? -1 : 1;
  }

  const Eigen::MatrixXi *faces_ = nullptr;
  const SourceTopologyRegions *authority_ = nullptr;
  const std::set<std::uint64_t> *hardFeatureEdges_ = nullptr;
  SurfacePointSourceSupportResolver supportResolver_;
  double barycentricTolerance_ = 1.0e-8;
  std::vector<int> faceChartComponent_;
  std::vector<std::optional<authority::FieldChartId>> faceFieldChart_;
  std::vector<std::vector<int>> chartComponentFaces_;
  std::vector<SurfaceCellCanonicalIdentity> chartComponentIdentity_;
  std::map<std::pair<int, int>, authority::SourceVertexFanId> vertexFan_;
  std::vector<SourceChartTransition> transitions_;
  bool consistent_ = true;
};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SOURCE_CHART_TRANSITIONS_H
