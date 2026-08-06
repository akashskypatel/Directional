# Design-Aligned Uniform Phase-Front Code + Build Plan

## Turn type

Code changes plus compile-only build. Do not execute tests, benchmarks, CLI, GUI, discovery, or generated project binaries.

## Active design gate

**Gate 1 — Uniform phase-front plane**

The turn exists only to implement the smallest general phase-labelled advancing-front producer needed by the plane fixture.

## Authority

- Design: `.agents/Directional/DESIGN.md`.
- Reorientation: `.agents/Directional/REORIENTATION_PLAN.md`.
- Remediation: `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`.
- Runtime baseline: `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`.
- Testing policy: `tests/TESTING_STRATEGY.md`.
- Exact tested source baseline: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`.

## Required pre-work declaration

Before changing code, record in the Code + Build report:

```text
Active gate: Gate 1 — Uniform phase-front plane
Earliest failing fixture: Plane
Missing design contract: authoritative local lattice phase and directed front ownership
Material-progress condition: phase-labelled source-attached cells are consumed by arrangement, and the next artifact can test direct plane acceptance
Deferred work: all Gate 2+ work, fan-interval repair, caches, memory, scheduling, performance, broad test cleanup
```

Do not substitute a different objective during the turn.

## Goal

Create a compile-valid general producer path that:

1. carries first-class local phase and lattice coordinates;
2. owns directed front edges explicitly;
3. seeds and advances a uniform source-attached front on the plane;
4. constructs a quad only from four phase-compatible source-attached corners and ordered sides;
5. passes already-decided cells to arrangement;
6. prevents arrangement from inventing new-path connectivity through pair-local fan-sector inference.

No fixture names, source IDs, expected counts, or geometry-specific thresholds may enter production code.

## Scope A — authoritative lattice and front state

Add project-convention equivalents of:

```cpp
struct LocalLatticeState {
    Eigen::Vector2d phase;
    Eigen::Vector2i latticeCoordinate;
    int branchRotation = 0;
    int scaleLevel = 0;
};

struct SurfaceFrontEdge {
    SurfacePoint from;
    SurfacePoint to;
    int fieldFamily = 0;
    int advanceSign = 1;
    LocalLatticeState lattice;
    int unfilledSide = 0;
    SourceRouteIdentity route;
};
```

Requirements:

- first-class, not reconstructed from diagnostics;
- serializable and deterministically hashable;
- complete component, local-sheet, source-chart, family, sign, and route provenance;
- missing or inconsistent state fails closed.

## Scope B — source-chart phase transport

Reuse the existing source-chart transition and cross-field matching services to transport:

- quarter-turn branch rotation;
- selected field family and sign;
- local phase;
- integer lattice coordinate;
- component and local-sheet identity;
- route provenance.

A transition is accepted only when source entity, orientation, component, local sheet, and matching agree. Do not use world-space proximity to select a chart or sheet.

This turn only needs the transport required by the uniform plane proof, but the implementation must be general across adjacent source triangles.

## Scope C — bounded uniform front producer

Implement only these event types:

```text
CompatibleFrontMerge
BoundaryTermination
HardRailCapture
PhaseMismatch
PeriodicHolonomyConflict
```

For Gate 1:

1. Tessellate and seed the authoritative source boundary.
2. Assign deterministic lattice coordinates and phase to boundary/front state.
3. Advance an open front edge by one uniform target size through intrinsic surface walking.
4. Construct four authoritative source-attached corners and four ordered boundary arcs.
5. Accept a cell only when phase, family, orientation, ownership, and provenance are compatible.
6. Give each directed front edge one filled side or explicit exterior classification.
7. Emit already-decided embedded cells or front cycles.

No post-hoc cycle decomposition, positional merging, or fan-interval pairing may construct the new-path cell.

## Scope D — arrangement materialization boundary

Add or isolate an arrangement entry that consumes already-decided cells.

Arrangement may:

- canonicalize embedded source identities;
- split exact crossings;
- stitch adjacent chart representations;
- materialize twins, next links, cycles, and cell IDs;
- validate topology and provenance.

Arrangement must not choose the intended sides of a cell through angular interval ranking, identity frequency, count/order rules, or unrelated fan identities.

Preserve the existing path behind an internal boundary while Gate 1 is incomplete; do not delete validated source-provenance, extraction, or validation infrastructure.

## Scope E — minimal test/build integration

Allowed test changes are limited to:

- compiling the new first-class types and producer path;
- preserving or extending the four direct acceptance cases without weakening them;
- adding focused Gate 1 invariants needed for the next artifact-only turn;
- moving a test only when it otherwise blocks compilation of the approved design-aligned targets.

Defer unrelated test-hygiene work. Do not spend this constructive turn repairing historical, performance, cache-accounting, or invalid downstream fixtures unless they are direct compile blockers.

## Explicitly deferred work

Do not implement in this turn:

- pair-local fan interval projection or repair;
- new ownership or diagnostic taxonomies for existing failures;
- multi-face seam acceptance logic beyond general chart transport required by Scope B;
- close-sheet, cylinder, torus, sphere, thin-tube, mechanical, or bunny-specific work;
- adaptivity or 2:1 transitions;
- general FlowRep simplification;
- general topology-distinct completion catalog;
- cache reuse, recomputation accounting, memory compaction, scheduling, or performance optimization;
- source-grid recovery enhancement.

## Compile-only verification

Compile exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Use Release `-O2 -DNDEBUG`, static libraries, recursive shallow submodules, and `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`.

Package:

- five executables;
- two libraries;
- fixture/input closure;
- exact source archive;
- source and workflow-event commits;
- compile database;
- detailed configure/build/activity logs;
- checksum manifest;
- execution policy proving no generated binary ran.

## Code + Build exit criteria

The turn is complete only when:

- the Gate 1 types and producer path compile;
- source-chart phase transport is consumed by the producer;
- already-decided cells reach the arrangement materialization boundary;
- the new path does not invoke fan-sector inference to decide cell connectivity;
- all approved targets compile and link;
- no test or benchmark executable is run;
- a self-contained artifact and logs are published;
- TODO, milestone, plan, handoff, runtime authority, and PR status identify Gate 1 as the next artifact-only test target.

A compile-only turn does not claim plane success.

## Next Test + Benchmark turn

Run in causal order:

1. plane direct acceptance;
2. multi-face seam only after plane evidence is recorded;
3. close sheets only after seam evidence is recorded;
4. cylinder only after close-sheet evidence is recorded;
5. remaining default suites.

The direct fixtures must still use `SurfaceCells`, fallback `Fail`, recovery disabled, and strict source-authoritative validation.

### Material-progress gate

Material progress requires one of:

- plane passes direct acceptance; or
- the plane's earliest invalid stage advances because authoritative phase/front state is live and consumed; or
- a general missing front-ownership invariant is exposed with direct evidence that cannot be represented by the old fan-interval path.

A different diagnostic string, counter, hash, interval subtype, or aggregate pass count is not progress.

## No-progress rule

If this turn and the following Code + Build turn both fail to advance Gate 1 materially, the next turn must be a design review or bounded producer replacement proof. Do not continue an equivalent micro-repair sequence.

## Preserved prohibitions

- no validator weakening;
- no fallback or source-grid recovery substitution;
- no fixture, ID, geometry, or expected-count special cases;
- no arbitrary subset search;
- no count/order/frequency ownership selection;
- no positional merging across unrelated sheets;
- no post-hoc cycle decomposition or cell merging;
- no synthetic counters or Euler correction;
- no timeout-as-correctness.
