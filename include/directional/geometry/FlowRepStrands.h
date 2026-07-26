// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_FLOW_REP_STRANDS_H
#define DIRECTIONAL_GEOMETRY_FLOW_REP_STRANDS_H

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

enum class FlowRepAffinityCue : int {
  ParallelAdjacent = 0,
  JunctionContinuation = 1,
  OrthogonalJunction = 2,
  GeometricCrossing = 3,
  FeatureConflict = 4,
  SameStrandCrossing = 5,
  None = 6,
};

enum class FlowRepEndpointTag : int {
  Boundary = 0,
  Feature = 1,
  NetworkJunction = 2,
  NeedsCompletion = 3,
};

enum class FlowRepPatchClass : int {
  Infeasible = 0,
  ThreeSided = 3,
  FourSided = 4,
  FiveSided = 5,
  SixSided = 6,
};

struct FlowRepArc {
  int id = -1;
  Eigen::RowVector3d start = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d end = Eigen::RowVector3d::Zero();
  int sourceFace = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  int sourceComponent = -1;
  int sourceSheet = -1;
  int family = 0;
  int featureClass = 0;
  bool mandatoryRail = false;
  bool boundaryRail = false;
  bool hardFeatureRail = false;
  int strandProvenance = -1;
  int featureProvenance = -1;
  int railId = -1;
  int curveId = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  double dominance = 1.0;
  double alignmentCost = 0.0;
  int sameStrandHint = -1;
  std::vector<int> substitutions;
};

struct FlowRepAffinity {
  int firstArc = -1;
  int secondArc = -1;
  double score = 0.0;
  FlowRepAffinityCue cue = FlowRepAffinityCue::None;
};

struct FlowRepStrand {
  int id = -1;
  std::vector<int> arcIds;
  bool closed = false;
  bool mandatory = false;
  double length = 0.0;
  double curvaturePenalty = 0.0;
};

struct FlowRepFlowline {
  int id = -1;
  int strandId = -1;
  std::vector<int> arcIds;
  bool closed = false;
  bool mandatory = false;
  double length = 0.0;
};

struct FlowRepCycleInput {
  std::vector<Eigen::RowVector3d> normals;
  std::vector<Eigen::RowVector3d> boundaryNormalA;
  std::vector<Eigen::RowVector3d> boundaryNormalB;
  std::vector<double> distanceA;
  std::vector<double> distanceB;
  std::vector<double> surfaceDistances;
  std::vector<int> sideCounts;
  double targetSize = 1.0;
  double normalThresholdRadians = 0.25;
  bool diskTopology = true;
  bool forbiddenTurn = false;
  bool unresolvedHardFeatureCrossing = false;
  bool impossibleSideCounts = false;
};

struct FlowRepCycleEvaluation {
  bool descriptive = false;
  bool quadrangulable = false;
  double normalP90 = 0.0;
  double surfaceP95 = 0.0;
  double sizePenalty = 0.0;
  double quadPenalty = std::numeric_limits<double>::infinity();
  double energy = std::numeric_limits<double>::infinity();
  FlowRepPatchClass patchClass = FlowRepPatchClass::Infeasible;
};

struct FlowRepSparseOptions {
  double parallelDotThreshold = 0.94;
  double adjacentDistance = 1.0e-8;
  double crossingPenalty = -10.0;
  double featureConflictPenalty = -8.0;
  double orthogonalPenalty = -2.0;
  double maxCoverageWorsening = 0.02;
};

struct FlowRepSparseNetwork {
  std::vector<int> retainedArcIds;
  std::vector<int> removedArcIds;
  std::vector<FlowRepEndpointTag> endpointTags;
  std::vector<FlowRepCycleEvaluation> cycleEvaluations;
  int mandatoryRails = 0;
  int retainedMandatoryRails = 0;
  int acceptedTransactions = 0;
  int cycleRebuilds = 0;
  double denseCoverageMax = 0.0;
  double sparseCoverageMax = 0.0;
};

struct FlowRepOverlay {
  Eigen::MatrixXd rawArcStarts;
  Eigen::MatrixXd rawArcEnds;
  Eigen::VectorXi strandColor;
  Eigen::VectorXi retained;
  Eigen::VectorXi removed;
  Eigen::VectorXd cycleEnergy;
  Eigen::VectorXi patchClass;
};

namespace flow_rep_detail {

inline Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v) {
  const double n = v.norm();
  if (n <= 0.0) {
    return Eigen::RowVector3d::Zero();
  }
  return v / n;
}

inline double arc_length(const FlowRepArc &arc) { return (arc.end - arc.start).norm(); }

inline Eigen::RowVector3d arc_tangent(const FlowRepArc &arc) {
  return normalized_or_zero(arc.end - arc.start);
}

inline bool close_points(const Eigen::RowVector3d &a,
                         const Eigen::RowVector3d &b, const double eps) {
  return (a - b).norm() <= eps;
}

