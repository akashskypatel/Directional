# Milestone G P5-TB42 Artifact-Only R2E14 Test + Benchmark Report

**Date:** 2026-08-06  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E14 is **not accepted**.

The two-sided exterior-root change advances the interior hard-rail fixture beyond its prior `ExteriorPairMismatch`, but the earliest remaining observable producer for both focused targets is still chart interval normalization for an already-authoritative non-exterior pair:

- planar remains `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)` at tuple `3/5/4/9`;
- interior hard rail advances from `ExteriorPairMismatch(2)` at tuple `1/7/6/1` to `InvalidOrientedInterval(8)` at tuple `1/5/4/1`.

The planar fixture still publishes three canonical pairs and one exterior exclusion but no cyclic-wrap interior sector. The hard-rail diagnostic counters remain zero because the failure occurs before candidate publication and counter accumulation; those zero counters do not independently prove or disprove earlier exterior-record construction. No later separator, orbit, embedding, disk, Euler, ownership, or aggregate-topology gate is reached.

Phase 17 remains **20/26**. The complete failure inventory remains **597/625** with the exact same 28 failures as P5-TB41. No failure closed and no new failure appeared.

R2 remains open. Do not advance to R2F or R3.

## Exact artifact authority

- exact tested source: `2a8b9870b8e3854ae77a7e4eeae6da29a7899968`;
- workflow event commit: `c35fd7a4ca44946a233be4e18f175d4aa88bc03d`;
- workflow run/job: `31077891125` / `92539833523`;
- artifact ID/name: `8958361834` / `surface-cell-p5-r2e14-github-source-linux-release`;
- artifact SHA-256: `1f2607859ecf84d2cb82597f2c4f8f9341491df62d99b694510241f8df719db6`;
- artifact size: **12,307,622 bytes**;
- build configuration: Release `-O2 -DNDEBUG`;
- internal manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- executable-relative fixtures staged byte-identically: **26**;
- source status: empty;
- `SurfaceArrangement.cpp` blob: `bea11b3b24149c552e3569669d170419532f527e`;
- public header blob: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- Phase 16 test blob: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- Milestone D test blob: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`.

The outer artifact digest and size match GitHub's recorded authority. Every internal `SHA256SUMS` entry verifies from the package parent. Required binaries, libraries, source metadata, submodule revisions, fixtures, and source/test blobs match the package manifest.

No configure, rebuild, relink, regeneration, patch, implementation/test/fixture/validator/workflow/build change, or binary replacement occurred. Only the packaged binaries were executed.

## Focused deterministic diagnostics

### Planar higher-valence boundary

Test: `SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture`

- aggregate: `BoundaryFanSectorCoverConflict`;
- derived conflict: `InvalidOrientedInterval(8)`;
- tuple: node/incoming/source/target = `3/5/4/9`;
- canonical pairs: **3**;
- exterior exclusions: **1**;
- fan-sector nodes: **1**;
- cyclic-wrap interior sectors: **0**;
- hard-rail separators / side pairs: **0 / 0**;
- repetitions: **3**;
- byte-identical log SHA-256: `3498659bc601e18794fc90fe2d3b87349f66e4c172d9f57a9312b9d049887ade`.

This is unchanged from P5-TB41. Pair inventory and explicit exterior exclusion remain observable, but the first non-exterior interval still rejects before positive wrap, successor/predecessor publication, Euler, cell, area, ownership, and aggregate topology.

### Interior hard rail

Test: `MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary`

- aggregate: `BoundaryFanSectorCoverConflict`;
- derived conflict: `InvalidOrientedInterval(8)`;
- tuple: node/incoming/source/target = `1/5/4/1`;
- canonical pairs: **0**;
- exterior exclusions: **0**;
- fan-sector nodes: **0**;
- cyclic-wrap interior sectors: **0**;
- hard-rail separators / side pairs: **0 / 0**;
- repetitions: **3**;
- byte-identical log SHA-256: `fc7c65f89c71d707f7cf2df8873ec28147788d6b203307f39b0150194819f5cf`.

This is deterministic progression from P5-TB41's `ExteriorPairMismatch(2)` at tuple `1/7/6/1`. The prior common-root exterior mismatch is no longer the first observable producer. The new failure is a non-exterior oriented interval. Publication counters remain zero because candidate publication has not completed, so no claim of complete exterior insertion, separator authority, or orbit validity is made from those counters.

## Focused and aggregate results

| Group | P5-TB42 | P5-TB41 |
|---|---:|---:|
| Source chart + validator | **17/17** | **17/17** |
| Recovery authority | **9/9** | **9/9** |
| Feature/barrier | **8/8** | **8/8** |
| Graph-dependent | **5/6** | **5/6** |
| R2 focused | **13/16** | **13/16** |
| Milestone D | **5/7** | **5/7** |
| Phase 16 | **45/47** | **45/47** |
| Phase 17 | **20/26** | **20/26** |
| Phase 18 | **57/57** | **57/57** |
| Phase 14–18 | **235/244** | **235/244** |
| Phase 20 | **46/48** | **46/48** |

The accepted source-chart, validator, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold authority does not regress. The exact 28-test failure set is unchanged.

## Complete-suite and cumulative-state evidence

A bounded single-process complete suite finished normally:

- **597/625**, 28 failures, 0 errors, 0 disabled;
- XML time: **74.216 s**;
- wall time: **74.23 s**;
- maximum RSS: **282,848 KiB**;
- process exit: `1`, caused by test failures.

The P5-TB39–TB41 cumulative-state P27/bunny stop was **not reproduced** in this turn. P5-TB42 therefore has normal single-process correctness and process-completion authority. The earlier stop remains historical performance/nontermination evidence and is not erased or reclassified as correctness evidence.

The complete non-overlapping split was also retained:

- complete suite excluding two isolated P27 long cases: **596/623**, 27 failures, XML **26.914 s**, maximum RSS **272,408 KiB**;
- isolated P27 production matrix: **0/1**, XML **23.647 s**, maximum RSS **269,168 KiB**;
- isolated P27 bunny parameter: **1/1**, XML **21.994 s**, maximum RSS **269,132 KiB**;
- combined split inventory: **597/625**, 28 failures, 0 errors, 0 disabled.

The split and normal single-process results agree exactly.

## Direct production processes

Every direct process used:

- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- no legacy execution;
- the exact packaged benchmark executable and executable-relative fixtures.

| Case | Measured runs | Successes | Median wall | CV | Arrangement / simplified / quads |
|---|---:|---:|---:|---:|---:|
| Plane | 5 | 0 | 0.013177 s | 0.03048 | 9 / 9 / 12 |
| Multi-face seam | 5 | 0 | 0.013432 s | 0.02758 | 0 / 0 / 0 |
| Close sheets | 5 | 0 | 0.020155 s | 0.01031 | 0 / 0 / 0 |
| Cylinder | 5 | 0 | 0.132339 s | 0.01474 | 0 / 0 / 0 |

All measured analytic processes report `success=false` with terminal `NotProductionReady/completion`. Each case has identical structural lineage across its repetitions.

Two independent bunny processes completed:

- run 1: **21.712128 s**, **272,269,312 B** peak working set;
- run 2: **22.569164 s**, **272,265,216 B** peak working set.

Both report `success=false`, terminal `NotProductionReady/completion`, counts `0 / 0 / 0`, no fallback attempt, no legacy execution, no source-grid recovery, and the same structural lineage hash.

A clean process exit or completed benchmark record with `success=false` remains a production failure.

## Source-supported diagnosis

The following is an inference from the deterministic runtime diagnostics and exact packaged source. It is not an additional emitted runtime field.

The chart resolver already computes a unique **wedge-local lifted angle** for every chart ray:

1. raw direction angle is calculated with `atan2`;
2. integer turns of `2π` are tested;
3. exactly one lifted angle inside `[wedgeStart, wedgeEnd]` is required;
4. `chartRays` is sorted and ambiguity-checked using that lifted angle.

The implementation then creates a second `circularChartRays` inventory sorted by global raw `atan2` angle and uses that raw ordering to decide directed adjacency, seam adjacency, interval span, and third-ray intrusion. This discards the chart wedge's already-established lifted coordinate authority. A pair can therefore be authoritative in the chart wedge yet fail because the global `[-π, π]` branch cut does not represent the chart-local directed interval.

The earliest common remaining producer is **chart-local lifted interval authority for already-authoritative non-exterior pairs**.

The next implementation should:

- keep node-level canonical pair existence and normalized entity/root ownership unchanged;
- use each ray's unique lifted angle as the sole adjacency and interval coordinate inside the matched chart wedge;
- require exact directed adjacency in lifted order;
- derive a seam-wrap flag only from an exact one-turn difference between source and target lifted/raw representations, not from a second global raw-angle ordering;
- retain raw angle only as diagnostic provenance;
- reject ambiguous lifts, non-adjacency, third-ray intrusion, non-positive spans, and spans outside the authoritative wedge;
- leave two-sided exterior authority, non-exterior common-root authority, complete cover, predecessor, hard-rail, orbit, embedding, Euler, ownership, and aggregate topology gates fail-closed and unchanged.

Chart-local evidence must continue to resolve geometry only after canonical pair existence and ownership are fixed. It must not create, remove, choose, or score pairs.

## Acceptance audit

- [x] exact artifact and source authority verified;
- [x] all internal manifest entries, blobs, submodules, fixtures, and clean status verified;
- [x] packaged binaries only; no rebuild or mutation;
- [x] source-chart and source-authoritative validator prerequisite remains **17/17**;
- [x] hard rail advances beyond the previous `ExteriorPairMismatch`;
- [ ] planar interval publishes one genuine chart-seam wrap;
- [ ] hard rail completes non-exterior chart intervals;
- [ ] hard-rail separator, side roots, bounded orbits, and topology are reached and valid;
- [ ] planar successor/predecessor bijection, Euler `1`, and topology are reached and valid;
- [ ] Phase 17 returns to **26/26**;
- [x] accepted authority groups do not regress;
- [x] exact full-suite failure set does not regress;
- [x] one normal single-process 625-test run completed;
- [x] direct production remains fail-closed with no fallback, legacy, or recovery substitution;
- [x] no validator weakening, arbitrary ownership selection, synthetic wrap/counter/Euler correction, fixture special case, or timeout-as-correctness;
- [ ] R2E14 accepted — **not accepted**.

## Evidence

- archive: `directional-p5-tb42-8958361834-evidence.zip`;
- archive SHA-256: `41a2a7b58cc16ac96944a796a67d6a42ec00559b86a6cdb6991e0e9b04500fa3`;
- archive size: **431,852 bytes**;
- evidence files: **214**.

The archive contains artifact integrity records, source/test blob verification, submodule and fixture closure, machine context, exact filters, raw focused/group/full logs, XML, timing/RSS, process exit and progress evidence, direct benchmark JSON and logs, deterministic hashes, source excerpts, the complete failure inventory, and the machine-readable summary.

## Next turn

Execute **P5-R2E15 chart-local lifted interval authority Code + Build**.

The implementation must correct only the chart interval geometry of already-authoritative non-exterior pairs. It must preserve the R2E14 two-sided excluded exterior contract and every existing fail-closed ownership, root, cover, predecessor, separator, orbit, embedding, disk, Euler, orientation, area, ownership, and aggregate topology gate.

Compile exactly the four approved targets and execute no project binary. Runtime closure remains the responsibility of the following artifact-only Test + Benchmark turn.
