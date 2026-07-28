#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

using Clock = std::chrono::steady_clock;
using directional::geometry::FlowRepArc;
using directional::geometry::FlowRepCoverageSample;
using directional::geometry::FlowRepCycleInput;
using directional::geometry::SurfaceCellTracingOptions;
using directional::geometry::SurfaceTraceSeed;

constexpr double kPi = 3.141592653589793238462643383279502884;

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

struct BenchmarkResult {
  std::string fixture;
  int vertices = 0;
  int faces = 0;
  double traceSeconds = 0.0;
  double flowRepSeconds = 0.0;
  int attemptedCells = 0;
  int acceptedCells = 0;
  int rejectedCells = 0;
  int traceSegments = 0;
  int retainedStrands = 0;
  int removedStrands = 0;
  double denseCoverageMax = 0.0;
  double sparseCoverageMax = 0.0;
  int cycleRebuildCount = 0;
};

MeshFixture make_grid(const int n) {
  MeshFixture mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      mesh.vertices.row(y * (n + 1) + x) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  mesh.faces.resize(2 * n * n, 3);
  int face = 0;
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      const int v00 = y * (n + 1) + x;
      const int v10 = v00 + 1;
      const int v01 = (y + 1) * (n + 1) + x;
      const int v11 = v01 + 1;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

MeshFixture make_cylinder(const int segments, const int axialCells) {
  MeshFixture mesh;
  mesh.vertices.resize((axialCells + 1) * segments, 3);
  for (int ring = 0; ring <= axialCells; ++ring) {
    const double z =
        2.0 * static_cast<double>(ring) / static_cast<double>(axialCells);
    for (int segment = 0; segment < segments; ++segment) {
      const double angle =
          2.0 * kPi * static_cast<double>(segment) /
          static_cast<double>(segments);
      mesh.vertices.row(ring * segments + segment)
          << std::cos(angle), std::sin(angle), z;
    }
  }
  mesh.faces.resize(2 * axialCells * segments, 3);
  int face = 0;
  for (int ring = 0; ring < axialCells; ++ring) {
    for (int segment = 0; segment < segments; ++segment) {
      const int next = (segment + 1) % segments;
      const int v00 = ring * segments + segment;
      const int v10 = ring * segments + next;
      const int v01 = (ring + 1) * segments + segment;
      const int v11 = (ring + 1) * segments + next;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

void grid_axes(const MeshFixture &mesh, Eigen::MatrixXd &axisU,
               Eigen::MatrixXd &axisV) {
  axisU.resize(mesh.faces.rows(), 3);
  axisV.resize(mesh.faces.rows(), 3);
  axisU.rowwise() = Eigen::RowVector3d(1.0, 0.0, 0.0);
  axisV.rowwise() = Eigen::RowVector3d(0.0, 1.0, 0.0);
}

void cylinder_axes(const MeshFixture &mesh, Eigen::MatrixXd &axisU,
                   Eigen::MatrixXd &axisV) {
  axisU.resize(mesh.faces.rows(), 3);
  axisV.resize(mesh.faces.rows(), 3);
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    Eigen::RowVector3d center = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      center += mesh.vertices.row(mesh.faces(face, corner));
    }
    center /= 3.0;
    Eigen::RowVector3d tangent(-center.y(), center.x(), 0.0);
    tangent.normalize();
    axisU.row(face) = tangent;
    axisV.row(face) << 0.0, 0.0, 1.0;
  }
}

FlowRepArc cycle_arc(const int id, const int cycleId, const int side,
                     const Eigen::RowVector3d &start,
                     const Eigen::RowVector3d &end) {
  FlowRepArc arc;
  arc.id = id;
  arc.start = start;
  arc.end = end;
  arc.sourceFace = cycleId;
  arc.startBarycentric =
      side == 0   ? Eigen::RowVector3d(1.0, 0.0, 0.0)
      : side == 1 ? Eigen::RowVector3d(0.0, 1.0, 0.0)
      : side == 2 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
                  : Eigen::RowVector3d(0.5, 0.5, 0.0);
  arc.endBarycentric =
      side == 0   ? Eigen::RowVector3d(0.0, 1.0, 0.0)
      : side == 1 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
      : side == 2 ? Eigen::RowVector3d(0.5, 0.5, 0.0)
                  : Eigen::RowVector3d(1.0, 0.0, 0.0);
  arc.sourceComponent = 0;
  arc.sourceSheet = 0;
  arc.family = side % 2;
  arc.strandProvenance = cycleId;
  arc.proposalId = cycleId;
  arc.proposalSeedId = cycleId;
  arc.proposalSide = side;
  arc.proposalBoundarySegment = 0;
  return arc;
}

void build_cycles(const int count, std::vector<FlowRepArc> &arcs,
                  std::vector<FlowRepCoverageSample> &samples,
                  std::vector<FlowRepCycleInput> &cycles) {
  arcs.reserve(4 * count);
  samples.reserve(4 * count);
  cycles.reserve(count);
  for (int cycleId = 0; cycleId < count; ++cycleId) {
    const double x = 2.0 * static_cast<double>(cycleId);
    const std::array<Eigen::RowVector3d, 4> points = {
        Eigen::RowVector3d(x, 0.0, 0.0),
        Eigen::RowVector3d(x + 1.0, 0.0, 0.0),
        Eigen::RowVector3d(x + 1.0, 1.0, 0.0),
        Eigen::RowVector3d(x, 1.0, 0.0)};
    FlowRepCycleInput cycle;
    cycle.id = cycleId;
    cycle.proposalId = cycleId;
    cycle.targetSize = 1.0;
    cycle.sideCounts = {1, 1, 1, 1};
    for (int side = 0; side < 4; ++side) {
      const int id = static_cast<int>(arcs.size());
      arcs.push_back(cycle_arc(id, cycleId, side, points[side],
                               points[(side + 1) % 4]));
      FlowRepCoverageSample sample;
      sample.position = 0.5 * (arcs.back().start + arcs.back().end);
      sample.sourceFace = arcs.back().sourceFace;
      sample.barycentric =
          0.5 * (arcs.back().startBarycentric +
                 arcs.back().endBarycentric);
      sample.sourceComponent = 0;
      sample.sourceSheet = 0;
      sample.targetSize = 1.0;
      sample.sourceArcId = id;
      samples.push_back(sample);
      cycle.sideArcIds.push_back({id});
      cycle.boundaryArcIds.push_back(id);
    }
    for (int sample = 0; sample < 8; ++sample) {
      cycle.normals.emplace_back(0.0, 0.0, 1.0);
      cycle.boundaryNormalA.emplace_back(0.0, 0.0, 1.0);
      cycle.boundaryNormalB.emplace_back(0.0, 0.0, 1.0);
      cycle.distanceA.push_back(1.0);
      cycle.distanceB.push_back(1.0);
      cycle.surfaceDistances.push_back(0.01);
    }
    cycles.push_back(std::move(cycle));
  }
}

BenchmarkResult run_fixture(const std::string &name, const MeshFixture &mesh,
                            const Eigen::MatrixXd &axisU,
                            const Eigen::MatrixXd &axisV,
                            const int seedCount, const double targetSize,
                            const int cycleCount) {
  BenchmarkResult result;
  result.fixture = name;
  result.vertices = static_cast<int>(mesh.vertices.rows());
  result.faces = static_cast<int>(mesh.faces.rows());

  SurfaceCellTracingOptions options;
  options.defaultTargetSize = targetSize;
  options.maxTraceLength = 16.0;
  options.maxTraceSegments = 4096;
  options.closureToleranceFactor = 0.35;
  options.minimumCellSideFactor = 0.05;
  options.maximumCellSideFactor = 8.0;
  const Eigen::VectorXd size =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), targetSize);

  const auto traceStart = Clock::now();
  for (int seedIndex = 0; seedIndex < seedCount; ++seedIndex) {
    SurfaceTraceSeed seed;
    seed.id = seedIndex;
    seed.point.face =
        (seedIndex * std::max(1, result.faces / seedCount)) % result.faces;
    seed.point.barycentric << 0.23, 0.31, 0.46;

    const auto trace = directional::geometry::trace_surface_field(
        mesh.vertices, mesh.faces, axisU, axisV, seed, 0, 1, options);
    result.traceSegments += static_cast<int>(trace.segments.size());

    const auto proposal = directional::geometry::make_surface_cell_proposal(
        mesh.vertices, mesh.faces, axisU, axisV, size, seed, options);
    ++result.attemptedCells;
    if (proposal.accepted) {
      ++result.acceptedCells;
    } else {
      ++result.rejectedCells;
    }
  }
  result.traceSeconds =
      std::chrono::duration<double>(Clock::now() - traceStart).count();

  std::vector<FlowRepArc> arcs;
  std::vector<FlowRepCoverageSample> samples;
  std::vector<FlowRepCycleInput> cycles;
  build_cycles(cycleCount, arcs, samples, cycles);
  const auto flowStart = Clock::now();
  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, cycles);
  result.flowRepSeconds =
      std::chrono::duration<double>(Clock::now() - flowStart).count();
  if (!network.selectionSucceeded) {
    throw std::runtime_error("FlowRep benchmark selection failed.");
  }
  result.retainedStrands = network.retainedFlowlines;
  result.removedStrands = network.removedFlowlines;
  result.denseCoverageMax = network.denseCoverageMax;
  result.sparseCoverageMax = network.sparseCoverageMax;
  result.cycleRebuildCount = network.cycleRebuilds;
  return result;
}

