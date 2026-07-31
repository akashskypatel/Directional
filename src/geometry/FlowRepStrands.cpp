#include <directional/geometry/FlowRepStrands.h>

namespace directional::geometry {

const char *flow_rep_selection_failure_name(
    const FlowRepSelectionFailureCode code) {
  switch (code) {
  case FlowRepSelectionFailureCode::None:
    return "None";
  case FlowRepSelectionFailureCode::EmptyNetwork:
    return "EmptyNetwork";
  case FlowRepSelectionFailureCode::MissingCoverageEvidence:
    return "MissingCoverageEvidence";
  case FlowRepSelectionFailureCode::MissingCycleEvidence:
    return "MissingCycleEvidence";
  case FlowRepSelectionFailureCode::InvalidCoverageEvidence:
    return "InvalidCoverageEvidence";
  case FlowRepSelectionFailureCode::InvalidCycleEvidence:
    return "InvalidCycleEvidence";
  case FlowRepSelectionFailureCode::InvalidArcIdentity:
    return "InvalidArcIdentity";
  case FlowRepSelectionFailureCode::IncompleteArcProvenance:
    return "IncompleteArcProvenance";
  case FlowRepSelectionFailureCode::IncompleteCycleCoverage:
    return "IncompleteCycleCoverage";
  case FlowRepSelectionFailureCode::MandatoryRailLoss:
    return "MandatoryRailLoss";
  }
  return "Unknown";
}

} // namespace directional::geometry

