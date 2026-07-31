#include <directional/geometry/TensorCurvatureTarget.h>

namespace directional {

TensorCurvatureTarget tensor_curvature_target(
    const Eigen::Matrix2d &shapeOperator,
    const double epsilon) {
  TensorCurvatureTarget result;
  if (!shapeOperator.array().isFinite().all()) {
    return result;
  }

  const Eigen::Matrix2d symmetric =
      0.5 * (shapeOperator + shapeOperator.transpose());
  const double a = symmetric(0, 0);
  const double b = symmetric(0, 1);
  const double c = symmetric(1, 1);

  const std::complex<double> t2(a - c, 2.0 * b);
  const double deviatorNorm = std::abs(t2);
  if (!(deviatorNorm > epsilon) || !std::isfinite(deviatorNorm)) {
    return result;
  }

  const double trace = a + c;
  const double halfTrace = 0.5 * trace;
  const double k0 = halfTrace - 0.5 * deviatorNorm;
  const double k1 = halfTrace + 0.5 * deviatorNorm;

  const std::complex<double> unit = t2 / deviatorNorm;
  result.q4 = unit * unit;
  result.anisotropy = deviatorNorm;
  result.magnitude = std::abs(k0) + std::abs(k1);
  result.valid = result.q4.real() == result.q4.real() &&
                 result.q4.imag() == result.q4.imag();
  return result;
}

} // namespace directional

namespace directional {

Eigen::Matrix2d restrict_tensor_to_basis(
    const Eigen::Matrix3d &ambientTensor, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = basisX;
  basis.col(1) = basisY;
  return basis.transpose() * ambientTensor * basis;
}

} // namespace directional

namespace directional {

Eigen::Matrix3d lift_tensor_to_ambient(
    const Eigen::Matrix2d &shapeOperator, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  Eigen::Matrix<double, 3, 2> basis;
  basis.col(0) = basisX;
  basis.col(1) = basisY;
  return basis * shapeOperator * basis.transpose();
}

} // namespace directional

namespace directional {

Eigen::Matrix2d transport_shape_operator_between_faces(
    const Eigen::Matrix2d &sourceShapeOperator,
    const Eigen::Vector3d &sourceBasisX, const Eigen::Vector3d &sourceBasisY,
    const Eigen::Vector3d &sourceNormal, const Eigen::Vector3d &targetBasisX,
    const Eigen::Vector3d &targetBasisY,
    const Eigen::Vector3d &targetNormal) {
  const Eigen::Matrix3d rotation =
      transport_rotation_between_normals(sourceNormal, targetNormal);
  const Eigen::Matrix3d sourceAmbient = lift_tensor_to_ambient(
      sourceShapeOperator, sourceBasisX, sourceBasisY);
  const Eigen::Matrix3d transportedAmbient =
      rotation * sourceAmbient * rotation.transpose();
  return restrict_tensor_to_basis(transportedAmbient, targetBasisX,
                                  targetBasisY);
}

} // namespace directional

namespace directional {

Eigen::Vector3d representative_direction_from_q4(
    const std::complex<double> &q4, const Eigen::Vector3d &basisX,
    const Eigen::Vector3d &basisY) {
  const double angle = 0.25 * std::atan2(q4.imag(), q4.real());
  Eigen::Vector3d direction = std::cos(angle) * basisX +
                              std::sin(angle) * basisY;
  const double norm = direction.norm();
  if (!(norm > 1e-14) || !direction.array().isFinite().all()) {
    return Eigen::Vector3d::Zero();
  }
  return direction / norm;
}

} // namespace directional
