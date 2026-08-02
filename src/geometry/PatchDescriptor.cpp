#include <directional/geometry/PatchDescriptor.h>

namespace directional::geometry::patch_descriptor_detail {

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
  point.face = node.sourceFace;
  point.component = edge.sourceComponent;
  point.sheet = edge.sourceSheet;
  point.barycentric = node.barycentric.transpose();
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
    if (edge.railId >= 0) {
      side.railIds.insert(edge.railId);
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

void append_identity(std::vector<std::int64_t> &destination,
                     const SurfaceCellCanonicalIdentity &identity) {
  destination.push_back(static_cast<std::int64_t>(identity.values.size()));
  destination.insert(destination.end(), identity.values.begin(),
                     identity.values.end());
}

SurfaceCellCanonicalIdentity source_point_identity(
    const Eigen::MatrixXi &F, const int face,
    const Eigen::RowVector3d &barycentric, const int component,
    const int sheet) {
  SurfaceCellCanonicalIdentity result;
  if (face < 0 || face >= F.rows() || F.cols() != 3 ||
      !barycentric.allFinite()) {
    return result;
  }
  std::vector<std::pair<int, std::int64_t>> weights;
  weights.reserve(3);
  for (int corner = 0; corner < 3; ++corner) {
    weights.emplace_back(F(face, corner),
                         quantized_parameter(barycentric[corner]));
  }
  std::sort(weights.begin(), weights.end());
  result.valid = true;
  result.values = {component, sheet};
  for (const auto &[vertex, weight] : weights) {
    result.values.push_back(vertex);
    result.values.push_back(weight);
  }
  return result;
}

SurfaceCellCanonicalIdentity arrangement_node_identity(
    const SurfaceArrangementNode &node, const Eigen::MatrixXi &F,
    const int component, const int sheet) {
  std::vector<SurfaceCellCanonicalIdentity> occurrences;
  occurrences.push_back(
      source_point_identity(F, node.sourceFace, node.barycentric, component,
                            sheet));
  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
    occurrences.push_back(source_point_identity(
        F, occurrence.sourceFace, occurrence.barycentric, component, sheet));
  }
  occurrences.erase(
      std::remove_if(occurrences.begin(), occurrences.end(),
                     [](const SurfaceCellCanonicalIdentity &identity) {
                       return !identity.valid;
                     }),
      occurrences.end());
  std::sort(occurrences.begin(), occurrences.end());
  occurrences.erase(std::unique(occurrences.begin(), occurrences.end()),
                    occurrences.end());

  SurfaceCellCanonicalIdentity result;
  if (occurrences.empty()) {
    return result;
  }
  result.valid = true;
  result.values = {component, sheet,
                   static_cast<std::int64_t>(occurrences.size())};
  for (const SurfaceCellCanonicalIdentity &occurrence : occurrences) {
    append_identity(result.values, occurrence);
  }
  return result;
}

std::vector<std::int64_t> provenance_semantics(
    const SurfaceArrangementProvenance &provenance) {
  return {
      provenance.family,
      provenance.featureClass,
      provenance.hardFeature ? 1 : 0,
      provenance.layoutSupport ? 1 : 0,
      provenance.singularitySupport ? 1 : 0,
      provenance.railId,
      provenance.curveId,
      provenance.sourceComponent,
      provenance.sourceSheet,
      provenance.proposalSide,
      provenance.proposalBoundarySegment,
      quantized_parameter(std::min(provenance.sourceT0,
                                   provenance.sourceT1)),
      quantized_parameter(std::max(provenance.sourceT0,
                                   provenance.sourceT1)),
      quantized_parameter(std::min(provenance.railT0,
                                   provenance.railT1)),
      quantized_parameter(std::max(provenance.railT0,
                                   provenance.railT1)),
  };
}

std::vector<std::int64_t> halfedge_identity(
    const SurfaceCellComplex &complex,
    const SurfaceArrangementHalfedge &edge, const Eigen::MatrixXi &F,
    const bool directed) {
  const SurfaceArrangementNode *from = find_node(complex, edge.from);
  const SurfaceArrangementNode *to = find_node(complex, edge.to);
  if (from == nullptr || to == nullptr) {
    return {};
  }
  SurfaceCellCanonicalIdentity fromIdentity = arrangement_node_identity(
      *from, F, edge.sourceComponent, edge.sourceSheet);
  SurfaceCellCanonicalIdentity toIdentity = arrangement_node_identity(
      *to, F, edge.sourceComponent, edge.sourceSheet);
  if (!fromIdentity.valid || !toIdentity.valid) {
    return {};
  }
  if (!directed && toIdentity < fromIdentity) {
    std::swap(fromIdentity, toIdentity);
  }

  std::vector<std::vector<std::int64_t>> provenance;
  provenance.reserve(edge.provenance.size());
  for (const SurfaceArrangementProvenance &entry : edge.provenance) {
    provenance.push_back(provenance_semantics(entry));
  }
  std::sort(provenance.begin(), provenance.end());

  std::vector<std::int64_t> result;
  append_identity(result, fromIdentity);
  append_identity(result, toIdentity);
  result.insert(result.end(),
                {edge.family,
                 edge.featureClass,
                 edge.hardFeature ? 1 : 0,
                 edge.layoutSupport ? 1 : 0,
                 edge.singularitySupport ? 1 : 0,
                 edge.railId,
                 edge.curveId,
                 edge.sourceComponent,
                 edge.sourceSheet,
                 edge.proposalSide,
                 edge.proposalBoundarySegment});
  if (directed) {
    result.push_back(quantized_parameter(edge.sourceT0));
    result.push_back(quantized_parameter(edge.sourceT1));
    result.push_back(quantized_parameter(edge.railT0));
    result.push_back(quantized_parameter(edge.railT1));
  } else {
    result.push_back(quantized_parameter(
        std::min(edge.sourceT0, edge.sourceT1)));
    result.push_back(quantized_parameter(
        std::max(edge.sourceT0, edge.sourceT1)));
    result.push_back(
        quantized_parameter(std::min(edge.railT0, edge.railT1)));
    result.push_back(
        quantized_parameter(std::max(edge.railT0, edge.railT1)));
  }
  result.push_back(static_cast<std::int64_t>(provenance.size()));
  for (const std::vector<std::int64_t> &entry : provenance) {
    result.push_back(static_cast<std::int64_t>(entry.size()));
    result.insert(result.end(), entry.begin(), entry.end());
  }
  return result;
}

std::vector<std::vector<std::int64_t>> canonical_cycle_rotation(
    const std::vector<std::vector<std::int64_t>> &cycle) {
  if (cycle.empty()) {
    return {};
  }
  std::vector<std::vector<std::int64_t>> best;
  for (std::size_t start = 0; start < cycle.size(); ++start) {
    std::vector<std::vector<std::int64_t>> candidate;
    candidate.reserve(cycle.size());
    for (std::size_t offset = 0; offset < cycle.size(); ++offset) {
      candidate.push_back(cycle[(start + offset) % cycle.size()]);
    }
    if (best.empty() || candidate < best) {
      best = std::move(candidate);
    }
  }
  return best;
}

SurfaceCellCanonicalIdentity flatten_identities(
    const std::vector<std::vector<std::int64_t>> &identities) {
  SurfaceCellCanonicalIdentity result;
  if (identities.empty()) {
    return result;
  }
  result.valid = true;
  result.values.push_back(static_cast<std::int64_t>(identities.size()));
  for (const std::vector<std::int64_t> &identity : identities) {
    result.values.push_back(static_cast<std::int64_t>(identity.size()));
    result.values.insert(result.values.end(), identity.begin(), identity.end());
  }
  return result;
}

SurfaceCellCanonicalIdentity source_support_identity(
    const SurfaceArrangementCell &cell, const Eigen::MatrixXi &F) {
  std::vector<std::vector<std::int64_t>> faces;
  std::vector<int> sourceFaces = cell.sourceFaces;
  if (sourceFaces.empty() && cell.sourceFace >= 0) {
    sourceFaces.push_back(cell.sourceFace);
  }
  for (const int face : sourceFaces) {
    if (face < 0 || face >= F.rows() || F.cols() != 3) {
      return {};
    }
    std::vector<std::int64_t> vertices = {
        F(face, 0), F(face, 1), F(face, 2)};
    std::sort(vertices.begin(), vertices.end());
    faces.push_back(std::move(vertices));
  }
  std::sort(faces.begin(), faces.end());
  faces.erase(std::unique(faces.begin(), faces.end()), faces.end());
  return flatten_identities(faces);
}

SurfaceCellDomainIdentity build_domain_identity(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::vector<int> &boundary, const Eigen::MatrixXi &F) {
  SurfaceCellDomainIdentity result;
  if (boundary.empty()) {
    return result;
  }
  std::vector<std::vector<std::int64_t>> directed;
  std::vector<std::vector<std::int64_t>> undirected;
  std::set<int> components;
  std::set<int> sheets;
  for (const int halfedgeId : boundary) {
    if (halfedgeId < 0 ||
        halfedgeId >= static_cast<int>(complex.halfedges.size())) {
      return {};
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    std::vector<std::int64_t> directedIdentity =
        halfedge_identity(complex, edge, F, true);
    std::vector<std::int64_t> undirectedIdentity =
        halfedge_identity(complex, edge, F, false);
    if (directedIdentity.empty() || undirectedIdentity.empty()) {
      return {};
    }
    directed.push_back(std::move(directedIdentity));
    undirected.push_back(std::move(undirectedIdentity));
    components.insert(edge.sourceComponent);
    sheets.insert(edge.sourceSheet);
  }
  std::sort(undirected.begin(), undirected.end());
  result.orientedBoundary =
      flatten_identities(canonical_cycle_rotation(directed));
  result.undirectedBoundary = flatten_identities(undirected);
  result.sourceSupport = source_support_identity(cell, F);
  result.sourceComponent =
      components.size() == 1U ? *components.begin() : -2;
  result.sourceSheet = sheets.size() == 1U ? *sheets.begin() : -2;
  result.valid = result.orientedBoundary.valid &&
                 result.undirectedBoundary.valid &&
                 result.sourceSupport.valid;
  return result;
}

} // namespace directional::geometry::patch_descriptor_detail

namespace directional::geometry {

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
      descriptor.feasibility = check_pure_quad_patch_admissibility(patch);
      return descriptor;
    }
    patch.boundaryVertices.push_back(node->id);
    patch.boundaryRailIds.push_back(edge.railId);
    patch.boundaryCurveIds.push_back(edge.curveId);
    patch.boundaryComponents.push_back(edge.sourceComponent);
    patch.boundarySheets.push_back(edge.sourceSheet);
    patch.boundaryNodeIdentities.push_back(
        patch_descriptor_detail::arrangement_node_identity(
            *node, F, edge.sourceComponent, edge.sourceSheet));
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

