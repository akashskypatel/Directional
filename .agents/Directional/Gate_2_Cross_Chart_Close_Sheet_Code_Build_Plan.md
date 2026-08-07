# Gate 2 Cross-Chart and Close-Sheet Propagation — Code + Build Plan

## Turn type

Code + Build. Configure and compile only the approved targets. Do not execute generated tests, benchmarks, discovery, CLI, GUI, help, list, or project runtime commands.

## Active gate

**Gate 2 — Cross-chart and close-sheet propagation**

## Earliest failing fixture

`multi_face_seam__surface_cells`

Current exact evidence:

- trace segments: 137;
- arrangement/simplified cells: 0/0;
- completed quads: 0;
- terminal: `NotProductionReady:completion`;
- completion reason: `SideSubdivisionRepair:InvalidInputIncidence`;
- fallback attempted: false;
- source-grid recovery used: false.

`close_sheets__surface_cells` is the second Gate 2 fixture and remains at the same zero-cell completion boundary with 158 trace segments.

## Missing design contract

The Gate 1 producer uses a single planar phase frame. It does not yet construct and transport authoritative phase-front state across source-face charts. Gate 2 requires exact source-topology transitions carrying:

- `SourceChartId` or an equivalent authoritative chart identity;
- component and local-sheet provenance;
- selected cross-field branch and quarter-turn matching;
- phase and integer lattice coordinates;
- field family and advance sign;
- ordered source route and transition witness;
- deterministic structural identity.

World-space proximity cannot select a chart, sheet, branch, or connectivity relation.

## Smallest general implementation change

Extend the constructive phase front from the planar single-chart proof to exact adjacent source-chart transport while preserving the Gate 1 oriented direct-cell path.

### 1. First-class chart state

Add source-chart identity and transition provenance to the authoritative lattice/front state. The state must be deterministic and included in structural hashes. Do not infer chart identity from the final corner position.

### 2. Exact transition graph

Use the existing `SourceChartTransitionGraph`, exact source topology, component labels, local-sheet labels, hard-feature barriers, and cross-field edge matching/transition data.

For every face crossing:

- resolve one exact admissible source transition;
- transport barycentric support through the transition;
- transport branch rotation by the authoritative quarter-turn matching;
- transport phase, integer lattice coordinate, family/sign, component, sheet, and route state coherently;
- verify the reverse transition is the exact inverse;
- fail closed when transition or matching data is absent, ambiguous, or inconsistent.

### 3. Intrinsic front advance

Advance one target-size step through a sequence of source charts rather than projecting a global planar grid. A side path may cross source-face boundaries, but every segment must retain its chart and route witness.

The multi-face seam fixture must be produced by this general transport. Do not special-case fixture names, face IDs, edge order, or expected counts.

### 4. Compatible merge across charts

Two directed fronts may merge only when authoritative transport proves:

- reciprocal source routes;
- compatible canonical chart transition;
- equal transported integer lattice coordinate and phase;
- compatible branch/family/sign state;
- equal component and intended local-sheet identity;
- reciprocal filled-side ownership.

Emit `CompatibleFrontMerge` only after these checks. Emit `PhaseMismatch` and fail closed for incompatible state. Do not rank candidates by count, order, distance, or frequency.

### 5. Close-sheet isolation

For `close_sheets__surface_cells`:

- permit exact manifold transitions inside the intended source component;
- retain local-sheet identity in every state, hash, and merge decision;
- never capture or merge a geometrically close but topologically unrelated sheet;
- reject positional canonicalization across unrelated source support.

### 6. Preserve Gate 1 direct materialization

Every accepted four-sided cross-chart cell must use the existing source-normal orientation, complete-cycle reversal, directed-edge ownership, and one-cell-to-one-quad materialization path.

Do not route accepted cells through generic completion. Do not weaken the plane gate.

## Required compile-time test additions

Add or update focused tests only where needed to compile the new contract:

- identity chart transition;
- forward/reverse transition round trip;
- quarter-turn branch/family transport;
- phase and integer-coordinate preservation across an exact seam;
- missing or inconsistent transition fails closed;
- local-sheet identity prevents close-sheet capture;
- source face/edge permutation preserves the structural result;
- the four direct acceptance tests remain unchanged in strength.

Do not execute them in this turn.

## Material-progress condition for the next artifact

The next Test + Benchmark turn must show at least one of:

1. multi-face seam direct `CompletedSurfaceCells` success with non-empty pure quads, zero strict validation failures, no fallback, and no recovery; or
2. nonzero authoritative cross-chart cells with deterministic chart/phase transport that fail closed at a new first-class transport or direct-materialization boundary before generic completion.

A different completion diagnostic, extra counters, or unchanged zero-cell output is not material progress.

## Explicitly deferred

- Gate 3 cylinder periodic closure and holonomy;
- topology-distinct completion and singularities;
- adaptive 2:1 transitions;
- hard-feature production cases;
- sphere, torus, thin tube, mechanical, and bunny acceptance;
- performance, cache, scheduler, parallelism, and memory optimization;
- historical completion-fixture cleanup unless required for compilation;
- source-grid recovery enhancements.

## Compile boundary

Configure Release, static, `-O2 -DNDEBUG`, Ninja, shallow recursive submodules, and `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`.

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Package five executables, two libraries, the exact source archive, all required fixtures, metadata, logs, and checksums. Execute no generated binary.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
