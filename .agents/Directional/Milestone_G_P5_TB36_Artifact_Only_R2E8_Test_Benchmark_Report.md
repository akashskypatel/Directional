# Milestone G P5-TB36 Artifact-Only R2E8 Test/Benchmark Report

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E8 is **not accepted** as the active R2 closure checkpoint.

R2E8 makes two real advances:

1. the planar fixture no longer fails the typed boundary-sector incidence gate before publication; it reaches the unchanged topology validators;
2. all six Phase 17 failures caused by invalid upstream arrangements are naturally restored, moving Phase 17 from **20/26** to **26/26**.

The two intended R2E8 topology closures remain incomplete:

- planar still has `topologyValid=false`, `boundaryCyclicWrapInteriorSectorCount=0`, and Euler characteristic `0` instead of `1`;
- the interior hard-rail fixture still has `embeddingValid=false` and therefore `topologyValid=false`.

Cylinder and bunny remain independent producers. Do not advance to R2F or R3.

This turn did not configure, build, relink, patch, regenerate, or modify source, tests, fixtures, validators, workflows, or build logic.

## Package authority

Validation used artifact `8944910920`, `surface-cell-p5-r2e8-github-source-linux-release`.

- archive SHA-256: `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`;
- exact compiled source: `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`;
- workflow event commit: `89423d0a49d7e1c2020cda87ee2333f35a3abe98`;
- `SurfaceArrangement.cpp` blob: `76e57fef36f9322598387b6b5e968a14b885b755`;
- recursive manifest: **13/13**;
- original package files: **14**, including the manifest;
- fixture files staged from the packaged source archive: **26**;
- recursive submodule records: **9**;
- packaged execution policy explicitly states compile-only production of the artifact.

The authority gate passed before any packaged executable ran. The source archive was staged only to satisfy executable-relative fixture lookup; no source file was compiled or modified.

## Focused results

| Scope | P5-TB36 | P5-TB35 comparison |
|---|---:|---|
| Source chart + source validator | **17/17** | preserved (`11/11` + `6/6`) |
| Recovery authority | **9/9** | preserved |
| Feature/barrier | **8/8** | preserved |
| Graph-dependent | **5/6** | bunny only; preserved |
| R2 focused | **13/16** | unchanged count |
| Milestone D | **5/7** | unchanged |
| Phase 16 | **45/47** | unchanged |
| Phase 17 | **26/26** | **+6 natural restorations** |
| Phase 18 | **57/57** | preserved |
| Phase 14–18 | **241/244** | **+6** |
| Phase 20 | **46/48** | unchanged |

### Naturally restored Phase 17 tests

The exact six P5-TB35 upstream-input failures now pass without any Phase 17 implementation change:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

This confirms that R2E8 improves the published arrangement sufficiently for those simplification inputs, even though the planar and hard-rail topology gates remain open.

## R2E8 producer diagnosis

### Planar canonical boundary sectors

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` now passes its incidence assertion and reaches the unchanged topology checks. It fails only on:

- `topologyValid == false`;
- `boundaryCyclicWrapInteriorSectorCount == 0`;
- Euler characteristic `0` instead of `1`.

Therefore R2E8 closes the prior pre-publication `BoundaryFanSectorCoverConflict`, but the published relation omits or misorients the required cyclic-wrap interior corner sector. The resulting successor inventory is locally publishable but globally closes the wrong cell topology.

Source inspection is consistent with the runtime evidence: direct sectors are currently emitted from consecutive rays in each chart-filtered angle list, and wrap authority is recognized only when the adjacent records happen to carry fan positions `last -> 0`. The next producer must enumerate the canonical cyclic R1 fan pairs themselves, then resolve each pair to its exact chart corner and remove the one independently proven exterior pair exactly once.

### Interior hard rail

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` continues to pass all assertions before embedding, including:

