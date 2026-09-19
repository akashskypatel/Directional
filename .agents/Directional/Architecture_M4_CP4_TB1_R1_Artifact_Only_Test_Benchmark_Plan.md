# M4-CP4-TB1-R1-EXEC — corrected artifact-only focused CP4 Test + Benchmark plan

**Turn:** `M4-CP4-TB1-R1-EXEC`
**Type:** immutable artifact-only Test + Benchmark retry
**Predecessor:** `M4-CP4-CB2`
**Candidate artifact:** `10575545321`
**Exact compiled source:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`
**Selector:** exact selector427, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`

## 1. Goal

Repeat TB1 evidence intake from scratch on the corrected immutable CB2 package. The orchestration-invalid TB1 attempt contributes no semantic row result, package promotion or produced-witness credit.

## 2. Frozen control authority

Before the execution marker, reinstall byte-for-byte and verify:

- harness from commit `cfb6d5a97419fb119c8f73c02d9c42a2235db21b`: **19,871 bytes**, SHA-256 `4b956829e4b656ccc71f00c781028fcb08452cad995cbcdfaaacde314954d29f`;
- caller from commit `7ca49c0b345b3e6baa50b7e6718d9909125fb77f`: **4,974 bytes**, SHA-256 `617e9e3634cccffd7a68ab2c30e82fb5bc48026823232ada59eae81e89a9790f`.

The caller passed SchemaStore validation in CB2 run `35413925663`. Install the caller first, verify exact bytes on branch authority, then create its exact marker in a separate later commit. Do not regenerate or widen either file.

## 3. Immutable preflight

Download artifact `10575545321` exactly once and require:

1. provider/package SHA-256 `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00` and complete `SHA256SUMS` verification;
2. packaged source archive SHA-256 `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed` and exact source `ad54c12774e10480fd3cef8138cacb8d5dec1529`;
3. clean empty receipts exactly: `source-status-before-configure.txt`, `source-status-preconfigure.txt`, `source-status-after-configure.txt`, `source-status-after-build.txt`, `source-status-final.txt`;
4. `runtimeExecution=false`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`, plus GMPXX/GMP evidence;
5. archive-preserved executable modes for authority-kernel, producer, completion and validation owner binaries; missing modes are orchestration failure, never permission to `chmod`;
6. selector427 exactly **427 LF rows**, expected SHA and owner partition **30 / 281 / 75 / 41**.

Any integrity mismatch is orchestration failure, not semantic evidence.

## 4. Focused gate — six fresh processes

Run one exact identity per fresh process with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, exactly one selected and zero skips:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` — producer;
2. `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` — completion;
3. `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering` — producer;
4. `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected` — producer;
5. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` — producer;
6. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` — authority-kernel.

Execute all six focused rows unless orchestration integrity is invalidated. Semantic non-green is evidence; do not retry or patch it.

## 5. Exact selector427 reproof

After focused execution, unless orchestration integrity failed, execute selector427 in exact file order, one fresh process per row with the frozen owner mapping and exactly one selected identity. Record every planned row as PASS/RED/SKIP/crash/timeout/selection-mismatch/unexecuted. Stop after the first selector semantic non-green while preserving all later rows explicitly unexecuted.

Planned ledger: **433 rows = 6 focused + 427 selector**. Benchmark execution count: **0**.

## 6. Boundary and postflight

No configure, compile, relink, package repair, permission repair, generated discovery/list/help/version, source/test/fixture/selector mutation or custom benchmark input. Extract mode-preservingly and require exact byte+mode package/source/execution-view postflight whenever runtime starts.

## 7. Classification and successor

R1 is evidence intake only. Candidate artifact `10575545321` remains unpromoted; accepted runtime authority remains package `10565723112` / selector427 **427/427** until Review.

- Any trustworthy semantic outcome, all-green or non-green, routes to **`M4-CP4-TB1-R1-REV`**.
- Orchestration/integrity failure before trustworthy semantic evidence routes to the smallest correction Code + Build permitted by cadence.
