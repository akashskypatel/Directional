# Milestone G P5-R2E16 Pair-Local Authoritative Fan-Chart Interval Projection Code + Build Plan

**Date:** 2026-08-06  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Purpose

Correct the earliest remaining deterministic interval producer identified by P5-TB43 without changing canonical pair ownership, normalized source entity/root authority, R2E14 exterior treatment, or downstream topology validation.

P5-TB43 proves that P5-R2E15 does not advance either target:

- planar remains `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)` at tuple `3/5/4/9`;
- hard rail remains `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)` at tuple `1/5/4/1`;
- both targets reproduce byte-identically across three independent processes;
- Phase 17 remains **20/26**;
- the exact complete failure inventory remains **597/625**, 28 failures.

The exact source still resolves each authoritative pair against a node-wide same-chart ray inventory assembled from all fan identities. It does not project interval geometry from the complete exact set of fan identities already recorded on that pair. R2E16 must make those recorded identities the pair-local interval evidence while preserving node-level pair ownership and fail-closed reconciliation.

## Required implementation

### 1. Preserve node-level canonical pair authority

Do not change how a canonical pair is created, keyed, or owned.

Retain:

- exact node-level directed tuple `(incoming, sourceRay, target)`;
- normalized canonical source entity;
- one exact common transition root for each non-exterior pair;
- complete `record.fanIdentities` provenance;
- target multiplicity and incoming/target cover rules;
- predecessor multiplicity one;
- one explicit exterior record and exclusion per valid boundary-fan node;
- R2E14 endpoint-specific exterior source/target chart, root, side, and provenance;
- the rule that the excluded exterior record contributes no bounded-orbit root.

Pair-local fan-chart projection may validate interval geometry only after pair existence, normalized entity, and root authority are fixed. It must not create, delete, choose, score, merge, replace, or reorder canonical pairs.

### 2. Build complete pair-local fan-identity evidence

For each already-authoritative non-exterior canonical pair:

1. Require `record.fanIdentities` to be non-empty and complete.
2. Resolve **every exact identity** in `record.fanIdentities` through `nodeWedges` and the existing source-chart witness machinery.
3. Do not select one identity by count, order, frequency, score, position, minimum angle, or nearest relation.
4. Do not search arbitrary subsets of identities.
5. For each identity, derive the exact chart membership relevant to the pair's normalized entity and transition root.
6. Preserve duplicate-equivalent provenance as provenance, but reject contradictory identity content.
7. Keep fan identities not recorded on this pair available for their own canonical pairs; they must not enter this pair's adjacency or third-ray interval inventory merely because they share the node/chart.

The projection is the union of all rays and exact chart witnesses contributed by every recorded identity, with canonical deduplication by exact halfedge/chart identity. It is not one arbitrarily chosen fan.

### 3. Reconcile all contributing identities

Every contributing identity must agree on:

- pair source and target halfedges;
- directed provenance `target -> source`;
- normalized source entity;
- transition root;
- source chart component/sheet/face;
- unique lifted source and target coordinates;
- integer lift turns;
- wedge bounds and span;
- immediate directed adjacency after pair-local projection;
- third-ray absence inside the pair interval;
- wrap classification (`turn difference 0` or exact directed difference `1`).

Require at least one complete exact identity witness and require all recorded identities that claim the pair to reconcile to the same interval result. Missing, ambiguous, incomplete, or contradictory evidence fails closed.

Do not silently discard a disagreeing identity. Do not let one agreeing identity mask another identity's contradiction.

### 4. Use pair-local lifted interval geometry

For each reconciled pair-local chart projection:

1. Retain the existing unique admissible `rawAngle + k·2π` representative in the authoritative wedge.
2. Retain the exact integer lift turn `k`.
3. Build the lifted-order inventory from rays contributed by the pair's complete exact identity set only.
4. Require source to be the immediate increasing-angle successor of target.
5. Reject reverse order, skipped pair-local rays, duplicate lifted angles, and any pair-local third-ray intrusion.
6. Compute `orientedSpan = sourceLiftedAngle - targetLiftedAngle`.
7. Require positive span and both endpoints inside the same authoritative wedge.
8. Require span no larger than the wedge span within existing tolerance.
9. Classify `cyclicWrap=true` only when the exact source-target turn difference is `1`; difference `0` is a valid non-wrap; all other differences fail closed.

Raw global angle remains diagnostic provenance only. It must not regain interval, pair, entity, or root authority.

### 5. Preserve exterior and hard-rail contracts

Do not broaden the pair-local rule into the excluded exterior relation.

Retain unchanged:

- two endpoint-specific exterior charts, roots, sides, and provenance;
- exact exterior source/target boundary witness reconciliation;
- exactly one exterior record and exclusion;
- no exterior root in bounded-orbit authority;
- one exact common root for every non-exterior pair;
- opposite hard-rail sides retain distinct selected roots;
- complete bounded-orbit root preservation;
- no exterior entry, barrier crossing, root loss/change, or ownership conflict.

### 6. Add non-weakening interval observability

Current runtime diagnostics collapse all interval failures into `InvalidOrientedInterval`. Add deterministic derived context without changing aggregate acceptance or existing assertions.

Expose the first interval-rejection subtype from a fixed enum or equivalent stable classification, including at least:

- `MissingFanIdentity`;
- `MissingIdentityWedge`;
- `MissingDirectedProvenance`;
- `MissingChartWitness`;
- `EntityMismatch`;
- `RootMismatch`;
- `NoAdmissibleLift`;
- `MultipleAdmissibleLifts`;
- `NonIntegralLiftTurn`;
- `DuplicateLiftedAngle`;
- `MissingSourceRay`;
- `MissingTargetRay`;
- `ReverseLiftedOrder`;
- `NonAdjacentLiftedPair`;
- `ThirdRayIntrusion`;
- `InvalidLiftTurnDifference`;
- `NonPositiveSpan`;
- `SpanOutsideWedge`;
- `IdentityIntervalConflict`.

Record exact deterministic context as available:

- node, incoming, source ray, target;
- source chart component/sheet/face;
- normalized entity key and transition root;
- pair-local contributing identity count;
- source and target positions in lifted order;
- raw and lifted source/target angles;
- source/target lift turns and turn difference;
- wedge start, end, and span;
- first intruding halfedge/identity when applicable.

Retain `BoundaryFanSectorCoverConflict` and `InvalidOrientedInterval(8)` as the existing aggregate/derived contract unless the valid arrangement progresses to a later authoritative gate. Diagnostics must not relax success criteria.

### 7. Preserve publication and topology gates

Before publishing `candidateNext`, retain unchanged:

- one reconciled chart witness per non-exterior canonical pair;
- complete non-exterior canonical pair cover;
- target multiplicity one;
- complete incoming/target bijection;
- predecessor multiplicity one;
- exact chart/entity/root authority;
- exactly one exterior exclusion per boundary-fan node;
- hard-rail separator and side-pair validation;
- distinct selected roots across hard-rail sides;
- complete bounded-orbit root audit;
- no exterior entry, barrier crossing, root loss/change, or ownership conflict;
- embedding, disk, loop, Euler, orientation, area, ownership, and aggregate-topology validation.

Do not compensate downstream for missing or invalid pair-local interval evidence.

## Required target regression coverage

Tests may change only for non-weakening diagnostic context or exact semantic assertions. Do not relax any existing assertion.

Required focused checks:

1. Planar target exposes the first pair-local subtype/context if it still fails.
2. Hard-rail target exposes the first pair-local subtype/context if it still fails.
3. Existing degree-two and genuine four-disk valid boundary cases remain valid.
4. Source-row and orientation permutations remain deterministic.
5. Pinched, cyclic, nested non-disk, disconnected close-sheet, bridge/support, and nonmanifold invalid cases remain fail-closed.
6. Add or strengthen a generalized regression showing that an unrelated fan identity sharing a node/chart cannot intrude into a canonical pair's interval unless that identity belongs to the pair's complete provenance.
7. Add or strengthen a contradiction regression showing that two recorded identities claiming the same pair but disagreeing on interval/root/chart fail closed.