inline bool arcs_adjacent(const FlowRepArc &a, const FlowRepArc &b,
                          const double eps) {
  return close_points(a.start, b.start, eps) || close_points(a.start, b.end, eps) ||
         close_points(a.end, b.start, eps) || close_points(a.end, b.end, eps);
}

inline double cross2(const Eigen::RowVector3d &a, const Eigen::RowVector3d &b) {
  return a.x() * b.y() - a.y() * b.x();
}

inline Eigen::RowVector3d barycentric_uv3(const Eigen::RowVector3d &bary) {
  return {bary[1], bary[2], 0.0};
}

inline Eigen::RowVector3d predicate_start(const FlowRepArc &arc) {
  return arc.sourceFace >= 0 ? barycentric_uv3(arc.startBarycentric) : arc.start;
}

inline Eigen::RowVector3d predicate_end(const FlowRepArc &arc) {
  return arc.sourceFace >= 0 ? barycentric_uv3(arc.endBarycentric) : arc.end;
}

inline FlowRepArc predicate_arc(const FlowRepArc &arc) {
  FlowRepArc projected = arc;
  projected.start = predicate_start(arc);
  projected.end = predicate_end(arc);
  return projected;
}

inline bool point_on_segment_2d(const Eigen::RowVector3d &p,
                                const Eigen::RowVector3d &a,
                                const Eigen::RowVector3d &b,
                                const double eps = 1.0e-10) {
  const Eigen::RowVector3d ap = p - a;
  const Eigen::RowVector3d ab = b - a;
  if (std::abs(cross2(ap, ab)) > eps) {
    return false;
  }
  return ap.dot(ab) >= -eps && ap.dot(ab) <= ab.squaredNorm() + eps;
}

inline bool segments_cross_2d(const FlowRepArc &a, const FlowRepArc &b,
                              const bool countSharedEndpoints = false) {
  if (a.sourceFace >= 0 && b.sourceFace >= 0 && a.sourceFace != b.sourceFace) {
    return false;
  }
  const FlowRepArc aa = predicate_arc(a);
  const FlowRepArc bb = predicate_arc(b);
  if (!countSharedEndpoints &&
      (close_points(aa.start, bb.start, 1.0e-10) ||
       close_points(aa.start, bb.end, 1.0e-10) ||
       close_points(aa.end, bb.start, 1.0e-10) ||
       close_points(aa.end, bb.end, 1.0e-10))) {
    return false;
  }
  const Eigen::RowVector3d r = aa.end - aa.start;
  const Eigen::RowVector3d s = bb.end - bb.start;
  const double denom = cross2(r, s);
  const Eigen::RowVector3d qp = bb.start - aa.start;
  if (std::abs(denom) <= 1.0e-12) {
    return point_on_segment_2d(aa.start, bb.start, bb.end) ||
           point_on_segment_2d(aa.end, bb.start, bb.end) ||
           point_on_segment_2d(bb.start, aa.start, aa.end) ||
           point_on_segment_2d(bb.end, aa.start, aa.end);
  }
  const double t = cross2(qp, s) / denom;
  const double u = cross2(qp, r) / denom;
  const double eps = countSharedEndpoints ? 1.0e-12 : 1.0e-8;
  return t > eps && t < 1.0 - eps && u > eps && u < 1.0 - eps;
}

inline std::uint64_t point_key(const Eigen::RowVector3d &p) {
  const auto q = [](const double value) {
    return static_cast<std::int64_t>(std::llround(value * 1.0e9));
  };
  std::uint64_t h = 1469598103934665603ULL;
  for (const std::int64_t value : {q(p.x()), q(p.y()), q(p.z())}) {
    h ^= static_cast<std::uint64_t>(value);
    h *= 1099511628211ULL;
  }
  return h;
}

inline std::uint64_t endpoint_key(const FlowRepArc &arc, const bool start) {
  if (arc.sourceFace < 0) {
    return point_key(start ? arc.start : arc.end);
  }
  std::uint64_t h = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    h ^= static_cast<std::uint64_t>(value);
    h *= 1099511628211ULL;
  };
  const Eigen::RowVector3d bary = start ? arc.startBarycentric : arc.endBarycentric;
  mix(arc.sourceFace);
  for (int i = 0; i < 3; ++i) {
    mix(static_cast<std::int64_t>(std::llround(bary[i] * 1.0e9)));
  }
  return h;
}

inline double percentile(std::vector<double> values, const double p) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const std::size_t index = static_cast<std::size_t>(
      std::floor(std::clamp(p, 0.0, 1.0) *
                 static_cast<double>(values.size() - 1)));
  return values[index];
}

inline double point_segment_distance(const Eigen::RowVector3d &p,
                                     const FlowRepArc &arc) {
  const Eigen::RowVector3d ab = arc.end - arc.start;
  const double denom = ab.squaredNorm();
  if (denom <= 0.0) {
    return (p - arc.start).norm();
  }
  const double t = std::clamp((p - arc.start).dot(ab) / denom, 0.0, 1.0);
  return (p - (arc.start + t * ab)).norm();
}

