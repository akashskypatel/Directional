#include <directional/geometry/SurfaceMeshOptimizer.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

#if defined(_WIN32)
#define NOMINMAX
#include <windows.h>
#include <psapi.h>
#elif defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

namespace {

using Clock = std::chrono::steady_clock;
using directional::geometry::SurfaceOptimizationConstraints;
using directional::geometry::SurfaceOptimizationEnergy;
using directional::geometry::SurfaceOptimizationOptions;
using directional::geometry::SurfaceOptimizationResult;
using directional::geometry::SurfacePoint;

struct Fixture {
  Eigen::MatrixXd sourceVertices;
  Eigen::MatrixXi sourceFaces;
  Eigen::MatrixXd initialVertices;
  Eigen::MatrixXi quads;
  SurfaceOptimizationConstraints constraints;
  SurfaceOptimizationOptions options;
};

struct RunResult {
  double optimizationSeconds = 0.0;
  double validationSeconds = 0.0;
  double endToEndSeconds = 0.0;
  double validatorOverheadRatio = 0.0;
  bool accepted = false;
  bool strictGeometryChecksEnabled = false;
  std::size_t iterations = 0;
  std::size_t acceptedIterations = 0;
  std::size_t lineSearchTrials = 0;
  std::size_t lineSearchRejections = 0;
  std::size_t projectionConstraintRejections = 0;
  std::size_t orientationRejections = 0;
  std::size_t hardInvariantRejections = 0;
  std::size_t armijoRejections = 0;
  std::size_t projectionQueries = 0;
  SurfaceOptimizationEnergy initialEnergy;
  SurfaceOptimizationEnergy finalEnergy;
};

std::uint64_t peak_working_set_bytes() {
#if defined(_WIN32)
  PROCESS_MEMORY_COUNTERS counters{};
  counters.cb = sizeof(counters);
  if (GetProcessMemoryInfo(GetCurrentProcess(), &counters, sizeof(counters)) == 0) {
    return 0;
  }
  return static_cast<std::uint64_t>(counters.PeakWorkingSetSize);
#elif defined(__APPLE__)
  rusage usage{};
  return getrusage(RUSAGE_SELF, &usage) == 0
             ? static_cast<std::uint64_t>(usage.ru_maxrss)
             : 0;
#elif defined(__unix__)
  rusage usage{};
  return getrusage(RUSAGE_SELF, &usage) == 0
             ? static_cast<std::uint64_t>(usage.ru_maxrss) * 1024ULL
             : 0;
#else
  return 0;
#endif
}

Fixture make_grid_fixture(const int cells = 16) {
  if (cells < 2) {
    throw std::invalid_argument("Milestone F benchmark requires at least two cells.");
  }
  Fixture fixture;
  const int side = cells + 1;
  const int vertexCount = side * side;
  const double h = 1.0 / static_cast<double>(cells);
  fixture.sourceVertices.resize(vertexCount, 3);
  fixture.initialVertices.resize(vertexCount, 3);
  for (int y = 0; y < side; ++y) {
    for (int x = 0; x < side; ++x) {
      const int vertex = y * side + x;
      const double px = static_cast<double>(x) * h;
      const double py = static_cast<double>(y) * h;
      fixture.sourceVertices.row(vertex) << px, py, 0.0;
      fixture.initialVertices.row(vertex) = fixture.sourceVertices.row(vertex);
      if (x > 0 && x < cells && y > 0 && y < cells) {
        const double phase = 0.73 * static_cast<double>(x) +
                             1.19 * static_cast<double>(y);
        fixture.initialVertices(vertex, 0) += 0.02 * h * std::sin(phase);
        fixture.initialVertices(vertex, 1) += 0.02 * h * std::cos(phase);
        fixture.initialVertices(vertex, 2) = 0.01 * h * std::sin(1.7 * phase);
      }
    }
  }

  fixture.quads.resize(cells * cells, 4);
  fixture.sourceFaces.resize(2 * cells * cells, 3);
  int quad = 0;
  int triangle = 0;
  for (int y = 0; y < cells; ++y) {
    for (int x = 0; x < cells; ++x) {
      const int v00 = y * side + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * side + x;
      const int v11 = v01 + 1;
      fixture.quads.row(quad++) << v00, v10, v11, v01;
      fixture.sourceFaces.row(triangle++) << v00, v10, v11;
      fixture.sourceFaces.row(triangle++) << v00, v11, v01;
    }
  }

  auto &constraints = fixture.constraints;
  constraints.sourceVertices = fixture.sourceVertices;
  constraints.sourceFaces = fixture.sourceFaces;
  constraints.sourceNormals =
      Eigen::MatrixXd::Zero(fixture.sourceFaces.rows(), 3);
  constraints.sourceFieldX =
      Eigen::MatrixXd::Zero(fixture.sourceFaces.rows(), 3);
  constraints.sourceFieldY =
      Eigen::MatrixXd::Zero(fixture.sourceFaces.rows(), 3);
  for (int face = 0; face < fixture.sourceFaces.rows(); ++face) {
    constraints.sourceNormals.row(face) << 0.0, 0.0, 1.0;
    constraints.sourceFieldX.row(face) << 1.0, 0.0, 0.0;
    constraints.sourceFieldY.row(face) << 0.0, 1.0, 0.0;
  }
  constraints.sourceFaceComponent.assign(
      static_cast<std::size_t>(fixture.sourceFaces.rows()), 0);
  constraints.sourceFaceSheet.assign(
      static_cast<std::size_t>(fixture.sourceFaces.rows()), 0);
  constraints.localTargetSize = Eigen::VectorXd::Constant(vertexCount, h);

  for (int x = 0; x <= cells; ++x) {
    constraints.fixedVertices.push_back(x);
    constraints.fixedVertices.push_back(cells * side + x);
  }
  for (int y = 1; y < cells; ++y) {
    constraints.fixedVertices.push_back(y * side);
    constraints.fixedVertices.push_back(y * side + cells);
  }
  std::sort(constraints.fixedVertices.begin(), constraints.fixedVertices.end());
  constraints.fixedVertices.erase(
      std::unique(constraints.fixedVertices.begin(), constraints.fixedVertices.end()),
      constraints.fixedVertices.end());

  std::vector<int> boundary;
  for (int x = 0; x <= cells; ++x) {
    boundary.push_back(x);
  }
  for (int y = 1; y <= cells; ++y) {
    boundary.push_back(y * side + cells);
  }
  for (int x = cells - 1; x >= 0; --x) {
    boundary.push_back(cells * side + x);
  }
  for (int y = cells - 1; y >= 1; --y) {
    boundary.push_back(y * side);
  }
  constraints.authoritativeBoundaryLoop = boundary;
  constraints.authoritativeBoundaryLoops = {boundary};
  for (std::size_t index = 0; index < boundary.size(); ++index) {
    constraints.authoritativeBoundaryEdges.insert(
        directional::validation::canonical_edge(
            boundary[index], boundary[(index + 1U) % boundary.size()]));
  }
  constraints.featureRailAuthorityProvided = true;
  constraints.requiredFeatureRailCount = 0;

  directional::geometry::SurfaceProjectionBvh bvh(fixture.sourceVertices,
                                                    fixture.sourceFaces);
  directional::geometry::SurfaceProjectionOptions projectionOptions;
  projectionOptions.faceComponents = &constraints.sourceFaceComponent;
  projectionOptions.faceSheets = &constraints.sourceFaceSheet;
  constraints.vertexProvenance.reserve(static_cast<std::size_t>(vertexCount));
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    constraints.vertexProvenance.push_back(
        bvh.project(fixture.initialVertices.row(vertex).transpose(),
                    projectionOptions));
  }

