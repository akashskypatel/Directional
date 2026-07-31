#include <directional/geometry/SurfacePoint.h>

namespace directional::geometry::detail {

Eigen::Vector3d closest_point_on_triangle_barycentric(
    const Eigen::Vector3d &point, const Eigen::Vector3d &a,
    const Eigen::Vector3d &b, const Eigen::Vector3d &c) {
  const Eigen::Vector3d ab = b - a;
  const Eigen::Vector3d ac = c - a;
  const Eigen::Vector3d ap = point - a;
  const double d1 = ab.dot(ap);
  const double d2 = ac.dot(ap);
  if (d1 <= 0.0 && d2 <= 0.0) {
    return {1.0, 0.0, 0.0};
  }

  const Eigen::Vector3d bp = point - b;
  const double d3 = ab.dot(bp);
  const double d4 = ac.dot(bp);
  if (d3 >= 0.0 && d4 <= d3) {
    return {0.0, 1.0, 0.0};
  }

  const double vc = d1 * d4 - d3 * d2;
  if (vc <= 0.0 && d1 >= 0.0 && d3 <= 0.0) {
    const double v = d1 / (d1 - d3);
    return {1.0 - v, v, 0.0};
  }

  const Eigen::Vector3d cp = point - c;
  const double d5 = ab.dot(cp);
  const double d6 = ac.dot(cp);
  if (d6 >= 0.0 && d5 <= d6) {
    return {0.0, 0.0, 1.0};
  }

  const double vb = d5 * d2 - d1 * d6;
  if (vb <= 0.0 && d2 >= 0.0 && d6 <= 0.0) {
    const double w = d2 / (d2 - d6);
    return {1.0 - w, 0.0, w};
  }

  const double va = d3 * d6 - d5 * d4;
  if (va <= 0.0 && (d4 - d3) >= 0.0 && (d5 - d6) >= 0.0) {
    const double w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
    return {0.0, 1.0 - w, w};
  }

  const double denominator = 1.0 / (va + vb + vc);
  const double v = vb * denominator;
  const double w = vc * denominator;
  return {1.0 - v - w, v, w};
}

} // namespace directional::geometry::detail

namespace directional::geometry {

SurfacePoint project_to_surface(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::Vector3d &point,
    const SurfaceProjectionOptions &options) {
  return SurfaceProjectionBvh(vertices, faces).project(point, options);
}

} // namespace directional::geometry

namespace directional::geometry {

std::vector<SurfacePoint>
project_vertices_to_surface(const Eigen::MatrixXd &sourceVertices,
                            const Eigen::MatrixXi &sourceFaces,
                            const Eigen::MatrixXd &queryVertices) {
  std::vector<SurfacePoint> provenance;
  provenance.reserve(static_cast<std::size_t>(queryVertices.rows()));
  const SurfaceProjectionBvh bvh(sourceVertices, sourceFaces);
  for (int row = 0; row < queryVertices.rows(); ++row) {
    provenance.push_back(bvh.project(queryVertices.row(row).transpose()));
  }
  return provenance;
}

} // namespace directional::geometry
