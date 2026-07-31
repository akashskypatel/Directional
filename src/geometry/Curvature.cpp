#include <directional/geometry/Curvature.h>

namespace directional {

void gaussian_curvature(const Eigen::MatrixXd &V,
                               const Eigen::MatrixXi &F,
                               const Eigen::VectorXi &isBoundaryVertex,
                               Eigen::VectorXd &G) {

  G.resize(V.rows());
  for (int i = 0; i < V.rows(); i++)
    G(i) = (isBoundaryVertex(i) ? std::numbers::pi : 2.0 * std::numbers::pi);

  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < 3; j++) {
      Eigen::RowVector3d v1 = V.row(F(i, (j + 1) % 3)) - V.row(F(i, j));
      Eigen::RowVector3d v2 = V.row(F(i, (j + 2) % 3)) - V.row(F(i, j));
      double currAngle = std::acos(v1.dot(v2) / (v1.norm() * v2.norm()));
      G(F(i, j)) -= currAngle;
    }
  }
}

} // namespace directional

namespace directional {

std::unordered_map<int, std::set<int>>
build_adjacency(const Eigen::MatrixXi &EV) {
  std::unordered_map<int, std::set<int>> adj;
  for (int i = 0; i < EV.rows(); ++i) {
    int v0 = EV(i, 0);
    int v1 = EV(i, 1);
    adj[v0].insert(v1);
    adj[v1].insert(v0);
  }
  return adj;
}

} // namespace directional

namespace directional {

void shape_operator(const Eigen::MatrixXd &V, const Eigen::MatrixXi &EV,
                    const Eigen::MatrixXd &VBx, const Eigen::MatrixXd &VBy,
                    const Eigen::MatrixXd &vertexNormals,
                    std::vector<Eigen::Matrix2d> &Sv) {

  Sv.resize(V.rows(),
            Eigen::Matrix2d::Constant(std::nan(""))); // default to NaNs

  auto adjacency = build_adjacency(EV);

  for (int vi = 0; vi < V.rows(); ++vi) {
    const auto &neighbors = adjacency[vi];

    const Eigen::RowVector3d origin = V.row(vi);
    const Eigen::RowVector3d normal = vertexNormals.row(vi).normalized();
    const Eigen::RowVector3d bx = VBx.row(vi).normalized();
    const Eigen::RowVector3d by = VBy.row(vi).normalized();

    Eigen::MatrixXd A(neighbors.size(), 5);
    Eigen::VectorXd rhs(neighbors.size());

    int currRow = 0;
    for (int nj : neighbors) {
      Eigen::RowVector3d delta = V.row(nj) - origin;
      double x = delta.dot(bx);
      double y = delta.dot(by);
      double z = delta.dot(normal); // height along normal direction

      A.row(currRow) << x * x, x * y, y * y, x, y;
      rhs(currRow) = z;
      currRow++;
    }

    Eigen::VectorXd coeffs = A.colPivHouseholderQr().solve(rhs);
    double a = coeffs(0), b = coeffs(1), c = coeffs(2);

    Eigen::Matrix2d H;
    H << 2 * a, b, b, 2 * c;

    Sv[vi] = -H;
  }
}

} // namespace directional
