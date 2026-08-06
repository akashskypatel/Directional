# Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build Plan

**Active gate:** Gate 1 — Uniform phase-front plane  
**Earliest failing fixture:** plane  
**First authoritative failure:** `completion/output-validation:FlippedFace`, cell 38, source face 41  
**Missing design contract:** source-normal-oriented cell incidence and one-to-one materialization of already-decided four-sided cells  
**Material-progress condition:** the plane produces one valid direct quad-domain cell per accepted phase-front cell and advances beyond flipped output validation, preferably to direct success  
**Explicitly deferred:** G2+ fixtures and logic, fan-interval repairs, general completion catalogs, adaptivity, features, caches, memory, scheduling, and performance

## Current evidence

The phase-front patch is live and deterministic:

- previous plane: 106 traces, 9 arrangement cells, 12 completed quads;
- current plane: 352 traces, 65 arrangement cells, 409 completed quads;
- current failure: 100 strict validation failures, first `FlippedFace` at cell 38/source face 41;
- tracing, arrangement, and completion hashes stable across three fresh processes.

The next turn must correct the constructive contract, not add observability around the same defect.

## Scope A — authoritative cell orientation

Before a proposed phase-front cell becomes authoritative, require:

1. exactly four distinct source-attached corners;
2. four ordered side routes whose endpoints connect cyclically;
3. nonzero intrinsic signed area;
4. winding consistent with the authoritative source normal;
5. coherent component, source-chart, and local-sheet identity;
6. coherent phase, lattice coordinate, branch rotation, scale level, family, sign, and route provenance;
7. exactly one filled side or explicit exterior classification per directed front edge.

When winding is opposite, reverse the **entire cycle transactionally**:

- corner order and lattice states;
- side order and every side route direction;
- front-edge directions and ownership;
- field families and advance signs as required by the project orientation convention;
- event references and deterministic hash inputs.

Do not sort corners by position, source ID, incidence count, or arbitrary orientation heuristics.

## Scope B — direct-cell materialization

An accepted four-sided phase-front cell already defines intended topology. Materialize it as one quad-domain arrangement cell.

Arrangement may:

- canonicalize equivalent source identities;
- split exact crossings;
- materialize halfedges, twins, next links, cycles, and cell IDs;
- validate topology and provenance.

Arrangement/completion must not:

- choose intended connectivity through fan-sector ranking;
- merge unrelated sheets by position;
- route an authoritative four-sided cell through generic patch completion that expands it into new topology;
- perform post-hoc cycle decomposition or cell merging.

Preserve generic topology-distinct completion for intentionally non-four-sided supported regions, but keep it outside the direct four-sided phase-front path.

## Scope C — fail-closed stage boundary

Reject invalid cells before completion. Record the earliest failure when any orientation, incidence, ownership, route, component, chart, sheet, or phase invariant is inconsistent.

Do not emit partial authoritative cell state that later stages must guess or repair.

## Scope D — test-suite corrections

Allowed corrections:

1. `AdaptiveTargetSizePhase12.SurfaceCellScaffoldPopulatesSizeDiagnostics`: verify populated and valid sizing diagnostics without assuming the backend must fail.
2. `SurfaceCellsPhase10.SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture`: use a true recovery-required fixture for recovery-only assertions, or separate direct-success and recovery-only scenarios.

Requirements:

- preserve the four direct acceptance tests unchanged in strength;
- retain real recovery coverage;
- do not special-case fixture IDs or expected output counts;
- do not demote a test merely because the new producer violates a required contract.

## Compile-only verification

Compile exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

Use Release `-O2 -DNDEBUG`, static libraries, recursive submodules, and `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`.

Package five executables, two libraries, fixture closure, exact source/patch authority, compile database, logs, metadata, and recursive checksums.

Execute no generated binary, test, benchmark, help/list command, discovery, CLI, or GUI operation.

## Local build execution during outage

GitHub Actions remains unavailable for this project workflow path. Build locally from exact source composition and use extended timeouts. Prefer local ephemeral filesystem for compilation if the persistent mounted volume causes compiler I/O contention. Preserve logs and final artifacts under `/mnt/data`.

Do not use a workflow for source application, build, or repository updates while the outage persists.

## Remote synchronization backlog

The current exact Gate 1 patch remains pending on `TODO` and `MILESTONE_G_TODO.md` until GitHub service recovery. Do not modify or replace it while implementing the next incremental patch.

After recovery:

1. apply and commit the current exact five-file patch through direct Git objects or an authenticated local client;
2. verify all five expected Git blobs;
3. layer the orientation/direct-materialization patch as a separate coherent commit;
4. verify its source and build authority;
5. remove payload files only after all referenced source state is committed and verified.

## Exit criteria

The Code + Build turn is complete only when:

- orientation/incidence invariants are first-class and consumed;
- accepted four-sided cells bypass generic patch expansion;
- all seven targets compile and link;
- no generated binary executes;
- exact source and artifact evidence is packaged;
- the next artifact-only plan tests plane first.

Gate 1 is not complete until direct plane acceptance passes strict validation with non-empty pure-quad `CompletedSurfaceCells` output and no fallback/recovery.
