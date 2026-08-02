#include <directional/geometry/SurfaceCellOwnership.h>

#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <tuple>

#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SurfaceArrangement.h>

namespace directional::geometry {
namespace surface_cell_ownership_detail {

using IdentityToken = std::vector<std::int64_t>;
using IdentityCycle = std::vector<IdentityToken>;

std::int64_t quantize_parameter(const double value) {
  if (!std::isfinite(value)) {
    return std::numeric_limits<std::int64_t>::min();
  }
  return static_cast<std::int64_t>(std::llround(value * 1.0e10));
}

const SurfaceArrangementNode *find_node(const SurfaceCellComplex &complex,
                                        const int id) {
  if (id >= 0 && id < static_cast<int>(complex.nodes.size()) &&
      complex.nodes[static_cast<std::size_t>(id)].id == id) {
    return &complex.nodes[static_cast<std::size_t>(id)];
  }
  const auto found = std::find_if(
      complex.nodes.begin(), complex.nodes.end(),
      [&](const SurfaceArrangementNode &node) { return node.id == id; });
  return found == complex.nodes.end() ? nullptr : &*found;
}

int source_vertex_at_node(const SurfaceArrangementNode &node,
                          const Eigen::MatrixXi &faces,
                          const double tolerance) {
  const auto inspect = [&](const int face,
                           const Eigen::RowVector3d &barycentric) {
    if (face < 0 || face >= faces.rows() || faces.cols() != 3) {
      return -1;
    }
    int corner = 0;
    barycentric.maxCoeff(&corner);
    return barycentric(corner) >= 1.0 - tolerance ? faces(face, corner) : -1;
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

SurfaceCellCanonicalIdentity flatten_cycle(const IdentityCycle &cycle,
                                           const std::size_t offset) {
  SurfaceCellCanonicalIdentity result;
  if (cycle.empty()) {
    return result;
  }
  result.valid = true;
  result.values.push_back(static_cast<std::int64_t>(cycle.size()));
  for (std::size_t index = 0; index < cycle.size(); ++index) {
    const IdentityToken &token = cycle[(offset + index) % cycle.size()];
    result.values.push_back(static_cast<std::int64_t>(token.size()));
    result.values.insert(result.values.end(), token.begin(), token.end());
  }
  return result;
}

SurfaceCellCanonicalIdentity canonical_rotation(const IdentityCycle &cycle) {
  SurfaceCellCanonicalIdentity best;
  for (std::size_t offset = 0; offset < cycle.size(); ++offset) {
    SurfaceCellCanonicalIdentity candidate = flatten_cycle(cycle, offset);
    if (!best.valid || candidate.values < best.values) {
      best = std::move(candidate);
    }
  }
  return best;
}

PureQuadStitchIdentity node_identity(
    const SurfaceCellComplex &complex, const SurfaceArrangementHalfedge &edge,
    const int nodeId, const bool edgeEnd, const Eigen::MatrixXi &faces,
    const double tolerance) {
  PureQuadStitchIdentity result;
  const SurfaceArrangementNode *node = find_node(complex, nodeId);
  if (node == nullptr) {
    return result;
  }

  const int component = edge.sourceComponent >= 0 ? edge.sourceComponent
                                                   : node->sourceComponent;
  const int sheet = edge.sourceSheet >= 0 ? edge.sourceSheet
                                           : node->sourceSheet;
  const int sourceVertex = source_vertex_at_node(*node, faces, tolerance);
  result.canonical.valid = true;
  if (sourceVertex >= 0) {
    result.kind = PureQuadStitchIdentityKind::CanonicalSourcePoint;
    result.canonical.values = {component, sheet, sourceVertex};
    return result;
  }

  if (edge.railId >= 0 || edge.curveId >= 0) {
    result.kind = PureQuadStitchIdentityKind::OrderedFeatureInterval;
    result.canonical.values = {
        component,
        sheet,
        edge.railId,
        edge.curveId,
        quantize_parameter(edgeEnd ? edge.railT1 : edge.railT0),
        edge.family < 0 ? edge.family : (edge.family & 1),
        edge.proposalSide,
        edge.proposalBoundarySegment,
    };
    return result;
  }

  result.kind = PureQuadStitchIdentityKind::ArrangementBoundaryNode;
  result.canonical.values = {
      component,
      sheet,
      node->id,
      node->sourceEdge,
      quantize_parameter(node->sourceEdgeParameter),
  };
  return result;
}

IdentityToken identity_token(const PureQuadStitchIdentity &identity) {
  IdentityToken token;
  token.push_back(static_cast<std::int64_t>(identity.kind));
  token.push_back(identity.canonical.valid ? 1 : 0);
  token.push_back(static_cast<std::int64_t>(identity.canonical.values.size()));
  token.insert(token.end(), identity.canonical.values.begin(),
               identity.canonical.values.end());
  return token;
}

IdentityToken provenance_token(const SurfaceArrangementProvenance &provenance,
                               const bool reverse) {
  const double sourceT0 = reverse ? provenance.sourceT1 : provenance.sourceT0;
  const double sourceT1 = reverse ? provenance.sourceT0 : provenance.sourceT1;
  const double railT0 = reverse ? provenance.railT1 : provenance.railT0;
  const double railT1 = reverse ? provenance.railT0 : provenance.railT1;
  return {
      provenance.sourceFace,
      provenance.family < 0 ? provenance.family : (provenance.family & 1),
      provenance.strand,
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
      quantize_parameter(sourceT0),
      quantize_parameter(sourceT1),
      quantize_parameter(railT0),
      quantize_parameter(railT1),
  };
}

IdentityToken halfedge_token(const SurfaceCellComplex &complex,
                             const SurfaceArrangementHalfedge &edge,
                             const bool reverse,
                             const Eigen::MatrixXi &faces,
                             const double tolerance) {
  const PureQuadStitchIdentity from = node_identity(
      complex, edge, reverse ? edge.to : edge.from, reverse, faces, tolerance);
  const PureQuadStitchIdentity to = node_identity(
      complex, edge, reverse ? edge.from : edge.to, !reverse, faces, tolerance);
  const double sourceT0 = reverse ? edge.sourceT1 : edge.sourceT0;
  const double sourceT1 = reverse ? edge.sourceT0 : edge.sourceT1;
  const double railT0 = reverse ? edge.railT1 : edge.railT0;
  const double railT1 = reverse ? edge.railT0 : edge.railT1;

  IdentityToken token;
  const IdentityToken fromToken = identity_token(from);
  const IdentityToken toToken = identity_token(to);
  token.push_back(static_cast<std::int64_t>(fromToken.size()));
  token.insert(token.end(), fromToken.begin(), fromToken.end());
  token.push_back(static_cast<std::int64_t>(toToken.size()));
  token.insert(token.end(), toToken.begin(), toToken.end());
  const IdentityToken semantics = {
      edge.family < 0 ? edge.family : (edge.family & 1),
      edge.strand,
      edge.featureClass,
      edge.hardFeature ? 1 : 0,
      edge.layoutSupport ? 1 : 0,
      edge.singularitySupport ? 1 : 0,
      edge.railId,
      edge.curveId,
      edge.sourceComponent,
      edge.sourceSheet,
      edge.proposalSide,
      edge.proposalBoundarySegment,
      quantize_parameter(sourceT0),
      quantize_parameter(sourceT1),
      quantize_parameter(railT0),
      quantize_parameter(railT1),
  };
  token.push_back(static_cast<std::int64_t>(semantics.size()));
  token.insert(token.end(), semantics.begin(), semantics.end());

  std::vector<IdentityToken> provenance;
  provenance.reserve(edge.provenance.size());
  for (const SurfaceArrangementProvenance &entry : edge.provenance) {
    provenance.push_back(provenance_token(entry, reverse));
  }
  std::sort(provenance.begin(), provenance.end());
  token.push_back(static_cast<std::int64_t>(provenance.size()));
  for (const IdentityToken &entry : provenance) {
    token.push_back(static_cast<std::int64_t>(entry.size()));
    token.insert(token.end(), entry.begin(), entry.end());
  }
  return token;
}

std::pair<int, int> consistent_scope(
    const SurfaceCellComplex &complex,
    const std::vector<int> &orderedBoundaryHalfedges) {
  int component = -1;
  int sheet = -1;
  bool componentInitialized = false;
  bool sheetInitialized = false;
  for (const int id : orderedBoundaryHalfedges) {
    if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) {
      return {-2, -2};
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    if (!componentInitialized) {
      component = edge.sourceComponent;
      componentInitialized = true;
    } else if (component != edge.sourceComponent) {
      component = -2;
    }
    if (!sheetInitialized) {
      sheet = edge.sourceSheet;
      sheetInitialized = true;
    } else if (sheet != edge.sourceSheet) {
      sheet = -2;
    }
  }
  return {component, sheet};
}

std::vector<PureQuadStitchIdentity> sorted_corner_identities(
    std::vector<PureQuadStitchIdentity> identities) {
  std::sort(identities.begin(), identities.end());
  return identities;
}

} // namespace surface_cell_ownership_detail

SurfaceCellOwnershipRecord derive_surface_cell_ownership(
    const SurfaceCellComplex &complex, const SurfaceArrangementCell &cell,
    const std::vector<int> &orderedBoundaryHalfedges,
    const Eigen::MatrixXi &sourceFaces, const double barycentricTolerance) {
  SurfaceCellOwnershipRecord result;
  if (orderedBoundaryHalfedges.empty()) {
    return result;
  }

  surface_cell_ownership_detail::IdentityCycle forwardEdges;
  surface_cell_ownership_detail::IdentityCycle reverseEdges;
  surface_cell_ownership_detail::IdentityCycle forwardNodes;
  forwardEdges.reserve(orderedBoundaryHalfedges.size());
  reverseEdges.reserve(orderedBoundaryHalfedges.size());
  forwardNodes.reserve(orderedBoundaryHalfedges.size());
  result.boundaryVertices.reserve(orderedBoundaryHalfedges.size());

  for (const int id : orderedBoundaryHalfedges) {
    if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) {
      return {};
    }
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    const PureQuadStitchIdentity identity =
        surface_cell_ownership_detail::node_identity(
            complex, edge, edge.from, false, sourceFaces,
            barycentricTolerance);
    if (!identity.valid()) {
      return {};
    }
    result.boundaryVertices.push_back(identity);
    forwardNodes.push_back(
        surface_cell_ownership_detail::identity_token(identity));
    forwardEdges.push_back(surface_cell_ownership_detail::halfedge_token(
        complex, edge, false, sourceFaces, barycentricTolerance));
  }

  for (auto iterator = orderedBoundaryHalfedges.rbegin();
       iterator != orderedBoundaryHalfedges.rend(); ++iterator) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(*iterator)];
    reverseEdges.push_back(surface_cell_ownership_detail::halfedge_token(
        complex, edge, true, sourceFaces, barycentricTolerance));
  }

