#include "CliCommands.h"

#include "MatrixIO.h"
#include "MeshIO.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include <directional/meshing/TriFlowSimplification.h>

namespace directional::cli {
namespace {

std::string lowercase(std::string value) {
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

int parse_positive_int(const std::string &text, const char *optionName) {
  std::size_t parsed = 0;
  const int value = std::stoi(text, &parsed);
  if (parsed != text.size() || value <= 0) {
    throw std::runtime_error(std::string(optionName) +
                             " requires a positive integer value.");
  }
  return value;
}

double parse_nonnegative_double(const std::string &text,
                                const char *optionName) {
  std::size_t parsed = 0;
  const double value = std::stod(text, &parsed);
  if (parsed != text.size() || !std::isfinite(value) || value < 0.0) {
    throw std::runtime_error(std::string(optionName) +
                             " requires a non-negative numeric value.");
  }
  return value;
}

double parse_positive_double(const std::string &text, const char *optionName) {
  const double value = parse_nonnegative_double(text, optionName);
  if (value <= 0.0) {
    throw std::runtime_error(std::string(optionName) +
                             " requires a positive numeric value.");
  }
  return value;
}

void write_simplified_mesh(const std::filesystem::path &path,
                           const Eigen::MatrixXd &vertices,
                           const Eigen::MatrixXi &faces) {
  const std::string extension = lowercase(path.extension().string());
  if (extension == ".obj") {
    write_triangle_obj(path, vertices, faces);
    return;
  }
  if (extension == ".off") {
    write_triangle_off(path, vertices, faces);
    return;
  }
  throw std::runtime_error(
      "Simplification output must use the .obj or .off extension.");
}

std::filesystem::path sidecar(const std::filesystem::path &prefix,
                              const char *suffix) {
  return std::filesystem::path(prefix.string() + suffix);
}

} // namespace

int run_simplify(const int argc, char **argv) {
  if (argc < 4) {
    throw std::runtime_error(
        "simplify requires an input mesh and output .obj or .off path.");
  }

  const std::filesystem::path inputPath = argv[2];
  const std::filesystem::path outputPath = argv[3];
  std::optional<std::filesystem::path> nvfPath;
  std::optional<std::filesystem::path> targetPath;
  std::optional<std::filesystem::path> diagnosticsPrefix;
  TriFlowSimplificationOptions options;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    if (option == "--target-faces") {
      if (++argument >= argc) {
        throw std::runtime_error("--target-faces requires a value.");
      }
      options.targetFaceCount = parse_positive_int(argv[argument],
                                                   "--target-faces");
    } else if (option == "--ratio") {
      if (++argument >= argc) {
        throw std::runtime_error("--ratio requires a value.");
      }
      options.targetFaceRatio = parse_positive_double(argv[argument],
                                                      "--ratio");
      if (options.targetFaceRatio > 1.0) {
        throw std::runtime_error("--ratio must be in the range (0, 1].");
      }
    } else if (option == "--nvf") {
      if (++argument >= argc) {
        throw std::runtime_error("--nvf requires a DMAT input path.");
      }
      nvfPath = std::filesystem::path(argv[argument]);
    } else if (option == "--targets") {
      if (++argument >= argc) {
        throw std::runtime_error("--targets requires a DMAT input path.");
      }
      targetPath = std::filesystem::path(argv[argument]);
    } else if (option == "--root-threshold") {
      if (++argument >= argc) {
        throw std::runtime_error("--root-threshold requires a value.");
      }
      options.rootThreshold = parse_nonnegative_double(argv[argument],
                                                       "--root-threshold");
    } else if (option == "--voxel-resolution") {
      if (++argument >= argc) {
        throw std::runtime_error("--voxel-resolution requires a value.");
      }
      options.voxelResolution = parse_positive_int(argv[argument],
                                                   "--voxel-resolution");
    } else if (option == "--topology-weight") {
      if (++argument >= argc) {
        throw std::runtime_error("--topology-weight requires a value.");
      }
      options.topologyWeight = parse_nonnegative_double(argv[argument],
                                                        "--topology-weight");
    } else if (option == "--root-relaxation-threshold") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--root-relaxation-threshold requires a value.");
      }
      options.rootRelaxationThreshold = parse_nonnegative_double(
          argv[argument], "--root-relaxation-threshold");
    } else if (option == "--no-preserve-boundary") {
      options.preserveBoundary = false;
    } else if (option == "--allow-face-flips") {
      options.rejectFaceFlips = false;
    } else if (option == "--diagnostics-prefix") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--diagnostics-prefix requires an output prefix.");
      }
      diagnosticsPrefix = std::filesystem::path(argv[argument]);
    } else if (option == "--verbose") {
      options.verbose = true;
    } else {
      throw std::runtime_error("Unknown simplify option: " + option);
    }
  }

  if (nvfPath.has_value() && targetPath.has_value()) {
    throw std::runtime_error("--nvf and --targets are mutually exclusive.");
  }

  const MeshData mesh = load_mesh(inputPath);

  if (nvfPath.has_value()) {
    options.vertexNvf = read_dmat_double(*nvfPath);
    if (options.vertexNvf.rows() != mesh.vertices.rows() ||
        options.vertexNvf.cols() != 3) {
      throw std::runtime_error(
          "--nvf matrix must have shape (#input vertices, 3).");
    }
  }
  if (targetPath.has_value()) {
    options.vertexTargets = read_dmat_double(*targetPath);
    if (options.vertexTargets.rows() != mesh.vertices.rows() ||
        options.vertexTargets.cols() != 3) {
      throw std::runtime_error(
          "--targets matrix must have shape (#input vertices, 3).");
    }
  }

  TriFlowSimplificationResult result =
      tri_flow_simplify(mesh.vertices, mesh.faces, options);
  if (!result.success) {
    throw std::runtime_error("Simplification failed to produce a valid mesh.");
  }

  write_simplified_mesh(outputPath, result.vertices, result.faces);

  if (diagnosticsPrefix.has_value()) {
    write_dmat(sidecar(*diagnosticsPrefix, ".root_labels.dmat"),
               result.rootLabels);
  }

  std::cout << "Simplified " << mesh.faces.rows() << " source triangles into "
            << result.faces.rows() << " triangles using " << result.rootCount
            << " watershed roots and " << result.collapsedEdges
            << " edge collapses.\n";
  std::cout << "Wrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace directional::cli
