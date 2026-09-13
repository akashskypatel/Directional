#include <directional/geometry/PatchDescriptor.h>

#include <cstring>
#include <iterator>
#include <type_traits>

namespace directional::geometry::patch_descriptor_detail {

struct SurfaceCellComplexCompletionDraft
    : SurfaceCellComplexCompletionEvidence {
  bool success = false;
  SurfaceCellComplexCompletionFailureKind failureKind =
      SurfaceCellComplexCompletionFailureKind::None;
  std::string failure;
  SurfaceCellComplex preparedComplex;
  bool hasPreparedComplex = false;
  PatchDescriptorSet descriptors;
  std::vector<PureQuadMesh> completedPatches;
  PureQuadAssemblyResult assembly;
};

SurfaceCellComplexCompletionResult close_surface_cell_complex_completion(
    SurfaceCellComplexCompletionDraft draft) {
  if (draft.success) {
    SurfaceCellComplexCompletionEvidence evidence =
        std::move(static_cast<SurfaceCellComplexCompletionEvidence &>(draft));
    SurfaceCellComplexCompletionProduct product;
    product.preparedComplex = std::move(draft.preparedComplex);
    product.hasPreparedComplex = draft.hasPreparedComplex;
    product.descriptors = std::move(draft.descriptors);
    product.completedPatches = std::move(draft.completedPatches);
    product.assembly = std::move(draft.assembly);
    return SurfaceCellComplexCompletionResult::produced(
        std::move(evidence), std::move(product));
  }
  if (draft.failureKind == SurfaceCellComplexCompletionFailureKind::None) {
    throw std::logic_error(
        "Surface-cell completion rejected without a typed failure.");
  }
  SurfaceCellComplexCompletionFailure failure;
  failure.kind = draft.failureKind;
  failure.detail = draft.failure.empty() ? draft.assembly.failure : draft.failure;
  failure.ownershipConflict = draft.assembly.ownershipConflict;
  failure.ownershipConflicts = std::move(draft.assembly.ownershipConflicts);
  SurfaceCellComplexCompletionEvidence evidence =
      std::move(static_cast<SurfaceCellComplexCompletionEvidence &>(draft));
  return SurfaceCellComplexCompletionResult::rejected(
      std::move(evidence), std::move(failure));
}


struct SourceScope {
  std::optional<authority::TopologyRegionId> region;
  std::optional<SourceProjectionChart> chart;

  [[nodiscard]] bool valid() const noexcept {
    return region.has_value() && chart.has_value();
  }

