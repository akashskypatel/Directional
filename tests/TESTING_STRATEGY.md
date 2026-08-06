# Surface-cell testing strategy

## Purpose

The default test suite protects the constructive path defined by
`.agents/Directional/DESIGN.md`:

1. Prepare source-attached field, feature, and metric inputs.
2. Construct a coherent direct surface paving.
3. Complete and simplify valid embedded cells.
4. Optimize on the source surface.
5. Pass source-authoritative validation.

A diagnostic change, ownership-classification change, cache result, or failure
hash change is not production progress by itself.

## Default suites

### `directional_surface_cell_producer_tests`

Protects the current critical path:

- bounded source-mesh preconditioning;
- cross-field construction and transfer;
- shared adaptive feature and target-size fields;
- direct `SurfaceCells` acceptance on plane, multi-face seam, close sheets, and
  cylinder.

The four acceptance fixtures must use:

- backend `SurfaceCells`;
- fallback policy `Fail`;
- source-grid recovery disabled;
- optional skeleton guidance disabled;
- direct `CompletedSurfaceCells` output;
- non-empty pure-quad output.

The acceptance order is intentional:

```text
plane
→ multi-face seam
→ close sheets
→ cylinder
```

Do not advance the authoritative producer gate to torus, prescribed sphere,
adaptive thin-tube, mechanical-feature, or random-bunny acceptance until these
four fixtures pass directly.

### `directional_surface_cell_completion_tests`

Protects FlowRep strand/cycle selection, embedded-complex simplification,
patch descriptor feasibility, and pure-quad completion. These tests do not
substitute for producer success.

### `directional_surface_cell_validation_tests`

Protects source-constrained optimization and final source-authoritative mesh
validation.

### `directional_compiled_api_tests`

Protects the public compiled-library surface independently of meshing quality.

## Non-default suites

The following tests remain available but no longer run as part of the default
surface-cell gate.

### Historical tests

Enable with:

```text
-DDIRECTIONAL_BUILD_HISTORICAL_TESTS=ON
```

This group contains milestone closure tests, broad diagnostic/lineage tests,
component scheduling, and detailed tracing/arrangement implementation tests.
They are useful for targeted regression investigation, but they must not
outweigh direct producer acceptance or duplicate the same translation units in
multiple default CTest targets.

### Legacy integration tests

Enable with:

```text
-DDIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS=ON
```

This group contains the mixed-integer integration path, integer batching and
transition-basis tests, targeted stiffening, legacy patch fallback, and legacy
remesh regression coverage. These remain valid for the legacy backend but do
not define acceptance of direct surface paving.

### Optional guidance tests

Enable with:

```text
-DDIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS=ON
```

Relief guidance remains optional and must not block the uniform phase-front
proof.

## Test validity rules

Keep a test in the default suite only when failure means at least one of the
following production contracts is broken:

- source topology, boundary, feature, component, or local-sheet authority;
- cross-field matching or singular-index consistency;
- phase/front construction or direct cell ownership;
- manifold directed incidence and disk-cell extraction;
- topology-distinct pure-quad completion;
- source-constrained geometric validity;
- deterministic output for equivalent input ordering.

Demote or remove a default test when it only checks:

- a superseded milestone number;
- an exact diagnostic string, counter, hash, ordinal, cache layout, or memory
  accounting implementation;
- repeated execution of a test already present in another default target;
- fallback or recovery output as evidence of direct `SurfaceCells` success;
- a synthetic fixture that is invalid before reaching the behavior it claims
  to test.

Performance and memory tests are benchmark/closeout gates. They become blocking
only after the direct analytic fixtures produce valid output.

## Verification commands

Configure the default design-aligned suite:

```text
cmake -S . -B build -G Ninja \
  -DDIRECTIONAL_BUILD_TESTS=ON \
  -DDIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF \
  -DDIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS=OFF \
  -DDIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS=OFF
```

Build the three surface-cell gates and API test:

```text
cmake --build build --target \
  directional_compiled_api_tests \
  directional_surface_cell_producer_tests \
  directional_surface_cell_completion_tests \
  directional_surface_cell_validation_tests
```

Run only the design-aligned tests:

```text
ctest --test-dir build --output-on-failure \
  -L "api|surface-cell"
```

A turn must report the direct acceptance result separately from unit-test totals.
A higher pass count caused by demoting duplicated or obsolete tests is not an
implementation success claim.

## Current compile authority

The design-aligned targets are compile-valid at source checkpoint
`e82fb47dccbefa1b878bc9ddff0ae63745f6efe9` in artifact `8974081923`.
Runtime acceptance is intentionally deferred to the artifact-only plan in
`.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Plan.md`.
