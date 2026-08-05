# Milestone G P5-TB28 Artifact-Only R2D Test/Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB28 is complete against artifact `8913777837` and exact compiled source `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`.

R2D closes the two contracts it directly added or strengthened:

- `SurfaceArrangementPhase16.NonManifoldSourceEdgeFailsClosedWithTypedIncidenceEvidence`;
- `SurfaceArrangementPhase16.NestedCyclesAreClassifiedAsNonDiskInsteadOfDefaultDisk`.

No previously passing test regressed. The complete suite improves from **593/623** to **595/623**. R2 nevertheless remains open because source-boundary side ownership, global arrangement topology, planar area/Euler accounting, singularity-fan embedding, and periodic/open-strand publication remain invalid. Multi-face seam, close sheets, and cylinder still publish zero arrangement cells and completion reports `SideSubdivisionRepair:InvalidInputIncidence`.

Do **not** advance to R3. The next turn is **P5-R2E source-boundary side ownership and Euler topology accounting plus compile-only build**.

## Package authority

- artifact: `8913777837`, `surface-cell-p5-r2d-github-source-linux-release`;
- archive SHA-256: `bcb9c6962677f2f638cf6a832eb25d88fdcd2a97e506a1435a7f936d4891416a`;
- exact compiled source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`;
- workflow event commit: `6757e6e98aa90e5b5eefce1db9645fbf523f2650`;
- reviewed patch SHA-256: `c7355a7de3998638f596fa927117584fce274920ca00fcd84f08773bf75935e8`;
- applied commit-diff SHA-256: `de9b6e9e30bf182d73082330d1ef2dbaceca07ffb7a2aa1a938d8e71896319a8`;
- workflow-log artifact: `8913778202`;
- workflow-log SHA-256: `04ba6f577b4d76519c365b564762b72844fa5b3f17e71c80bd7d292acf760384`;
- source status empty;
- recursive checksums **44/44**;
- package files **45**;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- source archive contains only `.github/workflows/agent-source-snapshot.yml` and zero agent patch payloads;
- compiled source is the parent of the documentation-only handoff head.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB28.

## Focused runtime results

| Scope | P5-TB27 | P5-TB28 | Result |
|---|---:|---:|---|
| Source-chart R1 | 11/11 | **11/11** | preserved |
| Phase 22 validator | 6/6 | **6/6** | preserved |
| Recovery authority | 9/9 | **9/9** | preserved |
| Feature/barrier authority | 8/8 | **8/8** | preserved |
| Graph-dependent | 5/6 | **5/6** | unchanged |
| R2/R2C/R2D focused | 7/10 R2C scope | **11/14** expanded scope | two R2D gates close |
| Milestone D | 5/7 | **5/7** | unchanged |
| Phase 14–18 | 231/242 | **233/242** | +2 |
| Phase 16 | 41/45 | **43/45** | +2 |
| Phase 17 | 20/26 | **20/26** | unchanged |
| Phase 18 | 57/57 | **57/57** | preserved |
| Phase 20 | 46/48 | **46/48** | unchanged |

### R2D contracts that close

1. A three-face nonmanifold source edge now fails closed with typed `NonManifoldSourceEdge` evidence.
2. Nested bounded cycles are retained as a two-boundary, Euler-zero `NonDisk` cell instead of being flattened or defaulted to a disk.

These are real producer corrections, not expectation changes or fallback substitutions.

### Remaining arrangement failures

1. `EulerBoundaryAndAreaChecksPassOnPlanarFixture`
   - arrangement Euler remains `-1` instead of `1`;
   - relative area error remains `1`;
   - no cell is classified as the source-boundary exterior orbit.
2. `BunnySingularityFanUsesIntrinsicSourceVertexRotation`
   - `embeddingValid == false`;
   - `topologyValid == false`;
   - zero center cells are published instead of three.
3. `InteriorHardRailIsNotClassifiedAsExteriorBoundary`
   - incidence, successor, predecessor, and cycle counters remain clean;
   - topology is invalid;
   - two cells are classified exterior instead of the one source boundary loop.
4. `CylindricalOpenStrandCommitsWithTopologyPreserved`
   - halfedge incidence and complete cell ownership pass;
   - no support-only cell is present;
   - final `topologyValid` remains false.

The R2D implementation therefore separates and publishes more structure correctly, but its per-orbit source-boundary classification and aggregate topology accounting are still not authoritative.

## Phase 17 and completion disposition

The same six Phase 17 failures remain:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

Their inputs still have invalid or absent arrangement topology. Do not repair these tests in simplification before R2 exterior/topology authority is clean.

Phase 20 remains **46/48**:

- cylinder production still fails at `NotProductionReady/completion`;
- real completion failure still preempts the intended validation-stage lineage test.

## Direct analytic evidence

All direct cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Result | Arrangement cells | Completed quads | Earliest failure | Wall | Peak working set |
|---|---:|---:|---:|---|---:|---:|
| plane | failed | 9 | 12 | `completion/output-validation: AggregateCompletionValidationFailure` | 0.026871 s | 8,257,536 B |
| multi-face seam | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.029563 s | 8,122,368 B |
| close sheets | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.041790 s | 8,327,168 B |
| cylinder | failed | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` | 0.298168 s | 9,879,552 B |

