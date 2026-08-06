# Milestone G P5-R2E16 Pair-Local Authoritative Fan-Chart Interval Projection Code + Build Report

**Date:** 2026-08-06  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E16 pair-local authoritative fan-chart interval projection is implemented and compile-valid.

Runtime acceptance is not claimed. P5-TB44 must execute the exact packaged binaries described below. R2 remains open; do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `a882dec6321ae632578b40aca6282015ac5284d2`;
- exact compiled source: `9db5531913195b255ea4c86ad50f609772527604`;
- workflow run/job: `31110167386` / `92645562024`;
- build artifact: `8971571147`;
- build artifact name: `surface-cell-p5-r2e16-github-source-linux-release`;
- build artifact SHA-256: `a0f18f8f4d544f8dd8e1a0f3ebb2b558188beed485294019c68f56ab2f4c2da3`;
- build artifact size: **12,343,344 bytes**;
- log artifact: `8971571865`;
- log artifact name: `surface-cell-p5-r2e16-workflow-logs-31110167386`;
- log artifact SHA-256: `4b2404a68368ae7eef3445f8c1db7c43ef8b05fcbb929a7768ea20b270d16358`;
- log artifact size: **5,803 bytes**;
- `SurfaceArrangement.cpp` blob: `ed26133b36673be28f70e91ea3e281c4cdd85441`;
- `SurfaceArrangement.h` blob: `43484706abcc54cf68e5d3ec7092487d07e0cf8c`;
- Phase 16 test blob: `7f2dbddd3e45ee98d5ac37bfe18b7970f41a6d06`;
- Milestone D test blob: `6887608b5aea173d6e6b5eaaee60150c4db17924`;
- decoded patch SHA-256: `c8f281c966c7a2fcb102c8079b2ff4cc3b460ca5b0d94c978104dd5fc954f47c`;
- recursive manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- source status: empty;
- fixture/input closure in the exact packaged source archive: **26/26** files under `benchmarks/fixtures`;
- compile/link actions: **132/132**.

Downloaded build and log archive digests match GitHub's recorded digests. Every internal `SHA256SUMS` entry verifies from the artifact parent, and the packaged source archive reproduces all four recorded source/header/test blobs.

Packaged target SHA-256 values:

- `directional_benchmarks`: `c61fac7e13f9b8d3ef40a0052d69d85c074fcbea67e7047144632170d0d81f05`;
- `directional_phase1_tests`: `253d24019700e0477d55ba9f0411b291f31533620b539b51a51c47e18732e45e`;
- `libdirectional_core.a`: `bde7b4b3759168e5499a6ca409cca0034f5ea638b1969c40206058af1ff77973`;
- `libdirectional_pipeline.a`: `79463fe011b6715732e47f0eefa585d73f3a239529c7fe5ec151c02267d62795`.

## Implementation

### 1. Pair-local evidence is derived from the complete exact identity set

The implementation retains node-level canonical pair existence and then resolves interval geometry from the complete deduplicated `record.fanIdentities` set for that pair. It does not choose one identity, rank identities, search subsets, or use frequency/order as ownership authority.

Every exact identity must provide:

- an exact fan witness and source-entity wedge;
- directed target-to-source provenance for the already-owned pair;
- one reconciled source chart;
- the pair's exact normalized source entity;
- the pair's exact common non-exterior transition root;
- one unique admissible lifted representation for every contributing ray.

Missing, incomplete, ambiguous, or contradictory identity evidence fails closed.

### 2. Unrelated fan identities cannot become pair-local intruders

The pair-local ray inventory is the union of rays contributed by the complete exact identity set recorded on that pair. A ray belonging only to an unrelated identity remains available to that identity's own canonical pair but does not participate in adjacency or third-ray intrusion for this pair.

When the same halfedge appears through more than one contributing identity, all chart, angle, turn, and provenance data must reconcile exactly. Conflicting evidence fails closed.

### 3. Lifted interval rules remain authoritative

For each non-exterior canonical pair:

- source and target must both occur in the pair-local lifted inventory;
- source must be the immediate increasing-angle successor of target;
- reverse order and skipped pair-local rays fail closed;
- span is computed from lifted angles and must be positive and remain within the exact wedge;
- third-ray intrusion is tested only against pair-local contributing rays;
- lift-turn difference `0` is non-wrap and `1` is one exact seam wrap;
- every other turn difference fails closed;
- all exact identities must reconcile to one chart, interval, and turn classification before publication.

Raw global angle remains diagnostic provenance only and does not create, choose, merge, remove, or replace a pair.