  auto operator<=>(const SourceScope &) const = default;
};

template <typename T>
SourceScope source_scope(const T &value) {
  return {value.sourceTopologyRegion, value.sourceChart};
}

void append_source_scope(SurfaceCellCanonicalIdentity &destination,
               const SourceScope &scope) {
  destination.values.push_back(scope.region.has_value() ? 1 : 0);
  if (scope.region.has_value()) {
    destination.topologyRegions.push_back(scope.region.value());
  }
  destination.values.push_back(scope.chart.has_value() ? 1 : 0);
  if (scope.chart.has_value()) {
    destination.sourceCharts.push_back(
        {scope.chart->chart, scope.chart->face});
  }
}

const SurfaceArrangementNode *find_node(
    const SurfaceCellComplex &complex, const int id) {
  if (id >= 0 && id < static_cast<int>(complex.nodes.size()) &&
      complex.nodes[static_cast<std::size_t>(id)].id == id) {
    return &complex.nodes[static_cast<std::size_t>(id)];
  }
  const auto it = std::find_if(
      complex.nodes.begin(), complex.nodes.end(),
      [&](const SurfaceArrangementNode &node) { return node.id == id; });
  return it == complex.nodes.end() ? nullptr : &*it;
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry::patch_descriptor_detail {

int normalized_family(const int family) {
  if (family < 0) {
    return family;
  }
  return family & 1;
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry::patch_descriptor_detail {

int source_vertex_at_node(const SurfaceArrangementNode &node,
                                 const Eigen::MatrixXi &F,
                                 const double tolerance) {
  const auto inspect = [&](const int face, const Eigen::RowVector3d &bary) {
    if (face < 0 || face >= F.rows()) {
      return -1;
    }
    int corner = 0;
    bary.maxCoeff(&corner);
    if (bary(corner) >= 1.0 - tolerance) {
      return F(face, corner);
    }
    return -1;
  };
  int vertex = inspect(node.sourceFace, node.barycentric);
  if (vertex >= 0) {
    return vertex;
  }
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    vertex = inspect(occurrence.sourceFace, occurrence.barycentric);
    if (vertex >= 0) {
      return vertex;
    }
  }
  return -1;
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry::patch_descriptor_detail {

SurfacePoint node_surface_point(const SurfaceArrangementNode &node,
                                       const Eigen::MatrixXd &V,
                                       const Eigen::MatrixXi &F,
                                       const SurfaceArrangementHalfedge &edge) {
  SurfacePoint point;
  const SourceScope edgeScope = source_scope(edge);
  const SurfaceArrangementNodeOccurrence *selected = nullptr;
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    if (!edgeScope.valid() || source_scope(occurrence) != edgeScope) {
      continue;
    }
    if (selected == nullptr ||
        std::make_tuple(occurrence.sourceFace == edge.sourceFace ? 0 : 1,
                        occurrence.sourceFace, occurrence.sourceArc,
                        occurrence.provenance) <
            std::make_tuple(selected->sourceFace == edge.sourceFace ? 0 : 1,
                            selected->sourceFace, selected->sourceArc,
                            selected->provenance)) {
      selected = &occurrence;
    }
  }
  point.face = selected != nullptr ? selected->sourceFace : node.sourceFace;
  point.barycentric =
      (selected != nullptr ? selected->barycentric : node.barycentric)
          .transpose();
  if (point.face >= 0 && point.face < F.rows() && F.cols() == 3 &&
      V.cols() == 3) {
    point.position =
        point.barycentric(0) * V.row(F(point.face, 0)).transpose() +
        point.barycentric(1) * V.row(F(point.face, 1)).transpose() +
        point.barycentric(2) * V.row(F(point.face, 2)).transpose();
    point.squaredDistance = 0.0;
  }
  return point;
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry::patch_descriptor_detail {

bool ordered_boundary(const SurfaceCellComplex &complex,
                             const SurfaceArrangementCell &cell,
                             std::vector<int> &ordered) {
  ordered.clear();
  if (cell.halfedges.empty()) {
    return false;
  }
  std::map<int, int> byFrom;
  for (const int id : cell.halfedges) {
    if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    if (edge.cell != cell.id || edge.from < 0 || edge.to < 0 ||
        !byFrom.emplace(edge.from, id).second) {
      return false;
    }
  }

  int current = *std::min_element(cell.halfedges.begin(), cell.halfedges.end());
  const int first = current;
  std::set<int> visited;
  while (visited.insert(current).second) {
    ordered.push_back(current);
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(current)];
    const auto next = byFrom.find(edge.to);
    if (next == byFrom.end()) {
      return false;
    }
    current = next->second;
  }
  return current == first && ordered.size() == cell.halfedges.size();
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry::patch_descriptor_detail {

std::vector<PatchSideDescriptor>
extract_sides(const SurfaceCellComplex &complex,
              const SurfaceArrangementCell &cell,
              const std::vector<int> &boundary,
              const Eigen::MatrixXd &V,
              const Eigen::MatrixXi &F) {
  std::vector<PatchSideDescriptor> sides;
  if (boundary.empty()) {
    return sides;
  }
  for (const int id : boundary) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    const int family = normalized_family(edge.family);
    bool continues = !sides.empty() && sides.back().family == family;
    if (continues) {
      const int previousId = sides.back().halfedges.back();
      continues = surface_arrangement_detail::same_logical_side(
          complex.halfedges[static_cast<std::size_t>(previousId)], edge,
          complex.nodes, V, F);
    }
    if (!continues) {
      PatchSideDescriptor side;
      side.family = family;
      sides.push_back(std::move(side));
    }
    PatchSideDescriptor &side = sides.back();
    side.halfedges.push_back(id);
    side.boundaryVertices.push_back(edge.from);
    ++side.subdivisionCount;
    side.hardFeature = side.hardFeature || edge.hardFeature;
    if (edge.railId.has_value()) {
      side.railIds.insert(edge.railId.value());
    }
    if (edge.curveId >= 0) {
      side.curveIds.insert(edge.curveId);
    }
  }
  if (sides.size() > 1 && sides.front().family == sides.back().family &&
      surface_arrangement_detail::same_logical_side(
          complex.halfedges[static_cast<std::size_t>(
              sides.back().halfedges.back())],
          complex.halfedges[static_cast<std::size_t>(
              sides.front().halfedges.front())],
          complex.nodes, V, F)) {
    PatchSideDescriptor tail = std::move(sides.back());
    sides.pop_back();
    PatchSideDescriptor &front = sides.front();
    front.halfedges.insert(front.halfedges.begin(), tail.halfedges.begin(),
                           tail.halfedges.end());
    front.boundaryVertices.insert(front.boundaryVertices.begin(),
                                  tail.boundaryVertices.begin(),
                                  tail.boundaryVertices.end());
    front.subdivisionCount += tail.subdivisionCount;
    front.hardFeature = front.hardFeature || tail.hardFeature;
    front.railIds.insert(tail.railIds.begin(), tail.railIds.end());
    front.curveIds.insert(tail.curveIds.begin(), tail.curveIds.end());
  }
  return sides;
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry::patch_descriptor_detail {

bool source_vertex_is_in_cell(const int vertex,
                                     const SurfaceArrangementCell &cell,
                                     const Eigen::MatrixXi &F) {
  for (const int face : cell.sourceFaces) {
    if (face < 0 || face >= F.rows()) {
      continue;
    }
    for (int corner = 0; corner < F.cols(); ++corner) {
      if (F(face, corner) == vertex) {
        return true;
      }
    }
  }
  if (cell.sourceFaces.empty() && cell.sourceFace >= 0 &&
      cell.sourceFace < F.rows()) {
    for (int corner = 0; corner < F.cols(); ++corner) {
      if (F(cell.sourceFace, corner) == vertex) {
        return true;
      }
    }
  }
  return false;
}

} // namespace directional::geometry::patch_descriptor_detail


namespace directional::geometry::patch_descriptor_detail {

std::int64_t quantized_parameter(const double value) {
  return static_cast<std::int64_t>(std::llround(value * 1.0e10));
}

void append_identity(SurfaceCellCanonicalIdentity &destination,
           const SurfaceCellCanonicalIdentity &identity) {
  destination.values.push_back(identity.valid ? 1 : 0);
  destination.values.push_back(static_cast<std::int64_t>(identity.values.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.topologyRegions.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.isolationSheets.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.ownershipClasses.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.sourceCharts.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.hardRails.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.supportVertices.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.supportEdges.size()));
  destination.values.push_back(static_cast<std::int64_t>(identity.supportFaces.size()));
  destination.values.insert(destination.values.end(), identity.values.begin(),
                            identity.values.end());
  destination.topologyRegions.insert(destination.topologyRegions.end(),
                                     identity.topologyRegions.begin(),
                                     identity.topologyRegions.end());
  destination.isolationSheets.insert(destination.isolationSheets.end(),
                                     identity.isolationSheets.begin(),
                                     identity.isolationSheets.end());
  destination.ownershipClasses.insert(destination.ownershipClasses.end(),
                                      identity.ownershipClasses.begin(),
                                      identity.ownershipClasses.end());
  destination.sourceCharts.insert(destination.sourceCharts.end(),
                                  identity.sourceCharts.begin(),
                                  identity.sourceCharts.end());
  destination.hardRails.insert(destination.hardRails.end(),
                               identity.hardRails.begin(), identity.hardRails.end());
  destination.supportVertices.insert(destination.supportVertices.end(),
                                     identity.supportVertices.begin(),
                                     identity.supportVertices.end());
  destination.supportEdges.insert(destination.supportEdges.end(),
                                  identity.supportEdges.begin(),
                                  identity.supportEdges.end());
  destination.supportFaces.insert(destination.supportFaces.end(),
                                  identity.supportFaces.begin(),
                                  identity.supportFaces.end());
}

std::optional<authority::SourceFaceTopologyKey> source_face_topology_identity(
    const Eigen::MatrixXi &F, const int face) {
  if (face < 0 || face >= F.rows() || F.cols() != 3) {
    return std::nullopt;
  }
  const int a = F(face, 0);
  const int b = F(face, 1);
  const int c = F(face, 2);
  if (a < 0 || b < 0 || c < 0) {
    return std::nullopt;
  }
  const std::size_t extent = static_cast<std::size_t>(std::max({a, b, c}) + 1);
  const auto av = authority::SourceVertexId::from_index(a, extent);
  const auto bv = authority::SourceVertexId::from_index(b, extent);
  const auto cv = authority::SourceVertexId::from_index(c, extent);
  if (!av || !bv || !cv) {
    return std::nullopt;
  }
  const auto topology = authority::SourceFaceTopologyKey::make(
      {av.value(), bv.value(), cv.value()});
  return topology ? std::optional<authority::SourceFaceTopologyKey>(topology.value())
                  : std::nullopt;
}

SurfaceCellCanonicalIdentity source_point_identity(
    const Eigen::MatrixXi &F, const int face,
    const Eigen::RowVector3d &barycentric, const SourceScope &scope) {
  SurfaceCellCanonicalIdentity result;
  if (!scope.valid() || face < 0 || face >= F.rows() || F.cols() != 3 ||
      !barycentric.allFinite()) {
    return result;
  }
  const auto faceTopology = source_face_topology_identity(F, face);
  if (!faceTopology.has_value()) {
    return result;
  }
  std::vector<std::pair<authority::SourceVertexId, std::int64_t>> weights;
  weights.reserve(3);
  for (int corner = 0; corner < 3; ++corner) {
    const int rawVertex = F(face, corner);
    const std::size_t extent = static_cast<std::size_t>(
        std::max({F(face, 0), F(face, 1), F(face, 2)}) + 1);
    const auto typedVertex = authority::SourceVertexId::from_index(rawVertex, extent);
    if (!typedVertex) return {};
    weights.emplace_back(typedVertex.value(),
                         quantized_parameter(barycentric[corner]));
  }
  std::sort(weights.begin(), weights.end());
  result.valid = true;
  append_source_scope(result, scope);
  result.values.push_back(static_cast<std::int64_t>(weights.size()));
  for (const auto &[vertex, weight] : weights) {
    result.supportVertices.push_back(vertex);
    result.values.push_back(weight);
  }
  return result;
}

SurfaceCellCanonicalIdentity arrangement_node_identity(
    const SurfaceArrangementNode &node, const Eigen::MatrixXi &F,
    const SourceScope &scope) {
  std::vector<SurfaceCellCanonicalIdentity> occurrences;
  if (!scope.valid()) return {};
  if (source_scope(node) == scope) {
    occurrences.push_back(source_point_identity(F, node.sourceFace, node.barycentric, scope));
  }
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    if (source_scope(occurrence) != scope) continue;
    occurrences.push_back(source_point_identity(F, occurrence.sourceFace, occurrence.barycentric, scope));
  }
  occurrences.erase(std::remove_if(occurrences.begin(), occurrences.end(),
                     [](const SurfaceCellCanonicalIdentity &identity) { return !identity.valid; }),
                     occurrences.end());
  std::sort(occurrences.begin(), occurrences.end());
  occurrences.erase(std::unique(occurrences.begin(), occurrences.end()), occurrences.end());
  SurfaceCellCanonicalIdentity result;
  if (occurrences.empty()) return result;
  result.valid = true;
  append_source_scope(result, scope);
  result.values.push_back(static_cast<std::int64_t>(occurrences.size()));
  for (const SurfaceCellCanonicalIdentity &occurrence : occurrences) append_identity(result, occurrence);
  return result;
}

SurfaceCellCanonicalIdentity provenance_semantics(const SurfaceArrangementProvenance &provenance) {
  SurfaceCellCanonicalIdentity result;
  result.valid = true;
  result.values = {provenance.family, provenance.featureClass,
                   provenance.hardFeature ? 1 : 0,
                   provenance.layoutSupport ? 1 : 0,
                   provenance.singularitySupport ? 1 : 0,
                   provenance.railId.has_value() ? 1 : 0,
                   provenance.curveId};
  if (provenance.railId.has_value()) result.hardRails.push_back(provenance.railId.value());
  append_source_scope(result, source_scope(provenance));
  result.values.insert(result.values.end(),
      {provenance.proposalSide, provenance.proposalBoundarySegment,
       quantized_parameter(std::min(provenance.sourceT0, provenance.sourceT1)),
       quantized_parameter(std::max(provenance.sourceT0, provenance.sourceT1)),
       quantized_parameter(std::min(provenance.railT0, provenance.railT1)),
       quantized_parameter(std::max(provenance.railT0, provenance.railT1))});
  return result;
}

SurfaceCellCanonicalIdentity halfedge_identity(
    const SurfaceCellComplex &complex, const SurfaceArrangementHalfedge &edge,
    const Eigen::MatrixXi &F, const bool directed) {
  const SurfaceArrangementNode *from = find_node(complex, edge.from);
  const SurfaceArrangementNode *to = find_node(complex, edge.to);
  const SourceScope edgeScope = source_scope(edge);
  if (from == nullptr || to == nullptr || !edgeScope.valid()) return {};
  SurfaceCellCanonicalIdentity fromIdentity = arrangement_node_identity(*from, F, edgeScope);
  SurfaceCellCanonicalIdentity toIdentity = arrangement_node_identity(*to, F, edgeScope);
  if (!fromIdentity.valid || !toIdentity.valid) return {};
  if (!directed && toIdentity < fromIdentity) std::swap(fromIdentity, toIdentity);
  std::vector<SurfaceCellCanonicalIdentity> provenance;
  provenance.reserve(edge.provenance.size());
  for (const SurfaceArrangementProvenance &entry : edge.provenance) provenance.push_back(provenance_semantics(entry));
  std::sort(provenance.begin(), provenance.end());
  SurfaceCellCanonicalIdentity result;
  result.valid = true;
  append_identity(result, fromIdentity);
  append_identity(result, toIdentity);
  result.values.insert(result.values.end(),
      {edge.family, edge.featureClass, edge.hardFeature ? 1 : 0,
       edge.layoutSupport ? 1 : 0, edge.singularitySupport ? 1 : 0,
       edge.railId.has_value() ? 1 : 0, edge.curveId});
  if (edge.railId.has_value()) result.hardRails.push_back(edge.railId.value());
  append_source_scope(result, edgeScope);
  result.values.insert(result.values.end(), {edge.proposalSide, edge.proposalBoundarySegment});
  if (directed) {
    result.values.push_back(quantized_parameter(edge.sourceT0));
    result.values.push_back(quantized_parameter(edge.sourceT1));
    result.values.push_back(quantized_parameter(edge.railT0));
    result.values.push_back(quantized_parameter(edge.railT1));
  } else {
    result.values.push_back(quantized_parameter(std::min(edge.sourceT0, edge.sourceT1)));
    result.values.push_back(quantized_parameter(std::max(edge.sourceT0, edge.sourceT1)));
    result.values.push_back(quantized_parameter(std::min(edge.railT0, edge.railT1)));
    result.values.push_back(quantized_parameter(std::max(edge.railT0, edge.railT1)));
  }
  result.values.push_back(static_cast<std::int64_t>(provenance.size()));
  for (const SurfaceCellCanonicalIdentity &entry : provenance) append_identity(result, entry);
  return result;
}

std::vector<SurfaceCellCanonicalIdentity> canonical_cycle_rotation(const std::vector<SurfaceCellCanonicalIdentity> &cycle) {
  if (cycle.empty()) return {};
  std::vector<SurfaceCellCanonicalIdentity> best;
  for (std::size_t start = 0; start < cycle.size(); ++start) {
    std::vector<SurfaceCellCanonicalIdentity> candidate;
    candidate.reserve(cycle.size());
    for (std::size_t offset = 0; offset < cycle.size(); ++offset) candidate.push_back(cycle[(start + offset) % cycle.size()]);
    if (best.empty() || candidate < best) best = std::move(candidate);
  }
  return best;
}

SurfaceCellCanonicalIdentity flatten_identities(const std::vector<SurfaceCellCanonicalIdentity> &identities) {
  SurfaceCellCanonicalIdentity result;
  if (identities.empty()) return result;
  result.valid = true;
  result.values.push_back(static_cast<std::int64_t>(identities.size()));
  for (const SurfaceCellCanonicalIdentity &identity : identities) append_identity(result, identity);
  return result;
}

SurfaceCellCanonicalIdentity source_support_identity(const SurfaceArrangementCell &cell, const Eigen::MatrixXi &F) {
  std::vector<authority::SourceFaceTopologyKey> faces;
  std::vector<int> sourceFaces = cell.sourceFaces;
  if (sourceFaces.empty() && cell.sourceFace >= 0) sourceFaces.push_back(cell.sourceFace);
  for (const int face : sourceFaces) {
    const auto topology = source_face_topology_identity(F, face);
    if (!topology.has_value()) return {};
    faces.push_back(topology.value());
  }
  std::sort(faces.begin(), faces.end());
  faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  SurfaceCellCanonicalIdentity result;
  if (faces.empty()) return result;
  result.valid = true;
  result.values.push_back(static_cast<std::int64_t>(faces.size()));
  result.supportFaces = std::move(faces);
  return result;
}

SurfaceCellCanonicalIdentity source_chart_map_identity(const SurfaceArrangementCell &cell, const Eigen::MatrixXi &F) {
  (void)F;
  SurfaceCellCanonicalIdentity result;
  std::vector<SurfaceCellSourceChartIdentity> charts;
  charts.reserve(cell.sourceCharts.size());
  for (const SourceProjectionChart &chart : cell.sourceCharts) {
    if (!chart.valid()) return {};
    charts.push_back({chart.chart, chart.face});
  }
  std::sort(charts.begin(), charts.end());
  charts.erase(std::unique(charts.begin(), charts.end()), charts.end());
  if (charts.empty()) return result;
  result.valid = true;
  result.values.push_back(static_cast<std::int64_t>(charts.size()));
  result.sourceCharts = std::move(charts);
  return result;
}


bool cell_contains_source_chart(const SurfaceArrangementCell &cell,
                                const SourceProjectionChart &chart) {
  return std::binary_search(cell.sourceCharts.begin(), cell.sourceCharts.end(),
                            chart);
}

int source_support_count(const SurfaceArrangementCell &cell,
                         const Eigen::MatrixXi &F) {
  std::vector<std::array<int, 3>> faces;
  std::vector<int> sourceFaces = cell.sourceFaces;
  if (sourceFaces.empty() && cell.sourceFace >= 0) {
    sourceFaces.push_back(cell.sourceFace);
  }
  for (const int face : sourceFaces) {
    if (face < 0 || face >= F.rows() || F.cols() != 3) {
      continue;
    }
    std::array<int, 3> vertices{{F(face, 0), F(face, 1), F(face, 2)}};
    std::sort(vertices.begin(), vertices.end());
    faces.push_back(vertices);
  }
  std::sort(faces.begin(), faces.end());
  faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  return static_cast<int>(faces.size());
}

SurfaceCellDomainIdentityAudit build_domain_identity_audit(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::vector<int> &boundary, const Eigen::MatrixXi &F) {
  SurfaceCellDomainIdentityAudit audit;
  audit.cellId = cell.id;
  if (boundary.empty()) {
    audit.failure = SurfaceCellDomainIdentityFailureKind::EmptyBoundary;
    return audit;
  }
  if (!cell.closed) {
    audit.failure = SurfaceCellDomainIdentityFailureKind::OpenBoundary;
    return audit;
  }
  if (!cell.sourceTopologyRegion.has_value() || cell.sourceCharts.empty() ||
      !std::is_sorted(cell.sourceCharts.begin(), cell.sourceCharts.end())) {
    audit.failure = SurfaceCellDomainIdentityFailureKind::MissingSourceChart;
    return audit;
  }
  if (!cell.sourceOwnershipClass.has_value()) {
    audit.failure =
        SurfaceCellDomainIdentityFailureKind::OwnershipRegistryMismatch;
    return audit;
  }
  const SurfaceCellOwnershipClassRecord *ownershipRecord =
      find_surface_cell_ownership_class(
          complex, cell.sourceTopologyRegion, cell.sourceOwnershipClass);
  if (ownershipRecord == nullptr ||
      ownershipRecord->sourceTopologyRegion != cell.sourceTopologyRegion) {
    audit.failure =
        SurfaceCellDomainIdentityFailureKind::OwnershipRegistryMismatch;
    return audit;
  }
  for (const SourceProjectionChart &chart : cell.sourceCharts) {
    if (!std::binary_search(ownershipRecord->exactCharts.begin(),
                            ownershipRecord->exactCharts.end(), chart)) {
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::OwnershipRegistryMismatch;
      return audit;
    }
  }

  std::vector<SurfaceCellCanonicalIdentity> directed;
  std::vector<SurfaceCellCanonicalIdentity> undirected;
  std::set<SourceProjectionChart> exactCharts;
  std::set<int> seenBoundaryHalfedges;
  std::set<int> seenBoundaryNodes;
  directed.reserve(boundary.size());
  undirected.reserve(boundary.size());

  const auto node_occurrence_failure =
      [&](const SurfaceArrangementNode &node, const SourceScope &scope,
          int &sourceFace) {
        bool hasSourceChart = false;
        const auto accept = [&](const int face,
                                const Eigen::RowVector3d &barycentric,
                                const SourceScope &occurrenceScope) {
          if (face < 0 || face >= F.rows() || F.cols() != 3 ||
              occurrenceScope != scope) {
            return false;
          }
          hasSourceChart = true;
          sourceFace = face;
          if (!barycentric.allFinite() ||
              barycentric.minCoeff() < -1.0e-10 ||
              barycentric.maxCoeff() > 1.0 + 1.0e-10 ||
              std::abs(barycentric.sum() - 1.0) > 1.0e-8) {
            return false;
          }
          return source_point_identity(F, face, barycentric, scope).valid;
        };
        if (accept(node.sourceFace, node.barycentric, source_scope(node))) {
          return SurfaceCellDomainIdentityFailureKind::None;
        }
        for (const SurfaceArrangementNodeOccurrence &occurrence :
             node.occurrences) {
          if (accept(occurrence.sourceFace, occurrence.barycentric,
                     source_scope(occurrence))) {
            return SurfaceCellDomainIdentityFailureKind::None;
          }
        }
        return hasSourceChart
            ? SurfaceCellDomainIdentityFailureKind::InvalidEndpointBarycentric
            : SurfaceCellDomainIdentityFailureKind::
                  MissingEndpointSourceOccurrence;
      };

  for (std::size_t boundaryIndex = 0; boundaryIndex < boundary.size();
       ++boundaryIndex) {
    const int halfedgeId = boundary[boundaryIndex];
    audit.halfedgeId = halfedgeId;
    if (!seenBoundaryHalfedges.insert(halfedgeId).second) {
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::RepeatedBoundaryHalfedge;
      return audit;
    }
    if (halfedgeId < 0 ||
        halfedgeId >= static_cast<int>(complex.halfedges.size())) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::InvalidHalfedge;
      return audit;
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    if (edge.id != halfedgeId) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::InvalidHalfedge;
      return audit;
    }
    if (edge.twin < 0 ||
        edge.twin >= static_cast<int>(complex.halfedges.size()) ||
        complex.halfedges[static_cast<std::size_t>(edge.twin)].twin !=
            edge.id) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::InvalidTwin;
      return audit;
    }
    const int expectedNext =
        boundary[(boundaryIndex + 1U) % boundary.size()];
    if (edge.next != expectedNext) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::InvalidNext;
      return audit;
    }
    if (edge.cell != cell.id) {
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::InvalidCellIncidence;
      return audit;
    }
    if (edge.from < 0 ||
        edge.from >= static_cast<int>(complex.nodes.size()) ||
        edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()) ||
        complex.halfedges[static_cast<std::size_t>(expectedNext)].from !=
            edge.to) {
      audit.nodeId = edge.from < 0 ||
                             edge.from >= static_cast<int>(complex.nodes.size())
                         ? edge.from
                         : edge.to;
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::InvalidEndpointNode;
      return audit;
    }
    if (!seenBoundaryNodes.insert(edge.from).second) {
      audit.nodeId = edge.from;
      audit.failure = SurfaceCellDomainIdentityFailureKind::RepeatedBoundaryNode;
      return audit;
    }

    const SourceScope edgeScope = source_scope(edge);
    audit.sourceComponent = -1;
    audit.sourceSheet = -1;
    audit.sourceFace = edge.sourceFace;
    if (!edgeScope.valid() || edgeScope.region != cell.sourceTopologyRegion ||
        !cell_contains_source_chart(cell, edgeScope.chart.value())) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::MissingSourceChart;
      return audit;
    }
    exactCharts.insert(edgeScope.chart.value());

    const SurfaceArrangementNode &from =
        complex.nodes[static_cast<std::size_t>(edge.from)];
    const SurfaceArrangementNode &to =
        complex.nodes[static_cast<std::size_t>(edge.to)];
    int validFace = -1;
    const SurfaceCellDomainIdentityFailureKind fromFailure =
        node_occurrence_failure(from, edgeScope, validFace);
    if (fromFailure != SurfaceCellDomainIdentityFailureKind::None) {
      audit.nodeId = edge.from;
      audit.sourceFace = validFace >= 0 ? validFace : edge.sourceFace;
      audit.failure = fromFailure;
      return audit;
    }
    validFace = -1;
    const SurfaceCellDomainIdentityFailureKind toFailure =
        node_occurrence_failure(to, edgeScope, validFace);
    if (toFailure != SurfaceCellDomainIdentityFailureKind::None) {
      audit.nodeId = edge.to;
      audit.sourceFace = validFace >= 0 ? validFace : edge.sourceFace;
      audit.failure = toFailure;
      return audit;
    }

    SurfaceCellCanonicalIdentity directedIdentity =
        halfedge_identity(complex, edge, F, true);
    SurfaceCellCanonicalIdentity undirectedIdentity =
        halfedge_identity(complex, edge, F, false);
    if (!directedIdentity.valid) {
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::InvalidOrientedBoundaryIdentity;
      return audit;
    }
    if (!undirectedIdentity.valid) {
      audit.failure = SurfaceCellDomainIdentityFailureKind::
          InvalidUndirectedBoundaryIdentity;
      return audit;
    }
    directed.push_back(std::move(directedIdentity));
    undirected.push_back(std::move(undirectedIdentity));
  }

  for (const SourceProjectionChart &chart : exactCharts) {
    if (!std::binary_search(ownershipRecord->exactCharts.begin(),
                            ownershipRecord->exactCharts.end(), chart)) {
      audit.failure =
          SurfaceCellDomainIdentityFailureKind::OwnershipRegistryMismatch;
      return audit;
    }
  }

  std::sort(undirected.begin(), undirected.end());
  audit.identity.orientedBoundary =
      flatten_identities(canonical_cycle_rotation(directed));
  audit.identity.undirectedBoundary = flatten_identities(undirected);
  audit.identity.sourceSupport = source_support_identity(cell, F);
  audit.identity.sourceOwnershipClass = cell.sourceOwnershipClass;
  audit.identity.sourceChartMap = source_chart_map_identity(cell, F);
  audit.identity.boundaryNodeCount = static_cast<int>(boundary.size());
  audit.identity.boundaryHalfedgeCount = static_cast<int>(boundary.size());
  audit.identity.sourceSupportCount = source_support_count(cell, F);
  audit.identity.sourceTopologyRegion = cell.sourceTopologyRegion;
  if (!audit.identity.sourceSupport.valid ||
      !audit.identity.sourceOwnershipClass.has_value() ||
      !audit.identity.sourceChartMap.valid ||
      !audit.identity.sourceTopologyRegion.has_value() ||
      audit.identity.sourceSupportCount <= 0) {
    audit.failure = SurfaceCellDomainIdentityFailureKind::InvalidSourceSupport;
    return audit;
  }
  if (!audit.identity.orientedBoundary.valid) {
    audit.failure =
        SurfaceCellDomainIdentityFailureKind::InvalidOrientedBoundaryIdentity;
    return audit;
  }
  if (!audit.identity.undirectedBoundary.valid) {
    audit.failure = SurfaceCellDomainIdentityFailureKind::
        InvalidUndirectedBoundaryIdentity;
    return audit;
  }
  audit.identity.valid = true;
  audit.valid = true;
  audit.failure = SurfaceCellDomainIdentityFailureKind::None;
  return audit;
}


SurfaceCellDomainIdentity build_domain_identity(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::vector<int> &boundary, const Eigen::MatrixXi &F) {
  return build_domain_identity_audit(complex, cell, boundary, F).identity;
}

void compact_identity_group(
    std::vector<SurfaceCellCanonicalIdentity *> identities,
    const std::int64_t namespaceTag) {
  identities.erase(
      std::remove_if(identities.begin(), identities.end(),
                     [](const SurfaceCellCanonicalIdentity *identity) {
                       return identity == nullptr || !identity->valid;
                     }),
      identities.end());
  std::sort(identities.begin(), identities.end(),
            [](const SurfaceCellCanonicalIdentity *lhs,
               const SurfaceCellCanonicalIdentity *rhs) {
              if (*lhs != *rhs) {
                return *lhs < *rhs;
              }
              return lhs < rhs;
            });

  std::vector<std::pair<SurfaceCellCanonicalIdentity *, std::int64_t>>
      assignments;
  assignments.reserve(identities.size());
  std::int64_t nextId = -1;
  const SurfaceCellCanonicalIdentity *previous = nullptr;
  for (SurfaceCellCanonicalIdentity *identity : identities) {
    if (previous == nullptr || *identity != *previous) {
      ++nextId;
      previous = identity;
    }
    assignments.emplace_back(identity, nextId);
  }
  for (const auto &[identity, id] : assignments) {
    std::vector<std::int64_t> compactValues{namespaceTag, id};
    identity->values.swap(compactValues);
    identity->valid = true;
  }
}

void compact_patch_ownership_identities(
    std::vector<PatchDescriptor> &descriptors) {
  std::vector<SurfaceCellCanonicalIdentity *> boundaryNodes;
  std::vector<SurfaceCellCanonicalIdentity *> orientedBoundaries;
  std::vector<SurfaceCellCanonicalIdentity *> undirectedBoundaries;
  std::vector<SurfaceCellCanonicalIdentity *> sourceSupports;
  for (PatchDescriptor &descriptor : descriptors) {
    for (SurfaceCellCanonicalIdentity &identity :
         descriptor.patch.boundaryNodeIdentities) {
      boundaryNodes.push_back(&identity);
    }
    orientedBoundaries.push_back(
        &descriptor.patch.domainIdentity.orientedBoundary);
    undirectedBoundaries.push_back(
        &descriptor.patch.domainIdentity.undirectedBoundary);
    sourceSupports.push_back(&descriptor.patch.domainIdentity.sourceSupport);
  }
  // IDs are assigned after exact lexicographic comparison of the complete
  // records. They are collision-free interned identities, not hashes, and are
  // deterministic under descriptor, patch, and source-face reordering.
  compact_identity_group(std::move(boundaryNodes), 1);
  compact_identity_group(std::move(orientedBoundaries), 2);
  compact_identity_group(std::move(undirectedBoundaries), 3);
  compact_identity_group(std::move(sourceSupports), 4);
}

int completion_variant_count(const PureQuadPatch &patch,
                             const PureQuadCompletionBackend backend) {
  switch (backend) {
  case PureQuadCompletionBackend::TransitionTemplate:
    return 6;
  case PureQuadCompletionBackend::Pattern:
  case PureQuadCompletionBackend::BoundedCombinatorial:
    return std::max(1, 2 * static_cast<int>(patch.boundaryVertices.size()));
  case PureQuadCompletionBackend::ClosedForm:
  case PureQuadCompletionBackend::PoleTemplate:
  case PureQuadCompletionBackend::SourceGridRecovery:
    return 1;
  }
  return 1;
}


const SurfaceArrangementCell *find_cell_by_id(
    const SurfaceCellComplex &complex, const int cellId) {
  if (cellId >= 0 && cellId < static_cast<int>(complex.cells.size()) &&
      complex.cells[static_cast<std::size_t>(cellId)].id == cellId) {
    return &complex.cells[static_cast<std::size_t>(cellId)];
  }
  const auto found = std::find_if(
      complex.cells.begin(), complex.cells.end(),
      [&](const SurfaceArrangementCell &cell) { return cell.id == cellId; });
  return found == complex.cells.end() ? nullptr : &*found;
}

int canonical_complex_halfedge(const SurfaceCellComplex &complex,
                               const int halfedgeId) {
  if (halfedgeId < 0 ||
      halfedgeId >= static_cast<int>(complex.halfedges.size())) {
    return -1;
  }
  const SurfaceArrangementHalfedge &edge =
      complex.halfedges[static_cast<std::size_t>(halfedgeId)];
  if (edge.twin < 0 ||
      edge.twin >= static_cast<int>(complex.halfedges.size())) {
    return -1;
  }
  return std::min(edge.id, edge.twin);
}

std::set<int> canonical_cell_boundary(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell) {
  std::set<int> result;
  for (const int halfedgeId : cell.halfedges) {
    const int canonical = canonical_complex_halfedge(complex, halfedgeId);
    if (canonical < 0) {
      return {};
    }
    result.insert(canonical);
  }
  return result;
}

struct SameCornerBoundaryRoute {
  int patch = -1;
  bool hardFeature = false;
  SurfaceCellCanonicalIdentity firstCorner;
  SurfaceCellCanonicalIdentity secondCorner;
  std::vector<int> halfedges;
  std::vector<SurfaceCellCanonicalIdentity> boundaryIdentities;
  std::vector<SurfaceCellCanonicalIdentity> geometricSupportIdentities;
  SurfaceCellCanonicalIdentity endpointIdentity;
  SurfaceCellCanonicalIdentity exactIdentity;
  SurfaceCellCanonicalIdentity geometricIdentity;
};

struct SameCornerRouteCandidate {
  int priority = 1;
  bool hardFeature = false;
  std::vector<int> patches;
  std::vector<int> halfedges;
  std::vector<std::uint64_t> sharedCornerIdentityHashes;
  SurfaceCellCanonicalIdentity identity;

  friend bool operator<(const SameCornerRouteCandidate &lhs,
                        const SameCornerRouteCandidate &rhs) {
    return std::tie(lhs.priority, lhs.hardFeature, lhs.identity, lhs.patches,
                    lhs.halfedges) <
           std::tie(rhs.priority, rhs.hardFeature, rhs.identity, rhs.patches,
                    rhs.halfedges);
  }
};

struct SameCornerRouteCandidateSet {
  std::vector<SameCornerRouteCandidate> candidates;
  bool semanticOverlap = false;
  bool incompleteRoute = false;
};

SurfaceCellCanonicalIdentity source_face_geometry_identity(
    const Eigen::MatrixXi &F, const int face) {
  SurfaceCellCanonicalIdentity result;
  const auto topology = source_face_topology_identity(F, face);
  if (!topology.has_value()) return result;
  result.valid = true;
  result.values.push_back(1);
  result.supportFaces.push_back(topology.value());
  return result;
}

SurfaceCellCanonicalIdentity halfedge_geometric_support_identity(
    const SurfaceCellComplex &complex,
    const SurfaceArrangementHalfedge &edge, const Eigen::MatrixXi &F) {
  const SurfaceArrangementNode *from = find_node(complex, edge.from);
  const SurfaceArrangementNode *to = find_node(complex, edge.to);
  if (from == nullptr || to == nullptr) return {};
  const SourceScope edgeScope = source_scope(edge);
  SurfaceCellCanonicalIdentity fromIdentity =
      arrangement_node_identity(*from, F, edgeScope);
  SurfaceCellCanonicalIdentity toIdentity =
      arrangement_node_identity(*to, F, edgeScope);
  if (!fromIdentity.valid || !toIdentity.valid) return {};
  if (toIdentity < fromIdentity) std::swap(fromIdentity, toIdentity);
  std::vector<SurfaceCellCanonicalIdentity> support;
  const auto appendSupport = [&](const int sourceFace, const double t0,
                                 const double t1) {
    SurfaceCellCanonicalIdentity item =
        source_face_geometry_identity(F, sourceFace);
    if (!item.valid) return;
    item.values.push_back(quantized_parameter(std::min(t0, t1)));
    item.values.push_back(quantized_parameter(std::max(t0, t1)));
    support.push_back(std::move(item));
  };
  appendSupport(edge.sourceFace, edge.sourceT0, edge.sourceT1);
  for (const SurfaceArrangementProvenance &entry : edge.provenance) {
    appendSupport(entry.sourceFace, entry.sourceT0, entry.sourceT1);
  }
  std::sort(support.begin(), support.end());
  support.erase(std::unique(support.begin(), support.end()), support.end());
  SurfaceCellCanonicalIdentity result;
  result.valid = true;
  append_source_scope(result, edgeScope);
  append_identity(result, fromIdentity);
  append_identity(result, toIdentity);
  result.values.push_back(static_cast<std::int64_t>(support.size()));
  for (const auto &item : support) append_identity(result, item);
  return result;
}

SurfaceCellCanonicalIdentity boundary_node_identity(
    const SurfaceCellComplex &complex, const int halfedgeId,
    const Eigen::MatrixXi &F) {
  if (halfedgeId < 0 ||
      halfedgeId >= static_cast<int>(complex.halfedges.size())) return {};
  const SurfaceArrangementHalfedge &edge =
      complex.halfedges[static_cast<std::size_t>(halfedgeId)];
  const SurfaceArrangementNode *node = find_node(complex, edge.from);
  return node == nullptr ? SurfaceCellCanonicalIdentity{}
                         : arrangement_node_identity(*node, F, source_scope(edge));
}

SurfaceCellCanonicalIdentity endpoint_pair_identity(
    SurfaceCellCanonicalIdentity first, SurfaceCellCanonicalIdentity second) {
  if (!first.valid || !second.valid || first == second) return {};
  if (second < first) std::swap(first, second);
  SurfaceCellCanonicalIdentity result;
  result.valid = true;
  append_identity(result, first);
  append_identity(result, second);
  return result;
}

std::vector<SameCornerBoundaryRoute> boundary_routes_between_shared_corners(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const Eigen::MatrixXi &F,
    const std::set<SurfaceCellCanonicalIdentity> &sharedCorners,
    bool &incomplete) {
  std::vector<int> boundary;
  if (!ordered_boundary(complex, cell, boundary) || boundary.size() < 2U) {
    incomplete = true;
    return {};
  }
  std::vector<SurfaceCellCanonicalIdentity> nodeIdentities;
  nodeIdentities.reserve(boundary.size());
  std::vector<int> anchors;
  for (int index = 0; index < static_cast<int>(boundary.size()); ++index) {
    SurfaceCellCanonicalIdentity identity = boundary_node_identity(
        complex, boundary[static_cast<std::size_t>(index)], F);
    if (!identity.valid) { incomplete = true; return {}; }
    nodeIdentities.push_back(identity);
    if (sharedCorners.count(identity) != 0U) anchors.push_back(index);
  }
  if (anchors.size() < 2U) { incomplete = true; return {}; }
  std::vector<SameCornerBoundaryRoute> routes;
  routes.reserve(anchors.size());
  for (int anchor = 0; anchor < static_cast<int>(anchors.size()); ++anchor) {
    const int begin = anchors[static_cast<std::size_t>(anchor)];
    const int end = anchors[static_cast<std::size_t>((anchor + 1) % static_cast<int>(anchors.size()))];
    SameCornerBoundaryRoute route;
    route.patch = cell.id;
    route.firstCorner = nodeIdentities[static_cast<std::size_t>(begin)];
    route.secondCorner = nodeIdentities[static_cast<std::size_t>(end)];
    route.endpointIdentity = endpoint_pair_identity(route.firstCorner, route.secondCorner);
    if (!route.endpointIdentity.valid) { incomplete = true; return {}; }
    int cursor = begin;
    do {
      const int directedHalfedge = boundary[static_cast<std::size_t>(cursor)];
      const int canonical = canonical_complex_halfedge(complex, directedHalfedge);
      if (canonical < 0 || canonical >= static_cast<int>(complex.halfedges.size())) { incomplete = true; return {}; }
      const SurfaceArrangementHalfedge &edge = complex.halfedges[static_cast<std::size_t>(canonical)];
      const SurfaceArrangementHalfedge &twin = complex.halfedges[static_cast<std::size_t>(edge.twin)];
      SurfaceCellCanonicalIdentity boundaryIdentity = halfedge_identity(complex, edge, F, false);
      SurfaceCellCanonicalIdentity geometricIdentity = halfedge_geometric_support_identity(complex, edge, F);
      if (!boundaryIdentity.valid || !geometricIdentity.valid) { incomplete = true; return {}; }
      route.halfedges.push_back(canonical);
      route.boundaryIdentities.push_back(std::move(boundaryIdentity));
      route.geometricSupportIdentities.push_back(std::move(geometricIdentity));
      route.hardFeature = route.hardFeature || edge.hardFeature || twin.hardFeature;
      cursor = (cursor + 1) % static_cast<int>(boundary.size());
    } while (cursor != end);
    if (route.secondCorner < route.firstCorner) {
      std::swap(route.firstCorner, route.secondCorner);
      std::reverse(route.halfedges.begin(), route.halfedges.end());
      std::reverse(route.boundaryIdentities.begin(), route.boundaryIdentities.end());
      std::reverse(route.geometricSupportIdentities.begin(), route.geometricSupportIdentities.end());
    }
    route.exactIdentity = route.endpointIdentity;
    route.exactIdentity.values.push_back(static_cast<std::int64_t>(route.boundaryIdentities.size()));
    for (const auto &identity : route.boundaryIdentities) append_identity(route.exactIdentity, identity);
    route.geometricIdentity = route.endpointIdentity;
    route.geometricIdentity.values.push_back(static_cast<std::int64_t>(route.geometricSupportIdentities.size()));
    for (const auto &identity : route.geometricSupportIdentities) append_identity(route.geometricIdentity, identity);
    routes.push_back(std::move(route));
  }
  return routes;
}

SameCornerRouteCandidateSet same_corner_route_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceCellOwnershipConflict &conflict,
    const Eigen::MatrixXi &F) {
  SameCornerRouteCandidateSet result;
  const SurfaceArrangementCell *first = find_cell_by_id(complex, conflict.firstPatch);
  const SurfaceArrangementCell *second = find_cell_by_id(complex, conflict.secondPatch);
  if (first == nullptr || second == nullptr) { result.incompleteRoute = true; return result; }
  const auto boundaryNodeSet = [&](const SurfaceArrangementCell &cell) {
    std::set<SurfaceCellCanonicalIdentity> identities;
    std::vector<int> boundary;
    if (!ordered_boundary(complex, cell, boundary)) return identities;
    for (const int halfedge : boundary) {
      SurfaceCellCanonicalIdentity identity = boundary_node_identity(complex, halfedge, F);
      if (!identity.valid) { identities.clear(); return identities; }
      identities.insert(std::move(identity));
    }
    return identities;
  };
  const auto firstNodes = boundaryNodeSet(*first);
  const auto secondNodes = boundaryNodeSet(*second);
  if (firstNodes.empty() || secondNodes.empty()) { result.incompleteRoute = true; return result; }
  std::set<SurfaceCellCanonicalIdentity> sharedCorners;
  std::set_intersection(firstNodes.begin(), firstNodes.end(), secondNodes.begin(), secondNodes.end(), std::inserter(sharedCorners, sharedCorners.end()));
  if (sharedCorners.size() < 2U) { result.incompleteRoute = true; return result; }
  bool incomplete = false;
  const auto firstRoutes = boundary_routes_between_shared_corners(complex, *first, F, sharedCorners, incomplete);
  const auto secondRoutes = boundary_routes_between_shared_corners(complex, *second, F, sharedCorners, incomplete);
  if (incomplete || firstRoutes.empty() || secondRoutes.empty()) { result.incompleteRoute = true; return result; }
  std::map<SurfaceCellCanonicalIdentity, std::vector<SameCornerBoundaryRoute>> firstByEndpoints;
  std::map<SurfaceCellCanonicalIdentity, std::vector<SameCornerBoundaryRoute>> secondByEndpoints;
  for (const auto &route : firstRoutes) firstByEndpoints[route.endpointIdentity].push_back(route);
  for (const auto &route : secondRoutes) secondByEndpoints[route.endpointIdentity].push_back(route);
  for (auto &[endpoint, routes] : firstByEndpoints) {
    auto secondIt = secondByEndpoints.find(endpoint);
    if (secondIt == secondByEndpoints.end()) continue;
    auto &otherRoutes = secondIt->second;
    const auto routeLess = [](const SameCornerBoundaryRoute &lhs, const SameCornerBoundaryRoute &rhs) {
      return std::tie(lhs.exactIdentity, lhs.geometricIdentity, lhs.patch, lhs.halfedges) < std::tie(rhs.exactIdentity, rhs.geometricIdentity, rhs.patch, rhs.halfedges);
    };
    std::sort(routes.begin(), routes.end(), routeLess);
    std::sort(otherRoutes.begin(), otherRoutes.end(), routeLess);
    if (routes.size() != otherRoutes.size()) { result.incompleteRoute = true; continue; }
    for (std::size_t routeIndex = 0; routeIndex < routes.size(); ++routeIndex) {
      const auto &a = routes[routeIndex];
      const auto &b = otherRoutes[routeIndex];
      if (a.exactIdentity == b.exactIdentity) continue;
      if (a.geometricIdentity == b.geometricIdentity) { result.semanticOverlap = true; continue; }
      const SameCornerBoundaryRoute *selected = &a;
      const SameCornerBoundaryRoute *other = &b;
      if (std::tie(a.geometricIdentity, a.exactIdentity, a.halfedges) < std::tie(b.geometricIdentity, b.exactIdentity, b.halfedges)) { selected = &b; other = &a; }
      std::set<SurfaceCellCanonicalIdentity> otherIntervals(other->boundaryIdentities.begin(), other->boundaryIdentities.end());
      std::vector<std::pair<SurfaceCellCanonicalIdentity, int>> intervals;
      for (std::size_t index = 0; index < selected->boundaryIdentities.size(); ++index) {
        const auto &identity = selected->boundaryIdentities[index];
        if (otherIntervals.count(identity) == 0U) intervals.emplace_back(identity, selected->halfedges[index]);
      }
      std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) { return std::tie(lhs.first, lhs.second) < std::tie(rhs.first, rhs.second); });
      intervals.erase(std::unique(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) { return lhs.second == rhs.second; }), intervals.end());
      if (intervals.empty()) { result.incompleteRoute = true; continue; }
      SameCornerRouteCandidate candidate;
      candidate.hardFeature = a.hardFeature || b.hardFeature;
      candidate.patches = {a.patch, b.patch};
      std::sort(candidate.patches.begin(), candidate.patches.end());
      candidate.patches.erase(std::unique(candidate.patches.begin(), candidate.patches.end()), candidate.patches.end());
      candidate.sharedCornerIdentityHashes = {a.firstCorner.hash(), a.secondCorner.hash()};
      std::sort(candidate.sharedCornerIdentityHashes.begin(), candidate.sharedCornerIdentityHashes.end());
      for (const auto &[identity, halfedge] : intervals) { (void)identity; candidate.halfedges.push_back(halfedge); }
      candidate.identity = endpoint;
      std::array<SurfaceCellCanonicalIdentity, 2> geometricIdentities{a.geometricIdentity, b.geometricIdentity};
      if (geometricIdentities[1] < geometricIdentities[0]) std::swap(geometricIdentities[0], geometricIdentities[1]);
      candidate.identity.values.push_back(2);
      for (const auto &identity : geometricIdentities) append_identity(candidate.identity, identity);
      append_identity(candidate.identity, selected->exactIdentity);
      candidate.identity.values.push_back(static_cast<std::int64_t>(intervals.size()));
      for (const auto &[identity, halfedge] : intervals) { (void)halfedge; append_identity(candidate.identity, identity); }
      result.candidates.push_back(std::move(candidate));
    }
  }
  if (result.candidates.size() > 1U) {
    SameCornerRouteCandidate coupled;
    coupled.priority = 2;
    coupled.identity.valid = true;
    coupled.identity.values = {-1, static_cast<std::int64_t>(result.candidates.size())};
    for (const auto &candidate : result.candidates) {
      coupled.hardFeature = coupled.hardFeature || candidate.hardFeature;
      coupled.patches.insert(coupled.patches.end(), candidate.patches.begin(), candidate.patches.end());
      coupled.halfedges.insert(coupled.halfedges.end(), candidate.halfedges.begin(), candidate.halfedges.end());
      coupled.sharedCornerIdentityHashes.insert(coupled.sharedCornerIdentityHashes.end(), candidate.sharedCornerIdentityHashes.begin(), candidate.sharedCornerIdentityHashes.end());
      append_identity(coupled.identity, candidate.identity);
    }
    std::sort(coupled.patches.begin(), coupled.patches.end());
    coupled.patches.erase(std::unique(coupled.patches.begin(), coupled.patches.end()), coupled.patches.end());
    std::sort(coupled.halfedges.begin(), coupled.halfedges.end());
    coupled.halfedges.erase(std::unique(coupled.halfedges.begin(), coupled.halfedges.end()), coupled.halfedges.end());
    std::sort(coupled.sharedCornerIdentityHashes.begin(), coupled.sharedCornerIdentityHashes.end());
    coupled.sharedCornerIdentityHashes.erase(std::unique(coupled.sharedCornerIdentityHashes.begin(), coupled.sharedCornerIdentityHashes.end()), coupled.sharedCornerIdentityHashes.end());
    result.candidates.push_back(std::move(coupled));
  }
  std::sort(result.candidates.begin(), result.candidates.end());
  result.candidates.erase(std::unique(result.candidates.begin(), result.candidates.end(), [](const auto &lhs, const auto &rhs) { return lhs.identity == rhs.identity; }), result.candidates.end());
  return result;
}

