// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_POINT_SUPPORT_H
#define DIRECTIONAL_GEOMETRY_SURFACE_POINT_SUPPORT_H

#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <optional>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/authority/SourceSupport.h>
#include <directional/geometry/SurfacePoint.h>

namespace directional::geometry {

enum class SurfacePointSourceSupportFailure : int {
  None = 0,
  SourceTopologyUnavailable = 1,
  InvalidSourceFace = 2,
  NonFiniteBarycentric = 3,
  InvalidBarycentricRange = 4,
  InvalidBarycentricSum = 5,
  AmbiguousSourceEntity = 6,
  MissingSourceEntityIncidence = 7,
};

inline const char *surface_point_source_support_failure_name(
    const SurfacePointSourceSupportFailure failure) {
  switch (failure) {
  case SurfacePointSourceSupportFailure::None:
    return "None";
  case SurfacePointSourceSupportFailure::SourceTopologyUnavailable:
    return "SourceTopologyUnavailable";
  case SurfacePointSourceSupportFailure::InvalidSourceFace:
    return "InvalidSourceFace";
  case SurfacePointSourceSupportFailure::NonFiniteBarycentric:
    return "NonFiniteBarycentric";
  case SurfacePointSourceSupportFailure::InvalidBarycentricRange:
    return "InvalidBarycentricRange";
  case SurfacePointSourceSupportFailure::InvalidBarycentricSum:
    return "InvalidBarycentricSum";
  case SurfacePointSourceSupportFailure::AmbiguousSourceEntity:
    return "AmbiguousSourceEntity";
  case SurfacePointSourceSupportFailure::MissingSourceEntityIncidence:
    return "MissingSourceEntityIncidence";
  }
  return "Unknown";
}

struct SurfacePointSourceSupport {
  std::optional<authority::SourceSupport> identity;
  SurfacePointSourceSupportFailure failure =
      SurfacePointSourceSupportFailure::None;
  std::vector<authority::SourceFaceId> incidentFaces;

  [[nodiscard]] bool valid() const {
    return identity.has_value() &&
           failure == SurfacePointSourceSupportFailure::None &&
           !incidentFaces.empty();
  }

  [[nodiscard]] std::optional<authority::SourceSupportKind> kind() const {
    if (!identity.has_value()) return std::nullopt;
    return authority::support_kind(identity.value());
  }
};

inline const char *surface_point_source_support_kind_name(
    const SurfacePointSourceSupport &support) {
  if (!support.identity.has_value()) return "invalid";
  switch (authority::support_kind(support.identity.value())) {
  case authority::SourceSupportKind::FaceInterior:
    return "face-interior";
  case authority::SourceSupportKind::Edge:
    return "source-edge";
  case authority::SourceSupportKind::Vertex:
    return "source-vertex";
  }
  return "invalid";
}

/**
 * Resolves the intrinsic source entity supporting a SurfacePoint.
 *
 * The stored SurfacePoint::face is a projection chart. For a point on a
 * source edge or source vertex, all incident source faces are valid charts.
 * Face-interior points remain owned only by their stored source face.
 */
class SurfacePointSourceSupportResolver {
public:
  explicit SurfacePointSourceSupportResolver(
      const Eigen::MatrixXi *sourceFaces,
      const double barycentricTolerance = 1.0e-8)
      : sourceFaces_(sourceFaces),
        barycentricTolerance_(std::max(0.0, barycentricTolerance)) {
    build_incidence();
  }

  explicit SurfacePointSourceSupportResolver(
      const Eigen::MatrixXi &sourceFaces,
      const double barycentricTolerance = 1.0e-8)
      : SurfacePointSourceSupportResolver(&sourceFaces,
                                          barycentricTolerance) {}

  [[nodiscard]] bool available() const {
    return sourceFaces_ != nullptr && sourceFaces_->cols() == 3;
  }

  [[nodiscard]] double barycentric_tolerance() const {
    return barycentricTolerance_;
  }

