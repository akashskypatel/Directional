// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_PURE_QUAD_COMPLETION_H
#define DIRECTIONAL_GEOMETRY_PURE_QUAD_COMPLETION_H

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/meshing/PatchRegion.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/validation/MeshValidator.h>

namespace directional::geometry {

enum class PureQuadPatchRejectReason : int {
  None = 0,
  NonDisk = 1,
  BoundaryLoopCount = 2,
  SideCountUnsupported = 3,
  InvalidTurn = 4,
  OddBoundary = 5,
  HardFeatureCrossing = 6,
  SideInequality = 7,
  HexParity = 8,
  SingularityMismatch = 9,
};

enum class PureQuadCompletionBackend : int {
  ClosedForm = 0,
  PatternFallback = 1,
};

enum class EndpointResolutionAction : int {
  Extend = 0,
  RemoveTrace = 1,
  InsertTransition = 2,
  Unresolved = 3,
};

enum class TopologyTemplateKind : int {
  PolePairSlide = 0,
  PolePairCancellation = 1,
  LoopStripReduction = 2,
  LoopRedirection = 3,
  Radial16To8 = 4,
  Radial8To16 = 5,
  CornerFeatureTermination = 6,
};

struct PureQuadPatch {
  std::vector<int> boundaryVertices;
  std::vector<SurfacePoint> boundaryProvenance;
  std::vector<int> boundaryRailIds;
  std::vector<int> boundaryCurveIds;
  std::vector<int> sideEdgeCounts;
  std::vector<int> turns;
  int boundaryLoopCount = 1;
  bool diskTopology = true;
  bool hardFeatureCrossing = false;
  int singularityCount = 0;
  int singularIndexNumerator = 0;
  bool unmatchedInteriorSingularity = false;
  bool simple = true;
};

struct PureQuadPatchAdmissibility {
  bool admissible = false;
  PureQuadPatchRejectReason reason = PureQuadPatchRejectReason::None;
  int expectedInteriorValence = 4;
};

struct PureQuadMesh {
  std::vector<int> vertices;
  Eigen::MatrixXd vertexPositions;
  std::vector<SurfacePoint> vertexProvenance;
  std::vector<std::vector<int>> quads;
  std::vector<int> boundaryVertices;
  PureQuadCompletionBackend backend = PureQuadCompletionBackend::ClosedForm;
  bool usesCenterFan = false;
};

struct PureQuadCompletionResult {
  bool success = false;
  PureQuadPatchAdmissibility admissibility;
  PureQuadMesh mesh;
};

struct CompletionEndpoint {
  int id = -1;
  int incidentTrace = -1;
  int targetCurve = -1;
  int family = 0;
  double extendCost = std::numeric_limits<double>::infinity();
  double removeCost = std::numeric_limits<double>::infinity();
  double transitionCost = std::numeric_limits<double>::infinity();
  bool compatibleCurveAvailable = false;
  bool removalKeepsPatchesFeasible = false;
  bool transitionTemplateAvailable = false;
};

struct EndpointResolutionRecord {
  int endpointId = -1;
  EndpointResolutionAction action = EndpointResolutionAction::Unresolved;
  double cost = std::numeric_limits<double>::infinity();
};

struct EndpointResolutionResult {
  std::vector<EndpointResolutionRecord> records;
  std::vector<std::pair<int, int>> mutatedAdjacency;
  int arrangementRebuilds = 0;
  int hangingNodes = 0;
  int endpointsEmbeddedInEdges = 0;
};

struct TopologyRewriteTemplate {
  int id = -1;
  TopologyTemplateKind kind = TopologyTemplateKind::PolePairSlide;
  std::vector<int> inputAdjacency;
  std::vector<int> boundarySignature;
  std::set<int> permittedFeatureLabels;
  std::set<int> permittedSingularityLabels;
  std::vector<int> outputAdjacency;
  bool requiresSingularityBudget = false;
  double objectiveDelta = -1.0;
};

struct TopologyRewriteCandidate {
  int id = -1;
  std::vector<int> adjacency;
  std::vector<int> boundarySignature;
  int featureLabel = 0;
  int singularityLabel = 0;
  bool singularityBudgetAvailable = true;
  bool postconditionsHold = true;
  bool strictValidatorAccepts = true;
};

struct TopologyRewriteRecord {
  int candidateId = -1;
  int templateId = -1;
  bool committed = false;
  std::vector<int> outputAdjacency;
};

struct TopologyRewriteResult {
  std::vector<TopologyRewriteRecord> records;
  int committed = 0;
  int rejected = 0;
};

struct PureQuadValidationReport {
  bool pureQuads = true;
  int tJunctions = 0;
  int hangingNodes = 0;
  int nonManifoldElements = 0;
  int degenerateElements = 0;
  int invertedElements = 0;
  int selfIntersectingElements = 0;
  bool topologyInvariant = true;
  bool featureBoundaryInvariant = true;
  bool closedSurfaceSingularityBudgetExact = true;
  double extraordinaryValence35Ratio = 1.0;
  std::vector<int> reportedHighValenceVertices;
};

namespace pure_quad_detail {

inline int boundary_edge_count(const PureQuadPatch &patch) {
  return std::accumulate(patch.sideEdgeCounts.begin(),
                         patch.sideEdgeCounts.end(), 0);
}

inline bool turns_are_valid(const PureQuadPatch &patch) {
  for (const int turn : patch.turns) {
    if (turn != 0 && std::abs(turn) != 1) {
      return false;
    }
  }
  return true;
}

inline bool side_inequalities_hold(const std::vector<int> &e) {
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

inline bool hex_parity_holds(const std::vector<int> &e) {
  if (e.size() != 6) {
    return true;
  }
  const int even = e[0] + e[2] + e[4];
  const int odd = e[1] + e[3] + e[5];
  return even == odd;
}

inline int expected_valence(const int singularIndexNumerator) {
  return 4 - singularIndexNumerator;
}

inline int next_generated_vertex(int &next) { return next--; }

inline SurfacePoint make_planar_source_point(const int face,
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

inline SurfacePoint boundary_source_point(const PureQuadPatch &patch,
                                          const int boundaryIndex) {
  if (boundaryIndex >= 0 &&
      boundaryIndex < static_cast<int>(patch.boundaryProvenance.size()) &&
      patch.boundaryProvenance[static_cast<std::size_t>(boundaryIndex)].valid()) {
    return patch.boundaryProvenance[static_cast<std::size_t>(boundaryIndex)];
  }
  const int count = std::max(1, static_cast<int>(patch.boundaryVertices.size()));
  const double t = static_cast<double>(boundaryIndex) / static_cast<double>(count);
  double x = 0.0;
  double y = 0.0;
  if (t < 0.25) {
    x = 4.0 * t;
  } else if (t < 0.5) {
    x = 1.0;
    y = 4.0 * (t - 0.25);
  } else if (t < 0.75) {
    x = 1.0 - 4.0 * (t - 0.5);
    y = 1.0;
  } else {
    y = 1.0 - 4.0 * (t - 0.75);
  }
  const Eigen::Vector3d position(x, y, 0.0);
  const Eigen::Vector3d barycentric(
      std::max(0.0, 1.0 - 0.5 * (x + y)), 0.5 * x, 0.5 * y);
  return make_planar_source_point(0, position, barycentric);
}

inline SurfacePoint average_source_point(const std::vector<SurfacePoint> &points) {
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
    return make_planar_source_point(0, {1.0 / 3.0, 1.0 / 3.0, 0.0},
                                    {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0});
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

inline void initialize_boundary_embedding(const PureQuadPatch &patch,
                                          PureQuadMesh &mesh) {
  mesh.boundaryVertices = patch.boundaryVertices;
  mesh.vertices = patch.boundaryVertices;
  mesh.vertexProvenance.clear();
  mesh.vertexProvenance.reserve(mesh.vertices.size());
  for (int i = 0; i < static_cast<int>(mesh.boundaryVertices.size()); ++i) {
    mesh.vertexProvenance.push_back(boundary_source_point(patch, i));
  }
}

inline int append_embedded_vertex(PureQuadMesh &mesh, int &nextInterior,
                                  const std::vector<SurfacePoint> &anchors) {
  const int vertex = next_generated_vertex(nextInterior);
  mesh.vertices.push_back(vertex);
  mesh.vertexProvenance.push_back(average_source_point(anchors));
  return vertex;
}

inline void fill_positions(PureQuadMesh &mesh) {
  mesh.vertexPositions.resize(static_cast<int>(mesh.vertices.size()), 3);
  for (int i = 0; i < static_cast<int>(mesh.vertices.size()); ++i) {
    if (i < static_cast<int>(mesh.vertexProvenance.size()) &&
        mesh.vertexProvenance[static_cast<std::size_t>(i)].valid()) {
      mesh.vertexPositions.row(i) =
          mesh.vertexProvenance[static_cast<std::size_t>(i)].position;
    } else {
      mesh.vertexPositions.row(i) << static_cast<double>(i), 0.0, 0.0;
    }
  }
}

inline bool vectors_equal(const std::vector<int> &a, const std::vector<int> &b) {
  return a == b;
}

} // namespace pure_quad_detail

inline PureQuadPatchAdmissibility
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
  result.admissible = true;
  result.reason = PureQuadPatchRejectReason::None;
  return result;
}

inline PureQuadCompletionResult complete_pure_quad_patch(
    const PureQuadPatch &patch) {
  PureQuadCompletionResult result;
  result.admissibility = check_pure_quad_patch_admissibility(patch);
  if (!result.admissibility.admissible) {
    return result;
  }
  PureQuadMesh mesh;
  pure_quad_detail::initialize_boundary_embedding(patch, mesh);
  int nextInterior = -1;
  const int sides = static_cast<int>(patch.sideEdgeCounts.size());
  if (sides == 4 && patch.simple) {
    const int width = patch.sideEdgeCounts[0];
    const int height = patch.sideEdgeCounts[1];
    std::vector<std::vector<int>> grid(
        static_cast<std::size_t>(height + 1),
        std::vector<int>(static_cast<std::size_t>(width + 1), -1));
    const int boundaryCount = static_cast<int>(patch.boundaryVertices.size());
    const auto boundary_at = [&](const int index) {
      return patch.boundaryVertices[static_cast<std::size_t>(
          (index % boundaryCount + boundaryCount) % boundaryCount)];
    };
    int index = 0;
    for (int x = 0; x <= width; ++x) {
      grid[0][static_cast<std::size_t>(x)] = boundary_at(index++);
    }
    for (int y = 1; y <= height; ++y) {
      grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(width)] =
          boundary_at(index++);
    }
    for (int x = width - 1; x >= 0; --x) {
      grid[static_cast<std::size_t>(height)][static_cast<std::size_t>(x)] =
          boundary_at(index++);
    }
    for (int y = height - 1; y >= 1; --y) {
      grid[static_cast<std::size_t>(y)][0] = boundary_at(index++);
    }
    for (int y = 1; y < height; ++y) {
      for (int x = 1; x < width; ++x) {
        const int boundaryCount = static_cast<int>(patch.boundaryVertices.size());
        const int a = (x + y) % std::max(1, boundaryCount);
        const int b = (a + boundaryCount / 2) % std::max(1, boundaryCount);
        const int v = pure_quad_detail::append_embedded_vertex(
            mesh, nextInterior,
            {pure_quad_detail::boundary_source_point(patch, a),
             pure_quad_detail::boundary_source_point(patch, b)});
        grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(x)] = v;
      }
    }
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        mesh.quads.push_back({
            grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(x)],
            grid[static_cast<std::size_t>(y)][static_cast<std::size_t>(x + 1)],
            grid[static_cast<std::size_t>(y + 1)][static_cast<std::size_t>(x + 1)],
            grid[static_cast<std::size_t>(y + 1)][static_cast<std::size_t>(x)],
        });
      }
    }
    mesh.backend = PureQuadCompletionBackend::ClosedForm;
  } else if (patch.simple) {
    const int boundaryCount = static_cast<int>(patch.boundaryVertices.size());
    for (int i = 0; i < boundaryCount; i += 2) {
      const int a = pure_quad_detail::append_embedded_vertex(
          mesh, nextInterior,
          {pure_quad_detail::boundary_source_point(patch, i),
           pure_quad_detail::boundary_source_point(patch, (i + 1) % boundaryCount)});
      const int b = pure_quad_detail::append_embedded_vertex(
          mesh, nextInterior,
          {pure_quad_detail::boundary_source_point(patch, (i + 1) % boundaryCount),
           pure_quad_detail::boundary_source_point(patch, (i + 2) % boundaryCount)});
      mesh.quads.push_back(
          {patch.boundaryVertices[static_cast<std::size_t>(i)],
           patch.boundaryVertices[static_cast<std::size_t>((i + 1) % boundaryCount)],
           patch.boundaryVertices[static_cast<std::size_t>((i + 2) % boundaryCount)],
           b});
      mesh.quads.push_back(
          {patch.boundaryVertices[static_cast<std::size_t>(i)],
           b, a,
           patch.boundaryVertices[static_cast<std::size_t>((i + 2) % boundaryCount)]});
    }
    mesh.backend = PureQuadCompletionBackend::ClosedForm;
  } else {
    const int boundaryCount = static_cast<int>(patch.boundaryVertices.size());
    for (int i = 0; i < boundaryCount; i += 2) {
      const int inner0 = pure_quad_detail::append_embedded_vertex(
          mesh, nextInterior,
          {pure_quad_detail::boundary_source_point(patch, i),
           pure_quad_detail::boundary_source_point(patch, (i + 2) % boundaryCount)});
      const int inner1 = pure_quad_detail::append_embedded_vertex(
          mesh, nextInterior,
          {pure_quad_detail::boundary_source_point(patch, (i + 1) % boundaryCount),
           pure_quad_detail::boundary_source_point(patch, (i + 3) % boundaryCount)});
      mesh.quads.push_back(
          {patch.boundaryVertices[static_cast<std::size_t>(i)],
           patch.boundaryVertices[static_cast<std::size_t>((i + 1) % boundaryCount)],
           inner1, inner0});
    }
    mesh.backend = PureQuadCompletionBackend::PatternFallback;
  }
  pure_quad_detail::fill_positions(mesh);
  result.mesh = std::move(mesh);
  result.success = std::all_of(result.mesh.quads.begin(), result.mesh.quads.end(),
                               [](const auto &q) { return q.size() == 4; });
  return result;
}

