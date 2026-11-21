// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/FieldAlignedNetworkPolylines.h>

#include <array>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace directional::visualization {
namespace {

Eigen::RowVector3d vertex_position(const Eigen::MatrixXd &V,
                                   const authority::SourceVertexId vertex) {
  const std::size_t row = vertex.index();
  if (row >= static_cast<std::size_t>(V.rows())) {
    throw std::invalid_argument("A2a network vertex " + std::to_string(row) +
                                " is outside the source vertices.");
  }
  return V.row(static_cast<Eigen::Index>(row));
}

Eigen::RowVector3d boundary_point_position(
    const Eigen::MatrixXd &V, const authority::FieldBoundaryPoint &point) {
  if (!point.parameter.in_unit_interval()) {
    throw std::invalid_argument(
        "A2a network edge parameter is outside [0, 1].");
  }
  const double t = static_cast<double>(point.parameter.value.to_double());
  return (1.0 - t) * vertex_position(V, point.edge.first()) +
         t * vertex_position(V, point.edge.second());
}

Eigen::RowVector3d contact_position(
    const Eigen::MatrixXd &V,
    const geometry::FieldAlignedTerminalContact &contact) {
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  const auto &vertices = contact.sourceFace.vertices();
  Eigen::RowVector3d position = Eigen::RowVector3d::Zero();
  for (std::size_t corner = 0; corner < vertices.size(); ++corner) {
    const auto &weight = contact.barycentric[corner];
    if (weight < zero || weight > one) {
      throw std::invalid_argument(
          "A2a network contact barycentric is outside [0, 1].");
    }
    position += static_cast<double>(weight.to_double()) *
                vertex_position(V, vertices[corner]);
  }
  return position;
}

} // namespace

FieldAlignedNetworkPolylines field_aligned_network_polylines(
    const Eigen::MatrixXd &V, const geometry::FieldAlignedCurveNetwork &network) {
  if (V.cols() != 3) {
    throw std::invalid_argument("Source vertices must be an n x 3 matrix.");
  }

  std::map<authority::FieldSingularityId, const geometry::FieldAlignedSingularityPort *>
      portBySingularity;
  for (const auto &port : network.singularity_ports()) {
    portBySingularity.emplace(port.singularity, &port);
  }

  FieldAlignedNetworkPolylines result;
  std::vector<Eigen::RowVector3d> points;
  std::vector<std::array<int, 2>> edges;
  std::vector<int> edgeTrace;
  std::vector<int> edgeTerminal;

  const auto &traces = network.candidate_traces();
  for (std::size_t ordinal = 0; ordinal < traces.size(); ++ordinal) {
    const geometry::FieldAlignedCandidateTrace &trace = traces[ordinal];
    std::vector<Eigen::RowVector3d> polyline;
    // Consecutive duplicates appear where a segment's entry point is the
    // trace's own source vertex; they would only add zero-length edges.
    const auto append = [&polyline](const Eigen::RowVector3d &point) {
      if (polyline.empty() || polyline.back() != point) {
        polyline.push_back(point);
      }
    };

    append(vertex_position(V, trace.sourceVertex));
    for (const auto &segment : trace.segments) {
      append(boundary_point_position(V, segment.entryPoint));
      if (segment.edgeTransitExit.has_value()) {
        append(boundary_point_position(V, *segment.edgeTransitExit));
      }
    }

    FieldAlignedNetworkTerminal terminal = FieldAlignedNetworkTerminal::Open;
    if (trace.terminalContact.has_value()) {
      append(contact_position(V, *trace.terminalContact));
      terminal = FieldAlignedNetworkTerminal::Contact;
    } else if (trace.terminalSingularity.has_value()) {
      const auto port = portBySingularity.find(*trace.terminalSingularity);
      if (port == portBySingularity.end()) {
        throw std::invalid_argument(
            "A2a network trace ends at a singularity with no published port.");
      }
      append(vertex_position(V, port->second->sourceVertex));
      terminal = FieldAlignedNetworkTerminal::Singularity;
    } else if (trace.terminalLimitCycle.has_value()) {
      append(boundary_point_position(V, trace.terminalLimitCycle->entryPoint));
      terminal = FieldAlignedNetworkTerminal::LimitCycle;
    } else if (trace.terminalPoint.has_value()) {
      append(boundary_point_position(V, *trace.terminalPoint));
      terminal = FieldAlignedNetworkTerminal::Barrier;
    }

    const int first = static_cast<int>(points.size());
    points.insert(points.end(), polyline.begin(), polyline.end());
    for (std::size_t index = 1; index < polyline.size(); ++index) {
      const int to = first + static_cast<int>(index);
      edges.push_back({to - 1, to});
      edgeTrace.push_back(static_cast<int>(ordinal));
      edgeTerminal.push_back(static_cast<int>(terminal));
    }
    result.segmentCount += trace.segments.size();
  }
  result.traceCount = traces.size();

  result.tracePoints.resize(static_cast<Eigen::Index>(points.size()), 3);
  for (std::size_t row = 0; row < points.size(); ++row) {
    result.tracePoints.row(static_cast<Eigen::Index>(row)) = points[row];
  }
  if (!result.tracePoints.allFinite()) {
    throw std::invalid_argument("A2a network produced a non-finite point.");
  }
  result.traceEdges.resize(static_cast<Eigen::Index>(edges.size()), 2);
  result.traceEdgeTrace.resize(static_cast<Eigen::Index>(edges.size()));
  result.traceEdgeTerminal.resize(static_cast<Eigen::Index>(edges.size()));
  for (std::size_t row = 0; row < edges.size(); ++row) {
    const auto index = static_cast<Eigen::Index>(row);
    result.traceEdges(index, 0) = edges[row][0];
    result.traceEdges(index, 1) = edges[row][1];
    result.traceEdgeTrace(index) = edgeTrace[row];
    result.traceEdgeTerminal(index) = edgeTerminal[row];
  }

  const auto &mandatory = network.mandatory_edges();
  result.mandatoryPoints.resize(2 * static_cast<Eigen::Index>(mandatory.size()), 3);
  result.mandatoryEdges.resize(static_cast<Eigen::Index>(mandatory.size()), 2);
  for (std::size_t row = 0; row < mandatory.size(); ++row) {
    const auto index = static_cast<Eigen::Index>(row);
    result.mandatoryPoints.row(2 * index) =
        vertex_position(V, mandatory[row].sourceEdge.first());
    result.mandatoryPoints.row(2 * index + 1) =
        vertex_position(V, mandatory[row].sourceEdge.second());
    result.mandatoryEdges(index, 0) = static_cast<int>(2 * index);
    result.mandatoryEdges(index, 1) = static_cast<int>(2 * index + 1);
  }

  result.singularityPoints.resize(
      static_cast<Eigen::Index>(portBySingularity.size()), 3);
  result.singularityIndex.resize(
      static_cast<Eigen::Index>(portBySingularity.size()));
  Eigen::Index singularityRow = 0;
  for (const auto &[singularity, port] : portBySingularity) {
    (void)singularity;
    result.singularityPoints.row(singularityRow) =
        vertex_position(V, port->sourceVertex);
    result.singularityIndex(singularityRow) = port->indexNumerator;
    ++singularityRow;
  }
  return result;
}

} // namespace directional::visualization
