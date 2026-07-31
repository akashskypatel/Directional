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
#include <map>
#include <memory>
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
  MissingBoundaryData = 10,
  UnsupportedSingularityCompletion = 11,
  SearchLimitExceeded = 12,
  TopologyValidationFailed = 13,
  RewritePreconditionFailed = 14,
  RewriteFeatureViolation = 15,
  RewriteValenceMismatch = 16,
};

enum class PureQuadCompletionBackend : int {
  ClosedForm = 0,
  TransitionTemplate = 1,
  Pattern = 2,
  BoundedCombinatorial = 3,
  PoleTemplate = 4,
  SourceGridRecovery = 5,
};

enum class PureQuadVertexLineageKind : int { SourceTriangle = 0, OrderedFeatureInterval = 1 };

struct PureQuadFeatureIntervalLineage {
  int railId = -1; int curveId = -1; SurfacePoint start; SurfacePoint end; double parameter = 0.0;
  [[nodiscard]] bool valid() const { return (railId >= 0 || curveId >= 0) && start.valid() && end.valid() && parameter >= 0.0 && parameter <= 1.0; }
};
struct PureQuadVertexLineage {
  int outputVertex = -1; PureQuadVertexLineageKind kind = PureQuadVertexLineageKind::SourceTriangle; SurfacePoint sourcePoint; PureQuadFeatureIntervalLineage featureInterval;
  [[nodiscard]] bool valid() const { return outputVertex >= 0 && ((kind == PureQuadVertexLineageKind::SourceTriangle && sourcePoint.valid()) || (kind == PureQuadVertexLineageKind::OrderedFeatureInterval && featureInterval.valid())); }
};
struct PureQuadFaceLineage {
  int outputQuad = -1; int sourcePatch = -1; PureQuadCompletionBackend operation = PureQuadCompletionBackend::ClosedForm; int operationLocalQuad = -1;
  [[nodiscard]] bool valid() const { return outputQuad >= 0 && sourcePatch >= 0 && operationLocalQuad >= 0; }
};
struct PureQuadOutputLineageValidation { bool valid=false; bool allVerticesMapped=false; bool allQuadsMapped=false; bool solelyPairedSourceTriangleBoundaries=false; std::string failure; };

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
  // Source triangles covered by this patch. Completion uses this set to
  // project generated vertices without leaking onto another component or
  // nearby sheet.
  std::vector<int> sourceFaces;
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
  int sourcePatch = -1;
  std::vector<int> vertices;
  Eigen::MatrixXd vertexPositions;
  std::vector<SurfacePoint> vertexProvenance;
  std::vector<std::vector<int>> quads;
  std::vector<int> boundaryVertices;
  std::vector<std::vector<int>> boundaryLoops;
  PureQuadCompletionBackend backend = PureQuadCompletionBackend::ClosedForm;
  bool usesCenterFan = false;
  std::vector<PureQuadVertexLineage> vertexLineage;
  std::vector<PureQuadFaceLineage> quadLineage;
};

struct PureQuadCompletionOptions {
  int sourcePatch = -1;
  int maxBoundaryEdges = 128;
  bool allowBoundedCombinatorialFallback = true;
  const Eigen::MatrixXd *sourceVertices = nullptr;
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const std::vector<int> *sourceFaceComponents = nullptr;
  const std::vector<int> *sourceFaceSheets = nullptr;
};

struct PureQuadCompletionResult {
  bool success = false;
  PureQuadPatchAdmissibility admissibility;
  PureQuadMesh mesh;
  PureQuadPatchRejectReason failureReason = PureQuadPatchRejectReason::None;
  int exploredPatterns = 0;
};