- valid incidence and no typed incidence failure;
- complete local successor bijection;
- predecessor multiplicity;
- no repeated node or edge cycles;
- directed wedge, boundary-sector, separator, and rail-side-pair evidence;
- one exterior and two bounded cells;
- disk, loop, Euler, ownership, and distinct bounded rail-twin ownership authority.

It still fails only:

- `embeddingValid == false`;
- aggregate `topologyValid == false`.

The accepted sector roots are sufficient to preserve topology and ownership, but they are not yet the authoritative chart selection used when the bounded cell embedding is assembled. The next producer must propagate the selected exact corner/chart root through the complete directed orbit and use that root to publish each bounded cell's authoritative source-chart support, while preserving full provenance separately.

### Independent cylinder and bunny producers

- `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` remains uncommitted.
- `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation` remains the only graph-dependent failure.

Neither is part of the next R2E9 scope.

## Direct analytic cases

All cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, no legacy execution, and no returned-input substitution.

| Case | Arrangement | Simplified | Quads | Result | Earliest failure | Peak working set |
|---|---:|---:|---:|---|---|---:|
| plane | 9 | 9 | 12 | fail | `completion/output-validation: AggregateCompletionValidationFailure` | 8,519,680 B |
| multi-face seam | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 8,454,144 B |
| close sheets | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 8,716,288 B |
| cylinder | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 9,920,512 B |

The cell inventories are unchanged from P5-TB35. No direct analytic production case closed.

## Bunny production evidence

Two independent processes executed `bunny_1k_random__surface_cells` with fallback `Fail` and source-grid recovery disabled.

| Run | Wall time | Peak working set | Arrangement | Quads | Result |
|---|---:|---:|---:|---:|---|
| 1 | 24.995377 s | 270,729,216 B | 0 | 0 | `NotProductionReady/completion` |
| 2 | 25.475514 s | 270,667,776 B | 0 | 0 | `NotProductionReady/completion` |

Both report `SideSubdivisionRepair:InvalidInputIncidence`. Every stage structural hash and object count matches between the two runs. The result is deterministic and fail-closed, but not production success.

## Complete suite

The complete packaged suite was executed exactly once.

- tests: **625**;
- passed: **603**;
- failures: **22**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **72.397 s**;
- measured wall time: **72.40 s**;
- maximum RSS: **281,112 KiB**;
- normal process termination: yes;
- exit status: `1`, from test failures.

The failure set is exactly P5-TB35's 28 failures minus the six restored Phase 17 tests. There are no new failures and no other closures.

P5-TB35's 206.053-second measurement lacked an attached wrapper/RSS result and was already treated as runner-sensitive. P5-TB36 records exact wall/RSS authority but does not claim a generalized performance improvement from this cross-run comparison.

## Decision

Proceed with **P5-R2E9 canonical boundary wrap-sector and bounded rail-orbit chart publication Code + Build**.

R2E9 must:

1. construct the complete cyclic adjacent-pair inventory directly from authoritative R1 fan order, including wrap;
2. resolve each pair to one exact source-chart corner and exclude the authoritative exterior pair once;
3. restore the planar interior-wrap sector and Euler-one disk topology without arbitrary selection;
4. propagate the selected hard-rail chart root over each bounded orbit and publish that root as authoritative cell embedding support;
5. preserve the six restored Phase 17 tests and every accepted R2E5/R2E6/R2E7/R2E8 contract;
6. leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, and downstream validators unchanged;
7. compile only the four approved targets and execute no project binary.

## Evidence

- machine-readable summary: `benchmark-results/p5-tb36-summary.json`;
- evidence archive: `directional-p5-tb36-8944910920-evidence.zip`;
- evidence archive SHA-256: `af3747b1238a01802a4fc158032451a505cbeb224c51601d888e390b6fd01096`;
- evidence archive entries: **118**;
- raw XML, logs, benchmark JSON, review images, manifest checks, source inspection excerpt, and machine context are included in the archive.

P5 remains open. PR #8 remains open, draft, and unmerged.
