#include "GuiBackend.h"

#include <utility>

#include <directional/fields/CrossField.h>
#include <directional/fields/RegularizedCurvatureCrossField.h>

namespace directional::gui {

FieldData calculate_field(const MeshData &mesh, const FieldOptions &options,
                          ProgressCallback progress) {
  validate_options(options, {});

  fields::CrossFieldResult field;
  if (options.method == FieldMethod::Smooth) {
    fields::CrossFieldOptions extraction;
    extraction.normalizeDirections = options.normalizeDirections;
    extraction.combDirections = true;
    extraction.computeMatching = false;
    extraction.progress = std::move(progress);
    field = fields::extract_cross_field(mesh.vertices, mesh.faces, extraction);
  } else {
    fields::RegularizedCurvatureCrossFieldOptions extraction;
    extraction.proxy.fidelityWeight = options.proxyFidelityWeight;
    extraction.proxy.smoothnessWeight = options.proxySmoothnessWeight;
    extraction.proxy.preserveBoundary = options.preserveBoundary;
    extraction.proxy.preserveSharpFeatures = options.preserveSharpFeatures;
    extraction.proxy.sharpFeatureAngleDegrees =
        options.sharpFeatureAngleDegrees;
    extraction.curvature.useFeatureAwareCornerNormals =
        options.useFeatureAwareCornerNormals;
    extraction.curvature.preserveSharpFeatures =
        options.preserveSharpFeatures;
    extraction.curvature.sharpFeatureAngleDegrees =
        options.sharpFeatureAngleDegrees;
    extraction.fieldSmoothnessWeight = options.fieldSmoothnessWeight;
    extraction.curvatureAlignmentWeight = options.curvatureAlignmentWeight;
    extraction.boundaryAlignmentWeight = options.boundaryAlignmentWeight;
    extraction.sharpFeatureAlignmentWeight =
        options.sharpFeatureAlignmentWeight;
    extraction.minimumConfidence = options.minimumConfidence;
    extraction.confidenceExponent = options.confidenceExponent;
    extraction.curvature.smoothingIterations =
        options.curvatureSmoothingIterations;
    extraction.normalizeDirections = options.normalizeDirections;
    extraction.combDirections = true;
    extraction.computeMatching = false;
    extraction.progress = std::move(progress);
    field = fields::extract_regularized_curvature_cross_field(
                mesh.vertices, mesh.faces, extraction)
                .field;
  }

  FieldData result;
  result.degree = field.degree;
  result.primary = std::move(field.primaryDirections);
  result.secondary = std::move(field.secondaryDirections);
  result.raw = std::move(field.rawField);
  return result;
}

} // namespace directional::gui