  fixture.options.targetSize = h;
  fixture.options.maxIterations = 8;
  fixture.options.tolerance = 1.0e-10;
  fixture.options.enforceOptimizerTimeGate = false;
  fixture.options.enforceSourceAuthoritativeHardInvariants = true;
  fixture.options.weights.surface = 0.25;
  fixture.options.weights.normal = 0.0;
  fixture.options.weights.field = 0.25;
  fixture.options.weights.orthogonality = 0.25;
  fixture.options.weights.size = 0.25;
  fixture.options.weights.valenceShape = 0.0;
  fixture.options.weights.feature = 0.0;
  return fixture;
}

RunResult run_once(const Fixture &fixture) {
  RunResult run;
  const auto start = Clock::now();
  const auto optimizationStart = Clock::now();
  const SurfaceOptimizationResult optimization =
      directional::geometry::optimize_projected_surface_mesh(
          fixture.initialVertices, fixture.quads, fixture.constraints,
          fixture.options);
  const auto optimizationEnd = Clock::now();
  run.optimizationSeconds =
      std::chrono::duration<double>(optimizationEnd - optimizationStart).count();

  const auto validationStart = Clock::now();
  auto report = directional::geometry::validate_final_surface_mesh(
      optimization.vertices, optimization.quads, fixture.constraints,
      optimization, fixture.options, run.optimizationSeconds,
      std::numeric_limits<double>::infinity());
  const auto validationEnd = Clock::now();
  run.validationSeconds =
      std::chrono::duration<double>(validationEnd - validationStart).count();
  run.endToEndSeconds =
      std::chrono::duration<double>(validationEnd - start).count();
  run.validatorOverheadRatio =
      run.validationSeconds / std::max(1.0e-12, run.endToEndSeconds);

  report.optimizerTimeWithinGate =
      run.optimizationSeconds <= fixture.options.maxOptimizerTimeRatio *
                                     std::max(1.0e-12, run.endToEndSeconds);
  run.accepted = report.accepted;
  run.strictGeometryChecksEnabled =
      report.strictValidationUsed && report.provenanceValidationUsed &&
      report.sourceAuthoritativeValidationUsed && report.spatialAccelerationUsed &&
      report.authoritativeBoundaryUsed && report.authoritativeFeatureRailsUsed &&
      report.orderedBoundaryCyclesPassed &&
      report.authoritativeFeatureRailsPassed &&
      report.localSheetCompatibilityPassed;
  run.iterations = optimization.iterations.size();
  run.acceptedIterations = static_cast<std::size_t>(std::count_if(
      optimization.iterations.begin(), optimization.iterations.end(),
      [](const auto &iteration) { return iteration.accepted; }));
  run.lineSearchTrials = optimization.lineSearchTrialCount;
  run.lineSearchRejections = optimization.lineSearchRejectionCount;
  run.projectionConstraintRejections =
      optimization.projectionConstraintRejectionCount;
  run.orientationRejections = optimization.orientationRejectionCount;
  run.hardInvariantRejections = optimization.hardInvariantRejectionCount;
  run.armijoRejections = optimization.armijoRejectionCount;
  run.projectionQueries = optimization.projectionQueryCount;
  run.initialEnergy = optimization.initialEnergy;
  run.finalEnergy = optimization.finalEnergy;
  return run;
}