inline double coverage_max_distance(const std::vector<FlowRepArc> &arcs,
                                    const std::vector<int> &activeArcIds,
                                    const std::vector<Eigen::RowVector3d> &samples) {
  double maxDistance = 0.0;
  for (const Eigen::RowVector3d &sample : samples) {
    double nearest = std::numeric_limits<double>::infinity();
    for (const int arcId : activeArcIds) {
      if (arcId < 0 || arcId >= static_cast<int>(arcs.size())) {
        continue;
      }
      nearest = std::min(nearest, point_segment_distance(sample, arcs[arcId]));
    }
    if (std::isfinite(nearest)) {
      maxDistance = std::max(maxDistance, nearest);
    }
  }
  return maxDistance;
}

inline std::vector<FlowRepEndpointTag>
classify_endpoints(const std::vector<FlowRepArc> &arcs,
                   const std::vector<int> &activeArcIds) {
  std::map<std::uint64_t, int> counts;
  for (const int arcId : activeArcIds) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
    ++counts[point_key(arc.start)];
    ++counts[point_key(arc.end)];
  }
  std::vector<FlowRepEndpointTag> tags;
  tags.reserve(2 * activeArcIds.size());
  for (const int arcId : activeArcIds) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
    for (const Eigen::RowVector3d &point : {arc.start, arc.end}) {
      if (arc.boundaryRail) {
        tags.push_back(FlowRepEndpointTag::Boundary);
      } else if (arc.hardFeatureRail) {
        tags.push_back(FlowRepEndpointTag::Feature);
      } else if (counts[point_key(point)] > 1) {
        tags.push_back(FlowRepEndpointTag::NetworkJunction);
      } else {
        tags.push_back(FlowRepEndpointTag::NeedsCompletion);
      }
    }
  }
  return tags;
}

} // namespace flow_rep_detail

inline std::vector<FlowRepArc> build_flow_rep_arcs_from_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellNetwork &network) {
  std::vector<FlowRepArc> arcs;
  const auto append_segment = [&](const SurfaceTraceSegment &segment,
                                  const bool mandatory) {
    FlowRepArc arc;
    arc.id = static_cast<int>(arcs.size());
    arc.start = surface_cell_tracing_detail::point_position(
        vertices, faces,
        SurfaceTracePoint{segment.face, segment.startBarycentric});
    arc.end = surface_cell_tracing_detail::point_position(
        vertices, faces,
        SurfaceTracePoint{segment.face, segment.endBarycentric});
    arc.sourceFace = segment.face;
    arc.startBarycentric = segment.startBarycentric;
    arc.endBarycentric = segment.endBarycentric;
    arc.family = segment.family;
    arc.strandProvenance = segment.family;
    arc.featureProvenance = segment.exitEdge;
    arc.featureClass = segment.exitEdge;
    arc.hardFeatureRail = mandatory || segment.railId >= 0;
    arc.mandatoryRail = mandatory || segment.railId >= 0;
    if (segment.railId >= 0) {
      arc.featureProvenance = segment.curveId;
      arc.featureClass = 3;
      arc.railId = segment.railId;
      arc.curveId = segment.curveId;
      arc.railT0 = segment.railT0;
      arc.railT1 = segment.railT1;
      arc.sameStrandHint = segment.railId;
    }
    arcs.push_back(arc);
  };
  for (const SurfaceCellRail &rail : network.authoritativeRails) {
    if (rail.samples.size() < 2U) {
      continue;
    }
    const int segmentCount = static_cast<int>(rail.samples.size()) / 2;
    for (int segment = 0; segment < segmentCount; ++segment) {
      const int i = 2 * segment;
      const SurfaceCellRailSample &a = rail.samples[static_cast<std::size_t>(i)];
      const SurfaceCellRailSample &b = rail.samples[static_cast<std::size_t>(i + 1)];
      if (a.sourceFace < 0 || b.sourceFace < 0 || a.sourceFace != b.sourceFace) {
        continue;
      }
      FlowRepArc arc;
      arc.id = static_cast<int>(arcs.size());
      arc.start = a.position;
      arc.end = b.position;
      arc.sourceFace = a.sourceFace;
      arc.startBarycentric = a.barycentric;
      arc.endBarycentric = b.barycentric;
      arc.sourceComponent = rail.component;
      arc.family = -1;
      arc.featureClass = rail.kind == SurfaceCellRailKind::Boundary ? 1 : 3;
      arc.mandatoryRail = true;
      arc.boundaryRail = rail.kind == SurfaceCellRailKind::Boundary;
      arc.hardFeatureRail = rail.kind == SurfaceCellRailKind::HardFeature;
      arc.strandProvenance = rail.id;
      arc.featureProvenance = rail.curveId;
      arc.railId = rail.id;
      arc.curveId = rail.curveId;
      arc.railT0 = a.railParameter;
      arc.railT1 = b.railParameter;
      arc.sameStrandHint = rail.id;
      arcs.push_back(arc);
    }
  }
  for (const SurfaceTraceResult &trace : network.traces) {
    for (const SurfaceTraceSegment &segment : trace.segments) {
      append_segment(segment, trace.termination == TraceTerminationReason::Feature);
    }
  }
  for (const SurfaceCellProposal &proposal : network.proposals) {
    for (const SurfaceTraceSegment &segment : proposal.sides) {
      append_segment(segment, false);
    }
  }
  return arcs;
}