  patch.domainIdentity = patch_descriptor_detail::build_domain_identity(
      complex, cell, boundary, F);
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
    if (descriptor.feasibility.admissible) {
      ++result.feasible;
    } else {
      ++result.rejected;
    }
    result.descriptors.push_back(std::move(descriptor));
  }

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
      std::tuple<int, int, SurfaceCellCanonicalIdentity,
                 SurfaceCellCanonicalIdentity>;
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
      result.ownershipConflict.firstComponent =
          first.patch.domainIdentity.sourceComponent;
      result.ownershipConflict.firstSheet =
          first.patch.domainIdentity.sourceSheet;
      result.ownershipConflict.secondComponent = identity.sourceComponent;
      result.ownershipConflict.secondSheet = identity.sourceSheet;
      break;
    }

    const UndirectedOwnerKey key{
        identity.sourceComponent, identity.sourceSheet,
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
      result.ownershipConflict.firstComponent =
          first.patch.domainIdentity.sourceComponent;
      result.ownershipConflict.firstSheet =
          first.patch.domainIdentity.sourceSheet;
      result.ownershipConflict.secondComponent = identity.sourceComponent;
      result.ownershipConflict.secondSheet = identity.sourceSheet;
      break;
    }
  }
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

SurfaceCellComplexCompletionResult complete_surface_cell_complex(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options) {
  SurfaceCellComplexCompletionResult result;
  const SurfaceCellParityRepairResult parityRepair =
      repair_surface_cell_boundary_parity(complex);
  result.parityOddCellsBefore = parityRepair.oddCellsBefore;
  result.parityOddCellsAfter = parityRepair.oddCellsAfter;
  result.paritySplitEdges =
      static_cast<int>(parityRepair.splitHalfedges.size());
  result.parityHardFeatureSplits = parityRepair.hardFeatureSplits;
  if (!parityRepair.success) {
    result.failure = "BoundaryParityRepair:" + parityRepair.failure;
    result.assembly.failure = result.failure;
    return result;
  }
  const SurfaceCellSideRepairResult sideRepair =
      repair_surface_cell_side_subdivisions(parityRepair.complex, V, F);
  result.sideInfeasibleCellsBefore = sideRepair.infeasibleCellsBefore;
  result.sideInfeasibleCellsAfter = sideRepair.infeasibleCellsAfter;
  result.sideInitialEquationDefect = sideRepair.initialEquationDefect;
  result.sideFinalEquationDefect = sideRepair.finalEquationDefect;
  result.sidePropagationPasses = sideRepair.propagationPasses;
  result.sideAttemptedInsertions = sideRepair.attemptedInsertions;
  result.sideInsertedVertices = sideRepair.insertedVertices;
  result.sideSplitEdges = sideRepair.splitUndirectedEdges;
  result.sideHardFeatureSplits = sideRepair.hardFeatureSplits;
  const bool mayUseGeneralFallback =
      options.allowBoundedCombinatorialFallback &&
      (sideRepair.failure == "CoupledSideRepairStalled" ||
       sideRepair.failure == "SideRepairInsertionLimit" ||
       sideRepair.failure == "SideRepairPropagationLimit" ||
       sideRepair.failure == "LocalSideInsertionLimit");
  if (!sideRepair.success && !mayUseGeneralFallback) {
    result.failure = "SideSubdivisionRepair:" + sideRepair.failure;
    result.assembly.failure = result.failure;
    return result;
  }
  if (sideRepair.success) {
    result.preparedComplex = sideRepair.complex;
  } else {
    // The simple closed-form equations are a regularity condition, not a
    // necessary condition for an even disk patch. If their coupled global
    // subdivision solve cannot converge, retain the last committed parity
    // complex and route only the strict inequality/parity rejections to the
    // bounded general-pattern backend. Never expose the uncommitted greedy
    // insertion trial as repaired topology.
    result.preparedComplex = parityRepair.complex;
    result.sideInfeasibleCellsAfter = result.sideInfeasibleCellsBefore;
    result.sideFinalEquationDefect = result.sideInitialEquationDefect;
    result.sideInsertedVertices = 0;
    result.sideSplitEdges = 0;
    result.sideHardFeatureSplits = 0;
  }
  result.hasPreparedComplex = true;
  const SurfaceCellComplex &prepared = result.preparedComplex;
  result.descriptors = derive_patch_descriptors(
      prepared, V, F, options.descriptorOptions);
  if (result.descriptors.descriptors.empty()) {
    result.failure = "NoPatchDescriptors";
    result.assembly.failure = result.failure;
    return result;
  }
  if (result.descriptors.ownershipConflict.active()) {
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
    result.assembly.failure = result.failure;
    return result;
  }
  if (result.descriptors.ownershipConflict.active()) {
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
    result.assembly.failure = result.failure;
    return result;
  }
  if (!result.descriptors.unresolvedSingularVertices.empty()) {
    result.failure = "UnresolvedSingularityOwnership";
    result.assembly.failure = result.failure;
    return result;
  }
  for (const PatchDescriptor &descriptor : result.descriptors.descriptors) {
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
      continue;
    }
    ++result.attemptedPatches;
    PureQuadCompletionOptions completionOptions;
    completionOptions.sourcePatch = descriptor.cellId;
    completionOptions.maxBoundaryEdges = options.maxBoundaryEdges;
    completionOptions.allowBoundedCombinatorialFallback =
        options.allowBoundedCombinatorialFallback;
    completionOptions.sourceVertices = &V;
    completionOptions.sourceFaces = &F;
    completionOptions.sourceFaceComponents = options.sourceFaceComponents;
    completionOptions.sourceFaceSheets = options.sourceFaceSheets;
    const PureQuadCompletionResult completion =
        complete_pure_quad_patch(descriptor.patch, completionOptions);
    if (!completion.success || completion.mesh.quads.empty()) {
      ++result.failedPatches;
      continue;
    }
    result.completedPatches.push_back(completion.mesh);
  }
  if (result.failedPatches != 0 ||
      result.completedPatches.size() != result.descriptors.descriptors.size()) {
    result.failure = "IncompleteSurfaceCellComplex";
    result.assembly.failure = result.failure;
    return result;
  }
  result.assembly = stitch_pure_quad_patches(result.completedPatches);
  result.success = result.assembly.success;
  if (!result.success) {
    result.failure = result.assembly.failure;
  }
  return result;
}

} // namespace directional::geometry
