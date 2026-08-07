# Surface-Cell Testing Strategy

## Purpose

The default test suite measures progress toward direct, production-ready `SurfaceCells` paving. Historical diagnostics, repair bookkeeping, cache details, timing ratios, and aggregate pass counts cannot outweigh a failed direct design gate.

The primary question is:

> Does the direct `SurfaceCells` producer construct valid source-authoritative pure-quad output for the earliest active design gate?

## Gate-first execution order

Run and report direct fixtures before aggregate totals:

1. plane — passed and retained as a regression gate;
2. multi-face seam — active first Gate 2 fixture;
3. close sheets — active second Gate 2 fixture;
4. cylinder — blocked until Gate 2 passes;
5. later topology, feature, adaptive, and production fixtures only after preceding gates pass.

Each direct acceptance case requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, `CompletedSurfaceCells`, non-empty pure quads, complete source provenance, strict validation, and deterministic structural output.

Fallback, recovery, partial cells, legacy output, input return, and timeout do not satisfy a direct gate.

## Passed Gate 1 contract

The plane now protects:

- first-class phase and integer lattice coordinates;
- deterministic directed front ownership;
- exactly one filled side or explicit exterior classification per edge;
- four distinct source-attached corners and ordered side paths;
- source-normal-consistent winding and transactional whole-cycle reversal;
- coherent component, local-sheet, phase, family/sign, and route state;
- one accepted four-sided cell mapping to one output quad;
- direct materialization without generic patch expansion;
- zero strict validation failures and deterministic output.

Exact evidence: 64 direct cells, 64 pure quads, 81 vertices, output hash `730caeae49ec872c`, no fallback/recovery.

## Active Gate 2 contract

Gate 2 tests must protect:

- exact source-chart identity in constructive state;
- exact source-topology transition witnesses;
- forward/reverse transition round trips;
- authoritative cross-field quarter-turn branch transport;
- phase and integer lattice-coordinate transport across source faces;
- component, local-sheet, family/sign, and route preservation;
- compatible reciprocal front merging across charts;
- fail-closed missing/ambiguous/inconsistent transitions;
- deterministic results under face/edge/source permutations;
- zero positional capture or merging across close unrelated sheets;
- preservation of Gate 1 direct orientation and one-cell-to-one-quad materialization.

## Default suites

### `directional_surface_cell_producer_tests`

Primary production correctness authority for source topology, field construction/matching, chart/component/sheet authority, lattice/front construction, direct ownership, and direct design-gate acceptance.

### `directional_surface_cell_completion_tests`

Protects valid FlowRep selection, transactional simplification, patch feasibility, and intentionally topology-distinct completion. Completion tests cannot substitute for producer success.

### `directional_surface_cell_validation_tests`

Protects source-constrained optimization and strict source-authoritative validation. Validation remains fail closed.

### `directional_compiled_api_tests`

Protects the compiled public API independently of meshing quality.

## Non-default coverage

Scheduler-sensitive wall-clock ratios, exact cache/recomputation counters, superseded route-repair machinery, and milestone bookkeeping belong in benchmark, closeout, or historical coverage rather than default correctness.

`SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` is scheduler-sensitive and should be optional benchmark/closeout coverage. Its failure cannot outweigh valid direct gate evidence.

The historical implementation-detail tests `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` and `OneCandidateBudgetIsExactAndDoesNotRecurse` should remain non-default; they do not define current production behavior.

## Later gate coverage

- Gate 3: explicit phase holonomy, deterministic periodic reconciliation, complete directed incidence, cylinder closure.
- Gate 4: distinct topology graphs, intentional singularities, supported 3–6-sided completion, no generic center-fan production fallback.
- Gate 5: dyadic scale levels, 2:1 grading, hard-feature rails, no T-junctions or sheet jumps.
- Gates 6–7: deterministic bunny success, complete production fixtures, parallel equivalence, performance, and memory only after constructive correctness.

## Test validity rules

A default test is valid when its failure means a current or already-passed production contract is broken. Demote, reconstruct, or remove tests that only check a superseded milestone; exact diagnostics, counters, ordinals, cache layouts, memory inventories, or recomputation counts; fallback/recovery as success; scheduler-sensitive timing; or invalid fixtures that do not create their claimed precondition.

Fixtures must create valid source-supported geometry and reach the behavior they claim to test. Do not synthesize counters, weaken assertions, or special-case fixture identifiers.

## Turn boundaries

### Code + Build

May edit implementation, tests, and build logic required by the active gate. Compile only approved targets. Execute no generated project binary, test, benchmark, discovery, CLI, GUI, help, or list command.

### Test + Benchmark

Use an exact packaged artifact. Perform no configure, compile, relink, regeneration, or source/test/fixture/validator edit. Preserve raw logs and machine-readable results. Run each direct case in a fresh process and report direct results before aggregate totals.

## Current inventory

The latest exact artifact produced direct acceptance **1/4**, remaining producer **78/79**, completion **154/164**, validation **60/60**, compiled API **8/8**, and a non-overlapping total of **301/315**. The plane passed; seam and close sheets define active Gate 2.

## Material-progress classification

A test turn shows material progress only when the active direct fixture passes, the earliest failure advances because a missing first-class contract is live, or a structural ambiguity is removed without an equivalent downstream ambiguity.

Different wording, a new hash, higher aggregate counts, faster failure, or fixture-specific behavior are insufficient.

If two consecutive Code + Build turns do not materially advance the active gate, the next turn must be a design review or bounded producer replacement proof.

## Preserved prohibitions

- no validator weakening;
- no fixture/ID special cases;
- no fallback/recovery substitution;
- no positional merging across unrelated sheets;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no synthetic counters or Euler correction;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.

Every report must state the active direct-gate result separately from the complete non-overlapping inventory.
