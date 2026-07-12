#include "GuiBackend.h"

#include <algorithm>
#include <stdexcept>
#include <string>

#include <polyscope/polyscope.h>
#include <polyscope/surface_mesh.h>
#include <polyscope/surface_scalar_quantity.h>

#include <directional/fields/CompareCrossFields.h>

namespace directional::gui {
namespace {

inline Eigen::MatrixXd comparison_raw_field(const FieldData &field,
                                     const Eigen::Index faceCount) {
  if (field.raw.rows() == faceCount && field.raw.cols() == 12) {
    return field.raw;
  }
  if (field.primary.rows() == faceCount && field.primary.cols() == 3 &&
      field.secondary.rows() == faceCount && field.secondary.cols() == 3) {
    Eigen::MatrixXd raw(faceCount, 12);
    raw.leftCols<3>() = field.primary;
    raw.middleCols<3>(3) = field.secondary;
    raw.middleCols<3>(6) = -field.primary;
    raw.middleCols<3>(9) = -field.secondary;
    return raw;
  }
  throw std::runtime_error(
      "Field comparison requires either a 12-column raw field or two "
      "3D cross axes per face.");
}

} // namespace

inline FieldComparisonData compare_fields(const MeshData &mesh, const FieldData &first,
                                   const FieldData &second,
                                   const double highErrorThresholdDegrees,
                                   const bool removeGlobalPhase,
                                   const bool computeShapeOperatorAlignment) {
  validate_field(first, mesh.faces.rows());
  validate_field(second, mesh.faces.rows());

  fields::CrossFieldComparisonOptions options;
  options.highErrorThresholdDegrees = highErrorThresholdDegrees;
  options.removeGlobalPhase = removeGlobalPhase;
  options.computeShapeOperatorAlignment = computeShapeOperatorAlignment;
  const Eigen::MatrixXd firstRaw =
      comparison_raw_field(first, mesh.faces.rows());
  const Eigen::MatrixXd secondRaw =
      comparison_raw_field(second, mesh.faces.rows());
  const fields::CrossFieldComparisonResult comparison =
      fields::compare_cross_fields(mesh.vertices, mesh.faces, firstRaw,
                                   secondRaw, options);

  FieldComparisonData result;
  result.details = comparison;
  result.faceDeviationDegrees = comparison.faceDeviationDegrees;
  result.globalPhaseDegrees = comparison.globalPhaseDegrees;
  result.meanDegrees = comparison.faceDeviationStats.mean;
  result.medianDegrees = comparison.faceDeviationStats.median;
  result.p95Degrees = comparison.faceDeviationStats.p95;
  result.p99Degrees = comparison.faceDeviationStats.p99;
  result.areaWeightedMeanDegrees = comparison.faceDeviationStats.weightedMean;
  result.areaWeightedRmsDegrees = comparison.faceDeviationStats.weightedRms;
  result.q4WeightedMeanError =
      comparison.q4SquaredChordalErrorStats.weightedMean;
  result.highErrorAreaFraction = comparison.highErrorComponents.areaFraction;
  result.highErrorFaceCount = comparison.highErrorComponents.faceCount;
  result.highErrorComponentCount = comparison.highErrorComponents.componentCount;
  result.candidateSingularityCount =
      comparison.topology.first.singularVertices.size();
  result.referenceSingularityCount =
      comparison.topology.second.singularVertices.size();
  result.singularityMismatchVertexCount =
      comparison.topology.mismatchedVertexCount;
  result.singularityMismatchAreaFraction =
      comparison.topology.mismatchedVertexAreaFraction;
  result.hasTopologyDiagnostics = comparison.topology.available;
  if (comparison.hasShapeOperatorAlignment) {
    result.hasShapeOperatorAlignment = true;
    result.firstShapeAlignmentMeanDegrees =
        comparison.firstShapeOperatorStats.angleDegrees.weightedMean;
    result.firstShapeAlignmentP95Degrees =
        comparison.firstShapeOperatorStats.angleDegrees.p95;
    result.firstShapeAlignmentEnergy =
        comparison.firstShapeOperatorStats.weightedMeanEnergy;
    result.secondShapeAlignmentMeanDegrees =
        comparison.secondShapeOperatorStats.angleDegrees.weightedMean;
    result.secondShapeAlignmentP95Degrees =
        comparison.secondShapeOperatorStats.angleDegrees.p95;
    result.secondShapeAlignmentEnergy =
        comparison.secondShapeOperatorStats.weightedMeanEnergy;
  }
  return result;
}

inline void show_field_deviation_heatmap(const char *meshName,
                                  const FieldComparisonData &comparison,
                                  const double maximumDegrees) {
  if (meshName == nullptr || !polyscope::hasSurfaceMesh(meshName)) {
    throw std::runtime_error("Cannot show deviation heatmap before the mesh is loaded.");
  }
  if (comparison.faceDeviationDegrees.size() == 0) {
    throw std::runtime_error("Comparison result has no face deviations to display.");
  }

  auto *mesh = polyscope::getSurfaceMesh(meshName);
  auto *quantity = mesh->addFaceScalarQuantity(
      "Cross-field deviation (degrees)", comparison.faceDeviationDegrees,
      polyscope::DataType::MAGNITUDE);
  quantity->setMapRange({0.0, std::max(1.0, maximumDegrees)});
  quantity->setEnabled(true);
}

} // namespace directional::gui
