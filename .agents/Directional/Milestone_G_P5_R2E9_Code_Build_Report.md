# Milestone G P5-R2E9 Code + Build Report

**Date:** 2026-08-05  
**Turn type:** Code + Build, compile-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`

## Result

P5-R2E9 canonical boundary wrap-sector and bounded rail-orbit chart publication is implemented and the four approved targets compile successfully.

Runtime acceptance is intentionally not claimed. The next turn is P5-TB37 artifact-only Test + Benchmark.

## Exact authority

- workflow event commit: `29e71770a3c2ff001fa6daa687a2bdf957dd79c4`;
- exact compiled source commit: `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c`;
- workflow run: `31046039110`;
- job: `92441663510`;
- build artifact: `8946700183`, `surface-cell-p5-r2e9-github-source-linux-release`;
- build artifact SHA-256: `bae182ef1e3e5fbbc9fff25ea60a56821e31e4e6fe81787137cdac58f30c6a3a`;
- log artifact: `8946700685`, `surface-cell-p5-r2e9-workflow-logs-31046039110`;
- log artifact SHA-256: `03e137c8af8c41a24595ba1176a3e575fe8da34c44c4605d352a2c9629117e37`;
- configuration: Release, `-O2 -DNDEBUG`;
- compile/link actions: **132/132**;
- recursive submodules: **9**;
- artifact manifest entries: **19/19 verified**;
- packaged files: **20**, including the manifest.

### Exact changed blobs

- `src/geometry/SurfaceArrangement.cpp`: `fec7b37c0692a0e23d28727d8fad60215bd7fa6c`;
- `include/directional/geometry/SurfaceArrangement.h`: `b172625cd82862d16b81b6f3b8d52686b5fda41c`;
- `tests/SurfaceArrangementPhase16Tests.cpp`: `e58bceda098f7768b8a7203cca00564f82a7d831`;
- `tests/MilestoneDClosureTests.cpp`: `e673e60133a39ddfc657fc9bc65ce538a5147930`.

The packaged source status is empty. The compiled source commit is the exact commit pushed before CMake configuration and compilation.

## Implementation

### Canonical cyclic fan-pair inventory

For affected higher-valence source-boundary nodes, the arrangement producer now:

1. enumerates every adjacent pair from the authoritative R1 fan's canonical cyclic ray order before chart filtering, including vector wrap;
2. converts each canonical pair to its directed incoming/source/target relation;
3. resolves non-exterior pairs to exactly one supporting source-face/chart corner with the required intrinsic orientation;
4. removes the independently proven exterior pair exactly once;
5. rejects missing, duplicated, or conflicting incoming/target claims transactionally;
6. publishes derived canonical-pair, exterior-exclusion, and wrap-sector diagnostics only after the complete local audit succeeds.

Chart-local angle ordering remains evidence for an exact corner witness; it no longer defines or truncates the canonical pair inventory.

### Hard-rail bounded-orbit roots

Each accepted hard-rail side now carries its exact selected source-chart root through the complete predicted bounded successor orbit. Publication requires every halfedge in that orbit to support the same root through the source-chart transition graph. Root loss, root change, exterior entry, barrier crossing, conflict with another orbit, or failure to close rejects the candidate transactionally.

`SurfaceArrangementHalfedge::authoritativeChartRoot` stores this directed-orbit embedding authority. Full per-halfedge provenance remains separate and unchanged. Materialized bounded cells use the one accepted orbit root as authoritative embedding support; opposite hard-rail bounded cells must retain distinct incident roots.

### Focused semantic evidence

Existing arrangement tests were strengthened without fixture IDs or expected-output embedding:

- planar checks now require a positive canonical fan-pair inventory and exactly one accepted exterior exclusion per affected sector node;
- hard-rail checks now require nonnegative, distinct authoritative roots on the two bounded rail sides and the same root on every halfedge of each corresponding bounded cell.

No Phase 17 test or implementation was modified.

## Compile gate

Compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No test, benchmark, custom mesh, help/list/discovery command, CLI, GUI, or generated project binary was executed.

## Workflow history

Initial run `31045700083` failed before patch application because the expected payload digest included a final newline that the first repository write omitted. Its unconditional log artifact is `8946331924`. The payload was corrected to the exact declared digest, then successful run `31046039110` verified both payload and decoded patch SHA-256 before applying any source change. The failed orchestration run is not product or compile evidence.

The bounded workflow and transfer payload were removed after successful artifact publication. Only the durable source-snapshot workflow remains.

## Scope deliberately unchanged

- cylinder and bunny producers;
- tracing and singularity-fan logic;
- FlowRep selection or simplification;
- patch completion;
- optimizer and cache;
- fallback and recovery behavior;
- memory accounting;
- downstream validators;
- Phase 17 implementation and tests.

## Next turn

Execute `.agents/Directional/Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Plan.md` using artifact `8946700183` without rebuilding or modifying source, tests, fixtures, validators, workflows, or build logic.

R2 remains open. Do not advance to R2F or R3 from compile evidence. PR #8 remains open, draft, and unmerged.
