# CB128 annulus rim edge schedule — code and build record

## Situation

- **Turn:** `M6-CP3-CB128-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE` (64D.4). Code + Build, compile only.
- **Authority:** [RA-228](Architecture_M6_CP3_DEFN_P13_A3_Annulus_Rim_Schedule_Review_20261112.md) §4. Exact frozen [patch](Architecture_M6_CP3_CB128_P13_A3_Annulus_Rim_Edge_Schedule_Exact.diff), SHA-256 `eb7e63e262dfd6a030aa1bba375a3a6fbccb1ceeae3901e7ee4479dd3bbeec0b`; 709 lines and 15 single-space context lines. The patch applies to the verified `11f1dafb879562315d02cf9feaf4c90721d5c32d` control-plane head, with the same semantic base as RA-228.

## Background and implementation

- Changed exactly three files: `include/directional/geometry/SurfaceCellTracing.h` (44 insertions), `src/geometry/SurfaceCellTracing.cpp` (262 insertions, 148 deletions), and `tests/SurfaceCellsPhase10Tests.cpp` (130 insertions).
- One shared Mandatory source-edge arc-breakpoint reader replaces the bounded-disk arc reader without changing its cursor-join behavior. The annulus rim-edge reader is present but **unwired**. Test `SurfaceCellAuthorityContractCutover.D4AnnulusRimEdgeReadsEvenSplitsInWalkOrder` is added as gate row 944. Gate row 729 records `annulus-read` without changing production behavior.
- Exact application commit: [`739e79e240f75ac1c24e659004b13b425803081b`](https://github.com/akashskypatel/Directional/commit/739e79e240f75ac1c24e659004b13b425803081b); [Drive apply run 43150034720](https://github.com/akashskypatel/Directional/actions/runs/43150034720). The application result reports a successful exact patch check and `runtimeExecution=false`. Both temporary staged Google Drive patch files were retired by owner-authorized deletion.

## Assessment — verified compile-only evidence

- [Compile run 43150206247](https://github.com/akashskypatel/Directional/actions/runs/43150206247) **SUCCESS**. [Immutable package 13913578057](https://github.com/akashskypatel/Directional/actions/runs/43150206247/artifacts/13913578057); outer ZIP SHA-256 `1eb3f762034dff9cf31f1ba45362a9f1b371eda35986fc062f3bd521e679f394`.
- The package contains **28/28 matching SHA-256 checksums**. Its source record is `739e79e240f75ac1c24e659004b13b425803081b`; the source working-tree status is clean before, during, and after the build. Preflight and build exit codes are both zero.
- Eight compiled targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.
- The generated linker command includes both `libgmpxx.so` and `libgmp.so`; the package records `exactArithmeticBackend=GMP`, `turnBoundary=Code+Build-only`, and `runtimeExecution=false`. Its activity log confirms no generated binary, test, benchmark, help, version, discovery command, `ctest`, or custom input was executed.
- **No test pass, runtime behavior change, or production acceptance is claimed.** The new unit test was compiled, not executed. TB108 remains the last measured candidate (943/943 scoped MATCH; Cylinder PASS, BunnyRandom and Vase registered RED). CP2 491/491 is the last accepted semantic runtime; stable accounting remains 66 events / 17 categories / 49 recurrences, debt 1, deferred 81. O36 remains unwired, CP3/selector497 unpromoted, PR #8 draft/open/unmerged.

## Recommendation — separate next turn

- **Next:** `M6-CP3-TB109-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-FULL-GATE-EXEC` (64D.5), artifact-only Test + Benchmark against the exact compiled CB128 source/package. Manifest `gates/Architecture_M6_TB109_P13_A3_Annulus_Rim_Edge_Schedule_Full_Gate_Case_Manifest.tsv`, SHA-256 `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61`, 944 rows, membership 1,025.
- Follow RA-228 §5: 944/944, all TB108 receipt lines and census byte-identical, and row 729 `annulus-read` recorded verbatim with `recorded=0` and `outputRimEdges > 0`. After MATCH, only if row 729 `readable = equalOutput = rimEdges` may the successor be CB129; otherwise route to the Review-only annulus pairing definition. On a gate mismatch use the registered TB109 Review path; on infrastructure failure use its registered orchestration path.
- TB109 was **not started** in this Code + Build turn.
