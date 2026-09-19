# M4-CP4-TB2-R1-EXEC — immutable artifact-only full-gate re-execution plan

**Turn type:** Test + Benchmark / immutable artifact-only execution
**Authorized by:** `M4-CP4-CB6`
**Mandatory successor for any orchestration-valid semantic result:** `M4-CP4-TB2-R1-REV`

## 1. Purpose

Re-run the complete frozen M4-CP4 acceptance surface from ordinal 1 on a repository-authorized GitHub Actions execution plane that has no full-suite elapsed-time cutoff. The two `M4-CP4-TB2-EXEC` interrupted attempts are audit-only and contribute **zero** focused or selector rows.

## 2. Frozen payload authority

Use the durable CB6 payloads exactly:

- harness `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-harness.sh`, mode `755`, SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`;
- caller draft `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-caller-draft.yml`, mode `644`, SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c`.

The caller draft was schema-validated successfully in run `35441895809`. At R1 start, publish those exact caller bytes as temporary `.github/workflows/m4-cp4-tb2-r1-exec.yml` through the GitHub connector. Do not edit the semantic content while publishing. Re-verify its SHA-256 after publication and schema-validate the exact installed workflow before triggering runtime. Caller installation and trigger marker must be separate commits.

The workload job must contain no `timeout-minutes`. The harness must not use shell `timeout`, watchdogs, or any full-gate elapsed-time cutoff.

## 3. Immutable package authority

Use exactly:

- CB4 artifact `10578784752`, source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`, source archive `dd7dd3351ad3ea10f56ef9ce2021fc8ea84e10d682560b93f70ca1d79b089175`, manifest SHA-256 `8d3c8902504ed6ef4f09f26329fcf7bddeeaa3fff9c023772c5f7e81abcb33b2`, **28/28** entries;
- CB5 artifact `10582435470`, source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`, source archive `b904ba5fec938d74d432501396f94de0c015072de6d9009c6213e6d547c19c81`, manifest SHA-256 `f5239fa4cb8fb31551599d6f836ca16e44ab203056dc262eb5c26141ed62d270`, **24/24** entries.

Both packages must verify `runtimeExecution=false`, clean source receipts and GMP/GMPXX compile evidence before runtime. Do not rebuild, repackage, chmod, repair or mutate either package.

## 4. Frozen selector and owner routing

Use selector `.agents/Directional/Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt` exactly: **427 LF rows**, **34,783 bytes**, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Re-derive owner identity statically from packaged source/CMake authority. Required census is:

- authority-kernel: `30` -> CB5;
- producer: `281` -> CB4;
- completion: `75` -> CB5;
- validation: `41` -> CB4.

The only semantic source differences between CB4 and CB5 must be `tests/FieldTransportAtlasTests.cpp` and `tests/SurfaceComplexSimplificationPhase17Tests.cpp`. Any other relevant source/fixture/CMake delta is orchestration failure before runtime.

## 5. Four focused processes

Execute exactly once each, in this order and in fresh processes:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` — producer / CB4;
2. `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` — completion / CB5;
3. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` — producer / CB4;
4. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` — authority-kernel / CB5.

Do not execute the two periodic focused identities re-homed to M5. Focus semantic RED does not stop later focused or selector processes.

## 6. Selector427 phase

After all four focused rows, execute selector427 from ordinal 1 through 427, one fresh exact-filter process per row. Require exactly one selected test and zero skips for every process. Semantic RED is recorded and execution continues; selection mismatch, skip, missing/mode/hash/source mismatch or invalid postflight is orchestration failure.

Required complete-gate cardinality is **431 process-ledger rows**. Benchmark execution count remains `0`.

## 7. Evidence and immutable postflight

Before runtime, freeze byte+mode censuses for both package trees, both packaged-source trees and the composite execution view. Materialize fixtures only from immutable packaged source to sibling `test-data/benchmarks/fixtures` under the existing executable-relative contract.

Always preserve:

- raw stdout/stderr for every process;
- focus and selector ledgers plus combined 431-row ledger;
- exact exit/selected/passed/skipped/result/classification fields;
- first semantic RED summary;
- owner/package routing and source authority receipts;
- boundary counters proving configure/compile/relink/discovery/repair/mutation/benchmark counts remain zero;
- pre/post censuses and both postflight manifest checks;
- self-excluding result `SHA256SUMS`;
- separate persistent diagnostic log.

After runtime starts, postflight is mandatory even when semantic RED occurs. The job may fail only for orchestration-invalid evidence; semantic RED is valid runtime evidence and must remain inspectable.

## 8. Regression gate and successor

Classify every semantic non-green in `.agents/Directional/Regression_Root_Cause_Tracker.md` before R1 closes. Do not alter stable counts without independent evidence supporting a stable regression.

Any orchestration-valid R1 result, green or semantic RED, routes to mandatory runtime-free **`M4-CP4-TB2-R1-REV`**. R1 itself grants no package promotion, debt discharge, M4 closure, or M5 periodic credit.
