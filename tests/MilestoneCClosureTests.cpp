#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::FlowRepArc;
using directional::geometry::FlowRepCoverageSample;
using directional::geometry::FlowRepCycleInput;
using directional::geometry::SurfaceCellTracingOptions;
using directional::geometry::SurfaceTracePoint;
using directional::geometry::SurfaceTraceSeed;
using directional::geometry::TraceTerminationReason;

constexpr double kPi = 3.141592653589793238462643383279502884;

struct MeshFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

MeshFixture make_open_cylinder(const int segments, const int axialCells,
                               const double radius = 1.0,
                               const double height = 2.0) {
  MeshFixture mesh;
  mesh.vertices.resize((axialCells + 1) * segments, 3);
  for (int ring = 0; ring <= axialCells; ++ring) {
    const double z = height * static_cast<double>(ring) /
                     static_cast<double>(axialCells);
    for (int segment = 0; segment < segments; ++segment) {
      const double angle =
          2.0 * kPi * static_cast<double>(segment) /
          static_cast<double>(segments);
      const int vertex = ring * segments + segment;
      mesh.vertices.row(vertex) << radius * std::cos(angle),
          radius * std::sin(angle), z;
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

MeshFixture make_torus(const int majorSegments, const int minorSegments,
                       const double majorRadius = 2.0,
                       const double minorRadius = 0.5,
                       const double zOffset = 0.0) {
  MeshFixture mesh;
  mesh.vertices.resize(majorSegments * minorSegments, 3);
  for (int u = 0; u < majorSegments; ++u) {
    const double majorAngle =
        2.0 * kPi * static_cast<double>(u) /
        static_cast<double>(majorSegments);
    for (int v = 0; v < minorSegments; ++v) {
      const double minorAngle =
          2.0 * kPi * static_cast<double>(v) /
          static_cast<double>(minorSegments);
      const double radial = majorRadius + minorRadius * std::cos(minorAngle);
      const int vertex = u * minorSegments + v;
      mesh.vertices.row(vertex) << radial * std::cos(majorAngle),
          radial * std::sin(majorAngle),
          zOffset + minorRadius * std::sin(minorAngle);
    }
  }

  mesh.faces.resize(2 * majorSegments * minorSegments, 3);
  int face = 0;
  for (int u = 0; u < majorSegments; ++u) {
    const int nextU = (u + 1) % majorSegments;
    for (int v = 0; v < minorSegments; ++v) {
      const int nextV = (v + 1) % minorSegments;
      const int v00 = u * minorSegments + v;
      const int v10 = nextU * minorSegments + v;
      const int v01 = u * minorSegments + nextV;
      const int v11 = nextU * minorSegments + nextV;
      mesh.faces.row(face++) << v00, v10, v11;
      mesh.faces.row(face++) << v00, v11, v01;
    }
  }
  return mesh;
}

void torus_axes(const MeshFixture &mesh, Eigen::MatrixXd &axisU,
                Eigen::MatrixXd &axisV) {
  axisU.resize(mesh.faces.rows(), 3);
  axisV.resize(mesh.faces.rows(), 3);
  for (int face = 0; face < mesh.faces.rows(); ++face) {
    Eigen::RowVector3d center = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      center += mesh.vertices.row(mesh.faces(face, corner));
    }
    center /= 3.0;

    Eigen::RowVector3d majorTangent(-center.y(), center.x(), 0.0);
    majorTangent.normalize();

    const Eigen::RowVector3d a =
        mesh.vertices.row(mesh.faces(face, 1)) -
        mesh.vertices.row(mesh.faces(face, 0));
    const Eigen::RowVector3d b =
        mesh.vertices.row(mesh.faces(face, 2)) -
        mesh.vertices.row(mesh.faces(face, 0));
    Eigen::RowVector3d normal = a.cross(b);
    normal.normalize();

    Eigen::RowVector3d minorTangent = normal.cross(majorTangent);
    minorTangent.normalize();
    axisU.row(face) = majorTangent;
    axisV.row(face) = minorTangent;
  }
}

Eigen::RowVector3d point_position(const MeshFixture &mesh,
                                  const SurfaceTracePoint &point) {
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 3; ++corner) {
    position += point.barycentric[corner] *
                mesh.vertices.row(mesh.faces(point.face, corner));
  }
  return position;
}

FlowRepArc embedded_arc_from_trace(
    const MeshFixture &mesh,
    const directional::geometry::SurfaceTraceSegment &segment,
    const int id, const int boundarySegment) {
  FlowRepArc arc;
  arc.id = id;
  arc.sourceFace = segment.face;
  arc.startBarycentric = segment.startBarycentric;
  arc.endBarycentric = segment.endBarycentric;
  arc.start = Eigen::RowVector3d::Zero();
  arc.end = Eigen::RowVector3d::Zero();
  for (int corner = 0; corner < 3; ++corner) {
    arc.start += segment.startBarycentric[corner] *
                 mesh.vertices.row(mesh.faces(segment.face, corner));
    arc.end += segment.endBarycentric[corner] *
               mesh.vertices.row(mesh.faces(segment.face, corner));
  }
  arc.sourceComponent = 0;
  arc.sourceSheet = 0;
  arc.family = segment.family;
  arc.strandProvenance = 0;
  arc.proposalId = 0;
  arc.proposalSeedId = 0;
  arc.proposalSide = 0;
  arc.proposalBoundarySegment = boundarySegment;
  return arc;
}

FlowRepArc square_arc(const int id, const Eigen::RowVector3d &start,
                      const Eigen::RowVector3d &end, const int side) {
  FlowRepArc arc;
  arc.id = id;
  arc.start = start;
  arc.end = end;
  arc.sourceFace = 0;
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
  arc.strandProvenance = 0;
  arc.proposalId = 0;
  arc.proposalSeedId = 0;
  arc.proposalSide = side;
  arc.proposalBoundarySegment = 0;
  return arc;
}

FlowRepCoverageSample coverage_sample(const FlowRepArc &arc) {
  FlowRepCoverageSample sample;
  sample.position = 0.5 * (arc.start + arc.end);
  sample.sourceFace = arc.sourceFace;
  sample.barycentric =
      0.5 * (arc.startBarycentric + arc.endBarycentric);
  sample.sourceComponent = arc.sourceComponent;
  sample.sourceSheet = arc.sourceSheet;
  sample.targetSize = 1.0;
  sample.sourceArcId = arc.id;
  return sample;
}

FlowRepCycleInput square_cycle() {
  FlowRepCycleInput cycle;
  cycle.id = 0;
  cycle.proposalId = 0;
  cycle.sideArcIds = {{0}, {1}, {2}, {3}};
  cycle.boundaryArcIds = {0, 1, 2, 3};
  cycle.sideCounts = {1, 1, 1, 1};
  cycle.targetSize = 1.0;
  for (int i = 0; i < 8; ++i) {
    cycle.normals.emplace_back(0.0, 0.0, 1.0);
    cycle.boundaryNormalA.emplace_back(0.0, 0.0, 1.0);
    cycle.boundaryNormalB.emplace_back(0.0, 0.0, 1.0);
    cycle.distanceA.push_back(1.0);
    cycle.distanceB.push_back(1.0);
    cycle.surfaceDistances.push_back(0.01);
  }
  return cycle;
}

TEST(MilestoneCClosure, CylinderPeriodicTraceProducesClosedEmbeddedFlowline) {
  const MeshFixture mesh = make_open_cylinder(16, 2);
  Eigen::MatrixXd axisU;
  Eigen::MatrixXd axisV;
  cylinder_axes(mesh, axisU, axisV);

  SurfaceTraceSeed seed;
  seed.id = 0;
  seed.point.face = 0;
  seed.point.barycentric << 0.23, 0.31, 0.46;

  SurfaceCellTracingOptions options;
  options.maxTraceLength = 4.0 * kPi;
  options.maxTraceSegments = 1024;
  options.defaultTargetSize = 0.4;

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, axisU, axisV, seed, 0, 1, options);

  ASSERT_EQ(trace.termination, TraceTerminationReason::RepeatedState);
  ASSERT_GT(trace.segments.size(), 16U);
  ASSERT_EQ(trace.states.size(), trace.segments.size() + 1U);

  bool crossedPeriodicSeam = false;
  for (std::size_t i = 1; i < trace.segments.size(); ++i) {
    const int previousFace = trace.segments[i - 1].face;
    const int currentFace = trace.segments[i].face;
    if (previousFace >= 2 * (16 - 1) && currentFace <= 1) {
      crossedPeriodicSeam = true;
      break;
    }
  }
  EXPECT_TRUE(crossedPeriodicSeam);

  const auto repeated =
      std::find(trace.states.begin(), trace.states.end() - 1,
                trace.states.back());
  ASSERT_NE(repeated, trace.states.end() - 1);
  const std::size_t loopStart =
      static_cast<std::size_t>(std::distance(trace.states.begin(), repeated));

  std::vector<FlowRepArc> loopArcs;
  std::vector<int> loopArcIds;
  for (std::size_t segment = loopStart; segment < trace.segments.size();
       ++segment) {
    const int id = static_cast<int>(loopArcs.size());
    loopArcs.push_back(embedded_arc_from_trace(
        mesh, trace.segments[segment], id, id));
    loopArcIds.push_back(id);
  }

  const auto flowlines =
      directional::geometry::flow_rep_detail::extract_transactional_flowlines(
          loopArcs, loopArcIds);
  ASSERT_EQ(flowlines.size(), 1U);
  EXPECT_TRUE(flowlines.front().closed);
  EXPECT_EQ(flowlines.front().arcIds.size(), loopArcs.size());
}

