# Milestone G P5-TB29 Artifact-Only R2E Test/Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB29 is complete against artifact `8914900872` and exact compiled source `de0aa1a58a5861954dc9e14e731e681b5e5feb87`.

R2E does **not** close an additional runtime contract. The complete suite remains **595/623** with the same 28 failures as P5-TB28. The stricter source-loop cardinality check changes the hard-rail failure into typed `BoundaryLoopOwnerCount` evidence, but planar exterior publication, hard-rail exterior continuation, cylinder publication, global topology, and bunny singularity-fan embedding remain invalid.

Do **not** advance to R3 or to the previously reserved intrinsic-fan R2F turn. The next turn is **P5-R2E2 authoritative boundary-exterior successor construction and compile-only build**.

## Package authority

- artifact: `8914900872`, `surface-cell-p5-r2e-corrected-github-source-linux-release`;
- archive SHA-256: `418518d879ec8686296ed3dd30d24e3b9e3b9df4280278996292fa1eba4d1d1c`;
- exact compiled/package source: `de0aa1a58a5861954dc9e14e731e681b5e5feb87`;
- implementation commit: `f5afd014cced8205d485bea4f1470725e1fd8be1`;
- workflow event commit: `2a40add65b13137d4d7183e0715c6807dbd6a10a`;
- reviewed patch SHA-256: `3ca1d3b940989e1fbda9e0f8f4b0b8c5971643575550ff9e34501e219651d628`;
- applied implementation diff SHA-256: `abf671a365ab97ba3075962528bcf76b71901f6dc06a7d0b877499561c89814e`;
- workflow-log artifact: `8914901042`, SHA-256 `351462cc5e3c72440fd2933bb31e3c2c63ee8560b61af20b9de8361a6713e0a3`;
- source status empty;
- recursive checksums **45/45**;
- package files **46**;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- source archive contains only `.github/workflows/agent-source-snapshot.yml` and zero temporary patch payloads.

The checksum file records paths relative to the workflow package directory (`artifact/...`), while GitHub's artifact upload removes that directory level. Verification recreated the original package root and passed all **45/45** entries. No file content was altered.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB29.

## Focused runtime results

| Scope | P5-TB28 | P5-TB29 | Result |
|---|---:|---:|---|
| Source-chart R1 | 11/11 | **11/11** | preserved |
| Phase 22 validator | 6/6 | **6/6** | preserved |
| Recovery authority | 9/9 | **9/9** | preserved |
| Feature/barrier authority | 8/8 | **8/8** | preserved |
| Graph-dependent | 5/6 | **5/6** | unchanged |
| R2/R2C/R2D/R2E focused | 11/14 | **11/14** | unchanged |
| Milestone D | 5/7 | **5/7** | unchanged |
| Phase 14–18 | 233/242 | **233/242** | unchanged |
| Phase 16 | 43/45 | **43/45** | unchanged |
| Phase 17 | 20/26 | **20/26** | unchanged |
| Phase 18 | 57/57 | **57/57** | preserved |
| Phase 20 | 46/48 | **46/48** | unchanged |

No previously passing test regressed and no previously failing test closed.

## R2E-focused failure evidence

### Planar exterior publication remains absent

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` still reports:

- arrangement Euler `-1` instead of `1`;
- relative area error `1` instead of at most `1e-8`;
- no exterior cell.

The strengthened exact-side fields therefore do not create the missing exterior successor orbit or bounded area inventory.

### Hard rail now fails earlier and more precisely

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` now fails with:

- `incidenceValid == false`;
- typed incidence failure `BoundaryLoopOwnerCount`.

This is a fail-closed improvement over publishing two exterior cells, but it does not satisfy the intended contract. The raw successor-orbit inventory still presents zero or multiple exterior-side records for one authoritative source boundary loop.

