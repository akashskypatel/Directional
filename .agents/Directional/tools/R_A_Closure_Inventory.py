#!/usr/bin/env python3
"""Reproducible static R-A closure inventory through R-A-REV-35.

This audit is intentionally source-only. It never executes a generated Directional
binary. Runtime semantic acceptance remains a separate artifact-only turn.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Sequence


@dataclass(frozen=True)
class Probe:
    rev: str
    name: str
    paths: tuple[str, ...]
    pattern: str
    expectation: str  # absent | present
    rationale: str
    flags: int = 0


ROOT_SCOPES = (
    "include/directional",
    "src",
    "tests",
    ".github/workflows/agent-compile-reusable.yml",
)

PROBES: tuple[Probe, ...] = (
    Probe("REV-01", "materializer owns typed isolation-sheet state",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"authority::IsolationSheetId isolationSheet;", "present",
          "OccurrenceData carries typed sheet authority instead of reading SurfacePoint::sheet as authority."),
    Probe("REV-01", "materializer raw projection is not read for sheet/component decisions",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"occurrence\.point\.(?:component|sheet)|representativeOccurrence\.point\.(?:component|sheet)", "absent",
          "The quotient/materializer semantic path must consume typed region/sheet/chart/support authority."),

    Probe("REV-02", "completion stitch key has no raw provenance component/sheet encoding",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"(?:stitchIdentity|canonical|identity).*provenance\.(?:component|sheet)|provenance\.(?:component|sheet).*(?:stitchIdentity|canonical|identity)", "absent",
          "Raw SurfacePoint labels may not enter semantic stitch/ownership identity."),
    Probe("REV-03", "typed stitch resolver rejects stale cached identity",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"lineage\.stitchIdentity != typed", "present",
          "A prebuilt compatibility identity cannot bypass typed fail-closed derivation."),
    Probe("REV-03", "missing typed stitch authority is an explicit failure",
          ("src/geometry/PureQuadCompletion.cpp", "tests/PureQuadCompletionPhase18Tests.cpp"),
          r"MissingTypedStitchIdentity", "present",
          "Exact geometry identity alone is insufficient for stitch publication."),

    Probe("REV-04", "validator does not read raw SurfacePoint component/sheet",
          ("src/validation/SourceAuthoritativeMeshValidator.cpp",),
          r"\.(?:component|sheet)\b", "absent",
          "Source-authoritative validation must use typed source authority, not generic projection labels."),
    Probe("REV-04", "rail constraints do not read raw SurfacePoint component/sheet",
          ("src/geometry/SurfaceOptimizationRailConstraints.cpp",),
          r"\.(?:component|sheet)\b", "absent",
          "Rail authority must not be scoped or accepted from generic projection labels."),

    Probe("REV-05", "typed-authority contract coverage remains compiled",
          ("tests/PureQuadCompletionPhase18Tests.cpp", "tests/SurfaceMeshOptimizerPhase19Tests.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"(?:MissingTypedStitchIdentity|MissingSourceAuthority|RawProjection|Stale|Distinct.*Sheet|Wrong.*Authority)", "present",
          "Retained test sources must contain fail-closed typed-authority and tamper contracts."),
    Probe("REV-06", "compile package manifest excludes and verifies itself",
          (".github/workflows/agent-compile-reusable.yml",),
          r"find \. -type f ! -name SHA256SUMS.*SHA256SUMS|sha256sum -c SHA256SUMS", "present",
          "Compile evidence must remain internally self-verifying."),
    Probe("REV-06", "compile package records clean source snapshots",
          (".github/workflows/agent-compile-reusable.yml",),
          r"source-status-(?:preconfigure|before-configure|after-configure|after-build|final)", "present",
          "Build provenance requires clean source status before/after build/package steps."),

    Probe("REV-07", "assembly validates owner-backed typed certificate",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"owner_validated_typed_authority_certificate", "present",
          "Published/stitch-authoritative vertices require complete owned region/sheet/chart/support authority."),
    Probe("REV-08", "SurfaceCells optimizer has mandatory source-authority predicate",
          ("src/geometry/SurfaceMeshOptimizer.cpp",),
          r"source_optimization_has_complete_authority", "present",
          "Strict optimizer/final validator entry points must fail closed without source authority."),
    Probe("REV-09", "component remap domain is typed and owner-derived",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"ComponentTypedAuthorityRemapDomain|make_component_typed_authority_remap_domain", "present",
          "Multi-component sheet/region/chart/support remapping must derive from typed owner domains."),
    Probe("REV-10", "bounded legacy audit is superseded by this complete inventory",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"R-A closure inventory through R-A-REV-35", "present",
          "REV-10's sampled audit is not used as closure evidence; this reproducible inventory replaces it."),

    Probe("REV-11", "collision certificates are intersected before publication",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"intersect_typed_authority_certificate", "present",
          "Same-key/same-position collision is not sufficient without compatible typed authority."),
    Probe("REV-11", "same region-sheet distinct support compatibility negative remains compiled",
          ("tests/PureQuadCompletionPhase18Tests.cpp",),
          r"SameRegionSheetDifferentCompletedSupportsRejectTypedStitchCompatibility", "present",
          "Typed stitch compatibility must reject genuinely different completed source supports even when region and isolation sheet agree."),
    Probe("REV-11", "faces-only typed stitch discrimination reasons remain explicit",
          ("tests/PureQuadCompletionPhase18Tests.cpp",),
          r"CoincidentPositionsOnDistinctTypedSheetsDoNotMerge|WrongOwnerSheetCertificatePublishesNothing|SameExactBoundaryKeyRejectsIncompatibleTypedLineage|InvalidTypedStitchAuthority|IncompatibleTypedStitchAuthority", "present",
          "The next immutable runtime report must record each retained faces-only contract's actual discrimination outcome or rejection reason."),
    Probe("REV-12", "aggregate remap is checked and final lineage is validated",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"remap_quotient_lineage_authority|validate_aggregate_lineage_authority", "present",
          "Invalid chart/support/region/sheet remaps must reject before publication."),
    Probe("REV-13", "complete affected surface list is explicitly audited",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"AFFECTED_R_A_PATHS", "present",
          "Closure evidence names the affected source/test/workflow surfaces instead of sampling a few blocks."),

    Probe("REV-14", "post-intersection canonical authority identity is retained",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"canonical_typed_authority_identity", "present",
          "Collision publication derives one canonical authority identity from the final certificate."),
    Probe("REV-15", "region/sheet/chart/support remap domain is not self-bounded",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"ComponentTypedAuthorityRemapDomain", "present",
          "Remap domains are owned by published source topology/chart authority."),
    Probe("REV-16", "counterfactual mutation seam occurs before aggregation",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"beforeAggregation", "present",
          "Raw/tamper counterfactuals must reach the real aggregate consumer before publication."),
    Probe("REV-17", "certificate claims are checked against source ownership",
          ("src/geometry/PureQuadCompletion.cpp",),
          r"owner_validated_typed_authority_certificate", "present",
          "Collision certificates must be owned by exact source topology/chart/support authority."),

    Probe("REV-18", "one global aggregate source owner is constructed",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"globalSourceAuthority", "present",
          "Disconnected aggregation must publish lineage through one checked global SourceTopologyRegions owner."),
    Probe("REV-18", "post-remap derived identity caches are rebuilt",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"rebuild_aggregate_output_identity_caches", "present",
          "Stitch/authoritative identities and face cycles must be regenerated after global remap."),
    Probe("REV-18", "aggregate identity rebuild reports typed failing sub-invariant",
          ("src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"AggregateIdentityRebuildResult|AggregateIdentityInvalidPatchMetadata|AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant", "present",
          "Aggregate derived-identity rejection must identify the failed canonical rebuild invariant instead of collapsing every defect to one generic bool."),
    Probe("REV-18", "aggregate boundary identity cache is reconstructed from canonical lineage",
          ("include/directional/diagnostics/RemeshDiagnostics.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"surfaceCellAggregateIdentityBoundaryCacheRebuildCount|boundaryNodeIdentities\.assign", "present",
          "Missing or stale patch-local boundary identity cache is derived state and must be rebuilt from remapped completion-owned lineage."),
    Probe("REV-18", "anti-stale aggregate boundary cache proves canonical publication",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches", "present",
          "The anti-stale contract requires valid boundary identities equal to completion-owned canonical lineage, not merely absence of a stale token."),
    Probe("REV-19", "aggregate publication is staged transactionally",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"RemeshResult staged = merged;", "present",
          "Semantic context remains uncommitted until all remaps and final validation succeed."),
    Probe("REV-19", "actual final merged mesh reaches source-authoritative validator",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"validate_source_authoritative_surface_mesh", "present",
          "Cached component reports cannot substitute for the post-merge oracle."),

    Probe("REV-20", "removed raw/legacy SurfaceCells compatibility paths stay absent",
          ("include/directional/geometry/SurfaceMeshOptimizer.h", "src/geometry/SurfaceMeshOptimizer.cpp", "src/geometry/SurfaceOptimizationRailConstraints.cpp", "src/validation/SourceAuthoritativeMeshValidator.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"sourcePositions|constraints\.sourceComponent|featureIntervals|legacyIndex|standaloneFixture", "absent",
          "Named raw optimizer/verifier and legacy point-cloud/feature-interval/standalone compatibility authority must remain removed."),
    Probe("REV-20", "post-move single-component optimizer retains exact source authority",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"PostMoveSingleComponentOptimizerUsesRetainedSourceAuthority", "present",
          "Moving the trace network must not invalidate the exact typed source owner consumed later by optimization; this contract isolates that lifetime from aggregate merge success."),
    Probe("REV-20", "typed optimizer authority mismatch negative remains compiled",
          ("tests/SurfaceMeshOptimizerPhase19Tests.cpp",),
          r"TriangleProjectionFailsClosedWhenTypedSourceAuthorityDoesNotMatchSourceFaces", "present",
          "Raw SurfacePoint sheet labels are not authority; the replacement negative mutates exact typed source ownership and must remain present."),

    Probe("REV-21", "exact source-row topology binding is used",
          ("include/directional/geometry/SourceTopologyRegions.h", "src/geometry/PureQuadCompletion.cpp", "src/geometry/SurfaceMeshOptimizer.cpp", "src/validation/SourceAuthoritativeMeshValidator.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"matches_source_faces", "present",
          "Same face count is not source ownership; paired geometry and authority must match exact row topology."),
    Probe("REV-21", "authority-only row permutation negative exists",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"AuthorityOnlyFaceRowPermutationRejectsExactTopologyBinding", "present",
          "The mismatched-pair counterexample must retain old authority while permuting only the source matrix."),
    Probe("REV-21", "consistent matrix-plus-authority permutation positive exists",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"ConsistentlyPermutedSourceMatrixAndAuthorityPreserveSemanticTopology", "present",
          "A row permutation remains valid when source geometry and rebuilt authority are paired consistently."),

    Probe("REV-22", "final aggregate carries independent strict validator authority",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"ComponentFinalValidationAuthority|globalValidationBoundaryLoops|globalValidationFeatureRails|globalValidationVertexCharts|globalValidationOutputQuadSourceFaces|globalValidationHardFeatureEdges", "present",
          "Boundary, feature, chart, output-face, hard-edge, and provenance authority must survive global remap into the final oracle."),
    Probe("REV-22", "final aggregate enables strict boundary/feature/local-sheet gates",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"finalAuthorityOptions\.requireBoundaryAuthority = true;|finalAuthorityOptions\.requireFeatureRailAuthority = true;|finalAuthorityOptions\.requireLocalSheetCompatibility = true;", "present",
          "The final oracle cannot weaken component strict gates to make aggregate output pass."),
    Probe("REV-22", "materialized hard-feature rail authority derives from exact quotient lineage",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"project_materialized_hard_feature_rails_from_lineage|PureQuadEquivalenceKind::HardRail", "present",
          "Phase-front hard-feature output sequences must be reconstructed from exact materializer equivalence provenance and actual output edges rather than proximity alone."),
    Probe("REV-22", "hard-feature no-producer-applicable outcome is typed and fail-closed",
          ("src/geometry/SurfaceCellTracing.cpp", "include/directional/diagnostics/RemeshDiagnostics.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped|UnsupportedSourceSheetTopology|surfaceCellUniformPhaseFrontProducerDeclined|surfaceCellPeriodicPhaseFrontProducerDeclined|surfaceCellBoundedDiskPhaseFrontProducerDeclined", "present",
          "When all ordered regional phase-front producers decline a hard-feature topology region, the typed unsupported outcome must fail closed and retain producer-decline evidence."),
    Probe("REV-22", "feature aggregate witness explicitly enters a produced phase-front domain",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r'RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent|make_disconnected_rectangular_feature_pair_mesh|surfaceCellAuthoritativeProducerDisposition == \"Produced\"', "present",
          "The internal hard-feature aggregate witness must use rectangular planar regions and explicitly observe a Produced authoritative phase-front before downstream oracle claims."),
    Probe("REV-22", "component authority tamper contracts name the aggregation seam",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"ComponentBoundaryRailTamperRejectsAtAggregationSeam|ComponentFeatureRailTamperRejectsAtAggregationSeam", "present",
          "Component capture-versus-mutation tests prove the pre-oracle seam guard and do not claim final-oracle coverage."),
    Probe("REV-22", "component explicit feature options are remapped to compact ownership",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"make_component_feature_option_remap_plan|apply_component_feature_option_remap|userHardEdges|userSoftEdges", "present",
          "Global explicit feature-edge IDs must be filtered by component ownership and translated into compact component-local vertex IDs before execution."),
    Probe("REV-22", "component feature-option no-leakage contract remains compiled",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"ComponentFeatureOptionsRemapOwnedEdgesWithoutCrossComponentLeakage", "present",
          "An explicit edge owned by one disconnected source component must not appear as a same-numbered local feature tag in another component."),
    Probe("REV-22", "component feature-option transport is conserved and typed",
          ("include/directional/diagnostics/RemeshDiagnostics.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"surfaceCellUserHardFeatureEdgeUnassignedCount|surfaceCellUserSoftFeatureEdgeUnassignedCount|SurfaceCellFeatureOptionRemapIssue", "present",
          "Every canonical requested hard/soft source edge must be remapped exactly once or explicitly counted as unassigned; unassigned hard edges fail closed."),
    Probe("REV-22", "unassigned user hard-feature edge fails before component execution",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"UnassignedUserHardFeatureEdgeFailsClosedBeforeComponentExecution", "present",
          "A requested hard edge with no owning source component may not disappear silently."),
    Probe("REV-22", "final oracle boundary and feature authority negatives exist",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"FinalMergedOracleRejectsMissingRemappedBoundaryAuthority|FinalMergedOracleRejectsMissingRemappedFeatureAuthority", "present",
          "Post-remap counterfactuals must pass component seam checks and make the final oracle reject missing boundary/feature authority with zero publication."),
    Probe("REV-22", "final oracle boundary content mismatch negative exists",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent", "present",
          "Present remapped boundary authority must be content-checked and reject with ChangedBoundaryLoop rather than only proving the absence guard."),
    Probe("REV-22", "final oracle feature content mismatch negative exists",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"FinalMergedOracleRejectsChangedRemappedFeatureRailContent", "present",
          "Present remapped feature authority with preserved cardinality must reject when a rail is absent from the merged output."),
    Probe("REV-22", "feature-bearing final oracle positive is non-vacuous",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority|expectedFeatureRailCount > 0U", "present",
          "Positive aggregate coverage must observe a non-empty feature-rail authority set before accepting it."),
    Probe("REV-22", "final oracle full issue list is retained in diagnostics",
          ("include/directional/diagnostics/RemeshDiagnostics.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"surfaceCellFinalSourceAuthorityValidationIssues", "present",
          "Content-mismatch negatives must prove the actual final-oracle issue list rather than relying only on preferred-code selection."),
    Probe("REV-22", "aggregate validation flags are sourced from final oracle observables",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"finalAuthorityValidation\.(?:strictValidationUsed|provenanceValidationUsed|boundaryAuthorityUsed|featureRailAuthorityUsed)", "present",
          "Published strict/provenance/boundary/feature usage flags must be oracle evidence, not constants."),
    Probe("REV-22", "aggregate validation flags are not hardcoded true",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"aggregateValidationResult\.(?:strictValidationUsed|provenanceValidationUsed|authoritativeFeatureRailsUsed)\s*=\s*true", "absent",
          "A hardcoded publication flag is a tautology and cannot establish validator execution."),
    Probe("REV-22", "option-echo usage EXPECT_TRUE assertions are absent",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"EXPECT_TRUE\((?:finalValidation\.strictValidationUsed|finalValidation\.authoritativeFeatureRailsUsed|oracle\.strictValidationUsed|oracle\.featureRailAuthorityUsed)\)", "absent",
          "Usage-option echoes are not semantic evidence; tests retain published-vs-oracle equality and input-derived gate observations instead."),
    Probe("REV-22", "final oracle outcome is published independently of component reports",
          ("include/directional/pipeline/RemeshPipeline.h", "src/pipeline/RemeshPipeline.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"hasFinalSourceAuthorityValidationResult|componentValidationReportsComplete|FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing", "present",
          "Consumers must distinguish final oracle success from missing component-level aggregate reports."),
    Probe("REV-22", "valid boundary-bearing aggregate asserts strict final oracle evidence",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"finalSourceAuthorityValidationResult|authoritativeBoundaryUsed|authoritativeFeatureRailsUsed|orderedBoundaryCyclesPassed|sourceAuthoritativeValidationUsed", "present",
          "Positive coverage must prove the strict final merged-product validator actually ran and published its typed result."),

    Probe("REV-23", "pipeline stitch-kind assignment is structurally absent",
          ("src/pipeline",),
          r"stitchIdentity\s*(?:\.|->)\s*kind|(?:\w+::)*PureQuadStitchIdentityKind", "absent",
          "A structural whole-statement matcher rejects wrapped, fully-qualified, alias-based, and stale-copy stitch-kind writes across every pipeline translation unit."),
    Probe("REV-23", "pipeline stitch-kind classifier self-test is wired",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"self_test_pipeline_stitch_kind_classifier", "present",
          "The audit proves its own coverage against the four independently reviewed evasion forms."),
    Probe("REV-23", "completion-owned canonical stitch constructor is used",
          ("include/directional/geometry/PureQuadCompletion.h", "src/geometry/PureQuadCompletion.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"canonical_lineage_stitch_identity", "present",
          "Post-remap stitch kind/schema is derived from authoritative patch structure by the completion owner."),
    Probe("REV-23", "stale-kind and post-publication re-stitch contracts exist",
          ("tests/SurfaceCellsPhase10Tests.cpp", ),
          r"GeneratedPatchInterior|stitch_pure_quad_patches|stitchIdentity\.kind", "present",
          "Generated interior lineages must remain canonical/resolvable after stale cache tamper and publication."),

    Probe("REV-24", "direct source-authoritative validator rejects null authority at entry",
          ("src/validation/SourceAuthoritativeMeshValidator.cpp",),
          r"options\.sourceAuthority == nullptr", "present",
          "Missing typed source authority is invalid independently of optional boundary/feature/local-sheet gates."),
    Probe("REV-24", "direct null/foreign authority negatives exist",
          ("tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp",),
          r"MissingSourceAuthorityRejectsEvenWhenOptionalGatesAreDisabled|SameExtentForeignSourceAuthorityRejectsBeforeOptionalGates", "present",
          "Direct public validator coverage must prove null and same-extent foreign authority fail closed."),
    Probe("REV-25", "hard-rail pair grouping uses orientation-independent canonical route content",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"routeSteps|edge\.route\.steps\(\)", "present",
          "Hard-rail chart copies group by canonical route content while retaining per-edge route orientation authority."),
    Probe("REV-25", "hard-rail pair validates reversed route before opposite publication",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"first\.route != second\.route\.reversed\(\)", "present",
          "Producer pairing rejects non-opposite route orientation/content before publishing oppositeEdge."),
    Probe("REV-25", "hard-rail pair validates explicit rail owner compatibility",
          ("src/geometry/SurfaceCellTracing.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"first\.railId\.has_value\(\).*second\.railId\.has_value\(\)", "present",
          "When both hard-rail copies name explicit rail owners, producer and materializer reject unequal IDs."),
    Probe("REV-25", "hard-rail transport counterfactuals remain compiled",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"HardRailPairPublishesReverseRouteTransportBeforeMaterialization|HardRailPairSameOrientationRejectsStrictTransport|HardRailPairChangedRouteContentRejectsStrictTransport|HardRailPairExplicitRailIdMismatchRejectsStrictTransport|HardRailPairingIsFaceRowOrderInvariant", "present",
          "Focused contracts cover valid reverse transport, same-orientation rejection, route mutation, rail-ID mismatch, and ordering invariance."),
    Probe("REV-25", "empty canonical route reversal still flips orientation",
          ("tests/SurfaceCellAuthorityKernelTests.cpp",),
          r"EmptyCanonicalRouteReversalStillFlipsOrientation", "present",
          "CanonicalRoute reversal changes canonical orientation even with no steps; no empty-route identity exception is valid."),
    Probe("REV-26", "retained-boundary observation derives intrinsic canonical edge parameter",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"canonical_retained_edge_parameter", "present",
          "Retained source-edge route authority derives direction from ordered intrinsic edge coordinates rather than face row, winding, or downstream repair."),
    Probe("REV-26", "retained-boundary observation emits reverse traversal orientation",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"authority::Orientation::Reverse", "present",
          "CB-01 must introduce an explicit Reverse observation in SurfaceCellTracing.cpp; a zero count proves orientation was not added at the retained-edge observation layer."),
    Probe("REV-27", "retained HardRail owner resolves from authoritative source-rail intervals",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"rail_interval_refs\(options\.authoritativeRails|find_rail_interval\(railBuild\.intervals", "present",
          "HardRail publication must resolve an existing owner from validated source-attached rail support, never output geometry or proximity."),
    Probe("REV-27", "HardRail owner coverage is non-vacuous before materialization",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"EXPECT_TRUE\(first\.railId\.has_value\(\)\)|EXPECT_EQ\(first\.railId, second\.railId\)|sawMaterializedHardRailOwner", "present",
          "The direct producer contract requires non-empty equal source-authoritative HardRail ownership before and after materialization."),
    Probe("REV-27", "pair route-content counterfactual remains individually valid",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"HardRailPairChangedRouteContentRejectsStrictTransport|pairs\.back\(\)\.first", "present",
          "The strict pair negative reuses another producer-emitted individually valid route instead of manufacturing invalid per-edge authority."),
    Probe("REV-28", "completion preserves certified HardRail chart and region closure",
          ("src/geometry/PureQuadCompletion.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"completion_certified_hard_rail_components|sawCertifiedHardRailCompletionLineage", "present",
          "Completion may retain cross-hard-feature chart/region authority only when exact retained HardRail quotient lineage certifies that closure."),
    Probe("REV-28", "uncertified HardRail chart broadening remains rejected",
          ("src/geometry/PureQuadCompletion.cpp", "tests/SurfaceCellsPhase10Tests.cpp"),
          r"reachableHardRailComponents|FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority", "present",
          "Completion must not broadly union incident charts across hard features; missing, malformed-owner, and foreign chart counterfactuals remain strict."),
    Probe("REV-29", "generic and authoritative completion use one shared chart-closure implementation",
          ("include/directional/geometry/PureQuadCompletion.h", "src/geometry/PureQuadCompletion.cpp", "src/pipeline/RemeshPipeline.cpp"),
          r"close_completion_lineage_source_authority|validate_materialized_completion_domain_ownership", "present",
          "Both completion paths must converge on the same source region/sheet/chart closure implementation rather than duplicate authority semantics."),
    Probe("REV-29", "authoritative completion validates ownership before declaring success",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"validate_materialized_completion_domain_ownership", "present",
          "The useAuthoritativePhaseFront branch may not hand-synthesize successful completion without source-authority ownership validation."),
    Probe("REV-29", "strict HardRail final-oracle negative is explicitly non-vacuous",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"reachedFinalValidationCallback|mutated=false is non-evidence", "present",
          "A strict negative is evidence only after the callback is reached and the intended authority mutation is actually applied."),
    Probe("REV-30", "authoritative regional production consumes canonical source-chart authority",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"SourceChartTransitionGraph canonicalSourceCharts|canonicalSourceCharts\.chart", "present",
          "Planar, periodic, and bounded regional producers must publish FieldChartId from the canonical full-source chart owner."),
    Probe("REV-30", "region-local semantic chart writers are removed",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"single_field_chart_authority|legacyFaceChart|equalOrientationAdjacency", "absent",
          "Region-local ordinal/chart partitions may not become semantic source-chart identity."),
    Probe("REV-30", "canonical chart publication is direct at cell and segment seams",
          ("src/geometry/SurfaceCellTracing.cpp",),
          r"sourceChart = canonicalChart->chart|frame\.faceChart.*canonicalChart", "present",
          "Semantic sourceChart publication is a projection of canonical SourceChartTransitionGraph authority, not an independently numbered producer chart."),
    Probe("REV-30", "pre-closure contract compares phase-front charts to canonical graph",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"AuthoritativePhaseFrontPublishesCanonicalSourceChartsBeforeMaterialization|chartGraph\.chart\(sourceFace\)", "present",
          "The writer boundary is tested before materialization/shared closure so downstream repair cannot hide a chart-domain split."),

    Probe("REV-31", "production source-label classification does not alias hard-feature rails into isolation sheets",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"classify_source_surface_labels\s*\(\s*meshWhole\.V\s*,\s*meshWhole\.F\s*,\s*hardFeatureRailEdges\b", "absent",
          "Hard-feature rail authority may split topology regions/charts without becoming IsolationSheetId authority."),
    Probe("REV-31", "production declares a separate isolation-barrier authority input",
          ("src/pipeline/RemeshPipeline.cpp",),
          r"sourceIsolationBarrierEdges", "present",
          "Production source-sheet classification consumes a distinct barrier domain while geometric close-sheet classification remains active."),
    Probe("REV-31", "production hard-feature witness distinguishes topology regions from isolation sheets",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent|sheetCounts|hard-feature topology separation must not create an isolation sheet", "present",
          "The representative production witness requires two hard-feature topology regions but exactly one isolation sheet per component."),
    Probe("REV-31", "explicit isolation barrier counterexample remains compiled in packaged producer source",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet|isolationBarriers", "present",
          "A genuine independently supplied isolation barrier must still split an otherwise connected local sheet."),

    Probe("REV-32", "mandatory isolation-barrier contract is owned by packaged producer source",
          ("tests/SurfaceCellsPhase10Tests.cpp",),
          r"SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet", "present",
          "The package-specific mandatory contract must live in a source compiled by an approved default R-A executable."),
    Probe("REV-32", "mandatory isolation-barrier contract is absent from historical-only source",
          ("tests/SurfaceCellTracingPhase14Tests.cpp",),
          r"SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet", "absent",
          "The same acceptance authority must not remain duplicated behind the disabled historical-test option."),
    Probe("REV-32", "packaged producer target compiles the mandatory-contract source",
          ("cmake/DirectionalTests.cmake",),
          r"tests/SurfaceCellsPhase10Tests\.cpp\)", "present",
          "Static target membership must map the mandatory-contract source to the approved packaged producer executable."),
    Probe("REV-32", "compile configuration keeps historical suite disabled",
          (".github/workflows/agent-compile-reusable.yml",),
          r"-DDIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF", "present",
          "Package closure must come from surgical default-target placement rather than enabling the historical suite."),

    Probe("REV-33", "source-chart barrier authority is mandatory by constructor type",
          ("include/directional/geometry/SourceChartTransitions.h",),
          r"const std::set<std::uint64_t> &hardFeatureEdges", "present",
          "Omitting canonical chart barrier authority is a compile error; callers must pass an explicit set."),
    Probe("REV-33", "source-chart constructor has no default-null barrier authority",
          ("include/directional/geometry/SourceChartTransitions.h",),
          r"hardFeatureEdges\s*=\s*nullptr", "absent",
          "The authority omission class is closed by construction rather than rediscovered at runtime."),
    Probe("REV-33", "aggregate typed remap requires explicit hard-feature authority",
          ("include/directional/pipeline/RemeshPipeline.h", "src/pipeline/RemeshPipeline.cpp"),
          r"const std::set<std::uint64_t> &hardFeatureEdges", "present",
          "Aggregate canonical chart reconstruction consumes barrier authority explicitly."),
    Probe("REV-33", "focused aggregate remap barrier counterexample is packaged",
          ("tests/SurfaceCellTransitionQuotientTests.cpp",),
          r"ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain", "present",
          "The same lineage succeeds with captured HardRail barriers and fails closed with explicit empty barriers."),

    Probe("REV-34", "mandatory remap witness constructs source topology directly",
          ("tests/SurfaceCellTransitionQuotientTests.cpp",),
          r"build_source_topology_regions", "present",
          "The mandatory remap contract owns only source topology/HardRail authority and does not require phase-front production.", flags=re.S),
    Probe("REV-34", "production-dependent HardRail fixture uses feasible internal midline",
          ("tests/SurfaceCellTransitionQuotientTests.cpp",),
          r"authoritativeRails\.push_back", "present",
          "Tests that genuinely require phase-front HardRail transport use the proven 3x3 internal-midline producer domain.", flags=re.S),
    Probe("REV-34", "mandatory remap source remains in packaged producer target",
          ("cmake/DirectionalTests.cmake",),
          r"tests/SurfaceCellTransitionQuotientTests\.cpp", "present",
          "The mandatory identity must remain compiled into the approved immutable producer package.", flags=re.S),

    Probe("REV-35", "mandatory remap builds source topology from compact component faces",
          ("tests/SurfaceCellTransitionQuotientTests.cpp",),
          r"build_source_topology_regions\(component\.faces, options\)", "present",
          "The direct remap witness must construct source authority in the same compact component topology consumed by the remap helper."),
    Probe("REV-35", "mandatory remap names component-local hard-feature authority",
          ("tests/SurfaceCellTransitionQuotientTests.cpp",),
          r"localHardFeatureEdges", "present",
          "Original HardRail vertices are remapped before barrier authority enters the compact component domain."),
    Probe("REV-35", "mandatory remap asserts exact compact source ownership",
          ("tests/SurfaceCellTransitionQuotientTests.cpp",),
          r"direct remap witness authority must match compact component topology", "present",
          "The test must prove the exact source-face ownership precondition before constructing either remap domain."),
    Probe("REV-35", "retry16 produced-fixture diagnostics are explicitly declared",
          (".agents/Directional/R_A_Closure_Inventory.py",),
          r"RETRY16_MANDATORY_PRODUCED_IDENTITIES", "present",
          "All six changed produced HardRail fixture consumers are explicit package-specific mandatory identities for retry-16 discovery."),

)

AFFECTED_R_A_PATHS: tuple[str, ...] = (
    "include/directional/diagnostics/RemeshDiagnostics.h",
    "include/directional/pipeline/RemeshPipeline.h",
    "include/directional/geometry/PureQuadCompletion.h",
    "include/directional/geometry/SourceChartTransitions.h",
    "include/directional/geometry/SourceTopologyRegions.h",
    "include/directional/geometry/SurfaceMeshOptimizer.h",
    "include/directional/validation/SourceAuthoritativeMeshValidator.h",
    "src/geometry/PureQuadCompletion.cpp",
    "src/geometry/SurfaceArrangement.cpp",
    "src/geometry/SurfaceCellTracing.cpp",
    "src/geometry/SurfaceMeshOptimizer.cpp",
    "src/geometry/SurfaceOptimizationRailConstraints.cpp",
    "src/pipeline/RemeshPipeline.cpp",
    "src/validation/SourceAuthoritativeMeshValidator.cpp",
    "tests/PureQuadCompletionPhase18Tests.cpp",
    "tests/SurfaceCellAuthorityKernelTests.cpp",
    "tests/SurfaceCellsPhase10Tests.cpp",
    "tests/SurfaceMeshOptimizerPhase19Tests.cpp",
    "tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp",
    ".github/workflows/agent-compile-reusable.yml",
    "cmake/DirectionalTests.cmake",
)


def iter_files(root: Path, paths: Sequence[str]) -> Iterable[tuple[str, Path]]:
    for rel in paths:
        path = root / rel
        if path.is_dir():
            for child in sorted(path.rglob("*")):
                if child.is_file() and child.suffix in {".h", ".hpp", ".cpp", ".cc", ".cxx", ".yml", ".yaml", ".py"}:
                    yield child.relative_to(root).as_posix(), child
        elif path.is_file():
            yield rel, path
        else:
            raise FileNotFoundError(rel)


def _normalized_statement(text: str) -> str:
    return " ".join(text.split())


def _statement_line(text: str, offset: int) -> int:
    return text.count("\n", 0, offset) + 1


def _pipeline_stitch_kind_assignment_matches(
    rel: str, text: str,
) -> list[tuple[str, int, str]]:
    enum_aliases = set(re.findall(
        r"\busing\s+([A-Za-z_]\w*)\s*=\s*(?:[A-Za-z_]\w*::)*PureQuadStitchIdentityKind\s*;",
        text,
        re.MULTILINE,
    ))
    typed_identity_variables = set(re.findall(
        r"(?:[A-Za-z_]\w*::)*PureQuadStitchIdentity\s+([A-Za-z_]\w*)\b",
        text,
        re.MULTILINE,
    ))
    auto_identity_variables = set(re.findall(
        r"\bauto\s+([A-Za-z_]\w*)\s*=\s*[^;]*canonical_lineage_stitch_identity\s*\(",
        text,
        re.MULTILINE | re.DOTALL,
    ))
    identity_variables = typed_identity_variables | auto_identity_variables
    assignment = re.compile(
        r"(?P<lhs>\b[A-Za-z_]\w*(?:\s*(?:\.|->)\s*[A-Za-z_]\w*)*)"
        r"\s*(?:\.|->)\s*kind\s*=\s*(?P<rhs>[^;]+);",
        re.MULTILINE,
    )
    enum_reference = re.compile(
        r"(?:[A-Za-z_]\w*::)*PureQuadStitchIdentityKind\b"
    )
    stale_kind_copy = re.compile(
        r"\bstitchIdentity\s*(?:\.|->)\s*kind\b"
    )
    out: list[tuple[str, int, str]] = []
    for match in assignment.finditer(text):
        lhs = re.sub(r"\s+", "", match.group("lhs"))
        rhs = match.group("rhs")
        root = re.split(r"(?:\.|->)", lhs, maxsplit=1)[0]
        alias_reference = any(
            re.search(rf"\b{re.escape(alias)}\s*::", rhs)
            for alias in enum_aliases
        )
        if (
            "stitchIdentity" not in lhs
            and root not in identity_variables
            and enum_reference.search(rhs) is None
            and stale_kind_copy.search(rhs) is None
            and not alias_reference
        ):
            continue
        out.append((
            rel,
            _statement_line(text, match.start()),
            _normalized_statement(match.group(0)),
        ))
    return out


def matches_for(root: Path, probe: Probe) -> list[tuple[str, int, str]]:
    if probe.name == "pipeline stitch-kind assignment is structurally absent":
        out: list[tuple[str, int, str]] = []
        for rel, path in iter_files(root, probe.paths):
            if path.suffix not in {".cpp", ".cc", ".cxx"}:
                continue
            out.extend(_pipeline_stitch_kind_assignment_matches(
                rel, path.read_text(encoding="utf-8")))
        return out

    regex = re.compile(probe.pattern, probe.flags)
    out: list[tuple[str, int, str]] = []
    for rel, path in iter_files(root, probe.paths):
        for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            if regex.search(line):
                out.append((rel, line_no, line.strip()))
    return out


def classify_raw_projection_leaves(root: Path) -> tuple[list[tuple[str, int, str, str]], list[tuple[str, int, str]]]:
    paths = (
        "src/pipeline/RemeshPipeline.cpp",
        "src/geometry/PureQuadCompletion.cpp",
        "src/geometry/SurfaceMeshOptimizer.cpp",
        "src/geometry/SurfaceOptimizationRailConstraints.cpp",
        "src/validation/SourceAuthoritativeMeshValidator.cpp",
    )
    regex = re.compile(r"\b(?:point|provenance|projected|sourcePoint|averaged)\.(?:component|sheet)\b")
    allowed: list[tuple[str, int, str, str]] = []
    unexpected: list[tuple[str, int, str]] = []
    for rel, path in iter_files(root, paths):
        lines = path.read_text(encoding="utf-8").splitlines()
        for line_no, line in enumerate(lines, 1):
            if not regex.search(line):
                continue
            text = line.strip()
            if re.search(r"\.(?:component|sheet)\s*=", text):
                classification = "one-way SurfacePoint geometry/export projection write"
            elif rel == "src/geometry/PureQuadCompletion.cpp" and re.search(r"=\s*point\.(?:component|sheet)\s*;", text):
                classification = "geometry-only averaging payload propagation; not stitch/owner/validator identity"
            else:
                unexpected.append((rel, line_no, text))
                continue
            allowed.append((rel, line_no, text, classification))
    return allowed, unexpected


def classify_face_count_leaves(root: Path) -> tuple[list[tuple[str, int, str, str]], list[tuple[str, int, str]]]:
    regex = re.compile(r"complete_for_face_count")
    allowed: list[tuple[str, int, str, str]] = []
    unexpected: list[tuple[str, int, str]] = []
    for rel, path in iter_files(root, ("include/directional", "src", "tests")):
        for line_no, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            if not regex.search(line):
                continue
            text = line.strip()
            if rel == "include/directional/geometry/SourceTopologyRegions.h":
                classification = (
                    "SourceTopologyRegions-local structural extent precondition; semantic consumers use matches_source_faces, "
                    "which immediately performs exact checked row-topology equality"
                )
                allowed.append((rel, line_no, text, classification))
            else:
                unexpected.append((rel, line_no, text))
    return allowed, unexpected


def _function_span(text: str, signature: str) -> tuple[int, int] | None:
    start = text.find(signature)
    if start < 0:
        return None
    open_brace = text.find("{", start)
    if open_brace < 0:
        return None
    depth = 0
    for offset in range(open_brace, len(text)):
        if text[offset] == "{":
            depth += 1
        elif text[offset] == "}":
            depth -= 1
            if depth == 0:
                return start, offset + 1
    return None


def classify_pipeline_stitch_identity_assignments(
    root: Path,
) -> tuple[list[tuple[str, int, str, str]], list[tuple[str, int, str]]]:
    whole_assignment = re.compile(
        r"\bstitchIdentity\s*=\s*([^;]+);", re.MULTILINE
    )
    member_assignment = re.compile(
        r"\bstitchIdentity\s*(?:\.|->)\s*[A-Za-z_]\w*"
        r"(?:\s*(?:\.|->)\s*[A-Za-z_]\w*)*\s*=\s*([^;]+);",
        re.MULTILINE,
    )
    allowed: list[tuple[str, int, str, str]] = []
    unexpected_by_key: dict[tuple[str, int, str], tuple[str, int, str]] = {}

    for rel, path in iter_files(root, ("src/pipeline",)):
        if path.suffix not in {".cpp", ".cc", ".cxx"}:
            continue
        text = path.read_text(encoding="utf-8")
        function_span = None
        function_text = ""
        canonical_factory_present = False
        canonical_map_populated = False
        if rel == "src/pipeline/RemeshPipeline.cpp":
            function_span = _function_span(
                text, "AggregateIdentityRebuildResult rebuild_aggregate_output_identity_caches("
            )
            if function_span is not None:
                function_text = text[function_span[0]:function_span[1]]
                canonical_factory_present = (
                    "canonical_lineage_stitch_identity(" in function_text
                )
                canonical_map_populated = bool(re.search(
                    r"canonicalStitchByPatchVertex\s*\n?\s*\.emplace\("
                    r"[\s\S]{0,300}?lineage\.stitchIdentity\)",
                    function_text,
                ))

        for match in whole_assignment.finditer(text):
            line_no = _statement_line(text, match.start())
            rhs = _normalized_statement(match.group(1))
            statement = _normalized_statement(match.group(0))
            inside_canonical = (
                function_span is not None
                and function_span[0] <= match.start() < function_span[1]
            )
            if rel == "src/pipeline/RemeshPipeline.cpp" and inside_canonical:
                if rhs == "stitch":
                    lookback = text[max(function_span[0], match.start() - 500):match.start()]
                    if "canonical_lineage_stitch_identity(" in lookback:
                        allowed.append((
                            rel, line_no, statement,
                            "direct assignment from the completion-owned canonical_lineage_stitch_identity result",
                        ))
                        continue
                if (
                    rhs == "canonical->second"
                    and canonical_factory_present
                    and canonical_map_populated
                ):
                    lookback = text[max(function_span[0], match.start() - 400):match.start()]
                    if "canonicalStitchByPatchVertex.find(" in lookback:
                        allowed.append((
                            rel, line_no, statement,
                            "assignment from a lookup map populated only by the completion-owned canonical stitch result",
                        ))
                        continue
            unexpected_by_key[(rel, line_no, statement)] = (rel, line_no, statement)

        for match in member_assignment.finditer(text):
            line_no = _statement_line(text, match.start())
            statement = _normalized_statement(match.group(0))
            unexpected_by_key[(rel, line_no, statement)] = (rel, line_no, statement)

        for kind_match in _pipeline_stitch_kind_assignment_matches(rel, text):
            unexpected_by_key[kind_match] = kind_match

    unexpected = sorted(unexpected_by_key.values())
    if not allowed and not unexpected:
        unexpected.append((
            "src/pipeline",
            0,
            "no stitchIdentity assignments found for structural classification",
        ))
    return allowed, unexpected


def self_test_pipeline_stitch_kind_classifier() -> tuple[list[str], list[str]]:
    cases = (
        (
            "fully-qualified-enum",
            "identity.kind = directional::geometry::PureQuadStitchIdentityKind::ArrangementBoundaryNode;",
        ),
        (
            "wrapped-enum-assignment",
            "identity.kind =\n    geometry::PureQuadStitchIdentityKind::ArrangementBoundaryNode;",
        ),
        (
            "stale-kind-copy",
            "identity.kind = lineage.stitchIdentity.kind;",
        ),
        (
            "enum-alias",
            "using K = geometry::PureQuadStitchIdentityKind; identity.kind = K::ArrangementBoundaryNode;",
        ),
    )
    passed: list[str] = []
    failed: list[str] = []
    for name, sample in cases:
        matches = _pipeline_stitch_kind_assignment_matches(
            f"<self-test:{name}>", sample
        )
        if matches:
            passed.append(name)
        else:
            failed.append(name)
    return passed, failed


def rev30_convergence_guards(root: Path) -> tuple[list[str], list[str]]:
    completion = (root / "src/geometry/PureQuadCompletion.cpp").read_text(encoding="utf-8")
    pipeline = (root / "src/pipeline/RemeshPipeline.cpp").read_text(encoding="utf-8")
    tracing = (root / "src/geometry/SurfaceCellTracing.cpp").read_text(encoding="utf-8")
    tests = (root / "tests/SurfaceCellsPhase10Tests.cpp").read_text(encoding="utf-8")
    passed: list[str] = []
    failed: list[str] = []

    def record(name: str, condition: bool) -> None:
        (passed if condition else failed).append(name)

    definitions = len(re.findall(
        r"\bbool\s+close_completion_lineage_source_authority\s*\(",
        completion,
    ))
    record("exactly-one-shared-closure-definition", definitions == 1)

    generic_start = completion.find("bool validate_completion_domain_ownership(")
    adapter_start = completion.find("bool validate_materialized_completion_domain_ownership(")
    record("generic-completion-calls-shared-closure",
           generic_start >= 0 and completion.find(
               "close_completion_lineage_source_authority(", generic_start) >= 0)
    record("authoritative-adapter-calls-shared-closure",
           adapter_start >= 0 and generic_start > adapter_start and
           completion.find("close_completion_lineage_source_authority(",
                           adapter_start, generic_start) >= 0)

    completion_result = pipeline.find(
        "geometry::SurfaceCellComplexCompletionResult completionResult;")
    branch_start = pipeline.find("if (useAuthoritativePhaseFront) {",
                                 completion_result)
    branch_end = pipeline.find("    } else {", branch_start)
    branch = pipeline[branch_start:branch_end] \
        if branch_start >= 0 and branch_end > branch_start else ""
    validation_pos = branch.find(
        "validate_materialized_completion_domain_ownership(")
    success_pos = branch.find("completionResult.success = true;")
    record("authoritative-success-follows-ownership-validation",
           validation_pos >= 0 and success_pos > validation_pos)
    record("pipeline-does-not-duplicate-chart-closure-internals",
           "reachableHardRailComponents" not in pipeline and
           "completion_certified_hard_rail_components" not in pipeline)
    record("final-oracle-negative-requires-callback-and-mutation",
           "reachedFinalValidationCallback = true;" in tests and
           "mutated=false is non-evidence" in tests)
    record("authoritative-regional-producers-use-canonical-source-chart-domain",
           tracing.count("SourceChartTransitionGraph canonicalSourceCharts(") >= 3 and
           tracing.count("canonicalSourceCharts.chart(") >= 3)
    record("local-field-chart-writers-removed",
           "single_field_chart_authority" not in tracing and
           "legacyFaceChart" not in tracing and
           "equalOrientationAdjacency" not in tracing)
    record("planar-chart-publication-is-not-region-local-ordinal",
           "frame.faceChart[static_cast<std::size_t>(face)] =" in tracing and
           "canonicalChart->chart;" in tracing)
    record("preclosure-test-compares-phase-front-chart-to-canonical-graph",
           "AuthoritativePhaseFrontPublishesCanonicalSourceChartsBeforeMaterialization" in tests and
           "chartGraph.chart(sourceFace)" in tests and
           "HardRail-separated regional copies must not collide" in tests)
    return passed, failed


def _call_arguments_after_open(text: str, start: int) -> list[str]:
    depth = 0
    argument_start = start
    arguments: list[str] = []
    index = start
    while index < len(text):
        char = text[index]
        if char in "([{":
            depth += 1
        elif char in ")]}":
            if char == ")" and depth == 0:
                arguments.append(text[argument_start:index].strip())
                break
            depth -= 1
        elif char == "," and depth == 0:
            arguments.append(text[argument_start:index].strip())
            argument_start = index + 1
        index += 1
    return arguments


def _source_chart_construction_calls(text: str) -> list[tuple[str, list[str]]]:
    calls: list[tuple[str, list[str]]] = []
    direct = re.compile(r"\bSourceChartTransitionGraph\s+([A-Za-z_][A-Za-z0-9_]*)\s*\(")
    for match in direct.finditer(text):
        calls.append((match.group(1), _call_arguments_after_open(text, match.end())))
    optional_names = set(re.findall(
        r"std::optional\s*<\s*(?:geometry::)?SourceChartTransitionGraph\s*>\s+"
        r"([A-Za-z_][A-Za-z0-9_]*)\s*;", text))
    for name in optional_names:
        pattern = re.compile(rf"\b{re.escape(name)}\.emplace\s*\(")
        for match in pattern.finditer(text):
            calls.append((f"{name}.emplace", _call_arguments_after_open(text, match.end())))
    return calls


def rev33_chart_barrier_site_set_guards(root: Path) -> tuple[list[str], list[str]]:
    passed: list[str] = []
    failed: list[str] = []

    def record(name: str, condition: bool) -> None:
        (passed if condition else failed).append(name)

    sites: list[tuple[str, str, list[str]]] = []
    for source_path in sorted((root / "src").rglob("*.cpp")):
        source_text = source_path.read_text(encoding="utf-8")
        for site_name, arguments in _source_chart_construction_calls(source_text):
            sites.append((source_path.relative_to(root).as_posix(), site_name, arguments))

    record("source-chart-construction-site-set-is-exhaustively-enumerated", len(sites) == 10)
    record("every-source-chart-construction-passes-explicit-barrier-authority",
           len(sites) == 10 and all(len(arguments) >= 3 and arguments[2] not in {"nullptr", "NULL"}
                                    for _, _, arguments in sites))
    pipeline_sites = [(name, arguments) for rel, name, arguments in sites
                      if rel == "src/pipeline/RemeshPipeline.cpp"]
    aggregate_sites = [arguments for name, arguments in pipeline_sites if name == "chartGraph"]
    flowrep_sites = [arguments for name, arguments in pipeline_sites if name == "transitionGraph.emplace"]
    record("aggregate-remap-chart-site-consumes-hard-feature-authority",
           len(aggregate_sites) == 1 and len(aggregate_sites[0]) >= 3 and "hardFeatureEdges" in aggregate_sites[0][2])
    record("nullable-flowrep-input-resolves-to-explicit-empty-authority",
           len(flowrep_sites) == 1 and len(flowrep_sites[0]) >= 3 and "empty_hard_feature_edges" in flowrep_sites[0][2])
    pipeline = (root / "src/pipeline/RemeshPipeline.cpp").read_text(encoding="utf-8")
    validation_pos = pipeline.find("if (!componentValidationAuthority.available ||")
    derive_pos = pipeline.find("componentHardFeatureEdges =", validation_pos)
    derive_owner_pos = pipeline.find("componentValidationAuthority.authoritativeRails", derive_pos)
    domain_pos = pipeline.find("make_component_typed_authority_remap_domain(", derive_owner_pos)
    record("aggregate-validates-captured-rails-before-deriving-chart-barriers",
           validation_pos >= 0 and derive_pos > validation_pos and derive_owner_pos > derive_pos and domain_pos > derive_owner_pos)
    validator_header = (root / "include/directional/validation/SourceAuthoritativeMeshValidator.h").read_text(encoding="utf-8")
    completion_header = (root / "include/directional/geometry/PureQuadCompletion.h").read_text(encoding="utf-8")
    record("barrier-consuming-callable-default-null-parameters-removed",
           "*hardFeatureEdges = nullptr)" not in validator_header and
           "*sourceHardFeatureEdges = nullptr);" not in completion_header)
    return passed, failed


def rev32_package_contract_guards(root: Path) -> tuple[list[str], list[str]]:
    contract = "SourceClassifierExplicitIsolationBarrierSplitsOtherwiseConnectedSheet"
    producer_path = root / "tests/SurfaceCellsPhase10Tests.cpp"
    historical_path = root / "tests/SurfaceCellTracingPhase14Tests.cpp"
    cmake_path = root / "cmake/DirectionalTests.cmake"
    producer = producer_path.read_text(encoding="utf-8")
    historical = historical_path.read_text(encoding="utf-8")
    cmake = cmake_path.read_text(encoding="utf-8")
    passed: list[str] = []
    failed: list[str] = []

    def record(name: str, condition: bool) -> None:
        (passed if condition else failed).append(name)

    occurrences: list[tuple[str, int]] = []
    for path in sorted((root / "tests").glob("*.cpp")):
        count = path.read_text(encoding="utf-8").count(contract)
        if count:
            occurrences.append((path.relative_to(root).as_posix(), count))
    record("exactly-one-mandatory-isolation-contract-definition",
           occurrences == [("tests/SurfaceCellsPhase10Tests.cpp", 1)])
    record("mandatory-isolation-contract-owned-by-producer-source",
           producer.count(contract) == 1 and contract not in historical)

    producer_start = cmake.find("add_executable(\n  directional_surface_cell_producer_tests")
    producer_end = cmake.find(
        "directional_configure_test_target(directional_surface_cell_producer_tests)",
        producer_start,
    )
    historical_gate = cmake.find("if(DIRECTIONAL_BUILD_HISTORICAL_TESTS)")
    producer_block = (
        cmake[producer_start:producer_end]
        if producer_start >= 0 and producer_end > producer_start
        else ""
    )
    record("producer-source-is-member-of-packaged-producer-target",
           "tests/SurfaceCellsPhase10Tests.cpp" in producer_block)
    record("producer-target-is-outside-historical-option-gate",
           producer_start >= 0 and producer_end > producer_start and
           historical_gate > producer_end)
    return passed, failed



RETRY16_MANDATORY_PRODUCED_IDENTITIES: tuple[str, ...] = (
    "SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions",
    "SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected",
    "SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected",
    "SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity",
    "SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed",
    "SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed",
)


def rev34_hard_rail_fixture_guards(root: Path) -> tuple[list[str], list[str]]:
    source = (root / "tests/SurfaceCellTransitionQuotientTests.cpp").read_text(encoding="utf-8")
    cmake = (root / "cmake/DirectionalTests.cmake").read_text(encoding="utf-8")
    passed: list[str] = []
    failed: list[str] = []

    def record(name: str, condition: bool) -> None:
        (passed if condition else failed).append(name)

    def test_body(suite: str, name: str) -> str:
        pattern = re.compile(
            rf"TEST\({re.escape(suite)},\s*{re.escape(name)}\)\s*\{{(.*?)(?=\nTEST\(|\Z)",
            re.S,
        )
        match = pattern.search(source)
        return match.group(1) if match else ""

    produced_consumers = (
        ("SurfaceCellTransitionQuotient", "ExactHardRailCounterpartsStitchAcrossTopologyRegions"),
        ("SurfaceCellTransitionQuotient", "MissingHardRailCounterpartIsRejected"),
        ("SurfaceCellTransitionQuotient", "AmbiguousHardRailCounterpartIsRejected"),
        ("SurfaceCellTypedTransportAuthority", "ValidHardRailRouteUsesTypedIdentity"),
        ("SurfaceCellTypedTransportAuthority", "RouteTopologyTransitionMismatchFailsClosed"),
        ("SurfaceCellTypedTransportAuthority", "DuplicateSemanticRouteTopologyFailsClosed"),
    )
    direct_consumers = (
        ("SurfaceCellTypedTransportAuthority", "MissingInteriorTransitionIsRejectedByTypedFactory"),
        ("SurfaceCellTransitionQuotient", "ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain"),
        ("SurfaceCellTypedTransportAuthority", "OutOfDomainSourceVertexIsRejectedAtIngress"),
    )

    actual_fixture_consumers: list[str] = []
    for suite, name in produced_consumers + direct_consumers:
        body = test_body(suite, name)
        if "hard_rail_fixture()" in body:
            actual_fixture_consumers.append(f"{suite}.{name}")

    expected_fixture_consumers = [f"{suite}.{name}" for suite, name in produced_consumers]
    record("exact six production-dependent HardRail fixture consumers", actual_fixture_consumers == expected_fixture_consumers)

    for suite, name in produced_consumers:
        body = test_body(suite, name)
        record(f"produced fixture retained: {suite}.{name}", bool(body) and "hard_rail_fixture()" in body)

    for suite, name in direct_consumers:
        body = test_body(suite, name)
        record(f"direct fixture isolated: {suite}.{name}", bool(body) and "hard_rail_fixture()" not in body and "build_surface_cell_network(" not in body)

    mandatory = test_body("SurfaceCellTransitionQuotient", "ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain")
    record("mandatory remap identity defined exactly once", source.count("ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain") == 1)
    record("mandatory remap directly builds source topology authority", "build_source_topology_regions(" in mandatory)
    record("mandatory remap proves hard-aware and barrierless domains", mandatory.count("make_component_typed_authority_remap_domain(") == 2 and "empty_hard_feature_edges()" in mandatory)
    record("mandatory remap source is packaged producer input", "directional_surface_cell_producer_tests" in cmake and "tests/SurfaceCellTransitionQuotientTests.cpp" in cmake)

    helper_match = re.search(r"PhaseFrontFixture make_hard_rail_fixture\(\) \{(.*?)\n\}\n\nPhaseFrontFixture make_committed_fixture", source, re.S)
    helper = helper_match.group(1) if helper_match else ""
    record("produced fixture is 3x3 internal-midline authority", bool(helper) and "vertices(9, 3)" in helper and "faces(8, 3)" in helper and "surface_cell_source_edge_key(1, 4)" in helper and "surface_cell_source_edge_key(4, 7)" in helper and "authoritativeRails.push_back" in helper and "require_produced" in helper)


    return passed, failed


def rev35_test_authority_guards(root: Path) -> tuple[list[str], list[str]]:
    source = (root / "tests/SurfaceCellTransitionQuotientTests.cpp").read_text(encoding="utf-8")
    cmake = (root / "cmake/DirectionalTests.cmake").read_text(encoding="utf-8")
    passed: list[str] = []
    failed: list[str] = []

    def record(name: str, condition: bool) -> None:
        (passed if condition else failed).append(name)

    pattern = re.compile(
        r"TEST\(SurfaceCellTransitionQuotient,\s*"
        r"ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain\)\s*\{"
        r"(.*?)(?=\nTEST\(|\Z)",
        re.S,
    )
    match = pattern.search(source)
    mandatory = match.group(1) if match else ""

    record("mandatory-remap-authority-built-from-compact-component-faces",
           "build_source_topology_regions(component.faces, options)" in mandatory and
           "build_source_topology_regions(mesh.F, options)" not in mandatory)
    record("mandatory-remap-hardrail-is-remapped-to-component-local-vertices",
           "localVertexByOriginal" in mandatory and
           "localHardFeatureEdges" in mandatory and
           "options.hardFeatureEdges = localHardFeatureEdges;" in mandatory)
    record("mandatory-remap-asserts-exact-component-topology-ownership",
           "sourceAuthority->matches_source_faces(component.faces, component.originalVertices.size())" in mandatory and
           "direct remap witness authority must match compact component topology" in mandatory)
    record("mandatory-remap-preserves-two-region-one-sheet-oracle",
           "ASSERT_EQ(2U, sourceAuthority->regions().size())" in mandatory and
           "sourceSheetIds" in mandatory and
           "ASSERT_EQ(1U, sourceSheetIds.size())" in mandatory)
    record("mandatory-remap-lineage-support-is-created-in-local-face-domain",
           "static_cast<std::size_t>(component.faces.rows())" in mandatory and
           "SourceFaceId::from_index" in mandatory)
    record("mandatory-remap-identity-defined-exactly-once",
           source.count("ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain") == 1)

    expected = (
        "SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions",
        "SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected",
        "SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected",
        "SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity",
        "SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed",
        "SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed",
    )
    record("retry16-mandatory-produced-identity-set-is-exact",
           RETRY16_MANDATORY_PRODUCED_IDENTITIES == expected)
    for identity in RETRY16_MANDATORY_PRODUCED_IDENTITIES:
        _, name = identity.split(".", 1)
        record(f"retry16 mandatory produced identity packaged: {identity}",
               source.count(name) == 1)

    producer_start = cmake.find("add_executable(\n  directional_surface_cell_producer_tests")
    producer_end = cmake.find(
        "directional_configure_test_target(directional_surface_cell_producer_tests)",
        producer_start,
    )
    producer_block = (
        cmake[producer_start:producer_end]
        if producer_start >= 0 and producer_end > producer_start
        else ""
    )
    record("retry16-mandatory-produced-source-is-packaged-producer-input",
           "tests/SurfaceCellTransitionQuotientTests.cpp" in producer_block)

    return passed, failed


def render(root: Path) -> tuple[str, bool]:
    lines: list[str] = []
    ok = True
    lines.append("# R-A Closure Inventory through R-A-REV-35")
    lines.append("")
    lines.append("Command: `python3 .agents/Directional/R_A_Closure_Inventory.py --root .`")
    lines.append("")
    lines.append("Scope: source-only Code + Build audit. No generated Directional binary, test, benchmark, discovery, `ctest`, CLI, fuzzer, or custom input is executed.")
    lines.append("")
    lines.append("## Checked affected paths")
    lines.append("")
    for path in AFFECTED_R_A_PATHS:
        exists = (root / path).is_file()
        ok = ok and exists
        lines.append(f"- `{path}` — {'present' if exists else 'MISSING'}")
    lines.append("")
    lines.append("## REV-01 through REV-35 probes")
    lines.append("")

    current_rev = None
    total_matches = 0
    for probe in PROBES:
        if probe.rev != current_rev:
            current_rev = probe.rev
            lines.append(f"### R-A-{probe.rev}")
            lines.append("")
        matches = matches_for(root, probe)
        total_matches += len(matches)
        passed = bool(matches) if probe.expectation == "present" else not matches
        ok = ok and passed
        lines.append(f"**{probe.name}** — {'PASS' if passed else 'FAIL'}")
        lines.append("")
        lines.append(f"- Checked paths: {', '.join(f'`{p}`' for p in probe.paths)}")
        lines.append(f"- Pattern: `{probe.pattern}`")
        lines.append(f"- Expectation: `{probe.expectation}`")
        lines.append(f"- Match count: **{len(matches)}**")
        lines.append(f"- Classification: {probe.rationale}")
        if matches:
            lines.append("- Matches:")
            for rel, line_no, text in matches:
                lines.append(f"  - `{rel}:{line_no}` — `{text}`")
        lines.append("")

    lines.append("## Allowed-leaf classification")
    lines.append("")
    raw_allowed, raw_unexpected = classify_raw_projection_leaves(root)
    lines.append("### Raw `SurfacePoint::{component,sheet}` projection leaves")
    lines.append("")
    lines.append(f"- Match count: **{len(raw_allowed) + len(raw_unexpected)}**")
    lines.append(f"- Allowed count: **{len(raw_allowed)}**")
    lines.append(f"- Unexpected count: **{len(raw_unexpected)}**")
    for rel, line_no, text, classification in raw_allowed:
        lines.append(f"- ALLOWED `{rel}:{line_no}` — {classification} — `{text}`")
    for rel, line_no, text in raw_unexpected:
        lines.append(f"- UNEXPECTED `{rel}:{line_no}` — `{text}`")
    if raw_unexpected:
        ok = False
    lines.append("")

    face_allowed, face_unexpected = classify_face_count_leaves(root)
    lines.append("### `complete_for_face_count` leaves")
    lines.append("")
    lines.append(f"- Match count: **{len(face_allowed) + len(face_unexpected)}**")
    lines.append(f"- Allowed count: **{len(face_allowed)}**")
    lines.append(f"- Unexpected count: **{len(face_unexpected)}**")
    for rel, line_no, text, classification in face_allowed:
        lines.append(f"- ALLOWED `{rel}:{line_no}` — {classification} — `{text}`")
    for rel, line_no, text in face_unexpected:
        lines.append(f"- UNEXPECTED `{rel}:{line_no}` — `{text}`")
    if face_unexpected:
        ok = False
    lines.append("")

    stitch_allowed, stitch_unexpected = classify_pipeline_stitch_identity_assignments(root)
    lines.append("### Pipeline `stitchIdentity` assignment leaves")
    lines.append("")
    lines.append(f"- Match count: **{len(stitch_allowed) + len(stitch_unexpected)}**")
    lines.append(f"- Allowed count: **{len(stitch_allowed)}**")
    lines.append(f"- Unexpected count: **{len(stitch_unexpected)}**")
    for rel, line_no, text, classification in stitch_allowed:
        lines.append(f"- ALLOWED `{rel}:{line_no}` — {classification} — `{text}`")
    for rel, line_no, text in stitch_unexpected:
        lines.append(f"- UNEXPECTED `{rel}:{line_no}` — `{text}`")
    if stitch_unexpected:
        ok = False
    lines.append("")

    stitch_self_test_passed, stitch_self_test_failed = \
        self_test_pipeline_stitch_kind_classifier()
    lines.append("### Pipeline stitch-kind classifier self-test")
    lines.append("")
    lines.append(f"- Case count: **{len(stitch_self_test_passed) + len(stitch_self_test_failed)}**")
    lines.append(f"- Passed count: **{len(stitch_self_test_passed)}**")
    lines.append(f"- Failed count: **{len(stitch_self_test_failed)}**")
    for name in stitch_self_test_passed:
        lines.append(f"- PASS `{name}`")
    for name in stitch_self_test_failed:
        lines.append(f"- FAIL `{name}`")
    if stitch_self_test_failed:
        ok = False
    lines.append("")

    rev30_passed, rev30_failed = rev30_convergence_guards(root)
    lines.append("## REV-30 structural convergence guards")
    lines.append("")
    lines.append(f"- Guard count: **{len(rev30_passed) + len(rev30_failed)}**")
    lines.append(f"- Passed count: **{len(rev30_passed)}**")
    lines.append(f"- Failed count: **{len(rev30_failed)}**")
    for name in rev30_passed:
        lines.append(f"- PASS `{name}`")
    for name in rev30_failed:
        lines.append(f"- FAIL `{name}`")
    if rev30_failed:
        ok = False
    lines.append("")

    rev33_passed, rev33_failed = rev33_chart_barrier_site_set_guards(root)
    lines.append("## REV-33 exhaustive chart-barrier site-set guards")
    lines.append("")
    lines.append(f"- Guard count: **{len(rev33_passed) + len(rev33_failed)}**")
    lines.append(f"- Passed count: **{len(rev33_passed)}**")
    lines.append(f"- Failed count: **{len(rev33_failed)}**")
    for name in rev33_passed:
        lines.append(f"- PASS `{name}`")
    for name in rev33_failed:
        lines.append(f"- FAIL `{name}`")
    if rev33_failed:
        ok = False
    lines.append("")

    rev32_passed, rev32_failed = rev32_package_contract_guards(root)
    lines.append("## REV-32 package-contract membership guards")
    lines.append("")
    lines.append(f"- Guard count: **{len(rev32_passed) + len(rev32_failed)}**")
    lines.append(f"- Passed count: **{len(rev32_passed)}**")
    lines.append(f"- Failed count: **{len(rev32_failed)}**")
    for name in rev32_passed:
        lines.append(f"- PASS `{name}`")
    for name in rev32_failed:
        lines.append(f"- FAIL `{name}`")
    if rev32_failed:
        ok = False
    lines.append("")

    rev34_passed, rev34_failed = rev34_hard_rail_fixture_guards(root)
    lines.append("## REV-34 HardRail fixture/test-authority guards")
    lines.append("")
    lines.append(f"- Guard count: **{len(rev34_passed) + len(rev34_failed)}**")
    lines.append(f"- Passed count: **{len(rev34_passed)}**")
    lines.append(f"- Failed count: **{len(rev34_failed)}**")
    for name in rev34_passed:
        lines.append(f"- PASS `{name}`")
    for name in rev34_failed:
        lines.append(f"- FAIL `{name}`")
    if rev34_failed:
        ok = False
    lines.append("")

    rev35_passed, rev35_failed = rev35_test_authority_guards(root)
    lines.append("## REV-35 component-local remap/package-mandatory guards")
    lines.append("")
    lines.append(f"- Guard count: **{len(rev35_passed) + len(rev35_failed)}**")
    lines.append(f"- Passed count: **{len(rev35_passed)}**")
    lines.append(f"- Failed count: **{len(rev35_failed)}**")
    for name in rev35_passed:
        lines.append(f"- PASS `{name}`")
    for name in rev35_failed:
        lines.append(f"- FAIL `{name}`")
    if rev35_failed:
        ok = False
    lines.append("")
    lines.append("### Retry-16 package-specific mandatory produced identities")
    lines.append("")
    for identity in RETRY16_MANDATORY_PRODUCED_IDENTITIES:
        lines.append(f"- `{identity}`")
    lines.append("")

    lines.append("## Inventory summary")
    lines.append("")
    lines.append(f"- Probe count: **{len(PROBES)}**")
    lines.append(f"- Probe match count: **{total_matches}**")
    lines.append(f"- Affected path count: **{len(AFFECTED_R_A_PATHS)}**")
    lines.append(f"- Allowed raw-projection leaves: **{len(raw_allowed)}**")
    lines.append(f"- Unexpected raw-projection leaves: **{len(raw_unexpected)}**")
    lines.append(f"- Allowed face-count leaves: **{len(face_allowed)}**")
    lines.append(f"- Unexpected face-count leaves: **{len(face_unexpected)}**")
    lines.append(f"- Allowed pipeline stitchIdentity assignments: **{len(stitch_allowed)}**")
    lines.append(f"- Unexpected pipeline stitchIdentity assignments: **{len(stitch_unexpected)}**")
    lines.append(f"- Stitch-kind classifier self-test cases: **{len(stitch_self_test_passed) + len(stitch_self_test_failed)}**")
    lines.append(f"- Stitch-kind classifier self-test failures: **{len(stitch_self_test_failed)}**")
    lines.append(f"- REV-30 structural convergence guard failures: **{len(rev30_failed)}**")
    lines.append(f"- REV-32 package-contract membership guard failures: **{len(rev32_failed)}**")
    lines.append(f"- REV-33 exhaustive chart-barrier site-set guard failures: **{len(rev33_failed)}**")
    lines.append(f"- REV-34 HardRail fixture/test-authority guard failures: **{len(rev34_failed)}**")
    lines.append(f"- REV-35 component-local remap/package-mandatory guard failures: **{len(rev35_failed)}**")
    lines.append(f"- Final static inventory: **{'PASS' if ok else 'FAIL'}**")
    lines.append("")
    lines.append(f"This {'PASS' if ok else 'FAIL'} is a static/compile-contract result only. R-A semantic acceptance requires the separately packaged artifact-only runtime turn on the fresh corrected compile package.")
    lines.append("")
    return "\n".join(lines), ok


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", default=".")
    parser.add_argument("--output", default="")
    args = parser.parse_args()
    root = Path(args.root).resolve()
    report, ok = render(root)
    if args.output:
        Path(args.output).write_text(report, encoding="utf-8")
    else:
        print(report, end="")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
