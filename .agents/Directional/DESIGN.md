# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from the requested `SurfaceCells` backend. Fallback, source-grid recovery, synthetic topology repair, or validator relaxation cannot satisfy acceptance.

## Design-first operating rule

Implementation always advances the earliest incomplete gate. A later fixture, downstream completion catalog, diagnostic taxonomy, cache, scheduler, memory optimization, or benchmark cannot become the principal objective while an earlier constructive gate is red.

Every implementation turn declares:

```text
Active design gate
Earliest failing fixture
Missing design contract
Smallest general implementation change
Observable material-progress condition
Explicitly deferred work
```

## Architecture

### 1. Source authority

All geometric and topological decisions retain source triangle, chart, component, local-sheet, route, and feature provenance. World-space proximity is never sufficient to select a sheet, chart, or connectivity relation.

### 2. Cross-field orientation plus lattice phase

The cross field supplies local orientation, not connectivity. The producer therefore carries first-class:

- local phase;
- integer lattice coordinate;
- branch rotation;
- scale level;
- field family and advance sign;
- component, source-chart, and local-sheet identity.

This state is deterministic, hashable, and transported only through authoritative source transitions.

### 3. Directed phase front

A front edge owns:

- source-attached endpoints and ordered source route;
- lattice state;
- field family/sign;
- one unfilled side or explicit exterior classification.

Bounded event classes are:

- `CompatibleFrontMerge`;
- `BoundaryTermination`;
- `HardRailCapture`;
- `PhaseMismatch`;
- `PeriodicHolonomyConflict`.

Missing or inconsistent transition, ownership, phase, route, component, or sheet state fails closed.

### 4. Authoritative cell contract

A phase-front cell becomes authoritative only when it has:

1. exactly four distinct source-attached corners;
2. four ordered side paths with endpoint continuity;
3. nonzero intrinsic signed area;
4. winding consistent with the authoritative source normal;
5. coherent phase, lattice, family/sign, component, chart, sheet, and route state;
6. exactly one filled side or explicit exterior classification on every directed front edge.

Opposite winding is corrected only by transactionally reversing the complete cycle, including corners, lattice states, side routes, directions, family/sign state, and ownership. Positional sorting or index heuristics are prohibited.

### 5. Arrangement materialization boundary

An accepted four-sided phase-front cell already defines its intended topology and maps to one quad-domain cell.

Arrangement may:

- canonicalize equivalent source identities;
- split exact geometric crossings;
- materialize halfedges, twins, next links, cycles, and cell IDs;
- validate topology and provenance.

Arrangement and completion must not:

- infer cell connectivity through fan-sector ranking;
- select topology by count, order, or frequency;
- merge unrelated sheets by position;
- expand an already-decided four-sided cell through generic patch completion;
- decompose or merge cycles post hoc to obtain desired output.

### 6. Downstream stages

Only after valid direct cells exist may later stages perform bounded simplification, topology-distinct completion where the producer intentionally emits a supported non-four-sided region, source-surface optimization, validation, and cleanup. Downstream machinery cannot substitute for a missing producer contract.

## Ordered high-level gates

### G0 — Truthful authority

Passed and continuously enforced:

- requested/executed backend `SurfaceCells`;
- fallback `Fail` for acceptance;
- source-grid recovery disabled;
- only valid `CompletedSurfaceCells` output can succeed;
- strict source-authoritative validation.

### G1 — Uniform phase-front plane

**Active.** Required:

- first-class lattice/front state;
- uniform planar source-attached front;
- authoritative oriented four-sided cells;
- one-to-one direct quad-domain materialization;
- non-empty pure-quad plane output passing strict validation without fallback/recovery.

Current evidence: 352 traces, 65 arrangement cells, 409 completed quads, then `completion/output-validation:FlippedFace` with 100 validation failures. The phase front is live, but orientation and materialization are invalid.

### G2 — Cross-chart and close-sheet propagation

Blocked by G1. Add authoritative transition transport, seam success, deterministic permutations, close-sheet success, and zero cross-sheet capture/merge.

### G3 — Periodic closure and holonomy

Blocked by G2. Add explicit periodic phase reconciliation, complete directed incidence, and cylinder success.

### G4 — Topology-distinct completion and singularities

Blocked by G3. Add finite topology graph templates, intentional singularities, and supported 3–6-sided completion without generic center-fan fallback.

### G5 — Adaptive scale and hard features

Blocked by G4. Add dyadic scale levels, 2:1 transitions, hard feature rails, and thin/mechanical cases without T-junctions or feature loss.

### G6 — General production geometry

Blocked by G5. Direct deterministic validated success on `bunny_1k_random.obj` for supplied and generated fields.

### G7 — Operational hardening and default-on decision

Blocked by G6. Exact predicates, spatial indices, caches, parallelism, memory, performance, full matrix, and explicit production-default decision.

## Current Gate 1 subgate

The next Code + Build turn implements source-normal orientation and one-to-one direct-cell materialization. It must not add seam, periodic, adaptive, feature, singularity, or bunny logic.

Material progress requires plane success or a structurally later failure with one-to-one materialization and reduced invalid-output burden. A diagnostic change alone is not progress.

If the next Code + Build turn does not materially improve this contract, the following turn must perform a bounded design review or producer replacement proof.

## Source synchronization during GitHub outage

The tested implementation is exact base `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9` plus patch blob `aa18d454877ccf40d16f71f173fdaf765f5f1086`. Keep five-file synchronization on the TODO until service recovery. Do not use workflows for repository updates while the outage persists. After recovery, apply the existing patch exactly through direct Git objects or an authenticated client and verify every expected output blob before removing the payload.

## Non-negotiable prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
