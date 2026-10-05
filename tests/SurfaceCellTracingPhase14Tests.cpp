#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <set>
#include <vector>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

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

MeshFixture make_vertex_fan() {
  MeshFixture mesh;
  mesh.vertices.resize(5, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0,
      0.0, 0.0, 0.0, -1.0, 0.0;
  mesh.faces.resize(4, 3);
  mesh.faces << 0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 1;
  return mesh;
}

MeshFixture make_close_parallel_triangles() {
  MeshFixture mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
      0.0, 0.01, 0.0, 1.0, 0.01, 1.0, 0.0, 0.01;
  mesh.faces.resize(2, 3);
  mesh.faces << 0, 1, 2, 3, 5, 4;
  return mesh;
}

MeshFixture make_connected_close_opposing_sheets() {
  MeshFixture mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
                   1.0, 0.0, 0.0,
                   1.0, 0.0, 0.02,
                   0.0, 0.0, 0.02,
                   0.0, 1.0, 0.0,
                   1.0, 1.0, 0.0,
                   1.0, 1.0, 0.02,
                   0.0, 1.0, 0.02;
  mesh.faces.resize(6, 3);
  mesh.faces << 0, 1, 5,
                0, 5, 4,
                1, 2, 6,
                1, 6, 5,
                2, 3, 7,
                2, 7, 6;
  return mesh;
}

MeshFixture make_open_cylinder(const int segments) {
  MeshFixture mesh;
  mesh.vertices.resize(2 * segments, 3);
  constexpr double tau = 6.28318530717958647692;
  for (int segment = 0; segment < segments; ++segment) {
    const double angle = tau * static_cast<double>(segment) / segments;
    for (int row = 0; row < 2; ++row) {
      mesh.vertices.row(row * segments + segment)
          << std::cos(angle), std::sin(angle), static_cast<double>(row);
    }
  }
  mesh.faces.resize(2 * segments, 3);
  int face = 0;
  for (int segment = 0; segment < segments; ++segment) {
    const int next = (segment + 1) % segments;
    const int a = segment;
    const int b = next;
    const int c = segments + segment;
    const int d = segments + next;
    mesh.faces.row(face++) << a, b, d;
    mesh.faces.row(face++) << a, d, c;
  }
  return mesh;
}

MeshFixture make_octahedron_sphere() {
  MeshFixture mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices << 0.0, 0.0, 1.0,
                   0.0, 0.0, -1.0,
                   1.0, 0.0, 0.0,
                   0.0, 1.0, 0.0,
                   -1.0, 0.0, 0.0,
                   0.0, -1.0, 0.0;
  mesh.faces.resize(8, 3);
  mesh.faces << 0, 2, 3,
                0, 3, 4,
                0, 4, 5,
                0, 5, 2,
                1, 3, 2,
                1, 4, 3,
                1, 5, 4,
                1, 2, 5;
  return mesh;
}

MeshFixture make_coarse_curved_strip() {
  const std::array<Eigen::Vector2d, 4> path{
      Eigen::Vector2d(0.0, 0.0), Eigen::Vector2d(1.0, 0.0),
      Eigen::Vector2d(1.7, 0.7), Eigen::Vector2d(1.7, 1.7)};
  MeshFixture mesh;
  mesh.vertices.resize(2 * static_cast<int>(path.size()), 3);
  for (int point = 0; point < static_cast<int>(path.size()); ++point) {
    mesh.vertices.row(point) << path[static_cast<std::size_t>(point)].x(), 0.0,
        path[static_cast<std::size_t>(point)].y();
    mesh.vertices.row(point + static_cast<int>(path.size()))
        << path[static_cast<std::size_t>(point)].x(), 1.0,
        path[static_cast<std::size_t>(point)].y();
  }
  mesh.faces.resize(2 * (static_cast<int>(path.size()) - 1), 3);
  int face = 0;
  for (int point = 0; point + 1 < static_cast<int>(path.size()); ++point) {
    const int a = point;
    const int b = point + 1;
    const int c = point + static_cast<int>(path.size());
    const int d = c + 1;
    mesh.faces.row(face++) << a, b, d;
    mesh.faces.row(face++) << a, d, c;
  }
  return mesh;
}

std::uint64_t source_label_hash(
    const directional::geometry::SourceSurfaceLabels &labels) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const int value) {
    hash ^= static_cast<std::uint64_t>(static_cast<std::uint32_t>(value));
    hash *= 1099511628211ULL;
  };
  for (const int component : labels.componentByFace) {
    mix(component);
  }
  mix(-1);
  for (const int sheet : labels.localSheetByFace) {
    mix(sheet);
  }
  return hash;
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
  mix(network.stats.rejectedSourceSheet);
  mix(network.stats.rejectedFieldMetadata);
  mix(network.stats.rejectedSelfIntersection);
  mix(network.stats.rejectedInverted);
  mix(network.stats.rejectedDuplicateCorner);
  mix(network.stats.rejectedOutOfSize);
  mix(network.stats.rejectedHardRailCrossing);
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
    mix(static_cast<int>(trace.states.size()));
    for (const auto &state : trace.states) {
      mix(state.sourceFace);
      mix(state.entryEdge);
      mix(state.family);
      mix(state.sign);
      for (const std::int64_t barycentric : state.quantizedBarycentric) {
        mix(barycentric);
      }
    }
    mix(static_cast<int>(trace.segments.size()));
    for (const auto &segment : trace.segments) {
      mix(segment.face);
      for (int corner = 0; corner < 3; ++corner) {
        mix(static_cast<std::int64_t>(
            std::llround(segment.startBarycentric[corner] * 1.0e9)));
        mix(static_cast<std::int64_t>(
            std::llround(segment.endBarycentric[corner] * 1.0e9)));
      }
      mix(segment.family);
      mix(segment.sign);
      mix(segment.entryEdge);
      mix(segment.exitEdge);
      mix(segment.matching);
      mix(static_cast<std::int64_t>(
          std::llround(segment.matchingEffort * 1.0e9)));
      mix(segment.railId.has_value()
              ? static_cast<std::int64_t>(segment.railId->index())
              : -1);
      mix(segment.curveId);
      mix(segment.railIntervalIndex);
      mix(segment.railSideSign);
      mix(static_cast<std::int64_t>(std::llround(segment.railT0 * 1.0e9)));
      mix(static_cast<std::int64_t>(std::llround(segment.railT1 * 1.0e9)));
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

directional::geometry::SurfaceCellRailSample rail_sample(
    const MeshFixture &mesh, const int sourceFace, const int sourceEdge,
    const double parameter, const double railParameter,
    const Eigen::RowVector3d &barycentric, const int vertex) {
  directional::geometry::SurfaceCellRailSample sample;
  sample.sourceFace = sourceFace;
  sample.sourceEdge = sourceEdge;
  sample.parameter = parameter;
  sample.railParameter = railParameter;
  sample.barycentric = barycentric;
  sample.position = mesh.vertices.row(vertex);
  return sample;
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

TEST(SurfaceCellTracingPhase14,
     IntrinsicFarthestSamplingKeepsSharedVertexSheetsIndependent) {
  const MeshFixture mesh = make_vertex_fan();
  MeshFixture split;
  split.vertices = mesh.vertices;
  split.faces.resize(2, 3);
  split.faces << 0, 1, 2, 0, 3, 4;
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(split.vertices.rows(), 1.1);

  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 1.1;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(1));
  directional::geometry::SurfaceCellRailSample sample;
  sample.sourceFace = 0;
  sample.barycentric << 1.0, 0.0, 0.0;
  sample.position = split.vertices.row(0);
  rail.samples.push_back(sample);
  options.authoritativeRails.push_back(rail);

  const auto seeds = directional::geometry::generate_deterministic_surface_seeds(
      split.vertices, split.faces, targetSize, options);

  ASSERT_EQ(2U, seeds.size());
  EXPECT_EQ(0, seeds[0].point.face);
  EXPECT_EQ(1, seeds[1].point.face);
  EXPECT_EQ(directional::geometry::SurfaceSeedProvenance::AdaptiveFarthest,
            seeds[1].provenance);
  EXPECT_GT(seeds[1].point.barycentric.minCoeff(), 0.0);
  EXPECT_LT(seeds[1].point.barycentric.maxCoeff(), 1.0);
  const Eigen::RowVector3d adaptivePosition =
      directional::geometry::surface_cell_tracing_detail::point_position(
          split.vertices, split.faces, seeds[1].point);
  EXPECT_LT((adaptivePosition - split.vertices.row(0)).norm(),
            targetSize[0]);
}

TEST(SurfaceCellTracingPhase14,
     TraceStateUsesCurrentFaceLocalEntryEdgeAndBranch) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  ASSERT_GE(trace.segments.size(), 2U);
  ASSERT_GE(trace.states.size(), 2U);
  const auto crossing =
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces));
  const int expectedEntry =
      directional::geometry::surface_cell_tracing_detail::local_edge_for_key(
          mesh.faces, 1, crossing);
  ASSERT_GE(expectedEntry, 0);
  EXPECT_EQ(0, trace.states[0].sourceFace);
  EXPECT_EQ(-1, trace.states[0].entryEdge);
  EXPECT_EQ(1, trace.states[1].sourceFace);
  EXPECT_EQ(expectedEntry, trace.states[1].entryEdge);
  EXPECT_EQ(trace.segments[1].family, trace.states[1].family);
  EXPECT_EQ(trace.segments[1].sign, trace.states[1].sign);
  for (int corner = 0; corner < 3; ++corner) {
    EXPECT_EQ(
        directional::geometry::surface_cell_tracing_detail::
            quantized_barycentric_value(
                trace.segments[1].startBarycentric[corner]),
        trace.states[1]
            .quantizedBarycentric[static_cast<std::size_t>(corner)]);
  }
}

