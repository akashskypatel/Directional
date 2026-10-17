#pragma once

#include "BenchmarkCases.h"

#include <atomic>
#include <cstdint>
#include <filesystem>
#include <map>
#include <ostream>
#include <string>
#include <thread>

namespace directional::bench {

struct BenchmarkQuality {
  bool available = false;
  std::string error;

  double pureQuadRate = 0.0;
  int nonManifoldEdgeCount = 0;
  int tJunctionCount = 0;
  int duplicateFaceCount = 0;
  int selfIntersectionCount = 0;
  bool topologyPreserved = false;
  bool boundaryPreserved = false;
  double featureRecall = 1.0;
  double featureAlignmentP95Degrees = 0.0;
  double fieldAlignmentP95Degrees = 0.0;
  double relativeSizeErrorP95 = 0.0;
  double surfaceApproximationP95 = 0.0;
  int irregularVertexCount = 0;
  std::map<int, int> valenceHistogram;

  std::uint64_t peakWorkingSetBytes = 0;
  std::uint64_t outputStructuralHashValue = 0;
  std::string outputStructuralHash;
  std::uint64_t outputSemanticHashValue = 0;
  std::string outputSemanticHash;
  std::string outputMeshPath;
  std::string reviewImagePath;
};

class PeakWorkingSetSampler {
public:
  PeakWorkingSetSampler();
  PeakWorkingSetSampler(const PeakWorkingSetSampler &) = delete;
  PeakWorkingSetSampler &operator=(const PeakWorkingSetSampler &) = delete;
  ~PeakWorkingSetSampler();

  std::uint64_t finish();

private:
  std::atomic<bool> stop_{false};
  std::atomic<std::uint64_t> peak_{0};
  std::thread worker_;
  bool finished_ = false;
};

[[nodiscard]] std::uint64_t current_process_working_set_bytes();

[[nodiscard]] std::uint64_t
benchmark_output_structural_hash(const pipeline::RemeshResult &result);

/** Component/row-order invariant digest over connectivity and exact lineage. */
[[nodiscard]] std::uint64_t
benchmark_output_semantic_hash(const pipeline::RemeshResult &result);

[[nodiscard]] std::string benchmark_hash_string(std::uint64_t hash);

[[nodiscard]] BenchmarkQuality evaluate_benchmark_quality(
    const BenchmarkCase &benchmarkCase, const BenchmarkMesh &sourceMesh,
    const BenchmarkField &field, const pipeline::RemeshResult &result,
    std::uint64_t peakWorkingSetBytes,
    const std::filesystem::path &artifactDirectory);

[[nodiscard]] std::string write_benchmark_failure_review_image(
    const BenchmarkCase &benchmarkCase, const BenchmarkMesh &sourceMesh,
    const std::filesystem::path &artifactDirectory);

void write_benchmark_quality_json(std::ostream &out,
                                  const BenchmarkQuality &quality);

} // namespace directional::bench