struct PureQuadAssemblyResult {
  bool success = false;
  PureQuadMesh mesh;
  int mergedBoundaryVertices = 0;
  int connectedComponents = 0;
  int boundaryLoopCount = 0;
  int eulerCharacteristic = 0;
  std::string failure;
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

struct GuardedTopologyMutation {
  int id = -1;
  TopologyTemplateKind kind = TopologyTemplateKind::PolePairSlide;
  std::vector<int> removeQuadIndices;
  std::vector<std::vector<int>> replacementQuads;
  std::vector<std::pair<int, int>> protectedEdges;
  std::map<int, int> expectedValenceBefore;
  std::map<int, int> expectedValenceAfter;
  bool preserveBoundary = true;
  bool preserveEulerCharacteristic = true;
};

struct GuardedTopologyMutationRecord {
  int mutationId = -1;
  TopologyTemplateKind kind = TopologyTemplateKind::PolePairSlide;
  bool committed = false;
  PureQuadPatchRejectReason reason =
      PureQuadPatchRejectReason::RewritePreconditionFailed;
  std::vector<int> affectedVertices;
};

struct GuardedTopologyMutationResult {
  PureQuadMesh mesh;
  std::vector<GuardedTopologyMutationRecord> records;
  int committed = 0;
  int rejected = 0;
};

struct TopologyRewriteCandidate {
  int id = -1;
  std::vector<int> adjacency;
  std::vector<int> boundarySignature;
  int featureLabel = 0;
  int singularityLabel = 0;
  bool singularityBudgetAvailable = true;
  GuardedTopologyMutation mutation;
};

struct TopologyRewriteRecord {
  int candidateId = -1;
  int templateId = -1;
  bool committed = false;
  std::vector<int> outputAdjacency;
  PureQuadPatchRejectReason reason =
      PureQuadPatchRejectReason::RewritePreconditionFailed;
};

struct TopologyRewriteResult {
  PureQuadMesh mesh;
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

int boundary_edge_count(const PureQuadPatch &patch);

bool turns_are_valid(const PureQuadPatch &patch);

bool side_inequalities_hold(const std::vector<int> &e);

bool hex_parity_holds(const std::vector<int> &e);

int expected_valence(const int singularIndexNumerator);

int next_generated_vertex(int &next);

SurfacePoint make_planar_source_point(const int face,
                                             const Eigen::Vector3d &position,
                                             const Eigen::Vector3d &barycentric);

SurfacePoint boundary_source_point(const PureQuadPatch &patch,
                                          const int boundaryIndex);

SurfacePoint average_source_point(const std::vector<SurfacePoint> &points);

SurfacePoint project_generated_point(
    const Eigen::Vector3d &target, const std::vector<SurfacePoint> &anchors,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets);

void initialize_boundary_embedding(const PureQuadPatch &patch,
                                          PureQuadMesh &mesh);

int append_embedded_vertex(
    PureQuadMesh &mesh, int &nextInterior,
    const Eigen::Vector3d &targetPosition,
    const std::vector<SurfacePoint> &anchors,
    const SurfaceProjectionBvh *projection = nullptr,
    const std::vector<unsigned char> *allowedFaces = nullptr,
    const std::vector<int> *faceComponents = nullptr,
    const std::vector<int> *faceSheets = nullptr);

bool fill_positions(PureQuadMesh &mesh);

bool vectors_equal(const std::vector<int> &a, const std::vector<int> &b);

std::pair<int, int> canonical_edge(const int a, const int b);

std::map<std::pair<int, int>, int>
edge_incidence(const std::vector<std::vector<int>> &quads);

std::map<int, int> vertex_valences(
    const std::vector<std::vector<int>> &quads);

int mesh_euler_characteristic(const std::vector<std::vector<int>> &quads);

std::set<std::pair<int, int>> boundary_edges(
    const std::vector<std::vector<int>> &quads);

bool quads_are_locally_valid(const std::vector<std::vector<int>> &quads);

} // namespace pure_quad_detail

PureQuadPatchAdmissibility
check_pure_quad_patch_admissibility(const PureQuadPatch &patch);

bool pure_quad_topology_is_disk(const PureQuadMesh &mesh);

namespace pure_quad_detail {

bool complete_rectangular_grid(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets);

bool complete_six_vertex_transition(const PureQuadPatch &patch,
                                           PureQuadMesh &mesh);

void append_boundary_fan(const std::vector<int> &boundary,
                                const int anchor, PureQuadMesh &mesh);

bool complete_singularity_pole(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const std::vector<int> *faceComponents,
    const std::vector<int> *faceSheets);

bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh);

bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
                             int &explored);

} // namespace pure_quad_detail

PureQuadCompletionResult complete_pure_quad_patch(
    const PureQuadPatch &patch,
    const PureQuadCompletionOptions &options = {});

PureQuadAssemblyResult stitch_pure_quad_patches(
    const std::vector<PureQuadMesh> &patches,
    const double positionTolerance = 1.0e-9);

EndpointResolutionResult resolve_completion_endpoints(
    std::vector<CompletionEndpoint> endpoints);

std::vector<TopologyRewriteTemplate> default_topology_rewrite_catalog();

GuardedTopologyMutationResult apply_guarded_topology_mutations(
    const PureQuadMesh &input,
    std::vector<GuardedTopologyMutation> mutations);

TopologyRewriteResult apply_topology_rewrite_catalog(
    const PureQuadMesh &input,
    const std::vector<TopologyRewriteCandidate> &candidates,
    const std::vector<TopologyRewriteTemplate> &catalog =
        default_topology_rewrite_catalog());

GuardedTopologyMutationResult apply_guarded_topology_mutations(
    const PureQuadMesh &input,
    std::vector<GuardedTopologyMutation> mutations);

bool closed_surface_singularity_budget_exact(
    const int eulerCharacteristic, const std::vector<int> &singularityNumerators);

PureQuadValidationReport validate_pure_quad_completion(
    const PureQuadMesh &mesh, const std::vector<int> &extraordinaryValences = {},
    const std::set<int> &featureVertices = {},
    const bool singularityBudgetExact = true);

int source_vertex_from_point(const SurfacePoint &p, const Eigen::MatrixXi &F, double tol=1e-8);
bool output_is_only_paired_source_triangle_boundaries(const PureQuadMesh &mesh,const Eigen::MatrixXi &F);
PureQuadOutputLineageValidation validate_pure_quad_output_lineage(const PureQuadMesh &mesh,const Eigen::MatrixXi &F,bool rejectPaired=true);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_PURE_QUAD_COMPLETION_H
