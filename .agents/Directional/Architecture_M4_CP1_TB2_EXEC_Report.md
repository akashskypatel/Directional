# M4-CP1-TB2-EXEC Report

**Status:** COMPLETE / ARTIFACT-ONLY RUNTIME / MECHANICALLY VALID / FULL GREEN / CB4 CONTROL PREDICTION MET / REVIEW REQUIRED

**Turn:** `M4-CP1-TB2-EXEC`
**Boundary:** Test + Benchmark, artifact-only
**Date:** 2026-09-10

## 1. Authority and immutable input

TB2-EXEC consumed immutable CB4 package115 exactly as frozen. It did not configure, compile, relink, regenerate
selection/discovery, repair package bytes or executable modes, mutate source/tests/fixtures/selectors, or run a
performance benchmark.

- semantic/build evidence source: `680f9f1573d3c7e56a273366436463e40e196131`;
- immutable package115 artifact: `10159019500`, `m4-cp1-cb4-package-result-34493860436`;
- package provider/downloaded ZIP SHA-256:
  `de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b`;
- selector373 SHA-256: `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`, 373 rows;
- accepted predecessor count: 365;
- artifact-only harness SHA-256: `ddfbda2ff626008d3d2e9f6d117b10c98de159c4f9b8a3a36f99e50e24fd22d9`;
- exact owner partition: **30 authority-kernel / 227 producer / 75 completion / 41 validation**;
- accepted-prefix owner partition: **30 / 219 / 75 / 41**;
- per-identity runtime control: `timeout -k 5s 180s`;
- outer gate timeout: none.

The start-of-turn repository snapshot was taken at event SHA
`c9c43fb5969d7e8ca5200fb02ae94617223c265c` by run/job
`34496273415 / 102935470463`; source-snapshot artifact `10159919139` has provider/downloaded SHA-256
`1e73ae498540d2f4f7377ffd72b76ec3f4b0213e361ddfb13a13bb90ea5db9f8`. Its embedded source manifest verified all
5,237 files.

## 2. Execution evidence and caller boundary

Authoritative workflow run **`34497233764`**, event SHA
`2de16f45a01311ec93fe4196c1d0a89d6f8447a3`, completed successfully. The artifact-only execute job is
**`102938757986`** and completed successfully.

- result artifact: `10160450899`, `m4-cp1-tb2-exec-result-34497233764`, provider/downloaded SHA-256
  `0b7f1551fe3881a0fd46386e1a45ae043faa307f6cb167e91cb4ef78839b9e38`;
- diagnostic log artifact: `10160451919`, `m4-cp1-tb2-exec-log-34497233764`, provider/downloaded SHA-256
  `2feedf2c278e4735d3506afa124f0cad367d2f23be43cd0d5c3aa66d03f9b955`;
- schema-validation job `102938684841`: **success**;
- run-observer PR-comment job `102938685303`: **success**;
- execute job `102938757986`: **success**;
- exact harness invocation exited `0`.

