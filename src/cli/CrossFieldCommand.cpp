#include "CliCommands.h"
#include "CrossFieldOutput.h"
#include "MeshIO.h"

#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include <directional/fields/CrossField.h>

namespace directional::cli {

int run_cross_field(const int argc, char **argv) {
  if (argc < 4) {
    throw std::runtime_error(
        "cross-field requires an input mesh and output .rawfield path.");
  }

  const std::filesystem::path inputPath = argv[2];
  const std::filesystem::path outputPath = argv[3];
  std::optional<std::filesystem::path> singularitiesPath;
  std::optional<std::filesystem::path> diagnosticsPrefix;
  bool verbose = false;
  fields::CrossFieldOptions options;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    if (option == "--no-normalize" ||
        option == "--no-normalize-directions") {
      options.normalizeDirections = false;
    } else if (option == "--no-matching") {
      options.computeMatching = false;
    } else if (option == "--verbose") {
      verbose = true;
    } else if (option == "--singularities") {
      if (++argument >= argc) {
        throw std::runtime_error("--singularities requires an output path.");
      }
      singularitiesPath = std::filesystem::path(argv[argument]);
    } else if (option == "--diagnostics-prefix") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--diagnostics-prefix requires an output prefix.");
      }
      diagnosticsPrefix = std::filesystem::path(argv[argument]);
    } else {
      throw std::runtime_error("Unknown cross-field option: " + option);
    }
  }

  if (!options.computeMatching && singularitiesPath.has_value()) {
    throw std::runtime_error(
        "--singularities cannot be combined with --no-matching.");
  }

  if (verbose) {
    std::cout << "Loading mesh: " << inputPath.string() << '\n';
  }
  const MeshData mesh = load_mesh(inputPath);

  if (verbose) {
    std::cout << "Extracting a degree-4 cross field on " << mesh.faces.rows()
              << " faces.\n";
  }
  const fields::CrossFieldResult result =
      fields::extract_cross_field(mesh.vertices, mesh.faces, options);

  write_raw_field(outputPath, result.degree, result.rawField);

  if (singularitiesPath.has_value()) {
    write_singularities_file(*singularitiesPath, result.degree,
                             result.singularCycles, result.singularIndices);
  }

  if (diagnosticsPrefix.has_value()) {
    write_cross_field_diagnostics(
        *diagnosticsPrefix, result.primaryDirections,
        result.secondaryDirections, result.matching, result.effort,
        result.singularCycles, result.singularIndices);
  }

  std::cout << "Extracted " << result.degree << "-RoSy cross field on "
            << result.rawField.rows() << " faces";
  if (options.computeMatching) {
    std::cout << " with " << result.singularIndices.size()
              << " singularities";
  }
  std::cout << ".\nWrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace directional::cli
