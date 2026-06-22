#include "CrossFieldOutput.h"
#include "MatrixIO.h"

#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

#include <directional/io/WriteSingularities.h>

namespace directional::cli {
namespace {

void ensure_parent_directory(const std::filesystem::path &path) {
  const std::filesystem::path parent = path.parent_path();
  if (!parent.empty()) {
    std::filesystem::create_directories(parent);
  }
}

std::filesystem::path sidecar(const std::filesystem::path &prefix,
                              const char *suffix) {
  return std::filesystem::path(prefix.string() + suffix);
}

} // namespace

RawFieldData read_raw_field(const std::filesystem::path &path) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open raw field input: " + path.string());
  }

  RawFieldData result;
  Eigen::Index rowCount = 0;
  if (!(stream >> result.degree >> rowCount) || result.degree <= 0 ||
      rowCount < 0) {
    throw std::runtime_error("Invalid raw field header in: " + path.string());
  }

  result.values.resize(rowCount, 3 * result.degree);
  for (Eigen::Index row = 0; row < result.values.rows(); ++row) {
    for (Eigen::Index column = 0; column < result.values.cols(); ++column) {
      if (!(stream >> result.values(row, column))) {
        throw std::runtime_error("Invalid raw field data in: " + path.string());
      }
    }
  }
  return result;
}

void write_raw_field(const std::filesystem::path &path, const int degree,
                     const Eigen::MatrixXd &rawField) {
  ensure_parent_directory(path);
  std::ofstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open cross-field output: " +
                             path.string());
  }

  stream.flags(std::ios::scientific);
  stream.precision(std::numeric_limits<double>::digits10 + 1);
  stream << degree << ' ' << rawField.rows() << '\n';
  for (Eigen::Index face = 0; face < rawField.rows(); ++face) {
    for (Eigen::Index column = 0; column < rawField.cols(); ++column) {
      if (column > 0) {
        stream << ' ';
      }
      stream << rawField(face, column);
    }
    stream << '\n';
  }

  stream.close();
  if (stream.fail()) {
    throw std::runtime_error("Failed to write cross field: " + path.string());
  }
}

void write_singularities_file(const std::filesystem::path &path,
                              const int degree,
                              const Eigen::VectorXi &singularCycles,
                              const Eigen::VectorXi &singularIndices) {
  ensure_parent_directory(path);
  if (!directional::write_singularities(path.string(), degree, singularCycles,
                                        singularIndices)) {
    throw std::runtime_error("Failed to write singularities: " + path.string());
  }
}

void write_cross_field_diagnostics(
    const std::filesystem::path &prefix,
    const Eigen::MatrixXd &primaryDirections,
    const Eigen::MatrixXd &secondaryDirections,
    const Eigen::VectorXi &matching,
    const Eigen::VectorXd &effort,
    const Eigen::VectorXi &singularCycles,
    const Eigen::VectorXi &singularIndices) {
  write_dmat(sidecar(prefix, ".primary.dmat"), primaryDirections);
  write_dmat(sidecar(prefix, ".secondary.dmat"), secondaryDirections);

  if (matching.size() > 0) {
    write_dmat(sidecar(prefix, ".matching.dmat"), matching);
    write_dmat(sidecar(prefix, ".effort.dmat"), effort);
    write_dmat(sidecar(prefix, ".singular_cycles.dmat"), singularCycles);
    write_dmat(sidecar(prefix, ".singular_indices.dmat"), singularIndices);
  }
}

} // namespace directional::cli
