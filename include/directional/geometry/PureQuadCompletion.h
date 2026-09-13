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
#include <optional>
#include <set>
#include <string>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/authority/CanonicalRoute.h>

#include <directional/meshing/PatchRegion.h>
#include <directional/geometry/SurfacePoint.h>
#include <directional/geometry/SurfacePointSupport.h>
#include <directional/geometry/SourceTopologyRegions.h>
#include <directional/geometry/SurfaceCellOwnership.h>
#include <directional/geometry/SurfaceCellTracing.h>
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

inline const char *pure_quad_patch_reject_reason_name(
    const PureQuadPatchRejectReason reason) {
  switch (reason) {
  case PureQuadPatchRejectReason::None:
    return "none";
  case PureQuadPatchRejectReason::NonDisk:
    return "non-disk";
  case PureQuadPatchRejectReason::BoundaryLoopCount:
    return "boundary-loop-count";
  case PureQuadPatchRejectReason::SideCountUnsupported:
    return "side-count-unsupported";
  case PureQuadPatchRejectReason::InvalidTurn:
    return "invalid-turn";
  case PureQuadPatchRejectReason::OddBoundary:
    return "odd-boundary";
  case PureQuadPatchRejectReason::HardFeatureCrossing:
    return "hard-feature-crossing";
  case PureQuadPatchRejectReason::SideInequality:
    return "side-inequality";
  case PureQuadPatchRejectReason::HexParity:
    return "hex-parity";
  case PureQuadPatchRejectReason::SingularityMismatch:
    return "singularity-mismatch";
  case PureQuadPatchRejectReason::MissingBoundaryData:
    return "missing-boundary-data";
  case PureQuadPatchRejectReason::UnsupportedSingularityCompletion:
    return "unsupported-singularity-completion";
  case PureQuadPatchRejectReason::SearchLimitExceeded:
    return "search-limit-exceeded";
  case PureQuadPatchRejectReason::TopologyValidationFailed:
    return "topology-validation-failed";
  case PureQuadPatchRejectReason::RewritePreconditionFailed:
    return "rewrite-precondition-failed";
  case PureQuadPatchRejectReason::RewriteFeatureViolation:
    return "rewrite-feature-violation";
  case PureQuadPatchRejectReason::RewriteValenceMismatch:
    return "rewrite-valence-mismatch";
  }
  return "unknown";
}

enum class PureQuadCompletionBackend : int {
  ClosedForm = 0,
  TransitionTemplate = 1,
  Pattern = 2,
  BoundedCombinatorial = 3,
  PoleTemplate = 4,
  SourceGridRecovery = 5,
};

inline const char *pure_quad_completion_backend_name(
    const PureQuadCompletionBackend backend) {
  switch (backend) {
  case PureQuadCompletionBackend::ClosedForm:
    return "closed-form";
  case PureQuadCompletionBackend::TransitionTemplate:
    return "transition-template";
  case PureQuadCompletionBackend::Pattern:
    return "pattern";
  case PureQuadCompletionBackend::BoundedCombinatorial:
    return "bounded-combinatorial";
  case PureQuadCompletionBackend::PoleTemplate:
    return "pole-template";
  case PureQuadCompletionBackend::SourceGridRecovery:
    return "source-grid-recovery";
  }
  return "unknown";
}

enum class PureQuadEmbeddingFailureKind : int {
  None = 0,
  DuplicateMeshVertex = 1,
  InvalidQuadCardinality = 2,
  RepeatedQuadVertex = 3,
  MissingVertexPosition = 4,
  NonFinitePosition = 5,
  DegenerateNormal = 6,
  ZeroProjectedArea = 7,
  BowTieIntersection = 8,
};

