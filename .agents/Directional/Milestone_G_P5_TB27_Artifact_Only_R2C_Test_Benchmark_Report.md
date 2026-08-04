# Milestone G P5-TB27 Artifact-Only R2C Test/Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB27 is complete against artifact `8912374007` and exact compiled source `94b86c50c38a849a744f40b0a21c86ed19551769`.

The R2C bridge/core audit is integrated and its two new bridge-ownership contracts pass. It also restores the Milestone D branched-strand contract and two Phase 17 contracts. However, R2 remains open: authoritative source topology, boundary/exterior classification, non-disk topology, singularity-fan embedding, and periodic/open-strand cell publication are not simultaneously correct. Multi-face seam, close sheets, and cylinder still publish zero arrangement cells and fail at `SideSubdivisionRepair:InvalidInputIncidence`.

Do **not** advance to R3. The next turn is **P5-R2D authoritative orbit publication and structural cell classification plus compile-only build**.

## Package authority

- artifact: `8912374007`, `surface-cell-p5-r2c-github-source-linux-release`;
- archive SHA-256: `ffe30c89655b60f5f7e90e509388c44b5a6c2c830508648348a4d01189ebb689`;
- exact compiled source: `94b86c50c38a849a744f40b0a21c86ed19551769`;
- workflow event commit: `69e7486ad59bdec64e95bd1c6a5c3ac0289bf244`;
- reviewed source patch SHA-256: `7ed8df0b92da7719395a50fb8f4d93485e163345d7f11c82c5866bd7adabf79a`;
- applied commit-diff SHA-256: `ddb5a8ae90ac227afd3ce5f1deccecfb8f676314d0638e7b295c49a390fc0ec3`;
- workflow-log artifact: `8912374385`;
- workflow-log SHA-256: `e1f4ccd6d218b6505f6e97d04eef9533d71adb987cbca7ad4daf1f7357a66d6f`;
- source status empty;
- recursive checksums **41/41**;
- package files **43**;
- fixtures **26**;
- recursive submodule records **9**;
- all four packaged target hashes verified;
- source archive contains `cutCellDisk`, `bridgeExcursion`, `supportOnlyCycle`, Tarjan bridge/core audit, transactional cell publication, and the two focused R2C bridge contracts.

The compiled source is an ancestor of the documentation-only handoff head. No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB27.

## Focused runtime results

| Scope | P5-TB26 | P5-TB27 | Result |
|---|---:|---:|---|
| Source-chart R1 | 11/11 | **11/11** | clean |
| Phase 22 source validator | 6/6 | **6/6** | clean |
| Recovery authority | 9/9 | **9/9** | clean |
| Feature-rail/barrier authority | 8/8 | **8/8** | clean |
| P5-TB25 graph-dependent scope | 5/6 | **5/6** | unchanged failure |
| Expanded R2/R2C focused scope | — | **7/10** | open |
| Milestone D | 4/7 | **5/7** | one contract restored |
| Phase 14–18 aggregate | 227/240 | **231/242** | 11 failures remain |
| Phase 16 | 39/43 | **41/45** | two new contracts pass; four failures remain |
| Phase 17 | 18/26 | **20/26** | two contracts restored |
| Phase 18 | 57/57 | **57/57** | clean |
| Phase 20 | 46/48 | **46/48** | unchanged failures |

### R1 and authority gates

Source-chart transitions, source-authoritative validation, recovery authority, and feature/barrier authority remain clean. No fallback, recovery, legacy output, input-mesh substitution, or validator weakening was used.

### R2C improvements

The new contracts pass:

- `DanglingBridgeRetainsCompleteCellOwnershipWithoutCycleDecomposition`;
- `IsolatedSupportBridgeReceivesTransactionalCellOwnership`.

`MilestoneDClosure.BranchedStrandIsTopologyChangingRegionCandidate` also returns to passing. Two Phase 17 contracts that failed in P5-TB26 now pass:

- `OptionalLayoutBridgeHealsPinchedCellTransactionally`;
- `RequiredSingularityBridgeIsProtectedAndRollsBackExactly`.

### Remaining R2/R2C failures

1. `EulerBoundaryAndAreaChecksPassOnPlanarFixture` — arrangement Euler characteristic is `-1`, expected `1`.
2. `NestedCyclesAreClassifiedAsNonDiskInsteadOfDefaultDisk` — no bounded two-boundary-component, Euler-zero `NonDisk` cell is published.
3. `NonManifoldSourceEdgeFailsClosedWithTypedIncidenceEvidence` — `incidenceValid` is incorrectly true for a three-face nonmanifold source edge.
4. `BunnySingularityFanUsesIntrinsicSourceVertexRotation` — arrangement embedding is invalid.
5. `InteriorHardRailIsNotClassifiedAsExteriorBoundary` — incidence passes but final topology is invalid.
6. `CylindricalOpenStrandCommitsWithTopologyPreserved` — incidence audit passes but final topology is invalid.

