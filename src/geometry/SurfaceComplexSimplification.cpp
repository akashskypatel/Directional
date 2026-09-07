#include <directional/geometry/SurfaceComplexSimplification.h>

namespace directional::geometry::surface_simplification_detail {

std::int64_t rail_id_leaf(const std::optional<authority::HardRailId> &rail) {
  return rail.has_value() ? static_cast<std::int64_t>(rail->index()) : -1;
}

bool element_protected(const SurfaceSimplificationElement &element) {
  return element.hardFeature || element.boundary || element.basinRoot ||
         element.rootLabelProtected || element.singularityProtected;
}















void append_source_scope_identity(
    SourceAwareIdentity &identity,
    const std::optional<authority::TopologyRegionId> &region,
    const std::optional<SourceProjectionChart> &chart) {
  identity.sourceScopes.push_back({region, chart});
}


} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

std::uint64_t structural_hash(
    const std::vector<SurfaceSimplificationElement> &elements) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  for (const SurfaceSimplificationElement &element : elements) {
    mix(element.id);
    mix(element.active ? 1 : 0);
    mix(element.hardFeature ? 1 : 0);
    mix(element.boundary ? 1 : 0);
    mix(element.basinRoot ? 1 : 0);
    mix(element.rootLabelProtected ? 1 : 0);
    mix(element.singularityProtected ? 1 : 0);
    mix(element.handleCritical ? 1 : 0);
  }
  return hash;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

std::uint64_t complex_structural_hash(const SurfaceCellComplex &complex) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  const auto mix_scope = [&](
      const std::optional<authority::TopologyRegionId> &region,
      const std::optional<SourceProjectionChart> &chart) {
    mix(region.has_value() ? static_cast<std::int64_t>(region->index()) : -1);
    if (!chart.has_value()) { mix(-1); return; }
    mix(static_cast<std::int64_t>(chart->chart.index()));
    for (const authority::SourceVertexId vertex : chart->face.vertices()) {
      mix(static_cast<std::int64_t>(vertex.index()));
    }
  };
  const auto mix_required_chart = [&](const SourceProjectionChart &chart) {
    mix(static_cast<std::int64_t>(chart.chart.index()));
    for (const authority::SourceVertexId vertex : chart.face.vertices()) {
      mix(static_cast<std::int64_t>(vertex.index()));
    }
  };
  mix(static_cast<int>(complex.nodes.size()));
  mix(static_cast<int>(complex.halfedges.size()));
  mix(static_cast<int>(complex.cells.size()));
  mix(static_cast<int>(complex.sourceOwnershipRegistry.size()));
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    mix(record.sourceTopologyRegion.has_value() ? static_cast<std::int64_t>(record.sourceTopologyRegion->index()) : -1);
    for (const SourceProjectionChart &chart : record.exactCharts) {
      mix_required_chart(chart);
    }
  }
  for (const SurfaceArrangementNode &node : complex.nodes) {
    mix(node.id);
    mix(node.sourceFace);
    mix(node.hardBarrierCrossing ? 1 : 0);
    mix(node.sourceEdge);
    mix(static_cast<std::int64_t>(
        std::llround(node.sourceEdgeParameter * 1.0e10)));
    for (int i = 0; i < 3; ++i) {
      mix(static_cast<std::int64_t>(std::llround(node.barycentric[i] * 1.0e10)));
    }
    mix(static_cast<int>(node.occurrences.size()));
    for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
      mix(occurrence.sourceFace);
      mix_scope(occurrence.sourceTopologyRegion, occurrence.sourceChart);
      mix(occurrence.sourceArc);
      mix(occurrence.provenance);
      mix(rail_id_leaf(occurrence.railId));
      mix(occurrence.curveId);
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.sourceT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.sourceT1 * 1.0e10)));
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.railT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(
          std::llround(occurrence.railT1 * 1.0e10)));
      for (int i = 0; i < 3; ++i) {
        mix(static_cast<std::int64_t>(
            std::llround(occurrence.barycentric[i] * 1.0e10)));
      }
    }
  }
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    mix(halfedge.id);
    mix(halfedge.twin);
    mix(halfedge.next);
    mix(halfedge.from);
    mix(halfedge.to);
    mix(halfedge.sourceArc);
    mix(halfedge.family);
    mix(halfedge.strand);
    mix(halfedge.featureClass);
    mix(halfedge.sourceFace);
    mix(static_cast<std::int64_t>(std::llround(halfedge.sourceT0 * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(halfedge.sourceT1 * 1.0e10)));
    mix(halfedge.hardFeature ? 1 : 0);
    mix(halfedge.layoutSupport ? 1 : 0);
    mix(halfedge.singularitySupport ? 1 : 0);
    mix(rail_id_leaf(halfedge.railId));
    mix(halfedge.curveId);
    mix_scope(halfedge.sourceTopologyRegion, halfedge.sourceChart);
    mix(halfedge.proposalId);
    mix(halfedge.proposalSeedId);
    mix(halfedge.proposalSide);
    mix(halfedge.proposalBoundarySegment);
    mix(static_cast<std::int64_t>(std::llround(halfedge.railT0 * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(halfedge.railT1 * 1.0e10)));
    mix(static_cast<int>(halfedge.provenance.size()));
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      mix(value.sourceArc);
      mix(value.provenance);
      mix(value.sourceFace);
      mix(value.family);
      mix(value.strand);
      mix(value.featureClass);
      mix(value.hardFeature ? 1 : 0);
      mix(value.layoutSupport ? 1 : 0);
      mix(value.singularitySupport ? 1 : 0);
      mix(rail_id_leaf(value.railId));
      mix(value.curveId);
      mix_scope(value.sourceTopologyRegion, value.sourceChart);
      mix(value.proposalId);
      mix(value.proposalSeedId);
      mix(value.proposalSide);
      mix(value.proposalBoundarySegment);
      mix(static_cast<std::int64_t>(std::llround(value.sourceT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.sourceT1 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.railT0 * 1.0e10)));
      mix(static_cast<std::int64_t>(std::llround(value.railT1 * 1.0e10)));
    }
    mix(halfedge.cell);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    mix(cell.id);
    mix(cell.sourceFace);
    mix(cell.sourceTopologyRegion.has_value()
            ? static_cast<std::int64_t>(cell.sourceTopologyRegion->index())
            : -1);
    mix(surface_cell_ownership_class_representation_leaf(
        cell.sourceOwnershipClass));
    for (const SourceProjectionChart &chart : cell.sourceCharts) {
      mix_required_chart(chart);
    }
    for (const int sourceFace : cell.sourceFaces) {
      mix(sourceFace);
    }
    mix(static_cast<int>(cell.cellClass));
    mix(static_cast<int>(cell.rejectReason));
    mix(cell.closed ? 1 : 0);
    mix(cell.boundaryCycle ? 1 : 0);
    mix(cell.disk ? 1 : 0);
    mix(cell.cutCellDisk ? 1 : 0);
    mix(cell.bridgeExcursion ? 1 : 0);
    mix(cell.supportOnlyCycle ? 1 : 0);
    mix(cell.sourceBoundarySide);
    for (const int loop : cell.sourceBoundaryLoopIds) {
      mix(loop);
    }
    mix(cell.boundaryComponentCount);
    mix(cell.eulerCharacteristic);
    mix(cell.quadReady ? 1 : 0);
    mix(static_cast<std::int64_t>(std::llround(cell.signedArea * 1.0e10)));
    mix(static_cast<std::int64_t>(std::llround(cell.area * 1.0e10)));
    for (const int halfedge : cell.halfedges) {
      mix(halfedge);
    }
    for (const int offset : cell.boundaryCycleOffsets) {
      mix(offset);
    }
    for (const int family : cell.sideFamilies) {
      mix(family);
    }
    for (const int count : cell.sideEdgeCounts) {
      mix(count);
    }
  }
  mix(complex.diagnostics.eulerCharacteristic);
  mix(complex.diagnostics.connectedComponentCount);
  mix(complex.diagnostics.boundaryLoopCount);
  mix(complex.diagnostics.directedWedgeCount);
  mix(complex.diagnostics.successorMissingCount);
  mix(complex.diagnostics.successorAmbiguityCount);
  mix(complex.diagnostics.predecessorMultiplicityFailureCount);
  mix(complex.diagnostics.repeatedNodeCycleCount);
  mix(complex.diagnostics.repeatedEdgeCycleCount);
  mix(static_cast<int>(complex.diagnostics.incidenceFailure));
  mix(complex.diagnostics.incidenceFailureNode);
  mix(complex.diagnostics.incidenceFailureHalfedge);
  mix(complex.diagnostics.incidenceFailureTwin);
  mix(complex.diagnostics.incidenceFailureNext);
  mix(static_cast<std::int64_t>(complex.diagnostics.directedIncidenceHash));
  mix(complex.diagnostics.incidenceValid ? 1 : 0);
  mix(complex.diagnostics.embeddingValid ? 1 : 0);
  mix(complex.diagnostics.orientationValid ? 1 : 0);
  mix(complex.diagnostics.cellsDiskValid ? 1 : 0);
  mix(complex.diagnostics.boundaryLoopsValid ? 1 : 0);
  mix(complex.diagnostics.eulerCharacteristicValid ? 1 : 0);
  mix(complex.diagnostics.topologyValid ? 1 : 0);
  return hash;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

