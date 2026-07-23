// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H
#define DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::geometry {

enum class SurfaceArrangementCellClass : int {
  Exterior = 0,
  RegularQuad = 1,
  PatchCandidate = 2,
  NonDisk = 3,
};

enum class SurfaceArrangementRejectReason : int {
  None = 0,
  NonAlternatingFamilies = 1,
  NotFourSided = 2,
  OddBoundaryParity = 3,
  HardFeatureCrossing = 4,
  Sliver = 5,
};

struct SurfaceArrangementOptions {
  bool insertBoundaryRails = true;
  std::set<std::uint64_t> hardFeatureEdges;
};

struct SurfaceArrangementArc {
  int id = -1;
  int sourceFace = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  int family = 0;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  int provenance = -1;
};

struct SurfaceArrangementNode {
  int id = -1;
  int sourceFace = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  int sourceEdge = -1;
  double sourceEdgeParameter = 0.0;
};

struct SurfaceArrangementHalfedge {
  int id = -1;
  int twin = -1;
  int next = -1;
  int from = -1;
  int to = -1;
  int sourceArc = -1;
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  int sourceFace = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
  bool hardFeature = false;
  int cell = -1;
};

struct SurfaceArrangementCell {
  int id = -1;
  int sourceFace = -1;
  std::vector<int> halfedges;
  std::vector<int> sideFamilies;
  std::vector<int> sideEdgeCounts;
  double signedArea = 0.0;
  double area = 0.0;
  bool boundaryCycle = false;
  bool disk = true;
  bool quadReady = false;
  SurfaceArrangementCellClass cellClass =
      SurfaceArrangementCellClass::PatchCandidate;
  SurfaceArrangementRejectReason rejectReason =
      SurfaceArrangementRejectReason::None;
};

struct SurfaceArrangementDiagnostics {
  int plantedIntersections = 0;
  int uniqueIntersections = 0;
  int unsplitCrossings = 0;
  int geometricTJunctions = 0;
  int incompleteArcChains = 0;
  int hardBarrierCrossings = 0;
  int eulerCharacteristic = 0;
  int sourceEulerCharacteristic = 0;
  int peakSegmentsPerFace = 0;
  double supportedArea = 0.0;
  double extractedArea = 0.0;
  double relativeAreaError = 0.0;
  double memoryRatioEstimate = 0.0;
  double measuredMemoryRatio = 0.0;
};

struct SurfaceCellComplex {
  std::vector<SurfaceArrangementNode> nodes;
  std::vector<SurfaceArrangementHalfedge> halfedges;
  std::vector<SurfaceArrangementCell> cells;
  SurfaceArrangementDiagnostics diagnostics;
};

struct SurfaceArrangementOverlay {
  Eigen::MatrixXd splitSegmentStarts;
  Eigen::MatrixXd splitSegmentEnds;
  Eigen::VectorXi sideFamily;
  Eigen::VectorXi cellId;
  Eigen::VectorXi cellClass;
  Eigen::VectorXi sliverCycle;
  Eigen::VectorXi hardRailCrossing;
};

namespace surface_arrangement_detail {

struct Segment2 {
  int sourceArc = -1;
  int sourceFace = -1;
  Eigen::Vector2d start = Eigen::Vector2d::Zero();
  Eigen::Vector2d end = Eigen::Vector2d::Zero();
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
};

struct NodeKey {
  int kind = 2;
  int face = -1;
  std::int64_t edge = -1;
  std::int64_t edgeT = -1;
  int vertex = -1;
  std::int64_t u = 0;
  std::int64_t v = 0;