Plane retains 15 output-validation failures. Seam, close sheets, and cylinder do not retain the required nonzero arrangement inventory. No fallback, source-grid recovery, legacy backend, or input-mesh substitution occurred.

## Complete-suite result

- **623 tests discovered**;
- **595 passed**;
- **28 failed**;
- normal termination in **192.964 seconds**;
- no watchdog expiration;
- no new failures relative to P5-TB27;
- exact maximum RSS was not emitted because the outer execution wrapper detached before `/usr/bin/time` finalized;
- the highest sampled process RSS was at least **204,532 KiB**;
- XML and complete stdout/stderr finalized normally.

Comparison:

| Checkpoint | Passed/total | Failures | Duration |
|---|---:|---:|---:|
| P5-TB26 | 588/621 | 33 | 74.763 s |
| P5-TB27 | 593/623 | 30 | 161.786 s |
| P5-TB28 | **595/623** | **28** | **192.964 s** |

P5-TB28 is **19.27% slower** than P5-TB27. The dominant bunny-containing executions are:

- GP26 production matrix: **67.008 s**;
- GP27 production matrix: **61.108 s**;
- parameterized bunny case `/7`: **57.725 s**.

The two correctness closures are accepted, but the runtime increase is not considered performance progress while R2 remains invalid.

## Earliest remaining producer

The earliest common producer is now the mapping from complete audited successor orbits to authoritative source-side regions:

- a source component with one boundary loop can publish zero exterior cells (planar fixture) or two exterior cells (interior hard rail);
- aggregate Euler still counts each bounded record as one face rather than summing its explicit structural Euler contribution;
- arrangement boundary loops are inferred from the resulting exterior labels, so a wrong label invalidates topology even when halfedge incidence and ownership are complete;
- cylinder reaches complete incidence/ownership but fails only at aggregate topology;
- seam, close sheets, and cylinder subsequently reach completion with zero valid arrangement cells.

Bunny singularity-fan embedding remains a second R2 producer. It should be changed in the next turn only if static analysis proves it shares the same source-side region or boundary-cycle geometry defect; otherwise preserve it for the following focused R2 turn.

## Decision

- R0 recovery authority: **closed**;
- R1 source transitions and validator authority: **closed**;
- R2 source nonmanifold preflight: **closed**;
- R2 explicit nested multi-boundary representation: **closed**;
- R2 source-boundary side ownership: **open**;
- R2 aggregate topology/Euler authority: **open**;
- R2 singularity-fan embedding: **open**;
- Milestone D closure: **open**;
- direct production: **open**;
- advance to R3: **no**;
- next turn: **P5-R2E source-boundary side ownership and Euler topology accounting plus compile-only build**.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.