inline FlowRepAffinity compute_flow_rep_affinity(
    const FlowRepArc &a, const FlowRepArc &b,
    const FlowRepSparseOptions &options = {}) {
  FlowRepAffinity affinity;
  affinity.firstArc = a.id;
  affinity.secondArc = b.id;

  if (a.featureClass != b.featureClass &&
      (a.hardFeatureRail || b.hardFeatureRail)) {
    affinity.score = options.featureConflictPenalty;
    affinity.cue = FlowRepAffinityCue::FeatureConflict;
    return affinity;
  }
  if (flow_rep_detail::segments_cross_2d(a, b)) {
    affinity.score = options.crossingPenalty;
    affinity.cue = FlowRepAffinityCue::GeometricCrossing;
    return affinity;
  }

  const bool adjacent =
      flow_rep_detail::arcs_adjacent(a, b, options.adjacentDistance);
  const double parallel =
      std::abs(flow_rep_detail::arc_tangent(a).dot(flow_rep_detail::arc_tangent(b)));
  if (adjacent && a.sameStrandHint >= 0 && a.sameStrandHint == b.sameStrandHint) {
    affinity.score = 0.75 + parallel;
    affinity.cue = FlowRepAffinityCue::JunctionContinuation;
    return affinity;
  }
  if (adjacent && a.family != b.family && parallel < 0.25) {
    affinity.score = options.orthogonalPenalty;
    affinity.cue = FlowRepAffinityCue::OrthogonalJunction;
    return affinity;
  }
  if (adjacent && a.family == b.family && parallel >= options.parallelDotThreshold) {
    affinity.score = 1.0 + parallel;
    affinity.cue = FlowRepAffinityCue::ParallelAdjacent;
    return affinity;
  }
  if (adjacent && parallel >= options.parallelDotThreshold) {
    affinity.score = 0.5 + parallel;
    affinity.cue = FlowRepAffinityCue::JunctionContinuation;
    return affinity;
  }

  affinity.cue = FlowRepAffinityCue::None;
  affinity.score = 0.0;
  return affinity;
}

inline std::vector<FlowRepAffinity> compute_flow_rep_affinities(
    const std::vector<FlowRepArc> &arcs,
    const FlowRepSparseOptions &options = {}) {
  std::vector<FlowRepAffinity> affinities;
  for (int i = 0; i < static_cast<int>(arcs.size()); ++i) {
    for (int j = i + 1; j < static_cast<int>(arcs.size()); ++j) {
      FlowRepAffinity affinity =
          compute_flow_rep_affinity(arcs[static_cast<std::size_t>(i)],
                                    arcs[static_cast<std::size_t>(j)], options);
      if (affinity.score != 0.0) {
        affinities.push_back(affinity);
      }
    }
  }
  return affinities;
}

inline bool strand_merge_is_simple(const std::vector<FlowRepArc> &arcs,
                                   const std::vector<int> &clusterA,
                                   const std::vector<int> &clusterB) {
  std::vector<int> merged = clusterA;
  merged.insert(merged.end(), clusterB.begin(), clusterB.end());
  for (int i = 0; i < static_cast<int>(merged.size()); ++i) {
    for (int j = i + 1; j < static_cast<int>(merged.size()); ++j) {
      const FlowRepArc &a = arcs[static_cast<std::size_t>(merged[i])];
      const FlowRepArc &b = arcs[static_cast<std::size_t>(merged[j])];
      if (flow_rep_detail::endpoint_key(a, true) == flow_rep_detail::endpoint_key(b, true) ||
          flow_rep_detail::endpoint_key(a, true) == flow_rep_detail::endpoint_key(b, false) ||
          flow_rep_detail::endpoint_key(a, false) == flow_rep_detail::endpoint_key(b, true) ||
          flow_rep_detail::endpoint_key(a, false) == flow_rep_detail::endpoint_key(b, false) ||
          flow_rep_detail::arcs_adjacent(a, b, 1.0e-8)) {
        continue;
      }
      if (flow_rep_detail::segments_cross_2d(a, b)) {
        return false;
      }
    }
  }
  return true;
}

