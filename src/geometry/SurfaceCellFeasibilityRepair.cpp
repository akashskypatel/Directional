#include <directional/geometry/SurfaceCellFeasibilityRepair.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <type_traits>
#include <utility>

namespace directional::geometry::surface_cell_feasibility_detail {

namespace {

std::int64_t rail_id_leaf(const std::optional<authority::HardRailId> &rail) {
  return rail.has_value() ? static_cast<std::int64_t>(rail->index()) : -1;
}

struct SourceScope {
  std::optional<authority::TopologyRegionId> region;
  std::optional<SourceProjectionChart> chart;

  [[nodiscard]] bool valid() const noexcept {
    return region.has_value() && chart.has_value();
  }

  auto operator<=>(const SourceScope &) const = default;
};

struct RollbackIdentity {
  std::vector<std::uint64_t> values;
  std::vector<SourceScope> sourceScopes;
  std::vector<SourceProjectionChart> sourceCharts;

  friend bool operator==(const RollbackIdentity &,
                         const RollbackIdentity &) = default;
};

void append_rollback_word(RollbackIdentity &identity,
                          const std::int64_t value) {
  identity.values.push_back(static_cast<std::uint64_t>(value));
}

void append_rollback_double(RollbackIdentity &identity,
                            const double value) {
  std::uint64_t bits = 0U;
  static_assert(sizeof(bits) == sizeof(value));
  std::memcpy(&bits, &value, sizeof(bits));
  identity.values.push_back(bits);
}

template <typename T>
SourceScope source_scope(const T &value) {
  return {value.sourceTopologyRegion, value.sourceChart};
}

void append_source_scope_identity(
    RollbackIdentity &identity,
    const std::optional<authority::TopologyRegionId> &region,
    const std::optional<SourceProjectionChart> &chart) {
  identity.sourceScopes.push_back({region, chart});
}

void append_source_chart_identity(RollbackIdentity &identity,
                                  const SourceProjectionChart &chart) {
  identity.sourceCharts.push_back(chart);
}

RollbackIdentity exact_rollback_identity(
    const SurfaceCellComplex &complex) {
  RollbackIdentity identity;
  identity.values.reserve(complex.nodes.size() * 16U +
                          complex.halfedges.size() * 32U +
                          complex.cells.size() * 16U + 32U);
  append_rollback_word(
      identity,
      static_cast<std::int64_t>(complex.sourceOwnershipRegistry.size()));
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    append_rollback_word(
        identity,
        record.sourceTopologyRegion.has_value()
            ? static_cast<std::int64_t>(record.sourceTopologyRegion->index())
            : -1);
    append_rollback_word(
        identity, static_cast<std::int64_t>(record.exactCharts.size()));
    for (const SourceProjectionChart &chart : record.exactCharts) {
      append_source_chart_identity(identity, chart);
    }
  }

  append_rollback_word(identity, static_cast<std::int64_t>(complex.nodes.size()));
  for (const SurfaceArrangementNode &node : complex.nodes) {
    append_rollback_word(identity, node.id);
    append_rollback_word(identity, node.sourceFace);
    append_source_scope_identity(identity, node.sourceTopologyRegion,
                                 node.sourceChart);
    append_rollback_word(identity, node.hardBarrierCrossing ? 1 : 0);
    for (int corner = 0; corner < 3; ++corner) {
      append_rollback_double(identity, node.barycentric[corner]);
    }
    append_rollback_word(identity, node.sourceEdge);
    append_rollback_double(identity, node.sourceEdgeParameter);
    append_rollback_word(identity,
                         static_cast<std::int64_t>(node.occurrences.size()));
    for (const SurfaceArrangementNodeOccurrence &occurrence :
         node.occurrences) {
      append_rollback_word(identity, occurrence.sourceFace);
      append_source_scope_identity(identity, occurrence.sourceTopologyRegion,
                                   occurrence.sourceChart);
      append_rollback_word(identity, occurrence.sourceArc);
      append_rollback_word(identity, occurrence.provenance);
      append_rollback_word(identity, rail_id_leaf(occurrence.railId));
      append_rollback_word(identity, occurrence.curveId);
      append_rollback_double(identity, occurrence.sourceT0);
      append_rollback_double(identity, occurrence.sourceT1);
      append_rollback_double(identity, occurrence.railT0);
      append_rollback_double(identity, occurrence.railT1);
      for (int corner = 0; corner < 3; ++corner) {
        append_rollback_double(identity, occurrence.barycentric[corner]);
      }
    }
  }

  append_rollback_word(
      identity, static_cast<std::int64_t>(complex.halfedges.size()));
  for (const SurfaceArrangementHalfedge &edge : complex.halfedges) {
    for (const std::int64_t value :
         std::array<std::int64_t, 20>{
             edge.id, edge.twin, edge.next, edge.from, edge.to,
             edge.sourceArc, edge.family, edge.strand, edge.featureClass,
             edge.sourceFace, edge.hardFeature ? 1 : 0,
             edge.layoutSupport ? 1 : 0, edge.singularitySupport ? 1 : 0,
             rail_id_leaf(edge.railId), edge.curveId, edge.proposalId,
             edge.proposalSeedId, edge.proposalSide,
             edge.proposalBoundarySegment, edge.cell}) {
      append_rollback_word(identity, value);
    }
    append_source_scope_identity(identity, edge.sourceTopologyRegion,
                                 edge.sourceChart);
    append_rollback_double(identity, edge.sourceT0);
    append_rollback_double(identity, edge.sourceT1);
    append_rollback_double(identity, edge.railT0);
    append_rollback_double(identity, edge.railT1);
    append_rollback_word(
        identity, static_cast<std::int64_t>(edge.provenance.size()));
    for (const SurfaceArrangementProvenance &provenance : edge.provenance) {
      for (const std::int64_t value :
           std::array<std::int64_t, 15>{
               provenance.sourceArc, provenance.provenance,
               provenance.sourceFace, provenance.family, provenance.strand,
               provenance.featureClass, provenance.hardFeature ? 1 : 0,
               provenance.layoutSupport ? 1 : 0,
               provenance.singularitySupport ? 1 : 0,
               rail_id_leaf(provenance.railId), provenance.curveId,
               provenance.proposalId, provenance.proposalSeedId,
               provenance.proposalSide,
               provenance.proposalBoundarySegment}) {
        append_rollback_word(identity, value);
      }
      append_source_scope_identity(identity, provenance.sourceTopologyRegion,
                                   provenance.sourceChart);
      append_rollback_double(identity, provenance.sourceT0);
      append_rollback_double(identity, provenance.sourceT1);
      append_rollback_double(identity, provenance.railT0);
      append_rollback_double(identity, provenance.railT1);
    }
  }

  append_rollback_word(identity, static_cast<std::int64_t>(complex.cells.size()));
  for (const SurfaceArrangementCell &cell : complex.cells) {
    append_rollback_word(identity, cell.id);
    append_rollback_word(identity, cell.sourceFace);
    append_rollback_word(
        identity, cell.sourceTopologyRegion.has_value()
                      ? static_cast<std::int64_t>(
                            cell.sourceTopologyRegion->index())
                      : -1);
    append_rollback_word(
        identity, surface_cell_ownership_class_representation_leaf(
                      cell.sourceOwnershipClass));
    append_rollback_word(identity,
                         static_cast<std::int64_t>(cell.sourceCharts.size()));
    for (const SourceProjectionChart &chart : cell.sourceCharts) {
      append_source_chart_identity(identity, chart);
    }
    const auto appendVector = [&](const std::vector<int> &values) {
      append_rollback_word(identity,
                           static_cast<std::int64_t>(values.size()));
      for (const int value : values) {
        append_rollback_word(identity, value);
      }
    };
    appendVector(cell.sourceFaces);
    appendVector(cell.halfedges);
    appendVector(cell.boundaryCycleOffsets);
    appendVector(cell.sourceBoundaryLoopIds);
    appendVector(cell.sideFamilies);
    appendVector(cell.sideEdgeCounts);
    append_rollback_double(identity, cell.signedArea);
    append_rollback_double(identity, cell.area);
    for (const std::int64_t value :
         {cell.boundaryCycle ? 1 : 0, cell.closed ? 1 : 0,
          cell.disk ? 1 : 0, cell.cutCellDisk ? 1 : 0,
          cell.bridgeExcursion ? 1 : 0,
          cell.supportOnlyCycle ? 1 : 0, cell.boundaryComponentCount,
          cell.eulerCharacteristic, cell.sourceBoundarySide,
          cell.quadReady ? 1 : 0,
          static_cast<int>(cell.cellClass),
          static_cast<int>(cell.rejectReason)}) {
      append_rollback_word(identity, value);
    }
  }

  const SurfaceArrangementDiagnostics &d = complex.diagnostics;
  const std::array<std::int64_t, 32> diagnosticsIdentity{{
      d.plantedIntersections, d.uniqueIntersections, d.unsplitCrossings,
      d.geometricTJunctions, d.incompleteArcChains,
      d.hardBarrierCrossings, d.eulerCharacteristic,
      d.sourceEulerCharacteristic, d.connectedComponentCount,
      d.sourceConnectedComponentCount, d.boundaryLoopCount,
      d.sourceBoundaryLoopCount, d.directedWedgeCount,
      d.successorMissingCount, d.successorAmbiguityCount,
      d.predecessorMultiplicityFailureCount, d.repeatedNodeCycleCount,
      d.repeatedEdgeCycleCount, static_cast<int>(d.incidenceFailure),
      d.incidenceFailureNode, d.incidenceFailureHalfedge,
      d.incidenceFailureTwin, d.incidenceFailureNext,
      static_cast<std::int64_t>(d.directedIncidenceHash),
      d.incidenceValid ? 1 : 0, d.embeddingValid ? 1 : 0,
      d.orientationValid ? 1 : 0, d.cellsDiskValid ? 1 : 0,
      d.boundaryLoopsValid ? 1 : 0,
      d.eulerCharacteristicValid ? 1 : 0,
      d.topologyValid ? 1 : 0, d.peakSegmentsPerFace}};
  for (const std::int64_t value : diagnosticsIdentity) {
    append_rollback_word(identity, value);
  }
  append_rollback_double(identity, d.supportedArea);
  append_rollback_double(identity, d.extractedArea);
  append_rollback_double(identity, d.relativeAreaError);
  append_rollback_double(identity, d.memoryRatioEstimate);
  append_rollback_double(identity, d.measuredMemoryRatio);
  identity.values.push_back(d.inputMemoryBytes);
  identity.values.push_back(d.retainedMemoryBytes);
  identity.values.push_back(d.peakMemoryBytes);
  return identity;
}

std::uint64_t rollback_identity_hash(const RollbackIdentity &identity) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::uint64_t word) {
    hash ^= word;
    hash *= 1099511628211ULL;
  };
  for (const std::uint64_t word : identity.values) {
    mix(word);
  }
  // Collision-domain diagnostic only. Exact rollback equivalence below uses
  // typed source authority directly and never decodes this hash.
  mix(static_cast<std::uint64_t>(identity.sourceScopes.size()));
  for (const SourceScope &scope : identity.sourceScopes) {
    mix(scope.region.has_value() ? 1U : 0U);
    mix(scope.chart.has_value() ? 1U : 0U);
  }
  mix(static_cast<std::uint64_t>(identity.sourceCharts.size()));
  return hash;
}

} // namespace

int canonical_halfedge(const SurfaceCellComplex &complex, const int id) {
  if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) {
    return -1;
  }
  const int twin = complex.halfedges[static_cast<std::size_t>(id)].twin;
  if (twin < 0 || twin >= static_cast<int>(complex.halfedges.size())) {
    return -1;
  }
  return std::min(id, twin);
}

Eigen::RowVector3d interpolated_barycentric(
    const SurfaceCellComplex &complex, const int from, const int to,
    const int face, const SurfaceArrangementHalfedge &edge,
    const double alpha) {
  const auto edge_barycentric = [&](const SurfaceArrangementNode &node) {
    const int provenance = edge.provenance.empty()
                               ? -1
                               : edge.provenance.front().provenance;
    const SourceScope edgeScope = source_scope(edge);
    for (const SurfaceArrangementNodeOccurrence &occurrence :
         node.occurrences) {
      if (occurrence.sourceFace == face &&
          source_scope(occurrence) == edgeScope &&
          occurrence.sourceArc == edge.sourceArc &&
          (provenance < 0 || occurrence.provenance == provenance)) {
        return occurrence.barycentric;
      }
    }
    return surface_arrangement_detail::node_barycentric_on_face(node, face);
  };
  const Eigen::RowVector3d a =
      edge_barycentric(complex.nodes[static_cast<std::size_t>(from)]);
  const Eigen::RowVector3d b =
      edge_barycentric(complex.nodes[static_cast<std::size_t>(to)]);
  if (!a.allFinite() || !b.allFinite()) {
    return Eigen::RowVector3d::Constant(
        std::numeric_limits<double>::quiet_NaN());
  }
  Eigen::RowVector3d result = (1.0 - alpha) * a + alpha * b;
  for (int corner = 0; corner < 3; ++corner) {
    if (std::abs(result[corner]) <= 1.0e-14) {
      result[corner] = 0.0;
    }
  }
  const double sum = result.sum();
  if (!std::isfinite(sum) || std::abs(sum) <= 1.0e-14) {
    return Eigen::RowVector3d::Constant(
        std::numeric_limits<double>::quiet_NaN());
  }
  result /= sum;
  return result;
}