  bool operator<(const NodeKey &other) const {
    return std::tie(kind, vertex, edge, edgeT, face, u, v) <
           std::tie(other.kind, other.vertex, other.edge, other.edgeT,
                    other.face, other.u, other.v);
  }
};

inline double cross2(const Eigen::Vector2d &a, const Eigen::Vector2d &b) {
  return a.x() * b.y() - a.y() * b.x();
}

inline Eigen::Vector2d bary_to_uv(const Eigen::RowVector3d &bary) {
  return {bary[1], bary[2]};
}

inline Eigen::RowVector3d uv_to_bary(const Eigen::Vector2d &uv) {
  return {1.0 - uv.x() - uv.y(), uv.x(), uv.y()};
}

inline double triangle_area_3d(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const int face) {
  const Eigen::RowVector3d a = vertices.row(faces(face, 0));
  const Eigen::RowVector3d b = vertices.row(faces(face, 1));
  const Eigen::RowVector3d c = vertices.row(faces(face, 2));
  return 0.5 * surface_cell_tracing_detail::cross3(b - a, c - a).norm();
}

inline int source_edge(const Eigen::Vector2d &uv, const double eps = 1.0e-10) {
  const Eigen::RowVector3d bary = uv_to_bary(uv);
  for (int i = 0; i < 3; ++i) {
    if (std::abs(bary[i]) <= eps) {
      return i;
    }
  }
  return -1;
}

inline double edge_parameter(const Eigen::Vector2d &uv, const int edge) {
  const Eigen::RowVector3d b = uv_to_bary(uv);
  if (edge == 0) {
    const double denom = std::max(1.0e-20, b[1] + b[2]);
    return b[2] / denom;
  }
  if (edge == 1) {
    const double denom = std::max(1.0e-20, b[0] + b[2]);
    return b[0] / denom;
  }
  if (edge == 2) {
    const double denom = std::max(1.0e-20, b[0] + b[1]);
    return b[1] / denom;
  }
  return 0.0;
}

inline std::uint64_t source_edge_key(const Eigen::MatrixXi &faces,
                                     const int face, const int edge) {
  const int a = faces(face, (edge + 1) % 3);
  const int b = faces(face, (edge + 2) % 3);
  return surface_cell_tracing_detail::edge_key(a, b);
}

inline int source_vertex(const Eigen::RowVector3d &bary,
                         const double eps = 1.0e-10) {
  for (int i = 0; i < 3; ++i) {
    if (bary[i] >= 1.0 - eps) {
      return i;
    }
  }
  return -1;
}

inline NodeKey make_node_key(const Eigen::MatrixXi &faces, const int face,
                             const Eigen::Vector2d &uv) {
  const int edge = source_edge(uv);
  const double t = edge >= 0 ? edge_parameter(uv, edge) : -1.0;
  const Eigen::RowVector3d bary = uv_to_bary(uv);
  const int vertexCorner = source_vertex(bary);
  if (vertexCorner >= 0) {
    return {0, -1, -1, -1, faces(face, vertexCorner), 0, 0};
  }
  if (edge >= 0) {
    const std::uint64_t key = source_edge_key(faces, face, edge);
    return {1,
            -1,
            static_cast<std::int64_t>(key),
            static_cast<std::int64_t>(std::llround(t * 1.0e10)),
            -1,
            0,
            0};
  }
  return {2,
          face,
          -1,
          -1,
          -1,
          static_cast<std::int64_t>(std::llround(uv.x() * 1.0e10)),
          static_cast<std::int64_t>(std::llround(uv.y() * 1.0e10))};
}

inline int canonical_source_edge_id(const Eigen::MatrixXi &faces, const int face,
                                    const int edge) {
  if (edge < 0) {
    return -1;
  }
  return static_cast<int>(source_edge_key(faces, face, edge) & 0x7fffffffu);
}

inline bool clip_to_triangle(Eigen::Vector2d &a, Eigen::Vector2d &b,
                             double &ta, double &tb) {
  double lo = 0.0;
  double hi = 1.0;
  const Eigen::Vector2d d = b - a;
  const auto clip_lower = [&](const double value, const double delta) {
    if (std::abs(delta) <= 1.0e-14) {
      return value >= -1.0e-12;
    }
    const double t = -value / delta;
    if (delta > 0.0) {
      lo = std::max(lo, t);
    } else {
      hi = std::min(hi, t);
    }
    return lo <= hi + 1.0e-12;
  };
  if (!clip_lower(a.x(), d.x()) || !clip_lower(a.y(), d.y()) ||
      !clip_lower(1.0 - a.x() - a.y(), -d.x() - d.y())) {
    return false;
  }
  if (hi < -1.0e-12 || lo > 1.0 + 1.0e-12) {
    return false;
  }
  lo = std::clamp(lo, 0.0, 1.0);
  hi = std::clamp(hi, 0.0, 1.0);
  const Eigen::Vector2d oldA = a;
  const Eigen::Vector2d oldB = b;
  a = oldA + lo * (oldB - oldA);
  b = oldA + hi * (oldB - oldA);
  const double oldTa = ta;
  const double oldTb = tb;
  ta = oldTa + lo * (oldTb - oldTa);
  tb = oldTa + hi * (oldTb - oldTa);
  return (b - a).squaredNorm() > 1.0e-24;
}

inline bool segment_intersection_params(const Segment2 &a, const Segment2 &b,
                                        double &ta, double &tb,
                                        Eigen::Vector2d &point) {
  const Eigen::Vector2d r = a.end - a.start;
  const Eigen::Vector2d s = b.end - b.start;
  const double denom = cross2(r, s);
  const Eigen::Vector2d qp = b.start - a.start;
  if (std::abs(denom) <= 1.0e-12) {
    if (std::abs(cross2(qp, r)) > 1.0e-12) {
      return false;
    }
    const double rr = std::max(1.0e-20, r.squaredNorm());
    const double t0 = (b.start - a.start).dot(r) / rr;
    const double t1 = (b.end - a.start).dot(r) / rr;
    const double lo = std::max(0.0, std::min(t0, t1));
    const double hi = std::min(1.0, std::max(t0, t1));
    if (lo > hi + 1.0e-12) {
      return false;
    }
    ta = lo;
    point = a.start + ta * r;
    const double ss = std::max(1.0e-20, s.squaredNorm());
    tb = (point - b.start).dot(s) / ss;
    return true;
  }
  ta = cross2(qp, s) / denom;
  tb = cross2(qp, r) / denom;
  if (ta < -1.0e-12 || ta > 1.0 + 1.0e-12 || tb < -1.0e-12 ||
      tb > 1.0 + 1.0e-12) {
    return false;
  }
  ta = std::clamp(ta, 0.0, 1.0);
  tb = std::clamp(tb, 0.0, 1.0);
  point = a.start + ta * r;
  return true;
}

inline bool point_on_segment(const Eigen::Vector2d &p, const Segment2 &s) {
  const Eigen::Vector2d ap = p - s.start;
  const Eigen::Vector2d ab = s.end - s.start;
  if (std::abs(cross2(ap, ab)) > 1.0e-10) {
    return false;
  }
  return ap.dot(ab) > 1.0e-10 && ap.dot(ab) < ab.squaredNorm() - 1.0e-10;
}

inline double polygon_area(const std::vector<Eigen::Vector2d> &points) {
  double twice = 0.0;
  for (std::size_t i = 0; i < points.size(); ++i) {
    twice += cross2(points[i], points[(i + 1) % points.size()]);
  }
  return 0.5 * twice;
}

inline bool same_family_collinear(const SurfaceArrangementHalfedge &a,
                                  const SurfaceArrangementHalfedge &b,
                                  const std::vector<SurfaceArrangementNode> &nodes) {
  if (a.family != b.family) {
    return false;
  }
  const Eigen::Vector2d a0 = bary_to_uv(nodes[static_cast<std::size_t>(a.from)].barycentric);
  const Eigen::Vector2d a1 = bary_to_uv(nodes[static_cast<std::size_t>(a.to)].barycentric);
  const Eigen::Vector2d b1 = bary_to_uv(nodes[static_cast<std::size_t>(b.to)].barycentric);
  return std::abs(cross2(a1 - a0, b1 - a1)) <= 1.0e-10;
}

} // namespace surface_arrangement_detail