int active_count(const std::vector<SurfaceSimplificationElement> &elements) {
  return static_cast<int>(std::count_if(
      elements.begin(), elements.end(),
      [](const SurfaceSimplificationElement &element) { return element.active; }));
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

double objective_cost(
    const SurfaceSimplificationCandidate &candidate,
    const SurfaceSimplificationObjectiveWeights &weights) {
  if (candidate.changesTopology) {
    return std::numeric_limits<double>::infinity();
  }
  return weights.surface * candidate.deltaSurface +
         weights.normal * candidate.deltaNormal +
         weights.field * candidate.deltaField +
         weights.size * candidate.deltaSize +
         weights.quad * candidate.deltaQuad +
         weights.feature * candidate.featurePenalty +
         weights.topology * candidate.topologyPenalty;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

SurfaceSimplificationRejectionReason validate_candidate(
    const SurfaceSimplificationCandidate &candidate,
    const std::vector<SurfaceSimplificationElement> &elements,
    const SurfaceSimplificationOptions &options, const double cost) {
  if (candidate.invalidated) {
    return SurfaceSimplificationRejectionReason::StaleCandidate;
  }
  for (const int elementId : candidate.elementIds) {
    if (elementId < 0 || elementId >= static_cast<int>(elements.size()) ||
        !elements[static_cast<std::size_t>(elementId)].active) {
      return SurfaceSimplificationRejectionReason::StaleCandidate;
    }
    const SurfaceSimplificationElement &element =
        elements[static_cast<std::size_t>(elementId)];
    if (element.hardFeature) {
      return SurfaceSimplificationRejectionReason::ProtectedFeature;
    }
    if (element.boundary) {
      return SurfaceSimplificationRejectionReason::ProtectedBoundary;
    }
    if (element.basinRoot || element.rootLabelProtected) {
      return SurfaceSimplificationRejectionReason::ProtectedRoot;
    }
    if (element.singularityProtected) {
      return SurfaceSimplificationRejectionReason::ProtectedSingularity;
    }
    if (element.handleCritical) {
      return SurfaceSimplificationRejectionReason::TopologyChanged;
    }
  }
  if (candidate.changesTopology || !std::isfinite(cost)) {
    return SurfaceSimplificationRejectionReason::TopologyChanged;
  }
  if (!candidate.affectedPatchDisk) {
    return SurfaceSimplificationRejectionReason::NonDiskPatch;
  }
  if (!candidate.sideFeasible) {
    return SurfaceSimplificationRejectionReason::PatchInfeasible;
  }
  if (candidate.descriptivenessWorsening >
      options.maxDescriptivenessWorsening + 1.0e-14) {
    return SurfaceSimplificationRejectionReason::DescriptivenessWorsened;
  }
  if (cost > options.objectiveTolerance + 1.0e-14) {
    return SurfaceSimplificationRejectionReason::ObjectiveWorsened;
  }
  return SurfaceSimplificationRejectionReason::None;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

SurfaceCellIncidenceAudit audit_complex_incidence(
    const SurfaceCellComplex &complex, const bool requireDiskCells) {
  SurfaceCellIncidenceAudit audit;
  for (int i = 0; i < static_cast<int>(complex.nodes.size()); ++i) {
    if (complex.nodes[static_cast<std::size_t>(i)].id != i) {
      audit.failure = SurfaceCellIncidenceFailureKind::NodeIdMismatch;
      audit.node = i;
      audit.expected = i;
      audit.actual = complex.nodes[static_cast<std::size_t>(i)].id;
      return audit;
    }
  }
  if (!complex.sourceOwnershipRegistry.empty() &&
      !validate_surface_cell_ownership_registry(complex)) {
    audit.failure = SurfaceCellIncidenceFailureKind::OwnershipRegistryMismatch;
    return audit;
  }

  std::vector<int> halfedgeUse(complex.halfedges.size(), 0);
  std::vector<int> predecessorUse(complex.halfedges.size(), 0);
  std::set<std::tuple<int, int, int>> directedIncidence;
  for (int i = 0; i < static_cast<int>(complex.halfedges.size()); ++i) {
    const SurfaceArrangementHalfedge &halfedge =
        complex.halfedges[static_cast<std::size_t>(i)];
    audit.halfedge = i;
    audit.twin = halfedge.twin;
    audit.next = halfedge.next;
    audit.cell = halfedge.cell;
    if (halfedge.id != i) {
      audit.failure = SurfaceCellIncidenceFailureKind::HalfedgeIdMismatch;
      audit.expected = i;
      audit.actual = halfedge.id;
      return audit;
    }
    if (halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size())) {
      audit.failure = SurfaceCellIncidenceFailureKind::InvalidTwin;
      return audit;
    }
    if (halfedge.from < 0 ||
        halfedge.from >= static_cast<int>(complex.nodes.size()) ||
        halfedge.to < 0 ||
        halfedge.to >= static_cast<int>(complex.nodes.size())) {
      audit.failure = SurfaceCellIncidenceFailureKind::InvalidEndpoint;
      audit.node = halfedge.from < 0 ||
                           halfedge.from >= static_cast<int>(complex.nodes.size())
                       ? halfedge.from
                       : halfedge.to;
      return audit;
    }
    if (halfedge.from == halfedge.to) {
      audit.failure = SurfaceCellIncidenceFailureKind::DegenerateEdge;
      audit.node = halfedge.from;
      return audit;
    }
    if (halfedge.cell < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size())) {
      audit.failure = SurfaceCellIncidenceFailureKind::InvalidCell;
      return audit;
    }
    if (halfedge.next < 0 ||
        halfedge.next >= static_cast<int>(complex.halfedges.size())) {
      audit.failure = SurfaceCellIncidenceFailureKind::InvalidNext;
      return audit;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (twin.twin != i || twin.from != halfedge.to ||
        twin.to != halfedge.from) {
      audit.failure = SurfaceCellIncidenceFailureKind::TwinAsymmetry;
      audit.expected = i;
      audit.actual = twin.twin;
      return audit;
    }
    const SurfaceArrangementHalfedge &next =
        complex.halfedges[static_cast<std::size_t>(halfedge.next)];
    if (next.from != halfedge.to) {
      audit.failure = SurfaceCellIncidenceFailureKind::NextEndpointMismatch;
      audit.node = halfedge.to;
      audit.expected = halfedge.to;
      audit.actual = next.from;
      return audit;
    }
    ++predecessorUse[static_cast<std::size_t>(halfedge.next)];
    if (!directedIncidence.emplace(halfedge.cell, halfedge.from,
                                   halfedge.to)
             .second) {
      audit.failure =
          SurfaceCellIncidenceFailureKind::DirectedEdgeMultiplicity;
      return audit;
    }
  }

  for (int i = 0; i < static_cast<int>(complex.halfedges.size()); ++i) {
    if (predecessorUse[static_cast<std::size_t>(i)] != 1) {
      audit.failure = SurfaceCellIncidenceFailureKind::PredecessorMultiplicity;
      audit.halfedge = i;
      audit.expected = 1;
      audit.actual = predecessorUse[static_cast<std::size_t>(i)];
      return audit;
    }
  }

  for (int i = 0; i < static_cast<int>(complex.cells.size()); ++i) {
    const SurfaceArrangementCell &cell =
        complex.cells[static_cast<std::size_t>(i)];
    audit.cell = i;
    if (cell.id != i) {
      audit.failure = SurfaceCellIncidenceFailureKind::CellIdMismatch;
      audit.expected = i;
      audit.actual = cell.id;
      return audit;
    }
    if (!cell.closed) {
      audit.failure = SurfaceCellIncidenceFailureKind::CellNotClosed;
      return audit;
    }
    const bool validSupportOnlyCycle =
        cell.supportOnlyCycle && cell.halfedges.size() == 2U &&
        complex.halfedges[static_cast<std::size_t>(cell.halfedges[0])].twin ==
            cell.halfedges[1] &&
        complex.halfedges[static_cast<std::size_t>(cell.halfedges[1])].twin ==
            cell.halfedges[0];
    if (cell.halfedges.size() < 3U && !validSupportOnlyCycle) {
      audit.failure = SurfaceCellIncidenceFailureKind::CellTooSmall;
      audit.actual = static_cast<int>(cell.halfedges.size());
      return audit;
    }
    if (requireDiskCells && !cell.boundaryCycle &&
        (!cell.disk || cell.boundaryComponentCount != 1 ||
         cell.eulerCharacteristic != 1)) {
      audit.failure = SurfaceCellIncidenceFailureKind::NonDiskCell;
      return audit;
    }
    if (cell.sideFamilies.size() != cell.sideEdgeCounts.size()) {
      audit.failure = SurfaceCellIncidenceFailureKind::SideMetadataMismatch;
      return audit;
    }
    std::vector<std::pair<std::size_t, std::size_t>> boundaryRanges;
    if (!surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges)) {
      audit.failure = SurfaceCellIncidenceFailureKind::CellNotClosed;
      return audit;
    }
    std::set<int> seen;
    for (const auto &[begin, end] : boundaryRanges) {
      for (std::size_t j = begin; j < end; ++j) {
        const int halfedgeId = cell.halfedges[j];
        audit.halfedge = halfedgeId;
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(complex.halfedges.size())) {
          audit.failure = SurfaceCellIncidenceFailureKind::InvalidNext;
          return audit;
        }
        if (!seen.insert(halfedgeId).second) {
          audit.failure =
              SurfaceCellIncidenceFailureKind::RepeatedCellHalfedge;
          return audit;
        }
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        const int expectedNext =
            cell.halfedges[j + 1U < end ? j + 1U : begin];
        if (halfedge.cell != i) {
          audit.failure =
              SurfaceCellIncidenceFailureKind::HalfedgeCellMismatch;
          audit.expected = i;
          audit.actual = halfedge.cell;
          return audit;
        }
        if (halfedge.next != expectedNext) {
          audit.failure = SurfaceCellIncidenceFailureKind::CellNextMismatch;
          audit.expected = expectedNext;
          audit.actual = halfedge.next;
          return audit;
        }
        if (halfedge.to !=
            complex.halfedges[static_cast<std::size_t>(expectedNext)].from) {
          audit.failure =
              SurfaceCellIncidenceFailureKind::NextEndpointMismatch;
          audit.expected = halfedge.to;
          audit.actual =
              complex.halfedges[static_cast<std::size_t>(expectedNext)].from;
          return audit;
        }
        ++halfedgeUse[static_cast<std::size_t>(halfedgeId)];
      }
    }
  }
  for (int i = 0; i < static_cast<int>(halfedgeUse.size()); ++i) {
    if (halfedgeUse[static_cast<std::size_t>(i)] != 1) {
      audit.failure = SurfaceCellIncidenceFailureKind::HalfedgeUseMismatch;
      audit.halfedge = i;
      audit.expected = 1;
      audit.actual = halfedgeUse[static_cast<std::size_t>(i)];
      return audit;
    }
  }
  audit.valid = true;
  audit.failure = SurfaceCellIncidenceFailureKind::None;
  audit.node = audit.halfedge = audit.twin = audit.next = audit.cell = -1;
  audit.expected = audit.actual = -1;
  return audit;
}

bool validate_complex_incidence(const SurfaceCellComplex &complex,
                                const bool requireDiskCells) {
  return audit_complex_incidence(complex, requireDiskCells).valid;
}
} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

int non_disk_topology_defect(const SurfaceCellComplex &complex) {
  int defect = 0;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (cell.boundaryCycle || cell.disk) {
      continue;
    }
    // A pinched face repeats nodes in its DCEL walk and therefore has
    // chi <= 0. Count the missing disk Euler characteristic, with a minimum
    // unit penalty for any other non-disk representation.
    defect += std::max(1, 1 - cell.eulerCharacteristic);
  }
  return defect;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

std::vector<std::int64_t> protected_node_signature(
    const SurfaceArrangementNode &node) {
  std::vector<std::int64_t> signature;
  signature.push_back(static_cast<std::int64_t>(node.occurrences.size()));
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    signature.push_back(occurrence.sourceFace);
    for (int i = 0; i < 3; ++i) {
      signature.push_back(static_cast<std::int64_t>(
          std::llround(occurrence.barycentric[i] * 1.0e10)));
    }
  }
  return signature;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

std::multiset<SourceAwareIdentity> protected_support(
    const SurfaceCellComplex &complex) {
  std::multiset<SourceAwareIdentity> keys;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin ||
        (!halfedge.hardFeature && halfedge.family >= 0 &&
         !halfedge.singularitySupport)) {
      continue;
    }
    if (halfedge.from < 0 || halfedge.to < 0 ||
        halfedge.from >= static_cast<int>(complex.nodes.size()) ||
        halfedge.to >= static_cast<int>(complex.nodes.size())) {
      SourceAwareIdentity invalid;
      invalid.values.push_back(std::numeric_limits<std::int64_t>::min());
      keys.insert(std::move(invalid));
      continue;
    }
    std::vector<std::int64_t> from = protected_node_signature(
        complex.nodes[static_cast<std::size_t>(halfedge.from)]);
    std::vector<std::int64_t> to = protected_node_signature(
        complex.nodes[static_cast<std::size_t>(halfedge.to)]);
    if (to < from) {
      std::swap(from, to);
    }

    std::vector<SourceAwareIdentity> provenanceKeys;
    provenanceKeys.reserve(halfedge.provenance.size());
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      const double sourceLo = std::min(value.sourceT0, value.sourceT1);
      const double sourceHi = std::max(value.sourceT0, value.sourceT1);
      const double railLo = std::min(value.railT0, value.railT1);
      const double railHi = std::max(value.railT0, value.railT1);
      SourceAwareIdentity provenanceKey;
      provenanceKey.values = {
          value.sourceArc, value.provenance, value.sourceFace, value.family,
          value.strand, value.featureClass, value.hardFeature ? 1 : 0,
          value.layoutSupport ? 1 : 0, value.singularitySupport ? 1 : 0,
          rail_id_leaf(value.railId), value.curveId};
      append_source_scope_identity(provenanceKey, value.sourceTopologyRegion,
                                   value.sourceChart);
      provenanceKey.values.insert(provenanceKey.values.end(),
          {value.proposalId, value.proposalSeedId, value.proposalSide,
           value.proposalBoundarySegment,
           static_cast<std::int64_t>(std::llround(sourceLo * 1.0e10)),
           static_cast<std::int64_t>(std::llround(sourceHi * 1.0e10)),
           static_cast<std::int64_t>(std::llround(railLo * 1.0e10)),
           static_cast<std::int64_t>(std::llround(railHi * 1.0e10))});
      provenanceKeys.push_back(std::move(provenanceKey));
    }
    std::sort(provenanceKeys.begin(), provenanceKeys.end());

    SourceAwareIdentity key;
    key.values = {
        halfedge.hardFeature ? 1 : 0,
        halfedge.family < 0 ? 1 : 0,
        static_cast<std::int64_t>(from.size())};
    key.values.insert(key.values.end(), from.begin(), from.end());
    key.values.push_back(static_cast<std::int64_t>(to.size()));
    key.values.insert(key.values.end(), to.begin(), to.end());
    key.values.push_back(static_cast<std::int64_t>(provenanceKeys.size()));
    for (const SourceAwareIdentity &provenance : provenanceKeys) {
      key.values.push_back(static_cast<std::int64_t>(provenance.values.size()));
      key.values.insert(key.values.end(), provenance.values.begin(),
                        provenance.values.end());
      key.sourceScopes.insert(key.sourceScopes.end(),
                              provenance.sourceScopes.begin(),
                              provenance.sourceScopes.end());
    }
    keys.insert(std::move(key));
  }
  return keys;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

