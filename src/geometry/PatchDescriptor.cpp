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

struct SameCornerBoundaryCandidate {
  int patch = -1;
  int halfedge = -1;
  bool hardFeature = false;
  std::vector<std::int64_t> boundaryIdentity;
  // Exact embedded support without rail/curve/proposal labels. If two
  // boundaries differ only in semantic labels while occupying the same source
  // interval, they are overlapping ownership, not a parallel route.
  std::vector<std::int64_t> geometricSupportIdentity;

  friend bool operator<(const SameCornerBoundaryCandidate &lhs,
                        const SameCornerBoundaryCandidate &rhs) {
    return std::tie(lhs.hardFeature, lhs.boundaryIdentity,
                    lhs.geometricSupportIdentity, lhs.patch, lhs.halfedge) <
           std::tie(rhs.hardFeature, rhs.boundaryIdentity,
                    rhs.geometricSupportIdentity, rhs.patch, rhs.halfedge);
  }
};

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

  // A single arrangement interval is geometrically determined by its exact
  // authoritative endpoints and source sheet. Face/rail/proposal labels are
  // chart or semantic metadata and cannot by themselves prove a distinct
  // embedded route. Routes with intermediate arrangement nodes naturally
  // produce different endpoint identities and remain eligible candidates.
  std::vector<std::int64_t> result{
      edge.sourceComponent, edge.sourceSheet};
  append_identity(result, fromIdentity);
  append_identity(result, toIdentity);
  return result;
}

std::map<std::vector<std::int64_t>, SameCornerBoundaryCandidate>
canonical_cell_boundary_candidates(const SurfaceCellComplex &complex,
                                   const SurfaceArrangementCell &cell,
                                   const Eigen::MatrixXi &F) {
  std::map<std::vector<std::int64_t>, SameCornerBoundaryCandidate> result;
  for (const int halfedgeId : cell.halfedges) {
    const int canonical = canonical_complex_halfedge(complex, halfedgeId);
    if (canonical < 0 ||
        canonical >= static_cast<int>(complex.halfedges.size())) {
      return {};
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(canonical)];
    if (edge.twin < 0 ||
        edge.twin >= static_cast<int>(complex.halfedges.size())) {
      return {};
    }
    std::vector<std::int64_t> identity =
        halfedge_identity(complex, edge, F, false);
    if (identity.empty()) {
      return {};
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(edge.twin)];
    SameCornerBoundaryCandidate candidate;
    candidate.patch = cell.id;
    candidate.halfedge = canonical;
    candidate.hardFeature = edge.hardFeature || twin.hardFeature;
    candidate.boundaryIdentity = identity;
    candidate.geometricSupportIdentity =
        halfedge_geometric_support_identity(complex, edge, F);
    if (candidate.geometricSupportIdentity.empty()) {
      return {};
    }
    result.emplace(std::move(identity), std::move(candidate));
  }
  return result;
}

