#include "CliCommands.h"

#include "CrossFieldOutput.h"
#include "MatrixIO.h"
#include "MeshIO.h"
#include "RemeshOutput.h"

#include <cmath>
#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include <directional/pipeline/RemeshPipeline.h>

namespace directional::cli {
namespace {

double parse_positive_double(const std::string &text,
                             const char *optionName) {
  std::size_t parsed = 0;
  const double value = std::stod(text, &parsed);
  if (parsed != text.size() || !std::isfinite(value) || value <= 0.0) {
    throw std::runtime_error(std::string(optionName) +
                             " requires a positive numeric value.");
  }
  return value;
}

void validate_direction_matrix(const Eigen::MatrixXd &matrix,
                               const Eigen::Index faceCount,
                               const char *name) {
  if (matrix.rows() != faceCount || matrix.cols() != 3) {
    throw std::runtime_error(std::string(name) +
                             " must have shape (#F, 3).");
  }
}

} // namespace

int run_remesh(const int argc, char **argv) {
  if (argc < 4) {
    throw std::runtime_error(
        "remesh requires an input mesh and output .off path.");
  }

  const std::filesystem::path inputPath = argv[2];
  const std::filesystem::path outputPath = argv[3];
  std::optional<std::filesystem::path> rawFieldPath;
  std::optional<std::filesystem::path> primaryDirectionsPath;
  std::optional<std::filesystem::path> secondaryDirectionsPath;
  std::optional<std::filesystem::path> diagnosticsPrefix;
  pipeline::RemeshOptions options;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    if (option == "--raw-field") {
      if (++argument >= argc) {
        throw std::runtime_error("--raw-field requires an input path.");
      }
      rawFieldPath = std::filesystem::path(argv[argument]);
    } else if (option == "--primary-directions") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--primary-directions requires a DMAT input path.");
      }
      primaryDirectionsPath = std::filesystem::path(argv[argument]);
    } else if (option == "--secondary-directions") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--secondary-directions requires a DMAT input path.");
      }
      secondaryDirectionsPath = std::filesystem::path(argv[argument]);
    } else if (option == "--length-ratio") {
      if (++argument >= argc) {
        throw std::runtime_error("--length-ratio requires a value.");
      }
      options.lengthRatio =
          parse_positive_double(argv[argument], "--length-ratio");
    } else if (option == "--no-integral-seamless") {
      options.integralSeamless = false;
    } else if (option == "--round-seams") {
      options.roundSeams = true;
    } else if (option == "--feature-align") {
      options.featureAlign = true;
    } else if (option == "--no-normalize-directions" ||
               option == "--no-normalize") {
      options.normalizeDirections = false;
    } else if (option == "--diagnostics-prefix") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--diagnostics-prefix requires an output prefix.");
      }
      diagnosticsPrefix = std::filesystem::path(argv[argument]);
    } else if (option == "--verbose") {
      options.verbose = true;
    } else {
      throw std::runtime_error("Unknown remesh option: " + option);
    }
  }

  if (rawFieldPath.has_value() && primaryDirectionsPath.has_value()) {
    throw std::runtime_error(
        "--raw-field and --primary-directions are mutually exclusive.");
  }
  if (rawFieldPath.has_value() && secondaryDirectionsPath.has_value()) {
    throw std::runtime_error(
        "--raw-field and --secondary-directions are mutually exclusive.");
  }
  if (secondaryDirectionsPath.has_value() &&
      !primaryDirectionsPath.has_value()) {
    throw std::runtime_error(
        "--secondary-directions requires --primary-directions.");
  }

  if (options.verbose) {
    std::cout << "Loading mesh: " << inputPath.string() << '\n';
  }
  const MeshData mesh = load_mesh(inputPath);

  pipeline::RemeshResult result;
  if (rawFieldPath.has_value()) {
    if (options.verbose) {
      std::cout << "Using raw cross field: " << rawFieldPath->string() << '\n';
    }
    const RawFieldData rawField = read_raw_field(*rawFieldPath);
    if (rawField.degree != 4) {
      throw std::runtime_error(
          "The remeshing pipeline requires a degree-4 raw cross field.");
    }
    if (rawField.values.rows() != mesh.faces.rows()) {
      throw std::runtime_error(
          "Raw cross-field row count must match the mesh face count.");
    }
    result = pipeline::remesh_from_raw_cross_field(
        mesh.vertices, mesh.faces, rawField.values, options);
  } else if (primaryDirectionsPath.has_value()) {
    Eigen::MatrixXd primary = read_dmat_double(*primaryDirectionsPath);
    validate_direction_matrix(primary, mesh.faces.rows(),
                              "Primary directions");

    if (secondaryDirectionsPath.has_value()) {
      Eigen::MatrixXd secondary = read_dmat_double(*secondaryDirectionsPath);
      validate_direction_matrix(secondary, mesh.faces.rows(),
                                "Secondary directions");
      result = pipeline::remesh_from_cross_field(
          mesh.vertices, mesh.faces, primary, secondary, options);
    } else {
      result = pipeline::remesh_from_cross_field(
          mesh.vertices, mesh.faces, primary, options);
    }
  } else {
    if (options.verbose) {
      std::cout << "No field supplied; extracting a degree-4 cross field.\n";
    }
    result = pipeline::remesh_from_mesh(mesh.vertices, mesh.faces, options);
  }

  if (!result.success) {
    throw std::runtime_error(
        "Remeshing failed while simplifying or assembling the output mesh.");
  }

  write_remeshed_mesh(outputPath, result.vertices, result.degrees,
                      result.faces);

  if (diagnosticsPrefix.has_value()) {
    write_remesh_diagnostics(
        *diagnosticsPrefix, result.degrees, result.cutVertices,
        result.cutFaces, result.cutFunctions, result.cutCornerFunctions,
        result.rawCrossField, result.crossFieldMatching,
        result.crossFieldEffort, result.crossFieldSingularCycles,
        result.crossFieldSingularIndices);
  }

  std::cout << "Remeshed " << mesh.faces.rows() << " source triangles into "
            << result.faces.rows() << " polygons.\n";
  std::cout << "Wrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace directional::cli