  result.boundaryNodes =
      surface_cell_ownership_detail::canonical_rotation(forwardNodes);
  result.boundaryHalfedges =
      surface_cell_ownership_detail::canonical_rotation(forwardEdges);
  result.domain.orientedBoundary = result.boundaryHalfedges;
  const SurfaceCellCanonicalIdentity reverseBoundary =
      surface_cell_ownership_detail::canonical_rotation(reverseEdges);
  result.domain.undirectedBoundary =
      !reverseBoundary.valid ||
              result.domain.orientedBoundary.values < reverseBoundary.values
          ? result.domain.orientedBoundary
          : reverseBoundary;

  std::vector<int> support = cell.sourceFaces;
  if (support.empty() && cell.sourceFace >= 0) {
    support.push_back(cell.sourceFace);
  }
  std::sort(support.begin(), support.end());
  support.erase(std::unique(support.begin(), support.end()), support.end());
  result.domain.sourceSupport.valid = !support.empty();
  result.domain.sourceSupport.values = {
      static_cast<std::int64_t>(cell.cellClass),
      cell.boundaryCycle ? 1 : 0,
      cell.disk ? 1 : 0,
      cell.closed ? 1 : 0,
      cell.boundaryComponentCount,
      cell.eulerCharacteristic,
      static_cast<std::int64_t>(support.size()),
  };
  result.domain.sourceSupport.values.insert(
      result.domain.sourceSupport.values.end(), support.begin(), support.end());
  const auto [component, sheet] =
      surface_cell_ownership_detail::consistent_scope(
          complex, orderedBoundaryHalfedges);
  result.domain.sourceComponent = component;
  result.domain.sourceSheet = sheet;
  result.domain.valid = result.domain.orientedBoundary.valid &&
                        result.domain.undirectedBoundary.valid &&
                        result.domain.sourceSupport.valid;
  result.valid = result.domain.valid && result.boundaryNodes.valid &&
                 result.boundaryHalfedges.valid &&
                 result.boundaryVertices.size() ==
                     orderedBoundaryHalfedges.size();
  return result;
}

