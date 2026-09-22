# M5-CP3-CB11 Code + Build Report

**Turn:** `M5-CP3-CB11`
**Boundary:** **Code + Build only / runtime-free / product-only**
**Result:** **COMPLETE / ROTATION-AWARE SAME-REGION PAIRING CORRECTION APPLIED / ALL-EIGHT GMP COMPILE-PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Exact successor:** `M5-CP3-TB1-R10-EXEC`

## 1. Semantic correction

CB11 implements only the R9 Review-authorized same-region periodic-pairing correction in:

```text
src/geometry/SurfaceCellTracing.cpp
```

The change is deliberately surgical. The common hard-rail structural gate still requires exact reciprocal intervals, opposite interval orientation, reverse routes, compatible optional rail identity, and — for same-region promotion — distinct exact boundary occurrences. The raw local-chart reciprocity test

```text
first.family == second.family
first.advanceSign == -second.advanceSign
```

now applies only when the two edges belong to **different** source-topology regions. A same-region periodic pair is no longer rejected before the generator rotation is known merely because its untransported local family/sign labels differ.

Everything after that gate is unchanged: `generator_route_for_span(...)` supplies the one exact directed route; its composed rotation is passed unchanged to `periodic_action_for_pair(...)`; that helper still checks both transported branch rotations, derives one integer translation, and requires exact application to both reciprocal lattice endpoints; checked `SurfacePeriodicHolonomy::make(...)` and its typed failures remain unchanged. No inverse-rotation retry, rotation search, endpoint rewrite, translation fit, or fallback was introduced.

Semantic patch commit is:

```text
53a21f550cf67e643e8c67a633bb63a20b055c6a
```

The work-preservation patch was derived from exact snapshot base `5e446cb3e91ef1190321c09745262944db2765b0`:

- complete patch SHA-256 `7cbd3551db9d73169c12e8f26f599a7a364d1e9de96942d0fa59df6f4a7fd5f1`;
- diff-body SHA-256 `06759006081d838d185fcf990cfe4b85806c356b29d46b60fd8b616e6ae539b5`;
- intended path count **1**;
- local `git diff --check`, CB11 static falsifiers, and clean-baseline `git apply --check` all passed before remote application.

Drive patch application run/job `35689803073 / 106624198737` succeeded. Result/log artifacts are `10678172884 / 10677863325` with provider SHA-256 `b6d394adca76710395a9abea16da303312a58fb2fcc8c64d66db0a8e226bba8a / 77c4489c1660975a10b76d07c38f38e015419ff826f6c53e52291f3bb810621e`. The result records `runtimeExecution=false`, the exact base and patch hashes, and applied commit `53a21f550cf67e643e8c67a633bb63a20b055c6a`. Workflow-side Drive trash was unavailable to the service account, so the user-authorized Drive connector permanently deleted the staged patch after successful push/evidence capture.

## 2. Static falsifiers

Before compile, the snapshot-derived source review established all frozen CB11 falsifiers:

1. cross-region HardRail still requires raw family equality and opposite advance sign;
2. same-region pairing no longer applies that raw family/sign test before transport;
3. exact distinct same-region occurrences, reciprocal intervals and reverse routes remain required;
4. `generator_route_for_span(...)` is unchanged;
5. the exact directed `generatorRotation` is passed unchanged to `periodic_action_for_pair(...)`;
6. no inverse/best-of-two retry exists in the affected path;
7. `periodic_action_for_pair(...)` retains two branch-rotation checks, one integer shift and two exact endpoint applications;
8. checked `SurfacePeriodicHolonomy::make(...)` remains unchanged;
9. the semantic diff contains only `src/geometry/SurfaceCellTracing.cpp`.

No test, fixture, selector, routing, header, CMake, benchmark or frozen-definition semantic byte was changed.

## 3. Mandatory GMP compile/package

The exact semantic source `53a21f550cf67e643e8c67a633bb63a20b055c6a` was compiled by the durable GitHub Actions compile workflow in run/job:

```text
35689915209 / 106624528816
```

All required targets built successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

`directional_core` was the explicit preflight target and returned 0; the full target compile returned 0. Configure forced `DIRECTIONAL_ENABLE_GMP=ON`. Packaged GMP evidence resolves both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the authoritative test-owner link command. Source status is empty before configure, after configure, after build and at final packaging.

The candidate result/log artifacts are:

```text
candidate: 10678487447
provider/download SHA-256: 60c4a643cd4a56c70c5fd0674a0df110c501deffe32e244795213a33c96afc3c
log: 10678382883
provider SHA-256: 87618baf7bffb80e7a557d1d6ea1a038360f782067dee61ef2df81aaa49ff955
```

Candidate root `SHA256SUMS` verifies **28/28** and hashes to `5f009791f3d237383a472bd1d5c4b50ca771b5f6e5d66295d99726cdd857e364`. The packaged source archive `source-53a21f550cf67e643e8c67a633bb63a20b055c6a.tar.gz` hashes to `fcd122a41bdcf64010e3c732c1fba89624815b304803e31c114c56018c5dd6b8`.

The command-boundary receipt explicitly records:

```text
runtimeExecution=false
turnBoundary=Code+Build-only
exactArithmeticBackend=GMP
preflightCompile=true
semanticContracts=compiled-not-executed
```

No generated Directional binary, test, benchmark, discovery/list command, `ctest`, CLI, fuzzer, help/version command or custom input was executed in CB11.

## 4. Authority disposition

CB11 proves only that the frozen product correction compiles and packages cleanly. It does **not** establish runtime recovery, candidate promotion, debt discharge, selector publication eligibility, or closure of `M5-CP3-TB1-R9-REV-CAND-01`.

Accepted runtime authority therefore remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains **50 events / 14 categories / 36 recurrences**. Project produced-witness debt remains **3**: two M5 nonzero-Z4 debts and one M6 closed-complex debt. Selector publication remains prohibited.

Exact successor is immutable artifact-only **`M5-CP3-TB1-R10-EXEC`** against candidate `10678487447` and exact source `53a21f550cf67e643e8c67a633bb63a20b055c6a`, followed by mandatory `M5-CP3-TB1-R10-REV` for any mechanically complete result.