### 4. Deterministic non-weakening interval diagnostics

A public `SurfaceArrangementIntervalFailure` subtype and stable name function now distinguish the first interval producer, including missing identity/wedge/provenance/chart evidence, entity/root mismatch, lift ambiguity, duplicate lifted angle, missing endpoint, reverse/non-adjacent order, third-ray intrusion, invalid turn difference, invalid span, and cross-identity interval conflict.

The arrangement diagnostics retain deterministic context for the first rejection:

- source component, face, sheet, entity key, and transition root;
- exact identity count and canonical identity;
- source/target positions, raw angles, lifted angles, and lift turns;
- wedge start/end/span;
- intruding halfedge and identity when applicable.

The two focused tests print this context only when the existing aggregate incidence assertion fails and require a non-`None` subtype in that failure path. Their success criteria are not weakened.

### 5. Existing ownership and topology gates are preserved

P5-R2E16 does not change or weaken:

- node-level canonical pair construction and ownership;
- exact normalized source entity and one common root for every non-exterior pair;
- R2E14 endpoint-specific exterior chart/root/side authority;
- exclusion of exterior roots from bounded-orbit authority;
- one exterior exclusion per boundary-fan node;
- complete incoming/target cover and predecessor multiplicity;
- hard-rail separator side-pair and distinct-root checks;
- complete bounded-orbit root preservation;
- no exterior entry, barrier crossing, root loss/change, or ownership conflict;
- embedding, disk, loop, Euler, orientation, area, ownership, and aggregate-topology validation.

## Scope audit

Modified only:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` for the public non-weakening diagnostic subtype/context;
- `tests/SurfaceArrangementPhase16Tests.cpp` for focused diagnostic output/assertion context;
- `tests/MilestoneDClosureTests.cpp` for focused diagnostic output/assertion context.

Unchanged:

- Phase 17 implementation and tests;
- P27, bunny, cylinder, FlowRep, completion, optimization, fallback, and recovery behavior;
- fixtures and manifests;
- source-authoritative validators and thresholds;
- unrelated pipeline stages and tests.

## Compile gate

Configuration:

- Ubuntu 24.04;
- GNU C++ 13.3.0;
- Ninja;
- Release `-O2 -DNDEBUG`;
- static libraries;
- tests and benchmarks enabled for compilation;
- CLI, GUI, GMP, PARDISO, cuDSS, and SuiteSparse disabled.

Built exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_phase1_tests`;
4. `directional_benchmarks`.

No test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

## Workflow staging attempts

Two non-authoritative workflow runs stopped at the turn-file closure gate because the workflow commit did not yet contain the compressed patch payload:

- run `31109651905`, event `12473a926ba7963de085329d40f83dfd68255a80`;
- run `31109796879`, event `9da04dcf5f3851bb4dc2015c0c077fb8ef6c62a3`.

Both runs failed before tool-version checks, patch decode, patch application, source commit creation, submodule initialization, configuration, compilation, or runtime execution. Each uploaded only its unconditional diagnostic log artifact. They have no source, build, or runtime authority.

The payload was then committed as a verified descendant and the branch was advanced non-forced. The authoritative workflow event `a882dec6321ae632578b40aca6282015ac5284d2` contained both exact bounded inputs, passed all transport/preimage/postimage gates, pushed source `9db5531913195b255ea4c86ad50f609772527604` before compilation, and produced the verified artifacts above.

## Repository hygiene

After artifact verification:

- the bounded P5-R2E16 workflow was removed;
- the compressed patch payload is absent from the exact source commit and final branch;
- no `.agents/Directional/patches` directory remains;
- only the durable `agent-source-snapshot.yml` workflow remains;
- no generated build artifact is committed to the repository.

## Last runtime baseline

P5-TB43 remains runtime authority:

- planar: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `3/5/4/9`, three canonical pairs, one exterior exclusion, zero wraps;
- interior hard rail: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `1/5/4/1`, zero publication counters;
- source chart + validator **17/17**;
- recovery authority **9/9**;
- feature/barrier authority **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- complete suite **597/625**, 28 failures.

## Next turn

Execute **P5-TB44 artifact-only R2E16 Test + Benchmark** using artifact `8971571147`.

Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, fixtures, validators, workflows, or build logic. The runtime turn must use the new interval subtype/context to determine whether pair-local exact-identity projection closes the planar and hard-rail interval producers, then apply every unchanged publication, orbit, Euler, ownership, and aggregate-topology gate. Phase 17 must recover naturally before R2E16 can be accepted.
