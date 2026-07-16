#include "BenchmarkCases.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include <directional/geometry/MeshTopology.h>
#include <directional/integration/IntegrationLinearSolver.h>

namespace directional::bench {
namespace {

struct Options {
  std::filesystem::path manifestPath;
  std::string selectedCase;
  int warmupRuns = 1;
  int measuredRuns = 5;
  std::filesystem::path outputPath = "benchmark-results/baseline.json";
};

struct StructuralMetrics {
  int outputVertices = 0;
  int outputFaces = 0;
  int quadFaces = 0;
  int nonQuadFaces = 0;
  int connectedComponents = 0;
  int boundaryEdges = 0;
  int degenerateFaces = 0;
};

struct RunRecord {
  bool success = false;
  double wallSeconds = 0.0;
  std::uint64_t fixtureHash = 0;
  std::uint64_t fieldHash = 0;
  bool usedFieldFile = false;
  std::string error;
  pipeline::RemeshResult result;
  StructuralMetrics metrics;
};

void print_usage() {
  std::cout << "Usage: directional_benchmarks [options]\n"
            << "  --manifest <path>   Benchmark fixture manifest JSON.\n"
            << "  --case <name>       Run one case from the manifest.\n"
            << "  --warmup <count>    Warm-up runs before measurements.\n"
            << "  --runs <count>      Measured run count.\n"
            << "  --output <path>     Output JSON path.\n";
}

int parse_nonnegative_int(const std::string &value, const char *name) {
  std::size_t parsed = 0;
  const int result = std::stoi(value, &parsed);
  if (parsed != value.size() || result < 0) {
    throw std::runtime_error(std::string(name) + " requires a non-negative integer.");
  }
  return result;
}

Options parse_options(const int argc, char **argv) {
  Options options;
  for (int index = 1; index < argc; ++index) {
    const std::string argument = argv[index];
    const auto requireValue = [&](const char *name) -> std::string {
      if (++index >= argc) {
        throw std::runtime_error(std::string(name) + " requires a value.");
      }
      return argv[index];
    };
    if (argument == "--help" || argument == "-h") {
      print_usage();
      std::exit(0);
    } else if (argument == "--manifest") {
      options.manifestPath = requireValue("--manifest");
    } else if (argument == "--case") {
      options.selectedCase = requireValue("--case");
    } else if (argument == "--warmup") {
      options.warmupRuns = parse_nonnegative_int(requireValue("--warmup"), "--warmup");
    } else if (argument == "--runs") {
      options.measuredRuns = parse_nonnegative_int(requireValue("--runs"), "--runs");
    } else if (argument == "--output") {
      options.outputPath = requireValue("--output");
    } else {
      throw std::runtime_error("Unknown benchmark option: " + argument);
    }
  }
  if (options.measuredRuns <= 0) {
    throw std::runtime_error("--runs must be greater than zero.");
  }
  return options;
}

std::string escape_json(const std::string &value) {
  std::ostringstream escaped;
  for (const char character : value) {
    switch (character) {
    case '\\':
      escaped << "\\\\";
      break;
    case '"':
      escaped << "\\\"";
      break;
    case '\n':
      escaped << "\\n";
      break;
    case '\r':
      escaped << "\\r";
      break;
    case '\t':
      escaped << "\\t";
      break;
    default:
      escaped << character;
      break;
    }
  }
  return escaped.str();
}

std::string timestamp_utc() {
  const auto now = std::chrono::system_clock::now();
  const std::time_t time = std::chrono::system_clock::to_time_t(now);
  std::tm utc{};
#ifdef _WIN32
  gmtime_s(&utc, &time);
#else
  gmtime_r(&time, &utc);
#endif
  std::ostringstream output;
  output << std::put_time(&utc, "%Y-%m-%dT%H:%M:%SZ");
  return output.str();
}

std::string cpu_description() {
#ifdef _WIN32
  if (const char *processor = std::getenv("PROCESSOR_IDENTIFIER")) {
    return processor;
  }
#elif defined(__linux__)
  std::ifstream cpuinfo("/proc/cpuinfo");
  std::string line;
  while (std::getline(cpuinfo, line)) {
    constexpr std::string_view modelName = "model name";
    if (line.rfind(modelName.data(), 0) == 0) {
      const std::size_t colon = line.find(':');
      if (colon != std::string::npos) {
        return line.substr(colon + 2);
      }
    }
  }
#endif
  return "unknown";
}

std::vector<BenchmarkCase> select_cases(const Options &options) {
  std::vector<BenchmarkCase> cases =
      options.manifestPath.empty() ? default_benchmark_cases()
                                   : load_benchmark_manifest(options.manifestPath);
  if (options.selectedCase.empty()) {
    return cases;
  }
  std::vector<BenchmarkCase> selected;
  std::copy_if(cases.begin(), cases.end(), std::back_inserter(selected),
               [&](const BenchmarkCase &candidate) {
                 return candidate.name == options.selectedCase;
               });
  if (selected.empty()) {
    throw std::runtime_error("Benchmark case not found: " + options.selectedCase);
  }
  return selected;
}

double polygon_area(const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
                    const Eigen::VectorXi &degrees, const int face) {
  if (degrees(face) < 3) {
    return 0.0;
  }
  const Eigen::RowVector3d origin = vertices.row(faces(face, 0));
  double area = 0.0;
  for (int corner = 1; corner + 1 < degrees(face); ++corner) {
    const Eigen::RowVector3d a = vertices.row(faces(face, corner)) - origin;
    const Eigen::RowVector3d b = vertices.row(faces(face, corner + 1)) - origin;
    area += 0.5 * a.cross(b).norm();
  }
  return area;
}

StructuralMetrics compute_structural_metrics(const pipeline::RemeshResult &result) {
  StructuralMetrics metrics;
  metrics.outputVertices = static_cast<int>(result.vertices.rows());
  metrics.outputFaces = static_cast<int>(result.degrees.size());
  if (metrics.outputVertices == 0 || metrics.outputFaces == 0) {
    return metrics;
  }

  std::map<std::pair<int, int>, int> edgeUse;
  std::vector<std::vector<int>> adjacency(static_cast<std::size_t>(metrics.outputVertices));
  for (int face = 0; face < metrics.outputFaces; ++face) {
    if (result.degrees(face) == 4) {
      ++metrics.quadFaces;
    } else {
      ++metrics.nonQuadFaces;
    }
    if (polygon_area(result.vertices, result.faces, result.degrees, face) <= 1.0e-14) {
      ++metrics.degenerateFaces;
    }
    for (int corner = 0; corner < result.degrees(face); ++corner) {
      const int a = result.faces(face, corner);
      const int b = result.faces(face, (corner + 1) % result.degrees(face));
      if (a < 0 || b < 0 || a >= metrics.outputVertices ||
          b >= metrics.outputVertices || a == b) {
        ++metrics.degenerateFaces;
        continue;
      }
      const auto key = std::minmax(a, b);
      ++edgeUse[key];
      adjacency[static_cast<std::size_t>(a)].push_back(b);
      adjacency[static_cast<std::size_t>(b)].push_back(a);
    }
  }
  for (const auto &[edge, useCount] : edgeUse) {
    if (useCount == 1) {
      ++metrics.boundaryEdges;
    }
  }

  std::vector<unsigned char> visited(static_cast<std::size_t>(metrics.outputVertices), 0);
  for (int vertex = 0; vertex < metrics.outputVertices; ++vertex) {
    if (visited[static_cast<std::size_t>(vertex)] ||
        adjacency[static_cast<std::size_t>(vertex)].empty()) {
      continue;
    }
    ++metrics.connectedComponents;
    std::queue<int> pending;
    pending.push(vertex);
    visited[static_cast<std::size_t>(vertex)] = 1;
    while (!pending.empty()) {
      const int current = pending.front();
      pending.pop();
      for (const int next : adjacency[static_cast<std::size_t>(current)]) {
        if (!visited[static_cast<std::size_t>(next)]) {
          visited[static_cast<std::size_t>(next)] = 1;
          pending.push(next);
        }
      }
    }
  }
  return metrics;
}

void fnv_mix(std::uint64_t &hash, const std::uint64_t value) {
  hash ^= value;
  hash *= 1099511628211ULL;
}

std::uint64_t hash_benchmark_mesh(const BenchmarkMesh &mesh) {
  std::uint64_t hash = 1469598103934665603ULL;
  fnv_mix(hash, static_cast<std::uint64_t>(mesh.vertices.rows()));
  fnv_mix(hash, static_cast<std::uint64_t>(mesh.vertices.cols()));
  fnv_mix(hash, static_cast<std::uint64_t>(mesh.faces.rows()));
  fnv_mix(hash, static_cast<std::uint64_t>(mesh.faces.cols()));
  for (Eigen::Index row = 0; row < mesh.vertices.rows(); ++row) {
    for (Eigen::Index col = 0; col < mesh.vertices.cols(); ++col) {
      std::uint64_t bits = 0;
      static_assert(sizeof(bits) == sizeof(double));
      std::memcpy(&bits, &mesh.vertices(row, col), sizeof(double));
      fnv_mix(hash, bits);
    }
  }
  for (Eigen::Index row = 0; row < mesh.faces.rows(); ++row) {
    for (Eigen::Index col = 0; col < mesh.faces.cols(); ++col) {
      fnv_mix(hash, static_cast<std::uint64_t>(
                        static_cast<std::uint32_t>(mesh.faces(row, col))));
    }
  }
  return hash;
}

std::uint64_t hash_matrix(const Eigen::MatrixXd &matrix) {
  std::uint64_t hash = 1469598103934665603ULL;
  fnv_mix(hash, static_cast<std::uint64_t>(matrix.rows()));
  fnv_mix(hash, static_cast<std::uint64_t>(matrix.cols()));
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      std::uint64_t bits = 0;
      const double value = matrix(row, col);
      std::memcpy(&bits, &value, sizeof(double));
      fnv_mix(hash, bits);
    }
  }
  return hash;
}