bool same_unordered_conflict_pair(const SurfaceCellOwnershipConflict &conflict,
                                  const int firstPatch,
                                  const int secondPatch) {
  if (!conflict.active()) {
    return false;
  }
  return (conflict.firstPatch == firstPatch &&
          conflict.secondPatch == secondPatch) ||
         (conflict.firstPatch == secondPatch &&
          conflict.secondPatch == firstPatch);
}

void append_repair_identity(SurfaceCellCanonicalIdentity &destination,
                        const SurfaceCellCanonicalIdentity &identity) {
  append_identity(destination, identity);
}

void append_repair_domain_identity(
    SurfaceCellCanonicalIdentity &destination,
    const SurfaceCellDomainIdentity &identity) {
  destination.values.insert(destination.values.end(),
                            {identity.valid ? 1 : 0,
                             identity.boundaryNodeCount,
                             identity.boundaryHalfedgeCount,
                             identity.sourceSupportCount,
                             identity.sourceTopologyRegion.has_value() ? 1 : 0,
                             identity.sourceOwnershipClass.has_value() ? 1 : 0});
  if (identity.sourceTopologyRegion.has_value()) destination.topologyRegions.push_back(identity.sourceTopologyRegion.value());
  if (identity.sourceOwnershipClass.has_value()) destination.ownershipClasses.push_back(identity.sourceOwnershipClass.value());
  append_repair_identity(destination, identity.orientedBoundary);
  append_repair_identity(destination, identity.undirectedBoundary);
  append_repair_identity(destination, identity.sourceSupport);
  append_repair_identity(destination, identity.sourceChartMap);
}

void append_repair_conflict_identity(
    SurfaceCellCanonicalIdentity &destination,
    const SurfaceCellOwnershipConflict &conflict) {
  auto &raw = destination.values;
  raw.push_back(static_cast<int>(conflict.classification));
  const auto ownerIdentity = [&](const bool first) {
    std::vector<std::int64_t> owner;
    owner.push_back(first ? conflict.firstPatch : conflict.secondPatch);
    owner.push_back(first ? conflict.firstLocalQuad : conflict.secondLocalQuad);
    owner.push_back(first ? conflict.firstBoundaryNodeCount : conflict.secondBoundaryNodeCount);
    owner.push_back(first ? conflict.firstBoundaryHalfedgeCount : conflict.secondBoundaryHalfedgeCount);
    owner.push_back(first ? conflict.firstBoundaryVertexCount : conflict.secondBoundaryVertexCount);
    owner.push_back(first ? conflict.firstComponent : conflict.secondComponent);
    owner.push_back(first ? conflict.firstSheet : conflict.secondSheet);
    owner.push_back(first ? conflict.firstCompletionBackend : conflict.secondCompletionBackend);
    owner.push_back(first ? conflict.firstCompletionVariant : conflict.secondCompletionVariant);
    const auto &cornerKinds = first ? conflict.firstCornerIdentityKinds : conflict.secondCornerIdentityKinds;
    const auto &cornerHashes = first ? conflict.firstCornerIdentityHashes : conflict.secondCornerIdentityHashes;
    const auto &authoritativeHashes = first ? conflict.firstCornerAuthoritativeHashes : conflict.secondCornerAuthoritativeHashes;
    for (const int value : cornerKinds) owner.push_back(value);
    for (const std::uint64_t value : cornerHashes) owner.push_back(static_cast<std::int64_t>(value));
    for (const std::uint64_t value : authoritativeHashes) owner.push_back(static_cast<std::int64_t>(value));
    return owner;
  };
  std::array<std::vector<std::int64_t>, 2> owners{ownerIdentity(true), ownerIdentity(false)};
  if (owners[1] < owners[0]) std::swap(owners[0], owners[1]);
  for (const auto &owner : owners) { raw.push_back(static_cast<std::int64_t>(owner.size())); raw.insert(raw.end(), owner.begin(), owner.end()); }
}

using SurfaceCellRepairStateIdentity = SurfaceCellCanonicalIdentity;

SurfaceCellRepairStateIdentity canonical_repair_state_identity(
    const SurfaceCellComplex &complex, const Eigen::MatrixXi &F,
    const std::vector<SurfaceCellOwnershipConflict> &conflicts) {
  SurfaceCellRepairStateIdentity identity;
  identity.valid = true;
  auto &raw = identity.values;
  raw.reserve(complex.nodes.size() * 12U + complex.halfedges.size() * 7U + complex.cells.size() * 16U);
  raw.push_back(static_cast<std::int64_t>(complex.nodes.size()));
  raw.push_back(static_cast<std::int64_t>(complex.halfedges.size()));
  raw.push_back(static_cast<std::int64_t>(complex.cells.size()));
  std::vector<const SurfaceArrangementNode *> nodes;
  nodes.reserve(complex.nodes.size());
  for (const auto &node : complex.nodes) nodes.push_back(&node);
  std::sort(nodes.begin(), nodes.end(), [](const auto *lhs, const auto *rhs) { return lhs->id < rhs->id; });
  for (const auto *node : nodes) {
    raw.insert(raw.end(), {node->id, node->sourceFace, node->sourceEdge, quantized_parameter(node->sourceEdgeParameter), quantized_parameter(node->barycentric(0)), quantized_parameter(node->barycentric(1)), quantized_parameter(node->barycentric(2))});
    append_source_scope(identity, source_scope(*node));
    std::vector<std::array<std::int64_t, 4>> occurrences;
    occurrences.reserve(node->occurrences.size());
    for (const auto &occurrence : node->occurrences) occurrences.push_back({occurrence.sourceFace, quantized_parameter(occurrence.barycentric(0)), quantized_parameter(occurrence.barycentric(1)), quantized_parameter(occurrence.barycentric(2))});
    std::sort(occurrences.begin(), occurrences.end());
    raw.push_back(static_cast<std::int64_t>(occurrences.size()));
    for (const auto &occurrence : occurrences) raw.insert(raw.end(), occurrence.begin(), occurrence.end());
  }
  std::vector<const SurfaceArrangementHalfedge *> halfedges;
  halfedges.reserve(complex.halfedges.size());
  for (const auto &edge : complex.halfedges) halfedges.push_back(&edge);
  std::sort(halfedges.begin(), halfedges.end(), [](const auto *lhs, const auto *rhs) { return lhs->id < rhs->id; });
  for (const auto *edge : halfedges) raw.insert(raw.end(), {edge->id, edge->twin, edge->next, edge->from, edge->to, edge->cell});
  std::vector<const SurfaceArrangementCell *> cells;
  cells.reserve(complex.cells.size());
  for (const auto &cell : complex.cells) cells.push_back(&cell);
  std::sort(cells.begin(), cells.end(), [](const auto *lhs, const auto *rhs) { return lhs->id < rhs->id; });
  for (const auto *cell : cells) {
    std::vector<int> boundary;
    const bool boundaryValid = ordered_boundary(complex, *cell, boundary);
    raw.insert(raw.end(), {cell->id, cell->sourceFace, cell->boundaryCycle ? 1 : 0, cell->closed ? 1 : 0, cell->disk ? 1 : 0, static_cast<int>(cell->cellClass), static_cast<int>(cell->rejectReason), boundaryValid ? 1 : 0});
    std::vector<int> sourceFaces = cell->sourceFaces;
    std::sort(sourceFaces.begin(), sourceFaces.end());
    sourceFaces.erase(std::unique(sourceFaces.begin(), sourceFaces.end()), sourceFaces.end());
    raw.push_back(static_cast<std::int64_t>(sourceFaces.size()));
    raw.insert(raw.end(), sourceFaces.begin(), sourceFaces.end());
    if (boundaryValid) append_repair_domain_identity(identity, build_domain_identity(complex, *cell, boundary, F));
    else { raw.push_back(static_cast<std::int64_t>(cell->halfedges.size())); raw.insert(raw.end(), cell->halfedges.begin(), cell->halfedges.end()); }
  }
  raw.push_back(static_cast<std::int64_t>(conflicts.size()));
  for (const auto &conflict : conflicts) append_repair_conflict_identity(identity, conflict);
  return identity;
}

std::vector<int> affected_patches_for_halfedge(
    const SurfaceCellComplex &complex, const int halfedgeId) {
  std::vector<int> patches;
  if (halfedgeId < 0 ||
      halfedgeId >= static_cast<int>(complex.halfedges.size())) {
    return patches;
  }
  const SurfaceArrangementHalfedge &edge =
      complex.halfedges[static_cast<std::size_t>(halfedgeId)];
  if (edge.cell >= 0) {
    patches.push_back(edge.cell);
  }
  if (edge.twin >= 0 &&
      edge.twin < static_cast<int>(complex.halfedges.size())) {
    const int twinCell = complex.halfedges[static_cast<std::size_t>(edge.twin)].cell;
    if (twinCell >= 0) {
      patches.push_back(twinCell);
    }
  }
  std::sort(patches.begin(), patches.end());
  patches.erase(std::unique(patches.begin(), patches.end()), patches.end());
  return patches;
}


std::vector<int> affected_patches_for_halfedges(
    const SurfaceCellComplex &complex, const std::vector<int> &halfedges) {
  std::vector<int> patches;
  for (const int halfedge : halfedges) {
    std::vector<int> local =
        affected_patches_for_halfedge(complex, halfedge);
    patches.insert(patches.end(), local.begin(), local.end());
  }
  std::sort(patches.begin(), patches.end());
  patches.erase(std::unique(patches.begin(), patches.end()), patches.end());
  return patches;
}

std::uint64_t exact_identity_hash(
    const SurfaceCellCanonicalIdentity &identity) {
  return identity.hash();
}

std::uint64_t logical_complex_payload_bytes(
    const SurfaceCellComplex &complex) {
  std::uint64_t bytes = sizeof(SurfaceCellComplex);
  bytes += static_cast<std::uint64_t>(
               complex.sourceOwnershipRegistry.size()) *
           sizeof(SurfaceCellOwnershipClassRecord);
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    bytes += static_cast<std::uint64_t>(record.exactCharts.size()) *
             sizeof(SourceProjectionChart);
  }
  bytes += static_cast<std::uint64_t>(complex.nodes.size()) *
           sizeof(SurfaceArrangementNode);
  bytes += static_cast<std::uint64_t>(complex.halfedges.size()) *
           sizeof(SurfaceArrangementHalfedge);
  bytes += static_cast<std::uint64_t>(complex.cells.size()) *
           sizeof(SurfaceArrangementCell);
  for (const SurfaceArrangementNode &node : complex.nodes) {
    bytes += static_cast<std::uint64_t>(node.occurrences.size()) *
             sizeof(SurfaceArrangementNodeOccurrence);
  }
  for (const SurfaceArrangementHalfedge &edge : complex.halfedges) {
    bytes += static_cast<std::uint64_t>(edge.provenance.size()) *
             sizeof(SurfaceArrangementProvenance);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    bytes += static_cast<std::uint64_t>(cell.sourceCharts.size()) *
             sizeof(SourceProjectionChart);
    bytes += static_cast<std::uint64_t>(cell.sourceFaces.size()) * sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.halfedges.size()) * sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.sideFamilies.size()) * sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.sideEdgeCounts.size()) *
             sizeof(int);
  }
  return bytes;
}