TEST(SurfaceCellTracingPhase14,
     EdgeSeedReorientsMatchedFamilyIntoNeighborFace) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;
  Eigen::MatrixXd x(2, 3);
  Eigen::MatrixXd y(2, 3);
  x.row(0) << 1.0, 0.1, 0.0;
  y.row(0) << -0.1, 1.0, 0.0;
  x.row(1) << 1.0, -1.2, 0.0;
  y.row(1) << 1.2, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    x.row(face).normalize();
    y.row(face).normalize();
  }

  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceVertex0 = 1;
  transition.sourceVertex1 = 2;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = 0;
  transition.effort = 0.4;
  const std::vector<directional::fields::CrossFieldEdgeTransition>
      transitions{transition};

  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.0, 0.5, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 0.1;
  options.maxTraceSegments = 4;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 0};

  const auto trace = directional::geometry::trace_surface_field(
      vertices, faces, x, y, seed, 0, 1, options, nullptr, nullptr,
      &transitions);

  ASSERT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Budget);
  ASSERT_EQ(trace.segments.size(), 1U);
  const auto shared =
      directional::geometry::surface_cell_tracing_detail::edge_key(
          1, 2, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(faces));
  const int entry =
      directional::geometry::surface_cell_tracing_detail::local_edge_for_key(
          faces, 1, shared);
  ASSERT_GE(entry, 0);
  EXPECT_EQ(trace.segments[0].face, 1);
  EXPECT_EQ(trace.segments[0].entryEdge, entry);
  EXPECT_EQ(trace.segments[0].family, 0);
  EXPECT_EQ(trace.segments[0].sign, -1);
  EXPECT_NEAR(trace.segments[0].startBarycentric[entry], 0.0, 1.0e-12);
  EXPECT_GT(trace.segments[0].endBarycentric[entry], 1.0e-12);
}

TEST(SurfaceCellTracingPhase14,
     EdgeSeedFailsClosedWhenMatchedFamilyIsTangentToSharedEdge) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;
  Eigen::MatrixXd x(2, 3);
  Eigen::MatrixXd y(2, 3);
  x.row(0) << 1.0, 0.1, 0.0;
  y.row(0) << -0.1, 1.0, 0.0;
  x.row(1) << 1.0, -1.0, 0.0;
  y.row(1) << 1.0, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    x.row(face).normalize();
    y.row(face).normalize();
  }

  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceVertex0 = 1;
  transition.sourceVertex1 = 2;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = 0;
  transition.effort = 0.4;
  const std::vector<directional::fields::CrossFieldEdgeTransition>
      transitions{transition};

  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.0, 0.5, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 0.1;
  options.maxTraceSegments = 4;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 0};

  const auto trace = directional::geometry::trace_surface_field(
      vertices, faces, x, y, seed, 0, 1, options, nullptr, nullptr,
      &transitions);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Degenerate);
  EXPECT_TRUE(trace.segments.empty());
}

TEST(SurfaceCellTracingPhase14,
     VertexContinuationAppliesMatchingAcrossEveryCrossedEdge) {
  const MeshFixture mesh = make_vertex_fan();
  const double q = std::sqrt(0.5);
  Eigen::MatrixXd x(4, 3);
  Eigen::MatrixXd y(4, 3);
  x.row(0) << -q, -q, 0.0;
  y.row(0) << q, -q, 0.0;
  x.row(1) << q, -q, 0.0;
  y.row(1) << -q, -q, 0.0;
  x.row(2) << q, q, 0.0;
  y.row(2) << -q, q, 0.0;
  x.row(3) << q, -q, 0.0;
  y.row(3) << q, q, 0.0;

  std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
  directional::fields::CrossFieldEdgeTransition first;
  first.sourceVertex0 = 0;
  first.sourceVertex1 = 2;
  first.firstFace = 0;
  first.secondFace = 1;
  first.matching = 1;
  first.effort = 0.2;
  transitions.push_back(first);
  directional::fields::CrossFieldEdgeTransition second;
  second.sourceVertex0 = 0;
  second.sourceVertex1 = 3;
  second.firstFace = 1;
  second.secondFace = 2;
  second.matching = 1;
  second.effort = 0.3;
  transitions.push_back(second);

  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.5, 0.25, 0.25;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.sourceFaceComponents = {0, 0, 0, 0};
  options.sourceFaceSheets = {0, 0, 0, 0};
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 1, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 4, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options, nullptr, nullptr,
      &transitions);

  ASSERT_GE(trace.segments.size(), 2U);
  EXPECT_EQ(2, trace.segments[0].matching);
  EXPECT_NEAR(0.5, trace.segments[0].matchingEffort, 1.0e-12);
  EXPECT_EQ(2, trace.segments[1].face);
  EXPECT_EQ(0, trace.segments[1].family);
  EXPECT_EQ(-1, trace.segments[1].sign);
  ASSERT_GE(trace.states.size(), 2U);
  EXPECT_EQ(2, trace.states[1].sourceFace);
  EXPECT_EQ(-1, trace.states[1].entryEdge);
}

TEST(SurfaceCellTracingPhase14,
     VertexContinuationRanksTurnThenEffortThenStableFaceId) {
  const MeshFixture mesh = make_vertex_fan();
  const double q = std::sqrt(0.5);
  Eigen::MatrixXd x(4, 3);
  Eigen::MatrixXd y(4, 3);
  x.row(0) << -q, -q, 0.0;
  y.row(0) << q, -q, 0.0;
  x.row(1) << -q, q, 0.0;
  y.row(1) << -q, -q, 0.0;
  x.row(2) << q, q, 0.0;
  y.row(2) << -q, q, 0.0;
  x.row(3) << q, -q, 0.0;
  y.row(3) << q, q, 0.0;

  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = {0, 0, 0, 0};
  options.sourceFaceSheets = {0, 0, 0, 0};
  // Bound the candidate wedge with real topology constraints. Local sheet IDs
  // are query/projection charts and must not be abused to remove valid vertex
  // continuation candidates from this matching-effort test.
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 4, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.faces);
  const auto indices = directional::geometry::surface_cell_tracing_detail::
      edge_matching_indices(edgeFaces);

  const auto choose = [&](const double faceOneEffort,
                          const double faceThreeEffort) {
    std::vector<directional::fields::CrossFieldEdgeTransition> transitions;
    directional::fields::CrossFieldEdgeTransition one;
    one.sourceVertex0 = 0;
    one.sourceVertex1 = 2;
    one.firstFace = 0;
    one.secondFace = 1;
    one.matching = 0;
    one.effort = faceOneEffort;
    transitions.push_back(one);
    directional::fields::CrossFieldEdgeTransition three;
    three.sourceVertex0 = 0;
    three.sourceVertex1 = 1;
    three.firstFace = 0;
    three.secondFace = 3;
    three.matching = 0;
    three.effort = faceThreeEffort;
    transitions.push_back(three);
    const auto lookup = directional::geometry::surface_cell_tracing_detail::
        edge_transition_lookup(transitions);
    return directional::geometry::surface_cell_tracing_detail::
        resolve_vertex_continuation(
            mesh.vertices, mesh.faces, x, y, edgeFaces, indices, lookup, 0, 0,
            0, 1, Eigen::RowVector3d(-q, -q, 0.0), options, nullptr, nullptr,
            &transitions);
  };

  const auto lowerEffort = choose(0.5, 0.1);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            lowerEffort.status);
  EXPECT_EQ(3, lowerEffort.face);

  const auto stableFace = choose(0.1, 0.1);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            stableFace.status);
  EXPECT_EQ(1, stableFace.face);

  const auto signedEffort = choose(-0.5, -0.1);
  ASSERT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::Found,
            signedEffort.status);
  EXPECT_EQ(3, signedEffort.face);
  EXPECT_NEAR(0.1, signedEffort.matchingEffort, 1.0e-12);
}

TEST(SurfaceCellTracingPhase14,
     VertexContinuationFailsClosedOnIncompleteMatchingMetadata) {
  const MeshFixture mesh = make_vertex_fan();
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.faces);
  const auto indices = directional::geometry::surface_cell_tracing_detail::
      edge_matching_indices(edgeFaces);

  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceVertex0 = 0;
  transition.sourceVertex1 = 2;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = 0;
  transition.effort = 0.1;
  const std::vector<directional::fields::CrossFieldEdgeTransition> transitions{
      transition};
  const auto lookup = directional::geometry::surface_cell_tracing_detail::
      edge_transition_lookup(transitions);
  const directional::geometry::SurfaceCellTracingOptions options;

  const auto continuation = directional::geometry::
      surface_cell_tracing_detail::resolve_vertex_continuation(
          mesh.vertices, mesh.faces, x, y, edgeFaces, indices, lookup, 0, 0,
          0, 1, Eigen::RowVector3d(-1.0, -1.0, 0.0).normalized(), options,
          nullptr, nullptr, &transitions);

  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                VertexContinuationStatus::FieldMetadata,
            continuation.status);
}