RunRecord run_case_once(const BenchmarkCase &benchmarkCase) {
  RunRecord record;
  const BenchmarkMesh mesh = load_benchmark_mesh(benchmarkCase);
  record.fixtureHash = hash_benchmark_mesh(mesh);
  BenchmarkField field = load_benchmark_field(benchmarkCase, mesh.faces.rows());
  if (!field.available) {
    field = generate_benchmark_field(benchmarkCase, mesh);
  }
  if (field.available) {
    record.usedFieldFile = true;
    record.fieldHash = hash_matrix(field.raw);
  }
  pipeline::RemeshOptions options = make_remesh_options(benchmarkCase);
  const auto start = std::chrono::steady_clock::now();
  try {
    if (field.available) {
      record.result = pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);
    } else {
      record.result =
          pipeline::remesh_from_mesh(mesh.vertices, mesh.faces, options);
    }
    record.success = record.result.success;
    if (record.success) {
      record.metrics = compute_structural_metrics(record.result);
    }
  } catch (const std::exception &exception) {
    record.success = false;
    record.error = exception.what();
  }
  record.wallSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::steady_clock::now() - start)
          .count() /
      1.0e6;
  return record;
}

double median(std::vector<double> values) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const std::size_t middle = values.size() / 2;
  if ((values.size() % 2) == 1) {
    return values[middle];
  }
  return 0.5 * (values[middle - 1] + values[middle]);
}