double mean(const std::vector<double> &values) {
  return std::accumulate(values.begin(), values.end(), 0.0) /
         static_cast<double>(values.size());
}

double coefficient_of_variation(const std::vector<double> &values) {
  const double average = mean(values);
  if (average <= 0.0) {
    return 0.0;
  }
  double variance = 0.0;
  for (const double value : values) {
    const double difference = value - average;
    variance += difference * difference;
  }
  variance /= static_cast<double>(values.size());
  return std::sqrt(variance) / average;
}

double percentile(std::vector<double> values, const double fraction) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const double position =
      fraction * static_cast<double>(values.size() - 1U);
  const std::size_t lower = static_cast<std::size_t>(std::floor(position));
  const std::size_t upper = static_cast<std::size_t>(std::ceil(position));
  const double weight = position - static_cast<double>(lower);
  return (1.0 - weight) * values[lower] + weight * values[upper];
}

void print_energy(const SurfaceOptimizationEnergy &energy) {
  std::cout << "{\"surface\":" << energy.surface
            << ",\"normal\":" << energy.normal
            << ",\"field\":" << energy.field
            << ",\"orthogonality\":" << energy.orthogonality
            << ",\"size\":" << energy.size
            << ",\"valenceShape\":" << energy.valenceShape
            << ",\"feature\":" << energy.feature
            << ",\"total\":" << energy.total << "}";
}

} // namespace

