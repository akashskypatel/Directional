#include "CliCommands.h"
#include "CrossFieldOutput.h"
#include "FieldConversion.h"
#include "MatrixIO.h"
#include "MeshIO.h"
#include "ProgressDisplay.h"

#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include <directional/fields/CrossField.h>
#include <directional/fields/RegularizedCurvatureCrossField.h>

namespace directional::cli {
namespace {

double parse_double_option(const std::string &name, const char *value) {
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

int parse_integer_option(const std::string &name, const char *value) {
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

std::filesystem::path diagnostic_path(const std::filesystem::path &prefix,
                                      const std::string &suffix) {
  return std::filesystem::path(prefix.string() + suffix);
}

} // namespace

int run_cross_field(const int argc, char **argv) {
  if (argc < 4) {
    throw std::runtime_error(
        "cross-field requires an input mesh and output field path.");
  }

  const std::filesystem::path inputPath = argv[2];
  const std::filesystem::path outputPath = argv[3];
  std::string outputFormat = "auto";
  std::string method = "smooth";
  std::optional<std::filesystem::path> singularitiesPath;
  std::optional<std::filesystem::path> diagnosticsPrefix;
  bool verbose = false;
  fields::CrossFieldOptions smoothOptions;
  fields::RegularizedCurvatureCrossFieldOptions regularizedOptions;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    const auto require_value = [&](const std::string &name) -> const char * {
      if (++argument >= argc) {
        throw std::runtime_error(name + " requires a value.");
      }
      return argv[argument];
    };

    if (option == "--method") {
      method = require_value(option);
      if (method != "smooth" && method != "regularized-curvature") {
        throw std::runtime_error(
            "--method must be smooth or regularized-curvature.");
      }
    } else if (option == "--no-normalize" ||
               option == "--no-normalize-directions") {
      smoothOptions.normalizeDirections = false;
      regularizedOptions.normalizeDirections = false;
    } else if (option == "--no-matching") {
      smoothOptions.computeMatching = false;
      regularizedOptions.computeMatching = false;
    } else if (option == "--output-format") {
      outputFormat = require_value(option);
    } else if (option == "--verbose") {
      verbose = true;
    } else if (option == "--singularities") {
      singularitiesPath = std::filesystem::path(require_value(option));
    } else if (option == "--diagnostics-prefix") {
      diagnosticsPrefix = std::filesystem::path(require_value(option));
    } else if (option == "--proxy-fidelity") {
      regularizedOptions.proxy.fidelityWeight =
          parse_double_option(option, require_value(option));
    } else if (option == "--proxy-smoothness") {
      regularizedOptions.proxy.smoothnessWeight =
          parse_double_option(option, require_value(option));
    } else if (option == "--no-preserve-boundary") {
      regularizedOptions.proxy.preserveBoundary = false;
    } else if (option == "--field-smoothness") {
      regularizedOptions.fieldSmoothnessWeight =
          parse_double_option(option, require_value(option));
    } else if (option == "--curvature-alignment") {
      regularizedOptions.curvatureAlignmentWeight =
          parse_double_option(option, require_value(option));
    } else if (option == "--curvature-min-confidence") {
      regularizedOptions.minimumConfidence =
          parse_double_option(option, require_value(option));
    } else if (option == "--curvature-confidence-exponent") {
      regularizedOptions.confidenceExponent =
          parse_double_option(option, require_value(option));
    } else if (option == "--curvature-smoothing-iterations") {
      regularizedOptions.curvature.smoothingIterations =
          parse_integer_option(option, require_value(option));
    } else if (option == "--curvature-sharp-angle") {
      regularizedOptions.curvature.sharpFeatureAngleDegrees =
          parse_double_option(option, require_value(option));
    } else if (option == "--smooth-curvature-across-features") {
      regularizedOptions.curvature.preserveSharpFeatures = false;
    } else {
      throw std::runtime_error("Unknown cross-field option: " + option);
    }
  }

  if (!smoothOptions.computeMatching && singularitiesPath.has_value()) {
    throw std::runtime_error(
        "--singularities cannot be combined with --no-matching.");
  }

  constexpr std::size_t progressTotal = 7;
  ProgressDisplay progress(std::cout, !verbose);
  progress.update(1, progressTotal, "Loading input mesh");
  const MeshData mesh = load_mesh(inputPath);

  fields::CrossFieldResult result;
  std::optional<fields::RegularizedCurvatureCrossFieldResult>
      regularizedResult;
  if (method == "regularized-curvature") {
    regularizedOptions.progress = progress.range(2, 5, progressTotal);
    regularizedResult = fields::extract_regularized_curvature_cross_field(
        mesh.vertices, mesh.faces, regularizedOptions);
    result = regularizedResult->field;
  } else {
    smoothOptions.progress = progress.range(2, 5, progressTotal);
    result = fields::extract_cross_field(mesh.vertices, mesh.faces,
                                         smoothOptions);
  }

  FieldData field;
  field.degree = result.degree;
  field.primary = result.primaryDirections;
  field.secondary = result.secondaryDirections;
  field.raw = result.rawField;
  progress.update(6, progressTotal, "Writing cross-field output");
  write_field(outputPath, infer_field_format(outputPath, outputFormat), field);

  if (singularitiesPath.has_value()) {
    write_singularities_file(*singularitiesPath, result.degree,
                             result.singularCycles, result.singularIndices);
  }

  if (diagnosticsPrefix.has_value()) {
    write_cross_field_diagnostics(
        *diagnosticsPrefix, result.primaryDirections,
        result.secondaryDirections, result.matching, result.effort,
        result.singularCycles, result.singularIndices);

    if (regularizedResult.has_value()) {
      write_triangle_obj(diagnostic_path(*diagnosticsPrefix, "_proxy.obj"),
                         regularizedResult->proxyVertices, mesh.faces);
      write_dmat(diagnostic_path(*diagnosticsPrefix,
                                 "_proxy_displacement.dmat"),
                 regularizedResult->proxyDisplacement);
      write_dmat(diagnostic_path(*diagnosticsPrefix,
                                 "_principal_curvatures.dmat"),
                 regularizedResult->proxyCurvature.principalCurvatures);
      write_dmat(diagnostic_path(*diagnosticsPrefix,
                                 "_curvature_confidence.dmat"),
                 regularizedResult->proxyCurvature.confidence);
      write_dmat(diagnostic_path(*diagnosticsPrefix,
                                 "_curvature_valid.dmat"),
                 regularizedResult->proxyCurvature.valid);
      write_dmat(diagnostic_path(*diagnosticsPrefix,
                                 "_constrained_faces.dmat"),
                 regularizedResult->constrainedFaces);
      write_dmat(diagnostic_path(*diagnosticsPrefix,
                                 "_alignment_weights.dmat"),
                 regularizedResult->alignmentWeights);
    }
  }

  progress.update(7, progressTotal, "Finalizing cross-field pipeline");
  progress.finish();

  std::cout << "Extracted " << result.degree << "-RoSy cross field on "
            << result.rawField.rows() << " faces using " << method;
  if (regularizedResult.has_value()) {
    std::cout << " with " << regularizedResult->constrainedFaces.size()
              << " curvature constraints"
              << " (smoothness energy "
              << regularizedResult->smoothnessEnergy
              << ", alignment energy "
              << regularizedResult->alignmentEnergy << ')';
  }
  if (smoothOptions.computeMatching) {
    std::cout << " and " << result.singularIndices.size()
              << " singularities";
  }
  std::cout << ".\nWrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace directional::cli
