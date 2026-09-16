# M4-CP-SCALE-CB12 — Selector426 Publication Code + Build Plan

**Boundary:** publication-only Code + Build; no product/test/fixture/CMake/benchmark semantic change and no Directional runtime
**Accepted semantic authority:** package `10461816370` / source `2adb7b8169a387fcb6db6487768d7bd3d678265c`
**Accepted selector prefix:** selector425 / `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`
**Publication obligation:** `M4-CP-SCALE-TB10-REV-OBS-01`
**Mandatory successor:** `M4-CP-SCALE-TB11-EXEC`

## 1. Purpose

Publish the Review-accepted S4 product identity into the append-only required-green selector without changing any product semantics. CB12 exists only because TB10 Review accepted the focused S4 product outside selector425; cumulative S4 credit requires a separate prefix-preserving selector publication followed by fresh artifact-only cumulative runtime and Review.

## 2. Exact selector426 bytes

Create `Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt` as the **exact bytes of accepted selector425** followed by exactly one LF-terminated row:

`M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`

Required publication properties:

- 426 LF-terminated rows;
- 426 unique identities;
- first 425 rows byte-identical to selector425;
- first425 SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- full selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- expected owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**;
- row426 owner: producer;
- row426 identity must exist exactly once in the compiled test source.

Update `Required_Green_Selector_Manifest.md` additively for selector426. Do not rewrite, reorder, normalize, deduplicate or regenerate any accepted prefix selector.

## 3. Frozen semantic scope

CB12 may modify only selector/publication lineage, required documentation/control state, and compile orchestration needed to package unchanged semantic source. It must not alter:

- `src/**`, `include/**`, `tests/**`, fixtures, CMake/build semantics or benchmark semantics;
- the S4 product implementation or focused test;
- accepted selector425 or any historical selector bytes;
- final certificate authority;
- A2a' cut ordering, proposal, saturation, repair or backtracking semantics.

Any need to change those surfaces stops CB12 and returns to Review rather than broadening publication scope.

## 4. Compile/package gate

Use durable `.github/workflows/agent-compile-reusable.yml` under `GMP_COMPILE_POLICY.md`. Compile/package the unchanged promoted semantic source with:

- `runtimeExecution=false`;
- `exactArithmeticBackend=GMP`;
- direct `gmpxx` and `gmp` linkage evidence;
- changed-owner preflight appropriate to selector/test ownership;
- all eight standard Directional targets packaged;
- exact source/package manifests and clean source-status evidence.

No Directional test, benchmark, CTest, discovery, help or version invocation is authorized in CB12.

## 5. Falsifiers and STOP rules

STOP and do not claim publication if any of the following occurs:

1. selector425 does not re-hash to `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
2. selector426 first425 bytes differ from accepted selector425;
3. selector426 does not have exactly 426 LF rows / 426 unique identities;
4. full selector426 SHA-256 differs from `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
5. row426 differs from the exact Review-accepted S4 identity or is not producer-owned exactly once;
6. owner census differs from **30 / 280 / 75 / 41**;
7. any product/test/fixture/CMake/benchmark semantic path changes;
8. any Directional runtime executes;
9. mandatory GMP/GMPXX compile/package evidence fails;
10. source/package status or manifests are not exact.

A compile/orchestration failure is not semantic S4 failure and grants no selector publication credit.

## 6. Successor runtime

After CB12 compile/package GREEN, exact successor is `M4-CP-SCALE-TB11-EXEC`.

TB11 must consume the immutable CB12 artifact without rebuild/repair and execute selector426 as **426 fresh exact-filter processes in exact file order**. Require exactly one selection/execution per row, expected owner census **30/280/75/41**, zero RED/SKIP/crash/timeout/selection mismatch/unexecuted, and exact immutable postflight. No benchmark is needed for this publication-only acceptance surface. `M4-CP-SCALE-TB11-REV` is mandatory before cumulative S4 selector credit or further CP-SCALE advancement.