int main() {
  try {
    const Fixture fixture = make_grid_fixture();
    (void)run_once(fixture); // Required warm-up.

    std::vector<RunResult> runs;
    double cv = std::numeric_limits<double>::infinity();
    int attempts = 0;
    for (; attempts < 3 && cv > 0.10; ++attempts) {
      runs.clear();
      for (int run = 0; run < 5; ++run) {
        runs.push_back(run_once(fixture));
      }
      std::vector<double> totals;
      totals.reserve(runs.size());
      for (const RunResult &run : runs) {
        totals.push_back(run.endToEndSeconds);
      }
      cv = coefficient_of_variation(totals);
    }

    const bool allAccepted = std::all_of(
        runs.begin(), runs.end(), [](const RunResult &run) { return run.accepted; });
    const bool allStrict = std::all_of(
        runs.begin(), runs.end(),
        [](const RunResult &run) { return run.strictGeometryChecksEnabled; });
    const bool allProgressed = std::all_of(
        runs.begin(), runs.end(), [](const RunResult &run) {
          return run.acceptedIterations > 0U &&
                 std::isfinite(run.initialEnergy.total) &&
                 std::isfinite(run.finalEnergy.total) &&
                 run.finalEnergy.total < run.initialEnergy.total;
        });
    if (!allAccepted || !allStrict || !allProgressed || cv > 0.10) {
      throw std::runtime_error(
          "Milestone F benchmark did not produce stable, strictly validated optimization progress.");
    }

    std::vector<double> optimizationTimes;
    std::vector<double> validationTimes;
    std::vector<double> totalTimes;
    std::vector<double> overheadRatios;
    for (const RunResult &run : runs) {
      optimizationTimes.push_back(run.optimizationSeconds);
      validationTimes.push_back(run.validationSeconds);
      totalTimes.push_back(run.endToEndSeconds);
      overheadRatios.push_back(run.validatorOverheadRatio);
    }

    const double medianOverhead = percentile(overheadRatios, 0.50);
    std::cout << std::setprecision(17);
    std::cout << "{\n"
              << "  \"schemaVersion\": 1,\n"
              << "  \"fixture\": \"planar_grid_16x16\",\n"
              << "  \"warmupRuns\": 1,\n"
              << "  \"measuredRuns\": 5,\n"
              << "  \"measurementAttempts\": " << attempts << ",\n"
              << "  \"coefficientOfVariation\": " << cv << ",\n"
              << "  \"peakWorkingSetBytes\": " << peak_working_set_bytes() << ",\n"
              << "  \"allAccepted\": true,\n"
              << "  \"allStrictGeometryChecksEnabled\": true,\n"
              << "  \"allOptimizationProgressed\": true,\n"
              << "  \"validatorOverheadTarget\": 0.05,\n"
              << "  \"validatorOverheadMedian\": " << medianOverhead << ",\n"
              << "  \"validatorOverheadGatePassed\": "
              << (medianOverhead < 0.05 ? "true" : "false") << ",\n"
              << "  \"productionDisposition\": \"default-off experimental\",\n"
              << "  \"summary\": {\n"
              << "    \"optimizationMedianSeconds\": "
              << percentile(optimizationTimes, 0.50) << ",\n"
              << "    \"validationMedianSeconds\": "
              << percentile(validationTimes, 0.50) << ",\n"
              << "    \"endToEndMedianSeconds\": "
              << percentile(totalTimes, 0.50) << ",\n"
              << "    \"endToEndP90Seconds\": "
              << percentile(totalTimes, 0.90) << ",\n"
              << "    \"endToEndMinSeconds\": "
              << *std::min_element(totalTimes.begin(), totalTimes.end()) << ",\n"
              << "    \"endToEndMaxSeconds\": "
              << *std::max_element(totalTimes.begin(), totalTimes.end()) << "\n"
              << "  },\n"
              << "  \"runs\": [\n";
    for (std::size_t index = 0; index < runs.size(); ++index) {
      const RunResult &run = runs[index];
      std::cout << "    {\"optimizationSeconds\":" << run.optimizationSeconds
                << ",\"validationSeconds\":" << run.validationSeconds
                << ",\"endToEndSeconds\":" << run.endToEndSeconds
                << ",\"validatorOverheadRatio\":"
                << run.validatorOverheadRatio
                << ",\"iterations\":" << run.iterations
                << ",\"acceptedIterations\":" << run.acceptedIterations
                << ",\"lineSearchTrials\":" << run.lineSearchTrials
                << ",\"lineSearchRejections\":" << run.lineSearchRejections
                << ",\"projectionConstraintRejections\":"
                << run.projectionConstraintRejections
                << ",\"orientationRejections\":" << run.orientationRejections
                << ",\"hardInvariantRejections\":"
                << run.hardInvariantRejections
                << ",\"armijoRejections\":" << run.armijoRejections
                << ",\"projectionQueries\":" << run.projectionQueries
                << ",\"initialEnergy\":";
      print_energy(run.initialEnergy);
      std::cout << ",\"finalEnergy\":";
      print_energy(run.finalEnergy);
      std::cout << "}" << (index + 1U == runs.size() ? "\n" : ",\n");
    }
    std::cout << "  ]\n}\n";
    return 0;
  } catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