TEST(MilestoneCClosure,
     TorusTraceCapturesCompatibleNodeAndIgnoresCloseOtherSheet) {
  constexpr int kMajorSegments = 16;
  constexpr int kMinorSegments = 8;
  const MeshFixture primary = make_torus(kMajorSegments, kMinorSegments);
  const MeshFixture decoy =
      make_torus(kMajorSegments, kMinorSegments, 2.0, 0.5, 0.02);

  MeshFixture mesh;
  mesh.vertices.resize(primary.vertices.rows() + decoy.vertices.rows(), 3);
  mesh.vertices.topRows(primary.vertices.rows()) = primary.vertices;
  mesh.vertices.bottomRows(decoy.vertices.rows()) = decoy.vertices;
  mesh.faces.resize(primary.faces.rows() + decoy.faces.rows(), 3);
  mesh.faces.topRows(primary.faces.rows()) = primary.faces;
  mesh.faces.bottomRows(decoy.faces.rows()) =
      (decoy.faces.array() + primary.vertices.rows()).matrix();

  Eigen::MatrixXd primaryU;
  Eigen::MatrixXd primaryV;
  Eigen::MatrixXd decoyU;
  Eigen::MatrixXd decoyV;
  torus_axes(primary, primaryU, primaryV);
  torus_axes(decoy, decoyU, decoyV);
  Eigen::MatrixXd axisU(mesh.faces.rows(), 3);
  Eigen::MatrixXd axisV(mesh.faces.rows(), 3);
  axisU.topRows(primaryU.rows()) = primaryU;
  axisU.bottomRows(decoyU.rows()) = decoyU;
  axisV.topRows(primaryV.rows()) = primaryV;
  axisV.bottomRows(decoyV.rows()) = decoyV;

  SurfaceTraceSeed seed;
  seed.id = 0;
  seed.point.face = 0;
  seed.point.barycentric << 0.2, 0.3, 0.5;

  const int targetFace =
      2 * ((kMajorSegments / 2) * kMinorSegments);
  SurfaceTracePoint target;
  target.face = targetFace;
  target.barycentric << 1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0;
  SurfaceTracePoint closeDecoy = target;
  closeDecoy.face += primary.faces.rows();

  SurfaceCellTracingOptions options;
  options.maxTraceLength = 5.0 * kPi;
  options.maxTraceSegments = 2048;
  options.captureRadius = 0.35;
  options.capturePoints = {closeDecoy, target};
  options.sourceFaceComponents.assign(mesh.faces.rows(), 0);
  options.sourceFaceSheets.assign(mesh.faces.rows(), 0);
  std::fill(options.sourceFaceSheets.begin() + primary.faces.rows(),
            options.sourceFaceSheets.end(), 1);

  const auto trace = directional::geometry::trace_surface_field(
      mesh.vertices, mesh.faces, axisU, axisV, seed, 0, 1, options);

  ASSERT_EQ(trace.termination, TraceTerminationReason::Captured);
  ASSERT_FALSE(trace.segments.empty());
  EXPECT_EQ(trace.segments.back().face, target.face);

  SurfaceTracePoint endpoint;
  endpoint.face = trace.segments.back().face;
  endpoint.barycentric = trace.segments.back().endBarycentric;
  EXPECT_NEAR((point_position(mesh, endpoint) -
               point_position(mesh, target))
                  .norm(),
              0.0, 1.0e-10);
  EXPECT_GT((point_position(mesh, endpoint) -
             point_position(mesh, closeDecoy))
                .norm(),
            1.0e-3);
}

TEST(MilestoneCClosure, FlowRepRetainsClosedCycleForDownstreamCells) {
  std::vector<FlowRepArc> arcs = {
      square_arc(0, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0),
      square_arc(1, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, 1),
      square_arc(2, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 2),
      square_arc(3, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, 3),
  };
  std::vector<FlowRepCoverageSample> samples;
  for (const FlowRepArc &arc : arcs) {
    samples.push_back(coverage_sample(arc));
  }

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});

  ASSERT_TRUE(network.selectionSucceeded);
  EXPECT_TRUE(network.coverageEvidenceUsed);
  EXPECT_TRUE(network.cycleEvidenceUsed);
  EXPECT_EQ(network.cycleEvidenceCount, 1);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
  ASSERT_EQ(network.cycleEvaluations.size(), 1U);
  EXPECT_TRUE(network.cycleEvaluations.front().descriptive);
  EXPECT_TRUE(network.cycleEvaluations.front().quadrangulable);
}

} // namespace
