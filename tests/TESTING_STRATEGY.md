# Surface-Cell Testing Strategy

## Purpose

The default test suite measures progress toward direct, production-ready `SurfaceCells` paving. Historical diagnostics, repair bookkeeping, cache details, timing ratios, and aggregate pass counts cannot outweigh a failed direct design gate.

The primary question is:

> Does the direct `SurfaceCells` producer construct valid source-authoritative pure-quad output for the earliest active design gate?

## Gate-first execution order

Run and report direct fixtures before aggregate totals:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder;
5. later topology, feature, adaptive, and production fixtures only after preceding gates pass.

Do not skip a red analytic gate and use a more complex fixture as the main progress signal.

Each direct acceptance case requires:

- requested and executed backend `SurfaceCells`;
- fallback policy `Fail`;
- no fallback attempt;
- source-grid recovery disabled;
- output origin `CompletedSurfaceCells`;
- non-empty pure-quad output;
- complete source provenance;
- strict source-authoritative validation;
- deterministic structural output.

Fallback, recovery, partial cells, legacy output, input return, and timeout do not satisfy a direct gate.

## Active Gate 1 contract

The plane now exercises first-class phase-front production. Current evidence is 352 traces, 65 arrangement cells, and 409 completed quads, followed by `completion/output-validation:FlippedFace`.

Gate 1 tests must protect:

- first-class phase and integer lattice coordinates;
- deterministic directed front ownership;
- exactly one filled side or explicit exterior classification per directed front edge;
- four distinct source-attached corners;
- four ordered side paths with endpoint continuity;
- nonzero intrinsic signed area;
- source-normal-consistent winding;
- coherent component, chart, local-sheet, route, phase, family, and sign state;
- transactional whole-cycle reversal when winding is opposite;
- one accepted four-sided phase-front cell mapping to one intended quad-domain cell;
- fail-closed behavior before completion on invalid orientation or incidence;
- arrangement materialization of already-decided topology;
- no fan-sector inference, positional merge, or generic patch expansion of an authoritative cell.

## Default suites

### `directional_surface_cell_producer_tests`

Protects bounded source preconditioning, field construction and matching, source-chart/component/sheet authority, lattice/front construction, direct cell ownership, and direct design-gate acceptance. This is the primary production correctness authority.

### `directional_surface_cell_completion_tests`

Protects valid FlowRep selection, transactional simplification, patch feasibility, and topology-distinct completion. Completion tests cannot substitute for producer success.

### `directional_surface_cell_validation_tests`

Protects source-constrained optimization and strict source-authoritative validation. Validation remains fail closed.

### `directional_compiled_api_tests`

Protects the compiled public API independently of meshing quality.

## Correct stale producer expectations

Two current producer tests must be corrected in the next Code + Build turn:

1. `AdaptiveTargetSizePhase12.SurfaceCellScaffoldPopulatesSizeDiagnostics` must verify meaningful sizing diagnostics without assuming production failure.
2. `SurfaceCellsPhase10.SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture` must not require recovery when direct SurfaceCells succeeds. Use a true recovery-required fixture or separate direct-success and recovery-only scenarios.

These corrections must not weaken the four direct acceptance tests or remove genuine recovery coverage.

## Later gate coverage

### Gate 2 — Cross-chart and close-sheet propagation

Protect authoritative phase/lattice transport, quarter-turn matching, deterministic source permutations, and zero cross-sheet capture or merge.

### Gate 3 — Periodic closure

Protect explicit phase holonomy, deterministic periodic reconciliation, complete directed incidence, and cylinder closure.

### Gate 4 — Topology-distinct completion

Protect distinct topology graphs, intentional singularity placement, supported 3–6-sided completion, and rejection of generic center-fan production fallback.

### Gate 5 — Adaptive transitions and features

Protect dyadic scale levels, 2:1 grading, validated pure-quad transitions, structural hard-feature rails, and absence of T-junctions or sheet jumps.

### Gates 6–7 — General production and hardening

Protect deterministic bunny success, complete production fixtures, parallel equivalence, performance, and memory only after constructive correctness.

## Non-default coverage

Historical, legacy-integration, and optional-guidance suites may be enabled for focused investigation, but they cannot block or outweigh the active direct design gate unless they expose a currently required production invariant.

Scheduler-sensitive wall-clock ratios, exact cache/recomputation counters, superseded route-repair machinery, and milestone bookkeeping belong in benchmark, closeout, or historical coverage rather than default correctness.

## Test validity rules

A default test is valid when its failure means a current or already-passed production contract is broken: source topology, boundaries, features, components, sheets, field transport, front construction, directed incidence, direct cell ownership, topology-distinct completion, source validity, or determinism.

Demote, reconstruct, or remove a default test when it only checks:

- a superseded milestone;
- an exact diagnostic, counter, ordinal, cache layout, memory inventory, or recomputation count;
- fallback or recovery as direct success;
- scheduler-sensitive timing;
- an invalid synthetic fixture that does not create its claimed precondition.

Fixtures must create valid source-supported geometry and reach the behavior they claim to test. Do not synthesize counters, weaken assertions, or special-case fixture identifiers.

## Turn boundaries

### Code + Build

- May edit implementation, tests, and build logic required by the active gate.
- Compiles only approved targets.
- Executes no test, benchmark, discovery, CLI, GUI, help/list, or generated project binary.

### Test + Benchmark

- Uses an exact packaged artifact.
- Performs no configure, compile, relink, regeneration, or source/test/fixture/validator edit.
- Preserves raw logs and machine-readable results.
- Runs each direct case in a fresh process and reports direct results before aggregate totals.

## Material-progress classification

A test turn shows material progress only when at least one is true:

- the active direct fixture passes;
- the earliest direct failure advances because a missing design contract is live and consumed;
- a general phase/front/topology invariant replaces an underdetermined repair;
- a structural ambiguity is removed without an equivalent downstream ambiguity.

Different wording, a new hash, a higher aggregate count caused by demotion, faster failure, stable cache metrics, or fixture-specific behavior are not sufficient.

If two consecutive Code + Build turns do not materially advance the active gate, the next turn must be a design review or bounded producer replacement proof.

## GitHub outage rule

While the current GitHub workflow outage persists, do not use Actions workflows for repository updates. Keep exact source-patch synchronization on project TODOs. Local artifact testing is authoritative only when artifact, source, patch, dependency, fixture, and checksum closure are verified.

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
