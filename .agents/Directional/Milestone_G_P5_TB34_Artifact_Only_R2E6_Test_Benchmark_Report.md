# Milestone G P5-TB34 Artifact-Only R2E6 Test/Benchmark Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E6 closes the corrected genuine higher-valence four-disk boundary partition, but the checkpoint is not accepted as a complete remediation. The new higher-valence fan-sector cover regresses ordinary single-spoke boundary nodes and six Phase 17 contracts, while the interior hard-rail partition remains topology-invalid.

The next turn is **P5-R2E7 cyclic fan-sector cover and hard-rail side closure Code + Build**. Do not advance to R2F or R3.

This was an artifact-only Test + Benchmark turn. No configure, build, relink, patch, regeneration, fixture modification, source modification, test modification, or build-logic modification occurred.

## Package authority

Validation used artifact `8936470245`, `surface-cell-p5-r2e6-github-source-linux-release`.

- archive SHA-256: `bcc2c0d81e4382368a7fcafe7818c79a2e5bdb23d9a044232a4f3294f4554bf5`;
- exact compiled source: `2444c38b8216656b636f4dad9f8acfa70b86bd41`;
- workflow event commit: `6cd5a5c10aa0f15eb5e1312145425395b8a8372d`;
- reviewed/applied diff SHA-256: `e4196fd4ed1a68d31ba6310af8e8a4822533fac3c1f0248f75721521785f8d3d`;
- source status empty;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e6.yml`.

The authority gate passed before any packaged executable ran.

## Focused results

| Scope | Result | P5-TB33 comparison |
|---|---:|---|
| Source-chart R1 | **11/11** | preserved |
| Source validator | **6/6** | preserved |
| Recovery authority | **9/9** | preserved |
| Feature/barrier | **8/8** | preserved |
| Graph-dependent | **5/6** | bunny only; preserved |
| R2 focused | **13/16** | higher-valence closed; planar, hard rail, cylinder remain |
| Milestone D | **5/7** | unchanged |
| Phase 14–18 | **235/244** | six Phase 17 regressions, higher-valence closure |
| Phase 16 | **45/47** | higher-valence closed; planar and bunny fail |
| Phase 17 | **20/26** | six regressions |
| Phase 18 | **57/57** | preserved |
| Phase 20 | **46/48** | unchanged |

## Confirmed closure

`SurfaceArrangementPhase16.MultipleInteriorRaysAtBoundaryVertexUseAdjacentRotationalSectors` now passes its corrected genuine partition contract:

- one ordered exterior sector;
- audited higher-valence fan-sector node;
- at least four interior sectors;
- zero hard-rail separators;
- no repeated node or edge cycle;
- one exterior plus four bounded disk cells;
- complete halfedge ownership;
- topology validity.

The passing R2E5 degree-two contract also remains valid. Source-row and whole-orientation incidence-hash authority remain passing.

## Regressions and remaining producers

### 1. Ordinary single-spoke boundary fan regression

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` now fails incidence with `BoundaryFanSectorCoverConflict` before topology/Euler analysis. P5-TB33 reached topology and reported Euler 0; P5-R2E6 therefore moves this fixture backward.

The R2E6 producer treats the ordered fan-ray vector as linear and rejects every intrinsic sector whose target wraps from the first ray to the final ray. A source-interior sector can legitimately occupy that vector wrap. Sector classification must be cyclic and must exclude only the one independently proven exterior adjacency, not every wrap adjacency.

The same producer regression invalidates arrangement inputs used by six Phase 17 tests.

### 2. Interior hard rail remains topology-invalid

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` now passes incidence validity, canonical endpoint aliases, node-local successor bijection, predecessor cardinality, repeated node/edge checks, fan-sector diagnostics, and at least two hard-rail separators. It then fails only at `topologyValid`.

The cover is complete, but the current separator audit proves only that the two incident sector identities differ. It does not prove that each directed rail side is paired with the correct adjacent source fan in cyclic order. The resulting orbits can remain non-disk, boundary-owner invalid, or Euler-invalid despite a complete permutation.

### 3. Phase 17 regressions

Six tests that passed in P5-TB33 fail again because their arrangement inputs no longer produce the expected valid candidate complexes:

- `SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate`;
- `SurfaceComplexSimplificationPhase17.TransactionalMutationPreservesHardRailSupport`;
- `SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

No Phase 17 implementation changed. These are upstream arrangement regressions and must not be patched in Phase 17.

### 4. Cylinder and bunny

Cylinder remains uncommitted with invalid cell ownership and zero direct arrangement inventory. Bunny remains the separate intrinsic singularity-fan embedding producer. Neither is part of the immediate P5-R2E7 correction.

## Direct analytic cases

All direct cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Arrangement | Simplified | Quads | Result | Earliest reported failure | Peak RSS |
|---|---:|---:|---:|---|---|---:|
| plane | 9 | 9 | 12 | fail | `AggregateCompletionValidationFailure` | 10,572 KiB |
| multi-face seam | 0 | 0 | 0 | fail | `SideSubdivisionRepair:InvalidInputIncidence` | 10,308 KiB |
| close sheets | 0 | 0 | 0 | fail | `SideSubdivisionRepair:InvalidInputIncidence` | 10,636 KiB |
| cylinder | 0 | 0 | 0 | fail | `SideSubdivisionRepair:InvalidInputIncidence` | 11,908 KiB |

Direct inventories are unchanged from P5-TB33. No fallback, recovery, returned-input substitution, or legacy execution was used.

## Complete suite

The complete suite was started exactly once after focused and direct scopes. The outer execution wrapper detached, but the already-running packaged test process continued to normal XML and Google Test completion. It was not rerun.

- tests: **625**;
- passed: **597**;
- failures: **28**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **73.085 s**;
- normal test-process termination: yes;
- exact wrapper exit code: unavailable after detachment;
- exact maximum RSS: unavailable after detachment.

Relative to P5-TB33:

- one failure closed: the corrected higher-valence fan partition;
- six failures introduced: the six Phase 17 contracts listed above;
- net failure increase: **5**.

The complete failure set otherwise matches P5-TB33.

## Decision

P5-R2E6 is accepted only as proof that a genuine multi-spoke higher-valence partition can be assembled from authoritative fan sectors. It is rejected as the active R2 checkpoint because it regresses ordinary cyclic boundary sectors and Phase 17 inputs, and hard-rail topology remains invalid.

Proceed with **P5-R2E7 cyclic fan-sector cover and hard-rail side closure Code + Build**.

## Evidence

- machine summary: `benchmark-results/p5-tb34-summary.json`;
- raw evidence bundle: `directional-p5-tb34-8936470245-evidence.zip`;
- evidence SHA-256: `dc662e8d207585ceec9482f64fb859a6e64d38d39892af2f323a84b8d3c0e8c8`;
- archive entries: **180**.

Preserved prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