namespace directional::geometry::flow_rep_detail {

Eigen::RowVector3d normalized_or_zero(const Eigen::RowVector3d &v) {
  const double n = v.norm();
  if (n <= 0.0) {
    return Eigen::RowVector3d::Zero();
  }
  return v / n;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

double arc_length(const FlowRepArc &arc) { return (arc.end - arc.start).norm(); }

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

Eigen::RowVector3d arc_tangent(const FlowRepArc &arc) {
  return normalized_or_zero(arc.end - arc.start);
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool close_points(const Eigen::RowVector3d &a,
                         const Eigen::RowVector3d &b, const double eps) {
  return (a - b).norm() <= eps;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool arcs_adjacent(const FlowRepArc &a, const FlowRepArc &b,
                          const double eps) {
  return close_points(a.start, b.start, eps) || close_points(a.start, b.end, eps) ||
         close_points(a.end, b.start, eps) || close_points(a.end, b.end, eps);
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

double cross2(const Eigen::RowVector3d &a, const Eigen::RowVector3d &b) {
  return a.x() * b.y() - a.y() * b.x();
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

Eigen::RowVector3d barycentric_uv3(const Eigen::RowVector3d &bary) {
  return {bary[1], bary[2], 0.0};
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

Eigen::RowVector3d predicate_start(const FlowRepArc &arc) {
  return arc.sourceFace >= 0 ? barycentric_uv3(arc.startBarycentric) : arc.start;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

Eigen::RowVector3d predicate_end(const FlowRepArc &arc) {
  return arc.sourceFace >= 0 ? barycentric_uv3(arc.endBarycentric) : arc.end;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

FlowRepArc predicate_arc(const FlowRepArc &arc) {
  FlowRepArc projected = arc;
  projected.start = predicate_start(arc);
  projected.end = predicate_end(arc);
  return projected;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool point_on_segment_2d(const Eigen::RowVector3d &p,
                                const Eigen::RowVector3d &a,
                                const Eigen::RowVector3d &b,
                                const double eps) {
  const Eigen::RowVector3d ap = p - a;
  const Eigen::RowVector3d ab = b - a;
  if (std::abs(cross2(ap, ab)) > eps) {
    return false;
  }
  return ap.dot(ab) >= -eps && ap.dot(ab) <= ab.squaredNorm() + eps;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool segments_cross_2d(const FlowRepArc &a, const FlowRepArc &b,
                              const bool countSharedEndpoints) {
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

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::uint64_t point_key(const Eigen::RowVector3d &p) {
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

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::uint64_t endpoint_key(const FlowRepArc &arc, const bool start) {
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

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

double percentile(std::vector<double> values, const double p) {
  if (values.empty()) {
    return 0.0;
  }
  std::sort(values.begin(), values.end());
  const std::size_t index = static_cast<std::size_t>(
      std::floor(std::clamp(p, 0.0, 1.0) *
                 static_cast<double>(values.size() - 1)));
  return values[index];
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

double point_segment_distance(const Eigen::RowVector3d &p,
                                     const FlowRepArc &arc) {
  const Eigen::RowVector3d ab = arc.end - arc.start;
  const double denom = ab.squaredNorm();
  if (denom <= 0.0) {
    return (p - arc.start).norm();
  }
  const double t = std::clamp((p - arc.start).dot(ab) / denom, 0.0, 1.0);
  return (p - (arc.start + t * ab)).norm();
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool finite_row3(const Eigen::RowVector3d &value) {
  return value.array().isFinite().all();
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool valid_barycentric(const Eigen::RowVector3d &value,
                              const double tolerance) {
  return finite_row3(value) &&
         std::abs(value.sum() - 1.0) <= tolerance &&
         value.minCoeff() >= -tolerance && value.maxCoeff() <= 1.0 + tolerance;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool arc_has_complete_provenance(const FlowRepArc &arc) {
  if (arc.sourceFace < 0 || arc.sourceComponent < 0 || arc.sourceSheet < 0 ||
      !valid_barycentric(arc.startBarycentric) ||
      !valid_barycentric(arc.endBarycentric) || !finite_row3(arc.start) ||
      !finite_row3(arc.end) || arc_length(arc) <= 0.0) {
    return false;
  }
  if (arc.mandatoryRail) {
    return arc.initiallyActive && arc.railId >= 0 && arc.curveId >= 0 &&
           arc.strandProvenance >= 0 &&
           (arc.boundaryRail || arc.hardFeatureRail);
  }
  return arc.proposalId >= 0 && arc.proposalSide >= 0 &&
         arc.proposalSide < 6 && arc.proposalBoundarySegment >= 0;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool coverage_sample_is_valid(const FlowRepCoverageSample &sample) {
  return finite_row3(sample.position) && sample.sourceFace >= 0 &&
         sample.sourceComponent >= 0 && sample.sourceSheet >= 0 &&
         valid_barycentric(sample.barycentric) &&
         std::isfinite(sample.targetSize) && sample.targetSize > 0.0 &&
         sample.sourceArcId >= 0;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool sample_and_arc_are_intrinsically_compatible(
    const FlowRepCoverageSample &sample, const FlowRepArc &arc) {
  return sample.sourceFace == arc.sourceFace &&
         sample.sourceComponent == arc.sourceComponent &&
         sample.sourceSheet == arc.sourceSheet;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

double normalized_intrinsic_sample_distance(
    const FlowRepCoverageSample &sample, const FlowRepArc &arc) {
  if (!sample_and_arc_are_intrinsically_compatible(sample, arc)) {
    return std::numeric_limits<double>::infinity();
  }
  return point_segment_distance(sample.position, arc) / sample.targetSize;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

double coverage_max_distance(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds,
    const std::vector<FlowRepCoverageSample> &samples) {
  double maxDistance = 0.0;
  for (const FlowRepCoverageSample &sample : samples) {
    double nearest = std::numeric_limits<double>::infinity();
    for (const int arcId : activeArcIds) {
      if (arcId < 0 || arcId >= static_cast<int>(arcs.size())) {
        continue;
      }
      nearest = std::min(
          nearest,
          normalized_intrinsic_sample_distance(
              sample, arcs[static_cast<std::size_t>(arcId)]));
    }
    if (!std::isfinite(nearest)) {
      return std::numeric_limits<double>::infinity();
    }
    maxDistance = std::max(maxDistance, nearest);
  }
  return maxDistance;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::vector<FlowRepEndpointTag>
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

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry {

std::vector<FlowRepArc> build_flow_rep_arcs_from_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellNetwork &network) {
  std::vector<FlowRepArc> arcs;
  const auto face_label = [](const std::vector<int> &labels, const int face) {
    return face >= 0 && face < static_cast<int>(labels.size())
               ? labels[static_cast<std::size_t>(face)]
               : -1;
  };
  const auto append_segment = [&](const SurfaceTraceSegment &segment,
                                  const bool mandatory, const int proposalId,
                                  const int proposalSeedId,
                                  const int proposalSide,
                                  const int proposalBoundarySegment) {
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
    arc.sourceComponent =
        face_label(network.sourceFaceComponents, segment.face);
    arc.sourceSheet = face_label(network.sourceFaceSheets, segment.face);
    arc.family = segment.family;
    arc.strandProvenance = proposalId;
    arc.featureProvenance = segment.exitEdge;
    arc.featureClass = segment.exitEdge;
    arc.proposalId = proposalId;
    arc.proposalSeedId = proposalSeedId;
    arc.proposalSide = proposalSide;
    arc.proposalBoundarySegment = proposalBoundarySegment;
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
      arc.sourceComponent = rail.component >= 0
                                ? rail.component
                                : face_label(network.sourceFaceComponents,
                                             a.sourceFace);
      arc.sourceSheet = face_label(network.sourceFaceSheets, a.sourceFace);
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
  // Half traces are diagnostic exploration only. FlowRep receives complete,
  // prevalidated cell-boundary cycles and authoritative rails exclusively.
  for (int proposalId = 0;
       proposalId < static_cast<int>(network.proposals.size()); ++proposalId) {
    const SurfaceCellProposal &proposal =
        network.proposals[static_cast<std::size_t>(proposalId)];
    if (!proposal.accepted ||
        proposal.rejection != CellRejectionReason::Accepted) {
      continue;
    }
    for (int side = 0; side < static_cast<int>(proposal.boundaryPaths.size());
         ++side) {
      const auto &boundaryPath =
          proposal.boundaryPaths[static_cast<std::size_t>(side)];
      for (int segmentIndex = 0;
           segmentIndex < static_cast<int>(boundaryPath.size());
           ++segmentIndex) {
        append_segment(boundaryPath[static_cast<std::size_t>(segmentIndex)],
                       false, proposalId, proposal.seedId, side, segmentIndex);
      }
    }
  }
  return arcs;
}

} // namespace directional::geometry

namespace directional::geometry {

FlowRepSelectionInput build_flow_rep_selection_input(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::VectorXd &targetSize, const SurfaceCellNetwork &network,
    const double defaultTargetSize) {
  FlowRepSelectionInput input;
  input.arcs = build_flow_rep_arcs_from_network(vertices, faces, network);

  const auto target_size_at_barycentric = [&](const int face,
                                               const Eigen::RowVector3d &bary) {
    if (face < 0 || face >= faces.rows()) {
      return defaultTargetSize;
    }
    double value = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      value += bary[corner] *
               surface_cell_tracing_detail::target_size_at_vertex(
                   targetSize, faces(face, corner), defaultTargetSize);
    }
    return std::isfinite(value) && value > 0.0 ? value : defaultTargetSize;
  };

  input.coverageSamples.reserve(input.arcs.size());
  for (const FlowRepArc &arc : input.arcs) {
    if (!arc.initiallyActive || arc.sourceFace < 0) {
      continue;
    }
    const Eigen::RowVector3d midpointBarycentric =
        0.5 * (arc.startBarycentric + arc.endBarycentric);
    const double midpointTargetSize = target_size_at_barycentric(
        arc.sourceFace, midpointBarycentric);
    const int sampleCount = std::max(
        1, static_cast<int>(std::ceil(
               flow_rep_detail::arc_length(arc) /
               std::max(0.5 * midpointTargetSize, 1.0e-12))));
    for (int sampleIndex = 0; sampleIndex < sampleCount; ++sampleIndex) {
      const double parameter =
          (static_cast<double>(sampleIndex) + 0.5) /
          static_cast<double>(sampleCount);
      FlowRepCoverageSample sample;
      sample.position =
          (1.0 - parameter) * arc.start + parameter * arc.end;
      sample.sourceFace = arc.sourceFace;
      sample.barycentric = (1.0 - parameter) * arc.startBarycentric +
                           parameter * arc.endBarycentric;
      sample.sourceComponent = arc.sourceComponent;
      sample.sourceSheet = arc.sourceSheet;
      sample.targetSize =
          target_size_at_barycentric(sample.sourceFace, sample.barycentric);
      sample.sourceArcId = arc.id;
      input.coverageSamples.push_back(sample);
    }
  }

  std::map<int, std::size_t> cycleByProposal;
  for (const FlowRepArc &arc : input.arcs) {
    // Standalone authoritative rails are constraints, not cell boundaries.
    // Proposal segments that follow a rail remain mandatory, but must still
    // participate in the proposal cycle they bound.
    if (arc.proposalId < 0) {
      continue;
    }
    auto [it, inserted] =
        cycleByProposal.emplace(arc.proposalId, input.cycles.size());
    if (inserted) {
      FlowRepCycleInput cycle;
      cycle.id = static_cast<int>(input.cycles.size());
      cycle.proposalId = arc.proposalId;
      cycle.targetSize = 0.0;
      cycle.sideArcIds.resize(4);
      input.cycles.push_back(std::move(cycle));
    }
    FlowRepCycleInput &cycle = input.cycles[it->second];
    if (arc.proposalSide >= 0 &&
        arc.proposalSide < static_cast<int>(cycle.sideArcIds.size())) {
      cycle.sideArcIds[static_cast<std::size_t>(arc.proposalSide)].push_back(
          arc.id);
    }
    cycle.boundaryArcIds.push_back(arc.id);

    const Eigen::RowVector3d normal =
        surface_cell_tracing_detail::face_normal(vertices, faces,
                                                 arc.sourceFace);
    cycle.normals.push_back(normal);
    cycle.boundaryNormalA.push_back(normal);
    cycle.boundaryNormalB.push_back(normal);
    const double halfLength = std::max(0.5 * flow_rep_detail::arc_length(arc),
                                       1.0e-12);
    cycle.distanceA.push_back(halfLength);
    cycle.distanceB.push_back(halfLength);
    cycle.surfaceDistances.push_back(0.0);
    cycle.targetSize += target_size_at_barycentric(
        arc.sourceFace,
        0.5 * (arc.startBarycentric + arc.endBarycentric));
  }

  for (FlowRepCycleInput &cycle : input.cycles) {
    cycle.sideCounts.clear();
    cycle.sideCounts.reserve(cycle.sideArcIds.size());
    for (std::vector<int> &side : cycle.sideArcIds) {
      std::stable_sort(side.begin(), side.end(), [&](const int first,
                                                     const int second) {
        const FlowRepArc &a = input.arcs[static_cast<std::size_t>(first)];
        const FlowRepArc &b = input.arcs[static_cast<std::size_t>(second)];
        if (a.proposalBoundarySegment != b.proposalBoundarySegment) {
          return a.proposalBoundarySegment < b.proposalBoundarySegment;
        }
        return a.id < b.id;
      });
      // A traced proposal has one logical boundary side even when that side is
      // split into multiple source-triangle segments. Segment count is used to
      // prove completeness, not as the final patch subdivision count.
      cycle.sideCounts.push_back(side.empty() ? 0 : 1);
    }
    std::stable_sort(cycle.boundaryArcIds.begin(), cycle.boundaryArcIds.end());
    if (!cycle.boundaryArcIds.empty()) {
      cycle.targetSize /= static_cast<double>(cycle.boundaryArcIds.size());
    } else {
      cycle.targetSize = defaultTargetSize;
    }
  }

  return input;
}

} // namespace directional::geometry

namespace directional::geometry {

FlowRepAffinity compute_flow_rep_affinity(
    const FlowRepArc &a, const FlowRepArc &b,
    const FlowRepSparseOptions &options) {
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

} // namespace directional::geometry

namespace directional::geometry {

std::vector<FlowRepAffinity> compute_flow_rep_affinities(
    const std::vector<FlowRepArc> &arcs,
    const FlowRepSparseOptions &options) {
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

} // namespace directional::geometry

namespace directional::geometry {

bool strand_merge_is_simple(const std::vector<FlowRepArc> &arcs,
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

} // namespace directional::geometry

namespace directional::geometry {

std::vector<FlowRepStrand> cluster_flow_rep_strands(
    const std::vector<FlowRepArc> &arcs,
    const FlowRepSparseOptions &options) {
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

} // namespace directional::geometry

namespace directional::geometry {

std::vector<FlowRepFlowline> extract_flow_rep_flowlines(
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

} // namespace directional::geometry

namespace directional::geometry {

FlowRepCycleEvaluation
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

} // namespace directional::geometry

namespace directional::geometry::flow_rep_detail {

bool substitution_preserves_cycle_boundary(const FlowRepArc &original,
                                                   const FlowRepArc &candidate) {
  if (candidate.mandatoryRail || candidate.sourceFace != original.sourceFace ||
      candidate.sourceComponent != original.sourceComponent ||
      candidate.sourceSheet != original.sourceSheet ||
      candidate.family != original.family ||
      candidate.proposalId != original.proposalId ||
      candidate.proposalSide != original.proposalSide ||
      candidate.proposalBoundarySegment !=
          original.proposalBoundarySegment) {
    return false;
  }
  const bool sameOrientation =
      close_points(predicate_start(original), predicate_start(candidate),
                   1.0e-10) &&
      close_points(predicate_end(original), predicate_end(candidate), 1.0e-10);
  const bool reverseOrientation =
      close_points(predicate_start(original), predicate_end(candidate),
                   1.0e-10) &&
      close_points(predicate_end(original), predicate_start(candidate),
                   1.0e-10);
  return sameOrientation || reverseOrientation;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

int resolve_cycle_arc(const FlowRepCycleInput &cycle,
                             const std::vector<FlowRepArc> &arcs,
                             const std::vector<unsigned char> &active,
                             const int originalArcId) {
  (void)cycle;
  if (originalArcId < 0 || originalArcId >= static_cast<int>(arcs.size())) {
    return -1;
  }
  if (active[static_cast<std::size_t>(originalArcId)] != 0) {
    return originalArcId;
  }
  const FlowRepArc &original = arcs[static_cast<std::size_t>(originalArcId)];
  for (const int substituteId : original.substitutions) {
    if (substituteId < 0 || substituteId >= static_cast<int>(arcs.size()) ||
        active[static_cast<std::size_t>(substituteId)] == 0) {
      continue;
    }
    const FlowRepArc &candidate = arcs[static_cast<std::size_t>(substituteId)];
    if (substitution_preserves_cycle_boundary(original, candidate)) {
      return substituteId;
    }
  }
  return -1;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

FlowRepCycleEvaluation rebuild_cycle_evaluation(
    const FlowRepCycleInput &cycle, const std::vector<FlowRepArc> &arcs,
    const std::vector<unsigned char> &active) {
  FlowRepCycleInput rebuilt = cycle;
  rebuilt.boundaryArcIds.clear();
  rebuilt.sideCounts.clear();
  bool completeBoundary = !cycle.sideArcIds.empty();
  std::set<int> resolvedBoundary;
  for (std::size_t sideIndex = 0; sideIndex < cycle.sideArcIds.size();
       ++sideIndex) {
    const std::vector<int> &side = cycle.sideArcIds[sideIndex];
    bool completeSide = !side.empty();
    for (const int originalArcId : side) {
      const int resolvedArcId =
          resolve_cycle_arc(cycle, arcs, active, originalArcId);
      if (resolvedArcId < 0 || !resolvedBoundary.insert(resolvedArcId).second) {
        completeSide = false;
        continue;
      }
      rebuilt.boundaryArcIds.push_back(resolvedArcId);
    }
    const int logicalSideCount =
        sideIndex < cycle.sideCounts.size() ? cycle.sideCounts[sideIndex] : 0;
    rebuilt.sideCounts.push_back(completeSide ? logicalSideCount : 0);
    completeBoundary = completeBoundary && completeSide && logicalSideCount > 0;
  }
  rebuilt.diskTopology = rebuilt.diskTopology && completeBoundary;
  return evaluate_flow_rep_cycle(rebuilt);
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool cycle_input_is_structurally_valid(
    const FlowRepCycleInput &cycle, const std::vector<FlowRepArc> &arcs) {
  if (cycle.id < 0 || cycle.proposalId < 0 ||
      cycle.sideArcIds.size() < 3U || cycle.sideArcIds.size() > 6U ||
      cycle.sideCounts.size() != cycle.sideArcIds.size() ||
      cycle.boundaryArcIds.empty() || !std::isfinite(cycle.targetSize) ||
      cycle.targetSize <= 0.0 ||
      !std::isfinite(cycle.normalThresholdRadians) ||
      cycle.normalThresholdRadians <= 0.0 || cycle.normals.empty() ||
      cycle.normals.size() != cycle.boundaryNormalA.size() ||
      cycle.normals.size() != cycle.boundaryNormalB.size() ||
      cycle.normals.size() != cycle.distanceA.size() ||
      cycle.normals.size() != cycle.distanceB.size() ||
      cycle.surfaceDistances.empty()) {
    return false;
  }
  for (std::size_t sample = 0; sample < cycle.normals.size(); ++sample) {
    if (!finite_row3(cycle.normals[sample]) ||
        !finite_row3(cycle.boundaryNormalA[sample]) ||
        !finite_row3(cycle.boundaryNormalB[sample]) ||
        !std::isfinite(cycle.distanceA[sample]) || cycle.distanceA[sample] < 0.0 ||
        !std::isfinite(cycle.distanceB[sample]) || cycle.distanceB[sample] < 0.0) {
      return false;
    }
  }
  for (const double distance : cycle.surfaceDistances) {
    if (!std::isfinite(distance) || distance < 0.0) {
      return false;
    }
  }
  std::vector<int> flattened;
  for (std::size_t sideIndex = 0; sideIndex < cycle.sideArcIds.size();
       ++sideIndex) {
    const std::vector<int> &side = cycle.sideArcIds[sideIndex];
    if (side.empty() || cycle.sideCounts[sideIndex] <= 0) {
      return false;
    }
    int expectedSegment = 0;
    for (const int arcId : side) {
      if (arcId < 0 || arcId >= static_cast<int>(arcs.size())) {
        return false;
      }
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
      if (arc.proposalId != cycle.proposalId ||
          arc.proposalSide != static_cast<int>(sideIndex) ||
          arc.proposalBoundarySegment != expectedSegment++) {
        return false;
      }
    }
    flattened.insert(flattened.end(), side.begin(), side.end());
  }
  std::stable_sort(flattened.begin(), flattened.end());
  std::vector<int> boundary = cycle.boundaryArcIds;
  std::stable_sort(boundary.begin(), boundary.end());
  if (flattened != boundary ||
      std::adjacent_find(boundary.begin(), boundary.end()) != boundary.end()) {
    return false;
  }
  for (const int arcId : boundary) {
    if (arcId < 0 || arcId >= static_cast<int>(arcs.size()) ||
        !arcs[static_cast<std::size_t>(arcId)].initiallyActive) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool cycle_evaluations_are_valid(
    const std::vector<FlowRepCycleEvaluation> &evaluations) {
  for (const FlowRepCycleEvaluation &cycle : evaluations) {
    if (!cycle.descriptive || !cycle.quadrangulable) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

FlowRepLogicalStrandKey logical_strand_key(const FlowRepArc &arc) {
  if (arc.mandatoryRail || arc.railId >= 0) {
    return {0, arc.railId, arc.curveId, arc.family, arc.sourceSheet};
  }
  if (arc.proposalId >= 0 && arc.proposalSide >= 0) {
    return {1, arc.proposalId, arc.proposalSide, arc.family, arc.sourceSheet};
  }
  return {2, arc.sameStrandHint, arc.family, arc.sourceComponent,
          arc.sourceSheet};
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::uint64_t embedded_endpoint_key(const FlowRepArc &arc,
                                           const bool start) {
  std::uint64_t h = point_key(start ? arc.start : arc.end);
  const auto mix = [&](const std::int64_t value) {
    h ^= static_cast<std::uint64_t>(value);
    h *= 1099511628211ULL;
  };
  mix(arc.sourceComponent);
  mix(arc.sourceSheet);
  return h;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::vector<FlowRepFlowline> extract_transactional_flowlines(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds) {
  using IncidenceKey = std::pair<FlowRepLogicalStrandKey, std::uint64_t>;
  std::map<std::uint64_t, std::vector<int>> globalIncident;
  std::map<IncidenceKey, std::vector<int>> logicalIncident;
  std::map<FlowRepLogicalStrandKey, std::vector<int>> logicalArcs;

  for (const int arcId : activeArcIds) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
    const FlowRepLogicalStrandKey key = logical_strand_key(arc);
    logicalArcs[key].push_back(arcId);
    for (const bool start : {true, false}) {
      const std::uint64_t endpoint = embedded_endpoint_key(arc, start);
      globalIncident[endpoint].push_back(arcId);
      logicalIncident[{key, endpoint}].push_back(arcId);
    }
  }
  for (auto &[unused, ids] : globalIncident) {
    (void)unused;
    std::sort(ids.begin(), ids.end());
  }
  for (auto &[unused, ids] : logicalIncident) {
    (void)unused;
    std::sort(ids.begin(), ids.end());
  }

  std::vector<FlowRepFlowline> result;
  std::set<int> visited;
  const auto logical_degree = [&](const FlowRepLogicalStrandKey &key,
                                  const std::uint64_t endpoint) {
    const auto found = logicalIncident.find({key, endpoint});
    return found == logicalIncident.end()
               ? 0
               : static_cast<int>(found->second.size());
  };
  const auto global_degree = [&](const std::uint64_t endpoint) {
    const auto found = globalIncident.find(endpoint);
    return found == globalIncident.end()
               ? 0
               : static_cast<int>(found->second.size());
  };
  const auto append = [&](std::vector<int> chain, const bool closed) {
    if (chain.empty()) {
      return;
    }
    FlowRepFlowline flowline;
    flowline.id = static_cast<int>(result.size());
    flowline.strandId = flowline.id;
    flowline.arcIds = std::move(chain);
    flowline.closed = closed;
    for (const int arcId : flowline.arcIds) {
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
      flowline.length += arc_length(arc);
      flowline.mandatory = flowline.mandatory || arc.mandatoryRail ||
                           arc.boundaryRail || arc.hardFeatureRail;
    }
    result.push_back(std::move(flowline));
  };

  for (auto &[key, ids] : logicalArcs) {
    std::sort(ids.begin(), ids.end());
    const auto trace_from = [&](const int seedArc,
                                const std::uint64_t initialEndpoint,
                                const bool closed) {
      std::vector<int> chain;
      int currentArc = seedArc;
      std::uint64_t previousEndpoint = initialEndpoint;
      while (currentArc >= 0 && visited.insert(currentArc).second) {
        chain.push_back(currentArc);
        const FlowRepArc &arc = arcs[static_cast<std::size_t>(currentArc)];
        const std::uint64_t a0 = embedded_endpoint_key(arc, true);
        const std::uint64_t a1 = embedded_endpoint_key(arc, false);
        const std::uint64_t nextEndpoint = previousEndpoint == a0 ? a1 : a0;
        if (!closed &&
            (global_degree(nextEndpoint) != 2 ||
             logical_degree(key, nextEndpoint) != 2)) {
          break;
        }
        currentArc = -1;
        const auto found = logicalIncident.find({key, nextEndpoint});
        if (found != logicalIncident.end()) {
          for (const int candidate : found->second) {
            if (visited.count(candidate) == 0) {
              currentArc = candidate;
              break;
            }
          }
        }
        previousEndpoint = nextEndpoint;
      }
      append(std::move(chain), closed);
    };

    for (const int seedArc : ids) {
      if (visited.count(seedArc) != 0) {
        continue;
      }
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(seedArc)];
      const std::uint64_t a0 = embedded_endpoint_key(arc, true);
      const std::uint64_t a1 = embedded_endpoint_key(arc, false);
      const bool endpoint0 = global_degree(a0) != 2 || logical_degree(key, a0) != 2;
      const bool endpoint1 = global_degree(a1) != 2 || logical_degree(key, a1) != 2;
      if (endpoint0 || endpoint1) {
        trace_from(seedArc, endpoint0 ? a0 : a1, false);
      }
    }
    for (const int seedArc : ids) {
      if (visited.count(seedArc) != 0) {
        continue;
      }
      trace_from(seedArc, embedded_endpoint_key(
                              arcs[static_cast<std::size_t>(seedArc)], true),
                 true);
    }
  }

  std::stable_sort(result.begin(), result.end(),
                   [](const FlowRepFlowline &a, const FlowRepFlowline &b) {
                     const int amin = *std::min_element(a.arcIds.begin(), a.arcIds.end());
                     const int bmin = *std::min_element(b.arcIds.begin(), b.arcIds.end());
                     return amin < bmin;
                   });
  for (int index = 0; index < static_cast<int>(result.size()); ++index) {
    result[static_cast<std::size_t>(index)].id = index;
    result[static_cast<std::size_t>(index)].strandId = index;
  }
  return result;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::map<std::uint64_t, int> protected_endpoint_degrees(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds) {
  std::map<std::uint64_t, int> degrees;
  std::set<std::uint64_t> protectedEndpoints;
  for (const int arcId : activeArcIds) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
    for (const bool start : {true, false}) {
      const std::uint64_t key = embedded_endpoint_key(arc, start);
      ++degrees[key];
      if (arc.boundaryRail || arc.hardFeatureRail || arc.mandatoryRail) {
        protectedEndpoints.insert(key);
      }
    }
  }
  for (const auto &[key, degree] : degrees) {
    if (degree >= 3) {
      protectedEndpoints.insert(key);
    }
  }
  for (auto it = degrees.begin(); it != degrees.end();) {
    if (protectedEndpoints.count(it->first) == 0) {
      it = degrees.erase(it);
    } else {
      ++it;
    }
  }
  return degrees;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool preserves_protected_endpoint_degrees(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds,
    const std::map<std::uint64_t, int> &requiredDegrees) {
  std::map<std::uint64_t, int> trial;
  for (const int arcId : activeArcIds) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
    ++trial[embedded_endpoint_key(arc, true)];
    ++trial[embedded_endpoint_key(arc, false)];
  }
  for (const auto &[key, degree] : requiredDegrees) {
    const auto found = trial.find(key);
    if (found == trial.end() || found->second != degree) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

int count_closed_boundary_cycles(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<int> &activeArcIds) {
  std::vector<int> boundaryArcIds;
  std::map<std::uint64_t, std::vector<int>> incidentByEndpoint;
  for (const int arcId : activeArcIds) {
    if (arcId < 0 || arcId >= static_cast<int>(arcs.size())) {
      continue;
    }
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
    if (!arc.boundaryRail) {
      continue;
    }
    boundaryArcIds.push_back(arcId);
    incidentByEndpoint[embedded_endpoint_key(arc, true)].push_back(arcId);
    incidentByEndpoint[embedded_endpoint_key(arc, false)].push_back(arcId);
  }

  std::set<int> visited;
  int closedCycles = 0;
  for (const int seedArcId : boundaryArcIds) {
    if (visited.count(seedArcId) != 0) {
      continue;
    }

    std::vector<int> pending{seedArcId};
    std::set<int> componentArcs;
    std::set<std::uint64_t> componentEndpoints;
    while (!pending.empty()) {
      const int arcId = pending.back();
      pending.pop_back();
      if (!visited.insert(arcId).second) {
        continue;
      }
      componentArcs.insert(arcId);
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
      for (const bool start : {true, false}) {
        const std::uint64_t endpoint = embedded_endpoint_key(arc, start);
        componentEndpoints.insert(endpoint);
        const auto found = incidentByEndpoint.find(endpoint);
        if (found == incidentByEndpoint.end()) {
          continue;
        }
        for (const int adjacentArcId : found->second) {
          if (visited.count(adjacentArcId) == 0) {
            pending.push_back(adjacentArcId);
          }
        }
      }
    }

    bool closed = componentArcs.size() >= 3U &&
                  componentEndpoints.size() >= 3U;
    for (const std::uint64_t endpoint : componentEndpoints) {
      int degree = 0;
      const auto found = incidentByEndpoint.find(endpoint);
      if (found != incidentByEndpoint.end()) {
        for (const int arcId : found->second) {
          degree += componentArcs.count(arcId) != 0 ? 1 : 0;
        }
      }
      if (degree != 2) {
        closed = false;
        break;
      }
    }
    if (closed) {
      ++closedCycles;
    }
  }
  return closedCycles;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry {

FlowRepSparseNetwork select_sparse_flow_rep_network(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<FlowRepCoverageSample> &coverageSamples,
    const std::vector<FlowRepCycleInput> &cycles,
    const FlowRepSparseOptions &options) {
  FlowRepSparseNetwork network;
  network.coverageSampleCount = static_cast<int>(coverageSamples.size());
  network.cycleEvidenceCount = static_cast<int>(cycles.size());

  std::vector<unsigned char> active(arcs.size(), static_cast<unsigned char>(0));
  std::vector<int> denseArcIds;
  denseArcIds.reserve(arcs.size());
  bool invalidArcIdentity = false;
  for (int index = 0; index < static_cast<int>(arcs.size()); ++index) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(index)];
    if (arc.mandatoryRail) {
      ++network.mandatoryRails;
    }
    if (arc.id != index) {
      invalidArcIdentity = true;
      continue;
    }
    active[static_cast<std::size_t>(index)] =
        static_cast<unsigned char>(arc.initiallyActive ? 1 : 0);
    if (arc.initiallyActive) {
      denseArcIds.push_back(arc.id);
    }
  }
  if (invalidArcIdentity) {
    network.failureCode = FlowRepSelectionFailureCode::InvalidArcIdentity;
    for (int index = 0; index < static_cast<int>(arcs.size()); ++index) {
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(index)];
      if (arc.initiallyActive) {
        // IDs are invalid, so report safe vector identities for diagnostics.
        network.retainedArcIds.push_back(index);
        if (arc.mandatoryRail) {
          ++network.retainedMandatoryRails;
        }
      } else {
        network.removedArcIds.push_back(index);
      }
    }
    return network;
  }

  const auto finish_failure = [&](const FlowRepSelectionFailureCode code) {
    network.selectionSucceeded = false;
    network.failureCode = code;
    network.retainedArcIds.clear();
    network.removedArcIds.clear();
    network.retainedMandatoryRails = 0;
    for (const FlowRepArc &arc : arcs) {
      if (arc.initiallyActive) {
        network.retainedArcIds.push_back(arc.id);
        if (arc.mandatoryRail) {
          ++network.retainedMandatoryRails;
        }
      } else {
        network.removedArcIds.push_back(arc.id);
      }
    }
    if (!network.retainedArcIds.empty()) {
      network.endpointTags =
          flow_rep_detail::classify_endpoints(arcs, network.retainedArcIds);
    }
    if (network.coverageEvidenceUsed) {
      network.sparseCoverageMax = flow_rep_detail::coverage_max_distance(
          arcs, network.retainedArcIds, coverageSamples);
    }
    return network;
  };

  if (denseArcIds.empty()) {
    return finish_failure(FlowRepSelectionFailureCode::EmptyNetwork);
  }

  // A network containing only authoritative rails has no optional strand to
  // simplify. Treat it as a successful no-op, but still validate and report
  // the evidence supplied by the producer. Coverage samples prove that the
  // retained rails represent their embedded geometry. Closed boundary rails
  // provide cycle evidence even though they are constraints rather than
  // proposal-generated cell boundaries.
  const bool constraintOnlyNetwork =
      std::all_of(denseArcIds.begin(), denseArcIds.end(), [&](const int arcId) {
        const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
        return arc.mandatoryRail || arc.boundaryRail || arc.hardFeatureRail;
      });
  if (constraintOnlyNetwork) {
    if (!coverageSamples.empty()) {
      for (const FlowRepCoverageSample &sample : coverageSamples) {
        if (!flow_rep_detail::coverage_sample_is_valid(sample) ||
            sample.sourceArcId < 0 ||
            sample.sourceArcId >= static_cast<int>(arcs.size()) ||
            !arcs[static_cast<std::size_t>(sample.sourceArcId)].initiallyActive ||
            sample.sourceFace !=
                arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceFace ||
            sample.sourceComponent !=
                arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceComponent ||
            sample.sourceSheet !=
                arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceSheet) {
          return finish_failure(
              FlowRepSelectionFailureCode::InvalidCoverageEvidence);
        }
      }
      network.coverageEvidenceUsed = true;
      network.denseCoverageMax = flow_rep_detail::coverage_max_distance(
          arcs, denseArcIds, coverageSamples);
      if (!std::isfinite(network.denseCoverageMax)) {
        return finish_failure(
            FlowRepSelectionFailureCode::InvalidCoverageEvidence);
      }
      network.sparseCoverageMax = network.denseCoverageMax;
    }

    if (!cycles.empty()) {
      network.cycleEvaluations.reserve(cycles.size());
      for (const FlowRepCycleInput &cycle : cycles) {
        if (!flow_rep_detail::cycle_input_is_structurally_valid(cycle, arcs)) {
          return finish_failure(
              FlowRepSelectionFailureCode::InvalidCycleEvidence);
        }
        const FlowRepCycleEvaluation evaluation =
            flow_rep_detail::rebuild_cycle_evaluation(cycle, arcs, active);
        if (!evaluation.descriptive || !evaluation.quadrangulable) {
          return finish_failure(
              FlowRepSelectionFailureCode::InvalidCycleEvidence);
        }
        network.cycleEvaluations.push_back(evaluation);
      }
      network.cycleEvidenceUsed = true;
      network.cycleEvidenceCount = static_cast<int>(cycles.size());
    } else {
      const int closedBoundaryCycles =
          flow_rep_detail::count_closed_boundary_cycles(arcs, denseArcIds);
      if (closedBoundaryCycles > 0) {
        network.cycleEvidenceUsed = true;
        network.cycleEvidenceCount = closedBoundaryCycles;
      }
    }

    network.selectionSucceeded = true;
    network.failureCode = FlowRepSelectionFailureCode::None;
    network.retainedArcIds = denseArcIds;
    for (const int arcId : denseArcIds) {
      if (arcs[static_cast<std::size_t>(arcId)].mandatoryRail) {
        ++network.retainedMandatoryRails;
      }
    }
    for (const FlowRepArc &arc : arcs) {
      if (!arc.initiallyActive) {
        network.removedArcIds.push_back(arc.id);
      }
    }
    network.endpointTags =
        flow_rep_detail::classify_endpoints(arcs, network.retainedArcIds);
    const std::vector<FlowRepFlowline> retainedFlowlines =
        flow_rep_detail::extract_transactional_flowlines(arcs, denseArcIds);
    network.retainedFlowlines =
        static_cast<int>(retainedFlowlines.size());
    network.removedFlowlines = 0;
    return network;
  }

  // Absence of required evidence is the primary failure. Do not obscure it
  // with secondary provenance validation on an input that cannot be selected.
  if (coverageSamples.empty() && options.requireCoverageEvidence) {
    return finish_failure(
        FlowRepSelectionFailureCode::MissingCoverageEvidence);
  }
  if (options.requireCompleteProvenance) {
    for (const FlowRepArc &arc : arcs) {
      if (!flow_rep_detail::arc_has_complete_provenance(arc)) {
        return finish_failure(
            FlowRepSelectionFailureCode::IncompleteArcProvenance);
      }
    }
  }

  if (!coverageSamples.empty()) {
    for (const FlowRepCoverageSample &sample : coverageSamples) {
      if (!flow_rep_detail::coverage_sample_is_valid(sample) ||
          sample.sourceArcId >= static_cast<int>(arcs.size()) ||
          !arcs[static_cast<std::size_t>(sample.sourceArcId)].initiallyActive ||
          sample.sourceFace !=
              arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceFace ||
          sample.sourceComponent !=
              arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceComponent ||
          sample.sourceSheet !=
              arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceSheet) {
        return finish_failure(
            FlowRepSelectionFailureCode::InvalidCoverageEvidence);
      }
    }
    network.coverageEvidenceUsed = true;
    network.denseCoverageMax = flow_rep_detail::coverage_max_distance(
        arcs, denseArcIds, coverageSamples);
    if (!std::isfinite(network.denseCoverageMax)) {
      return finish_failure(
          FlowRepSelectionFailureCode::InvalidCoverageEvidence);
    }
  }

  std::vector<std::vector<int>> arcToCycles(arcs.size());
  if (cycles.empty()) {
    if (options.requireCycleEvidence) {
      return finish_failure(FlowRepSelectionFailureCode::MissingCycleEvidence);
    }
  } else {
    std::vector<unsigned char> coveredByCycle(arcs.size(),
                                               static_cast<unsigned char>(0));
    network.cycleEvaluations.reserve(cycles.size());
    for (int cycleIndex = 0; cycleIndex < static_cast<int>(cycles.size());
         ++cycleIndex) {
      const FlowRepCycleInput &cycle =
          cycles[static_cast<std::size_t>(cycleIndex)];
      if (!flow_rep_detail::cycle_input_is_structurally_valid(cycle, arcs)) {
        return finish_failure(
            FlowRepSelectionFailureCode::InvalidCycleEvidence);
      }
      for (const int arcId : cycle.boundaryArcIds) {
        arcToCycles[static_cast<std::size_t>(arcId)].push_back(cycleIndex);
        coveredByCycle[static_cast<std::size_t>(arcId)] =
            static_cast<unsigned char>(1);
        for (const int substituteId :
             arcs[static_cast<std::size_t>(arcId)].substitutions) {
          if (substituteId >= 0 &&
              substituteId < static_cast<int>(arcs.size())) {
            arcToCycles[static_cast<std::size_t>(substituteId)].push_back(
                cycleIndex);
          }
        }
      }
      network.cycleEvaluations.push_back(
          flow_rep_detail::rebuild_cycle_evaluation(cycle, arcs, active));
    }
    for (const FlowRepArc &arc : arcs) {
      if (arc.initiallyActive && arc.proposalId >= 0 &&
          coveredByCycle[static_cast<std::size_t>(arc.id)] == 0) {
        return finish_failure(
            FlowRepSelectionFailureCode::IncompleteCycleCoverage);
      }
    }
    if (!flow_rep_detail::cycle_evaluations_are_valid(
            network.cycleEvaluations)) {
      return finish_failure(FlowRepSelectionFailureCode::InvalidCycleEvidence);
    }
    for (std::vector<int> &affected : arcToCycles) {
      std::stable_sort(affected.begin(), affected.end());
      affected.erase(std::unique(affected.begin(), affected.end()),
                     affected.end());
    }
    network.cycleEvidenceUsed = true;
  }

  const auto active_arc_ids = [&]() {
    std::vector<int> ids;
    ids.reserve(arcs.size());
    for (const FlowRepArc &arc : arcs) {
      if (active[static_cast<std::size_t>(arc.id)] != 0) {
        ids.push_back(arc.id);
      }
    }
    return ids;
  };
  const auto rebuild_affected_cycles =
      [&](const std::vector<int> &affectedCycles,
          std::vector<FlowRepCycleEvaluation> &evaluations) {
        for (const int cycleIndex : affectedCycles) {
          evaluations[static_cast<std::size_t>(cycleIndex)] =
              flow_rep_detail::rebuild_cycle_evaluation(
                  cycles[static_cast<std::size_t>(cycleIndex)], arcs, active);
          ++network.cycleRebuilds;
        }
      };
  const auto transaction_is_valid =
      [&](const std::vector<int> &trialArcIds,
          const std::vector<FlowRepCycleEvaluation> &trialCycles) {
        const double trialCoverage =
            network.coverageEvidenceUsed
                ? flow_rep_detail::coverage_max_distance(
                      arcs, trialArcIds, coverageSamples)
                : 0.0;
        const bool coverageOk =
            !network.coverageEvidenceUsed ||
            (std::isfinite(trialCoverage) &&
             trialCoverage - network.denseCoverageMax <=
                 options.maxCoverageWorsening);
        const bool cyclesOk =
            !network.cycleEvidenceUsed ||
            flow_rep_detail::cycle_evaluations_are_valid(trialCycles);
        return std::make_pair(coverageOk && cyclesOk, trialCoverage);
      };

  const std::vector<FlowRepFlowline> denseFlowlines =
      flow_rep_detail::extract_transactional_flowlines(arcs, denseArcIds);
  const std::map<std::uint64_t, int> protectedEndpointDegrees =
      flow_rep_detail::protected_endpoint_degrees(arcs, denseArcIds);

  std::vector<int> removableFlowlines;
  for (const FlowRepFlowline &flowline : denseFlowlines) {
    if (!flowline.mandatory) {
      removableFlowlines.push_back(flowline.id);
    }
  }
  std::stable_sort(removableFlowlines.begin(), removableFlowlines.end(),
                   [&](const int a, const int b) {
    const FlowRepFlowline &aa = denseFlowlines[static_cast<std::size_t>(a)];
    const FlowRepFlowline &bb = denseFlowlines[static_cast<std::size_t>(b)];
    const auto objective = [&](const FlowRepFlowline &flowline) {
      double dominance = 0.0;
      double alignment = 0.0;
      int minId = std::numeric_limits<int>::max();
      for (const int arcId : flowline.arcIds) {
        const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
        dominance += arc.dominance;
        alignment += arc.alignmentCost;
        minId = std::min(minId, arcId);
      }
      return std::make_tuple(dominance, -alignment, minId);
    };
    return objective(aa) < objective(bb);
  });

  for (const int flowlineId : removableFlowlines) {
    const FlowRepFlowline &flowline =
        denseFlowlines[static_cast<std::size_t>(flowlineId)];
    bool allActive = true;
    for (const int arcId : flowline.arcIds) {
      allActive = allActive && active[static_cast<std::size_t>(arcId)] != 0;
    }
    if (!allActive) {
      continue;
    }
    ++network.attemptedStrandTransactions;
    std::vector<int> affected;
    for (const int arcId : flowline.arcIds) {
      active[static_cast<std::size_t>(arcId)] = static_cast<unsigned char>(0);
      affected.insert(affected.end(),
                      arcToCycles[static_cast<std::size_t>(arcId)].begin(),
                      arcToCycles[static_cast<std::size_t>(arcId)].end());
    }
    std::stable_sort(affected.begin(), affected.end());
    affected.erase(std::unique(affected.begin(), affected.end()),
                   affected.end());
    std::vector<FlowRepCycleEvaluation> trialCycles = network.cycleEvaluations;
    if (network.cycleEvidenceUsed) {
      rebuild_affected_cycles(affected, trialCycles);
    }
    const std::vector<int> trial = active_arc_ids();
    const auto [evidenceAccepted, trialCoverage] =
        transaction_is_valid(trial, trialCycles);
    (void)trialCoverage;
    const bool endpointsAccepted =
        flow_rep_detail::preserves_protected_endpoint_degrees(
            arcs, trial, protectedEndpointDegrees);
    if (!evidenceAccepted || !endpointsAccepted) {
      for (const int arcId : flowline.arcIds) {
        active[static_cast<std::size_t>(arcId)] = static_cast<unsigned char>(1);
      }
      ++network.rejectedStrandTransactions;
    } else {
      network.cycleEvaluations = std::move(trialCycles);
      ++network.acceptedTransactions;
    }
  }

  for (const FlowRepFlowline &flowline : denseFlowlines) {
    bool allActive = !flowline.arcIds.empty();
    for (const int arcId : flowline.arcIds) {
      allActive = allActive && active[static_cast<std::size_t>(arcId)] != 0;
    }
    if (!allActive || flowline.mandatory) {
      continue;
    }

    std::vector<int> substitutes;
    substitutes.reserve(flowline.arcIds.size());
    double currentObjective = 0.0;
    double substituteObjective = 0.0;
    bool completeSubstitution = true;
    for (const int arcId : flowline.arcIds) {
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
      currentObjective += arc.dominance + arc.alignmentCost;
      int chosen = -1;
      for (const int substituteId : arc.substitutions) {
        if (substituteId < 0 || substituteId >= static_cast<int>(arcs.size()) ||
            active[static_cast<std::size_t>(substituteId)] != 0 ||
            arcs[static_cast<std::size_t>(substituteId)].mandatoryRail ||
            std::find(substitutes.begin(), substitutes.end(), substituteId) !=
                substitutes.end()) {
          continue;
        }
        chosen = substituteId;
        break;
      }
      if (chosen < 0) {
        completeSubstitution = false;
        break;
      }
      substitutes.push_back(chosen);
      const FlowRepArc &substitute = arcs[static_cast<std::size_t>(chosen)];
      substituteObjective += substitute.dominance + substitute.alignmentCost;
    }
    if (!completeSubstitution ||
        substituteObjective >= currentObjective - 1.0e-14) {
      continue;
    }

    const std::vector<FlowRepFlowline> substituteFlowlines =
        flow_rep_detail::extract_transactional_flowlines(arcs, substitutes);
    if (substituteFlowlines.size() != 1U ||
        substituteFlowlines.front().arcIds.size() != substitutes.size() ||
        substituteFlowlines.front().closed != flowline.closed) {
      continue;
    }

    ++network.attemptedStrandTransactions;
    std::vector<int> affected;
    for (const int arcId : flowline.arcIds) {
      active[static_cast<std::size_t>(arcId)] = static_cast<unsigned char>(0);
      affected.insert(affected.end(),
                      arcToCycles[static_cast<std::size_t>(arcId)].begin(),
                      arcToCycles[static_cast<std::size_t>(arcId)].end());
    }
    for (const int substituteId : substitutes) {
      active[static_cast<std::size_t>(substituteId)] =
          static_cast<unsigned char>(1);
      affected.insert(
          affected.end(),
          arcToCycles[static_cast<std::size_t>(substituteId)].begin(),
          arcToCycles[static_cast<std::size_t>(substituteId)].end());
    }
    std::stable_sort(affected.begin(), affected.end());
    affected.erase(std::unique(affected.begin(), affected.end()),
                   affected.end());
    std::vector<FlowRepCycleEvaluation> trialCycles = network.cycleEvaluations;
    if (network.cycleEvidenceUsed) {
      rebuild_affected_cycles(affected, trialCycles);
    }
    const std::vector<int> trial = active_arc_ids();
    const auto [evidenceAccepted, trialCoverage] =
        transaction_is_valid(trial, trialCycles);
    (void)trialCoverage;
    const bool endpointsAccepted =
        flow_rep_detail::preserves_protected_endpoint_degrees(
            arcs, trial, protectedEndpointDegrees);
    if (!evidenceAccepted || !endpointsAccepted) {
      for (const int arcId : flowline.arcIds) {
        active[static_cast<std::size_t>(arcId)] = static_cast<unsigned char>(1);
      }
      for (const int substituteId : substitutes) {
        active[static_cast<std::size_t>(substituteId)] =
            static_cast<unsigned char>(0);
      }
      ++network.rejectedStrandTransactions;
    } else {
      network.cycleEvaluations = std::move(trialCycles);
      ++network.acceptedTransactions;
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
  if (network.retainedMandatoryRails != network.mandatoryRails) {
    return finish_failure(FlowRepSelectionFailureCode::MandatoryRailLoss);
  }
  network.sparseCoverageMax =
      network.coverageEvidenceUsed
          ? flow_rep_detail::coverage_max_distance(
                arcs, network.retainedArcIds, coverageSamples)
          : 0.0;
  network.endpointTags =
      flow_rep_detail::classify_endpoints(arcs, network.retainedArcIds);

  // Report the flowlines that actually exist in the committed sparse
  // network. Counting only the initially active dense flowlines loses
  // substitute flowlines that are activated by a successful transaction.
  const std::vector<FlowRepFlowline> retainedFlowlines =
      flow_rep_detail::extract_transactional_flowlines(
          arcs, network.retainedArcIds);
  network.retainedFlowlines =
      static_cast<int>(retainedFlowlines.size());

  // A dense flowline is removed when its atomic transaction is no longer
  // fully active. This remains a count over the original dense network so
  // diagnostics distinguish replaced/removed inputs from the committed
  // sparse result above.
  for (const FlowRepFlowline &flowline : denseFlowlines) {
    bool retained = !flowline.arcIds.empty();
    for (const int arcId : flowline.arcIds) {
      retained = retained && active[static_cast<std::size_t>(arcId)] != 0;
    }
    if (!retained) {
      ++network.removedFlowlines;
    }
  }
  network.selectionSucceeded = true;
  network.failureCode = FlowRepSelectionFailureCode::None;
  return network;
}

} // namespace directional::geometry

namespace directional::geometry {

FlowRepOverlay make_flow_rep_overlay(
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
