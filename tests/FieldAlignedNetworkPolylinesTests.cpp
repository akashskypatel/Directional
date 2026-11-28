#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/FieldAlignedNetworkPolylines.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

struct ProducedNetwork {
  std::string fixture;
  directional::TriMesh mesh;
  Eigen::MatrixXd raw;
  std::optional<directional::geometry::FieldAlignedCurveNetwork> network;
};

Eigen::MatrixXd read_rawfield(const std::filesystem::path &path,
                              const int expectedFaces) {
  std::ifstream stream(path);
  int degree = 0;
  int faceCount = 0;
  if (!stream || !(stream >> degree >> faceCount) || degree != 4 ||
      faceCount != expectedFaces) {
    throw std::runtime_error("Invalid rawfield fixture: " + path.string());
  }
  Eigen::MatrixXd raw(faceCount, 3 * degree);
  for (int face = 0; face < faceCount; ++face) {
    for (int column = 0; column < raw.cols(); ++column) {
      if (!(stream >> raw(face, column))) {
        throw std::runtime_error("Invalid rawfield payload: " + path.string());
      }
    }
  }
  return raw;
}

// The first committed fixture whose A2a network has a multi-segment trace and
// a singularity port, so every check below is non-vacuous.
const ProducedNetwork &produced_network() {
  static const std::optional<ProducedNetwork> cached = [] {
    std::string rejected;
    for (const std::string name :
         {"sphere_prescribed", "genus_two", "close_sheets", "cylinder"}) {
      ProducedNetwork candidate;
      candidate.fixture = name;
      const auto meshPath = directional::tests::benchmark_fixture_path(
          "milestone-g/" + name + ".obj");
      if (!directional::readOBJ(meshPath.string(), candidate.mesh)) {
        rejected += name + ":unreadable ";
        continue;
      }
      candidate.raw = read_rawfield(
          directional::tests::benchmark_fixture_path("milestone-g/" + name +
                                                     ".rawfield"),
          static_cast<int>(candidate.mesh.F.rows()));

      directional::pipeline::RemeshOptions options;
      options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
      options.surfaceCells.enabled = true;
      options.surfaceCells.fallbackPolicy =
          directional::pipeline::SurfaceCellFallbackPolicy::Fail;
      options.surfaceCells.allowSourceGridRecovery = false;
      options.surfaceCells.retainIntermediateGeometry = true;
      options.parallelizeComponents = false;
      const auto result = directional::pipeline::remesh_from_raw_cross_field(
          candidate.mesh.V, candidate.mesh.F, candidate.raw, options);
      const auto &snapshot =
          result.surfaceCellContext.productSnapshots.fieldAlignedCurveNetwork;
      if (!snapshot.has_value()) {
        rejected += name + ":" + result.diagnostics.terminalFailureStage + " ";
        continue;
      }
      const bool multiSegment = std::any_of(
          snapshot->candidate_traces().begin(),
          snapshot->candidate_traces().end(),
          [](const auto &trace) { return trace.segments.size() >= 2U; });
      if (!multiSegment || snapshot->singularity_ports().empty()) {
        rejected += name + ":trivial-network ";
        continue;
      }
      candidate.network = *snapshot;
      return std::optional<ProducedNetwork>(std::move(candidate));
    }
    ADD_FAILURE() << "no committed fixture published a non-trivial A2a "
                     "network: "
                  << rejected;
    return std::optional<ProducedNetwork>();
  }();
  if (!cached.has_value()) {
    throw std::runtime_error("no produced A2a network fixture");
  }
  return *cached;
}

std::optional<Eigen::Index> face_row_for_key(
    const Eigen::MatrixXi &F,
    const directional::authority::SourceFaceTopologyKey &key) {
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    std::array<std::size_t, 3> sorted{static_cast<std::size_t>(F(face, 0)),
                                      static_cast<std::size_t>(F(face, 1)),
                                      static_cast<std::size_t>(F(face, 2))};
    std::sort(sorted.begin(), sorted.end());
    if (sorted[0] == key.vertices()[0].index() &&
        sorted[1] == key.vertices()[1].index() &&
        sorted[2] == key.vertices()[2].index()) {
      return face;
    }
  }
  return std::nullopt;
}

} // namespace

