#pragma once

#include <filesystem>
#include <string>

#include <Eigen/Core>

#include "MeshIO.h"

namespace directional::cli {

enum class FieldFormat { CrossField, Rosy, RawField };

struct FieldData {
  int degree = 4;
  Eigen::MatrixXd primary;
  Eigen::MatrixXd secondary;
  Eigen::MatrixXd raw;
};

FieldFormat parse_field_format(const std::string &value);
FieldFormat infer_field_format(const std::filesystem::path &path,
                               const std::string &requested = "auto");
std::filesystem::path infer_field_output_path(
    const std::filesystem::path &inputPath, FieldFormat format);

FieldData read_field(const std::filesystem::path &path, FieldFormat format,
                     const MeshData *mesh = nullptr);
void write_field(const std::filesystem::path &path, FieldFormat format,
                 const FieldData &field);

int run_convert_field(int argc, char **argv);

} // namespace directional::cli