bool same_protected_support(const SurfaceCellComplex &before,
                                   const SurfaceCellComplex &after) {
  return protected_support(before) == protected_support(after);
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

bool order_boundary_cycle(const SurfaceCellComplex &complex,
                                 const std::vector<int> &input,
                                 std::vector<int> &ordered) {
  if (input.size() < 3) return false;
  std::map<int, std::vector<int>> outgoing;
  for (int hid : input) {
    if (hid < 0 || hid >= static_cast<int>(complex.halfedges.size())) return false;
    outgoing[complex.halfedges[static_cast<std::size_t>(hid)].from].push_back(hid);
  }
  for (auto &[node, ids] : outgoing) {
    std::sort(ids.begin(), ids.end());
    if (ids.size() != 1) return false;
  }
  ordered.clear();
  std::set<int> used;
  int current = *std::min_element(input.begin(), input.end());
  for (std::size_t i = 0; i < input.size(); ++i) {
    if (!used.insert(current).second) return false;
    ordered.push_back(current);
    const int node = complex.halfedges[static_cast<std::size_t>(current)].to;
    const auto it = outgoing.find(node);
    if (it == outgoing.end() || it->second.size() != 1) return false;
    current = it->second.front();
  }
  return current == ordered.front() && used.size() == input.size();
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

void classify_rebuilt_cell_sides(
    SurfaceArrangementCell &cell, const SurfaceCellComplex &complex,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces) {
  cell.sideFamilies.clear();
  cell.sideEdgeCounts.clear();
  for (std::size_t index = 0; index < cell.halfedges.size(); ++index) {
    const SurfaceArrangementHalfedge &current =
        complex.halfedges[static_cast<std::size_t>(cell.halfedges[index])];
    bool continuesPrevious = false;
    if (index > 0U && !cell.sideFamilies.empty() &&
        cell.sideFamilies.back() == current.family) {
      const SurfaceArrangementHalfedge &previous =
          complex.halfedges[static_cast<std::size_t>(
              cell.halfedges[index - 1U])];
      continuesPrevious =
          vertices != nullptr && faces != nullptr
              ? surface_arrangement_detail::same_family_collinear(
                    previous, current, complex.nodes, *vertices, *faces)
              : previous.strand == current.strand;
    }
    if (continuesPrevious) {
      ++cell.sideEdgeCounts.back();
    } else {
      cell.sideFamilies.push_back(current.family);
      cell.sideEdgeCounts.push_back(1);
    }
  }
  if (cell.sideFamilies.size() > 1U &&
      cell.sideFamilies.front() == cell.sideFamilies.back()) {
    const SurfaceArrangementHalfedge &last =
        complex.halfedges[static_cast<std::size_t>(cell.halfedges.back())];
    const SurfaceArrangementHalfedge &first =
        complex.halfedges[static_cast<std::size_t>(cell.halfedges.front())];
    const bool closesSameSide =
        vertices != nullptr && faces != nullptr
            ? surface_arrangement_detail::same_family_collinear(
                  last, first, complex.nodes, *vertices, *faces)
            : last.strand == first.strand;
    if (closesSameSide) {
      cell.sideEdgeCounts.front() += cell.sideEdgeCounts.back();
      cell.sideEdgeCounts.pop_back();
      cell.sideFamilies.pop_back();
    }
  }
  cell.quadReady = !cell.boundaryCycle && cell.disk &&
                   cell.sideFamilies.size() == 4U;
  if (cell.boundaryCycle) {
    cell.cellClass = SurfaceArrangementCellClass::Exterior;
    cell.rejectReason = SurfaceArrangementRejectReason::None;
  } else if (!cell.disk) {
    cell.cellClass = SurfaceArrangementCellClass::NonDisk;
    cell.rejectReason = SurfaceArrangementRejectReason::NotFourSided;
  } else if (cell.quadReady) {
    cell.cellClass = SurfaceArrangementCellClass::RegularQuad;
    cell.rejectReason = SurfaceArrangementRejectReason::None;
  } else {
    cell.cellClass = SurfaceArrangementCellClass::PatchCandidate;
    cell.rejectReason = SurfaceArrangementRejectReason::NotFourSided;
  }
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

void recompute_rebuilt_diagnostics(SurfaceCellComplex &complex) {
  const int undirectedEdges = static_cast<int>(complex.halfedges.size()) / 2;
  const int boundedEulerContribution = std::accumulate(
      complex.cells.begin(), complex.cells.end(), 0,
      [](const int sum, const SurfaceArrangementCell &cell) {
        return sum + (!cell.boundaryCycle && !cell.supportOnlyCycle
                          ? cell.eulerCharacteristic
                          : 0);
      });
  complex.diagnostics.eulerCharacteristic =
      static_cast<int>(complex.nodes.size()) - undirectedEdges +
      boundedEulerContribution;

  std::vector<std::pair<int, int>> arrangementEdges;
  std::vector<std::pair<int, int>> arrangementBoundaryEdges;
  arrangementEdges.reserve(static_cast<std::size_t>(undirectedEdges));
  bool orientationValid = true;
  bool cellsDiskValid = true;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id >= halfedge.twin) {
      continue;
    }
    arrangementEdges.emplace_back(halfedge.from, halfedge.to);
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell >= 0 && twin.cell >= 0 &&
        halfedge.cell < static_cast<int>(complex.cells.size()) &&
        twin.cell < static_cast<int>(complex.cells.size())) {
      const bool leftExterior =
          complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle;
      const bool rightExterior =
          complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle;
      if (leftExterior != rightExterior) {
        arrangementBoundaryEdges.emplace_back(halfedge.from, halfedge.to);
      }
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.boundaryCycle && !cell.disk) {
      cellsDiskValid = false;
    }
    if (!cell.supportOnlyCycle &&
        (cell.boundaryCycle ? !(cell.signedArea < -1.0e-14)
                            : !(cell.signedArea > 1.0e-14))) {
      if (cell.rejectReason != SurfaceArrangementRejectReason::Sliver) {
        orientationValid = false;
      }
    }
  }

  complex.diagnostics.incidenceValid = validate_complex_incidence(complex);
  if (complex.diagnostics.incidenceValid) {
    complex.diagnostics.incidenceFailure =
        SurfaceArrangementIncidenceFailure::None;
    complex.diagnostics.incidenceFailureNode = -1;
    complex.diagnostics.incidenceFailureHalfedge = -1;
    complex.diagnostics.incidenceFailureTwin = -1;
    complex.diagnostics.incidenceFailureNext = -1;
    complex.diagnostics.successorMissingCount = 0;
    complex.diagnostics.successorAmbiguityCount = 0;
    complex.diagnostics.predecessorMultiplicityFailureCount = 0;
    complex.diagnostics.repeatedNodeCycleCount = 0;
    complex.diagnostics.repeatedEdgeCycleCount = 0;
  }
  complex.diagnostics.embeddingValid =
      complex.diagnostics.embeddingValid &&
      validate_surface_cell_ownership_registry(complex);
  complex.diagnostics.orientationValid = orientationValid;
  complex.diagnostics.cellsDiskValid = cellsDiskValid;
  complex.diagnostics.connectedComponentCount =
      surface_arrangement_detail::graph_component_count(
          static_cast<int>(complex.nodes.size()), arrangementEdges);
  const bool hasExplicitBoundaryEvidence =
      complex.diagnostics.sourceBoundaryLoopCount == 0 ||
      std::any_of(complex.cells.begin(), complex.cells.end(),
                  [](const SurfaceArrangementCell &cell) {
                    return !cell.sourceBoundaryLoopIds.empty();
                  });
  if (hasExplicitBoundaryEvidence) {
    std::map<int, int> exteriorOwners;
    bool boundaryValid = true;
    for (const SurfaceArrangementCell &cell : complex.cells) {
      if (cell.sourceBoundaryLoopIds.empty()) {
        continue;
      }
      if (cell.sourceBoundarySide != (cell.boundaryCycle ? -1 : 1)) {
        boundaryValid = false;
      }
      if (!cell.boundaryCycle) {
        continue;
      }
      for (const int loop : cell.sourceBoundaryLoopIds) {
        if (loop < 0) {
          boundaryValid = false;
          continue;
        }
        ++exteriorOwners[loop];
      }
    }
    boundaryValid =
        boundaryValid &&
        static_cast<int>(exteriorOwners.size()) ==
            complex.diagnostics.sourceBoundaryLoopCount &&
        std::all_of(exteriorOwners.begin(), exteriorOwners.end(),
                    [](const auto &entry) { return entry.second == 1; });
    complex.diagnostics.boundaryLoopCount =
        static_cast<int>(exteriorOwners.size());
    complex.diagnostics.boundaryLoopsValid = boundaryValid;
  } else {
    const auto [boundaryLoops, boundaryValid] =
        surface_arrangement_detail::boundary_loop_count(
            static_cast<int>(complex.nodes.size()), arrangementBoundaryEdges);
    complex.diagnostics.boundaryLoopCount = boundaryLoops;
    complex.diagnostics.boundaryLoopsValid = boundaryValid;
  }
  complex.diagnostics.eulerCharacteristicValid =
      complex.diagnostics.eulerCharacteristic ==
          complex.diagnostics.sourceEulerCharacteristic &&
      complex.diagnostics.connectedComponentCount ==
          complex.diagnostics.sourceConnectedComponentCount &&
      complex.diagnostics.boundaryLoopCount ==
          complex.diagnostics.sourceBoundaryLoopCount &&
      complex.diagnostics.boundaryLoopsValid;
  complex.diagnostics.extractedArea = 0.0;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (!cell.boundaryCycle && !cell.supportOnlyCycle) {
      complex.diagnostics.extractedArea += cell.area;
    }
  }
  complex.diagnostics.relativeAreaError =
      std::abs(complex.diagnostics.extractedArea -
               complex.diagnostics.supportedArea) /
      std::max(1.0e-20, complex.diagnostics.supportedArea);
  complex.diagnostics.retainedMemoryBytes =
      surface_arrangement_detail::complex_storage_bytes(complex);
  complex.diagnostics.peakMemoryBytes =
      std::max(complex.diagnostics.peakMemoryBytes,
               complex.diagnostics.retainedMemoryBytes);
  complex.diagnostics.measuredMemoryRatio =
      static_cast<double>(complex.diagnostics.peakMemoryBytes) /
      static_cast<double>(
          std::max<std::uint64_t>(1U, complex.diagnostics.inputMemoryBytes));
  complex.diagnostics.memoryRatioEstimate =
      complex.diagnostics.measuredMemoryRatio;
  complex.diagnostics.topologyValid =
      complex.diagnostics.incidenceValid &&
      complex.diagnostics.embeddingValid &&
      complex.diagnostics.orientationValid &&
      complex.diagnostics.cellsDiskValid &&
      complex.diagnostics.boundaryLoopsValid &&
      complex.diagnostics.eulerCharacteristicValid &&
      complex.diagnostics.unsplitCrossings == 0 &&
      complex.diagnostics.geometricTJunctions == 0;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

