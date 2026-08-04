# Milestone G P5-CB142 Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB22 artifact-only test and benchmark

## Authority

Execute artifact `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`, directly.

- exact compiled source: `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- workflow event commit: `b7f8a9978764b77931ba6d299fdcbc65639235de`;
- artifact SHA-256: `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`;
- reviewed patch SHA-256: `890dd621cf549f32c55d44f52b85050bfdfa5ce15df5f2bda2f8ba3e33c8ed70`;
- workflow-log artifact: `8894035556`;
- workflow-log SHA-256: `b7b84ba230c873702ec548318a5cad6b43fe4e1ccaf5d437bcd535201020ab1b`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB22.

## 1. Package authority

Before executing either packaged binary, verify:

- archive SHA-256;
- exact source commit and implementation ancestry;
- empty source status;
- internal recursive manifest **40/40**;
- **26** fixture files;
- **9** recursive submodule records;
- all four packaged target hashes;
- source archive contains the parity-state, completion-variant, route/cache, chart-reconciliation, typed-inventory, pipeline, and memory changes.

Any authority mismatch terminates the turn before runtime execution.

## 2. Focused P5-CB135 termination contracts

Run the smallest named tests covering alternative repair first.

Require:

- finite candidate budget derived from canonical incident interfaces;
- each canonical state visited at most once;
- deterministic state sequence/hash under face-row, insertion-order, and orientation permutations;
- actual memoized state reuse rather than repeated recomputation;
- a valid one-exclusion alternative still commits;
- all-invalid cases return typed `CycleDetected`, `BudgetExhausted`, or `AllInvalid` evidence with exact rollback;
- the earliest typed domain failure remains preserved.

A process watchdog may be used only as a safety mechanism to record nontermination. It is not correctness evidence and cannot convert a timeout into a pass.

## 3. Repeated-node alternatives

Run generalized reduced sources for the topologies represented by:

- sphere cell 2 / halfedge 37 / node 13;
- mechanical cell 2 / halfedge 719 / node 65;
- face-edge-derived cell 2 / halfedge 45 / node 20.

Record:

- initial typed rejection;
- candidate budget and attempts;
- state sequence hash;
- selected excluded interface;
- committed replacement cycle or terminal typed disposition;
- incidence, domain, ownership, protected-rail, and rollback audits.

Rejection alone is not completion success. At least one generalized repeated-node source must produce a valid committed bounded alternative before this gate closes.

## 4. Cylinder periodic DCEL

Run `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` plus existing seam-start, face-row, insertion-order, and orientation permutations.

Require:

- valid incidence;
- every bounded interior cell disk-valid;
- Euler characteristic 0;
- two boundary loops;
- consistent orientation;
- protected rail and strand continuation;
- deterministic topology hashes.

Do not accept relabeled invalid topology.

## 5. Local completion variants

Run focused and production cases that previously reported:

- bounded-combinatorial variant 23 `degenerate-normal`;
- cylinder pattern variant 25 `bow-tie-intersection`;
- thin-tube bounded-combinatorial variant 21 `degenerate-normal`;
- smooth bunny closed-form variant 0 `degenerate-normal`.

Require each invalid candidate to reject before authority and the bounded catalog to continue deterministically. Record backend, variant, patch/cell, local quad, corners, component/sheet, source faces, and terminal candidate count.

A case passes only when a valid source-supported local pure-quad completion is produced or an intended negative contract receives its exact typed failure.

## 6. Parallel route and exact completion-cache reuse

Run:

- renamed semantic duplicate rejection;
- valid annular/parallel route;
- whole-complex parallel-route completion;
- duplicate stitched-output regressions;
- one-candidate incremental budget;
- patch-order and route-order permutations.

Require:

- semantic duplicates reject before candidate expansion;
- stitch-separated annular routes remain distinct;
- valid annular route reaches completion;
- unchanged exact dependencies retarget and validate;
- `reused > 0` only after real validated cache reuse;
- `recomputed > 0` only after actual completion execution;
- no duplicate stitched quad.

## 7. Global source-chart reconciliation

Run plane, multi-face seam, close sheets, and disconnected-close-sheets contracts.

Require:

- exact intrinsic source-entity support intersections;
- a common component/sheet chart for each shared completed vertex and edge;
- deterministic canonical source-face selection;
- exact barycentric rebinding;
- agreement across all owning patches before global commit;
- disconnected close sheets remain distinct;
- no positional merge or source-triangle pairing.

Record the complete conflicting provenance set if the intersection remains empty.

## 8. Pipeline stage and failure lineage

Run focused GP23, GP24, and Phase20 contracts covering:

- declared optimization injection;
- declared validation injection;
- original and terminal failure code/stage;
- last-valid artifacts;
- fallback cause and executed backend;
- policy `Fail` with no legacy/fallback execution.

Each fixture must reach its intended declared stage through production-valid preceding output. Do not bypass completion or reorder production stages to satisfy a test.

Acceptance targets:

- GP23 **6/6**;
- GP24 **8/8**;
- Phase20 focused lineage contracts clean.

## 9. Torus typed inventory

Run torus descriptor/completion-focused tests and direct production.

Require:

- stable typed incomplete reason name, not only numeric `reasonCode`;
- descriptor/cell, attempted/failed/total inventory consistency;
- no skipped feasible descriptor;
- valid bounded template or a proven intended infeasibility contract;
- complete valid production output for the supported torus fixture.

## 10. Aggregate test scopes

After focused contracts, run independently:

1. Phase 14–18;
2. Phase 16;
3. Phase 17;
4. Milestone D;
5. Milestone E;
6. GP23 + GP24;
7. Phase20;
8. complete unfiltered suite.

The complete suite must terminate normally. A filtered subset is diagnostic evidence only and cannot replace the full-suite gate. When a safety watchdog fires, record the exact running test and last durable marker, then stop the aggregate attempt.

## 11. Direct production matrix

Run all eight established production fixtures with:

- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled.

Require nonempty, source-valid, consistently oriented, manifold pure-quad output with correct diagnostics and no hidden fallback for:

- plane;
- cylinder;
- torus;
- thin bent tube;
- close sheets;
- prescribed sphere;
- multi-face seam;
- mechanical feature.

Production acceptance is **8/8**.

## 12. Bunny determinism and resources

Run one isolated process per field/run using `bunny_1k_random.obj`.

### Face-edge field

Require four independent terminating runs with:

- identical successful output/topology/diagnostic signatures;
- valid pure-quad output;
- deterministic alternative-state sequence hash;
- wall and peak working set within established limits.

### Smooth/default field

Start with one isolated run. Continue only when the preceding run remains within:

- wall: 39.228299 s;
- peak working set: 1,115,394,560 B.

Stop repetitions after the first resource violation and record it as an open gate, not a correctness result.

## 13. Same-sample memory reconciliation

For every resource-gated bunny run, record:

- same-sample sequence/timestamp identity;
- working-set bytes;
- categorized owned bytes;
- reconciliation remainder;
- availability flag;
- exact categorized coverage ratio.

Require measurement availability and at least 75% categorized coverage at the same sample. Do not derive coverage from phase maxima or unrelated timestamps.

## Exit criteria

P5-TB22 closes only when all required runtime gates pass. Otherwise, record the earliest typed producer, update the handoff and next code/build plan, and keep P5 and PR #8 open.
