#include <directional/geometry/PatchDescriptor.h>

#include <iterator>

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
  result.boundaryNodeCount = static_cast<int>(boundary.size());
  result.boundaryHalfedgeCount = static_cast<int>(boundary.size());
  result.sourceSupportCount = source_support_count(cell, F);
  result.sourceComponent =
      components.size() == 1U ? *components.begin() : -2;
  result.sourceSheet = sheets.size() == 1U ? *sheets.begin() : -2;
  result.valid = result.orientedBoundary.valid &&
                 result.undirectedBoundary.valid &&
                 result.sourceSupport.valid;
  return result;
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
    return 3;
  case PureQuadCompletionBackend::Pattern:
  case PureQuadCompletionBackend::BoundedCombinatorial:
    return std::max(1, static_cast<int>(patch.boundaryVertices.size()));
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
  std::vector<std::vector<std::int64_t>> boundaryIdentities;
  std::vector<std::vector<std::int64_t>> geometricSupportIdentities;
  std::vector<std::int64_t> endpointIdentity;
  std::vector<std::int64_t> exactIdentity;
  std::vector<std::int64_t> geometricIdentity;
};

struct SameCornerRouteCandidate {
  // Coupled route-sector candidates sort before individual route candidates.
  // This is a topology-derived all-sector transaction, not an arbitrary subset.
  int priority = 1;
  bool hardFeature = false;
  std::vector<int> patches;
  std::vector<int> halfedges;
  std::vector<std::uint64_t> sharedCornerIdentityHashes;
  std::vector<std::int64_t> identity;

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

std::vector<std::int64_t> source_face_geometry_identity(
    const Eigen::MatrixXi &F, const int face) {
  if (face < 0 || face >= F.rows() || F.cols() != 3) {
    return {};
  }
  std::array<int, 3> vertices{{F(face, 0), F(face, 1), F(face, 2)}};
  std::sort(vertices.begin(), vertices.end());
  return {vertices[0], vertices[1], vertices[2]};
}

std::vector<std::int64_t> halfedge_geometric_support_identity(
    const SurfaceCellComplex &complex,
    const SurfaceArrangementHalfedge &edge, const Eigen::MatrixXi &F) {
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
  if (toIdentity < fromIdentity) {
    std::swap(fromIdentity, toIdentity);
  }

  // Geometric support deliberately excludes rail/curve/proposal labels.  It
  // retains source-triangle vertex identities and interval parameters so two
  // chart aliases of the same embedded interval compare equal while genuinely
  // different routes through the source triangulation remain distinct.  Face
  // row numbers are never serialized, preserving source-row invariance.
  std::vector<std::vector<std::int64_t>> support;
  const auto appendSupport = [&](const int sourceFace, const double t0,
                                 const double t1) {
    std::vector<std::int64_t> item =
        source_face_geometry_identity(F, sourceFace);
    if (item.empty()) {
      return;
    }
    item.push_back(quantized_parameter(std::min(t0, t1)));
    item.push_back(quantized_parameter(std::max(t0, t1)));
    support.push_back(std::move(item));
  };
  appendSupport(edge.sourceFace, edge.sourceT0, edge.sourceT1);
  for (const SurfaceArrangementProvenance &entry : edge.provenance) {
    appendSupport(entry.sourceFace, entry.sourceT0, entry.sourceT1);
  }
  std::sort(support.begin(), support.end());
  support.erase(std::unique(support.begin(), support.end()), support.end());

  std::vector<std::int64_t> result{edge.sourceComponent, edge.sourceSheet};
  append_identity(result, fromIdentity);
  append_identity(result, toIdentity);
  result.push_back(static_cast<std::int64_t>(support.size()));
  for (const auto &item : support) {
    result.push_back(static_cast<std::int64_t>(item.size()));
    result.insert(result.end(), item.begin(), item.end());
  }
  return result;
}

SurfaceCellCanonicalIdentity boundary_node_identity(
    const SurfaceCellComplex &complex, const int halfedgeId,
    const Eigen::MatrixXi &F) {
  SurfaceCellCanonicalIdentity result;
  if (halfedgeId < 0 ||
      halfedgeId >= static_cast<int>(complex.halfedges.size())) {
    return result;
  }
  const SurfaceArrangementHalfedge &edge =
      complex.halfedges[static_cast<std::size_t>(halfedgeId)];
  const SurfaceArrangementNode *node = find_node(complex, edge.from);
  if (node == nullptr) {
    return result;
  }
  return arrangement_node_identity(*node, F, edge.sourceComponent,
                                   edge.sourceSheet);
}

std::vector<std::int64_t> endpoint_pair_identity(
    SurfaceCellCanonicalIdentity first, SurfaceCellCanonicalIdentity second) {
  if (!first.valid || !second.valid || first == second) {
    return {};
  }
  if (second < first) {
    std::swap(first, second);
  }
  std::vector<std::int64_t> result;
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
    SurfaceCellCanonicalIdentity identity =
        boundary_node_identity(complex, boundary[static_cast<std::size_t>(index)],
                               F);
    if (!identity.valid) {
      incomplete = true;
      return {};
    }
    nodeIdentities.push_back(identity);
    if (sharedCorners.count(identity) != 0U) {
      anchors.push_back(index);
    }
  }
  if (anchors.size() < 2U) {
    incomplete = true;
    return {};
  }

