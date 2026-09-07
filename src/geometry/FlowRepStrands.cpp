#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/SurfaceArrangement.h>

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
  if (arc.sourceFace < 0 || !arc.sourceTopologyRegion.has_value() ||
      !arc.sourceIsolationSheet.has_value() ||
      !valid_barycentric(arc.startBarycentric) ||
      !valid_barycentric(arc.endBarycentric) || !finite_row3(arc.start) ||
      !finite_row3(arc.end) || arc_length(arc) <= 0.0) {
    return false;
  }
  if (arc.mandatoryRail) {
    return arc.initiallyActive && arc.railId.has_value() && arc.curveId >= 0 &&
           (arc.boundaryRail || arc.hardFeatureRail);
  }
  if (arc.layoutSupport) {
    return !arc.boundaryRail && !arc.hardFeatureRail && !arc.railId.has_value() &&
           arc.curveId < 0 && arc.proposalId < 0 && arc.supportTraceId >= 0 &&
           arc.supportSeedId >= 0 && arc.supportSegment >= 0 &&
           arc.sameStrandHint == arc.supportTraceId;
  }
  return arc.proposalId >= 0 && arc.proposalSide >= 0 &&
         arc.proposalSide < 6 && arc.proposalBoundarySegment >= 0;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool coverage_sample_is_valid(const FlowRepCoverageSample &sample) {
  return finite_row3(sample.position) && sample.sourceFace >= 0 &&
         sample.sourceTopologyRegion.has_value() &&
         sample.sourceIsolationSheet.has_value() &&
         valid_barycentric(sample.barycentric) &&
         std::isfinite(sample.targetSize) && sample.targetSize > 0.0 &&
         sample.sourceArcId >= 0;
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

bool sample_and_arc_are_intrinsically_compatible(
    const FlowRepCoverageSample &sample, const FlowRepArc &arc) {
  return sample.sourceFace == arc.sourceFace &&
         sample.sourceTopologyRegion == arc.sourceTopologyRegion &&
         sample.sourceIsolationSheet == arc.sourceIsolationSheet;
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

struct CoverageCandidate {
  int arcId = -1;
  double normalizedDistance = std::numeric_limits<double>::infinity();
};

struct CoverageIndex {
  std::vector<std::vector<CoverageCandidate>> candidatesBySample;
};

CoverageIndex build_coverage_index(
    const std::vector<FlowRepArc> &arcs,
    const std::vector<FlowRepCoverageSample> &samples) {
  int maximumSourceFace = -1;
  for (const FlowRepArc &arc : arcs) {
    maximumSourceFace = std::max(maximumSourceFace, arc.sourceFace);
  }
  for (const FlowRepCoverageSample &sample : samples) {
    maximumSourceFace = std::max(maximumSourceFace, sample.sourceFace);
  }

  std::vector<std::vector<int>> arcsBySourceFace(
      static_cast<std::size_t>(maximumSourceFace + 1));
  for (int arcIndex = 0; arcIndex < static_cast<int>(arcs.size()); ++arcIndex) {
    const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcIndex)];
    if (arc.sourceFace >= 0) {
      arcsBySourceFace[static_cast<std::size_t>(arc.sourceFace)].push_back(
          arcIndex);
    }
  }

  CoverageIndex index;
  index.candidatesBySample.resize(samples.size());
  for (int sampleIndex = 0; sampleIndex < static_cast<int>(samples.size());
       ++sampleIndex) {
    const FlowRepCoverageSample &sample =
        samples[static_cast<std::size_t>(sampleIndex)];
    if (sample.sourceFace < 0 ||
        sample.sourceFace >= static_cast<int>(arcsBySourceFace.size())) {
      continue;
    }
    std::vector<CoverageCandidate> &candidates =
        index.candidatesBySample[static_cast<std::size_t>(sampleIndex)];
    for (const int arcIndex :
         arcsBySourceFace[static_cast<std::size_t>(sample.sourceFace)]) {
      const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcIndex)];
      if (!sample_and_arc_are_intrinsically_compatible(sample, arc)) {
        continue;
      }
      candidates.push_back(
          {arcIndex, normalized_intrinsic_sample_distance(sample, arc)});
    }
  }
  return index;
}

