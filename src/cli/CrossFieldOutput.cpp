#include "CrossFieldOutput.h"

#include <fstream>
#include <limits>
#include <stdexcept>

#include <directional/io/WriteSingularities.h>

namespace directional::cli {
namespace {

void ensure_parent_directory(const std::filesystem::path &path) {
  const std::filesystem::path parent = path.parent_path();
  if (!parent.empty()) {
    std::filesystem::create_directories(parent);
  }
}

} // namespace

void write_raw_field(const std::filesystem::path &path, const int degree,
                     const Eigen::MatrixXd &rawField) {
  ensure_parent_directory(path);
  std::ofstream stream(path);
  stream.flags(std::ios::scientific);
  stream.precision(std::numeric_limits<double>::digits10 + 1);
  stream << degree << ' ' << rawField.rows() << '\n';
  for (int face = 0; face < rawField.rows(); ++face) {
    stream << rawField.row(face) << '\n';
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

} // namespace directional::cli
