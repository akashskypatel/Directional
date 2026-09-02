#include <directional/pipeline/RemeshPipeline.h>
#include <directional/geometry/GeneralGraphMatching.h>
#include <directional/geometry/SourceChartTransitions.h>

#include <iterator>

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
  case SurfaceCellFailureCode::InvalidFieldTransportAtlas:
    return "InvalidFieldTransportAtlas";
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

SurfaceCellFailureCode surface_cell_failure_from_endpoint_completion(
    const geometry::FlowRepEndpointCompletionFailureKind kind) {
  switch (kind) {
  case geometry::FlowRepEndpointCompletionFailureKind::None:
    return SurfaceCellFailureCode::None;
  case geometry::FlowRepEndpointCompletionFailureKind::InvalidRetainedArcIdentity:
  case geometry::FlowRepEndpointCompletionFailureKind::DuplicateRetainedArc:
    return SurfaceCellFailureCode::InvalidFlowRepArcIdentity;
  case geometry::FlowRepEndpointCompletionFailureKind::
      IncompleteRetainedArcProvenance:
  case geometry::FlowRepEndpointCompletionFailureKind::
      GeneratedEndpointArcMissingProvenance:
    return SurfaceCellFailureCode::IncompleteFlowRepProvenance;
  case geometry::FlowRepEndpointCompletionFailureKind::InvalidOptions:
  case geometry::FlowRepEndpointCompletionFailureKind::IncompleteCrossFieldAxes:
  case geometry::FlowRepEndpointCompletionFailureKind::EndpointTraceLimitExceeded:
  case geometry::FlowRepEndpointCompletionFailureKind::
      UnresolvedRequiredEndpoints:
    return SurfaceCellFailureCode::NotProductionReady;
  }
  return SurfaceCellFailureCode::NotProductionReady;
}


} // namespace directional::pipeline

namespace directional::pipeline::remesh_pipeline_detail {

SurfaceCellFailureLocusDiagnostics
project_field_aligned_curve_network_failure_locus(
    const geometry::FieldAlignedCurveNetworkError &error,
    const authority::FieldTransportAtlas &atlas) {
  constexpr std::size_t kPublishedFailureEntryLimit = 8U;
  const auto topology_face_locus = [](
      const authority::SourceFaceTopologyKey &face) {
    const auto &vertices = face.vertices();
    return std::array<std::size_t, 3>{vertices[0].index(),
                                      vertices[1].index(),
                                      vertices[2].index()};
  };
  const auto topology_edge_locus = [](
      const authority::SourceEdgeTopologyKey &edge) {
    return std::array<std::size_t, 2>{edge.first().index(),
                                      edge.second().index()};
  };
  const auto exact_string = [](const authority::FieldExactRational &value) {
    return value.numerator_string() + "/" + value.denominator_string();
  };

  SurfaceCellFailureLocusDiagnostics locus;
  if (error.condition.has_value()) {
    locus.networkErrorCondition =
        geometry::field_aligned_curve_network_error_condition_name(
            *error.condition);
  }
  if (error.sourceVertex.has_value())
    locus.sourceVertex = error.sourceVertex->index();
  if (error.sourceEdge.has_value())
    locus.sourceEdge = topology_edge_locus(*error.sourceEdge);
  if (error.rail.has_value()) locus.rail = error.rail->index();
  if (error.singularity.has_value())
    locus.singularity = error.singularity->index();
  if (error.sourceFace.has_value())
    locus.sourceFace = topology_face_locus(*error.sourceFace);
  if (error.relatedSourceFace.has_value())
    locus.relatedSourceFace = topology_face_locus(*error.relatedSourceFace);
  if (error.branch.has_value())
    locus.branch = static_cast<int>(error.branch->value());
  if (error.relatedBranch.has_value())
    locus.relatedBranch = static_cast<int>(error.relatedBranch->value());
  if (error.topologyRegion.has_value())
    locus.topologyRegion = error.topologyRegion->index();
  locus.signedLift = error.signedLift;
  if (error.parameter.has_value())
    locus.parameter = exact_string(error.parameter->value);
  locus.exactValues.reserve(error.exactValues.size());
  for (const auto &value : error.exactValues)
    locus.exactValues.push_back(exact_string(value));
  locus.publishedEdges.reserve(error.publishedEdges.size());
  for (const auto &edge : error.publishedEdges)
    locus.publishedEdges.push_back(topology_edge_locus(edge));
  locus.publishedFaces.reserve(error.publishedFaces.size());
  for (const auto &face : error.publishedFaces)
    locus.publishedFaces.push_back(topology_face_locus(face));
  if (error.traceSeedVertex.has_value())
    locus.traceSeedVertex = error.traceSeedVertex->index();
  if (error.traceSeedSingularity.has_value())
    locus.traceSeedSingularity = error.traceSeedSingularity->index();
  locus.traceHistoryCount = error.traceHistory.size();
  locus.traceHistoryTruncated =
      error.traceHistory.size() > kPublishedFailureEntryLimit;
  const std::size_t traceLimit =
      std::min(kPublishedFailureEntryLimit, error.traceHistory.size());
  locus.traceHistory.reserve(traceLimit);
  for (std::size_t index = 0U; index < traceLimit; ++index) {
    const auto &step = error.traceHistory[index];
    SurfaceCellTraceStepDiagnostics projected;
    projected.sourceFace = topology_face_locus(step.sourceFace);
    projected.branch = static_cast<int>(step.branch.value());
    if (step.incomingCarrier.has_value())
      projected.incomingCarrier = topology_edge_locus(*step.incomingCarrier);
    projected.entryParameter = exact_string(step.entryParameter.value);
    locus.traceHistory.push_back(std::move(projected));
  }
  locus.traceSteps = error.traceSteps;
  locus.traceStepBudget = error.traceStepBudget;
  locus.traceCombinatorialVisits = error.traceCombinatorialVisits;
  locus.traceCombinatorialVisitAllowance =
      error.traceCombinatorialVisitAllowance;
  if (error.vertexArrivalMode.has_value()) {
    locus.vertexArrivalMode =
        *error.vertexArrivalMode == geometry::FieldVertexArrivalMode::FaceInterior
            ? "FaceInterior"
            : "EdgeTransit";
  }

  locus.vertexTransitStates.reserve(error.vertexTransitStates.size());
  for (const auto &state : error.vertexTransitStates) {
    SurfaceCellVertexTransitStateDiagnostics projected;
    projected.sourceFace = topology_face_locus(state.sourceFace);
    projected.branch = static_cast<int>(state.branch.value());
    projected.outcome =
        geometry::field_vertex_transit_state_outcome_name(state.outcome);
    if (state.representativeDirection.has_value()) {
      for (const auto &coordinate : state.representativeDirection->barycentric)
        projected.representativeDirection.push_back(exact_string(coordinate));
    }
    if (state.incomingDirection.has_value()) {
      for (const auto &coordinate : state.incomingDirection->barycentric)
        projected.incomingDirection.push_back(exact_string(coordinate));
    }
    if (state.transportEdge.has_value())
      projected.transportEdge = topology_edge_locus(*state.transportEdge);
    projected.transportPath.reserve(state.transportPath.size());
    for (const auto &edge : state.transportPath)
      projected.transportPath.push_back(topology_edge_locus(edge));
    projected.composedQuarterTurn = state.composedQuarterTurn;
    projected.eligibleForElection = state.eligibleForElection;
    projected.representativeInSector = state.representativeInSector;
    projected.incomingInSector = state.incomingInSector;
    locus.vertexTransitStates.push_back(std::move(projected));
  }

  if (error.vertexStarTransit.has_value()) {
    const auto &audit = *error.vertexStarTransit;
    switch (audit.kernelRoute) {
    case geometry::VertexStarDecisionKernelRoute::Filter:
      locus.vertexStarKernelRoute = "Filter"; break;
    case geometry::VertexStarDecisionKernelRoute::ExactFallback:
      locus.vertexStarKernelRoute = "ExactFallback"; break;
    case geometry::VertexStarDecisionKernelRoute::RationalShortCircuit:
      locus.vertexStarKernelRoute = "RationalShortCircuit"; break;
    case geometry::VertexStarDecisionKernelRoute::NotRun:
      locus.vertexStarKernelRoute = "NotRun"; break;
    }
    switch (audit.state) {
    case geometry::VertexStarTransitState::Owner:
      locus.vertexStarState = "Owner"; break;
    case geometry::VertexStarTransitState::TruncatedBeforeContinuation:
      locus.vertexStarState = "VertexStarTruncatedBeforeContinuation"; break;
    case geometry::VertexStarTransitState::DegenerateSector:
      locus.vertexStarState = "VertexStarDegenerateSector"; break;
    case geometry::VertexStarTransitState::ExactBudgetExceeded:
      locus.vertexStarState = "VertexStarExactBudgetExceeded"; break;
    case geometry::VertexStarTransitState::SeedUnavailable:
      locus.vertexStarState = "SeedUnavailable"; break;
    }
    locus.vertexStarFanLength = audit.fanLength;
    locus.vertexStarExactFanLengthBudget = audit.exactFanLengthBudget;
    locus.vertexStarClosedFan = audit.closedFan;
    locus.vertexStarTruncationReason = audit.truncationReason;
    locus.vertexStarConeAngleDefinition = audit.coneAngleDefinition;
    if (audit.seed.has_value()) {
      locus.vertexStarArrivalFace = topology_face_locus(audit.seed->arrivalFace);
      locus.vertexStarArrivalBranch =
          static_cast<int>(audit.seed->arrivalBranch.value());
      for (const auto &coordinate : audit.seed->arrivalRay.barycentric)
        locus.vertexStarArrivalRay.push_back(exact_string(coordinate));
      locus.vertexStarArrivalOnRadialRay = audit.seed->onRadialRay;
      if (audit.seed->radialRay.has_value())
        locus.vertexStarArrivalRadialRay = audit.seed->radialRay->index();
      if (audit.seed->provenanceTrace.has_value())
        locus.vertexStarProvenanceTrace = audit.seed->provenanceTrace->index();
      locus.vertexStarProvenanceEvent = audit.seed->provenanceEvent;
    }
    for (const auto &sector : audit.sectors) {
      locus.vertexStarFanFaces.push_back(topology_face_locus(sector.sourceFace));
      locus.vertexStarFanBranches.push_back(static_cast<int>(sector.branch.value()));
      locus.vertexStarFanNextRadialVertices.push_back(sector.nextRadialVertex.index());
      locus.vertexStarFanPreviousRadialVertices.push_back(
          sector.previousRadialVertex.index());
      locus.vertexStarSectorExactDPQ.push_back(
          {exact_string(sector.dot), exact_string(sector.normProduct),
           exact_string(sector.crossSquared)});
      locus.vertexStarSectorEligibleForElection.push_back(
          sector.eligibleForElection);
      locus.vertexStarSectorContainsContinuation.push_back(
          sector.containsContinuation);
      locus.vertexStarCandidateRepresentativeInOwnSector.push_back(
          sector.candidateRepresentativeInOwnSector);
    }
    locus.vertexStarOwnerCardinality = audit.ownerCardinality;
    if (audit.ownerFace.has_value())
      locus.vertexStarOwnerFace = topology_face_locus(*audit.ownerFace);
    if (audit.ownerBranch.has_value())
      locus.vertexStarOwnerBranch = static_cast<int>(audit.ownerBranch->value());
    locus.vertexStarOnRadialRay = audit.onRadialRay;
    if (audit.radialRay.has_value())
      locus.vertexStarRadialRay = audit.radialRay->index();
  }

  if (error.sourceVertex.has_value()) {
    locus.barrierAbsorbed = false;
    for (const auto &singularity : atlas.singularities()) {
      if (singularity.sourceVertex != *error.sourceVertex) continue;
      if (error.topologyRegion.has_value() &&
          singularity.topologyRegion != error.topologyRegion)
        continue;
      if (singularity.portPolicy ==
          authority::FieldSingularityFact::PortPolicy::BarrierAbsorbed) {
        locus.barrierAbsorbed = true;
        break;
      }
    }

    locus.barrierIncident = false;
    for (const auto &region : atlas.region_transport_diagnostics()) {
      if (error.topologyRegion.has_value() &&
          region.topologyRegion != *error.topologyRegion)
        continue;
      const auto found = std::find_if(
          region.barrierIncidentSingularities.begin(),
          region.barrierIncidentSingularities.end(),
          [&](const authority::FieldBarrierIncidentSingularityDiagnostics &row) {
            return row.sourceVertex == *error.sourceVertex;
          });
      if (found == region.barrierIncidentSingularities.end()) continue;
      locus.barrierIncident = true;
      locus.barrierDegree = found->barrierDegree;
      locus.transportStarComponentCount = found->transportStarComponentCount;
      break;
    }
  }
  return locus;
}

} // namespace directional::pipeline::remesh_pipeline_detail

namespace directional::pipeline {

namespace {

template <typename T>
std::uint64_t vector_owned_bytes(const std::vector<T> &values) {
  return static_cast<std::uint64_t>(values.capacity()) * sizeof(T);
}

template <typename T>
std::uint64_t vector_logical_bytes(const std::vector<T> &values) {
  return static_cast<std::uint64_t>(values.size()) * sizeof(T);
}

template <typename Derived>
std::uint64_t eigen_logical_bytes(const Eigen::MatrixBase<Derived> &values) {
  return static_cast<std::uint64_t>(values.size()) *
         sizeof(typename Derived::Scalar);
}

template <typename T>
std::uint64_t set_payload_owned_bytes(const std::set<T> &values) {
  // std::set does not expose allocator node capacity. Count the payload plus
  // the three links owned by each balanced-tree node; allocator bookkeeping is
  // intentionally excluded, matching the capacity-based completion telemetry.
  return static_cast<std::uint64_t>(values.size()) *
         (sizeof(T) + 3U * sizeof(void *));
}

template <typename T>
std::uint64_t set_payload_logical_bytes(const std::set<T> &values) {
  return static_cast<std::uint64_t>(values.size()) * sizeof(T);
}

std::uint64_t surface_trace_segment_owned_bytes(
    const geometry::SurfaceTraceSegment &segment) {
  return vector_owned_bytes(segment.entryRoute.steps());
}

std::uint64_t surface_trace_segment_logical_bytes(
    const geometry::SurfaceTraceSegment &segment) {
  return vector_logical_bytes(segment.entryRoute.steps());
}

std::uint64_t surface_trace_path_owned_bytes(
    const std::vector<geometry::SurfaceTraceSegment> &path) {
  std::uint64_t bytes = vector_owned_bytes(path);
  for (const geometry::SurfaceTraceSegment &segment : path) {
    bytes += surface_trace_segment_owned_bytes(segment);
  }
  return bytes;
}

std::uint64_t surface_trace_path_logical_bytes(
    const std::vector<geometry::SurfaceTraceSegment> &path) {
  std::uint64_t bytes = vector_logical_bytes(path);
  for (const geometry::SurfaceTraceSegment &segment : path) {
    bytes += surface_trace_segment_logical_bytes(segment);
  }
  return bytes;
}

std::uint64_t surface_trace_result_owned_bytes(
    const geometry::SurfaceTraceResult &trace) {
  return vector_owned_bytes(trace.states) +
         surface_trace_path_owned_bytes(trace.segments);
}

std::uint64_t surface_cell_rail_owned_bytes(
    const geometry::SurfaceCellRail &rail) {
  return vector_owned_bytes(rail.samples);
}

std::uint64_t trace_network_owned_bytes(
    const geometry::SurfaceCellNetwork &network) {
  std::uint64_t bytes = vector_owned_bytes(network.seeds) +
                        vector_owned_bytes(network.traces) +
                        vector_owned_bytes(network.singularSeparatrices) +
                        vector_owned_bytes(network.proposals) +
                        vector_owned_bytes(network.authoritativeRails) +
                        vector_owned_bytes(network.reliefRootVertices) +
                        static_cast<std::uint64_t>(
                            network.reliefRegionLabels.size()) * sizeof(int) +
                        set_payload_owned_bytes(network.reliefBarrierEdges);
  if (const auto *phaseFront = network.phaseFront.produced_product()) {
    bytes += vector_owned_bytes(phaseFront->edges()) +
             vector_owned_bytes(phaseFront->events()) +
             vector_owned_bytes(phaseFront->cells()) +
             vector_owned_bytes(phaseFront->isolationSeamTransportCertificates()) +
             static_cast<std::uint64_t>(phaseFront->sourceTopologyRegions().face_count()) *
                 (sizeof(authority::TopologyRegionId) + sizeof(std::size_t) +
                  sizeof(authority::SourceFaceTopologyKey) +
                  sizeof(authority::SourceFaceId)) +
             vector_owned_bytes(phaseFront->sourceTopologyRegions().regions());
    for (const geometry::SurfacePhaseFrontCell &cell : phaseFront->cells()) {
      for (const auto &path : cell.boundaryPaths) {
        bytes += surface_trace_path_owned_bytes(path);
      }
    }
    for (const geometry::SurfaceFrontEdge &edge : phaseFront->edges()) {
      bytes += vector_owned_bytes(edge.route.steps());
    }
    for (const geometry::SurfaceTopologyRegion &region :
         phaseFront->sourceTopologyRegions().regions()) {
      bytes += vector_owned_bytes(region.faces()) +
               vector_owned_bytes(region.boundary_edges()) +
               vector_owned_bytes(region.isolation_seams());
    }
  }
  for (const geometry::SurfaceTraceResult &trace : network.traces) {
    bytes += surface_trace_result_owned_bytes(trace);
  }
  for (const geometry::SurfaceSingularitySeparatrix &separatrix :
       network.singularSeparatrices) {
    bytes += surface_trace_result_owned_bytes(separatrix.trace);
  }
  for (const geometry::SurfaceCellProposal &proposal : network.proposals) {
    bytes += surface_trace_path_owned_bytes(proposal.sides);
    for (const auto &path : proposal.boundaryPaths) {
      bytes += surface_trace_path_owned_bytes(path);
    }
  }
  for (const geometry::SurfaceCellRail &rail : network.authoritativeRails) {
    bytes += surface_cell_rail_owned_bytes(rail);
  }
  return bytes;
}

std::uint64_t trace_network_logical_bytes(
    const geometry::SurfaceCellNetwork &network) {
  std::uint64_t bytes = vector_logical_bytes(network.seeds) +
                        vector_logical_bytes(network.traces) +
                        vector_logical_bytes(network.singularSeparatrices) +
                        vector_logical_bytes(network.proposals) +
                        vector_logical_bytes(network.authoritativeRails) +
                        vector_logical_bytes(network.reliefRootVertices) +
                        eigen_logical_bytes(network.reliefRegionLabels) +
                        set_payload_logical_bytes(network.reliefBarrierEdges);
  if (const auto *phaseFront = network.phaseFront.produced_product()) {
    bytes += vector_logical_bytes(phaseFront->edges()) +
             vector_logical_bytes(phaseFront->events()) +
             vector_logical_bytes(phaseFront->cells()) +
             vector_logical_bytes(phaseFront->isolationSeamTransportCertificates()) +
             static_cast<std::uint64_t>(phaseFront->sourceTopologyRegions().face_count()) *
                 (sizeof(authority::TopologyRegionId) + sizeof(std::size_t) +
                  sizeof(authority::SourceFaceTopologyKey) +
                  sizeof(authority::SourceFaceId)) +
             vector_logical_bytes(phaseFront->sourceTopologyRegions().regions());
    for (const geometry::SurfacePhaseFrontCell &cell : phaseFront->cells()) {
      for (const auto &path : cell.boundaryPaths) {
        bytes += surface_trace_path_logical_bytes(path);
      }
    }
    for (const geometry::SurfaceFrontEdge &edge : phaseFront->edges()) {
      bytes += vector_logical_bytes(edge.route.steps());
    }
    for (const geometry::SurfaceTopologyRegion &region :
         phaseFront->sourceTopologyRegions().regions()) {
      bytes += vector_logical_bytes(region.faces()) +
               vector_logical_bytes(region.boundary_edges()) +
               vector_logical_bytes(region.isolation_seams());
    }
  }
  for (const geometry::SurfaceTraceResult &trace : network.traces) {
    bytes += vector_logical_bytes(trace.states) +
             surface_trace_path_logical_bytes(trace.segments);
  }
  for (const geometry::SurfaceSingularitySeparatrix &separatrix :
       network.singularSeparatrices) {
    bytes += vector_logical_bytes(separatrix.trace.states) +
             surface_trace_path_logical_bytes(separatrix.trace.segments);
  }
  for (const geometry::SurfaceCellProposal &proposal : network.proposals) {
    bytes += surface_trace_path_logical_bytes(proposal.sides);
    for (const auto &path : proposal.boundaryPaths) {
      bytes += surface_trace_path_logical_bytes(path);
    }
  }
  for (const geometry::SurfaceCellRail &rail : network.authoritativeRails) {
    bytes += vector_logical_bytes(rail.samples);
  }
  return bytes;
}

std::uint64_t flow_rep_arc_vector_owned_bytes(
    const std::vector<geometry::FlowRepArc> &arcs) {
  std::uint64_t bytes = vector_owned_bytes(arcs);
  for (const geometry::FlowRepArc &arc : arcs) {
    bytes += vector_owned_bytes(arc.substitutions);
  }
  return bytes;
}

std::uint64_t flow_rep_arc_vector_logical_bytes(
    const std::vector<geometry::FlowRepArc> &arcs) {
  std::uint64_t bytes = vector_logical_bytes(arcs);
  for (const geometry::FlowRepArc &arc : arcs) {
    bytes += vector_logical_bytes(arc.substitutions);
  }
  return bytes;
}

std::uint64_t flow_rep_cycle_owned_bytes(
    const geometry::FlowRepCycleInput &cycle) {
  std::uint64_t bytes = vector_owned_bytes(cycle.sideArcIds) +
                        vector_owned_bytes(cycle.boundaryArcIds) +
                        vector_owned_bytes(cycle.normals) +
                        vector_owned_bytes(cycle.boundaryNormalA) +
                        vector_owned_bytes(cycle.boundaryNormalB) +
                        vector_owned_bytes(cycle.distanceA) +
                        vector_owned_bytes(cycle.distanceB) +
                        vector_owned_bytes(cycle.surfaceDistances) +
                        vector_owned_bytes(cycle.sideCounts);
  for (const std::vector<int> &side : cycle.sideArcIds) {
    bytes += vector_owned_bytes(side);
  }
  return bytes;
}

std::uint64_t flow_rep_selection_input_owned_bytes(
    const geometry::FlowRepSelectionInput &input) {
  std::uint64_t bytes = flow_rep_arc_vector_owned_bytes(input.arcs) +
                        vector_owned_bytes(input.coverageSamples) +
                        vector_owned_bytes(input.cycles);
  for (const geometry::FlowRepCycleInput &cycle : input.cycles) {
    bytes += flow_rep_cycle_owned_bytes(cycle);
  }
  return bytes;
}

std::uint64_t sparse_flow_rep_owned_bytes(
    const geometry::FlowRepSparseNetwork &network) {
  return vector_owned_bytes(network.retainedArcIds) +
         vector_owned_bytes(network.removedArcIds) +
         vector_owned_bytes(network.endpointTags) +
         vector_owned_bytes(network.cycleEvaluations);
}

std::uint64_t sparse_flow_rep_logical_bytes(
    const geometry::FlowRepSparseNetwork &network) {
  return vector_logical_bytes(network.retainedArcIds) +
         vector_logical_bytes(network.removedArcIds) +
         vector_logical_bytes(network.endpointTags) +
         vector_logical_bytes(network.cycleEvaluations);
}

std::uint64_t endpoint_completion_owned_bytes(
    const geometry::FlowRepEndpointCompletionResult &completion) {
  std::uint64_t bytes = vector_owned_bytes(completion.diagnostics);
  if (const auto *failure = completion.rejection()) {
    bytes += static_cast<std::uint64_t>(failure->detail.capacity());
  }
  if (const auto *product = completion.produced_product()) {
    bytes += flow_rep_arc_vector_owned_bytes(product->arcs) +
             vector_owned_bytes(product->retainedArcIds) +
             vector_owned_bytes(product->endpointTags);
  }
  return bytes;
}

std::uint64_t endpoint_completion_logical_bytes(
    const geometry::FlowRepEndpointCompletionResult &completion) {
  std::uint64_t bytes = vector_logical_bytes(completion.diagnostics);
  if (const auto *failure = completion.rejection()) {
    bytes += static_cast<std::uint64_t>(failure->detail.size());
  }
  if (const auto *product = completion.produced_product()) {
    bytes += flow_rep_arc_vector_logical_bytes(product->arcs) +
             vector_logical_bytes(product->retainedArcIds) +
             vector_logical_bytes(product->endpointTags);
  }
  return bytes;
}

std::uint64_t surface_complex_owned_bytes(
    const geometry::SurfaceCellComplex &complex) {
  if (complex.diagnostics.retainedMemoryBytes != 0U) {
    return complex.diagnostics.retainedMemoryBytes;
  }
  std::uint64_t bytes = vector_owned_bytes(complex.nodes) +
                        vector_owned_bytes(complex.halfedges) +
                        vector_owned_bytes(complex.cells);
  for (const geometry::SurfaceArrangementNode &node : complex.nodes) {
    bytes += vector_owned_bytes(node.occurrences);
  }
  for (const geometry::SurfaceArrangementHalfedge &edge : complex.halfedges) {
    bytes += vector_owned_bytes(edge.provenance);
  }
  for (const geometry::SurfaceArrangementCell &cell : complex.cells) {
    bytes += vector_owned_bytes(cell.sourceFaces) +
             vector_owned_bytes(cell.halfedges) +
             vector_owned_bytes(cell.sideFamilies) +
             vector_owned_bytes(cell.sideEdgeCounts);
  }
  return bytes;
}

std::uint64_t surface_complex_logical_bytes(
    const geometry::SurfaceCellComplex &complex) {
  std::uint64_t bytes = vector_logical_bytes(complex.nodes) +
                        vector_logical_bytes(complex.halfedges) +
                        vector_logical_bytes(complex.cells);
  for (const geometry::SurfaceArrangementNode &node : complex.nodes) {
    bytes += vector_logical_bytes(node.occurrences);
  }
  for (const geometry::SurfaceArrangementHalfedge &edge : complex.halfedges) {
    bytes += vector_logical_bytes(edge.provenance);
  }
  for (const geometry::SurfaceArrangementCell &cell : complex.cells) {
    bytes += vector_logical_bytes(cell.sourceFaces) +
             vector_logical_bytes(cell.halfedges) +
             vector_logical_bytes(cell.sideFamilies) +
             vector_logical_bytes(cell.sideEdgeCounts);
  }
  return bytes;
}

std::uint64_t simplification_candidate_owned_bytes(
    const geometry::SurfaceSimplificationCandidate &candidate) {
  return vector_owned_bytes(candidate.elementIds) +
         vector_owned_bytes(candidate.affectedNodeIds) +
         vector_owned_bytes(candidate.affectedCellIds) +
         vector_owned_bytes(candidate.affectedStrandIds);
}

std::uint64_t simplification_candidate_vector_owned_bytes(
    const std::vector<geometry::SurfaceSimplificationCandidate> &candidates) {
  std::uint64_t bytes = vector_owned_bytes(candidates);
  for (const geometry::SurfaceSimplificationCandidate &candidate :
       candidates) {
    bytes += simplification_candidate_owned_bytes(candidate);
  }
  return bytes;
}

std::uint64_t simplification_candidates_owned_bytes(
    const geometry::SurfaceSimplificationCandidateSet &set) {
  return simplification_candidate_vector_owned_bytes(set.candidates);
}

std::uint64_t simplification_transaction_vector_owned_bytes(
    const std::vector<geometry::SurfaceSimplificationTransaction> &transactions) {
  std::uint64_t bytes = vector_owned_bytes(transactions);
  for (const geometry::SurfaceSimplificationTransaction &transaction :
       transactions) {
    bytes += vector_owned_bytes(transaction.elementIds) +
             vector_owned_bytes(transaction.affectedCellIds);
  }
  return bytes;
}

std::uint64_t simplification_candidate_vector_logical_bytes(
    const std::vector<geometry::SurfaceSimplificationCandidate> &candidates) {
  std::uint64_t bytes = vector_logical_bytes(candidates);
  for (const geometry::SurfaceSimplificationCandidate &candidate : candidates) {
    bytes += vector_logical_bytes(candidate.elementIds) +
             vector_logical_bytes(candidate.affectedNodeIds) +
             vector_logical_bytes(candidate.affectedCellIds) +
             vector_logical_bytes(candidate.affectedStrandIds);
  }
  return bytes;
}

std::uint64_t simplification_transaction_vector_logical_bytes(
    const std::vector<geometry::SurfaceSimplificationTransaction> &transactions) {
  std::uint64_t bytes = vector_logical_bytes(transactions);
  for (const geometry::SurfaceSimplificationTransaction &transaction :
       transactions) {
    bytes += vector_logical_bytes(transaction.elementIds) +
             vector_logical_bytes(transaction.affectedCellIds);
  }
  return bytes;
}

std::uint64_t simplification_result_logical_bytes(
    const geometry::SurfaceSimplificationResult &result) {
  return vector_logical_bytes(result.elements) +
         surface_complex_logical_bytes(result.complex) +
         simplification_transaction_vector_logical_bytes(result.transactions);
}

std::uint64_t simplification_result_owned_bytes(
    const geometry::SurfaceSimplificationResult &result) {
  return vector_owned_bytes(result.elements) +
         surface_complex_owned_bytes(result.complex) +
         simplification_transaction_vector_owned_bytes(result.transactions);
}

} // namespace

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

namespace {

struct RemeshResultBuilder : RemeshProduct {
  SurfaceCellPipelineContext surfaceCellContext;
  directional::RemeshDiagnostics diagnostics;

  [[nodiscard]] RemeshResult finish_produced(
      const RemeshProductKind kind, const bool crossFieldAccepted) && {
    RemeshProduct output =
        std::move(static_cast<RemeshProduct &>(*this));
    return RemeshResult::produced(
        std::move(output), kind, crossFieldAccepted,
        std::move(surfaceCellContext), std::move(diagnostics));
  }

  [[nodiscard]] RemeshResult finish_rejected(RemeshFailure failure) && {
    return RemeshResult::rejected(
        std::move(failure), std::move(surfaceCellContext),
        std::move(diagnostics));
  }
};

void set_overall_pipeline_time(
    RemeshResultBuilder &result, const RemeshPipelineClock::time_point start) {
  result.diagnostics.overallPipelineSeconds = remesh_elapsed_seconds(start);
  result.diagnostics.overallPipelineTimeAvailable = true;
}

} // namespace

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

void hash_vector(std::uint64_t &seed,
                 const std::vector<std::uint64_t> &values) {
  hash_combine_u64(seed, values.size());
  for (const std::uint64_t value : values) {
    hash_combine_u64(seed, value);
  }
}

template <typename Tag>
void hash_semantic_id(
    std::uint64_t &seed, const authority::SemanticId<Tag> &value) {
  hash_combine_u64(seed, value.index());
}

template <typename Tag>
void hash_optional_semantic_id(
    std::uint64_t &seed,
    const std::optional<authority::SemanticId<Tag>> &value) {
  hash_combine_i64(seed, value.has_value() ? 1 : 0);
  if (value.has_value()) hash_semantic_id(seed, value.value());
}

template <typename Tag>
void hash_vector(
    std::uint64_t &seed,
    const std::vector<authority::SemanticId<Tag>> &values) {
  hash_combine_u64(seed, values.size());
  for (const auto &value : values) {
    hash_semantic_id(seed, value);
  }
}

void hash_source_edge_topology_key(
    std::uint64_t &seed, const authority::SourceEdgeTopologyKey &topology) {
  hash_semantic_id(seed, topology.first());
  hash_semantic_id(seed, topology.second());
}

void hash_vector(
    std::uint64_t &seed,
    const std::vector<authority::SourceEdgeTopologyKey> &values) {
  hash_combine_u64(seed, values.size());
  for (const auto &value : values) {
    hash_source_edge_topology_key(seed, value);
  }
}

void hash_grid_automorphism(
    std::uint64_t &seed, const authority::GridAutomorphism &action) {
  hash_combine_i64(seed, action.rotation.value());
  hash_combine_i64(seed, action.shift.x);
  hash_combine_i64(seed, action.shift.y);
}

void hash_canonical_route(
    std::uint64_t &seed, const authority::CanonicalRoute &route) {
  hash_combine_u64(seed, route.steps().size());
  for (const authority::TransitionStep &step : route.steps()) {
    hash_source_edge_topology_key(seed, step.topology());
    hash_combine_i64(seed, static_cast<int>(step.kind()));
    hash_combine_i64(seed, step.interior().has_value() ? 1 : 0);
    if (step.interior().has_value()) {
      hash_semantic_id(seed, step.interior().value());
    }
    hash_grid_automorphism(seed, step.transport());
    hash_combine_i64(seed, static_cast<int>(step.orientation()));
  }
  hash_combine_i64(seed, static_cast<int>(route.canonical_orientation()));
}

void hash_source_face_topology_key(
    std::uint64_t &seed, const authority::SourceFaceTopologyKey &topology) {
  for (const authority::SourceVertexId vertex : topology.vertices()) {
    hash_semantic_id(seed, vertex);
  }
}

void hash_source_support(
    std::uint64_t &seed,
    const std::optional<authority::SourceSupport> &support) {
  hash_combine_i64(seed, support.has_value() ? 1 : 0);
  if (!support.has_value()) return;
  hash_combine_i64(seed, static_cast<int>(authority::support_kind(*support)));
  if (const auto *vertex =
          std::get_if<authority::SourceVertexSupport>(&*support)) {
    hash_semantic_id(seed, vertex->vertex);
  } else if (const auto *edge =
                 std::get_if<authority::SourceEdgeSupport>(&*support)) {
    hash_source_edge_topology_key(seed, edge->edge);
  } else if (const auto *face =
                 std::get_if<authority::SourceFaceInteriorSupport>(&*support)) {
    hash_source_face_topology_key(seed, face->face);
  }
}

void hash_source_projection_chart(
    std::uint64_t &seed, const geometry::SourceProjectionChart &chart) {
  hash_semantic_id(seed, chart.chart);
  hash_source_face_topology_key(seed, chart.face);
}

void hash_optional_source_projection_chart(
    std::uint64_t &seed,
    const std::optional<geometry::SourceProjectionChart> &chart) {
  hash_combine_i64(seed, chart.has_value() ? 1 : 0);
  if (chart.has_value()) hash_source_projection_chart(seed, *chart);
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
  hash_combine_i64(seed, segment.sourceChart.has_value() ? 1 : 0);
  if (segment.sourceChart.has_value()) {
    hash_semantic_id(seed, segment.sourceChart.value());
  }
  hash_canonical_route(seed, segment.entryRoute);
  hash_optional_semantic_id(seed, segment.railId);
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
  for (const authority::SourceEdgeTopologyKey &barrier : network.reliefBarrierEdges) {
    hash_combine_i64(seed, barrier.first().index());
    hash_combine_i64(seed, barrier.second().index());
  }
  hash_combine_u64(seed, network.authoritativeRails.size());
  for (const geometry::SurfaceCellRail &rail : network.authoritativeRails) {
    hash_semantic_id(seed, rail.id);
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
  hash_combine_i64(
      seed, static_cast<int>(network.phaseFront.disposition()));
  if (const auto *failure = network.phaseFront.rejection()) {
    hash_combine_i64(seed, static_cast<int>(failure->reason));
    hash_combine_i64(seed, failure->cell);
    hash_combine_i64(seed, failure->side);
    hash_combine_i64(seed, failure->face);
    hash_combine_i64(seed, failure->targetFace);
    hash_combine_i64(seed, failure->sourceVertex);
    hash_combine_i64(seed, failure->sourceEdge);
    hash_combine_i64(seed, failure->secondarySourceEdge);
  }
  if (const auto *phaseFront = network.phaseFront.produced_product()) {
    // Source-face rows are representation locators and never participate in
    // semantic hashes. The region product is already ordered canonically by
    // row-independent source-face topology.
    hash_combine_u64(seed, phaseFront->sourceTopologyRegions().regions().size());
    for (const auto &region : phaseFront->sourceTopologyRegions().regions()) {
      hash_semantic_id(seed, region.id());
      hash_semantic_id(seed, region.component());
      hash_combine_i64(seed, region.euler_characteristic());
      hash_combine_i64(seed, region.boundary_loop_count());
      hash_combine_u64(seed, geometry::surface_topology_region_hash(region));
      hash_vector(seed, region.boundary_edges());
      hash_vector(seed, region.isolation_seams());
      for (const geometry::SourceRegionFaceAuthority &face : region.faces()) {
        hash_source_face_topology_key(seed, face.topology);
        hash_semantic_id(seed, face.sheet);
      }
    }
    hash_combine_i64(seed, phaseFront->gridU());
    hash_combine_i64(seed, phaseFront->gridV());
    hash_combine_u64(
        seed, phaseFront->isolationSeamTransportCertificates().size());
    for (const auto &certificate :
         phaseFront->isolationSeamTransportCertificates()) {
      hash_semantic_id(seed, certificate.region());
      hash_source_edge_topology_key(seed, certificate.seam());
      hash_semantic_id(seed, certificate.transition());
      hash_source_face_topology_key(seed, certificate.firstFace());
      hash_source_face_topology_key(seed, certificate.secondFace());
      hash_semantic_id(seed, certificate.firstSheet());
      hash_semantic_id(seed, certificate.secondSheet());
      hash_combine_i64(seed, certificate.forward().value());
      hash_combine_i64(seed, certificate.reverse().value());
      hash_combine_u64(
          seed, geometry::surface_cell_tracing_detail::
                    isolation_seam_transport_certificate_hash(certificate));
    }
    hash_combine_u64(seed, phaseFront->periodicHolonomies().size());
    for (const auto &relation : phaseFront->periodicHolonomies()) {
      hash_semantic_id(seed, relation.sourceTopologyRegion());
      hash_grid_automorphism(seed, relation.action());
      hash_canonical_route(seed, relation.route());
      hash_canonical_route(seed, relation.cutRoute());
    }
    if (!phaseFront->boundedDiskBoundaryPhases().empty()) {
      hash_combine_u64(seed, phaseFront->boundedDiskBoundaryPhases().size());
    }
    for (const auto &phase : phaseFront->boundedDiskBoundaryPhases()) {
      hash_semantic_id(seed, phase.sourceTopologyRegion);
      hash_combine_i64(seed, phase.chartUBranch);
      hash_combine_i64(seed, phase.signedQuarterTurnSum);
      hash_combine_double(seed, phase.totalIntrinsicLength);
      hash_combine_i64(seed, phase.rectangular ? 1 : 0);
      hash_combine_i64(seed, phase.polygonClosed ? 1 : 0);
      hash_combine_i64(seed, phase.chartConstructed ? 1 : 0);
      hash_combine_u64(seed, phase.structuralHash);
      hash_combine_u64(seed, phase.runs.size());
      for (const auto &run : phase.runs) {
        hash_combine_i64(seed, run.branch);
        hash_combine_i64(seed, run.family);
        hash_combine_i64(seed, run.sign);
        hash_combine_i64(seed, run.signedQuarterTurnToNext);
        hash_combine_double(seed, run.cumulativeIntrinsicLength);
        hash_combine_double(seed, run.intrinsicLength);
        hash_combine_double(seed, run.chartStart.x());
        hash_combine_double(seed, run.chartStart.y());
        hash_combine_double(seed, run.chartEnd.x());
        hash_combine_double(seed, run.chartEnd.y());
        hash_vector(seed, run.sourceEdgeTopology);
        hash_combine_u64(seed, run.edgeAuthority.size());
        for (const auto &authority : run.edgeAuthority) {
          hash_combine_i64(seed, authority.sourceBoundary ? 1 : 0);
          hash_combine_i64(seed, authority.hardFeature ? 1 : 0);
          hash_combine_i64(seed, authority.sourceSheet ? 1 : 0);
        }
      }
    }
    const auto hash_lattice_state = [&](
        const geometry::LocalLatticeState &state) {
      hash_combine_double(seed, state.phase.x());
      hash_combine_double(seed, state.phase.y());
      hash_combine_i64(seed, state.latticeCoordinate.x);
      hash_combine_i64(seed, state.latticeCoordinate.y);
      hash_combine_i64(seed, state.branchRotation);
      hash_combine_i64(seed, state.scaleLevel);
      hash_combine_i64(seed, state.sourceChart.has_value() ? 1 : 0);
      if (state.sourceChart.has_value()) {
        hash_combine_i64(
            seed, static_cast<std::int64_t>(
                      (
                          state.sourceChart.value()).index()));
      }
    };
    hash_combine_u64(seed, phaseFront->edges().size());
    for (const geometry::SurfaceFrontEdge &edge : phaseFront->edges()) {
      hash_trace_point(seed, edge.from);
      hash_trace_point(seed, edge.to);
      hash_combine_i64(seed, edge.family);
      hash_combine_i64(seed, edge.advanceSign);
      hash_lattice_state(edge.fromLattice);
      hash_lattice_state(edge.toLattice);
      hash_semantic_id(seed, edge.filledCell);
      hash_combine_i64(seed, edge.filledSide);
      hash_combine_i64(seed, edge.oppositeEdge);
      hash_combine_i64(seed, edge.unfilledSide);
      hash_combine_i64(seed, edge.exterior ? 1 : 0);
      hash_semantic_id(seed, edge.sourceTopologyRegion);
      hash_combine_i64(seed, static_cast<int>(edge.boundaryKind));
      hash_combine_i64(seed, edge.periodicRelation.has_value() ? 1 : 0);
      if (edge.periodicRelation.has_value()) {
        hash_semantic_id(seed, edge.periodicRelation.value());
      }
      hash_optional_semantic_id(seed, edge.railId);
      hash_canonical_route(seed, edge.route);
    }
    hash_combine_u64(seed, phaseFront->events().size());
    for (const geometry::SurfaceFrontEvent &event : phaseFront->events()) {
      hash_combine_i64(seed, static_cast<int>(event.kind));
      hash_combine_i64(seed, event.firstEdge);
      hash_combine_i64(seed, event.secondEdge);
    }
    hash_combine_u64(seed, phaseFront->cells().size());
    for (const geometry::SurfacePhaseFrontCell &cell : phaseFront->cells()) {
      hash_semantic_id(seed, cell.id);
      hash_semantic_id(seed, cell.sourceTopologyRegion);
      hash_combine_i64(seed, cell.orientationValidated ? 1 : 0);
      for (const geometry::SurfaceTracePoint &corner : cell.corners) {
        hash_trace_point(seed, corner);
      }
      for (const geometry::LocalLatticeState &state : cell.lattice) {
        hash_lattice_state(state);
      }
      for (const auto &path : cell.boundaryPaths) {
        hash_combine_u64(seed, path.size());
        for (const geometry::SurfaceTraceSegment &segment : path) {
          hash_trace_segment(seed, segment);
        }
      }
    }
  }
  hash_combine_u64(seed, network.seeds.size());
  for (const geometry::SurfaceTraceSeed &traceSeed : network.seeds) {
    hash_combine_i64(seed, traceSeed.id);
    hash_trace_point(seed, traceSeed.point);
    hash_combine_i64(seed, static_cast<int>(traceSeed.provenance));
    hash_combine_i64(seed, traceSeed.sourceId);
    hash_optional_semantic_id(seed, traceSeed.hardRailId);
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
    hash_optional_semantic_id(seed, arc.sourceTopologyRegion);
    hash_optional_semantic_id(seed, arc.sourceIsolationSheet);
    hash_combine_i64(seed, arc.family);
    hash_combine_i64(seed, arc.featureClass);
    hash_combine_i64(seed, arc.mandatoryRail ? 1 : 0);
    hash_combine_i64(seed, arc.boundaryRail ? 1 : 0);
    hash_combine_i64(seed, arc.hardFeatureRail ? 1 : 0);
    hash_combine_i64(seed, arc.strandProvenance);
    hash_combine_i64(seed, arc.featureProvenance);
    hash_optional_semantic_id(seed, arc.railId);
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
    hash_optional_semantic_id(seed, sample.sourceTopologyRegion);
    hash_optional_semantic_id(seed, sample.sourceIsolationSheet);
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
    hash_optional_semantic_id(seed, arc.railId);
    hash_combine_i64(seed, arc.curveId);
    hash_optional_semantic_id(seed, arc.sourceTopologyRegion);
    hash_optional_source_projection_chart(seed, arc.sourceChart);
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
      hash_optional_semantic_id(seed, occurrence.sourceTopologyRegion);
      hash_optional_source_projection_chart(seed, occurrence.sourceChart);
      hash_combine_i64(seed, occurrence.sourceArc);
      hash_combine_i64(seed, occurrence.provenance);
      hash_optional_semantic_id(seed, occurrence.railId);
      hash_combine_i64(seed, occurrence.curveId);
      hash_combine_double(seed, occurrence.sourceT0);
      hash_combine_double(seed, occurrence.sourceT1);
      hash_combine_double(seed, occurrence.railT0);
      hash_combine_double(seed, occurrence.railT1);
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
    hash_optional_semantic_id(seed, halfedge.railId);
    hash_combine_i64(seed, halfedge.curveId);
    hash_optional_semantic_id(seed, halfedge.sourceTopologyRegion);
    hash_optional_source_projection_chart(seed, halfedge.sourceChart);
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
    hash_optional_semantic_id(seed, cell.sourceTopologyRegion);
    hash_combine_u64(seed, cell.sourceCharts.size());
    for (const auto &chart : cell.sourceCharts) {
      hash_source_projection_chart(seed, chart);
    }
    hash_vector(seed, cell.sourceFaces);
    hash_vector(seed, cell.halfedges);
    hash_vector(seed, cell.boundaryCycleOffsets);
    hash_vector(seed, cell.sourceBoundaryLoopIds);
    hash_vector(seed, cell.sideFamilies);
    hash_vector(seed, cell.sideEdgeCounts);
    hash_combine_double(seed, cell.signedArea);
    hash_combine_double(seed, cell.area);
    hash_combine_i64(seed, cell.boundaryCycle ? 1 : 0);
    hash_combine_i64(seed, cell.closed ? 1 : 0);
    hash_combine_i64(seed, cell.disk ? 1 : 0);
    hash_combine_i64(seed, cell.boundaryComponentCount);
    hash_combine_i64(seed, cell.eulerCharacteristic);
    hash_combine_i64(seed, cell.sourceBoundarySide);
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
  hash_combine_i64(seed, complex.diagnostics.directedWedgeCount);
  hash_combine_i64(seed, complex.diagnostics.successorMissingCount);
  hash_combine_i64(seed, complex.diagnostics.successorAmbiguityCount);
  hash_combine_i64(
      seed, complex.diagnostics.predecessorMultiplicityFailureCount);
  hash_combine_i64(seed, complex.diagnostics.repeatedNodeCycleCount);
  hash_combine_i64(seed, complex.diagnostics.repeatedEdgeCycleCount);
  hash_combine_i64(seed,
                   static_cast<int>(complex.diagnostics.incidenceFailure));
  hash_combine_i64(seed, complex.diagnostics.incidenceFailureNode);
  hash_combine_i64(seed, complex.diagnostics.incidenceFailureHalfedge);
  hash_combine_i64(seed, complex.diagnostics.incidenceFailureTwin);
  hash_combine_i64(seed, complex.diagnostics.incidenceFailureNext);
  hash_combine_i64(
      seed, static_cast<std::int64_t>(complex.diagnostics.directedIncidenceHash));
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
  hash_combine_u64(seed, mesh.boundaryNodeIdentities.size());
  for (const geometry::SurfaceCellCanonicalIdentity &identity :
       mesh.boundaryNodeIdentities) {
    hash_combine_u64(seed, identity.hash());
  }
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
    hash_combine_i64(seed, static_cast<int>(lineage.stitchIdentity.kind));
    hash_combine_u64(seed, lineage.stitchIdentity.hash());
    hash_combine_i64(seed,
                     static_cast<int>(lineage.authoritativeIdentity.kind));
    hash_combine_u64(seed, lineage.authoritativeIdentity.hash());
    hash_vector(seed, lineage.sourceTopologyRegions);
    hash_vector(seed, lineage.sourceIsolationSheets);
    hash_source_support(seed, lineage.sourceSupport);
    hash_combine_i64(seed, lineage.quotientClass.has_value() ? 1 : 0);
    if (lineage.quotientClass.has_value()) {
      hash_semantic_id(seed, lineage.quotientClass.value());
    }
    hash_vector(seed, lineage.sourceOccurrences);
    hash_combine_u64(seed, lineage.sourceCharts.size());
    for (const auto &chart : lineage.sourceCharts) {
      hash_semantic_id(seed, chart.chart);
      hash_source_face_topology_key(seed, chart.face);
    }
    hash_combine_u64(seed, lineage.equivalences.size());
    for (const auto &equivalence : lineage.equivalences) {
      hash_combine_i64(seed, static_cast<int>(equivalence.kind));
      hash_combine_i64(seed, equivalence.firstFrontEdge);
      hash_combine_i64(seed, equivalence.secondFrontEdge);
      hash_combine_i64(seed, equivalence.periodicRelation.has_value() ? 1 : 0);
      if (equivalence.periodicRelation.has_value()) {
        hash_semantic_id(seed, equivalence.periodicRelation.value());
      }
      hash_optional_semantic_id(seed, equivalence.railId);
      hash_grid_automorphism(seed, equivalence.action);
      hash_canonical_route(seed, equivalence.route);
      hash_vector(seed, equivalence.isolationSeams);
    }
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

authority::SourceEdgeTopologyKey surface_cell_source_edge_key(
    const int a, const int b, const std::size_t vertexExtent) {
  const auto key = authority::SourceEdgeTopologyKey::from_indices(
      a, b, vertexExtent);
  if (!key) {
    throw std::invalid_argument("invalid pipeline source-edge topology key");
  }
  return key.value();
}

std::uint64_t surface_cell_source_edge_diagnostic_key(
    const authority::SourceEdgeTopologyKey &key) {
  const auto first = static_cast<std::uint64_t>(key.first().index());
  const auto second = static_cast<std::uint64_t>(key.second().index());
  // One-way diagnostic projection only. This value is never decoded back into
  // source-edge authority.
  return (first << 32U) | second;
}

std::set<std::uint64_t> relief_representation_edges(
    const std::set<authority::SourceEdgeTopologyKey> &semanticEdges) {
  std::set<std::uint64_t> representation;
  for (const authority::SourceEdgeTopologyKey &edge : semanticEdges) {
    representation.insert(geometry::relief_topology_detail::edge_key(
        static_cast<int>(edge.first().index()),
        static_cast<int>(edge.second().index())));
  }
  // ReliefTopology owns an operation-local integer representation. It is a
  // one-way projection from typed source-edge authority and is never decoded.
  return representation;
}

} // namespace directional::pipeline

namespace directional::pipeline {

AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const geometry::SurfacePhaseFrontProduct &phaseFront) {
  AuthoritativePhaseFrontMeshResult result;
  if (phaseFront.cells().empty() || phaseFront.edges().empty()) {
    result.failure = "MissingAuthoritativePhaseFront";
    return result;
  }
  if (sourceVertices.cols() != 3 || sourceFaces.cols() != 3 ||
      phaseFront.sourceTopologyRegions().face_count() !=
          static_cast<std::size_t>(sourceFaces.rows())) {
    result.failure = "InvalidAuthoritativePhaseFrontSource";
    return result;
  }

  result.mesh.sourcePatch = 0;
  result.mesh.backend = geometry::PureQuadCompletionBackend::ClosedForm;
  result.mesh.usesCenterFan = false;

  const auto trace_equal = [](const geometry::SurfaceTracePoint &first,
                              const geometry::SurfaceTracePoint &second) {
    return first.face == second.face &&
           (first.barycentric - second.barycentric).norm() <= 1.0e-10;
  };
  const auto lattice_equal = [](const geometry::LocalLatticeState &first,
                                const geometry::LocalLatticeState &second) {
    if (!first.sourceChart.has_value() || !second.sourceChart.has_value()) {
      return false;
    }
    return first.latticeCoordinate == second.latticeCoordinate &&
           first.branchRotation == second.branchRotation &&
           first.scaleLevel == second.scaleLevel &&
           first.sourceChart.value() == second.sourceChart.value() &&
           (first.phase - second.phase).norm() <= 1.0e-10;
  };
  const auto source_face_id = [&](const int face)
      -> std::optional<authority::SourceFaceId> {
    const auto id = authority::SourceFaceId::from_index(
        face, static_cast<std::size_t>(sourceFaces.rows()));
    return id ? std::optional<authority::SourceFaceId>(id.value())
              : std::nullopt;
  };
  const auto make_surface_point = [&](const geometry::SurfaceTracePoint &trace) {
    geometry::SurfacePoint point;
    if (trace.face < 0 || trace.face >= sourceFaces.rows() ||
        !trace.barycentric.allFinite() ||
        std::abs(trace.barycentric.sum() - 1.0) > 1.0e-8 ||
        trace.barycentric.minCoeff() < -1.0e-8) {
      return point;
    }
    const auto faceId = source_face_id(trace.face);
    if (!faceId.has_value()) {
      return point;
    }
    point.face = trace.face;
    // Semantic component/sheet ownership stays in typed source authority and
    // lineage support. SurfacePoint's legacy integer fields are representation
    // payload only and must not mirror typed authority IDs.
    point.component = -1;
    point.sheet = -1;
    point.barycentric = trace.barycentric.transpose();
    point.position =
        point.barycentric(0) *
            sourceVertices.row(sourceFaces(trace.face, 0)).transpose() +
        point.barycentric(1) *
            sourceVertices.row(sourceFaces(trace.face, 1)).transpose() +
        point.barycentric(2) *
            sourceVertices.row(sourceFaces(trace.face, 2)).transpose();
    point.squaredDistance = 0.0;
    return point;
  };
  const geometry::SurfacePointSourceSupportResolver sourceSupportResolver(
      sourceFaces);

  std::map<authority::TopologyRegionId,
           const geometry::SurfaceTopologyRegion *> topologyRegionById;
  if (phaseFront.sourceTopologyRegions().face_count() !=
      static_cast<std::size_t>(sourceFaces.rows())) {
    result.failure = "AuthoritativeTopologyRegionMapMismatch";
    return result;
  }
  std::vector<char> mappedFaces(static_cast<std::size_t>(sourceFaces.rows()), 0);
  for (const auto &region : phaseFront.sourceTopologyRegions().regions()) {
    if (region.faces().empty() ||
        !topologyRegionById.emplace(region.id(), &region).second) {
      result.failure = "InvalidAuthoritativeTopologyRegion";
      return result;
    }
    for (const geometry::SourceRegionFaceAuthority &member : region.faces()) {
      const auto faceId =
          phaseFront.sourceTopologyRegions().row_for_topology(member.topology);
      if (!faceId.has_value()) {
        result.failure = "AuthoritativeTopologyRegionMapMismatch";
        return result;
      }
      const auto face = static_cast<int>(faceId->index());
      if (face < 0 || face >= sourceFaces.rows() ||
          mappedFaces[static_cast<std::size_t>(face)] != 0 ||
          phaseFront.sourceTopologyRegions().region_for_row(*faceId) !=
              region.id()) {
        result.failure = "AuthoritativeTopologyRegionMapMismatch";
        return result;
      }
      mappedFaces[static_cast<std::size_t>(face)] = 1;
    }
  }
  if (topologyRegionById.empty() ||
      std::any_of(mappedFaces.begin(), mappedFaces.end(),
                  [](char mapped) { return mapped == 0; })) {
    result.failure = topologyRegionById.empty()
                         ? "MissingAuthoritativeTopologyRegions"
                         : "AuthoritativeTopologyRegionMapMismatch";
    return result;
  }

  const auto exactSourceIncidence =
      geometry::surface_cell_tracing_detail::edge_faces(sourceFaces);
  const auto sourceEdgeIndices =
      geometry::surface_cell_tracing_detail::edge_matching_indices(
          exactSourceIncidence);
  const auto exactSourceIncidenceByTopology = exactSourceIncidence;
  std::map<authority::SourceEdgeTopologyKey, authority::InteriorTransitionId>
      sourceTransitionByTopology;
  for (const auto &[topology, transitionRow] : sourceEdgeIndices) {
    const auto transition = authority::InteriorTransitionId::from_index(
        transitionRow, sourceEdgeIndices.size());
    if (!transition) {
      result.failure = "InvalidAuthoritativeSourceEdgeTransition";
      return result;
    }
    sourceTransitionByTopology.emplace(topology, transition.value());
  }
  const auto canonical_source_face = [&](const int face)
      -> std::optional<authority::SourceFaceTopologyKey> {
    std::array<authority::SourceVertexId, 3> vertices = {
        authority::SourceVertexId::from_index(sourceFaces(face, 0),
                                              sourceVertices.rows()).value(),
        authority::SourceVertexId::from_index(sourceFaces(face, 1),
                                              sourceVertices.rows()).value(),
        authority::SourceVertexId::from_index(sourceFaces(face, 2),
                                              sourceVertices.rows()).value()};
    const auto topology = authority::SourceFaceTopologyKey::make(vertices);
    if (!topology) return std::nullopt;
    return topology.value();
  };

  using IsolationSeamKey =
      std::pair<authority::TopologyRegionId,
                authority::SourceEdgeTopologyKey>;
  std::map<IsolationSeamKey,
           const geometry::SurfaceIsolationSeamTransportCertificate *>
      isolationCertificateBySeam;
  std::map<authority::TopologyRegionId,
           std::map<authority::IsolationSheetId,
                    std::set<authority::IsolationSheetId>>>
      isolationSheetGraphByRegion;
  std::size_t requiredIsolationSeams = 0U;
  std::map<authority::TopologyRegionId,
           std::vector<authority::IsolationSheetId>> regionSheetsById;
  for (const auto &[regionId, region] : topologyRegionById) {
    std::vector<authority::IsolationSheetId> regionSheets =
        region->isolation_sheets();
    if (regionSheets.empty() ||
        !std::is_sorted(regionSheets.begin(), regionSheets.end()) ||
        std::adjacent_find(regionSheets.begin(), regionSheets.end()) !=
            regionSheets.end() ||
        !std::is_sorted(region->isolation_seams().begin(),
                        region->isolation_seams().end()) ||
        std::adjacent_find(region->isolation_seams().begin(),
                           region->isolation_seams().end()) !=
            region->isolation_seams().end()) {
      result.failure = "InvalidAuthoritativeTopologyRegionIsolationAuthority";
      return result;
    }
    regionSheetsById.emplace(regionId, regionSheets);
    auto &graph = isolationSheetGraphByRegion[regionId];
    for (const authority::IsolationSheetId sheet : regionSheets) {
      graph[sheet];
    }
    requiredIsolationSeams += region->isolation_seams().size();
  }

  for (const auto &certificate :
       phaseFront.isolationSeamTransportCertificates()) {
    const auto region = topologyRegionById.find(certificate.region());
    const IsolationSeamKey key{certificate.region(), certificate.seam()};
    const auto incidence =
        exactSourceIncidenceByTopology.find(certificate.seam());
    const auto sourceTransition =
        sourceTransitionByTopology.find(certificate.seam());
    if (region == topologyRegionById.end() ||
        !std::binary_search(
            region->second->isolation_seams().begin(),
            region->second->isolation_seams().end(),
            certificate.seam()) ||
        !isolationCertificateBySeam.emplace(key, &certificate).second ||
        incidence == exactSourceIncidenceByTopology.end() ||
        incidence->second[0] < 0 || incidence->second[1] < 0 ||
        incidence->second[0] == incidence->second[1] ||
        sourceTransition == sourceTransitionByTopology.end() ||
        certificate.transition() != sourceTransition->second ||
        certificate.firstSheet() == certificate.secondSheet() ||
        certificate.forward().inverse() != certificate.reverse()) {
      result.failure = "InvalidAuthoritativeIsolationSeamCertificate";
      return result;
    }

    int firstFace = incidence->second[0];
    int secondFace = incidence->second[1];
    auto firstTopology = canonical_source_face(firstFace);
    auto secondTopology = canonical_source_face(secondFace);
    if (!firstTopology.has_value() || !secondTopology.has_value()) {
      result.failure = "InvalidAuthoritativeIsolationSeamCertificate";
      return result;
    }
    if (secondTopology.value() < firstTopology.value()) {
      std::swap(firstFace, secondFace);
      std::swap(firstTopology, secondTopology);
    }
    if (firstTopology.value() != certificate.firstFace() ||
        secondTopology.value() != certificate.secondFace() ||
        !source_face_id(firstFace).has_value() ||
        !source_face_id(secondFace).has_value() ||
        phaseFront.sourceTopologyRegions().region_for_row(*source_face_id(firstFace)) !=
            certificate.region() ||
        phaseFront.sourceTopologyRegions().region_for_row(*source_face_id(secondFace)) !=
            certificate.region() ||
        phaseFront.sourceTopologyRegions().component_for_row(*source_face_id(firstFace)) !=
            region->second->component() ||
        phaseFront.sourceTopologyRegions().component_for_row(*source_face_id(secondFace)) !=
            region->second->component() ||
        phaseFront.sourceTopologyRegions().sheet_for_row(*source_face_id(firstFace)) !=
            certificate.firstSheet() ||
        phaseFront.sourceTopologyRegions().sheet_for_row(*source_face_id(secondFace)) !=
            certificate.secondSheet() ||
        !std::binary_search(regionSheetsById.at(certificate.region()).begin(),
                            regionSheetsById.at(certificate.region()).end(),
                            certificate.firstSheet()) ||
        !std::binary_search(regionSheetsById.at(certificate.region()).begin(),
                            regionSheetsById.at(certificate.region()).end(),
                            certificate.secondSheet())) {
      result.failure = "IsolationSeamCertificateSourceAuthorityMismatch";
      return result;
    }
    auto &graph = isolationSheetGraphByRegion[certificate.region()];
    graph[certificate.firstSheet()].insert(certificate.secondSheet());
    graph[certificate.secondSheet()].insert(certificate.firstSheet());
  }
  if (isolationCertificateBySeam.size() != requiredIsolationSeams) {
    result.failure = "IsolationSeamCertificateBijectionMismatch";
    return result;
  }
  for (const auto &[regionId, region] : topologyRegionById) {
    for (const authority::SourceEdgeTopologyKey &seam :
         region->isolation_seams()) {
      if (isolationCertificateBySeam.count({regionId, seam}) != 1U) {
        result.failure = "IsolationSeamCertificateBijectionMismatch";
        return result;
      }
    }
  }

  const auto isolation_sheets_connected_typed =
      [&](const authority::TopologyRegionId regionId,
          const std::vector<authority::IsolationSheetId> &sheets) {
        const auto graph = isolationSheetGraphByRegion.find(regionId);
        if (graph == isolationSheetGraphByRegion.end() || sheets.empty() ||
            !std::is_sorted(sheets.begin(), sheets.end()) ||
            std::adjacent_find(sheets.begin(), sheets.end()) != sheets.end()) {
          return false;
        }
        for (const authority::IsolationSheetId sheet : sheets) {
          if (graph->second.count(sheet) == 0U) return false;
        }
        std::set<authority::IsolationSheetId> reached;
        std::vector<authority::IsolationSheetId> stack{sheets.front()};
        while (!stack.empty()) {
          const authority::IsolationSheetId sheet = stack.back();
          stack.pop_back();
          if (!reached.insert(sheet).second) continue;
          const auto neighbors = graph->second.find(sheet);
          if (neighbors == graph->second.end()) continue;
          for (const authority::IsolationSheetId neighbor : neighbors->second) {
            if (reached.count(neighbor) == 0U) stack.push_back(neighbor);
          }
        }
        return std::all_of(sheets.begin(), sheets.end(),
                           [&](const authority::IsolationSheetId sheet) {
          return reached.count(sheet) != 0U;
        });
      };
  for (const auto &[regionId, region] : topologyRegionById) {
    if (!isolation_sheets_connected_typed(regionId, regionSheetsById.at(regionId))) {
      result.failure = "DisconnectedAuthoritativeIsolationSheetGraph";
      return result;
    }
  }

  struct OccurrenceData {
    OccurrenceData(authority::OccurrenceId occurrenceId,
                   geometry::SurfacePoint sourcePoint,
                   authority::SourceSupport sourceSupport,
                   geometry::SourceProjectionChart sourceChart,
                   geometry::LocalLatticeState latticeState,
                   authority::TopologyRegionId region,
                   authority::IsolationSheetId sheet, int cornerIndex)
        : id(occurrenceId), point(std::move(sourcePoint)),
          support(std::move(sourceSupport)), chart(std::move(sourceChart)),
          lattice(std::move(latticeState)), topologyRegion(region),
          isolationSheet(sheet), corner(cornerIndex) {}

    authority::OccurrenceId id;
    geometry::SurfacePoint point;
    authority::SourceSupport support;
    geometry::SourceProjectionChart chart;
    geometry::LocalLatticeState lattice;
    authority::TopologyRegionId topologyRegion;
    authority::IsolationSheetId isolationSheet;
    int corner = -1;
  };
  const int occurrenceCount = static_cast<int>(phaseFront.cells().size()) * 4;
  std::vector<OccurrenceData> occurrences;
  occurrences.reserve(static_cast<std::size_t>(occurrenceCount));
  std::vector<int> parents(static_cast<std::size_t>(occurrenceCount));
  std::vector<int> ranks(static_cast<std::size_t>(occurrenceCount), 0);
  std::iota(parents.begin(), parents.end(), 0);
  const auto find_root = [&](int value) {
    int root = value;
    while (parents[static_cast<std::size_t>(root)] != root) {
      root = parents[static_cast<std::size_t>(root)];
    }
    while (parents[static_cast<std::size_t>(value)] != value) {
      const int next = parents[static_cast<std::size_t>(value)];
      parents[static_cast<std::size_t>(value)] = root;
      value = next;
    }
    return root;
  };
  const auto unite = [&](int first, int second) {
    int firstRoot = find_root(first);
    int secondRoot = find_root(second);
    if (firstRoot == secondRoot) return;
    if (ranks[static_cast<std::size_t>(firstRoot)] <
        ranks[static_cast<std::size_t>(secondRoot)]) {
      std::swap(firstRoot, secondRoot);
    }
    parents[static_cast<std::size_t>(secondRoot)] = firstRoot;
    if (ranks[static_cast<std::size_t>(firstRoot)] ==
        ranks[static_cast<std::size_t>(secondRoot)]) {
      ++ranks[static_cast<std::size_t>(firstRoot)];
    }
  };

  std::map<authority::CellId, int> cellIndexById;
  for (int cellIndex = 0;
       cellIndex < static_cast<int>(phaseFront.cells().size()); ++cellIndex) {
    const auto &cell = phaseFront.cells()[static_cast<std::size_t>(cellIndex)];
    if (!cellIndexById.emplace(cell.id, cellIndex).second) {
      result.invalidCell = static_cast<int>(cell.id.index());
      result.failure = "InvalidAuthoritativePhaseFrontCell";
      return result;
    }
  }
  using OccurrenceOwnerKey = std::pair<authority::CellId, int>;
  std::set<OccurrenceOwnerKey> occurrenceOwnerKeys;
  for (const auto &cell : phaseFront.cells()) {
    for (int corner = 0; corner < 4; ++corner) {
      if (!occurrenceOwnerKeys.emplace(cell.id, corner).second) {
        result.invalidCell = static_cast<int>(cell.id.index());
        result.failure = "InvalidAuthoritativePhaseFrontCorner";
        return result;
      }
    }
  }
  if (occurrenceOwnerKeys.size() != static_cast<std::size_t>(occurrenceCount)) {
    result.failure = "InvalidAuthoritativePhaseFrontCorner";
    return result;
  }
  std::map<OccurrenceOwnerKey, authority::OccurrenceId> occurrenceIdByOwner;
  std::size_t canonicalOccurrenceOrdinal = 0U;
  for (const OccurrenceOwnerKey &owner : occurrenceOwnerKeys) {
    const auto occurrenceId = authority::OccurrenceId::from_index(
        static_cast<std::int64_t>(canonicalOccurrenceOrdinal),
        static_cast<std::size_t>(occurrenceCount));
    if (!occurrenceId ||
        !occurrenceIdByOwner.emplace(owner, occurrenceId.value()).second) {
      result.failure = "InvalidAuthoritativePhaseFrontCorner";
      return result;
    }
    ++canonicalOccurrenceOrdinal;
  }
  std::set<authority::TopologyRegionId> consumedTopologyRegions;
  for (int cellIndex = 0;
       cellIndex < static_cast<int>(phaseFront.cells().size()); ++cellIndex) {
    const auto &cell = phaseFront.cells()[static_cast<std::size_t>(cellIndex)];
    result.invalidCell = static_cast<int>(cell.id.index());
    const auto region = topologyRegionById.find(cell.sourceTopologyRegion);
    if (!cell.orientationValidated || region == topologyRegionById.end() ||
        regionSheetsById.at(cell.sourceTopologyRegion).empty() ||
        !isolation_sheets_connected_typed(
            cell.sourceTopologyRegion,
            regionSheetsById.at(cell.sourceTopologyRegion))) {
      result.failure = "InvalidAuthoritativePhaseFrontCell";
      return result;
    }
    consumedTopologyRegions.insert(cell.sourceTopologyRegion);
    for (int corner = 0; corner < 4; ++corner) {
      const auto &trace = cell.corners[static_cast<std::size_t>(corner)];
      const auto faceId = source_face_id(trace.face);
      if (!faceId.has_value()) {
        result.failure = "AuthoritativePhaseFrontSourceLabelMismatch";
        return result;
      }
      const authority::SourceComponentId typedComponent =
          phaseFront.sourceTopologyRegions().component_for_row(*faceId);
      const authority::IsolationSheetId typedSheet =
          phaseFront.sourceTopologyRegions().sheet_for_row(*faceId);
      if (typedComponent != region->second->component() ||
          phaseFront.sourceTopologyRegions().region_for_row(*faceId) !=
              cell.sourceTopologyRegion ||
          !std::binary_search(
              regionSheetsById.at(cell.sourceTopologyRegion).begin(),
              regionSheetsById.at(cell.sourceTopologyRegion).end(),
              typedSheet)) {
        result.failure = "AuthoritativePhaseFrontSourceLabelMismatch";
        return result;
      }
      geometry::SurfacePoint point = make_surface_point(trace);
      const auto resolvedSupport = sourceSupportResolver.resolve(point);
      const geometry::LocalLatticeState &lattice =
          cell.lattice[static_cast<std::size_t>(corner)];
      const auto occurrenceOwner =
          occurrenceIdByOwner.find(OccurrenceOwnerKey{cell.id, corner});
      if (!point.valid() || !point.position.allFinite() ||
          !resolvedSupport.valid() || !resolvedSupport.identity.has_value() ||
          !lattice.sourceChart.has_value() ||
          occurrenceOwner == occurrenceIdByOwner.end()) {
        result.failure = "InvalidAuthoritativePhaseFrontCorner";
        return result;
      }
      occurrences.emplace_back(
          occurrenceOwner->second, std::move(point),
          resolvedSupport.identity.value(),
          geometry::SourceProjectionChart(
              lattice.sourceChart.value(),
              phaseFront.sourceTopologyRegions().topology_for_row(*faceId)),
          lattice, cell.sourceTopologyRegion, typedSheet, corner);
    }
  }
  if (consumedTopologyRegions.size() != topologyRegionById.size()) {
    result.failure = "IncompleteAuthoritativeTopologyRegionConsumption";
    return result;
  }

  std::vector<int> edgeByCellSide(
      static_cast<std::size_t>(occurrenceCount), -1);
  std::vector<std::vector<authority::SourceEdgeTopologyKey>>
      isolationSeamsByFrontEdge(phaseFront.edges().size());
  const auto exact_interior_route_valid =
      [&](const authority::CanonicalRoute &route) {
    if (route.empty()) return false;
    std::set<authority::SourceEdgeTopologyKey> uniqueTopology;
    for (const authority::TransitionStep &step : route.steps()) {
      if (step.kind() != authority::TransitionStepKind::Interior ||
          !step.interior().has_value() ||
          !uniqueTopology.insert(step.topology()).second) {
        return false;
      }
      const auto incidence = exactSourceIncidenceByTopology.find(step.topology());
      const auto expectedTransition =
          sourceTransitionByTopology.find(step.topology());
      if (incidence == exactSourceIncidenceByTopology.end() ||
          incidence->second[0] < 0 || incidence->second[1] < 0 ||
          expectedTransition == sourceTransitionByTopology.end() ||
          step.interior().value() != expectedTransition->second) {
        return false;
      }
    }
    return true;
  };
  const auto interior_source_route_valid = [&](const auto &edge) {
    return exact_interior_route_valid(edge.route);
  };
  for (int edgeIndex = 0;
       edgeIndex < static_cast<int>(phaseFront.edges().size()); ++edgeIndex) {
    result.invalidEdge = edgeIndex;
    const auto &edge = phaseFront.edges()[static_cast<std::size_t>(edgeIndex)];
    const auto cell = cellIndexById.find(edge.filledCell);
    if (cell == cellIndexById.end() || edge.filledSide < 0 ||
        edge.filledSide >= 4 || edge.unfilledSide != 0) {
      result.failure = "InvalidAuthoritativePhaseFrontOwnership";
      return result;
    }
    const auto &owner =
        phaseFront.cells()[static_cast<std::size_t>(cell->second)];
    const int slot = cell->second * 4 + edge.filledSide;
    const auto edgeRegion = topologyRegionById.find(edge.sourceTopologyRegion);
    if (edgeByCellSide[static_cast<std::size_t>(slot)] >= 0 ||
        edge.sourceTopologyRegion != owner.sourceTopologyRegion ||
        edgeRegion == topologyRegionById.end() ||
        !trace_equal(edge.from,
                     owner.corners[static_cast<std::size_t>(edge.filledSide)]) ||
        !trace_equal(edge.to, owner.corners[static_cast<std::size_t>(
                                  (edge.filledSide + 1) % 4)]) ||
        !lattice_equal(edge.fromLattice,
                       owner.lattice[static_cast<std::size_t>(
                           edge.filledSide)]) ||
        !lattice_equal(edge.toLattice,
                       owner.lattice[static_cast<std::size_t>(
                           (edge.filledSide + 1) % 4)]) ||
        !isolation_sheets_connected_typed(
            edge.sourceTopologyRegion, edgeRegion->second->isolation_sheets())) {
      result.failure = "InvalidAuthoritativePhaseFrontSideAuthority";
      return result;
    }
    edgeByCellSide[static_cast<std::size_t>(slot)] = edgeIndex;
    auto &crossedIsolationSeams =
        isolationSeamsByFrontEdge[static_cast<std::size_t>(edgeIndex)];
    for (const auto &segment :
         owner.boundaryPaths[static_cast<std::size_t>(edge.filledSide)]) {
      for (const authority::TransitionStep &step :
           segment.entryRoute.oriented_steps()) {
        if (step.kind() != authority::TransitionStepKind::Interior ||
            !step.interior().has_value()) {
          result.failure = "InvalidAuthoritativeTransitionSourceEdge";
          return result;
        }
        const auto incidence =
            exactSourceIncidenceByTopology.find(step.topology());
        const auto sourceTransition =
            sourceTransitionByTopology.find(step.topology());
        if (incidence == exactSourceIncidenceByTopology.end() ||
            incidence->second[0] < 0 || incidence->second[1] < 0 ||
            sourceTransition == sourceTransitionByTopology.end() ||
            step.interior().value() != sourceTransition->second) {
          result.failure = "InvalidAuthoritativeTransitionSourceEdge";
          return result;
        }
        if (isolationCertificateBySeam.count(
                {edge.sourceTopologyRegion, step.topology()}) != 0U) {
          crossedIsolationSeams.push_back(step.topology());
          continue;
        }
        const bool belongsToOtherRegion = std::any_of(
            isolationCertificateBySeam.begin(),
            isolationCertificateBySeam.end(), [&](const auto &entry) {
              return entry.first.second == step.topology();
            });
        if (belongsToOtherRegion) {
          result.failure = "IsolationSeamTransitionOwnerMismatch";
          return result;
        }
      }
    }
    std::sort(crossedIsolationSeams.begin(), crossedIsolationSeams.end());
    crossedIsolationSeams.erase(
        std::unique(crossedIsolationSeams.begin(),
                    crossedIsolationSeams.end()),
        crossedIsolationSeams.end());
    const bool hasOpposite = edge.oppositeEdge >= 0;
    if (hasOpposite == edge.exterior ||
        (hasOpposite &&
         (edge.oppositeEdge >= static_cast<int>(phaseFront.edges().size()) ||
          phaseFront.edges()[static_cast<std::size_t>(edge.oppositeEdge)]
                  .oppositeEdge != edgeIndex))) {
      result.failure = "InvalidAuthoritativePhaseFrontOwnership";
      return result;
    }
    switch (edge.boundaryKind) {
    case geometry::SurfaceFrontBoundaryKind::OrdinaryInterior:
      if (!hasOpposite || edge.periodicRelation.has_value() || edge.exterior ||
          !edge.route.empty()) {
        result.failure = "InvalidOrdinaryFrontRelation";
        return result;
      }
      break;
    case geometry::SurfaceFrontBoundaryKind::GenuineSourceBoundary:
      if (hasOpposite || !edge.exterior || edge.periodicRelation.has_value() ||
          edge.route.empty()) {
        result.failure = "InvalidSourceBoundaryAuthority";
        return result;
      }
      {
        std::set<authority::SourceEdgeTopologyKey> uniqueTopology;
        for (const authority::TransitionStep &step : edge.route.steps()) {
          const auto sourceEdge =
              exactSourceIncidenceByTopology.find(step.topology());
          if (step.kind() != authority::TransitionStepKind::Boundary ||
              step.interior().has_value() ||
              !uniqueTopology.insert(step.topology()).second ||
              sourceEdge == exactSourceIncidenceByTopology.end() ||
              sourceEdge->second[1] >= 0) {
            result.failure = "FalseAuthoritativeSourceBoundary";
            return result;
          }
        }
      }
      break;
    case geometry::SurfaceFrontBoundaryKind::HardRail:
      if (!hasOpposite || edge.exterior ||
          !interior_source_route_valid(edge)) {
        result.failure = "InvalidHardRailAuthority";
        return result;
      }
      break;
    case geometry::SurfaceFrontBoundaryKind::EmbeddedReliefCut:
      result.failure = "UnsupportedEmbeddedReliefCut";
      return result;
    case geometry::SurfaceFrontBoundaryKind::PeriodicCut:
      if (!hasOpposite || edge.exterior || !edge.periodicRelation.has_value() ||
          !interior_source_route_valid(edge)) {
        result.failure = "InvalidPeriodicCutAuthority";
        return result;
      }
      break;
    }
  }
  if (std::any_of(edgeByCellSide.begin(), edgeByCellSide.end(),
                  [](const int edge) { return edge < 0; })) {
    result.failure = "IncompleteAuthoritativePhaseFrontSides";
    return result;
  }

  std::map<authority::PeriodicRelationId,
           const geometry::SurfacePeriodicHolonomy *> periodicRelationById;
  for (const auto &relation : phaseFront.periodicHolonomies()) {
    const auto region = topologyRegionById.find(relation.sourceTopologyRegion());
    if (region == topologyRegionById.end() ||
        !periodicRelationById.emplace(relation.id(), &relation).second ||
        !isolation_sheets_connected_typed(
            relation.sourceTopologyRegion(), region->second->isolation_sheets())) {
      result.failure = "InvalidPeriodicRelationIsolationAuthority";
      return result;
    }
  }

  std::set<authority::PeriodicRelationId> consumedPeriodicRelations;
  std::vector<std::vector<geometry::PureQuadEquivalenceProvenance>>
      occurrenceEquivalences(static_cast<std::size_t>(occurrenceCount));
  const auto canonical_route = [](std::vector<std::uint64_t> route) {
    std::vector<std::uint64_t> reversed(route.rbegin(), route.rend());
    return reversed < route ? reversed : route;
  };
  const auto action_matches = [&](const geometry::LocalLatticeState &first,
                                  const geometry::LocalLatticeState &second,
                                  const authority::GridAutomorphism &action) {
    const authority::LatticeTranslation transformed =
        action.apply(first.latticeCoordinate);
    const authority::QuarterTurn transformedRotation =
        compose(action.rotation,
                authority::QuarterTurn::from_integer(first.branchRotation));
    return transformed == second.latticeCoordinate &&
           transformedRotation ==
               authority::QuarterTurn::from_integer(second.branchRotation) &&
           first.scaleLevel == second.scaleLevel;
  };
  for (int edgeIndex = 0;
       edgeIndex < static_cast<int>(phaseFront.edges().size()); ++edgeIndex) {
    const auto &first = phaseFront.edges()[static_cast<std::size_t>(edgeIndex)];
    if (first.oppositeEdge < 0 || edgeIndex > first.oppositeEdge) continue;
    result.invalidEdge = edgeIndex;
    const int secondIndex = first.oppositeEdge;
    const auto &second =
        phaseFront.edges()[static_cast<std::size_t>(secondIndex)];
    const bool periodicPair =
        first.boundaryKind ==
        geometry::SurfaceFrontBoundaryKind::PeriodicCut;
    if (first.boundaryKind != second.boundaryKind ||
        (!periodicPair &&
         (first.family != second.family ||
          first.advanceSign == second.advanceSign))) {
      result.failure = "IncompatibleAuthoritativeFrontPair";
      return result;
    }
    const int firstCell = cellIndexById[first.filledCell];
    const int secondCell = cellIndexById[second.filledCell];
    const int firstFrom = firstCell * 4 + first.filledSide;
    const int firstTo = firstCell * 4 + (first.filledSide + 1) % 4;
    const int secondFrom = secondCell * 4 + second.filledSide;
    const int secondTo = secondCell * 4 + (second.filledSide + 1) % 4;
    if (occurrences[static_cast<std::size_t>(firstFrom)].support !=
            occurrences[static_cast<std::size_t>(secondTo)].support ||
        occurrences[static_cast<std::size_t>(firstTo)].support !=
            occurrences[static_cast<std::size_t>(secondFrom)].support) {
      result.failure = "AuthoritativeFrontPairSourceSupportMismatch";
      return result;
    }

    geometry::PureQuadEquivalenceProvenance equivalence;
    equivalence.firstFrontEdge = edgeIndex;
    equivalence.secondFrontEdge = secondIndex;
    if (first.boundaryKind ==
        geometry::SurfaceFrontBoundaryKind::OrdinaryInterior) {
      if (!lattice_equal(first.fromLattice, second.toLattice) ||
          !lattice_equal(first.toLattice, second.fromLattice) ||
          first.sourceTopologyRegion != second.sourceTopologyRegion) {
        result.failure = "InvalidOrdinaryFrontTransport";
        return result;
      }
      equivalence.kind = geometry::PureQuadEquivalenceKind::OrdinaryFront;
      equivalence.isolationSeams =
          isolationSeamsByFrontEdge[static_cast<std::size_t>(edgeIndex)];
      const auto &secondSeams =
          isolationSeamsByFrontEdge[static_cast<std::size_t>(secondIndex)];
      equivalence.isolationSeams.insert(
          equivalence.isolationSeams.end(), secondSeams.begin(),
          secondSeams.end());
      std::sort(equivalence.isolationSeams.begin(),
                equivalence.isolationSeams.end());
      equivalence.isolationSeams.erase(
          std::unique(equivalence.isolationSeams.begin(),
                      equivalence.isolationSeams.end()),
          equivalence.isolationSeams.end());
      const bool crossesSheets =
          occurrences[static_cast<std::size_t>(firstFrom)].isolationSheet !=
              occurrences[static_cast<std::size_t>(secondTo)].isolationSheet ||
          occurrences[static_cast<std::size_t>(firstTo)].isolationSheet !=
              occurrences[static_cast<std::size_t>(secondFrom)].isolationSheet;
      if (crossesSheets && equivalence.isolationSeams.empty()) {
        result.failure = "MissingIsolationSeamEquivalenceAuthority";
        return result;
      }
      for (const authority::SourceEdgeTopologyKey &seam :
           equivalence.isolationSeams) {
        if (isolationCertificateBySeam.count(
                {first.sourceTopologyRegion, seam}) != 1U) {
          result.failure = "InvalidIsolationSeamEquivalenceAuthority";
          return result;
        }
      }
    } else if (first.boundaryKind ==
               geometry::SurfaceFrontBoundaryKind::HardRail) {
      if (first.sourceTopologyRegion == second.sourceTopologyRegion ||
          (first.railId.has_value() && second.railId.has_value() &&
           first.railId != second.railId) ||
          first.route != second.route.reversed()) {
        result.failure = "InvalidHardRailTransport";
        return result;
      }
      equivalence.kind = geometry::PureQuadEquivalenceKind::HardRail;
      equivalence.railId =
          first.railId.has_value() ? first.railId : second.railId;
      equivalence.route = first.route;
    } else if (first.boundaryKind ==
               geometry::SurfaceFrontBoundaryKind::PeriodicCut) {
      if (first.periodicRelation != second.periodicRelation ||
          !first.periodicRelation.has_value()) {
        result.failure = "InvalidPeriodicRelationOwner";
        return result;
      }
      const auto relationOwner = periodicRelationById.find(*first.periodicRelation);
      if (relationOwner == periodicRelationById.end()) {
        result.failure = "InvalidPeriodicRelationOwner";
        return result;
      }
      const auto &relation = *relationOwner->second;
      if (relation.sourceTopologyRegion() != first.sourceTopologyRegion ||
          (relation.action().shift.x == 0 && relation.action().shift.y == 0) ||
          !exact_interior_route_valid(relation.route()) ||
          !exact_interior_route_valid(relation.cutRoute()) ||
          first.route != relation.cutRoute() ||
          second.route != relation.cutRoute().reversed()) {
        result.failure = "InvalidPeriodicRelation";
        return result;
      }
      const authority::GridAutomorphism &action = relation.action();
      const authority::GridAutomorphism inverseAction = action.inverse();
      const bool forward =
          action_matches(first.fromLattice, second.toLattice, action) &&
          action_matches(first.toLattice, second.fromLattice, action);
      const bool inverse =
          action_matches(first.fromLattice, second.toLattice, inverseAction) &&
          action_matches(first.toLattice, second.fromLattice, inverseAction);
      if (!forward && !inverse) {
        result.failure = "InvalidPeriodicFrontTransport";
        return result;
      }
      consumedPeriodicRelations.insert(*first.periodicRelation);
      equivalence.kind =
          geometry::PureQuadEquivalenceKind::PeriodicHolonomy;
      equivalence.periodicRelation = first.periodicRelation;
      equivalence.action = relation.action();
      equivalence.route = relation.route();
    } else {
      result.failure = "InvalidPairedBoundaryKind";
      return result;
    }
    unite(firstFrom, secondTo);
    unite(firstTo, secondFrom);
    for (const int occurrence : {firstFrom, firstTo, secondFrom, secondTo}) {
      occurrenceEquivalences[static_cast<std::size_t>(occurrence)].push_back(
          equivalence);
    }
  }
  if (consumedPeriodicRelations.size() != periodicRelationById.size()) {
    result.failure = "UnconsumedAuthoritativePeriodicRelation";
    return result;
  }

  std::map<int, std::vector<int>> membersByRoot;
  for (int occurrence = 0; occurrence < occurrenceCount; ++occurrence) {
    membersByRoot[find_root(occurrence)].push_back(occurrence);
  }
  using QuotientDomainState = std::tuple<
      authority::TopologyRegionId, authority::IsolationSheetId, int, int, int,
      int, authority::FieldChartId>;
  struct QuotientClass {
    int root = -1; // union-find representation index only
    std::vector<int> memberIndices; // occurrence-vector representation indices
    std::vector<authority::OccurrenceId> members;
    std::optional<authority::QuotientClassId> id;
    std::optional<authority::SourceSupport> support;
    std::vector<QuotientDomainState> domainStates;
  };
  using QuotientClassKey =
      std::pair<authority::SourceSupport, std::vector<QuotientDomainState>>;
  std::vector<QuotientClass> quotientClasses;
  std::set<QuotientClassKey> uniqueClassKeys;
  for (auto &[root, members] : membersByRoot) {
    const authority::SourceSupport &support =
        occurrences[static_cast<std::size_t>(members.front())].support;
    std::vector<QuotientDomainState> domainStates;
    std::map<authority::TopologyRegionId, std::set<authority::IsolationSheetId>>
        sheetsByTopologyRegion;
    for (const int member : members) {
      const auto &occurrence = occurrences[static_cast<std::size_t>(member)];
      if (occurrence.support != support) {
        result.failure = "QuotientSourceSupportConflict";
        return result;
      }
      domainStates.emplace_back(
          occurrence.topologyRegion, occurrence.isolationSheet,
          occurrence.lattice.latticeCoordinate.x,
          occurrence.lattice.latticeCoordinate.y,
          occurrence.lattice.branchRotation, occurrence.lattice.scaleLevel,
          occurrence.chart.chart);
      sheetsByTopologyRegion[occurrence.topologyRegion].insert(
          occurrence.isolationSheet);
    }
    for (const auto &[regionId, sheetSet] : sheetsByTopologyRegion) {
      const std::vector<authority::IsolationSheetId> sheets(
          sheetSet.begin(), sheetSet.end());
      if (!isolation_sheets_connected_typed(regionId, sheets)) {
        result.failure = "DisconnectedQuotientIsolationAuthority";
        return result;
      }
    }
    std::sort(domainStates.begin(), domainStates.end());
    domainStates.erase(std::unique(domainStates.begin(), domainStates.end()),
                       domainStates.end());
    QuotientClass quotient;
    quotient.root = root;
    quotient.memberIndices = std::move(members);
    quotient.members.reserve(quotient.memberIndices.size());
    for (const int memberIndex : quotient.memberIndices) {
      quotient.members.push_back(
          occurrences[static_cast<std::size_t>(memberIndex)].id);
    }
    std::sort(quotient.members.begin(), quotient.members.end());
    quotient.support = support;
    quotient.domainStates = std::move(domainStates);
    const QuotientClassKey key{support, quotient.domainStates};
    if (!uniqueClassKeys.insert(key).second) {
      result.failure = "UnpairedDuplicateAuthoritativeCorner";
      return result;
    }
    quotientClasses.push_back(std::move(quotient));
  }
  std::map<QuotientClassKey, authority::QuotientClassId>
      quotientClassIdByKey;
  std::size_t canonicalQuotientOrdinal = 0U;
  for (const QuotientClassKey &key : uniqueClassKeys) {
    const auto quotientClassId = authority::QuotientClassId::from_index(
        static_cast<std::int64_t>(canonicalQuotientOrdinal),
        uniqueClassKeys.size());
    if (!quotientClassId ||
        !quotientClassIdByKey.emplace(key, quotientClassId.value()).second) {
      result.failure = "InvalidAuthoritativeQuotientClassId";
      return result;
    }
    ++canonicalQuotientOrdinal;
  }
  std::sort(quotientClasses.begin(), quotientClasses.end(),
            [](const QuotientClass &first, const QuotientClass &second) {
              return std::tie(first.support.value(), first.domainStates) <
                     std::tie(second.support.value(), second.domainStates);
            });
  for (QuotientClass &quotient : quotientClasses) {
    const QuotientClassKey key{quotient.support.value(), quotient.domainStates};
    const auto quotientClassId = quotientClassIdByKey.find(key);
    if (quotientClassId == quotientClassIdByKey.end()) {
      result.failure = "InvalidAuthoritativeQuotientClassId";
      return result;
    }
    quotient.id = quotientClassId->second;
  }

  result.mesh.vertexPositions.resize(
      static_cast<int>(quotientClasses.size()), 3);
  std::map<int, int> outputVertexByRoot;
  for (int outputVertex = 0;
       outputVertex < static_cast<int>(quotientClasses.size());
       ++outputVertex) {
    QuotientClass &quotient =
        quotientClasses[static_cast<std::size_t>(outputVertex)];
    outputVertexByRoot[quotient.root] = outputVertex;
    const auto representative_key = [&](const int member) {
      const auto &occurrence = occurrences[static_cast<std::size_t>(member)];
      std::array<std::pair<int, std::int64_t>, 3> weightedVertices;
      for (int corner = 0; corner < 3; ++corner) {
        weightedVertices[static_cast<std::size_t>(corner)] = {
            sourceFaces(occurrence.point.face, corner),
            static_cast<std::int64_t>(std::llround(
                occurrence.point.barycentric(corner) * 1.0e12))};
      }
      std::sort(weightedVertices.begin(), weightedVertices.end());
      // Source triangle topology and exact barycentric chart select the
      // representative. The face row is only a final lookup tie-break for an
      // already identical chart; it is never a merge or provenance policy.
      return std::tuple{
          weightedVertices, occurrence.isolationSheet,
          occurrence.chart.chart, occurrence.topologyRegion,
          occurrence.point.face};
    };
    const int representative = *std::min_element(
        quotient.memberIndices.begin(), quotient.memberIndices.end(),
        [&](const int first, const int second) {
          return representative_key(first) < representative_key(second);
        });
    const auto &representativeOccurrence =
        occurrences[static_cast<std::size_t>(representative)];
    std::set<geometry::SourceProjectionChart> charts;
    std::set<authority::TopologyRegionId> topologyRegions;
    std::set<authority::IsolationSheetId> isolationSheets;
    std::vector<geometry::PureQuadEquivalenceProvenance> equivalences;
    for (const int member : quotient.memberIndices) {
      const auto &occurrence = occurrences[static_cast<std::size_t>(member)];
      const double tolerance = 1.0e-9 * std::max(
          {1.0, representativeOccurrence.point.position.norm(),
           occurrence.point.position.norm()});
      if ((representativeOccurrence.point.position - occurrence.point.position)
              .norm() > tolerance) {
        result.failure = "QuotientGeometryConsistencyFailure";
        return result;
      }
      charts.insert(occurrence.chart);
      topologyRegions.insert(occurrence.topologyRegion);
      isolationSheets.insert(occurrence.isolationSheet);
      const auto &memberEquivalences =
          occurrenceEquivalences[static_cast<std::size_t>(member)];
      equivalences.insert(equivalences.end(), memberEquivalences.begin(),
                          memberEquivalences.end());
    }
    std::sort(equivalences.begin(), equivalences.end());
    equivalences.erase(
        std::unique(equivalences.begin(), equivalences.end()),
        equivalences.end());
    result.mesh.vertices.push_back(outputVertex);
    result.mesh.vertexPositions.row(outputVertex) =
        representativeOccurrence.point.position.transpose();
    result.mesh.vertexProvenance.push_back(representativeOccurrence.point);
    geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = outputVertex;
    lineage.kind = geometry::PureQuadVertexLineageKind::SourceTriangle;
    lineage.sourcePoint = representativeOccurrence.point;
    lineage.sourcePatch = 0;
    lineage.localVertex = outputVertex;
    lineage.sourceTopologyRegions.assign(topologyRegions.begin(),
                                         topologyRegions.end());
    lineage.sourceCharts.assign(charts.begin(), charts.end());
    lineage.sourceIsolationSheets.assign(isolationSheets.begin(),
                                         isolationSheets.end());
    lineage.sourceSupport = representativeOccurrence.support;
    if (!quotient.id.has_value()) {
      result.failure = "MissingAuthoritativeQuotientClassId";
      return result;
    }
    lineage.quotientClass = quotient.id.value();
    lineage.sourceOccurrences = quotient.members;
    lineage.equivalences = std::move(equivalences);
    result.mesh.vertexLineage.push_back(std::move(lineage));
  }

  struct PendingQuad {
    std::vector<int> vertices;
    std::vector<int> canonicalCycle;
    std::vector<int> duplicateKey;
    int cellIndex = -1;
  };
  const auto canonical_cycle = [](const std::vector<int> &cycle,
                                  const bool allowReverse) {
    std::vector<int> best;
    const auto consume = [&](const std::vector<int> &candidate,
                             std::vector<int> &target) {
      for (std::size_t offset = 0; offset < candidate.size(); ++offset) {
        std::vector<int> rotated;
        for (std::size_t index = 0; index < candidate.size(); ++index) {
          rotated.push_back(candidate[(offset + index) % candidate.size()]);
        }
        if (target.empty() || rotated < target) target = std::move(rotated);
      }
    };
    consume(cycle, best);
    if (allowReverse) {
      std::vector<int> reversed(cycle.rbegin(), cycle.rend());
      consume(reversed, best);
    }
    return best;
  };
  std::vector<PendingQuad> pendingQuads;
  std::set<std::vector<int>> duplicateFaces;
  for (int cellIndex = 0;
       cellIndex < static_cast<int>(phaseFront.cells().size()); ++cellIndex) {
    const auto &cell = phaseFront.cells()[static_cast<std::size_t>(cellIndex)];
    PendingQuad pending;
    pending.cellIndex = cellIndex;
    std::array<Eigen::RowVector3d, 4> positions;
    Eigen::RowVector3d expectedNormal = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 4; ++corner) {
      const int root = find_root(cellIndex * 4 + corner);
      pending.vertices.push_back(outputVertexByRoot[root]);
      positions[static_cast<std::size_t>(corner)] =
          result.mesh.vertexPositions.row(pending.vertices.back());
      const int face = cell.corners[static_cast<std::size_t>(corner)].face;
      const Eigen::RowVector3d a = sourceVertices.row(sourceFaces(face, 0));
      const Eigen::RowVector3d b = sourceVertices.row(sourceFaces(face, 1));
      const Eigen::RowVector3d c = sourceVertices.row(sourceFaces(face, 2));
      expectedNormal += (b - a).cross(c - a);
    }
    if (std::set<int>(pending.vertices.begin(), pending.vertices.end()).size() !=
            4U ||
        expectedNormal.squaredNorm() <= 1.0e-24) {
      result.failure = "DegenerateAuthoritativePhaseFrontQuad";
      return result;
    }
    Eigen::RowVector3d quadNormal = Eigen::RowVector3d::Zero();
    for (int corner = 0; corner < 4; ++corner) {
      quadNormal += positions[static_cast<std::size_t>(corner)].cross(
          positions[static_cast<std::size_t>((corner + 1) % 4)]);
    }
    if (!quadNormal.allFinite() || quadNormal.squaredNorm() <= 1.0e-24 ||
        quadNormal.dot(expectedNormal) <= 0.0) {
      result.failure = "InvertedAuthoritativePhaseFrontQuad";
      return result;
    }
    pending.canonicalCycle = canonical_cycle(pending.vertices, false);
    pending.duplicateKey = canonical_cycle(pending.vertices, true);
    if (!duplicateFaces.insert(pending.duplicateKey).second) {
      result.failure = "DuplicateAuthoritativePhaseFrontQuad";
      return result;
    }
    pendingQuads.push_back(std::move(pending));
  }
  std::sort(pendingQuads.begin(), pendingQuads.end(),
            [](const PendingQuad &first, const PendingQuad &second) {
              return first.canonicalCycle < second.canonicalCycle;
            });
  std::vector<int> outputQuadByCell(phaseFront.cells().size(), -1);
  for (int outputQuad = 0;
       outputQuad < static_cast<int>(pendingQuads.size()); ++outputQuad) {
    const PendingQuad &pending =
        pendingQuads[static_cast<std::size_t>(outputQuad)];
    result.mesh.quads.push_back(pending.vertices);
    outputQuadByCell[static_cast<std::size_t>(pending.cellIndex)] = outputQuad;
    geometry::PureQuadFaceLineage lineage;
    lineage.outputQuad = outputQuad;
    lineage.sourcePatch = 0;
    lineage.operation = geometry::PureQuadCompletionBackend::ClosedForm;
    // operationLocalQuad is a local completed-quad row, not CellId authority.
    lineage.operationLocalQuad = pending.cellIndex;
    lineage.completionVariant = 0;
    lineage.boundaryOnly = false;
    result.mesh.quadLineage.push_back(std::move(lineage));
  }

  struct MeshSideRef {
    int quad = -1;
    int side = -1;
    int frontEdge = -1;
    int from = -1;
    int to = -1;
  };
  std::map<std::pair<int, int>, std::vector<MeshSideRef>> meshEdges;
  for (const PendingQuad &pending : pendingQuads) {
    const int outputQuad =
        outputQuadByCell[static_cast<std::size_t>(pending.cellIndex)];
    for (int side = 0; side < 4; ++side) {
      const int from = pending.vertices[static_cast<std::size_t>(side)];
      const int to = pending.vertices[static_cast<std::size_t>((side + 1) % 4)];
      if (from == to) {
        result.failure = "CollapsedAuthoritativeMeshEdge";
        return result;
      }
      meshEdges[std::minmax(from, to)].push_back(
          {outputQuad, side,
           edgeByCellSide[static_cast<std::size_t>(pending.cellIndex * 4 + side)],
           from, to});
    }
  }
  std::vector<std::set<int>> quadAdjacency(pendingQuads.size());
  std::vector<std::pair<int, int>> directedBoundary;
  for (const auto &[edgeKey, incidence] : meshEdges) {
    (void)edgeKey;
    if (incidence.empty() || incidence.size() > 2U) {
      result.failure = "NonManifoldAuthoritativeMeshEdge";
      return result;
    }
    if (incidence.size() == 1U) {
      const auto &front = phaseFront.edges()[static_cast<std::size_t>(
          incidence.front().frontEdge)];
      if (front.boundaryKind !=
              geometry::SurfaceFrontBoundaryKind::GenuineSourceBoundary ||
          !front.exterior || front.oppositeEdge >= 0) {
        result.failure = "UnjustifiedAuthoritativeMeshBoundary";
        return result;
      }
      directedBoundary.emplace_back(incidence.front().from,
                                    incidence.front().to);
    } else {
      const auto &firstFront = phaseFront.edges()[static_cast<std::size_t>(
          incidence[0].frontEdge)];
      const auto &secondFront = phaseFront.edges()[static_cast<std::size_t>(
          incidence[1].frontEdge)];
      if (firstFront.oppositeEdge != incidence[1].frontEdge ||
          secondFront.oppositeEdge != incidence[0].frontEdge ||
          incidence[0].from != incidence[1].to ||
          incidence[0].to != incidence[1].from) {
        result.failure = "AuthoritativeMeshEdgeRelationMismatch";
        return result;
      }
      quadAdjacency[static_cast<std::size_t>(incidence[0].quad)].insert(
          incidence[1].quad);
      quadAdjacency[static_cast<std::size_t>(incidence[1].quad)].insert(
          incidence[0].quad);
    }
  }

  std::set<int> unvisitedQuads;
  for (int quad = 0; quad < static_cast<int>(pendingQuads.size()); ++quad) {
    unvisitedQuads.insert(quad);
  }
  while (!unvisitedQuads.empty()) {
    ++result.connectedComponents;
    std::vector<int> stack{*unvisitedQuads.begin()};
    while (!stack.empty()) {
      const int quad = stack.back();
      stack.pop_back();
      if (unvisitedQuads.erase(quad) == 0U) continue;
      for (const int adjacent :
           quadAdjacency[static_cast<std::size_t>(quad)]) {
        if (unvisitedQuads.count(adjacent) != 0U) stack.push_back(adjacent);
      }
    }
  }

  std::map<int, int> boundaryNext;
  std::map<int, int> boundaryPrevious;
  std::set<std::pair<int, int>> unvisitedBoundary(directedBoundary.begin(),
                                                  directedBoundary.end());
  for (const auto &[from, to] : directedBoundary) {
    if (!boundaryNext.emplace(from, to).second ||
        !boundaryPrevious.emplace(to, from).second) {
      result.failure = "NonManifoldAuthoritativeBoundaryVertex";
      return result;
    }
  }
  if (boundaryNext.size() != boundaryPrevious.size()) {
    result.failure = "OpenAuthoritativeBoundary";
    return result;
  }
  while (!unvisitedBoundary.empty()) {
    const int start = unvisitedBoundary.begin()->first;
    int current = start;
    std::vector<int> loop;
    do {
      const auto next = boundaryNext.find(current);
      if (next == boundaryNext.end() ||
          unvisitedBoundary.erase({current, next->second}) == 0U) {
        result.failure = "InvalidAuthoritativeBoundaryLoop";
        return result;
      }
      loop.push_back(current);
      current = next->second;
      if (loop.size() > directedBoundary.size()) {
        result.failure = "InvalidAuthoritativeBoundaryLoop";
        return result;
      }
    } while (current != start);
    if (loop.size() < 3U) {
      result.failure = "DegenerateAuthoritativeBoundaryLoop";
      return result;
    }
    const auto minimum = std::min_element(loop.begin(), loop.end());
    std::rotate(loop.begin(), minimum, loop.end());
    result.mesh.boundaryLoops.push_back(std::move(loop));
  }
  std::sort(result.mesh.boundaryLoops.begin(),
            result.mesh.boundaryLoops.end());
  for (const auto &loop : result.mesh.boundaryLoops) {
    result.mesh.boundaryVertices.insert(result.mesh.boundaryVertices.end(),
                                        loop.begin(), loop.end());
  }
  result.boundaryLoopCount =
      static_cast<int>(result.mesh.boundaryLoops.size());
  result.eulerCharacteristic =
      static_cast<int>(quotientClasses.size()) -
      static_cast<int>(meshEdges.size()) +
      static_cast<int>(pendingQuads.size());

  std::vector<std::set<int>> incidentQuadsByVertex(quotientClasses.size());
  std::vector<std::map<int, std::set<int>>> fanAdjacency(
      quotientClasses.size());
  std::vector<int> boundaryEdgesByVertex(quotientClasses.size(), 0);
  for (const auto &[edgeKey, incidence] : meshEdges) {
    for (const MeshSideRef &side : incidence) {
      incidentQuadsByVertex[static_cast<std::size_t>(edgeKey.first)].insert(
          side.quad);
      incidentQuadsByVertex[static_cast<std::size_t>(edgeKey.second)].insert(
          side.quad);
    }
    if (incidence.size() == 1U) {
      ++boundaryEdgesByVertex[static_cast<std::size_t>(edgeKey.first)];
      ++boundaryEdgesByVertex[static_cast<std::size_t>(edgeKey.second)];
    } else {
      for (const int vertex : {edgeKey.first, edgeKey.second}) {
        fanAdjacency[static_cast<std::size_t>(vertex)][incidence[0].quad]
            .insert(incidence[1].quad);
        fanAdjacency[static_cast<std::size_t>(vertex)][incidence[1].quad]
            .insert(incidence[0].quad);
      }
    }
  }
  for (int vertex = 0; vertex < static_cast<int>(quotientClasses.size());
       ++vertex) {
    const auto &incident =
        incidentQuadsByVertex[static_cast<std::size_t>(vertex)];
    if (incident.empty()) {
      result.failure = "UnreferencedAuthoritativeVertex";
      return result;
    }
    std::set<int> unvisited = incident;
    std::vector<int> stack{*unvisited.begin()};
    while (!stack.empty()) {
      const int quad = stack.back();
      stack.pop_back();
      if (unvisited.erase(quad) == 0U) continue;
      const auto neighbors =
          fanAdjacency[static_cast<std::size_t>(vertex)].find(quad);
      if (neighbors ==
          fanAdjacency[static_cast<std::size_t>(vertex)].end()) continue;
      for (const int adjacent : neighbors->second) {
        if (unvisited.count(adjacent) != 0U) stack.push_back(adjacent);
      }
    }
    if (!unvisited.empty()) {
      result.failure = "DisconnectedAuthoritativeVertexFan";
      return result;
    }
    int degreeOne = 0;
    bool invalidDegree = false;
    for (const int quad : incident) {
      const auto found =
          fanAdjacency[static_cast<std::size_t>(vertex)].find(quad);
      const std::size_t degree =
          found == fanAdjacency[static_cast<std::size_t>(vertex)].end()
              ? 0U
              : found->second.size();
      degreeOne += degree == 1U ? 1 : 0;
      if (degree > 2U) invalidDegree = true;
    }
    const int boundaryDegree =
        boundaryEdgesByVertex[static_cast<std::size_t>(vertex)];
    const bool validInterior =
        boundaryDegree == 0 && !invalidDegree &&
        std::all_of(incident.begin(), incident.end(), [&](const int quad) {
          return fanAdjacency[static_cast<std::size_t>(vertex)][quad].size() ==
                 2U;
        });
    const bool validBoundary =
        boundaryDegree == 2 && !invalidDegree &&
        ((incident.size() == 1U && degreeOne == 0) || degreeOne == 2);
    if (!validInterior && !validBoundary) {
      result.failure = "NonManifoldAuthoritativeVertexFan";
      return result;
    }
  }

  result.consumedTopologyRegions = consumedTopologyRegions.size();
  result.consumedInternalIsolationSeams =
      isolationCertificateBySeam.size();
  result.consumedPeriodicHolonomies = consumedPeriodicRelations.size();
  result.invalidCell = -1;
  result.invalidEdge = -1;
  result.success = true;
  return result;
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
    if (surface_cell_source_edge_key(
            transition.sourceVertex0, transition.sourceVertex1,
            static_cast<std::size_t>(meshWhole.V.rows())) !=
        surface_cell_source_edge_key(
            meshWhole.EV(edge, 0), meshWhole.EV(edge, 1),
            static_cast<std::size_t>(meshWhole.V.rows()))) {
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
  SurfaceCellRailBuildProduct product;
  SurfaceCellRailBuildFailure failure;
  std::set<int> coveredEdges;
  const auto fail_edge = [&](const int edgeIndex) {
    failure.kind = SurfaceCellRailBuildFailureKind::InvalidFeatureEdge;
    failure.failedEdgeIndex = edgeIndex;
    return false;
  };
  std::set<authority::HardRailId> railOwners;
  const auto allocate_rail_id = [&]() -> std::optional<authority::HardRailId> {
    const std::size_t ownerExtent = railOwners.size() + 1U;
    for (std::size_t candidateIndex = 0; candidateIndex < ownerExtent;
         ++candidateIndex) {
      const auto candidate = authority::HardRailId::from_index(
          static_cast<std::int64_t>(candidateIndex), ownerExtent);
      if (!candidate) return std::nullopt;
      if (railOwners.insert(candidate.value()).second) {
        return candidate.value();
      }
    }
    return std::nullopt;
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
    const auto railId = allocate_rail_id();
    if (!railId) return fail_edge(
        ordered[static_cast<std::size_t>(run.front())].edgeIndex);
    geometry::SurfaceCellRail rail(railId.value());
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
    product.rails.push_back(std::move(rail));
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
      return SurfaceCellRailBuildResult::rejected(std::move(failure));
    }

    std::vector<OrderedCurveEdge> ordered;
    ordered.reserve(static_cast<std::size_t>(edgeCount));
    for (int index = 0; index < edgeCount; ++index) {
      const int edgeIndex = curve.edges[static_cast<std::size_t>(index)];
      if (edgeIndex < 0 ||
          edgeIndex >= static_cast<int>(featureMap.edges.size())) {
        fail_edge(edgeIndex);
        return SurfaceCellRailBuildResult::rejected(std::move(failure));
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
        return SurfaceCellRailBuildResult::rejected(std::move(failure));
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
        return SurfaceCellRailBuildResult::rejected(std::move(failure));
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
        return SurfaceCellRailBuildResult::rejected(std::move(failure));
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
    const auto railId = allocate_rail_id();
    if (!railId) {
      fail_edge(edgeIndex);
      return SurfaceCellRailBuildResult::rejected(std::move(failure));
    }
    geometry::SurfaceCellRail rail(railId.value());
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
      return SurfaceCellRailBuildResult::rejected(std::move(failure));
    }
    product.rails.push_back(std::move(rail));
  }

  std::map<authority::HardRailId, const geometry::SurfaceCellRail *> railById;
  for (const geometry::SurfaceCellRail &rail : product.rails) {
    railById.emplace(rail.id, &rail);
  }
  const auto railValidation =
      geometry::surface_cell_tracing_detail::rail_interval_refs(
          product.rails, meshWhole.V, meshWhole.F,
          geometry::surface_cell_tracing_detail::edge_faces(meshWhole.F));
  if (railValidation.status !=
      geometry::surface_cell_tracing_detail::RailBuildStatus::Valid) {
    failure.kind = SurfaceCellRailBuildFailureKind::InvalidRailIntervals;
    failure.validationStatus = railValidation.status;
    failure.failedRailId =
        railValidation.railId.has_value()
            ? static_cast<int>(railValidation.railId->index())
            : -1;
    failure.failedIntervalIndex = railValidation.intervalIndex;
    if (railValidation.railId.has_value() &&
        railValidation.intervalIndex >= 0) {
      const auto owner = railById.find(*railValidation.railId);
      if (owner != railById.end() &&
          railValidation.intervalIndex <
              static_cast<int>(owner->second->sourceEdges.size())) {
        failure.failedEdgeIndex =
            owner->second->sourceEdges[static_cast<std::size_t>(
                railValidation.intervalIndex)];
      }
    }
    return SurfaceCellRailBuildResult::rejected(std::move(failure));
  }
  return SurfaceCellRailBuildResult::produced(std::move(product));
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::set<authority::SourceEdgeTopologyKey> relief_barrier_edges_from_topology(
    const geometry::ReliefTopologyResult &topology,
    const std::size_t vertexExtent) {
  std::set<authority::SourceEdgeTopologyKey> barriers;
  for (const geometry::ReliefBranch &branch : topology.branches) {
    for (int index = 0; index + 1 < static_cast<int>(branch.vertices.size());
         ++index) {
      barriers.insert(surface_cell_source_edge_key(
          branch.vertices[static_cast<std::size_t>(index)],
          branch.vertices[static_cast<std::size_t>(index + 1)],
          vertexExtent));
    }
  }
  return barriers;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::uint64_t hash_relief_operational_inputs(
    const geometry::ReliefRootSelectionResult &roots,
    const std::set<authority::SourceEdgeTopologyKey> &barriers) {
  std::uint64_t seed = structural_hash_seed("relief-consumption");
  hash_vector(seed, roots.roots);
  hash_vector(seed, roots.labels);
  hash_matrix(seed, roots.targets);
  hash_combine_u64(seed, barriers.size());
  for (const authority::SourceEdgeTopologyKey &barrier : barriers) {
    hash_combine_u64(seed, barrier.first().index());
    hash_combine_u64(seed, barrier.second().index());
  }
  return seed;
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::set<authority::SourceEdgeTopologyKey> hard_feature_edge_keys_from_rails(
    const std::vector<geometry::SurfaceCellRail> &rails,
    const std::size_t vertexExtent) {
  std::set<authority::SourceEdgeTopologyKey> keys;
  for (const geometry::SurfaceCellRail &rail : rails) {
    if (rail.kind != geometry::SurfaceCellRailKind::HardFeature) {
      continue;
    }
    for (int index = 0; index + 1 < static_cast<int>(rail.sourceVertices.size());
         ++index) {
      keys.insert(surface_cell_source_edge_key(
          rail.sourceVertices[static_cast<std::size_t>(index)],
          rail.sourceVertices[static_cast<std::size_t>(index + 1)],
          vertexExtent));
    }
    if (rail.closed && rail.sourceVertices.size() > 1U &&
        rail.sourceVertices.back() != rail.sourceVertices.front()) {
      keys.insert(surface_cell_source_edge_key(
          rail.sourceVertices.back(), rail.sourceVertices.front(),
          vertexExtent));
    }
  }
  return keys;
}

bool project_surface_cell_vertex_chart_authority(
    const std::vector<geometry::PureQuadVertexLineage> &lineages,
    const int outputVertexCount, const std::size_t railCount,
    std::vector<validation::SourceVertexChartAuthority> &projected) {
  if (outputVertexCount < 0 ||
      lineages.size() != static_cast<std::size_t>(outputVertexCount)) {
    projected.clear();
    return false;
  }
  projected.assign(static_cast<std::size_t>(outputVertexCount), {});
  bool valid = true;
  for (const geometry::PureQuadVertexLineage &lineage : lineages) {
    if (!valid || lineage.outputVertex < 0 ||
        lineage.outputVertex >= outputVertexCount) {
      valid = false;
      break;
    }
    validation::SourceVertexChartAuthority &authority =
        projected[static_cast<std::size_t>(lineage.outputVertex)];
    if (authority.retained) {
      valid = false;
      break;
    }
    authority.retained = true;
    authority.sourceCharts = lineage.sourceCharts;
    std::sort(authority.sourceCharts.begin(), authority.sourceCharts.end());
    authority.sourceCharts.erase(
        std::unique(authority.sourceCharts.begin(), authority.sourceCharts.end()),
        authority.sourceCharts.end());
    if (authority.sourceCharts.empty()) {
      valid = false;
      break;
    }
    for (const geometry::PureQuadEquivalenceProvenance &equivalence :
         lineage.equivalences) {
      if (equivalence.kind != geometry::PureQuadEquivalenceKind::HardRail) {
        continue;
      }
      if (!equivalence.railId.has_value() ||
          equivalence.railId->index() >= railCount) {
        valid = false;
        break;
      }
      validation::SourceHardRailChartEquivalence entry;
      entry.firstFrontEdge = equivalence.firstFrontEdge;
      entry.secondFrontEdge = equivalence.secondFrontEdge;
      entry.rail = equivalence.railId.value();
      entry.route = equivalence.route;
      authority.hardRailEquivalences.push_back(std::move(entry));
    }
    if (!valid) break;
    std::sort(authority.hardRailEquivalences.begin(),
              authority.hardRailEquivalences.end());
    authority.hardRailEquivalences.erase(
        std::unique(authority.hardRailEquivalences.begin(),
                    authority.hardRailEquivalences.end()),
        authority.hardRailEquivalences.end());
  }
  if (!valid ||
      std::any_of(projected.begin(), projected.end(), [](const auto &authority) {
        return !authority.retained || authority.sourceCharts.empty();
      })) {
    for (auto &authority : projected) authority.retained = false;
    return false;
  }
  return true;
}

bool project_materialized_hard_feature_rails_from_lineage(
    const std::vector<geometry::SurfaceCellRail> &rails,
    const Eigen::MatrixXi &outputQuads,
    const std::vector<geometry::PureQuadVertexLineage> &lineages,
    geometry::SurfaceOptimizationConstraints &constraints) {
  std::map<authority::HardRailId, const geometry::SurfaceCellRail *> hardRails;
  for (const geometry::SurfaceCellRail &rail : rails) {
    if (rail.kind != geometry::SurfaceCellRailKind::HardFeature) continue;
    if (!hardRails.emplace(rail.id, &rail).second) return false;
  }
  constraints.requiredFeatureRailCount = hardRails.size();
  constraints.authoritativeFeatureRails.clear();
  constraints.missingFeatureRailIds.clear();
  if (hardRails.empty()) return true;

  if (outputQuads.rows() <= 0 || outputQuads.cols() < 2) return false;
  std::set<std::pair<int, int>> outputEdges;
  for (int face = 0; face < outputQuads.rows(); ++face) {
    for (int corner = 0; corner < outputQuads.cols(); ++corner) {
      const int first = outputQuads(face, corner);
      const int second = outputQuads(face, (corner + 1) % outputQuads.cols());
      if (first < 0 || second < 0 || first == second) return false;
      outputEdges.insert(std::minmax(first, second));
    }
  }

  using SegmentKey = std::tuple<authority::HardRailId, int, int>;
  std::map<SegmentKey, std::set<int>> verticesBySegment;
  for (const geometry::PureQuadVertexLineage &lineage : lineages) {
    if (lineage.outputVertex < 0 ||
        static_cast<std::size_t>(lineage.outputVertex) >= lineages.size()) {
      return false;
    }
    for (const geometry::PureQuadEquivalenceProvenance &equivalence :
         lineage.equivalences) {
      if (equivalence.kind != geometry::PureQuadEquivalenceKind::HardRail) {
        continue;
      }
      if (!equivalence.railId.has_value() || equivalence.firstFrontEdge < 0 ||
          equivalence.secondFrontEdge < 0 ||
          equivalence.firstFrontEdge == equivalence.secondFrontEdge ||
          hardRails.count(equivalence.railId.value()) == 0U) {
        return false;
      }
      const auto frontEdges = std::minmax(equivalence.firstFrontEdge,
                                          equivalence.secondFrontEdge);
      verticesBySegment[{equivalence.railId.value(), frontEdges.first,
                         frontEdges.second}]
          .insert(lineage.outputVertex);
    }
  }

  std::map<authority::HardRailId, std::set<std::pair<int, int>>>
      segmentsByRail;
  std::set<authority::HardRailId> invalidRails;
  for (const auto &[key, vertices] : verticesBySegment) {
    const authority::HardRailId rail = std::get<0>(key);
    if (vertices.size() != 2U) {
      invalidRails.insert(rail);
      continue;
    }
    const auto first = vertices.begin();
    auto second = first;
    ++second;
    const int a = *first;
    const int b = *second;
    const auto edge = std::minmax(a, b);
    if (outputEdges.count(edge) == 0U) {
      invalidRails.insert(rail);
      continue;
    }
    segmentsByRail[rail].insert(edge);
  }

  const auto append_sequence = [&](const geometry::SurfaceCellRail &rail,
                                   const std::set<std::pair<int, int>> &segments,
                                   std::vector<int> &sequence) {
    std::map<int, std::set<int>> adjacency;
    for (const auto &[first, second] : segments) {
      adjacency[first].insert(second);
      adjacency[second].insert(first);
    }
    if (adjacency.empty() || std::any_of(
                                 adjacency.begin(), adjacency.end(),
                                 [](const auto &entry) {
                                   return entry.second.empty() ||
                                          entry.second.size() > 2U;
                                 })) {
      return false;
    }

    int start = -1;
    if (rail.closed) {
      if (adjacency.size() < 3U ||
          std::any_of(adjacency.begin(), adjacency.end(),
                      [](const auto &entry) {
                        return entry.second.size() != 2U;
                      })) {
        return false;
      }
      start = adjacency.begin()->first;
    } else {
      std::vector<int> endpoints;
      for (const auto &[vertex, neighbors] : adjacency) {
        if (neighbors.size() == 1U) endpoints.push_back(vertex);
      }
      if (endpoints.size() != 2U) return false;
      start = std::min(endpoints[0], endpoints[1]);
    }

    std::set<std::pair<int, int>> traversed;
    int previous = -1;
    int current = start;
    while (true) {
      sequence.push_back(current);
      int next = -1;
      for (const int neighbor : adjacency.at(current)) {
        const auto edge = std::minmax(current, neighbor);
        if (traversed.count(edge) == 0U && neighbor != previous) {
          next = neighbor;
          break;
        }
      }
      if (next < 0) {
        for (const int neighbor : adjacency.at(current)) {
          const auto edge = std::minmax(current, neighbor);
          if (traversed.count(edge) == 0U) {
            next = neighbor;
            break;
          }
        }
      }
      if (next < 0) break;
      traversed.insert(std::minmax(current, next));
      previous = current;
      current = next;
      if (rail.closed && current == start) {
        sequence.push_back(start);
        break;
      }
      if (sequence.size() > adjacency.size()) return false;
    }
    return traversed.size() == segments.size() &&
           ((!rail.closed && sequence.size() == adjacency.size()) ||
            (rail.closed && sequence.size() == adjacency.size() + 1U));
  };

  std::set<authority::HardRailId> missing;
  for (const auto &[railId, rail] : hardRails) {
    const auto found = segmentsByRail.find(railId);
    std::vector<int> sequence;
    if (invalidRails.count(railId) != 0U || found == segmentsByRail.end() ||
        !append_sequence(*rail, found->second, sequence)) {
      missing.insert(railId);
      continue;
    }
    constraints.authoritativeFeatureRails.push_back(std::move(sequence));
  }
  constraints.missingFeatureRailIds.clear();
  for (const authority::HardRailId railId : missing) {
    constraints.missingFeatureRailIds.push_back(railId);
  }
  return true;
}

bool has_materialized_phase_front_lineage(
    const std::vector<geometry::PureQuadVertexLineage> &lineages) {
  return !lineages.empty() &&
         std::all_of(lineages.begin(), lineages.end(), [](const auto &lineage) {
           return lineage.quotientClass.has_value() &&
                  !lineage.sourceOccurrences.empty();
         });
}

bool same_surface_cell_rail_authority(
    const std::vector<geometry::SurfaceCellRail> &first,
    const std::vector<geometry::SurfaceCellRail> &second) {
  if (first.size() != second.size()) return false;
  for (std::size_t railIndex = 0; railIndex < first.size(); ++railIndex) {
    const geometry::SurfaceCellRail &a = first[railIndex];
    const geometry::SurfaceCellRail &b = second[railIndex];
    if (a.id != b.id || a.kind != b.kind || a.curveId != b.curveId ||
        a.component != b.component || a.closed != b.closed ||
        a.sourceVertices != b.sourceVertices || a.sourceEdges != b.sourceEdges ||
        a.samples.size() != b.samples.size()) {
      return false;
    }
    for (std::size_t sampleIndex = 0; sampleIndex < a.samples.size();
         ++sampleIndex) {
      const geometry::SurfaceCellRailSample &x = a.samples[sampleIndex];
      const geometry::SurfaceCellRailSample &y = b.samples[sampleIndex];
      if (x.sourceFace != y.sourceFace || x.sourceEdge != y.sourceEdge ||
          x.parameter != y.parameter || x.railParameter != y.railParameter ||
          !(x.barycentric.array() == y.barycentric.array()).all() ||
          !(x.position.array() == y.position.array()).all()) {
        return false;
      }
    }
  }
  return true;
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
    hash_semantic_id(seed, rail.id);
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

namespace {

void record_face_degree_histogram_impl(
    directional::RemeshDiagnostics &diagnostics,
    const Eigen::VectorXi &degrees) {
  diagnostics.faceDegreeHistogram.clear();
  for (Eigen::Index face = 0; face < degrees.size(); ++face) {
    const int degree = degrees(face);
    if (degree < 0) {
      continue;
    }
    const std::size_t index = static_cast<std::size_t>(degree);
    if (diagnostics.faceDegreeHistogram.size() <= index) {
      diagnostics.faceDegreeHistogram.resize(index + 1U, 0U);
    }
    ++diagnostics.faceDegreeHistogram[index];
  }
}

void record_face_degree_histogram(RemeshResultBuilder &result) {
  record_face_degree_histogram_impl(result.diagnostics, result.degrees);
}

} // namespace

void record_face_degree_histogram(RemeshResult &result) {
  if (!result.is_produced()) {
    result.diagnostics.faceDegreeHistogram.clear();
    return;
  }
  record_face_degree_histogram_impl(result.diagnostics, result.product().degrees);
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
  target.surfaceCellTracingLogicalPayloadBytes =
      source.surfaceCellTracingLogicalPayloadBytes;
  target.surfaceCellTracingRetainedCapacityBytes =
      source.surfaceCellTracingRetainedCapacityBytes;
  target.surfaceCellFlowRepLogicalPayloadBytes =
      source.surfaceCellFlowRepLogicalPayloadBytes;
  target.surfaceCellFlowRepRetainedCapacityBytes =
      source.surfaceCellFlowRepRetainedCapacityBytes;
  target.surfaceCellArrangementLogicalPayloadBytes =
      source.surfaceCellArrangementLogicalPayloadBytes;
  target.surfaceCellArrangementRetainedCapacityBytes =
      source.surfaceCellArrangementRetainedCapacityBytes;
  target.surfaceCellSimplificationLogicalPayloadBytes =
      source.surfaceCellSimplificationLogicalPayloadBytes;
  target.surfaceCellSimplificationRetainedCapacityBytes =
      source.surfaceCellSimplificationRetainedCapacityBytes;
  target.surfaceCellCompletionLogicalPayloadBytes =
      source.surfaceCellCompletionLogicalPayloadBytes;
  target.surfaceCellCompletionRetainedCapacityBytes =
      source.surfaceCellCompletionRetainedCapacityBytes;
  target.surfaceCellEstimatedPeakSimultaneousOwnedBytes =
      source.surfaceCellEstimatedPeakSimultaneousOwnedBytes;
  target.surfaceCellMemoryOwnershipTimeline =
      source.surfaceCellMemoryOwnershipTimeline;
  target.surfaceCellCompletionParityScopeFailureAvailable =
      source.surfaceCellCompletionParityScopeFailureAvailable;
  target.surfaceCellCompletionParityOriginalCell =
      source.surfaceCellCompletionParityOriginalCell;
  target.surfaceCellCompletionParityReplacementCell =
      source.surfaceCellCompletionParityReplacementCell;
  target.surfaceCellCompletionParityHalfedge =
      source.surfaceCellCompletionParityHalfedge;
  target.surfaceCellCompletionParityTwin =
      source.surfaceCellCompletionParityTwin;
  target.surfaceCellCompletionParitySelectedComponent =
      source.surfaceCellCompletionParitySelectedComponent;
  target.surfaceCellCompletionParitySelectedSheet =
      source.surfaceCellCompletionParitySelectedSheet;
  target.surfaceCellCompletionParityAvailableComponents =
      source.surfaceCellCompletionParityAvailableComponents;
  target.surfaceCellCompletionParityAvailableSheets =
      source.surfaceCellCompletionParityAvailableSheets;
  target.surfaceCellCompletionParityMutationPhase =
      source.surfaceCellCompletionParityMutationPhase;
  target.surfaceCellAuthoritativeProducerDisposition =
      source.surfaceCellAuthoritativeProducerDisposition;
  target.surfaceCellTopologyRegionCount = source.surfaceCellTopologyRegionCount;
  target.surfaceCellInternalIsolationSeamCount =
      source.surfaceCellInternalIsolationSeamCount;
  target.surfaceCellTopologyRegionHashes = source.surfaceCellTopologyRegionHashes;
  target.surfaceCellTopologyRegionEulerCharacteristics =
      source.surfaceCellTopologyRegionEulerCharacteristics;
  target.surfaceCellTopologyRegionBoundaryLoopCounts =
      source.surfaceCellTopologyRegionBoundaryLoopCounts;
  target.surfaceCellTopologyRegionIsolationSheetCounts =
      source.surfaceCellTopologyRegionIsolationSheetCounts;
  target.surfaceCellBoundedDiskBoundaryPhaseCount =
      source.surfaceCellBoundedDiskBoundaryPhaseCount;
  target.surfaceCellBoundedDiskBoundaryRunCount =
      source.surfaceCellBoundedDiskBoundaryRunCount;
  target.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount =
      source.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount;
  target.surfaceCellBoundedDiskConstructedChartCount =
      source.surfaceCellBoundedDiskConstructedChartCount;
  target.surfaceCellBoundedDiskBoundaryPhaseHashes =
      source.surfaceCellBoundedDiskBoundaryPhaseHashes;
  target.surfaceCellPeriodicHolonomies = source.surfaceCellPeriodicHolonomies;
  target.surfaceCellPeriodicHolonomyAvailable =
      source.surfaceCellPeriodicHolonomyAvailable;
  target.surfaceCellPeriodicHolonomyQuarterTurnRotation =
      source.surfaceCellPeriodicHolonomyQuarterTurnRotation;
  target.surfaceCellPeriodicHolonomyTranslationU =
      source.surfaceCellPeriodicHolonomyTranslationU;
  target.surfaceCellPeriodicHolonomyTranslationV =
      source.surfaceCellPeriodicHolonomyTranslationV;
  target.surfaceCellPeriodicHolonomyRouteEdgeCount =
      source.surfaceCellPeriodicHolonomyRouteEdgeCount;
  target.surfaceCellPeriodicCutEdgeCount =
      source.surfaceCellPeriodicCutEdgeCount;
  target.surfaceCellFirstInvalidProducerStage =
      source.surfaceCellFirstInvalidProducerStage;
  target.surfaceCellFirstInvalidProducerReason =
      source.surfaceCellFirstInvalidProducerReason;
  target.surfaceCellFirstInvalidProducerValidationIssue =
      source.surfaceCellFirstInvalidProducerValidationIssue;
  target.surfaceCellFirstInvalidProducerCell =
      source.surfaceCellFirstInvalidProducerCell;
  target.surfaceCellFirstInvalidProducerHalfedge =
      source.surfaceCellFirstInvalidProducerHalfedge;
  target.surfaceCellFirstInvalidProducerTwin =
      source.surfaceCellFirstInvalidProducerTwin;
  target.surfaceCellFirstInvalidProducerNode =
      source.surfaceCellFirstInvalidProducerNode;
  target.surfaceCellFirstInvalidProducerFace =
      source.surfaceCellFirstInvalidProducerFace;
  target.surfaceCellFirstInvalidProducerVertex =
      source.surfaceCellFirstInvalidProducerVertex;
  target.surfaceCellFirstInvalidProducerEdgeFirst =
      source.surfaceCellFirstInvalidProducerEdgeFirst;
  target.surfaceCellFirstInvalidProducerEdgeSecond =
      source.surfaceCellFirstInvalidProducerEdgeSecond;
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
  (void)quadLineage;
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
    // PureQuadFaceLineage::sourcePatch identifies the arrangement patch that
    // produced the quad.  It is not a source-triangle row and therefore must
    // never be used to index sourceFaces.  Prefer an exact common source chart
    // carried by the output-vertex provenance; otherwise use geometric
    // projection as the orientation fallback.
    int authoritativeFace = -1;
    bool commonFace = true;
    for (int col = 0; col < 4; ++col) {
      const int vertex = quads(row, col);
      if (vertex < 0 ||
          vertex >= static_cast<int>(outputProvenance.size()) ||
          !outputProvenance[static_cast<std::size_t>(vertex)].valid()) {
        commonFace = false;
        break;
      }
      const int face =
          outputProvenance[static_cast<std::size_t>(vertex)].face;
      if (authoritativeFace < 0) {
        authoritativeFace = face;
      } else if (authoritativeFace != face) {
        commonFace = false;
        break;
      }
    }
    if (commonFace && authoritativeFace >= 0 &&
        authoritativeFace < sourceFaces.rows()) {
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
    const geometry::FlowRepSparseNetwork &sparseNetwork,
    const Eigen::MatrixXi &sourceFaces,
    const geometry::SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *hardFeatureEdges) {
  std::optional<geometry::SourceChartTransitionGraph> transitionGraph;
  if (sourceAuthority != nullptr &&
      sourceAuthority->matches_source_faces(sourceFaces)) {
    transitionGraph.emplace(
        sourceFaces, *sourceAuthority,
        hardFeatureEdges != nullptr ? *hardFeatureEdges
                                    : geometry::empty_hard_feature_edges());
  }
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
    if (sourceAuthority != nullptr && transitionGraph.has_value()) {
      const auto row = authority::SourceFaceId::from_index(
          arc.sourceFace, sourceAuthority->face_count());
      const auto chart = transitionGraph->chart(arc.sourceFace);
      if (row && chart.has_value()) {
        arrangementArc.sourceTopologyRegion =
            sourceAuthority->region_for_row(row.value());
        arrangementArc.sourceChart = chart.value();
      }
    }
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
  std::map<authority::SourceEdgeTopologyKey, int> counts;
  std::map<authority::SourceEdgeTopologyKey, std::pair<int, int>> endpoints;
  for (const int face : {firstFace, secondFace}) {
    for (int corner = 0; corner < 3; ++corner) {
      const int a = mesh.F(face, corner);
      const int b = mesh.F(face, (corner + 1) % 3);
      const auto key = surface_cell_source_edge_key(
          a, b, static_cast<std::size_t>(mesh.V.rows()));
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
    const geometry::SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *excludedDiagonalEdges) {
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
            mesh.EV(edge, 0), mesh.EV(edge, 1),
            static_cast<std::size_t>(mesh.V.rows()))) != 0U) {
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
              mesh.EV(edge, 0), mesh.EV(edge, 1),
              static_cast<std::size_t>(mesh.V.rows()))) != 0U) {
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
  std::map<authority::SourceEdgeTopologyKey, int> subdivisionsBySourceEdge;
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
      subdivisionsBySourceEdge[surface_cell_source_edge_key(
          a, b, static_cast<std::size_t>(mesh.V.rows()))] =
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
        const auto key = surface_cell_source_edge_key(
            candidate.boundary[side], candidate.boundary[(side + 1) % 4],
            static_cast<std::size_t>(mesh.V.rows()));
        subdivisionsBySourceEdge[key] = shortSubdivisions;
      }
    }
    for (const int side : {longSide, longSide + 2}) {
      const auto key = surface_cell_source_edge_key(
            candidate.boundary[side], candidate.boundary[(side + 1) % 4],
            static_cast<std::size_t>(mesh.V.rows()));
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
      subdivisionsBySourceEdge[surface_cell_source_edge_key(
          a, b, static_cast<std::size_t>(mesh.V.rows()))] =
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
        const auto firstKey = surface_cell_source_edge_key(
            candidate.boundary[direction], candidate.boundary[(direction + 1) % 4], static_cast<std::size_t>(mesh.V.rows()));
        const auto oppositeKey = surface_cell_source_edge_key(
            candidate.boundary[opposite], candidate.boundary[(opposite + 1) % 4], static_cast<std::size_t>(mesh.V.rows()));
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
  std::map<std::tuple<authority::SourceEdgeTopologyKey, int, int>, int>
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
    if (sourceAuthority != nullptr && sourceFace >= 0 &&
        static_cast<std::size_t>(sourceFace) < sourceAuthority->face_count()) {
      const auto sourceFaceId = authority::SourceFaceId::from_index(
          sourceFace, sourceAuthority->face_count());
      if (!sourceFaceId) {
        point.face = -1;
        return point;
      }
      point.component = static_cast<int>(sourceAuthority->component_for_row(sourceFaceId.value()).index());
      point.sheet = static_cast<int>(sourceAuthority->sheet_for_row(sourceFaceId.value()).index());
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
    const auto edgeKey = surface_cell_source_edge_key(
          a, b, static_cast<std::size_t>(mesh.V.rows()));
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
        surface_cell_source_edge_key(
            candidate.boundary[0], candidate.boundary[1],
            static_cast<std::size_t>(mesh.V.rows())));
    const int vSubdivisions = subdivisionsBySourceEdge.at(
        surface_cell_source_edge_key(
            candidate.boundary[1], candidate.boundary[2],
            static_cast<std::size_t>(mesh.V.rows())));
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
      const auto edgeKey = surface_cell_source_edge_key(
          sourceVertex, nextSourceVertex,
          static_cast<std::size_t>(mesh.V.rows()));
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

namespace {

using remesh_pipeline_detail::SurfaceCellComponentStageProducts;

} // namespace

RemeshResult
remesh_from_raw_cross_field_impl_with_stage_products(
    const TriMesh &meshWhole, const Eigen::MatrixXd &rawCrossField,
    const RemeshOptions &options,
    const fields::CrossFieldResult *authoritativeCrossField,
    SurfaceCellComponentStageProducts *componentProducts) {
  using Clock = RemeshPipelineClock;
  const auto pipelineStart = Clock::now();
  auto phaseStart = pipelineStart;
  if (options.backend == RemeshBackend::SurfaceCells ||
      options.surfaceCells.enabled) {
    RemeshResultBuilder result;
    fields::CrossFieldResult crossFieldProduct;
    std::optional<geometry::SourceTopologyRegions> sourceTopologyRegionsProduct;
    std::optional<authority::FieldTransportAtlas> fieldTransportAtlasProduct;
    std::optional<geometry::FieldAlignedCurveNetwork> fieldAlignedNetworkProduct;
    std::optional<geometry::SurfaceCutGraph> surfaceCutGraphProduct;
    std::optional<geometry::GlobalTopologyPlan> globalTopologyPlanProduct;
    std::vector<geometry::PureQuadMesh> completedPatchesProduct;
    bool sourceGridRecoveryUsedProduct = false;
    Eigen::VectorXd sourceGridRecoveryTargetSizeProduct;
    bool hasSourceGridRecoveryTargetSizeProduct = false;
    bool sourceGridRecoveryTargetSizeRelaxedProduct = false;
    double sourceGridRecoveryTargetSizeMaxRelaxationRatioProduct = 1.0;
    std::optional<geometry::SurfaceOptimizationResult> optimizationProduct;
    std::optional<geometry::SurfaceFinalValidationReport> validationProduct;
    const bool retainRequested =
        options.surfaceCells.retainIntermediateGeometry;
    const bool retainForExecution =
        retainRequested || options.surfaceCells.injectFailureAfterStage >= 0;
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
    std::map<std::string, std::uint64_t> liveOwnedBytesByStage;
    bool crossFieldAccepted = false;
    auto record_memory_ownership = [&](const std::string &stage,
                                       const std::string &action,
                                       const std::uint64_t logicalPayloadBytes,
                                       const std::uint64_t retainedCapacityBytes) {
      if (action == "release" || retainedCapacityBytes == 0U) {
        liveOwnedBytesByStage.erase(stage);
      } else {
        liveOwnedBytesByStage[stage] = retainedCapacityBytes;
      }
      std::uint64_t simultaneousOwnedBytes = 0U;
      for (const auto &[liveStage, bytes] : liveOwnedBytesByStage) {
        (void)liveStage;
        simultaneousOwnedBytes += bytes;
      }
      SurfaceCellMemoryOwnershipEvent event;
      event.stage = stage;
      event.action = action;
      event.logicalPayloadBytes = logicalPayloadBytes;
      event.retainedCapacityBytes = retainedCapacityBytes;
      event.simultaneousOwnedBytes = simultaneousOwnedBytes;
      result.surfaceCellContext.memoryOwnershipTimeline.push_back(event);
      result.diagnostics.surfaceCellMemoryOwnershipTimeline.push_back(
          std::move(event));
      result.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes = std::max(
          result.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes,
          simultaneousOwnedBytes);
      result.diagnostics.surfaceCellEstimatedPeakSimultaneousOwnedBytes =
          result.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes;
    };
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
    auto clear_unrequested_intermediate_context = [&]() {
      if (retainRequested) return;

      result.surfaceCellContext.productSnapshots.traceNetwork =
          geometry::SurfaceCellNetwork{};
      result.surfaceCellContext.hasTraceNetwork = false;
      result.surfaceCellContext.productSnapshots.flowRepArcs =
          std::vector<geometry::FlowRepArc>{};
      result.surfaceCellContext.productSnapshots.flowRepNetwork =
          geometry::FlowRepSparseNetwork{};
      result.surfaceCellContext.hasFlowRepNetwork = false;
      result.surfaceCellContext.productSnapshots.embeddedArrangementArcs =
          std::vector<geometry::SurfaceArrangementArc>{};
      result.surfaceCellContext.hasEmbeddedArrangementArcs = false;
      result.surfaceCellContext.productSnapshots.arrangement = geometry::SurfaceCellComplex{};
      result.surfaceCellContext.hasArrangement = false;

      result.surfaceCellContext.tracingCurrentOwnedBytes = 0U;
      result.surfaceCellContext.flowRepCurrentOwnedBytes = 0U;
      result.surfaceCellContext.arrangementCurrentOwnedBytes = 0U;
      result.surfaceCellContext.tracingRetainedCapacityBytes = 0U;
      result.surfaceCellContext.flowRepRetainedCapacityBytes = 0U;
      result.surfaceCellContext.arrangementRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellTracingCurrentOwnedBytes = 0U;
      result.diagnostics.surfaceCellFlowRepCurrentOwnedBytes = 0U;
      result.diagnostics.surfaceCellArrangementCurrentOwnedBytes = 0U;
      result.diagnostics.surfaceCellTracingRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellFlowRepRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellArrangementRetainedCapacityBytes = 0U;
    };
    auto fail_surface_cells = [&](
                                  const SurfaceCellFailureCode code,
                                  const std::string &stage,
                                  const std::string &detailCode = "None",
                                  SurfaceCellFailureLocusDiagnostics locus = {})
        -> RemeshResult {
      const std::string failureCode = surface_cell_failure_code_name(code);
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
      result.diagnostics.terminalFailureDetailCode = detailCode;
      result.diagnostics.terminalFailureLocus = locus;
      const std::string noneFailure = surface_cell_failure_code_name(
          SurfaceCellFailureCode::None);
      if (result.diagnostics.originalSurfaceCellFailureCode.empty() ||
          result.diagnostics.originalSurfaceCellFailureCode == noneFailure) {
        result.diagnostics.originalSurfaceCellFailureCode = failureCode;
        result.diagnostics.originalSurfaceCellFailureStage = stage;
        result.diagnostics.originalSurfaceCellFailureDetailCode = detailCode;
        result.diagnostics.originalSurfaceCellFailureLocus = locus;
      }
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
      clear_unrequested_intermediate_context();

      if (options.surfaceCells.fallbackPolicy ==
          SurfaceCellFallbackPolicy::ReturnInputMesh) {
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
        result.diagnostics.terminalFailureDetailCode = "None";
        result.diagnostics.terminalFailureLocus = {};
        result.diagnostics.surfaceCellRemeshOccurred = false;
        record_face_degree_histogram(result);
        update_overall_pipeline_time();
        return std::move(result).finish_produced(
            RemeshProductKind::InputMeshFallback, crossFieldAccepted);
      }

      RemeshFailure failure;
      failure.kind = RemeshFailureKind::SurfaceCellRejected;
      failure.surfaceCellFailure = code;
      failure.stage = stage;
      failure.crossFieldAccepted = crossFieldAccepted;
      return std::move(result).finish_rejected(std::move(failure));
    };
    if (authoritativeCrossField != nullptr) {
      crossFieldProduct = *authoritativeCrossField;
    } else {
      try {
        crossFieldProduct =
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
    normalize_surface_cell_cross_field_directions(crossFieldProduct);
    result.surfaceCellContext.productSnapshots.crossField = crossFieldProduct;
    result.surfaceCellContext.productSnapshots.hasCrossField = true;
    result.surfaceCellContext.crossFieldHasMatching =
        crossFieldProduct.matchingComputed;
    result.surfaceCellContext.crossFieldHasSingularities =
        crossFieldProduct.singularitiesComputed;
    result.rawCrossField = crossFieldProduct.rawField;
    result.crossFieldMatching = crossFieldProduct.matching;
    result.crossFieldEffort = crossFieldProduct.effort;
    result.crossFieldSingularCycles =
        crossFieldProduct.singularCycles;
    result.crossFieldSingularIndices =
        crossFieldProduct.singularIndices;
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
    hash_matrix(crossFieldHash, crossFieldProduct.rawField);
    hash_vector(crossFieldHash, crossFieldProduct.matching);
    hash_vector(crossFieldHash, crossFieldProduct.effort);
    hash_combine_u64(
        crossFieldHash,
        crossFieldProduct.edgeTransitions.size());
    for (const fields::CrossFieldEdgeTransition &transition :
         crossFieldProduct.edgeTransitions) {
      hash_combine_i64(crossFieldHash, transition.sourceEdge);
      hash_combine_i64(crossFieldHash, transition.sourceVertex0);
      hash_combine_i64(crossFieldHash, transition.sourceVertex1);
      hash_combine_i64(crossFieldHash, transition.firstFace);
      hash_combine_i64(crossFieldHash, transition.secondFace);
      hash_combine_i64(crossFieldHash, transition.matching);
      hash_combine_double(crossFieldHash, transition.effort);
    }
    hash_vector(crossFieldHash,
                crossFieldProduct.singularCycles);
    hash_vector(crossFieldHash,
                crossFieldProduct.singularIndices);
    hash_vector(crossFieldHash, crossFieldProduct.confidence);
    hash_vector(crossFieldHash,
                crossFieldProduct.uncoveredFaces);
    hash_combine_i64(crossFieldHash,
                     crossFieldProduct.matchingComputed ? 1 : 0);
    hash_combine_i64(
        crossFieldHash,
        crossFieldProduct.singularitiesComputed ? 1 : 0);
    hash_combine_i64(crossFieldHash,
                     crossFieldProduct.confidenceComputed ? 1 : 0);
    hash_combine_i64(
        crossFieldHash,
        crossFieldProduct.uncoveredFacePolicyApplied ? 1 : 0);
    record_surface_cell_context_product(
        result.surfaceCellContext, "cross-field",
        make_identity("cross-field", crossFieldHash,
                      static_cast<std::size_t>(
                          crossFieldProduct.rawField.rows())),
        true);
    const SurfaceCellFailureCode crossFieldFailure =
        validate_surface_cell_cross_field(
            meshWhole, crossFieldProduct,
            options.surfaceCells);
    if (crossFieldFailure != SurfaceCellFailureCode::None) {
      return fail_surface_cells(crossFieldFailure, "cross-field-validation");
    }
    crossFieldAccepted = true;

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
    if (railBuild.is_rejected()) {
      return fail_surface_cells(SurfaceCellFailureCode::InvalidRailTopology,
                                "feature");
    }
    const SurfaceCellRailBuildProduct *railProduct = railBuild.produced_product();
    if (railProduct == nullptr) {
      return fail_surface_cells(SurfaceCellFailureCode::InvalidRailTopology,
                                "feature");
    }
    const std::vector<geometry::SurfaceCellRail> &authoritativeRails =
        railProduct->rails;
    const std::set<authority::SourceEdgeTopologyKey> hardFeatureRailEdges =
        hard_feature_edge_keys_from_rails(
            authoritativeRails, static_cast<std::size_t>(meshWhole.V.rows()));
    result.surfaceCellContext.productSnapshots.authoritativeRails = authoritativeRails;
    result.surfaceCellContext.productSnapshots.hasAuthoritativeRails = true;
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
    const std::set<std::uint64_t> reliefHardFeatureRepresentation =
        relief_representation_edges(hardFeatureRailEdges);
    const geometry::ReliefTopologyResult reliefTopology =
        geometry::analyze_relief_topology(
            meshWhole.V, meshWhole.F, reliefValues,
            reliefHardFeatureRepresentation, reliefOptions);
    const std::set<authority::SourceEdgeTopologyKey> reliefBarrierEdges =
        relief_barrier_edges_from_topology(
            reliefTopology, static_cast<std::size_t>(meshWhole.V.rows()));
    std::set<authority::SourceEdgeTopologyKey> operationalBarrierEdges = hardFeatureRailEdges;
    operationalBarrierEdges.insert(reliefBarrierEdges.begin(),
                                   reliefBarrierEdges.end());
    geometry::ReliefRootSelectionOptions reliefRootOptions =
        options.surfaceCells.reliefRoots;
    reliefRootOptions.hardBarrierEdges =
        relief_representation_edges(operationalBarrierEdges);
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
        crossFieldProduct.primaryDirections;
    const Eigen::MatrixXd &faceAxisY =
        crossFieldProduct.secondaryDirections;
    geometry::SurfaceCellTracingOptions tracingOptions;
    tracingOptions.authoritativeRails = authoritativeRails;
    tracingOptions.hardFeatureEdges = hardFeatureRailEdges;
    tracingOptions.reliefRootVertices = reliefRootSelection.roots;
    tracingOptions.reliefRegionLabels = reliefRootSelection.labels;
    tracingOptions.reliefBarrierEdges = reliefBarrierEdges;
    tracingOptions.reliefBarriersEmbedded = false;
    if (!geometry::surface_cell_tracing_detail::
            source_surface_classifier_options_valid(
                options.surfaceCells.sourceClassifier)) {
      return fail_surface_cells(
          SurfaceCellFailureCode::InvalidClassifierOptions,
          "source-classification");
    }
    // Hard-feature rails already own topology-region/chart separation. They
    // are not isolation-sheet barriers; close-sheet classification and any
    // future explicit isolation barriers remain a separate authority domain.
    const std::set<authority::SourceEdgeTopologyKey> sourceIsolationBarrierEdges;
    const geometry::SourceSurfaceLabels sourceSurfaceLabels =
        geometry::surface_cell_tracing_detail::classify_source_surface_labels(
            meshWhole.V, meshWhole.F, sourceIsolationBarrierEdges,
            options.surfaceCells.sourceClassifier);
    result.surfaceCellContext.productSnapshots.sourceSurfaceLabels = sourceSurfaceLabels;
    result.surfaceCellContext.productSnapshots.hasSourceSurfaceLabels = true;
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
    sourceTopologyRegionsProduct =
        geometry::surface_cell_tracing_detail::build_source_topology_regions(
            meshWhole.F, tracingOptions);
    if (!sourceTopologyRegionsProduct.has_value() ||
        !sourceTopologyRegionsProduct->matches_source_faces(
            meshWhole.F, static_cast<std::size_t>(meshWhole.V.rows()))) {
      return fail_surface_cells(
          SurfaceCellFailureCode::InvalidFieldTransportAtlas,
          "field-transport-atlas/source-authority");
    }
    result.surfaceCellContext.productSnapshots.sourceTopologyRegions =
        sourceTopologyRegionsProduct;
    tracingOptions.sourceAuthority = &*sourceTopologyRegionsProduct;

    const auto topology_face_locus = [](
        const authority::SourceFaceTopologyKey &face) {
      const auto &vertices = face.vertices();
      return std::array<std::size_t, 3>{vertices[0].index(),
                                        vertices[1].index(),
                                        vertices[2].index()};
    };
    const auto topology_edge_locus = [](
        const authority::SourceEdgeTopologyKey &edge) {
      return std::array<std::size_t, 2>{edge.first().index(),
                                        edge.second().index()};
    };
    const auto atlas_failure_locus = [&](
        const authority::FieldAtlasBuildError &error) {
      SurfaceCellFailureLocusDiagnostics locus;
      if (error.sourceVertex.has_value())
        locus.sourceVertex = error.sourceVertex->index();
      if (error.sourceEdge.has_value())
        locus.sourceEdge = topology_edge_locus(*error.sourceEdge);
      if (error.sourceFace.has_value() &&
          error.sourceFace->index() <
              static_cast<std::size_t>(meshWhole.F.rows())) {
        const Eigen::Index row =
            static_cast<Eigen::Index>(error.sourceFace->index());
        locus.sourceFace = std::array<std::size_t, 3>{
            static_cast<std::size_t>(meshWhole.F(row, 0)),
            static_cast<std::size_t>(meshWhole.F(row, 1)),
            static_cast<std::size_t>(meshWhole.F(row, 2))};
      }
      if (error.branch.has_value())
        locus.branch = static_cast<int>(error.branch->value());
      if (error.topologyRegion.has_value())
        locus.topologyRegion = error.topologyRegion->index();
      return locus;
    };
    const auto network_failure_locus = [&](
        const geometry::FieldAlignedCurveNetworkError &error,
        const authority::FieldTransportAtlas &atlas) {
      return remesh_pipeline_detail::
          project_field_aligned_curve_network_failure_locus(error, atlas);
    };
    const auto cut_graph_failure_locus = [&](
        const geometry::SurfaceCutGraphError &error) {
      SurfaceCellFailureLocusDiagnostics locus;
      if (error.sourceVertex.has_value())
        locus.sourceVertex = error.sourceVertex->index();
      if (error.sourceEdge.has_value())
        locus.sourceEdge = topology_edge_locus(*error.sourceEdge);
      if (error.sourceFace.has_value())
        locus.sourceFace = topology_face_locus(*error.sourceFace);
      if (error.originatingRotationSystemInconsistencyReason.has_value()) {
        locus.rotationSystemInconsistencyReason =
            geometry::rotation_system_inconsistency_reason_name(
                *error.originatingRotationSystemInconsistencyReason);
      }
      if (error.trace.has_value()) locus.trace = error.trace->index();
      locus.traceEventIndex = error.traceEventIndex;
      if (error.traceEventPositionFailureReason.has_value()) {
        locus.traceEventPositionFailureReason =
            geometry::trace_event_position_failure_reason_name(
                *error.traceEventPositionFailureReason);
      }
      if (error.traceEventPositionPass.has_value()) {
        locus.traceEventPositionPass = geometry::trace_event_position_pass_name(
            *error.traceEventPositionPass);
      }
      locus.cutCandidateCount = error.cutCandidates.size();
      locus.nonDiscComponentCount = error.nonDiscComponentCount;
      locus.remainingAdmissibleEdgeCount = error.remainingAdmissibleEdgeCount;
      locus.certificationAttemptIndex = error.certificationAttemptIndex;
      locus.certificationCutEdgeCount = error.certificationCutEdgeCount;
      return locus;
    };
    const auto topology_plan_failure_locus = [&](
        const geometry::GlobalTopologyPlanError &error) {
      SurfaceCellFailureLocusDiagnostics locus;
      if (error.sourceVertex.has_value())
        locus.sourceVertex = error.sourceVertex->index();
      if (error.sourceEdge.has_value())
        locus.sourceEdge = topology_edge_locus(*error.sourceEdge);
      if (error.sourceFace.has_value())
        locus.sourceFace = topology_face_locus(*error.sourceFace);
      return locus;
    };

    authority::FieldTransportAtlasBuildResult atlasBuild =
        authority::FieldTransportAtlas::make(
            meshWhole, *sourceTopologyRegionsProduct, hardFeatureRailEdges,
            crossFieldProduct);
    if (!atlasBuild) {
      const authority::FieldAtlasBuildError &error = atlasBuild.error();
      result.surfaceCellContext.productSnapshots.fieldTransportAtlasError =
          error;
      std::ostringstream stage;
      stage << "field-transport-atlas/"
            << authority::field_atlas_build_error_code_name(error.code);
      if (error.sourceEdge.has_value()) {
        stage << ";sourceEdge=" << error.sourceEdge->first().index() << '-'
              << error.sourceEdge->second().index();
      }
      if (error.sourceFace.has_value()) {
        stage << ";sourceFace=" << error.sourceFace->index();
      }
      if (error.sourceVertex.has_value()) {
        stage << ";sourceVertex=" << error.sourceVertex->index();
      }
      if (error.topologyRegion.has_value()) {
        stage << ";topologyRegion=" << error.topologyRegion->index();
      }
      if (error.branch.has_value()) {
        stage << ";branch=" << static_cast<int>(error.branch->value());
      }
      if (error.incompleteCycleBasisReason.has_value()) {
        stage << ";incompleteCycleBasisReason="
              << authority::incomplete_cycle_basis_reason_name(
                     *error.incompleteCycleBasisReason);
      }
      for (std::size_t index = 0U;
           index < error.regionCycleBasisDiagnostics.size(); ++index) {
        const auto &row = error.regionCycleBasisDiagnostics[index];
        stage << ";cycleBasisRegion[" << index << "]={topologyRegion="
              << row.topologyRegion.index()
              << ",localMeshAvailable="
              << (row.localMeshAvailable ? "true" : "false")
              << ",bundleInitialized="
              << (row.bundleInitialized ? "true" : "false")
              << ",V=" << row.vertexCount << ",E=" << row.edgeCount
              << ",F=" << row.faceCount
              << ",eulerCharacteristic=" << row.eulerCharacteristic
              << ",boundaryLoopCount=" << row.boundaryLoopCount
              << ",genus=" << row.genus
              << ",interiorLocalVertexCount=" << row.interiorLocalVertexCount
              << ",expectedCycleCount=" << row.expectedCycleCount
              << ",cycleRows=" << row.cycleRowCount
              << ",cycleCurvatures=" << row.cycleCurvatureCount
              << ",innerAdjacencies=" << row.innerAdjacencyCount << '}';
      }
      for (std::size_t index = 0U;
           index < error.regionTransportDiagnostics.size(); ++index) {
        const auto &row = error.regionTransportDiagnostics[index];
        stage << ";transportRegion[" << index << "]={topologyRegion="
              << row.topologyRegion.index()
              << ",hardFeatureEdges=" << row.hardFeatureEdgeCount
              << ",barrierEdges=" << row.barrierEdgeCount
              << ",barrierVertices=" << row.barrierVertexCount
              << ",barrierComponents=" << row.barrierComponentCount
              << ",barrierChi=" << row.barrierEulerCharacteristic
              << ",boundaryBarrierVertices="
              << row.barrierRegionBoundaryVertexCount
              << ",barrierIncidentSingularities="
              << row.barrierIncidentSingularityCount
              << ",uncutChi=" << row.uncutEulerCharacteristic
              << ",cutChi=" << row.cutEulerCharacteristic
              << ",uncutBoundaryLoops=" << row.uncutBoundaryLoopCount
              << ",cutBoundaryLoops=" << row.cutBoundaryLoopCount << '}';
        for (std::size_t singularityIndex = 0U;
             singularityIndex < row.barrierIncidentSingularities.size();
             ++singularityIndex) {
          const auto &singularity =
              row.barrierIncidentSingularities[singularityIndex];
          stage << ";transportRegion[" << index
                << "].barrierSingularity[" << singularityIndex
                << "]={sourceVertex=" << singularity.sourceVertex.index()
                << ",indexNumerator=" << singularity.indexNumerator
                << ",barrierDegree=" << singularity.barrierDegree
                << ",transportStarComponents="
                << singularity.transportStarComponentCount << '}';
        }
      }
      return fail_surface_cells(
          SurfaceCellFailureCode::InvalidFieldTransportAtlas, stage.str(),
          authority::field_atlas_build_error_code_name(error.code),
          atlas_failure_locus(error));
    }
    fieldTransportAtlasProduct = std::move(atlasBuild.value());
    result.surfaceCellContext.productSnapshots.fieldTransportAtlas =
        fieldTransportAtlasProduct;
    tracingOptions.fieldTransportAtlas = &*fieldTransportAtlasProduct;
    auto fieldAlignedBuild = geometry::FieldAlignedCurveNetwork::make(
        meshWhole,
        *sourceTopologyRegionsProduct, *fieldTransportAtlasProduct,
        authoritativeRails);
    if (!fieldAlignedBuild) {
      const geometry::FieldAlignedCurveNetworkError &error =
          fieldAlignedBuild.error();
      return fail_surface_cells(
          SurfaceCellFailureCode::NotProductionReady,
          "field-aligned-network",
          geometry::field_aligned_curve_network_error_code_name(error.code),
          network_failure_locus(error, *fieldTransportAtlasProduct));
    }
    fieldAlignedNetworkProduct = std::move(fieldAlignedBuild.value());
    result.surfaceCellContext.productSnapshots.fieldAlignedCurveNetwork =
        fieldAlignedNetworkProduct;
    tracingOptions.fieldAlignedNetwork = &*fieldAlignedNetworkProduct;
    auto surfaceCutGraphBuild = geometry::SurfaceCutGraph::make(
        meshWhole.F, static_cast<std::size_t>(meshWhole.V.rows()),
        *sourceTopologyRegionsProduct, *fieldTransportAtlasProduct,
        *fieldAlignedNetworkProduct);
    if (!surfaceCutGraphBuild) {
      std::string detail = std::string("surface-cut-graph/") +
          geometry::surface_cut_graph_error_code_name(
              surfaceCutGraphBuild.error().code);
      if (surfaceCutGraphBuild.error().originatingTopologyError.has_value()) {
        detail += "/origin=";
        detail += geometry::global_topology_plan_error_code_name(
            *surfaceCutGraphBuild.error().originatingTopologyError);
      }
      return fail_surface_cells(
          SurfaceCellFailureCode::NotProductionReady, std::move(detail),
          geometry::surface_cut_graph_error_code_name(
              surfaceCutGraphBuild.error().code),
          cut_graph_failure_locus(surfaceCutGraphBuild.error()));
    }
    surfaceCutGraphProduct = std::move(surfaceCutGraphBuild.value());
    result.surfaceCellContext.productSnapshots.surfaceCutGraph =
        surfaceCutGraphProduct;
    auto globalTopologyBuild = geometry::GlobalTopologyPlan::make(
        meshWhole.F, static_cast<std::size_t>(meshWhole.V.rows()),
        *sourceTopologyRegionsProduct, *fieldAlignedNetworkProduct,
        *surfaceCutGraphProduct);
    if (!globalTopologyBuild) {
      const geometry::GlobalTopologyPlanError &error =
          globalTopologyBuild.error();
      return fail_surface_cells(
          SurfaceCellFailureCode::NotProductionReady,
          std::string("global-topology-plan/") +
              geometry::global_topology_plan_error_code_name(error.code),
          geometry::global_topology_plan_error_code_name(error.code),
          topology_plan_failure_locus(error));
    }
    globalTopologyPlanProduct = std::move(globalTopologyBuild.value());
    result.surfaceCellContext.productSnapshots.globalTopologyPlan =
        globalTopologyPlanProduct;
    result.surfaceCellContext.fieldAlignedNetworkAuthorityUsed =
        tracingOptions.fieldAlignedNetwork != nullptr;
    result.surfaceCellContext.rawSingularityProjectionUsed =
        tracingOptions.has_legacy_raw_singularity_ingress();
    record_surface_cell_context_product(
        result.surfaceCellContext, "field-transport-atlas",
        make_identity(
            "field-transport-atlas",
            authority::field_transport_atlas_hash(*fieldTransportAtlasProduct),
            fieldTransportAtlasProduct->adjacencies().size() +
                fieldTransportAtlasProduct->cycles().size()),
        true);
    record_surface_cell_context_product(
        result.surfaceCellContext, "field-aligned-network",
        make_identity(
            "field-aligned-network",
            geometry::field_aligned_curve_network_hash(
                *fieldAlignedNetworkProduct),
            fieldAlignedNetworkProduct->nodes().size() +
                fieldAlignedNetworkProduct->singularity_ports().size() +
                fieldAlignedNetworkProduct->mandatory_edges().size()),
        true);
    record_surface_cell_context_product(
        result.surfaceCellContext, "surface-cut-graph",
        make_identity(
            "surface-cut-graph",
            geometry::surface_cut_graph_hash(*surfaceCutGraphProduct),
            surfaceCutGraphProduct->cut_edges().size() +
                surfaceCutGraphProduct->certificate().faces.size()),
        true);
    record_surface_cell_context_product(
        result.surfaceCellContext, "global-topology-plan",
        make_identity(
            "global-topology-plan",
            geometry::global_topology_plan_hash(*globalTopologyPlanProduct),
            globalTopologyPlanProduct->arcs().size() +
                globalTopologyPlanProduct->regions().size() +
                globalTopologyPlanProduct->rotation_system().size()),
        true);
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
            meshWhole.V, meshWhole.F, crossFieldProduct,
            targetSize.targetSize, tracingOptions);
    result.diagnostics.surfaceCellAuthoritativeProducerDisposition =
        geometry::surface_cell_producer_disposition_name(
            traceNetwork.phaseFront.disposition());
    const geometry::SurfacePhaseFrontProduct *phaseFrontProduct =
        traceNetwork.phaseFront.produced_product();
    result.diagnostics.surfaceCellTopologyRegionCount = 0U;
    result.diagnostics.surfaceCellInternalIsolationSeamCount = 0U;
    result.diagnostics.surfaceCellTopologyRegionHashes.clear();
    result.diagnostics.surfaceCellTopologyRegionEulerCharacteristics.clear();
    result.diagnostics.surfaceCellTopologyRegionBoundaryLoopCounts.clear();
    result.diagnostics.surfaceCellTopologyRegionIsolationSheetCounts.clear();
    result.diagnostics.surfaceCellBoundedDiskBoundaryPhaseCount = 0U;
    result.diagnostics.surfaceCellBoundedDiskBoundaryRunCount = 0U;
    result.diagnostics.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount = 0U;
    result.diagnostics.surfaceCellBoundedDiskConstructedChartCount = 0U;
    result.diagnostics.surfaceCellBoundedDiskBoundaryPhaseHashes.clear();
    result.diagnostics.surfaceCellPeriodicHolonomies.clear();
    result.diagnostics.surfaceCellPeriodicHolonomyAvailable = false;
    if (phaseFrontProduct != nullptr) {
      // Preserve the independently validated typed source-authority domain for
      // disconnected-component aggregation even when the heavyweight trace
      // network is released later in this pipeline execution.
      if (!sourceTopologyRegionsProduct.has_value() ||
          !phaseFrontProduct->sourceTopologyRegions().matches_source_faces(
              meshWhole.F, static_cast<std::size_t>(meshWhole.V.rows())) ||
          !fieldTransportAtlasProduct.has_value() ||
          !fieldTransportAtlasProduct->matches_source_faces(
              meshWhole.F, phaseFrontProduct->sourceTopologyRegions(),
              static_cast<std::size_t>(meshWhole.V.rows()))) {
        return fail_surface_cells(
            SurfaceCellFailureCode::InvalidFieldTransportAtlas,
            "field-transport-atlas/phase-front-binding");
      }
      result.diagnostics.surfaceCellTopologyRegionCount =
          phaseFrontProduct->sourceTopologyRegions().regions().size();
      result.diagnostics.surfaceCellInternalIsolationSeamCount = 0U;
      result.diagnostics.surfaceCellTopologyRegionHashes.clear();
      result.diagnostics.surfaceCellTopologyRegionEulerCharacteristics.clear();
      result.diagnostics.surfaceCellTopologyRegionBoundaryLoopCounts.clear();
      result.diagnostics.surfaceCellTopologyRegionIsolationSheetCounts.clear();
      for (const auto &region : phaseFrontProduct->sourceTopologyRegions().regions()) {
        result.diagnostics.surfaceCellInternalIsolationSeamCount +=
            region.isolation_seams().size();
        result.diagnostics.surfaceCellTopologyRegionHashes.push_back(
            geometry::surface_topology_region_hash(region));
        result.diagnostics.surfaceCellTopologyRegionEulerCharacteristics.push_back(
            region.euler_characteristic());
        result.diagnostics.surfaceCellTopologyRegionBoundaryLoopCounts.push_back(
            region.boundary_loop_count());
        result.diagnostics.surfaceCellTopologyRegionIsolationSheetCounts.push_back(
            region.isolation_sheets().size());
      }
      result.diagnostics.surfaceCellBoundedDiskBoundaryPhaseCount =
          phaseFrontProduct->boundedDiskBoundaryPhases().size();
      result.diagnostics.surfaceCellBoundedDiskBoundaryRunCount = 0U;
      result.diagnostics.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount = 0U;
      result.diagnostics.surfaceCellBoundedDiskConstructedChartCount = 0U;
      result.diagnostics.surfaceCellBoundedDiskBoundaryPhaseHashes.clear();
      for (const auto &phase : phaseFrontProduct->boundedDiskBoundaryPhases()) {
        result.diagnostics.surfaceCellBoundedDiskBoundaryRunCount +=
            phase.runs.size();
        if (!phase.rectangular) {
          ++result.diagnostics.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount;
        }
        if (phase.chartConstructed) {
          ++result.diagnostics.surfaceCellBoundedDiskConstructedChartCount;
        }
        result.diagnostics.surfaceCellBoundedDiskBoundaryPhaseHashes.push_back(
            phase.structuralHash);
      }
      result.diagnostics.surfaceCellPeriodicHolonomies.clear();
      for (const auto &relation : phaseFrontProduct->periodicHolonomies()) {
        const auto region = std::find_if(
            phaseFrontProduct->sourceTopologyRegions().regions().begin(),
            phaseFrontProduct->sourceTopologyRegions().regions().end(),
            [&](const geometry::SurfaceTopologyRegion &candidate) {
              return candidate.id() == relation.sourceTopologyRegion();
            });
        if (region == phaseFrontProduct->sourceTopologyRegions().regions().end()) {
          result.diagnostics.surfaceCellFirstInvalidProducerStage =
              "tracing/phase-front";
          result.diagnostics.surfaceCellFirstInvalidProducerReason =
              "InvalidAuthoritativePeriodicTopologyRegion";
          return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                    "tracing");
        }
        SurfaceCellPeriodicHolonomyDiagnostics diagnostic;
        diagnostic.sourceComponent =
            static_cast<int>(region->component().index());
        diagnostic.sourceTopologyRegion =
            static_cast<int>(relation.sourceTopologyRegion().index());
        const std::vector<authority::IsolationSheetId> regionSheets =
            region->isolation_sheets();
        diagnostic.sourceSheet =
            regionSheets.size() == 1U
                ? static_cast<int>(regionSheets.front().index())
                : -1;
        diagnostic.sourceIsolationSheets.reserve(regionSheets.size());
        for (const authority::IsolationSheetId sheet : regionSheets) {
          diagnostic.sourceIsolationSheets.push_back(
              static_cast<int>(sheet.index()));
        }
        const auto diagnosticQuarterTurn = relation.action().rotation.value();
        diagnostic.quarterTurnRotation =
            static_cast<int>(diagnosticQuarterTurn);
        diagnostic.translationU = static_cast<int>(relation.action().shift.x);
        diagnostic.translationV = static_cast<int>(relation.action().shift.y);
        for (const authority::TransitionStep &step : relation.route().steps()) {
          diagnostic.routeTransitionIndices.push_back(
              step.interior().has_value()
                  ? static_cast<int>(step.interior()->index())
                  : -1);
          diagnostic.routeTopologyKeys.push_back(
              surface_cell_source_edge_diagnostic_key(step.topology()));
        }
        for (const authority::TransitionStep &step : relation.cutRoute().steps()) {
          diagnostic.cutSourceEdges.push_back(
              step.interior().has_value()
                  ? static_cast<int>(step.interior()->index())
                  : -1);
          diagnostic.cutSourceTopology.push_back(
              surface_cell_source_edge_diagnostic_key(step.topology()));
        }
        result.diagnostics.surfaceCellPeriodicHolonomies.push_back(
            std::move(diagnostic));
      }
      result.diagnostics.surfaceCellPeriodicHolonomyAvailable =
          !phaseFrontProduct->periodicHolonomies().empty();
      if (!phaseFrontProduct->periodicHolonomies().empty()) {
        const auto &primary = phaseFrontProduct->periodicHolonomies().front();
        result.diagnostics.surfaceCellPeriodicHolonomyQuarterTurnRotation =
            static_cast<int>(primary.action().rotation.value());
        result.diagnostics.surfaceCellPeriodicHolonomyTranslationU =
            static_cast<int>(primary.action().shift.x);
        result.diagnostics.surfaceCellPeriodicHolonomyTranslationV =
            static_cast<int>(primary.action().shift.y);
        result.diagnostics.surfaceCellPeriodicHolonomyRouteEdgeCount =
            primary.route().steps().size();
        result.diagnostics.surfaceCellPeriodicCutEdgeCount =
            primary.cutRoute().steps().size();
      }
    }
    if (const auto *failure = traceNetwork.phaseFront.rejection();
        failure != nullptr &&
        failure->reason != geometry::SurfacePhaseFrontFailureReason::None &&
        result.diagnostics.surfaceCellFirstInvalidProducerStage.empty()) {
      result.diagnostics.surfaceCellFirstInvalidProducerStage =
          "tracing/phase-front";
      result.diagnostics.surfaceCellFirstInvalidProducerReason =
          geometry::surface_phase_front_failure_reason_name(failure->reason);
      result.diagnostics.surfaceCellFirstInvalidProducerCell = failure->cell;
      result.diagnostics.surfaceCellFirstInvalidProducerHalfedge = failure->side;
      result.diagnostics.surfaceCellFirstInvalidProducerFace = failure->face;
      result.diagnostics.surfaceCellFirstInvalidProducerVertex =
          failure->sourceVertex;
      result.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
          failure->sourceEdge;
      result.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
          failure->secondarySourceEdge;
      if (failure->reason ==
          geometry::SurfacePhaseFrontFailureReason::UnsupportedSourceSheetTopology) {
        // This public reason is emitted only after the ordered regional
        // producer chain has returned NotApplicable from uniform, periodic
        // annulus, and curved bounded-disk production for the same region.
        result.diagnostics.surfaceCellUniformPhaseFrontProducerDeclined = true;
        result.diagnostics.surfaceCellPeriodicPhaseFrontProducerDeclined = true;
        result.diagnostics.surfaceCellBoundedDiskPhaseFrontProducerDeclined = true;
      }
    }
    if (traceNetwork.phaseFront.rejection_reason() ==
            geometry::SurfacePhaseFrontFailureReason::
                UnsupportedSourceSheetTopology &&
        !hardFeatureRailEdges.empty()) {
      // NotApplicable is the only outcome allowed to enter the legacy tracing
      // fallback. A hard-feature region that every authoritative producer
      // declined cannot silently continue without its mandatory barrier.
      if (retainForExecution) {
        result.surfaceCellContext.productSnapshots.traceNetwork = std::move(traceNetwork);
        result.surfaceCellContext.hasTraceNetwork = true;
      }
      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                "tracing");
    }
    const bool useAuthoritativePhaseFront = phaseFrontProduct != nullptr;
    AuthoritativePhaseFrontMeshResult authoritativePhaseFrontMesh;
    if (useAuthoritativePhaseFront) {
      authoritativePhaseFrontMesh = build_authoritative_phase_front_mesh(
          meshWhole.V, meshWhole.F, *phaseFrontProduct);
      if (!authoritativePhaseFrontMesh.success) {
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "tracing/phase-front-materialization";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            authoritativePhaseFrontMesh.failure;
        result.diagnostics.surfaceCellFirstInvalidProducerCell =
            authoritativePhaseFrontMesh.invalidCell;
        result.diagnostics.surfaceCellFirstInvalidProducerHalfedge =
            authoritativePhaseFrontMesh.invalidEdge;
        if (retainForExecution) {
          result.surfaceCellContext.productSnapshots.traceNetwork = std::move(traceNetwork);
          result.surfaceCellContext.hasTraceNetwork = true;
        }
        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                  "tracing");
      }
      result.diagnostics.surfaceCellConsumedTopologyRegionCount =
          authoritativePhaseFrontMesh.consumedTopologyRegions;
      result.diagnostics.surfaceCellConsumedInternalIsolationSeamCount =
          authoritativePhaseFrontMesh.consumedInternalIsolationSeams;
      result.diagnostics.surfaceCellConsumedPeriodicHolonomyCount =
          authoritativePhaseFrontMesh.consumedPeriodicHolonomies;
      result.diagnostics.surfaceCellMaterializedConnectedComponentCount =
          authoritativePhaseFrontMesh.connectedComponents;
      result.diagnostics.surfaceCellMaterializedBoundaryLoopCount =
          authoritativePhaseFrontMesh.boundaryLoopCount;
      result.diagnostics.surfaceCellMaterializedEulerCharacteristic =
          authoritativePhaseFrontMesh.eulerCharacteristic;
    }
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
    const std::uint64_t tracingOwnedBytes =
        trace_network_owned_bytes(traceNetwork);
    const std::uint64_t tracingLogicalBytes =
        trace_network_logical_bytes(traceNetwork);
    result.surfaceCellContext.tracingLogicalPayloadBytes = tracingLogicalBytes;
    result.surfaceCellContext.tracingRetainedCapacityBytes = tracingOwnedBytes;
    result.diagnostics.surfaceCellTracingLogicalPayloadBytes =
        tracingLogicalBytes;
    result.diagnostics.surfaceCellTracingRetainedCapacityBytes =
        tracingOwnedBytes;
    record_memory_ownership("tracing", "acquire", tracingLogicalBytes,
                            tracingOwnedBytes);
    result.surfaceCellContext.tracingCurrentOwnedBytes = tracingOwnedBytes;
    result.surfaceCellContext.tracingPeakOwnedBytes = tracingOwnedBytes;
    result.diagnostics.surfaceCellTracingCurrentOwnedBytes = tracingOwnedBytes;
    result.diagnostics.surfaceCellTracingPeakOwnedBytes = tracingOwnedBytes;
    result.surfaceCellContext.maxSimultaneousLiveLargeStructures = 1;
    result.diagnostics.surfaceCellMaxSimultaneousLiveLargeStructures = 1;
    const std::uint64_t tracingHash = hash_trace_network(traceNetwork);
    if (retainForExecution) {
      result.surfaceCellContext.productSnapshots.traceNetwork = traceNetwork;
      result.surfaceCellContext.hasTraceNetwork = true;
    }
    // The typed source authority has already been copied into its declared
    // stage product. Do not retain a pointer into the mutable trace product.
    phaseFrontProduct = nullptr;
    const geometry::SourceTopologyRegions *retainedSourceAuthority =
        sourceTopologyRegionsProduct.has_value()
            ? &sourceTopologyRegionsProduct.value()
            : nullptr;
    const geometry::SurfaceCellNetwork &retainedTraceNetwork = traceNetwork;
    const SurfaceCellObjectIdentity tracingIdentity = make_identity(
        "tracing", tracingHash, result.diagnostics.surfaceCellTraceSegmentCount);
    mark_stage_consumed("relief", reliefIdentity,
                        SurfaceCellConsumptionKind::Partial);
    record_surface_cell_stage("tracing", reliefIdentity, tracingIdentity, true,
                              result.diagnostics.surfaceCellTracingSeconds);
    completedSurfaceCellStages.push_back("tracing");
    if (retainedTraceNetwork.phaseFront.is_rejected()) {
      if (!retainForExecution) {
        result.surfaceCellContext.productSnapshots.traceNetwork =
            geometry::SurfaceCellNetwork{};
        result.surfaceCellContext.hasTraceNetwork = false;
      }
      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                "tracing");
    }
    if (options.surfaceCells.injectFailureAfterStage == 3) {
      if (!retainForExecution) {
        result.surfaceCellContext.productSnapshots.traceNetwork =
            geometry::SurfaceCellNetwork{};
        result.surfaceCellContext.hasTraceNetwork = false;
      }
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "tracing");
    }

    const auto strandsStart = Clock::now();
    geometry::FlowRepSelectionInput flowRepInput =
        geometry::build_flow_rep_selection_input(
            meshWhole.V, meshWhole.F, targetSize.targetSize,
            retainedTraceNetwork, tracingOptions.defaultTargetSize);
    const std::uint64_t flowRepInputOwnedBytes =
        flow_rep_selection_input_owned_bytes(flowRepInput);
    record_memory_ownership("flowrep-selection", "acquire",
                            flowRepInputOwnedBytes, flowRepInputOwnedBytes);
    result.surfaceCellContext.flowRepPeakOwnedBytes = flowRepInputOwnedBytes;
    result.diagnostics.surfaceCellFlowRepPeakOwnedBytes =
        flowRepInputOwnedBytes;
    result.surfaceCellContext.maxSimultaneousLiveLargeStructures =
        std::max(result.surfaceCellContext.maxSimultaneousLiveLargeStructures,
                 2);
    result.diagnostics.surfaceCellMaxSimultaneousLiveLargeStructures =
        std::max<std::size_t>(
            result.diagnostics.surfaceCellMaxSimultaneousLiveLargeStructures,
            2U);
    if (!retainForExecution) {
      // Source labels already live in sourceSurfaceLabels. Do not retain a
      // second copy merely to keep a consumed trace-stage shell alive.
      traceNetwork = geometry::SurfaceCellNetwork{};
      result.surfaceCellContext.productSnapshots.traceNetwork = geometry::SurfaceCellNetwork{};
      record_memory_ownership("tracing", "release", 0U, 0U);
      result.surfaceCellContext.tracingRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellTracingRetainedCapacityBytes = 0U;
      result.surfaceCellContext.hasTraceNetwork = false;
      result.surfaceCellContext.traceStorageReleasedAfterFlowRep = true;
      result.diagnostics.surfaceCellTraceStorageReleasedAfterFlowRep = true;
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
          meshWhole.V, meshWhole.F, crossFieldProduct,
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
      if (retainForExecution) {
        result.surfaceCellContext.flowRepEndpointDiagnostics =
            std::move(endpointCompletion.diagnostics);
      }
      const auto *endpointFailure = endpointCompletion.rejection();
      result.surfaceCellContext.flowRepEndpointCompletionFailure =
          endpointFailure == nullptr ? std::string{} : endpointFailure->detail;
      if (endpointCompletion.is_rejected()) {
        const auto *failure = endpointFailure;
        if (failure == nullptr) {
          return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                    "strands");
        }
        return fail_surface_cells(
            surface_cell_failure_from_endpoint_completion(failure->kind),
            "strands");
      }
      if (!endpointCompletion.is_produced()) {
        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                  "strands");
      }
      // A produced endpoint-completion product is the sole owner of the dense
      // network consumed by embedding. Rejected outcomes carry no network.
      auto endpointProduct = std::move(endpointCompletion).product();
      flowRepArcs = std::move(endpointProduct.arcs);
      sparseFlowRep.retainedArcIds = std::move(endpointProduct.retainedArcIds);
      sparseFlowRep.endpointTags = std::move(endpointProduct.endpointTags);
    }
    const double surfaceCellStrandsSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - strandsStart)
            .count() /
        1.0e6;
    const std::uint64_t flowRepCurrentOwnedBytes =
        flow_rep_arc_vector_owned_bytes(flowRepArcs) +
        sparse_flow_rep_owned_bytes(sparseFlowRep) +
        endpoint_completion_owned_bytes(endpointCompletion) +
        vector_owned_bytes(
            result.surfaceCellContext.flowRepEndpointDiagnostics) +
        static_cast<std::uint64_t>(
            result.surfaceCellContext.flowRepEndpointCompletionFailure
                .capacity());
    const std::uint64_t flowRepLogicalBytes =
        flow_rep_arc_vector_logical_bytes(flowRepArcs) +
        sparse_flow_rep_logical_bytes(sparseFlowRep) +
        endpoint_completion_logical_bytes(endpointCompletion) +
        vector_logical_bytes(
            result.surfaceCellContext.flowRepEndpointDiagnostics) +
        static_cast<std::uint64_t>(
            result.surfaceCellContext.flowRepEndpointCompletionFailure.size());
    result.surfaceCellContext.flowRepLogicalPayloadBytes = flowRepLogicalBytes;
    result.surfaceCellContext.flowRepRetainedCapacityBytes =
        flowRepCurrentOwnedBytes;
    result.diagnostics.surfaceCellFlowRepLogicalPayloadBytes =
        flowRepLogicalBytes;
    result.diagnostics.surfaceCellFlowRepRetainedCapacityBytes =
        flowRepCurrentOwnedBytes;
    record_memory_ownership("flowrep", "acquire", flowRepLogicalBytes,
                            flowRepCurrentOwnedBytes);
    result.surfaceCellContext.flowRepCurrentOwnedBytes =
        flowRepCurrentOwnedBytes;
    result.surfaceCellContext.flowRepPeakOwnedBytes =
        std::max(result.surfaceCellContext.flowRepPeakOwnedBytes,
                 flowRepCurrentOwnedBytes);
    result.diagnostics.surfaceCellFlowRepCurrentOwnedBytes =
        flowRepCurrentOwnedBytes;
    result.diagnostics.surfaceCellFlowRepPeakOwnedBytes =
        result.surfaceCellContext.flowRepPeakOwnedBytes;
    std::uint64_t strandsHash = hash_sparse_network(sparseFlowRep);
    hash_combine_u64(
        strandsHash,
        hash_flow_rep_selection_input_components(
            flowRepArcs, flowRepInput.coverageSamples, flowRepInput.cycles));
    // Coverage/cycle evidence has now been consumed by selection and hashing.
    // Release it before arrangement and completion allocate their graphs.
    flowRepInput = geometry::FlowRepSelectionInput{};
    record_memory_ownership("flowrep-selection", "release", 0U, 0U);
    result.surfaceCellContext.flowRepSelectionStorageReleasedAfterSelection =
        flowRepInput.arcs.empty() && flowRepInput.coverageSamples.empty() &&
        flowRepInput.cycles.empty();
    result.diagnostics
        .surfaceCellFlowRepSelectionStorageReleasedAfterSelection =
        result.surfaceCellContext
            .flowRepSelectionStorageReleasedAfterSelection;
    const bool flowRepSelectionSucceeded = sparseFlowRep.selectionSucceeded;
    const geometry::FlowRepSelectionFailureCode flowRepFailureCode =
        sparseFlowRep.failureCode;
    const std::size_t retainedFlowRepArcCount =
        sparseFlowRep.retainedArcIds.size();
    if (retainForExecution) {
      // Retained context is diagnostic/debug shadow only. The declared local
      // FlowRep products remain the semantic inputs to embedding.
      result.surfaceCellContext.productSnapshots.flowRepArcs = flowRepArcs;
      result.surfaceCellContext.productSnapshots.flowRepNetwork = sparseFlowRep;
      result.surfaceCellContext.hasFlowRepNetwork = true;
    }
    const SurfaceCellObjectIdentity strandsIdentity = make_identity(
        "strands", strandsHash, retainedFlowRepArcCount);
    mark_stage_consumed("tracing", tracingIdentity,
                        SurfaceCellConsumptionKind::Full);
    record_surface_cell_stage("strands", tracingIdentity, strandsIdentity,
                              flowRepSelectionSucceeded,
                              surfaceCellStrandsSeconds);
    if (!flowRepSelectionSucceeded) {
      return fail_surface_cells(
          surface_cell_failure_from_flow_rep(flowRepFailureCode), "strands");
    }
    completedSurfaceCellStages.push_back("strands");
    if (options.surfaceCells.injectFailureAfterStage == 4) {
      return fail_surface_cells(SurfaceCellFailureCode::InjectedStageFailure,
                                "strands");
    }

    const auto embeddingStart = Clock::now();
    const std::vector<geometry::FlowRepArc> &embeddingFlowRepArcs = flowRepArcs;
    const geometry::FlowRepSparseNetwork &embeddingSparseFlowRep = sparseFlowRep;
    std::vector<geometry::SurfaceArrangementArc> arrangementArcs =
        surface_arrangement_arcs_from_flow_rep(
            embeddingFlowRepArcs, embeddingSparseFlowRep, meshWhole.F,
            retainedSourceAuthority,
            hardFeatureRailEdges.empty() ? nullptr : &hardFeatureRailEdges);
    if (!retainForExecution) {
      // Arrangement arcs are a compact projection of the retained FlowRep.
      // Release the much larger dense arc graph before building the DCEL.
      std::vector<geometry::FlowRepArc>().swap(flowRepArcs);
      sparseFlowRep = geometry::FlowRepSparseNetwork{};
      endpointCompletion = geometry::FlowRepEndpointCompletionResult{};
      result.surfaceCellContext.flowRepRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellFlowRepRetainedCapacityBytes = 0U;
      record_memory_ownership("flowrep", "release", 0U, 0U);
    }
    const double surfaceCellEmbeddingSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - embeddingStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount = arrangementArcs.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    const std::uint64_t arrangementArcOwnedBytes =
        vector_owned_bytes(arrangementArcs);
    const std::uint64_t arrangementArcHash =
        hash_arrangement_arcs(arrangementArcs);
    const std::size_t arrangementArcCount = arrangementArcs.size();
    if (retainForExecution) {
      result.surfaceCellContext.productSnapshots.embeddedArrangementArcs = arrangementArcs;
      result.surfaceCellContext.hasEmbeddedArrangementArcs = true;
    }
    const SurfaceCellObjectIdentity retainedNetworkIdentity = make_identity(
        "embedded-network", arrangementArcHash, arrangementArcCount);
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
    arrangementOptions.useAuthoritativeProposalCycles =
        useAuthoritativePhaseFront;
    arrangementOptions.hardFeatureEdges = hardFeatureRailEdges;
    arrangementOptions.sourceAuthority = retainedSourceAuthority;
    const std::vector<geometry::SurfaceArrangementArc> &arrangementInputArcs =
        arrangementArcs;
    geometry::SurfaceCellComplex arrangementComplex =
        geometry::build_surface_cell_complex(meshWhole.V, meshWhole.F,
                                             arrangementInputArcs,
                                             arrangementOptions);
    if (!retainForExecution) {
      std::vector<geometry::SurfaceArrangementArc>().swap(arrangementArcs);
      result.surfaceCellContext
          .embeddedArrangementStorageReleasedAfterArrangement = true;
      result.diagnostics
          .surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement =
          true;
    }
    result.diagnostics.surfaceCellArrangementSeconds =
        std::chrono::duration_cast<std::chrono::microseconds>(
            Clock::now() - arrangementStart)
            .count() /
        1.0e6;
    result.diagnostics.surfaceCellArrangementCellCount =
        arrangementComplex.cells.size();
    result.diagnostics.surfaceCellArrangementCountAvailable = true;
    const std::uint64_t arrangementOwnedBytes =
        surface_complex_owned_bytes(arrangementComplex);
    const std::uint64_t arrangementLogicalBytes =
        surface_complex_logical_bytes(arrangementComplex);
    const std::uint64_t arrangementCurrentOwnedBytes =
        arrangementOwnedBytes +
        (retainForExecution ? arrangementArcOwnedBytes : 0U);
    result.surfaceCellContext.arrangementLogicalPayloadBytes =
        arrangementLogicalBytes;
    result.surfaceCellContext.arrangementRetainedCapacityBytes =
        arrangementCurrentOwnedBytes;
    result.diagnostics.surfaceCellArrangementLogicalPayloadBytes =
        arrangementLogicalBytes;
    result.diagnostics.surfaceCellArrangementRetainedCapacityBytes =
        arrangementCurrentOwnedBytes;
    record_memory_ownership("arrangement", "acquire",
                            arrangementLogicalBytes,
                            arrangementCurrentOwnedBytes);
    result.surfaceCellContext.arrangementCurrentOwnedBytes =
        arrangementCurrentOwnedBytes;
    result.surfaceCellContext.arrangementPeakOwnedBytes = std::max(
        arrangementComplex.diagnostics.peakMemoryBytes,
        arrangementOwnedBytes + arrangementArcOwnedBytes);
    result.diagnostics.surfaceCellArrangementCurrentOwnedBytes =
        arrangementCurrentOwnedBytes;
    result.diagnostics.surfaceCellArrangementPeakOwnedBytes =
        result.surfaceCellContext.arrangementPeakOwnedBytes;
    const std::uint64_t arrangementHash = hash_surface_complex(arrangementComplex);
    if (retainForExecution) {
      // Retain a debug copy; simplification consumes the local stage product.
      result.surfaceCellContext.productSnapshots.arrangement = arrangementComplex;
      result.surfaceCellContext.hasArrangement = true;
    }
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
    const geometry::SurfaceCellComplex &arrangementForSimplification =
        arrangementComplex;
    geometry::SurfaceSimplificationCandidateSet simplificationCandidates =
        geometry::extract_surface_simplification_candidates(
            arrangementForSimplification, meshWhole.V, meshWhole.F);
    const std::uint64_t simplificationCandidateOwnedBytes =
        simplification_candidates_owned_bytes(simplificationCandidates);
    geometry::SurfaceSimplificationOptions simplificationOptions;
    // The production path currently enables only the independently validated
    // topological repair: trim optional layout-support graph bridges that
    // pinch DCEL face walks. General FlowRep removals remain available to the
    // experimental API but require separate fidelity gates before integration.
    simplificationOptions.topologyHealingOnly = true;
    simplificationOptions.retainTransactionDetails = retainForExecution;
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
    if (retainForExecution) {
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
    if (retainForExecution) {
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
      simplificationCandidates =
          geometry::SurfaceSimplificationCandidateSet{};
    } else {
      simplificationCandidates = geometry::SurfaceSimplificationCandidateSet{};
      simplified.transactions.clear();
      simplified.transactions.shrink_to_fit();
    }
    result.surfaceCellContext.simplificationCommitted = simplified.committed;
    result.surfaceCellContext.simplificationRejected = simplified.rejected;
    result.surfaceCellContext.simplificationGeneratedCandidates =
        simplified.generatedCandidates;
    result.surfaceCellContext.simplificationDeduplicatedCandidates =
        simplified.deduplicatedCandidates;
    result.surfaceCellContext.simplificationInvalidatedCandidates =
        simplified.invalidatedCandidates;
    result.surfaceCellContext.simplificationStaleGenerationCandidates =
        simplified.staleGenerationCandidates;
    result.surfaceCellContext.simplificationFrontierGenerations =
        simplified.frontierGenerations;
    result.surfaceCellContext.simplificationPeakLiveCandidates =
        simplified.peakLiveCandidates;
    result.surfaceCellContext.simplificationEvaluatedCandidates =
        simplified.empiricalWork;
    result.surfaceCellContext.hasSimplificationDiagnostics = true;
    const std::uint64_t simplificationCurrentOwnedBytes =
        simplification_result_owned_bytes(simplified) +
        simplification_candidate_vector_owned_bytes(
            result.surfaceCellContext.simplificationTopologyHealingCandidates) +
        simplification_transaction_vector_owned_bytes(
            result.surfaceCellContext.simplificationTransactions);
    const std::uint64_t simplificationLogicalBytes =
        simplification_result_logical_bytes(simplified) +
        simplification_candidate_vector_logical_bytes(
            result.surfaceCellContext.simplificationTopologyHealingCandidates) +
        simplification_transaction_vector_logical_bytes(
            result.surfaceCellContext.simplificationTransactions);
    result.surfaceCellContext.simplificationLogicalPayloadBytes =
        simplificationLogicalBytes;
    result.surfaceCellContext.simplificationRetainedCapacityBytes =
        simplificationCurrentOwnedBytes;
    result.diagnostics.surfaceCellSimplificationLogicalPayloadBytes =
        simplificationLogicalBytes;
    result.diagnostics.surfaceCellSimplificationRetainedCapacityBytes =
        simplificationCurrentOwnedBytes;
    record_memory_ownership("simplification", "acquire",
                            simplificationLogicalBytes,
                            simplificationCurrentOwnedBytes);
    result.surfaceCellContext.simplificationCurrentOwnedBytes =
        simplificationCurrentOwnedBytes;
    result.surfaceCellContext.simplificationPeakOwnedBytes = std::max(
        simplificationCurrentOwnedBytes,
        arrangementOwnedBytes + simplificationCandidateOwnedBytes);
    result.diagnostics.surfaceCellSimplificationCurrentOwnedBytes =
        simplificationCurrentOwnedBytes;
    result.diagnostics.surfaceCellSimplificationPeakOwnedBytes =
        result.surfaceCellContext.simplificationPeakOwnedBytes;
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
        retainForExecution
            ? simplifiedComplexForHash
            : (simplified.hasComplexOutput
                   ? std::move(simplified.complex)
                   : std::move(arrangementComplex));
    if (!retainForExecution) {
      // If simplification produced a replacement complex, the input
      // arrangement would otherwise remain live for the entire completion
      // stage. Its semantic hash and diagnostics are already recorded.
      arrangementComplex = geometry::SurfaceCellComplex{};
      simplified = geometry::SurfaceSimplificationResult{};
      result.surfaceCellContext.arrangementRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellArrangementRetainedCapacityBytes = 0U;
      record_memory_ownership("arrangement", "release", 0U, 0U);
      result.surfaceCellContext.simplificationRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellSimplificationRetainedCapacityBytes = 0U;
      record_memory_ownership("simplification", "release", 0U, 0U);
    }
    geometry::SurfaceCellComplexCompletionOptions completionOptions;
    completionOptions.descriptorOptions.singularCycles =
        crossFieldProduct.singularCycles;
    completionOptions.descriptorOptions.singularIndices =
        crossFieldProduct.singularIndices;
    completionOptions.sourceAuthority = retainedSourceAuthority;
    completionOptions.sourceHardFeatureEdges = &hardFeatureRailEdges;
    geometry::SurfaceCellComplexCompletionResult completionResult;
    if (useAuthoritativePhaseFront) {
      std::string authoritativeOwnershipFailure;
      if (retainedSourceAuthority == nullptr ||
          !geometry::pure_quad_detail::
              validate_materialized_completion_domain_ownership(
                  authoritativePhaseFrontMesh.mesh, meshWhole.F,
                  retainedSourceAuthority, &hardFeatureRailEdges,
                  authoritativeOwnershipFailure)) {
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion/ownership-authority";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            retainedSourceAuthority == nullptr
                ? "MissingSourceAuthority"
                : authoritativeOwnershipFailure;
        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                  "completion");
      }
      geometry::SurfaceCellComplexCompletionEvidence completionEvidence;
      completionEvidence.attemptedPatches =
          static_cast<int>(authoritativePhaseFrontMesh.mesh.quads.size());
      completionEvidence.failedPatches = 0;
      geometry::SurfaceCellComplexCompletionProduct completionProduct;
      completionProduct.completedPatches = {authoritativePhaseFrontMesh.mesh};
      completionProduct.assembly.success = true;
      completionProduct.assembly.mesh = authoritativePhaseFrontMesh.mesh;
      completionProduct.assembly.connectedComponents =
          authoritativePhaseFrontMesh.connectedComponents;
      completionProduct.assembly.boundaryLoopCount =
          authoritativePhaseFrontMesh.boundaryLoopCount;
      completionProduct.assembly.eulerCharacteristic =
          authoritativePhaseFrontMesh.eulerCharacteristic;
      completionResult = geometry::SurfaceCellComplexCompletionResult::produced(
          std::move(completionEvidence), std::move(completionProduct));
    } else {
      completionResult = geometry::complete_surface_cell_complex(
          std::move(completionComplex), meshWhole.V, meshWhole.F,
          completionOptions);
    }
    result.surfaceCellContext.completionOddCellsBeforeRepair =
        completionResult.parityOddCellsBefore;
    result.surfaceCellContext.completionOddCellsAfterRepair =
        completionResult.parityOddCellsAfter;
    result.surfaceCellContext.completionParitySplitEdges =
        completionResult.paritySplitEdges;
    result.surfaceCellContext.completionParityHardFeatureSplits =
        completionResult.parityHardFeatureSplits;
    result.surfaceCellContext.completionParityAlternativeCandidateBudget =
        completionResult.parityAlternativeCandidateBudget;
    result.surfaceCellContext.completionParityAlternativeCandidatesAttempted =
        completionResult.parityAlternativeCandidatesAttempted;
    result.surfaceCellContext.completionParityAlternativeVisitedStates =
        completionResult.parityAlternativeVisitedStates;
    result.surfaceCellContext.completionParityAlternativeSelectedExclusion =
        completionResult.parityAlternativeSelectedExclusion;
    result.surfaceCellContext.completionParityAlternativeStateSequenceHash =
        completionResult.parityAlternativeStateSequenceHash;
    result.surfaceCellContext.completionParityAlternativeDisposition =
        completionResult.parityAlternativeDisposition;
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
    result.surfaceCellContext.completionSideRollbackEquivalent =
        completionResult.sideRollbackEquivalent;
    result.surfaceCellContext.completionSideRollbackIdentityHashBefore =
        completionResult.sideRollbackIdentityHashBefore;
    result.surfaceCellContext.completionSideRollbackIdentityHashAfter =
        completionResult.sideRollbackIdentityHashAfter;
    result.surfaceCellContext.completionSideRollbackUndoOwnedBytes =
        completionResult.sideRollbackUndoOwnedBytes;
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
    result.surfaceCellContext.completionOwnershipProductCacheHashMisses =
        completionResult.completionOwnershipProductCacheHashMisses;
    result.surfaceCellContext.completionOwnershipProductCacheExactMismatches =
        completionResult.completionOwnershipProductCacheExactMismatches;
    result.surfaceCellContext.completionOwnershipProductCacheMismatchVector =
        completionResult.completionOwnershipProductCacheMismatchVector;
    result.surfaceCellContext.completionParityScopeFailure =
        completionResult.firstParityScopeFailure;
    result.surfaceCellContext.hasCompletionParityScopeFailure =
        completionResult.firstParityScopeFailure.active;
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
    result.surfaceCellContext.completionLogicalPayloadBytes =
        completionResult.completionLogicalPayloadBytes;
    result.surfaceCellContext.completionRetainedCapacityBytes =
        completionResult.completionRetainedCapacityBytes;
    result.diagnostics.surfaceCellCompletionLogicalPayloadBytes =
        completionResult.completionLogicalPayloadBytes;
    result.diagnostics.surfaceCellCompletionRetainedCapacityBytes =
        completionResult.completionRetainedCapacityBytes;
    record_memory_ownership("completion", "acquire",
                            completionResult.completionLogicalPayloadBytes,
                            completionResult.completionRetainedCapacityBytes);
    result.surfaceCellContext.completionOwnershipRepairLog =
        std::move(completionResult.ownershipRepairAttempts);
    result.surfaceCellContext.firstCompletionOwnershipRejection =
        completionResult.firstCompletionOwnershipRejection;
    result.surfaceCellContext.firstCompletionEmbeddingFailure =
        completionResult.firstCompletionEmbeddingFailure;
    const auto *closedCompletionFailure = completionResult.rejection();
    result.surfaceCellContext.completionFailure =
        closedCompletionFailure == nullptr ? std::string{}
                                           : closedCompletionFailure->detail;
    result.surfaceCellContext.completionDomainIdentityAudit =
        completionResult.firstInvalidDomain;
    result.surfaceCellContext.hasCompletionDomainIdentityAudit =
        completionResult.firstInvalidDomain.failure !=
        geometry::SurfaceCellDomainIdentityFailureKind::None;
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
    const geometry::SurfaceCellReplacementScopeFailure &parityScopeFailure =
        completionResult.firstParityScopeFailure;
    if (parityScopeFailure.active) {
      result.diagnostics.surfaceCellCompletionParityScopeFailureAvailable = true;
      result.diagnostics.surfaceCellCompletionParityOriginalCell =
          parityScopeFailure.originalCell;
      result.diagnostics.surfaceCellCompletionParityReplacementCell =
          parityScopeFailure.replacementCell;
      result.diagnostics.surfaceCellCompletionParityHalfedge =
          parityScopeFailure.halfedge;
      result.diagnostics.surfaceCellCompletionParityTwin =
          parityScopeFailure.twin;
      result.diagnostics.surfaceCellCompletionParitySelectedComponent =
          parityScopeFailure.selectedComponent;
      result.diagnostics.surfaceCellCompletionParitySelectedSheet =
          parityScopeFailure.selectedSheet;
      result.diagnostics.surfaceCellCompletionParityAvailableComponents =
          parityScopeFailure.availableComponents;
      result.diagnostics.surfaceCellCompletionParityAvailableSheets =
          parityScopeFailure.availableSheets;
      result.diagnostics.surfaceCellCompletionParityMutationPhase =
          parityScopeFailure.mutationPhase;
    }
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
      result.diagnostics.surfaceCellCompletionOwnershipEntityKind = 0;
      result.diagnostics.surfaceCellCompletionOwnershipSourceVertex = -1;
      result.diagnostics.surfaceCellCompletionOwnershipSourceEdge = {{-1, -1}};
      if (ownershipRejection.sourceSupport.has_value()) {
        if (const auto *vertex =
                std::get_if<authority::SourceVertexSupport>(
                    &ownershipRejection.sourceSupport.value())) {
          result.diagnostics.surfaceCellCompletionOwnershipEntityKind = 3;
          result.diagnostics.surfaceCellCompletionOwnershipSourceVertex =
              static_cast<int>(vertex->vertex.index());
        } else if (const auto *edge =
                       std::get_if<authority::SourceEdgeSupport>(
                           &ownershipRejection.sourceSupport.value())) {
          result.diagnostics.surfaceCellCompletionOwnershipEntityKind = 2;
          result.diagnostics.surfaceCellCompletionOwnershipSourceEdge = {
              {static_cast<int>(edge->edge.first().index()),
               static_cast<int>(edge->edge.second().index())}};
        } else {
          result.diagnostics.surfaceCellCompletionOwnershipEntityKind = 1;
        }
      }
      result.diagnostics.surfaceCellCompletionOwnershipCandidateFaces.clear();
      result.diagnostics.surfaceCellCompletionOwnershipCandidateFaces.reserve(
          ownershipRejection.candidateSupportedFaces.size());
      for (const authority::SourceFaceId sourceFace :
           ownershipRejection.candidateSupportedFaces) {
        result.diagnostics.surfaceCellCompletionOwnershipCandidateFaces.push_back(
            static_cast<int>(sourceFace.index()));
      }
      result.diagnostics.surfaceCellCompletionOwnershipPatchFaces =
          ownershipRejection.patchSourceFaces;
      // Raw component/sheet diagnostics are representation leaves only. The
      // ownership rejection now carries typed source support instead.
      result.diagnostics.surfaceCellCompletionOwnershipComponent = -1;
      result.diagnostics.surfaceCellCompletionOwnershipSheet = -1;
    }
    if (retainForExecution) {
      result.surfaceCellContext.simplifiedComplex = simplifiedComplexForHash;
      result.surfaceCellContext.hasSimplifiedComplex = true;
    }
    if (completionResult.is_rejected()) {
      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                "completion");
    }
    if (!completionResult.is_produced()) {
      return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                "completion");
    }
    auto &completionProduct = completionResult.product();
    completedPatchesProduct = completionProduct.completedPatches;
    if (retainForExecution) {
      if (completionProduct.hasPreparedComplex) {
        result.surfaceCellContext.completionComplex =
            std::move(completionProduct.preparedComplex);
        result.surfaceCellContext.hasCompletionComplex = true;
      }
      result.surfaceCellContext.patchDescriptors =
          std::move(completionProduct.descriptors.descriptors);
      result.surfaceCellContext.completionUnresolvedSingularVertices =
          std::move(completionProduct.descriptors.unresolvedSingularVertices);
      result.surfaceCellContext.hasPatchDescriptors =
          !result.surfaceCellContext.patchDescriptors.empty();
      result.surfaceCellContext.productSnapshots.completedPatches = completedPatchesProduct;
    }

    geometry::PureQuadMesh aggregateLineageMesh;
    const bool completionSucceededForRecovery = true;
    bool completionOnlyReusesSourceTrianglePairBoundaries = false;
    if (useAuthoritativePhaseFront) {
      aggregateLineageMesh = authoritativePhaseFrontMesh.mesh;
      completedPatchesProduct = {aggregateLineageMesh};
      result.surfaceCellContext.productSnapshots.completedPatches = completedPatchesProduct;
    } else {
      aggregateLineageMesh = retainForExecution
          ? completionProduct.assembly.mesh
          : std::move(completionProduct.assembly.mesh);
      completionOnlyReusesSourceTrianglePairBoundaries =
          geometry::output_is_only_paired_source_triangle_boundaries(
              aggregateLineageMesh, meshWhole.F);
    }
    if (!retainForExecution) {
      // Scalar diagnostics and the authoritative assembled mesh have been
      // extracted. Release prepared topology, descriptors, patch completions,
      // and conflict workspaces before output validation/refinalization.
      completionResult = geometry::SurfaceCellComplexCompletionResult{};
      result.surfaceCellContext.completionRetainedCapacityBytes = 0U;
      result.diagnostics.surfaceCellCompletionRetainedCapacityBytes = 0U;
      record_memory_ownership("completion", "release", 0U, 0U);
    }

    // A source-triangle pair may identify a valid source cell, but returning
    // that pair boundary as the final quad is not a remesh. Unless the caller
    // explicitly requested the proof path, prefer deterministic source-grid
    // refinement so the final output has new topology and complete lineage.
    // Pair-boundary-only output is rejected unconditionally by the lineage
    // gate below if recovery is disabled or fails.
    const bool shouldAttemptSourceGridRecovery =
        completionSucceededForRecovery &&
        completionOnlyReusesSourceTrianglePairBoundaries &&
        options.surfaceCells.allowSourceGridRecovery &&
        !options.surfaceCells.rejectPairedSourceTriangleBoundaryOutput;
    if (shouldAttemptSourceGridRecovery) {
      const FieldAlignedSourceQuadRecoveryResult recovery =
          recover_unique_field_aligned_source_quads(
              meshWhole, crossFieldProduct,
              retainedSourceAuthority,
              &hardFeatureRailEdges);
      if (recovery.success) {
        aggregateLineageMesh = recovery.mesh;
        completedPatchesProduct = {recovery.mesh};
        result.surfaceCellContext.productSnapshots.completedPatches = completedPatchesProduct;
        sourceGridRecoveryUsedProduct = true;
        result.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed = true;
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
    result.surfaceCellContext.productSnapshots.outputLineageValidation = lineageValidation;
    result.surfaceCellContext.hasCompletedPatches =
        !completedPatchesProduct.empty();
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
      hash_source_support(completionHash, hashRejection.sourceSupport);
      hash_vector(completionHash, hashRejection.candidateSupportedFaces);
      hash_vector(completionHash, hashRejection.patchSourceFaces);
    }
    const SurfaceCellObjectIdentity completionIdentity = make_identity(
        "completion", completionHash, completedQuadCount);
    mark_stage_consumed("simplification", simplificationIdentity,
                        SurfaceCellConsumptionKind::Full);
    const bool completionAccepted =
        completedQuadCount > 0U && lineageValidation.valid;
    record_surface_cell_stage("completion", simplificationIdentity,
                              completionIdentity, completionAccepted,
                              result.diagnostics.surfaceCellCompletionSeconds);
    if (!completionAccepted) {
      if (completionResult.firstParityScopeFailure.active) {
        const auto &failure = completionResult.firstParityScopeFailure;
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion/parity-repair";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            failure.mutationPhase;
        result.diagnostics.surfaceCellFirstInvalidProducerCell =
            failure.originalCell;
        result.diagnostics.surfaceCellFirstInvalidProducerHalfedge =
            failure.halfedge;
        result.diagnostics.surfaceCellFirstInvalidProducerTwin = failure.twin;
      } else if (completionResult.firstInvalidDomain.failure !=
                 geometry::SurfaceCellDomainIdentityFailureKind::None) {
        const auto &failure = completionResult.firstInvalidDomain;
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion/domain-identity";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            geometry::surface_cell_domain_identity_failure_name(
                failure.failure);
        result.diagnostics.surfaceCellFirstInvalidProducerCell = failure.cellId;
        result.diagnostics.surfaceCellFirstInvalidProducerHalfedge =
            failure.halfedgeId;
        result.diagnostics.surfaceCellFirstInvalidProducerNode = failure.nodeId;
        result.diagnostics.surfaceCellFirstInvalidProducerFace =
            failure.sourceFace;
      } else if (completionResult.firstCompletionOwnershipRejection.active) {
        const auto &failure =
            completionResult.firstCompletionOwnershipRejection;
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion/ownership";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            failure.failure;
        result.diagnostics.surfaceCellFirstInvalidProducerCell =
            failure.sourcePatch;
        result.diagnostics.surfaceCellFirstInvalidProducerVertex =
            failure.localVertex;
        result.diagnostics.surfaceCellFirstInvalidProducerFace =
            failure.storedFace;
        if (failure.sourceSupport.has_value()) {
          if (const auto *edge =
                  std::get_if<authority::SourceEdgeSupport>(
                      &failure.sourceSupport.value())) {
            result.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
                static_cast<int>(edge->edge.first().index());
            result.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
                static_cast<int>(edge->edge.second().index());
          }
        }
      } else if (result.diagnostics.surfaceCellFirstInvalidProducerStage.empty()) {
        // Preserve an earlier typed producer rejection. A generic completion
        // failure, especially one with an empty detail string, is later
        // evidence and must not erase the first authoritative failure.
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion";
        const auto *completionFailure = completionResult.rejection();
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            completionFailure == nullptr || completionFailure->detail.empty()
                ? lineageValidation.failure
                : completionFailure->detail;
      }
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
      constraints.sourceNormals = meshWhole.faceNormals;
      constraints.sourceFieldX = faceAxisX;
      constraints.sourceFieldY = faceAxisY;
      constraints.sourceAuthority = retainedSourceAuthority;
      constraints.sourceHardFeatureEdges = hardFeatureRailEdges;
      constraints.outputQuadSourceFaces.assign(
          static_cast<std::size_t>(completedQuads.rows()), -1);
      constraints.constrainVerticesToProvenanceEntities =
          sourceGridRecoveryUsedProduct ||
          useAuthoritativePhaseFront;
      // PureQuadFaceLineage::sourcePatch is an arrangement patch identity,
      // not a source-triangle row. Leaving these entries unset makes the
      // optimizer derive each quad's exact compatible source chart from its
      // four vertex provenance records instead of projecting onto an unrelated
      // triangle that happens to share the same integer id.
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
      if (sourceGridRecoveryUsedProduct) {
        const double requestedRecoveryTargetSize =
            targetSizeOptions.baseSize * kSourceGridRecoverySubdivisionScale;
        const SourceGridRecoveryTargetSizeResult recoveryTargetSize =
            make_source_grid_recovery_target_size(
                meshWhole.V, meshWhole.F, completedVertices, completedQuads,
                completedProvenance, requestedRecoveryTargetSize,
                options.surfaceCells.maxSourceGridRecoveryTargetRelaxation);
        sourceGridRecoveryTargetSizeProduct = recoveryTargetSize.targetSize;
        hasSourceGridRecoveryTargetSizeProduct =
            recoveryTargetSize.targetSize.size() == meshWhole.V.rows();
        sourceGridRecoveryTargetSizeRelaxedProduct = recoveryTargetSize.relaxed;
        sourceGridRecoveryTargetSizeMaxRelaxationRatioProduct =
            recoveryTargetSize.maxRelaxationRatio;
        result.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize =
            sourceGridRecoveryTargetSizeProduct;
        result.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize =
            hasSourceGridRecoveryTargetSizeProduct;
        result.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeRelaxed =
            sourceGridRecoveryTargetSizeRelaxedProduct;
        result.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeMaxRelaxationRatio =
            sourceGridRecoveryTargetSizeMaxRelaxationRatioProduct;
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
      if (useAuthoritativePhaseFront) {
        project_surface_cell_vertex_chart_authority(
            completedVertexLineage, completedVertices.rows(),
            authoritativeRails.size(), constraints.vertexChartAuthority);
      }
      fill_surface_cell_rail_constraints(authoritativeRails, completedVertices,
                                         completedProvenance, constraints);
      if (useAuthoritativePhaseFront &&
          !project_materialized_hard_feature_rails_from_lineage(
              authoritativeRails, completedQuads, completedVertexLineage,
              constraints)) {
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion/feature-authority";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            "InvalidMaterializedHardFeatureAuthority";
        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                  "completion");
      }
      if ((sourceGridRecoveryUsedProduct ||
           useAuthoritativePhaseFront) &&
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
      if (!geometry::source_optimization_has_complete_authority(constraints)) {
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "optimization/source-authority";
        result.diagnostics.surfaceCellFirstInvalidProducerReason =
            "MissingSourceAuthority";
        return fail_surface_cells(SurfaceCellFailureCode::NotProductionReady,
                                  "optimization");
      }
      geometry::fill_required_singularity_valence_targets(
          meshWhole.V, meshWhole.F,
          crossFieldProduct.singularCycles,
          crossFieldProduct.singularIndices,
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
      geometry::SurfaceOptimizationResult completedCheckpoint;
      completedCheckpoint.vertices = completedVertices;
      completedCheckpoint.quads = completedQuads;
      completedCheckpoint.vertexProvenance = completedProvenance;
      completedCheckpoint.initialEnergy =
          geometry::evaluate_surface_optimization_energy(
              completedVertices, completedQuads, constraints,
              optimizationOptions);
      completedCheckpoint.finalEnergy = completedCheckpoint.initialEnergy;
      const geometry::SurfaceFinalValidationReport completedValidation =
          geometry::validate_source_authoritative_final_surface_mesh(
              completedCheckpoint.vertices, completedCheckpoint.quads,
              constraints, completedCheckpoint, optimizationOptions, 0.0,
              std::numeric_limits<double>::infinity());
      if (!completedValidation.accepted) {
        optimizationProduct = completedCheckpoint;
        validationProduct = completedValidation;
        result.surfaceCellContext.productSnapshots.optimizationResult = completedCheckpoint;
        result.surfaceCellContext.productSnapshots.hasOptimizationResult = true;
        result.surfaceCellContext.productSnapshots.validationResult = completedValidation;
        result.surfaceCellContext.productSnapshots.hasValidationResult = true;
        result.diagnostics.surfaceCellOptimizationIterationCount = 0U;
        result.diagnostics.surfaceCellOptimizationIterationCountAvailable =
            true;
        result.diagnostics.surfaceCellOptimizationSeconds = 0.0;
        result.diagnostics.surfaceCellValidationFailureCountAvailable = true;
        result.diagnostics.surfaceCellValidationFailures =
            surface_cell_validation_failure_count(
                completedValidation,
                optimizationOptions.enforceOptimizerTimeGate);
        result.diagnostics.surfaceCellFirstInvalidProducerStage =
            "completion/output-validation";
        if (!completedValidation.strictValidationIssues.empty()) {
          const validation::MeshValidationIssue &issue =
              completedValidation.strictValidationIssues.front();
          result.diagnostics.surfaceCellFirstInvalidProducerReason =
              validation::mesh_validation_failure_name(issue.code);
          result.diagnostics.surfaceCellFirstInvalidProducerFace = issue.face;
          result.diagnostics.surfaceCellFirstInvalidProducerVertex =
              issue.vertex;
          result.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
              issue.edgeFirst;
          result.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
              issue.edgeSecond;
          if (issue.face >= 0 &&
              issue.face < static_cast<int>(completedQuadLineage.size())) {
            result.diagnostics.surfaceCellFirstInvalidProducerCell =
                completedQuadLineage[static_cast<std::size_t>(issue.face)]
                    .sourcePatch;
          }
        } else if (!completedValidation.authoritativeFeatureRailsPassed) {
          result.diagnostics.surfaceCellFirstInvalidProducerReason =
              "MissingFeatureRail";
          result.diagnostics.surfaceCellFirstInvalidProducerValidationIssue =
              "MissingFeatureRail";
        } else {
          result.diagnostics.surfaceCellFirstInvalidProducerReason =
              "AggregateCompletionValidationFailure";
        }
        return fail_surface_cells(
            SurfaceCellFailureCode::NotProductionReady, "completion");
      }

      geometry::SurfaceOptimizationResult optimization =
          geometry::optimize_source_authoritative_surface_mesh(
              completedVertices, completedQuads, constraints,
              optimizationOptions);
      const auto optimizationEnd = Clock::now();
      const double optimizationSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(
              optimizationEnd - optimizationStart)
              .count() /
          1.0e6;
      const auto validationStart = Clock::now();
      geometry::SurfaceFinalValidationReport validation =
          geometry::validate_source_authoritative_final_surface_mesh(
              optimization.vertices, optimization.quads, constraints,
              optimization, optimizationOptions, optimizationSeconds,
              std::numeric_limits<double>::infinity());
      if (!validation.accepted) {
        geometry::SurfaceOptimizationResult recovered =
            completedCheckpoint;
        recovered.rolledBackToInput = true;
        geometry::SurfaceFinalValidationReport recoveredValidation =
            completedValidation;
        recoveredValidation.optimizerTimeWithinGate = true;
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
      optimizationProduct = optimization;
      result.surfaceCellContext.productSnapshots.optimizationResult = optimization;
      result.surfaceCellContext.productSnapshots.hasOptimizationResult = true;
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
      validationProduct = validation;
      result.surfaceCellContext.productSnapshots.validationResult = validation;
      result.surfaceCellContext.productSnapshots.hasValidationResult = true;
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
        result.vertices = optimization.vertices;
        result.faces = optimization.quads;
        result.degrees = Eigen::VectorXi::Constant(optimization.quads.rows(), 4);
        result.outputVertexProvenance = optimization.vertexProvenance;
        result.outputVertexLineage = completedVertexLineage;
        result.outputQuadLineage = completedQuadLineage;
        result.diagnostics.surfaceCellRemeshOccurred = true;
        result.diagnostics.surfaceCellSourceGridRecoveryUsed =
            sourceGridRecoveryUsedProduct;
        result.diagnostics.surfaceCellOutputOrigin =
            sourceGridRecoveryUsedProduct
                ? SurfaceCellOutputOrigin::SourceGridRecovery
                : SurfaceCellOutputOrigin::CompletedSurfaceCells;
        result.diagnostics.terminalFailureCode = "None";
        result.diagnostics.terminalFailureStage.clear();

        if (componentProducts != nullptr) {
          componentProducts->sourceTopologyRegions = sourceTopologyRegionsProduct;
          componentProducts->fieldTransportAtlas = fieldTransportAtlasProduct;
          componentProducts->fieldAlignedCurveNetwork = fieldAlignedNetworkProduct;
          componentProducts->surfaceCutGraph = surfaceCutGraphProduct;
          componentProducts->globalTopologyPlan = globalTopologyPlanProduct;
          componentProducts->authoritativeRails = authoritativeRails;
          componentProducts->sourceSurfaceLabels = sourceSurfaceLabels;
          componentProducts->completedPatches = completedPatchesProduct;
          componentProducts->sourceGridRecoveryUsed =
              sourceGridRecoveryUsedProduct;
          componentProducts->sourceGridRecoveryTargetSize =
              sourceGridRecoveryTargetSizeProduct;
          componentProducts->hasSourceGridRecoveryTargetSize =
              hasSourceGridRecoveryTargetSizeProduct;
          componentProducts->sourceGridRecoveryTargetSizeRelaxed =
              sourceGridRecoveryTargetSizeRelaxedProduct;
          componentProducts->sourceGridRecoveryTargetSizeMaxRelaxationRatio =
              sourceGridRecoveryTargetSizeMaxRelaxationRatioProduct;
          componentProducts->optimizationResult = optimizationProduct;
          componentProducts->validationResult = validationProduct;
        }

        update_overall_pipeline_time();
        record_face_degree_histogram(result);
        clear_unrequested_intermediate_context();
        return std::move(result).finish_produced(RemeshProductKind::Meshed,
                                                 crossFieldAccepted);
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

    if (validationProduct.has_value() &&
        !validationProduct->strictValidationIssues.empty()) {
      const validation::MeshValidationIssue &issue =
          validationProduct->strictValidationIssues.front();
      result.diagnostics.surfaceCellFirstInvalidProducerStage =
          "optimization/output-validation";
      result.diagnostics.surfaceCellFirstInvalidProducerReason =
          std::string(validation::mesh_validation_failure_name(issue.code));
      result.diagnostics.surfaceCellFirstInvalidProducerFace = issue.face;
      result.diagnostics.surfaceCellFirstInvalidProducerVertex = issue.vertex;
      result.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
          issue.edgeFirst;
      result.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
          issue.edgeSecond;
    } else if (result.diagnostics.surfaceCellFirstInvalidProducerStage.empty()) {
      result.diagnostics.surfaceCellFirstInvalidProducerStage = "validation";
      result.diagnostics.surfaceCellFirstInvalidProducerReason =
          "AggregateValidationFailure";
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
    RemeshResultBuilder result;
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
    return std::move(result).finish_produced(
        RemeshProductKind::IntegrationOnly, true);
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

  RemeshResultBuilder result;
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
  const bool mesherSucceeded =
      mesher(workingMesh, mesherData, result.vertices, result.degrees,
             result.faces);
  diagnostics.mesherTotalSeconds += log_phase("mesher");
  diagnostics.mesher = mesherData.diagnostics;
  diagnostics.overallPipelineSeconds = remesh_elapsed_seconds(pipelineStart);
  diagnostics.overallPipelineTimeAvailable = true;
  result.diagnostics = diagnostics;
  record_face_degree_histogram(result);
  report_progress(options.progress, 100, 100, "Finalizing remesh result");
  if (!mesherSucceeded) {
    RemeshFailure failure;
    failure.kind = RemeshFailureKind::MesherRejected;
    failure.stage = "mesher";
    failure.crossFieldAccepted = true;
    return std::move(result).finish_rejected(std::move(failure));
  }
  return std::move(result).finish_produced(RemeshProductKind::Meshed, true);
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult
remesh_from_raw_cross_field_impl(const TriMesh &meshWhole,
                                 const Eigen::MatrixXd &rawCrossField,
                                 const RemeshOptions &options,
                                 const fields::CrossFieldResult *authoritativeCrossField) {
  return remesh_from_raw_cross_field_impl_with_stage_products(
      meshWhole, rawCrossField, options, authoritativeCrossField, nullptr);
}

namespace {

RemeshResult remesh_surface_cells_from_cross_field_with_stage_products(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const RemeshOptions &options,
    SurfaceCellComponentStageProducts *componentProducts) {
  return remesh_from_raw_cross_field_impl_with_stage_products(
      meshWhole, crossField.rawField, options, &crossField, componentProducts);
}

} // namespace

RemeshResult remesh_surface_cells_from_cross_field_impl(
    const TriMesh &meshWhole, const fields::CrossFieldResult &crossField,
    const RemeshOptions &options) {
  return remesh_surface_cells_from_cross_field_with_stage_products(
      meshWhole, crossField, options, nullptr);
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

  std::map<authority::SourceEdgeTopologyKey, int> sourceEdgeByVertices;
  for (int edge = 0; edge < sourceMesh.EV.rows(); ++edge) {
    sourceEdgeByVertices[surface_cell_source_edge_key(
        sourceMesh.EV(edge, 0), sourceMesh.EV(edge, 1),
        static_cast<std::size_t>(sourceMesh.V.rows()))] = edge;
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
          surface_cell_source_edge_key(
              originalVertex0, originalVertex1,
              static_cast<std::size_t>(sourceMesh.V.rows())));
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
    const std::size_t componentIndex,
    const std::optional<authority::IsolationSheetId> typedGlobalSheet) {
  if (point.face >= 0 &&
      static_cast<std::size_t>(point.face) < component.originalFaces.size()) {
    point.face =
        component.originalFaces[static_cast<std::size_t>(point.face)];
  } else {
    point.face = -1;
  }
  // Component and sheet authority is carried by the remapped typed lineage.
  // SurfacePoint integers are legacy representation payload and stay unset.
  (void)componentIndex;
  (void)typedGlobalSheet;
  point.component = -1;
  point.sheet = -1;
  return point;
}

struct ComponentFeatureOptionRemapPlan {
  std::vector<std::set<std::pair<int, int>>> hardEdgesByComponent;
  std::vector<std::set<std::pair<int, int>>> softEdgesByComponent;
  std::size_t hardRequested = 0U;
  std::size_t hardRemapped = 0U;
  std::size_t hardUnassigned = 0U;
  std::size_t softRequested = 0U;
  std::size_t softRemapped = 0U;
  std::size_t softUnassigned = 0U;
  std::pair<int, int> firstUnassignedHard{-1, -1};
  std::pair<int, int> firstUnassignedSoft{-1, -1};
};

ComponentFeatureOptionRemapPlan make_component_feature_option_remap_plan(
    const std::vector<geometry::FaceComponent> &components,
    const std::set<std::pair<int, int>> &globalHardEdges,
    const std::set<std::pair<int, int>> &globalSoftEdges) {
  ComponentFeatureOptionRemapPlan plan;
  plan.hardEdgesByComponent.resize(components.size());
  plan.softEdgesByComponent.resize(components.size());

  std::vector<std::map<int, int>> localVertexByOriginal(components.size());
  std::vector<std::set<std::pair<int, int>>> localSourceEdges(components.size());
  for (std::size_t componentIndex = 0; componentIndex < components.size();
       ++componentIndex) {
    const geometry::FaceComponent &component = components[componentIndex];
    for (std::size_t localVertex = 0;
         localVertex < component.originalVertices.size(); ++localVertex) {
      localVertexByOriginal[componentIndex].emplace(
          component.originalVertices[localVertex],
          static_cast<int>(localVertex));
    }
    for (int face = 0; face < component.faces.rows(); ++face) {
      for (int corner = 0; corner < component.faces.cols(); ++corner) {
        const int first = component.faces(face, corner);
        const int second =
            component.faces(face, (corner + 1) % component.faces.cols());
        localSourceEdges[componentIndex].emplace(
            std::min(first, second), std::max(first, second));
      }
    }
  }

  const auto remapEdges =
      [&](const std::set<std::pair<int, int>> &globalEdges,
          std::vector<std::set<std::pair<int, int>>> &edgesByComponent,
          std::size_t &requested, std::size_t &remapped,
          std::size_t &unassigned, std::pair<int, int> &firstUnassigned) {
    std::set<std::pair<int, int>> canonicalRequests;
    for (const auto &[first, second] : globalEdges) {
      canonicalRequests.emplace(std::min(first, second),
                                std::max(first, second));
    }
    requested = canonicalRequests.size();
    for (const auto &[globalFirst, globalSecond] : canonicalRequests) {
      std::size_t owner = std::numeric_limits<std::size_t>::max();
      std::pair<int, int> localEdge{-1, -1};
      bool ambiguous = false;
      for (std::size_t componentIndex = 0; componentIndex < components.size();
           ++componentIndex) {
        const auto first =
            localVertexByOriginal[componentIndex].find(globalFirst);
        const auto second =
            localVertexByOriginal[componentIndex].find(globalSecond);
        if (first == localVertexByOriginal[componentIndex].end() ||
            second == localVertexByOriginal[componentIndex].end()) {
          continue;
        }
        const std::pair<int, int> candidate{
            std::min(first->second, second->second),
            std::max(first->second, second->second)};
        if (localSourceEdges[componentIndex].find(candidate) ==
            localSourceEdges[componentIndex].end()) {
          continue;
        }
        if (owner != std::numeric_limits<std::size_t>::max()) {
          ambiguous = true;
          break;
        }
        owner = componentIndex;
        localEdge = candidate;
      }
      if (ambiguous || owner == std::numeric_limits<std::size_t>::max()) {
        ++unassigned;
        if (firstUnassigned.first < 0) {
          firstUnassigned = {globalFirst, globalSecond};
        }
        continue;
      }
      edgesByComponent[owner].insert(localEdge);
      ++remapped;
    }
  };

  remapEdges(globalHardEdges, plan.hardEdgesByComponent, plan.hardRequested,
             plan.hardRemapped, plan.hardUnassigned,
             plan.firstUnassignedHard);
  remapEdges(globalSoftEdges, plan.softEdgesByComponent, plan.softRequested,
             plan.softRemapped, plan.softUnassigned,
             plan.firstUnassignedSoft);
  return plan;
}

void apply_component_feature_option_remap(
    const ComponentFeatureOptionRemapPlan &plan,
    const std::size_t componentIndex, RemeshOptions &options) {
  options.surfaceCells.featureMap.userHardEdges =
      plan.hardEdgesByComponent[componentIndex];
  options.surfaceCells.featureMap.userSoftEdges =
      plan.softEdgesByComponent[componentIndex];
}

void publish_component_feature_option_remap_diagnostics(
    RemeshDiagnostics &diagnostics,
    const ComponentFeatureOptionRemapPlan &plan) {
  diagnostics.surfaceCellUserHardFeatureEdgeRequestedCount =
      plan.hardRequested;
  diagnostics.surfaceCellUserHardFeatureEdgeRemappedCount =
      plan.hardRemapped;
  diagnostics.surfaceCellUserHardFeatureEdgeUnassignedCount =
      plan.hardUnassigned;
  diagnostics.surfaceCellUserSoftFeatureEdgeRequestedCount =
      plan.softRequested;
  diagnostics.surfaceCellUserSoftFeatureEdgeRemappedCount =
      plan.softRemapped;
  diagnostics.surfaceCellUserSoftFeatureEdgeUnassignedCount =
      plan.softUnassigned;
  if (plan.hardUnassigned > 0U) {
    diagnostics.surfaceCellFeatureOptionFirstIssue =
        SurfaceCellFeatureOptionRemapIssue::UnassignedHardEdge;
    diagnostics.surfaceCellFirstUnassignedFeatureEdge = {
        plan.firstUnassignedHard.first, plan.firstUnassignedHard.second};
  } else if (plan.softUnassigned > 0U) {
    diagnostics.surfaceCellFeatureOptionFirstIssue =
        SurfaceCellFeatureOptionRemapIssue::UnassignedSoftEdge;
    diagnostics.surfaceCellFirstUnassignedFeatureEdge = {
        plan.firstUnassignedSoft.first, plan.firstUnassignedSoft.second};
  }
}

} // namespace directional::pipeline

namespace directional::pipeline {

std::optional<ComponentTypedAuthorityRemapDomain>
make_component_typed_authority_remap_domain(
    const geometry::FaceComponent &component,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges,
    const std::size_t topologyRegionBase,
    const std::size_t isolationSheetBase,
    const std::size_t fieldChartBase) {
  const std::size_t localFaceCount =
      static_cast<std::size_t>(component.faces.rows());
  if (component.faces.cols() != 3 || localFaceCount == 0U ||
      component.originalFaces.size() != localFaceCount ||
      !sourceAuthority.matches_source_faces(
          component.faces, component.originalVertices.size())) {
    return std::nullopt;
  }

  geometry::SourceChartTransitionGraph chartGraph(
      component.faces, sourceAuthority, hardFeatureEdges);
  if (!chartGraph.available()) {
    return std::nullopt;
  }

  ComponentTypedAuthorityRemapDomain domain;
  std::vector<authority::TopologyRegionId> localRegions;
  localRegions.reserve(sourceAuthority.regions().size());
  std::vector<authority::IsolationSheetId> localSheets;
  for (const geometry::SurfaceTopologyRegion &region :
       sourceAuthority.regions()) {
    localRegions.push_back(region.id());
    for (const geometry::SourceRegionFaceAuthority &face : region.faces()) {
      localSheets.push_back(face.sheet);
      domain.localRegionSheets.emplace(region.id(), face.sheet);
    }
  }
  std::sort(localRegions.begin(), localRegions.end());
  localRegions.erase(std::unique(localRegions.begin(), localRegions.end()),
                     localRegions.end());
  std::sort(localSheets.begin(), localSheets.end());
  localSheets.erase(std::unique(localSheets.begin(), localSheets.end()),
                    localSheets.end());
  if (localRegions.empty() || localSheets.empty()) {
    return std::nullopt;
  }

  std::vector<authority::FieldChartId> localChartIds;
  localChartIds.reserve(localFaceCount);
  domain.localChartsByFace.reserve(localFaceCount);
  domain.localRegionsByFace.reserve(localFaceCount);
  domain.localSheetsByFace.reserve(localFaceCount);
  for (std::size_t localFace = 0; localFace < localFaceCount; ++localFace) {
    const auto row = authority::SourceFaceId::from_index(localFace,
                                                         localFaceCount);
    if (!row) return std::nullopt;
    const auto chart = chartGraph.chart(static_cast<int>(localFace));
    if (!chart.has_value() ||
        chart->face != sourceAuthority.topology_for_row(row.value())) {
      return std::nullopt;
    }
    domain.localChartsByFace.push_back(chart.value());
    domain.localRegionsByFace.push_back(
        sourceAuthority.region_for_row(row.value()));
    domain.localSheetsByFace.push_back(
        sourceAuthority.sheet_for_row(row.value()));
    localChartIds.push_back(chart->chart);
  }
  std::sort(localChartIds.begin(), localChartIds.end());
  localChartIds.erase(
      std::unique(localChartIds.begin(), localChartIds.end()),
      localChartIds.end());
  if (localChartIds.empty()) return std::nullopt;

  const auto checked_extent = [](const std::size_t base,
                                 const std::size_t count)
      -> std::optional<std::size_t> {
    constexpr std::size_t maxExtent =
        static_cast<std::size_t>(std::numeric_limits<int>::max()) + 1U;
    if (count == 0U || base > maxExtent || count > maxExtent - base) {
      return std::nullopt;
    }
    return base + count;
  };
  const auto regionExtent = checked_extent(topologyRegionBase,
                                           localRegions.size());
  const auto sheetExtent = checked_extent(isolationSheetBase,
                                          localSheets.size());
  const auto chartExtent = checked_extent(fieldChartBase,
                                          localChartIds.size());
  if (!regionExtent.has_value() || !sheetExtent.has_value() ||
      !chartExtent.has_value()) {
    return std::nullopt;
  }

  for (std::size_t index = 0; index < localRegions.size(); ++index) {
    const auto global = authority::TopologyRegionId::from_index(
        topologyRegionBase + index, *regionExtent);
    if (!global ||
        !domain.topologyRegions.emplace(localRegions[index], global.value())
             .second) {
      return std::nullopt;
    }
  }
  for (std::size_t index = 0; index < localSheets.size(); ++index) {
    const auto global = authority::IsolationSheetId::from_index(
        isolationSheetBase + index, *sheetExtent);
    if (!global ||
        !domain.isolationSheets.emplace(localSheets[index], global.value())
             .second) {
      return std::nullopt;
    }
  }
  for (std::size_t index = 0; index < localChartIds.size(); ++index) {
    const auto global = authority::FieldChartId::from_index(
        fieldChartBase + index, *chartExtent);
    if (!global ||
        !domain.fieldCharts.emplace(localChartIds[index], global.value())
             .second) {
      return std::nullopt;
    }
  }
  domain.nextTopologyRegion = *regionExtent;
  domain.nextIsolationSheet = *sheetExtent;
  domain.nextFieldChart = *chartExtent;
  return domain.complete()
             ? std::optional<ComponentTypedAuthorityRemapDomain>(
                   std::move(domain))
             : std::nullopt;
}

bool remap_component_typed_lineage_authority(
    geometry::PureQuadVertexLineage &lineage,
    const geometry::FaceComponent &component,
    const std::size_t globalSourceVertexCount,
    const std::size_t globalSourceFaceCount,
    const ComponentTypedAuthorityRemapDomain &domain) {
  (void)globalSourceFaceCount;
  if (lineage.sourceTopologyRegions.empty() ||
      lineage.sourceIsolationSheets.empty() || lineage.sourceCharts.empty() ||
      !lineage.sourceSupport.has_value() || !domain.complete()) {
    return false;
  }

  for (const authority::TopologyRegionId region :
       lineage.sourceTopologyRegions) {
    if (domain.topologyRegions.find(region) == domain.topologyRegions.end()) {
      return false;
    }
  }
  for (const authority::IsolationSheetId sheet :
       lineage.sourceIsolationSheets) {
    if (domain.isolationSheets.find(sheet) == domain.isolationSheets.end()) {
      return false;
    }
  }
  const auto local_face_for_chart = [&](const geometry::SourceProjectionChart &chart)
      -> std::optional<std::size_t> {
    const auto it = std::find(domain.localChartsByFace.begin(),
                              domain.localChartsByFace.end(), chart);
    return it != domain.localChartsByFace.end()
               ? std::optional<std::size_t>(static_cast<std::size_t>(
                     std::distance(domain.localChartsByFace.begin(), it)))
               : std::nullopt;
  };
  for (const geometry::SourceProjectionChart &chart : lineage.sourceCharts) {
    const auto localFaceValue = local_face_for_chart(chart);
    if (!localFaceValue.has_value() ||
        domain.fieldCharts.find(chart.chart) == domain.fieldCharts.end()) {
      return false;
    }
    const std::size_t localFace = localFaceValue.value();
    const authority::TopologyRegionId expectedRegion =
        domain.localRegionsByFace[localFace];
    const authority::IsolationSheetId expectedSheet =
        domain.localSheetsByFace[localFace];
    if (std::find(lineage.sourceTopologyRegions.begin(),
                  lineage.sourceTopologyRegions.end(), expectedRegion) ==
            lineage.sourceTopologyRegions.end() ||
        std::find(lineage.sourceIsolationSheets.begin(),
                  lineage.sourceIsolationSheets.end(), expectedSheet) ==
            lineage.sourceIsolationSheets.end()) {
      return false;
    }
  }
  const auto region_sheet_owned = [&](const authority::TopologyRegionId region,
                                      const authority::IsolationSheetId sheet) {
    return domain.localRegionSheets.count({region, sheet}) != 0U;
  };
  if (std::any_of(
          lineage.sourceTopologyRegions.begin(),
          lineage.sourceTopologyRegions.end(), [&](const auto region) {
            return std::none_of(lineage.sourceIsolationSheets.begin(),
                                lineage.sourceIsolationSheets.end(),
                                [&](const auto sheet) {
                                  return region_sheet_owned(region, sheet);
                                });
          }) ||
      std::any_of(
          lineage.sourceIsolationSheets.begin(),
          lineage.sourceIsolationSheets.end(), [&](const auto sheet) {
            return std::none_of(lineage.sourceTopologyRegions.begin(),
                                lineage.sourceTopologyRegions.end(),
                                [&](const auto region) {
                                  return region_sheet_owned(region, sheet);
                                });
          })) {
    return false;
  }

  std::map<authority::SourceVertexId, int> localVertexRows;
  std::map<authority::SourceVertexId, authority::SourceVertexId>
      globalVertexByLocal;
  for (std::size_t localRow = 0;
       localRow < component.originalVertices.size(); ++localRow) {
    const auto localVertex = authority::SourceVertexId::from_index(
        localRow, component.originalVertices.size());
    const int globalRow = component.originalVertices[localRow];
    const auto globalVertex = authority::SourceVertexId::from_index(
        globalRow, globalSourceVertexCount);
    if (!localVertex || !globalVertex ||
        !localVertexRows.emplace(localVertex.value(),
                                 static_cast<int>(localRow)).second ||
        !globalVertexByLocal.emplace(localVertex.value(),
                                     globalVertex.value()).second) {
      return false;
    }
  }

  const auto support_has_chart_witness = [&]() {
    const authority::SourceSupport &support = lineage.sourceSupport.value();
    for (const geometry::SourceProjectionChart &chart : lineage.sourceCharts) {
      const auto localFaceValue = local_face_for_chart(chart);
      if (!localFaceValue.has_value()) {
        continue;
      }
      const std::size_t localFace = localFaceValue.value();
      if (localFace >= static_cast<std::size_t>(component.faces.rows())) {
        continue;
      }
      if (const auto *face =
              std::get_if<authority::SourceFaceInteriorSupport>(&support)) {
        if (face->face == chart.face) return true;
      } else if (const auto *vertex =
                     std::get_if<authority::SourceVertexSupport>(&support)) {
        const auto vertexRow = localVertexRows.find(vertex->vertex);
        if (vertexRow == localVertexRows.end()) return false;
        for (int corner = 0; corner < 3; ++corner) {
          if (component.faces(static_cast<Eigen::Index>(localFace), corner) ==
              vertexRow->second) {
            return true;
          }
        }
      } else if (const auto *edge =
                     std::get_if<authority::SourceEdgeSupport>(&support)) {
        const auto firstRow = localVertexRows.find(edge->edge.first());
        const auto secondRow = localVertexRows.find(edge->edge.second());
        if (firstRow == localVertexRows.end() ||
            secondRow == localVertexRows.end()) {
          return false;
        }
        bool firstFound = false;
        bool secondFound = false;
        for (int corner = 0; corner < 3; ++corner) {
          const int sourceVertex =
              component.faces(static_cast<Eigen::Index>(localFace), corner);
          firstFound = firstFound || sourceVertex == firstRow->second;
          secondFound = secondFound || sourceVertex == secondRow->second;
        }
        if (firstFound && secondFound) return true;
      }
    }
    return false;
  };
  if (!support_has_chart_witness()) return false;

  for (authority::TopologyRegionId &region : lineage.sourceTopologyRegions) {
    const auto mapped = domain.topologyRegions.find(region);
    if (mapped == domain.topologyRegions.end()) return false;
    region = mapped->second;
  }
  for (authority::IsolationSheetId &sheet : lineage.sourceIsolationSheets) {
    const auto mapped = domain.isolationSheets.find(sheet);
    if (mapped == domain.isolationSheets.end()) return false;
    sheet = mapped->second;
  }
  const auto remap_vertex = [&](const authority::SourceVertexId local)
      -> std::optional<authority::SourceVertexId> {
    const auto mapped = globalVertexByLocal.find(local);
    return mapped != globalVertexByLocal.end()
               ? std::optional<authority::SourceVertexId>(mapped->second)
               : std::nullopt;
  };
  const auto remap_face_topology =
      [&](const authority::SourceFaceTopologyKey &local)
      -> std::optional<authority::SourceFaceTopologyKey> {
    const auto &localVertices = local.vertices();
    const auto vertex0 = remap_vertex(localVertices[0]);
    const auto vertex1 = remap_vertex(localVertices[1]);
    const auto vertex2 = remap_vertex(localVertices[2]);
    if (!vertex0.has_value() || !vertex1.has_value() ||
        !vertex2.has_value()) {
      return std::nullopt;
    }
    const auto topology = authority::SourceFaceTopologyKey::make(
        {*vertex0, *vertex1, *vertex2});
    return topology
               ? std::optional<authority::SourceFaceTopologyKey>(topology.value())
               : std::nullopt;
  };

  for (geometry::SourceProjectionChart &chart : lineage.sourceCharts) {
    const auto chartId = domain.fieldCharts.find(chart.chart);
    const auto remappedFace = remap_face_topology(chart.face);
    if (chartId == domain.fieldCharts.end() || !remappedFace.has_value()) {
      return false;
    }
    chart = geometry::SourceProjectionChart(chartId->second, *remappedFace);
  }

  std::optional<authority::SourceSupport> remappedSupport;
  if (const auto *vertex = std::get_if<authority::SourceVertexSupport>(
          &lineage.sourceSupport.value())) {
    const auto remapped = remap_vertex(vertex->vertex);
    if (!remapped.has_value()) return false;
    remappedSupport = authority::SourceVertexSupport{*remapped};
  } else if (const auto *edge = std::get_if<authority::SourceEdgeSupport>(
                 &lineage.sourceSupport.value())) {
    const auto first = remap_vertex(edge->edge.first());
    const auto second = remap_vertex(edge->edge.second());
    if (!first.has_value() || !second.has_value()) return false;
    const auto topology =
        authority::SourceEdgeTopologyKey::make(*first, *second);
    if (!topology) return false;
    remappedSupport = authority::SourceEdgeSupport{topology.value()};
  } else if (const auto *face =
                 std::get_if<authority::SourceFaceInteriorSupport>(
                     &lineage.sourceSupport.value())) {
    const auto remapped = remap_face_topology(face->face);
    if (!remapped.has_value()) return false;
    remappedSupport = authority::SourceFaceInteriorSupport{*remapped};
  }
  if (!remappedSupport.has_value()) return false;
  lineage.sourceSupport = std::move(remappedSupport);

  const auto normalize = [](auto &values) {
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
  };
  normalize(lineage.sourceTopologyRegions);
  normalize(lineage.sourceIsolationSheets);
  normalize(lineage.sourceCharts);
  return !lineage.sourceTopologyRegions.empty() &&
         !lineage.sourceIsolationSheets.empty() &&
         !lineage.sourceCharts.empty() && lineage.sourceSupport.has_value();
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
    target.terminalFailureDetailCode = source.terminalFailureDetailCode;
    target.terminalFailureLocus = source.terminalFailureLocus;
  }
  if (source.originalSurfaceCellFailureCode != "None") {
    if (target.originalSurfaceCellFailureCode == "None") {
      target.originalSurfaceCellFailureCode =
          source.originalSurfaceCellFailureCode;
      target.originalSurfaceCellFailureStage =
          source.originalSurfaceCellFailureStage;
      target.originalSurfaceCellFailureDetailCode =
          source.originalSurfaceCellFailureDetailCode;
      target.originalSurfaceCellFailureLocus =
          source.originalSurfaceCellFailureLocus;
    } else if (target.originalSurfaceCellFailureCode !=
                   source.originalSurfaceCellFailureCode ||
               target.originalSurfaceCellFailureStage !=
                   source.originalSurfaceCellFailureStage) {
      target.originalSurfaceCellFailureCode = "Mixed";
      target.originalSurfaceCellFailureStage = "component-aggregation";
      target.originalSurfaceCellFailureDetailCode = "Mixed";
      target.originalSurfaceCellFailureLocus = {};
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
  target.surfaceCellTracingCurrentOwnedBytes +=
      source.surfaceCellTracingCurrentOwnedBytes;
  target.surfaceCellTracingPeakOwnedBytes +=
      source.surfaceCellTracingPeakOwnedBytes;
  target.surfaceCellFlowRepCurrentOwnedBytes +=
      source.surfaceCellFlowRepCurrentOwnedBytes;
  target.surfaceCellFlowRepPeakOwnedBytes +=
      source.surfaceCellFlowRepPeakOwnedBytes;
  target.surfaceCellArrangementCurrentOwnedBytes +=
      source.surfaceCellArrangementCurrentOwnedBytes;
  target.surfaceCellArrangementPeakOwnedBytes +=
      source.surfaceCellArrangementPeakOwnedBytes;
  target.surfaceCellSimplificationCurrentOwnedBytes +=
      source.surfaceCellSimplificationCurrentOwnedBytes;
  target.surfaceCellSimplificationPeakOwnedBytes +=
      source.surfaceCellSimplificationPeakOwnedBytes;
  target.surfaceCellTracingLogicalPayloadBytes +=
      source.surfaceCellTracingLogicalPayloadBytes;
  target.surfaceCellTracingRetainedCapacityBytes +=
      source.surfaceCellTracingRetainedCapacityBytes;
  target.surfaceCellFlowRepLogicalPayloadBytes +=
      source.surfaceCellFlowRepLogicalPayloadBytes;
  target.surfaceCellFlowRepRetainedCapacityBytes +=
      source.surfaceCellFlowRepRetainedCapacityBytes;
  target.surfaceCellArrangementLogicalPayloadBytes +=
      source.surfaceCellArrangementLogicalPayloadBytes;
  target.surfaceCellArrangementRetainedCapacityBytes +=
      source.surfaceCellArrangementRetainedCapacityBytes;
  target.surfaceCellSimplificationLogicalPayloadBytes +=
      source.surfaceCellSimplificationLogicalPayloadBytes;
  target.surfaceCellSimplificationRetainedCapacityBytes +=
      source.surfaceCellSimplificationRetainedCapacityBytes;
  target.surfaceCellCompletionLogicalPayloadBytes +=
      source.surfaceCellCompletionLogicalPayloadBytes;
  target.surfaceCellCompletionRetainedCapacityBytes +=
      source.surfaceCellCompletionRetainedCapacityBytes;
  target.surfaceCellEstimatedPeakSimultaneousOwnedBytes +=
      source.surfaceCellEstimatedPeakSimultaneousOwnedBytes;
  for (SurfaceCellMemoryOwnershipEvent event :
       source.surfaceCellMemoryOwnershipTimeline) {
    if (componentIndex != std::numeric_limits<std::size_t>::max()) {
      event.stage = "component[" + std::to_string(componentIndex) + "]/" +
                    event.stage;
    }
    target.surfaceCellMemoryOwnershipTimeline.push_back(std::move(event));
  }
  target.surfaceCellMaxSimultaneousLiveLargeStructures = std::max(
      target.surfaceCellMaxSimultaneousLiveLargeStructures,
      source.surfaceCellMaxSimultaneousLiveLargeStructures);
  target.surfaceCellTraceStorageReleasedAfterFlowRep =
      firstComponent ? source.surfaceCellTraceStorageReleasedAfterFlowRep
                     : (target.surfaceCellTraceStorageReleasedAfterFlowRep &&
                        source.surfaceCellTraceStorageReleasedAfterFlowRep);
  target.surfaceCellFlowRepSelectionStorageReleasedAfterSelection =
      firstComponent
          ? source.surfaceCellFlowRepSelectionStorageReleasedAfterSelection
          : (target.surfaceCellFlowRepSelectionStorageReleasedAfterSelection &&
             source.surfaceCellFlowRepSelectionStorageReleasedAfterSelection);
  target.surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement =
      firstComponent
          ? source.surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement
          : (target.surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement &&
             source.surfaceCellEmbeddedArrangementStorageReleasedAfterArrangement);

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
  if (source.surfaceCellCompletionParityScopeFailureAvailable &&
      !target.surfaceCellCompletionParityScopeFailureAvailable) {
    target.surfaceCellCompletionParityScopeFailureAvailable = true;
    target.surfaceCellCompletionParityOriginalCell =
        source.surfaceCellCompletionParityOriginalCell;
    target.surfaceCellCompletionParityReplacementCell =
        source.surfaceCellCompletionParityReplacementCell;
    target.surfaceCellCompletionParityHalfedge =
        source.surfaceCellCompletionParityHalfedge;
    target.surfaceCellCompletionParityTwin =
        source.surfaceCellCompletionParityTwin;
    target.surfaceCellCompletionParitySelectedComponent =
        source.surfaceCellCompletionParitySelectedComponent;
    target.surfaceCellCompletionParitySelectedSheet =
        source.surfaceCellCompletionParitySelectedSheet;
    target.surfaceCellCompletionParityAvailableComponents =
        source.surfaceCellCompletionParityAvailableComponents;
    target.surfaceCellCompletionParityAvailableSheets =
        source.surfaceCellCompletionParityAvailableSheets;
    target.surfaceCellCompletionParityMutationPhase =
        source.surfaceCellCompletionParityMutationPhase;
  }
  if (!source.surfaceCellAuthoritativeProducerDisposition.empty() &&
      target.surfaceCellAuthoritativeProducerDisposition.empty()) {
    target.surfaceCellAuthoritativeProducerDisposition =
        source.surfaceCellAuthoritativeProducerDisposition;
  }
  target.surfaceCellTopologyRegionCount += source.surfaceCellTopologyRegionCount;
  target.surfaceCellInternalIsolationSeamCount +=
      source.surfaceCellInternalIsolationSeamCount;
  target.surfaceCellConsumedTopologyRegionCount +=
      source.surfaceCellConsumedTopologyRegionCount;
  target.surfaceCellConsumedInternalIsolationSeamCount +=
      source.surfaceCellConsumedInternalIsolationSeamCount;
  target.surfaceCellConsumedPeriodicHolonomyCount +=
      source.surfaceCellConsumedPeriodicHolonomyCount;
  target.surfaceCellMaterializedConnectedComponentCount +=
      source.surfaceCellMaterializedConnectedComponentCount;
  target.surfaceCellMaterializedBoundaryLoopCount +=
      source.surfaceCellMaterializedBoundaryLoopCount;
  target.surfaceCellMaterializedEulerCharacteristic +=
      source.surfaceCellMaterializedEulerCharacteristic;
  target.surfaceCellTopologyRegionHashes.insert(
      target.surfaceCellTopologyRegionHashes.end(),
      source.surfaceCellTopologyRegionHashes.begin(),
      source.surfaceCellTopologyRegionHashes.end());
  target.surfaceCellTopologyRegionEulerCharacteristics.insert(
      target.surfaceCellTopologyRegionEulerCharacteristics.end(),
      source.surfaceCellTopologyRegionEulerCharacteristics.begin(),
      source.surfaceCellTopologyRegionEulerCharacteristics.end());
  target.surfaceCellTopologyRegionBoundaryLoopCounts.insert(
      target.surfaceCellTopologyRegionBoundaryLoopCounts.end(),
      source.surfaceCellTopologyRegionBoundaryLoopCounts.begin(),
      source.surfaceCellTopologyRegionBoundaryLoopCounts.end());
  target.surfaceCellTopologyRegionIsolationSheetCounts.insert(
      target.surfaceCellTopologyRegionIsolationSheetCounts.end(),
      source.surfaceCellTopologyRegionIsolationSheetCounts.begin(),
      source.surfaceCellTopologyRegionIsolationSheetCounts.end());
  target.surfaceCellBoundedDiskBoundaryPhaseCount +=
      source.surfaceCellBoundedDiskBoundaryPhaseCount;
  target.surfaceCellBoundedDiskBoundaryRunCount +=
      source.surfaceCellBoundedDiskBoundaryRunCount;
  target.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount +=
      source.surfaceCellPolygonalBoundedDiskBoundaryPhaseCount;
  target.surfaceCellBoundedDiskConstructedChartCount +=
      source.surfaceCellBoundedDiskConstructedChartCount;
  target.surfaceCellBoundedDiskBoundaryPhaseHashes.insert(
      target.surfaceCellBoundedDiskBoundaryPhaseHashes.end(),
      source.surfaceCellBoundedDiskBoundaryPhaseHashes.begin(),
      source.surfaceCellBoundedDiskBoundaryPhaseHashes.end());
  if (source.surfaceCellPeriodicHolonomyAvailable) {
    target.surfaceCellPeriodicHolonomies.insert(
        target.surfaceCellPeriodicHolonomies.end(),
        source.surfaceCellPeriodicHolonomies.begin(),
        source.surfaceCellPeriodicHolonomies.end());
    target.surfaceCellPeriodicHolonomyAvailable = true;
    target.surfaceCellPeriodicHolonomyQuarterTurnRotation =
        source.surfaceCellPeriodicHolonomyQuarterTurnRotation;
    target.surfaceCellPeriodicHolonomyTranslationU =
        source.surfaceCellPeriodicHolonomyTranslationU;
    target.surfaceCellPeriodicHolonomyTranslationV =
        source.surfaceCellPeriodicHolonomyTranslationV;
    target.surfaceCellPeriodicHolonomyRouteEdgeCount =
        source.surfaceCellPeriodicHolonomyRouteEdgeCount;
    target.surfaceCellPeriodicCutEdgeCount =
        source.surfaceCellPeriodicCutEdgeCount;
  }
  if (!source.surfaceCellFirstInvalidProducerStage.empty() &&
      target.surfaceCellFirstInvalidProducerStage.empty()) {
    target.surfaceCellFirstInvalidProducerStage =
        source.surfaceCellFirstInvalidProducerStage;
    target.surfaceCellFirstInvalidProducerReason =
        source.surfaceCellFirstInvalidProducerReason;
    target.surfaceCellFirstInvalidProducerValidationIssue =
        source.surfaceCellFirstInvalidProducerValidationIssue;
    target.surfaceCellFirstInvalidProducerCell =
        source.surfaceCellFirstInvalidProducerCell;
    target.surfaceCellFirstInvalidProducerHalfedge =
        source.surfaceCellFirstInvalidProducerHalfedge;
    target.surfaceCellFirstInvalidProducerTwin =
        source.surfaceCellFirstInvalidProducerTwin;
    target.surfaceCellFirstInvalidProducerNode =
        source.surfaceCellFirstInvalidProducerNode;
    target.surfaceCellFirstInvalidProducerFace =
        source.surfaceCellFirstInvalidProducerFace;
    target.surfaceCellFirstInvalidProducerVertex =
        source.surfaceCellFirstInvalidProducerVertex;
    target.surfaceCellFirstInvalidProducerEdgeFirst =
        source.surfaceCellFirstInvalidProducerEdgeFirst;
    target.surfaceCellFirstInvalidProducerEdgeSecond =
        source.surfaceCellFirstInvalidProducerEdgeSecond;
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

namespace {

std::array<geometry::PureQuadStitchIdentity, 4>
canonical_aggregate_quad_cycle(
    const std::array<geometry::PureQuadStitchIdentity, 4> &cycle) {
  std::array<geometry::PureQuadStitchIdentity, 4> best{};
  bool initialized = false;
  for (int start = 0; start < 4; ++start) {
    std::array<geometry::PureQuadStitchIdentity, 4> candidate{};
    for (int offset = 0; offset < 4; ++offset) {
      candidate[static_cast<std::size_t>(offset)] =
          cycle[static_cast<std::size_t>((start + offset) % 4)];
    }
    if (!initialized || candidate < best) {
      best = std::move(candidate);
      initialized = true;
    }
  }
  return best;
}

std::uint64_t aggregate_stitch_cycle_hash(
    const std::array<geometry::PureQuadStitchIdentity, 4> &cycle) {
  std::uint64_t seed = 1469598103934665603ULL;
  for (const geometry::PureQuadStitchIdentity &identity : cycle) {
    seed ^= static_cast<std::uint64_t>(identity.kind);
    seed *= 1099511628211ULL;
    seed ^= identity.canonical.hash();
    seed *= 1099511628211ULL;
  }
  return seed;
}

struct AggregateIdentityRebuildResult {
  const char *failure = nullptr;
  int patch = -1;
  int vertex = -1;
  int face = -1;
  std::size_t boundaryCacheRebuildCount = 0U;

  [[nodiscard]] bool success() const { return failure == nullptr; }
};

AggregateIdentityRebuildResult rebuild_aggregate_output_identity_caches(
    RemeshResultBuilder &result, std::vector<geometry::PureQuadMesh> &completedPatches,
    const Eigen::MatrixXi &sourceFaces,
    const geometry::SourceTopologyRegions &sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges) {
  AggregateIdentityRebuildResult outcome;
  const auto fail = [&](const char *failure, const int patch = -1,
                        const int vertex = -1, const int face = -1) {
    outcome.failure = failure;
    outcome.patch = patch;
    outcome.vertex = vertex;
    outcome.face = face;
    return outcome;
  };

  if (result.outputVertexLineage.size() !=
          static_cast<std::size_t>(result.vertices.rows()) ||
      result.outputQuadLineage.size() !=
          static_cast<std::size_t>(result.faces.rows()) ||
      result.faces.cols() < 4 ||
      completedPatches.empty()) {
    return fail("AggregateIdentityInvalidAggregateExtent");
  }

  using PatchVertexKey = std::pair<int, int>;
  std::map<PatchVertexKey, geometry::PureQuadStitchIdentity>
      canonicalStitchByPatchVertex;

  // Rebuild patch-local identity through the completion-owned canonical
  // constructor first. The pipeline never interprets or preserves a cached
  // stitch kind/schema of its own.
  for (std::size_t patchIndex = 0;
       patchIndex < completedPatches.size();
       ++patchIndex) {
    geometry::PureQuadMesh &patch =
        completedPatches[patchIndex];
    if (patch.sourcePatch < 0 ||
        patch.vertexLineage.size() != patch.vertices.size() ||
        patch.vertexProvenance.size() != patch.vertices.size() ||
        patch.quadLineage.size() != patch.quads.size()) {
      return fail("AggregateIdentityInvalidPatchMetadata",
                  static_cast<int>(patchIndex));
    }
    std::map<int, std::size_t> lineageByLocalVertex;
    for (std::size_t row = 0; row < patch.vertexLineage.size(); ++row) {
      geometry::PureQuadVertexLineage &lineage = patch.vertexLineage[row];
      if (lineage.sourcePatch != patch.sourcePatch || lineage.localVertex < 0 ||
          !lineageByLocalVertex.emplace(lineage.localVertex, row).second) {
        return fail("AggregateIdentityInvalidPatchVertexLineage",
                    static_cast<int>(patchIndex), lineage.localVertex);
      }
      const geometry::PureQuadStitchIdentity stitch =
          geometry::pure_quad_detail::canonical_lineage_stitch_identity(
              patch, static_cast<int>(row));
      if (!stitch.valid()) {
        return fail("AggregateIdentityInvalidPatchStitchIdentity",
                    static_cast<int>(patchIndex), lineage.localVertex);
      }
      lineage.stitchIdentity = stitch;
      lineage.authoritativeIdentity =
          geometry::pure_quad_detail::canonical_authoritative_identity(
              lineage, sourceFaces, sourceAuthority, sourceHardFeatureEdges);
      if (!lineage.authoritativeIdentity.valid()) {
        return fail("AggregateIdentityInvalidPatchSourceAuthority",
                    static_cast<int>(patchIndex), lineage.localVertex);
      }
      if (!canonicalStitchByPatchVertex
               .emplace(PatchVertexKey{lineage.sourcePatch,
                                       lineage.localVertex},
                        lineage.stitchIdentity)
               .second) {
        return fail("AggregateIdentityInvalidPatchVertexLineage",
                    static_cast<int>(patchIndex), lineage.localVertex);
      }
      patch.vertexProvenance[row] = lineage.sourcePoint;
    }

    // boundaryNodeIdentities is a derived cache. Authoritative phase-front
    // materialization intentionally does not populate it, and stale component
    // caches are not global authority. Reinitialize the cache from the
    // remapped completion-owned lineages instead of requiring a preexisting
    // local cache with the final extent.
    if (patch.boundaryNodeIdentities.size() != patch.boundaryVertices.size()) {
      ++outcome.boundaryCacheRebuildCount;
    }
    patch.boundaryNodeIdentities.assign(patch.boundaryVertices.size(), {});
    for (std::size_t boundary = 0; boundary < patch.boundaryVertices.size();
         ++boundary) {
      const auto row =
          lineageByLocalVertex.find(patch.boundaryVertices[boundary]);
      if (row == lineageByLocalVertex.end()) {
        return fail("AggregateIdentityInvalidPatchBoundaryVertex",
                    static_cast<int>(patchIndex),
                    patch.boundaryVertices[boundary]);
      }
      patch.boundaryNodeIdentities[boundary] =
          patch.vertexLineage[row->second].stitchIdentity.canonical;
    }

    for (std::size_t quad = 0; quad < patch.quads.size(); ++quad) {
      if (patch.quads[quad].size() != 4) {
        return fail("AggregateIdentityInvalidPatchQuad",
                    static_cast<int>(patchIndex), -1,
                    static_cast<int>(quad));
      }
      std::array<geometry::PureQuadStitchIdentity, 4> stitchCycle{};
      std::array<geometry::PureQuadStitchIdentity, 4> authoritativeCycle{};
      for (int corner = 0; corner < 4; ++corner) {
        const auto row = lineageByLocalVertex.find(
            patch.quads[quad][static_cast<std::size_t>(corner)]);
        if (row == lineageByLocalVertex.end()) {
          return fail("AggregateIdentityInvalidPatchQuadVertex",
                      static_cast<int>(patchIndex),
                      patch.quads[quad][static_cast<std::size_t>(corner)],
                      static_cast<int>(quad));
        }
        const geometry::PureQuadVertexLineage &lineage =
            patch.vertexLineage[row->second];
        stitchCycle[static_cast<std::size_t>(corner)] = lineage.stitchIdentity;
        authoritativeCycle[static_cast<std::size_t>(corner)] =
            lineage.authoritativeIdentity;
      }
      patch.quadLineage[quad].canonicalStitchCycleHash =
          aggregate_stitch_cycle_hash(
              canonical_aggregate_quad_cycle(stitchCycle));
      patch.quadLineage[quad].canonicalAuthoritativeCycleHash =
          aggregate_stitch_cycle_hash(
              canonical_aggregate_quad_cycle(authoritativeCycle));
    }
  }

  std::vector<int> lineageByOutputVertex(
      static_cast<std::size_t>(result.vertices.rows()), -1);
  for (std::size_t row = 0; row < result.outputVertexLineage.size(); ++row) {
    geometry::PureQuadVertexLineage &lineage = result.outputVertexLineage[row];
    if (lineage.outputVertex < 0 || lineage.outputVertex >= result.vertices.rows() ||
        lineage.sourcePatch < 0 || lineage.localVertex < 0 ||
        lineageByOutputVertex[static_cast<std::size_t>(lineage.outputVertex)] >= 0) {
      return fail("AggregateIdentityInvalidOutputVertexLineage",
                  lineage.sourcePatch, lineage.outputVertex);
    }
    const auto canonical = canonicalStitchByPatchVertex.find(
        PatchVertexKey{lineage.sourcePatch, lineage.localVertex});
    if (canonical == canonicalStitchByPatchVertex.end()) {
      return fail("AggregateIdentityMissingOutputPatchVertex",
                  lineage.sourcePatch, lineage.localVertex);
    }
    lineage.stitchIdentity = canonical->second;
    lineage.authoritativeIdentity =
        geometry::pure_quad_detail::canonical_authoritative_identity(
            lineage, sourceFaces, sourceAuthority, sourceHardFeatureEdges);
    if (!lineage.authoritativeIdentity.valid()) {
      return fail("AggregateIdentityInvalidOutputSourceAuthority",
                  lineage.sourcePatch, lineage.outputVertex);
    }
    lineageByOutputVertex[static_cast<std::size_t>(lineage.outputVertex)] =
        static_cast<int>(row);
  }

  std::vector<int> lineageByOutputQuad(
      static_cast<std::size_t>(result.faces.rows()), -1);
  for (std::size_t row = 0; row < result.outputQuadLineage.size(); ++row) {
    const int outputQuad = result.outputQuadLineage[row].outputQuad;
    if (outputQuad < 0 || outputQuad >= result.faces.rows() ||
        lineageByOutputQuad[static_cast<std::size_t>(outputQuad)] >= 0) {
      return fail("AggregateIdentityInvalidOutputQuadLineage",
                  -1, -1, outputQuad);
    }
    lineageByOutputQuad[static_cast<std::size_t>(outputQuad)] =
        static_cast<int>(row);
  }

  for (int face = 0; face < result.faces.rows(); ++face) {
    if ((result.degrees.size() == result.faces.rows() &&
         result.degrees(face) != 4) ||
        lineageByOutputQuad[static_cast<std::size_t>(face)] < 0) {
      return fail("AggregateIdentityInvalidOutputQuad",
                  -1, -1, face);
    }
    std::array<geometry::PureQuadStitchIdentity, 4> stitchCycle{};
    std::array<geometry::PureQuadStitchIdentity, 4> authoritativeCycle{};
    for (int corner = 0; corner < 4; ++corner) {
      const int outputVertex = result.faces(face, corner);
      if (outputVertex < 0 || outputVertex >= result.vertices.rows()) {
        return fail("AggregateIdentityInvalidOutputVertex",
                    -1, outputVertex, face);
      }
      const int lineageRow =
          lineageByOutputVertex[static_cast<std::size_t>(outputVertex)];
      if (lineageRow < 0) {
        return fail("AggregateIdentityMissingOutputVertexLineage",
                    -1, outputVertex, face);
      }
      const geometry::PureQuadVertexLineage &lineage =
          result.outputVertexLineage[static_cast<std::size_t>(lineageRow)];
      stitchCycle[static_cast<std::size_t>(corner)] = lineage.stitchIdentity;
      authoritativeCycle[static_cast<std::size_t>(corner)] =
          lineage.authoritativeIdentity;
    }
    geometry::PureQuadFaceLineage &lineage =
        result.outputQuadLineage[static_cast<std::size_t>(
            lineageByOutputQuad[static_cast<std::size_t>(face)])];
    lineage.canonicalStitchCycleHash = aggregate_stitch_cycle_hash(
        canonical_aggregate_quad_cycle(stitchCycle));
    lineage.canonicalAuthoritativeCycleHash = aggregate_stitch_cycle_hash(
        canonical_aggregate_quad_cycle(authoritativeCycle));
  }
  return outcome;
}

} // namespace

RemeshResult remesh_surface_cell_components_from_cross_field_aggregate_impl(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options,
    const remesh_pipeline_detail::ComponentAggregationInputMutator
        *beforeAggregation,
    const remesh_pipeline_detail::FinalAggregateValidationAuthorityMutator
        *beforeFinalValidation) {
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

  const ComponentFeatureOptionRemapPlan featureOptionRemap =
      make_component_feature_option_remap_plan(
          components, options.surfaceCells.featureMap.userHardEdges,
          options.surfaceCells.featureMap.userSoftEdges);
  if (featureOptionRemap.hardUnassigned > 0U) {
    RemeshResultBuilder rejected;
    rejected.diagnostics.remeshBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    rejected.diagnostics.requestedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    rejected.diagnostics.executedBackend =
        remesh_backend_name(RemeshBackend::SurfaceCells);
    rejected.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    rejected.diagnostics.componentSplitSeconds = splitSeconds;
    rejected.diagnostics.componentCount = components.size();
    publish_component_feature_option_remap_diagnostics(
        rejected.diagnostics, featureOptionRemap);
    rejected.diagnostics.terminalFailureCode =
        surface_cell_failure_code_name(SurfaceCellFailureCode::NotProductionReady);
    rejected.diagnostics.terminalFailureStage = "component-feature-remap";
    rejected.diagnostics.surfaceCellFirstInvalidProducerStage =
        "component-feature-remap";
    rejected.diagnostics.surfaceCellFirstInvalidProducerReason =
        "UnassignedUserHardFeatureEdge";
    rejected.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
        featureOptionRemap.firstUnassignedHard.first;
    rejected.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
        featureOptionRemap.firstUnassignedHard.second;
    set_overall_pipeline_time(rejected, pipelineStart);
    RemeshFailure failure;
    failure.kind = RemeshFailureKind::SurfaceCellRejected;
    failure.surfaceCellFailure = SurfaceCellFailureCode::NotProductionReady;
    failure.stage = "component-feature-remap";
    failure.crossFieldAccepted = true;
    return std::move(rejected).finish_rejected(std::move(failure));
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

  struct ComponentFinalValidationAuthority {
    bool available = false;
    std::vector<geometry::SurfaceCellRail> authoritativeRails;
    std::vector<geometry::PureQuadVertexLineage> vertexLineage;
    std::vector<int> outputQuadSourceFaces;
    std::set<std::pair<int, int>> authoritativeBoundaryEdges;
    std::vector<std::vector<int>> authoritativeBoundaryLoops;
    std::vector<std::vector<int>> authoritativeFeatureRails;
    std::size_t expectedFeatureRailCount = 0U;
    bool featureRailAuthorityProvided = false;
  };

  struct ComponentRun {
    RemeshResult result;
    SurfaceCellComponentStageProducts stageProducts;
    ComponentFinalValidationAuthority finalValidationAuthority;
    double wallSeconds = 0.0;
  };

  const auto captureFinalValidationAuthority =
      [&](const geometry::FaceComponent &component, ComponentRun &run) {
        if (!run.result.is_produced() ||
            !run.stageProducts.sourceTopologyRegions.has_value() ||
            !run.stageProducts.sourceTopologyRegions->matches_source_faces(
                component.faces, component.originalVertices.size())) {
          return;
        }
        const RemeshProduct &componentProduct = run.result.product();
        if (componentProduct.outputVertexProvenance.size() !=
                static_cast<std::size_t>(componentProduct.vertices.rows()) ||
            componentProduct.outputVertexLineage.size() !=
                static_cast<std::size_t>(componentProduct.vertices.rows())) {
          return;
        }

        geometry::SurfaceOptimizationConstraints constraints;
        constraints.sourceVertices = component.vertices;
        constraints.sourceFaces = component.faces;
        constraints.sourceAuthority =
            &run.stageProducts.sourceTopologyRegions.value();
        constraints.sourceHardFeatureEdges = hard_feature_edge_keys_from_rails(
            run.stageProducts.authoritativeRails,
            component.originalVertices.size());
        constraints.vertexProvenance = componentProduct.outputVertexProvenance;
        constraints.outputQuadSourceFaces.assign(
            static_cast<std::size_t>(componentProduct.faces.rows()), -1);
        const bool chartAuthorityComplete =
            project_surface_cell_vertex_chart_authority(
                componentProduct.outputVertexLineage, componentProduct.vertices.rows(),
                run.stageProducts.authoritativeRails.size(),
                constraints.vertexChartAuthority);
        fill_surface_cell_rail_constraints(
            run.stageProducts.authoritativeRails,
            componentProduct.vertices, componentProduct.outputVertexProvenance, constraints);
        if (has_materialized_phase_front_lineage(
                componentProduct.outputVertexLineage) &&
            !project_materialized_hard_feature_rails_from_lineage(
                run.stageProducts.authoritativeRails,
                componentProduct.faces, componentProduct.outputVertexLineage,
                constraints)) {
          return;
        }

        // The component strict path may replace rail-derived boundary loops with
        // the completion-owned aggregate mesh loops. Preserve that authority
        // before the counterfactual aggregation seam can mutate component data.
        if (run.stageProducts.completedPatches.size() == 1U) {
          const geometry::PureQuadMesh &completed =
              run.stageProducts.completedPatches.front();
          if (!completed.boundaryLoops.empty() &&
              completed.vertexPositions.rows() == componentProduct.vertices.rows() &&
              completed.quads.size() ==
                  static_cast<std::size_t>(componentProduct.faces.rows())) {
            constraints.authoritativeBoundaryEdges.clear();
            constraints.authoritativeBoundaryLoops = completed.boundaryLoops;
            constraints.authoritativeBoundaryLoop =
                constraints.authoritativeBoundaryLoops.front();
            for (const std::vector<int> &loop :
                 constraints.authoritativeBoundaryLoops) {
              for (std::size_t edge = 0; edge < loop.size(); ++edge) {
                constraints.authoritativeBoundaryEdges.insert(std::minmax(
                    loop[edge], loop[(edge + 1U) % loop.size()]));
              }
            }
          }
        }

        if (!chartAuthorityComplete ||
            !geometry::source_optimization_has_complete_authority(constraints)) {
          return;
        }
        ComponentFinalValidationAuthority &authority =
            run.finalValidationAuthority;
        authority.authoritativeRails =
            run.stageProducts.authoritativeRails;
        authority.vertexLineage = componentProduct.outputVertexLineage;
        authority.outputQuadSourceFaces = constraints.outputQuadSourceFaces;
        authority.authoritativeBoundaryEdges =
            constraints.authoritativeBoundaryEdges;
        authority.authoritativeBoundaryLoops =
            constraints.authoritativeBoundaryLoops;
        authority.authoritativeFeatureRails =
            constraints.authoritativeFeatureRails;
        authority.expectedFeatureRailCount =
            constraints.requiredFeatureRailCount;
        authority.featureRailAuthorityProvided =
            constraints.featureRailAuthorityProvided;
        authority.available = true;
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
      apply_component_feature_option_remap(featureOptionRemap, componentIndex,
                                           componentOptions);
      if (componentOptions.surfaceCells.injectFailureComponentIndex >= 0 &&
          componentOptions.surfaceCells.injectFailureComponentIndex !=
              static_cast<int>(componentIndex)) {
        componentOptions.surfaceCells.injectFailureAfterStage = -1;
      }

      run.result = remesh_surface_cells_from_cross_field_with_stage_products(
          componentMesh, componentCrossField, componentOptions,
          &run.stageProducts);
      captureFinalValidationAuthority(component, run);
    } catch (const std::exception &) {
      RemeshResultBuilder rejected;
      rejected.diagnostics.remeshBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      rejected.diagnostics.requestedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      rejected.diagnostics.executedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      rejected.diagnostics.surfaceCellFallbackPolicy =
          surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
      rejected.diagnostics.terminalFailureCode =
          surface_cell_failure_code_name(SurfaceCellFailureCode::UnsupportedInput);
      rejected.diagnostics.terminalFailureStage = "component-execution";
      rejected.diagnostics.originalSurfaceCellFailureCode =
          rejected.diagnostics.terminalFailureCode;
      rejected.diagnostics.originalSurfaceCellFailureStage =
          rejected.diagnostics.terminalFailureStage;
      rejected.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
      rejected.diagnostics.surfaceCellRemeshOccurred = false;
      set_overall_pipeline_time(rejected, componentStart);
      RemeshFailure failure;
      failure.kind = RemeshFailureKind::Exception;
      failure.surfaceCellFailure = SurfaceCellFailureCode::UnsupportedInput;
      failure.stage = "component-execution";
      failure.crossFieldAccepted = false;
      run.result = std::move(rejected).finish_rejected(std::move(failure));
    } catch (...) {
      RemeshResultBuilder rejected;
      rejected.diagnostics.remeshBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      rejected.diagnostics.requestedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      rejected.diagnostics.executedBackend =
          remesh_backend_name(RemeshBackend::SurfaceCells);
      rejected.diagnostics.surfaceCellFallbackPolicy =
          surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
      rejected.diagnostics.terminalFailureCode =
          surface_cell_failure_code_name(SurfaceCellFailureCode::UnsupportedInput);
      rejected.diagnostics.terminalFailureStage = "component-execution";
      rejected.diagnostics.originalSurfaceCellFailureCode =
          rejected.diagnostics.terminalFailureCode;
      rejected.diagnostics.originalSurfaceCellFailureStage =
          rejected.diagnostics.terminalFailureStage;
      rejected.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
      rejected.diagnostics.surfaceCellRemeshOccurred = false;
      set_overall_pipeline_time(rejected, componentStart);
      RemeshFailure failure;
      failure.kind = RemeshFailureKind::Exception;
      failure.surfaceCellFailure = SurfaceCellFailureCode::UnsupportedInput;
      failure.stage = "component-execution";
      failure.crossFieldAccepted = false;
      run.result = std::move(rejected).finish_rejected(std::move(failure));
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

  if (beforeAggregation != nullptr) {
    for (std::size_t index = 0; index < runs.size(); ++index) {
      (*beforeAggregation)(index, runs[index].result,
                           runs[index].stageProducts);
    }
  }

  const auto mergeStart = Clock::now();
  RemeshResultBuilder merged;
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
  publish_component_feature_option_remap_diagnostics(
      merged.diagnostics, featureOptionRemap);

  const auto finish_aggregate_rejection =
      [&](RemeshResultBuilder &builder, const std::string &stage) {
        RemeshFailure failure;
        failure.kind = RemeshFailureKind::ComponentRejected;
        failure.surfaceCellFailure = SurfaceCellFailureCode::NotProductionReady;
        failure.stage = stage;
        failure.crossFieldAccepted = true;
        return std::move(builder).finish_rejected(std::move(failure));
      };

  std::size_t failedComponent = std::numeric_limits<std::size_t>::max();
  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    const RemeshResult &componentResult = runs[index].result;

    ComponentRemeshDiagnostics componentDiagnostics;
    componentDiagnostics.componentIndex = index;
    componentDiagnostics.minimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    componentDiagnostics.inputFaceCount = component.originalFaces.size();
    const RemeshProduct *componentProduct =
        componentResult.is_produced() ? &componentResult.product() : nullptr;
    componentDiagnostics.outputVertexCount =
        componentProduct == nullptr
            ? 0U
            : static_cast<std::size_t>(componentProduct->vertices.rows());
    componentDiagnostics.outputFaceCount =
        componentProduct == nullptr
            ? 0U
            : static_cast<std::size_t>(componentProduct->faces.rows());
    componentDiagnostics.success = componentResult.is_produced();
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
    if (componentResult.is_rejected() &&
        failedComponent == std::numeric_limits<std::size_t>::max()) {
      failedComponent = index;
    }
  }

  if (failedComponent != std::numeric_limits<std::size_t>::max()) {
    const geometry::FaceComponent &component = components[failedComponent];
    const RemeshResult &failure = runs[failedComponent].result;
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
    merged.surfaceCellContext = SurfaceCellPipelineContext{};
    merged.diagnostics.failedComponentIndex = failedComponent;
    merged.diagnostics.failedComponentMinimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    merged.diagnostics.terminalFailureCode =
        failure.diagnostics.terminalFailureCode;
    merged.diagnostics.terminalFailureStage =
        failure.diagnostics.terminalFailureStage;
    merged.diagnostics.terminalFailureDetailCode =
        failure.diagnostics.terminalFailureDetailCode;
    merged.diagnostics.terminalFailureLocus =
        failure.diagnostics.terminalFailureLocus;
    merged.diagnostics.surfaceCellFirstInvalidProducerStage =
        failure.diagnostics.surfaceCellFirstInvalidProducerStage;
    merged.diagnostics.surfaceCellFirstInvalidProducerReason =
        failure.diagnostics.surfaceCellFirstInvalidProducerReason;
    merged.diagnostics.surfaceCellFirstInvalidProducerValidationIssue =
        failure.diagnostics.surfaceCellFirstInvalidProducerValidationIssue;
    merged.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues =
        failure.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues;
    merged.diagnostics.surfaceCellFirstInvalidProducerCell =
        failure.diagnostics.surfaceCellFirstInvalidProducerCell;
    merged.diagnostics.surfaceCellFirstInvalidProducerHalfedge =
        failure.diagnostics.surfaceCellFirstInvalidProducerHalfedge;
    merged.diagnostics.surfaceCellFirstInvalidProducerTwin =
        failure.diagnostics.surfaceCellFirstInvalidProducerTwin;
    merged.diagnostics.surfaceCellFirstInvalidProducerNode =
        failure.diagnostics.surfaceCellFirstInvalidProducerNode;
    merged.diagnostics.surfaceCellFirstInvalidProducerFace =
        failure.diagnostics.surfaceCellFirstInvalidProducerFace;
    merged.diagnostics.surfaceCellFirstInvalidProducerVertex =
        failure.diagnostics.surfaceCellFirstInvalidProducerVertex;
    merged.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
        failure.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst;
    merged.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
        failure.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond;
    merged.diagnostics.surfaceCellUniformPhaseFrontProducerDeclined =
        failure.diagnostics.surfaceCellUniformPhaseFrontProducerDeclined;
    merged.diagnostics.surfaceCellPeriodicPhaseFrontProducerDeclined =
        failure.diagnostics.surfaceCellPeriodicPhaseFrontProducerDeclined;
    merged.diagnostics.surfaceCellBoundedDiskPhaseFrontProducerDeclined =
        failure.diagnostics.surfaceCellBoundedDiskPhaseFrontProducerDeclined;
    merged.diagnostics.surfaceCellOutputOrigin =
        SurfaceCellOutputOrigin::None;
    merged.diagnostics.surfaceCellRemeshOccurred = false;
    merged.diagnostics.componentMergeSeconds =
        remesh_elapsed_seconds(mergeStart);
    set_overall_pipeline_time(merged, pipelineStart);
    return finish_aggregate_rejection(merged, "component-aggregation");
  }

  // Semantic aggregation is transactional.  The diagnostics-only `merged`
  // shell remains the rollback result until every component remap, global
  // source-authority reconstruction, derived-identity rebuild, and final
  // merged-product validation has succeeded.
  RemeshResultBuilder staged = merged;

  staged.rawCrossField = sourceCrossField.rawField;
  staged.crossFieldMatching = sourceCrossField.matching;
  staged.crossFieldEffort = sourceCrossField.effort;
  staged.crossFieldSingularCycles = sourceCrossField.singularCycles;
  staged.crossFieldSingularIndices = sourceCrossField.singularIndices;
  staged.surfaceCellContext.sourceMesh = sourceMesh;
  staged.surfaceCellContext.hasSourceMesh = true;
  staged.surfaceCellContext.productSnapshots.crossField = sourceCrossField;
  staged.surfaceCellContext.productSnapshots.hasCrossField = true;
  staged.surfaceCellContext.crossFieldHasMatching =
      sourceCrossField.matchingComputed;
  staged.surfaceCellContext.crossFieldHasSingularities =
      sourceCrossField.singularitiesComputed;

  std::size_t nextIsolationSheet = 0U;
  int patchOffset = 0;
  std::size_t railOffset = 0U;
  int curveOffset = 0;
  std::size_t nextTopologyRegion = 0U;
  std::size_t nextFieldChart = 0U;
  int frontEdgeOffset = 0;
  std::size_t periodicRelationOffset = 0U;
  std::size_t occurrenceOffset = 0U;
  std::size_t quotientClassOffset = 0U;
  bool allHaveSourceLabels = true;
  bool allHaveAuthoritativeRails = true;
  staged.surfaceCellContext.productSnapshots.sourceSurfaceLabels.componentByFace.assign(
      static_cast<std::size_t>(faces.rows()), -1);
  staged.surfaceCellContext.productSnapshots.sourceSurfaceLabels.localSheetByFace.assign(
      static_cast<std::size_t>(faces.rows()), -1);
  const auto globalSourceEdgeFaces =
      geometry::surface_cell_tracing_detail::edge_faces(faces);
  const auto globalSourceMatchingIndices =
      geometry::surface_cell_tracing_detail::edge_matching_indices(
          globalSourceEdgeFaces);
  std::map<authority::SourceEdgeTopologyKey, authority::InteriorTransitionId>
      globalTransitionByTopology;
  bool globalTransitionAuthorityValid = true;
  for (const auto &[topology, transitionRow] : globalSourceMatchingIndices) {
    const auto transition = authority::InteriorTransitionId::from_index(
        transitionRow, globalSourceMatchingIndices.size());
    if (!transition) {
      globalTransitionAuthorityValid = false;
      continue;
    }
    globalTransitionByTopology.emplace(topology, transition.value());
  }
  std::map<authority::SourceEdgeTopologyKey, int> globalEdgeByVertices;
  for (int edge = 0; edge < sourceMesh.EV.rows(); ++edge) {
    globalEdgeByVertices[surface_cell_source_edge_key(
        sourceMesh.EV(edge, 0), sourceMesh.EV(edge, 1),
        static_cast<std::size_t>(sourceMesh.V.rows()))] = edge;
  }
  bool allCompletedSurfaceCells = true;
  bool allComponentsUsedSourceGridRecovery = true;
  bool anyComponentUsedSourceGridRecovery = false;
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

  std::vector<std::optional<authority::SourceFaceTopologyKey>>
      globalRowTopology(static_cast<std::size_t>(faces.rows()));
  std::vector<std::optional<authority::SourceComponentId>>
      globalRowComponents(static_cast<std::size_t>(faces.rows()));
  std::vector<std::optional<authority::IsolationSheetId>>
      globalRowSheets(static_cast<std::size_t>(faces.rows()));
  std::vector<geometry::SurfaceTopologyRegion> globalRegions;
  std::vector<geometry::SurfaceCellRail> aggregateAuthoritativeRails;
  std::vector<geometry::PureQuadMesh> aggregateCompletedPatches;

  std::set<std::pair<int, int>> globalValidationBoundaryEdges;
  std::vector<std::vector<int>> globalValidationBoundaryLoops;
  std::vector<std::vector<int>> globalValidationFeatureRails;
  std::vector<validation::SourceVertexChartAuthority>
      globalValidationVertexCharts;
  std::vector<int> globalValidationOutputQuadSourceFaces;
  std::set<authority::SourceEdgeTopologyKey> globalValidationHardFeatureEdges;
  std::size_t globalValidationExpectedFeatureRailCount = 0U;
  bool globalValidationFeatureRailAuthorityProvided = true;

  const auto reject_merge_authority =
      [&](const std::size_t componentIndex, const std::string &reason) {
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
        merged.surfaceCellContext = SurfaceCellPipelineContext{};
        if (componentIndex < components.size()) {
          merged.diagnostics.failedComponentIndex = componentIndex;
          merged.diagnostics.failedComponentMinimumOriginalFace =
              static_cast<std::size_t>(
                  components[componentIndex].minimum_original_face());
        }
        merged.diagnostics.terminalFailureCode =
            surface_cell_failure_code_name(
                SurfaceCellFailureCode::NotProductionReady);
        merged.diagnostics.terminalFailureStage = "component-merge-authority";
        merged.diagnostics.terminalFailureDetailCode = "None";
        merged.diagnostics.terminalFailureLocus = {};
        merged.diagnostics.surfaceCellFirstInvalidProducerStage =
            "component-merge-authority";
        merged.diagnostics.surfaceCellFirstInvalidProducerReason = reason;
        merged.diagnostics.surfaceCellOutputOrigin = SurfaceCellOutputOrigin::None;
        merged.diagnostics.surfaceCellRemeshOccurred = false;
        merged.diagnostics.componentMergeSeconds =
            remesh_elapsed_seconds(mergeStart);
        set_overall_pipeline_time(merged, pipelineStart);
      };

  if (!globalTransitionAuthorityValid) {
    reject_merge_authority(components.size(),
                           "InvalidGlobalSourceTransitionAuthority");
    return finish_aggregate_rejection(merged, "component-aggregation");
  }

  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    const RemeshResult &componentResult = runs[index].result;
    const RemeshProduct &componentProduct = componentResult.product();
    const SurfaceCellComponentStageProducts &componentProducts =
        runs[index].stageProducts;
    const int vertexOffset = static_cast<int>(staged.vertices.rows());
    const int faceOffset = static_cast<int>(staged.faces.rows());

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
          surface_cell_source_edge_key(
              originalVertex0, originalVertex1,
              static_cast<std::size_t>(sourceMesh.V.rows())));
      if (found != globalEdgeByVertices.end()) {
        globalEdgeByLocal[static_cast<std::size_t>(localEdge)] = found->second;
      }
    }

    std::map<authority::SourceVertexId, authority::SourceVertexId>
        globalSourceVertexByLocal;
    for (std::size_t localVertexRow = 0;
         localVertexRow < component.originalVertices.size(); ++localVertexRow) {
      const auto localVertex = authority::SourceVertexId::from_index(
          localVertexRow, component.originalVertices.size());
      const auto globalVertex = authority::SourceVertexId::from_index(
          component.originalVertices[localVertexRow],
          static_cast<std::size_t>(vertices.rows()));
      if (!localVertex || !globalVertex ||
          !globalSourceVertexByLocal.emplace(localVertex.value(),
                                             globalVertex.value()).second) {
        reject_merge_authority(index,
                               "InvalidTypedComponentSourceVertexRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
    }
    const auto remap_source_vertex =
        [&](const authority::SourceVertexId local)
        -> std::optional<authority::SourceVertexId> {
      const auto mapped = globalSourceVertexByLocal.find(local);
      return mapped != globalSourceVertexByLocal.end()
                 ? std::optional<authority::SourceVertexId>(mapped->second)
                 : std::nullopt;
    };
    const auto remap_source_edge_topology =
        [&](const authority::SourceEdgeTopologyKey &localTopology)
        -> std::optional<authority::SourceEdgeTopologyKey> {
      const auto globalFirst = remap_source_vertex(localTopology.first());
      const auto globalSecond = remap_source_vertex(localTopology.second());
      if (!globalFirst || !globalSecond) return std::nullopt;
      const auto topology = authority::SourceEdgeTopologyKey::make(
          globalFirst.value(), globalSecond.value());
      return topology
                 ? std::optional<authority::SourceEdgeTopologyKey>(
                       topology.value())
                 : std::nullopt;
    };
    const auto remap_source_face_topology =
        [&](const authority::SourceFaceTopologyKey &localTopology)
        -> std::optional<authority::SourceFaceTopologyKey> {
      std::array<authority::SourceVertexId, 3> verticesGlobal = {
          localTopology.vertices()[0], localTopology.vertices()[1],
          localTopology.vertices()[2]};
      for (authority::SourceVertexId &vertex : verticesGlobal) {
        const auto mapped = remap_source_vertex(vertex);
        if (!mapped) return std::nullopt;
        vertex = mapped.value();
      }
      const auto topology = authority::SourceFaceTopologyKey::make(
          verticesGlobal);
      return topology
                 ? std::optional<authority::SourceFaceTopologyKey>(
                       topology.value())
                 : std::nullopt;
    };

    const auto remap_route = [&](const authority::CanonicalRoute &localRoute)
        -> std::optional<authority::CanonicalRoute> {
      if (localRoute.empty()) return authority::CanonicalRoute{};
      std::vector<authority::TransitionStep> remappedSteps;
      remappedSteps.reserve(localRoute.steps().size());
      for (const authority::TransitionStep &step :
           localRoute.oriented_steps()) {
        const auto topology = remap_source_edge_topology(step.topology());
        if (!topology) return std::nullopt;
        if (step.kind() == authority::TransitionStepKind::Boundary) {
          if (step.interior().has_value()) return std::nullopt;
          remappedSteps.push_back(authority::TransitionStep::boundary(
              topology.value(), step.transport(), step.orientation()));
          continue;
        }
        const auto globalTransition =
            globalTransitionByTopology.find(topology.value());
        if (globalTransition == globalTransitionByTopology.end()) {
          return std::nullopt;
        }
        const auto remapped = authority::TransitionStep::interior(
            topology.value(), globalTransition->second, step.transport(),
            step.orientation());
        if (!remapped) return std::nullopt;
        remappedSteps.push_back(remapped.value());
      }
      return authority::CanonicalRoute::from_observed_steps(
          std::move(remappedSteps));
    };

    int localMaximumCurve = -1;
    staged.surfaceCellContext.tracingCurrentOwnedBytes +=
        componentResult.surfaceCellContext.tracingCurrentOwnedBytes;
    staged.surfaceCellContext.tracingPeakOwnedBytes +=
        componentResult.surfaceCellContext.tracingPeakOwnedBytes;
    staged.surfaceCellContext.flowRepCurrentOwnedBytes +=
        componentResult.surfaceCellContext.flowRepCurrentOwnedBytes;
    staged.surfaceCellContext.flowRepPeakOwnedBytes +=
        componentResult.surfaceCellContext.flowRepPeakOwnedBytes;
    staged.surfaceCellContext.arrangementCurrentOwnedBytes +=
        componentResult.surfaceCellContext.arrangementCurrentOwnedBytes;
    staged.surfaceCellContext.arrangementPeakOwnedBytes +=
        componentResult.surfaceCellContext.arrangementPeakOwnedBytes;
    staged.surfaceCellContext.simplificationCurrentOwnedBytes +=
        componentResult.surfaceCellContext.simplificationCurrentOwnedBytes;
    staged.surfaceCellContext.simplificationPeakOwnedBytes +=
        componentResult.surfaceCellContext.simplificationPeakOwnedBytes;
    staged.surfaceCellContext.tracingLogicalPayloadBytes +=
        componentResult.surfaceCellContext.tracingLogicalPayloadBytes;
    staged.surfaceCellContext.tracingRetainedCapacityBytes +=
        componentResult.surfaceCellContext.tracingRetainedCapacityBytes;
    staged.surfaceCellContext.flowRepLogicalPayloadBytes +=
        componentResult.surfaceCellContext.flowRepLogicalPayloadBytes;
    staged.surfaceCellContext.flowRepRetainedCapacityBytes +=
        componentResult.surfaceCellContext.flowRepRetainedCapacityBytes;
    staged.surfaceCellContext.arrangementLogicalPayloadBytes +=
        componentResult.surfaceCellContext.arrangementLogicalPayloadBytes;
    staged.surfaceCellContext.arrangementRetainedCapacityBytes +=
        componentResult.surfaceCellContext.arrangementRetainedCapacityBytes;
    staged.surfaceCellContext.simplificationLogicalPayloadBytes +=
        componentResult.surfaceCellContext.simplificationLogicalPayloadBytes;
    staged.surfaceCellContext.simplificationRetainedCapacityBytes +=
        componentResult.surfaceCellContext.simplificationRetainedCapacityBytes;
    staged.surfaceCellContext.completionLogicalPayloadBytes +=
        componentResult.surfaceCellContext.completionLogicalPayloadBytes;
    staged.surfaceCellContext.completionRetainedCapacityBytes +=
        componentResult.surfaceCellContext.completionRetainedCapacityBytes;
    staged.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes +=
        componentResult.surfaceCellContext.estimatedPeakSimultaneousOwnedBytes;
    for (SurfaceCellMemoryOwnershipEvent event :
         componentResult.surfaceCellContext.memoryOwnershipTimeline) {
      event.stage = "component[" + std::to_string(index) + "]/" + event.stage;
      staged.surfaceCellContext.memoryOwnershipTimeline.push_back(
          std::move(event));
    }
    staged.surfaceCellContext.maxSimultaneousLiveLargeStructures = std::max(
        staged.surfaceCellContext.maxSimultaneousLiveLargeStructures,
        componentResult.surfaceCellContext.maxSimultaneousLiveLargeStructures);
    if (index == 0U) {
      staged.surfaceCellContext.traceStorageReleasedAfterFlowRep =
          componentResult.surfaceCellContext.traceStorageReleasedAfterFlowRep;
      staged.surfaceCellContext
          .flowRepSelectionStorageReleasedAfterSelection =
          componentResult.surfaceCellContext
              .flowRepSelectionStorageReleasedAfterSelection;
      staged.surfaceCellContext
          .embeddedArrangementStorageReleasedAfterArrangement =
          componentResult.surfaceCellContext
              .embeddedArrangementStorageReleasedAfterArrangement;
    } else {
      staged.surfaceCellContext.traceStorageReleasedAfterFlowRep =
          staged.surfaceCellContext.traceStorageReleasedAfterFlowRep &&
          componentResult.surfaceCellContext.traceStorageReleasedAfterFlowRep;
      staged.surfaceCellContext
          .flowRepSelectionStorageReleasedAfterSelection =
          staged.surfaceCellContext
              .flowRepSelectionStorageReleasedAfterSelection &&
          componentResult.surfaceCellContext
              .flowRepSelectionStorageReleasedAfterSelection;
      staged.surfaceCellContext
          .embeddedArrangementStorageReleasedAfterArrangement =
          staged.surfaceCellContext
              .embeddedArrangementStorageReleasedAfterArrangement &&
          componentResult.surfaceCellContext
              .embeddedArrangementStorageReleasedAfterArrangement;
    }
    if (!componentProducts.sourceTopologyRegions.has_value()) {
      reject_merge_authority(
          index, "MissingTypedComponentSourceAuthorityDomain");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    const ComponentFinalValidationAuthority &componentValidationAuthority =
        runs[index].finalValidationAuthority;
    const auto invalidCompletedPatch = std::find_if(
        componentProducts.completedPatches.begin(),
        componentProducts.completedPatches.end(),
        [](const geometry::PureQuadMesh &patch) { return patch.sourcePatch < 0; });
    if (invalidCompletedPatch != componentProducts.completedPatches.end()) {
      reject_merge_authority(index, "AggregateIdentityInvalidPatchMetadata");
      merged.diagnostics.surfaceCellFirstInvalidProducerCell = static_cast<int>(
          std::distance(componentProducts.completedPatches.begin(),
                        invalidCompletedPatch));
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    if (!componentValidationAuthority.available ||
        !same_surface_cell_rail_authority(
            componentProducts.authoritativeRails,
            componentValidationAuthority.authoritativeRails)) {
      reject_merge_authority(index, "ChangedComponentValidationAuthority");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    const std::set<authority::SourceEdgeTopologyKey> componentHardFeatureEdges =
        hard_feature_edge_keys_from_rails(
            componentValidationAuthority.authoritativeRails,
            component.originalVertices.size());
    const auto typedAuthorityDomain = make_component_typed_authority_remap_domain(
        component,
        componentProducts.sourceTopologyRegions.value(),
        componentHardFeatureEdges, nextTopologyRegion, nextIsolationSheet,
        nextFieldChart);
    if (!typedAuthorityDomain.has_value()) {
      reject_merge_authority(
          index, "InvalidTypedComponentSourceAuthorityDomain");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }

    const auto globalComponent = authority::SourceComponentId::from_index(
        static_cast<std::int64_t>(index), components.size());
    if (!globalComponent) {
      reject_merge_authority(index,
                             "InvalidGlobalSourceAuthorityComponent");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    const geometry::SourceTopologyRegions &componentAuthority =
        componentProducts.sourceTopologyRegions.value();
    for (std::size_t localFace = 0;
         localFace < component.originalFaces.size(); ++localFace) {
      const int globalFace = component.originalFaces[localFace];
      if (globalFace < 0 || globalFace >= faces.rows()) {
        reject_merge_authority(index,
                               "InvalidGlobalSourceAuthorityFace");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      const auto localRow = authority::SourceFaceId::from_index(
          static_cast<std::int64_t>(localFace),
          component.originalFaces.size());
      if (!localRow) {
        reject_merge_authority(index,
                               "InvalidGlobalSourceAuthorityFace");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      const auto topology = remap_source_face_topology(
          componentAuthority.topology_for_row(localRow.value()));
      const auto mappedSheet = typedAuthorityDomain->isolationSheets.find(
          componentAuthority.sheet_for_row(localRow.value()));
      if (!topology ||
          mappedSheet == typedAuthorityDomain->isolationSheets.end() ||
          globalRowTopology[static_cast<std::size_t>(globalFace)].has_value() ||
          globalRowComponents[static_cast<std::size_t>(globalFace)].has_value() ||
          globalRowSheets[static_cast<std::size_t>(globalFace)].has_value()) {
        reject_merge_authority(index,
                               "InvalidGlobalSourceAuthorityFace");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      globalRowTopology[static_cast<std::size_t>(globalFace)] = topology.value();
      globalRowComponents[static_cast<std::size_t>(globalFace)] =
          globalComponent.value();
      globalRowSheets[static_cast<std::size_t>(globalFace)] =
          mappedSheet->second;
    }

    for (const geometry::SurfaceTopologyRegion &localRegion :
         componentAuthority.regions()) {
      const auto mappedRegion =
          typedAuthorityDomain->topologyRegions.find(localRegion.id());
      if (mappedRegion == typedAuthorityDomain->topologyRegions.end()) {
        reject_merge_authority(index,
                               "InvalidGlobalSourceAuthorityRegion");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      std::vector<geometry::SourceRegionFaceAuthority> regionFaces;
      regionFaces.reserve(localRegion.faces().size());
      for (const geometry::SourceRegionFaceAuthority &localFace :
           localRegion.faces()) {
        const auto topology =
            remap_source_face_topology(localFace.topology);
        const auto mappedSheet =
            typedAuthorityDomain->isolationSheets.find(localFace.sheet);
        if (!topology ||
            mappedSheet == typedAuthorityDomain->isolationSheets.end()) {
          reject_merge_authority(index,
                                 "InvalidGlobalSourceAuthorityRegion");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        regionFaces.push_back(
            {topology.value(), mappedSheet->second});
      }
      std::sort(regionFaces.begin(), regionFaces.end(),
                [](const auto &a, const auto &b) {
                  return a.topology < b.topology;
                });

      std::vector<authority::SourceEdgeTopologyKey> boundaryEdges;
      boundaryEdges.reserve(localRegion.boundary_edges().size());
      for (const authority::SourceEdgeTopologyKey &edge :
           localRegion.boundary_edges()) {
        const auto topology = remap_source_edge_topology(edge);
        if (!topology) {
          reject_merge_authority(index,
                                 "InvalidGlobalSourceAuthorityRegion");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        boundaryEdges.push_back(topology.value());
      }
      std::sort(boundaryEdges.begin(), boundaryEdges.end());
      boundaryEdges.erase(
          std::unique(boundaryEdges.begin(), boundaryEdges.end()),
          boundaryEdges.end());

      std::vector<authority::SourceEdgeTopologyKey> isolationSeams;
      isolationSeams.reserve(localRegion.isolation_seams().size());
      for (const authority::SourceEdgeTopologyKey &edge :
           localRegion.isolation_seams()) {
        const auto topology = remap_source_edge_topology(edge);
        if (!topology) {
          reject_merge_authority(index,
                                 "InvalidGlobalSourceAuthorityRegion");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        isolationSeams.push_back(topology.value());
      }
      std::sort(isolationSeams.begin(), isolationSeams.end());
      isolationSeams.erase(
          std::unique(isolationSeams.begin(), isolationSeams.end()),
          isolationSeams.end());

      const auto region = geometry::SurfaceTopologyRegion::make(
          mappedRegion->second, globalComponent.value(),
          std::move(regionFaces), std::move(boundaryEdges),
          std::move(isolationSeams), localRegion.euler_characteristic(),
          localRegion.boundary_loop_count());
      if (!region) {
        reject_merge_authority(index,
                               "InvalidGlobalSourceAuthorityRegion");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      globalRegions.push_back(region.value());
    }

    allHaveSourceLabels =
        allHaveSourceLabels &&
        componentProducts.sourceSurfaceLabels.has_value();
    if (componentProducts.sourceSurfaceLabels.has_value()) {
      for (std::size_t localFace = 0;
           localFace < component.originalFaces.size(); ++localFace) {
        const int originalFace = component.originalFaces[localFace];
        staged.surfaceCellContext.productSnapshots.sourceSurfaceLabels.componentByFace[
            static_cast<std::size_t>(originalFace)] =
            static_cast<int>(index);
        const geometry::SourceSurfaceLabels &componentLabels =
            componentProducts.sourceSurfaceLabels.value();
        if (componentLabels.localSheetByFace.size() !=
                component.originalFaces.size() ||
            componentLabels.localSheetByFace[localFace] < 0) {
          reject_merge_authority(
              index, "InvalidComponentSourceSurfaceLabels");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        // SourceSurfaceLabels is explicitly a raw per-component tracing
        // representation. Preserve that local label; typed merged sheet
        // authority is carried separately in globalRowSheets.
        staged.surfaceCellContext.productSnapshots.sourceSurfaceLabels.localSheetByFace[
            static_cast<std::size_t>(originalFace)] =
            componentLabels.localSheetByFace[localFace];
      }
    }

    if (componentValidationAuthority.vertexLineage.size() !=
            static_cast<std::size_t>(componentProduct.vertices.rows()) ||
        componentValidationAuthority.outputQuadSourceFaces.size() !=
            static_cast<std::size_t>(componentProduct.faces.rows())) {
      reject_merge_authority(index, "ChangedComponentValidationAuthority");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    const auto remapValidationOutputVertex = [&](const int localVertex)
        -> std::optional<int> {
      if (localVertex < 0 || localVertex >= componentProduct.vertices.rows() ||
          localVertex > std::numeric_limits<int>::max() - vertexOffset) {
        return std::nullopt;
      }
      return localVertex + vertexOffset;
    };
    for (const auto &edge :
         componentValidationAuthority.authoritativeBoundaryEdges) {
      const auto first = remapValidationOutputVertex(edge.first);
      const auto second = remapValidationOutputVertex(edge.second);
      if (!first.has_value() || !second.has_value()) {
        reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      globalValidationBoundaryEdges.insert(std::minmax(*first, *second));
    }
    for (const std::vector<int> &localLoop :
         componentValidationAuthority.authoritativeBoundaryLoops) {
      std::vector<int> globalLoop;
      globalLoop.reserve(localLoop.size());
      for (const int localVertex : localLoop) {
        const auto globalVertex = remapValidationOutputVertex(localVertex);
        if (!globalVertex.has_value()) {
          reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        globalLoop.push_back(*globalVertex);
      }
      globalValidationBoundaryLoops.push_back(std::move(globalLoop));
    }
    for (const std::vector<int> &localRail :
         componentValidationAuthority.authoritativeFeatureRails) {
      std::vector<int> globalRail;
      globalRail.reserve(localRail.size());
      for (const int localVertex : localRail) {
        const auto globalVertex = remapValidationOutputVertex(localVertex);
        if (!globalVertex.has_value()) {
          reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        globalRail.push_back(*globalVertex);
      }
      globalValidationFeatureRails.push_back(std::move(globalRail));
    }
    if (componentValidationAuthority.expectedFeatureRailCount >
        std::numeric_limits<std::size_t>::max() -
            globalValidationExpectedFeatureRailCount) {
      reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    globalValidationExpectedFeatureRailCount +=
        componentValidationAuthority.expectedFeatureRailCount;
    globalValidationFeatureRailAuthorityProvided =
        globalValidationFeatureRailAuthorityProvided &&
        componentValidationAuthority.featureRailAuthorityProvided;
    for (const int localSourceFace :
         componentValidationAuthority.outputQuadSourceFaces) {
      if (localSourceFace < 0) {
        globalValidationOutputQuadSourceFaces.push_back(-1);
        continue;
      }
      if (static_cast<std::size_t>(localSourceFace) >=
          component.originalFaces.size()) {
        reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      globalValidationOutputQuadSourceFaces.push_back(
          component.originalFaces[static_cast<std::size_t>(localSourceFace)]);
    }
    for (const geometry::SurfaceCellRail &rail :
         componentValidationAuthority.authoritativeRails) {
      if (rail.kind != geometry::SurfaceCellRailKind::HardFeature) continue;
      const auto addHardFeatureEdge = [&](const int localFirst,
                                          const int localSecond) -> bool {
        if (localFirst < 0 || localSecond < 0 ||
            static_cast<std::size_t>(localFirst) >=
                component.originalVertices.size() ||
            static_cast<std::size_t>(localSecond) >=
                component.originalVertices.size()) {
          return false;
        }
        globalValidationHardFeatureEdges.insert(surface_cell_source_edge_key(
            component.originalVertices[static_cast<std::size_t>(localFirst)],
            component.originalVertices[static_cast<std::size_t>(localSecond)],
            static_cast<std::size_t>(vertices.rows())));
        return true;
      };
      for (std::size_t sourceVertex = 0;
           sourceVertex + 1U < rail.sourceVertices.size(); ++sourceVertex) {
        if (!addHardFeatureEdge(rail.sourceVertices[sourceVertex],
                                rail.sourceVertices[sourceVertex + 1U])) {
          reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
      }
      if (rail.closed && rail.sourceVertices.size() > 1U &&
          rail.sourceVertices.front() != rail.sourceVertices.back() &&
          !addHardFeatureEdge(rail.sourceVertices.back(),
                              rail.sourceVertices.front())) {
        reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
    }

    allHaveAuthoritativeRails =
        allHaveAuthoritativeRails &&
        !componentProducts.authoritativeRails.empty();
    std::map<authority::HardRailId, authority::HardRailId> railIdRemap;
    const auto allocate_rail_id = [&](const authority::HardRailId local)
        -> std::optional<authority::HardRailId> {
      const auto existing = railIdRemap.find(local);
      if (existing != railIdRemap.end()) return existing->second;
      if (railOffset > std::numeric_limits<std::size_t>::max() -
                           railIdRemap.size()) {
        return std::nullopt;
      }
      const std::size_t globalIndex = railOffset + railIdRemap.size();
      const auto global = authority::HardRailId::from_index(
          static_cast<std::int64_t>(globalIndex), globalIndex + 1U);
      if (!global || !railIdRemap.emplace(local, global.value()).second) {
        return std::nullopt;
      }
      return global.value();
    };
    for (geometry::SurfaceCellRail rail :
         componentProducts.authoritativeRails) {
      const auto remappedRail = allocate_rail_id(rail.id);
      if (!remappedRail) {
        reject_merge_authority(index,
                               "InvalidTypedComponentAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      localMaximumCurve = std::max(localMaximumCurve, rail.curveId);
      rail.id = remappedRail.value();
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
      aggregateAuthoritativeRails.push_back(
          std::move(rail));
    }

    int localMaximumFrontEdge = -1;
    std::map<authority::PeriodicRelationId, authority::PeriodicRelationId>
        periodicRelationIdRemap;
    std::map<authority::OccurrenceId, authority::OccurrenceId>
        occurrenceIdRemap;
    std::map<authority::QuotientClassId, authority::QuotientClassId>
        quotientClassIdRemap;
    const auto remap_periodic_relation_id =
        [&](const authority::PeriodicRelationId local)
        -> std::optional<authority::PeriodicRelationId> {
      const auto existing = periodicRelationIdRemap.find(local);
      if (existing != periodicRelationIdRemap.end()) return existing->second;
      const std::size_t globalIndex =
          periodicRelationOffset + periodicRelationIdRemap.size();
      if (globalIndex < periodicRelationOffset) return std::nullopt;
      const auto global = authority::PeriodicRelationId::from_index(
          static_cast<std::int64_t>(globalIndex), globalIndex + 1U);
      if (!global ||
          !periodicRelationIdRemap.emplace(local, global.value()).second) {
        return std::nullopt;
      }
      return global.value();
    };
    const auto remap_occurrence_id = [&](const authority::OccurrenceId local)
        -> std::optional<authority::OccurrenceId> {
      const auto existing = occurrenceIdRemap.find(local);
      if (existing != occurrenceIdRemap.end()) return existing->second;
      const std::size_t globalIndex = occurrenceOffset + occurrenceIdRemap.size();
      if (globalIndex < occurrenceOffset) return std::nullopt;
      const auto global = authority::OccurrenceId::from_index(
          static_cast<std::int64_t>(globalIndex), globalIndex + 1U);
      if (!global || !occurrenceIdRemap.emplace(local, global.value()).second) {
        return std::nullopt;
      }
      return global.value();
    };
    const auto remap_quotient_class_id =
        [&](const authority::QuotientClassId local)
        -> std::optional<authority::QuotientClassId> {
      const auto existing = quotientClassIdRemap.find(local);
      if (existing != quotientClassIdRemap.end()) return existing->second;
      const std::size_t globalIndex =
          quotientClassOffset + quotientClassIdRemap.size();
      if (globalIndex < quotientClassOffset) return std::nullopt;
      const auto global = authority::QuotientClassId::from_index(
          static_cast<std::int64_t>(globalIndex), globalIndex + 1U);
      if (!global ||
          !quotientClassIdRemap.emplace(local, global.value()).second) {
        return std::nullopt;
      }
      return global.value();
    };
    const auto remap_rail_id = [&](const authority::HardRailId local)
        -> std::optional<authority::HardRailId> {
      const auto existing = railIdRemap.find(local);
      return existing != railIdRemap.end()
                 ? std::optional<authority::HardRailId>(existing->second)
                 : std::nullopt;
    };

    const auto remap_quotient_lineage_authority =
        [&](geometry::PureQuadVertexLineage &lineage) -> bool {
          if (!remap_component_typed_lineage_authority(
                  lineage, component, static_cast<std::size_t>(vertices.rows()),
                  static_cast<std::size_t>(faces.rows()),
                  typedAuthorityDomain.value())) {
            return false;
          }
          const std::optional<authority::IsolationSheetId> projectionSheet =
              lineage.sourceIsolationSheets.size() == 1U
                  ? std::optional<authority::IsolationSheetId>(
                        lineage.sourceIsolationSheets.front())
                  : std::nullopt;
          lineage.sourcePoint = remap_component_surface_point(
              lineage.sourcePoint, component, index, projectionSheet);
          lineage.featureInterval.start = remap_component_surface_point(
              lineage.featureInterval.start, component, index,
              projectionSheet);
          lineage.featureInterval.end = remap_component_surface_point(
              lineage.featureInterval.end, component, index,
              projectionSheet);
          if ((lineage.kind == geometry::PureQuadVertexLineageKind::SourceTriangle &&
               !lineage.sourcePoint.valid()) ||
              (lineage.kind ==
                   geometry::PureQuadVertexLineageKind::OrderedFeatureInterval &&
               !lineage.featureInterval.valid())) {
            return false;
          }

          if (lineage.quotientClass.has_value()) {
            const auto remapped =
                remap_quotient_class_id(lineage.quotientClass.value());
            if (!remapped) return false;
            lineage.quotientClass = remapped.value();
          }
          for (authority::OccurrenceId &occurrence :
               lineage.sourceOccurrences) {
            const auto remapped = remap_occurrence_id(occurrence);
            if (!remapped) return false;
            occurrence = remapped.value();
          }
          for (geometry::PureQuadEquivalenceProvenance &equivalence :
               lineage.equivalences) {
            if (equivalence.firstFrontEdge >= 0) {
              localMaximumFrontEdge = std::max(
                  localMaximumFrontEdge, equivalence.firstFrontEdge);
              if (equivalence.firstFrontEdge >
                  std::numeric_limits<int>::max() - frontEdgeOffset) {
                return false;
              }
              equivalence.firstFrontEdge += frontEdgeOffset;
            }
            if (equivalence.secondFrontEdge >= 0) {
              localMaximumFrontEdge = std::max(
                  localMaximumFrontEdge, equivalence.secondFrontEdge);
              if (equivalence.secondFrontEdge >
                  std::numeric_limits<int>::max() - frontEdgeOffset) {
                return false;
              }
              equivalence.secondFrontEdge += frontEdgeOffset;
            }
            if (equivalence.periodicRelation.has_value()) {
              const auto relationId = remap_periodic_relation_id(
                  equivalence.periodicRelation.value());
              if (!relationId) return false;
              equivalence.periodicRelation = relationId.value();
            }
            if (equivalence.railId.has_value()) {
              const auto railId = remap_rail_id(equivalence.railId.value());
              if (!railId) return false;
              equivalence.railId = railId.value();
            }
            const auto remappedRoute = remap_route(equivalence.route);
            if (!remappedRoute) return false;
            equivalence.route = remappedRoute.value();
            for (authority::SourceEdgeTopologyKey &topology :
                 equivalence.isolationSeams) {
              const auto remappedTopology =
                  remap_source_edge_topology(topology);
              if (!remappedTopology) return false;
              topology = remappedTopology.value();
            }
          }
          std::sort(lineage.equivalences.begin(),
                    lineage.equivalences.end());
          lineage.equivalences.erase(
              std::unique(lineage.equivalences.begin(),
                          lineage.equivalences.end()),
              lineage.equivalences.end());
          return !lineage.sourceTopologyRegions.empty() &&
                 !lineage.sourceIsolationSheets.empty() &&
                 !lineage.sourceCharts.empty() &&
                 lineage.sourceSupport.has_value();
        };

    std::vector<geometry::PureQuadVertexLineage>
        remappedValidationVertexLineage =
            componentValidationAuthority.vertexLineage;
    for (geometry::PureQuadVertexLineage &lineage :
         remappedValidationVertexLineage) {
      if (!remap_quotient_lineage_authority(lineage)) {
        reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
    }
    std::vector<validation::SourceVertexChartAuthority>
        remappedValidationVertexCharts;
    const std::size_t globalRailExtent = railOffset + railIdRemap.size();
    if (!project_surface_cell_vertex_chart_authority(
            remappedValidationVertexLineage, componentProduct.vertices.rows(),
            globalRailExtent, remappedValidationVertexCharts) ||
        globalValidationVertexCharts.size() !=
            static_cast<std::size_t>(vertexOffset)) {
      reject_merge_authority(index, "InvalidFinalValidationAuthorityRemap");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    globalValidationVertexCharts.insert(
        globalValidationVertexCharts.end(),
        std::make_move_iterator(remappedValidationVertexCharts.begin()),
        std::make_move_iterator(remappedValidationVertexCharts.end()));

    int localMaximumPatch = -1;
    std::vector<geometry::PureQuadVertexLineage> remappedOutputVertexLineage;
    remappedOutputVertexLineage.reserve(
        componentProduct.outputVertexLineage.size());
    for (geometry::PureQuadVertexLineage lineage :
         componentProduct.outputVertexLineage) {
      if (lineage.outputVertex < 0 ||
          lineage.outputVertex >
              std::numeric_limits<int>::max() - vertexOffset) {
        reject_merge_authority(
          index,   "InvalidTypedComponentAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      lineage.outputVertex += vertexOffset;
      if (lineage.sourcePatch >= 0) {
        localMaximumPatch = std::max(localMaximumPatch, lineage.sourcePatch);
        if (lineage.sourcePatch >
            std::numeric_limits<int>::max() - patchOffset) {
          reject_merge_authority(index,
                                 "InvalidTypedComponentAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        lineage.sourcePatch += patchOffset;
      }
      if (lineage.featureInterval.railId.has_value()) {
        const auto railId = remap_rail_id(lineage.featureInterval.railId.value());
        if (!railId) {
          reject_merge_authority(
              index, "InvalidTypedComponentAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        lineage.featureInterval.railId = railId.value();
      }
      if (lineage.featureInterval.curveId >= 0) {
        if (lineage.featureInterval.curveId >
            std::numeric_limits<int>::max() - curveOffset) {
          reject_merge_authority(
          index,     "InvalidTypedComponentAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        lineage.featureInterval.curveId += curveOffset;
      }
      if (!remap_quotient_lineage_authority(lineage)) {
        reject_merge_authority(
          index,   "InvalidTypedComponentAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      remappedOutputVertexLineage.push_back(std::move(lineage));
    }

    if (componentProduct.outputVertexProvenance.size() !=
        remappedOutputVertexLineage.size()) {
      reject_merge_authority(
          index, "InvalidTypedComponentAuthorityRemap");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    std::vector<geometry::SurfacePoint> remappedOutputVertexProvenance;
    remappedOutputVertexProvenance.reserve(
        componentProduct.outputVertexProvenance.size());
    for (std::size_t vertex = 0;
         vertex < componentProduct.outputVertexProvenance.size(); ++vertex) {
      const geometry::PureQuadVertexLineage &remappedLineage =
          remappedOutputVertexLineage[vertex];
      const std::optional<authority::IsolationSheetId> projectionSheet =
          remappedLineage.sourceIsolationSheets.size() == 1U
              ? std::optional<authority::IsolationSheetId>(
                    remappedLineage.sourceIsolationSheets.front())
              : std::nullopt;
      geometry::SurfacePoint provenance = remap_component_surface_point(
          componentProduct.outputVertexProvenance[vertex], component, index,
          projectionSheet);
      if (!provenance.valid()) {
        reject_merge_authority(
          index,   "InvalidTypedComponentAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      remappedOutputVertexProvenance.push_back(std::move(provenance));
    }

    std::vector<geometry::PureQuadFaceLineage> remappedOutputQuadLineage;
    remappedOutputQuadLineage.reserve(componentProduct.outputQuadLineage.size());
    for (geometry::PureQuadFaceLineage lineage :
         componentProduct.outputQuadLineage) {
      if (lineage.outputQuad < 0 ||
          lineage.outputQuad >
              std::numeric_limits<int>::max() - faceOffset) {
        reject_merge_authority(
          index,   "InvalidTypedComponentAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      lineage.outputQuad += faceOffset;
      if (lineage.sourcePatch >= 0) {
        localMaximumPatch = std::max(localMaximumPatch, lineage.sourcePatch);
        if (lineage.sourcePatch >
            std::numeric_limits<int>::max() - patchOffset) {
          reject_merge_authority(
          index,     "InvalidTypedComponentAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        lineage.sourcePatch += patchOffset;
      }
      remappedOutputQuadLineage.push_back(std::move(lineage));
    }

    std::vector<geometry::PureQuadMesh> remappedCompletedPatches;
    remappedCompletedPatches.reserve(
        componentProducts.completedPatches.size());
    for (geometry::PureQuadMesh patch :
         componentProducts.completedPatches) {
      if (patch.sourcePatch >= 0) {
        localMaximumPatch = std::max(localMaximumPatch, patch.sourcePatch);
        if (patch.sourcePatch >
            std::numeric_limits<int>::max() - patchOffset) {
          reject_merge_authority(
          index,     "InvalidTypedComponentAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
        patch.sourcePatch += patchOffset;
      }
      if (patch.vertexProvenance.size() != patch.vertexLineage.size()) {
        reject_merge_authority(
          index,   "InvalidTypedComponentAuthorityRemap");
        return finish_aggregate_rejection(merged, "component-aggregation");
      }
      for (geometry::PureQuadVertexLineage &lineage : patch.vertexLineage) {
        if (lineage.sourcePatch >= 0) {
          localMaximumPatch = std::max(localMaximumPatch, lineage.sourcePatch);
          if (lineage.sourcePatch >
              std::numeric_limits<int>::max() - patchOffset) {
            reject_merge_authority(index,
                                   "InvalidTypedComponentAuthorityRemap");
            return finish_aggregate_rejection(merged, "component-aggregation");
          }
          lineage.sourcePatch += patchOffset;
        }
        if (lineage.featureInterval.railId.has_value()) {
          const auto railId =
              remap_rail_id(lineage.featureInterval.railId.value());
          if (!railId) {
            reject_merge_authority(
                index, "InvalidTypedComponentAuthorityRemap");
            return finish_aggregate_rejection(merged, "component-aggregation");
          }
          lineage.featureInterval.railId = railId.value();
        }
        if (lineage.featureInterval.curveId >= 0) {
          if (lineage.featureInterval.curveId >
              std::numeric_limits<int>::max() - curveOffset) {
            reject_merge_authority(
          index,       "InvalidTypedComponentAuthorityRemap");
            return finish_aggregate_rejection(merged, "component-aggregation");
          }
          lineage.featureInterval.curveId += curveOffset;
        }
        if (!remap_quotient_lineage_authority(lineage)) {
          reject_merge_authority(
          index,     "InvalidTypedComponentAuthorityRemap");
          return finish_aggregate_rejection(merged, "component-aggregation");
        }
      }
      for (std::size_t vertex = 0; vertex < patch.vertexLineage.size();
           ++vertex) {
        patch.vertexProvenance[vertex] = patch.vertexLineage[vertex].sourcePoint;
      }
      for (geometry::PureQuadFaceLineage &lineage : patch.quadLineage) {
        if (lineage.sourcePatch >= 0) {
          localMaximumPatch = std::max(localMaximumPatch, lineage.sourcePatch);
          if (lineage.sourcePatch >
              std::numeric_limits<int>::max() - patchOffset) {
            reject_merge_authority(
          index,       "InvalidTypedComponentAuthorityRemap");
            return finish_aggregate_rejection(merged, "component-aggregation");
          }
          lineage.sourcePatch += patchOffset;
        }
      }
      remappedCompletedPatches.push_back(std::move(patch));
    }

    // Publish component geometry and semantic products only after every typed
    // lineage remap above has succeeded. A malformed component therefore cannot
    // leave a partially merged mesh or completion product behind.
    append_matrix_rows(staged.vertices, componentProduct.vertices);
    append_polygon_faces(staged.faces, staged.degrees, componentProduct.faces,
                         componentProduct.degrees, vertexOffset);
    staged.outputVertexProvenance.insert(
        staged.outputVertexProvenance.end(),
        std::make_move_iterator(remappedOutputVertexProvenance.begin()),
        std::make_move_iterator(remappedOutputVertexProvenance.end()));
    staged.outputVertexLineage.insert(
        staged.outputVertexLineage.end(),
        std::make_move_iterator(remappedOutputVertexLineage.begin()),
        std::make_move_iterator(remappedOutputVertexLineage.end()));
    staged.outputQuadLineage.insert(
        staged.outputQuadLineage.end(),
        std::make_move_iterator(remappedOutputQuadLineage.begin()),
        std::make_move_iterator(remappedOutputQuadLineage.end()));
    aggregateCompletedPatches.insert(
        aggregateCompletedPatches.end(),
        std::make_move_iterator(remappedCompletedPatches.begin()),
        std::make_move_iterator(remappedCompletedPatches.end()));

    for (const SurfaceCellContextProductDebug &product :
         componentResult.surfaceCellContext.debugProducts) {
      SurfaceCellContextProductDebug mergedProduct = product;
      mergedProduct.name = "component[" + std::to_string(index) + "]/" +
                           product.name;
      staged.surfaceCellContext.debugProducts.push_back(
          std::move(mergedProduct));
    }

    const SurfaceCellOutputOrigin componentOrigin =
        componentResult.diagnostics.surfaceCellOutputOrigin;
    allCompletedSurfaceCells =
        allCompletedSurfaceCells &&
        (componentOrigin == SurfaceCellOutputOrigin::CompletedSurfaceCells ||
         componentOrigin == SurfaceCellOutputOrigin::SourceGridRecovery);
    const bool componentUsedSourceGridRecovery =
        componentProducts.sourceGridRecoveryUsed;
    anyComponentUsedSourceGridRecovery =
        anyComponentUsedSourceGridRecovery || componentUsedSourceGridRecovery;
    allComponentsUsedSourceGridRecovery =
        allComponentsUsedSourceGridRecovery &&
        componentUsedSourceGridRecovery;
    if (componentUsedSourceGridRecovery) {
      const bool componentRecoveryTargetAvailable =
          componentProducts.hasSourceGridRecoveryTargetSize &&
          componentProducts.sourceGridRecoveryTargetSize.size() ==
              component.vertices.rows();
      allRecoveryTargetsAvailable =
          allRecoveryTargetsAvailable && componentRecoveryTargetAvailable;
      anyRecoveryTargetRelaxed =
          anyRecoveryTargetRelaxed ||
          componentProducts.sourceGridRecoveryTargetSizeRelaxed;
      maximumRecoveryTargetRelaxationRatio = std::max(
          maximumRecoveryTargetRelaxationRatio,
          componentProducts.sourceGridRecoveryTargetSizeMaxRelaxationRatio);
      if (componentRecoveryTargetAvailable) {
        for (std::size_t localVertex = 0;
             localVertex < component.originalVertices.size(); ++localVertex) {
          const int originalVertex = component.originalVertices[localVertex];
          if (originalVertex < 0 || originalVertex >= vertices.rows()) {
            allRecoveryTargetsAvailable = false;
            continue;
          }
          const double target = componentProducts.sourceGridRecoveryTargetSize(
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
        componentProducts.optimizationResult.has_value();
    if (componentProducts.optimizationResult.has_value()) {
      const geometry::SurfaceOptimizationResult &componentOptimization =
          componentProducts.optimizationResult.value();
      hash_combine_u64(aggregateOptimizationResult.topologyHash,
                       componentOptimization.topologyHash);
      accumulate_surface_optimization_result(
          aggregateOptimizationResult, componentOptimization,
          firstOptimizationResult);
      firstOptimizationResult = false;
    }

    allHaveValidationResult =
        allHaveValidationResult &&
        componentProducts.validationResult.has_value();
    if (componentProducts.validationResult.has_value()) {
      accumulate_surface_validation_report(
          aggregateValidationResult,
          componentProducts.validationResult.value(),
          firstValidationResult);
      firstValidationResult = false;
    }

    nextIsolationSheet = typedAuthorityDomain->nextIsolationSheet;
    patchOffset += localMaximumPatch + 1;
    railOffset += railIdRemap.size();
    curveOffset += localMaximumCurve + 1;
    nextTopologyRegion = typedAuthorityDomain->nextTopologyRegion;
    nextFieldChart = typedAuthorityDomain->nextFieldChart;
    frontEdgeOffset += localMaximumFrontEdge + 1;
    periodicRelationOffset += periodicRelationIdRemap.size();
    occurrenceOffset += occurrenceIdRemap.size();
    quotientClassOffset += quotientClassIdRemap.size();
  }

  std::vector<authority::SourceFaceTopologyKey> publishedRowTopology;
  std::vector<authority::SourceComponentId> publishedRowComponents;
  std::vector<authority::IsolationSheetId> publishedRowSheets;
  publishedRowTopology.reserve(globalRowTopology.size());
  publishedRowComponents.reserve(globalRowComponents.size());
  publishedRowSheets.reserve(globalRowSheets.size());
  for (std::size_t row = 0; row < globalRowTopology.size(); ++row) {
    if (!globalRowTopology[row].has_value() ||
        !globalRowComponents[row].has_value() ||
        !globalRowSheets[row].has_value()) {
      reject_merge_authority(components.size(),
                             "IncompleteGlobalSourceAuthority");
      return finish_aggregate_rejection(merged, "component-aggregation");
    }
    publishedRowTopology.push_back(globalRowTopology[row].value());
    publishedRowComponents.push_back(globalRowComponents[row].value());
    publishedRowSheets.push_back(globalRowSheets[row].value());
  }
  const auto globalSourceAuthority = geometry::SourceTopologyRegions::make(
      std::move(publishedRowTopology), publishedRowComponents,
      publishedRowSheets, std::move(globalRegions));
  if (!globalSourceAuthority.has_value() ||
      !globalSourceAuthority->matches_source_faces(
          faces, static_cast<std::size_t>(vertices.rows()))) {
    reject_merge_authority(components.size(),
                           "InvalidGlobalSourceAuthority");
    return finish_aggregate_rejection(merged, "component-aggregation");
  }

  if (globalValidationVertexCharts.size() !=
          static_cast<std::size_t>(staged.vertices.rows()) ||
      globalValidationOutputQuadSourceFaces.size() !=
          static_cast<std::size_t>(staged.faces.rows()) ||
      !globalValidationFeatureRailAuthorityProvided) {
    reject_merge_authority(components.size(),
                           "InvalidFinalValidationAuthorityRemap");
    return finish_aggregate_rejection(merged, "component-aggregation");
  }
  const AggregateIdentityRebuildResult aggregateIdentityRebuild =
      rebuild_aggregate_output_identity_caches(
          staged, aggregateCompletedPatches, faces,
          globalSourceAuthority.value(), &globalValidationHardFeatureEdges);
  staged.diagnostics.surfaceCellAggregateIdentityBoundaryCacheRebuildCount =
      aggregateIdentityRebuild.boundaryCacheRebuildCount;
  if (!aggregateIdentityRebuild.success()) {
    reject_merge_authority(
        components.size(),
        aggregateIdentityRebuild.failure != nullptr
            ? aggregateIdentityRebuild.failure
            : "AggregateIdentityUnknownFailure");
    merged.diagnostics.surfaceCellAggregateIdentityBoundaryCacheRebuildCount =
        aggregateIdentityRebuild.boundaryCacheRebuildCount;
    merged.diagnostics.surfaceCellFirstInvalidProducerCell =
        aggregateIdentityRebuild.patch;
    merged.diagnostics.surfaceCellFirstInvalidProducerVertex =
        aggregateIdentityRebuild.vertex;
    merged.diagnostics.surfaceCellFirstInvalidProducerFace =
        aggregateIdentityRebuild.face;
    return finish_aggregate_rejection(merged, "component-aggregation");
  }
  staged.surfaceCellContext.productSnapshots.sourceTopologyRegions = globalSourceAuthority.value();
  staged.surfaceCellContext.productSnapshots.authoritativeRails = aggregateAuthoritativeRails;
  staged.surfaceCellContext.productSnapshots.completedPatches = aggregateCompletedPatches;

  validation::SourceAuthoritativeMeshValidatorOptions finalAuthorityOptions;
  finalAuthorityOptions.sourceVertices = &vertices;
  finalAuthorityOptions.sourceFaces = &faces;
  finalAuthorityOptions.sourceAuthority = &globalSourceAuthority.value();
  finalAuthorityOptions.vertexProvenance = &staged.outputVertexProvenance;
  finalAuthorityOptions.vertexChartAuthority =
      &globalValidationVertexCharts;
  finalAuthorityOptions.outputQuadSourceFaces =
      &globalValidationOutputQuadSourceFaces;
  finalAuthorityOptions.sourceHardFeatureEdges =
      globalValidationHardFeatureEdges;
  finalAuthorityOptions.authoritativeBoundaryEdges =
      globalValidationBoundaryEdges;
  finalAuthorityOptions.authoritativeBoundaryLoops =
      globalValidationBoundaryLoops;
  finalAuthorityOptions.authoritativeFeatureRails =
      globalValidationFeatureRails;
  finalAuthorityOptions.expectedFeatureRailCount =
      globalValidationExpectedFeatureRailCount;
  finalAuthorityOptions.requireBoundaryAuthority = true;
  finalAuthorityOptions.requireFeatureRailAuthority = true;
  finalAuthorityOptions.requireLocalSheetCompatibility = true;
  if (beforeFinalValidation != nullptr) {
    (*beforeFinalValidation)(finalAuthorityOptions);
  }
  const validation::SourceAuthoritativeMeshValidationResult
      finalAuthorityValidation =
          validation::validate_source_authoritative_surface_mesh(
              staged.vertices, staged.faces, finalAuthorityOptions);
  if (!finalAuthorityValidation.accepted) {
    reject_merge_authority(components.size(),
                           "FinalMergedSourceAuthorityValidationFailed");
    merged.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues.clear();
    for (const validation::MeshValidationIssue &issue :
         finalAuthorityValidation.issues) {
      merged.diagnostics.surfaceCellFinalSourceAuthorityValidationIssues
          .emplace_back(validation::mesh_validation_failure_name(issue.code));
    }
    if (!finalAuthorityValidation.issues.empty()) {
      const validation::MeshValidationIssue *reportedIssue =
          &finalAuthorityValidation.issues.front();
      for (const validation::MeshValidationIssue &issue :
           finalAuthorityValidation.issues) {
        if (issue.code == validation::MeshValidationFailureCode::
                              MissingBoundaryAuthority ||
            issue.code == validation::MeshValidationFailureCode::
                              ChangedBoundaryLoop ||
            issue.code == validation::MeshValidationFailureCode::
                              MissingFeatureRail) {
          reportedIssue = &issue;
          break;
        }
      }
      merged.diagnostics.surfaceCellFirstInvalidProducerValidationIssue =
          std::string(
              validation::mesh_validation_failure_name(reportedIssue->code));
      merged.diagnostics.surfaceCellFirstInvalidProducerFace =
          reportedIssue->face;
      merged.diagnostics.surfaceCellFirstInvalidProducerVertex =
          reportedIssue->vertex;
      merged.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
          reportedIssue->edgeFirst;
      merged.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
          reportedIssue->edgeSecond;
    }
    return finish_aggregate_rejection(merged, "component-aggregation");
  }

  staged.surfaceCellContext.finalSourceAuthorityValidationResult =
      finalAuthorityValidation;
  staged.surfaceCellContext.hasFinalSourceAuthorityValidationResult = true;
  staged.surfaceCellContext.componentValidationReportsComplete =
      allCompletedSurfaceCells && allHaveValidationResult &&
      !firstValidationResult;

  staged.surfaceCellContext.productSnapshots.hasSourceSurfaceLabels =
      allHaveSourceLabels;
  staged.surfaceCellContext.productSnapshots.hasAuthoritativeRails =
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
  staged.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed =
      anyComponentUsedSourceGridRecovery;
  staged.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeRelaxed =
      anyRecoveryTargetRelaxed;
  staged.surfaceCellContext.productSnapshots
      .sourceGridRecoveryTargetSizeMaxRelaxationRatio =
      maximumRecoveryTargetRelaxationRatio;
  const bool hasAggregateRecoveryTarget =
      allCompletedSurfaceCells && allComponentsUsedSourceGridRecovery &&
      allRecoveryTargetsAvailable && allReferencedRecoveryTargetsAssigned;
  staged.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize =
      hasAggregateRecoveryTarget;
  if (hasAggregateRecoveryTarget) {
    staged.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize =
        std::move(mergedRecoveryTargetSize);
  } else {
    staged.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize.resize(0);
  }
  staged.surfaceCellContext.completedVertices = staged.vertices;
  staged.surfaceCellContext.completedQuads =
      allCompletedSurfaceCells ? staged.faces : Eigen::MatrixXi{};
  staged.surfaceCellContext.completedProvenance =
      staged.outputVertexProvenance;
  staged.surfaceCellContext.completedVertexLineage =
      staged.outputVertexLineage;
  staged.surfaceCellContext.completedQuadLineage =
      staged.outputQuadLineage;
  staged.surfaceCellContext.hasCompletedPatches =
      allCompletedSurfaceCells && !aggregateCompletedPatches.empty();

  if (allCompletedSurfaceCells && allHaveOptimizationResult &&
      !firstOptimizationResult) {
    aggregateOptimizationResult.vertices = staged.vertices;
    aggregateOptimizationResult.quads = staged.faces;
    aggregateOptimizationResult.vertexProvenance =
        staged.outputVertexProvenance;
    staged.surfaceCellContext.productSnapshots.optimizationResult =
        std::move(aggregateOptimizationResult);
    staged.surfaceCellContext.productSnapshots.hasOptimizationResult = true;
  }
  if (allCompletedSurfaceCells && allHaveValidationResult &&
      !firstValidationResult) {
    aggregateValidationResult.strictValidationUsed =
        finalAuthorityValidation.strictValidationUsed;
    aggregateValidationResult.provenanceValidationUsed =
        finalAuthorityValidation.provenanceValidationUsed;
    aggregateValidationResult.sourceAuthoritativeValidationUsed =
        finalAuthorityValidation.sourceAuthorityUsed;
    aggregateValidationResult.spatialAccelerationUsed =
        finalAuthorityValidation.spatialAccelerationUsed;
    aggregateValidationResult.authoritativeBoundaryUsed =
        finalAuthorityValidation.boundaryAuthorityUsed;
    aggregateValidationResult.authoritativeFeatureRailsUsed =
        finalAuthorityValidation.featureRailAuthorityUsed;
    aggregateValidationResult.authoritativeFeatureRailsPassed =
        finalAuthorityValidation.featureRailsPassed;
    aggregateValidationResult.localSheetCompatibilityPassed =
        finalAuthorityValidation.localSheetCompatibilityPassed;
    aggregateValidationResult.orderedBoundaryCyclesPassed =
        finalAuthorityValidation.orderedBoundaryCyclesPassed;
    aggregateValidationResult.strictValidationIssues =
        finalAuthorityValidation.issues;
    aggregateValidationResult.accepted =
        aggregateValidationResult.accepted &&
        finalAuthorityValidation.accepted;
    staged.surfaceCellContext.productSnapshots.validationResult =
        std::move(aggregateValidationResult);
    staged.surfaceCellContext.productSnapshots.hasValidationResult = true;
  }

  staged.diagnostics.surfaceCellRemeshOccurred =
      allCompletedSurfaceCells;
  record_face_degree_histogram(staged);
  staged.diagnostics.componentMergeSeconds =
      remesh_elapsed_seconds(mergeStart);
  set_overall_pipeline_time(staged, pipelineStart);
  return std::move(staged).finish_produced(RemeshProductKind::Meshed, true);
}

} // namespace directional::pipeline

namespace directional::pipeline {

RemeshResult remesh_surface_cell_components_from_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options) {
  return remesh_surface_cell_components_from_cross_field_aggregate_impl(
      vertices, faces, authoritativeCrossField, options, nullptr, nullptr);
}

} // namespace directional::pipeline

namespace directional::pipeline::remesh_pipeline_detail {

RemeshResult remesh_surface_cell_components_from_cross_field_counterfactual(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options,
    const ComponentAggregationInputMutator &beforeAggregation) {
  return remesh_surface_cell_components_from_cross_field_aggregate_impl(
      vertices, faces, authoritativeCrossField, options, &beforeAggregation,
      nullptr);
}

RemeshResult
remesh_surface_cell_components_from_cross_field_final_validation_counterfactual(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const fields::CrossFieldResult &authoritativeCrossField,
    const RemeshOptions &options,
    const FinalAggregateValidationAuthorityMutator &beforeFinalValidation) {
  return remesh_surface_cell_components_from_cross_field_aggregate_impl(
      vertices, faces, authoritativeCrossField, options, nullptr,
      &beforeFinalValidation);
}

} // namespace directional::pipeline::remesh_pipeline_detail

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

  const ComponentFeatureOptionRemapPlan featureOptionRemap =
      make_component_feature_option_remap_plan(
          components, options.surfaceCells.featureMap.userHardEdges,
          options.surfaceCells.featureMap.userSoftEdges);
  if (featureOptionRemap.hardUnassigned > 0U) {
    RemeshResultBuilder rejected;
    rejected.diagnostics.remeshBackend = remesh_backend_name(options.backend);
    rejected.diagnostics.requestedBackend = remesh_backend_name(options.backend);
    rejected.diagnostics.executedBackend = remesh_backend_name(options.backend);
    rejected.diagnostics.surfaceCellFallbackPolicy =
        surface_cell_fallback_policy_name(options.surfaceCells.fallbackPolicy);
    rejected.diagnostics.componentSplitSeconds = splitSeconds;
    rejected.diagnostics.componentCount = components.size();
    publish_component_feature_option_remap_diagnostics(
        rejected.diagnostics, featureOptionRemap);
    rejected.diagnostics.terminalFailureCode =
        surface_cell_failure_code_name(SurfaceCellFailureCode::NotProductionReady);
    rejected.diagnostics.terminalFailureStage = "component-feature-remap";
    rejected.diagnostics.surfaceCellFirstInvalidProducerStage =
        "component-feature-remap";
    rejected.diagnostics.surfaceCellFirstInvalidProducerReason =
        "UnassignedUserHardFeatureEdge";
    rejected.diagnostics.surfaceCellFirstInvalidProducerEdgeFirst =
        featureOptionRemap.firstUnassignedHard.first;
    rejected.diagnostics.surfaceCellFirstInvalidProducerEdgeSecond =
        featureOptionRemap.firstUnassignedHard.second;
    set_overall_pipeline_time(rejected, pipelineStart);
    RemeshFailure failure;
    failure.kind = RemeshFailureKind::ComponentRejected;
    failure.surfaceCellFailure = SurfaceCellFailureCode::NotProductionReady;
    failure.stage = "component-feature-remap";
    failure.crossFieldAccepted = false;
    return std::move(rejected).finish_rejected(std::move(failure));
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
      apply_component_feature_option_remap(featureOptionRemap, componentIndex,
                                           componentOptions);
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
  RemeshResultBuilder merged;
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
  publish_component_feature_option_remap_diagnostics(
      merged.diagnostics, featureOptionRemap);
  bool allCrossFieldsAccepted = true;
  bool anyComponentRejected = false;

  for (std::size_t index = 0; index < components.size(); ++index) {
    const geometry::FaceComponent &component = components[index];
    directional::ComponentRemeshDiagnostics componentDiagnostics;
    componentDiagnostics.componentIndex = index;
    componentDiagnostics.minimumOriginalFace =
        static_cast<std::size_t>(component.minimum_original_face());
    componentDiagnostics.inputFaceCount = component.originalFaces.size();
    componentDiagnostics.success =
        !runs[index].threw && runs[index].result.is_produced();
    componentDiagnostics.wallSeconds = runs[index].wallSeconds;
    componentDiagnostics.integrationSeconds =
        runs[index].result.diagnostics.integrationTotalSeconds;
    componentDiagnostics.mesherSeconds =
        runs[index].result.diagnostics.mesherTotalSeconds;
    const RemeshProduct *componentProduct =
        componentDiagnostics.success ? &runs[index].result.product() : nullptr;
    componentDiagnostics.outputVertexCount =
        componentProduct == nullptr
            ? 0U
            : static_cast<std::size_t>(componentProduct->vertices.rows());
    componentDiagnostics.outputFaceCount =
        componentProduct == nullptr
            ? 0U
            : static_cast<std::size_t>(componentProduct->faces.rows());
    merged.diagnostics.components.push_back(componentDiagnostics);
    accumulate_component_diagnostics(
        merged.diagnostics, runs[index].result.diagnostics, index, index == 0U);

    if (!componentDiagnostics.success) {
      anyComponentRejected = true;
      allCrossFieldsAccepted =
          allCrossFieldsAccepted && runs[index].result.cross_field_accepted();
      merged.diagnostics.failedComponentIndex = index;
      merged.diagnostics.failedComponentMinimumOriginalFace =
          componentDiagnostics.minimumOriginalFace;
      break;
    }

    allCrossFieldsAccepted =
        allCrossFieldsAccepted && runs[index].result.cross_field_accepted();
    const int outputVertexOffset = static_cast<int>(merged.vertices.rows());
    append_matrix_rows(merged.vertices, componentProduct->vertices);
    append_matrix_rows(merged.faces, componentProduct->faces,
                       outputVertexOffset);
    append_vector(merged.degrees, componentProduct->degrees);

    const int cutVertexOffset = static_cast<int>(merged.cutVertices.rows());
    append_matrix_rows(merged.cutVertices, componentProduct->cutVertices);
    append_matrix_rows(merged.cutFaces, componentProduct->cutFaces,
                       cutVertexOffset);
    append_matrix_rows(merged.cutFunctions, componentProduct->cutFunctions);
    append_matrix_rows(merged.cutCornerFunctions,
                       componentProduct->cutCornerFunctions);
    append_matrix_rows(merged.rawCrossField, componentProduct->rawCrossField);
    append_vector(merged.crossFieldMatching,
                  componentProduct->crossFieldMatching);
    append_vector(merged.crossFieldEffort, componentProduct->crossFieldEffort);
    append_vector(merged.crossFieldSingularCycles,
                  componentProduct->crossFieldSingularCycles);
    append_vector(merged.crossFieldSingularIndices,
                  componentProduct->crossFieldSingularIndices);

  }

  merged.diagnostics.componentMergeSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            mergeStart)
          .count() /
      1.0e6;
  clear_unavailable_surface_cell_counts(merged.diagnostics);
  set_overall_pipeline_time(merged, pipelineStart);
  if (anyComponentRejected) {
    RemeshFailure failure;
    failure.kind = RemeshFailureKind::ComponentRejected;
    failure.stage = "component-execution";
    failure.crossFieldAccepted = allCrossFieldsAccepted;
    return std::move(merged).finish_rejected(std::move(failure));
  }
  return std::move(merged).finish_produced(
      options.stopAfterIntegration ? RemeshProductKind::IntegrationOnly
                                   : RemeshProductKind::Meshed,
      allCrossFieldsAccepted);
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
          meshWhole, rawCrossField, sequentialOptions, nullptr);
    }
  } else if (options.parallelizeComponents) {
    result = remesh_components_from_raw_cross_field(
        vertices, faces, rawCrossField, options);
  } else {
    TriMesh meshWhole;
    meshWhole.set_mesh(vertices, faces);
    result = remesh_from_raw_cross_field_impl(meshWhole, rawCrossField, options, nullptr);
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

  const bool crossFieldWasAccepted = result.cross_field_accepted();
  if (result.is_produced() &&
      !result.diagnostics.surfaceCellUsedLegacyFallback &&
      crossFieldWasAccepted) {
    RemeshProduct &product = result.product();
    product.crossFieldMatching = crossField.matching;
    product.crossFieldEffort = crossField.effort;
    product.crossFieldSingularCycles = crossField.singularCycles;
    product.crossFieldSingularIndices = crossField.singularIndices;
  }
  if (surfaceCellsRequested && crossFieldWasAccepted) {
    fields::CrossFieldResult diagnosticCrossField = crossField;
    normalize_surface_cell_cross_field_directions(diagnosticCrossField);
    result.surfaceCellContext.crossFieldHasMatching =
        diagnosticCrossField.matchingComputed;
    result.surfaceCellContext.crossFieldHasSingularities =
        diagnosticCrossField.singularitiesComputed;
    result.surfaceCellContext.productSnapshots.crossField =
        std::move(diagnosticCrossField);
    result.surfaceCellContext.productSnapshots.hasCrossField = true;
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
