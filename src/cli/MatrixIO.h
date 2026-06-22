#pragma once

#include <filesystem>

#include <Eigen/Core>

namespace directional::cli {

Eigen::MatrixXd read_dmat_double(const std::filesystem::path &path);

void write_dmat(const std::filesystem::path &path,
                const Eigen::MatrixXd &matrix);
void write_dmat(const std::filesystem::path &path,
                const Eigen::MatrixXi &matrix);
void write_dmat(const std::filesystem::path &path,
                const Eigen::VectorXd &vector);
void write_dmat(const std::filesystem::path &path,
                const Eigen::VectorXi &vector);

void write_polygonal_off(const std::filesystem::path &path,
                         const Eigen::MatrixXd &vertices,
                         const Eigen::VectorXi &degrees,
                         const Eigen::MatrixXi &faces);

void write_triangle_off(const std::filesystem::path &path,
                        const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces);

} // namespace directional::cli