double percentile(std::vector<double> values, const double p) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const double index = (values.size() - 1) * p;
  const auto lower = static_cast<std::size_t>(std::floor(index));
  const auto upper = static_cast<std::size_t>(std::ceil(index));
  if (lower == upper) {
    return values[lower];
  }
  return values[lower] + (values[upper] - values[lower]) * (index - lower);
}

double coefficient_of_variation(const std::vector<double> &values) {
  if (values.empty()) {
    return 0.0;
  }
  const double mean =
      std::accumulate(values.begin(), values.end(), 0.0) / values.size();
  if (mean == 0.0) {
    return 0.0;
  }
  double variance = 0.0;
  for (const double value : values) {
    const double delta = value - mean;
    variance += delta * delta;
  }
  variance /= values.size();
  return std::sqrt(variance) / mean;
}

void write_integration_json(std::ostream &out,
                            const IntegrationDiagnostics &diagnostics) {
  out << "{"
      << "\"totalSeconds\":" << diagnostics.totalSeconds << ","
      << "\"fullEnergyPrecomputeSeconds\":"
      << diagnostics.fullEnergyPrecomputeSeconds << ","
      << "\"freeVariableMapSeconds\":" << diagnostics.freeVariableMapSeconds
      << ","
      << "\"reducedOperatorExtractionSeconds\":"
      << diagnostics.reducedOperatorExtractionSeconds << ","
      << "\"constraintRankReductionSeconds\":"
      << diagnostics.constraintRankReductionSeconds << ","
      << "\"kktAssemblySeconds\":" << diagnostics.kktAssemblySeconds << ","
      << "\"rhsAssemblySeconds\":" << diagnostics.rhsAssemblySeconds << ","
      << "\"symbolicAnalysisSeconds\":" << diagnostics.symbolicAnalysisSeconds
      << ","
      << "\"numericFactorizationSeconds\":"
      << diagnostics.numericFactorizationSeconds << ","
      << "\"backSubstitutionSeconds\":"
      << diagnostics.backSubstitutionSeconds << ","
      << "\"fullSolutionReconstructionSeconds\":"
      << diagnostics.fullSolutionReconstructionSeconds << ","
      << "\"integerCandidateSelectionSeconds\":"
      << diagnostics.integerCandidateSelectionSeconds << ","
      << "\"integerIterations\":" << diagnostics.integerIterations << ","
      << "\"roundingBatches\":" << diagnostics.roundingBatches << ","
      << "\"roundingBatchHistogram\":[";
  for (std::size_t index = 0;
       index < diagnostics.roundingBatchHistogram.size(); ++index) {
    out << diagnostics.roundingBatchHistogram[index]
        << (index + 1 == diagnostics.roundingBatchHistogram.size() ? "" : ",");
  }
  out << "],"
      << "\"directFactorizations\":" << diagnostics.directFactorizations
      << ","
      << "\"factorizationFailures\":" << diagnostics.factorizationFailures
      << ","
      << "\"solveFailures\":" << diagnostics.solveFailures << ","
      << "\"maximumFreeVariables\":" << diagnostics.maximumFreeVariables
      << ","
      << "\"maximumConstraintRows\":" << diagnostics.maximumConstraintRows
      << ","
      << "\"maximumSystemRows\":" << diagnostics.maximumSystemRows << ","
      << "\"maximumSystemNonZeros\":" << diagnostics.maximumSystemNonZeros
      << ","
      << "\"finalLinearSystemResidualNorm\":"
      << diagnostics.finalLinearSystemResidualNorm << ","
      << "\"finalConstraintResidualNorm\":"
      << diagnostics.finalConstraintResidualNorm << ","
      << "\"maximumUnresolvedIntegerResidual\":"
      << diagnostics.maximumUnresolvedIntegerResidual << ","
      << "\"finalIntegrationEnergy\":" << diagnostics.finalIntegrationEnergy
      << "}";
}

