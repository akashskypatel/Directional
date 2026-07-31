#pragma once

#ifndef DIRECTIONAL_FIELDS_COMPARE_CROSS_FIELDS_H
#define DIRECTIONAL_FIELDS_COMPARE_CROSS_FIELDS_H

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstddef>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <map>
#include <numbers>
#include <numeric>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Dense>

#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/FieldMatching.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/fields/ShapeOperatorAlignment.h>

/**
 * @file CompareCrossFields.h
 * @brief Face-wise and edge-wise comparison metrics for 4-RoSy cross fields.
 *
 * The comparison is intentionally representation-invariant for ordinary cross
 * fields: sign flips, branch permutations, and 90-degree rotations are compared
 * through a degree-4 complex representative in each face tangent basis.
 */

namespace directional::fields {

struct ScalarDistributionStats {
  double minimum = 0.0;
  double maximum = 0.0;
  double mean = 0.0;
  double median = 0.0;
  double p75 = 0.0;
  double p90 = 0.0;
  double p95 = 0.0;
  double p99 = 0.0;
  double rms = 0.0;
  double weightedMean = 0.0;
  double weightedRms = 0.0;
};

struct CrossFieldSmoothnessStats {
  ScalarDistributionStats angleDegrees;
  double weightedChordalEnergy = 0.0;
  Eigen::VectorXd edgeAngleDegrees;
  Eigen::VectorXd edgeWeights;
};

struct ShapeOperatorAlignmentStats {
  ScalarDistributionStats angleDegrees;
  ScalarDistributionStats normalizedEnergy;
  Eigen::Index validFaceCount = 0;
  double validAreaFraction = 0.0;
  double weightedMeanEnergy = 0.0;
};

struct HighErrorComponents {
  double thresholdDegrees = 20.0;
  Eigen::Index faceCount = 0;
  double areaFraction = 0.0;
  int componentCount = 0;
  Eigen::VectorXi componentSizes;
  Eigen::VectorXi faceComponentIds;

  struct Component {
    int id = -1;
    Eigen::Index firstFace = -1;
    Eigen::Index faceCount = 0;
    double areaFraction = 0.0;
    double areaWeightedMeanDegrees = 0.0;
    double maximumDegrees = 0.0;
    Eigen::RowVector3d areaWeightedCentroid = Eigen::RowVector3d::Zero();
  };
  std::vector<Component> components;
};

struct CrossFieldTopologyStats {
  Eigen::VectorXi singularVertices;
  Eigen::VectorXi singularNumerators;
  Eigen::VectorXi vertexNumerators;
  Eigen::Index positiveCount = 0;
  Eigen::Index negativeCount = 0;
  double totalAbsoluteIndex = 0.0;
};

struct CrossFieldTopologyComparison {
  bool available = false;
  std::string error;
  CrossFieldTopologyStats first;
  CrossFieldTopologyStats second;
  Eigen::Index matchingSingularityCount = 0;
  Eigen::Index firstOnlyCount = 0;
  Eigen::Index secondOnlyCount = 0;
  Eigen::Index differingIndexCount = 0;
  Eigen::Index mismatchedVertexCount = 0;
  double mismatchedVertexAreaFraction = 0.0;
  double l1IndexDifference = 0.0;
  ScalarDistributionStats firstToSecondDistanceEdgeLengths;
  ScalarDistributionStats secondToFirstDistanceEdgeLengths;
  Eigen::Index firstWithoutSameIndexReference = 0;
  Eigen::Index secondWithoutSameIndexReference = 0;
};

struct CrossFieldComparisonReportMetadata {
  std::string meshPath;
  Eigen::Index vertexCount = 0;
  std::string candidatePath;
  std::string referencePath;
  std::string candidateLabel = "candidate";
  std::string referenceLabel = "reference";
  std::string referenceFormat;
  std::map<std::string, std::string> candidateStringParameters;
  std::map<std::string, double> candidateNumericParameters;
  std::map<std::string, bool> candidateBooleanParameters;
  bool removeGlobalPhase = true;
  bool shapeOperatorAlignment = false;
  std::string faceCsvPath;
  std::string heatmapPath;
};

struct CrossFieldComparisonReportPaths {
  std::filesystem::path json;
  std::filesystem::path facesCsv;
  std::filesystem::path heatmapPly;
};

struct CrossFieldComparisonOptions {
  bool removeGlobalPhase = true;
  double highErrorThresholdDegrees = 20.0;

  /// Also evaluate each field against the regularized shape operator.
  bool computeShapeOperatorAlignment = false;