SurfaceCellComplex rebuild_complex_after_halfedge_removal(
    const SurfaceCellComplex &complex, const std::set<int> &requestedRemoval,
    const Eigen::MatrixXd *vertices,
    const Eigen::MatrixXi *faces) {
  SurfaceCellComplex invalid;
  if (requestedRemoval.empty()) return invalid;

  std::set<int> removeHalfedges;
  std::map<int, std::set<int>> mergeAdjacency;
  std::set<int> affectedCells;
  std::set<int> trimCells;
  std::set<int> canonicalRequested;
  for (const int halfedgeId : requestedRemoval) {
    if (halfedgeId < 0 ||
        halfedgeId >= static_cast<int>(complex.halfedges.size())) {
      return invalid;
    }
    const SurfaceArrangementHalfedge &halfedge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    if (halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size())) {
      return invalid;
    }
    canonicalRequested.insert(std::min(halfedge.id, halfedge.twin));
  }

  for (const int canonical : canonicalRequested) {
    const SurfaceArrangementHalfedge &halfedge =
        complex.halfedges[static_cast<std::size_t>(canonical)];
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell < 0 || twin.cell < 0 ||
        halfedge.cell >= static_cast<int>(complex.cells.size()) ||
        twin.cell >= static_cast<int>(complex.cells.size()) ||
        complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle ||
        complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle) {
      return invalid;
    }
    removeHalfedges.insert(halfedge.id);
    removeHalfedges.insert(halfedge.twin);
    affectedCells.insert(halfedge.cell);
    affectedCells.insert(twin.cell);
    if (halfedge.cell == twin.cell) {
      trimCells.insert(halfedge.cell);
    } else {
      mergeAdjacency[halfedge.cell].insert(twin.cell);
      mergeAdjacency[twin.cell].insert(halfedge.cell);
    }
  }
  if (affectedCells.empty()) return invalid;

  std::vector<std::vector<int>> mergeComponents;
  std::set<int> visitedCells;
  for (const auto &[seed, neighbors] : mergeAdjacency) {
    (void)neighbors;
    if (!visitedCells.insert(seed).second) continue;
    std::vector<int> component;
    std::queue<int> queue;
    queue.push(seed);
    while (!queue.empty()) {
      const int cell = queue.front();
      queue.pop();
      component.push_back(cell);
      for (const int neighbor : mergeAdjacency[cell]) {
        if (visitedCells.insert(neighbor).second) queue.push(neighbor);
      }
    }
    std::sort(component.begin(), component.end());
    if (component.size() < 2U) return invalid;
    mergeComponents.push_back(std::move(component));
  }
  std::sort(mergeComponents.begin(), mergeComponents.end(),
            [](const auto &a, const auto &b) { return a.front() < b.front(); });

  std::map<int, int> componentOfCell;
  for (int component = 0;
       component < static_cast<int>(mergeComponents.size()); ++component) {
    for (const int cell : mergeComponents[static_cast<std::size_t>(component)]) {
      componentOfCell[cell] = component;
    }
  }

  // An unselected edge may remain between two different merge regions, but an
  // edge internal to one merged region would become an orphan/self-adjacency.
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.cell < 0) continue;
    const int twinCell =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell;
    const auto left = componentOfCell.find(halfedge.cell);
    const auto right = componentOfCell.find(twinCell);
    if (halfedge.cell != twinCell && left != componentOfCell.end() &&
        right != componentOfCell.end() && left->second == right->second &&
        removeHalfedges.count(halfedge.id) == 0) {
      return invalid;
    }
  }

  struct CellRecord {
    SurfaceArrangementCell cell;
    std::vector<int> oldBoundary;
    bool reclassify = false;
    bool recomputeGeometry = false;
  };
  std::vector<CellRecord> records;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (affectedCells.count(cell.id) == 0) {
      records.push_back({cell, cell.halfedges, false, false});
    }
  }

  // A topological bridge appears twice on the same DCEL face. Removing both
  // directions trims an out-and-back excursion rather than merging two
  // distinct cells. Reorder the remaining boundary and keep the cell count;
  // this preserves the source Euler characteristic when the bridge's now
  // unused nodes are compacted below.
  for (const int cellId : trimCells) {
    if (componentOfCell.count(cellId) != 0U) {
      continue;
    }
    const SurfaceArrangementCell &source =
        complex.cells[static_cast<std::size_t>(cellId)];
    std::vector<int> remaining;
    for (const int halfedgeId : source.halfedges) {
      if (removeHalfedges.count(halfedgeId) == 0U) {
        remaining.push_back(halfedgeId);
      }
    }
    std::vector<int> orderedBoundary;
    if (remaining.size() < 3U ||
        !order_boundary_cycle(complex, remaining, orderedBoundary)) {
      return invalid;
    }
    SurfaceArrangementCell trimmed = source;
    trimmed.closed = true;
    records.push_back(
        {std::move(trimmed), std::move(orderedBoundary), true, false});
  }

  for (const std::vector<int> &mergeComponent : mergeComponents) {
    const std::set<int> componentCells(mergeComponent.begin(),
                                       mergeComponent.end());
    std::vector<int> mergedBoundary;
    for (const int cellId : mergeComponent) {
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      for (const int halfedgeId : cell.halfedges) {
        if (removeHalfedges.count(halfedgeId) != 0) continue;
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        const int twinCell =
            halfedge.twin >= 0
                ? complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell
                : -1;
        if (componentCells.count(twinCell) == 0) {
          mergedBoundary.push_back(halfedgeId);
        }
      }
    }
    std::vector<int> orderedBoundary;
    if (!order_boundary_cycle(complex, mergedBoundary, orderedBoundary)) {
      return invalid;
    }

    SurfaceArrangementCell mergedCell;
    mergedCell.boundaryCycle = false;
    mergedCell.closed = true;
    mergedCell.disk = true;
    mergedCell.boundaryCycleOffsets = {0};
    mergedCell.boundaryComponentCount = 1;
    mergedCell.eulerCharacteristic = 1;
    std::set<int> mergedSourceFaces;
    std::set<authority::TopologyRegionId> mergedRegions;
    std::set<int> mergedBoundaryLoops;
    int mergedBoundarySide = 0;
    std::set<authority::SurfaceCellOwnershipClassId> mergedOwnershipClasses;
    std::set<SourceProjectionChart> mergedCharts;
    double fallbackArea = 0.0;
    for (const int cellId : mergeComponent) {
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      fallbackArea += cell.area;
      mergedSourceFaces.insert(cell.sourceFaces.begin(), cell.sourceFaces.end());
      if (cell.sourceFace >= 0) mergedSourceFaces.insert(cell.sourceFace);
      if (!cell.sourceOwnershipClass.has_value() ||
          find_surface_cell_ownership_class(
              complex, cell.sourceTopologyRegion,
              cell.sourceOwnershipClass) == nullptr) {
        return invalid;
      }
      if (!cell.sourceTopologyRegion.has_value()) return invalid;
      mergedRegions.insert(cell.sourceTopologyRegion.value());
      mergedBoundaryLoops.insert(cell.sourceBoundaryLoopIds.begin(),
                                 cell.sourceBoundaryLoopIds.end());
      if (cell.sourceBoundarySide != 0) {
        if (mergedBoundarySide != 0 &&
            mergedBoundarySide != cell.sourceBoundarySide) {
          return invalid;
        }
        mergedBoundarySide = cell.sourceBoundarySide;
      }
      mergedCharts.insert(cell.sourceCharts.begin(), cell.sourceCharts.end());
      mergedOwnershipClasses.insert(cell.sourceOwnershipClass.value());
    }
    if (mergedOwnershipClasses.size() != 1U || mergedRegions.size() != 1U) {
      return invalid;
    }
    mergedCell.sourceOwnershipClass = *mergedOwnershipClasses.begin();
    mergedCell.sourceCharts.assign(mergedCharts.begin(), mergedCharts.end());
    mergedCell.sourceTopologyRegion = *mergedRegions.begin();
    mergedCell.sourceFaces.assign(mergedSourceFaces.begin(),
                                  mergedSourceFaces.end());
    mergedCell.sourceBoundaryLoopIds.assign(mergedBoundaryLoops.begin(),
                                            mergedBoundaryLoops.end());
    mergedCell.sourceBoundarySide = mergedBoundarySide;
    mergedCell.sourceFace = mergedCell.sourceFaces.empty()
                                ? -1
                                : mergedCell.sourceFaces.front();
    mergedCell.area = fallbackArea;
    mergedCell.signedArea = fallbackArea;
    records.push_back(
        {std::move(mergedCell), std::move(orderedBoundary), true, true});
  }

  SurfaceCellComplex rebuilt = complex;
  std::vector<int> oldToNew(complex.halfedges.size(), -1);
  rebuilt.halfedges.clear();
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (removeHalfedges.count(halfedge.id) != 0) continue;
    oldToNew[static_cast<std::size_t>(halfedge.id)] =
        static_cast<int>(rebuilt.halfedges.size());
    rebuilt.halfedges.push_back(halfedge);
  }
  for (SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    const int oldId = halfedge.id;
    halfedge.id = oldToNew[static_cast<std::size_t>(oldId)];
    halfedge.twin = oldToNew[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.id < 0 || halfedge.twin < 0) return invalid;
    halfedge.next = -1;
    halfedge.cell = -1;
  }

  rebuilt.cells.clear();
  std::vector<unsigned char> rebuiltCellNeedsClassification;
  std::vector<unsigned char> rebuiltCellNeedsGeometry;
  for (CellRecord &record : records) {
    SurfaceArrangementCell cell = std::move(record.cell);
    cell.id = static_cast<int>(rebuilt.cells.size());
    cell.halfedges.clear();
    for (const int oldHalfedgeId : record.oldBoundary) {
      if (oldHalfedgeId < 0 ||
          oldHalfedgeId >= static_cast<int>(oldToNew.size())) {
        return invalid;
      }
      const int newHalfedgeId = oldToNew[static_cast<std::size_t>(oldHalfedgeId)];
      if (newHalfedgeId < 0) return invalid;
      cell.halfedges.push_back(newHalfedgeId);
    }
    rebuiltCellNeedsClassification.push_back(record.reclassify ? 1U : 0U);
    rebuiltCellNeedsGeometry.push_back(record.recomputeGeometry ? 1U : 0U);
    rebuilt.cells.push_back(std::move(cell));
  }
  for (SurfaceArrangementCell &cell : rebuilt.cells) {
    for (std::size_t index = 0; index < cell.halfedges.size(); ++index) {
      SurfaceArrangementHalfedge &halfedge =
          rebuilt.halfedges[static_cast<std::size_t>(cell.halfedges[index])];
      if (halfedge.cell >= 0) return invalid;
      halfedge.cell = cell.id;
      halfedge.next = cell.halfedges[(index + 1U) % cell.halfedges.size()];
    }
  }

  std::vector<int> nodeUse(rebuilt.nodes.size(), 0);
  for (const SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    if (halfedge.from < 0 || halfedge.to < 0 ||
        halfedge.from >= static_cast<int>(nodeUse.size()) ||
        halfedge.to >= static_cast<int>(nodeUse.size())) {
      return invalid;
    }
    ++nodeUse[static_cast<std::size_t>(halfedge.from)];
    ++nodeUse[static_cast<std::size_t>(halfedge.to)];
  }
  std::vector<int> nodeMap(rebuilt.nodes.size(), -1);
  std::vector<SurfaceArrangementNode> compactNodes;
  for (std::size_t index = 0; index < rebuilt.nodes.size(); ++index) {
    if (nodeUse[index] == 0) continue;
    nodeMap[index] = static_cast<int>(compactNodes.size());
    SurfaceArrangementNode node = rebuilt.nodes[index];
    node.id = nodeMap[index];
    compactNodes.push_back(std::move(node));
  }
  for (SurfaceArrangementHalfedge &halfedge : rebuilt.halfedges) {
    halfedge.from = nodeMap[static_cast<std::size_t>(halfedge.from)];
    halfedge.to = nodeMap[static_cast<std::size_t>(halfedge.to)];
    if (halfedge.from < 0 || halfedge.to < 0) return invalid;
  }
  rebuilt.nodes = std::move(compactNodes);

  for (std::size_t cellIndex = 0; cellIndex < rebuilt.cells.size(); ++cellIndex) {
    if (rebuiltCellNeedsClassification[cellIndex] == 0U) continue;
    SurfaceArrangementCell &rebuiltCell = rebuilt.cells[cellIndex];
    std::set<int> uniqueNodes;
    for (const int halfedgeId : rebuiltCell.halfedges) {
      uniqueNodes.insert(
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)].from);
    }
    rebuiltCell.cutCellDisk = false;
    rebuiltCell.bridgeExcursion = false;
    rebuiltCell.supportOnlyCycle = false;
    rebuiltCell.closed = rebuiltCell.halfedges.size() >= 3U;
    rebuiltCell.boundaryCycleOffsets =
        rebuiltCell.closed ? std::vector<int>{0} : std::vector<int>{};
    rebuiltCell.boundaryComponentCount = rebuiltCell.closed ? 1 : 0;
    rebuiltCell.eulerCharacteristic =
        static_cast<int>(uniqueNodes.size()) -
        static_cast<int>(rebuiltCell.halfedges.size()) +
        (rebuiltCell.closed ? 1 : 0);
    rebuiltCell.disk = rebuiltCell.closed &&
                       uniqueNodes.size() == rebuiltCell.halfedges.size() &&
                       rebuiltCell.boundaryComponentCount == 1 &&
                       rebuiltCell.eulerCharacteristic == 1;

    if (rebuiltCellNeedsGeometry[cellIndex] != 0U && vertices != nullptr &&
        faces != nullptr) {
      if (!surface_arrangement_detail::polygon_geometry(
              *vertices, *faces, rebuiltCell.halfedges, rebuilt.halfedges,
              rebuilt.nodes, rebuiltCell.signedArea, rebuiltCell.area,
              rebuiltCell.sourceFaces)) {
        rebuilt.diagnostics.embeddingValid = false;
      }
      rebuiltCell.sourceFace = rebuiltCell.sourceFaces.empty()
                                    ? -1
                                    : rebuiltCell.sourceFaces.front();
    }
    // A same-cell bridge contributes an out-and-back excursion with zero
    // signed area. Trimming it leaves the represented surface region and its
    // source-face support unchanged, so preserve the authoritative geometry
    // instead of forcing a new single-chart projection of a curved multi-face
    // cell. Distinct-cell merges still recompute their geometry above.
    classify_rebuilt_cell_sides(rebuiltCell, rebuilt, vertices, faces);
  }
  recompute_rebuilt_diagnostics(rebuilt);
  return rebuilt;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry::surface_simplification_detail {

std::vector<SurfaceSimplificationCandidate> recompute_overlap_candidates(
    const SurfaceCellComplex &complex, const std::set<int> &affectedNodes,
    const int nextStableBase) {
  std::vector<SurfaceSimplificationCandidate> recomputed;
  std::set<int> usedHalfedges;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.hardFeature ||
        halfedge.family < 0 ||
        (affectedNodes.count(halfedge.from) == 0 &&
         affectedNodes.count(halfedge.to) == 0)) {
      continue;
    }
    if (usedHalfedges.count(halfedge.id) != 0 ||
        usedHalfedges.count(halfedge.twin) != 0) {
      continue;
    }
    usedHalfedges.insert(halfedge.id);
    usedHalfedges.insert(halfedge.twin);
    SurfaceSimplificationCandidate candidate;
    candidate.stableId = nextStableBase + static_cast<int>(recomputed.size());
    candidate.type = SurfaceSimplificationCandidateType::RedundantStrand;
    candidate.elementIds = {halfedge.id};
    candidate.deltaSurface = -0.25;
    recomputed.push_back(std::move(candidate));
  }
  return recomputed;
}

} // namespace directional::geometry::surface_simplification_detail

