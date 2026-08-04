# Milestone G P5-TB18 Canonical Ownership, Output, and Memory Test/Benchmark Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** artifact-only test and benchmark

## Disposition

P5-TB18 is complete as an artifact-only runtime turn. P5 remains open.

The exact P5-CB107 package was extracted and executed without configuring,
compiling, relinking, patching, regenerating, or modifying source. The package
is internally valid, but runtime closure regressed severely:

- the two new canonical-chart regressions pass;
- one prior Phase 16 regression (`BunnySingularityFanUsesIntrinsicSourceVertexRotation`) is restored;
- Phase 14–18 remains open at **223/232**;
- Milestone D remains **4/7**;
- Milestone E remains **23/26**;
- Phase 20 remains **47/48**;
- the complete 596-test binary cannot finish because the random-bunny smooth path is killed after multi-gigabyte growth;
- the 593 tests excluding the three blocked heavy cases finish **573/593**, with 20 assertion failures;
- every direct production fixture still fails;
- face-edge bunny now gets past raw mixed-sheet parity, but fails at `InvalidArrangementDomainIdentity;firstPatch=2` after **98.613553 s** and **2,513,285,120 B** peak RSS;
- smooth bunny is terminated by SIGKILL after **65.60 s** with **3,801,161,728 B** maximum RSS and writes no result JSON;
- exact completion reuse remains zero;
- the invalid-midpoint fixture still stops at `MissingCommonSourceChart`;
- the 75% memory reconciliation gate is not reached.

No source or test was changed during runtime execution.

## Artifact integrity

- artifact ID: `8876934846`;
- name: `surface-cell-p5-cb107-github-source-linux-release`;
- archive SHA-256: `ba06737ab313f30e23c74f402114649ee2c9f9d7c3a7177c7e0ba3328749df47`;
- exact source: `94bf8347b10eebcd8d3e777c6f5f0a2227283a2e`;
- source status bytes: `0`;
- recursive checksums: **39/39**;
- fixture files: **26**;
- bunny: **502 vertices / 1000 triangle faces**.

## Test results

| Scope | Passed | Failed | Total | Time |
|---|---:|---:|---:|---:|
| Focused ownership/topology/reuse/midpoint contracts | 5 | 15 | 20 | 0.002 s |
| Phase 14–18 | 223 | 9 | 232 | 0.018 s |
| Milestone E | 23 | 3 | 26 | 0.005 s |
| Milestone D | 4 | 3 | 7 | 0.000 s |
| Milestone G P23 | 6 | 0 | 6 | 0.025 s |
| Phase 20 | 47 | 1 | 48 | 0.269 s |
| Complete binary excluding three blocked heavy cases | **573** | **20** | **593** | 4.010 s |

The full binary contains 596 tests. These three heavy cases were excluded from
the completed aggregate after direct attempts established the blocker:

1. `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` reaches the bunny case and does not complete.
2. `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` reports non-bunny assertion failures, reaches the bunny case, and does not complete within the execution cap.
3. `ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/7` is represented by the direct smooth-bunny run that is killed at 3.80 GB RSS.

Timeout or exclusion is not treated as correctness. The full-suite termination
gate fails.

### Passing new/targeted contracts

- adjacent face-local charts can share one canonical physical ownership class;
- disconnected close sheets retain distinct canonical classes;
- the bunny singularity fan intrinsic-rotation regression is restored;
- the authoritative-cell-scope subdivision regression passes;
- the separate missing-common-chart regression passes.

### Remaining topology regressions

Phase 16 still fails:

- `AuthoritativeTopologyDiagnosticsMatchSingleDiskSource`;
- `AuthoritativeTopologyDiagnosticsHandleDisconnectedSourceComponents`;
- `CurvedMultiFaceFixturePreservesStitchedTopologyAndEulerCharacteristic`.

All six Phase 17 regressions remain. All three Milestone D failures remain,
including the cylinder fixture failing incidence before candidate extraction.

### Reuse and midpoint

`WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` still fails with
`same-corner-distinct-boundary` route validation. `OneCandidateBudgetIsExactAndDoesNotRecurse`
records incremental recomputation `0`, reused completions `0`, and recomputed
completions `0`.

`FailedSubdivisionReturnsBitExactCommittedComplex` still expects
`InvalidMidpointEmbedding` but receives `MissingCommonSourceChart`.

## Production fixture matrix

All eight direct `SurfaceCells` cases used fallback `Fail` with source-grid
recovery disabled. No fallback or recovery was used.

| Case | Result | Completed quads | Earliest failure |
|---|---|---:|---|
| plane | fail | 12 | `optimization/output-validation:SelfIntersectingFace`, face 6 |
| cylinder | fail | 246 | `optimization/output-validation:SelfIntersectingFace`, face 107 |
| multi-face seam | fail | 24 | `optimization/output-validation:SelfIntersectingFace`, face 2 |
| close sheets | fail | 34 | `optimization/output-validation:SelfIntersectingFace`, face 6 |
| mechanical feature | fail | 0 | `completion:InvalidArrangementDomainIdentity;firstPatch=24` |
| prescribed sphere | fail | 0 | `completion:InvalidArrangementDomainIdentity;firstPatch=2` |
| torus | fail | 0 | `completion:IncompleteSurfaceCellComplex` |
| thin bent tube | fail | 0 | `completion:IncompleteSurfaceCellComplex` |