std::uint64_t estimated_complex_owned_bytes(
    const SurfaceCellComplex &complex) {
  std::uint64_t bytes = sizeof(SurfaceCellComplex);
  bytes += static_cast<std::uint64_t>(
               complex.sourceOwnershipRegistry.capacity()) *
           sizeof(SurfaceCellOwnershipClassRecord);
  for (const SurfaceCellOwnershipClassRecord &record :
       complex.sourceOwnershipRegistry) {
    bytes += static_cast<std::uint64_t>(record.exactCharts.capacity()) *
             sizeof(SourceProjectionChart);
  }
  bytes += static_cast<std::uint64_t>(complex.nodes.capacity()) *
           sizeof(SurfaceArrangementNode);
  bytes += static_cast<std::uint64_t>(complex.halfedges.capacity()) *
           sizeof(SurfaceArrangementHalfedge);
  bytes += static_cast<std::uint64_t>(complex.cells.capacity()) *
           sizeof(SurfaceArrangementCell);
  for (const SurfaceArrangementNode &node : complex.nodes) {
    bytes += static_cast<std::uint64_t>(node.occurrences.capacity()) *
             sizeof(SurfaceArrangementNodeOccurrence);
  }
  for (const SurfaceArrangementHalfedge &edge : complex.halfedges) {
    bytes += static_cast<std::uint64_t>(edge.provenance.capacity()) *
             sizeof(SurfaceArrangementProvenance);
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    bytes += static_cast<std::uint64_t>(cell.sourceCharts.capacity()) *
             sizeof(SourceProjectionChart);
    bytes += static_cast<std::uint64_t>(cell.sourceFaces.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.halfedges.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(
                 cell.boundaryCycleOffsets.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(
                 cell.sourceBoundaryLoopIds.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.sideFamilies.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.sideEdgeCounts.capacity()) *
             sizeof(int);
  }
  return bytes;
}

std::uint64_t logical_descriptor_payload_bytes(
    const PatchDescriptor &descriptor) {
  std::uint64_t bytes = 0U;
  bytes += static_cast<std::uint64_t>(descriptor.sides.size()) *
           sizeof(PatchSideDescriptor);
  bytes += static_cast<std::uint64_t>(descriptor.singularSourceVertices.size()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(descriptor.singularNumerators.size()) *
           sizeof(int);
  for (const PatchSideDescriptor &side : descriptor.sides) {
    bytes += static_cast<std::uint64_t>(side.halfedges.size()) * sizeof(int);
    bytes += static_cast<std::uint64_t>(side.boundaryVertices.size()) *
             sizeof(int);
  }
  const PureQuadPatch &patch = descriptor.patch;
  bytes += static_cast<std::uint64_t>(patch.sideEdgeCounts.size()) * sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.turns.size()) * sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.boundaryVertices.size()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.boundaryProvenance.size()) *
           sizeof(SurfacePoint);
  bytes += static_cast<std::uint64_t>(patch.boundaryRailIds.size()) * sizeof(std::optional<authority::HardRailId>);
  bytes += static_cast<std::uint64_t>(patch.boundaryCurveIds.size()) * sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.sourceFaces.size()) * sizeof(int);
  return bytes;
}

