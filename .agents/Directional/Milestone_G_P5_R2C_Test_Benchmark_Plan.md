# Milestone G P5-R2C Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB27 artifact-only R2C validation

## Authority

Execute artifact `8912374007`, `surface-cell-p5-r2c-github-source-linux-release`, directly.

- exact compiled source: `94b86c50c38a849a744f40b0a21c86ed19551769`;
- workflow event commit: `69e7486ad59bdec64e95bd1c6a5c3ac0289bf244`;
- reviewed source patch SHA-256: `7ed8df0b92da7719395a50fb8f4d93485e163345d7f11c82c5866bd7adabf79a`;
- applied commit-diff SHA-256: `ddb5a8ae90ac227afd3ce5f1deccecfb8f676314d0638e7b295c49a390fc0ec3`;
- artifact SHA-256: `ffe30c89655b60f5f7e90e509388c44b5a6c2c830508648348a4d01189ebb689`;
- workflow-log artifact: `8912374385`;
- workflow-log SHA-256: `e1f4ccd6d218b6505f6e97d04eef9533d71adb987cbca7ad4daf1f7357a66d6f`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB27.

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
- source archive contains `cutCellDisk`, `bridgeExcursion`, `supportOnlyCycle`, the bridge/core audit, transactional cell assignment, and the focused R2C contracts.

Any authority mismatch terminates the turn before runtime execution.

## 2. Preserve R1 authority

Run first:

- all `SourceChartTransitionsR1.*` tests;
- all `SourceAuthoritativeMeshValidatorPhase22.*` tests;
- focused recovery-authority scope;
- feature-rail/barrier authority scope;
- P5-TB25 graph-dependent scope.

Reference acceptance:

- source-chart **11/11**;
- Phase 22 validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **6/6**.

R2C may consume R1 source topology but must not reintroduce raw local-sheet equality, proximity-based topology ownership, or recovery substitution.

## 3. R2 and R2C focused contracts

Run all directed-incidence and cell-inventory contracts, including:

1. `SurfaceArrangementPhase16.DirectedWedgeIncidenceFormsACompletePermutation`;
2. `SurfaceArrangementPhase16.AdjacentLocalSheetChartsShareDirectedIntrinsicWedges`;
3. `SurfaceArrangementPhase16.NonManifoldSourceEdgeFailsClosedWithTypedIncidenceEvidence`;
4. `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence`;
5. source-face row-order incidence-hash invariance;
6. disconnected close-sheet/component wedge separation;
7. hard-rail wedge separation and authoritative boundary classification;
8. `SurfaceArrangementPhase16.DanglingBridgeRetainsCompleteCellOwnershipWithoutCycleDecomposition`;
9. `SurfaceArrangementPhase16.IsolatedSupportBridgeReceivesTransactionalCellOwnership`;
10. rollback identity mutation when directed-incidence or R2C structural evidence changes.

For every valid arrangement require:

- `incidenceValid == true`;
- `incidenceFailure == None`;
- successor missing and ambiguity counts zero;
- predecessor multiplicity failures zero;
- every halfedge has a symmetric twin;
- every halfedge belongs to exactly one audited orbit;
- every halfedge has one bounded cell ID;
- no halfedge retains `cell == -1`;
- the published cell inventory covers all halfedges exactly once;
- `directedIncidenceHash` is nonzero and deterministic.

Structural classifications must satisfy:

- a simple area-bearing cycle is neither cut, bridge-excursion, nor support-only;
- a valid cut disk is `cutCellDisk && disk` and is not decomposed;
- a dangling support excursion is `bridgeExcursion && !disk` and remains represented;
- a support-only authoritative twin orbit is `supportOnlyCycle`, has exactly two twin halfedges, and is excluded from area/Euler totals;
- a genuine repeated nonbridge node/edge, theta graph, malformed bridge multiplicity, ambiguous successor, duplicate predecessor, or incomplete permutation fails with the intended typed producer evidence.

Do not accept a generic later simplification or completion rejection as proof of an R2C contract.

## 4. Milestone D closure gate

Run all `MilestoneDClosure.*` tests.

Require **7/7**, with specific attention to:

1. `InteriorHardRailIsNotClassifiedAsExteriorBoundary`;
2. `BranchedStrandIsTopologyChangingRegionCandidate`;
3. `CylindricalOpenStrandCommitsWithTopologyPreserved`.

