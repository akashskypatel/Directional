# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → **G2 cross-chart / close-sheet isolation [active]** → G3 cylinder/periodic holonomy → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Gate 1 closed by artifact-only validation

Exact authority:

- source commit `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- payload cleanup `bcf934d34e9a15f5d0929628ffd26f6833643214`;
- workflow run/job/artifact `31154489371` / `92790924907` / `8984760467`;
- artifact SHA-256 `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- 44/44 internal checksums passed;
- six explicit producer/topology contracts: 6/6 passed;
- no configure/compile/relink or source/test/fixture/validator edit during validation.

Gate 1 acceptance:

- plane: `Produced`, direct `CompletedSurfaceCells`, 81 provenance vertices, 64 pure quads, zero strict validation failures, no fallback/recovery, deterministic output hash suffix `730caeae49ec872c`;
- seam: `Produced`, direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, deterministic hash `a8972efd7c4900a4`;
- plane and seam each reproduced identically across three independent benchmark processes.

G1 is therefore complete.

## Active G2 failure

`close_sheets__surface_cells` is now the earliest failing direct fixture:

- producer disposition `NotApplicable`;
- 158 generic traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

The next Code + Build turn must extend authoritative phase/front construction to independent disconnected but spatially close source-sheet components using component/local-sheet identity. Positional or nearest-sheet coupling is prohibited.

## Later observations

- cylinder: `NotApplicable`, 732 traces, zero arrangement/completion; G3 remains blocked;
- bunny: direct failure, `NotApplicable`, 80,862 traces, zero arrangement/completion, 53.493351 s;
- vase: exceeded bounded 180 s runtime window; timeout is failure only and no correctness claim is made.

## Default-suite state

- remaining producer: 23/24, only scheduler-sensitive validator timing ratio failure;
- completion/simplification: 154/164, same ten downstream failures;
- validation: 60/60;
- compiled API: 8/8.

Direct gate ordering remains authoritative; downstream cleanup and performance work are deferred while G2 is red.

## Required next turn

Code + Build only.

Before editing, declare:

```text
Active design gate: G2 cross-chart/close-sheet isolation
Earliest failing fixture: close_sheets__surface_cells
Missing design contract: authoritative uniform phase/front applicability and construction across multiple disconnected but spatially close source sheets without positional cross-sheet coupling
Smallest general implementation change: extend the existing authoritative phase/front producer from the proven plane/seam domain to independent same-topology sheet components using source component/local-sheet authority and exact per-component transition/fan routing; do not alter cylinder/periodic logic
Observable material-progress condition: close_sheets disposition becomes Produced and yields direct deterministic valid pure quads with zero cross-sheet provenance/merge violations while plane and seam remain unchanged regressions
Explicitly deferred work: cylinder holonomy, singularities, topology-distinct completion, adaptive transitions/features, bunny/vase production/performance, timing, downstream completion/simplification failures
```

Compile approved targets only and execute no generated project binaries. Package an immutable artifact for the following artifact-only Test + Benchmark turn.

Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
