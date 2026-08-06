# Milestone G P5-TB43 Artifact-Only R2E15 Test + Benchmark Report

**Date:** 2026-08-06  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

**P5-R2E15 is not accepted. R2 remains open. Do not advance to R2F or R3.**

The exact P5-R2E15 packaged binaries were executed without configuring, rebuilding, relinking, patching, regenerating, or modifying implementation, tests, benchmarks, fixtures, validators, workflows, or build logic. Artifact integrity and exact source authority passed.

The chart-local lifted-order change does not advance either focused target from P5-TB42:

- planar remains `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)` at tuple `3/5/4/9`;
- interior hard rail remains `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)` at tuple `1/5/4/1`.

The same complete 28-test failure inventory remains. No failure closed and no new failure appeared. Phase 17 remains **20/26**, so the required natural recovery to **26/26** did not occur.

## Exact artifact authority

- workflow event commit: `47a5bf7a93fca3f63d9c54e09a1becd22251caef`;
- exact compiled source: `f14f1d416a9cb1b7afdf8109d22a76895e22fced`;
- workflow run/job: `31096815851` / `92600707664`;
- artifact: `8965975937`;
- artifact name: `surface-cell-p5-r2e15-github-source-linux-release`;
- artifact SHA-256: `2ea192b2be7496aa104948171d509d0f422b63afcf4ce296d4b35c60e2a28315`;
- artifact size: **12,306,846 bytes**;
- log artifact: `8965976454`;
- log artifact SHA-256: `68a5c352a618f594c757a1904ea1e9df31706dcb0706adabf6f4e9d87de3f0e9`;
- configuration: Release `-O2 -DNDEBUG`;
- internal manifest: **20/20**;
- artifact package files including manifest: **21**;
- recursive submodules: **9**;
- packaged source status: empty;
- executable-relative fixture closure: **26/26**, byte-identical.

Verified source/test blobs:

- `src/geometry/SurfaceArrangement.cpp`: `bc14dff449151f7925cb39e03cdc9d089f161558`;
- `include/directional/geometry/SurfaceArrangement.h`: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- `tests/SurfaceArrangementPhase16Tests.cpp`: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- `tests/MilestoneDClosureTests.cpp`: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`.

Only the packaged `directional_phase1_tests` and `directional_benchmarks` executables were run. No replacement binary was generated or substituted.

## Validation environment

- Debian GNU/Linux 13 (`trixie`), x86-64;
- Linux kernel `6.18.35`;
- AMD EPYC 9V74 virtual CPU;
- 5 online CPUs;
- approximately 6.37 GB memory;
- no swap.

Complete machine and process context is retained in the evidence archive.

## Prerequisite authority

The source-chart transition and source-authoritative validator prerequisite group passes **17/17**. Therefore the focused arrangement failures are interpreted as production implementation failures downstream of accepted source-chart authority, rather than as prerequisite infrastructure failures.

Accepted authority groups remain unchanged:

- recovery authority: **9/9**;
- feature/barrier authority: **8/8**.

## Focused deterministic targets

### Planar higher-valence boundary

Target:

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture`

Three independent processes produced byte-identical logs:

- log SHA-256: `3498659bc601e18794fc90fe2d3b87349f66e4c172d9f57a9312b9d049887ade`;
- aggregate failure: `BoundaryFanSectorCoverConflict`;
- derived failure: `InvalidOrientedInterval(8)`;
- tuple: node/incoming/source-ray/target = `3/5/4/9`;
- canonical pairs: **3**;
- exterior exclusions: **1**;
- boundary-fan sector nodes: **1**;
- cyclic-wrap interior sectors: **0**;
- hard-rail separators: **0**;
- hard-rail side pairs: **0**.

This is unchanged from P5-TB42. R2E15 does not publish the required positive integer-turn seam wrap and does not reach successor/predecessor bijection, Euler `1`, or the embedding, disk, loop, orientation, area, ownership, and aggregate-topology gates. Later topology behavior is not inferred from this earlier interval failure.

### Interior hard rail