double coverage_max_distance(
    const CoverageIndex &index, const std::vector<unsigned char> &active) {
  if (index.candidatesBySample.empty()) {
    return 0.0;
  }
  double maximumDistance = 0.0;
  for (const std::vector<CoverageCandidate> &candidates :
       index.candidatesBySample) {
    double nearest = std::numeric_limits<double>::infinity();
    for (const CoverageCandidate &candidate : candidates) {
      if (candidate.arcId < 0 ||
          candidate.arcId >= static_cast<int>(active.size()) ||
          active[static_cast<std::size_t>(candidate.arcId)] == 0) {
        continue;
      }
      nearest = std::min(nearest, candidate.normalizedDistance);
    }
    if (!std::isfinite(nearest)) {
      return std::numeric_limits<double>::infinity();
    }
    maximumDistance = std::max(maximumDistance, nearest);
  }
  return maximumDistance;
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
    for (const bool start : {true, false}) {
      const Eigen::RowVector3d &point = start ? arc.start : arc.end;
      if (arc.boundaryRail) {
        tags.push_back(FlowRepEndpointTag::Boundary);
      } else if (arc.hardFeatureRail) {
        tags.push_back(FlowRepEndpointTag::Feature);
      } else if (start ? arc.startEmbeddedAnchor : arc.endEmbeddedAnchor) {
        tags.push_back(FlowRepEndpointTag::NetworkJunction);
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

namespace {

std::optional<std::pair<authority::TopologyRegionId,
                             authority::IsolationSheetId>> network_source_scope(
    const SurfaceCellNetwork &network, const int sourceFace) {
  if (!network.sourceTopologyRegions.has_value() || sourceFace < 0) {
    return std::nullopt;
  }
  const SourceTopologyRegions &authority = *network.sourceTopologyRegions;
  const auto row = authority::SourceFaceId::from_index(
      sourceFace, authority.face_count());
  if (!row) return std::nullopt;
  return std::make_pair(authority.region_for_row(row.value()),
                        authority.sheet_for_row(row.value()));
}

std::optional<std::pair<authority::TopologyRegionId,
                        authority::IsolationSheetId>> tracing_source_scope(
    const SurfaceCellTracingOptions &options, const int sourceFace) {
  if (options.sourceAuthority == nullptr || sourceFace < 0) {
    return std::nullopt;
  }
  const auto row = authority::SourceFaceId::from_index(
      sourceFace, options.sourceAuthority->face_count());
  if (!row) return std::nullopt;
  return std::make_pair(options.sourceAuthority->region_for_row(row.value()),
                        options.sourceAuthority->sheet_for_row(row.value()));
}

} // namespace

std::vector<FlowRepArc> build_flow_rep_arcs_from_network(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceCellNetwork &network) {
  std::vector<FlowRepArc> arcs;
  const auto append_segment = [&](const SurfaceTraceSegment &segment,
                                  const bool mandatory, const int proposalId,
                                  const int proposalSeedId,
                                  const int proposalSide,
                                  const int proposalBoundarySegment,
                                  const int supportTraceId,
                                  const int supportSeedId,
                                  const int supportSegment) {
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
    const auto sourceScope = network_source_scope(network, segment.face);
    arc.sourceTopologyRegion =
        sourceScope.has_value()
            ? std::optional<authority::TopologyRegionId>(sourceScope->first)
            : std::nullopt;
    arc.sourceIsolationSheet =
        sourceScope.has_value()
            ? std::optional<authority::IsolationSheetId>(sourceScope->second)
            : std::nullopt;
    arc.family = segment.family;
    arc.strandProvenance = proposalId;
    arc.featureProvenance = segment.exitEdge;
    arc.featureClass = segment.exitEdge;
    arc.proposalId = proposalId;
    arc.proposalSeedId = proposalSeedId;
    arc.proposalSide = proposalSide;
    arc.proposalBoundarySegment = proposalBoundarySegment;
    arc.layoutSupport = supportTraceId >= 0;
    arc.supportTraceId = supportTraceId;
    arc.supportSeedId = supportSeedId;
    arc.supportSegment = supportSegment;
    if (arc.layoutSupport) {
      arc.strandProvenance = -2 - supportTraceId;
      arc.sameStrandHint = supportTraceId;
    }
    arc.hardFeatureRail = mandatory || segment.railId.has_value();
    arc.mandatoryRail = mandatory || segment.railId.has_value();
    if (segment.railId.has_value()) {
      arc.featureProvenance = segment.curveId;
      arc.featureClass = 3;
      arc.railId = segment.railId;
      arc.curveId = segment.curveId;
      arc.railT0 = segment.railT0;
      arc.railT1 = segment.railT1;
      arc.sameStrandHint = -1;
    }
    flow_rep_detail::assign_intrinsic_endpoint_keys(arc, faces);
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
      const auto sourceScope = network_source_scope(network, a.sourceFace);
      arc.sourceTopologyRegion =
          sourceScope.has_value()
              ? std::optional<authority::TopologyRegionId>(sourceScope->first)
              : std::nullopt;
      arc.sourceIsolationSheet =
          sourceScope.has_value()
              ? std::optional<authority::IsolationSheetId>(sourceScope->second)
              : std::nullopt;
      arc.family = -1;
      arc.featureClass = rail.kind == SurfaceCellRailKind::Boundary ? 1 : 3;
      arc.mandatoryRail = true;
      arc.boundaryRail = rail.kind == SurfaceCellRailKind::Boundary;
      arc.hardFeatureRail = rail.kind == SurfaceCellRailKind::HardFeature;
      // HardRailId is the sole rail strand authority; no raw ordinal mirror.
      arc.featureProvenance = rail.curveId;
      arc.railId = rail.id;
      arc.curveId = rail.curveId;
      arc.railT0 = a.railParameter;
      arc.railT1 = b.railParameter;
      arc.sameStrandHint = -1;
      flow_rep_detail::assign_intrinsic_endpoint_keys(arc, faces);
      arcs.push_back(arc);
    }
  }

  // An open boundary/feature rail is a bridge unless the field layout connects
  // it to surrounding cells, and a cross-field singularity must emit its
  // separatrix branches to become an explicit layout node. Retain these
  // deterministic anchored traces as optional layout support. Traces that run
  // along a rail are already represented by the authoritative rail arc,
  // while budget/degenerate endpoints remain unresolved and are intentionally
  // excluded. A whole-path canonical key removes the same connector traced in
  // opposite directions without collapsing distinct paths that merely share a
  // segment or endpoint.
  std::set<std::vector<std::int64_t>> supportPathKeys;
  const auto quantized_barycentric = [](const double value) {
    return static_cast<std::int64_t>(std::llround(value * 1.0e12));
  };
  const auto encode_support_path = [&](const std::vector<SurfaceTraceSegment> &path,
                                       const bool reverse) {
    std::vector<std::int64_t> key;
    key.reserve(8U * path.size());
    for (int offset = 0; offset < static_cast<int>(path.size()); ++offset) {
      const int index = reverse ? static_cast<int>(path.size()) - 1 - offset
                                : offset;
      const SurfaceTraceSegment &segment =
          path[static_cast<std::size_t>(index)];
      const Eigen::RowVector3d &start =
          reverse ? segment.endBarycentric : segment.startBarycentric;
      const Eigen::RowVector3d &end =
          reverse ? segment.startBarycentric : segment.endBarycentric;
      key.push_back(segment.face);
      key.push_back(segment.family);
      for (int corner = 0; corner < 3; ++corner) {
        key.push_back(quantized_barycentric(start[corner]));
      }
      for (int corner = 0; corner < 3; ++corner) {
        key.push_back(quantized_barycentric(end[corner]));
      }
    }
    return key;
  };
  const auto terminal_is_embedded_anchor = [](const TraceTerminationReason reason) {
    return reason == TraceTerminationReason::Boundary ||
           reason == TraceTerminationReason::Feature ||
           reason == TraceTerminationReason::Captured ||
           reason == TraceTerminationReason::Singularity ||
           reason == TraceTerminationReason::RepeatedState;
  };
  std::set<int> indexAwareSingularityVertices;
  for (const SurfaceSingularitySeparatrix &separatrix :
       network.singularSeparatrices) {
    indexAwareSingularityVertices.insert(separatrix.sourceVertex);
  }
  if (network.traces.size() == 4U * network.seeds.size()) {
    for (int seedIndex = 0;
         seedIndex < static_cast<int>(network.seeds.size()); ++seedIndex) {
      const SurfaceTraceSeed &seed =
          network.seeds[static_cast<std::size_t>(seedIndex)];
      if (seed.provenance != SurfaceSeedProvenance::Boundary &&
          seed.provenance != SurfaceSeedProvenance::Feature &&
          seed.provenance != SurfaceSeedProvenance::Singularity) {
        continue;
      }
      if (seed.provenance == SurfaceSeedProvenance::Singularity &&
          indexAwareSingularityVertices.count(seed.sourceId) != 0U) {
        continue;
      }
      for (int branch = 0; branch < 4; ++branch) {
        const int traceId = 4 * seedIndex + branch;
        const SurfaceTraceResult &trace =
            network.traces[static_cast<std::size_t>(traceId)];
        if (trace.segments.empty() ||
            !terminal_is_embedded_anchor(trace.termination) ||
            trace.segments.front().railId.has_value()) {
          continue;
        }
        std::vector<SurfaceTraceSegment> supportPath;
        for (const SurfaceTraceSegment &segment : trace.segments) {
          if (segment.railId.has_value()) {
            break;
          }
          supportPath.push_back(segment);
        }
        if (supportPath.empty()) {
          continue;
        }
        std::vector<std::int64_t> forward =
            encode_support_path(supportPath, false);
        std::vector<std::int64_t> reverse =
            encode_support_path(supportPath, true);
        std::vector<std::int64_t> canonical =
            reverse < forward ? std::move(reverse) : std::move(forward);
        if (!supportPathKeys.insert(std::move(canonical)).second) {
          continue;
        }
        const std::size_t firstSupportArc = arcs.size();
        for (int segmentIndex = 0;
             segmentIndex < static_cast<int>(supportPath.size());
             ++segmentIndex) {
          append_segment(supportPath[static_cast<std::size_t>(segmentIndex)],
                         false, -1, -1, -1, -1, traceId, seed.id,
                         segmentIndex);
        }
        if (arcs.size() > firstSupportArc) {
          arcs[firstSupportArc].startEmbeddedAnchor = true;
          // A trace can enter an authoritative rail before its recorded
          // terminal reason. The rail suffix is intentionally omitted because
          // the authoritative rail is already represented, but that does not
          // transfer the full trace's terminal anchor to the last pre-rail
          // segment. Its endpoint must be connected by canonical rail ownership
          // or remain an explicit endpoint-completion obligation.
          arcs.back().endEmbeddedAnchor =
              supportPath.size() == trace.segments.size();
        }
      }
    }
  }

  // Index-aware singular separatrices own the source singularity topology.
  // Retain a nonempty budget-limited trace as well as an anchored one: its
  // open tip is an explicit completion obligation, whereas dropping it would
  // silently erase a required 3/5-valent branch from the arrangement.
  const int singularSupportTraceBase =
      static_cast<int>(4U * network.seeds.size());
  for (int separatrixIndex = 0;
       separatrixIndex <
       static_cast<int>(network.singularSeparatrices.size());
       ++separatrixIndex) {
    const SurfaceSingularitySeparatrix &separatrix =
        network.singularSeparatrices[static_cast<std::size_t>(
            separatrixIndex)];
    const SurfaceTraceResult &trace = separatrix.trace;
    if (trace.segments.empty() ||
        trace.termination == TraceTerminationReason::FieldMetadata ||
        trace.termination == TraceTerminationReason::SourceSheet ||
        trace.segments.front().railId.has_value()) {
      continue;
    }
    std::vector<SurfaceTraceSegment> supportPath;
    for (const SurfaceTraceSegment &segment : trace.segments) {
      if (segment.railId.has_value()) {
        break;
      }
      supportPath.push_back(segment);
    }
    if (supportPath.empty()) {
      continue;
    }
    std::vector<std::int64_t> forward =
        encode_support_path(supportPath, false);
    std::vector<std::int64_t> reverse =
        encode_support_path(supportPath, true);
    std::vector<std::int64_t> canonical =
        reverse < forward ? std::move(reverse) : std::move(forward);
    if (!supportPathKeys.insert(std::move(canonical)).second) {
      continue;
    }
    const int supportTraceId = singularSupportTraceBase + separatrixIndex;
    const std::size_t firstSupportArc = arcs.size();
    for (int segmentIndex = 0;
         segmentIndex < static_cast<int>(supportPath.size());
         ++segmentIndex) {
      append_segment(supportPath[static_cast<std::size_t>(segmentIndex)],
                     false, -1, -1, -1, -1, supportTraceId,
                     separatrix.sourceVertex, segmentIndex);
      arcs.back().singularitySupport = true;
    }
    if (arcs.size() > firstSupportArc) {
      arcs[firstSupportArc].startEmbeddedAnchor = true;
      // Preserve an embedded terminal only when the retained support path
      // actually reaches that terminal. A pre-rail prefix cannot inherit the
      // later Boundary/Feature/Captured label from the omitted rail suffix.
      arcs.back().endEmbeddedAnchor =
          supportPath.size() == trace.segments.size() &&
          terminal_is_embedded_anchor(trace.termination);
    }
  }

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
                       false, proposalId, proposal.seedId, side, segmentIndex,
                       -1, -1, -1);
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

  // Radial separatrices alone form graph bridges at a 3/5-valent field
  // singularity.  Insert one intrinsic transition ring in the source
  // one-ring so every radial branch bounds a local disk sector.  Each point
  // on a source edge is parameterized only by its two global endpoints and
  // the singular vertex target size; both incident faces therefore emit the
  // identical canonical point without a world-space weld tolerance.
  std::set<int> singularVertices;
  for (const SurfaceSingularitySeparatrix &separatrix :
       network.singularSeparatrices) {
    if (separatrix.sourceVertex >= 0 &&
        separatrix.sourceVertex < vertices.rows() &&
        separatrix.expectedValence > 0) {
      singularVertices.insert(separatrix.sourceVertex);
    }
  }
  const auto face_label = [](const std::vector<int> &labels, const int face) {
    return face >= 0 && face < static_cast<int>(labels.size())
               ? labels[static_cast<std::size_t>(face)]
               : -1;
  };
  const auto vertex_target_size = [&](const int vertex) {
    return surface_cell_tracing_detail::target_size_at_vertex(
        targetSize, vertex, defaultTargetSize);
  };
  const auto edge_fraction = [&](const int singularVertex,
                                 const int otherVertex) {
    const double length =
        (vertices.row(otherVertex) - vertices.row(singularVertex)).norm();
    if (!(length > 1.0e-14) || !std::isfinite(length)) {
      return 0.0;
    }
    const double localTargetSize =
        std::min(vertex_target_size(singularVertex),
                 vertex_target_size(otherVertex));
    constexpr double targetRadiusFraction = 0.25;
    constexpr double maximumEdgeFraction = 0.20;
    constexpr double minimumEdgeFraction = 1.0e-6;
    return std::clamp(targetRadiusFraction * localTargetSize / length,
                      minimumEdgeFraction, maximumEdgeFraction);
  };
  const int transitionRingTraceBase =
      static_cast<int>(4U * network.seeds.size() +
                       network.singularSeparatrices.size());
  std::map<int, std::vector<int>> transitionRingArcIdsByVertex;
  int transitionRingIndex = 0;
  for (const int singularVertex : singularVertices) {
    const int supportTraceId = transitionRingTraceBase + transitionRingIndex++;
    int supportSegment = 0;
    for (int face = 0; face < faces.rows(); ++face) {
      int singularCorner = -1;
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(face, corner) == singularVertex) {
          singularCorner = corner;
          break;
        }
      }
      if (singularCorner < 0) {
        continue;
      }
      const int firstCorner = (singularCorner + 1) % 3;
      const int secondCorner = (singularCorner + 2) % 3;
      const int firstVertex = faces(face, firstCorner);
      const int secondVertex = faces(face, secondCorner);
      const double firstFraction =
          edge_fraction(singularVertex, firstVertex);
      const double secondFraction =
          edge_fraction(singularVertex, secondVertex);
      if (!(firstFraction > 0.0) || !(secondFraction > 0.0)) {
        continue;
      }

      FlowRepArc arc;
      arc.id = static_cast<int>(input.arcs.size());
      arc.sourceFace = face;
      arc.startBarycentric[singularCorner] = 1.0 - firstFraction;
      arc.startBarycentric[firstCorner] = firstFraction;
      arc.endBarycentric[singularCorner] = 1.0 - secondFraction;
      arc.endBarycentric[secondCorner] = secondFraction;
      arc.start = surface_cell_tracing_detail::point_position(
          vertices, faces,
          SurfaceTracePoint{face, arc.startBarycentric});
      arc.end = surface_cell_tracing_detail::point_position(
          vertices, faces,
          SurfaceTracePoint{face, arc.endBarycentric});
      if (!arc.start.allFinite() || !arc.end.allFinite() ||
          (arc.end - arc.start).norm() <= 1.0e-14) {
        continue;
      }
      const auto sourceScope = network_source_scope(network, face);
      arc.sourceTopologyRegion =
          sourceScope.has_value()
              ? std::optional<authority::TopologyRegionId>(sourceScope->first)
              : std::nullopt;
      arc.sourceIsolationSheet =
          sourceScope.has_value()
              ? std::optional<authority::IsolationSheetId>(sourceScope->second)
              : std::nullopt;
      // A transition ring is a protected topology-template boundary, not one
      // of the two transported cross-field families.
      arc.family = -1;
      arc.strandProvenance = -2 - supportTraceId;
      arc.sameStrandHint = supportTraceId;
      arc.layoutSupport = true;
      arc.supportTraceId = supportTraceId;
      arc.supportSeedId = singularVertex;
      arc.supportSegment = supportSegment++;
      arc.startEmbeddedAnchor = true;
      arc.endEmbeddedAnchor = true;
      arc.singularitySupport = true;
      flow_rep_detail::assign_intrinsic_endpoint_keys(arc, faces);
      transitionRingArcIdsByVertex[singularVertex].push_back(arc.id);
      input.arcs.push_back(std::move(arc));
    }
  }

  // A separatrix can take a numerically tiny tour through the singular
  // one-ring and enter an authoritative rail before it reaches the transition
  // ring. Retaining that pre-rail micro-loop creates a homoclinic edge at the
  // singular node: one DCEL face becomes a two-sided lens and its neighbor is
  // pinched. The authoritative rail already represents the omitted suffix, so
  // replace only these entirely intra-ring prefixes with the canonical radial
  // spoke defined by the enumerated branch ray and the intrinsic transition
  // ring. Branches that actually cross the ring keep their traced geometry.
  const int singularSupportTraceBase =
      static_cast<int>(4U * network.seeds.size());
  const auto barycentric_uv = [](const Eigen::RowVector3d &barycentric) {
    return Eigen::Vector2d(barycentric[1], barycentric[2]);
  };
  for (int separatrixIndex = 0;
       separatrixIndex <
       static_cast<int>(network.singularSeparatrices.size());
       ++separatrixIndex) {
    const SurfaceSingularitySeparatrix &separatrix =
        network.singularSeparatrices[static_cast<std::size_t>(
            separatrixIndex)];
    const int supportTraceId =
        singularSupportTraceBase + separatrixIndex;
    const auto foundRing =
        transitionRingArcIdsByVertex.find(separatrix.sourceVertex);
    if (foundRing == transitionRingArcIdsByVertex.end()) {
      continue;
    }

    std::vector<int> supportArcIds;
    for (const FlowRepArc &arc : input.arcs) {
      if (arc.initiallyActive && arc.singularitySupport && arc.family >= 0 &&
          arc.supportTraceId == supportTraceId) {
        supportArcIds.push_back(arc.id);
      }
    }
    if (supportArcIds.empty()) {
      continue;
    }
    std::sort(supportArcIds.begin(), supportArcIds.end(),
              [&](const int first, const int second) {
                const FlowRepArc &a =
                    input.arcs[static_cast<std::size_t>(first)];
                const FlowRepArc &b =
                    input.arcs[static_cast<std::size_t>(second)];
                return std::tie(a.supportSegment, a.id) <
                       std::tie(b.supportSegment, b.id);
              });

    double minimumRingRadius = std::numeric_limits<double>::infinity();
    const Eigen::RowVector3d singularPosition =
        vertices.row(separatrix.sourceVertex);
    for (const int ringArcId : foundRing->second) {
      const FlowRepArc &ring =
          input.arcs[static_cast<std::size_t>(ringArcId)];
      minimumRingRadius =
          std::min(minimumRingRadius,
                   std::min((ring.start - singularPosition).norm(),
                            (ring.end - singularPosition).norm()));
    }
    const double returnTolerance =
        std::isfinite(minimumRingRadius) && minimumRingRadius > 0.0
            ? std::max(1.0e-12, 1.0e-5 * minimumRingRadius)
            : 1.0e-12;

    int firstRingCrossingPosition = -1;
    for (int position = 0;
         position < static_cast<int>(supportArcIds.size()); ++position) {
      const FlowRepArc &support = input.arcs[static_cast<std::size_t>(
          supportArcIds[static_cast<std::size_t>(position)])];
      for (const int ringArcId : foundRing->second) {
        const FlowRepArc &ring =
            input.arcs[static_cast<std::size_t>(ringArcId)];
        if (support.sourceFace != ring.sourceFace) {
          continue;
        }
        surface_arrangement_detail::Segment2 supportSegment;
        supportSegment.start = barycentric_uv(support.startBarycentric);
        supportSegment.end = barycentric_uv(support.endBarycentric);
        surface_arrangement_detail::Segment2 ringSegment;
        ringSegment.start = barycentric_uv(ring.startBarycentric);
        ringSegment.end = barycentric_uv(ring.endBarycentric);
        double supportParameter = 0.0;
        double ringParameter = 0.0;
        Eigen::Vector2d point = Eigen::Vector2d::Zero();
        if (surface_arrangement_detail::segment_intersection_params(
                supportSegment, ringSegment, supportParameter,
                ringParameter, point) &&
            supportParameter > 1.0e-10) {
          firstRingCrossingPosition = position;
          break;
        }
      }
      if (firstRingCrossingPosition >= 0) {
        break;
      }
    }

    // Re-root a branch that numerically returns to its source singularity
    // before it first reaches the transition ring. The removed prefix lies
    // wholly inside the ring and therefore cannot encode global layout
    // topology; retaining it creates a tiny homoclinic loop and a pinched
    // DCEL face. The continuation remains the authoritative traced branch.
    int lastPreRingReturnPosition = -1;
    const int returnSearchEnd =
        firstRingCrossingPosition >= 0
            ? firstRingCrossingPosition
            : static_cast<int>(supportArcIds.size());
    for (int position = 0; position < returnSearchEnd; ++position) {
      const FlowRepArc &support = input.arcs[static_cast<std::size_t>(
          supportArcIds[static_cast<std::size_t>(position)])];
      if ((support.end - singularPosition).norm() <= returnTolerance) {
        lastPreRingReturnPosition = position;
      }
    }
    if (lastPreRingReturnPosition >= 0 &&
        lastPreRingReturnPosition + 1 <
            static_cast<int>(supportArcIds.size())) {
      const int continuationArcId =
          supportArcIds[static_cast<std::size_t>(
              lastPreRingReturnPosition + 1)];
      FlowRepArc &continuation =
          input.arcs[static_cast<std::size_t>(continuationArcId)];
      int singularCorner = -1;
      for (int corner = 0; corner < 3; ++corner) {
        if (faces(continuation.sourceFace, corner) ==
            separatrix.sourceVertex) {
          singularCorner = corner;
          break;
        }
      }
      if (singularCorner >= 0 &&
          (continuation.start - singularPosition).norm() <=
              returnTolerance) {
        for (int position = 0;
             position <= lastPreRingReturnPosition; ++position) {
          input.arcs[static_cast<std::size_t>(
              supportArcIds[static_cast<std::size_t>(position)])]
              .initiallyActive = false;
        }
        continuation.start = singularPosition;
        continuation.startBarycentric = Eigen::RowVector3d::Zero();
        continuation.startBarycentric[singularCorner] = 1.0;
        continuation.startEmbeddedAnchor = true;
        flow_rep_detail::assign_intrinsic_endpoint_keys(continuation, faces);
        continue;
      }
    }

    bool hasAuthoritativeRailSuffix = false;
    for (const SurfaceTraceSegment &segment : separatrix.trace.segments) {
      if (segment.railId.has_value()) {
        hasAuthoritativeRailSuffix = true;
        break;
      }
    }
    const bool terminalReturnNeedsSpoke =
        lastPreRingReturnPosition ==
        static_cast<int>(supportArcIds.size()) - 1;
    if (firstRingCrossingPosition >= 0 ||
        (!hasAuthoritativeRailSuffix && !terminalReturnNeedsSpoke)) {
      continue;
    }

    int firstSupportArcId = -1;
    int owningRingArcId = -1;
    for (const int supportArcId : supportArcIds) {
      const FlowRepArc &support =
          input.arcs[static_cast<std::size_t>(supportArcId)];
      if (support.sourceFace != separatrix.initialFace) {
        continue;
      }
      firstSupportArcId = supportArcId;
      for (const int ringArcId : foundRing->second) {
        if (input.arcs[static_cast<std::size_t>(ringArcId)].sourceFace ==
            separatrix.initialFace) {
          owningRingArcId = ringArcId;
          break;
        }
      }
      if (owningRingArcId >= 0) {
        break;
      }
    }
    if (firstSupportArcId < 0 || owningRingArcId < 0) {
      continue;
    }

    const FlowRepArc &firstSupport =
        input.arcs[static_cast<std::size_t>(firstSupportArcId)];
    const FlowRepArc &owningRing =
        input.arcs[static_cast<std::size_t>(owningRingArcId)];
    Eigen::RowVector3d vertexBarycentric = Eigen::RowVector3d::Zero();
    int singularCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      if (faces(separatrix.initialFace, corner) ==
          separatrix.sourceVertex) {
        singularCorner = corner;
        vertexBarycentric[corner] = 1.0;
        break;
      }
    }
    if (singularCorner < 0) {
      continue;
    }
    const Eigen::Vector2d vertexUv = barycentric_uv(vertexBarycentric);
    const Eigen::Vector2d firstStartUv =
        barycentric_uv(firstSupport.startBarycentric);
    const Eigen::Vector2d firstEndUv =
        barycentric_uv(firstSupport.endBarycentric);
    Eigen::Vector2d rayDirection = firstEndUv - firstStartUv;
    if ((firstStartUv - vertexUv).norm() >
        (firstEndUv - vertexUv).norm()) {
      rayDirection = firstStartUv - firstEndUv;
    }
    if (!(rayDirection.norm() > 1.0e-14) ||
        !rayDirection.allFinite()) {
      continue;
    }
    rayDirection.normalize();
    surface_arrangement_detail::Segment2 ray;
    ray.start = vertexUv;
    ray.end = vertexUv + 4.0 * rayDirection;
    surface_arrangement_detail::Segment2 ringSegment;
    ringSegment.start = barycentric_uv(owningRing.startBarycentric);
    ringSegment.end = barycentric_uv(owningRing.endBarycentric);
    double rayParameter = 0.0;
    double ringParameter = 0.0;
    Eigen::Vector2d intersection = Eigen::Vector2d::Zero();
    if (!surface_arrangement_detail::segment_intersection_params(
            ray, ringSegment, rayParameter, ringParameter, intersection) ||
        rayParameter <= 1.0e-10) {
      continue;
    }
    Eigen::RowVector3d ringBarycentric;
    ringBarycentric << 1.0 - intersection.x() - intersection.y(),
        intersection.x(), intersection.y();
    ringBarycentric =
        surface_arrangement_detail::canonicalize_barycentric(
            ringBarycentric);
    if (!ringBarycentric.allFinite() ||
        ringBarycentric.minCoeff() < -1.0e-10) {
      continue;
    }

    for (const int supportArcId : supportArcIds) {
      input.arcs[static_cast<std::size_t>(supportArcId)].initiallyActive =
          false;
    }
    FlowRepArc spoke = firstSupport;
    spoke.id = static_cast<int>(input.arcs.size());
    spoke.start = singularPosition;
    spoke.end = surface_cell_tracing_detail::point_position(
        vertices, faces,
        SurfaceTracePoint{separatrix.initialFace, ringBarycentric});
    spoke.sourceFace = separatrix.initialFace;
    spoke.startBarycentric = vertexBarycentric;
    spoke.endBarycentric = ringBarycentric;
    spoke.family = separatrix.family;
    spoke.featureProvenance = -1;
    spoke.supportSegment = 0;
    spoke.startEmbeddedAnchor = true;
    spoke.endEmbeddedAnchor = true;
    spoke.initiallyActive = true;
    spoke.substitutions.clear();
    flow_rep_detail::assign_intrinsic_endpoint_keys(spoke, faces);
    input.arcs.push_back(std::move(spoke));
  }

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
      sample.sourceTopologyRegion = arc.sourceTopologyRegion;
      sample.sourceIsolationSheet = arc.sourceIsolationSheet;
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
  if (adjacent && a.railId.has_value() && b.railId.has_value() &&
      a.railId == b.railId) {
    affinity.score = 0.75 + parallel;
    affinity.cue = FlowRepAffinityCue::JunctionContinuation;
    return affinity;
  }
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
      candidate.sourceTopologyRegion != original.sourceTopologyRegion ||
      candidate.sourceIsolationSheet != original.sourceIsolationSheet ||
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
  if (arc.mandatoryRail || arc.railId.has_value()) {
    return {0, arc.railId, arc.curveId, -1, arc.family, arc.sourceTopologyRegion};
  }
  if (arc.proposalId >= 0 && arc.proposalSide >= 0) {
    return {1, std::nullopt, arc.proposalId, arc.proposalSide, arc.family,
            arc.sourceTopologyRegion};
  }
  return {2, std::nullopt, arc.sameStrandHint, -1, arc.family,
          arc.sourceTopologyRegion};
}

} // namespace directional::geometry::flow_rep_detail

