#include "BenchmarkCases.h"
#include "BenchmarkQuality.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include <directional/geometry/MeshTopology.h>
#include <directional/integration/IntegerBatchSelector.h>
#include <directional/integration/IntegrationLinearSolver.h>
#include <directional/integration/ParametrizationQuality.h>
#include <directional/meshing/Mesher.h>

namespace directional::bench {
namespace {

struct Options {
  std::filesystem::path manifestPath;
  std::string selectedCase;
  IntegrationSolveStrategy solveStrategy = IntegrationSolveStrategy::DirectOnly;
  IntegerBatchStrategy batchStrategy = IntegerBatchStrategy::ResidualOnly;
  bool reduceIntegerTransitionBasis = false;
  bool integrationOnly = false;
  bool verbose = false;
  bool skipConstraintRankReduction = false;
  bool useFunctionSkeletonCleanup = true;
  bool useLocalPatchPrevalidation = true;
  bool useLocalPatchQuadrangulationFallback = false;
  bool preconditionInputMesh = false;
  bool parallelizeComponents = false;
  bool useTargetedParametrizationStiffening = false;
  int maxComponentThreads = 0;
  int maximumIntegerBatchSize = 0;
  int surfaceCellInjectFailureAfterStage = -1;
  bool disableSurfaceCellSourceGridRecovery = false;
  std::filesystem::path parametrizationHeatmapDirectory;
  std::filesystem::path saveMesherCachePath;
  std::filesystem::path loadMesherCachePath;
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
  std::uint64_t peakWorkingSetBytes = 0;
  bool sameSampleOwnershipMeasurementAvailable = false;
  std::uint64_t sameSampleWorkingSetBytes = 0;
  std::uint64_t sameSampleCategorizedOwnedBytes = 0;
  std::uint64_t sameSampleReconciliationRemainderBytes = 0;
  std::uint64_t sameSampleSequence = 0;
  std::uint64_t fixtureHash = 0;
  std::uint64_t fieldHash = 0;
  bool usedFieldFile = false;
  std::string error;
  std::string reviewImagePath;
  pipeline::RemeshResult result;
  StructuralMetrics metrics;
  BenchmarkQuality quality;
};

void print_usage() {
  std::cout << "Usage: directional_benchmarks [options]\n"
            << "  --manifest <path>   Benchmark fixture manifest JSON.\n"
            << "  --case <name>       Run one case from the manifest.\n"
            << "  --solve-strategy <direct|adaptive>\n"
            << "  --batch-strategy <residual|coupling>\n"
            << "  --reduce-transition-basis\n"
            << "  --integration-only Stop after integration diagnostics.\n"
            << "  --skip-constraint-rank-reduction\n"
            << "  --disable-function-skeleton-cleanup\n"
            << "  --disable-local-patch-prevalidation\n"
            << "  --enable-local-patch-quadrangulation-fallback\n"
            << "  --precondition-input-mesh\n"
            << "  --parallelize-components\n"
            << "  --enable-targeted-stiffening\n"
            << "  --max-component-threads <count> 0 selects hardware concurrency.\n"
            << "  --integer-batch-max <count> Override integration rounding batch cap.\n"
            << "  --surface-cell-inject-failure-after-stage <index> Stop after a SurfaceCells stage for diagnostics.\n"
            << "  --disable-surface-cell-source-grid-recovery Diagnose direct SurfaceCells completion without recovery.\n"
            << "  --write-parametrization-heatmaps <dir>\n"
            << "  --save-mesher-cache <path>\n"
            << "  --load-mesher-cache <path> Run mesher only from cache.\n"
            << "  --verbose          Emit pipeline progress logs.\n"
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
    } else if (argument == "--solve-strategy") {
      const std::string strategy = requireValue("--solve-strategy");
      if (strategy == "direct" || strategy == "direct-only" ||
          strategy == "DirectOnly") {
        options.solveStrategy = IntegrationSolveStrategy::DirectOnly;
      } else if (strategy == "adaptive" || strategy == "Adaptive") {
        options.solveStrategy = IntegrationSolveStrategy::Adaptive;
      } else {
        throw std::runtime_error(
            "--solve-strategy requires direct or adaptive.");
      }
    } else if (argument == "--batch-strategy") {
      const std::string strategy = requireValue("--batch-strategy");
      if (strategy == "residual" || strategy == "residual-only" ||
          strategy == "ResidualOnly") {
        options.batchStrategy = IntegerBatchStrategy::ResidualOnly;
      } else if (strategy == "coupling" || strategy == "coupling-aware" ||
                 strategy == "CouplingAware") {
        options.batchStrategy = IntegerBatchStrategy::CouplingAware;
      } else {
        throw std::runtime_error(
            "--batch-strategy requires residual or coupling.");
      }
    } else if (argument == "--reduce-transition-basis") {
      options.reduceIntegerTransitionBasis = true;
    } else if (argument == "--integration-only") {
      options.integrationOnly = true;
    } else if (argument == "--skip-constraint-rank-reduction") {
      options.skipConstraintRankReduction = true;
    } else if (argument == "--disable-function-skeleton-cleanup") {
      options.useFunctionSkeletonCleanup = false;
    } else if (argument == "--disable-local-patch-prevalidation") {
      options.useLocalPatchPrevalidation = false;
    } else if (argument ==
               "--enable-local-patch-quadrangulation-fallback") {
      options.useLocalPatchQuadrangulationFallback = true;
    } else if (argument == "--precondition-input-mesh") {
      options.preconditionInputMesh = true;
    } else if (argument == "--parallelize-components") {
      options.parallelizeComponents = true;
    } else if (argument == "--enable-targeted-stiffening") {
      options.useTargetedParametrizationStiffening = true;
    } else if (argument == "--max-component-threads") {
      options.maxComponentThreads =
          parse_nonnegative_int(requireValue("--max-component-threads"),
                                "--max-component-threads");
    } else if (argument == "--integer-batch-max") {
      options.maximumIntegerBatchSize =
          parse_nonnegative_int(requireValue("--integer-batch-max"),
                                "--integer-batch-max");
      if (options.maximumIntegerBatchSize <= 0) {
        throw std::runtime_error("--integer-batch-max must be greater than zero.");
      }
    } else if (argument == "--surface-cell-inject-failure-after-stage") {
      options.surfaceCellInjectFailureAfterStage = parse_nonnegative_int(
          requireValue("--surface-cell-inject-failure-after-stage"),
          "--surface-cell-inject-failure-after-stage");
    } else if (argument ==
               "--disable-surface-cell-source-grid-recovery") {
      options.disableSurfaceCellSourceGridRecovery = true;
    } else if (argument == "--write-parametrization-heatmaps") {
      options.parametrizationHeatmapDirectory =
          requireValue("--write-parametrization-heatmaps");
    } else if (argument == "--save-mesher-cache") {
      options.saveMesherCachePath = requireValue("--save-mesher-cache");
    } else if (argument == "--load-mesher-cache") {
      options.loadMesherCachePath = requireValue("--load-mesher-cache");
    } else if (argument == "--verbose") {
      options.verbose = true;
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

std::string safe_artifact_name(std::string value) {
  for (char &character : value) {
    const unsigned char byte = static_cast<unsigned char>(character);
    if (!std::isalnum(byte) && character != '-' && character != '_') {
      character = '_';
    }
  }
  return value.empty() ? "case" : value;
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
  metrics.outputVertices = static_cast<int>(result.product().vertices.rows());
  metrics.outputFaces = static_cast<int>(result.product().degrees.size());
  if (metrics.outputVertices == 0 || metrics.outputFaces == 0) {
    return metrics;
  }

  std::map<std::pair<int, int>, int> edgeUse;
  std::vector<std::vector<int>> adjacency(static_cast<std::size_t>(metrics.outputVertices));
  for (int face = 0; face < metrics.outputFaces; ++face) {
    if (result.product().degrees(face) == 4) {
      ++metrics.quadFaces;
    } else {
      ++metrics.nonQuadFaces;
    }
    if (polygon_area(result.product().vertices, result.product().faces, result.product().degrees, face) <= 1.0e-14) {
      ++metrics.degenerateFaces;
    }
    for (int corner = 0; corner < result.product().degrees(face); ++corner) {
      const int a = result.product().faces(face, corner);
      const int b = result.product().faces(face, (corner + 1) % result.product().degrees(face));
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

std::array<unsigned char, 3>
determinant_heatmap_color(const ParametrizationFaceQuality &quality) {
  if (quality.inverted) {
    return {220, 40, 40};
  }
  if (quality.nearDegenerate || quality.highCondition ||
      quality.highScaleDistortion) {
    return {255, 150, 35};
  }
  const double determinant =
      std::isfinite(quality.determinant) ? std::abs(quality.determinant) : 0.0;
  const double normalized = std::clamp(std::log1p(determinant) / std::log(2.0),
                                       0.0, 1.0);
  const auto channel = [](const double value) -> unsigned char {
    return static_cast<unsigned char>(
        std::clamp(std::lround(value), 0L, 255L));
  };
  return {channel(45.0 + 180.0 * normalized),
          channel(95.0 + 130.0 * normalized), 255};
}

void write_parametrization_heatmap_ply(
    const std::filesystem::path &path,
    const directional::pipeline::RemeshResult &result) {
  if (result.product().cutVertices.rows() == 0 || result.product().cutFaces.rows() == 0 ||
      result.product().cutFunctions.rows() == 0 || result.product().cutFunctions.cols() < 2) {
    return;
  }

  const ParametrizationQualityReport report =
      analyze_parametrization_quality(result.product().cutVertices, result.product().cutFaces,
                                      result.product().cutFunctions);

  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }

  std::ofstream out(path);
  if (!out) {
    throw std::runtime_error("Failed to open parametrization heatmap: " +
                             path.string());
  }

  out << "ply\n"
      << "format ascii 1.0\n"
      << "comment Directional parametrization determinant heatmap\n"
      << "comment red=inverted orange=degenerate/high-distortion blue=healthy\n"
      << "element vertex " << result.product().cutVertices.rows() << "\n"
      << "property float x\n"
      << "property float y\n"
      << "property float z\n"
      << "element face " << result.product().cutFaces.rows() << "\n"
      << "property list uchar int vertex_indices\n"
      << "property uchar red\n"
      << "property uchar green\n"
      << "property uchar blue\n"
      << "end_header\n";

  out << std::setprecision(9);
  for (Eigen::Index row = 0; row < result.product().cutVertices.rows(); ++row) {
    out << result.product().cutVertices(row, 0) << ' ' << result.product().cutVertices(row, 1)
        << ' ' << result.product().cutVertices(row, 2) << '\n';
  }

  for (Eigen::Index face = 0; face < result.product().cutFaces.rows(); ++face) {
    const std::array<unsigned char, 3> color = determinant_heatmap_color(
        report.faces[static_cast<std::size_t>(face)]);
    out << "3 " << result.product().cutFaces(face, 0) << ' ' << result.product().cutFaces(face, 1)
        << ' ' << result.product().cutFaces(face, 2) << ' '
        << static_cast<int>(color[0]) << ' ' << static_cast<int>(color[1])
        << ' ' << static_cast<int>(color[2]) << '\n';
  }
}

template <typename T> void write_binary(std::ostream &out, const T &value) {
  out.write(reinterpret_cast<const char *>(&value), sizeof(T));
}

template <typename T> void read_binary(std::istream &in, T &value) {
  in.read(reinterpret_cast<char *>(&value), sizeof(T));
  if (!in) {
    throw std::runtime_error("Unexpected end of mesher cache.");
  }
}

void write_matrix(std::ostream &out, const Eigen::MatrixXd &matrix) {
  const std::int64_t rows = matrix.rows();
  const std::int64_t cols = matrix.cols();
  write_binary(out, rows);
  write_binary(out, cols);
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      write_binary(out, matrix(row, col));
    }
  }
}

Eigen::MatrixXd read_matrix(std::istream &in) {
  std::int64_t rows = 0;
  std::int64_t cols = 0;
  read_binary(in, rows);
  read_binary(in, cols);
  Eigen::MatrixXd matrix(rows, cols);
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      read_binary(in, matrix(row, col));
    }
  }
  return matrix;
}

void write_matrix(std::ostream &out, const Eigen::MatrixXi &matrix) {
  const std::int64_t rows = matrix.rows();
  const std::int64_t cols = matrix.cols();
  write_binary(out, rows);
  write_binary(out, cols);
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      write_binary(out, matrix(row, col));
    }
  }
}

Eigen::MatrixXi read_matrix_i(std::istream &in) {
  std::int64_t rows = 0;
  std::int64_t cols = 0;
  read_binary(in, rows);
  read_binary(in, cols);
  Eigen::MatrixXi matrix(rows, cols);
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      read_binary(in, matrix(row, col));
    }
  }
  return matrix;
}

void write_vector(std::ostream &out, const Eigen::VectorXd &vector) {
  write_matrix(out, Eigen::MatrixXd(vector));
}

Eigen::VectorXd read_vector(std::istream &in) {
  return read_matrix(in);
}

void write_vector(std::ostream &out, const Eigen::VectorXi &vector) {
  write_matrix(out, Eigen::MatrixXi(vector));
}

Eigen::VectorXi read_vector_i(std::istream &in) {
  return read_matrix_i(in);
}

template <typename Scalar>
void write_sparse(std::ostream &out,
                  const Eigen::SparseMatrix<Scalar> &matrix) {
  const std::int64_t rows = matrix.rows();
  const std::int64_t cols = matrix.cols();
  const std::int64_t nonZeros = matrix.nonZeros();
  write_binary(out, rows);
  write_binary(out, cols);
  write_binary(out, nonZeros);
  for (int col = 0; col < matrix.outerSize(); ++col) {
    for (typename Eigen::SparseMatrix<Scalar>::InnerIterator it(matrix, col);
         it; ++it) {
      const std::int64_t rowIndex = it.row();
      const std::int64_t colIndex = it.col();
      const Scalar value = it.value();
      write_binary(out, rowIndex);
      write_binary(out, colIndex);
      write_binary(out, value);
    }
  }
}

template <typename Scalar>
Eigen::SparseMatrix<Scalar> read_sparse(std::istream &in) {
  std::int64_t rows = 0;
  std::int64_t cols = 0;
  std::int64_t nonZeros = 0;
  read_binary(in, rows);
  read_binary(in, cols);
  read_binary(in, nonZeros);
  std::vector<Eigen::Triplet<Scalar>> triplets;
  triplets.reserve(static_cast<std::size_t>(nonZeros));
  for (std::int64_t index = 0; index < nonZeros; ++index) {
    std::int64_t row = 0;
    std::int64_t col = 0;
    Scalar value{};
    read_binary(in, row);
    read_binary(in, col);
    read_binary(in, value);
    triplets.emplace_back(static_cast<int>(row), static_cast<int>(col), value);
  }
  Eigen::SparseMatrix<Scalar> matrix(static_cast<int>(rows),
                                     static_cast<int>(cols));
  matrix.setFromTriplets(triplets.begin(), triplets.end());
  matrix.makeCompressed();
  return matrix;
}

void save_mesher_cache(const std::filesystem::path &path,
                       const MesherData &mesherData) {
  if (!path.parent_path().empty()) {
    std::filesystem::create_directories(path.parent_path());
  }
  std::ofstream out(path, std::ios::binary);
  if (!out) {
    throw std::runtime_error("Failed to open mesher cache for writing: " +
                             path.string());
  }
  const std::array<char, 16> magic = {'D', 'I', 'R', 'M', 'E', 'S',
                                      'H', 'C', 'A', 'C', 'H', 'E',
                                      '0', '1', '\0', '\0'};
  out.write(magic.data(), static_cast<std::streamsize>(magic.size()));
  write_binary(out, mesherData.N);
  write_binary(out, mesherData.exactResolution);
  write_matrix(out, mesherData.cutV);
  write_matrix(out, mesherData.cutF);
  write_vector(out, mesherData.vertexNFunction);
  write_sparse(out, mesherData.orig2CutMat);
  write_sparse(out, mesherData.exactOrig2CutMat);
  write_vector(out, mesherData.integerVars);
}

MesherData load_mesher_cache(const std::filesystem::path &path) {
  std::ifstream in(path, std::ios::binary);
  if (!in) {
    throw std::runtime_error("Failed to open mesher cache for reading: " +
                             path.string());
  }
  std::array<char, 16> magic = {};
  in.read(magic.data(), static_cast<std::streamsize>(magic.size()));
  const std::array<char, 16> expected = {'D', 'I', 'R', 'M', 'E', 'S',
                                         'H', 'C', 'A', 'C', 'H', 'E',
                                         '0', '1', '\0', '\0'};
  if (!in || magic != expected) {
    throw std::runtime_error("Invalid mesher cache header: " + path.string());
  }
  MesherData mesherData;
  read_binary(in, mesherData.N);
  read_binary(in, mesherData.exactResolution);
  mesherData.cutV = read_matrix(in);
  mesherData.cutF = read_matrix_i(in);
  mesherData.vertexNFunction = read_vector(in);
  mesherData.orig2CutMat = read_sparse<double>(in);
  mesherData.exactOrig2CutMat = read_sparse<int>(in);
  mesherData.integerVars = read_vector_i(in);
  return mesherData;
}

void record_benchmark_exception(RunRecord &record,
                                const BenchmarkCase &benchmarkCase,
                                const std::string &message) {
  record.error = message;
  RemeshDiagnostics &diagnostics = record.result.diagnostics;
  diagnostics.remeshBackend =
      pipeline::remesh_backend_name(benchmarkCase.backend);
  diagnostics.requestedBackend = diagnostics.remeshBackend;
  diagnostics.executedBackend = diagnostics.remeshBackend;
  diagnostics.surfaceCellFallbackPolicy =
      pipeline::surface_cell_fallback_policy_name(
          benchmarkCase.surfaceCellFallback);
  diagnostics.terminalFailureCode = "BenchmarkException";
  diagnostics.terminalFailureStage = "benchmark";
}

