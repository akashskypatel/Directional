#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <Eigen/Core>

#include <directional/pipeline/RemeshPipeline.h>

namespace directional::bench {

struct BenchmarkCase {
  std::string name;
  std::filesystem::path meshPath;
  std::filesystem::path fieldPath;
  std::string fieldFormat = "auto";
  std::string generatedField = "smooth";
  double lengthRatio = 0.02;
  bool integralSeamless = true;
  bool roundSeams = true;
  pipeline::RemeshBackend backend = pipeline::RemeshBackend::LegacyInteger;
  pipeline::SurfaceCellFallbackPolicy surfaceCellFallback =
      pipeline::SurfaceCellFallbackPolicy::Fail;
  bool surfaceCellSkeletonHints = false;
  bool surfaceCellPreserveDebugArtifacts = false;
  bool surfaceCellTraverseUnmarkedSharpBends = true;
  double surfaceCellSheetNormalCompatibility = 0.25;
  double surfaceCellCloseSheetRadiusMeanEdges = 2.5;
  int surfaceCellGeodesicExclusionDepth = 2;
  bool synthetic = false;
  int syntheticSubdivisions = 1;
  int syntheticComponents = 1;
};

struct BenchmarkMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

struct BenchmarkField {
  bool available = false;
  int degree = 4;
  Eigen::MatrixXd raw;
};

std::vector<BenchmarkCase> default_benchmark_cases();
std::vector<BenchmarkCase>
load_benchmark_manifest(const std::filesystem::path &path);
BenchmarkMesh load_benchmark_mesh(const BenchmarkCase &benchmarkCase);
BenchmarkField load_benchmark_field(const BenchmarkCase &benchmarkCase,
                                    Eigen::Index expectedFaces);
BenchmarkField generate_benchmark_field(const BenchmarkCase &benchmarkCase,
                                        const BenchmarkMesh &mesh);
pipeline::RemeshOptions make_remesh_options(const BenchmarkCase &benchmarkCase);

} // namespace directional::bench