TEST(SurfaceCellTracingPhase14,
     IntrinsicCaptureDoesNotJumpToEuclideanCloseOppositeSheet) {
  const MeshFixture mesh = make_close_parallel_triangles();
  Eigen::MatrixXd x(2, 3);
  Eigen::MatrixXd y(2, 3);
  x.row(0) << 1.0, 0.0, 0.0;
  y.row(0) << 0.0, 1.0, 0.0;
  x.row(1) << 1.0, 0.0, 0.0;
  y.row(1) << 0.0, -1.0, 0.0;

  directional::geometry::SurfaceTracePoint source;
  source.face = 0;
  source.barycentric << 0.0, 0.6, 0.4;
  directional::geometry::SurfaceTracePoint opposite;
  opposite.face = 1;
  opposite.barycentric << 0.0, 0.4, 0.6;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.captureRadius = 0.02;
  options.capturePoints.push_back(opposite);
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};

  const auto barriers = directional::geometry::surface_cell_tracing_detail::
      combined_barrier_edges(options);
  const auto graph = directional::geometry::surface_cell_tracing_detail::
      build_intrinsic_surface_graph(mesh.vertices, mesh.faces, options,
                                    barriers);
  EXPECT_TRUE(std::isinf(
      directional::geometry::surface_cell_tracing_detail::
          intrinsic_same_sheet_distance(graph, mesh.vertices, mesh.faces,
                                         source, opposite)));

  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.4, 0.2, 0.4;
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);
  EXPECT_EQ(directional::geometry::TraceTerminationReason::Boundary,
            trace.termination);
  EXPECT_NE(directional::geometry::TraceTerminationReason::Captured,
            trace.termination);
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
  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceEdge = 0;
  transition.sourceVertex0 = 0;
  transition.sourceVertex1 = 3;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = 1;
  transition.effort = 0.25;
  crossField.edgeTransitions.push_back(transition);
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

TEST(SurfaceCellTracingPhase14,
     SingularitySeedEmitsOutgoingSeparatrixBranch) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 9;
  seed.point.face = 0;
  seed.point.barycentric << 1.0, 0.0, 0.0;
  seed.provenance =
      directional::geometry::SurfaceSeedProvenance::Singularity;

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.singularityVertices.push_back(0);
  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  ASSERT_FALSE(trace.segments.empty());
  EXPECT_NE(trace.termination,
            directional::geometry::TraceTerminationReason::Singularity);
  EXPECT_NEAR(1.0, trace.segments.front().startBarycentric.sum(), 1.0e-12);
  EXPECT_GE(trace.segments.front().startBarycentric.minCoeff(), -1.0e-12);
}

TEST(SurfaceCellTracingPhase14,
     NegativeIndexSingularityEmitsFiveOneRingSeparatrices) {
  MeshFixture mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.141592653589793238462643383279502884;
  for (int ring = 0; ring < 5; ++ring) {
    const double angle = 2.0 * pi * static_cast<double>(ring) / 5.0;
    mesh.vertices.row(ring + 1) << std::cos(angle), std::sin(angle), 0.0;
  }
  mesh.faces.resize(5, 3);
  for (int face = 0; face < 5; ++face) {
    mesh.faces.row(face) << 0, face + 1, (face + 1) % 5 + 1;
  }
  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(5, 3);
  field.secondaryDirections.resize(5, 3);
  for (int face = 0; face < 5; ++face) {
    const double angle =
        2.0 * pi * (static_cast<double>(face) + 0.5) / 5.0;
    field.primaryDirections.row(face) << std::cos(angle), std::sin(angle), 0.0;
    field.secondaryDirections.row(face) << -std::sin(angle), std::cos(angle),
        0.0;
  }
  field.matching.resize(0);
  field.effort.resize(0);

  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 1.0;
  options.maxTraceLength = 10.0;
  options.maxTraceSegments = 16;
  options.singularityVertices = {0};
  options.singularityIndexNumerators = {-1};
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Ones(6);
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.vertices, mesh.faces, field, targetSize, options);

  EXPECT_TRUE(network.singularSeparatrixStats.metadataValid);
  EXPECT_EQ(network.singularSeparatrixStats.singularityCount, 1);
  EXPECT_EQ(network.singularSeparatrixStats.expectedBranches, 5);
  EXPECT_EQ(network.singularSeparatrixStats.enumeratedBranches, 5);
  EXPECT_EQ(network.singularSeparatrixStats.nonemptyBranches, 5);
  EXPECT_EQ(network.singularSeparatrixStats.incompleteSingularities, 0);
  ASSERT_EQ(network.singularSeparatrices.size(), 5U);
  std::set<int> initialFaces;
  for (const auto &separatrix : network.singularSeparatrices) {
    EXPECT_EQ(separatrix.sourceVertex, 0);
    EXPECT_EQ(separatrix.singularityIndexNumerator, -1);
    EXPECT_EQ(separatrix.expectedValence, 5);
    ASSERT_FALSE(separatrix.trace.segments.empty());
    EXPECT_NE(separatrix.trace.termination,
              directional::geometry::TraceTerminationReason::Singularity);
    initialFaces.insert(separatrix.initialFace);
    const auto &start = separatrix.trace.segments.front().startBarycentric;
    EXPECT_NEAR(start.sum(), 1.0, 1.0e-12);
    EXPECT_NEAR(start.maxCoeff(), 1.0, 1.0e-12);
  }
  EXPECT_EQ(initialFaces.size(), 5U);
}

TEST(SurfaceCellTracingPhase14,
     SingularIndexReconcilesFacewiseRayMismatchToRequiredValence) {
  MeshFixture mesh;
  mesh.vertices.resize(6, 3);
  mesh.vertices.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.141592653589793238462643383279502884;
  for (int ring = 0; ring < 5; ++ring) {
    const double angle = 2.0 * pi * static_cast<double>(ring) / 5.0;
    mesh.vertices.row(ring + 1) << std::cos(angle), std::sin(angle), 0.0;
  }
  mesh.faces.resize(5, 3);
  for (int face = 0; face < 5; ++face) {
    mesh.faces.row(face) << 0, face + 1, (face + 1) % 5 + 1;
  }
  directional::fields::CrossFieldResult field;
  field.primaryDirections = Eigen::MatrixXd::Zero(5, 3);
  field.secondaryDirections = Eigen::MatrixXd::Zero(5, 3);
  field.primaryDirections.col(0).setOnes();
  field.secondaryDirections.col(1).setOnes();
  field.matching.resize(0);
  field.effort.resize(0);

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.maxTraceSegments = 16;
  options.singularityVertices = {0};
  options.singularityIndexNumerators = {-1};
  const auto network = directional::geometry::build_surface_cell_network(
      mesh.vertices, mesh.faces, field, Eigen::VectorXd::Ones(6), options);

  EXPECT_TRUE(network.singularSeparatrixStats.metadataValid);
  EXPECT_EQ(network.singularSeparatrixStats.expectedBranches, 5);
  EXPECT_NE(network.singularSeparatrixStats.enumeratedBranches, 5);
  EXPECT_EQ(network.singularSeparatrixStats.reconciledSingularities, 1);
  EXPECT_EQ(network.singularSeparatrixStats.incompleteSingularities, 0);
  EXPECT_EQ(network.singularSeparatrixStats.nonemptyBranches, 5);
  ASSERT_EQ(network.singularSeparatrices.size(), 5U);
  for (const auto &separatrix : network.singularSeparatrices) {
    ASSERT_FALSE(separatrix.trace.segments.empty());
    const auto &prefix = separatrix.trace.segments.front();
    EXPECT_NEAR(prefix.startBarycentric.maxCoeff(), 1.0, 1.0e-12);
    EXPECT_GE(prefix.endBarycentric.minCoeff(), -1.0e-12);
    EXPECT_NEAR(prefix.endBarycentric.sum(), 1.0, 1.0e-12);
  }
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
      directional::geometry::surface_cell_tracing_detail::edge_key(
          1, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.segments.back().face, 0);
}

TEST(SurfaceCellTracingPhase14, BoundaryRailTerminatesAndDoesNotCross) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.50, 0.25, 0.25;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Boundary);
  ASSERT_FALSE(trace.segments.empty());
  for (const directional::geometry::SurfaceTraceSegment &segment :
       trace.segments) {
    EXPECT_GE(segment.face, 0);
    EXPECT_LT(segment.face, mesh.faces.rows());
  }
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
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(5));
  rail.curveId = 8;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.sourceEdge = 1;
  a.parameter = 0.0;
  a.railParameter = 0.0;
  a.barycentric << 1.0, 0.0, 0.0;
  a.position = mesh.vertices.row(0);
  directional::geometry::SurfaceCellRailSample b;
  b.sourceFace = 0;
  b.sourceEdge = 1;
  b.parameter = 1.0;
  b.railParameter = 1.0;
  b.barycentric << 0.0, 0.0, 1.0;
  b.position = mesh.vertices.row(3);
  rail.samples = {a, b};
  options.authoritativeRails.push_back(rail);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_NE(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.segments.front().exitEdge, 1);
  EXPECT_TRUE(std::any_of(
      trace.segments.begin(), trace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(5) && segment.curveId == 8 &&
               segment.railIntervalIndex == 0;
      }));
}

TEST(SurfaceCellTracingPhase14, CompatibleHardFeatureRailTerminatesWhenFollowDisabled) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 0.75;
  options.followCompatibleHardFeatureRails = false;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.segments.front().exitEdge, 1);
}

