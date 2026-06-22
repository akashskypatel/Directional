#include <directional/fields/CrossField.h>

#include <cmath>
#include <complex>
#include <numbers>
#include <stdexcept>
#include <vector>

#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

#include <directional/core/CartesianField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/fields/PCFaceTangentBundle.h>

namespace directional::fields {
namespace {

using Complex = std::complex<double>;
using ComplexSparseMatrix = Eigen::SparseMatrix<Complex>;
using ComplexTriplet = Eigen::Triplet<Complex>;

Eigen::VectorXcd solve_power_field(const PCFaceTangentBundle &tangentBundle,
                                   const bool normalizeDirections) {
  const int faceCount = tangentBundle.numSpaces;
  Eigen::VectorXcd power = Eigen::VectorXcd::Ones(faceCount);
  if (faceCount == 1) {
    return power;
  }

  std::vector<ComplexTriplet> triplets;
  triplets.reserve(static_cast<std::size_t>(
      4 * tangentBundle.innerAdjacencies.size()));
  Eigen::VectorXcd rhs = Eigen::VectorXcd::Zero(faceCount - 1);

  const auto add_coefficient = [&](const int row, const int column,
                                   const Complex value) {
    if (row == 0) {
      return;
    }
    if (column == 0) {
      rhs(row - 1) -= value;
      return;
    }
    triplets.emplace_back(row - 1, column - 1, value);
  };

  int innerEdge = 0;
  for (int edge = 0; edge < tangentBundle.adjSpaces.rows(); ++edge) {
    const int firstFace = tangentBundle.adjSpaces(edge, 0);
    const int secondFace = tangentBundle.adjSpaces(edge, 1);
    if (firstFace == -1 || secondFace == -1) {
      continue;
    }

    const double weight =
        tangentBundle.connectionMass.coeff(innerEdge, innerEdge);
    const Complex transport =
        std::pow(tangentBundle.connection(edge), kCrossFieldDegree);

    add_coefficient(firstFace, firstFace,
                    weight * std::norm(transport));
    add_coefficient(secondFace, secondFace, weight);
    add_coefficient(firstFace, secondFace,
                    -weight * std::conj(transport));
    add_coefficient(secondFace, firstFace, -weight * transport);
    ++innerEdge;
  }

  ComplexSparseMatrix system(faceCount - 1, faceCount - 1);
  system.setFromTriplets(triplets.begin(), triplets.end());

  Eigen::SimplicialLDLT<ComplexSparseMatrix> solver;
  solver.compute(system);
  if (solver.info() != Eigen::Success) {
    throw std::runtime_error(
        "Cross-field power-system factorization failed. The mesh must be a "
        "connected manifold triangle mesh.");
  }

  power.tail(faceCount - 1) = solver.solve(rhs);
  if (solver.info() != Eigen::Success) {
    throw std::runtime_error("Cross-field power-system solve failed.");
  }

  if (normalizeDirections) {
    for (int face = 0; face < power.size(); ++face) {
      const double magnitude = std::abs(power(face));
      if (magnitude <= 1e-14) {
        throw std::runtime_error(
            "Cross-field extraction produced a degenerate power value.");
      }
      power(face) /= magnitude;
    }
  }

  return power;
}

CartesianField make_raw_field(const PCFaceTangentBundle &tangentBundle,
                              const Eigen::VectorXcd &power,
                              const bool normalizeDirections) {
  const int faceCount = tangentBundle.numSpaces;
  Eigen::MatrixXcd roots(faceCount, kCrossFieldDegree);

  for (int face = 0; face < faceCount; ++face) {
    Complex firstRoot =
        std::pow(power(face), 1.0 / static_cast<double>(kCrossFieldDegree));
    if (normalizeDirections) {
      const double magnitude = std::abs(firstRoot);
      if (magnitude <= 1e-14) {
        throw std::runtime_error(
            "Cross-field extraction produced a degenerate direction.");
      }
      firstRoot /= magnitude;
    }

    for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
      const double angle = 2.0 * std::numbers::pi * direction /
                           static_cast<double>(kCrossFieldDegree);
      roots(face, direction) =
          firstRoot * std::exp(Complex(0.0, angle));
    }
  }

  Eigen::MatrixXd intrinsic(faceCount, 2 * kCrossFieldDegree);
  for (int direction = 0; direction < kCrossFieldDegree; ++direction) {
    intrinsic.col(2 * direction) = roots.col(direction).real();
    intrinsic.col(2 * direction + 1) = roots.col(direction).imag();
  }

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, kCrossFieldDegree);
  rawField.set_intrinsic_field(intrinsic);
  return rawField;
}

} // namespace

CrossFieldResult extract_cross_field(const TriMesh &mesh,
                                     const CrossFieldOptions &options) {
  if (mesh.V.rows() == 0 || mesh.F.rows() == 0) {
    throw std::runtime_error(
        "Cross-field extraction requires a non-empty triangle mesh.");
  }
  if (mesh.F.cols() != 3) {
    throw std::runtime_error(
        "Cross-field extraction requires triangular faces.");
  }

  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(mesh);

  const Eigen::VectorXcd power =
      solve_power_field(tangentBundle, options.normalizeDirections);
  CartesianField rawField =
      make_raw_field(tangentBundle, power, options.normalizeDirections);

  if (options.computeMatching) {
    principal_matching(rawField);
  }

  CrossFieldResult result;
  result.rawField = rawField.extField;
  result.primaryDirections = rawField.extField.leftCols<3>();
  result.secondaryDirections = rawField.extField.middleCols<3>(3);

  if (options.computeMatching) {
    result.matching = rawField.matching;
    result.effort = rawField.effort;
    result.singularCycles = rawField.singLocalCycles;
    result.singularIndices = rawField.singIndices;
  }

  return result;
}

CrossFieldResult extract_cross_field(const Eigen::MatrixXd &vertices,
                                     const Eigen::MatrixXi &faces,
                                     const CrossFieldOptions &options) {
  TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  return extract_cross_field(mesh, options);
}

} // namespace directional::fields
