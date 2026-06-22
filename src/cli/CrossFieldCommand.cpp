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
  fields::CrossFieldOptions options;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    if (option == "--no-normalize") {
      options.normalizeDirections = false;
    } else if (option == "--singularities") {
      if (++argument >= argc) {
        throw std::runtime_error("--singularities requires an output path.");
      }
      singularitiesPath = std::filesystem::path(argv[argument]);
    } else {
      throw std::runtime_error("Unknown cross-field option: " + option);
    }
  }

  const MeshData mesh = load_mesh(inputPath);
  const fields::CrossFieldResult result =
      fields::extract_cross_field(mesh.vertices, mesh.faces, options);

  write_raw_field(outputPath, result.degree, result.rawField);

  if (singularitiesPath.has_value()) {
    write_singularities_file(*singularitiesPath, result.degree,
                             result.singularCycles, result.singularIndices);
  }

  std::cout << "Extracted " << result.degree << "-RoSy cross field on "
            << result.rawField.rows() << " faces with "
            << result.singularIndices.size() << " singularities.\n";
  std::cout << "Wrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace directional::cli