inline SurfaceCellComplex build_surface_cell_complex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<SurfaceArrangementArc> &inputArcs,
    const SurfaceArrangementOptions &options = {}) {
  if (vertices.cols() != 3 || faces.cols() != 3) {
    throw std::invalid_argument("surface arrangement requires triangle mesh.");
  }
  using namespace surface_arrangement_detail;
  SurfaceCellComplex complex;
  std::vector<Segment2> segments;
  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);

  for (int face = 0; face < faces.rows(); ++face) {
    for (const auto &[a, b, edge] :
         {std::tuple<int, int, int>{0, 1, 2}, {1, 2, 0}, {2, 0, 1}}) {
      const std::uint64_t key = source_edge_key(faces, face, edge);
      const auto found = edgeFaces.find(key);
      const bool boundaryEdge =
          found == edgeFaces.end() || found->second[1] < 0;
      const bool hardFeature =
          options.hardFeatureEdges.count(key) != 0;
      if ((!options.insertBoundaryRails || !boundaryEdge) && !hardFeature) {
        continue;
      }
      Segment2 boundary;
      boundary.sourceArc = -1;
      boundary.sourceFace = face;
      boundary.start = bary_to_uv(Eigen::RowVector3d::Unit(a));
      boundary.end = bary_to_uv(Eigen::RowVector3d::Unit(b));
      boundary.family = -1;
      boundary.hardFeature = hardFeature || boundaryEdge;
      boundary.featureClass = edge;
      segments.push_back(boundary);
    }
  }

  for (const SurfaceArrangementArc &arc : inputArcs) {
    if (arc.sourceFace < 0 || arc.sourceFace >= faces.rows()) {
      continue;
    }
    Segment2 segment;
    segment.sourceArc = arc.id;
    segment.sourceFace = arc.sourceFace;
    segment.start = bary_to_uv(arc.startBarycentric);
    segment.end = bary_to_uv(arc.endBarycentric);
    segment.family = arc.family;
    segment.strand = arc.strand;
    segment.featureClass = arc.featureClass;
    segment.hardFeature = arc.hardFeature;
    if (clip_to_triangle(segment.start, segment.end, segment.sourceT0,
                         segment.sourceT1)) {
      segments.push_back(segment);
    }
  }
  std::sort(segments.begin(), segments.end(), [](const Segment2 &a,
                                                 const Segment2 &b) {
    const auto qa = [](const double value) {
      return static_cast<std::int64_t>(std::llround(value * 1.0e10));
    };
    return std::make_tuple(a.sourceFace, qa(a.start.x()), qa(a.start.y()),
                           qa(a.end.x()), qa(a.end.y()), a.family, a.strand,
                           a.featureClass, a.hardFeature ? 1 : 0, a.sourceArc) <
           std::make_tuple(b.sourceFace, qa(b.start.x()), qa(b.start.y()),
                           qa(b.end.x()), qa(b.end.y()), b.family, b.strand,
                           b.featureClass, b.hardFeature ? 1 : 0, b.sourceArc);
  });

  complex.diagnostics.peakSegmentsPerFace = 0;
  for (int face = 0; face < faces.rows(); ++face) {
    int count = 0;
    for (const Segment2 &segment : segments) {
      if (segment.sourceFace == face) {
        ++count;
      }
    }
    complex.diagnostics.peakSegmentsPerFace =
        std::max(complex.diagnostics.peakSegmentsPerFace, count);
  }

  std::vector<std::vector<double>> splitParams(segments.size());
  for (auto &params : splitParams) {
    params = {0.0, 1.0};
  }
  std::set<NodeKey> intersectionKeys;
  for (int i = 0; i < static_cast<int>(segments.size()); ++i) {
    for (int j = i + 1; j < static_cast<int>(segments.size()); ++j) {
      if (segments[static_cast<std::size_t>(i)].sourceFace !=
          segments[static_cast<std::size_t>(j)].sourceFace) {
        continue;
      }
      double ti = 0.0;
      double tj = 0.0;
      Eigen::Vector2d p;
      if (!segment_intersection_params(segments[static_cast<std::size_t>(i)],
                                       segments[static_cast<std::size_t>(j)], ti,
                                       tj, p)) {
        continue;
      }
      splitParams[static_cast<std::size_t>(i)].push_back(ti);
      splitParams[static_cast<std::size_t>(j)].push_back(tj);
      if (ti > 1.0e-10 && ti < 1.0 - 1.0e-10 && tj > 1.0e-10 &&
          tj < 1.0 - 1.0e-10) {
        ++complex.diagnostics.plantedIntersections;
        const bool aHard = segments[static_cast<std::size_t>(i)].hardFeature;
        const bool bHard = segments[static_cast<std::size_t>(j)].hardFeature;
        const bool aInput = segments[static_cast<std::size_t>(i)].sourceArc >= 0;
        const bool bInput = segments[static_cast<std::size_t>(j)].sourceArc >= 0;
        if (aHard != bHard && (aInput || bInput)) {
          ++complex.diagnostics.hardBarrierCrossings;
        }
      }
      intersectionKeys.insert(make_node_key(
          faces, segments[static_cast<std::size_t>(i)].sourceFace, p));
    }
  }
  complex.diagnostics.uniqueIntersections =
      static_cast<int>(intersectionKeys.size());

  std::map<NodeKey, int> nodeByKey;
  const auto node_id = [&](const int face, const Eigen::Vector2d &uv) {
    const NodeKey key = make_node_key(faces, face, uv);
    auto found = nodeByKey.find(key);
    if (found != nodeByKey.end()) {
      return found->second;
    }
    SurfaceArrangementNode node;
    node.id = static_cast<int>(complex.nodes.size());
    node.sourceFace = face;
    node.barycentric = uv_to_bary(uv);
    node.sourceEdge =
        key.kind == 1 ? static_cast<int>(key.edge & 0x7fffffffu) : -1;
    node.sourceEdgeParameter =
        key.kind == 1 ? static_cast<double>(key.edgeT) / 1.0e10 : 0.0;
    nodeByKey.emplace(key, node.id);
    complex.nodes.push_back(node);
    return node.id;
  };

  std::set<std::pair<int, int>> edgeSet;
  for (int segmentIndex = 0; segmentIndex < static_cast<int>(segments.size());
       ++segmentIndex) {
    auto &params = splitParams[static_cast<std::size_t>(segmentIndex)];
    std::sort(params.begin(), params.end());
    params.erase(std::unique(params.begin(), params.end(), [](double a, double b) {
                   return std::abs(a - b) <= 1.0e-10;
                 }),
                 params.end());
    const Segment2 &segment = segments[static_cast<std::size_t>(segmentIndex)];
    for (int k = 0; k + 1 < static_cast<int>(params.size()); ++k) {
      const double t0 = params[static_cast<std::size_t>(k)];
      const double t1 = params[static_cast<std::size_t>(k + 1)];
      if (t1 - t0 <= 1.0e-12) {
        continue;
      }
      const Eigen::Vector2d p0 = segment.start + t0 * (segment.end - segment.start);
      const Eigen::Vector2d p1 = segment.start + t1 * (segment.end - segment.start);
      const int a = node_id(segment.sourceFace, p0);
      const int b = node_id(segment.sourceFace, p1);
      if (a == b || !edgeSet.insert({std::min(a, b), std::max(a, b)}).second) {
        continue;
      }
      SurfaceArrangementHalfedge h0;
      SurfaceArrangementHalfedge h1;
      h0.id = static_cast<int>(complex.halfedges.size());
      h1.id = h0.id + 1;
      h0.twin = h1.id;
      h1.twin = h0.id;
      h0.from = a;
      h0.to = b;
      h1.from = b;
      h1.to = a;
      h0.sourceArc = h1.sourceArc = segment.sourceArc;
      h0.family = h1.family = segment.family;
      h0.strand = h1.strand = segment.strand;
      h0.featureClass = h1.featureClass = segment.featureClass;
      h0.sourceFace = h1.sourceFace = segment.sourceFace;
      h0.sourceT0 = segment.sourceT0 + t0 * (segment.sourceT1 - segment.sourceT0);
      h0.sourceT1 = segment.sourceT0 + t1 * (segment.sourceT1 - segment.sourceT0);
      h1.sourceT0 = h0.sourceT1;
      h1.sourceT1 = h0.sourceT0;
      h0.hardFeature = h1.hardFeature = segment.hardFeature;
      complex.halfedges.push_back(h0);
      complex.halfedges.push_back(h1);
    }
  }

  std::vector<std::vector<int>> outgoing(complex.nodes.size());
  for (const SurfaceArrangementHalfedge &h : complex.halfedges) {
    outgoing[static_cast<std::size_t>(h.from)].push_back(h.id);
  }
  for (auto &list : outgoing) {
    std::sort(list.begin(), list.end(), [&](const int lhs, const int rhs) {
      const auto &a = complex.halfedges[static_cast<std::size_t>(lhs)];
      const auto &b = complex.halfedges[static_cast<std::size_t>(rhs)];
      const Eigen::Vector2d p =
          bary_to_uv(complex.nodes[static_cast<std::size_t>(a.from)].barycentric);
      const Eigen::Vector2d au =
          bary_to_uv(complex.nodes[static_cast<std::size_t>(a.to)].barycentric) - p;
      const Eigen::Vector2d bu =
          bary_to_uv(complex.nodes[static_cast<std::size_t>(b.to)].barycentric) - p;
      const double aa = std::atan2(au.y(), au.x());
      const double ba = std::atan2(bu.y(), bu.x());
      if (std::abs(aa - ba) > 1.0e-14) {
        return aa < ba;
      }
      return lhs < rhs;
    });
  }
  for (SurfaceArrangementHalfedge &h : complex.halfedges) {
    const int at = h.to;
    const int twin = h.twin;
    const auto &list = outgoing[static_cast<std::size_t>(at)];
    const auto found = std::find(list.begin(), list.end(), twin);
    const int pos = static_cast<int>(std::distance(list.begin(), found));
    const int nextPos = (pos - 1 + static_cast<int>(list.size())) %
                        static_cast<int>(list.size());
    h.next = list[static_cast<std::size_t>(nextPos)];
  }

  std::vector<unsigned char> visited(complex.halfedges.size(), 0);
  for (int start = 0; start < static_cast<int>(complex.halfedges.size()); ++start) {
    if (visited[static_cast<std::size_t>(start)] != 0) {
      continue;
    }
    SurfaceArrangementCell cell;
    cell.id = static_cast<int>(complex.cells.size());
    int h = start;
    std::vector<Eigen::Vector2d> polygon;
    for (int guard = 0; guard < static_cast<int>(complex.halfedges.size()) + 1;
         ++guard) {
      if (visited[static_cast<std::size_t>(h)] != 0) {
        break;
      }
      visited[static_cast<std::size_t>(h)] = 1;
      complex.halfedges[static_cast<std::size_t>(h)].cell = cell.id;
      cell.halfedges.push_back(h);
      const auto &he = complex.halfedges[static_cast<std::size_t>(h)];
      cell.sourceFace = he.sourceFace;
      polygon.push_back(
          bary_to_uv(complex.nodes[static_cast<std::size_t>(he.from)].barycentric));
      h = he.next;
      if (h == start) {
        break;
      }
    }
    if (cell.halfedges.size() < 3) {
      continue;
    }
    cell.signedArea = polygon_area(polygon);
    cell.area = std::abs(cell.signedArea);
    cell.boundaryCycle = cell.signedArea < 0.0;
    for (int index = 0; index < static_cast<int>(cell.halfedges.size()); ++index) {
      const auto &he =
          complex.halfedges[static_cast<std::size_t>(cell.halfedges[index])];
      const auto &next =
          complex.halfedges[static_cast<std::size_t>(
              cell.halfedges[(index + 1) % cell.halfedges.size()])];
      if (he.family < 0) {
        cell.sideFamilies.push_back(he.family);
        cell.sideEdgeCounts.push_back(1);
      } else if (!cell.sideFamilies.empty() &&
                 same_family_collinear(he, next, complex.nodes)) {
        ++cell.sideEdgeCounts.back();
      } else {
        cell.sideFamilies.push_back(he.family);
        cell.sideEdgeCounts.push_back(1);
      }
    }
    if (cell.boundaryCycle) {
      cell.cellClass = SurfaceArrangementCellClass::Exterior;
    } else if (cell.area <= 1.0e-14) {
      cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
      cell.rejectReason = SurfaceArrangementRejectReason::Sliver;
    } else {
      std::set<int> uniqueNodes;
      for (const int halfedge : cell.halfedges) {
        uniqueNodes.insert(
            complex.halfedges[static_cast<std::size_t>(halfedge)].from);
      }
      cell.disk = uniqueNodes.size() == cell.halfedges.size();
      if (!cell.disk) {
        cell.cellClass = SurfaceArrangementCellClass::NonDisk;
        cell.rejectReason = SurfaceArrangementRejectReason::NotFourSided;
        complex.cells.push_back(cell);
        continue;
      }
      if (complex.diagnostics.hardBarrierCrossings > 0) {
        cell.rejectReason = SurfaceArrangementRejectReason::HardFeatureCrossing;
      }
      bool alternating = true;
      for (int i = 0; i < static_cast<int>(cell.sideFamilies.size()); ++i) {
        const int a = cell.sideFamilies[static_cast<std::size_t>(i)];
        const int b =
            cell.sideFamilies[static_cast<std::size_t>((i + 1) % cell.sideFamilies.size())];
        if (a >= 0 && b >= 0 && a == b) {
          alternating = false;
        }
      }
      const int boundaryCount = std::accumulate(cell.sideEdgeCounts.begin(),
                                                cell.sideEdgeCounts.end(), 0);
      if (cell.sideFamilies.size() == 4 && alternating) {
        cell.quadReady = true;
        cell.cellClass = SurfaceArrangementCellClass::RegularQuad;
      } else {
        cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
        cell.rejectReason = !alternating
                                ? SurfaceArrangementRejectReason::NonAlternatingFamilies
                                : (boundaryCount % 2 != 0
                                       ? SurfaceArrangementRejectReason::OddBoundaryParity
                                       : SurfaceArrangementRejectReason::NotFourSided);
      }
    }
    complex.cells.push_back(cell);
  }

  for (int i = 0; i < static_cast<int>(segments.size()); ++i) {
    const Segment2 &a = segments[static_cast<std::size_t>(i)];
    for (int j = i + 1; j < static_cast<int>(segments.size()); ++j) {
      const Segment2 &b = segments[static_cast<std::size_t>(j)];
      if (a.sourceFace != b.sourceFace) {
        continue;
      }
      double ta = 0.0;
      double tb = 0.0;
      Eigen::Vector2d p;
      if (segment_intersection_params(a, b, ta, tb, p) && ta > 1.0e-8 &&
          ta < 1.0 - 1.0e-8 && tb > 1.0e-8 && tb < 1.0 - 1.0e-8) {
        const NodeKey key = make_node_key(faces, a.sourceFace, p);
        if (nodeByKey.count(key) == 0) {
          ++complex.diagnostics.unsplitCrossings;
        }
      }
    }
  }
  for (const SurfaceArrangementNode &node : complex.nodes) {
    const Eigen::Vector2d p = bary_to_uv(node.barycentric);
    for (const SurfaceArrangementHalfedge &h : complex.halfedges) {
      if (h.sourceFace != node.sourceFace || h.from == node.id || h.to == node.id) {
        continue;
      }
      Segment2 split;
      split.sourceFace = h.sourceFace;
      split.start =
          bary_to_uv(complex.nodes[static_cast<std::size_t>(h.from)].barycentric);
      split.end =
          bary_to_uv(complex.nodes[static_cast<std::size_t>(h.to)].barycentric);
      if (point_on_segment(p, split)) {
        ++complex.diagnostics.geometricTJunctions;
        break;
      }
    }
  }

  std::map<int, double> coveredByArc;
  for (const SurfaceArrangementHalfedge &h : complex.halfedges) {
    if (h.sourceArc >= 0 && h.id < h.twin) {
      coveredByArc[h.sourceArc] += std::abs(h.sourceT1 - h.sourceT0);
    }
  }
  for (const SurfaceArrangementArc &arc : inputArcs) {
    if (coveredByArc[arc.id] < 1.0 - 1.0e-8) {
      ++complex.diagnostics.incompleteArcChains;
    }
  }
  complex.diagnostics.supportedArea = 0.0;
  for (int face = 0; face < faces.rows(); ++face) {
    complex.diagnostics.supportedArea += triangle_area_3d(vertices, faces, face);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.boundaryCycle) {
      complex.diagnostics.extractedArea +=
          cell.area * 2.0 * triangle_area_3d(vertices, faces, cell.sourceFace);
    }
  }
  complex.diagnostics.relativeAreaError =
      std::abs(complex.diagnostics.extractedArea -
               complex.diagnostics.supportedArea) /
      std::max(1.0e-20, complex.diagnostics.supportedArea);
  const int undirectedEdges = static_cast<int>(complex.halfedges.size()) / 2;
  const int interiorCells = static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(),
      [](const SurfaceArrangementCell &cell) { return !cell.boundaryCycle; }));
  complex.diagnostics.eulerCharacteristic =
      static_cast<int>(complex.nodes.size()) - undirectedEdges + interiorCells;
  std::set<std::uint64_t> sourceEdges;
  for (int face = 0; face < faces.rows(); ++face) {
    for (int edge = 0; edge < 3; ++edge) {
      sourceEdges.insert(source_edge_key(faces, face, edge));
    }
  }
  complex.diagnostics.sourceEulerCharacteristic =
      static_cast<int>(vertices.rows()) - static_cast<int>(sourceEdges.size()) +
      static_cast<int>(faces.rows());
  const int inputStorageUnits =
      std::max(1, static_cast<int>(faces.rows()) * 3 +
                      static_cast<int>(inputArcs.size()) * 2);
  const double inputStorage = static_cast<double>(inputStorageUnits);
  const double arrangementStorage =
      static_cast<double>(complex.nodes.size() * 3 + complex.halfedges.size() * 2 +
                          complex.cells.size());
  complex.diagnostics.memoryRatioEstimate = arrangementStorage / inputStorage;
  const std::size_t measuredBytes =
      complex.nodes.size() * sizeof(SurfaceArrangementNode) +
      complex.halfedges.size() * sizeof(SurfaceArrangementHalfedge) +
      complex.cells.size() * sizeof(SurfaceArrangementCell);
  const std::size_t inputBytes =
      static_cast<std::size_t>(faces.rows()) * 3U * sizeof(int) +
      inputArcs.size() * sizeof(SurfaceArrangementArc);
  complex.diagnostics.measuredMemoryRatio =
      static_cast<double>(measuredBytes) /
      static_cast<double>(std::max<std::size_t>(1U, inputBytes));
  return complex;
}

