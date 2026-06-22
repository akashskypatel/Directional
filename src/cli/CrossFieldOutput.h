#pragma once

#include <filesystem>

#include <Eigen/Core>

namespace directional::cli {

void write_raw_field(const std::filesystem::path &path, int degree,
                     const Eigen::MatrixXd &rawField);

void write_singularities_file(const std::filesystem::path &path, int degree,
                              const Eigen::VectorXi &singularCycles,
                              const Eigen::VectorXi &singularIndices);

} // namespace directional::cli
