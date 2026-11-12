# CB133 — Completed-mesh size census: Code + Build record (2026-11-12)

## Situation

Canonical `M6-CP3-CB133-P13-A4-COMPLETED-MESH-SIZE-CENSUS` (64E.7) is **COMPLETE, compile-only**. Its exact test-only patch was committed and all eight required targets compiled. No Directional binary was run. The next, separate turn is `M6-CP3-TB114-P13-A4-COMPLETED-MESH-SIZE-CENSUS-FULL-GATE-EXEC` (64E.8).

## Background

- RA-232 froze `Architecture_M6_CP3_CB133_P13_A4_Completed_Mesh_Size_Census_Exact.diff`, SHA-256 `874773240cc5934854915a0f7ed8076c10dc5073100c41030859c32f44e570ee`, with 97 additions and 4 deletions in `tests/SurfaceCellDesignAcceptanceTests.cpp` only.
- Exact [source snapshot 43223491105](https://github.com/akashskypatel/Directional/actions/runs/43223491105), source `804735a152a9828ee710277bea70913e09079471`, artifact `13946114822`, ZIP SHA-256 `03c20971ec4bf38c8a8fa003bee6f41d5f0a0f67c5a38f659240a0b9d1b549b2`; 5518/5518 source checksums passed. Patch passed `git apply --check` and `git diff --check`.
- [Drive apply 43224295903](https://github.com/akashskypatel/Directional/actions/runs/43224295903) succeeded; result artifact `13946289936` ZIP SHA-256 `a5eb75be006d612c0934a8ef8fbb2796b6ce81e5df85180f26ff3c8b940319b4`. Exact [source commit `e60f2c76cc782767daf149d9a78af09474eb310e`](https://github.com/akashskypatel/Directional/commit/e60f2c76cc782767daf149d9a78af09474eb310e) touches the one prescribed test file. The staged Google Drive patch was permanently deleted after push.

## Assessment

- [Compile run 43224657893](https://github.com/akashskypatel/Directional/actions/runs/43224657893) succeeded from exact source `e60f2c76cc782767daf149d9a78af09474eb310e`. Immutable package `13947781593`, ZIP SHA-256 `e89169f233a6e8c9591acdaaaa76fc345900af19d056c6ee088e1bdfb8ca3aa5`; 28/28 internal checksums verified.
- All eight compile targets succeeded: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- GMP and GMPXX linkage verified from the packaged linker command; `exactArithmeticBackend=GMP`, clean source status, exit codes 0, `runtimeExecution=false`.
- The new observational receipts `switch-size` and `switch-spans` are compiled, **not executed**. No production code, default option, selector, fixture, runtime gate, or acceptance threshold changed. Production remains `chainRimSchedules=false`.
- TB113 remains the last scoped runtime evidence: 945/945 PASS, 1026 memberships. CP2 491/491 accepted, stable 66/17/49, debt 1, deferred 81. O41 open; CP3/selector497 not promoted.

## Recommendation

Run `M6-CP3-TB114-P13-A4-COMPLETED-MESH-SIZE-CENSUS-FULL-GATE-EXEC` in a **new artifact-only Test + Benchmark turn**, using this exact immutable compiled artifact `13947781593`. Use `.agents/Directional/gates/Architecture_M6_TB114_P13_A4_Completed_Mesh_Size_Census_Full_Gate_Case_Manifest.tsv`, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1026. RA-232 §5 requires 945/945, every TB113 receipt unchanged, new `switch-size` and `switch-spans` receipts, and the MultiFaceSeam chained `switch-size` line. If MATCH, only the later independent Review may address O41 (`M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING`). No TB114 execution was part of CB133.