void write_mesher_json(std::ostream &out, const MesherDiagnostics &diagnostics) {
  out << "{"
      << "\"totalMesherSeconds\":" << diagnostics.totalMesherSeconds << ","
      << "\"generateArrangementSeconds\":"
      << diagnostics.generateArrangementSeconds << ","
      << "\"simplifyTotalSeconds\":" << diagnostics.simplifyTotalSeconds << ","
      << "\"initialConsistencySeconds\":"
      << diagnostics.initialConsistencySeconds << ","
      << "\"boundaryScanSeconds\":" << diagnostics.boundaryScanSeconds << ","
      << "\"boundaryStripSeconds\":" << diagnostics.boundaryStripSeconds << ","
      << "\"vertexMatchSeconds\":" << diagnostics.vertexMatchSeconds << ","
      << "\"representativeBuildSeconds\":"
      << diagnostics.representativeBuildSeconds << ","
      << "\"halfedgeRemapSeconds\":" << diagnostics.halfedgeRemapSeconds
      << ","
      << "\"degeneratePruneSeconds\":" << diagnostics.degeneratePruneSeconds
      << ","
      << "\"retwinSeconds\":" << diagnostics.retwinSeconds << ","
      << "\"danglingFunctionPruneSeconds\":"
      << diagnostics.danglingFunctionPruneSeconds << ","
      << "\"regionClassificationSeconds\":"
      << diagnostics.regionClassificationSeconds << ","
      << "\"faceRealignmentSeconds\":" << diagnostics.faceRealignmentSeconds
      << ","
      << "\"lowQualityFacePruneSeconds\":"
      << diagnostics.lowQualityFacePruneSeconds << ","
      << "\"lowValenceUnificationSeconds\":"
      << diagnostics.lowValenceUnificationSeconds << ","
      << "\"finalCleanSeconds\":" << diagnostics.finalCleanSeconds << ","
      << "\"triFlowSeconds\":" << diagnostics.triFlowSeconds << ","
      << "\"verticesBeforeSimplification\":"
      << diagnostics.verticesBeforeSimplification << ","
      << "\"facesBeforeSimplification\":"
      << diagnostics.facesBeforeSimplification << ","
      << "\"halfedgesBeforeSimplification\":"
      << diagnostics.halfedgesBeforeSimplification << ","
      << "\"verticesAfterSimplification\":"
      << diagnostics.verticesAfterSimplification << ","
      << "\"facesAfterSimplification\":"
      << diagnostics.facesAfterSimplification << ","
      << "\"halfedgesAfterSimplification\":"
      << diagnostics.halfedgesAfterSimplification << ","
      << "\"retwinnedPairCount\":" << diagnostics.retwinnedPairCount << ","
      << "\"danglingFunctionEdgesCleared\":"
      << diagnostics.danglingFunctionEdgesCleared << ","
      << "\"lowQualityFacesPruned\":" << diagnostics.lowQualityFacesPruned
      << ","
      << "\"lowValenceCandidatesConsidered\":"
      << diagnostics.lowValenceCandidatesConsidered << ","
      << "\"lowValenceOperationsAccepted\":"
      << diagnostics.lowValenceOperationsAccepted << ","
      << "\"lowValenceOperationsRejected\":"
      << diagnostics.lowValenceOperationsRejected << ","
      << "\"cleanupRollbacks\":" << diagnostics.cleanupRollbacks << ","
      << "\"boundaryHoleFillsAttempted\":"
      << diagnostics.boundaryHoleFillsAttempted << ","
      << "\"boundaryHoleFillsSucceeded\":"
      << diagnostics.boundaryHoleFillsSucceeded << ","
      << "\"nonSimpleFacesPruned\":" << diagnostics.nonSimpleFacesPruned
      << "}";
}

