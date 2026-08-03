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
#include <cmath>
#include <map>
#include <utility>
#include <vector>

#include <Eigen/Core>

#include <directional/geometry/SurfacePoint.h>

namespace directional::geometry {

enum class SurfacePointSourceEntityKind : int {
  Invalid = 0,
  FaceInterior = 1,
  SourceEdge = 2,
  SourceVertex = 3,
};

inline const char *surface_point_source_entity_kind_name(
    const SurfacePointSourceEntityKind kind) {
  switch (kind) {
  case SurfacePointSourceEntityKind::Invalid:
    return "invalid";
  case SurfacePointSourceEntityKind::FaceInterior:
    return "face-interior";
  case SurfacePointSourceEntityKind::SourceEdge:
    return "source-edge";
  case SurfacePointSourceEntityKind::SourceVertex:
    return "source-vertex";
  }
  return "invalid";
}

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
  SurfacePointSourceEntityKind kind = SurfacePointSourceEntityKind::Invalid;
  SurfacePointSourceSupportFailure failure =
      SurfacePointSourceSupportFailure::None;
  int sourceVertex = -1;
  std::pair<int, int> sourceEdge{-1, -1};
  std::vector<int> supportedFaces;

  [[nodiscard]] bool valid() const {
    return kind != SurfacePointSourceEntityKind::Invalid &&
           failure == SurfacePointSourceSupportFailure::None &&
           !supportedFaces.empty();
  }
};

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

    if (supportCorners.size() == 3U) {
      result.kind = SurfacePointSourceEntityKind::FaceInterior;
      result.supportedFaces.push_back(point.face);
      return result;
    }
    if (supportCorners.size() == 2U) {
      const int first = (*sourceFaces_)(point.face, supportCorners[0]);
      const int second = (*sourceFaces_)(point.face, supportCorners[1]);
      if (first < 0 || second < 0 || first == second) {
        result.failure =
            SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
        return result;
      }
      result.kind = SurfacePointSourceEntityKind::SourceEdge;
      result.sourceEdge = canonical_edge(first, second);
      const auto found = edgeFaces_.find(result.sourceEdge);
      if (found == edgeFaces_.end() || found->second.empty()) {
        result.kind = SurfacePointSourceEntityKind::Invalid;
        result.failure =
            SurfacePointSourceSupportFailure::MissingSourceEntityIncidence;
        return result;
      }
      result.supportedFaces = found->second;
      return result;
    }
    if (supportCorners.size() == 1U) {
      const int vertex = (*sourceFaces_)(point.face, supportCorners.front());
      if (vertex < 0 || vertex >= static_cast<int>(vertexFaces_.size())) {
        result.failure =
            SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
        return result;
      }
      result.kind = SurfacePointSourceEntityKind::SourceVertex;
      result.sourceVertex = vertex;
      result.supportedFaces =
          vertexFaces_[static_cast<std::size_t>(vertex)];
      if (result.supportedFaces.empty()) {
        result.kind = SurfacePointSourceEntityKind::Invalid;
        result.failure =
            SurfacePointSourceSupportFailure::MissingSourceEntityIncidence;
      }
      return result;
    }

    result.failure = SurfacePointSourceSupportFailure::AmbiguousSourceEntity;
    return result;
  }

private:
  [[nodiscard]] static std::pair<int, int> canonical_edge(const int first,
                                                           const int second) {
    return first < second ? std::make_pair(first, second)
                          : std::make_pair(second, first);
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
    for (int face = 0; face < sourceFaces_->rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = (*sourceFaces_)(face, corner);
        const int next = (*sourceFaces_)(face, (corner + 1) % 3);
        if (vertex >= 0 && vertex < static_cast<int>(vertexFaces_.size())) {
          vertexFaces_[static_cast<std::size_t>(vertex)].push_back(face);
        }
        if (vertex >= 0 && next >= 0 && vertex != next) {
          edgeFaces_[canonical_edge(vertex, next)].push_back(face);
        }
      }
    }
    for (std::vector<int> &faces : vertexFaces_) {
      canonicalize_faces(faces);
    }
    for (auto &[edge, faces] : edgeFaces_) {
      (void)edge;
      canonicalize_faces(faces);
    }
  }

  static void canonicalize_faces(std::vector<int> &faces) {
    std::sort(faces.begin(), faces.end());
    faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  }

  const Eigen::MatrixXi *sourceFaces_ = nullptr;
  double barycentricTolerance_ = 1.0e-8;
  std::vector<std::vector<int>> vertexFaces_;
  std::map<std::pair<int, int>, std::vector<int>> edgeFaces_;
};

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_POINT_SUPPORT_H
