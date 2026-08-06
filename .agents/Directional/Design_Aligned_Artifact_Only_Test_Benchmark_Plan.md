# Design-Aligned Artifact-Only Test + Benchmark Plan

**Artifact:** `8974081923`  
**Artifact SHA-256:** `4166325a2f38fa17d05d0d7e71cb147760a1e5208a6e971f60c35665bf3671de`  
**Exact source:** `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`  
**Workflow run/job:** `31118705108` / `92674426941`

## Purpose

Establish the first runtime baseline for the design-aligned default suite. The
turn must determine whether the direct surface-cell producer satisfies the four
analytic acceptance fixtures and then measure the remaining default contracts
without allowing aggregate pass count to obscure producer failure.

## Artifact-only restrictions

- Download artifact `8974081923` through the GitHub connector.
- Verify the outer SHA-256 and all internal `SHA256SUMS` entries before any
  binary execution.
- Extract into a clean arbitrary directory.
- Execute packaged binaries only.
- Do not configure, compile, relink, patch, regenerate, or modify source, tests,
  fixtures, validators, CMake, or workflow logic.
- Do not run legacy or historical suites.
- Do not treat fallback, source-grid recovery, timeout, or a reduced test count
  as direct producer success.

## Execution order

### 1. Package verification

Verify:

- `SOURCE_COMMIT` equals `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- `WORKFLOW_EVENT_COMMIT` equals
  `b412c8f78a7b597b204b52efbb64afc9899d6517`;
- 49 internal checksum entries pass;
- tracked source status is empty;
- nine recursive submodules are recorded;
- all four test executables, benchmark executable, two libraries, and 26
  fixture/input files exist.

### 2. Direct producer acceptance first

Run only the parameterized `SurfaceCellDesignAcceptance` cases, individually and
in this order:

```text
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Plane
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/MultiFaceSeam
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/CloseSheets
UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder
```

Run each case in a fresh process and retain complete stdout/stderr, exit code,
elapsed time, terminal failure code/stage, trace segment count, arrangement cell
count, completed quad count, backend identity, fallback flag, recovery flag, and
output origin.

Repeat any nondeterministic-looking case in at least three independent processes.
A direct acceptance pass requires all assertions in the compiled test:

- success;
- requested/executed backend `SurfaceCells`;
- no fallback attempt;
- a surface-cell remesh occurred;
- no source-grid recovery;
- output origin `CompletedSurfaceCells`;
- terminal failure code `None`;
- non-empty pure-quad output.

Report these four results separately before any aggregate totals.

### 3. Remaining default producer tests

Run the full `directional_surface_cell_producer_tests` executable after the four
isolated cases. Separate the four direct acceptance cases from the remaining
producer-unit result in the report.

### 4. Completion, validation, and API

Run, each in its own process:

- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_compiled_api_tests`.

Report suites independently and as a non-overlapping combined inventory.

### 5. Benchmark disposition

Do not use benchmark success as a correctness substitute. Run only the bounded
benchmark cases needed to capture stage timing and diagnostic context for the
first authoritative failed direct fixture after tests establish its failure.
Do not expand to torus, sphere, thin tube, mechanical feature, or random bunny
as acceptance work unless plane, seam, close sheets, and cylinder all pass.

## Required report

Produce a concise runtime summary containing:

1. Exact package/source authority and checksum verification.
2. Four direct acceptance results in required order.
3. First authoritative producer failure with full diagnostic context.
4. Remaining producer-unit total.
5. Completion, validation, and API totals.
6. Complete non-overlapping default-suite inventory.
7. Any deterministic repeat evidence.
8. Bounded benchmark result for the first failed fixture, when useful.
9. Explicit statement that no rebuilding or test modification occurred.
10. Next Code + Build plan driven by the first authoritative producer failure.

The next implementation plan must follow `DESIGN.md`, `REORIENTATION_PLAN.md`,
and `tests/TESTING_STRATEGY.md`. Do not resume pair-local fan-interval
micro-repair merely because a demoted historical test remains available.
