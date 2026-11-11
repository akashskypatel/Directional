# CB119 — boundary field corner derivation (2026-11-10 UTC)

**Turn:** `M6-CP3-CB119-P13-A3-BOUNDARY-FIELD-CORNERS`. Code and build only. The next Test and Benchmark turn is separate.

## Exact source

- Applied the unchanged RA-224 patch. Frozen diff SHA-256: `06d6cadd1640b30107db7d4e4a5299849a8a041f5ed33cef1bdb9e6bcbb90b0f` (307 lines). Source base `d99e7bde555fef6b0be0bddfb10505431c7bf81b`.
- [Source commit](https://github.com/akashskypatel/Directional/commit/cd1d451b4190bdd6b88e07fafa7e6fe69ff5b3d2): header +15, implementation +117, tests +142, with no removed lines. These are the only changed source paths.
- New function `derive_boundary_field_corner_vertices` finds source-boundary vertices where the boundary-following cross-field branch changes. The two tests check field-versus-geometry corners and producer-side-start equivalence. Production does not call this function.

## Compile-only evidence

- [GMP/GMPXX compile run](https://github.com/akashskypatel/Directional/actions/runs/42926339655) and immutable [artifact](https://github.com/akashskypatel/Directional/actions/runs/42926339655/artifacts/13815545121), archive SHA-256 `6af2c551287b8861f64955f8604d968091ebcfbb9db9ceff08126c5edbe1e70a`. Package manifest verified `28` entries.
- Eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.
- CMake and build exit 0. GMP and GMPXX linked. Package records `exactArithmeticBackend=GMP`, `runtimeExecution=false`, clean source state. No test or benchmark ran. Compilation does not establish runtime success.

## Unchanged authority and next action

Last accepted CP2 491/491. Stable 66/17/49, debt 1 and deferred 81 are unchanged. Last measured gate TB99 936/936 PASS, membership 1017. O36 production switch is off. CP3/selector497 not promoted.

Next turn: `M6-CP3-TB100-P13-A3-BOUNDARY-FIELD-CORNERS-FULL-GATE-EXEC`. Use the immutable CB119 artifact, exact 938-row manifest SHA-256 `2df4bd96ee8a52323ffa4f07292e37a3b6e4aedd6424fb9dc68e805da2cbc24c`, membership 1019, and RA-224 §5. Execute no rebuild, repair, or source edits within TB100.