namespace directional::geometry::flow_rep_detail {

std::uint64_t embedded_endpoint_key(const FlowRepArc &arc,
                                    const bool start) {
  const bool intrinsicValid =
      start ? arc.startIntrinsicEndpointKeyValid
            : arc.endIntrinsicEndpointKeyValid;
  if (intrinsicValid) {
    return start ? arc.startIntrinsicEndpointKey
                 : arc.endIntrinsicEndpointKey;
  }
  std::uint64_t h = point_key(start ? arc.start : arc.end);
  const auto mix = [&](const std::int64_t value) {
    h ^= static_cast<std::uint64_t>(value);
    h *= 1099511628211ULL;
  };
  mix(arc.sourceTopologyRegion.has_value()
          ? static_cast<std::int64_t>(arc.sourceTopologyRegion->index())
          : -1);
  mix(arc.sourceIsolationSheet.has_value()
          ? static_cast<std::int64_t>(arc.sourceIsolationSheet->index())
          : -1);
  return h;
}

void assign_intrinsic_endpoint_keys(FlowRepArc &arc,
                                    const Eigen::MatrixXi &faces) {
  const auto key = [&](const Eigen::RowVector3d &barycentric) {
    const surface_arrangement_detail::NodeKey node =
        surface_arrangement_detail::make_node_key(
            faces, arc.sourceFace,
            surface_arrangement_detail::bary_to_uv(barycentric));
    std::uint64_t hash = 1469598103934665603ULL;
    const auto mix = [&](const std::int64_t value) {
      hash ^= static_cast<std::uint64_t>(value);
      hash *= 1099511628211ULL;
    };
    mix(node.kind);
    mix(node.face);
    mix(node.edge.has_value() ? node.edge->first().index() : -1);
    mix(node.edge.has_value() ? node.edge->second().index() : -1);
    mix(node.edgeT);
    mix(node.vertex);
    mix(node.u);
    mix(node.v);
    mix(arc.sourceTopologyRegion.has_value()
            ? static_cast<std::int64_t>(arc.sourceTopologyRegion->index())
            : -1);
    mix(arc.sourceIsolationSheet.has_value()
            ? static_cast<std::int64_t>(arc.sourceIsolationSheet->index())
            : -1);
    return hash;
  };
  if (arc.sourceFace < 0 || arc.sourceFace >= faces.rows() ||
      !arc.startBarycentric.allFinite() ||
      !arc.endBarycentric.allFinite()) {
    arc.startIntrinsicEndpointKeyValid = false;
    arc.endIntrinsicEndpointKeyValid = false;
    arc.startIntrinsicEndpointKey = 0U;
    arc.endIntrinsicEndpointKey = 0U;
    return;
  }
  arc.startIntrinsicEndpointKey = key(arc.startBarycentric);
  arc.endIntrinsicEndpointKey = key(arc.endBarycentric);
  arc.startIntrinsicEndpointKeyValid = true;
  arc.endIntrinsicEndpointKeyValid = true;
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
                           arc.boundaryRail || arc.hardFeatureRail ||
                           arc.singularitySupport;
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
      if (arc.boundaryRail || arc.hardFeatureRail || arc.mandatoryRail ||
          arc.singularitySupport) {
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

  const std::vector<unsigned char> initiallyActive = active;
  const flow_rep_detail::CoverageIndex coverageIndex =
      flow_rep_detail::build_coverage_index(arcs, coverageSamples);

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
          coverageIndex, initiallyActive);
    }
    return network;
  };

  if (denseArcIds.empty()) {
    return finish_failure(FlowRepSelectionFailureCode::EmptyNetwork);
  }

  // A network containing only authoritative rails and anchored layout-support
  // traces has no proposal cycle on which FlowRep can transact. Treat it as a
  // successful no-op, but still validate and report the supplied coverage.
  // This does not fabricate cycle evidence: closed boundary rails are counted
  // only when they actually close, and support-only networks report zero.
  const bool constraintOnlyNetwork =
      std::all_of(denseArcIds.begin(), denseArcIds.end(), [&](const int arcId) {
        const FlowRepArc &arc = arcs[static_cast<std::size_t>(arcId)];
        return arc.mandatoryRail || arc.boundaryRail || arc.hardFeatureRail ||
               arc.layoutSupport;
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
            sample.sourceTopologyRegion !=
                arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceTopologyRegion ||
            sample.sourceIsolationSheet !=
                arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceIsolationSheet) {
          return finish_failure(
              FlowRepSelectionFailureCode::InvalidCoverageEvidence);
        }
      }
      network.coverageEvidenceUsed = true;
      network.denseCoverageMax = flow_rep_detail::coverage_max_distance(
          coverageIndex, initiallyActive);
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
          sample.sourceTopologyRegion !=
              arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceTopologyRegion ||
          sample.sourceIsolationSheet !=
              arcs[static_cast<std::size_t>(sample.sourceArcId)].sourceIsolationSheet) {
        return finish_failure(
            FlowRepSelectionFailureCode::InvalidCoverageEvidence);
      }
    }
    network.coverageEvidenceUsed = true;
    network.denseCoverageMax = flow_rep_detail::coverage_max_distance(
        coverageIndex, initiallyActive);
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
        (void)trialArcIds;
        const double trialCoverage =
            network.coverageEvidenceUsed
                ? flow_rep_detail::coverage_max_distance(coverageIndex, active)
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
          ? flow_rep_detail::coverage_max_distance(coverageIndex, active)
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

