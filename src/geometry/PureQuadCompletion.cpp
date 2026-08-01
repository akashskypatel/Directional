#include <directional/geometry/PureQuadCompletion.h>

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
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets) {
  if (projection != nullptr) {
    SurfaceProjectionOptions options;
    options.allowedFaces = allowedFaces;
    options.faceComponents = faceComponents;
    options.faceSheets = faceSheets;
    SurfacePoint projected = projection->project(target, options);
    if (projected.valid()) {
      return projected;
    }
  }

  // Standalone completion tests may not provide a source mesh. A fallback is
  // truthful only when all anchors refer to the same source triangle and
  // sheet. Real multi-triangle patches must provide a projection context.
  const SurfacePoint averaged = average_source_point(anchors);
  if (!averaged.valid()) {
    return {};
  }
  for (const SurfacePoint &anchor : anchors) {
    if (!anchor.valid() || anchor.face != averaged.face ||
        anchor.component != averaged.component || anchor.sheet != averaged.sheet) {
      return {};
    }
  }
  return averaged;
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
  for (int i = 0; i < static_cast<int>(mesh.boundaryVertices.size()); ++i) {
    const SurfacePoint point = boundary_source_point(patch, i);
    mesh.vertexProvenance.push_back(point);
    PureQuadVertexLineage lineage; lineage.outputVertex = mesh.boundaryVertices[static_cast<std::size_t>(i)];
    const int rail = i < static_cast<int>(patch.boundaryRailIds.size()) ? patch.boundaryRailIds[static_cast<std::size_t>(i)] : -1;
    const int curve = i < static_cast<int>(patch.boundaryCurveIds.size()) ? patch.boundaryCurveIds[static_cast<std::size_t>(i)] : -1;
    if (rail >= 0 || curve >= 0) { lineage.kind = PureQuadVertexLineageKind::OrderedFeatureInterval; lineage.featureInterval.railId=rail; lineage.featureInterval.curveId=curve; lineage.featureInterval.start=point; lineage.featureInterval.end=boundary_source_point(patch,(i+1)%static_cast<int>(mesh.boundaryVertices.size())); }
    else { lineage.sourcePoint = point; }
    mesh.vertexLineage.push_back(lineage);
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
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets) {
  const SurfacePoint point = project_generated_point(
      targetPosition, anchors, projection, allowedFaces, faceComponents,
      faceSheets);
  if (!point.valid()) {
    return std::numeric_limits<int>::max();
  }
  const int vertex = next_generated_vertex(nextInterior);
  mesh.vertices.push_back(vertex);
  mesh.vertexProvenance.push_back(point);
  PureQuadVertexLineage lineage; lineage.outputVertex=vertex; lineage.sourcePoint=point; mesh.vertexLineage.push_back(lineage);
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
  if (sides < 3 || sides > 6) {
    result.reason = PureQuadPatchRejectReason::SideCountUnsupported;
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
  if (!pure_quad_detail::side_inequalities_hold(patch.sideEdgeCounts)) {
    result.reason = PureQuadPatchRejectReason::SideInequality;
    return result;
  }
  if (!pure_quad_detail::hex_parity_holds(patch.sideEdgeCounts)) {
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
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets) {
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
          allowedFaces, faceComponents, faceSheets);
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
                                           PureQuadMesh &mesh) {
  if (patch.boundaryVertices.size() != 6) return false;
  const auto &v = patch.boundaryVertices;
  mesh.quads.push_back({v[0], v[1], v[2], v[3]});
  mesh.quads.push_back({v[0], v[3], v[4], v[5]});
  mesh.backend = PureQuadCompletionBackend::TransitionTemplate;
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

void append_boundary_fan(const std::vector<int> &boundary,
                                const int anchor, PureQuadMesh &mesh) {
  const int n = static_cast<int>(boundary.size());
  const auto at = [&](int i) { return boundary[(anchor + i) % n]; };
  for (int i = 1; i + 2 < n; i += 2) {
    mesh.quads.push_back({at(0), at(i), at(i + 1), at(i + 2)});
  }
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool complete_singularity_pole(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets) {
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
      allowedFaces, faceComponents, faceSheets);
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

bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh) {
  if (patch.boundaryVertices.size() < 4 ||
      patch.boundaryVertices.size() % 2 != 0) return false;
  append_boundary_fan(patch.boundaryVertices, 0, mesh);
  mesh.backend = PureQuadCompletionBackend::Pattern;
  return true;
}

} // namespace directional::geometry::pure_quad_detail

namespace directional::geometry::pure_quad_detail {

bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
                             int &explored) {
  const int n = static_cast<int>(patch.boundaryVertices.size());
  for (int anchor = 0; anchor < n; ++anchor) {
    PureQuadMesh trial = mesh;
    append_boundary_fan(patch.boundaryVertices, anchor, trial);
    ++explored;
    if (pure_quad_topology_is_disk(trial)) {
      trial.backend = PureQuadCompletionBackend::BoundedCombinatorial;
      mesh = std::move(trial);
      return true;
    }
  }
  return false;
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
  pure_quad_detail::initialize_boundary_embedding(patch, mesh);
  if ((options.sourceVertices == nullptr) != (options.sourceFaces == nullptr)) {
    result.failureReason = PureQuadPatchRejectReason::MissingBoundaryData;
    return result;
  }
  std::unique_ptr<SurfaceProjectionBvh> projection;
  std::vector<unsigned char> allowedFaces;
  if (options.sourceVertices != nullptr && options.sourceFaces != nullptr) {
    projection = std::make_unique<SurfaceProjectionBvh>(
        *options.sourceVertices, *options.sourceFaces);
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
        options.sourceFaceComponents, options.sourceFaceSheets);
    if (!completed) {
      result.failureReason =
          PureQuadPatchRejectReason::UnsupportedSingularityCompletion;
      return result;
    }
  }
  if (!completed && !boundedFallbackAdmissible) {
    completed = pure_quad_detail::complete_rectangular_grid(
        patch, mesh, projection.get(), allowedFacePtr,
        options.sourceFaceComponents, options.sourceFaceSheets);
  }
  if (!completed && !boundedFallbackAdmissible && boundaryCount == 6) {
    completed = pure_quad_detail::complete_six_vertex_transition(patch, mesh);
  }
  if (!completed && !boundedFallbackAdmissible && patch.simple) {
    completed = pure_quad_detail::complete_pattern(patch, mesh);
  }
  if (!completed && options.allowBoundedCombinatorialFallback) {
    completed = pure_quad_detail::complete_bounded(
        patch, mesh, result.exploredPatterns);
  }
  if (!completed) {
    result.failureReason = PureQuadPatchRejectReason::SearchLimitExceeded;
    return result;
  }
  if (!pure_quad_detail::fill_positions(mesh)) {
    result.failureReason = PureQuadPatchRejectReason::MissingBoundaryData;
    return result;
  }
  for (int q=0; q<static_cast<int>(mesh.quads.size()); ++q) mesh.quadLineage.push_back({q, mesh.sourcePatch, mesh.backend, q});
  if (!pure_quad_topology_is_disk(mesh)) {
    result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
    return result;
  }
  result.mesh = std::move(mesh);
  result.success = true;
  return result;
}

} // namespace directional::geometry

