# Milestone G P5-R2E14 Two-Sided Exterior-Root Authority and Chart-Seam Interval Normalization Code + Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Purpose

Correct the two earliest deterministic R2E13 producers without weakening validation:

1. hard rail rejects `ExteriorPairMismatch` before any canonical pair/exclusion because exterior source and target projections are collapsed to one transition root;
2. planar inserts and excludes the exterior pair, then rejects `InvalidOrientedInterval` because chart-seam wrap authority is derived from raw fan-vector index rather than the exact matched chart interval.

## Required implementation

### 1. Preserve two-sided exterior projection authority

Replace the exterior record's single-root assumption with an explicit two-sided contract:

- authoritative source-boundary loop identity;
- common normalized boundary entity, expected to be the exact source vertex/entity at the boundary node;
- source projected chart and source transition root with side `+1`;
- target projected chart and target transition root with side `-1`;
- exact agreeing fan provenance for each endpoint side.

Source and target roots may differ when an authoritative hard rail separates the incident interior chart components. Do not select or merge them. Validate each endpoint independently against its exact projected chart/root.

The excluded exterior pair must not be used as an interior complete-orbit root. All non-exterior canonical pairs continue to require exactly one common transition root.

### 2. Exact generic exterior reconciliation

When generic fan enumeration contributes the exact exterior directed triple, reconcile it against the two-sided record:

- directed triple and source-boundary loop must match exactly;
- source endpoint evidence must match the source projected chart/root/side;
- target endpoint evidence must match the target projected chart/root/side;
- contradictory evidence claiming either projected boundary chart must fail closed;
- unrelated fan memberships remain available for independent interior pairs.

No count, order, frequency, score, or subset selection is permitted.

### 3. Normalize chart-seam intervals after pair authority

Retain node-level canonical pair inventory as the sole authority that a pair exists.

For each already-authoritative non-exterior pair and matched chart/root:

1. identify the exact source and target corner rays on that chart;
2. establish circular adjacency from the chart's complete ordered corner-ray inventory and the pair's exact provenance;
3. if the oriented source angle is not greater than target angle, add `2π` only when the rays are the unique adjacent pair across the chart seam;
4. reject if another ray lies strictly inside the normalized interval, if adjacency is ambiguous, or if the normalized span exceeds the available chart wedge;
5. publish `cyclicWrap=true` from this exact chart-seam witness.

Do not create, delete, or choose a canonical pair from chart-local evidence. Chart evidence resolves the geometry of an already-existing pair only.

### 4. Preserve all gates

Before publishing `candidateNext`, retain:

- one explicit exterior record and one exclusion per boundary-fan node;
- complete non-exterior canonical pair inventory;
- exactly one reconciled chart witness per non-exterior pair;
- complete one-to-one incoming and target cover;
- predecessor multiplicity one;
- valid source entity and chart authority;
- hard-rail separator side-pair checks;
- distinct selected roots on opposite hard-rail sides;
- complete bounded-orbit root audit;
- embedding, disk, loop, Euler, orientation, area, ownership, and aggregate topology validation.

### 5. Non-weakening observability

Add deterministic diagnostic context only where needed to distinguish:

- invalid source projection;
- invalid target projection;
- boundary entity or loop mismatch;
- source-side provenance mismatch;
- target-side provenance mismatch;
- prohibited same-chart contradictory claim;
- non-adjacent chart interval;
- ambiguous chart-seam wrap;
- third-ray intrusion;
- normalized span outside the chart wedge.

Retain the aggregate failure and existing assertions. Do not relax expectations or thresholds.

## Allowed scope

Production/test changes are limited to:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` only if strictly necessary for derived diagnostic fields;
- `tests/SurfaceArrangementPhase16Tests.cpp` and `tests/MilestoneDClosureTests.cpp` only for non-weakening diagnostic context or exact semantic regression assertions.

Do not modify Phase 17, P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery, fixtures, manifests, source-authoritative validators, or unrelated tests.

## Prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture, ID, node, halfedge, or test-name special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness;
- no chart-local list used to define whether a canonical pair exists.

## Code + Build gate

1. Inspect and clean stale bounded workflows and temporary payloads before work.
2. Start from the current branch and exact P5-R2E13 source authority.
3. Use exact preimage/blob checks for every modified file.
4. Apply only the bounded source/test changes above.
5. Push the exact source commit before compilation.
6. Configure Release with `-O2 -DNDEBUG`.
7. Build exactly:
   - `directional_core`;
   - `directional_pipeline`;
   - `directional_phase1_tests`;
   - `directional_benchmarks`.
8. Do not execute any project binary, test, benchmark, custom input, help/list/discovery command, CLI, or GUI.
9. Package exact source/test blobs, clean source status, recursive submodules, binaries/libraries, fixtures, configure/build/activity logs, and an internal SHA-256 manifest.
10. Upload the build artifact and a separate detailed log artifact.
11. Verify outer digests, every manifest entry, source/event commits, blobs, submodules, fixture closure, and empty source status.
12. Remove the bounded workflow and all temporary trigger/payload files after verification.

## Compile acceptance

Compile acceptance requires:

- only approved files changed;
- exterior source and target roots remain exact and side-specific rather than selected or merged;
- non-exterior pairs retain one exact common root;
- chart-seam wrap resolves geometry only after node-level pair authority exists;
- contradictory or ambiguous evidence remains fail-closed;
- exactly four approved targets compile/link successfully;
- no project binary is executed;
- artifact/log authority is complete and verified;
- repository workflow/payload hygiene is restored.

Compile evidence does not establish runtime closure.

## Required next plan

After successful compilation, prepare **P5-TB42 artifact-only R2E14 Test + Benchmark**. It must first require:

- hard rail: one exterior record/exclusion with endpoint-specific roots, then two distinct bounded-orbit roots and valid embedding/topology;
- planar: one exterior exclusion, one positive genuine chart-seam wrap, complete successor/predecessor bijection, Euler `1`, and valid disk/topology;
- Phase 17 recovery to **26/26** without Phase 17 changes;
- no regression in the complete 625-test failure inventory or direct production lineage.