std::uint64_t estimated_descriptor_payload_owned_bytes(
    const PatchDescriptor &descriptor) {
  std::uint64_t bytes = 0U;
  bytes += static_cast<std::uint64_t>(descriptor.sides.capacity()) *
           sizeof(PatchSideDescriptor);
  bytes += static_cast<std::uint64_t>(
               descriptor.singularSourceVertices.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(
               descriptor.singularNumerators.capacity()) *
           sizeof(int);
  for (const PatchSideDescriptor &side : descriptor.sides) {
    bytes += static_cast<std::uint64_t>(side.halfedges.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(side.boundaryVertices.capacity()) *
             sizeof(int);
  }
  const PureQuadPatch &patch = descriptor.patch;
  bytes += static_cast<std::uint64_t>(patch.sideEdgeCounts.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.turns.capacity()) * sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.boundaryVertices.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.boundaryProvenance.capacity()) *
           sizeof(SurfacePoint);
  bytes += static_cast<std::uint64_t>(patch.boundaryRailIds.capacity()) *
           sizeof(std::optional<authority::HardRailId>);
  bytes += static_cast<std::uint64_t>(patch.boundaryCurveIds.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.sourceFaces.capacity()) *
           sizeof(int);
  return bytes;
}

std::uint64_t logical_descriptor_bytes(
    const PatchDescriptorSet &descriptors) {
  std::uint64_t bytes = sizeof(PatchDescriptorSet);
  bytes += static_cast<std::uint64_t>(descriptors.descriptors.size()) *
           sizeof(PatchDescriptor);
  bytes += static_cast<std::uint64_t>(
               descriptors.unresolvedSingularVertices.size()) * sizeof(int);
  for (const PatchDescriptor &descriptor : descriptors.descriptors) {
    bytes += logical_descriptor_payload_bytes(descriptor);
  }
  return bytes;
}

std::uint64_t estimated_descriptor_owned_bytes(
    const PatchDescriptorSet &descriptors) {
  std::uint64_t bytes = sizeof(PatchDescriptorSet);
  bytes += static_cast<std::uint64_t>(descriptors.descriptors.capacity()) *
           sizeof(PatchDescriptor);
  bytes += static_cast<std::uint64_t>(
               descriptors.unresolvedSingularVertices.capacity()) *
           sizeof(int);
  for (const PatchDescriptor &descriptor : descriptors.descriptors) {
    bytes += estimated_descriptor_payload_owned_bytes(descriptor);
  }
  return bytes;
}

std::uint64_t logical_mesh_payload_bytes(const PureQuadMesh &mesh) {
  std::uint64_t bytes = sizeof(PureQuadMesh);
  bytes += static_cast<std::uint64_t>(mesh.vertices.size()) * sizeof(int);
  bytes += static_cast<std::uint64_t>(mesh.vertexPositions.size()) *
           sizeof(double);
  bytes += static_cast<std::uint64_t>(mesh.vertexProvenance.size()) *
           sizeof(SurfacePoint);
  bytes += static_cast<std::uint64_t>(mesh.quads.size()) *
           sizeof(std::vector<int>);
  for (const auto &quad : mesh.quads) {
    bytes += static_cast<std::uint64_t>(quad.size()) * sizeof(int);
  }
  bytes += static_cast<std::uint64_t>(mesh.boundaryVertices.size()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(mesh.boundaryLoops.size()) *
           sizeof(std::vector<int>);
  for (const auto &loop : mesh.boundaryLoops) {
    bytes += static_cast<std::uint64_t>(loop.size()) * sizeof(int);
  }
  bytes += static_cast<std::uint64_t>(mesh.sourceSideEdgeCounts.size()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(mesh.vertexLineage.size()) *
           sizeof(PureQuadVertexLineage);
  bytes += static_cast<std::uint64_t>(mesh.quadLineage.size()) *
           sizeof(PureQuadFaceLineage);
  return bytes;
}

std::uint64_t estimated_mesh_owned_bytes(const PureQuadMesh &mesh) {
  std::uint64_t bytes = sizeof(PureQuadMesh);
  bytes += static_cast<std::uint64_t>(mesh.vertices.capacity()) * sizeof(int);
  bytes += static_cast<std::uint64_t>(mesh.vertexPositions.size()) *
           sizeof(double);
  bytes += static_cast<std::uint64_t>(mesh.vertexProvenance.capacity()) *
           sizeof(SurfacePoint);
  bytes += static_cast<std::uint64_t>(mesh.quads.capacity()) *
           sizeof(std::vector<int>);
  for (const auto &quad : mesh.quads) {
    bytes += static_cast<std::uint64_t>(quad.capacity()) * sizeof(int);
  }
  bytes += static_cast<std::uint64_t>(mesh.boundaryVertices.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(mesh.boundaryLoops.capacity()) *
           sizeof(std::vector<int>);
  for (const auto &loop : mesh.boundaryLoops) {
    bytes += static_cast<std::uint64_t>(loop.capacity()) * sizeof(int);
  }
  bytes += static_cast<std::uint64_t>(mesh.sourceSideEdgeCounts.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(mesh.vertexLineage.capacity()) *
           sizeof(PureQuadVertexLineage);
  bytes += static_cast<std::uint64_t>(mesh.quadLineage.capacity()) *
           sizeof(PureQuadFaceLineage);
  return bytes;
}

std::uint64_t logical_completed_patches_bytes(
    const std::vector<PureQuadMesh> &patches) {
  std::uint64_t bytes =
      static_cast<std::uint64_t>(patches.size()) * sizeof(PureQuadMesh);
  for (const PureQuadMesh &patch : patches) {
    bytes += logical_mesh_payload_bytes(patch);
  }
  return bytes;
}

std::uint64_t estimated_completed_patches_owned_bytes(
    const std::vector<PureQuadMesh> &patches) {
  std::uint64_t bytes =
      static_cast<std::uint64_t>(patches.capacity()) * sizeof(PureQuadMesh);
  for (const PureQuadMesh &patch : patches) {
    bytes += estimated_mesh_owned_bytes(patch);
  }
  return bytes;
}

void release_rejected_completion_storage(
    SurfaceCellComplexCompletionDraft &result) {
  result.completedPatches.clear();
  result.completedPatches.shrink_to_fit();
  // Preserve compact authoritative descriptors and their typed diagnostics on
  // failure. They are required to identify the responsible stage and are
  // released by production pipeline ownership after result transfer.
  result.preparedComplex = {};
  result.assembly.mesh = {};
}

void renumber_ownership_repair_attempts(
    std::vector<SurfaceCellOwnershipRepairAttempt> &attempts) {
  for (int index = 0; index < static_cast<int>(attempts.size()); ++index) {
    attempts[static_cast<std::size_t>(index)].ordinal = index;
  }
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry {

SurfaceCellDomainIdentityAudit audit_surface_cell_domain_identity(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::vector<int> &boundary, const Eigen::MatrixXi &F) {
  return patch_descriptor_detail::build_domain_identity_audit(
      complex, cell, boundary, F);
}

PatchDescriptor derive_patch_descriptor(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const PatchDescriptorOptions &options) {
  PatchDescriptor descriptor;
  descriptor.cellId = cell.id;
  PureQuadPatch &patch = descriptor.patch;
  patch.diskTopology = cell.disk && cell.eulerCharacteristic == 1;
  patch.boundaryLoopCount = cell.boundaryComponentCount;
  patch.sourceFaces = cell.sourceFaces;
  if (patch.sourceFaces.empty() && cell.sourceFace >= 0) {
    patch.sourceFaces.push_back(cell.sourceFace);
  }
  patch.simple = true;

  std::vector<int> boundary;
  descriptor.boundaryCycleValid =
      patch_descriptor_detail::ordered_boundary(complex, cell, boundary);
  if (!descriptor.boundaryCycleValid) {
    patch.diskTopology = false;
    descriptor.domainIdentityAudit =
        patch_descriptor_detail::build_domain_identity_audit(
            complex, cell, cell.halfedges, F);
    if (descriptor.domainIdentityAudit.failure ==
        SurfaceCellDomainIdentityFailureKind::None) {
      descriptor.domainIdentityAudit.cellId = cell.id;
      descriptor.domainIdentityAudit.failure =
          SurfaceCellDomainIdentityFailureKind::NonSimpleBoundary;
    }
    descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
    return descriptor;
  }

  descriptor.sides =
      patch_descriptor_detail::extract_sides(complex, cell, boundary, V, F);
  patch.sideEdgeCounts.reserve(descriptor.sides.size());
  patch.turns.reserve(descriptor.sides.size());
  for (const PatchSideDescriptor &side : descriptor.sides) {
    patch.sideEdgeCounts.push_back(side.subdivisionCount);
    // Arrangement families encode the two orthogonal cross directions. A
    // change of family is one quarter turn; the cell orientation determines
    // its sign. Straight runs were merged into the same side above.
    patch.turns.push_back(1);
  }

  std::set<int> boundarySourceVertices;
  for (const int id : boundary) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    const SurfaceArrangementNode *node =
        patch_descriptor_detail::find_node(complex, edge.from);
    if (node == nullptr) {
      patch.diskTopology = false;
      descriptor.boundaryCycleValid = false;
      descriptor.domainIdentityAudit =
          patch_descriptor_detail::build_domain_identity_audit(
              complex, cell, boundary, F);
      if (descriptor.domainIdentityAudit.failure ==
          SurfaceCellDomainIdentityFailureKind::None) {
        descriptor.domainIdentityAudit.cellId = cell.id;
        descriptor.domainIdentityAudit.nodeId = edge.from;
        descriptor.domainIdentityAudit.failure =
            SurfaceCellDomainIdentityFailureKind::InvalidEndpointNode;
      }
      descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
      return descriptor;
    }
    patch.boundaryVertices.push_back(node->id);
    patch.boundaryRailIds.push_back(edge.railId);
    patch.boundaryCurveIds.push_back(edge.curveId);
    if (!edge.sourceTopologyRegion.has_value() || !edge.sourceChart.has_value()) {
      patch.diskTopology = false;
      descriptor.boundaryCycleValid = false;
      descriptor.domainIdentityAudit.cellId = cell.id;
      descriptor.domainIdentityAudit.halfedgeId = edge.id;
      descriptor.domainIdentityAudit.failure =
          SurfaceCellDomainIdentityFailureKind::MissingSourceChart;
      descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
      return descriptor;
    }
    patch.boundaryTopologyRegions.push_back(edge.sourceTopologyRegion.value());
    patch.boundaryCharts.push_back(edge.sourceChart.value());
    patch.boundaryNodeIdentities.push_back(
        patch_descriptor_detail::arrangement_node_identity(
            *node, F, patch_descriptor_detail::source_scope(edge)));
    patch.boundaryProvenance.push_back(
        patch_descriptor_detail::node_surface_point(*node, V, F, edge));
    patch.hardFeatureCrossing =
        patch.hardFeatureCrossing || node->hardBarrierCrossing;
    const int sourceVertex = patch_descriptor_detail::source_vertex_at_node(
        *node, F, options.barycentricTolerance);
    if (sourceVertex >= 0) {
      boundarySourceVertices.insert(sourceVertex);
    }
  }

  descriptor.domainIdentityAudit =
      patch_descriptor_detail::build_domain_identity_audit(
          complex, cell, boundary, F);
  patch.domainIdentity = descriptor.domainIdentityAudit.identity;
  descriptor.featureConstraintsValid = !patch.hardFeatureCrossing;
  const int singularCount =
      std::min(options.singularCycles.size(), options.singularIndices.size());
  for (int i = 0; i < singularCount; ++i) {
    const int sourceVertex = options.singularCycles(i);
    if (options.enforceGlobalSingularityOwnership) {
      if (options.embeddedSingularVertices.count(sourceVertex) != 0U) {
        continue;
      }
      const auto owner = options.interiorSingularityOwner.find(sourceVertex);
      if (owner == options.interiorSingularityOwner.end() ||
          owner->second != cell.id) {
        continue;
      }
    } else {
      if (!patch_descriptor_detail::source_vertex_is_in_cell(sourceVertex,
                                                              cell, F)) {
        continue;
      }
    }
    if (boundarySourceVertices.count(sourceVertex) != 0) {
      // Boundary singularities are represented by adjacent patches and do not
      // consume an interior irregular vertex in this patch.
      continue;
    }
    descriptor.singularSourceVertices.push_back(sourceVertex);
    descriptor.singularNumerators.push_back(options.singularIndices(i));
  }
  patch.singularityCount =
      static_cast<int>(descriptor.singularNumerators.size());
  patch.unmatchedInteriorSingularity = patch.singularityCount > 1;
  patch.singularIndexNumerator =
      patch.singularityCount == 1 ? descriptor.singularNumerators.front() : 0;

  descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
  return descriptor;
}

} // namespace directional::geometry

namespace directional::geometry {

PatchDescriptorSet derive_patch_descriptors(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F, const PatchDescriptorOptions &options) {
  PatchDescriptorSet result;
  result.descriptors.reserve(complex.cells.size());
  PatchDescriptorOptions resolvedOptions = options;
  resolvedOptions.enforceGlobalSingularityOwnership = true;
  const int singularCount =
      std::min(options.singularCycles.size(), options.singularIndices.size());
  std::set<int> singularVertices;
  for (int singular = 0; singular < singularCount; ++singular) {
    singularVertices.insert(options.singularCycles(singular));
  }
  for (const SurfaceArrangementNode &node : complex.nodes) {
    const int sourceVertex = patch_descriptor_detail::source_vertex_at_node(
        node, F, options.barycentricTolerance);
    if (singularVertices.count(sourceVertex) != 0U) {
      resolvedOptions.embeddedSingularVertices.insert(sourceVertex);
    }
  }
  for (const int sourceVertex : singularVertices) {
    if (resolvedOptions.embeddedSingularVertices.count(sourceVertex) != 0U) {
      continue;
    }
    std::vector<int> candidates;
    for (const SurfaceArrangementCell &cell : complex.cells) {
      if (cell.cellClass == SurfaceArrangementCellClass::Exterior) {
        continue;
      }
      if (patch_descriptor_detail::source_vertex_is_in_cell(sourceVertex, cell,
                                                             F)) {
        candidates.push_back(cell.id);
      }
    }
    if (candidates.size() == 1U) {
      resolvedOptions.interiorSingularityOwner.emplace(sourceVertex,
                                                       candidates.front());
    } else {
      result.unresolvedSingularVertices.push_back(sourceVertex);
    }
  }
  for (const SurfaceArrangementCell &cell : complex.cells) {
    // Exterior DCEL cycles describe the unbounded side of each connected
    // arrangement component. They are not authoritative surface patches and
    // must not participate in completion completeness checks.
    if (cell.cellClass == SurfaceArrangementCellClass::Exterior) {
      continue;
    }
    PatchDescriptor descriptor =
        derive_patch_descriptor(complex, cell, V, F, resolvedOptions);
    if (!descriptor.domainIdentityAudit.valid &&
        result.firstInvalidDomain.failure ==
            SurfaceCellDomainIdentityFailureKind::None) {
      result.firstInvalidDomain = descriptor.domainIdentityAudit;
    }
    if (descriptor.feasibility.admissible) {
      ++result.feasible;
    } else {
      ++result.rejected;
    }
    result.descriptors.push_back(std::move(descriptor));
  }

  patch_descriptor_detail::compact_patch_ownership_identities(
      result.descriptors);

  std::sort(result.descriptors.begin(), result.descriptors.end(),
            [](const PatchDescriptor &lhs, const PatchDescriptor &rhs) {
              if (lhs.patch.domainIdentity < rhs.patch.domainIdentity) {
                return true;
              }
              if (rhs.patch.domainIdentity < lhs.patch.domainIdentity) {
                return false;
              }
              return lhs.cellId < rhs.cellId;
            });

  std::map<SurfaceCellDomainIdentity, int> orientedOwner;
  using UndirectedOwnerKey =
      std::tuple<std::optional<authority::TopologyRegionId>,
                 std::optional<authority::SurfaceCellOwnershipClassId>,
                 SurfaceCellCanonicalIdentity, SurfaceCellCanonicalIdentity>;
  std::map<UndirectedOwnerKey, int> undirectedOwner;
  for (int descriptorIndex = 0;
       descriptorIndex < static_cast<int>(result.descriptors.size());
       ++descriptorIndex) {
    const PatchDescriptor &descriptor =
        result.descriptors[static_cast<std::size_t>(descriptorIndex)];
    const SurfaceCellDomainIdentity &identity = descriptor.patch.domainIdentity;
    if (!identity.valid) {
      result.ownershipConflict.classification =
          SurfaceCellOwnershipConflictClass::InvalidDomainIdentity;
      result.ownershipConflict.firstPatch = descriptor.cellId;
      result.ownershipConflict.firstDomainHash = identity.hash();
      break;
    }
    const auto [oriented, inserted] =
        orientedOwner.emplace(identity, descriptorIndex);
    if (!inserted) {
      const PatchDescriptor &first = result.descriptors[
          static_cast<std::size_t>(oriented->second)];
      result.ownershipConflict.classification =
          SurfaceCellOwnershipConflictClass::DuplicateOrientedDomain;
      result.ownershipConflict.firstPatch = first.cellId;
      result.ownershipConflict.secondPatch = descriptor.cellId;
      result.ownershipConflict.firstDomainHash = first.patch.domainIdentity.hash();
      result.ownershipConflict.secondDomainHash = identity.hash();
      result.ownershipConflict.firstBoundaryNodeHash =
          first.patch.domainIdentity.orientedBoundary.hash();
      result.ownershipConflict.secondBoundaryNodeHash =
          identity.orientedBoundary.hash();
      result.ownershipConflict.firstBoundaryHalfedgeHash =
          first.patch.domainIdentity.undirectedBoundary.hash();
      result.ownershipConflict.secondBoundaryHalfedgeHash =
          identity.undirectedBoundary.hash();
      result.ownershipConflict.firstSourceSupportHash =
          first.patch.domainIdentity.sourceSupport.hash();
      result.ownershipConflict.secondSourceSupportHash =
          identity.sourceSupport.hash();
      result.ownershipConflict.firstSourceSupportCount =
          first.patch.domainIdentity.sourceSupportCount;
      result.ownershipConflict.secondSourceSupportCount =
          identity.sourceSupportCount;
      result.ownershipConflict.firstComponent = -1;
      result.ownershipConflict.firstSheet = -1;
      result.ownershipConflict.secondComponent = -1;
      result.ownershipConflict.secondSheet = -1;
      break;
    }

    const UndirectedOwnerKey key{
        identity.sourceTopologyRegion, identity.sourceOwnershipClass,
        identity.sourceSupport, identity.undirectedBoundary};
    const auto [undirected, undirectedInserted] =
        undirectedOwner.emplace(key, descriptorIndex);
    if (!undirectedInserted) {
      const PatchDescriptor &first = result.descriptors[
          static_cast<std::size_t>(undirected->second)];
      result.ownershipConflict.classification =
          SurfaceCellOwnershipConflictClass::OverlappingUndirectedBoundary;
      result.ownershipConflict.firstPatch = first.cellId;
      result.ownershipConflict.secondPatch = descriptor.cellId;
      result.ownershipConflict.firstDomainHash = first.patch.domainIdentity.hash();
      result.ownershipConflict.secondDomainHash = identity.hash();
      result.ownershipConflict.firstBoundaryHalfedgeHash =
          first.patch.domainIdentity.undirectedBoundary.hash();
      result.ownershipConflict.secondBoundaryHalfedgeHash =
          identity.undirectedBoundary.hash();
      result.ownershipConflict.firstSourceSupportHash =
          first.patch.domainIdentity.sourceSupport.hash();
      result.ownershipConflict.secondSourceSupportHash =
          identity.sourceSupport.hash();
      result.ownershipConflict.firstSourceSupportCount =
          first.patch.domainIdentity.sourceSupportCount;
      result.ownershipConflict.secondSourceSupportCount =
          identity.sourceSupportCount;
      result.ownershipConflict.firstComponent = -1;
      result.ownershipConflict.firstSheet = -1;
      result.ownershipConflict.secondComponent = -1;
      result.ownershipConflict.secondSheet = -1;
      break;
    }
  }
  return result;
}

} // namespace directional::geometry

namespace directional::geometry::patch_descriptor_detail {

using PatchCompletionDependencyIdentity = SurfaceCellCanonicalIdentity;

void append_completion_dependency_values(
    PatchCompletionDependencyIdentity &identity,
    const std::vector<int> &values) {
  identity.valid = true;
  identity.values.push_back(static_cast<std::int64_t>(values.size()));
  for (const int value : values) identity.values.push_back(value);
}

void append_completion_dependency_set(
    PatchCompletionDependencyIdentity &identity,
    const std::set<int> &values) {
  identity.valid = true;
  identity.values.push_back(static_cast<std::int64_t>(values.size()));
  for (const int value : values) identity.values.push_back(value);
}

void append_completion_dependency_set(
    PatchCompletionDependencyIdentity &identity,
    const std::set<authority::HardRailId> &values) {
  identity.valid = true;
  identity.values.push_back(static_cast<std::int64_t>(values.size()));
  identity.hardRails.insert(identity.hardRails.end(), values.begin(), values.end());
}

int completion_dependency_label(const std::vector<int> &values,
                                const std::size_t index) {
  return index < values.size() ? values[index] : -1;
}

void append_completion_dependency_rail(
    PatchCompletionDependencyIdentity &identity,
    const std::vector<std::optional<authority::HardRailId>> &values,
    const std::size_t index) {
  const bool present = index < values.size() && values[index].has_value();
  identity.values.push_back(present ? 1 : 0);
  if (present) identity.hardRails.push_back(values[index].value());
}

void append_completion_dependency_point(
    PatchCompletionDependencyIdentity &identity, const PureQuadPatch &patch,
    const std::size_t index) {
  identity.valid = true;
  if (index >= patch.boundaryProvenance.size() ||
      index >= patch.boundaryTopologyRegions.size() ||
      index >= patch.boundaryCharts.size()) {
    identity.values.push_back(-1);
    return;
  }
  const SurfacePoint &point = patch.boundaryProvenance[index];
  const authority::TopologyRegionId region =
      patch.boundaryTopologyRegions[index];
  const SourceProjectionChart &chart = patch.boundaryCharts[index];
  identity.values.push_back(1);
  identity.topologyRegions.push_back(region);
  identity.sourceCharts.push_back({chart.chart, chart.face});
  for (int coordinate = 0; coordinate < 3; ++coordinate) {
    identity.values.push_back(
        quantized_parameter(point.barycentric(coordinate)));
  }
  append_completion_dependency_rail(identity, patch.boundaryRailIds, index);
  identity.values.push_back(
      completion_dependency_label(patch.boundaryCurveIds, index));
}

PatchCompletionDependencyIdentity completion_dependency_side_record(
    const PatchDescriptor &descriptor,
    const std::vector<std::size_t> &offsets, const int sideIndex,
    const bool reversed) {
  PatchCompletionDependencyIdentity record;
  record.valid = true;
  const PatchSideDescriptor &side =
      descriptor.sides[static_cast<std::size_t>(sideIndex)];
  const PureQuadPatch &patch = descriptor.patch;
  const int count = patch.sideEdgeCounts[static_cast<std::size_t>(sideIndex)];
  record.values.insert(record.values.end(),
                       {side.family,
                        static_cast<std::int64_t>(side.halfedges.size()),
                        static_cast<std::int64_t>(side.boundaryVertices.size()),
                        side.subdivisionCount,
                        side.hardFeature ? 1 : 0,
                        count});
  const int turn = sideIndex < static_cast<int>(patch.turns.size())
                       ? patch.turns[static_cast<std::size_t>(sideIndex)]
                       : 0;
  record.values.push_back(reversed ? -turn : turn);
  append_completion_dependency_set(record, side.railIds);
  append_completion_dependency_set(record, side.curveIds);
  record.values.push_back(count);
  for (int local = 0; local < count; ++local) {
    const int orientedLocal = reversed ? count - local - 1 : local;
    PatchCompletionDependencyIdentity point;
    append_completion_dependency_point(
        point, patch,
        offsets[static_cast<std::size_t>(sideIndex)] +
            static_cast<std::size_t>(orientedLocal));
    append_identity(record, point);
  }
  return record;
}

PatchCompletionDependencyIdentity canonical_side_subdivision_dependency(
    const PatchDescriptor &descriptor) {
  const PureQuadPatch &patch = descriptor.patch;
  const int sideCount = static_cast<int>(descriptor.sides.size());
  PatchCompletionDependencyIdentity invalid;
  if (sideCount <= 0 || patch.sideEdgeCounts.size() != descriptor.sides.size()) {
    invalid.valid = true;
    invalid.values = {-1};
    return invalid;
  }
  PatchCompletionDependencyIdentity canonical;
  bool initialized = false;
  for (const bool reversed : {false, true}) {
    for (int startSide = 0; startSide < sideCount; ++startSide) {
      PatchCompletionDependencyIdentity candidate;
      candidate.valid = true;
      candidate.values.push_back(sideCount);
      for (int step = 0; step < sideCount; ++step) {
        const int sideIndex = reversed
            ? (startSide - step + sideCount) % sideCount
            : (startSide + step) % sideCount;
        const PatchSideDescriptor &side =
            descriptor.sides[static_cast<std::size_t>(sideIndex)];
        const int turn = sideIndex < static_cast<int>(patch.turns.size())
                             ? patch.turns[static_cast<std::size_t>(sideIndex)]
                             : 0;
        candidate.values.insert(
            candidate.values.end(),
            {side.family, side.subdivisionCount,
             static_cast<std::int64_t>(side.halfedges.size()),
             static_cast<std::int64_t>(side.boundaryVertices.size()),
             side.hardFeature ? 1 : 0,
             patch.sideEdgeCounts[static_cast<std::size_t>(sideIndex)],
             reversed ? -turn : turn});
      }
      if (!initialized || candidate < canonical) {
        canonical = std::move(candidate);
        initialized = true;
      }
    }
  }
  return canonical;
}

PatchCompletionDependencyIdentity canonical_completion_boundary_dependency(
    const PatchDescriptor &descriptor) {
  const PureQuadPatch &patch = descriptor.patch;
  const int sideCount = static_cast<int>(descriptor.sides.size());
  bool metadataValid =
      sideCount > 0 && patch.sideEdgeCounts.size() == descriptor.sides.size();
  std::vector<std::size_t> offsets(
      static_cast<std::size_t>(std::max(sideCount, 0)) + 1U, 0U);
  if (metadataValid) {
    for (int side = 0; side < sideCount; ++side) {
      const int count = patch.sideEdgeCounts[static_cast<std::size_t>(side)];
      if (count < 0) { metadataValid = false; break; }
      offsets[static_cast<std::size_t>(side + 1)] =
          offsets[static_cast<std::size_t>(side)] +
          static_cast<std::size_t>(count);
    }
    metadataValid = metadataValid &&
                    offsets.back() == patch.boundaryProvenance.size();
  }

  if (!metadataValid) {
    PatchCompletionDependencyIdentity fallback;
    fallback.valid = true;
    fallback.values = {-1,
        static_cast<std::int64_t>(patch.boundaryProvenance.size())};
    for (std::size_t index = 0; index < patch.boundaryProvenance.size(); ++index) {
      PatchCompletionDependencyIdentity point;
      append_completion_dependency_point(point, patch, index);
      append_identity(fallback, point);
    }
    append_completion_dependency_values(fallback, patch.sideEdgeCounts);
    append_completion_dependency_values(fallback, patch.turns);
    return fallback;
  }

  PatchCompletionDependencyIdentity canonical;
  bool initialized = false;
  for (const bool reversed : {false, true}) {
    for (int startSide = 0; startSide < sideCount; ++startSide) {
      PatchCompletionDependencyIdentity candidate;
      candidate.valid = true;
      candidate.values.push_back(sideCount);
      for (int step = 0; step < sideCount; ++step) {
        const int sideIndex = reversed
            ? (startSide - step + sideCount) % sideCount
            : (startSide + step) % sideCount;
        PatchCompletionDependencyIdentity record =
            completion_dependency_side_record(
                descriptor, offsets, sideIndex, reversed);
        append_identity(candidate, record);
      }
      if (!initialized || candidate < canonical) {
        canonical = std::move(candidate);
        initialized = true;
      }
    }
  }
  return canonical;
}

struct PatchCompletionDependencyFields {
  PatchCompletionDependencyIdentity sourceDomain;
  PatchCompletionDependencyIdentity sideSubdivision;
  PatchCompletionDependencyIdentity boundarySourceCoordinates;
  PatchCompletionDependencyIdentity railCurveSupport;
  PatchCompletionDependencyIdentity singularityRequirements;
  PatchCompletionDependencyIdentity topologyTemplate;
  int backend = -1;
  int variant = -1;
};

PatchCompletionDependencyFields completion_dependency_fields(
    const PatchDescriptor &descriptor, const PureQuadMesh *mesh = nullptr) {
  PatchCompletionDependencyFields fields;
  const PureQuadPatch &patch = descriptor.patch;

  fields.sourceDomain.valid = true;
  fields.sourceDomain.values = {
      patch.domainIdentity.valid ? 1 : 0,
      patch.domainIdentity.boundaryNodeCount,
      patch.domainIdentity.boundaryHalfedgeCount,
      patch.domainIdentity.sourceSupportCount,
      patch.domainIdentity.sourceTopologyRegion.has_value() ? 1 : 0,
      patch.domainIdentity.sourceOwnershipClass.has_value() ? 1 : 0};
  if (patch.domainIdentity.sourceTopologyRegion.has_value()) {
    fields.sourceDomain.topologyRegions.push_back(
        patch.domainIdentity.sourceTopologyRegion.value());
  }
  if (patch.domainIdentity.sourceOwnershipClass.has_value()) {
    fields.sourceDomain.ownershipClasses.push_back(
        patch.domainIdentity.sourceOwnershipClass.value());
  }
  append_identity(fields.sourceDomain, patch.domainIdentity.sourceSupport);
  append_identity(fields.sourceDomain, patch.domainIdentity.sourceChartMap);

  fields.sideSubdivision =
      canonical_side_subdivision_dependency(descriptor);
  fields.boundarySourceCoordinates =
      canonical_completion_boundary_dependency(descriptor);

  fields.railCurveSupport.valid = true;
  std::set<authority::HardRailId> railIds;
  std::set<int> curveIds;
  for (const auto rail : patch.boundaryRailIds) {
    if (rail.has_value()) railIds.insert(rail.value());
  }
  for (const int curve : patch.boundaryCurveIds) {
    if (curve >= 0) curveIds.insert(curve);
  }
  for (const PatchSideDescriptor &side : descriptor.sides) {
    railIds.insert(side.railIds.begin(), side.railIds.end());
    curveIds.insert(side.curveIds.begin(), side.curveIds.end());
  }
  append_completion_dependency_set(fields.railCurveSupport, railIds);
  append_completion_dependency_set(fields.railCurveSupport, curveIds);

  fields.singularityRequirements.valid = true;
  std::vector<std::pair<int, int>> singularities;
  const std::size_t singularityCount = std::max(
      descriptor.singularSourceVertices.size(),
      descriptor.singularNumerators.size());
  singularities.reserve(singularityCount);
  for (std::size_t index = 0; index < singularityCount; ++index) {
    singularities.emplace_back(
        index < descriptor.singularSourceVertices.size()
            ? descriptor.singularSourceVertices[index] : -1,
        index < descriptor.singularNumerators.size()
            ? descriptor.singularNumerators[index] : 0);
  }
  std::sort(singularities.begin(), singularities.end());
  fields.singularityRequirements.values.push_back(
      static_cast<std::int64_t>(singularities.size()));
  for (const auto &[sourceVertex, numerator] : singularities) {
    fields.singularityRequirements.values.push_back(sourceVertex);
    fields.singularityRequirements.values.push_back(numerator);
  }
  fields.singularityRequirements.values.insert(
      fields.singularityRequirements.values.end(),
      {patch.singularityCount, patch.singularIndexNumerator,
       patch.unmatchedInteriorSingularity ? 1 : 0});

  fields.topologyTemplate.valid = true;
  fields.topologyTemplate.values = {
      descriptor.feasibility.admissible ? 1 : 0,
      static_cast<int>(descriptor.feasibility.reason),
      descriptor.feasibility.expectedInteriorValence,
      descriptor.boundaryCycleValid ? 1 : 0,
      descriptor.featureConstraintsValid ? 1 : 0,
      patch.boundaryLoopCount, patch.diskTopology ? 1 : 0,
      patch.hardFeatureCrossing ? 1 : 0, patch.simple ? 1 : 0};
  const bool rectangular = patch.sideEdgeCounts.size() == 4U &&
                           patch.sideEdgeCounts[0] > 0 &&
                           patch.sideEdgeCounts[1] > 0 &&
                           patch.sideEdgeCounts[0] == patch.sideEdgeCounts[2] &&
                           patch.sideEdgeCounts[1] == patch.sideEdgeCounts[3];
  if (patch.singularityCount != 0) {
    fields.backend = static_cast<int>(PureQuadCompletionBackend::PoleTemplate);
  } else if (rectangular) {
    fields.backend = static_cast<int>(PureQuadCompletionBackend::ClosedForm);
  } else if (patch.boundaryVertices.size() == 6U) {
    fields.backend = static_cast<int>(PureQuadCompletionBackend::TransitionTemplate);
  } else if (patch.simple) {
    fields.backend = static_cast<int>(PureQuadCompletionBackend::Pattern);
  } else {
    fields.backend = static_cast<int>(PureQuadCompletionBackend::BoundedCombinatorial);
  }
  fields.variant = 0;
  if (mesh != nullptr) {
    fields.backend = static_cast<int>(mesh->backend);
    fields.variant = !mesh->quadLineage.empty()
                         ? mesh->quadLineage.front().completionVariant : 0;
  }
  return fields;
}


  PatchCompletionReuseMismatch dependency_mismatch(
      const PatchCompletionDependencyFields &requested,
      const PatchCompletionDependencyFields &cached, const int requestedCell,
      const int cachedCell) {
    PatchCompletionReuseMismatch mismatch;
    mismatch.requestedCell = requestedCell;
    mismatch.cachedCell = cachedCell;
    mismatch.sourceDomain = requested.sourceDomain != cached.sourceDomain;
    mismatch.sideSubdivision =
        requested.sideSubdivision != cached.sideSubdivision;
    mismatch.boundarySourceCoordinates =
        requested.boundarySourceCoordinates !=
        cached.boundarySourceCoordinates;
    mismatch.railCurveSupport =
        requested.railCurveSupport != cached.railCurveSupport;
    mismatch.singularityRequirements =
        requested.singularityRequirements !=
        cached.singularityRequirements;
    mismatch.topologyTemplate =
        requested.topologyTemplate != cached.topologyTemplate;
    mismatch.backendVariant =
        requested.backend >= 0 && cached.backend >= 0 &&
        (requested.backend != cached.backend ||
         requested.variant != cached.variant);
    return mismatch;
  }

PatchCompletionDependencyIdentity exact_patch_dependency_identity(
    const PatchDescriptor &descriptor) {
  const PatchCompletionDependencyFields fields =
      completion_dependency_fields(descriptor);
  PatchCompletionDependencyIdentity identity;
  identity.valid = true;
  append_identity(identity, fields.sourceDomain);
  append_identity(identity, fields.sideSubdivision);
  append_identity(identity, fields.boundarySourceCoordinates);
  append_identity(identity, fields.railCurveSupport);
  append_identity(identity, fields.singularityRequirements);
  append_identity(identity, fields.topologyTemplate);
  identity.values.push_back(fields.backend);
  identity.values.push_back(fields.variant);
  return identity;
}

std::uint64_t exact_patch_dependency_hash(const PatchDescriptor &descriptor) {
  return exact_patch_dependency_identity(descriptor).hash();
}


struct CachedCompletionProduct {
  PatchDescriptor descriptor;
  PureQuadMesh mesh;
  PatchCompletionDependencyFields dependency;
  bool consumed = false;
};

struct ReusableCompletionProducts {
  std::map<std::uint64_t, std::vector<CachedCompletionProduct>> products;
  std::uint64_t ownedBytes = 0U;
};

void retarget_reused_completion_product(
    PureQuadMesh &mesh, const PatchDescriptor &descriptor) {
  mesh.sourcePatch = descriptor.cellId;
  mesh.domainIdentity = descriptor.patch.domainIdentity;
  for (PureQuadVertexLineage &lineage : mesh.vertexLineage) {
    lineage.sourcePatch = descriptor.cellId;
  }
  for (PureQuadFaceLineage &lineage : mesh.quadLineage) {
    lineage.sourcePatch = descriptor.cellId;
  }
}

ReusableCompletionProducts take_reusable_completion_products(
    SurfaceCellComplexCompletionDraft &result) {
  ReusableCompletionProducts cache;
  std::vector<unsigned char> meshUsed(result.completedPatches.size(), 0U);
  for (std::size_t descriptorIndex = 0;
       descriptorIndex < result.descriptors.descriptors.size();
       ++descriptorIndex) {
    PatchDescriptor &descriptor =
        result.descriptors.descriptors[descriptorIndex];
    std::size_t meshIndex = result.completedPatches.size();
    if (descriptorIndex < result.completedPatches.size() &&
        result.completedPatches[descriptorIndex].sourcePatch ==
            descriptor.cellId) {
      meshIndex = descriptorIndex;
    } else {
      for (std::size_t candidate = 0;
           candidate < result.completedPatches.size(); ++candidate) {
        if (meshUsed[candidate] == 0U &&
            result.completedPatches[candidate].sourcePatch ==
                descriptor.cellId) {
          meshIndex = candidate;
          break;
        }
      }
    }
    if (meshIndex >= result.completedPatches.size()) {
      continue;
    }
    meshUsed[meshIndex] = 1U;
    CachedCompletionProduct product;
    product.descriptor = std::move(descriptor);
    product.mesh = std::move(result.completedPatches[meshIndex]);
    product.dependency =
        completion_dependency_fields(product.descriptor, &product.mesh);
    const std::uint64_t semanticHash =
        exact_patch_dependency_hash(product.descriptor);
    cache.products[semanticHash].push_back(std::move(product));
  }
  result.completedPatches.clear();
  result.completedPatches.shrink_to_fit();
  result.descriptors.descriptors.clear();
  result.descriptors.descriptors.shrink_to_fit();
  result.assembly.mesh = {};
  for (const auto &[hash, bucket] : cache.products) {
    (void)hash;
    for (const CachedCompletionProduct &product : bucket) {
      cache.ownedBytes += sizeof(PatchDescriptor) +
                          estimated_descriptor_payload_owned_bytes(
                              product.descriptor);
      cache.ownedBytes += estimated_mesh_owned_bytes(product.mesh);
    }
  }
  return cache;
}

std::uint64_t conflict_inventory_hash(
    const std::vector<SurfaceCellOwnershipConflict> &conflicts) {
  std::uint64_t seed = 1469598103934665603ULL;
  const auto mix = [&](const std::uint64_t value) {
    seed ^= value;
    seed *= 1099511628211ULL;
  };
  mix(static_cast<std::uint64_t>(conflicts.size()));
  for (const SurfaceCellOwnershipConflict &conflict : conflicts) {
    mix(conflict.exact_hash());
  }
  return seed;
}

struct ConflictInventoryDifference {
  int retained = 0;
  int removed = 0;
  int introduced = 0;
  bool strictReduction = false;
};

ConflictInventoryDifference compare_conflict_inventories(
    const std::vector<SurfaceCellOwnershipConflict> &before,
    const std::vector<SurfaceCellOwnershipConflict> &after) {
  ConflictInventoryDifference difference;
  std::size_t beforeIndex = 0;
  std::size_t afterIndex = 0;
  while (beforeIndex < before.size() && afterIndex < after.size()) {
    if (before[beforeIndex] == after[afterIndex]) {
      ++difference.retained;
      ++beforeIndex;
      ++afterIndex;
    } else if (before[beforeIndex] < after[afterIndex]) {
      ++difference.removed;
      ++beforeIndex;
    } else {
      ++difference.introduced;
      ++afterIndex;
    }
  }
  difference.removed += static_cast<int>(before.size() - beforeIndex);
  difference.introduced += static_cast<int>(after.size() - afterIndex);
  difference.strictReduction = difference.introduced == 0 &&
                               difference.removed > 0 &&
                               after.size() < before.size();
  return difference;
}

SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
    SurfaceCellComplex complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options,
    ReusableCompletionProducts *reusableProducts = nullptr) {
  SurfaceCellComplexCompletionDraft result;
  const SurfacePointSourceSupportResolver sourceSupportResolver(F);
  SurfaceCellParityRepairResult parityRepair =
      repair_surface_cell_boundary_parity(std::move(complex));
  std::optional<SurfaceCellParityRepairProduct> parityProduct;
  std::optional<SurfaceCellParityRepairFailure> parityFailure;
  bool parityNotApplicable = false;
  std::visit(
      [&](auto &&outcome) {
        using Outcome = std::decay_t<decltype(outcome)>;
        if constexpr (std::is_same_v<Outcome, NotApplicable>) {
          parityNotApplicable = true;
        } else if constexpr (
            std::is_same_v<Outcome, Produced<SurfaceCellParityRepairProduct>>) {
          parityProduct = std::move(outcome.product);
        } else {
          parityFailure = std::move(outcome.failure);
        }
      },
      std::move(parityRepair).outcome());
  const auto recordParityDiagnostics = [&](const auto &parity) {
    result.parityOddCellsBefore = parity.oddCellsBefore;
    result.parityOddCellsAfter = parity.oddCellsAfter;
    result.paritySplitEdges = static_cast<int>(parity.splitHalfedges.size());
    result.parityHardFeatureSplits = parity.hardFeatureSplits;
    result.parityAlternativeCandidateBudget = parity.alternativeCandidateBudget;
    result.parityAlternativeCandidatesAttempted =
        parity.alternativeCandidatesAttempted;
    result.parityAlternativeVisitedStates = parity.alternativeVisitedStates;
    result.parityAlternativeSelectedExclusion =
        parity.alternativeSelectedExclusion;
    result.parityAlternativeStateSequenceHash =
        parity.alternativeStateSequenceHash;
    result.parityAlternativeDisposition = parity.alternativeDisposition;
    result.firstParityScopeFailure = parity.firstScopeFailure;
    if (parity.firstDomainFailure.failure !=
        SurfaceCellDomainIdentityFailureKind::None) {
      result.firstInvalidDomain = parity.firstDomainFailure;
    }
  };
  if (parityNotApplicable) {
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "BoundaryParityRepair:UnexpectedNotApplicable";
    result.assembly.failure = result.failure;
    return result;
  }
  if (parityFailure.has_value()) {
    recordParityDiagnostics(parityFailure.value());
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "BoundaryParityRepair:" + parityFailure->detail;
    result.assembly.failure = result.failure;
    return result;
  }
  if (!parityProduct.has_value()) {
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "BoundaryParityRepair:MissingOutcome";
    result.assembly.failure = result.failure;
    return result;
  }
  recordParityDiagnostics(parityProduct.value());

  SurfaceCellSideRepairResult sideRepair =
      repair_surface_cell_side_subdivisions(
          std::move(parityProduct->complex), V, F, options.sideRepairOptions);
  std::optional<SurfaceCellSideRepairProduct> sideProduct;
  std::optional<SurfaceCellSideRepairFailure> sideFailure;
  bool sideNotApplicable = false;
  std::visit(
      [&](auto &&outcome) {
        using Outcome = std::decay_t<decltype(outcome)>;
        if constexpr (std::is_same_v<Outcome, NotApplicable>) {
          sideNotApplicable = true;
        } else if constexpr (
            std::is_same_v<Outcome, Produced<SurfaceCellSideRepairProduct>>) {
          sideProduct = std::move(outcome.product);
        } else {
          sideFailure = std::move(outcome.failure);
        }
      },
      std::move(sideRepair).outcome());
  const auto recordSideDiagnostics = [&](const auto &side) {
    result.sideInfeasibleCellsBefore = side.infeasibleCellsBefore;
    result.sideInfeasibleCellsAfter = side.infeasibleCellsAfter;
    result.sideInitialEquationDefect = side.initialEquationDefect;
    result.sideFinalEquationDefect = side.finalEquationDefect;
    result.sidePropagationPasses = side.propagationPasses;
    result.sideAttemptedInsertions = side.attemptedInsertions;
    result.sideInsertedVertices = side.insertedVertices;
    result.sideSplitEdges = side.splitUndirectedEdges;
    result.sideHardFeatureSplits = side.hardFeatureSplits;
    result.sideRollbackEquivalent = side.rollbackEquivalent;
    result.sideRollbackIdentityHashBefore = side.rollbackIdentityHashBefore;
    result.sideRollbackIdentityHashAfter = side.rollbackIdentityHashAfter;
    result.sideRollbackUndoOwnedBytes = side.rollbackUndoOwnedBytes;
    if (side.firstDomainFailure.failure !=
        SurfaceCellDomainIdentityFailureKind::None) {
      result.firstInvalidDomain = side.firstDomainFailure;
    }
  };
  if (sideNotApplicable) {
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "SideSubdivisionRepair:UnexpectedNotApplicable";
    result.assembly.failure = result.failure;
    return result;
  }
  if (sideFailure.has_value()) {
    recordSideDiagnostics(sideFailure.value());
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "SideSubdivisionRepair:" + sideFailure->detail;
    result.assembly.failure = result.failure;
    return result;
  }
  if (!sideProduct.has_value()) {
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "SideSubdivisionRepair:MissingOutcome";
    result.assembly.failure = result.failure;
    return result;
  }
  recordSideDiagnostics(sideProduct.value());
  if (sideProduct->kind ==
      SurfaceCellSideRepairProductKind::GeneralFallbackPreparation) {
    if (!options.allowBoundedCombinatorialFallback) {
      result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
      result.failure = "SideSubdivisionRepair:" + sideProduct->preparationDetail;
      result.assembly.failure = result.failure;
      return result;
    }
    // The simple closed-form equations are a regularity condition, not a
    // necessary condition for an even disk patch. The produced preparation
    // product owns the exact rolled-back canonical complex that general
    // completion may consume; no rejected outcome is reinterpreted here.
    result.preparedComplex = std::move(sideProduct->complex);
    result.sideInfeasibleCellsAfter = result.sideInfeasibleCellsBefore;
    result.sideFinalEquationDefect = result.sideInitialEquationDefect;
    result.sideInsertedVertices = 0;
    result.sideSplitEdges = 0;
    result.sideHardFeatureSplits = 0;
  } else {
    result.preparedComplex = std::move(sideProduct->complex);
  }
  result.hasPreparedComplex = true;
  const SurfaceCellComplex &prepared = result.preparedComplex;
  for (const SurfaceArrangementCell &cell : prepared.cells) {
    if (cell.cellClass == SurfaceArrangementCellClass::Exterior) {
      continue;
    }
    const SurfaceCellDomainIdentityAudit audit =
        audit_surface_cell_domain_identity(prepared, cell, cell.halfedges, F);
    if (audit.valid) {
      continue;
    }
    result.firstInvalidDomain = audit;
    result.failureKind = SurfaceCellComplexCompletionFailureKind::InvalidDomainIdentity;
    result.failure =
        std::string("SuccessfulSubdivisionDomainIdentity;identityFailure=") +
        surface_cell_domain_identity_failure_name(audit.failure) +
        ";cell=" + std::to_string(audit.cellId) +
        ";halfedge=" + std::to_string(audit.halfedgeId) +
        ";node=" + std::to_string(audit.nodeId) +
        ";sourceFace=" + std::to_string(audit.sourceFace) +
        ";component=" + std::to_string(audit.sourceComponent) +
        ";sheet=" + std::to_string(audit.sourceSheet);
    result.assembly.failure = result.failure;
    return result;
  }
  result.descriptors = derive_patch_descriptors(
      prepared, V, F, options.descriptorOptions);
  result.firstInvalidDomain = result.descriptors.firstInvalidDomain;
  if (result.descriptors.descriptors.empty()) {
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PreparationRejected;
    result.failure = "NoPatchDescriptors";
    result.assembly.failure = result.failure;
    return result;
  }
  if (result.descriptors.ownershipConflict.active()) {
    result.failureKind =
        SurfaceCellComplexCompletionFailureKind::CompletionOwnershipRejected;
    result.assembly.ownershipConflict =
        result.descriptors.ownershipConflict;
    const SurfaceCellOwnershipConflict &conflict =
        result.descriptors.ownershipConflict;
    std::string prefix = "InvalidArrangementDomainIdentity";
    if (conflict.classification ==
        SurfaceCellOwnershipConflictClass::DuplicateOrientedDomain) {
      prefix = "DuplicateArrangementDomain";
    } else if (conflict.classification ==
               SurfaceCellOwnershipConflictClass::
                   OverlappingUndirectedBoundary) {
      prefix = "OverlappingArrangementBoundary";
    }
    result.failure = prefix + ";firstPatch=" +
                     std::to_string(conflict.firstPatch) +
                     ";secondPatch=" +
                     std::to_string(conflict.secondPatch);
    if (conflict.classification ==
            SurfaceCellOwnershipConflictClass::InvalidDomainIdentity &&
        result.firstInvalidDomain.failure !=
            SurfaceCellDomainIdentityFailureKind::None) {
      result.failure +=
          ";identityFailure=" +
          std::string(surface_cell_domain_identity_failure_name(
              result.firstInvalidDomain.failure)) +
          ";halfedge=" +
          std::to_string(result.firstInvalidDomain.halfedgeId) +
          ";node=" + std::to_string(result.firstInvalidDomain.nodeId) +
          ";sourceFace=" +
          std::to_string(result.firstInvalidDomain.sourceFace) +
          ";component=" +
          std::to_string(result.firstInvalidDomain.sourceComponent) +
          ";sheet=" +
          std::to_string(result.firstInvalidDomain.sourceSheet);
    }
    result.assembly.failure = result.failure;
    return result;
  }
  if (!result.descriptors.unresolvedSingularVertices.empty()) {
    result.failureKind =
        SurfaceCellComplexCompletionFailureKind::UnresolvedSingularityOwnership;
    result.failure = "UnresolvedSingularityOwnership";
    result.assembly.failure = result.failure;
    return result;
  }
  const int descriptorCount =
      static_cast<int>(result.descriptors.descriptors.size());
  std::vector<int> completionVariants(
      static_cast<std::size_t>(descriptorCount), 0);
  std::map<int, int> descriptorIndexByPatch;
  for (int descriptorIndex = 0; descriptorIndex < descriptorCount;
       ++descriptorIndex) {
    descriptorIndexByPatch.emplace(
        result.descriptors.descriptors[static_cast<std::size_t>(descriptorIndex)]
            .cellId,
        descriptorIndex);
  }

  const auto completeDescriptor = [&](const int descriptorIndex,
                                      const int completionVariant) {
    const PatchDescriptor &descriptor = result.descriptors.descriptors[
        static_cast<std::size_t>(descriptorIndex)];
    PureQuadCompletionOptions completionOptions;
    completionOptions.sourcePatch = descriptor.cellId;
    completionOptions.maxBoundaryEdges = options.maxBoundaryEdges;
    completionOptions.allowBoundedCombinatorialFallback =
        options.allowBoundedCombinatorialFallback;
    completionOptions.completionVariant = completionVariant;
    completionOptions.sourceVertices = &V;
    completionOptions.sourceFaces = &F;
    completionOptions.sourceSupportResolver = &sourceSupportResolver;
    completionOptions.sourceAuthority = options.sourceAuthority;
    completionOptions.sourceHardFeatureEdges =
        options.sourceHardFeatureEdges;
    return complete_pure_quad_patch(descriptor.patch, completionOptions);
  };

  int firstFailedDescriptor = -1;
  int firstFailedCell = -1;
  PureQuadPatchRejectReason firstFailedReason =
      PureQuadPatchRejectReason::None;
  for (int descriptorIndex = 0; descriptorIndex < descriptorCount;
       ++descriptorIndex) {
    const PatchDescriptor &descriptor = result.descriptors.descriptors[
        static_cast<std::size_t>(descriptorIndex)];
    const bool boundedFallbackAdmissible =
        options.allowBoundedCombinatorialFallback &&
        (descriptor.feasibility.reason ==
             PureQuadPatchRejectReason::SideInequality ||
         descriptor.feasibility.reason ==
             PureQuadPatchRejectReason::HexParity);
    if (!descriptor.boundaryCycleValid ||
        (!descriptor.feasibility.admissible &&
         !boundedFallbackAdmissible)) {
      ++result.failedPatches;
      if (firstFailedDescriptor < 0) {
        firstFailedDescriptor = descriptorIndex;
        firstFailedCell = descriptor.cellId;
        firstFailedReason = descriptor.feasibility.reason;
      }
      continue;
    }
    ++result.attemptedPatches;
    if (reusableProducts != nullptr) {
      const PatchCompletionDependencyFields requestedDependency =
          completion_dependency_fields(descriptor);
      const std::uint64_t semanticHash =
          exact_patch_dependency_hash(descriptor);
      const auto cached = reusableProducts->products.find(semanticHash);
      std::vector<CachedCompletionProduct *> candidates;
      if (cached != reusableProducts->products.end()) {
        for (CachedCompletionProduct &product : cached->second) {
          candidates.push_back(&product);
        }
      } else {
        ++result.completionOwnershipProductCacheHashMisses;
        // Compact canonical identities can be re-interned after a structural
        // transaction even when the exact dependency fields are unchanged.
        // A hash miss therefore falls back to one deterministic exact-field
        // scan over the finite cache. Reuse is counted only after exact
        // dependency comparison, source-chart rebinding, topology, and lineage
        // validation all succeed.
        for (auto &[candidateHash, products] : reusableProducts->products) {
          (void)candidateHash;
          for (CachedCompletionProduct &product : products) {
            candidates.push_back(&product);
          }
        }
      }
      std::sort(candidates.begin(), candidates.end(),
                [](const CachedCompletionProduct *lhs,
                   const CachedCompletionProduct *rhs) {
                  return std::tie(lhs->descriptor.cellId,
                                  lhs->dependency.backend,
                                  lhs->dependency.variant) <
                         std::tie(rhs->descriptor.cellId,
                                  rhs->dependency.backend,
                                  rhs->dependency.variant);
                });

      bool reusedProduct = false;
      PatchCompletionReuseMismatch bestMismatch;
      bestMismatch.requestedCell = descriptor.cellId;
      bestMismatch.hashMiss = cached == reusableProducts->products.end();
      int bestMismatchCount = std::numeric_limits<int>::max();
      for (CachedCompletionProduct *product : candidates) {
        if (product == nullptr || product->consumed) {
          continue;
        }
        PatchCompletionReuseMismatch mismatch = dependency_mismatch(
            requestedDependency, product->dependency, descriptor.cellId,
            product->descriptor.cellId);
        mismatch.hashMiss = cached == reusableProducts->products.end();
        const bool exactDependency =
            !mismatch.sourceDomain && !mismatch.sideSubdivision &&
            !mismatch.boundarySourceCoordinates &&
            !mismatch.railCurveSupport &&
            !mismatch.singularityRequirements &&
            !mismatch.backendVariant && !mismatch.topologyTemplate;
        if (!exactDependency) {
          const int mismatchCount =
              static_cast<int>(mismatch.sourceDomain) +
              static_cast<int>(mismatch.sideSubdivision) +
              static_cast<int>(mismatch.boundarySourceCoordinates) +
              static_cast<int>(mismatch.railCurveSupport) +
              static_cast<int>(mismatch.singularityRequirements) +
              static_cast<int>(mismatch.backendVariant) +
              static_cast<int>(mismatch.topologyTemplate);
          if (mismatchCount < bestMismatchCount ||
              (mismatchCount == bestMismatchCount &&
               mismatch.cachedCell < bestMismatch.cachedCell)) {
            bestMismatchCount = mismatchCount;
            bestMismatch = mismatch;
          }
          continue;
        }

        PureQuadMesh reused = product->mesh;
        retarget_reused_completion_product(reused, descriptor);
        std::string ownershipFailure;
        PureQuadCompletionOwnershipRejection ownershipRejection;
        const int completionVariant =
            product->dependency.variant >= 0 ? product->dependency.variant : 0;
        const bool ownershipValid =
            pure_quad_detail::validate_completion_domain_ownership(
                descriptor.patch, reused, completionVariant,
                &sourceSupportResolver, &F, options.sourceAuthority,
                ownershipFailure,
                &ownershipRejection, options.sourceHardFeatureEdges);
        const bool topologyValid =
            ownershipValid && pure_quad_topology_is_disk(reused) &&
            !reused.quads.empty();
        const PureQuadOutputLineageValidation lineage =
            topologyValid ? validate_pure_quad_output_lineage(reused, F, true)
                          : PureQuadOutputLineageValidation{};
        if (!topologyValid || !lineage.valid) {
          mismatch.rebindValidation = true;
          result.completionOwnershipProductCacheMismatchVector.push_back(
              std::move(mismatch));
          if (!result.firstCompletionOwnershipRejection.active &&
              ownershipRejection.active) {
            result.firstCompletionOwnershipRejection = ownershipRejection;
          }
          continue;
        }

        product->consumed = true;
        result.completedPatches.push_back(std::move(reused));
        ++result.completionOwnershipReusedPatchCompletions;
        reusedProduct = true;
        break;
      }
      if (reusedProduct) {
        continue;
      }
      if (bestMismatchCount != std::numeric_limits<int>::max()) {
        result.completionOwnershipProductCacheMismatchVector.push_back(
            std::move(bestMismatch));
      }
      ++result.completionOwnershipProductCacheExactMismatches;
    }

    ++result.completionOwnershipRecomputedPatchCompletions;
    PureQuadCompletionBackend expectedBackend =
        PureQuadCompletionBackend::BoundedCombinatorial;
    const bool rectangular = descriptor.patch.sideEdgeCounts.size() == 4U &&
        descriptor.patch.sideEdgeCounts[0] > 0 &&
        descriptor.patch.sideEdgeCounts[1] > 0 &&
        descriptor.patch.sideEdgeCounts[0] == descriptor.patch.sideEdgeCounts[2] &&
        descriptor.patch.sideEdgeCounts[1] == descriptor.patch.sideEdgeCounts[3];
    if (descriptor.patch.singularityCount != 0) {
      expectedBackend = PureQuadCompletionBackend::PoleTemplate;
    } else if (rectangular) {
      expectedBackend = PureQuadCompletionBackend::ClosedForm;
    } else if (descriptor.patch.boundaryVertices.size() == 6U) {
      expectedBackend = PureQuadCompletionBackend::TransitionTemplate;
    } else if (descriptor.patch.simple) {
      expectedBackend = PureQuadCompletionBackend::Pattern;
    }
    const int variantCount =
        completion_variant_count(descriptor.patch, expectedBackend);
    PureQuadCompletionResult completion;
    int selectedVariant = 0;
    for (int variant = 0; variant < variantCount; ++variant) {
      PureQuadCompletionResult candidate =
          completeDescriptor(descriptorIndex, variant);
      const bool candidateSucceeded =
          candidate.is_produced() && !candidate.product().quads.empty();
      if (candidateSucceeded) {
        completion = std::move(candidate);
        selectedVariant = variant;
        break;
      }
      const auto *candidateFailure = candidate.rejection();
      const bool invalidEmbedding =
          candidateFailure != nullptr &&
          candidateFailure->detail.rfind("InvalidCompletionQuadEmbedding", 0) ==
              0;
      completion = std::move(candidate);
      if (!invalidEmbedding) {
        break;
      }
    }
    completionVariants[static_cast<std::size_t>(descriptorIndex)] =
        selectedVariant;
    if (!completion.is_produced() || completion.product().quads.empty()) {
      ++result.failedPatches;
      const auto *completionFailure = completion.rejection();
      if (firstFailedDescriptor < 0) {
        firstFailedDescriptor = descriptorIndex;
        firstFailedCell = descriptor.cellId;
        firstFailedReason = completionFailure == nullptr
            ? PureQuadPatchRejectReason::TopologyValidationFailed
            : completionFailure->reason;
      }
      if (completionFailure != nullptr) {
        if (!result.firstCompletionOwnershipRejection.active &&
            completionFailure->ownershipRejection.active) {
          result.firstCompletionOwnershipRejection =
              completionFailure->ownershipRejection;
        }
        if (!result.firstCompletionEmbeddingFailure.active &&
            completionFailure->embeddingFailure.active) {
          result.firstCompletionEmbeddingFailure =
              completionFailure->embeddingFailure;
        }
        if (result.failure.empty() && !completionFailure->detail.empty()) {
          result.failure = completionFailure->detail;
        }
      } else if (result.failure.empty()) {
        result.failure = "CompletionMissingOutcome";
      }
      continue;
    }
    result.completedPatches.push_back(std::move(completion).product());
  }
  if (result.failedPatches != 0 ||
      result.completedPatches.size() != result.descriptors.descriptors.size()) {
    if (result.failure.empty()) {
      std::ostringstream stream;
      stream << "IncompleteSurfaceCellComplex;descriptor="
             << firstFailedDescriptor << ";cell=" << firstFailedCell
             << ";reason="
             << pure_quad_patch_reject_reason_name(firstFailedReason)
             << ";reasonCode=" << static_cast<int>(firstFailedReason)
             << ";attempted=" << result.attemptedPatches
             << ";failed=" << result.failedPatches
             << ";total=" << result.descriptors.descriptors.size();
      result.failure = stream.str();
    }
    result.failureKind = SurfaceCellComplexCompletionFailureKind::PatchCompletionRejected;
    result.assembly.failure = result.failure;
    return result;
  }
  for (int descriptorIndex = 0; descriptorIndex < descriptorCount;
       ++descriptorIndex) {
    const PureQuadMesh &mesh = result.completedPatches[
        static_cast<std::size_t>(descriptorIndex)];
    if (!mesh.quadLineage.empty()) {
      completionVariants[static_cast<std::size_t>(descriptorIndex)] =
          mesh.quadLineage.front().completionVariant;
    }
  }

  const auto normalizedConflicts = [](const PureQuadAssemblyResult &assembly) {
    std::vector<SurfaceCellOwnershipConflict> conflicts =
        assembly.ownershipConflicts;
    if (conflicts.empty() && assembly.ownershipConflict.active()) {
      conflicts.push_back(assembly.ownershipConflict);
    }
    std::sort(conflicts.begin(), conflicts.end());
    conflicts.erase(std::unique(conflicts.begin(), conflicts.end()),
                    conflicts.end());
    return conflicts;
  };

  const auto conflictComponentCount = [](
      const std::vector<SurfaceCellOwnershipConflict> &conflicts) {
    std::map<int, std::set<int>> adjacency;
    for (const SurfaceCellOwnershipConflict &conflict : conflicts) {
      adjacency[conflict.firstPatch].insert(conflict.secondPatch);
      adjacency[conflict.secondPatch].insert(conflict.firstPatch);
    }
    std::set<int> visited;
    int components = 0;
    for (const auto &[patch, neighbours] : adjacency) {
      (void)neighbours;
      if (!visited.insert(patch).second) {
        continue;
      }
      ++components;
      std::vector<int> stack{patch};
      while (!stack.empty()) {
        const int currentPatch = stack.back();
        stack.pop_back();
        const auto found = adjacency.find(currentPatch);
        if (found == adjacency.end()) {
          continue;
        }
        for (const int neighbour : found->second) {
          if (visited.insert(neighbour).second) {
            stack.push_back(neighbour);
          }
        }
      }
    }
    return components;
  };

  result.assembly = stitch_pure_quad_patches(
      result.completedPatches, 1.0e-9, &F, options.sourceAuthority,
      options.sourceHardFeatureEdges);
  result.completionTemplateAssemblyPasses = 1;
  std::vector<SurfaceCellOwnershipConflict> initialConflicts =
      normalizedConflicts(result.assembly);
  result.completionTemplateInitialConflictCount =
      static_cast<int>(initialConflicts.size());
  result.completionTemplateConflictComponentCount =
      conflictComponentCount(initialConflicts);
  std::set<int> globallyChangedPatches;

  while (!result.assembly.success &&
         result.completionOwnershipRepairAttempts <
             options.maxCompletionOwnershipRepairs) {
    const std::vector<SurfaceCellOwnershipConflict> before =
        normalizedConflicts(result.assembly);
    if (before.empty() ||
        std::any_of(before.begin(), before.end(),
                    [](const SurfaceCellOwnershipConflict &conflict) {
                      return conflict.classification !=
                             SurfaceCellOwnershipConflictClass::
                                 CompletionTemplateOwnership;
                    })) {
      break;
    }

    std::map<int, int> degree;
    std::map<int, SurfaceCellOwnershipConflict> firstConflictByPatch;
    for (const SurfaceCellOwnershipConflict &conflict : before) {
      ++degree[conflict.firstPatch];
      ++degree[conflict.secondPatch];
      firstConflictByPatch.try_emplace(conflict.firstPatch, conflict);
      firstConflictByPatch.try_emplace(conflict.secondPatch, conflict);
    }

    const auto hasNextVariant = [&](const int patchId) {
      const auto descriptor = descriptorIndexByPatch.find(patchId);
      if (descriptor == descriptorIndexByPatch.end()) {
        return false;
      }
      const int descriptorIndex = descriptor->second;
      const PureQuadMesh &mesh = result.completedPatches[
          static_cast<std::size_t>(descriptorIndex)];
      const PatchDescriptor &patchDescriptor = result.descriptors.descriptors[
          static_cast<std::size_t>(descriptorIndex)];
      const int variantCount =
          patch_descriptor_detail::completion_variant_count(
              patchDescriptor.patch, mesh.backend);
      return completionVariants[static_cast<std::size_t>(descriptorIndex)] + 1 <
             variantCount;
    };

    // Deterministic greedy cover of the complete conflict graph. A selected
    // patch is advanced once in this assignment transaction, so independent
    // completion-template conflicts are evaluated by one assembly pass rather
    // than one full pass per first conflict.
    std::set<int> selectedPatches;
    for (const SurfaceCellOwnershipConflict &conflict : before) {
      if (selectedPatches.count(conflict.firstPatch) != 0U ||
          selectedPatches.count(conflict.secondPatch) != 0U) {
        continue;
      }
      const bool firstAvailable = hasNextVariant(conflict.firstPatch);
      const bool secondAvailable = hasNextVariant(conflict.secondPatch);
      if (!firstAvailable && !secondAvailable) {
        continue;
      }
      int selected = firstAvailable ? conflict.firstPatch
                                    : conflict.secondPatch;
      if (firstAvailable && secondAvailable) {
        const int firstDegree = degree[conflict.firstPatch];
        const int secondDegree = degree[conflict.secondPatch];
        if (secondDegree > firstDegree ||
            (secondDegree == firstDegree &&
             conflict.secondPatch < conflict.firstPatch)) {
          selected = conflict.secondPatch;
        }
      }
      selectedPatches.insert(selected);
    }
    if (selectedPatches.empty()) {
      break;
    }

    struct VariantRollback {
      int descriptorIndex = -1;
      int previousVariant = 0;
      std::size_t attemptIndex = 0;
    };
    std::vector<VariantRollback> rollback;
    rollback.reserve(selectedPatches.size());

    for (const int patchId : selectedPatches) {
      if (result.completionOwnershipRepairAttempts >=
          options.maxCompletionOwnershipRepairs) {
        break;
      }
      const auto descriptorIndexIt = descriptorIndexByPatch.find(patchId);
      if (descriptorIndexIt == descriptorIndexByPatch.end()) {
        continue;
      }
      const int descriptorIndex = descriptorIndexIt->second;
      PureQuadMesh &currentMesh = result.completedPatches[
          static_cast<std::size_t>(descriptorIndex)];
      const PatchDescriptor &descriptor = result.descriptors.descriptors[
          static_cast<std::size_t>(descriptorIndex)];
      const int variantCount =
          patch_descriptor_detail::completion_variant_count(
              descriptor.patch, currentMesh.backend);
      int &variant =
          completionVariants[static_cast<std::size_t>(descriptorIndex)];
      const int previousVariant = variant;
      bool replacementFound = false;
      while (variant + 1 < variantCount &&
             result.completionOwnershipRepairAttempts <
                 options.maxCompletionOwnershipRepairs) {
        SurfaceCellOwnershipRepairAttempt attempt;
        attempt.action = SurfaceCellOwnershipRepairAction::CompletionVariant;
        attempt.conflictClass =
            SurfaceCellOwnershipConflictClass::CompletionTemplateOwnership;
        const SurfaceCellOwnershipConflict &representative =
            firstConflictByPatch.at(patchId);
        attempt.firstPatch = representative.firstPatch;
        attempt.secondPatch = representative.secondPatch;
        attempt.selectedPatch = patchId;
        attempt.backend = currentMesh.backend;
        attempt.fromVariant = variant;
        ++variant;
        attempt.toVariant = variant;
        ++result.completionOwnershipRepairAttempts;
        PureQuadCompletionResult alternative =
            completeDescriptor(descriptorIndex, variant);
        attempt.completionSucceeded =
            alternative.is_produced() && !alternative.product().quads.empty();
        if (!attempt.completionSucceeded) {
          attempt.outcome =
              SurfaceCellOwnershipRepairOutcome::ValidationFailed;
          const auto *alternativeFailure = alternative.rejection();
          attempt.failure =
              alternativeFailure == nullptr || alternativeFailure->detail.empty()
                  ? "CompletionVariantUnavailable"
                  : alternativeFailure->detail;
          if (alternativeFailure != nullptr &&
              !result.firstCompletionOwnershipRejection.active &&
              alternativeFailure->ownershipRejection.active) {
            result.firstCompletionOwnershipRejection =
                alternativeFailure->ownershipRejection;
          }
          result.ownershipRepairAttempts.push_back(std::move(attempt));
          continue;
        }

        const std::size_t attemptIndex =
            result.ownershipRepairAttempts.size();
        result.ownershipRepairAttempts.push_back(std::move(attempt));
        VariantRollback change;
        change.descriptorIndex = descriptorIndex;
        change.previousVariant = previousVariant;
        change.attemptIndex = attemptIndex;
        currentMesh = std::move(alternative).product();
        rollback.push_back(std::move(change));
        replacementFound = true;
        break;
      }
      if (!replacementFound) {
        variant = previousVariant;
      }
    }

    if (rollback.empty()) {
      break;
    }

    PureQuadAssemblyResult previousAssembly = std::move(result.assembly);
    PureQuadAssemblyResult candidateAssembly =
        stitch_pure_quad_patches(result.completedPatches, 1.0e-9, &F,
                                 options.sourceAuthority,
                                 options.sourceHardFeatureEdges);
    ++result.completionTemplateAssemblyPasses;
    const std::vector<SurfaceCellOwnershipConflict> after =
        normalizedConflicts(candidateAssembly);
    const ConflictInventoryDifference difference =
        compare_conflict_inventories(before, after);
    const bool commit = candidateAssembly.success ||
                        (difference.introduced == 0 &&
                         difference.strictReduction);

    if (commit) {
      for (VariantRollback &change : rollback) {
        SurfaceCellOwnershipRepairAttempt &attempt =
            result.ownershipRepairAttempts[change.attemptIndex];
        attempt.committed = true;
        attempt.madeProgress = true;
        attempt.resultingConflictClass =
            candidateAssembly.ownershipConflict.classification;
        attempt.outcome = candidateAssembly.success
            ? SurfaceCellOwnershipRepairOutcome::AssemblySucceeded
            : SurfaceCellOwnershipRepairOutcome::Committed;
        if (!candidateAssembly.success) {
          attempt.failure = candidateAssembly.failure;
        }
        globallyChangedPatches.insert(attempt.selectedPatch);
      }
      result.assembly = std::move(candidateAssembly);
      continue;
    }

    bool rollbackSucceeded = true;
    for (auto change = rollback.rbegin(); change != rollback.rend(); ++change) {
      PureQuadCompletionResult previous = completeDescriptor(
          change->descriptorIndex, change->previousVariant);
      if (!previous.is_produced() || previous.product().quads.empty()) {
        rollbackSucceeded = false;
      } else {
        result.completedPatches[static_cast<std::size_t>(
            change->descriptorIndex)] = std::move(previous).product();
      }
      completionVariants[static_cast<std::size_t>(change->descriptorIndex)] =
          change->previousVariant;
      SurfaceCellOwnershipRepairAttempt &attempt =
          result.ownershipRepairAttempts[change->attemptIndex];
      attempt.resultingConflictClass =
          candidateAssembly.ownershipConflict.classification;
      attempt.outcome = difference.introduced != 0
          ? SurfaceCellOwnershipRepairOutcome::IntroducedOwnershipClaim
          : SurfaceCellOwnershipRepairOutcome::NoProgress;
      attempt.failure = difference.introduced != 0
          ? "CompletionTemplateAssignmentIntroducedClaim:" +
                candidateAssembly.failure
          : "CompletionTemplateAssignmentNoProgress:" +
                candidateAssembly.failure;
    }
    result.assembly = std::move(previousAssembly);
    if (!rollbackSucceeded) {
      result.failureKind = SurfaceCellComplexCompletionFailureKind::AssemblyRejected;
      result.failure = "CompletionTemplateAssignmentRollbackFailed";
      result.assembly.failure = result.failure;
    }
    break;
  }

  result.completionTemplateChangedPatchCount =
      static_cast<int>(globallyChangedPatches.size());
  result.completionTemplateFinalConflictCount =
      static_cast<int>(normalizedConflicts(result.assembly).size());

  result.success = result.assembly.success;
  if (!result.success) {
    result.failureKind =
        (result.assembly.ownershipConflict.active() ||
         !result.assembly.ownershipConflicts.empty())
            ? SurfaceCellComplexCompletionFailureKind::CompletionOwnershipRejected
            : SurfaceCellComplexCompletionFailureKind::AssemblyRejected;
    result.failure = result.assembly.failure;
  }
  patch_descriptor_detail::renumber_ownership_repair_attempts(
      result.ownershipRepairAttempts);
  return result;
}

} // namespace directional::geometry::patch_descriptor_detail


namespace directional::geometry {

SurfaceCellComplexCompletionResult complete_surface_cell_complex(
    SurfaceCellComplex complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options) {
  struct StructuralRepairLedger {
    int candidateBudget = 0;
    int structuralAttemptBudget = 0;
    int insertedVertexBudget = -1;
    int fullPassBudget = 0;
    int visitedStateBudget = 0;
    int candidatesConsumed = 0;
    int structuralAttempts = 0;
    int insertedVertices = 0;
    int fullRecomputationPasses = 0;
    int incrementalRecomputationPasses = 0;
    int currentLiveCandidateComplexes = 0;
    int peakLiveCandidateComplexes = 0;
    int routeCandidateCount = 0;
    int preConflictCount = 0;
    int postConflictCount = 0;
    int retainedConflictCount = 0;
    int removedConflictCount = 0;
    int introducedConflictCount = 0;
    int conflictComponentCount = 0;
    int independentComponentCount = 0;
    int reusedPatchCompletions = 0;
    int recomputedPatchCompletions = 0;
    int productCacheHashMisses = 0;
    int productCacheExactMismatches = 0;
    std::vector<PatchCompletionReuseMismatch> productCacheMismatchVector;
    int completionTemplateInitialConflictCount = -1;
    int completionTemplateFinalConflictCount = 0;
    int completionTemplateConflictComponentCount = 0;
    int completionTemplateChangedPatchCount = 0;
    int completionTemplateAssemblyPasses = 0;
    std::uint64_t preConflictInventoryHash = 0U;
    std::uint64_t postConflictInventoryHash = 0U;
    std::uint64_t conflictFrontierOwnedBytes = 0U;
    std::uint64_t productCacheOwnedBytes = 0U;
    std::uint64_t rollbackOwnedBytes = 0U;
    std::uint64_t candidateOwnedBytes = 0U;
    std::uint64_t descriptorOwnedBytes = 0U;
    std::uint64_t completedPatchOwnedBytes = 0U;
    std::uint64_t assemblyOwnedBytes = 0U;
    std::uint64_t currentStructuralOwnedBytes = 0U;
    std::uint64_t peakStructuralOwnedBytes = 0U;
    SurfaceCellStructuralRepairExhaustionReason exhaustionReason =
        SurfaceCellStructuralRepairExhaustionReason::None;
    std::set<patch_descriptor_detail::SurfaceCellRepairStateIdentity>
        visitedStates;
  } ledger;

  ledger.candidateBudget =
      std::max(0, options.maxSameCornerCandidateEvaluations);
  ledger.structuralAttemptBudget =
      std::max(0, options.maxSameCornerBoundaryRepairs);
  ledger.insertedVertexBudget = options.maxSameCornerInsertedVertices;
  ledger.fullPassBudget =
      std::max(1, options.maxSameCornerFullCompletionPasses);
  ledger.visitedStateBudget =
      std::max(1, options.maxSameCornerVisitedStates);

  std::vector<SurfaceCellOwnershipRepairAttempt> aggregateAttempts;
  int aggregateVariantAttempts = 0;
  PureQuadCompletionOwnershipRejection firstOwnershipRejection;

  const auto mergePassEvidence =
      [&](patch_descriptor_detail::SurfaceCellComplexCompletionDraft &pass) {
        aggregateVariantAttempts += pass.completionOwnershipRepairAttempts;
        if (ledger.completionTemplateInitialConflictCount < 0) {
          ledger.completionTemplateInitialConflictCount =
              pass.completionTemplateInitialConflictCount;
        }
        ledger.completionTemplateFinalConflictCount =
            pass.completionTemplateFinalConflictCount;
        ledger.completionTemplateConflictComponentCount = std::max(
            ledger.completionTemplateConflictComponentCount,
            pass.completionTemplateConflictComponentCount);
        ledger.completionTemplateChangedPatchCount +=
            pass.completionTemplateChangedPatchCount;
        ledger.completionTemplateAssemblyPasses +=
            pass.completionTemplateAssemblyPasses;
        aggregateAttempts.insert(
            aggregateAttempts.end(),
            std::make_move_iterator(pass.ownershipRepairAttempts.begin()),
            std::make_move_iterator(pass.ownershipRepairAttempts.end()));
        pass.ownershipRepairAttempts.clear();
        ledger.productCacheMismatchVector.insert(
            ledger.productCacheMismatchVector.end(),
            std::make_move_iterator(
                pass.completionOwnershipProductCacheMismatchVector.begin()),
            std::make_move_iterator(
                pass.completionOwnershipProductCacheMismatchVector.end()));
        pass.completionOwnershipProductCacheMismatchVector.clear();
        if (!firstOwnershipRejection.active &&
            pass.firstCompletionOwnershipRejection.active) {
          firstOwnershipRejection = pass.firstCompletionOwnershipRejection;
        }
      };

  const auto finalize = [&](patch_descriptor_detail::SurfaceCellComplexCompletionDraft pass) {
    pass.completionOwnershipRepairAttempts = aggregateVariantAttempts;
    pass.completionTemplateInitialConflictCount =
        std::max(0, ledger.completionTemplateInitialConflictCount);
    pass.completionTemplateFinalConflictCount =
        ledger.completionTemplateFinalConflictCount;
    pass.completionTemplateConflictComponentCount =
        ledger.completionTemplateConflictComponentCount;
    pass.completionTemplateChangedPatchCount =
        ledger.completionTemplateChangedPatchCount;
    pass.completionTemplateAssemblyPasses =
        ledger.completionTemplateAssemblyPasses;
    pass.completionOwnershipStructuralRepairAttempts =
        ledger.structuralAttempts;
    pass.completionOwnershipInsertedBoundaryVertices =
        ledger.insertedVertices;
    pass.completionOwnershipStructuralCandidateBudget =
        ledger.candidateBudget;
    pass.completionOwnershipStructuralCandidatesConsumed =
        ledger.candidatesConsumed;
    pass.completionOwnershipVisitedStateCount =
        static_cast<int>(ledger.visitedStates.size());
    pass.completionOwnershipFullRecomputationPasses =
        ledger.fullRecomputationPasses;
    pass.completionOwnershipIncrementalRecomputationPasses =
        ledger.incrementalRecomputationPasses;
    pass.completionOwnershipPreConflictCount = ledger.preConflictCount;
    pass.completionOwnershipPostConflictCount = ledger.postConflictCount;
    pass.completionOwnershipRetainedConflictCount =
        ledger.retainedConflictCount;
    pass.completionOwnershipRemovedConflictCount =
        ledger.removedConflictCount;
    pass.completionOwnershipIntroducedConflictCount =
        ledger.introducedConflictCount;
    pass.completionOwnershipConflictComponentCount =
        ledger.conflictComponentCount;
    pass.completionOwnershipIndependentComponentCount =
        ledger.independentComponentCount;
    pass.completionOwnershipReusedPatchCompletions =
        ledger.reusedPatchCompletions;
    pass.completionOwnershipRecomputedPatchCompletions =
        ledger.recomputedPatchCompletions;
    pass.completionOwnershipProductCacheHashMisses =
        ledger.productCacheHashMisses;
    pass.completionOwnershipProductCacheExactMismatches =
        ledger.productCacheExactMismatches;
    pass.completionOwnershipProductCacheMismatchVector =
        std::move(ledger.productCacheMismatchVector);
    pass.completionOwnershipPreConflictInventoryHash =
        ledger.preConflictInventoryHash;
    pass.completionOwnershipPostConflictInventoryHash =
        ledger.postConflictInventoryHash;
    pass.completionOwnershipConflictFrontierOwnedBytes =
        ledger.conflictFrontierOwnedBytes;
    pass.completionOwnershipProductCacheOwnedBytes =
        ledger.productCacheOwnedBytes;
    pass.completionOwnershipCurrentLiveCandidateComplexes =
        ledger.currentLiveCandidateComplexes;
    pass.completionOwnershipPeakLiveCandidateComplexes =
        ledger.peakLiveCandidateComplexes;
    pass.completionOwnershipRouteCandidateCount = ledger.routeCandidateCount;
    pass.completionOwnershipRollbackOwnedBytes = ledger.rollbackOwnedBytes;
    pass.completionOwnershipCandidateOwnedBytes = ledger.candidateOwnedBytes;
    pass.completionOwnershipDescriptorOwnedBytes = ledger.descriptorOwnedBytes;
    pass.completionOwnershipCompletedPatchOwnedBytes =
        ledger.completedPatchOwnedBytes;
    pass.completionOwnershipAssemblyOwnedBytes = ledger.assemblyOwnedBytes;
    pass.completionOwnershipCurrentStructuralOwnedBytes =
        ledger.currentStructuralOwnedBytes;
    pass.completionOwnershipPeakStructuralOwnedBytes =
        ledger.peakStructuralOwnedBytes;
    pass.completionLogicalPayloadBytes =
        patch_descriptor_detail::logical_complex_payload_bytes(
            pass.preparedComplex) +
        patch_descriptor_detail::logical_descriptor_bytes(pass.descriptors) +
        patch_descriptor_detail::logical_completed_patches_bytes(
            pass.completedPatches) +
        patch_descriptor_detail::logical_mesh_payload_bytes(pass.assembly.mesh) +
        static_cast<std::uint64_t>(pass.assembly.ownershipConflicts.size()) *
            sizeof(SurfaceCellOwnershipConflict);
    pass.completionRetainedCapacityBytes =
        std::max(pass.completionOwnershipCurrentStructuralOwnedBytes,
                 patch_descriptor_detail::estimated_complex_owned_bytes(
                     pass.preparedComplex) +
                 patch_descriptor_detail::estimated_descriptor_owned_bytes(
                     pass.descriptors) +
                 patch_descriptor_detail::estimated_completed_patches_owned_bytes(
                     pass.completedPatches) +
                 patch_descriptor_detail::estimated_mesh_owned_bytes(
                     pass.assembly.mesh) +
                 static_cast<std::uint64_t>(
                     pass.assembly.ownershipConflicts.capacity()) *
                     sizeof(SurfaceCellOwnershipConflict));
    pass.completionOwnershipStructuralExhaustionReason =
        ledger.exhaustionReason;
    pass.ownershipRepairAttempts = std::move(aggregateAttempts);
    if (!pass.firstCompletionOwnershipRejection.active &&
        firstOwnershipRejection.active) {
      pass.firstCompletionOwnershipRejection = firstOwnershipRejection;
    }
    patch_descriptor_detail::renumber_ownership_repair_attempts(
        pass.ownershipRepairAttempts);
    return patch_descriptor_detail::close_surface_cell_complex_completion(
        std::move(pass));
  };

  patch_descriptor_detail::SurfaceCellComplexCompletionDraft current =
      patch_descriptor_detail::complete_surface_cell_complex_pass(
          std::move(complex), V, F, options);
  ++ledger.fullRecomputationPasses;
  mergePassEvidence(current);
  // Account for the initial production pass as well as later structural
  // candidates. Previously all owned-byte diagnostics remained zero when the
  // frontier was rejected before its first transaction, obscuring the actual
  // memory cost of a 21k-cell completion complex.
  ledger.rollbackOwnedBytes =
      patch_descriptor_detail::estimated_complex_owned_bytes(
          current.preparedComplex);
  ledger.descriptorOwnedBytes =
      patch_descriptor_detail::estimated_descriptor_owned_bytes(
          current.descriptors);
  ledger.completedPatchOwnedBytes =
      patch_descriptor_detail::estimated_completed_patches_owned_bytes(
          current.completedPatches);
  ledger.assemblyOwnedBytes =
      patch_descriptor_detail::estimated_mesh_owned_bytes(
          current.assembly.mesh) +
      current.assembly.estimatedWorkspaceOwnedBytes;
  ledger.conflictFrontierOwnedBytes =
      static_cast<std::uint64_t>(
          current.assembly.ownershipConflicts.capacity()) *
      sizeof(SurfaceCellOwnershipConflict);
  ledger.currentStructuralOwnedBytes =
      ledger.rollbackOwnedBytes + ledger.descriptorOwnedBytes +
      ledger.completedPatchOwnedBytes + ledger.assemblyOwnedBytes +
      ledger.conflictFrontierOwnedBytes;
  ledger.peakStructuralOwnedBytes = ledger.currentStructuralOwnedBytes;

  // An initially valid assembly is already the authoritative terminal result.
  // Do not route it through the structural-exhaustion epilogue, which would
  // relabel success as a failure and clear the mesh while leaving success=true.
  if (current.success) {
    return finalize(std::move(current));
  }

  struct FrontierCandidate {
    SurfaceCellOwnershipConflict conflict;
    patch_descriptor_detail::SameCornerRouteCandidate candidate;
    std::vector<int> affectedPatches;
  };

  const auto exact_set_overlap = [](const std::vector<int> &lhs,
                                    const std::vector<int> &rhs) {
    std::size_t a = 0;
    std::size_t b = 0;
    while (a < lhs.size() && b < rhs.size()) {
      if (lhs[a] == rhs[b]) {
        return true;
      }
      if (lhs[a] < rhs[b]) {
        ++a;
      } else {
        ++b;
      }
    }
    return false;
  };

  const auto owner_corner_overlap = [](
      const SurfaceCellCompletedFaceOwnerIdentity &lhs,
      const SurfaceCellCompletedFaceOwnerIdentity &rhs) {
    for (const PureQuadStitchIdentity &left :
         lhs.canonicalAuthoritativeCycle) {
      for (const PureQuadStitchIdentity &right :
           rhs.canonicalAuthoritativeCycle) {
        if (left == right) {
          return true;
        }
      }
    }
    return false;
  };

  const auto conflicts_overlap = [&](const FrontierCandidate &lhs,
                                     const FrontierCandidate &rhs) {
    if (exact_set_overlap(lhs.affectedPatches, rhs.affectedPatches) ||
        exact_set_overlap(lhs.candidate.halfedges,
                          rhs.candidate.halfedges)) {
      return true;
    }
    const std::array<const SurfaceCellCompletedFaceOwnerIdentity *, 2>
        leftOwners{{&lhs.conflict.firstOwner, &lhs.conflict.secondOwner}};
    const std::array<const SurfaceCellCompletedFaceOwnerIdentity *, 2>
        rightOwners{{&rhs.conflict.firstOwner, &rhs.conflict.secondOwner}};
    for (const auto *left : leftOwners) {
      for (const auto *right : rightOwners) {
        if (left->domain.same_undirected_support(right->domain) ||
            (left->domain.same_source_ownership(right->domain) &&
             left->domain.sourceSupport.valid &&
             right->domain.sourceSupport.valid &&
             left->domain.sourceSupport == right->domain.sourceSupport) ||
            owner_corner_overlap(*left, *right)) {
          return true;
        }
      }
    }
    return false;
  };

  while (!current.success) {
    std::vector<SurfaceCellOwnershipConflict> before =
        current.assembly.ownershipConflicts;
    if (before.empty() && current.assembly.ownershipConflict.active()) {
      before.push_back(current.assembly.ownershipConflict);
    }
    std::sort(before.begin(), before.end());
    before.erase(std::unique(before.begin(), before.end()), before.end());

    if (!current.hasPreparedComplex || before.empty()) {
      return finalize(std::move(current));
    }
    if (std::any_of(before.begin(), before.end(),
                    [](const SurfaceCellOwnershipConflict &conflict) {
                      return conflict.classification !=
                             SurfaceCellOwnershipConflictClass::
                                 SameCornerDistinctBoundaryClaim;
                    })) {
      return finalize(std::move(current));
    }
    const auto state =
        patch_descriptor_detail::canonical_repair_state_identity(
            current.preparedComplex, F, before);
    if (ledger.visitedStates.count(state) != 0U) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RepeatedState;
      break;
    }
    if (static_cast<int>(ledger.visitedStates.size()) >=
        ledger.visitedStateBudget) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::VisitedStateBudget;
      break;
    }
    ledger.visitedStates.insert(state);

    std::vector<FrontierCandidate> frontier;
    std::set<SurfaceCellCanonicalIdentity> candidateIdentities;
    bool invalidFrontier = false;
    for (const SurfaceCellOwnershipConflict &conflict : before) {
      const auto candidateSet =
          patch_descriptor_detail::same_corner_route_candidates(
              current.preparedComplex, conflict, F);
      ledger.routeCandidateCount +=
          static_cast<int>(candidateSet.candidates.size());
      if (candidateSet.semanticOverlap || candidateSet.incompleteRoute ||
          candidateSet.candidates.empty()) {
        ledger.exhaustionReason = candidateSet.semanticOverlap
            ? SurfaceCellStructuralRepairExhaustionReason::OwnershipOverlap
            : candidateSet.incompleteRoute
                  ? SurfaceCellStructuralRepairExhaustionReason::IncompleteRoute
                  : SurfaceCellStructuralRepairExhaustionReason::
                        NoRouteCompleteCandidate;
        if (candidateSet.semanticOverlap) {
          current.failure =
              "SameCornerDistinctBoundaryOverlap:" +
              current.assembly.failure;
          current.assembly.failure = current.failure;
        }
        invalidFrontier = true;
        break;
      }
      const auto &candidate = candidateSet.candidates.front();
      if (!candidateIdentities.insert(candidate.identity).second) {
        continue;
      }
      FrontierCandidate entry;
      entry.conflict = conflict;
      entry.candidate = candidate;
      entry.affectedPatches =
          patch_descriptor_detail::affected_patches_for_halfedges(
              current.preparedComplex, candidate.halfedges);
      entry.affectedPatches.insert(entry.affectedPatches.end(),
                                   candidate.patches.begin(),
                                   candidate.patches.end());
      std::sort(entry.affectedPatches.begin(), entry.affectedPatches.end());
      entry.affectedPatches.erase(
          std::unique(entry.affectedPatches.begin(),
                      entry.affectedPatches.end()),
          entry.affectedPatches.end());
      frontier.push_back(std::move(entry));
    }
    if (invalidFrontier || frontier.empty()) {
      break;
    }
    std::vector<int> parent(frontier.size());
    std::iota(parent.begin(), parent.end(), 0);
    const auto findRoot = [&](int value, const auto &self) -> int {
      if (parent[static_cast<std::size_t>(value)] == value) {
        return value;
      }
      parent[static_cast<std::size_t>(value)] =
          self(parent[static_cast<std::size_t>(value)], self);
      return parent[static_cast<std::size_t>(value)];
    };
    for (int lhs = 0; lhs < static_cast<int>(frontier.size()); ++lhs) {
      for (int rhs = lhs + 1; rhs < static_cast<int>(frontier.size()); ++rhs) {
        if (!conflicts_overlap(frontier[static_cast<std::size_t>(lhs)],
                               frontier[static_cast<std::size_t>(rhs)])) {
          continue;
        }
        const int leftRoot = findRoot(lhs, findRoot);
        const int rightRoot = findRoot(rhs, findRoot);
        if (leftRoot != rightRoot) {
          parent[static_cast<std::size_t>(rightRoot)] = leftRoot;
        }
      }
    }
    std::set<int> components;
    for (int index = 0; index < static_cast<int>(frontier.size()); ++index) {
      components.insert(findRoot(index, findRoot));
    }
    ledger.conflictComponentCount = static_cast<int>(components.size());
    ledger.independentComponentCount = ledger.conflictComponentCount;

    // The candidate budget bounds evaluated atomic frontier transactions, not
    // the number of exact claims or route intervals carried by one batch.
    // Partitioning happens first so diagnostics retain the complete topology-
    // derived frontier even when the next transaction is rejected.
    if (ledger.candidatesConsumed + 1 > ledger.candidateBudget) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::CandidateBudget;
      break;
    }
    if (ledger.structuralAttempts >= ledger.structuralAttemptBudget) {
      ledger.exhaustionReason = SurfaceCellStructuralRepairExhaustionReason::
          StructuralAttemptBudget;
      break;
    }
    if (ledger.incrementalRecomputationPasses +
            ledger.fullRecomputationPasses >=
        ledger.fullPassBudget) {
      ledger.exhaustionReason = SurfaceCellStructuralRepairExhaustionReason::
          FullRecomputationBudget;
      break;
    }

    std::map<int, int> routeInsertions;
    std::vector<int> allAffectedPatches;
    std::vector<std::uint64_t> routeHashes;
    for (const FrontierCandidate &entry : frontier) {
      for (const int halfedge : entry.candidate.halfedges) {
        routeInsertions.emplace(halfedge, 1);
      }
      allAffectedPatches.insert(allAffectedPatches.end(),
                                entry.affectedPatches.begin(),
                                entry.affectedPatches.end());
      routeHashes.push_back(
          patch_descriptor_detail::exact_identity_hash(entry.candidate.identity));
    }
    std::sort(allAffectedPatches.begin(), allAffectedPatches.end());
    allAffectedPatches.erase(
        std::unique(allAffectedPatches.begin(), allAffectedPatches.end()),
        allAffectedPatches.end());
    std::sort(routeHashes.begin(), routeHashes.end());

    if (routeInsertions.empty()) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::NoCandidate;
      break;
    }
    const int requiredInsertions = static_cast<int>(routeInsertions.size());
    if (ledger.insertedVertexBudget >= 0 &&
        ledger.insertedVertices + requiredInsertions >
            ledger.insertedVertexBudget) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::InsertedVertexBudget;
      break;
    }

    ++ledger.structuralAttempts;
    ++ledger.candidatesConsumed;
    SurfaceCellOwnershipRepairAttempt attempt;
    attempt.action =
        SurfaceCellOwnershipRepairAction::RouteCompleteBoundarySubdivision;
    attempt.conflictClass = before.front().classification;
    attempt.firstPatch = before.front().firstPatch;
    attempt.secondPatch = before.front().secondPatch;
    attempt.selectedPatch = allAffectedPatches.empty()
                                ? -1
                                : allAffectedPatches.front();
    for (const auto &[halfedge, count] : routeInsertions) {
      (void)count;
      attempt.selectedHalfedges.push_back(halfedge);
    }
    attempt.selectedHalfedge = attempt.selectedHalfedges.empty()
                                   ? -1
                                   : attempt.selectedHalfedges.front();
    attempt.routeCandidateCount = ledger.routeCandidateCount;
    attempt.routeIntervalCount = requiredInsertions;
    std::uint64_t batchedRouteHash = 1469598103934665603ULL;
    for (const std::uint64_t routeHash : routeHashes) {
      batchedRouteHash ^= routeHash;
      batchedRouteHash *= 1099511628211ULL;
    }
    attempt.routeIdentityHash =
        routeHashes.empty() ? 0U : batchedRouteHash;
    attempt.candidateEvaluation = ledger.candidatesConsumed;
    attempt.structuralAttempt = ledger.structuralAttempts;
    attempt.fullRecomputationPass = ledger.fullRecomputationPasses;
    attempt.globalInsertedVerticesBefore = ledger.insertedVertices;
    attempt.affectedPatches = allAffectedPatches;
    attempt.preConflictCount = static_cast<int>(before.size());
    attempt.preConflictInventoryHash =
        patch_descriptor_detail::conflict_inventory_hash(before);
    attempt.rollbackOwnedBytes =
        patch_descriptor_detail::estimated_complex_owned_bytes(
            current.preparedComplex);
    ledger.rollbackOwnedBytes = attempt.rollbackOwnedBytes;
    ledger.preConflictCount = attempt.preConflictCount;
    ledger.preConflictInventoryHash = attempt.preConflictInventoryHash;
    ledger.conflictFrontierOwnedBytes =
        static_cast<std::uint64_t>(before.capacity()) *
        sizeof(SurfaceCellOwnershipConflict);

    SurfaceCellSubdivisionResult subdivision =
        subdivide_surface_cell_complex_edges(current.preparedComplex,
                                             routeInsertions);
    std::optional<SurfaceCellSubdivisionProduct> subdivisionProduct;
    std::optional<SurfaceCellSubdivisionFailure> subdivisionFailure;
    bool subdivisionNotApplicable = false;
    std::visit(
        [&](auto &&outcome) {
          using Outcome = std::decay_t<decltype(outcome)>;
          if constexpr (std::is_same_v<Outcome, NotApplicable>) {
            subdivisionNotApplicable = true;
          } else if constexpr (
              std::is_same_v<Outcome,
                             Produced<SurfaceCellSubdivisionProduct>>) {
            subdivisionProduct = std::move(outcome.product);
          } else {
            subdivisionFailure = std::move(outcome.failure);
          }
        },
        std::move(subdivision).outcome());
    if (subdivisionNotApplicable) {
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::SubdivisionFailed;
      attempt.failure =
          "GlobalOwnershipFrontierSubdivision:UnexpectedNotApplicable";
      aggregateAttempts.push_back(std::move(attempt));
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RouteValidationFailed;
      break;
    }
    if (subdivisionFailure.has_value()) {
      attempt.insertedVertices = subdivisionFailure->insertedVertices;
      attempt.splitUndirectedEdges = subdivisionFailure->splitUndirectedEdges;
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::SubdivisionFailed;
      attempt.failure = "GlobalOwnershipFrontierSubdivision:" +
                        subdivisionFailure->detail;
      aggregateAttempts.push_back(std::move(attempt));
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RouteValidationFailed;
      break;
    }
    if (!subdivisionProduct.has_value()) {
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::SubdivisionFailed;
      attempt.failure = "GlobalOwnershipFrontierSubdivision:MissingOutcome";
      aggregateAttempts.push_back(std::move(attempt));
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RouteValidationFailed;
      break;
    }
    attempt.insertedVertices = subdivisionProduct->insertedVertices;
    attempt.splitUndirectedEdges = subdivisionProduct->splitUndirectedEdges;
    if (subdivisionProduct->insertedVertices != requiredInsertions ||
        subdivisionProduct->splitUndirectedEdges != requiredInsertions) {
      attempt.outcome =
          SurfaceCellOwnershipRepairOutcome::RouteValidationFailed;
      attempt.failure = "GlobalOwnershipFrontierSubdivisionIncomplete";
      aggregateAttempts.push_back(std::move(attempt));
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RouteValidationFailed;
      break;
    }

    patch_descriptor_detail::ReusableCompletionProducts cache =
        patch_descriptor_detail::take_reusable_completion_products(current);
    ledger.productCacheOwnedBytes = cache.ownedBytes;

    ledger.insertedVertices += subdivisionProduct->insertedVertices;
    attempt.globalInsertedVerticesAfter = ledger.insertedVertices;
    ledger.currentLiveCandidateComplexes = 1;
    ledger.peakLiveCandidateComplexes =
        std::max(ledger.peakLiveCandidateComplexes,
                 ledger.currentLiveCandidateComplexes);
    attempt.liveCandidateComplexes = 1;
    ledger.candidateOwnedBytes =
        patch_descriptor_detail::estimated_complex_owned_bytes(
            subdivisionProduct->complex);
    attempt.candidateOwnedBytes = ledger.candidateOwnedBytes;
    ledger.currentStructuralOwnedBytes =
        ledger.rollbackOwnedBytes + ledger.candidateOwnedBytes +
        ledger.productCacheOwnedBytes + ledger.conflictFrontierOwnedBytes;
    ledger.peakStructuralOwnedBytes =
        std::max(ledger.peakStructuralOwnedBytes,
                 ledger.currentStructuralOwnedBytes);

    patch_descriptor_detail::SurfaceCellComplexCompletionDraft candidateResult =
        patch_descriptor_detail::complete_surface_cell_complex_pass(
            std::move(subdivisionProduct->complex), V, F, options, &cache);
    ++ledger.incrementalRecomputationPasses;
    ledger.currentLiveCandidateComplexes = 0;
    subdivisionProduct->complex = {};

    ledger.reusedPatchCompletions +=
        candidateResult.completionOwnershipReusedPatchCompletions;
    ledger.recomputedPatchCompletions +=
        candidateResult.completionOwnershipRecomputedPatchCompletions;
    ledger.productCacheHashMisses +=
        candidateResult.completionOwnershipProductCacheHashMisses;
    ledger.productCacheExactMismatches +=
        candidateResult.completionOwnershipProductCacheExactMismatches;
    attempt.reusedPatchCompletions =
        candidateResult.completionOwnershipReusedPatchCompletions;
    attempt.recomputedPatchCompletions =
        candidateResult.completionOwnershipRecomputedPatchCompletions;
    ledger.descriptorOwnedBytes =
        patch_descriptor_detail::estimated_descriptor_owned_bytes(
            candidateResult.descriptors);
    ledger.completedPatchOwnedBytes =
        patch_descriptor_detail::estimated_completed_patches_owned_bytes(
            candidateResult.completedPatches);
    ledger.assemblyOwnedBytes =
        patch_descriptor_detail::estimated_mesh_owned_bytes(
            candidateResult.assembly.mesh) +
        candidateResult.assembly.estimatedWorkspaceOwnedBytes;
    ledger.currentStructuralOwnedBytes =
        ledger.rollbackOwnedBytes + ledger.candidateOwnedBytes +
        ledger.descriptorOwnedBytes + ledger.completedPatchOwnedBytes +
        ledger.assemblyOwnedBytes + ledger.conflictFrontierOwnedBytes;
    ledger.peakStructuralOwnedBytes =
        std::max(ledger.peakStructuralOwnedBytes,
                 ledger.currentStructuralOwnedBytes);
    attempt.descriptorOwnedBytes = ledger.descriptorOwnedBytes;
    attempt.completedPatchOwnedBytes = ledger.completedPatchOwnedBytes;
    attempt.assemblyOwnedBytes = ledger.assemblyOwnedBytes;
    attempt.totalStructuralOwnedBytes = ledger.currentStructuralOwnedBytes;
    attempt.completionSucceeded = candidateResult.success;
    attempt.resultingConflictClass =
        candidateResult.assembly.ownershipConflict.classification;

    std::vector<SurfaceCellOwnershipConflict> after =
        candidateResult.assembly.ownershipConflicts;
    if (after.empty() &&
        candidateResult.assembly.ownershipConflict.active()) {
      after.push_back(candidateResult.assembly.ownershipConflict);
    }
    std::sort(after.begin(), after.end());
    after.erase(std::unique(after.begin(), after.end()), after.end());
    const auto difference =
        patch_descriptor_detail::compare_conflict_inventories(before, after);
    attempt.postConflictCount = static_cast<int>(after.size());
    attempt.retainedConflictCount = difference.retained;
    attempt.removedConflictCount = difference.removed;
    attempt.introducedConflictCount = difference.introduced;
    attempt.postConflictInventoryHash =
        patch_descriptor_detail::conflict_inventory_hash(after);
    attempt.introducedOwnershipClaim = difference.introduced != 0;
    ledger.postConflictCount = attempt.postConflictCount;
    ledger.retainedConflictCount = difference.retained;
    ledger.removedConflictCount = difference.removed;
    ledger.introducedConflictCount = difference.introduced;
    ledger.postConflictInventoryHash = attempt.postConflictInventoryHash;

    if (candidateResult.success) {
      attempt.madeProgress = true;
      attempt.committed = true;
      attempt.outcome =
          SurfaceCellOwnershipRepairOutcome::AssemblySucceeded;
      aggregateAttempts.push_back(std::move(attempt));
      mergePassEvidence(candidateResult);
      return finalize(std::move(candidateResult));
    }

    if (difference.introduced != 0) {
      attempt.outcome =
          SurfaceCellOwnershipRepairOutcome::IntroducedOwnershipClaim;
      attempt.failure = "GlobalOwnershipFrontierIntroducedClaim:" +
                        candidateResult.assembly.failure;
      aggregateAttempts.push_back(std::move(attempt));
      mergePassEvidence(candidateResult);
      candidateResult.failure = aggregateAttempts.back().failure;
      candidateResult.assembly.failure = candidateResult.failure;
      ledger.exhaustionReason = SurfaceCellStructuralRepairExhaustionReason::
          IntroducedOwnershipClaim;
      candidateResult.failureKind =
          SurfaceCellComplexCompletionFailureKind::StructuralRepairExhausted;
      return finalize(std::move(candidateResult));
    }
    if (!difference.strictReduction) {
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::NoProgress;
      attempt.failure = "GlobalOwnershipFrontierNoProgress:" +
                        candidateResult.assembly.failure;
      aggregateAttempts.push_back(std::move(attempt));
      mergePassEvidence(candidateResult);
      candidateResult.failure = aggregateAttempts.back().failure;
      candidateResult.assembly.failure = candidateResult.failure;
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::NoProgress;
      candidateResult.failureKind =
          SurfaceCellComplexCompletionFailureKind::StructuralRepairExhausted;
      return finalize(std::move(candidateResult));
    }

    attempt.madeProgress = true;
    attempt.committed = true;
    attempt.outcome = difference.retained > 0
        ? SurfaceCellOwnershipRepairOutcome::LatentClaimExposed
        : SurfaceCellOwnershipRepairOutcome::StrictConflictReduction;
    aggregateAttempts.push_back(std::move(attempt));
    mergePassEvidence(candidateResult);
    current = std::move(candidateResult);
  }

  if (ledger.exhaustionReason ==
      SurfaceCellStructuralRepairExhaustionReason::None) {
    ledger.exhaustionReason =
        SurfaceCellStructuralRepairExhaustionReason::NoCandidate;
  }
  if (current.failure.rfind("SameCornerDistinctBoundaryOverlap:", 0) != 0U) {
    current.failure =
        std::string("SameCornerStructuralRepairExhausted:") +
        surface_cell_structural_repair_exhaustion_reason_name(
            ledger.exhaustionReason) +
        ":" + current.assembly.failure;
    current.assembly.failure = current.failure;
  }
  current.failureKind =
      SurfaceCellComplexCompletionFailureKind::StructuralRepairExhausted;
  patch_descriptor_detail::release_rejected_completion_storage(current);
  return finalize(std::move(current));
}

} // namespace directional::geometry