inline std::vector<FlowRepStrand> cluster_flow_rep_strands(
    const std::vector<FlowRepArc> &arcs,
    const FlowRepSparseOptions &options = {}) {
  std::vector<std::vector<int>> clusters;
  clusters.reserve(arcs.size());
  for (const FlowRepArc &arc : arcs) {
    clusters.push_back({arc.id});
  }

  while (true) {
    double bestScore = 0.0;
    int bestA = -1;
    int bestB = -1;
    std::pair<int, int> bestTie{std::numeric_limits<int>::max(),
                                std::numeric_limits<int>::max()};

    for (int a = 0; a < static_cast<int>(clusters.size()); ++a) {
      if (clusters[static_cast<std::size_t>(a)].empty()) {
        continue;
      }
      for (int b = a + 1; b < static_cast<int>(clusters.size()); ++b) {
        if (clusters[static_cast<std::size_t>(b)].empty()) {
          continue;
        }
        if (!strand_merge_is_simple(arcs, clusters[static_cast<std::size_t>(a)],
                                    clusters[static_cast<std::size_t>(b)])) {
          continue;
        }
        double score = 0.0;
        bool blocked = false;
        for (const int arcA : clusters[static_cast<std::size_t>(a)]) {
          for (const int arcB : clusters[static_cast<std::size_t>(b)]) {
            const FlowRepAffinity affinity =
                compute_flow_rep_affinity(arcs[static_cast<std::size_t>(arcA)],
                                          arcs[static_cast<std::size_t>(arcB)],
                                          options);
            if (affinity.score < 0.0) {
              blocked = true;
            }
            score += affinity.score;
          }
        }
        if (blocked || score <= 0.0) {
          continue;
        }
        const int minId = std::min(clusters[static_cast<std::size_t>(a)].front(),
                                   clusters[static_cast<std::size_t>(b)].front());
        const int maxId = std::max(clusters[static_cast<std::size_t>(a)].front(),
                                   clusters[static_cast<std::size_t>(b)].front());
        const std::pair<int, int> tie{minId, maxId};
        if (score > bestScore + 1.0e-14 ||
            (std::abs(score - bestScore) <= 1.0e-14 && tie < bestTie)) {
          bestScore = score;
          bestA = a;
          bestB = b;
          bestTie = tie;
        }
      }
    }
    if (bestA < 0) {
      break;
    }
    auto &target = clusters[static_cast<std::size_t>(bestA)];
    auto &source = clusters[static_cast<std::size_t>(bestB)];
    target.insert(target.end(), source.begin(), source.end());
    std::sort(target.begin(), target.end());
    source.clear();
  }

  std::vector<FlowRepStrand> strands;
  for (auto &cluster : clusters) {
    if (cluster.empty()) {
      continue;
    }
    std::sort(cluster.begin(), cluster.end());
    FlowRepStrand strand;
    strand.id = static_cast<int>(strands.size());
    strand.arcIds = cluster;
    std::map<std::uint64_t, int> endpointCounts;
    for (const int arcId : cluster) {
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
      ++endpointCounts[flow_rep_detail::endpoint_key(arc, true)];
      ++endpointCounts[flow_rep_detail::endpoint_key(arc, false)];
      strand.length += flow_rep_detail::arc_length(arc);
      strand.mandatory = strand.mandatory || arc.mandatoryRail;
    }
    strand.closed = !endpointCounts.empty();
    for (const auto &[unused, count] : endpointCounts) {
      (void)unused;
      strand.closed = strand.closed && count == 2;
    }
    strands.push_back(strand);
  }
  std::stable_sort(strands.begin(), strands.end(), [](const FlowRepStrand &a,
                                                      const FlowRepStrand &b) {
    if (a.closed != b.closed) {
      return a.closed > b.closed;
    }
    if (std::abs(a.length - b.length) > 1.0e-14) {
      return a.length > b.length;
    }
    return a.arcIds.front() < b.arcIds.front();
  });
  for (int index = 0; index < static_cast<int>(strands.size()); ++index) {
    strands[static_cast<std::size_t>(index)].id = index;
  }
  return strands;
}