Acceptance requires:

- interior hard rail partitions support without increasing authoritative exterior-cycle count;
- branched topology remains represented and retains singularity-touch/candidate evidence;
- cylinder has complete successor/predecessor/cell ownership before simplification and completion;
- no `invalid-cell cell=-1` evidence;
- no support-only cylinder orbit;
- no post-hoc repeated-node decomposition;
- row, seam-start, and orientation permutations preserve incidence and cell hashes.

Any remaining Milestone D failure keeps R2 open.

## 5. Phase 14–18 regression gate

Run:

- complete Phase 14–18 aggregate;
- Phase 16 independently;
- Phase 17 simplification independently;
- Phase 18 independently.

References:

- P5-TB25: Phase 14–18 **247/247**, Phase 16 **39/39**;
- P5-TB26: Phase 14–18 **227/240**, Phase 16 **39/43**, Phase 17 **18/26**, Phase 18 **57/57**.

P5-TB27 acceptance requires:

- all pre-R2 R1 contracts remain clean;
- all new R2/R2C tests pass;
- Phase 16 valid cell-inventory scenarios are restored;
- all eight P5-TB26 Phase 17 regressions close;
- Phase 18 remains clean.

Report exact numerator and denominator for each scope.

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
- wedge/orbit/cell counts and directed-incidence hash;
- counts of simple, cut-disk, bridge-excursion, and support-only cells;
- successor/predecessor/repeated-cycle counters;
- count of unassigned halfedges;
- completed cell and quad counts;
- manifold, valence, rail, provenance, and sheet validation counts;
- earliest subsequent typed producer;
- fallback/recovery/legacy flags;
- wall time and peak working set.

Reference P5-TB26:

- plane: 9 arrangement cells, 12 quads, 15 validation failures;
- seam: 0 cells/quads, invalid input incidence;
- close sheets: 0 cells/quads, invalid input incidence;
- cylinder: 0 cells/quads, invalid input incidence.

R2C closes its defect only when seam, close sheets, and cylinder retain nonzero valid arrangement inventories and no valid halfedge remains unassigned. Analytic production may remain open only when the earliest failure moves to a later typed completion producer without arrangement manifold/ownership defects.

## 7. Phase 20 and pipeline regression

Run complete `SurfaceCellPipelinePhase20.*`.

Reference P5-TB26: **46/48**.

Pay specific attention to:

- cylinder production output;
- validation-lineage preemption;
- output-origin semantics;
- fail-closed direct execution;
- no recovery or legacy substitution;
- propagation of typed arrangement incidence evidence;
- no support-only cell entering completion as an area-bearing domain.

Do not synthetically bypass an R2C or later completion failure to reach injected lineage.

## 8. Complete-suite termination and performance

Run the complete packaged test suite once with a watchdog used only as a safety mechanism.

Requirements:

- report discovered, passed, and failed counts;
- record normal termination or exact last test on watchdog expiration;
- record duration and maximum resident set;
- record duration of each bunny execution;
- compare against:
  - P5-TB24: **590/613**, 75.260 s, 256,544 KiB;
  - P5-TB25: **598/617**, 333.444 s, at least 582,904 KiB;
  - P5-TB26: **588/621**, 74.763 s, exact maximum RSS unavailable.

A timeout is a termination failure. Faster rejection is not correctness. Bunny timing and memory count as progress only after the valid cycle/cell inventory gates pass.

Do not run the full standalone direct bunny benchmark matrix solely for R2C unless focused and complete-suite evidence cannot identify the producer.

## 9. Runtime decision

Advance to R3 only when:

- all R1 authority remains clean;
- all directed-incidence and R2C inventory contracts pass;
- every valid halfedge has one successor, predecessor, audited orbit, and cell ID;
- no valid cell inventory contains an untyped malformed graph;
- all Milestone D tests pass;
- Phase 16 and Phase 17 return to a clean baseline plus new tests;
- Phase 14–18 is clean;
- seam, close sheets, and cylinder have nonzero valid arrangement inventories;
- analytic arrangement failures disappear or move to a later typed completion producer;
- Phase 20 does not regress due to incidence;
- the complete suite terminates.

If R2C remains causal, prepare the smallest boundary/orbit/cell correction. If R2 closes and completion remains causal, prepare the focused R3 topology-distinct completion plan using exact runtime evidence.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition;
- no timeout-as-correctness.
