#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <vector>

#include <gtest/gtest.h>

namespace {

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshFixture make_grid(const int n) {
  MeshFixture mesh;
  mesh.vertices.resize((n + 1) * (n + 1), 3);
  for (int y = 0; y <= n; ++y) {
    for (int x = 0; x <= n; ++x) {
      const int vertex = y * (n + 1) + x;
      mesh.vertices.row(vertex) << static_cast<double>(x),
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

MeshFixture make_hinge_pair() {
  MeshFixture mesh;
  const double angle = 3.14159265358979323846 / 2.0;
  mesh.vertices.resize(4, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0,
      std::cos(angle), std::sin(angle);
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2, 1, 3, 2;
  return mesh;
}

void constant_axes(const MeshFixture &mesh, Eigen::MatrixXd &x,
                   Eigen::MatrixXd &y) {
  x.resize(mesh.faces.rows(), 3);
  y.resize(mesh.faces.rows(), 3);
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    x.row(face) << 1.0, 0.0, 0.0;
    y.row(face) << 0.0, 1.0, 0.0;
  }
}

std::uint64_t network_hash(const directional::geometry::SurfaceCellNetwork &network) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  mix(static_cast<int>(network.seeds.size()));
  mix(static_cast<int>(network.traces.size()));
  mix(network.stats.attempted);
  mix(network.stats.accepted);
  mix(network.stats.rejectedBarrier);
  mix(network.stats.rejectedClosure);
  mix(network.stats.rejectedDegenerate);
  for (const auto &seed : network.seeds) {
    mix(seed.id);
    mix(seed.point.face);
    mix(static_cast<int>(seed.provenance));
    for (int corner = 0; corner < 3; ++corner) {
      mix(static_cast<std::int64_t>(
          std::llround(seed.point.barycentric[corner] * 1.0e9)));
    }
  }
  for (const auto &trace : network.traces) {
    mix(static_cast<int>(trace.termination));
    mix(static_cast<int>(trace.segments.size()));
    for (const auto &segment : trace.segments) {
      mix(segment.face);
      mix(segment.family);
      mix(segment.sign);
    }
  }
  return hash;
}

double point_segment_distance(const Eigen::RowVector3d &point,
                              const Eigen::RowVector3d &a,
                              const Eigen::RowVector3d &b) {
  const Eigen::RowVector3d ab = b - a;
  const double lengthSquared = ab.squaredNorm();
  if (lengthSquared == 0.0) {
    return (point - a).norm();
  }
  const double t =
      std::clamp((point - a).dot(ab) / lengthSquared, 0.0, 1.0);
  return (point - (a + t * ab)).norm();
}

double distance_to_candidate_network(
    const MeshFixture &mesh,
    const directional::geometry::SurfaceCellNetwork &network,
    const Eigen::RowVector3d &point) {
  double nearest = std::numeric_limits<double>::infinity();
  for (const auto &seed : network.seeds) {
    const Eigen::RowVector3d seedPosition =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces, seed.point);
    nearest = std::min(nearest, (point - seedPosition).norm());
  }
  const auto measure_segment =
      [&](const directional::geometry::SurfaceTraceSegment &segment) {
        const Eigen::RowVector3d a =
            directional::geometry::surface_cell_tracing_detail::point_position(
                mesh.vertices, mesh.faces,
                directional::geometry::SurfaceTracePoint{
                    segment.face, segment.startBarycentric});
        const Eigen::RowVector3d b =
            directional::geometry::surface_cell_tracing_detail::point_position(
                mesh.vertices, mesh.faces,
                directional::geometry::SurfaceTracePoint{
                    segment.face, segment.endBarycentric});
        nearest = std::min(nearest, point_segment_distance(point, a, b));
      };
  for (const auto &trace : network.traces) {
    for (const auto &segment : trace.segments) {
      measure_segment(segment);
    }
  }
  for (const auto &proposal : network.proposals) {
    for (const auto &segment : proposal.sides) {
      measure_segment(segment);
    }
  }
  return nearest;
}

double segment_axis_deviation_degrees(
    const MeshFixture &mesh, const Eigen::MatrixXd &faceAxisX,
    const Eigen::MatrixXd &faceAxisY,
    const directional::geometry::SurfaceTraceSegment &segment) {
  const Eigen::RowVector3d a =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces,
          directional::geometry::SurfaceTracePoint{segment.face,
                                                   segment.startBarycentric});
  const Eigen::RowVector3d b =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces,
          directional::geometry::SurfaceTracePoint{segment.face,
                                                   segment.endBarycentric});
  const Eigen::RowVector3d direction = (b - a).normalized();
  const Eigen::RowVector3d axis =
      segment.family == 0 ? faceAxisX.row(segment.face)
                          : faceAxisY.row(segment.face);
  const double alignment = std::clamp(std::abs(direction.dot(axis.normalized())),
                                      0.0, 1.0);
  return std::acos(alignment) * 180.0 / 3.14159265358979323846;
}

} // namespace