namespace {

struct FlowRepEndpointCompletionDraft : FlowRepEndpointCompletionEvidence {
  bool success = false;
  FlowRepEndpointCompletionFailureKind failureKind =
      FlowRepEndpointCompletionFailureKind::None;
  std::string failure;
  std::vector<FlowRepArc> arcs;
  std::vector<int> retainedArcIds;
  std::vector<FlowRepEndpointTag> endpointTags;
};

FlowRepEndpointCompletionResult close_flow_rep_endpoint_completion(
    FlowRepEndpointCompletionDraft draft) {
  if (draft.success) {
    FlowRepEndpointCompletionEvidence evidence =
        std::move(static_cast<FlowRepEndpointCompletionEvidence &>(draft));
    FlowRepEndpointCompletionProduct product;
    product.arcs = std::move(draft.arcs);
    product.retainedArcIds = std::move(draft.retainedArcIds);
    product.endpointTags = std::move(draft.endpointTags);
    return FlowRepEndpointCompletionResult::produced(
        std::move(evidence), std::move(product));
  }
  if (draft.failureKind == FlowRepEndpointCompletionFailureKind::None) {
    throw std::logic_error(
        "FlowRep endpoint completion rejected without a typed failure.");
  }
  FlowRepEndpointCompletionFailure failure;
  failure.kind = draft.failureKind;
  failure.detail = std::move(draft.failure);
  FlowRepEndpointCompletionEvidence evidence =
      std::move(static_cast<FlowRepEndpointCompletionEvidence &>(draft));
  return FlowRepEndpointCompletionResult::rejected(
      std::move(evidence), std::move(failure));
}

} // namespace