namespace directional::geometry {

SurfaceSimplificationCandidateSet
extract_surface_simplification_candidates_impl(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd *vertices,
    const Eigen::MatrixXi *faces,
    const SurfaceSimplificationCandidateExtractionOptions &options) {
  using namespace surface_simplification_detail;
  SurfaceSimplificationCandidateSet result;

  struct EdgeRecord {
    int halfedge = -1;
    int from = -1;
    int to = -1;
    int family = -1;
    int strand = -1;
    std::set<authority::SurfaceCellOwnershipClassId> ownershipClasses;
    bool hardFeature = false;
    bool boundary = false;
    bool layoutSupport = false;
    bool singularitySupport = false;
    double length = 0.0;
    std::set<int> cells;
  };

  const auto cell_is_exterior = [&](const int cellId) {
    return cellId < 0 || cellId >= static_cast<int>(complex.cells.size()) ||
           complex.cells[static_cast<std::size_t>(cellId)].boundaryCycle;
  };

  std::vector<EdgeRecord> edges;
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin ||
        halfedge.twin >= static_cast<int>(complex.halfedges.size())) {
      continue;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
    EdgeRecord record;
    record.halfedge = halfedge.id;
    record.from = halfedge.from;
    record.to = halfedge.to;
    record.family = halfedge.family;
    record.strand = halfedge.strand;
    record.hardFeature = halfedge.hardFeature || twin.hardFeature;
    record.layoutSupport =
        halfedge.layoutSupport || twin.layoutSupport;
    record.singularitySupport =
        halfedge.singularitySupport || twin.singularitySupport;
    record.boundary = halfedge.family < 0 || twin.family < 0 ||
                      cell_is_exterior(halfedge.cell) ||
                      cell_is_exterior(twin.cell);
    for (const SurfaceArrangementProvenance &value : halfedge.provenance) {
      record.layoutSupport = record.layoutSupport || value.layoutSupport;
      record.singularitySupport =
          record.singularitySupport || value.singularitySupport;
    }
    for (const SurfaceArrangementProvenance &value : twin.provenance) {
      record.layoutSupport = record.layoutSupport || value.layoutSupport;
      record.singularitySupport =
          record.singularitySupport || value.singularitySupport;
    }
    const auto appendOwnership = [&](const int cellId,
                                     const SurfaceArrangementHalfedge &edge) {
      if (cellId < 0 || cellId >= static_cast<int>(complex.cells.size())) {
        return;
      }
      record.cells.insert(cellId);
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      if (cell.sourceOwnershipClass.has_value() &&
          find_surface_cell_ownership_class(
              complex, cell.sourceTopologyRegion,
              cell.sourceOwnershipClass) != nullptr) {
        record.ownershipClasses.insert(cell.sourceOwnershipClass.value());
      }
    };
    appendOwnership(halfedge.cell, halfedge);
    appendOwnership(twin.cell, twin);

    if (vertices != nullptr && faces != nullptr && record.from >= 0 &&
        record.to >= 0 && record.from < static_cast<int>(complex.nodes.size()) &&
        record.to < static_cast<int>(complex.nodes.size())) {
      const Eigen::RowVector3d from = surface_arrangement_detail::node_position(
          *vertices, *faces,
          complex.nodes[static_cast<std::size_t>(record.from)]);
      const Eigen::RowVector3d to = surface_arrangement_detail::node_position(
          *vertices, *faces,
          complex.nodes[static_cast<std::size_t>(record.to)]);
      record.length = (to - from).norm();
    } else {
      record.length = std::abs(halfedge.sourceT1 - halfedge.sourceT0);
    }
    record.length = std::max(record.length, 1.0e-12);
    edges.push_back(std::move(record));
  }

