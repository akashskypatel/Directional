#include <directional/fields/ShapeOperatorAlignment.h>

namespace directional::fields::shape_operator_alignment_detail {

Eigen::RowVector3d normalized_row(const Eigen::RowVector3d &value) {
  const double norm = value.norm();
  if (!(norm > 1e-30) || !std::isfinite(norm)) {
    return Eigen::RowVector3d::Zero();
  }
  return value / norm;
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

Eigen::Vector3d normalized_vector(const Eigen::Vector3d &value) {
  const double norm = value.norm();
  if (!(norm > 1e-30) || !std::isfinite(norm)) {
    return Eigen::Vector3d::Zero();
  }
  return value / norm;
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

void validate_field(const Eigen::MatrixXd &field,
                           const Eigen::Index faceCount) {
  if (field.rows() != faceCount) {
    throw std::runtime_error(
        "Shape-operator alignment field row count does not match faces.");
  }
  if (field.cols() != 6 && field.cols() != 12) {
    throw std::runtime_error(
        "Shape-operator alignment requires a 6-column crossfield or "
        "12-column rawfield.");
  }
  if (!field.array().isFinite().all()) {
    throw std::runtime_error(
        "Shape-operator alignment field contains non-finite values.");
  }
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

Eigen::Vector3d field_axis(const Eigen::MatrixXd &field,
                                  const Eigen::Index face,
                                  const int axis) {
  const int column = axis == 0 ? 0 : 3;
  return field.block(face, column, 1, 3).transpose();
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

Eigen::Vector3d transport_axis_to_proxy(
    const Eigen::Vector3d &axis, const Eigen::Vector3d &originalNormal,
    const Eigen::Vector3d &proxyNormal) {
  Eigen::Vector3d transported =
      transport_rotation_between_normals(originalNormal, proxyNormal) * axis;
  transported -= transported.dot(proxyNormal) * proxyNormal;
  return normalized_vector(transported);
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

Eigen::Vector2d coordinates_in_basis(
    const Eigen::Vector3d &axis, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  Eigen::Vector2d coordinates(axis.dot(basisX), axis.dot(basisY));
  const double norm = coordinates.norm();
  if (!(norm > 1e-30) || !std::isfinite(norm)) {
    return Eigen::Vector2d::Zero();
  }
  return coordinates / norm;
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

double anisotropy_from_shape_operator(const Eigen::Matrix2d &shape) {
  if (!shape.array().isFinite().all()) {
    return 0.0;
  }
  const Eigen::Matrix2d symmetric = 0.5 * (shape + shape.transpose());
  Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> eigensolver(symmetric);
  if (eigensolver.info() != Eigen::Success) {
    return 0.0;
  }
  return std::abs(eigensolver.eigenvalues()(1) -
                  eigensolver.eigenvalues()(0));
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

double normalized_offdiagonal_ratio(const Eigen::Matrix2d &shape,
                                           const Eigen::Vector2d &axisA,
                                           const Eigen::Vector2d &axisB,
                                           const double anisotropy) {
  if (!(anisotropy > 1e-30) || !shape.array().isFinite().all() ||
      !axisA.array().isFinite().all() || !axisB.array().isFinite().all()) {
    return std::numeric_limits<double>::quiet_NaN();
  }
  const Eigen::Matrix2d symmetric = 0.5 * (shape + shape.transpose());
  const double mixed = axisA.transpose() * symmetric * axisB;
  return std::clamp(2.0 * std::abs(mixed) / anisotropy, 0.0, 1.0);
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

Eigen::Vector3d orthogonalized_second_axis(const Eigen::Vector3d &axisA,
                                                  const Eigen::Vector3d &axisB,
                                                  const Eigen::Vector3d &normal) {
  Eigen::Vector3d second = axisB - axisB.dot(axisA) * axisA;
  second -= second.dot(normal) * normal;
  second = normalized_vector(second);
  if (second.squaredNorm() > 1e-20) {
    return second;
  }
  second = normal.cross(axisA);
  return normalized_vector(second);
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields::shape_operator_alignment_detail {

void ensure_valid_options(const ShapeOperatorAlignmentOptions &options) {
  if (!std::isfinite(options.minimumConfidence) ||
      options.minimumConfidence < 0.0 || options.minimumConfidence > 1.0 ||
      !std::isfinite(options.confidenceExponent) ||
      options.confidenceExponent <= 0.0) {
    throw std::runtime_error(
        "Invalid shape-operator alignment confidence options.");
  }
}

} // namespace directional::fields::shape_operator_alignment_detail

namespace directional::fields {

ShapeOperatorAlignmentResult evaluate_shape_operator_alignment(
    const TriMesh &mesh, const Eigen::MatrixXd &field,
    const ShapeOperatorAlignmentOptions &options) {
  using namespace shape_operator_alignment_detail;

  validate_field(field, mesh.F.rows());
  ensure_valid_options(options);

  TriMesh curvatureMesh;
  RegularizedProxyMeshResult proxy;
  if (options.useRegularizedProxy) {
    proxy = regularize_proxy_mesh(mesh.V, mesh.F, mesh.EV,
                                  mesh.isBoundaryVertex, options.proxy);
    curvatureMesh.set_mesh(proxy.vertices, mesh.F);
  } else {
    curvatureMesh.set_mesh(mesh.V, mesh.F);
    proxy.vertices = mesh.V;
    proxy.displacement = Eigen::VectorXd::Zero(mesh.V.rows());
  }

  ShapeOperatorAlignmentResult result;
  result.curvature = estimate_face_curvature(
      curvatureMesh.V, curvatureMesh.F, curvatureMesh.FBx,
      curvatureMesh.FBy, curvatureMesh.faceNormals, curvatureMesh.faceAreas,
      curvatureMesh.TT, curvatureMesh.vertexNormals, options.curvature);
  result.proxyVertices = proxy.vertices;
  result.proxyDisplacement = proxy.displacement;

  const Eigen::Index faceCount = mesh.F.rows();
  result.angleDegrees = Eigen::VectorXd::Zero(faceCount);
  result.normalizedEnergy = Eigen::VectorXd::Zero(faceCount);
  result.confidence = Eigen::VectorXd::Zero(faceCount);
  result.weights = Eigen::VectorXd::Zero(faceCount);
  result.valid = Eigen::VectorXi::Zero(faceCount);
  result.anisotropy = Eigen::VectorXd::Zero(faceCount);

  double validArea = 0.0;
  double totalArea = mesh.faceAreas.sum();
  double weightedEnergy = 0.0;
  double totalWeight = 0.0;

  for (Eigen::Index face = 0; face < faceCount; ++face) {
    if (result.curvature.valid(face) == 0 ||
        result.curvature.confidence(face) < options.minimumConfidence) {
      continue;
    }

    const Eigen::Matrix2d shape = result.curvature.shapeOperators[face];
    const double anisotropy = anisotropy_from_shape_operator(shape);
    if (!(anisotropy > 1e-30)) {
      continue;
    }

    const Eigen::Vector3d originalNormal = mesh.faceNormals.row(face).transpose();
    const Eigen::Vector3d proxyNormal =
        curvatureMesh.faceNormals.row(face).transpose();
    Eigen::Vector3d axisA = transport_axis_to_proxy(
        field_axis(field, face, 0), originalNormal, proxyNormal);
    Eigen::Vector3d axisB = transport_axis_to_proxy(
        field_axis(field, face, 1), originalNormal, proxyNormal);
    if (axisA.squaredNorm() <= 1e-20 || axisB.squaredNorm() <= 1e-20) {
      continue;
    }
    axisB = orthogonalized_second_axis(axisA, axisB, proxyNormal);
    if (axisB.squaredNorm() <= 1e-20) {
      continue;
    }

    const Eigen::Vector2d localA = coordinates_in_basis(
        axisA, curvatureMesh.FBx.row(face).transpose(),
        curvatureMesh.FBy.row(face).transpose());
    const Eigen::Vector2d localB = coordinates_in_basis(
        axisB, curvatureMesh.FBx.row(face).transpose(),
        curvatureMesh.FBy.row(face).transpose());
    if (localA.squaredNorm() <= 1e-20 || localB.squaredNorm() <= 1e-20) {
      continue;
    }

    const double ratio = normalized_offdiagonal_ratio(
        shape, localA, localB, anisotropy);
    if (!std::isfinite(ratio)) {
      continue;
    }

    const double angle = 0.5 * std::asin(std::clamp(ratio, 0.0, 1.0));
    const double confidenceWeight =
        std::pow(result.curvature.confidence(face), options.confidenceExponent);
    const double areaWeight = mesh.faceAreas(face) * confidenceWeight;

    result.valid(face) = 1;
    result.angleDegrees(face) = angle * 180.0 / pi;
    result.normalizedEnergy(face) = ratio * ratio;
    result.confidence(face) = result.curvature.confidence(face);
    result.weights(face) = areaWeight;
    result.anisotropy(face) = anisotropy;
    ++result.validFaceCount;
    validArea += mesh.faceAreas(face);
    weightedEnergy += areaWeight * result.normalizedEnergy(face);
    totalWeight += areaWeight;
  }

  result.validAreaFraction = totalArea > 0.0 ? validArea / totalArea : 0.0;
  result.weightedMeanEnergy =
      totalWeight > 0.0 ? weightedEnergy / totalWeight : 0.0;
  return result;
}

} // namespace directional::fields

namespace directional::fields {

ShapeOperatorAlignmentResult evaluate_shape_operator_alignment(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &field,
    const ShapeOperatorAlignmentOptions &options) {
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return evaluate_shape_operator_alignment(mesh, field, options);
}

} // namespace directional::fields