TEST(SurfaceCellTracingPhase14,
     OpenHardFeatureRailEndpointIsNotClassifiedAsSourceSheet) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.10, 0.20, 0.70;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.sourceFaceComponents.assign(mesh.faces.rows(), 0);
  options.sourceFaceSheets.assign(mesh.faces.rows(), 0);
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(43));
  rail.curveId = 9;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3)};
  options.authoritativeRails.push_back(rail);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_NE(trace.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_TRUE(std::any_of(
      trace.segments.begin(), trace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(43) && segment.railIntervalIndex == 0 &&
               segment.railSideSign != 0;
      }));

  directional::geometry::SurfaceCellRail reverseRail = rail;
  reverseRail.id = directional::tests::test_hard_rail_id(44);
  reverseRail.samples = {
      rail_sample(mesh, 1, 2, 0.0, 1.0,
                  Eigen::RowVector3d(0.0, 1.0, 0.0), 3),
      rail_sample(mesh, 1, 2, 1.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0)};
  options.authoritativeRails = {reverseRail};
  directional::geometry::SurfaceTraceSeed reverseSeed = seed;
  reverseSeed.point.face = 0;
  reverseSeed.point.barycentric << 0.25, 0.25, 0.50;
  const auto reverseTrace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, reverseSeed, 0, -1, options);
  EXPECT_NE(reverseTrace.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
  EXPECT_TRUE(reverseTrace.termination ==
                  directional::geometry::TraceTerminationReason::Feature ||
              reverseTrace.termination ==
                  directional::geometry::TraceTerminationReason::Boundary);
}

TEST(SurfaceCellTracingPhase14,
     AdjacentLocalSheetChartsAllowInteriorEdgeTransition) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  ASSERT_GE(trace.segments.size(), 2U);
  EXPECT_EQ(1, trace.segments[1].face);
  EXPECT_NE(trace.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
}

TEST(SurfaceCellTracingPhase14,
     SourceComponentMismatchTerminatesInteriorEdgeTransition) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.sourceFaceComponents = {0, 1};
  options.sourceFaceSheets = {0, 1};

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(0, trace.segments.back().face);
}

TEST(SurfaceCellTracingPhase14,
     AdjacentLocalSheetChartsAllowVertexContinuation) {
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
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  EXPECT_NE(trace.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
}

TEST(SurfaceCellTracingPhase14,
     SourceComponentMismatchBlocksVertexContinuation) {
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
  options.sourceFaceComponents = {0, 1};
  options.sourceFaceSheets = {0, 1};

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
}

TEST(SurfaceCellTracingPhase14, InvalidSourceSheetArraysFailClosed) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.sourceFaceComponents = {0};
  options.sourceFaceSheets = {0, 0};

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);
  EXPECT_TRUE(trace.segments.empty());
}

TEST(SurfaceCellTracingPhase14,
     CellProposalMayCrossAdjacentLocalSheetCharts) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 0.75);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 11;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.75;
  options.maxTraceLength = 2.0;
  options.closureToleranceFactor = 10.0;
  options.sourceFaceComponents = {0, 0};
  options.sourceFaceSheets = {0, 1};

  const auto proposal = directional::geometry::make_surface_cell_proposal(
      mesh.vertices, mesh.faces, x, y, targetSize, seed, options);

  EXPECT_TRUE(proposal.accepted);
  EXPECT_EQ(directional::geometry::CellRejectionReason::Accepted,
            proposal.rejection);
}

TEST(SurfaceCellTracingPhase14,
     CellProposalRejectsSourceComponentCrossing) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 0.75);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 11;
  seed.point.face = 0;
  seed.point.barycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.75;
  options.maxTraceLength = 2.0;
  options.closureToleranceFactor = 10.0;
  options.sourceFaceComponents = {0, 1};
  options.sourceFaceSheets = {0, 1};

  const auto proposal = directional::geometry::make_surface_cell_proposal(
      mesh.vertices, mesh.faces, x, y, targetSize, seed, options);

  EXPECT_FALSE(proposal.accepted);
  EXPECT_EQ(directional::geometry::CellRejectionReason::SourceSheet,
            proposal.rejection);
}

TEST(SurfaceCellTracingPhase14, CompatibleHardFeatureRailPreservesIntervalMetadata) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.10, 0.20, 0.70;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(42));
  rail.curveId = 7;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.sourceEdge = 1;
  a.parameter = 0.0;
  a.railParameter = 0.0;
  a.barycentric << 1.0, 0.0, 0.0;
  a.position = mesh.vertices.row(0);
  directional::geometry::SurfaceCellRailSample b;
  b.sourceFace = 0;
  b.sourceEdge = 1;
  b.parameter = 1.0;
  b.railParameter = 1.0;
  b.barycentric << 0.0, 0.0, 1.0;
  b.position = mesh.vertices.row(3);
  rail.samples = {a, b};
  options.authoritativeRails.push_back(rail);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, -1, options);

  ASSERT_GE(trace.segments.size(), 2U);
  const auto followed = std::find_if(
      trace.segments.begin(), trace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(42);
      });
  ASSERT_NE(trace.segments.end(), followed);
  EXPECT_EQ(7, followed->curveId);
  EXPECT_EQ(0, followed->railIntervalIndex);
  EXPECT_NEAR(0.70, followed->railT0, 1.0e-12);
  EXPECT_NEAR(0.0, followed->railT1, 1.0e-12);
}

TEST(SurfaceCellTracingPhase14, CompatibleHardFeatureRailEntersFromEitherSide) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);

  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 0.75;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 3, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  directional::geometry::SurfaceCellRail faceZeroRail(directional::tests::test_hard_rail_id(91));
  faceZeroRail.curveId = 21;
  faceZeroRail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  faceZeroRail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3)};
  options.authoritativeRails = {faceZeroRail};

  directional::geometry::SurfaceTraceSeed fromOppositeSide;
  fromOppositeSide.point.face = 1;
  fromOppositeSide.point.barycentric << 0.25, 0.25, 0.50;
  const auto oppositeTrace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, fromOppositeSide, 0, 1, options);

  EXPECT_NE(oppositeTrace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_TRUE(std::any_of(
      oppositeTrace.segments.begin(), oppositeTrace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(91) && segment.curveId == 21 &&
               segment.railIntervalIndex == 0;
      }));

  directional::geometry::SurfaceCellRail faceOneReversedRail(directional::tests::test_hard_rail_id(92));
  faceOneReversedRail.curveId = 22;
  faceOneReversedRail.kind =
      directional::geometry::SurfaceCellRailKind::HardFeature;
  faceOneReversedRail.samples = {
      rail_sample(mesh, 1, 2, 0.0, 1.0,
                  Eigen::RowVector3d(0.0, 1.0, 0.0), 3),
      rail_sample(mesh, 1, 2, 1.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0)};
  options.authoritativeRails = {faceOneReversedRail};

  directional::geometry::SurfaceTraceSeed fromStoredOppositeSide;
  fromStoredOppositeSide.point.face = 0;
  fromStoredOppositeSide.point.barycentric << 0.25, 0.25, 0.50;
  const auto reversedTrace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, fromStoredOppositeSide, 0, -1, options);

  EXPECT_NE(reversedTrace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_TRUE(std::any_of(
      reversedTrace.segments.begin(), reversedTrace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(92) && segment.curveId == 22 &&
               segment.railIntervalIndex == 0;
      }));
}

TEST(SurfaceCellTracingPhase14,
     CompatibleHardFeatureRailVisitsAlternatingStoredSideIntervalsInOrder) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.10, 0.70, 0.20;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 4, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          4, 7, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          4, 8, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(77));
  rail.curveId = 11;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  directional::geometry::SurfaceCellRailSample a0;
  a0.sourceFace = 0;
  a0.sourceEdge = 1;
  a0.railParameter = 0.0;
  a0.barycentric << 1.0, 0.0, 0.0;
  a0.position = mesh.vertices.row(0);
  directional::geometry::SurfaceCellRailSample b0;
  b0.sourceFace = 0;
  b0.sourceEdge = 1;
  b0.parameter = 1.0;
  b0.railParameter = 0.5;
  b0.barycentric << 0.0, 0.0, 1.0;
  b0.position = mesh.vertices.row(4);
  directional::geometry::SurfaceCellRailSample a1;
  a1.sourceFace = 7;
  a1.sourceEdge = 1;
  a1.railParameter = 0.5;
  a1.barycentric << 1.0, 0.0, 0.0;
  a1.position = mesh.vertices.row(4);
  directional::geometry::SurfaceCellRailSample b1;
  b1.sourceFace = 7;
  b1.sourceEdge = 1;
  b1.parameter = 1.0;
  b1.railParameter = 1.0;
  b1.barycentric << 0.0, 0.0, 1.0;
  b1.position = mesh.vertices.row(7);
  rail.samples = {a0, b0, a1, b1};
  options.authoritativeRails.push_back(rail);
  directional::geometry::SurfaceCellRail spur(directional::tests::test_hard_rail_id(78));
  spur.curveId = 12;
  spur.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  directional::geometry::SurfaceCellRailSample spurA;
  spurA.sourceFace = 6;
  spurA.sourceEdge = 1;
  spurA.railParameter = 0.0;
  spurA.barycentric << 1.0, 0.0, 0.0;
  spurA.position = mesh.vertices.row(4);
  directional::geometry::SurfaceCellRailSample spurB;
  spurB.sourceFace = 6;
  spurB.sourceEdge = 1;
  spurB.parameter = 1.0;
  spurB.railParameter = 1.0;
  spurB.barycentric << 0.0, 0.0, 1.0;
  spurB.position = mesh.vertices.row(8);
  spur.samples = {spurA, spurB};
  options.authoritativeRails.push_back(spur);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 1, 1, options);

  std::vector<int> intervals;
  std::vector<double> starts;
  std::vector<double> ends;
  for (const directional::geometry::SurfaceTraceSegment &segment :
       trace.segments) {
    if (segment.railId == directional::tests::test_hard_rail_id(77)) {
      intervals.push_back(segment.railIntervalIndex);
      starts.push_back(segment.railT0);
      ends.push_back(segment.railT1);
    }
    EXPECT_NE(segment.railId, directional::tests::test_hard_rail_id(78));
  }
  ASSERT_GE(intervals.size(), 2U);
  EXPECT_EQ(0, intervals[0]);
  EXPECT_EQ(1, intervals[1]);
  ASSERT_GE(trace.segments.size(), 2U);
  EXPECT_EQ(0, trace.segments[trace.segments.size() - 2].face);
  EXPECT_EQ(7, trace.segments[trace.segments.size() - 1].face);
  EXPECT_NE(0, trace.segments[trace.segments.size() - 2].railSideSign);
  EXPECT_EQ(trace.segments[trace.segments.size() - 2].railSideSign,
            trace.segments[trace.segments.size() - 1].railSideSign);
  EXPECT_LT(starts[0], ends[0]);
  EXPECT_LT(starts[1], ends[1]);
  EXPECT_NEAR(0.45, starts[0], 1.0e-12);
  EXPECT_NEAR(0.5, ends[0], 1.0e-12);
  EXPECT_NEAR(0.5, starts[1], 1.0e-12);
  EXPECT_NEAR(1.0, ends[1], 1.0e-12);
}

