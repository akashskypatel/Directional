#pragma once

#include <filesystem>

#include <Eigen/Core>

namespace directional::cli {

struct RawFieldData {
  int degree = 0;
  Eigen::MatrixXd values;
};

RawFieldData read_raw_field(const std::filesystem::path &path);

void write_raw_field(const std::filesystem::path &path, int degree,
                     const Eigen::MatrixXd &rawField);

void write_singularities_file(const std::filesystem::path &path, int degree,
                              const Eigen::VectorXi &singularCycles,
                              const Eigen::VectorXi &singularIndices);

void write_cross_field_diagnostics(
    const std::filesystem::path &prefix,
    const Eigen::MatrixXd &primaryDirections,
    const Eigen::MatrixXd &secondaryDirections,
    const Eigen::VectorXi &matching,
    const Eigen::VectorXd &effort,
    const Eigen::VectorXi &singularCycles,
    const Eigen::VectorXi &singularIndices);

} // namespace directional::cli