inline const char *pure_quad_embedding_failure_name(
    const PureQuadEmbeddingFailureKind failure) {
  switch (failure) {
  case PureQuadEmbeddingFailureKind::None:
    return "none";
  case PureQuadEmbeddingFailureKind::DuplicateMeshVertex:
    return "duplicate-mesh-vertex";
  case PureQuadEmbeddingFailureKind::InvalidQuadCardinality:
    return "invalid-quad-cardinality";
  case PureQuadEmbeddingFailureKind::RepeatedQuadVertex:
    return "repeated-quad-vertex";
  case PureQuadEmbeddingFailureKind::MissingVertexPosition:
    return "missing-vertex-position";
  case PureQuadEmbeddingFailureKind::NonFinitePosition:
    return "nonfinite-position";
  case PureQuadEmbeddingFailureKind::DegenerateNormal:
    return "degenerate-normal";
  case PureQuadEmbeddingFailureKind::ZeroProjectedArea:
    return "zero-projected-area";
  case PureQuadEmbeddingFailureKind::BowTieIntersection:
    return "bow-tie-intersection";
  }
  return "unknown";
}

struct PureQuadEmbeddingFailure {
  bool active = false;
  PureQuadEmbeddingFailureKind kind = PureQuadEmbeddingFailureKind::None;
  int sourcePatch = -1;
  PureQuadCompletionBackend backend = PureQuadCompletionBackend::ClosedForm;
  int completionVariant = 0;
  int localQuad = -1;
  std::array<int, 4> localVertices{{-1, -1, -1, -1}};
  std::vector<int> sourceFaces;
};

enum class PureQuadVertexLineageKind : int { SourceTriangle = 0, OrderedFeatureInterval = 1 };

struct PureQuadFeatureIntervalLineage {
  std::optional<authority::HardRailId> railId; int curveId = -1; SurfacePoint start; SurfacePoint end; double parameter = 0.0;
  [[nodiscard]] bool valid() const { return (railId.has_value() || curveId >= 0) && start.valid() && end.valid() && parameter >= 0.0 && parameter <= 1.0; }
};

enum class PureQuadEquivalenceKind : int {
  OrdinaryFront = 0,
  HardRail = 1,
  PeriodicHolonomy = 2,
};

/** Exact relation that joined two source-corner occurrences. */
struct PureQuadEquivalenceProvenance {
  PureQuadEquivalenceKind kind = PureQuadEquivalenceKind::OrdinaryFront;
  int firstFrontEdge = -1;
  int secondFrontEdge = -1;
  std::optional<authority::PeriodicRelationId> periodicRelation;
  std::optional<authority::HardRailId> railId;
  authority::GridAutomorphism action = authority::GridAutomorphism::identity();
  authority::CanonicalRoute route;
  std::vector<authority::SourceEdgeTopologyKey> isolationSeams;

  auto operator<=>(const PureQuadEquivalenceProvenance &) const = default;
};