  std::vector<std::vector<int>> nodeEdges(complex.nodes.size());
  for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
    const EdgeRecord &edge = edges[static_cast<std::size_t>(i)];
    if (edge.from >= 0 && edge.from < static_cast<int>(nodeEdges.size())) {
      nodeEdges[static_cast<std::size_t>(edge.from)].push_back(i);
    }
    if (edge.to >= 0 && edge.to < static_cast<int>(nodeEdges.size())) {
      nodeEdges[static_cast<std::size_t>(edge.to)].push_back(i);
    }
  }

  std::vector<unsigned char> boundaryNode(complex.nodes.size(), 0);
  for (const EdgeRecord &edge : edges) {
    if (!edge.boundary) continue;
    if (edge.from >= 0 && edge.from < static_cast<int>(boundaryNode.size())) {
      boundaryNode[static_cast<std::size_t>(edge.from)] = 1;
    }
    if (edge.to >= 0 && edge.to < static_cast<int>(boundaryNode.size())) {
      boundaryNode[static_cast<std::size_t>(edge.to)] = 1;
    }
  }
  std::vector<unsigned char> singularNode(complex.nodes.size(), 0);
  for (std::size_t node = 0; node < nodeEdges.size(); ++node) {
    if (!boundaryNode[node] && nodeEdges[node].size() != 4U) {
      singularNode[node] = 1;
    }
  }

  auto populate = [&](SurfaceSimplificationCandidate &candidate,
                      const std::vector<int> &edgeIndices,
                      const bool explicitSingularityOnly = false) {
    std::set<int> nodes;
    std::set<int> cells;
    std::set<int> strands;
    std::set<authority::SurfaceCellOwnershipClassId> ownershipClasses;
    for (const int edgeIndex : edgeIndices) {
      const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
      candidate.elementIds.push_back(edge.halfedge);
      nodes.insert(edge.from);
      nodes.insert(edge.to);
      cells.insert(edge.cells.begin(), edge.cells.end());
      if (edge.strand >= 0) strands.insert(edge.strand);
      ownershipClasses.insert(edge.ownershipClasses.begin(),
                              edge.ownershipClasses.end());
      candidate.touchesHardFeature =
          candidate.touchesHardFeature || edge.hardFeature;
      candidate.touchesSingularity =
          candidate.touchesSingularity || edge.singularitySupport;
      candidate.touchesBoundary = candidate.touchesBoundary || edge.boundary;
      candidate.removedLength += edge.length;
    }
    std::sort(candidate.elementIds.begin(), candidate.elementIds.end());
    candidate.elementIds.erase(
        std::unique(candidate.elementIds.begin(), candidate.elementIds.end()),
        candidate.elementIds.end());
    candidate.affectedNodeIds.assign(nodes.begin(), nodes.end());
    candidate.affectedCellIds.assign(cells.begin(), cells.end());
    candidate.affectedStrandIds.assign(strands.begin(), strands.end());
    candidate.touchesLocalSheetBoundary = ownershipClasses.size() > 1U;
    if (!explicitSingularityOnly) {
      for (const int node : candidate.affectedNodeIds) {
        if (node >= 0 && node < static_cast<int>(singularNode.size()) &&
            singularNode[static_cast<std::size_t>(node)] != 0U) {
          candidate.touchesSingularity = true;
        }
      }
    }

    candidate.affectedPatchDisk = true;
    candidate.sideFeasible = true;
    for (const int cellId : candidate.affectedCellIds) {
      if (cellId < 0 || cellId >= static_cast<int>(complex.cells.size())) {
        candidate.affectedPatchDisk = false;
        candidate.sideFeasible = false;
        continue;
      }
      const SurfaceArrangementCell &cell =
          complex.cells[static_cast<std::size_t>(cellId)];
      if (cell.boundaryCycle) {
        candidate.touchesBoundary = true;
        continue;
      }
      candidate.affectedPatchDisk = candidate.affectedPatchDisk && cell.disk;
      candidate.sideFeasible = candidate.sideFeasible && cell.closed &&
                               cell.boundaryComponentCount == 1;
    }
    candidate.changesTopology = candidate.touchesLocalSheetBoundary ||
                                candidate.touchesSingularity;
    candidate.deltaSurface = -candidate.removedLength;
    candidate.deltaSize =
        -0.25 * static_cast<double>(candidate.elementIds.size());
    candidate.deltaQuad = candidate.sideFeasible ? -0.1 : 1.0;
    candidate.featurePenalty = candidate.touchesHardFeature ? 1.0e6 : 0.0;
    candidate.topologyPenalty =
        (candidate.touchesBoundary || candidate.changesTopology) ? 1.0e6 : 0.0;
    candidate.descriptivenessWorsening =
        candidate.touchesHardFeature ? 1.0 : 0.0;
  };

  const auto append_candidate = [&](SurfaceSimplificationCandidate candidate) {
    const bool protectedCandidate =
        candidate.touchesHardFeature || candidate.touchesBoundary ||
        candidate.touchesSingularity || candidate.changesTopology;
    if (protectedCandidate &&
        !options.includeProtectedCandidatesForDiagnostics) {
      return;
    }
    switch (candidate.type) {
    case SurfaceSimplificationCandidateType::OpenStrip:
      ++result.openStripCandidates;
      break;
    case SurfaceSimplificationCandidateType::ClosedLoop:
      ++result.closedLoopCandidates;
      break;
    case SurfaceSimplificationCandidateType::RedundantStrand:
      ++result.redundantStrandCandidates;
      break;
    case SurfaceSimplificationCandidateType::RegionCollapse:
      ++result.regionCandidates;
      break;
    case SurfaceSimplificationCandidateType::PoleRelocation:
      ++result.poleCandidates;
      break;
    case SurfaceSimplificationCandidateType::TransitionRemoval:
      ++result.transitionCandidates;
      break;
    default:
      break;
    }
    if (protectedCandidate) ++result.protectedCandidates;
    result.candidates.push_back(std::move(candidate));
  };

  // A graph bridge cannot bound an arrangement cell. When such an edge is an
  // optional layout-support trace, its two DCEL directions occur on the same
  // face walk and pinch that walk into a non-disk cell. Extract maximal,
  // provenance-coherent bridge chains as explicit healing candidates. Tarjan
  // uses edge IDs (rather than parent vertices) so parallel edges are handled
  // correctly and are never mistaken for bridges.
  std::vector<int> discovery(complex.nodes.size(), -1);
  std::vector<int> low(complex.nodes.size(), -1);
  std::set<int> bridgeEdges;
  int discoveryTime = 0;
  std::function<void(int, int)> findBridges =
      [&](const int node, const int parentEdge) {
        discovery[static_cast<std::size_t>(node)] = discoveryTime;
        low[static_cast<std::size_t>(node)] = discoveryTime++;
        for (const int edgeIndex : nodeEdges[static_cast<std::size_t>(node)]) {
          if (edgeIndex == parentEdge) continue;
          const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
          const int next = edge.from == node ? edge.to : edge.from;
          if (next == node || next < 0 ||
              next >= static_cast<int>(complex.nodes.size())) {
            continue;
          }
          if (discovery[static_cast<std::size_t>(next)] < 0) {
            findBridges(next, edgeIndex);
            low[static_cast<std::size_t>(node)] = std::min(
                low[static_cast<std::size_t>(node)],
                low[static_cast<std::size_t>(next)]);
            if (low[static_cast<std::size_t>(next)] >
                discovery[static_cast<std::size_t>(node)]) {
              bridgeEdges.insert(edgeIndex);
            }
          } else {
            low[static_cast<std::size_t>(node)] = std::min(
                low[static_cast<std::size_t>(node)],
                discovery[static_cast<std::size_t>(next)]);
          }
        }
      };
  for (int node = 0; node < static_cast<int>(complex.nodes.size()); ++node) {
    if (discovery[static_cast<std::size_t>(node)] < 0) {
      findBridges(node, -1);
    }
  }

  int stableId = 0;
  // A pinched DCEL face can contain several disconnected optional bridge
  // excursions. Removing any one excursion in isolation may leave a repeated
  // node walk that cannot be represented as a simple boundary cycle. Emit a
  // cell-scoped aggregate candidate containing every optional bridge on that
  // face so the transaction can prove the complete repair atomically. This is
  // deliberately narrower than a general region collapse: every selected
  // edge is independently a graph bridge, layout support is optional, and
  // hard-feature, boundary, and singularity support are excluded.
  std::map<int, std::vector<int>> healingEdgesByCell;
  for (const int edgeIndex : bridgeEdges) {
    const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
    if (edge.family < 0 || !edge.layoutSupport || edge.singularitySupport ||
        edge.hardFeature || edge.boundary || edge.cells.size() != 1U) {
      continue;
    }
    const int cellId = *edge.cells.begin();
    if (cellId < 0 || cellId >= static_cast<int>(complex.cells.size()) ||
        complex.cells[static_cast<std::size_t>(cellId)].boundaryCycle ||
        complex.cells[static_cast<std::size_t>(cellId)].disk) {
      continue;
    }
    healingEdgesByCell[cellId].push_back(edgeIndex);
  }
  for (auto &[cellId, group] : healingEdgesByCell) {
    (void)cellId;
    std::sort(group.begin(), group.end(), [&](const int a, const int b) {
      return edges[static_cast<std::size_t>(a)].halfedge <
             edges[static_cast<std::size_t>(b)].halfedge;
    });
    group.erase(std::unique(group.begin(), group.end()), group.end());
    if (group.size() < 2U ||
        static_cast<int>(group.size()) < options.minimumElements) {
      continue;
    }
    SurfaceSimplificationCandidate candidate;
    candidate.stableId = stableId++;
    candidate.type = SurfaceSimplificationCandidateType::OpenStrip;
    populate(candidate, group, true);
    candidate.topologyHealing = true;
    candidate.sideFeasible = true;
    // Independent same-cell bridge trims may live on different local source
    // sheets without crossing or merging those sheets. Protect only an edge
    // whose own provenance spans multiple sheets; do not reject an atomic
    // collection merely because its disconnected excursions belong to
    // different sheets.
    candidate.touchesLocalSheetBoundary = std::any_of(
        group.begin(), group.end(), [&](const int edgeIndex) {
          return edges[static_cast<std::size_t>(edgeIndex)]
                     .ownershipClasses.size() > 1U;
        });
    candidate.changesTopology = candidate.touchesLocalSheetBoundary ||
                                candidate.touchesSingularity;
    candidate.topologyPenalty = candidate.changesTopology ? 1.0e6 : 0.0;
    append_candidate(std::move(candidate));
  }

  std::map<std::pair<int, int>, std::vector<int>> healingGroups;
  for (const int edgeIndex : bridgeEdges) {
    const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
    if (edge.family >= 0 && edge.layoutSupport && !edge.hardFeature &&
        !edge.boundary) {
      healingGroups[{edge.family, edge.strand}].push_back(edgeIndex);
    }
  }
  for (const auto &[key, group] : healingGroups) {
    (void)key;
    const std::set<int> groupSet(group.begin(), group.end());
    std::set<int> visited;
    for (const int seed : group) {
      if (!visited.insert(seed).second) continue;
      std::vector<int> component;
      std::queue<int> queue;
      queue.push(seed);
      while (!queue.empty()) {
        const int current = queue.front();
        queue.pop();
        component.push_back(current);
        const EdgeRecord &edge = edges[static_cast<std::size_t>(current)];
        for (const int node : {edge.from, edge.to}) {
          if (node < 0 || node >= static_cast<int>(nodeEdges.size())) continue;
          for (const int neighbor : nodeEdges[static_cast<std::size_t>(node)]) {
            if (groupSet.count(neighbor) != 0U &&
                visited.insert(neighbor).second) {
              queue.push(neighbor);
            }
          }
        }
      }
      if (static_cast<int>(component.size()) < options.minimumElements) {
        continue;
      }
      std::sort(component.begin(), component.end(), [&](const int a, const int b) {
        return edges[static_cast<std::size_t>(a)].halfedge <
               edges[static_cast<std::size_t>(b)].halfedge;
      });
      SurfaceSimplificationCandidate candidate;
      candidate.stableId = stableId++;
      candidate.type = SurfaceSimplificationCandidateType::OpenStrip;
      // An irregular endpoint created by the bridge itself is not a field
      // singularity. Only dedicated index-aware separatrix provenance protects
      // a topology-healing candidate.
      populate(candidate, component, true);
      candidate.topologyHealing = true;
      candidate.sideFeasible = true;
      candidate.changesTopology = candidate.touchesLocalSheetBoundary ||
                                  candidate.touchesSingularity;
      candidate.topologyPenalty = candidate.changesTopology ? 1.0e6 : 0.0;
      append_candidate(std::move(candidate));
    }
  }

  std::map<std::pair<int, int>, std::vector<int>> grouped;
  for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
    const EdgeRecord &edge = edges[static_cast<std::size_t>(i)];
    if (edge.family >= 0) grouped[{edge.family, edge.strand}].push_back(i);
  }

  for (const auto &[key, group] : grouped) {
    (void)key;
    const std::set<int> groupSet(group.begin(), group.end());
    std::set<int> visited;
    for (const int seed : group) {
      if (!visited.insert(seed).second) continue;
      std::vector<int> component;
      std::queue<int> queue;
      queue.push(seed);
      while (!queue.empty()) {
        const int current = queue.front();
        queue.pop();
        component.push_back(current);
        const EdgeRecord &edge = edges[static_cast<std::size_t>(current)];
        for (const int node : {edge.from, edge.to}) {
          if (node < 0 || node >= static_cast<int>(nodeEdges.size())) continue;
          for (const int neighbor : nodeEdges[static_cast<std::size_t>(node)]) {
            if (groupSet.count(neighbor) != 0 &&
                visited.insert(neighbor).second) {
              queue.push(neighbor);
            }
          }
        }
      }
      std::sort(component.begin(), component.end(),
                [&](const int a, const int b) {
                  return edges[static_cast<std::size_t>(a)].halfedge <
                         edges[static_cast<std::size_t>(b)].halfedge;
                });
      if (static_cast<int>(component.size()) < options.minimumElements) {
        continue;
      }

      std::map<int, int> degree;
      for (const int edgeIndex : component) {
        const EdgeRecord &edge = edges[static_cast<std::size_t>(edgeIndex)];
        ++degree[edge.from];
        ++degree[edge.to];
      }
      const int degreeOne = static_cast<int>(std::count_if(
          degree.begin(), degree.end(),
          [](const auto &entry) { return entry.second == 1; }));
      const bool allDegreeAtMostTwo = std::all_of(
          degree.begin(), degree.end(),
          [](const auto &entry) { return entry.second == 1 || entry.second == 2; });
      const bool closed = options.classifyClosedLoops && !component.empty() &&
                          std::all_of(degree.begin(), degree.end(),
                                      [](const auto &entry) {
                                        return entry.second == 2;
                                      });
      const bool open = allDegreeAtMostTwo && degreeOne == 2;

      SurfaceSimplificationCandidate candidate;
      candidate.stableId = stableId++;
      candidate.type = closed
                           ? SurfaceSimplificationCandidateType::ClosedLoop
                           : (open
                                  ? SurfaceSimplificationCandidateType::OpenStrip
                                  : SurfaceSimplificationCandidateType::RegionCollapse);
      populate(candidate, component);
      if (!closed && !open) {
        candidate.sideFeasible = false;
        candidate.changesTopology = true;
        candidate.topologyPenalty = 1.0e6;
      }
      append_candidate(std::move(candidate));

      if (component.size() > 1U) {
        SurfaceSimplificationCandidate redundant;
        redundant.stableId = stableId++;
        redundant.type = SurfaceSimplificationCandidateType::RedundantStrand;
        populate(redundant, component);
        if (!closed && !open) {
          redundant.sideFeasible = false;
          redundant.changesTopology = true;
          redundant.topologyPenalty = 1.0e6;
        }
        append_candidate(std::move(redundant));
      }
    }
  }

  std::sort(result.candidates.begin(), result.candidates.end(),
            [](const SurfaceSimplificationCandidate &a,
               const SurfaceSimplificationCandidate &b) {
              if (a.topologyHealing != b.topologyHealing) {
                return a.topologyHealing > b.topologyHealing;
              }
              if (a.type != b.type) {
                return static_cast<int>(a.type) < static_cast<int>(b.type);
              }
              if (a.elementIds != b.elementIds) return a.elementIds < b.elementIds;
              return a.stableId < b.stableId;
            });
  for (int i = 0; i < static_cast<int>(result.candidates.size()); ++i) {
    result.candidates[static_cast<std::size_t>(i)].stableId = i;
  }

  std::uint64_t hash = complex_structural_hash(complex);
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  for (const SurfaceSimplificationCandidate &candidate : result.candidates) {
    mix(candidate.stableId);
    mix(static_cast<int>(candidate.type));
    for (const int value : candidate.elementIds) mix(value);
    for (const int value : candidate.affectedNodeIds) mix(value);
    for (const int value : candidate.affectedCellIds) mix(value);
    mix(candidate.touchesHardFeature ? 1 : 0);
    mix(candidate.touchesBoundary ? 1 : 0);
    mix(candidate.touchesSingularity ? 1 : 0);
    mix(candidate.touchesLocalSheetBoundary ? 1 : 0);
    mix(candidate.changesTopology ? 1 : 0);
    mix(candidate.topologyHealing ? 1 : 0);
    mix(candidate.sideFeasible ? 1 : 0);
    mix(static_cast<std::int64_t>(std::llround(candidate.removedLength * 1.0e10)));
  }
  result.structuralHash = hash;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceSimplificationCandidateExtractionOptions &options) {
  return extract_surface_simplification_candidates_impl(complex, nullptr, nullptr,
                                                         options);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationCandidateSet extract_surface_simplification_candidates(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    const SurfaceSimplificationCandidateExtractionOptions &options) {
  return extract_surface_simplification_candidates_impl(complex, &vertices, &faces,
                                                         options);
}

} // namespace directional::geometry

