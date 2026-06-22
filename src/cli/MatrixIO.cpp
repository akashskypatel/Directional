#include "MatrixIO.h"

#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

namespace directional::cli {
namespace {

void ensure_parent_directory(const std::filesystem::path &path) {
  const std::filesystem::path parent = path.parent_path();
  if (!parent.empty()) {
    std::filesystem::create_directories(parent);
  }
}

template <typename Derived>
void write_dmat_impl(const std::filesystem::path &path,
                     const Eigen::MatrixBase<Derived> &matrix) {
  ensure_parent_directory(path);
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open DMAT output: " + path.string());
  }

  stream.flags(std::ios::scientific);
  stream.precision(std::numeric_limits<double>::digits10 + 1);
  stream << matrix.cols() << ' ' << matrix.rows() << '\n';
  for (Eigen::Index column = 0; column < matrix.cols(); ++column) {
    for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
      stream << matrix(row, column) << '\n';
    }
  }

  stream.close();
  if (stream.fail()) {
    throw std::runtime_error("Failed to write DMAT output: " + path.string());
  }
}

} // namespace

Eigen::MatrixXd read_dmat_double(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open DMAT input: " + path.string());
  }

  Eigen::Index columns = 0;
  Eigen::Index rows = 0;
  if (!(stream >> columns >> rows) || rows < 0 || columns < 0) {
    throw std::runtime_error("Invalid DMAT header in: " + path.string());
  }

  Eigen::MatrixXd matrix(rows, columns);
  for (Eigen::Index column = 0; column < columns; ++column) {
    for (Eigen::Index row = 0; row < rows; ++row) {
      if (!(stream >> matrix(row, column))) {
        throw std::runtime_error("Invalid DMAT data in: " + path.string());
      }
    }
  }

  return matrix;
}

void write_dmat(const std::filesystem::path &path,
                const Eigen::MatrixXd &matrix) {
  write_dmat_impl(path, matrix);
}

void write_dmat(const std::filesystem::path &path,
                const Eigen::MatrixXi &matrix) {
  write_dmat_impl(path, matrix);
}

void write_dmat(const std::filesystem::path &path,
                const Eigen::VectorXd &vector) {
  write_dmat_impl(path, vector);
}

void write_dmat(const std::filesystem::path &path,
                const Eigen::VectorXi &vector) {
  write_dmat_impl(path, vector);
}

void write_polygonal_off(const std::filesystem::path &path,
                         const Eigen::MatrixXd &vertices,
                         const Eigen::VectorXi &degrees,
                         const Eigen::MatrixXi &faces) {
  if (vertices.cols() != 3) {
    throw std::runtime_error("OFF output vertices must have shape (#V, 3).");
  }
  if (degrees.size() != faces.rows()) {
    throw std::runtime_error(
        "OFF output requires one polygon degree per face row.");
  }

  ensure_parent_directory(path);
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open OFF output: " + path.string());
  }

  stream.flags(std::ios::scientific);
  stream.precision(std::numeric_limits<double>::digits10 + 1);
  stream << "OFF\n" << vertices.rows() << ' ' << faces.rows() << " 0\n";
  for (Eigen::Index vertex = 0; vertex < vertices.rows(); ++vertex) {
    stream << vertices(vertex, 0) << ' ' << vertices(vertex, 1) << ' '
           << vertices(vertex, 2) << '\n';
  }

  for (Eigen::Index face = 0; face < faces.rows(); ++face) {
    const int degree = degrees(face);
    if (degree < 3 || degree > faces.cols()) {
      throw std::runtime_error("Invalid polygon degree in remeshing output.");
    }
    stream << degree;
    for (int corner = 0; corner < degree; ++corner) {
      const int index = faces(face, corner);
      if (index < 0 || index >= vertices.rows()) {
        throw std::runtime_error("Invalid vertex index in remeshing output.");
      }
      stream << ' ' << index;
    }
    stream << '\n';
  }

  stream.close();
  if (stream.fail()) {
    throw std::runtime_error("Failed to write OFF output: " + path.string());
  }
}

void write_triangle_off(const std::filesystem::path &path,
                        const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces) {
  if (faces.cols() != 3) {
    throw std::runtime_error("Triangle OFF output faces must have shape (#F, 3).");
  }
  write_polygonal_off(path, vertices,
                      Eigen::VectorXi::Constant(faces.rows(), 3), faces);
}

} // namespace directional::cli