FlowRepEndpointCompletionResult complete_flow_rep_endpoints(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &crossField,
    const SurfaceCellTracingOptions &tracingOptions,
    std::vector<FlowRepArc> arcs,
    std::vector<int> retainedArcIds,
    const FlowRepEndpointCompletionOptions &options) {
  FlowRepEndpointCompletionDraft result;
  result.arcs = std::move(arcs);
  result.retainedArcIds = std::move(retainedArcIds);
  if (options.maxEndpointTraces < 0 || options.maxAddedArcs < 0 ||
      !std::isfinite(options.intersectionTolerance) ||
      options.intersectionTolerance <= 0.0) {
    result.failureKind = FlowRepEndpointCompletionFailureKind::InvalidOptions;
    result.failure = "InvalidEndpointCompletionOptions";
    return close_flow_rep_endpoint_completion(std::move(result));
  }
  if (crossField.primaryDirections.rows() != faces.rows() ||
      crossField.primaryDirections.cols() != 3 ||
      crossField.secondaryDirections.rows() != faces.rows() ||
      crossField.secondaryDirections.cols() != 3) {
    result.failureKind = FlowRepEndpointCompletionFailureKind::IncompleteCrossFieldAxes;
    result.failure = "IncompleteCrossFieldAxes";
    return close_flow_rep_endpoint_completion(std::move(result));
  }

  const auto edgeFaces = surface_cell_tracing_detail::edge_faces(faces);
  std::vector<std::vector<int>> activeArcsByFace(
      static_cast<std::size_t>(faces.rows()));
  std::map<std::uint64_t, int> endpointDegree;
  struct RetainedFeatureRailInterval {
    double t0 = 0.0;
    double t1 = 0.0;
    std::optional<authority::TopologyRegionId> sourceTopologyRegion;
    std::set<authority::IsolationSheetId> incidentSourceSheets;
  };
  std::map<authority::SourceEdgeTopologyKey, std::vector<RetainedFeatureRailInterval>>
      retainedFeatureRailsByEdge;
  std::map<int, std::vector<RetainedFeatureRailInterval>>
      retainedFeatureRailsByVertex;
  std::vector<unsigned char> retained(result.arcs.size(), 0U);
  for (const int arcId : result.retainedArcIds) {
    if (arcId < 0 || arcId >= static_cast<int>(result.arcs.size()) ||
        result.arcs[static_cast<std::size_t>(arcId)].id != arcId) {
      result.failureKind = FlowRepEndpointCompletionFailureKind::InvalidRetainedArcIdentity;
      result.failure = "InvalidRetainedArcIdentity";
      return close_flow_rep_endpoint_completion(std::move(result));
    }
    if (retained[static_cast<std::size_t>(arcId)] != 0U) {
      result.failureKind = FlowRepEndpointCompletionFailureKind::DuplicateRetainedArc;
      result.failure = "DuplicateRetainedArc";
      return close_flow_rep_endpoint_completion(std::move(result));
    }
    retained[static_cast<std::size_t>(arcId)] = 1U;
    if (!flow_rep_detail::arc_has_complete_provenance(
            result.arcs[static_cast<std::size_t>(arcId)])) {
      result.failureKind = FlowRepEndpointCompletionFailureKind::IncompleteRetainedArcProvenance;
      result.failure = "IncompleteRetainedArcProvenance";
      return close_flow_rep_endpoint_completion(std::move(result));
    }
  }

  // Trace transitions can leave two retained chart endpoints on different
  // incident edges only a sub-tolerance distance from the same exact source
  // vertex. The arrangement identifies that vertex intrinsically, while a
  // per-face endpoint key keeps the unsanitized points separate and turns one
  // support segment into a bridge. Canonicalize only when at least two
  // distinct retained arcs prove ownership inside the same edge-connected
  // source-face fan. Faces that merely touch at a vertex remain separated, as
  // do different source components.
  struct NearVertexEndpoint {
    int arcId = -1;
    bool start = false;
    int sourceFace = -1;
    int sourceVertex = -1;
    std::optional<authority::TopologyRegionId> sourceTopologyRegion;
  };
  std::map<std::pair<int, std::optional<authority::TopologyRegionId>>,
           std::vector<NearVertexEndpoint>>
      nearVertexEndpoints;
  for (const int arcId : result.retainedArcIds) {
    const FlowRepArc &arc = result.arcs[static_cast<std::size_t>(arcId)];
    if (arc.sourceFace < 0 || arc.sourceFace >= faces.rows()) {
      continue;
    }
    for (const bool start : {true, false}) {
      const Eigen::RowVector3d &position = start ? arc.start : arc.end;
      if (!position.allFinite()) {
        continue;
      }
      int nearestVertex = -1;
      double nearestDistance = std::numeric_limits<double>::infinity();
      for (int corner = 0; corner < 3; ++corner) {
        const int vertex = faces(arc.sourceFace, corner);
        const double distance =
            (position - vertices.row(vertex)).norm();
        if (distance < nearestDistance) {
          nearestDistance = distance;
          nearestVertex = vertex;
        }
      }
      if (nearestVertex >= 0 &&
          nearestDistance <= options.intersectionTolerance) {
        nearVertexEndpoints[{nearestVertex, arc.sourceTopologyRegion}].push_back(
            {arcId, start, arc.sourceFace, nearestVertex,
             arc.sourceTopologyRegion});
      }
    }
  }
  const auto faces_share_vertex_edge = [&](const int firstFace,
                                            const int secondFace,
                                            const int vertex) {
    if (firstFace == secondFace) {
      return true;
    }
    int sharedVertices = 0;
    bool sharesVertex = false;
    for (int firstCorner = 0; firstCorner < 3; ++firstCorner) {
      const int firstVertex = faces(firstFace, firstCorner);
      for (int secondCorner = 0; secondCorner < 3; ++secondCorner) {
        if (firstVertex != faces(secondFace, secondCorner)) {
          continue;
        }
        ++sharedVertices;
        sharesVertex = sharesVertex || firstVertex == vertex;
      }
    }
    return sharesVertex && sharedVertices >= 2;
  };
  for (auto &[vertexComponent, endpoints] : nearVertexEndpoints) {
    const int sourceVertex = vertexComponent.first;
    std::vector<int> parent(endpoints.size());
    std::iota(parent.begin(), parent.end(), 0);
    const auto find_root = [&](int index) {
      int root = index;
      while (parent[static_cast<std::size_t>(root)] != root) {
        root = parent[static_cast<std::size_t>(root)];
      }
      while (parent[static_cast<std::size_t>(index)] != index) {
        const int next = parent[static_cast<std::size_t>(index)];
        parent[static_cast<std::size_t>(index)] = root;
        index = next;
      }
      return root;
    };
    for (int first = 0; first < static_cast<int>(endpoints.size()); ++first) {
      for (int second = first + 1;
           second < static_cast<int>(endpoints.size()); ++second) {
        if (!faces_share_vertex_edge(
                endpoints[static_cast<std::size_t>(first)].sourceFace,
                endpoints[static_cast<std::size_t>(second)].sourceFace,
                sourceVertex)) {
          continue;
        }
        const int firstRoot = find_root(first);
        const int secondRoot = find_root(second);
        if (firstRoot != secondRoot) {
          parent[static_cast<std::size_t>(secondRoot)] = firstRoot;
        }
      }
    }
    std::map<int, std::vector<int>> fanEndpoints;
    for (int endpointIndex = 0;
         endpointIndex < static_cast<int>(endpoints.size());
         ++endpointIndex) {
      fanEndpoints[find_root(endpointIndex)].push_back(endpointIndex);
    }
    for (const auto &[fan, endpointIndices] : fanEndpoints) {
      (void)fan;
      std::set<int> distinctArcs;
      for (const int endpointIndex : endpointIndices) {
        distinctArcs.insert(
            endpoints[static_cast<std::size_t>(endpointIndex)].arcId);
      }
      if (distinctArcs.size() < 2U) {
        continue;
      }
      for (const int endpointIndex : endpointIndices) {
        const NearVertexEndpoint &endpoint =
            endpoints[static_cast<std::size_t>(endpointIndex)];
        FlowRepArc &arc =
            result.arcs[static_cast<std::size_t>(endpoint.arcId)];
        Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
        for (int corner = 0; corner < 3; ++corner) {
          if (faces(arc.sourceFace, corner) == sourceVertex) {
            barycentric[corner] = 1.0;
            break;
          }
        }
        if (endpoint.start) {
          arc.start = vertices.row(sourceVertex);
          arc.startBarycentric = barycentric;
          arc.startEmbeddedAnchor = true;
        } else {
          arc.end = vertices.row(sourceVertex);
          arc.endBarycentric = barycentric;
          arc.endEmbeddedAnchor = true;
        }
      }
    }
  }

  for (const int arcId : result.retainedArcIds) {
    FlowRepArc &arc = result.arcs[static_cast<std::size_t>(arcId)];
    flow_rep_detail::assign_intrinsic_endpoint_keys(arc, faces);
    if (arc.sourceFace >= 0 && arc.sourceFace < faces.rows()) {
      activeArcsByFace[static_cast<std::size_t>(arc.sourceFace)].push_back(
          arcId);
      if (arc.hardFeatureRail) {
        const Eigen::RowVector3d startBarycentric =
            surface_arrangement_detail::canonicalize_barycentric(
                arc.startBarycentric);
        const Eigen::RowVector3d endBarycentric =
            surface_arrangement_detail::canonicalize_barycentric(
                arc.endBarycentric);
        int localEdge = -1;
        for (int edge = 0; edge < 3; ++edge) {
          if (std::abs(startBarycentric[edge]) <= 1.0e-10 &&
              std::abs(endBarycentric[edge]) <= 1.0e-10) {
            localEdge = edge;
            break;
          }
        }
        if (localEdge >= 0) {
          const Eigen::Vector2d startUv =
              surface_arrangement_detail::bary_to_uv(startBarycentric);
          const Eigen::Vector2d endUv =
              surface_arrangement_detail::bary_to_uv(endBarycentric);
          const double startT =
              surface_arrangement_detail::canonical_edge_parameter(
                  faces, arc.sourceFace, localEdge, startUv);
          const double endT =
              surface_arrangement_detail::canonical_edge_parameter(
                  faces, arc.sourceFace, localEdge, endUv);
          const authority::SourceEdgeTopologyKey edgeKey =
              surface_arrangement_detail::source_edge_key(
                  faces, arc.sourceFace, localEdge);
          RetainedFeatureRailInterval interval;
          interval.t0 = std::min(startT, endT);
          interval.t1 = std::max(startT, endT);
          interval.sourceTopologyRegion = arc.sourceTopologyRegion;
          const auto edgeOwner = edgeFaces.find(edgeKey);
          if (edgeOwner != edgeFaces.end()) {
            for (const int incidentFace : edgeOwner->second) {
              const auto incidentScope =
                  tracing_source_scope(tracingOptions, incidentFace);
              if (!incidentScope.has_value() ||
                  incidentScope->first != arc.sourceTopologyRegion) {
                continue;
              }
              interval.incidentSourceSheets.insert(incidentScope->second);
            }
          }
          if (interval.incidentSourceSheets.empty() &&
              arc.sourceIsolationSheet.has_value()) {
            interval.incidentSourceSheets.insert(*arc.sourceIsolationSheet);
          }
          const int edgeVertex0 =
              faces(arc.sourceFace, (localEdge + 1) % 3);
          const int edgeVertex1 =
              faces(arc.sourceFace, (localEdge + 2) % 3);
          const int canonicalVertex0 = std::min(edgeVertex0, edgeVertex1);
          const int canonicalVertex1 = std::max(edgeVertex0, edgeVertex1);
          const double edgeLength =
              (vertices.row(canonicalVertex1) -
               vertices.row(canonicalVertex0))
                  .norm();
          const double endpointParameterTolerance =
              std::isfinite(edgeLength) && edgeLength > 0.0
                  ? std::max(1.0e-10,
                             options.intersectionTolerance / edgeLength)
                  : 1.0e-10;
          if (interval.t0 <= endpointParameterTolerance) {
            retainedFeatureRailsByVertex[canonicalVertex0].push_back(interval);
          }
          if (interval.t1 >= 1.0 - endpointParameterTolerance) {
            retainedFeatureRailsByVertex[canonicalVertex1].push_back(interval);
          }
          retainedFeatureRailsByEdge[edgeKey].push_back(
              std::move(interval));
        }
      }
    }
    ++endpointDegree[flow_rep_detail::embedded_endpoint_key(arc, true)];
    ++endpointDegree[flow_rep_detail::embedded_endpoint_key(arc, false)];
  }
  struct OpenEndpoint {
    int arcId = -1;
    bool start = false;
    std::uint64_t key = 0U;
  };
  std::vector<OpenEndpoint> openEndpoints;
  for (const int arcId : result.retainedArcIds) {
    const FlowRepArc &arc = result.arcs[static_cast<std::size_t>(arcId)];
    // Boundary rails are complete boundary cycles and never need extension.
    // An open hard-feature chain is different: preserving the rail without a
    // layout connection leaves every chain edge as a graph bridge and pinches
    // the incident DCEL face. Extend degree-one hard-feature endpoints just
    // like optional layout tips; the authoritative rail itself remains fixed.
    if (arc.boundaryRail || (arc.mandatoryRail && !arc.hardFeatureRail)) {
      continue;
    }
    for (const bool start : {true, false}) {
      const std::uint64_t key =
          flow_rep_detail::embedded_endpoint_key(arc, start);
      const bool embeddedAnchor =
          start ? arc.startEmbeddedAnchor : arc.endEmbeddedAnchor;
      if (!embeddedAnchor && endpointDegree[key] == 1) {
        openEndpoints.push_back({arcId, start, key});
      }
    }
  }
  result.openEndpointsBefore = static_cast<int>(openEndpoints.size());
  if (result.openEndpointsBefore > options.maxEndpointTraces) {
    result.unresolvedEndpoints = result.openEndpointsBefore;
    result.failureKind = FlowRepEndpointCompletionFailureKind::EndpointTraceLimitExceeded;
    result.failure = "EndpointTraceLimitExceeded";
    return close_flow_rep_endpoint_completion(std::move(result));
  }

  const auto face_label = [](const std::vector<int> &labels, const int face,
                             const int fallback) {
    return face >= 0 && face < static_cast<int>(labels.size())
               ? labels[static_cast<std::size_t>(face)]
               : fallback;
  };
  const auto uv = [](const Eigen::RowVector3d &barycentric) {
    return Eigen::Vector2d(barycentric[1], barycentric[2]);
  };
  const auto cross = [](const Eigen::Vector2d &a,
                        const Eigen::Vector2d &b) {
    return a.x() * b.y() - a.y() * b.x();
  };
  struct FeatureRailOwnershipQuery {
    bool owned = false;
    int candidates = 0;
    int compatibleCandidates = 0;
  };
  const auto retained_feature_rail_ownership =
      [&](const FlowRepArc &arc) -> FeatureRailOwnershipQuery {
    FeatureRailOwnershipQuery query;
    if (arc.sourceFace < 0 || arc.sourceFace >= faces.rows()) {
      return query;
    }
    const surface_arrangement_detail::NodeKey node =
        surface_arrangement_detail::make_node_key(
            faces, arc.sourceFace,
            surface_arrangement_detail::bary_to_uv(arc.endBarycentric));
    const auto compatible = [&](const RetainedFeatureRailInterval &interval) {
      return interval.sourceTopologyRegion == arc.sourceTopologyRegion &&
             arc.sourceIsolationSheet.has_value() &&
             interval.incidentSourceSheets.count(*arc.sourceIsolationSheet) != 0U;
    };
    if (node.kind == 0 && node.vertex >= 0) {
      const auto found = retainedFeatureRailsByVertex.find(node.vertex);
      if (found == retainedFeatureRailsByVertex.end()) {
        return query;
      }
      query.candidates = static_cast<int>(found->second.size());
      for (const RetainedFeatureRailInterval &interval : found->second) {
        if (compatible(interval)) {
          ++query.compatibleCandidates;
          query.owned = true;
        }
      }
      return query;
    }
    if (node.kind != 1 || !node.edge.has_value() || node.edgeT < 0) {
      return query;
    }
    const authority::SourceEdgeTopologyKey &edgeKey = *node.edge;
    const double t = static_cast<double>(node.edgeT) / 1.0e10;
    const int edgeVertex0 = static_cast<int>(edgeKey.first().index());
    const int edgeVertex1 = static_cast<int>(edgeKey.second().index());
    const double edgeLength =
        edgeVertex0 >= 0 && edgeVertex0 < vertices.rows() &&
                edgeVertex1 >= 0 && edgeVertex1 < vertices.rows()
            ? (vertices.row(edgeVertex1) - vertices.row(edgeVertex0)).norm()
            : std::numeric_limits<double>::quiet_NaN();
    const double parameterTolerance =
        std::isfinite(edgeLength) && edgeLength > 0.0
            ? std::max(1.0e-10,
                       options.intersectionTolerance / edgeLength)
            : 1.0e-10;
    const auto consider_vertex = [&](const int sourceVertex) {
      const auto foundVertex = retainedFeatureRailsByVertex.find(sourceVertex);
      if (foundVertex == retainedFeatureRailsByVertex.end()) {
        return;
      }
      query.candidates += static_cast<int>(foundVertex->second.size());
      for (const RetainedFeatureRailInterval &interval : foundVertex->second) {
        if (compatible(interval)) {
          ++query.compatibleCandidates;
          query.owned = true;
        }
      }
    };
    const auto found = retainedFeatureRailsByEdge.find(edgeKey);
    if (found != retainedFeatureRailsByEdge.end()) {
      query.candidates += static_cast<int>(found->second.size());
      for (const RetainedFeatureRailInterval &interval : found->second) {
        if (!compatible(interval)) {
          continue;
        }
        ++query.compatibleCandidates;
        if (t >= interval.t0 - parameterTolerance &&
            t <= interval.t1 + parameterTolerance) {
          query.owned = true;
        }
      }
    }
    // A trace can terminate numerically on the final sliver of one feature
    // edge while the authoritative retained rail leaves the same source
    // vertex through another incident edge. Convert the spatial endpoint
    // tolerance to this source edge's parameter domain before transferring
    // ownership. A Feature label alone is still insufficient: an incident
    // retained rail must prove component- and sheet-compatible ownership.
    if (t <= parameterTolerance) {
      consider_vertex(edgeVertex0);
    }
    if (1.0 - t <= parameterTolerance) {
      consider_vertex(edgeVertex1);
    }
    return query;
  };
  struct NetworkIntersection {
    double traceParameter = std::numeric_limits<double>::infinity();
    double targetParameter = -1.0;
    int targetArcId = -1;
    int traceSegment = -1;
    int targetSourceFace = -1;
    Eigen::RowVector3d targetBarycentric =
        Eigen::RowVector3d::Constant(
            std::numeric_limits<double>::quiet_NaN());
    Eigen::RowVector3d targetStartBarycentric =
        Eigen::RowVector3d::Constant(
            std::numeric_limits<double>::quiet_NaN());
    Eigen::RowVector3d targetEndBarycentric =
        Eigen::RowVector3d::Constant(
            std::numeric_limits<double>::quiet_NaN());
  };
  const auto first_network_intersection = [&](
      const SurfaceTraceSegment &segment, const FlowRepArc &target,
      NetworkIntersection &intersection) {
    if (segment.face != target.sourceFace) {
      return false;
    }
    const Eigen::RowVector3d segmentStart =
        surface_cell_tracing_detail::point_position(
            vertices, faces,
            SurfaceTracePoint{segment.face, segment.startBarycentric});
    const Eigen::RowVector3d segmentEnd =
        surface_cell_tracing_detail::point_position(
            vertices, faces,
            SurfaceTracePoint{segment.face, segment.endBarycentric});
    const double segmentLength = (segmentEnd - segmentStart).norm();
    if (!segmentStart.allFinite() || !segmentEnd.allFinite() ||
        !std::isfinite(segmentLength) ||
        segmentLength <= options.intersectionTolerance) {
      return false;
    }
    const auto is_resolvable_parameter = [&](const double parameter) {
      return std::isfinite(parameter) && parameter > 0.0 &&
             parameter <= 1.0 + 1.0e-12 &&
             parameter * segmentLength > options.intersectionTolerance;
    };

    surface_arrangement_detail::Segment2 traceSegment;
    traceSegment.sourceFace = segment.face;
    traceSegment.start = uv(segment.startBarycentric);
    traceSegment.end = uv(segment.endBarycentric);
    surface_arrangement_detail::Segment2 targetSegment;
    targetSegment.sourceFace = target.sourceFace;
    targetSegment.start = uv(target.startBarycentric);
    targetSegment.end = uv(target.endBarycentric);

    double traceParameter = 0.0;
    double targetParameter = 0.0;
    Eigen::Vector2d point = Eigen::Vector2d::Zero();
    if (!surface_arrangement_detail::segment_intersection_params(
            traceSegment, targetSegment, traceParameter, targetParameter,
            point)) {
      return false;
    }

    if (!is_resolvable_parameter(traceParameter)) {
      // Collinear overlap can begin at the trace origin. That point cannot
      // close a degree-one endpoint, so consider the exact target endpoints
      // farther along the trace before discarding the overlap. Use the same
      // strict collinearity tolerance as arrangement construction.
      const Eigen::Vector2d direction = traceSegment.end - traceSegment.start;
      const double directionSquared = direction.squaredNorm();
      if (directionSquared <= 1.0e-24) {
        return false;
      }
      double best = std::numeric_limits<double>::infinity();
      double bestTargetParameter = -1.0;
      Eigen::RowVector3d bestBarycentric =
          Eigen::RowVector3d::Constant(
              std::numeric_limits<double>::quiet_NaN());
      for (const auto &[targetPoint, targetBarycentric,
                        candidateTargetParameter] :
           {std::tuple<Eigen::Vector2d, Eigen::RowVector3d, double>{
                targetSegment.start, target.startBarycentric, 0.0},
            {targetSegment.end, target.endBarycentric, 1.0}}) {
        if (std::abs(surface_arrangement_detail::cross2(
                targetPoint - traceSegment.start, direction)) > 1.0e-12) {
          continue;
        }
        const double candidate =
            (targetPoint - traceSegment.start).dot(direction) /
            directionSquared;
        if (is_resolvable_parameter(candidate) && candidate < best) {
          best = candidate;
          bestTargetParameter = candidateTargetParameter;
          bestBarycentric = targetBarycentric;
        }
      }
      if (!std::isfinite(best)) {
        return false;
      }
      intersection.traceParameter = std::clamp(best, 0.0, 1.0);
      intersection.targetParameter = bestTargetParameter;
      intersection.targetArcId = target.id;
      intersection.targetSourceFace = target.sourceFace;
      intersection.targetBarycentric = bestBarycentric;
      intersection.targetStartBarycentric = target.startBarycentric;
      intersection.targetEndBarycentric = target.endBarycentric;
      return true;
    }

    intersection.traceParameter =
        std::clamp(traceParameter, 0.0, 1.0);
    intersection.targetParameter =
        std::clamp(targetParameter, 0.0, 1.0);
    intersection.targetArcId = target.id;
    intersection.targetSourceFace = target.sourceFace;
    // Snap the connector endpoint to the intersection point represented in
    // the target chart. This makes the ownership proof consumed here exactly
    // reproducible by the arrangement splitter instead of relying on two
    // independently rounded trace/target evaluations.
    intersection.targetBarycentric =
        surface_arrangement_detail::canonicalize_barycentric(
            surface_arrangement_detail::uv_to_bary(point));
    intersection.targetStartBarycentric = target.startBarycentric;
    intersection.targetEndBarycentric = target.endBarycentric;
    return intersection.targetBarycentric.allFinite();
  };

  int nextSupportTraceId = 0;
  for (const FlowRepArc &arc : result.arcs) {
    nextSupportTraceId = std::max(nextSupportTraceId, arc.supportTraceId + 1);
  }
  const auto endpoint_location = [&](const FlowRepArc *arc, int &sourceFace,
                                     int &sourceVertex, int &sourceEdge0,
                                     int &sourceEdge1, double &sourceEdgeT,
                                     Eigen::RowVector3d &barycentric) {
    if (arc == nullptr || arc->sourceFace < 0 ||
        arc->sourceFace >= faces.rows()) {
      return;
    }
    sourceFace = arc->sourceFace;
    barycentric = arc->endBarycentric;
    const surface_arrangement_detail::NodeKey node =
        surface_arrangement_detail::make_node_key(
            faces, arc->sourceFace,
            surface_arrangement_detail::bary_to_uv(arc->endBarycentric));
    if (node.kind == 0) {
      sourceVertex = node.vertex;
    } else if (node.kind == 1 && node.edge.has_value() && node.edgeT >= 0) {
      sourceEdge0 = static_cast<int>(node.edge->first().index());
      sourceEdge1 = static_cast<int>(node.edge->second().index());
      sourceEdgeT = static_cast<double>(node.edgeT) / 1.0e10;
    }
  };
  const auto record_diagnostic = [&](
      const OpenEndpoint &endpoint, const FlowRepArc &source,
      const int family, const int sign, const SurfaceTraceResult *trace,
      const FlowRepArc *terminalArc,
      const FlowRepArc *lastRepresentableArc,
      const FeatureRailOwnershipQuery &featureRailOwnership,
      const int generatedSupportTraceId,
      const NetworkIntersection *networkIntersection,
      const int skippedDegenerateSegments,
      const FlowRepEndpointResolution resolution) {
    FlowRepEndpointCompletionDiagnostic diagnostic;
    diagnostic.sourceArcId = endpoint.arcId;
    diagnostic.startEndpoint = endpoint.start;
    diagnostic.requiredSingularitySupport = source.singularitySupport;
    diagnostic.hardFeatureRail = source.hardFeatureRail;
    diagnostic.family = family;
    diagnostic.sign = sign;
    diagnostic.skippedDegenerateSegments = skippedDegenerateSegments;
    diagnostic.resolution = resolution;
    if (trace != nullptr) {
      diagnostic.termination = trace->termination;
      diagnostic.tracedSegments = static_cast<int>(trace->segments.size());
      const int termination = static_cast<int>(trace->termination);
      if (termination >= 0 &&
          termination < static_cast<int>(result.traceTerminationCounts.size())) {
        ++result.traceTerminationCounts[static_cast<std::size_t>(termination)];
      }
    }
    endpoint_location(terminalArc, diagnostic.terminalSourceFace,
                      diagnostic.terminalSourceVertex,
                      diagnostic.terminalSourceEdge0,
                      diagnostic.terminalSourceEdge1,
                      diagnostic.terminalSourceEdgeT,
                      diagnostic.terminalBarycentric);
    endpoint_location(lastRepresentableArc,
                      diagnostic.lastRepresentableSourceFace,
                      diagnostic.lastRepresentableSourceVertex,
                      diagnostic.lastRepresentableSourceEdge0,
                      diagnostic.lastRepresentableSourceEdge1,
                      diagnostic.lastRepresentableSourceEdgeT,
                      diagnostic.lastRepresentableBarycentric);
    if (terminalArc != nullptr && lastRepresentableArc != nullptr &&
        terminalArc->end.allFinite() &&
        lastRepresentableArc->end.allFinite()) {
      diagnostic.terminalDistanceToLastRepresentable =
          (terminalArc->end - lastRepresentableArc->end).norm();
    }
    diagnostic.terminalFeatureRailCandidates = featureRailOwnership.candidates;
    diagnostic.terminalCompatibleFeatureRailCandidates =
        featureRailOwnership.compatibleCandidates;
    diagnostic.generatedSupportTraceId = generatedSupportTraceId;
    if (networkIntersection != nullptr) {
      diagnostic.captureTargetArcId = networkIntersection->targetArcId;
      diagnostic.captureTraceSegment = networkIntersection->traceSegment;
      diagnostic.captureTraceParameter =
          networkIntersection->traceParameter;
      diagnostic.captureTargetParameter =
          networkIntersection->targetParameter;
      diagnostic.captureTargetSourceFace =
          networkIntersection->targetSourceFace;
      diagnostic.captureBarycentric =
          networkIntersection->targetBarycentric;
      diagnostic.captureTargetStartBarycentric =
          networkIntersection->targetStartBarycentric;
      diagnostic.captureTargetEndBarycentric =
          networkIntersection->targetEndBarycentric;
    }
    result.diagnostics.push_back(std::move(diagnostic));
  };
  for (const OpenEndpoint &endpoint : openEndpoints) {
    const int sourceArcId = endpoint.arcId;
    FlowRepArc &source =
        result.arcs[static_cast<std::size_t>(sourceArcId)];
    if (endpointDegree[endpoint.key] != 1) {
      ++result.resolvedEndpoints;
      record_diagnostic(endpoint, source, source.family, 0, nullptr,
                        nullptr, nullptr, {}, -1, nullptr, 0,
                        FlowRepEndpointResolution::AlreadyResolved);
      continue;
    }
    if (source.sourceFace < 0 || source.sourceFace >= faces.rows()) {
      ++result.unresolvedEndpoints;
      result.unresolvedRequiredEndpoints += source.singularitySupport ? 1 : 0;
      record_diagnostic(endpoint, source, source.family, 0, nullptr,
                        nullptr, nullptr, {}, -1, nullptr, 0,
                        FlowRepEndpointResolution::InvalidSourceFace);
      continue;
    }
    const SurfaceTracePoint startPoint{
        source.sourceFace,
        endpoint.start ? source.startBarycentric : source.endBarycentric};
    const Eigen::RowVector3d outward =
        endpoint.start ? source.start - source.end : source.end - source.start;
    int family = ((source.family % 2) + 2) % 2;
    if (source.family < 0) {
      const Eigen::RowVector3d tangent = source.end - source.start;
      if (!tangent.allFinite() || tangent.squaredNorm() <= 1.0e-24) {
        ++result.unresolvedEndpoints;
        result.unresolvedRequiredEndpoints +=
            source.singularitySupport ? 1 : 0;
        record_diagnostic(endpoint, source, family, 0, nullptr,
                          nullptr, nullptr, {}, -1, nullptr, 0,
                          FlowRepEndpointResolution::DegenerateSource);
        continue;
      }
      const Eigen::RowVector3d unitTangent = tangent.normalized();
      const double primaryAlignment = std::abs(unitTangent.dot(
          crossField.primaryDirections.row(source.sourceFace)));
      const double secondaryAlignment = std::abs(unitTangent.dot(
          crossField.secondaryDirections.row(source.sourceFace)));
      // Stable ties choose the primary family. Feature-constrained fields are
      // expected to make one of these axes tangent to the rail.
      family = secondaryAlignment > primaryAlignment ? 1 : 0;
    }
    const Eigen::RowVector3d axis =
        family == 0 ? crossField.primaryDirections.row(source.sourceFace)
                    : crossField.secondaryDirections.row(source.sourceFace);
    const int sign = outward.dot(axis) >= 0.0 ? 1 : -1;
    SurfaceTraceSeed seed;
    seed.point = startPoint;
    const SurfaceTraceResult trace = trace_surface_field(
        vertices, faces, crossField, seed, family, sign, tracingOptions);
    if (trace.segments.empty()) {
      ++result.unresolvedEndpoints;
      result.unresolvedRequiredEndpoints += source.singularitySupport ? 1 : 0;
      record_diagnostic(endpoint, source, family, sign, &trace,
                        nullptr, nullptr, {}, -1, nullptr, 0,
                        FlowRepEndpointResolution::EmptyTrace);
      continue;
    }

    const int supportTraceId = nextSupportTraceId++;
    std::vector<FlowRepArc> appended;
    bool reachedNetwork = false;
    bool reachedIntrinsicNode = false;
    bool reconciledSourceEndpoint = false;
    FeatureRailOwnershipQuery terminalFeatureRailOwnership;
    int skippedDegenerateSegments = 0;
    FlowRepArc terminalTraceArc;
    bool hasTerminalTraceArc = false;
    FlowRepArc lastRepresentableTraceArc;
    bool hasLastRepresentableTraceArc = false;
    NetworkIntersection committedNetworkIntersection;
    bool hasCommittedNetworkIntersection = false;
    for (int segmentIndex = 0;
         segmentIndex < static_cast<int>(trace.segments.size());
         ++segmentIndex) {
      SurfaceTraceSegment segment =
          trace.segments[static_cast<std::size_t>(segmentIndex)];
      NetworkIntersection earliestIntersection;
      if (segment.face >= 0 && segment.face < faces.rows()) {
        for (const int targetId :
             activeArcsByFace[static_cast<std::size_t>(segment.face)]) {
          if (targetId == endpoint.arcId) {
            continue;
          }
          const FlowRepArc &target =
              result.arcs[static_cast<std::size_t>(targetId)];
          const auto segmentScope =
              tracing_source_scope(tracingOptions, segment.face);
          const std::optional<authority::TopologyRegionId> segmentRegion =
              segmentScope.has_value()
                  ? std::optional<authority::TopologyRegionId>(segmentScope->first)
                  : source.sourceTopologyRegion;
          const std::optional<authority::IsolationSheetId> segmentSheet =
              segmentScope.has_value()
                  ? std::optional<authority::IsolationSheetId>(segmentScope->second)
                  : source.sourceIsolationSheet;
          if (target.sourceTopologyRegion != segmentRegion ||
              target.sourceIsolationSheet != segmentSheet) {
            continue;
          }
          NetworkIntersection candidate;
          if (first_network_intersection(segment, target, candidate)) {
            candidate.traceSegment = segmentIndex;
          }
          if (std::isfinite(candidate.traceParameter) &&
              candidate.traceParameter <
                  earliestIntersection.traceParameter) {
            earliestIntersection = candidate;
          }
        }
      }
      if (std::isfinite(earliestIntersection.traceParameter)) {
        segment.endBarycentric = earliestIntersection.targetBarycentric;
        reachedNetwork = true;
        committedNetworkIntersection = earliestIntersection;
        hasCommittedNetworkIntersection = true;
      }
      FlowRepArc arc;
      arc.id = static_cast<int>(result.arcs.size() + appended.size());
      arc.start = surface_cell_tracing_detail::point_position(
          vertices, faces,
          SurfaceTracePoint{segment.face, segment.startBarycentric});
      arc.end = surface_cell_tracing_detail::point_position(
          vertices, faces,
          SurfaceTracePoint{segment.face, segment.endBarycentric});
      if (!arc.start.allFinite() || !arc.end.allFinite()) {
        break;
      }
      arc.sourceFace = segment.face;
      arc.startBarycentric = segment.startBarycentric;
      arc.endBarycentric = segment.endBarycentric;
      const auto segmentScope =
          tracing_source_scope(tracingOptions, segment.face);
      arc.sourceTopologyRegion =
          segmentScope.has_value()
              ? std::optional<authority::TopologyRegionId>(segmentScope->first)
              : source.sourceTopologyRegion;
      arc.sourceIsolationSheet =
          segmentScope.has_value()
              ? std::optional<authority::IsolationSheetId>(segmentScope->second)
              : source.sourceIsolationSheet;
      arc.family = segment.family;
      arc.strandProvenance = -2 - supportTraceId;
      arc.featureProvenance = segment.exitEdge;
      arc.proposalId = -1;
      arc.proposalSeedId = -1;
      arc.proposalSide = -1;
      arc.proposalBoundarySegment = -1;
      arc.layoutSupport = true;
      arc.supportTraceId = supportTraceId;
      arc.supportSeedId =
          source.supportSeedId >= 0 ? source.supportSeedId : source.id;
      arc.supportSegment = segmentIndex;
      arc.sameStrandHint = supportTraceId;
      flow_rep_detail::assign_intrinsic_endpoint_keys(arc, faces);
      const std::uint64_t terminalKey =
          flow_rep_detail::embedded_endpoint_key(arc, false);
      terminalTraceArc = arc;
      hasTerminalTraceArc = true;
      if (!reachedNetwork && terminalKey != endpoint.key &&
          endpointDegree[terminalKey] > 0) {
        reachedNetwork = true;
        reachedIntrinsicNode = true;
      }
      if (!reachedNetwork &&
          trace.termination == TraceTerminationReason::Feature &&
          segmentIndex + 1 == static_cast<int>(trace.segments.size())) {
        terminalFeatureRailOwnership =
            retained_feature_rail_ownership(arc);
      }
      if (!reachedNetwork && terminalFeatureRailOwnership.owned) {
        // A hard-feature rail can be represented in the chart on the other
        // side of its source edge, and a branch can reach a rail endpoint
        // through another incident face at the same source vertex. Same-face
        // segment intersection cannot see either ownership case. Accept only
        // a canonical source-edge interval or rail endpoint owned by a
        // retained rail on the same component and incident sheet; the
        // termination label alone remains insufficient.
        reachedNetwork = true;
        reachedIntrinsicNode = true;
      }
      if ((arc.end - arc.start).norm() <= options.intersectionTolerance) {
        ++skippedDegenerateSegments;
        if (reachedNetwork) {
          // A retained-network capture can occur within the spatial tolerance
          // of the original degree-one endpoint. Emitting that final sliver is
          // numerically meaningless, but dropping it leaves the required
          // branch open. Because the old endpoint has degree one, reconcile it
          // transactionally to the proven capture point and mark it embedded.
          // This is a topology-preserving snap, not synthetic completion: the
          // target was already verified on the same source component/sheet.
          if (appended.empty()) {
            auto foundDegree = endpointDegree.find(endpoint.key);
            if (foundDegree != endpointDegree.end() && foundDegree->second > 0) {
              --foundDegree->second;
            }
            if (endpoint.start) {
              source.start = arc.end;
              source.startBarycentric = arc.endBarycentric;
              source.startEmbeddedAnchor = true;
            } else {
              source.end = arc.end;
              source.endBarycentric = arc.endBarycentric;
              source.endEmbeddedAnchor = true;
            }
            flow_rep_detail::assign_intrinsic_endpoint_keys(source, faces);
            ++endpointDegree[flow_rep_detail::embedded_endpoint_key(
                source, endpoint.start)];
            reconciledSourceEndpoint = true;
          }
          break;
        }
        continue;
      }
      lastRepresentableTraceArc = arc;
      hasLastRepresentableTraceArc = true;
      appended.push_back(std::move(arc));
      if (reachedNetwork) {
        break;
      }
    }

    if (reconciledSourceEndpoint) {
      ++result.resolvedEndpoints;
      record_diagnostic(
          endpoint, source, family, sign, &trace,
          hasTerminalTraceArc ? &terminalTraceArc : nullptr,
          hasLastRepresentableTraceArc ? &lastRepresentableTraceArc : nullptr,
          terminalFeatureRailOwnership, supportTraceId,
          hasCommittedNetworkIntersection ? &committedNetworkIntersection
                                          : nullptr,
          skippedDegenerateSegments,
          reachedIntrinsicNode ? FlowRepEndpointResolution::IntrinsicNode
                               : FlowRepEndpointResolution::SegmentIntersection);
      continue;
    }

    // A termination label alone is not proof that the embedded network owns
    // the terminal point. In particular, an unrepresented feature barrier or
    // singularity would leave the new path as another bridge. Commit only a
    // connector whose endpoint intersects an already retained embedded arc;
    // arrangement construction will split that target arc conformingly.
    if (appended.empty() || !reachedNetwork ||
        result.addedArcs + static_cast<int>(appended.size()) >
            options.maxAddedArcs) {
      ++result.unresolvedEndpoints;
      result.unresolvedRequiredEndpoints += source.singularitySupport ? 1 : 0;
      const FlowRepEndpointResolution resolution =
          result.addedArcs + static_cast<int>(appended.size()) >
                  options.maxAddedArcs
              ? FlowRepEndpointResolution::AddedArcLimit
              : FlowRepEndpointResolution::NoNetworkCapture;
      record_diagnostic(endpoint, source, family, sign, &trace,
                        hasTerminalTraceArc ? &terminalTraceArc : nullptr,
                        hasLastRepresentableTraceArc
                            ? &lastRepresentableTraceArc
                            : nullptr,
                        terminalFeatureRailOwnership, supportTraceId,
                        hasCommittedNetworkIntersection
                            ? &committedNetworkIntersection
                            : nullptr,
                        skippedDegenerateSegments, resolution);
      continue;
    }
    appended.back().endEmbeddedAnchor = true;
    for (FlowRepArc &arc : appended) {
      arc.singularitySupport = source.singularitySupport;
    }
    for (FlowRepArc &arc : appended) {
      if (!flow_rep_detail::arc_has_complete_provenance(arc)) {
        result.failureKind = FlowRepEndpointCompletionFailureKind::GeneratedEndpointArcMissingProvenance;
        result.failure = "GeneratedEndpointArcMissingProvenance";
        return close_flow_rep_endpoint_completion(std::move(result));
      }
      const int arcId = arc.id;
      result.arcs.push_back(std::move(arc));
      result.retainedArcIds.push_back(arcId);
      activeArcsByFace[static_cast<std::size_t>(
          result.arcs[static_cast<std::size_t>(arcId)].sourceFace)]
          .push_back(arcId);
      ++endpointDegree[flow_rep_detail::embedded_endpoint_key(
          result.arcs[static_cast<std::size_t>(arcId)], true)];
      ++endpointDegree[flow_rep_detail::embedded_endpoint_key(
          result.arcs[static_cast<std::size_t>(arcId)], false)];
      ++result.addedArcs;
    }
    ++result.resolvedEndpoints;
    // Generated connector insertion can reallocate result.arcs. Reacquire
    // the source by stable arc identity before recording committed evidence.
    const FlowRepArc &committedSource =
        result.arcs[static_cast<std::size_t>(sourceArcId)];
    record_diagnostic(
        endpoint, committedSource, family, sign, &trace,
        hasTerminalTraceArc ? &terminalTraceArc : nullptr,
        hasLastRepresentableTraceArc ? &lastRepresentableTraceArc : nullptr,
        terminalFeatureRailOwnership, supportTraceId,
        hasCommittedNetworkIntersection ? &committedNetworkIntersection
                                        : nullptr,
        skippedDegenerateSegments,
        reachedIntrinsicNode ? FlowRepEndpointResolution::IntrinsicNode
                             : FlowRepEndpointResolution::SegmentIntersection);
  }

  std::stable_sort(result.retainedArcIds.begin(), result.retainedArcIds.end());
  result.endpointTags = flow_rep_detail::classify_endpoints(
      result.arcs, result.retainedArcIds);
  if (result.unresolvedEndpoints != 0 && options.requireAllEndpointsResolved) {
    result.failureKind = FlowRepEndpointCompletionFailureKind::UnresolvedRequiredEndpoints;
    result.failure = "UnresolvedFlowlineEndpoints";
    return close_flow_rep_endpoint_completion(std::move(result));
  }
  result.success = true;
  return close_flow_rep_endpoint_completion(std::move(result));
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
