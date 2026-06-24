#pragma once

#include <cstddef>
#include <filesystem>
#include <functional>
#include <string_view>

#include <Eigen/Core>

namespace directional::gui {

enum class FieldMethod { Smooth, RegularizedCurvature };
enum class FieldFormat { Auto, RawField, CrossField, Rosy };

using ProgressCallback = std::function<void(
    std::size_t current, std::size_t total, std::string_view task)>;

struct MeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

struct FieldData {
  int degree = 4;
  Eigen::MatrixXd primary;
  Eigen::MatrixXd secondary;
  Eigen::MatrixXd raw;
};

struct QuadMeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

struct FieldOptions {
  FieldMethod method = FieldMethod::RegularizedCurvature;
  bool normalizeDirections = true;

  double proxyFidelityWeight = 1.0;
  double proxySmoothnessWeight = 0.01;
  bool preserveBoundary = true;
  double fieldSmoothnessWeight = 1.0;
  double curvatureAlignmentWeight = 1.0;
  double minimumConfidence = 1e-3;
  double confidenceExponent = 2.0;
  int curvatureSmoothingIterations = 1;
};

struct RemeshOptions {
  double lengthRatio = 0.02;
  bool integralSeamless = true;
  bool roundSeams = false;
  bool verbose = false;
};

struct AutoRemeshResult {
  FieldData field;
  QuadMeshData quadMesh;
};

MeshData load_mesh(const std::filesystem::path &path);

FieldData load_field(const std::filesystem::path &path, FieldFormat format,
                     const MeshData &mesh);

void save_field(const std::filesystem::path &path, FieldFormat format,
                const FieldData &field);

FieldData calculate_field(const MeshData &mesh, const FieldOptions &options,
                          ProgressCallback progress = {});

AutoRemeshResult auto_remesh(const MeshData &mesh,
                             const FieldOptions &fieldOptions,
                             const RemeshOptions &remeshOptions,
                             ProgressCallback progress = {});

QuadMeshData remesh_with_field(const MeshData &mesh, const FieldData &field,
                               const RemeshOptions &options,
                               ProgressCallback progress = {});

void save_quad_mesh(const std::filesystem::path &path,
                    const QuadMeshData &mesh);

void validate_field(const FieldData &field, Eigen::Index faceCount);
void validate_options(const FieldOptions &fieldOptions,
                      const RemeshOptions &remeshOptions);

} // namespace directional::gui
