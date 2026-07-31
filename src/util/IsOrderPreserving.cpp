#include <directional/util/IsOrderPreserving.h>

#include <Eigen/Geometry>

namespace directional {

void is_order_preserving(const Eigen::MatrixXd &vertices,
                         const Eigen::MatrixXi &faces,
                         const Eigen::MatrixXd &rawField,
                         Eigen::VectorXi &isOrderPreserving,
                         Eigen::MatrixXd &products) {
  Eigen::MatrixXd normals(faces.rows(), 3);
  for (Eigen::Index face = 0; face < faces.rows(); ++face) {
    const Eigen::RowVector3d edge0 =
        vertices.row(faces(face, 1)) - vertices.row(faces(face, 0));
    const Eigen::RowVector3d edge1 =
        vertices.row(faces(face, 2)) - vertices.row(faces(face, 0));
    normals.row(face) = edge0.cross(edge1).normalized();
  }

  const int degree = static_cast<int>(rawField.cols() / 3);
  products.resize(rawField.rows(), degree);
  isOrderPreserving = Eigen::VectorXi::Ones(rawField.rows());

  for (Eigen::Index face = 0; face < rawField.rows(); ++face) {
    for (int direction = 0; direction < degree; ++direction) {
      const Eigen::RowVector3d first =
          rawField.block<1, 3>(face, 3 * direction);
      const Eigen::RowVector3d second =
          rawField.block<1, 3>(face, 3 * ((direction + 1) % degree));
      products(face, direction) = normals.row(face).dot(first.cross(second));
      if (products(face, direction) <= 0.0) {
        isOrderPreserving(face) = 0;
      }
    }
  }
}

} // namespace directional