bool valid_source_face_index(const int face,
                             const Eigen::MatrixXi *sourceFaces) {
  return face >= 0 &&
         (sourceFaces == nullptr ||
          (sourceFaces->cols() == 3 && face < sourceFaces->rows()));
}

std::set<int> node_supported_faces(
    const SurfaceArrangementNode &node,
    const Eigen::MatrixXi *sourceFaces,
    const std::optional<SourceScope> &requestedScope = std::nullopt) {
  std::set<int> result;
  const auto add = [&](const int face, const SourceScope &storedScope) {
    // Face membership and chart validity are separate contracts. Preserve a
    // declared common chart here so midpoint interpolation can report the
    // typed InvalidMidpointEmbedding failure for malformed chart data.
    if (!valid_source_face_index(face, sourceFaces) ||
        (requestedScope.has_value() && storedScope != requestedScope.value())) {
      return;
    }
    result.insert(face);
  };
  const SourceScope nodeScope = source_scope(node);
  if (nodeScope.valid()) {
    add(node.sourceFace, nodeScope);
  }
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    const SourceScope occurrenceScope = source_scope(occurrence);
    if (occurrenceScope.valid()) {
      add(occurrence.sourceFace, occurrenceScope);
    }
  }
  return result;
}

std::vector<int> common_edge_source_faces(
    const SurfaceArrangementNode &from,
    const SurfaceArrangementNode &to,
    const SurfaceArrangementHalfedge &oriented,
    const Eigen::MatrixXi *sourceFaces) {
  const SourceScope orientedScope = source_scope(oriented);
  if (!orientedScope.valid()) {
    return {};
  }
  const std::set<int> fromFaces =
      node_supported_faces(from, sourceFaces, orientedScope);
  const std::set<int> toFaces =
      node_supported_faces(to, sourceFaces, orientedScope);
  std::vector<int> common;
  std::set_intersection(fromFaces.begin(), fromFaces.end(),
                        toFaces.begin(), toFaces.end(),
                        std::back_inserter(common));
  const auto priority = [&](const int face) {
    if (face == oriented.sourceFace) {
      return 0;
    }
    const bool orientedProvenance = std::any_of(
        oriented.provenance.begin(), oriented.provenance.end(),
        [&](const SurfaceArrangementProvenance &value) {
          return value.sourceFace == face &&
                 source_scope(value) == orientedScope;
        });
    return orientedProvenance ? 1 : 2;
  };
  std::sort(common.begin(), common.end(), [&](const int lhs, const int rhs) {
    return std::make_tuple(priority(lhs), lhs) <
           std::make_tuple(priority(rhs), rhs);
  });
  return common;
}


void split_provenance_interval(
    const std::vector<SurfaceArrangementProvenance> &source,
    const double alpha0, const double alpha1,
    std::vector<SurfaceArrangementProvenance> &target) {
  target = source;
  for (SurfaceArrangementProvenance &value : target) {
    const double sourceStart = value.sourceT0;
    const double sourceEnd = value.sourceT1;
    const double railStart = value.railT0;
    const double railEnd = value.railT1;
    value.sourceT0 = (1.0 - alpha0) * sourceStart + alpha0 * sourceEnd;
    value.sourceT1 = (1.0 - alpha1) * sourceStart + alpha1 * sourceEnd;
    value.railT0 = (1.0 - alpha0) * railStart + alpha0 * railEnd;
    value.railT1 = (1.0 - alpha1) * railStart + alpha1 * railEnd;
  }
}

int odd_bounded_cell_count(const SurfaceCellComplex &complex) {
  return static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.halfedges.size() % 2U != 0U;
      }));
}

bool validate_incidence_allowing_nondisk(const SurfaceCellComplex &complex) {
  for (int node = 0; node < static_cast<int>(complex.nodes.size()); ++node) {
    if (complex.nodes[static_cast<std::size_t>(node)].id != node) {
      return false;
    }
  }
  std::vector<int> useCount(complex.halfedges.size(), 0);
  for (int id = 0; id < static_cast<int>(complex.halfedges.size()); ++id) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    if (edge.id != id || edge.twin < 0 ||
        edge.twin >= static_cast<int>(complex.halfedges.size()) ||
        edge.next < 0 ||
        edge.next >= static_cast<int>(complex.halfedges.size()) ||
        edge.from < 0 || edge.from >= static_cast<int>(complex.nodes.size()) ||
        edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()) ||
        edge.from == edge.to || edge.cell < 0 ||
        edge.cell >= static_cast<int>(complex.cells.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(edge.twin)];
    if (twin.twin != id || twin.from != edge.to || twin.to != edge.from) {
      return false;
    }
  }
  for (int id = 0; id < static_cast<int>(complex.cells.size()); ++id) {
    const SurfaceArrangementCell &cell =
        complex.cells[static_cast<std::size_t>(id)];
    if (cell.id != id || !cell.closed || cell.halfedges.size() < 2U ||
        cell.sideFamilies.size() != cell.sideEdgeCounts.size()) {
      return false;
    }
    std::vector<std::pair<std::size_t, std::size_t>> boundaryRanges;
    if (!surface_arrangement_boundary_cycle_ranges(cell, boundaryRanges)) {
      return false;
    }
    std::set<int> seenHalfedges;
    for (const auto &[begin, end] : boundaryRanges) {
      for (std::size_t index = begin; index < end; ++index) {
        const int edgeId = cell.halfedges[index];
        if (edgeId < 0 ||
            edgeId >= static_cast<int>(complex.halfedges.size()) ||
            !seenHalfedges.insert(edgeId).second) {
          return false;
        }
        const SurfaceArrangementHalfedge &edge =
            complex.halfedges[static_cast<std::size_t>(edgeId)];
        const int nextId =
            cell.halfedges[index + 1U < end ? index + 1U : begin];
        if (edge.cell != id || edge.next != nextId ||
            edge.to !=
                complex.halfedges[static_cast<std::size_t>(nextId)].from) {
          return false;
        }
        ++useCount[static_cast<std::size_t>(edgeId)];
      }
    }
  }
  return std::all_of(useCount.begin(), useCount.end(),
                     [](const int count) { return count == 1; });
}

SurfaceCellDomainIdentityAudit audit_simple_cell_boundary(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell) {
  SurfaceCellDomainIdentityAudit audit;
  audit.cellId = cell.id;
  std::set<int> seenHalfedges;
  std::set<int> seenNodes;
  if (!cell.closed || cell.boundaryComponentCount != 1 ||
      cell.halfedges.size() < 3U) {
    audit.failure = SurfaceCellDomainIdentityFailureKind::NonSimpleBoundary;
    return audit;
  }
  for (std::size_t index = 0; index < cell.halfedges.size(); ++index) {
    const int halfedgeId = cell.halfedges[index];
    audit.halfedgeId = halfedgeId;
    if (halfedgeId < 0 ||
        halfedgeId >= static_cast<int>(complex.halfedges.size())) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::InvalidHalfedge;
      return audit;
    }
    if (!seenHalfedges.insert(halfedgeId).second) {
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::RepeatedBoundaryHalfedge;
      return audit;
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    audit.nodeId = edge.from;
    audit.sourceFace = edge.sourceFace;
    audit.sourceComponent = -1;
    audit.sourceSheet = -1;
    if (!seenNodes.insert(edge.from).second) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::RepeatedBoundaryNode;
      return audit;
    }
    const int expectedNext =
        cell.halfedges[(index + 1U) % cell.halfedges.size()];
    if (edge.cell != cell.id || edge.next != expectedNext ||
        edge.to != complex.halfedges[static_cast<std::size_t>(expectedNext)].from) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::NonSimpleBoundary;
      return audit;
    }
  }
  audit.valid = true;
  audit.failure = SurfaceCellDomainIdentityFailureKind::None;
  audit.halfedgeId = -1;
  audit.nodeId = -1;
  return audit;
}

bool supported_side_metadata(const SurfaceArrangementCell &cell) {
  const int sides = static_cast<int>(cell.sideEdgeCounts.size());
  return !cell.boundaryCycle && cell.disk && sides >= 3 && sides <= 6 &&
         cell.sideFamilies.size() == cell.sideEdgeCounts.size() &&
         std::accumulate(cell.sideEdgeCounts.begin(),
                         cell.sideEdgeCounts.end(), 0) ==
             static_cast<int>(cell.halfedges.size());
}

void canonicalize_logical_sides(SurfaceCellComplex &complex,
                                const Eigen::MatrixXd &sourceVertices,
                                const Eigen::MatrixXi &sourceFaces) {
  for (SurfaceArrangementCell &cell : complex.cells) {
    cell.sideFamilies.clear();
    cell.sideEdgeCounts.clear();
    int previousHalfedge = -1;
    for (const int halfedgeId : cell.halfedges) {
      const SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      const int family = edge.family < 0
                             ? -1
                             : ((edge.family % 2) + 2) % 2;
      bool continues = !cell.sideFamilies.empty() &&
                       cell.sideFamilies.back() == family;
      if (continues && previousHalfedge >= 0) {
        const SurfaceArrangementHalfedge &previous =
            complex.halfedges[static_cast<std::size_t>(previousHalfedge)];
        continues = surface_arrangement_detail::same_logical_side(
            previous, edge, complex.nodes, sourceVertices, sourceFaces);
      }
      if (!continues) {
        cell.sideFamilies.push_back(family);
        cell.sideEdgeCounts.push_back(1);
      } else {
        ++cell.sideEdgeCounts.back();
      }
      previousHalfedge = halfedgeId;
    }
    if (cell.sideFamilies.size() > 1U &&
        cell.sideFamilies.front() == cell.sideFamilies.back()) {
      bool merge = false;
      if (!cell.halfedges.empty()) {
        const SurfaceArrangementHalfedge &last = complex.halfedges[
            static_cast<std::size_t>(cell.halfedges.back())];
        const SurfaceArrangementHalfedge &first = complex.halfedges[
            static_cast<std::size_t>(cell.halfedges.front())];
        merge = surface_arrangement_detail::same_logical_side(
            last, first, complex.nodes, sourceVertices, sourceFaces);
      }
      if (merge) {
        cell.sideEdgeCounts.front() += cell.sideEdgeCounts.back();
        cell.sideEdgeCounts.pop_back();
        cell.sideFamilies.pop_back();
      }
    }
  }
}

bool side_equations_hold(const std::vector<int> &counts) {
  const int sides = static_cast<int>(counts.size());
  if (sides < 3 || sides > 6 ||
      std::any_of(counts.begin(), counts.end(),
                  [](const int value) { return value <= 0; }) ||
      std::accumulate(counts.begin(), counts.end(), 0) % 2 != 0) {
    return false;
  }
  if (sides == 3) {
    return counts[0] <= counts[1] + counts[2] &&
           counts[1] <= counts[2] + counts[0] &&
           counts[2] <= counts[0] + counts[1];
  }
  if (sides == 4) {
    return counts[0] == counts[2] && counts[1] == counts[3];
  }
  if (sides == 5) {
    for (int side = 0; side < 5; ++side) {
      if (counts[side] + counts[(side + 1) % 5] +
              counts[(side + 4) % 5] <
          counts[(side + 2) % 5] + counts[(side + 3) % 5]) {
        return false;
      }
    }
    return true;
  }
  for (int side = 0; side < 6; ++side) {
    if (counts[side] > counts[(side + 2) % 6] + counts[(side + 4) % 6]) {
      return false;
    }
  }
  return counts[0] + counts[2] + counts[4] ==
         counts[1] + counts[3] + counts[5];
}

int side_equation_defect(const std::vector<int> &counts) {
  const int sides = static_cast<int>(counts.size());
  if (sides < 3 || sides > 6 ||
      std::any_of(counts.begin(), counts.end(),
                  [](const int value) { return value <= 0; })) {
    return std::numeric_limits<int>::max() / 4;
  }
  int defect = std::accumulate(counts.begin(), counts.end(), 0) & 1;
  if (sides == 3) {
    for (int side = 0; side < 3; ++side) {
      defect += std::max(0, counts[side] - counts[(side + 1) % 3] -
                               counts[(side + 2) % 3]);
    }
    return defect;
  }
  if (sides == 4) {
    return defect + std::abs(counts[0] - counts[2]) +
           std::abs(counts[1] - counts[3]);
  }
  if (sides == 5) {
    for (int side = 0; side < 5; ++side) {
      const int lhs = counts[side] + counts[(side + 1) % 5] +
                      counts[(side + 4) % 5];
      const int rhs = counts[(side + 2) % 5] + counts[(side + 3) % 5];
      defect += std::max(0, rhs - lhs);
    }
    return defect;
  }
  const int even = counts[0] + counts[2] + counts[4];
  const int odd = counts[1] + counts[3] + counts[5];
  defect += std::abs(even - odd);
  for (const std::array<int, 3> group :
       {std::array<int, 3>{0, 2, 4}, std::array<int, 3>{1, 3, 5}}) {
    for (int local = 0; local < 3; ++local) {
      defect += std::max(0, counts[group[local]] -
                                counts[group[(local + 1) % 3]] -
                                counts[group[(local + 2) % 3]]);
    }
  }
  return defect;
}