The graph-dependent scope remains **5/6** because the bunny singularity-fan contract still fails.

### Phase 15 and Phase 17 regressions

`FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation` remains failed because the retained continuation points directly to its twin.

Six Phase 17 contracts remain failed because expected candidates are absent or no transactional mutation commits:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

Phase 18 remains **57/57**, so R3 completion is still downstream of the open arrangement and simplification input defects.

## Direct analytic evidence

All direct cases used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Result | Arrangement cells | Completed quads | Earliest reported failure | Wall | Peak working set |
|---|---:|---:|---:|---|---:|---:|
| plane | failed | 9 | 12 | `completion/output-validation: AggregateCompletionValidationFailure` | 0.028084 s | 8,216,576 B |
| multi-face seam | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.028413 s | 8,089,600 B |
| close sheets | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.042557 s | 8,327,168 B |
| cylinder | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.297505 s | 10,108,928 B |

Plane retains 9 cells, 12 quads, and 15 aggregate completion-validation failures. Seam, close sheets, and cylinder retain the P5-TB26 causal outcome of zero arrangement cells and invalid input incidence. The packaged manifest has no independent disconnected-close-sheet direct case; its source-transition and ownership behavior was covered by focused tests.

The benchmark JSON exposes arrangement and completed-quad counts but does not serialize the new R2C per-orbit classifications, bridge/core counts, unassigned-halfedge count, or directed-incidence hash. Those values are therefore not claimed for direct cases.

## Phase 20 and complete suite

Phase 20 remains **46/48**. The failures are:

- `CylinderFixtureCompletesProductionOutput`;
- `ValidationRejectionCannotReportCompletedSurfaceCells` — the actual terminal stage is `completion`, not `validation`, because the producer fails before the injected validation scenario.

Complete suite:

- **623 tests discovered**;
- **593 passed**;
- **30 failed**;
- completed normally in **161.786 seconds**;
- no watchdog expiration;
- exact maximum RSS unavailable because the outer timing helper detached before writing its final statistics; XML and complete logs finalized normally.

Comparison:

| Checkpoint | Passed/total | Failures | Duration | Memory |
|---|---:|---:|---:|---:|
| P5-TB24 | 590/613 | 23 | 75.260 s | 256,544 KiB |
| P5-TB25 | 598/617 | 19 | 333.444 s | at least 582,904 KiB |
| P5-TB26 | 588/621 | 33 | 74.763 s | unavailable |
| P5-TB27 | **593/623** | **30** | **161.786 s** | unavailable |

P5-TB27 adds two passing R2C tests and reduces the failure count by three, but total duration regresses **116.40%** versus P5-TB26. The three dominant production-matrix/bunny executions are:

- GP26 production matrix: **54.052 s**;
- GP27 production matrix: **51.459 s**;
- parameterized bunny case `/7`: **49.185 s**.

This is roughly twice the P5-TB26 23–24 second early-failure duration and is not accepted as performance progress. No standalone bunny matrix was run because focused and complete-suite evidence already identified the producer.

## Failure classification

- **Production implementation:** all 30 suite failures. The integration and later-stage lineage failures are preempted by the real completion/arrangement failure; no assertion or fixture was changed.
- **Infrastructure evidence limitation:** exact complete-suite maximum RSS is unavailable due the detached outer timing helper. This does not affect XML counts, test failure evidence, direct benchmark memory, or normal suite termination.
- **Structurally invalid fixture:** none identified in P5-TB27.
- **Incorrect expectation:** none established in P5-TB27.
- **Nondeterminism:** none observed in the executed scopes.

## Earliest remaining producer

R2C correctly recognizes two classes of bridge-bearing successor orbits, but the publication model still conflates three separate decisions:

1. whether source topology is admissible;
2. whether a complete successor orbit is structurally valid;
3. what bounded-cell topology and exterior role that orbit represents.

Runtime evidence shows the consequences:

- a nonmanifold source edge can reach `incidenceValid == true`;
- planar Euler accounting is wrong;
- nested bounded cycles are not represented as a two-boundary non-disk cell;
- an interior hard rail and an open cylinder pass narrow incidence checks but fail final topology;
- the bunny singularity fan remains embedding-invalid;
- seam, close sheets, and cylinder publish no arrangement cells for completion.

The next correction must preserve the new bridge contracts while making source-topology rejection, orbit structural audit, bounded-cell topology, exterior classification, and transactional cell assignment independently authoritative.

## Decision

- R0 recovery authority: **closed**;
- R1 source transitions and validator authority: **closed**;
- R2C bridge/core narrow contracts: **passing**;
- R2 authoritative orbit/cell topology: **open**;
- Milestone D closure: **open**;
- direct production: **open**;
- advance to R3: **no**;
- next turn: **P5-R2D authoritative orbit publication and structural cell classification plus compile-only build**.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.