bool apply_surface_cell_ownership(const PureQuadPatch &patch,
                                  PureQuadMesh &mesh,
                                  const int sourcePatch) {
  if (mesh.vertices.size() != mesh.vertexProvenance.size()) {
    return false;
  }
  if (!patch.boundaryStitchIdentities.empty() &&
      patch.boundaryStitchIdentities.size() != patch.boundaryVertices.size()) {
    return false;
  }

  mesh.domainIdentity = patch.domainIdentity;
  mesh.boundaryNodeIdentity = patch.boundaryNodeIdentity;
  mesh.boundaryHalfedgeIdentity = patch.boundaryHalfedgeIdentity;
  std::map<int, PureQuadStitchIdentity> boundaryIdentities;
  for (std::size_t index = 0; index < patch.boundaryVertices.size(); ++index) {
    PureQuadStitchIdentity identity;
    if (!patch.boundaryStitchIdentities.empty()) {
      identity = patch.boundaryStitchIdentities[index];
    } else {
      const SurfacePoint &point = patch.boundaryProvenance[index];
      identity.kind = PureQuadStitchIdentityKind::ArrangementBoundaryNode;
      identity.canonical.valid = true;
      identity.canonical.values = {
          point.component,
          point.sheet,
          patch.boundaryVertices[index],
      };
    }
    if (!identity.valid()) {
      return false;
    }
    const auto [existing, inserted] = boundaryIdentities.emplace(
        patch.boundaryVertices[index], identity);
    if (!inserted && existing->second != identity) {
      return false;
    }
  }

  mesh.vertexStitchIdentities.clear();
  mesh.vertexStitchIdentities.reserve(mesh.vertices.size());
  for (const int localVertex : mesh.vertices) {
    const auto boundary = boundaryIdentities.find(localVertex);
    if (boundary != boundaryIdentities.end()) {
      mesh.vertexStitchIdentities.push_back(boundary->second);
      continue;
    }
    PureQuadStitchIdentity identity;
    identity.kind = PureQuadStitchIdentityKind::GeneratedPatchInterior;
    identity.canonical.valid = true;
    identity.canonical.values = {
        patch.domainIdentity.sourceComponent,
        patch.domainIdentity.sourceSheet,
        sourcePatch,
        localVertex,
    };
    mesh.vertexStitchIdentities.push_back(std::move(identity));
  }
  return true;
}

