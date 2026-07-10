#include "CliCommands.h"
#include "FieldConversion.h"
#include "MeshIO.h"
#include "ProgressDisplay.h"

#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include <directional/fields/CompareCrossFields.h>

namespace directional::cli {
namespace {

inline double parse_double_option(const std::string &name, const char *value) {
  try {
    std::size_t parsed = 0;
    const double result = std::stod(value, &parsed);
    if (parsed != std::string(value).size()) {
      throw std::invalid_argument("trailing characters");
    }
    return result;
  } catch (const std::exception &) {
    throw std::runtime_error(name + " requires a numeric value.");
  }
}

inline int parse_int_option(const std::string &name, const char *value) {
  try {
    std::size_t parsed = 0;
    const int result = std::stoi(value, &parsed);
    if (parsed != std::string(value).size()) {
      throw std::invalid_argument("trailing characters");
    }
    return result;
  } catch (const std::exception &) {
    throw std::runtime_error(name + " requires an integer value.");
  }
}

inline std::filesystem::path with_suffix(const std::filesystem::path &prefix,
                                  const std::string &suffix) {
  return std::filesystem::path(prefix.string() + suffix);
}

} // namespace

inline int run_compare_fields(const int argc, char **argv) {
  if (argc < 5) {
    throw std::runtime_error(
        "compare-fields requires input mesh, first field, and second field paths.");
  }

  const std::filesystem::path meshPath = argv[2];
  const std::filesystem::path firstFieldPath = argv[3];
  const std::filesystem::path secondFieldPath = argv[4];

  std::string firstFormat = "auto";
  std::string secondFormat = "auto";
  std::optional<std::filesystem::path> csvPath;
  std::optional<std::filesystem::path> heatmapPath;
  std::optional<std::filesystem::path> jsonPath;
  std::optional<std::filesystem::path> outputPrefix;
  double highErrorThreshold = 20.0;
  bool removeGlobalPhase = true;
  bool computeShapeOperatorAlignment = false;
  fields::ShapeOperatorAlignmentOptions shapeOptions;
  bool verbose = false;

  for (int argument = 5; argument < argc; ++argument) {
    const std::string option = argv[argument];
    const auto require_value = [&](const std::string &name) -> const char * {
      if (++argument >= argc) {
        throw std::runtime_error(name + " requires a value.");
      }
      return argv[argument];
    };

    if (option == "--first-format" || option == "--candidate-format") {
      firstFormat = require_value(option);
    } else if (option == "--second-format" || option == "--reference-format") {
      secondFormat = require_value(option);
    } else if (option == "--csv") {
      csvPath = std::filesystem::path(require_value(option));
    } else if (option == "--heatmap") {
      heatmapPath = std::filesystem::path(require_value(option));
    } else if (option == "--json") {
      jsonPath = std::filesystem::path(require_value(option));
    } else if (option == "--prefix") {
      outputPrefix = std::filesystem::path(require_value(option));
    } else if (option == "--high-error-threshold") {
      highErrorThreshold = parse_double_option(option, require_value(option));
    } else if (option == "--shape-operator-alignment" ||
               option == "--shape-alignment") {
      computeShapeOperatorAlignment = true;
    } else if (option == "--shape-no-proxy") {
      shapeOptions.useRegularizedProxy = false;
    } else if (option == "--shape-proxy-fidelity") {
      shapeOptions.proxy.fidelityWeight =
          parse_double_option(option, require_value(option));
    } else if (option == "--shape-proxy-smoothness") {
      shapeOptions.proxy.smoothnessWeight =
          parse_double_option(option, require_value(option));
    } else if (option == "--shape-no-preserve-boundary") {
      shapeOptions.proxy.preserveBoundary = false;
    } else if (option == "--shape-curvature-min-confidence") {
      shapeOptions.minimumConfidence =
          parse_double_option(option, require_value(option));
    } else if (option == "--shape-curvature-confidence-exponent") {
      shapeOptions.confidenceExponent =
          parse_double_option(option, require_value(option));
    } else if (option == "--shape-curvature-smoothing-iterations") {
      shapeOptions.curvature.smoothingIterations =
          parse_int_option(option, require_value(option));
    } else if (option == "--keep-global-phase") {
      removeGlobalPhase = false;
    } else if (option == "--verbose") {
      verbose = true;
    } else {
      throw std::runtime_error("Unknown compare-fields option: " + option);
    }
  }

  if (outputPrefix.has_value()) {
    if (!csvPath.has_value()) {
      csvPath = with_suffix(*outputPrefix, "_field_difference.csv");
    }
    if (!heatmapPath.has_value()) {
      heatmapPath = with_suffix(*outputPrefix, "_field_difference.ply");
    }
    if (!jsonPath.has_value()) {
      jsonPath = with_suffix(*outputPrefix, "_field_summary.json");
    }
  }

  fields::CrossFieldComparisonOptions options;
  options.removeGlobalPhase = removeGlobalPhase;
  options.highErrorThresholdDegrees = highErrorThreshold;
  options.computeShapeOperatorAlignment = computeShapeOperatorAlignment;
  options.shapeOperatorAlignment = shapeOptions;

  constexpr std::size_t progressTotal = 5;
  ProgressDisplay progress(std::cout, !verbose);
  progress.update(1, progressTotal, "Loading mesh");
  const MeshData mesh = load_mesh(meshPath);

  progress.update(2, progressTotal, "Loading first field");
  const FieldData first = read_field(
      firstFieldPath, infer_field_format(firstFieldPath, firstFormat), &mesh);

  progress.update(3, progressTotal, "Loading second field");
  const FieldData second = read_field(
      secondFieldPath, infer_field_format(secondFieldPath, secondFormat), &mesh);

  progress.update(4, progressTotal, "Comparing cross fields");
  const fields::CrossFieldComparisonResult comparison =
      fields::compare_cross_fields(mesh.vertices, mesh.faces, first.raw,
                                   second.raw, options);

  if (csvPath.has_value()) {
    fields::write_cross_field_comparison_csv(*csvPath, comparison);
  }
  if (heatmapPath.has_value()) {
    fields::write_cross_field_comparison_ply(*heatmapPath, mesh.vertices,
                                             mesh.faces, comparison);
  }
  if (jsonPath.has_value()) {
    fields::write_cross_field_comparison_json(*jsonPath, comparison);
  }

  progress.update(5, progressTotal, "Finalizing field comparison");
  progress.finish();

  std::cout << fields::summarize_cross_field_comparison(comparison);
  if (csvPath.has_value()) {
    std::cout << "Wrote CSV: " << csvPath->string() << '\n';
  }
  if (heatmapPath.has_value()) {
    std::cout << "Wrote heatmap: " << heatmapPath->string() << '\n';
  }
  if (jsonPath.has_value()) {
    std::cout << "Wrote JSON: " << jsonPath->string() << '\n';
  }
  return 0;
}

} // namespace directional::cli
