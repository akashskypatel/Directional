# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from the requested `SurfaceCells` backend. Fallback, source-grid recovery, synthetic topology repair, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete design gate. A later fixture, downstream completion catalog, diagnostic taxonomy, cache, scheduler, memory optimization, or benchmark cannot displace an earlier constructive gate.

Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Architecture

### Source authority

All decisions retain source triangle, chart, component, local-sheet, route, and feature provenance. World-space proximity is never sufficient to select a sheet, chart, or connectivity relation.

### Orientation, phase, and chart state

The cross field supplies local orientation, not connectivity. The producer carries first-class local phase, integer lattice coordinate, branch rotation, scale level, field family/sign, component, source-chart, and local-sheet identity. This state is deterministic, hashable, and transported only through authoritative source transitions.

### Directed phase front

A front edge owns source-attached endpoints, an ordered source route, lattice/chart state, family/sign, and one filled side or explicit exterior classification. Valid events are `CompatibleFrontMerge`, `BoundaryTermination`, `HardRailCapture`, `PhaseMismatch`, and `PeriodicHolonomyConflict`.

Missing or inconsistent transition, ownership, phase, route, component, or sheet state fails closed.

### Authoritative cell contract

A cell is authoritative only with four distinct source-attached corners, four ordered side paths, nonzero intrinsic area, source-normal-consistent winding, coherent phase/lattice/family/chart/sheet/route state, and exactly one filled side or exterior classification on every directed edge.

Opposite winding is corrected only by transactionally reversing the complete cycle. Positional sorting or index heuristics are prohibited.

### Materialization boundary

An accepted four-sided phase-front cell maps to one quad-domain cell. Arrangement may canonicalize exact source identities, split exact crossings, materialize halfedges/cycles, and validate provenance. It must not infer connectivity through fan-sector ranking, choose topology by count/order/frequency, merge unrelated sheets by position, expand an already-decided cell through generic completion, or decompose/merge cycles after the fact.

## Ordered gates

### G0 — Truthful authority

**Passed and continuously enforced.** Acceptance requires requested/executed `SurfaceCells`, fallback `Fail`, recovery disabled, valid `CompletedSurfaceCells`, and strict source-authoritative validation.

### G1 — Uniform phase-front plane

**Passed.** Exact artifact evidence produced 64 authoritative cells and 64 pure output quads, 81 vertices, zero validation failures, no fallback/recovery, and stable output hash `730caeae49ec872c` across three processes. The prior 65-to-409 expansion and `FlippedFace` failure are eliminated.

### G2 — Cross-chart and close-sheet propagation

**Active.** Add exact source-chart transition transport, quarter-turn cross-field matching, phase/lattice transport, seam success, deterministic source permutations, close-sheet success, and zero cross-sheet capture or merge.

Current evidence:

- multi-face seam: 137 traces, zero cells/quads, `SideSubdivisionRepair:InvalidInputIncidence`;
- close sheets: 158 traces, zero cells/quads, the same failure;
- both are deterministic across three artifact processes and use no fallback/recovery.

### G3 — Periodic closure and holonomy

Blocked by G2. Add explicit periodic phase reconciliation, complete directed incidence, and cylinder success.

### G4 — Topology-distinct completion and singularities

Blocked by G3. Add finite topology templates and intentional singularity handling without generic center-fan production fallback.

### G5 — Adaptive scale and hard features

Blocked by G4. Add dyadic scale levels, 2:1 transitions, hard-feature rails, and no T-junctions or feature loss.

### G6 — General production geometry

Blocked by G5. Achieve direct deterministic validated success on `bunny_1k_random.obj` for supplied and generated fields.

### G7 — Operational hardening

Blocked by G6. Address exact predicates, spatial indices, caches, parallelism, memory, performance, full validation matrix, and the production-default decision.

## Current Gate 2 subgate

Integrate exact source-chart and cross-field transition state into the constructive phase front. The multi-face seam is first; close-sheet isolation is second. Cylinder periodic reconciliation remains blocked.

Material progress requires nonzero authoritative cross-chart cells with explicit deterministic transport, preferably direct seam success. Unchanged zero-cell completion failure, renamed diagnostics, or new counters are not progress.

If two consecutive Code + Build turns do not materially improve the active gate, the following turn must perform a bounded design review or producer replacement proof.

## Current authority

- phase-front source commit: `4842911b6134c60410c92496d85d1152164a73c7`;
- orientation/direct-cell commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- tested artifact SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- evidence archive SHA-256: `458afe01241e8bf0c4623b5064f00eb294b17ffe99b9e34188625c14fbd0f074`.

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