std::vector<std::vector<int>> side_halfedges(
    const SurfaceArrangementCell &cell) {
  std::vector<std::vector<int>> result(cell.sideEdgeCounts.size());
  int offset = 0;
  for (int side = 0; side < static_cast<int>(cell.sideEdgeCounts.size());
       ++side) {
    for (int local = 0;
         local < cell.sideEdgeCounts[static_cast<std::size_t>(side)];
         ++local) {
      result[static_cast<std::size_t>(side)].push_back(
          cell.halfedges[static_cast<std::size_t>(offset++)]);
    }
  }
  return result;
}

std::vector<int> effective_side_counts(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::map<int, int> &insertions) {
  std::vector<int> counts = cell.sideEdgeCounts;
  const auto sides = side_halfedges(cell);
  for (int side = 0; side < static_cast<int>(sides.size()); ++side) {
    for (const int halfedge : sides[static_cast<std::size_t>(side)]) {
      const int canonical = canonical_halfedge(complex, halfedge);
      const auto found = insertions.find(canonical);
      if (found != insertions.end()) {
        counts[static_cast<std::size_t>(side)] += found->second;
      }
    }
  }
  return counts;
}

std::vector<int> local_side_repair_delta(const std::vector<int> &counts,
                                         const int maxLocalInsertions) {
  const int sides = static_cast<int>(counts.size());
  std::vector<int> delta(static_cast<std::size_t>(sides), 0);
  if (side_equations_hold(counts)) {
    return delta;
  }
  if (sides == 3) {
    int maximum = 0;
    for (int side = 1; side < 3; ++side) {
      if (counts[side] > counts[maximum]) {
        maximum = side;
      }
    }
    const int first = (maximum + 1) % 3;
    const int second = (maximum + 2) % 3;
    const int deficit =
        std::max(0, counts[maximum] - counts[first] - counts[second]);
    if (deficit > 0) {
      const int target = counts[first] <= counts[second] ? first : second;
      delta[static_cast<std::size_t>(target)] = deficit;
    } else {
      const int target = static_cast<int>(std::min_element(
                             counts.begin(), counts.end()) -
                         counts.begin());
      delta[static_cast<std::size_t>(target)] = 1;
    }
    return delta;
  }
  if (sides == 4) {
    for (const auto [first, second] :
         {std::pair<int, int>{0, 2}, {1, 3}}) {
      if (counts[first] < counts[second]) {
        delta[static_cast<std::size_t>(first)] =
            counts[second] - counts[first];
      } else if (counts[second] < counts[first]) {
        delta[static_cast<std::size_t>(second)] =
            counts[first] - counts[second];
      }
    }
    return delta;
  }
  if (sides == 5) {
    // Equal side counts satisfy every pentagonal side inequality.  Raising
    // each side to the current maximum therefore gives a deterministic,
    // linear-time feasible target and avoids the combinatorial composition
    // search previously used here.  If the resulting perimeter is odd, one
    // further subdivision is sufficient; choosing the lowest target side
    // keeps the result deterministic and preserves every inequality.
    const int maximum = *std::max_element(counts.begin(), counts.end());
    std::vector<int> target(5, maximum);
    if (std::accumulate(target.begin(), target.end(), 0) % 2 != 0) {
      const int side = static_cast<int>(std::min_element(
                           counts.begin(), counts.end()) -
                       counts.begin());
      ++target[static_cast<std::size_t>(side)];
    }
    int inserted = 0;
    for (int side = 0; side < 5; ++side) {
      delta[static_cast<std::size_t>(side)] =
          target[static_cast<std::size_t>(side)] -
          counts[static_cast<std::size_t>(side)];
      inserted += delta[static_cast<std::size_t>(side)];
    }
    return inserted <= maxLocalInsertions && side_equations_hold(target)
               ? delta
               : std::vector<int>{};
  }
  if (sides == 6) {
    std::vector<int> target = counts;
    const auto repair_triplet = [&](const std::array<int, 3> &indices) {
      int maximum = indices[0];
      for (const int index : indices) {
        if (target[index] > target[maximum]) {
          maximum = index;
        }
      }
      std::vector<int> others;
      for (const int index : indices) {
        if (index != maximum) {
          others.push_back(index);
        }
      }
      const int deficit = std::max(
          0, target[maximum] - target[others[0]] - target[others[1]]);
      const int destination =
          target[others[0]] <= target[others[1]] ? others[0] : others[1];
      target[destination] += deficit;
    };
    const std::array<int, 3> even{0, 2, 4};
    const std::array<int, 3> odd{1, 3, 5};
    repair_triplet(even);
    repair_triplet(odd);
    auto sum = [&](const std::array<int, 3> &indices) {
      return target[indices[0]] + target[indices[1]] + target[indices[2]];
    };
    while (sum(even) != sum(odd)) {
      const auto &lower = sum(even) < sum(odd) ? even : odd;
      const int destination = *std::min_element(
          lower.begin(), lower.end(),
          [&](const int a, const int b) {
            return std::tie(target[a], a) < std::tie(target[b], b);
          });
      ++target[destination];
    }
    for (int side = 0; side < 6; ++side) {
      delta[static_cast<std::size_t>(side)] =
          target[static_cast<std::size_t>(side)] -
          counts[static_cast<std::size_t>(side)];
    }
    return side_equations_hold(target) ? delta : std::vector<int>{};
  }
  return {};
}

int side_infeasible_cell_count(const SurfaceCellComplex &complex,
                               const std::map<int, int> &insertions) {
  int count = 0;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (supported_side_metadata(cell) &&
        !side_equations_hold(
            effective_side_counts(complex, cell, insertions))) {
      ++count;
    }
  }
  return count;
}

int total_side_equation_defect(const SurfaceCellComplex &complex,
                               const std::map<int, int> &insertions) {
  int defect = 0;
  for (const SurfaceArrangementCell &cell : complex.cells) {
    if (supported_side_metadata(cell)) {
      defect += side_equation_defect(
          effective_side_counts(complex, cell, insertions));
    }
  }
  return defect;
}

} // namespace directional::geometry::surface_cell_feasibility_detail

