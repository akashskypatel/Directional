#pragma once

#include <filesystem>

#include <Eigen/Core>

namespace directional::cli {

struct MeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshData load_mesh(const std::filesystem::path &path);

} // namespace directional::cli