TEST(SurfaceCellTracingPhase14,
     HardFeatureRailContinuationCrossesAdjacentLocalSheetCharts) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.10, 0.70, 0.20;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 10.0;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 4, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          4, 7, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.sourceFaceComponents.assign(mesh.faces.rows(), 0);
  options.sourceFaceSheets.assign(mesh.faces.rows(), 0);
  options.sourceFaceSheets[4] = 1;
  options.sourceFaceSheets[7] = 1;

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(93));
  rail.curveId = 23;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 4),
      rail_sample(mesh, 7, 1, 0.0, 0.5,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 4),
      rail_sample(mesh, 7, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 7)};
  options.authoritativeRails.push_back(rail);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 1, 1, options);

  EXPECT_EQ(trace.termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_TRUE(std::any_of(
      trace.segments.begin(), trace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(93) && segment.railIntervalIndex == 0;
      }));
  EXPECT_TRUE(std::any_of(
      trace.segments.begin(), trace.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(93) && segment.railIntervalIndex == 1;
      }));

  options.sourceFaceComponents[4] = 1;
  options.sourceFaceComponents[7] = 1;
  const auto componentBlocked =
      directional::geometry::trace_surface_field(
          mesh.vertices, mesh.faces, x, y, seed, 1, 1, options);
  EXPECT_EQ(componentBlocked.termination,
            directional::geometry::TraceTerminationReason::SourceSheet);
  EXPECT_FALSE(std::any_of(
      componentBlocked.segments.begin(), componentBlocked.segments.end(),
      [](const directional::geometry::SurfaceTraceSegment &segment) {
        return segment.railId == directional::tests::test_hard_rail_id(93) && segment.railIntervalIndex == 1;
      }));
}

TEST(SurfaceCellTracingPhase14,
     RailPreprocessingRejectsMalformedIntervalsAndReportsEndpointForValidRail) {
  const MeshFixture mesh = make_grid(2);
  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.faces);
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(95));
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 4),
      rail_sample(mesh, 0, 99, 0.0, 0.5,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 4),
      rail_sample(mesh, 0, 99, 1.0, 0.75,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 4),
      rail_sample(mesh, 7, 1, 0.0, 0.75,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 4),
      rail_sample(mesh, 7, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 7)};
  const auto refs =
      directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
          {rail}, mesh.vertices, mesh.faces, edgeFaces);
  ASSERT_EQ(refs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::InvalidSamplePair);
  directional::geometry::SurfaceCellRail validRail = rail;
  validRail.samples.resize(2);
  const auto validRefs =
      directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
          {validRail}, mesh.vertices, mesh.faces, edgeFaces);
  ASSERT_EQ(validRefs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::Valid);
  directional::geometry::SurfaceCellTracingOptions options;
  const auto endpoint =
      directional::geometry::surface_cell_tracing_detail::find_next_rail_interval(
          validRefs.intervals,
          {&validRefs.intervals[0],
           validRefs.intervals[0].incidentSides.front()},
          1, options);
  EXPECT_EQ(endpoint.status,
            directional::geometry::surface_cell_tracing_detail::RailContinuationStatus::OpenEndpoint);
}

TEST(SurfaceCellTracingPhase14,
     MalformedAuthoritativeRailsFailBeforeTracingAndSideDiscontinuityIsTyped) {
  const MeshFixture mesh = make_grid(1);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.2, 0.3, 0.5;
  const auto trace_with = [&](const std::vector<directional::geometry::SurfaceCellRail> &rails) {
    directional::geometry::SurfaceCellTracingOptions options;
    options.maxTraceLength = 10.0;
    options.authoritativeRails = rails;
    return directional::geometry::trace_surface_field(
        mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);
  };
  directional::geometry::SurfaceCellRail odd(directional::tests::test_hard_rail_id(101));
  odd.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  odd.samples.push_back(rail_sample(mesh, 0, 1, 0.0, 0.0,
                                     Eigen::RowVector3d(1.0, 0.0, 0.0), 0));
  EXPECT_EQ(trace_with({odd}).termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);

  directional::geometry::SurfaceCellRail invalid = odd;
  invalid.id = directional::tests::test_hard_rail_id(directional::tests::test_hard_rail_id(102));
  invalid.samples = {
      rail_sample(mesh, 0, 99, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 99, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3)};
  EXPECT_EQ(trace_with({invalid}).termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);
  directional::geometry::SurfaceCellRail invalidMiddle = invalid;
  invalidMiddle.id = directional::tests::test_hard_rail_id(105);
  invalidMiddle.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.33,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3),
      rail_sample(mesh, 0, 99, 0.0, 0.33,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 99, 1.0, 0.66,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3),
      rail_sample(mesh, 0, 0, 0.0, 0.66,
                  Eigen::RowVector3d(0.0, 1.0, 0.0), 1),
      rail_sample(mesh, 0, 0, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3)};
  EXPECT_EQ(trace_with({invalidMiddle}).termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);
  directional::geometry::SurfaceCellRail invalidFinal = invalidMiddle;
  invalidFinal.id = directional::tests::test_hard_rail_id(106);
  invalidFinal.samples[2].sourceEdge = 2;
  invalidFinal.samples[3].sourceEdge = 2;
  invalidFinal.samples[4].sourceEdge = 99;
  invalidFinal.samples[5].sourceEdge = 99;
  EXPECT_EQ(trace_with({invalidFinal}).termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);

  directional::geometry::SurfaceCellRail valid = invalid;
  valid.id = directional::tests::test_hard_rail_id(103);
  valid.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3)};
  directional::geometry::SurfaceCellRail duplicate = valid;
  EXPECT_EQ(trace_with({valid, duplicate}).termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);
  valid.closed = true;
  EXPECT_EQ(trace_with({valid}).termination,
            directional::geometry::TraceTerminationReason::FieldMetadata);

  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.faces);
  directional::geometry::SurfaceCellRail ordered = valid;
  ordered.id = directional::tests::test_hard_rail_id(104);
  ordered.closed = false;
  ordered.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3),
      rail_sample(mesh, 0, 1, 0.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3),
      rail_sample(mesh, 0, 1, 1.0, 1.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0)};
  auto refs = directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
      {ordered}, mesh.vertices, mesh.faces, edgeFaces);
  ASSERT_EQ(refs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::DuplicateInterval);
  ordered.samples[2] =
      rail_sample(mesh, 0, 0, 0.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 3);
  ordered.samples[3] =
      rail_sample(mesh, 0, 0, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 1.0, 0.0), 1);
  refs = directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
      {ordered}, mesh.vertices, mesh.faces, edgeFaces);
  ASSERT_EQ(refs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::Valid);
  refs.intervals[1].incidentSides.resize(1);
  refs.intervals[1].incidentSides[0].sideSign =
      -refs.intervals[0].incidentSides.front().sideSign;
  directional::geometry::SurfaceCellTracingOptions options;
  const auto continuation =
      directional::geometry::surface_cell_tracing_detail::find_next_rail_interval(
          refs.intervals,
          {&refs.intervals[0], refs.intervals[0].incidentSides.front()}, 1,
          options);
  EXPECT_EQ(continuation.status,
            directional::geometry::surface_cell_tracing_detail::RailContinuationStatus::SideDiscontinuity);
}