std::vector<SameCornerBoundaryCandidate> same_corner_boundary_candidates(
    const SurfaceCellComplex &complex,
    const SurfaceCellOwnershipConflict &conflict,
    const Eigen::MatrixXi &F) {
  const SurfaceArrangementCell *first =
      find_cell_by_id(complex, conflict.firstPatch);
  const SurfaceArrangementCell *second =
      find_cell_by_id(complex, conflict.secondPatch);
  if (first == nullptr || second == nullptr) {
    return {};
  }
  const auto firstBoundary =
      canonical_cell_boundary_candidates(complex, *first, F);
  const auto secondBoundary =
      canonical_cell_boundary_candidates(complex, *second, F);
  if (firstBoundary.empty() || secondBoundary.empty()) {
    return {};
  }

  std::set<std::vector<std::int64_t>> firstGeometricSupport;
  std::set<std::vector<std::int64_t>> secondGeometricSupport;
  for (const auto &[identity, candidate] : firstBoundary) {
    (void)identity;
    firstGeometricSupport.insert(candidate.geometricSupportIdentity);
  }
  for (const auto &[identity, candidate] : secondBoundary) {
    (void)identity;
    secondGeometricSupport.insert(candidate.geometricSupportIdentity);
  }

  std::vector<SameCornerBoundaryCandidate> candidates;
  for (const auto &[identity, candidate] : firstBoundary) {
    if (secondBoundary.count(identity) == 0U &&
        secondGeometricSupport.count(candidate.geometricSupportIdentity) ==
            0U) {
      candidates.push_back(candidate);
    }
  }
  for (const auto &[identity, candidate] : secondBoundary) {
    if (firstBoundary.count(identity) == 0U &&
        firstGeometricSupport.count(candidate.geometricSupportIdentity) ==
            0U) {
      candidates.push_back(candidate);
    }
  }
  std::sort(candidates.begin(), candidates.end());
  return candidates;
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
    const SurfaceCellOwnershipConflict &conflict) {
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
  append_repair_conflict_identity(identity, conflict);
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

SurfaceCellComplexCompletionResult complete_surface_cell_complex_pass(
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options) {
  SurfaceCellComplexCompletionResult result;
  const SurfacePointSourceSupportResolver sourceSupportResolver(F);
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
    const PureQuadCompletionResult completion =
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
    result.completedPatches.push_back(completion.mesh);
  }
  if (result.failedPatches != 0 ||
      result.completedPatches.size() != result.descriptors.descriptors.size()) {
    if (result.failure.empty()) {
      result.failure = "IncompleteSurfaceCellComplex";
    }
    result.assembly.failure = result.failure;
    return result;
  }
  result.assembly = stitch_pure_quad_patches(result.completedPatches);
  while (!result.assembly.success &&
         result.assembly.ownershipConflict.classification ==
             SurfaceCellOwnershipConflictClass::CompletionTemplateOwnership &&
         result.completionOwnershipRepairAttempts <
             options.maxCompletionOwnershipRepairs) {
    const SurfaceCellOwnershipConflict conflict =
        result.assembly.ownershipConflict;
    const std::array<int, 2> candidatePatches{{conflict.secondPatch,
                                               conflict.firstPatch}};
    bool advanced = false;
    for (const int patchId : candidatePatches) {
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
      while (variant + 1 < variantCount &&
             result.completionOwnershipRepairAttempts <
                 options.maxCompletionOwnershipRepairs) {
        SurfaceCellOwnershipRepairAttempt attempt;
        attempt.action = SurfaceCellOwnershipRepairAction::CompletionVariant;
        attempt.conflictClass = conflict.classification;
        attempt.firstPatch = conflict.firstPatch;
        attempt.secondPatch = conflict.secondPatch;
        attempt.selectedPatch = patchId;
        attempt.backend = currentMesh.backend;
        attempt.fromVariant = variant;
        ++variant;
        attempt.toVariant = variant;
        ++result.completionOwnershipRepairAttempts;
        const PureQuadCompletionResult alternative =
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
        currentMesh = alternative.mesh;
        result.assembly = stitch_pure_quad_patches(result.completedPatches);
        attempt.committed = true;
        attempt.madeProgress = true;
        attempt.outcome = result.assembly.success
                              ? SurfaceCellOwnershipRepairOutcome::
                                    AssemblySucceeded
                              : SurfaceCellOwnershipRepairOutcome::Committed;
        attempt.resultingConflictClass =
            result.assembly.ownershipConflict.classification;
        if (!result.assembly.success) {
          attempt.failure = result.assembly.failure;
        }
        result.ownershipRepairAttempts.push_back(std::move(attempt));
        advanced = true;
        break;
      }
      if (advanced) {
        break;
      }
    }
    if (!advanced) {
      break;
    }
  }

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
    const SurfaceCellComplex &complex, const Eigen::MatrixXd &V,
    const Eigen::MatrixXi &F,
    const SurfaceCellComplexCompletionOptions &options) {
  struct StructuralRepairLedger {
    int candidateBudget = 0;
    int structuralAttemptBudget = 0;
    int insertedVertexBudget = 0;
    int fullPassBudget = 0;
    int visitedStateBudget = 0;
    int candidatesConsumed = 0;
    int structuralAttempts = 0;
    int insertedVertices = 0;
    int fullRecomputationPasses = 0;
    int incrementalRecomputationPasses = 0;
    int currentLiveCandidateComplexes = 0;
    int peakLiveCandidateComplexes = 0;
    SurfaceCellStructuralRepairExhaustionReason exhaustionReason =
        SurfaceCellStructuralRepairExhaustionReason::None;
    std::set<patch_descriptor_detail::SurfaceCellRepairStateIdentity>
        visitedStates;
  } ledger;

  ledger.candidateBudget =
      std::max(0, options.maxSameCornerCandidateEvaluations);
  ledger.structuralAttemptBudget =
      std::max(0, options.maxSameCornerBoundaryRepairs);
  ledger.insertedVertexBudget =
      std::max(0, options.maxSameCornerInsertedVertices);
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
    pass.completionOwnershipCurrentLiveCandidateComplexes =
        ledger.currentLiveCandidateComplexes;
    pass.completionOwnershipPeakLiveCandidateComplexes =
        ledger.peakLiveCandidateComplexes;
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
          complex, V, F, options);
  ++ledger.fullRecomputationPasses;
  mergePassEvidence(current);

  if (current.hasPreparedComplex &&
      current.assembly.ownershipConflict.active()) {
    ledger.visitedStates.insert(
        patch_descriptor_detail::canonical_repair_state_identity(
            current.preparedComplex, F, current.assembly.ownershipConflict));
  }

  if (current.success ||
      current.assembly.ownershipConflict.classification !=
          SurfaceCellOwnershipConflictClass::SameCornerDistinctBoundaryClaim) {
    return finalize(std::move(current));
  }

  const SurfaceCellOwnershipConflict originalConflict =
      current.assembly.ownershipConflict;
  const std::vector<patch_descriptor_detail::SameCornerBoundaryCandidate>
      candidates = patch_descriptor_detail::same_corner_boundary_candidates(
          current.preparedComplex, originalConflict, F);
  if (candidates.empty()) {
    ledger.exhaustionReason =
        SurfaceCellStructuralRepairExhaustionReason::OwnershipOverlap;
    current.failure = "SameCornerDistinctBoundaryOverlap:" +
                      current.assembly.failure;
    current.assembly.failure = current.failure;
    patch_descriptor_detail::release_rejected_completion_storage(current);
    return finalize(std::move(current));
  }

  // Retain one rollback snapshot (the prepared complex) and one mutable
  // candidate complex. Failed patch meshes and descriptors are not part of the
  // rollback contract and are released before candidate evaluation.
  current.completedPatches.clear();
  current.completedPatches.shrink_to_fit();
  current.descriptors.descriptors.clear();
  current.descriptors.descriptors.shrink_to_fit();
  current.assembly.mesh = {};

  bool sawRepeatedState = false;
  bool sawNoProgress = false;
  bool sawIntroducedClaim = false;
  bool sawValidationFailure = false;

  for (const patch_descriptor_detail::SameCornerBoundaryCandidate &candidate :
       candidates) {
    if (ledger.candidatesConsumed >= ledger.candidateBudget) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::CandidateBudget;
      break;
    }
    if (ledger.structuralAttempts >= ledger.structuralAttemptBudget) {
      ledger.exhaustionReason = SurfaceCellStructuralRepairExhaustionReason::
          StructuralAttemptBudget;
      break;
    }
    if (ledger.fullRecomputationPasses >= ledger.fullPassBudget) {
      ledger.exhaustionReason = SurfaceCellStructuralRepairExhaustionReason::
          FullRecomputationBudget;
      break;
    }
    if (ledger.insertedVertices >= ledger.insertedVertexBudget) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::InsertedVertexBudget;
      break;
    }

    ++ledger.candidatesConsumed;
    ++ledger.structuralAttempts;
    SurfaceCellOwnershipRepairAttempt attempt;
    attempt.action =
        SurfaceCellOwnershipRepairAction::BoundarySectorSubdivision;
    attempt.conflictClass = originalConflict.classification;
    attempt.firstPatch = originalConflict.firstPatch;
    attempt.secondPatch = originalConflict.secondPatch;
    attempt.selectedPatch = candidate.patch;
    attempt.selectedHalfedge = candidate.halfedge;
    attempt.candidateEvaluation = ledger.candidatesConsumed;
    attempt.structuralAttempt = ledger.structuralAttempts;
    attempt.fullRecomputationPass = ledger.fullRecomputationPasses + 1;
    attempt.globalInsertedVerticesBefore = ledger.insertedVertices;
    attempt.affectedPatches =
        patch_descriptor_detail::affected_patches_for_halfedge(
            current.preparedComplex, candidate.halfedge);
    current.completionOwnershipLastCandidateHalfedge = candidate.halfedge;
    current.completionOwnershipLastAffectedPatches = attempt.affectedPatches;
    const int selectedBackend =
        candidate.patch == originalConflict.firstPatch
            ? originalConflict.firstCompletionBackend
            : originalConflict.secondCompletionBackend;
    attempt.backend =
        selectedBackend >=
                    static_cast<int>(PureQuadCompletionBackend::ClosedForm) &&
                selectedBackend <= static_cast<int>(
                                       PureQuadCompletionBackend::
                                           BoundedCombinatorial)
            ? static_cast<PureQuadCompletionBackend>(selectedBackend)
            : PureQuadCompletionBackend::ClosedForm;

    SurfaceCellSubdivisionResult subdivision =
        subdivide_surface_cell_complex_edges(
            current.preparedComplex, {{candidate.halfedge, 1}});
    attempt.insertedVertices = subdivision.insertedVertices;
    attempt.splitUndirectedEdges = subdivision.splitUndirectedEdges;
    if (!subdivision.success) {
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::SubdivisionFailed;
      attempt.failure = "BoundarySectorSubdivision:" + subdivision.failure;
      attempt.globalInsertedVerticesAfter = ledger.insertedVertices;
      aggregateAttempts.push_back(std::move(attempt));
      continue;
    }
    if (ledger.insertedVertices + subdivision.insertedVertices >
        ledger.insertedVertexBudget) {
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::BudgetExhausted;
      attempt.failure = "SameCornerInsertedVertexBudget";
      attempt.globalInsertedVerticesAfter = ledger.insertedVertices;
      aggregateAttempts.push_back(std::move(attempt));
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::InsertedVertexBudget;
      subdivision.complex = {};
      break;
    }

    ledger.insertedVertices += subdivision.insertedVertices;
    attempt.globalInsertedVerticesAfter = ledger.insertedVertices;
    ledger.currentLiveCandidateComplexes = 1;
    ledger.peakLiveCandidateComplexes =
        std::max(ledger.peakLiveCandidateComplexes,
                 ledger.currentLiveCandidateComplexes);
    attempt.liveCandidateComplexes = ledger.currentLiveCandidateComplexes;

    SurfaceCellComplexCompletionResult candidateResult =
        patch_descriptor_detail::complete_surface_cell_complex_pass(
            subdivision.complex, V, F, options);
    ++ledger.fullRecomputationPasses;
    ledger.currentLiveCandidateComplexes = 0;
    subdivision.complex = {};

    attempt.completionSucceeded = candidateResult.success;
    attempt.resultingConflictClass =
        candidateResult.assembly.ownershipConflict.classification;

    if (candidateResult.success) {
      // The monotonic ownership measure is the number of active exact
      // ownership claims: one before subdivision and zero after assembly.
      attempt.madeProgress = true;
      attempt.committed = true;
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::AssemblySucceeded;
      attempt.visitedStateCount =
          static_cast<int>(ledger.visitedStates.size());
      candidateResult.completionOwnershipLastCandidateHalfedge =
          candidate.halfedge;
      candidateResult.completionOwnershipLastAffectedPatches =
          attempt.affectedPatches;
      aggregateAttempts.push_back(std::move(attempt));
      mergePassEvidence(candidateResult);
      return finalize(std::move(candidateResult));
    }

    patch_descriptor_detail::SurfaceCellRepairStateIdentity candidateState;
    const bool hasCandidateState = candidateResult.hasPreparedComplex;
    if (hasCandidateState) {
      candidateState = patch_descriptor_detail::canonical_repair_state_identity(
          candidateResult.preparedComplex, F,
          candidateResult.assembly.ownershipConflict);
    }
    if (hasCandidateState &&
        ledger.visitedStates.count(candidateState) != 0U) {
      sawRepeatedState = true;
      attempt.repeatedState = true;
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::RepeatedState;
      attempt.failure = "SameCornerRepeatedRepairState";
      attempt.visitedStateCount =
          static_cast<int>(ledger.visitedStates.size());
      aggregateAttempts.push_back(std::move(attempt));
      mergePassEvidence(candidateResult);
      patch_descriptor_detail::release_rejected_completion_storage(
          candidateResult);
      continue;
    }
    if (hasCandidateState) {
      if (static_cast<int>(ledger.visitedStates.size()) >=
          ledger.visitedStateBudget) {
        attempt.outcome = SurfaceCellOwnershipRepairOutcome::BudgetExhausted;
        attempt.failure = "SameCornerVisitedStateBudget";
        aggregateAttempts.push_back(std::move(attempt));
        mergePassEvidence(candidateResult);
        patch_descriptor_detail::release_rejected_completion_storage(
            candidateResult);
        ledger.exhaustionReason =
            SurfaceCellStructuralRepairExhaustionReason::VisitedStateBudget;
        break;
      }
      ledger.visitedStates.insert(std::move(candidateState));
    }
    attempt.visitedStateCount =
        static_cast<int>(ledger.visitedStates.size());

    if (candidateResult.assembly.ownershipConflict.active()) {
      const bool originalClaimPersists =
          candidateResult.assembly.ownershipConflict.classification ==
              SurfaceCellOwnershipConflictClass::
                  SameCornerDistinctBoundaryClaim &&
          patch_descriptor_detail::same_unordered_conflict_pair(
              candidateResult.assembly.ownershipConflict,
              originalConflict.firstPatch, originalConflict.secondPatch);
      if (originalClaimPersists) {
        sawNoProgress = true;
        attempt.outcome = SurfaceCellOwnershipRepairOutcome::NoProgress;
        attempt.failure =
            "SameCornerBoundarySubdivisionDidNotResolveClaim";
      } else {
        sawIntroducedClaim = true;
        attempt.introducedOwnershipClaim = true;
        attempt.outcome =
            SurfaceCellOwnershipRepairOutcome::IntroducedOwnershipClaim;
        attempt.failure = candidateResult.assembly.failure.empty()
                              ? "SameCornerRepairIntroducedOwnershipClaim"
                              : candidateResult.assembly.failure;
      }
    } else {
      sawValidationFailure = true;
      attempt.outcome = SurfaceCellOwnershipRepairOutcome::ValidationFailed;
      attempt.failure = candidateResult.failure.empty()
                            ? "SameCornerRepairCandidateValidationFailed"
                            : candidateResult.failure;
    }
    aggregateAttempts.push_back(std::move(attempt));
    mergePassEvidence(candidateResult);
    patch_descriptor_detail::release_rejected_completion_storage(
        candidateResult);
  }

  if (ledger.exhaustionReason ==
      SurfaceCellStructuralRepairExhaustionReason::None) {
    if (sawRepeatedState) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::RepeatedState;
    } else if (sawNoProgress) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::NoProgress;
    } else if (sawIntroducedClaim) {
      ledger.exhaustionReason = SurfaceCellStructuralRepairExhaustionReason::
          IntroducedOwnershipClaim;
    } else if (sawValidationFailure) {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::NoProgress;
    } else {
      ledger.exhaustionReason =
          SurfaceCellStructuralRepairExhaustionReason::NoCandidate;
    }
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