inline std::vector<FlowRepFlowline> extract_flow_rep_flowlines(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<FlowRepStrand> &strands) {
  std::vector<FlowRepFlowline> flowlines;
  for (const FlowRepStrand &strand : strands) {
    std::map<std::uint64_t, std::vector<int>> incident;
    for (const int arcId : strand.arcIds) {
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
      incident[flow_rep_detail::endpoint_key(arc, true)].push_back(arcId);
      incident[flow_rep_detail::endpoint_key(arc, false)].push_back(arcId);
    }
    std::set<int> visited;
    const auto endpoint_degree = [&](const std::uint64_t key) {
      const auto found = incident.find(key);
      return found == incident.end() ? 0 : static_cast<int>(found->second.size());
    };
    const auto make_flowline = [&](std::vector<int> chain, const bool closed) {
      if (chain.empty()) {
        return;
      }
      FlowRepFlowline flowline;
      flowline.id = static_cast<int>(flowlines.size());
      flowline.strandId = strand.id;
      flowline.arcIds = std::move(chain);
      flowline.closed = closed;
      flowline.mandatory = strand.mandatory;
      for (const int arcId : flowline.arcIds) {
        flowline.length +=
            flow_rep_detail::arc_length(arcs[static_cast<std::size_t>(arcId)]);
      }
      flowlines.push_back(flowline);
    };
    for (const int seedArc : strand.arcIds) {
      if (visited.count(seedArc) != 0) {
        continue;
      }
      const FlowRepArc &seed = arcs[static_cast<std::size_t>(seedArc)];
      const std::uint64_t s0 = flow_rep_detail::endpoint_key(seed, true);
      const std::uint64_t s1 = flow_rep_detail::endpoint_key(seed, false);
      const bool startsAtJunction = endpoint_degree(s0) != 2 || endpoint_degree(s1) != 2;
      if (!startsAtJunction && strand.closed) {
        continue;
      }
      std::vector<int> chain;
      int currentArc = seedArc;
      std::uint64_t previousEndpoint = endpoint_degree(s0) == 1 ? s0 : s1;
      while (currentArc >= 0 && visited.insert(currentArc).second) {
        chain.push_back(currentArc);
        const FlowRepArc &arc = arcs[static_cast<std::size_t>(currentArc)];
        const std::uint64_t a0 = flow_rep_detail::endpoint_key(arc, true);
        const std::uint64_t a1 = flow_rep_detail::endpoint_key(arc, false);
        const std::uint64_t nextEndpoint = previousEndpoint == a0 ? a1 : a0;
        if (endpoint_degree(nextEndpoint) != 2) {
          break;
        }
        currentArc = -1;
        for (const int candidate : incident[nextEndpoint]) {
          if (visited.count(candidate) == 0) {
            currentArc = candidate;
            break;
          }
        }
        previousEndpoint = nextEndpoint;
      }
      make_flowline(std::move(chain), false);
    }
    for (const int seedArc : strand.arcIds) {
      if (visited.count(seedArc) != 0) {
        continue;
      }
      std::vector<int> cycle;
      int currentArc = seedArc;
      std::uint64_t previousEndpoint =
          flow_rep_detail::endpoint_key(arcs[static_cast<std::size_t>(seedArc)],
                                        true);
      while (currentArc >= 0 && visited.insert(currentArc).second) {
        cycle.push_back(currentArc);
        const FlowRepArc &arc = arcs[static_cast<std::size_t>(currentArc)];
        const std::uint64_t a0 = flow_rep_detail::endpoint_key(arc, true);
        const std::uint64_t a1 = flow_rep_detail::endpoint_key(arc, false);
        const std::uint64_t nextEndpoint = previousEndpoint == a0 ? a1 : a0;
        currentArc = -1;
        for (const int candidate : incident[nextEndpoint]) {
          if (visited.count(candidate) == 0) {
            currentArc = candidate;
            break;
          }
        }
        previousEndpoint = nextEndpoint;
      }
      make_flowline(std::move(cycle), true);
    }
  }
  std::stable_sort(flowlines.begin(), flowlines.end(),
                   [](const FlowRepFlowline &a, const FlowRepFlowline &b) {
                     if (a.closed != b.closed) {
                       return a.closed > b.closed;
                     }
                     if (std::abs(a.length - b.length) > 1.0e-14) {
                       return a.length > b.length;
                     }
                     return a.arcIds.front() < b.arcIds.front();
                   });
  for (int index = 0; index < static_cast<int>(flowlines.size()); ++index) {
    flowlines[static_cast<std::size_t>(index)].id = index;
  }
  return flowlines;
}