RunRecord run_case_once(
    const BenchmarkCase &benchmarkCase, const Options &benchmarkOptions,
    const std::filesystem::path &artifactDirectory = {},
    std::map<std::uint64_t, BenchmarkQuality> *qualityCache = nullptr) {
  RunRecord record;
  const BenchmarkMesh mesh = load_benchmark_mesh(benchmarkCase);
  record.fixtureHash = hash_benchmark_mesh(mesh);
  if (!benchmarkOptions.loadMesherCachePath.empty()) {
    PeakWorkingSetSampler memorySampler;
    const auto start = std::chrono::steady_clock::now();
    try {
      TriMesh meshWhole;
      meshWhole.set_mesh(mesh.vertices, mesh.faces);
      MesherData mesherData =
          load_mesher_cache(benchmarkOptions.loadMesherCachePath);
      mesherData.verbose = benchmarkOptions.verbose;
      mesherData.useFunctionSkeletonCleanup =
          benchmarkOptions.useFunctionSkeletonCleanup;
      mesherData.useLocalPatchPrevalidation =
          benchmarkOptions.useLocalPatchPrevalidation;
      mesherData.useLocalPatchQuadrangulationFallback =
          benchmarkOptions.useLocalPatchQuadrangulationFallback;
      pipeline::RemeshProduct product;
      product.cutVertices = mesherData.cutV;
      product.cutFaces = mesherData.cutF;
      const bool mesherSucceeded =
          mesher(meshWhole, mesherData, product.vertices, product.degrees,
                 product.faces);
      directional::RemeshDiagnostics diagnostics;
      diagnostics.mesher = mesherData.diagnostics;
      if (mesherSucceeded) {
        record.result = pipeline::RemeshResult::produced(
            std::move(product), pipeline::RemeshProductKind::Meshed, true, {},
            std::move(diagnostics));
      } else {
        pipeline::RemeshFailure failure;
        failure.kind = pipeline::RemeshFailureKind::MesherRejected;
        failure.stage = "mesher-cache";
        failure.crossFieldAccepted = true;
        record.result = pipeline::RemeshResult::rejected(
            std::move(failure), {}, std::move(diagnostics));
      }
      record.success = record.result.is_produced();
      if (record.success) {
        record.metrics = compute_structural_metrics(record.result);
      }
    } catch (const std::exception &exception) {
      record.success = false;
      record_benchmark_exception(record, benchmarkCase, exception.what());
    } catch (...) {
      record.success = false;
      record_benchmark_exception(record, benchmarkCase,
                                 "unknown non-std exception");
    }
    record.wallSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now() - start)
            .count() /
        1.0e6;
    record.sameSampleWorkingSetBytes =
        current_process_working_set_bytes();
    record.sameSampleSequence = static_cast<std::uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::steady_clock::now().time_since_epoch())
            .count());
    if (!record.result.surfaceCellContext.memoryOwnershipTimeline.empty()) {
      record.sameSampleCategorizedOwnedBytes =
          record.result.surfaceCellContext.memoryOwnershipTimeline.back()
              .simultaneousOwnedBytes;
      record.sameSampleOwnershipMeasurementAvailable =
          record.sameSampleWorkingSetBytes > 0U;
    }
    record.sameSampleReconciliationRemainderBytes =
        record.sameSampleWorkingSetBytes >
                record.sameSampleCategorizedOwnedBytes
            ? record.sameSampleWorkingSetBytes -
                  record.sameSampleCategorizedOwnedBytes
            : 0U;
    record.peakWorkingSetBytes = memorySampler.finish();
    return record;
  }
  BenchmarkField field = load_benchmark_field(benchmarkCase, mesh.faces.rows());
  if (!field.available) {
    field = generate_benchmark_field(benchmarkCase, mesh);
  }
  if (field.available) {
    record.usedFieldFile = true;
    record.fieldHash = hash_matrix(field.raw);
  }
  pipeline::RemeshOptions options = make_remesh_options(benchmarkCase);
  options.integrationSolveStrategy = benchmarkOptions.solveStrategy;
  options.integerBatching.strategy = benchmarkOptions.batchStrategy;
  options.integerTransitionBasis.reduceIntegerTransitionBasis =
      benchmarkOptions.reduceIntegerTransitionBasis;
  options.stopAfterIntegration = benchmarkOptions.integrationOnly;
  options.verbose = benchmarkOptions.verbose;
  options.skipConstraintRankReduction =
      benchmarkOptions.skipConstraintRankReduction;
  options.useFunctionSkeletonCleanup =
      benchmarkOptions.useFunctionSkeletonCleanup;
  options.useLocalPatchPrevalidation =
      benchmarkOptions.useLocalPatchPrevalidation;
  options.useLocalPatchQuadrangulationFallback =
      benchmarkOptions.useLocalPatchQuadrangulationFallback;
  options.preconditionInputMesh = benchmarkOptions.preconditionInputMesh;
  options.parallelizeComponents = benchmarkOptions.parallelizeComponents;
  options.useTargetedParametrizationStiffening =
      benchmarkOptions.useTargetedParametrizationStiffening;
  options.targetedStiffening.enabled =
      benchmarkOptions.useTargetedParametrizationStiffening;
  options.maxComponentThreads = benchmarkOptions.maxComponentThreads;
  if (benchmarkOptions.surfaceCellInjectFailureAfterStage >= 0) {
    options.surfaceCells.injectFailureAfterStage =
        benchmarkOptions.surfaceCellInjectFailureAfterStage;
  }
  if (benchmarkOptions.disableSurfaceCellSourceGridRecovery) {
    options.surfaceCells.allowSourceGridRecovery = false;
  }
  if (benchmarkOptions.maximumIntegerBatchSize > 0) {
    options.integerBatching.maximumBatchSize =
        benchmarkOptions.maximumIntegerBatchSize;
  }
  if (!benchmarkOptions.saveMesherCachePath.empty()) {
    options.mesherDataCallback =
        [path = benchmarkOptions.saveMesherCachePath](
            const MesherData &mesherData) { save_mesher_cache(path, mesherData); };
  }
  if (benchmarkOptions.solveStrategy == IntegrationSolveStrategy::Adaptive &&
      benchmarkOptions.batchStrategy == IntegerBatchStrategy::ResidualOnly) {
    options.integerBatching.absoluteResidualCeiling = 0.49;
    options.integerBatching.residualWindow = 0.49;
  }
  PeakWorkingSetSampler memorySampler;
  const auto start = std::chrono::steady_clock::now();
  try {
    if (field.available) {
      record.result = pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, field.raw, options);
    } else {
      record.result =
          pipeline::remesh_from_mesh(mesh.vertices, mesh.faces, options);
    }
    record.success = record.result.is_produced();
    if (record.success) {
      record.metrics = compute_structural_metrics(record.result);
    }
  } catch (const std::exception &exception) {
    record.success = false;
    record_benchmark_exception(record, benchmarkCase, exception.what());
  } catch (...) {
    record.success = false;
    record_benchmark_exception(record, benchmarkCase,
                               "unknown non-std exception");
  }
  record.wallSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::steady_clock::now() - start)
          .count() /
      1.0e6;
  record.sameSampleWorkingSetBytes = current_process_working_set_bytes();
  record.sameSampleSequence = static_cast<std::uint64_t>(
      std::chrono::duration_cast<std::chrono::nanoseconds>(
          std::chrono::steady_clock::now().time_since_epoch())
          .count());
  if (!record.result.surfaceCellContext.memoryOwnershipTimeline.empty()) {
    record.sameSampleCategorizedOwnedBytes =
        record.result.surfaceCellContext.memoryOwnershipTimeline.back()
            .simultaneousOwnedBytes;
    record.sameSampleOwnershipMeasurementAvailable =
        record.sameSampleWorkingSetBytes > 0U;
  }
  record.sameSampleReconciliationRemainderBytes =
      record.sameSampleWorkingSetBytes > record.sameSampleCategorizedOwnedBytes
          ? record.sameSampleWorkingSetBytes -
                record.sameSampleCategorizedOwnedBytes
          : 0U;
  record.peakWorkingSetBytes = memorySampler.finish();
  if (record.success && !artifactDirectory.empty()) {
    const std::uint64_t outputHash =
        benchmark_output_structural_hash(record.result);
    if (qualityCache != nullptr) {
      const auto cached = qualityCache->find(outputHash);
      if (cached != qualityCache->end()) {
        record.quality = cached->second;
        record.quality.peakWorkingSetBytes = record.peakWorkingSetBytes;
      } else {
        record.quality = evaluate_benchmark_quality(
            benchmarkCase, mesh, field, record.result,
            record.peakWorkingSetBytes, artifactDirectory);
        if (record.quality.available) {
          qualityCache->emplace(outputHash, record.quality);
        }
      }
    } else {
      record.quality = evaluate_benchmark_quality(
          benchmarkCase, mesh, field, record.result,
          record.peakWorkingSetBytes, artifactDirectory);
    }
    record.reviewImagePath = record.quality.reviewImagePath;
  } else if (!record.success && !artifactDirectory.empty()) {
    try {
      record.reviewImagePath = write_benchmark_failure_review_image(
          benchmarkCase, mesh, artifactDirectory);
    } catch (const std::exception &exception) {
      if (!record.error.empty()) {
        record.error += "; ";
      }
      record.error +=
          std::string("failed to write review image: ") + exception.what();
    }
  }
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

void write_json_number(std::ostream &out, const double value) {
  if (std::isfinite(value)) {
    out << value;
  } else {
    out << "null";
  }
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
      << "\"constraintRankReductionSkipped\":"
      << (diagnostics.constraintRankReductionSkipped ? "true" : "false")
      << ","
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
      << "\"couplingAnalysisSeconds\":" << diagnostics.couplingAnalysisSeconds
      << ","
      << "\"integerTransitionBasisAnalysisSeconds\":"
      << diagnostics.integerTransitionBasisAnalysisSeconds << ","
      << "\"parametrizationQualityAnalysisSeconds\":"
      << diagnostics.parametrizationQualityAnalysisSeconds << ","
      << "\"targetedStiffeningExtraSolveSeconds\":"
      << diagnostics.targetedStiffeningExtraSolveSeconds << ","
      << "\"integerIterations\":" << diagnostics.integerIterations << ","
      << "\"rawTransitionCount\":" << diagnostics.rawTransitionCount << ","
      << "\"rawIntegerVariableCount\":" << diagnostics.rawIntegerVariableCount
      << ","
      << "\"reducedIntegerVariableCount\":"
      << diagnostics.reducedIntegerVariableCount << ","
      << "\"redundantIntegerVariableCount\":"
      << diagnostics.redundantIntegerVariableCount << ","
      << "\"integerTransitionReductionRatio\":"
      << diagnostics.integerTransitionReductionRatio << ","
      << "\"integerTransitionNumericalRank\":"
      << diagnostics.integerTransitionNumericalRank << ","
      << "\"integerTransitionReductionEnabled\":"
      << (diagnostics.integerTransitionReductionEnabled ? "true" : "false")
      << ","
      << "\"roundingBatches\":" << diagnostics.roundingBatches << ","
      << "\"roundingBatchHistogram\":[";
  for (std::size_t index = 0;
       index < diagnostics.roundingBatchHistogram.size(); ++index) {
    out << diagnostics.roundingBatchHistogram[index]
        << (index + 1 == diagnostics.roundingBatchHistogram.size() ? "" : ",");
  }
  out << "],"
      << "\"meanRoundingBatchSize\":" << diagnostics.meanRoundingBatchSize
      << ","
      << "\"medianRoundingBatchSize\":" << diagnostics.medianRoundingBatchSize
      << ","
      << "\"directFactorizations\":" << diagnostics.directFactorizations
      << ","
      << "\"iterativeAttempts\":" << diagnostics.iterativeAttempts << ","
      << "\"iterativeSuccesses\":" << diagnostics.iterativeSuccesses << ","
      << "\"iterativeFailures\":" << diagnostics.iterativeFailures << ","
      << "\"directFallbacks\":" << diagnostics.directFallbacks << ","
      << "\"parametrizationInitialBadFaceCount\":"
      << diagnostics.parametrizationInitialBadFaceCount << ","
      << "\"parametrizationPostStiffeningBadFaceCount\":"
      << diagnostics.parametrizationPostStiffeningBadFaceCount << ","
      << "\"parametrizationInvertedFaceCount\":"
      << diagnostics.parametrizationInvertedFaceCount << ","
      << "\"parametrizationNearDegenerateFaceCount\":"
      << diagnostics.parametrizationNearDegenerateFaceCount << ","
      << "\"targetedStiffeningPasses\":"
      << diagnostics.targetedStiffeningPasses << ","
      << "\"targetedStiffeningExtraFactorizations\":"
      << diagnostics.targetedStiffeningExtraFactorizations << ","
      << "\"adaptiveDisabledAfterFailures\":"
      << diagnostics.adaptiveDisabledAfterFailures << ","
      << "\"iterativeIterations\":" << diagnostics.iterativeIterations << ","
      << "\"iterativeSolverSeconds\":" << diagnostics.iterativeSolverSeconds
      << ","
      << "\"directFactorizationSecondsAvoided\":"
      << diagnostics.directFactorizationSecondsAvoided << ","
      << "\"medianIterationsPerIterativeSolve\":"
      << diagnostics.medianIterationsPerIterativeSolve << ","
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
      << "\"finalLinearSystemResidualNorm\":";
  write_json_number(out, diagnostics.finalLinearSystemResidualNorm);
  out << ","
      << "\"finalConstraintResidualNorm\":";
  write_json_number(out, diagnostics.finalConstraintResidualNorm);
  out << ","
      << "\"maximumUnresolvedIntegerResidual\":";
  write_json_number(out, diagnostics.maximumUnresolvedIntegerResidual);
  out << ","
      << "\"finalIntegrationEnergy\":";
  write_json_number(out, diagnostics.finalIntegrationEnergy);
  out << "}";
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
      << "\"functionSkeletonBuildSeconds\":"
      << diagnostics.functionSkeletonBuildSeconds << ","
      << "\"functionSkeletonSimplificationSeconds\":"
      << diagnostics.functionSkeletonSimplificationSeconds << ","
      << "\"functionSkeletonEditPlanApplicationSeconds\":"
      << diagnostics.functionSkeletonEditPlanApplicationSeconds << ","
      << "\"regionClassificationSeconds\":"
      << diagnostics.regionClassificationSeconds << ","
      << "\"faceRealignmentSeconds\":" << diagnostics.faceRealignmentSeconds
      << ","
      << "\"lowQualityFacePruneSeconds\":"
      << diagnostics.lowQualityFacePruneSeconds << ","
      << "\"lowValenceUnificationSeconds\":"
      << diagnostics.lowValenceUnificationSeconds << ","
      << "\"localPatchPrevalidationSeconds\":"
      << diagnostics.localPatchPrevalidationSeconds << ","
      << "\"postUnificationRetwinSeconds\":"
      << diagnostics.postUnificationRetwinSeconds << ","
      << "\"nonSimplePruneSeconds\":" << diagnostics.nonSimplePruneSeconds
      << ","
      << "\"holeFillSeconds\":" << diagnostics.holeFillSeconds << ","
      << "\"patchFallbackExtractionSeconds\":"
      << diagnostics.patchFallbackExtractionSeconds << ","
      << "\"patchFallbackClassificationSeconds\":"
      << diagnostics.patchFallbackClassificationSeconds << ","
      << "\"patchFallbackQuadrangulationSeconds\":"
      << diagnostics.patchFallbackQuadrangulationSeconds << ","
      << "\"patchFallbackReinsertionSeconds\":"
      << diagnostics.patchFallbackReinsertionSeconds << ","
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
      << "\"retwinCallCount\":" << diagnostics.retwinCallCount << ","
      << "\"retwinCallsBeforeFunctionCleanup\":"
      << diagnostics.retwinCallsBeforeFunctionCleanup << ","
      << "\"retwinCallsAfterFunctionCleanup\":"
      << diagnostics.retwinCallsAfterFunctionCleanup << ","
      << "\"retwinnedPairCount\":" << diagnostics.retwinnedPairCount << ","
      << "\"danglingFunctionEdgesCleared\":"
      << diagnostics.danglingFunctionEdgesCleared << ","
      << "\"functionSkeletonNodeCount\":"
      << diagnostics.functionSkeletonNodeCount << ","
      << "\"functionSkeletonEdgeCount\":"
      << diagnostics.functionSkeletonEdgeCount << ","
      << "\"functionSkeletonRawFunctionEdgeCount\":"
      << diagnostics.functionSkeletonRawFunctionEdgeCount << ","
      << "\"functionSkeletonAverageHalfedgesPerEdge\":"
      << diagnostics.functionSkeletonAverageHalfedgesPerEdge << ","
      << "\"functionSkeletonEditsPlanned\":"
      << diagnostics.functionSkeletonEditsPlanned << ","
      << "\"functionSkeletonEditsApplied\":"
      << diagnostics.functionSkeletonEditsApplied << ","
      << "\"functionSkeletonEditsRejected\":"
      << diagnostics.functionSkeletonEditsRejected << ","
      << "\"functionSkeletonMatchesConnectivity\":"
      << (diagnostics.functionSkeletonMatchesConnectivity ? "true" : "false")
      << ","
      << "\"lowQualityFacesPruned\":" << diagnostics.lowQualityFacesPruned
      << ","
      << "\"lowValenceCandidatesConsidered\":"
      << diagnostics.lowValenceCandidatesConsidered << ","
      << "\"localPatchPrevalidationAccepted\":"
      << diagnostics.localPatchPrevalidationAccepted << ","
      << "\"localPatchPrevalidationRejected\":"
      << diagnostics.localPatchPrevalidationRejected << ","
      << "\"localPatchInvalidPatchRejections\":"
      << diagnostics.localPatchInvalidPatchRejections << ","
      << "\"localPatchDisconnectedRegionRejections\":"
      << diagnostics.localPatchDisconnectedRegionRejections << ","
      << "\"localPatchRepeatedBoundaryVertexRejections\":"
      << diagnostics.localPatchRepeatedBoundaryVertexRejections << ","
      << "\"localPatchConsecutiveDuplicateEdgeRejections\":"
      << diagnostics.localPatchConsecutiveDuplicateEdgeRejections << ","
      << "\"localPatchFaceDegreeBelowThreeRejections\":"
      << diagnostics.localPatchFaceDegreeBelowThreeRejections << ","
      << "\"localPatchZeroLengthBoundaryEdgeRejections\":"
      << diagnostics.localPatchZeroLengthBoundaryEdgeRejections << ","
      << "\"localPatchEulerCharacteristicRejections\":"
      << diagnostics.localPatchEulerCharacteristicRejections << ","
      << "\"localPatchProtectedSeamRejections\":"
      << diagnostics.localPatchProtectedSeamRejections << ","
      << "\"localPatchComponentSplitRejections\":"
      << diagnostics.localPatchComponentSplitRejections << ","
      << "\"localPatchNewBoundaryOnClosedRegionRejections\":"
      << diagnostics.localPatchNewBoundaryOnClosedRegionRejections << ","
      << "\"lowValenceMutationsAttempted\":"
      << diagnostics.lowValenceMutationsAttempted << ","
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
      << ","
      << "\"patchFallbackRegionsDetected\":"
      << diagnostics.patchFallbackRegionsDetected << ","
      << "\"patchFallbackPatchesAttempted\":"
      << diagnostics.patchFallbackPatchesAttempted << ","
      << "\"patchFallbackPatchesSucceeded\":"
      << diagnostics.patchFallbackPatchesSucceeded << ","
      << "\"patchFallbackPatchesRejected\":"
      << diagnostics.patchFallbackPatchesRejected << ","
      << "\"patchFallbackFacesRepaired\":"
      << diagnostics.patchFallbackFacesRepaired << ","
      << "\"patchFallbackNonQuadFacesBefore\":"
      << diagnostics.patchFallbackNonQuadFacesBefore << ","
      << "\"patchFallbackNonQuadFacesAfter\":"
      << diagnostics.patchFallbackNonQuadFacesAfter
      << "}";
}