namespace directional::geometry {

namespace {

SurfaceCellSubdivisionFailure subdivision_failure_from_product(
    SurfaceCellSubdivisionProduct &&product,
    const SurfaceCellSubdivisionFailureKind kind, std::string detail) {
  SurfaceCellSubdivisionFailure failure;
  failure.kind = kind;
  failure.detail = std::move(detail);
  failure.rollbackEquivalent = product.rollbackEquivalent;
  failure.rollbackIdentityHashBefore = product.rollbackIdentityHashBefore;
  failure.rollbackIdentityHashAfter = product.rollbackIdentityHashAfter;
  failure.rollbackUndoOwnedBytes = product.rollbackUndoOwnedBytes;
  failure.splitUndirectedEdges = product.splitUndirectedEdges;
  failure.insertedVertices = product.insertedVertices;
  failure.hardFeatureSplits = product.hardFeatureSplits;
  failure.firstScopeFailure = std::move(product.firstScopeFailure);
  failure.firstDomainFailure = std::move(product.firstDomainFailure);
  return failure;
}

SurfaceCellParityRepairFailure parity_failure_from_product(
    SurfaceCellParityRepairProduct &&product,
    const SurfaceCellParityRepairFailureKind kind, std::string detail,
    std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure =
        std::nullopt) {
  SurfaceCellParityRepairFailure failure;
  failure.kind = kind;
  failure.detail = std::move(detail);
  failure.splitHalfedges = std::move(product.splitHalfedges);
  failure.oddCellsBefore = product.oddCellsBefore;
  failure.oddCellsAfter = product.oddCellsAfter;
  failure.hardFeatureSplits = product.hardFeatureSplits;
  failure.alternativeCandidateBudget = product.alternativeCandidateBudget;
  failure.alternativeCandidatesAttempted =
      product.alternativeCandidatesAttempted;
  failure.alternativeVisitedStates = product.alternativeVisitedStates;
  failure.alternativeSelectedExclusion = product.alternativeSelectedExclusion;
  failure.alternativeStateSequenceHash = product.alternativeStateSequenceHash;
  failure.alternativeStateHashes = std::move(product.alternativeStateHashes);
  failure.alternativeDisposition = product.alternativeDisposition;
  failure.firstScopeFailure = std::move(product.firstScopeFailure);
  failure.firstDomainFailure = std::move(product.firstDomainFailure);
  failure.subdivisionFailure = std::move(subdivisionFailure);
  return failure;
}

SurfaceCellSideRepairFailure side_failure_from_product(
    SurfaceCellSideRepairProduct &&product,
    const SurfaceCellSideRepairFailureKind kind, std::string detail,
    std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure =
        std::nullopt) {
  SurfaceCellSideRepairFailure failure;
  failure.kind = kind;
  failure.detail = std::move(detail);
  failure.rollbackEquivalent = product.rollbackEquivalent;
  failure.rollbackIdentityHashBefore = product.rollbackIdentityHashBefore;
  failure.rollbackIdentityHashAfter = product.rollbackIdentityHashAfter;
  failure.rollbackUndoOwnedBytes = product.rollbackUndoOwnedBytes;
  failure.infeasibleCellsBefore = product.infeasibleCellsBefore;
  failure.infeasibleCellsAfter = product.infeasibleCellsAfter;
  failure.initialEquationDefect = product.initialEquationDefect;
  failure.finalEquationDefect = product.finalEquationDefect;
  failure.propagationPasses = product.propagationPasses;
  failure.attemptedInsertions = product.attemptedInsertions;
  failure.insertedVertices = product.insertedVertices;
  failure.splitUndirectedEdges = product.splitUndirectedEdges;
  failure.hardFeatureSplits = product.hardFeatureSplits;
  failure.firstDomainFailure = std::move(product.firstDomainFailure);
  failure.subdivisionFailure = std::move(subdivisionFailure);
  return failure;
}

std::optional<SurfaceCellSideRepairPreparationReason>
side_repair_fallback_preparation_reason(
    const SurfaceCellSideRepairFailureKind kind) {
  switch (kind) {
  case SurfaceCellSideRepairFailureKind::LocalSideInsertionLimit:
    return SurfaceCellSideRepairPreparationReason::LocalSideInsertionLimit;
  case SurfaceCellSideRepairFailureKind::CoupledSideRepairStalled:
    return SurfaceCellSideRepairPreparationReason::CoupledSideRepairStalled;
  case SurfaceCellSideRepairFailureKind::SideRepairInsertionLimit:
    return SurfaceCellSideRepairPreparationReason::SideRepairInsertionLimit;
  case SurfaceCellSideRepairFailureKind::SideRepairPropagationLimit:
    return SurfaceCellSideRepairPreparationReason::SideRepairPropagationLimit;
  default:
    return std::nullopt;
  }
}

} // namespace

bool SurfaceCellSubdivisionResult::rollback_matches(
    const SurfaceCellComplex &expected) const {
  return rollbackEvidence_.has_value() &&
         surface_cell_feasibility_detail::exact_rollback_identity(
             *rollbackEvidence_) ==
             surface_cell_feasibility_detail::exact_rollback_identity(expected);
}

bool SurfaceCellSideRepairResult::rollback_matches(
    const SurfaceCellComplex &expected) const {
  return rollbackEvidence_.has_value() &&
         surface_cell_feasibility_detail::exact_rollback_identity(
             *rollbackEvidence_) ==
             surface_cell_feasibility_detail::exact_rollback_identity(expected);
}

SurfaceCellSubdivisionResult subdivide_surface_cell_complex_edges(
    SurfaceCellComplex input,
    const std::map<int, int> &insertionsByHalfedge,
    const Eigen::MatrixXi *sourceFaces) {
  SurfaceCellSubdivisionProduct result;
  const auto rollbackIdentity =
      surface_cell_feasibility_detail::exact_rollback_identity(input);
  result.rollbackIdentityHashBefore =
      surface_cell_feasibility_detail::rollback_identity_hash(
          rollbackIdentity);

  const auto returnCommittedFailure =
      [&](SurfaceCellSubdivisionFailureKind kind,
          std::string detail) -> SurfaceCellSubdivisionResult {
    SurfaceCellComplex rollbackEvidence = std::move(input);
    const auto after =
        surface_cell_feasibility_detail::exact_rollback_identity(
            rollbackEvidence);
    result.rollbackIdentityHashAfter =
        surface_cell_feasibility_detail::rollback_identity_hash(after);
    result.rollbackEquivalent = after == rollbackIdentity;
    if (!result.rollbackEquivalent) {
      kind = SurfaceCellSubdivisionFailureKind::RollbackMismatch;
      detail = "SubdivisionRollbackMismatch:" + detail;
    }
    return SurfaceCellSubdivisionResult::rejected(
        subdivision_failure_from_product(std::move(result), kind,
                                         std::move(detail)),
        std::move(rollbackEvidence));
  };

  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(input)) {
    return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::InvalidInputIncidence, "InvalidInputIncidence");
  }

  std::map<int, int> insertionCount;
  for (const auto &[id, count] : insertionsByHalfedge) {
    if (count <= 0) {
      return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::InvalidInsertionCount, "InvalidInsertionCount");
    }
    const int canonical =
        surface_cell_feasibility_detail::canonical_halfedge(input, id);
    if (canonical < 0) {
      return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::InvalidHalfedge, "InvalidHalfedge");
    }
    const auto [iterator, inserted] = insertionCount.emplace(canonical, count);
    if (!inserted && iterator->second != count) {
      return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::ConflictingTwinInsertionCount, "ConflictingTwinInsertionCount");
    }
  }
  if (insertionCount.empty()) {
    result.complex = std::move(input);
    result.rollbackEquivalent = true;
    result.rollbackIdentityHashAfter = result.rollbackIdentityHashBefore;
    return SurfaceCellSubdivisionResult::produced(std::move(result));
  }

  // Resolve typed source ownership before mutation. Every repaired boundary
  // edge must already carry its topology-region and exact projection-chart
  // authority, and that authority must be contained by the owning cell. No
  // component/sheet compatibility fallback is reconstructed here.
  for (const SurfaceArrangementCell &cell : input.cells) {
    if (!cell.sourceTopologyRegion.has_value() || cell.sourceCharts.empty() ||
        !std::is_sorted(cell.sourceCharts.begin(), cell.sourceCharts.end())) {
      result.firstScopeFailure.active = true;
      result.firstScopeFailure.originalCell = cell.id;
      result.firstScopeFailure.replacementCell = cell.id;
      result.firstScopeFailure.mutationPhase = "preflight";
      return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::MissingCellSourceScope, "MissingCellSourceScope");
    }
    for (const int halfedgeId : cell.halfedges) {
      if (halfedgeId < 0 ||
          halfedgeId >= static_cast<int>(input.halfedges.size())) {
        return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::InvalidCellHalfedge, "InvalidCellHalfedge");
      }
      const SurfaceArrangementHalfedge &edge =
          input.halfedges[static_cast<std::size_t>(halfedgeId)];
      const surface_cell_feasibility_detail::SourceScope edgeScope =
          surface_cell_feasibility_detail::source_scope(edge);
      if (!edgeScope.valid() ||
          edgeScope.region != cell.sourceTopologyRegion ||
          !std::binary_search(cell.sourceCharts.begin(), cell.sourceCharts.end(),
                              edgeScope.chart.value())) {
        result.firstScopeFailure.active = true;
        result.firstScopeFailure.originalCell = cell.id;
        result.firstScopeFailure.replacementCell = cell.id;
        result.firstScopeFailure.halfedge = halfedgeId;
        result.firstScopeFailure.twin = edge.twin;
        result.firstScopeFailure.mutationPhase = "preflight";
        return returnCommittedFailure(SurfaceCellSubdivisionFailureKind::MixedCellSourceScope, "MixedCellSourceScope");
      }
    }
  }

  SurfaceCellComplex rebuilt;
  const bool inputTopologyValid = input.diagnostics.topologyValid;
  const std::size_t originalNodeCount = input.nodes.size();
  const SurfaceArrangementDiagnostics originalDiagnostics = input.diagnostics;
  // Keep the committed halfedge vector in `input`. Nodes and cells move into
  // the mutable transaction and are restored through a compact undo log on
  // every rejected path, avoiding a second full complex.
  rebuilt.sourceOwnershipRegistry =
      std::move(input.sourceOwnershipRegistry);
  rebuilt.nodes = std::move(input.nodes);
  rebuilt.cells = std::move(input.cells);
  rebuilt.diagnostics = std::move(input.diagnostics);
  std::vector<std::vector<int>> replacement(input.halfedges.size());
  std::vector<unsigned char> processed(input.halfedges.size(), 0);

  struct CellUndo {
    int index = -1;
    std::vector<int> halfedges;
    std::vector<int> boundaryCycleOffsets;
    std::vector<int> sourceBoundaryLoopIds;
    std::vector<int> sideFamilies;
    std::vector<int> sideEdgeCounts;
    std::vector<int> sourceFaces;
    int sourceFace = -1;
    int sourceBoundarySide = 0;
    int boundaryComponentCount = 0;
    int eulerCharacteristic = 0;
    bool disk = false;
  };
  std::vector<CellUndo> cellUndo;
  cellUndo.reserve(rebuilt.cells.size());

  const auto restoreCommitted =
      [&](SurfaceCellSubdivisionFailureKind kind,
          std::string detail) -> SurfaceCellSubdivisionResult {
    for (auto undo = cellUndo.rbegin(); undo != cellUndo.rend(); ++undo) {
      SurfaceArrangementCell &cell =
          rebuilt.cells[static_cast<std::size_t>(undo->index)];
      cell.halfedges = std::move(undo->halfedges);
      cell.boundaryCycleOffsets =
          std::move(undo->boundaryCycleOffsets);
      cell.sourceBoundaryLoopIds =
          std::move(undo->sourceBoundaryLoopIds);
      cell.sideFamilies = std::move(undo->sideFamilies);
      cell.sideEdgeCounts = std::move(undo->sideEdgeCounts);
      cell.sourceFaces = std::move(undo->sourceFaces);
      cell.sourceFace = undo->sourceFace;
      cell.sourceBoundarySide = undo->sourceBoundarySide;
      cell.boundaryComponentCount = undo->boundaryComponentCount;
      cell.eulerCharacteristic = undo->eulerCharacteristic;
      cell.disk = undo->disk;
    }
    rebuilt.nodes.resize(originalNodeCount);
    input.sourceOwnershipRegistry =
        std::move(rebuilt.sourceOwnershipRegistry);
    input.nodes = std::move(rebuilt.nodes);
    input.cells = std::move(rebuilt.cells);
    input.diagnostics = originalDiagnostics;
    SurfaceCellComplex rollbackEvidence = std::move(input);
    const auto after =
        surface_cell_feasibility_detail::exact_rollback_identity(
            rollbackEvidence);
    result.rollbackIdentityHashAfter =
        surface_cell_feasibility_detail::rollback_identity_hash(after);
    result.rollbackEquivalent = after == rollbackIdentity;
    SurfaceCellSubdivisionFailureKind rejectedKind = kind;
    std::string rejectedDetail = std::move(detail);
    if (!result.rollbackEquivalent) {
      rejectedKind = SurfaceCellSubdivisionFailureKind::RollbackMismatch;
      rejectedDetail = "SubdivisionRollbackMismatch:" + rejectedDetail;
    }
    return SurfaceCellSubdivisionResult::rejected(
        subdivision_failure_from_product(std::move(result), rejectedKind,
                                         std::move(rejectedDetail)),
        std::move(rollbackEvidence));
  };

  const auto append_halfedge = [&](SurfaceArrangementHalfedge value) {
    value.id = static_cast<int>(rebuilt.halfedges.size());
    value.next = -1;
    rebuilt.halfedges.push_back(std::move(value));
    return static_cast<int>(rebuilt.halfedges.size()) - 1;
  };

  for (int id = 0; id < static_cast<int>(input.halfedges.size()); ++id) {
    if (processed[static_cast<std::size_t>(id)] != 0U) {
      continue;
    }
    const SurfaceArrangementHalfedge &forward =
        input.halfedges[static_cast<std::size_t>(id)];
    const int twinId = forward.twin;
    if (twinId < 0 || twinId >= static_cast<int>(input.halfedges.size()) ||
        processed[static_cast<std::size_t>(twinId)] != 0U) {
      return restoreCommitted(SurfaceCellSubdivisionFailureKind::InvalidTwinPair, "InvalidTwinPair");
    }
    const SurfaceArrangementHalfedge &reverse =
        input.halfedges[static_cast<std::size_t>(twinId)];
    const SurfaceArrangementNode &edgeFromNode =
        rebuilt.nodes[static_cast<std::size_t>(forward.from)];
    const SurfaceArrangementNode &edgeToNode =
        rebuilt.nodes[static_cast<std::size_t>(forward.to)];
    const std::vector<int> forwardSourceFaces =
        surface_cell_feasibility_detail::common_edge_source_faces(
            edgeFromNode, edgeToNode, forward, sourceFaces);
    const std::vector<int> reverseSourceFaces =
        surface_cell_feasibility_detail::common_edge_source_faces(
            edgeToNode, edgeFromNode, reverse, sourceFaces);
    if (forwardSourceFaces.empty() || reverseSourceFaces.empty()) {
      return restoreCommitted(SurfaceCellSubdivisionFailureKind::MissingCommonSourceChart, "MissingCommonSourceChart");
    }
    const int primaryForwardFace = forwardSourceFaces.front();
    const int primaryReverseFace = reverseSourceFaces.front();
    const auto forwardRegion = forward.sourceTopologyRegion;
    const auto forwardChart = forward.sourceChart;
    const auto reverseRegion = reverse.sourceTopologyRegion;
    const auto reverseChart = reverse.sourceChart;
    if (!forwardRegion.has_value() || !forwardChart.has_value() ||
        !reverseRegion.has_value() || !reverseChart.has_value()) {
      return restoreCommitted(SurfaceCellSubdivisionFailureKind::MissingCommonSourceChart, "MissingCommonSourceChart");
    }
    processed[static_cast<std::size_t>(id)] = 1U;
    processed[static_cast<std::size_t>(twinId)] = 1U;
    const int canonical = std::min(id, twinId);
    const auto requested = insertionCount.find(canonical);
    const int insertedVertices =
        requested == insertionCount.end() ? 0 : requested->second;
    const int parts = insertedVertices + 1;

    std::vector<int> pathNodes;
    pathNodes.reserve(static_cast<std::size_t>(parts + 1));
    pathNodes.push_back(forward.from);
    for (int split = 1; split < parts; ++split) {
      const double alpha = static_cast<double>(split) /
                           static_cast<double>(parts);
      SurfaceArrangementNode node;
      node.id = static_cast<int>(rebuilt.nodes.size());
      const SurfaceArrangementNode &fromNode =
          rebuilt.nodes[static_cast<std::size_t>(forward.from)];
      const SurfaceArrangementNode &toNode =
          rebuilt.nodes[static_cast<std::size_t>(forward.to)];
      node.hardBarrierCrossing =
          fromNode.hardBarrierCrossing || toNode.hardBarrierCrossing;

      struct OccurrenceScope {
        int face = -1;
        std::optional<authority::TopologyRegionId> region;
        std::optional<SourceProjectionChart> chart;
        const SurfaceArrangementHalfedge *edge = nullptr;
        double orientedAlpha = 0.0;
      };
      std::vector<OccurrenceScope> scopes;
      for (const int face : forwardSourceFaces) {
        scopes.push_back(
            {face, forwardRegion, forwardChart, &forward, alpha});
      }
      for (const int face : reverseSourceFaces) {
        scopes.push_back(
            {face, reverseRegion, reverseChart, &reverse, 1.0 - alpha});
      }
      std::sort(scopes.begin(), scopes.end(), [](const auto &a, const auto &b) {
        return std::tie(a.region, a.chart, a.face) <
               std::tie(b.region, b.chart, b.face);
      });
      scopes.erase(std::unique(scopes.begin(), scopes.end(),
                               [](const auto &a, const auto &b) {
                                 return a.face == b.face &&
                                        a.region == b.region &&
                                        a.chart == b.chart;
                               }),
                   scopes.end());

      bool primarySet = false;
      for (const OccurrenceScope &scope : scopes) {
        const Eigen::RowVector3d barycentric =
            surface_cell_feasibility_detail::interpolated_barycentric(
                rebuilt, forward.from, forward.to, scope.face,
                *scope.edge, alpha);
        if (!barycentric.allFinite() ||
            barycentric.minCoeff() < -1.0e-10 ||
            barycentric.maxCoeff() > 1.0 + 1.0e-10) {
          continue;
        }
        SurfaceArrangementNodeOccurrence occurrence;
        occurrence.sourceFace = scope.face;
        occurrence.barycentric = barycentric;
        occurrence.sourceTopologyRegion = scope.region;
        occurrence.sourceChart = scope.chart;
        occurrence.sourceArc = scope.edge->sourceArc;
        occurrence.provenance =
            scope.edge->provenance.empty()
                ? -1
                : scope.edge->provenance.front().provenance;
        occurrence.railId = scope.edge->railId;
        occurrence.curveId = scope.edge->curveId;
        occurrence.sourceT0 =
            (1.0 - scope.orientedAlpha) * scope.edge->sourceT0 +
            scope.orientedAlpha * scope.edge->sourceT1;
        occurrence.sourceT1 = occurrence.sourceT0;
        occurrence.railT0 =
            (1.0 - scope.orientedAlpha) * scope.edge->railT0 +
            scope.orientedAlpha * scope.edge->railT1;
        occurrence.railT1 = occurrence.railT0;
        node.occurrences.push_back(std::move(occurrence));
        if (!primarySet) {
          node.sourceFace = scope.face;
          node.sourceTopologyRegion = scope.region;
          node.sourceChart = scope.chart;
          node.barycentric = barycentric;
          primarySet = true;
        }
      }
      if (!primarySet) {
        return restoreCommitted(SurfaceCellSubdivisionFailureKind::InvalidMidpointEmbedding, "InvalidMidpointEmbedding");
      }
      if (fromNode.sourceEdge >= 0 &&
          fromNode.sourceEdge == toNode.sourceEdge) {
        node.sourceEdge = fromNode.sourceEdge;
        node.sourceEdgeParameter =
            (1.0 - alpha) * fromNode.sourceEdgeParameter +
            alpha * toNode.sourceEdgeParameter;
      }
      rebuilt.nodes.push_back(std::move(node));
      pathNodes.push_back(static_cast<int>(rebuilt.nodes.size()) - 1);
    }
    pathNodes.push_back(forward.to);

    std::vector<int> forwardPieces;
    std::vector<int> reversePieces;
    forwardPieces.reserve(static_cast<std::size_t>(parts));
    reversePieces.reserve(static_cast<std::size_t>(parts));
    for (int part = 0; part < parts; ++part) {
      const double alpha0 =
          static_cast<double>(part) / static_cast<double>(parts);
      const double alpha1 =
          static_cast<double>(part + 1) / static_cast<double>(parts);
      SurfaceArrangementHalfedge piece = forward;
      piece.sourceFace = primaryForwardFace;
      piece.sourceTopologyRegion = forwardRegion;
      piece.sourceChart = forwardChart;
      piece.from = pathNodes[static_cast<std::size_t>(part)];
      piece.to = pathNodes[static_cast<std::size_t>(part + 1)];
      piece.sourceT0 =
          (1.0 - alpha0) * forward.sourceT0 + alpha0 * forward.sourceT1;
      piece.sourceT1 =
          (1.0 - alpha1) * forward.sourceT0 + alpha1 * forward.sourceT1;
      piece.railT0 =
          (1.0 - alpha0) * forward.railT0 + alpha0 * forward.railT1;
      piece.railT1 =
          (1.0 - alpha1) * forward.railT0 + alpha1 * forward.railT1;
      surface_cell_feasibility_detail::split_provenance_interval(
          forward.provenance, alpha0, alpha1, piece.provenance);
      forwardPieces.push_back(append_halfedge(std::move(piece)));

      SurfaceArrangementHalfedge twinPiece = reverse;
      twinPiece.sourceFace = primaryReverseFace;
      twinPiece.sourceTopologyRegion = reverseRegion;
      twinPiece.sourceChart = reverseChart;
      twinPiece.from = pathNodes[static_cast<std::size_t>(parts - part)];
      twinPiece.to = pathNodes[static_cast<std::size_t>(parts - part - 1)];
      twinPiece.sourceT0 =
          (1.0 - alpha0) * reverse.sourceT0 + alpha0 * reverse.sourceT1;
      twinPiece.sourceT1 =
          (1.0 - alpha1) * reverse.sourceT0 + alpha1 * reverse.sourceT1;
      twinPiece.railT0 =
          (1.0 - alpha0) * reverse.railT0 + alpha0 * reverse.railT1;
      twinPiece.railT1 =
          (1.0 - alpha1) * reverse.railT0 + alpha1 * reverse.railT1;
      surface_cell_feasibility_detail::split_provenance_interval(
          reverse.provenance, alpha0, alpha1, twinPiece.provenance);
      reversePieces.push_back(append_halfedge(std::move(twinPiece)));
    }
    for (int part = 0; part < parts; ++part) {
      const int forwardId = forwardPieces[static_cast<std::size_t>(part)];
      const int reverseId =
          reversePieces[static_cast<std::size_t>(parts - part - 1)];
      rebuilt.halfedges[static_cast<std::size_t>(forwardId)].twin = reverseId;
      rebuilt.halfedges[static_cast<std::size_t>(reverseId)].twin = forwardId;
    }
    replacement[static_cast<std::size_t>(id)] = forwardPieces;
    replacement[static_cast<std::size_t>(twinId)] = reversePieces;
    if (insertedVertices > 0) {
      ++result.splitUndirectedEdges;
      result.insertedVertices += insertedVertices;
      if (forward.hardFeature || reverse.hardFeature) {
        ++result.hardFeatureSplits;
      }
    }
  }

  result.rollbackUndoOwnedBytes +=
      static_cast<std::uint64_t>(
          rebuilt.sourceOwnershipRegistry.capacity()) *
      sizeof(SurfaceCellOwnershipClassRecord);
  for (const SurfaceCellOwnershipClassRecord &record :
       rebuilt.sourceOwnershipRegistry) {
    result.rollbackUndoOwnedBytes +=
        static_cast<std::uint64_t>(record.exactCharts.capacity()) *
        sizeof(SourceProjectionChart);
  }

  for (int cellIndex = 0; cellIndex < static_cast<int>(rebuilt.cells.size());
       ++cellIndex) {
    SurfaceArrangementCell &cell =
        rebuilt.cells[static_cast<std::size_t>(cellIndex)];
    CellUndo undo;
    undo.index = cellIndex;
    undo.halfedges = cell.halfedges;
    undo.boundaryCycleOffsets = cell.boundaryCycleOffsets;
    undo.sourceBoundaryLoopIds = cell.sourceBoundaryLoopIds;
    undo.sideFamilies = cell.sideFamilies;
    undo.sideEdgeCounts = cell.sideEdgeCounts;
    undo.sourceFaces = cell.sourceFaces;
    undo.sourceFace = cell.sourceFace;
    undo.sourceBoundarySide = cell.sourceBoundarySide;
    undo.boundaryComponentCount = cell.boundaryComponentCount;
    undo.eulerCharacteristic = cell.eulerCharacteristic;
    undo.disk = cell.disk;
    result.rollbackUndoOwnedBytes +=
        static_cast<std::uint64_t>(undo.halfedges.capacity()) * sizeof(int) +
        static_cast<std::uint64_t>(undo.boundaryCycleOffsets.capacity()) *
            sizeof(int) +
        static_cast<std::uint64_t>(undo.sourceBoundaryLoopIds.capacity()) *
            sizeof(int) +
        static_cast<std::uint64_t>(undo.sideFamilies.capacity()) * sizeof(int) +
        static_cast<std::uint64_t>(undo.sideEdgeCounts.capacity()) * sizeof(int) +
        static_cast<std::uint64_t>(undo.sourceFaces.capacity()) * sizeof(int) +
        static_cast<std::uint64_t>(cell.sourceCharts.capacity()) *
            sizeof(SourceProjectionChart);
    cellUndo.push_back(std::move(undo));

    const std::vector<int> oldBoundary = cell.halfedges;
    std::vector<int> newBoundary;
    std::vector<int> newSideCounts(cell.sideEdgeCounts.size(), 0);
    const bool sideMetadataValid =
        cell.sideFamilies.size() == cell.sideEdgeCounts.size() &&
        std::accumulate(cell.sideEdgeCounts.begin(), cell.sideEdgeCounts.end(),
                        0) == static_cast<int>(oldBoundary.size());
    int side = 0;
    int usedOnSide = 0;
    for (const int oldId : oldBoundary) {
      if (oldId < 0 || oldId >= static_cast<int>(replacement.size()) ||
          replacement[static_cast<std::size_t>(oldId)].empty()) {
        return restoreCommitted(SurfaceCellSubdivisionFailureKind::MissingHalfedgeReplacement, "MissingHalfedgeReplacement");
      }
      const auto &pieces = replacement[static_cast<std::size_t>(oldId)];
      newBoundary.insert(newBoundary.end(), pieces.begin(), pieces.end());
      if (sideMetadataValid) {
        while (side < static_cast<int>(cell.sideEdgeCounts.size()) &&
               usedOnSide >=
                   cell.sideEdgeCounts[static_cast<std::size_t>(side)]) {
          ++side;
          usedOnSide = 0;
        }
        if (side >= static_cast<int>(newSideCounts.size())) {
          return restoreCommitted(SurfaceCellSubdivisionFailureKind::InvalidSideMetadata, "InvalidSideMetadata");
        }
        newSideCounts[static_cast<std::size_t>(side)] +=
            static_cast<int>(pieces.size());
        ++usedOnSide;
      }
    }
    cell.halfedges = std::move(newBoundary);
    if (sideMetadataValid) {
      cell.sideEdgeCounts = std::move(newSideCounts);
    } else {
      cell.sideFamilies.clear();
      cell.sideEdgeCounts.clear();
    }
    for (int index = 0; index < static_cast<int>(cell.halfedges.size());
         ++index) {
      const int halfedgeId = cell.halfedges[static_cast<std::size_t>(index)];
      SurfaceArrangementHalfedge &halfedge =
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)];
      halfedge.cell = cell.id;
      halfedge.next = cell.halfedges[static_cast<std::size_t>(
          (index + 1) % static_cast<int>(cell.halfedges.size()))];
    }

    if (!cell.sourceTopologyRegion.has_value() || cell.sourceCharts.empty()) {
      return restoreCommitted(SurfaceCellSubdivisionFailureKind::MissingCellSourceScope, "MissingCellSourceScope");
    }
    for (const int halfedgeId : cell.halfedges) {
      SurfaceArrangementHalfedge &edge =
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)];
      const auto exactEdgeScope =
          surface_cell_feasibility_detail::source_scope(edge);
      if (!exactEdgeScope.valid() ||
          exactEdgeScope.region != cell.sourceTopologyRegion ||
          !std::binary_search(cell.sourceCharts.begin(), cell.sourceCharts.end(),
                              exactEdgeScope.chart.value())) {
        result.firstScopeFailure.active = true;
        result.firstScopeFailure.originalCell = cell.id;
        result.firstScopeFailure.replacementCell = cell.id;
        result.firstScopeFailure.halfedge = halfedgeId;
        result.firstScopeFailure.twin = edge.twin;
        result.firstScopeFailure.mutationPhase = "replacement-scope";
        return restoreCommitted(SurfaceCellSubdivisionFailureKind::MixedCellSourceScope, "MixedCellSourceScope");
      }

      const auto selected = std::min_element(
          edge.provenance.begin(), edge.provenance.end(),
          [&](const SurfaceArrangementProvenance &lhs,
              const SurfaceArrangementProvenance &rhs) {
            const auto key = [&](const SurfaceArrangementProvenance &value) {
              const bool compatible =
                  surface_cell_feasibility_detail::source_scope(value) ==
                      exactEdgeScope &&
                  value.sourceFace == edge.sourceFace;
              return std::make_tuple(
                  compatible ? 0 : 1, value.railId.has_value() ? 1 : 0,
                  value.hardFeature ? 0 : 1, value.sourceFace,
                  value.sourceArc, value.provenance, value.family,
                  value.strand, value.railId, value.curveId);
            };
            return key(lhs) < key(rhs);
          });
      const bool selectedCompatible =
          selected != edge.provenance.end() &&
          surface_cell_feasibility_detail::source_scope(*selected) ==
              exactEdgeScope &&
          selected->sourceFace == edge.sourceFace;
      if (selectedCompatible) {
        edge.sourceArc = selected->sourceArc;
        edge.family = selected->family;
        edge.strand = selected->strand;
        edge.featureClass = selected->featureClass;
        edge.sourceFace = selected->sourceFace;
        edge.sourceT0 = selected->sourceT0;
        edge.sourceT1 = selected->sourceT1;
        edge.hardFeature = edge.hardFeature || selected->hardFeature;
        edge.layoutSupport = edge.layoutSupport || selected->layoutSupport;
        edge.singularitySupport =
            edge.singularitySupport || selected->singularitySupport;
        edge.railId = selected->railId;
        edge.curveId = selected->curveId;
        edge.sourceTopologyRegion = selected->sourceTopologyRegion;
        edge.sourceChart = selected->sourceChart;
        edge.proposalId = selected->proposalId;
        edge.proposalSeedId = selected->proposalSeedId;
        edge.proposalSide = selected->proposalSide;
        edge.proposalBoundarySegment = selected->proposalBoundarySegment;
        edge.railT0 = selected->railT0;
        edge.railT1 = selected->railT1;
      }

      const auto ensureOccurrence = [&](const int nodeId,
                                        const double sourceParameter,
                                        const double railParameter) {
        if (nodeId < 0 || nodeId >= static_cast<int>(rebuilt.nodes.size())) {
          return false;
        }
        SurfaceArrangementNode &node =
            rebuilt.nodes[static_cast<std::size_t>(nodeId)];
        const auto present = std::find_if(
            node.occurrences.begin(), node.occurrences.end(),
            [&](const SurfaceArrangementNodeOccurrence &occurrence) {
              return occurrence.sourceFace == edge.sourceFace &&
                     surface_cell_feasibility_detail::source_scope(occurrence) ==
                         exactEdgeScope;
            });
        if (present != node.occurrences.end()) {
          return true;
        }
        Eigen::RowVector3d barycentric =
            surface_arrangement_detail::node_barycentric_on_face(
                node, edge.sourceFace);
        if (!barycentric.allFinite()) {
          return false;
        }
        SurfaceArrangementNodeOccurrence occurrence;
        occurrence.sourceFace = edge.sourceFace;
        occurrence.barycentric = barycentric;
        occurrence.sourceTopologyRegion = edge.sourceTopologyRegion;
        occurrence.sourceChart = edge.sourceChart;
        occurrence.sourceArc = edge.sourceArc;
        occurrence.provenance = edge.provenance.empty()
                                    ? -1
                                    : edge.provenance.front().provenance;
        occurrence.railId = edge.railId;
        occurrence.curveId = edge.curveId;
        occurrence.sourceT0 = sourceParameter;
        occurrence.sourceT1 = sourceParameter;
        occurrence.railT0 = railParameter;
        occurrence.railT1 = railParameter;
        node.occurrences.push_back(std::move(occurrence));
        if (node.sourceFace < 0) {
          node.sourceFace = edge.sourceFace;
          node.barycentric = barycentric;
        }
        if (!node.sourceTopologyRegion.has_value() ||
            !node.sourceChart.has_value()) {
          node.sourceTopologyRegion = edge.sourceTopologyRegion;
          node.sourceChart = edge.sourceChart;
        }
        return true;
      };
      if (!ensureOccurrence(edge.from, edge.sourceT0, edge.railT0) ||
          !ensureOccurrence(edge.to, edge.sourceT1, edge.railT1)) {
        result.firstScopeFailure.active = true;
        result.firstScopeFailure.originalCell = cell.id;
        result.firstScopeFailure.replacementCell = cell.id;
        result.firstScopeFailure.halfedge = halfedgeId;
        result.firstScopeFailure.twin = edge.twin;
        result.firstScopeFailure.selectedComponent = -1;
        result.firstScopeFailure.selectedSheet = -1;
        result.firstScopeFailure.mutationPhase = "replacement-occurrence";
        return restoreCommitted(SurfaceCellSubdivisionFailureKind::MissingReplacementSourceOccurrence, "MissingReplacementSourceOccurrence");
      }
    }

    std::set<int> authoritativeSourceFaces;
    const auto addSourceFace = [&](const int face) {
      if (surface_cell_feasibility_detail::valid_source_face_index(
              face, sourceFaces)) {
        authoritativeSourceFaces.insert(face);
      }
    };
    for (const int sourceFace : cell.sourceFaces) {
      addSourceFace(sourceFace);
    }
    addSourceFace(cell.sourceFace);
    for (const int halfedgeId : cell.halfedges) {
      const SurfaceArrangementHalfedge &edge =
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)];
      addSourceFace(edge.sourceFace);
      for (const SurfaceArrangementProvenance &provenance :
           edge.provenance) {
        const auto scope =
            surface_cell_feasibility_detail::source_scope(provenance);
        if (scope.valid() && scope.region == cell.sourceTopologyRegion &&
            std::binary_search(cell.sourceCharts.begin(),
                               cell.sourceCharts.end(), scope.chart.value())) {
          addSourceFace(provenance.sourceFace);
        }
      }
    }
    if (authoritativeSourceFaces.empty()) {
      return restoreCommitted(SurfaceCellSubdivisionFailureKind::MissingCellSourceSupport, "MissingCellSourceSupport");
    }
    cell.sourceFaces.assign(authoritativeSourceFaces.begin(),
                            authoritativeSourceFaces.end());
    cell.sourceFace = cell.sourceFaces.front();

    std::set<int> uniqueNodes;
    for (const int halfedgeId : cell.halfedges) {
      uniqueNodes.insert(
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)].from);
    }
    cell.boundaryCycleOffsets =
        cell.closed ? std::vector<int>{0} : std::vector<int>{};
    cell.boundaryComponentCount = cell.closed ? 1 : 0;
    cell.eulerCharacteristic =
        static_cast<int>(uniqueNodes.size()) -
        static_cast<int>(cell.halfedges.size()) + (cell.closed ? 1 : 0);
    cell.disk = cell.closed && cell.boundaryComponentCount == 1 &&
                uniqueNodes.size() == cell.halfedges.size() &&
                cell.eulerCharacteristic == 1;
    const SurfaceCellDomainIdentityAudit boundaryAudit =
        surface_cell_feasibility_detail::audit_simple_cell_boundary(rebuilt,
                                                                    cell);
    if (!boundaryAudit.valid) {
      result.firstDomainFailure = boundaryAudit;
      return restoreCommitted(
          SurfaceCellSubdivisionFailureKind::InvalidReplacementBoundary,
          std::string("InvalidReplacementBoundary:") +
              surface_cell_domain_identity_failure_name(boundaryAudit.failure));
    }
  }

  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(rebuilt)) {
    return restoreCommitted(SurfaceCellSubdivisionFailureKind::InvalidOutputIncidence, "InvalidOutputIncidence");
  }
  rebuilt.diagnostics.incidenceValid = true;
  rebuilt.diagnostics.incidenceFailure =
      SurfaceArrangementIncidenceFailure::None;
  rebuilt.diagnostics.incidenceFailureNode = -1;
  rebuilt.diagnostics.incidenceFailureHalfedge = -1;
  rebuilt.diagnostics.incidenceFailureTwin = -1;
  rebuilt.diagnostics.incidenceFailureNext = -1;
  rebuilt.diagnostics.successorMissingCount = 0;
  rebuilt.diagnostics.successorAmbiguityCount = 0;
  rebuilt.diagnostics.predecessorMultiplicityFailureCount = 0;
  rebuilt.diagnostics.repeatedNodeCycleCount = 0;
  rebuilt.diagnostics.repeatedEdgeCycleCount = 0;
  rebuilt.diagnostics.topologyValid =
      inputTopologyValid && rebuilt.diagnostics.incidenceValid;
  result.complex = std::move(rebuilt);
  result.rollbackIdentityHashAfter =
      surface_cell_feasibility_detail::rollback_identity_hash(
          surface_cell_feasibility_detail::exact_rollback_identity(
              result.complex));
  return SurfaceCellSubdivisionResult::produced(std::move(result));
}

