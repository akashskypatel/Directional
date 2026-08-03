# Milestone G P5 — Bounded Structural Repair Code + Build Plan

**Next turn type:** Code changes + compile-only build  
**Authoritative input:** P5-TB8 artifact `8842377256` evidence  
**Review policy:** `never`

## Objective

Replace the recursive same-corner repair search with an exact, deterministic, globally bounded transaction system that cannot expand combinatorially or retain unbounded complex copies. Preserve every existing ownership, topology, provenance, source-support, geometry, component/sheet, and duplicate validator.

## P5-CB27 — Global repair-work ledger

- Remove recursive candidate-tree expansion from `complete_surface_cell_complex()`.
- Use one invocation-owned work ledger containing:
  - total candidate evaluations;
  - total structural attempts;
  - total inserted vertices;
  - total full descriptor/completion passes;
  - canonical states visited;
  - remaining wall-independent deterministic work budget.
- Child/candidate evaluation must consume the same global budget; it must never receive a reset depth-local budget.
- Stop deterministically with a typed fail-closed result when any global limit is exhausted.
- Record every attempted candidate exactly once in stable canonical order.

## P5-CB28 — Canonical state deduplication and memory discipline

- Compute a collision-safe canonical repair-state identity from:
  - complete arrangement topology and domain identities;
  - complete undirected boundary identities;
  - inserted split identities;
  - active ownership claim.
- Skip already visited states using exact equality, not hash equality alone.
- Keep at most one mutable candidate complex and one rollback snapshot active at a time.
- Release descriptor, completed-patch, and assembly storage immediately after a rejected candidate.
- Do not retain recursive result trees or repeated full ownership ledgers.
- Preserve compact interned identities and diagnostic hashes.

## P5-CB29 — Strict progress and commit contract

A structural candidate may be committed only when all of the following hold:

1. subdivision succeeds and is twin-conforming;
2. topology/source-support/lineage validators pass;
3. the exact original claim is removed;
4. no new duplicate-domain, overlapping-boundary, false-equivalence, or same-corner claim is introduced;
5. a canonical monotonic progress measure decreases; and
6. either assembly succeeds or another iteration remains inside the same global work ledger.

Do not commit merely because a different terminal conflict replaced the original pair.

For a claim with no provably valid adjacent parallel boundary route, fail immediately with typed `SameCornerDistinctBoundaryOverlap`. Do not enter candidate search.

## P5-CB30 — Avoid full recomputation where correctness permits

- Reuse unchanged descriptor/completion products outside the two affected domains.
- Recompute only cells incident to the subdivided undirected interval plus any parity-coupled neighbors.
- If partial recomputation cannot be proven equivalent, retain full recomputation but enforce the global ledger and single-candidate memory discipline.
- Structural hashes must prove which products were reused and which were recomputed.

## P5-CB31 — Real structural-repair regressions

Add non-synthetic tests that invoke `complete_surface_cell_complex()` rather than only the stitcher:

- a valid twin-aware parallel-route fixture that performs one structural repair and completes;
- an unrepairable same-corner overlap that fails before recursive/full candidate expansion;
- a two-candidate fixture where the first fails and the second succeeds within one shared ledger;
- a repeated-state fixture proving canonical memoization stops a cycle;
- zero/one-budget fixtures proving exact attempt and insertion bounds;
- patch-order and source-face-row-order invariance;
- diagnostics/semantic-hash coverage for structural attempts, inserted intervals, visited-state count, and exhaustion reason;
- a medium multi-cell fixture proving bounded memory by construction and no repeated all-patch completion count.

Each test must establish the intended topology and ownership scenario from authoritative inputs. Do not set final validity flags synthetically.

## P5-CB32 — Observable typed diagnostics

Expose through completion result, pipeline diagnostics, structural hashes, and benchmark JSON:

- global structural candidate budget and consumed count;
- visited canonical state count;
- full versus incremental recomputation counts;
- current and peak live candidate-complex count;
- exact exhaustion reason;
- exact candidate interval and affected domain set;
- whether the candidate failed validation, made no progress, repeated a state, or introduced another ownership claim.

Hashes remain diagnostic; equality remains collision-safe.

## P5-CB33 — Compile-only gate

- Run no test, benchmark, or custom mesh executable.
- Perform a clean optimized Release configure.
- Compile only:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`.
- Package exact source, binaries, libraries, logs, source status, submodule revisions, and checksums.
- Source status must be empty.
- Update `TODO`, `MILESTONE_G_TODO.md`, the draft PR, and the code/build report.
- Leave P5 open and hand off the artifact to P5-TB9.

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