struct PureQuadVertexLineage {
  int outputVertex = -1;
  PureQuadVertexLineageKind kind = PureQuadVertexLineageKind::SourceTriangle;
  SurfacePoint sourcePoint;
  PureQuadFeatureIntervalLineage featureInterval;
  PureQuadStitchIdentity stitchIdentity;
  // Derived canonical certificate cache for diagnostics/ownership-cycle
  // comparison. The typed region/sheet/chart/support fields below remain the
  // source authority; this value is recomputed from their final intersection
  // at stitch publication and is never a source for reconstructing them.
  PureQuadStitchIdentity authoritativeIdentity;
  int sourcePatch = -1;
  int localVertex = -1;
  /// Full retained authority for quotient-materialized vertices.
  std::vector<authority::TopologyRegionId> sourceTopologyRegions;
  std::vector<SourceProjectionChart> sourceCharts;
  std::vector<authority::IsolationSheetId> sourceIsolationSheets;
  std::optional<authority::SourceSupport> sourceSupport;
  /// Canonical quotient owner when this vertex was materialized from phase-front occurrences.
  std::optional<authority::QuotientClassId> quotientClass;
  /// Exact typed source-corner occurrences consumed by quotient materialization.
  std::vector<authority::OccurrenceId> sourceOccurrences;
  std::vector<PureQuadEquivalenceProvenance> equivalences;
  [[nodiscard]] bool valid() const {
    return outputVertex >= 0 &&
           ((kind == PureQuadVertexLineageKind::SourceTriangle &&
             sourcePoint.valid()) ||
            (kind == PureQuadVertexLineageKind::OrderedFeatureInterval &&
             featureInterval.valid()));
  }
};
struct PureQuadFaceLineage {
  int outputQuad = -1; int sourcePatch = -1; PureQuadCompletionBackend operation = PureQuadCompletionBackend::ClosedForm; int operationLocalQuad = -1;
  int completionVariant = 0;
  bool boundaryOnly = false;
  std::uint64_t canonicalStitchCycleHash = 0U;
  std::uint64_t canonicalAuthoritativeCycleHash = 0U;
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
  std::vector<std::optional<authority::HardRailId>> boundaryRailIds;
  std::vector<int> boundaryCurveIds;
  std::vector<authority::TopologyRegionId> boundaryTopologyRegions;
  std::vector<SourceProjectionChart> boundaryCharts;
  std::vector<SurfaceCellCanonicalIdentity> boundaryNodeIdentities;
  SurfaceCellDomainIdentity domainIdentity;
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
  SurfaceCellDomainIdentity domainIdentity;
  std::vector<int> vertices;
  Eigen::MatrixXd vertexPositions;
  std::vector<SurfacePoint> vertexProvenance;
  std::vector<std::vector<int>> quads;
  std::vector<int> boundaryVertices;
  // Exact arrangement-boundary authority indexed with boundaryVertices.
  // Compact lineage stitch keys are validated against this single owner.
  std::vector<SurfaceCellCanonicalIdentity> boundaryNodeIdentities;
  std::vector<std::vector<int>> boundaryLoops;
  PureQuadCompletionBackend backend = PureQuadCompletionBackend::ClosedForm;
  bool usesCenterFan = false;
  // Exact logical-side subdivision signature from the source patch. This is
  // retained through completion so assembly conflicts can distinguish
  // different boundary routes that happen to share the same four corners.
  std::vector<int> sourceSideEdgeCounts;
  std::vector<PureQuadVertexLineage> vertexLineage;
  std::vector<PureQuadFaceLineage> quadLineage;
};

struct PureQuadCompletionOwnershipRejection {
  bool active = false;
  std::string failure;
  int sourcePatch = -1;
  int localVertex = -1;
  bool boundaryVertex = false;
  PureQuadCompletionBackend backend = PureQuadCompletionBackend::ClosedForm;
  int completionVariant = 0;
  int storedFace = -1;
  Eigen::Vector3d barycentric = Eigen::Vector3d::Zero();
  std::optional<authority::SourceSupport> sourceSupport;
  std::vector<authority::SourceFaceId> candidateSupportedFaces;
  std::vector<int> patchSourceFaces;
};

struct PureQuadCompletionOptions {
  int sourcePatch = -1;
  int maxBoundaryEdges = 128;
  bool allowBoundedCombinatorialFallback = true;
  // Selects a deterministic alternative completion template. Variant zero is
  // the historical template; higher values are used only by global ownership
  // assignment when a distinct patch would otherwise emit the same face.
  int completionVariant = 0;
  const Eigen::MatrixXd *sourceVertices = nullptr;
  const Eigen::MatrixXi *sourceFaces = nullptr;
  const SurfacePointSourceSupportResolver *sourceSupportResolver = nullptr;
  const SourceTopologyRegions *sourceAuthority = nullptr;
  const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges = nullptr;
};

struct PureQuadCompletionEvidence {
  PureQuadPatchAdmissibility admissibility;
  int exploredPatterns = 0;
};

struct PureQuadCompletionFailure {
  PureQuadPatchRejectReason reason = PureQuadPatchRejectReason::None;
  PureQuadCompletionOwnershipRejection ownershipRejection;
  PureQuadEmbeddingFailure embeddingFailure;
  std::string detail;
};

