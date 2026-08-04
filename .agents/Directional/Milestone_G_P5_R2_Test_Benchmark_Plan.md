# Milestone G P5-R2 Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB26 artifact-only R2 validation

## Authority

Execute artifact `8908691591`, `surface-cell-p5-r2-final-github-source-linux-release`, directly.

- exact compiled source: `306fab5d440199cb090e1aa343fadb6112663edc`;
- workflow event commit: `b332bb3119a133b957b2f573a5bd447d4ca62d4e`;
- reviewed R2 patch SHA-256: `e4da79427d33a5fd7bf29b707ec0765974faf0bc67c2dc18e6f2e6e6dd9a8658`;
- formatting-fix SHA-256: `d0696338ecdf5cf9af57b9dca3d56260192c8fe12cf0122a98c45e8b31734522`;
- artifact SHA-256: `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`;
- workflow-log artifact: `8908692488`;
- workflow-log SHA-256: `1f3cc3630d89f4aacf419d60ece84f9f5c8d5a4e8fa2e59cbb314c79421b97f6`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB26.

## 1. Package authority

Before executing either packaged binary, verify:

- archive SHA-256;
- exact source commit and branch ancestry;
- empty source status;
- recursive checksum manifest **41/41**;
- **43** packaged files;
- **26** fixture files;
- **9** recursive submodule records;
- all four packaged target hashes;
- source archive contains `SurfaceArrangementIncidenceFailure`, directed-incidence diagnostics, the R2 arrangement implementation, and the focused R2 contracts.

Any authority mismatch terminates the turn before runtime execution.

## 2. Preserve R1 authority

Run first:

- all `SourceChartTransitionsR1.*` tests;
- all `SourceAuthoritativeMeshValidatorPhase22.*` tests;
- focused recovery-authority scope;
- P5-TB25 graph-dependent and feature-rail/barrier scopes.

Reference acceptance:

- source-chart **11/11**;
- Phase 22 validator **6/6**;
- recovery **9/9**;
- graph-dependent **6/6**;
- feature-rail/barrier **8/8**.

R2 may consume R1 source topology but must not reintroduce raw local-sheet equality, proximity-based topology ownership, or recovery substitution.

## 3. Directed-incidence focused contracts

Run the new and strengthened R2 contracts explicitly:

1. `SurfaceArrangementPhase16.DirectedWedgeIncidenceFormsACompletePermutation`;
2. `SurfaceArrangementPhase16.AdjacentLocalSheetChartsShareDirectedIntrinsicWedges`;
3. `SurfaceArrangementPhase16.NonManifoldSourceEdgeFailsClosedWithTypedIncidenceEvidence`;
4. `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence`;
5. source-face row-order incidence-hash invariance;
6. hard-rail wedge separation and non-exterior classification;
7. disconnected close-sheet/component wedge separation;
8. rollback identity mutation when typed incidence evidence changes.

For every valid arrangement require:

- `incidenceValid == true`;
- `incidenceFailure == None`;
- successor missing count zero;
- successor ambiguity count zero;
- predecessor multiplicity failure count zero;
- repeated-node and repeated-edge cycle counts zero;
- every halfedge has a symmetric twin;
- every halfedge has exactly one successor and predecessor;
- every halfedge belongs to exactly one node-simple, edge-simple cycle;
- `directedIncidenceHash` is nonzero and deterministic.

For intentionally invalid nonmanifold or repeated-cycle scenarios require the intended typed producer failure. Do not accept a generic later topology or completion rejection as the R2 contract.

## 4. Milestone D closure gate

Run all `MilestoneDClosure.*` tests with specific attention to the two P5-TB25 failures:

1. `InteriorHardRailIsNotClassifiedAsExteriorBoundary`;
2. `CylindricalOpenStrandCommitsWithTopologyPreserved`.

Require:

- interior hard rails split wedges without becoming exterior source-boundary sectors;
- cylinder successor/predecessor incidence is valid before simplification and completion;
- no `non-disk-cell cell=0 halfedge=43 twin=42 next=29` recurrence;
- no post-hoc repeated-node splitting behavior;
- source-row, seam-start, and whole-orientation permutations preserve incidence and cell hashes.

Any remaining Milestone D failure keeps R2 open.

## 5. Phase 14–18 regression gate

Run:

- complete Phase 14–18 aggregate;
- Phase 16 independently;
- Phase 17 simplification independently;
- Phase 18 completion entry contracts receiving arrangement cells.

Reference P5-TB25:

- Phase 14–18 **247/247**;
- Phase 16 **39/39**.

R2 acceptance requires all pre-existing R1 contracts to remain clean and all new R2 tests to pass. Report exact numerator and denominator.

## 6. Analytic direct production

Run independently with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder diagnostic;
5. disconnected close sheets when a packaged direct entry exists.

Record:

- success and output origin;
- arrangement incidence validity and typed failure;
- wedge count and directed incidence hash;
- successor/predecessor/repeated-cycle counters;
- completed cell and quad counts;
- manifold, valence, rail, provenance, and sheet validation counts;
- earliest subsequent typed producer;
- fallback/recovery/legacy flags;
- wall time and peak working set.

Reference P5-TB25:

- plane: 12 quads, 15 validation failures;
- seam: 24 quads, 22 validation failures;
- close sheets: 34 quads, 27 validation failures;
- cylinder: pattern variant 51 bow-tie completion.

R2 closes only when arrangement incidence is valid before completion. Analytic production may remain open when evidence moves to a later typed R3 completion producer, but manifold/valence defects must not still originate from repeated or cross-wedge arrangement cycles.

## 7. Phase 20 and pipeline regression

Run complete `SurfaceCellPipelinePhase20.*`.

Reference P5-TB25: **46/48**.

Pay specific attention to:

- cylinder production output;
- validation-lineage preemption;
- output-origin semantics;
- fail-closed direct execution;
- no recovery or legacy substitution;
- propagation of typed arrangement incidence evidence.

Do not synthetically bypass an R2 or R3 failure to reach an injected later-stage lineage.

## 8. Complete-suite termination and performance

Run the complete packaged test suite once with a process watchdog used only as a safety mechanism.

Requirements:

- report discovered, passed, and failed counts;
- record normal termination or the exact last test on watchdog expiration;
- record duration and maximum resident set;
- report the duration of each bunny execution;
- compare against:
  - P5-TB24: **590/613**, 75.260 s, 256,544 KiB;
  - P5-TB25: **598/617**, 333.444 s, at least 582,904 KiB.

A timeout is a termination failure. Faster failure is not correctness. R2 runtime evidence must also reveal whether directed wedge construction improves, preserves, or worsens the current bunny time and memory regression.

Do not run the full standalone direct bunny benchmark matrix solely for R2 unless the focused and complete-suite evidence cannot identify the incidence producer.

## 9. Runtime decision

Advance to R3 only when:

- all R1 authority remains clean;
- all directed-incidence focused contracts pass;
- both Milestone D failures close;
- all valid arrangements have complete one-to-one halfedge permutations;
- no valid cell inventory contains repeated nodes or edges;
- cylinder arrangement incidence is valid before completion;
- analytic arrangement failures are eliminated or move to a later typed completion producer;
- Phase 14–18 remains clean;
- Phase 20 does not regress due to incidence;
- the complete suite terminates.

If R2 remains causal, prepare the smallest directed-incidence correction. If R2 closes and completion still fails, prepare the focused R3 topology-distinct completion plan using the exact new producer evidence.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.