TEST(SurfaceCellTracingPhase14,
     RailValidationRejectsDisconnectedGeometryParametersAndSharedEdges) {
  const MeshFixture mesh = make_grid(2);
  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.faces);
  const auto validate = [&](const std::vector<directional::geometry::SurfaceCellRail> &rails) {
    return directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
        rails, mesh.vertices, mesh.faces, edgeFaces);
  };

  directional::geometry::SurfaceCellRail first(directional::tests::test_hard_rail_id(201));
  first.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  first.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 4)};

  directional::geometry::SurfaceCellRail empty(directional::tests::test_hard_rail_id(200));
  EXPECT_EQ(validate({empty}).status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::EmptyRail);

  directional::geometry::SurfaceCellRail disconnected = first;
  disconnected.id = directional::tests::test_hard_rail_id(202);
  disconnected.samples.insert(
      disconnected.samples.end(),
      {rail_sample(mesh, 3, 2, 0.0, 0.5,
                   Eigen::RowVector3d(1.0, 0.0, 0.0), 1),
       rail_sample(mesh, 3, 2, 1.0, 1.0,
                   Eigen::RowVector3d(0.0, 1.0, 0.0), 5)});
  EXPECT_EQ(validate({disconnected}).status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::DisconnectedIntervals);

  directional::geometry::SurfaceCellRail parameterGap = first;
  parameterGap.id = directional::tests::test_hard_rail_id(203);
  parameterGap.samples.insert(
      parameterGap.samples.end(),
      {rail_sample(mesh, 7, 1, 0.0, 0.6,
                   Eigen::RowVector3d(1.0, 0.0, 0.0), 4),
       rail_sample(mesh, 7, 1, 1.0, 1.0,
                   Eigen::RowVector3d(0.0, 0.0, 1.0), 7)});
  EXPECT_EQ(validate({parameterGap}).status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::NonContiguousIntervals);

  directional::geometry::SurfaceCellRail invalidGeometry = first;
  invalidGeometry.id = directional::tests::test_hard_rail_id(204);
  invalidGeometry.samples[1].position.x() += 0.25;
  EXPECT_EQ(validate({invalidGeometry}).status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::InvalidSampleGeometry);

  directional::geometry::SurfaceCellRail invalidLocalParameter = first;
  invalidLocalParameter.id = directional::tests::test_hard_rail_id(206);
  invalidLocalParameter.samples[0].parameter = 0.25;
  EXPECT_EQ(validate({invalidLocalParameter}).status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::InvalidRailParameters);

  directional::geometry::SurfaceCellRail duplicateEdge = first;
  duplicateEdge.id = directional::tests::test_hard_rail_id(205);
  EXPECT_EQ(validate({first, duplicateEdge}).status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::DuplicateInterval);
}

TEST(SurfaceCellTracingPhase14,
     RailSideSelectionIsStableForReverseTraversalAndIncidentOrder) {
  const MeshFixture mesh = make_grid(2);
  const auto edgeFaces =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.faces);
  auto reversedEdgeFaces = edgeFaces;
  for (auto &[key, faces] : reversedEdgeFaces) {
    std::swap(faces[0], faces[1]);
  }
  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(96));
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 4),
      rail_sample(mesh, 7, 1, 0.0, 0.5,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 4),
      rail_sample(mesh, 7, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 7)};
  const auto refs =
      directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
          {rail}, mesh.vertices, mesh.faces, edgeFaces);
  const auto reversedRefs =
      directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
          {rail}, mesh.vertices, mesh.faces, reversedEdgeFaces);
  ASSERT_EQ(refs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::Valid);
  ASSERT_EQ(reversedRefs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::Valid);
  ASSERT_EQ(refs.intervals.size(), 2U);
  ASSERT_EQ(reversedRefs.intervals.size(), 2U);
  const auto side_for_face = [](const auto &interval, const int face) {
    return std::find_if(interval.incidentSides.begin(),
                        interval.incidentSides.end(),
                        [&](const auto &side) { return side.sourceFace == face; });
  };
  const auto forwardSide = side_for_face(refs.intervals[0], 0);
  const auto reverseSide = side_for_face(refs.intervals[1], 7);
  const auto reorderedSide = side_for_face(reversedRefs.intervals[0], 0);
  ASSERT_NE(refs.intervals[0].incidentSides.end(), forwardSide);
  ASSERT_NE(refs.intervals[1].incidentSides.end(), reverseSide);
  ASSERT_NE(reversedRefs.intervals[0].incidentSides.end(), reorderedSide);
  directional::geometry::SurfaceCellTracingOptions options;
  const auto forward =
      directional::geometry::surface_cell_tracing_detail::find_next_rail_interval(
          refs.intervals, {&refs.intervals[0], *forwardSide}, 1, options);
  const auto reverse =
      directional::geometry::surface_cell_tracing_detail::find_next_rail_interval(
          refs.intervals, {&refs.intervals[1], *reverseSide}, -1, options);
  const auto reordered =
      directional::geometry::surface_cell_tracing_detail::find_next_rail_interval(
          reversedRefs.intervals,
          {&reversedRefs.intervals[0], *reorderedSide}, 1, options);
  ASSERT_EQ(forward.status,
            directional::geometry::surface_cell_tracing_detail::RailContinuationStatus::Found);
  ASSERT_EQ(reverse.status,
            directional::geometry::surface_cell_tracing_detail::RailContinuationStatus::Found);
  ASSERT_EQ(reordered.status,
            directional::geometry::surface_cell_tracing_detail::RailContinuationStatus::Found);
  EXPECT_EQ(forward.selection.side.sideSign, reverse.selection.side.sideSign);
  EXPECT_EQ(forward.selection.side.sourceFace, 7);
  EXPECT_EQ(reverse.selection.side.sourceFace, 0);
  EXPECT_EQ(forward.selection.side.sideSign, reordered.selection.side.sideSign);

  MeshFixture faceReordered = mesh;
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    faceReordered.faces.row(face) = mesh.faces.row(mesh.faces.rows() - 1 - face);
  }
  directional::geometry::SurfaceCellRail rowReorderedRail = rail;
  rowReorderedRail.samples[0].sourceFace = 7;
  rowReorderedRail.samples[1].sourceFace = 7;
  rowReorderedRail.samples[2].sourceFace = 0;
  rowReorderedRail.samples[3].sourceFace = 0;
  const auto rowReorderedRefs =
      directional::geometry::surface_cell_tracing_detail::rail_interval_refs(
          {rowReorderedRail}, faceReordered.vertices, faceReordered.faces,
          directional::geometry::surface_cell_tracing_detail::edge_faces(
              faceReordered.faces));
  ASSERT_EQ(rowReorderedRefs.status,
            directional::geometry::surface_cell_tracing_detail::RailBuildStatus::Valid);
  const auto rowSide = std::find_if(
      rowReorderedRefs.intervals[0].incidentSides.begin(),
      rowReorderedRefs.intervals[0].incidentSides.end(),
      [](const auto &side) { return side.sourceFace == 7; });
  ASSERT_NE(rowReorderedRefs.intervals[0].incidentSides.end(), rowSide);
  const auto rowForward =
      directional::geometry::surface_cell_tracing_detail::find_next_rail_interval(
          rowReorderedRefs.intervals,
          {&rowReorderedRefs.intervals[0], *rowSide}, 1, options);
  ASSERT_EQ(rowForward.status,
            directional::geometry::surface_cell_tracing_detail::RailContinuationStatus::Found);
  EXPECT_EQ(rowForward.selection.side.sourceFace, 0);
  EXPECT_EQ(rowForward.selection.side.sideSign, forward.selection.side.sideSign);
}

TEST(SurfaceCellTracingPhase14,
     CellProposalDoesNotMislabelRailBarrierAsSourceSheet) {
  const MeshFixture mesh = make_grid(2);
  Eigen::MatrixXd x, y;
  constant_axes(mesh, x, y);
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 2.0);
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 94;
  seed.point.face = 0;
  seed.point.barycentric << 0.10, 0.70, 0.20;
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 2.0;
  options.maxTraceLength = 10.0;
  options.closureToleranceFactor = 100.0;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 4, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          4, 7, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.sourceFaceComponents.assign(mesh.faces.rows(), 0);
  options.sourceFaceSheets.assign(mesh.faces.rows(), 0);
  options.sourceFaceSheets[4] = 1;
  options.sourceFaceSheets[7] = 1;

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(94));
  rail.curveId = 24;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.samples = {
      rail_sample(mesh, 0, 1, 0.0, 0.0,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      rail_sample(mesh, 0, 1, 1.0, 0.5,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 4),
      rail_sample(mesh, 7, 1, 0.0, 0.5,
                  Eigen::RowVector3d(1.0, 0.0, 0.0), 4),
      rail_sample(mesh, 7, 1, 1.0, 1.0,
                  Eigen::RowVector3d(0.0, 0.0, 1.0), 7)};
  options.authoritativeRails.push_back(rail);

  const auto proposal = directional::geometry::make_surface_cell_proposal(
      mesh.vertices, mesh.faces, x, y, targetSize, seed, options);

  EXPECT_FALSE(proposal.accepted);
  EXPECT_EQ(directional::geometry::CellRejectionReason::Barrier,
            proposal.rejection);
}