void write_remesh_diagnostics_json(std::ostream &out,
                                   const RemeshDiagnostics &diagnostics) {
  out << "{"
      << "\"overallPipelineSeconds\":" << diagnostics.overallPipelineSeconds
      << ","
      << "\"tangentBundleInitializationSeconds\":"
      << diagnostics.tangentBundleInitializationSeconds << ","
      << "\"fieldSetupSeconds\":" << diagnostics.fieldSetupSeconds << ","
      << "\"principalMatchingSeconds\":"
      << diagnostics.principalMatchingSeconds << ","
      << "\"setupIntegrationSeconds\":" << diagnostics.setupIntegrationSeconds
      << ","
      << "\"integrationTotalSeconds\":" << diagnostics.integrationTotalSeconds
      << ","
      << "\"setupMesherSeconds\":" << diagnostics.setupMesherSeconds << ","
      << "\"mesherTotalSeconds\":" << diagnostics.mesherTotalSeconds << ","
      << "\"integration\":";
  write_integration_json(out, diagnostics.integration);
  out << ",\"mesher\":";
  write_mesher_json(out, diagnostics.mesher);
  out << "}";
}

void write_results_json(const Options &options,
                        const std::vector<std::pair<BenchmarkCase, std::vector<RunRecord>>> &results) {
  if (!options.outputPath.parent_path().empty()) {
    std::filesystem::create_directories(options.outputPath.parent_path());
  }
  std::ofstream out(options.outputPath);
  if (!out) {
    throw std::runtime_error("Failed to open benchmark output: " +
                             options.outputPath.string());
  }
  out << std::setprecision(10);
  out << "{\n";
  out << "  \"schema\": 1,\n";
  out << "  \"timestamp\": \"" << timestamp_utc() << "\",\n";
  out << "  \"buildType\": \"";
#ifdef NDEBUG
  out << "Release";
#else
  out << "Debug";
#endif
  out << "\",\n";
  out << "  \"compiler\": \"";
#ifdef _MSC_VER
  out << "MSVC " << _MSC_VER;
#elif defined(__clang__)
  out << "Clang " << __clang_version__;
#elif defined(__GNUC__)
  out << "GCC " << __VERSION__;
#else
  out << "unknown";
#endif
  out << "\",\n";
  out << "  \"platform\": \"";
#ifdef _WIN32
  out << "Windows";
#elif defined(__APPLE__)
  out << "macOS";
#elif defined(__linux__)
  out << "Linux";
#else
  out << "unknown";
#endif
  out << "\",\n";
  out << "  \"cpuDescription\": \"" << escape_json(cpu_description())
      << "\",\n";
  out << "  \"warmupRuns\": " << options.warmupRuns << ",\n";
  out << "  \"measuredRuns\": " << options.measuredRuns << ",\n";
  out << "  \"selectedIntegrationBackend\": \""
      << integration_linear_solver_name(resolve_default_integration_linear_solver())
      << "\",\n";
  out << "  \"cases\": [\n";
  for (std::size_t caseIndex = 0; caseIndex < results.size(); ++caseIndex) {
    const BenchmarkCase &benchmarkCase = results[caseIndex].first;
    const std::vector<RunRecord> &runs = results[caseIndex].second;
    std::vector<double> successfulTimes;
    for (const RunRecord &run : runs) {
      if (run.success) {
        successfulTimes.push_back(run.wallSeconds);
      }
    }
    out << "    {\n";
    out << "      \"name\": \"" << escape_json(benchmarkCase.name) << "\",\n";
    out << "      \"fixturePath\": \""
        << escape_json(benchmarkCase.synthetic ? std::string("synthetic")
                                               : benchmarkCase.meshPath.string())
        << "\",\n";
    out << "      \"fixtureHash\": \"";
    if (!runs.empty()) {
      out << std::hex << runs.front().fixtureHash << std::dec;
    }
    out << "\",\n";
    out << "      \"field\": {";
    if (!benchmarkCase.fieldPath.empty()) {
      out << "\"source\": \"file\", \"path\": \""
          << escape_json(benchmarkCase.fieldPath.string())
          << "\", \"format\": \"" << escape_json(benchmarkCase.fieldFormat)
          << "\", \"hash\": \"";
      if (!runs.empty()) {
        out << std::hex << runs.front().fieldHash << std::dec;
      }
      out << "\"";
    } else if (benchmarkCase.generatedField == "face_edges") {
      out << "\"source\": \"generated\", \"method\": "
             "\"face_edges\", \"normalizeDirections\": true, \"hash\": \"";
      if (!runs.empty()) {
        out << std::hex << runs.front().fieldHash << std::dec;
      }
      out << "\"";
    } else {
      out << "\"source\": \"generated\", \"method\": "
             "\"smooth\", \"normalizeDirections\": true";
    }
    out << "},\n";
    out << "      \"remeshOptions\": {\"lengthRatio\": "
        << benchmarkCase.lengthRatio << ", \"integralSeamless\": "
        << (benchmarkCase.integralSeamless ? "true" : "false")
        << ", \"roundSeams\": "
        << (benchmarkCase.roundSeams ? "true" : "false") << "},\n";
    out << "      \"runs\": [\n";
    for (std::size_t runIndex = 0; runIndex < runs.size(); ++runIndex) {
      const RunRecord &run = runs[runIndex];
      out << "        {\"success\": " << (run.success ? "true" : "false")
          << ", \"wallSeconds\": " << run.wallSeconds;
      if (!run.success) {
        out << ", \"error\": \"" << escape_json(run.error) << "\"";
      } else {
        out << ", \"diagnostics\": ";
        write_remesh_diagnostics_json(out, run.result.diagnostics);
        out << ", \"outputVertexCount\": " << run.metrics.outputVertices
            << ", \"outputFaceCount\": " << run.metrics.outputFaces
            << ", \"quadCount\": " << run.metrics.quadFaces
            << ", \"nonQuadFaceCount\": " << run.metrics.nonQuadFaces
            << ", \"connectedComponentCount\": "
            << run.metrics.connectedComponents
            << ", \"boundaryEdgeCount\": " << run.metrics.boundaryEdges
            << ", \"degenerateFaceCount\": " << run.metrics.degenerateFaces;
      }
      out << "}" << (runIndex + 1 == runs.size() ? "\n" : ",\n");
    }
    out << "      ],\n";
    out << "      \"aggregates\": {\"median\": " << median(successfulTimes)
        << ", \"p90\": " << percentile(successfulTimes, 0.90)
        << ", \"min\": "
        << (successfulTimes.empty()
                ? 0.0
                : *std::min_element(successfulTimes.begin(), successfulTimes.end()))
        << ", \"max\": "
        << (successfulTimes.empty()
                ? 0.0
                : *std::max_element(successfulTimes.begin(), successfulTimes.end()))
        << ", \"coefficientOfVariation\": "
        << coefficient_of_variation(successfulTimes) << "}\n";
    out << "    }" << (caseIndex + 1 == results.size() ? "\n" : ",\n");
  }
  out << "  ]\n";
  out << "}\n";
}

} // namespace
} // namespace directional::bench