void print_result(const BenchmarkResult &result, const bool last) {
  std::cout << "    {\n"
            << "      \"fixture\": \"" << result.fixture << "\",\n"
            << "      \"vertices\": " << result.vertices << ",\n"
            << "      \"faces\": " << result.faces << ",\n"
            << "      \"traceSeconds\": " << result.traceSeconds << ",\n"
            << "      \"flowRepSeconds\": " << result.flowRepSeconds << ",\n"
            << "      \"attemptedCells\": " << result.attemptedCells << ",\n"
            << "      \"acceptedCells\": " << result.acceptedCells << ",\n"
            << "      \"rejectedCells\": " << result.rejectedCells << ",\n"
            << "      \"traceSegments\": " << result.traceSegments << ",\n"
            << "      \"retainedStrands\": " << result.retainedStrands << ",\n"
            << "      \"removedStrands\": " << result.removedStrands << ",\n"
            << "      \"denseCoverageMax\": " << result.denseCoverageMax << ",\n"
            << "      \"sparseCoverageMax\": " << result.sparseCoverageMax << ",\n"
            << "      \"cycleRebuildCount\": " << result.cycleRebuildCount
            << "\n"
            << "    }" << (last ? "\n" : ",\n");
}

} // namespace

int main() {
  std::cout << std::setprecision(17);
  std::vector<BenchmarkResult> results;
  for (const int n : {4, 8, 12}) {
    const MeshFixture mesh = make_grid(n);
    Eigen::MatrixXd axisU;
    Eigen::MatrixXd axisV;
    grid_axes(mesh, axisU, axisV);
    results.push_back(run_fixture("planar_grid_" + std::to_string(n), mesh,
                                  axisU, axisV, n, 1.0, n * n));
  }

  const MeshFixture cylinder = make_cylinder(64, 8);
  Eigen::MatrixXd cylinderU;
  Eigen::MatrixXd cylinderV;
  cylinder_axes(cylinder, cylinderU, cylinderV);
  results.push_back(run_fixture("cylinder_64x8", cylinder, cylinderU,
                                cylinderV, 16, 0.2, 64));

  std::cout << "{\n  \"schemaVersion\": 1,\n  \"fixtures\": [\n";
  for (std::size_t index = 0; index < results.size(); ++index) {
    print_result(results[index], index + 1 == results.size());
  }
  std::cout << "  ]\n}\n";
  return 0;
}