  std::vector<SameCornerBoundaryRoute> routes;
  routes.reserve(anchors.size());
  for (int anchor = 0; anchor < static_cast<int>(anchors.size()); ++anchor) {
    const int begin = anchors[static_cast<std::size_t>(anchor)];
    const int end = anchors[static_cast<std::size_t>(
        (anchor + 1) % static_cast<int>(anchors.size()))];
    SameCornerBoundaryRoute route;
    route.patch = cell.id;
    route.firstCorner = nodeIdentities[static_cast<std::size_t>(begin)];
    route.secondCorner = nodeIdentities[static_cast<std::size_t>(end)];
    route.endpointIdentity =
        endpoint_pair_identity(route.firstCorner, route.secondCorner);
    if (route.endpointIdentity.empty()) {
      incomplete = true;
      return {};
    }

    int cursor = begin;
    do {
      const int directedHalfedge = boundary[static_cast<std::size_t>(cursor)];
      const int canonical =
          canonical_complex_halfedge(complex, directedHalfedge);
      if (canonical < 0 ||
          canonical >= static_cast<int>(complex.halfedges.size())) {
        incomplete = true;
        return {};
      }
      const SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(canonical)];
      const SurfaceArrangementHalfedge &twin =
          complex.halfedges[static_cast<std::size_t>(edge.twin)];
      std::vector<std::int64_t> boundaryIdentity =
          halfedge_identity(complex, edge, F, false);
      std::vector<std::int64_t> geometricIdentity =
          halfedge_geometric_support_identity(complex, edge, F);
      if (boundaryIdentity.empty() || geometricIdentity.empty()) {
        incomplete = true;
        return {};
      }
      route.halfedges.push_back(canonical);
      route.boundaryIdentities.push_back(std::move(boundaryIdentity));
      route.geometricSupportIdentities.push_back(
          std::move(geometricIdentity));
      route.hardFeature = route.hardFeature || edge.hardFeature ||
                          twin.hardFeature;
      cursor = (cursor + 1) % static_cast<int>(boundary.size());
    } while (cursor != end);

    // Normalize route orientation by exact authoritative endpoint identity.
    if (route.secondCorner < route.firstCorner) {
      std::swap(route.firstCorner, route.secondCorner);
      std::reverse(route.halfedges.begin(), route.halfedges.end());
      std::reverse(route.boundaryIdentities.begin(),
                   route.boundaryIdentities.end());
      std::reverse(route.geometricSupportIdentities.begin(),
                   route.geometricSupportIdentities.end());
    }

    route.exactIdentity = route.endpointIdentity;
    route.exactIdentity.push_back(
        static_cast<std::int64_t>(route.boundaryIdentities.size()));
    for (const auto &identity : route.boundaryIdentities) {
      route.exactIdentity.push_back(
          static_cast<std::int64_t>(identity.size()));
      route.exactIdentity.insert(route.exactIdentity.end(), identity.begin(),
                                 identity.end());
    }
    route.geometricIdentity = route.endpointIdentity;
    route.geometricIdentity.push_back(
        static_cast<std::int64_t>(route.geometricSupportIdentities.size()));
    for (const auto &identity : route.geometricSupportIdentities) {
      route.geometricIdentity.push_back(
          static_cast<std::int64_t>(identity.size()));
      route.geometricIdentity.insert(route.geometricIdentity.end(),
                                     identity.begin(), identity.end());
    }
    routes.push_back(std::move(route));
  }
  return routes;
}