int main(const int argc, char **argv) {
  try {
    const directional::bench::Options options =
        directional::bench::parse_options(argc, argv);
    const std::vector<directional::bench::BenchmarkCase> cases =
        directional::bench::select_cases(options);
    std::vector<std::pair<directional::bench::BenchmarkCase,
                          std::vector<directional::bench::RunRecord>>>
        results;
    for (const directional::bench::BenchmarkCase &benchmarkCase : cases) {
      std::cout << "Running benchmark case " << benchmarkCase.name << '\n';
      for (int warmup = 0; warmup < options.warmupRuns; ++warmup) {
        (void)directional::bench::run_case_once(benchmarkCase);
      }
      std::vector<directional::bench::RunRecord> runs;
      for (int run = 0; run < options.measuredRuns; ++run) {
        runs.push_back(directional::bench::run_case_once(benchmarkCase));
        std::cout << "  run " << (run + 1) << "/" << options.measuredRuns
                  << ": " << (runs.back().success ? "success" : "failed")
                  << " in " << runs.back().wallSeconds << " s\n";
      }
      results.emplace_back(benchmarkCase, std::move(runs));
    }
    directional::bench::write_results_json(options, results);
    std::cout << "Wrote " << options.outputPath.string() << '\n';
    return 0;
  } catch (const std::exception &exception) {
    std::cerr << "directional_benchmarks: " << exception.what() << '\n';
    return 1;
  }
}
