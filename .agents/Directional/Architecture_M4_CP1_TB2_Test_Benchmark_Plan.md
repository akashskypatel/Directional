# M4-CP1-TB2 Test + Benchmark Plan — immutable package closure and execution-view falsifier

**Status:** ISSUED / ARTIFACT-ONLY / RUNTIME AUTHORITY PENDING
**Turn:** `M4-CP1-TB2-EXEC` then `M4-CP1-TB2-REV`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Evidence commit:** `680f9f1573d3c7e56a273366436463e40e196131`
**Candidate package:** package115, artifact `10159019500`
**Harness:** `.agents/Directional/tools/m4_cp1_tb2_artifact_only_harness.sh`

## 1. Validation identity

Package115 was produced by CB4 from the unchanged M4-CP1 semantic source through the mandatory GMP/GMPXX compile
path. TB2 must validate **that immutable artifact**, never rebuild it.

Frozen package authority:

- artifact name: `m4-cp1-cb4-package-result-34493860436`;
- artifact ID: `10159019500`;
- provider/downloaded ZIP SHA-256:
  `de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b`;
- semantic source: `680f9f1573d3c7e56a273366436463e40e196131`;
- selector: `.agents/Directional/Architecture_M4_CP1_Required_Green_Selector_373.txt`;
- selector count/hash: **373** /
  `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`;
- harness SHA-256:
  `ddfbda2ff626008d3d2e9f6d117b10c98de159c4f9b8a3a36f99e50e24fd22d9`;
- planned platform: `ubuntu-24.04` with `/usr/bin/time`, GNU `timeout`, `sha256sum`, `tar`, `jq`, Python 3, and GitHub
  artifact API access through `GH_TOKEN`.

The TB execution workflow may stage/download immutable bytes and create a derived read-only execution view. It may
not configure, compile, relink, regenerate, patch, chmod-repair package binaries, edit fixtures/tests/selector, or use
a runner checkout as source/fixture authority.

## 2. Validation objective

TB1 established two package/control-plane failures without establishing a product-semantic regression:

1. package114 contained only the producer owner target, leaving exactly 146 selector rows unselectable;
2. its launch view lacked the executable-relative `test-data` root, causing 38 selected predecessor identities to
   fail before their intended assertions.

CB4 predicts both defects are removed while semantic source is held fixed. TB2 is the falsifier:

- prove selector373 maps exact-once to **30 authority / 227 producer / 75 completion / 41 validation** rows;
- prove all four owner binaries exist and are executable in package115;
- prove package-owned source bytes alone materialize the existing `TestFixturePaths.h` sibling/legacy fixture layout;
- then execute the eight CP1 identities twice and the entire frozen selector373 one identity per fresh process;
- prove package, extracted source, and execution view are byte/mode unchanged after runtime.

A changed runtime result can therefore be attributed to the package/execution-view correction rather than a product,
test, fixture, or selector change.

## 3. Preconditions and immutable preflight

The execution agent must first verify the checked-in harness hash above and then invoke it with exact immutable values:

```bash
export TURN_ID=M4-CP1-TB2-EXEC
export GITHUB_REPOSITORY=akashskypatel/Directional
export ARTIFACT_ID=10159019500
export EXPECTED_ARTIFACT_NAME=m4-cp1-cb4-package-result-34493860436
export EXPECTED_PROVIDER_DIGEST=sha256:de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b
export EXPECTED_ZIP_SHA256=de391c44744d83622dee30cf3a78f781c3b9ad95f0b517a866e7285e77a6b45b
# GH_TOKEN is supplied through the authorized workflow secret surface and is never logged.

bash .agents/Directional/tools/m4_cp1_tb2_artifact_only_harness.sh --execute
```

The harness preflight must fail closed **before any Directional process** unless all of these are true:

1. artifact ID/name/provider digest/downloaded ZIP digest match exactly;
2. every package `SHA256SUMS` entry verifies;
3. `metadata/source-commit.txt` equals the evidence commit;
4. compile boundary says `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
5. CMake/GMP evidence proves `DIRECTIONAL_ENABLE_GMP=ON` and both `gmpxx` and `gmp` are linked;
6. package source archive exists and is the only source/fixture materialization authority;
7. selector count/hash are exact;
8. owner map is 373/373 exact-once with 30/227/75/41, first365 30/219/75/41, rows366-373 producer-owned;
9. all four mapped owner executables exist with executable mode;
10. the fresh execution view byte/mode matches package binaries and its sibling fixture tree comes only from the
    package source archive;
11. the unchanged `TestFixturePaths.h` sibling/legacy rule resolves the known
    `test-data/benchmarks/fixtures/milestone-g/mechanical_feature.obj` fixture;
12. package/source/execution-view pre-runtime censuses are recorded.

A failure of any item above is **orchestration failure**, not semantic RED. Stop, preserve raw evidence, and route to a
Code + Build orchestration correction without executing the semantic gate.

## 4. Ordered execution plan

### 4.1 Focused CP1 phase A

Run frozen selector rows **366-373** in order. Each identity executes in a fresh process through its mapped owner
binary with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, `GTEST_COLOR=no`, and exact `--gtest_filter=<identity>`.

Acceptance:

- 8 identities attempted;
- every process reports exactly one selected test;
- **8 PASS / 0 RED / 0 SKIP / 0 timeout**;
- preserve per-identity exit, elapsed time, peak RSS, selected count, log, and verdict vector.

### 4.2 Focused CP1 phase B

Repeat rows **366-373** identically in fresh processes.

Acceptance:

- **8 PASS / 0 RED / 0 SKIP / 0 timeout**;
- phase-B verdict vector is byte-for-byte identical to phase A;
- any disagreement is runtime evidence and must be reviewed, not retried away.

### 4.3 Frozen cumulative selector373

Run rows **1-373** in selector order, one identity per fresh process and through its exact owner executable. The harness
uses the established per-process bound `timeout -k 5s 180s`; there is **no outer gate timeout** intended to truncate
the complete semantic suite.

Acceptance:

- 373 identities attempted and each process reports `selected=1`;
- **373 PASS / 0 RED / 0 SKIP / 0 timeout**;
- rows 1-365 reported separately as **365/365 PASS**;
- rows 366-373 reported separately as **8/8 PASS**;
- preserve first failure/raw log even if the gate continues to collect the complete planned receipt.

Any assertion-level failure, crash, nonzero exit, skip, or timeout after valid preflight is semantic runtime evidence
for `M4-CP1-TB2-REV`; do not edit or rebuild in TB-EXEC.

### 4.4 Immutable postflight

After the last planned process, recompute and compare package, extracted-source, and execution-view censuses including
file hashes and modes.

Acceptance: all three postflight censuses equal their pre-runtime versions exactly. Any mutation invalidates the gate
and is orchestration/integrity failure rather than product acceptance evidence.

## 5. Evidence to preserve

TB-EXEC must package enough raw evidence for TB-REV to adjudicate without reconstructing intent from chat:

- workflow run/job IDs and exact workflow event/source;
- artifact metadata response and downloaded artifact SHA-256;
- package checksum verification and metadata copies;
- source-archive authority/hash and selector hash/count;
- full 373-row owner map and owner-distribution receipts;
- owner executable mode/size/hash receipts;
- resolved fixture-root receipt and execution-view construction manifest;
- pre/post package/source/execution-view censuses;
- focused A and B per-identity ledgers/logs and verdict vectors;
- cumulative 373-row ledger/logs, per-process time/RSS/exit/selected count, and semantic summary;
- harness SHA-256 and exact invocation environment excluding secrets.

The execution workflow must upload a dedicated detailed activity log under `if: always()` separately from result
evidence, regardless of success or failure.

## 6. Benchmark plan

No performance benchmark is part of M4-CP1 acceptance. Runtime and peak RSS are recorded per identity as diagnostic
metadata only; there is no performance threshold and no performance claim may substitute for correctness.

## 7. Unit-test design check

No unit-test source, fixture, selector membership, or assertion was changed in CB4. TB2 validates the existing frozen
373 identities and the package/execution contract only. The deferred multi-coordinate `±2` oracle strengthening is
**not** part of this gate and remains assigned to the first later Code + Build turn authorized to change test source.

## 8. Stop, routing, and rerun rules

- **Pre-runtime identity/integrity/owner/binary/fixture failure:** orchestration failure; no semantic ledger; preserve
  evidence and route to Code + Build orchestration correction.
- **Valid preflight + assertion-level RED/crash/skip/timeout/nondeterministic focused receipt:** semantic runtime
  evidence; preserve it and stop the canonical loop at the mandatory independent `M4-CP1-TB2-REV` boundary.
- **Complete 373/373 PASS + focused 8/8 twice + immutable postflight:** M4-CP1 closes under standing policy; TB-REV
  records/validates closeout and the orchestrator must stop if that review boundary is delegated independently.
- Do not rerun an unchanged deterministic failure. Only the two focused repetitions pre-authored above are allowed.
- Do not mutate the package or replace its source revision inside TB.

## 9. Completion criteria

TB-EXEC is complete when every planned phase has a recorded result or explicit blocker, all raw evidence is preserved,
and `M4-CP1-TB2-REV` can classify the result without any new unplanned runtime execution. Package115 remains a
candidate until that evidence establishes acceptance.