class PureQuadCompletionResult : public PureQuadCompletionEvidence {
public:
  using Product = PureQuadMesh;
  using Failure = PureQuadCompletionFailure;
  using Outcome = ProducerOutcome<Product, Failure>;

  PureQuadCompletionResult() = default;
  PureQuadCompletionResult(const PureQuadCompletionResult &) = default;
  PureQuadCompletionResult(PureQuadCompletionResult &&) noexcept = default;
  PureQuadCompletionResult &operator=(const PureQuadCompletionResult &) = default;
  PureQuadCompletionResult &operator=(PureQuadCompletionResult &&) noexcept = default;

  [[nodiscard]] static PureQuadCompletionResult produced(
      PureQuadCompletionEvidence evidence, Product product) {
    if (product.quads.empty()) {
      throw std::invalid_argument(
          "Produced pure-quad completion requires a nonempty mesh.");
    }
    return PureQuadCompletionResult(
        std::move(evidence), Outcome{Produced<Product>{std::move(product)}});
  }

  [[nodiscard]] static PureQuadCompletionResult rejected(
      PureQuadCompletionEvidence evidence, Failure failure) {
    if (failure.reason == PureQuadPatchRejectReason::None) {
      throw std::invalid_argument(
          "Rejected pure-quad completion requires a typed failure.");
    }
    return PureQuadCompletionResult(
        std::move(evidence), Outcome{Rejected<Failure>{std::move(failure)}});
  }

  [[nodiscard]] bool is_produced() const noexcept {
    return std::holds_alternative<Produced<Product>>(outcome_);
  }
  [[nodiscard]] bool is_rejected() const noexcept {
    return std::holds_alternative<Rejected<Failure>>(outcome_);
  }
  [[nodiscard]] bool is_not_applicable() const noexcept {
    return std::holds_alternative<NotApplicable>(outcome_);
  }
  [[nodiscard]] const Product *produced_product() const noexcept {
    const auto *produced = std::get_if<Produced<Product>>(&outcome_);
    return produced == nullptr ? nullptr : &produced->product;
  }
  [[nodiscard]] Product &product() & {
    return std::get<Produced<Product>>(outcome_).product;
  }
  [[nodiscard]] const Product &product() const & {
    return std::get<Produced<Product>>(outcome_).product;
  }
  [[nodiscard]] Product &&product() && {
    return std::move(std::get<Produced<Product>>(outcome_).product);
  }
  [[nodiscard]] const Failure *rejection() const noexcept {
    const auto *rejected = std::get_if<Rejected<Failure>>(&outcome_);
    return rejected == nullptr ? nullptr : &rejected->failure;
  }
  [[nodiscard]] const Outcome &outcome() const & noexcept { return outcome_; }
  [[nodiscard]] Outcome &&outcome() && noexcept { return std::move(outcome_); }

private:
  PureQuadCompletionResult(PureQuadCompletionEvidence evidence, Outcome outcome)
      : PureQuadCompletionEvidence(std::move(evidence)),
        outcome_(std::move(outcome)) {}

  Outcome outcome_{NotApplicable{}};
};

namespace pure_quad_detail {

/**
 * Close one retained vertex lineage against exact source authority.
 *
 * This is the single region/sheet/chart closure implementation shared by
 * patch completion and authoritative phase-front completion. The caller
 * supplies the already-resolved source support so generated patch interiors
 * can retain their deliberate face-interior support semantics.
 */
bool close_completion_lineage_source_authority(
    PureQuadVertexLineage &lineage,
    const SurfacePointSourceSupport &support,
    const Eigen::MatrixXi *sourceFaces,
    const SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
    std::string &failure);

/**
 * Validate and close a materialized authoritative phase-front mesh before it
 * may be published as a successful completion result. This adapter performs
 * only mesh/support checks and delegates chart closure to
 * close_completion_lineage_source_authority().
 */
bool validate_materialized_completion_domain_ownership(
    PureQuadMesh &mesh, const Eigen::MatrixXi &sourceFaces,
    const SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
    std::string &failure);

bool validate_completion_domain_ownership(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    int completionVariant,
    const SurfacePointSourceSupportResolver *sourceSupportResolver,
    const Eigen::MatrixXi *sourceFaces,
    const SourceTopologyRegions *sourceAuthority, std::string &failure,
    PureQuadCompletionOwnershipRejection *ownershipRejection,
    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges);

} // namespace pure_quad_detail