namespace directional::geometry {

PureQuadAssemblyResult stitch_pure_quad_patches(
    const std::vector<PureQuadMesh> &patches,
    const double positionTolerance) {
  PureQuadAssemblyResult result;
  if (patches.empty()) {
    result.failure = "NoCompletedPatches";
    return result;
  }

  std::map<std::tuple<int, int, int>, int> vertexRows;
  std::vector<Eigen::Vector3d> positions;
  std::set<std::vector<int>> canonicalQuads;

  for (int patchIndex = 0; patchIndex < static_cast<int>(patches.size());
       ++patchIndex) {
    const PureQuadMesh &patch = patches[static_cast<std::size_t>(patchIndex)];
    if (patch.vertices.size() !=
            static_cast<std::size_t>(patch.vertexPositions.rows()) ||
        patch.vertices.size() != patch.vertexProvenance.size() ||
        patch.vertices.size() != patch.vertexLineage.size() ||
        patch.quads.size() != patch.quadLineage.size()) {
      result.failure = "IncompletePatchLineage";
      return result;
    }

    const std::set<int> boundary(patch.boundaryVertices.begin(),
                                 patch.boundaryVertices.end());
    std::map<int, int> localToGlobal;
    for (int localRow = 0; localRow < static_cast<int>(patch.vertices.size());
         ++localRow) {
      const int localVertex = patch.vertices[static_cast<std::size_t>(localRow)];
      const bool sharedBoundary = boundary.count(localVertex) != 0;
      const auto key = sharedBoundary
                           ? std::make_tuple(0, 0, localVertex)
                           : std::make_tuple(1, patchIndex, localVertex);
      const Eigen::Vector3d position =
          patch.vertexPositions.row(localRow).transpose();
      const auto existing = vertexRows.find(key);
      int globalRow = -1;
      if (existing == vertexRows.end()) {
        globalRow = static_cast<int>(positions.size());
        vertexRows.emplace(key, globalRow);
        positions.push_back(position);
        result.mesh.vertexProvenance.push_back(
            patch.vertexProvenance[static_cast<std::size_t>(localRow)]);
        PureQuadVertexLineage lineage =
            patch.vertexLineage[static_cast<std::size_t>(localRow)];
        lineage.outputVertex = globalRow;
        result.mesh.vertexLineage.push_back(std::move(lineage));
      } else {
        globalRow = existing->second;
        if ((positions[static_cast<std::size_t>(globalRow)] - position).norm() >
            positionTolerance) {
          result.failure = "InconsistentSharedBoundaryPosition";
          return result;
        }
        ++result.mergedBoundaryVertices;
        PureQuadVertexLineage &stored =
            result.mesh.vertexLineage[static_cast<std::size_t>(globalRow)];
        const PureQuadVertexLineage &incoming =
            patch.vertexLineage[static_cast<std::size_t>(localRow)];
        if (stored.kind == PureQuadVertexLineageKind::SourceTriangle &&
            incoming.kind == PureQuadVertexLineageKind::OrderedFeatureInterval) {
          stored = incoming;
          stored.outputVertex = globalRow;
        }
      }
      localToGlobal.emplace(localVertex, globalRow);
    }

    for (int localQuad = 0; localQuad < static_cast<int>(patch.quads.size());
         ++localQuad) {
      const std::vector<int> &quad =
          patch.quads[static_cast<std::size_t>(localQuad)];
      if (quad.size() != 4) {
        result.failure = "NonQuadPatchFace";
        return result;
      }
      std::vector<int> globalQuad(4, -1);
      for (int corner = 0; corner < 4; ++corner) {
        const auto mapped = localToGlobal.find(quad[static_cast<std::size_t>(corner)]);
        if (mapped == localToGlobal.end()) {
          result.failure = "UnknownPatchVertex";
          return result;
        }
        globalQuad[static_cast<std::size_t>(corner)] = mapped->second;
      }
      if (std::set<int>(globalQuad.begin(), globalQuad.end()).size() != 4) {
        result.failure = "DegenerateStitchedQuad";
        return result;
      }
      std::vector<int> canonical = globalQuad;
      std::sort(canonical.begin(), canonical.end());
      if (!canonicalQuads.insert(canonical).second) {
        result.failure = "DuplicateStitchedQuad";
        return result;
      }
      const int outputQuad = static_cast<int>(result.mesh.quads.size());
      result.mesh.quads.push_back(std::move(globalQuad));
      PureQuadFaceLineage lineage =
          patch.quadLineage[static_cast<std::size_t>(localQuad)];
      lineage.outputQuad = outputQuad;
      result.mesh.quadLineage.push_back(std::move(lineage));
    }
  }

  result.mesh.vertices.resize(positions.size());
  std::iota(result.mesh.vertices.begin(), result.mesh.vertices.end(), 0);
  result.mesh.vertexPositions.resize(static_cast<int>(positions.size()), 3);
  for (int row = 0; row < static_cast<int>(positions.size()); ++row) {
    result.mesh.vertexPositions.row(row) = positions[static_cast<std::size_t>(row)];
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
