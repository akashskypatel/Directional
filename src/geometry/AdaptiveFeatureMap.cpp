#include <directional/geometry/AdaptiveFeatureMap.h>

namespace directional::geometry::adaptive_feature_detail {

double radians_to_degrees(const double radians) {
  return radians * 180.0 / pi;
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

double degrees_to_radians(const double degrees) {
  return degrees * pi / 180.0;
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

double smoothstep(const double value, const double low,
                         const double high) {
  if (high <= low) {
    return value >= high ? 1.0 : 0.0;
  }
  const double t = std::clamp((value - low) / (high - low), 0.0, 1.0);
  return t * t * (3.0 - 2.0 * t);
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

Eigen::RowVector3d row3(const Eigen::MatrixXd &vertices,
                               const int vertex) {
  return {vertices(vertex, 0), vertices(vertex, 1), vertices(vertex, 2)};
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

Eigen::RowVector3d cross3(const Eigen::RowVector3d &a,
                                 const Eigen::RowVector3d &b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

Eigen::RowVector3d face_normal(const Eigen::MatrixXd &vertices,
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

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

std::uint64_t edge_hash(const std::pair<int, int> &edge) {
  std::uint64_t hash = 1469598103934665603ULL;
  hash ^= static_cast<std::uint64_t>(edge.first);
  hash *= 1099511628211ULL;
  hash ^= static_cast<std::uint64_t>(edge.second);
  hash *= 1099511628211ULL;
  return hash;
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

double percentile(std::vector<double> values, const double q) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const std::size_t index = static_cast<std::size_t>(std::round(
      std::clamp(q, 0.0, 1.0) * static_cast<double>(values.size() - 1)));
  return values[index];
}

} // namespace directional::geometry::adaptive_feature_detail

namespace directional::geometry::adaptive_feature_detail {

std::vector<double>
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

} // namespace directional::geometry::adaptive_feature_detail
