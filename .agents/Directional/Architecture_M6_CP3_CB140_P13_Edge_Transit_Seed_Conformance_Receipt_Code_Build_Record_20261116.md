# CB140 — edge transit seed conformance receipt (Code + Build, 2026-11-16 UTC)

**Canonical turn:** `M6-CP3-CB140-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT`.
**Authority:** [RA-240](Architecture_M6_CP3_DEFN_P13_Vertex_Transit_Outflow_Outcome_Review_20261116.md) §5.

## Scope and source

- Applied only the frozen exact diff, `Architecture_M6_CP3_CB140_P13_Edge_Transit_Seed_Conformance_Receipt_Exact.diff`, SHA-256 `2e135b8cc18c6e59187928779756d429d0c8e2819e9dcfdc21344f71e8b667eb`. One modified file: `src/geometry/SurfaceCellTracing.cpp`, +105/−0.
- Frozen source snapshot: `e945c08b3e42383bd0cb60b1e3e4ce991cb69f91`; GitHub Actions snapshot [run 43824474633](https://github.com/akashskypatel/Directional/actions/runs/43824474633), artifact `14205244396`, outer SHA-256 `ae7ff483b8f6f868a0cbf5e95ae83561f01bbb4e0cb5c695f31e07ab3c95150d`, 5,553/5,553 source hashes verified.
- Frozen patch staged by the authorized Drive transport, full SHA-256 `4f6fc15fa52fe3afe75430fe5ab9681744cf2cce304645ff948e4ec03bcbca57`, diff-body SHA-256 `b9b401acfbe4db553f5234812050ff9ab653a5cca49d2355c09371b675518054`. [Apply run 43824903318](https://github.com/akashskypatel/Directional/actions/runs/43824903318) SUCCESS, result artifact `14205951852`, applied semantic commit `6a293e4641a2160cb9f447322c9aa1d1d26f3838`, `runtimeExecution=false`. Google Drive staging file was permanently retired after successful apply.
- The report-only `edgeTransitSeedConformance` diagnostic checks the carrier-ray owner with the exact comparison kernel and prints only nonconformances or model-unavailable reasons. It does not alter the vertex election or any trace decision.

## Compile evidence

- GMP/GMPXX eight-target compile/package: [run 43825208976](https://github.com/akashskypatel/Directional/actions/runs/43825208976), outcome **SUCCESS**, source `6a293e4641a2160cb9f447322c9aa1d1d26f3838`.
- Immutable package artifact `14206223032`, outer ZIP SHA-256 `98acb75fbed52ab6909be65d165310ac8dfe0c75a5be5117aed473c4fd7db089`, internal checks `28/28`.
- Target set: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `runtimeExecution=false`; no tests, benchmarks, case census or discovery executed in this Code + Build turn. Gate membership remains 1,028 by source inspection; this turn did not run the gate.

## Disposition

- Compile-only scope accepted; diagnostics remain **unobserved at runtime** pending separate immutable TB121.
- Next separate turn: `M6-CP3-TB121-P13-EDGE-TRANSIT-SEED-CONFORMANCE-RECEIPT-FULL-GATE-EXEC` (artifact only, RA-240 §6). No successor work performed.
- D12 remains pending; O42/O43/O44 remain open; D11=A, D10 deferred, D6 pending; accepted CP2 491/491; stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81; CP3/selector497 unpromoted and `chainRimSchedules=false`.