namespace directional::geometry {

std::vector<SurfaceSimplificationElement>
make_simplification_elements_from_complex(const SurfaceCellComplex &complex) {
  std::vector<SurfaceSimplificationElement> elements;
  elements.reserve(complex.halfedges.size());
  for (const SurfaceArrangementHalfedge &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin) {
      continue;
    }
    SurfaceSimplificationElement element;
    element.id = static_cast<int>(elements.size());
    element.cellOrHalfedge = halfedge.id;
    element.hardFeature = halfedge.hardFeature;
    element.boundary = halfedge.family < 0;
    element.length = std::abs(halfedge.sourceT1 - halfedge.sourceT0);
    elements.push_back(element);
  }
  return elements;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationCandidate make_removal_candidate(
    const int stableId, const SurfaceSimplificationCandidateType type,
    std::vector<int> elementIds, const double cost) {
  SurfaceSimplificationCandidate candidate;
  candidate.stableId = stableId;
  candidate.type = type;
  candidate.elementIds = std::move(elementIds);
  candidate.deltaSurface = cost;
  return candidate;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationResult simplify_surface_complex(
    std::vector<SurfaceSimplificationElement> elements,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options) {
  using namespace surface_simplification_detail;
  SurfaceSimplificationResult result;
  result.initialActiveElements = active_count(elements);

  std::priority_queue<QueueEntry> queue;
  for (int i = 0; i < static_cast<int>(candidates.size()); ++i) {
    if (options.topologyHealingOnly &&
        !candidates[static_cast<std::size_t>(i)].topologyHealing) {
      continue;
    }
    const double cost = objective_cost(candidates[static_cast<std::size_t>(i)],
                                       options.weights);
    queue.push({cost, candidates[static_cast<std::size_t>(i)].type,
                candidates[static_cast<std::size_t>(i)].stableId, i});
  }

  while (!queue.empty()) {
    if (options.targetActiveElements > 0 &&
        active_count(elements) <= options.targetActiveElements) {
      break;
    }
    const QueueEntry entry = queue.top();
    queue.pop();
    ++result.empiricalWork;
    SurfaceSimplificationCandidate &candidate =
        candidates[static_cast<std::size_t>(entry.index)];
    const double cost = objective_cost(candidate, options.weights);
    SurfaceSimplificationTransaction transaction;
    transaction.candidateId = candidate.stableId;
    transaction.type = candidate.type;
    transaction.objectiveCost = cost;
    transaction.beforeHash = structural_hash(elements);
    const SurfaceSimplificationRejectionReason rejection =
        validate_candidate(candidate, elements, options, cost);
    if (rejection == SurfaceSimplificationRejectionReason::None) {
      std::vector<SurfaceSimplificationElement> trial = elements;
      for (const int elementId : candidate.elementIds) {
        trial[static_cast<std::size_t>(elementId)].active = false;
      }
      elements = std::move(trial);
      transaction.committed = true;
      transaction.rejection = SurfaceSimplificationRejectionReason::None;
      transaction.afterHash = structural_hash(elements);
      ++result.committed;

      std::set<int> removed(candidate.elementIds.begin(),
                            candidate.elementIds.end());
      for (SurfaceSimplificationCandidate &other : candidates) {
        if (other.stableId == candidate.stableId || other.invalidated) {
          continue;
        }
        for (const int elementId : other.elementIds) {
          if (removed.count(elementId) != 0) {
            other.invalidated = true;
            ++result.invalidatedCandidates;
            ++result.recomputedCandidates;
            break;
          }
        }
      }
    } else {
      transaction.committed = false;
      transaction.rejection = rejection;
      transaction.afterHash = structural_hash(elements);
      ++result.rejected;
    }
    if (options.retainTransactionDetails) {
      result.transactions.push_back(std::move(transaction));
    }
  }

  result.elements = std::move(elements);
  result.finalActiveElements = active_count(result.elements);
  result.finalHash = structural_hash(result.elements);
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationResult simplify_surface_cell_complex_impl(
    SurfaceCellComplex inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const Eigen::MatrixXd *vertices, const Eigen::MatrixXi *faces,
    const SurfaceSimplificationOptions &options) {
  using namespace surface_simplification_detail;
  SurfaceSimplificationResult result;
  result.hasComplexOutput = true;
  SurfaceCellComplex complex = std::move(inputComplex);
  Eigen::MatrixXi topologyOnlyFaces(0, 3);
  const Eigen::MatrixXi &ownershipFaces =
      faces != nullptr ? *faces : topologyOnlyFaces;
  if (!canonicalize_surface_cell_ownership(complex, ownershipFaces)) {
    result.complex = std::move(complex);
    result.rejected = static_cast<int>(candidates.size());
    result.initialActiveElements =
        static_cast<int>(result.complex.halfedges.size()) / 2;
    result.finalActiveElements = result.initialActiveElements;
    result.finalHash = hash_surface_cell_complex(result.complex);
    return result;
  }
  result.initialActiveElements =
      static_cast<int>(complex.halfedges.size()) / 2;

  const auto candidateSemanticIdentity =
      [&](const SurfaceSimplificationCandidate &candidate) {
        SourceAwareIdentity identity;
        identity.values = {static_cast<int>(candidate.type),
                           candidate.topologyHealing ? 1 : 0};
        std::vector<SourceAwareIdentity> edges;
        for (const int halfedgeId : candidate.elementIds) {
          if (halfedgeId < 0 ||
              halfedgeId >= static_cast<int>(complex.halfedges.size())) {
            SourceAwareIdentity invalid;
            invalid.values = {-1, halfedgeId};
            edges.push_back(std::move(invalid));
            continue;
          }
          const SurfaceArrangementHalfedge &edge =
              complex.halfedges[static_cast<std::size_t>(halfedgeId)];
          SourceAwareIdentity edgeIdentity;
          edgeIdentity.values = {
              std::min(edge.from, edge.to), std::max(edge.from, edge.to),
              edge.family, edge.strand, edge.featureClass,
              edge.hardFeature ? 1 : 0, edge.layoutSupport ? 1 : 0,
              edge.singularitySupport ? 1 : 0, rail_id_leaf(edge.railId),
              edge.curveId};
          append_source_scope_identity(edgeIdentity, edge.sourceTopologyRegion,
                                       edge.sourceChart);
          edgeIdentity.values.insert(edgeIdentity.values.end(),
                                     {edge.proposalSide,
                                      edge.proposalBoundarySegment});
          for (const SurfaceArrangementProvenance &provenance :
               edge.provenance) {
            edgeIdentity.values.insert(
                edgeIdentity.values.end(),
                {provenance.family, provenance.strand,
                 provenance.featureClass, provenance.hardFeature ? 1 : 0,
                 provenance.layoutSupport ? 1 : 0,
                 provenance.singularitySupport ? 1 : 0,
                 rail_id_leaf(provenance.railId), provenance.curveId});
            append_source_scope_identity(edgeIdentity,
                                         provenance.sourceTopologyRegion,
                                         provenance.sourceChart);
            edgeIdentity.values.insert(edgeIdentity.values.end(),
                                       {provenance.proposalSide,
                                        provenance.proposalBoundarySegment});
          }
          edges.push_back(std::move(edgeIdentity));
        }
        std::sort(edges.begin(), edges.end());
        identity.values.push_back(static_cast<std::int64_t>(edges.size()));
        for (const SourceAwareIdentity &edge : edges) {
          identity.values.push_back(static_cast<std::int64_t>(edge.values.size()));
          identity.values.insert(identity.values.end(), edge.values.begin(),
                                 edge.values.end());
          identity.sourceScopes.insert(identity.sourceScopes.end(),
                                       edge.sourceScopes.begin(),
                                       edge.sourceScopes.end());
        }
        return identity;
      };
  const auto hashSemanticIdentity = [](const SourceAwareIdentity &identity) {
    std::uint64_t hash = 1469598103934665603ULL;
    const auto mix = [&](const std::uint64_t value) {
      hash ^= value;
      hash *= 1099511628211ULL;
    };
    for (const std::int64_t value : identity.values) {
      mix(static_cast<std::uint64_t>(value));
    }
    // Collision-domain diagnostic only. Exact candidate deduplication uses the
    // typed SourceAwareIdentity below and never decodes this digest.
    mix(static_cast<std::uint64_t>(identity.sourceScopes.size()));
    for (const SourceScope &scope : identity.sourceScopes) {
      mix(scope.region.has_value() ? 1U : 0U);
      mix(scope.chart.has_value() ? 1U : 0U);
    }
    return hash;
  };

  int currentGeneration = 0;
  const auto normalizeGeneration =
      [&](std::vector<SurfaceSimplificationCandidate> input,
          const bool preserveStableIds) {
        std::vector<SurfaceSimplificationCandidate> normalized;
        normalized.reserve(input.size());
        std::set<SourceAwareIdentity> liveIdentities;
        for (SurfaceSimplificationCandidate &candidate : input) {
          if (options.topologyHealingOnly && !candidate.topologyHealing) {
            continue;
          }
          ++result.generatedCandidates;
          const SourceAwareIdentity identity =
              candidateSemanticIdentity(candidate);
          if (!liveIdentities.insert(identity).second) {
            ++result.deduplicatedCandidates;
            continue;
          }
          candidate.generation = currentGeneration;
          candidate.semanticHash = hashSemanticIdentity(identity);
          if (!preserveStableIds || candidate.stableId < 0) {
            candidate.stableId = 1000000 +
                currentGeneration * 1000000 +
                static_cast<int>(normalized.size());
          }
          normalized.push_back(std::move(candidate));
        }
        result.peakLiveCandidates = std::max(
            result.peakLiveCandidates, static_cast<int>(normalized.size()));
        return normalized;
      };

  candidates = normalizeGeneration(std::move(candidates), true);
  result.frontierGenerations = 1;

  std::priority_queue<QueueEntry> queue;
  for (int i = 0; i < static_cast<int>(candidates.size()); ++i) {
    if (options.topologyHealingOnly &&
        !candidates[static_cast<std::size_t>(i)].topologyHealing) {
      continue;
    }
    const double cost = objective_cost(candidates[static_cast<std::size_t>(i)],
                                       options.weights);
    queue.push({cost, candidates[static_cast<std::size_t>(i)].type,
                candidates[static_cast<std::size_t>(i)].stableId, i});
  }

  while (!queue.empty()) {
    if (options.targetActiveElements > 0 &&
        static_cast<int>(complex.halfedges.size()) / 2 <=
            options.targetActiveElements) {
      break;
    }
    const QueueEntry entry = queue.top();
    queue.pop();
    ++result.empiricalWork;
    if (entry.index < 0 || entry.index >= static_cast<int>(candidates.size())) {
      continue;
    }
    SurfaceSimplificationCandidate &candidate =
        candidates[static_cast<std::size_t>(entry.index)];
    if (candidate.generation != currentGeneration) {
      ++result.staleGenerationCandidates;
      continue;
    }
    const double cost = objective_cost(candidate, options.weights);
    SurfaceSimplificationTransaction transaction;
    transaction.candidateId = candidate.stableId;
    transaction.type = candidate.type;
    transaction.topologyHealing = candidate.topologyHealing;
    transaction.elementIds = candidate.elementIds;
    transaction.affectedCellIds = candidate.affectedCellIds;
    transaction.objectiveCost = cost;
    transaction.beforeHash = complex_structural_hash(complex);
    transaction.beforeNodeCount = static_cast<int>(complex.nodes.size());
    transaction.beforeUndirectedEdgeCount =
        static_cast<int>(complex.halfedges.size()) / 2;
    transaction.beforeInteriorCellCount = static_cast<int>(std::count_if(
        complex.cells.begin(), complex.cells.end(),
        [](const SurfaceArrangementCell &cell) { return !cell.boundaryCycle; }));
    transaction.beforeEulerCharacteristic =
        complex.diagnostics.eulerCharacteristic;
    transaction.sourceEulerCharacteristic =
        complex.diagnostics.sourceEulerCharacteristic;
    transaction.beforeConnectedComponentCount =
        complex.diagnostics.connectedComponentCount;
    transaction.sourceConnectedComponentCount =
        complex.diagnostics.sourceConnectedComponentCount;
    transaction.beforeBoundaryLoopCount =
        complex.diagnostics.boundaryLoopCount;
    transaction.sourceBoundaryLoopCount =
        complex.diagnostics.sourceBoundaryLoopCount;
    transaction.beforeUnsplitCrossings =
        complex.diagnostics.unsplitCrossings;
    transaction.beforeGeometricTJunctions =
        complex.diagnostics.geometricTJunctions;
    transaction.beforeEmbeddingValid = complex.diagnostics.embeddingValid;
    transaction.beforeOrientationValid = complex.diagnostics.orientationValid;
    transaction.beforeBoundaryLoopsValid =
        complex.diagnostics.boundaryLoopsValid;
    transaction.beforeEulerCharacteristicValid =
        complex.diagnostics.eulerCharacteristicValid;

    std::set<int> removeHalfedges;
    SurfaceSimplificationRejectionReason rejection =
        SurfaceSimplificationRejectionReason::None;
    if (candidate.invalidated) {
      rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
    } else if (candidate.touchesHardFeature) {
      rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
    } else if (candidate.touchesBoundary) {
      rejection = SurfaceSimplificationRejectionReason::ProtectedBoundary;
    } else if (candidate.touchesSingularity) {
      rejection = SurfaceSimplificationRejectionReason::ProtectedSingularity;
    } else if (candidate.touchesLocalSheetBoundary ||
               (candidate.changesTopology && !candidate.topologyHealing) ||
               !std::isfinite(cost)) {
      rejection = SurfaceSimplificationRejectionReason::TopologyChanged;
    } else if (!candidate.affectedPatchDisk && !candidate.topologyHealing) {
      rejection = SurfaceSimplificationRejectionReason::NonDiskPatch;
    } else if (!candidate.sideFeasible && !candidate.topologyHealing) {
      rejection = SurfaceSimplificationRejectionReason::PatchInfeasible;
    } else if (candidate.descriptivenessWorsening >
               options.maxDescriptivenessWorsening + 1.0e-14) {
      rejection = SurfaceSimplificationRejectionReason::DescriptivenessWorsened;
    } else if (cost > options.objectiveTolerance + 1.0e-14) {
      rejection = SurfaceSimplificationRejectionReason::ObjectiveWorsened;
    }

    if (rejection == SurfaceSimplificationRejectionReason::None) {
      if (candidate.elementIds.empty()) {
        rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
      }
      for (const int halfedgeId : candidate.elementIds) {
        if (halfedgeId < 0 ||
            halfedgeId >= static_cast<int>(complex.halfedges.size())) {
          rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
          break;
        }
        const SurfaceArrangementHalfedge &halfedge =
            complex.halfedges[static_cast<std::size_t>(halfedgeId)];
        if (halfedge.twin < 0 ||
            halfedge.twin >= static_cast<int>(complex.halfedges.size()) ||
            halfedge.id > halfedge.twin ||
            !removeHalfedges.insert(halfedge.id).second) {
          rejection = SurfaceSimplificationRejectionReason::StaleCandidate;
          break;
        }
        const SurfaceArrangementHalfedge &twin =
            complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
        if (halfedge.hardFeature || twin.hardFeature) {
          rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
          break;
        }
        const bool boundary =
            halfedge.family < 0 || twin.family < 0 || halfedge.cell < 0 ||
            twin.cell < 0 ||
            halfedge.cell >= static_cast<int>(complex.cells.size()) ||
            twin.cell >= static_cast<int>(complex.cells.size()) ||
            complex.cells[static_cast<std::size_t>(halfedge.cell)].boundaryCycle ||
            complex.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle;
        if (boundary) {
          rejection = SurfaceSimplificationRejectionReason::ProtectedBoundary;
          break;
        }
        removeHalfedges.insert(halfedge.twin);
      }
    }

    if (rejection == SurfaceSimplificationRejectionReason::None) {
      const int beforeNonDiskDefect = non_disk_topology_defect(complex);
      transaction.beforeNonDiskDefect = beforeNonDiskDefect;
      SurfaceCellComplex trial = rebuild_complex_after_halfedge_removal(
          complex, removeHalfedges, vertices, faces);
      transaction.trialBuilt = true;
      ++result.incidenceRebuilds;
      transaction.afterNonDiskDefect = non_disk_topology_defect(trial);
      transaction.afterNodeCount = static_cast<int>(trial.nodes.size());
      transaction.afterUndirectedEdgeCount =
          static_cast<int>(trial.halfedges.size()) / 2;
      transaction.afterInteriorCellCount = static_cast<int>(std::count_if(
          trial.cells.begin(), trial.cells.end(),
          [](const SurfaceArrangementCell &cell) {
            return !cell.boundaryCycle;
          }));
      transaction.afterEulerCharacteristic =
          trial.diagnostics.eulerCharacteristic;
      transaction.afterConnectedComponentCount =
          trial.diagnostics.connectedComponentCount;
      transaction.afterBoundaryLoopCount =
          trial.diagnostics.boundaryLoopCount;
      transaction.afterUnsplitCrossings =
          trial.diagnostics.unsplitCrossings;
      transaction.afterGeometricTJunctions =
          trial.diagnostics.geometricTJunctions;
      transaction.incidenceValid = validate_complex_incidence(trial, false);
      transaction.embeddingValid = trial.diagnostics.embeddingValid;
      transaction.orientationValid = trial.diagnostics.orientationValid;
      transaction.boundaryLoopsValid = trial.diagnostics.boundaryLoopsValid;
      transaction.eulerCharacteristicValid =
          trial.diagnostics.eulerCharacteristicValid;
      transaction.noUnsplitCrossings =
          trial.diagnostics.unsplitCrossings == 0;
      transaction.noGeometricTJunctions =
          trial.diagnostics.geometricTJunctions == 0;
      const auto mismatch = [](const int value, const int source) {
        return std::abs(value - source);
      };
      transaction.topologyMismatchNotWorse =
          (!transaction.beforeEmbeddingValid ||
           transaction.embeddingValid) &&
          (!transaction.beforeOrientationValid ||
           transaction.orientationValid) &&
          (!transaction.beforeBoundaryLoopsValid ||
           transaction.boundaryLoopsValid) &&
          mismatch(transaction.afterEulerCharacteristic,
                   transaction.sourceEulerCharacteristic) <=
              mismatch(transaction.beforeEulerCharacteristic,
                       transaction.sourceEulerCharacteristic) &&
          mismatch(transaction.afterConnectedComponentCount,
                   transaction.sourceConnectedComponentCount) <=
              mismatch(transaction.beforeConnectedComponentCount,
                       transaction.sourceConnectedComponentCount) &&
          mismatch(transaction.afterBoundaryLoopCount,
                   transaction.sourceBoundaryLoopCount) <=
              mismatch(transaction.beforeBoundaryLoopCount,
                       transaction.sourceBoundaryLoopCount) &&
          transaction.afterUnsplitCrossings <=
              transaction.beforeUnsplitCrossings &&
          transaction.afterGeometricTJunctions <=
              transaction.beforeGeometricTJunctions;
      transaction.protectedSupportPreserved =
          same_protected_support(complex, trial);
      const bool healingTopologyValid =
          transaction.incidenceValid &&
          transaction.topologyMismatchNotWorse &&
          transaction.afterNonDiskDefect < beforeNonDiskDefect;
      const bool ordinaryTopologyValid =
          validate_complex_incidence(trial) && trial.diagnostics.topologyValid;
      const bool monotoneReduction =
          transaction.afterUndirectedEdgeCount <
          transaction.beforeUndirectedEdgeCount;
      if (!monotoneReduction ||
          (candidate.topologyHealing ? !healingTopologyValid
                                     : !ordinaryTopologyValid)) {
        rejection = SurfaceSimplificationRejectionReason::TopologyChanged;
      } else if (!transaction.protectedSupportPreserved) {
        rejection = SurfaceSimplificationRejectionReason::ProtectedFeature;
      } else {
        ++result.validationPasses;
        complex = std::move(trial);
        transaction.committed = true;
        transaction.rejection = SurfaceSimplificationRejectionReason::None;
        transaction.afterHash = complex_structural_hash(complex);
        ++result.committed;

        result.invalidatedCandidates +=
            std::max(0, static_cast<int>(candidates.size()) - 1);
        const bool commitLimitReached =
            options.maxCommittedTransactions >= 0 &&
            result.committed >= options.maxCommittedTransactions;
        if (options.refreshCandidatesAfterCommit && !commitLimitReached) {
          const SurfaceSimplificationCandidateSet refreshed =
              vertices != nullptr && faces != nullptr
                  ? extract_surface_simplification_candidates(
                        complex, *vertices, *faces)
                  : extract_surface_simplification_candidates(complex);
          ++currentGeneration;
          ++result.frontierGenerations;
          candidates = normalizeGeneration(refreshed.candidates, false);
          result.recomputedCandidates +=
              static_cast<int>(candidates.size());
          queue = std::priority_queue<QueueEntry>();
          for (int index = 0; index < static_cast<int>(candidates.size());
               ++index) {
            const SurfaceSimplificationCandidate &refreshedCandidate =
                candidates[static_cast<std::size_t>(index)];
            const double refreshedCost =
                objective_cost(refreshedCandidate, options.weights);
            queue.push({refreshedCost, refreshedCandidate.type,
                        refreshedCandidate.stableId, index});
          }
        } else {
          for (SurfaceSimplificationCandidate &other : candidates) {
            other.invalidated = true;
          }
        }
      }
    }

    if (rejection != SurfaceSimplificationRejectionReason::None) {
      transaction.committed = false;
      transaction.rejection = rejection;
      transaction.afterHash = complex_structural_hash(complex);
      ++result.rejected;
    }
    if (options.retainTransactionDetails) {
      result.transactions.push_back(std::move(transaction));
    }
  }

  result.complex = std::move(complex);
  result.finalActiveElements =
      static_cast<int>(result.complex.halfedges.size()) / 2;
  result.finalHash = complex_structural_hash(result.complex);
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationResult simplify_surface_cell_complex(
    SurfaceCellComplex inputComplex,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options) {
  return simplify_surface_cell_complex_impl(std::move(inputComplex),
                                             std::move(candidates),
                                             nullptr, nullptr, options);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationResult simplify_surface_cell_complex(
    SurfaceCellComplex inputComplex, const Eigen::MatrixXd &vertices,
    const Eigen::MatrixXi &faces,
    std::vector<SurfaceSimplificationCandidate> candidates,
    const SurfaceSimplificationOptions &options) {
  return simplify_surface_cell_complex_impl(std::move(inputComplex),
                                             std::move(candidates), &vertices,
                                             &faces, options);
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceSimplificationOverlay
make_surface_simplification_overlay(const SurfaceSimplificationResult &result) {
  SurfaceSimplificationOverlay overlay;
  const int transactionCount = static_cast<int>(result.transactions.size());
  overlay.candidateType.resize(transactionCount);
  overlay.retained.resize(static_cast<int>(result.elements.size()));
  overlay.removed.resize(static_cast<int>(result.elements.size()));
  overlay.rejectionReason.resize(transactionCount);
  overlay.objectiveCost.resize(transactionCount);
  for (int i = 0; i < transactionCount; ++i) {
    const SurfaceSimplificationTransaction &transaction =
        result.transactions[static_cast<std::size_t>(i)];
    overlay.candidateType(i) = static_cast<int>(transaction.type);
    overlay.rejectionReason(i) = static_cast<int>(transaction.rejection);
    overlay.objectiveCost(i) = transaction.objectiveCost;
  }
  for (int i = 0; i < static_cast<int>(result.elements.size()); ++i) {
    const bool active = result.elements[static_cast<std::size_t>(i)].active;
    overlay.retained(i) = active ? 1 : 0;
    overlay.removed(i) = active ? 0 : 1;
  }
  return overlay;
}

} // namespace directional::geometry