struct PureQuadAssemblyResult {
  bool success = false;
  PureQuadMesh mesh;
  int mergedBoundaryVertices = 0;
  int connectedComponents = 0;
  int boundaryLoopCount = 0;
  int eulerCharacteristic = 0;
  SurfaceCellOwnershipConflict ownershipConflict;
  std::vector<SurfaceCellOwnershipConflict> ownershipConflicts;
  // Deterministic capacity-based estimates of the transient stitching
  // workspace. These exclude allocator bookkeeping but expose the dominant
  // ownership registry and deferred-output payloads that are otherwise gone by
  // the time pipeline-level memory diagnostics are recorded.
  std::uint64_t estimatedOwnershipRegistryOwnedBytes = 0U;
  std::uint64_t estimatedDeferredOutputOwnedBytes = 0U;
  std::uint64_t estimatedWorkspaceOwnedBytes = 0U;
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
    const SourceTopologyRegions *sourceAuthority);

void initialize_boundary_embedding(const PureQuadPatch &patch,
                                          PureQuadMesh &mesh);

int append_embedded_vertex(
    PureQuadMesh &mesh, int &nextInterior,
    const Eigen::Vector3d &targetPosition,
    const std::vector<SurfacePoint> &anchors,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority);

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

/**
 * Derive the canonical strong authority identity from the lineage's published
 * stitch key and complete typed region/sheet/chart/support authority.
 *
 * This is intentionally a one-way derivation.  The compact identity must not
 * become an alternate source of region, sheet, chart, or support authority.
 */
/** Rebuild the compact stitch key from authoritative patch structure and
 * final typed lineage authority. Stored stitch-kind/cache values are ignored. */
PureQuadStitchIdentity canonical_lineage_stitch_identity(
    const PureQuadMesh &patch, int localRow);

PureQuadStitchIdentity canonical_authoritative_identity(
    const PureQuadVertexLineage &lineage, const Eigen::MatrixXi &sourceFaces,
    const SourceTopologyRegions &sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges);

} // namespace pure_quad_detail

PureQuadPatchAdmissibility
check_pure_quad_patch_admissibility(const PureQuadPatch &patch);

bool pure_quad_topology_is_disk(const PureQuadMesh &mesh);

namespace pure_quad_detail {

bool complete_rectangular_grid(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority);

bool complete_six_vertex_transition(const PureQuadPatch &patch,
                                           PureQuadMesh &mesh);

void append_boundary_fan(const std::vector<int> &boundary,
                                const int anchor, PureQuadMesh &mesh);

bool complete_singularity_pole(
    const PureQuadPatch &patch, PureQuadMesh &mesh,
    const SurfaceProjectionBvh *projection,
    const std::vector<unsigned char> *allowedFaces,
    const SourceTopologyRegions *sourceAuthority);

bool complete_pattern(const PureQuadPatch &patch, PureQuadMesh &mesh);

bool complete_bounded(const PureQuadPatch &patch, PureQuadMesh &mesh,
                             int &explored);

} // namespace pure_quad_detail

PureQuadCompletionResult complete_pure_quad_patch(
    const PureQuadPatch &patch,
    const PureQuadCompletionOptions &options = {});

PureQuadAssemblyResult stitch_pure_quad_patches(
    const std::vector<PureQuadMesh> &patches,
    const double positionTolerance,
    const Eigen::MatrixXi *sourceFaces,
    const SourceTopologyRegions *sourceAuthority,
    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges);

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
