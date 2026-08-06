# Milestone G P5-R2E15 Chart-Local Lifted Interval Authority Code + Build Plan

**Date:** 2026-08-06  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Purpose

Correct the earliest deterministic producer shared by the planar and interior hard-rail targets.

P5-TB42 proves:

- planar remains `InvalidOrientedInterval(8)` for the already-authoritative pair at tuple `3/5/4/9`;
- hard rail advances beyond `ExteriorPairMismatch(2)` and now first rejects `InvalidOrientedInterval(8)` at tuple `1/5/4/1`;
- the exact 28-test inventory is unchanged;
- no later separator, orbit, Euler, or aggregate-topology gate is reached.

The source computes a unique wedge-local lifted angle for every chart ray, but then re-sorts the same rays by global raw `atan2` angle to determine pair adjacency and interval geometry. Replace that second global ordering with exact chart-local lifted interval authority without changing pair existence, ownership, roots, exterior treatment, or downstream validators.

## Required implementation

### 1. Preserve canonical pair and exterior authority

Do not change how a canonical pair is created or owned.

Retain:

- node-level canonical directed pair inventory as the sole authority that a pair exists;
- normalized source entity and exact non-exterior common transition root;
- exact pair provenance;
- one explicit excluded exterior record per boundary-fan node;
- R2E14 endpoint-specific exterior source/target chart, root, side, and provenance;
- the rule that the excluded exterior record supplies no bounded-orbit root.

Chart-local interval evidence may resolve geometry only for an already-authoritative non-exterior pair. It must not create, remove, choose, score, merge, or replace a pair.

### 2. Make the existing lifted chart coordinate authoritative

For each matched chart/root:

1. retain the exact source entity wedge and its validated `wedgeStart`, `wedgeEnd`, and `wedgeSpan`;
2. retain the existing requirement that every participating chart ray has exactly one admissible angle `rawAngle + k·2π` in the wedge;
3. record the exact integer lift turn `k` together with the lifted angle;
4. reject a ray when:
   - no admissible lift exists;
   - more than one admissible lift exists;
   - the lift is not an exact integer turn within tolerance;
   - the lifted angle is non-finite or outside the authoritative wedge;
5. sort and ambiguity-check one chart-ray inventory by lifted angle;
6. do not build a second ownership or adjacency inventory sorted by raw global `atan2`.

The lifted angle is the sole chart-local coordinate for directed adjacency, span, and third-ray checks. Raw angle and lift turn are retained only as diagnostic provenance and for exact seam-wrap classification.

### 3. Resolve directed adjacency in the lifted wedge

For each already-authoritative non-exterior pair after normalized entity/root matching:

1. require exact directed-pair provenance from the canonical record;
2. find source and target in the lifted chart-ray inventory;
3. require the source ray to be the immediate successor of the target ray in increasing lifted angle;
4. do not use circular first/last adjacency across the bounded wedge ends as a substitute for missing directed adjacency;
5. reject any other ray strictly between target and source;
6. compute `orientedSpan = sourceLiftedAngle - targetLiftedAngle`;
7. require:
   - `orientedSpan > tolerance`;
   - `orientedSpan <= wedgeSpan + tolerance`;
   - source and target remain inside the same authoritative chart wedge.

No count, order, frequency, score, nearest-angle rule, or subset search may select a pair or root. Ordering is used only after exact pair ownership to verify immediate chart adjacency.

### 4. Derive seam-wrap observability exactly

Set `cyclicWrap=true` only when all of the following hold:

- the pair is already authoritative and uniquely adjacent in lifted chart order;
- source and target lifted angles form a valid positive interval in the wedge;
- their integer lift turns differ by exactly one in the authoritative direction, meaning the interval crosses the global raw-angle branch cut exactly once;
- no third ray intrudes;
- the interval remains within the chart wedge.

Set `cyclicWrap=false` when the adjacent valid pair has the same lift turn. Reject turn differences other than `0` or the one exact directed seam crossing.

Do not add `2π` during pair resolution as a heuristic. The unique lifted coordinates already encode the required turn.

### 5. Preserve complete witness and publication gates

Before publishing `candidateNext`, retain unchanged:

- exactly one reconciled chart witness per non-exterior canonical pair;
- complete one-to-one incoming and target cover;
- predecessor multiplicity one;
- source entity and chart authority;
- one explicit exterior exclusion per boundary-fan node;
- hard-rail separator side-pair checks;
- distinct selected roots on opposite hard-rail sides;
- complete bounded-orbit root audit;
- no exterior entry, barrier crossing, root loss/change, or ownership conflict;
- embedding, disk, loop, Euler, orientation, area, ownership, and aggregate topology validation.

Do not compensate downstream for a missing or invalid interval.

### 6. Non-weakening observability

Add deterministic diagnostic context only as needed to distinguish:

- no admissible lifted angle;
- multiple admissible lifted angles;
- non-integral or unsupported lift turn;
- duplicate lifted angle;
- missing source or target ray;
- missing directed provenance;
- non-adjacent lifted pair;
- reverse lifted order;
- third-ray intrusion;
- invalid lift-turn difference;
- non-positive span;
- span outside the authoritative wedge.

Retain the aggregate failure and all existing assertions. Do not relax expected counts, topology checks, tolerances, or success criteria.

## Allowed scope

Production/test changes are limited to:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` only if strictly necessary for derived diagnostic fields;
- `tests/SurfaceArrangementPhase16Tests.cpp` and `tests/MilestoneDClosureTests.cpp` only for non-weakening diagnostic context or exact semantic regression assertions.

Do not modify Phase 17, P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery, fixtures, manifests, source-authoritative validators, thresholds, or unrelated tests.

## Prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic wrap, counter, or Euler correction;
- no positional merging across unrelated sheets;
- no fixture, ID, node, halfedge, or test-name special case;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness;
- no chart-local inventory used to define whether a canonical pair exists;
- no raw global angle ordering used as pair ownership or chart-interval authority;
- no forced wrap merely because `sourceRawAngle <= targetRawAngle`.

## Code + Build gate

1. Inspect and clean stale bounded workflows and temporary payloads before work.
2. Start from the current branch and exact P5-R2E14 source authority.
3. Re-read the P5-TB42 report, this plan, live handoff, TODO, milestone tracker, and durable workflow policy.
4. Use exact preimage/blob checks for every modified file.
5. Apply only the bounded source/test changes above.
6. Push the exact source commit before compilation.
7. Configure Release with `-O2 -DNDEBUG`.
8. Build exactly:
   - `directional_core`;
   - `directional_pipeline`;
   - `directional_phase1_tests`;
   - `directional_benchmarks`.
9. Do not execute any project binary, test, benchmark, custom input, help/list/discovery command, CLI, or GUI.
10. Package exact source/test blobs, clean source status, recursive submodules, binaries/libraries, fixtures, configure/build/activity logs, and an internal SHA-256 manifest.
11. Upload the build artifact and a separate detailed log artifact.
12. Verify outer digests, every manifest entry, source/event commits, blobs, submodules, fixture closure, and empty source status.
13. Remove the bounded workflow and all temporary trigger/payload/patch files after verification.
14. Update the report, next artifact-only validation plan, summary, TODO, milestone tracker, live handoff, and PR body.
15. Make the final top-level PR #8 handoff comment the final repository write.

## Compile acceptance

Compile acceptance requires:

- only approved files changed;
- pair existence and ownership remain node-level and exact;
- R2E14 two-sided exterior authority remains unchanged;
- every non-exterior pair still requires one exact common root;
- one unique lifted coordinate per chart ray is enforced;
- directed adjacency and span use the authoritative lifted chart order;
- seam wrap is derived only from exact lift-turn provenance;
- contradictory or ambiguous evidence remains fail-closed;
- exactly four approved targets compile/link successfully;
- no project binary is executed;
- artifact/log authority is complete and verified;
- repository workflow/payload hygiene is restored.

Compile evidence does not establish runtime closure.

## Required next plan

After successful compilation, prepare **P5-TB43 artifact-only R2E15 Test + Benchmark**. It must first require:

- planar: one exterior exclusion, one positive genuine lifted-coordinate seam wrap, complete successor/predecessor bijection, Euler `1`, and valid disk/topology;
- hard rail: progress beyond `InvalidOrientedInterval`, one exterior exclusion with endpoint-specific exterior roots, two exact non-exterior common roots, complete bounded orbits, and valid embedding/topology;
- Phase 17 recovery to **26/26** without Phase 17 changes;
- no regression in accepted authority groups, the exact 625-test failure inventory, or direct production lineage.
