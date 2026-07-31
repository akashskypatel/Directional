#include <directional/geometry/BoundedMeshPreconditioner.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

namespace directional::geometry {

class BoundedMeshPreconditionerImpl {
public:
  [[nodiscard]] static BoundedMeshPreconditionerResult
  precondition(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
               const BoundedMeshPreconditionerOptions &options) {
    BoundedMeshPreconditionerResult result;
    result.vertices = vertices;
    result.faces = faces;
    result.inputTriangleCount = static_cast<std::size_t>(faces.rows());
    result.outputTriangleCount = static_cast<std::size_t>(faces.rows());
    result.before = evaluate_quality(vertices, faces);
    result.after = result.before;

    if (!options.enabled || vertices.cols() != 3 || faces.cols() != 3 ||
        faces.rows() == 0) {
      return result;
    }
    if (!face_count_within_budget(faces.rows(), faces.rows(), options)) {
      return result;
    }

    std::set<std::pair<int, int>> protectedEdges =
        collect_boundary_edges(faces);
    const auto featureMapStart = std::chrono::high_resolution_clock::now();
    const AdaptiveFeatureMap featureMap =
        build_adaptive_feature_map(vertices, faces, options);
    result.adaptiveFeatureMapSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() - featureMapStart)
            .count() /
        1.0e6;
    store_feature_map_metrics(featureMap, result);
    const std::set<std::pair<int, int>> featureEdges =
        collect_adaptive_feature_edges(featureMap);
    protectedEdges.insert(featureEdges.begin(), featureEdges.end());

    for (int pass = 0; pass < std::max(0, options.maxFlipPasses); ++pass) {
      bool changed = false;
      const auto edgeFaces = collect_edge_faces(result.faces);
      for (const auto &[edge, incidentFaces] : edgeFaces) {
        if (incidentFaces.size() != 2 || protectedEdges.count(edge) != 0) {
          continue;
        }
        if (try_flip_edge(result.vertices, result.faces, incidentFaces[0],
                          incidentFaces[1], edge)) {
          ++result.flipsAccepted;
          changed = true;
        }
      }
      if (!changed) {
        break;
      }
    }

    result.outputTriangleCount = static_cast<std::size_t>(result.faces.rows());
    result.after = evaluate_quality(result.vertices, result.faces);
    return result;
  }

  [[nodiscard]] static MeshQualityMetrics
  evaluate_quality(const Eigen::MatrixXd &vertices,
                   const Eigen::MatrixXi &faces) {
    MeshQualityMetrics metrics;
    if (vertices.cols() != 3 || faces.cols() != 3 || faces.rows() == 0) {
      return metrics;
    }

    std::vector<double> aspects;
    std::vector<double> edgeLengths;
    aspects.reserve(static_cast<std::size_t>(faces.rows()));
    edgeLengths.reserve(static_cast<std::size_t>(faces.rows()) * 3U);
    metrics.minTriangleAngleDegrees = 180.0;

    for (int face = 0; face < faces.rows(); ++face) {
      const Eigen::RowVector3d a = row3(vertices, faces(face, 0));
      const Eigen::RowVector3d b = row3(vertices, faces(face, 1));
      const Eigen::RowVector3d c = row3(vertices, faces(face, 2));
      const std::array<double, 3> lengths = {
          (b - c).norm(), (c - a).norm(), (a - b).norm()};
      edgeLengths.insert(edgeLengths.end(), lengths.begin(), lengths.end());
      const double area = 0.5 * cross3(b - a, c - a).norm();
      const double longest = *std::max_element(lengths.begin(), lengths.end());
      if (area > 1.0e-14 && longest > 0.0) {
        aspects.push_back(longest * longest / (2.0 * area));
      }
      for (int corner = 0; corner < 3; ++corner) {
        const double opposite = lengths[static_cast<std::size_t>(corner)];
        const double lhs = lengths[static_cast<std::size_t>((corner + 1) % 3)];
        const double rhs = lengths[static_cast<std::size_t>((corner + 2) % 3)];
        const double denom = 2.0 * lhs * rhs;
        if (denom <= 0.0) {
          continue;
        }
        const double cosine =
            std::clamp((lhs * lhs + rhs * rhs - opposite * opposite) / denom,
                       -1.0, 1.0);
        const double angle =
            std::acos(cosine) * 180.0 / 3.14159265358979323846;
        metrics.minTriangleAngleDegrees =
            std::min(metrics.minTriangleAngleDegrees, angle);
      }
    }

    if (metrics.minTriangleAngleDegrees == 180.0) {
      metrics.minTriangleAngleDegrees = 0.0;
    }
    metrics.aspectRatioP95 = percentile(aspects, 0.95);
    metrics.aspectRatioP99 = percentile(aspects, 0.99);
    metrics.edgeLengthCoefficientOfVariation =
        coefficient_of_variation(edgeLengths);
    return metrics;
  }

private:
  [[nodiscard]] static std::pair<int, int> canonical_edge(const int a,
                                                          const int b) {
    return a <= b ? std::make_pair(a, b) : std::make_pair(b, a);
  }