SurfaceCellOwnershipConflict classify_surface_cell_ownership_conflict(
    const PureQuadMesh &first, const int firstLocalQuad,
    const std::vector<PureQuadStitchIdentity> &firstCorners,
    const PureQuadMesh &second, const int secondLocalQuad,
    const std::vector<PureQuadStitchIdentity> &secondCorners) {
  SurfaceCellOwnershipConflict result;
  result.firstPatch = first.sourcePatch;
  result.firstLocalQuad = firstLocalQuad;
  result.secondPatch = second.sourcePatch;
  result.secondLocalQuad = secondLocalQuad;
  result.firstDomainHash = first.domainIdentity.hash();
  result.secondDomainHash = second.domainIdentity.hash();
  result.firstBoundaryNodeHash = first.boundaryNodeIdentity.hash();
  result.secondBoundaryNodeHash = second.boundaryNodeIdentity.hash();
  result.firstBoundaryHalfedgeHash = first.boundaryHalfedgeIdentity.hash();
  result.secondBoundaryHalfedgeHash = second.boundaryHalfedgeIdentity.hash();
  result.firstSourceSupportHash = first.domainIdentity.sourceSupport.hash();
  result.secondSourceSupportHash = second.domainIdentity.sourceSupport.hash();
  result.firstSourceSupportCount = static_cast<int>(
      first.domainIdentity.sourceSupport.values.size());
  result.secondSourceSupportCount = static_cast<int>(
      second.domainIdentity.sourceSupport.values.size());
  result.firstComponent = first.domainIdentity.sourceComponent;
  result.firstSheet = first.domainIdentity.sourceSheet;
  result.secondComponent = second.domainIdentity.sourceComponent;
  result.secondSheet = second.domainIdentity.sourceSheet;
  for (const PureQuadStitchIdentity &identity : firstCorners) {
    result.firstCornerIdentityHashes.push_back(identity.hash());
  }
  for (const PureQuadStitchIdentity &identity : secondCorners) {
    result.secondCornerIdentityHashes.push_back(identity.hash());
  }

  if (!first.domainIdentity.valid || !second.domainIdentity.valid) {
    result.classification =
        SurfaceCellOwnershipConflictClass::InvalidDomainIdentity;
  } else if (first.domainIdentity.same_oriented_domain(
                 second.domainIdentity)) {
    result.classification =
        SurfaceCellOwnershipConflictClass::DuplicateOrientedDomain;
  } else if (first.domainIdentity.same_undirected_support(
                 second.domainIdentity)) {
    result.classification =
        SurfaceCellOwnershipConflictClass::OverlappingUndirectedBoundary;
  } else if (surface_cell_ownership_detail::sorted_corner_identities(
                 firstCorners) ==
             surface_cell_ownership_detail::sorted_corner_identities(
                 secondCorners)) {
    result.classification =
        SurfaceCellOwnershipConflictClass::CompletionTemplateOwnership;
  } else {
    result.classification =
        SurfaceCellOwnershipConflictClass::FalseVertexEquivalence;
  }
  return result;
}

std::string format_surface_cell_ownership_conflict(
    const SurfaceCellOwnershipConflict &conflict) {
  std::ostringstream stream;
  stream << ";classification="
         << surface_cell_ownership_conflict_name(conflict.classification)
         << ";firstDomainHash=" << conflict.firstDomainHash
         << ";secondDomainHash=" << conflict.secondDomainHash
         << ";firstBoundaryNodeHash=" << conflict.firstBoundaryNodeHash
         << ";secondBoundaryNodeHash=" << conflict.secondBoundaryNodeHash
         << ";firstBoundaryHalfedgeHash="
         << conflict.firstBoundaryHalfedgeHash
         << ";secondBoundaryHalfedgeHash="
         << conflict.secondBoundaryHalfedgeHash
         << ";firstComponent=" << conflict.firstComponent
         << ";firstSheet=" << conflict.firstSheet
         << ";secondComponent=" << conflict.secondComponent
         << ";secondSheet=" << conflict.secondSheet;
  return stream.str();
}

} // namespace directional::geometry