Plane, cylinder, seam, and close-sheets prove that patch completion can produce
nonempty quad buffers, but the optimizer/output path does not return a valid
mesh or roll back to a valid completed checkpoint.

## Random bunny

### Face-edge field

- completed normally with a failed pipeline result;
- wall: **98.613553 s**;
- peak working set: **2,513,285,120 B**;
- estimated simultaneous owned bytes: **636,377,024 B**;
- owned/RSS ratio: **25.32%**;
- failure: `NotProductionReady/completion:InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1`;
- trace segments: `12,130`;
- arrangement/simplified cells: `7,405 / 7,405`;
- odd cells: `1,860 -> 0`;
- parity split edges: `2,213`;
- side-repair inserted vertices: `8,137`;
- completed quads/output: `0 / None`;
- reuse/recompute: `0 / 0`;
- fallback/recovery: none.

The former `BoundaryParityRepair:MixedCellSourceScope` blocker is removed, but
it exposes an invalid prepared arrangement domain immediately afterward.

Established limits were 39.228299 s and 1,115,394,560 B. This run fails both.

### Smooth field

The first smooth run is terminated by SIGKILL before its 180-second timeout:

- elapsed: **65.60 s**;
- maximum RSS: **3,801,161,728 B**;
- exit code: `137`;
- result JSON: not written.

Because the process was killed well before the explicit timeout while using
3.80 GB RSS, the evidence is consistent with an external memory/resource kill.
No correctness or deterministic-result claim is made. Additional four-run
repetition was stopped after the first catastrophic resource failure.

## Root-cause findings

### 1. Missing default canonical ownership

The new arrangement ownership pass only receives valid chart records when
explicit source component/sheet labels or already-scoped arc records exist.
Legacy and topology-only calls with no labels leave the chart set empty,
`selectedRoot` becomes `-1`, and `embeddingValid` is cleared. This directly
explains the three remaining Phase 16 failures and cascades into simplification
and Milestone D.

The correction must derive default intrinsic source components and one local
chart per source face from source adjacency when explicit classifier labels are
absent. It must not bypass canonical ownership or restore frequency voting.

### 2. Quadratic ownership duplication

`ownershipIdentity(root)` serializes every chart member in an ownership class
into every cell using that class. On a connected bunny component, thousands of
cells therefore duplicate a component-sized chart vector. The patch-level
identity compaction currently interns oriented boundary, undirected boundary,
source support, and boundary-node identities, but not
`sourceOwnershipClass` or `sourceChartMap`.

This creates approximately `O(cell count × component face count)` retained
storage and multiplies it across parity rollback, prepared complexes,
descriptors, and completion caches. The face-edge telemetry reports a
320,039,788 B rollback owner; the smooth path grows to 3.80 GB and is killed.

Canonical ownership must be stored as a fixed-size deterministic class key with
one exact class-membership table per complex, while each cell retains only its
own exact incident chart map.

### 3. Missing typed prepared-domain evidence

A patch descriptor may return before constructing a domain audit. That leaves
an invalid domain identity with failure kind `None`, producing
`InvalidArrangementDomainIdentity;firstPatch=...` without the exact repeated
node, boundary, chart, or source support failure. The prepared-complex gate must
run the same ordered simple-boundary audit used by descriptor construction and
report a typed first invalid entity.

### 4. Invalid-midpoint fixture precondition

The malformed-midpoint fixture clears both endpoint occurrence lists on nodes
shared with earlier edges. It then adds only the bad edge/twin charts. An
earlier edge can therefore fail `MissingCommonSourceChart` before any tentative
midpoint is appended. Preserve all unrelated incident charts and replace only
the target chart coordinates.

### 5. Output rollback and route/reuse remain open

The same-corner route producer still rejects the positive repair path, so cache
lookup is never reached. Separately, four fixtures reach nonempty completed
quads but become self-intersecting in optimization/output validation without a
valid rollback result.

## Gate disposition

| Gate | Result |
|---|---|
| Package integrity | pass |
| New canonical-chart regressions | pass |
| Phase 14–18 closure | fail — 223/232 |
| Milestone D closure | fail — 4/7 |
| Full suite terminates | fail |
| Prior failures close | fail |
| Positive exact reuse | fail |
| Invalid midpoint after valid chart | fail |
| Canonical cylinder topology | fail |
| Valid nonempty production output | fail |
| No fallback/source-grid recovery | pass |
| Face-edge resource limits | fail |
| Smooth run completion | fail — SIGKILL |
| Four-run determinism | not evaluable |
| 75% memory reconciliation | fail |

## Required next turn

Proceed with **P5-CB108 through P5-CB116 code changes + compile-only build**.
Follow:

`.agents/Directional/Milestone_G_P5_Post_TB18_Ownership_Compaction_Topology_Output_Code_Build_Plan.md`

Do not execute tests or benchmarks in that code/build turn.
