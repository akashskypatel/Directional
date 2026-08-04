# Milestone G P5-R1D Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB25 artifact-only R1D validation

## Authority

Execute artifact `8906115786`, `surface-cell-p5-r1d-github-source-linux-release`, directly.

- exact compiled source: `a1fec970297739cfe23ade339b6a7b57071b7300`;
- workflow event commit: `6fc57831afc7f77e0cda9bd1f409aaaaece15bda`;
- applied source-diff SHA-256: `4488988dc877f1a0a001e27286b68f2752314bade361d59a11c1e7eae8a6cd89`;
- artifact SHA-256: `361c06696c56234666f8ce18d018415715851b03e2225b04bdbdfc624a0bdd66`;
- workflow-log artifact: `8906116758`;
- workflow-log SHA-256: `c8ceb09ca4ea9f72148125466a9958366b51a52f8e02c229aa71d1852b2d1ec2`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB25.

## 1. Package authority

Before executing either packaged binary, verify:

- archive SHA-256;
- exact source commit and ancestry;
- empty source status;
- recursive checksum manifest **40/40**;
- **42** packaged files;
- **26** fixture files;
- **9** recursive submodule records;
- all four packaged target hashes;
- source archive contains the cross-local-sheet adjacency rule and the four new focused tests.

Any authority mismatch terminates the turn before runtime execution.

## 2. Source-chart R1 contracts

Run all `SourceChartTransitionsR1.*` tests first. The packaged target should expose eleven tests.

Require:

- valid opposite-winding manifold adjacency remains accepted;
- equal-direction winding remains rejected;
- exact manifold adjacency crosses different local-sheet labels within one source component;
- exact source-edge and source-vertex rebinds preserve target local-sheet provenance;
- component mismatch blocks adjacency;
- hard rails block adjacency;
- nonmanifold edge incidence creates no transition;
- disconnected topology remains distinct;
- face-row permutation preserves canonical component identity and transition hashes;
- whole-mesh orientation reversal preserves valid transitions and hashes;
- reversing one incident face remains invalid.

Any failure remains an R1 blocker.

## 3. Source-authoritative validator and recovery regression

Run:

- all `SourceAuthoritativeMeshValidatorPhase22.*` contracts;
- the focused recovery-authority scope from P5-TB24.

Require:

- validator valid/invalid cases remain **6/6** with intended typed outcomes;
- recovery remains **9/9**;
- source-grid recovery remains opt-in and reports `SourceGridRecovery`;
- direct fallback `Fail` never executes legacy output;
- disconnected close sheets and proximity-based reconciliation remain sheet-safe.

The exact-adjacency correction does not authorize proximity capture across sheets and does not make recovery authoritative direct output.

## 4. Previously blocked graph-dependent contracts

Run the three P5-TB24 failures explicitly:

1. `PureQuadCompletionPhase18.CompletionAcceptsBoundaryVertexAndEdgeChartAliases`;
2. `SurfaceArrangementPhase16.AdjacentPerFaceChartsShareOneCanonicalCellOwnershipClass`;
3. `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation`.

Also run:

- `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets`;
- hard-rail source-vertex fan separation;
- disconnected-close-sheet ownership separation;
- curved multi-face stitched topology and Euler contracts.

Record whether each now receives a usable transition graph and identify the earliest subsequent producer for any remaining failure.

## 5. Phase 14–18 regression gate

Run the complete Phase 14–18 aggregate and Phase 16 independently.

Reference points:

- P5-TB22: **236/236** before R1 additions;
- P5-TB23: **233/242** with inverted orientation;
- P5-TB24: **240/243** after R1C, with three exact-adjacency failures;
- P5-TB25 includes four new R1D contracts.

Acceptance requires all intended R1 and pre-existing Phase 14–18 tests to pass. Report exact numerator and denominator.

## 6. Analytic direct production

Run independently with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

1. plane;
2. multi-face seam;
3. close sheets;
4. disconnected close sheets when an existing packaged direct-production entry is available.

Record:

- success and output origin;
- completed quad count;
- transition graph availability and hashes;
- source component and local-sheet evidence;
- validation failure count and earliest typed failure;
- fallback/recovery/legacy flags;
- wall time and peak working set.

R1D closes its specific defect when local-sheet inequality is no longer the causal rejection. A later R2 producer may remain; report it without masking it through recovery.

## 7. Phase 20 and pipeline regression

Run the complete Phase 20 scope, with specific attention to:

- `CylinderFixtureCompletesProductionOutput`;
- `ValidationRejectionCannotReportCompletedSurfaceCells`;
- output-origin semantics;
- fallback `Fail` behavior;
- source-grid recovery isolation;
- later-stage lineage tests preempted by completion.

Do not rewrite a later failure as R1 success or bypass completion to reach an injected stage.

## 8. Complete-suite termination

Run the complete packaged test suite once with a process watchdog used only as a safety mechanism.

Requirements:

- report total discovered tests;
- record pass/fail counts;
- record duration and maximum resident set;
- record the last test and marker if a timeout occurs;
- treat timeout as a termination failure;
- compare against P5-TB24 **590/613** in 75.260 seconds.

Do not run the full direct bunny benchmark matrix solely for R1D. The focused bunny fan/feature-rail tests and complete-suite GP26 coverage are sufficient for this R1 gate.

## 9. Runtime decision

Advance to R2 only when:

- all eleven source-chart R1 tests pass;
- Phase 22 validator and recovery authority remain clean;
- all three P5-TB24 graph-dependent failures close;
- feature-rail incident-sheet support passes;
- Phase 14–18 is clean;
- analytic cases are not blocked by local-sheet chart incompatibility;
- the complete suite still terminates.

When a later analytic producer remains after these conditions, document its earliest typed failure and prepare the focused R2 directed wedge/incidence plan. Otherwise remain on R1 and prepare the smallest causally necessary correction.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
