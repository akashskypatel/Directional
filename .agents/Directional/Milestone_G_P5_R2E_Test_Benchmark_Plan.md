# Milestone G P5-R2E Test/Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Artifact-only Test + Benchmark

## Purpose

Validate the exact P5-R2E artifact without configuring, rebuilding, relinking, patching, regenerating, or modifying source. Decide whether exact source-boundary side ownership and structural Euler accounting close R2 or identify the next earliest producer.

## Artifact authority

- artifact: `8914900872`, `surface-cell-p5-r2e-corrected-github-source-linux-release`;
- archive SHA-256: `418518d879ec8686296ed3dd30d24e3b9e3b9df4280278996292fa1eba4d1d1c`;
- exact compiled/package source: `de0aa1a58a5861954dc9e14e731e681b5e5feb87`;
- implementation commit: `f5afd014cced8205d485bea4f1470725e1fd8be1`;
- workflow event commit: `2a40add65b13137d4d7183e0715c6807dbd6a10a`;
- reviewed patch SHA-256: `3ca1d3b940989e1fbda9e0f8f4b0b8c5971643575550ff9e34501e219651d628`;
- applied diff SHA-256: `abf671a365ab97ba3075962528bcf76b71901f6dc06a7d0b877499561c89814e`;
- workflow logs: `8914901042`, SHA-256 `351462cc5e3c72440fd2933bb31e3c2c63ee8560b61af20b9de8361a6713e0a3`;
- expected recursive checksums: **45/45**;
- expected package files: **46**;
- expected fixtures: **26**;
- expected recursive submodules: **9**;
- expected source workflows: one base workflow;
- expected temporary payloads: zero.

## Prohibited actions

Do not run CMake, build or relink any target, modify source, apply patches, regenerate files, alter expectations or fixtures, enable fallback/recovery/legacy output, or run the standalone bunny matrix unless focused and complete-suite evidence cannot identify the producer.

Execute only packaged binaries and fixtures.

## Execution order

### 1. Package integrity

Verify archive SHA, exact source and implementation records, empty status, **45/45** checksums, 46 files, all four target hashes, 26 fixtures, nine submodules, one base workflow, zero payloads, and the R2E implementation/tests in the source archive.

Reject any artifact that fails authority verification.

### 2. Preserved R0/R1 authority

Require:

- source-chart R1 **11/11**;
- Phase 22 validator **6/6**;
- recovery authority **9/9**;
- feature/barrier authority **8/8**.

### 3. Graph-dependent and R2 contracts

Run all directed-incidence, source-boundary, bridge/core, multi-boundary, and transactional-publication contracts.

Require:

- graph-dependent **6/6**;
- all expanded R2/R2C/R2D/R2E focused tests pass;
- typed nonmanifold and nested-cell closures remain passing;
- contradictory boundary-side evidence fails with the typed reason;
- every canonical source boundary loop has exactly one exterior owner;
- no valid halfedge retains `cell == -1`.

### 4. Planar, hard-rail, and cylinder topology

Require:

- planar: one source boundary loop, one exterior cell, full area coverage, Euler one, valid topology;
- interior hard rail: one source loop, one exterior owner, two bounded regions, valid topology;
- open cylinder: two source loops, two exterior owners, nonzero bounded inventory, Euler zero, valid topology;
- row permutation and whole-orientation reversal preserve loop identity, ownership, and deterministic hashes.

### 5. Milestone D and phase aggregates

Run:

- all `MilestoneDClosure.*`, requiring **7/7**;
- Phase 14–18 aggregate;
- Phase 16;
- Phase 17;
- Phase 18, requiring **57/57**.

Do not patch Phase 17 independently when its failures remain downstream of invalid arrangement topology.

### 6. Direct production cases

Run packaged plane, multi-face seam, close sheets, cylinder, and disconnected close-sheet case when present. Use `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

Record success/disposition, earliest typed failure, arrangement/exterior/bounded cell counts, source-loop owner counts, side contradictions, structural Euler, quads, validation failures, wall time, and memory.

Require seam, close sheets, and cylinder to retain nonzero valid arrangement inventories.

### 7. Phase 20 and complete suite

Run complete Phase 20, then the complete suite once with a watchdog used only for safety. Record discovered/passed/failed/disabled tests, normal termination, complete XML/logs, wall time, maximum RSS or sampled peak, dominant bunny durations, and comparison with P5-TB28.

Do not treat earlier rejection or lower runtime as correctness progress.

## Decision rule

Advance to R3 only when R0/R1 remain clean; all R2 incidence, source-side region, loop ownership, topology, and embedding gates close; planar/hard-rail/cylinder/seam/close-sheet inventories are valid; Milestone D and Phase 16 are clean; remaining direct failures move to later typed completion evidence; Phase 20 does not regress; and the complete suite terminates.

If source-boundary and Euler gates close but bunny singularity-fan embedding remains causal, prepare **P5-R2F intrinsic fan embedding Code + Build**. If R2 fully closes and completion remains causal, prepare R3.

## Failure classification

Classify every failure as production implementation defect, structurally invalid fixture, incorrect test expectation, or infrastructure/evidence limitation. Do not alter tests unless their input or assertion fails to exercise the documented purpose.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition;
- no timeout-as-correctness.