TEST(FieldAlignedNetworkPolylines, ProducedTracesFollowTheInputField) {
  const ProducedNetwork &produced = produced_network();
  const auto polylines = directional::visualization::field_aligned_network_polylines(
      produced.mesh.V, (*produced.network));
  const auto &traces = (*produced.network).candidate_traces();

  std::size_t expectedSegments = 0;
  for (const auto &trace : traces) expectedSegments += trace.segments.size();
  EXPECT_EQ(traces.size(), polylines.traceCount) << produced.fixture;
  EXPECT_EQ(expectedSegments, polylines.segmentCount) << produced.fixture;
  ASSERT_GT(polylines.traceEdges.rows(), 0) << produced.fixture;
  ASSERT_EQ(polylines.traceEdges.rows(), polylines.traceEdgeTrace.size());
  ASSERT_TRUE(polylines.tracePoints.allFinite());

  // Edges join consecutive points of one trace, in trace order.
  for (Eigen::Index edge = 0; edge < polylines.traceEdges.rows(); ++edge) {
    EXPECT_EQ(polylines.traceEdges(edge, 0) + 1, polylines.traceEdges(edge, 1));
    ASSERT_LT(polylines.traceEdges(edge, 1), polylines.tracePoints.rows());
    if (edge > 0 &&
        polylines.traceEdgeTrace(edge) == polylines.traceEdgeTrace(edge - 1)) {
      EXPECT_EQ(polylines.traceEdges(edge - 1, 1), polylines.traceEdges(edge, 0));
    }
  }

  // Independent oracle: inside each face, a trace runs along one of the four
  // raw input directions. A flipped edge parameter would bend the polyline
  // off the field.
  const double scale =
      (produced.mesh.V.colwise().maxCoeff() - produced.mesh.V.colwise().minCoeff())
          .norm();
  std::size_t checkedSegments = 0;
  for (const auto &trace : traces) {
    for (std::size_t index = 0; index < trace.segments.size(); ++index) {
      const auto &segment = trace.segments[index];
      if (segment.edgeTransitExit.has_value()) continue;
      const auto position = [&](const directional::authority::FieldBoundaryPoint &point) {
        const double t = static_cast<double>(point.parameter.value.to_double());
        return Eigen::RowVector3d(
            (1.0 - t) * produced.mesh.V.row(point.edge.first().index()) +
            t * produced.mesh.V.row(point.edge.second().index()));
      };
      std::optional<Eigen::RowVector3d> exit;
      if (index + 1 < trace.segments.size()) {
        exit = position(trace.segments[index + 1].entryPoint);
      } else if (trace.terminalPoint.has_value() &&
                 !trace.terminalContact.has_value() &&
                 !trace.terminalSingularity.has_value() &&
                 !trace.terminalLimitCycle.has_value()) {
        exit = position(*trace.terminalPoint);
      }
      if (!exit.has_value()) continue;
      const Eigen::RowVector3d entry = index == 0
          ? Eigen::RowVector3d(produced.mesh.V.row(trace.sourceVertex.index()))
          : position(segment.entryPoint);
      const Eigen::RowVector3d step = *exit - entry;
      if (step.norm() <= 1e-9 * scale) continue;
      const auto row = face_row_for_key(produced.mesh.F, segment.sourceFace);
      ASSERT_TRUE(row.has_value()) << produced.fixture;
      double best = 0.0;
      for (int direction = 0; direction < 4; ++direction) {
        const Eigen::RowVector3d field =
            produced.raw.block(*row, 3 * direction, 1, 3);
        best = std::max(best, field.normalized().dot(step.normalized()));
      }
      EXPECT_GT(best, 0.99) << produced.fixture << " trace " << trace.id.index()
                            << " segment " << index;
      ++checkedSegments;
    }
  }
  EXPECT_GT(checkedSegments, 0U) << produced.fixture;
  RecordProperty("fixture", produced.fixture);
  RecordProperty("traces", static_cast<int>(polylines.traceCount));
  RecordProperty("segments", static_cast<int>(polylines.segmentCount));
  RecordProperty("fieldCheckedSegments", static_cast<int>(checkedSegments));
  RecordProperty("singularities",
                 static_cast<int>(polylines.singularityPoints.rows()));
  RecordProperty("mandatoryEdges",
                 static_cast<int>(polylines.mandatoryEdges.rows()));

  // The adapter's points are exactly that field-checked reconstruction, in
  // trace order: source vertex, entries, transit exits, then the terminal.
  const auto point_at = [&](const directional::authority::FieldBoundaryPoint &point) {
    const double t = static_cast<double>(point.parameter.value.to_double());
    return Eigen::RowVector3d(
        (1.0 - t) * produced.mesh.V.row(point.edge.first().index()) +
        t * produced.mesh.V.row(point.edge.second().index()));
  };
  std::vector<Eigen::RowVector3d> expected;
  for (const auto &trace : traces) {
    std::vector<Eigen::RowVector3d> polyline{
        Eigen::RowVector3d(produced.mesh.V.row(trace.sourceVertex.index()))};
    const auto append = [&polyline](const Eigen::RowVector3d &point) {
      if (polyline.back() != point) polyline.push_back(point);
    };
    for (const auto &segment : trace.segments) {
      append(point_at(segment.entryPoint));
      if (segment.edgeTransitExit.has_value()) {
        append(point_at(*segment.edgeTransitExit));
      }
    }
    if (trace.terminalContact.has_value()) {
      Eigen::RowVector3d contact = Eigen::RowVector3d::Zero();
      for (std::size_t corner = 0; corner < 3; ++corner) {
        contact += static_cast<double>(
                       trace.terminalContact->barycentric[corner].to_double()) *
                   produced.mesh.V.row(
                       trace.terminalContact->sourceFace.vertices()[corner].index());
      }
      append(contact);
    } else if (trace.terminalSingularity.has_value()) {
      for (const auto &port : (*produced.network).singularity_ports()) {
        if (port.singularity == *trace.terminalSingularity) {
          append(produced.mesh.V.row(port.sourceVertex.index()));
          break;
        }
      }
    } else if (trace.terminalLimitCycle.has_value()) {
      append(point_at(trace.terminalLimitCycle->entryPoint));
    } else if (trace.terminalPoint.has_value()) {
      append(point_at(*trace.terminalPoint));
    }
    expected.insert(expected.end(), polyline.begin(), polyline.end());
  }
  ASSERT_EQ(static_cast<Eigen::Index>(expected.size()),
            polylines.tracePoints.rows());
  for (std::size_t row = 0; row < expected.size(); ++row) {
    EXPECT_LE((polylines.tracePoints.row(static_cast<Eigen::Index>(row)) -
               expected[row]).norm(),
              1e-12 * scale)
        << produced.fixture << " point " << row;
  }

  // Singularity markers sit on their published port vertices.
  ASSERT_GT(polylines.singularityPoints.rows(), 0) << produced.fixture;
  for (Eigen::Index row = 0; row < polylines.singularityPoints.rows(); ++row) {
    const bool onPort = std::any_of(
        (*produced.network).singularity_ports().begin(),
        (*produced.network).singularity_ports().end(), [&](const auto &port) {
          return polylines.singularityPoints.row(row) ==
                 produced.mesh.V.row(port.sourceVertex.index());
        });
    EXPECT_TRUE(onPort) << produced.fixture << " singularity " << row;
  }
}

TEST(FieldAlignedNetworkPolylines, RejectsVerticesThatDoNotCoverTheNetwork) {
  const ProducedNetwork &produced = produced_network();
  const Eigen::MatrixXd truncated = produced.mesh.V.topRows(1);
  EXPECT_THROW(directional::visualization::field_aligned_network_polylines(
                   truncated, (*produced.network)),
               std::invalid_argument);
  const Eigen::MatrixXd planar = produced.mesh.V.leftCols(2);
  EXPECT_THROW(directional::visualization::field_aligned_network_polylines(
                   planar, (*produced.network)),
               std::invalid_argument);
}
