# M5-CP1-TB1 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP1-TB1-EXEC`
**Disposition:** **BLOCKED / PRE-RUNTIME ORCHESTRATION PLAN DEFECT / ZERO SEMANTIC CREDIT**
**Candidate:** artifact `10595705100`, semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Accepted runtime authority remains:** M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**
**Exact successor:** `M5-CP1-TB1-PREFLIGHT-REV`

## 1. Outcome

TB1 did **not** execute a Directional binary. Immutable candidate-package preflight reached two contradictions in the frozen TB1 orchestration authority before the focused gate could lawfully begin. The plan itself says an authority mismatch stops execution and that zero-selection is orchestration failure, so this turn failed closed rather than silently repairing or substituting the frozen inputs.

Runtime counters are therefore **focused 0/9, selector430 0/430, benchmark 0**. No configure, compile, relink, generated discovery, package repair, chmod/mode repair, source/test/fixture/selector mutation, or fallback package occurred.

## 2. Immutable package and snapshot evidence

The candidate artifact was downloaded exactly once and verified before the blocker was classified:

- artifact ID/name: `10595705100` / `directional-m5-cp1-cb1-result-35478855426`;
- provider/download SHA-256: `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`;
- root `SHA256SUMS`: **28/28 PASS**; manifest SHA-256 `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d`;
- source commit: `b98f461b9a392cc182891a81c0a84b0b01dfbb45`;
- packaged source archive SHA-256: `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`;
- source-status receipts are clean; `runtimeExecution=false`; `exactArithmeticBackend=GMP`; `DIRECTIONAL_ENABLE_GMP=ON`; explicit `libgmpxx.so` + `libgmp.so` linkage is recorded;
- required packaged executables retain mode `0755` without repair;
- packaged selector430 is exactly **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`.

Turn-local source authority was materialized through source-snapshot run/job `35480330535 / 105996871120`, event/source SHA `f6f37856b7f6a55d62e1d9668844bfa992e700a9`, artifact `10595288347`, provider/download SHA-256 `a6d97835ea811c6a6c76287ce3d8f72c9e83759b5248025bb8f8c66cee836ba0`. Its source archive SHA-256 is `9374dd529192ae135c19d4588b914f0df919c52927cc5e4a7f940394266dd431` and its source manifest verified **5293/5293**.

The accepted M4-TB3 result artifact `10592987234` was also re-opened as the frozen routing authority. Its provider/download SHA-256 is `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`.

## 3. Blocking plan defects

### 3.1 `M5-CP1-TB1-CAND-01` — malformed accepted identity-map digest

The TB1 plan freezes the M4-TB3 identity-map SHA-256 as:

`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6`

That literal has **63 hexadecimal characters**, so it cannot be a SHA-256 digest. The immutable accepted M4-TB3 `identity-map.tsv` has 431 lines (header + 430 rows), owner census **31 / 283 / 75 / 41**, and SHA-256:

`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`

The accepted M4-TB3 report/review use the 64-character value ending in `cf6c`. TB1 did not silently alter the frozen plan literal.

### 3.2 `M5-CP1-TB1-CAND-02` — ninth focused exact-filter identity does not exist

The frozen plan requires this exact ninth focused filter:

`M4CP4.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`

Exact static enumeration of the immutable packaged test source finds **no such test identity**. The compiled test body carrying the required non-vacuity assertions is instead:

`SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`

in `tests/SurfaceCellTransitionQuotientTests.cpp`. That body asserts exactly two periodic holonomies, exactly two edges, and exactly two distinct relation-owner snapshots before container reorder. Substituting the near-match would change the frozen exact-filter plan, so TB1 did not do so. Launching the frozen name would select zero tests, which the plan explicitly classifies as orchestration failure.

## 4. Static CP1 audit

The immutable packaged source independently satisfies the plan's static CP1 audit:

- no production `PeriodicRelationId::from_index` reference;
- no production `periodicRelationOffset` reference;
- no production `reachableHardRailComponents` reference;
- no production `hardRailAdjacency` reference;
- `SelectedRelationPathCertificate` is present in the published completion product and in pipeline producer/validation paths.

This is static evidence only and receives no runtime gate credit.

## 5. Regression/accounting disposition

`M5-CP1-TB1-CAND-01` and `M5-CP1-TB1-CAND-02` are **ORCHESTRATION / FROZEN-PLAN AUTHORITY / NON-STABLE** candidates, not product regressions. No accepted-green identity ran and no candidate M5 identity ran. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

The candidate package is **not promoted**. Accepted runtime authority remains M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**.

## 6. Process note

At turn start, multi-document connector inspection began before the explicit `READ_MODE=snapshot` choice required by the conservation policy. The miss was detected before runtime or semantic mutation; piecemeal source/document inspection stopped, the turn switched to `READ_MODE=snapshot`, and the verified snapshot above became the sole subsequent repository-content authority. This is a process-order deviation only and does not alter semantic evidence.

## 7. Exact next

`M5-CP1-TB1-PREFLIGHT-REV` must independently adjudicate the two frozen-plan defects. The review may issue a corrected immutable TB1 execution plan only if it can prove the intended identity-map digest and intended ninth focused identity from accepted M4 authority plus exact source. No product/test/build change, package rebuild, selector edit, or semantic runtime is authorized before that review.