TEST(SurfaceCellTracingPhase14, ClosedHardFeatureRailWrapsIntervalSequence) {
  MeshFixture mesh;
  mesh.vertices.resize(3, 3);
  mesh.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  mesh.faces.resize(1, 3);
  mesh.faces << 0, 1, 2;
  Eigen::MatrixXd x(1, 3);
  Eigen::MatrixXd y(1, 3);
  x.row(0) << 1.0, -1.0, 0.0;
  x.row(0).normalize();
  y.row(0) << 0.0, 1.0, 0.0;
  directional::geometry::SurfaceTraceSeed seed;
  seed.point.face = 0;
  seed.point.barycentric << 0.40, 0.20, 0.40;
  directional::geometry::SurfaceCellTracingOptions options;
  options.maxTraceLength = 4.0;
  options.maxTraceSegments = 16;
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          0, 1, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          1, 2, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));
  options.hardFeatureEdges.insert(
      directional::geometry::surface_cell_tracing_detail::edge_key(
          2, 0, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces)));

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(88));
  rail.curveId = 12;
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.closed = true;
  const auto sample = [&](const int sourceEdge, const double parameter,
                          const double railParameter,
                          const Eigen::RowVector3d &barycentric,
                          const int vertex) {
    directional::geometry::SurfaceCellRailSample result;
    result.sourceFace = 0;
    result.sourceEdge = sourceEdge;
    result.parameter = parameter;
    result.railParameter = railParameter;
    result.barycentric = barycentric;
    result.position = mesh.vertices.row(vertex);
    return result;
  };
  rail.samples = {
      sample(2, 0.0, 0.0, Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
      sample(2, 1.0, 1.0 / 3.0, Eigen::RowVector3d(0.0, 1.0, 0.0), 1),
      sample(0, 0.0, 1.0 / 3.0, Eigen::RowVector3d(0.0, 1.0, 0.0), 1),
      sample(0, 1.0, 2.0 / 3.0, Eigen::RowVector3d(0.0, 0.0, 1.0), 2),
      sample(1, 0.0, 2.0 / 3.0, Eigen::RowVector3d(0.0, 0.0, 1.0), 2),
      sample(1, 1.0, 1.0, Eigen::RowVector3d(1.0, 0.0, 0.0), 0),
  };
  options.authoritativeRails.push_back(rail);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, x, y, seed, 0, 1, options);

  std::vector<int> intervals;
  for (const directional::geometry::SurfaceTraceSegment &segment :
       trace.segments) {
    if (segment.railId == directional::tests::test_hard_rail_id(88)) {
      intervals.push_back(segment.railIntervalIndex);
    }
  }
  ASSERT_GE(intervals.size(), 4U);
  EXPECT_EQ(0, intervals[0]);
  EXPECT_EQ(1, intervals[1]);
  EXPECT_EQ(2, intervals[2]);
  EXPECT_EQ(0, intervals[3]);
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
                network.stats.rejectedClosure + network.stats.rejectedDegenerate +
                network.stats.rejectedSourceSheet +
                network.stats.rejectedFieldMetadata +
                network.stats.rejectedSelfIntersection +
                network.stats.rejectedInverted +
                network.stats.rejectedDuplicateCorner +
                network.stats.rejectedOutOfSize +
                network.stats.rejectedHardRailCrossing);
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
            directional::geometry::CellRejectionReason::DuplicateCorner);
}

TEST(SurfaceCellTracingPhase14, CellLoopRejectionsAreSpecific) {
  using directional::geometry::CellRejectionReason;
  using directional::geometry::SurfaceCellTracingOptions;
  using directional::geometry::surface_cell_tracing_detail::classify_quad_loop;
  const Eigen::RowVector3d normal(0.0, 0.0, 1.0);
  SurfaceCellTracingOptions options;

  const std::array<Eigen::RowVector3d, 4> duplicate{
      Eigen::RowVector3d(0.0, 0.0, 0.0),
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0)};
  EXPECT_EQ(classify_quad_loop(duplicate, 1.0, normal, options),
            CellRejectionReason::DuplicateCorner);

  const std::array<Eigen::RowVector3d, 4> crossing{
      Eigen::RowVector3d(0.0, 0.0, 0.0),
      Eigen::RowVector3d(1.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(1.0, 0.0, 0.0)};
  EXPECT_EQ(classify_quad_loop(crossing, 1.0, normal, options),
            CellRejectionReason::SelfIntersection);

  const std::array<Eigen::RowVector3d, 4> inverted{
      Eigen::RowVector3d(0.0, 0.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(1.0, 1.0, 0.0),
      Eigen::RowVector3d(1.0, 0.0, 0.0)};
  EXPECT_EQ(classify_quad_loop(inverted, 1.0, normal, options),
            CellRejectionReason::Inverted);

  const std::array<Eigen::RowVector3d, 4> oversized{
      Eigen::RowVector3d(0.0, 0.0, 0.0),
      Eigen::RowVector3d(5.0, 0.0, 0.0),
      Eigen::RowVector3d(5.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0)};
  EXPECT_EQ(classify_quad_loop(oversized, 1.0, normal, options),
            CellRejectionReason::OutOfSize);
}

TEST(SurfaceCellTracingPhase14, CellBoundaryRejectsProperHardRailCrossing) {
  directional::geometry::SurfaceTraceSegment segment;
  segment.face = 0;
  segment.startBarycentric << 0.5, 0.5, 0.0;
  segment.endBarycentric << 0.5, 0.0, 0.5;

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(17));
  directional::geometry::SurfaceCellRailSample a;
  a.sourceFace = 0;
  a.barycentric << 0.75, 0.0, 0.25;
  directional::geometry::SurfaceCellRailSample b;
  b.sourceFace = 0;
  b.barycentric << 0.25, 0.5, 0.25;
  rail.samples = {a, b};

  EXPECT_TRUE(directional::geometry::surface_cell_tracing_detail::
                  trace_segment_crosses_authoritative_rail(segment, {rail}));
  segment.railId = rail.id;
  EXPECT_FALSE(directional::geometry::surface_cell_tracing_detail::
                   trace_segment_crosses_authoritative_rail(segment, {rail}));
}

TEST(SurfaceCellTracingPhase14, HardRailCrossingUsesEndpointPairsOnly) {
  directional::geometry::SurfaceTraceSegment segment;
  segment.face = 0;
  segment.startBarycentric << 0.5, 0.5, 0.0;
  segment.endBarycentric << 0.5, 0.0, 0.5;

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(19));
  const auto sample = [](const Eigen::RowVector3d &barycentric) {
    directional::geometry::SurfaceCellRailSample result;
    result.sourceFace = 0;
    result.barycentric = barycentric;
    return result;
  };
  // Neither stored interval crosses the trace. The artificial bridge between
  // samples 1 and 2 does, and must not be interpreted as part of the rail.
  rail.samples = {
      sample(Eigen::RowVector3d(0.9, 0.1, 0.0)),
      sample(Eigen::RowVector3d(0.8, 0.2, 0.0)),
      sample(Eigen::RowVector3d(0.2, 0.0, 0.8)),
      sample(Eigen::RowVector3d(0.1, 0.0, 0.9)),
  };

  EXPECT_FALSE(directional::geometry::surface_cell_tracing_detail::
                   trace_segment_crosses_authoritative_rail(segment, {rail}));
}

TEST(SurfaceCellTracingPhase14, ClosedBoundaryRejectsInteriorPathCrossing) {
  using directional::geometry::CellRejectionReason;
  using directional::geometry::SurfaceCellProposal;
  using directional::geometry::SurfaceTracePoint;
  using directional::geometry::SurfaceTraceSegment;

  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  SurfaceCellProposal proposal;
  proposal.corners = {
      SurfaceTracePoint{0, Eigen::RowVector3d(0.6, 0.2, 0.2)},
      SurfaceTracePoint{0, Eigen::RowVector3d(0.2, 0.6, 0.2)},
      SurfaceTracePoint{0, Eigen::RowVector3d(0.1, 0.6, 0.3)},
      SurfaceTracePoint{0, Eigen::RowVector3d(0.5, 0.2, 0.3)},
  };
  const auto segment = [](const Eigen::RowVector3d &a,
                          const Eigen::RowVector3d &b) {
    SurfaceTraceSegment result;
    result.face = 0;
    result.startBarycentric = a;
    result.endBarycentric = b;
    return result;
  };

  // Side 0 detours through the triangle interior. Side 2 crosses that detour,
  // while the four corner chords themselves remain non-self-intersecting.
  const Eigen::RowVector3d center(0.25, 0.40, 0.35);
  proposal.boundaryPaths[0] = {
      segment(proposal.corners[0].barycentric, center),
      segment(center, proposal.corners[1].barycentric),
  };
  proposal.boundaryPaths[1] = {
      segment(proposal.corners[1].barycentric,
              proposal.corners[2].barycentric),
  };
  proposal.boundaryPaths[2] = {
      segment(proposal.corners[2].barycentric,
              proposal.corners[3].barycentric),
  };
  proposal.boundaryPaths[3] = {
      segment(proposal.corners[3].barycentric,
              proposal.corners[0].barycentric),
  };

  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                validate_closed_boundary_paths(vertices, faces, proposal.corners,
                                               proposal.boundaryPaths, 1.0e-12),
            CellRejectionReason::SelfIntersection);
}

