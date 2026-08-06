# Milestone G P5-R2E15 Chart-Local Lifted Interval Authority Code + Build Report

**Date:** 2026-08-06  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E15 chart-local lifted interval authority is implemented and compile-valid.

For an already-authoritative non-exterior canonical pair, the validated source-entity wedge's unique lifted coordinate is now the sole chart-local authority for directed adjacency, interval span, third-ray intrusion, and seam-wrap classification. The former second inventory sorted by global raw `atan2` angle was removed. Pair creation, normalized entity/root ownership, R2E14 two-sided exterior authority, publication gates, bounded-orbit audits, and downstream topology validators remain unchanged.

Runtime acceptance is not claimed. P5-TB43 must execute the exact artifact below. R2 remains open; do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `47a5bf7a93fca3f63d9c54e09a1becd22251caef`;
- exact compiled source: `f14f1d416a9cb1b7afdf8109d22a76895e22fced`;
- workflow run/job: `31096815851` / `92600707664`;
- build artifact: `8965975937`;
- build artifact name: `surface-cell-p5-r2e15-github-source-linux-release`;
- build artifact SHA-256: `2ea192b2be7496aa104948171d509d0f422b63afcf4ce296d4b35c60e2a28315`;
- build artifact size: **12,306,846 bytes**;
- log artifact: `8965976454`;
- log artifact SHA-256: `68a5c352a618f594c757a1904ea1e9df31706dcb0706adabf6f4e9d87de3f0e9`;
- log artifact size: **5,654 bytes**;
- `SurfaceArrangement.cpp` blob: `bc14dff449151f7925cb39e03cdc9d089f161558`;
- unchanged public header blob: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- unchanged Phase 16 test blob: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- unchanged Milestone D test blob: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`;
- decoded patch SHA-256: `b500beffbcb7a414fff2f265a730916a6a600d90d2ee797a72348f1480fad3e0`;
- accepted patch transport concatenation SHA-256: `b37484a949340e63d26a4da55f3b13683bcda6c02e68f0ab6d16b3bbf0e4dabe`;
- recursive manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- executable-relative fixture closure: **26** files;
- compile/link actions: **132/132**;
- packaged source status: empty.

Downloaded build and log archive digests match GitHub's recorded digests. Every internal manifest entry verifies from the package parent, and the source archive reproduces all recorded production/header/test blobs.

Packaged target SHA-256 values:

- `directional_benchmarks`: `de2d9b9b36298a2b4fbe9075f453a3fa023dbad37df03e0297ac941ffd87ed9a`;
- `directional_phase1_tests`: `ca2e1ff2e238134c5ae1a9c9b298fb0a58aa51108ab05a1fac8a08328e33374f`;
- `libdirectional_core.a`: `112c419a7a3cb0a8514bd7ef8525e47124cd86c20d1d282ca73ecabbe713138a`;
- `libdirectional_pipeline.a`: `7bac91c0a17866bf56c10cc512532879c3a04e1f542150ef4c8b7508f8b04345`.

## Implementation

### 1. One exact lifted coordinate per chart ray

`ChartCornerRay` now retains the exact integer lift turn together with its raw diagnostic angle and its authoritative lifted angle. A participating ray is accepted only when exactly one `rawAngle + k·2π` representative lies in the validated source-entity wedge. Non-finite candidates, non-integral reconstructed turns, zero admissible lifts, and multiple admissible lifts fail closed.

### 2. Lifted chart order is sole interval authority

The implementation retains the existing chart-ray inventory sorted and ambiguity-checked by lifted angle. It no longer copies and re-sorts that inventory by global raw angle. A halfedge-to-position map is built directly from the lifted order.

Chart-local ordering is consulted only after node-level canonical pair existence, normalized entity authority, exact common non-exterior transition root, and directed provenance have already been established. It cannot create, choose, score, merge, delete, or replace a pair.

### 3. Exact directed adjacency and span

For each matched non-exterior pair:

- source and target must both exist in the lifted inventory;
- source must be the immediate increasing-angle successor of target;
- first/last circular raw-angle adjacency is not accepted across the bounded wedge ends;
- reverse order fails closed;
- a skipped lifted ray is classified as third-ray intrusion;
- interval span is `sourceLiftedAngle - targetLiftedAngle`;
- span must be positive, remain within `wedgeSpan`, and both endpoints must remain inside the authoritative wedge.

The explicit third-ray scan also uses lifted angles only.

### 4. Exact seam-wrap provenance

`cyclicWrap` is derived from integer lift-turn difference after valid directed lifted adjacency:

- difference `0`: valid non-wrapping interval;
- difference `1`: one exact directed crossing of the global raw-angle branch cut;
- any other difference: fail closed.

No heuristic `2π` addition occurs during pair resolution, and raw angle is no longer interval or ownership authority.

### 5. Existing authority and validators preserved

P5-R2E15 does not change or weaken:

- node-level canonical pair construction and ownership;
- normalized source entity and one exact common root for every non-exterior pair;
- R2E14 endpoint-specific exterior charts, roots, sides, and provenance;
- the rule that the excluded exterior record supplies no interior bounded-orbit root;
- one exterior exclusion per boundary-fan node;
- one reconciled chart witness per non-exterior pair;
- complete incoming/target cover and predecessor multiplicity;
- hard-rail separator side-pair and distinct-root checks;
- complete bounded-orbit root audit;
- no exterior entry, barrier crossing, root loss/change, or ownership conflict;
- embedding, disk, loop, Euler, orientation, area, ownership, and aggregate topology validation.

## Scope audit

Production change only:

- `src/geometry/SurfaceArrangement.cpp`.

Unchanged:

- public header and all tests;
- Phase 17;
- P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery;
- fixtures, source-authoritative validators, thresholds, and unrelated diagnostics.

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

## Workflow and repository hygiene

The first bounded attempt, run `31096571994`, failed before patch decode because staged part 00 contained extra transport bytes and the concatenated base64 checksum did not match. It produced log artifact `8965673988` only. No patch was applied, no source commit was created, and no configure/build/runtime command ran in that attempt.

The transport fragment was corrected and hash-verified before the authoritative run. Run `31096815851` applied the exact patch, removed all three transfer fragments in the exact source commit, pushed that source commit before compilation, and uploaded successful build and log artifacts separately. After verification, the bounded workflow was removed. Only the durable source-snapshot workflow remains.

## Last runtime baseline

P5-TB42 remains runtime authority:

- source chart + validator **17/17**;
- recovery authority **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- complete suite and split inventory **597/625**, 28 failures.

Planar failed `InvalidOrientedInterval(8)` at tuple `3/5/4/9`, with three canonical pairs, one exterior exclusion, and zero wraps. Hard rail advanced beyond exterior mismatch and failed `InvalidOrientedInterval(8)` at tuple `1/5/4/1`. The full 625-test process completed normally in 74.23 seconds with maximum RSS 282,848 KiB. Direct production cases remained fail-closed and deterministic.

## Next turn

Execute **P5-TB43 artifact-only R2E15 Test + Benchmark** using artifact `8965975937`.

Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, fixtures, validators, workflows, or build logic. The runtime turn must determine whether planar and hard rail progress beyond the prior interval producer, then apply all unchanged publication, orbit, Euler, ownership, and aggregate topology gates. Phase 17 must return to **26/26** naturally before R2E15 can be accepted.