SurfaceCellParityRepairResult repair_surface_cell_boundary_parity(
    SurfaceCellComplex input) {
  SurfaceCellParityRepairProduct result;
  result.oddCellsBefore =
      surface_cell_feasibility_detail::odd_bounded_cell_count(input);
  const auto reject =
      [&](SurfaceCellParityRepairFailureKind kind, std::string detail,
          std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure =
              std::nullopt) -> SurfaceCellParityRepairResult {
    return SurfaceCellParityRepairResult::rejected(
        parity_failure_from_product(std::move(result), kind, std::move(detail),
                                    std::move(subdivisionFailure)));
  };
  if (result.oddCellsBefore == 0) {
    result.complex = std::move(input);
    return SurfaceCellParityRepairResult::produced(std::move(result));
  }
  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(input)) {
    return reject(SurfaceCellParityRepairFailureKind::InvalidInputIncidence,
                  "InvalidInputIncidence");
  }

  struct DualEdge {
    int neighbor = -1;
    int halfedge = -1;
    bool hardFeature = false;
  };
  std::vector<std::vector<DualEdge>> adjacency(input.cells.size());
  for (const SurfaceArrangementHalfedge &halfedge : input.halfedges) {
    if (halfedge.id > halfedge.twin) {
      continue;
    }
    const SurfaceArrangementHalfedge &twin =
        input.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell == twin.cell) {
      continue;
    }
    const bool hard = halfedge.hardFeature || twin.hardFeature;
    adjacency[static_cast<std::size_t>(halfedge.cell)].push_back(
        {twin.cell, halfedge.id, hard});
    adjacency[static_cast<std::size_t>(twin.cell)].push_back(
        {halfedge.cell, halfedge.id, hard});
  }
  for (auto &neighbors : adjacency) {
    std::sort(neighbors.begin(), neighbors.end(),
              [](const DualEdge &a, const DualEdge &b) {
                return std::tie(a.hardFeature, a.halfedge, a.neighbor) <
                       std::tie(b.hardFeature, b.halfedge, b.neighbor);
              });
  }

  const auto computeSelected = [&](const std::set<int> &excluded,
                                   std::set<int> &selected,
                                   SurfaceCellParityRepairFailureKind &failure) {
    selected.clear();
    std::vector<unsigned char> globallyVisited(input.cells.size(), 0U);
    for (int startCell = 0; startCell < static_cast<int>(input.cells.size());
         ++startCell) {
      if (globallyVisited[static_cast<std::size_t>(startCell)] != 0U) {
        continue;
      }
      std::vector<int> component;
      std::queue<int> discover;
      discover.push(startCell);
      globallyVisited[static_cast<std::size_t>(startCell)] = 1U;
      while (!discover.empty()) {
        const int cell = discover.front();
        discover.pop();
        component.push_back(cell);
        for (const DualEdge &edge : adjacency[static_cast<std::size_t>(cell)]) {
          if (excluded.count(edge.halfedge) != 0U) {
            continue;
          }
          if (globallyVisited[static_cast<std::size_t>(edge.neighbor)] == 0U) {
            globallyVisited[static_cast<std::size_t>(edge.neighbor)] = 1U;
            discover.push(edge.neighbor);
          }
        }
      }
      int root = *std::min_element(component.begin(), component.end());
      for (const int cell : component) {
        if (input.cells[static_cast<std::size_t>(cell)].boundaryCycle) {
          root = cell;
          break;
        }
      }

      using QueueEntry = std::tuple<std::int64_t, int, int>;
      std::priority_queue<QueueEntry, std::vector<QueueEntry>,
                          std::greater<QueueEntry>> queue;
      std::vector<std::int64_t> distance(
          input.cells.size(), std::numeric_limits<std::int64_t>::max());
      std::vector<int> parent(input.cells.size(), -1);
      std::vector<int> parentEdge(input.cells.size(), -1);
      std::vector<int> order;
      distance[static_cast<std::size_t>(root)] = 0;
      queue.emplace(0, root, -1);
      while (!queue.empty()) {
        const auto [cost, cell, unused] = queue.top();
        (void)unused;
        queue.pop();
        if (cost != distance[static_cast<std::size_t>(cell)]) {
          continue;
        }
        order.push_back(cell);
        for (const DualEdge &edge : adjacency[static_cast<std::size_t>(cell)]) {
          if (excluded.count(edge.halfedge) != 0U) {
            continue;
          }
          const bool bothBounded =
              !input.cells[static_cast<std::size_t>(cell)].boundaryCycle &&
              !input.cells[static_cast<std::size_t>(edge.neighbor)]
                   .boundaryCycle;
          const std::int64_t edgeCost =
              (edge.hardFeature ? 1000000LL : 0LL) +
              (bothBounded ? 1LL : 2LL);
          const std::int64_t candidate = cost + edgeCost;
          const auto candidateKey =
              std::make_tuple(candidate, cell, edge.halfedge);
          const auto previousKey = std::make_tuple(
              distance[static_cast<std::size_t>(edge.neighbor)],
              parent[static_cast<std::size_t>(edge.neighbor)],
              parentEdge[static_cast<std::size_t>(edge.neighbor)]);
          if (candidateKey < previousKey) {
            distance[static_cast<std::size_t>(edge.neighbor)] = candidate;
            parent[static_cast<std::size_t>(edge.neighbor)] = cell;
            parentEdge[static_cast<std::size_t>(edge.neighbor)] =
                edge.halfedge;
            queue.emplace(candidate, edge.neighbor, edge.halfedge);
          }
        }
      }
      if (order.size() != component.size()) {
        failure = SurfaceCellParityRepairFailureKind::DisconnectedDualComponent;
        return false;
      }
      std::vector<unsigned char> parity(input.cells.size(), 0U);
      for (const int cell : component) {
        if (!input.cells[static_cast<std::size_t>(cell)].boundaryCycle &&
            input.cells[static_cast<std::size_t>(cell)].halfedges.size() % 2U !=
                0U) {
          parity[static_cast<std::size_t>(cell)] = 1U;
        }
      }
      for (auto iterator = order.rbegin(); iterator != order.rend();
           ++iterator) {
        const int cell = *iterator;
        if (cell == root || parity[static_cast<std::size_t>(cell)] == 0U) {
          continue;
        }
        const int edge = parentEdge[static_cast<std::size_t>(cell)];
        const int ancestor = parent[static_cast<std::size_t>(cell)];
        if (edge < 0 || ancestor < 0) {
          failure = SurfaceCellParityRepairFailureKind::UnpairableOddCell;
          return false;
        }
        selected.insert(edge);
        parity[static_cast<std::size_t>(ancestor)] ^= 1U;
      }
      if (!input.cells[static_cast<std::size_t>(root)].boundaryCycle &&
          parity[static_cast<std::size_t>(root)] != 0U) {
        failure = SurfaceCellParityRepairFailureKind::UnpairableClosedComponentParity;
        return false;
      }
    }
    return true;
  };

  const auto attemptSubdivision = [&](const std::set<int> &selected) {
    std::map<int, int> insertions;
    for (const int halfedge : selected) {
      insertions.emplace(halfedge, 1);
    }
    return subdivide_surface_cell_complex_edges(input, insertions);
  };

  const auto consumeSubdivision = [](SurfaceCellSubdivisionResult value) {
    struct Consumed {
      std::optional<SurfaceCellSubdivisionProduct> product;
      std::optional<SurfaceCellSubdivisionFailure> failure;
      bool notApplicable = false;
    } consumed;
    std::visit(
        [&](auto &&outcome) {
          using Outcome = std::decay_t<decltype(outcome)>;
          if constexpr (std::is_same_v<Outcome, NotApplicable>) {
            consumed.notApplicable = true;
          } else if constexpr (
              std::is_same_v<Outcome,
                             Produced<SurfaceCellSubdivisionProduct>>) {
            consumed.product = std::move(outcome.product);
          } else {
            consumed.failure = std::move(outcome.failure);
          }
        },
        std::move(value).outcome());
    return consumed;
  };

  std::set<int> selected;
  SurfaceCellParityRepairFailureKind selectionFailure =
      SurfaceCellParityRepairFailureKind::None;
  if (!computeSelected({}, selected, selectionFailure)) {
    return reject(selectionFailure,
                  surface_cell_parity_repair_failure_kind_name(
                      selectionFailure));
  }
  auto firstSubdivision = consumeSubdivision(attemptSubdivision(selected));
  std::optional<SurfaceCellSubdivisionProduct> acceptedSubdivision;
  std::set<int> acceptedSelection;
  if (firstSubdivision.product.has_value()) {
    acceptedSubdivision = std::move(firstSubdivision.product.value());
    acceptedSelection = selected;
  } else {
    // The first deterministic T-join may cross a pinched local boundary. Build
    // the retry frontier from every canonical dual interface incident to the
    // typed failing cell, not only from interfaces selected by the failed
    // T-join. Each topology-derived exclusion is attempted at most once.
    // Canonical state hashes prevent repeated recomputation and make the work
    // bound equal to the unique incident-interface count rather than elapsed
    // time or an arbitrary subset cap.
    struct AlternativeInterface {
      int halfedge = -1;
      std::tuple<int, int, std::optional<authority::TopologyRegionId>,
                 std::optional<SourceProjectionChart>, int, int, int, int, int>
          key;
    };
    std::vector<AlternativeInterface> localAlternatives;
    const SurfaceCellSubdivisionFailure *firstFailure =
        firstSubdivision.failure.has_value()
            ? &firstSubdivision.failure.value()
            : nullptr;
    const int failingCell =
        firstFailure == nullptr ? -1 : firstFailure->firstDomainFailure.cellId;
    if (firstFailure != nullptr &&
        firstFailure->kind ==
            SurfaceCellSubdivisionFailureKind::InvalidReplacementBoundary &&
        failingCell >= 0 && failingCell < static_cast<int>(adjacency.size())) {
      for (const DualEdge &dual :
           adjacency[static_cast<std::size_t>(failingCell)]) {
        if (dual.halfedge < 0 ||
            dual.halfedge >= static_cast<int>(input.halfedges.size())) {
          continue;
        }
        const SurfaceArrangementHalfedge &edge =
            input.halfedges[static_cast<std::size_t>(dual.halfedge)];
        if (edge.twin < 0 ||
            edge.twin >= static_cast<int>(input.halfedges.size())) {
          continue;
        }
        const SurfaceArrangementHalfedge &twin =
            input.halfedges[static_cast<std::size_t>(edge.twin)];
        const int firstNode = std::min(edge.from, edge.to);
        const int secondNode = std::max(edge.from, edge.to);
        const int firstCell = std::min(edge.cell, twin.cell);
        const int secondCell = std::max(edge.cell, twin.cell);
        const bool exteriorInterface =
            input.cells[static_cast<std::size_t>(edge.cell)].boundaryCycle ||
            input.cells[static_cast<std::size_t>(twin.cell)].boundaryCycle;
        AlternativeInterface candidate;
        candidate.halfedge = std::min(edge.id, edge.twin);
        candidate.key = std::make_tuple(
            dual.hardFeature ? 1 : 0, exteriorInterface ? 1 : 0,
            edge.sourceTopologyRegion, edge.sourceChart, firstCell, secondCell,
            firstNode, secondNode, candidate.halfedge);
        localAlternatives.push_back(std::move(candidate));
      }
    }
    std::sort(localAlternatives.begin(), localAlternatives.end(),
              [](const AlternativeInterface &lhs,
                 const AlternativeInterface &rhs) {
                return lhs.key < rhs.key;
              });
    localAlternatives.erase(
        std::unique(localAlternatives.begin(), localAlternatives.end(),
                    [](const AlternativeInterface &lhs,
                       const AlternativeInterface &rhs) {
                      return lhs.halfedge == rhs.halfedge;
                    }),
        localAlternatives.end());
    result.alternativeCandidateBudget =
        static_cast<int>(localAlternatives.size());
    if (localAlternatives.empty()) {
      result.alternativeDisposition =
          SurfaceCellParityAlternativeDisposition::NoCandidate;
    }

    std::set<std::uint64_t> visitedStates;
    std::map<std::uint64_t, std::pair<bool, std::set<int>>> selectionCache;
    const auto stateHash = [&](const int excludedHalfedge) {
      std::uint64_t seed = 1469598103934665603ULL;
      const auto mix = [&](const std::uint64_t value) {
        seed ^= value;
        seed *= 1099511628211ULL;
      };
      mix(static_cast<std::uint64_t>(result.oddCellsBefore));
      mix(static_cast<std::uint64_t>(failingCell + 1));
      mix(static_cast<std::uint64_t>(
          firstFailure == nullptr
              ? SurfaceCellDomainIdentityFailureKind::None
              : firstFailure->firstDomainFailure.failure));
      mix(static_cast<std::uint64_t>(
          (firstFailure == nullptr ? -1 : firstFailure->firstDomainFailure.nodeId) +
          1));
      mix(static_cast<std::uint64_t>(excludedHalfedge + 1));
      for (const int halfedge : selected) {
        mix(static_cast<std::uint64_t>(halfedge + 1));
      }
      return seed;
    };
    std::uint64_t sequenceHash = 1469598103934665603ULL;
    for (const AlternativeInterface &alternative : localAlternatives) {
      const std::uint64_t hash = stateHash(alternative.halfedge);
      sequenceHash ^= hash;
      sequenceHash *= 1099511628211ULL;
      result.alternativeStateHashes.push_back(hash);
      if (!visitedStates.insert(hash).second) {
        result.alternativeDisposition =
            SurfaceCellParityAlternativeDisposition::CycleDetected;
        continue;
      }
      ++result.alternativeCandidatesAttempted;
      std::set<int> retrySelection;
      SurfaceCellParityRepairFailureKind retryFailure =
          SurfaceCellParityRepairFailureKind::None;
      const auto cached = selectionCache.find(hash);
      bool selectionValid = false;
      if (cached != selectionCache.end()) {
        selectionValid = cached->second.first;
        retrySelection = cached->second.second;
      } else {
        selectionValid = computeSelected({alternative.halfedge}, retrySelection,
                                         retryFailure);
        selectionCache.emplace(hash,
                               std::make_pair(selectionValid, retrySelection));
      }
      if (!selectionValid) {
        continue;
      }
      auto retry = consumeSubdivision(attemptSubdivision(retrySelection));
      if (retry.product.has_value()) {
        acceptedSubdivision = std::move(retry.product.value());
        acceptedSelection = std::move(retrySelection);
        result.alternativeSelectedExclusion = alternative.halfedge;
        result.alternativeDisposition =
            SurfaceCellParityAlternativeDisposition::Committed;
        break;
      }
    }
    result.alternativeVisitedStates = static_cast<int>(visitedStates.size());
    result.alternativeStateSequenceHash = sequenceHash;
    if (!acceptedSubdivision.has_value()) {
      if (result.alternativeDisposition ==
          SurfaceCellParityAlternativeDisposition::None) {
        result.alternativeDisposition =
            result.alternativeCandidatesAttempted >=
                        result.alternativeCandidateBudget &&
                    result.alternativeCandidateBudget > 0
                ? SurfaceCellParityAlternativeDisposition::BudgetExhausted
                : SurfaceCellParityAlternativeDisposition::AllInvalid;
      }
      if (firstSubdivision.notApplicable) {
        return reject(
            SurfaceCellParityRepairFailureKind::UnexpectedSubdivisionNotApplicable,
            "UnexpectedSubdivisionNotApplicable");
      }
      if (!firstSubdivision.failure.has_value()) {
        return reject(SurfaceCellParityRepairFailureKind::SubdivisionRejected,
                      "SubdivisionRejectedWithoutFailure");
      }
      SurfaceCellSubdivisionFailure failure =
          std::move(firstSubdivision.failure.value());
      std::string detail = failure.detail;
      if (result.alternativeDisposition ==
          SurfaceCellParityAlternativeDisposition::BudgetExhausted) {
        detail += ";AlternativeRepairBudgetExhausted;attempted=" +
                  std::to_string(result.alternativeCandidatesAttempted) +
                  ";budget=" +
                  std::to_string(result.alternativeCandidateBudget);
      } else if (result.alternativeDisposition ==
                 SurfaceCellParityAlternativeDisposition::CycleDetected) {
        detail += ";AlternativeRepairCycleDetected;visited=" +
                  std::to_string(result.alternativeVisitedStates);
      }
      result.firstScopeFailure = failure.firstScopeFailure;
      result.firstDomainFailure = failure.firstDomainFailure;
      return reject(SurfaceCellParityRepairFailureKind::SubdivisionRejected,
                    std::move(detail), std::move(failure));
    }
  }

  result.complex = std::move(acceptedSubdivision->complex);
  result.hardFeatureSplits = acceptedSubdivision->hardFeatureSplits;
  result.splitHalfedges.assign(acceptedSelection.begin(),
                               acceptedSelection.end());
  result.oddCellsAfter =
      surface_cell_feasibility_detail::odd_bounded_cell_count(result.complex);
  if (result.oddCellsAfter != 0) {
    return reject(SurfaceCellParityRepairFailureKind::ParityRepairIncomplete,
                  "ParityRepairIncomplete");
  }
  return SurfaceCellParityRepairResult::produced(std::move(result));
}