TEST(SurfaceCellTracingPhase14, ClosedBoundaryRejectsEndpointGap) {
  using directional::geometry::CellRejectionReason;
  using directional::geometry::SurfaceCellProposal;
  using directional::geometry::SurfaceTracePoint;
  using directional::geometry::SurfaceTraceSegment;

  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  SurfaceCellProposal proposal;
  proposal.corners = {
      SurfaceTracePoint{0, Eigen::RowVector3d(0.8, 0.2, 0.0)},
      SurfaceTracePoint{0, Eigen::RowVector3d(0.2, 0.8, 0.0)},
      SurfaceTracePoint{0, Eigen::RowVector3d(0.2, 0.0, 0.8)},
      SurfaceTracePoint{0, Eigen::RowVector3d(0.8, 0.0, 0.2)},
  };
  const auto segment = [](const Eigen::RowVector3d &a,
                          const Eigen::RowVector3d &b) {
    SurfaceTraceSegment result;
    result.face = 0;
    result.startBarycentric = a;
    result.endBarycentric = b;
    return result;
  };
  for (int side = 0; side < 4; ++side) {
    proposal.boundaryPaths[static_cast<std::size_t>(side)] = {
        segment(proposal.corners[static_cast<std::size_t>(side)].barycentric,
                proposal.corners[static_cast<std::size_t>((side + 1) % 4)]
                    .barycentric),
    };
  }
  proposal.boundaryPaths[1][0].endBarycentric << 0.25, 0.0, 0.75;

  EXPECT_EQ(directional::geometry::surface_cell_tracing_detail::
                validate_closed_boundary_paths(vertices, faces, proposal.corners,
                                               proposal.boundaryPaths, 1.0e-12),
            CellRejectionReason::Closure);
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

TEST(SurfaceCellTracingPhase14,
     IntersectingFlowlinesCloseWhenOrderedFieldWalksDoNotCommute) {
  const MeshFixture mesh = make_grid(8);
  Eigen::MatrixXd axisX(mesh.faces.rows(), 3);
  Eigen::MatrixXd axisY(mesh.faces.rows(), 3);
  constexpr double gradient = 0.8;
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    double centroidX = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      centroidX += mesh.vertices(mesh.faces(face, corner), 0) / 3.0;
    }
    const double angle = gradient * centroidX;
    axisX.row(face) << std::cos(angle), std::sin(angle), 0.0;
    axisY.row(face) << -std::sin(angle), std::cos(angle), 0.0;
  }
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 81;
  seed.point.face = 2 * (4 * 8 + 4);
  seed.point.barycentric << 0.2, 0.3, 0.5;
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(mesh.vertices.rows(), 1.0);
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 1.0;
  options.maxTraceLength = 4.0;
  options.closureToleranceFactor = 0.05;

  const auto walk = [&](const int family, const int sign,
                        const directional::geometry::SurfaceTracePoint &start) {
    return directional::geometry::walk_surface_field(
        mesh.vertices, mesh.faces, axisX, axisY, start, family, sign, 0.5,
        options);
  };
  const auto xFirst = walk(0, 1, seed.point);
  const auto xy = walk(1, 1, xFirst.point);
  const auto yFirst = walk(1, 1, seed.point);
  const auto yx = walk(0, 1, yFirst.point);
  const Eigen::RowVector3d xyPosition =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces, xy.point);
  const Eigen::RowVector3d yxPosition =
      directional::geometry::surface_cell_tracing_detail::point_position(
          mesh.vertices, mesh.faces, yx.point);
  ASSERT_GT((xyPosition - yxPosition).norm(),
            options.closureToleranceFactor);

  const auto proposal = directional::geometry::make_surface_cell_proposal(
      mesh.vertices, mesh.faces, axisX, axisY, targetSize, seed, options);
  ASSERT_TRUE(proposal.accepted);
  EXPECT_EQ(directional::geometry::CellRejectionReason::Accepted,
            proposal.rejection);
  for (const auto &boundaryPath : proposal.boundaryPaths) {
    EXPECT_FALSE(boundaryPath.empty());
  }
}

TEST(SurfaceCellTracingPhase14,
     SourceClassifierMakesUnmarkedSharpBendPolicyExplicit) {
  const MeshFixture mesh = make_hinge_pair();
  const auto defaultLabels =
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(mesh.vertices, mesh.faces);
  ASSERT_EQ(2U, defaultLabels.localSheetByFace.size());
  EXPECT_EQ(defaultLabels.localSheetByFace[0],
            defaultLabels.localSheetByFace[1]);

  directional::geometry::SourceSurfaceClassifierOptions splitPolicy;
  splitPolicy.traverseUnmarkedSharpBends = false;
  const auto splitLabels =
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(mesh.vertices, mesh.faces, {},
                                         splitPolicy);
  EXPECT_NE(splitLabels.localSheetByFace[0], splitLabels.localSheetByFace[1]);

  const std::set<directional::authority::SourceEdgeTopologyKey> markedBarrier{
      directional::geometry::surface_cell_tracing_detail::edge_key(
          1, 2, directional::geometry::surface_cell_tracing_detail::
                    source_vertex_extent(mesh.faces))};
  const auto markedLabels =
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(mesh.vertices, mesh.faces,
                                         markedBarrier);
  EXPECT_NE(markedLabels.localSheetByFace[0],
            markedLabels.localSheetByFace[1]);
}

TEST(SurfaceCellTracingPhase14,
     SourceClassifierSeparatesConnectedCloseOpposingSheets) {
  const MeshFixture mesh = make_connected_close_opposing_sheets();
  const auto labels = directional::geometry::surface_cell_tracing_detail::
      classify_source_surface_labels(mesh.vertices, mesh.faces);
  ASSERT_EQ(6U, labels.componentByFace.size());
  EXPECT_EQ(labels.componentByFace[0], labels.componentByFace[4]);
  EXPECT_EQ(labels.localSheetByFace[0], labels.localSheetByFace[1]);
  EXPECT_NE(labels.localSheetByFace[0], labels.localSheetByFace[4]);
}

TEST(SurfaceCellTracingPhase14,
     SourceClassifierIsScaleInvariantAndDeterministic) {
  const MeshFixture source = make_connected_close_opposing_sheets();
  std::vector<int> referenceComponents;
  std::vector<int> referenceSheets;
  std::uint64_t referenceHash = 0U;
  for (const double scale : {1.0e-3, 1.0, 1.0e3}) {
    MeshFixture mesh = source;
    mesh.vertices *= scale;
    const auto labels = directional::geometry::surface_cell_tracing_detail::
        classify_source_surface_labels(mesh.vertices, mesh.faces);
    if (referenceComponents.empty()) {
      referenceComponents = labels.componentByFace;
      referenceSheets = labels.localSheetByFace;
      referenceHash = source_label_hash(labels);
    } else {
      EXPECT_EQ(referenceComponents, labels.componentByFace);
      EXPECT_EQ(referenceSheets, labels.localSheetByFace);
      EXPECT_EQ(referenceHash, source_label_hash(labels));
    }
    for (int repeat = 0; repeat < 3; ++repeat) {
      const auto repeated =
          directional::geometry::surface_cell_tracing_detail::
              classify_source_surface_labels(mesh.vertices, mesh.faces);
      EXPECT_EQ(source_label_hash(labels), source_label_hash(repeated));
    }
  }
}

TEST(SurfaceCellTracingPhase14,
     SourceClassifierCoversCurvedClosedAndCoarseManifoldFixtures) {
  for (const MeshFixture mesh : {make_open_cylinder(16),
                                 make_octahedron_sphere(),
                                 make_coarse_curved_strip()}) {
    const auto first = directional::geometry::surface_cell_tracing_detail::
        classify_source_surface_labels(mesh.vertices, mesh.faces);
    const auto second = directional::geometry::surface_cell_tracing_detail::
        classify_source_surface_labels(mesh.vertices, mesh.faces);
    ASSERT_EQ(static_cast<std::size_t>(mesh.faces.rows()),
              first.componentByFace.size());
    ASSERT_EQ(static_cast<std::size_t>(mesh.faces.rows()),
              first.localSheetByFace.size());
    EXPECT_TRUE(std::all_of(first.componentByFace.begin(),
                            first.componentByFace.end(),
                            [](const int label) { return label >= 0; }));
    EXPECT_TRUE(std::all_of(first.localSheetByFace.begin(),
                            first.localSheetByFace.end(),
                            [](const int label) { return label >= 0; }));
    EXPECT_EQ(source_label_hash(first), source_label_hash(second));
  }
  const auto stripLabels =
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(make_coarse_curved_strip().vertices,
                                         make_coarse_curved_strip().faces);
  EXPECT_TRUE(std::all_of(
      stripLabels.localSheetByFace.begin(), stripLabels.localSheetByFace.end(),
      [&](const int label) {
        return label == stripLabels.localSheetByFace.front();
      }));
}

TEST(SurfaceCellTracingPhase14,
     SourceClassifierFailsClosedOnInvalidTopologyAndPolicy) {
  MeshFixture nonManifold;
  nonManifold.vertices.resize(5, 3);
  nonManifold.vertices << 0.0, 0.0, 0.0,
                          1.0, 0.0, 0.0,
                          0.0, 1.0, 0.0,
                          0.0, -1.0, 0.0,
                          0.0, 0.0, 1.0;
  nonManifold.faces.resize(3, 3);
  nonManifold.faces << 0, 1, 2,
                       1, 0, 3,
                       1, 0, 4;
  EXPECT_THROW(
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(nonManifold.vertices,
                                         nonManifold.faces),
      std::invalid_argument);

  MeshFixture inconsistent = nonManifold;
  inconsistent.faces.resize(2, 3);
  inconsistent.faces << 0, 1, 2,
                        0, 1, 3;
  EXPECT_THROW(
      directional::geometry::surface_cell_tracing_detail::
          classify_source_surface_labels(inconsistent.vertices,
                                         inconsistent.faces),
      std::invalid_argument);

  directional::geometry::SourceSurfaceClassifierOptions invalid;
  invalid.normalCompatibility = -0.01;
  EXPECT_FALSE(directional::geometry::surface_cell_tracing_detail::
                   source_surface_classifier_options_valid(invalid));
  invalid = {};
  invalid.closeSheetRadiusMeanEdges = 0.0;
  EXPECT_FALSE(directional::geometry::surface_cell_tracing_detail::
                   source_surface_classifier_options_valid(invalid));
  invalid = {};
  invalid.geodesicExclusionDepth = 65;
  EXPECT_FALSE(directional::geometry::surface_cell_tracing_detail::
                   source_surface_classifier_options_valid(invalid));
}
