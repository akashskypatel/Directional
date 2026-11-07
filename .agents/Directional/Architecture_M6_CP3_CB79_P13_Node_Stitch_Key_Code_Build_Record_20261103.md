# M6-CP3-CB79 P13 arrangement-node stitch key — Code + Build (2026-11-03)

- Authority: RA-200.4 and RA-200.8, DESIGN Amendment 32; exact `M6-CP3-CB79-P13-NODE-STITCH-KEY`, draft PR #8.
- Source base `4c52ef9221a93ab22cb83aeecef51488d0ddbed7`, identical semantic files to CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca`.
- Exact RA-200.8 diff SHA-256 `89f37001d6eea167672c32edf73178cbf98d23e0501e28ca8795fb79a0719028`, 146 lines; two files, numstat `25 2` / `95 0`.
- Final file SHA-256: `PatchDescriptor.cpp` `cef48a850cac9ba3c0a471491f1fb5e4d094571173dd6db916df6aa1683ce41f`; `PatchDescriptorMilestoneETests.cpp` `068271a6d0afb08bba23ba391495ae82de86ff35d50826ca26bffa06ded985fc`.
- Implementation: node-wide canonical stitch identity across each occurrence's source scope; halfedge/domain identity behavior unchanged. Three RA-200 GUARD tests added; **not executed here**.
- Corrected patch full SHA-256 `6add7091ea9c8111fa83e95f6ea35bdbc8dd6b8c93bd72e5be0b53ac48648e51`, diff-body SHA-256 `aad6ad51f7e1362f43f45280b430d43bd2f096aaefba53ae8741ecb20ae7cc57`.
- Initial [Drive apply 41690486136](https://github.com/akashskypatel/Directional/actions/runs/41690486136) failed before commit due comma-vs-semicolon `intended_paths` metadata. Corrected staged patch applied by [run 41692965488](https://github.com/akashskypatel/Directional/actions/runs/41692965488); result artifact `13258925336`.
- Applied source commit: [`3feb2a4182a5a12c2a9f306272756f8333a44b59`](https://github.com/akashskypatel/Directional/commit/3feb2a4182a5a12c2a9f306272756f8333a44b59).
- [Linux compile-only run 41693542399](https://github.com/akashskypatel/Directional/actions/runs/41693542399) succeeded: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Build artifact `13261460152`, ZIP SHA-256 `eb926a8f2577b12128c5e9c0a668eb48157c2c53df8316389e49c6a1e5d52ede`, `28/28` source/package checksums verified; exact compiled source above; GMP and GMPXX required on authoritative linker evidence, `runtimeExecution=false`.
- No tests, benchmarks, runtime binaries, fixture/selector or acceptance modifications were executed. The new GUARD tests require separate TB73 execution.
- Accepted CP2 491/491; stable 66/17/49, debt 1, deferred ledger 81; selector497 unpromoted. Latest candidate TB72A 883/883, membership 964, unchanged by this compile.
- **Authorized separate successor:** `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC`, RA-200.5 manifest 886 `5d09fa33…`, membership 967, artifact-only (no rebuild), Vase registered ABNORMAL timeout 600 s after assembly.
