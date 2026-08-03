#include <directional/pipeline/RemeshPipeline.h>
#include <directional/geometry/GeneralGraphMatching.h>

namespace directional::pipeline {

std::string remesh_backend_name(const RemeshBackend backend) {
  switch (backend) {
  case RemeshBackend::LegacyInteger:
    return "LegacyInteger";
  case RemeshBackend::SurfaceCells:
    return "SurfaceCells";
  }
  return "Unknown";
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::string
surface_cell_fallback_policy_name(const SurfaceCellFallbackPolicy policy) {
  switch (policy) {
  case SurfaceCellFallbackPolicy::Fail:
    return "Fail";
  case SurfaceCellFallbackPolicy::ReturnInputMesh:
    return "ReturnInputMesh";
  }
  return "Unknown";
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::string
surface_cell_failure_code_name(const SurfaceCellFailureCode code) {
  switch (code) {
  case SurfaceCellFailureCode::None:
    return "None";
  case SurfaceCellFailureCode::InvalidFieldDimensions:
    return "InvalidFieldDimensions";
  case SurfaceCellFailureCode::MissingMatching:
    return "MissingMatching";
  case SurfaceCellFailureCode::MissingSingularities:
    return "MissingSingularities";
  case SurfaceCellFailureCode::MissingConfidence:
    return "MissingConfidence";
  case SurfaceCellFailureCode::UncoveredFaces:
    return "UncoveredFaces";
  case SurfaceCellFailureCode::UnsupportedInput:
    return "UnsupportedInput";
  case SurfaceCellFailureCode::InvalidClassifierOptions:
    return "InvalidClassifierOptions";
  case SurfaceCellFailureCode::InvalidRailTopology:
    return "InvalidRailTopology";
  case SurfaceCellFailureCode::EmptyFlowRepNetwork:
    return "EmptyFlowRepNetwork";
  case SurfaceCellFailureCode::MissingFlowRepCoverageEvidence:
    return "MissingFlowRepCoverageEvidence";
  case SurfaceCellFailureCode::MissingFlowRepCycleEvidence:
    return "MissingFlowRepCycleEvidence";
  case SurfaceCellFailureCode::InvalidFlowRepCoverageEvidence:
    return "InvalidFlowRepCoverageEvidence";
  case SurfaceCellFailureCode::InvalidFlowRepCycleEvidence:
    return "InvalidFlowRepCycleEvidence";
  case SurfaceCellFailureCode::InvalidFlowRepArcIdentity:
    return "InvalidFlowRepArcIdentity";
  case SurfaceCellFailureCode::IncompleteFlowRepProvenance:
    return "IncompleteFlowRepProvenance";
  case SurfaceCellFailureCode::IncompleteFlowRepCycleCoverage:
    return "IncompleteFlowRepCycleCoverage";
  case SurfaceCellFailureCode::FlowRepMandatoryRailLoss:
    return "FlowRepMandatoryRailLoss";
  case SurfaceCellFailureCode::InjectedStageFailure:
    return "InjectedStageFailure";
  case SurfaceCellFailureCode::NotProductionReady:
    return "NotProductionReady";
  }
  return "Unknown";
}

} // namespace directional::pipeline

namespace directional::pipeline {

SurfaceCellFailureCode surface_cell_failure_from_flow_rep(
    const geometry::FlowRepSelectionFailureCode code) {
  switch (code) {
  case geometry::FlowRepSelectionFailureCode::None:
    return SurfaceCellFailureCode::None;
  case geometry::FlowRepSelectionFailureCode::EmptyNetwork:
    return SurfaceCellFailureCode::EmptyFlowRepNetwork;
  case geometry::FlowRepSelectionFailureCode::MissingCoverageEvidence:
    return SurfaceCellFailureCode::MissingFlowRepCoverageEvidence;
  case geometry::FlowRepSelectionFailureCode::MissingCycleEvidence:
    return SurfaceCellFailureCode::MissingFlowRepCycleEvidence;
  case geometry::FlowRepSelectionFailureCode::InvalidCoverageEvidence:
    return SurfaceCellFailureCode::InvalidFlowRepCoverageEvidence;
  case geometry::FlowRepSelectionFailureCode::InvalidCycleEvidence:
    return SurfaceCellFailureCode::InvalidFlowRepCycleEvidence;
  case geometry::FlowRepSelectionFailureCode::InvalidArcIdentity:
    return SurfaceCellFailureCode::InvalidFlowRepArcIdentity;
  case geometry::FlowRepSelectionFailureCode::IncompleteArcProvenance:
    return SurfaceCellFailureCode::IncompleteFlowRepProvenance;
  case geometry::FlowRepSelectionFailureCode::IncompleteCycleCoverage:
    return SurfaceCellFailureCode::IncompleteFlowRepCycleCoverage;
  case geometry::FlowRepSelectionFailureCode::MandatoryRailLoss:
    return SurfaceCellFailureCode::FlowRepMandatoryRailLoss;
  }
  return SurfaceCellFailureCode::InvalidFlowRepCycleEvidence;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::string normalize_option_token(std::string value) {
  value.erase(std::remove_if(value.begin(), value.end(),
                             [](const char character) {
                               return character == '-' || character == '_';
                             }),
              value.end());
  std::transform(value.begin(), value.end(), value.begin(),
                 [](const unsigned char character) {
                   return static_cast<char>(std::tolower(character));
                 });
  return value;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshBackend parse_remesh_backend(const std::string &value) {
  const std::string token = normalize_option_token(value);
  if (token == "legacy" || token == "legacyinteger") {
    return RemeshBackend::LegacyInteger;
  }
  if (token == "surfacecells" || token == "surfacecell") {
    return RemeshBackend::SurfaceCells;
  }
  throw std::runtime_error(
      "Backend must be LegacyInteger or SurfaceCells.");
}

} // namespace directional::pipeline

namespace directional::pipeline {

SurfaceCellFallbackPolicy
parse_surface_cell_fallback_policy(const std::string &value) {
  const std::string token = normalize_option_token(value);
  if (token == "fail") {
    return SurfaceCellFallbackPolicy::Fail;
  }
  if (token == "returninputmesh" || token == "inputmesh" ||
      token == "returnquaddominant" || token == "quaddominant") {
    return SurfaceCellFallbackPolicy::ReturnInputMesh;
  }
  if (token == "trylegacy") {
    throw std::runtime_error(
        "TryLegacy is disabled for SurfaceCells; failures must terminate "
        "without entering legacy integer integration.");
  }
  throw std::runtime_error(
      "Surface-cell fallback must be Fail or ReturnInputMesh.");
}

} // namespace directional::pipeline

namespace directional::pipeline {

double remesh_elapsed_seconds(
    const RemeshPipelineClock::time_point start) {
  return std::chrono::duration<double>(RemeshPipelineClock::now() - start)
      .count();
}

} // namespace directional::pipeline

namespace directional::pipeline {

void set_overall_pipeline_time(
    RemeshResult &result, const RemeshPipelineClock::time_point start) {
  result.diagnostics.overallPipelineSeconds = remesh_elapsed_seconds(start);
  result.diagnostics.overallPipelineTimeAvailable = true;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void copy_adaptive_feature_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::BoundedMeshPreconditionerResult &preconditioned) {
  diagnostics.adaptiveFeatureMapSeconds =
      preconditioned.adaptiveFeatureMapSeconds;
  diagnostics.adaptiveFeatureHardEdgeCount =
      preconditioned.adaptiveFeatureHardEdgeCount;
  diagnostics.adaptiveFeatureSoftEdgeCount =
      preconditioned.adaptiveFeatureSoftEdgeCount;
  diagnostics.adaptiveFeatureBoundaryEdgeCount =
      preconditioned.adaptiveFeatureBoundaryEdgeCount;
  diagnostics.adaptiveFeatureNonManifoldEdgeCount =
      preconditioned.adaptiveFeatureNonManifoldEdgeCount;
  diagnostics.adaptiveFeatureCurveCount =
      preconditioned.adaptiveFeatureCurveCount;
  diagnostics.adaptiveFeatureClosedCurveCount =
      preconditioned.adaptiveFeatureClosedCurveCount;
  diagnostics.adaptiveFeatureMaxDensity =
      preconditioned.adaptiveFeatureMaxDensity;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void copy_adaptive_feature_map_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::AdaptiveFeatureMap &featureMap) {
  diagnostics.adaptiveFeatureHardEdgeCount = 0;
  diagnostics.adaptiveFeatureSoftEdgeCount = 0;
  diagnostics.adaptiveFeatureBoundaryEdgeCount = 0;
  diagnostics.adaptiveFeatureNonManifoldEdgeCount = 0;
  for (const geometry::AdaptiveFeatureEdge &edge : featureMap.edges) {
    switch (edge.edgeClass) {
    case geometry::AdaptiveFeatureClass::Hard:
      ++diagnostics.adaptiveFeatureHardEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::Soft:
      ++diagnostics.adaptiveFeatureSoftEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::Boundary:
      ++diagnostics.adaptiveFeatureBoundaryEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::NonManifold:
      ++diagnostics.adaptiveFeatureNonManifoldEdgeCount;
      break;
    case geometry::AdaptiveFeatureClass::Smooth:
      break;
    }
  }
  diagnostics.adaptiveFeatureCurveCount = featureMap.curves.size();
  diagnostics.adaptiveFeatureClosedCurveCount = 0;
  for (const geometry::AdaptiveFeatureCurve &curve : featureMap.curves) {
    if (curve.closed) {
      ++diagnostics.adaptiveFeatureClosedCurveCount;
    }
  }
  diagnostics.adaptiveFeatureMaxDensity =
      featureMap.vertexDensity.size() == 0 ? 0.0
                                           : featureMap.vertexDensity.maxCoeff();
}

} // namespace directional::pipeline

namespace directional::pipeline {

void copy_adaptive_target_size_diagnostics(
    directional::RemeshDiagnostics &diagnostics,
    const geometry::AdaptiveTargetSizeResult &targetSize) {
  diagnostics.adaptiveTargetSizeResolvedSurfaceError =
      targetSize.resolvedSurfaceError;
  diagnostics.adaptiveTargetSizeFiniteVertexCount = 0;
  diagnostics.adaptiveTargetSizeNonFiniteVertexCount = 0;
  diagnostics.adaptiveTargetSizeMin = 0.0;
  diagnostics.adaptiveTargetSizeMax = 0.0;
  bool initialized = false;
  for (int vertex = 0; vertex < targetSize.targetSize.size(); ++vertex) {
    const double value = targetSize.targetSize[vertex];
    if (std::isfinite(value)) {
      ++diagnostics.adaptiveTargetSizeFiniteVertexCount;
      if (!initialized) {
        diagnostics.adaptiveTargetSizeMin = value;
        diagnostics.adaptiveTargetSizeMax = value;
        initialized = true;
      } else {
        diagnostics.adaptiveTargetSizeMin =
            std::min(diagnostics.adaptiveTargetSizeMin, value);
        diagnostics.adaptiveTargetSizeMax =
            std::max(diagnostics.adaptiveTargetSizeMax, value);
      }
    } else {
      ++diagnostics.adaptiveTargetSizeNonFiniteVertexCount;
    }
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

Eigen::RowVector3d project_tangent(const Eigen::RowVector3d &vector,
                                          const Eigen::RowVector3d &normal,
                                          const bool normalize) {
  return fields::project_tangent(vector, normal, normalize);
}

} // namespace directional::pipeline

namespace directional::pipeline {

Eigen::MatrixXd
make_raw_cross_field(const TriMesh &mesh,
                     const Eigen::MatrixXd &primaryDirections,
                     const Eigen::MatrixXd &secondaryDirections,
                     const bool normalizeDirections) {
  return fields::make_raw_cross_field(mesh, primaryDirections,
                                      secondaryDirections,
                                      normalizeDirections);
}

} // namespace directional::pipeline

namespace directional::pipeline {

Eigen::MatrixXd
orthogonal_complement(const TriMesh &mesh,
                      const Eigen::MatrixXd &primaryDirections,
                      const bool normalizeDirections) {
  return fields::orthogonal_complement(mesh, primaryDirections,
                                       normalizeDirections);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_combine_u64(std::uint64_t &seed, const std::uint64_t value) {
  seed ^= value + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_combine_i64(std::uint64_t &seed, const std::int64_t value) {
  hash_combine_u64(seed, static_cast<std::uint64_t>(value));
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_combine_double(std::uint64_t &seed, const double value) {
  const double sanitized = std::isfinite(value) ? value : 0.0;
  hash_combine_i64(seed, static_cast<std::int64_t>(std::llround(sanitized * 1.0e9)));
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_combine_string(std::uint64_t &seed, const std::string &value) {
  for (const char ch : value) {
    hash_combine_u64(seed, static_cast<unsigned char>(ch));
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t structural_hash_seed(const std::string &type) {
  std::uint64_t seed = 1469598103934665603ULL;
  hash_combine_string(seed, type);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_matrix(std::uint64_t &seed, const Eigen::MatrixXd &matrix) {
  hash_combine_i64(seed, matrix.rows());
  hash_combine_i64(seed, matrix.cols());
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      hash_combine_double(seed, matrix(row, col));
    }
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_matrix(std::uint64_t &seed, const Eigen::MatrixXi &matrix) {
  hash_combine_i64(seed, matrix.rows());
  hash_combine_i64(seed, matrix.cols());
  for (Eigen::Index row = 0; row < matrix.rows(); ++row) {
    for (Eigen::Index col = 0; col < matrix.cols(); ++col) {
      hash_combine_i64(seed, matrix(row, col));
    }
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_vector(std::uint64_t &seed, const Eigen::VectorXd &values) {
  hash_combine_i64(seed, values.size());
  for (Eigen::Index index = 0; index < values.size(); ++index) {
    hash_combine_double(seed, values(index));
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_vector(std::uint64_t &seed, const std::vector<int> &values) {
  hash_combine_u64(seed, values.size());
  for (const int value : values) {
    hash_combine_i64(seed, value);
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_row_vector(std::uint64_t &seed, const Eigen::RowVector3d &v) {
  hash_combine_double(seed, v.x());
  hash_combine_double(seed, v.y());
  hash_combine_double(seed, v.z());
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_surface_point(std::uint64_t &seed,
                               const geometry::SurfacePoint &point) {
  hash_combine_i64(seed, point.face);
  hash_combine_i64(seed, point.component);
  hash_combine_i64(seed, point.sheet);
  hash_combine_double(seed, point.barycentric.x());
  hash_combine_double(seed, point.barycentric.y());
  hash_combine_double(seed, point.barycentric.z());
  hash_combine_double(seed, point.position.x());
  hash_combine_double(seed, point.position.y());
  hash_combine_double(seed, point.position.z());
  hash_combine_double(seed, point.squaredDistance);
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_feature_map(
    const geometry::AdaptiveFeatureMap &map) {
  std::uint64_t seed = structural_hash_seed("feature");
  for (const auto &entry : map.edgeIndex) {
    hash_combine_i64(seed, entry.first.first);
    hash_combine_i64(seed, entry.first.second);
    hash_combine_i64(seed, entry.second);
  }
  for (const geometry::AdaptiveFeatureEdge &edge : map.edges) {
    hash_combine_i64(seed, edge.vertices.first);
    hash_combine_i64(seed, edge.vertices.second);
    hash_vector(seed, edge.incidentFaces);
    hash_combine_i64(seed, edge.component);
    hash_combine_i64(seed, edge.curve);
    hash_combine_double(seed, edge.angleRadians);
    hash_combine_double(seed, edge.strength);
    hash_combine_double(seed, edge.ridgeValleyConfidence);
    hash_combine_double(seed, edge.length);
    hash_combine_i64(seed, static_cast<int>(edge.edgeClass));
    hash_combine_i64(seed, edge.userTagged ? 1 : 0);
  }
  for (const geometry::AdaptiveFeatureCurve &curve : map.curves) {
    hash_combine_i64(seed, curve.id);
    hash_combine_i64(seed, curve.component);
    hash_vector(seed, curve.edges);
    hash_vector(seed, curve.vertices);
    hash_combine_i64(seed, curve.closed ? 1 : 0);
    hash_vector(seed, curve.corners);
    hash_vector(seed, curve.junctions);
  }
  for (const geometry::AdaptiveFeatureComponentStats &stats : map.componentStats) {
    hash_combine_u64(seed, stats.manifoldInteriorEdgeCount);
    hash_combine_double(seed, stats.p50Degrees);
    hash_combine_double(seed, stats.p75Degrees);
    hash_combine_double(seed, stats.p90Degrees);
    hash_combine_double(seed, stats.p95Degrees);
    hash_combine_double(seed, stats.p98Degrees);
    hash_combine_double(seed, stats.maxDegrees);
    hash_combine_i64(seed, stats.cadLike ? 1 : 0);
  }
  hash_vector(seed, map.vertexDensity);
  hash_combine_i64(seed, map.hasNonManifold ? 1 : 0);
  hash_combine_u64(seed, map.tangentRejectedEdges);
  hash_combine_u64(seed, map.indexedLookupCount);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_trace_segment(std::uint64_t &seed,
                               const geometry::SurfaceTraceSegment &segment) {
  hash_combine_i64(seed, segment.face);
  hash_row_vector(seed, segment.startBarycentric);
  hash_row_vector(seed, segment.endBarycentric);
  hash_combine_i64(seed, segment.family);
  hash_combine_i64(seed, segment.sign);
  hash_combine_i64(seed, segment.entryEdge);
  hash_combine_i64(seed, segment.exitEdge);
  hash_combine_i64(seed, segment.matching);
  hash_combine_double(seed, segment.matchingEffort);
  hash_combine_i64(seed, segment.railId);
  hash_combine_i64(seed, segment.curveId);
  hash_combine_i64(seed, segment.railIntervalIndex);
  hash_combine_i64(seed, segment.railSideSign);
  hash_combine_double(seed, segment.railT0);
  hash_combine_double(seed, segment.railT1);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_trace_point(std::uint64_t &seed,
                             const geometry::SurfaceTracePoint &point) {
  hash_combine_i64(seed, point.face);
  hash_row_vector(seed, point.barycentric);
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_trace_network(
    const geometry::SurfaceCellNetwork &network) {
  std::uint64_t seed = structural_hash_seed("tracing");
  hash_vector(seed, network.reliefRootVertices);
  hash_combine_i64(seed, network.reliefRegionLabels.size());
  for (Eigen::Index index = 0; index < network.reliefRegionLabels.size(); ++index) {
    hash_combine_i64(seed, network.reliefRegionLabels(index));
  }
  hash_combine_u64(seed, network.reliefBarrierEdges.size());
  for (const std::uint64_t barrier : network.reliefBarrierEdges) {
    hash_combine_u64(seed, barrier);
  }
  hash_vector(seed, network.sourceFaceComponents);
  hash_vector(seed, network.sourceFaceSheets);
  hash_combine_u64(seed, network.authoritativeRails.size());
  for (const geometry::SurfaceCellRail &rail : network.authoritativeRails) {
    hash_combine_i64(seed, rail.id);
    hash_combine_i64(seed, static_cast<int>(rail.kind));
    hash_combine_i64(seed, rail.curveId);
    hash_combine_i64(seed, rail.component);
    hash_combine_i64(seed, rail.closed ? 1 : 0);
    hash_vector(seed, rail.sourceVertices);
    hash_vector(seed, rail.sourceEdges);
    hash_combine_u64(seed, rail.samples.size());
    for (const geometry::SurfaceCellRailSample &sample : rail.samples) {
      hash_combine_i64(seed, sample.sourceFace);
      hash_combine_i64(seed, sample.sourceEdge);
      hash_combine_double(seed, sample.parameter);
      hash_combine_double(seed, sample.railParameter);
      hash_row_vector(seed, sample.barycentric);
      hash_row_vector(seed, sample.position);
    }
  }
  hash_combine_u64(seed, network.seeds.size());
  for (const geometry::SurfaceTraceSeed &traceSeed : network.seeds) {
    hash_combine_i64(seed, traceSeed.id);
    hash_trace_point(seed, traceSeed.point);
    hash_combine_i64(seed, static_cast<int>(traceSeed.provenance));
    hash_combine_i64(seed, traceSeed.sourceId);
  }
  hash_combine_u64(seed, network.traces.size());
  for (const geometry::SurfaceTraceResult &trace : network.traces) {
    hash_combine_u64(seed, trace.segments.size());
    for (const geometry::SurfaceTraceSegment &segment : trace.segments) {
      hash_trace_segment(seed, segment);
    }
    hash_combine_i64(seed, static_cast<int>(trace.termination));
    hash_combine_double(seed, trace.length);
  }
  hash_combine_u64(seed, network.singularSeparatrices.size());
  for (const geometry::SurfaceSingularitySeparatrix &separatrix :
       network.singularSeparatrices) {
    hash_combine_i64(seed, separatrix.sourceVertex);
    hash_combine_i64(seed, separatrix.singularityIndexNumerator);
    hash_combine_i64(seed, separatrix.expectedValence);
    hash_combine_i64(seed, separatrix.branch);
    hash_combine_i64(seed, separatrix.initialFace);
    hash_combine_i64(seed, separatrix.family);
    hash_combine_i64(seed, separatrix.sign);
    hash_combine_double(seed, separatrix.oneRingAngle);
    hash_combine_u64(seed, separatrix.trace.segments.size());
    for (const geometry::SurfaceTraceSegment &segment :
         separatrix.trace.segments) {
      hash_trace_segment(seed, segment);
    }
    hash_combine_i64(seed,
                     static_cast<int>(separatrix.trace.termination));
    hash_combine_double(seed, separatrix.trace.length);
  }
  hash_combine_i64(seed, network.singularSeparatrixStats.singularityCount);
  hash_combine_i64(seed, network.singularSeparatrixStats.expectedBranches);
  hash_combine_i64(seed, network.singularSeparatrixStats.enumeratedBranches);
  hash_combine_i64(seed, network.singularSeparatrixStats.nonemptyBranches);
  hash_combine_i64(seed,
                   network.singularSeparatrixStats.reconciledSingularities);
  hash_combine_i64(seed,
                   network.singularSeparatrixStats.incompleteSingularities);
  hash_combine_i64(seed, network.singularSeparatrixStats.invalidIndexCount);
  hash_combine_i64(seed,
                   network.singularSeparatrixStats.metadataValid ? 1 : 0);
  hash_combine_u64(seed, network.proposals.size());
  for (const geometry::SurfaceCellProposal &proposal : network.proposals) {
    hash_combine_i64(seed, proposal.seedId);
    hash_combine_i64(seed, proposal.accepted ? 1 : 0);
    hash_combine_i64(seed, static_cast<int>(proposal.rejection));
    hash_combine_double(seed, proposal.closureError);
    for (const geometry::SurfaceTracePoint &corner : proposal.corners) {
      hash_trace_point(seed, corner);
    }
    hash_combine_u64(seed, proposal.sides.size());
    for (const geometry::SurfaceTraceSegment &side : proposal.sides) {
      hash_trace_segment(seed, side);
    }
    hash_combine_u64(seed, proposal.boundaryPaths.size());
    for (const auto &path : proposal.boundaryPaths) {
      hash_combine_u64(seed, path.size());
      for (const geometry::SurfaceTraceSegment &segment : path) {
        hash_trace_segment(seed, segment);
      }
    }
  }
  hash_combine_i64(seed, network.stats.attempted);
  hash_combine_i64(seed, network.stats.accepted);
  hash_combine_i64(seed, network.stats.rejectedClosure);
  hash_combine_i64(seed, network.stats.rejectedBarrier);
  hash_combine_i64(seed, network.stats.rejectedDegenerate);
  hash_combine_i64(seed, network.stats.rejectedSourceSheet);
  hash_combine_i64(seed, network.stats.rejectedFieldMetadata);
  hash_combine_i64(seed, network.stats.rejectedSelfIntersection);
  hash_combine_i64(seed, network.stats.rejectedInverted);
  hash_combine_i64(seed, network.stats.rejectedDuplicateCorner);
  hash_combine_i64(seed, network.stats.rejectedOutOfSize);
  hash_combine_i64(seed, network.stats.rejectedHardRailCrossing);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_sparse_network(
    const geometry::FlowRepSparseNetwork &network) {
  std::uint64_t seed = structural_hash_seed("strands");
  hash_combine_i64(seed, network.selectionSucceeded ? 1 : 0);
  hash_combine_i64(seed, static_cast<int>(network.failureCode));
  hash_vector(seed, network.retainedArcIds);
  hash_vector(seed, network.removedArcIds);
  for (const geometry::FlowRepEndpointTag tag : network.endpointTags) {
    hash_combine_i64(seed, static_cast<int>(tag));
  }
  for (const geometry::FlowRepCycleEvaluation &cycle : network.cycleEvaluations) {
    hash_combine_i64(seed, cycle.descriptive ? 1 : 0);
    hash_combine_i64(seed, cycle.quadrangulable ? 1 : 0);
    hash_combine_double(seed, cycle.normalP90);
    hash_combine_double(seed, cycle.surfaceP95);
    hash_combine_double(seed, cycle.sizePenalty);
    hash_combine_double(seed, cycle.quadPenalty);
    hash_combine_double(seed, cycle.energy);
    hash_combine_i64(seed, static_cast<int>(cycle.patchClass));
  }
  hash_combine_i64(seed, network.mandatoryRails);
  hash_combine_i64(seed, network.retainedMandatoryRails);
  hash_combine_i64(seed, network.acceptedTransactions);
  hash_combine_i64(seed, network.attemptedStrandTransactions);
  hash_combine_i64(seed, network.rejectedStrandTransactions);
  hash_combine_i64(seed, network.retainedFlowlines);
  hash_combine_i64(seed, network.removedFlowlines);
  hash_combine_i64(seed, network.cycleRebuilds);
  hash_combine_i64(seed, network.coverageSampleCount);
  hash_combine_i64(seed, network.cycleEvidenceCount);
  hash_combine_i64(seed, network.coverageEvidenceUsed ? 1 : 0);
  hash_combine_i64(seed, network.cycleEvidenceUsed ? 1 : 0);
  hash_combine_double(seed, network.denseCoverageMax);
  hash_combine_double(seed, network.sparseCoverageMax);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_flow_rep_selection_input_components(
    const std::vector<geometry::FlowRepArc> &arcs,
    const std::vector<geometry::FlowRepCoverageSample> &coverageSamples,
    const std::vector<geometry::FlowRepCycleInput> &cycles) {
  std::uint64_t seed = structural_hash_seed("flow-rep-selection-input");
  hash_combine_u64(seed, arcs.size());
  for (const geometry::FlowRepArc &arc : arcs) {
    hash_combine_i64(seed, arc.id);
    hash_row_vector(seed, arc.start);
    hash_row_vector(seed, arc.end);
    hash_combine_i64(seed, arc.sourceFace);
    hash_row_vector(seed, arc.startBarycentric);
    hash_row_vector(seed, arc.endBarycentric);
    hash_combine_i64(seed, arc.startIntrinsicEndpointKeyValid ? 1 : 0);
    hash_combine_i64(seed, arc.endIntrinsicEndpointKeyValid ? 1 : 0);
    hash_combine_u64(seed, arc.startIntrinsicEndpointKey);
    hash_combine_u64(seed, arc.endIntrinsicEndpointKey);
    hash_combine_i64(seed, arc.sourceComponent);
    hash_combine_i64(seed, arc.sourceSheet);
    hash_combine_i64(seed, arc.family);
    hash_combine_i64(seed, arc.featureClass);
    hash_combine_i64(seed, arc.mandatoryRail ? 1 : 0);
    hash_combine_i64(seed, arc.boundaryRail ? 1 : 0);
    hash_combine_i64(seed, arc.hardFeatureRail ? 1 : 0);
    hash_combine_i64(seed, arc.strandProvenance);
    hash_combine_i64(seed, arc.featureProvenance);
    hash_combine_i64(seed, arc.railId);
    hash_combine_i64(seed, arc.curveId);
    hash_combine_double(seed, arc.railT0);
    hash_combine_double(seed, arc.railT1);
    hash_combine_i64(seed, arc.layoutSupport ? 1 : 0);
    hash_combine_i64(seed, arc.singularitySupport ? 1 : 0);
    hash_combine_double(seed, arc.dominance);
    hash_combine_double(seed, arc.alignmentCost);
    hash_combine_i64(seed, arc.sameStrandHint);
    hash_combine_i64(seed, arc.initiallyActive ? 1 : 0);
    hash_combine_i64(seed, arc.proposalId);
    hash_combine_i64(seed, arc.proposalSeedId);
    hash_combine_i64(seed, arc.proposalSide);
    hash_combine_i64(seed, arc.proposalBoundarySegment);
    hash_combine_i64(seed, arc.layoutSupport ? 1 : 0);
    hash_combine_i64(seed, arc.supportTraceId);
    hash_combine_i64(seed, arc.supportSeedId);
    hash_combine_i64(seed, arc.supportSegment);
    hash_combine_i64(seed, arc.startEmbeddedAnchor ? 1 : 0);
    hash_combine_i64(seed, arc.endEmbeddedAnchor ? 1 : 0);
    hash_combine_i64(seed, arc.singularitySupport ? 1 : 0);
    hash_vector(seed, arc.substitutions);
  }
  hash_combine_u64(seed, coverageSamples.size());
  for (const geometry::FlowRepCoverageSample &sample : coverageSamples) {
    hash_row_vector(seed, sample.position);
    hash_combine_i64(seed, sample.sourceFace);
    hash_row_vector(seed, sample.barycentric);
    hash_combine_i64(seed, sample.sourceComponent);
    hash_combine_i64(seed, sample.sourceSheet);
    hash_combine_double(seed, sample.targetSize);
    hash_combine_i64(seed, sample.sourceArcId);
  }
  hash_combine_u64(seed, cycles.size());
  for (const geometry::FlowRepCycleInput &cycle : cycles) {
    hash_combine_i64(seed, cycle.id);
    hash_combine_i64(seed, cycle.proposalId);
    hash_combine_u64(seed, cycle.sideArcIds.size());
    for (const std::vector<int> &side : cycle.sideArcIds) {
      hash_vector(seed, side);
    }
    hash_vector(seed, cycle.boundaryArcIds);
    hash_vector(seed, cycle.sideCounts);
    hash_combine_u64(seed, cycle.normals.size());
    for (const Eigen::RowVector3d &normal : cycle.normals) {
      hash_row_vector(seed, normal);
    }
    for (const Eigen::RowVector3d &normal : cycle.boundaryNormalA) {
      hash_row_vector(seed, normal);
    }
    for (const Eigen::RowVector3d &normal : cycle.boundaryNormalB) {
      hash_row_vector(seed, normal);
    }
    hash_combine_u64(seed, cycle.distanceA.size());
    for (const double value : cycle.distanceA) {
      hash_combine_double(seed, value);
    }
    hash_combine_u64(seed, cycle.distanceB.size());
    for (const double value : cycle.distanceB) {
      hash_combine_double(seed, value);
    }
    hash_combine_u64(seed, cycle.surfaceDistances.size());
    for (const double value : cycle.surfaceDistances) {
      hash_combine_double(seed, value);
    }
    hash_combine_double(seed, cycle.targetSize);
    hash_combine_double(seed, cycle.normalThresholdRadians);
    hash_combine_i64(seed, cycle.diskTopology ? 1 : 0);
    hash_combine_i64(seed, cycle.forbiddenTurn ? 1 : 0);
    hash_combine_i64(seed, cycle.unresolvedHardFeatureCrossing ? 1 : 0);
    hash_combine_i64(seed, cycle.impossibleSideCounts ? 1 : 0);
  }
  return seed;
}

std::uint64_t hash_flow_rep_selection_input(
    const geometry::FlowRepSelectionInput &input) {
  return hash_flow_rep_selection_input_components(
      input.arcs, input.coverageSamples, input.cycles);
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_arrangement_arcs(
    const std::vector<geometry::SurfaceArrangementArc> &arcs) {
  std::uint64_t seed = structural_hash_seed("embedded-network");
  hash_combine_u64(seed, arcs.size());
  for (const geometry::SurfaceArrangementArc &arc : arcs) {
    hash_combine_i64(seed, arc.id);
    hash_combine_i64(seed, arc.sourceFace);
    hash_row_vector(seed, arc.startBarycentric);
    hash_row_vector(seed, arc.endBarycentric);
    hash_combine_i64(seed, arc.family);
    hash_combine_i64(seed, arc.strand);
    hash_combine_i64(seed, arc.featureClass);
    hash_combine_i64(seed, arc.hardFeature ? 1 : 0);
    hash_combine_i64(seed, arc.provenance);
    hash_combine_i64(seed, arc.railId);
    hash_combine_i64(seed, arc.curveId);
    hash_combine_i64(seed, arc.sourceComponent);
    hash_combine_i64(seed, arc.sourceSheet);
    hash_combine_i64(seed, arc.proposalId);
    hash_combine_i64(seed, arc.proposalSeedId);
    hash_combine_i64(seed, arc.proposalSide);
    hash_combine_i64(seed, arc.proposalBoundarySegment);
    hash_combine_double(seed, arc.railT0);
    hash_combine_double(seed, arc.railT1);
  }
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_surface_complex(
    const geometry::SurfaceCellComplex &complex) {
  std::uint64_t seed = structural_hash_seed("arrangement");
  for (const geometry::SurfaceArrangementNode &node : complex.nodes) {
    hash_combine_i64(seed, node.id);
    hash_combine_i64(seed, node.sourceFace);
    hash_combine_i64(seed, node.hardBarrierCrossing ? 1 : 0);
    hash_row_vector(seed, node.barycentric);
    hash_combine_i64(seed, static_cast<int>(node.occurrences.size()));
    for (const geometry::SurfaceArrangementNodeOccurrence &occurrence :
         node.occurrences) {
      hash_combine_i64(seed, occurrence.sourceFace);
      hash_row_vector(seed, occurrence.barycentric);
    }
    hash_combine_i64(seed, node.sourceEdge);
    hash_combine_double(seed, node.sourceEdgeParameter);
  }
  for (const geometry::SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    hash_combine_i64(seed, halfedge.id);
    hash_combine_i64(seed, halfedge.twin);
    hash_combine_i64(seed, halfedge.next);
    hash_combine_i64(seed, halfedge.from);
    hash_combine_i64(seed, halfedge.to);
    hash_combine_i64(seed, halfedge.sourceArc);
    hash_combine_i64(seed, halfedge.family);
    hash_combine_i64(seed, halfedge.strand);
    hash_combine_i64(seed, halfedge.featureClass);
    hash_combine_i64(seed, halfedge.sourceFace);
    hash_combine_double(seed, halfedge.sourceT0);
    hash_combine_double(seed, halfedge.sourceT1);
    hash_combine_i64(seed, halfedge.hardFeature ? 1 : 0);
    hash_combine_i64(seed, halfedge.layoutSupport ? 1 : 0);
    hash_combine_i64(seed, halfedge.singularitySupport ? 1 : 0);
    hash_combine_i64(seed, halfedge.railId);
    hash_combine_i64(seed, halfedge.curveId);
    hash_combine_i64(seed, halfedge.sourceComponent);
    hash_combine_i64(seed, halfedge.sourceSheet);
    hash_combine_i64(seed, halfedge.proposalId);
    hash_combine_i64(seed, halfedge.proposalSeedId);
    hash_combine_i64(seed, halfedge.proposalSide);
    hash_combine_i64(seed, halfedge.proposalBoundarySegment);
    hash_combine_double(seed, halfedge.railT0);
    hash_combine_double(seed, halfedge.railT1);
    hash_combine_i64(seed, halfedge.cell);
  }
  for (const geometry::SurfaceArrangementCell &cell : complex.cells) {
    hash_combine_i64(seed, cell.id);
    hash_combine_i64(seed, cell.sourceFace);
    hash_vector(seed, cell.sourceFaces);
    hash_vector(seed, cell.halfedges);
    hash_vector(seed, cell.sideFamilies);
    hash_vector(seed, cell.sideEdgeCounts);
    hash_combine_double(seed, cell.signedArea);
    hash_combine_double(seed, cell.area);
    hash_combine_i64(seed, cell.boundaryCycle ? 1 : 0);
    hash_combine_i64(seed, cell.closed ? 1 : 0);
    hash_combine_i64(seed, cell.disk ? 1 : 0);
    hash_combine_i64(seed, cell.boundaryComponentCount);
    hash_combine_i64(seed, cell.eulerCharacteristic);
    hash_combine_i64(seed, cell.quadReady ? 1 : 0);
    hash_combine_i64(seed, static_cast<int>(cell.cellClass));
    hash_combine_i64(seed, static_cast<int>(cell.rejectReason));
  }
  hash_combine_i64(seed, complex.diagnostics.plantedIntersections);
  hash_combine_i64(seed, complex.diagnostics.uniqueIntersections);
  hash_combine_i64(seed, complex.diagnostics.unsplitCrossings);
  hash_combine_i64(seed, complex.diagnostics.geometricTJunctions);
  hash_combine_i64(seed, complex.diagnostics.incompleteArcChains);
  hash_combine_i64(seed, complex.diagnostics.hardBarrierCrossings);
  hash_combine_i64(seed, complex.diagnostics.eulerCharacteristic);
  hash_combine_i64(seed, complex.diagnostics.sourceEulerCharacteristic);
  hash_combine_i64(seed, complex.diagnostics.connectedComponentCount);
  hash_combine_i64(seed, complex.diagnostics.sourceConnectedComponentCount);
  hash_combine_i64(seed, complex.diagnostics.boundaryLoopCount);
  hash_combine_i64(seed, complex.diagnostics.sourceBoundaryLoopCount);
  hash_combine_i64(seed, complex.diagnostics.incidenceValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.embeddingValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.orientationValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.cellsDiskValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.boundaryLoopsValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.eulerCharacteristicValid ? 1 : 0);
  hash_combine_i64(seed, complex.diagnostics.topologyValid ? 1 : 0);
  hash_combine_double(seed, complex.diagnostics.supportedArea);
  hash_combine_double(seed, complex.diagnostics.extractedArea);
  hash_combine_double(seed, complex.diagnostics.relativeAreaError);
  hash_combine_double(seed, complex.diagnostics.memoryRatioEstimate);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_completion_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &quads,
    const std::vector<geometry::SurfacePoint> &provenance) {
  std::uint64_t seed = structural_hash_seed("completion");
  hash_matrix(seed, vertices);
  hash_matrix(seed, quads);
  for (const geometry::SurfacePoint &point : provenance) {
    hash_surface_point(seed, point);
  }
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_completion(const geometry::PureQuadMesh &mesh) {
  std::uint64_t seed = structural_hash_seed("completion");
  hash_combine_i64(seed, mesh.sourcePatch);
  hash_combine_u64(seed, mesh.domainIdentity.hash());
  hash_combine_i64(seed, mesh.domainIdentity.boundaryNodeCount);
  hash_combine_i64(seed, mesh.domainIdentity.boundaryHalfedgeCount);
  hash_combine_i64(seed, mesh.domainIdentity.sourceSupportCount);
  hash_vector(seed, mesh.vertices);
  hash_matrix(seed, mesh.vertexPositions);
  hash_combine_u64(seed, mesh.quads.size());
  for (const std::vector<int> &quad : mesh.quads) {
    hash_vector(seed, quad);
  }
  for (const geometry::SurfacePoint &point : mesh.vertexProvenance) {
    hash_surface_point(seed, point);
  }
  hash_combine_u64(seed, mesh.vertexLineage.size());
  for (const geometry::PureQuadVertexLineage &lineage : mesh.vertexLineage) {
    hash_combine_i64(seed, lineage.outputVertex);
    hash_combine_i64(seed, lineage.sourcePatch);
    hash_combine_i64(seed, lineage.localVertex);
    hash_combine_i64(seed, lineage.sourceComponent);
    hash_combine_i64(seed, lineage.sourceSheet);
    hash_combine_i64(seed, static_cast<int>(lineage.stitchIdentity.kind));
    hash_combine_u64(seed, lineage.stitchIdentity.hash());
    hash_combine_i64(seed,
                     static_cast<int>(lineage.authoritativeIdentity.kind));
    hash_combine_u64(seed, lineage.authoritativeIdentity.hash());
  }
  hash_combine_u64(seed, mesh.quadLineage.size());
  for (const geometry::PureQuadFaceLineage &lineage : mesh.quadLineage) {
    hash_combine_i64(seed, lineage.outputQuad);
    hash_combine_i64(seed, lineage.sourcePatch);
    hash_combine_i64(seed, static_cast<int>(lineage.operation));
    hash_combine_i64(seed, lineage.operationLocalQuad);
    hash_combine_i64(seed, lineage.completionVariant);
    hash_combine_i64(seed, lineage.boundaryOnly ? 1 : 0);
    hash_combine_u64(seed, lineage.canonicalStitchCycleHash);
    hash_combine_u64(seed, lineage.canonicalAuthoritativeCycleHash);
  }
  hash_vector(seed, mesh.boundaryVertices);
  hash_combine_i64(seed, static_cast<int>(mesh.backend));
  hash_combine_i64(seed, mesh.usesCenterFan ? 1 : 0);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void hash_vector(std::uint64_t &seed, const Eigen::VectorXi &values) {
  hash_combine_i64(seed, values.size());
  for (Eigen::Index index = 0; index < values.size(); ++index) {
    hash_combine_i64(seed, values(index));
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_relief_topology(
    const geometry::ReliefTopologyResult &topology) {
  std::uint64_t seed = structural_hash_seed("relief");
  hash_vector(seed, topology.relief);
  hash_vector(seed, topology.watershedLabels);
  hash_vector(seed, topology.watershedRoots);
  for (const geometry::ReliefCriticalPoint &point : topology.criticalPoints) {
    hash_combine_i64(seed, point.vertex);
    hash_combine_i64(seed, static_cast<int>(point.type));
    hash_combine_i64(seed, point.lowerComponents);
    hash_combine_i64(seed, point.upperComponents);
    hash_combine_i64(seed, point.multiplicity);
    hash_combine_i64(seed, point.retained ? 1 : 0);
  }
  for (const geometry::ReliefPersistencePair &pair : topology.persistencePairs) {
    hash_combine_i64(seed, pair.extremum);
    hash_combine_i64(seed, pair.saddle);
    hash_combine_i64(seed, pair.minimumPair ? 1 : 0);
    hash_combine_double(seed, pair.persistence);
    hash_combine_i64(seed, pair.canceled ? 1 : 0);
  }
  for (const geometry::ReliefBranch &branch : topology.branches) {
    hash_combine_i64(seed, branch.saddle);
    hash_combine_i64(seed, branch.extremum);
    hash_combine_i64(seed, branch.ascending ? 1 : 0);
    hash_vector(seed, branch.vertices);
  }
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::string structural_hash_string(const std::uint64_t hash) {
  std::ostringstream out;
  out << std::hex << std::setw(16) << std::setfill('0') << hash;
  return out.str();
}

} // namespace directional::pipeline

namespace directional::pipeline {

SurfaceCellObjectIdentity make_surface_cell_identity(
    const std::string &type, const std::uint64_t hash,
    const std::size_t elementCount) {
  SurfaceCellObjectIdentity identity;
  identity.type = type;
  identity.structuralHash = hash;
  identity.elementCount = elementCount;
  return identity;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::string surface_cell_identity_label(
    const SurfaceCellObjectIdentity &identity) {
  return identity.type + ":hash=" +
         structural_hash_string(identity.structuralHash) + ";count=" +
         std::to_string(identity.elementCount);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void normalize_surface_cell_cross_field_directions(
    fields::CrossFieldResult &crossField) {
  if (crossField.primaryDirections.rows() != crossField.rawField.rows() &&
      crossField.rawField.cols() >= 6) {
    crossField.primaryDirections =
        crossField.rawField.block(0, 0, crossField.rawField.rows(), 3);
    crossField.secondaryDirections =
        crossField.rawField.block(0, 3, crossField.rawField.rows(), 3);
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

fields::CrossFieldResult make_surface_cell_cross_field_context(
    const Eigen::MatrixXd &rawCrossField) {
  fields::CrossFieldResult crossField;
  crossField.degree = fields::kCrossFieldDegree;
  crossField.rawField = rawCrossField;
  normalize_surface_cell_cross_field_directions(crossField);
  return crossField;
}

} // namespace directional::pipeline

namespace directional::pipeline {

fields::CrossFieldResult finalize_surface_cell_raw_cross_field(
    const TriMesh &meshWhole, const Eigen::MatrixXd &rawCrossField) {
  if (rawCrossField.rows() != meshWhole.F.rows() ||
      rawCrossField.cols() != 3 * fields::kCrossFieldDegree) {
    throw std::invalid_argument(
        "SurfaceCells raw cross field must have shape (#F, 12).");
  }
  for (Eigen::Index face = 0; face < rawCrossField.rows(); ++face) {
    for (Eigen::Index col = 0; col < rawCrossField.cols(); ++col) {
      if (!std::isfinite(rawCrossField(face, col))) {
        throw std::invalid_argument(
            "SurfaceCells raw cross field contains a nonfinite value.");
      }
    }
    for (int branch = 0; branch < fields::kCrossFieldDegree; ++branch) {
      if (rawCrossField.block(face, 3 * branch, 1, 3).norm() <= 1.0e-12) {
        throw std::invalid_argument(
            "SurfaceCells raw cross field contains a zero-length branch.");
      }
    }
  }
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(meshWhole);

  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD,
                fields::kCrossFieldDegree);
  rawField.set_extrinsic_field(rawCrossField);

  // Boundary cycles measure the total turning of an open surface boundary,
  // which is not a point singularity and need not be an integer multiple of
  // 1/N. Compute edge matching first, then derive singularities only from
  // interior vertex cycles. Treating the aggregate boundary cycle as a local
  // singularity caused valid open strips and cylinders to fail raw-field
  // finalization before tracing.
  principal_matching(rawField, false);

  fields::CrossFieldResult crossField;
  crossField.degree = fields::kCrossFieldDegree;
  crossField.rawField = rawField.extField;
  normalize_surface_cell_cross_field_directions(crossField);
  crossField.matching = rawField.matching;
  crossField.effort = rawField.effort;
  fields::populate_cross_field_edge_transitions(rawField, crossField);
  crossField.matchingComputed = true;

  Eigen::VectorXd interiorEffort(tangentBundle.innerAdjacencies.size());
  for (int index = 0; index < tangentBundle.innerAdjacencies.size(); ++index) {
    interiorEffort(index) =
        rawField.effort(tangentBundle.innerAdjacencies(index));
  }
  const Eigen::VectorXd cycleIndices =
      ((tangentBundle.cycles * interiorEffort +
        static_cast<double>(fields::kCrossFieldDegree) *
            tangentBundle.cycleCurvatures)
           .array() /
       (2.0 * std::numbers::pi));

  std::vector<char> boundaryVertex(
      static_cast<std::size_t>(meshWhole.V.rows()), 0);
  for (const std::vector<int> &loop : meshWhole.boundaryLoops) {
    for (const int vertex : loop) {
      if (vertex >= 0 && vertex < meshWhole.V.rows()) {
        boundaryVertex[static_cast<std::size_t>(vertex)] = 1;
      }
    }
  }
  std::vector<int> singularVertices;
  std::vector<int> singularNumerators;
  for (int vertex = 0; vertex < tangentBundle.local2Cycle.size(); ++vertex) {
    if (boundaryVertex[static_cast<std::size_t>(vertex)] != 0) {
      continue;
    }
    const int cycle = tangentBundle.local2Cycle(vertex);
    if (cycle < 0 || cycle >= cycleIndices.size()) {
      throw std::runtime_error(
          "SurfaceCells cross field contains an invalid interior cycle map.");
    }
    const double value = cycleIndices(cycle);
    const double rounded = std::round(value);
    if (!std::isfinite(value) || std::abs(value - rounded) >= 1.0e-6) {
      throw std::runtime_error(
          "SurfaceCells interior singularity index is not naturally integer.");
    }
    const int numerator = static_cast<int>(rounded);
    if (numerator != 0) {
      singularVertices.push_back(vertex);
      singularNumerators.push_back(numerator);
    }
  }
  crossField.singularCycles.resize(
      static_cast<Eigen::Index>(singularVertices.size()));
  crossField.singularIndices.resize(
      static_cast<Eigen::Index>(singularNumerators.size()));
  for (Eigen::Index index = 0; index < crossField.singularCycles.size();
       ++index) {
    crossField.singularCycles(index) =
        singularVertices[static_cast<std::size_t>(index)];
    crossField.singularIndices(index) =
        singularNumerators[static_cast<std::size_t>(index)];
  }
  crossField.singularitiesComputed = true;

  crossField.confidence = Eigen::VectorXd::Ones(meshWhole.F.rows());
  crossField.uncoveredFaces.resize(0);
  crossField.confidenceComputed = true;
  crossField.uncoveredFacePolicyApplied = true;
  return crossField;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t surface_cell_source_edge_key(const int a, const int b) {
  const int lo = std::min(a, b);
  const int hi = std::max(a, b);
  return (static_cast<std::uint64_t>(static_cast<std::uint32_t>(lo)) << 32u) |
         static_cast<std::uint32_t>(hi);
}

} // namespace directional::pipeline

namespace directional::pipeline {

bool cross_field_transitions_match_source_edges(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField) {
  if (crossField.matching.size() != meshWhole.EF.rows() ||
      crossField.effort.size() != meshWhole.EF.rows()) {
    return false;
  }
  std::set<int> seenEdges;
  for (const fields::CrossFieldEdgeTransition &transition :
       crossField.edgeTransitions) {
    if (transition.sourceEdge < 0 ||
        transition.sourceEdge >= meshWhole.EF.rows() ||
        !seenEdges.insert(transition.sourceEdge).second) {
      return false;
    }
    const int edge = transition.sourceEdge;
    if (surface_cell_source_edge_key(transition.sourceVertex0,
                                     transition.sourceVertex1) !=
        surface_cell_source_edge_key(meshWhole.EV(edge, 0),
                                     meshWhole.EV(edge, 1))) {
      return false;
    }
    if (transition.firstFace != meshWhole.EF(edge, 0) ||
        transition.secondFace != meshWhole.EF(edge, 1)) {
      return false;
    }
    if (transition.matching != crossField.matching(edge) ||
        !std::isfinite(transition.effort) ||
        std::abs(transition.effort - crossField.effort(edge)) > 1.0e-12) {
      return false;
    }
  }
  for (int edge = 0; edge < meshWhole.EF.rows(); ++edge) {
    if (meshWhole.EF(edge, 0) >= 0 && meshWhole.EF(edge, 1) >= 0 &&
        seenEdges.count(edge) == 0) {
      return false;
    }
  }
  return true;
}

} // namespace directional::pipeline

namespace directional::pipeline {

SurfaceCellFailureCode validate_surface_cell_cross_field(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const SurfaceCellOptions &options) {
  if (crossField.degree != fields::kCrossFieldDegree ||
      crossField.rawField.rows() != meshWhole.F.rows() ||
      crossField.rawField.cols() != 12 ||
      crossField.primaryDirections.rows() != meshWhole.F.rows() ||
      crossField.secondaryDirections.rows() != meshWhole.F.rows()) {
    return SurfaceCellFailureCode::InvalidFieldDimensions;
  }
  if (options.requireMatching &&
      (!crossField.matchingComputed || crossField.matching.size() == 0 ||
       crossField.effort.size() != crossField.matching.size() ||
       !cross_field_transitions_match_source_edges(meshWhole, crossField))) {
    return SurfaceCellFailureCode::MissingMatching;
  }
  if (options.requireSingularities && !crossField.singularitiesComputed) {
    return SurfaceCellFailureCode::MissingSingularities;
  }
  if (!crossField.confidenceComputed ||
      crossField.confidence.rows() != meshWhole.F.rows()) {
    return SurfaceCellFailureCode::MissingConfidence;
  }
  if (!crossField.uncoveredFacePolicyApplied ||
      crossField.uncoveredFaces.size() > 0) {
    return SurfaceCellFailureCode::UncoveredFaces;
  }
  return SurfaceCellFailureCode::None;
}

} // namespace directional::pipeline

namespace directional::pipeline {

int surface_cell_local_edge_index(const Eigen::MatrixXi &faces,
                                         const int face, const int a,
                                         const int b) {
  if (face < 0 || face >= faces.rows()) {
    return -1;
  }
  for (const auto &[u, v, edge] :
       {std::tuple<int, int, int>{0, 1, 2}, {1, 2, 0}, {2, 0, 1}}) {
    const int fu = faces(face, u);
    const int fv = faces(face, v);
    if ((fu == a && fv == b) || (fu == b && fv == a)) {
      return edge;
    }
  }
  return -1;
}

} // namespace directional::pipeline

namespace directional::pipeline {

geometry::SurfaceCellRailSample make_surface_cell_rail_sample(
    const TriMesh &meshWhole, const int face, const int a, const int b,
    const double t, const double railParameter) {
  geometry::SurfaceCellRailSample sample;
  sample.sourceFace = face;
  sample.sourceEdge = surface_cell_local_edge_index(meshWhole.F, face, a, b);
  sample.parameter = t;
  sample.railParameter = railParameter;
  if (face >= 0 && face < meshWhole.F.rows()) {
    for (int corner = 0; corner < 3; ++corner) {
      if (meshWhole.F(face, corner) == a) {
        sample.barycentric[corner] = 1.0 - t;
      } else if (meshWhole.F(face, corner) == b) {
        sample.barycentric[corner] = t;
      }
    }
    sample.position = sample.barycentric[0] * meshWhole.V.row(meshWhole.F(face, 0)) +
                      sample.barycentric[1] * meshWhole.V.row(meshWhole.F(face, 1)) +
                      sample.barycentric[2] * meshWhole.V.row(meshWhole.F(face, 2));
  }
  return sample;
}

} // namespace directional::pipeline

namespace directional::pipeline {

bool surface_cell_feature_edge_is_rail(
    const geometry::AdaptiveFeatureEdge &edge) {
  return edge.edgeClass == geometry::AdaptiveFeatureClass::Boundary ||
         edge.edgeClass == geometry::AdaptiveFeatureClass::Hard;
}

} // namespace directional::pipeline

namespace directional::pipeline {

SurfaceCellRailBuildResult build_authoritative_surface_cell_rails(
    const TriMesh &meshWhole, const geometry::AdaptiveFeatureMap &featureMap) {
  SurfaceCellRailBuildResult result;
  std::set<int> coveredEdges;
  const auto fail_edge = [&](const int edgeIndex) {
    result.success = false;
    result.failedEdgeIndex = edgeIndex;
    result.rails.clear();
    return false;
  };
  const auto append_edge_interval = [&](geometry::SurfaceCellRail &rail,
                                        const geometry::AdaptiveFeatureEdge &edge,
                                        const int edgeIndex, const int a,
                                        const int b, const double t0,
                                        const double t1) {
    int face = -1;
    for (const int incidentFace : edge.incidentFaces) {
      if (incidentFace >= 0 && incidentFace < meshWhole.F.rows()) {
        face = incidentFace;
        break;
      }
    }
    if (face < 0 || a < 0 || b < 0 || a >= meshWhole.V.rows() ||
        b >= meshWhole.V.rows() || a == b) {
      return fail_edge(edgeIndex);
    }
    bool hasA = false;
    bool hasB = false;
    for (int corner = 0; corner < 3; ++corner) {
      hasA = hasA || meshWhole.F(face, corner) == a;
      hasB = hasB || meshWhole.F(face, corner) == b;
    }
    if (!hasA || !hasB) {
      return fail_edge(edgeIndex);
    }
    const geometry::SurfaceCellRailSample startSample =
        make_surface_cell_rail_sample(meshWhole, face, a, b, 0.0, t0);
    const geometry::SurfaceCellRailSample endSample =
        make_surface_cell_rail_sample(meshWhole, face, a, b, 1.0, t1);
    if (startSample.sourceEdge < 0 || endSample.sourceEdge < 0) {
      return fail_edge(edgeIndex);
    }
    rail.samples.push_back(startSample);
    rail.samples.push_back(endSample);
    return true;
  };

  struct OrderedCurveEdge {
    int edgeIndex = -1;
    int startVertex = -1;
    int endVertex = -1;
    bool isRail = false;
    geometry::SurfaceCellRailKind kind =
        geometry::SurfaceCellRailKind::Boundary;
  };

  const auto emit_run = [&](const geometry::AdaptiveFeatureCurve &curve,
                            const std::vector<OrderedCurveEdge> &ordered,
                            const std::vector<int> &run,
                            const bool closed) {
    if (run.empty()) {
      return true;
    }
    geometry::SurfaceCellRail rail;
    rail.id = static_cast<int>(result.rails.size());
    rail.kind = ordered[static_cast<std::size_t>(run.front())].kind;
    rail.curveId = curve.id;
    rail.component = curve.component;
    rail.closed = closed;
    rail.sourceVertices.push_back(
        ordered[static_cast<std::size_t>(run.front())].startVertex);
    for (int localIndex = 0; localIndex < static_cast<int>(run.size());
         ++localIndex) {
      const OrderedCurveEdge &entry =
          ordered[static_cast<std::size_t>(run[static_cast<std::size_t>(localIndex)])];
      if (entry.kind != rail.kind || !entry.isRail ||
          rail.sourceVertices.back() != entry.startVertex) {
        return fail_edge(entry.edgeIndex);
      }
      const geometry::AdaptiveFeatureEdge &edge =
          featureMap.edges[static_cast<std::size_t>(entry.edgeIndex)];
      const double t0 = static_cast<double>(localIndex) /
                        static_cast<double>(run.size());
      const double t1 = static_cast<double>(localIndex + 1) /
                        static_cast<double>(run.size());
      if (!append_edge_interval(rail, edge, entry.edgeIndex, entry.startVertex,
                                entry.endVertex, t0, t1)) {
        return false;
      }
      rail.sourceEdges.push_back(entry.edgeIndex);
      rail.sourceVertices.push_back(entry.endVertex);
      coveredEdges.insert(entry.edgeIndex);
    }
    if (closed) {
      if (rail.sourceVertices.front() != rail.sourceVertices.back()) {
        return fail_edge(rail.sourceEdges.back());
      }
      rail.sourceVertices.pop_back();
    }
    result.rails.push_back(std::move(rail));
    return true;
  };

  for (const geometry::AdaptiveFeatureCurve &curve : featureMap.curves) {
    const int edgeCount = static_cast<int>(curve.edges.size());
    if (edgeCount == 0) {
      continue;
    }
    const bool hasExplicitClosingVertex =
        curve.vertices.size() == static_cast<std::size_t>(edgeCount + 1);
    const bool hasImplicitClosingVertex =
        curve.closed &&
        curve.vertices.size() == static_cast<std::size_t>(edgeCount);
    if (!hasExplicitClosingVertex && !hasImplicitClosingVertex) {
      fail_edge(curve.edges.front());
      return result;
    }

    std::vector<OrderedCurveEdge> ordered;
    ordered.reserve(static_cast<std::size_t>(edgeCount));
    for (int index = 0; index < edgeCount; ++index) {
      const int edgeIndex = curve.edges[static_cast<std::size_t>(index)];
      if (edgeIndex < 0 ||
          edgeIndex >= static_cast<int>(featureMap.edges.size())) {
        fail_edge(edgeIndex);
        return result;
      }
      const geometry::AdaptiveFeatureEdge &edge =
          featureMap.edges[static_cast<std::size_t>(edgeIndex)];
      const int a = curve.vertices[static_cast<std::size_t>(index)];
      const int b = hasExplicitClosingVertex
                        ? curve.vertices[static_cast<std::size_t>(index + 1)]
                        : curve.vertices[static_cast<std::size_t>(
                              (index + 1) % edgeCount)];
      if (geometry::AdaptiveFeatureMap::canonical_edge(a, b) !=
          geometry::AdaptiveFeatureMap::canonical_edge(edge.vertices.first,
                                                       edge.vertices.second)) {
        fail_edge(edgeIndex);
        return result;
      }
      OrderedCurveEdge entry;
      entry.edgeIndex = edgeIndex;
      entry.startVertex = a;
      entry.endVertex = b;
      entry.isRail = surface_cell_feature_edge_is_rail(edge);
      entry.kind = edge.edgeClass == geometry::AdaptiveFeatureClass::Hard
                       ? geometry::SurfaceCellRailKind::HardFeature
                       : geometry::SurfaceCellRailKind::Boundary;
      ordered.push_back(entry);
    }

    const bool allRail = std::all_of(
        ordered.begin(), ordered.end(),
        [](const OrderedCurveEdge &entry) { return entry.isRail; });
    const bool oneKind = allRail &&
                         std::all_of(ordered.begin() + 1, ordered.end(),
                                     [&](const OrderedCurveEdge &entry) {
                                       return entry.kind == ordered.front().kind;
                                     });
    if (curve.closed && allRail && oneKind) {
      std::vector<int> run(static_cast<std::size_t>(edgeCount));
      std::iota(run.begin(), run.end(), 0);
      if (!emit_run(curve, ordered, run, true)) {
        return result;
      }
      continue;
    }

    int startIndex = 0;
    if (curve.closed) {
      for (int index = 0; index < edgeCount; ++index) {
        const int previous = (index + edgeCount - 1) % edgeCount;
        if (!ordered[static_cast<std::size_t>(index)].isRail ||
            !ordered[static_cast<std::size_t>(previous)].isRail ||
            ordered[static_cast<std::size_t>(index)].kind !=
                ordered[static_cast<std::size_t>(previous)].kind) {
          startIndex = index;
          break;
        }
      }
    }

    int processed = 0;
    int index = startIndex;
    while (processed < edgeCount) {
      const OrderedCurveEdge &entry =
          ordered[static_cast<std::size_t>(index)];
      if (!entry.isRail) {
        index = (index + 1) % edgeCount;
        ++processed;
        continue;
      }
      const geometry::SurfaceCellRailKind kind = entry.kind;
      std::vector<int> run;
      while (processed < edgeCount) {
        const OrderedCurveEdge &candidate =
            ordered[static_cast<std::size_t>(index)];
        if (!candidate.isRail || candidate.kind != kind) {
          break;
        }
        run.push_back(index);
        index = (index + 1) % edgeCount;
        ++processed;
      }
      if (!emit_run(curve, ordered, run, false)) {
        return result;
      }
    }
  }

  for (int edgeIndex = 0;
       edgeIndex < static_cast<int>(featureMap.edges.size()); ++edgeIndex) {
    if (coveredEdges.count(edgeIndex) != 0) {
      continue;
    }
    const geometry::AdaptiveFeatureEdge &edge =
        featureMap.edges[static_cast<std::size_t>(edgeIndex)];
    if (!surface_cell_feature_edge_is_rail(edge)) {
      continue;
    }
    geometry::SurfaceCellRail rail;
    rail.id = static_cast<int>(result.rails.size());
    rail.kind = edge.edgeClass == geometry::AdaptiveFeatureClass::Hard
                    ? geometry::SurfaceCellRailKind::HardFeature
                    : geometry::SurfaceCellRailKind::Boundary;
    rail.curveId = edge.curve;
    rail.component = edge.component;
    rail.closed = false;
    rail.sourceVertices = {edge.vertices.first, edge.vertices.second};
    rail.sourceEdges = {edgeIndex};
    if (!append_edge_interval(rail, edge, edgeIndex, edge.vertices.first,
                              edge.vertices.second, 0.0, 1.0)) {
      return result;
    }
    result.rails.push_back(std::move(rail));
  }

  const auto railValidation =
      geometry::surface_cell_tracing_detail::rail_interval_refs(
          result.rails, meshWhole.V, meshWhole.F,
          geometry::surface_cell_tracing_detail::edge_faces(meshWhole.F));
  if (railValidation.status !=
      geometry::surface_cell_tracing_detail::RailBuildStatus::Valid) {
    result.success = false;
    result.validationStatus = railValidation.status;
    result.failedRailId = railValidation.railId;
    result.failedIntervalIndex = railValidation.intervalIndex;
    if (railValidation.railId >= 0 &&
        railValidation.railId < static_cast<int>(result.rails.size()) &&
        railValidation.intervalIndex >= 0 &&
        railValidation.intervalIndex < static_cast<int>(
            result.rails[static_cast<std::size_t>(railValidation.railId)]
                .sourceEdges.size())) {
      result.failedEdgeIndex =
          result.rails[static_cast<std::size_t>(railValidation.railId)]
              .sourceEdges[static_cast<std::size_t>(
                  railValidation.intervalIndex)];
    }
    result.rails.clear();
  }
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::set<std::uint64_t> relief_barrier_edges_from_topology(
    const geometry::ReliefTopologyResult &topology) {
  std::set<std::uint64_t> barriers;
  for (const geometry::ReliefBranch &branch : topology.branches) {
    for (int index = 0; index + 1 < static_cast<int>(branch.vertices.size());
         ++index) {
      barriers.insert(surface_cell_source_edge_key(
          branch.vertices[static_cast<std::size_t>(index)],
          branch.vertices[static_cast<std::size_t>(index + 1)]));
    }
  }
  return barriers;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_relief_operational_inputs(
    const geometry::ReliefRootSelectionResult &roots,
    const std::set<std::uint64_t> &barriers) {
  std::uint64_t seed = structural_hash_seed("relief-consumption");
  hash_vector(seed, roots.roots);
  hash_vector(seed, roots.labels);
  hash_matrix(seed, roots.targets);
  hash_combine_u64(seed, barriers.size());
  for (const std::uint64_t barrier : barriers) {
    hash_combine_u64(seed, barrier);
  }
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::set<std::uint64_t> hard_feature_edge_keys_from_rails(
    const std::vector<geometry::SurfaceCellRail> &rails) {
  std::set<std::uint64_t> keys;
  for (const geometry::SurfaceCellRail &rail : rails) {
    if (rail.kind != geometry::SurfaceCellRailKind::HardFeature) {
      continue;
    }
    for (int index = 0; index + 1 < static_cast<int>(rail.sourceVertices.size());
         ++index) {
      keys.insert(surface_cell_source_edge_key(
          rail.sourceVertices[static_cast<std::size_t>(index)],
          rail.sourceVertices[static_cast<std::size_t>(index + 1)]));
    }
    if (rail.closed && rail.sourceVertices.size() > 1U &&
        rail.sourceVertices.back() != rail.sourceVertices.front()) {
      keys.insert(surface_cell_source_edge_key(rail.sourceVertices.back(),
                                               rail.sourceVertices.front()));
    }
  }
  return keys;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void fill_surface_cell_rail_constraints(
    const std::vector<geometry::SurfaceCellRail> &rails,
    const Eigen::MatrixXd &outputVertices,
    const std::vector<geometry::SurfacePoint> &outputProvenance,
    geometry::SurfaceOptimizationConstraints &constraints) {
  geometry::fill_surface_optimization_rail_constraints(
      rails, outputVertices, outputProvenance, constraints);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void fill_surface_cell_rail_constraints(
    const std::vector<geometry::SurfaceCellRail> &rails,
    geometry::SurfaceOptimizationConstraints &constraints) {
  constraints.featureCurveIntervals.clear();
  constraints.featureIntervals.clear();
  constraints.featureVertices.clear();
  constraints.orderedFeatureVertices.clear();
  constraints.authoritativeBoundaryEdges.clear();
  constraints.authoritativeBoundaryLoop.clear();
  constraints.authoritativeBoundaryLoops.clear();
  constraints.authoritativeFeatureRails.clear();
  constraints.requiredFeatureRailCount = 0;
  constraints.missingFeatureRailIds.clear();
  constraints.featureRailAuthorityProvided = true;
  constraints.featureCurveIds.resize(0);
  constraints.featureRailIds.resize(0);
  constraints.featureIntervalIds.resize(0);
  constraints.featureParameters.resize(0);

  for (const geometry::SurfaceCellRail &rail : rails) {
    if (rail.kind != geometry::SurfaceCellRailKind::Boundary) {
      continue;
    }
    for (int index = 0;
         index + 1 < static_cast<int>(rail.sourceVertices.size()); ++index) {
      const int a = rail.sourceVertices[static_cast<std::size_t>(index)];
      const int b = rail.sourceVertices[static_cast<std::size_t>(index + 1)];
      constraints.authoritativeBoundaryEdges.insert(
          {std::min(a, b), std::max(a, b)});
    }
    if (rail.closed && rail.sourceVertices.size() > 1U) {
      if (rail.sourceVertices.back() != rail.sourceVertices.front()) {
        constraints.authoritativeBoundaryEdges.insert(
            {std::min(rail.sourceVertices.back(), rail.sourceVertices.front()),
             std::max(rail.sourceVertices.back(), rail.sourceVertices.front())});
      }
      if (constraints.authoritativeBoundaryLoop.empty()) {
        constraints.authoritativeBoundaryLoop = rail.sourceVertices;
        if (constraints.authoritativeBoundaryLoop.size() > 1U &&
            constraints.authoritativeBoundaryLoop.front() ==
                constraints.authoritativeBoundaryLoop.back()) {
          constraints.authoritativeBoundaryLoop.pop_back();
        }
      }
    }
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_surface_cell_rails(
    const std::vector<geometry::SurfaceCellRail> &rails) {
  std::uint64_t seed = structural_hash_seed("rails");
  hash_combine_u64(seed, rails.size());
  for (const geometry::SurfaceCellRail &rail : rails) {
    hash_combine_i64(seed, rail.id);
    hash_combine_i64(seed, static_cast<int>(rail.kind));
    hash_combine_i64(seed, rail.curveId);
    hash_combine_i64(seed, rail.component);
    hash_combine_i64(seed, rail.closed ? 1 : 0);
    hash_vector(seed, rail.sourceVertices);
    hash_vector(seed, rail.sourceEdges);
    hash_combine_u64(seed, rail.samples.size());
    for (const geometry::SurfaceCellRailSample &sample : rail.samples) {
      hash_combine_i64(seed, sample.sourceFace);
      hash_combine_i64(seed, sample.sourceEdge);
      hash_combine_double(seed, sample.parameter);
      hash_combine_double(seed, sample.railParameter);
      hash_row_vector(seed, sample.barycentric);
      hash_row_vector(seed, sample.position);
    }
  }
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void record_surface_cell_context_product(
    SurfaceCellPipelineContext &context, const std::string &name,
    const SurfaceCellObjectIdentity &identity, const bool available) {
  SurfaceCellContextProductDebug product;
  product.name = name;
  product.type = identity.type;
  product.structuralHash = identity.structuralHash;
  product.elementCount = identity.elementCount;
  product.available = available;
  context.debugProducts.push_back(product);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void record_face_degree_histogram(RemeshResult &result) {
  result.diagnostics.faceDegreeHistogram.clear();
  for (Eigen::Index face = 0; face < result.degrees.size(); ++face) {
    const int degree = result.degrees(face);
    if (degree < 0) {
      continue;
    }
    const std::size_t index = static_cast<std::size_t>(degree);
    if (result.diagnostics.faceDegreeHistogram.size() <= index) {
      result.diagnostics.faceDegreeHistogram.resize(index + 1U, 0U);
    }
    ++result.diagnostics.faceDegreeHistogram[index];
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::size_t surface_cell_validation_failure_count(
    const geometry::SurfaceFinalValidationReport &validation,
    const bool enforceOptimizerTimeGate) {
  if (validation.accepted) {
    return 0U;
  }

  auto nonnegative = [](const int value) -> std::size_t {
    return value > 0 ? static_cast<std::size_t>(value) : 0U;
  };

  std::size_t failures = 0U;
  failures += nonnegative(validation.tJunctions);
  failures += nonnegative(validation.nonManifold);
  failures += nonnegative(validation.degenerate);
  failures += nonnegative(validation.inverted);
  failures += nonnegative(validation.selfIntersecting);
  failures += nonnegative(validation.nonConvex);
  failures += nonnegative(validation.boundaryValenceMismatchCount);
  failures += nonnegative(validation.requiredSingularityValenceMismatchCount);
  failures += nonnegative(validation.connectedComponentMismatchCount);
  failures += nonnegative(validation.eulerCharacteristicMismatchCount);
  failures += nonnegative(validation.boundaryCycleMismatchCount);
  failures += nonnegative(validation.featureRailMismatchCount);
  failures += nonnegative(validation.provenanceFailureCount);
  failures += nonnegative(validation.localSheetMismatchCount);
  failures += nonnegative(validation.duplicateFaceCount);
  failures += nonnegative(validation.bowTieVertexCount);

  auto failed_upper_bound = [&](const double value,
                                const double maximum) {
    failures += value <= maximum ? 0U : 1U;
  };
  auto failed_lower_bound = [&](const double value,
                                const double minimum) {
    failures += value >= minimum ? 0U : 1U;
  };
  failed_upper_bound(validation.quadToSourceP95, 0.15);
  failed_upper_bound(validation.quadToSourceMax, 0.50);
  failed_upper_bound(validation.sourceToOutputP95, 0.15);
  failed_upper_bound(validation.sourceToOutputMax, 0.50);
  failed_upper_bound(validation.normalP95Degrees, 15.0);
  failed_upper_bound(validation.fieldMedianDegrees, 7.5);
  failed_upper_bound(validation.fieldP95Degrees, 15.0);
  failed_lower_bound(validation.sizeP5, 0.50);
  failed_upper_bound(validation.sizeP95, 2.00);
  failed_lower_bound(validation.angleP5Degrees, 35.0);
  failed_upper_bound(validation.angleP95Degrees, 145.0);
  failed_upper_bound(validation.warpageP95Degrees, 30.0);
  failed_upper_bound(validation.warpageMaxDegrees, 60.0);
  failed_upper_bound(validation.aspectP95, 4.0);
  failed_upper_bound(validation.aspectP99, 8.0);
  failures += validation.scaledJacobianMin > 0.0 ? 0U : 1U;
  failed_lower_bound(validation.scaledJacobianP5, 0.20);

  failures += validation.topologyHashFixed ? 0U : 1U;
  failures += validation.featureParametersOrdered ? 0U : 1U;
  failures += validation.projectionStayedOnComponents ? 0U : 1U;
  if (enforceOptimizerTimeGate && !validation.optimizerTimeWithinGate) {
    failures += 1U;
  }
  if (validation.authoritativeBoundaryUsed &&
      !validation.orderedBoundaryCyclesPassed &&
      validation.boundaryCycleMismatchCount <= 0) {
    failures += 1U;
  }
  if (validation.authoritativeFeatureRailsUsed &&
      !validation.authoritativeFeatureRailsPassed &&
      validation.featureRailMismatchCount <= 0) {
    failures += 1U;
  }
  if (validation.provenanceValidationUsed &&
      !validation.localSheetCompatibilityPassed &&
      validation.localSheetMismatchCount <= 0) {
    failures += 1U;
  }

  if (!validation.accepted && failures == 0U) {
    failures = 1U;
  }
  return failures;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_surface_cell_validation(
    const geometry::SurfaceFinalValidationReport &validation,
    const bool enforceOptimizerTimeGate) {
  std::uint64_t seed = structural_hash_seed("validation");
  hash_combine_i64(seed, validation.accepted ? 1 : 0);
  hash_combine_i64(seed, enforceOptimizerTimeGate ? 1 : 0);
  hash_combine_u64(
      seed, surface_cell_validation_failure_count(
                validation, enforceOptimizerTimeGate));
  hash_combine_i64(seed, validation.tJunctions);
  hash_combine_i64(seed, validation.nonManifold);
  hash_combine_i64(seed, validation.degenerate);
  hash_combine_i64(seed, validation.inverted);
  hash_combine_i64(seed, validation.selfIntersecting);
  hash_combine_i64(seed, validation.nonConvex);
  hash_combine_i64(seed, validation.connectedComponentMismatchCount);
  hash_combine_i64(seed, validation.eulerCharacteristicMismatchCount);
  hash_combine_i64(seed, validation.boundaryCycleMismatchCount);
  hash_combine_i64(seed, validation.featureRailMismatchCount);
  hash_combine_i64(seed, validation.provenanceFailureCount);
  hash_combine_i64(seed, validation.localSheetMismatchCount);
  hash_combine_i64(seed, validation.duplicateFaceCount);
  hash_combine_i64(seed, validation.bowTieVertexCount);
  hash_combine_i64(seed, validation.topologyHashFixed ? 1 : 0);
  hash_combine_i64(seed, validation.featureParametersOrdered ? 1 : 0);
  hash_combine_i64(seed, validation.projectionStayedOnComponents ? 1 : 0);
  hash_combine_i64(seed, validation.orderedBoundaryCyclesPassed ? 1 : 0);
  hash_combine_i64(seed, validation.authoritativeFeatureRailsPassed ? 1 : 0);
  hash_combine_i64(seed, validation.localSheetCompatibilityPassed ? 1 : 0);
  hash_combine_double(seed, validation.surfaceP95);
  hash_combine_double(seed, validation.surfaceMax);
  hash_combine_double(seed, validation.fieldMedianDegrees);
  hash_combine_double(seed, validation.fieldP95Degrees);
  hash_combine_double(seed, validation.scaledJacobianMin);
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void clear_unavailable_surface_cell_counts(
    directional::RemeshDiagnostics &diagnostics) {
  if (!diagnostics.surfaceCellValidationFailureCountAvailable) {
    diagnostics.surfaceCellValidationFailures = 0U;
  }
  if (!diagnostics.surfaceCellProvenanceVertexCountAvailable) {
    diagnostics.surfaceCellProvenanceVertexCount = 0U;
  }
  if (!diagnostics.surfaceCellFeatureCountAvailable) {
    diagnostics.surfaceCellFeatureCount = 0U;
  }
  if (!diagnostics.surfaceCellMetricSampleCountAvailable) {
    diagnostics.surfaceCellMetricSampleCount = 0U;
  }
  if (!diagnostics.surfaceCellReliefCountAvailable) {
    diagnostics.surfaceCellReliefPatchCount = 0U;
  }
  if (!diagnostics.surfaceCellTraceCountAvailable) {
    diagnostics.surfaceCellTraceSegmentCount = 0U;
  }
  if (!diagnostics.surfaceCellArrangementCountAvailable) {
    diagnostics.surfaceCellArrangementCellCount = 0U;
  }
  if (!diagnostics.surfaceCellSimplifiedCountAvailable) {
    diagnostics.surfaceCellSimplifiedCellCount = 0U;
  }
  if (!diagnostics.surfaceCellCompletedQuadCountAvailable) {
    diagnostics.surfaceCellCompletedQuadCount = 0U;
  }
  if (!diagnostics.surfaceCellCompletionOwnershipRepairAttemptsAvailable) {
    diagnostics.surfaceCellCompletionOwnershipRepairAttempts = 0U;
  }
  if (!diagnostics.surfaceCellCompletionOwnershipStructuralLedgerAvailable) {
    diagnostics.surfaceCellCompletionOwnershipStructuralRepairAttempts = 0U;
    diagnostics.surfaceCellCompletionOwnershipInsertedBoundaryVertices = 0U;
    diagnostics.surfaceCellCompletionOwnershipStructuralCandidateBudget = 0U;
    diagnostics.surfaceCellCompletionOwnershipStructuralCandidatesConsumed = 0U;
    diagnostics.surfaceCellCompletionOwnershipVisitedStateCount = 0U;
    diagnostics.surfaceCellCompletionOwnershipFullRecomputationPasses = 0U;
    diagnostics.surfaceCellCompletionOwnershipIncrementalRecomputationPasses = 0U;
    diagnostics.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes = 0U;
    diagnostics.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes = 0U;
    diagnostics.surfaceCellCompletionOwnershipLastCandidateHalfedge = -1;
    diagnostics.surfaceCellCompletionOwnershipLastAffectedPatches.clear();
    diagnostics.surfaceCellCompletionOwnershipStructuralExhaustionReason =
        "none";
  }
  if (!diagnostics.surfaceCellOptimizationIterationCountAvailable) {
    diagnostics.surfaceCellOptimizationIterationCount = 0U;
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void copy_surface_cell_stage_diagnostics(
    const directional::RemeshDiagnostics &source,
    directional::RemeshDiagnostics &target) {
  target.surfaceCellFeatureSeconds = source.surfaceCellFeatureSeconds;
  target.surfaceCellMetricSeconds = source.surfaceCellMetricSeconds;
  target.surfaceCellReliefSeconds = source.surfaceCellReliefSeconds;
  target.surfaceCellTracingSeconds = source.surfaceCellTracingSeconds;
  target.surfaceCellArrangementSeconds = source.surfaceCellArrangementSeconds;
  target.surfaceCellSimplificationSeconds =
      source.surfaceCellSimplificationSeconds;
  target.surfaceCellCompletionSeconds = source.surfaceCellCompletionSeconds;
  target.surfaceCellOptimizationSeconds = source.surfaceCellOptimizationSeconds;
  target.surfaceCellValidationSeconds = source.surfaceCellValidationSeconds;

  target.surfaceCellValidationFailures = source.surfaceCellValidationFailures;
  target.surfaceCellProvenanceVertexCount =
      source.surfaceCellProvenanceVertexCount;
  target.surfaceCellFeatureCount = source.surfaceCellFeatureCount;
  target.surfaceCellMetricSampleCount = source.surfaceCellMetricSampleCount;
  target.surfaceCellReliefPatchCount = source.surfaceCellReliefPatchCount;
  target.surfaceCellTraceSegmentCount = source.surfaceCellTraceSegmentCount;
  target.surfaceCellArrangementCellCount =
      source.surfaceCellArrangementCellCount;
  target.surfaceCellSimplifiedCellCount =
      source.surfaceCellSimplifiedCellCount;
  target.surfaceCellCompletedQuadCount = source.surfaceCellCompletedQuadCount;
  target.surfaceCellCompletionOwnershipRepairAttempts =
      source.surfaceCellCompletionOwnershipRepairAttempts;
  target.surfaceCellCompletionOwnershipStructuralRepairAttempts =
      source.surfaceCellCompletionOwnershipStructuralRepairAttempts;
  target.surfaceCellCompletionOwnershipInsertedBoundaryVertices =
      source.surfaceCellCompletionOwnershipInsertedBoundaryVertices;
  target.surfaceCellCompletionOwnershipStructuralCandidateBudget =
      source.surfaceCellCompletionOwnershipStructuralCandidateBudget;
  target.surfaceCellCompletionOwnershipStructuralCandidatesConsumed =
      source.surfaceCellCompletionOwnershipStructuralCandidatesConsumed;
  target.surfaceCellCompletionOwnershipVisitedStateCount =
      source.surfaceCellCompletionOwnershipVisitedStateCount;
  target.surfaceCellCompletionOwnershipFullRecomputationPasses =
      source.surfaceCellCompletionOwnershipFullRecomputationPasses;
  target.surfaceCellCompletionOwnershipIncrementalRecomputationPasses =
      source.surfaceCellCompletionOwnershipIncrementalRecomputationPasses;
  target.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes =
      source.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes;
  target.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes =
      source.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes;
  target.surfaceCellCompletionOwnershipLastCandidateHalfedge =
      source.surfaceCellCompletionOwnershipLastCandidateHalfedge;
  target.surfaceCellCompletionOwnershipLastAffectedPatches =
      source.surfaceCellCompletionOwnershipLastAffectedPatches;
  target.surfaceCellCompletionOwnershipStructuralExhaustionReason =
      source.surfaceCellCompletionOwnershipStructuralExhaustionReason;
  target.surfaceCellCompletionOwnershipRejectionAvailable =
      source.surfaceCellCompletionOwnershipRejectionAvailable;
  target.surfaceCellCompletionOwnershipFailure =
      source.surfaceCellCompletionOwnershipFailure;
  target.surfaceCellCompletionOwnershipSourcePatch =
      source.surfaceCellCompletionOwnershipSourcePatch;
  target.surfaceCellCompletionOwnershipLocalVertex =
      source.surfaceCellCompletionOwnershipLocalVertex;
  target.surfaceCellCompletionOwnershipBoundaryVertex =
      source.surfaceCellCompletionOwnershipBoundaryVertex;
  target.surfaceCellCompletionOwnershipBackend =
      source.surfaceCellCompletionOwnershipBackend;
  target.surfaceCellCompletionOwnershipVariant =
      source.surfaceCellCompletionOwnershipVariant;
  target.surfaceCellCompletionOwnershipStoredFace =
      source.surfaceCellCompletionOwnershipStoredFace;
  target.surfaceCellCompletionOwnershipBarycentric =
      source.surfaceCellCompletionOwnershipBarycentric;
  target.surfaceCellCompletionOwnershipEntityKind =
      source.surfaceCellCompletionOwnershipEntityKind;
  target.surfaceCellCompletionOwnershipSourceVertex =
      source.surfaceCellCompletionOwnershipSourceVertex;
  target.surfaceCellCompletionOwnershipSourceEdge =
      source.surfaceCellCompletionOwnershipSourceEdge;
  target.surfaceCellCompletionOwnershipCandidateFaces =
      source.surfaceCellCompletionOwnershipCandidateFaces;
  target.surfaceCellCompletionOwnershipPatchFaces =
      source.surfaceCellCompletionOwnershipPatchFaces;
  target.surfaceCellCompletionOwnershipComponent =
      source.surfaceCellCompletionOwnershipComponent;
  target.surfaceCellCompletionOwnershipSheet =
      source.surfaceCellCompletionOwnershipSheet;
  target.surfaceCellOptimizationIterationCount =
      source.surfaceCellOptimizationIterationCount;

  target.surfaceCellValidationFailureCountAvailable =
      source.surfaceCellValidationFailureCountAvailable;
  target.surfaceCellProvenanceVertexCountAvailable =
      source.surfaceCellProvenanceVertexCountAvailable;
  target.surfaceCellFeatureCountAvailable =
      source.surfaceCellFeatureCountAvailable;
  target.surfaceCellMetricSampleCountAvailable =
      source.surfaceCellMetricSampleCountAvailable;
  target.surfaceCellReliefCountAvailable =
      source.surfaceCellReliefCountAvailable;
  target.surfaceCellTraceCountAvailable = source.surfaceCellTraceCountAvailable;
  target.surfaceCellArrangementCountAvailable =
      source.surfaceCellArrangementCountAvailable;
  target.surfaceCellSimplifiedCountAvailable =
      source.surfaceCellSimplifiedCountAvailable;
  target.surfaceCellCompletedQuadCountAvailable =
      source.surfaceCellCompletedQuadCountAvailable;
  target.surfaceCellCompletionOwnershipRepairAttemptsAvailable =
      source.surfaceCellCompletionOwnershipRepairAttemptsAvailable;
  target.surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable =
      source.surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable;
  target.surfaceCellCompletionOwnershipStructuralLedgerAvailable =
      source.surfaceCellCompletionOwnershipStructuralLedgerAvailable;
  target.surfaceCellOptimizationIterationCountAvailable =
      source.surfaceCellOptimizationIterationCountAvailable;

  target.adaptiveFeatureMapSeconds = source.adaptiveFeatureMapSeconds;
  target.adaptiveFeatureHardEdgeCount = source.adaptiveFeatureHardEdgeCount;
  target.adaptiveFeatureSoftEdgeCount = source.adaptiveFeatureSoftEdgeCount;
  target.adaptiveFeatureBoundaryEdgeCount =
      source.adaptiveFeatureBoundaryEdgeCount;
  target.adaptiveFeatureNonManifoldEdgeCount =
      source.adaptiveFeatureNonManifoldEdgeCount;
  target.adaptiveFeatureCurveCount = source.adaptiveFeatureCurveCount;
  target.adaptiveFeatureClosedCurveCount =
      source.adaptiveFeatureClosedCurveCount;
  target.adaptiveFeatureMaxDensity = source.adaptiveFeatureMaxDensity;
  target.adaptiveTargetSizeSeconds = source.adaptiveTargetSizeSeconds;
  target.adaptiveTargetSizeResolvedSurfaceError =
      source.adaptiveTargetSizeResolvedSurfaceError;
  target.adaptiveTargetSizeMin = source.adaptiveTargetSizeMin;
  target.adaptiveTargetSizeMax = source.adaptiveTargetSizeMax;
  target.adaptiveTargetSizeFiniteVertexCount =
      source.adaptiveTargetSizeFiniteVertexCount;
  target.adaptiveTargetSizeNonFiniteVertexCount =
      source.adaptiveTargetSizeNonFiniteVertexCount;

  target.surfaceCellDebugArtifactsPreserved =
      source.surfaceCellDebugArtifactsPreserved;
  target.surfaceCellDebugArtifacts = source.surfaceCellDebugArtifacts;
  target.surfaceCellStageLineage = source.surfaceCellStageLineage;
  clear_unavailable_surface_cell_counts(target);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void orient_quads_to_source_normals(
    const Eigen::MatrixXd &outputVertices,
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const std::vector<geometry::SurfacePoint> &outputProvenance,
    Eigen::MatrixXi &quads,
    const std::vector<geometry::PureQuadFaceLineage> *quadLineage) {
  (void)outputProvenance;
  if (outputVertices.cols() != 3 || sourceVertices.cols() != 3 ||
      sourceFaces.cols() != 3 || quads.cols() != 4) {
    return;
  }
  const geometry::SurfaceProjectionBvh projection(sourceVertices, sourceFaces);
  for (int row = 0; row < quads.rows(); ++row) {
    Eigen::RowVector3d centroid = Eigen::RowVector3d::Zero();
    Eigen::RowVector3d sourceNormal = Eigen::RowVector3d::Zero();
    bool valid = true;
    for (int col = 0; col < 4; ++col) {
      const int vertex = quads(row, col);
      if (vertex < 0 || vertex >= outputVertices.rows()) {
        valid = false;
        break;
      }
      centroid += 0.25 * outputVertices.row(vertex);
    }
    if (!valid) {
      continue;
    }
    int authoritativeFace = -1;
    if (quadLineage != nullptr &&
        row < static_cast<int>(quadLineage->size())) {
      const geometry::PureQuadFaceLineage &lineage =
          (*quadLineage)[static_cast<std::size_t>(row)];
      if (lineage.valid() && lineage.sourcePatch >= 0 &&
          lineage.sourcePatch < sourceFaces.rows()) {
        authoritativeFace = lineage.sourcePatch;
      }
    }
    if (authoritativeFace >= 0) {
      const Eigen::RowVector3d sa =
          sourceVertices.row(sourceFaces(authoritativeFace, 0));
      const Eigen::RowVector3d sb =
          sourceVertices.row(sourceFaces(authoritativeFace, 1));
      const Eigen::RowVector3d sc =
          sourceVertices.row(sourceFaces(authoritativeFace, 2));
      sourceNormal = (sb - sa).cross(sc - sa);
    }
    if (!(sourceNormal.norm() > 0.0)) {
      const geometry::SurfacePoint source =
          projection.project(centroid.transpose());
      if (!source.valid() || source.face < 0 ||
          source.face >= sourceFaces.rows()) {
        continue;
      }
      const Eigen::RowVector3d sa =
          sourceVertices.row(sourceFaces(source.face, 0));
      const Eigen::RowVector3d sb =
          sourceVertices.row(sourceFaces(source.face, 1));
      const Eigen::RowVector3d sc =
          sourceVertices.row(sourceFaces(source.face, 2));
      sourceNormal = (sb - sa).cross(sc - sa);
    }
    const Eigen::RowVector3d a = outputVertices.row(quads(row, 0));
    const Eigen::RowVector3d b = outputVertices.row(quads(row, 1));
    const Eigen::RowVector3d c = outputVertices.row(quads(row, 2));
    const Eigen::RowVector3d quadNormal = (b - a).cross(c - a);
    if (quadNormal.norm() > 0.0 && sourceNormal.norm() > 0.0 &&
        quadNormal.dot(sourceNormal) < 0.0) {
      std::swap(quads(row, 1), quads(row, 3));
    }
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::vector<geometry::SurfaceArrangementArc>
surface_arrangement_arcs_from_flow_rep(
    const std::vector<geometry::FlowRepArc> &arcs,
    const geometry::FlowRepSparseNetwork &sparseNetwork) {
  std::set<int> retained(sparseNetwork.retainedArcIds.begin(),
                         sparseNetwork.retainedArcIds.end());
  if (retained.empty() && sparseNetwork.removedArcIds.empty()) {
    for (const geometry::FlowRepArc &arc : arcs) {
      retained.insert(arc.id);
    }
  }
  std::vector<geometry::SurfaceArrangementArc> arrangementArcs;
  arrangementArcs.reserve(retained.size());
  for (const geometry::FlowRepArc &arc : arcs) {
    if (retained.count(arc.id) == 0 || arc.sourceFace < 0) {
      continue;
    }
    geometry::SurfaceArrangementArc arrangementArc;
    arrangementArc.id = static_cast<int>(arrangementArcs.size());
    arrangementArc.sourceFace = arc.sourceFace;
    arrangementArc.startBarycentric = arc.startBarycentric;
    arrangementArc.endBarycentric = arc.endBarycentric;
    arrangementArc.family = arc.family;
    arrangementArc.strand = arc.strandProvenance;
    arrangementArc.featureClass = arc.featureClass;
    arrangementArc.hardFeature = arc.hardFeatureRail || arc.mandatoryRail;
    arrangementArc.provenance = arc.id;
    arrangementArc.railId = arc.railId;
    arrangementArc.curveId = arc.curveId;
    arrangementArc.sourceComponent = arc.sourceComponent;
    arrangementArc.sourceSheet = arc.sourceSheet;
    arrangementArc.proposalId = arc.proposalId;
    arrangementArc.proposalSeedId = arc.proposalSeedId;
    arrangementArc.proposalSide = arc.proposalSide;
    arrangementArc.proposalBoundarySegment = arc.proposalBoundarySegment;
    arrangementArc.railT0 = arc.railT0;
    arrangementArc.railT1 = arc.railT1;
    // Every non-authoritative FlowRep arc is optional layout support at the
    // arrangement layer. Proposal boundaries that participate in cycles are
    // retained; a proposal segment that is a graph bridge cannot bound a cell
    // and is eligible for the conservative topology-healing pass.
    arrangementArc.layoutSupport = !arc.mandatoryRail;
    arrangementArc.singularitySupport = arc.singularitySupport;
    arrangementArcs.push_back(arrangementArc);
  }
  return arrangementArcs;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::array<int, 4> ordered_source_quad_boundary(
    const TriMesh &mesh, const int firstFace, const int secondFace) {
  std::map<std::uint64_t, int> counts;
  std::map<std::uint64_t, std::pair<int, int>> endpoints;
  for (const int face : {firstFace, secondFace}) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = mesh.F(face, corner);
      const int b = mesh.F(face, (corner + 1) % 3);
      const std::uint64_t key = surface_cell_source_edge_key(a, b);
      ++counts[key];
      endpoints[key] = {a, b};
    }
  }

  std::map<int, std::vector<int>> adjacency;
  for (const auto &[key, count] : counts) {
    if (count != 1) {
      continue;
    }
    const auto [a, b] = endpoints.at(key);
    adjacency[a].push_back(b);
    adjacency[b].push_back(a);
  }
  if (adjacency.size() != 4U) {
    return {-1, -1, -1, -1};
  }
  for (auto &[vertex, neighbors] : adjacency) {
    (void)vertex;
    std::sort(neighbors.begin(), neighbors.end());
    if (neighbors.size() != 2U) {
      return {-1, -1, -1, -1};
    }
  }

  std::array<int, 4> order{-1, -1, -1, -1};
  order[0] = adjacency.begin()->first;
  order[1] = adjacency.at(order[0]).front();
  for (int index = 2; index < 4; ++index) {
    const auto &neighbors = adjacency.at(order[index - 1]);
    order[index] = neighbors[0] == order[index - 2] ? neighbors[1] : neighbors[0];
  }
  if (adjacency.at(order[3])[0] != order[0] &&
      adjacency.at(order[3])[1] != order[0]) {
    return {-1, -1, -1, -1};
  }

  Eigen::RowVector3d polygonNormal = Eigen::RowVector3d::Zero();
  for (int index = 0; index < 4; ++index) {
    const Eigen::RowVector3d current = mesh.V.row(order[index]);
    const Eigen::RowVector3d next = mesh.V.row(order[(index + 1) % 4]);
    polygonNormal += current.cross(next);
  }
  Eigen::RowVector3d sourceNormal =
      mesh.faceNormals.row(firstFace) + mesh.faceNormals.row(secondFace);
  if (polygonNormal.dot(sourceNormal) < 0.0) {
    std::swap(order[1], order[3]);
  }
  return order;
}

} // namespace directional::pipeline

namespace directional::pipeline {

int source_quad_edge_family(
    const TriMesh &mesh, const fields::CrossFieldResult &crossField,
    const int firstFace, const int secondFace, const int a, const int b,
    double &alignment) {
  int ownerFace = -1;
  for (const int face : {firstFace, secondFace}) {
    bool hasA = false;
    bool hasB = false;
    for (int corner = 0; corner < 3; ++corner) {
      hasA = hasA || mesh.F(face, corner) == a;
      hasB = hasB || mesh.F(face, corner) == b;
    }
    if (hasA && hasB) {
      ownerFace = face;
      break;
    }
  }
  if (ownerFace < 0) {
    alignment = 0.0;
    return -1;
  }

  Eigen::RowVector3d direction = mesh.V.row(b) - mesh.V.row(a);
  const double directionNorm = direction.norm();
  if (!(directionNorm > 1.0e-12)) {
    alignment = 0.0;
    return -1;
  }
  direction /= directionNorm;
  Eigen::RowVector3d primary = crossField.primaryDirections.row(ownerFace);
  Eigen::RowVector3d secondary = crossField.secondaryDirections.row(ownerFace);
  const double primaryNorm = primary.norm();
  const double secondaryNorm = secondary.norm();
  if (!(primaryNorm > 1.0e-12) || !(secondaryNorm > 1.0e-12)) {
    alignment = 0.0;
    return -1;
  }
  primary /= primaryNorm;
  secondary /= secondaryNorm;
  const double primaryAlignment = std::abs(direction.dot(primary));
  const double secondaryAlignment = std::abs(direction.dot(secondary));
  alignment = std::max(primaryAlignment, secondaryAlignment);
  return primaryAlignment >= secondaryAlignment ? 0 : 1;
}

} // namespace directional::pipeline

namespace directional::pipeline {

FieldAlignedSourceQuadRecoveryResult
recover_unique_field_aligned_source_quads(
    const TriMesh &mesh, const fields::CrossFieldResult &crossField,
    const std::vector<int> *sourceFaceComponents,
    const std::vector<int> *sourceFaceSheets,
    const std::set<std::uint64_t> *excludedDiagonalEdges) {
  FieldAlignedSourceQuadRecoveryResult result;
  if (mesh.F.cols() != 3 || mesh.F.rows() == 0 ||
      crossField.primaryDirections.rows() != mesh.F.rows() ||
      crossField.secondaryDirections.rows() != mesh.F.rows()) {
    result.failure = "InvalidSourceGridInput";
    return result;
  }

  struct Candidate {
    int firstFace = -1;
    int secondFace = -1;
    int diagonalEdge = -1;
    std::array<int, 4> boundary{-1, -1, -1, -1};
    double score = std::numeric_limits<double>::infinity();
  };
  std::vector<Candidate> candidates;
  std::vector<std::vector<int>> candidatesByFace(
      static_cast<std::size_t>(mesh.F.rows()));
  constexpr double kMinimumBoundaryAlignment = 0.80;
  constexpr double kMaximumDiagonalAlignment = 0.99;

  for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
    const int firstFace = mesh.EF(edge, 0);
    const int secondFace = mesh.EF(edge, 1);
    if (firstFace < 0 || secondFace < 0) {
      continue;
    }
    if (excludedDiagonalEdges != nullptr &&
        excludedDiagonalEdges->count(surface_cell_source_edge_key(
            mesh.EV(edge, 0), mesh.EV(edge, 1))) != 0U) {
      continue;
    }
    const std::array<int, 4> boundary =
        ordered_source_quad_boundary(mesh, firstFace, secondFace);
    if (boundary[0] < 0) {
      continue;
    }

    const int diagonalA = mesh.EV(edge, 0);
    const int diagonalB = mesh.EV(edge, 1);
    double diagonalAlignment = 0.0;
    const int diagonalFamily = source_quad_edge_family(
        mesh, crossField, firstFace, secondFace, diagonalA, diagonalB,
        diagonalAlignment);
    if (diagonalFamily < 0 || diagonalAlignment >= kMaximumDiagonalAlignment) {
      continue;
    }

    std::array<int, 4> families{-1, -1, -1, -1};
    bool aligned = true;
    double boundaryAlignmentPenalty = 0.0;
    for (int side = 0; side < 4; ++side) {
      double sideAlignment = 0.0;
      families[side] = source_quad_edge_family(
          mesh, crossField, firstFace, secondFace, boundary[side],
          boundary[(side + 1) % 4], sideAlignment);
      aligned = aligned && families[side] >= 0 &&
                sideAlignment >= kMinimumBoundaryAlignment;
      boundaryAlignmentPenalty += 1.0 - sideAlignment;
    }
    if (!aligned || families[0] == families[1] ||
        families[0] != families[2] || families[1] != families[3]) {
      continue;
    }

    const int candidateIndex = static_cast<int>(candidates.size());
    candidates.push_back(
        {firstFace, secondFace, edge, boundary,
         diagonalAlignment + 0.25 * boundaryAlignmentPenalty});
    candidatesByFace[static_cast<std::size_t>(firstFace)].push_back(
        candidateIndex);
    candidatesByFace[static_cast<std::size_t>(secondFace)].push_back(
        candidateIndex);
  }
  result.strictCandidatePairCount = candidates.size();
  result.candidatePairCount = candidates.size();

  bool strictGraphEligible = true;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    const std::size_t candidateCount =
        candidatesByFace[static_cast<std::size_t>(face)].size();
    if (candidateCount == 0U || candidateCount > 2U) {
      strictGraphEligible = false;
      break;
    }
  }

  struct MatchingSolution {
    double score = std::numeric_limits<double>::infinity();
    std::vector<int> candidateIndices;
  };
  std::vector<int> selectedCandidateIndices;
  std::vector<int> unmatchedFaces;
  std::vector<char> componentVisited(
      static_cast<std::size_t>(mesh.F.rows()), 0);
  std::vector<char> matched(static_cast<std::size_t>(mesh.F.rows()), 0);
  bool strictMatchingSucceeded = strictGraphEligible;

  for (int seedFace = 0;
       strictMatchingSucceeded && seedFace < mesh.F.rows(); ++seedFace) {
    if (componentVisited[static_cast<std::size_t>(seedFace)] != 0) {
      continue;
    }
    std::vector<int> componentFaces;
    std::vector<int> stack{seedFace};
    componentVisited[static_cast<std::size_t>(seedFace)] = 1;
    while (!stack.empty()) {
      const int face = stack.back();
      stack.pop_back();
      componentFaces.push_back(face);
      for (const int candidateIndex :
           candidatesByFace[static_cast<std::size_t>(face)]) {
        const Candidate &candidate =
            candidates[static_cast<std::size_t>(candidateIndex)];
        const int adjacentFace = candidate.firstFace == face
                                     ? candidate.secondFace
                                     : candidate.firstFace;
        if (componentVisited[static_cast<std::size_t>(adjacentFace)] == 0) {
          componentVisited[static_cast<std::size_t>(adjacentFace)] = 1;
          stack.push_back(adjacentFace);
        }
      }
    }
    std::sort(componentFaces.begin(), componentFaces.end());

    std::vector<MatchingSolution> solutions;
    std::vector<int> currentSelection;
    std::function<void(double)> searchMatching = [&](const double score) {
      if (solutions.size() > 2U) {
        return;
      }
      const auto unmatched = std::find_if(
          componentFaces.begin(), componentFaces.end(), [&](const int face) {
            return matched[static_cast<std::size_t>(face)] == 0;
          });
      if (unmatched == componentFaces.end()) {
        std::vector<int> orderedSelection = currentSelection;
        std::sort(orderedSelection.begin(), orderedSelection.end());
        solutions.push_back({score, std::move(orderedSelection)});
        return;
      }

      const int face = *unmatched;
      matched[static_cast<std::size_t>(face)] = 1;
      for (const int candidateIndex :
           candidatesByFace[static_cast<std::size_t>(face)]) {
        const Candidate &candidate =
            candidates[static_cast<std::size_t>(candidateIndex)];
        const int adjacentFace = candidate.firstFace == face
                                     ? candidate.secondFace
                                     : candidate.firstFace;
        if (matched[static_cast<std::size_t>(adjacentFace)] != 0) {
          continue;
        }
        matched[static_cast<std::size_t>(adjacentFace)] = 1;
        currentSelection.push_back(candidateIndex);
        searchMatching(score + candidate.score);
        currentSelection.pop_back();
        matched[static_cast<std::size_t>(adjacentFace)] = 0;
      }
      matched[static_cast<std::size_t>(face)] = 0;
    };
    searchMatching(0.0);

    if (solutions.empty()) {
      strictMatchingSucceeded = false;
      break;
    }
    std::sort(solutions.begin(), solutions.end(),
              [](const MatchingSolution &lhs, const MatchingSolution &rhs) {
                if (lhs.score != rhs.score) {
                  return lhs.score < rhs.score;
                }
                return lhs.candidateIndices < rhs.candidateIndices;
              });
    if (solutions.size() > 1U &&
        std::abs(solutions[0].score - solutions[1].score) <= 1.0e-10) {
      strictMatchingSucceeded = false;
      break;
    }
    selectedCandidateIndices.insert(selectedCandidateIndices.end(),
                                    solutions.front().candidateIndices.begin(),
                                    solutions.front().candidateIndices.end());
  }

  if (!strictMatchingSucceeded ||
      selectedCandidateIndices.size() * 2U !=
          static_cast<std::size_t>(mesh.F.rows())) {
    // The strict route intentionally recognizes only grid-like inputs.  An
    // arbitrary manifold triangulation normally gives every dual vertex three
    // legal neighbors and must not be rejected as "ambiguous".  Fall back to
    // deterministic general-graph matching and use cross-field/shape quality
    // as a soft preference rather than an eligibility threshold.
    result.usedGeneralMatching = true;
    candidates.clear();
    candidatesByFace.assign(static_cast<std::size_t>(mesh.F.rows()), {});
    selectedCandidateIndices.clear();

    std::vector<geometry::GeneralGraphMatchingEdge> matchingEdges;
    std::map<std::pair<int, int>, int> candidateByFacePair;
    constexpr double kIdealDiagonalAlignment =
        0.707106781186547524400844362104849039;
    for (int edge = 0; edge < mesh.EF.rows(); ++edge) {
      const int firstFace = mesh.EF(edge, 0);
      const int secondFace = mesh.EF(edge, 1);
      if (firstFace < 0 || secondFace < 0) {
        continue;
      }
      if (excludedDiagonalEdges != nullptr &&
          excludedDiagonalEdges->count(surface_cell_source_edge_key(
              mesh.EV(edge, 0), mesh.EV(edge, 1))) != 0U) {
        continue;
      }
      const std::array<int, 4> boundary =
          ordered_source_quad_boundary(mesh, firstFace, secondFace);
      if (boundary[0] < 0) {
        continue;
      }

      double diagonalAlignment = 0.0;
      const int diagonalFamily = source_quad_edge_family(
          mesh, crossField, firstFace, secondFace, mesh.EV(edge, 0),
          mesh.EV(edge, 1), diagonalAlignment);
      if (diagonalFamily < 0 || !std::isfinite(diagonalAlignment)) {
        continue;
      }

      std::array<int, 4> families{-1, -1, -1, -1};
      double boundaryAlignmentPenalty = 0.0;
      bool validDirections = true;
      std::array<double, 4> sideLengths{};
      for (int side = 0; side < 4; ++side) {
        double sideAlignment = 0.0;
        families[side] = source_quad_edge_family(
            mesh, crossField, firstFace, secondFace, boundary[side],
            boundary[(side + 1) % 4], sideAlignment);
        validDirections = validDirections && families[side] >= 0 &&
                          std::isfinite(sideAlignment);
        boundaryAlignmentPenalty += 1.0 - sideAlignment;
        sideLengths[side] =
            (mesh.V.row(boundary[side]) -
             mesh.V.row(boundary[(side + 1) % 4]))
                .norm();
      }
      if (!validDirections ||
          std::any_of(sideLengths.begin(), sideLengths.end(),
                      [](const double length) {
                        return !(length > 1.0e-12) || !std::isfinite(length);
                      })) {
        continue;
      }

      double familyPenalty = 0.0;
      familyPenalty += families[0] == families[1] ? 1.0 : 0.0;
      familyPenalty += families[1] == families[2] ? 1.0 : 0.0;
      familyPenalty += families[2] == families[3] ? 1.0 : 0.0;
      familyPenalty += families[3] == families[0] ? 1.0 : 0.0;
      familyPenalty += families[0] != families[2] ? 0.5 : 0.0;
      familyPenalty += families[1] != families[3] ? 0.5 : 0.0;
      const auto [minimumLength, maximumLength] =
          std::minmax_element(sideLengths.begin(), sideLengths.end());
      const double aspectPenalty =
          std::log(std::max(1.0, *maximumLength / *minimumLength));
      const double normalAlignment = std::clamp(
          mesh.faceNormals.row(firstFace).dot(
              mesh.faceNormals.row(secondFace)),
          -1.0, 1.0);
      const Eigen::RowVector3d pairNormal =
          mesh.faceNormals.row(firstFace) +
          mesh.faceNormals.row(secondFace);
      bool convexPair = pairNormal.norm() > 1.0e-12;
      for (int corner = 0; convexPair && corner < 4; ++corner) {
        const Eigen::RowVector3d point = mesh.V.row(boundary[corner]);
        const Eigen::RowVector3d next =
            mesh.V.row(boundary[(corner + 1) % 4]) - point;
        const Eigen::RowVector3d previous =
            mesh.V.row(boundary[(corner + 3) % 4]) - point;
        convexPair = next.cross(previous).dot(pairNormal) > 1.0e-14;
      }
      // A paired template spans the removed source diagonal. Concave pairs
      // invert at least one refined quad. Keeping the source-face bend below
      // 30 degrees bounds both per-quad warpage and the normal deviation from
      // either authoritative face; sharper pairs use the conforming
      // three-sided template below instead.
      constexpr double kMinimumPairNormalAlignment =
          0.866025403784438646763723170752936183;
      if (!convexPair || normalAlignment <= kMinimumPairNormalAlignment) {
        continue;
      }

      const auto pair_surface_sample =
          [&](const double u,
              const double v) -> std::pair<Eigen::RowVector3d, int> {
        const int c0 = boundary[0];
        const int c1 = boundary[1];
        const int c2 = boundary[2];
        const int c3 = boundary[3];
        const std::pair<int, int> diagonal =
            geometry::AdaptiveFeatureMap::canonical_edge(
                mesh.EV(edge, 0), mesh.EV(edge, 1));
        std::array<std::pair<int, double>, 3> weights{};
        if (diagonal ==
            geometry::AdaptiveFeatureMap::canonical_edge(c0, c2)) {
          if (v <= u) {
            weights = {{{c0, 1.0 - u}, {c1, u - v}, {c2, v}}};
          } else {
            weights = {{{c0, 1.0 - v}, {c2, u}, {c3, v - u}}};
          }
        } else if (u + v <= 1.0) {
          weights = {{{c0, 1.0 - u - v}, {c1, u}, {c3, v}}};
        } else {
          weights =
              {{{c1, 1.0 - v}, {c2, u + v - 1.0}, {c3, 1.0 - u}}};
        }

        for (const int sourceFace : {firstFace, secondFace}) {
          Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
          bool supported = true;
          for (const auto &[sourceVertex, weight] : weights) {
            if (weight <= 1.0e-12) {
              continue;
            }
            int sourceCorner = -1;
            for (int corner = 0; corner < 3; ++corner) {
              if (mesh.F(sourceFace, corner) == sourceVertex) {
                sourceCorner = corner;
                break;
              }
            }
            if (sourceCorner < 0) {
              supported = false;
              break;
            }
            barycentric(sourceCorner) += weight;
          }
          if (supported) {
            const Eigen::RowVector3d position =
                barycentric(0) *
                    mesh.V.row(mesh.F(sourceFace, 0)) +
                barycentric(1) *
                    mesh.V.row(mesh.F(sourceFace, 1)) +
                barycentric(2) *
                    mesh.V.row(mesh.F(sourceFace, 2));
            return {position, sourceFace};
          }
        }
        return {Eigen::RowVector3d::Zero(), -1};
      };
      bool refinedPairValid = true;
      for (int vCell = 0; refinedPairValid && vCell < 2; ++vCell) {
        for (int uCell = 0; refinedPairValid && uCell < 2; ++uCell) {
          Eigen::MatrixXd localVertices(4, 3);
          Eigen::MatrixXi localQuad(1, 4);
          localQuad.row(0) << 0, 1, 2, 3;
          const std::array<std::pair<double, double>, 4> parameters{{
              {0.5 * uCell, 0.5 * vCell},
              {0.5 * (uCell + 1), 0.5 * vCell},
              {0.5 * (uCell + 1), 0.5 * (vCell + 1)},
              {0.5 * uCell, 0.5 * (vCell + 1)},
          }};
          for (int corner = 0; corner < 4; ++corner) {
            const auto [position, sourceFace] = pair_surface_sample(
                parameters[static_cast<std::size_t>(corner)].first,
                parameters[static_cast<std::size_t>(corner)].second);
            if (sourceFace < 0) {
              refinedPairValid = false;
              break;
            }
            localVertices.row(corner) = position;
          }
          const auto [centerPosition, centerFace] = pair_surface_sample(
              0.25 + 0.5 * uCell, 0.25 + 0.5 * vCell);
          (void)centerPosition;
          if (!refinedPairValid || centerFace < 0) {
            refinedPairValid = false;
            break;
          }
          const geometry::SurfaceQuadQualityMetrics quality =
              geometry::evaluate_surface_quad_quality(
                  localVertices, localQuad, 0,
                  mesh.faceNormals.row(centerFace));
          refinedPairValid = quality.convex &&
                             quality.signedScaledJacobian > 0.0 &&
                             quality.warpageDegrees <= 30.0;
        }
      }
      if (!refinedPairValid) {
        continue;
      }
      const double score =
          boundaryAlignmentPenalty + 0.5 * familyPenalty +
          std::abs(diagonalAlignment - kIdealDiagonalAlignment) +
          0.1 * aspectPenalty + 0.1 * (1.0 - normalAlignment);
      if (!std::isfinite(score)) {
        continue;
      }

      const int candidateIndex = static_cast<int>(candidates.size());
      candidates.push_back(
          {firstFace, secondFace, edge, boundary, score});
      candidatesByFace[static_cast<std::size_t>(firstFace)].push_back(
          candidateIndex);
      candidatesByFace[static_cast<std::size_t>(secondFace)].push_back(
          candidateIndex);
      matchingEdges.push_back({firstFace, secondFace, score});
      candidateByFacePair[std::minmax(firstFace, secondFace)] =
          candidateIndex;
    }
    result.candidatePairCount = candidates.size();

    const geometry::GeneralGraphMatchingResult matching =
        geometry::maximum_cardinality_matching(
            static_cast<int>(mesh.F.rows()), matchingEdges);
    result.matchedPairCount =
        static_cast<std::size_t>(matching.matchedEdgeCount);
    result.unmatchedFaceCount =
        static_cast<std::size_t>(mesh.F.rows() -
                                 2 * matching.matchedEdgeCount);
    for (int face = 0; face < mesh.F.rows(); ++face) {
      const int mate = matching.mate[static_cast<std::size_t>(face)];
      if (mate < 0) {
        unmatchedFaces.push_back(face);
        continue;
      }
      if (face >= mate) {
        continue;
      }
      const auto found = candidateByFacePair.find({face, mate});
      if (found == candidateByFacePair.end()) {
        result.failure = "MissingGeneralSourceCellCandidate";
        return result;
      }
      selectedCandidateIndices.push_back(found->second);
    }
    result.triangleTemplateCount = unmatchedFaces.size();
  } else {
    result.matchedPairCount = selectedCandidateIndices.size();
    result.unmatchedFaceCount = 0U;
  }

  std::vector<Candidate> selected;
  selected.reserve(selectedCandidateIndices.size());
  for (const int candidateIndex : selectedCandidateIndices) {
    selected.push_back(candidates[static_cast<std::size_t>(candidateIndex)]);
  }
  std::sort(selected.begin(), selected.end(), [](const Candidate &lhs,
                                                  const Candidate &rhs) {
    return std::tie(lhs.firstFace, lhs.secondFace, lhs.diagonalEdge) <
           std::tie(rhs.firstFace, rhs.secondFace, rhs.diagonalEdge);
  });

  std::set<int> usedSourceVertices;
  std::map<std::uint64_t, int> subdivisionsBySourceEdge;
  constexpr int kBaseSourceGridSubdivisions = 2;
  constexpr int kMaximumSourceGridSubdivisions = 64;
  constexpr double kMaximumRecoveredQuadAspect = 3.0;
  for (const Candidate &candidate : selected) {
    usedSourceVertices.insert(candidate.boundary.begin(),
                              candidate.boundary.end());
    std::array<double, 4> sideLengths{};
    for (int side = 0; side < 4; ++side) {
      const int a = candidate.boundary[side];
      const int b = candidate.boundary[(side + 1) % 4];
      subdivisionsBySourceEdge[surface_cell_source_edge_key(a, b)] =
          kBaseSourceGridSubdivisions;
      sideLengths[side] = (mesh.V.row(a) - mesh.V.row(b)).norm();
    }
    if (result.usedGeneralMatching) {
      continue;
    }
    const double firstDirection =
        0.5 * (sideLengths[0] + sideLengths[2]);
    const double secondDirection =
        0.5 * (sideLengths[1] + sideLengths[3]);
    const double shorter = std::min(firstDirection, secondDirection);
    const double longer = std::max(firstDirection, secondDirection);
    if (!(shorter > 1.0e-12) || !std::isfinite(longer)) {
      result.failure = "DegenerateSourceGridCell";
      return result;
    }
    const double sourceNormalAlignment = std::clamp(
        mesh.faceNormals.row(candidate.firstFace).dot(
            mesh.faceNormals.row(candidate.secondFace)),
        -1.0, 1.0);
    constexpr double kCoplanarNormalTolerance = 1.0e-10;
    const bool nonCoplanar =
        sourceNormalAlignment < 1.0 - kCoplanarNormalTolerance;
    const bool anisotropic =
        !nonCoplanar &&
        longer > kMaximumRecoveredQuadAspect * shorter;
    const int shortSubdivisions =
        anisotropic ? 1 : kBaseSourceGridSubdivisions;
    const int requiredLongSubdivisions = std::max(
        kBaseSourceGridSubdivisions,
        static_cast<int>(std::ceil(
            shortSubdivisions * longer /
            (kMaximumRecoveredQuadAspect * shorter))));
    if (requiredLongSubdivisions > kMaximumSourceGridSubdivisions) {
      result.failure = "SourceGridRecoveryAspectSubdivisionLimitExceeded";
      return result;
    }
    const int longSide = firstDirection >= secondDirection ? 0 : 1;
    if (anisotropic) {
      for (const int side : {1 - longSide, 3 - longSide}) {
        const std::uint64_t key = surface_cell_source_edge_key(
            candidate.boundary[side], candidate.boundary[(side + 1) % 4]);
        subdivisionsBySourceEdge[key] = shortSubdivisions;
      }
    }
    for (const int side : {longSide, longSide + 2}) {
      const std::uint64_t key = surface_cell_source_edge_key(
          candidate.boundary[side], candidate.boundary[(side + 1) % 4]);
      subdivisionsBySourceEdge[key] =
          std::max(subdivisionsBySourceEdge[key], requiredLongSubdivisions);
    }
  }
  for (const int face : unmatchedFaces) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = mesh.F(face, corner);
      const int b = mesh.F(face, (corner + 1) % 3);
      usedSourceVertices.insert(a);
      usedSourceVertices.insert(b);
      subdivisionsBySourceEdge[surface_cell_source_edge_key(a, b)] =
          kBaseSourceGridSubdivisions;
    }
  }

  // Opposite source-cell edges must use the same subdivision count. Propagate
  // increases across neighboring cells until every shared grid line agrees.
  bool subdivisionChanged = true;
  while (subdivisionChanged) {
    subdivisionChanged = false;
    for (const Candidate &candidate : selected) {
      for (const int direction : {0, 1}) {
        const int opposite = direction + 2;
        const std::uint64_t firstKey = surface_cell_source_edge_key(
            candidate.boundary[direction],
            candidate.boundary[(direction + 1) % 4]);
        const std::uint64_t oppositeKey = surface_cell_source_edge_key(
            candidate.boundary[opposite],
            candidate.boundary[(opposite + 1) % 4]);
        const int agreed = std::max(subdivisionsBySourceEdge[firstKey],
                                    subdivisionsBySourceEdge[oppositeKey]);
        if (subdivisionsBySourceEdge[firstKey] != agreed ||
            subdivisionsBySourceEdge[oppositeKey] != agreed) {
          subdivisionsBySourceEdge[firstKey] = agreed;
          subdivisionsBySourceEdge[oppositeKey] = agreed;
          subdivisionChanged = true;
        }
      }
    }
  }

  result.mesh.sourcePatch = 0;
  result.mesh.backend = geometry::PureQuadCompletionBackend::SourceGridRecovery;
  std::vector<Eigen::RowVector3d> outputPositions;
  std::map<int, int> sourceToOutput;
  std::map<std::tuple<std::uint64_t, int, int>, int>
      outputBySourceEdgeSubdivision;

  auto surface_point_on_source_face = [&](const int sourceFace,
                                          const Eigen::Vector3d &barycentric) {
    geometry::SurfacePoint point;
    point.face = sourceFace;
    point.barycentric = barycentric;
    point.position =
        barycentric(0) * mesh.V.row(mesh.F(sourceFace, 0)).transpose() +
        barycentric(1) * mesh.V.row(mesh.F(sourceFace, 1)).transpose() +
        barycentric(2) * mesh.V.row(mesh.F(sourceFace, 2)).transpose();
    point.squaredDistance = 0.0;
    if (sourceFaceComponents != nullptr && sourceFace >= 0 &&
        sourceFace < static_cast<int>(sourceFaceComponents->size())) {
      point.component =
          (*sourceFaceComponents)[static_cast<std::size_t>(sourceFace)];
    }
    if (sourceFaceSheets != nullptr && sourceFace >= 0 &&
        sourceFace < static_cast<int>(sourceFaceSheets->size())) {
      point.sheet = (*sourceFaceSheets)[static_cast<std::size_t>(sourceFace)];
    }
    return point;
  };
  auto append_surface_vertex = [&](const geometry::SurfacePoint &point) {
    const int outputVertex = static_cast<int>(outputPositions.size());
    outputPositions.push_back(point.position.transpose());
    result.mesh.vertexProvenance.push_back(point);
    geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = outputVertex;
    lineage.kind = geometry::PureQuadVertexLineageKind::SourceTriangle;
    lineage.sourcePoint = point;
    result.mesh.vertexLineage.push_back(lineage);
    return outputVertex;
  };
  auto find_source_face_and_barycentric =
      [&](const int a, const int b, const double weightA,
          const double weightB, const int preferredFace = -1) {
        for (const int sourceFace : {preferredFace, -1}) {
          const int faceBegin = sourceFace >= 0 ? sourceFace : 0;
          const int faceEnd = sourceFace >= 0 ? sourceFace + 1 : mesh.F.rows();
          for (int face = faceBegin; face < faceEnd; ++face) {
            int cornerA = -1;
            int cornerB = -1;
            for (int corner = 0; corner < 3; ++corner) {
              if (mesh.F(face, corner) == a) {
                cornerA = corner;
              }
              if (mesh.F(face, corner) == b) {
                cornerB = corner;
              }
            }
            if (cornerA >= 0 && cornerB >= 0) {
              Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
              barycentric(cornerA) = weightA;
              barycentric(cornerB) = weightB;
              return std::pair<int, Eigen::Vector3d>{face, barycentric};
            }
          }
          if (sourceFace < 0) {
            break;
          }
        }
        return std::pair<int, Eigen::Vector3d>{-1,
                                               Eigen::Vector3d::Zero()};
      };

  const auto source_edge_vertex =
      [&](const int a, const int b, const int index, const int subdivisions,
          const int preferredFace) -> int {
    if (index == 0) {
      return sourceToOutput.at(a);
    }
    if (index == subdivisions) {
      return sourceToOutput.at(b);
    }
    const std::uint64_t edgeKey = surface_cell_source_edge_key(a, b);
    const int canonicalIndex = a <= b ? index : subdivisions - index;
    const auto subdivisionKey =
        std::make_tuple(edgeKey, subdivisions, canonicalIndex);
    const auto found = outputBySourceEdgeSubdivision.find(subdivisionKey);
    if (found != outputBySourceEdgeSubdivision.end()) {
      return found->second;
    }
    const double t =
        static_cast<double>(index) / static_cast<double>(subdivisions);
    const auto [sourceFace, barycentric] =
        find_source_face_and_barycentric(a, b, 1.0 - t, t, preferredFace);
    if (sourceFace < 0) {
      return -1;
    }
    const int outputVertex = append_surface_vertex(
        surface_point_on_source_face(sourceFace, barycentric));
    outputBySourceEdgeSubdivision[subdivisionKey] = outputVertex;
    return outputVertex;
  };

  const auto candidate_surface_point =
      [&](const Candidate &candidate, const double u,
          const double v) -> geometry::SurfacePoint {
    const int c0 = candidate.boundary[0];
    const int c1 = candidate.boundary[1];
    const int c2 = candidate.boundary[2];
    const int c3 = candidate.boundary[3];
    const std::pair<int, int> diagonal =
        geometry::AdaptiveFeatureMap::canonical_edge(
            mesh.EV(candidate.diagonalEdge, 0),
            mesh.EV(candidate.diagonalEdge, 1));
    std::array<std::pair<int, double>, 3> weights{};
    if (diagonal ==
        geometry::AdaptiveFeatureMap::canonical_edge(c0, c2)) {
      if (v <= u) {
        weights = {{{c0, 1.0 - u}, {c1, u - v}, {c2, v}}};
      } else {
        weights = {{{c0, 1.0 - v}, {c2, u}, {c3, v - u}}};
      }
    } else {
      if (u + v <= 1.0) {
        weights = {{{c0, 1.0 - u - v}, {c1, u}, {c3, v}}};
      } else {
        weights = {{{c1, 1.0 - v}, {c2, u + v - 1.0}, {c3, 1.0 - u}}};
      }
    }

    for (const int sourceFace :
         {candidate.firstFace, candidate.secondFace}) {
      Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
      bool supported = true;
      for (const auto &[sourceVertex, weight] : weights) {
        if (weight <= 1.0e-12) {
          continue;
        }
        int sourceCorner = -1;
        for (int corner = 0; corner < 3; ++corner) {
          if (mesh.F(sourceFace, corner) == sourceVertex) {
            sourceCorner = corner;
            break;
          }
        }
        if (sourceCorner < 0) {
          supported = false;
          break;
        }
        barycentric(sourceCorner) += weight;
      }
      if (supported) {
        return surface_point_on_source_face(sourceFace, barycentric);
      }
    }
    return {};
  };

  for (const int sourceVertex : usedSourceVertices) {
    int sourceFace = -1;
    int sourceCorner = -1;
    for (int face = 0; face < mesh.F.rows() && sourceFace < 0; ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        if (mesh.F(face, corner) == sourceVertex) {
          sourceFace = face;
          sourceCorner = corner;
          break;
        }
      }
    }
    if (sourceFace < 0) {
      result.failure = "MissingSourceVertexProvenance";
      return result;
    }
    Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
    barycentric(sourceCorner) = 1.0;
    sourceToOutput[sourceVertex] = append_surface_vertex(
        surface_point_on_source_face(sourceFace, barycentric));
  }

  for (const Candidate &candidate : selected) {
    const int uSubdivisions = subdivisionsBySourceEdge.at(
        surface_cell_source_edge_key(candidate.boundary[0],
                                     candidate.boundary[1]));
    const int vSubdivisions = subdivisionsBySourceEdge.at(
        surface_cell_source_edge_key(candidate.boundary[1],
                                     candidate.boundary[2]));
    std::vector<int> grid(static_cast<std::size_t>(
                              (uSubdivisions + 1) * (vSubdivisions + 1)),
                          -1);
    const auto grid_index = [&](const int u, const int v) {
      return static_cast<std::size_t>(v * (uSubdivisions + 1) + u);
    };
    for (int vIndex = 0; vIndex <= vSubdivisions; ++vIndex) {
      for (int uIndex = 0; uIndex <= uSubdivisions; ++uIndex) {
        int outputVertex = -1;
        if (vIndex == 0) {
          outputVertex = source_edge_vertex(
              candidate.boundary[0], candidate.boundary[1], uIndex,
              uSubdivisions, candidate.firstFace);
        } else if (uIndex == uSubdivisions) {
          outputVertex = source_edge_vertex(
              candidate.boundary[1], candidate.boundary[2], vIndex,
              vSubdivisions, candidate.firstFace);
        } else if (vIndex == vSubdivisions) {
          outputVertex = source_edge_vertex(
              candidate.boundary[3], candidate.boundary[2], uIndex,
              uSubdivisions, candidate.secondFace);
        } else if (uIndex == 0) {
          outputVertex = source_edge_vertex(
              candidate.boundary[0], candidate.boundary[3], vIndex,
              vSubdivisions, candidate.secondFace);
        } else {
          const double u = static_cast<double>(uIndex) /
                           static_cast<double>(uSubdivisions);
          const double v = static_cast<double>(vIndex) /
                           static_cast<double>(vSubdivisions);
          const geometry::SurfacePoint point =
              candidate_surface_point(candidate, u, v);
          if (!point.valid()) {
            result.failure = "MissingSourceGridInteriorProvenance";
            return result;
          }
          outputVertex = append_surface_vertex(point);
        }
        if (outputVertex < 0) {
          result.failure = "MissingSourceEdgeProvenance";
          return result;
        }
        grid[grid_index(uIndex, vIndex)] = outputVertex;
      }
    }

    int localQuad = 0;
    for (int vIndex = 0; vIndex < vSubdivisions; ++vIndex) {
      for (int uIndex = 0; uIndex < uSubdivisions; ++uIndex) {
        std::array<int, 4> quad{
            grid[grid_index(uIndex, vIndex)],
            grid[grid_index(uIndex + 1, vIndex)],
            grid[grid_index(uIndex + 1, vIndex + 1)],
            grid[grid_index(uIndex, vIndex + 1)]};
        const std::pair<int, int> sourceDiagonal =
            geometry::AdaptiveFeatureMap::canonical_edge(
                mesh.EV(candidate.diagonalEdge, 0),
                mesh.EV(candidate.diagonalEdge, 1));
        if (sourceDiagonal ==
            geometry::AdaptiveFeatureMap::canonical_edge(
                candidate.boundary[1], candidate.boundary[3])) {
          // The strict validator triangulates a quad through corners 0--2.
          // Rotate the cyclic order so that this implicit geometric diagonal
          // follows the authoritative c1--c3 source diagonal rather than
          // cutting a chord away from the input surface.
          quad = {quad[1], quad[2], quad[3], quad[0]};
        }
        const int outputQuad = static_cast<int>(result.mesh.quads.size());
        result.mesh.quads.emplace_back(quad.begin(), quad.end());
        const geometry::SurfacePoint centerPoint = candidate_surface_point(
            candidate,
            (static_cast<double>(uIndex) + 0.5) /
                static_cast<double>(uSubdivisions),
            (static_cast<double>(vIndex) + 0.5) /
                static_cast<double>(vSubdivisions));
        result.mesh.quadLineage.push_back(
            {outputQuad,
             centerPoint.valid() ? centerPoint.face : candidate.firstFace,
             geometry::PureQuadCompletionBackend::SourceGridRecovery,
             localQuad++});
      }
    }
  }

  // Standard conforming 3-sided patch template.  It is used only for source
  // triangles that cannot participate in a convex, bounded-warpage pair.  The
  // center has valence three (not an unbounded polygon fan), every generated
  // quad lies in one authoritative source triangle, and edge midpoints are
  // canonical so adjacent paired/unpaired patches stitch exactly.
  for (const int sourceFace : unmatchedFaces) {
    const int a = mesh.F(sourceFace, 0);
    const int b = mesh.F(sourceFace, 1);
    const int c = mesh.F(sourceFace, 2);
    const int midpointAB = source_edge_vertex(a, b, 1, 2, sourceFace);
    const int midpointBC = source_edge_vertex(b, c, 1, 2, sourceFace);
    const int midpointCA = source_edge_vertex(c, a, 1, 2, sourceFace);
    const auto outputA = sourceToOutput.find(a);
    const auto outputB = sourceToOutput.find(b);
    const auto outputC = sourceToOutput.find(c);
    if (midpointAB < 0 || midpointBC < 0 || midpointCA < 0 ||
        outputA == sourceToOutput.end() ||
        outputB == sourceToOutput.end() ||
        outputC == sourceToOutput.end()) {
      result.failure = "MissingTriangleTemplateBoundaryProvenance";
      return result;
    }
    const geometry::SurfacePoint centerPoint = surface_point_on_source_face(
        sourceFace, Eigen::Vector3d::Constant(1.0 / 3.0));
    const int center = append_surface_vertex(centerPoint);
    const std::array<std::array<int, 4>, 3> quads{{
        {outputA->second, midpointAB, center, midpointCA},
        {outputB->second, midpointBC, center, midpointAB},
        {outputC->second, midpointCA, center, midpointBC},
    }};
    for (int localQuad = 0; localQuad < 3; ++localQuad) {
      const int outputQuad = static_cast<int>(result.mesh.quads.size());
      result.mesh.quads.emplace_back(
          quads[static_cast<std::size_t>(localQuad)].begin(),
          quads[static_cast<std::size_t>(localQuad)].end());
      result.mesh.quadLineage.push_back(
          {outputQuad, sourceFace,
           geometry::PureQuadCompletionBackend::SourceGridRecovery,
           localQuad});
    }
  }

  result.mesh.vertices.resize(outputPositions.size());
  result.mesh.vertexPositions.resize(static_cast<int>(outputPositions.size()),
                                     3);
  for (int outputVertex = 0;
       outputVertex < static_cast<int>(outputPositions.size());
       ++outputVertex) {
    result.mesh.vertices[static_cast<std::size_t>(outputVertex)] =
        outputVertex;
    result.mesh.vertexPositions.row(outputVertex) =
        outputPositions[static_cast<std::size_t>(outputVertex)];
  }

  std::set<int> boundaryVertices;
  for (const std::vector<int> &sourceLoop : mesh.boundaryLoops) {
    std::vector<int> outputLoop;
    for (std::size_t index = 0; index < sourceLoop.size(); ++index) {
      const int sourceVertex = sourceLoop[index];
      const int nextSourceVertex =
          sourceLoop[(index + 1U) % sourceLoop.size()];
      const auto sourceFound = sourceToOutput.find(sourceVertex);
      if (sourceFound == sourceToOutput.end()) {
        continue;
      }
      const std::uint64_t edgeKey =
          surface_cell_source_edge_key(sourceVertex, nextSourceVertex);
      const auto subdivisions = subdivisionsBySourceEdge.find(edgeKey);
      if (subdivisions == subdivisionsBySourceEdge.end()) {
        outputLoop.push_back(sourceFound->second);
        boundaryVertices.insert(sourceFound->second);
        continue;
      }
      for (int subdivision = 0; subdivision < subdivisions->second;
           ++subdivision) {
        const int outputVertex = source_edge_vertex(
            sourceVertex, nextSourceVertex, subdivision, subdivisions->second,
            -1);
        if (outputVertex < 0) {
          result.failure = "MissingSourceBoundarySubdivisionProvenance";
          return result;
        }
        outputLoop.push_back(outputVertex);
        boundaryVertices.insert(outputVertex);
      }
    }
    if (!outputLoop.empty()) {
      result.mesh.boundaryLoops.push_back(std::move(outputLoop));
    }
  }
  result.mesh.boundaryVertices.assign(boundaryVertices.begin(),
                                      boundaryVertices.end());
  result.success = !result.mesh.quads.empty();
  if (!result.success) {
    result.failure = "EmptySourceGridRecovery";
  }
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

SourceGridRecoveryTargetSizeResult
make_source_grid_recovery_target_size(
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const Eigen::MatrixXd &outputVertices,
    const Eigen::MatrixXi &outputQuads,
    const std::vector<geometry::SurfacePoint> &outputProvenance,
    const double requestedTargetSize,
    const double maxRelaxationRatio) {
  SourceGridRecoveryTargetSizeResult result;
  if (sourceVertices.rows() == 0 || sourceVertices.cols() != 3 ||
      sourceFaces.cols() != 3 || outputVertices.cols() != 3 ||
      outputQuads.cols() != 4 || outputQuads.rows() == 0 ||
      outputProvenance.size() <
          static_cast<std::size_t>(outputVertices.rows()) ||
      !(requestedTargetSize > 0.0) ||
      !std::isfinite(requestedTargetSize) ||
      !(maxRelaxationRatio >= 1.0) ||
      !std::isfinite(maxRelaxationRatio)) {
    result.failure = "InvalidSourceGridRecoveryTargetInput";
    return result;
  }

  const int sourceVertexCount = static_cast<int>(sourceVertices.rows());
  Eigen::VectorXd minimumIncidentEdge = Eigen::VectorXd::Constant(
      sourceVertexCount, std::numeric_limits<double>::infinity());
  Eigen::VectorXd maximumIncidentEdge = Eigen::VectorXd::Zero(sourceVertexCount);
  std::set<std::pair<int, int>> visitedEdges;

  const auto accumulate_at_point = [&](const geometry::SurfacePoint &point,
                                       const double edgeLength) {
    if (!point.valid() || point.face < 0 || point.face >= sourceFaces.rows() ||
        !point.barycentric.allFinite()) {
      return false;
    }
    bool supported = false;
    for (int corner = 0; corner < 3; ++corner) {
      if (point.barycentric(corner) <= 1.0e-10) {
        continue;
      }
      const int sourceVertex = sourceFaces(point.face, corner);
      if (sourceVertex < 0 || sourceVertex >= sourceVertexCount) {
        return false;
      }
      minimumIncidentEdge(sourceVertex) =
          std::min(minimumIncidentEdge(sourceVertex), edgeLength);
      maximumIncidentEdge(sourceVertex) =
          std::max(maximumIncidentEdge(sourceVertex), edgeLength);
      supported = true;
    }
    return supported;
  };

  for (int face = 0; face < outputQuads.rows(); ++face) {
    for (int corner = 0; corner < 4; ++corner) {
      const int first = outputQuads(face, corner);
      const int second = outputQuads(face, (corner + 1) % 4);
      if (first < 0 || second < 0 || first >= outputVertices.rows() ||
          second >= outputVertices.rows() || first == second) {
        result.failure = "InvalidSourceGridRecoveryOutputEdge";
        return result;
      }
      const std::pair<int, int> edge =
          first < second ? std::pair<int, int>{first, second}
                         : std::pair<int, int>{second, first};
      if (!visitedEdges.insert(edge).second) {
        continue;
      }
      const double edgeLength =
          (outputVertices.row(first) - outputVertices.row(second)).norm();
      if (!(edgeLength > 1.0e-12) || !std::isfinite(edgeLength) ||
          !accumulate_at_point(
              outputProvenance[static_cast<std::size_t>(first)], edgeLength) ||
          !accumulate_at_point(
              outputProvenance[static_cast<std::size_t>(second)], edgeLength)) {
        result.failure = "InvalidSourceGridRecoveryOutputProvenance";
        return result;
      }
    }
  }

  // The final validator accepts edge-size ratios in [0.5, 2.0]. Keep a small
  // numerical margin so interpolation of source-vertex targets cannot land
  // exactly on a rejection threshold. This is a topology-feasibility
  // projection, not an unconditional validator bypass: requests requiring a
  // larger relaxation than the configured bound remain rejected.
  constexpr double kMinimumAcceptedSizeRatio = 0.55;
  constexpr double kMaximumAcceptedSizeRatio = 1.90;
  result.targetSize =
      Eigen::VectorXd::Constant(sourceVertexCount, requestedTargetSize);
  for (int sourceVertex = 0; sourceVertex < sourceVertexCount; ++sourceVertex) {
    if (!(maximumIncidentEdge(sourceVertex) > 0.0) ||
        !std::isfinite(minimumIncidentEdge(sourceVertex))) {
      continue;
    }
    const double minimumFeasible =
        maximumIncidentEdge(sourceVertex) / kMaximumAcceptedSizeRatio;
    const double maximumFeasible =
        minimumIncidentEdge(sourceVertex) / kMinimumAcceptedSizeRatio;
    if (!(minimumFeasible <= maximumFeasible) ||
        !(maximumFeasible > 0.0) || !std::isfinite(minimumFeasible) ||
        !std::isfinite(maximumFeasible)) {
      result.failure = "IncompatibleSourceGridRecoveryEdgeScales";
      return result;
    }
    const double effectiveTarget =
        std::clamp(requestedTargetSize, minimumFeasible, maximumFeasible);
    result.targetSize(sourceVertex) = effectiveTarget;
    const double relaxation = std::max(
        effectiveTarget / requestedTargetSize,
        requestedTargetSize / effectiveTarget);
    result.maxRelaxationRatio =
        std::max(result.maxRelaxationRatio, relaxation);
  }

  result.relaxed = result.maxRelaxationRatio > 1.0 + 1.0e-12;
  result.valid = result.targetSize.allFinite() &&
                 result.targetSize.minCoeff() > 0.0 &&
                 result.maxRelaxationRatio <= maxRelaxationRatio + 1.0e-12;
  if (!result.valid) {
    result.failure = "SourceGridRecoveryTargetRelaxationExceeded";
  }
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult
remesh_from_raw_cross_field_impl(const TriMesh &meshWhole,
                                 const Eigen::MatrixXd &rawCrossField,
                                 const RemeshOptions &options,
                                 const fields::CrossFieldResult *authoritativeCrossField) {
  using Clock = RemeshPipelineClock;
  const auto pipelineStart = Clock::now();
  auto phaseStart = pipelineStart;
  if (options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled) {
    RemeshResult result;
    const bool retainIntermediateGeometry =
        options.surfaceCells.retainIntermediateGeometry ||
        options.surfaceCells.injectFailureAfterStage >= 0;
    result.diagnostics.remeshBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.requestedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.executedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    result.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
    result.surfaceCellContext.sourceMesh = meshWhole;
    result.surfaceCellContext.hasSourceMesh = true;
    std::vector<std::string> completedSurfaceCellStages;
    auto update_overall_pipeline_time = [&]() {
      set_overall_pipeline_time(result, pipelineStart);
    };
    auto preserve_completed_debug_artifacts = [&]() {
      result.diagnostics.surfaceCellDebugArtifactsPreserved =
          options.surfaceCells.preserveDebugArtifacts;
      if (options.surfaceCells.preserveDebugArtifacts) {
        result.diagnostics.surfaceCellDebugArtifacts =
            completedSurfaceCellStages;
      } else {
        result.diagnostics.surfaceCellDebugArtifacts.clear();
      }
    };
    auto fail_surface_cells = [&](const SurfaceCellFailureCode code,
                                  const std::string &stage) {
      const std::string failureCode = surface_cell_failure_code_name(code);
      result.success = false;
      result.vertices.resize(0, 3);
      result.faces.resize(0, 0);
      result.degrees.resize(0);
      result.outputVertexProvenance.clear();
      result.outputVertexLineage.clear();
      result.outputQuadLineage.clear();

      result.diagnostics.remeshBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      result.diagnostics.requestedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      result.diagnostics.executedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      result.diagnostics.terminalFailureCode = failureCode;
      result.diagnostics.terminalFailureStage = stage;
      result.diagnostics.originalSurfaceCellFailureCode = failureCode;
      result.diagnostics.originalSurfaceCellFailureStage = stage;
      result.diagnostics.surfaceCellFallbackCause.clear();
      result.diagnostics.surfaceCellFallbackAttempted = false;
      result.diagnostics.surfaceCellUsedLegacyFallback = false;
      result.diagnostics.surfaceCellReturnedInputMeshFallback = false;
      result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
      result.diagnostics.surfaceCellRemeshOccurred = false;
      if (!result.diagnostics.surfaceCellStageLineage.empty()) {
        SurfaceCellStageLineage &lineage =
            result.diagnostics.surfaceCellStageLineage.back();
        if (lineage.stage == stage) {
          lineage.terminalFailureCode = failureCode;
          lineage.terminalFailureStage = stage;
          lineage.consumedByNextStage = false;
          lineage.consumptionKind = SurfaceCellConsumptionKind::None;
        }
      }
      clear_unavailable_surface_cell_counts(result.diagnostics);
      preserve_completed_debug_artifacts();
      update_overall_pipeline_time();

      if (options.surfaceCells.fallbackPolicy ==
          SurfaceCellFallbackPolicy::ReturnInputMesh) {
        result.success = true;
        result.vertices = meshWhole.V;
        result.faces = meshWhole.F;
        result.degrees =
            Eigen::VectorXi::Constant(meshWhole.F.rows(), meshWhole.F.cols());
        result.diagnostics.executedBackend = "InputMesh";
        result.diagnostics.remeshBackend =
            result.diagnostics.executedBackend;
        result.diagnostics.surfaceCellFallbackAttempted = true;
        result.diagnostics.surfaceCellFallbackCause = failureCode;
        result.diagnostics.surfaceCellReturnedInputMeshFallback = true;
        result.diagnostics.surfaceCellOutputOrigin =
            SurfaceCellOutputOrigin::InputMeshFallback;
        result.diagnostics.terminalFailureCode =
            surface_cell_failure_code_name(SurfaceCellFailureCode::None);
        result.diagnostics.terminalFailureStage.clear();
        result.diagnostics.surfaceCellRemeshOccurred = false;
        record_face_degree_histogram(result);
        update_overall_pipeline_time();
        return result;
      }


      return result;
    };
    if (authoritativeCrossField != nullptr) {
      result.surfaceCellContext.crossField = *authoritativeCrossField;
    } else {
      try {
        result.surfaceCellContext.crossField =
            finalize_surface_cell_raw_cross_field(meshWhole, rawCrossField);
      } catch (const std::invalid_argument &) {
        return fail_surface_cells(
            SurfaceCellFailureCode::InvalidFieldDimensions,
            "cross-field-validation");
      } catch (const std::runtime_error &) {
        return fail_surface_cells(SurfaceCellFailureCode::MissingMatching,
                                  "cross-field-validation");
      }
    }
    normalize_surface_cell_cross_field_directions(
        result.surfaceCellContext.crossField);
    result.surfaceCellContext.hasCrossField = true;
    result.surfaceCellContext.crossFieldHasMatching =
        result.surfaceCellContext.crossField.matchingComputed;
    result.surfaceCellContext.crossFieldHasSingularities =
        result.surfaceCellContext.crossField.singularitiesComputed;
    result.rawCrossField = result.surfaceCellContext.crossField.rawField;
    result.crossFieldMatching = result.surfaceCellContext.crossField.matching;
    result.crossFieldEffort = result.surfaceCellContext.crossField.effort;
    result.crossFieldSingularCycles =
        result.surfaceCellContext.crossField.singularCycles;
    result.crossFieldSingularIndices =
        result.surfaceCellContext.crossField.singularIndices;
    auto make_identity = [](const std::string &type,
                            const std::uint64_t hash,
                            const std::size_t count) {
      return make_surface_cell_identity(type, hash, count);
    };
    auto record_surface_cell_stage = [&](const std::string &stage,
                                         const SurfaceCellObjectIdentity &input,
                                         const SurfaceCellObjectIdentity &output,
                                         const bool available,
                                         const double durationSeconds) {
      SurfaceCellStageLineage lineage;
      lineage.stage = stage;
      lineage.inputObject = input;
      lineage.outputObject = output;
      lineage.inputObjectHash = surface_cell_identity_label(input);
      lineage.outputObjectHash = surface_cell_identity_label(output);
      lineage.objectCount = output.elementCount;
      lineage.available = available;
      lineage.noOp = input.structuralHash == output.structuralHash &&
                     input.type == output.type;
      lineage.durationSeconds = durationSeconds;
      result.diagnostics.surfaceCellStageLineage.push_back(lineage);
      record_surface_cell_context_product(result.surfaceCellContext, stage,
                                          output, available);
    };
    auto mark_stage_consumed = [&](const std::string &stage,
                                   const SurfaceCellObjectIdentity &identity,
                                   const SurfaceCellConsumptionKind kind) {
      for (SurfaceCellStageLineage &lineage :
           result.diagnostics.surfaceCellStageLineage) {
        if (lineage.stage != stage) {
          continue;
        }
        const bool identityMatches =
            lineage.outputObject.structuralHash == identity.structuralHash &&
            lineage.outputObject.type == identity.type;
        lineage.consumedByNextStage =
            identityMatches && kind != SurfaceCellConsumptionKind::None &&
            kind != SurfaceCellConsumptionKind::Discontinuous;
        lineage.consumptionKind = identityMatches
                                      ? kind
                                      : SurfaceCellConsumptionKind::Discontinuous;
        return;
      }
    };
    std::uint64_t sourceHash = structural_hash_seed("source");
    hash_matrix(sourceHash, meshWhole.V);
    hash_matrix(sourceHash, meshWhole.F);
    const SurfaceCellObjectIdentity sourceIdentity = make_identity(
        "source", sourceHash, static_cast<std::size_t>(meshWhole.F.rows()));
    record_surface_cell_context_product(result.surfaceCellContext, "source",
                                        sourceIdentity, true);
    std::uint64_t crossFieldHash = structural_hash_seed("cross-field");
    hash_matrix(crossFieldHash, result.surfaceCellContext.crossField.rawField);
    hash_vector(crossFieldHash, result.surfaceCellContext.crossField.matching);
    hash_vector(crossFieldHash, result.surfaceCellContext.crossField.effort);
    hash_combine_u64(
        crossFieldHash,
        result.surfaceCellContext.crossField.edgeTransitions.size());
    for (const fields::CrossFieldEdgeTransition &transition :
         result.surfaceCellContext.crossField.edgeTransitions) {
      hash_combine_i64(crossFieldHash, transition.sourceEdge);
      hash_combine_i64(crossFieldHash, transition.sourceVertex0);
      hash_combine_i64(crossFieldHash, transition.sourceVertex1);
      hash_combine_i64(crossFieldHash, transition.firstFace);
      hash_combine_i64(crossFieldHash, transition.secondFace);
      hash_combine_i64(crossFieldHash, transition.matching);
      hash_combine_double(crossFieldHash, transition.effort);
    }
    hash_vector(crossFieldHash,
                result.surfaceCellContext.crossField.singularCycles);
    hash_vector(crossFieldHash,
                result.surfaceCellContext.crossField.singularIndices);
    hash_vector(crossFieldHash, result.surfaceCellContext.crossField.confidence);
    hash_vector(crossFieldHash,
                result.surfaceCellContext.crossField.uncoveredFaces);
    hash_combine_i64(crossFieldHash,
                     result.surfaceCellContext.crossField.matchingComputed ? 1 : 0);
    hash_combine_i64(
        crossFieldHash,
        result.surfaceCellContext.crossField.singularitiesComputed ? 1 : 0);
    hash_combine_i64(crossFieldHash,
                     result.surfaceCellContext.crossField.confidenceComputed ? 1 : 0);
    hash_combine_i64(
        crossFieldHash,
        result.surfaceCellContext.crossField.uncoveredFacePolicyApplied ? 1 : 0);
    record_surface_cell_context_product(
        result.surfaceCellContext, "cross-field",
        make_identity("cross-field", crossFieldHash,
                      static_cast<std::size_t>(
                          result.surfaceCellContext.crossField.rawField.rows())),
        result.surfaceCellContext.hasCrossField);
    const SurfaceCellFailureCode crossFieldFailure =
        validate_surface_cell_cross_field(
            meshWhole, result.surfaceCellContext.crossField,
            options.surfaceCells);
    if (crossFieldFailure != SurfaceCellFailureCode::None) {
      return fail_surface_cells(crossFieldFailure, "cross-field-validation");
    }

    const auto featureStart = Clock::now();
    const geometry::AdaptiveFeatureMap featureMap =
        geometry::AdaptiveFeatureMapBuilder::build(
            meshWhole.V, meshWhole.F,
            options.featureAlign ? options.featureMap
                                 : options.surfaceCells.featureMap);
    result.diagnostics.surfaceCellFeatureSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - featureStart)
            .count() /
        1.0e6;
    result.diagnostics.adaptiveFeatureMapSeconds =
        result.diagnostics.surfaceCellFeatureSeconds;
    result.diagnostics.surfaceCellFeatureCount = featureMap.edges.size();
    result.diagnostics.surfaceCellFeatureCountAvailable = true;
    copy_adaptive_feature_map_diagnostics(result.diagnostics, featureMap);
    result.surfaceCellContext.featureMap = featureMap;
    result.surfaceCellContext.hasFeatureMap = true;
    const std::uint64_t featureHash = hash_feature_map(featureMap);
    const SurfaceCellObjectIdentity featureIdentity = make_identity(
        "feature", featureHash, featureMap.edges.size());
    record_surface_cell_stage("feature", sourceIdentity, featureIdentity, true,
                              result.diagnostics.surfaceCellFeatureSeconds);
    completedSurfaceCellStages.push_back("feature");
    const SurfaceCellRailBuildResult railBuild =
        build_authoritative_surface_cell_rails(meshWhole, featureMap);
    if (!railBuild.success) {
      return fail_surface_cells(SurfaceCellFailureCode::InvalidRailTopology,
                                "feature");
    }
    const std::vector<geometry::SurfaceCellRail> &authoritativeRails =
        railBuild.rails;
    const std::set<std::uint64_t> hardFeatureRailEdges =
        hard_feature_edge_keys_from_rails(authoritativeRails);
    result.surfaceCellContext.authoritativeRails = authoritativeRails;
    result.surfaceCellContext.hasAuthoritativeRails = true;
    const SurfaceCellObjectIdentity railsIdentity = make_identity(
        "rails", hash_surface_cell_rails(authoritativeRails),
        authoritativeRails.size());
    record_surface_cell_context_product(result.surfaceCellContext, "rails",
                                        railsIdentity, true);
    if (options.surfaceCells.injectFailureAfterStage == 0) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "feature");
    }
    const auto targetSizeStart = Clock::now();
    geometry::AdaptiveTargetSizeOptions targetSizeOptions =
        options.surfaceCells.targetSize;
    const geometry::AdaptiveTargetSizeOptions defaultTargetSizeOptions;
    if (targetSizeOptions.baseSize == defaultTargetSizeOptions.baseSize) {
      const double derivedBaseSize =
          derive_absolute_target_length(meshWhole.V, options);
      if (derivedBaseSize > 0.0 && std::isfinite(derivedBaseSize)) {
        targetSizeOptions.baseSize = derivedBaseSize;
      }
    }
    const geometry::AdaptiveTargetSizeResult targetSize =
        geometry::compute_adaptive_target_size(
            meshWhole.V, meshWhole.F, featureMap, targetSizeOptions,
            options.surfaceCells.thickness);
    result.diagnostics.adaptiveTargetSizeSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - targetSizeStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellMetricSeconds =
        result.diagnostics.adaptiveTargetSizeSeconds;
    result.diagnostics.surfaceCellMetricSampleCount =
        static_cast<std::size_t>(targetSize.targetSize.size());
    result.diagnostics.surfaceCellMetricSampleCountAvailable = true;
    copy_adaptive_target_size_diagnostics(result.diagnostics, targetSize);
    result.surfaceCellContext.metricField = targetSize;
    result.surfaceCellContext.hasMetricField = true;
    std::uint64_t metricHash = structural_hash_seed("metric");
    hash_combine_u64(metricHash, featureIdentity.structuralHash);
    hash_vector(metricHash, targetSize.targetSize);
    hash_vector(metricHash, targetSize.normalizedSalience);
    const SurfaceCellObjectIdentity metricIdentity = make_identity(
        "metric", metricHash, result.diagnostics.surfaceCellMetricSampleCount);
    mark_stage_consumed("feature", featureIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("metric", featureIdentity, metricIdentity, true,
                              result.diagnostics.surfaceCellMetricSeconds);
    completedSurfaceCellStages.push_back("metric");

    if (options.surfaceCells.injectFailureAfterStage == 1) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "metric");
    }

    const auto reliefStart = Clock::now();
    geometry::ReliefInput reliefInput;
    reliefInput.salience = targetSize.normalizedSalience;
    reliefInput.curvature = targetSize.curvature;
    reliefInput.density = targetSize.normalizedFeatureDensity;
    reliefInput.thickness = targetSize.thickness;
    reliefInput.patchEnergy = Eigen::VectorXd::Zero(meshWhole.V.rows());
    const geometry::ReliefOptions reliefOptions = options.surfaceCells.relief;
    const Eigen::VectorXd reliefValues =
        geometry::compute_salience_relief(reliefInput, reliefOptions);
    const geometry::ReliefTopologyResult reliefTopology =
        geometry::analyze_relief_topology(meshWhole.V, meshWhole.F, reliefValues,
                                          hardFeatureRailEdges, reliefOptions);
    const std::set<std::uint64_t> reliefBarrierEdges =
        relief_barrier_edges_from_topology(reliefTopology);
    std::set<std::uint64_t> operationalBarrierEdges = hardFeatureRailEdges;
    operationalBarrierEdges.insert(reliefBarrierEdges.begin(),
                                   reliefBarrierEdges.end());
    geometry::ReliefRootSelectionOptions reliefRootOptions =
        options.surfaceCells.reliefRoots;
    reliefRootOptions.hardBarrierEdges = operationalBarrierEdges;
    const geometry::ReliefRootSelectionResult reliefRootSelection =
        geometry::select_relief_roots(meshWhole.V, meshWhole.F, reliefTopology,
                                      targetSize.targetSize, reliefRootOptions);
    result.diagnostics.surfaceCellReliefSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - reliefStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellReliefPatchCount =
        reliefTopology.branches.size();
    result.diagnostics.surfaceCellReliefCountAvailable = true;
    result.surfaceCellContext.reliefResult = reliefTopology;
    result.surfaceCellContext.hasReliefResult = true;
    result.surfaceCellContext.reliefRootSelection = reliefRootSelection;
    result.surfaceCellContext.hasReliefRootSelection = true;
    result.surfaceCellContext.reliefBarrierEdges = reliefBarrierEdges;
    result.surfaceCellContext.hasReliefBarrierEdges = true;
    const std::uint64_t reliefHash = hash_relief_topology(reliefTopology);
    const SurfaceCellObjectIdentity reliefIdentity = make_identity(
        "relief", reliefHash, result.diagnostics.surfaceCellReliefPatchCount);
    mark_stage_consumed("metric", metricIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("relief", metricIdentity, reliefIdentity, true,
                              result.diagnostics.surfaceCellReliefSeconds);
    const SurfaceCellObjectIdentity reliefConsumptionIdentity = make_identity(
        "relief-consumption",
        hash_relief_operational_inputs(reliefRootSelection, reliefBarrierEdges),
        reliefRootSelection.roots.size() + reliefBarrierEdges.size());
    record_surface_cell_context_product(result.surfaceCellContext,
                                        "relief-consumption",
                                        reliefConsumptionIdentity, true);
    completedSurfaceCellStages.push_back("relief");
    if (options.surfaceCells.injectFailureAfterStage == 2) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "relief");
    }

    const auto tracingStart = Clock::now();
    const Eigen::MatrixXd &faceAxisX =
        result.surfaceCellContext.crossField.primaryDirections;
    const Eigen::MatrixXd &faceAxisY =
        result.surfaceCellContext.crossField.secondaryDirections;
    geometry::SurfaceCellTracingOptions tracingOptions;
    tracingOptions.authoritativeRails = authoritativeRails;
    tracingOptions.hardFeatureEdges = hardFeatureRailEdges;
    tracingOptions.reliefRootVertices = reliefRootSelection.roots;
    tracingOptions.reliefRegionLabels = reliefRootSelection.labels;
    tracingOptions.reliefBarrierEdges = reliefBarrierEdges;
    tracingOptions.reliefBarriersEmbedded = false;
    tracingOptions.singularityVertices.reserve(
        static_cast<std::size_t>(
            result.surfaceCellContext.crossField.singularCycles.size()));
    tracingOptions.singularityIndexNumerators.reserve(
        static_cast<std::size_t>(
            result.surfaceCellContext.crossField.singularIndices.size()));
    for (Eigen::Index singularity = 0;
         singularity <
         result.surfaceCellContext.crossField.singularCycles.size();
         ++singularity) {
      tracingOptions.singularityVertices.push_back(
          result.surfaceCellContext.crossField.singularCycles[singularity]);
      tracingOptions.singularityIndexNumerators.push_back(
          result.surfaceCellContext.crossField.singularIndices[singularity]);
    }
    if (!geometry::surface_cell_tracing_detail::
            source_surface_classifier_options_valid(
                options.surfaceCells.sourceClassifier)) {
      return fail_surface_cells(
          SurfaceCellFailureCode::InvalidClassifierOptions,
          "source-classification");
    }
    const geometry::SourceSurfaceLabels sourceSurfaceLabels =
        geometry::surface_cell_tracing_detail::classify_source_surface_labels(
            meshWhole.V, meshWhole.F, hardFeatureRailEdges,
            options.surfaceCells.sourceClassifier);
    result.surfaceCellContext.sourceSurfaceLabels = sourceSurfaceLabels;
    result.surfaceCellContext.hasSourceSurfaceLabels = true;
    std::uint64_t sourceLabelHash = structural_hash_seed("source-labels");
    hash_combine_i64(
        sourceLabelHash,
        options.surfaceCells.sourceClassifier.traverseUnmarkedSharpBends ? 1
                                                                         : 0);
    hash_combine_double(
        sourceLabelHash,
        options.surfaceCells.sourceClassifier.normalCompatibility);
    hash_combine_double(
        sourceLabelHash,
        options.surfaceCells.sourceClassifier.closeSheetRadiusMeanEdges);
    hash_combine_i64(
        sourceLabelHash,
        options.surfaceCells.sourceClassifier.geodesicExclusionDepth);
    hash_vector(sourceLabelHash, sourceSurfaceLabels.componentByFace);
    hash_vector(sourceLabelHash, sourceSurfaceLabels.localSheetByFace);
    record_surface_cell_context_product(
        result.surfaceCellContext, "source-labels",
        make_identity("source-labels", sourceLabelHash,
                      sourceSurfaceLabels.localSheetByFace.size()),
        true);
    tracingOptions.sourceFaceComponents = sourceSurfaceLabels.componentByFace;
    tracingOptions.sourceFaceSheets = sourceSurfaceLabels.localSheetByFace;
    if (targetSize.targetSize.size() > 0) {
      tracingOptions.defaultTargetSize = targetSize.targetSize.mean();
    }
    for (const geometry::ReliefCriticalPoint &point :
         reliefTopology.criticalPoints) {
      if (point.retained && point.vertex >= 0) {
        tracingOptions.reliefCriticalVertices.push_back(point.vertex);
      }
    }
    geometry::SurfaceCellNetwork traceNetwork =
        geometry::build_surface_cell_network(
            meshWhole.V, meshWhole.F, result.surfaceCellContext.crossField,
            targetSize.targetSize, tracingOptions);
    std::size_t traceSegmentCount = 0U;
    for (const geometry::SurfaceTraceResult &trace : traceNetwork.traces) {
      traceSegmentCount += trace.segments.size();
    }
    for (const geometry::SurfaceSingularitySeparatrix &separatrix :
         traceNetwork.singularSeparatrices) {
      traceSegmentCount += separatrix.trace.segments.size();
    }
    for (const geometry::SurfaceCellProposal &proposal :
         traceNetwork.proposals) {
      traceSegmentCount += proposal.sides.size();
    }
    result.diagnostics.surfaceCellTracingSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - tracingStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellTraceSegmentCount = traceSegmentCount;
    result.diagnostics.surfaceCellTraceCountAvailable = true;
    const std::uint64_t tracingHash = hash_trace_network(traceNetwork);
    result.surfaceCellContext.traceNetwork = std::move(traceNetwork);
    result.surfaceCellContext.hasTraceNetwork = true;
    const geometry::SurfaceCellNetwork &retainedTraceNetwork =
        result.surfaceCellContext.traceNetwork;
    const SurfaceCellObjectIdentity tracingIdentity = make_identity(
        "tracing", tracingHash, result.diagnostics.surfaceCellTraceSegmentCount);
    mark_stage_consumed("relief", reliefIdentity,
                        SurfaceCellConsumptionKind::Partial);
    record_surface_cell_stage("tracing", reliefIdentity, tracingIdentity, true,
                              result.diagnostics.surfaceCellTracingSeconds);
    completedSurfaceCellStages.push_back("tracing");
    if (options.surfaceCells.injectFailureAfterStage == 3) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "tracing");
    }

    const auto strandsStart = Clock::now();
    geometry::FlowRepSelectionInput flowRepInput =
        geometry::build_flow_rep_selection_input(
            meshWhole.V, meshWhole.F, targetSize.targetSize,
            retainedTraceNetwork, tracingOptions.defaultTargetSize);
    if (!retainIntermediateGeometry) {
      // Source labels already live in sourceSurfaceLabels. Do not retain a
      // second copy merely to keep a consumed trace-stage shell alive.
      result.surfaceCellContext.traceNetwork = geometry::SurfaceCellNetwork{};
      result.surfaceCellContext.hasTraceNetwork = false;
    }
    geometry::FlowRepSparseNetwork sparseFlowRep =
        geometry::select_sparse_flow_rep_network(
            flowRepInput.arcs, flowRepInput.coverageSamples,
            flowRepInput.cycles);
    // Selection no longer needs ownership of the dense arc vector. Transfer it
    // into endpoint completion instead of retaining two full copies of the
    // expanded trace graph.
    std::vector<geometry::FlowRepArc> flowRepArcs =
        std::move(flowRepInput.arcs);
    geometry::FlowRepEndpointCompletionResult endpointCompletion;
    if (sparseFlowRep.selectionSucceeded) {
      geometry::FlowRepEndpointCompletionOptions endpointOptions;
      // Extension is the first endpoint-resolution action. Unresolved tips
      // remain explicit patch-completion evidence until the guarded removal
      // and transition actions are implemented; they are never accepted by
      // the final complex/completion validators.
      endpointOptions.requireAllEndpointsResolved = false;
      endpointCompletion = geometry::complete_flow_rep_endpoints(
          meshWhole.V, meshWhole.F, result.surfaceCellContext.crossField,
          tracingOptions, std::move(flowRepArcs),
          std::move(sparseFlowRep.retainedArcIds), endpointOptions);
      result.surfaceCellContext.flowRepEndpointCompletionAttempted = true;
      result.surfaceCellContext.flowRepOpenEndpointsBeforeCompletion =
          endpointCompletion.openEndpointsBefore;
      result.surfaceCellContext.flowRepResolvedEndpoints =
          endpointCompletion.resolvedEndpoints;
      result.surfaceCellContext.flowRepUnresolvedEndpoints =
          endpointCompletion.unresolvedEndpoints;
      result.surfaceCellContext.flowRepUnresolvedRequiredEndpoints =
          endpointCompletion.unresolvedRequiredEndpoints;
      result.surfaceCellContext.flowRepEndpointCompletionAddedArcs =
          endpointCompletion.addedArcs;
      result.surfaceCellContext.flowRepEndpointTerminationCounts =
          endpointCompletion.traceTerminationCounts;
      if (retainIntermediateGeometry) {
        result.surfaceCellContext.flowRepEndpointDiagnostics =
            std::move(endpointCompletion.diagnostics);
      }
      result.surfaceCellContext.flowRepEndpointCompletionFailure =
          std::move(endpointCompletion.failure);
      // Endpoint completion owns the only dense arc vector. Recover it for the
      // embedding stage on both success and fail-closed outcomes.
      flowRepArcs = std::move(endpointCompletion.arcs);
      sparseFlowRep.retainedArcIds =
          std::move(endpointCompletion.retainedArcIds);
      if (endpointCompletion.success) {
        sparseFlowRep.endpointTags =
            std::move(endpointCompletion.endpointTags);
      }
    }
    const double surfaceCellStrandsSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - strandsStart)
            .count() /
        1.0e6;
    if (retainIntermediateGeometry) {
      result.surfaceCellContext.flowRepArcs = flowRepArcs;
      result.surfaceCellContext.flowRepNetwork = sparseFlowRep;
      result.surfaceCellContext.hasFlowRepNetwork = true;
    }
    std::uint64_t strandsHash = hash_sparse_network(sparseFlowRep);
    hash_combine_u64(
        strandsHash,
        hash_flow_rep_selection_input_components(
            flowRepArcs, flowRepInput.coverageSamples, flowRepInput.cycles));
    // Coverage/cycle evidence has now been consumed by selection and hashing.
    // Release it before arrangement and completion allocate their graphs.
    flowRepInput = geometry::FlowRepSelectionInput{};
    const SurfaceCellObjectIdentity strandsIdentity = make_identity(
        "strands", strandsHash, sparseFlowRep.retainedArcIds.size());
    mark_stage_consumed("tracing", tracingIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("strands", tracingIdentity, strandsIdentity,
                              sparseFlowRep.selectionSucceeded,
                              surfaceCellStrandsSeconds);
    if (!sparseFlowRep.selectionSucceeded) {
      return fail_surface_cells(
          surface_cell_failure_from_flow_rep(sparseFlowRep.failureCode),
          "strands");
    }
    completedSurfaceCellStages.push_back("strands");
    if (options.surfaceCells.injectFailureAfterStage == 4) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "strands");
    }

    const auto embeddingStart = Clock::now();
    std::vector<geometry::SurfaceArrangementArc> arrangementArcs =
        surface_arrangement_arcs_from_flow_rep(flowRepArcs, sparseFlowRep);
    if (!retainIntermediateGeometry) {
      // Arrangement arcs are a compact projection of the retained FlowRep.
      // Release the much larger dense arc graph before building the DCEL.
      std::vector<geometry::FlowRepArc>().swap(flowRepArcs);
      sparseFlowRep = geometry::FlowRepSparseNetwork{};
      endpointCompletion = geometry::FlowRepEndpointCompletionResult{};
    }
    const double surfaceCellEmbeddingSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - embeddingStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount = arrangementArcs.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    if (retainIntermediateGeometry) {
      result.surfaceCellContext.embeddedArrangementArcs = arrangementArcs;
      result.surfaceCellContext.hasEmbeddedArrangementArcs = true;
    }
    const SurfaceCellObjectIdentity retainedNetworkIdentity = make_identity(
        "embedded-network", hash_arrangement_arcs(arrangementArcs),
        arrangementArcs.size());
    mark_stage_consumed("strands", strandsIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("embedding", strandsIdentity,
                              retainedNetworkIdentity, true,
                              surfaceCellEmbeddingSeconds);
    completedSurfaceCellStages.push_back("embedding");
    if (options.surfaceCells.injectFailureAfterStage == 5) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "embedding");
    }

    const auto arrangementStart = Clock::now();
    geometry::SurfaceArrangementOptions arrangementOptions;
    arrangementOptions.insertBoundaryRails = authoritativeRails.empty();
    arrangementOptions.hardFeatureEdges = hardFeatureRailEdges;
    arrangementOptions.sourceFaceComponents =
        &result.surfaceCellContext.sourceSurfaceLabels.componentByFace;
    arrangementOptions.sourceFaceSheets =
        &result.surfaceCellContext.sourceSurfaceLabels.localSheetByFace;
    geometry::SurfaceCellComplex arrangementComplex =
        geometry::build_surface_cell_complex(meshWhole.V, meshWhole.F,
                                             arrangementArcs, arrangementOptions);
    if (!retainIntermediateGeometry) {
      std::vector<geometry::SurfaceArrangementArc>().swap(arrangementArcs);
    }
    result.diagnostics.surfaceCellArrangementSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - arrangementStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount =
        arrangementComplex.cells.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    const std::uint64_t arrangementHash = hash_surface_complex(arrangementComplex);
    const SurfaceCellObjectIdentity arrangementIdentity = make_identity(
        "arrangement", arrangementHash,
        result.diagnostics.surfaceCellArrangementCellCount);
    mark_stage_consumed("embedding", retainedNetworkIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("arrangement", retainedNetworkIdentity,
                              arrangementIdentity, true,
                              result.diagnostics.surfaceCellArrangementSeconds);
    completedSurfaceCellStages.push_back("arrangement");
    if (options.surfaceCells.injectFailureAfterStage == 6) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "arrangement");
    }

    const auto simplificationStart = Clock::now();
    geometry::SurfaceSimplificationCandidateSet simplificationCandidates =
        geometry::extract_surface_simplification_candidates(
            arrangementComplex, meshWhole.V, meshWhole.F);
    geometry::SurfaceSimplificationOptions simplificationOptions;
    // The production path currently enables only the independently validated
    // topological repair: trim optional layout-support graph bridges that
    // pinch DCEL face walks. General FlowRep removals remain available to the
    // experimental API but require separate fidelity gates before integration.
    simplificationOptions.topologyHealingOnly = true;
    simplificationOptions.retainTransactionDetails = retainIntermediateGeometry;
    const int simplificationCandidateCount =
        static_cast<int>(simplificationCandidates.candidates.size());
    const int simplificationTopologyHealingCandidateCount =
        static_cast<int>(std::count_if(
            simplificationCandidates.candidates.begin(),
            simplificationCandidates.candidates.end(),
            [](const geometry::SurfaceSimplificationCandidate &candidate) {
              return candidate.topologyHealing;
            }));
    geometry::SurfaceSimplificationResult simplified;
    if (retainIntermediateGeometry) {
      simplified = geometry::simplify_surface_cell_complex(
          arrangementComplex, meshWhole.V, meshWhole.F,
          simplificationCandidates.candidates, simplificationOptions);
    } else {
      simplified = geometry::simplify_surface_cell_complex(
          std::move(arrangementComplex), meshWhole.V, meshWhole.F,
          std::move(simplificationCandidates.candidates),
          simplificationOptions);
    }
    result.surfaceCellContext.simplificationCandidateCount =
        simplificationCandidateCount;
    result.surfaceCellContext.simplificationTopologyHealingCandidateCount =
        simplificationTopologyHealingCandidateCount;
    if (retainIntermediateGeometry) {
      result.surfaceCellContext.simplificationTopologyHealingCandidates.clear();
      for (const geometry::SurfaceSimplificationCandidate &candidate :
           simplificationCandidates.candidates) {
        if (candidate.topologyHealing) {
          result.surfaceCellContext.simplificationTopologyHealingCandidates
              .push_back(candidate);
        }
      }
      result.surfaceCellContext.simplificationTransactions =
          std::move(simplified.transactions);
    } else {
      simplificationCandidates = geometry::SurfaceSimplificationCandidateSet{};
      simplified.transactions.clear();
      simplified.transactions.shrink_to_fit();
    }
    result.surfaceCellContext.simplificationCommitted = simplified.committed;
    result.surfaceCellContext.simplificationRejected = simplified.rejected;
    result.surfaceCellContext.hasSimplificationDiagnostics = true;
    result.diagnostics.surfaceCellSimplificationSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - simplificationStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellSimplifiedCellCount =
        simplified.hasComplexOutput ? simplified.complex.cells.size() : 0U;
    result.diagnostics.surfaceCellSimplifiedCountAvailable = true;
    const geometry::SurfaceCellComplex &simplifiedComplexForHash =
        simplified.hasComplexOutput ? simplified.complex : arrangementComplex;
    const std::uint64_t simplificationHash =
        hash_surface_complex(simplifiedComplexForHash);
    const SurfaceCellObjectIdentity simplificationIdentity = make_identity(
        "arrangement", simplificationHash,
        result.diagnostics.surfaceCellSimplifiedCellCount);
    mark_stage_consumed("arrangement", arrangementIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("simplification", arrangementIdentity,
                              simplificationIdentity, true,
                              result.diagnostics.surfaceCellSimplificationSeconds);
    completedSurfaceCellStages.push_back("simplification");
    if (options.surfaceCells.injectFailureAfterStage == 7) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "simplification");
    }

    const auto completionStart = Clock::now();
    std::size_t completedQuadCount = 0U;
    Eigen::MatrixXd completedVertices(0, 3);
    Eigen::MatrixXi completedQuads(0, 4);
    std::vector<geometry::SurfacePoint> completedProvenance;
    std::vector<geometry::PureQuadVertexLineage> completedVertexLineage;
    std::vector<geometry::PureQuadFaceLineage> completedQuadLineage;
    geometry::SurfaceCellComplex completionComplex =
        retainIntermediateGeometry
            ? simplifiedComplexForHash
            : (simplified.hasComplexOutput
                   ? std::move(simplified.complex)
                   : std::move(arrangementComplex));
    if (!retainIntermediateGeometry) {
      // If simplification produced a replacement complex, the input
      // arrangement would otherwise remain live for the entire completion
      // stage. Its semantic hash and diagnostics are already recorded.
      arrangementComplex = geometry::SurfaceCellComplex{};
      simplified = geometry::SurfaceSimplificationResult{};
    }
    geometry::SurfaceCellComplexCompletionOptions completionOptions;
    completionOptions.descriptorOptions.singularCycles =
        result.surfaceCellContext.crossField.singularCycles;
    completionOptions.descriptorOptions.singularIndices =
        result.surfaceCellContext.crossField.singularIndices;
    if (result.surfaceCellContext.hasSourceSurfaceLabels) {
      completionOptions.sourceFaceComponents =
          &result.surfaceCellContext.sourceSurfaceLabels.componentByFace;
      completionOptions.sourceFaceSheets =
          &result.surfaceCellContext.sourceSurfaceLabels.localSheetByFace;
    }
    geometry::SurfaceCellComplexCompletionResult completionResult =
        geometry::complete_surface_cell_complex(
            std::move(completionComplex), meshWhole.V, meshWhole.F,
            completionOptions);
    result.surfaceCellContext.completionOddCellsBeforeRepair =
        completionResult.parityOddCellsBefore;
    result.surfaceCellContext.completionOddCellsAfterRepair =
        completionResult.parityOddCellsAfter;
    result.surfaceCellContext.completionParitySplitEdges =
        completionResult.paritySplitEdges;
    result.surfaceCellContext.completionParityHardFeatureSplits =
        completionResult.parityHardFeatureSplits;
    result.surfaceCellContext.completionSideInfeasibleBeforeRepair =
        completionResult.sideInfeasibleCellsBefore;
    result.surfaceCellContext.completionSideInfeasibleAfterRepair =
        completionResult.sideInfeasibleCellsAfter;
    result.surfaceCellContext.completionSideInitialEquationDefect =
        completionResult.sideInitialEquationDefect;
    result.surfaceCellContext.completionSideFinalEquationDefect =
        completionResult.sideFinalEquationDefect;
    result.surfaceCellContext.completionSidePropagationPasses =
        completionResult.sidePropagationPasses;
    result.surfaceCellContext.completionSideAttemptedInsertions =
        completionResult.sideAttemptedInsertions;
    result.surfaceCellContext.completionSideInsertedVertices =
        completionResult.sideInsertedVertices;
    result.surfaceCellContext.completionSideSplitEdges =
        completionResult.sideSplitEdges;
    result.surfaceCellContext.completionSideHardFeatureSplits =
        completionResult.sideHardFeatureSplits;
    result.surfaceCellContext.completionAttemptedPatches =
        completionResult.attemptedPatches;
    result.surfaceCellContext.completionFailedPatches =
        completionResult.failedPatches;
    result.surfaceCellContext.completionOwnershipRepairAttempts =
        completionResult.completionOwnershipRepairAttempts;
    result.surfaceCellContext.completionTemplateInitialConflictCount =
        completionResult.completionTemplateInitialConflictCount;
    result.surfaceCellContext.completionTemplateFinalConflictCount =
        completionResult.completionTemplateFinalConflictCount;
    result.surfaceCellContext.completionTemplateConflictComponentCount =
        completionResult.completionTemplateConflictComponentCount;
    result.surfaceCellContext.completionTemplateChangedPatchCount =
        completionResult.completionTemplateChangedPatchCount;
    result.surfaceCellContext.completionTemplateAssemblyPasses =
        completionResult.completionTemplateAssemblyPasses;
    result.surfaceCellContext.completionOwnershipStructuralRepairAttempts =
        completionResult.completionOwnershipStructuralRepairAttempts;
    result.surfaceCellContext.completionOwnershipInsertedBoundaryVertices =
        completionResult.completionOwnershipInsertedBoundaryVertices;
    result.surfaceCellContext.completionOwnershipStructuralCandidateBudget =
        completionResult.completionOwnershipStructuralCandidateBudget;
    result.surfaceCellContext.completionOwnershipStructuralCandidatesConsumed =
        completionResult.completionOwnershipStructuralCandidatesConsumed;
    result.surfaceCellContext.completionOwnershipVisitedStateCount =
        completionResult.completionOwnershipVisitedStateCount;
    result.surfaceCellContext.completionOwnershipFullRecomputationPasses =
        completionResult.completionOwnershipFullRecomputationPasses;
    result.surfaceCellContext.completionOwnershipIncrementalRecomputationPasses =
        completionResult.completionOwnershipIncrementalRecomputationPasses;
    result.surfaceCellContext.completionOwnershipPreConflictCount =
        completionResult.completionOwnershipPreConflictCount;
    result.surfaceCellContext.completionOwnershipPostConflictCount =
        completionResult.completionOwnershipPostConflictCount;
    result.surfaceCellContext.completionOwnershipRetainedConflictCount =
        completionResult.completionOwnershipRetainedConflictCount;
    result.surfaceCellContext.completionOwnershipRemovedConflictCount =
        completionResult.completionOwnershipRemovedConflictCount;
    result.surfaceCellContext.completionOwnershipIntroducedConflictCount =
        completionResult.completionOwnershipIntroducedConflictCount;
    result.surfaceCellContext.completionOwnershipConflictComponentCount =
        completionResult.completionOwnershipConflictComponentCount;
    result.surfaceCellContext.completionOwnershipIndependentComponentCount =
        completionResult.completionOwnershipIndependentComponentCount;
    result.surfaceCellContext.completionOwnershipReusedPatchCompletions =
        completionResult.completionOwnershipReusedPatchCompletions;
    result.surfaceCellContext.completionOwnershipRecomputedPatchCompletions =
        completionResult.completionOwnershipRecomputedPatchCompletions;
    result.surfaceCellContext.completionOwnershipPreConflictInventoryHash =
        completionResult.completionOwnershipPreConflictInventoryHash;
    result.surfaceCellContext.completionOwnershipPostConflictInventoryHash =
        completionResult.completionOwnershipPostConflictInventoryHash;
    result.surfaceCellContext.completionOwnershipConflictFrontierOwnedBytes =
        completionResult.completionOwnershipConflictFrontierOwnedBytes;
    result.surfaceCellContext.completionOwnershipProductCacheOwnedBytes =
        completionResult.completionOwnershipProductCacheOwnedBytes;
    result.surfaceCellContext.completionOwnershipCurrentLiveCandidateComplexes =
        completionResult.completionOwnershipCurrentLiveCandidateComplexes;
    result.surfaceCellContext.completionOwnershipPeakLiveCandidateComplexes =
        completionResult.completionOwnershipPeakLiveCandidateComplexes;
    result.surfaceCellContext.completionOwnershipLastCandidateHalfedge =
        completionResult.completionOwnershipLastCandidateHalfedge;
    result.surfaceCellContext.completionOwnershipLastCandidateHalfedges =
        completionResult.completionOwnershipLastCandidateHalfedges;
    result.surfaceCellContext.completionOwnershipLastAffectedPatches =
        completionResult.completionOwnershipLastAffectedPatches;
    result.surfaceCellContext.completionOwnershipRouteCandidateCount =
        completionResult.completionOwnershipRouteCandidateCount;
    result.surfaceCellContext.completionOwnershipRollbackOwnedBytes =
        completionResult.completionOwnershipRollbackOwnedBytes;
    result.surfaceCellContext.completionOwnershipCandidateOwnedBytes =
        completionResult.completionOwnershipCandidateOwnedBytes;
    result.surfaceCellContext.completionOwnershipDescriptorOwnedBytes =
        completionResult.completionOwnershipDescriptorOwnedBytes;
    result.surfaceCellContext.completionOwnershipCompletedPatchOwnedBytes =
        completionResult.completionOwnershipCompletedPatchOwnedBytes;
    result.surfaceCellContext.completionOwnershipAssemblyOwnedBytes =
        completionResult.completionOwnershipAssemblyOwnedBytes;
    result.surfaceCellContext.completionOwnershipCurrentStructuralOwnedBytes =
        completionResult.completionOwnershipCurrentStructuralOwnedBytes;
    result.surfaceCellContext.completionOwnershipPeakStructuralOwnedBytes =
        completionResult.completionOwnershipPeakStructuralOwnedBytes;
    result.surfaceCellContext.completionOwnershipStructuralExhaustionReason =
        completionResult.completionOwnershipStructuralExhaustionReason;
    result.surfaceCellContext.completionOwnershipRepairLog =
        std::move(completionResult.ownershipRepairAttempts);
    result.surfaceCellContext.firstCompletionOwnershipRejection =
        completionResult.firstCompletionOwnershipRejection;
    result.surfaceCellContext.completionFailure = completionResult.failure;
    result.diagnostics.surfaceCellCompletionOwnershipRepairAttempts =
        static_cast<std::size_t>(
            completionResult.completionOwnershipRepairAttempts);
    result.diagnostics.surfaceCellCompletionOwnershipRepairAttemptsAvailable =
        true;
    result.diagnostics
        .surfaceCellCompletionOwnershipStructuralRepairAttempts =
        static_cast<std::size_t>(
            completionResult.completionOwnershipStructuralRepairAttempts);
    result.diagnostics
        .surfaceCellCompletionOwnershipInsertedBoundaryVertices =
        static_cast<std::size_t>(
            completionResult.completionOwnershipInsertedBoundaryVertices);
    result.diagnostics.surfaceCellCompletionOwnershipStructuralCandidateBudget =
        static_cast<std::size_t>(
            completionResult.completionOwnershipStructuralCandidateBudget);
    result.diagnostics
        .surfaceCellCompletionOwnershipStructuralCandidatesConsumed =
        static_cast<std::size_t>(
            completionResult.completionOwnershipStructuralCandidatesConsumed);
    result.diagnostics.surfaceCellCompletionOwnershipVisitedStateCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipVisitedStateCount);
    result.diagnostics
        .surfaceCellCompletionOwnershipFullRecomputationPasses =
        static_cast<std::size_t>(
            completionResult.completionOwnershipFullRecomputationPasses);
    result.diagnostics
        .surfaceCellCompletionOwnershipIncrementalRecomputationPasses =
        static_cast<std::size_t>(
            completionResult.completionOwnershipIncrementalRecomputationPasses);
    result.diagnostics.surfaceCellCompletionOwnershipPreConflictCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipPreConflictCount);
    result.diagnostics.surfaceCellCompletionOwnershipPostConflictCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipPostConflictCount);
    result.diagnostics.surfaceCellCompletionOwnershipRetainedConflictCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipRetainedConflictCount);
    result.diagnostics.surfaceCellCompletionOwnershipRemovedConflictCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipRemovedConflictCount);
    result.diagnostics.surfaceCellCompletionOwnershipIntroducedConflictCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipIntroducedConflictCount);
    result.diagnostics.surfaceCellCompletionOwnershipConflictComponentCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipConflictComponentCount);
    result.diagnostics
        .surfaceCellCompletionOwnershipIndependentComponentCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipIndependentComponentCount);
    result.diagnostics.surfaceCellCompletionOwnershipReusedPatchCompletions =
        static_cast<std::size_t>(
            completionResult.completionOwnershipReusedPatchCompletions);
    result.diagnostics.surfaceCellCompletionOwnershipRecomputedPatchCompletions =
        static_cast<std::size_t>(
            completionResult.completionOwnershipRecomputedPatchCompletions);
    result.diagnostics.surfaceCellCompletionOwnershipPreConflictInventoryHash =
        completionResult.completionOwnershipPreConflictInventoryHash;
    result.diagnostics.surfaceCellCompletionOwnershipPostConflictInventoryHash =
        completionResult.completionOwnershipPostConflictInventoryHash;
    result.diagnostics.surfaceCellCompletionOwnershipConflictFrontierOwnedBytes =
        completionResult.completionOwnershipConflictFrontierOwnedBytes;
    result.diagnostics.surfaceCellCompletionOwnershipProductCacheOwnedBytes =
        completionResult.completionOwnershipProductCacheOwnedBytes;
    result.diagnostics
        .surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes =
        static_cast<std::size_t>(
            completionResult.completionOwnershipCurrentLiveCandidateComplexes);
    result.diagnostics.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes =
        static_cast<std::size_t>(
            completionResult.completionOwnershipPeakLiveCandidateComplexes);
    result.diagnostics.surfaceCellCompletionOwnershipLastCandidateHalfedge =
        completionResult.completionOwnershipLastCandidateHalfedge;
    result.diagnostics.surfaceCellCompletionOwnershipLastCandidateHalfedges =
        completionResult.completionOwnershipLastCandidateHalfedges;
    result.diagnostics.surfaceCellCompletionOwnershipLastAffectedPatches =
        completionResult.completionOwnershipLastAffectedPatches;
    result.diagnostics.surfaceCellCompletionOwnershipRouteCandidateCount =
        static_cast<std::size_t>(
            completionResult.completionOwnershipRouteCandidateCount);
    result.diagnostics.surfaceCellCompletionOwnershipRollbackOwnedBytes =
        completionResult.completionOwnershipRollbackOwnedBytes;
    result.diagnostics.surfaceCellCompletionOwnershipCandidateOwnedBytes =
        completionResult.completionOwnershipCandidateOwnedBytes;
    result.diagnostics.surfaceCellCompletionOwnershipDescriptorOwnedBytes =
        completionResult.completionOwnershipDescriptorOwnedBytes;
    result.diagnostics
        .surfaceCellCompletionOwnershipCompletedPatchOwnedBytes =
        completionResult.completionOwnershipCompletedPatchOwnedBytes;
    result.diagnostics.surfaceCellCompletionOwnershipAssemblyOwnedBytes =
        completionResult.completionOwnershipAssemblyOwnedBytes;
    result.diagnostics
        .surfaceCellCompletionOwnershipCurrentStructuralOwnedBytes =
        completionResult.completionOwnershipCurrentStructuralOwnedBytes;
    result.diagnostics.surfaceCellCompletionOwnershipPeakStructuralOwnedBytes =
        completionResult.completionOwnershipPeakStructuralOwnedBytes;
    result.diagnostics
        .surfaceCellCompletionOwnershipStructuralExhaustionReason =
        geometry::surface_cell_structural_repair_exhaustion_reason_name(
            completionResult.completionOwnershipStructuralExhaustionReason);
    result.diagnostics
        .surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable = true;
    result.diagnostics.surfaceCellCompletionOwnershipStructuralLedgerAvailable =
        true;
    const geometry::PureQuadCompletionOwnershipRejection &ownershipRejection =
        completionResult.firstCompletionOwnershipRejection;
    if (ownershipRejection.active) {
      result.diagnostics.surfaceCellCompletionOwnershipRejectionAvailable =
          true;
      result.diagnostics.surfaceCellCompletionOwnershipFailure =
          ownershipRejection.failure;
      result.diagnostics.surfaceCellCompletionOwnershipSourcePatch =
          ownershipRejection.sourcePatch;
      result.diagnostics.surfaceCellCompletionOwnershipLocalVertex =
          ownershipRejection.localVertex;
      result.diagnostics.surfaceCellCompletionOwnershipBoundaryVertex =
          ownershipRejection.boundaryVertex;
      result.diagnostics.surfaceCellCompletionOwnershipBackend =
          static_cast<int>(ownershipRejection.backend);
      result.diagnostics.surfaceCellCompletionOwnershipVariant =
          ownershipRejection.completionVariant;
      result.diagnostics.surfaceCellCompletionOwnershipStoredFace =
          ownershipRejection.storedFace;
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        result.diagnostics.surfaceCellCompletionOwnershipBarycentric[
            static_cast<std::size_t>(coordinate)] =
            ownershipRejection.barycentric(coordinate);
      }
      result.diagnostics.surfaceCellCompletionOwnershipEntityKind =
          static_cast<int>(ownershipRejection.sourceEntityKind);
      result.diagnostics.surfaceCellCompletionOwnershipSourceVertex =
          ownershipRejection.sourceVertex;
      result.diagnostics.surfaceCellCompletionOwnershipSourceEdge =
          ownershipRejection.sourceEdge;
      result.diagnostics.surfaceCellCompletionOwnershipCandidateFaces =
          ownershipRejection.candidateSupportedFaces;
      result.diagnostics.surfaceCellCompletionOwnershipPatchFaces =
          ownershipRejection.patchSourceFaces;
      result.diagnostics.surfaceCellCompletionOwnershipComponent =
          ownershipRejection.sourceComponent;
      result.diagnostics.surfaceCellCompletionOwnershipSheet =
          ownershipRejection.sourceSheet;
    }
    if (retainIntermediateGeometry) {
      result.surfaceCellContext.arrangement = arrangementComplex;
      result.surfaceCellContext.hasArrangement = true;
      result.surfaceCellContext.simplifiedComplex = simplifiedComplexForHash;
      result.surfaceCellContext.hasSimplifiedComplex = true;
      if (completionResult.hasPreparedComplex) {
        result.surfaceCellContext.completionComplex =
            std::move(completionResult.preparedComplex);
        result.surfaceCellContext.hasCompletionComplex = true;
      }
      result.surfaceCellContext.patchDescriptors =
          std::move(completionResult.descriptors.descriptors);
      result.surfaceCellContext.completionUnresolvedSingularVertices =
          std::move(completionResult.descriptors.unresolvedSingularVertices);
      result.surfaceCellContext.hasPatchDescriptors =
          !result.surfaceCellContext.patchDescriptors.empty();
      result.surfaceCellContext.completedPatches =
          std::move(completionResult.completedPatches);
    }

    geometry::PureQuadMesh aggregateLineageMesh;
    bool completionOnlyReusesSourceTrianglePairBoundaries = false;
    if (completionResult.success) {
      aggregateLineageMesh = retainIntermediateGeometry
          ? completionResult.assembly.mesh
          : std::move(completionResult.assembly.mesh);
      completionOnlyReusesSourceTrianglePairBoundaries =
          geometry::output_is_only_paired_source_triangle_boundaries(
              aggregateLineageMesh, meshWhole.F);
    }
    if (!retainIntermediateGeometry) {
      // Scalar diagnostics and the authoritative assembled mesh have been
      // extracted. Release prepared topology, descriptors, patch completions,
      // and conflict workspaces before output validation/refinalization.
      completionResult = geometry::SurfaceCellComplexCompletionResult{};
    }

    // A source-triangle pair may identify a valid source cell, but returning
    // that pair boundary as the final quad is not a remesh. Unless the caller
    // explicitly requested the proof path, prefer deterministic source-grid
    // refinement so the final output has new topology and complete lineage.
    // Pair-boundary-only output is rejected unconditionally by the lineage
    // gate below if recovery is disabled or fails.
    const bool shouldAttemptSourceGridRecovery =
        options.surfaceCells.allowSourceGridRecovery &&
        !options.surfaceCells.rejectPairedSourceTriangleBoundaryOutput;
    if (shouldAttemptSourceGridRecovery) {
      const FieldAlignedSourceQuadRecoveryResult recovery =
          recover_unique_field_aligned_source_quads(
              meshWhole, result.surfaceCellContext.crossField,
              completionOptions.sourceFaceComponents,
              completionOptions.sourceFaceSheets, &hardFeatureRailEdges);
      if (recovery.success) {
        aggregateLineageMesh = recovery.mesh;
        result.surfaceCellContext.completedPatches = {recovery.mesh};
        result.surfaceCellContext.sourceGridRecoveryUsed = true;
        completionOnlyReusesSourceTrianglePairBoundaries = false;
      }
    }

    if (!aggregateLineageMesh.quads.empty()) {
      completedVertices = aggregateLineageMesh.vertexPositions;
      completedProvenance = aggregateLineageMesh.vertexProvenance;
      completedVertexLineage = aggregateLineageMesh.vertexLineage;
      completedQuadLineage = aggregateLineageMesh.quadLineage;
      completedQuads.resize(
          static_cast<int>(aggregateLineageMesh.quads.size()), 4);
      for (int q = 0; q < completedQuads.rows(); ++q) {
        for (int c = 0; c < 4; ++c) {
          completedQuads(q, c) =
              aggregateLineageMesh.quads[static_cast<std::size_t>(q)]
                                            [static_cast<std::size_t>(c)];
        }
      }
      completedQuadCount = aggregateLineageMesh.quads.size();
    }

    result.diagnostics.surfaceCellCompletionSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - completionStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellCompletedQuadCount = completedQuadCount;
    result.diagnostics.surfaceCellCompletedQuadCountAvailable = true;
    result.diagnostics.surfaceCellProvenanceVertexCount =
        completedProvenance.size();
    result.diagnostics.surfaceCellProvenanceVertexCountAvailable = true;
    result.surfaceCellContext.completedVertices = completedVertices;
    result.surfaceCellContext.completedQuads = completedQuads;
    result.surfaceCellContext.completedProvenance = completedProvenance;
    result.surfaceCellContext.completedVertexLineage = completedVertexLineage;
    result.surfaceCellContext.completedQuadLineage = completedQuadLineage;
    // Aggregate quads may originate from different patches, so validate each
    // lineage record independently. Geometric coincidence with paired source
    // triangles is always detected, but it is rejected only when the explicit
    // proof-fixture gate is enabled. A valid minimal completed patch can
    // otherwise coincide with the boundary of two source triangles.
    geometry::PureQuadOutputLineageValidation lineageValidation;
    lineageValidation.allVerticesMapped =
        completedVertexLineage.size() ==
            static_cast<std::size_t>(completedVertices.rows()) &&
        std::all_of(completedVertexLineage.begin(),
                    completedVertexLineage.end(),
                    [](const auto &lineage) { return lineage.valid(); });
    lineageValidation.allQuadsMapped =
        completedQuadLineage.size() ==
            static_cast<std::size_t>(completedQuads.rows()) &&
        std::all_of(completedQuadLineage.begin(), completedQuadLineage.end(),
                    [](const auto &lineage) { return lineage.valid(); });
    lineageValidation.solelyPairedSourceTriangleBoundaries =
        geometry::output_is_only_paired_source_triangle_boundaries(
            aggregateLineageMesh, meshWhole.F);
    const bool pairedBoundaryOutputRejected =
        lineageValidation.solelyPairedSourceTriangleBoundaries;
    lineageValidation.valid = lineageValidation.allVerticesMapped &&
                              lineageValidation.allQuadsMapped &&
                              !pairedBoundaryOutputRejected;
    if (!lineageValidation.allVerticesMapped) {
      lineageValidation.failure = "MissingOutputVertexLineage";
    } else if (!lineageValidation.allQuadsMapped) {
      lineageValidation.failure = "MissingOutputQuadLineage";
    } else if (pairedBoundaryOutputRejected) {
      lineageValidation.failure = "PairedSourceTriangleBoundaryOutput";
    }
    result.surfaceCellContext.outputLineageValidation = lineageValidation;
    result.surfaceCellContext.hasCompletedPatches =
        !result.surfaceCellContext.completedPatches.empty();
    std::uint64_t completionHash = hash_completion_mesh(
        completedVertices, completedQuads, completedProvenance);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionOwnershipRepairAttempts);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionTemplateInitialConflictCount);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionTemplateFinalConflictCount);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionTemplateConflictComponentCount);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionTemplateChangedPatchCount);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionTemplateAssemblyPasses);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipStructuralRepairAttempts);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipInsertedBoundaryVertices);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipStructuralCandidateBudget);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipStructuralCandidatesConsumed);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionOwnershipVisitedStateCount);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipFullRecomputationPasses);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipIncrementalRecomputationPasses);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipPreConflictCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipPostConflictCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipRetainedConflictCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipRemovedConflictCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipIntroducedConflictCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipConflictComponentCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipIndependentComponentCount);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipReusedPatchCompletions);
    hash_combine_i64(completionHash,
                     result.surfaceCellContext.completionOwnershipRecomputedPatchCompletions);
    hash_combine_i64(completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
            .completionOwnershipPreConflictInventoryHash));
    hash_combine_i64(completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
            .completionOwnershipPostConflictInventoryHash));
    hash_combine_i64(completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
            .completionOwnershipConflictFrontierOwnedBytes));
    hash_combine_i64(completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
            .completionOwnershipProductCacheOwnedBytes));
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipCurrentLiveCandidateComplexes);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext
            .completionOwnershipPeakLiveCandidateComplexes);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionOwnershipLastCandidateHalfedge);
    hash_vector(completionHash,
                result.surfaceCellContext
                    .completionOwnershipLastCandidateHalfedges);
    hash_combine_i64(
        completionHash,
        result.surfaceCellContext.completionOwnershipRouteCandidateCount);
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
                                      .completionOwnershipRollbackOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
                                      .completionOwnershipCandidateOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
                                      .completionOwnershipDescriptorOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(
            result.surfaceCellContext
                .completionOwnershipCompletedPatchOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
                                      .completionOwnershipAssemblyOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(
            result.surfaceCellContext
                .completionOwnershipCurrentStructuralOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
                                      .completionOwnershipPeakStructuralOwnedBytes));
    hash_combine_i64(
        completionHash,
        static_cast<int>(result.surfaceCellContext
                             .completionOwnershipStructuralExhaustionReason));
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(result.surfaceCellContext
                                      .completionOwnershipLastAffectedPatches
                                      .size()));
    for (const int patch : result.surfaceCellContext
                               .completionOwnershipLastAffectedPatches) {
      hash_combine_i64(completionHash, patch);
    }
    hash_combine_i64(
        completionHash,
        static_cast<std::int64_t>(
            result.surfaceCellContext.completionOwnershipRepairLog.size()));
    for (const geometry::SurfaceCellOwnershipRepairAttempt &attempt :
         result.surfaceCellContext.completionOwnershipRepairLog) {
      hash_combine_i64(completionHash, attempt.ordinal);
      hash_combine_i64(completionHash, static_cast<int>(attempt.action));
      hash_combine_i64(completionHash,
                       static_cast<int>(attempt.conflictClass));
      hash_combine_i64(completionHash,
                       static_cast<int>(attempt.resultingConflictClass));
      hash_combine_i64(completionHash, attempt.firstPatch);
      hash_combine_i64(completionHash, attempt.secondPatch);
      hash_combine_i64(completionHash, attempt.selectedPatch);
      hash_combine_i64(completionHash, attempt.selectedHalfedge);
      hash_vector(completionHash, attempt.selectedHalfedges);
      hash_combine_i64(
          completionHash,
          static_cast<std::int64_t>(attempt.sharedCornerIdentityHashes.size()));
      for (const std::uint64_t hash : attempt.sharedCornerIdentityHashes) {
        hash_combine_i64(completionHash, static_cast<std::int64_t>(hash));
      }
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.routeIdentityHash));
      hash_combine_i64(completionHash, attempt.routeCandidateCount);
      hash_combine_i64(completionHash, attempt.routeIntervalCount);
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.rollbackOwnedBytes));
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.candidateOwnedBytes));
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.descriptorOwnedBytes));
      hash_combine_i64(
          completionHash,
          static_cast<std::int64_t>(attempt.completedPatchOwnedBytes));
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.assemblyOwnedBytes));
      hash_combine_i64(
          completionHash,
          static_cast<std::int64_t>(attempt.totalStructuralOwnedBytes));
      hash_combine_i64(completionHash, static_cast<int>(attempt.backend));
      hash_combine_i64(completionHash, attempt.fromVariant);
      hash_combine_i64(completionHash, attempt.toVariant);
      hash_combine_i64(completionHash, attempt.insertedVertices);
      hash_combine_i64(completionHash, attempt.splitUndirectedEdges);
      hash_combine_i64(completionHash, attempt.candidateEvaluation);
      hash_combine_i64(completionHash, attempt.structuralAttempt);
      hash_combine_i64(completionHash, attempt.fullRecomputationPass);
      hash_combine_i64(completionHash, attempt.visitedStateCount);
      hash_combine_i64(completionHash,
                       attempt.globalInsertedVerticesBefore);
      hash_combine_i64(completionHash,
                       attempt.globalInsertedVerticesAfter);
      hash_combine_i64(completionHash, attempt.liveCandidateComplexes);
      hash_combine_i64(completionHash,
                       attempt.completionSucceeded ? 1 : 0);
      hash_combine_i64(completionHash, attempt.committed ? 1 : 0);
      hash_combine_i64(completionHash, attempt.repeatedState ? 1 : 0);
      hash_combine_i64(completionHash, attempt.madeProgress ? 1 : 0);
      hash_combine_i64(completionHash,
                       attempt.introducedOwnershipClaim ? 1 : 0);
      hash_combine_i64(completionHash, attempt.preConflictCount);
      hash_combine_i64(completionHash, attempt.postConflictCount);
      hash_combine_i64(completionHash, attempt.retainedConflictCount);
      hash_combine_i64(completionHash, attempt.removedConflictCount);
      hash_combine_i64(completionHash, attempt.introducedConflictCount);
      hash_combine_i64(completionHash, attempt.reusedPatchCompletions);
      hash_combine_i64(completionHash, attempt.recomputedPatchCompletions);
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.preConflictInventoryHash));
      hash_combine_i64(completionHash,
                       static_cast<std::int64_t>(attempt.postConflictInventoryHash));
      hash_combine_i64(completionHash, static_cast<int>(attempt.outcome));
      hash_combine_i64(
          completionHash,
          static_cast<std::int64_t>(attempt.affectedPatches.size()));
      for (const int patch : attempt.affectedPatches) {
        hash_combine_i64(completionHash, patch);
      }
      hash_combine_string(completionHash, attempt.failure);
    }
    const geometry::PureQuadCompletionOwnershipRejection &hashRejection =
        result.surfaceCellContext.firstCompletionOwnershipRejection;
    hash_combine_i64(completionHash, hashRejection.active ? 1 : 0);
    if (hashRejection.active) {
      hash_combine_string(completionHash, hashRejection.failure);
      hash_combine_i64(completionHash, hashRejection.sourcePatch);
      hash_combine_i64(completionHash, hashRejection.localVertex);
      hash_combine_i64(completionHash,
                       hashRejection.boundaryVertex ? 1 : 0);
      hash_combine_i64(completionHash,
                       static_cast<int>(hashRejection.backend));
      hash_combine_i64(completionHash, hashRejection.completionVariant);
      hash_combine_i64(completionHash, hashRejection.storedFace);
      for (int coordinate = 0; coordinate < 3; ++coordinate) {
        hash_combine_double(completionHash,
                            hashRejection.barycentric(coordinate));
      }
      hash_combine_i64(completionHash,
                       static_cast<int>(hashRejection.sourceEntityKind));
      hash_combine_i64(completionHash, hashRejection.sourceVertex);
      hash_combine_i64(completionHash, hashRejection.sourceEdge[0]);
      hash_combine_i64(completionHash, hashRejection.sourceEdge[1]);
      hash_vector(completionHash, hashRejection.candidateSupportedFaces);
      hash_vector(completionHash, hashRejection.patchSourceFaces);
      hash_combine_i64(completionHash, hashRejection.sourceComponent);
      hash_combine_i64(completionHash, hashRejection.sourceSheet);
    }
    const SurfaceCellObjectIdentity completionIdentity = make_identity(
        "completion", completionHash, completedQuadCount);
    mark_stage_consumed("simplification", simplificationIdentity,
                        SurfaceCellConsumptionKind::Full);
    const bool completionAccepted =
        completedQuadCount > 0U &&
        result.surfaceCellContext.outputLineageValidation.valid;
    record_surface_cell_stage("completion", simplificationIdentity,
                              completionIdentity, completionAccepted,
                              result.diagnostics.surfaceCellCompletionSeconds);
    if (!completionAccepted) {
      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                "completion");
    }
    completedSurfaceCellStages.push_back("completion");
    if (options.surfaceCells.injectFailureAfterStage == 8) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "completion");
    }

    const auto optimizationStart = Clock::now();
    if (completedVertices.rows() > 0 && completedQuads.rows() > 0) {
      orient_quads_to_source_normals(
          completedVertices, meshWhole.V, meshWhole.F, completedProvenance,
          completedQuads, &completedQuadLineage);
      geometry::SurfaceOptimizationConstraints constraints;
      constraints.sourceVertices = meshWhole.V;
      constraints.sourceFaces = meshWhole.F;
      constraints.sourcePositions = meshWhole.V;
      constraints.sourceNormals = meshWhole.faceNormals;
      constraints.sourceFieldX = faceAxisX;
      constraints.sourceFieldY = faceAxisY;
      constraints.sourceFaceComponent =
          result.surfaceCellContext.sourceSurfaceLabels.componentByFace;
      constraints.sourceFaceSheet =
          result.surfaceCellContext.sourceSurfaceLabels.localSheetByFace;
      constraints.outputQuadSourceFaces.assign(
          static_cast<std::size_t>(completedQuads.rows()), -1);
      constraints.constrainVerticesToProvenanceEntities =
          result.surfaceCellContext.sourceGridRecoveryUsed;
      for (int quad = 0;
           quad < completedQuads.rows() &&
           quad < static_cast<int>(completedQuadLineage.size());
           ++quad) {
        const geometry::PureQuadFaceLineage &lineage =
            completedQuadLineage[static_cast<std::size_t>(quad)];
        if (lineage.valid() && lineage.sourcePatch >= 0 &&
            lineage.sourcePatch < meshWhole.F.rows()) {
          constraints.outputQuadSourceFaces[static_cast<std::size_t>(quad)] =
              lineage.sourcePatch;
        }
      }
      constraints.sourceVertexFaces.resize(
          static_cast<std::size_t>(meshWhole.V.rows()));
      for (int face = 0; face < meshWhole.F.rows(); ++face) {
        for (int corner = 0; corner < meshWhole.F.cols(); ++corner) {
          const int vertex = meshWhole.F(face, corner);
          if (vertex >= 0 && vertex < meshWhole.V.rows()) {
            constraints.sourceVertexFaces[static_cast<std::size_t>(vertex)]
                .push_back(face);
          }
          const int next =
              meshWhole.F(face, (corner + 1) % meshWhole.F.cols());
          if (vertex >= 0 && next >= 0 && vertex != next) {
            constraints.sourceEdgeFaces[std::minmax(vertex, next)].push_back(
                face);
          }
        }
      }
      constraints.localTargetSize = targetSize.targetSize;
      constexpr double kSourceGridRecoverySubdivisionScale = 0.5;
      double effectiveOptimizationTargetSize = tracingOptions.defaultTargetSize;
      if (result.surfaceCellContext.sourceGridRecoveryUsed) {
        const double requestedRecoveryTargetSize =
            targetSizeOptions.baseSize * kSourceGridRecoverySubdivisionScale;
        const SourceGridRecoveryTargetSizeResult recoveryTargetSize =
            make_source_grid_recovery_target_size(
                meshWhole.V, meshWhole.F, completedVertices, completedQuads,
                completedProvenance, requestedRecoveryTargetSize,
                options.surfaceCells.maxSourceGridRecoveryTargetRelaxation);
        result.surfaceCellContext.sourceGridRecoveryTargetSize =
            recoveryTargetSize.targetSize;
        result.surfaceCellContext.hasSourceGridRecoveryTargetSize =
            recoveryTargetSize.targetSize.size() == meshWhole.V.rows();
        result.surfaceCellContext.sourceGridRecoveryTargetSizeRelaxed =
            recoveryTargetSize.relaxed;
        result.surfaceCellContext
            .sourceGridRecoveryTargetSizeMaxRelaxationRatio =
            recoveryTargetSize.maxRelaxationRatio;
        result.diagnostics.surfaceCellSourceGridRecoveryTargetSizeRelaxed =
            recoveryTargetSize.relaxed;
        result.diagnostics
            .surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio =
            recoveryTargetSize.maxRelaxationRatio;
        if (recoveryTargetSize.valid) {
          constraints.localTargetSize = recoveryTargetSize.targetSize;
          effectiveOptimizationTargetSize =
              recoveryTargetSize.targetSize.mean();
        } else {
          // Preserve the requested target so an excessive or infeasible
          // topology relaxation is rejected by the normal validation stage.
          constraints.localTargetSize = Eigen::VectorXd::Constant(
              meshWhole.V.rows(), requestedRecoveryTargetSize);
          effectiveOptimizationTargetSize = requestedRecoveryTargetSize;
        }
      }
      constraints.vertexProvenance = completedProvenance;
      fill_surface_cell_rail_constraints(authoritativeRails, completedVertices,
                                         completedProvenance, constraints);
      if (result.surfaceCellContext.sourceGridRecoveryUsed &&
          !aggregateLineageMesh.boundaryLoops.empty()) {
        constraints.authoritativeBoundaryEdges.clear();
        constraints.authoritativeBoundaryLoops =
            aggregateLineageMesh.boundaryLoops;
        constraints.authoritativeBoundaryLoop =
            constraints.authoritativeBoundaryLoops.front();
        for (const std::vector<int> &loop :
             constraints.authoritativeBoundaryLoops) {
          for (std::size_t index = 0; index < loop.size(); ++index) {
            constraints.authoritativeBoundaryEdges.insert(std::minmax(
                loop[index], loop[(index + 1U) % loop.size()]));
          }
        }
        std::vector<std::set<int>> recoveredNeighbors(
            static_cast<std::size_t>(completedVertices.rows()));
        for (int face = 0; face < completedQuads.rows(); ++face) {
          for (int corner = 0; corner < 4; ++corner) {
            const int first = completedQuads(face, corner);
            const int second = completedQuads(face, (corner + 1) % 4);
            if (first >= 0 && second >= 0 &&
                first < completedVertices.rows() &&
                second < completedVertices.rows()) {
              recoveredNeighbors[static_cast<std::size_t>(first)].insert(second);
              recoveredNeighbors[static_cast<std::size_t>(second)].insert(first);
            }
          }
        }
        // The recovery construct explicitly owns the refined boundary
        // topology. Use those source-authoritative loops to define corner and
        // edge-point valence instead of the geometry-only angle heuristic.
        for (const int vertex : aggregateLineageMesh.boundaryVertices) {
          if (vertex >= 0 && vertex < completedVertices.rows()) {
            constraints.boundaryValenceTargets[vertex] = static_cast<int>(
                recoveredNeighbors[static_cast<std::size_t>(vertex)].size());
          }
        }
      }
      constraints.requireSourceAuthoritativeValidation = true;
      geometry::fill_required_singularity_valence_targets(
          meshWhole.V, meshWhole.F,
          result.surfaceCellContext.crossField.singularCycles,
          result.surfaceCellContext.crossField.singularIndices,
          completedVertices, completedProvenance, constraints);
      geometry::SurfaceOptimizationOptions optimizationOptions;
      optimizationOptions.targetSize = effectiveOptimizationTargetSize;
      optimizationOptions.maxIterations =
          std::max(0, options.surfaceCells.optimizerMaxIterations);
      optimizationOptions.maxLineSearchTrials =
          std::max(0, options.surfaceCells.optimizerMaxLineSearchTrials);
      optimizationOptions.enforceOptimizerTimeGate =
          options.surfaceCells.enforceOptimizerTimeGate;
      optimizationOptions.maxOptimizerTimeRatio =
          options.surfaceCells.maxOptimizerTimeRatio;
      geometry::SurfaceOptimizationResult optimization =
          geometry::optimize_projected_surface_mesh(completedVertices,
                                                    completedQuads,
                                                    constraints,
                                                    optimizationOptions);
      const auto optimizationEnd = Clock::now();
      const double optimizationSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              optimizationEnd - optimizationStart)
              .count() /
          1.0e6;
      const auto validationStart = Clock::now();
      geometry::SurfaceFinalValidationReport validation =
          geometry::validate_final_surface_mesh(optimization.vertices,
                                                optimization.quads,
                                                constraints, optimization,
                                                optimizationOptions,
                                                optimizationSeconds,
                                                std::numeric_limits<double>::infinity());
      if (!validation.accepted &&
          result.surfaceCellContext.sourceGridRecoveryUsed) {
        geometry::SurfaceOptimizationResult recovered = optimization;
        recovered.vertices = completedVertices;
        recovered.quads = completedQuads;
        recovered.vertexProvenance = completedProvenance;
        recovered.finalEnergy =
            geometry::evaluate_surface_optimization_energy(
                recovered.vertices, recovered.quads, constraints,
                optimizationOptions);
        recovered.rolledBackToInput = true;
        geometry::SurfaceFinalValidationReport recoveredValidation =
            geometry::validate_final_surface_mesh(
                recovered.vertices, recovered.quads, constraints, recovered,
                optimizationOptions, optimizationSeconds,
                std::numeric_limits<double>::infinity());
        if (recoveredValidation.accepted) {
          optimization = std::move(recovered);
          validation = std::move(recoveredValidation);
        }
      }
      const auto validationEnd = Clock::now();
      const double endToEndSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              validationEnd - pipelineStart)
              .count() /
          1.0e6;
      validation.optimizerTimeWithinGate =
          optimizationSeconds <=
          optimizationOptions.maxOptimizerTimeRatio *
              std::max(1.0e-12, endToEndSeconds);
      if (optimizationOptions.enforceOptimizerTimeGate &&
          !validation.optimizerTimeWithinGate) {
        validation.accepted = false;
      }
      result.diagnostics.surfaceCellOptimizationIterationCount =
          optimization.iterations.size();
      result.diagnostics.surfaceCellOptimizationSeconds = optimizationSeconds;
      result.diagnostics.surfaceCellOptimizationIterationCountAvailable = true;
      result.diagnostics.surfaceCellProvenanceVertexCount =
          optimization.vertexProvenance.size();
      result.diagnostics.surfaceCellProvenanceVertexCountAvailable = true;
      std::uint64_t optimizationHash = structural_hash_seed("optimization");
      hash_combine_u64(optimizationHash, completionIdentity.structuralHash);
      hash_matrix(optimizationHash, optimization.vertices);
      hash_matrix(optimizationHash, optimization.quads);
      result.surfaceCellContext.optimizationResult = optimization;
      result.surfaceCellContext.hasOptimizationResult = true;
      const SurfaceCellObjectIdentity optimizationIdentity = make_identity(
          "optimization", optimizationHash,
          static_cast<std::size_t>(optimization.quads.rows()));
      mark_stage_consumed("completion", completionIdentity,
                          SurfaceCellConsumptionKind::Full);
      record_surface_cell_stage("optimization", completionIdentity,
                                optimizationIdentity, true,
                                result.diagnostics.surfaceCellOptimizationSeconds);

      completedSurfaceCellStages.push_back("optimization");
      if (options.surfaceCells.injectFailureAfterStage == 9) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "optimization");
      }
      result.surfaceCellContext.validationResult = validation;
      result.surfaceCellContext.hasValidationResult = true;
      result.diagnostics.surfaceCellValidationSeconds =
          std::chrono::duration<double>(validationEnd - validationStart).count();
      result.diagnostics.surfaceCellValidationFailures =
          surface_cell_validation_failure_count(
              validation, optimizationOptions.enforceOptimizerTimeGate);
      result.diagnostics.surfaceCellValidationFailureCountAvailable = true;
      std::uint64_t validationHash = hash_surface_cell_validation(
          validation, optimizationOptions.enforceOptimizerTimeGate);
      hash_combine_u64(validationHash, optimizationIdentity.structuralHash);
      const SurfaceCellObjectIdentity validationIdentity = make_identity(
          "validation", validationHash,
          static_cast<std::size_t>(optimization.quads.rows()));
      mark_stage_consumed("optimization", optimizationIdentity,
                          SurfaceCellConsumptionKind::Full);
      record_surface_cell_stage("validation", optimizationIdentity,
                                validationIdentity, true,
                                result.diagnostics.surfaceCellValidationSeconds);
      completedSurfaceCellStages.push_back("validation");
      if (options.surfaceCells.injectFailureAfterStage == 10) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "validation");
      }
      if (validation.accepted) {
        result.success = true;
        result.vertices = optimization.vertices;
        result.faces = optimization.quads;
        result.degrees = Eigen::VectorXi::Constant(optimization.quads.rows(), 4);
        result.outputVertexProvenance = optimization.vertexProvenance;
        result.outputVertexLineage = completedVertexLineage;
        result.outputQuadLineage = completedQuadLineage;
        result.diagnostics.surfaceCellRemeshOccurred = true;
        result.diagnostics.surfaceCellSourceGridRecoveryUsed =
            result.surfaceCellContext.sourceGridRecoveryUsed;
        result.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::CompletedSurfaceCells;
        result.diagnostics.terminalFailureCode = "None";
        result.diagnostics.terminalFailureStage.clear();

        update_overall_pipeline_time();
        record_face_degree_histogram(result);
        return result;
      }
    } else {
      result.diagnostics.surfaceCellOptimizationIterationCount = 0U;
    }
    if (!result.diagnostics.surfaceCellOptimizationIterationCountAvailable) {
      result.diagnostics.surfaceCellOptimizationSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              Clock::now() - optimizationStart)
              .count() /
          1.0e6;
      result.diagnostics.surfaceCellOptimizationIterationCountAvailable = true;
      const SurfaceCellObjectIdentity emptyOptimizationIdentity = make_identity(
          "optimization", structural_hash_seed("optimization"), 0U);
      mark_stage_consumed("completion", completionIdentity,
                          SurfaceCellConsumptionKind::Full);
      record_surface_cell_stage("optimization", completionIdentity,
                                emptyOptimizationIdentity, true,
                                result.diagnostics.surfaceCellOptimizationSeconds);

      completedSurfaceCellStages.push_back("optimization");
      if (options.surfaceCells.injectFailureAfterStage == 9) {
        return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                  "optimization");
      }
    }

    return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                              "validation");
  }
  const auto log_phase = [&](const char *label) {
    const auto now = Clock::now();
    const auto phaseSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now - phaseStart)
            .count() /
        1e+6;
    const auto totalSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(now -
                                                              pipelineStart)
            .count() /
        1e+6;
    if (options.verbose) {
      std::cout
          << "[Directional::pipeline::remesh_from_raw_cross_field_impl()]: "
          << label << " completed in " << phaseSeconds << " s (total "
          << totalSeconds << " s)" << std::endl;
    }
    phaseStart = now;
    return phaseSeconds;
  };
  directional::RemeshDiagnostics diagnostics;
  diagnostics.remeshBackend = remesh_backend_name(RemeshBackend::LegacyInteger);
  diagnostics.requestedBackend =
      remesh_backend_name(RemeshBackend::LegacyInteger);
  diagnostics.executedBackend = remesh_backend_name(RemeshBackend::LegacyInteger);
  diagnostics.surfaceCellFallbackPolicy =
      surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);

  // if (options.featureAlign) {
  //   throw std::runtime_error("featureAlign is not supported by the headless "
  //                            "Directional pipeline yet.");
  // }
  if (rawCrossField.rows() != meshWhole.F.rows() ||
      rawCrossField.cols() != 12) {
    throw std::runtime_error(
        "rawCrossField must have shape (#F, 12) for a 4-RoSy cross field.");
  }

  TriMesh workingMesh = meshWhole;
  Eigen::MatrixXd workingRawCrossField = rawCrossField;
  if (options.preconditionInputMesh) {
    report_progress(options.progress, 3, 100, "Preconditioning input mesh");
    geometry::BoundedMeshPreconditionerOptions preconditionOptions;
    preconditionOptions.enabled = true;
    preconditionOptions.targetFaceRatio = options.preconditionTargetFaceRatio;
    preconditionOptions.maxFaceRatio = options.preconditionMaxFaceRatio;
    preconditionOptions.minFaceRatio = options.preconditionMinFaceRatio;
    preconditionOptions.sharpAngleDegrees =
        options.preconditionSharpAngleDegrees;
    preconditionOptions.featureMap = options.featureMap;
    const geometry::BoundedMeshPreconditionerResult preconditioned =
        geometry::BoundedMeshPreconditioner::precondition(
            meshWhole.V, meshWhole.F, preconditionOptions);
    diagnostics.preconditioningSeconds += log_phase("input preconditioning");
    copy_adaptive_feature_diagnostics(diagnostics, preconditioned);
    diagnostics.preconditioningFlipsAccepted = preconditioned.flipsAccepted;
    diagnostics.preconditioningCollapsesAccepted =
        preconditioned.collapsesAccepted;
    diagnostics.preconditioningSplitsAccepted = preconditioned.splitsAccepted;
    diagnostics.preconditioningInputTriangleCount =
        preconditioned.inputTriangleCount;
    diagnostics.preconditioningOutputTriangleCount =
        preconditioned.outputTriangleCount;
    diagnostics.preconditioningMinAngleBefore =
        preconditioned.before.minTriangleAngleDegrees;
    diagnostics.preconditioningMinAngleAfter =
        preconditioned.after.minTriangleAngleDegrees;
    diagnostics.preconditioningAspectRatioP95Before =
        preconditioned.before.aspectRatioP95;
    diagnostics.preconditioningAspectRatioP95After =
        preconditioned.after.aspectRatioP95;
    diagnostics.preconditioningAspectRatioP99Before =
        preconditioned.before.aspectRatioP99;
    diagnostics.preconditioningAspectRatioP99After =
        preconditioned.after.aspectRatioP99;
    diagnostics.preconditioningEdgeLengthCvBefore =
        preconditioned.before.edgeLengthCoefficientOfVariation;
    diagnostics.preconditioningEdgeLengthCvAfter =
        preconditioned.after.edgeLengthCoefficientOfVariation;
    try {
      workingMesh.set_mesh(preconditioned.vertices, preconditioned.faces);
      workingRawCrossField =
          fields::CrossFieldTransfer::transfer_raw_field_nearest_face(
              meshWhole, rawCrossField, workingMesh,
              options.normalizeDirections);
      diagnostics.fieldSetupSeconds += log_phase("cross-field transfer");
    } catch (const std::exception &) {
      workingMesh = meshWhole;
      workingRawCrossField = rawCrossField;
      diagnostics.preconditioningFlipsAccepted = 0;
      diagnostics.preconditioningCollapsesAccepted = 0;
      diagnostics.preconditioningSplitsAccepted = 0;
      diagnostics.preconditioningOutputTriangleCount =
          static_cast<std::size_t>(meshWhole.F.rows());
      diagnostics.preconditioningMinAngleAfter =
          diagnostics.preconditioningMinAngleBefore;
      diagnostics.preconditioningAspectRatioP95After =
          diagnostics.preconditioningAspectRatioP95Before;
      diagnostics.preconditioningAspectRatioP99After =
          diagnostics.preconditioningAspectRatioP99Before;
      diagnostics.preconditioningEdgeLengthCvAfter =
          diagnostics.preconditioningEdgeLengthCvBefore;
      log_phase("discard invalid preconditioning output");
    }
  } else {
    diagnostics.preconditioningInputTriangleCount =
        static_cast<std::size_t>(meshWhole.F.rows());
    diagnostics.preconditioningOutputTriangleCount =
        static_cast<std::size_t>(meshWhole.F.rows());
  }

  report_progress(options.progress, 5, 100, "Initializing tangent bundle");
  PCFaceTangentBundle tangentBundle;
  tangentBundle.init(workingMesh);
  diagnostics.tangentBundleInitializationSeconds +=
      log_phase("PCFaceTangentBundle::init");

  report_progress(options.progress, 10, 100, "Preparing raw cross field");
  CartesianField rawField;
  rawField.init(tangentBundle, fieldTypeEnum::RAW_FIELD, 4);
  rawField.set_extrinsic_field(workingRawCrossField);
  diagnostics.fieldSetupSeconds +=
      log_phase("CartesianField::init + set_extrinsic_field");
  report_progress(options.progress, 15, 100, "Computing field matching");
  principal_matching(rawField);
  diagnostics.principalMatchingSeconds += log_phase("principal_matching");

  IntegrationData integration(4);
  integration.lengthRatio = options.lengthRatio;
  integration.absoluteTargetLength = options.absoluteTargetLength;
  integration.integralSeamless = options.integralSeamless;
  integration.roundSeams = options.roundSeams;
  integration.verbose = options.verbose;
  integration.solveStrategy = options.integrationSolveStrategy;
  integration.adaptiveOptions = options.adaptiveIntegration;
  integration.integerBatchOptions = options.integerBatching;
  integration.integerTransitionBasisOptions = options.integerTransitionBasis;
  integration.targetedStiffening = options.targetedStiffening;
  integration.targetedStiffening.enabled =
      options.useTargetedParametrizationStiffening &&
      options.targetedStiffening.enabled;
  integration.skipConstraintRankReduction = options.skipConstraintRankReduction;

  report_progress(options.progress, 20, 100, "Setting up integration");
  TriMesh meshCut;
  CartesianField combedField;
  setup_integration(rawField, integration, meshCut, combedField);
  diagnostics.setupIntegrationSeconds += log_phase("setup_integration");

  report_progress(options.progress, 21, 100, "Solving field integration");
  if (!options.verbose && options.progress) {
    integration.progress =
        [callback = options.progress](const std::size_t current,
                                      const std::size_t total,
                                      const std::string_view task) {
          constexpr std::size_t first = 21;
          constexpr std::size_t last = 75;
          const std::size_t safeTotal = std::max<std::size_t>(total, 1);
          const std::size_t safeCurrent =
              std::min(std::max<std::size_t>(current, 1), safeTotal);
          const std::size_t mapped =
              safeTotal == 1
                  ? last
                  : first + (safeCurrent - 1) * (last - first) /
                                (safeTotal - 1);
          report_progress(callback, mapped, 100, task);
        };
  }
  Eigen::MatrixXd cutFunctions;
  Eigen::MatrixXd cutCornerFunctions;
  if (!integrate(combedField, integration, meshCut, cutFunctions,
                 cutCornerFunctions)) {
    throw std::runtime_error(
        "Field integration failed; the mesher cannot continue.");
  }
  diagnostics.integrationTotalSeconds += log_phase("integrate");
  diagnostics.integration = integration.diagnostics;

  if (options.stopAfterIntegration) {
    RemeshResult result;
    result.success = true;
    result.rawCrossField = rawField.extField;
    result.crossFieldMatching = rawField.matching;
    result.crossFieldEffort = rawField.effort;
    result.crossFieldSingularCycles = rawField.singLocalCycles;
    result.crossFieldSingularIndices = rawField.singIndices;
    result.cutVertices = meshCut.V;
    result.cutFaces = meshCut.F;
    result.cutFunctions = cutFunctions;
    result.cutCornerFunctions = cutCornerFunctions;
    diagnostics.overallPipelineSeconds = remesh_elapsed_seconds(pipelineStart);
    diagnostics.overallPipelineTimeAvailable = true;
    result.diagnostics = diagnostics;
    report_progress(options.progress, 100, 100,
                    "Finalizing integration-only result");
    return result;
  }

  report_progress(options.progress, 80, 100, "Preparing mesher");
  MesherData mesherData;
  mesherData.verbose = options.verbose;
  mesherData.simplificationBackend =
      options.useTriFlowDcelSimplification
          ? MesherSimplificationBackend::TriFlowDCEL
          : MesherSimplificationBackend::Directional;
  mesherData.useFunctionSkeletonCleanup = options.useFunctionSkeletonCleanup;
  mesherData.useLocalPatchPrevalidation = options.useLocalPatchPrevalidation;
  mesherData.useLocalPatchQuadrangulationFallback =
      options.useLocalPatchQuadrangulationFallback;
  if (!options.verbose && options.progress) {
    mesherData.progress =
        [callback = options.progress](const std::size_t current,
                                      const std::size_t total,
                                      const std::string_view task) {
          constexpr std::size_t first = 81;
          constexpr std::size_t last = 99;
          const std::size_t safeTotal = std::max<std::size_t>(total, 1);
          const std::size_t safeCurrent =
              std::min(current, safeTotal);
          const std::size_t mapped =
              first + safeCurrent * (last - first) / safeTotal;
          report_progress(callback, mapped, 100, task);
        };
  }
  setup_mesher(meshCut, integration, mesherData);
  diagnostics.setupMesherSeconds += log_phase("setup_mesher");
  if (options.mesherDataCallback) {
    options.mesherDataCallback(mesherData);
  }

  RemeshResult result;
  result.rawCrossField = rawField.extField;
  result.crossFieldMatching = rawField.matching;
  result.crossFieldEffort = rawField.effort;
  result.crossFieldSingularCycles = rawField.singLocalCycles;
  result.crossFieldSingularIndices = rawField.singIndices;
  result.cutVertices = meshCut.V;
  result.cutFaces = meshCut.F;
  result.cutFunctions = cutFunctions;
  result.cutCornerFunctions = cutCornerFunctions;
  report_progress(options.progress, 81, 100, "Generating output mesh");
  result.success = mesher(workingMesh, mesherData, result.vertices,
                          result.degrees, result.faces);
  diagnostics.mesherTotalSeconds += log_phase("mesher");
  diagnostics.mesher = mesherData.diagnostics;
  diagnostics.overallPipelineSeconds = remesh_elapsed_seconds(pipelineStart);
  diagnostics.overallPipelineTimeAvailable = true;
  result.diagnostics = diagnostics;
  record_face_degree_histogram(result);
  report_progress(options.progress, 100, 100, "Finalizing remesh result");
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult remesh_surface_cells_from_cross_field_impl(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const RemeshOptions &options) {
  return remesh_from_raw_cross_field_impl(meshWhole, crossField.rawField,
                                          options, &crossField);
}

} // namespace directional::pipeline

namespace directional::pipeline {

double derive_absolute_target_length(const Eigen::MatrixXd &vertices,
                                            const RemeshOptions &options) {
  if (options.absoluteTargetLength >= 0.0) {
    return options.absoluteTargetLength;
  }
  if (vertices.rows() == 0) {
    return 0.0;
  }
  return (vertices.colwise().maxCoeff() - vertices.colwise().minCoeff())
             .norm() *
         options.lengthRatio;
}

} // namespace directional::pipeline

namespace directional::pipeline {

fields::CrossFieldResult remap_surface_cell_cross_field_component(
    const TriMesh &sourceMesh, const geometry::FaceComponent &component,
    const TriMesh &componentMesh,
    const fields::CrossFieldResult &sourceCrossField) {
  fields::CrossFieldResult local;
  local.degree = sourceCrossField.degree;

  const Eigen::Index localFaceCount =
      static_cast<Eigen::Index>(component.originalFaces.size());
  auto copy_face_rows = [&](const Eigen::MatrixXd &source,
                            Eigen::MatrixXd &target) {
    if (source.rows() != sourceMesh.F.rows()) {
      target.resize(0, source.cols());
      return;
    }
    target.resize(localFaceCount, source.cols());
    for (Eigen::Index localFace = 0; localFace < localFaceCount; ++localFace) {
      target.row(localFace) =
          source.row(component.originalFaces[static_cast<std::size_t>(
              localFace)]);
    }
  };
  copy_face_rows(sourceCrossField.rawField, local.rawField);
  copy_face_rows(sourceCrossField.primaryDirections, local.primaryDirections);
  copy_face_rows(sourceCrossField.secondaryDirections,
                 local.secondaryDirections);

  if (sourceCrossField.confidence.rows() == sourceMesh.F.rows()) {
    local.confidence.resize(localFaceCount);
    for (Eigen::Index localFace = 0; localFace < localFaceCount; ++localFace) {
      local.confidence(localFace) =
          sourceCrossField.confidence(
              component.originalFaces[static_cast<std::size_t>(localFace)]);
    }
  }

  std::map<int, int> localFaceByOriginal;
  for (std::size_t localFace = 0;
       localFace < component.originalFaces.size(); ++localFace) {
    localFaceByOriginal[component.originalFaces[localFace]] =
        static_cast<int>(localFace);
  }
  std::map<int, int> localVertexByOriginal;
  for (std::size_t localVertex = 0;
       localVertex < component.originalVertices.size(); ++localVertex) {
    localVertexByOriginal[component.originalVertices[localVertex]] =
        static_cast<int>(localVertex);
  }

  std::vector<int> uncovered;
  for (Eigen::Index index = 0;
       index < sourceCrossField.uncoveredFaces.size(); ++index) {
    const auto found =
        localFaceByOriginal.find(sourceCrossField.uncoveredFaces(index));
    if (found != localFaceByOriginal.end()) {
      uncovered.push_back(found->second);
    }
  }
  local.uncoveredFaces.resize(static_cast<Eigen::Index>(uncovered.size()));
  for (Eigen::Index index = 0; index < local.uncoveredFaces.size(); ++index) {
    local.uncoveredFaces(index) =
        uncovered[static_cast<std::size_t>(index)];
  }

  std::vector<int> singularCycles;
  std::vector<int> singularIndices;
  const Eigen::Index singularCount =
      std::min(sourceCrossField.singularCycles.size(),
               sourceCrossField.singularIndices.size());
  for (Eigen::Index index = 0; index < singularCount; ++index) {
    const auto found =
        localVertexByOriginal.find(sourceCrossField.singularCycles(index));
    if (found == localVertexByOriginal.end()) {
      continue;
    }
    singularCycles.push_back(found->second);
    singularIndices.push_back(sourceCrossField.singularIndices(index));
  }
  local.singularCycles.resize(
      static_cast<Eigen::Index>(singularCycles.size()));
  local.singularIndices.resize(
      static_cast<Eigen::Index>(singularIndices.size()));
  for (Eigen::Index index = 0; index < local.singularCycles.size(); ++index) {
    local.singularCycles(index) =
        singularCycles[static_cast<std::size_t>(index)];
    local.singularIndices(index) =
        singularIndices[static_cast<std::size_t>(index)];
  }

  std::map<std::uint64_t, int> sourceEdgeByVertices;
  for (int edge = 0; edge < sourceMesh.EV.rows(); ++edge) {
    sourceEdgeByVertices[surface_cell_source_edge_key(
        sourceMesh.EV(edge, 0), sourceMesh.EV(edge, 1))] = edge;
  }

  if (sourceCrossField.matching.size() == sourceMesh.EF.rows() &&
      sourceCrossField.effort.size() == sourceMesh.EF.rows()) {
    local.matching.resize(componentMesh.EF.rows());
    local.effort.resize(componentMesh.EF.rows());
    local.edgeTransitions.reserve(
        static_cast<std::size_t>(componentMesh.EF.rows()));
    for (int localEdge = 0; localEdge < componentMesh.EV.rows();
         ++localEdge) {
      const int originalVertex0 = component.originalVertices[
          static_cast<std::size_t>(componentMesh.EV(localEdge, 0))];
      const int originalVertex1 = component.originalVertices[
          static_cast<std::size_t>(componentMesh.EV(localEdge, 1))];
      const auto found = sourceEdgeByVertices.find(
          surface_cell_source_edge_key(originalVertex0, originalVertex1));
      if (found == sourceEdgeByVertices.end()) {
        local.matching.resize(0);
        local.effort.resize(0);
        local.edgeTransitions.clear();
        break;
      }

      const int sourceEdge = found->second;
      local.matching(localEdge) = sourceCrossField.matching(sourceEdge);
      local.effort(localEdge) = sourceCrossField.effort(sourceEdge);

      fields::CrossFieldEdgeTransition transition;
      transition.sourceEdge = localEdge;
      transition.sourceVertex0 = componentMesh.EV(localEdge, 0);
      transition.sourceVertex1 = componentMesh.EV(localEdge, 1);
      transition.firstFace = componentMesh.EF(localEdge, 0);
      transition.secondFace = componentMesh.EF(localEdge, 1);
      transition.matching = local.matching(localEdge);
      transition.effort = local.effort(localEdge);
      local.edgeTransitions.push_back(transition);
    }
  }

  local.matchingComputed = sourceCrossField.matchingComputed;
  local.singularitiesComputed = sourceCrossField.singularitiesComputed;
  local.confidenceComputed = sourceCrossField.confidenceComputed;
  local.uncoveredFacePolicyApplied =
      sourceCrossField.uncoveredFacePolicyApplied;
  normalize_surface_cell_cross_field_directions(local);
  return local;
}

} // namespace directional::pipeline

namespace directional::pipeline {

geometry::SurfacePoint remap_component_surface_point(
    geometry::SurfacePoint point, const geometry::FaceComponent &component,
    const std::size_t componentIndex, const int sheetOffset) {
  if (point.face >= 0 &&
      static_cast<std::size_t>(point.face) < component.originalFaces.size()) {
    point.face =
        component.originalFaces[static_cast<std::size_t>(point.face)];
  } else {
    point.face = -1;
  }
  point.component = static_cast<int>(componentIndex);
  if (point.sheet >= 0) {
    point.sheet += sheetOffset;
  }
  return point;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void append_polygon_faces(
    Eigen::MatrixXi &targetFaces, Eigen::VectorXi &targetDegrees,
    const Eigen::MatrixXi &sourceFaces, const Eigen::VectorXi &sourceDegrees,
    const int vertexOffset) {
  if (sourceFaces.rows() == 0) {
    return;
  }
  const Eigen::Index oldRows = targetFaces.rows();
  const Eigen::Index oldColumns = targetFaces.cols();
  const Eigen::Index newColumns =
      std::max(oldColumns, sourceFaces.cols());
  if (oldRows == 0) {
    targetFaces =
        Eigen::MatrixXi::Constant(sourceFaces.rows(), newColumns, -1);
  } else {
    targetFaces.conservativeResize(oldRows + sourceFaces.rows(), newColumns);
    if (newColumns > oldColumns) {
      targetFaces.block(0, oldColumns, oldRows, newColumns - oldColumns)
          .setConstant(-1);
    }
    targetFaces.block(oldRows, 0, sourceFaces.rows(), newColumns)
        .setConstant(-1);
  }

  const Eigen::Index oldDegreeCount = targetDegrees.size();
  targetDegrees.conservativeResize(oldDegreeCount + sourceFaces.rows());
  for (Eigen::Index face = 0; face < sourceFaces.rows(); ++face) {
    const int degree =
        sourceDegrees.size() == sourceFaces.rows()
            ? sourceDegrees(face)
            : static_cast<int>(sourceFaces.cols());
    targetDegrees(oldDegreeCount + face) = degree;
    for (int corner = 0;
         corner < degree && corner < sourceFaces.cols(); ++corner) {
      const int sourceVertex = sourceFaces(face, corner);
      targetFaces(oldRows + face, corner) =
          sourceVertex >= 0 ? sourceVertex + vertexOffset : -1;
    }
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void accumulate_surface_optimization_energy(
    geometry::SurfaceOptimizationEnergy &target,
    const geometry::SurfaceOptimizationEnergy &source) {
  target.surface += source.surface;
  target.normal += source.normal;
  target.field += source.field;
  target.orthogonality += source.orthogonality;
  target.size += source.size;
  target.valenceShape += source.valenceShape;
  target.feature += source.feature;
  target.total += source.total;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void accumulate_surface_optimization_result(
    geometry::SurfaceOptimizationResult &target,
    const geometry::SurfaceOptimizationResult &source,
    const bool firstComponent) {
  if (firstComponent) {
    target.monotonicEnergy = source.monotonicEnergy;
    target.topologyHashFixed = source.topologyHashFixed;
    target.featureParametersOrdered = source.featureParametersOrdered;
    target.projectionStayedOnComponents =
        source.projectionStayedOnComponents;
    target.projectionStayedOnSheets = source.projectionStayedOnSheets;
    target.projectionHasCompleteProvenance =
        source.projectionHasCompleteProvenance;
  } else {
    target.monotonicEnergy =
        target.monotonicEnergy && source.monotonicEnergy;
    target.topologyHashFixed =
        target.topologyHashFixed && source.topologyHashFixed;
    target.featureParametersOrdered =
        target.featureParametersOrdered && source.featureParametersOrdered;
    target.projectionStayedOnComponents =
        target.projectionStayedOnComponents &&
        source.projectionStayedOnComponents;
    target.projectionStayedOnSheets =
        target.projectionStayedOnSheets && source.projectionStayedOnSheets;
    target.projectionHasCompleteProvenance =
        target.projectionHasCompleteProvenance &&
        source.projectionHasCompleteProvenance;
  }
  target.sourceTriangleProjectionUsed =
      target.sourceTriangleProjectionUsed ||
      source.sourceTriangleProjectionUsed;
  target.rolledBackToInput =
      target.rolledBackToInput || source.rolledBackToInput;
  target.directGradientUsed =
      target.directGradientUsed || source.directGradientUsed;
  target.directGradientEvaluationCount +=
      source.directGradientEvaluationCount;
  target.sourceBvhBuildCount += source.sourceBvhBuildCount;
  target.projectionQueryCount += source.projectionQueryCount;
  target.lineSearchTrialCount += source.lineSearchTrialCount;
  target.lineSearchRejectionCount += source.lineSearchRejectionCount;
  target.projectionConstraintRejectionCount +=
      source.projectionConstraintRejectionCount;
  target.orientationRejectionCount += source.orientationRejectionCount;
  target.armijoRejectionCount += source.armijoRejectionCount;
  target.hardInvariantRejectionCount +=
      source.hardInvariantRejectionCount;
  accumulate_surface_optimization_energy(target.initialEnergy,
                                         source.initialEnergy);
  accumulate_surface_optimization_energy(target.finalEnergy,
                                         source.finalEnergy);
  for (geometry::SurfaceOptimizationIteration iteration : source.iterations) {
    iteration.iteration = static_cast<int>(target.iterations.size());
    target.iterations.push_back(std::move(iteration));
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

void accumulate_surface_validation_report(
    geometry::SurfaceFinalValidationReport &target,
    const geometry::SurfaceFinalValidationReport &source,
    const bool firstComponent) {
  if (firstComponent) {
    target = source;
    return;
  }
  target.accepted = target.accepted && source.accepted;
  target.quadToSourceP95 =
      std::max(target.quadToSourceP95, source.quadToSourceP95);
  target.quadToSourceMax =
      std::max(target.quadToSourceMax, source.quadToSourceMax);
  target.sourceToOutputP95 =
      std::max(target.sourceToOutputP95, source.sourceToOutputP95);
  target.sourceToOutputMax =
      std::max(target.sourceToOutputMax, source.sourceToOutputMax);
  target.surfaceP95 = std::max(target.surfaceP95, source.surfaceP95);
  target.surfaceMax = std::max(target.surfaceMax, source.surfaceMax);
  target.normalP95Degrees =
      std::max(target.normalP95Degrees, source.normalP95Degrees);
  target.featureP95 = std::max(target.featureP95, source.featureP95);
  target.featureMax = std::max(target.featureMax, source.featureMax);
  target.featureTangentP95Degrees =
      std::max(target.featureTangentP95Degrees,
               source.featureTangentP95Degrees);
  target.fieldMedianDegrees =
      std::max(target.fieldMedianDegrees, source.fieldMedianDegrees);
  target.fieldP95Degrees =
      std::max(target.fieldP95Degrees, source.fieldP95Degrees);
  target.sizeP5 = std::min(target.sizeP5, source.sizeP5);
  target.sizeP95 = std::max(target.sizeP95, source.sizeP95);
  target.angleMinDegrees =
      std::min(target.angleMinDegrees, source.angleMinDegrees);
  target.angleMaxDegrees =
      std::max(target.angleMaxDegrees, source.angleMaxDegrees);
  target.angleP5Degrees =
      std::min(target.angleP5Degrees, source.angleP5Degrees);
  target.angleP95Degrees =
      std::max(target.angleP95Degrees, source.angleP95Degrees);
  target.warpageP95Degrees =
      std::max(target.warpageP95Degrees, source.warpageP95Degrees);
  target.warpageMaxDegrees =
      std::max(target.warpageMaxDegrees, source.warpageMaxDegrees);
  target.aspectP95 = std::max(target.aspectP95, source.aspectP95);
  target.aspectP99 = std::max(target.aspectP99, source.aspectP99);
  target.scaledJacobianMin =
      std::min(target.scaledJacobianMin, source.scaledJacobianMin);
  target.scaledJacobianP5 =
      std::min(target.scaledJacobianP5, source.scaledJacobianP5);
  target.tJunctions += source.tJunctions;
  target.nonManifold += source.nonManifold;
  target.degenerate += source.degenerate;
  target.inverted += source.inverted;
  target.selfIntersecting += source.selfIntersecting;
  target.nonConvex += source.nonConvex;
  target.boundaryValenceTargetCount += source.boundaryValenceTargetCount;
  target.boundaryValenceMismatchCount += source.boundaryValenceMismatchCount;
  target.requiredSingularityValenceTargetCount +=
      source.requiredSingularityValenceTargetCount;
  target.requiredSingularityValenceMismatchCount +=
      source.requiredSingularityValenceMismatchCount;
  target.quadToSourceSampleCount += source.quadToSourceSampleCount;
  target.sourceToOutputSampleCount += source.sourceToOutputSampleCount;
  target.topologyHashFixed =
      target.topologyHashFixed && source.topologyHashFixed;
  target.featureParametersOrdered =
      target.featureParametersOrdered && source.featureParametersOrdered;
  target.projectionStayedOnComponents =
      target.projectionStayedOnComponents &&
      source.projectionStayedOnComponents;
  target.optimizerTimeWithinGate =
      target.optimizerTimeWithinGate && source.optimizerTimeWithinGate;
  target.strictValidationUsed =
      target.strictValidationUsed && source.strictValidationUsed;
  target.authoritativeBoundaryUsed =
      target.authoritativeBoundaryUsed && source.authoritativeBoundaryUsed;
  target.authoritativeFeatureRailsUsed =
      target.authoritativeFeatureRailsUsed &&
      source.authoritativeFeatureRailsUsed;
  target.provenanceValidationUsed =
      target.provenanceValidationUsed && source.provenanceValidationUsed;
  target.sourceAuthoritativeValidationUsed =
      target.sourceAuthoritativeValidationUsed &&
      source.sourceAuthoritativeValidationUsed;
  target.spatialAccelerationUsed =
      target.spatialAccelerationUsed && source.spatialAccelerationUsed;
  target.orderedBoundaryCyclesPassed =
      target.orderedBoundaryCyclesPassed &&
      source.orderedBoundaryCyclesPassed;
  target.authoritativeFeatureRailsPassed =
      target.authoritativeFeatureRailsPassed &&
      source.authoritativeFeatureRailsPassed;
  target.localSheetCompatibilityPassed =
      target.localSheetCompatibilityPassed &&
      source.localSheetCompatibilityPassed;
  target.connectedComponentMismatchCount +=
      source.connectedComponentMismatchCount;
  target.eulerCharacteristicMismatchCount +=
      source.eulerCharacteristicMismatchCount;
  target.boundaryCycleMismatchCount += source.boundaryCycleMismatchCount;
  target.featureRailMismatchCount += source.featureRailMismatchCount;
  target.provenanceFailureCount += source.provenanceFailureCount;
  target.localSheetMismatchCount += source.localSheetMismatchCount;
  target.duplicateFaceCount += source.duplicateFaceCount;
  target.bowTieVertexCount += source.bowTieVertexCount;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void append_matrix_rows(Eigen::MatrixXd &target,
                               const Eigen::MatrixXd &source) {
  if (source.rows() == 0) {
    return;
  }
  if (target.rows() == 0) {
    target = source;
    return;
  }
  const Eigen::Index oldRows = target.rows();
  target.conservativeResize(oldRows + source.rows(), source.cols());
  target.block(oldRows, 0, source.rows(), source.cols()) = source;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void append_matrix_rows(Eigen::MatrixXi &target,
                               const Eigen::MatrixXi &source,
                               const int indexOffset) {
  if (source.rows() == 0) {
    return;
  }
  Eigen::MatrixXi shifted = source;
  if (indexOffset != 0) {
    shifted.array() += indexOffset;
  }
  if (target.rows() == 0) {
    target = shifted;
    return;
  }
  const Eigen::Index oldRows = target.rows();
  target.conservativeResize(oldRows + shifted.rows(), shifted.cols());
  target.block(oldRows, 0, shifted.rows(), shifted.cols()) = shifted;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void append_vector(Eigen::VectorXi &target,
                          const Eigen::VectorXi &source) {
  if (source.size() == 0) {
    return;
  }
  if (target.size() == 0) {
    target = source;
    return;
  }
  const Eigen::Index oldRows = target.size();
  target.conservativeResize(oldRows + source.size());
  target.segment(oldRows, source.size()) = source;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void append_vector(Eigen::VectorXd &target,
                          const Eigen::VectorXd &source) {
  if (source.size() == 0) {
    return;
  }
  if (target.size() == 0) {
    target = source;
    return;
  }
  const Eigen::Index oldRows = target.size();
  target.conservativeResize(oldRows + source.size());
  target.segment(oldRows, source.size()) = source;
}

} // namespace directional::pipeline

namespace directional::pipeline {

void accumulate_component_diagnostics(
    directional::RemeshDiagnostics &target,
    const directional::RemeshDiagnostics &source,
    const std::size_t componentIndex,
    const bool firstComponent) {
  if (target.terminalFailureCode == "None" &&
      source.terminalFailureCode != "None") {
    target.terminalFailureCode = source.terminalFailureCode;
    target.terminalFailureStage = source.terminalFailureStage;
  }
  if (source.originalSurfaceCellFailureCode != "None") {
    if (target.originalSurfaceCellFailureCode == "None") {
      target.originalSurfaceCellFailureCode =
          source.originalSurfaceCellFailureCode;
      target.originalSurfaceCellFailureStage =
          source.originalSurfaceCellFailureStage;
    } else if (target.originalSurfaceCellFailureCode !=
                   source.originalSurfaceCellFailureCode ||
               target.originalSurfaceCellFailureStage !=
                   source.originalSurfaceCellFailureStage) {
      target.originalSurfaceCellFailureCode = "Mixed";
      target.originalSurfaceCellFailureStage = "component-aggregation";
    }
  }
  if (target.requestedBackend == "LegacyInteger" &&
      source.requestedBackend != "LegacyInteger") {
    target.requestedBackend = source.requestedBackend;
  }
  if (target.executedBackend != source.executedBackend) {
    target.executedBackend =
        target.executedBackend.empty() ? source.executedBackend : "Mixed";
    target.remeshBackend = target.executedBackend;
  }
  if (!source.surfaceCellFallbackCause.empty()) {
    if (target.surfaceCellFallbackCause.empty()) {
      target.surfaceCellFallbackCause = source.surfaceCellFallbackCause;
    } else if (target.surfaceCellFallbackCause !=
               source.surfaceCellFallbackCause) {
      target.surfaceCellFallbackCause = "Mixed";
    }
  }
  target.surfaceCellFallbackAttempted =
      target.surfaceCellFallbackAttempted || source.surfaceCellFallbackAttempted;
  target.surfaceCellUsedLegacyFallback =
      target.surfaceCellUsedLegacyFallback || source.surfaceCellUsedLegacyFallback;
  target.surfaceCellReturnedInputMeshFallback =
      target.surfaceCellReturnedInputMeshFallback ||
      source.surfaceCellReturnedInputMeshFallback;
  target.surfaceCellRemeshOccurred =
      firstComponent ? source.surfaceCellRemeshOccurred
                     : (target.surfaceCellRemeshOccurred &&
                        source.surfaceCellRemeshOccurred);
  target.surfaceCellSourceGridRecoveryUsed =
      target.surfaceCellSourceGridRecoveryUsed ||
      source.surfaceCellSourceGridRecoveryUsed;
  target.surfaceCellSourceGridRecoveryTargetSizeRelaxed =
      target.surfaceCellSourceGridRecoveryTargetSizeRelaxed ||
      source.surfaceCellSourceGridRecoveryTargetSizeRelaxed;
  target.surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio =
      std::max(
          target.surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio,
          source.surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio);
  if (target.surfaceCellOutputOrigin == SurfaceCellOutputOrigin::None) {
    target.surfaceCellOutputOrigin = source.surfaceCellOutputOrigin;
  } else if (source.surfaceCellOutputOrigin != SurfaceCellOutputOrigin::None &&
             target.surfaceCellOutputOrigin != source.surfaceCellOutputOrigin) {
    target.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::Mixed;
  }
  target.surfaceCellDebugArtifactsPreserved =
      target.surfaceCellDebugArtifactsPreserved ||
      source.surfaceCellDebugArtifactsPreserved;
  for (const std::string &artifact : source.surfaceCellDebugArtifacts) {
    if (componentIndex == std::numeric_limits<std::size_t>::max()) {
      target.surfaceCellDebugArtifacts.push_back(artifact);
    } else {
      target.surfaceCellDebugArtifacts.push_back(
          "component[" + std::to_string(componentIndex) + "]/" + artifact);
    }
  }
  for (const SurfaceCellStageLineage &sourceLineage :
       source.surfaceCellStageLineage) {
    SurfaceCellStageLineage lineage = sourceLineage;
    lineage.componentIndex = componentIndex;
    target.surfaceCellStageLineage.push_back(std::move(lineage));
  }

  target.surfaceCellFeatureSeconds += source.surfaceCellFeatureSeconds;
  target.surfaceCellMetricSeconds += source.surfaceCellMetricSeconds;
  target.surfaceCellReliefSeconds += source.surfaceCellReliefSeconds;
  target.surfaceCellTracingSeconds += source.surfaceCellTracingSeconds;
  target.surfaceCellArrangementSeconds += source.surfaceCellArrangementSeconds;
  target.surfaceCellSimplificationSeconds +=
      source.surfaceCellSimplificationSeconds;
  target.surfaceCellCompletionSeconds += source.surfaceCellCompletionSeconds;
  target.surfaceCellOptimizationSeconds +=
      source.surfaceCellOptimizationSeconds;
  target.surfaceCellValidationSeconds += source.surfaceCellValidationSeconds;

  auto merge_count = [firstComponent](
                         std::size_t &targetValue, bool &targetAvailable,
                         const std::size_t sourceValue,
                         const bool sourceAvailable) {
    if (firstComponent) {
      targetAvailable = sourceAvailable;
      targetValue = sourceAvailable ? sourceValue : 0U;
      return;
    }
    if (!targetAvailable || !sourceAvailable) {
      targetAvailable = false;
      targetValue = 0U;
      return;
    }
    targetValue += sourceValue;
  };

  merge_count(target.surfaceCellValidationFailures,
              target.surfaceCellValidationFailureCountAvailable,
              source.surfaceCellValidationFailures,
              source.surfaceCellValidationFailureCountAvailable);
  merge_count(target.surfaceCellProvenanceVertexCount,
              target.surfaceCellProvenanceVertexCountAvailable,
              source.surfaceCellProvenanceVertexCount,
              source.surfaceCellProvenanceVertexCountAvailable);
  merge_count(target.surfaceCellFeatureCount,
              target.surfaceCellFeatureCountAvailable,
              source.surfaceCellFeatureCount,
              source.surfaceCellFeatureCountAvailable);
  merge_count(target.surfaceCellMetricSampleCount,
              target.surfaceCellMetricSampleCountAvailable,
              source.surfaceCellMetricSampleCount,
              source.surfaceCellMetricSampleCountAvailable);
  merge_count(target.surfaceCellReliefPatchCount,
              target.surfaceCellReliefCountAvailable,
              source.surfaceCellReliefPatchCount,
              source.surfaceCellReliefCountAvailable);
  merge_count(target.surfaceCellTraceSegmentCount,
              target.surfaceCellTraceCountAvailable,
              source.surfaceCellTraceSegmentCount,
              source.surfaceCellTraceCountAvailable);
  merge_count(target.surfaceCellArrangementCellCount,
              target.surfaceCellArrangementCountAvailable,
              source.surfaceCellArrangementCellCount,
              source.surfaceCellArrangementCountAvailable);
  merge_count(target.surfaceCellSimplifiedCellCount,
              target.surfaceCellSimplifiedCountAvailable,
              source.surfaceCellSimplifiedCellCount,
              source.surfaceCellSimplifiedCountAvailable);
  merge_count(target.surfaceCellCompletedQuadCount,
              target.surfaceCellCompletedQuadCountAvailable,
              source.surfaceCellCompletedQuadCount,
              source.surfaceCellCompletedQuadCountAvailable);
  merge_count(target.surfaceCellCompletionOwnershipRepairAttempts,
              target.surfaceCellCompletionOwnershipRepairAttemptsAvailable,
              source.surfaceCellCompletionOwnershipRepairAttempts,
              source.surfaceCellCompletionOwnershipRepairAttemptsAvailable);
  if (firstComponent) {
    target.surfaceCellCompletionOwnershipStructuralLedgerAvailable =
        source.surfaceCellCompletionOwnershipStructuralLedgerAvailable;
    target.surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable =
        source.surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable;
    target.surfaceCellCompletionOwnershipStructuralRepairAttempts =
        source.surfaceCellCompletionOwnershipStructuralRepairAttempts;
    target.surfaceCellCompletionOwnershipInsertedBoundaryVertices =
        source.surfaceCellCompletionOwnershipInsertedBoundaryVertices;
    target.surfaceCellCompletionOwnershipStructuralCandidateBudget =
        source.surfaceCellCompletionOwnershipStructuralCandidateBudget;
    target.surfaceCellCompletionOwnershipStructuralCandidatesConsumed =
        source.surfaceCellCompletionOwnershipStructuralCandidatesConsumed;
    target.surfaceCellCompletionOwnershipVisitedStateCount =
        source.surfaceCellCompletionOwnershipVisitedStateCount;
    target.surfaceCellCompletionOwnershipFullRecomputationPasses =
        source.surfaceCellCompletionOwnershipFullRecomputationPasses;
    target.surfaceCellCompletionOwnershipIncrementalRecomputationPasses =
        source.surfaceCellCompletionOwnershipIncrementalRecomputationPasses;
    target.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes =
        source.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes;
    target.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes =
        source.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes;
    target.surfaceCellCompletionOwnershipLastCandidateHalfedge =
        source.surfaceCellCompletionOwnershipLastCandidateHalfedge;
    target.surfaceCellCompletionOwnershipLastAffectedPatches =
        source.surfaceCellCompletionOwnershipLastAffectedPatches;
    target.surfaceCellCompletionOwnershipStructuralExhaustionReason =
        source.surfaceCellCompletionOwnershipStructuralExhaustionReason;
  } else if (target.surfaceCellCompletionOwnershipStructuralLedgerAvailable &&
             source.surfaceCellCompletionOwnershipStructuralLedgerAvailable) {
    target.surfaceCellCompletionOwnershipStructuralRepairAttempts +=
        source.surfaceCellCompletionOwnershipStructuralRepairAttempts;
    target.surfaceCellCompletionOwnershipInsertedBoundaryVertices +=
        source.surfaceCellCompletionOwnershipInsertedBoundaryVertices;
    target.surfaceCellCompletionOwnershipStructuralCandidateBudget +=
        source.surfaceCellCompletionOwnershipStructuralCandidateBudget;
    target.surfaceCellCompletionOwnershipStructuralCandidatesConsumed +=
        source.surfaceCellCompletionOwnershipStructuralCandidatesConsumed;
    target.surfaceCellCompletionOwnershipVisitedStateCount +=
        source.surfaceCellCompletionOwnershipVisitedStateCount;
    target.surfaceCellCompletionOwnershipFullRecomputationPasses +=
        source.surfaceCellCompletionOwnershipFullRecomputationPasses;
    target.surfaceCellCompletionOwnershipIncrementalRecomputationPasses +=
        source.surfaceCellCompletionOwnershipIncrementalRecomputationPasses;
    target.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes +=
        source.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes;
    target.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes =
        std::max(
            target.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes,
            source.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes);
    if (target.surfaceCellCompletionOwnershipStructuralExhaustionReason ==
            "none" &&
        source.surfaceCellCompletionOwnershipStructuralExhaustionReason !=
            "none") {
      target.surfaceCellCompletionOwnershipStructuralExhaustionReason =
          source.surfaceCellCompletionOwnershipStructuralExhaustionReason;
      target.surfaceCellCompletionOwnershipLastCandidateHalfedge =
          source.surfaceCellCompletionOwnershipLastCandidateHalfedge;
      target.surfaceCellCompletionOwnershipLastAffectedPatches =
          source.surfaceCellCompletionOwnershipLastAffectedPatches;
    }
  } else {
    target.surfaceCellCompletionOwnershipStructuralLedgerAvailable = false;
    target.surfaceCellCompletionOwnershipStructuralRepairAttemptsAvailable =
        false;
    target.surfaceCellCompletionOwnershipStructuralRepairAttempts = 0U;
    target.surfaceCellCompletionOwnershipInsertedBoundaryVertices = 0U;
    target.surfaceCellCompletionOwnershipStructuralCandidateBudget = 0U;
    target.surfaceCellCompletionOwnershipStructuralCandidatesConsumed = 0U;
    target.surfaceCellCompletionOwnershipVisitedStateCount = 0U;
    target.surfaceCellCompletionOwnershipFullRecomputationPasses = 0U;
    target.surfaceCellCompletionOwnershipIncrementalRecomputationPasses = 0U;
    target.surfaceCellCompletionOwnershipCurrentLiveCandidateComplexes = 0U;
    target.surfaceCellCompletionOwnershipPeakLiveCandidateComplexes = 0U;
    target.surfaceCellCompletionOwnershipLastCandidateHalfedge = -1;
    target.surfaceCellCompletionOwnershipLastAffectedPatches.clear();
    target.surfaceCellCompletionOwnershipStructuralExhaustionReason = "none";
  }
  if (source.surfaceCellCompletionOwnershipRejectionAvailable &&
      !target.surfaceCellCompletionOwnershipRejectionAvailable) {
    target.surfaceCellCompletionOwnershipRejectionAvailable = true;
    target.surfaceCellCompletionOwnershipFailure =
        source.surfaceCellCompletionOwnershipFailure;
    target.surfaceCellCompletionOwnershipSourcePatch =
        source.surfaceCellCompletionOwnershipSourcePatch;
    target.surfaceCellCompletionOwnershipLocalVertex =
        source.surfaceCellCompletionOwnershipLocalVertex;
    target.surfaceCellCompletionOwnershipBoundaryVertex =
        source.surfaceCellCompletionOwnershipBoundaryVertex;
    target.surfaceCellCompletionOwnershipBackend =
        source.surfaceCellCompletionOwnershipBackend;
    target.surfaceCellCompletionOwnershipVariant =
        source.surfaceCellCompletionOwnershipVariant;
    target.surfaceCellCompletionOwnershipStoredFace =
        source.surfaceCellCompletionOwnershipStoredFace;
    target.surfaceCellCompletionOwnershipBarycentric =
        source.surfaceCellCompletionOwnershipBarycentric;
    target.surfaceCellCompletionOwnershipEntityKind =
        source.surfaceCellCompletionOwnershipEntityKind;
    target.surfaceCellCompletionOwnershipSourceVertex =
        source.surfaceCellCompletionOwnershipSourceVertex;
    target.surfaceCellCompletionOwnershipSourceEdge =
        source.surfaceCellCompletionOwnershipSourceEdge;
    target.surfaceCellCompletionOwnershipCandidateFaces =
        source.surfaceCellCompletionOwnershipCandidateFaces;
    target.surfaceCellCompletionOwnershipPatchFaces =
        source.surfaceCellCompletionOwnershipPatchFaces;
    target.surfaceCellCompletionOwnershipComponent =
        source.surfaceCellCompletionOwnershipComponent;
    target.surfaceCellCompletionOwnershipSheet =
        source.surfaceCellCompletionOwnershipSheet;
  }
  merge_count(target.surfaceCellOptimizationIterationCount,
              target.surfaceCellOptimizationIterationCountAvailable,
              source.surfaceCellOptimizationIterationCount,
              source.surfaceCellOptimizationIterationCountAvailable);

  target.adaptiveFeatureMapSeconds += source.adaptiveFeatureMapSeconds;
  target.adaptiveFeatureHardEdgeCount += source.adaptiveFeatureHardEdgeCount;
  target.adaptiveFeatureSoftEdgeCount += source.adaptiveFeatureSoftEdgeCount;
  target.adaptiveFeatureBoundaryEdgeCount +=
      source.adaptiveFeatureBoundaryEdgeCount;
  target.adaptiveFeatureNonManifoldEdgeCount +=
      source.adaptiveFeatureNonManifoldEdgeCount;
  target.adaptiveFeatureCurveCount += source.adaptiveFeatureCurveCount;
  target.adaptiveFeatureClosedCurveCount +=
      source.adaptiveFeatureClosedCurveCount;
  target.adaptiveFeatureMaxDensity =
      std::max(target.adaptiveFeatureMaxDensity,
               source.adaptiveFeatureMaxDensity);
  target.adaptiveTargetSizeSeconds += source.adaptiveTargetSizeSeconds;
  target.adaptiveTargetSizeResolvedSurfaceError =
      std::max(target.adaptiveTargetSizeResolvedSurfaceError,
               source.adaptiveTargetSizeResolvedSurfaceError);
  if (firstComponent) {
    target.adaptiveTargetSizeMin = source.adaptiveTargetSizeMin;
    target.adaptiveTargetSizeMax = source.adaptiveTargetSizeMax;
  } else {
    target.adaptiveTargetSizeMin =
        std::min(target.adaptiveTargetSizeMin,
                 source.adaptiveTargetSizeMin);
    target.adaptiveTargetSizeMax =
        std::max(target.adaptiveTargetSizeMax,
                 source.adaptiveTargetSizeMax);
  }
  target.adaptiveTargetSizeFiniteVertexCount +=
      source.adaptiveTargetSizeFiniteVertexCount;
  target.adaptiveTargetSizeNonFiniteVertexCount +=
      source.adaptiveTargetSizeNonFiniteVertexCount;

  target.preconditioningSeconds += source.preconditioningSeconds;
  target.tangentBundleInitializationSeconds +=
      source.tangentBundleInitializationSeconds;
  target.fieldSetupSeconds += source.fieldSetupSeconds;
  target.principalMatchingSeconds += source.principalMatchingSeconds;
  target.setupIntegrationSeconds += source.setupIntegrationSeconds;
  target.integrationTotalSeconds += source.integrationTotalSeconds;
  target.setupMesherSeconds += source.setupMesherSeconds;
  target.mesherTotalSeconds += source.mesherTotalSeconds;

  target.preconditioningFlipsAccepted += source.preconditioningFlipsAccepted;
  target.preconditioningCollapsesAccepted +=
      source.preconditioningCollapsesAccepted;
  target.preconditioningSplitsAccepted += source.preconditioningSplitsAccepted;
  target.preconditioningInputTriangleCount +=
      source.preconditioningInputTriangleCount;
  target.preconditioningOutputTriangleCount +=
      source.preconditioningOutputTriangleCount;

  target.integration.totalSeconds += source.integration.totalSeconds;
  target.integration.parametrizationQualityAnalysisSeconds +=
      source.integration.parametrizationQualityAnalysisSeconds;
  target.integration.targetedStiffeningExtraSolveSeconds +=
      source.integration.targetedStiffeningExtraSolveSeconds;
  target.integration.directFactorizations += source.integration.directFactorizations;
  target.integration.roundingBatches += source.integration.roundingBatches;
  target.integration.integerIterations += source.integration.integerIterations;
  target.integration.parametrizationInitialBadFaceCount +=
      source.integration.parametrizationInitialBadFaceCount;
  target.integration.parametrizationPostStiffeningBadFaceCount +=
      source.integration.parametrizationPostStiffeningBadFaceCount;
  target.integration.parametrizationInvertedFaceCount +=
      source.integration.parametrizationInvertedFaceCount;
  target.integration.parametrizationNearDegenerateFaceCount +=
      source.integration.parametrizationNearDegenerateFaceCount;
  target.integration.targetedStiffeningPasses +=
      source.integration.targetedStiffeningPasses;
  target.integration.targetedStiffeningExtraFactorizations +=
      source.integration.targetedStiffeningExtraFactorizations;
  target.integration.maximumFreeVariables =
      std::max(target.integration.maximumFreeVariables,
               source.integration.maximumFreeVariables);
  target.integration.maximumConstraintRows =
      std::max(target.integration.maximumConstraintRows,
               source.integration.maximumConstraintRows);
  target.integration.maximumSystemRows =
      std::max(target.integration.maximumSystemRows,
               source.integration.maximumSystemRows);
  target.integration.maximumSystemNonZeros =
      std::max(target.integration.maximumSystemNonZeros,
               source.integration.maximumSystemNonZeros);

  target.mesher.totalMesherSeconds += source.mesher.totalMesherSeconds;
  target.mesher.generateArrangementSeconds +=
      source.mesher.generateArrangementSeconds;
  target.mesher.simplifyTotalSeconds += source.mesher.simplifyTotalSeconds;
  target.mesher.verticesBeforeSimplification +=
      source.mesher.verticesBeforeSimplification;
  target.mesher.facesBeforeSimplification +=
      source.mesher.facesBeforeSimplification;
  target.mesher.halfedgesBeforeSimplification +=
      source.mesher.halfedgesBeforeSimplification;
  target.mesher.verticesAfterSimplification +=
      source.mesher.verticesAfterSimplification;
  target.mesher.facesAfterSimplification +=
      source.mesher.facesAfterSimplification;
  target.mesher.halfedgesAfterSimplification +=
      source.mesher.halfedgesAfterSimplification;

  clear_unavailable_surface_cell_counts(target);
}

} // namespace directional::pipeline

namespace directional::pipeline {

void accumulate_component_diagnostics(
    directional::RemeshDiagnostics &target,
    const directional::RemeshDiagnostics &source) {
  const bool firstComponent =
      target.surfaceCellStageLineage.empty() &&
      target.surfaceCellOutputOrigin == SurfaceCellOutputOrigin::None &&
      !target.surfaceCellFeatureCountAvailable &&
      !target.surfaceCellMetricSampleCountAvailable &&
      !target.surfaceCellReliefCountAvailable;
  accumulate_component_diagnostics(
      target, source, std::numeric_limits<std::size_t>::max(), firstComponent);
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult remesh_surface_cell_components_from_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options) {
  using Clock = RemeshPipelineClock;
  const auto pipelineStart = Clock::now();

  TriMesh sourceMesh;
  sourceMesh.set_mesh(vertices, faces);
  fields::CrossFieldResult sourceCrossField = authoritativeCrossField;
  normalize_surface_cell_cross_field_directions(sourceCrossField);

  RemeshOptions sequentialOptions = options;
  sequentialOptions.parallelizeComponents = false;
  const SurfaceCellFailureCode globalFieldFailure =
      validate_surface_cell_cross_field(sourceMesh, sourceCrossField,
                                        options.surfaceCells);
  if (globalFieldFailure != SurfaceCellFailureCode::None) {
    RemeshResult result = remesh_surface_cells_from_cross_field_impl(
        sourceMesh, sourceCrossField, sequentialOptions);
    set_overall_pipeline_time(result, pipelineStart);
    return result;
  }

  const auto splitStart = Clock::now();
  std::vector<geometry::FaceComponent> components =
      geometry::compact_face_components(vertices, faces,
                                        &sourceCrossField.rawField);
  const double splitSeconds = remesh_elapsed_seconds(splitStart);
  if (components.size() <= 1U) {
    RemeshResult result = remesh_surface_cells_from_cross_field_impl(
        sourceMesh, sourceCrossField, sequentialOptions);
    result.diagnostics.componentSplitSeconds = splitSeconds;
    result.diagnostics.componentCount =
        std::max<std::size_t>(1U, components.size());
    set_overall_pipeline_time(result, pipelineStart);
    return result;
  }

  const unsigned int hardwareThreads =
      std::max(1U, std::thread::hardware_concurrency());
  const std::size_t requestedThreads =
      options.maxComponentThreads > 0
          ? static_cast<std::size_t>(options.maxComponentThreads)
          : static_cast<std::size_t>(hardwareThreads);
  const std::size_t workerCount =
      std::max<std::size_t>(1U,
                            std::min(requestedThreads, components.size()));
  const double absoluteTargetLength =
      derive_absolute_target_length(vertices, options);

  struct ComponentRun {
    RemeshResult result;
    double wallSeconds = 0.0;
  };

  auto runComponent = [&](const std::size_t componentIndex) {
    const auto componentStart = Clock::now();
    ComponentRun run;
    const geometry::FaceComponent &component = components[componentIndex];
    try {
      TriMesh componentMesh;
      componentMesh.set_mesh(component.vertices, component.faces);
      fields::CrossFieldResult componentCrossField =
          remap_surface_cell_cross_field_component(
              sourceMesh, component, componentMesh, sourceCrossField);

      RemeshOptions componentOptions = options;
      componentOptions.parallelizeComponents = false;
      componentOptions.progress = nullptr;
      componentOptions.mesherDataCallback = nullptr;
      componentOptions.absoluteTargetLength = absoluteTargetLength;
      if (componentOptions.surfaceCells.injectFailureComponentIndex >= 0 &&
          componentOptions.surfaceCells.injectFailureComponentIndex !=
              static_cast<int>(componentIndex)) {
        componentOptions.surfaceCells.injectFailureAfterStage = -1;
      }

      run.result = remesh_surface_cells_from_cross_field_impl(
          componentMesh, componentCrossField, componentOptions);
    } catch (const std::exception &) {
      run.result.success = false;
      run.result.diagnostics.remeshBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      run.result.diagnostics.requestedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      run.result.diagnostics.executedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      run.result.diagnostics.surfaceCellFallbackPolicy =
          surface_cell_fallback_policy_name(
              options.surfaceCells.fallbackPolicy);
      run.result.diagnostics.terminalFailureCode =
          surface_cell_failure_code_name(
              SurfaceCellFailureCode::UnsupportedInput);
      run.result.diagnostics.terminalFailureStage = "component-execution";
      run.result.diagnostics.originalSurfaceCellFailureCode =
          run.result.diagnostics.terminalFailureCode;
      run.result.diagnostics.originalSurfaceCellFailureStage =
          run.result.diagnostics.terminalFailureStage;
      run.result.diagnostics.surfaceCellOutputOrigin =
          SurfaceCellOutputOrigin::None;
      run.result.diagnostics.surfaceCellRemeshOccurred = false;
      set_overall_pipeline_time(run.result, componentStart);
    } catch (...) {
      run.result.success = false;
      run.result.diagnostics.remeshBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      run.result.diagnostics.requestedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      run.result.diagnostics.executedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      run.result.diagnostics.surfaceCellFallbackPolicy =
          surface_cell_fallback_policy_name(
              options.surfaceCells.fallbackPolicy);
      run.result.diagnostics.terminalFailureCode =
          surface_cell_failure_code_name(
              SurfaceCellFailureCode::UnsupportedInput);
      run.result.diagnostics.terminalFailureStage = "component-execution";
      run.result.diagnostics.originalSurfaceCellFailureCode =
          run.result.diagnostics.terminalFailureCode;
      run.result.diagnostics.originalSurfaceCellFailureStage =
          run.result.diagnostics.terminalFailureStage;
      run.result.diagnostics.surfaceCellOutputOrigin =
          SurfaceCellOutputOrigin::None;
      run.result.diagnostics.surfaceCellRemeshOccurred = false;
      set_overall_pipeline_time(run.result, componentStart);
    }
    run.wallSeconds = remesh_elapsed_seconds(componentStart);
    return run;
  };

  const auto parallelStart = Clock::now();
  std::vector<ComponentRun> runs(components.size());
  if (workerCount == 1U) {
    for (std::size_t index = 0; index < components.size(); ++index) {
      runs[index] = runComponent(index);
    }
  } else {
    std::vector<std::future<ComponentRun>> active;
    std::vector<std::size_t> activeIndices;
    for (std::size_t next = 0; next < components.size(); ++next) {
      activeIndices.push_back(next);
      active.push_back(std::async(std::launch::async, runComponent, next));
      if (active.size() == workerCount || next + 1U == components.size()) {
        for (std::size_t activeIndex = 0; activeIndex < active.size();
             ++activeIndex) {
          runs[activeIndices[activeIndex]] = active[activeIndex].get();
        }
        active.clear();
        activeIndices.clear();
      }
    }
  }
  const double parallelSeconds = remesh_elapsed_seconds(parallelStart);

  const auto mergeStart = Clock::now();
  RemeshResult merged;
  merged.success = true;
  merged.diagnostics.remeshBackend =
      remesh_backend_name(RemeshBackend::SurfaceCells);
  merged.diagnostics.requestedBackend =
      remesh_backend_name(RemeshBackend::SurfaceCells);
  merged.diagnostics.executedBackend.clear();
  merged.diagnostics.surfaceCellFallbackPolicy =
      surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
  merged.diagnostics.componentSplitSeconds = splitSeconds;
  merged.diagnostics.componentParallelWallSeconds = parallelSeconds;
  merged.diagnostics.componentCount = components.size();
  merged.diagnostics.componentThreadsRequested = requestedThreads;
  merged.diagnostics.componentThreadsUsed = workerCount;
  merged.diagnostics.componentPeakConcurrentTasks = workerCount;

  std::size_t failedComponent = std::numeric_limits<std::size_t>::max();
  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    const RemeshResult &componentResult = runs[index].result;

    ComponentRemeshDiagnostics componentDiagnostics;
    componentDiagnostics.componentIndex = index;
    componentDiagnostics.minimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    componentDiagnostics.inputFaceCount = component.originalFaces.size();
    componentDiagnostics.outputVertexCount =
        static_cast<std::size_t>(componentResult.vertices.rows());
    componentDiagnostics.outputFaceCount =
        static_cast<std::size_t>(componentResult.faces.rows());
    componentDiagnostics.success = componentResult.success;
    componentDiagnostics.terminalFailureCode =
        componentResult.diagnostics.terminalFailureCode;
    componentDiagnostics.terminalFailureStage =
        componentResult.diagnostics.terminalFailureStage;
    componentDiagnostics.outputOrigin = surface_cell_output_origin_name(
        componentResult.diagnostics.surfaceCellOutputOrigin);
    componentDiagnostics.wallSeconds = runs[index].wallSeconds;
    componentDiagnostics.integrationSeconds =
        componentResult.diagnostics.integrationTotalSeconds;
    componentDiagnostics.mesherSeconds =
        componentResult.diagnostics.mesherTotalSeconds;
    merged.diagnostics.components.push_back(componentDiagnostics);

    accumulate_component_diagnostics(
        merged.diagnostics, componentResult.diagnostics, index, index == 0U);
    if (!componentResult.success &&
        failedComponent == std::numeric_limits<std::size_t>::max()) {
      failedComponent = index;
    }
  }

  if (failedComponent != std::numeric_limits<std::size_t>::max()) {
    const geometry::FaceComponent &component = components[failedComponent];
    const RemeshResult &failure = runs[failedComponent].result;
    merged.success = false;
    merged.vertices.resize(0, 3);
    merged.faces.resize(0, 0);
    merged.degrees.resize(0);
    merged.outputVertexProvenance.clear();
    merged.outputVertexLineage.clear();
    merged.outputQuadLineage.clear();
    merged.rawCrossField.resize(0, 0);
    merged.crossFieldMatching.resize(0);
    merged.crossFieldEffort.resize(0);
    merged.crossFieldSingularCycles.resize(0);
    merged.crossFieldSingularIndices.resize(0);
    merged.surfaceCellContext = failure.surfaceCellContext;
    merged.diagnostics.failedComponentIndex = failedComponent;
    merged.diagnostics.failedComponentMinimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    merged.diagnostics.terminalFailureCode =
        failure.diagnostics.terminalFailureCode;
    merged.diagnostics.terminalFailureStage =
        failure.diagnostics.terminalFailureStage;
    merged.diagnostics.surfaceCellOutputOrigin =
        SurfaceCellOutputOrigin::None;
    merged.diagnostics.surfaceCellRemeshOccurred = false;
    merged.diagnostics.componentMergeSeconds =
        remesh_elapsed_seconds(mergeStart);
    set_overall_pipeline_time(merged, pipelineStart);
    return merged;
  }

  merged.rawCrossField = sourceCrossField.rawField;
  merged.crossFieldMatching = sourceCrossField.matching;
  merged.crossFieldEffort = sourceCrossField.effort;
  merged.crossFieldSingularCycles = sourceCrossField.singularCycles;
  merged.crossFieldSingularIndices = sourceCrossField.singularIndices;
  merged.surfaceCellContext.sourceMesh = sourceMesh;
  merged.surfaceCellContext.hasSourceMesh = true;
  merged.surfaceCellContext.crossField = sourceCrossField;
  merged.surfaceCellContext.hasCrossField = true;
  merged.surfaceCellContext.crossFieldHasMatching =
      sourceCrossField.matchingComputed;
  merged.surfaceCellContext.crossFieldHasSingularities =
      sourceCrossField.singularitiesComputed;

  int sheetOffset = 0;
  int patchOffset = 0;
  int railOffset = 0;
  int curveOffset = 0;
  bool allHaveSourceLabels = true;
  bool allHaveAuthoritativeRails = true;
  merged.surfaceCellContext.sourceSurfaceLabels.componentByFace.assign(
      static_cast<std::size_t>(faces.rows()), -1);
  merged.surfaceCellContext.sourceSurfaceLabels.localSheetByFace.assign(
      static_cast<std::size_t>(faces.rows()), -1);
  std::map<std::uint64_t, int> globalEdgeByVertices;
  for (int edge = 0; edge < sourceMesh.EV.rows(); ++edge) {
    globalEdgeByVertices[surface_cell_source_edge_key(
        sourceMesh.EV(edge, 0), sourceMesh.EV(edge, 1))] = edge;
  }
  bool allCompletedSurfaceCells = true;
  bool allComponentsUsedSourceGridRecovery = true;
  bool allRecoveryTargetsAvailable = true;
  bool anyRecoveryTargetRelaxed = false;
  double maximumRecoveryTargetRelaxationRatio = 1.0;
  Eigen::VectorXd mergedRecoveryTargetSize =
      Eigen::VectorXd::Zero(vertices.rows());
  std::vector<unsigned char> recoveryTargetAssigned(
      static_cast<std::size_t>(vertices.rows()), 0U);
  std::vector<unsigned char> sourceVertexReferenced(
      static_cast<std::size_t>(vertices.rows()), 0U);
  for (int sourceFace = 0; sourceFace < faces.rows(); ++sourceFace) {
    for (int corner = 0; corner < faces.cols(); ++corner) {
      const int sourceVertex = faces(sourceFace, corner);
      if (sourceVertex >= 0 && sourceVertex < vertices.rows()) {
        sourceVertexReferenced[static_cast<std::size_t>(sourceVertex)] = 1U;
      }
    }
  }
  bool allHaveOptimizationResult = true;
  bool allHaveValidationResult = true;
  bool firstOptimizationResult = true;
  bool firstValidationResult = true;
  geometry::SurfaceOptimizationResult aggregateOptimizationResult;
  aggregateOptimizationResult.topologyHash =
      structural_hash_seed("component-optimization");
  geometry::SurfaceFinalValidationReport aggregateValidationResult;

  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    const RemeshResult &componentResult = runs[index].result;
    const int vertexOffset = static_cast<int>(merged.vertices.rows());
    const int faceOffset = static_cast<int>(merged.faces.rows());

    TriMesh componentMesh;
    componentMesh.set_mesh(component.vertices, component.faces);
    std::vector<int> globalEdgeByLocal(
        static_cast<std::size_t>(componentMesh.EV.rows()), -1);
    for (int localEdge = 0; localEdge < componentMesh.EV.rows(); ++localEdge) {
      const int originalVertex0 = component.originalVertices[
          static_cast<std::size_t>(componentMesh.EV(localEdge, 0))];
      const int originalVertex1 = component.originalVertices[
          static_cast<std::size_t>(componentMesh.EV(localEdge, 1))];
      const auto found = globalEdgeByVertices.find(
          surface_cell_source_edge_key(originalVertex0, originalVertex1));
      if (found != globalEdgeByVertices.end()) {
        globalEdgeByLocal[static_cast<std::size_t>(localEdge)] = found->second;
      }
    }

    int localMaximumRail = -1;
    int localMaximumCurve = -1;
    allHaveSourceLabels =
        allHaveSourceLabels &&
        componentResult.surfaceCellContext.hasSourceSurfaceLabels;
    if (componentResult.surfaceCellContext.hasSourceSurfaceLabels) {
      const auto &labels =
          componentResult.surfaceCellContext.sourceSurfaceLabels;
      for (std::size_t localFace = 0;
           localFace < component.originalFaces.size(); ++localFace) {
        const int originalFace = component.originalFaces[localFace];
        merged.surfaceCellContext.sourceSurfaceLabels.componentByFace[
            static_cast<std::size_t>(originalFace)] =
            static_cast<int>(index);
        if (localFace < labels.localSheetByFace.size() &&
            labels.localSheetByFace[localFace] >= 0) {
          merged.surfaceCellContext.sourceSurfaceLabels.localSheetByFace[
              static_cast<std::size_t>(originalFace)] =
              labels.localSheetByFace[localFace] + sheetOffset;
        }
      }
    }

    allHaveAuthoritativeRails =
        allHaveAuthoritativeRails &&
        componentResult.surfaceCellContext.hasAuthoritativeRails;
    for (geometry::SurfaceCellRail rail :
         componentResult.surfaceCellContext.authoritativeRails) {
      localMaximumRail = std::max(localMaximumRail, rail.id);
      localMaximumCurve = std::max(localMaximumCurve, rail.curveId);
      if (rail.id >= 0) {
        rail.id += railOffset;
      }
      if (rail.curveId >= 0) {
        rail.curveId += curveOffset;
      }
      rail.component = static_cast<int>(index);
      for (int &sourceVertex : rail.sourceVertices) {
        if (sourceVertex >= 0 &&
            static_cast<std::size_t>(sourceVertex) <
                component.originalVertices.size()) {
          sourceVertex = component.originalVertices[
              static_cast<std::size_t>(sourceVertex)];
        } else {
          sourceVertex = -1;
        }
      }
      for (int &sourceEdge : rail.sourceEdges) {
        if (sourceEdge >= 0 &&
            static_cast<std::size_t>(sourceEdge) <
                globalEdgeByLocal.size()) {
          sourceEdge =
              globalEdgeByLocal[static_cast<std::size_t>(sourceEdge)];
        } else {
          sourceEdge = -1;
        }
      }
      for (geometry::SurfaceCellRailSample &sample : rail.samples) {
        if (sample.sourceFace >= 0 &&
            static_cast<std::size_t>(sample.sourceFace) <
                component.originalFaces.size()) {
          sample.sourceFace = component.originalFaces[
              static_cast<std::size_t>(sample.sourceFace)];
        } else {
          sample.sourceFace = -1;
        }
      }
      merged.surfaceCellContext.authoritativeRails.push_back(
          std::move(rail));
    }

    append_matrix_rows(merged.vertices, componentResult.vertices);
    append_polygon_faces(merged.faces, merged.degrees,
                         componentResult.faces, componentResult.degrees,
                         vertexOffset);

    int localMaximumSheet = -1;
    if (componentResult.surfaceCellContext.hasSourceSurfaceLabels) {
      for (const int sheet :
           componentResult.surfaceCellContext.sourceSurfaceLabels
               .localSheetByFace) {
        localMaximumSheet = std::max(localMaximumSheet, sheet);
      }
    }

    for (geometry::SurfacePoint provenance :
         componentResult.outputVertexProvenance) {
      provenance = remap_component_surface_point(
          provenance, component, index, sheetOffset);
      localMaximumSheet =
          std::max(localMaximumSheet, provenance.sheet - sheetOffset);
      merged.outputVertexProvenance.push_back(std::move(provenance));
    }

    for (geometry::PureQuadVertexLineage lineage :
         componentResult.outputVertexLineage) {
      lineage.outputVertex += vertexOffset;
      lineage.sourcePoint = remap_component_surface_point(
          lineage.sourcePoint, component, index, sheetOffset);
      lineage.featureInterval.start = remap_component_surface_point(
          lineage.featureInterval.start, component, index, sheetOffset);
      lineage.featureInterval.end = remap_component_surface_point(
          lineage.featureInterval.end, component, index, sheetOffset);
      if (lineage.featureInterval.railId >= 0) {
        lineage.featureInterval.railId += railOffset;
      }
      if (lineage.featureInterval.curveId >= 0) {
        lineage.featureInterval.curveId += curveOffset;
      }
      merged.outputVertexLineage.push_back(std::move(lineage));
    }

    int localMaximumPatch = -1;
    for (geometry::PureQuadFaceLineage lineage :
         componentResult.outputQuadLineage) {
      lineage.outputQuad += faceOffset;
      if (lineage.sourcePatch >= 0) {
        localMaximumPatch = std::max(localMaximumPatch, lineage.sourcePatch);
        lineage.sourcePatch += patchOffset;
      }
      merged.outputQuadLineage.push_back(std::move(lineage));
    }

    for (geometry::PureQuadMesh patch :
         componentResult.surfaceCellContext.completedPatches) {
      if (patch.sourcePatch >= 0) {
        localMaximumPatch = std::max(localMaximumPatch, patch.sourcePatch);
        patch.sourcePatch += patchOffset;
      }
      for (geometry::SurfacePoint &point : patch.vertexProvenance) {
        point = remap_component_surface_point(
            point, component, index, sheetOffset);
      }
      for (geometry::PureQuadVertexLineage &lineage :
           patch.vertexLineage) {
        lineage.sourcePoint = remap_component_surface_point(
            lineage.sourcePoint, component, index, sheetOffset);
        lineage.featureInterval.start = remap_component_surface_point(
            lineage.featureInterval.start, component, index, sheetOffset);
        lineage.featureInterval.end = remap_component_surface_point(
            lineage.featureInterval.end, component, index, sheetOffset);
        if (lineage.featureInterval.railId >= 0) {
          lineage.featureInterval.railId += railOffset;
        }
        if (lineage.featureInterval.curveId >= 0) {
          lineage.featureInterval.curveId += curveOffset;
        }
      }
      for (geometry::PureQuadFaceLineage &lineage : patch.quadLineage) {
        if (lineage.sourcePatch >= 0) {
          localMaximumPatch = std::max(localMaximumPatch,
                                       lineage.sourcePatch);
          lineage.sourcePatch += patchOffset;
        }
      }
      merged.surfaceCellContext.completedPatches.push_back(std::move(patch));
    }

    for (const SurfaceCellContextProductDebug &product :
         componentResult.surfaceCellContext.debugProducts) {
      SurfaceCellContextProductDebug mergedProduct = product;
      mergedProduct.name = "component[" + std::to_string(index) + "]/" +
                           product.name;
      merged.surfaceCellContext.debugProducts.push_back(
          std::move(mergedProduct));
    }

    allCompletedSurfaceCells =
        allCompletedSurfaceCells &&
        componentResult.diagnostics.surfaceCellOutputOrigin ==
            SurfaceCellOutputOrigin::CompletedSurfaceCells;
    const bool componentUsedSourceGridRecovery =
        componentResult.surfaceCellContext.sourceGridRecoveryUsed;
    merged.surfaceCellContext.sourceGridRecoveryUsed =
        merged.surfaceCellContext.sourceGridRecoveryUsed ||
        componentUsedSourceGridRecovery;
    allComponentsUsedSourceGridRecovery =
        allComponentsUsedSourceGridRecovery &&
        componentUsedSourceGridRecovery;
    if (componentUsedSourceGridRecovery) {
      const bool componentRecoveryTargetAvailable =
          componentResult.surfaceCellContext.hasSourceGridRecoveryTargetSize &&
          componentResult.surfaceCellContext.sourceGridRecoveryTargetSize.size() ==
              component.vertices.rows();
      allRecoveryTargetsAvailable =
          allRecoveryTargetsAvailable && componentRecoveryTargetAvailable;
      anyRecoveryTargetRelaxed =
          anyRecoveryTargetRelaxed ||
          componentResult.surfaceCellContext
              .sourceGridRecoveryTargetSizeRelaxed;
      maximumRecoveryTargetRelaxationRatio = std::max(
          maximumRecoveryTargetRelaxationRatio,
          componentResult.surfaceCellContext
              .sourceGridRecoveryTargetSizeMaxRelaxationRatio);
      if (componentRecoveryTargetAvailable) {
        for (std::size_t localVertex = 0;
             localVertex < component.originalVertices.size(); ++localVertex) {
          const int originalVertex = component.originalVertices[localVertex];
          if (originalVertex < 0 || originalVertex >= vertices.rows()) {
            allRecoveryTargetsAvailable = false;
            continue;
          }
          const double target = componentResult.surfaceCellContext
                                    .sourceGridRecoveryTargetSize(
                                        static_cast<Eigen::Index>(localVertex));
          const std::size_t originalIndex =
              static_cast<std::size_t>(originalVertex);
          if (recoveryTargetAssigned[originalIndex] != 0U &&
              std::abs(mergedRecoveryTargetSize(originalVertex) - target) >
                  1.0e-12 *
                      std::max({1.0,
                                std::abs(mergedRecoveryTargetSize(originalVertex)),
                                std::abs(target)})) {
            allRecoveryTargetsAvailable = false;
            continue;
          }
          mergedRecoveryTargetSize(originalVertex) = target;
          recoveryTargetAssigned[originalIndex] = 1U;
        }
      }
    } else {
      allRecoveryTargetsAvailable = false;
    }

    allHaveOptimizationResult =
        allHaveOptimizationResult &&
        componentResult.surfaceCellContext.hasOptimizationResult;
    if (componentResult.surfaceCellContext.hasOptimizationResult) {
      const geometry::SurfaceOptimizationResult &componentOptimization =
          componentResult.surfaceCellContext.optimizationResult;
      hash_combine_u64(aggregateOptimizationResult.topologyHash,
                       componentOptimization.topologyHash);
      accumulate_surface_optimization_result(
          aggregateOptimizationResult, componentOptimization,
          firstOptimizationResult);
      firstOptimizationResult = false;
    }

    allHaveValidationResult =
        allHaveValidationResult &&
        componentResult.surfaceCellContext.hasValidationResult;
    if (componentResult.surfaceCellContext.hasValidationResult) {
      accumulate_surface_validation_report(
          aggregateValidationResult,
          componentResult.surfaceCellContext.validationResult,
          firstValidationResult);
      firstValidationResult = false;
    }

    sheetOffset += localMaximumSheet + 1;
    patchOffset += localMaximumPatch + 1;
    railOffset += localMaximumRail + 1;
    curveOffset += localMaximumCurve + 1;
  }

  merged.surfaceCellContext.hasSourceSurfaceLabels =
      allHaveSourceLabels;
  merged.surfaceCellContext.hasAuthoritativeRails =
      allHaveAuthoritativeRails;
  bool allReferencedRecoveryTargetsAssigned = true;
  for (std::size_t sourceVertex = 0;
       sourceVertex < sourceVertexReferenced.size(); ++sourceVertex) {
    if (sourceVertexReferenced[sourceVertex] != 0U &&
        recoveryTargetAssigned[sourceVertex] == 0U) {
      allReferencedRecoveryTargetsAssigned = false;
      break;
    }
  }
  merged.surfaceCellContext.sourceGridRecoveryTargetSizeRelaxed =
      anyRecoveryTargetRelaxed;
  merged.surfaceCellContext
      .sourceGridRecoveryTargetSizeMaxRelaxationRatio =
      maximumRecoveryTargetRelaxationRatio;
  merged.surfaceCellContext.hasSourceGridRecoveryTargetSize =
      allCompletedSurfaceCells && allComponentsUsedSourceGridRecovery &&
      allRecoveryTargetsAvailable && allReferencedRecoveryTargetsAssigned;
  if (merged.surfaceCellContext.hasSourceGridRecoveryTargetSize) {
    merged.surfaceCellContext.sourceGridRecoveryTargetSize =
        std::move(mergedRecoveryTargetSize);
  } else {
    merged.surfaceCellContext.sourceGridRecoveryTargetSize.resize(0);
  }
  merged.surfaceCellContext.completedVertices = merged.vertices;
  merged.surfaceCellContext.completedQuads =
      allCompletedSurfaceCells ? merged.faces : Eigen::MatrixXi{};
  merged.surfaceCellContext.completedProvenance =
      merged.outputVertexProvenance;
  merged.surfaceCellContext.completedVertexLineage =
      merged.outputVertexLineage;
  merged.surfaceCellContext.completedQuadLineage =
      merged.outputQuadLineage;
  merged.surfaceCellContext.hasCompletedPatches =
      allCompletedSurfaceCells &&
      !merged.surfaceCellContext.completedPatches.empty();

  if (allCompletedSurfaceCells && allHaveOptimizationResult &&
      !firstOptimizationResult) {
    aggregateOptimizationResult.vertices = merged.vertices;
    aggregateOptimizationResult.quads = merged.faces;
    aggregateOptimizationResult.vertexProvenance =
        merged.outputVertexProvenance;
    merged.surfaceCellContext.optimizationResult =
        std::move(aggregateOptimizationResult);
    merged.surfaceCellContext.hasOptimizationResult = true;
  }
  if (allCompletedSurfaceCells && allHaveValidationResult &&
      !firstValidationResult) {
    merged.surfaceCellContext.validationResult =
        std::move(aggregateValidationResult);
    merged.surfaceCellContext.hasValidationResult = true;
  }

  merged.diagnostics.surfaceCellRemeshOccurred =
      allCompletedSurfaceCells;
  merged.success = true;
  record_face_degree_histogram(merged);
  merged.diagnostics.componentMergeSeconds =
      remesh_elapsed_seconds(mergeStart);
  set_overall_pipeline_time(merged, pipelineStart);
  return merged;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult remesh_components_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options) {
  using Clock = RemeshPipelineClock;
  const auto pipelineStart = Clock::now();
  const auto splitStart = Clock::now();
  std::vector<geometry::FaceComponent> components =
      geometry::compact_face_components(vertices, faces, &rawCrossField);
  const double splitSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            splitStart)
          .count() /
      1.0e6;

  if (components.size() <= 1U) {
    RemeshOptions sequentialOptions = options;
    sequentialOptions.parallelizeComponents = false;
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    const fields::CrossFieldResult crossField =
        finalize_surface_cell_raw_cross_field(meshWhole, rawCrossField);
    RemeshResult result = remesh_surface_cells_from_cross_field_impl(
        meshWhole, crossField, sequentialOptions);
    set_overall_pipeline_time(result, pipelineStart);
    return result;
  }

  const unsigned int hardwareThreads =
      std::max(1U, std::thread::hardware_concurrency());
  const std::size_t requestedThreads =
      options.maxComponentThreads > 0
          ? static_cast<std::size_t>(options.maxComponentThreads)
          : static_cast<std::size_t>(hardwareThreads);
  const std::size_t workerCount =
      std::max<std::size_t>(1, std::min(requestedThreads, components.size()));
  const double absoluteTargetLength =
      derive_absolute_target_length(vertices, options);

  struct ComponentRun {
    RemeshResult result;
    bool threw = false;
    std::string error;
    double wallSeconds = 0.0;
  };

  auto runComponent = [&](const std::size_t componentIndex) {
    const auto componentStart = Clock::now();
    ComponentRun run;
    try {
      const geometry::FaceComponent &component = components[componentIndex];
      TriMesh componentMesh;
      componentMesh.set_mesh(component.vertices, component.faces);
      RemeshOptions componentOptions = options;
      componentOptions.parallelizeComponents = false;
      componentOptions.progress = nullptr;
      componentOptions.mesherDataCallback = nullptr;
      componentOptions.absoluteTargetLength = absoluteTargetLength;
      const fields::CrossFieldResult crossField =
          finalize_surface_cell_raw_cross_field(componentMesh, component.rawField);
      run.result = remesh_surface_cells_from_cross_field_impl(
          componentMesh, crossField, componentOptions);
    } catch (const std::exception &exception) {
      run.threw = true;
      run.error = exception.what();
    } catch (...) {
      run.threw = true;
      run.error = "Unknown component remesh failure.";
    }
    run.wallSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                              componentStart)
            .count() /
        1.0e6;
    return run;
  };

  const auto parallelStart = Clock::now();
  std::vector<ComponentRun> runs(components.size());
  if (workerCount == 1U) {
    for (std::size_t index = 0; index < components.size(); ++index) {
      runs[index] = runComponent(index);
    }
  } else {
    std::vector<std::future<ComponentRun>> active;
    std::vector<std::size_t> activeIndices;
    for (std::size_t next = 0; next < components.size(); ++next) {
      activeIndices.push_back(next);
      active.push_back(
          std::async(std::launch::async, runComponent, next));
      if (active.size() == workerCount || next + 1 == components.size()) {
        for (std::size_t activeIndex = 0; activeIndex < active.size();
             ++activeIndex) {
          runs[activeIndices[activeIndex]] = active[activeIndex].get();
        }
        active.clear();
        activeIndices.clear();
      }
    }
  }
  const double parallelSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            parallelStart)
          .count() /
      1.0e6;

  const auto mergeStart = Clock::now();
  RemeshResult merged;
  merged.success = true;
  merged.diagnostics.remeshBackend = remesh_backend_name(options.backend);
  merged.diagnostics.requestedBackend = remesh_backend_name(options.backend);
  merged.diagnostics.executedBackend.clear();
  merged.diagnostics.surfaceCellFallbackPolicy =
      surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
  merged.diagnostics.componentSplitSeconds = splitSeconds;
  merged.diagnostics.componentParallelWallSeconds = parallelSeconds;
  merged.diagnostics.componentCount = components.size();
  merged.diagnostics.componentThreadsRequested = requestedThreads;
  merged.diagnostics.componentThreadsUsed = workerCount;
  merged.diagnostics.componentPeakConcurrentTasks = workerCount;

  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    directional::ComponentRemeshDiagnostics componentDiagnostics;
    componentDiagnostics.componentIndex = index;
    componentDiagnostics.minimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    componentDiagnostics.inputFaceCount = component.originalFaces.size();
    componentDiagnostics.success =
        !runs[index].threw && runs[index].result.success;
    componentDiagnostics.wallSeconds = runs[index].wallSeconds;
    componentDiagnostics.integrationSeconds =
        runs[index].result.diagnostics.integrationTotalSeconds;
    componentDiagnostics.mesherSeconds =
        runs[index].result.diagnostics.mesherTotalSeconds;
    componentDiagnostics.outputVertexCount =
        static_cast<std::size_t>(runs[index].result.vertices.rows());
    componentDiagnostics.outputFaceCount =
        static_cast<std::size_t>(runs[index].result.faces.rows());
    merged.diagnostics.components.push_back(componentDiagnostics);
    accumulate_component_diagnostics(
        merged.diagnostics, runs[index].result.diagnostics, index, index == 0U);

    if (!componentDiagnostics.success) {
      merged.success = false;
      merged.diagnostics.failedComponentIndex = index;
      merged.diagnostics.failedComponentMinimumOriginalFace =
          componentDiagnostics.minimumOriginalFace;
      break;
    }

    const int outputVertexOffset = static_cast<int>(merged.vertices.rows());
    append_matrix_rows(merged.vertices, runs[index].result.vertices);
    append_matrix_rows(merged.faces, runs[index].result.faces,
                       outputVertexOffset);
    append_vector(merged.degrees, runs[index].result.degrees);

    const int cutVertexOffset = static_cast<int>(merged.cutVertices.rows());
    append_matrix_rows(merged.cutVertices, runs[index].result.cutVertices);
    append_matrix_rows(merged.cutFaces, runs[index].result.cutFaces,
                       cutVertexOffset);
    append_matrix_rows(merged.cutFunctions, runs[index].result.cutFunctions);
    append_matrix_rows(merged.cutCornerFunctions,
                       runs[index].result.cutCornerFunctions);
    append_matrix_rows(merged.rawCrossField, runs[index].result.rawCrossField);
    append_vector(merged.crossFieldMatching,
                  runs[index].result.crossFieldMatching);
    append_vector(merged.crossFieldEffort, runs[index].result.crossFieldEffort);
    append_vector(merged.crossFieldSingularCycles,
                  runs[index].result.crossFieldSingularCycles);
    append_vector(merged.crossFieldSingularIndices,
                  runs[index].result.crossFieldSingularIndices);

  }

  merged.diagnostics.componentMergeSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            mergeStart)
          .count() /
      1.0e6;
  clear_unavailable_surface_cell_counts(merged.diagnostics);
  set_overall_pipeline_time(merged, pipelineStart);
  return merged;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult remesh_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, const RemeshOptions &options) {
  const auto pipelineStart = RemeshPipelineClock::now();
  const bool surfaceCellsRequested =
      options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled;
  RemeshResult result;
  if (options.parallelizeComponents && surfaceCellsRequested) {
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    try {
      const fields::CrossFieldResult crossField =
          finalize_surface_cell_raw_cross_field(meshWhole, rawCrossField);
      result = remesh_surface_cell_components_from_cross_field(
          vertices, faces, crossField, options);
    } catch (...) {
      RemeshOptions sequentialOptions = options;
      sequentialOptions.parallelizeComponents = false;
      result = remesh_from_raw_cross_field_impl(
          meshWhole, rawCrossField, sequentialOptions);
    }
  } else if (options.parallelizeComponents) {
    result = remesh_components_from_raw_cross_field(
        vertices, faces, rawCrossField, options);
  } else {
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    result = remesh_from_raw_cross_field_impl(meshWhole, rawCrossField, options);
  }
  set_overall_pipeline_time(result, pipelineStart);
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult
remesh_from_cross_field_result(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const fields::CrossFieldResult &crossField,
                               const RemeshOptions &options) {
  const auto pipelineStart = RemeshPipelineClock::now();
  const bool surfaceCellsRequested =
      options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled;
  if (!surfaceCellsRequested &&
      (crossField.degree != fields::kCrossFieldDegree ||
       crossField.rawField.rows() != faces.rows() ||
       crossField.rawField.cols() != 12)) {
    throw std::runtime_error(
        "CrossFieldResult must contain a #F-by-12 degree-4 raw field.");
  }

  RemeshResult result;
  if (surfaceCellsRequested && options.parallelizeComponents) {
    result = remesh_surface_cell_components_from_cross_field(
        vertices, faces, crossField, options);
  } else if (surfaceCellsRequested) {
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    result = remesh_surface_cells_from_cross_field_impl(meshWhole, crossField,
                                                        options);
  } else {
    result = remesh_from_raw_cross_field(vertices, faces, crossField.rawField,
                                         options);
  }

  const bool crossFieldWasAccepted =
      !surfaceCellsRequested || result.surfaceCellContext.hasCrossField;
  if (!result.diagnostics.surfaceCellUsedLegacyFallback &&
      crossFieldWasAccepted) {
    result.crossFieldMatching = crossField.matching;
    result.crossFieldEffort = crossField.effort;
    result.crossFieldSingularCycles = crossField.singularCycles;
    result.crossFieldSingularIndices = crossField.singularIndices;
  }
  if (result.surfaceCellContext.hasCrossField) {
    result.surfaceCellContext.crossField = crossField;
    normalize_surface_cell_cross_field_directions(
        result.surfaceCellContext.crossField);
    result.surfaceCellContext.crossFieldHasMatching =
        result.surfaceCellContext.crossField.matchingComputed;
    result.surfaceCellContext.crossFieldHasSingularities =
        result.surfaceCellContext.crossField.singularitiesComputed;
  }
  set_overall_pipeline_time(result, pipelineStart);
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const Eigen::MatrixXd &secondaryDirections,
                        const RemeshOptions &options) {
  const auto pipelineStart = RemeshPipelineClock::now();
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd rawField =
      fields::make_raw_cross_field(meshWhole, primaryDirections,
                                   secondaryDirections,
                                   options.normalizeDirections);
  RemeshResult result =
      remesh_from_raw_cross_field(vertices, faces, rawField, options);
  set_overall_pipeline_time(result, pipelineStart);
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult
remesh_from_cross_field(const Eigen::MatrixXd &vertices,
                        const Eigen::MatrixXi &faces,
                        const Eigen::MatrixXd &primaryDirections,
                        const RemeshOptions &options) {
  const auto pipelineStart = RemeshPipelineClock::now();
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  const Eigen::MatrixXd secondaryDirections = fields::orthogonal_complement(
      meshWhole, primaryDirections, options.normalizeDirections);
  const Eigen::MatrixXd rawField =
      fields::make_raw_cross_field(meshWhole, primaryDirections,
                                   secondaryDirections,
                                   options.normalizeDirections);
  RemeshResult result =
      remesh_from_raw_cross_field(vertices, faces, rawField, options);
  set_overall_pipeline_time(result, pipelineStart);
  return result;
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult
remesh_from_mesh(const Eigen::MatrixXd &vertices,
                 const Eigen::MatrixXi &faces,
                 const RemeshOptions &options) {
  const auto pipelineStart = RemeshPipelineClock::now();
  TriMesh meshWhole;
  meshWhole.set_mesh(vertices, faces);
  if (options.preconditionInputMesh) {
    const auto preconditionStart = std::chrono::high_resolution_clock::now();
    geometry::BoundedMeshPreconditionerOptions preconditionOptions;
    preconditionOptions.enabled = true;
    preconditionOptions.targetFaceRatio = options.preconditionTargetFaceRatio;
    preconditionOptions.maxFaceRatio = options.preconditionMaxFaceRatio;
    preconditionOptions.minFaceRatio = options.preconditionMinFaceRatio;
    preconditionOptions.sharpAngleDegrees =
        options.preconditionSharpAngleDegrees;
    preconditionOptions.featureMap = options.featureMap;
    const geometry::BoundedMeshPreconditionerResult preconditioned =
        geometry::BoundedMeshPreconditioner::precondition(
            meshWhole.V, meshWhole.F, preconditionOptions);
    const double preconditioningSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now() - preconditionStart)
            .count() /
        1.0e6;
    bool appliedPreconditioning = false;
    try {
      meshWhole.set_mesh(preconditioned.vertices, preconditioned.faces);
      appliedPreconditioning = true;
    } catch (const std::exception &) {
      meshWhole.set_mesh(vertices, faces);
    }
    RemeshOptions preconditionedOptions = options;
    preconditionedOptions.preconditionInputMesh = false;

    report_progress(options.progress, 10, 110,
                    "Extracting source cross field");
    fields::CrossFieldOptions crossFieldOptions;
    crossFieldOptions.normalizeDirections = options.normalizeDirections;
    crossFieldOptions.computeMatching = true;
    const fields::CrossFieldResult crossField =
        fields::extract_cross_field(meshWhole, crossFieldOptions);
    RemeshResult result =
        remesh_from_raw_cross_field(meshWhole.V, meshWhole.F,
                                    crossField.rawField, preconditionedOptions);
    result.diagnostics.preconditioningSeconds = preconditioningSeconds;
    copy_adaptive_feature_diagnostics(result.diagnostics, preconditioned);
    result.diagnostics.preconditioningFlipsAccepted =
        appliedPreconditioning ? preconditioned.flipsAccepted : 0;
    result.diagnostics.preconditioningCollapsesAccepted =
        appliedPreconditioning ? preconditioned.collapsesAccepted : 0;
    result.diagnostics.preconditioningSplitsAccepted =
        appliedPreconditioning ? preconditioned.splitsAccepted : 0;
    result.diagnostics.preconditioningInputTriangleCount =
        preconditioned.inputTriangleCount;
    result.diagnostics.preconditioningOutputTriangleCount =
        appliedPreconditioning ? preconditioned.outputTriangleCount
                               : static_cast<std::size_t>(faces.rows());
    result.diagnostics.preconditioningMinAngleBefore =
        preconditioned.before.minTriangleAngleDegrees;
    result.diagnostics.preconditioningMinAngleAfter =
        appliedPreconditioning ? preconditioned.after.minTriangleAngleDegrees
                               : preconditioned.before.minTriangleAngleDegrees;
    result.diagnostics.preconditioningAspectRatioP95Before =
        preconditioned.before.aspectRatioP95;
    result.diagnostics.preconditioningAspectRatioP95After =
        appliedPreconditioning ? preconditioned.after.aspectRatioP95
                               : preconditioned.before.aspectRatioP95;
    result.diagnostics.preconditioningAspectRatioP99Before =
        preconditioned.before.aspectRatioP99;
    result.diagnostics.preconditioningAspectRatioP99After =
        appliedPreconditioning ? preconditioned.after.aspectRatioP99
                               : preconditioned.before.aspectRatioP99;
    result.diagnostics.preconditioningEdgeLengthCvBefore =
        preconditioned.before.edgeLengthCoefficientOfVariation;
    result.diagnostics.preconditioningEdgeLengthCvAfter =
        appliedPreconditioning
            ? preconditioned.after.edgeLengthCoefficientOfVariation
            : preconditioned.before.edgeLengthCoefficientOfVariation;
    set_overall_pipeline_time(result, pipelineStart);
    return result;
  }

  report_progress(options.progress, 10, 110, "Extracting source cross field");
  fields::CrossFieldOptions crossFieldOptions;
  crossFieldOptions.normalizeDirections = options.normalizeDirections;
  crossFieldOptions.computeMatching = true;
  const fields::CrossFieldResult crossField =
      fields::extract_cross_field(meshWhole, crossFieldOptions);

  RemeshOptions remeshOptions = options;
  remeshOptions.progress =
      [callback = options.progress](const std::size_t current,
                                    const std::size_t total,
                                    const std::string_view task) {
        const std::size_t safeTotal = std::max<std::size_t>(total, 1);
        const std::size_t safeCurrent =
            std::min(std::max<std::size_t>(current, 1), safeTotal);
        const std::size_t mapped =
            10 + safeCurrent * 100 / safeTotal;
        report_progress(callback, std::min<std::size_t>(mapped, 110), 110,
                        task);
      };
  RemeshResult result = remesh_from_cross_field_result(
      meshWhole.V, meshWhole.F, crossField, remeshOptions);
  set_overall_pipeline_time(result, pipelineStart);
  return result;
}

} // namespace directional::pipeline
