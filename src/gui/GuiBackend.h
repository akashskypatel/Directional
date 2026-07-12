#pragma once

#include <cstddef>
#include <filesystem>
#include <functional>
#include <string_view>

#include <Eigen/Core>

#include <directional/fields/CompareCrossFields.h>

namespace directional::gui {

enum class FieldMethod { Smooth, RegularizedCurvature };
enum class FieldFormat { Auto, RawField, CrossField, Rosy };

using ProgressCallback = std::function<void(
    std::size_t current, std::size_t total, std::string_view task)>;

struct MeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

struct FieldData {
  int degree = 4;
  Eigen::MatrixXd primary;
  Eigen::MatrixXd secondary;
  Eigen::MatrixXd raw;
};

struct QuadMeshData {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

struct MeshSimplificationOptions {
  int targetFaceCount = 6000;
  double targetFaceRatio = 0.5;

  Eigen::MatrixXd vertexNvf;
  Eigen::MatrixXd vertexTargets;

  double rootThreshold = -1.0;
  int voxelResolution = 512;
  double topologyWeight = 0.1;
  double rootRelaxationThreshold = 0.0;
  bool preserveBoundary = true;
  bool rejectFaceFlips = true;
  bool verbose = false;
};

struct MeshSimplificationData {
  MeshData mesh;
  Eigen::VectorXi rootLabels;
  int rootCount = 0;
  int collapsedEdges = 0;
};

struct FieldComparisonData {
  fields::CrossFieldComparisonResult details;
  Eigen::VectorXd faceDeviationDegrees;
  double globalPhaseDegrees = 0.0;
  double meanDegrees = 0.0;
  double medianDegrees = 0.0;
  double p95Degrees = 0.0;
  double p99Degrees = 0.0;
  double areaWeightedMeanDegrees = 0.0;
  double areaWeightedRmsDegrees = 0.0;
  double q4WeightedMeanError = 0.0;
  double highErrorAreaFraction = 0.0;
  Eigen::Index highErrorFaceCount = 0;
  int highErrorComponentCount = 0;

  Eigen::Index candidateSingularityCount = 0;
  Eigen::Index referenceSingularityCount = 0;
  Eigen::Index singularityMismatchVertexCount = 0;
  double singularityMismatchAreaFraction = 0.0;
  bool hasTopologyDiagnostics = false;

  bool hasShapeOperatorAlignment = false;
  double firstShapeAlignmentMeanDegrees = 0.0;
  double firstShapeAlignmentP95Degrees = 0.0;
  double firstShapeAlignmentEnergy = 0.0;
  double secondShapeAlignmentMeanDegrees = 0.0;
  double secondShapeAlignmentP95Degrees = 0.0;
  double secondShapeAlignmentEnergy = 0.0;
};

struct FieldOptions {
  FieldMethod method = FieldMethod::RegularizedCurvature;
  bool normalizeDirections = true;

  double proxyFidelityWeight = 1.0;
  double proxySmoothnessWeight = 0.01;
  bool preserveBoundary = true;
  bool preserveSharpFeatures = true;
  double sharpFeatureAngleDegrees = 60.0;
  bool useFeatureAwareCornerNormals = true;
  double fieldSmoothnessWeight = 1.0;
  double curvatureAlignmentWeight = 1.0;
  double boundaryAlignmentWeight = 1.0;
  double sharpFeatureAlignmentWeight = 1.0;
  double minimumConfidence = 1e-3;
  double confidenceExponent = 2.0;
  int curvatureSmoothingIterations = 1;
};

struct RemeshOptions {
  double lengthRatio = 0.02;
  bool integralSeamless = true;
  bool roundSeams = false;
  bool useTriFlowDcelSimplification = false;
  bool verbose = false;
};

struct AutoRemeshResult {
  FieldData field;
  QuadMeshData quadMesh;
};

MeshData load_mesh(const std::filesystem::path &path);

FieldData load_field(const std::filesystem::path &path, FieldFormat format,
                     const MeshData &mesh);

void save_field(const std::filesystem::path &path, FieldFormat format,
                const FieldData &field);

FieldComparisonData compare_fields(const MeshData &mesh,
                                   const FieldData &first,
                                   const FieldData &second,
                                   double highErrorThresholdDegrees = 20.0,
                                   bool removeGlobalPhase = true,
                                   bool computeShapeOperatorAlignment = false);

void show_field_deviation_heatmap(const char *meshName,
                                  const FieldComparisonData &comparison,
                                  double maximumDegrees = 45.0);

MeshSimplificationData simplify_mesh(
    const MeshData &mesh, const MeshSimplificationOptions &options,
    ProgressCallback progress = {});

FieldData calculate_field(const MeshData &mesh, const FieldOptions &options,
                          ProgressCallback progress = {});

AutoRemeshResult auto_remesh(const MeshData &mesh,
                             const FieldOptions &fieldOptions,
                             const RemeshOptions &remeshOptions,
                             ProgressCallback progress = {});

QuadMeshData remesh_with_field(const MeshData &mesh, const FieldData &field,
                               const RemeshOptions &options,
                               ProgressCallback progress = {});
void save_mesh(const std::filesystem::path &path, const MeshData &mesh);
void save_quad_mesh(const std::filesystem::path &path,
                    const QuadMeshData &mesh);

void validate_field(const FieldData &field, Eigen::Index faceCount);
void validate_options(const FieldOptions &fieldOptions,
                      const RemeshOptions &remeshOptions);

} // namespace directional::gui