  /// Options for the optional NeurCross-style shape-operator diagnostic.
  ShapeOperatorAlignmentOptions shapeOperatorAlignment;
};

struct CrossFieldComparisonResult {
  Eigen::VectorXd faceSignedDeviationDegrees;
  Eigen::VectorXd faceDeviationDegrees;
  Eigen::VectorXd faceQ4SquaredChordalError;
  Eigen::VectorXd faceAreas;
  Eigen::MatrixXd faceCenters;
  ScalarDistributionStats faceDeviationStats;
  ScalarDistributionStats q4SquaredChordalErrorStats;
  std::array<double, 7> withinDegreeFractions{{0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                               0.0}};
  std::array<double, 7> withinDegreeAreaFractions{{0.0, 0.0, 0.0, 0.0, 0.0,
                                                   0.0, 0.0}};
  std::array<double, 7> withinDegreeThresholds{{2.5, 5.0, 10.0, 15.0, 20.0,
                                                30.0, 40.0}};
  double globalPhaseDegrees = 0.0;
  CrossFieldSmoothnessStats firstSmoothness;
  CrossFieldSmoothnessStats secondSmoothness;
  bool hasShapeOperatorAlignment = false;
  ShapeOperatorAlignmentResult firstShapeOperatorAlignment;
  ShapeOperatorAlignmentResult secondShapeOperatorAlignment;
  ShapeOperatorAlignmentStats firstShapeOperatorStats;
  ShapeOperatorAlignmentStats secondShapeOperatorStats;
  HighErrorComponents highErrorComponents;
  CrossFieldTopologyComparison topology;
};

namespace compare_detail {

inline constexpr double pi = std::numbers::pi_v<double>;
inline constexpr int crossFieldDegree = 4;

void validate_mesh(const Eigen::MatrixXd &V, const Eigen::MatrixXi &F);

void validate_field(const Eigen::MatrixXd &field,
                           const Eigen::Index faceCount,
                           const std::string &name);

Eigen::RowVector3d normalized_row(const Eigen::RowVector3d &value,
                                         const char *context);

void compute_face_geometry(const Eigen::MatrixXd &V,
                                  const Eigen::MatrixXi &F,
                                  Eigen::MatrixXd &normals,
                                  Eigen::MatrixXd &basisX,
                                  Eigen::MatrixXd &basisY,
                                  Eigen::MatrixXd &centers,
                                  Eigen::VectorXd &areas);

std::complex<double> normalized_complex(std::complex<double> value);

std::complex<double> direction_q4(const Eigen::RowVector3d &direction,
                                         const Eigen::RowVector3d &basisX,
                                         const Eigen::RowVector3d &basisY);

Eigen::VectorXcd field_q4(const Eigen::MatrixXd &field,
                                 const Eigen::MatrixXd &basisX,
                                 const Eigen::MatrixXd &basisY);

Eigen::MatrixXd raw_cross_field(const Eigen::MatrixXd &field);

double percentile_sorted(const std::vector<double> &sorted,
                                const double percentile);

ScalarDistributionStats scalar_stats(const Eigen::VectorXd &values,
                                            const Eigen::VectorXd &weights);

ScalarDistributionStats scalar_stats(const std::vector<double> &values);


ScalarDistributionStats masked_scalar_stats(
    const Eigen::VectorXd &values, const Eigen::VectorXd &weights,
    const Eigen::VectorXi &valid);

ShapeOperatorAlignmentStats shape_operator_stats(
    const ShapeOperatorAlignmentResult &alignment);

double average_edge_length(const Eigen::MatrixXd &V,
                                  const Eigen::MatrixXi &F);

Eigen::VectorXd vertex_area_weights(const Eigen::MatrixXi &F,
                                           const Eigen::VectorXd &faceAreas,
                                           const Eigen::Index vertexCount);

CrossFieldTopologyStats
topology_stats(const PCFaceTangentBundle &tangentBundle,
               const Eigen::Index vertexCount,
               const Eigen::MatrixXd &field);

CrossFieldTopologyComparison topology_comparison(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::VectorXd &faceAreas, const Eigen::MatrixXd &firstField,
    const Eigen::MatrixXd &secondField);

struct InteriorEdge {
  Eigen::Index firstFace = -1;
  Eigen::Index secondFace = -1;
  int firstVertex = -1;
  int secondVertex = -1;
};

std::vector<InteriorEdge> interior_edges(const Eigen::MatrixXi &F);

CrossFieldSmoothnessStats smoothness_stats(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::MatrixXd &basisX, const Eigen::MatrixXd &basisY,
    const Eigen::VectorXd &areas, const Eigen::VectorXcd &q4);

HighErrorComponents high_error_components(
    const Eigen::MatrixXi &F, const Eigen::VectorXd &areas,
    const Eigen::MatrixXd &centers,
    const Eigen::VectorXd &deviationDegrees, const double thresholdDegrees);

std::array<unsigned char, 3> heatmap_color(double value,
                                                  double maximumDegrees);

void write_json_string(std::ostream &stream, const std::string &value);

std::string utc_timestamp();

} // namespace compare_detail

CrossFieldComparisonResult compare_cross_fields(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const Eigen::MatrixXd &firstField, const Eigen::MatrixXd &secondField,
    const CrossFieldComparisonOptions &options = {});

void write_cross_field_comparison_csv(
    const std::filesystem::path &path, const CrossFieldComparisonResult &result);

void write_cross_field_comparison_ply(
    const std::filesystem::path &path, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const CrossFieldComparisonResult &result,
    const double maximumDegrees = 45.0);

void write_cross_field_comparison_json(
    const std::filesystem::path &path, const CrossFieldComparisonResult &result,
    const CrossFieldComparisonReportMetadata &metadata = {});

CrossFieldComparisonReportPaths write_cross_field_comparison_report(
    const std::filesystem::path &requestedPath, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const CrossFieldComparisonResult &result,
    const CrossFieldComparisonReportMetadata &metadata = {},
    const double maximumDegrees = 45.0);

std::string summarize_cross_field_comparison(
    const CrossFieldComparisonResult &result);

} // namespace directional::fields

#endif // DIRECTIONAL_FIELDS_COMPARE_CROSS_FIELDS_H
