# M5-CP3-CB7 Code + Build Report

**Turn:** `M5-CP3-CB7`
**Boundary:** **Code + Build / runtime-free**
**Result:** **COMPLETE / STATIC GREEN / GMP COMPILE-PACKAGE GREEN / RUNTIME-FREE / DIAGNOSTIC CUTOVER BUILT**
**Exact successor:** `M5-CP3-TB1-R6-EXEC`

## 1. Authorized implementation

Semantic patch commit `a1392c61a4f800512bb8bd73126f993638d1f55c` changes exactly the two files authorized by `Architecture_M5_CP3_CB7_Periodic_Holonomy_Failure_Disambiguation_Plan.md`:

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`

Existing `SurfacePhaseFrontFailureReason` numeric values **0–49 are unchanged**. Six values are appended at **50–55**:

- `PeriodicGeneratorRouteUnavailable`
- `PeriodicActionCorrespondenceMismatch`
- `PeriodicHolonomyZeroTranslation`
- `PeriodicHolonomyMissingGeneratorRoute`
- `PeriodicHolonomyMissingCutRoute`
- `PeriodicHolonomyInvalidRelationIdentity`

Only the same-region promotion boundary is relabelled. Generator-route lookup failure now reports the generator-route reason; `periodic_action_for_pair(...)` failure reports the action-correspondence reason; and the four existing `SurfacePeriodicHolonomyErrorCode` values map one-to-one to their appended phase-front reasons. The prior generic `PeriodicHolonomyMismatch` remains intact at unrelated call sites and as the defensive fallback. No route selection, face authority, action mathematics, relation identity/factory semantics, atlas semantics, test/fixture/selector bytes, acceptance expectations, or frozen definitions changed.

## 2. Static verification

Static diff review proves:

- exactly two production paths changed;
- no test, fixture, benchmark, selector, atlas implementation/API, relation factory, or build-system source changed;
- the existing enum values were not renumbered;
- selector430 remains **430 LF rows**, no CR bytes, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- exact first427 remains SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

The R5 Review addendum's accepted-row hazard remains a runtime falsifier, not a test-authority edit: the three accepted selector identities that explicitly expect the legacy generic `PeriodicHolonomyMismatch` remain byte-unchanged and are required to stay green in R6. No expectation was weakened or pre-edited.

## 3. Mandatory GMP compile/package evidence

Authoritative compile/package run/job: `35598796960 / 106329775985`.

The reusable compile workflow built all eight required targets from exact packaged source `8f77ec403f16930145bba5bfc526a5b881b9f166`:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Preflight/build exit codes are **0 / 0**. GMP evidence records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the generated authoritative test link command. All five source-status receipts are empty. Command boundary is `Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`.

Immutable package evidence:

- result artifact: `10637998372`
- result artifact SHA-256: `1c92e42939081ec9f041f72e916c99d80a700b39a61e3917e8cf8830c5a3f98f`
- root `SHA256SUMS`: **28/28 verified**
- root manifest SHA-256: `1b0bc0b8ce4ff0c339659c7f7c5c3c4e9e26143d352424f7aecf1a2b8f91f737`
- packaged source archive SHA-256: `dbc083059b4dbd8ea7b429ca32819ce8a91b179b5e2cbd6201a66113d37a9163`
- diagnostic log artifact: `10637858795`
- diagnostic log artifact SHA-256: `ad626d649fdae2bb8fe591e2a3a38d0ee670ed152967f08cb800c098e4c4645a`
- compiler cache: **78/129 hits**, fixed GMP PRE_TEST key, 256 MiB cap

No generated Directional executable was run. No GoogleTest discovery/listing, test, benchmark, `ctest`, CLI/GUI, fuzzer, help/version command, or custom input executed.

## 4. Disposition

CB7 satisfies the diagnostic-only Code + Build contract and creates no semantic/runtime acceptance credit. Candidate artifact `10637998372` remains **unpromoted**. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains **50 events / 14 categories / 36 recurrences**, debt **5**; all four M5 produced debts remain open and selector publication remains prohibited.

Exact successor is immutable artifact-only `M5-CP3-TB1-R6-EXEC` under `Architecture_M5_CP3_TB1_R6_Artifact_Only_Test_Benchmark_Plan.md`. R6 must execute the unchanged **446-process** gate and use the six produced rows only to identify which appended failure branch is active. No semantic correction is authorized until mandatory `M5-CP3-TB1-R6-REV` independently adjudicates that runtime evidence.
