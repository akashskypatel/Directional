#include <directional/geometry/SurfaceMeshOptimizer.h>

#include <stdexcept>

namespace directional::geometry::surface_optimizer_detail {

bool contains(const std::vector<int> &values, const int value) {
  return std::find(values.begin(), values.end(), value) != values.end();
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

bool armijo_sufficient_decrease(const double currentEnergy,
                                       const double trialEnergy,
                                       const double alpha,
                                       const double descentDirectionalDerivative,
                                       const double armijo) {
  return trialEnergy <=
         currentEnergy - armijo * alpha * descentDirectionalDerivative;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v) {
  const double n = v.norm();
  if (n <= 0.0) {
    return Eigen::RowVector3d::Zero();
  }
  return v / n;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d tangent_direction(
    const Eigen::RowVector3d &vector,
    const Eigen::RowVector3d &surfaceNormal) {
  const Eigen::RowVector3d normal = normalized_or_zero(surfaceNormal);
  if (normal.squaredNorm() == 0.0) {
    return normalized_or_zero(vector);
  }
  return normalized_or_zero(vector - vector.dot(normal) * normal);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::uint64_t topology_hash(const Eigen::MatrixXi &quads) {
  std::uint64_t hash = 1469598103934665603ULL;
  for (int r = 0; r < quads.rows(); ++r) {
    std::array<int, 4> face = {quads(r, 0), quads(r, 1), quads(r, 2),
                               quads(r, 3)};
    const auto minIt = std::min_element(face.begin(), face.end());
    std::rotate(face.begin(), minIt, face.end());
    for (const int v : face) {
      hash ^= static_cast<std::uint64_t>(v);
      hash *= 1099511628211ULL;
    }
    hash ^= 0xff;
    hash *= 1099511628211ULL;
  }
  return hash;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d project_to_interval(const Eigen::RowVector3d &p,
                                              const Eigen::RowVector3d &a,
                                              const Eigen::RowVector3d &b,
                                              double *parameter) {
  const Eigen::RowVector3d ab = b - a;
  const double denom = ab.squaredNorm();
  double t = 0.0;
  if (denom > 0.0) {
    t = std::clamp((p - a).dot(ab) / denom, 0.0, 1.0);
  }
  if (parameter != nullptr) {
    *parameter = t;
  }
  return a + t * ab;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d source_point_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfacePoint &point) {
  if (!point.valid() || point.face < 0 || point.face >= faces.rows() ||
      faces.cols() != 3) {
    return point.position.transpose();
  }
  Eigen::RowVector3d p = Eigen::RowVector3d::Zero();
  for (int c = 0; c < 3; ++c) {
    const int vertex = faces(point.face, c);
    if (vertex >= 0 && vertex < vertices.rows()) {
      p += point.barycentric(c) * vertices.row(vertex);
    }
  }
  return p;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

SurfacePoint nearest_source_point(
    const Eigen::RowVector3d &p, const SurfaceOptimizationConstraints &constraints,
    const std::optional<SourceProjectionScope> &requiredScope,
    SourceProjectionCache *projectionCache) {
  if (!source_optimization_has_complete_authority(constraints) ||
      constraints.sourceVertices.rows() <= 0 ||
      constraints.sourceFaces.rows() <= 0 || constraints.sourceFaces.cols() != 3) {
    return {};
  }
  SourceProjectionCache localCache(constraints);
  SourceProjectionCache *cache =
      projectionCache != nullptr ? projectionCache : &localCache;
  return cache->project(p, requiredScope);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

int feature_curve_for_vertex(const SurfaceOptimizationConstraints &constraints,
                                    const int vertex) {
  if (constraints.featureCurveIds.size() == 0 ||
      vertex < 0 || vertex >= constraints.featureCurveIds.size()) {
    return vertex;
  }
  return constraints.featureCurveIds(vertex);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

SurfaceFeatureSequenceKey feature_sequence_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex) {
  if (vertex >= 0 &&
      static_cast<std::size_t>(vertex) < constraints.featureRailIds.size() &&
      constraints.featureRailIds[static_cast<std::size_t>(vertex)].has_value()) {
    return {constraints.featureRailIds[static_cast<std::size_t>(vertex)], -1};
  }
  return {std::nullopt, feature_curve_for_vertex(constraints, vertex)};
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

int feature_interval_for_vertex(
    const SurfaceOptimizationConstraints &constraints, const int vertex) {
  if (constraints.featureIntervalIds.size() == 0 || vertex < 0 ||
      vertex >= constraints.featureIntervalIds.size()) {
    return -1;
  }
  return constraints.featureIntervalIds(vertex);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

SurfaceFeatureProjection project_to_feature_curve(
    const Eigen::RowVector3d &point,
    const SurfaceOptimizationConstraints &constraints, const int vertex) {
  SurfaceFeatureProjection best;
  const int curveId = feature_curve_for_vertex(constraints, vertex);
  const int requiredInterval = feature_interval_for_vertex(constraints, vertex);
  for (const SurfaceFeatureCurveInterval &interval :
       constraints.featureCurveIntervals) {
    if (interval.curveId != curveId ||
        (requiredInterval >= 0 && interval.intervalId != requiredInterval)) {
      continue;
    }
    double localParameter = 0.0;
    const Eigen::RowVector3d projected = project_to_interval(
        point, interval.start, interval.end, &localParameter);
    const double curveParameter =
        interval.parameterStart +
        localParameter * (interval.parameterEnd - interval.parameterStart);
    const double distance = (point - projected).squaredNorm();
    const bool better =
        !best.valid || distance + 1.0e-24 < best.squaredDistance ||
        (std::abs(distance - best.squaredDistance) <= 1.0e-24 &&
         std::pair<int, int>{interval.order, interval.intervalId} <
             std::pair<int, int>{best.intervalOrder, best.intervalId});
    if (!better) {
      continue;
    }
    best.valid = true;
    best.curveId = interval.curveId;
    best.intervalId = interval.intervalId;
    best.intervalOrder = interval.order;
    best.localParameter = localParameter;
    best.orderCoordinate =
        static_cast<double>(interval.order) + localParameter;
    best.parameter = curveParameter;
    best.squaredDistance = distance;
    best.position = projected;
    best.tangent = interval.end - interval.start;
  }

  if (best.valid) {
    return best;
  }

  return best;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

bool find_feature_interval(
    const SurfaceOptimizationConstraints &constraints, const int vertex,
    Eigen::RowVector3d *start, Eigen::RowVector3d *end) {
  const int curveId = feature_curve_for_vertex(constraints, vertex);
  const int intervalId = feature_interval_for_vertex(constraints, vertex);
  for (const SurfaceFeatureCurveInterval &interval :
       constraints.featureCurveIntervals) {
    if (interval.curveId == curveId &&
        (intervalId < 0 || interval.intervalId == intervalId)) {
      if (start != nullptr) {
        *start = interval.start;
      }
      if (end != nullptr) {
        *end = interval.end;
      }
      return true;
    }
  }
  return false;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d local_source_normal(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace) {
  if (point.valid() && point.face >= 0 &&
      point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3) {
    if (constraints.sourceNormals.rows() == constraints.sourceVertices.rows()) {
      Eigen::RowVector3d normal = Eigen::RowVector3d::Zero();
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = constraints.sourceFaces(point.face, corner);
        if (vertex >= 0 && vertex < constraints.sourceNormals.rows()) {
          normal += point.barycentric(corner) *
                    constraints.sourceNormals.row(vertex);
        }
      }
      const Eigen::RowVector3d interpolated = normalized_or_zero(normal);
      if (interpolated.squaredNorm() > 0.0) {
        return interpolated;
      }
    }
    if (constraints.sourceNormals.rows() == constraints.sourceFaces.rows()) {
      const Eigen::RowVector3d normal =
          normalized_or_zero(constraints.sourceNormals.row(point.face));
      if (normal.squaredNorm() > 0.0) {
        return normal;
      }
    }
    if (constraints.sourceVertices.rows() > 0) {
      const int ia = constraints.sourceFaces(point.face, 0);
      const int ib = constraints.sourceFaces(point.face, 1);
      const int ic = constraints.sourceFaces(point.face, 2);
      if (ia >= 0 && ib >= 0 && ic >= 0 &&
          ia < constraints.sourceVertices.rows() &&
          ib < constraints.sourceVertices.rows() &&
          ic < constraints.sourceVertices.rows()) {
        const Eigen::RowVector3d normal = normalized_or_zero(cross3(
            constraints.sourceVertices.row(ib) -
                constraints.sourceVertices.row(ia),
            constraints.sourceVertices.row(ic) -
                constraints.sourceVertices.row(ia)));
        if (normal.squaredNorm() > 0.0) {
          return normal;
        }
      }
    }
  }
  if (constraints.sourceNormals.rows() > 0) {
    return normalized_or_zero(
        constraints.sourceNormals.row(std::clamp(fallbackFace, 0,
                                                 static_cast<int>(
                                                     constraints.sourceNormals.rows()) -
                                                     1)));
  }
  return {0.0, 0.0, 1.0};
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d tangent_reference(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::RowVector3d &normal) {
  Eigen::RowVector3d reference = Eigen::RowVector3d::Zero();
  if (point.valid() && point.face >= 0 &&
      point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3) {
    const int a = constraints.sourceFaces(point.face, 0);
    const int b = constraints.sourceFaces(point.face, 1);
    if (a >= 0 && b >= 0 && a < constraints.sourceVertices.rows() &&
        b < constraints.sourceVertices.rows()) {
      reference = constraints.sourceVertices.row(b) -
                  constraints.sourceVertices.row(a);
    }
  }
  reference -= reference.dot(normal) * normal;
  reference = normalized_or_zero(reference);
  if (reference.squaredNorm() == 0.0) {
    const Eigen::RowVector3d axis =
        std::abs(normal.x()) < 0.8 ? Eigen::RowVector3d(1.0, 0.0, 0.0)
                                   : Eigen::RowVector3d(0.0, 1.0, 0.0);
    reference = normalized_or_zero(axis - axis.dot(normal) * normal);
  }
  return reference;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

LocalSourceCross local_source_cross(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const int fallbackFace) {
  const Eigen::RowVector3d normal =
      local_source_normal(constraints, point, fallbackFace);
  const Eigen::RowVector3d basisX =
      tangent_reference(constraints, point, normal);
  const Eigen::RowVector3d basisY = normalized_or_zero(cross3(normal, basisX));

  const bool vertexField =
      point.valid() && point.face >= 0 &&
      point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3 &&
      constraints.sourceFieldX.rows() == constraints.sourceVertices.rows();
  if (vertexField) {
    std::complex<double> power(0.0, 0.0);
    double totalWeight = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = constraints.sourceFaces(point.face, corner);
      if (vertex < 0 || vertex >= constraints.sourceFieldX.rows()) {
        continue;
      }
      Eigen::RowVector3d direction = constraints.sourceFieldX.row(vertex);
      direction -= direction.dot(normal) * normal;
      direction = normalized_or_zero(direction);
      if (direction.squaredNorm() == 0.0) {
        continue;
      }
      const double angle =
          std::atan2(direction.dot(basisY), direction.dot(basisX));
      const double weight = std::max(0.0, point.barycentric(corner));
      power += weight *
               std::complex<double>(std::cos(4.0 * angle),
                                    std::sin(4.0 * angle));
      totalWeight += weight;
    }
    if (totalWeight > 0.0 && std::abs(power) > 1.0e-15) {
      const double angle = 0.25 * std::arg(power);
      LocalSourceCross cross;
      cross.x = normalized_or_zero(std::cos(angle) * basisX +
                                   std::sin(angle) * basisY);
      cross.y = normalized_or_zero(cross3(normal, cross.x));
      return cross;
    }
  }

  Eigen::RowVector3d x = basisX;
  if (point.valid() && constraints.sourceFieldX.rows() ==
                           constraints.sourceFaces.rows() &&
      point.face >= 0 && point.face < constraints.sourceFieldX.rows()) {
    x = constraints.sourceFieldX.row(point.face);
  } else if (constraints.sourceFieldX.rows() > 0) {
    x = constraints.sourceFieldX.row(std::clamp(
        fallbackFace, 0, static_cast<int>(constraints.sourceFieldX.rows()) - 1));
  }
  x -= x.dot(normal) * normal;
  x = normalized_or_zero(x);
  if (x.squaredNorm() == 0.0) {
    x = basisX;
  }
  LocalSourceCross cross;
  cross.x = x;
  cross.y = normalized_or_zero(cross3(normal, x));
  return cross;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::vector<int> compatible_source_field_charts(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point) {
  std::vector<int> charts;
  if (!point.valid() || point.face < 0 ||
      point.face >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      constraints.sourceFieldX.rows() != constraints.sourceFaces.rows()) {
    return charts;
  }

  std::vector<int> supportCorners;
  for (int corner = 0; corner < 3; ++corner) {
    if (point.barycentric(corner) > 1.0e-8) {
      supportCorners.push_back(corner);
    }
  }
  if (supportCorners.size() == 1U) {
    const int vertex =
        constraints.sourceFaces(point.face, supportCorners.front());
    if (vertex >= 0 &&
        vertex < static_cast<int>(constraints.sourceVertexFaces.size())) {
      charts = constraints.sourceVertexFaces[static_cast<std::size_t>(vertex)];
    }
  } else if (supportCorners.size() == 2U) {
    const int first =
        constraints.sourceFaces(point.face, supportCorners[0]);
    const int second =
        constraints.sourceFaces(point.face, supportCorners[1]);
    const auto found =
        constraints.sourceEdgeFaces.find(std::minmax(first, second));
    if (found != constraints.sourceEdgeFaces.end()) {
      charts = found->second;
    }
  }
  if (charts.empty()) {
    charts.push_back(point.face);
  } else if (std::find(charts.begin(), charts.end(), point.face) ==
             charts.end()) {
    charts.push_back(point.face);
  }

  charts.erase(
      std::remove_if(charts.begin(), charts.end(), [&](const int face) {
        return face < 0 || face >= constraints.sourceFaces.rows();
      }),
      charts.end());
  std::sort(charts.begin(), charts.end());
  charts.erase(std::unique(charts.begin(), charts.end()), charts.end());
  return charts;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

double best_source_field_alignment(
    const Eigen::RowVector3d &edge,
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &point, const int fallbackFace,
    const SurfacePoint *firstEndpoint,
    const SurfacePoint *secondEndpoint) {
  std::vector<int> charts =
      compatible_source_field_charts(constraints, point);
  if (firstEndpoint != nullptr && secondEndpoint != nullptr) {
    const std::vector<int> firstCharts =
        compatible_source_field_charts(constraints, *firstEndpoint);
    const std::vector<int> secondCharts =
        compatible_source_field_charts(constraints, *secondEndpoint);
    std::vector<int> commonCharts;
    std::set_intersection(firstCharts.begin(), firstCharts.end(),
                          secondCharts.begin(), secondCharts.end(),
                          std::back_inserter(commonCharts));
    if (!commonCharts.empty()) {
      charts = std::move(commonCharts);
    }
  }
  if (charts.empty()) {
    charts.push_back(point.valid() ? point.face : fallbackFace);
  }
  double best = 0.0;
  for (const int chart : charts) {
    SurfacePoint chartPoint = point;
    chartPoint.face = chart;
    const LocalSourceCross cross =
        local_source_cross(constraints, chartPoint, fallbackFace);
    const Eigen::RowVector3d normal =
        local_source_normal(constraints, chartPoint, fallbackFace);
    const Eigen::RowVector3d direction = tangent_direction(edge, normal);
    best = std::max(
        best, std::max(std::abs(direction.dot(cross.x)),
                       std::abs(direction.dot(cross.y))));
  }
  return std::clamp(best, 0.0, 1.0);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d source_triangle_scalar_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point,
    const Eigen::VectorXd &values) {
  if (!point.valid() || point.face < 0 ||
      point.face >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      constraints.sourceVertices.cols() != 3 ||
      values.size() != constraints.sourceVertices.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  const int i0 = constraints.sourceFaces(point.face, 0);
  const int i1 = constraints.sourceFaces(point.face, 1);
  const int i2 = constraints.sourceFaces(point.face, 2);
  if (i0 < 0 || i1 < 0 || i2 < 0 ||
      i0 >= constraints.sourceVertices.rows() ||
      i1 >= constraints.sourceVertices.rows() ||
      i2 >= constraints.sourceVertices.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  const Eigen::RowVector3d e1 =
      constraints.sourceVertices.row(i1) - constraints.sourceVertices.row(i0);
  const Eigen::RowVector3d e2 =
      constraints.sourceVertices.row(i2) - constraints.sourceVertices.row(i0);
  Eigen::Matrix2d gram;
  gram << e1.dot(e1), e1.dot(e2),
      e1.dot(e2), e2.dot(e2);
  const double determinant = gram.determinant();
  if (std::abs(determinant) <= 1.0e-24) {
    return Eigen::RowVector3d::Zero();
  }
  Eigen::Vector2d difference;
  difference << values(i1) - values(i0), values(i2) - values(i0);
  const Eigen::Vector2d coefficients = gram.inverse() * difference;
  return coefficients(0) * e1 + coefficients(1) * e2;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d local_target_size_gradient(
    const SurfaceOptimizationConstraints &constraints, const SurfacePoint &point) {
  if (constraints.localTargetSize.size() !=
      constraints.sourceVertices.rows()) {
    return Eigen::RowVector3d::Zero();
  }
  return source_triangle_scalar_gradient(constraints, point,
                                         constraints.localTargetSize);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

double local_target_size(const SurfaceOptimizationConstraints &constraints,
                                const SurfacePoint &point,
                                const int fallbackVertex,
                                const double globalTargetSize) {
  if (point.valid() &&
      point.face >= 0 && point.face < constraints.sourceFaces.rows() &&
      constraints.sourceFaces.cols() == 3) {
    if (constraints.localTargetSize.size() ==
        constraints.sourceVertices.rows()) {
      double target = 0.0;
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = constraints.sourceFaces(point.face, corner);
        if (vertex >= 0 && vertex < constraints.localTargetSize.size()) {
          target += point.barycentric(corner) *
                    constraints.localTargetSize(vertex);
        }
      }
      if (target > 0.0) {
        return std::max(1.0e-12, target);
      }
    }
    if (constraints.localTargetSize.size() == constraints.sourceFaces.rows()) {
      return std::max(1.0e-12, constraints.localTargetSize(point.face));
    }
  }
  if (constraints.localTargetSize.size() > fallbackVertex &&
      fallbackVertex >= 0) {
    return std::max(1.0e-12, constraints.localTargetSize(fallbackVertex));
  }
  return std::max(1.0e-12, globalTargetSize);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

bool immutable_rail_edge(
    const SurfaceOptimizationConstraints &constraints, const int firstVertex,
    const int secondVertex) {
  if (firstVertex < 0 || secondVertex < 0 ||
      !contains(constraints.fixedVertices, firstVertex) ||
      !contains(constraints.fixedVertices, secondVertex) ||
      !contains(constraints.featureVertices, firstVertex) ||
      !contains(constraints.featureVertices, secondVertex) ||
      constraints.featureRailIds.size() <= firstVertex ||
      constraints.featureRailIds.size() <= secondVertex) {
    return false;
  }
  const auto &firstRail =
      constraints.featureRailIds[static_cast<std::size_t>(firstVertex)];
  const auto &secondRail =
      constraints.featureRailIds[static_cast<std::size_t>(secondVertex)];
  return firstRail.has_value() && firstRail == secondRail;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

double effective_edge_target_size(
    const SurfaceOptimizationConstraints &constraints,
    const SurfacePoint &firstPoint, const SurfacePoint &secondPoint,
    const int firstVertex, const int secondVertex, const double edgeLength,
    const double globalTargetSize) {
  const double localTarget =
      0.5 * (local_target_size(constraints, firstPoint, firstVertex,
                               globalTargetSize) +
             local_target_size(constraints, secondPoint, secondVertex,
                               globalTargetSize));
  // A rail segment whose endpoints are both fixed has no positional degree of
  // freedom. For a bounded mismatch, treat its realized length as the feasible
  // target rather than asking the optimizer to violate an authoritative rail.
  // Extreme target-size requests remain observable and fail validation.
  if (immutable_rail_edge(constraints, firstVertex, secondVertex)) {
    const double safeLength = std::max(1.0e-12, edgeLength);
    const double safeTarget = std::max(1.0e-12, localTarget);
    const double mismatch =
        std::max(safeLength / safeTarget, safeTarget / safeLength);
    if (mismatch <= kMaxImmutableRailSizeRatio) {
      return safeLength;
    }
  }
  return localTarget;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

bool provenance_is_complete(
    const SurfacePoint &point,
    const SurfaceOptimizationConstraints &constraints) {
  if (!point.valid() || !point.position.allFinite() ||
      !point.barycentric.allFinite()) {
    return false;
  }
  const double barycentricSum = point.barycentric.sum();
  if (std::abs(barycentricSum - 1.0) > 1.0e-8 ||
      point.barycentric.minCoeff() < -1.0e-10 ||
      point.barycentric.maxCoeff() > 1.0 + 1.0e-10) {
    return false;
  }
  const bool sourceAuthorityComplete =
      constraints.sourceFaces.rows() > 0 &&
      constraints.sourceAuthority != nullptr &&
      constraints.sourceAuthority->matches_source_faces(
          constraints.sourceFaces,
          static_cast<std::size_t>(constraints.sourceVertices.rows()));
  if (!sourceAuthorityComplete) return false;
  return source_face_scope(constraints, point.face).has_value();
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

SurfacePoint project_to_provenance_entity(
    const Eigen::RowVector3d &candidate, const SurfacePoint &seed,
    const SurfaceOptimizationConstraints &constraints,
    SourceProjectionCache &projectionCache) {
  if (!seed.valid() || seed.face < 0 ||
      seed.face >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      constraints.sourceVertices.cols() != 3 ||
      !seed.barycentric.allFinite()) {
    return {};
  }
  std::vector<int> supportCorners;
  for (int corner = 0; corner < 3; ++corner) {
    if (seed.barycentric(corner) > 1.0e-8) {
      supportCorners.push_back(corner);
    }
  }
  if (supportCorners.empty()) {
    return {};
  }
  if (supportCorners.size() >= 3U) {
    return projectionCache.project(candidate, std::vector<int>{seed.face});
  }

  SurfacePoint projected = seed;
  projected.barycentric.setZero();
  if (supportCorners.size() == 1U) {
    const int corner = supportCorners.front();
    const int sourceVertex = constraints.sourceFaces(seed.face, corner);
    if (sourceVertex < 0 || sourceVertex >= constraints.sourceVertices.rows()) {
      return {};
    }
    projected.barycentric(corner) = 1.0;
    projected.position =
        constraints.sourceVertices.row(sourceVertex).transpose();
  } else {
    const int firstCorner = supportCorners[0];
    const int secondCorner = supportCorners[1];
    const int firstVertex = constraints.sourceFaces(seed.face, firstCorner);
    const int secondVertex = constraints.sourceFaces(seed.face, secondCorner);
    if (firstVertex < 0 || secondVertex < 0 ||
        firstVertex >= constraints.sourceVertices.rows() ||
        secondVertex >= constraints.sourceVertices.rows()) {
      return {};
    }
    const Eigen::RowVector3d first =
        constraints.sourceVertices.row(firstVertex);
    const Eigen::RowVector3d edge =
        constraints.sourceVertices.row(secondVertex) - first;
    const double lengthSquared = edge.squaredNorm();
    if (!(lengthSquared > 1.0e-24)) {
      return {};
    }
    const double parameter = std::clamp(
        (candidate - first).dot(edge) / lengthSquared, 0.0, 1.0);
    projected.barycentric(firstCorner) = 1.0 - parameter;
    projected.barycentric(secondCorner) = parameter;
    projected.position = (first + parameter * edge).transpose();
  }
  projected.squaredDistance =
      (candidate.transpose() - projected.position).squaredNorm();
  return projected;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices, const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters,
    bool *ordered, bool *componentsOk,
    bool *sheetsOk, bool *completeProvenance,
    std::vector<SurfacePoint> *provenance,
    SourceProjectionCache *projectionCache) {
  Eigen::MatrixXd projected = vertices;
  Eigen::VectorXd params = constraints.featureParameters;
  if (params.size() != vertices.rows()) {
    params = Eigen::VectorXd::Zero(vertices.rows());
  }
  Eigen::VectorXd orderCoordinates = params;
  bool orderOk = true;
  bool componentOk = true;
  bool sheetOk = true;
  bool provenanceComplete = true;
  SourceProjectionCache localCache(constraints);
  SourceProjectionCache *cache =
      projectionCache != nullptr ? projectionCache : &localCache;
  std::vector<SurfacePoint> projectedProvenance(
      static_cast<std::size_t>(vertices.rows()));
  for (int i = 0; i < vertices.rows(); ++i) {
    const SurfacePoint seed =
        i < static_cast<int>(constraints.vertexProvenance.size())
            ? constraints.vertexProvenance[static_cast<std::size_t>(i)]
            : SurfacePoint{};
    const auto requiredScope = source_face_scope(constraints, seed.face);
    const bool fixed = contains(constraints.fixedVertices, i);
    const bool feature = contains(constraints.featureVertices, i);
    const auto project_candidate = [&](const Eigen::RowVector3d &candidate) {
      if (constraints.constrainVerticesToProvenanceEntities && seed.valid()) {
        const SurfacePoint entityProjection = project_to_provenance_entity(
            candidate, seed, constraints, *cache);
        if (entityProjection.valid()) {
          return entityProjection;
        }
      }
      return nearest_source_point(candidate, constraints, requiredScope, cache);
    };
    if (fixed) {
      Eigen::RowVector3d constrainedPoint = vertices.row(i);
      if (feature) {
        const SurfaceFeatureProjection featureProjection =
            project_to_feature_curve(constrainedPoint, constraints, i);
        if (featureProjection.valid) {
          constrainedPoint = featureProjection.position;
          params(i) = featureProjection.parameter;
          orderCoordinates(i) = featureProjection.orderCoordinate;
        } else {
          provenanceComplete = false;
        }
      }
      SurfacePoint source = project_candidate(constrainedPoint);
      if (source.valid()) {
        projected.row(i) = source.position.transpose();
      }
      projectedProvenance[static_cast<std::size_t>(i)] = source;
      provenanceComplete =
          provenanceComplete && provenance_is_complete(source, constraints);
      if (requiredScope.has_value()) {
        const auto sourceScope = source_face_scope(constraints, source.face);
        if (!sourceScope.has_value() ||
            sourceScope->component != requiredScope->component) {
          componentOk = false;
        }
        if (!sourceScope.has_value() ||
            sourceScope->sheet != requiredScope->sheet) {
          sheetOk = false;
        }
      }
      continue;
    }
    if (feature) {
      const SurfaceFeatureProjection feature =
          project_to_feature_curve(vertices.row(i), constraints, i);
      if (feature.valid) {
        projected.row(i) = feature.position;
        params(i) = feature.parameter;
        orderCoordinates(i) = feature.orderCoordinate;
      } else {
        provenanceComplete = false;
      }
      projectedProvenance[static_cast<std::size_t>(i)] =
          project_candidate(projected.row(i));
      const SurfacePoint &source =
          projectedProvenance[static_cast<std::size_t>(i)];
      provenanceComplete =
          provenanceComplete && provenance_is_complete(source, constraints);
      if (requiredScope.has_value()) {
        const auto sourceScope = source_face_scope(constraints, source.face);
        if (!sourceScope.has_value() ||
            sourceScope->component != requiredScope->component) {
          componentOk = false;
        }
        if (!sourceScope.has_value() ||
            sourceScope->sheet != requiredScope->sheet) {
          sheetOk = false;
        }
      }
    } else {
      SurfacePoint source = project_candidate(vertices.row(i));
      if (source.valid()) {
        projected.row(i) = source.position.transpose();
      }
      projectedProvenance[static_cast<std::size_t>(i)] = source;
      provenanceComplete =
          provenanceComplete && provenance_is_complete(source, constraints);
      if (requiredScope.has_value()) {
        const auto sourceScope = source_face_scope(constraints, source.face);
        if (!sourceScope.has_value() ||
            sourceScope->component != requiredScope->component) {
          componentOk = false;
        }
        if (!sourceScope.has_value() ||
            sourceScope->sheet != requiredScope->sheet) {
          sheetOk = false;
        }
      }
    }
  }
  std::vector<int> features = constraints.orderedFeatureVertices;
  if (features.empty()) {
    features = constraints.featureVertices;
  }
  std::optional<SurfaceFeatureSequenceKey> previousSequence;
  double previous = -std::numeric_limits<double>::infinity();
  for (const int v : features) {
    if (v >= 0 && v < params.size()) {
      const SurfaceFeatureSequenceKey sequenceId =
          feature_sequence_for_vertex(constraints, v);
      if (!previousSequence.has_value() || sequenceId != previousSequence.value()) {
        previousSequence = sequenceId;
        previous = -std::numeric_limits<double>::infinity();
      }
      if (orderCoordinates(v) + 1.0e-12 < previous) {
        orderOk = false;
      }
      previous = orderCoordinates(v);
    }
  }
  if (featureParameters != nullptr) {
    *featureParameters = params;
  }
  if (ordered != nullptr) {
    *ordered = orderOk;
  }
  if (componentsOk != nullptr) {
    *componentsOk = componentOk;
  }
  if (sheetsOk != nullptr) {
    *sheetsOk = sheetOk;
  }
  if (completeProvenance != nullptr) {
    *completeProvenance = provenanceComplete;
  }
  if (provenance != nullptr) {
    *provenance = std::move(projectedProvenance);
  }
  return projected;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::MatrixXd project_vertices(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints,
    Eigen::VectorXd *featureParameters, bool *ordered, bool *componentsOk,
    std::vector<SurfacePoint> *provenance) {
  return project_vertices(vertices, constraints, featureParameters, ordered,
                          componentsOk, nullptr, nullptr, provenance, nullptr);
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d face_normal(const Eigen::MatrixXd &v,
                                      const Eigen::MatrixXi &q,
                                      const int face) {
  const Eigen::RowVector3d a = v.row(q(face, 0));
  const Eigen::RowVector3d b = v.row(q(face, 1));
  const Eigen::RowVector3d c = v.row(q(face, 2));
  return normalized_or_zero(cross3(b - a, c - a));
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::vector<double> sorted_percentiles(std::vector<double> values) {
  std::sort(values.begin(), values.end());
  return values;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

double percentile(std::vector<double> values, const double p) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const int index = static_cast<int>(
      std::floor(std::clamp(p, 0.0, 1.0) * static_cast<double>(values.size() - 1)));
  return values[static_cast<std::size_t>(index)];
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

double angle_degrees(const Eigen::RowVector3d &a,
                            const Eigen::RowVector3d &b) {
  const Eigen::RowVector3d na = normalized_or_zero(a);
  const Eigen::RowVector3d nb = normalized_or_zero(b);
  const double dot = std::clamp(na.dot(nb), -1.0, 1.0);
  return std::acos(dot) * 180.0 / 3.14159265358979323846;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

FaceChartAuthorityView quad_chart_authority(
    const Eigen::MatrixXi &quads, const int face,
    const SurfaceOptimizationConstraints &constraints,
    const std::size_t provenanceCount) {
  FaceChartAuthorityView result;
  if (constraints.vertexChartAuthority.empty()) {
    return result;
  }
  if (constraints.vertexChartAuthority.size() != provenanceCount ||
      face < 0 || face >= quads.rows()) {
    result.valid = false;
    return result;
  }
  result.vertices.reserve(static_cast<std::size_t>(quads.cols()));
  for (int corner = 0; corner < quads.cols(); ++corner) {
    const int vertex = quads(face, corner);
    if (vertex < 0 ||
        vertex >= static_cast<int>(constraints.vertexChartAuthority.size())) {
      result.valid = false;
      result.vertices.clear();
      return result;
    }
    result.vertices.push_back(
        &constraints.vertexChartAuthority[static_cast<std::size_t>(vertex)]);
  }
  return result;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::optional<SourceProjectionScope> consistent_source_scope(
    const Eigen::MatrixXi &quads, const int face,
    const std::vector<SurfacePoint> &provenance,
    const SurfaceOptimizationConstraints *constraints) {
  if (constraints == nullptr) {
    return std::nullopt;
  }
  const validation::source_authoritative_detail::SourcePointLabelSupport
      labelSupport(&constraints->sourceFaces, constraints->sourceAuthority,
                   &constraints->sourceHardFeatureEdges);
  if (!labelSupport.available()) {
    return std::nullopt;
  }

  std::vector<const SurfacePoint *> points;
  points.reserve(4);
  for (int corner = 0; corner < 4; ++corner) {
    const int vertex = quads(face, corner);
    if (vertex < 0 || vertex >= static_cast<int>(provenance.size())) {
      return std::nullopt;
    }
    const SurfacePoint &point = provenance[static_cast<std::size_t>(vertex)];
    if (labelSupport.supported_faces(point).empty()) {
      return std::nullopt;
    }
    points.push_back(&point);
  }

  const FaceChartAuthorityView authority =
      quad_chart_authority(quads, face, *constraints, provenance.size());
  if (!authority.valid) {
    return std::nullopt;
  }
  const auto resolution = labelSupport.resolve_compatible_chart(
      points, authority.vertices, &provenance,
      &constraints->vertexChartAuthority);
  if (!resolution.valid()) {
    return std::nullopt;
  }

  std::set<SourceProjectionScope> scopes;
  for (const int sourceFace : resolution.chartFaces) {
    const auto scope = source_face_scope(*constraints, sourceFace);
    if (!scope.has_value()) {
      return std::nullopt;
    }
    scopes.insert(*scope);
  }
  if (scopes.size() == 1U) {
    return *scopes.begin();
  }
  if (scopes.empty()) {
    return std::nullopt;
  }
  const auto component = scopes.begin()->component;
  const bool oneComponent = std::all_of(
      scopes.begin(), scopes.end(), [&](const SourceProjectionScope &scope) {
        return scope.component == component;
      });
  if (!oneComponent) {
    return std::nullopt;
  }
  return SourceProjectionScope{component, std::nullopt};
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

SurfacePoint quad_reference_surface_point(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance,
    SourceProjectionCache *projectionCache) {
  Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 4; ++corner) {
    centroid += 0.25 * vertices.row(quads(face, corner));
  }
  const validation::source_authoritative_detail::SourcePointLabelSupport
      labelSupport(&constraints.sourceFaces, constraints.sourceAuthority,
                   &constraints.sourceHardFeatureEdges);
  std::vector<const SurfacePoint *> points;
  points.reserve(4);
  for (int corner = 0; corner < 4; ++corner) {
    const int vertex = quads(face, corner);
    if (vertex < 0 || vertex >= static_cast<int>(provenance.size())) {
      points.clear();
      break;
    }
    points.push_back(&provenance[static_cast<std::size_t>(vertex)]);
  }
  const FaceChartAuthorityView authority = quad_chart_authority(
      quads, face, constraints, provenance.size());
  const auto resolution =
      authority.valid
          ? labelSupport.resolve_compatible_chart(
                points, authority.vertices, &provenance,
                &constraints.vertexChartAuthority)
          : validation::source_authoritative_detail::SourceChartCompatibility{};
  const std::vector<int> &chartFaces = resolution.chartFaces;
  SourceProjectionCache localCache(constraints);
  SourceProjectionCache *cache =
      projectionCache != nullptr ? projectionCache : &localCache;
  SurfacePoint point;
  if (face >= 0 &&
      face < static_cast<int>(constraints.outputQuadSourceFaces.size())) {
    const int authoritativeFace =
        constraints.outputQuadSourceFaces[static_cast<std::size_t>(face)];
    if (authoritativeFace >= 0 &&
        authoritativeFace < constraints.sourceFaces.rows() &&
        (!labelSupport.available() ||
         (resolution.valid() &&
          std::binary_search(chartFaces.begin(), chartFaces.end(),
                             authoritativeFace)))) {
      point = cache->project(centroid, std::vector<int>{authoritativeFace});
      if (point.valid()) {
        return point;
      }
    }
  }
  if (!chartFaces.empty()) {
    point = cache->project(centroid, chartFaces);
  } else {
    return {};
  }
  if (point.valid()) {
    return point;
  }
  for (int corner = 0; corner < 4; ++corner) {
    const int vertex = quads(face, corner);
    if (vertex >= 0 && vertex < static_cast<int>(provenance.size()) &&
        provenance[static_cast<std::size_t>(vertex)].valid()) {
      return provenance[static_cast<std::size_t>(vertex)];
    }
  }
  return {};
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d quad_bilinear_sample(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const double u, const double v) {
  const Eigen::RowVector3d p0 = vertices.row(quads(face, 0));
  const Eigen::RowVector3d p1 = vertices.row(quads(face, 1));
  const Eigen::RowVector3d p2 = vertices.row(quads(face, 2));
  const Eigen::RowVector3d p3 = vertices.row(quads(face, 3));
  return (1.0 - u) * (1.0 - v) * p0 + u * (1.0 - v) * p1 +
         u * v * p2 + (1.0 - u) * v * p3;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::vector<Eigen::Vector3d> triangle_sample_barycentrics() {
  return {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},
          {0.5, 0.5, 0.0}, {0.0, 0.5, 0.5}, {0.5, 0.0, 0.5},
          {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0}};
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::map<std::pair<int, int>, int> quad_edge_incidence(
    const Eigen::MatrixXi &quads) {
  std::map<std::pair<int, int>, int> incidence;
  for (int face = 0; face < quads.rows(); ++face) {
    for (int corner = 0; corner < 4; ++corner) {
      int a = quads(face, corner);
      int b = quads(face, (corner + 1) % 4);
      if (a > b) {
        std::swap(a, b);
      }
      ++incidence[{a, b}];
    }
  }
  return incidence;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::vector<std::set<int>> quad_vertex_neighbors(
    const Eigen::MatrixXi &quads, const int vertexCount) {
  std::vector<std::set<int>> neighbors(static_cast<std::size_t>(vertexCount));
  for (int face = 0; face < quads.rows(); ++face) {
    for (int corner = 0; corner < 4; ++corner) {
      const int a = quads(face, corner);
      const int b = quads(face, (corner + 1) % 4);
      if (a >= 0 && b >= 0 && a < vertexCount && b < vertexCount) {
        neighbors[static_cast<std::size_t>(a)].insert(b);
        neighbors[static_cast<std::size_t>(b)].insert(a);
      }
    }
  }
  return neighbors;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::map<int, std::vector<int>> quad_boundary_neighbors(
    const Eigen::MatrixXi &quads) {
  std::map<int, std::vector<int>> result;
  for (const auto &[edge, count] : quad_edge_incidence(quads)) {
    if (count != 1) {
      continue;
    }
    result[edge.first].push_back(edge.second);
    result[edge.second].push_back(edge.first);
  }
  return result;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

int inferred_boundary_valence_target(
    const Eigen::MatrixXd &vertices, const int vertex,
    const std::vector<int> &boundaryNeighbors) {
  if (vertex < 0 || vertex >= vertices.rows() ||
      boundaryNeighbors.size() != 2U) {
    return 3;
  }
  const Eigen::RowVector3d first =
      vertices.row(boundaryNeighbors[0]) - vertices.row(vertex);
  const Eigen::RowVector3d second =
      vertices.row(boundaryNeighbors[1]) - vertices.row(vertex);
  // Straight boundary samples have two nearly opposite boundary tangents and
  // need one interior edge (valence 3). Geometric corners need no additional
  // boundary-parallel continuation and have target valence 2.
  return angle_degrees(first, second) < 150.0 ? 2 : 3;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d normalized_pullback(
    const Eigen::RowVector3d &raw,
    const Eigen::RowVector3d &normalizedGradient) {
  const double length = raw.norm();
  if (length <= 1.0e-20) {
    return Eigen::RowVector3d::Zero();
  }
  const Eigen::RowVector3d unit = raw / length;
  return (normalizedGradient -
          unit * unit.dot(normalizedGradient)) /
         length;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

Eigen::RowVector3d feature_order_coordinate_gradient(
    const SurfaceFeatureProjection &projection) {
  if (!projection.valid || projection.localParameter <= 1.0e-12 ||
      projection.localParameter >= 1.0 - 1.0e-12) {
    return Eigen::RowVector3d::Zero();
  }
  const double squaredLength = projection.tangent.squaredNorm();
  if (squaredLength <= 1.0e-20) {
    return Eigen::RowVector3d::Zero();
  }
  return projection.tangent / squaredLength;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

std::vector<int> ordered_feature_vertices(
    const SurfaceOptimizationConstraints &constraints) {
  if (!constraints.orderedFeatureVertices.empty()) {
    return constraints.orderedFeatureVertices;
  }
  return constraints.featureVertices;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

double feature_order_energy(
    const Eigen::MatrixXd &vertices,
    const SurfaceOptimizationConstraints &constraints) {
  const std::vector<int> features = ordered_feature_vertices(constraints);
  std::optional<SurfaceFeatureSequenceKey> previousSequence;
  int previousVertex = -1;
  SurfaceFeatureProjection previousProjection;
  double energy = 0.0;
  for (const int vertex : features) {
    if (vertex < 0 || vertex >= vertices.rows()) {
      continue;
    }
    const SurfaceFeatureSequenceKey sequence =
        feature_sequence_for_vertex(constraints, vertex);
    const SurfaceFeatureProjection projection =
        project_to_feature_curve(vertices.row(vertex), constraints, vertex);
    if (!projection.valid) {
      previousSequence.reset();
      previousVertex = -1;
      previousProjection = {};
      continue;
    }
    if (previousSequence.has_value() && sequence == previousSequence.value() &&
        previousVertex >= 0) {
      const double violation =
          previousProjection.orderCoordinate - projection.orderCoordinate;
      if (violation > 0.0) {
        energy += violation * violation;
      }
    }
    previousSequence = sequence;
    previousVertex = vertex;
    previousProjection = projection;
  }
  return energy;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

SurfaceOptimizationGradient zero_surface_optimization_gradient(
    const int vertexCount, const int dimensions) {
  SurfaceOptimizationGradient gradient;
  gradient.surface = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.normal = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.field = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.orthogonality = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.size = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.valenceShape = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.feature = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  gradient.total = Eigen::MatrixXd::Zero(vertexCount, dimensions);
  return gradient;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

void add_edge_length_gradient(Eigen::MatrixXd &gradient,
                                     const int firstVertex,
                                     const int secondVertex,
                                     const Eigen::RowVector3d &edge,
                                     const double derivativeByLength) {
  const double length = edge.norm();
  if (length <= 1.0e-20 || derivativeByLength == 0.0) {
    return;
  }
  const Eigen::RowVector3d edgeGradient =
      derivativeByLength * edge / length;
  gradient.row(firstVertex) -= edgeGradient;
  gradient.row(secondVertex) += edgeGradient;
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry::surface_optimizer_detail {

void zero_fixed_gradient_rows(
    SurfaceOptimizationGradient &gradient,
    const SurfaceOptimizationConstraints &constraints) {
  for (const int vertex : constraints.fixedVertices) {
    if (vertex < 0 || vertex >= gradient.total.rows()) {
      continue;
    }
    gradient.surface.row(vertex).setZero();
    gradient.normal.row(vertex).setZero();
    gradient.field.row(vertex).setZero();
    gradient.orthogonality.row(vertex).setZero();
    gradient.size.row(vertex).setZero();
    gradient.valenceShape.row(vertex).setZero();
    gradient.feature.row(vertex).setZero();
    gradient.total.row(vertex).setZero();
  }
}

} // namespace directional::geometry::surface_optimizer_detail

namespace directional::geometry {

std::complex<double> degree_four_average(
    const std::vector<double> &anglesRadians,
    const std::vector<double> &connectionAnglesRadians,
    const std::vector<double> &weights) {
  std::complex<double> sum(0.0, 0.0);
  for (int i = 0; i < static_cast<int>(anglesRadians.size()); ++i) {
    const double connection =
        i < static_cast<int>(connectionAnglesRadians.size())
            ? connectionAnglesRadians[static_cast<std::size_t>(i)]
            : 0.0;
    const double weight =
        i < static_cast<int>(weights.size()) ? weights[static_cast<std::size_t>(i)]
                                             : 1.0;
    const double angle = 4.0 * (anglesRadians[static_cast<std::size_t>(i)] +
                                connection);
    sum += weight * std::complex<double>(std::cos(angle), std::sin(angle));
  }
  const double n = std::abs(sum);
  if (n <= 0.0) {
    return {1.0, 0.0};
  }
  return sum / n;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationEnergy evaluate_surface_optimization_energy_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache) {
  using namespace surface_optimizer_detail;
  if (!source_optimization_has_complete_authority(constraints)) {
    throw std::invalid_argument(
        "Surface optimization requires complete source authority.");
  }
  SurfaceOptimizationEnergy energy;
  std::vector<SurfacePoint> provenance;
  project_vertices(vertices, constraints, nullptr, nullptr, nullptr, nullptr,
                   nullptr, &provenance, &projectionCache);
  for (int i = 0; i < vertices.rows(); ++i) {
    const Eigen::RowVector3d p = vertices.row(i);
    const SurfacePoint &sourcePoint = provenance[static_cast<std::size_t>(i)];
    if (!provenance_is_complete(sourcePoint, constraints)) {
      throw std::runtime_error(
          "Source-authoritative surface optimization projection failed.");
    }
    energy.surface +=
        (p - sourcePoint.position.transpose()).squaredNorm();
    if (contains(constraints.featureVertices, i)) {
      const SurfaceFeatureProjection feature =
          project_to_feature_curve(p, constraints, i);
      if (feature.valid) {
        energy.feature += (p - feature.position).squaredNorm();
      }
    }
  }
  energy.feature += feature_order_energy(vertices, constraints);

  std::vector<int> valence(vertices.rows(), 0);
  for (int f = 0; f < quads.rows(); ++f) {
    const Eigen::RowVector3d n = face_normal(vertices, quads, f);
    SurfacePoint faceSource;
    std::vector<SurfacePoint> facePoints;
    for (int c = 0; c < 4; ++c) {
      const int vertex = quads(f, c);
      if (vertex >= 0 && vertex < static_cast<int>(provenance.size())) {
        facePoints.push_back(provenance[static_cast<std::size_t>(vertex)]);
      }
    }
    if (!facePoints.empty()) {
      faceSource = facePoints.front();
    }
    const Eigen::RowVector3d sourceNormal =
        local_source_normal(constraints, faceSource, f);
    energy.normal +=
        std::pow(1.0 - std::abs(n.dot(normalized_or_zero(sourceNormal))), 2.0);
    std::array<double, 4> faceLengths = {};
    for (int c = 0; c < 4; ++c) {
      ++valence[static_cast<std::size_t>(quads(f, c))];
      const Eigen::RowVector3d a = vertices.row(quads(f, c));
      const Eigen::RowVector3d b = vertices.row(quads(f, (c + 1) % 4));
      const Eigen::RowVector3d e = b - a;
      const double length = e.norm();
      faceLengths[static_cast<std::size_t>(c)] = length;
      const int firstVertex = quads(f, c);
      const int secondVertex = quads(f, (c + 1) % 4);
      const double target = effective_edge_target_size(
          constraints, provenance[static_cast<std::size_t>(firstVertex)],
          provenance[static_cast<std::size_t>(secondVertex)], firstVertex,
          secondVertex, length, options.targetSize);
      const double ratio = length / std::max(1.0e-12, target);
      energy.size += std::pow(ratio - 1.0, 2.0);
      const LocalSourceCross cross =
          local_source_cross(constraints, faceSource, f);
      const Eigen::RowVector3d dir = tangent_direction(e, sourceNormal);
      const double align =
          std::max(std::abs(dir.dot(cross.x)), std::abs(dir.dot(cross.y)));
      energy.field += std::pow(1.0 - align, 2.0);
      const Eigen::RowVector3d prev = vertices.row(quads(f, (c + 3) % 4)) - a;
      const Eigen::RowVector3d next = vertices.row(quads(f, (c + 1) % 4)) - a;
      const double cosCorner =
          std::abs(normalized_or_zero(prev).dot(normalized_or_zero(next)));
      energy.orthogonality += cosCorner * cosCorner;
    }
    const auto [minLength, maxLength] =
        std::minmax_element(faceLengths.begin(), faceLengths.end());
    energy.valenceShape +=
        std::pow((*maxLength / std::max(1.0e-12, *minLength)) - 1.0, 2.0);
  }
  for (const int v : valence) {
    energy.valenceShape += std::pow(static_cast<double>(v - 4), 2.0);
  }
  energy.total = options.weights.surface * energy.surface +
                 options.weights.normal * energy.normal +
                 options.weights.field * energy.field +
                 options.weights.orthogonality * energy.orthogonality +
                 options.weights.size * energy.size +
                 options.weights.valenceShape * energy.valenceShape +
                 options.weights.feature * energy.feature;
  return energy;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationEnergy evaluate_surface_optimization_energy(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  surface_optimizer_detail::SourceProjectionCache projectionCache(constraints);
  return evaluate_surface_optimization_energy_cached(
      vertices, quads, constraints, options, projectionCache);
}

} // namespace directional::geometry

namespace directional::geometry {

double signed_scaled_jacobian(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads, const int face,
    const Eigen::RowVector3d &sourceNormal) {
  double minimum = std::numeric_limits<double>::infinity();
  for (int c = 0; c < 4; ++c) {
    const Eigen::RowVector3d p = vertices.row(quads(face, c));
    const Eigen::RowVector3d e0 =
        vertices.row(quads(face, (c + 1) % 4)) - p;
    const Eigen::RowVector3d e1 =
        vertices.row(quads(face, (c + 3) % 4)) - p;
    const double denom = std::max(1.0e-20, e0.norm() * e1.norm());
    const double signedCorner =
        surface_optimizer_detail::cross3(e0, e1)
            .dot(surface_optimizer_detail::normalized_or_zero(sourceNormal)) /
        denom;
    minimum = std::min(minimum, signedCorner);
  }
  return minimum == std::numeric_limits<double>::infinity() ? 0.0 : minimum;
}

} // namespace directional::geometry

namespace directional::geometry {

std::vector<unsigned char> source_boundary_vertex_mask(
    const Eigen::MatrixXi &sourceFaces, const int sourceVertexCount) {
  std::map<std::pair<int, int>, int> edgeIncidence;
  for (int face = 0; face < sourceFaces.rows(); ++face) {
    if (sourceFaces.cols() != 3) {
      break;
    }
    for (int corner = 0; corner < 3; ++corner) {
      int first = sourceFaces(face, corner);
      int second = sourceFaces(face, (corner + 1) % 3);
      if (first > second) {
        std::swap(first, second);
      }
      ++edgeIncidence[{first, second}];
    }
  }

  std::vector<unsigned char> boundary(
      static_cast<std::size_t>(std::max(0, sourceVertexCount)), 0);
  for (const auto &[edge, incidence] : edgeIncidence) {
    if (incidence != 1) {
      continue;
    }
    for (const int vertex : {edge.first, edge.second}) {
      if (vertex >= 0 && vertex < sourceVertexCount) {
        boundary[static_cast<std::size_t>(vertex)] = 1;
      }
    }
  }
  return boundary;
}

} // namespace directional::geometry

namespace directional::geometry {

void fill_required_singularity_valence_targets(
    const Eigen::MatrixXd &sourceVertices, const Eigen::MatrixXi &sourceFaces,
    const Eigen::VectorXi &singularCycles,
    const Eigen::VectorXi &singularIndices,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<SurfacePoint> &outputProvenance,
    SurfaceOptimizationConstraints &constraints) {
  constraints.requiredSingularityValenceTargets.clear();
  const std::vector<unsigned char> sourceBoundary =
      source_boundary_vertex_mask(sourceFaces, sourceVertices.rows());
  const int count = std::min(singularCycles.size(), singularIndices.size());
  for (int index = 0; index < count; ++index) {
    const int sourceVertex = singularCycles(index);
    if (sourceVertex < 0 || sourceVertex >= sourceVertices.rows()) {
      continue;
    }
    // Cross-field index-to-valence conversion differs at the source boundary.
    // Interior poles have target valence 4-indexNumerator. A regular boundary
    // sample has valence three, so boundary poles use 3-indexNumerator. This
    // prevents ordinary 90-degree boundary corners (index +1) from being
    // incorrectly forced to interior valence three instead of corner valence two.
    const bool boundarySingularity =
        sourceVertex < static_cast<int>(sourceBoundary.size()) &&
        sourceBoundary[static_cast<std::size_t>(sourceVertex)] != 0;
    const int regularValence = boundarySingularity ? 3 : 4;
    const int targetValence = regularValence - singularIndices(index);
    if (targetValence < 2 || targetValence > 8) {
      continue;
    }
    int bestOutput = -1;
    double bestDistance = std::numeric_limits<double>::infinity();
    for (int output = 0; output < outputVertices.rows(); ++output) {
      if (output >= static_cast<int>(outputProvenance.size())) {
        continue;
      }
      const SurfacePoint &point =
          outputProvenance[static_cast<std::size_t>(output)];
      if (!point.valid() || point.face < 0 || point.face >= sourceFaces.rows()) {
        continue;
      }
      bool incident = false;
      for (int corner = 0; corner < 3; ++corner) {
        incident = incident || sourceFaces(point.face, corner) == sourceVertex;
      }
      if (!incident) {
        continue;
      }
      const double distance =
          (outputVertices.row(output) - sourceVertices.row(sourceVertex))
              .squaredNorm();
      if (distance < bestDistance) {
        bestDistance = distance;
        bestOutput = output;
      }
    }
    if (bestOutput < 0) {
      continue;
    }
    const auto existing =
        constraints.requiredSingularityValenceTargets.find(bestOutput);
    if (existing == constraints.requiredSingularityValenceTargets.end() ||
        existing->second == targetValence) {
      constraints.requiredSingularityValenceTargets[bestOutput] = targetValence;
    } else {
      // Two authoritative singularities cannot consume one output pole with
      // incompatible valences. Record an impossible target so validation fails
      // closed instead of silently dropping one requirement.
      constraints.requiredSingularityValenceTargets[bestOutput] = 0;
    }
  }
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceQuadQualityMetrics evaluate_surface_quad_quality(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const int face, const Eigen::RowVector3d &sourceNormal) {
  using namespace surface_optimizer_detail;
  SurfaceQuadQualityMetrics quality;
  const Eigen::RowVector3d normal = normalized_or_zero(sourceNormal);
  std::array<double, 4> lengths{};
  quality.minimumAngleDegrees = std::numeric_limits<double>::infinity();
  quality.maximumAngleDegrees = 0.0;
  for (int corner = 0; corner < 4; ++corner) {
    const Eigen::RowVector3d point = vertices.row(quads(face, corner));
    const Eigen::RowVector3d next =
        vertices.row(quads(face, (corner + 1) % 4)) - point;
    const Eigen::RowVector3d previous =
        vertices.row(quads(face, (corner + 3) % 4)) - point;
    lengths[static_cast<std::size_t>(corner)] = next.norm();
    const double signedCorner = cross3(next, previous).dot(normal);
    const double cornerScale = next.norm() * previous.norm();
    quality.convex = quality.convex && cornerScale > 1.0e-15 &&
                     signedCorner / cornerScale > 1.0e-12;
    const double angle = angle_degrees(previous, next);
    quality.minimumAngleDegrees =
        std::min(quality.minimumAngleDegrees, angle);
    quality.maximumAngleDegrees =
        std::max(quality.maximumAngleDegrees, angle);
  }
  if (!std::isfinite(quality.minimumAngleDegrees)) {
    quality.minimumAngleDegrees = 0.0;
  }
  const auto [minimumLength, maximumLength] =
      std::minmax_element(lengths.begin(), lengths.end());
  quality.aspectRatio =
      *maximumLength / std::max(1.0e-12, *minimumLength);
  quality.signedScaledJacobian =
      signed_scaled_jacobian(vertices, quads, face, normal);

  const Eigen::RowVector3d p0 = vertices.row(quads(face, 0));
  const Eigen::RowVector3d p1 = vertices.row(quads(face, 1));
  const Eigen::RowVector3d p2 = vertices.row(quads(face, 2));
  const Eigen::RowVector3d p3 = vertices.row(quads(face, 3));
  const Eigen::RowVector3d n012 = normalized_or_zero(cross3(p1 - p0, p2 - p0));
  const Eigen::RowVector3d n023 = normalized_or_zero(cross3(p2 - p0, p3 - p0));
  const Eigen::RowVector3d n013 = normalized_or_zero(cross3(p1 - p0, p3 - p0));
  const Eigen::RowVector3d n123 = normalized_or_zero(cross3(p2 - p1, p3 - p1));
  const double diagonal02 = angle_degrees(n012, n023);
  const double diagonal13 = angle_degrees(n013, n123);
  quality.warpageDegrees = std::max(diagonal02, diagonal13);
  return quality;
}

} // namespace directional::geometry

namespace directional::geometry {

bool local_orientation_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints *constraints,
    const std::vector<SurfacePoint> *vertexProvenance,
    surface_optimizer_detail::SourceProjectionCache *projectionCache) {
  const std::vector<SurfacePoint> *authoritativeProvenance =
      vertexProvenance != nullptr
          ? vertexProvenance
          : (constraints != nullptr ? &constraints->vertexProvenance : nullptr);
  for (int f = 0; f < quads.rows(); ++f) {
    Eigen::RowVector3d normal(0.0, 0.0, 1.0);
    if (constraints != nullptr) {
      const SurfacePoint reference =
          authoritativeProvenance != nullptr
              ? surface_optimizer_detail::quad_reference_surface_point(
                    vertices, quads, f, *constraints,
                    *authoritativeProvenance, projectionCache)
              : SurfacePoint{};
      normal = surface_optimizer_detail::local_source_normal(
          *constraints, reference, f);
    }
    const SurfaceQuadQualityMetrics quality =
        evaluate_surface_quad_quality(vertices, quads, f, normal);
    if (!quality.convex || quality.signedScaledJacobian <= 1.0e-12) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry

namespace directional::geometry {

validation::SourceAuthoritativeMeshValidatorOptions
make_source_authoritative_validator_options(
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance) {
  validation::SourceAuthoritativeMeshValidatorOptions validatorOptions;
  validatorOptions.sourceVertices = &constraints.sourceVertices;
  validatorOptions.sourceFaces = &constraints.sourceFaces;
  validatorOptions.sourceAuthority = constraints.sourceAuthority;
  validatorOptions.vertexProvenance = &provenance;
  validatorOptions.vertexChartAuthority =
      constraints.vertexChartAuthority.empty()
          ? nullptr
          : &constraints.vertexChartAuthority;
  validatorOptions.outputQuadSourceFaces =
      &constraints.outputQuadSourceFaces;
  validatorOptions.sourceHardFeatureEdges =
      constraints.sourceHardFeatureEdges;
  validatorOptions.authoritativeBoundaryEdges =
      constraints.authoritativeBoundaryEdges;
  validatorOptions.authoritativeBoundaryLoops =
      constraints.authoritativeBoundaryLoops;
  if (validatorOptions.authoritativeBoundaryLoops.empty() &&
      !constraints.authoritativeBoundaryLoop.empty()) {
    validatorOptions.authoritativeBoundaryLoops.push_back(
        constraints.authoritativeBoundaryLoop);
  }
  validatorOptions.authoritativeFeatureRails =
      constraints.authoritativeFeatureRails;
  validatorOptions.expectedFeatureRailCount =
      constraints.requiredFeatureRailCount;
  validatorOptions.requireBoundaryAuthority = true;
  validatorOptions.requireFeatureRailAuthority =
      constraints.featureRailAuthorityProvided;
  validatorOptions.requireLocalSheetCompatibility = true;
  return validatorOptions;
}

} // namespace directional::geometry

namespace directional::geometry {

bool source_optimization_has_complete_authority(
    const SurfaceOptimizationConstraints &constraints) {
  if (constraints.sourceAuthority == nullptr ||
      constraints.sourceVertices.rows() <= 0 ||
      constraints.sourceVertices.cols() != 3 ||
      constraints.sourceFaces.rows() <= 0 || constraints.sourceFaces.cols() != 3 ||
      !constraints.sourceAuthority->matches_source_faces(
          constraints.sourceFaces,
          static_cast<std::size_t>(constraints.sourceVertices.rows()))) {
    return false;
  }
  for (int face = 0; face < constraints.sourceFaces.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int vertex = constraints.sourceFaces(face, corner);
      if (vertex < 0 || vertex >= constraints.sourceVertices.rows()) {
        return false;
      }
    }
  }
  return true;
}

} // namespace directional::geometry

namespace directional::geometry {

bool source_authoritative_hard_invariants_valid(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const std::vector<SurfacePoint> &provenance,
    std::vector<validation::MeshValidationIssue> *issues) {
  const auto validation = validation::validate_source_authoritative_surface_mesh(
      vertices, quads,
      make_source_authoritative_validator_options(constraints, provenance));
  if (issues != nullptr) {
    *issues = validation.issues;
  }
  return validation.accepted;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationGradient evaluate_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache) {
  using namespace surface_optimizer_detail;
  if (!source_optimization_has_complete_authority(constraints)) {
    throw std::invalid_argument(
        "Surface optimization requires complete source authority.");
  }
  SurfaceOptimizationGradient gradient =
      zero_surface_optimization_gradient(vertices.rows(), vertices.cols());

  std::vector<SurfacePoint> provenance;
  project_vertices(vertices, constraints, nullptr, nullptr, nullptr, nullptr,
                   nullptr, &provenance, &projectionCache);

  std::vector<SurfaceFeatureProjection> featureProjections(
      static_cast<std::size_t>(vertices.rows()));
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    const Eigen::RowVector3d point = vertices.row(vertex);
    const SurfacePoint &sourcePoint =
        provenance[static_cast<std::size_t>(vertex)];
    if (!provenance_is_complete(sourcePoint, constraints)) {
      throw std::runtime_error(
          "Source-authoritative surface optimization projection failed.");
    }
    gradient.surface.row(vertex) +=
        2.0 * (point - sourcePoint.position.transpose());

    if (!contains(constraints.featureVertices, vertex)) {
      continue;
    }
    SurfaceFeatureProjection projection =
        project_to_feature_curve(point, constraints, vertex);
    featureProjections[static_cast<std::size_t>(vertex)] = projection;
    if (projection.valid) {
      gradient.feature.row(vertex) +=
          2.0 * (point - projection.position);
    }
  }

  const std::vector<int> orderedFeatures =
      ordered_feature_vertices(constraints);
  std::optional<SurfaceFeatureSequenceKey> previousSequence;
  int previousVertex = -1;
  SurfaceFeatureProjection previousProjection;
  for (const int vertex : orderedFeatures) {
    if (vertex < 0 || vertex >= vertices.rows()) {
      continue;
    }
    const SurfaceFeatureSequenceKey sequence =
        feature_sequence_for_vertex(constraints, vertex);
    SurfaceFeatureProjection projection =
        featureProjections[static_cast<std::size_t>(vertex)];
    if (!projection.valid) {
      projection = project_to_feature_curve(vertices.row(vertex), constraints,
                                            vertex);
      featureProjections[static_cast<std::size_t>(vertex)] = projection;
    }
    if (!projection.valid) {
      previousSequence.reset();
      previousVertex = -1;
      previousProjection = {};
      continue;
    }
    if (previousSequence.has_value() && sequence == previousSequence.value() &&
        previousVertex >= 0) {
      const double violation =
          previousProjection.orderCoordinate - projection.orderCoordinate;
      if (violation > 0.0) {
        gradient.feature.row(previousVertex) +=
            2.0 * violation *
            feature_order_coordinate_gradient(previousProjection);
        gradient.feature.row(vertex) -=
            2.0 * violation * feature_order_coordinate_gradient(projection);
      }
    }
    previousSequence = sequence;
    previousVertex = vertex;
    previousProjection = projection;
  }

  for (int face = 0; face < quads.rows(); ++face) {
    std::array<int, 4> faceVertices = {};
    std::array<Eigen::RowVector3d, 4> faceEdges = {};
    std::array<double, 4> faceLengths = {};
    for (int corner = 0; corner < 4; ++corner) {
      faceVertices[static_cast<std::size_t>(corner)] = quads(face, corner);
      const int first = quads(face, corner);
      const int second = quads(face, (corner + 1) % 4);
      faceEdges[static_cast<std::size_t>(corner)] =
          vertices.row(second) - vertices.row(first);
      faceLengths[static_cast<std::size_t>(corner)] =
          faceEdges[static_cast<std::size_t>(corner)].norm();
    }

    SurfacePoint faceSource;
    int faceSourceVertex = -1;
    for (const int vertex : faceVertices) {
      if (vertex >= 0 && vertex < static_cast<int>(provenance.size()) &&
          provenance[static_cast<std::size_t>(vertex)].valid()) {
        faceSource = provenance[static_cast<std::size_t>(vertex)];
        faceSourceVertex = vertex;
        break;
      }
    }
    const Eigen::RowVector3d sourceNormal = normalized_or_zero(
        local_source_normal(constraints, faceSource, face));
    const LocalSourceCross sourceCross =
        local_source_cross(constraints, faceSource, face);

    const int aIndex = faceVertices[0];
    const int bIndex = faceVertices[1];
    const int cIndex = faceVertices[2];
    const Eigen::RowVector3d edgeAB =
        vertices.row(bIndex) - vertices.row(aIndex);
    const Eigen::RowVector3d edgeAC =
        vertices.row(cIndex) - vertices.row(aIndex);
    const Eigen::RowVector3d rawNormal = cross3(edgeAB, edgeAC);
    const double rawNormalLength = rawNormal.norm();
    if (rawNormalLength > 1.0e-20 && sourceNormal.squaredNorm() > 0.0) {
      const Eigen::RowVector3d faceNormal = rawNormal / rawNormalLength;
      const double dot = faceNormal.dot(sourceNormal);
      const double sign = dot >= 0.0 ? 1.0 : -1.0;
      const Eigen::RowVector3d normalGradient =
          2.0 * (std::abs(dot) - 1.0) * sign * sourceNormal;
      const Eigen::RowVector3d rawNormalGradient =
          normalized_pullback(rawNormal, normalGradient);
      const Eigen::RowVector3d edgeABGradient =
          cross3(edgeAC, rawNormalGradient);
      const Eigen::RowVector3d edgeACGradient =
          cross3(rawNormalGradient, edgeAB);
      gradient.normal.row(aIndex) -= edgeABGradient + edgeACGradient;
      gradient.normal.row(bIndex) += edgeABGradient;
      gradient.normal.row(cIndex) += edgeACGradient;
    }

    if (faceSourceVertex >= 0 && rawNormalLength > 1.0e-20) {
      const Eigen::RowVector3d faceNormal = rawNormal / rawNormalLength;
      const double eps = std::max(1.0e-8, options.finiteDifferenceStep);
      const auto requiredScope = source_face_scope(constraints, faceSource.face);
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        Eigen::RowVector3d plusPoint = vertices.row(faceSourceVertex);
        Eigen::RowVector3d minusPoint = vertices.row(faceSourceVertex);
        plusPoint(coordinate) += eps;
        minusPoint(coordinate) -= eps;
        const SurfacePoint plusSource = nearest_source_point(
            plusPoint, constraints, requiredScope, &projectionCache);
        const SurfacePoint minusSource = nearest_source_point(
            minusPoint, constraints, requiredScope, &projectionCache);
        const Eigen::RowVector3d plusNormal = normalized_or_zero(
            local_source_normal(constraints, plusSource, face));
        const Eigen::RowVector3d minusNormal = normalized_or_zero(
            local_source_normal(constraints, minusSource, face));
        const double plusDot = faceNormal.dot(plusNormal);
        const double minusDot = faceNormal.dot(minusNormal);
        const double plusEnergy =
            std::pow(1.0 - std::abs(plusDot), 2.0);
        const double minusEnergy =
            std::pow(1.0 - std::abs(minusDot), 2.0);
        gradient.normal(faceSourceVertex, coordinate) +=
            (plusEnergy - minusEnergy) / (2.0 * eps);
      }
    }

    for (int corner = 0; corner < 4; ++corner) {
      const int first = faceVertices[static_cast<std::size_t>(corner)];
      const int second =
          faceVertices[static_cast<std::size_t>((corner + 1) % 4)];
      const Eigen::RowVector3d edge =
          faceEdges[static_cast<std::size_t>(corner)];
      const double length = faceLengths[static_cast<std::size_t>(corner)];
      if (length > 1.0e-20) {
        const SurfacePoint &firstPoint =
            provenance[static_cast<std::size_t>(first)];
        const SurfacePoint &secondPoint =
            provenance[static_cast<std::size_t>(second)];
        const double firstTarget = local_target_size(
            constraints, firstPoint, first, options.targetSize);
        const double secondTarget = local_target_size(
            constraints, secondPoint, second, options.targetSize);
        const double rawTarget = 0.5 * (firstTarget + secondTarget);
        const double target = effective_edge_target_size(
            constraints, firstPoint, secondPoint, first, second, length,
            options.targetSize);
        const double safeTarget = std::max(1.0e-12, target);
        const double ratio = length / safeTarget;
        add_edge_length_gradient(gradient.size, first, second, edge,
                                 2.0 * (ratio - 1.0) / safeTarget);
        const bool immutableOverride =
            immutable_rail_edge(constraints, first, second) &&
            std::abs(target - length) <=
                1.0e-12 * std::max({1.0, target, length}) &&
            std::abs(rawTarget - target) >
                1.0e-12 * std::max({1.0, rawTarget, target});
        if (!immutableOverride) {
          const double derivativeByTarget =
              -2.0 * (ratio - 1.0) * length /
              (safeTarget * safeTarget);
          gradient.size.row(first) +=
              0.5 * derivativeByTarget *
              local_target_size_gradient(constraints, firstPoint);
          gradient.size.row(second) +=
              0.5 * derivativeByTarget *
              local_target_size_gradient(constraints, secondPoint);
        }

        const Eigen::RowVector3d projectedEdge =
            edge - edge.dot(sourceNormal) * sourceNormal;
        const double projectedLength = projectedEdge.norm();
        if (projectedLength > 1.0e-20) {
          const Eigen::RowVector3d direction = projectedEdge / projectedLength;
          const double dotX = direction.dot(sourceCross.x);
          const double dotY = direction.dot(sourceCross.y);
          const bool chooseX = std::abs(dotX) >= std::abs(dotY);
          const double selectedDot = chooseX ? dotX : dotY;
          const Eigen::RowVector3d selectedAxis =
              chooseX ? sourceCross.x : sourceCross.y;
          const double selectedSign = selectedDot >= 0.0 ? 1.0 : -1.0;
          const double alignment = std::abs(selectedDot);
          const Eigen::RowVector3d directionGradient =
              2.0 * (alignment - 1.0) * selectedSign * selectedAxis;
          const Eigen::RowVector3d projectedGradient =
              normalized_pullback(projectedEdge, directionGradient);
          const Eigen::RowVector3d edgeGradient =
              projectedGradient -
              projectedGradient.dot(sourceNormal) * sourceNormal;
          gradient.field.row(first) -= edgeGradient;
          gradient.field.row(second) += edgeGradient;
        }
      }

      const int center = faceVertices[static_cast<std::size_t>(corner)];
      const int previous =
          faceVertices[static_cast<std::size_t>((corner + 3) % 4)];
      const int next =
          faceVertices[static_cast<std::size_t>((corner + 1) % 4)];
      const Eigen::RowVector3d previousEdge =
          vertices.row(previous) - vertices.row(center);
      const Eigen::RowVector3d nextEdge =
          vertices.row(next) - vertices.row(center);
      const double previousLength = previousEdge.norm();
      const double nextLength = nextEdge.norm();
      if (previousLength > 1.0e-20 && nextLength > 1.0e-20) {
        const Eigen::RowVector3d previousDirection =
            previousEdge / previousLength;
        const Eigen::RowVector3d nextDirection = nextEdge / nextLength;
        const double cosine = previousDirection.dot(nextDirection);
        const Eigen::RowVector3d previousGradient =
            2.0 * cosine *
            (nextDirection - cosine * previousDirection) / previousLength;
        const Eigen::RowVector3d nextGradient =
            2.0 * cosine *
            (previousDirection - cosine * nextDirection) / nextLength;
        gradient.orthogonality.row(previous) += previousGradient;
        gradient.orthogonality.row(next) += nextGradient;
        gradient.orthogonality.row(center) -=
            previousGradient + nextGradient;
      }
    }

    if (faceSourceVertex >= 0) {
      const double eps = std::max(1.0e-8, options.finiteDifferenceStep);
      const auto requiredScope = source_face_scope(constraints, faceSource.face);
      const auto fieldEnergyForSource = [&](const SurfacePoint &source) {
        const LocalSourceCross cross =
            local_source_cross(constraints, source, face);
        const Eigen::RowVector3d fieldNormal =
            local_source_normal(constraints, source, face);
        double value = 0.0;
        for (int edgeIndex = 0; edgeIndex < 4; ++edgeIndex) {
          const Eigen::RowVector3d edge =
              faceEdges[static_cast<std::size_t>(edgeIndex)];
          const Eigen::RowVector3d direction =
              tangent_direction(edge, fieldNormal);
          if (direction.squaredNorm() == 0.0) {
            continue;
          }
          const double alignment =
              std::max(std::abs(direction.dot(cross.x)),
                       std::abs(direction.dot(cross.y)));
          value += std::pow(1.0 - alignment, 2.0);
        }
        return value;
      };
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        Eigen::RowVector3d plusPoint = vertices.row(faceSourceVertex);
        Eigen::RowVector3d minusPoint = vertices.row(faceSourceVertex);
        plusPoint(coordinate) += eps;
        minusPoint(coordinate) -= eps;
        const SurfacePoint plusSource = nearest_source_point(
            plusPoint, constraints, requiredScope, &projectionCache);
        const SurfacePoint minusSource = nearest_source_point(
            minusPoint, constraints, requiredScope, &projectionCache);
        const double plusEnergy = fieldEnergyForSource(plusSource);
        const double minusEnergy = fieldEnergyForSource(minusSource);
        gradient.field(faceSourceVertex, coordinate) +=
            (plusEnergy - minusEnergy) / (2.0 * eps);
      }
    }

    int minimumEdge = 0;
    int maximumEdge = 0;
    for (int edge = 1; edge < 4; ++edge) {
      if (faceLengths[static_cast<std::size_t>(edge)] <
          faceLengths[static_cast<std::size_t>(minimumEdge)]) {
        minimumEdge = edge;
      }
      if (faceLengths[static_cast<std::size_t>(edge)] >
          faceLengths[static_cast<std::size_t>(maximumEdge)]) {
        maximumEdge = edge;
      }
    }
    const double minimumLength =
        faceLengths[static_cast<std::size_t>(minimumEdge)];
    const double maximumLength =
        faceLengths[static_cast<std::size_t>(maximumEdge)];
    if (minimumLength > 1.0e-20 && maximumEdge != minimumEdge) {
      const double ratio = maximumLength / minimumLength;
      const double residual = ratio - 1.0;
      const int minimumFirst =
          faceVertices[static_cast<std::size_t>(minimumEdge)];
      const int minimumSecond =
          faceVertices[static_cast<std::size_t>((minimumEdge + 1) % 4)];
      const int maximumFirst =
          faceVertices[static_cast<std::size_t>(maximumEdge)];
      const int maximumSecond =
          faceVertices[static_cast<std::size_t>((maximumEdge + 1) % 4)];
      add_edge_length_gradient(
          gradient.valenceShape, maximumFirst, maximumSecond,
          faceEdges[static_cast<std::size_t>(maximumEdge)],
          2.0 * residual / minimumLength);
      add_edge_length_gradient(
          gradient.valenceShape, minimumFirst, minimumSecond,
          faceEdges[static_cast<std::size_t>(minimumEdge)],
          -2.0 * residual * maximumLength /
              (minimumLength * minimumLength));
    }
    // The valence/pole penalty is topological for fixed connectivity. Its
    // positional derivative is exactly zero; the shape portion above carries
    // the differentiable contribution of this combined energy.
  }

  gradient.total = options.weights.surface * gradient.surface +
                   options.weights.normal * gradient.normal +
                   options.weights.field * gradient.field +
                   options.weights.orthogonality * gradient.orthogonality +
                   options.weights.size * gradient.size +
                   options.weights.valenceShape * gradient.valenceShape +
                   options.weights.feature * gradient.feature;
  zero_fixed_gradient_rows(gradient, constraints);
  return gradient;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationGradient evaluate_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  surface_optimizer_detail::SourceProjectionCache projectionCache(constraints);
  return evaluate_surface_optimization_gradient_cached(
      vertices, quads, constraints, options, projectionCache);
}

} // namespace directional::geometry

namespace directional::geometry {

Eigen::MatrixXd finite_difference_surface_optimization_gradient_cached(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options,
    surface_optimizer_detail::SourceProjectionCache &projectionCache) {
  Eigen::MatrixXd gradient = Eigen::MatrixXd::Zero(vertices.rows(), vertices.cols());
  const double eps = std::max(1.0e-9, options.finiteDifferenceStep);
  for (int r = 0; r < vertices.rows(); ++r) {
    if (surface_optimizer_detail::contains(constraints.fixedVertices, r)) {
      continue;
    }
    for (int c = 0; c < vertices.cols(); ++c) {
      Eigen::MatrixXd plus = vertices;
      Eigen::MatrixXd minus = vertices;
      plus(r, c) += eps;
      minus(r, c) -= eps;
      const double ePlus =
          evaluate_surface_optimization_energy_cached(
              plus, quads, constraints, options, projectionCache)
              .total;
      const double eMinus =
          evaluate_surface_optimization_energy_cached(
              minus, quads, constraints, options, projectionCache)
              .total;
      gradient(r, c) = (ePlus - eMinus) / (2.0 * eps);
    }
  }
  return gradient;
}

} // namespace directional::geometry

namespace directional::geometry {

Eigen::MatrixXd finite_difference_surface_optimization_gradient(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  surface_optimizer_detail::SourceProjectionCache projectionCache(constraints);
  return finite_difference_surface_optimization_gradient_cached(
      vertices, quads, constraints, options, projectionCache);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationResult optimize_projected_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  using namespace surface_optimizer_detail;
  SurfaceOptimizationResult result;
  result.vertices = initialVertices;
  result.quads = quads;
  result.topologyHash = topology_hash(quads);
  if (!source_optimization_has_complete_authority(constraints)) {
    result.vertexProvenance = constraints.vertexProvenance;
    result.projectionStayedOnComponents = false;
    result.projectionStayedOnSheets = false;
    result.projectionHasCompleteProvenance = false;
    result.rolledBackToInput = true;
    result.lastHardInvariantIssues.push_back(
        {validation::MeshValidationFailureCode::MissingSourceAuthority});
    return result;
  }
  SourceProjectionCache projectionCache(constraints);
  Eigen::VectorXd featureParameters;
  result.vertices = project_vertices(result.vertices, constraints, &featureParameters,
                                     &result.featureParametersOrdered,
                                     &result.projectionStayedOnComponents,
                                     &result.projectionStayedOnSheets,
                                     &result.projectionHasCompleteProvenance,
                                     &result.vertexProvenance, &projectionCache);
  result.sourceTriangleProjectionUsed =
      constraints.sourceVertices.rows() > 0 && constraints.sourceFaces.rows() > 0 &&
      std::all_of(result.vertexProvenance.begin(), result.vertexProvenance.end(),
                  [](const SurfacePoint &point) {
                    return point.valid() && point.face >= 0;
                  });
  if (!result.projectionStayedOnComponents || !result.projectionStayedOnSheets ||
      !result.projectionHasCompleteProvenance ||
      !result.sourceTriangleProjectionUsed) {
    result.vertices = initialVertices;
    result.rolledBackToInput = true;
    result.lastHardInvariantIssues.push_back(
        {validation::MeshValidationFailureCode::InvalidProvenance});
    return result;
  }
  SurfaceOptimizationEnergy current =
      evaluate_surface_optimization_energy_cached(
          result.vertices, quads, constraints, options, projectionCache);
  result.initialEnergy = current;
  result.finalEnergy = current;

  for (int iteration = 0; iteration < options.maxIterations; ++iteration) {
    const SurfaceOptimizationGradient derivative =
        evaluate_surface_optimization_gradient_cached(
            result.vertices, quads, constraints, options, projectionCache);
    Eigen::MatrixXd direction = derivative.total;
    double maximumRowNorm = 0.0;
    for (int vertex = 0; vertex < direction.rows(); ++vertex) {
      maximumRowNorm = std::max(maximumRowNorm, direction.row(vertex).norm());
    }
    result.maximumRawGradientRowNorm =
        std::max(result.maximumRawGradientRowNorm, maximumRowNorm);
    const double maximumStep =
        std::max(1.0e-12,
                 options.maxStepTargetFraction *
                     std::max(1.0e-12, options.targetSize));
    if (maximumRowNorm > maximumStep) {
      direction *= maximumStep / maximumRowNorm;
      ++result.trustRegionScaleCount;
    }
    const double descentDirectionalDerivative =
        derivative.total.cwiseProduct(direction).sum();
    result.directGradientUsed = true;
    ++result.directGradientEvaluationCount;
    bool accepted = false;
    double acceptedAlpha = 0.0;
    SurfaceOptimizationEnergy acceptedEnergy = current;
    const int trialLimit = std::clamp(
        options.maxLineSearchTrials, 0,
        static_cast<int>(options.lineSearchSteps.size()));
    for (int trialIndex = 0; trialIndex < trialLimit; ++trialIndex) {
      const double alpha =
          options.lineSearchSteps[static_cast<std::size_t>(trialIndex)];
      ++result.lineSearchTrialCount;
      bool ordered = true;
      bool componentsOk = true;
      bool sheetsOk = true;
      bool provenanceComplete = true;
      std::vector<SurfacePoint> trialProvenance;
      const Eigen::MatrixXd trial = project_vertices(
          result.vertices - alpha * direction, constraints, nullptr, &ordered,
          &componentsOk, &sheetsOk, &provenanceComplete, &trialProvenance,
          &projectionCache);
      if (!ordered || !componentsOk || !sheetsOk || !provenanceComplete) {
        ++result.lineSearchRejectionCount;
        ++result.projectionConstraintRejectionCount;
        continue;
      }
      if (!local_orientation_valid(trial, quads, &constraints,
                                   &trialProvenance, &projectionCache)) {
        ++result.lineSearchRejectionCount;
        ++result.orientationRejectionCount;
        continue;
      }
      if (options.enforceSourceAuthoritativeHardInvariants &&
          !source_authoritative_hard_invariants_valid(
              trial, quads, constraints, trialProvenance,
              &result.lastHardInvariantIssues)) {
        ++result.lineSearchRejectionCount;
        ++result.hardInvariantRejectionCount;
        continue;
      }
      const SurfaceOptimizationEnergy trialEnergy =
          evaluate_surface_optimization_energy_cached(
              trial, quads, constraints, options, projectionCache);
      if (armijo_sufficient_decrease(current.total, trialEnergy.total, alpha,
                                     descentDirectionalDerivative,
                                     options.armijo)) {
        result.vertices = trial;
        accepted = true;
        acceptedAlpha = alpha;
        acceptedEnergy = trialEnergy;
        result.featureParametersOrdered =
            result.featureParametersOrdered && ordered;
        result.projectionStayedOnComponents =
            result.projectionStayedOnComponents && componentsOk;
        result.projectionStayedOnSheets =
            result.projectionStayedOnSheets && sheetsOk;
        result.projectionHasCompleteProvenance =
            result.projectionHasCompleteProvenance && provenanceComplete;
        project_vertices(result.vertices, constraints, nullptr, nullptr, nullptr,
                         nullptr, nullptr, &result.vertexProvenance,
                         &projectionCache);
        break;
      }
      ++result.lineSearchRejectionCount;
      ++result.armijoRejectionCount;
    }
    SurfaceOptimizationIteration record;
    record.iteration = iteration;
    record.accepted = accepted;
    record.alpha = acceptedAlpha;
    record.energy = acceptedEnergy;
    result.iterations.push_back(record);
    if (!accepted) {
      break;
    }
    const double drop = current.total - acceptedEnergy.total;
    if (acceptedEnergy.total > current.total + 1.0e-12) {
      result.monotonicEnergy = false;
    }
    current = acceptedEnergy;
    result.finalEnergy = current;
    if (drop / std::max(1.0, current.total) < options.tolerance) {
      break;
    }
  }
  result.topologyHashFixed = result.topologyHash == topology_hash(quads);
  result.sourceBvhBuildCount = projectionCache.bvh.has_value() ? 1U : 0U;
  result.projectionQueryCount = projectionCache.queryCount;
  result.finalEnergy = current;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationResult optimize_source_authoritative_surface_mesh(
    const Eigen::MatrixXd &initialVertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  if (!source_optimization_has_complete_authority(constraints)) {
    SurfaceOptimizationResult rejected;
    rejected.vertices = initialVertices;
    rejected.quads = quads;
    rejected.vertexProvenance = constraints.vertexProvenance;
    rejected.projectionStayedOnComponents = false;
    rejected.projectionStayedOnSheets = false;
    rejected.projectionHasCompleteProvenance = false;
    rejected.rolledBackToInput = true;
    rejected.lastHardInvariantIssues.push_back(
        {validation::MeshValidationFailureCode::MissingSourceAuthority});
    return rejected;
  }
  SurfaceOptimizationOptions strictOptions = options;
  strictOptions.enforceSourceAuthoritativeHardInvariants = true;
  return optimize_projected_surface_mesh(initialVertices, quads, constraints,
                                         strictOptions);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceFinalValidationReport validate_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options,
    const double optimizerSeconds, const double endToEndSeconds) {
  using namespace surface_optimizer_detail;
  SurfaceFinalValidationReport report;
  if (!source_optimization_has_complete_authority(constraints)) {
    report.strictValidationUsed = true;
    report.provenanceValidationUsed = true;
    report.sourceAuthoritativeValidationUsed = false;
    report.localSheetCompatibilityPassed = false;
    report.provenanceFailureCount = 1;
    report.strictValidationIssues.push_back(
        {validation::MeshValidationFailureCode::MissingSourceAuthority});
    report.accepted = false;
    return report;
  }
  std::vector<double> quadToSourceErrors;
  std::vector<double> sourceToOutputErrors;
  std::vector<double> normalErrors;
  std::vector<double> featureErrors;
  std::vector<double> featureTangentErrors;
  std::vector<double> fieldErrors;
  std::vector<double> sizeRatios;
  std::vector<double> angles;
  std::vector<double> warpages;
  std::vector<double> aspects;
  std::vector<double> jacobians;
  const std::vector<SurfacePoint> &provenance = optimization.vertexProvenance;
  SourceProjectionCache sourceProjection(constraints);
  const validation::source_authoritative_detail::SourcePointLabelSupport
      sourceLabelSupport(&constraints.sourceFaces, constraints.sourceAuthority,
                         &constraints.sourceHardFeatureEdges);

  // Sample the complete output faces, not only their vertices. Bilinear 3x3
  // sampling observes bowed edges and warped interiors while remaining
  // deterministic and inexpensive for the P21 quality gate.
  constexpr std::array<double, 3> quadSamples = {0.0, 0.5, 1.0};
  if (constraints.sourceVertices.rows() > 0 &&
      constraints.sourceFaces.rows() > 0) {
  for (int face = 0; face < quads.rows(); ++face) {
    std::vector<const SurfacePoint *> facePoints;
    facePoints.reserve(4);
    for (int corner = 0; corner < 4; ++corner) {
      const int vertex = quads(face, corner);
      if (vertex < 0 || vertex >= static_cast<int>(provenance.size())) {
        facePoints.clear();
        break;
      }
      facePoints.push_back(&provenance[static_cast<std::size_t>(vertex)]);
    }
    const FaceChartAuthorityView authority = quad_chart_authority(
        quads, face, constraints, provenance.size());
    const std::vector<int> chartFaces =
        authority.valid
            ? sourceLabelSupport.compatible_chart_faces(facePoints,
                                                        authority.vertices,
                                                        &provenance,
                                                        &constraints.vertexChartAuthority)
            : std::vector<int>{};
    const auto sourceScope =
        consistent_source_scope(quads, face, provenance, &constraints);
    for (const double u : quadSamples) {
      for (const double v : quadSamples) {
        const Eigen::RowVector3d sample =
            quad_bilinear_sample(vertices, quads, face, u, v);
        const SurfacePoint sourcePoint =
            !chartFaces.empty()
                ? sourceProjection.project(sample, chartFaces)
                : nearest_source_point(sample, constraints, sourceScope,
                                       &sourceProjection);
        if (!sourcePoint.valid()) {
          quadToSourceErrors.push_back(
              std::numeric_limits<double>::infinity());
          continue;
        }
        const double target = local_target_size(
            constraints, sourcePoint, 0, options.targetSize);
        quadToSourceErrors.push_back(
            std::sqrt(sourcePoint.squaredDistance) /
            std::max(1.0e-12, target));
      }
    }
  }
  }

  if (quadToSourceErrors.empty()) {
    quadToSourceErrors.push_back(std::numeric_limits<double>::infinity());
  }

  // Sample every source triangle in the reverse direction. Output triangles
  // inherit component/sheet authority from their quad provenance so nearby
  // disconnected or folded sheets cannot hide a coverage hole.
  if (constraints.sourceVertices.rows() > 0 &&
      constraints.sourceFaces.rows() > 0 && quads.rows() > 0) {
    OutputProjectionCache outputProjection(vertices, quads, provenance,
                                           &constraints);
    const std::vector<Eigen::Vector3d> barycentrics =
        triangle_sample_barycentrics();
    for (int face = 0; face < constraints.sourceFaces.rows(); ++face) {
      const auto sourceScope = source_face_scope(constraints, face);
      for (const Eigen::Vector3d &barycentric : barycentrics) {
        SurfacePoint sourcePoint;
        sourcePoint.face = face;
        sourcePoint.barycentric = barycentric;
        sourcePoint.position = source_point_position(
                                   constraints.sourceVertices,
                                   constraints.sourceFaces, sourcePoint)
                                   .transpose();
        sourcePoint.squaredDistance = 0.0;
        const SurfacePoint outputPoint = outputProjection.project(
            sourcePoint.position.transpose(), sourceScope);
        if (!outputPoint.valid()) {
          sourceToOutputErrors.push_back(
              std::numeric_limits<double>::infinity());
          continue;
        }
        const double target = local_target_size(
            constraints, sourcePoint, 0, options.targetSize);
        sourceToOutputErrors.push_back(
            std::sqrt(outputPoint.squaredDistance) /
            std::max(1.0e-12, target));
      }
    }
  } else if (constraints.sourceVertices.rows() > 0 &&
             constraints.sourceFaces.rows() > 0 && quads.rows() == 0) {
    sourceToOutputErrors.push_back(std::numeric_limits<double>::infinity());
  }

  for (const int vertex : constraints.featureVertices) {
    Eigen::RowVector3d start;
    Eigen::RowVector3d end;
    if (vertex < 0 || vertex >= vertices.rows() ||
        !find_feature_interval(constraints, vertex, &start, &end)) {
      continue;
    }
    const Eigen::RowVector3d projected =
        project_to_interval(vertices.row(vertex), start, end);
    featureErrors.push_back((vertices.row(vertex) - projected).norm());
    const Eigen::RowVector3d railTangent = normalized_or_zero(end - start);
    double bestTangentError = std::numeric_limits<double>::infinity();
    for (int face = 0; face < quads.rows(); ++face) {
      for (int corner = 0; corner < 4; ++corner) {
        if (quads(face, corner) != vertex) {
          continue;
        }
        for (const int offset : {-1, 1}) {
          const int adjacent = quads(face, (corner + offset + 4) % 4);
          if (adjacent < 0 || adjacent >= vertices.rows() ||
              !contains(constraints.featureVertices, adjacent) ||
              feature_sequence_for_vertex(constraints, adjacent) !=
                  feature_sequence_for_vertex(constraints, vertex)) {
            continue;
          }
          const double error = angle_degrees(
              railTangent, vertices.row(adjacent) - vertices.row(vertex));
          bestTangentError =
              std::min(bestTangentError, std::min(error, 180.0 - error));
        }
      }
    }
    if (std::isfinite(bestTangentError)) {
      featureTangentErrors.push_back(bestTangentError);
    }
  }

  for (int face = 0; face < quads.rows(); ++face) {
    const SurfacePoint faceSource = quad_reference_surface_point(
        vertices, quads, face, constraints, provenance, &sourceProjection);
    const Eigen::RowVector3d sourceNormal =
        local_source_normal(constraints, faceSource, face);
    normalErrors.push_back(
        angle_degrees(face_normal(vertices, quads, face), sourceNormal));
    const SurfaceQuadQualityMetrics quality =
        evaluate_surface_quad_quality(vertices, quads, face, sourceNormal);
    if (!quality.convex) {
      ++report.nonConvex;
    }
    angles.push_back(quality.minimumAngleDegrees);
    angles.push_back(quality.maximumAngleDegrees);
    warpages.push_back(quality.warpageDegrees);
    aspects.push_back(quality.aspectRatio);
    jacobians.push_back(quality.signedScaledJacobian);

    for (int corner = 0; corner < 4; ++corner) {
      const int firstVertex = quads(face, corner);
      const int secondVertex = quads(face, (corner + 1) % 4);
      const Eigen::RowVector3d first = vertices.row(firstVertex);
      const Eigen::RowVector3d second = vertices.row(secondVertex);
      const Eigen::RowVector3d edge = second - first;
      const SurfacePoint firstPoint =
          firstVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(firstVertex)]
              : SurfacePoint{};
      const SurfacePoint secondPoint =
          secondVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(secondVertex)]
              : SurfacePoint{};
      const double target = effective_edge_target_size(
          constraints, firstPoint, secondPoint, firstVertex, secondVertex,
          edge.norm(), options.targetSize);
      sizeRatios.push_back(edge.norm() / std::max(1.0e-12, target));
      const auto sourceScope = source_face_scope(constraints, firstPoint.face);
      const SurfacePoint edgeSource = nearest_source_point(
          0.5 * (first + second), constraints, sourceScope, &sourceProjection);
      const double alignment = best_source_field_alignment(
          edge, constraints, edgeSource.valid() ? edgeSource : faceSource,
          face, &firstPoint, &secondPoint);
      fieldErrors.push_back(
          std::acos(alignment) * 180.0 / 3.14159265358979323846);
    }
  }

  report.quadToSourceSampleCount = quadToSourceErrors.size();
  report.sourceToOutputSampleCount = sourceToOutputErrors.size();
  report.quadToSourceP95 = percentile(quadToSourceErrors, 0.95);
  report.quadToSourceMax =
      quadToSourceErrors.empty()
          ? 0.0
          : *std::max_element(quadToSourceErrors.begin(),
                              quadToSourceErrors.end());
  report.sourceToOutputP95 = percentile(sourceToOutputErrors, 0.95);
  report.sourceToOutputMax =
      sourceToOutputErrors.empty()
          ? 0.0
          : *std::max_element(sourceToOutputErrors.begin(),
                              sourceToOutputErrors.end());
  report.surfaceP95 =
      std::max(report.quadToSourceP95, report.sourceToOutputP95);
  report.surfaceMax =
      std::max(report.quadToSourceMax, report.sourceToOutputMax);
  report.normalP95Degrees = percentile(normalErrors, 0.95);
  report.featureP95 = percentile(featureErrors, 0.95);
  report.featureMax =
      featureErrors.empty()
          ? 0.0
          : *std::max_element(featureErrors.begin(), featureErrors.end());
  report.featureTangentP95Degrees = percentile(featureTangentErrors, 0.95);
  report.fieldMedianDegrees = percentile(fieldErrors, 0.50);
  report.fieldP95Degrees = percentile(fieldErrors, 0.95);
  report.sizeP5 = percentile(sizeRatios, 0.05);
  report.sizeP95 = percentile(sizeRatios, 0.95);
  report.angleMinDegrees =
      angles.empty() ? 90.0 : *std::min_element(angles.begin(), angles.end());
  report.angleMaxDegrees =
      angles.empty() ? 90.0 : *std::max_element(angles.begin(), angles.end());
  report.angleP5Degrees = percentile(angles, 0.05);
  report.angleP95Degrees = percentile(angles, 0.95);
  report.warpageP95Degrees = percentile(warpages, 0.95);
  report.warpageMaxDegrees =
      warpages.empty() ? 0.0 : *std::max_element(warpages.begin(), warpages.end());
  report.aspectP95 = percentile(aspects, 0.95);
  report.aspectP99 = percentile(aspects, 0.99);
  report.scaledJacobianMin =
      jacobians.empty() ? 1.0
                        : *std::min_element(jacobians.begin(), jacobians.end());
  report.scaledJacobianP5 = percentile(jacobians, 0.05);

  const std::vector<std::set<int>> neighbors =
      quad_vertex_neighbors(quads, vertices.rows());
  const std::map<int, std::vector<int>> boundary =
      quad_boundary_neighbors(quads);
  for (const auto &[vertex, boundaryNeighbors] : boundary) {
    const auto explicitTarget = constraints.boundaryValenceTargets.find(vertex);
    const int target =
        explicitTarget != constraints.boundaryValenceTargets.end()
            ? explicitTarget->second
            : inferred_boundary_valence_target(vertices, vertex,
                                                boundaryNeighbors);
    ++report.boundaryValenceTargetCount;
    if (vertex < 0 || vertex >= static_cast<int>(neighbors.size()) ||
        static_cast<int>(neighbors[static_cast<std::size_t>(vertex)].size()) !=
            target) {
      ++report.boundaryValenceMismatchCount;
    }
  }
  for (const auto &[vertex, target] :
       constraints.requiredSingularityValenceTargets) {
    ++report.requiredSingularityValenceTargetCount;
    if (vertex < 0 || vertex >= static_cast<int>(neighbors.size()) ||
        static_cast<int>(neighbors[static_cast<std::size_t>(vertex)].size()) !=
            target) {
      ++report.requiredSingularityValenceMismatchCount;
    }
  }

  report.strictValidationUsed = true;
  report.provenanceValidationUsed = true;
  report.authoritativeBoundaryUsed =
      !constraints.authoritativeBoundaryEdges.empty() ||
      !constraints.authoritativeBoundaryLoop.empty() ||
      !constraints.authoritativeBoundaryLoops.empty();
  report.authoritativeFeatureRailsUsed =
      constraints.featureRailAuthorityProvided;
  std::vector<validation::MeshValidationIssue> validationIssues;
  const auto sourceValidation =
      validation::validate_source_authoritative_surface_mesh(
          vertices, quads,
          make_source_authoritative_validator_options(constraints, provenance));
  const bool strictValidationAccepted = sourceValidation.accepted;
  validationIssues = sourceValidation.issues;
  report.sourceAuthoritativeValidationUsed = sourceValidation.sourceAuthorityUsed;
  report.spatialAccelerationUsed = sourceValidation.spatialAccelerationUsed;
  report.orderedBoundaryCyclesPassed =
      sourceValidation.orderedBoundaryCyclesPassed;
  report.authoritativeFeatureRailsPassed = sourceValidation.featureRailsPassed;
  report.localSheetCompatibilityPassed =
      sourceValidation.localSheetCompatibilityPassed;
  for (const auto &issue : validationIssues) {
    if (issue.code ==
        validation::MeshValidationFailureCode::GeometricVertexOnUnsplitEdge) {
      ++report.tJunctions;
    } else if (issue.code ==
                   validation::MeshValidationFailureCode::ThreeSidedInteriorEdge ||
               issue.code ==
                   validation::MeshValidationFailureCode::OneSidedInteriorEdge) {
      ++report.nonManifold;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::ZeroAreaFace) {
      ++report.degenerate;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::FlippedFace) {
      ++report.inverted;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::SelfIntersectingFace) {
      ++report.selfIntersecting;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::DuplicateFace) {
      ++report.duplicateFaceCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::BowTieVertex) {
      ++report.bowTieVertexCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::ComponentMerge) {
      ++report.connectedComponentMismatchCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::ChangedEulerCharacteristic) {
      ++report.eulerCharacteristicMismatchCount;
    } else if (issue.code ==
                   validation::MeshValidationFailureCode::ChangedBoundaryLoop ||
               issue.code ==
                   validation::MeshValidationFailureCode::MissingBoundaryAuthority ||
               issue.code ==
                   validation::MeshValidationFailureCode::WrongBoundaryEdge) {
      ++report.boundaryCycleMismatchCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::MissingFeatureRail) {
      ++report.featureRailMismatchCount;
    } else if (issue.code ==
                   validation::MeshValidationFailureCode::MissingProvenance ||
               issue.code ==
                   validation::MeshValidationFailureCode::MissingSourceAuthority ||
               issue.code ==
                   validation::MeshValidationFailureCode::InvalidProvenance ||
               issue.code ==
                   validation::MeshValidationFailureCode::SourceComponentMismatch ||
               issue.code ==
                   validation::MeshValidationFailureCode::SourceSheetMismatch ||
               issue.code ==
                   validation::MeshValidationFailureCode::SourcePositionMismatch) {
      ++report.provenanceFailureCount;
    } else if (issue.code ==
               validation::MeshValidationFailureCode::LocalSheetMismatch) {
      ++report.localSheetMismatchCount;
    }
  }
  report.strictValidationIssues = validationIssues;
  report.missingFeatureRailIds = constraints.missingFeatureRailIds;
  report.topologyHashFixed = optimization.topologyHashFixed;
  report.featureParametersOrdered = optimization.featureParametersOrdered;
  report.projectionStayedOnComponents =
      optimization.projectionStayedOnComponents;
  report.optimizerTimeWithinGate =
      optimizerSeconds <=
      options.maxOptimizerTimeRatio * std::max(1.0e-12, endToEndSeconds);
  report.accepted =
      strictValidationAccepted &&
      report.quadToSourceP95 <= 0.15 && report.quadToSourceMax <= 0.50 &&
      report.sourceToOutputP95 <= 0.15 && report.sourceToOutputMax <= 0.50 &&
      report.normalP95Degrees <= 15.0 &&
      report.fieldMedianDegrees <= 7.5 && report.fieldP95Degrees <= 15.0 &&
      report.sizeP5 >= 0.50 && report.sizeP95 <= 2.00 &&
      report.angleP5Degrees >= 35.0 && report.angleP95Degrees <= 145.0 &&
      report.warpageP95Degrees <= 30.0 && report.warpageMaxDegrees <= 60.0 &&
      report.aspectP95 <= 4.0 && report.aspectP99 <= 8.0 &&
      report.scaledJacobianMin > 0.0 && report.scaledJacobianP5 >= 0.20 &&
      report.nonConvex == 0 && report.boundaryValenceMismatchCount == 0 &&
      report.requiredSingularityValenceMismatchCount == 0 &&
      report.tJunctions == 0 && report.nonManifold == 0 &&
      report.degenerate == 0 && report.inverted == 0 &&
      report.selfIntersecting == 0 && report.topologyHashFixed &&
      report.featureParametersOrdered && report.projectionStayedOnComponents &&
      (!options.enforceOptimizerTimeGate || report.optimizerTimeWithinGate);
  return report;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceFinalValidationReport validate_source_authoritative_final_surface_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationResult &optimization,
    const SurfaceOptimizationOptions &options,
    const double optimizerSeconds, const double endToEndSeconds) {
  if (!source_optimization_has_complete_authority(constraints)) {
    SurfaceFinalValidationReport rejected;
    rejected.strictValidationUsed = true;
    rejected.provenanceValidationUsed = true;
    rejected.sourceAuthoritativeValidationUsed = false;
    rejected.localSheetCompatibilityPassed = false;
    rejected.provenanceFailureCount = 1;
    rejected.strictValidationIssues.push_back(
        {validation::MeshValidationFailureCode::MissingSourceAuthority});
    rejected.accepted = false;
    return rejected;
  }
  return validate_final_surface_mesh(vertices, quads, constraints, optimization,
                                     options, optimizerSeconds,
                                     endToEndSeconds);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceOptimizationOverlay make_surface_optimization_overlay(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const SurfaceOptimizationConstraints &constraints,
    const SurfaceOptimizationOptions &options) {
  using namespace surface_optimizer_detail;
  if (!source_optimization_has_complete_authority(constraints)) {
    throw std::invalid_argument(
        "Surface optimization overlay requires complete source authority.");
  }
  SurfaceOptimizationOverlay overlay;
  overlay.wireframeStarts.resize(4 * quads.rows(), 3);
  overlay.wireframeEnds.resize(4 * quads.rows(), 3);
  overlay.shadedVertices = vertices;
  overlay.surfaceError = Eigen::VectorXd::Zero(vertices.rows());
  overlay.normalError = Eigen::VectorXd::Zero(quads.rows());
  overlay.fieldAlignmentError = Eigen::VectorXd::Zero(4 * quads.rows());
  overlay.sizeRatio = Eigen::VectorXd::Zero(4 * quads.rows());
  overlay.poleValence = Eigen::VectorXi::Zero(vertices.rows());
  overlay.targetValence = Eigen::VectorXi::Constant(vertices.rows(), 4);
  overlay.valenceError = Eigen::VectorXi::Zero(vertices.rows());

  std::vector<SurfacePoint> provenance;
  SourceProjectionCache sourceProjection(constraints);
  project_vertices(vertices, constraints, nullptr, nullptr, nullptr, nullptr,
                   nullptr, &provenance, &sourceProjection);
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    const SurfacePoint point =
        vertex < static_cast<int>(provenance.size())
            ? provenance[static_cast<std::size_t>(vertex)]
            : nearest_source_point(vertices.row(vertex), constraints);
    if (point.valid()) {
      const double target =
          local_target_size(constraints, point, vertex, options.targetSize);
      overlay.surfaceError(vertex) =
          (vertices.row(vertex) - point.position.transpose()).norm() /
          std::max(1.0e-12, target);
    }
  }

  for (int face = 0; face < quads.rows(); ++face) {
    const SurfacePoint faceSource = quad_reference_surface_point(
        vertices, quads, face, constraints, provenance, &sourceProjection);
    overlay.normalError(face) = angle_degrees(
        face_normal(vertices, quads, face),
        local_source_normal(constraints, faceSource, face));
    for (int corner = 0; corner < 4; ++corner) {
      const int row = 4 * face + corner;
      const int firstVertex = quads(face, corner);
      const int secondVertex = quads(face, (corner + 1) % 4);
      const Eigen::RowVector3d first = vertices.row(firstVertex);
      const Eigen::RowVector3d second = vertices.row(secondVertex);
      overlay.wireframeStarts.row(row) = first;
      overlay.wireframeEnds.row(row) = second;
      const SurfacePoint firstPoint =
          firstVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(firstVertex)]
              : SurfacePoint{};
      const SurfacePoint secondPoint =
          secondVertex < static_cast<int>(provenance.size())
              ? provenance[static_cast<std::size_t>(secondVertex)]
              : SurfacePoint{};
      const double target = effective_edge_target_size(
          constraints, firstPoint, secondPoint, firstVertex, secondVertex,
          (second - first).norm(), options.targetSize);
      overlay.sizeRatio(row) =
          (second - first).norm() / std::max(1.0e-12, target);

      const auto sourceScope = source_face_scope(constraints, firstPoint.face);
      const SurfacePoint edgeSource = nearest_source_point(
          0.5 * (first + second), constraints, sourceScope, &sourceProjection);
      const double alignment = best_source_field_alignment(
          second - first, constraints,
          edgeSource.valid() ? edgeSource : faceSource, face, &firstPoint,
          &secondPoint);
      overlay.fieldAlignmentError(row) =
          std::acos(alignment) * 180.0 / 3.14159265358979323846;
    }
  }

  const std::vector<std::set<int>> overlayNeighbors =
      quad_vertex_neighbors(quads, vertices.rows());
  for (int vertex = 0; vertex < vertices.rows(); ++vertex) {
    overlay.poleValence(vertex) = static_cast<int>(
        overlayNeighbors[static_cast<std::size_t>(vertex)].size());
  }

  const std::map<int, std::vector<int>> boundary =
      quad_boundary_neighbors(quads);
  for (const auto &[vertex, boundaryNeighbors] : boundary) {
    const auto explicitTarget = constraints.boundaryValenceTargets.find(vertex);
    overlay.targetValence(vertex) =
        explicitTarget != constraints.boundaryValenceTargets.end()
            ? explicitTarget->second
            : inferred_boundary_valence_target(vertices, vertex,
                                                boundaryNeighbors);
  }
  for (const auto &[vertex, target] :
       constraints.requiredSingularityValenceTargets) {
    if (vertex >= 0 && vertex < overlay.targetValence.size()) {
      overlay.targetValence(vertex) = target;
    }
  }
  overlay.valenceError = overlay.poleValence - overlay.targetValence;

  const int sourceSampleCount = constraints.sourceVertices.rows();
  overlay.sourceToOutputError = Eigen::VectorXd::Zero(sourceSampleCount);
  if (sourceSampleCount > 0 && quads.rows() > 0) {
    OutputProjectionCache outputProjection(vertices, quads, provenance,
                                           &constraints);
    for (int source = 0; source < sourceSampleCount; ++source) {
      const Eigen::RowVector3d position = constraints.sourceVertices.row(source);
      std::optional<SourceProjectionScope> sourceScope;
      SurfacePoint sourcePoint;
      if (constraints.sourceVertices.rows() > 0 &&
          constraints.sourceFaces.rows() > 0) {
        for (int face = 0; face < constraints.sourceFaces.rows(); ++face) {
          for (int corner = 0; corner < 3; ++corner) {
            if (constraints.sourceFaces(face, corner) != source) {
              continue;
            }
            sourcePoint.face = face;
            sourcePoint.barycentric.setZero();
            sourcePoint.barycentric(corner) = 1.0;
            sourcePoint.position = position.transpose();
            sourceScope = source_face_scope(constraints, face);
            break;
          }
          if (sourcePoint.valid()) {
            break;
          }
        }
      }
      const SurfacePoint projected =
          outputProjection.project(position, sourceScope);
      if (projected.valid()) {
        const double target = sourcePoint.valid()
                                  ? local_target_size(constraints, sourcePoint,
                                                      source, options.targetSize)
                                  : options.targetSize;
        overlay.sourceToOutputError(source) =
            std::sqrt(projected.squaredDistance) /
            std::max(1.0e-12, target);
      } else {
        overlay.sourceToOutputError(source) =
            std::numeric_limits<double>::infinity();
      }
    }
  }
  return overlay;
}

} // namespace directional::geometry