TEST(SurfaceCellTracingPhase14, DeterministicSeedsCoverAdaptiveMetricRadius) {
  const MeshFixture mesh = make_grid(2);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0);

  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 1.0;
  const auto seeds =
      directional::geometry::generate_deterministic_surface_seeds(
          mesh.vertices, mesh.faces, targetSize, options);

  ASSERT_FALSE(seeds.empty());
  for (int vertex = 0; vertex < mesh.vertices.rows(); ++vertex) {
    double nearest = std::numeric_limits<double>::infinity();
    const Eigen::RowVector3d p = mesh.vertices.row(vertex);
    for (const auto &seed : seeds) {
      const Eigen::RowVector3d q =
          directional::geometry::surface_cell_tracing_detail::point_position(
              mesh.vertices, mesh.faces, seed.point);
      nearest = std::min(nearest, (p - q).norm());
    }
    EXPECT_LE(nearest, targetSize[vertex] + 1.0e-12);
  }
}

TEST(SurfaceCellTracingPhase14, PlanarConstantCrossTraceHitsBoundaryExactly) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 0;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Boundary);
  const auto &first = trace.segments.front();
  EXPECT_NEAR(first.startBarycentric.sum(), 1.0, 1.0e-12);
  EXPECT_NEAR(first.endBarycentric.sum(), 1.0, 1.0e-12);
  const Eigen::RowVector3d start =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces,
          directional::geometry::SurfaceTracePoint{first.face,
                                                   first.startBarycentric});
  const Eigen::RowVector3d end =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces,
          directional::geometry::SurfaceTracePoint{first.face,
                                                   first.endBarycentric});
  const Eigen::RowVector3d direction = (end - start).normalized();
  EXPECT_NEAR(direction.dot(Eigen::RowVector3d(1.0, 0.0, 0.0)), 1.0,
              1.0e-12);
}

TEST(SurfaceCellTracingPhase14, QuarterTurnHingeTransportKeepsForwardSign) {
  const MeshFixture mesh = make_hinge_pair();
  Eigen::MatrixXd x(mesh.faces.rows(), 3);
  Eigen::MatrixXd y(mesh.faces.rows(), 3);
  x.row(0) << 1.0, 0.0, 0.0;
  y.row(0) << 0.0, 1.0, 0.0;
  x.row(1) << 0.0, 0.0, 1.0;
  y.row(1) << 0.0, 1.0, 0.0;
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.45, 0.45, 0.10;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  ASSERT_GE(trace.segments.size(), 2U);
  EXPECT_EQ(trace.segments[1].face, 1);
}

TEST(SurfaceCellTracingPhase14, CrossFieldResultMatchingSwapsFamilyAcrossEdge) {
  const MeshFixture mesh = make_grid(1);
  directional::fields::CrossFieldResult crossField;
  crossField.primaryDirections.resize(mesh.faces.rows(), 3);
  crossField.secondaryDirections.resize(mesh.faces.rows(), 3);
  crossField.primaryDirections.row(0) << 1.0, 0.0, 0.0;
  crossField.secondaryDirections.row(0) << 0.0, 1.0, 0.0;
  crossField.primaryDirections.row(1) << 1.0, 0.0, 0.0;
  crossField.secondaryDirections.row(1) << -1.0, 0.0, 0.0;
  crossField.matching = Eigen::VectorXi::Constant(1, 1);
  crossField.effort = Eigen::VectorXd::Constant(1, 0.25);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, crossField, seed, 0, -1, options);

  ASSERT_GE(trace.segments.size(), 2U);
  EXPECT_EQ(trace.segments[0].matching, 1);
  EXPECT_NEAR(trace.segments[0].matchingEffort, 0.25, 1.0e-12);
  EXPECT_EQ(trace.segments[1].face, 1);
  EXPECT_EQ(trace.segments[1].family, 1);
}