Do not encode fixture IDs, node IDs, halfedge IDs, test names, or expected implementation output into production behavior.

## Allowed scope

Production/test changes are limited to:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` only if strictly necessary for derived diagnostic fields;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

Do not modify:

- Phase 17;
- P27 or production fixture manifests;
- bunny, cylinder, FlowRep, completion, optimization, fallback, or recovery logic;
- source-authoritative validators;
- thresholds or tolerances;
- unrelated tests or build configuration.

## Prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no choosing one fan identity and ignoring the rest;
- no fallback/recovery substitution;
- no synthetic wrap, counter, Euler, orbit, or topology correction;
- no positional merging across unrelated sheets;
- no fixture, ID, node, halfedge, seed, or test-name special case;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness;
- no pair-local inventory used to redefine whether a canonical pair exists;
- no raw global angle restored as interval or ownership authority;
- no contradictory identity silently discarded.

## Code + Build gate

1. Inspect and clean stale bounded workflows, triggers, patch/payload directories, and generated artifacts before work.
2. Re-read TODO, milestone tracker, live handoff, P5-TB43 report, this plan, and durable workflow policy.
3. Start from the current branch head and exact P5-R2E15 source authority.
4. Record exact preimage blob SHA for every modified file.
5. Apply only the bounded implementation/test changes above.
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
12. Verify outer digests, every internal manifest entry, exact source/event commits, all modified/unchanged blobs, nine recursive submodules, 26-file fixture closure, and empty source status.
13. Remove the bounded workflow and every temporary trigger/patch/payload file after verification.
14. Produce the P5-R2E16 Code + Build report, machine-readable summary, P5-TB44 artifact-only plan, updated TODO/milestone/handoff, and updated PR body.
15. Delete superseded current-chain documents/results only after their replacements exist and are verified.
16. Make a new top-level PR #8 handoff comment after every other repository/PR write; that comment is the final repository write.

## Compile acceptance

Compile acceptance requires:

- only approved files changed;
- node-level canonical pair existence and ownership remain unchanged;
- every non-exterior pair still requires one normalized entity and exact common root;
- R2E14 two-sided exterior authority remains unchanged;
- pair-local interval projection consumes every exact identity in `record.fanIdentities`;
- no identity is selected by count, order, frequency, score, or arbitrary subset search;
- all contributing identities reconcile or fail closed;
- unrelated identities cannot intrude into another pair's interval;
- lifted coordinates remain sole interval geometry authority;
- first interval-rejection subtype/context is deterministic and non-weakening;
- all existing publication, hard-rail, orbit, embedding, Euler, ownership, and topology gates remain;
- exactly four approved targets compile/link successfully;
- no project binary is executed;
- artifact/log authority is complete and verified;
- repository workflow/payload/document/result hygiene is restored.

Compile evidence does not establish runtime closure.

## Required next plan

After successful compilation, prepare **P5-TB44 artifact-only R2E16 Test + Benchmark**. It must require:

- planar progression beyond tuple `3/5/4/9`, one exact exterior exclusion, one genuine lifted-coordinate seam wrap, complete successor/predecessor bijection, Euler `1`, and valid topology;
- hard-rail progression beyond tuple `1/5/4/1`, one two-sided exterior exclusion, two exact non-exterior common roots, complete bounded orbits, and valid topology;
- deterministic first rejection subtype/context if either target remains invalid;
- Phase 17 recovery to **26/26** without Phase 17 changes;
- no regression in accepted source-chart/validator, recovery, feature/barrier, focused, aggregate, complete-suite, or direct-production lineage evidence.

R2 remains open until runtime evidence proves closure.