inline FlowRepCycleEvaluation
evaluate_flow_rep_cycle(const FlowRepCycleInput &cycle) {
  FlowRepCycleEvaluation evaluation;
  if (!cycle.diskTopology || cycle.forbiddenTurn ||
      cycle.unresolvedHardFeatureCrossing || cycle.impossibleSideCounts) {
    return evaluation;
  }
  const int totalBoundary = std::accumulate(cycle.sideCounts.begin(),
                                            cycle.sideCounts.end(), 0);
  const std::size_t sides = cycle.sideCounts.size();
  if (sides < 3 || sides > 6 || totalBoundary % 2 != 0) {
    return evaluation;
  }

  std::vector<double> normalAngles;
  const std::size_t sampleCount =
      std::min({cycle.normals.size(), cycle.boundaryNormalA.size(),
                cycle.boundaryNormalB.size(), cycle.distanceA.size(),
                cycle.distanceB.size()});
  for (std::size_t i = 0; i < sampleCount; ++i) {
    const double d1 = std::max(0.0, cycle.distanceA[i]);
    const double d2 = std::max(0.0, cycle.distanceB[i]);
    const double denom = std::max(d1 + d2, 1.0e-12);
    const Eigen::RowVector3d predicted = flow_rep_detail::normalized_or_zero(
        (d2 / denom) * cycle.boundaryNormalA[i] +
        (d1 / denom) * cycle.boundaryNormalB[i]);
    const Eigen::RowVector3d normal =
        flow_rep_detail::normalized_or_zero(cycle.normals[i]);
    const double dot = std::clamp(predicted.dot(normal), -1.0, 1.0);
    normalAngles.push_back(std::acos(dot));
  }
  evaluation.normalP90 = flow_rep_detail::percentile(normalAngles, 0.90);
  evaluation.surfaceP95 =
      flow_rep_detail::percentile(cycle.surfaceDistances, 0.95);
  const double meanSide =
      cycle.sideCounts.empty()
          ? 0.0
          : static_cast<double>(totalBoundary) /
                static_cast<double>(cycle.sideCounts.size());
  double sideVariance = 0.0;
  for (const int side : cycle.sideCounts) {
    sideVariance += std::abs(static_cast<double>(side) - meanSide);
  }
  evaluation.sizePenalty =
      cycle.sideCounts.empty() ? std::numeric_limits<double>::infinity()
                               : sideVariance / std::max(1.0, meanSide);
  if (sides == 3) {
    evaluation.patchClass = FlowRepPatchClass::ThreeSided;
    evaluation.quadPenalty = 0.25;
  } else if (sides == 4) {
    evaluation.patchClass = FlowRepPatchClass::FourSided;
    evaluation.quadPenalty = 0.0;
  } else if (sides == 5) {
    evaluation.patchClass = FlowRepPatchClass::FiveSided;
    evaluation.quadPenalty = 0.35;
  } else {
    evaluation.patchClass = FlowRepPatchClass::SixSided;
    evaluation.quadPenalty = 0.5;
  }
  const double surfaceScale = std::max(1.0e-12, 0.15 * cycle.targetSize);
  const double normalScale = std::max(1.0e-12, cycle.normalThresholdRadians);
  evaluation.energy =
      std::max({evaluation.normalP90 / normalScale,
                evaluation.surfaceP95 / surfaceScale, evaluation.sizePenalty,
                evaluation.quadPenalty});
  evaluation.quadrangulable = std::isfinite(evaluation.quadPenalty);
  evaluation.descriptive = evaluation.quadrangulable && evaluation.energy <= 1.0;
  return evaluation;
}