TEST(SurfaceCellTracingPhase14, CurvedHingeTraceFieldDeviationWithinGate) {
  const MeshFixture mesh = make_hinge_pair();
  Eigen::MatrixXd x(mesh.faces.rows(), 3);
  Eigen::MatrixXd y(mesh.faces.rows(), 3);
  x.row(0) << 1.0, 0.0, 0.0;
  y.row(0) << 0.0, 1.0, 0.0;
  x.row(1) << 0.0, 0.0, 1.0;
  y.row(1) << 0.0, 1.0, 0.0;
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.45, 0.45, 0.10;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  ASSERT_GE(trace.segments.size(), 2U);
  std::vector<double> deviations;
  for (const auto &segment : trace.segments) {
    deviations.push_back(segment_axis_deviation_degrees(mesh, x, y, segment));
  }
  std::sort(deviations.begin(), deviations.end());
  const double median = deviations[deviations.size() / 2];
  const double p95 =
      deviations[static_cast<std::size_t>(std::floor(
          0.95 * static_cast<double>(deviations.size() - 1)))];
  EXPECT_LE(median, 2.0);
  EXPECT_LE(p95, 5.0);
}

TEST(SurfaceCellTracingPhase14, ExactSourceVertexHitTerminatesAsSingularity) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.5, 0.25, 0.25;
  const Eigen::RowVector3d start =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces, seed.point);
  x.row(0) = (mesh.vertices.row(0) - start).normalized();

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.singularityVertices.push_back(0);
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Singularity);
}

TEST(SurfaceCellTracingPhase14, CaptureRadiusTerminatesOnCompatibleTraceNode) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceTracePoint capture;
  capture.face = 0;
  capture.barycentric << 0.0, 0.5, 0.5;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.captureRadius = 1.0e-9;
  options.capturePoints.push_back(capture);
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Captured);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_NEAR(trace.segments.back().endBarycentric[0], capture.barycentric[0],
              1.0e-12);
  EXPECT_NEAR(trace.segments.back().endBarycentric[1], capture.barycentric[1],
              1.0e-12);
  EXPECT_NEAR(trace.segments.back().endBarycentric[2], capture.barycentric[2],
              1.0e-12);
}

TEST(SurfaceCellTracingPhase14, RepeatedDirectedStateTerminatesCycle) {
  MeshFixture mesh;
  mesh.vertices.resize(3, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2, 0, 2, 1;
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.2, 0.3, 0.5;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.maxTraceSegments = 8;
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::RepeatedState);
}

TEST(SurfaceCellTracingPhase14, HardFeatureTerminatesAndDoesNotCross) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(1, 3));

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.segments.back().face, 0);
}

TEST(SurfaceCellTracingPhase14, CompatibleHardFeatureRailIsFollowed) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 0.75;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(0, 3));

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_NE(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.segments.front().exitEdge, 1);
}

TEST(SurfaceCellTracingPhase14, ProposalStatsAccountForEveryAttempt) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0);
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 1.0;
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.vertices, mesh.faces, x, y, targetSize, options);

  EXPECT_EQ(network.stats.attempted, static_cast<int>(network.proposals.size()));
  EXPECT_EQ(network.stats.attempted,
            network.stats.accepted + network.stats.rejectedBarrier +
                network.stats.rejectedClosure + network.stats.rejectedDegenerate);
}

TEST(SurfaceCellTracingPhase14, CellProposalReportsClosureAndAcceptedSides) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 0.25);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 7;
  seed.point.face = 6;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.25;
  options.maxTraceLength = 1.0;

  const auto proposal = directional::geometry::make_surface_cell_proposal(
      mesh.vertices, mesh.faces, x, y, targetSize, seed, options);

  EXPECT_TRUE(proposal.accepted);
  EXPECT_EQ(proposal.rejection,
            directional::geometry::CellRejectionReason::Accepted);
  EXPECT_NEAR(proposal.closureError, 0.0, 1.0e-12);
  EXPECT_FALSE(proposal.sides.empty());
  for (const auto &path : proposal.boundaryPaths) {
    EXPECT_FALSE(path.empty());
  }

  const Eigen::RowVector3d center =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces, seed.point);
  const std::array<Eigen::RowVector3d, 4> expected{
      center + Eigen::RowVector3d(-0.5 * targetSize[0], -0.5 * targetSize[0],
                                  0.0),
      center + Eigen::RowVector3d(0.5 * targetSize[0], -0.5 * targetSize[0],
                                  0.0),
      center + Eigen::RowVector3d(0.5 * targetSize[0], 0.5 * targetSize[0],
                                  0.0),
      center + Eigen::RowVector3d(-0.5 * targetSize[0], 0.5 * targetSize[0],
                                  0.0)};
  for (int cornerIndex = 0; cornerIndex < 4; ++cornerIndex) {
    const Eigen::RowVector3d actual =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces,
            proposal.corners[static_cast<std::size_t>(cornerIndex)]);
    EXPECT_LE((actual - expected[static_cast<std::size_t>(cornerIndex)]).norm(),
              1.0e-6 * targetSize[0]);
  }
  for (int sideIndex = 0; sideIndex < 4; ++sideIndex) {
    const auto &path =
        proposal.boundaryPaths[static_cast<std::size_t>(sideIndex)];
    ASSERT_FALSE(path.empty());
    const Eigen::RowVector3d start =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces,
            directional::geometry::SurfaceTracePoint{
                path.front().face, path.front().startBarycentric});
    const Eigen::RowVector3d end =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces,
            directional::geometry::SurfaceTracePoint{path.back().face,
                                                     path.back().endBarycentric});
    const Eigen::RowVector3d expectedStart =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces,
            proposal.corners[static_cast<std::size_t>(sideIndex)]);
    const Eigen::RowVector3d expectedEnd =
        directional::geometry::surface_cell_tracing_detail::point_position(
            mesh.vertices, mesh.faces,
            proposal.corners[static_cast<std::size_t>((sideIndex + 1) % 4)]);
    EXPECT_LE((start - expectedStart).norm(), 1.0e-9);
    EXPECT_LE((end - expectedEnd).norm(), 1.0e-9);
  }
}

