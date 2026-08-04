# Milestone G P5-TB26 Artifact-Only R2 Test/Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB26 is complete against artifact `8908691591` and exact source `306fab5d440199cb090e1aa343fadb6112663edc`.

The packaged R2 implementation compiles and its new narrow contracts mostly pass, but the authoritative runtime gate does **not** close R2. Valid boundary, disconnected-component, singularity-fan, hard-rail, and periodic-cylinder arrangements are omitted from the audited cycle inventory, leaving halfedges without cell ownership and causing broad Phase 16/17 regressions.

Do **not** advance to R3. The next turn is **P5-R2C directed boundary-sector and cycle-inventory correction plus compile-only build**.

## Package authority

- artifact: `8908691591`, `surface-cell-p5-r2-final-github-source-linux-release`;
- archive SHA-256: `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`;
- exact compiled source: `306fab5d440199cb090e1aa343fadb6112663edc`;
- workflow event commit: `b332bb3119a133b957b2f573a5bd447d4ca62d4e`;
- reviewed R2 patch SHA-256: `e4da79427d33a5fd7bf29b707ec0765974faf0bc67c2dc18e6f2e6e6dd9a8658`;
- formatting-fix SHA-256: `d0696338ecdf5cf9af57b9dca3d56260192c8fe12cf0122a98c45e8b31734522`;
- source status empty;
- recursive checksums **41/41**;
- package files **43**;
- fixtures **26**;
- recursive submodules **9**;
- all four packaged target hashes verified;
- source archive contains typed incidence failures, `directedIncidenceHash`, directed-wedge construction, global permutation audit, and focused R2 contracts.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB26.

## Focused runtime results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Phase 22 source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature-rail/barrier authority | **8/8** |
| P5-TB25 graph-dependent scope | **5/6** |
| R2 focused contracts | **6/7** |
| Milestone D | **4/7** |
| Phase 14–18 aggregate | **227/240** |
| Phase 16 | **39/43** |
| Phase 17 | **18/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |

R1 source transitions, source validation, recovery authority, and feature-rail barriers remain clean. However, the arrangement-dependent bunny singularity-fan contract regresses, so the complete R1-dependent arrangement behavior is not preserved.

### R2 focused failure

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` still fails because the arrangement reports two exterior cycles instead of one. The new directed-wedge contracts for complete permutation, adjacent local sheets, nonmanifold rejection, disconnected close sheets, ownership invariance, and whole-orientation invariance pass on their narrow fixtures.

### Milestone D failures

1. `InteriorHardRailIsNotClassifiedAsExteriorBoundary` — interior hard rail creates a second exterior classification.
2. `BranchedStrandIsTopologyChangingRegionCandidate` — the resulting candidate does not retain singularity-touch evidence.
3. `CylindricalOpenStrandCommitsWithTopologyPreserved` — incidence validation fails with:

```text
invalid-cell cell=-1 halfedge=0 twin=1 next=4 node=-1 expected=-1 actual=-1
```

This is not the prior `non-disk-cell` failure. R2 now rejects or omits a valid periodic cycle before assigning a cell, leaving authoritative halfedges with `cell == -1`.

### Phase 16 failures

- `DisconnectedComponentsExtractMultipleCells` — interior cell count is zero.
- `NonDiskAndPatchCandidateClassificationIsExposed` — no intended non-exterior candidate/non-disk cell is emitted.
- `EulerBoundaryAndAreaChecksPassOnPlanarFixture` — arrangement Euler is `-1`, relative area error is `1`, and no boundary cycle exists.
- `BunnySingularityFanUsesIntrinsicSourceVertexRotation` — embedding/topology are invalid and zero center cells are produced instead of three.

### Phase 17 failures

Eight simplification contracts fail because valid arrangement cells/candidates are absent or invalid before simplification:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `OptionalLayoutBridgeHealsPinchedCellTransactionally`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`;
- `RequiredSingularityBridgeIsProtectedAndRollsBackExactly`.

Phase 18 remains **57/57**, so the earliest new regression is arrangement cycle inventory and its immediate simplification inputs, not the topology-distinct completion engine.

## Direct analytic evidence

All direct cases used `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy output.

| Case | Result | Arrangement cells | Completed quads | Earliest reported failure | Wall | Peak working set |
|---|---:|---:|---:|---|---:|---:|
| plane | failed | 9 | 12 | `completion/output-validation: AggregateCompletionValidationFailure` | 0.013276 s | 8,519,680 B |
| multi-face seam | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.013581 s | 8,384,512 B |
| close sheets | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.021626 s | 8,572,928 B |
| cylinder | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.134687 s | 9,908,224 B |

Plane retains the P5-TB25 result of 12 completed quads and 15 aggregate validation failures. Multi-face seam and close sheets regress from 24/34 completed quads with later validation failures to zero cells and zero quads. Cylinder regresses from a later pattern-variant bow-tie failure to zero cells and invalid input incidence.

No case used fallback, source-grid recovery, legacy output, or returned input-mesh substitution. Faster early failure is not correctness progress.

## Complete-suite result

- **621 tests discovered**;
- **588 passed**;
- **33 failed**;
- completed normally in **74.763 seconds**;
- no watchdog expiration;
- exact maximum RSS unavailable because the outer timing shell detached before emitting its final statistics, although the packaged test process completed and finalized XML/log output.

Comparison:

| Checkpoint | Passed/total | Failures | Duration | Memory |
|---|---:|---:|---:|---:|
| P5-TB24 | 590/613 | 23 | 75.260 s | 256,544 KiB |
| P5-TB25 | 598/617 | 19 | 333.444 s | at least 582,904 KiB |
| P5-TB26 | 588/621 | 33 | 74.763 s | unavailable |

The three dominant bunny executions improve to approximately 23–24 seconds:

- GP26 production matrix: **24.435 s**;
- GP27 production matrix: **23.575 s**;
- parameterized bunny case `/7`: **23.249 s**.

This recovers P5-TB24-like total duration, but correctness regresses from 19 to 33 failures. The speedup is therefore not accepted as a production improvement.

## Earliest remaining R2 producer

The R2 implementation correctly removes post-hoc repeated-node decomposition and audits node-simple/edge-simple cycles, but it only assigns cell IDs from `auditedCycles`. Runtime evidence shows valid source-boundary, hard-rail, disconnected-component, singularity-fan, and periodic sectors are being rejected or omitted before this inventory is finalized.

The causal symptoms are:

- valid halfedges retain `cell == -1`;
- planar boundary and area inventory disappears;
- disconnected interiors disappear;
- interior hard rails are classified as separate exterior cycles;
- valid singularity sectors produce zero center cells;
- seam, close-sheet, and cylinder completion receive zero arrangement cells.

The next correction must preserve fail-closed rejection for genuinely nonmanifold, repeated-node, repeated-edge, ambiguous, or incomplete permutations while restoring valid boundary-sector closure and complete cell ownership.

## Decision

- R0 recovery authority: **closed**;
- R1 source transitions and validator authority: **closed**;
- R2 directed-wedge narrow contracts: **partially passing**;
- R2 valid cycle inventory: **open**;
- Milestone D closure: **open**;
- direct production: **open**;
- advance to R3: **no**;
- next turn: **P5-R2C directed boundary-sector/cycle-inventory correction plus compile-only build**.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.
