#include <directional/geometry/BarycentricCoordinates.h>

namespace directional {

void barycentric_coordinates(const Eigen::MatrixXd &points,
                                    const Eigen::MatrixXd &corner0,
                                    const Eigen::MatrixXd &corner1,
                                    const Eigen::MatrixXd &corner2,
                                    Eigen::MatrixXd &coordinates) {
  const Eigen::Index rowCount = points.rows();
  const bool dimensionsMatch =
      points.cols() == 3 && corner0.rows() == rowCount &&
      corner1.rows() == rowCount && corner2.rows() == rowCount &&
      corner0.cols() == 3 && corner1.cols() == 3 && corner2.cols() == 3;
  if (!dimensionsMatch) {
    throw std::invalid_argument(
        "barycentric_coordinates expects matching N-by-3 matrices");
  }

  coordinates.resize(rowCount, 3);
  const double nan = std::numeric_limits<double>::quiet_NaN();

  for (Eigen::Index row = 0; row < rowCount; ++row) {
    const Eigen::RowVector3d edge0 = corner1.row(row) - corner0.row(row);
    const Eigen::RowVector3d edge1 = corner2.row(row) - corner0.row(row);
    const Eigen::RowVector3d offset = points.row(row) - corner0.row(row);

    const double dot00 = edge0.dot(edge0);
    const double dot01 = edge0.dot(edge1);
    const double dot11 = edge1.dot(edge1);
    const double dot20 = offset.dot(edge0);
    const double dot21 = offset.dot(edge1);
    const double denominator = dot00 * dot11 - dot01 * dot01;

    if (denominator == 0.0) {
      coordinates.row(row).setConstant(nan);
      continue;
    }

    const double weight1 = (dot11 * dot20 - dot01 * dot21) / denominator;
    const double weight2 = (dot00 * dot21 - dot01 * dot20) / denominator;
    coordinates(row, 0) = 1.0 - weight1 - weight2;
    coordinates(row, 1) = weight1;
    coordinates(row, 2) = weight2;
  }
}

} // namespace directional
