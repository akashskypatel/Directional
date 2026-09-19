#include "CliCommands.h"

#include "CrossFieldOutput.h"
#include "FieldConversion.h"
#include "MatrixIO.h"
#include "MeshIO.h"
#include "RemeshOutput.h"
#include "ProgressDisplay.h"

#include <cmath>
#include <filesystem>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

#include <directional/fields/RegularizedCurvatureCrossField.h>
#include <directional/pipeline/RemeshPipeline.h>

namespace directional::cli {
namespace {

enum class GeneratedFieldMethod { Smooth, RegularizedCurvature };

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

double parse_numeric_option(const std::string &text, const char *optionName) {
  std::size_t parsed = 0;
  const double value = std::stod(text, &parsed);
  if (parsed != text.size() || !std::isfinite(value)) {
    throw std::runtime_error(std::string(optionName) +
                             " requires a numeric value.");
  }
  return value;
}

int parse_integer_option(const std::string &text, const char *optionName) {
  std::size_t parsed = 0;
  const int value = std::stoi(text, &parsed);
  if (parsed != text.size()) {
    throw std::runtime_error(std::string(optionName) +
                             " requires an integer value.");
  }
  return value;
}

IntegrationSolveStrategy parse_integration_solve_strategy(
    const std::string &text, const char *optionName) {
  if (text == "direct" || text == "direct-only" || text == "DirectOnly") {
    return IntegrationSolveStrategy::DirectOnly;
  }
  if (text == "adaptive" || text == "Adaptive") {
    return IntegrationSolveStrategy::Adaptive;
  }
  throw std::runtime_error(std::string(optionName) +
                           " requires direct or adaptive.");
}

void validate_direction_matrix(const Eigen::MatrixXd &matrix,
                               const Eigen::Index faceCount,
                               const char *name) {
  if (matrix.rows() != faceCount || matrix.cols() != 3) {
    throw std::runtime_error(std::string(name) +
                             " must have shape (#F, 3).");
  }
}

GeneratedFieldMethod parse_generated_field_method(const std::string &value) {
  if (value == "smooth") {
    return GeneratedFieldMethod::Smooth;
  }
  if (value == "regularized-curvature") {
    return GeneratedFieldMethod::RegularizedCurvature;
  }
  throw std::runtime_error(
      "--field-method must be smooth or regularized-curvature.");
}

} // namespace

int run_remesh(const int argc, char **argv) {
  if (argc < 4) {
    throw std::runtime_error(
        "remesh requires an input mesh and output .obj or .off path.");
  }

  const std::filesystem::path inputPath = argv[2];
  const std::filesystem::path outputPath = argv[3];
  std::optional<std::filesystem::path> fieldPath;
  std::string fieldFormat = "auto";
  std::optional<std::filesystem::path> rawFieldPath;
  std::optional<std::filesystem::path> primaryDirectionsPath;
  std::optional<std::filesystem::path> secondaryDirectionsPath;
  std::optional<std::filesystem::path> diagnosticsPrefix;
  GeneratedFieldMethod generatedFieldMethod = GeneratedFieldMethod::Smooth;
  pipeline::RemeshOptions options;
  fields::RegularizedCurvatureCrossFieldOptions regularizedFieldOptions;

  for (int argument = 4; argument < argc; ++argument) {
    const std::string option = argv[argument];
    if (option == "--field") {
      if (++argument >= argc) {
        throw std::runtime_error("--field requires an input path.");
      }
      fieldPath = std::filesystem::path(argv[argument]);
    } else if (option == "--field-format") {
      if (++argument >= argc) {
        throw std::runtime_error("--field-format requires a value.");
      }
      fieldFormat = argv[argument];
    } else if (option == "--field-method") {
      if (++argument >= argc) {
        throw std::runtime_error("--field-method requires a value.");
      }
      generatedFieldMethod = parse_generated_field_method(argv[argument]);
    } else if (option == "--raw-field") {
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
    } else if (option == "--integration-solve-strategy") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--integration-solve-strategy requires direct or adaptive.");
      }
      options.integrationSolveStrategy = parse_integration_solve_strategy(
          argv[argument], "--integration-solve-strategy");
    } else if (option == "--remesh-backend") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--remesh-backend requires LegacyInteger or SurfaceCells.");
      }
      options.backend = pipeline::parse_remesh_backend(argv[argument]);
      options.surfaceCells.enabled =
          options.backend == pipeline::RemeshBackend::SurfaceCells;
    } else if (option == "--surface-cell-fallback") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--surface-cell-fallback requires Fail or ReturnInputMesh.");
      }
      options.surfaceCells.fallbackPolicy =
          pipeline::parse_surface_cell_fallback_policy(argv[argument]);
    } else if (option == "--surface-cell-preserve-debug-artifacts") {
      options.surfaceCells.preserveDebugArtifacts = true;
      options.surfaceCells.retainIntermediateGeometry = true;
    } else if (option == "--surface-cell-skeleton-hints") {
      options.surfaceCells.useSkeletonHints = true;
    } else if (option ==
               "--surface-cell-split-unmarked-sharp-bends") {
      options.surfaceCells.sourceClassifier.traverseUnmarkedSharpBends = false;
    } else if (option ==
               "--surface-cell-traverse-unmarked-sharp-bends") {
      options.surfaceCells.sourceClassifier.traverseUnmarkedSharpBends = true;
    } else if (option ==
               "--surface-cell-sheet-normal-compatibility") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--surface-cell-sheet-normal-compatibility requires a value in [0, 1].");
      }
      options.surfaceCells.sourceClassifier.normalCompatibility =
          parse_numeric_option(
              argv[argument],
              "--surface-cell-sheet-normal-compatibility");
    } else if (option == "--surface-cell-close-sheet-radius") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--surface-cell-close-sheet-radius requires a positive mean-edge factor.");
      }
      options.surfaceCells.sourceClassifier.closeSheetRadiusMeanEdges =
          parse_positive_double(argv[argument],
                                "--surface-cell-close-sheet-radius");
    } else if (option ==
               "--surface-cell-geodesic-exclusion-depth") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--surface-cell-geodesic-exclusion-depth requires an edge-ring count.");
      }
      options.surfaceCells.sourceClassifier.geodesicExclusionDepth =
          parse_integer_option(
              argv[argument],
              "--surface-cell-geodesic-exclusion-depth");
    } else if (option == "--simplification-backend") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--simplification-backend requires directional or triflow-dcel.");
      }
      const std::string backend = argv[argument];
      if (backend == "directional") {
        options.useTriFlowDcelSimplification = false;
      } else if (backend == "triflow-dcel") {
        options.useTriFlowDcelSimplification = true;
      } else {
        throw std::runtime_error(
            "--simplification-backend requires directional or triflow-dcel.");
      }
    } else if (option == "--experimental-triflow-dcel-simplify" ||
               option == "--use-triflow-dcel-simplification") {
      options.useTriFlowDcelSimplification = true;
    } else if (option == "--no-normalize-directions" ||
               option == "--no-normalize") {
      options.normalizeDirections = false;
      regularizedFieldOptions.normalizeDirections = false;
    } else if (option == "--proxy-fidelity") {
      if (++argument >= argc) {
        throw std::runtime_error("--proxy-fidelity requires a value.");
      }
      regularizedFieldOptions.proxy.fidelityWeight =
          parse_numeric_option(argv[argument], "--proxy-fidelity");
    } else if (option == "--proxy-smoothness") {
      if (++argument >= argc) {
        throw std::runtime_error("--proxy-smoothness requires a value.");
      }
      regularizedFieldOptions.proxy.smoothnessWeight =
          parse_numeric_option(argv[argument], "--proxy-smoothness");
    } else if (option == "--no-preserve-boundary") {
      regularizedFieldOptions.proxy.preserveBoundary = false;
    } else if (option == "--no-preserve-sharp-features") {
      regularizedFieldOptions.proxy.preserveSharpFeatures = false;
      regularizedFieldOptions.curvature.preserveSharpFeatures = false;
    } else if (option == "--no-feature-aware-corner-normals") {
      regularizedFieldOptions.curvature.useFeatureAwareCornerNormals = false;
    } else if (option == "--field-smoothness") {
      if (++argument >= argc) {
        throw std::runtime_error("--field-smoothness requires a value.");
      }
      regularizedFieldOptions.fieldSmoothnessWeight =
          parse_numeric_option(argv[argument], "--field-smoothness");
    } else if (option == "--curvature-alignment") {
      if (++argument >= argc) {
        throw std::runtime_error("--curvature-alignment requires a value.");
      }
      regularizedFieldOptions.curvatureAlignmentWeight =
          parse_numeric_option(argv[argument], "--curvature-alignment");
    } else if (option == "--boundary-alignment") {
      if (++argument >= argc) {
        throw std::runtime_error("--boundary-alignment requires a value.");
      }
      regularizedFieldOptions.boundaryAlignmentWeight =
          parse_numeric_option(argv[argument], "--boundary-alignment");
    } else if (option == "--sharp-feature-alignment") {
      if (++argument >= argc) {
        throw std::runtime_error("--sharp-feature-alignment requires a value.");
      }
      regularizedFieldOptions.sharpFeatureAlignmentWeight =
          parse_numeric_option(argv[argument], "--sharp-feature-alignment");
    } else if (option == "--curvature-min-confidence") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--curvature-min-confidence requires a value.");
      }
      regularizedFieldOptions.minimumConfidence =
          parse_numeric_option(argv[argument], "--curvature-min-confidence");
    } else if (option == "--curvature-confidence-exponent") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--curvature-confidence-exponent requires a value.");
      }
      regularizedFieldOptions.confidenceExponent = parse_numeric_option(
          argv[argument], "--curvature-confidence-exponent");
    } else if (option == "--curvature-smoothing-iterations") {
      if (++argument >= argc) {
        throw std::runtime_error(
            "--curvature-smoothing-iterations requires a value.");
      }
      regularizedFieldOptions.curvature.smoothingIterations =
          parse_integer_option(argv[argument],
                               "--curvature-smoothing-iterations");
    } else if (option == "--curvature-sharp-angle") {
      if (++argument >= argc) {
        throw std::runtime_error("--curvature-sharp-angle requires a value.");
      }
      const double angle =
          parse_numeric_option(argv[argument], "--curvature-sharp-angle");
      regularizedFieldOptions.proxy.sharpFeatureAngleDegrees = angle;
      regularizedFieldOptions.curvature.sharpFeatureAngleDegrees = angle;
    } else if (option == "--smooth-curvature-across-features") {
      regularizedFieldOptions.curvature.preserveSharpFeatures = false;
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

  if (fieldPath.has_value() &&
      (rawFieldPath.has_value() || primaryDirectionsPath.has_value() ||
       secondaryDirectionsPath.has_value())) {
    throw std::runtime_error(
        "--field cannot be combined with legacy field input options.");
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

  constexpr std::size_t progressTotal = 100;
  ProgressDisplay progress(std::cout, !options.verbose);
  progress.update(2, progressTotal, "Loading input mesh");
  const MeshData mesh = load_mesh(inputPath);
  options.progress = progress.range(5, 90, progressTotal);

  pipeline::RemeshResult result;
  if (fieldPath.has_value()) {
    const FieldFormat format = infer_field_format(*fieldPath, fieldFormat);
    const FieldData field = read_field(*fieldPath, format, &mesh);
    if (field.primary.rows() != mesh.faces.rows() ||
        field.secondary.rows() != mesh.faces.rows()) {
      throw std::runtime_error(
          "Field row count must match the mesh face count.");
    }
    if (format == FieldFormat::RawField && field.degree == 4 &&
        field.raw.cols() == 12) {
      result = pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);
    } else {
      result = pipeline::remesh_from_cross_field(
          mesh.vertices, mesh.faces, field.primary, field.secondary, options);
    }
  } else if (rawFieldPath.has_value()) {
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
  } else if (generatedFieldMethod == GeneratedFieldMethod::RegularizedCurvature) {
    regularizedFieldOptions.progress = progress.range(5, 20, progressTotal);
    regularizedFieldOptions.combDirections = true;
    regularizedFieldOptions.computeMatching = false;
    const fields::RegularizedCurvatureCrossFieldResult crossField =
        fields::extract_regularized_curvature_cross_field(
            mesh.vertices, mesh.faces, regularizedFieldOptions);
    pipeline::RemeshOptions pipelineOptions = options;
    pipelineOptions.progress = progress.range(20, 90, progressTotal);
    result = pipeline::remesh_from_raw_cross_field(
        mesh.vertices, mesh.faces, crossField.field.rawField, pipelineOptions);
  } else {
    result = pipeline::remesh_from_mesh(mesh.vertices, mesh.faces, options);
  }

  if (!result.is_produced()) {
    throw std::runtime_error(
        "Remeshing failed while simplifying or assembling the output mesh"
        " (backend=" + result.diagnostics.remeshBackend +
        ", failure=" + result.diagnostics.terminalFailureCode +
        ", stage=" + result.diagnostics.terminalFailureStage + ").");
  }

  progress.update(95, progressTotal, "Writing remeshed output");
  write_remeshed_mesh(outputPath, result.product().vertices, result.product().degrees,
                      result.product().faces);

  if (diagnosticsPrefix.has_value()) {
    write_remesh_diagnostics(
        *diagnosticsPrefix, outputPath.extension().string(), result.product().degrees, result.product().cutVertices,
        result.product().cutFaces, result.product().cutFunctions, result.product().cutCornerFunctions,
        result.product().rawCrossField, result.product().crossFieldMatching,
        result.product().crossFieldEffort, result.product().crossFieldSingularCycles,
        result.product().crossFieldSingularIndices, result.diagnostics);
  }

  progress.update(100, progressTotal, "Finalizing remesh pipeline");
  progress.finish();

  std::cout << "Remeshed " << mesh.faces.rows() << " source triangles into "
            << result.product().faces.rows() << " polygons.\n";
  std::cout << "Wrote " << outputPath.string() << '\n';
  return 0;
}

} // namespace directional::cli