### Open cylinder publication is cleared

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` fails the independent complex-incidence audit with:

- `invalid-cell`;
- `cell=-1`, `halfedge=0`, `twin=1`, `next=4`.

The owner-count failure clears pending cells and leaves halfedges without committed ownership. The cylinder therefore cannot validate structural Euler or its two authoritative boundary loops.

### Bunny fan remains independent and open

`SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation` remains unchanged:

- `embeddingValid == false`;
- `topologyValid == false`;
- zero center cells instead of three.

R2E produced no evidence that this is caused by source-boundary side classification. Keep it deferred until the boundary-exterior successor producer closes.

## Static producer analysis

The R2E source shows the following sequence:

1. `SourceBoundaryTopology` stores only `loopByEdge`, `loopCount`, and `valid`; it does not retain ordered loop vertices, directed continuation, or subedge order.
2. Generic directed-wedge successor orbits are audited first.
3. `boundary_side_evidence` labels each already-formed raw orbit from any source-boundary halfedge it contains.
4. The implementation then requires exactly one raw negative-side orbit for each source loop.
5. On zero or multiple raw owners, it records `BoundaryLoopOwnerCount`, clears every pending cell, and later leaves all halfedge cell IDs invalid.

This applies an authoritative cardinality rule to a non-authoritative raw orbit partition. Boundary-terminating traces and hard rails can split the generic exterior-side continuation at source-boundary vertices. Counting or relabeling those fragments cannot construct the one authoritative exterior orbit.

The next correction must construct the exterior successor relation directly from ordered source-boundary topology **before** orbit audit. It must not merge or decompose cells after publication.

## Phase 17 and completion disposition

The same six Phase 17 failures remain:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

They still receive invalid or absent arrangement topology. Do not patch simplification independently.

Phase 20 remains **46/48**:

- cylinder production still fails at `NotProductionReady/completion`;
- the real completion failure still preempts the intended validation-stage lineage test.

## Direct analytic evidence

All direct cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Result | Arrangement cells | Completed quads | Earliest recorded failure | Wall | Peak working set |
|---|---:|---:|---:|---|---:|---:|
| plane | failed | 9 | 12 | `completion/output-validation: AggregateCompletionValidationFailure` | 0.026983 s | 8,171,520 B |
| multi-face seam | failed | 0 | 0 | `NotProductionReady/completion` | 0.028057 s | 8,040,448 B |
| close sheets | failed | 0 | 0 | `NotProductionReady/completion` | 0.042120 s | 8,196,096 B |
| cylinder | failed | 0 | 0 | `NotProductionReady/completion` | 0.291414 s | 9,814,016 B |

Plane still retains 15 output-validation failures. Seam, close sheets, and cylinder retain zero arrangement cells, zero simplified cells, and zero completed quads. No fallback, recovery, legacy backend, or input-mesh substitution occurred.

The benchmark JSON does not serialize the full arrangement diagnostic object after the failing context is released; focused tests provide the authoritative `BoundaryLoopOwnerCount` and invalid-cell evidence.

## Complete-suite result

- **623 tests discovered**;
- **595 passed**;
- **28 failed**;
- normal GoogleTest termination in **200.707 seconds**;
- no watchdog expiration;
- exact same failure set as P5-TB28;
- exact maximum RSS was unavailable because the outer timing wrapper detached while the test process continued;
- sampled process RSS reached at least **204,108 KiB**;
- XML and complete stdout/stderr finalized normally.

Comparison:

| Checkpoint | Passed/total | Failures | Duration |
|---|---:|---:|---:|
| P5-TB27 | 593/623 | 30 | 161.786 s |
| P5-TB28 | 595/623 | 28 | 192.964 s |
| P5-TB29 | **595/623** | **28** | **200.707 s** |

P5-TB29 is **4.01% slower** than P5-TB28. The dominant bunny-containing executions were:

- GP26 production matrix: **66.707 s**;
- GP27 production matrix: **65.378 s**;
- parameterized bunny case `/7`: **61.550 s**.

No performance conclusion is accepted while R2 remains invalid.

## Failure classification

- Package integrity: valid.
- R0/R1 focused authority: valid.
- Planar, hard-rail, cylinder, seam, close-sheet, bunny, Phase 17, and Phase 20 failures: **production implementation defects**.
- Existing focused fixtures and assertions continue to exercise their stated purposes; no structurally invalid fixture or incorrect expectation was identified.
- Exact full-suite maximum RSS: **infrastructure/evidence limitation** only.

## Decision

- R0 recovery authority: **closed**;
- R1 source transitions and validator authority: **closed**;
- R2 source nonmanifold preflight: **closed**;
- R2 explicit nested multi-boundary representation: **closed**;
- R2 boundary-side witness extraction: **compiled, fail-closed evidence observed**;
- R2 authoritative exterior successor construction: **open**;
- R2 source-loop ownership cardinality: **open**;
- R2 structural Euler runtime authority: **blocked by invalid publication**;
- R2 singularity-fan embedding: **open**;
- Milestone D closure: **open**;
- direct production: **open**;
- advance to R3: **no**;
- next turn: **P5-R2E2 authoritative boundary-exterior successor construction plus compile-only build**.

Preserve all prohibitions: no validator weakening, frequency/count/order ownership selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.