  [[nodiscard]] static Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                                               const int vertex) {
    return Eigen::RowVector3d(vertices(vertex, 0), vertices(vertex, 1),
                              vertices(vertex, 2));
  }

  [[nodiscard]] static Eigen::RowVector3d
  cross3(const Eigen::RowVector3d &a, const Eigen::RowVector3d &b) {
    return Eigen::RowVector3d(a.y() * b.z() - a.z() * b.y(),
                              a.z() * b.x() - a.x() * b.z(),
                              a.x() * b.y() - a.y() * b.x());
  }

  [[nodiscard]] static bool
  face_count_within_budget(const int inputFaces, const int outputFaces,
                           const BoundedMeshPreconditionerOptions &options) {
    if (inputFaces <= 0) {
      return true;
    }
    const double ratio =
        static_cast<double>(outputFaces) / static_cast<double>(inputFaces);
    return ratio >= options.minFaceRatio && ratio <= options.maxFaceRatio;
  }

  [[nodiscard]] static std::map<std::pair<int, int>, std::vector<int>>
  collect_edge_faces(const Eigen::MatrixXi &faces) {
    std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
    for (int face = 0; face < faces.rows(); ++face) {
      for (int edge = 0; edge < 3; ++edge) {
        edgeFaces[canonical_edge(faces(face, edge),
                                 faces(face, (edge + 1) % 3))]
            .push_back(face);
      }
    }
    return edgeFaces;
  }

  [[nodiscard]] static std::set<std::pair<int, int>>
  collect_boundary_edges(const Eigen::MatrixXi &faces) {
    std::set<std::pair<int, int>> boundary;
    const auto edgeFaces = collect_edge_faces(faces);
    for (const auto &[edge, incidentFaces] : edgeFaces) {
      if (incidentFaces.size() == 1) {
        boundary.insert(edge);
      }
    }
    return boundary;
  }

  [[nodiscard]] static AdaptiveFeatureMap build_adaptive_feature_map(
      const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
      const BoundedMeshPreconditionerOptions &options) {
    AdaptiveFeatureMapOptions mapOptions = options.featureMap;
    mapOptions.cadAbsoluteHighDegrees =
        std::min(mapOptions.cadAbsoluteHighDegrees, options.sharpAngleDegrees);
    mapOptions.organicAbsoluteHighDegrees = std::min(
        mapOptions.organicAbsoluteHighDegrees, options.sharpAngleDegrees);
    return AdaptiveFeatureMapBuilder::build(vertices, faces, mapOptions);
  }

  [[nodiscard]] static std::set<std::pair<int, int>>
  collect_adaptive_feature_edges(const AdaptiveFeatureMap &map) {
    std::set<std::pair<int, int>> features;
    for (const AdaptiveFeatureEdge &edge : map.edges) {
      if (edge.edgeClass == AdaptiveFeatureClass::Hard ||
          edge.edgeClass == AdaptiveFeatureClass::Soft ||
          edge.edgeClass == AdaptiveFeatureClass::NonManifold) {
        features.insert(edge.vertices);
      }
    }
    return features;
  }

  static void store_feature_map_metrics(const AdaptiveFeatureMap &map,
                                        BoundedMeshPreconditionerResult &result) {
    for (const AdaptiveFeatureEdge &edge : map.edges) {
      switch (edge.edgeClass) {
      case AdaptiveFeatureClass::Hard:
        ++result.adaptiveFeatureHardEdgeCount;
        break;
      case AdaptiveFeatureClass::Soft:
        ++result.adaptiveFeatureSoftEdgeCount;
        break;
      case AdaptiveFeatureClass::Boundary:
        ++result.adaptiveFeatureBoundaryEdgeCount;
        break;
      case AdaptiveFeatureClass::NonManifold:
        ++result.adaptiveFeatureNonManifoldEdgeCount;
        break;
      case AdaptiveFeatureClass::Smooth:
        break;
      }
    }
    result.adaptiveFeatureCurveCount = map.curves.size();
    for (const AdaptiveFeatureCurve &curve : map.curves) {
      if (curve.closed) {
        ++result.adaptiveFeatureClosedCurveCount;
      }
    }
    result.adaptiveFeatureMaxDensity =
        map.vertexDensity.size() == 0 ? 0.0 : map.vertexDensity.maxCoeff();
  }

  [[nodiscard]] static Eigen::RowVector3d
  face_normal(const Eigen::MatrixXd &vertices,
              const Eigen::Ref<const Eigen::RowVector3i> face) {
    const Eigen::RowVector3d a = row3(vertices, face(0));
    const Eigen::RowVector3d b = row3(vertices, face(1));
    const Eigen::RowVector3d c = row3(vertices, face(2));
    Eigen::RowVector3d normal = cross3(b - a, c - a);
    const double norm = normal.norm();
    if (norm > 0.0) {
      normal /= norm;
    }
    return normal;
  }

  [[nodiscard]] static double min_angle_for_triangle(
      const Eigen::MatrixXd &vertices, const std::array<int, 3> &tri) {
    Eigen::MatrixXi face(1, 3);
    face << tri[0], tri[1], tri[2];
    return evaluate_quality(vertices, face).minTriangleAngleDegrees;
  }

  [[nodiscard]] static double triangle_area(const Eigen::MatrixXd &vertices,
                                            const std::array<int, 3> &tri) {
    const Eigen::RowVector3d a = row3(vertices, tri[0]);
    const Eigen::RowVector3d b = row3(vertices, tri[1]);
    const Eigen::RowVector3d c = row3(vertices, tri[2]);
    return 0.5 * cross3(b - a, c - a).norm();
  }

  static bool try_flip_edge(const Eigen::MatrixXd &vertices,
                            Eigen::MatrixXi &faces, const int firstFace,
                            const int secondFace,
                            const std::pair<int, int> &edge) {
    std::vector<int> opposite;
    opposite.reserve(2);
    for (const int face : {firstFace, secondFace}) {
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = faces(face, corner);
        if (vertex != edge.first && vertex != edge.second) {
          opposite.push_back(vertex);
        }
      }
    }
    if (opposite.size() != 2 || opposite[0] == opposite[1]) {
      return false;
    }

    const std::array<int, 3> oldA{faces(firstFace, 0), faces(firstFace, 1),
                                  faces(firstFace, 2)};
    const std::array<int, 3> oldB{faces(secondFace, 0), faces(secondFace, 1),
                                  faces(secondFace, 2)};
    std::array<int, 3> newA{opposite[0], opposite[1], edge.first};
    std::array<int, 3> newB{opposite[1], opposite[0], edge.second};
    orient_like(vertices, oldA, newA);
    orient_like(vertices, oldB, newB);
    if (triangle_area(vertices, newA) <= 1.0e-14 ||
        triangle_area(vertices, newB) <= 1.0e-14) {
      return false;
    }

    const double before =
        std::min(min_angle_for_triangle(vertices, oldA),
                 min_angle_for_triangle(vertices, oldB));
    const double after =
        std::min(min_angle_for_triangle(vertices, newA),
                 min_angle_for_triangle(vertices, newB));
    if (after <= before + 1.0e-8) {
      return false;
    }

    Eigen::MatrixXi candidateFaces = faces;
    candidateFaces.row(firstFace) << newA[0], newA[1], newA[2];
    candidateFaces.row(secondFace) << newB[0], newB[1], newB[2];
    if (!oriented_edge_manifold(candidateFaces)) {
      return false;
    }
    faces = std::move(candidateFaces);
    return true;
  }

  [[nodiscard]] static bool
  oriented_edge_manifold(const Eigen::MatrixXi &faces) {
    std::map<std::pair<int, int>, int> directedCounts;
    std::map<std::pair<int, int>, int> undirectedCounts;
    for (int face = 0; face < faces.rows(); ++face) {
      if (faces(face, 0) == faces(face, 1) ||
          faces(face, 1) == faces(face, 2) ||
          faces(face, 2) == faces(face, 0)) {
        return false;
      }
      for (int edge = 0; edge < 3; ++edge) {
        const int a = faces(face, edge);
        const int b = faces(face, (edge + 1) % 3);
        if (++directedCounts[std::make_pair(a, b)] > 1) {
          return false;
        }
        if (++undirectedCounts[canonical_edge(a, b)] > 2) {
          return false;
        }
      }
    }
    for (const auto &[edge, count] : undirectedCounts) {
      if (count == 2) {
        const int forward = directedCounts[edge];
        const int reverse =
            directedCounts[std::make_pair(edge.second, edge.first)];
        if (forward != 1 || reverse != 1) {
          return false;
        }
      }
    }
    return true;
  }

  static void orient_like(const Eigen::MatrixXd &vertices,
                          const std::array<int, 3> &reference,
                          std::array<int, 3> &candidate) {
    const Eigen::RowVector3d refA = row3(vertices, reference[0]);
    const Eigen::RowVector3d refB = row3(vertices, reference[1]);
    const Eigen::RowVector3d refC = row3(vertices, reference[2]);
    const Eigen::RowVector3d candA = row3(vertices, candidate[0]);
    const Eigen::RowVector3d candB = row3(vertices, candidate[1]);
    const Eigen::RowVector3d candC = row3(vertices, candidate[2]);
    const Eigen::RowVector3d refNormal = cross3(refB - refA, refC - refA);
    const Eigen::RowVector3d candNormal =
        cross3(candB - candA, candC - candA);
    if (refNormal.dot(candNormal) < 0.0) {
      std::swap(candidate[1], candidate[2]);
    }
  }

  [[nodiscard]] static double percentile(std::vector<double> values,
                                         const double q) {
    if (values.empty()) {
      return 0.0;
    }
    std::sort(values.begin(), values.end());
    const double clamped = std::clamp(q, 0.0, 1.0);
    const std::size_t index = static_cast<std::size_t>(
        std::round(clamped * static_cast<double>(values.size() - 1)));
    return values[index];
  }

  [[nodiscard]] static double
  coefficient_of_variation(const std::vector<double> &values) {
    if (values.empty()) {
      return 0.0;
    }
    const double mean =
        std::accumulate(values.begin(), values.end(), 0.0) /
        static_cast<double>(values.size());
    if (mean <= 0.0) {
      return 0.0;
    }
    double variance = 0.0;
    for (const double value : values) {
      const double delta = value - mean;
      variance += delta * delta;
    }
    variance /= static_cast<double>(values.size());
    return std::sqrt(variance) / mean;
  }
};

BoundedMeshPreconditionerResult BoundedMeshPreconditioner::precondition(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const BoundedMeshPreconditionerOptions &options) {
  return BoundedMeshPreconditionerImpl::precondition(vertices, faces, options);
}

MeshQualityMetrics BoundedMeshPreconditioner::evaluate_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces) {
  return BoundedMeshPreconditionerImpl::evaluate_quality(vertices, faces);
}

} // namespace directional::geometry
