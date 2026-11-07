# M6-CP3-CB1-ENTRY-R4 — relief guidance original-source A3 ingress (2026-10-11)

**Boundary:** Code + Build only. R4 remains unfinished. Compile evidence is blocked by an external Eigen submodule checkout outage. No tests, benchmarks, selector discovery or frozen 497 execution.

## Source-exact correction

Snapshot workflow `38177742186` at base `7dcdd09db450880fc4e969e8afb734c160817576`, 6,261/6,261 source manifest checksums verified. Only `tests/SurfaceCellsPhase10Tests.cpp` changed: existing `SurfaceCellsPhase10.UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded` now uses pre-existing `build_phase10_with_source_atlas(mesh, crossField, targetSize, options)` in both guidance-only and embedded cases, so the checked producer receives independently derived original-source A2/A3. Original mesh, cross field, target size, barrier settings, test identity, assertions and expected results unchanged. No production code, selector, or workflow altered.

Patch full SHA-256 `e5b29f892b4c7921d03d286d3200cfa5618722f28955c431d64f5efbe6140bd0`, diff body SHA-256 `9d02c1b832bd1a5e0e344b4be169e66d230ad1836f93edc06bb05d93e3038ea4`. Local `git diff --check` and exact-base `git apply --cached --check` passed. Drive apply workflow `38178284384` verified and pushed semantic commit `572cd8aea6a11717c1dd471025fde69c76acfd1e`; result artifact `11717370437`, workflow success and `runtimeExecution=false`. Temporary Drive stage `1EwkFLjfBhWJgKDNcXstNm-RdOpcbFOXR` owner-permanently deleted after push. Exact backup retained in Library `/Directional/Evidence/Directional_M6_CP3_R4_Relief_Guidance_A3_Ingress_20261011.patch`.

## Mandatory compile failure — external prerequisite, not a source result

Eight-target source-exact GMP/GMPXX dispatcher run `38178491667`, compile job `114585905731`, requested source `572cd8aea6a11717c1dd471025fde69c76acfd1e`, failed before CMake and compilation: checkout recursively cloned Eigen from `https://gitlab.com/libeigen/eigen`, and GitLab twice returned `fatal: remote error: GitLab is currently unable to handle this request due to load`. Checkout exit 1; `compile_status=missing`. Failure mailbox is authoritative. Diagnostic artifact `11717111809` has ZIP SHA-256 `6f5c4485cf987518f1cd157431f73704a0536b843798f6b4765fbe93b3120465`. No executable output or successful GMP/link/package/manifest validation. This is not evidence of C++ compilation failure or success.

The source-snapshot workflow can fall back to the Eigen mirror, but the existing compile workflow's recursive checkout did not. Resume only after source transport recovers or a separately schema-validated, permissions-preserving correction is authorized. Do not bypass mandatory GMP.

## Unchanged obligations / continuation

Accepted CP2 baseline `491/491`; rejected R3 `403/497`. No new runtime PASS. R4 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 restoration, six CP3, true multi-carrier odd-tau and independently reviewed terminal A3 dual-path definition remain outstanding. Do not promote frozen TB497 or start a successor. Recheck current repository handoff/STATUS, resolve checkout prerequisite, obtain eight-target compile for source commit above, then continue R4 under turn policies. Full external preservation record in Library `/Directional/Evidence/M6_CP3_R4_Relief_A3_Ingress_Compile_Blocker_20261011.md`.