The harness boundary records `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`,
`execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, and `timeout_count=0`.
It also records `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`,
`relink_execution=false`, `generated_discovery=false`, `package_repair=false`, `mode_repair=false`, and
`source_test_fixture_selector_mutation=false`.

## 3. Immutable preflight and execution-view closure

Every frozen pre-runtime condition succeeded before the first Directional process:

- artifact ID/name/provider/download hash matched exactly;
- complete package `SHA256SUMS` verification succeeded;
- source metadata matched `680f9f1573d3c7e56a273366436463e40e196131`;
- compile evidence remained runtime-free and GMP/GMPXX authoritative;
- selector373 count/hash matched exactly;
- all 373 identities mapped exact-once to the four owner binaries at **30 / 227 / 75 / 41**;
- all four owner executables were present with executable mode;
- the fresh execution view was derived only from package-owned binary and source-archive bytes;
- unchanged `TestFixturePaths` resolved through the **sibling** rule to the package-derived `test-data` tree;
- known fixture `test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj` resolved before semantic runtime.

Owner executable receipt SHA-256 is
`dc90e9347f60b54fb5b1a572b78db31072f08207b16f95ebb8edae7d0f9bdce6`; identity-map SHA-256 is
`b69a5d82fc4f576853c91845b0c79d9f24affe990fb3a6ec6947ea1d97b4e587`.

## 4. Raw measured result

TB2-EXEC measured the exact frozen gate fully green:

- focused CP1 phase A, rows 366-373: **8 PASS / 0 RED / 0 SKIP / 0 timeout**;
- focused CP1 phase B, rows 366-373: **8 PASS / 0 RED / 0 SKIP / 0 timeout**;
- focused verdict vectors: **identical**;
- cumulative selector373: **373 PASS / 0 RED / 0 SKIP / 0 timeout**;
- accepted predecessor rows 1-365: **365/365 PASS**;
- CP1 rows 366-373 within the cumulative gate: **8/8 PASS**;
- selection mismatches: **0**.

Full-ledger SHA-256 is `ef6300dd2616d064add61db9ae5ff38992af523bf2cae40a293e1dd4c6163fbc`.
Focused A/B ledger SHA-256 values are
`7336c6630f50ce3c8b6a53eb61140264f75199bb15f86ac40bc8a8eca16a8dbf` and
`2583a43e8ef3feae5f0ec51dccfb8a74d54d5b2d823325a4e61a89c836393073`.

An independent scan of all **389** raw gtest process logs (8 + 8 + 373) found exactly **389** `[ RUN ]`, **389**
`[ OK ]`, **0** `[ SKIPPED ]`, and **0** `[ FAILED ]` markers. This independently confirms that the ledger's green
result is not hiding a gtest skip.

## 5. CB4 package/control prediction is met

TB1-REV predicted that holding semantic/test bytes fixed while adding the three omitted owner binaries and restoring
the package-source-derived executable-relative fixture view would eliminate TB1's **146 MISSING** rows and **38
pre-assertion fixture failures**.

TB2-EXEC is the direct falsifier and the prediction is met: all 373 identities selected exactly once and all 373
passed. The previously omitted owner populations are present and the fixture-backed predecessor identities execute
through the intended `TestFixturePaths` contract. No product/test/fixture/selector change occurred between the CB3
semantic source and this package-closure control experiment.

This is raw runtime recovery evidence for the already-adjudicated non-stable
`M4-CP1-TB1-EXEC-CAND-01` and `M4-CP1-TB1-EXEC-CAND-02`. TB-EXEC does **not** independently close those candidates,
promote package115, or make a final semantic acceptance claim; `M4-CP1-TB2-REV` owns that adjudication.

## 6. Immutable postflight

All three post-runtime censuses are byte-identical to pre-runtime authority:

- package census before/after SHA-256:
  `c505b0b83636e40cd1e61ad6589b7149b1b4a27f438571ddd6da0fc89819d258`;
- extracted-source census before/after SHA-256:
  `64ed4e540ed5881e7d7d083aa01cdd18545322490cf498fbb92e09d9aa31f4c3`;
- execution-view census before/after SHA-256:
  `507669eb13a9e1388c61ce959f4483d64af60c9437b2809fb6590a3503bbbb08`.

The harness records `package_census_equal=true`, `source_census_equal=true`, and
`execution_view_census_equal=true`.

## 7. Regression accounting and authority boundary

TB2-EXEC observed **no RED, crash, skip, timeout, selection mismatch, nondeterminism, or integrity failure**, so it
creates no new regression candidate and no new stable event/category/recurrence. Stable accounting remains **47 events
/ 14 categories / 33 recurrences**, produced-witness debt **5**, accepted packages **113** pending review.

Package115/TB2 is complete full-green raw runtime evidence, but package115 remains a candidate until independent
review validates the gate and records closure. Until then, reviewed semantic runtime authority remains **M3 /
package113 / TB48** at selector409 **405 PASS / 4 RED / 0 SKIP**, accepted selector365 **365/365**.

The deferred multi-coordinate bidirected `±2` exhaustive-oracle coverage obligation remains outside this unchanged-
semantics control gate and remains assigned to the first later Code + Build turn authorized to change test source.

## 8. Exact successor

**Exact next: `M4-CP1-TB2-REV` — independent REVIEW / runtime-free.**

The review must re-open the primary TB2 result/log evidence, validate package115 provenance and full 373/373 plus
focused 8/8-twice receipts, adjudicate closure of the two TB1 package/control candidates, decide package115 promotion
and formal M4-CP1 closure, update `ORIENTATION.md`, and perform mandatory REVIEW-turn document consolidation. It must
not compile, execute Directional runtime, or change product/test/fixture/selector/build semantics.