  [[nodiscard]] SurfacePointSourceSupport
  resolve(const SurfacePoint &point) const {
    SurfacePointSourceSupport result;
    if (!available()) {
      result.failure =
          SurfacePointSourceSupportFailure::SourceTopologyUnavailable;
      return result;
    }
    if (!point.valid() || point.face < 0 ||
        point.face >= sourceFaces_->rows()) {
      result.failure = SurfacePointSourceSupportFailure::InvalidSourceFace;
      return result;
    }
    if (!point.barycentric.allFinite()) {
      result.failure = SurfacePointSourceSupportFailure::NonFiniteBarycentric;
      return result;
    }

    Eigen::Vector3d barycentric = point.barycentric;
    const double sumTolerance =
        std::max(1.0e-12, 8.0 * barycentricTolerance_);
    for (int corner = 0; corner < 3; ++corner) {
      if (barycentric(corner) < -barycentricTolerance_ ||
          barycentric(corner) > 1.0 + barycentricTolerance_) {
        result.failure =
            SurfacePointSourceSupportFailure::InvalidBarycentricRange;
        return result;
      }
      if (std::abs(barycentric(corner)) <= barycentricTolerance_) {
        barycentric(corner) = 0.0;
      } else if (std::abs(1.0 - barycentric(corner)) <=
                 barycentricTolerance_) {
        barycentric(corner) = 1.0;
      }
    }
    const double sum = barycentric.sum();
    if (!std::isfinite(sum) || std::abs(sum - 1.0) > sumTolerance ||
        sum <= 0.0) {
      result.failure =
          SurfacePointSourceSupportFailure::InvalidBarycentricSum;
      return result;
    }
    barycentric /= sum;

    std::vector<int> supportCorners;
    for (int corner = 0; corner < 3; ++corner) {
      if (barycentric(corner) > barycentricTolerance_) {
        supportCorners.push_back(corner);
      }
    }

    const auto sourceFace = authority::SourceFaceId::from_index(
        point.face, static_cast<std::size_t>(sourceFaces_->rows()));
    if (!sourceFace) {
      result.failure = SurfacePointSourceSupportFailure::InvalidSourceFace;
      return result;
    }

    if (supportCorners.size() == 3U) {
      const auto topology = face_topology_key(point.face);
      if (!topology.has_value()) {
        result.failure =
            SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
        return result;
      }
      result.identity = authority::SourceFaceInteriorSupport{*topology};
      result.incidentFaces.push_back(sourceFace.value());
      return result;
    }
    if (supportCorners.size() == 2U) {
      const int first = (*sourceFaces_)(point.face, supportCorners[0]);
      const int second = (*sourceFaces_)(point.face, supportCorners[1]);
      const auto firstVertex = authority::SourceVertexId::from_index(
          first, vertexFaces_.size());
      const auto secondVertex = authority::SourceVertexId::from_index(
          second, vertexFaces_.size());
      if (!firstVertex || !secondVertex) {
        result.failure =
            SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
        return result;
      }
      const auto edge = authority::SourceEdgeTopologyKey::make(
          firstVertex.value(), secondVertex.value());
      if (!edge) {
        result.failure =
            SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
        return result;
      }
      const auto found = edgeFaces_.find(edge.value());
      if (found == edgeFaces_.end() || found->second.empty()) {
        result.failure =
            SurfacePointSourceSupportFailure::MissingSourceEntityIncidence;
        return result;
      }
      result.identity = authority::SourceEdgeSupport{edge.value()};
      result.incidentFaces = found->second;
      return result;
    }
    if (supportCorners.size() == 1U) {
      const int vertex = (*sourceFaces_)(point.face, supportCorners.front());
      const auto sourceVertex = authority::SourceVertexId::from_index(
          vertex, vertexFaces_.size());
      if (!sourceVertex) {
        result.failure =
            SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
        return result;
      }
      result.identity = authority::SourceVertexSupport{sourceVertex.value()};
      result.incidentFaces =
          vertexFaces_[sourceVertex.value().index()];
      if (result.incidentFaces.empty()) {
        result.identity.reset();
        result.failure =
            SurfacePointSourceSupportFailure::MissingSourceEntityIncidence;
      }
      return result;
    }

    result.failure = SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
    return result;
  }

private:
  [[nodiscard]] std::optional<authority::SourceFaceTopologyKey>
  face_topology_key(const int face) const {
    if (!available() || face < 0 || face >= sourceFaces_->rows() ||
        vertexFaces_.empty()) {
      return std::nullopt;
    }
    const auto first = authority::SourceVertexId::from_index(
        (*sourceFaces_)(face, 0), vertexFaces_.size());
    const auto second = authority::SourceVertexId::from_index(
        (*sourceFaces_)(face, 1), vertexFaces_.size());
    const auto third = authority::SourceVertexId::from_index(
        (*sourceFaces_)(face, 2), vertexFaces_.size());
    if (!first || !second || !third) {
      return std::nullopt;
    }
    const auto topology = authority::SourceFaceTopologyKey::make(
        {first.value(), second.value(), third.value()});
    return topology
               ? std::optional<authority::SourceFaceTopologyKey>(topology.value())
               : std::nullopt;
  }

  void build_incidence() {
    if (!available()) {
      return;
    }
    int maximumVertex = -1;
    for (int face = 0; face < sourceFaces_->rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        maximumVertex = std::max(maximumVertex, (*sourceFaces_)(face, corner));
      }
    }
    vertexFaces_.resize(
        static_cast<std::size_t>(std::max(0, maximumVertex + 1)));
    const std::size_t faceExtent =
        static_cast<std::size_t>(sourceFaces_->rows());
    for (int face = 0; face < sourceFaces_->rows(); ++face) {
      const auto sourceFace = authority::SourceFaceId::from_index(face, faceExtent);
      if (!sourceFace) continue;
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = (*sourceFaces_)(face, corner);
        const int next = (*sourceFaces_)(face, (corner + 1) % 3);
        const auto sourceVertex = authority::SourceVertexId::from_index(
            vertex, vertexFaces_.size());
        if (sourceVertex) {
          vertexFaces_[sourceVertex.value().index()].push_back(sourceFace.value());
        }
        const auto nextVertex = authority::SourceVertexId::from_index(
            next, vertexFaces_.size());
        if (sourceVertex && nextVertex) {
          const auto edge = authority::SourceEdgeTopologyKey::make(
              sourceVertex.value(), nextVertex.value());
          if (edge) {
            edgeFaces_[edge.value()].push_back(sourceFace.value());
          }
        }
      }
    }
    for (auto &faces : vertexFaces_) {
      canonicalize_faces(faces);
    }
    for (auto &[edge, faces] : edgeFaces_) {
      (void)edge;
      canonicalize_faces(faces);
    }
  }

  static void canonicalize_faces(std::vector<authority::SourceFaceId> &faces) {
    std::sort(faces.begin(), faces.end());
    faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  }

  const Eigen::MatrixXi *sourceFaces_ = nullptr;
  double barycentricTolerance_ = 1.0e-8;
  std::vector<std::vector<authority::SourceFaceId>> vertexFaces_;
  std::map<authority::SourceEdgeTopologyKey,
           std::vector<authority::SourceFaceId>>
      edgeFaces_;

};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_POINT_SUPPORT_H
