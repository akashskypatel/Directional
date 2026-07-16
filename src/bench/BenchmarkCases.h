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
  double lengthRatio = 0.02;
  bool integralSeamless = true;
  bool roundSeams = true;
  bool synthetic = false;
  int syntheticSubdivisions = 1;
};

struct BenchmarkMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

std::vector<BenchmarkCase> default_benchmark_cases();
std::vector<BenchmarkCase>
load_benchmark_manifest(const std::filesystem::path &path);
BenchmarkMesh load_benchmark_mesh(const BenchmarkCase &benchmarkCase);
pipeline::RemeshOptions make_remesh_options(const BenchmarkCase &benchmarkCase);

} // namespace directional::bench
