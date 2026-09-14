# M4-CP-SCALE-CB1 — S1 Exact Trace-Scale Census Code + Build Report

**Turn:** `M4-CP-SCALE-CB1`
**Type:** Code + Build only
**Status:** COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED
**Successor:** `M4-CP-SCALE-TB1-EXEC`

## 1. Scope and authority

CB1 implements only frozen CP-SCALE S1: passive exact A2a trace-entry rational scale measurement. No S2-S5 product change, selector row, scale threshold, traversal-decision change, or 4096-bit continuation-guard change is present.

Accepted runtime authority is deliberately unchanged at package `10331193451` / semantic source `07984711db59eaa228820e7d44e5552a652edadf` / selector423 **423/423**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`. CB1 produces a new **candidate compile package only** for TB1; CB1 does not promote runtime authority.

## 2. Implemented source

Final semantic source: `a359b981f9350139304bc5a654041dfba78609b6`.

Only the three frozen semantic surfaces changed from the CB1 entry source:

1. `include/directional/geometry/SurfaceCellTracing.h`
   - adds `FieldAlignedTraceScaleSampleClass`, exact row/measurement/aggregate types, success/failure results, and package-visible measurement/census entry points;
   - the row schema is exactly `{trace, step, sourceFace, branch, incomingCarrier, sampleClass, numeratorBits, denominatorBits, magnitudeBits}`;
   - failure results retain the partial exact census together with the unchanged typed production error.
2. `src/geometry/SurfaceCellTracing.cpp`
   - threads an optional `FieldAlignedTraceScaleCensus*` only through the canonical production candidate path;
   - samples `entryPoint.parameter.value` only **after** the existing traversal guard returns `Advanced`;
   - derives numerator/denominator/magnitude widths directly from GMP-backed exact rational state, with no floating conversion;
   - canonicalizes rows by `(trace, step)` and computes integer sums/maxima plus exact `{sum,count}` means;
   - returns the same semantic candidate digest on success and the same production error on failure; collection does not participate in any decision.
3. `tests/FieldAlignedCurveNetworkTests.cpp`
   - adds `M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral`;
   - proves a nontrivial two-ring exact sample, independent width recomputation, deterministic repeated census/order/aggregate, enabled-vs-disabled semantic equality, and a deliberate `0 -> 1/257` exact-parameter measurement change;
   - extends the same deterministic census contract across retained torus, mechanical-feature, and prescribed-sphere witness paths, preserving partial census evidence when the baseline production result is a typed error.

The accepted selector remains byte-identical at **423 LF rows** / `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`. `kFieldExactContinuationMagnitudeBits` remains `4096U`.

## 3. Compile/package evidence

Authoritative final compile:

- workflow run/job: `34872546633 / 104071824274`;
- exact compiled semantic source: `a359b981f9350139304bc5a654041dfba78609b6`;
- result artifact: `10360085644`, provider/result-ZIP SHA-256 `996189b38c26f906bdd86354451571475900d98d0811f50e50a9439f26ff6ec7`;
- diagnostic-log artifact: `10359913218`, SHA-256 `15345f2c43adc684dd219ff42a7c37003123c065c7fff257dcb554a85d34550c`;
- package root `SHA256SUMS`: **28/28 verified**, self-excluding, file SHA-256 `3ac6c9e388d06ed5572613480a587952736657be88cf8dfba393d356e47028b8`;
- packaged source archive SHA-256: `b261f468cde2e54974f19931ca5101e2c6d07e273ca555c0526d9e7ce112e3d4`;
- preflight compile exit `0`; full compile exit `0`; every packaged source-status receipt is empty.

Compiled owners, all GREEN:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

GMP authority is explicit in package metadata: `DIRECTIONAL_ENABLE_GMP=ON`, `libgmpxx.so` and `libgmp.so` are both present in the recorded link command, and `exactArithmeticBackend=GMP`.

The command boundary records `runtimeExecution=false` and `turnBoundary=Code+Build-only`. No generated Directional binary, test discovery, test, benchmark, CLI/help/version command, fuzzer, or custom input executed in CB1.

## 4. Failed-closed authoring evidence

An earlier compile-only attempt (`34858481904`) failed before packaging on an unqualified test-source type name (`FieldAlignedCandidateTrace`). The correction was test-source-only and preserved before application. Later authoring extended the failure-preserving census contract and retained-witness matrix without widening production semantics. These attempts carried no runtime/test authority and the final package above supersedes them for TB1.

## 5. Acceptance disposition

All CB1 frozen Code + Build criteria are satisfied:

- exact intended semantic files only;
- passive exact GMP-backed census with canonical ordering and exact aggregates;
- decision-neutral success/error behavior by construction and authored regression contract;
- non-default/tamper-sensitive measurement oracle;
- complete selector423 owner package compiles and links;
- selector423 and the 4096-bit guard are unchanged;
- no S2-S5 implementation and no numeric threshold;
- immutable package and self-excluding manifest produced;
- runtime prohibited and not executed.

CB1 is therefore **COMPLETE / COMPILE GREEN / RUNTIME UNADJUDICATED**. Exact next is immutable artifact-only `M4-CP-SCALE-TB1-EXEC` under `Architecture_M4_CP_SCALE_TB1_Artifact_Only_Test_Benchmark_Plan.md`.
