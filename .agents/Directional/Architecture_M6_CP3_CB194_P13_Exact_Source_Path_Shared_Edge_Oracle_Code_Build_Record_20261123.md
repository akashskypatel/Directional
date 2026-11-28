# CB-194 exact source-path shared-edge oracle — Code + Build (2026-11-23 UTC)

## Scope and authority

- Canonical turn `M6-CP3-CB-194-P13-EXACT-SOURCE-PATH-SHARED-EDGE-ORACLE`. Exact approved source diff `.agents/Directional/Architecture_M6_CP3_CB194_P13_Exact_Source_Path_Shared_Edge_Oracle_Exact.diff` SHA-256 `7913097b108c6f8b0d74bedbded1048e5e4b45ae41ab892d069f9398957365e5` (7,432 bytes, two paths, +129/-0).
- Source-snapshot run `45172131599`, exact source `97a0a606b4edd7bb95b8ac3398e39cab61c6d842`, snapshot artifact `14817736780`, ZIP SHA-256 `36bd4d827dca32151a9252b2b2533129a814265e2548492d089f6943549a02b2`, 5,801/5,801 file checksums verified.
- The source diff is exactly unchanged. Google Drive transport was repackaged with required base, body hash and intended paths. The first apply attempt (`45172825970`) failed at metadata verification without applying code. The corrected apply run `45173608325` succeeded and committed `fae9eb71bb5806d71901cc2ccb8c925201be0c0a`. Both staged Google Drive files were deleted by the owner-side connector after success.
- Changed source files only: `include/directional/authority/ExactSourcePath.h` and `tests/FieldAlignedCurveNetworkTests.cpp`. The new helper detects strictly positive-length common source-edge intervals, including reversed traversal and face-carried edge pieces. It remains unwired in production; two new focused tests are compiled but not executed in this turn.

## Compile-only verification

- GitHub Actions dispatcher run `45173887503`; exact compile source `fae9eb71bb5806d71901cc2ccb8c925201be0c0a`; artifact `14820355596`; ZIP SHA-256 `817583b75f8d9a5f7b9e7300426756d1044d535e9f63ebf3ec5d5cf88fe45ec6`.
- Eight GMP/GMPXX compile targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- `runtimeExecution=false`. No test, benchmark, or runtime executable was run in Code + Build. Acceptance of the two new cases is reserved for `M6-CP3-TB-EXEC-173-P13-SHARED-EDGE-ORACLE-FULL-GATE`.

## Disposition

- CB-194 compile scope completed. Existing TB172 remains rejected 987/994 with seven mechanical failures; latest accepted full gate TB169 remains 993/993 and CP2 remains 491/491. No CP3, selector497, D0 or production output promoted.
- Next `M6-CP3-TB-EXEC-173-P13-SHARED-EDGE-ORACLE-FULL-GATE` is artifact-only with 996-row manifest (expected 989 PASS and the same seven RED), subject to independent review. D13 remains an unanswered owner design question for TB-REV-173, not an authorization to start CB-195/196.
- Workflow process note: the mandatory snapshot read-mode gate was selected after early document reads; this policy-order miss was disclosed during the turn. No source behavior outside the exact approved diff was changed.