inline FlowRepSparseNetwork select_sparse_flow_rep_network(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<Eigen::RowVector3d> &coverageSamples = {},
    const std::vector<FlowRepCycleInput> &cycles = {},
    const FlowRepSparseOptions &options = {}) {
  FlowRepSparseNetwork network;
  std::vector<unsigned char> active(arcs.size(), static_cast<unsigned char>(1));
  std::vector<int> allArcIds;
  allArcIds.reserve(arcs.size());
  for (const FlowRepArc &arc : arcs) {
    allArcIds.push_back(arc.id);
    if (arc.mandatoryRail) {
      ++network.mandatoryRails;
    }
  }
  network.denseCoverageMax =
      flow_rep_detail::coverage_max_distance(arcs, allArcIds, coverageSamples);

  for (const FlowRepCycleInput &cycle : cycles) {
    network.cycleEvaluations.push_back(evaluate_flow_rep_cycle(cycle));
  }
  const auto rebuild_cycles = [&]() {
    std::vector<FlowRepCycleEvaluation> rebuilt;
    rebuilt.reserve(cycles.size());
    for (const FlowRepCycleInput &cycle : cycles) {
      rebuilt.push_back(evaluate_flow_rep_cycle(cycle));
    }
    return rebuilt;
  };
  const auto cycles_ok = [&](const std::vector<FlowRepCycleEvaluation> &evaluations) {
    for (const FlowRepCycleEvaluation &cycle : evaluations) {
      if (!cycle.descriptive || !cycle.quadrangulable) {
        return false;
      }
    }
    return true;
  };

  std::vector<int> removable;
  for (const FlowRepArc &arc : arcs) {
    if (!arc.mandatoryRail) {
      removable.push_back(arc.id);
    }
  }
  std::stable_sort(removable.begin(), removable.end(), [&](const int a,
                                                           const int b) {
    const FlowRepArc &aa = arcs[static_cast<std::size_t>(a)];
    const FlowRepArc &bb = arcs[static_cast<std::size_t>(b)];
    const auto keyA =
        std::make_tuple(aa.dominance, -aa.alignmentCost, aa.id);
    const auto keyB =
        std::make_tuple(bb.dominance, -bb.alignmentCost, bb.id);
    return keyA < keyB;
  });

  for (const int arcId : removable) {
    active[static_cast<std::size_t>(arcId)] = static_cast<unsigned char>(0);
    std::vector<int> trial;
    for (const FlowRepArc &arc : arcs) {
      if (active[static_cast<std::size_t>(arc.id)] != 0) {
        trial.push_back(arc.id);
      }
    }
    const double trialCoverage =
        flow_rep_detail::coverage_max_distance(arcs, trial, coverageSamples);
    std::vector<FlowRepCycleEvaluation> trialCycles = rebuild_cycles();
    ++network.cycleRebuilds;
    if (!cycles_ok(trialCycles) ||
        trialCoverage - network.denseCoverageMax > options.maxCoverageWorsening) {
      active[static_cast<std::size_t>(arcId)] = static_cast<unsigned char>(1);
    } else {
      network.cycleEvaluations = std::move(trialCycles);
      ++network.acceptedTransactions;
    }
  }

  for (const FlowRepArc &arc : arcs) {
    if (active[static_cast<std::size_t>(arc.id)] == 0 || arc.mandatoryRail) {
      continue;
    }
    for (const int substituteId : arc.substitutions) {
      if (substituteId < 0 || substituteId >= static_cast<int>(arcs.size()) ||
          active[static_cast<std::size_t>(substituteId)] != 0 ||
          arcs[static_cast<std::size_t>(substituteId)].mandatoryRail) {
        continue;
      }
      const FlowRepArc &substitute = arcs[static_cast<std::size_t>(substituteId)];
      const double currentObjective = arc.dominance + arc.alignmentCost;
      const double substituteObjective =
          substitute.dominance + substitute.alignmentCost;
      if (substituteObjective >= currentObjective - 1.0e-14) {
        continue;
      }
      active[static_cast<std::size_t>(arc.id)] = static_cast<unsigned char>(0);
      active[static_cast<std::size_t>(substituteId)] =
          static_cast<unsigned char>(1);
      std::vector<int> trial;
      for (const FlowRepArc &candidate : arcs) {
        if (active[static_cast<std::size_t>(candidate.id)] != 0) {
          trial.push_back(candidate.id);
        }
      }
      const double trialCoverage =
          flow_rep_detail::coverage_max_distance(arcs, trial, coverageSamples);
      std::vector<FlowRepCycleEvaluation> trialCycles = rebuild_cycles();
      ++network.cycleRebuilds;
      if (!cycles_ok(trialCycles) ||
          trialCoverage - network.denseCoverageMax >
              options.maxCoverageWorsening) {
        active[static_cast<std::size_t>(arc.id)] = static_cast<unsigned char>(1);
        active[static_cast<std::size_t>(substituteId)] =
            static_cast<unsigned char>(0);
      } else {
        network.cycleEvaluations = std::move(trialCycles);
        ++network.acceptedTransactions;
      }
      break;
    }
  }

  for (const FlowRepArc &arc : arcs) {
    if (active[static_cast<std::size_t>(arc.id)] != 0) {
      network.retainedArcIds.push_back(arc.id);
      if (arc.mandatoryRail) {
        ++network.retainedMandatoryRails;
      }
    } else {
      network.removedArcIds.push_back(arc.id);
    }
  }
  network.sparseCoverageMax = flow_rep_detail::coverage_max_distance(
      arcs, network.retainedArcIds, coverageSamples);
  network.endpointTags =
      flow_rep_detail::classify_endpoints(arcs, network.retainedArcIds);
  return network;
}

inline FlowRepOverlay make_flow_rep_overlay(
    const std::vector<FlowRepArc> &arcs, const std::vector<FlowRepStrand> &strands,
    const FlowRepSparseNetwork &network) {
  FlowRepOverlay overlay;
  overlay.rawArcStarts.resize(static_cast<int>(arcs.size()), 3);
  overlay.rawArcEnds.resize(static_cast<int>(arcs.size()), 3);
  overlay.strandColor =
      Eigen::VectorXi::Constant(static_cast<int>(arcs.size()), -1);
  overlay.retained =
      Eigen::VectorXi::Zero(static_cast<int>(arcs.size()));
  overlay.removed =
      Eigen::VectorXi::Zero(static_cast<int>(arcs.size()));
  for (const FlowRepArc &arc : arcs) {
    overlay.rawArcStarts.row(arc.id) = arc.start;
    overlay.rawArcEnds.row(arc.id) = arc.end;
  }
  for (const FlowRepStrand &strand : strands) {
    for (const int arcId : strand.arcIds) {
      overlay.strandColor(arcId) = strand.id;
    }
  }
  for (const int arcId : network.retainedArcIds) {
    overlay.retained(arcId) = 1;
  }
  for (const int arcId : network.removedArcIds) {
    overlay.removed(arcId) = 1;
  }
  overlay.cycleEnergy.resize(static_cast<int>(network.cycleEvaluations.size()));
  overlay.patchClass.resize(static_cast<int>(network.cycleEvaluations.size()));
  for (int index = 0; index < static_cast<int>(network.cycleEvaluations.size());
       ++index) {
    overlay.cycleEnergy(index) =
        network.cycleEvaluations[static_cast<std::size_t>(index)].energy;
    overlay.patchClass(index) =
        static_cast<int>(
            network.cycleEvaluations[static_cast<std::size_t>(index)].patchClass);
  }
  return overlay;
}

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_FLOW_REP_STRANDS_H