inline SurfaceArrangementOverlay
make_surface_arrangement_overlay(const SurfaceCellComplex &complex) {
  SurfaceArrangementOverlay overlay;
  const int edgeCount = static_cast<int>(complex.halfedges.size());
  overlay.splitSegmentStarts.resize(edgeCount, 3);
  overlay.splitSegmentEnds.resize(edgeCount, 3);
  overlay.sideFamily.resize(edgeCount);
  overlay.cellId.resize(edgeCount);
  overlay.hardRailCrossing.resize(edgeCount);
  for (int i = 0; i < edgeCount; ++i) {
    const SurfaceArrangementHalfedge &h = complex.halfedges[static_cast<std::size_t>(i)];
    overlay.splitSegmentStarts.row(i) =
        complex.nodes[static_cast<std::size_t>(h.from)].barycentric;
    overlay.splitSegmentEnds.row(i) =
        complex.nodes[static_cast<std::size_t>(h.to)].barycentric;
    overlay.sideFamily(i) = h.family;
    overlay.cellId(i) = h.cell;
    overlay.hardRailCrossing(i) = h.hardFeature ? 1 : 0;
  }
  overlay.cellClass.resize(static_cast<int>(complex.cells.size()));
  overlay.sliverCycle.resize(static_cast<int>(complex.cells.size()));
  for (int i = 0; i < static_cast<int>(complex.cells.size()); ++i) {
    const SurfaceArrangementCell &cell = complex.cells[static_cast<std::size_t>(i)];
    overlay.cellClass(i) = static_cast<int>(cell.cellClass);
    overlay.sliverCycle(i) =
        cell.rejectReason == SurfaceArrangementRejectReason::Sliver ? 1 : 0;
  }
  return overlay;
}

inline std::uint64_t hash_surface_cell_complex(const SurfaceCellComplex &complex) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  mix(static_cast<int>(complex.nodes.size()));
  mix(static_cast<int>(complex.halfedges.size()));
  mix(static_cast<int>(complex.cells.size()));
  for (const SurfaceArrangementNode &node : complex.nodes) {
    mix(node.sourceFace);
    mix(node.sourceEdge);
    mix(static_cast<std::int64_t>(std::llround(node.sourceEdgeParameter * 1.0e10)));
    for (int i = 0; i < 3; ++i) {
      mix(static_cast<std::int64_t>(std::llround(node.barycentric[i] * 1.0e10)));
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    mix(static_cast<int>(cell.cellClass));
    mix(static_cast<int>(cell.rejectReason));
    mix(static_cast<std::int64_t>(std::llround(cell.area * 1.0e10)));
  }
  return hash;
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H
