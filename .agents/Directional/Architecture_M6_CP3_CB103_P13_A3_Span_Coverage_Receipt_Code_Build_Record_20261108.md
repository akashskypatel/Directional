# CB103 — A3 span-coverage receipt (Code + Build, 2026-11-08 UTC)

**Turn:** `M6-CP3-CB103-P13-A3-SPAN-COVERAGE-RECEIPT` (step 59). **Verdict:** code applied exactly and the authoritative eight-target GNU/Linux GMP compile succeeded. **No Directional runtime executed.** Next separate turn: `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-EXEC`.

## Source and patch authority

- Governing frozen review: [RA-214 §6](Architecture_M6_CP3_DEFN_P13_A4_A2b_Disc_Producer_Runtime_Free_Resolution_20261108.md).
- Exact patch: [`Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff`](Architecture_M6_CP3_CB103_P13_A3_Span_Coverage_Receipt.diff), 292 lines, SHA-256 `0982bd4ae02d98c876ee42c53b19b7f9452cc90708db991d9ee415609db531ec` (diff body), base `07d1a2207bf91965fce66636b640b63663d8b183`.
- Preserved eight single-space context lines and six-file numstat: `8 0` / `36 1` / `71 0` / `22 0` / `11 0` / `63 0`; total **211 additions and 1 deletion**.
- Verified remote `drive_apply`: [run 42467958970](https://github.com/akashskypatel/Directional/actions/runs/42467958970), committed exact source [`000752d896aad4e515bcffc23331c26692539830`](https://github.com/akashskypatel/Directional/commit/000752d896aad4e515bcffc23331c26692539830). Application was hash/paths/base checked; the separate transport copy was retired after success.
- Added pure report-only `summarize_a3_span_coverage`, six `RemeshDiagnostics` fields, one census `a3-coverage case=` line, corrected the pre-producer conformity receipt comment (D8), and compiled the new GUARD `SurfaceCellAuthorityContractCutover.A3SpanCoverageObservesRecordedHardRailIntervalsAndTheirLoss`. No disposition consumes counters; no hash material changed.

## Compile-only evidence

- Dispatcher/compile: [GitHub Actions run 42468093355](https://github.com/akashskypatel/Directional/actions/runs/42468093355), `compile / compile` completed **success**; source SHA `000752d896aad4e515bcffc23331c26692539830`.
- Immutable package artifact **`13613225138`**, ZIP SHA-256 **`b7fc883e27bd31f03e595e120aa685feba3bb769ce84837dc73da94e11ee13d2`**; packaged source archive SHA-256 **`16af3c8af1c771bc475bc9c47185b05670a93418c076d2baee9c07a44e5f2951`**.
- Dedicated compile log artifact **`13612707846`**, ZIP SHA-256 **`881d0e5fe07a0df3bf25e1ab0a1ca853a559746eb6b405f8321c315383c4e92f`**.
- Package `SHA256SUMS`: **28/28 PASS**; `preflight-exit-code=0`, `build-exit-code=0`; before/after/final source statuses empty. All eight targets compiled: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- GMP authority: `exactArithmeticBackend=GMP` and both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` present on the generated link command. `DIRECTIONAL_ENABLE_GMP=ON` was mandatory for the reusable compile.
- Execution boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`. No tests, benchmarks, generated executables, CLI discovery or runtime were executed.

## Disposition and separate gate

The compile establishes only compilation/package validity. **TB86 is not yet executed**. Its frozen [909-row manifest](Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv) has SHA-256 `3573ffbf6cba47592489c34f2177988c1b66871db4cd983577694dbb9dcabe76`, deferred 81 and membership 990. TB86 independently verifies 909/909, the four pinned TB85 rows and three `platform-digest` lines unchanged, `partial=0`, `foreign=0`, `covered+unrecorded=scheduled`, and Vase `observed=0`. Mismatch routes to Review; infrastructure failure to an orchestration-correction turn per RA-214 §6.

No promotion: accepted CP2 **491/491** remains, TB85 remains latest executed gate **908/908**, membership 989, stable regression accounting **66/17/49**, debt **1**, 81 deferred; selector497/CP3 unpromoted. D6 Vase expected-D1 criterion still awaits user decision (not a prerequisite for TB86).