TEST(SurfaceCellTracingPhase14, CellProposalRejectsDegenerateLoop) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  y = x;
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 0.25);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 8;
  seed.point.face = 6;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.25;
  options.maxTraceLength = 1.0;

  const auto proposal = directional::geometry::make_surface_cell_proposal(
      mesh.vertices, mesh.faces, x, y, targetSize, seed, options);

  EXPECT_FALSE(proposal.accepted);
  EXPECT_EQ(proposal.rejection,
            directional::geometry::CellRejectionReason::Degenerate);
}

TEST(SurfaceCellTracingPhase14, SampledSourceAreaWithinLocalTargetSize) {
  const MeshFixture mesh = make_grid(3);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0);
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 1.0;
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.vertices, mesh.faces, x, y, targetSize, options);

  int covered = 0;
  int sampled = 0;
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      centroid += mesh.vertices.row(mesh.faces(face, corner)) / 3.0;
    }
    ++sampled;
    if (distance_to_candidate_network(mesh, network, centroid) <=
        options.defaultTargetSize + 1.0e-12) {
      ++covered;
    }
  }
  ASSERT_GT(sampled, 0);
  EXPECT_GE(static_cast<double>(covered) / static_cast<double>(sampled), 0.99);
}

TEST(SurfaceCellTracingPhase14, OverlayExposesQualitativeDisplayChannels) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0);
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 1.0;
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.vertices, mesh.faces, x, y, targetSize, options);

  const auto overlay = directional::geometry::make_surface_cell_tracing_overlay(
      mesh.vertices, mesh.faces, x, y, targetSize, network);

  EXPECT_EQ(overlay.crossGlyphStarts.rows(), 2 * mesh.faces.rows());
  EXPECT_EQ(overlay.crossGlyphEnds.rows(), 2 * mesh.faces.rows());
  EXPECT_EQ(overlay.crossGlyphFamily.size(), 2 * mesh.faces.rows());
  EXPECT_EQ(overlay.seedPositions.rows(), static_cast<int>(network.seeds.size()));
  EXPECT_EQ(overlay.seedProvenance.size(), static_cast<int>(network.seeds.size()));
  EXPECT_EQ(overlay.cellClosureError.size(),
            static_cast<int>(network.proposals.size()));
  EXPECT_EQ(overlay.cellRejection.size(),
            static_cast<int>(network.proposals.size()));
  EXPECT_EQ(overlay.traceSegmentStarts.rows(), overlay.traceSegmentEnds.rows());
  EXPECT_EQ(overlay.traceSegmentStarts.rows(), overlay.traceFamily.size());
  EXPECT_EQ(overlay.traceSegmentStarts.rows(), overlay.traceSign.size());
  EXPECT_EQ(overlay.traceSegmentStarts.rows(), overlay.traceTermination.size());
  EXPECT_GT(overlay.traceSegmentStarts.rows(), 0);
}

TEST(SurfaceCellTracingPhase14, TenRunNetworkHashIsIdentical) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0);
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 1.0;
  const auto first = directional::geometry::build_surface_cell_network(
      mesh.vertices, mesh.faces, x, y, targetSize, options);
  const std::uint64_t hash = network_hash(first);
  for (int run = 0; run < 9; ++run) {
    const auto repeated = directional::geometry::build_surface_cell_network(
        mesh.vertices, mesh.faces, x, y, targetSize, options);
    EXPECT_EQ(network_hash(repeated), hash);
  }
}
