# Surface-cell testing strategy

## Purpose

The test suite protects the constructive path in `.agents/Directional/DESIGN.md` and enforces its gate order.

The default suite answers one primary question:

> Does the direct `SurfaceCells` producer construct valid source-authoritative pure-quad output for the earliest active design gate?

A diagnostic change, ownership classification, counter, hash, cache result, memory metric, or aggregate pass-count increase is not production progress by itself.

## Gate-first execution policy

Only one direct design gate is active at a time.

Current active gate:

```text
Gate 1 — Uniform phase-front plane
```

Every Test + Benchmark turn must:

1. run the active direct fixture first in a fresh process;
2. report its terminal stage and constructive counts before aggregate totals;
3. determine whether the gate exit criteria passed;
4. run later analytic fixtures only after the active fixture evidence is recorded;
5. classify downstream unit failures separately from direct producer acceptance.

Do not skip a red analytic gate to run a more complex acceptance fixture as the main progress signal.

## Direct gate sequence

```text
Gate 1: plane
Gate 2: multi-face seam → close sheets
Gate 3: cylinder
Gate 4: prescribed sphere and torus/reduced topology cases
Gate 5: thin bent tube and mechanical feature
Gate 6: bunny_1k_random
Gate 7: production benchmark and hardening matrix
```

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

Fallback, recovery, partial cells, legacy output, input return, and timeout do not satisfy a gate.

## Default suites

### `directional_surface_cell_producer_tests`

Protects:

- bounded source-mesh preconditioning;
- cross-field construction, matching, and transport;
- source-chart, component, and local-sheet authority;
- local lattice phase and directed front ownership;
- direct design-gate acceptance.

The producer suite is the primary correctness authority.

### `directional_surface_cell_completion_tests`

Protects:

- FlowRep strand and cycle selection on valid embedded input;
- transactional complex simplification;
- patch descriptor feasibility;
- topology-distinct pure-quad completion.

Completion tests do not substitute for producer success. A completion unit test may pass while the active direct producer gate remains red.

### `directional_surface_cell_validation_tests`

Protects source-constrained optimization and strict source-authoritative validation.

Validation must remain fail closed. Test failures may not be resolved by weakening topology, provenance, feature, sheet, or quality requirements.

### `directional_compiled_api_tests`

Protects the compiled public API independently of meshing quality.

## Gate-specific required tests

### Gate 1 — Uniform phase-front plane

Protect:

- first-class phase and integer lattice coordinates;
- deterministic front-edge ownership;
- one filled side or explicit exterior side per directed front edge;
- intrinsic source walking;
- four ordered phase-compatible sides per accepted cell;
- arrangement materialization of already-decided cells;
- absence of fan-sector inference on the new producer path.

### Gate 2 — Cross-chart and close-sheet propagation

Protect:

- phase and lattice transport across source edges and vertices;
- quarter-turn matching and orientation correction;
- deterministic face-row/orientation permutations;
- zero cross-sheet capture, merge, or projection.

### Gate 3 — Periodic closure

Protect:

- explicit phase holonomy;
- deterministic periodic reconciliation;
- valid predecessor/successor incidence;
- disk-cell and seam closure.

### Gate 4 — Topology-distinct completion

Protect:

- distinct topology graphs rather than rotations/reversals;
- strip routing and pole placement;
- 3–6-sided feasibility;
- intentional singularity-index accounting;
- no center-fan production fallback.

### Gate 5 — Adaptive transitions and features

Protect:

- dyadic levels and 2:1 grading;
- validated pure-quad transition templates;
- structural hard-feature rails;
- no final T-junctions or sheet jumps.

### Gates 6–7 — General production and hardening

Protect:

- deterministic bunny success;
- complete production fixture matrix;
- component scheduling and parallel equivalence;
- performance, memory, and benchmark stability only after constructive correctness.

## Non-default suites

### Historical tests

Enable with:

```text
-DDIRECTIONAL_BUILD_HISTORICAL_TESTS=ON
```

Historical tests may protect milestone closure, exact diagnostics, route-repair machinery, cache accounting, or implementation details. They are useful for targeted investigation but cannot block or outweigh the active direct design gate unless they expose a currently required production invariant.

### Legacy integration tests

Enable with:

```text
-DDIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS=ON
```

These remain valid for the legacy backend but do not establish direct surface-paving correctness.

### Optional guidance tests

Enable with:

```text
-DDIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS=ON
```

Relief, skeleton, and other optional guidance must not block the uniform phase-front proof.

## Test validity rules

Keep a test in the default suite only when its failure means a current or already-passed production contract is broken:

- source topology, boundaries, features, components, or local sheets;
- cross-field matching, phase transport, or singularity budget;
- front construction or direct cell ownership;
- manifold directed incidence and disk-cell extraction;
- topology-distinct completion;
- source-constrained geometric validity;
- deterministic output for equivalent inputs.

Demote, reconstruct, or remove a default test when it only checks:

- a superseded milestone number;
- an exact diagnostic string, counter, ordinal, cache layout, memory inventory, or recomputation count;
- repeated execution already covered elsewhere;
- fallback or recovery as direct success;
- scheduler-sensitive wall-clock ratios;
- an invalid synthetic fixture that does not create the stated precondition.

Fixtures must create valid source-supported geometry and reach the behavior they claim to test. Do not synthesize counters or weaken assertions to preserve an invalid fixture.

## Progress classification

A test turn shows material progress only when at least one is true:

- the active direct fixture passes;
- the earliest direct failure advances because a missing design contract is live and consumed;
- a general front/phase/topology invariant replaces an underdetermined repair;
- a previously equivalent ambiguity is removed without an equivalent downstream failure.

The following are not sufficient:

- different failure wording;
- different diagnostic hash;
- a higher aggregate pass count caused by demotion;
- faster failure;
- stable cache or memory counters;
- fixture-specific behavior.

## No-progress escalation

When two consecutive Code + Build turns do not materially advance the active gate, the next turn must be a design review or bounded producer replacement proof. Tests should then compare the implementation directly to the stage contracts in `DESIGN.md`, not add more implementation-coupled diagnostics.

## Performance and memory

Performance and memory are benchmark/closeout gates. They become blocking only after the applicable constructive fixtures pass.

Do not optimize a failing producer unless the optimization is required to execute the active correctness fixture within an explicit bounded resource limit.

## Verification commands

Configure the default design-aligned suite:

```text
cmake -S . -B build -G Ninja \
  -DDIRECTIONAL_BUILD_TESTS=ON \
  -DDIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF \
  -DDIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS=OFF \
  -DDIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS=OFF
```

Build:

```text
cmake --build build --target \
  directional_compiled_api_tests \
  directional_surface_cell_producer_tests \
  directional_surface_cell_completion_tests \
  directional_surface_cell_validation_tests
```

Run:

```text
ctest --test-dir build --output-on-failure -L "api|surface-cell"
```

Every report must state the active gate result separately from the complete non-overlapping inventory.