Target:

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`

Three independent processes produced byte-identical logs:

- log SHA-256: `fc7c65f89c71d707f7cf2df8873ec28147788d6b203307f39b0150194819f5cf`;
- aggregate failure: `BoundaryFanSectorCoverConflict`;
- derived failure: `InvalidOrientedInterval(8)`;
- tuple: node/incoming/source-ray/target = `1/5/4/1`;
- canonical pairs: **0**;
- exterior exclusions: **0**;
- boundary-fan sector nodes: **0**;
- cyclic-wrap interior sectors: **0**;
- hard-rail separators: **0**;
- hard-rail side pairs: **0**.

This is unchanged from P5-TB42. The target does not reach exterior-record publication, hard-rail separator and side-pair validation, distinct non-exterior roots, complete bounded-orbit audits, or embedding/topology validation. Zero publication counters are evidence only of the early failure state; they do not establish later topology behavior.

## Focused and aggregate results

| Validation group | Result | P5-TB42 baseline | Disposition |
|---|---:|---:|---|
| Source chart + validator | **17/17** | 17/17 | unchanged pass |
| Recovery authority | **9/9** | 9/9 | unchanged pass |
| Feature/barrier authority | **8/8** | 8/8 | unchanged pass |
| Graph-dependent | **5/6** | 5/6 | unchanged |
| R2 focused | **13/16** | 13/16 | unchanged |
| Milestone D | **5/7** | 5/7 | unchanged |
| Phase 16 | **45/47** | 45/47 | unchanged |
| Phase 17 | **20/26** | 20/26 | unchanged; acceptance gate not met |
| Phase 18 | **57/57** | 57/57 | unchanged pass |
| Phase 14–18 | **235/244** | 235/244 | unchanged |
| Phase 20 | **46/48** | 46/48 | unchanged |
| Complete suite | **597/625** | 597/625 | exact same 28 failures |

The unchanged graph-dependent failure is:

- `FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation`.

The unchanged R2-focused failures are:

- `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`;
- `SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture`;
- `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation`.

## Complete-suite authority

The authoritative normal single-process run completed under the 180-second external bound:

- run label: `full-single-authoritative`;
- tests: **625**;
- passed: **597**;
- failed: **28**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **75.894 seconds**;
- wall time: **1:15.90**;
- maximum RSS: **279,568 KiB**;
- wrapper exit code: `1`, caused by test failures.

The exact failure set matches P5-TB42:

- closed failures: **0**;
- new failures: **0**;
- unchanged failures: **28**.

Two earlier local orchestration attempts did not produce complete authoritative suite evidence. Their incomplete outputs were removed. They are not used for correctness, performance, or process-state claims.

## Direct production processes

All direct runs used:

- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled;
- no legacy execution.

All processes returned `success=false`. A clean process exit with `success=false` remains a production failure.

| Case | Measured processes | Median wall time | CV | Arrangement / simplified / quads | Terminal failure | Deterministic structural lineage |
|---|---:|---:|---:|---:|---|---|
| Plane | 5 | **0.013274 s** | 0.03243 | `9 / 9 / 12` | `NotProductionReady/completion` | yes |
| Multi-face seam | 5 | **0.013449 s** | 0.03894 | `0 / 0 / 0` | `NotProductionReady/completion` | yes |
| Close sheets | 5 | **0.021009 s** | 0.03465 | `0 / 0 / 0` | `NotProductionReady/completion` | yes |
| Cylinder | 5 | **0.141729 s** | 0.25417 | `0 / 0 / 0` | `NotProductionReady/completion` | yes |
| `bunny_1k_random.obj` | 2 | **23.385574 s** | 0.00346 | `0 / 0 / 0` | `NotProductionReady/completion` | yes |

Cylinder variance includes one slower measured process; correctness remains failed in every process. Bunny had one warmup before the first measured process and two independent measured processes. No fallback, legacy, or source-grid recovery path was used.

## Failure classification

The focused failures are classified as **production implementation failures**. The fixtures and assertions are unchanged, source-chart/validator prerequisites pass, both targets reproduce deterministically, and R2E15 does not alter their first observable failure or tuple.

The complete suite remains incomplete. Focused passing groups and deterministic lineage do not establish production readiness.

## Source-supported diagnosis

The following is an inference from the exact packaged source and deterministic runtime evidence. It is not an additional emitted runtime field.

R2E15 correctly replaces the second raw-global-angle ordering with lifted chart order. However, the implementation still constructs one node-wide `raysByChart`/`chartWitnesses` inventory from every fan identity and resolves each already-authoritative canonical pair against all same-kind rays in that chart. Interval adjacency and third-ray intrusion are therefore not projected from the complete exact fan identities attached to that pair in `record.fanIdentities`.

An unrelated fan membership at the same node/chart can consequently appear between the pair endpoints or otherwise invalidate the node-wide chart interval even though it does not own that pair. The unchanged planar and hard-rail tuples after the raw-to-lifted ordering correction support this as the earliest remaining source producer.

Because all current interval rejection branches collapse into `InvalidOrientedInterval`, the evidence does not identify the exact branch subtype. The next implementation must add non-weakening deterministic subtype/context observability while preserving the aggregate failure and every existing acceptance gate.

## Authoritative next turn

Review is skipped under policy `never`. The proposed plan is therefore authoritative:

**P5-R2E16 Pair-Local Authoritative Fan-Chart Interval Projection Code + Build**

The next implementation must:

1. retain node-level canonical pair existence, normalized entity ownership, and exact common non-exterior transition root;
2. retain R2E14 endpoint-specific exterior authority;
3. project interval geometry for a non-exterior pair from the union of **every exact fan identity** in `record.fanIdentities`;
4. never choose one identity or an arbitrary subset;
5. require every contributing identity to reconcile to the same source/target lifted interval and turn classification;
6. keep unrelated identities available for their own pairs without allowing them to intrude into this pair's interval;
7. fail closed on missing, contradictory, ambiguous, or incomplete pair-local evidence;
8. expose the deterministic first interval-rejection subtype and exact chart/entity/root/position/angle/turn/wedge context;
9. preserve complete cover, predecessor multiplicity, exterior exclusion, hard-rail, bounded-orbit, embedding, Euler, orientation, area, ownership, and aggregate-topology gates.

The next Test + Benchmark plan after successful compilation must be **P5-TB44 artifact-only R2E16 Test + Benchmark**.

## Evidence archive

- file: `directional-p5-tb43-8965975937-evidence.zip`;
- SHA-256: `a905452fc0061344b21b61aba386be4c8084c1919a0b5398145f0c19dc5ec3b5`;
- size: **474,775 bytes**;
- entries: **296**.

The archive contains artifact-integrity records, machine context, exact filters, raw focused and aggregate logs/XML/timing/exit evidence, complete-suite evidence, direct-process JSON/log/timing evidence, failure-inventory comparison, source excerpts, execution tools, and the source-supported diagnosis.

## Required repository disposition

- PR #8 remains open, draft, and unmerged;
- R2 remains open;
- do not advance to R2F or R3;
- retain only the durable workflow, seven current/durable agent documents, durable baseline, and current P5-TB43 summary;
- the final top-level PR #8 handoff comment must be the final repository write.