void write_remesh_diagnostics_json(std::ostream &out,
                                   const pipeline::RemeshResult &result) {
  const RemeshDiagnostics &diagnostics = result.diagnostics;
  const geometry::SourceTopologyRegions *sourceAuthority =
      result.surfaceCellContext.productSnapshots.traceNetwork.sourceTopologyRegions.has_value()
          ? &*result.surfaceCellContext.productSnapshots.traceNetwork.sourceTopologyRegions
          : nullptr;
  const auto typed_sheet_index =
      [](const std::optional<authority::IsolationSheetId> &sheet) {
        return sheet.has_value() ? static_cast<int>(sheet->index()) : -1;
      };
  const auto source_component_for_region =
      [&](const std::optional<authority::TopologyRegionId> &region) {
        if (sourceAuthority == nullptr || !region.has_value() ||
            region->index() >= sourceAuthority->regions().size()) {
          return -1;
        }
        return static_cast<int>(sourceAuthority->region(*region).component().index());
      };
  const auto source_component_for_face = [&](const int sourceFace) {
    if (sourceAuthority == nullptr || sourceFace < 0) return -1;
    const auto row = authority::SourceFaceId::from_index(
        sourceFace, sourceAuthority->face_count());
    return row ? static_cast<int>(sourceAuthority->component_for_row(row.value()).index())
               : -1;
  };
  const auto source_sheet_for_face = [&](const int sourceFace) {
    if (sourceAuthority == nullptr || sourceFace < 0) return -1;
    const auto row = authority::SourceFaceId::from_index(
        sourceFace, sourceAuthority->face_count());
    return row ? static_cast<int>(sourceAuthority->sheet_for_row(row.value()).index())
               : -1;
  };
  const auto source_scope_for_faces = [&](const std::vector<int> &sourceFaces) {
    if (sourceFaces.empty()) return std::pair<int, int>{-1, -1};
    const int component = source_component_for_face(sourceFaces.front());
    const int sheet = source_sheet_for_face(sourceFaces.front());
    for (const int sourceFace : sourceFaces) {
      if (source_component_for_face(sourceFace) != component ||
          source_sheet_for_face(sourceFace) != sheet) {
        return std::pair<int, int>{-1, -1};
      }
    }
    return std::pair<int, int>{component, sheet};
  };
  out << "{"
      << "\"overallPipelineSeconds\":" << diagnostics.overallPipelineSeconds
      << ","
      << "\"overallPipelineTimeAvailable\":"
      << (diagnostics.overallPipelineTimeAvailable ? "true" : "false") << ","
      << "\"remeshBackend\":\"" << diagnostics.remeshBackend << "\","
      << "\"requestedBackend\":\"" << diagnostics.requestedBackend << "\","
      << "\"executedBackend\":\"" << diagnostics.executedBackend << "\","
      << "\"surfaceCellFallbackPolicy\":\""
      << diagnostics.surfaceCellFallbackPolicy << "\","
      << "\"surfaceCellFallbackCause\":\""
      << diagnostics.surfaceCellFallbackCause << "\","
      << "\"originalSurfaceCellFailureCode\":\""
      << diagnostics.originalSurfaceCellFailureCode << "\","
      << "\"originalSurfaceCellFailureStage\":\""
      << diagnostics.originalSurfaceCellFailureStage << "\","
      << "\"terminalFailureCode\":\""
      << diagnostics.terminalFailureCode << "\","
      << "\"terminalFailureStage\":\""
      << diagnostics.terminalFailureStage << "\","
      << "\"surfaceCellFallbackAttempted\":"
      << (diagnostics.surfaceCellFallbackAttempted ? "true" : "false") << ","
      << "\"surfaceCellUsedLegacyFallback\":"
      << (diagnostics.surfaceCellUsedLegacyFallback ? "true" : "false") << ","
      << "\"surfaceCellReturnedInputMeshFallback\":"
      << (diagnostics.surfaceCellReturnedInputMeshFallback ? "true" : "false")
      << ","
      << "\"surfaceCellRemeshOccurred\":"
      << (diagnostics.surfaceCellRemeshOccurred ? "true" : "false") << ","
      << "\"surfaceCellSourceGridRecoveryUsed\":"
      << (diagnostics.surfaceCellSourceGridRecoveryUsed ? "true" : "false")
      << ","
      << "\"surfaceCellSourceGridRecoveryTargetSizeRelaxed\":"
      << (diagnostics.surfaceCellSourceGridRecoveryTargetSizeRelaxed
              ? "true"
              : "false")
      << ","
      << "\"surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio\":"
      << diagnostics.surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio
      << ","
      << "\"surfaceCellOutputOrigin\":\""
      << surface_cell_output_origin_name(diagnostics.surfaceCellOutputOrigin) << "\","
      << "\"surfaceCellStageLineage\":[";
  for (std::size_t stageIndex = 0;
       stageIndex < diagnostics.surfaceCellStageLineage.size(); ++stageIndex) {
    const SurfaceCellStageLineage &lineage =
        diagnostics.surfaceCellStageLineage[stageIndex];
    if (stageIndex > 0) {
      out << ",";
    }
    out << "{"
        << "\"stage\":\"" << lineage.stage << "\","
        << "\"inputObjectHash\":\"" << lineage.inputObjectHash << "\","
        << "\"outputObjectHash\":\"" << lineage.outputObjectHash << "\","
        << "\"inputObjectType\":\"" << lineage.inputObject.type << "\","
        << "\"inputStructuralHash\":" << lineage.inputObject.structuralHash << ","
        << "\"outputObjectType\":\"" << lineage.outputObject.type << "\","
        << "\"outputStructuralHash\":" << lineage.outputObject.structuralHash << ","
        << "\"objectCount\":" << lineage.objectCount << ","
        << "\"available\":" << (lineage.available ? "true" : "false") << ","
        << "\"consumedByNextStage\":"
        << (lineage.consumedByNextStage ? "true" : "false") << ","
        << "\"consumptionKind\":\"" << surface_cell_consumption_kind_name(lineage.consumptionKind) << "\","
        << "\"noOp\":" << (lineage.noOp ? "true" : "false") << ","
        << "\"componentIndex\":";
    if (lineage.componentIndex == std::numeric_limits<std::size_t>::max()) {
      out << "null";
    } else {
      out << lineage.componentIndex;
    }
    out << ","
        << "\"durationSeconds\":" << lineage.durationSeconds << ","
        << "\"terminalFailureCode\":\"" << lineage.terminalFailureCode << "\","
        << "\"terminalFailureStage\":\"" << lineage.terminalFailureStage << "\""
        << "}";
  }
  out << "],"
      << "\"surfaceCellContextProducts\":[";
  for (std::size_t productIndex = 0;
       productIndex < result.surfaceCellContext.debugProducts.size();
       ++productIndex) {
    const pipeline::SurfaceCellContextProductDebug &product =
        result.surfaceCellContext.debugProducts[productIndex];
    if (productIndex > 0) {
      out << ",";
    }
    out << "{"
        << "\"name\":\"" << escape_json(product.name) << "\","
        << "\"type\":\"" << escape_json(product.type) << "\","
        << "\"structuralHash\":" << product.structuralHash << ","
        << "\"elementCount\":" << product.elementCount << ","
        << "\"available\":" << (product.available ? "true" : "false")
        << "}";
  }
  out << "],"
      << "\"flowRepEndpointCompletionAttempted\":"
      << (result.surfaceCellContext.flowRepEndpointCompletionAttempted ? "true" : "false") << ","
      << "\"flowRepOpenEndpointsBeforeCompletion\":"
      << result.surfaceCellContext.flowRepOpenEndpointsBeforeCompletion << ","
      << "\"flowRepResolvedEndpoints\":"
      << result.surfaceCellContext.flowRepResolvedEndpoints << ","
      << "\"flowRepUnresolvedEndpoints\":"
      << result.surfaceCellContext.flowRepUnresolvedEndpoints << ","
      << "\"flowRepUnresolvedRequiredEndpoints\":"
      << result.surfaceCellContext.flowRepUnresolvedRequiredEndpoints << ","
      << "\"flowRepEndpointCompletionAddedArcs\":"
      << result.surfaceCellContext.flowRepEndpointCompletionAddedArcs << ","
      << "\"flowRepEndpointCompletionFailure\":\""
      << escape_json(result.surfaceCellContext.flowRepEndpointCompletionFailure)
      << "\","
      << "\"flowRepEndpointTerminationCounts\":[";
  for (std::size_t index = 0;
       index < result.surfaceCellContext.flowRepEndpointTerminationCounts.size();
       ++index) {
    if (index > 0) {
      out << ",";
    }
    out << result.surfaceCellContext.flowRepEndpointTerminationCounts[index];
  }
  out << "],"
      << "\"flowRepEndpointDiagnostics\":[";
  for (std::size_t index = 0;
       index < result.surfaceCellContext.flowRepEndpointDiagnostics.size();
       ++index) {
    if (index > 0) {
      out << ",";
    }
    const geometry::FlowRepEndpointCompletionDiagnostic &endpoint =
        result.surfaceCellContext.flowRepEndpointDiagnostics[index];
    out << "{"
        << "\"sourceArcId\":" << endpoint.sourceArcId << ","
        << "\"startEndpoint\":"
        << (endpoint.startEndpoint ? "true" : "false") << ","
        << "\"requiredSingularitySupport\":"
        << (endpoint.requiredSingularitySupport ? "true" : "false") << ","
        << "\"hardFeatureRail\":"
        << (endpoint.hardFeatureRail ? "true" : "false") << ","
        << "\"family\":" << endpoint.family << ","
        << "\"sign\":" << endpoint.sign << ","
        << "\"termination\":"
        << static_cast<int>(endpoint.termination) << ","
        << "\"tracedSegments\":" << endpoint.tracedSegments << ","
        << "\"skippedDegenerateSegments\":"
        << endpoint.skippedDegenerateSegments << ","
        << "\"terminalSourceFace\":" << endpoint.terminalSourceFace << ","
        << "\"terminalSourceVertex\":" << endpoint.terminalSourceVertex
        << ","
        << "\"terminalSourceEdge0\":" << endpoint.terminalSourceEdge0
        << ","
        << "\"terminalSourceEdge1\":" << endpoint.terminalSourceEdge1
        << ","
        << "\"terminalSourceEdgeT\":" << endpoint.terminalSourceEdgeT
        << ",\"terminalBarycentric\":[";
    write_json_number(out, endpoint.terminalBarycentric[0]);
    out << ",";
    write_json_number(out, endpoint.terminalBarycentric[1]);
    out << ",";
    write_json_number(out, endpoint.terminalBarycentric[2]);
    out << "],"
        << "\"lastRepresentableSourceFace\":"
        << endpoint.lastRepresentableSourceFace << ","
        << "\"lastRepresentableSourceVertex\":"
        << endpoint.lastRepresentableSourceVertex << ","
        << "\"lastRepresentableSourceEdge0\":"
        << endpoint.lastRepresentableSourceEdge0 << ","
        << "\"lastRepresentableSourceEdge1\":"
        << endpoint.lastRepresentableSourceEdge1 << ","
        << "\"lastRepresentableSourceEdgeT\":"
        << endpoint.lastRepresentableSourceEdgeT
        << ",\"lastRepresentableBarycentric\":[";
    write_json_number(out, endpoint.lastRepresentableBarycentric[0]);
    out << ",";
    write_json_number(out, endpoint.lastRepresentableBarycentric[1]);
    out << ",";
    write_json_number(out, endpoint.lastRepresentableBarycentric[2]);
    out << "],\"terminalDistanceToLastRepresentable\":";
    write_json_number(out, endpoint.terminalDistanceToLastRepresentable);
    out << ","
        << "\"terminalFeatureRailCandidates\":"
        << endpoint.terminalFeatureRailCandidates << ","
        << "\"terminalCompatibleFeatureRailCandidates\":"
        << endpoint.terminalCompatibleFeatureRailCandidates << ","
        << "\"generatedSupportTraceId\":"
        << endpoint.generatedSupportTraceId << ","
        << "\"captureTargetArcId\":" << endpoint.captureTargetArcId << ","
        << "\"captureTraceSegment\":" << endpoint.captureTraceSegment << ","
        << "\"captureTraceParameter\":";
    write_json_number(out, endpoint.captureTraceParameter);
    out << ",\"captureTargetParameter\":";
    write_json_number(out, endpoint.captureTargetParameter);
    out << ",\"captureTargetSourceFace\":"
        << endpoint.captureTargetSourceFace
        << ",\"captureBarycentric\":[";
    write_json_number(out, endpoint.captureBarycentric[0]);
    out << ",";
    write_json_number(out, endpoint.captureBarycentric[1]);
    out << ",";
    write_json_number(out, endpoint.captureBarycentric[2]);
    out << "],\"captureTargetStartBarycentric\":[";
    write_json_number(out, endpoint.captureTargetStartBarycentric[0]);
    out << ",";
    write_json_number(out, endpoint.captureTargetStartBarycentric[1]);
    out << ",";
    write_json_number(out, endpoint.captureTargetStartBarycentric[2]);
    out << "],\"captureTargetEndBarycentric\":[";
    write_json_number(out, endpoint.captureTargetEndBarycentric[0]);
    out << ",";
    write_json_number(out, endpoint.captureTargetEndBarycentric[1]);
    out << ",";
    write_json_number(out, endpoint.captureTargetEndBarycentric[2]);
    out << "],"
        << "\"resolution\":"
        << static_cast<int>(endpoint.resolution)
        << "}";
  }
  out << "],"
      << "\"simplificationDiagnosticsAvailable\":"
      << (result.surfaceCellContext.hasSimplificationDiagnostics ? "true"
                                                                 : "false")
      << ","
      << "\"simplificationCandidateCount\":"
      << result.surfaceCellContext.simplificationCandidateCount << ","
      << "\"simplificationTopologyHealingCandidateCount\":"
      << result.surfaceCellContext.simplificationTopologyHealingCandidateCount
      << ","
      << "\"simplificationCommitted\":"
      << result.surfaceCellContext.simplificationCommitted << ","
      << "\"simplificationRejected\":"
      << result.surfaceCellContext.simplificationRejected << ","
      << "\"simplificationGeneratedCandidates\":"
      << result.surfaceCellContext.simplificationGeneratedCandidates << ","
      << "\"simplificationDeduplicatedCandidates\":"
      << result.surfaceCellContext.simplificationDeduplicatedCandidates << ","
      << "\"simplificationInvalidatedCandidates\":"
      << result.surfaceCellContext.simplificationInvalidatedCandidates << ","
      << "\"simplificationStaleGenerationCandidates\":"
      << result.surfaceCellContext.simplificationStaleGenerationCandidates << ","
      << "\"simplificationFrontierGenerations\":"
      << result.surfaceCellContext.simplificationFrontierGenerations << ","
      << "\"simplificationPeakLiveCandidates\":"
      << result.surfaceCellContext.simplificationPeakLiveCandidates << ","
      << "\"simplificationEvaluatedCandidates\":"
      << result.surfaceCellContext.simplificationEvaluatedCandidates << ","
      << "\"simplificationTopologyHealingCandidates\":[";
  for (std::size_t index = 0;
       index < result.surfaceCellContext
                   .simplificationTopologyHealingCandidates.size();
       ++index) {
    if (index > 0) {
      out << ",";
    }
    const geometry::SurfaceSimplificationCandidate &candidate =
        result.surfaceCellContext
            .simplificationTopologyHealingCandidates[index];
    out << "{"
        << "\"candidateId\":" << candidate.stableId << ","
        << "\"type\":" << static_cast<int>(candidate.type) << ","
        << "\"touchesHardFeature\":"
        << (candidate.touchesHardFeature ? "true" : "false") << ","
        << "\"touchesBoundary\":"
        << (candidate.touchesBoundary ? "true" : "false") << ","
        << "\"touchesSingularity\":"
        << (candidate.touchesSingularity ? "true" : "false") << ","
        << "\"touchesLocalSheetBoundary\":"
        << (candidate.touchesLocalSheetBoundary ? "true" : "false") << ","
        << "\"changesTopology\":"
        << (candidate.changesTopology ? "true" : "false") << ","
        << "\"affectedPatchDisk\":"
        << (candidate.affectedPatchDisk ? "true" : "false") << ","
        << "\"sideFeasible\":"
        << (candidate.sideFeasible ? "true" : "false") << ","
        << "\"elementIds\":[";
    for (std::size_t elementIndex = 0;
         elementIndex < candidate.elementIds.size(); ++elementIndex) {
      if (elementIndex > 0) out << ",";
      out << candidate.elementIds[elementIndex];
    }
    out << "],\"affectedCellIds\":[";
    for (std::size_t cellIndex = 0;
         cellIndex < candidate.affectedCellIds.size(); ++cellIndex) {
      if (cellIndex > 0) out << ",";
      out << candidate.affectedCellIds[cellIndex];
    }
    out << "],\"elements\":[";
    for (std::size_t elementIndex = 0;
         elementIndex < candidate.elementIds.size(); ++elementIndex) {
      if (elementIndex > 0) out << ",";
      const int halfedgeId = candidate.elementIds[elementIndex];
      if (!result.surfaceCellContext.hasArrangement || halfedgeId < 0 ||
          halfedgeId >= static_cast<int>(
                            result.surfaceCellContext.productSnapshots.arrangement.halfedges
                                .size())) {
        out << "{\"halfedgeId\":" << halfedgeId << "}";
        continue;
      }
      const geometry::SurfaceArrangementHalfedge &halfedge =
          result.surfaceCellContext.productSnapshots.arrangement.halfedges[
              static_cast<std::size_t>(halfedgeId)];
      int fromDegree = 0;
      int toDegree = 0;
      for (const geometry::SurfaceArrangementHalfedge &incident :
           result.surfaceCellContext.productSnapshots.arrangement.halfedges) {
        if (incident.from == halfedge.from) ++fromDegree;
        if (incident.from == halfedge.to) ++toDegree;
      }
      out << "{"
          << "\"halfedgeId\":" << halfedge.id << ","
          << "\"twin\":" << halfedge.twin << ","
          << "\"from\":" << halfedge.from << ","
          << "\"to\":" << halfedge.to << ","
          << "\"fromDegree\":" << fromDegree << ","
          << "\"toDegree\":" << toDegree << ","
          << "\"sourceArc\":" << halfedge.sourceArc << ","
          << "\"family\":" << halfedge.family << ","
          << "\"strand\":" << halfedge.strand << ","
          << "\"sourceFace\":" << halfedge.sourceFace << ","
          << "\"sourceComponent\":"
          << source_component_for_region(halfedge.sourceTopologyRegion) << ","
          << "\"sourceSheet\":" << source_sheet_for_face(halfedge.sourceFace) << ","
          << "\"layoutSupport\":"
          << (halfedge.layoutSupport ? "true" : "false") << ","
          << "\"singularitySupport\":"
          << (halfedge.singularitySupport ? "true" : "false") << "}";
    }
    out << "]}";
  }
  out << "],\"simplificationTransactions\":[";
  for (std::size_t index = 0;
       index < result.surfaceCellContext.simplificationTransactions.size();
       ++index) {
    if (index > 0) {
      out << ",";
    }
    const geometry::SurfaceSimplificationTransaction &transaction =
        result.surfaceCellContext.simplificationTransactions[index];
    out << "{"
        << "\"candidateId\":" << transaction.candidateId << ","
        << "\"type\":" << static_cast<int>(transaction.type) << ","
        << "\"topologyHealing\":"
        << (transaction.topologyHealing ? "true" : "false") << ","
        << "\"committed\":"
        << (transaction.committed ? "true" : "false") << ","
        << "\"rejection\":" << static_cast<int>(transaction.rejection)
        << ","
        << "\"beforeNonDiskDefect\":"
        << transaction.beforeNonDiskDefect << ","
        << "\"afterNonDiskDefect\":" << transaction.afterNonDiskDefect
        << ","
        << "\"beforeNodeCount\":" << transaction.beforeNodeCount << ","
        << "\"afterNodeCount\":" << transaction.afterNodeCount << ","
        << "\"beforeUndirectedEdgeCount\":"
        << transaction.beforeUndirectedEdgeCount << ","
        << "\"afterUndirectedEdgeCount\":"
        << transaction.afterUndirectedEdgeCount << ","
        << "\"beforeInteriorCellCount\":"
        << transaction.beforeInteriorCellCount << ","
        << "\"afterInteriorCellCount\":"
        << transaction.afterInteriorCellCount << ","
        << "\"beforeEulerCharacteristic\":"
        << transaction.beforeEulerCharacteristic << ","
        << "\"afterEulerCharacteristic\":"
        << transaction.afterEulerCharacteristic << ","
        << "\"sourceEulerCharacteristic\":"
        << transaction.sourceEulerCharacteristic << ","
        << "\"beforeConnectedComponentCount\":"
        << transaction.beforeConnectedComponentCount << ","
        << "\"afterConnectedComponentCount\":"
        << transaction.afterConnectedComponentCount << ","
        << "\"sourceConnectedComponentCount\":"
        << transaction.sourceConnectedComponentCount << ","
        << "\"beforeBoundaryLoopCount\":"
        << transaction.beforeBoundaryLoopCount << ","
        << "\"afterBoundaryLoopCount\":"
        << transaction.afterBoundaryLoopCount << ","
        << "\"sourceBoundaryLoopCount\":"
        << transaction.sourceBoundaryLoopCount << ","
        << "\"beforeUnsplitCrossings\":"
        << transaction.beforeUnsplitCrossings << ","
        << "\"afterUnsplitCrossings\":"
        << transaction.afterUnsplitCrossings << ","
        << "\"beforeGeometricTJunctions\":"
        << transaction.beforeGeometricTJunctions << ","
        << "\"afterGeometricTJunctions\":"
        << transaction.afterGeometricTJunctions << ","
        << "\"trialBuilt\":"
        << (transaction.trialBuilt ? "true" : "false") << ","
        << "\"beforeEmbeddingValid\":"
        << (transaction.beforeEmbeddingValid ? "true" : "false") << ","
        << "\"beforeOrientationValid\":"
        << (transaction.beforeOrientationValid ? "true" : "false") << ","
        << "\"beforeBoundaryLoopsValid\":"
        << (transaction.beforeBoundaryLoopsValid ? "true" : "false") << ","
        << "\"beforeEulerCharacteristicValid\":"
        << (transaction.beforeEulerCharacteristicValid ? "true" : "false")
        << ","
        << "\"incidenceValid\":"
        << (transaction.incidenceValid ? "true" : "false") << ","
        << "\"embeddingValid\":"
        << (transaction.embeddingValid ? "true" : "false") << ","
        << "\"orientationValid\":"
        << (transaction.orientationValid ? "true" : "false") << ","
        << "\"boundaryLoopsValid\":"
        << (transaction.boundaryLoopsValid ? "true" : "false") << ","
        << "\"eulerCharacteristicValid\":"
        << (transaction.eulerCharacteristicValid ? "true" : "false") << ","
        << "\"noUnsplitCrossings\":"
        << (transaction.noUnsplitCrossings ? "true" : "false") << ","
        << "\"noGeometricTJunctions\":"
        << (transaction.noGeometricTJunctions ? "true" : "false") << ","
        << "\"topologyMismatchNotWorse\":"
        << (transaction.topologyMismatchNotWorse ? "true" : "false") << ","
        << "\"protectedSupportPreserved\":"
        << (transaction.protectedSupportPreserved ? "true" : "false")
        << ",\"elementIds\":[";
    for (std::size_t elementIndex = 0;
         elementIndex < transaction.elementIds.size(); ++elementIndex) {
      if (elementIndex > 0) out << ",";
      out << transaction.elementIds[elementIndex];
    }
    out << "],\"affectedCellIds\":[";
    for (std::size_t cellIndex = 0;
         cellIndex < transaction.affectedCellIds.size(); ++cellIndex) {
      if (cellIndex > 0) out << ",";
      out << transaction.affectedCellIds[cellIndex];
    }
    out << "]}";
  }
  out << "],"
      << "\"tracingCurrentOwnedBytes\":"
      << result.surfaceCellContext.tracingCurrentOwnedBytes << ","
      << "\"tracingPeakOwnedBytes\":"
      << result.surfaceCellContext.tracingPeakOwnedBytes << ","
      << "\"flowRepCurrentOwnedBytes\":"
      << result.surfaceCellContext.flowRepCurrentOwnedBytes << ","
      << "\"flowRepPeakOwnedBytes\":"
      << result.surfaceCellContext.flowRepPeakOwnedBytes << ","
      << "\"arrangementCurrentOwnedBytes\":"
      << result.surfaceCellContext.arrangementCurrentOwnedBytes << ","
      << "\"arrangementPeakOwnedBytes\":"
      << result.surfaceCellContext.arrangementPeakOwnedBytes << ","
      << "\"simplificationCurrentOwnedBytes\":"
      << result.surfaceCellContext.simplificationCurrentOwnedBytes << ","
      << "\"simplificationPeakOwnedBytes\":"
      << result.surfaceCellContext.simplificationPeakOwnedBytes << ","
      << "\"maxSimultaneousLiveLargeStructures\":"
      << result.surfaceCellContext.maxSimultaneousLiveLargeStructures << ","
      << "\"traceStorageReleasedAfterFlowRep\":"
      << (result.surfaceCellContext.traceStorageReleasedAfterFlowRep
              ? "true" : "false") << ","
      << "\"flowRepSelectionStorageReleasedAfterSelection\":"
      << (result.surfaceCellContext
                  .flowRepSelectionStorageReleasedAfterSelection
              ? "true" : "false") << ","
      << "\"embeddedArrangementStorageReleasedAfterArrangement\":"
      << (result.surfaceCellContext
                  .embeddedArrangementStorageReleasedAfterArrangement
              ? "true" : "false") << ","
      << "\"tracingLogicalPayloadBytes\":"
      << result.surfaceCellContext.tracingLogicalPayloadBytes << ","
      << "\"tracingRetainedCapacityBytes\":"
      << result.surfaceCellContext.tracingRetainedCapacityBytes << ","
      << "\"flowRepLogicalPayloadBytes\":"
      << result.surfaceCellContext.flowRepLogicalPayloadBytes << ","
      << "\"flowRepRetainedCapacityBytes\":"
      << result.surfaceCellContext.flowRepRetainedCapacityBytes << ","
      << "\"arrangementLogicalPayloadBytes\":"
      << result.surfaceCellContext.arrangementLogicalPayloadBytes << ","
      << "\"arrangementRetainedCapacityBytes\":"
      << result.surfaceCellContext.arrangementRetainedCapacityBytes << ","
      << "\"simplificationLogicalPayloadBytes\":"
      << result.surfaceCellContext.simplificationLogicalPayloadBytes << ","
      << "\"simplificationRetainedCapacityBytes\":"
      << result.surfaceCellContext.simplificationRetainedCapacityBytes << ","
      << "\"completionLogicalPayloadBytes\":"
      << result.surfaceCellContext.completionLogicalPayloadBytes << ","
      << "\"completionRetainedCapacityBytes\":"
      << result.surfaceCellContext.completionRetainedCapacityBytes << ","
      << "\"estimatedPeakSimultaneousOwnedBytes\":"
      << result.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes << ","
      << "\"memoryOwnershipTimeline\":[";
  for (std::size_t eventIndex = 0;
       eventIndex < result.surfaceCellContext.memoryOwnershipTimeline.size();
       ++eventIndex) {
    if (eventIndex > 0U) out << ",";
    const auto &event =
        result.surfaceCellContext.memoryOwnershipTimeline[eventIndex];
    out << "{\"stage\":\"" << escape_json(event.stage)
        << "\",\"action\":\"" << escape_json(event.action)
        << "\",\"logicalPayloadBytes\":"
        << event.logicalPayloadBytes
        << ",\"retainedCapacityBytes\":"
        << event.retainedCapacityBytes
        << ",\"simultaneousOwnedBytes\":"
        << event.simultaneousOwnedBytes << "}";
  }
  out << "],"
      << "\"surfaceCellContextSourceGridRecoveryUsed\":"
      << (result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed ? "true" : "false")
      << ","
      << "\"completionOddCellsBeforeRepair\":"
      << result.surfaceCellContext.completionOddCellsBeforeRepair << ","
      << "\"completionOddCellsAfterRepair\":"
      << result.surfaceCellContext.completionOddCellsAfterRepair << ","
      << "\"completionParitySplitEdges\":"
      << result.surfaceCellContext.completionParitySplitEdges << ","
      << "\"completionParityAlternativeCandidateBudget\":"
      << result.surfaceCellContext.completionParityAlternativeCandidateBudget
      << ","
      << "\"completionParityAlternativeCandidatesAttempted\":"
      << result.surfaceCellContext.completionParityAlternativeCandidatesAttempted
      << ","
      << "\"completionParityAlternativeVisitedStates\":"
      << result.surfaceCellContext.completionParityAlternativeVisitedStates
      << ","
      << "\"completionParityAlternativeSelectedExclusion\":"
      << result.surfaceCellContext.completionParityAlternativeSelectedExclusion
      << ","
      << "\"completionParityAlternativeStateSequenceHash\":"
      << result.surfaceCellContext.completionParityAlternativeStateSequenceHash
      << ","
      << "\"completionParityAlternativeDisposition\":\""
      << geometry::surface_cell_parity_alternative_disposition_name(
             result.surfaceCellContext.completionParityAlternativeDisposition)
      << "\","
      << "\"completionSideInfeasibleBeforeRepair\":"
      << result.surfaceCellContext.completionSideInfeasibleBeforeRepair << ","
      << "\"completionSideInfeasibleAfterRepair\":"
      << result.surfaceCellContext.completionSideInfeasibleAfterRepair << ","
      << "\"completionSideInitialEquationDefect\":"
      << result.surfaceCellContext.completionSideInitialEquationDefect << ","
      << "\"completionSideFinalEquationDefect\":"
      << result.surfaceCellContext.completionSideFinalEquationDefect << ","
      << "\"completionSideInsertedVertices\":"
      << result.surfaceCellContext.completionSideInsertedVertices << ","
      << "\"completionSideRollbackEquivalent\":"
      << (result.surfaceCellContext.completionSideRollbackEquivalent
              ? "true"
              : "false")
      << ","
      << "\"completionSideRollbackIdentityHashBefore\":"
      << result.surfaceCellContext.completionSideRollbackIdentityHashBefore
      << ","
      << "\"completionSideRollbackIdentityHashAfter\":"
      << result.surfaceCellContext.completionSideRollbackIdentityHashAfter
      << ","
      << "\"completionSideRollbackUndoOwnedBytes\":"
      << result.surfaceCellContext.completionSideRollbackUndoOwnedBytes
      << ","
      << "\"completionAttemptedPatches\":"
      << result.surfaceCellContext.completionAttemptedPatches << ","
      << "\"completionFailedPatches\":"
      << result.surfaceCellContext.completionFailedPatches << ","
      << "\"completionOwnershipRepairAttempts\":"
      << result.surfaceCellContext.completionOwnershipRepairAttempts << ","
      << "\"completionTemplateInitialConflictCount\":"
      << result.surfaceCellContext.completionTemplateInitialConflictCount << ","
      << "\"completionTemplateFinalConflictCount\":"
      << result.surfaceCellContext.completionTemplateFinalConflictCount << ","
      << "\"completionTemplateConflictComponentCount\":"
      << result.surfaceCellContext.completionTemplateConflictComponentCount << ","
      << "\"completionTemplateChangedPatchCount\":"
      << result.surfaceCellContext.completionTemplateChangedPatchCount << ","
      << "\"completionTemplateAssemblyPasses\":"
      << result.surfaceCellContext.completionTemplateAssemblyPasses << ","
      << "\"completionOwnershipStructuralRepairAttempts\":"
      << result.surfaceCellContext
             .completionOwnershipStructuralRepairAttempts
      << ","
      << "\"completionOwnershipInsertedBoundaryVertices\":"
      << result.surfaceCellContext
             .completionOwnershipInsertedBoundaryVertices
      << ","
      << "\"completionOwnershipStructuralCandidateBudget\":"
      << result.surfaceCellContext
             .completionOwnershipStructuralCandidateBudget
      << ","
      << "\"completionOwnershipStructuralCandidatesConsumed\":"
      << result.surfaceCellContext
             .completionOwnershipStructuralCandidatesConsumed
      << ","
      << "\"completionOwnershipVisitedStateCount\":"
      << result.surfaceCellContext.completionOwnershipVisitedStateCount
      << ","
      << "\"completionOwnershipFullRecomputationPasses\":"
      << result.surfaceCellContext
             .completionOwnershipFullRecomputationPasses
      << ","
      << "\"completionOwnershipIncrementalRecomputationPasses\":"
      << result.surfaceCellContext
             .completionOwnershipIncrementalRecomputationPasses
      << ","
      << "\"completionOwnershipPreConflictCount\":"
      << result.surfaceCellContext.completionOwnershipPreConflictCount
      << ","
      << "\"completionOwnershipPostConflictCount\":"
      << result.surfaceCellContext.completionOwnershipPostConflictCount
      << ","
      << "\"completionOwnershipRetainedConflictCount\":"
      << result.surfaceCellContext.completionOwnershipRetainedConflictCount
      << ","
      << "\"completionOwnershipRemovedConflictCount\":"
      << result.surfaceCellContext.completionOwnershipRemovedConflictCount
      << ","
      << "\"completionOwnershipIntroducedConflictCount\":"
      << result.surfaceCellContext.completionOwnershipIntroducedConflictCount
      << ","
      << "\"completionOwnershipConflictComponentCount\":"
      << result.surfaceCellContext.completionOwnershipConflictComponentCount
      << ","
      << "\"completionOwnershipIndependentComponentCount\":"
      << result.surfaceCellContext
             .completionOwnershipIndependentComponentCount
      << ","
      << "\"completionOwnershipReusedPatchCompletions\":"
      << result.surfaceCellContext.completionOwnershipReusedPatchCompletions
      << ","
      << "\"completionOwnershipRecomputedPatchCompletions\":"
      << result.surfaceCellContext
             .completionOwnershipRecomputedPatchCompletions
      << ","
      << "\"completionOwnershipProductCacheHashMisses\":"
      << result.surfaceCellContext
             .completionOwnershipProductCacheHashMisses
      << ","
      << "\"completionOwnershipProductCacheExactMismatches\":"
      << result.surfaceCellContext
             .completionOwnershipProductCacheExactMismatches
      << ","
      << "\"completionOwnershipProductCacheMismatchVector\":[";
  for (std::size_t mismatchIndex = 0;
       mismatchIndex < result.surfaceCellContext
                           .completionOwnershipProductCacheMismatchVector.size();
       ++mismatchIndex) {
    if (mismatchIndex > 0U) out << ",";
    const auto &mismatch = result.surfaceCellContext
        .completionOwnershipProductCacheMismatchVector[mismatchIndex];
    out << "{\"requestedCell\":" << mismatch.requestedCell
        << ",\"cachedCell\":" << mismatch.cachedCell
        << ",\"hashMiss\":" << (mismatch.hashMiss ? "true" : "false")
        << ",\"sourceDomain\":" << (mismatch.sourceDomain ? "true" : "false")
        << ",\"sideSubdivision\":" << (mismatch.sideSubdivision ? "true" : "false")
        << ",\"boundarySourceCoordinates\":"
        << (mismatch.boundarySourceCoordinates ? "true" : "false")
        << ",\"railCurveSupport\":" << (mismatch.railCurveSupport ? "true" : "false")
        << ",\"singularityRequirements\":"
        << (mismatch.singularityRequirements ? "true" : "false")
        << ",\"backendVariant\":" << (mismatch.backendVariant ? "true" : "false")
        << ",\"topologyTemplate\":" << (mismatch.topologyTemplate ? "true" : "false")
        << ",\"rebindValidation\":" << (mismatch.rebindValidation ? "true" : "false")
        << "}";
  }
  out << "],"
      << "\"completionParityScopeFailureAvailable\":"
      << (result.surfaceCellContext.hasCompletionParityScopeFailure
              ? "true" : "false")
      << ",\"completionParityOriginalCell\":"
      << result.surfaceCellContext.completionParityScopeFailure.originalCell
      << ",\"completionParityReplacementCell\":"
      << result.surfaceCellContext.completionParityScopeFailure.replacementCell
      << ",\"completionParityHalfedge\":"
      << result.surfaceCellContext.completionParityScopeFailure.halfedge
      << ",\"completionParityTwin\":"
      << result.surfaceCellContext.completionParityScopeFailure.twin
      << ",\"completionParitySelectedComponent\":"
      << result.surfaceCellContext.completionParityScopeFailure.selectedComponent
      << ",\"completionParitySelectedSheet\":"
      << result.surfaceCellContext.completionParityScopeFailure.selectedSheet
      << ",\"completionParityAvailableComponents\":[";
  for (std::size_t componentIndex = 0;
       componentIndex < result.surfaceCellContext.completionParityScopeFailure
                            .availableComponents.size();
       ++componentIndex) {
    if (componentIndex > 0U) out << ",";
    out << result.surfaceCellContext.completionParityScopeFailure
               .availableComponents[componentIndex];
  }
  out << "],\"completionParityAvailableSheets\":[";
  for (std::size_t sheetIndex = 0;
       sheetIndex < result.surfaceCellContext.completionParityScopeFailure
                        .availableSheets.size();
       ++sheetIndex) {
    if (sheetIndex > 0U) out << ",";
    out << result.surfaceCellContext.completionParityScopeFailure
               .availableSheets[sheetIndex];
  }
  out << "],"
      << "\"completionParityMutationPhase\":\""
      << escape_json(result.surfaceCellContext
                         .completionParityScopeFailure.mutationPhase)
      << "\","
      << "\"completionOwnershipPreConflictInventoryHash\":"
      << result.surfaceCellContext
             .completionOwnershipPreConflictInventoryHash
      << ","
      << "\"completionOwnershipPostConflictInventoryHash\":"
      << result.surfaceCellContext
             .completionOwnershipPostConflictInventoryHash
      << ","
      << "\"completionOwnershipConflictFrontierOwnedBytes\":"
      << result.surfaceCellContext
             .completionOwnershipConflictFrontierOwnedBytes
      << ","
      << "\"completionOwnershipProductCacheOwnedBytes\":"
      << result.surfaceCellContext
             .completionOwnershipProductCacheOwnedBytes
      << ","
      << "\"completionOwnershipCurrentLiveCandidateComplexes\":"
      << result.surfaceCellContext
             .completionOwnershipCurrentLiveCandidateComplexes
      << ","
      << "\"completionOwnershipPeakLiveCandidateComplexes\":"
      << result.surfaceCellContext
             .completionOwnershipPeakLiveCandidateComplexes
      << ","
      << "\"completionOwnershipLastCandidateHalfedge\":"
      << result.surfaceCellContext.completionOwnershipLastCandidateHalfedge
      << ","
      << "\"completionOwnershipRouteCandidateCount\":"
      << result.surfaceCellContext.completionOwnershipRouteCandidateCount
      << ","
      << "\"completionOwnershipRollbackOwnedBytes\":"
      << result.surfaceCellContext.completionOwnershipRollbackOwnedBytes
      << ","
      << "\"completionOwnershipCandidateOwnedBytes\":"
      << result.surfaceCellContext.completionOwnershipCandidateOwnedBytes
      << ","
      << "\"completionOwnershipDescriptorOwnedBytes\":"
      << result.surfaceCellContext.completionOwnershipDescriptorOwnedBytes
      << ","
      << "\"completionOwnershipCompletedPatchOwnedBytes\":"
      << result.surfaceCellContext
             .completionOwnershipCompletedPatchOwnedBytes
      << ","
      << "\"completionOwnershipAssemblyOwnedBytes\":"
      << result.surfaceCellContext.completionOwnershipAssemblyOwnedBytes
      << ","
      << "\"completionOwnershipCurrentStructuralOwnedBytes\":"
      << result.surfaceCellContext
             .completionOwnershipCurrentStructuralOwnedBytes
      << ","
      << "\"completionOwnershipPeakStructuralOwnedBytes\":"
      << result.surfaceCellContext.completionOwnershipPeakStructuralOwnedBytes
      << ","
      << "\"completionOwnershipLastCandidateHalfedges\":[";
  for (std::size_t halfedgeIndex = 0;
       halfedgeIndex < result.surfaceCellContext
                           .completionOwnershipLastCandidateHalfedges.size();
       ++halfedgeIndex) {
    if (halfedgeIndex > 0U) out << ",";
    out << result.surfaceCellContext
               .completionOwnershipLastCandidateHalfedges[halfedgeIndex];
  }
  out << "],"
      << "\"completionOwnershipStructuralExhaustionReason\":\""
      << geometry::surface_cell_structural_repair_exhaustion_reason_name(
             result.surfaceCellContext
                 .completionOwnershipStructuralExhaustionReason)
      << "\","
      << "\"completionOwnershipLastAffectedPatches\":[";
  for (std::size_t patchIndex = 0;
       patchIndex < result.surfaceCellContext
                        .completionOwnershipLastAffectedPatches.size();
       ++patchIndex) {
    if (patchIndex > 0U) out << ",";
    out << result.surfaceCellContext
               .completionOwnershipLastAffectedPatches[patchIndex];
  }
  out << "],"
      << "\"completionOwnershipRepairLog\":[";
  for (std::size_t attemptIndex = 0;
       attemptIndex <
       result.surfaceCellContext.completionOwnershipRepairLog.size();
       ++attemptIndex) {
    if (attemptIndex > 0U) out << ",";
    const geometry::SurfaceCellOwnershipRepairAttempt &attempt =
        result.surfaceCellContext
            .completionOwnershipRepairLog[attemptIndex];
    out << "{"
        << "\"ordinal\":" << attempt.ordinal << ","
        << "\"action\":\""
        << geometry::surface_cell_ownership_repair_action_name(
               attempt.action)
        << "\","
        << "\"conflictClass\":\""
        << geometry::surface_cell_ownership_conflict_name(
               attempt.conflictClass)
        << "\","
        << "\"resultingConflictClass\":\""
        << geometry::surface_cell_ownership_conflict_name(
               attempt.resultingConflictClass)
        << "\","
        << "\"firstPatch\":" << attempt.firstPatch << ","
        << "\"secondPatch\":" << attempt.secondPatch << ","
        << "\"selectedPatch\":" << attempt.selectedPatch << ","
        << "\"selectedHalfedge\":" << attempt.selectedHalfedge
        << ","
        << "\"routeIdentityHash\":" << attempt.routeIdentityHash
        << ","
        << "\"routeCandidateCount\":" << attempt.routeCandidateCount
        << ","
        << "\"routeIntervalCount\":" << attempt.routeIntervalCount
        << ","
        << "\"rollbackOwnedBytes\":" << attempt.rollbackOwnedBytes
        << ","
        << "\"candidateOwnedBytes\":" << attempt.candidateOwnedBytes
        << ","
        << "\"descriptorOwnedBytes\":" << attempt.descriptorOwnedBytes
        << ","
        << "\"completedPatchOwnedBytes\":"
        << attempt.completedPatchOwnedBytes << ","
        << "\"assemblyOwnedBytes\":" << attempt.assemblyOwnedBytes
        << ","
        << "\"totalStructuralOwnedBytes\":"
        << attempt.totalStructuralOwnedBytes << ","
        << "\"selectedHalfedges\":[";
    for (std::size_t halfedgeIndex = 0;
         halfedgeIndex < attempt.selectedHalfedges.size(); ++halfedgeIndex) {
      if (halfedgeIndex > 0U) out << ",";
      out << attempt.selectedHalfedges[halfedgeIndex];
    }
    out << "],\"sharedCornerIdentityHashes\":[";
    for (std::size_t hashIndex = 0;
         hashIndex < attempt.sharedCornerIdentityHashes.size(); ++hashIndex) {
      if (hashIndex > 0U) out << ",";
      out << attempt.sharedCornerIdentityHashes[hashIndex];
    }
    out << "],"
        << "\"backend\":\""
        << geometry::pure_quad_completion_backend_name(attempt.backend)
        << "\","
        << "\"fromVariant\":" << attempt.fromVariant << ","
        << "\"toVariant\":" << attempt.toVariant << ","
        << "\"insertedVertices\":" << attempt.insertedVertices
        << ","
        << "\"splitUndirectedEdges\":"
        << attempt.splitUndirectedEdges << ","
        << "\"candidateEvaluation\":"
        << attempt.candidateEvaluation << ","
        << "\"structuralAttempt\":"
        << attempt.structuralAttempt << ","
        << "\"fullRecomputationPass\":"
        << attempt.fullRecomputationPass << ","
        << "\"visitedStateCount\":"
        << attempt.visitedStateCount << ","
        << "\"globalInsertedVerticesBefore\":"
        << attempt.globalInsertedVerticesBefore << ","
        << "\"globalInsertedVerticesAfter\":"
        << attempt.globalInsertedVerticesAfter << ","
        << "\"liveCandidateComplexes\":"
        << attempt.liveCandidateComplexes << ","
        << "\"outcome\":\""
        << geometry::surface_cell_ownership_repair_outcome_name(
               attempt.outcome)
        << "\","
        << "\"completionSucceeded\":"
        << (attempt.completionSucceeded ? "true" : "false") << ","
        << "\"committed\":"
        << (attempt.committed ? "true" : "false") << ","
        << "\"repeatedState\":"
        << (attempt.repeatedState ? "true" : "false") << ","
        << "\"madeProgress\":"
        << (attempt.madeProgress ? "true" : "false") << ","
        << "\"introducedOwnershipClaim\":"
        << (attempt.introducedOwnershipClaim ? "true" : "false") << ","
        << "\"preConflictCount\":" << attempt.preConflictCount << ","
        << "\"postConflictCount\":" << attempt.postConflictCount << ","
        << "\"retainedConflictCount\":"
        << attempt.retainedConflictCount << ","
        << "\"removedConflictCount\":"
        << attempt.removedConflictCount << ","
        << "\"introducedConflictCount\":"
        << attempt.introducedConflictCount << ","
        << "\"preConflictInventoryHash\":"
        << attempt.preConflictInventoryHash << ","
        << "\"postConflictInventoryHash\":"
        << attempt.postConflictInventoryHash << ","
        << "\"reusedPatchCompletions\":"
        << attempt.reusedPatchCompletions << ","
        << "\"recomputedPatchCompletions\":"
        << attempt.recomputedPatchCompletions << ","
        << "\"affectedPatches\":[";
    for (std::size_t patchIndex = 0;
         patchIndex < attempt.affectedPatches.size(); ++patchIndex) {
      if (patchIndex > 0U) out << ",";
      out << attempt.affectedPatches[patchIndex];
    }
    out << "],"
        << "\"failure\":\"" << escape_json(attempt.failure)
        << "\"}";
  }
  out << "],"
      << "\"completionFailure\":\""
      << escape_json(result.surfaceCellContext.completionFailure) << "\","
      << "\"completionDomainIdentityAuditAvailable\":"
      << (result.surfaceCellContext.hasCompletionDomainIdentityAudit
              ? "true"
              : "false")
      << ","
      << "\"completionDomainIdentityFailure\":\""
      << directional::geometry::surface_cell_domain_identity_failure_name(
             result.surfaceCellContext.completionDomainIdentityAudit.failure)
      << "\","
      << "\"completionDomainIdentityCell\":"
      << result.surfaceCellContext.completionDomainIdentityAudit.cellId
      << ","
      << "\"completionDomainIdentityHalfedge\":"
      << result.surfaceCellContext.completionDomainIdentityAudit.halfedgeId
      << ","
      << "\"completionDomainIdentityNode\":"
      << result.surfaceCellContext.completionDomainIdentityAudit.nodeId
      << ","
      << "\"completionDomainIdentitySourceFace\":"
      << result.surfaceCellContext.completionDomainIdentityAudit.sourceFace
      << ","
      << "\"completionDomainIdentityComponent\":"
      << result.surfaceCellContext.completionDomainIdentityAudit.sourceComponent
      << ","
      << "\"completionDomainIdentitySheet\":"
      << result.surfaceCellContext.completionDomainIdentityAudit.sourceSheet
      << ","
      << "\"completionOwnershipRejectionAvailable\":"
      << (result.surfaceCellContext.firstCompletionOwnershipRejection.active
              ? "true"
              : "false")
      << ",";
  const geometry::PureQuadCompletionOwnershipRejection &ownershipRejection =
      result.surfaceCellContext.firstCompletionOwnershipRejection;
  const char *ownershipSupportKind = "invalid";
  int ownershipSourceVertex = -1;
  std::array<int, 2> ownershipSourceEdge{{-1, -1}};
  if (ownershipRejection.sourceSupport.has_value()) {
    if (const auto *vertex =
            std::get_if<authority::SourceVertexSupport>(
                &ownershipRejection.sourceSupport.value())) {
      ownershipSupportKind = "source-vertex";
      ownershipSourceVertex = static_cast<int>(vertex->vertex.index());
    } else if (const auto *edge =
                   std::get_if<authority::SourceEdgeSupport>(
                       &ownershipRejection.sourceSupport.value())) {
      ownershipSupportKind = "source-edge";
      ownershipSourceEdge = {static_cast<int>(edge->edge.first().index()),
                             static_cast<int>(edge->edge.second().index())};
    } else {
      ownershipSupportKind = "face-interior";
    }
  }
  out << "\"completionOwnershipFailure\":\""
      << escape_json(ownershipRejection.failure) << "\","
      << "\"completionOwnershipSourcePatch\":"
      << ownershipRejection.sourcePatch << ","
      << "\"completionOwnershipLocalVertex\":"
      << ownershipRejection.localVertex << ","
      << "\"completionOwnershipBoundaryVertex\":"
      << (ownershipRejection.boundaryVertex ? "true" : "false") << ","
      << "\"completionOwnershipBackend\":\""
      << geometry::pure_quad_completion_backend_name(ownershipRejection.backend)
      << "\","
      << "\"completionOwnershipVariant\":"
      << ownershipRejection.completionVariant << ","
      << "\"completionOwnershipStoredFace\":"
      << ownershipRejection.storedFace << ","
      << "\"completionOwnershipBarycentric\":["
      << ownershipRejection.barycentric(0) << ","
      << ownershipRejection.barycentric(1) << ","
      << ownershipRejection.barycentric(2) << "],"
      << "\"completionOwnershipEntityKind\":\""
      << ownershipSupportKind << "\","
      << "\"completionOwnershipSourceVertex\":"
      << ownershipSourceVertex << ","
      << "\"completionOwnershipSourceEdge\":["
      << ownershipSourceEdge[0] << "," << ownershipSourceEdge[1] << "],"
      << "\"completionOwnershipComponent\":"
      << source_component_for_face(ownershipRejection.storedFace) << ","
      << "\"completionOwnershipSheet\":"
      << source_sheet_for_face(ownershipRejection.storedFace) << ","
      << "\"completionOwnershipCandidateFaces\":[";
  for (std::size_t faceIndex = 0;
       faceIndex < ownershipRejection.candidateSupportedFaces.size();
       ++faceIndex) {
    if (faceIndex > 0U) out << ",";
    out << ownershipRejection.candidateSupportedFaces[faceIndex].index();
  }
  out << "],\"completionOwnershipPatchFaces\":[";
  for (std::size_t faceIndex = 0;
       faceIndex < ownershipRejection.patchSourceFaces.size(); ++faceIndex) {
    if (faceIndex > 0U) out << ",";
    out << ownershipRejection.patchSourceFaces[faceIndex];
  }
  const geometry::PureQuadEmbeddingFailure &embeddingFailure =
      result.surfaceCellContext.firstCompletionEmbeddingFailure;
  const auto embeddingScope = source_scope_for_faces(embeddingFailure.sourceFaces);
  out << "],"
      << "\"completionEmbeddingFailureAvailable\":"
      << (embeddingFailure.active ? "true" : "false") << ","
      << "\"completionEmbeddingFailureKind\":\""
      << geometry::pure_quad_embedding_failure_name(embeddingFailure.kind)
      << "\","
      << "\"completionEmbeddingSourcePatch\":"
      << embeddingFailure.sourcePatch << ","
      << "\"completionEmbeddingBackend\":\""
      << geometry::pure_quad_completion_backend_name(embeddingFailure.backend)
      << "\","
      << "\"completionEmbeddingVariant\":"
      << embeddingFailure.completionVariant << ","
      << "\"completionEmbeddingLocalQuad\":"
      << embeddingFailure.localQuad << ","
      << "\"completionEmbeddingVertices\":["
      << embeddingFailure.localVertices[0] << ","
      << embeddingFailure.localVertices[1] << ","
      << embeddingFailure.localVertices[2] << ","
      << embeddingFailure.localVertices[3] << "],"
      << "\"completionEmbeddingComponent\":"
      << embeddingScope.first << ","
      << "\"completionEmbeddingSheet\":"
      << embeddingScope.second << ","
      << "\"completionEmbeddingSourceFaces\":[";
  for (std::size_t faceIndex = 0;
       faceIndex < embeddingFailure.sourceFaces.size(); ++faceIndex) {
    if (faceIndex > 0U) out << ",";
    out << embeddingFailure.sourceFaces[faceIndex];
  }
  out << "],"
      << "\"completionUnresolvedSingularVertexCount\":"
      << result.surfaceCellContext.completionUnresolvedSingularVertices.size()
      << ","
      << "\"completionPatchDescriptorCount\":"
      << result.surfaceCellContext.patchDescriptors.size() << ","
      << "\"completionCompletedPatchCount\":"
      << result.surfaceCellContext.productSnapshots.completedPatches.size() << ","
      << "\"completionOutputLineageValid\":"
      << (result.surfaceCellContext.productSnapshots.outputLineageValidation.valid ? "true"
                                                                : "false")
      << ","
      << "\"completionOutputLineageFailure\":\""
      << escape_json(result.surfaceCellContext.productSnapshots.outputLineageValidation.failure)
      << "\",\"completionRejectedDescriptors\":[";
  using FlowRepEndpointIdentity = std::tuple<int, int, std::uint64_t>;
  std::map<FlowRepEndpointIdentity, int> retainedFlowRepEndpointDegree;
  std::map<int, const geometry::FlowRepArc *> flowRepArcById;
  std::map<int, const geometry::SurfaceArrangementArc *> arrangementArcById;
  std::set<int> retainedFlowRepArcIds;
  for (const geometry::FlowRepArc &arc :
       result.surfaceCellContext.productSnapshots.flowRepArcs) {
    flowRepArcById.emplace(arc.id, &arc);
  }
  for (const geometry::SurfaceArrangementArc &arc :
       result.surfaceCellContext.productSnapshots.embeddedArrangementArcs) {
    arrangementArcById.emplace(arc.id, &arc);
  }
  for (const int arcId :
       result.surfaceCellContext.productSnapshots.flowRepNetwork.retainedArcIds) {
    const auto foundArc = flowRepArcById.find(arcId);
    if (foundArc == flowRepArcById.end()) {
      continue;
    }
    retainedFlowRepArcIds.insert(arcId);
    const geometry::FlowRepArc &arc = *foundArc->second;
    if (arc.startIntrinsicEndpointKeyValid) {
      ++retainedFlowRepEndpointDegree[{
          source_component_for_region(arc.sourceTopologyRegion),
          typed_sheet_index(arc.sourceIsolationSheet),
          arc.startIntrinsicEndpointKey}];
    }
    if (arc.endIntrinsicEndpointKeyValid) {
      ++retainedFlowRepEndpointDegree[{
          source_component_for_region(arc.sourceTopologyRegion),
          typed_sheet_index(arc.sourceIsolationSheet),
          arc.endIntrinsicEndpointKey}];
    }
  }
  const auto retained_endpoint_degree =
      [&](const geometry::FlowRepArc &arc, const bool start) {
        const bool valid = start ? arc.startIntrinsicEndpointKeyValid
                                 : arc.endIntrinsicEndpointKeyValid;
        if (!valid) {
          return -1;
        }
        const std::uint64_t key = start ? arc.startIntrinsicEndpointKey
                                        : arc.endIntrinsicEndpointKey;
        const auto found = retainedFlowRepEndpointDegree.find(
            {source_component_for_region(arc.sourceTopologyRegion),
             typed_sheet_index(arc.sourceIsolationSheet), key});
        return found == retainedFlowRepEndpointDegree.end() ? 0
                                                            : found->second;
      };
  std::vector<int> completionArrangementNodeDegree;
  if (result.surfaceCellContext.hasCompletionComplex) {
    completionArrangementNodeDegree.assign(
        result.surfaceCellContext.completionComplex.nodes.size(), 0);
    for (const geometry::SurfaceArrangementHalfedge &halfedge :
         result.surfaceCellContext.completionComplex.halfedges) {
      if (halfedge.from >= 0 &&
          halfedge.from < static_cast<int>(
                              completionArrangementNodeDegree.size())) {
        ++completionArrangementNodeDegree[
            static_cast<std::size_t>(halfedge.from)];
      }
    }
  }
  const auto arrangement_node_degree = [&](const int node) {
    return node >= 0 &&
                   node < static_cast<int>(completionArrangementNodeDegree.size())
               ? completionArrangementNodeDegree[static_cast<std::size_t>(node)]
               : -1;
  };
  const auto complex_node_degrees_by_key = [&](
      const geometry::SurfaceCellComplex &complex) {
    std::vector<int> nodeDegree(complex.nodes.size(), 0);
    for (const geometry::SurfaceArrangementHalfedge &halfedge :
         complex.halfedges) {
      if (halfedge.from >= 0 &&
          halfedge.from < static_cast<int>(nodeDegree.size())) {
        ++nodeDegree[static_cast<std::size_t>(halfedge.from)];
      }
    }
    std::map<geometry::surface_arrangement_detail::NodeKey, int> byKey;
    const Eigen::MatrixXi &sourceFaces =
        result.surfaceCellContext.sourceMesh.F;
    for (std::size_t nodeIndex = 0; nodeIndex < complex.nodes.size();
         ++nodeIndex) {
      const geometry::SurfaceArrangementNode &node = complex.nodes[nodeIndex];
      const auto add_occurrence = [&](const int sourceFace,
                                      const Eigen::RowVector3d &barycentric) {
        if (sourceFace < 0 || sourceFace >= sourceFaces.rows() ||
            !barycentric.allFinite()) {
          return;
        }
        const auto key = geometry::surface_arrangement_detail::make_node_key(
            sourceFaces, sourceFace,
            geometry::surface_arrangement_detail::bary_to_uv(barycentric));
        byKey[key] = std::max(byKey[key], nodeDegree[nodeIndex]);
      };
      add_occurrence(node.sourceFace, node.barycentric);
      for (const geometry::SurfaceArrangementNodeOccurrence &occurrence :
           node.occurrences) {
        add_occurrence(occurrence.sourceFace, occurrence.barycentric);
      }
    }
    return byKey;
  };
  const auto arrangementDegreesByKey =
      complex_node_degrees_by_key(result.surfaceCellContext.productSnapshots.arrangement);
  const auto simplifiedDegreesByKey =
      complex_node_degrees_by_key(result.surfaceCellContext.simplifiedComplex);
  const auto completionDegreesByKey =
      complex_node_degrees_by_key(result.surfaceCellContext.completionComplex);
  const auto endpoint_complex_degree = [&](
      const geometry::FlowRepArc &arc, const bool start,
      const std::map<geometry::surface_arrangement_detail::NodeKey, int>
          &degrees) {
    const Eigen::MatrixXi &sourceFaces =
        result.surfaceCellContext.sourceMesh.F;
    if (arc.sourceFace < 0 || arc.sourceFace >= sourceFaces.rows()) {
      return -1;
    }
    const Eigen::RowVector3d &barycentric =
        start ? arc.startBarycentric : arc.endBarycentric;
    if (!barycentric.allFinite()) {
      return -1;
    }
    const auto key = geometry::surface_arrangement_detail::make_node_key(
        sourceFaces, arc.sourceFace,
        geometry::surface_arrangement_detail::bary_to_uv(barycentric));
    const auto found = degrees.find(key);
    return found == degrees.end() ? 0 : found->second;
  };
  const auto support_trace_result = [&](const geometry::FlowRepArc &arc)
      -> const geometry::SurfaceTraceResult * {
    if (!result.surfaceCellContext.hasTraceNetwork || arc.supportTraceId < 0) {
      return nullptr;
    }
    const geometry::SurfaceCellNetwork &network =
        result.surfaceCellContext.productSnapshots.traceNetwork;
    const int genericTraceCount = static_cast<int>(4U * network.seeds.size());
    if (arc.supportTraceId < genericTraceCount &&
        arc.supportTraceId < static_cast<int>(network.traces.size())) {
      return &network.traces[static_cast<std::size_t>(arc.supportTraceId)];
    }
    const int separatrixIndex = arc.supportTraceId - genericTraceCount;
    if (separatrixIndex >= 0 &&
        separatrixIndex <
            static_cast<int>(network.singularSeparatrices.size())) {
      return &network.singularSeparatrices
                  [static_cast<std::size_t>(separatrixIndex)]
                      .trace;
    }
    return nullptr;
  };
  bool wroteRejectedDescriptor = false;
  for (const geometry::PatchDescriptor &descriptor :
       result.surfaceCellContext.patchDescriptors) {
    const bool boundedFallbackAdmissible =
        descriptor.feasibility.reason ==
            geometry::PureQuadPatchRejectReason::SideInequality ||
        descriptor.feasibility.reason ==
            geometry::PureQuadPatchRejectReason::HexParity;
    if (descriptor.boundaryCycleValid &&
        (descriptor.feasibility.admissible || boundedFallbackAdmissible)) {
      continue;
    }
    if (wroteRejectedDescriptor) {
      out << ",";
    }
    wroteRejectedDescriptor = true;
    const geometry::SurfaceArrangementCell *cell = nullptr;
    if (result.surfaceCellContext.hasCompletionComplex) {
      const auto foundCell = std::find_if(
          result.surfaceCellContext.completionComplex.cells.begin(),
          result.surfaceCellContext.completionComplex.cells.end(),
          [&](const geometry::SurfaceArrangementCell &candidate) {
            return candidate.id == descriptor.cellId;
          });
      if (foundCell !=
          result.surfaceCellContext.completionComplex.cells.end()) {
        cell = &*foundCell;
      }
    }
    out << "{"
        << "\"cellId\":" << descriptor.cellId << ","
        << "\"boundaryCycleValid\":"
        << (descriptor.boundaryCycleValid ? "true" : "false") << ","
        << "\"admissible\":"
        << (descriptor.feasibility.admissible ? "true" : "false") << ","
        << "\"rejectReason\":"
        << static_cast<int>(descriptor.feasibility.reason) << ","
        << "\"boundaryVertexCount\":"
        << descriptor.patch.boundaryVertices.size() << ","
        << "\"boundaryLoopCount\":"
        << descriptor.patch.boundaryLoopCount << ","
        << "\"diskTopology\":"
        << (descriptor.patch.diskTopology ? "true" : "false") << ","
        << "\"simple\":"
        << (descriptor.patch.simple ? "true" : "false") << ","
        << "\"sideCount\":" << descriptor.sides.size() << ","
        << "\"singularityCount\":"
        << descriptor.patch.singularityCount << ","
        << "\"singularIndexNumerator\":"
        << descriptor.patch.singularIndexNumerator << ","
        << "\"cellClosed\":"
        << (cell != nullptr && cell->closed ? "true" : "false") << ","
        << "\"cellDisk\":"
        << (cell != nullptr && cell->disk ? "true" : "false") << ","
        << "\"cellBoundaryComponentCount\":"
        << (cell != nullptr ? cell->boundaryComponentCount : -1) << ","
        << "\"cellEulerCharacteristic\":"
        << (cell != nullptr ? cell->eulerCharacteristic : -1) << ","
        << "\"cellRejectReason\":"
        << (cell != nullptr ? static_cast<int>(cell->rejectReason) : -1) << ","
        << "\"cellHalfedges\":[";
    if (cell != nullptr) {
      for (std::size_t halfedgeIndex = 0;
           halfedgeIndex < cell->halfedges.size(); ++halfedgeIndex) {
        if (halfedgeIndex > 0) {
          out << ",";
        }
        const int halfedgeId = cell->halfedges[halfedgeIndex];
        const geometry::SurfaceArrangementHalfedge *halfedge =
            halfedgeId >= 0 &&
                    halfedgeId < static_cast<int>(
                                     result.surfaceCellContext
                                         .completionComplex.halfedges.size())
                ? &result.surfaceCellContext.completionComplex.halfedges
                       [static_cast<std::size_t>(halfedgeId)]
                : nullptr;
        out << "{"
            << "\"id\":" << halfedgeId << ","
            << "\"from\":"
            << (halfedge != nullptr ? halfedge->from : -1) << ","
            << "\"to\":"
            << (halfedge != nullptr ? halfedge->to : -1) << ","
            << "\"twin\":"
            << (halfedge != nullptr ? halfedge->twin : -1) << ","
            << "\"sourceArc\":"
            << (halfedge != nullptr ? halfedge->sourceArc : -1) << ","
            << "\"family\":"
            << (halfedge != nullptr ? halfedge->family : -1) << ","
            << "\"hardFeature\":"
            << (halfedge != nullptr && halfedge->hardFeature ? "true"
                                                            : "false")
            << ","
            << "\"layoutSupport\":"
            << (halfedge != nullptr && halfedge->layoutSupport ? "true"
                                                              : "false")
            << ","
            << "\"singularitySupport\":"
            << (halfedge != nullptr && halfedge->singularitySupport
                    ? "true"
                    : "false")
            << ","
            << "\"railId\":"
            << (halfedge != nullptr && halfedge->railId.has_value()
                    ? static_cast<std::int64_t>(halfedge->railId->index())
                    : -1)
            << ","
            << "\"fromDegree\":"
            << arrangement_node_degree(halfedge != nullptr ? halfedge->from
                                                            : -1)
            << ","
            << "\"toDegree\":"
            << arrangement_node_degree(halfedge != nullptr ? halfedge->to
                                                            : -1)
            << ",\"provenance\":[";
        if (halfedge != nullptr) {
          for (std::size_t provenanceIndex = 0;
               provenanceIndex < halfedge->provenance.size();
               ++provenanceIndex) {
            if (provenanceIndex > 0) {
              out << ",";
            }
            const geometry::SurfaceArrangementProvenance &provenance =
                halfedge->provenance[provenanceIndex];
            out << "{"
                << "\"sourceArc\":" << provenance.sourceArc << ","
                << "\"flowRepArc\":" << provenance.provenance << ","
                << "\"sourceFace\":" << provenance.sourceFace << ","
                << "\"family\":" << provenance.family << ","
                << "\"layoutSupport\":"
                << (provenance.layoutSupport ? "true" : "false") << ","
                << "\"singularitySupport\":"
                << (provenance.singularitySupport ? "true" : "false") << ","
                << "\"sourceComponent\":"
                << source_component_for_region(provenance.sourceTopologyRegion) << ","
                << "\"sourceSheet\":"
                << source_sheet_for_face(provenance.sourceFace) << ","
                << "\"sourceT0\":";
            write_json_number(out, provenance.sourceT0);
            out << ",\"sourceT1\":";
            write_json_number(out, provenance.sourceT1);
            out << "}";
          }
        }
        out << "]}";
      }
    }
    out << "],\"sourceArcDetails\":[";
    std::set<int> cellSourceArcIds;
    if (cell != nullptr) {
      for (const int halfedgeId : cell->halfedges) {
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(
                                result.surfaceCellContext.completionComplex
                                    .halfedges.size())) {
          continue;
        }
        const int sourceArc =
            result.surfaceCellContext.completionComplex.halfedges
                [static_cast<std::size_t>(halfedgeId)]
                    .sourceArc;
        if (sourceArc >= 0) {
          cellSourceArcIds.insert(sourceArc);
        }
      }
    }
    bool wroteSourceArc = false;
    for (const int sourceArcId : cellSourceArcIds) {
      const auto foundArrangementArc = arrangementArcById.find(sourceArcId);
      if (foundArrangementArc == arrangementArcById.end()) {
        continue;
      }
      const geometry::SurfaceArrangementArc &arrangementArc =
          *foundArrangementArc->second;
      const auto foundArc = flowRepArcById.find(arrangementArc.provenance);
      if (foundArc == flowRepArcById.end()) {
        continue;
      }
      if (wroteSourceArc) {
        out << ",";
      }
      wroteSourceArc = true;
      const geometry::FlowRepArc &arc = *foundArc->second;
      const geometry::SurfaceTraceResult *supportTrace =
          support_trace_result(arc);
      out << "{"
          << "\"id\":" << sourceArcId << ","
          << "\"flowRepArcId\":" << arc.id << ","
          << "\"retained\":"
          << (retainedFlowRepArcIds.count(arc.id) != 0U ? "true"
                                                       : "false")
          << ","
          << "\"sourceFace\":" << arrangementArc.sourceFace << ","
          << "\"sourceComponent\":"
          << source_component_for_region(arrangementArc.sourceTopologyRegion) << ","
          << "\"sourceSheet\":"
          << source_sheet_for_face(arrangementArc.sourceFace) << ","
          << "\"family\":" << arrangementArc.family << ","
          << "\"layoutSupport\":"
          << (arc.layoutSupport ? "true" : "false") << ","
          << "\"singularitySupport\":"
          << (arc.singularitySupport ? "true" : "false") << ","
          << "\"hardFeatureRail\":"
          << (arc.hardFeatureRail ? "true" : "false") << ","
          << "\"supportTraceId\":" << arc.supportTraceId << ","
          << "\"supportSeedId\":" << arc.supportSeedId << ","
          << "\"supportSegment\":" << arc.supportSegment << ","
          << "\"supportTermination\":"
          << (supportTrace != nullptr
                  ? static_cast<int>(supportTrace->termination)
                  : -1)
          << ","
          << "\"supportTraceSegmentCount\":"
          << (supportTrace != nullptr
                  ? static_cast<int>(supportTrace->segments.size())
                  : -1)
          << ","
          << "\"startEmbeddedAnchor\":"
          << (arc.startEmbeddedAnchor ? "true" : "false") << ","
          << "\"endEmbeddedAnchor\":"
          << (arc.endEmbeddedAnchor ? "true" : "false") << ","
          << "\"startIntrinsicEndpointKeyValid\":"
          << (arc.startIntrinsicEndpointKeyValid ? "true" : "false") << ","
          << "\"endIntrinsicEndpointKeyValid\":"
          << (arc.endIntrinsicEndpointKeyValid ? "true" : "false") << ","
          << "\"startIntrinsicEndpointKey\":"
          << arc.startIntrinsicEndpointKey << ","
          << "\"endIntrinsicEndpointKey\":"
          << arc.endIntrinsicEndpointKey << ","
          << "\"startRetainedDegree\":"
          << retained_endpoint_degree(arc, true) << ","
          << "\"endRetainedDegree\":"
          << retained_endpoint_degree(arc, false) << ","
          << "\"startArrangementDegree\":"
          << endpoint_complex_degree(arc, true, arrangementDegreesByKey) << ","
          << "\"endArrangementDegree\":"
          << endpoint_complex_degree(arc, false, arrangementDegreesByKey) << ","
          << "\"startSimplifiedDegree\":"
          << endpoint_complex_degree(arc, true, simplifiedDegreesByKey) << ","
          << "\"endSimplifiedDegree\":"
          << endpoint_complex_degree(arc, false, simplifiedDegreesByKey) << ","
          << "\"startCompletionDegree\":"
          << endpoint_complex_degree(arc, true, completionDegreesByKey) << ","
          << "\"endCompletionDegree\":"
          << endpoint_complex_degree(arc, false, completionDegreesByKey) << ","
          << "\"startBarycentric\":[";
      write_json_number(out, arc.startBarycentric[0]);
      out << ",";
      write_json_number(out, arc.startBarycentric[1]);
      out << ",";
      write_json_number(out, arc.startBarycentric[2]);
      out << "],\"endBarycentric\":[";
      write_json_number(out, arc.endBarycentric[0]);
      out << ",";
      write_json_number(out, arc.endBarycentric[1]);
      out << ",";
      write_json_number(out, arc.endBarycentric[2]);
      out << "],\"supportTerminalBarycentric\":[";
      if (supportTrace != nullptr && !supportTrace->segments.empty()) {
        const Eigen::RowVector3d &terminal =
            supportTrace->segments.back().endBarycentric;
        write_json_number(out, terminal[0]);
        out << ",";
        write_json_number(out, terminal[1]);
        out << ",";
        write_json_number(out, terminal[2]);
      } else {
        out << "null,null,null";
      }
      out << "]}";
    }
    out << "]}";
  }
  out << "],"
      << "\"componentSplitSeconds\":" << diagnostics.componentSplitSeconds
      << ","
      << "\"componentParallelWallSeconds\":"
      << diagnostics.componentParallelWallSeconds << ","
      << "\"componentMergeSeconds\":" << diagnostics.componentMergeSeconds
      << ","
      << "\"componentCount\":" << diagnostics.componentCount << ","
      << "\"componentThreadsRequested\":"
      << diagnostics.componentThreadsRequested << ","
      << "\"componentThreadsUsed\":" << diagnostics.componentThreadsUsed
      << ","
      << "\"componentPeakConcurrentTasks\":"
      << diagnostics.componentPeakConcurrentTasks << ","
      << "\"failedComponentIndex\":" << diagnostics.failedComponentIndex
      << ","
      << "\"failedComponentMinimumOriginalFace\":"
      << diagnostics.failedComponentMinimumOriginalFace << ","
      << "\"components\":[";
  for (std::size_t componentIndex = 0;
       componentIndex < diagnostics.components.size(); ++componentIndex) {
    const ComponentRemeshDiagnostics &component =
        diagnostics.components[componentIndex];
    if (componentIndex > 0) {
      out << ",";
    }
    out << "{"
        << "\"componentIndex\":" << component.componentIndex << ","
        << "\"minimumOriginalFace\":" << component.minimumOriginalFace << ","
        << "\"inputFaceCount\":" << component.inputFaceCount << ","
        << "\"outputVertexCount\":" << component.outputVertexCount << ","
        << "\"outputFaceCount\":" << component.outputFaceCount << ","
        << "\"success\":" << (component.success ? "true" : "false") << ","
        << "\"terminalFailureCode\":\""
        << escape_json(component.terminalFailureCode) << "\","
        << "\"terminalFailureStage\":\""
        << escape_json(component.terminalFailureStage) << "\","
        << "\"outputOrigin\":\"" << escape_json(component.outputOrigin)
        << "\","
        << "\"wallSeconds\":" << component.wallSeconds << ","
        << "\"integrationSeconds\":" << component.integrationSeconds << ","
        << "\"mesherSeconds\":" << component.mesherSeconds << "}";
  }
  out << "],"
      << "\"surfaceCellFeatureSeconds\":"
      << diagnostics.surfaceCellFeatureSeconds << ","
      << "\"surfaceCellMetricSeconds\":" << diagnostics.surfaceCellMetricSeconds
      << ","
      << "\"surfaceCellReliefSeconds\":" << diagnostics.surfaceCellReliefSeconds
      << ","
      << "\"surfaceCellTracingSeconds\":"
      << diagnostics.surfaceCellTracingSeconds << ","
      << "\"surfaceCellArrangementSeconds\":"
      << diagnostics.surfaceCellArrangementSeconds << ","
      << "\"surfaceCellSimplificationSeconds\":"
      << diagnostics.surfaceCellSimplificationSeconds << ","
      << "\"surfaceCellCompletionSeconds\":"
      << diagnostics.surfaceCellCompletionSeconds << ","
      << "\"surfaceCellOptimizationSeconds\":"
      << diagnostics.surfaceCellOptimizationSeconds << ","
      << "\"surfaceCellValidationSeconds\":"
      << diagnostics.surfaceCellValidationSeconds << ","
      << "\"surfaceCellTracingCurrentOwnedBytes\":"
      << diagnostics.surfaceCellTracingCurrentOwnedBytes << ","
      << "\"surfaceCellTracingPeakOwnedBytes\":"
      << diagnostics.surfaceCellTracingPeakOwnedBytes << ","
      << "\"surfaceCellFlowRepCurrentOwnedBytes\":"
      << diagnostics.surfaceCellFlowRepCurrentOwnedBytes << ","
      << "\"surfaceCellFlowRepPeakOwnedBytes\":"
      << diagnostics.surfaceCellFlowRepPeakOwnedBytes << ","
      << "\"surfaceCellArrangementCurrentOwnedBytes\":"
      << diagnostics.surfaceCellArrangementCurrentOwnedBytes << ","
      << "\"surfaceCellArrangementPeakOwnedBytes\":"
      << diagnostics.surfaceCellArrangementPeakOwnedBytes << ","
      << "\"surfaceCellSimplificationCurrentOwnedBytes\":"
      << diagnostics.surfaceCellSimplificationCurrentOwnedBytes << ","
      << "\"surfaceCellSimplificationPeakOwnedBytes\":"
      << diagnostics.surfaceCellSimplificationPeakOwnedBytes << ","
      << "\"surfaceCellMaxSimultaneousLiveLargeStructures\":"
      << diagnostics.surfaceCellMaxSimultaneousLiveLargeStructures << ","
      << "\"surfaceCellTraceStorageReleasedAfterFlowRep\":"
      << (diagnostics.surfaceCellTraceStorageReleasedAfterFlowRep ? "true"
                                                                  : "false")
      << ","
      << "\"surfaceCellFlowRepSelectionStorageReleasedAfterSelection\":"
      << (diagnostics.surfaceCellFlowRepSelectionStorageReleasedAfterSelection
              ? "true"
              : "false")
      << ","
      << "\"surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement\":"
      << (diagnostics
                  .surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement
              ? "true"
              : "false")
      << ","
      << "\"surfaceCellTracingLogicalPayloadBytes\":"
      << diagnostics.surfaceCellTracingLogicalPayloadBytes << ","
      << "\"surfaceCellTracingRetainedCapacityBytes\":"
      << diagnostics.surfaceCellTracingRetainedCapacityBytes << ","
      << "\"surfaceCellFlowRepLogicalPayloadBytes\":"
      << diagnostics.surfaceCellFlowRepLogicalPayloadBytes << ","
      << "\"surfaceCellFlowRepRetainedCapacityBytes\":"
      << diagnostics.surfaceCellFlowRepRetainedCapacityBytes << ","
      << "\"surfaceCellArrangementLogicalPayloadBytes\":"
      << diagnostics.surfaceCellArrangementLogicalPayloadBytes << ","
      << "\"surfaceCellArrangementRetainedCapacityBytes\":"
      << diagnostics.surfaceCellArrangementRetainedCapacityBytes << ","
      << "\"surfaceCellSimplificationLogicalPayloadBytes\":"
      << diagnostics.surfaceCellSimplificationLogicalPayloadBytes << ","
      << "\"surfaceCellSimplificationRetainedCapacityBytes\":"
      << diagnostics.surfaceCellSimplificationRetainedCapacityBytes << ","
      << "\"surfaceCellCompletionLogicalPayloadBytes\":"
      << diagnostics.surfaceCellCompletionLogicalPayloadBytes << ","
      << "\"surfaceCellCompletionRetainedCapacityBytes\":"
      << diagnostics.surfaceCellCompletionRetainedCapacityBytes << ","
      << "\"surfaceCellEstimatedPeakSimultaneousOwnedBytes\":"
      << diagnostics.surfaceCellEstimatedPeakSimultaneousOwnedBytes << ","
      << "\"surfaceCellMemoryOwnershipTimeline\":[";
  for (std::size_t eventIndex = 0;
       eventIndex < diagnostics.surfaceCellMemoryOwnershipTimeline.size();
       ++eventIndex) {
    if (eventIndex > 0U) out << ",";
    const SurfaceCellMemoryOwnershipEvent &event =
        diagnostics.surfaceCellMemoryOwnershipTimeline[eventIndex];
    out << "{\"stage\":\"" << escape_json(event.stage)
        << "\",\"action\":\"" << escape_json(event.action)
        << "\",\"logicalPayloadBytes\":" << event.logicalPayloadBytes
        << ",\"retainedCapacityBytes\":" << event.retainedCapacityBytes
        << ",\"simultaneousOwnedBytes\":" << event.simultaneousOwnedBytes
        << "}";
  }
  out << "],"
      << "\"surfaceCellCompletionParityScopeFailureAvailable\":"
      << (diagnostics.surfaceCellCompletionParityScopeFailureAvailable
              ? "true"
              : "false")
      << ",\"surfaceCellCompletionParityOriginalCell\":"
      << diagnostics.surfaceCellCompletionParityOriginalCell
      << ",\"surfaceCellCompletionParityReplacementCell\":"
      << diagnostics.surfaceCellCompletionParityReplacementCell
      << ",\"surfaceCellCompletionParityHalfedge\":"
      << diagnostics.surfaceCellCompletionParityHalfedge
      << ",\"surfaceCellCompletionParityTwin\":"
      << diagnostics.surfaceCellCompletionParityTwin
      << ",\"surfaceCellCompletionParitySelectedComponent\":"
      << diagnostics.surfaceCellCompletionParitySelectedComponent
      << ",\"surfaceCellCompletionParitySelectedSheet\":"
      << diagnostics.surfaceCellCompletionParitySelectedSheet
      << ",\"surfaceCellCompletionParityAvailableComponents\":[";
  for (std::size_t componentIndex = 0;
       componentIndex <
       diagnostics.surfaceCellCompletionParityAvailableComponents.size();
       ++componentIndex) {
    if (componentIndex > 0U) out << ",";
    out << diagnostics.surfaceCellCompletionParityAvailableComponents[
        componentIndex];
  }
  out << "],\"surfaceCellCompletionParityAvailableSheets\":[";
  for (std::size_t sheetIndex = 0;
       sheetIndex < diagnostics.surfaceCellCompletionParityAvailableSheets.size();
       ++sheetIndex) {
    if (sheetIndex > 0U) out << ",";
    out << diagnostics.surfaceCellCompletionParityAvailableSheets[sheetIndex];
  }
  out << "],\"surfaceCellCompletionParityMutationPhase\":\""
      << escape_json(diagnostics.surfaceCellCompletionParityMutationPhase)
      << "\","
      << "\"surfaceCellAuthoritativeProducerDisposition\":\""
      << escape_json(diagnostics.surfaceCellAuthoritativeProducerDisposition)
      << "\","
      << "\"surfaceCellTopologyRegionCount\":"
      << diagnostics.surfaceCellTopologyRegionCount << ","
      << "\"surfaceCellInternalIsolationSeamCount\":"
      << diagnostics.surfaceCellInternalIsolationSeamCount << ","
      << "\"surfaceCellConsumedTopologyRegionCount\":"
      << diagnostics.surfaceCellConsumedTopologyRegionCount << ","
      << "\"surfaceCellConsumedInternalIsolationSeamCount\":"
      << diagnostics.surfaceCellConsumedInternalIsolationSeamCount << ","
      << "\"surfaceCellConsumedPeriodicHolonomyCount\":"
      << diagnostics.surfaceCellConsumedPeriodicHolonomyCount << ","
      << "\"surfaceCellMaterializedConnectedComponentCount\":"
      << diagnostics.surfaceCellMaterializedConnectedComponentCount << ","
      << "\"surfaceCellMaterializedBoundaryLoopCount\":"
      << diagnostics.surfaceCellMaterializedBoundaryLoopCount << ","
      << "\"surfaceCellMaterializedEulerCharacteristic\":"
      << diagnostics.surfaceCellMaterializedEulerCharacteristic << ","
      << "\"surfaceCellTopologyRegionHashes\":[";
  for (std::size_t regionIndex = 0;
       regionIndex < diagnostics.surfaceCellTopologyRegionHashes.size();
       ++regionIndex) {
    if (regionIndex > 0U) out << ",";
    out << diagnostics.surfaceCellTopologyRegionHashes[regionIndex];
  }
  out << "],\"surfaceCellTopologyRegionEulerCharacteristics\":[";
  for (std::size_t regionIndex = 0;
       regionIndex < diagnostics.surfaceCellTopologyRegionEulerCharacteristics.size();
       ++regionIndex) {
    if (regionIndex > 0U) out << ",";
    out << diagnostics.surfaceCellTopologyRegionEulerCharacteristics[regionIndex];
  }
  out << "],\"surfaceCellTopologyRegionBoundaryLoopCounts\":[";
  for (std::size_t regionIndex = 0;
       regionIndex < diagnostics.surfaceCellTopologyRegionBoundaryLoopCounts.size();
       ++regionIndex) {
    if (regionIndex > 0U) out << ",";
    out << diagnostics.surfaceCellTopologyRegionBoundaryLoopCounts[regionIndex];
  }
  out << "],\"surfaceCellTopologyRegionIsolationSheetCounts\":[";
  for (std::size_t regionIndex = 0;
       regionIndex < diagnostics.surfaceCellTopologyRegionIsolationSheetCounts.size();
       ++regionIndex) {
    if (regionIndex > 0U) out << ",";
    out << diagnostics.surfaceCellTopologyRegionIsolationSheetCounts[regionIndex];
  }
  out << "],"
      << "\"surfaceCellBoundedDiskBoundaryPhaseCount\":"
      << diagnostics.surfaceCellBoundedDiskBoundaryPhaseCount << ","
      << "\"surfaceCellBoundedDiskBoundaryRunCount\":"
      << diagnostics.surfaceCellBoundedDiskBoundaryRunCount << ","
      << "\"surfaceCellPolygonalBoundedDiskBoundaryPhaseCount\":"
      << diagnostics.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount << ","
      << "\"surfaceCellBoundedDiskConstructedChartCount\":"
      << diagnostics.surfaceCellBoundedDiskConstructedChartCount << ","
      << "\"surfaceCellBoundedDiskBoundaryPhaseHashes\":[";
  for (std::size_t phaseIndex = 0;
       phaseIndex < diagnostics.surfaceCellBoundedDiskBoundaryPhaseHashes.size();
       ++phaseIndex) {
    if (phaseIndex > 0U) out << ",";
    out << diagnostics.surfaceCellBoundedDiskBoundaryPhaseHashes[phaseIndex];
  }
  out << "],"
      << "\"surfaceCellPeriodicHolonomyRelationCount\":"
      << diagnostics.surfaceCellPeriodicHolonomies.size() << ","
      << "\"surfaceCellPeriodicHolonomyAvailable\":"
      << (diagnostics.surfaceCellPeriodicHolonomyAvailable ? "true" : "false") << ","
      << "\"surfaceCellPeriodicHolonomyQuarterTurnRotation\":"
      << diagnostics.surfaceCellPeriodicHolonomyQuarterTurnRotation << ","
      << "\"surfaceCellPeriodicHolonomyTranslationU\":"
      << diagnostics.surfaceCellPeriodicHolonomyTranslationU << ","
      << "\"surfaceCellPeriodicHolonomyTranslationV\":"
      << diagnostics.surfaceCellPeriodicHolonomyTranslationV << ","
      << "\"surfaceCellPeriodicHolonomyRouteEdgeCount\":"
      << diagnostics.surfaceCellPeriodicHolonomyRouteEdgeCount << ","
      << "\"surfaceCellPeriodicCutEdgeCount\":"
      << diagnostics.surfaceCellPeriodicCutEdgeCount << ","
      << "\"surfaceCellFirstInvalidProducerStage\":\""
      << escape_json(diagnostics.surfaceCellFirstInvalidProducerStage)
      << "\","
      << "\"surfaceCellFirstInvalidProducerReason\":\""
      << escape_json(diagnostics.surfaceCellFirstInvalidProducerReason)
      << "\","
      << "\"surfaceCellFirstInvalidProducerCell\":"
      << diagnostics.surfaceCellFirstInvalidProducerCell << ","
      << "\"surfaceCellFirstInvalidProducerHalfedge\":"
      << diagnostics.surfaceCellFirstInvalidProducerHalfedge << ","
      << "\"surfaceCellFirstInvalidProducerTwin\":"
      << diagnostics.surfaceCellFirstInvalidProducerTwin << ","
      << "\"surfaceCellFirstInvalidProducerNode\":"
      << diagnostics.surfaceCellFirstInvalidProducerNode << ","
      << "\"surfaceCellFirstInvalidProducerFace\":"
      << diagnostics.surfaceCellFirstInvalidProducerFace << ","
      << "\"surfaceCellFirstInvalidProducerVertex\":"
      << diagnostics.surfaceCellFirstInvalidProducerVertex << ","
      << "\"surfaceCellFirstInvalidProducerEdgeFirst\":"
      << diagnostics.surfaceCellFirstInvalidProducerEdgeFirst << ","
      << "\"surfaceCellFirstInvalidProducerEdgeSecond\":"
      << diagnostics.surfaceCellFirstInvalidProducerEdgeSecond << ","
      << "\"surfaceCellValidationFailures\":"
      << diagnostics.surfaceCellValidationFailures << ","
      << "\"surfaceCellProvenanceVertexCount\":"
      << diagnostics.surfaceCellProvenanceVertexCount << ","
      << "\"surfaceCellFeatureCount\":"
      << diagnostics.surfaceCellFeatureCount << ","
      << "\"surfaceCellMetricSampleCount\":"
      << diagnostics.surfaceCellMetricSampleCount << ","
      << "\"surfaceCellReliefPatchCount\":"
      << diagnostics.surfaceCellReliefPatchCount << ","
      << "\"surfaceCellTraceSegmentCount\":"
      << diagnostics.surfaceCellTraceSegmentCount << ","
      << "\"surfaceCellArrangementCellCount\":"
      << diagnostics.surfaceCellArrangementCellCount << ","
      << "\"surfaceCellSimplifiedCellCount\":"
      << diagnostics.surfaceCellSimplifiedCellCount << ","
      << "\"surfaceCellCompletedQuadCount\":"
      << diagnostics.surfaceCellCompletedQuadCount << ","
      << "\"surfaceCellOptimizationIterationCount\":"
      << diagnostics.surfaceCellOptimizationIterationCount << ","
      << "\"surfaceCellValidationFailureCountAvailable\":"
      << (diagnostics.surfaceCellValidationFailureCountAvailable ? "true" : "false")
      << ","
      << "\"surfaceCellProvenanceVertexCountAvailable\":"
      << (diagnostics.surfaceCellProvenanceVertexCountAvailable ? "true" : "false")
      << ","
      << "\"surfaceCellFeatureCountAvailable\":"
      << (diagnostics.surfaceCellFeatureCountAvailable ? "true" : "false") << ","
      << "\"surfaceCellMetricSampleCountAvailable\":"
      << (diagnostics.surfaceCellMetricSampleCountAvailable ? "true" : "false")
      << ","
      << "\"surfaceCellReliefCountAvailable\":"
      << (diagnostics.surfaceCellReliefCountAvailable ? "true" : "false") << ","
      << "\"surfaceCellTraceCountAvailable\":"
      << (diagnostics.surfaceCellTraceCountAvailable ? "true" : "false") << ","
      << "\"surfaceCellArrangementCountAvailable\":"
      << (diagnostics.surfaceCellArrangementCountAvailable ? "true" : "false")
      << ","
      << "\"surfaceCellSimplifiedCountAvailable\":"
      << (diagnostics.surfaceCellSimplifiedCountAvailable ? "true" : "false")
      << ","
      << "\"surfaceCellCompletedQuadCountAvailable\":"
      << (diagnostics.surfaceCellCompletedQuadCountAvailable ? "true" : "false")
      << ","
      << "\"surfaceCellOptimizationIterationCountAvailable\":"
      << (diagnostics.surfaceCellOptimizationIterationCountAvailable ? "true" : "false")
      << ","
      << "\"adaptiveFeatureMapSeconds\":"
      << diagnostics.adaptiveFeatureMapSeconds << ","
      << "\"adaptiveFeatureHardEdgeCount\":"
      << diagnostics.adaptiveFeatureHardEdgeCount << ","
      << "\"adaptiveFeatureSoftEdgeCount\":"
      << diagnostics.adaptiveFeatureSoftEdgeCount << ","
      << "\"adaptiveFeatureBoundaryEdgeCount\":"
      << diagnostics.adaptiveFeatureBoundaryEdgeCount << ","
      << "\"adaptiveFeatureNonManifoldEdgeCount\":"
      << diagnostics.adaptiveFeatureNonManifoldEdgeCount << ","
      << "\"adaptiveFeatureCurveCount\":"
      << diagnostics.adaptiveFeatureCurveCount << ","
      << "\"adaptiveFeatureClosedCurveCount\":"
      << diagnostics.adaptiveFeatureClosedCurveCount << ","
      << "\"adaptiveFeatureMaxDensity\":"
      << diagnostics.adaptiveFeatureMaxDensity << ","
      << "\"adaptiveTargetSizeSeconds\":"
      << diagnostics.adaptiveTargetSizeSeconds << ","
      << "\"adaptiveTargetSizeResolvedSurfaceError\":"
      << diagnostics.adaptiveTargetSizeResolvedSurfaceError << ","
      << "\"adaptiveTargetSizeMin\":"
      << diagnostics.adaptiveTargetSizeMin << ","
      << "\"adaptiveTargetSizeMax\":"
      << diagnostics.adaptiveTargetSizeMax << ","
      << "\"adaptiveTargetSizeFiniteVertexCount\":"
      << diagnostics.adaptiveTargetSizeFiniteVertexCount << ","
      << "\"adaptiveTargetSizeNonFiniteVertexCount\":"
      << diagnostics.adaptiveTargetSizeNonFiniteVertexCount << ","
      << "\"preconditioningSeconds\":" << diagnostics.preconditioningSeconds
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
      << "\"preconditioningFlipsAccepted\":"
      << diagnostics.preconditioningFlipsAccepted << ","
      << "\"preconditioningCollapsesAccepted\":"
      << diagnostics.preconditioningCollapsesAccepted << ","
      << "\"preconditioningSplitsAccepted\":"
      << diagnostics.preconditioningSplitsAccepted << ","
      << "\"preconditioningInputTriangleCount\":"
      << diagnostics.preconditioningInputTriangleCount << ","
      << "\"preconditioningOutputTriangleCount\":"
      << diagnostics.preconditioningOutputTriangleCount << ","
      << "\"preconditioningMinAngleBefore\":"
      << diagnostics.preconditioningMinAngleBefore << ","
      << "\"preconditioningMinAngleAfter\":"
      << diagnostics.preconditioningMinAngleAfter << ","
      << "\"preconditioningAspectRatioP95Before\":"
      << diagnostics.preconditioningAspectRatioP95Before << ","
      << "\"preconditioningAspectRatioP95After\":"
      << diagnostics.preconditioningAspectRatioP95After << ","
      << "\"preconditioningAspectRatioP99Before\":"
      << diagnostics.preconditioningAspectRatioP99Before << ","
      << "\"preconditioningAspectRatioP99After\":"
      << diagnostics.preconditioningAspectRatioP99After << ","
      << "\"preconditioningEdgeLengthCvBefore\":"
      << diagnostics.preconditioningEdgeLengthCvBefore << ","
      << "\"preconditioningEdgeLengthCvAfter\":"
      << diagnostics.preconditioningEdgeLengthCvAfter << ","
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
  out << "  \"integrationSolveStrategy\": \""
      << integration_solve_strategy_name(options.solveStrategy) << "\",\n";
  out << "  \"integerBatchStrategy\": \""
      << integer_batch_strategy_name(options.batchStrategy) << "\",\n";
  out << "  \"reduceIntegerTransitionBasis\": "
      << (options.reduceIntegerTransitionBasis ? "true" : "false") << ",\n";
  out << "  \"integrationOnly\": "
      << (options.integrationOnly ? "true" : "false") << ",\n";
  out << "  \"skipConstraintRankReduction\": "
      << (options.skipConstraintRankReduction ? "true" : "false") << ",\n";
  out << "  \"useFunctionSkeletonCleanup\": "
      << (options.useFunctionSkeletonCleanup ? "true" : "false") << ",\n";
  out << "  \"useLocalPatchPrevalidation\": "
      << (options.useLocalPatchPrevalidation ? "true" : "false") << ",\n";
  out << "  \"useLocalPatchQuadrangulationFallback\": "
      << (options.useLocalPatchQuadrangulationFallback ? "true" : "false")
      << ",\n";
  out << "  \"preconditionInputMesh\": "
      << (options.preconditionInputMesh ? "true" : "false") << ",\n";
  out << "  \"parallelizeComponents\": "
      << (options.parallelizeComponents ? "true" : "false") << ",\n";
  out << "  \"useTargetedParametrizationStiffening\": "
      << (options.useTargetedParametrizationStiffening ? "true" : "false")
      << ",\n";
  out << "  \"maxComponentThreads\": " << options.maxComponentThreads << ",\n";
  out << "  \"maximumIntegerBatchSize\": " << options.maximumIntegerBatchSize
      << ",\n";
  out << "  \"parametrizationHeatmapDirectory\": \""
      << escape_json(options.parametrizationHeatmapDirectory.string())
      << "\",\n";
  out << "  \"saveMesherCachePath\": \""
      << escape_json(options.saveMesherCachePath.string()) << "\",\n";
  out << "  \"loadMesherCachePath\": \""
      << escape_json(options.loadMesherCachePath.string()) << "\",\n";
  out << "  \"verbose\": " << (options.verbose ? "true" : "false") << ",\n";
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
    } else if (benchmarkCase.generatedField == "face_edges" ||
               benchmarkCase.generatedField == "constant_xy") {
      out << "\"source\": \"generated\", \"method\": "
          << "\"" << escape_json(benchmarkCase.generatedField)
          << "\", \"normalizeDirections\": true, \"hash\": \"";
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
        << (benchmarkCase.roundSeams ? "true" : "false")
        << ", \"backend\": \""
        << directional::pipeline::remesh_backend_name(benchmarkCase.backend)
        << "\", \"surfaceCellFallback\": \""
        << directional::pipeline::surface_cell_fallback_policy_name(
               benchmarkCase.surfaceCellFallback)
        << "\", \"surfaceCellSkeletonHints\": "
        << (benchmarkCase.surfaceCellSkeletonHints ? "true" : "false")
        << ", \"surfaceCellTraverseUnmarkedSharpBends\": "
        << (benchmarkCase.surfaceCellTraverseUnmarkedSharpBends ? "true"
                                                                : "false")
        << ", \"surfaceCellSheetNormalCompatibility\": "
        << benchmarkCase.surfaceCellSheetNormalCompatibility
        << ", \"surfaceCellCloseSheetRadiusMeanEdges\": "
        << benchmarkCase.surfaceCellCloseSheetRadiusMeanEdges
        << ", \"surfaceCellGeodesicExclusionDepth\": "
        << benchmarkCase.surfaceCellGeodesicExclusionDepth
        << ", \"integrationSolveStrategy\": \""
        << integration_solve_strategy_name(options.solveStrategy)
        << "\", \"integerBatchStrategy\": \""
        << integer_batch_strategy_name(options.batchStrategy)
        << "\", \"reduceIntegerTransitionBasis\": "
        << (options.reduceIntegerTransitionBasis ? "true" : "false")
        << ", \"integrationOnly\": "
        << (options.integrationOnly ? "true" : "false")
        << ", \"skipConstraintRankReduction\": "
        << (options.skipConstraintRankReduction ? "true" : "false")
        << ", \"useFunctionSkeletonCleanup\": "
        << (options.useFunctionSkeletonCleanup ? "true" : "false")
        << ", \"useLocalPatchPrevalidation\": "
        << (options.useLocalPatchPrevalidation ? "true" : "false")
        << ", \"useLocalPatchQuadrangulationFallback\": "
        << (options.useLocalPatchQuadrangulationFallback ? "true" : "false")
        << ", \"preconditionInputMesh\": "
        << (options.preconditionInputMesh ? "true" : "false")
        << ", \"parallelizeComponents\": "
        << (options.parallelizeComponents ? "true" : "false")
        << ", \"useTargetedParametrizationStiffening\": "
        << (options.useTargetedParametrizationStiffening ? "true" : "false")
        << ", \"maxComponentThreads\": " << options.maxComponentThreads
        << ", \"maximumIntegerBatchSize\": "
        << options.maximumIntegerBatchSize
        << "},\n";
    out << "      \"runs\": [\n";
    for (std::size_t runIndex = 0; runIndex < runs.size(); ++runIndex) {
      const RunRecord &run = runs[runIndex];
      out << "        {\"success\": " << (run.success ? "true" : "false")
          << ", \"wallSeconds\": " << run.wallSeconds
          << ", \"peakWorkingSetBytes\": " << run.peakWorkingSetBytes
          << ", \"estimatedPeakSimultaneousOwnedBytes\": "
          << run.result.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes
          << ", \"categorizedPeakOwnedBytes\": "
          << run.result.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes
          << ", \"sameSampleOwnershipMeasurementAvailable\": "
          << (run.sameSampleOwnershipMeasurementAvailable ? "true" : "false")
          << ", \"sameSampleWorkingSetBytes\": "
          << run.sameSampleWorkingSetBytes
          << ", \"sameSampleCategorizedOwnedBytes\": "
          << run.sameSampleCategorizedOwnedBytes
          << ", \"sameSampleSequence\": " << run.sameSampleSequence
          << ", \"peakReconciliationRemainderBytes\": "
          << run.sameSampleReconciliationRemainderBytes
          << ", \"unexplainedPeakWorkingSetBytes\": "
          << run.sameSampleReconciliationRemainderBytes
          << ", \"sameSampleOwnedToWorkingSetRatio\": ";
      write_json_number(
          out,
          run.sameSampleOwnershipMeasurementAvailable &&
                  run.sameSampleWorkingSetBytes > 0U
              ? static_cast<double>(run.sameSampleCategorizedOwnedBytes) /
                    static_cast<double>(run.sameSampleWorkingSetBytes)
              : 0.0);
      out
          << ", \"ownedToPeakWorkingSetRatio\": ";
      write_json_number(
          out,
          run.peakWorkingSetBytes > 0U
              ? static_cast<double>(
                    run.result.surfaceCellContext
                        .estimatedPeakSimultaneousOwnedBytes) /
                    static_cast<double>(run.peakWorkingSetBytes)
              : 0.0);
      out << ", \"reviewImagePath\": \""
          << escape_json(run.reviewImagePath) << "\""
          << ", \"diagnostics\": ";
      write_remesh_diagnostics_json(out, run.result);
      if (!run.success) {
        out << ", \"error\": \"" << escape_json(run.error) << "\"";
      } else {
        out << ", \"quality\": ";
        write_benchmark_quality_json(out, run.quality);
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
      std::cout.flush();
      for (int warmup = 0; warmup < options.warmupRuns; ++warmup) {
        (void)directional::bench::run_case_once(benchmarkCase, options);
      }
      std::vector<directional::bench::RunRecord> runs;
      std::map<std::uint64_t, directional::bench::BenchmarkQuality>
          qualityCache;
      const std::filesystem::path artifactDirectory =
          options.outputPath.parent_path() / "artifacts";
      for (int run = 0; run < options.measuredRuns; ++run) {
        runs.push_back(directional::bench::run_case_once(
            benchmarkCase, options, artifactDirectory, &qualityCache));
        if (runs.back().success &&
            !options.parametrizationHeatmapDirectory.empty()) {
          const std::filesystem::path heatmapPath =
              options.parametrizationHeatmapDirectory /
              (directional::bench::safe_artifact_name(benchmarkCase.name) +
               "_run" + std::to_string(run + 1) + ".param_det_heatmap.ply");
          directional::bench::write_parametrization_heatmap_ply(
              heatmapPath, runs.back().result);
        }
        std::cout << "  run " << (run + 1) << "/" << options.measuredRuns
                  << ": " << (runs.back().success ? "success" : "failed")
                  << " in " << runs.back().wallSeconds << " s\n";
        std::cout.flush();
      }
      results.emplace_back(benchmarkCase, std::move(runs));
    }
    directional::bench::write_results_json(options, results);
    std::cout << "Wrote " << options.outputPath.string() << '\n';
    std::cout.flush();
    return 0;
  } catch (const std::exception &exception) {
    std::cerr << "directional_benchmarks: " << exception.what() << '\n';
    std::cerr.flush();
    return 1;
  } catch (...) {
    std::cerr << "directional_benchmarks: unknown non-std exception\n";
    std::cerr.flush();
    return 2;
  }
}
