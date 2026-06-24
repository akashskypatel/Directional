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
    extraction.computeMatching = false;
    extraction.progress = std::move(progress);
    field = fields::extract_cross_field(mesh.vertices, mesh.faces, extraction);
  } else {
    fields::RegularizedCurvatureCrossFieldOptions extraction;
    extraction.proxy.fidelityWeight = options.proxyFidelityWeight;
    extraction.proxy.smoothnessWeight = options.proxySmoothnessWeight;
    extraction.proxy.preserveBoundary = options.preserveBoundary;
    extraction.fieldSmoothnessWeight = options.fieldSmoothnessWeight;
    extraction.curvatureAlignmentWeight = options.curvatureAlignmentWeight;
    extraction.minimumConfidence = options.minimumConfidence;
    extraction.confidenceExponent = options.confidenceExponent;
    extraction.curvature.smoothingIterations =
        options.curvatureSmoothingIterations;
    extraction.normalizeDirections = options.normalizeDirections;
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
