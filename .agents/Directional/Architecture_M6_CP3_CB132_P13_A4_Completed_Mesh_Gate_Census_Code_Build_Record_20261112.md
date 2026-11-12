# CB132 — Completed-mesh gate census: Code and Build record (2026-11-12)

## Situation

Canonical turn `M6-CP3-CB132-P13-A4-COMPLETED-MESH-GATE-CENSUS` (64E.4) is complete. The exact test-only patch is committed, and the eight required targets compile with GNU Multiple Precision (GMP) and its C++ interface (GMPXX). No tests, benchmarks, or project executables were run. The next separate turn is `M6-CP3-TB113-P13-A4-COMPLETED-MESH-GATE-CENSUS-FULL-GATE-EXEC` (64E.5).

## Background

- RA-231 froze [`Architecture_M6_CP3_CB132_P13_A4_Completed_Mesh_Gate_Census_Exact.diff`](Architecture_M6_CP3_CB132_P13_A4_Completed_Mesh_Gate_Census_Exact.diff), SHA-256 `ccaed2b5ecd4b6c562fdaed313f547f063cbf047225778836bf1eb9683182d90`, 43 lines, 32 insertions and zero deletions in `tests/SurfaceCellDesignAcceptanceTests.cpp` only.
- Source snapshot `bd4f424119901005700c8b176f82e09d5d0e4643`, [run 43209738087](https://github.com/akashskypatel/Directional/actions/runs/43209738087), artifact `13941340001`, ZIP SHA-256 `8bf0ab50562643ec9d7e30a1c27a8e5eb08482f41ef239522961b85eefd3214a`; 5,513 source-file checksums verified. The exact frozen body passed `git apply --check`.
- Patch wrapper SHA-256 `6f8590fb04ffc13648dad4d027075bf52f56e5c331f66537523b777f742937df`, with the frozen diff body unchanged; [Drive apply run 43210491507](https://github.com/akashskypatel/Directional/actions/runs/43210491507) succeeded, result artifact `13940269326`. Applied source commit [`196f611769ee738a86d4aa46903d0ed592384691`](https://github.com/akashskypatel/Directional/commit/196f611769ee738a86d4aa46903d0ed592384691). Both temporary Drive staging files were permanently deleted through the authorized Drive connector. Retained backup is in the ChatGPT Library `/Directional/`.

## Assessment — immutable compile evidence

- [Compile run 43210849945](https://github.com/akashskypatel/Directional/actions/runs/43210849945) succeeded for exact source `196f611769ee738a86d4aa46903d0ed592384691`. [Package artifact 13941286743](https://github.com/akashskypatel/Directional/actions/runs/43210849945/artifacts/13941286743), outer ZIP SHA-256 `3964dde25c8005048e018f2927f2f7dd29c288eb2afcb2d43ddd9451288c3b5e`, internal checksums 28/28 verified.
- Required targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Compile authority: both GMP and GMPXX linked, `exactArithmeticBackend=GMP`, clean source status, `runtimeExecution=false`. No test, benchmark, configuration change, or compiled binary execution during the code/build turn.
- The new `switch-validation` line prints the final mesh gate's input measures when a validation result exists. The existing `switch-run` line is unchanged. No product source, default option, selector, or acceptance criterion changed. `chainRimSchedules` stays false.
- No fresh runtime acceptance claim. TB112 remains 945/945 scoped MATCH and 1,026 memberships; accepted CP2 491/491, stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81. CP3/selector497 are unpromoted; O41 remains open.

## Recommendation — next separate turn

Run `M6-CP3-TB113-P13-A4-COMPLETED-MESH-GATE-CENSUS-FULL-GATE-EXEC` artifact-only against exact immutable package `13941286743`; do not recompile or modify code. Use manifest `.agents/Directional/gates/Architecture_M6_TB113_P13_A4_Completed_Mesh_Gate_Census_Full_Gate_Case_Manifest.tsv`, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026. RA-231 §5 requires 945/945, all TB112 receipts unchanged, every new `switch-validation` line recorded, and `accepted=0 strict=0` for MultiFaceSeam chained and SmoothRimDisc per-arc/chained. On MATCH, the following Review-only turn owns O41: `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE`.
