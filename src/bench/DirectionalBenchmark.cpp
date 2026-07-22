#include "BenchmarkCases.h"

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
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
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
  if (result.cutVertices.rows() == 0 || result.cutFaces.rows() == 0 ||
      result.cutFunctions.rows() == 0 || result.cutFunctions.cols() < 2) {
    return;
  }

  const ParametrizationQualityReport report =
      analyze_parametrization_quality(result.cutVertices, result.cutFaces,
                                      result.cutFunctions);

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
      << "element vertex " << result.cutVertices.rows() << "\n"
      << "property float x\n"
      << "property float y\n"
      << "property float z\n"
      << "element face " << result.cutFaces.rows() << "\n"
      << "property list uchar int vertex_indices\n"
      << "property uchar red\n"
      << "property uchar green\n"
      << "property uchar blue\n"
      << "end_header\n";

  out << std::setprecision(9);
  for (Eigen::Index row = 0; row < result.cutVertices.rows(); ++row) {
    out << result.cutVertices(row, 0) << ' ' << result.cutVertices(row, 1)
        << ' ' << result.cutVertices(row, 2) << '\n';
  }

  for (Eigen::Index face = 0; face < result.cutFaces.rows(); ++face) {
    const std::array<unsigned char, 3> color = determinant_heatmap_color(
        report.faces[static_cast<std::size_t>(face)]);
    out << "3 " << result.cutFaces(face, 0) << ' ' << result.cutFaces(face, 1)
        << ' ' << result.cutFaces(face, 2) << ' '
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

RunRecord run_case_once(const BenchmarkCase &benchmarkCase,
                        const Options &benchmarkOptions) {
  RunRecord record;
  const BenchmarkMesh mesh = load_benchmark_mesh(benchmarkCase);
  record.fixtureHash = hash_benchmark_mesh(mesh);
  if (!benchmarkOptions.loadMesherCachePath.empty()) {
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
      record.result.cutVertices = mesherData.cutV;
      record.result.cutFaces = mesherData.cutF;
      record.result.success =
          mesher(meshWhole, mesherData, record.result.vertices,
                 record.result.degrees, record.result.faces);
      record.result.diagnostics.mesher = mesherData.diagnostics;
      record.success = record.result.success;
      if (record.success) {
        record.metrics = compute_structural_metrics(record.result);
      }
    } catch (const std::exception &exception) {
      record.success = false;
      record.error = exception.what();
    } catch (...) {
      record.success = false;
      record.error = "unknown non-std exception";
    }
    record.wallSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now() - start)
            .count() /
        1.0e6;
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
  } catch (...) {
    record.success = false;
    record.error = "unknown non-std exception";
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
                                   const RemeshDiagnostics &diagnostics) {
  out << "{"
      << "\"overallPipelineSeconds\":" << diagnostics.overallPipelineSeconds
      << ","
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
      << "\"surfaceCellValidationFailures\":"
      << diagnostics.surfaceCellValidationFailures << ","
      << "\"surfaceCellProvenanceVertexCount\":"
      << diagnostics.surfaceCellProvenanceVertexCount << ","
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
      std::cout.flush();
      for (int warmup = 0; warmup < options.warmupRuns; ++warmup) {
        (void)directional::bench::run_case_once(benchmarkCase, options);
      }
      std::vector<directional::bench::RunRecord> runs;
      for (int run = 0; run < options.measuredRuns; ++run) {
        runs.push_back(directional::bench::run_case_once(benchmarkCase, options));
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