SameCornerRouteCandidateSet same_corner_route_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceCellOwnershipConflict &conflict,
    const Eigen::MatrixXi &F) {
  SameCornerRouteCandidateSet result;
  const SurfaceArrangementCell *first =
      find_cell_by_id(complex, conflict.firstPatch);
  const SurfaceArrangementCell *second =
      find_cell_by_id(complex, conflict.secondPatch);
  if (first == nullptr || second == nullptr) {
    result.incompleteRoute = true;
    return result;
  }

  const auto boundaryNodeSet = [&](const SurfaceArrangementCell &cell) {
    std::set<SurfaceCellCanonicalIdentity> identities;
    std::vector<int> boundary;
    if (!ordered_boundary(complex, cell, boundary)) {
      return identities;
    }
    for (const int halfedge : boundary) {
      SurfaceCellCanonicalIdentity identity =
          boundary_node_identity(complex, halfedge, F);
      if (!identity.valid) {
        identities.clear();
        return identities;
      }
      identities.insert(std::move(identity));
    }
    return identities;
  };

  const std::set<SurfaceCellCanonicalIdentity> firstNodes =
      boundaryNodeSet(*first);
  const std::set<SurfaceCellCanonicalIdentity> secondNodes =
      boundaryNodeSet(*second);
  if (firstNodes.empty() || secondNodes.empty()) {
    result.incompleteRoute = true;
    return result;
  }
  std::set<SurfaceCellCanonicalIdentity> sharedCorners;
  std::set_intersection(firstNodes.begin(), firstNodes.end(),
                        secondNodes.begin(), secondNodes.end(),
                        std::inserter(sharedCorners, sharedCorners.end()));
  if (sharedCorners.size() < 2U) {
    result.incompleteRoute = true;
    return result;
  }

  bool incomplete = false;
  const std::vector<SameCornerBoundaryRoute> firstRoutes =
      boundary_routes_between_shared_corners(complex, *first, F,
                                             sharedCorners, incomplete);
  const std::vector<SameCornerBoundaryRoute> secondRoutes =
      boundary_routes_between_shared_corners(complex, *second, F,
                                             sharedCorners, incomplete);
  if (incomplete || firstRoutes.empty() || secondRoutes.empty()) {
    result.incompleteRoute = true;
    return result;
  }

  std::map<std::vector<std::int64_t>, std::vector<SameCornerBoundaryRoute>>
      firstByEndpoints;
  std::map<std::vector<std::int64_t>, std::vector<SameCornerBoundaryRoute>>
      secondByEndpoints;
  for (const SameCornerBoundaryRoute &route : firstRoutes) {
    firstByEndpoints[route.endpointIdentity].push_back(route);
  }
  for (const SameCornerBoundaryRoute &route : secondRoutes) {
    secondByEndpoints[route.endpointIdentity].push_back(route);
  }

  for (auto &[endpoint, routes] : firstByEndpoints) {
    auto secondIt = secondByEndpoints.find(endpoint);
    if (secondIt == secondByEndpoints.end()) {
      continue;
    }
    auto &otherRoutes = secondIt->second;
    const auto routeLess = [](const SameCornerBoundaryRoute &lhs,
                              const SameCornerBoundaryRoute &rhs) {
      return std::tie(lhs.exactIdentity, lhs.geometricIdentity, lhs.patch,
                      lhs.halfedges) <
             std::tie(rhs.exactIdentity, rhs.geometricIdentity, rhs.patch,
                      rhs.halfedges);
    };
    std::sort(routes.begin(), routes.end(), routeLess);
    std::sort(otherRoutes.begin(), otherRoutes.end(), routeLess);
    if (routes.size() != otherRoutes.size()) {
      result.incompleteRoute = true;
      continue;
    }
    for (std::size_t routeIndex = 0; routeIndex < routes.size(); ++routeIndex) {
      const SameCornerBoundaryRoute &a = routes[routeIndex];
      const SameCornerBoundaryRoute &b = otherRoutes[routeIndex];
      if (a.exactIdentity == b.exactIdentity) {
        continue;
      }
      if (a.geometricIdentity == b.geometricIdentity) {
        result.semanticOverlap = true;
        continue;
      }

      std::map<std::vector<std::int64_t>, int> aIntervals;
      std::map<std::vector<std::int64_t>, int> bIntervals;
      for (std::size_t index = 0; index < a.boundaryIdentities.size(); ++index) {
        aIntervals.emplace(a.boundaryIdentities[index], a.halfedges[index]);
      }
      for (std::size_t index = 0; index < b.boundaryIdentities.size(); ++index) {
        bIntervals.emplace(b.boundaryIdentities[index], b.halfedges[index]);
      }
      std::vector<std::pair<std::vector<std::int64_t>, int>> intervals;
      for (const auto &[identity, halfedge] : aIntervals) {
        if (bIntervals.count(identity) == 0U) {
          intervals.emplace_back(identity, halfedge);
        }
      }
      for (const auto &[identity, halfedge] : bIntervals) {
        if (aIntervals.count(identity) == 0U) {
          intervals.emplace_back(identity, halfedge);
        }
      }
      std::sort(intervals.begin(), intervals.end(),
                [](const auto &lhs, const auto &rhs) {
                  return std::tie(lhs.first, lhs.second) <
                         std::tie(rhs.first, rhs.second);
                });
      intervals.erase(std::unique(intervals.begin(), intervals.end(),
                                  [](const auto &lhs, const auto &rhs) {
                                    return lhs.second == rhs.second;
                                  }),
                      intervals.end());
      if (intervals.empty()) {
        result.incompleteRoute = true;
        continue;
      }

      SameCornerRouteCandidate candidate;
      candidate.hardFeature = a.hardFeature || b.hardFeature;
      candidate.patches = {a.patch, b.patch};
      std::sort(candidate.patches.begin(), candidate.patches.end());
      candidate.patches.erase(
          std::unique(candidate.patches.begin(), candidate.patches.end()),
          candidate.patches.end());
      candidate.sharedCornerIdentityHashes = {
          a.firstCorner.hash(), a.secondCorner.hash()};
      std::sort(candidate.sharedCornerIdentityHashes.begin(),
                candidate.sharedCornerIdentityHashes.end());
      for (const auto &[identity, halfedge] : intervals) {
        (void)identity;
        candidate.halfedges.push_back(halfedge);
      }
      candidate.identity = endpoint;
      std::array<std::vector<std::int64_t>, 2> routeIdentities{
          a.exactIdentity, b.exactIdentity};
      if (routeIdentities[1] < routeIdentities[0]) {
        std::swap(routeIdentities[0], routeIdentities[1]);
      }
      for (const auto &identity : routeIdentities) {
        candidate.identity.push_back(
            static_cast<std::int64_t>(identity.size()));
        candidate.identity.insert(candidate.identity.end(), identity.begin(),
                                  identity.end());
      }
      candidate.identity.push_back(
          static_cast<std::int64_t>(intervals.size()));
      for (const auto &[identity, halfedge] : intervals) {
        (void)halfedge;
        candidate.identity.push_back(
            static_cast<std::int64_t>(identity.size()));
        candidate.identity.insert(candidate.identity.end(), identity.begin(),
                                  identity.end());
      }
      result.candidates.push_back(std::move(candidate));
    }
  }

  // When more than one differing route sector belongs to the same ownership
  // claim, evaluate their union atomically before any individual sector.  A
  // single-sector split can merely move the duplicate claim to an adjacent
  // sector; the all-sector transaction is the unique topology-derived coupled
  // candidate and does not enumerate a powerset.
  if (result.candidates.size() > 1U) {
    SameCornerRouteCandidate coupled;
    coupled.priority = 0;
    coupled.identity = {-1, static_cast<std::int64_t>(result.candidates.size())};
    for (const SameCornerRouteCandidate &candidate : result.candidates) {
      coupled.hardFeature = coupled.hardFeature || candidate.hardFeature;
      coupled.patches.insert(coupled.patches.end(), candidate.patches.begin(),
                             candidate.patches.end());
      coupled.halfedges.insert(coupled.halfedges.end(),
                               candidate.halfedges.begin(),
                               candidate.halfedges.end());
      coupled.sharedCornerIdentityHashes.insert(
          coupled.sharedCornerIdentityHashes.end(),
          candidate.sharedCornerIdentityHashes.begin(),
          candidate.sharedCornerIdentityHashes.end());
      coupled.identity.push_back(
          static_cast<std::int64_t>(candidate.identity.size()));
      coupled.identity.insert(coupled.identity.end(), candidate.identity.begin(),
                              candidate.identity.end());
    }
    std::sort(coupled.patches.begin(), coupled.patches.end());
    coupled.patches.erase(
        std::unique(coupled.patches.begin(), coupled.patches.end()),
        coupled.patches.end());
    std::sort(coupled.halfedges.begin(), coupled.halfedges.end());
    coupled.halfedges.erase(
        std::unique(coupled.halfedges.begin(), coupled.halfedges.end()),
        coupled.halfedges.end());
    std::sort(coupled.sharedCornerIdentityHashes.begin(),
              coupled.sharedCornerIdentityHashes.end());
    coupled.sharedCornerIdentityHashes.erase(
        std::unique(coupled.sharedCornerIdentityHashes.begin(),
                    coupled.sharedCornerIdentityHashes.end()),
        coupled.sharedCornerIdentityHashes.end());
    result.candidates.push_back(std::move(coupled));
  }

  std::sort(result.candidates.begin(), result.candidates.end());
  result.candidates.erase(
      std::unique(result.candidates.begin(), result.candidates.end(),
                  [](const SameCornerRouteCandidate &lhs,
                     const SameCornerRouteCandidate &rhs) {
                    return lhs.identity == rhs.identity;
                  }),
      result.candidates.end());
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

void append_repair_identity(std::vector<std::int64_t> &destination,
                            const SurfaceCellCanonicalIdentity &identity) {
  destination.push_back(identity.valid ? 1 : 0);
  destination.push_back(static_cast<std::int64_t>(identity.values.size()));
  destination.insert(destination.end(), identity.values.begin(),
                     identity.values.end());
}

void append_repair_domain_identity(
    std::vector<std::int64_t> &destination,
    const SurfaceCellDomainIdentity &identity) {
  destination.push_back(identity.valid ? 1 : 0);
  destination.push_back(identity.boundaryNodeCount);
  destination.push_back(identity.boundaryHalfedgeCount);
  destination.push_back(identity.sourceSupportCount);
  destination.push_back(identity.sourceComponent);
  destination.push_back(identity.sourceSheet);
  append_repair_identity(destination, identity.orientedBoundary);
  append_repair_identity(destination, identity.undirectedBoundary);
  append_repair_identity(destination, identity.sourceSupport);
}

void append_repair_conflict_identity(
    std::vector<std::int64_t> &destination,
    const SurfaceCellOwnershipConflict &conflict) {
  destination.push_back(static_cast<int>(conflict.classification));
  const auto ownerIdentity = [&](const bool first) {
    std::vector<std::int64_t> owner;
    owner.push_back(first ? conflict.firstPatch : conflict.secondPatch);
    owner.push_back(first ? conflict.firstLocalQuad : conflict.secondLocalQuad);
    owner.push_back(first ? conflict.firstBoundaryNodeCount
                          : conflict.secondBoundaryNodeCount);
    owner.push_back(first ? conflict.firstBoundaryHalfedgeCount
                          : conflict.secondBoundaryHalfedgeCount);
    owner.push_back(first ? conflict.firstBoundaryVertexCount
                          : conflict.secondBoundaryVertexCount);
    owner.push_back(first ? conflict.firstComponent : conflict.secondComponent);
    owner.push_back(first ? conflict.firstSheet : conflict.secondSheet);
    owner.push_back(first ? conflict.firstCompletionBackend
                          : conflict.secondCompletionBackend);
    owner.push_back(first ? conflict.firstCompletionVariant
                          : conflict.secondCompletionVariant);
    const auto &cornerKinds = first ? conflict.firstCornerIdentityKinds
                                    : conflict.secondCornerIdentityKinds;
    const auto &cornerHashes = first ? conflict.firstCornerIdentityHashes
                                     : conflict.secondCornerIdentityHashes;
    const auto &authoritativeHashes =
        first ? conflict.firstCornerAuthoritativeHashes
              : conflict.secondCornerAuthoritativeHashes;
    for (const int value : cornerKinds) {
      owner.push_back(value);
    }
    for (const std::uint64_t value : cornerHashes) {
      owner.push_back(static_cast<std::int64_t>(value));
    }
    for (const std::uint64_t value : authoritativeHashes) {
      owner.push_back(static_cast<std::int64_t>(value));
    }
    return owner;
  };
  std::array<std::vector<std::int64_t>, 2> owners{
      ownerIdentity(true), ownerIdentity(false)};
  if (owners[1] < owners[0]) {
    std::swap(owners[0], owners[1]);
  }
  for (const auto &owner : owners) {
    destination.push_back(static_cast<std::int64_t>(owner.size()));
    destination.insert(destination.end(), owner.begin(), owner.end());
  }
}


using SurfaceCellRepairStateIdentity = std::vector<std::int64_t>;

SurfaceCellRepairStateIdentity canonical_repair_state_identity(
    const SurfaceCellComplex &complex, const Eigen::MatrixXi &F,
    const std::vector<SurfaceCellOwnershipConflict> &conflicts) {
  SurfaceCellRepairStateIdentity identity;
  identity.reserve(complex.nodes.size() * 12U +
                   complex.halfedges.size() * 7U +
                   complex.cells.size() * 16U);
  identity.push_back(static_cast<std::int64_t>(complex.nodes.size()));
  identity.push_back(static_cast<std::int64_t>(complex.halfedges.size()));
  identity.push_back(static_cast<std::int64_t>(complex.cells.size()));

  std::vector<const SurfaceArrangementNode *> nodes;
  nodes.reserve(complex.nodes.size());
  for (const SurfaceArrangementNode &node : complex.nodes) {
    nodes.push_back(&node);
  }
  std::sort(nodes.begin(), nodes.end(),
            [](const SurfaceArrangementNode *lhs,
               const SurfaceArrangementNode *rhs) {
              return lhs->id < rhs->id;
            });
  for (const SurfaceArrangementNode *node : nodes) {
    identity.insert(identity.end(),
                    {node->id, node->sourceFace, node->sourceComponent,
                     node->sourceSheet, node->sourceEdge,
                     quantized_parameter(node->sourceEdgeParameter),
                     quantized_parameter(node->barycentric(0)),
                     quantized_parameter(node->barycentric(1)),
                     quantized_parameter(node->barycentric(2))});
    std::vector<std::array<std::int64_t, 4>> occurrences;
    occurrences.reserve(node->occurrences.size());
    for (const SurfaceArrangementNodeOccurrence &occurrence :
         node->occurrences) {
      occurrences.push_back(
          {occurrence.sourceFace,
           quantized_parameter(occurrence.barycentric(0)),
           quantized_parameter(occurrence.barycentric(1)),
           quantized_parameter(occurrence.barycentric(2))});
    }
    std::sort(occurrences.begin(), occurrences.end());
    identity.push_back(static_cast<std::int64_t>(occurrences.size()));
    for (const auto &occurrence : occurrences) {
      identity.insert(identity.end(), occurrence.begin(), occurrence.end());
    }
  }

  std::vector<const SurfaceArrangementHalfedge *> halfedges;
  halfedges.reserve(complex.halfedges.size());
  for (const SurfaceArrangementHalfedge &edge : complex.halfedges) {
    halfedges.push_back(&edge);
  }
  std::sort(halfedges.begin(), halfedges.end(),
            [](const SurfaceArrangementHalfedge *lhs,
               const SurfaceArrangementHalfedge *rhs) {
              return lhs->id < rhs->id;
            });
  for (const SurfaceArrangementHalfedge *edge : halfedges) {
    identity.insert(identity.end(),
                    {edge->id, edge->twin, edge->next, edge->from, edge->to,
                     edge->cell});
  }

  std::vector<const SurfaceArrangementCell *> cells;
  cells.reserve(complex.cells.size());
  for (const SurfaceArrangementCell &cell : complex.cells) {
    cells.push_back(&cell);
  }
  std::sort(cells.begin(), cells.end(),
            [](const SurfaceArrangementCell *lhs,
               const SurfaceArrangementCell *rhs) {
              return lhs->id < rhs->id;
            });
  for (const SurfaceArrangementCell *cell : cells) {
    std::vector<int> boundary;
    const bool boundaryValid = ordered_boundary(complex, *cell, boundary);
    identity.insert(identity.end(),
                    {cell->id, cell->sourceFace,
                     cell->boundaryCycle ? 1 : 0, cell->closed ? 1 : 0,
                     cell->disk ? 1 : 0,
                     static_cast<int>(cell->cellClass),
                     static_cast<int>(cell->rejectReason),
                     boundaryValid ? 1 : 0});
    std::vector<int> sourceFaces = cell->sourceFaces;
    std::sort(sourceFaces.begin(), sourceFaces.end());
    sourceFaces.erase(std::unique(sourceFaces.begin(), sourceFaces.end()),
                      sourceFaces.end());
    identity.push_back(static_cast<std::int64_t>(sourceFaces.size()));
    identity.insert(identity.end(), sourceFaces.begin(), sourceFaces.end());
    if (boundaryValid) {
      append_repair_domain_identity(
          identity, build_domain_identity(complex, *cell, boundary, F));
    } else {
      identity.push_back(static_cast<std::int64_t>(cell->halfedges.size()));
      identity.insert(identity.end(), cell->halfedges.begin(),
                      cell->halfedges.end());
    }
  }
  identity.push_back(static_cast<std::int64_t>(conflicts.size()));
  for (const SurfaceCellOwnershipConflict &conflict : conflicts) {
    append_repair_conflict_identity(identity, conflict);
  }
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
    const std::vector<std::int64_t> &identity) {
  SurfaceCellCanonicalIdentity canonical;
  canonical.valid = !identity.empty();
  canonical.values = identity;
  return canonical.hash();
}

std::uint64_t estimated_complex_owned_bytes(
    const SurfaceCellComplex &complex) {
  std::uint64_t bytes = sizeof(SurfaceCellComplex);
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
    bytes += static_cast<std::uint64_t>(cell.sourceFaces.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.halfedges.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.sideFamilies.capacity()) *
             sizeof(int);
    bytes += static_cast<std::uint64_t>(cell.sideEdgeCounts.capacity()) *
             sizeof(int);
  }
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
           sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.boundaryCurveIds.capacity()) *
           sizeof(int);
  bytes += static_cast<std::uint64_t>(patch.sourceFaces.capacity()) *
           sizeof(int);
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
    SurfaceCellComplexCompletionResult &result) {
  result.completedPatches.clear();
  result.completedPatches.shrink_to_fit();
  result.descriptors.descriptors.clear();
  result.descriptors.descriptors.shrink_to_fit();
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
      result.ownershipConflict.firstSourceSupportCount =
          first.patch.domainIdentity.sourceSupportCount;
      result.ownershipConflict.secondSourceSupportCount =
          identity.sourceSupportCount;
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
      result.ownershipConflict.firstSourceSupportCount =
          first.patch.domainIdentity.sourceSupportCount;
      result.ownershipConflict.secondSourceSupportCount =
          identity.sourceSupportCount;
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

namespace directional::geometry::patch_descriptor_detail {

bool exact_surface_point_equal(const SurfacePoint &lhs,
                               const SurfacePoint &rhs) {
  return lhs.face == rhs.face && lhs.component == rhs.component &&
         lhs.sheet == rhs.sheet &&
         (lhs.barycentric.array() == rhs.barycentric.array()).all() &&
         (lhs.position.array() == rhs.position.array()).all() &&
         lhs.squaredDistance == rhs.squaredDistance;
}

bool exact_surface_point_vector_equal(const std::vector<SurfacePoint> &lhs,
                                      const std::vector<SurfacePoint> &rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (std::size_t index = 0; index < lhs.size(); ++index) {
    if (!exact_surface_point_equal(lhs[index], rhs[index])) {
      return false;
    }
  }
  return true;
}

bool exact_patch_side_equal(const PatchSideDescriptor &lhs,
                            const PatchSideDescriptor &rhs) {
  // Halfedge and arrangement-node ids are allocation-local. Exact completion
  // reuse is keyed by the authoritative ordered rail/curve support and the
  // resulting subdivision signature instead of incidental rebuilt indices.
  return lhs.family == rhs.family &&
         lhs.halfedges.size() == rhs.halfedges.size() &&
         lhs.boundaryVertices.size() == rhs.boundaryVertices.size() &&
         lhs.subdivisionCount == rhs.subdivisionCount &&
         lhs.hardFeature == rhs.hardFeature && lhs.railIds == rhs.railIds &&
         lhs.curveIds == rhs.curveIds;
}

bool exact_patch_dependency_equal(const PatchDescriptor &lhs,
                                  const PatchDescriptor &rhs) {
  const PureQuadPatch &a = lhs.patch;
  const PureQuadPatch &b = rhs.patch;
  if (lhs.cellId != rhs.cellId ||
      lhs.feasibility.admissible != rhs.feasibility.admissible ||
      lhs.feasibility.reason != rhs.feasibility.reason ||
      lhs.feasibility.expectedInteriorValence !=
          rhs.feasibility.expectedInteriorValence ||
      lhs.singularSourceVertices != rhs.singularSourceVertices ||
      lhs.singularNumerators != rhs.singularNumerators ||
      lhs.boundaryCycleValid != rhs.boundaryCycleValid ||
      lhs.featureConstraintsValid != rhs.featureConstraintsValid ||
      lhs.sides.size() != rhs.sides.size() ||
      a.boundaryVertices.size() != b.boundaryVertices.size() ||
      !exact_surface_point_vector_equal(a.boundaryProvenance,
                                        b.boundaryProvenance) ||
      a.boundaryRailIds != b.boundaryRailIds ||
      a.boundaryCurveIds != b.boundaryCurveIds ||
      a.boundaryComponents != b.boundaryComponents ||
      a.boundarySheets != b.boundarySheets ||
      a.boundaryNodeIdentities != b.boundaryNodeIdentities ||
      a.domainIdentity != b.domainIdentity ||
      a.sideEdgeCounts != b.sideEdgeCounts || a.turns != b.turns ||
      a.sourceFaces != b.sourceFaces ||
      a.boundaryLoopCount != b.boundaryLoopCount ||
      a.diskTopology != b.diskTopology ||
      a.hardFeatureCrossing != b.hardFeatureCrossing ||
      a.singularityCount != b.singularityCount ||
      a.singularIndexNumerator != b.singularIndexNumerator ||
      a.unmatchedInteriorSingularity != b.unmatchedInteriorSingularity ||
      a.simple != b.simple) {
    return false;
  }
  for (std::size_t index = 0; index < lhs.sides.size(); ++index) {
    if (!exact_patch_side_equal(lhs.sides[index], rhs.sides[index])) {
      return false;
    }
  }
  return true;
}

struct CachedCompletionProduct {
  PatchDescriptor descriptor;
  PureQuadMesh mesh;
};

struct ReusableCompletionProducts {
  std::map<int, CachedCompletionProduct> products;
  std::uint64_t ownedBytes = 0U;
};

ReusableCompletionProducts take_reusable_completion_products(
    SurfaceCellComplexCompletionResult &result) {
  ReusableCompletionProducts cache;
  std::map<int, PureQuadMesh> meshes;
  for (PureQuadMesh &mesh : result.completedPatches) {
    meshes.emplace(mesh.sourcePatch, std::move(mesh));
  }
  for (PatchDescriptor &descriptor : result.descriptors.descriptors) {
    const auto mesh = meshes.find(descriptor.cellId);
    if (mesh == meshes.end()) {
      continue;
    }
    CachedCompletionProduct product;
    product.descriptor = std::move(descriptor);
    product.mesh = std::move(mesh->second);
    cache.products.emplace(product.descriptor.cellId, std::move(product));
  }
  result.completedPatches.clear();
  result.completedPatches.shrink_to_fit();
  result.descriptors.descriptors.clear();
  result.descriptors.descriptors.shrink_to_fit();
  result.assembly.mesh = {};
  for (const auto &[cell, product] : cache.products) {
    (void)cell;
    cache.ownedBytes += sizeof(PatchDescriptor) +
                        estimated_descriptor_payload_owned_bytes(
                            product.descriptor);
    cache.ownedBytes += estimated_mesh_owned_bytes(product.mesh);
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

SurfaceCellComplexCompletionResult complete_surface_cell_complex_pass(
    SurfaceCellComplex complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options,
    ReusableCompletionProducts *reusableProducts = nullptr) {
  SurfaceCellComplexCompletionResult result;
  const SurfacePointSourceSupportResolver sourceSupportResolver(F);
  SurfaceCellParityRepairResult parityRepair =
      repair_surface_cell_boundary_parity(std::move(complex));
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
  SurfaceCellSideRepairResult sideRepair =
      repair_surface_cell_side_subdivisions(std::move(parityRepair.complex),
                                            V, F);
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
    result.preparedComplex = std::move(sideRepair.complex);
  } else {
    // The simple closed-form equations are a regularity condition, not a
    // necessary condition for an even disk patch. If their coupled global
    // subdivision solve cannot converge, use the unmodified canonical
    // parity-repaired complex returned by the transaction. This preserves
    // fail-closed rollback without holding a second full complex in memory.
    result.preparedComplex = std::move(sideRepair.complex);
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
  if (!result.descriptors.unresolvedSingularVertices.empty()) {
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
    completionOptions.sourceFaceComponents = options.sourceFaceComponents;
    completionOptions.sourceFaceSheets = options.sourceFaceSheets;
    return complete_pure_quad_patch(descriptor.patch, completionOptions);
  };

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
      continue;
    }
    ++result.attemptedPatches;
    if (reusableProducts != nullptr) {
      const auto cached = reusableProducts->products.find(descriptor.cellId);
      if (cached != reusableProducts->products.end() &&
          exact_patch_dependency_equal(descriptor,
                                       cached->second.descriptor)) {
        result.completedPatches.push_back(std::move(cached->second.mesh));
        reusableProducts->products.erase(cached);
        ++result.completionOwnershipReusedPatchCompletions;
        continue;
      }
    }
    ++result.completionOwnershipRecomputedPatchCompletions;
    PureQuadCompletionResult completion =
        completeDescriptor(descriptorIndex, 0);
    if (!completion.success || completion.mesh.quads.empty()) {
      ++result.failedPatches;
      if (!result.firstCompletionOwnershipRejection.active &&
          completion.ownershipRejection.active) {
        result.firstCompletionOwnershipRejection =
            completion.ownershipRejection;
      }
      if (result.failure.empty() && !completion.failure.empty()) {
        result.failure = completion.failure;
      }
      continue;
    }
    result.completedPatches.push_back(std::move(completion.mesh));
  }
  if (result.failedPatches != 0 ||
      result.completedPatches.size() != result.descriptors.descriptors.size()) {
    if (result.failure.empty()) {
      result.failure = "IncompleteSurfaceCellComplex";
    }
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

  result.assembly = stitch_pure_quad_patches(result.completedPatches);
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
            alternative.success && !alternative.mesh.quads.empty();
        if (!attempt.completionSucceeded) {
          attempt.outcome =
              SurfaceCellOwnershipRepairOutcome::ValidationFailed;
          attempt.failure = alternative.failure.empty()
                                ? "CompletionVariantUnavailable"
                                : alternative.failure;
          if (!result.firstCompletionOwnershipRejection.active &&
              alternative.ownershipRejection.active) {
            result.firstCompletionOwnershipRejection =
                alternative.ownershipRejection;
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
        currentMesh = std::move(alternative.mesh);
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
        stitch_pure_quad_patches(result.completedPatches);
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
      if (!previous.success || previous.mesh.quads.empty()) {
        rollbackSucceeded = false;
      } else {
        result.completedPatches[static_cast<std::size_t>(
            change->descriptorIndex)] = std::move(previous.mesh);
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
      [&](SurfaceCellComplexCompletionResult &pass) {
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
        if (!firstOwnershipRejection.active &&
            pass.firstCompletionOwnershipRejection.active) {
          firstOwnershipRejection = pass.firstCompletionOwnershipRejection;
        }
      };

  const auto finalize = [&](SurfaceCellComplexCompletionResult pass) {
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
    pass.completionOwnershipStructuralExhaustionReason =
        ledger.exhaustionReason;
    pass.ownershipRepairAttempts = std::move(aggregateAttempts);
    if (!pass.firstCompletionOwnershipRejection.active &&
        firstOwnershipRejection.active) {
      pass.firstCompletionOwnershipRejection = firstOwnershipRejection;
    }
    patch_descriptor_detail::renumber_ownership_repair_attempts(
        pass.ownershipRepairAttempts);
    return pass;
  };

  SurfaceCellComplexCompletionResult current =
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
            (left->domain.sourceComponent == right->domain.sourceComponent &&
             left->domain.sourceSheet == right->domain.sourceSheet &&
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
    std::set<std::vector<std::int64_t>> candidateIdentities;
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
    attempt.insertedVertices = subdivision.insertedVertices;
    attempt.splitUndirectedEdges = subdivision.splitUndirectedEdges;
    if (!subdivision.success ||
        subdivision.insertedVertices != requiredInsertions ||
        subdivision.splitUndirectedEdges != requiredInsertions) {
      attempt.outcome = subdivision.success
          ? SurfaceCellOwnershipRepairOutcome::RouteValidationFailed
          : SurfaceCellOwnershipRepairOutcome::SubdivisionFailed;
      attempt.failure = subdivision.success
          ? "GlobalOwnershipFrontierSubdivisionIncomplete"
          : "GlobalOwnershipFrontierSubdivision:" + subdivision.failure;
      aggregateAttempts.push_back(std::move(attempt));
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RouteValidationFailed;
      break;
    }

    patch_descriptor_detail::ReusableCompletionProducts cache =
        patch_descriptor_detail::take_reusable_completion_products(current);
    ledger.productCacheOwnedBytes = cache.ownedBytes;

    ledger.insertedVertices += subdivision.insertedVertices;
    attempt.globalInsertedVerticesAfter = ledger.insertedVertices;
    ledger.currentLiveCandidateComplexes = 1;
    ledger.peakLiveCandidateComplexes =
        std::max(ledger.peakLiveCandidateComplexes,
                 ledger.currentLiveCandidateComplexes);
    attempt.liveCandidateComplexes = 1;
    ledger.candidateOwnedBytes =
        patch_descriptor_detail::estimated_complex_owned_bytes(
            subdivision.complex);
    attempt.candidateOwnedBytes = ledger.candidateOwnedBytes;
    ledger.currentStructuralOwnedBytes =
        ledger.rollbackOwnedBytes + ledger.candidateOwnedBytes +
        ledger.productCacheOwnedBytes + ledger.conflictFrontierOwnedBytes;
    ledger.peakStructuralOwnedBytes =
        std::max(ledger.peakStructuralOwnedBytes,
                 ledger.currentStructuralOwnedBytes);

    SurfaceCellComplexCompletionResult candidateResult =
        patch_descriptor_detail::complete_surface_cell_complex_pass(
            std::move(subdivision.complex), V, F, options, &cache);
    ++ledger.incrementalRecomputationPasses;
    ledger.currentLiveCandidateComplexes = 0;
    subdivision.complex = {};

    ledger.reusedPatchCompletions +=
        candidateResult.completionOwnershipReusedPatchCompletions;
    ledger.recomputedPatchCompletions +=
        candidateResult.completionOwnershipRecomputedPatchCompletions;
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
  current.failure =
      std::string("SameCornerStructuralRepairExhausted:") +
      surface_cell_structural_repair_exhaustion_reason_name(
          ledger.exhaustionReason) +
      ":" + current.assembly.failure;
  current.assembly.failure = current.failure;
  patch_descriptor_detail::release_rejected_completion_storage(current);
  return finalize(std::move(current));
}

} // namespace directional::geometry
