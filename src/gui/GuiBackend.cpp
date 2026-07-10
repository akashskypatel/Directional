#include "GuiBackend.h"

#include "FieldConversion.h"
#include "MatrixIO.h"
#include "MeshIO.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <string>
#include <utility>

namespace directional::gui {
namespace {

FieldData from_cli_field(const cli::FieldData &field) {
  FieldData result;
  result.degree = field.degree;
  result.primary = field.primary;
  result.secondary = field.secondary;
  result.raw = field.raw;
  return result;
}

cli::FieldData to_cli_field(const FieldData &field) {
  cli::FieldData result;
  result.degree = field.degree;
  result.primary = field.primary;
  result.secondary = field.secondary;
  result.raw = field.raw;
  return result;
}

bool has_raw_cross_field(const FieldData &field,
                         const Eigen::Index faceCount) {
  return field.raw.rows() == faceCount && field.raw.cols() == 12 &&
         field.raw.array().isFinite().all();
}

bool has_axis_cross_field(const FieldData &field,
                          const Eigen::Index faceCount) {
  return field.primary.rows() == faceCount && field.primary.cols() == 3 &&
         field.secondary.rows() == faceCount && field.secondary.cols() == 3 &&
         field.primary.array().isFinite().all() &&
         field.secondary.array().isFinite().all();
}

cli::FieldFormat to_cli_format(const FieldFormat format,
                               const std::filesystem::path &path) {
  switch (format) {
  case FieldFormat::RawField:
    return cli::FieldFormat::RawField;
  case FieldFormat::CrossField:
    return cli::FieldFormat::CrossField;
  case FieldFormat::Rosy:
    return cli::FieldFormat::Rosy;
  case FieldFormat::Auto:
    return cli::infer_field_format(path);
  }
  throw std::runtime_error("Unsupported field format.");
}


std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

ProgressCallback map_progress(ProgressCallback progress,
                              const std::size_t begin,
                              const std::size_t end) {
  if (!progress) {
    return {};
  }
  return [progress = std::move(progress), begin, end](
             const std::size_t current, const std::size_t total,
             const std::string_view task) {
    const std::size_t safeTotal = std::max<std::size_t>(total, 1);
    const std::size_t safeCurrent = std::min(current, safeTotal);
    const std::size_t mapped =
        begin + safeCurrent * (end - begin) / safeTotal;
    progress(mapped, 100, task);
  };
}

} // namespace

MeshData load_mesh(const std::filesystem::path &path) {
  const cli::MeshData mesh = cli::load_mesh(path);
  return {mesh.vertices, mesh.faces};
}

FieldData load_field(const std::filesystem::path &path,
                     const FieldFormat format, const MeshData &mesh) {
  const cli::MeshData cliMesh{mesh.vertices, mesh.faces};
  FieldData result = from_cli_field(
      cli::read_field(path, to_cli_format(format, path), &cliMesh));
  validate_field(result, mesh.faces.rows());
  return result;
}

void save_field(const std::filesystem::path &path, const FieldFormat format,
                const FieldData &field) {
  cli::write_field(path, to_cli_format(format, path), to_cli_field(field));
}

AutoRemeshResult auto_remesh(const MeshData &mesh,
                             const FieldOptions &fieldOptions,
                             const RemeshOptions &remeshOptions,
                             ProgressCallback progress) {
  validate_options(fieldOptions, remeshOptions);
  FieldData field = calculate_field(
      mesh, fieldOptions, map_progress(progress, 0, 20));
  QuadMeshData quadMesh = remesh_with_field(
      mesh, field, remeshOptions,
      map_progress(std::move(progress), 20, 100));
  return {std::move(field), std::move(quadMesh)};
}
void save_mesh(const std::filesystem::path &path, const MeshData &mesh) {
  const std::string extension = lowercase(path.extension().string());

  if (extension == ".obj") {
    cli::write_triangle_obj(path, mesh.vertices, mesh.faces);
    return;
  }

  if (extension == ".off") {
    cli::write_triangle_off(path, mesh.vertices, mesh.faces);
    return;
  }

  throw std::runtime_error("Mesh output must use .obj or .off.");
}
void save_quad_mesh(const std::filesystem::path &path,
                    const QuadMeshData &mesh) {
  const std::string extension = lowercase(path.extension().string());
  const Eigen::VectorXi degrees =
      Eigen::VectorXi::Constant(mesh.faces.rows(), 4);
  if (extension == ".obj") {
    cli::write_polygonal_obj(path, mesh.vertices, degrees, mesh.faces);
    return;
  }
  if (extension == ".off") {
    cli::write_polygonal_off(path, mesh.vertices, degrees, mesh.faces);
    return;
  }
  throw std::runtime_error("Quad mesh output must use .obj or .off.");
}

void validate_field(const FieldData &field, const Eigen::Index faceCount) {
  if (field.degree != 4) {
    throw std::runtime_error(
        "The remeshing UI requires a degree-4 cross field.");
  }
  if (has_raw_cross_field(field, faceCount) ||
      has_axis_cross_field(field, faceCount)) {
    return;
  }

  const bool rawShapeLooksRelevant = field.raw.rows() == faceCount ||
                                     field.raw.cols() == 6 ||
                                     field.raw.cols() == 12;
  if (rawShapeLooksRelevant && field.raw.size() != 0 &&
      !field.raw.array().isFinite().all()) {
    throw std::runtime_error("The field contains non-finite raw values.");
  }
  if ((field.primary.size() != 0 || field.secondary.size() != 0) &&
      (!field.primary.array().isFinite().all() ||
       !field.secondary.array().isFinite().all())) {
    throw std::runtime_error("The field contains non-finite axis values.");
  }

  throw std::runtime_error(
      "The field must contain either one 12-value raw cross per mesh face "
      "or two 3D cross axes per mesh face. NeurCross .txt files should be "
      "loaded as CrossField / NeurCross, not as raw 12-column fields.");
}

void validate_options(const FieldOptions &fieldOptions,
                      const RemeshOptions &remeshOptions) {
  if (!std::isfinite(remeshOptions.lengthRatio) ||
      remeshOptions.lengthRatio <= 0.0) {
    throw std::runtime_error("Length ratio must be positive.");
  }
  if (fieldOptions.method != FieldMethod::RegularizedCurvature) {
    return;
  }
  if (!std::isfinite(fieldOptions.proxyFidelityWeight) ||
      fieldOptions.proxyFidelityWeight <= 0.0 ||
      !std::isfinite(fieldOptions.proxySmoothnessWeight) ||
      fieldOptions.proxySmoothnessWeight < 0.0 ||
      !std::isfinite(fieldOptions.fieldSmoothnessWeight) ||
      fieldOptions.fieldSmoothnessWeight <= 0.0 ||
      !std::isfinite(fieldOptions.curvatureAlignmentWeight) ||
      fieldOptions.curvatureAlignmentWeight <= 0.0 ||
      !std::isfinite(fieldOptions.minimumConfidence) ||
      fieldOptions.minimumConfidence < 0.0 ||
      !std::isfinite(fieldOptions.confidenceExponent) ||
      fieldOptions.confidenceExponent <= 0.0 ||
      fieldOptions.curvatureSmoothingIterations < 0) {
    throw std::runtime_error(
        "Regularized-curvature options contain an invalid value.");
  }
}

} // namespace directional::gui
