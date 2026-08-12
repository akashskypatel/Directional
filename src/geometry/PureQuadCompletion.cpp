#include <directional/geometry/PureQuadCompletion.h>
#include <directional/geometry/SourceChartTransitions.h>

#include <sstream>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

namespace directional::geometry::pure_quad_detail {

int boundary_edge_count(const PureQuadPatch &patch) {
  return std::accumulate(patch.sideEdgeCounts.begin(),
                         patch.sideEdgeCounts.end(), 0);
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool turns_are_valid(const PureQuadPatch &patch) {
  for (const int turn : patch.turns) {
    if (turn != 0 && std::abs(turn) != 1) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool side_inequalities_hold(const std::vector<int> &e) {
  const int n = static_cast<int>(e.size());
  if (n < 3 || n > 6) {
    return false;
  }
  for (const int count : e) {
    if (count <= 0) {
      return false;
    }
  }
  if (n == 3) {
    for (int i = 0; i < 3; ++i) {
      if (e[i] > e[(i + 1) % 3] + e[(i + 2) % 3]) {
        return false;
      }
    }
    return true;
  }
  if (n == 4) {
    return e[0] == e[2] && e[1] == e[3];
  }
  if (n == 5) {
    for (int i = 0; i < 5; ++i) {
      if (e[i] + e[(i + 1) % 5] + e[(i + 4) % 5] <
          e[(i + 2) % 5] + e[(i + 3) % 5]) {
        return false;
      }
    }
    return true;
  }
  for (int i = 0; i < 6; ++i) {
    if (e[i] > e[(i + 2) % 6] + e[(i + 4) % 6]) {
      return false;
    }
  }
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool hex_parity_holds(const std::vector<int> &e) {
  if (e.size() != 6) {
    return true;
  }
  const int even = e[0] + e[2] + e[4];
  const int odd = e[1] + e[3] + e[5];
  return even == odd;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

int expected_valence(const int singularIndexNumerator) {
  return 4 - singularIndexNumerator;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

int next_generated_vertex(int &next) { return next--; }

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

int normalized_completion_variant(const int variant, const int count) {
  if (count <= 0) {
    return 0;
  }
  const int remainder = variant % count;
  return remainder < 0 ? remainder + count : remainder;
}

std::vector<int> rotated_cycle(const std::vector<int> &cycle,
                               const int variant) {
  if (cycle.empty()) {
    return {};
  }
  const int count = static_cast<int>(cycle.size());
  const int normalized = normalized_completion_variant(variant, 2 * count);
  const int start = normalized % count;
  const bool reversed = normalized >= count;
  std::vector<int> rotated;
  rotated.reserve(cycle.size());
  for (int offset = 0; offset < count; ++offset) {
    const int signedOffset = reversed ? -offset : offset;
    const int index = normalized_completion_variant(start + signedOffset,
                                                    count);
    rotated.push_back(cycle[static_cast<std::size_t>(index)]);
  }
  return rotated;
}

template <typename T>
struct CanonicalQuadCycle {
  std::array<T, 4> values{};
  std::array<int, 4> sourceIndices{{0, 1, 2, 3}};
};

template <typename T>
CanonicalQuadCycle<T> canonical_quad_cycle(
    const std::array<T, 4> &cycle, const bool reversed) {
  CanonicalQuadCycle<T> best;
  bool initialized = false;
  for (int start = 0; start < 4; ++start) {
    CanonicalQuadCycle<T> candidate;
    for (int offset = 0; offset < 4; ++offset) {
      const int index = reversed ? (start - offset + 8) % 4
                                 : (start + offset) % 4;
      candidate.values[static_cast<std::size_t>(offset)] =
          cycle[static_cast<std::size_t>(index)];
      candidate.sourceIndices[static_cast<std::size_t>(offset)] = index;
    }
    if (!initialized || candidate.values < best.values) {
      best = std::move(candidate);
      initialized = true;
    }
  }
  return best;
}

std::uint64_t stitch_cycle_hash(
    const std::array<PureQuadStitchIdentity, 4> &cycle) {
  std::uint64_t seed = 1469598103934665603ULL;
  for (const PureQuadStitchIdentity &identity : cycle) {
    seed ^= static_cast<std::uint64_t>(identity.kind);
    seed *= 1099511628211ULL;
    seed ^= identity.canonical.hash();
    seed *= 1099511628211ULL;
  }
  return seed;
}

bool same_unoriented_cycle(
    const CanonicalQuadCycle<PureQuadStitchIdentity> &firstForward,
    const CanonicalQuadCycle<PureQuadStitchIdentity> &firstReversed,
    const CanonicalQuadCycle<PureQuadStitchIdentity> &secondForward,
    const CanonicalQuadCycle<PureQuadStitchIdentity> &secondReversed) {
  return firstForward.values == secondForward.values ||
         firstForward.values == secondReversed.values ||
         firstReversed.values == secondForward.values ||
         firstReversed.values == secondReversed.values;
}

std::string identity_hash_list(
    const std::array<std::uint64_t, 4> &hashes) {
  std::ostringstream stream;
  for (int corner = 0; corner < 4; ++corner) {
    if (corner != 0) {
      stream << ',';
    }
    stream << hashes[static_cast<std::size_t>(corner)];
  }
  return stream.str();
}

std::string integer_list(const std::vector<int> &values) {
  std::ostringstream stream;
  for (std::size_t index = 0; index < values.size(); ++index) {
    if (index != 0U) {
      stream << ',';
    }
    stream << values[index];
  }
  return stream.str();
}

std::string identity_kind_list(const std::array<int, 4> &kinds) {
  std::ostringstream stream;
  for (int corner = 0; corner < 4; ++corner) {
    if (corner != 0) {
      stream << ',';
    }
    stream << pure_quad_stitch_identity_kind_name(
        static_cast<PureQuadStitchIdentityKind>(
            kinds[static_cast<std::size_t>(corner)]));
  }
  return stream.str();
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

SurfacePoint make_planar_source_point(const int face,
                                             const Eigen::Vector3d &position,
                                             const Eigen::Vector3d &barycentric) {
  SurfacePoint point;
  point.face = face;
  point.component = 0;
  point.sheet = 0;
  point.barycentric = barycentric;
  point.position = position;
  point.squaredDistance = 0.0;
  return point;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

SurfacePoint boundary_source_point(const PureQuadPatch &patch,
                                          const int boundaryIndex) {
  if (boundaryIndex >= 0 &&
      boundaryIndex < static_cast<int>(patch.boundaryProvenance.size()) &&
      patch.boundaryProvenance[static_cast<std::size_t>(boundaryIndex)].valid()) {
    return patch.boundaryProvenance[static_cast<std::size_t>(boundaryIndex)];
  }
  return {};
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

SurfacePoint average_source_point(const std::vector<SurfacePoint> &points) {
  Eigen::Vector3d position = Eigen::Vector3d::Zero();
  Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
  int face = -1;
  int component = -1;
  int sheet = -1;
  int count = 0;
  for (const SurfacePoint &point : points) {
    if (!point.valid()) {
      continue;
    }
    position += point.position;
    barycentric += point.barycentric;
    if (face < 0) {
      face = point.face;
      component = point.component;
      sheet = point.sheet;
    }
    ++count;
  }
  if (count == 0) {
    return {};
  }
  position /= static_cast<double>(count);
  barycentric /= static_cast<double>(count);
  const double sum = std::max(1.0e-20, barycentric.sum());
  barycentric /= sum;
  SurfacePoint averaged;
  averaged.face = face;
  averaged.component = component;
  averaged.sheet = sheet;
  averaged.position = position;
  averaged.barycentric = barycentric;
  averaged.squaredDistance = 0.0;
  return averaged;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

SurfacePoint project_generated_point(
    const Eigen::Vector3d &target, const std::vector<SurfacePoint> &anchors,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority) {
  const auto derive_source_payload = [&](SurfacePoint &point) {
    if (!point.valid() || sourceAuthority == nullptr) return point.valid();
    const auto row = authority::SourceFaceId::from_index(
        point.face, sourceAuthority->face_count());
    if (!row) return false;
    point.component = static_cast<int>(
        sourceAuthority->component_for_row(row.value()).index());
    point.sheet = static_cast<int>(
        sourceAuthority->sheet_for_row(row.value()).index());
    return true;
  };
  if (projection != nullptr) {
    SurfaceProjectionOptions options;
    options.allowedFaces = allowedFaces;
    SurfacePoint projected = projection->project(target, options);
    if (derive_source_payload(projected)) return projected;
  }

  const SurfacePoint averaged = average_source_point(anchors);
  if (!averaged.valid()) return {};
  for (const SurfacePoint &anchor : anchors) {
    if (!anchor.valid() || anchor.face != averaged.face) return {};
  }
  SurfacePoint result = averaged;
  if (!derive_source_payload(result)) return {};
  return result;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

void initialize_boundary_embedding(const PureQuadPatch &patch,
                                   PureQuadMesh &mesh) {
  mesh.boundaryVertices = patch.boundaryVertices;
  mesh.vertices = patch.boundaryVertices;
  mesh.vertexProvenance.clear();
  mesh.vertexProvenance.reserve(mesh.vertices.size());
  mesh.vertexLineage.clear();
  mesh.domainIdentity = patch.domainIdentity;
  for (int i = 0; i < static_cast<int>(mesh.boundaryVertices.size()); ++i) {
    const SurfacePoint point = boundary_source_point(patch, i);
    mesh.vertexProvenance.push_back(point);
    PureQuadVertexLineage lineage;
    lineage.outputVertex =
        mesh.boundaryVertices[static_cast<std::size_t>(i)];
    lineage.sourcePatch = mesh.sourcePatch;
    lineage.localVertex = lineage.outputVertex;
    if (i < static_cast<int>(patch.boundaryTopologyRegions.size())) {
      lineage.sourceTopologyRegions.push_back(
          patch.boundaryTopologyRegions[static_cast<std::size_t>(i)]);
    }
    if (i < static_cast<int>(patch.boundaryCharts.size())) {
      lineage.sourceCharts.push_back(
          patch.boundaryCharts[static_cast<std::size_t>(i)]);
    }
    lineage.stitchIdentity.kind =
        PureQuadStitchIdentityKind::ArrangementBoundaryNode;
    if (i < static_cast<int>(patch.boundaryNodeIdentities.size()) &&
        patch.boundaryNodeIdentities[static_cast<std::size_t>(i)].valid) {
      lineage.stitchIdentity.canonical =
          patch.boundaryNodeIdentities[static_cast<std::size_t>(i)];
    } else {
      // Compatibility path for standalone completion fixtures. Production
      // descriptors always provide the exact arrangement-node identity.
      lineage.stitchIdentity.canonical.valid = true;
      lineage.stitchIdentity.canonical.values = {lineage.outputVertex};
      if (!lineage.sourceTopologyRegions.empty()) {
        lineage.stitchIdentity.canonical.values.push_back(
            static_cast<std::int64_t>(
                lineage.sourceTopologyRegions.front().index()));
      }
      if (!lineage.sourceCharts.empty()) {
        lineage.stitchIdentity.canonical.values.push_back(
            static_cast<std::int64_t>(lineage.sourceCharts.front().chart.index()));
        lineage.stitchIdentity.canonical.values.push_back(
            static_cast<std::int64_t>(lineage.sourceCharts.front().face.index()));
      }
    }
    lineage.authoritativeIdentity = lineage.stitchIdentity;
    const std::optional<authority::HardRailId> rail =
        i < static_cast<int>(patch.boundaryRailIds.size())
            ? patch.boundaryRailIds[static_cast<std::size_t>(i)]
            : std::nullopt;
    const int curve =
        i < static_cast<int>(patch.boundaryCurveIds.size())
            ? patch.boundaryCurveIds[static_cast<std::size_t>(i)]
            : -1;
    if (rail.has_value() || curve >= 0) {
      lineage.kind = PureQuadVertexLineageKind::OrderedFeatureInterval;
      lineage.featureInterval.railId = rail;
      lineage.featureInterval.curveId = curve;
      lineage.featureInterval.start = point;
      lineage.featureInterval.end = boundary_source_point(
          patch, (i + 1) % static_cast<int>(mesh.boundaryVertices.size()));
    } else {
      lineage.sourcePoint = point;
    }
    mesh.vertexLineage.push_back(std::move(lineage));
  }
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

int append_embedded_vertex(
    PureQuadMesh &mesh, int &nextInterior,
    const Eigen::Vector3d &targetPosition,
    const std::vector<SurfacePoint> &anchors,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority) {
  const SurfacePoint point = project_generated_point(
      targetPosition, anchors, projection, allowedFaces, sourceAuthority);
  if (!point.valid()) return std::numeric_limits<int>::max();
  const int vertex = next_generated_vertex(nextInterior);
  mesh.vertices.push_back(vertex);
  mesh.vertexProvenance.push_back(point);
  PureQuadVertexLineage lineage;
  lineage.outputVertex = vertex;
  lineage.sourcePoint = point;
  lineage.sourcePatch = mesh.sourcePatch;
  lineage.localVertex = vertex;
  if (sourceAuthority != nullptr) {
    const auto row = authority::SourceFaceId::from_index(
        point.face, sourceAuthority->face_count());
    if (row) {
      lineage.sourceTopologyRegions.push_back(
          sourceAuthority->region_for_row(row.value()));
      lineage.sourceIsolationSheets.push_back(
          sourceAuthority->sheet_for_row(row.value()));
    }
  }
  lineage.stitchIdentity.kind =
      PureQuadStitchIdentityKind::GeneratedPatchInterior;
  lineage.stitchIdentity.canonical.valid = true;
  lineage.stitchIdentity.canonical.values = {mesh.sourcePatch, vertex};
  if (!lineage.sourceTopologyRegions.empty()) {
    lineage.stitchIdentity.canonical.values.push_back(
        static_cast<std::int64_t>(lineage.sourceTopologyRegions.front().index()));
  }
  if (!lineage.sourceIsolationSheets.empty()) {
    lineage.stitchIdentity.canonical.values.push_back(
        static_cast<std::int64_t>(lineage.sourceIsolationSheets.front().index()));
  }
  lineage.authoritativeIdentity = lineage.stitchIdentity;
  mesh.vertexLineage.push_back(std::move(lineage));
  return vertex;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool fill_positions(PureQuadMesh &mesh) {
  mesh.vertexPositions.resize(static_cast<int>(mesh.vertices.size()), 3);
  for (int i = 0; i < static_cast<int>(mesh.vertices.size()); ++i) {
    if (i < static_cast<int>(mesh.vertexProvenance.size()) &&
        mesh.vertexProvenance[static_cast<std::size_t>(i)].valid()) {
      mesh.vertexPositions.row(i) =
          mesh.vertexProvenance[static_cast<std::size_t>(i)].position;
    } else {
      return false;
    }
    if (!mesh.vertexPositions.row(i).allFinite()) {
      return false;
    }
  }
  return true;
}



std::pair<int, int> diagnostic_source_scope(const PureQuadMesh &mesh) {
  // One-way representation-only diagnostic projection. These raw labels are
  // never consulted for semantic equality, ordering, ownership, or routing.
  for (const PureQuadVertexLineage &lineage : mesh.vertexLineage) {
    const SurfacePoint *point = nullptr;
    if (lineage.kind == PureQuadVertexLineageKind::SourceTriangle &&
        lineage.sourcePoint.valid()) {
      point = &lineage.sourcePoint;
    } else if (lineage.kind ==
                   PureQuadVertexLineageKind::OrderedFeatureInterval &&
               lineage.featureInterval.start.valid()) {
      point = &lineage.featureInterval.start;
    }
    if (point != nullptr) return {point->component, point->sheet};
  }
  return {-1, -1};
}

bool completed_quads_have_simple_embedding(
    const PureQuadMesh &mesh, const int completionVariant,
    PureQuadEmbeddingFailure &failure) {
  failure = {};
  failure.sourcePatch = mesh.sourcePatch;
  failure.backend = mesh.backend;
  failure.completionVariant = completionVariant;
  const auto reject = [&](const PureQuadEmbeddingFailureKind kind,
                          const int localQuad) {
    failure.active = true;
    failure.kind = kind;
    failure.localQuad = localQuad;
    if (localQuad >= 0 &&
        localQuad < static_cast<int>(mesh.quads.size())) {
      const auto &quad = mesh.quads[static_cast<std::size_t>(localQuad)];
      for (int corner = 0; corner < 4 &&
                           corner < static_cast<int>(quad.size()); ++corner) {
        failure.localVertices[static_cast<std::size_t>(corner)] =
            quad[static_cast<std::size_t>(corner)];
      }
      std::set<int> sourceFaces;
      for (const int vertex : quad) {
        const auto row = std::find(mesh.vertices.begin(), mesh.vertices.end(),
                                   vertex);
        if (row == mesh.vertices.end()) {
          continue;
        }
        const std::size_t index =
            static_cast<std::size_t>(std::distance(mesh.vertices.begin(), row));
        if (index < mesh.vertexProvenance.size()) {
          const SurfacePoint &point = mesh.vertexProvenance[index];
          if (point.face >= 0) {
            sourceFaces.insert(point.face);
          }
        }
      }
      failure.sourceFaces.assign(sourceFaces.begin(), sourceFaces.end());
    }
    return false;
  };

  std::map<int, int> rowByVertex;
  for (int row = 0; row < static_cast<int>(mesh.vertices.size()); ++row) {
    if (!rowByVertex.emplace(mesh.vertices[static_cast<std::size_t>(row)], row)
             .second) {
      return reject(PureQuadEmbeddingFailureKind::DuplicateMeshVertex, 0);
    }
  }
  const auto orient2 = [](const Eigen::Vector2d &a,
                          const Eigen::Vector2d &b,
                          const Eigen::Vector2d &c) {
    return (b.x() - a.x()) * (c.y() - a.y()) -
           (b.y() - a.y()) * (c.x() - a.x());
  };
  const auto oppositeEdgesIntersect = [&](const Eigen::Vector2d &a,
                                          const Eigen::Vector2d &b,
                                          const Eigen::Vector2d &c,
                                          const Eigen::Vector2d &d) {
    constexpr double eps = 1.0e-13;
    const double o1 = orient2(a, b, c);
    const double o2 = orient2(a, b, d);
    const double o3 = orient2(c, d, a);
    const double o4 = orient2(c, d, b);
    return ((o1 > eps && o2 < -eps) || (o1 < -eps && o2 > eps)) &&
           ((o3 > eps && o4 < -eps) || (o3 < -eps && o4 > eps));
  };

  for (int quadIndex = 0; quadIndex < static_cast<int>(mesh.quads.size());
       ++quadIndex) {
    const std::vector<int> &quad =
        mesh.quads[static_cast<std::size_t>(quadIndex)];
    if (quad.size() != 4U) {
      return reject(PureQuadEmbeddingFailureKind::InvalidQuadCardinality,
                    quadIndex);
    }
    if (std::set<int>(quad.begin(), quad.end()).size() != 4U) {
      return reject(PureQuadEmbeddingFailureKind::RepeatedQuadVertex,
                    quadIndex);
    }
    std::array<Eigen::Vector3d, 4> p;
    for (int corner = 0; corner < 4; ++corner) {
      const auto row = rowByVertex.find(quad[static_cast<std::size_t>(corner)]);
      if (row == rowByVertex.end() || row->second < 0 ||
          row->second >= mesh.vertexPositions.rows()) {
        return reject(PureQuadEmbeddingFailureKind::MissingVertexPosition,
                      quadIndex);
      }
      p[static_cast<std::size_t>(corner)] =
          mesh.vertexPositions.row(row->second).transpose();
      if (!p[static_cast<std::size_t>(corner)].allFinite()) {
        return reject(PureQuadEmbeddingFailureKind::NonFinitePosition,
                      quadIndex);
      }
    }
    Eigen::Vector3d normal = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 4; ++corner) {
      const Eigen::Vector3d &current = p[static_cast<std::size_t>(corner)];
      const Eigen::Vector3d &next =
          p[static_cast<std::size_t>((corner + 1) % 4)];
      normal.x() += (current.y() - next.y()) * (current.z() + next.z());
      normal.y() += (current.z() - next.z()) * (current.x() + next.x());
      normal.z() += (current.x() - next.x()) * (current.y() + next.y());
    }
    if (!normal.allFinite() || normal.squaredNorm() <= 1.0e-24) {
      return reject(PureQuadEmbeddingFailureKind::DegenerateNormal, quadIndex);
    }
    Eigen::Index dropAxis = 0;
    normal.cwiseAbs().maxCoeff(&dropAxis);
    std::array<Eigen::Vector2d, 4> projected;
    for (int corner = 0; corner < 4; ++corner) {
      const Eigen::Vector3d &value = p[static_cast<std::size_t>(corner)];
      if (dropAxis == 0) {
        projected[static_cast<std::size_t>(corner)] =
            Eigen::Vector2d(value.y(), value.z());
      } else if (dropAxis == 1) {
        projected[static_cast<std::size_t>(corner)] =
            Eigen::Vector2d(value.x(), value.z());
      } else {
        projected[static_cast<std::size_t>(corner)] =
            Eigen::Vector2d(value.x(), value.y());
      }
    }
    double signedArea2 = 0.0;
    for (int corner = 0; corner < 4; ++corner) {
      const Eigen::Vector2d &a = projected[static_cast<std::size_t>(corner)];
      const Eigen::Vector2d &b =
          projected[static_cast<std::size_t>((corner + 1) % 4)];
      signedArea2 += a.x() * b.y() - a.y() * b.x();
    }
    if (!std::isfinite(signedArea2) || std::abs(signedArea2) <= 1.0e-14) {
      return reject(PureQuadEmbeddingFailureKind::ZeroProjectedArea,
                    quadIndex);
    }
    if (oppositeEdgesIntersect(projected[0], projected[1], projected[2],
                               projected[3]) ||
        oppositeEdgesIntersect(projected[1], projected[2], projected[3],
                               projected[0])) {
      return reject(PureQuadEmbeddingFailureKind::BowTieIntersection,
                    quadIndex);
    }
  }
  return true;
}
} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

std::string completion_ownership_face_list(const std::vector<int> &faces) {
  std::ostringstream stream;
  for (std::size_t index = 0; index < faces.size(); ++index) {
    if (index != 0U) {
      stream << ',';
    }
    stream << faces[index];
  }
  return stream.str();
}

std::string completion_ownership_face_list(
    const std::vector<authority::SourceFaceId> &faces) {
  std::ostringstream stream;
  for (std::size_t index = 0; index < faces.size(); ++index) {
    if (index != 0U) {
      stream << ',';
    }
    stream << faces[index].index();
  }
  return stream.str();
}

bool completion_ownership_face_matches_authority(
    const int face, const PureQuadVertexLineage &lineage,
    const SourceTopologyRegions *sourceAuthority) {
  if (face < 0 || sourceAuthority == nullptr) return false;
  const auto row = authority::SourceFaceId::from_index(
      face, sourceAuthority->face_count());
  if (!row) return false;
  const authority::TopologyRegionId region =
      sourceAuthority->region_for_row(row.value());
  const authority::IsolationSheetId sheet =
      sourceAuthority->sheet_for_row(row.value());
  if (!lineage.sourceTopologyRegions.empty() &&
      std::find(lineage.sourceTopologyRegions.begin(),
                lineage.sourceTopologyRegions.end(), region) ==
          lineage.sourceTopologyRegions.end()) {
    return false;
  }
  if (!lineage.sourceIsolationSheets.empty() &&
      std::find(lineage.sourceIsolationSheets.begin(),
                lineage.sourceIsolationSheets.end(), sheet) ==
          lineage.sourceIsolationSheets.end()) {
    return false;
  }
  return true;
}

void set_completion_ownership_rejection(
    PureQuadCompletionOwnershipRejection *rejection,
    const std::string &failureCode, const PureQuadMesh &mesh,
    const PureQuadVertexLineage &lineage, const SurfacePoint &provenance,
    const bool boundaryVertex, const int completionVariant,
    const SurfacePointSourceSupport &support,
    const std::vector<int> &patchSourceFaces,
    const SourceTopologyRegions *sourceAuthority, std::string &failure) {
  int sourceVertex = -1;
  std::array<int, 2> sourceEdge{{-1, -1}};
  if (support.identity.has_value()) {
    if (const auto *vertex =
            std::get_if<authority::SourceVertexSupport>(&support.identity.value())) {
      sourceVertex = static_cast<int>(vertex->vertex.index());
    } else if (const auto *edge =
                   std::get_if<authority::SourceEdgeSupport>(&support.identity.value())) {
      sourceEdge = {static_cast<int>(edge->edge.first().index()),
                    static_cast<int>(edge->edge.second().index())};
    }
  }
  failure = failureCode + ":sourcePatch=" +
            std::to_string(mesh.sourcePatch) + ";localVertex=" +
            std::to_string(lineage.localVertex) + ";boundary=" +
            std::to_string(boundaryVertex ? 1 : 0) + ";backend=" +
            pure_quad_completion_backend_name(mesh.backend) + ";variant=" +
            std::to_string(completionVariant) + ";storedFace=" +
            std::to_string(provenance.face) + ";barycentric=" +
            std::to_string(provenance.barycentric(0)) + "," +
            std::to_string(provenance.barycentric(1)) + "," +
            std::to_string(provenance.barycentric(2)) + ";entity=" +
            surface_point_source_support_kind_name(support) +
            ";sourceVertex=" + std::to_string(sourceVertex) +
            ";sourceEdge=" + std::to_string(sourceEdge[0]) + "," +
            std::to_string(sourceEdge[1]) + ";candidateFaces=" +
            completion_ownership_face_list(support.incidentFaces) +
            ";patchFaces=" + completion_ownership_face_list(patchSourceFaces) +
            ";component=" +
            std::to_string((sourceAuthority != nullptr && provenance.face >= 0 &&
                            authority::SourceFaceId::from_index(
                                provenance.face, sourceAuthority->face_count()))
                               ? static_cast<int>(sourceAuthority->component_for_row(
                                     authority::SourceFaceId::from_index(
                                         provenance.face, sourceAuthority->face_count()).value()).index())
                               : -1) +
            ";sheet=" +
            std::to_string((sourceAuthority != nullptr && provenance.face >= 0 &&
                            authority::SourceFaceId::from_index(
                                provenance.face, sourceAuthority->face_count()))
                               ? static_cast<int>(sourceAuthority->sheet_for_row(
                                     authority::SourceFaceId::from_index(
                                         provenance.face, sourceAuthority->face_count()).value()).index())
                               : -1) +
            ";supportFailure=" +
            surface_point_source_support_failure_name(support.failure);
  if (rejection == nullptr || rejection->active) {
    return;
  }
  rejection->active = true;
  rejection->failure = failureCode;
  rejection->sourcePatch = mesh.sourcePatch;
  rejection->localVertex = lineage.localVertex;
  rejection->boundaryVertex = boundaryVertex;
  rejection->backend = mesh.backend;
  rejection->completionVariant = completionVariant;
  rejection->storedFace = provenance.face;
  rejection->barycentric = provenance.barycentric;
  rejection->sourceSupport = support.identity;
  rejection->candidateSupportedFaces = support.incidentFaces;
  rejection->patchSourceFaces = patchSourceFaces;
}

bool validate_completion_domain_ownership(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const int completionVariant,
    const SurfacePointSourceSupportResolver *sourceSupportResolver,
    const Eigen::MatrixXi *sourceFaceMatrix,
    const SourceTopologyRegions *sourceAuthority, std::string &failure,
    PureQuadCompletionOwnershipRejection *ownershipRejection,
    const std::set<std::uint64_t> *sourceHardFeatureEdges) {
  if (mesh.vertices.size() != mesh.vertexProvenance.size() ||
      mesh.vertices.size() != mesh.vertexLineage.size()) {
    failure = "CompletionOwnershipIncompleteVertexLineage";
    return false;
  }

  std::map<int, std::size_t> boundaryRows;
  for (std::size_t boundaryIndex = 0;
       boundaryIndex < patch.boundaryVertices.size(); ++boundaryIndex) {
    if (!boundaryRows.emplace(patch.boundaryVertices[boundaryIndex],
                              boundaryIndex)
             .second) {
      failure = "CompletionOwnershipDuplicateBoundaryVertex";
      return false;
    }
  }
  std::vector<int> patchSourceFaces = patch.sourceFaces;
  std::sort(patchSourceFaces.begin(), patchSourceFaces.end());
  patchSourceFaces.erase(
      std::unique(patchSourceFaces.begin(), patchSourceFaces.end()),
      patchSourceFaces.end());
  const std::set<int> sourceFaces(patchSourceFaces.begin(),
                                  patchSourceFaces.end());
  const SourceChartTransitionGraph transitionGraph(
      sourceFaceMatrix, sourceAuthority, sourceHardFeatureEdges);
  const bool transitionAuthorityAvailable = transitionGraph.available();

  std::map<int, std::size_t> vertexRows;
  for (std::size_t row = 0; row < mesh.vertices.size(); ++row) {
    const int localVertex = mesh.vertices[row];
    if (!vertexRows.emplace(localVertex, row).second) {
      failure = "CompletionOwnershipDuplicateLocalVertex";
      return false;
    }
    PureQuadVertexLineage &lineage = mesh.vertexLineage[row];
    if (lineage.outputVertex != localVertex ||
        lineage.sourcePatch != mesh.sourcePatch ||
        lineage.localVertex != localVertex) {
      failure = "CompletionOwnershipInvalidVertexOwner";
      return false;
    }
    if (!lineage.stitchIdentity.valid()) {
      failure = "CompletionOwnershipMissingStitchIdentity";
      return false;
    }
    if (!lineage.authoritativeIdentity.valid()) {
      lineage.authoritativeIdentity = lineage.stitchIdentity;
    }

    const auto boundary = boundaryRows.find(localVertex);
    const bool boundaryVertex = boundary != boundaryRows.end();
    if (boundaryVertex) {
      const std::size_t boundaryIndex = boundary->second;
      if (boundaryIndex < patch.boundaryNodeIdentities.size() &&
          patch.boundaryNodeIdentities[boundaryIndex].valid) {
        PureQuadStitchIdentity expected;
        expected.kind = PureQuadStitchIdentityKind::ArrangementBoundaryNode;
        expected.canonical = patch.boundaryNodeIdentities[boundaryIndex];
        if (lineage.authoritativeIdentity != expected) {
          failure = "CompletionOwnershipBoundaryIdentityMismatch";
          return false;
        }
      } else if (lineage.authoritativeIdentity.kind !=
                 PureQuadStitchIdentityKind::ArrangementBoundaryNode) {
        // Standalone completion fixtures do not carry an arrangement. Their
        // fallback identity remains valid only as an arrangement-node key.
        failure = "CompletionOwnershipMissingBoundaryIdentity";
        return false;
      }
    } else if (lineage.stitchIdentity.kind !=
                   PureQuadStitchIdentityKind::GeneratedPatchInterior ||
               lineage.authoritativeIdentity.kind !=
                   PureQuadStitchIdentityKind::GeneratedPatchInterior) {
      failure = "CompletionOwnershipInteriorNotPatchLocal";
      return false;
    }

    SurfacePoint &provenance = mesh.vertexProvenance[row];
    if (!provenance.valid()) {
      failure = "CompletionOwnershipMissingSourcePoint";
      return false;
    }
    if (sourceFaces.empty()) {
      lineage.sourcePoint = provenance;
      continue;
    }

    SurfacePointSourceSupport support;
    if (boundaryVertex && sourceSupportResolver != nullptr &&
        sourceSupportResolver->available()) {
      support = sourceSupportResolver->resolve(provenance);
      if (!support.valid()) {
        set_completion_ownership_rejection(
            ownershipRejection, "CompletionOwnershipInvalidSourceSupport",
            mesh, lineage, provenance, true, completionVariant, support,
            patchSourceFaces, sourceAuthority, failure);
        return false;
      }
    } else {
      if (sourceFaceMatrix == nullptr) {
        failure = "CompletionOwnershipInvalidSourceSupport";
        return false;
      }
      const auto sourceFace = authority::SourceFaceId::from_index(
          provenance.face, static_cast<std::size_t>(sourceFaceMatrix->rows()));
      if (!sourceFace) {
        failure = "CompletionOwnershipInvalidSourceSupport";
        return false;
      }
      support.identity =
          authority::SourceFaceInteriorSupport{sourceFace.value()};
      support.incidentFaces = {sourceFace.value()};
    }

    bool intersectsPatch = false;
    std::vector<int> compatibleFaces;
    for (const authority::SourceFaceId sourceFace : support.incidentFaces) {
      const int candidateFace = static_cast<int>(sourceFace.index());
      if (sourceFaces.count(candidateFace) == 0U) {
        continue;
      }
      intersectsPatch = true;
      bool compatible = completion_ownership_face_matches_authority(
          candidateFace, lineage, sourceAuthority);
      if (compatible && transitionAuthorityAvailable) {
        SurfacePoint rebound;
        compatible = transitionGraph.rebind(provenance, candidateFace, rebound);
      }
      if (compatible) {
        compatibleFaces.push_back(candidateFace);
      }
    }
    if (compatibleFaces.empty()) {
      const std::string failureCode =
          intersectsPatch ? "CompletionOwnershipComponentSheetMismatch"
                          : "CompletionOwnershipSourceSupportEscape";
      set_completion_ownership_rejection(
          ownershipRejection, failureCode, mesh, lineage, provenance,
          boundaryVertex, completionVariant, support, patchSourceFaces,
          sourceAuthority, failure);
      return false;
    }

    // Select the compatible source chart by intrinsic source-vertex identity,
    // not source-face row order.  Boundary source-edge/source-vertex points can
    // then be rebound to the owning patch sheet without changing geometry.
    const auto faceKey = [&](const int face) {
      std::array<int, 3> vertices{{-1, -1, -1}};
      if (sourceFaceMatrix != nullptr && face >= 0 &&
          face < sourceFaceMatrix->rows()) {
        vertices = {{(*sourceFaceMatrix)(face, 0), (*sourceFaceMatrix)(face, 1),
                     (*sourceFaceMatrix)(face, 2)}};
        std::sort(vertices.begin(), vertices.end());
      }
      return std::make_pair(vertices, face);
    };
    const int selectedFace = *std::min_element(
        compatibleFaces.begin(), compatibleFaces.end(),
        [&](const int lhs, const int rhs) { return faceKey(lhs) < faceKey(rhs); });
    if (boundaryVertex && selectedFace != provenance.face) {
      if (transitionAuthorityAvailable) {
        SurfacePoint rebound;
        if (!transitionGraph.rebind(provenance, selectedFace, rebound)) {
          failure = "CompletionOwnershipCannotRebindSourceChart";
          return false;
        }
        provenance = rebound;
      } else {
        if (sourceFaceMatrix == nullptr || provenance.face < 0 ||
            provenance.face >= sourceFaceMatrix->rows() || selectedFace < 0 ||
            selectedFace >= sourceFaceMatrix->rows()) {
          failure = "CompletionOwnershipCannotRebindSourceChart";
          return false;
        }
        Eigen::Vector3d rebound = Eigen::Vector3d::Zero();
        if (const auto *vertexSupport =
                std::get_if<authority::SourceVertexSupport>(
                    &support.identity.value())) {
          const int sourceVertex =
              static_cast<int>(vertexSupport->vertex.index());
          bool found = false;
          for (int corner = 0; corner < 3; ++corner) {
            if ((*sourceFaceMatrix)(selectedFace, corner) == sourceVertex) {
              rebound(corner) = 1.0;
              found = true;
              break;
            }
          }
          if (!found) {
            failure = "CompletionOwnershipCannotRebindSourceVertex";
            return false;
          }
        } else if (const auto *edgeSupport =
                       std::get_if<authority::SourceEdgeSupport>(
                           &support.identity.value())) {
          const int sourceA =
              static_cast<int>(edgeSupport->edge.first().index());
          const int sourceB =
              static_cast<int>(edgeSupport->edge.second().index());
          double weightA = 0.0;
          double weightB = 0.0;
          for (int corner = 0; corner < 3; ++corner) {
            const int vertex = (*sourceFaceMatrix)(provenance.face, corner);
            if (vertex == sourceA) {
              weightA += provenance.barycentric(corner);
            } else if (vertex == sourceB) {
              weightB += provenance.barycentric(corner);
            }
          }
          const double weightSum = weightA + weightB;
          if (!std::isfinite(weightSum) || weightSum <= 1.0e-15) {
            failure = "CompletionOwnershipCannotRebindSourceEdgeWeights";
            return false;
          }
          weightA /= weightSum;
          weightB /= weightSum;
          bool foundA = false;
          bool foundB = false;
          for (int corner = 0; corner < 3; ++corner) {
            const int vertex = (*sourceFaceMatrix)(selectedFace, corner);
            if (vertex == sourceA) {
              rebound(corner) = weightA;
              foundA = true;
            } else if (vertex == sourceB) {
              rebound(corner) = weightB;
              foundB = true;
            }
          }
          if (!foundA || !foundB) {
            failure = "CompletionOwnershipCannotRebindSourceEdge";
            return false;
          }
        } else {
          failure = "CompletionOwnershipFaceInteriorChartMismatch";
          return false;
        }
        provenance.face = selectedFace;
        provenance.barycentric = rebound;
        if (sourceAuthority != nullptr) {
          const auto selectedFaceId = authority::SourceFaceId::from_index(
              selectedFace, sourceAuthority->face_count());
          if (!selectedFaceId) {
            failure = "CompletionOwnershipInvalidSelectedFaceAuthority";
            return false;
          }
          provenance.component = static_cast<int>(
              sourceAuthority->component_for_row(selectedFaceId.value()).index());
          provenance.sheet = static_cast<int>(
              sourceAuthority->sheet_for_row(selectedFaceId.value()).index());
        }
      }
    }
    lineage.sourcePoint = provenance;
    if (sourceAuthority != nullptr) {
      const auto selectedFaceId = authority::SourceFaceId::from_index(
          provenance.face, sourceAuthority->face_count());
      if (!selectedFaceId) {
        failure = "CompletionOwnershipInvalidPublishedFaceAuthority";
        return false;
      }
      lineage.sourceTopologyRegions = {
          sourceAuthority->region_for_row(selectedFaceId.value())};
      lineage.sourceIsolationSheets = {
          sourceAuthority->sheet_for_row(selectedFaceId.value())};
      if (const auto chart = transitionGraph.chart(provenance.face);
          chart.has_value()) {
        lineage.sourceCharts = {chart.value()};
      }
      lineage.sourceSupport = support.identity;
    }
  }

  mesh.quadLineage.clear();
  mesh.quadLineage.reserve(mesh.quads.size());
  for (int localQuad = 0; localQuad < static_cast<int>(mesh.quads.size());
       ++localQuad) {
    const std::vector<int> &quad =
        mesh.quads[static_cast<std::size_t>(localQuad)];
    if (quad.size() != 4 ||
        std::set<int>(quad.begin(), quad.end()).size() != 4U) {
      failure = "CompletionOwnershipInvalidLocalQuad";
      return false;
    }
    PureQuadFaceLineage lineage;
    lineage.outputQuad = localQuad;
    lineage.sourcePatch = mesh.sourcePatch;
    lineage.operation = mesh.backend;
    lineage.operationLocalQuad = localQuad;
    lineage.completionVariant = completionVariant;
    lineage.boundaryOnly = true;

    std::array<PureQuadStitchIdentity, 4> stitchCycle;
    std::array<PureQuadStitchIdentity, 4> authoritativeCycle;
    for (int corner = 0; corner < 4; ++corner) {
      const int localVertex = quad[static_cast<std::size_t>(corner)];
      const auto row = vertexRows.find(localVertex);
      if (row == vertexRows.end()) {
        failure = "CompletionOwnershipUnknownLocalVertex";
        return false;
      }
      const PureQuadVertexLineage &vertexLineage =
          mesh.vertexLineage[row->second];
      stitchCycle[static_cast<std::size_t>(corner)] =
          vertexLineage.stitchIdentity;
      authoritativeCycle[static_cast<std::size_t>(corner)] =
          vertexLineage.authoritativeIdentity;
      lineage.boundaryOnly =
          lineage.boundaryOnly && boundaryRows.count(localVertex) != 0U;
    }
    const auto canonicalStitch = canonical_quad_cycle(stitchCycle, false);
    const auto canonicalAuthoritative =
        canonical_quad_cycle(authoritativeCycle, false);
    lineage.canonicalStitchCycleHash =
        stitch_cycle_hash(canonicalStitch.values);
    lineage.canonicalAuthoritativeCycleHash =
        stitch_cycle_hash(canonicalAuthoritative.values);
    mesh.quadLineage.push_back(std::move(lineage));
  }
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool vectors_equal(const std::vector<int> &a, const std::vector<int> &b) {
  return a == b;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

std::pair<int, int> canonical_edge(const int a, const int b) {
  return std::minmax(a, b);
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

std::map<std::pair<int, int>, int>
edge_incidence(const std::vector<std::vector<int>> &quads) {
  std::map<std::pair<int, int>, int> incidence;
  for (const auto &quad : quads) {
    if (quad.size() != 4) continue;
    for (int i = 0; i < 4; ++i) {
      ++incidence[canonical_edge(quad[static_cast<std::size_t>(i)],
                                quad[static_cast<std::size_t>((i + 1) % 4)])];
    }
  }
  return incidence;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

std::map<int, int> vertex_valences(
    const std::vector<std::vector<int>> &quads) {
  std::map<int, std::set<int>> neighbors;
  for (const auto &quad : quads) {
    if (quad.size() != 4) continue;
    for (int i = 0; i < 4; ++i) {
      const int a = quad[static_cast<std::size_t>(i)];
      const int b = quad[static_cast<std::size_t>((i + 1) % 4)];
      neighbors[a].insert(b);
      neighbors[b].insert(a);
    }
  }
  std::map<int, int> result;
  for (const auto &[vertex, adjacent] : neighbors) {
    result[vertex] = static_cast<int>(adjacent.size());
  }
  return result;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

int mesh_euler_characteristic(const std::vector<std::vector<int>> &quads) {
  const auto incidence = edge_incidence(quads);
  std::set<int> vertices;
  for (const auto &quad : quads) vertices.insert(quad.begin(), quad.end());
  return static_cast<int>(vertices.size()) - static_cast<int>(incidence.size()) +
         static_cast<int>(quads.size());
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

std::set<std::pair<int, int>> boundary_edges(
    const std::vector<std::vector<int>> &quads) {
  std::set<std::pair<int, int>> result;
  for (const auto &[edge, count] : edge_incidence(quads)) {
    if (count == 1) result.insert(edge);
  }
  return result;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool quads_are_locally_valid(const std::vector<std::vector<int>> &quads) {
  const auto incidence = edge_incidence(quads);
  for (const auto &quad : quads) {
    if (quad.size() != 4 || std::set<int>(quad.begin(), quad.end()).size() != 4)
      return false;
  }
  return std::all_of(incidence.begin(), incidence.end(),
                     [](const auto &entry) {
                       return entry.second == 1 || entry.second == 2;
                     });
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry {

PureQuadPatchAdmissibility
check_pure_quad_patch_admissibility(const PureQuadPatch &patch) {
  PureQuadPatchAdmissibility result;
  result.expectedInteriorValence =
      pure_quad_detail::expected_valence(patch.singularIndexNumerator);
  if (!patch.diskTopology) {
    result.reason = PureQuadPatchRejectReason::NonDisk;
    return result;
  }
  if (patch.boundaryLoopCount != 1) {
    result.reason = PureQuadPatchRejectReason::BoundaryLoopCount;
    return result;
  }
  const int sides = static_cast<int>(patch.sideEdgeCounts.size());
  if (sides < 3) {
    result.reason = PureQuadPatchRejectReason::SideCountUnsupported;
    return result;
  }
  const bool generalRegularDisk =
      sides > 6 && patch.singularityCount == 0 &&
      !patch.unmatchedInteriorSingularity;
  if (sides > 6 && !generalRegularDisk) {
    result.reason = PureQuadPatchRejectReason::SingularityMismatch;
    return result;
  }
  if (!pure_quad_detail::turns_are_valid(patch)) {
    result.reason = PureQuadPatchRejectReason::InvalidTurn;
    return result;
  }
  if (pure_quad_detail::boundary_edge_count(patch) % 2 != 0) {
    result.reason = PureQuadPatchRejectReason::OddBoundary;
    return result;
  }
  if (patch.hardFeatureCrossing) {
    result.reason = PureQuadPatchRejectReason::HardFeatureCrossing;
    return result;
  }
  if (!std::all_of(patch.sideEdgeCounts.begin(),
                   patch.sideEdgeCounts.end(),
                   [](const int count) { return count > 0; })) {
    result.reason = PureQuadPatchRejectReason::SideInequality;
    return result;
  }
  if (!generalRegularDisk &&
      !pure_quad_detail::side_inequalities_hold(patch.sideEdgeCounts)) {
    result.reason = PureQuadPatchRejectReason::SideInequality;
    return result;
  }
  if (!generalRegularDisk &&
      !pure_quad_detail::hex_parity_holds(patch.sideEdgeCounts)) {
    result.reason = PureQuadPatchRejectReason::HexParity;
    return result;
  }
  if (sides == 4 &&
      (patch.unmatchedInteriorSingularity || patch.singularityCount != 0)) {
    result.reason = PureQuadPatchRejectReason::SingularityMismatch;
    return result;
  }
  if ((sides == 3 || sides == 5 || sides == 6) && patch.singularityCount > 1) {
    result.reason = PureQuadPatchRejectReason::SingularityMismatch;
    return result;
  }
  if ((sides == 3 || sides == 5 || sides == 6) &&
      patch.singularityCount == 1 &&
      result.expectedInteriorValence != sides) {
    result.reason = PureQuadPatchRejectReason::SingularityMismatch;
    return result;
  }
  result.admissible = true;
  result.reason = PureQuadPatchRejectReason::None;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

bool pure_quad_topology_is_disk(const PureQuadMesh &mesh) {
  if (mesh.quads.empty() || mesh.boundaryVertices.size() < 4) {
    return false;
  }
  std::map<std::pair<int, int>, int> incidence;
  std::set<int> usedVertices;
  for (const auto &quad : mesh.quads) {
    if (quad.size() != 4 || std::set<int>(quad.begin(), quad.end()).size() != 4) {
      return false;
    }
    for (int i = 0; i < 4; ++i) {
      const int a = quad[static_cast<std::size_t>(i)];
      const int b = quad[static_cast<std::size_t>((i + 1) % 4)];
      if (a == b) return false;
      ++incidence[std::minmax(a, b)];
      usedVertices.insert(a);
      usedVertices.insert(b);
    }
  }
  std::set<std::pair<int, int>> expectedBoundary;
  for (int i = 0; i < static_cast<int>(mesh.boundaryVertices.size()); ++i) {
    expectedBoundary.insert(std::minmax(
        mesh.boundaryVertices[static_cast<std::size_t>(i)],
        mesh.boundaryVertices[static_cast<std::size_t>(
            (i + 1) % mesh.boundaryVertices.size())]));
  }
  int boundaryEdges = 0;
  for (const auto &[edge, count] : incidence) {
    if (count == 1) {
      ++boundaryEdges;
      if (expectedBoundary.count(edge) == 0) return false;
    } else if (count != 2) {
      return false;
    }
  }
  if (boundaryEdges != static_cast<int>(expectedBoundary.size())) return false;
  const int V = static_cast<int>(usedVertices.size());
  const int E = static_cast<int>(incidence.size());
  const int F = static_cast<int>(mesh.quads.size());
  return V - E + F == 1;
}

} // namespace directional::geometry

namespace directional::geometry::pure_quad_detail {

bool complete_rectangular_grid(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority) {
  if (patch.sideEdgeCounts.size() != 4 ||
      patch.sideEdgeCounts[0] != patch.sideEdgeCounts[2] ||
      patch.sideEdgeCounts[1] != patch.sideEdgeCounts[3]) {
    return false;
  }
  const int width = patch.sideEdgeCounts[0];
  const int height = patch.sideEdgeCounts[1];
  if (width <= 0 || height <= 0) return false;
  std::vector<std::vector<int>> grid(
      static_cast<std::size_t>(height + 1),
      std::vector<int>(static_cast<std::size_t>(width + 1), -1));
  const int boundaryCount = static_cast<int>(patch.boundaryVertices.size());
  int index = 0;
  for (int x = 0; x <= width; ++x) grid[0][x] = patch.boundaryVertices[index++];
  for (int y = 1; y <= height; ++y) grid[y][width] = patch.boundaryVertices[index++];
  for (int x = width - 1; x >= 0; --x) grid[height][x] = patch.boundaryVertices[index++];
  for (int y = height - 1; y >= 1; --y) grid[y][0] = patch.boundaryVertices[index++];

  int nextInterior = -1;
  const SurfacePoint c00 = boundary_source_point(patch, 0);
  const SurfacePoint c10 = boundary_source_point(patch, width);
  const SurfacePoint c11 = boundary_source_point(patch, width + height);
  const SurfacePoint c01 = boundary_source_point(patch, 2 * width + height);
  for (int y = 1; y < height; ++y) {
    for (int x = 1; x < width; ++x) {
      const double u = static_cast<double>(x) / static_cast<double>(width);
      const double v = static_cast<double>(y) / static_cast<double>(height);
      const Eigen::Vector3d target =
          (1.0 - u) * (1.0 - v) * c00.position +
          u * (1.0 - v) * c10.position + u * v * c11.position +
          (1.0 - u) * v * c01.position;
      grid[y][x] = append_embedded_vertex(
          mesh, nextInterior, target, {c00, c10, c11, c01}, projection,
          allowedFaces, sourceAuthority);
      if (grid[y][x] == std::numeric_limits<int>::max()) {
        return false;
      }
    }
  }
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      mesh.quads.push_back({grid[y][x], grid[y][x + 1],
                            grid[y + 1][x + 1], grid[y + 1][x]});
    }
  }
  mesh.backend = PureQuadCompletionBackend::ClosedForm;
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool complete_six_vertex_transition(const PureQuadPatch &patch,
                                    PureQuadMesh &mesh,
                                    const int completionVariant) {
  if (patch.boundaryVertices.size() != 6) return false;
  const auto &v = patch.boundaryVertices;
  const int normalized = normalized_completion_variant(completionVariant, 6);
  const int start = normalized % 3;
  const bool reversed = normalized >= 3;
  const auto at = [&](const int offset) {
    const int signedOffset = reversed ? -offset : offset;
    return v[static_cast<std::size_t>(
        normalized_completion_variant(start + signedOffset, 6))];
  };
  mesh.quads.push_back({at(0), at(1), at(2), at(3)});
  mesh.quads.push_back({at(0), at(3), at(4), at(5)});
  mesh.backend = PureQuadCompletionBackend::TransitionTemplate;
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool append_balanced_boundary_quadrangulation(
    const std::vector<int> &boundary, PureQuadMesh &mesh) {
  const int n = static_cast<int>(boundary.size());
  if (n < 4 || n % 2 != 0) {
    return false;
  }
  if (n == 4) {
    mesh.quads.push_back(boundary);
    return true;
  }

  // Split along an odd-span diagonal so both child polygons remain even.
  // Choosing the diagonal near the polygon midpoint and rotating its start
  // into the current quarter distributes diagonal endpoints across the
  // boundary instead of concentrating every quad at one fan anchor.
  int splitSpan = -1;
  for (int candidate = 3; candidate <= n - 3; candidate += 2) {
    if (splitSpan < 0 ||
        std::abs(2 * candidate - n) < std::abs(2 * splitSpan - n)) {
      splitSpan = candidate;
    }
  }
  if (splitSpan < 0) {
    return false;
  }

  const int splitStart = n / 4;
  std::vector<int> first;
  first.reserve(static_cast<std::size_t>(splitSpan + 1));
  for (int offset = 0; offset <= splitSpan; ++offset) {
    first.push_back(boundary[static_cast<std::size_t>(
        (splitStart + offset) % n)]);
  }

  std::vector<int> second;
  second.reserve(static_cast<std::size_t>(n - splitSpan + 1));
  for (int offset = 0; offset <= n - splitSpan; ++offset) {
    second.push_back(boundary[static_cast<std::size_t>(
        (splitStart + splitSpan + offset) % n)]);
  }

  return append_balanced_boundary_quadrangulation(first, mesh) &&
         append_balanced_boundary_quadrangulation(second, mesh);
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool complete_singularity_pole(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority) {
  if (patch.singularityCount != 1) return false;
  const int valence = expected_valence(patch.singularIndexNumerator);
  if (valence < 3 || valence > 6 ||
      static_cast<int>(patch.sideEdgeCounts.size()) != valence ||
      static_cast<int>(patch.boundaryVertices.size()) != 2 * valence ||
      !std::all_of(patch.sideEdgeCounts.begin(), patch.sideEdgeCounts.end(),
                   [](const int count) { return count == 2; })) {
    return false;
  }
  int nextInterior = -1;
  Eigen::Vector3d target = Eigen::Vector3d::Zero();
  for (const SurfacePoint &point : patch.boundaryProvenance) {
    target += point.position;
  }
  target /= static_cast<double>(patch.boundaryProvenance.size());
  const int pole = append_embedded_vertex(
      mesh, nextInterior, target, patch.boundaryProvenance, projection,
      allowedFaces, sourceAuthority);
  if (pole == std::numeric_limits<int>::max()) {
    return false;
  }
  const auto &v = patch.boundaryVertices;
  for (int i = 0; i < valence; ++i) {
    const int a = v[static_cast<std::size_t>(2 * i)];
    const int b = v[static_cast<std::size_t>(2 * i + 1)];
    const int c = v[static_cast<std::size_t>((2 * i + 2) % (2 * valence))];
    mesh.quads.push_back({pole, a, b, c});
  }
  mesh.backend = PureQuadCompletionBackend::PoleTemplate;
  return vertex_valences(mesh.quads)[pole] == valence;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh,
                      const int completionVariant) {
  if (patch.boundaryVertices.size() < 4 ||
      patch.boundaryVertices.size() % 2 != 0) return false;
  const std::vector<int> boundary =
      rotated_cycle(patch.boundaryVertices, completionVariant);
  if (!append_balanced_boundary_quadrangulation(boundary, mesh)) {
    return false;
  }
  mesh.backend = PureQuadCompletionBackend::Pattern;
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
                      int &explored, const int completionVariant) {
  PureQuadMesh trial = mesh;
  ++explored;
  const std::vector<int> boundary =
      rotated_cycle(patch.boundaryVertices, completionVariant);
  if (!append_balanced_boundary_quadrangulation(boundary, trial) ||
      !pure_quad_topology_is_disk(trial)) {
    return false;
  }
  trial.backend = PureQuadCompletionBackend::BoundedCombinatorial;
  mesh = std::move(trial);
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry {

PureQuadCompletionResult complete_pure_quad_patch(
    const PureQuadPatch &patch,
    const PureQuadCompletionOptions &options) {
  PureQuadCompletionResult result;
  result.admissibility = check_pure_quad_patch_admissibility(patch);
  const bool boundedFallbackAdmissible =
      options.allowBoundedCombinatorialFallback &&
      (result.admissibility.reason ==
           PureQuadPatchRejectReason::SideInequality ||
       result.admissibility.reason == PureQuadPatchRejectReason::HexParity);
  if (!result.admissibility.admissible && !boundedFallbackAdmissible) {
    result.failureReason = result.admissibility.reason;
    return result;
  }
  const int boundaryCount = static_cast<int>(patch.boundaryVertices.size());
  if (boundaryCount != pure_quad_detail::boundary_edge_count(patch) ||
      boundaryCount < 4 || boundaryCount % 2 != 0 ||
      patch.boundaryProvenance.size() != patch.boundaryVertices.size() ||
      !std::all_of(patch.boundaryProvenance.begin(),
                   patch.boundaryProvenance.end(),
                   [](const SurfacePoint &point) { return point.valid(); })) {
    result.failureReason = PureQuadPatchRejectReason::MissingBoundaryData;
    return result;
  }
  if (boundaryCount > options.maxBoundaryEdges) {
    result.failureReason = PureQuadPatchRejectReason::SearchLimitExceeded;
    return result;
  }
  PureQuadMesh mesh;
  mesh.sourcePatch = options.sourcePatch;
  mesh.sourceSideEdgeCounts = patch.sideEdgeCounts;
  pure_quad_detail::initialize_boundary_embedding(patch, mesh);
  if ((options.sourceVertices == nullptr) != (options.sourceFaces == nullptr)) {
    result.failureReason = PureQuadPatchRejectReason::MissingBoundaryData;
    return result;
  }
  std::unique_ptr<SurfaceProjectionBvh> projection;
  std::unique_ptr<SurfacePointSourceSupportResolver> ownedSourceSupport;
  const SurfacePointSourceSupportResolver *sourceSupportResolver =
      options.sourceSupportResolver;
  std::vector<unsigned char> allowedFaces;
  if (options.sourceVertices != nullptr && options.sourceFaces != nullptr) {
    projection = std::make_unique<SurfaceProjectionBvh>(
        *options.sourceVertices, *options.sourceFaces);
    if (sourceSupportResolver == nullptr) {
      ownedSourceSupport = std::make_unique<SurfacePointSourceSupportResolver>(
          *options.sourceFaces);
      sourceSupportResolver = ownedSourceSupport.get();
    }
    if (!patch.sourceFaces.empty()) {
      allowedFaces.assign(static_cast<std::size_t>(options.sourceFaces->rows()),
                          0);
      for (const int face : patch.sourceFaces) {
        if (face >= 0 && face < options.sourceFaces->rows()) {
          allowedFaces[static_cast<std::size_t>(face)] = 1;
        }
      }
    }
  }
  const std::vector<unsigned char> *allowedFacePtr =
      allowedFaces.empty() ? nullptr : &allowedFaces;
  bool completed = false;
  if (!boundedFallbackAdmissible && patch.singularityCount != 0) {
    completed = pure_quad_detail::complete_singularity_pole(
        patch, mesh, projection.get(), allowedFacePtr,
        options.sourceAuthority);
    if (!completed) {
      result.failureReason =
          PureQuadPatchRejectReason::UnsupportedSingularityCompletion;
      return result;
    }
  }
  if (!completed && !boundedFallbackAdmissible) {
    completed = pure_quad_detail::complete_rectangular_grid(
        patch, mesh, projection.get(), allowedFacePtr,
        options.sourceAuthority);
  }
  if (!completed && !boundedFallbackAdmissible && boundaryCount == 6) {
    completed = pure_quad_detail::complete_six_vertex_transition(
        patch, mesh, options.completionVariant);
  }
  if (!completed && !boundedFallbackAdmissible && patch.simple) {
    completed = pure_quad_detail::complete_pattern(
        patch, mesh, options.completionVariant);
  }
  if (!completed && options.allowBoundedCombinatorialFallback) {
    completed = pure_quad_detail::complete_bounded(
        patch, mesh, result.exploredPatterns, options.completionVariant);
  }
  if (!completed) {
    result.failureReason = PureQuadPatchRejectReason::SearchLimitExceeded;
    return result;
  }
  if (!pure_quad_detail::fill_positions(mesh)) {
    result.failureReason = PureQuadPatchRejectReason::MissingBoundaryData;
    return result;
  }
  std::string ownershipFailure;
  if (!pure_quad_detail::validate_completion_domain_ownership(
          patch, mesh, options.completionVariant, sourceSupportResolver,
          options.sourceFaces, options.sourceAuthority, ownershipFailure,
          &result.ownershipRejection, options.sourceHardFeatureEdges)) {
    result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
    result.failure = ownershipFailure;
    return result;
  }
  if (!pure_quad_topology_is_disk(mesh)) {
    result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
    return result;
  }
  if (!pure_quad_detail::completed_quads_have_simple_embedding(
          mesh, options.completionVariant, result.embeddingFailure)) {
    result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
    const PureQuadEmbeddingFailure &failure = result.embeddingFailure;
    std::ostringstream stream;
    stream << "InvalidCompletionQuadEmbedding;patch=" << failure.sourcePatch
           << ";backend="
           << pure_quad_completion_backend_name(failure.backend)
           << ";variant=" << failure.completionVariant
           << ";localQuad=" << failure.localQuad
           << ";classification="
           << pure_quad_embedding_failure_name(failure.kind)
           << ";vertices=" << failure.localVertices[0] << ','
           << failure.localVertices[1] << ',' << failure.localVertices[2]
           << ',' << failure.localVertices[3]
           << ";sourceFaces=";
    for (std::size_t index = 0; index < failure.sourceFaces.size(); ++index) {
      if (index != 0U) {
        stream << ',';
      }
      stream << failure.sourceFaces[index];
    }
    result.failure = stream.str();
    return result;
  }
  result.mesh = std::move(mesh);
  result.success = true;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

namespace {

struct CompletedFaceOwnershipRecord {
  int patchIndex = -1;
  int localQuad = -1;
  std::array<int, 4> localRows{{-1, -1, -1, -1}};
  std::array<int, 4> localVertices{{-1, -1, -1, -1}};
  std::array<int, 4> globalVertices{{-1, -1, -1, -1}};
};

std::int64_t stable_patch_owner(const PureQuadMesh &patch) {
  if (patch.sourcePatch >= 0) {
    return static_cast<std::int64_t>(patch.sourcePatch);
  }
  if (patch.domainIdentity.valid) {
    return static_cast<std::int64_t>(patch.domainIdentity.hash());
  }
  std::uint64_t seed = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    seed ^= static_cast<std::uint64_t>(value);
    seed *= 1099511628211ULL;
  };
  mix(patch.vertexPositions.rows());
  mix(static_cast<std::int64_t>(patch.quads.size()));
  for (int row = 0; row < patch.vertexPositions.rows(); ++row) {
    for (int column = 0; column < patch.vertexPositions.cols(); ++column) {
      mix(static_cast<std::int64_t>(std::llround(
          patch.vertexPositions(row, column) * 1.0e10)));
    }
  }
  return static_cast<std::int64_t>(seed);
}

PureQuadStitchIdentity typed_lineage_stitch_identity(
    const PureQuadVertexLineage &lineage, const bool sharedBoundary,
    const std::int64_t patchOwner, const int localVertex) {
  std::vector<authority::TopologyRegionId> topologyRegions =
      lineage.sourceTopologyRegions;
  std::vector<authority::IsolationSheetId> isolationSheets =
      lineage.sourceIsolationSheets;
  std::sort(topologyRegions.begin(), topologyRegions.end());
  topologyRegions.erase(
      std::unique(topologyRegions.begin(), topologyRegions.end()),
      topologyRegions.end());
  std::sort(isolationSheets.begin(), isolationSheets.end());
  isolationSheets.erase(
      std::unique(isolationSheets.begin(), isolationSheets.end()),
      isolationSheets.end());
  if (topologyRegions.empty() || isolationSheets.empty()) {
    return {};
  }

  PureQuadStitchIdentity key;
  key.kind = sharedBoundary
                 ? PureQuadStitchIdentityKind::ArrangementBoundaryNode
                 : PureQuadStitchIdentityKind::GeneratedPatchInterior;
  key.canonical.valid = true;
  key.canonical.values = sharedBoundary
                             ? std::vector<std::int64_t>{localVertex}
                             : std::vector<std::int64_t>{patchOwner, localVertex};
  key.canonical.values.push_back(
      static_cast<std::int64_t>(topologyRegions.size()));
  for (const authority::TopologyRegionId region : topologyRegions) {
    key.canonical.values.push_back(static_cast<std::int64_t>(region.index()));
  }
  key.canonical.values.push_back(
      static_cast<std::int64_t>(isolationSheets.size()));
  for (const authority::IsolationSheetId sheet : isolationSheets) {
    key.canonical.values.push_back(static_cast<std::int64_t>(sheet.index()));
  }
  return key;
}

PureQuadStitchIdentity resolved_stitch_identity(
    const PureQuadMesh &patch, const int localRow,
    const bool sharedBoundary, const std::int64_t patchOwner) {
  const int localVertex =
      patch.vertices[static_cast<std::size_t>(localRow)];
  const PureQuadVertexLineage &lineage =
      patch.vertexLineage[static_cast<std::size_t>(localRow)];
  PureQuadStitchIdentity key = lineage.stitchIdentity;
  if (!key.valid() ||
      (!sharedBoundary &&
       key.kind != PureQuadStitchIdentityKind::GeneratedPatchInterior)) {
    key = typed_lineage_stitch_identity(lineage, sharedBoundary, patchOwner,
                                        localVertex);
  }
  return key;
}

PureQuadStitchIdentity resolved_stitch_identity(
    const PureQuadMesh &patch, const int localRow) {
  const int localVertex =
      patch.vertices[static_cast<std::size_t>(localRow)];
  const bool sharedBoundary =
      std::find(patch.boundaryVertices.begin(), patch.boundaryVertices.end(),
                localVertex) != patch.boundaryVertices.end();
  return resolved_stitch_identity(patch, localRow, sharedBoundary,
                                  stable_patch_owner(patch));
}

PureQuadStitchIdentity resolved_authoritative_identity(
    const PureQuadMesh &patch, const int localRow) {
  const PureQuadStitchIdentity &authoritative =
      patch.vertexLineage[static_cast<std::size_t>(localRow)]
          .authoritativeIdentity;
  return authoritative.valid() ? authoritative
                               : resolved_stitch_identity(patch, localRow);
}

CompletedFaceOwnershipRecord make_completed_face_ownership(
    const int patchIndex, const int localQuad,
    const std::vector<int> &localQuadVertices,
    const std::array<int, 4> &globalQuad,
    const std::unordered_map<int, int> &localRows) {
  CompletedFaceOwnershipRecord record;
  record.patchIndex = patchIndex;
  record.localQuad = localQuad;
  record.globalVertices = globalQuad;
  for (int corner = 0; corner < 4; ++corner) {
    const int localVertex =
        localQuadVertices[static_cast<std::size_t>(corner)];
    const auto row = localRows.find(localVertex);
    if (row == localRows.end()) {
      continue;
    }
    record.localRows[static_cast<std::size_t>(corner)] = row->second;
    record.localVertices[static_cast<std::size_t>(corner)] = localVertex;
  }
  return record;
}

struct ConflictDiagnosticCornerKey {
  PureQuadStitchIdentity stitchIdentity;
  PureQuadStitchIdentity authoritativeIdentity;

  friend bool operator<(const ConflictDiagnosticCornerKey &lhs,
                        const ConflictDiagnosticCornerKey &rhs) {
    return std::tie(lhs.stitchIdentity, lhs.authoritativeIdentity) <
           std::tie(rhs.stitchIdentity, rhs.authoritativeIdentity);
  }
};

std::array<PureQuadStitchIdentity, 4> exact_canonical_cycle(
    const CompletedFaceOwnershipRecord &record, const PureQuadMesh &patch,
    const bool authoritative) {
  std::array<PureQuadStitchIdentity, 4> cycle;
  for (int corner = 0; corner < 4; ++corner) {
    const int row = record.localRows[static_cast<std::size_t>(corner)];
    if (row >= 0 && row < static_cast<int>(patch.vertices.size())) {
      cycle[static_cast<std::size_t>(corner)] = authoritative
          ? resolved_authoritative_identity(patch, row)
          : resolved_stitch_identity(patch, row);
    }
  }
  const auto forward = pure_quad_detail::canonical_quad_cycle(cycle, false);
  const auto reversed = pure_quad_detail::canonical_quad_cycle(cycle, true);
  return reversed.values < forward.values ? reversed.values : forward.values;
}

void copy_conflict_corner_diagnostics(
    const CompletedFaceOwnershipRecord &record,
    const PureQuadMesh &patch,
    std::array<int, 4> &kinds,
    std::array<std::uint64_t, 4> &identityHashes,
    std::array<std::uint64_t, 4> &authoritativeHashes,
    std::array<int, 4> &localVertices,
    std::array<int, 4> &globalVertices) {
  std::array<ConflictDiagnosticCornerKey, 4> diagnosticCycle;
  for (int corner = 0; corner < 4; ++corner) {
    const int row = record.localRows[static_cast<std::size_t>(corner)];
    if (row < 0 || row >= static_cast<int>(patch.vertices.size())) {
      continue;
    }
    diagnosticCycle[static_cast<std::size_t>(corner)] = {
        resolved_stitch_identity(patch, row),
        resolved_authoritative_identity(patch, row)};
  }
  const auto forward =
      pure_quad_detail::canonical_quad_cycle(diagnosticCycle, false);
  const auto reversed =
      pure_quad_detail::canonical_quad_cycle(diagnosticCycle, true);
  const auto &order = reversed.values < forward.values
                          ? reversed.sourceIndices
                          : forward.sourceIndices;
  for (int corner = 0; corner < 4; ++corner) {
    const int sourceIndex = order[static_cast<std::size_t>(corner)];
    const int row = record.localRows[static_cast<std::size_t>(sourceIndex)];
    if (row < 0 || row >= static_cast<int>(patch.vertices.size())) {
      continue;
    }
    const PureQuadStitchIdentity stitch =
        resolved_stitch_identity(patch, row);
    const PureQuadStitchIdentity authoritative =
        resolved_authoritative_identity(patch, row);
    kinds[static_cast<std::size_t>(corner)] = static_cast<int>(stitch.kind);
    identityHashes[static_cast<std::size_t>(corner)] = stitch.hash();
    authoritativeHashes[static_cast<std::size_t>(corner)] =
        authoritative.hash();
    localVertices[static_cast<std::size_t>(corner)] =
        record.localVertices[static_cast<std::size_t>(sourceIndex)];
    globalVertices[static_cast<std::size_t>(corner)] =
        record.globalVertices[static_cast<std::size_t>(sourceIndex)];
  }
}

SurfaceCellCompletedFaceOwnerIdentity exact_owner_identity(
    const CompletedFaceOwnershipRecord &record, const PureQuadMesh &patch) {
  SurfaceCellCompletedFaceOwnerIdentity identity;
  identity.domain = patch.domainIdentity;
  identity.canonicalStitchCycle =
      exact_canonical_cycle(record, patch, false);
  identity.canonicalAuthoritativeCycle =
      exact_canonical_cycle(record, patch, true);
  identity.sourcePatch = patch.sourcePatch;
  identity.localQuad = record.localQuad;
  if (record.localQuad >= 0 &&
      record.localQuad < static_cast<int>(patch.quadLineage.size())) {
    const PureQuadFaceLineage &faceLineage =
        patch.quadLineage[static_cast<std::size_t>(record.localQuad)];
    identity.completionBackend = static_cast<int>(faceLineage.operation);
    identity.completionVariant = faceLineage.completionVariant;
  } else {
    identity.completionBackend = static_cast<int>(patch.backend);
  }
  identity.boundaryVertexCount =
      static_cast<int>(patch.boundaryVertices.size());
  identity.sideEdgeCounts = patch.sourceSideEdgeCounts;
  return identity;
}

SurfaceCellOwnershipConflict make_ownership_conflict(
    const CompletedFaceOwnershipRecord &firstRecord,
    const CompletedFaceOwnershipRecord &secondRecord,
    const std::vector<PureQuadMesh> &patches) {
  const PureQuadMesh &firstPatch =
      patches[static_cast<std::size_t>(firstRecord.patchIndex)];
  const PureQuadMesh &secondPatch =
      patches[static_cast<std::size_t>(secondRecord.patchIndex)];
  SurfaceCellOwnershipConflict conflict;
  conflict.firstOwner = exact_owner_identity(firstRecord, firstPatch);
  conflict.secondOwner = exact_owner_identity(secondRecord, secondPatch);

  const CompletedFaceOwnershipRecord *first = &firstRecord;
  const CompletedFaceOwnershipRecord *second = &secondRecord;
  const PureQuadMesh *firstMesh = &firstPatch;
  const PureQuadMesh *secondMesh = &secondPatch;
  if (conflict.secondOwner < conflict.firstOwner) {
    std::swap(conflict.firstOwner, conflict.secondOwner);
    std::swap(first, second);
    std::swap(firstMesh, secondMesh);
  }

  conflict.firstPatch = firstMesh->sourcePatch;
  conflict.firstLocalQuad = first->localQuad;
  conflict.secondPatch = secondMesh->sourcePatch;
  conflict.secondLocalQuad = second->localQuad;
  conflict.firstDomainHash = firstMesh->domainIdentity.hash();
  conflict.secondDomainHash = secondMesh->domainIdentity.hash();
  conflict.firstBoundaryNodeHash =
      firstMesh->domainIdentity.orientedBoundary.hash();
  conflict.secondBoundaryNodeHash =
      secondMesh->domainIdentity.orientedBoundary.hash();
  conflict.firstBoundaryHalfedgeHash =
      firstMesh->domainIdentity.undirectedBoundary.hash();
  conflict.secondBoundaryHalfedgeHash =
      secondMesh->domainIdentity.undirectedBoundary.hash();
  conflict.firstSourceSupportHash =
      firstMesh->domainIdentity.sourceSupport.hash();
  conflict.secondSourceSupportHash =
      secondMesh->domainIdentity.sourceSupport.hash();
  conflict.firstSourceSupportCount =
      firstMesh->domainIdentity.sourceSupportCount;
  conflict.secondSourceSupportCount =
      secondMesh->domainIdentity.sourceSupportCount;
  const auto [firstComponent, firstSheet] =
      pure_quad_detail::diagnostic_source_scope(*firstMesh);
  const auto [secondComponent, secondSheet] =
      pure_quad_detail::diagnostic_source_scope(*secondMesh);
  conflict.firstComponent = firstComponent;
  conflict.firstSheet = firstSheet;
  conflict.secondComponent = secondComponent;
  conflict.secondSheet = secondSheet;
  const PureQuadFaceLineage &firstLineage =
      firstMesh->quadLineage[static_cast<std::size_t>(first->localQuad)];
  const PureQuadFaceLineage &secondLineage =
      secondMesh->quadLineage[static_cast<std::size_t>(second->localQuad)];
  conflict.firstCompletionBackend = static_cast<int>(firstLineage.operation);
  conflict.secondCompletionBackend = static_cast<int>(secondLineage.operation);
  conflict.firstCompletionVariant = firstLineage.completionVariant;
  conflict.secondCompletionVariant = secondLineage.completionVariant;
  conflict.firstBoundaryNodeCount =
      firstMesh->domainIdentity.boundaryNodeCount;
  conflict.secondBoundaryNodeCount =
      secondMesh->domainIdentity.boundaryNodeCount;
  conflict.firstBoundaryHalfedgeCount =
      firstMesh->domainIdentity.boundaryHalfedgeCount;
  conflict.secondBoundaryHalfedgeCount =
      secondMesh->domainIdentity.boundaryHalfedgeCount;
  conflict.firstBoundaryVertexCount =
      static_cast<int>(firstMesh->boundaryVertices.size());
  conflict.secondBoundaryVertexCount =
      static_cast<int>(secondMesh->boundaryVertices.size());
  conflict.firstSideEdgeCounts = firstMesh->sourceSideEdgeCounts;
  conflict.secondSideEdgeCounts = secondMesh->sourceSideEdgeCounts;
  copy_conflict_corner_diagnostics(
      *first, *firstMesh, conflict.firstCornerIdentityKinds,
      conflict.firstCornerIdentityHashes,
      conflict.firstCornerAuthoritativeHashes, conflict.firstLocalVertices,
      conflict.firstGlobalVertices);
  copy_conflict_corner_diagnostics(
      *second, *secondMesh, conflict.secondCornerIdentityKinds,
      conflict.secondCornerIdentityHashes,
      conflict.secondCornerAuthoritativeHashes, conflict.secondLocalVertices,
      conflict.secondGlobalVertices);

  if (firstMesh->domainIdentity.same_oriented_domain(
          secondMesh->domainIdentity)) {
    conflict.classification =
        SurfaceCellOwnershipConflictClass::DuplicateOrientedDomain;
  } else if (firstMesh->domainIdentity.same_undirected_support(
                 secondMesh->domainIdentity)) {
    conflict.classification =
        SurfaceCellOwnershipConflictClass::OverlappingUndirectedBoundary;
  } else if (conflict.firstOwner.canonicalAuthoritativeCycle ==
             conflict.secondOwner.canonicalAuthoritativeCycle) {
    const bool sameSourceSupport =
        firstMesh->domainIdentity.valid && secondMesh->domainIdentity.valid &&
        firstMesh->domainIdentity.sourceSupport.valid &&
        secondMesh->domainIdentity.sourceSupport.valid &&
        firstMesh->domainIdentity.sourceSupport ==
            secondMesh->domainIdentity.sourceSupport &&
        firstMesh->domainIdentity.sourceSupportCount ==
            secondMesh->domainIdentity.sourceSupportCount &&
        firstMesh->domainIdentity.same_source_ownership(
            secondMesh->domainIdentity);
    conflict.classification =
        sameSourceSupport
            ? SurfaceCellOwnershipConflictClass::SameCornerDistinctBoundaryClaim
            : SurfaceCellOwnershipConflictClass::CompletionTemplateOwnership;
  } else if (conflict.firstOwner.canonicalStitchCycle ==
             conflict.secondOwner.canonicalStitchCycle) {
    conflict.classification =
        SurfaceCellOwnershipConflictClass::FalseVertexEquivalence;
  } else {
    conflict.classification = SurfaceCellOwnershipConflictClass::Unclassified;
  }
  return conflict;
}

std::string ownership_conflict_failure(
    const SurfaceCellOwnershipConflict &conflict) {
  const auto cornerKinds = [](const std::array<int, 4> &kinds) {
    std::ostringstream stream;
    for (int corner = 0; corner < 4; ++corner) {
      if (corner != 0) {
        stream << ',';
      }
      stream << pure_quad_stitch_identity_kind_name(
          static_cast<PureQuadStitchIdentityKind>(
              kinds[static_cast<std::size_t>(corner)]));
    }
    return stream.str();
  };
  return "DuplicateStitchedQuad:firstPatch=" +
         std::to_string(conflict.firstPatch) +
         ";firstLocalQuad=" + std::to_string(conflict.firstLocalQuad) +
         ";secondPatch=" + std::to_string(conflict.secondPatch) +
         ";secondLocalQuad=" + std::to_string(conflict.secondLocalQuad) +
         ";globalVertices=" +
         pure_quad_detail::integer_list(std::vector<int>(
             conflict.firstGlobalVertices.begin(),
             conflict.firstGlobalVertices.end())) +
         ";classification=" +
         surface_cell_ownership_conflict_name(conflict.classification) +
         ";firstBackend=" +
         pure_quad_completion_backend_name(
             static_cast<PureQuadCompletionBackend>(
                 conflict.firstCompletionBackend)) +
         ";firstVariant=" +
         std::to_string(conflict.firstCompletionVariant) +
         ";secondBackend=" +
         pure_quad_completion_backend_name(
             static_cast<PureQuadCompletionBackend>(
                 conflict.secondCompletionBackend)) +
         ";secondVariant=" +
         std::to_string(conflict.secondCompletionVariant) +
         ";firstCornerKinds=" +
         cornerKinds(conflict.firstCornerIdentityKinds) +
         ";secondCornerKinds=" +
         cornerKinds(conflict.secondCornerIdentityKinds) +
         ";firstDomainHash=" + std::to_string(conflict.firstDomainHash) +
         ";secondDomainHash=" + std::to_string(conflict.secondDomainHash) +
         ";firstBoundaryNodeHash=" +
         std::to_string(conflict.firstBoundaryNodeHash) +
         ";secondBoundaryNodeHash=" +
         std::to_string(conflict.secondBoundaryNodeHash) +
         ";firstBoundaryHalfedgeHash=" +
         std::to_string(conflict.firstBoundaryHalfedgeHash) +
         ";secondBoundaryHalfedgeHash=" +
         std::to_string(conflict.secondBoundaryHalfedgeHash) +
         ";firstSourceSupportHash=" +
         std::to_string(conflict.firstSourceSupportHash) +
         ";secondSourceSupportHash=" +
         std::to_string(conflict.secondSourceSupportHash) +
         ";exactConflictHash=" + std::to_string(conflict.exact_hash());
}


} // namespace

PureQuadAssemblyResult stitch_pure_quad_patches(
    const std::vector<PureQuadMesh> &patches,
    const double positionTolerance,
    const Eigen::MatrixXi *sourceFaces,
    const SourceTopologyRegions *sourceAuthority,
    const std::set<std::uint64_t> *sourceHardFeatureEdges) {
  PureQuadAssemblyResult result;
  if (patches.empty()) {
    result.failure = "NoCompletedPatches";
    return result;
  }


  std::vector<int> patchOrder(patches.size());
  std::iota(patchOrder.begin(), patchOrder.end(), 0);
  std::sort(patchOrder.begin(), patchOrder.end(), [&](const int lhs,
                                                       const int rhs) {
    const PureQuadMesh &a = patches[static_cast<std::size_t>(lhs)];
    const PureQuadMesh &b = patches[static_cast<std::size_t>(rhs)];
    if (a.domainIdentity < b.domainIdentity) {
      return true;
    }
    if (b.domainIdentity < a.domainIdentity) {
      return false;
    }
    const std::int64_t ownerA = stable_patch_owner(a);
    const std::int64_t ownerB = stable_patch_owner(b);
    if (ownerA != ownerB) {
      return ownerA < ownerB;
    }
    if (a.vertices != b.vertices) {
      return a.vertices < b.vertices;
    }
    return a.quads < b.quads;
  });

  struct StitchIdentityHash {
    std::size_t operator()(const PureQuadStitchIdentity &identity) const {
      return static_cast<std::size_t>(identity.hash());
    }
  };
  struct CanonicalQuadHash {
    std::size_t operator()(const std::array<int, 4> &quad) const {
      std::uint64_t seed = 1469598103934665603ULL;
      for (const int vertex : quad) {
        seed ^= static_cast<std::uint64_t>(vertex);
        seed *= 1099511628211ULL;
      }
      return static_cast<std::size_t>(seed);
    }
  };
  struct PendingOutputVertex {
    Eigen::Vector3d position = Eigen::Vector3d::Zero();
    int provenancePatchIndex = -1;
    int provenanceLocalRow = -1;
    int lineagePatchIndex = -1;
    int lineageLocalRow = -1;
    std::vector<std::pair<int, int>> provenanceCandidates;
  };
  std::size_t expectedVertexCount = 0;
  std::size_t expectedFaceCount = 0;
  for (const PureQuadMesh &patch : patches) {
    expectedVertexCount += patch.vertices.size();
    expectedFaceCount += patch.quads.size();
  }

  std::unordered_map<PureQuadStitchIdentity, int, StitchIdentityHash>
      vertexRows;
  vertexRows.reserve(expectedVertexCount);
  std::vector<PendingOutputVertex> pendingVertices;
  pendingVertices.reserve(expectedVertexCount);
  // Keep the first owner records in one contiguous vector. The canonical-face
  // registry stores only a compact index into it; this avoids duplicating the
  // full owner record in both a hash node and a deferred output-face vector.
  std::vector<CompletedFaceOwnershipRecord> uniqueFaceOwners;
  uniqueFaceOwners.reserve(expectedFaceCount);
  std::unordered_map<std::array<int, 4>, std::uint32_t,
                     CanonicalQuadHash>
      canonicalQuadFirstOwnerIndices;
  canonicalQuadFirstOwnerIndices.reserve(expectedFaceCount);
  std::unordered_map<std::array<int, 4>,
                     std::vector<CompletedFaceOwnershipRecord>,
                     CanonicalQuadHash>
      canonicalQuadDuplicateOwners;
  std::uint64_t peakPatchLocalOwnedBytes = 0U;

  const auto unorderedOwnedBytes = [](const auto &container) {
    using Container = std::decay_t<decltype(container)>;
    return static_cast<std::uint64_t>(container.size()) *
               (sizeof(typename Container::value_type) +
                2U * sizeof(void *)) +
           static_cast<std::uint64_t>(container.bucket_count()) *
               sizeof(void *);
  };
  const auto updateWorkspaceEstimates = [&]() {
    std::uint64_t duplicatePayloadBytes = 0U;
    for (const auto &[canonical, owners] : canonicalQuadDuplicateOwners) {
      (void)canonical;
      duplicatePayloadBytes +=
          static_cast<std::uint64_t>(owners.capacity()) *
          sizeof(CompletedFaceOwnershipRecord);
    }
    result.estimatedOwnershipRegistryOwnedBytes =
        unorderedOwnedBytes(vertexRows) +
        unorderedOwnedBytes(canonicalQuadFirstOwnerIndices) +
        unorderedOwnedBytes(canonicalQuadDuplicateOwners) +
        duplicatePayloadBytes;
    result.estimatedDeferredOutputOwnedBytes =
        static_cast<std::uint64_t>(pendingVertices.capacity()) *
            sizeof(PendingOutputVertex) +
        static_cast<std::uint64_t>(uniqueFaceOwners.capacity()) *
            sizeof(CompletedFaceOwnershipRecord);
    result.estimatedWorkspaceOwnedBytes =
        result.estimatedOwnershipRegistryOwnedBytes +
        result.estimatedDeferredOutputOwnedBytes +
        static_cast<std::uint64_t>(patchOrder.capacity()) * sizeof(int) +
        static_cast<std::uint64_t>(result.ownershipConflicts.capacity()) *
            sizeof(SurfaceCellOwnershipConflict) +
        peakPatchLocalOwnedBytes;
  };

  for (const int patchIndex : patchOrder) {
    const PureQuadMesh &patch = patches[static_cast<std::size_t>(patchIndex)];
    if (patch.vertices.size() !=
            static_cast<std::size_t>(patch.vertexPositions.rows()) ||
        patch.vertices.size() != patch.vertexProvenance.size() ||
        patch.vertices.size() != patch.vertexLineage.size() ||
        patch.quads.size() != patch.quadLineage.size()) {
      result.failure = "IncompletePatchLineage";
      return result;
    }

    const std::unordered_set<int> boundary(patch.boundaryVertices.begin(),
                                           patch.boundaryVertices.end());
    const std::int64_t patchOwner = stable_patch_owner(patch);
    std::unordered_map<int, int> localToGlobal;
    std::unordered_map<int, int> localRows;
    localToGlobal.reserve(patch.vertices.size());
    localRows.reserve(patch.vertices.size());
    peakPatchLocalOwnedBytes = std::max(
        peakPatchLocalOwnedBytes,
        unorderedOwnedBytes(boundary) + unorderedOwnedBytes(localToGlobal) +
            unorderedOwnedBytes(localRows));
    for (int localRow = 0; localRow < static_cast<int>(patch.vertices.size());
         ++localRow) {
      const int localVertex = patch.vertices[static_cast<std::size_t>(localRow)];
      const bool sharedBoundary = boundary.count(localVertex) != 0U;
      const SurfacePoint &provenance =
          patch.vertexProvenance[static_cast<std::size_t>(localRow)];
      const PureQuadVertexLineage &incoming =
          patch.vertexLineage[static_cast<std::size_t>(localRow)];
      const PureQuadStitchIdentity key = resolved_stitch_identity(
          patch, localRow, sharedBoundary, patchOwner);
      if (!key.valid()) {
        result.failure = "MissingTypedStitchIdentity";
        return result;
      }
      localRows.emplace(localVertex, localRow);

      const Eigen::Vector3d position =
          patch.vertexPositions.row(localRow).transpose();
      const auto existing = vertexRows.find(key);
      int globalRow = -1;
      if (existing == vertexRows.end()) {
        globalRow = static_cast<int>(pendingVertices.size());
        vertexRows.emplace(key, globalRow);
        PendingOutputVertex pending;
        pending.position = position;
        pending.provenancePatchIndex = patchIndex;
        pending.provenanceLocalRow = localRow;
        pending.lineagePatchIndex = patchIndex;
        pending.lineageLocalRow = localRow;
        pending.provenanceCandidates.emplace_back(patchIndex, localRow);
        pendingVertices.push_back(std::move(pending));
      } else {
        globalRow = existing->second;
        PendingOutputVertex &stored =
            pendingVertices[static_cast<std::size_t>(globalRow)];
        if ((stored.position - position).norm() > positionTolerance) {
          result.failure = "InconsistentSharedBoundaryPosition";
          return result;
        }
        ++result.mergedBoundaryVertices;
        stored.provenanceCandidates.emplace_back(patchIndex, localRow);
        const PureQuadVertexLineage &storedLineage =
            patches[static_cast<std::size_t>(stored.lineagePatchIndex)]
                .vertexLineage[static_cast<std::size_t>(
                    stored.lineageLocalRow)];
        if (storedLineage.kind == PureQuadVertexLineageKind::SourceTriangle &&
            incoming.kind ==
                PureQuadVertexLineageKind::OrderedFeatureInterval) {
          stored.lineagePatchIndex = patchIndex;
          stored.lineageLocalRow = localRow;
        }
      }
      localToGlobal.emplace(localVertex, globalRow);
    }
    peakPatchLocalOwnedBytes = std::max(
        peakPatchLocalOwnedBytes,
        unorderedOwnedBytes(boundary) + unorderedOwnedBytes(localToGlobal) +
            unorderedOwnedBytes(localRows));

    for (int localQuad = 0; localQuad < static_cast<int>(patch.quads.size());
         ++localQuad) {
      const std::vector<int> &quad =
          patch.quads[static_cast<std::size_t>(localQuad)];
      if (quad.size() != 4) {
        result.failure = "NonQuadPatchFace";
        return result;
      }
      std::array<int, 4> globalQuad{{-1, -1, -1, -1}};
      for (int corner = 0; corner < 4; ++corner) {
        const int localCorner = quad[static_cast<std::size_t>(corner)];
        const auto mapped = localToGlobal.find(localCorner);
        if (mapped == localToGlobal.end()) {
          result.failure = "UnknownPatchVertex";
          return result;
        }
        globalQuad[static_cast<std::size_t>(corner)] = mapped->second;
      }
      std::array<int, 4> canonical = globalQuad;
      std::sort(canonical.begin(), canonical.end());
      if (std::adjacent_find(canonical.begin(), canonical.end()) !=
          canonical.end()) {
        result.failure = "DegenerateStitchedQuad";
        return result;
      }
      CompletedFaceOwnershipRecord ownership =
          make_completed_face_ownership(patchIndex, localQuad, quad,
                                        globalQuad, localRows);
      if (std::any_of(ownership.localRows.begin(), ownership.localRows.end(),
                      [](const int row) { return row < 0; })) {
        result.failure = "UnknownPatchVertex";
        return result;
      }
      const std::uint32_t nextOwnerIndex =
          static_cast<std::uint32_t>(uniqueFaceOwners.size());
      const auto [firstOwnerIndex, inserted] =
          canonicalQuadFirstOwnerIndices.emplace(canonical, nextOwnerIndex);
      if (inserted) {
        uniqueFaceOwners.push_back(std::move(ownership));
        continue;
      }
      const CompletedFaceOwnershipRecord &firstOwner =
          uniqueFaceOwners[static_cast<std::size_t>(firstOwnerIndex->second)];
      auto duplicates = canonicalQuadDuplicateOwners.find(canonical);
      if (duplicates == canonicalQuadDuplicateOwners.end()) {
        std::vector<CompletedFaceOwnershipRecord> owners;
        owners.reserve(3);
        owners.push_back(firstOwner);
        owners.push_back(std::move(ownership));
        for (std::size_t previous = 0; previous + 1 < owners.size();
             ++previous) {
          result.ownershipConflicts.push_back(make_ownership_conflict(
              owners[previous], owners.back(), patches));
        }
        canonicalQuadDuplicateOwners.emplace(canonical, std::move(owners));
      } else {
        for (const CompletedFaceOwnershipRecord &previous :
             duplicates->second) {
          result.ownershipConflicts.push_back(make_ownership_conflict(
              previous, ownership, patches));
        }
        duplicates->second.push_back(std::move(ownership));
      }
    }
  }

  if (!result.ownershipConflicts.empty()) {
    std::sort(result.ownershipConflicts.begin(), result.ownershipConflicts.end());
    result.ownershipConflicts.erase(
        std::unique(result.ownershipConflicts.begin(),
                    result.ownershipConflicts.end()),
        result.ownershipConflicts.end());
    result.ownershipConflict = result.ownershipConflicts.front();
    result.failure = ownership_conflict_failure(result.ownershipConflict) +
                     ";inventoryCount=" +
                     std::to_string(result.ownershipConflicts.size());
    updateWorkspaceEstimates();
    return result;
  }

  updateWorkspaceEstimates();
  result.mesh.vertices.resize(pendingVertices.size());
  std::iota(result.mesh.vertices.begin(), result.mesh.vertices.end(), 0);
  result.mesh.vertexPositions.resize(
      static_cast<int>(pendingVertices.size()), 3);
  result.mesh.vertexProvenance.reserve(pendingVertices.size());
  result.mesh.vertexLineage.reserve(pendingVertices.size());
  const bool sourceAuthorityAvailable =
      sourceFaces != nullptr && sourceFaces->cols() == 3 &&
      sourceAuthority != nullptr &&
      sourceAuthority->complete_for_face_count(
          static_cast<std::size_t>(sourceFaces->rows()));
  const SurfacePointSourceSupportResolver sourceSupport(sourceFaces);
  const SourceChartTransitionGraph sourceTransitions(
      sourceFaces, sourceAuthority, sourceHardFeatureEdges);
  const auto canonicalSharedProvenance = [&](const PendingOutputVertex &pending) {
    const PureQuadMesh &fallbackPatch =
        patches[static_cast<std::size_t>(pending.provenancePatchIndex)];
    SurfacePoint selected = fallbackPatch.vertexProvenance[
        static_cast<std::size_t>(pending.provenanceLocalRow)];
    if (!sourceAuthorityAvailable ||
        pending.provenanceCandidates.size() < 2U) {
      return selected;
    }

    if (sourceTransitions.available()) {
      std::vector<const SurfacePoint *> candidates;
      candidates.reserve(pending.provenanceCandidates.size());
      SurfaceCellCanonicalIdentity commonEntity;
      bool haveEntity = false;
      for (const auto &[patchIndex, localRow] :
           pending.provenanceCandidates) {
        if (patchIndex < 0 || patchIndex >= static_cast<int>(patches.size()) ||
            localRow < 0 ||
            localRow >= static_cast<int>(
                patches[static_cast<std::size_t>(patchIndex)]
                    .vertexProvenance.size())) {
          return selected;
        }
        const SurfacePoint &candidate =
            patches[static_cast<std::size_t>(patchIndex)]
                .vertexProvenance[static_cast<std::size_t>(localRow)];
        const auto entity = sourceTransitions.resolve_entity(candidate);
        if (!entity.has_value() || !entity->valid() ||
            (haveEntity && entity->canonical != commonEntity)) {
          return selected;
        }
        if (!haveEntity) {
          commonEntity = entity->canonical;
          haveEntity = true;
        }
        candidates.push_back(&candidate);
      }
      if (!haveEntity || candidates.empty()) {
        return selected;
      }
      const SurfacePointSourceSupport firstSupport =
          sourceSupport.resolve(*candidates.front());
      if (!firstSupport.valid()) {
        return selected;
      }
      std::vector<int> compatibleFaces;
      for (const authority::SourceFaceId sourceFace :
           firstSupport.incidentFaces) {
        const int face = static_cast<int>(sourceFace.index());
        bool allCompatible = true;
        for (const SurfacePoint *candidate : candidates) {
          SurfacePoint rebound;
          if (!sourceTransitions.rebind(*candidate, face, rebound)) {
            allCompatible = false;
            break;
          }
        }
        if (allCompatible) {
          compatibleFaces.push_back(face);
        }
      }
      if (compatibleFaces.empty()) {
        return selected;
      }
      const auto faceKey = [&](const int face) {
        std::array<int, 3> vertices{{(*sourceFaces)(face, 0),
                                     (*sourceFaces)(face, 1),
                                     (*sourceFaces)(face, 2)}};
        std::sort(vertices.begin(), vertices.end());
        return std::make_pair(vertices, face);
      };
      const int selectedFace = *std::min_element(
          compatibleFaces.begin(), compatibleFaces.end(),
          [&](const int lhs, const int rhs) {
            return faceKey(lhs) < faceKey(rhs);
          });
      SurfacePoint canonical;
      if (sourceTransitions.rebind(selected, selectedFace, canonical)) {
        return canonical;
      }
      return selected;
    }

    SurfacePointSourceSupport commonSupport;
    std::vector<authority::SourceFaceId> commonFaces;
    bool initialized = false;
    for (const auto &[patchIndex, localRow] :
         pending.provenanceCandidates) {
      if (patchIndex < 0 ||
          patchIndex >= static_cast<int>(patches.size()) || localRow < 0 ||
          localRow >= static_cast<int>(
                          patches[static_cast<std::size_t>(patchIndex)]
                              .vertexProvenance.size())) {
        return selected;
      }
      const SurfacePoint &candidate =
          patches[static_cast<std::size_t>(patchIndex)]
              .vertexProvenance[static_cast<std::size_t>(localRow)];
      const SurfacePointSourceSupport support =
          sourceSupport.resolve(candidate);
      if (!support.valid()) {
        return selected;
      }
      if (!initialized) {
        commonSupport = support;
        commonFaces = support.incidentFaces;
        initialized = true;
      } else {
        if (support.identity != commonSupport.identity) {
          return selected;
        }
        std::vector<authority::SourceFaceId> intersection;
        std::set_intersection(commonFaces.begin(), commonFaces.end(),
                              support.incidentFaces.begin(),
                              support.incidentFaces.end(),
                              std::back_inserter(intersection));
        commonFaces = std::move(intersection);
      }
    }
    if (!initialized || commonFaces.empty()) {
      return selected;
    }
    const authority::SourceFaceId selectedFaceId =
        *std::min_element(commonFaces.begin(), commonFaces.end());
    const int selectedFace = static_cast<int>(selectedFaceId.index());
    if (selectedFace >= sourceFaces->rows()) {
      return selected;
    }

    Eigen::Vector3d rebound = Eigen::Vector3d::Zero();
    if (const auto *vertexSupport =
            std::get_if<authority::SourceVertexSupport>(
                &commonSupport.identity.value())) {
      const int sourceVertex =
          static_cast<int>(vertexSupport->vertex.index());
      for (int corner = 0; corner < 3; ++corner) {
        if ((*sourceFaces)(selectedFace, corner) == sourceVertex) {
          rebound(corner) = 1.0;
        }
      }
    } else if (const auto *edgeSupport =
                   std::get_if<authority::SourceEdgeSupport>(
                       &commonSupport.identity.value())) {
      const int sourceEdgeFirst =
          static_cast<int>(edgeSupport->edge.first().index());
      const int sourceEdgeSecond =
          static_cast<int>(edgeSupport->edge.second().index());
      double firstWeight = 0.0;
      double secondWeight = 0.0;
      for (int corner = 0; corner < 3; ++corner) {
        const int sourceVertex = (*sourceFaces)(selected.face, corner);
        if (sourceVertex == sourceEdgeFirst) {
          firstWeight += selected.barycentric(corner);
        } else if (sourceVertex == sourceEdgeSecond) {
          secondWeight += selected.barycentric(corner);
        }
      }
      const double sum = firstWeight + secondWeight;
      if (!(sum > 0.0)) {
        return selected;
      }
      firstWeight /= sum;
      secondWeight /= sum;
      for (int corner = 0; corner < 3; ++corner) {
        const int sourceVertex = (*sourceFaces)(selectedFace, corner);
        if (sourceVertex == sourceEdgeFirst) {
          rebound(corner) = firstWeight;
        } else if (sourceVertex == sourceEdgeSecond) {
          rebound(corner) = secondWeight;
        }
      }
    } else {
      if (selectedFace != selected.face) {
        return selected;
      }
      rebound = selected.barycentric;
    }
    if (std::abs(rebound.sum() - 1.0) > 1.0e-8) {
      return selected;
    }
    selected.face = selectedFace;
    selected.barycentric = rebound;
    selected.component = static_cast<int>(
        sourceAuthority->component_for_row(selectedFaceId).index());
    selected.sheet = static_cast<int>(
        sourceAuthority->sheet_for_row(selectedFaceId).index());
    return selected;
  };
  for (int row = 0; row < static_cast<int>(pendingVertices.size()); ++row) {
    const PendingOutputVertex &pending =
        pendingVertices[static_cast<std::size_t>(row)];
    result.mesh.vertexPositions.row(row) = pending.position;
    const PureQuadMesh &provenancePatch =
        patches[static_cast<std::size_t>(pending.provenancePatchIndex)];
    const SurfacePoint canonicalProvenance =
        canonicalSharedProvenance(pending);
    result.mesh.vertexProvenance.push_back(canonicalProvenance);

    const PureQuadMesh &lineagePatch =
        patches[static_cast<std::size_t>(pending.lineagePatchIndex)];
    PureQuadVertexLineage lineage =
        lineagePatch.vertexLineage[static_cast<std::size_t>(
            pending.lineageLocalRow)];
    const SurfacePoint &lineageProvenance =
        lineagePatch.vertexProvenance[static_cast<std::size_t>(
            pending.lineageLocalRow)];
    lineage.stitchIdentity =
        resolved_stitch_identity(lineagePatch, pending.lineageLocalRow);
    lineage.authoritativeIdentity =
        resolved_authoritative_identity(lineagePatch,
                                        pending.lineageLocalRow);
    lineage.outputVertex = row;
    lineage.sourcePatch = lineagePatch.sourcePatch;
    lineage.localVertex = lineagePatch.vertices[static_cast<std::size_t>(
        pending.lineageLocalRow)];
    if (lineage.kind == PureQuadVertexLineageKind::SourceTriangle) {
      lineage.sourcePoint = canonicalProvenance;
    }
    result.mesh.vertexLineage.push_back(std::move(lineage));
  }

  result.mesh.quads.reserve(uniqueFaceOwners.size());
  result.mesh.quadLineage.reserve(uniqueFaceOwners.size());
  for (const CompletedFaceOwnershipRecord &pending : uniqueFaceOwners) {
    const int outputQuad = static_cast<int>(result.mesh.quads.size());
    result.mesh.quads.push_back(
        {pending.globalVertices[0], pending.globalVertices[1],
         pending.globalVertices[2], pending.globalVertices[3]});
    PureQuadFaceLineage lineage =
        patches[static_cast<std::size_t>(pending.patchIndex)]
            .quadLineage[static_cast<std::size_t>(pending.localQuad)];
    lineage.outputQuad = outputQuad;
    result.mesh.quadLineage.push_back(std::move(lineage));
  }

  const auto incidence = pure_quad_detail::edge_incidence(result.mesh.quads);
  for (const auto &[edge, count] : incidence) {
    if (count != 1 && count != 2) {
      result.failure = "NonManifoldStitchedEdge";
      return result;
    }
  }
  result.eulerCharacteristic =
      static_cast<int>(result.mesh.vertices.size()) -
      static_cast<int>(incidence.size()) +
      static_cast<int>(result.mesh.quads.size());

  std::map<std::pair<int, int>, std::vector<int>> edgeFaces;
  for (int face = 0; face < static_cast<int>(result.mesh.quads.size()); ++face) {
    const auto &quad = result.mesh.quads[static_cast<std::size_t>(face)];
    for (int corner = 0; corner < 4; ++corner) {
      edgeFaces[pure_quad_detail::canonical_edge(
                    quad[static_cast<std::size_t>(corner)],
                    quad[static_cast<std::size_t>((corner + 1) % 4)])]
          .push_back(face);
    }
  }
  std::vector<std::vector<int>> faceAdjacency(result.mesh.quads.size());
  for (const auto &[edge, faces] : edgeFaces) {
    (void)edge;
    if (faces.size() == 2) {
      faceAdjacency[static_cast<std::size_t>(faces[0])].push_back(faces[1]);
      faceAdjacency[static_cast<std::size_t>(faces[1])].push_back(faces[0]);
    }
  }

  std::vector<std::vector<int>> vertexFaces(result.mesh.vertices.size());
  for (int face = 0; face < static_cast<int>(result.mesh.quads.size()); ++face) {
    for (const int vertex : result.mesh.quads[static_cast<std::size_t>(face)]) {
      vertexFaces[static_cast<std::size_t>(vertex)].push_back(face);
    }
  }
  for (int vertex = 0; vertex < static_cast<int>(vertexFaces.size()); ++vertex) {
    const auto &incident = vertexFaces[static_cast<std::size_t>(vertex)];
    if (incident.empty()) {
      result.failure = "UnusedStitchedVertex";
      return result;
    }
    std::set<int> incidentSet(incident.begin(), incident.end());
    std::set<int> reached;
    std::vector<int> stack{incident.front()};
    reached.insert(incident.front());
    while (!stack.empty()) {
      const int face = stack.back();
      stack.pop_back();
      const auto &quad = result.mesh.quads[static_cast<std::size_t>(face)];
      for (int corner = 0; corner < 4; ++corner) {
        if (quad[static_cast<std::size_t>(corner)] != vertex) {
          continue;
        }
        const int previous = quad[static_cast<std::size_t>((corner + 3) % 4)];
        const int next = quad[static_cast<std::size_t>((corner + 1) % 4)];
        for (const int adjacentVertex : {previous, next}) {
          const auto found = edgeFaces.find(
              pure_quad_detail::canonical_edge(vertex, adjacentVertex));
          if (found == edgeFaces.end()) {
            continue;
          }
          for (const int adjacentFace : found->second) {
            if (incidentSet.count(adjacentFace) != 0 &&
                reached.insert(adjacentFace).second) {
              stack.push_back(adjacentFace);
            }
          }
        }
      }
    }
    if (reached.size() != incidentSet.size()) {
      result.failure = "NonManifoldStitchedVertex";
      return result;
    }
  }

  std::vector<unsigned char> visited(result.mesh.quads.size(), 0);
  for (int start = 0; start < static_cast<int>(result.mesh.quads.size()); ++start) {
    if (visited[static_cast<std::size_t>(start)] != 0) {
      continue;
    }
    ++result.connectedComponents;
    std::vector<int> stack{start};
    visited[static_cast<std::size_t>(start)] = 1;
    while (!stack.empty()) {
      const int face = stack.back();
      stack.pop_back();
      for (const int next : faceAdjacency[static_cast<std::size_t>(face)]) {
        if (visited[static_cast<std::size_t>(next)] == 0) {
          visited[static_cast<std::size_t>(next)] = 1;
          stack.push_back(next);
        }
      }
    }
  }

  std::map<int, std::vector<int>> boundaryAdjacency;
  std::set<std::pair<int, int>> unvisitedBoundary;
  for (const auto &[edge, count] : incidence) {
    if (count == 1) {
      boundaryAdjacency[edge.first].push_back(edge.second);
      boundaryAdjacency[edge.second].push_back(edge.first);
      unvisitedBoundary.insert(edge);
    }
  }
  for (const auto &[vertex, adjacent] : boundaryAdjacency) {
    (void)vertex;
    if (adjacent.size() != 2) {
      result.failure = "NonManifoldBoundaryVertex";
      return result;
    }
  }
  while (!unvisitedBoundary.empty()) {
    const auto firstEdge = *unvisitedBoundary.begin();
    std::vector<int> loop;
    int previous = firstEdge.first;
    int current = firstEdge.second;
    loop.push_back(previous);
    unvisitedBoundary.erase(firstEdge);
    while (current != loop.front()) {
      loop.push_back(current);
      const auto &adjacent = boundaryAdjacency[current];
      const int next = adjacent[0] == previous ? adjacent[1] : adjacent[0];
      const auto edge = pure_quad_detail::canonical_edge(current, next);
      if (unvisitedBoundary.erase(edge) == 0) {
        result.failure = "BrokenBoundaryLoop";
        return result;
      }
      previous = current;
      current = next;
      if (loop.size() > boundaryAdjacency.size()) {
        result.failure = "BrokenBoundaryLoop";
        return result;
      }
    }
    result.mesh.boundaryLoops.push_back(std::move(loop));
  }
  result.boundaryLoopCount =
      static_cast<int>(result.mesh.boundaryLoops.size());
  if (!result.mesh.boundaryLoops.empty()) {
    result.mesh.boundaryVertices = result.mesh.boundaryLoops.front();
  }
  result.success = true;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

EndpointResolutionResult resolve_completion_endpoints(
    std::vector<CompletionEndpoint> endpoints) {
  std::sort(endpoints.begin(), endpoints.end(), [](const auto &a, const auto &b) {
    const double ca =
        std::min({a.compatibleCurveAvailable ? a.extendCost
                                             : std::numeric_limits<double>::infinity(),
                  a.removalKeepsPatchesFeasible ? a.removeCost
                                                : std::numeric_limits<double>::infinity(),
                  a.transitionTemplateAvailable
                      ? a.transitionCost
                      : std::numeric_limits<double>::infinity()});
    const double cb =
        std::min({b.compatibleCurveAvailable ? b.extendCost
                                             : std::numeric_limits<double>::infinity(),
                  b.removalKeepsPatchesFeasible ? b.removeCost
                                                : std::numeric_limits<double>::infinity(),
                  b.transitionTemplateAvailable
                      ? b.transitionCost
                      : std::numeric_limits<double>::infinity()});
    if (std::abs(ca - cb) > 1.0e-14) {
      return ca < cb;
    }
    return a.id < b.id;
  });
  EndpointResolutionResult result;
  for (const CompletionEndpoint &endpoint : endpoints) {
    EndpointResolutionRecord record;
    record.endpointId = endpoint.id;
    if (endpoint.compatibleCurveAvailable &&
        endpoint.extendCost <= endpoint.removeCost &&
        endpoint.extendCost <= endpoint.transitionCost) {
      record.action = EndpointResolutionAction::Extend;
      record.cost = endpoint.extendCost;
      result.mutatedAdjacency.push_back({endpoint.id, endpoint.targetCurve});
      ++result.arrangementRebuilds;
    } else if (endpoint.removalKeepsPatchesFeasible &&
               endpoint.removeCost <= endpoint.transitionCost) {
      record.action = EndpointResolutionAction::RemoveTrace;
      record.cost = endpoint.removeCost;
      result.mutatedAdjacency.push_back({endpoint.id, endpoint.incidentTrace});
      ++result.arrangementRebuilds;
    } else if (endpoint.transitionTemplateAvailable) {
      record.action = EndpointResolutionAction::InsertTransition;
      record.cost = endpoint.transitionCost;
      result.mutatedAdjacency.push_back({endpoint.id, -2});
      ++result.arrangementRebuilds;
    } else {
      record.action = EndpointResolutionAction::Unresolved;
      ++result.hangingNodes;
      ++result.endpointsEmbeddedInEdges;
    }
    result.records.push_back(record);
  }
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

std::vector<TopologyRewriteTemplate> default_topology_rewrite_catalog() {
  return {
      {0, TopologyTemplateKind::PolePairSlide, {3, 5, 4}, {2, 2}, {}, {3, 5},
       {4, 3, 5}, false, -1.0},
      {1, TopologyTemplateKind::PolePairCancellation, {3, 5}, {2, 2}, {}, {3, 5},
       {4, 4}, true, -2.0},
      {2, TopologyTemplateKind::LoopStripReduction, {4, 4, 4, 4}, {2, 2}, {}, {},
       {4, 4}, false, -1.0},
      {3, TopologyTemplateKind::LoopRedirection, {4, 4, 5}, {1, 2}, {7}, {},
       {4, 5, 4}, false, -0.5},
      {4, TopologyTemplateKind::Radial16To8, {16}, {16}, {}, {}, {8}, false,
       -1.0},
      {5, TopologyTemplateKind::Radial8To16, {8}, {8}, {}, {}, {16}, false,
       -0.25},
      {6, TopologyTemplateKind::CornerFeatureTermination, {4, 4}, {1, 1}, {9},
       {}, {3, 5}, false, -0.75},
  };
}

} // namespace directional::geometry

namespace directional::geometry {

TopologyRewriteResult apply_topology_rewrite_catalog(
    const PureQuadMesh &input,
    const std::vector<TopologyRewriteCandidate> &candidates,
    const std::vector<TopologyRewriteTemplate> &catalog) {
  TopologyRewriteResult result;
  result.mesh = input;
  std::vector<TopologyRewriteCandidate> sorted = candidates;
  std::sort(sorted.begin(), sorted.end(),
            [](const auto &a, const auto &b) { return a.id < b.id; });
  for (const TopologyRewriteCandidate &candidate : sorted) {
    TopologyRewriteRecord record;
    record.candidateId = candidate.id;
    bool committed = false;
    for (const TopologyRewriteTemplate &templ : catalog) {
      const bool featureOk =
          templ.permittedFeatureLabels.empty() ||
          templ.permittedFeatureLabels.count(candidate.featureLabel) != 0;
      const bool singularityOk =
          templ.permittedSingularityLabels.empty() ||
          templ.permittedSingularityLabels.count(candidate.singularityLabel) != 0;
      if (!pure_quad_detail::vectors_equal(candidate.adjacency,
                                           templ.inputAdjacency) ||
          !pure_quad_detail::vectors_equal(candidate.boundarySignature,
                                           templ.boundarySignature) ||
          !featureOk || !singularityOk ||
          (templ.requiresSingularityBudget &&
           !candidate.singularityBudgetAvailable) ||
          templ.objectiveDelta >= 0.0 || candidate.mutation.id < 0 ||
          candidate.mutation.kind != templ.kind) {
        continue;
      }
      const GuardedTopologyMutationResult applied =
          apply_guarded_topology_mutations(result.mesh, {candidate.mutation});
      if (applied.committed != 1) {
        if (!applied.records.empty()) {
          record.reason = applied.records.front().reason;
        }
        continue;
      }
      result.mesh = applied.mesh;
      record.templateId = templ.id;
      record.committed = true;
      record.outputAdjacency = templ.outputAdjacency;
      record.reason = PureQuadPatchRejectReason::None;
      ++result.committed;
      committed = true;
      break;
    }
    if (!committed) {
      ++result.rejected;
    }
    result.records.push_back(std::move(record));
  }
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

GuardedTopologyMutationResult apply_guarded_topology_mutations(
    const PureQuadMesh &input,
    std::vector<GuardedTopologyMutation> mutations) {
  GuardedTopologyMutationResult result;
  result.mesh = input;
  std::sort(mutations.begin(), mutations.end(),
            [](const auto &a, const auto &b) { return a.id < b.id; });

  for (const GuardedTopologyMutation &mutation : mutations) {
    GuardedTopologyMutationRecord record;
    record.mutationId = mutation.id;
    record.kind = mutation.kind;
    PureQuadMesh trial = result.mesh;
    const auto beforeValence =
        pure_quad_detail::vertex_valences(trial.quads);
    const auto beforeBoundary =
        pure_quad_detail::boundary_edges(trial.quads);
    const int beforeEuler =
        pure_quad_detail::mesh_euler_characteristic(trial.quads);

    bool preconditions = !mutation.removeQuadIndices.empty();
    std::set<int> uniqueIndices;
    for (const int index : mutation.removeQuadIndices) {
      preconditions = preconditions && index >= 0 &&
                      index < static_cast<int>(trial.quads.size()) &&
                      uniqueIndices.insert(index).second;
    }
    for (const auto &[vertex, expected] : mutation.expectedValenceBefore) {
      const auto found = beforeValence.find(vertex);
      preconditions = preconditions && found != beforeValence.end() &&
                      found->second == expected;
    }
    if (!preconditions) {
      record.reason = PureQuadPatchRejectReason::RewritePreconditionFailed;
      result.records.push_back(record);
      ++result.rejected;
      continue;
    }

    std::vector<std::vector<int>> retained;
    retained.reserve(trial.quads.size() - mutation.removeQuadIndices.size() +
                     mutation.replacementQuads.size());
    for (int i = 0; i < static_cast<int>(trial.quads.size()); ++i) {
      if (uniqueIndices.count(i) == 0) retained.push_back(trial.quads[i]);
    }
    retained.insert(retained.end(), mutation.replacementQuads.begin(),
                    mutation.replacementQuads.end());
    trial.quads = std::move(retained);

    if (!pure_quad_detail::quads_are_locally_valid(trial.quads)) {
      record.reason = PureQuadPatchRejectReason::TopologyValidationFailed;
      result.records.push_back(record);
      ++result.rejected;
      continue;
    }
    const auto afterIncidence = pure_quad_detail::edge_incidence(trial.quads);
    bool featuresPreserved = true;
    for (const auto &[a, b] : mutation.protectedEdges) {
      const auto edge = pure_quad_detail::canonical_edge(a, b);
      featuresPreserved = featuresPreserved &&
                          afterIncidence.find(edge) != afterIncidence.end();
    }
    if (!featuresPreserved) {
      record.reason = PureQuadPatchRejectReason::RewriteFeatureViolation;
      result.records.push_back(record);
      ++result.rejected;
      continue;
    }
    if (mutation.preserveBoundary &&
        beforeBoundary != pure_quad_detail::boundary_edges(trial.quads)) {
      record.reason = PureQuadPatchRejectReason::RewriteFeatureViolation;
      result.records.push_back(record);
      ++result.rejected;
      continue;
    }
    if (mutation.preserveEulerCharacteristic &&
        beforeEuler != pure_quad_detail::mesh_euler_characteristic(trial.quads)) {
      record.reason = PureQuadPatchRejectReason::TopologyValidationFailed;
      result.records.push_back(record);
      ++result.rejected;
      continue;
    }
    const auto afterValence = pure_quad_detail::vertex_valences(trial.quads);
    bool valenceMatches = true;
    for (const auto &[vertex, expected] : mutation.expectedValenceAfter) {
      const auto found = afterValence.find(vertex);
      valenceMatches = valenceMatches && found != afterValence.end() &&
                       found->second == expected;
      record.affectedVertices.push_back(vertex);
    }
    if (!valenceMatches) {
      record.reason = PureQuadPatchRejectReason::RewriteValenceMismatch;
      result.records.push_back(record);
      ++result.rejected;
      continue;
    }

    result.mesh = std::move(trial);
    record.committed = true;
    record.reason = PureQuadPatchRejectReason::None;
    result.records.push_back(std::move(record));
    ++result.committed;
  }
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

bool closed_surface_singularity_budget_exact(
    const int eulerCharacteristic, const std::vector<int> &singularityNumerators) {
  const int sum = std::accumulate(singularityNumerators.begin(),
                                  singularityNumerators.end(), 0);
  return sum == 4 * eulerCharacteristic;
}

} // namespace directional::geometry

namespace directional::geometry {

PureQuadValidationReport validate_pure_quad_completion(
    const PureQuadMesh &mesh, const std::vector<int> &extraordinaryValences,
    const std::set<int> &featureVertices,
    const bool singularityBudgetExact) {
  PureQuadValidationReport report;
  report.pureQuads = std::all_of(mesh.quads.begin(), mesh.quads.end(),
                                 [](const auto &q) { return q.size() == 4; });
  report.closedSurfaceSingularityBudgetExact = singularityBudgetExact;
  if (mesh.vertexPositions.rows() ==
      static_cast<Eigen::Index>(mesh.vertices.size())) {
    Eigen::MatrixXi faces(static_cast<int>(mesh.quads.size()), 4);
    bool canValidateGeometry = true;
    for (int f = 0; f < static_cast<int>(mesh.quads.size()); ++f) {
      if (mesh.quads[static_cast<std::size_t>(f)].size() != 4) {
        canValidateGeometry = false;
        break;
      }
      for (int c = 0; c < 4; ++c) {
        const auto found = std::find(mesh.vertices.begin(), mesh.vertices.end(),
                                     mesh.quads[static_cast<std::size_t>(f)]
                                               [static_cast<std::size_t>(c)]);
        if (found == mesh.vertices.end()) {
          canValidateGeometry = false;
          break;
        }
        faces(f, c) = static_cast<int>(std::distance(mesh.vertices.begin(), found));
      }
    }
    if (canValidateGeometry) {
      const auto validation =
          validation::MeshValidator::validate_surface_mesh(mesh.vertexPositions,
                                                           faces);
      for (const auto &issue : validation.issues) {
        if (issue.code ==
            validation::MeshValidationFailureCode::GeometricVertexOnUnsplitEdge) {
          ++report.tJunctions;
        } else if (issue.code ==
                       validation::MeshValidationFailureCode::
                           ThreeSidedInteriorEdge ||
                   issue.code ==
                       validation::MeshValidationFailureCode::
                           OneSidedInteriorEdge) {
          ++report.nonManifoldElements;
        } else if (issue.code ==
                   validation::MeshValidationFailureCode::ZeroAreaFace) {
          ++report.degenerateElements;
        } else if (issue.code ==
                   validation::MeshValidationFailureCode::FlippedFace) {
          ++report.invertedElements;
        } else if (issue.code ==
                   validation::MeshValidationFailureCode::SelfIntersectingFace) {
          ++report.selfIntersectingElements;
        }
      }
    }
  }
  int extraordinary = 0;
  int valence35 = 0;
  for (int i = 0; i < static_cast<int>(extraordinaryValences.size()); ++i) {
    const int valence = extraordinaryValences[static_cast<std::size_t>(i)];
    if (valence == 4 || featureVertices.count(i) != 0) {
      continue;
    }
    ++extraordinary;
    if (valence == 3 || valence == 5) {
      ++valence35;
    } else {
      report.reportedHighValenceVertices.push_back(i);
    }
  }
  report.extraordinaryValence35Ratio =
      extraordinary == 0 ? 1.0
                         : static_cast<double>(valence35) /
                               static_cast<double>(extraordinary);
  return report;
}

} // namespace directional::geometry

namespace directional::geometry {

int source_vertex_from_point(const SurfacePoint &p, const Eigen::MatrixXi &F, double tol) { if(!p.valid()||p.face<0||p.face>=F.rows()) return -1; int c=0; p.barycentric.maxCoeff(&c); return p.barycentric(c)>=1.0-tol ? F(p.face,c) : -1; }

} // namespace directional::geometry

namespace directional::geometry {

bool output_is_only_paired_source_triangle_boundaries(const PureQuadMesh &mesh,const Eigen::MatrixXi &F) {
  if(mesh.quads.empty()||F.cols()!=3||mesh.vertexProvenance.size()!=mesh.vertices.size()) return false; std::map<int,int> row; for(int i=0;i<(int)mesh.vertices.size();++i) row[mesh.vertices[i]]=i; std::set<std::set<int>> pairs;
  for(int a=0;a<F.rows();++a){ std::set<int> A={F(a,0),F(a,1),F(a,2)}; for(int b=a+1;b<F.rows();++b){ std::set<int>B={F(b,0),F(b,1),F(b,2)}; std::vector<int>I; std::set_intersection(A.begin(),A.end(),B.begin(),B.end(),std::back_inserter(I)); std::set<int>U=A; U.insert(B.begin(),B.end()); if(I.size()==2&&U.size()==4)pairs.insert(U); }}
  for(const auto&q:mesh.quads){ std::set<int> sv; for(int v:q){auto it=row.find(v); if(it==row.end())return false; int x=source_vertex_from_point(mesh.vertexProvenance[it->second],F); if(x<0)return false; sv.insert(x);} if(sv.size()!=4||!pairs.count(sv))return false;} return true; }

} // namespace directional::geometry

namespace directional::geometry {

PureQuadOutputLineageValidation validate_pure_quad_output_lineage(const PureQuadMesh &mesh,const Eigen::MatrixXi &F,bool rejectPaired){ PureQuadOutputLineageValidation r; r.allVerticesMapped=mesh.vertexLineage.size()==mesh.vertices.size()&&std::all_of(mesh.vertexLineage.begin(),mesh.vertexLineage.end(),[](const auto&x){return x.valid();}); r.allQuadsMapped=mesh.quadLineage.size()==mesh.quads.size()&&std::all_of(mesh.quadLineage.begin(),mesh.quadLineage.end(),[&](const auto&x){return x.valid()&&x.sourcePatch==mesh.sourcePatch;}); r.solelyPairedSourceTriangleBoundaries=output_is_only_paired_source_triangle_boundaries(mesh,F); if(!r.allVerticesMapped)r.failure="MissingOutputVertexLineage"; else if(!r.allQuadsMapped)r.failure="MissingOutputQuadLineage"; else if(rejectPaired&&r.solelyPairedSourceTriangleBoundaries)r.failure="PairedSourceTriangleBoundaryOutput"; else r.valid=true; return r;}

} // namespace directional::geometry
