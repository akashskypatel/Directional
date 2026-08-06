# Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build Plan

**Active gate:** Gate 1 — Uniform phase-front plane  
**Earliest failing fixture:** plane  
**First authoritative failure:** `completion/output-validation:FlippedFace`, cell 38, source face 41  
**Material-progress condition:** the plane produces one valid direct quad per accepted phase-front cell and advances beyond completion output validation, preferably to direct success.

## Scope

1. Preserve the current first-class lattice/front model and deterministic hashing.
2. Add a source-authoritative orientation contract for every proposed phase-front cell:
   - four distinct corners;
   - ordered side endpoint continuity;
   - nonzero signed area in the planar source chart;
   - winding consistent with the authoritative source normal;
   - component and sheet identity consistent across all corners and sides;
   - each directed front edge has exactly one filled side or explicit exterior classification.
3. Reverse the complete cell cycle, including side paths, families/signs, corner lattice states, and edge ownership, when winding is opposite; never reorder by positional heuristics.
4. Materialize already-decided phase-front cells directly as quad-domain arrangement cells. Arrangement may split exact crossings and canonicalize identities, but generic patch completion must not expand one authoritative four-sided cell into a new multi-quad topology.
5. Fail closed before completion when any cell violates the orientation or incidence contract.
6. Keep seam, close-sheet, cylinder, periodic, adaptive, feature, singularity, and bunny work blocked.

## Test-suite corrections allowed in this Code + Build turn

- Change `AdaptiveTargetSizePhase12.SurfaceCellScaffoldPopulatesSizeDiagnostics` so it tests populated sizing diagnostics without assuming failure.
- Change `SurfaceCellsPhase10.SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture` so recovery is tested on an input where direct production is unavailable, or accept direct validated output while retaining a separate recovery-only fixture.
- Do not weaken the four direct acceptance tests.

## Compile-only verification

Compile exactly:

- `directional_core`
- `directional_pipeline`
- `directional_compiled_api_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_benchmarks`

Use Release `-O2 -DNDEBUG`, static libraries, PRE_TEST discovery, recursive submodules, and package five executables, two libraries, fixtures, source authority, logs, metadata, and checksums. Execute no generated binary, test, benchmark, help/list, discovery, CLI, or GUI command.

## Remote synchronization backlog

Until the GitHub outage is resolved, keep the current exact patch pending on the TODO. Do not use a workflow to apply it. When remote writes are healthy, create a direct coherent five-file commit and verify the resulting Git blobs exactly before removing the backlog item.
