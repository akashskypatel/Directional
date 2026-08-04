# Milestone G P5-TB23 Artifact-Only R0/R1 Test and Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Turn type:** artifact-only runtime validation

## Disposition

P5-TB23 is complete. **R0 and R1 are not closed, and work must not advance to R2.**

The packaged checkpoint was executed directly. No configure, build, relink, patch, regeneration, or source modification occurred. Package authority passed, but the new source-chart producer contains an orientation-classification inversion that rejects correctly oriented manifold adjacency and accepts same-direction shared-edge winding. This earliest defect propagates into vertex-fan construction, arrangement ownership, completion aliases, recovery validation, direct analytic output, and full-suite termination.

## Package authority

- artifact: `8902050372`, `surface-cell-p5-r1-github-source-linux-release`;
- archive SHA-256: `5d1e5ca4fa8bc74e0a30615725c79a8b491830ab1f4407152cf79bfe56f8880f`;
- exact compiled source: `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- R0/R1 implementation commit: `ae0c09ed1290df75d1d2cc1d5af039fc1feb83a3`;
- workflow event commit: `233466e5b02c3762a3f2648518f5860a2a2fb014`;
- reviewed patch SHA-256: `a3898a847c6722a1f2d9b0de48e71ae71f08fcc0bc82b3d9396d8c842d9cad61`;
- compile-fix patch SHA-256: `92162aa709134c86a355253416dc614817fecabebaeb60c58555061958d12162`;
- source status empty;
- recursive checksum manifest **41/41** verified;
- package files **43**;
- fixture files **26**;
- recursive submodule records **9**;
- all four packaged target hashes verified.

The checksum manifest stores paths relative to its original `artifact/` staging directory. Verification stripped that fixed prefix after archive extraction; all file bytes matched.

## Focused R0/R1 contracts

### Combined focused scope

- **8/12 passed**.
- Failed:
  - `SourceChartTransitionsR1.SharedSourceEdgeRebindsWithCanonicalEndpointOrientation`;
  - `SourceChartTransitionsR1.SourceVertexFansRespectTwoHardRailBarriers`;
  - `SourceChartTransitionsR1.InconsistentSharedEdgeOrientationRejectsTransitionGraph`;
  - `SurfaceCellsPhase10.SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture`.

### Recovery authority scope

- **8/9 passed**.
- Default-off behavior, paired-boundary fail-closed behavior, recovery target projection, prescribed-field recovery construction, incomplete-field rejection, and component/sheet provenance passed.
- Explicit planar end-to-end recovery failed before output acceptance with four strict validation failures; no recovery output origin was returned.

R0 is therefore only partially demonstrated. Recovery is default-off and distinct in the data model, but the explicit recovery success contract is preempted by the broken R1 transition graph.

## Earliest R1 root cause

`SourceChartTransitionGraph::edge_orientation` computes each incident face's traversal along the canonical low-to-high source edge. A consistently oriented manifold pair traverses its shared edge in **opposite** directions.

The implementation currently returns the accepted value when the directions are equal and the rejected value when they are opposite. `build()` therefore behaves as follows:

```text
valid opposite traversal  -> graph rejected
invalid same traversal    -> graph accepted
```

The focused tests prove both sides of this inversion. Because `build()` clears the graph globally when it sees the supposedly invalid edge, downstream `resolve_entity`, `rebind`, and intrinsic vertex-fan operations become unavailable on otherwise valid source meshes.

## Phase 14–18 regression

- P5-TB22: **236/236**.
- P5-TB23: **233/242**.
- Failed:
  - `PureQuadCompletionPhase18.CompletionAcceptsBoundaryVertexAndEdgeChartAliases`;
  - `SurfaceArrangementPhase16.CurvedMultiFaceFixturePreservesStitchedTopologyAndEulerCharacteristic`;
  - `SurfaceArrangementPhase16.AdjacentPerFaceChartsShareOneCanonicalCellOwnershipClass`;
  - `SurfaceArrangementPhase16.UnlabelledTopologyDerivesCanonicalOwnershipRegistry`;
  - `SurfaceArrangementPhase16.OwnershipRegistryStoresClassMembershipOnceForRepeatedCells`;
  - `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation`;
  - the three failing `SourceChartTransitionsR1` tests listed above.

The completion alias failure is typed as:

```text
CompletionOwnershipComponentSheetMismatch;
sourcePatch=27;localVertex=10;storedFace=1;
entity=source-vertex;sourceVertex=0;
candidateFaces=0,1;patchFaces=0;component=0;sheet=0
```

This is consistent with the graph rejecting the valid adjacent source-face transition rather than evidence that the source vertex alias itself is invalid.

## Analytic direct production

All cases used backend `SurfaceCells`, fallback `Fail`, recovery disabled, and no legacy execution.

| Case | Result | Quads | Validation failures | Earliest failure | Wall time |
|---|---:|---:|---:|---|---:|
| Plane | failed | 12 | 27 | `LocalSheetMismatch` at cell/face 0/0 | 0.013220 s |
| Multi-face seam | failed | 24 | 46 | `LocalSheetMismatch` at cell/face 0/0 | 0.022410 s |
| Close sheets | failed | 34 | 61 | `LocalSheetMismatch` at cell/face 0/0 | 0.042241 s |

No case used recovery or fallback. Compared with P5-TB22, the same three cases still fail `LocalSheetMismatch`, but the first failure moved to cell/face `0/0` and validation-failure counts increased from 19/28/33 to **27/46/61**. R1 therefore regressed rather than closed the analytic gate.

The reduced disconnected-sheet identity contracts passed, but no packaged direct-production manifest case exists for disconnected close sheets.

## Phase 20

- P5-TB22: **46/48**.
- P5-TB23: **35/48**.
- Thirteen failures, including production output, recovery-backed fixture expectations, stage-lineage injection, component scheduling, and validation-stage ownership.

Most later-stage expectations are preempted by the earlier completion/source-chart failure. This is not a reason to bypass completion or change stage ordering.

## Full-suite termination

The complete packaged binary reports **606 tests**. The unfiltered run did not terminate within the **1200-second** watchdog. It stalled in:

```text
MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback
  bunny_1k_random__surface_cells
  last marker: [P5_P26_BEFORE_PIPELINE]
```

Before the stall, 192 tests completed: 179 passed and 13 failed. The timeout is a termination failure, not a pass.

A diagnostic bounded run excluded the three known production-matrix bunny entries and terminated normally:

- **553/603 passed**;
- **50 failures**;
- 4.943 seconds test time;
- 21,272 KiB maximum resident set.

The bounded result is not a full-suite pass. It shows that the orientation inversion broadly regressed arrangement, completion, validator, pipeline, and stage-lineage scopes even when the hanging bunny entries are excluded.

## Packaging gap

The P5-TB23 plan requested focused `SourceAuthoritativeMeshValidatorPhase22` contracts. The source file is compiled only into dedicated Milestone F validator executables, while the artifact packages only `directional_phase1_tests` and `directional_benchmarks`. Those requested tests were therefore unavailable without rebuilding, which this artifact-only turn correctly did not do.

The next compile turn should add `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` to the existing `directional_phase1_tests` source list so the exact four-target package exposes those contracts.

## Decision

Remain on R1. Do not begin directed-incidence reconstruction, completion-template expansion, repeated-node splicing, phase/front work, torus work, cache work, lineage work, or memory work.

The next turn is **P5-R1C code changes plus compile-only build**. Its only production behavior change should correct source-chart orientation and the immediate transition/fan integration consequences, while preserving all existing fail-closed and no-fallback constraints.