inline EndpointResolutionResult resolve_completion_endpoints(
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

inline std::vector<TopologyRewriteTemplate> default_topology_rewrite_catalog() {
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

inline TopologyRewriteResult apply_topology_rewrite_catalog(
    const std::vector<TopologyRewriteCandidate> &candidates,
    const std::vector<TopologyRewriteTemplate> &catalog =
        default_topology_rewrite_catalog()) {
  TopologyRewriteResult result;
  std::vector<TopologyRewriteCandidate> sorted = candidates;
  std::sort(sorted.begin(), sorted.end(),
            [](const auto &a, const auto &b) { return a.id < b.id; });
  for (const TopologyRewriteCandidate &candidate : sorted) {
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
          templ.objectiveDelta >= 0.0 || !candidate.postconditionsHold) {
        continue;
      }
      result.records.push_back({candidate.id, templ.id, true,
                                templ.outputAdjacency});
      ++result.committed;
      committed = true;
      break;
    }
    if (!committed) {
      result.records.push_back({candidate.id, -1, false});
      ++result.rejected;
    }
  }
  return result;
}

inline bool closed_surface_singularity_budget_exact(
    const int eulerCharacteristic, const std::vector<int> &singularityNumerators) {
  const int sum = std::accumulate(singularityNumerators.begin(),
                                  singularityNumerators.end(), 0);
  return sum == 4 * eulerCharacteristic;
}

inline PureQuadValidationReport validate_pure_quad_completion(
    const PureQuadMesh &mesh, const std::vector<int> &extraordinaryValences = {},
    const std::set<int> &featureVertices = {},
    const bool singularityBudgetExact = true) {
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

#endif // DIRECTIONAL_GEOMETRY_PURE_QUAD_COMPLETION_H