SurfaceCellSideRepairResult repair_surface_cell_side_subdivisions(
    SurfaceCellComplex input,
    const Eigen::MatrixXd &sourceVertices,
    const Eigen::MatrixXi &sourceFaces,
    const SurfaceCellSideRepairOptions &options) {
  SurfaceCellSideRepairProduct result;
  SurfaceCellComplex canonicalInput = std::move(input);
  struct LogicalSideUndo {
    std::vector<int> families;
    std::vector<int> counts;
  };
  std::vector<LogicalSideUndo> logicalSideUndo;
  logicalSideUndo.reserve(canonicalInput.cells.size());
  for (const SurfaceArrangementCell &cell : canonicalInput.cells) {
    logicalSideUndo.push_back({cell.sideFamilies, cell.sideEdgeCounts});
    result.rollbackUndoOwnedBytes +=
        static_cast<std::uint64_t>(cell.sideFamilies.capacity()) * sizeof(int) +
        static_cast<std::uint64_t>(cell.sideEdgeCounts.capacity()) * sizeof(int);
  }
  const auto rollbackIdentity =
      surface_cell_feasibility_detail::exact_rollback_identity(canonicalInput);
  surface_cell_feasibility_detail::canonicalize_logical_sides(
      canonicalInput, sourceVertices, sourceFaces);
  result.rollbackIdentityHashBefore =
      surface_cell_feasibility_detail::rollback_identity_hash(
          rollbackIdentity);
  const auto returnRollback =
      [&](SurfaceCellSideRepairFailureKind kind,
          std::string detail) -> SurfaceCellSideRepairResult {
    for (std::size_t index = 0; index < canonicalInput.cells.size() &&
                                index < logicalSideUndo.size();
         ++index) {
      canonicalInput.cells[index].sideFamilies =
          std::move(logicalSideUndo[index].families);
      canonicalInput.cells[index].sideEdgeCounts =
          std::move(logicalSideUndo[index].counts);
    }
    SurfaceCellComplex rollbackEvidence = std::move(canonicalInput);
    const auto after =
        surface_cell_feasibility_detail::exact_rollback_identity(
            rollbackEvidence);
    result.rollbackIdentityHashAfter =
        surface_cell_feasibility_detail::rollback_identity_hash(after);
    result.rollbackEquivalent = after == rollbackIdentity;
    if (!result.rollbackEquivalent) {
      const std::string mismatchDetail =
          "SideRepairRollbackMismatch:" + detail;
      return SurfaceCellSideRepairResult::rejected(
          side_failure_from_product(
              std::move(result), SurfaceCellSideRepairFailureKind::RollbackMismatch,
              mismatchDetail),
          std::move(rollbackEvidence));
    }
    if (const auto preparationReason =
            side_repair_fallback_preparation_reason(kind);
        preparationReason.has_value()) {
      result.kind = SurfaceCellSideRepairProductKind::GeneralFallbackPreparation;
      result.preparationReason = preparationReason.value();
      result.preparationDetail = std::move(detail);
      result.complex = std::move(rollbackEvidence);
      return SurfaceCellSideRepairResult::produced(std::move(result));
    }
    return SurfaceCellSideRepairResult::rejected(
        side_failure_from_product(std::move(result), kind, std::move(detail)),
        std::move(rollbackEvidence));
  };
  if (options.maxInsertedVertices < 0 ||
      options.maxLocalInsertedVertices < 0 ||
      options.maxPropagationPasses <= 0 || options.maxStagnantPasses <= 0) {
    return returnRollback(SurfaceCellSideRepairFailureKind::InvalidSideRepairOptions, "InvalidSideRepairOptions");
  }
  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(canonicalInput)) {
    return returnRollback(SurfaceCellSideRepairFailureKind::InvalidInputIncidence, "InvalidInputIncidence");
  }
  std::map<int, int> insertions;
  result.infeasibleCellsBefore =
      surface_cell_feasibility_detail::side_infeasible_cell_count(
          canonicalInput, insertions);
  result.initialEquationDefect =
      surface_cell_feasibility_detail::total_side_equation_defect(
          canonicalInput, insertions);
  result.finalEquationDefect = result.initialEquationDefect;
  if (result.infeasibleCellsBefore == 0) {
    result.complex = std::move(canonicalInput);
    result.kind = SurfaceCellSideRepairProductKind::Repaired;
    result.rollbackEquivalent = true;
    result.rollbackIdentityHashAfter = result.rollbackIdentityHashBefore;
    return SurfaceCellSideRepairResult::produced(std::move(result));
  }
  std::vector<int> halfedgeSide(canonicalInput.halfedges.size(), -1);
  for (const SurfaceArrangementCell &cell : canonicalInput.cells) {
    if (!surface_cell_feasibility_detail::supported_side_metadata(cell)) {
      continue;
    }
    const auto sides = surface_cell_feasibility_detail::side_halfedges(cell);
    for (int side = 0; side < static_cast<int>(sides.size()); ++side) {
      for (const int halfedge : sides[static_cast<std::size_t>(side)]) {
        halfedgeSide[static_cast<std::size_t>(halfedge)] = side;
      }
    }
  }
  int inserted = 0;
  int passes = 0;
  int stagnantPasses = 0;
  int bestDefect = result.initialEquationDefect;
  bool converged = result.infeasibleCellsBefore == 0;
  while (!converged && inserted < options.maxInsertedVertices &&
         passes < options.maxPropagationPasses) {
    ++passes;
    bool progress = false;
    for (const SurfaceArrangementCell &cell : canonicalInput.cells) {
      if (!surface_cell_feasibility_detail::supported_side_metadata(cell)) {
        continue;
      }
      const std::vector<int> counts =
          surface_cell_feasibility_detail::effective_side_counts(
              canonicalInput, cell, insertions);
      if (surface_cell_feasibility_detail::side_equations_hold(counts)) {
        continue;
      }
      const std::vector<int> delta =
          surface_cell_feasibility_detail::local_side_repair_delta(
              counts, options.maxLocalInsertedVertices);
      if (delta.size() != cell.sideEdgeCounts.size()) {
        result.propagationPasses = passes;
        result.attemptedInsertions = inserted;
        return returnRollback(SurfaceCellSideRepairFailureKind::LocalSideInsertionLimit, "LocalSideInsertionLimit");
      }
      const auto sideEdges =
          surface_cell_feasibility_detail::side_halfedges(cell);
      int selectedSide = -1;
      std::tuple<int, int, int, int, int> selectedScore{
          std::numeric_limits<int>::max(),
          std::numeric_limits<int>::max(), std::numeric_limits<int>::max(),
          std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
      int selectedEdge = -1;
      const int currentDefect =
          surface_cell_feasibility_detail::side_equation_defect(counts);
      for (int side = 0; side < static_cast<int>(delta.size()); ++side) {
        if (delta[static_cast<std::size_t>(side)] <= 0) {
          continue;
        }
        for (const int halfedge : sideEdges[static_cast<std::size_t>(side)]) {
          const int canonical =
              surface_cell_feasibility_detail::canonical_halfedge(canonicalInput,
                                                                  halfedge);
          const SurfaceArrangementHalfedge &oriented =
              canonicalInput.halfedges[static_cast<std::size_t>(halfedge)];
          const SurfaceArrangementHalfedge &twin =
              canonicalInput.halfedges[static_cast<std::size_t>(oriented.twin)];
          const SurfaceArrangementHalfedge &canonicalEdge =
              canonicalInput.halfedges[static_cast<std::size_t>(canonical)];
          const SurfaceArrangementHalfedge &canonicalTwin =
              canonicalInput.halfedges[
                  static_cast<std::size_t>(canonicalEdge.twin)];
          const int hard =
              canonicalEdge.hardFeature || canonicalTwin.hardFeature ? 1 : 0;
          const auto loaded = insertions.find(canonical);
          const int load = loaded == insertions.end() ? 0 : loaded->second;
          std::vector<int> currentAfter = counts;
          ++currentAfter[static_cast<std::size_t>(side)];
          int defectDelta =
              surface_cell_feasibility_detail::side_equation_defect(
                  currentAfter) -
              currentDefect;
          if (twin.cell != cell.id &&
              surface_cell_feasibility_detail::supported_side_metadata(
                  canonicalInput.cells[static_cast<std::size_t>(twin.cell)])) {
            const int twinSide =
                halfedgeSide[static_cast<std::size_t>(oriented.twin)];
            if (twinSide >= 0) {
              const SurfaceArrangementCell &neighbor =
                  canonicalInput.cells[static_cast<std::size_t>(twin.cell)];
              std::vector<int> neighborCounts =
                  surface_cell_feasibility_detail::effective_side_counts(
                      canonicalInput, neighbor, insertions);
              const int neighborBefore =
                  surface_cell_feasibility_detail::side_equation_defect(
                      neighborCounts);
              ++neighborCounts[static_cast<std::size_t>(twinSide)];
              defectDelta +=
                  surface_cell_feasibility_detail::side_equation_defect(
                      neighborCounts) -
                  neighborBefore;
            }
          }
          const auto score =
              std::make_tuple(defectDelta, hard, load, side, canonical);
          if (score < selectedScore) {
            selectedScore = score;
            selectedSide = side;
            selectedEdge = canonical;
          }
        }
      }
      if (selectedSide < 0 || selectedEdge < 0) {
        result.propagationPasses = passes;
        result.attemptedInsertions = inserted;
        return returnRollback(SurfaceCellSideRepairFailureKind::MissingSideSubdivisionEdge, "MissingSideSubdivisionEdge");
      }
      ++insertions[selectedEdge];
      ++inserted;
      progress = true;
      if (inserted >= options.maxInsertedVertices) {
        break;
      }
    }
    const int remaining =
        surface_cell_feasibility_detail::side_infeasible_cell_count(
            canonicalInput, insertions);
    const int defect =
        surface_cell_feasibility_detail::total_side_equation_defect(
            canonicalInput, insertions);
    result.infeasibleCellsAfter = remaining;
    result.finalEquationDefect = defect;
    result.propagationPasses = passes;
    result.attemptedInsertions = inserted;
    converged = remaining == 0;
    if (defect < bestDefect) {
      bestDefect = defect;
      stagnantPasses = 0;
    } else {
      ++stagnantPasses;
    }
    if (!progress && !converged) {
      return returnRollback(SurfaceCellSideRepairFailureKind::SideRepairStalled, "SideRepairStalled");
    }
    if (!converged && stagnantPasses >= options.maxStagnantPasses) {
      return returnRollback(SurfaceCellSideRepairFailureKind::CoupledSideRepairStalled, "CoupledSideRepairStalled");
    }
  }
  if (!converged) {
    const SurfaceCellSideRepairFailureKind limitKind =
        inserted >= options.maxInsertedVertices
            ? SurfaceCellSideRepairFailureKind::SideRepairInsertionLimit
            : SurfaceCellSideRepairFailureKind::SideRepairPropagationLimit;
    return returnRollback(limitKind,
                          surface_cell_side_repair_failure_kind_name(limitKind));
  }
  SurfaceCellSubdivisionResult subdivision =
      subdivide_surface_cell_complex_edges(std::move(canonicalInput),
                                           insertions, &sourceFaces);
  std::optional<SurfaceCellSubdivisionProduct> subdivisionProduct;
  std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure;
  bool subdivisionNotApplicable = false;
  std::visit(
      [&](auto &&outcome) {
        using Outcome = std::decay_t<decltype(outcome)>;
        if constexpr (std::is_same_v<Outcome, NotApplicable>) {
          subdivisionNotApplicable = true;
        } else if constexpr (
            std::is_same_v<Outcome, Produced<SurfaceCellSubdivisionProduct>>) {
          subdivisionProduct = std::move(outcome.product);
        } else {
          subdivisionFailure = std::move(outcome.failure);
        }
      },
      std::move(subdivision).outcome());
  if (subdivisionNotApplicable) {
    return SurfaceCellSideRepairResult::rejected(side_failure_from_product(
        std::move(result),
        SurfaceCellSideRepairFailureKind::UnexpectedSubdivisionNotApplicable,
        "UnexpectedSubdivisionNotApplicable"));
  }
  if (subdivisionFailure.has_value()) {
    SurfaceCellSubdivisionFailure failure =
        std::move(subdivisionFailure.value());
    result.rollbackEquivalent = failure.rollbackEquivalent;
    result.rollbackIdentityHashBefore = failure.rollbackIdentityHashBefore;
    result.rollbackIdentityHashAfter = failure.rollbackIdentityHashAfter;
    result.rollbackUndoOwnedBytes += failure.rollbackUndoOwnedBytes;
    result.firstDomainFailure = failure.firstDomainFailure;
    std::string detail = failure.detail;
    if (!result.rollbackEquivalent) {
      detail = "SideSubdivisionTransaction:" + detail;
    }
    return SurfaceCellSideRepairResult::rejected(side_failure_from_product(
        std::move(result), SurfaceCellSideRepairFailureKind::SubdivisionRejected,
        std::move(detail), std::move(failure)));
  }
  if (!subdivisionProduct.has_value()) {
    return SurfaceCellSideRepairResult::rejected(side_failure_from_product(
        std::move(result), SurfaceCellSideRepairFailureKind::SubdivisionRejected,
        "SubdivisionRejectedWithoutFailure"));
  }
  result.complex = std::move(subdivisionProduct->complex);
  result.propagationPasses = passes;
  result.attemptedInsertions = inserted;
  result.insertedVertices = subdivisionProduct->insertedVertices;
  result.splitUndirectedEdges = subdivisionProduct->splitUndirectedEdges;
  result.hardFeatureSplits = subdivisionProduct->hardFeatureSplits;
  result.infeasibleCellsAfter =
      surface_cell_feasibility_detail::side_infeasible_cell_count(
          result.complex, {});
  if (result.infeasibleCellsAfter != 0) {
    return SurfaceCellSideRepairResult::rejected(side_failure_from_product(
        std::move(result), SurfaceCellSideRepairFailureKind::SideRepairIncomplete,
        "SideRepairIncomplete"));
  }
  result.kind = SurfaceCellSideRepairProductKind::Repaired;
  result.rollbackIdentityHashAfter =
      surface_cell_feasibility_detail::rollback_identity_hash(
          surface_cell_feasibility_detail::exact_rollback_identity(
              result.complex));
  return SurfaceCellSideRepairResult::produced(std::move(result));
}

} // namespace directional::geometry
