# Milestone G P5 — Bounded Structural Repair Code + Build Plan

**Turn status:** Implemented and compile-valid  
**Authoritative input:** P5-TB8 artifact `8842377256` evidence  
**Exact compiled source:** `bc95579be68d5de073de956022eec8fb89120ec0`  
**Compile-only run:** `30779430182` — success  
**Artifact:** `8843206930`  
**Next turn:** P5-TB9 artifact-only test and benchmark  
**Review policy:** `never`

## Completion status

P5-CB27 through P5-CB33 are source-complete and compile-valid. The compile gate built all four required targets in 131/131 steps, packaged an empty source status and ten passing checksums, and executed no test, benchmark, or custom mesh binary.

Compilation does not establish runtime correctness or production readiness. P5 remains open pending P5-TB9 using artifact `8843206930` without rebuilding.

## Objective

Replace the recursive same-corner repair search with an exact, deterministic, globally bounded transaction system that cannot expand combinatorially or retain unbounded complex copies. Preserve every existing ownership, topology, provenance, source-support, geometry, component/sheet, and duplicate validator.

## P5-CB27 — Global repair-work ledger — completed

- Removed recursive candidate-tree expansion from `complete_surface_cell_complex()`.
- Added one invocation-owned work ledger containing:
  - total candidate evaluations;
  - total structural attempts;
  - total inserted vertices;
  - total full descriptor/completion passes;
  - canonical states visited;
  - deterministic candidate, attempt, insertion, pass, and state limits.
- Candidate evaluation consumes the same global budget and never receives a reset depth-local budget.
- Every global limit has a typed fail-closed exhaustion reason.
- Candidates are evaluated exactly once in stable canonical order.

## P5-CB28 — Canonical state deduplication and memory discipline — completed

- Added collision-safe canonical repair-state identity from complete arrangement topology/domain identities, complete boundary identities, inserted splits, and active ownership claim.
- Already visited states are rejected using exact equality, not hash equality.
- At most one mutable candidate complex and one rollback complex are live.
- Rejected descriptors, completed patches, assembly meshes, and candidate complexes are released before continuing.
- No recursive result tree or repeated full ownership-ledger tree is retained.

## P5-CB29 — Strict progress and commit contract — completed

A structural candidate commits only when:

1. subdivision succeeds and is twin-conforming;
2. the normal topology/source-support/lineage validators pass through the completion pass;
3. the exact ownership claim is removed;
4. no replacement ownership conflict is introduced; and
5. assembly succeeds, reducing the active ownership-claim count from one to zero.

Persistence of the original pair is typed `NoProgress`. A different terminal ownership conflict is typed `IntroducedOwnershipClaim` and is never committed.

A claim with no provably distinct geometric boundary route fails before candidate search as `SameCornerDistinctBoundaryOverlap`.

## P5-CB30 — Recompute only where correctness permits — completed conservatively

Incremental descriptor/completion reuse was not enabled because equivalence has not yet been proven. Full recomputation remains authoritative, but every full pass consumes the same invocation-owned global pass budget and is reported separately from incremental passes. The incremental count remains zero.

## P5-CB31 — Real structural-repair regressions — compiled, runtime validation pending

Added source coverage invoking `complete_surface_cell_complex()` for:

- valid twin-aware parallel-route repair through one global ledger;
- semantic-only same-corner overlap failing before candidate expansion;
- zero structural budget;
- exact one-candidate budget with no recursion;
- patch-order invariance of the global ledger.

These sources compile but were not executed in this turn. P5-TB9 must determine whether they test and pass their intended scenarios.

## P5-CB32 — Observable typed diagnostics — completed

Completion results, pipeline diagnostics, structural hashes, and benchmark JSON expose:

- structural candidate budget and consumed count;
- structural attempts and inserted vertices;
- exact visited-state count;
- full and incremental recomputation counts;
- current and peak live candidate-complex count;
- exact exhaustion reason;
- last candidate interval and affected patch set;
- per-attempt validation, progress, repeated-state, introduced-claim, and budget outcomes.

Hashes remain diagnostic; equality remains collision-safe.

## P5-CB33 — Compile-only gate — completed

- Exact source: `bc95579be68d5de073de956022eec8fb89120ec0`.
- Workflow run: `30779430182` — success.
- Artifact: `8843206930`.
- Digest: `sha256:9b6ef73f2bd04eb49486cd7f0f28a1d2e9121a36791c7dd25fe1ffcc19d64f94`.
- Clean optimized static Release build.
- Compiled only:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.
- Packaged exact source, binaries, libraries, logs, source status, submodule revisions, and checksums.
- Source status is empty and all ten checksums pass.
- No test, benchmark, or custom mesh executable ran.

## Required P5-TB9 gates

The following turn must validate without rebuilding:

- all new structural-repair tests;
- PatchDescriptor, Phase 16/18, Phase 14–18, and P23/Phase20 suites;
- two direct random-bunny processes;
- no timeout;
- no fallback or recovery;
- deterministic repair ledger and structural hashes;
- peak memory no greater than 1.25× artifact `8841726806` (1,115,394,560 B);
- wall time no greater than 1.5× artifact `8841726806` (39.228299 s), unless a documented correctness-driven exception is independently reviewed.

Compilation alone does not close P5.
